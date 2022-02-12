static void snd_tea575x_write(struct snd_tea575x *tea, unsigned int val)
{
u16 l;
u8 data;
if (tea->ops->write_val)
return tea->ops->write_val(tea, val);
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
static u32 snd_tea575x_read(struct snd_tea575x *tea)
{
u16 l, rdata;
u32 data = 0;
if (tea->ops->read_val)
return tea->ops->read_val(tea);
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
static u32 snd_tea575x_val_to_freq(struct snd_tea575x *tea, u32 val)
{
u32 freq = val & TEA575X_BIT_FREQ_MASK;
if (freq == 0)
return freq;
freq *= 125;
freq /= 10;
if (tea->tea5759)
freq += TEA575X_FMIF;
else
freq -= TEA575X_FMIF;
return clamp(freq * 16, FREQ_LO, FREQ_HI);
}
static u32 snd_tea575x_get_freq(struct snd_tea575x *tea)
{
return snd_tea575x_val_to_freq(tea, snd_tea575x_read(tea));
}
static void snd_tea575x_set_freq(struct snd_tea575x *tea)
{
u32 freq = tea->freq;
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
tea->freq = snd_tea575x_val_to_freq(tea, tea->val);
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct snd_tea575x *tea = video_drvdata(file);
strlcpy(v->driver, tea->v4l2_dev->name, sizeof(v->driver));
strlcpy(v->card, tea->card, sizeof(v->card));
strlcat(v->card, tea->tea5759 ? " TEA5759" : " TEA5757", sizeof(v->card));
strlcpy(v->bus_info, tea->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
if (!tea->cannot_read_data)
v->device_caps |= V4L2_CAP_HW_FREQ_SEEK;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
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
if (!tea->cannot_read_data)
v->capability |= V4L2_TUNER_CAP_HWSEEK_BOUNDED;
v->rangelow = FREQ_LO;
v->rangehigh = FREQ_HI;
v->rxsubchans = tea->stereo ? V4L2_TUNER_SUB_STEREO : V4L2_TUNER_SUB_MONO;
v->audmode = (tea->val & TEA575X_BIT_MONO) ?
V4L2_TUNER_MODE_MONO : V4L2_TUNER_MODE_STEREO;
v->signal = tea->tuned ? 0xffff : 0;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct snd_tea575x *tea = video_drvdata(file);
if (v->index)
return -EINVAL;
tea->val &= ~TEA575X_BIT_MONO;
if (v->audmode == V4L2_TUNER_MODE_MONO)
tea->val |= TEA575X_BIT_MONO;
snd_tea575x_write(tea, tea->val);
return 0;
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct snd_tea575x *tea = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = tea->freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct snd_tea575x *tea = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
tea->val &= ~TEA575X_BIT_SEARCH;
tea->freq = clamp(f->frequency, FREQ_LO, FREQ_HI);
snd_tea575x_set_freq(tea);
return 0;
}
static int vidioc_s_hw_freq_seek(struct file *file, void *fh,
struct v4l2_hw_freq_seek *a)
{
struct snd_tea575x *tea = video_drvdata(file);
unsigned long timeout;
int i;
if (tea->cannot_read_data)
return -ENOTTY;
if (a->tuner || a->wrap_around)
return -EINVAL;
tea->val &= ~TEA575X_BIT_FREQ_MASK;
tea->val |= TEA575X_BIT_SEARCH;
if (a->seek_upward)
tea->val |= TEA575X_BIT_UPDOWN;
else
tea->val &= ~TEA575X_BIT_UPDOWN;
snd_tea575x_write(tea, tea->val);
timeout = jiffies + msecs_to_jiffies(10000);
for (;;) {
if (time_after(jiffies, timeout))
break;
if (schedule_timeout_interruptible(msecs_to_jiffies(10))) {
tea->val &= ~TEA575X_BIT_SEARCH;
snd_tea575x_set_freq(tea);
return -ERESTARTSYS;
}
if (!(snd_tea575x_read(tea) & TEA575X_BIT_SEARCH)) {
u32 freq;
for (i = 0; i < 100; i++) {
msleep(10);
freq = snd_tea575x_get_freq(tea);
if (freq)
break;
}
if (freq == 0)
break;
if (abs(tea->freq - freq) < 16 * 50 ||
(a->seek_upward && freq < tea->freq) ||
(!a->seek_upward && freq > tea->freq)) {
snd_tea575x_write(tea, tea->val);
continue;
}
tea->freq = freq;
tea->val &= ~TEA575X_BIT_SEARCH;
return 0;
}
}
tea->val &= ~TEA575X_BIT_SEARCH;
snd_tea575x_set_freq(tea);
return -ENODATA;
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
int snd_tea575x_init(struct snd_tea575x *tea, struct module *owner)
{
int retval;
tea->mute = true;
if (!tea->cannot_read_data) {
snd_tea575x_write(tea, 0x55AA);
if (snd_tea575x_read(tea) != 0x55AA)
return -ENODEV;
}
tea->val = TEA575X_BIT_BAND_FM | TEA575X_BIT_SEARCH_5_28;
tea->freq = 90500 * 16;
snd_tea575x_set_freq(tea);
tea->vd = tea575x_radio;
video_set_drvdata(&tea->vd, tea);
mutex_init(&tea->mutex);
strlcpy(tea->vd.name, tea->v4l2_dev->name, sizeof(tea->vd.name));
tea->vd.lock = &tea->mutex;
tea->vd.v4l2_dev = tea->v4l2_dev;
tea->fops = tea575x_fops;
tea->fops.owner = owner;
tea->vd.fops = &tea->fops;
set_bit(V4L2_FL_USE_FH_PRIO, &tea->vd.flags);
if (tea->cannot_read_data)
v4l2_disable_ioctl(&tea->vd, VIDIOC_S_HW_FREQ_SEEK);
if (!tea->cannot_mute) {
tea->vd.ctrl_handler = &tea->ctrl_handler;
v4l2_ctrl_handler_init(&tea->ctrl_handler, 1);
v4l2_ctrl_new_std(&tea->ctrl_handler, &tea575x_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
retval = tea->ctrl_handler.error;
if (retval) {
v4l2_err(tea->v4l2_dev, "can't initialize controls\n");
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
}
retval = video_register_device(&tea->vd, VFL_TYPE_RADIO, tea->radio_nr);
if (retval) {
v4l2_err(tea->v4l2_dev, "can't register video device!\n");
v4l2_ctrl_handler_free(tea->vd.ctrl_handler);
return retval;
}
return 0;
}
void snd_tea575x_exit(struct snd_tea575x *tea)
{
video_unregister_device(&tea->vd);
v4l2_ctrl_handler_free(tea->vd.ctrl_handler);
}
static int __init alsa_tea575x_module_init(void)
{
return 0;
}
static void __exit alsa_tea575x_module_exit(void)
{
}
