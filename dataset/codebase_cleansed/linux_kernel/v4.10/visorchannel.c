void
visorchannel_destroy(struct visorchannel *channel)
{
if (!channel)
return;
if (channel->mapped) {
memunmap(channel->mapped);
if (channel->requested)
release_mem_region(channel->physaddr, channel->nbytes);
}
kfree(channel);
}
u64
visorchannel_get_physaddr(struct visorchannel *channel)
{
return channel->physaddr;
}
ulong
visorchannel_get_nbytes(struct visorchannel *channel)
{
return channel->nbytes;
}
char *
visorchannel_uuid_id(uuid_le *guid, char *s)
{
sprintf(s, "%pUL", guid);
return s;
}
char *
visorchannel_id(struct visorchannel *channel, char *s)
{
return visorchannel_uuid_id(&channel->guid, s);
}
char *
visorchannel_zoneid(struct visorchannel *channel, char *s)
{
return visorchannel_uuid_id(&channel->chan_hdr.zone_uuid, s);
}
u64
visorchannel_get_clientpartition(struct visorchannel *channel)
{
return channel->chan_hdr.partition_handle;
}
int
visorchannel_set_clientpartition(struct visorchannel *channel,
u64 partition_handle)
{
channel->chan_hdr.partition_handle = partition_handle;
return 0;
}
uuid_le
visorchannel_get_uuid(struct visorchannel *channel)
{
return channel->guid;
}
int
visorchannel_read(struct visorchannel *channel, ulong offset,
void *dest, ulong nbytes)
{
if (offset + nbytes > channel->nbytes)
return -EIO;
memcpy(dest, channel->mapped + offset, nbytes);
return 0;
}
int
visorchannel_write(struct visorchannel *channel, ulong offset,
void *dest, ulong nbytes)
{
size_t chdr_size = sizeof(struct channel_header);
size_t copy_size;
if (offset + nbytes > channel->nbytes)
return -EIO;
if (offset < chdr_size) {
copy_size = min(chdr_size - offset, nbytes);
memcpy(((char *)(&channel->chan_hdr)) + offset,
dest, copy_size);
}
memcpy(channel->mapped + offset, dest, nbytes);
return 0;
}
void __iomem *
visorchannel_get_header(struct visorchannel *channel)
{
return (void __iomem *)&channel->chan_hdr;
}
static int
sig_read_header(struct visorchannel *channel, u32 queue,
struct signal_queue_header *sig_hdr)
{
if (channel->chan_hdr.ch_space_offset < sizeof(struct channel_header))
return -EINVAL;
return visorchannel_read(channel,
SIG_QUEUE_OFFSET(&channel->chan_hdr, queue),
sig_hdr, sizeof(struct signal_queue_header));
}
static inline int
sig_read_data(struct visorchannel *channel, u32 queue,
struct signal_queue_header *sig_hdr, u32 slot, void *data)
{
int signal_data_offset = SIG_DATA_OFFSET(&channel->chan_hdr, queue,
sig_hdr, slot);
return visorchannel_read(channel, signal_data_offset,
data, sig_hdr->signal_size);
}
static inline int
sig_write_data(struct visorchannel *channel, u32 queue,
struct signal_queue_header *sig_hdr, u32 slot, void *data)
{
int signal_data_offset = SIG_DATA_OFFSET(&channel->chan_hdr, queue,
sig_hdr, slot);
return visorchannel_write(channel, signal_data_offset,
data, sig_hdr->signal_size);
}
static int
signalremove_inner(struct visorchannel *channel, u32 queue, void *msg)
{
struct signal_queue_header sig_hdr;
int error;
error = sig_read_header(channel, queue, &sig_hdr);
if (error)
return error;
if (sig_hdr.head == sig_hdr.tail)
return -EAGAIN;
sig_hdr.tail = (sig_hdr.tail + 1) % sig_hdr.max_slots;
error = sig_read_data(channel, queue, &sig_hdr, sig_hdr.tail, msg);
if (error)
return error;
sig_hdr.num_received++;
mb();
error = SIG_WRITE_FIELD(channel, queue, &sig_hdr, tail);
if (error)
return error;
error = SIG_WRITE_FIELD(channel, queue, &sig_hdr, num_received);
if (error)
return error;
return 0;
}
int
visorchannel_signalremove(struct visorchannel *channel, u32 queue, void *msg)
{
int rc;
unsigned long flags;
if (channel->needs_lock) {
spin_lock_irqsave(&channel->remove_lock, flags);
rc = signalremove_inner(channel, queue, msg);
spin_unlock_irqrestore(&channel->remove_lock, flags);
} else {
rc = signalremove_inner(channel, queue, msg);
}
return rc;
}
static bool
queue_empty(struct visorchannel *channel, u32 queue)
{
struct signal_queue_header sig_hdr;
if (sig_read_header(channel, queue, &sig_hdr))
return true;
return (sig_hdr.head == sig_hdr.tail);
}
bool
visorchannel_signalempty(struct visorchannel *channel, u32 queue)
{
bool rc;
unsigned long flags;
if (!channel->needs_lock)
return queue_empty(channel, queue);
spin_lock_irqsave(&channel->remove_lock, flags);
rc = queue_empty(channel, queue);
spin_unlock_irqrestore(&channel->remove_lock, flags);
return rc;
}
static int
signalinsert_inner(struct visorchannel *channel, u32 queue, void *msg)
{
struct signal_queue_header sig_hdr;
int error;
error = sig_read_header(channel, queue, &sig_hdr);
if (error)
return error;
sig_hdr.head = (sig_hdr.head + 1) % sig_hdr.max_slots;
if (sig_hdr.head == sig_hdr.tail) {
sig_hdr.num_overflows++;
visorchannel_write(channel,
SIG_QUEUE_OFFSET(&channel->chan_hdr, queue) +
offsetof(struct signal_queue_header,
num_overflows),
&sig_hdr.num_overflows,
sizeof(sig_hdr.num_overflows));
return -EIO;
}
error = sig_write_data(channel, queue, &sig_hdr, sig_hdr.head, msg);
if (error)
return error;
sig_hdr.num_sent++;
mb();
error = SIG_WRITE_FIELD(channel, queue, &sig_hdr, head);
if (error)
return error;
error = SIG_WRITE_FIELD(channel, queue, &sig_hdr, num_sent);
if (error)
return error;
return 0;
}
static struct visorchannel *
visorchannel_create_guts(u64 physaddr, unsigned long channel_bytes,
gfp_t gfp, uuid_le guid, bool needs_lock)
{
struct visorchannel *channel;
int err;
size_t size = sizeof(struct channel_header);
if (physaddr == 0)
return NULL;
channel = kzalloc(sizeof(*channel), gfp);
if (!channel)
return NULL;
channel->needs_lock = needs_lock;
spin_lock_init(&channel->insert_lock);
spin_lock_init(&channel->remove_lock);
channel->requested = request_mem_region(physaddr, size, MYDRVNAME);
if (!channel->requested) {
if (uuid_le_cmp(guid, spar_video_guid)) {
goto err_destroy_channel;
}
}
channel->mapped = memremap(physaddr, size, MEMREMAP_WB);
if (!channel->mapped) {
release_mem_region(physaddr, size);
goto err_destroy_channel;
}
channel->physaddr = physaddr;
channel->nbytes = size;
err = visorchannel_read(channel, 0, &channel->chan_hdr,
sizeof(struct channel_header));
if (err)
goto err_destroy_channel;
if (channel_bytes == 0)
channel_bytes = (ulong)channel->chan_hdr.size;
if (uuid_le_cmp(guid, NULL_UUID_LE) == 0)
guid = channel->chan_hdr.chtype;
memunmap(channel->mapped);
if (channel->requested)
release_mem_region(channel->physaddr, channel->nbytes);
channel->mapped = NULL;
channel->requested = request_mem_region(channel->physaddr,
channel_bytes, MYDRVNAME);
if (!channel->requested) {
if (uuid_le_cmp(guid, spar_video_guid)) {
goto err_destroy_channel;
}
}
channel->mapped = memremap(channel->physaddr, channel_bytes,
MEMREMAP_WB);
if (!channel->mapped) {
release_mem_region(channel->physaddr, channel_bytes);
goto err_destroy_channel;
}
channel->nbytes = channel_bytes;
channel->guid = guid;
return channel;
err_destroy_channel:
visorchannel_destroy(channel);
return NULL;
}
struct visorchannel *
visorchannel_create(u64 physaddr, unsigned long channel_bytes,
gfp_t gfp, uuid_le guid)
{
return visorchannel_create_guts(physaddr, channel_bytes, gfp, guid,
false);
}
struct visorchannel *
visorchannel_create_with_lock(u64 physaddr, unsigned long channel_bytes,
gfp_t gfp, uuid_le guid)
{
return visorchannel_create_guts(physaddr, channel_bytes, gfp, guid,
true);
}
int
visorchannel_signalinsert(struct visorchannel *channel, u32 queue, void *msg)
{
int rc;
unsigned long flags;
if (channel->needs_lock) {
spin_lock_irqsave(&channel->insert_lock, flags);
rc = signalinsert_inner(channel, queue, msg);
spin_unlock_irqrestore(&channel->insert_lock, flags);
} else {
rc = signalinsert_inner(channel, queue, msg);
}
return rc;
}
