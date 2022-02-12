int tea5764_i2c_read(struct tea5764_device *radio)
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
int tea5764_i2c_write(struct tea5764_device *radio)
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
static int tea5764_is_muted(struct tea5764_device *radio)
{
return radio->regs.tnctrl & TEA5764_TNCTRL_MU;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct tea5764_device *radio = video_drvdata(file);
struct video_device *dev = radio->videodev;
strlcpy(v->driver, dev->dev.driver->name, sizeof(v->driver));
strlcpy(v->card, dev->name, sizeof(v->card));
snprintf(v->bus_info, sizeof(v->bus_info),
"I2C:%s", dev_name(&dev->dev));
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct tea5764_device *radio = video_drvdata(file);
struct tea5764_regs *r = &radio->regs;
if (v->index > 0)
return -EINVAL;
memset(v, 0, sizeof(*v));
strcpy(v->name, "FM");
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
struct v4l2_tuner *v)
{
struct tea5764_device *radio = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
tea5764_set_audout_mode(radio, v->audmode);
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct tea5764_device *radio = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency == 0) {
tea5764_power_down(radio);
}
if (f->frequency < (FREQ_MIN * FREQ_MUL))
return -EINVAL;
if (f->frequency > (FREQ_MAX * FREQ_MUL))
return -EINVAL;
tea5764_power_up(radio);
tea5764_tune(radio, (f->frequency * 125) / 2);
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
memset(f, 0, sizeof(*f));
f->type = V4L2_TUNER_RADIO;
if (r->tnctrl & TEA5764_TNCTRL_PUPD0)
f->frequency = (tea5764_get_freq(radio) * 2) / 125;
else
f->frequency = 0;
return 0;
}
static int vidioc_queryctrl(struct file *file, void *priv,
struct v4l2_queryctrl *qc)
{
int i;
for (i = 0; i < ARRAY_SIZE(radio_qctrl); i++) {
if (qc->id && qc->id == radio_qctrl[i].id) {
memcpy(qc, &(radio_qctrl[i]), sizeof(*qc));
return 0;
}
}
return -EINVAL;
}
static int vidioc_g_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct tea5764_device *radio = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
tea5764_i2c_read(radio);
ctrl->value = tea5764_is_muted(radio) ? 1 : 0;
return 0;
}
return -EINVAL;
}
static int vidioc_s_ctrl(struct file *file, void *priv,
struct v4l2_control *ctrl)
{
struct tea5764_device *radio = video_drvdata(file);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
tea5764_mute(radio, ctrl->value);
return 0;
}
return -EINVAL;
}
static int vidioc_g_input(struct file *filp, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int vidioc_s_input(struct file *filp, void *priv, unsigned int i)
{
if (i != 0)
return -EINVAL;
return 0;
}
static int vidioc_g_audio(struct file *file, void *priv,
struct v4l2_audio *a)
{
if (a->index > 1)
return -EINVAL;
strcpy(a->name, "Radio");
a->capability = V4L2_AUDCAP_STEREO;
return 0;
}
static int vidioc_s_audio(struct file *file, void *priv,
const struct v4l2_audio *a)
{
if (a->index != 0)
return -EINVAL;
return 0;
}
static int __devinit tea5764_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tea5764_device *radio;
struct tea5764_regs *r;
int ret;
PDEBUG("probe");
radio = kzalloc(sizeof(struct tea5764_device), GFP_KERNEL);
if (!radio)
return -ENOMEM;
mutex_init(&radio->mutex);
radio->i2c_client = client;
ret = tea5764_i2c_read(radio);
if (ret)
goto errfr;
r = &radio->regs;
PDEBUG("chipid = %04X, manid = %04X", r->chipid, r->manid);
if (r->chipid != TEA5764_CHIPID ||
(r->manid & 0x0fff) != TEA5764_MANID) {
PWARN("This chip is not a TEA5764!");
ret = -EINVAL;
goto errfr;
}
radio->videodev = video_device_alloc();
if (!(radio->videodev)) {
ret = -ENOMEM;
goto errfr;
}
memcpy(radio->videodev, &tea5764_radio_template,
sizeof(tea5764_radio_template));
i2c_set_clientdata(client, radio);
video_set_drvdata(radio->videodev, radio);
radio->videodev->lock = &radio->mutex;
tea5764_i2c_read(radio);
tea5764_set_audout_mode(radio, V4L2_TUNER_MODE_STEREO);
tea5764_mute(radio, 1);
tea5764_power_down(radio);
ret = video_register_device(radio->videodev, VFL_TYPE_RADIO, radio_nr);
if (ret < 0) {
PWARN("Could not register video device!");
goto errrel;
}
PINFO("registered.");
return 0;
errrel:
video_device_release(radio->videodev);
errfr:
kfree(radio);
return ret;
}
static int __devexit tea5764_i2c_remove(struct i2c_client *client)
{
struct tea5764_device *radio = i2c_get_clientdata(client);
PDEBUG("remove");
if (radio) {
tea5764_power_down(radio);
video_unregister_device(radio->videodev);
kfree(radio);
}
return 0;
}
