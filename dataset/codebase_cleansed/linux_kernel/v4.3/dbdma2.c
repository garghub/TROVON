static void au1x_pcm_queue_tx(struct au1xpsc_audio_dmadata *cd)
{
au1xxx_dbdma_put_source(cd->ddma_chan, cd->dma_area,
cd->period_bytes, DDMA_FLAGS_IE);
++cd->q_period;
cd->dma_area += cd->period_bytes;
if (cd->q_period >= cd->periods) {
cd->q_period = 0;
cd->dma_area = cd->dma_area_s;
}
}
static void au1x_pcm_queue_rx(struct au1xpsc_audio_dmadata *cd)
{
au1xxx_dbdma_put_dest(cd->ddma_chan, cd->dma_area,
cd->period_bytes, DDMA_FLAGS_IE);
++cd->q_period;
cd->dma_area += cd->period_bytes;
if (cd->q_period >= cd->periods) {
cd->q_period = 0;
cd->dma_area = cd->dma_area_s;
}
}
static void au1x_pcm_dmatx_cb(int irq, void *dev_id)
{
struct au1xpsc_audio_dmadata *cd = dev_id;
cd->pos += cd->period_bytes;
if (++cd->curr_period >= cd->periods) {
cd->pos = 0;
cd->curr_period = 0;
}
snd_pcm_period_elapsed(cd->substream);
au1x_pcm_queue_tx(cd);
}
static void au1x_pcm_dmarx_cb(int irq, void *dev_id)
{
struct au1xpsc_audio_dmadata *cd = dev_id;
cd->pos += cd->period_bytes;
if (++cd->curr_period >= cd->periods) {
cd->pos = 0;
cd->curr_period = 0;
}
snd_pcm_period_elapsed(cd->substream);
au1x_pcm_queue_rx(cd);
}
static void au1x_pcm_dbdma_free(struct au1xpsc_audio_dmadata *pcd)
{
if (pcd->ddma_chan) {
au1xxx_dbdma_stop(pcd->ddma_chan);
au1xxx_dbdma_reset(pcd->ddma_chan);
au1xxx_dbdma_chan_free(pcd->ddma_chan);
pcd->ddma_chan = 0;
pcd->msbits = 0;
}
}
static int au1x_pcm_dbdma_realloc(struct au1xpsc_audio_dmadata *pcd,
int stype, int msbits)
{
if (msbits == 24)
msbits = 32;
if ((pcd->ddma_chan) && (msbits == pcd->msbits))
goto out;
au1x_pcm_dbdma_free(pcd);
if (stype == SNDRV_PCM_STREAM_CAPTURE)
pcd->ddma_chan = au1xxx_dbdma_chan_alloc(pcd->ddma_id,
DSCR_CMD0_ALWAYS,
au1x_pcm_dmarx_cb, (void *)pcd);
else
pcd->ddma_chan = au1xxx_dbdma_chan_alloc(DSCR_CMD0_ALWAYS,
pcd->ddma_id,
au1x_pcm_dmatx_cb, (void *)pcd);
if (!pcd->ddma_chan)
return -ENOMEM;
au1xxx_dbdma_set_devwidth(pcd->ddma_chan, msbits);
au1xxx_dbdma_ring_alloc(pcd->ddma_chan, 2);
pcd->msbits = msbits;
au1xxx_dbdma_stop(pcd->ddma_chan);
au1xxx_dbdma_reset(pcd->ddma_chan);
out:
return 0;
}
static inline struct au1xpsc_audio_dmadata *to_dmadata(struct snd_pcm_substream *ss)
{
struct snd_soc_pcm_runtime *rtd = ss->private_data;
struct au1xpsc_audio_dmadata *pcd =
snd_soc_platform_get_drvdata(rtd->platform);
return &pcd[ss->stream];
}
static int au1xpsc_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct au1xpsc_audio_dmadata *pcd;
int stype, ret;
ret = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (ret < 0)
goto out;
stype = substream->stream;
pcd = to_dmadata(substream);
DBG("runtime->dma_area = 0x%08lx dma_addr_t = 0x%08lx dma_size = %d "
"runtime->min_align %d\n",
(unsigned long)runtime->dma_area,
(unsigned long)runtime->dma_addr, runtime->dma_bytes,
runtime->min_align);
DBG("bits %d frags %d frag_bytes %d is_rx %d\n", params->msbits,
params_periods(params), params_period_bytes(params), stype);
ret = au1x_pcm_dbdma_realloc(pcd, stype, params->msbits);
if (ret) {
MSG("DDMA channel (re)alloc failed!\n");
goto out;
}
pcd->substream = substream;
pcd->period_bytes = params_period_bytes(params);
pcd->periods = params_periods(params);
pcd->dma_area_s = pcd->dma_area = runtime->dma_addr;
pcd->q_period = 0;
pcd->curr_period = 0;
pcd->pos = 0;
ret = 0;
out:
return ret;
}
static int au1xpsc_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static int au1xpsc_pcm_prepare(struct snd_pcm_substream *substream)
{
struct au1xpsc_audio_dmadata *pcd = to_dmadata(substream);
au1xxx_dbdma_reset(pcd->ddma_chan);
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE) {
au1x_pcm_queue_rx(pcd);
au1x_pcm_queue_rx(pcd);
} else {
au1x_pcm_queue_tx(pcd);
au1x_pcm_queue_tx(pcd);
}
return 0;
}
static int au1xpsc_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
u32 c = to_dmadata(substream)->ddma_chan;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
au1xxx_dbdma_start(c);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
au1xxx_dbdma_stop(c);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t
au1xpsc_pcm_pointer(struct snd_pcm_substream *substream)
{
return bytes_to_frames(substream->runtime, to_dmadata(substream)->pos);
}
static int au1xpsc_pcm_open(struct snd_pcm_substream *substream)
{
struct au1xpsc_audio_dmadata *pcd = to_dmadata(substream);
struct snd_soc_pcm_runtime *rtd = substream->private_data;
int stype = substream->stream, *dmaids;
dmaids = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dmaids)
return -ENODEV;
pcd->ddma_id = dmaids[stype];
snd_soc_set_runtime_hwparams(substream, &au1xpsc_pcm_hardware);
return 0;
}
static int au1xpsc_pcm_close(struct snd_pcm_substream *substream)
{
au1x_pcm_dbdma_free(to_dmadata(substream));
return 0;
}
static int au1xpsc_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
card->dev, AU1XPSC_BUFFER_MIN_BYTES, (4096 * 1024) - 1);
return 0;
}
static int au1xpsc_pcm_drvprobe(struct platform_device *pdev)
{
struct au1xpsc_audio_dmadata *dmadata;
dmadata = devm_kzalloc(&pdev->dev,
2 * sizeof(struct au1xpsc_audio_dmadata),
GFP_KERNEL);
if (!dmadata)
return -ENOMEM;
platform_set_drvdata(pdev, dmadata);
return devm_snd_soc_register_platform(&pdev->dev,
&au1xpsc_soc_platform);
}
