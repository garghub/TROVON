void cx18_alsa_announce_pcm_data(struct snd_cx18_card *cxsc, u8 *pcm_data,
size_t num_bytes)
{
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
unsigned int oldptr;
unsigned int stride;
int period_elapsed = 0;
int length;
dprintk("cx18 alsa announce ptr=%p data=%p num_bytes=%zu\n", cxsc,
pcm_data, num_bytes);
substream = cxsc->capture_pcm_substream;
if (substream == NULL) {
dprintk("substream was NULL\n");
return;
}
runtime = substream->runtime;
if (runtime == NULL) {
dprintk("runtime was NULL\n");
return;
}
stride = runtime->frame_bits >> 3;
if (stride == 0) {
dprintk("stride is zero\n");
return;
}
length = num_bytes / stride;
if (length == 0) {
dprintk("%s: length was zero\n", __func__);
return;
}
if (runtime->dma_area == NULL) {
dprintk("dma area was NULL - ignoring\n");
return;
}
oldptr = cxsc->hwptr_done_capture;
if (oldptr + length >= runtime->buffer_size) {
unsigned int cnt =
runtime->buffer_size - oldptr;
memcpy(runtime->dma_area + oldptr * stride, pcm_data,
cnt * stride);
memcpy(runtime->dma_area, pcm_data + cnt * stride,
length * stride - cnt * stride);
} else {
memcpy(runtime->dma_area + oldptr * stride, pcm_data,
length * stride);
}
snd_pcm_stream_lock(substream);
cxsc->hwptr_done_capture += length;
if (cxsc->hwptr_done_capture >=
runtime->buffer_size)
cxsc->hwptr_done_capture -=
runtime->buffer_size;
cxsc->capture_transfer_done += length;
if (cxsc->capture_transfer_done >=
runtime->period_size) {
cxsc->capture_transfer_done -=
runtime->period_size;
period_elapsed = 1;
}
snd_pcm_stream_unlock(substream);
if (period_elapsed)
snd_pcm_period_elapsed(substream);
}
static int snd_cx18_pcm_capture_open(struct snd_pcm_substream *substream)
{
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct v4l2_device *v4l2_dev = cxsc->v4l2_dev;
struct cx18 *cx = to_cx18(v4l2_dev);
struct cx18_stream *s;
struct cx18_open_id item;
int ret;
snd_cx18_lock(cxsc);
s = &cx->streams[CX18_ENC_STREAM_TYPE_PCM];
item.cx = cx;
item.type = s->type;
item.open_id = cx->open_id++;
if (cx18_claim_stream(&item, item.type)) {
snd_cx18_unlock(cxsc);
return -EBUSY;
}
if (test_bit(CX18_F_S_STREAMOFF, &s->s_flags) ||
test_and_set_bit(CX18_F_S_STREAMING, &s->s_flags)) {
snd_cx18_unlock(cxsc);
return 0;
}
runtime->hw = snd_cx18_hw_capture;
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
cxsc->capture_pcm_substream = substream;
runtime->private_data = cx;
cx->pcm_announce_callback = cx18_alsa_announce_pcm_data;
set_bit(CX18_F_S_STREAMING, &s->s_flags);
ret = cx18_start_v4l2_encode_stream(s);
snd_cx18_unlock(cxsc);
return ret;
}
static int snd_cx18_pcm_capture_close(struct snd_pcm_substream *substream)
{
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
struct v4l2_device *v4l2_dev = cxsc->v4l2_dev;
struct cx18 *cx = to_cx18(v4l2_dev);
struct cx18_stream *s;
snd_cx18_lock(cxsc);
s = &cx->streams[CX18_ENC_STREAM_TYPE_PCM];
cx18_stop_v4l2_encode_stream(s, 0);
clear_bit(CX18_F_S_STREAMING, &s->s_flags);
cx18_release_stream(s);
cx->pcm_announce_callback = NULL;
snd_cx18_unlock(cxsc);
return 0;
}
static int snd_cx18_pcm_ioctl(struct snd_pcm_substream *substream,
unsigned int cmd, void *arg)
{
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
int ret;
snd_cx18_lock(cxsc);
ret = snd_pcm_lib_ioctl(substream, cmd, arg);
snd_cx18_unlock(cxsc);
return ret;
}
static int snd_pcm_alloc_vmalloc_buffer(struct snd_pcm_substream *subs,
size_t size)
{
struct snd_pcm_runtime *runtime = subs->runtime;
dprintk("Allocating vbuffer\n");
if (runtime->dma_area) {
if (runtime->dma_bytes > size)
return 0;
vfree(runtime->dma_area);
}
runtime->dma_area = vmalloc(size);
if (!runtime->dma_area)
return -ENOMEM;
runtime->dma_bytes = size;
return 0;
}
static int snd_cx18_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
dprintk("%s called\n", __func__);
return snd_pcm_alloc_vmalloc_buffer(substream,
params_buffer_bytes(params));
}
static int snd_cx18_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
unsigned long flags;
unsigned char *dma_area = NULL;
spin_lock_irqsave(&cxsc->slock, flags);
if (substream->runtime->dma_area) {
dprintk("freeing pcm capture region\n");
dma_area = substream->runtime->dma_area;
substream->runtime->dma_area = NULL;
}
spin_unlock_irqrestore(&cxsc->slock, flags);
vfree(dma_area);
return 0;
}
static int snd_cx18_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
cxsc->hwptr_done_capture = 0;
cxsc->capture_transfer_done = 0;
return 0;
}
static int snd_cx18_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
return 0;
}
static
snd_pcm_uframes_t snd_cx18_pcm_pointer(struct snd_pcm_substream *substream)
{
unsigned long flags;
snd_pcm_uframes_t hwptr_done;
struct snd_cx18_card *cxsc = snd_pcm_substream_chip(substream);
spin_lock_irqsave(&cxsc->slock, flags);
hwptr_done = cxsc->hwptr_done_capture;
spin_unlock_irqrestore(&cxsc->slock, flags);
return hwptr_done;
}
static struct page *snd_pcm_get_vmalloc_page(struct snd_pcm_substream *subs,
unsigned long offset)
{
void *pageptr = subs->runtime->dma_area + offset;
return vmalloc_to_page(pageptr);
}
int snd_cx18_pcm_create(struct snd_cx18_card *cxsc)
{
struct snd_pcm *sp;
struct snd_card *sc = cxsc->sc;
struct v4l2_device *v4l2_dev = cxsc->v4l2_dev;
struct cx18 *cx = to_cx18(v4l2_dev);
int ret;
ret = snd_pcm_new(sc, "CX23418 PCM",
0,
0,
1,
&sp);
if (ret) {
CX18_ALSA_ERR("%s: snd_cx18_pcm_create() failed with err %d\n",
__func__, ret);
goto err_exit;
}
spin_lock_init(&cxsc->slock);
snd_pcm_set_ops(sp, SNDRV_PCM_STREAM_CAPTURE,
&snd_cx18_pcm_capture_ops);
sp->info_flags = 0;
sp->private_data = cxsc;
strlcpy(sp->name, cx->card_name, sizeof(sp->name));
return 0;
err_exit:
return ret;
}
