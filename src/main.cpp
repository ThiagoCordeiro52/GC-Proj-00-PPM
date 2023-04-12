#include <cstdint>
#include <iostream>

struct RGBColor {
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;
};

constexpr RGBColor red{255, 0, 0};
constexpr RGBColor green{0, 255, 0};
constexpr RGBColor blue{0, 0, 255};


RGBColor lerp(const RGBColor &A, const RGBColor &B, float t) {
  RGBColor color {
     (1 - t) * A.r + t * B.r,
     (1 - t) * A.g + t * B.g,
     (1 - t) * A.b + t * B.b,
  };
  return color;
}

int main(int argc, char *argv[]) {
  size_t W{400};
  size_t H{200};
  RGBColor leftTop {0, 255, 51};
  RGBColor rightTop {255, 255, 51};
  RGBColor leftBottom {0, 0, 51};
  RGBColor rightBottom {255, 0, 51};

  std::cout << "P3\n";
  std::cout << W << " " << H << '\n';
  std::cout << "255\n";
  for (auto row{0}; row < H; ++row) {
    for (auto col{0}; col < W; ++col) {
      float y = ((float) row) / H;
      float x = ((float) col / W);
      RGBColor firstColor = lerp(leftTop, rightTop, x);
      RGBColor secondColor = lerp(leftBottom, rightBottom, x);
      RGBColor finalColor = lerp(firstColor, secondColor, y);
      std::cout << (short) finalColor.r << ' '
                << (short) finalColor.g << ' '
                << (short) finalColor.b << '\n';
    }
  }
  return 0;
}
