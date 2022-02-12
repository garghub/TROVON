static void atmel_pcm_dma_irq(u32 ssc_sr,
struct snd_pcm_substream *substream)
{
struct atmel_runtime_data *prtd = substream->runtime->private_data;
struct atmel_pcm_dma_params *params = prtd->params;
static int count;
count++;
if (ssc_sr & params->mask->ssc_endbuf) {
pr_warn("atmel-pcm: buffer %s on %s (SSC_SR=%#x, count=%d)\n",
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
"(dma_bytes=%zu, period_size=%zu)\n",
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
"dma_area = %p, dma_bytes = %zu\n",
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
int atmel_pcm_pdc_platform_register(struct device *dev)
{
return snd_soc_register_platform(dev, &atmel_soc_platform);
}
void atmel_pcm_pdc_platform_unregister(struct device *dev)
{
snd_soc_unregister_platform(dev);
}
