static void bf5xx_mmap_copy(struct snd_pcm_substream *substream,
snd_pcm_uframes_t count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
unsigned int chan_mask = ac97_chan_mask[runtime->channels - 1];
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
bf5xx_pcm_to_ac97((struct ac97_frame *)sport->tx_dma_buf +
sport->tx_pos, (__u16 *)runtime->dma_area + sport->tx_pos *
runtime->channels, count, chan_mask);
sport->tx_pos += runtime->period_size;
if (sport->tx_pos >= runtime->buffer_size)
sport->tx_pos %= runtime->buffer_size;
sport->tx_delay_pos = sport->tx_pos;
} else {
bf5xx_ac97_to_pcm((struct ac97_frame *)sport->rx_dma_buf +
sport->rx_pos, (__u16 *)runtime->dma_area + sport->rx_pos *
runtime->channels, count);
sport->rx_pos += runtime->period_size;
if (sport->rx_pos >= runtime->buffer_size)
sport->rx_pos %= runtime->buffer_size;
}
}
static void bf5xx_dma_irq(void *data)
{
struct snd_pcm_substream *pcm = data;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
struct snd_pcm_runtime *runtime = pcm->runtime;
struct sport_device *sport = runtime->private_data;
bf5xx_mmap_copy(pcm, runtime->period_size);
if (pcm->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (sport->once == 0) {
snd_pcm_period_elapsed(pcm);
bf5xx_mmap_copy(pcm, runtime->period_size);
sport->once = 1;
}
}
#endif
snd_pcm_period_elapsed(pcm);
}
static int bf5xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
size_t size = bf5xx_pcm_hardware.buffer_bytes_max
* sizeof(struct ac97_frame) / 4;
snd_pcm_lib_malloc_pages(substream, size);
return 0;
}
static int bf5xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
sport->once = 0;
if (runtime->dma_area)
memset(runtime->dma_area, 0, runtime->buffer_size);
memset(sport->tx_dma_buf, 0, runtime->buffer_size *
sizeof(struct ac97_frame));
} else
memset(sport->rx_dma_buf, 0, runtime->buffer_size *
sizeof(struct ac97_frame));
#endif
snd_pcm_lib_free_pages(substream);
return 0;
}
static int bf5xx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
sport_set_tx_callback(sport, bf5xx_dma_irq, substream);
sport_config_tx_dma(sport, sport->tx_dma_buf, runtime->periods,
runtime->period_size * sizeof(struct ac97_frame));
} else {
sport_set_rx_callback(sport, bf5xx_dma_irq, substream);
sport_config_rx_dma(sport, sport->rx_dma_buf, runtime->periods,
runtime->period_size * sizeof(struct ac97_frame));
}
#else
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
sport_set_tx_callback(sport, bf5xx_dma_irq, substream);
sport_config_tx_dma(sport, runtime->dma_area, runtime->periods,
runtime->period_size * sizeof(struct ac97_frame));
} else {
sport_set_rx_callback(sport, bf5xx_dma_irq, substream);
sport_config_rx_dma(sport, runtime->dma_area, runtime->periods,
runtime->period_size * sizeof(struct ac97_frame));
}
#endif
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
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
bf5xx_mmap_copy(substream, runtime->period_size);
sport->tx_delay_pos = 0;
#endif
sport_tx_start(sport);
} else
sport_rx_start(sport);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
sport->tx_pos = 0;
#endif
sport_tx_stop(sport);
} else {
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
sport->rx_pos = 0;
#endif
sport_rx_stop(sport);
}
break;
default:
ret = -EINVAL;
}
return ret;
}
static snd_pcm_uframes_t bf5xx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct sport_device *sport = runtime->private_data;
unsigned int curr;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
curr = sport->tx_delay_pos;
else
curr = sport->rx_pos;
#else
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
curr = sport_curr_offset_tx(sport) / sizeof(struct ac97_frame);
else
curr = sport_curr_offset_rx(sport) / sizeof(struct ac97_frame);
#endif
return curr;
}
static int bf5xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
struct snd_pcm_runtime *runtime = substream->runtime;
int ret;
pr_debug("%s enter\n", __func__);
snd_soc_set_runtime_hwparams(substream, &bf5xx_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
if (sport_handle != NULL)
runtime->private_data = sport_handle;
else {
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
static int bf5xx_pcm_copy(struct snd_pcm_substream *substream,
int channel, unsigned long pos,
void *buf, unsigned long count)
{
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int chan_mask = ac97_chan_mask[runtime->channels - 1];
struct ac97_frame *dst;
pr_debug("%s copy pos:0x%lx count:0x%lx\n",
substream->stream ? "Capture" : "Playback", pos, count);
dst = (struct ac97_frame *)runtime->dma_area +
bytes_to_frames(runtime, pos);
count = bytes_to_frames(runtime, count);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
bf5xx_pcm_to_ac97(dst, buf, count, chan_mask);
else
bf5xx_ac97_to_pcm(dst, buf, count);
return 0;
}
static int bf5xx_pcm_copy_user(struct snd_pcm_substream *substream,
int channel, unsigned long pos,
void __user *buf, unsigned long count)
{
return bf5xx_pcm_copy(substream, channel, pos, (void *)buf, count);
}
static int bf5xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_soc_pcm_runtime *rtd = pcm->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = bf5xx_pcm_hardware.buffer_bytes_max
* sizeof(struct ac97_frame) / 4;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area) {
pr_err("Failed to allocate dma memory\n");
pr_err("Please increase uncached DMA memory region\n");
return -ENOMEM;
}
buf->bytes = size;
pr_debug("%s, area:%p, size:0x%08lx\n", __func__,
buf->area, buf->bytes);
if (stream == SNDRV_PCM_STREAM_PLAYBACK)
sport_handle->tx_buf = buf->area;
else
sport_handle->rx_buf = buf->area;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (!sport_handle->tx_dma_buf) {
sport_handle->tx_dma_buf = dma_alloc_coherent(NULL, \
size, &sport_handle->tx_dma_phy, GFP_KERNEL);
if (!sport_handle->tx_dma_buf) {
pr_err("Failed to allocate memory for tx dma buf - Please increase uncached DMA memory region\n");
return -ENOMEM;
} else
memset(sport_handle->tx_dma_buf, 0, size);
} else
memset(sport_handle->tx_dma_buf, 0, size);
} else {
if (!sport_handle->rx_dma_buf) {
sport_handle->rx_dma_buf = dma_alloc_coherent(NULL, \
size, &sport_handle->rx_dma_phy, GFP_KERNEL);
if (!sport_handle->rx_dma_buf) {
pr_err("Failed to allocate memory for rx dma buf - Please increase uncached DMA memory region\n");
return -ENOMEM;
} else
memset(sport_handle->rx_dma_buf, 0, size);
} else
memset(sport_handle->rx_dma_buf, 0, size);
}
#endif
return 0;
}
static void bf5xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
struct snd_soc_pcm_runtime *rtd = pcm->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct sport_device *sport_handle = snd_soc_dai_get_drvdata(cpu_dai);
size_t size = bf5xx_pcm_hardware.buffer_bytes_max *
sizeof(struct ac97_frame) / 4;
#endif
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
dma_free_coherent(NULL, buf->bytes, buf->area, 0);
buf->area = NULL;
#if defined(CONFIG_SND_BF5XX_MMAP_SUPPORT)
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (sport_handle->tx_dma_buf)
dma_free_coherent(NULL, size, \
sport_handle->tx_dma_buf, 0);
sport_handle->tx_dma_buf = NULL;
} else {
if (sport_handle->rx_dma_buf)
dma_free_coherent(NULL, size, \
sport_handle->rx_dma_buf, 0);
sport_handle->rx_dma_buf = NULL;
}
#endif
}
}
static int bf5xx_pcm_ac97_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret;
pr_debug("%s enter\n", __func__);
ret = dma_coerce_mask_and_coherent(card->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = bf5xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = bf5xx_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static int bf5xx_soc_platform_probe(struct platform_device *pdev)
{
return devm_snd_soc_register_platform(&pdev->dev,
&bf5xx_ac97_soc_platform);
}
