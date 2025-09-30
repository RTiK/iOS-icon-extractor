#ifndef MOSAIC_EXTRACT_SRC_ICONIO_H_
#define MOSAIC_EXTRACT_SRC_ICONIO_H_

#include <opencv2/opencv.hpp>

class IconIO {
 private:
  static const int kSquircleRadius = 96;
  static const int kMaxIconsOnPage = 24;
  static const int kMaxIconsInDock = 4;

  static bool IsInSquircle(const float x, const float y);
  static cv::Mat ReadIcon(const cv::Mat &image, const std::pair<int, int> icon_center);

 public:
  static void ExtractAndSavePageIcons(cv::Mat& image, int num_of_icons, const std::string& destination_dir);
  static void ExtractAndSaveDockIcons(cv::Mat& image, int num_of_icons, const std::string& destination_dir);
};

#endif //MOSAIC_EXTRACT_SRC_ICONIO_H_
