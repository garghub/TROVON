static void bf5xx_dma_irq(void *data)
{
struct snd_pcm_substream *pcm = data;
snd_pcm_period_elapsed(pcm);
}
static int bf5xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
unsigned int buffer_size = params_buffer_bytes(params);
struct bf5xx_i2s_pcm_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_data->tdm_mode)
buffer_size = buffer_size / params_channels(params) * 8;
return snd_pcm_lib_malloc_pages(substream, buffer_size);
}
static int bf5xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static int bf5xx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
int period_bytes = frames_to_bytes(runtime, runtime->period_size);
struct bf5xx_i2s_pcm_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_data->tdm_mode)
period_bytes = period_bytes / runtime->channels * 8;
pr_debug("%s enter\n", __func__);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
sport_set_tx_callback(sport, bf5xx_dma_irq, substream);
sport_config_tx_dma(sport, runtime->dma_area,
runtime->periods, period_bytes);
} else {
sport_set_rx_callback(sport, bf5xx_dma_irq, substream);
sport_config_rx_dma(sport, runtime->dma_area,
runtime->periods, period_bytes);
}
return 0;
}
static int bf5xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
int ret = 0;
pr_debug("%s enter\n", __func__);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_tx_start(sport);
else
sport_rx_start(sport);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_tx_stop(sport);
else
sport_rx_stop(sport);
break;
default:
ret = -EINVAL;
}
return ret;
}
static snd_pcm_uframes_t bf5xx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
unsigned int diff;
snd_pcm_uframes_t frames;
struct bf5xx_i2s_pcm_data *dma_data;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
pr_debug("%s enter\n", __func__);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
diff = sport_curr_offset_tx(sport);
} else {
diff = sport_curr_offset_rx(sport);
}
if (diff == snd_pcm_lib_buffer_bytes(substream))
diff = 0;
frames = bytes_to_frames(substream->runtime, diff);
if (dma_data->tdm_mode)
frames = frames * runtime->channels / 8;
return frames;
}
static int bf5xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_dma_buffer *buf = &substream->dma_buffer;
struct bf5xx_i2s_pcm_data *dma_data;
int ret;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
pr_debug("%s enter\n", __func__);
snd_soc_set_runtime_hwparams(substream, &bf5xx_pcm_hardware);
if (dma_data->tdm_mode)
runtime->hw.buffer_bytes_max /= 4;
else
runtime->hw.info |= SNDRV_PCM_INFO_MMAP;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
if (sport_handle != NULL) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_handle->tx_buf = buf->area;
else
sport_handle->rx_buf = buf->area;
runtime->private_data = sport_handle;
} else {
pr_err("sport_handle is NULL\n");
return -1;
}
return 0;
out:
return ret;
}
static int bf5xx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
size_t size = vma->vm_end - vma->vm_start;
vma->vm_start = (unsigned long)runtime->dma_area;
vma->vm_end = vma->vm_start + size;
vma->vm_flags |= VM_SHARED;
return 0 ;
}
static int bf5xx_pcm_copy(struct snd_pcm_substream *substream, int channel,
snd_pcm_uframes_t pos, void *buf, snd_pcm_uframes_t count)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int sample_size = runtime->sample_bits / 8;
struct bf5xx_i2s_pcm_data *dma_data;
unsigned int i;
void *src, *dst;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_data->tdm_mode) {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
src = buf;
dst = runtime->dma_area;
dst += pos * sample_size * 8;
while (count--) {
for (i = 0; i < runtime->channels; i++) {
memcpy(dst + dma_data->map[i] *
sample_size, src, sample_size);
src += sample_size;
}
dst += 8 * sample_size;
}
} else {
src = runtime->dma_area;
src += pos * sample_size * 8;
dst = buf;
while (count--) {
for (i = 0; i < runtime->channels; i++) {
memcpy(dst, src + dma_data->map[i] *
sample_size, sample_size);
dst += sample_size;
}
src += 8 * sample_size;
}
}
} else {
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
src = buf;
dst = runtime->dma_area;
dst += frames_to_bytes(runtime, pos);
} else {
src = runtime->dma_area;
src += frames_to_bytes(runtime, pos);
dst = buf;
}
memcpy(dst, src, frames_to_bytes(runtime, count));
}
return 0;
}
static int bf5xx_pcm_silence(struct snd_pcm_substream *substream,
int channel, snd_pcm_uframes_t pos, snd_pcm_uframes_t count)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int sample_size = runtime->sample_bits / 8;
void *buf = runtime->dma_area;
struct bf5xx_i2s_pcm_data *dma_data;
unsigned int offset, samples;
dma_data = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (dma_data->tdm_mode) {
offset = pos * 8 * sample_size;
samples = count * 8;
} else {
offset = frames_to_bytes(runtime, pos);
samples = count * runtime->channels;
}
snd_pcm_format_set_silence(runtime->format, buf + offset, samples);
return 0;
}
static int bf5xx_pcm_i2s_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
size_t size = bf5xx_pcm_hardware.buffer_bytes_max;
int ret;
pr_debug("%s enter\n", __func__);
ret = dma_coerce_mask_and_coherent(card->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
return snd_pcm_lib_preallocate_pages_for_all(rtd->pcm,
SNDRV_DMA_TYPE_DEV, card->dev, size, size);
}
static int bfin_i2s_soc_platform_probe(struct platform_device *pdev)
{
return devm_snd_soc_register_platform(&pdev->dev,
&bf5xx_i2s_soc_platform);
}
