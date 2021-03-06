static int atmel_pcm_preallocate_dma_buffer(struct snd_pcm *pcm,
int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = atmel_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
pr_debug("atmel-pcm:"
"preallocate_dma_buffer: area=%p, addr=%p, size=%d\n",
(void *) buf->area,
(void *) buf->addr,
size);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
static void atmel_pcm_dma_irq(u32 ssc_sr,
struct snd_pcm_substream *substream)
{
struct atmel_runtime_data *prtd = substream->runtime->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
static int count;
count++;
if (ssc_sr & params->mask->ssc_endbuf) {
pr_warning("atmel-pcm: buffer %s on %s"
" (SSC_SR=%#x, count=%d)\n",
substream->stream == SNDRV_PCM_STREAM_PLAYBACK
? "underrun" : "overrun",
params->name, ssc_sr, count);
ssc_writex(params->ssc->regs, ATMEL_PDC_PTCR,
params->mask->pdc_disable);
prtd->period_ptr += prtd->period_size;
if (prtd->period_ptr >= prtd->dma_buffer_end)
prtd->period_ptr = prtd->dma_buffer;
ssc_writex(params->ssc->regs, params->pdc->xpr,
prtd->period_ptr);
ssc_writex(params->ssc->regs, params->pdc->xcr,
prtd->period_size / params->pdc_xfer_size);
ssc_writex(params->ssc->regs, ATMEL_PDC_PTCR,
params->mask->pdc_enable);
}
if (ssc_sr & params->mask->ssc_endx) {
prtd->period_ptr += prtd->period_size;
if (prtd->period_ptr >= prtd->dma_buffer_end)
prtd->period_ptr = prtd->dma_buffer;
ssc_writex(params->ssc->regs, params->pdc->xnpr,
prtd->period_ptr);
ssc_writex(params->ssc->regs, params->pdc->xncr,
prtd->period_size / params->pdc_xfer_size);
}
snd_pcm_period_elapsed(substream);
}
static int atmel_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct atmel_runtime_data *prtd = runtime->private_data;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
runtime->dma_bytes = params_buffer_bytes(params);
prtd->params = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);
prtd->params->dma_intr_handler = atmel_pcm_dma_irq;
prtd->dma_buffer = runtime->dma_addr;
prtd->dma_buffer_end = runtime->dma_addr + runtime->dma_bytes;
prtd->period_size = params_period_bytes(params);
pr_debug("atmel-pcm: "
"hw_params: DMA for %s initialized "
"(dma_bytes=%u, period_size=%u)\n",
prtd->params->name,
runtime->dma_bytes,
prtd->period_size);
return 0;
}
static int atmel_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct atmel_runtime_data *prtd = substream->runtime->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
if (params != NULL) {
ssc_writex(params->ssc->regs, SSC_PDC_PTCR,
params->mask->pdc_disable);
prtd->params->dma_intr_handler = NULL;
}
return 0;
}
static int atmel_pcm_prepare(struct snd_pcm_substream *substream)
{
struct atmel_runtime_data *prtd = substream->runtime->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
ssc_writex(params->ssc->regs, SSC_IDR,
params->mask->ssc_endx | params->mask->ssc_endbuf);
ssc_writex(params->ssc->regs, ATMEL_PDC_PTCR,
params->mask->pdc_disable);
return 0;
}
static int atmel_pcm_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_pcm_runtime *rtd = substream->runtime;
struct atmel_runtime_data *prtd = rtd->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
int ret = 0;
pr_debug("atmel-pcm:buffer_size = %ld,"
"dma_area = %p, dma_bytes = %u\n",
rtd->buffer_size, rtd->dma_area, rtd->dma_bytes);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
prtd->period_ptr = prtd->dma_buffer;
ssc_writex(params->ssc->regs, params->pdc->xpr,
prtd->period_ptr);
ssc_writex(params->ssc->regs, params->pdc->xcr,
prtd->period_size / params->pdc_xfer_size);
prtd->period_ptr += prtd->period_size;
ssc_writex(params->ssc->regs, params->pdc->xnpr,
prtd->period_ptr);
ssc_writex(params->ssc->regs, params->pdc->xncr,
prtd->period_size / params->pdc_xfer_size);
pr_debug("atmel-pcm: trigger: "
"period_ptr=%lx, xpr=%u, "
"xcr=%u, xnpr=%u, xncr=%u\n",
(unsigned long)prtd->period_ptr,
ssc_readx(params->ssc->regs, params->pdc->xpr),
ssc_readx(params->ssc->regs, params->pdc->xcr),
ssc_readx(params->ssc->regs, params->pdc->xnpr),
ssc_readx(params->ssc->regs, params->pdc->xncr));
ssc_writex(params->ssc->regs, SSC_IER,
params->mask->ssc_endx | params->mask->ssc_endbuf);
ssc_writex(params->ssc->regs, SSC_PDC_PTCR,
params->mask->pdc_enable);
pr_debug("sr=%u imr=%u\n",
ssc_readx(params->ssc->regs, SSC_SR),
ssc_readx(params->ssc->regs, SSC_IER));
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ssc_writex(params->ssc->regs, ATMEL_PDC_PTCR,
params->mask->pdc_disable);
break;
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ssc_writex(params->ssc->regs, ATMEL_PDC_PTCR,
params->mask->pdc_enable);
break;
default:
ret = -EINVAL;
}
return ret;
}
static snd_pcm_uframes_t atmel_pcm_pointer(
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct atmel_runtime_data *prtd = runtime->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
dma_addr_t ptr;
snd_pcm_uframes_t x;
ptr = (dma_addr_t) ssc_readx(params->ssc->regs, params->pdc->xpr);
x = bytes_to_frames(runtime, ptr - prtd->dma_buffer);
if (x == runtime->buffer_size)
x = 0;
return x;
}
static int atmel_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct atmel_runtime_data *prtd;
int ret = 0;
snd_soc_set_runtime_hwparams(substream, &atmel_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
prtd = kzalloc(sizeof(struct atmel_runtime_data), GFP_KERNEL);
if (prtd == NULL) {
ret = -ENOMEM;
goto out;
}
runtime->private_data = prtd;
out:
return ret;
}
static int atmel_pcm_close(struct snd_pcm_substream *substream)
{
struct atmel_runtime_data *prtd = substream->runtime->private_data;
kfree(prtd);
return 0;
}
static int atmel_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
return remap_pfn_range(vma, vma->vm_start,
substream->dma_buffer.addr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
static int atmel_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &atmel_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = 0xffffffff;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
ret = atmel_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
pr_debug("atmel-pcm:"
"Allocating PCM capture DMA buffer\n");
ret = atmel_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
static void atmel_pcm_free_dma_buffers(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
struct snd_dma_buffer *buf;
int stream;
for (stream = 0; stream < 2; stream++) {
substream = pcm->streams[stream].substream;
if (!substream)
continue;
buf = &substream->dma_buffer;
if (!buf->area)
continue;
dma_free_coherent(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
static int atmel_pcm_suspend(struct snd_soc_dai *dai)
{
struct snd_pcm_runtime *runtime = dai->runtime;
struct atmel_runtime_data *prtd;
struct atmel_pcm_dma_params *params;
if (!runtime)
return 0;
prtd = runtime->private_data;
params = prtd->params;
ssc_writel(params->ssc->regs, PDC_PTCR, params->mask->pdc_disable);
prtd->pdc_xpr_save = ssc_readx(params->ssc->regs, params->pdc->xpr);
prtd->pdc_xcr_save = ssc_readx(params->ssc->regs, params->pdc->xcr);
prtd->pdc_xnpr_save = ssc_readx(params->ssc->regs, params->pdc->xnpr);
prtd->pdc_xncr_save = ssc_readx(params->ssc->regs, params->pdc->xncr);
return 0;
}
static int atmel_pcm_resume(struct snd_soc_dai *dai)
{
struct snd_pcm_runtime *runtime = dai->runtime;
struct atmel_runtime_data *prtd;
struct atmel_pcm_dma_params *params;
if (!runtime)
return 0;
prtd = runtime->private_data;
params = prtd->params;
ssc_writex(params->ssc->regs, params->pdc->xpr, prtd->pdc_xpr_save);
ssc_writex(params->ssc->regs, params->pdc->xcr, prtd->pdc_xcr_save);
ssc_writex(params->ssc->regs, params->pdc->xnpr, prtd->pdc_xnpr_save);
ssc_writex(params->ssc->regs, params->pdc->xncr, prtd->pdc_xncr_save);
ssc_writel(params->ssc->regs, PDC_PTCR, params->mask->pdc_enable);
return 0;
}
static int __devinit atmel_soc_platform_probe(struct platform_device *pdev)
{
return snd_soc_register_platform(&pdev->dev, &atmel_soc_platform);
}
static int __devexit atmel_soc_platform_remove(struct platform_device *pdev)
{
snd_soc_unregister_platform(&pdev->dev);
return 0;
}
