# Astrion Fusion Engine 星宸——可扩展的多源融合定位导航引擎

A next-generation multi-sensor fusion engine for intelligent positioning, navigation, and spatial perception.

新一代智能定位、导航与空间感知多传感器融合引擎。

## Features 特性

- GNSS/INS Fusion 卫星导航/惯性导航融合
- VIO & SLAM 视觉里程计与实时建图
- AI-assisted Localization 人工智能辅助定位
- Multi-modal Perception 多模态感知
- Edge Computing Support 边缘计算支持

## QuickStart 快速上手

### 1. 克隆项目仓库

首先将 Astrion Fusion Engine 项目下载到本地：

```bash
git clone https://github.com/your-username/astrion-fusion-engine.git
```

进入项目目录：

```bash
cd astrion-fusion-engine
```

---

### 2. 创建 Python 虚拟环境

为了避免不同项目之间的依赖冲突，推荐使用 Python 虚拟环境。

创建虚拟环境：

```bash
python -m venv venv
```

创建完成后，项目目录下会生成一个名为 `venv` 的虚拟环境文件夹。

---

### 3. 激活虚拟环境

#### Windows

```bash
venv\Scripts\activate
```

激活成功后，终端前面通常会出现：

```bash
(venv)
```

说明当前已经进入项目独立环境。

---

#### Linux / macOS

```bash
source venv/bin/activate
```

---

### 4. 安装项目依赖

项目运行所需的 Python 库统一写在：

```text
requirements.txt
```

使用以下命令自动安装：

```bash
pip install -r requirements.txt
```

首次安装可能需要几分钟时间。

---

### 5. 配置系统参数

系统参数统一保存在：

```text
configs/system.yaml
```

你可以根据自己的硬件设备修改配置。

示例配置：

```yaml
sensor:
  imu: true
  gnss: true
  camera: false

communication:
  mqtt: true
  serial_port: COM3
```

参数说明：

| 参数        | 作用                    |
| ----------- | ----------------------- |
| imu         | 是否启用 IMU 惯性传感器 |
| gnss        | 是否启用 GNSS 定位模块  |
| camera      | 是否启用视觉摄像头      |
| mqtt        | 是否启用 MQTT 通信      |
| serial_port | 设备串口号              |

Windows 常见串口：

```text
COM3
COM4
COM5
```

Linux 常见串口：

```text
/dev/ttyUSB0
/dev/ttyACM0
```

---

### 6. 启动融合引擎

运行主程序：

```bash
python backend/main.py
```

系统启动后将开始：

- 接收传感器数据
- 执行多传感器融合
- 计算定位与姿态
- 输出实时状态信息

---

### 7. 启动前端可视化界面（可选）

如果需要 Web 可视化界面，可以启动前端系统。

进入前端目录：

```bash
cd frontend
```

安装前端依赖：

```bash
npm install
```

启动开发服务器：

```bash
npm run dev
```

启动成功后，终端会显示本地访问地址，例如：

```text
http://localhost:5173
```

使用浏览器打开即可查看系统可视化界面。

---

### 8. 连接嵌入式设备

目前支持以下设备：

- ESP32-S3
- Witmotion JY901B IMU
- Witmotion WTGPS+BT

连接完成后，系统会自动读取：

- IMU 数据
- GNSS 定位数据
- 传感器状态信息

---

### 9. 系统输出内容

Astrion Fusion Engine 当前支持：

- 实时定位
- 多传感器融合
- 姿态解算
- 空间感知
- 导航可视化
- 传感器遥测
- MQTT 数据通信

系统输出结果默认保存在：

```text
outputs/
```

## Architecture 技术架构

1. ***Sensors Layer  采集层***
   (GNSS / IMU / Camera)
2. ***Communication Layer  通信层***
   (MQTT / Serial / WebSocket)
3. ***Fusion Layer 融合层***
   (ESKF / VIO / AI Fusion)
4. ***Perception Layer* *感知层***
   (SLAM / Semantic Perception)
5. ***Application Layer 应用层***
   (Web Visualization / Navigation)

## Tech Stack 技术栈

- 前端 Frontend: **Vue 3 + TypeScript**
- 后端 Backend: **Python + FastAPI**
- AI框架 AI Framework: **PyTorch**
- 嵌入式平台 Embedded Platform: **Espressif ESP32-S3-WROOM-1**
- **通信协议 Communication: **4G IoT + MQTT****

## Project Structure 项目架构

astrion-fusion-engine/
│
├── README.md		#说明
├── LICENSE			#权限证明
├── .gitignore			#github隐藏项
├── requirements.txt	#Python依赖库
├── pyproject.toml		#Python配置
├── package.json		#Node.js前端配置
│
├── docs/               	# 文档
├── data/                	# 样例数据
├── models/             	# AI模型
├── configs/             	# 配置文件
├── scripts/             	# 工具脚本
├── tests/               	# 测试
│
├── backend/           		# Python后端
│   ├── api/				#接口服务（FastAPI接口、WebSocket、数据查询接口）
│   ├── fusion/			#多传感器融合算法（GNSS/INS融合、ESKF、卡尔曼滤波）
│   ├── localization/	#定位解算（坐标转换、轨迹解算、PDR、VIO定位）
│   └── perception/		#感知算法（YOLO、SAM、BLIP-2、视觉识别、语义感知）
│
├─frontend/
│   ├──src/					#核心源码
│   │├──views/				#页面目录
│   │├── components/		#可复用组件
│   │├── api/				#前后端通信
│   │└── main.ts			#前端程序入口
│   └── public/				#静态资源
│
├── firmware/            # ESP32/STM32代码
│   ├── esp32/
│   └── k320mini/
│
├── datasets/            # 原始数据集
│
└── outputs/             # 输出结果


## License

This project is licensed under the MIT License.
