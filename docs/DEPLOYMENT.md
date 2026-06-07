# Raspberry Pi 4 Deployment

## 1. Install dependencies

```bash
sudo apt install libopencv-dev cmake
pip install ultralytics onnx onnxruntime
```

## 2. Export and quantise YOLOv8-nano

```bash
yolo export model=yolov8n.pt format=tflite int8
# Output: yolov8n_int8.tflite (~7 MB)
```

## 3. Build C++ runner

```bash
cd cpp/build
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/rpi4.cmake ..
make -j4
```

## 4. Power profiling

Use a USB power meter on the Pi 4 under sustained 22 FPS inference. Target: **≤ 3.5 W**.

## 5. Expected results

| Stage | Latency | FPS |
|-------|--------:|----:|
| FP32 ONNX | ~42 ms | 24 |
| INT8 TFLite | ~45 ms | 22 |
| MobileNet baseline | ~71 ms | 14 |
