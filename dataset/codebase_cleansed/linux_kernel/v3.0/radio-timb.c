static int timbradio_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
strlcpy(v->driver, DRIVER_NAME, sizeof(v->driver));
strlcpy(v->card, "Timberdale Radio", sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info), "platform:"DRIVER_NAME);
v->version = KERNEL_VERSION(0, 0, 1);
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int timbradio_vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_tuner, tuner, g_tuner, v);
}
static int timbradio_vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_tuner, tuner, s_tuner, v);
}
static int timbradio_vidioc_g_input(struct file *filp, void *priv,
unsigned int *i)
{
*i = 0;
return 0;
}
static int timbradio_vidioc_s_input(struct file *filp, void *priv,
unsigned int i)
{
return i ? -EINVAL : 0;
}
static int timbradio_vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
a->index = 0;
strlcpy(a->name, "Radio", sizeof(a->name));
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int timbradio_vidioc_s_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
return a->index ? -EINVAL : 0;
}
static int timbradio_vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_tuner, tuner, s_frequency, f);
}
static int timbradio_vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_tuner, tuner, g_frequency, f);
}
static int timbradio_vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_dsp, core, queryctrl, qc);
}
static int timbradio_vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_dsp, core, g_ctrl, ctrl);
}
static int timbradio_vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct timbradio *tr = video_drvdata(file);
return v4l2_subdev_call(tr->sd_dsp, core, s_ctrl, ctrl);
}
static int __devinit timbradio_probe(struct platform_device *pdev)
{
struct timb_radio_platform_data *pdata = pdev->dev.platform_data;
struct timbradio *tr;
int err;
if (!pdata) {
dev_err(&pdev->dev, "Platform data missing\n");
err = -EINVAL;
goto err;
}
tr = kzalloc(sizeof(*tr), GFP_KERNEL);
if (!tr) {
err = -ENOMEM;
goto err;
}
tr->pdata = *pdata;
mutex_init(&tr->lock);
strlcpy(tr->video_dev.name, "Timberdale Radio",
sizeof(tr->video_dev.name));
tr->video_dev.fops = &timbradio_fops;
tr->video_dev.ioctl_ops = &timbradio_ioctl_ops;
tr->video_dev.release = video_device_release_empty;
tr->video_dev.minor = -1;
tr->video_dev.lock = &tr->lock;
strlcpy(tr->v4l2_dev.name, DRIVER_NAME, sizeof(tr->v4l2_dev.name));
err = v4l2_device_register(NULL, &tr->v4l2_dev);
if (err)
goto err_v4l2_dev;
tr->video_dev.v4l2_dev = &tr->v4l2_dev;
err = video_register_device(&tr->video_dev, VFL_TYPE_RADIO, -1);
if (err) {
dev_err(&pdev->dev, "Error reg video\n");
goto err_video_req;
}
video_set_drvdata(&tr->video_dev, tr);
platform_set_drvdata(pdev, tr);
return 0;
err_video_req:
video_device_release_empty(&tr->video_dev);
v4l2_device_unregister(&tr->v4l2_dev);
err_v4l2_dev:
kfree(tr);
err:
dev_err(&pdev->dev, "Failed to register: %d\n", err);
return err;
}
static int __devexit timbradio_remove(struct platform_device *pdev)
{
struct timbradio *tr = platform_get_drvdata(pdev);
video_unregister_device(&tr->video_dev);
video_device_release_empty(&tr->video_dev);
v4l2_device_unregister(&tr->v4l2_dev);
kfree(tr);
return 0;
}
static int __init timbradio_init(void)
{
return platform_driver_register(&timbradio_platform_driver);
}
static void __exit timbradio_exit(void)
{
platform_driver_unregister(&timbradio_platform_driver);
}
