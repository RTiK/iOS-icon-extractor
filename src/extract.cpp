#include <opencv2/opencv.hpp>
#include "iOS-icon-extractor/IconIO.hpp"
#include "iOS-icon-extractor/config.hpp"


int main(int argc, char* argv[]) {

  Config config = Config(argc, argv);
  std::cout << config << std::endl;

  cv::Mat screenshot = cv::imread(config.GetInputPath(), cv::IMREAD_UNCHANGED);
  std::cout << "Dimensions: " << screenshot.size << " Type: " << cv::typeToString(screenshot.type()) << std::endl;

  IconIO::ExtractAndSavePageIcons(screenshot, config.GetNumIconsOnPage(), config.GetOutputPath());
  IconIO::ExtractAndSaveDockIcons(screenshot, config.GetNumIconsInDock(), config.GetOutputPath());

  return 0;
}