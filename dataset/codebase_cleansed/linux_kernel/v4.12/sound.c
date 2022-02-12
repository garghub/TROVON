static void swap_copy16(u16 *dest, const u16 *source, unsigned int bytes)
{
unsigned int i = 0;
while (i < (bytes / 2)) {
dest[i] = swap16(source[i]);
i++;
}
}
static void swap_copy24(u8 *dest, const u8 *source, unsigned int bytes)
{
unsigned int i = 0;
while (i < bytes - 2) {
dest[i] = source[i + 2];
dest[i + 1] = source[i + 1];
dest[i + 2] = source[i];
i += 3;
}
}
static void swap_copy32(u32 *dest, const u32 *source, unsigned int bytes)
{
unsigned int i = 0;
while (i < bytes / 4) {
dest[i] = swap32(source[i]);
i++;
}
}
static void alsa_to_most_memcpy(void *alsa, void *most, unsigned int bytes)
{
memcpy(most, alsa, bytes);
}
static void alsa_to_most_copy16(void *alsa, void *most, unsigned int bytes)
{
swap_copy16(most, alsa, bytes);
}
static void alsa_to_most_copy24(void *alsa, void *most, unsigned int bytes)
{
swap_copy24(most, alsa, bytes);
}
static void alsa_to_most_copy32(void *alsa, void *most, unsigned int bytes)
{
swap_copy32(most, alsa, bytes);
}
static void most_to_alsa_memcpy(void *alsa, void *most, unsigned int bytes)
{
memcpy(alsa, most, bytes);
}
static void most_to_alsa_copy16(void *alsa, void *most, unsigned int bytes)
{
swap_copy16(alsa, most, bytes);
}
static void most_to_alsa_copy24(void *alsa, void *most, unsigned int bytes)
{
swap_copy24(alsa, most, bytes);
}
static void most_to_alsa_copy32(void *alsa, void *most, unsigned int bytes)
{
swap_copy32(alsa, most, bytes);
}
static struct channel *get_channel(struct most_interface *iface,
int channel_id)
{
struct channel *channel, *tmp;
list_for_each_entry_safe(channel, tmp, &dev_list, list) {
if ((channel->iface == iface) && (channel->id == channel_id))
return channel;
}
return NULL;
}
static bool copy_data(struct channel *channel, struct mbo *mbo)
{
struct snd_pcm_runtime *const runtime = channel->substream->runtime;
unsigned int const frame_bytes = channel->cfg->subbuffer_size;
unsigned int const buffer_size = runtime->buffer_size;
unsigned int frames;
unsigned int fr0;
if (channel->cfg->direction & MOST_CH_RX)
frames = mbo->processed_length / frame_bytes;
else
frames = mbo->buffer_length / frame_bytes;
fr0 = min(buffer_size - channel->buffer_pos, frames);
channel->copy_fn(runtime->dma_area + channel->buffer_pos * frame_bytes,
mbo->virt_address,
fr0 * frame_bytes);
if (frames > fr0) {
channel->copy_fn(runtime->dma_area,
mbo->virt_address + fr0 * frame_bytes,
(frames - fr0) * frame_bytes);
}
channel->buffer_pos += frames;
if (channel->buffer_pos >= buffer_size)
channel->buffer_pos -= buffer_size;
channel->period_pos += frames;
if (channel->period_pos >= runtime->period_size) {
channel->period_pos -= runtime->period_size;
return true;
}
return false;
}
static int playback_thread(void *data)
{
struct channel *const channel = data;
while (!kthread_should_stop()) {
struct mbo *mbo = NULL;
bool period_elapsed = false;
wait_event_interruptible(
channel->playback_waitq,
kthread_should_stop() ||
(channel->is_stream_running &&
(mbo = most_get_mbo(channel->iface, channel->id,
&audio_aim))));
if (!mbo)
continue;
if (channel->is_stream_running)
period_elapsed = copy_data(channel, mbo);
else
memset(mbo->virt_address, 0, mbo->buffer_length);
most_submit_mbo(mbo);
if (period_elapsed)
snd_pcm_period_elapsed(channel->substream);
}
return 0;
}
static int pcm_open(struct snd_pcm_substream *substream)
{
struct channel *channel = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct most_channel_config *cfg = channel->cfg;
channel->substream = substream;
if (cfg->direction == MOST_CH_TX) {
channel->playback_task = kthread_run(playback_thread, channel,
"most_audio_playback");
if (IS_ERR(channel->playback_task)) {
pr_err("Couldn't start thread\n");
return PTR_ERR(channel->playback_task);
}
}
if (most_start_channel(channel->iface, channel->id, &audio_aim)) {
pr_err("most_start_channel() failed!\n");
if (cfg->direction == MOST_CH_TX)
kthread_stop(channel->playback_task);
return -EBUSY;
}
runtime->hw = channel->pcm_hardware;
return 0;
}
static int pcm_close(struct snd_pcm_substream *substream)
{
struct channel *channel = substream->private_data;
if (channel->cfg->direction == MOST_CH_TX)
kthread_stop(channel->playback_task);
most_stop_channel(channel->iface, channel->id, &audio_aim);
return 0;
}
static int pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct channel *channel = substream->private_data;
if ((params_channels(hw_params) > channel->pcm_hardware.channels_max) ||
(params_channels(hw_params) < channel->pcm_hardware.channels_min)) {
pr_err("Requested number of channels not supported.\n");
return -EINVAL;
}
return snd_pcm_lib_alloc_vmalloc_buffer(substream,
params_buffer_bytes(hw_params));
}
static int pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_vmalloc_buffer(substream);
}
static int pcm_prepare(struct snd_pcm_substream *substream)
{
struct channel *channel = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct most_channel_config *cfg = channel->cfg;
int width = snd_pcm_format_physical_width(runtime->format);
channel->copy_fn = NULL;
if (cfg->direction == MOST_CH_TX) {
if (snd_pcm_format_big_endian(runtime->format) || width == 8)
channel->copy_fn = alsa_to_most_memcpy;
else if (width == 16)
channel->copy_fn = alsa_to_most_copy16;
else if (width == 24)
channel->copy_fn = alsa_to_most_copy24;
else if (width == 32)
channel->copy_fn = alsa_to_most_copy32;
} else {
if (snd_pcm_format_big_endian(runtime->format) || width == 8)
channel->copy_fn = most_to_alsa_memcpy;
else if (width == 16)
channel->copy_fn = most_to_alsa_copy16;
else if (width == 24)
channel->copy_fn = most_to_alsa_copy24;
else if (width == 32)
channel->copy_fn = most_to_alsa_copy32;
}
if (!channel->copy_fn) {
pr_err("unsupported format\n");
return -EINVAL;
}
channel->period_pos = 0;
channel->buffer_pos = 0;
return 0;
}
static int pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct channel *channel = substream->private_data;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
channel->is_stream_running = true;
wake_up_interruptible(&channel->playback_waitq);
return 0;
case SNDRV_PCM_TRIGGER_STOP:
channel->is_stream_running = false;
return 0;
default:
pr_info("%s(), invalid\n", __func__);
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t pcm_pointer(struct snd_pcm_substream *substream)
{
struct channel *channel = substream->private_data;
return channel->buffer_pos;
}
static int split_arg_list(char *buf, char **card_name, char **pcm_format)
{
*card_name = strsep(&buf, ".");
if (!*card_name)
return -EIO;
*pcm_format = strsep(&buf, ".\n");
if (!*pcm_format)
return -EIO;
return 0;
}
static int audio_set_hw_params(struct snd_pcm_hardware *pcm_hw,
char *pcm_format,
struct most_channel_config *cfg)
{
pcm_hw->info = MOST_PCM_INFO;
pcm_hw->rates = SNDRV_PCM_RATE_48000;
pcm_hw->rate_min = 48000;
pcm_hw->rate_max = 48000;
pcm_hw->buffer_bytes_max = cfg->num_buffers * cfg->buffer_size;
pcm_hw->period_bytes_min = cfg->buffer_size;
pcm_hw->period_bytes_max = cfg->buffer_size;
pcm_hw->periods_min = 1;
pcm_hw->periods_max = cfg->num_buffers;
if (!strcmp(pcm_format, "1x8")) {
if (cfg->subbuffer_size != 1)
goto error;
pr_info("PCM format is 8-bit mono\n");
pcm_hw->channels_min = 1;
pcm_hw->channels_max = 1;
pcm_hw->formats = SNDRV_PCM_FMTBIT_S8;
} else if (!strcmp(pcm_format, "2x16")) {
if (cfg->subbuffer_size != 4)
goto error;
pr_info("PCM format is 16-bit stereo\n");
pcm_hw->channels_min = 2;
pcm_hw->channels_max = 2;
pcm_hw->formats = SNDRV_PCM_FMTBIT_S16_LE |
SNDRV_PCM_FMTBIT_S16_BE;
} else if (!strcmp(pcm_format, "2x24")) {
if (cfg->subbuffer_size != 6)
goto error;
pr_info("PCM format is 24-bit stereo\n");
pcm_hw->channels_min = 2;
pcm_hw->channels_max = 2;
pcm_hw->formats = SNDRV_PCM_FMTBIT_S24_3LE |
SNDRV_PCM_FMTBIT_S24_3BE;
} else if (!strcmp(pcm_format, "2x32")) {
if (cfg->subbuffer_size != 8)
goto error;
pr_info("PCM format is 32-bit stereo\n");
pcm_hw->channels_min = 2;
pcm_hw->channels_max = 2;
pcm_hw->formats = SNDRV_PCM_FMTBIT_S32_LE |
SNDRV_PCM_FMTBIT_S32_BE;
} else if (!strcmp(pcm_format, "6x16")) {
if (cfg->subbuffer_size != 12)
goto error;
pr_info("PCM format is 16-bit 5.1 multi channel\n");
pcm_hw->channels_min = 6;
pcm_hw->channels_max = 6;
pcm_hw->formats = SNDRV_PCM_FMTBIT_S16_LE |
SNDRV_PCM_FMTBIT_S16_BE;
} else {
pr_err("PCM format %s not supported\n", pcm_format);
return -EIO;
}
return 0;
error:
pr_err("Audio resolution doesn't fit subbuffer size\n");
return -EINVAL;
}
static int audio_probe_channel(struct most_interface *iface, int channel_id,
struct most_channel_config *cfg,
struct kobject *parent, char *arg_list)
{
struct channel *channel;
struct snd_card *card;
struct snd_pcm *pcm;
int playback_count = 0;
int capture_count = 0;
int ret;
int direction;
char *card_name;
char *pcm_format;
if (!iface)
return -EINVAL;
if (cfg->data_type != MOST_CH_SYNC) {
pr_err("Incompatible channel type\n");
return -EINVAL;
}
if (get_channel(iface, channel_id)) {
pr_err("channel (%s:%d) is already linked\n",
iface->description, channel_id);
return -EINVAL;
}
if (cfg->direction == MOST_CH_TX) {
playback_count = 1;
direction = SNDRV_PCM_STREAM_PLAYBACK;
} else {
capture_count = 1;
direction = SNDRV_PCM_STREAM_CAPTURE;
}
ret = split_arg_list(arg_list, &card_name, &pcm_format);
if (ret < 0) {
pr_info("PCM format missing\n");
return ret;
}
ret = snd_card_new(NULL, -1, card_name, THIS_MODULE,
sizeof(*channel), &card);
if (ret < 0)
return ret;
channel = card->private_data;
channel->card = card;
channel->cfg = cfg;
channel->iface = iface;
channel->id = channel_id;
init_waitqueue_head(&channel->playback_waitq);
ret = audio_set_hw_params(&channel->pcm_hardware, pcm_format, cfg);
if (ret)
goto err_free_card;
snprintf(card->driver, sizeof(card->driver), "%s", DRIVER_NAME);
snprintf(card->shortname, sizeof(card->shortname), "Microchip MOST:%d",
card->number);
snprintf(card->longname, sizeof(card->longname), "%s at %s, ch %d",
card->shortname, iface->description, channel_id);
ret = snd_pcm_new(card, card_name, 0, playback_count,
capture_count, &pcm);
if (ret < 0)
goto err_free_card;
pcm->private_data = channel;
snd_pcm_set_ops(pcm, direction, &pcm_ops);
ret = snd_card_register(card);
if (ret < 0)
goto err_free_card;
list_add_tail(&channel->list, &dev_list);
return 0;
err_free_card:
snd_card_free(card);
return ret;
}
static int audio_disconnect_channel(struct most_interface *iface,
int channel_id)
{
struct channel *channel;
channel = get_channel(iface, channel_id);
if (!channel) {
pr_err("sound_disconnect_channel(), invalid channel %d\n",
channel_id);
return -EINVAL;
}
list_del(&channel->list);
snd_card_free(channel->card);
return 0;
}
static int audio_rx_completion(struct mbo *mbo)
{
struct channel *channel = get_channel(mbo->ifp, mbo->hdm_channel_id);
bool period_elapsed = false;
if (!channel) {
pr_err("sound_rx_completion(), invalid channel %d\n",
mbo->hdm_channel_id);
return -EINVAL;
}
if (channel->is_stream_running)
period_elapsed = copy_data(channel, mbo);
most_put_mbo(mbo);
if (period_elapsed)
snd_pcm_period_elapsed(channel->substream);
return 0;
}
static int audio_tx_completion(struct most_interface *iface, int channel_id)
{
struct channel *channel = get_channel(iface, channel_id);
if (!channel) {
pr_err("sound_tx_completion(), invalid channel %d\n",
channel_id);
return -EINVAL;
}
wake_up_interruptible(&channel->playback_waitq);
return 0;
}
static int __init audio_init(void)
{
pr_info("init()\n");
INIT_LIST_HEAD(&dev_list);
return most_register_aim(&audio_aim);
}
static void __exit audio_exit(void)
{
struct channel *channel, *tmp;
pr_info("exit()\n");
list_for_each_entry_safe(channel, tmp, &dev_list, list) {
list_del(&channel->list);
snd_card_free(channel->card);
}
most_deregister_aim(&audio_aim);
}
