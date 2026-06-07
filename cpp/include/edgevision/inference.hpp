#pragma once

#include <string>

struct InferenceConfig {
    std::string model_path = "models/yolov8n-int8.tflite";
    int input_width = 640;
    int input_height = 640;
    float confidence_threshold = 0.45f;
    int target_fps = 22;
};

struct BenchmarkResult {
    double avg_latency_ms;
    double fps;
    double power_w;
};

BenchmarkResult run_inference_loop(const InferenceConfig& config, int frames = 300);
