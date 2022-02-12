static int soc_compr_open(struct snd_compr_stream *cstream)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->open) {
ret = platform->driver->compr_ops->open(cstream);
if (ret < 0) {
pr_err("compress asoc: can't open platform %s\n", platform->name);
goto out;
}
}
if (rtd->dai_link->compr_ops && rtd->dai_link->compr_ops->startup) {
ret = rtd->dai_link->compr_ops->startup(cstream);
if (ret < 0) {
pr_err("compress asoc: %s startup failed\n", rtd->dai_link->name);
goto machine_err;
}
}
if (cstream->direction == SND_COMPRESS_PLAYBACK) {
cpu_dai->playback_active++;
codec_dai->playback_active++;
} else {
cpu_dai->capture_active++;
codec_dai->capture_active++;
}
cpu_dai->active++;
codec_dai->active++;
rtd->codec->active++;
return 0;
machine_err:
if (platform->driver->compr_ops && platform->driver->compr_ops->free)
platform->driver->compr_ops->free(cstream);
out:
return ret;
}
static int soc_compr_free(struct snd_compr_stream *cstream)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
if (cstream->direction == SND_COMPRESS_PLAYBACK) {
cpu_dai->playback_active--;
codec_dai->playback_active--;
} else {
cpu_dai->capture_active--;
codec_dai->capture_active--;
}
snd_soc_dai_digital_mute(codec_dai, 1);
cpu_dai->active--;
codec_dai->active--;
codec->active--;
if (!cpu_dai->active)
cpu_dai->rate = 0;
if (!codec_dai->active)
codec_dai->rate = 0;
if (rtd->dai_link->compr_ops && rtd->dai_link->compr_ops->shutdown)
rtd->dai_link->compr_ops->shutdown(cstream);
if (platform->driver->compr_ops && platform->driver->compr_ops->free)
platform->driver->compr_ops->free(cstream);
cpu_dai->runtime = NULL;
if (cstream->direction == SND_COMPRESS_PLAYBACK) {
if (!rtd->pmdown_time || codec->ignore_pmdown_time ||
rtd->dai_link->ignore_pmdown_time) {
snd_soc_dapm_stream_event(rtd,
SNDRV_PCM_STREAM_PLAYBACK,
SND_SOC_DAPM_STREAM_STOP);
} else
rtd->pop_wait = 1;
schedule_delayed_work(&rtd->delayed_work,
msecs_to_jiffies(rtd->pmdown_time));
} else {
snd_soc_dapm_stream_event(rtd,
SNDRV_PCM_STREAM_CAPTURE,
SND_SOC_DAPM_STREAM_STOP);
}
return 0;
}
static int soc_compr_trigger(struct snd_compr_stream *cstream, int cmd)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->trigger) {
ret = platform->driver->compr_ops->trigger(cstream, cmd);
if (ret < 0)
return ret;
}
if (cmd == SNDRV_PCM_TRIGGER_START)
snd_soc_dai_digital_mute(codec_dai, 0);
else if (cmd == SNDRV_PCM_TRIGGER_STOP)
snd_soc_dai_digital_mute(codec_dai, 1);
return ret;
}
static int soc_compr_set_params(struct snd_compr_stream *cstream,
struct snd_compr_params *params)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->set_params) {
ret = platform->driver->compr_ops->set_params(cstream, params);
if (ret < 0)
return ret;
}
if (rtd->dai_link->compr_ops && rtd->dai_link->compr_ops->set_params) {
ret = rtd->dai_link->compr_ops->set_params(cstream);
if (ret < 0)
return ret;
}
snd_soc_dapm_stream_event(rtd, SNDRV_PCM_STREAM_PLAYBACK,
SND_SOC_DAPM_STREAM_START);
return ret;
}
static int soc_compr_get_params(struct snd_compr_stream *cstream,
struct snd_codec *params)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->get_params)
ret = platform->driver->compr_ops->get_params(cstream, params);
return ret;
}
static int soc_compr_get_caps(struct snd_compr_stream *cstream,
struct snd_compr_caps *caps)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->get_caps)
ret = platform->driver->compr_ops->get_caps(cstream, caps);
return ret;
}
static int soc_compr_get_codec_caps(struct snd_compr_stream *cstream,
struct snd_compr_codec_caps *codec)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->get_codec_caps)
ret = platform->driver->compr_ops->get_codec_caps(cstream, codec);
return ret;
}
static int soc_compr_ack(struct snd_compr_stream *cstream, size_t bytes)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
int ret = 0;
if (platform->driver->compr_ops && platform->driver->compr_ops->ack)
ret = platform->driver->compr_ops->ack(cstream, bytes);
return ret;
}
static int soc_compr_pointer(struct snd_compr_stream *cstream,
struct snd_compr_tstamp *tstamp)
{
struct snd_soc_pcm_runtime *rtd = cstream->private_data;
struct snd_soc_platform *platform = rtd->platform;
if (platform->driver->compr_ops && platform->driver->compr_ops->pointer)
platform->driver->compr_ops->pointer(cstream, tstamp);
return 0;
}
int soc_new_compress(struct snd_soc_pcm_runtime *rtd, int num)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_compr *compr;
char new_name[64];
int ret = 0, direction = 0;
snprintf(new_name, sizeof(new_name), "%s %s-%d",
rtd->dai_link->stream_name, codec_dai->name, num);
direction = SND_COMPRESS_PLAYBACK;
compr = kzalloc(sizeof(*compr), GFP_KERNEL);
if (compr == NULL) {
snd_printk(KERN_ERR "Cannot allocate compr\n");
return -ENOMEM;
}
compr->ops = &soc_compr_ops;
mutex_init(&compr->lock);
ret = snd_compress_new(rtd->card->snd_card, num, direction, compr);
if (ret < 0) {
pr_err("compress asoc: can't create compress for codec %s\n",
codec->name);
kfree(compr);
return ret;
}
rtd->compr = compr;
compr->private_data = rtd;
printk(KERN_INFO "compress asoc: %s <-> %s mapping ok\n", codec_dai->name,
cpu_dai->name);
return ret;
}
