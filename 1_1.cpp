#include <cstdio>
// #include <array>
const size_t kBufferSize = 80;
using namespace std;
void updateWave(const double timeInterval,double* x, double* speed) {
    (*x) += timeInterval * (*speed);
    if ((*x) > 1.0) {
        (*speed) *= -1.0;
        (*x) = 1.0 + timeInterval * (*speed);
    }
    else if ((*x) < 0.0) {
        (*speed) *= -1.0;
        (*x) = timeInterval * (*speed);
    }
}

#include <cmath>

void accumulateWaveToHeightField(
    const double x,
    const double waveLength,
    const double maxHeight,
    array<double, kBufferSize>* heightField
) {
    const double quarterWaveLength = 0.25 * waveLength;
    const int start = static_cast<int>((x - quarterWaveLength) * kBufferSize);
    const int end = static_cast<int>(())
}

int main() {
    const double waveLengthX = 0.8;
    const double waveLengthY = 1.2;

    const double maxHeightX = 0.5;
    const double maxHeightY = 0.4;

    double x = 0.0;
    double y = 1.0;
    double speedX = 1.0;
    double speedY = -0.5;

    const int fps = 100;
    const double timeInterval = 1.0 / fps;

    array<double, kBufferSize> heightField;

    for (int i = 0; i < 1000;++i) {
        updateWave(timeInterval, &x, &speedX);
        updateWave(timeInterval, &y, &speedY);
    }


    return 0;
}