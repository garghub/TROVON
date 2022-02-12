static int mmp_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct dma_chan *chan = snd_dmaengine_pcm_get_chan(substream);
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct pxa2xx_pcm_dma_params *dma_params;
struct dma_slave_config slave_config;
int ret;
dma_params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
if (!dma_params)
return 0;
ret = snd_hwparams_to_dma_slave_config(substream, params, &slave_config);
if (ret)
return ret;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
slave_config.dst_addr = dma_params->dev_addr;
slave_config.dst_maxburst = 4;
} else {
slave_config.src_addr = dma_params->dev_addr;
slave_config.src_maxburst = 4;
}
ret = dmaengine_slave_config(chan, &slave_config);
if (ret)
return ret;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static bool filter(struct dma_chan *chan, void *param)
{
struct mmp_dma_data *dma_data = param;
bool found = false;
char *devname;
devname = kasprintf(GFP_KERNEL, "%s.%d", dma_data->dma_res->name,
dma_data->ssp_id);
if ((strcmp(dev_name(chan->device->dev), devname) == 0) &&
(chan->chan_id == dma_data->dma_res->start)) {
found = true;
}
kfree(devname);
return found;
}
static int mmp_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct platform_device *pdev = to_platform_device(rtd->platform->dev);
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct mmp_dma_data dma_data;
struct resource *r;
r = platform_get_resource(pdev, IORESOURCE_DMA, substream->stream);
if (!r)
return -EBUSY;
snd_soc_set_runtime_hwparams(substream,
&mmp_pcm_hardware[substream->stream]);
dma_data.dma_res = r;
dma_data.ssp_id = cpu_dai->id;
return snd_dmaengine_pcm_open_request_chan(substream, filter,
&dma_data);
}
static int mmp_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned long off = vma->vm_pgoff;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return remap_pfn_range(vma, vma->vm_start,
__phys_to_pfn(runtime->dma_addr) + off,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
static void mmp_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
struct gen_pool *gpool;
gpool = sram_get_gpool("asram");
if (!gpool)
return;
for (stream = 0; stream < 2; stream++) {
size_t size = mmp_pcm_hardware[stream].buffer_bytes_max;
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
gen_pool_free(gpool, (unsigned long)buf->area, size);
buf->area = NULL;
}
return;
}
static int mmp_pcm_preallocate_dma_buffer(struct snd_pcm_substream *substream,
int stream)
{
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = mmp_pcm_hardware[stream].buffer_bytes_max;
struct gen_pool *gpool;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = substream->pcm->card->dev;
buf->private_data = NULL;
gpool = sram_get_gpool("asram");
if (!gpool)
return -ENOMEM;
buf->area = (unsigned char *)gen_pool_alloc(gpool, size);
if (!buf->area)
return -ENOMEM;
buf->addr = gen_pool_virt_to_phys(gpool, (unsigned long)buf->area);
buf->bytes = size;
return 0;
}
int mmp_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm_substream *substream;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0, stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
ret = mmp_pcm_preallocate_dma_buffer(substream, stream);
if (ret)
goto err;
}
return 0;
err:
mmp_pcm_free_dma_buffers(pcm);
return ret;
}
static int mmp_pcm_probe(struct platform_device *pdev)
{
struct mmp_audio_platdata *pdata = pdev->dev.platform_data;
if (pdata) {
mmp_pcm_hardware[SNDRV_PCM_STREAM_PLAYBACK].buffer_bytes_max =
pdata->buffer_max_playback;
mmp_pcm_hardware[SNDRV_PCM_STREAM_PLAYBACK].period_bytes_max =
pdata->period_max_playback;
mmp_pcm_hardware[SNDRV_PCM_STREAM_CAPTURE].buffer_bytes_max =
pdata->buffer_max_capture;
mmp_pcm_hardware[SNDRV_PCM_STREAM_CAPTURE].period_bytes_max =
pdata->period_max_capture;
}
return snd_soc_register_platform(&pdev->dev, &mmp_soc_platform);
}
static int mmp_pcm_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
