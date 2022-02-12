static int cx231xx_isoc_audio_deinit(struct cx231xx *dev)
{
int i;
dprintk("Stopping isoc\n");
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
if (dev->adev.urb[i]) {
if (!irqs_disabled())
usb_kill_urb(dev->adev.urb[i]);
else
usb_unlink_urb(dev->adev.urb[i]);
usb_free_urb(dev->adev.urb[i]);
dev->adev.urb[i] = NULL;
kfree(dev->adev.transfer_buffer[i]);
dev->adev.transfer_buffer[i] = NULL;
}
}
return 0;
}
static int cx231xx_bulk_audio_deinit(struct cx231xx *dev)
{
int i;
dprintk("Stopping bulk\n");
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
if (dev->adev.urb[i]) {
if (!irqs_disabled())
usb_kill_urb(dev->adev.urb[i]);
else
usb_unlink_urb(dev->adev.urb[i]);
usb_free_urb(dev->adev.urb[i]);
dev->adev.urb[i] = NULL;
kfree(dev->adev.transfer_buffer[i]);
dev->adev.transfer_buffer[i] = NULL;
}
}
return 0;
}
static void cx231xx_audio_isocirq(struct urb *urb)
{
struct cx231xx *dev = urb->context;
int i;
unsigned int oldptr;
int period_elapsed = 0;
int status;
unsigned char *cp;
unsigned int stride;
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
if (dev->state & DEV_DISCONNECTED)
return;
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dprintk("urb completition error %d.\n", urb->status);
break;
}
if (atomic_read(&dev->stream_started) == 0)
return;
if (dev->adev.capture_pcm_substream) {
substream = dev->adev.capture_pcm_substream;
runtime = substream->runtime;
stride = runtime->frame_bits >> 3;
for (i = 0; i < urb->number_of_packets; i++) {
int length = urb->iso_frame_desc[i].actual_length /
stride;
cp = (unsigned char *)urb->transfer_buffer +
urb->iso_frame_desc[i].offset;
if (!length)
continue;
oldptr = dev->adev.hwptr_done_capture;
if (oldptr + length >= runtime->buffer_size) {
unsigned int cnt;
cnt = runtime->buffer_size - oldptr;
memcpy(runtime->dma_area + oldptr * stride, cp,
cnt * stride);
memcpy(runtime->dma_area, cp + cnt * stride,
length * stride - cnt * stride);
} else {
memcpy(runtime->dma_area + oldptr * stride, cp,
length * stride);
}
snd_pcm_stream_lock(substream);
dev->adev.hwptr_done_capture += length;
if (dev->adev.hwptr_done_capture >=
runtime->buffer_size)
dev->adev.hwptr_done_capture -=
runtime->buffer_size;
dev->adev.capture_transfer_done += length;
if (dev->adev.capture_transfer_done >=
runtime->period_size) {
dev->adev.capture_transfer_done -=
runtime->period_size;
period_elapsed = 1;
}
snd_pcm_stream_unlock(substream);
}
if (period_elapsed)
snd_pcm_period_elapsed(substream);
}
urb->status = 0;
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
cx231xx_errdev("resubmit of audio urb failed (error=%i)\n",
status);
}
return;
}
static void cx231xx_audio_bulkirq(struct urb *urb)
{
struct cx231xx *dev = urb->context;
unsigned int oldptr;
int period_elapsed = 0;
int status;
unsigned char *cp;
unsigned int stride;
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
if (dev->state & DEV_DISCONNECTED)
return;
switch (urb->status) {
case 0:
case -ETIMEDOUT:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dprintk("urb completition error %d.\n", urb->status);
break;
}
if (atomic_read(&dev->stream_started) == 0)
return;
if (dev->adev.capture_pcm_substream) {
substream = dev->adev.capture_pcm_substream;
runtime = substream->runtime;
stride = runtime->frame_bits >> 3;
if (1) {
int length = urb->actual_length /
stride;
cp = (unsigned char *)urb->transfer_buffer;
oldptr = dev->adev.hwptr_done_capture;
if (oldptr + length >= runtime->buffer_size) {
unsigned int cnt;
cnt = runtime->buffer_size - oldptr;
memcpy(runtime->dma_area + oldptr * stride, cp,
cnt * stride);
memcpy(runtime->dma_area, cp + cnt * stride,
length * stride - cnt * stride);
} else {
memcpy(runtime->dma_area + oldptr * stride, cp,
length * stride);
}
snd_pcm_stream_lock(substream);
dev->adev.hwptr_done_capture += length;
if (dev->adev.hwptr_done_capture >=
runtime->buffer_size)
dev->adev.hwptr_done_capture -=
runtime->buffer_size;
dev->adev.capture_transfer_done += length;
if (dev->adev.capture_transfer_done >=
runtime->period_size) {
dev->adev.capture_transfer_done -=
runtime->period_size;
period_elapsed = 1;
}
snd_pcm_stream_unlock(substream);
}
if (period_elapsed)
snd_pcm_period_elapsed(substream);
}
urb->status = 0;
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
cx231xx_errdev("resubmit of audio urb failed (error=%i)\n",
status);
}
return;
}
static int cx231xx_init_audio_isoc(struct cx231xx *dev)
{
int i, errCode;
int sb_size;
cx231xx_info("%s: Starting ISO AUDIO transfers\n", __func__);
if (dev->state & DEV_DISCONNECTED)
return -ENODEV;
sb_size = CX231XX_ISO_NUM_AUDIO_PACKETS * dev->adev.max_pkt_size;
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
struct urb *urb;
int j, k;
dev->adev.transfer_buffer[i] = kmalloc(sb_size, GFP_ATOMIC);
if (!dev->adev.transfer_buffer[i])
return -ENOMEM;
memset(dev->adev.transfer_buffer[i], 0x80, sb_size);
urb = usb_alloc_urb(CX231XX_ISO_NUM_AUDIO_PACKETS, GFP_ATOMIC);
if (!urb) {
cx231xx_errdev("usb_alloc_urb failed!\n");
for (j = 0; j < i; j++) {
usb_free_urb(dev->adev.urb[j]);
kfree(dev->adev.transfer_buffer[j]);
}
return -ENOMEM;
}
urb->dev = dev->udev;
urb->context = dev;
urb->pipe = usb_rcvisocpipe(dev->udev,
dev->adev.end_point_addr);
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = dev->adev.transfer_buffer[i];
urb->interval = 1;
urb->complete = cx231xx_audio_isocirq;
urb->number_of_packets = CX231XX_ISO_NUM_AUDIO_PACKETS;
urb->transfer_buffer_length = sb_size;
for (j = k = 0; j < CX231XX_ISO_NUM_AUDIO_PACKETS;
j++, k += dev->adev.max_pkt_size) {
urb->iso_frame_desc[j].offset = k;
urb->iso_frame_desc[j].length = dev->adev.max_pkt_size;
}
dev->adev.urb[i] = urb;
}
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
errCode = usb_submit_urb(dev->adev.urb[i], GFP_ATOMIC);
if (errCode < 0) {
cx231xx_isoc_audio_deinit(dev);
return errCode;
}
}
return errCode;
}
static int cx231xx_init_audio_bulk(struct cx231xx *dev)
{
int i, errCode;
int sb_size;
cx231xx_info("%s: Starting BULK AUDIO transfers\n", __func__);
if (dev->state & DEV_DISCONNECTED)
return -ENODEV;
sb_size = CX231XX_NUM_AUDIO_PACKETS * dev->adev.max_pkt_size;
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
struct urb *urb;
int j;
dev->adev.transfer_buffer[i] = kmalloc(sb_size, GFP_ATOMIC);
if (!dev->adev.transfer_buffer[i])
return -ENOMEM;
memset(dev->adev.transfer_buffer[i], 0x80, sb_size);
urb = usb_alloc_urb(CX231XX_NUM_AUDIO_PACKETS, GFP_ATOMIC);
if (!urb) {
cx231xx_errdev("usb_alloc_urb failed!\n");
for (j = 0; j < i; j++) {
usb_free_urb(dev->adev.urb[j]);
kfree(dev->adev.transfer_buffer[j]);
}
return -ENOMEM;
}
urb->dev = dev->udev;
urb->context = dev;
urb->pipe = usb_rcvbulkpipe(dev->udev,
dev->adev.end_point_addr);
urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = dev->adev.transfer_buffer[i];
urb->complete = cx231xx_audio_bulkirq;
urb->transfer_buffer_length = sb_size;
dev->adev.urb[i] = urb;
}
for (i = 0; i < CX231XX_AUDIO_BUFS; i++) {
errCode = usb_submit_urb(dev->adev.urb[i], GFP_ATOMIC);
if (errCode < 0) {
cx231xx_bulk_audio_deinit(dev);
return errCode;
}
}
return errCode;
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
static int snd_cx231xx_capture_open(struct snd_pcm_substream *substream)
{
struct cx231xx *dev = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int ret = 0;
dprintk("opening device and trying to acquire exclusive lock\n");
if (!dev) {
cx231xx_errdev("BUG: cx231xx can't find device struct."
" Can't proceed with open\n");
return -ENODEV;
}
if (dev->state & DEV_DISCONNECTED) {
cx231xx_errdev("Can't open. the device was removed.\n");
return -ENODEV;
}
dev->mute = 0;
mutex_lock(&dev->lock);
if (dev->USE_ISO)
ret = cx231xx_set_alt_setting(dev, INDEX_AUDIO, 1);
else
ret = cx231xx_set_alt_setting(dev, INDEX_AUDIO, 0);
mutex_unlock(&dev->lock);
if (ret < 0) {
cx231xx_errdev("failed to set alternate setting !\n");
return ret;
}
runtime->hw = snd_cx231xx_hw_capture;
mutex_lock(&dev->lock);
ret = cx231xx_capture_start(dev, 1, Audio);
dev->adev.users++;
mutex_unlock(&dev->lock);
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
dev->adev.capture_pcm_substream = substream;
runtime->private_data = dev;
return 0;
}
static int snd_cx231xx_pcm_close(struct snd_pcm_substream *substream)
{
int ret;
struct cx231xx *dev = snd_pcm_substream_chip(substream);
dprintk("closing device\n");
mutex_lock(&dev->lock);
ret = cx231xx_capture_start(dev, 0, Audio);
ret = cx231xx_set_alt_setting(dev, INDEX_AUDIO, 0);
if (ret < 0) {
cx231xx_errdev("failed to set alternate setting !\n");
mutex_unlock(&dev->lock);
return ret;
}
dev->mute = 1;
dev->adev.users--;
mutex_unlock(&dev->lock);
if (dev->adev.users == 0 && dev->adev.shutdown == 1) {
dprintk("audio users: %d\n", dev->adev.users);
dprintk("disabling audio stream!\n");
dev->adev.shutdown = 0;
dprintk("released lock\n");
if (atomic_read(&dev->stream_started) > 0) {
atomic_set(&dev->stream_started, 0);
schedule_work(&dev->wq_trigger);
}
}
return 0;
}
static int snd_cx231xx_hw_capture_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
unsigned int channels, rate, format;
int ret;
dprintk("Setting capture parameters\n");
ret = snd_pcm_alloc_vmalloc_buffer(substream,
params_buffer_bytes(hw_params));
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
return 0;
}
static int snd_cx231xx_hw_capture_free(struct snd_pcm_substream *substream)
{
struct cx231xx *dev = snd_pcm_substream_chip(substream);
dprintk("Stop capture, if needed\n");
if (atomic_read(&dev->stream_started) > 0) {
atomic_set(&dev->stream_started, 0);
schedule_work(&dev->wq_trigger);
}
return 0;
}
static int snd_cx231xx_prepare(struct snd_pcm_substream *substream)
{
struct cx231xx *dev = snd_pcm_substream_chip(substream);
dev->adev.hwptr_done_capture = 0;
dev->adev.capture_transfer_done = 0;
return 0;
}
static void audio_trigger(struct work_struct *work)
{
struct cx231xx *dev = container_of(work, struct cx231xx, wq_trigger);
if (atomic_read(&dev->stream_started)) {
dprintk("starting capture");
if (is_fw_load(dev) == 0)
cx25840_call(dev, core, load_fw);
if (dev->USE_ISO)
cx231xx_init_audio_isoc(dev);
else
cx231xx_init_audio_bulk(dev);
} else {
dprintk("stopping capture");
cx231xx_isoc_audio_deinit(dev);
}
}
static int snd_cx231xx_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct cx231xx *dev = snd_pcm_substream_chip(substream);
int retval;
if (dev->state & DEV_DISCONNECTED)
return -ENODEV;
spin_lock(&dev->adev.slock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
atomic_set(&dev->stream_started, 1);
break;
case SNDRV_PCM_TRIGGER_STOP:
atomic_set(&dev->stream_started, 0);
break;
default:
retval = -EINVAL;
}
spin_unlock(&dev->adev.slock);
schedule_work(&dev->wq_trigger);
return 0;
}
static snd_pcm_uframes_t snd_cx231xx_capture_pointer(struct snd_pcm_substream
*substream)
{
struct cx231xx *dev;
unsigned long flags;
snd_pcm_uframes_t hwptr_done;
dev = snd_pcm_substream_chip(substream);
spin_lock_irqsave(&dev->adev.slock, flags);
hwptr_done = dev->adev.hwptr_done_capture;
spin_unlock_irqrestore(&dev->adev.slock, flags);
return hwptr_done;
}
static struct page *snd_pcm_get_vmalloc_page(struct snd_pcm_substream *subs,
unsigned long offset)
{
void *pageptr = subs->runtime->dma_area + offset;
return vmalloc_to_page(pageptr);
}
static int cx231xx_audio_init(struct cx231xx *dev)
{
struct cx231xx_audio *adev = &dev->adev;
struct snd_pcm *pcm;
struct snd_card *card;
static int devnr;
int err;
struct usb_interface *uif;
int i, isoc_pipe = 0;
if (dev->has_alsa_audio != 1) {
return 0;
}
cx231xx_info("cx231xx-audio.c: probing for cx231xx "
"non standard usbaudio\n");
err = snd_card_create(index[devnr], "Cx231xx Audio", THIS_MODULE,
0, &card);
if (err < 0)
return err;
spin_lock_init(&adev->slock);
err = snd_pcm_new(card, "Cx231xx Audio", 0, 0, 1, &pcm);
if (err < 0) {
snd_card_free(card);
return err;
}
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_cx231xx_pcm_capture);
pcm->info_flags = 0;
pcm->private_data = dev;
strcpy(pcm->name, "Conexant cx231xx Capture");
snd_card_set_dev(card, &dev->udev->dev);
strcpy(card->driver, "Cx231xx-Audio");
strcpy(card->shortname, "Cx231xx Audio");
strcpy(card->longname, "Conexant cx231xx Audio");
INIT_WORK(&dev->wq_trigger, audio_trigger);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
adev->sndcard = card;
adev->udev = dev->udev;
uif =
dev->udev->actconfig->interface[dev->current_pcb_config.
hs_config_info[0].interface_info.
audio_index + 1];
adev->end_point_addr =
le16_to_cpu(uif->altsetting[0].endpoint[isoc_pipe].desc.
bEndpointAddress);
adev->num_alt = uif->num_altsetting;
cx231xx_info("EndPoint Addr 0x%x, Alternate settings: %i\n",
adev->end_point_addr, adev->num_alt);
adev->alt_max_pkt_size = kmalloc(32 * adev->num_alt, GFP_KERNEL);
if (adev->alt_max_pkt_size == NULL) {
cx231xx_errdev("out of memory!\n");
return -ENOMEM;
}
for (i = 0; i < adev->num_alt; i++) {
u16 tmp =
le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].desc.
wMaxPacketSize);
adev->alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
cx231xx_info("Alternate setting %i, max size= %i\n", i,
adev->alt_max_pkt_size[i]);
}
return 0;
}
static int cx231xx_audio_fini(struct cx231xx *dev)
{
if (dev == NULL)
return 0;
if (dev->has_alsa_audio != 1) {
return 0;
}
if (dev->adev.sndcard) {
snd_card_free(dev->adev.sndcard);
kfree(dev->adev.alt_max_pkt_size);
dev->adev.sndcard = NULL;
}
return 0;
}
static int __init cx231xx_alsa_register(void)
{
return cx231xx_register_extension(&audio_ops);
}
static void __exit cx231xx_alsa_unregister(void)
{
cx231xx_unregister_extension(&audio_ops);
}
