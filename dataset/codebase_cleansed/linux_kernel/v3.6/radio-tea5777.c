static u32 tea5777_freq_to_v4l2_freq(struct radio_tea5777 *tea, u32 freq)
{
return (freq * TEA5777_FM_FREQ_STEP + TEA5777_FM_IF) * 16;
}
static int radio_tea5777_set_freq(struct radio_tea5777 *tea)
{
u64 freq;
int res;
freq = clamp_t(u32, tea->freq,
TEA5777_FM_RANGELOW, TEA5777_FM_RANGEHIGH) + 8;
do_div(freq, 16);
freq -= TEA5777_FM_IF;
do_div(freq, TEA5777_FM_FREQ_STEP);
tea->write_reg &= ~(TEA5777_W_FM_PLL_MASK | TEA5777_W_FM_FREF_MASK);
tea->write_reg |= freq << TEA5777_W_FM_PLL_SHIFT;
tea->write_reg |= TEA5777_W_FM_FREF_VALUE << TEA5777_W_FM_FREF_SHIFT;
res = tea->ops->write_reg(tea, tea->write_reg);
if (res)
return res;
tea->needs_write = false;
tea->read_reg = -1;
tea->freq = tea5777_freq_to_v4l2_freq(tea, freq);
return 0;
}
static int radio_tea5777_update_read_reg(struct radio_tea5777 *tea, int wait)
{
int res;
if (tea->read_reg != -1)
return 0;
if (tea->write_before_read && tea->needs_write) {
res = radio_tea5777_set_freq(tea);
if (res)
return res;
}
if (wait) {
if (schedule_timeout_interruptible(msecs_to_jiffies(wait)))
return -ERESTARTSYS;
}
res = tea->ops->read_reg(tea, &tea->read_reg);
if (res)
return res;
tea->needs_write = true;
return 0;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *v)
{
struct radio_tea5777 *tea = video_drvdata(file);
strlcpy(v->driver, tea->v4l2_dev->name, sizeof(v->driver));
strlcpy(v->card, tea->card, sizeof(v->card));
strlcat(v->card, " TEA5777", sizeof(v->card));
strlcpy(v->bus_info, tea->bus_info, sizeof(v->bus_info));
v->device_caps = V4L2_CAP_TUNER | V4L2_CAP_RADIO;
v->device_caps |= V4L2_CAP_HW_FREQ_SEEK;
v->capabilities = v->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct radio_tea5777 *tea = video_drvdata(file);
int res;
if (v->index > 0)
return -EINVAL;
res = radio_tea5777_update_read_reg(tea, 0);
if (res)
return res;
memset(v, 0, sizeof(*v));
if (tea->has_am)
strlcpy(v->name, "AM/FM", sizeof(v->name));
else
strlcpy(v->name, "FM", sizeof(v->name));
v->type = V4L2_TUNER_RADIO;
v->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_HWSEEK_BOUNDED;
v->rangelow = TEA5777_FM_RANGELOW;
v->rangehigh = TEA5777_FM_RANGEHIGH;
v->rxsubchans = (tea->read_reg & TEA5777_R_FM_STEREO_MASK) ?
V4L2_TUNER_SUB_STEREO : V4L2_TUNER_SUB_MONO;
v->audmode = (tea->write_reg & TEA5777_W_FM_FORCEMONO_MASK) ?
V4L2_TUNER_MODE_MONO : V4L2_TUNER_MODE_STEREO;
v->signal = (tea->read_reg & TEA5777_R_LEVEL_MASK) >>
(TEA5777_R_LEVEL_SHIFT - 12);
tea->read_reg = -1;
return 0;
}
static int vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *v)
{
struct radio_tea5777 *tea = video_drvdata(file);
if (v->index)
return -EINVAL;
if (v->audmode == V4L2_TUNER_MODE_MONO)
tea->write_reg |= TEA5777_W_FM_FORCEMONO_MASK;
else
tea->write_reg &= ~TEA5777_W_FM_FORCEMONO_MASK;
return radio_tea5777_set_freq(tea);
}
static int vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct radio_tea5777 *tea = video_drvdata(file);
if (f->tuner != 0)
return -EINVAL;
f->type = V4L2_TUNER_RADIO;
f->frequency = tea->freq;
return 0;
}
static int vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *f)
{
struct radio_tea5777 *tea = video_drvdata(file);
if (f->tuner != 0 || f->type != V4L2_TUNER_RADIO)
return -EINVAL;
tea->freq = f->frequency;
return radio_tea5777_set_freq(tea);
}
static int vidioc_s_hw_freq_seek(struct file *file, void *fh,
struct v4l2_hw_freq_seek *a)
{
struct radio_tea5777 *tea = video_drvdata(file);
u32 orig_freq = tea->freq;
unsigned long timeout;
int res, spacing = 200 * 16;
const u32 seek_rangelow = TEA5777_FM_RANGELOW;
const u32 seek_rangehigh = TEA5777_FM_RANGEHIGH;
if (a->tuner || a->wrap_around)
return -EINVAL;
tea->write_reg |= TEA5777_W_PROGBLIM_MASK;
if (seek_rangelow != tea->seek_rangelow) {
tea->write_reg &= ~TEA5777_W_UPDWN_MASK;
tea->freq = seek_rangelow;
res = radio_tea5777_set_freq(tea);
if (res)
goto leave;
tea->seek_rangelow = tea->freq;
}
if (seek_rangehigh != tea->seek_rangehigh) {
tea->write_reg |= TEA5777_W_UPDWN_MASK;
tea->freq = seek_rangehigh;
res = radio_tea5777_set_freq(tea);
if (res)
goto leave;
tea->seek_rangehigh = tea->freq;
}
tea->write_reg &= ~TEA5777_W_PROGBLIM_MASK;
tea->write_reg |= TEA5777_W_SEARCH_MASK;
if (a->seek_upward) {
tea->write_reg |= TEA5777_W_UPDWN_MASK;
tea->freq = orig_freq + spacing;
} else {
tea->write_reg &= ~TEA5777_W_UPDWN_MASK;
tea->freq = orig_freq - spacing;
}
res = radio_tea5777_set_freq(tea);
if (res)
goto leave;
timeout = jiffies + msecs_to_jiffies(5000);
for (;;) {
if (time_after(jiffies, timeout)) {
res = -ENODATA;
break;
}
res = radio_tea5777_update_read_reg(tea, 100);
if (res)
break;
tea->freq = (tea->read_reg & TEA5777_R_FM_PLL_MASK);
tea->freq = tea5777_freq_to_v4l2_freq(tea, tea->freq);
if ((tea->read_reg & TEA5777_R_SFOUND_MASK)) {
tea->write_reg &= ~TEA5777_W_SEARCH_MASK;
return 0;
}
if (tea->read_reg & TEA5777_R_BLIM_MASK) {
res = -ENODATA;
break;
}
tea->read_reg = -1;
}
leave:
tea->write_reg &= ~TEA5777_W_PROGBLIM_MASK;
tea->write_reg &= ~TEA5777_W_SEARCH_MASK;
tea->freq = orig_freq;
radio_tea5777_set_freq(tea);
return res;
}
static int tea575x_s_ctrl(struct v4l2_ctrl *c)
{
struct radio_tea5777 *tea =
container_of(c->handler, struct radio_tea5777, ctrl_handler);
switch (c->id) {
case V4L2_CID_AUDIO_MUTE:
if (c->val)
tea->write_reg |= TEA5777_W_MUTE_MASK;
else
tea->write_reg &= ~TEA5777_W_MUTE_MASK;
return radio_tea5777_set_freq(tea);
}
return -EINVAL;
}
int radio_tea5777_init(struct radio_tea5777 *tea, struct module *owner)
{
int res;
tea->write_reg = (1LL << TEA5777_W_IFCE_SHIFT) |
(1LL << TEA5777_W_IFW_SHIFT) |
(1LL << TEA5777_W_INTEXT_SHIFT) |
(1LL << TEA5777_W_CHP0_SHIFT) |
(2LL << TEA5777_W_SLEV_SHIFT);
tea->freq = 90500 * 16;
res = radio_tea5777_set_freq(tea);
if (res) {
v4l2_err(tea->v4l2_dev, "can't set initial freq (%d)\n", res);
return res;
}
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
tea->vd.ctrl_handler = &tea->ctrl_handler;
v4l2_ctrl_handler_init(&tea->ctrl_handler, 1);
v4l2_ctrl_new_std(&tea->ctrl_handler, &tea575x_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
res = tea->ctrl_handler.error;
if (res) {
v4l2_err(tea->v4l2_dev, "can't initialize controls\n");
v4l2_ctrl_handler_free(&tea->ctrl_handler);
return res;
}
v4l2_ctrl_handler_setup(&tea->ctrl_handler);
res = video_register_device(&tea->vd, VFL_TYPE_RADIO, -1);
if (res) {
v4l2_err(tea->v4l2_dev, "can't register video device!\n");
v4l2_ctrl_handler_free(tea->vd.ctrl_handler);
return res;
}
return 0;
}
void radio_tea5777_exit(struct radio_tea5777 *tea)
{
video_unregister_device(&tea->vd);
v4l2_ctrl_handler_free(tea->vd.ctrl_handler);
}
