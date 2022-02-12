static int tea5764_i2c_read(struct tea5764_device *radio)
{
int i;
u16 *p = (u16 *) &radio->regs;
struct i2c_msg msgs[1] = {
{ .addr = radio->i2c_client->addr,
.flags = I2C_M_RD,
.len = sizeof(radio->regs),
.buf = (void *)&radio->regs
},
};
if (i2c_transfer(radio->i2c_client->adapter, msgs, 1) != 1)
return -EIO;
for (i = 0; i < sizeof(struct tea5764_regs) / sizeof(u16); i++)
p[i] = __be16_to_cpu(p[i]);
return 0;
}
static int tea5764_i2c_write(struct tea5764_device *radio)
{
struct tea5764_write_regs wr;
struct tea5764_regs *r = &radio->regs;
struct i2c_msg msgs[1] = {
{
.addr = radio->i2c_client->addr,
.len = sizeof(wr),
.buf = (void *)&wr
},
};
wr.intreg = r->intreg & 0xff;
wr.frqset = __cpu_to_be16(r->frqset);
wr.tnctrl = __cpu_to_be16(r->tnctrl);
wr.testreg = __cpu_to_be16(r->testreg);
wr.rdsctrl = __cpu_to_be16(r->rdsctrl);
wr.rdsbbl = __cpu_to_be16(r->rdsbbl);
if (i2c_transfer(radio->i2c_client->adapter, msgs, 1) != 1)
return -EIO;
return 0;
}
static void tea5764_power_up(struct tea5764_device *radio)
{
struct tea5764_regs *r = &radio->regs;
if (!(r->tnctrl & TEA5764_TNCTRL_PUPD0)) {
r->tnctrl &= ~(TEA5764_TNCTRL_AFM | TEA5764_TNCTRL_MU |
TEA5764_TNCTRL_HLSI);
if (!use_xtal)
r->testreg |= TEA5764_TESTREG_TRIGFR;
else
r->testreg &= ~TEA5764_TESTREG_TRIGFR;
r->tnctrl |= TEA5764_TNCTRL_PUPD0;
tea5764_i2c_write(radio);
}
}
static void tea5764_power_down(struct tea5764_device *radio)
{
struct tea5764_regs *r = &radio->regs;
if (r->tnctrl & TEA5764_TNCTRL_PUPD0) {
r->tnctrl &= ~TEA5764_TNCTRL_PUPD0;
tea5764_i2c_write(radio);
}
}
static void tea5764_set_freq(struct tea5764_device *radio, int freq)
{
struct tea5764_regs *r = &radio->regs;
if (r->tnctrl & TEA5764_TNCTRL_HLSI)
r->frqset = (freq + 225000) / 8192;
else
r->frqset = (freq - 225000) / 8192;
}
static int tea5764_get_freq(struct tea5764_device *radio)
{
struct tea5764_regs *r = &radio->regs;
if (r->tnctrl & TEA5764_TNCTRL_HLSI)
return (r->frqchk * 8192) - 225000;
else
return (r->frqchk * 8192) + 225000;
}
static void tea5764_tune(struct tea5764_device *radio, int freq)
{
tea5764_set_freq(radio, freq);
if (tea5764_i2c_write(radio))
PWARN("Could not set frequency!");
}
static void tea5764_set_audout_mode(struct tea5764_device *radio, int audmode)
{
struct tea5764_regs *r = &radio->regs;
int tnctrl = r->tnctrl;
if (audmode == V4L2_TUNER_MODE_MONO)
r->tnctrl |= TEA5764_TNCTRL_MST;
else
r->tnctrl &= ~TEA5764_TNCTRL_MST;
if (tnctrl != r->tnctrl)
tea5764_i2c_write(radio);
}
static int tea5764_get_audout_mode(struct tea5764_device *radio)
{
struct tea5764_regs *r = &radio->regs;
if (r->tnctrl & TEA5764_TNCTRL_MST)
return V4L2_TUNER_MODE_MONO;
else
return V4L2_TUNER_MODE_STEREO;
}
static void tea5764_mute(struct tea5764_device *radio, int on)
{
struct tea5764_regs *r = &radio->regs;
int tnctrl = r->tnctrl;
if (on)
r->tnctrl |= TEA5764_TNCTRL_MU;
else
r->tnctrl &= ~TEA5764_TNCTRL_MU;
if (tnctrl != r->tnctrl)
tea5764_i2c_write(radio);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct tea5764_device *radio = video_drvdata(file);
struct video_device *dev = &radio->vdev;
strlcpy(v->driver, dev->dev.driver->name, sizeof(v->driver));
strlcpy(v->card, dev->name, sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info),
"I2C:%s", dev_name(&dev->dev));
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct tea5764_device *radio = video_drvdata(file);
struct tea5764_regs *r = &radio->regs;
if (v->index > 0)
return -EINVAL;
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
tea5764_i2c_read(radio);
v->rangelow = FREQ_MIN * FREQ_MUL;
v->rangehigh = FREQ_MAX * FREQ_MUL;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
if (r->tunchk & TEA5764_TUNCHK_STEREO)
v->rxsubchans = V4L2_TUNER_SUB_STEREO;
else
v->rxsubchans = V4L2_TUNER_SUB_MONO;
v->audmode = tea5764_get_audout_mode(radio);
v->signal = TEA5764_TUNCHK_LEVEL(r->tunchk) * 0xffff / 0xf;
v->afc = TEA5764_TUNCHK_IFCNT(r->tunchk);
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
const struct v4l2_tuner *v)
{
struct tea5764_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
tea5764_set_audout_mode(radio, v->audmode);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
const struct v4l2_frequency *f)
{
struct tea5764_device *radio = video_drvdata(file);
unsigned freq = f->frequency;
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (freq == 0) {
tea5764_power_down(radio);
return -EINVAL;
}
clamp(freq, FREQ_MIN * FREQ_MUL, FREQ_MAX * FREQ_MUL);
tea5764_power_up(radio);
tea5764_tune(radio, (freq * 125) / 2);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct tea5764_device *radio = video_drvdata(file);
struct tea5764_regs *r = &radio->regs;
if (f->tuner != 0)
return -EINVAL;
tea5764_i2c_read(radio);
f->type = V4L2_TUNER_RADIO;
if (r->tnctrl & TEA5764_TNCTRL_PUPD0)
f->frequency = (tea5764_get_freq(radio) * 2) / 125;
else
f->frequency = 0;
return 0;
}
static int tea5764_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct tea5764_device *radio =
container_of(ctrl->handler, struct tea5764_device, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
tea5764_mute(radio, ctrl->val);
return 0;
}
return -EINVAL;
}
static int tea5764_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tea5764_device *radio;
struct v4l2_device *v4l2_dev;
struct v4l2_ctrl_handler *hdl;
struct tea5764_regs *r;
int ret;
PDEBUG("probe");
radio = kzalloc(sizeof(struct tea5764_device), GFP_KERNEL);
if (!radio)
return -ENOMEM;
v4l2_dev = &radio->v4l2_dev;
ret = v4l2_device_register(&client->dev, v4l2_dev);
if (ret < 0) {
v4l2_err(v4l2_dev, "could not register v4l2_device\n");
goto errfr;
}
hdl = &radio->ctrl_handler;
v4l2_ctrl_handler_init(hdl, 1);
v4l2_ctrl_new_std(hdl, &tea5764_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
v4l2_dev->ctrl_handler = hdl;
if (hdl->error) {
ret = hdl->error;
v4l2_err(v4l2_dev, "Could not register controls\n");
goto errunreg;
}
mutex_init(&radio->mutex);
radio->i2c_client = client;
ret = tea5764_i2c_read(radio);
if (ret)
goto errunreg;
r = &radio->regs;
PDEBUG("chipid = %04X, manid = %04X", r->chipid, r->manid);
if (r->chipid != TEA5764_CHIPID ||
(r->manid & 0x0fff) != TEA5764_MANID) {
PWARN("This chip is not a TEA5764!");
ret = -EINVAL;
goto errunreg;
}
radio->vdev = tea5764_radio_template;
i2c_set_clientdata(client, radio);
video_set_drvdata(&radio->vdev, radio);
radio->vdev.lock = &radio->mutex;
radio->vdev.v4l2_dev = v4l2_dev;
set_bit(V4L2_FL_USE_FH_PRIO, &radio->vdev.flags);
tea5764_i2c_read(radio);
tea5764_set_audout_mode(radio, V4L2_TUNER_MODE_STEREO);
tea5764_mute(radio, 1);
tea5764_power_down(radio);
ret = video_register_device(&radio->vdev, VFL_TYPE_RADIO, radio_nr);
if (ret < 0) {
PWARN("Could not register video device!");
goto errunreg;
}
PINFO("registered.");
return 0;
errunreg:
v4l2_ctrl_handler_free(hdl);
v4l2_device_unregister(v4l2_dev);
errfr:
kfree(radio);
return ret;
}
static int tea5764_i2c_remove(struct i2c_client *client)
{
struct tea5764_device *radio = i2c_get_clientdata(client);
PDEBUG("remove");
if (radio) {
tea5764_power_down(radio);
video_unregister_device(&radio->vdev);
v4l2_ctrl_handler_free(&radio->ctrl_handler);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio);
}
return 0;
}
