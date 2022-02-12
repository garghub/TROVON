static void camelot_txdma(void *data)
{
struct camelot_pcm *cam = data;
cam->tx_period ^= 1;
snd_pcm_period_elapsed(cam->tx_ss);
}
static void camelot_rxdma(void *data)
{
struct camelot_pcm *cam = data;
cam->rx_period ^= 1;
snd_pcm_period_elapsed(cam->rx_ss);
}
static int camelot_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
int recv = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0:1;
int ret, dmairq;
snd_soc_set_runtime_hwparams(substream, &camelot_pcm_hardware);
dmairq = (recv) ? cam->txid + 2 : cam->txid;
if (recv) {
cam->rx_ss = substream;
ret = dmabrg_request_irq(dmairq, camelot_rxdma, cam);
if (unlikely(ret)) {
pr_debug("audio unit %d irqs already taken!\n",
rtd->cpu_dai->id);
return -EBUSY;
}
(void)dmabrg_request_irq(dmairq + 1,camelot_rxdma, cam);
} else {
cam->tx_ss = substream;
ret = dmabrg_request_irq(dmairq, camelot_txdma, cam);
if (unlikely(ret)) {
pr_debug("audio unit %d irqs already taken!\n",
rtd->cpu_dai->id);
return -EBUSY;
}
(void)dmabrg_request_irq(dmairq + 1, camelot_txdma, cam);
}
return 0;
}
static int camelot_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
int recv = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0:1;
int dmairq;
dmairq = (recv) ? cam->txid + 2 : cam->txid;
if (recv)
cam->rx_ss = NULL;
else
cam->tx_ss = NULL;
dmabrg_free_irq(dmairq + 1);
dmabrg_free_irq(dmairq);
return 0;
}
static int camelot_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
int recv = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0:1;
int ret;
ret = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (ret < 0)
return ret;
if (recv) {
cam->rx_period_size = params_period_bytes(hw_params);
cam->rx_period = 0;
} else {
cam->tx_period_size = params_period_bytes(hw_params);
cam->tx_period = 0;
}
return 0;
}
static int camelot_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int camelot_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
pr_debug("PCM data: addr 0x%08ulx len %d\n",
(u32)runtime->dma_addr, runtime->dma_bytes);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
BRGREG(BRGATXSAR) = (unsigned long)runtime->dma_area;
BRGREG(BRGATXTCR) = runtime->dma_bytes;
} else {
BRGREG(BRGARXDAR) = (unsigned long)runtime->dma_area;
BRGREG(BRGARXTCR) = runtime->dma_bytes;
}
return 0;
}
static inline void dmabrg_play_dma_start(struct camelot_pcm *cam)
{
unsigned long acr = BRGREG(BRGACR) & ~(ACR_TDS | ACR_RDS);
BRGREG(BRGACR) = acr | ACR_TDE | ACR_TAR | ACR_TAM_2WORD;
}
static inline void dmabrg_play_dma_stop(struct camelot_pcm *cam)
{
unsigned long acr = BRGREG(BRGACR) & ~(ACR_TDS | ACR_RDS);
BRGREG(BRGACR) = acr | ACR_TDS;
}
static inline void dmabrg_rec_dma_start(struct camelot_pcm *cam)
{
unsigned long acr = BRGREG(BRGACR) & ~(ACR_TDS | ACR_RDS);
BRGREG(BRGACR) = acr | ACR_RDE | ACR_RAR | ACR_RAM_2WORD;
}
static inline void dmabrg_rec_dma_stop(struct camelot_pcm *cam)
{
unsigned long acr = BRGREG(BRGACR) & ~(ACR_TDS | ACR_RDS);
BRGREG(BRGACR) = acr | ACR_RDS;
}
static int camelot_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
int recv = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0:1;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (recv)
dmabrg_rec_dma_start(cam);
else
dmabrg_play_dma_start(cam);
break;
case SNDRV_PCM_TRIGGER_STOP:
if (recv)
dmabrg_rec_dma_stop(cam);
else
dmabrg_play_dma_stop(cam);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t camelot_pos(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct camelot_pcm *cam = &cam_pcm_data[rtd->cpu_dai->id];
int recv = substream->stream == SNDRV_PCM_STREAM_PLAYBACK ? 0:1;
unsigned long pos;
if (recv)
pos = cam->rx_period ? cam->rx_period_size : 0;
else
pos = cam->tx_period ? cam->tx_period_size : 0;
return bytes_to_frames(runtime, pos);
}
static void camelot_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int camelot_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
DMABRG_PREALLOC_BUFFER, DMABRG_PREALLOC_BUFFER_MAX);
return 0;
}
static int __devinit sh7760_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &sh7760_soc_platform);
}
static int __devexit sh7760_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
