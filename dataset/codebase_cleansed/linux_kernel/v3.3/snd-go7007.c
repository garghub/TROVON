static void parse_audio_stream_data(struct go7007 *go, u8 *buf, int length)
{
struct go7007_snd *gosnd = go->snd_context;
struct snd_pcm_runtime *runtime = gosnd->substream->runtime;
int frames = bytes_to_frames(runtime, length);
spin_lock(&gosnd->lock);
gosnd->hw_ptr += frames;
if (gosnd->hw_ptr >= runtime->buffer_size)
gosnd->hw_ptr -= runtime->buffer_size;
gosnd->avail += frames;
spin_unlock(&gosnd->lock);
if (gosnd->w_idx + length > runtime->dma_bytes) {
int cpy = runtime->dma_bytes - gosnd->w_idx;
memcpy(runtime->dma_area + gosnd->w_idx, buf, cpy);
length -= cpy;
buf += cpy;
gosnd->w_idx = 0;
}
memcpy(runtime->dma_area + gosnd->w_idx, buf, length);
gosnd->w_idx += length;
spin_lock(&gosnd->lock);
if (gosnd->avail < runtime->period_size) {
spin_unlock(&gosnd->lock);
return;
}
gosnd->avail -= runtime->period_size;
spin_unlock(&gosnd->lock);
if (gosnd->capturing)
snd_pcm_period_elapsed(gosnd->substream);
}
static int go7007_snd_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
unsigned int bytes;
bytes = params_buffer_bytes(hw_params);
if (substream->runtime->dma_bytes > 0)
vfree(substream->runtime->dma_area);
substream->runtime->dma_bytes = 0;
substream->runtime->dma_area = vmalloc(bytes);
if (substream->runtime->dma_area == NULL)
return -ENOMEM;
substream->runtime->dma_bytes = bytes;
go->audio_deliver = parse_audio_stream_data;
return 0;
}
static int go7007_snd_hw_free(struct snd_pcm_substream *substream)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
go->audio_deliver = NULL;
if (substream->runtime->dma_bytes > 0)
vfree(substream->runtime->dma_area);
substream->runtime->dma_bytes = 0;
return 0;
}
static int go7007_snd_capture_open(struct snd_pcm_substream *substream)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
struct go7007_snd *gosnd = go->snd_context;
unsigned long flags;
int r;
spin_lock_irqsave(&gosnd->lock, flags);
if (gosnd->substream == NULL) {
gosnd->substream = substream;
substream->runtime->hw = go7007_snd_capture_hw;
r = 0;
} else
r = -EBUSY;
spin_unlock_irqrestore(&gosnd->lock, flags);
return r;
}
static int go7007_snd_capture_close(struct snd_pcm_substream *substream)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
struct go7007_snd *gosnd = go->snd_context;
gosnd->substream = NULL;
return 0;
}
static int go7007_snd_pcm_prepare(struct snd_pcm_substream *substream)
{
return 0;
}
static int go7007_snd_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
struct go7007_snd *gosnd = go->snd_context;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
gosnd->capturing = 1;
return 0;
case SNDRV_PCM_TRIGGER_STOP:
gosnd->hw_ptr = gosnd->w_idx = gosnd->avail = 0;
gosnd->capturing = 0;
return 0;
default:
return -EINVAL;
}
}
static snd_pcm_uframes_t go7007_snd_pcm_pointer(struct snd_pcm_substream *substream)
{
struct go7007 *go = snd_pcm_substream_chip(substream);
struct go7007_snd *gosnd = go->snd_context;
return gosnd->hw_ptr;
}
static struct page *go7007_snd_pcm_page(struct snd_pcm_substream *substream,
unsigned long offset)
{
return vmalloc_to_page(substream->runtime->dma_area + offset);
}
static int go7007_snd_free(struct snd_device *device)
{
struct go7007 *go = device->device_data;
kfree(go->snd_context);
go->snd_context = NULL;
if (--go->ref_count == 0)
kfree(go);
return 0;
}
int go7007_snd_init(struct go7007 *go)
{
static int dev;
struct go7007_snd *gosnd;
int ret = 0;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
gosnd = kmalloc(sizeof(struct go7007_snd), GFP_KERNEL);
if (gosnd == NULL)
return -ENOMEM;
spin_lock_init(&gosnd->lock);
gosnd->hw_ptr = gosnd->w_idx = gosnd->avail = 0;
gosnd->capturing = 0;
ret = snd_card_create(index[dev], id[dev], THIS_MODULE, 0,
&gosnd->card);
if (ret < 0) {
kfree(gosnd);
return ret;
}
ret = snd_device_new(gosnd->card, SNDRV_DEV_LOWLEVEL, go,
&go7007_snd_device_ops);
if (ret < 0) {
kfree(gosnd);
return ret;
}
snd_card_set_dev(gosnd->card, go->dev);
ret = snd_pcm_new(gosnd->card, "go7007", 0, 0, 1, &gosnd->pcm);
if (ret < 0) {
snd_card_free(gosnd->card);
kfree(gosnd);
return ret;
}
strncpy(gosnd->card->driver, "go7007", sizeof(gosnd->card->driver));
strncpy(gosnd->card->shortname, go->name, sizeof(gosnd->card->driver));
strncpy(gosnd->card->longname, gosnd->card->shortname,
sizeof(gosnd->card->longname));
gosnd->pcm->private_data = go;
snd_pcm_set_ops(gosnd->pcm, SNDRV_PCM_STREAM_CAPTURE,
&go7007_snd_capture_ops);
ret = snd_card_register(gosnd->card);
if (ret < 0) {
snd_card_free(gosnd->card);
kfree(gosnd);
return ret;
}
gosnd->substream = NULL;
go->snd_context = gosnd;
++dev;
++go->ref_count;
return 0;
}
int go7007_snd_remove(struct go7007 *go)
{
struct go7007_snd *gosnd = go->snd_context;
snd_card_disconnect(gosnd->card);
snd_card_free_when_closed(gosnd->card);
return 0;
}
