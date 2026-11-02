#include "ImageToFramebufferDecoder.h"

#include <Logging.h>

bool ImageToFramebufferDecoder::validateImageDimensions(int width, int height, const std::string& format) {
  if (width <= 0 || height <= 0) {
    LOG_ERR("IMG", "Invalid image dimensions (%dx%d %s)", width, height, format.c_str());
    return false;
  }

  const long long pixelCount = static_cast<long long>(width) * static_cast<long long>(height);
  if (pixelCount > MAX_SOURCE_PIXELS) {
    LOG_ERR("IMG", "Image too large (%dx%d = %lld pixels %s), max supported: %d pixels", width, height, pixelCount,
            format.c_str(), MAX_SOURCE_PIXELS);
    return false;
  }
  return true;
}

void ImageToFramebufferDecoder::warnUnsupportedFeature(const std::string& feature, const std::string& imagePath) {
  LOG_ERR("IMG", "Warning: Unsupported feature '%s' in image '%s'. Image may not display correctly.", feature.c_str(),
          imagePath.c_str());
}
