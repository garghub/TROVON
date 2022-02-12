static void hv_signal_on_write(u32 old_write, struct vmbus_channel *channel)
{
struct hv_ring_buffer_info *rbi = &channel->outbound;
virt_mb();
if (READ_ONCE(rbi->ring_buffer->interrupt_mask))
return;
virt_rmb();
if (old_write == READ_ONCE(rbi->ring_buffer->read_index))
vmbus_setevent(channel);
}
static inline u32
hv_get_next_write_location(struct hv_ring_buffer_info *ring_info)
{
u32 next = ring_info->ring_buffer->write_index;
return next;
}
static inline void
hv_set_next_write_location(struct hv_ring_buffer_info *ring_info,
u32 next_write_location)
{
ring_info->ring_buffer->write_index = next_write_location;
}
static inline void
hv_set_next_read_location(struct hv_ring_buffer_info *ring_info,
u32 next_read_location)
{
ring_info->ring_buffer->read_index = next_read_location;
ring_info->priv_read_index = next_read_location;
}
static inline u32
hv_get_ring_buffersize(const struct hv_ring_buffer_info *ring_info)
{
return ring_info->ring_datasize;
}
static inline u64
hv_get_ring_bufferindices(struct hv_ring_buffer_info *ring_info)
{
return (u64)ring_info->ring_buffer->write_index << 32;
}
static u32 hv_copyto_ringbuffer(
struct hv_ring_buffer_info *ring_info,
u32 start_write_offset,
const void *src,
u32 srclen)
{
void *ring_buffer = hv_get_ring_buffer(ring_info);
u32 ring_buffer_size = hv_get_ring_buffersize(ring_info);
memcpy(ring_buffer + start_write_offset, src, srclen);
start_write_offset += srclen;
if (start_write_offset >= ring_buffer_size)
start_write_offset -= ring_buffer_size;
return start_write_offset;
}
void hv_ringbuffer_get_debuginfo(const struct hv_ring_buffer_info *ring_info,
struct hv_ring_buffer_debug_info *debug_info)
{
u32 bytes_avail_towrite;
u32 bytes_avail_toread;
if (ring_info->ring_buffer) {
hv_get_ringbuffer_availbytes(ring_info,
&bytes_avail_toread,
&bytes_avail_towrite);
debug_info->bytes_avail_toread = bytes_avail_toread;
debug_info->bytes_avail_towrite = bytes_avail_towrite;
debug_info->current_read_index =
ring_info->ring_buffer->read_index;
debug_info->current_write_index =
ring_info->ring_buffer->write_index;
debug_info->current_interrupt_mask =
ring_info->ring_buffer->interrupt_mask;
}
}
int hv_ringbuffer_init(struct hv_ring_buffer_info *ring_info,
struct page *pages, u32 page_cnt)
{
int i;
struct page **pages_wraparound;
BUILD_BUG_ON((sizeof(struct hv_ring_buffer) != PAGE_SIZE));
memset(ring_info, 0, sizeof(struct hv_ring_buffer_info));
pages_wraparound = kzalloc(sizeof(struct page *) * (page_cnt * 2 - 1),
GFP_KERNEL);
if (!pages_wraparound)
return -ENOMEM;
pages_wraparound[0] = pages;
for (i = 0; i < 2 * (page_cnt - 1); i++)
pages_wraparound[i + 1] = &pages[i % (page_cnt - 1) + 1];
ring_info->ring_buffer = (struct hv_ring_buffer *)
vmap(pages_wraparound, page_cnt * 2 - 1, VM_MAP, PAGE_KERNEL);
kfree(pages_wraparound);
if (!ring_info->ring_buffer)
return -ENOMEM;
ring_info->ring_buffer->read_index =
ring_info->ring_buffer->write_index = 0;
ring_info->ring_buffer->feature_bits.value = 1;
ring_info->ring_size = page_cnt << PAGE_SHIFT;
ring_info->ring_datasize = ring_info->ring_size -
sizeof(struct hv_ring_buffer);
spin_lock_init(&ring_info->ring_lock);
return 0;
}
void hv_ringbuffer_cleanup(struct hv_ring_buffer_info *ring_info)
{
vunmap(ring_info->ring_buffer);
}
int hv_ringbuffer_write(struct vmbus_channel *channel,
const struct kvec *kv_list, u32 kv_count)
{
int i;
u32 bytes_avail_towrite;
u32 totalbytes_towrite = sizeof(u64);
u32 next_write_location;
u32 old_write;
u64 prev_indices;
unsigned long flags;
struct hv_ring_buffer_info *outring_info = &channel->outbound;
if (channel->rescind)
return -ENODEV;
for (i = 0; i < kv_count; i++)
totalbytes_towrite += kv_list[i].iov_len;
spin_lock_irqsave(&outring_info->ring_lock, flags);
bytes_avail_towrite = hv_get_bytes_to_write(outring_info);
if (bytes_avail_towrite <= totalbytes_towrite) {
spin_unlock_irqrestore(&outring_info->ring_lock, flags);
return -EAGAIN;
}
next_write_location = hv_get_next_write_location(outring_info);
old_write = next_write_location;
for (i = 0; i < kv_count; i++) {
next_write_location = hv_copyto_ringbuffer(outring_info,
next_write_location,
kv_list[i].iov_base,
kv_list[i].iov_len);
}
prev_indices = hv_get_ring_bufferindices(outring_info);
next_write_location = hv_copyto_ringbuffer(outring_info,
next_write_location,
&prev_indices,
sizeof(u64));
virt_mb();
hv_set_next_write_location(outring_info, next_write_location);
spin_unlock_irqrestore(&outring_info->ring_lock, flags);
hv_signal_on_write(old_write, channel);
if (channel->rescind)
return -ENODEV;
return 0;
}
int hv_ringbuffer_read(struct vmbus_channel *channel,
void *buffer, u32 buflen, u32 *buffer_actual_len,
u64 *requestid, bool raw)
{
struct vmpacket_descriptor *desc;
u32 packetlen, offset;
if (unlikely(buflen == 0))
return -EINVAL;
*buffer_actual_len = 0;
*requestid = 0;
desc = hv_pkt_iter_first(channel);
if (desc == NULL) {
return 0;
}
offset = raw ? 0 : (desc->offset8 << 3);
packetlen = (desc->len8 << 3) - offset;
*buffer_actual_len = packetlen;
*requestid = desc->trans_id;
if (unlikely(packetlen > buflen))
return -ENOBUFS;
memcpy(buffer, (const char *)desc + offset, packetlen);
__hv_pkt_iter_next(channel, desc);
hv_pkt_iter_close(channel);
return 0;
}
static u32 hv_pkt_iter_avail(const struct hv_ring_buffer_info *rbi)
{
u32 priv_read_loc = rbi->priv_read_index;
u32 write_loc = READ_ONCE(rbi->ring_buffer->write_index);
if (write_loc >= priv_read_loc)
return write_loc - priv_read_loc;
else
return (rbi->ring_datasize - priv_read_loc) + write_loc;
}
struct vmpacket_descriptor *hv_pkt_iter_first(struct vmbus_channel *channel)
{
struct hv_ring_buffer_info *rbi = &channel->inbound;
struct vmpacket_descriptor *desc;
if (hv_pkt_iter_avail(rbi) < sizeof(struct vmpacket_descriptor))
return NULL;
desc = hv_get_ring_buffer(rbi) + rbi->priv_read_index;
if (desc)
prefetch((char *)desc + (desc->len8 << 3));
return desc;
}
struct vmpacket_descriptor *
__hv_pkt_iter_next(struct vmbus_channel *channel,
const struct vmpacket_descriptor *desc)
{
struct hv_ring_buffer_info *rbi = &channel->inbound;
u32 packetlen = desc->len8 << 3;
u32 dsize = rbi->ring_datasize;
rbi->priv_read_index += packetlen + VMBUS_PKT_TRAILER;
if (rbi->priv_read_index >= dsize)
rbi->priv_read_index -= dsize;
return hv_pkt_iter_first(channel);
}
void hv_pkt_iter_close(struct vmbus_channel *channel)
{
struct hv_ring_buffer_info *rbi = &channel->inbound;
u32 orig_write_sz = hv_get_bytes_to_write(rbi);
virt_rmb();
rbi->ring_buffer->read_index = rbi->priv_read_index;
virt_mb();
if (rbi->ring_buffer->interrupt_mask)
return;
if (rbi->ring_buffer->feature_bits.feat_pending_send_sz) {
u32 pending_sz = READ_ONCE(rbi->ring_buffer->pending_send_sz);
if (orig_write_sz > pending_sz)
return;
if (hv_get_bytes_to_write(rbi) < pending_sz)
return;
}
vmbus_setevent(channel);
}
