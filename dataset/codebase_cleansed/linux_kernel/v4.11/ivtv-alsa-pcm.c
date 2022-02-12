static void ivtv_alsa_announce_pcm_data(struct snd_ivtv_card *itvsc,
u8 *pcm_data,
size_t num_bytes)
{
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
unsigned int oldptr;
unsigned int stride;
int period_elapsed = 0;
int length;
dprintk("ivtv alsa announce ptr=%p data=%p num_bytes=%zu\n", itvsc,
pcm_data, num_bytes);
substream = itvsc->capture_pcm_substream;
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
oldptr = itvsc->hwptr_done_capture;
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
itvsc->hwptr_done_capture += length;
if (itvsc->hwptr_done_capture >=
runtime->buffer_size)
itvsc->hwptr_done_capture -=
runtime->buffer_size;
itvsc->capture_transfer_done += length;
if (itvsc->capture_transfer_done >=
runtime->period_size) {
itvsc->capture_transfer_done -=
runtime->period_size;
period_elapsed = 1;
}
snd_pcm_stream_unlock(substream);
if (period_elapsed)
snd_pcm_period_elapsed(substream);
}
static int snd_ivtv_pcm_capture_open(struct snd_pcm_substream *substream)
{
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct v4l2_device *v4l2_dev = itvsc->v4l2_dev;
struct ivtv *itv = to_ivtv(v4l2_dev);
struct ivtv_stream *s;
struct ivtv_open_id item;
int ret;
snd_ivtv_lock(itvsc);
if (ivtv_init_on_first_open(itv)) {
snd_ivtv_unlock(itvsc);
return -ENXIO;
}
s = &itv->streams[IVTV_ENC_STREAM_TYPE_PCM];
v4l2_fh_init(&item.fh, &s->vdev);
item.itv = itv;
item.type = s->type;
if (ivtv_claim_stream(&item, item.type)) {
v4l2_fh_exit(&item.fh);
snd_ivtv_unlock(itvsc);
return -EBUSY;
}
if (test_bit(IVTV_F_S_STREAMOFF, &s->s_flags) ||
test_and_set_bit(IVTV_F_S_STREAMING, &s->s_flags)) {
snd_ivtv_unlock(itvsc);
return 0;
}
runtime->hw = snd_ivtv_hw_capture;
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
itvsc->capture_pcm_substream = substream;
runtime->private_data = itv;
itv->pcm_announce_callback = ivtv_alsa_announce_pcm_data;
set_bit(IVTV_F_S_STREAMING, &s->s_flags);
ret = ivtv_start_v4l2_encode_stream(s);
snd_ivtv_unlock(itvsc);
return ret;
}
static int snd_ivtv_pcm_capture_close(struct snd_pcm_substream *substream)
{
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
struct v4l2_device *v4l2_dev = itvsc->v4l2_dev;
struct ivtv *itv = to_ivtv(v4l2_dev);
struct ivtv_stream *s;
snd_ivtv_lock(itvsc);
s = &itv->streams[IVTV_ENC_STREAM_TYPE_PCM];
ivtv_stop_v4l2_encode_stream(s, 0);
clear_bit(IVTV_F_S_STREAMING, &s->s_flags);
ivtv_release_stream(s);
itv->pcm_announce_callback = NULL;
snd_ivtv_unlock(itvsc);
return 0;
}
static int snd_ivtv_pcm_ioctl(struct snd_pcm_substream *substream,
unsigned int cmd, void *arg)
{
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
int ret;
snd_ivtv_lock(itvsc);
ret = snd_pcm_lib_ioctl(substream, cmd, arg);
snd_ivtv_unlock(itvsc);
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
static int snd_ivtv_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
dprintk("%s called\n", __func__);
return snd_pcm_alloc_vmalloc_buffer(substream,
params_buffer_bytes(params));
}
static int snd_ivtv_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
unsigned long flags;
spin_lock_irqsave(&itvsc->slock, flags);
if (substream->runtime->dma_area) {
dprintk("freeing pcm capture region\n");
vfree(substream->runtime->dma_area);
substream->runtime->dma_area = NULL;
}
spin_unlock_irqrestore(&itvsc->slock, flags);
return 0;
}
static int snd_ivtv_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
itvsc->hwptr_done_capture = 0;
itvsc->capture_transfer_done = 0;
return 0;
}
static int snd_ivtv_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
return 0;
}
static
snd_pcm_uframes_t snd_ivtv_pcm_pointer(struct snd_pcm_substream *substream)
{
unsigned long flags;
snd_pcm_uframes_t hwptr_done;
struct snd_ivtv_card *itvsc = snd_pcm_substream_chip(substream);
spin_lock_irqsave(&itvsc->slock, flags);
hwptr_done = itvsc->hwptr_done_capture;
spin_unlock_irqrestore(&itvsc->slock, flags);
return hwptr_done;
}
static struct page *snd_pcm_get_vmalloc_page(struct snd_pcm_substream *subs,
unsigned long offset)
{
void *pageptr = subs->runtime->dma_area + offset;
return vmalloc_to_page(pageptr);
}
int snd_ivtv_pcm_create(struct snd_ivtv_card *itvsc)
{
struct snd_pcm *sp;
struct snd_card *sc = itvsc->sc;
struct v4l2_device *v4l2_dev = itvsc->v4l2_dev;
struct ivtv *itv = to_ivtv(v4l2_dev);
int ret;
ret = snd_pcm_new(sc, "CX2341[56] PCM",
0,
0,
1,
&sp);
if (ret) {
IVTV_ALSA_ERR("%s: snd_ivtv_pcm_create() failed with err %d\n",
__func__, ret);
goto err_exit;
}
spin_lock_init(&itvsc->slock);
snd_pcm_set_ops(sp, SNDRV_PCM_STREAM_CAPTURE,
&snd_ivtv_pcm_capture_ops);
sp->info_flags = 0;
sp->private_data = itvsc;
strlcpy(sp->name, itv->card_name, sizeof(sp->name));
return 0;
err_exit:
return ret;
}
