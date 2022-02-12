void hv_begin_read(struct hv_ring_buffer_info *rbi)
{
rbi->ring_buffer->interrupt_mask = 1;
mb();
}
u32 hv_end_read(struct hv_ring_buffer_info *rbi)
{
u32 read;
u32 write;
rbi->ring_buffer->interrupt_mask = 0;
mb();
hv_get_ringbuffer_availbytes(rbi, &read, &write);
return read;
}
static bool hv_need_to_signal(u32 old_write, struct hv_ring_buffer_info *rbi)
{
mb();
if (rbi->ring_buffer->interrupt_mask)
return false;
rmb();
if (old_write == rbi->ring_buffer->read_index)
return true;
return false;
}
static bool hv_need_to_signal_on_read(u32 prev_write_sz,
struct hv_ring_buffer_info *rbi)
{
u32 cur_write_sz;
u32 r_size;
u32 write_loc = rbi->ring_buffer->write_index;
u32 read_loc = rbi->ring_buffer->read_index;
u32 pending_sz = rbi->ring_buffer->pending_send_sz;
if (pending_sz == 0)
return false;
r_size = rbi->ring_datasize;
cur_write_sz = write_loc >= read_loc ? r_size - (write_loc - read_loc) :
read_loc - write_loc;
if ((prev_write_sz < pending_sz) && (cur_write_sz >= pending_sz))
return true;
return false;
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
}
static inline void *
hv_get_ring_buffer(struct hv_ring_buffer_info *ring_info)
{
return (void *)ring_info->ring_buffer->buffer;
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
u32 frag_len;
if (destlen > ring_buffer_size - start_read_offset) {
frag_len = ring_buffer_size - start_read_offset;
memcpy(dest, ring_buffer + start_read_offset, frag_len);
memcpy(dest + frag_len, ring_buffer, destlen - frag_len);
} else
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
u32 frag_len;
if (srclen > ring_buffer_size - start_write_offset) {
frag_len = ring_buffer_size - start_write_offset;
memcpy(ring_buffer + start_write_offset, src, frag_len);
memcpy(ring_buffer, src + frag_len, srclen - frag_len);
} else
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
void *buffer, u32 buflen)
{
if (sizeof(struct hv_ring_buffer) != PAGE_SIZE)
return -EINVAL;
memset(ring_info, 0, sizeof(struct hv_ring_buffer_info));
ring_info->ring_buffer = (struct hv_ring_buffer *)buffer;
ring_info->ring_buffer->read_index =
ring_info->ring_buffer->write_index = 0;
ring_info->ring_buffer->feature_bits.value = 1;
ring_info->ring_size = buflen;
ring_info->ring_datasize = buflen - sizeof(struct hv_ring_buffer);
spin_lock_init(&ring_info->ring_lock);
return 0;
}
void hv_ringbuffer_cleanup(struct hv_ring_buffer_info *ring_info)
{
}
int hv_ringbuffer_write(struct hv_ring_buffer_info *outring_info,
struct kvec *kv_list, u32 kv_count, bool *signal)
{
int i = 0;
u32 bytes_avail_towrite;
u32 bytes_avail_toread;
u32 totalbytes_towrite = 0;
u32 next_write_location;
u32 old_write;
u64 prev_indices = 0;
unsigned long flags;
for (i = 0; i < kv_count; i++)
totalbytes_towrite += kv_list[i].iov_len;
totalbytes_towrite += sizeof(u64);
spin_lock_irqsave(&outring_info->ring_lock, flags);
hv_get_ringbuffer_availbytes(outring_info,
&bytes_avail_toread,
&bytes_avail_towrite);
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
mb();
hv_set_next_write_location(outring_info, next_write_location);
spin_unlock_irqrestore(&outring_info->ring_lock, flags);
*signal = hv_need_to_signal(old_write, outring_info);
return 0;
}
int hv_ringbuffer_peek(struct hv_ring_buffer_info *Inring_info,
void *Buffer, u32 buflen)
{
u32 bytes_avail_towrite;
u32 bytes_avail_toread;
u32 next_read_location = 0;
unsigned long flags;
spin_lock_irqsave(&Inring_info->ring_lock, flags);
hv_get_ringbuffer_availbytes(Inring_info,
&bytes_avail_toread,
&bytes_avail_towrite);
if (bytes_avail_toread < buflen) {
spin_unlock_irqrestore(&Inring_info->ring_lock, flags);
return -EAGAIN;
}
next_read_location = hv_get_next_read_location(Inring_info);
next_read_location = hv_copyfrom_ringbuffer(Inring_info,
Buffer,
buflen,
next_read_location);
spin_unlock_irqrestore(&Inring_info->ring_lock, flags);
return 0;
}
int hv_ringbuffer_read(struct hv_ring_buffer_info *inring_info, void *buffer,
u32 buflen, u32 offset, bool *signal)
{
u32 bytes_avail_towrite;
u32 bytes_avail_toread;
u32 next_read_location = 0;
u64 prev_indices = 0;
unsigned long flags;
if (buflen <= 0)
return -EINVAL;
spin_lock_irqsave(&inring_info->ring_lock, flags);
hv_get_ringbuffer_availbytes(inring_info,
&bytes_avail_toread,
&bytes_avail_towrite);
if (bytes_avail_toread < buflen) {
spin_unlock_irqrestore(&inring_info->ring_lock, flags);
return -EAGAIN;
}
next_read_location =
hv_get_next_readlocation_withoffset(inring_info, offset);
next_read_location = hv_copyfrom_ringbuffer(inring_info,
buffer,
buflen,
next_read_location);
next_read_location = hv_copyfrom_ringbuffer(inring_info,
&prev_indices,
sizeof(u64),
next_read_location);
mb();
hv_set_next_read_location(inring_info, next_read_location);
spin_unlock_irqrestore(&inring_info->ring_lock, flags);
*signal = hv_need_to_signal_on_read(bytes_avail_towrite, inring_info);
return 0;
}
