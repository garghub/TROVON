void vivid_lock(struct vb2_queue *vq)
{
struct vivid_dev *dev = vb2_get_drv_priv(vq);
mutex_lock(&dev->mutex);
}
void vivid_unlock(struct vb2_queue *vq)
{
struct vivid_dev *dev = vb2_get_drv_priv(vq);
mutex_unlock(&dev->mutex);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
strcpy(cap->driver, "vivid");
strcpy(cap->card, "vivid");
snprintf(cap->bus_info, sizeof(cap->bus_info),
"platform:%s", dev->v4l2_dev.name);
if (vdev->vfl_type == VFL_TYPE_GRABBER && vdev->vfl_dir == VFL_DIR_RX)
cap->device_caps = dev->vid_cap_caps;
if (vdev->vfl_type == VFL_TYPE_GRABBER && vdev->vfl_dir == VFL_DIR_TX)
cap->device_caps = dev->vid_out_caps;
else if (vdev->vfl_type == VFL_TYPE_VBI && vdev->vfl_dir == VFL_DIR_RX)
cap->device_caps = dev->vbi_cap_caps;
else if (vdev->vfl_type == VFL_TYPE_VBI && vdev->vfl_dir == VFL_DIR_TX)
cap->device_caps = dev->vbi_out_caps;
else if (vdev->vfl_type == VFL_TYPE_SDR)
cap->device_caps = dev->sdr_cap_caps;
else if (vdev->vfl_type == VFL_TYPE_RADIO && vdev->vfl_dir == VFL_DIR_RX)
cap->device_caps = dev->radio_rx_caps;
else if (vdev->vfl_type == VFL_TYPE_RADIO && vdev->vfl_dir == VFL_DIR_TX)
cap->device_caps = dev->radio_tx_caps;
cap->capabilities = dev->vid_cap_caps | dev->vid_out_caps |
dev->vbi_cap_caps | dev->vbi_out_caps |
dev->radio_rx_caps | dev->radio_tx_caps |
dev->sdr_cap_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_s_hw_freq_seek(struct file *file, void *fh, const struct v4l2_hw_freq_seek *a)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_rx_s_hw_freq_seek(file, fh, a);
return -ENOTTY;
}
static int vidioc_enum_freq_bands(struct file *file, void *fh, struct v4l2_frequency_band *band)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_rx_enum_freq_bands(file, fh, band);
if (vdev->vfl_type == VFL_TYPE_SDR)
return vivid_sdr_enum_freq_bands(file, fh, band);
return -ENOTTY;
}
static int vidioc_g_tuner(struct file *file, void *fh, struct v4l2_tuner *vt)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_rx_g_tuner(file, fh, vt);
if (vdev->vfl_type == VFL_TYPE_SDR)
return vivid_sdr_g_tuner(file, fh, vt);
return vivid_video_g_tuner(file, fh, vt);
}
static int vidioc_s_tuner(struct file *file, void *fh, const struct v4l2_tuner *vt)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_rx_s_tuner(file, fh, vt);
if (vdev->vfl_type == VFL_TYPE_SDR)
return vivid_sdr_s_tuner(file, fh, vt);
return vivid_video_s_tuner(file, fh, vt);
}
static int vidioc_g_frequency(struct file *file, void *fh, struct v4l2_frequency *vf)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_g_frequency(file,
vdev->vfl_dir == VFL_DIR_RX ?
&dev->radio_rx_freq : &dev->radio_tx_freq, vf);
if (vdev->vfl_type == VFL_TYPE_SDR)
return vivid_sdr_g_frequency(file, fh, vf);
return vivid_video_g_frequency(file, fh, vf);
}
static int vidioc_s_frequency(struct file *file, void *fh, const struct v4l2_frequency *vf)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_type == VFL_TYPE_RADIO)
return vivid_radio_s_frequency(file,
vdev->vfl_dir == VFL_DIR_RX ?
&dev->radio_rx_freq : &dev->radio_tx_freq, vf);
if (vdev->vfl_type == VFL_TYPE_SDR)
return vivid_sdr_s_frequency(file, fh, vf);
return vivid_video_s_frequency(file, fh, vf);
}
static int vidioc_overlay(struct file *file, void *fh, unsigned i)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_overlay(file, fh, i);
return vivid_vid_out_overlay(file, fh, i);
}
static int vidioc_g_fbuf(struct file *file, void *fh, struct v4l2_framebuffer *a)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_g_fbuf(file, fh, a);
return vivid_vid_out_g_fbuf(file, fh, a);
}
static int vidioc_s_fbuf(struct file *file, void *fh, const struct v4l2_framebuffer *a)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_s_fbuf(file, fh, a);
return vivid_vid_out_s_fbuf(file, fh, a);
}
static int vidioc_s_std(struct file *file, void *fh, v4l2_std_id id)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_s_std(file, fh, id);
return vivid_vid_out_s_std(file, fh, id);
}
static int vidioc_s_dv_timings(struct file *file, void *fh, struct v4l2_dv_timings *timings)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_s_dv_timings(file, fh, timings);
return vivid_vid_out_s_dv_timings(file, fh, timings);
}
static int vidioc_cropcap(struct file *file, void *fh, struct v4l2_cropcap *cc)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_cropcap(file, fh, cc);
return vivid_vid_out_cropcap(file, fh, cc);
}
static int vidioc_g_selection(struct file *file, void *fh,
struct v4l2_selection *sel)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_g_selection(file, fh, sel);
return vivid_vid_out_g_selection(file, fh, sel);
}
static int vidioc_s_selection(struct file *file, void *fh,
struct v4l2_selection *sel)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_s_selection(file, fh, sel);
return vivid_vid_out_s_selection(file, fh, sel);
}
static int vidioc_g_parm(struct file *file, void *fh,
struct v4l2_streamparm *parm)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_g_parm(file, fh, parm);
return vivid_vid_out_g_parm(file, fh, parm);
}
static int vidioc_s_parm(struct file *file, void *fh,
struct v4l2_streamparm *parm)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_vid_cap_s_parm(file, fh, parm);
return vivid_vid_out_g_parm(file, fh, parm);
}
static ssize_t vivid_radio_read(struct file *file, char __user *buf,
size_t size, loff_t *offset)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_TX)
return -EINVAL;
return vivid_radio_rx_read(file, buf, size, offset);
}
static ssize_t vivid_radio_write(struct file *file, const char __user *buf,
size_t size, loff_t *offset)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return -EINVAL;
return vivid_radio_tx_write(file, buf, size, offset);
}
static unsigned int vivid_radio_poll(struct file *file, struct poll_table_struct *wait)
{
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX)
return vivid_radio_rx_poll(file, wait);
return vivid_radio_tx_poll(file, wait);
}
static bool vivid_is_in_use(struct video_device *vdev)
{
unsigned long flags;
bool res;
spin_lock_irqsave(&vdev->fh_lock, flags);
res = !list_empty(&vdev->fh_list);
spin_unlock_irqrestore(&vdev->fh_lock, flags);
return res;
}
static bool vivid_is_last_user(struct vivid_dev *dev)
{
unsigned uses = vivid_is_in_use(&dev->vid_cap_dev) +
vivid_is_in_use(&dev->vid_out_dev) +
vivid_is_in_use(&dev->vbi_cap_dev) +
vivid_is_in_use(&dev->vbi_out_dev) +
vivid_is_in_use(&dev->sdr_cap_dev) +
vivid_is_in_use(&dev->radio_rx_dev) +
vivid_is_in_use(&dev->radio_tx_dev);
return uses == 1;
}
static int vivid_fop_release(struct file *file)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
mutex_lock(&dev->mutex);
if (!no_error_inj && v4l2_fh_is_singular_file(file) &&
!video_is_registered(vdev) && vivid_is_last_user(dev)) {
v4l2_info(&dev->v4l2_dev, "reconnect\n");
set_bit(V4L2_FL_REGISTERED, &dev->vid_cap_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->vid_out_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->vbi_cap_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->vbi_out_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->sdr_cap_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->radio_rx_dev.flags);
set_bit(V4L2_FL_REGISTERED, &dev->radio_tx_dev.flags);
}
mutex_unlock(&dev->mutex);
if (file->private_data == dev->overlay_cap_owner)
dev->overlay_cap_owner = NULL;
if (file->private_data == dev->radio_rx_rds_owner) {
dev->radio_rx_rds_last_block = 0;
dev->radio_rx_rds_owner = NULL;
}
if (file->private_data == dev->radio_tx_rds_owner) {
dev->radio_tx_rds_last_block = 0;
dev->radio_tx_rds_owner = NULL;
}
if (vdev->queue)
return vb2_fop_release(file);
return v4l2_fh_release(file);
}
static int __init vivid_create_instance(int inst)
{
static const struct v4l2_dv_timings def_dv_timings =
V4L2_DV_BT_CEA_1280X720P60;
unsigned in_type_counter[4] = { 0, 0, 0, 0 };
unsigned out_type_counter[4] = { 0, 0, 0, 0 };
int ccs_cap = ccs_cap_mode[inst];
int ccs_out = ccs_out_mode[inst];
bool has_tuner;
bool has_modulator;
struct vivid_dev *dev;
struct video_device *vfd;
struct vb2_queue *q;
unsigned node_type = node_types[inst];
v4l2_std_id tvnorms_cap = 0, tvnorms_out = 0;
int ret;
int i;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->inst = inst;
snprintf(dev->v4l2_dev.name, sizeof(dev->v4l2_dev.name),
"%s-%03d", VIVID_MODULE_NAME, inst);
ret = v4l2_device_register(NULL, &dev->v4l2_dev);
if (ret)
goto free_dev;
dev->multiplanar = multiplanar[inst] > 1;
v4l2_info(&dev->v4l2_dev, "using %splanar format API\n",
dev->multiplanar ? "multi" : "single ");
dev->num_inputs = num_inputs[inst];
if (dev->num_inputs < 1)
dev->num_inputs = 1;
if (dev->num_inputs >= MAX_INPUTS)
dev->num_inputs = MAX_INPUTS;
for (i = 0; i < dev->num_inputs; i++) {
dev->input_type[i] = (input_types[inst] >> (i * 2)) & 0x3;
dev->input_name_counter[i] = in_type_counter[dev->input_type[i]]++;
}
dev->has_audio_inputs = in_type_counter[TV] && in_type_counter[SVID];
dev->num_outputs = num_outputs[inst];
if (dev->num_outputs < 1)
dev->num_outputs = 1;
if (dev->num_outputs >= MAX_OUTPUTS)
dev->num_outputs = MAX_OUTPUTS;
for (i = 0; i < dev->num_outputs; i++) {
dev->output_type[i] = ((output_types[inst] >> i) & 1) ? HDMI : SVID;
dev->output_name_counter[i] = out_type_counter[dev->output_type[i]]++;
}
dev->has_audio_outputs = out_type_counter[SVID];
dev->has_vid_cap = node_type & 0x0001;
if (in_type_counter[TV] || in_type_counter[SVID]) {
dev->has_raw_vbi_cap = node_type & 0x0004;
dev->has_sliced_vbi_cap = node_type & 0x0008;
dev->has_vbi_cap = dev->has_raw_vbi_cap | dev->has_sliced_vbi_cap;
}
dev->has_vid_out = node_type & 0x0100;
if (out_type_counter[SVID]) {
dev->has_raw_vbi_out = node_type & 0x0400;
dev->has_sliced_vbi_out = node_type & 0x0800;
dev->has_vbi_out = dev->has_raw_vbi_out | dev->has_sliced_vbi_out;
}
dev->has_radio_rx = node_type & 0x0010;
dev->has_radio_tx = node_type & 0x1000;
dev->has_sdr_cap = node_type & 0x0020;
has_tuner = ((dev->has_vid_cap || dev->has_vbi_cap) && in_type_counter[TV]) ||
dev->has_radio_rx || dev->has_sdr_cap;
has_modulator = dev->has_radio_tx;
if (dev->has_vid_cap)
dev->has_fb = node_type & 0x10000;
if (no_error_inj && ccs_cap == -1)
ccs_cap = 7;
if (ccs_cap != -1) {
dev->has_crop_cap = ccs_cap & 1;
dev->has_compose_cap = ccs_cap & 2;
dev->has_scaler_cap = ccs_cap & 4;
v4l2_info(&dev->v4l2_dev, "Capture Crop: %c Compose: %c Scaler: %c\n",
dev->has_crop_cap ? 'Y' : 'N',
dev->has_compose_cap ? 'Y' : 'N',
dev->has_scaler_cap ? 'Y' : 'N');
}
if (no_error_inj && ccs_out == -1)
ccs_out = 7;
if (ccs_out != -1) {
dev->has_crop_out = ccs_out & 1;
dev->has_compose_out = ccs_out & 2;
dev->has_scaler_out = ccs_out & 4;
v4l2_info(&dev->v4l2_dev, "Output Crop: %c Compose: %c Scaler: %c\n",
dev->has_crop_out ? 'Y' : 'N',
dev->has_compose_out ? 'Y' : 'N',
dev->has_scaler_out ? 'Y' : 'N');
}
if (dev->has_vid_cap) {
dev->vid_cap_caps = dev->multiplanar ?
V4L2_CAP_VIDEO_CAPTURE_MPLANE :
V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OVERLAY;
dev->vid_cap_caps |= V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
if (dev->has_audio_inputs)
dev->vid_cap_caps |= V4L2_CAP_AUDIO;
if (in_type_counter[TV])
dev->vid_cap_caps |= V4L2_CAP_TUNER;
}
if (dev->has_vid_out) {
dev->vid_out_caps = dev->multiplanar ?
V4L2_CAP_VIDEO_OUTPUT_MPLANE :
V4L2_CAP_VIDEO_OUTPUT;
if (dev->has_fb)
dev->vid_out_caps |= V4L2_CAP_VIDEO_OUTPUT_OVERLAY;
dev->vid_out_caps |= V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
if (dev->has_audio_outputs)
dev->vid_out_caps |= V4L2_CAP_AUDIO;
}
if (dev->has_vbi_cap) {
dev->vbi_cap_caps = (dev->has_raw_vbi_cap ? V4L2_CAP_VBI_CAPTURE : 0) |
(dev->has_sliced_vbi_cap ? V4L2_CAP_SLICED_VBI_CAPTURE : 0);
dev->vbi_cap_caps |= V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
if (dev->has_audio_inputs)
dev->vbi_cap_caps |= V4L2_CAP_AUDIO;
if (in_type_counter[TV])
dev->vbi_cap_caps |= V4L2_CAP_TUNER;
}
if (dev->has_vbi_out) {
dev->vbi_out_caps = (dev->has_raw_vbi_out ? V4L2_CAP_VBI_OUTPUT : 0) |
(dev->has_sliced_vbi_out ? V4L2_CAP_SLICED_VBI_OUTPUT : 0);
dev->vbi_out_caps |= V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
if (dev->has_audio_outputs)
dev->vbi_out_caps |= V4L2_CAP_AUDIO;
}
if (dev->has_sdr_cap) {
dev->sdr_cap_caps = V4L2_CAP_SDR_CAPTURE | V4L2_CAP_TUNER;
dev->sdr_cap_caps |= V4L2_CAP_STREAMING | V4L2_CAP_READWRITE;
}
if (dev->has_radio_rx)
dev->radio_rx_caps = V4L2_CAP_RADIO | V4L2_CAP_RDS_CAPTURE |
V4L2_CAP_HW_FREQ_SEEK | V4L2_CAP_TUNER |
V4L2_CAP_READWRITE;
if (dev->has_radio_tx)
dev->radio_tx_caps = V4L2_CAP_RDS_OUTPUT | V4L2_CAP_MODULATOR |
V4L2_CAP_READWRITE;
tpg_init(&dev->tpg, 640, 360);
if (tpg_alloc(&dev->tpg, MAX_ZOOM * MAX_WIDTH))
goto free_dev;
dev->scaled_line = vzalloc(MAX_ZOOM * MAX_WIDTH);
if (!dev->scaled_line)
goto free_dev;
dev->blended_line = vzalloc(MAX_ZOOM * MAX_WIDTH);
if (!dev->blended_line)
goto free_dev;
dev->edid = vmalloc(256 * 128);
if (!dev->edid)
goto free_dev;
while (v4l2_dv_timings_presets[dev->query_dv_timings_size].bt.width)
dev->query_dv_timings_size++;
dev->query_dv_timings_qmenu = kmalloc(dev->query_dv_timings_size *
(sizeof(void *) + 32), GFP_KERNEL);
if (dev->query_dv_timings_qmenu == NULL)
goto free_dev;
for (i = 0; i < dev->query_dv_timings_size; i++) {
const struct v4l2_bt_timings *bt = &v4l2_dv_timings_presets[i].bt;
char *p = (char *)&dev->query_dv_timings_qmenu[dev->query_dv_timings_size];
u32 htot, vtot;
p += i * 32;
dev->query_dv_timings_qmenu[i] = p;
htot = V4L2_DV_BT_FRAME_WIDTH(bt);
vtot = V4L2_DV_BT_FRAME_HEIGHT(bt);
snprintf(p, 32, "%ux%u%s%u",
bt->width, bt->height, bt->interlaced ? "i" : "p",
(u32)bt->pixelclock / (htot * vtot));
}
if (!dev->has_audio_inputs) {
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_AUDIO);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_AUDIO);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_ENUMAUDIO);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_S_AUDIO);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_G_AUDIO);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_ENUMAUDIO);
}
if (!dev->has_audio_outputs) {
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_S_AUDOUT);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_AUDOUT);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_ENUMAUDOUT);
v4l2_disable_ioctl(&dev->vbi_out_dev, VIDIOC_S_AUDOUT);
v4l2_disable_ioctl(&dev->vbi_out_dev, VIDIOC_G_AUDOUT);
v4l2_disable_ioctl(&dev->vbi_out_dev, VIDIOC_ENUMAUDOUT);
}
if (!in_type_counter[TV] && !in_type_counter[SVID]) {
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_STD);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_STD);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_ENUMSTD);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_QUERYSTD);
}
if (!out_type_counter[SVID]) {
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_S_STD);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_STD);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_ENUMSTD);
}
if (!has_tuner && !has_modulator) {
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_G_FREQUENCY);
}
if (!has_tuner) {
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_TUNER);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_TUNER);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_S_TUNER);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_G_TUNER);
}
if (in_type_counter[HDMI] == 0) {
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_EDID);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_EDID);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_DV_TIMINGS_CAP);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_G_DV_TIMINGS);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_DV_TIMINGS);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_ENUM_DV_TIMINGS);
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_QUERY_DV_TIMINGS);
}
if (out_type_counter[HDMI] == 0) {
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_EDID);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_DV_TIMINGS_CAP);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_DV_TIMINGS);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_S_DV_TIMINGS);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_ENUM_DV_TIMINGS);
}
if (!dev->has_fb) {
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_FBUF);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_S_FBUF);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_OVERLAY);
}
v4l2_disable_ioctl(&dev->vid_cap_dev, VIDIOC_S_HW_FREQ_SEEK);
v4l2_disable_ioctl(&dev->vbi_cap_dev, VIDIOC_S_HW_FREQ_SEEK);
v4l2_disable_ioctl(&dev->sdr_cap_dev, VIDIOC_S_HW_FREQ_SEEK);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_G_FREQUENCY);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_ENUM_FRAMESIZES);
v4l2_disable_ioctl(&dev->vid_out_dev, VIDIOC_ENUM_FRAMEINTERVALS);
v4l2_disable_ioctl(&dev->vbi_out_dev, VIDIOC_S_FREQUENCY);
v4l2_disable_ioctl(&dev->vbi_out_dev, VIDIOC_G_FREQUENCY);
dev->fmt_cap = &vivid_formats[0];
dev->fmt_out = &vivid_formats[0];
if (!dev->multiplanar)
vivid_formats[0].data_offset[0] = 0;
dev->webcam_size_idx = 1;
dev->webcam_ival_idx = 3;
tpg_s_fourcc(&dev->tpg, dev->fmt_cap->fourcc);
dev->std_cap = V4L2_STD_PAL;
dev->std_out = V4L2_STD_PAL;
if (dev->input_type[0] == TV || dev->input_type[0] == SVID)
tvnorms_cap = V4L2_STD_ALL;
if (dev->output_type[0] == SVID)
tvnorms_out = V4L2_STD_ALL;
dev->dv_timings_cap = def_dv_timings;
dev->dv_timings_out = def_dv_timings;
dev->tv_freq = 2804 ;
dev->tv_audmode = V4L2_TUNER_MODE_STEREO;
dev->tv_field_cap = V4L2_FIELD_INTERLACED;
dev->tv_field_out = V4L2_FIELD_INTERLACED;
dev->radio_rx_freq = 95000 * 16;
dev->radio_rx_audmode = V4L2_TUNER_MODE_STEREO;
if (dev->has_radio_tx) {
dev->radio_tx_freq = 95500 * 16;
dev->radio_rds_loop = false;
}
dev->radio_tx_subchans = V4L2_TUNER_SUB_STEREO | V4L2_TUNER_SUB_RDS;
dev->sdr_adc_freq = 300000;
dev->sdr_fm_freq = 50000000;
dev->edid_max_blocks = dev->edid_blocks = 2;
memcpy(dev->edid, vivid_hdmi_edid, sizeof(vivid_hdmi_edid));
ktime_get_ts(&dev->radio_rds_init_ts);
ret = vivid_create_controls(dev, ccs_cap == -1, ccs_out == -1, no_error_inj,
in_type_counter[TV] || in_type_counter[SVID] ||
out_type_counter[SVID],
in_type_counter[HDMI] || out_type_counter[HDMI]);
if (ret)
goto unreg_dev;
vivid_update_format_cap(dev, false);
vivid_update_format_out(dev);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_vid_cap);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_vid_out);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_vbi_cap);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_vbi_out);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_radio_rx);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_radio_tx);
v4l2_ctrl_handler_setup(&dev->ctrl_hdl_sdr_cap);
dev->fb_cap.fmt.width = dev->src_rect.width;
dev->fb_cap.fmt.height = dev->src_rect.height;
dev->fb_cap.fmt.pixelformat = dev->fmt_cap->fourcc;
dev->fb_cap.fmt.bytesperline = dev->src_rect.width * tpg_g_twopixelsize(&dev->tpg, 0) / 2;
dev->fb_cap.fmt.sizeimage = dev->src_rect.height * dev->fb_cap.fmt.bytesperline;
spin_lock_init(&dev->slock);
mutex_init(&dev->mutex);
INIT_LIST_HEAD(&dev->vid_cap_active);
INIT_LIST_HEAD(&dev->vid_out_active);
INIT_LIST_HEAD(&dev->vbi_cap_active);
INIT_LIST_HEAD(&dev->vbi_out_active);
INIT_LIST_HEAD(&dev->sdr_cap_active);
if (dev->has_vid_cap) {
q = &dev->vb_vid_cap_q;
q->type = dev->multiplanar ? V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE :
V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivid_buffer);
q->ops = &vivid_vid_cap_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
}
if (dev->has_vid_out) {
q = &dev->vb_vid_out_q;
q->type = dev->multiplanar ? V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE :
V4L2_BUF_TYPE_VIDEO_OUTPUT;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_WRITE;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivid_buffer);
q->ops = &vivid_vid_out_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
}
if (dev->has_vbi_cap) {
q = &dev->vb_vbi_cap_q;
q->type = dev->has_raw_vbi_cap ? V4L2_BUF_TYPE_VBI_CAPTURE :
V4L2_BUF_TYPE_SLICED_VBI_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivid_buffer);
q->ops = &vivid_vbi_cap_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
}
if (dev->has_vbi_out) {
q = &dev->vb_vbi_out_q;
q->type = dev->has_raw_vbi_out ? V4L2_BUF_TYPE_VBI_OUTPUT :
V4L2_BUF_TYPE_SLICED_VBI_OUTPUT;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_WRITE;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivid_buffer);
q->ops = &vivid_vbi_out_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 2;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
}
if (dev->has_sdr_cap) {
q = &dev->vb_sdr_cap_q;
q->type = V4L2_BUF_TYPE_SDR_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct vivid_buffer);
q->ops = &vivid_sdr_cap_qops;
q->mem_ops = &vb2_vmalloc_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->min_buffers_needed = 8;
ret = vb2_queue_init(q);
if (ret)
goto unreg_dev;
}
if (dev->has_fb) {
ret = vivid_fb_init(dev);
if (ret)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "Framebuffer device registered as fb%d\n",
dev->fb_info.node);
}
if (dev->has_vid_cap) {
vfd = &dev->vid_cap_dev;
strlcpy(vfd->name, "vivid-vid-cap", sizeof(vfd->name));
vfd->fops = &vivid_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = &dev->vb_vid_cap_q;
vfd->tvnorms = tvnorms_cap;
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_GRABBER, vid_cap_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 capture device registered as %s\n",
video_device_node_name(vfd));
}
if (dev->has_vid_out) {
vfd = &dev->vid_out_dev;
strlcpy(vfd->name, "vivid-vid-out", sizeof(vfd->name));
vfd->vfl_dir = VFL_DIR_TX;
vfd->fops = &vivid_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = &dev->vb_vid_out_q;
vfd->tvnorms = tvnorms_out;
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_GRABBER, vid_out_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 output device registered as %s\n",
video_device_node_name(vfd));
}
if (dev->has_vbi_cap) {
vfd = &dev->vbi_cap_dev;
strlcpy(vfd->name, "vivid-vbi-cap", sizeof(vfd->name));
vfd->fops = &vivid_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = &dev->vb_vbi_cap_q;
vfd->lock = &dev->mutex;
vfd->tvnorms = tvnorms_cap;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_VBI, vbi_cap_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 capture device registered as %s, supports %s VBI\n",
video_device_node_name(vfd),
(dev->has_raw_vbi_cap && dev->has_sliced_vbi_cap) ?
"raw and sliced" :
(dev->has_raw_vbi_cap ? "raw" : "sliced"));
}
if (dev->has_vbi_out) {
vfd = &dev->vbi_out_dev;
strlcpy(vfd->name, "vivid-vbi-out", sizeof(vfd->name));
vfd->vfl_dir = VFL_DIR_TX;
vfd->fops = &vivid_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = &dev->vb_vbi_out_q;
vfd->lock = &dev->mutex;
vfd->tvnorms = tvnorms_out;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_VBI, vbi_out_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 output device registered as %s, supports %s VBI\n",
video_device_node_name(vfd),
(dev->has_raw_vbi_out && dev->has_sliced_vbi_out) ?
"raw and sliced" :
(dev->has_raw_vbi_out ? "raw" : "sliced"));
}
if (dev->has_sdr_cap) {
vfd = &dev->sdr_cap_dev;
strlcpy(vfd->name, "vivid-sdr-cap", sizeof(vfd->name));
vfd->fops = &vivid_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->queue = &dev->vb_sdr_cap_q;
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_SDR, sdr_cap_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 capture device registered as %s\n",
video_device_node_name(vfd));
}
if (dev->has_radio_rx) {
vfd = &dev->radio_rx_dev;
strlcpy(vfd->name, "vivid-rad-rx", sizeof(vfd->name));
vfd->fops = &vivid_radio_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_RADIO, radio_rx_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 receiver device registered as %s\n",
video_device_node_name(vfd));
}
if (dev->has_radio_tx) {
vfd = &dev->radio_tx_dev;
strlcpy(vfd->name, "vivid-rad-tx", sizeof(vfd->name));
vfd->vfl_dir = VFL_DIR_TX;
vfd->fops = &vivid_radio_fops;
vfd->ioctl_ops = &vivid_ioctl_ops;
vfd->release = video_device_release_empty;
vfd->v4l2_dev = &dev->v4l2_dev;
vfd->lock = &dev->mutex;
video_set_drvdata(vfd, dev);
ret = video_register_device(vfd, VFL_TYPE_RADIO, radio_tx_nr[inst]);
if (ret < 0)
goto unreg_dev;
v4l2_info(&dev->v4l2_dev, "V4L2 transmitter device registered as %s\n",
video_device_node_name(vfd));
}
vivid_devs[inst] = dev;
return 0;
unreg_dev:
video_unregister_device(&dev->radio_tx_dev);
video_unregister_device(&dev->radio_rx_dev);
video_unregister_device(&dev->sdr_cap_dev);
video_unregister_device(&dev->vbi_out_dev);
video_unregister_device(&dev->vbi_cap_dev);
video_unregister_device(&dev->vid_out_dev);
video_unregister_device(&dev->vid_cap_dev);
vivid_free_controls(dev);
v4l2_device_unregister(&dev->v4l2_dev);
free_dev:
vfree(dev->scaled_line);
vfree(dev->blended_line);
vfree(dev->edid);
tpg_free(&dev->tpg);
kfree(dev->query_dv_timings_qmenu);
kfree(dev);
return ret;
}
static int __init vivid_init(void)
{
const struct font_desc *font = find_font("VGA8x16");
int ret = 0, i;
if (font == NULL) {
pr_err("vivid: could not find font\n");
return -ENODEV;
}
tpg_set_font(font->data);
n_devs = clamp_t(unsigned, n_devs, 1, VIVID_MAX_DEVS);
for (i = 0; i < n_devs; i++) {
ret = vivid_create_instance(i);
if (ret) {
if (i)
ret = 0;
break;
}
}
if (ret < 0) {
pr_err("vivid: error %d while loading driver\n", ret);
return ret;
}
n_devs = i;
return ret;
}
static void __exit vivid_exit(void)
{
struct vivid_dev *dev;
unsigned i;
for (i = 0; vivid_devs[i]; i++) {
dev = vivid_devs[i];
if (dev->has_vid_cap) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vid_cap_dev));
video_unregister_device(&dev->vid_cap_dev);
}
if (dev->has_vid_out) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vid_out_dev));
video_unregister_device(&dev->vid_out_dev);
}
if (dev->has_vbi_cap) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vbi_cap_dev));
video_unregister_device(&dev->vbi_cap_dev);
}
if (dev->has_vbi_out) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->vbi_out_dev));
video_unregister_device(&dev->vbi_out_dev);
}
if (dev->has_sdr_cap) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->sdr_cap_dev));
video_unregister_device(&dev->sdr_cap_dev);
}
if (dev->has_radio_rx) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->radio_rx_dev));
video_unregister_device(&dev->radio_rx_dev);
}
if (dev->has_radio_tx) {
v4l2_info(&dev->v4l2_dev, "unregistering %s\n",
video_device_node_name(&dev->radio_tx_dev));
video_unregister_device(&dev->radio_tx_dev);
}
if (dev->has_fb) {
v4l2_info(&dev->v4l2_dev, "unregistering fb%d\n",
dev->fb_info.node);
unregister_framebuffer(&dev->fb_info);
vivid_fb_release_buffers(dev);
}
v4l2_device_unregister(&dev->v4l2_dev);
vivid_free_controls(dev);
vfree(dev->scaled_line);
vfree(dev->blended_line);
vfree(dev->edid);
vfree(dev->bitmap_cap);
vfree(dev->bitmap_out);
tpg_free(&dev->tpg);
kfree(dev->query_dv_timings_qmenu);
kfree(dev);
vivid_devs[i] = NULL;
}
}
