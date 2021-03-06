static int radio_isa_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct radio_isa_card *isa = video_drvdata(file);
strlcpy(v->driver, isa->drv->driver.driver.name, sizeof(v->driver));
strlcpy(v->card, isa->drv->card, sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info), "ISA:%s", isa->v4l2_dev.name);
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
v->device_caps = v->capabilities | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int radio_isa_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct radio_isa_card *isa = video_drvdata(file);
const struct radio_isa_ops *ops = isa->drv->ops;
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->rangelow = FREQ_LOW;
v->rangehigh = FREQ_HIGH;
v->capability = V4L2_TUNER_CAP_LOW;
if (isa->drv->has_stereo)
v->capability |= V4L2_TUNER_CAP_STEREO;
if (ops->g_rxsubchans)
v->rxsubchans = ops->g_rxsubchans(isa);
else
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->audmode = isa->stereo ? V4L2_TUNER_MODE_STEREO : V4L2_TUNER_MODE_MONO;
if (ops->g_signal)
v->signal = ops->g_signal(isa);
else
v->signal = (v->rxsubchans & V4L2_TUNER_SUB_STEREO) ?
0xffff : 0;
return 0;
}
static int radio_isa_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct radio_isa_card *isa = video_drvdata(file);
const struct radio_isa_ops *ops = isa->drv->ops;
if (v->index)
return -EINVAL;
if (ops->s_stereo) {
isa->stereo = (v->audmode == V4L2_TUNER_MODE_STEREO);
return ops->s_stereo(isa, isa->stereo);
}
return 0;
}
static int radio_isa_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct radio_isa_card *isa = video_drvdata(file);
int res;
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
f->frequency = clamp(f->frequency, FREQ_LOW, FREQ_HIGH);
res = isa->drv->ops->s_frequency(isa, f->frequency);
if (res == 0)
isa->freq = f->frequency;
return res;
}
static int radio_isa_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct radio_isa_card *isa = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = isa->freq;
return 0;
}
static int radio_isa_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct radio_isa_card *isa =
container_of(ctrl->handler, struct radio_isa_card, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
return isa->drv->ops->s_mute_volume(isa, ctrl->val,
isa->volume ? isa->volume->val : 0);
}
return -EINVAL;
}
static int radio_isa_log_status(struct file *file, void *priv)
{
struct radio_isa_card *isa = video_drvdata(file);
v4l2_info(&isa->v4l2_dev, "I/O Port = 0x%03x\n", isa->io);
v4l2_ctrl_handler_log_status(&isa->hdl, isa->v4l2_dev.name);
return 0;
}
int radio_isa_match(struct device *pdev, unsigned int dev)
{
struct radio_isa_driver *drv = pdev->platform_data;
return drv->probe || drv->io_params[dev] >= 0;
}
static bool radio_isa_valid_io(const struct radio_isa_driver *drv, int io)
{
int i;
for (i = 0; i < drv->num_of_io_ports; i++)
if (drv->io_ports[i] == io)
return true;
return false;
}
struct radio_isa_card *radio_isa_alloc(struct radio_isa_driver *drv,
struct device *pdev)
{
struct v4l2_device *v4l2_dev;
struct radio_isa_card *isa = drv->ops->alloc();
if (!isa)
return NULL;
dev_set_drvdata(pdev, isa);
isa->drv = drv;
v4l2_dev = &isa->v4l2_dev;
strlcpy(v4l2_dev->name, dev_name(pdev), sizeof(v4l2_dev->name));
return isa;
}
int radio_isa_common_probe(struct radio_isa_card *isa, struct device *pdev,
int radio_nr, unsigned region_size)
{
const struct radio_isa_driver *drv = isa->drv;
const struct radio_isa_ops *ops = drv->ops;
struct v4l2_device *v4l2_dev = &isa->v4l2_dev;
int res;
if (!request_region(isa->io, region_size, v4l2_dev->name)) {
v4l2_err(v4l2_dev, "port 0x%x already in use\n", isa->io);
kfree(isa);
return -EBUSY;
}
res = v4l2_device_register(pdev, v4l2_dev);
if (res < 0) {
v4l2_err(v4l2_dev, "Could not register v4l2_device\n");
goto err_dev_reg;
}
v4l2_ctrl_handler_init(&isa->hdl, 1);
isa->mute = v4l2_ctrl_new_std(&isa->hdl, &radio_isa_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
if (drv->max_volume)
isa->volume = v4l2_ctrl_new_std(&isa->hdl, &radio_isa_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, drv->max_volume, 1,
drv->max_volume);
v4l2_dev->ctrl_handler = &isa->hdl;
if (isa->hdl.error) {
res = isa->hdl.error;
v4l2_err(v4l2_dev, "Could not register controls\n");
goto err_hdl;
}
if (drv->max_volume)
v4l2_ctrl_cluster(2, &isa->mute);
v4l2_dev->ctrl_handler = &isa->hdl;
mutex_init(&isa->lock);
isa->vdev.lock = &isa->lock;
strlcpy(isa->vdev.name, v4l2_dev->name, sizeof(isa->vdev.name));
isa->vdev.v4l2_dev = v4l2_dev;
isa->vdev.fops = &radio_isa_fops;
isa->vdev.ioctl_ops = &radio_isa_ioctl_ops;
isa->vdev.release = video_device_release_empty;
set_bit(V4L2_FL_USE_FH_PRIO, &isa->vdev.flags);
video_set_drvdata(&isa->vdev, isa);
isa->freq = FREQ_LOW;
isa->stereo = drv->has_stereo;
if (ops->init)
res = ops->init(isa);
if (!res)
res = v4l2_ctrl_handler_setup(&isa->hdl);
if (!res)
res = ops->s_frequency(isa, isa->freq);
if (!res && ops->s_stereo)
res = ops->s_stereo(isa, isa->stereo);
if (res < 0) {
v4l2_err(v4l2_dev, "Could not setup card\n");
goto err_hdl;
}
res = video_register_device(&isa->vdev, VFL_TYPE_RADIO, radio_nr);
if (res < 0) {
v4l2_err(v4l2_dev, "Could not register device node\n");
goto err_hdl;
}
v4l2_info(v4l2_dev, "Initialized radio card %s on port 0x%03x\n",
drv->card, isa->io);
return 0;
err_hdl:
v4l2_ctrl_handler_free(&isa->hdl);
err_dev_reg:
release_region(isa->io, region_size);
kfree(isa);
return res;
}
int radio_isa_common_remove(struct radio_isa_card *isa, unsigned region_size)
{
const struct radio_isa_ops *ops = isa->drv->ops;
ops->s_mute_volume(isa, true, isa->volume ? isa->volume->cur.val : 0);
video_unregister_device(&isa->vdev);
v4l2_ctrl_handler_free(&isa->hdl);
v4l2_device_unregister(&isa->v4l2_dev);
release_region(isa->io, region_size);
v4l2_info(&isa->v4l2_dev, "Removed radio card %s\n", isa->drv->card);
kfree(isa);
return 0;
}
int radio_isa_probe(struct device *pdev, unsigned int dev)
{
struct radio_isa_driver *drv = pdev->platform_data;
const struct radio_isa_ops *ops = drv->ops;
struct v4l2_device *v4l2_dev;
struct radio_isa_card *isa;
isa = radio_isa_alloc(drv, pdev);
if (!isa)
return -ENOMEM;
isa->io = drv->io_params[dev];
v4l2_dev = &isa->v4l2_dev;
if (drv->probe && ops->probe) {
int i;
for (i = 0; i < drv->num_of_io_ports; ++i) {
int io = drv->io_ports[i];
if (request_region(io, drv->region_size, v4l2_dev->name)) {
bool found = ops->probe(isa, io);
release_region(io, drv->region_size);
if (found) {
isa->io = io;
break;
}
}
}
}
if (!radio_isa_valid_io(drv, isa->io)) {
int i;
if (isa->io < 0)
return -ENODEV;
v4l2_err(v4l2_dev, "you must set an I/O address with io=0x%03x",
drv->io_ports[0]);
for (i = 1; i < drv->num_of_io_ports; i++)
printk(KERN_CONT "/0x%03x", drv->io_ports[i]);
printk(KERN_CONT ".\n");
kfree(isa);
return -EINVAL;
}
return radio_isa_common_probe(isa, pdev, drv->radio_nr_params[dev],
drv->region_size);
}
int radio_isa_remove(struct device *pdev, unsigned int dev)
{
struct radio_isa_card *isa = dev_get_drvdata(pdev);
return radio_isa_common_remove(isa, isa->drv->region_size);
}
int radio_isa_pnp_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
struct pnp_driver *pnp_drv = to_pnp_driver(dev->dev.driver);
struct radio_isa_driver *drv = container_of(pnp_drv,
struct radio_isa_driver, pnp_driver);
struct radio_isa_card *isa;
if (!pnp_port_valid(dev, 0))
return -ENODEV;
isa = radio_isa_alloc(drv, &dev->dev);
if (!isa)
return -ENOMEM;
isa->io = pnp_port_start(dev, 0);
return radio_isa_common_probe(isa, &dev->dev, drv->radio_nr_params[0],
pnp_port_len(dev, 0));
}
void radio_isa_pnp_remove(struct pnp_dev *dev)
{
struct radio_isa_card *isa = dev_get_drvdata(&dev->dev);
radio_isa_common_remove(isa, pnp_port_len(dev, 0));
}
