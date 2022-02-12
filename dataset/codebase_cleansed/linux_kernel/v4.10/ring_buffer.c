void hv_begin_read(struct hv_ring_buffer_info *rbi)
{
rbi->ring_buffer->interrupt_mask = 1;
virt_mb();
}
u32 hv_end_read(struct hv_ring_buffer_info *rbi)
{
rbi->ring_buffer->interrupt_mask = 0;
virt_mb();
return hv_get_bytes_to_read(rbi);
}
static void hv_signal_on_write(u32 old_write, struct vmbus_channel *channel,
bool kick_q)
{
struct hv_ring_buffer_info *rbi = &channel->outbound;
virt_mb();
if (READ_ONCE(rbi->ring_buffer->interrupt_mask))
return;
virt_rmb();
if (old_write == READ_ONCE(rbi->ring_buffer->read_index))
vmbus_setevent(channel);
return;
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
static inline u32
hv_get_next_read_location(struct hv_ring_buffer_info *ring_info)
{
u32 next = ring_info->ring_buffer->read_index;
return next;
}
static inline u32
hv_get_next_readlocation_withoffset(struct hv_ring_buffer_info *ring_info,
u32 offset)
{
u32 next = ring_info->ring_buffer->read_index;
next += offset;
next %= ring_info->ring_datasize;
return next;
}
static inline void
hv_set_next_read_location(struct hv_ring_buffer_info *ring_info,
u32 next_read_location)
{
ring_info->ring_buffer->read_index = next_read_location;
ring_info->priv_read_index = next_read_location;
}
static inline u32
hv_get_ring_buffersize(struct hv_ring_buffer_info *ring_info)
{
return ring_info->ring_datasize;
}
static inline u64
hv_get_ring_bufferindices(struct hv_ring_buffer_info *ring_info)
{
return (u64)ring_info->ring_buffer->write_index << 32;
}
static u32 hv_copyfrom_ringbuffer(
struct hv_ring_buffer_info *ring_info,
void *dest,
u32 destlen,
u32 start_read_offset)
{
void *ring_buffer = hv_get_ring_buffer(ring_info);
u32 ring_buffer_size = hv_get_ring_buffersize(ring_info);
memcpy(dest, ring_buffer + start_read_offset, destlen);
start_read_offset += destlen;
start_read_offset %= ring_buffer_size;
return start_read_offset;
}
static u32 hv_copyto_ringbuffer(
struct hv_ring_buffer_info *ring_info,
u32 start_write_offset,
void *src,
u32 srclen)
{
void *ring_buffer = hv_get_ring_buffer(ring_info);
u32 ring_buffer_size = hv_get_ring_buffersize(ring_info);
memcpy(ring_buffer + start_write_offset, src, srclen);
start_write_offset += srclen;
start_write_offset %= ring_buffer_size;
return start_write_offset;
}
void hv_ringbuffer_get_debuginfo(struct hv_ring_buffer_info *ring_info,
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
struct kvec *kv_list, u32 kv_count, bool lock,
bool kick_q)
{
int i = 0;
u32 bytes_avail_towrite;
u32 totalbytes_towrite = 0;
u32 next_write_location;
u32 old_write;
u64 prev_indices = 0;
unsigned long flags = 0;
struct hv_ring_buffer_info *outring_info = &channel->outbound;
for (i = 0; i < kv_count; i++)
totalbytes_towrite += kv_list[i].iov_len;
totalbytes_towrite += sizeof(u64);
if (lock)
spin_lock_irqsave(&outring_info->ring_lock, flags);
bytes_avail_towrite = hv_get_bytes_to_write(outring_info);
if (bytes_avail_towrite <= totalbytes_towrite) {
if (lock)
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
if (lock)
spin_unlock_irqrestore(&outring_info->ring_lock, flags);
hv_signal_on_write(old_write, channel, kick_q);
return 0;
}
int hv_ringbuffer_read(struct vmbus_channel *channel,
void *buffer, u32 buflen, u32 *buffer_actual_len,
u64 *requestid, bool raw)
{
u32 bytes_avail_toread;
u32 next_read_location = 0;
u64 prev_indices = 0;
struct vmpacket_descriptor desc;
u32 offset;
u32 packetlen;
int ret = 0;
struct hv_ring_buffer_info *inring_info = &channel->inbound;
if (buflen <= 0)
return -EINVAL;
*buffer_actual_len = 0;
*requestid = 0;
bytes_avail_toread = hv_get_bytes_to_read(inring_info);
if (bytes_avail_toread < sizeof(desc)) {
return ret;
}
init_cached_read_index(channel);
next_read_location = hv_get_next_read_location(inring_info);
next_read_location = hv_copyfrom_ringbuffer(inring_info, &desc,
sizeof(desc),
next_read_location);
offset = raw ? 0 : (desc.offset8 << 3);
packetlen = (desc.len8 << 3) - offset;
*buffer_actual_len = packetlen;
*requestid = desc.trans_id;
if (bytes_avail_toread < packetlen + offset)
return -EAGAIN;
if (packetlen > buflen)
return -ENOBUFS;
next_read_location =
hv_get_next_readlocation_withoffset(inring_info, offset);
next_read_location = hv_copyfrom_ringbuffer(inring_info,
buffer,
packetlen,
next_read_location);
next_read_location = hv_copyfrom_ringbuffer(inring_info,
&prev_indices,
sizeof(u64),
next_read_location);
virt_mb();
hv_set_next_read_location(inring_info, next_read_location);
hv_signal_on_read(channel);
return ret;
}
