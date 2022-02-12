static void snd_tea575x_write(struct snd_tea575x *tea, unsigned int val)
{
u16 l;
u8 data;
tea->ops->set_direction(tea, 1);
udelay(16);
for (l = 25; l > 0; l--) {
data = (val >> 24) & TEA575X_DATA;
val <<= 1;
tea->ops->set_pins(tea, data | TEA575X_WREN);
udelay(2);
tea->ops->set_pins(tea, data | TEA575X_WREN | TEA575X_CLK);
udelay(2);
tea->ops->set_pins(tea, data | TEA575X_WREN);
udelay(2);
}
if (!tea->mute)
tea->ops->set_pins(tea, 0);
}
static unsigned int snd_tea575x_read(struct snd_tea575x *tea)
{
u16 l, rdata;
u32 data = 0;
tea->ops->set_direction(tea, 0);
tea->ops->set_pins(tea, 0);
udelay(16);
for (l = 24; l--;) {
tea->ops->set_pins(tea, TEA575X_CLK);
udelay(2);
if (!l)
tea->tuned = tea->ops->get_pins(tea) & TEA575X_MOST ? 0 : 1;
tea->ops->set_pins(tea, 0);
udelay(2);
data <<= 1;
rdata = tea->ops->get_pins(tea);
if (!l)
tea->stereo = (rdata & TEA575X_MOST) ? 0 : 1;
if (rdata & TEA575X_DATA)
data++;
udelay(2);
}
if (tea->mute)
tea->ops->set_pins(tea, TEA575X_WREN);
return data;
}
static void snd_tea575x_get_freq(struct snd_tea575x *tea)
{
unsigned long freq;
freq = snd_tea575x_read(tea) & TEA575X_BIT_FREQ_MASK;
freq *= 125;
freq /= 10;
if (tea->tea5759)
freq += TEA575X_FMIF;
else
freq -= TEA575X_FMIF;
tea->freq = freq * 16;
}
static void snd_tea575x_set_freq(struct snd_tea575x *tea)
{
unsigned long freq;
freq = clamp(tea->freq, FREQ_LO, FREQ_HI);
freq /= 16;
if (tea->tea5759)
freq -= TEA575X_FMIF;
else
freq += TEA575X_FMIF;
freq *= 10;
freq /= 125;
tea->val &= ~TEA575X_BIT_FREQ_MASK;
tea->val |= freq & TEA575X_BIT_FREQ_MASK;
snd_tea575x_write(tea, tea->val);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct snd_tea575x *tea = video_drvdata(file);
strlcpy(v->driver, "tea575x-tuner", sizeof(v->driver));
strlcpy(v->card, tea->card, sizeof(v->card));
strlcat(v->card, tea->tea5759 ? " TEA5759" : " TEA5757", sizeof(v->card));
strlcpy(v->bus_info, tea->bus_info, sizeof(v->bus_info));
v->version = RADIO_VERSION;
v->capabilities = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct snd_tea575x *tea = video_drvdata(file);
if (v->index > 0)
return -EINVAL;
snd_tea575x_read(tea);
strcpy(v->name, "FM");
v->type = V4L2_TUNER_RADIO;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
v->rangelow = FREQ_LO;
v->rangehigh = FREQ_HI;
v->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
v->audmode = tea->stereo ? V4L2_TUNER_MODE_STEREO : V4L2_TUNER_MODE_MONO;
v->signal = tea->tuned ? 0xffff : 0;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
if (v->index > 0)
return -EINVAL;
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct snd_tea575x *tea = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
snd_tea575x_get_freq(tea);
f->frequency = tea->freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct snd_tea575x *tea = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
if (f->frequency < FREQ_LO || f->frequency > FREQ_HI)
return -EINVAL;
tea->freq = f->frequency;
snd_tea575x_set_freq(tea);
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
struct v4l2_audio *a)
{
if (a->index != 0)
return -EINVAL;
return 0;
}
static int tea575x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct snd_tea575x *tea = container_of(ctrl->handler, struct snd_tea575x, ctrl_handler);
switch (ctrl->id) {
case V4L2_CID_AUDIO_MUTE:
tea->mute = ctrl->val;
snd_tea575x_set_freq(tea);
return 0;
}
return -EINVAL;
}
int snd_tea575x_init(struct snd_tea575x *tea)
{
int retval;
tea->mute = 1;
snd_tea575x_write(tea, 0x55AA);
if (snd_tea575x_read(tea) != 0x55AA)
return -ENODEV;
tea->val = TEA575X_BIT_BAND_FM | TEA575X_BIT_SEARCH_10_40;
tea->freq = 90500 * 16;
snd_tea575x_set_freq(tea);
tea->vd = tea575x_radio;
video_set_drvdata(&tea->vd, tea);
mutex_init(&tea->mutex);
tea->vd.lock = &tea->mutex;
v4l2_ctrl_handler_init(&tea->ctrl_handler, 1);
tea->vd.ctrl_handler = &tea->ctrl_handler;
v4l2_ctrl_new_std(&tea->ctrl_handler, &tea575x_ctrl_ops, V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
retval = tea->ctrl_handler.error;
if (retval) {
printk(KERN_ERR "tea575x-tuner: can't initialize controls\n");
v4l2_ctrl_handler_free(&tea->ctrl_handler);
return retval;
}
if (tea->ext_init) {
retval = tea->ext_init(tea);
if (retval) {
v4l2_ctrl_handler_free(&tea->ctrl_handler);
return retval;
}
}
v4l2_ctrl_handler_setup(&tea->ctrl_handler);
retval = video_register_device(&tea->vd, VFL_TYPE_RADIO, radio_nr);
if (retval) {
printk(KERN_ERR "tea575x-tuner: can't register video device!\n");
v4l2_ctrl_handler_free(&tea->ctrl_handler);
return retval;
}
return 0;
}
void snd_tea575x_exit(struct snd_tea575x *tea)
{
video_unregister_device(&tea->vd);
v4l2_ctrl_handler_free(&tea->ctrl_handler);
}
static int __init alsa_tea575x_module_init(void)
{
return 0;
}
static void __exit alsa_tea575x_module_exit(void)
{
}
