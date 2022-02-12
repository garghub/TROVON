static int radio_si4713_querycap(struct file *file, void *priv,
struct v4l2_capability *capability)
{
strlcpy(capability->driver, "radio-si4713", sizeof(capability->driver));
strlcpy(capability->card, "Silicon Labs Si4713 Modulator",
sizeof(capability->card));
strlcpy(capability->bus_info, "platform:radio-si4713",
sizeof(capability->bus_info));
capability->device_caps = V4L2_CAP_MODULATOR | V4L2_CAP_RDS_OUTPUT;
capability->capabilities = capability->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static inline struct v4l2_device *get_v4l2_dev(struct file *file)
{
return &((struct radio_si4713_device *)video_drvdata(file))->v4l2_dev;
}
static int radio_si4713_g_modulator(struct file *file, void *p,
struct v4l2_modulator *vm)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
g_modulator, vm);
}
static int radio_si4713_s_modulator(struct file *file, void *p,
const struct v4l2_modulator *vm)
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
const struct v4l2_frequency *vf)
{
return v4l2_device_call_until_err(get_v4l2_dev(file), 0, tuner,
s_frequency, vf);
}
static long radio_si4713_default(struct file *file, void *p,
bool valid_prio, unsigned int cmd, void *arg)
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
rsdev = devm_kzalloc(&pdev->dev, sizeof(*rsdev), GFP_KERNEL);
if (!rsdev) {
dev_err(&pdev->dev, "Failed to alloc video device.\n");
rval = -ENOMEM;
goto exit;
}
mutex_init(&rsdev->lock);
rval = v4l2_device_register(&pdev->dev, &rsdev->v4l2_dev);
if (rval) {
dev_err(&pdev->dev, "Failed to register v4l2 device.\n");
goto exit;
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
rsdev->radio_dev = radio_si4713_vdev_template;
rsdev->radio_dev.v4l2_dev = &rsdev->v4l2_dev;
rsdev->radio_dev.ctrl_handler = sd->ctrl_handler;
rsdev->radio_dev.lock = &rsdev->lock;
video_set_drvdata(&rsdev->radio_dev, rsdev);
if (video_register_device(&rsdev->radio_dev, VFL_TYPE_RADIO, radio_nr)) {
dev_err(&pdev->dev, "Could not register video device.\n");
rval = -EIO;
goto put_adapter;
}
dev_info(&pdev->dev, "New device successfully probed\n");
goto exit;
put_adapter:
i2c_put_adapter(adapter);
unregister_v4l2_dev:
v4l2_device_unregister(&rsdev->v4l2_dev);
exit:
return rval;
}
static int radio_si4713_pdriver_remove(struct platform_device *pdev)
{
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct v4l2_subdev *sd = list_entry(v4l2_dev->subdevs.next,
struct v4l2_subdev, list);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct radio_si4713_device *rsdev;
rsdev = container_of(v4l2_dev, struct radio_si4713_device, v4l2_dev);
video_unregister_device(&rsdev->radio_dev);
i2c_put_adapter(client->adapter);
v4l2_device_unregister(&rsdev->v4l2_dev);
return 0;
}
