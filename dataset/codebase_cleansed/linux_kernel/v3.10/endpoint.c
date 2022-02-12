static inline unsigned get_usb_full_speed_rate(unsigned int rate)
{
return ((rate << 13) + 62) / 125;
}
static inline unsigned get_usb_high_speed_rate(unsigned int rate)
{
return ((rate << 10) + 62) / 125;
}
static void release_urb_ctx(struct snd_urb_ctx *u)
{
if (u->buffer_size)
usb_free_coherent(u->ep->chip->dev, u->buffer_size,
u->urb->transfer_buffer,
u->urb->transfer_dma);
usb_free_urb(u->urb);
u->urb = NULL;
}
static const char *usb_error_string(int err)
{
switch (err) {
case -ENODEV:
return "no device";
case -ENOENT:
return "endpoint not enabled";
case -EPIPE:
return "endpoint stalled";
case -ENOSPC:
return "not enough bandwidth";
case -ESHUTDOWN:
return "device disabled";
case -EHOSTUNREACH:
return "device suspended";
case -EINVAL:
case -EAGAIN:
case -EFBIG:
case -EMSGSIZE:
return "internal error";
default:
return "unknown error";
}
}
int snd_usb_endpoint_implicit_feedback_sink(struct snd_usb_endpoint *ep)
{
return ep->sync_master &&
ep->sync_master->type == SND_USB_ENDPOINT_TYPE_DATA &&
ep->type == SND_USB_ENDPOINT_TYPE_DATA &&
usb_pipeout(ep->pipe);
}
int snd_usb_endpoint_next_packet_size(struct snd_usb_endpoint *ep)
{
unsigned long flags;
int ret;
if (ep->fill_max)
return ep->maxframesize;
spin_lock_irqsave(&ep->lock, flags);
ep->phase = (ep->phase & 0xffff)
+ (ep->freqm << ep->datainterval);
ret = min(ep->phase >> 16, ep->maxframesize);
spin_unlock_irqrestore(&ep->lock, flags);
return ret;
}
static void retire_outbound_urb(struct snd_usb_endpoint *ep,
struct snd_urb_ctx *urb_ctx)
{
if (ep->retire_data_urb)
ep->retire_data_urb(ep->data_subs, urb_ctx->urb);
}
static void retire_inbound_urb(struct snd_usb_endpoint *ep,
struct snd_urb_ctx *urb_ctx)
{
struct urb *urb = urb_ctx->urb;
if (unlikely(ep->skip_packets > 0)) {
ep->skip_packets--;
return;
}
if (ep->sync_slave)
snd_usb_handle_sync_urb(ep->sync_slave, ep, urb);
if (ep->retire_data_urb)
ep->retire_data_urb(ep->data_subs, urb);
}
static void prepare_outbound_urb(struct snd_usb_endpoint *ep,
struct snd_urb_ctx *ctx)
{
int i;
struct urb *urb = ctx->urb;
unsigned char *cp = urb->transfer_buffer;
urb->dev = ep->chip->dev;
switch (ep->type) {
case SND_USB_ENDPOINT_TYPE_DATA:
if (ep->prepare_data_urb) {
ep->prepare_data_urb(ep->data_subs, urb);
} else {
unsigned int offs = 0;
for (i = 0; i < ctx->packets; ++i) {
int counts;
if (ctx->packet_size[i])
counts = ctx->packet_size[i];
else
counts = snd_usb_endpoint_next_packet_size(ep);
urb->iso_frame_desc[i].offset = offs * ep->stride;
urb->iso_frame_desc[i].length = counts * ep->stride;
offs += counts;
}
urb->number_of_packets = ctx->packets;
urb->transfer_buffer_length = offs * ep->stride;
memset(urb->transfer_buffer, ep->silence_value,
offs * ep->stride);
}
break;
case SND_USB_ENDPOINT_TYPE_SYNC:
if (snd_usb_get_speed(ep->chip->dev) >= USB_SPEED_HIGH) {
urb->iso_frame_desc[0].length = 4;
urb->iso_frame_desc[0].offset = 0;
cp[0] = ep->freqn;
cp[1] = ep->freqn >> 8;
cp[2] = ep->freqn >> 16;
cp[3] = ep->freqn >> 24;
} else {
urb->iso_frame_desc[0].length = 3;
urb->iso_frame_desc[0].offset = 0;
cp[0] = ep->freqn >> 2;
cp[1] = ep->freqn >> 10;
cp[2] = ep->freqn >> 18;
}
break;
}
}
static inline void prepare_inbound_urb(struct snd_usb_endpoint *ep,
struct snd_urb_ctx *urb_ctx)
{
int i, offs;
struct urb *urb = urb_ctx->urb;
urb->dev = ep->chip->dev;
switch (ep->type) {
case SND_USB_ENDPOINT_TYPE_DATA:
offs = 0;
for (i = 0; i < urb_ctx->packets; i++) {
urb->iso_frame_desc[i].offset = offs;
urb->iso_frame_desc[i].length = ep->curpacksize;
offs += ep->curpacksize;
}
urb->transfer_buffer_length = offs;
urb->number_of_packets = urb_ctx->packets;
break;
case SND_USB_ENDPOINT_TYPE_SYNC:
urb->iso_frame_desc[0].length = min(4u, ep->syncmaxsize);
urb->iso_frame_desc[0].offset = 0;
break;
}
}
static void queue_pending_output_urbs(struct snd_usb_endpoint *ep)
{
while (test_bit(EP_FLAG_RUNNING, &ep->flags)) {
unsigned long flags;
struct snd_usb_packet_info *uninitialized_var(packet);
struct snd_urb_ctx *ctx = NULL;
struct urb *urb;
int err, i;
spin_lock_irqsave(&ep->lock, flags);
if (ep->next_packet_read_pos != ep->next_packet_write_pos) {
packet = ep->next_packet + ep->next_packet_read_pos;
ep->next_packet_read_pos++;
ep->next_packet_read_pos %= MAX_URBS;
if (!list_empty(&ep->ready_playback_urbs))
ctx = list_first_entry(&ep->ready_playback_urbs,
struct snd_urb_ctx, ready_list);
}
spin_unlock_irqrestore(&ep->lock, flags);
if (ctx == NULL)
return;
list_del_init(&ctx->ready_list);
urb = ctx->urb;
for (i = 0; i < packet->packets; i++)
ctx->packet_size[i] = packet->packet_size[i];
prepare_outbound_urb(ep, ctx);
err = usb_submit_urb(ctx->urb, GFP_ATOMIC);
if (err < 0)
snd_printk(KERN_ERR "Unable to submit urb #%d: %d (urb %p)\n",
ctx->index, err, ctx->urb);
else
set_bit(ctx->index, &ep->active_mask);
}
}
static void snd_complete_urb(struct urb *urb)
{
struct snd_urb_ctx *ctx = urb->context;
struct snd_usb_endpoint *ep = ctx->ep;
int err;
if (unlikely(urb->status == -ENOENT ||
urb->status == -ENODEV ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN ||
ep->chip->shutdown))
goto exit_clear;
if (usb_pipeout(ep->pipe)) {
retire_outbound_urb(ep, ctx);
if (unlikely(!test_bit(EP_FLAG_RUNNING, &ep->flags)))
goto exit_clear;
if (snd_usb_endpoint_implicit_feedback_sink(ep)) {
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
list_add_tail(&ctx->ready_list, &ep->ready_playback_urbs);
spin_unlock_irqrestore(&ep->lock, flags);
queue_pending_output_urbs(ep);
goto exit_clear;
}
prepare_outbound_urb(ep, ctx);
} else {
retire_inbound_urb(ep, ctx);
if (unlikely(!test_bit(EP_FLAG_RUNNING, &ep->flags)))
goto exit_clear;
prepare_inbound_urb(ep, ctx);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err == 0)
return;
snd_printk(KERN_ERR "cannot submit urb (err = %d)\n", err);
exit_clear:
clear_bit(ctx->index, &ep->active_mask);
}
struct snd_usb_endpoint *snd_usb_add_endpoint(struct snd_usb_audio *chip,
struct usb_host_interface *alts,
int ep_num, int direction, int type)
{
struct snd_usb_endpoint *ep;
int is_playback = direction == SNDRV_PCM_STREAM_PLAYBACK;
mutex_lock(&chip->mutex);
list_for_each_entry(ep, &chip->ep_list, list) {
if (ep->ep_num == ep_num &&
ep->iface == alts->desc.bInterfaceNumber &&
ep->alt_idx == alts->desc.bAlternateSetting) {
snd_printdd(KERN_DEBUG "Re-using EP %x in iface %d,%d @%p\n",
ep_num, ep->iface, ep->alt_idx, ep);
goto __exit_unlock;
}
}
snd_printdd(KERN_DEBUG "Creating new %s %s endpoint #%x\n",
is_playback ? "playback" : "capture",
type == SND_USB_ENDPOINT_TYPE_DATA ? "data" : "sync",
ep_num);
ep = kzalloc(sizeof(*ep), GFP_KERNEL);
if (!ep)
goto __exit_unlock;
ep->chip = chip;
spin_lock_init(&ep->lock);
ep->type = type;
ep->ep_num = ep_num;
ep->iface = alts->desc.bInterfaceNumber;
ep->alt_idx = alts->desc.bAlternateSetting;
INIT_LIST_HEAD(&ep->ready_playback_urbs);
ep_num &= USB_ENDPOINT_NUMBER_MASK;
if (is_playback)
ep->pipe = usb_sndisocpipe(chip->dev, ep_num);
else
ep->pipe = usb_rcvisocpipe(chip->dev, ep_num);
if (type == SND_USB_ENDPOINT_TYPE_SYNC) {
if (get_endpoint(alts, 1)->bLength >= USB_DT_ENDPOINT_AUDIO_SIZE &&
get_endpoint(alts, 1)->bRefresh >= 1 &&
get_endpoint(alts, 1)->bRefresh <= 9)
ep->syncinterval = get_endpoint(alts, 1)->bRefresh;
else if (snd_usb_get_speed(chip->dev) == USB_SPEED_FULL)
ep->syncinterval = 1;
else if (get_endpoint(alts, 1)->bInterval >= 1 &&
get_endpoint(alts, 1)->bInterval <= 16)
ep->syncinterval = get_endpoint(alts, 1)->bInterval - 1;
else
ep->syncinterval = 3;
ep->syncmaxsize = le16_to_cpu(get_endpoint(alts, 1)->wMaxPacketSize);
}
list_add_tail(&ep->list, &chip->ep_list);
__exit_unlock:
mutex_unlock(&chip->mutex);
return ep;
}
static int wait_clear_urbs(struct snd_usb_endpoint *ep)
{
unsigned long end_time = jiffies + msecs_to_jiffies(1000);
int alive;
do {
alive = bitmap_weight(&ep->active_mask, ep->nurbs);
if (!alive)
break;
schedule_timeout_uninterruptible(1);
} while (time_before(jiffies, end_time));
if (alive)
snd_printk(KERN_ERR "timeout: still %d active urbs on EP #%x\n",
alive, ep->ep_num);
clear_bit(EP_FLAG_STOPPING, &ep->flags);
return 0;
}
void snd_usb_endpoint_sync_pending_stop(struct snd_usb_endpoint *ep)
{
if (ep && test_bit(EP_FLAG_STOPPING, &ep->flags))
wait_clear_urbs(ep);
}
static int deactivate_urbs(struct snd_usb_endpoint *ep, bool force)
{
unsigned int i;
if (!force && ep->chip->shutdown)
return -EBADFD;
clear_bit(EP_FLAG_RUNNING, &ep->flags);
INIT_LIST_HEAD(&ep->ready_playback_urbs);
ep->next_packet_read_pos = 0;
ep->next_packet_write_pos = 0;
for (i = 0; i < ep->nurbs; i++) {
if (test_bit(i, &ep->active_mask)) {
if (!test_and_set_bit(i, &ep->unlink_mask)) {
struct urb *u = ep->urb[i].urb;
usb_unlink_urb(u);
}
}
}
return 0;
}
static void release_urbs(struct snd_usb_endpoint *ep, int force)
{
int i;
ep->retire_data_urb = NULL;
ep->prepare_data_urb = NULL;
deactivate_urbs(ep, force);
wait_clear_urbs(ep);
for (i = 0; i < ep->nurbs; i++)
release_urb_ctx(&ep->urb[i]);
if (ep->syncbuf)
usb_free_coherent(ep->chip->dev, SYNC_URBS * 4,
ep->syncbuf, ep->sync_dma);
ep->syncbuf = NULL;
ep->nurbs = 0;
}
static int data_ep_set_params(struct snd_usb_endpoint *ep,
snd_pcm_format_t pcm_format,
unsigned int channels,
unsigned int period_bytes,
struct audioformat *fmt,
struct snd_usb_endpoint *sync_ep)
{
unsigned int maxsize, i, urb_packs, total_packs, packs_per_ms;
int is_playback = usb_pipeout(ep->pipe);
int frame_bits = snd_pcm_format_physical_width(pcm_format) * channels;
if (pcm_format == SNDRV_PCM_FORMAT_DSD_U16_LE && fmt->dsd_dop) {
frame_bits += channels << 3;
}
ep->datainterval = fmt->datainterval;
ep->stride = frame_bits >> 3;
ep->silence_value = pcm_format == SNDRV_PCM_FORMAT_U8 ? 0x80 : 0;
if (ep->maxpacksize) {
maxsize = ep->maxpacksize;
ep->freqmax = (maxsize / (frame_bits >> 3))
<< (16 - ep->datainterval);
} else {
ep->freqmax = ep->freqn + (ep->freqn >> 2);
maxsize = ((ep->freqmax + 0xffff) * (frame_bits >> 3))
>> (16 - ep->datainterval);
}
if (ep->fill_max)
ep->curpacksize = ep->maxpacksize;
else
ep->curpacksize = maxsize;
if (snd_usb_get_speed(ep->chip->dev) != USB_SPEED_FULL)
packs_per_ms = 8 >> ep->datainterval;
else
packs_per_ms = 1;
if (is_playback && !snd_usb_endpoint_implicit_feedback_sink(ep)) {
urb_packs = max(ep->chip->nrpacks, 1);
urb_packs = min(urb_packs, (unsigned int) MAX_PACKS);
} else {
urb_packs = 1;
}
urb_packs *= packs_per_ms;
if (sync_ep && !snd_usb_endpoint_implicit_feedback_sink(ep))
urb_packs = min(urb_packs, 1U << sync_ep->syncinterval);
if (is_playback && !snd_usb_endpoint_implicit_feedback_sink(ep)) {
unsigned int minsize, maxpacks;
minsize = (ep->freqn >> (16 - ep->datainterval))
* (frame_bits >> 3);
if (sync_ep)
minsize -= minsize >> 3;
minsize = max(minsize, 1u);
total_packs = (period_bytes + minsize - 1) / minsize;
if (total_packs < 2) {
total_packs = 2;
} else {
maxpacks = max(MAX_QUEUE * packs_per_ms, urb_packs * 2);
total_packs = min(total_packs, maxpacks);
}
} else {
while (urb_packs > 1 && urb_packs * maxsize >= period_bytes)
urb_packs >>= 1;
total_packs = MAX_URBS * urb_packs;
}
ep->nurbs = (total_packs + urb_packs - 1) / urb_packs;
if (ep->nurbs > MAX_URBS) {
ep->nurbs = MAX_URBS;
total_packs = MAX_URBS * urb_packs;
} else if (ep->nurbs < 2) {
ep->nurbs = 2;
}
for (i = 0; i < ep->nurbs; i++) {
struct snd_urb_ctx *u = &ep->urb[i];
u->index = i;
u->ep = ep;
u->packets = (i + 1) * total_packs / ep->nurbs
- i * total_packs / ep->nurbs;
u->buffer_size = maxsize * u->packets;
if (fmt->fmt_type == UAC_FORMAT_TYPE_II)
u->packets++;
u->urb = usb_alloc_urb(u->packets, GFP_KERNEL);
if (!u->urb)
goto out_of_memory;
u->urb->transfer_buffer =
usb_alloc_coherent(ep->chip->dev, u->buffer_size,
GFP_KERNEL, &u->urb->transfer_dma);
if (!u->urb->transfer_buffer)
goto out_of_memory;
u->urb->pipe = ep->pipe;
u->urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
u->urb->interval = 1 << ep->datainterval;
u->urb->context = u;
u->urb->complete = snd_complete_urb;
INIT_LIST_HEAD(&u->ready_list);
}
return 0;
out_of_memory:
release_urbs(ep, 0);
return -ENOMEM;
}
static int sync_ep_set_params(struct snd_usb_endpoint *ep,
struct audioformat *fmt)
{
int i;
ep->syncbuf = usb_alloc_coherent(ep->chip->dev, SYNC_URBS * 4,
GFP_KERNEL, &ep->sync_dma);
if (!ep->syncbuf)
return -ENOMEM;
for (i = 0; i < SYNC_URBS; i++) {
struct snd_urb_ctx *u = &ep->urb[i];
u->index = i;
u->ep = ep;
u->packets = 1;
u->urb = usb_alloc_urb(1, GFP_KERNEL);
if (!u->urb)
goto out_of_memory;
u->urb->transfer_buffer = ep->syncbuf + i * 4;
u->urb->transfer_dma = ep->sync_dma + i * 4;
u->urb->transfer_buffer_length = 4;
u->urb->pipe = ep->pipe;
u->urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;
u->urb->number_of_packets = 1;
u->urb->interval = 1 << ep->syncinterval;
u->urb->context = u;
u->urb->complete = snd_complete_urb;
}
ep->nurbs = SYNC_URBS;
return 0;
out_of_memory:
release_urbs(ep, 0);
return -ENOMEM;
}
int snd_usb_endpoint_set_params(struct snd_usb_endpoint *ep,
snd_pcm_format_t pcm_format,
unsigned int channels,
unsigned int period_bytes,
unsigned int rate,
struct audioformat *fmt,
struct snd_usb_endpoint *sync_ep)
{
int err;
if (ep->use_count != 0) {
snd_printk(KERN_WARNING "Unable to change format on ep #%x: already in use\n",
ep->ep_num);
return -EBUSY;
}
release_urbs(ep, 0);
ep->datainterval = fmt->datainterval;
ep->maxpacksize = fmt->maxpacksize;
ep->fill_max = !!(fmt->attributes & UAC_EP_CS_ATTR_FILL_MAX);
if (snd_usb_get_speed(ep->chip->dev) == USB_SPEED_FULL)
ep->freqn = get_usb_full_speed_rate(rate);
else
ep->freqn = get_usb_high_speed_rate(rate);
ep->freqm = ep->freqn;
ep->freqshift = INT_MIN;
ep->phase = 0;
switch (ep->type) {
case SND_USB_ENDPOINT_TYPE_DATA:
err = data_ep_set_params(ep, pcm_format, channels,
period_bytes, fmt, sync_ep);
break;
case SND_USB_ENDPOINT_TYPE_SYNC:
err = sync_ep_set_params(ep, fmt);
break;
default:
err = -EINVAL;
}
snd_printdd(KERN_DEBUG "Setting params for ep #%x (type %d, %d urbs), ret=%d\n",
ep->ep_num, ep->type, ep->nurbs, err);
return err;
}
int snd_usb_endpoint_start(struct snd_usb_endpoint *ep, bool can_sleep)
{
int err;
unsigned int i;
if (ep->chip->shutdown)
return -EBADFD;
if (++ep->use_count != 1)
return 0;
deactivate_urbs(ep, false);
if (can_sleep)
wait_clear_urbs(ep);
ep->active_mask = 0;
ep->unlink_mask = 0;
ep->phase = 0;
snd_usb_endpoint_start_quirk(ep);
set_bit(EP_FLAG_RUNNING, &ep->flags);
if (snd_usb_endpoint_implicit_feedback_sink(ep)) {
for (i = 0; i < ep->nurbs; i++) {
struct snd_urb_ctx *ctx = ep->urb + i;
list_add_tail(&ctx->ready_list, &ep->ready_playback_urbs);
}
return 0;
}
for (i = 0; i < ep->nurbs; i++) {
struct urb *urb = ep->urb[i].urb;
if (snd_BUG_ON(!urb))
goto __error;
if (usb_pipeout(ep->pipe)) {
prepare_outbound_urb(ep, urb->context);
} else {
prepare_inbound_urb(ep, urb->context);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
snd_printk(KERN_ERR "cannot submit urb %d, error %d: %s\n",
i, err, usb_error_string(err));
goto __error;
}
set_bit(i, &ep->active_mask);
}
return 0;
__error:
clear_bit(EP_FLAG_RUNNING, &ep->flags);
ep->use_count--;
deactivate_urbs(ep, false);
return -EPIPE;
}
void snd_usb_endpoint_stop(struct snd_usb_endpoint *ep)
{
if (!ep)
return;
if (snd_BUG_ON(ep->use_count == 0))
return;
if (--ep->use_count == 0) {
deactivate_urbs(ep, false);
ep->data_subs = NULL;
ep->sync_slave = NULL;
ep->retire_data_urb = NULL;
ep->prepare_data_urb = NULL;
set_bit(EP_FLAG_STOPPING, &ep->flags);
}
}
int snd_usb_endpoint_deactivate(struct snd_usb_endpoint *ep)
{
if (!ep)
return -EINVAL;
deactivate_urbs(ep, true);
wait_clear_urbs(ep);
if (ep->use_count != 0)
return 0;
clear_bit(EP_FLAG_ACTIVATED, &ep->flags);
return 0;
}
void snd_usb_endpoint_free(struct list_head *head)
{
struct snd_usb_endpoint *ep;
ep = list_entry(head, struct snd_usb_endpoint, list);
release_urbs(ep, 1);
kfree(ep);
}
void snd_usb_handle_sync_urb(struct snd_usb_endpoint *ep,
struct snd_usb_endpoint *sender,
const struct urb *urb)
{
int shift;
unsigned int f;
unsigned long flags;
snd_BUG_ON(ep == sender);
if (snd_usb_endpoint_implicit_feedback_sink(ep) &&
ep->use_count != 0) {
int i, bytes = 0;
struct snd_urb_ctx *in_ctx;
struct snd_usb_packet_info *out_packet;
in_ctx = urb->context;
for (i = 0; i < in_ctx->packets; i++)
if (urb->iso_frame_desc[i].status == 0)
bytes += urb->iso_frame_desc[i].actual_length;
if (bytes == 0)
return;
spin_lock_irqsave(&ep->lock, flags);
out_packet = ep->next_packet + ep->next_packet_write_pos;
out_packet->packets = in_ctx->packets;
for (i = 0; i < in_ctx->packets; i++) {
if (urb->iso_frame_desc[i].status == 0)
out_packet->packet_size[i] =
urb->iso_frame_desc[i].actual_length / sender->stride;
else
out_packet->packet_size[i] = 0;
}
ep->next_packet_write_pos++;
ep->next_packet_write_pos %= MAX_URBS;
spin_unlock_irqrestore(&ep->lock, flags);
queue_pending_output_urbs(ep);
return;
}
if (urb->iso_frame_desc[0].status != 0 ||
urb->iso_frame_desc[0].actual_length < 3)
return;
f = le32_to_cpup(urb->transfer_buffer);
if (urb->iso_frame_desc[0].actual_length == 3)
f &= 0x00ffffff;
else
f &= 0x0fffffff;
if (f == 0)
return;
if (unlikely(ep->freqshift == INT_MIN)) {
shift = 0;
while (f < ep->freqn - ep->freqn / 4) {
f <<= 1;
shift++;
}
while (f > ep->freqn + ep->freqn / 2) {
f >>= 1;
shift--;
}
ep->freqshift = shift;
} else if (ep->freqshift >= 0)
f <<= ep->freqshift;
else
f >>= -ep->freqshift;
if (likely(f >= ep->freqn - ep->freqn / 8 && f <= ep->freqmax)) {
spin_lock_irqsave(&ep->lock, flags);
ep->freqm = f;
spin_unlock_irqrestore(&ep->lock, flags);
} else {
ep->freqshift = INT_MIN;
}
}
