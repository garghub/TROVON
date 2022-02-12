static int atmel_pcm_preallocate_dma_buffer(struct snd_pcm *pcm,
int stream)
{
struct snd_pcm_substream *substream = pcm->streams[stream].substream;
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = ATMEL_SSC_DMABUF_SIZE;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = pcm->card->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(pcm->card->dev, size,
&buf->addr, GFP_KERNEL);
pr_debug("atmel-pcm: alloc dma buffer: area=%p, addr=%p, size=%d\n",
(void *)buf->area, (void *)buf->addr, size);
if (!buf->area)
return -ENOMEM;
buf->bytes = size;
return 0;
}
int atmel_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
return remap_pfn_range(vma, vma->vm_start,
substream->dma_buffer.addr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
int atmel_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_card *card = rtd->card->snd_card;
struct snd_pcm *pcm = rtd->pcm;
int ret = 0;
if (!card->dev->dma_mask)
card->dev->dma_mask = &atmel_pcm_dmamask;
if (!card->dev->coherent_dma_mask)
card->dev->coherent_dma_mask = DMA_BIT_MASK(32);
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {
pr_debug("atmel-pcm: allocating PCM playback DMA buffer\n");
ret = atmel_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_PLAYBACK);
if (ret)
goto out;
}
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
pr_debug("atmel-pcm: allocating PCM capture DMA buffer\n");
ret = atmel_pcm_preallocate_dma_buffer(pcm,
SNDRV_PCM_STREAM_CAPTURE);
if (ret)
goto out;
}
out:
return ret;
}
void atmel_pcm_free(struct snd_pcm *pcm)
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
