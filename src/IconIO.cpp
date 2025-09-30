#include "iOS-icon-extractor/IconIO.hpp"
#include "iOS-icon-extractor/IconCenters.hpp"
#include <cstdint>

bool IconIO::IsInSquircle(const float x, const float y) {
  // shift the integer coordinates by half of integer because the equation expects the coordinate lines to go between
  // pixels and not through them
  float x_shifted = x + 0.5f;
  float y_shifted = y + 0.5f;

  // iOS icons are a little translucent at the edges. as a result, some of the background might shine trough and distort
  // the colors. we keep this number <1 to cut off some of the edge of the icon
  float icon_border = 0.97f;

  // the equation below is a good enough approximation of the squircle shape. an alternative would have been to manage
  // a zoo of masks for different icon sizes
  return std::pow(std::abs(x_shifted / static_cast<float>(kSquircleRadius)), 4)
      + std::pow(std::abs(y_shifted / static_cast<float>(kSquircleRadius)), 4) <= icon_border;
}

cv::Mat IconIO::ReadIcon(const cv::Mat &image, const std::pair<int, int> icon_center) {
  int icon_width = 2 * kSquircleRadius;
  int icon_height = 2 * kSquircleRadius;
  cv::Mat icon = cv::Mat::zeros(cv::Size(icon_width, icon_height), CV_8UC4);

  for (int i = -kSquircleRadius; i < kSquircleRadius; i++) {  // horizontal; x
    for (int j = -kSquircleRadius; j < kSquircleRadius; j++) {  // vertical; y
      if (IsInSquircle(static_cast<float>(i), static_cast<float>(j))) {
        int pos_x = icon_center.first + i;
        int pos_y = icon_center.second + j;
        assert(pos_x >= 0 && pos_x < image.size[0]);
        assert(pos_y >= 0 && pos_y < image.size[1]);
        cv::Vec<std::uint8_t, 4> c = image.at<cv::Vec<std::uint8_t, 4>>(pos_x, pos_y);
        icon.at<cv::Vec<std::uint8_t, 4>>(kSquircleRadius + i, kSquircleRadius + j) = c;
      }
    }
  }

  return icon;
}

void IconIO::ExtractAndSavePageIcons(cv::Mat &image, int num_of_icons, const std::string &destination_dir) {
  assert(num_of_icons <= kMaxIconsOnPage);

  auto icon_center_iter = icon_centers::kIphone16Pro.begin();

  for (int i = 0; i < num_of_icons; i++) {
    cv::Mat icon = ReadIcon(image, *icon_center_iter++);
    std::string file_name = "icon_" + std::to_string(i) + ".png";
    cv::imwrite(destination_dir + file_name, icon);
  }
}

void IconIO::ExtractAndSaveDockIcons(cv::Mat &image, int num_of_icons, const std::string &destination_dir) {
  assert(num_of_icons <= kMaxIconsInDock);

  auto icon_center_iter = icon_centers::kIphone16ProDock[num_of_icons].begin();

  for (int i = 0; i < num_of_icons; i++) {
    cv::Mat icon = ReadIcon(image, *icon_center_iter++);
    std::string file_name = "dock_" + std::to_string(i) + ".png";
    cv::imwrite(destination_dir + file_name, icon);
  }
}
