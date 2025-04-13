#ifndef MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_
#define MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_

#include <vector>
#include <utility>

namespace icon_centers {
  // display size 828/1792
  const std::vector<std::pair<int, int>> kIphone13Page = {
      std::pair<int, int>(291, 180), std::pair<int, int>(291, 450), std::pair<int, int>(291, 720), std::pair<int, int>(291, 990),  // 1st row
      std::pair<int, int>(585, 180), std::pair<int, int>(585, 450), std::pair<int, int>(585, 720), std::pair<int, int>(585, 990),  // 2nd row
      std::pair<int, int>(879, 180), std::pair<int, int>(879, 450), std::pair<int, int>(879, 720), std::pair<int, int>(879, 990),  // 3rd row
      std::pair<int, int>(1173, 180), std::pair<int, int>(1173, 450), std::pair<int, int>(1173, 720), std::pair<int, int>(1173, 990),  // 4th row
      std::pair<int, int>(1467, 180), std::pair<int, int>(1467, 450), std::pair<int, int>(1467, 720), std::pair<int, int>(1467, 990),  // 5th row
      std::pair<int, int>(1761, 180), std::pair<int, int>(1761, 450), std::pair<int, int>(1761, 720), std::pair<int, int>(1761, 990)   // 6th row
  };

  // icon locations depend on number of icons in dock
  const std::vector<std::vector<std::pair<int, int>>> kIphone13Dock = {
      {},
      {std::vector<std::pair<int, int>>{std::pair<int, int>(2352, 585)}},
      {std::vector<std::pair<int, int>>{std::pair<int, int>(2352, 350), std::pair<int, int>(2352, 720)}},
      {std::vector<std::pair<int, int>>{std::pair<int, int>(2352, 315), std::pair<int, int>(2352, 585), std::pair<int, int>(2352, 855)}},
      {std::vector<std::pair<int, int>>{std::pair<int, int>(2352, 180), std::pair<int, int>(2352, 450), std::pair<int, int>(2352, 720), std::pair<int, int>(2352, 990)}}  // dock
  };
}

#endif //MOSAIC_EXTRACT_EXAMPLE_ICONCENTERS_H_
