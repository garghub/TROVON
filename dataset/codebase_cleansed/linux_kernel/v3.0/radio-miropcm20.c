static int pcm20_mute(struct pcm20 *dev, unsigned char mute)
{
dev->muted = mute;
return snd_aci_cmd(dev->aci, ACI_SET_TUNERMUTE, mute, -1);
}
static int pcm20_stereo(struct pcm20 *dev, unsigned char stereo)
{
return snd_aci_cmd(dev->aci, ACI_SET_TUNERMONO, !stereo, -1);
}
static int pcm20_setfreq(struct pcm20 *dev, unsigned long freq)
{
unsigned char freql;
unsigned char freqh;
struct snd_miro_aci *aci = dev->aci;
dev->freq = freq;
freq /= 160;
if (!(aci->aci_version == 0x07 || aci->aci_version >= 0xb0))
freq /= 10;
freql = freq & 0xff;
freqh = freq >> 8;
pcm20_stereo(dev, !mono);
return snd_aci_cmd(aci, ACI_WRITE_TUNE, freql, freqh);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, "Miro PCM20", sizeof(v->driver));
strlcpy(v->card, "Miro PCM20", sizeof(v->card));
strlcpy(v->bus_info, "ISA", sizeof(v->bus_info));
v->version = 0x1;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
if (v->index)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = 87*16000;
v->rangehigh = 108*16000;
v->signal = 0xffff;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->capability = V4L2_TUNER_CAP_LOW;
v->audmode = V4L2_TUNER_MODE_MONO;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
return v->index ? -EINVAL : 0;
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
dev->freq = f->frequency;
pcm20_setfreq(dev, f->frequency);
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_AUDIO_MUTE:
return v4l2_ctrl_query_fill(qc, 0, 1, 1, 1);
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct pcm20 *dev = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
ctrl->value = dev->muted;
break;
default:
return -EINVAL;
}
return 0;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct pcm20 *dev = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
pcm20_mute(dev, ctrl->value);
break;
default:
return -EINVAL;
}
return 0;
}
static int vidioc_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *filp, void *priv, unsigned int i)
{
return i ? -EINVAL : 0;
}
static int vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
a->index = 0;
strlcpy(a->name, "Radio", sizeof(a->name));
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
return a->index ? -EINVAL : 0;
}
static int __init pcm20_init(void)
{
struct pcm20 *dev = &pcm20_card;
struct v4l2_device *v4l2_dev = &dev->v4l2_dev;
int res;
dev->aci = snd_aci_get_aci();
if (dev->aci == NULL) {
v4l2_err(v4l2_dev,
"you must load the snd-miro driver first!\n");
return -ENODEV;
}
strlcpy(v4l2_dev->name, "miropcm20", sizeof(v4l2_dev->name));
mutex_init(&dev->lock);
res = v4l2_device_register(NULL, v4l2_dev);
if (res < 0) {
v4l2_err(v4l2_dev, "could not register v4l2_device\n");
return -EINVAL;
}
strlcpy(dev->vdev.name, v4l2_dev->name, sizeof(dev->vdev.name));
dev->vdev.v4l2_dev = v4l2_dev;
dev->vdev.fops = &pcm20_fops;
dev->vdev.ioctl_ops = &pcm20_ioctl_ops;
dev->vdev.release = video_device_release_empty;
dev->vdev.lock = &dev->lock;
video_set_drvdata(&dev->vdev, dev);
if (video_register_device(&dev->vdev, VFL_TYPE_RADIO, radio_nr) < 0)
goto fail;
v4l2_info(v4l2_dev, "Mirosound PCM20 Radio tuner\n");
return 0;
fail:
v4l2_device_unregister(v4l2_dev);
return -EINVAL;
}
static void __exit pcm20_cleanup(void)
{
struct pcm20 *dev = &pcm20_card;
video_unregister_device(&dev->vdev);
v4l2_device_unregister(&dev->v4l2_dev);
}
