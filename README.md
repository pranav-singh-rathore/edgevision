# EdgeVision

Real-time object detection on **embedded Linux** (Raspberry Pi 4 / ARM Cortex-A72) using **YOLOv8-nano**, TensorFlow Lite, and OpenCV.

## Highlights

| Metric | Result |
|--------|--------|
| Inference speed | **22 FPS** (YOLOv8-nano, Pi 4) |
| Power budget | **3.5 W** sustained |
| Model size (INT8) | **7 MB** (from 28 MB FP32) |
| vs MobileNet baseline | **47% faster** inference, <2% mAP loss |

## Architecture

```
Camera (V4L2) → OpenCV preprocess → TFLite INT8 YOLOv8-nano → NMS → Display / MQTT
```

## Quick start

```bash
python -m venv .venv && source .venv/bin/activate
pip install -r requirements.txt
python python/benchmark.py --output results
python python/quantize_model.py --output results/quantization.json
```

### C++ inference (embedded target)

```bash
cd cpp && mkdir build && cd build
cmake .. && make -j
./edgevision_infer
```

Cross-compile for Raspberry Pi 4 with `aarch64-linux-gnu-g++` and link TensorFlow Lite.

## Benchmarks

Run `python python/benchmark.py` to regenerate `results/BENCHMARK.md`. Compares:

- MobileNetV3-SSD
- EfficientDet-Lite0
- **YOLOv8-nano** ← production choice
- NanoDet-Plus

## Deployment guide

See [docs/DEPLOYMENT.md](docs/DEPLOYMENT.md) for Raspberry Pi setup, power profiling, and INT8 conversion steps.

## Stack

C++ · Python · TensorFlow Lite · OpenCV · YOLOv8 · ARM Cortex-A72 · Raspberry Pi 4

## License

MIT
