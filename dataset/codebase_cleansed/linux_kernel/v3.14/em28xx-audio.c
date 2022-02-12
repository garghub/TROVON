static int em28xx_deinit_isoc_audio(struct em28xx *dev)
{
int i;
dprintk("Stopping isoc\n");
for (i = 0; i < dev->adev.num_urb; i++) {
struct urb *urb = dev->adev.urb[i];
if (!irqs_disabled())
usb_kill_urb(urb);
else
usb_unlink_urb(urb);
}
return 0;
}
static void em28xx_audio_isocirq(struct urb *urb)
{
struct em28xx *dev = urb->context;
int i;
unsigned int oldptr;
int period_elapsed = 0;
int status;
unsigned char *cp;
unsigned int stride;
struct snd_pcm_substream *substream;
struct snd_pcm_runtime *runtime;
if (dev->disconnected) {
dprintk("device disconnected while streaming. URB status=%d.\n", urb->status);
atomic_set(&dev->stream_started, 0);
return;
}
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
int length =
urb->iso_frame_desc[i].actual_length / stride;
cp = (unsigned char *)urb->transfer_buffer +
urb->iso_frame_desc[i].offset;
if (!length)
continue;
oldptr = dev->adev.hwptr_done_capture;
if (oldptr + length >= runtime->buffer_size) {
unsigned int cnt =
runtime->buffer_size - oldptr;
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
if (status < 0)
em28xx_errdev("resubmit of audio urb failed (error=%i)\n",
status);
return;
}
static int em28xx_init_audio_isoc(struct em28xx *dev)
{
int i, errCode;
dprintk("Starting isoc transfers\n");
for (i = 0; i < dev->adev.num_urb; i++) {
memset(dev->adev.transfer_buffer[i], 0x80,
dev->adev.urb[i]->transfer_buffer_length);
errCode = usb_submit_urb(dev->adev.urb[i], GFP_ATOMIC);
if (errCode) {
em28xx_errdev("submit of audio urb failed (error=%i)\n",
errCode);
em28xx_deinit_isoc_audio(dev);
atomic_set(&dev->stream_started, 0);
return errCode;
}
}
return 0;
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
static int snd_em28xx_capture_open(struct snd_pcm_substream *substream)
{
struct em28xx *dev = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int ret = 0;
if (!dev) {
em28xx_err("BUG: em28xx can't find device struct."
" Can't proceed with open\n");
return -ENODEV;
}
if (dev->disconnected)
return -ENODEV;
dprintk("opening device and trying to acquire exclusive lock\n");
runtime->hw = snd_em28xx_hw_capture;
if ((dev->alt == 0 || dev->is_audio_only) && dev->adev.users == 0) {
int nonblock = !!(substream->f_flags & O_NONBLOCK);
if (nonblock) {
if (!mutex_trylock(&dev->lock))
return -EAGAIN;
} else
mutex_lock(&dev->lock);
if (dev->is_audio_only)
dev->alt = 1;
else
dev->alt = 7;
dprintk("changing alternate number on interface %d to %d\n",
dev->ifnum, dev->alt);
usb_set_interface(dev->udev, dev->ifnum, dev->alt);
dev->mute = 0;
ret = em28xx_audio_analog_set(dev);
if (ret < 0)
goto err;
dev->adev.users++;
mutex_unlock(&dev->lock);
}
snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
dev->adev.period * 95 / 100,
dev->adev.period * 105 / 100);
dev->adev.capture_pcm_substream = substream;
return 0;
err:
mutex_unlock(&dev->lock);
em28xx_err("Error while configuring em28xx mixer\n");
return ret;
}
static int snd_em28xx_pcm_close(struct snd_pcm_substream *substream)
{
struct em28xx *dev = snd_pcm_substream_chip(substream);
dprintk("closing device\n");
dev->mute = 1;
mutex_lock(&dev->lock);
dev->adev.users--;
if (atomic_read(&dev->stream_started) > 0) {
atomic_set(&dev->stream_started, 0);
schedule_work(&dev->wq_trigger);
}
em28xx_audio_analog_set(dev);
if (substream->runtime->dma_area) {
dprintk("freeing\n");
vfree(substream->runtime->dma_area);
substream->runtime->dma_area = NULL;
}
mutex_unlock(&dev->lock);
return 0;
}
static int snd_em28xx_hw_capture_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
int ret;
struct em28xx *dev = snd_pcm_substream_chip(substream);
if (dev->disconnected)
return -ENODEV;
dprintk("Setting capture parameters\n");
ret = snd_pcm_alloc_vmalloc_buffer(substream,
params_buffer_bytes(hw_params));
if (ret < 0)
return ret;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return 0;
}
static int snd_em28xx_hw_capture_free(struct snd_pcm_substream *substream)
{
struct em28xx *dev = snd_pcm_substream_chip(substream);
dprintk("Stop capture, if needed\n");
if (atomic_read(&dev->stream_started) > 0) {
atomic_set(&dev->stream_started, 0);
schedule_work(&dev->wq_trigger);
}
return 0;
}
static int snd_em28xx_prepare(struct snd_pcm_substream *substream)
{
struct em28xx *dev = snd_pcm_substream_chip(substream);
if (dev->disconnected)
return -ENODEV;
dev->adev.hwptr_done_capture = 0;
dev->adev.capture_transfer_done = 0;
return 0;
}
static void audio_trigger(struct work_struct *work)
{
struct em28xx *dev = container_of(work, struct em28xx, wq_trigger);
if (atomic_read(&dev->stream_started)) {
dprintk("starting capture");
em28xx_init_audio_isoc(dev);
} else {
dprintk("stopping capture");
em28xx_deinit_isoc_audio(dev);
}
}
static int snd_em28xx_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct em28xx *dev = snd_pcm_substream_chip(substream);
int retval = 0;
if (dev->disconnected)
return -ENODEV;
switch (cmd) {
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_START:
atomic_set(&dev->stream_started, 1);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_STOP:
atomic_set(&dev->stream_started, 0);
break;
default:
retval = -EINVAL;
}
schedule_work(&dev->wq_trigger);
return retval;
}
static snd_pcm_uframes_t snd_em28xx_capture_pointer(struct snd_pcm_substream
*substream)
{
unsigned long flags;
struct em28xx *dev;
snd_pcm_uframes_t hwptr_done;
dev = snd_pcm_substream_chip(substream);
if (dev->disconnected)
return SNDRV_PCM_POS_XRUN;
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
static int em28xx_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *info)
{
struct em28xx *dev = snd_kcontrol_chip(kcontrol);
if (dev->disconnected)
return -ENODEV;
info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
info->count = 2;
info->value.integer.min = 0;
info->value.integer.max = 0x1f;
return 0;
}
static int em28xx_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct em28xx *dev = snd_kcontrol_chip(kcontrol);
struct snd_pcm_substream *substream = dev->adev.capture_pcm_substream;
u16 val = (0x1f - (value->value.integer.value[0] & 0x1f)) |
(0x1f - (value->value.integer.value[1] & 0x1f)) << 8;
int nonblock = 0;
int rc;
if (dev->disconnected)
return -ENODEV;
if (substream)
nonblock = !!(substream->f_flags & O_NONBLOCK);
if (nonblock) {
if (!mutex_trylock(&dev->lock))
return -EAGAIN;
} else
mutex_lock(&dev->lock);
rc = em28xx_read_ac97(dev, kcontrol->private_value);
if (rc < 0)
goto err;
val |= rc & 0x8000;
rc = em28xx_write_ac97(dev, kcontrol->private_value, val);
if (rc < 0)
goto err;
dprintk("%sleft vol %d, right vol %d (0x%04x) to ac97 volume control 0x%04x\n",
(val & 0x8000) ? "muted " : "",
0x1f - ((val >> 8) & 0x1f), 0x1f - (val & 0x1f),
val, (int)kcontrol->private_value);
err:
mutex_unlock(&dev->lock);
return rc;
}
static int em28xx_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct em28xx *dev = snd_kcontrol_chip(kcontrol);
struct snd_pcm_substream *substream = dev->adev.capture_pcm_substream;
int nonblock = 0;
int val;
if (dev->disconnected)
return -ENODEV;
if (substream)
nonblock = !!(substream->f_flags & O_NONBLOCK);
if (nonblock) {
if (!mutex_trylock(&dev->lock))
return -EAGAIN;
} else
mutex_lock(&dev->lock);
val = em28xx_read_ac97(dev, kcontrol->private_value);
mutex_unlock(&dev->lock);
if (val < 0)
return val;
dprintk("%sleft vol %d, right vol %d (0x%04x) from ac97 volume control 0x%04x\n",
(val & 0x8000) ? "muted " : "",
0x1f - ((val >> 8) & 0x1f), 0x1f - (val & 0x1f),
val, (int)kcontrol->private_value);
value->value.integer.value[0] = 0x1f - (val & 0x1f);
value->value.integer.value[1] = 0x1f - ((val << 8) & 0x1f);
return 0;
}
static int em28xx_vol_put_mute(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct em28xx *dev = snd_kcontrol_chip(kcontrol);
u16 val = value->value.integer.value[0];
struct snd_pcm_substream *substream = dev->adev.capture_pcm_substream;
int nonblock = 0;
int rc;
if (dev->disconnected)
return -ENODEV;
if (substream)
nonblock = !!(substream->f_flags & O_NONBLOCK);
if (nonblock) {
if (!mutex_trylock(&dev->lock))
return -EAGAIN;
} else
mutex_lock(&dev->lock);
rc = em28xx_read_ac97(dev, kcontrol->private_value);
if (rc < 0)
goto err;
if (val)
rc &= 0x1f1f;
else
rc |= 0x8000;
rc = em28xx_write_ac97(dev, kcontrol->private_value, rc);
if (rc < 0)
goto err;
dprintk("%sleft vol %d, right vol %d (0x%04x) to ac97 volume control 0x%04x\n",
(val & 0x8000) ? "muted " : "",
0x1f - ((val >> 8) & 0x1f), 0x1f - (val & 0x1f),
val, (int)kcontrol->private_value);
err:
mutex_unlock(&dev->lock);
return rc;
}
static int em28xx_vol_get_mute(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct em28xx *dev = snd_kcontrol_chip(kcontrol);
struct snd_pcm_substream *substream = dev->adev.capture_pcm_substream;
int nonblock = 0;
int val;
if (dev->disconnected)
return -ENODEV;
if (substream)
nonblock = !!(substream->f_flags & O_NONBLOCK);
if (nonblock) {
if (!mutex_trylock(&dev->lock))
return -EAGAIN;
} else
mutex_lock(&dev->lock);
val = em28xx_read_ac97(dev, kcontrol->private_value);
mutex_unlock(&dev->lock);
if (val < 0)
return val;
if (val & 0x8000)
value->value.integer.value[0] = 0;
else
value->value.integer.value[0] = 1;
dprintk("%sleft vol %d, right vol %d (0x%04x) from ac97 volume control 0x%04x\n",
(val & 0x8000) ? "muted " : "",
0x1f - ((val >> 8) & 0x1f), 0x1f - (val & 0x1f),
val, (int)kcontrol->private_value);
return 0;
}
static int em28xx_cvol_new(struct snd_card *card, struct em28xx *dev,
char *name, int id)
{
int err;
char ctl_name[44];
struct snd_kcontrol *kctl;
struct snd_kcontrol_new tmp;
memset (&tmp, 0, sizeof(tmp));
tmp.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
tmp.private_value = id,
tmp.name = ctl_name,
sprintf(ctl_name, "%s Switch", name);
tmp.get = em28xx_vol_get_mute;
tmp.put = em28xx_vol_put_mute;
tmp.info = snd_ctl_boolean_mono_info;
kctl = snd_ctl_new1(&tmp, dev);
err = snd_ctl_add(card, kctl);
if (err < 0)
return err;
dprintk("Added control %s for ac97 volume control 0x%04x\n",
ctl_name, id);
memset (&tmp, 0, sizeof(tmp));
tmp.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
tmp.private_value = id,
tmp.name = ctl_name,
sprintf(ctl_name, "%s Volume", name);
tmp.get = em28xx_vol_get;
tmp.put = em28xx_vol_put;
tmp.info = em28xx_vol_info;
tmp.tlv.p = em28xx_db_scale,
kctl = snd_ctl_new1(&tmp, dev);
err = snd_ctl_add(card, kctl);
if (err < 0)
return err;
dprintk("Added control %s for ac97 volume control 0x%04x\n",
ctl_name, id);
return 0;
}
static void em28xx_audio_free_urb(struct em28xx *dev)
{
int i;
for (i = 0; i < dev->adev.num_urb; i++) {
struct urb *urb = dev->adev.urb[i];
if (!urb)
continue;
usb_free_coherent(dev->udev, urb->transfer_buffer_length,
dev->adev.transfer_buffer[i],
urb->transfer_dma);
usb_free_urb(urb);
}
kfree(dev->adev.urb);
kfree(dev->adev.transfer_buffer);
dev->adev.num_urb = 0;
}
static int em28xx_audio_ep_packet_size(struct usb_device *udev,
struct usb_endpoint_descriptor *e)
{
int size = le16_to_cpu(e->wMaxPacketSize);
if (udev->speed == USB_SPEED_HIGH)
return (size & 0x7ff) * (1 + (((size) >> 11) & 0x03));
return size & 0x7ff;
}
static int em28xx_audio_urb_init(struct em28xx *dev)
{
struct usb_interface *intf;
struct usb_endpoint_descriptor *e, *ep = NULL;
int i, ep_size, interval, num_urb, npackets;
int urb_size, bytes_per_transfer;
u8 alt;
if (dev->ifnum)
alt = 1;
else
alt = 7;
intf = usb_ifnum_to_if(dev->udev, dev->ifnum);
if (intf->num_altsetting <= alt) {
em28xx_errdev("alt %d doesn't exist on interface %d\n",
dev->ifnum, alt);
return -ENODEV;
}
for (i = 0; i < intf->altsetting[alt].desc.bNumEndpoints; i++) {
e = &intf->altsetting[alt].endpoint[i].desc;
if (!usb_endpoint_dir_in(e))
continue;
if (e->bEndpointAddress == EM28XX_EP_AUDIO) {
ep = e;
break;
}
}
if (!ep) {
em28xx_errdev("Couldn't find an audio endpoint");
return -ENODEV;
}
ep_size = em28xx_audio_ep_packet_size(dev->udev, ep);
interval = 1 << (ep->bInterval - 1);
em28xx_info("Endpoint 0x%02x %s on intf %d alt %d interval = %d, size %d\n",
EM28XX_EP_AUDIO, usb_speed_string(dev->udev->speed),
dev->ifnum, alt,
interval,
ep_size);
bytes_per_transfer = DIV_ROUND_UP(48000 * 2 * 2, 125 * interval);
num_urb = DIV_ROUND_UP(bytes_per_transfer, ep_size);
if (num_urb > EM28XX_MAX_AUDIO_BUFS)
num_urb = EM28XX_MAX_AUDIO_BUFS;
urb_size = bytes_per_transfer / num_urb;
npackets = EM28XX_MIN_AUDIO_PACKETS;
if (urb_size > ep_size * npackets)
npackets = DIV_ROUND_UP(urb_size, ep_size);
em28xx_info("Number of URBs: %d, with %d packets and %d size",
num_urb, npackets, urb_size);
dev->adev.period = urb_size * npackets;
dev->adev.transfer_buffer = kcalloc(num_urb,
sizeof(*dev->adev.transfer_buffer),
GFP_ATOMIC);
if (!dev->adev.transfer_buffer) {
return -ENOMEM;
}
dev->adev.urb = kcalloc(num_urb, sizeof(*dev->adev.urb), GFP_ATOMIC);
if (!dev->adev.urb) {
kfree(dev->adev.transfer_buffer);
return -ENOMEM;
}
dev->adev.num_urb = num_urb;
for (i = 0; i < num_urb; i++) {
struct urb *urb;
int j, k;
void *buf;
urb = usb_alloc_urb(npackets, GFP_ATOMIC);
if (!urb) {
em28xx_errdev("usb_alloc_urb failed!\n");
em28xx_audio_free_urb(dev);
return -ENOMEM;
}
dev->adev.urb[i] = urb;
buf = usb_alloc_coherent(dev->udev, npackets * ep_size, GFP_ATOMIC,
&urb->transfer_dma);
if (!buf) {
em28xx_errdev("usb_alloc_coherent failed!\n");
em28xx_audio_free_urb(dev);
return -ENOMEM;
}
dev->adev.transfer_buffer[i] = buf;
urb->dev = dev->udev;
urb->context = dev;
urb->pipe = usb_rcvisocpipe(dev->udev, EM28XX_EP_AUDIO);
urb->transfer_flags = URB_ISO_ASAP | URB_NO_TRANSFER_DMA_MAP;
urb->transfer_buffer = buf;
urb->interval = interval;
urb->complete = em28xx_audio_isocirq;
urb->number_of_packets = npackets;
urb->transfer_buffer_length = ep_size * npackets;
for (j = k = 0; j < npackets; j++, k += ep_size) {
urb->iso_frame_desc[j].offset = k;
urb->iso_frame_desc[j].length = ep_size;
}
}
return 0;
}
static int em28xx_audio_init(struct em28xx *dev)
{
struct em28xx_audio *adev = &dev->adev;
struct snd_pcm *pcm;
struct snd_card *card;
static int devnr;
int err;
if (!dev->has_alsa_audio) {
return 0;
}
em28xx_info("Binding audio extension\n");
printk(KERN_INFO "em28xx-audio.c: Copyright (C) 2006 Markus "
"Rechberger\n");
printk(KERN_INFO
"em28xx-audio.c: Copyright (C) 2007-2014 Mauro Carvalho Chehab\n");
err = snd_card_create(index[devnr], "Em28xx Audio", THIS_MODULE, 0,
&card);
if (err < 0)
return err;
spin_lock_init(&adev->slock);
adev->sndcard = card;
adev->udev = dev->udev;
err = snd_pcm_new(card, "Em28xx Audio", 0, 0, 1, &pcm);
if (err < 0)
goto card_free;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_em28xx_pcm_capture);
pcm->info_flags = 0;
pcm->private_data = dev;
strcpy(pcm->name, "Empia 28xx Capture");
snd_card_set_dev(card, &dev->udev->dev);
strcpy(card->driver, "Em28xx-Audio");
strcpy(card->shortname, "Em28xx Audio");
strcpy(card->longname, "Empia Em28xx Audio");
INIT_WORK(&dev->wq_trigger, audio_trigger);
if (dev->audio_mode.ac97 != EM28XX_NO_AC97) {
em28xx_cvol_new(card, dev, "Video", AC97_VIDEO);
em28xx_cvol_new(card, dev, "Line In", AC97_LINE);
em28xx_cvol_new(card, dev, "Phone", AC97_PHONE);
em28xx_cvol_new(card, dev, "Microphone", AC97_MIC);
em28xx_cvol_new(card, dev, "CD", AC97_CD);
em28xx_cvol_new(card, dev, "AUX", AC97_AUX);
em28xx_cvol_new(card, dev, "PCM", AC97_PCM);
em28xx_cvol_new(card, dev, "Master", AC97_MASTER);
em28xx_cvol_new(card, dev, "Line", AC97_HEADPHONE);
em28xx_cvol_new(card, dev, "Mono", AC97_MASTER_MONO);
em28xx_cvol_new(card, dev, "LFE", AC97_CENTER_LFE_MASTER);
em28xx_cvol_new(card, dev, "Surround", AC97_SURROUND_MASTER);
}
err = em28xx_audio_urb_init(dev);
if (err)
goto card_free;
err = snd_card_register(card);
if (err < 0)
goto urb_free;
em28xx_info("Audio extension successfully initialized\n");
return 0;
urb_free:
em28xx_audio_free_urb(dev);
card_free:
snd_card_free(card);
adev->sndcard = NULL;
return err;
}
static int em28xx_audio_fini(struct em28xx *dev)
{
if (dev == NULL)
return 0;
if (dev->has_alsa_audio != 1) {
return 0;
}
em28xx_info("Closing audio extension");
if (dev->adev.sndcard) {
snd_card_disconnect(dev->adev.sndcard);
flush_work(&dev->wq_trigger);
em28xx_audio_free_urb(dev);
snd_card_free(dev->adev.sndcard);
dev->adev.sndcard = NULL;
}
return 0;
}
static int __init em28xx_alsa_register(void)
{
return em28xx_register_extension(&audio_ops);
}
static void __exit em28xx_alsa_unregister(void)
{
em28xx_unregister_extension(&audio_ops);
}
