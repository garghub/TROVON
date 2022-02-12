static int si470x_set_chan(struct si470x_device *radio, unsigned short chan)
{
int retval;
unsigned long timeout;
bool timed_out = 0;
radio->registers[CHANNEL] &= ~CHANNEL_CHAN;
radio->registers[CHANNEL] |= CHANNEL_TUNE | chan;
retval = si470x_set_register(radio, CHANNEL);
if (retval < 0)
goto done;
if (radio->stci_enabled) {
INIT_COMPLETION(radio->completion);
retval = wait_for_completion_timeout(&radio->completion,
msecs_to_jiffies(tune_timeout));
if (!retval)
timed_out = true;
} else {
timeout = jiffies + msecs_to_jiffies(tune_timeout);
do {
retval = si470x_get_register(radio, STATUSRSSI);
if (retval < 0)
goto stop;
timed_out = time_after(jiffies, timeout);
} while (((radio->registers[STATUSRSSI] & STATUSRSSI_STC) == 0)
&& (!timed_out));
}
if ((radio->registers[STATUSRSSI] & STATUSRSSI_STC) == 0)
dev_warn(&radio->videodev.dev, "tune does not complete\n");
if (timed_out)
dev_warn(&radio->videodev.dev,
"tune timed out after %u ms\n", tune_timeout);
stop:
radio->registers[CHANNEL] &= ~CHANNEL_TUNE;
retval = si470x_set_register(radio, CHANNEL);
done:
return retval;
}
static int si470x_get_freq(struct si470x_device *radio, unsigned int *freq)
{
unsigned int spacing, band_bottom;
unsigned short chan;
int retval;
switch ((radio->registers[SYSCONFIG2] & SYSCONFIG2_SPACE) >> 4) {
case 0:
spacing = 0.200 * FREQ_MUL; break;
case 1:
spacing = 0.100 * FREQ_MUL; break;
default:
spacing = 0.050 * FREQ_MUL; break;
};
switch ((radio->registers[SYSCONFIG2] & SYSCONFIG2_BAND) >> 6) {
case 0:
band_bottom = 87.5 * FREQ_MUL; break;
default:
band_bottom = 76 * FREQ_MUL; break;
case 2:
band_bottom = 76 * FREQ_MUL; break;
};
retval = si470x_get_register(radio, READCHAN);
chan = radio->registers[READCHAN] & READCHAN_READCHAN;
*freq = chan * spacing + band_bottom;
return retval;
}
int si470x_set_freq(struct si470x_device *radio, unsigned int freq)
{
unsigned int spacing, band_bottom, band_top;
unsigned short chan;
switch ((radio->registers[SYSCONFIG2] & SYSCONFIG2_SPACE) >> 4) {
case 0:
spacing = 0.200 * FREQ_MUL; break;
case 1:
spacing = 0.100 * FREQ_MUL; break;
default:
spacing = 0.050 * FREQ_MUL; break;
};
switch ((radio->registers[SYSCONFIG2] & SYSCONFIG2_BAND) >> 6) {
case 0:
band_bottom = 87.5 * FREQ_MUL;
band_top = 108 * FREQ_MUL;
break;
default:
band_bottom = 76 * FREQ_MUL;
band_top = 108 * FREQ_MUL;
break;
case 2:
band_bottom = 76 * FREQ_MUL;
band_top = 90 * FREQ_MUL;
break;
};
freq = clamp(freq, band_bottom, band_top);
chan = (freq - band_bottom) / spacing;
return si470x_set_chan(radio, chan);
}
static int si470x_set_seek(struct si470x_device *radio,
unsigned int wrap_around, unsigned int seek_upward)
{
int retval = 0;
unsigned long timeout;
bool timed_out = 0;
radio->registers[POWERCFG] |= POWERCFG_SEEK;
if (wrap_around == 1)
radio->registers[POWERCFG] &= ~POWERCFG_SKMODE;
else
radio->registers[POWERCFG] |= POWERCFG_SKMODE;
if (seek_upward == 1)
radio->registers[POWERCFG] |= POWERCFG_SEEKUP;
else
radio->registers[POWERCFG] &= ~POWERCFG_SEEKUP;
retval = si470x_set_register(radio, POWERCFG);
if (retval < 0)
return retval;
if (radio->stci_enabled) {
INIT_COMPLETION(radio->completion);
retval = wait_for_completion_timeout(&radio->completion,
msecs_to_jiffies(seek_timeout));
if (!retval)
timed_out = true;
} else {
timeout = jiffies + msecs_to_jiffies(seek_timeout);
do {
retval = si470x_get_register(radio, STATUSRSSI);
if (retval < 0)
goto stop;
timed_out = time_after(jiffies, timeout);
} while (((radio->registers[STATUSRSSI] & STATUSRSSI_STC) == 0)
&& (!timed_out));
}
if ((radio->registers[STATUSRSSI] & STATUSRSSI_STC) == 0)
dev_warn(&radio->videodev.dev, "seek does not complete\n");
if (radio->registers[STATUSRSSI] & STATUSRSSI_SF)
dev_warn(&radio->videodev.dev,
"seek failed / band limit reached\n");
stop:
radio->registers[POWERCFG] &= ~POWERCFG_SEEK;
retval = si470x_set_register(radio, POWERCFG);
if (retval == 0 && timed_out)
return -EAGAIN;
return retval;
}
int si470x_start(struct si470x_device *radio)
{
int retval;
radio->registers[POWERCFG] =
POWERCFG_DMUTE | POWERCFG_ENABLE | POWERCFG_RDSM;
retval = si470x_set_register(radio, POWERCFG);
if (retval < 0)
goto done;
radio->registers[SYSCONFIG1] =
(de << 11) & SYSCONFIG1_DE;
retval = si470x_set_register(radio, SYSCONFIG1);
if (retval < 0)
goto done;
radio->registers[SYSCONFIG2] =
(0x3f << 8) |
((band << 6) & SYSCONFIG2_BAND) |
((space << 4) & SYSCONFIG2_SPACE) |
15;
retval = si470x_set_register(radio, SYSCONFIG2);
if (retval < 0)
goto done;
retval = si470x_set_chan(radio,
radio->registers[CHANNEL] & CHANNEL_CHAN);
done:
return retval;
}
int si470x_stop(struct si470x_device *radio)
{
int retval;
radio->registers[SYSCONFIG1] &= ~SYSCONFIG1_RDS;
retval = si470x_set_register(radio, SYSCONFIG1);
if (retval < 0)
goto done;
radio->registers[POWERCFG] &= ~POWERCFG_DMUTE;
radio->registers[POWERCFG] |= POWERCFG_ENABLE | POWERCFG_DISABLE;
retval = si470x_set_register(radio, POWERCFG);
done:
return retval;
}
static int si470x_rds_on(struct si470x_device *radio)
{
int retval;
radio->registers[SYSCONFIG1] |= SYSCONFIG1_RDS;
retval = si470x_set_register(radio, SYSCONFIG1);
if (retval < 0)
radio->registers[SYSCONFIG1] &= ~SYSCONFIG1_RDS;
return retval;
}
static ssize_t si470x_fops_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct si470x_device *radio = video_drvdata(file);
int retval = 0;
unsigned int block_count = 0;
if ((radio->registers[SYSCONFIG1] & SYSCONFIG1_RDS) == 0)
si470x_rds_on(radio);
while (radio->wr_index == radio->rd_index) {
if (file->f_flags & O_NONBLOCK) {
retval = -EWOULDBLOCK;
goto done;
}
if (wait_event_interruptible(radio->read_queue,
radio->wr_index != radio->rd_index) < 0) {
retval = -EINTR;
goto done;
}
}
count /= 3;
while (block_count < count) {
if (radio->rd_index == radio->wr_index)
break;
if (copy_to_user(buf, &radio->buffer[radio->rd_index], 3))
break;
radio->rd_index += 3;
if (radio->rd_index >= radio->buf_size)
radio->rd_index = 0;
block_count++;
buf += 3;
retval += 3;
}
done:
return retval;
}
static unsigned int si470x_fops_poll(struct file *file,
struct poll_table_struct *pts)
{
struct si470x_device *radio = video_drvdata(file);
unsigned long req_events = poll_requested_events(pts);
int retval = v4l2_ctrl_poll(file, pts);
if (req_events & (POLLIN | POLLRDNORM)) {
if ((radio->registers[SYSCONFIG1] & SYSCONFIG1_RDS) == 0)
si470x_rds_on(radio);
poll_wait(file, &radio->read_queue, pts);
if (radio->rd_index != radio->wr_index)
retval |= POLLIN | POLLRDNORM;
}
return retval;
}
static int si470x_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct si470x_device *radio =
container_of(ctrl->handler, struct si470x_device, hdl);
switch (ctrl->id) {
case V4L2_CID_AUDIO_VOLUME:
radio->registers[SYSCONFIG2] &= ~SYSCONFIG2_VOLUME;
radio->registers[SYSCONFIG2] |= ctrl->val;
return si470x_set_register(radio, SYSCONFIG2);
case V4L2_CID_AUDIO_MUTE:
if (ctrl->val)
radio->registers[POWERCFG] &= ~POWERCFG_DMUTE;
else
radio->registers[POWERCFG] |= POWERCFG_DMUTE;
return si470x_set_register(radio, POWERCFG);
default:
return -EINVAL;
}
}
static int si470x_vidioc_g_tuner(struct file *file, void *priv,
struct v4l2_tuner *tuner)
{
struct si470x_device *radio = video_drvdata(file);
int retval;
if (tuner->index != 0)
return -EINVAL;
retval = si470x_get_register(radio, STATUSRSSI);
if (retval < 0)
return retval;
strcpy(tuner->name, "FM");
tuner->type = V4L2_TUNER_RADIO;
tuner->capability = V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO |
V4L2_TUNER_CAP_RDS | V4L2_TUNER_CAP_RDS_BLOCK_IO;
switch ((radio->registers[SYSCONFIG2] & SYSCONFIG2_BAND) >> 6) {
default:
tuner->rangelow = 87.5 * FREQ_MUL;
tuner->rangehigh = 108 * FREQ_MUL;
break;
case 1:
tuner->rangelow = 76 * FREQ_MUL;
tuner->rangehigh = 108 * FREQ_MUL;
break;
case 2:
tuner->rangelow = 76 * FREQ_MUL;
tuner->rangehigh = 90 * FREQ_MUL;
break;
};
if ((radio->registers[STATUSRSSI] & STATUSRSSI_ST) == 0)
tuner->rxsubchans = V4L2_TUNER_SUB_MONO;
else
tuner->rxsubchans = V4L2_TUNER_SUB_STEREO;
tuner->rxsubchans |= V4L2_TUNER_SUB_RDS;
if ((radio->registers[POWERCFG] & POWERCFG_MONO) == 0)
tuner->audmode = V4L2_TUNER_MODE_STEREO;
else
tuner->audmode = V4L2_TUNER_MODE_MONO;
tuner->signal = (radio->registers[STATUSRSSI] & STATUSRSSI_RSSI);
tuner->signal = (tuner->signal * 873) + (8 * tuner->signal / 10);
if (tuner->signal > 0xffff)
tuner->signal = 0xffff;
tuner->afc = (radio->registers[STATUSRSSI] & STATUSRSSI_AFCRL) ? 1 : 0;
return retval;
}
static int si470x_vidioc_s_tuner(struct file *file, void *priv,
struct v4l2_tuner *tuner)
{
struct si470x_device *radio = video_drvdata(file);
if (tuner->index != 0)
return -EINVAL;
switch (tuner->audmode) {
case V4L2_TUNER_MODE_MONO:
radio->registers[POWERCFG] |= POWERCFG_MONO;
break;
case V4L2_TUNER_MODE_STEREO:
default:
radio->registers[POWERCFG] &= ~POWERCFG_MONO;
break;
}
return si470x_set_register(radio, POWERCFG);
}
static int si470x_vidioc_g_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct si470x_device *radio = video_drvdata(file);
if (freq->tuner != 0)
return -EINVAL;
freq->type = V4L2_TUNER_RADIO;
return si470x_get_freq(radio, &freq->frequency);
}
static int si470x_vidioc_s_frequency(struct file *file, void *priv,
struct v4l2_frequency *freq)
{
struct si470x_device *radio = video_drvdata(file);
if (freq->tuner != 0)
return -EINVAL;
return si470x_set_freq(radio, freq->frequency);
}
static int si470x_vidioc_s_hw_freq_seek(struct file *file, void *priv,
struct v4l2_hw_freq_seek *seek)
{
struct si470x_device *radio = video_drvdata(file);
if (seek->tuner != 0)
return -EINVAL;
return si470x_set_seek(radio, seek->wrap_around, seek->seek_upward);
}
