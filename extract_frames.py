import cv2
import os

# รายการ path ของวิดีโอทั้งหมด
video_paths = [
    "/home/mix/video1 ip_cam 60/20250811_20250811105019_20250811105922_105018.mp4",
    "/home/mix/video1 ip_cam 60/20250811_20250811110704_20250811111505_110703.mp4",
    "/home/mix/video1 ip_cam 64/20250811_20340103195649_20340103200547_105021.mp4",
    "/home/mix/video1 ip_cam 64/20250811_20340103201334_20340103202137_110705.mp4",
    "/home/mix/video2 ip_cam 60/20250811_20250811113636_20250811115806_113635.mp4",
    "/home/mix/video2 ip_cam 60/20250811_20250811115850_20250811120620_115849.mp4",
    "/home/mix/video2 ip_cam 64/20250811_20340103204306_20340103210438_113638.mp4",
    "/home/mix/video2 ip_cam 64/20250811_20340103210520_20340103211253_115852.mp4",
]

# โฟลเดอร์สำหรับเก็บผลลัพธ์
output_root = "/home/mix/frames"
os.makedirs(output_root, exist_ok=True)

# ดึง frame ทุกๆ n เฟรม (เช่น ทุกๆ 30 เฟรม ~ 1 วินาทีถ้าวิดีโอ 30 fps)
frame_interval = 30

for video_path in video_paths:
    # ตั้งชื่อโฟลเดอร์สำหรับวิดีโอนี้
    video_name = os.path.splitext(os.path.basename(video_path))[0]
    output_dir = os.path.join(output_root, video_name)
    os.makedirs(output_dir, exist_ok=True)

    cap = cv2.VideoCapture(video_path)
    if not cap.isOpened():
        print(f"❌ เปิดวิดีโอไม่ได้: {video_path}")
        continue

    frame_count = 0
    saved_count = 0

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        if frame_count % frame_interval == 0:
            frame_filename = os.path.join(output_dir, f"frame_{saved_count:05d}.jpg")
            cv2.imwrite(frame_filename, frame)
            saved_count += 1

        frame_count += 1

    cap.release()
    print(f"✅ {video_path} -> บันทึก {saved_count} เฟรมที่ {output_dir}")

