#ifndef MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_
#define MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_

#include <vector>
#include <utility>

namespace icon_centers {
  // display size 2622/1206
  const std::vector<std::pair<int, int>> kIphone16Pro = {
      {366, 187}, {366, 464}, {366, 743}, {366, 1020},  // 1st row
      {667, 187}, {667, 464}, {667, 743}, {667, 1020},  // 2nd row
      {968, 187}, {968, 464}, {968, 743}, {968, 1020},  // 3rd row
      {1269, 187}, {1269, 464}, {1269, 743}, {1269, 1020},  // 4th row
      {1570, 187}, {1570, 464}, {1570, 743}, {1570, 1020},  // 5th row
      {1871, 187}, {1871, 464}, {1871, 743}, {1871, 1020}   // 6th row
  };

  // icon locations depend on number of icons in dock
  const std::vector<std::vector<std::pair<int, int>>> kIphone16ProDock = {
      {},
      {std::vector<std::pair<int, int>>{{2416, 603}}},
      {std::vector<std::pair<int, int>>{{2416, 471}, {2416, 735}}},
      {std::vector<std::pair<int, int>>{{2416, 339}, {2416, 603}, {2416, 867}}},
      {std::vector<std::pair<int, int>>{{2416, 206}, {2416, 470}, {2416, 736}, {2416, 1000}}}
  };
}  // namespace icon_centers

#endif //MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_
