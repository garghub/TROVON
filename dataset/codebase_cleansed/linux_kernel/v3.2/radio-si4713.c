static int radio_si4713_fill_audout(struct v4l2_audioout *vao)
{
strlcpy(vao->name, "FM Modulator Audio Out", 32);
return 0;
}
static int radio_si4713_enumaudout(struct file *file, void *priv,
struct v4l2_audioout *vao)
{
return radio_si4713_fill_audout(vao);
}
static int radio_si4713_g_audout(struct file *file, void *priv,
struct v4l2_audioout *vao)
{
int rval = radio_si4713_fill_audout(vao);
vao->index = 0;
return rval;
}
static int radio_si4713_s_audout(struct file *file, void *priv,
struct v4l2_audioout *vao)
{
return vao->index ? -EINVAL : 0;
}
static int radio_si4713_querycap(struct file *file, void *priv,
struct v4l2_capability *capability)
{
strlcpy(capability->driver, "radio-si4713", sizeof(capability->driver));
strlcpy(capability->card, "Silicon Labs Si4713 Modulator",
sizeof(capability->card));
capability->capabilities = V4L2_CAP_MODULATOR | V4L2_CAP_RDS_OUTPUT;
return 0;
}
static int radio_si4713_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
static const u32 user_ctrls[] = {
V4L2_CID_USER_CLASS,
V4L2_CID_AUDIO_MUTE,
0
};
static const u32 fmtx_ctrls[] = {
V4L2_CID_FM_TX_CLASS,
V4L2_CID_RDS_TX_DEVIATION,
V4L2_CID_RDS_TX_PI,
V4L2_CID_RDS_TX_PTY,
V4L2_CID_RDS_TX_PS_NAME,
V4L2_CID_RDS_TX_RADIO_TEXT,
V4L2_CID_AUDIO_LIMITER_ENABLED,
V4L2_CID_AUDIO_LIMITER_RELEASE_TIME,
V4L2_CID_AUDIO_LIMITER_DEVIATION,
V4L2_CID_AUDIO_COMPRESSION_ENABLED,
V4L2_CID_AUDIO_COMPRESSION_GAIN,
V4L2_CID_AUDIO_COMPRESSION_THRESHOLD,
V4L2_CID_AUDIO_COMPRESSION_ATTACK_TIME,
V4L2_CID_AUDIO_COMPRESSION_RELEASE_TIME,
V4L2_CID_PILOT_TONE_ENABLED,
V4L2_CID_PILOT_TONE_DEVIATION,
V4L2_CID_PILOT_TONE_FREQUENCY,
V4L2_CID_TUNE_PREEMPHASIS,
V4L2_CID_TUNE_POWER_LEVEL,
V4L2_CID_TUNE_ANTENNA_CAPACITOR,
0
};
static const u32 *ctrl_classes[] = {
user_ctrls,
fmtx_ctrls,
NULL
};
struct radio_si4713_device *rsdev;
rsdev = video_get_drvdata(video_devdata(file));
qc->id = v4l2_ctrl_next(ctrl_classes, qc->id);
if (qc->id == 0)
return -EINVAL;
if (qc->id == V4L2_CID_USER_CLASS || qc->id == V4L2_CID_FM_TX_CLASS)
return v4l2_ctrl_query_fill(qc, 0, 0, 0, 0);
return v4l2_device_call_until_err(&rsdev->v4l2_dev, 0, core,
queryctrl, qc);
}
static inline struct v4l2_device *get_v4l2_dev(struct file *file)
{
return &((struct radio_si4713_device *)video_drvdata(file))->v4l2_dev;
}
static int radio_si4713_g_ext_ctrls(struct file *file, void *p,
struct v4l2_ext_controls *vecs)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
g_ext_ctrls, vecs);
}
static int radio_si4713_s_ext_ctrls(struct file *file, void *p,
struct v4l2_ext_controls *vecs)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
s_ext_ctrls, vecs);
}
static int radio_si4713_g_ctrl(struct file *file, void *p,
struct v4l2_control *vc)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
g_ctrl, vc);
}
static int radio_si4713_s_ctrl(struct file *file, void *p,
struct v4l2_control *vc)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
s_ctrl, vc);
}
static int radio_si4713_g_modulator(struct file *file, void *p,
struct v4l2_modulator *vm)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
g_modulator, vm);
}
static int radio_si4713_s_modulator(struct file *file, void *p,
struct v4l2_modulator *vm)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
s_modulator, vm);
}
static int radio_si4713_g_frequency(struct file *file, void *p,
struct v4l2_frequency *vf)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
g_frequency, vf);
}
static int radio_si4713_s_frequency(struct file *file, void *p,
struct v4l2_frequency *vf)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
s_frequency, vf);
}
static long radio_si4713_default(struct file *file, void *p,
bool valid_prio, int cmd, void *arg)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, core,
ioctl, cmd, arg);
}
static int radio_si4713_pdriver_probe(struct platform_device *pdev)
{
struct radio_si4713_platform_data *pdata = pdev->dev.platform_data;
struct radio_si4713_device *rsdev;
struct i2c_adapter *adapter;
struct v4l2_subdev *sd;
int rval = 0;
if (!pdata) {
dev_err(&pdev->dev, "Cannot proceed without platform data.\n");
rval = -EINVAL;
goto exit;
}
rsdev = kzalloc(sizeof *rsdev, GFP_KERNEL);
if (!rsdev) {
dev_err(&pdev->dev, "Failed to alloc video device.\n");
rval = -ENOMEM;
goto exit;
}
rval = v4l2_device_register(&pdev->dev, &rsdev->v4l2_dev);
if (rval) {
dev_err(&pdev->dev, "Failed to register v4l2 device.\n");
goto free_rsdev;
}
adapter = i2c_get_adapter(pdata->i2c_bus);
if (!adapter) {
dev_err(&pdev->dev, "Cannot get i2c adapter %d\n",
pdata->i2c_bus);
rval = -ENODEV;
goto unregister_v4l2_dev;
}
sd = v4l2_i2c_new_subdev_board(&rsdev->v4l2_dev, adapter,
pdata->subdev_board_info, NULL);
if (!sd) {
dev_err(&pdev->dev, "Cannot get v4l2 subdevice\n");
rval = -ENODEV;
goto put_adapter;
}
rsdev->radio_dev = video_device_alloc();
if (!rsdev->radio_dev) {
dev_err(&pdev->dev, "Failed to alloc video device.\n");
rval = -ENOMEM;
goto put_adapter;
}
memcpy(rsdev->radio_dev, &radio_si4713_vdev_template,
sizeof(radio_si4713_vdev_template));
video_set_drvdata(rsdev->radio_dev, rsdev);
if (video_register_device(rsdev->radio_dev, VFL_TYPE_RADIO, radio_nr)) {
dev_err(&pdev->dev, "Could not register video device.\n");
rval = -EIO;
goto free_vdev;
}
dev_info(&pdev->dev, "New device successfully probed\n");
goto exit;
free_vdev:
video_device_release(rsdev->radio_dev);
put_adapter:
i2c_put_adapter(adapter);
unregister_v4l2_dev:
v4l2_device_unregister(&rsdev->v4l2_dev);
free_rsdev:
kfree(rsdev);
exit:
return rval;
}
static int __exit radio_si4713_pdriver_remove(struct platform_device *pdev)
{
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct radio_si4713_device *rsdev = container_of(v4l2_dev,
struct radio_si4713_device,
v4l2_dev);
struct v4l2_subdev *sd = list_entry(v4l2_dev->subdevs.next,
struct v4l2_subdev, list);
struct i2c_client *client = v4l2_get_subdevdata(sd);
video_unregister_device(rsdev->radio_dev);
i2c_put_adapter(client->adapter);
v4l2_device_unregister(&rsdev->v4l2_dev);
kfree(rsdev);
return 0;
}
static int __init radio_si4713_module_init(void)
{
return platform_driver_register(&radio_si4713_pdriver);
}
static void __exit radio_si4713_module_exit(void)
{
platform_driver_unregister(&radio_si4713_pdriver);
}
