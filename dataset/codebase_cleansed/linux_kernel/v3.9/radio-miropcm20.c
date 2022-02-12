static int pcm20_setfreq(struct pcm20 *dev, unsigned long freq)
{
unsigned char freql;
unsigned char freqh;
struct snd_miro_aci *aci = dev->aci;
freq /= 160;
if (!(aci->aci_version == 0x07 || aci->aci_version >= 0xb0))
freq /= 10;
freql = freq & 0xff;
freqh = freq >> 8;
return snd_aci_cmd(aci, ACI_WRITE_TUNE, freql, freqh);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct pcm20 *dev = video_drvdata(file);
strlcpy(v->driver, "Miro PCM20", sizeof(v->driver));
strlcpy(v->card, "Miro PCM20", sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info), "ISA:%s", dev->v4l2_dev.name);
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct pcm20 *dev = video_drvdata(file);
int res;
if (v->index)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 87*16000;
v->rangehigh = 108*16000;
res = snd_aci_cmd(dev->aci, ACI_READ_TUNERSTATION, -1, -1);
v->signal = (res & 0x80) ? 0 : 0xffff;
res = snd_aci_cmd(dev->aci, ACI_READ_TUNERSTEREO, -1, -1);
v->rxsubchans = (res & 0x40) ? V4L2_TUNER_SUB_MONO :
V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->audmode = dev->audmode;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct pcm20 *dev = video_drvdata(file);
if (v->index)
return -EINVAL;
if (v->audmode > V4L2_TUNER_MODE_STEREO)
v->audmode = V4L2_TUNER_MODE_STEREO;
snd_aci_cmd(dev->aci, ACI_SET_TUNERMONO,
v->audmode == V4L2_TUNER_MODE_MONO, -1);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct pcm20 *dev = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = dev->freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct pcm20 *dev = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
dev->freq = clamp(f->frequency, 87 * 16000U, 108 * 16000U);
pcm20_setfreq(dev, dev->freq);
return 0;
}
static int pcm20_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct pcm20 *dev = container_of(ctrl->handler, struct pcm20, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
snd_aci_cmd(dev->aci, ACI_SET_TUNERMUTE, ctrl->val, -1);
return 0;
}
return -EINVAL;
}
static int __init pcm20_init(void)
{
struct pcm20 *dev = &pcm20_card;
struct v4l2_device *v4l2_dev = &dev->v4l2_dev;
struct v4l2_ctrl_handler *hdl;
int res;
dev->aci = snd_aci_get_aci();
if (dev->aci == NULL) {
v4l2_err(v4l2_dev,
"you must load the snd-miro driver first!\n");
return -ENODEV;
}
strlcpy(v4l2_dev->name, "radio-miropcm20", sizeof(v4l2_dev->name));
mutex_init(&dev->lock);
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
v4l2_err(v4l2_dev, "could not register v4l2_device\n");
return -EINVAL;
}
hdl = &dev->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 1);
v4l2_ctrl_new_std(hdl, &pcm20_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
v4l2_dev->ctrl_handler = hdl;
if (hdl->error) {
res = hdl->error;
v4l2_err(v4l2_dev, "Could not register control\n");
goto err_hdl;
}
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &pcm20_fops;
dev->vdev.ioctl_ops = &pcm20_ioctl_ops;
dev->vdev.release = video_device_release_empty;
dev->vdev.lock = &dev->lock;
set_bit(V4L2_FL_USE_FH_PRIO, &dev->vdev.flags);
video_set_drvdata(&dev->vdev, dev);
snd_aci_cmd(dev->aci, ACI_SET_TUNERMONO,
dev->audmode == V4L2_TUNER_MODE_MONO, -1);
pcm20_setfreq(dev, dev->freq);
if (video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr) < 0)
goto err_hdl;
v4l2_info(v4l2_dev, "Mirosound PCM20 Radio tuner\n");
return 0;
err_hdl:
v4l2_ctrl_handler_free(hdl);
v4l2_device_unregister(v4l2_dev);
return -EINVAL;
}
static void __exit pcm20_cleanup(void)
{
struct pcm20 *dev = &pcm20_card;
video_unregister_device(&dev->vdev);
snd_aci_cmd(dev->aci, ACI_SET_TUNERMUTE, 1, -1);
v4l2_ctrl_handler_free(&dev->ctrl_handler);
v4l2_device_unregister(&dev->v4l2_dev);
}
