int __pxa2xx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct pxa2xx_runtime_data *rtd = runtime->private_data;
size_t totsize = params_buffer_bytes(params);
size_t period = params_period_bytes(params);
pxa_dma_desc *dma_desc;
dma_addr_t dma_buff_phys, next_desc_phys;
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
runtime->dma_bytes = totsize;
dma_desc = rtd->dma_desc_array;
next_desc_phys = rtd->dma_desc_array_phys;
dma_buff_phys = runtime->dma_addr;
do {
next_desc_phys += sizeof(pxa_dma_desc);
dma_desc->ddadr = next_desc_phys;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dma_desc->dsadr = dma_buff_phys;
dma_desc->dtadr = rtd->params->dev_addr;
} else {
dma_desc->dsadr = rtd->params->dev_addr;
dma_desc->dtadr = dma_buff_phys;
}
if (period > totsize)
period = totsize;
dma_desc->dcmd = rtd->params->dcmd | period | DCMD_ENDIRQEN;
dma_desc++;
dma_buff_phys += period;
} while (totsize -= period);
dma_desc[-1].ddadr = rtd->dma_desc_array_phys;
return 0;
}
int __pxa2xx_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct pxa2xx_runtime_data *rtd = substream->runtime->private_data;
if (rtd && rtd->params && rtd->params->drcmr)
*rtd->params->drcmr = 0;
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
int pxa2xx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct pxa2xx_runtime_data *prtd = substream->runtime->private_data;
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
DDADR(prtd->dma_ch) = prtd->dma_desc_array_phys;
DCSR(prtd->dma_ch) = DCSR_RUN;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
DCSR(prtd->dma_ch) &= ~DCSR_RUN;
break;
case SNDRV_PCM_TRIGGER_RESUME:
DCSR(prtd->dma_ch) |= DCSR_RUN;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
DDADR(prtd->dma_ch) = prtd->dma_desc_array_phys;
DCSR(prtd->dma_ch) |= DCSR_RUN;
break;
default:
ret = -EINVAL;
}
return ret;
}
snd_pcm_uframes_t
pxa2xx_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct pxa2xx_runtime_data *prtd = runtime->private_data;
dma_addr_t ptr = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) ?
DSADR(prtd->dma_ch) : DTADR(prtd->dma_ch);
snd_pcm_uframes_t x = bytes_to_frames(runtime, ptr - runtime->dma_addr);
if (x == runtime->buffer_size)
x = 0;
return x;
}
int __pxa2xx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct pxa2xx_runtime_data *prtd = substream->runtime->private_data;
if (!prtd || !prtd->params)
return 0;
if (prtd->dma_ch == -1)
return -EINVAL;
DCSR(prtd->dma_ch) &= ~DCSR_RUN;
DCSR(prtd->dma_ch) = 0;
DCMD(prtd->dma_ch) = 0;
*prtd->params->drcmr = prtd->dma_ch | DRCMR_MAPVLD;
return 0;
}
void pxa2xx_pcm_dma_irq(int dma_ch, void *dev_id)
{
struct snd_pcm_substream *substream = dev_id;
struct pxa2xx_runtime_data *rtd = substream->runtime->private_data;
int dcsr;
dcsr = DCSR(dma_ch);
DCSR(dma_ch) = dcsr & ~DCSR_STOPIRQEN;
if (dcsr & DCSR_ENDINTR) {
snd_pcm_period_elapsed(substream);
} else {
printk(KERN_ERR "%s: DMA error on channel %d (DCSR=%#x)\n",
rtd->params->name, dma_ch, dcsr);
snd_pcm_stream_lock(substream);
snd_pcm_stop(substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(substream);
}
}
int __pxa2xx_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct pxa2xx_runtime_data *rtd;
int ret;
runtime->hw = pxa2xx_pcm_hardware;
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 32);
if (ret)
goto out;
ret = snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 32);
if (ret)
goto out;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0)
goto out;
ret = -ENOMEM;
rtd = kzalloc(sizeof(*rtd), GFP_KERNEL);
if (!rtd)
goto out;
rtd->dma_desc_array =
dma_alloc_writecombine(substream->pcm->card->dev, PAGE_SIZE,
&rtd->dma_desc_array_phys, GFP_KERNEL);
if (!rtd->dma_desc_array)
goto err1;
rtd->dma_ch = -1;
runtime->private_data = rtd;
return 0;
err1:
kfree(rtd);
out:
return ret;
}
int __pxa2xx_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct pxa2xx_runtime_data *rtd = runtime->private_data;
dma_free_writecombine(substream->pcm->card->dev, PAGE_SIZE,
rtd->dma_desc_array, rtd->dma_desc_array_phys);
kfree(rtd);
return 0;
}
int pxa2xx_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_writecombine(substream->pcm->card->dev, vma,
runtime->dma_area,
runtime->dma_addr,
runtime->dma_bytes);
}
int pxa2xx_pcm_preallocate_dma_buffer(struct snd_pcm *pcm, int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = pxa2xx_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_writecombine(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
void pxa2xx_pcm_free_dma_buffers(struct snd_pcm *pcm)
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
dma_free_writecombine(pcm->card->dev, buf->bytes,
buf->area, buf->addr);
buf->area = NULL;
}
}
