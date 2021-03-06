static VISORCHANNEL *
visorchannel_create_guts(HOSTADDRESS physaddr, ulong channelBytes,
VISORCHANNEL *parent, ulong off, uuid_le guid,
BOOL needs_lock)
{
VISORCHANNEL *p = NULL;
void *rc = NULL;
p = kmalloc(sizeof(VISORCHANNEL), GFP_KERNEL|__GFP_NORETRY);
if (p == NULL) {
ERRDRV("allocation failed: (status=0)\n");
rc = NULL;
goto cleanup;
}
p->memregion = NULL;
p->needs_lock = needs_lock;
spin_lock_init(&p->insert_lock);
spin_lock_init(&p->remove_lock);
if (parent == NULL)
p->memregion =
visor_memregion_create(physaddr,
sizeof(struct channel_header));
else
p->memregion =
visor_memregion_create_overlapped(parent->memregion,
off, sizeof(struct channel_header));
if (p->memregion == NULL) {
ERRDRV("visor_memregion_create failed failed: (status=0)\n");
rc = NULL;
goto cleanup;
}
if (visor_memregion_read(p->memregion, 0, &p->chan_hdr,
sizeof(struct channel_header)) < 0) {
ERRDRV("visor_memregion_read failed: (status=0)\n");
rc = NULL;
goto cleanup;
}
if (channelBytes == 0)
channelBytes = (ulong)p->chan_hdr.size;
if (uuid_le_cmp(guid, NULL_UUID_LE) == 0)
guid = p->chan_hdr.chtype;
if (visor_memregion_resize(p->memregion, channelBytes) < 0) {
ERRDRV("visor_memregion_resize failed: (status=0)\n");
rc = NULL;
goto cleanup;
}
p->size = channelBytes;
p->guid = guid;
rc = p;
cleanup:
if (rc == NULL) {
if (p != NULL) {
visorchannel_destroy(p);
p = NULL;
}
}
return rc;
}
VISORCHANNEL *
visorchannel_create(HOSTADDRESS physaddr, ulong channelBytes, uuid_le guid)
{
return visorchannel_create_guts(physaddr, channelBytes, NULL, 0, guid,
FALSE);
}
VISORCHANNEL *
visorchannel_create_with_lock(HOSTADDRESS physaddr, ulong channelBytes,
uuid_le guid)
{
return visorchannel_create_guts(physaddr, channelBytes, NULL, 0, guid,
TRUE);
}
VISORCHANNEL *
visorchannel_create_overlapped(ulong channelBytes,
VISORCHANNEL *parent, ulong off, uuid_le guid)
{
return visorchannel_create_guts(0, channelBytes, parent, off, guid,
FALSE);
}
VISORCHANNEL *
visorchannel_create_overlapped_with_lock(ulong channelBytes,
VISORCHANNEL *parent, ulong off,
uuid_le guid)
{
return visorchannel_create_guts(0, channelBytes, parent, off, guid,
TRUE);
}
void
visorchannel_destroy(VISORCHANNEL *channel)
{
if (channel == NULL)
return;
if (channel->memregion != NULL) {
visor_memregion_destroy(channel->memregion);
channel->memregion = NULL;
}
kfree(channel);
}
HOSTADDRESS
visorchannel_get_physaddr(VISORCHANNEL *channel)
{
return visor_memregion_get_physaddr(channel->memregion);
}
ulong
visorchannel_get_nbytes(VISORCHANNEL *channel)
{
return channel->size;
}
char *
visorchannel_uuid_id(uuid_le *guid, char *s)
{
sprintf(s, "%pUL", guid);
return s;
}
char *
visorchannel_id(VISORCHANNEL *channel, char *s)
{
return visorchannel_uuid_id(&channel->guid, s);
}
char *
visorchannel_zoneid(VISORCHANNEL *channel, char *s)
{
return visorchannel_uuid_id(&channel->chan_hdr.zone_uuid, s);
}
HOSTADDRESS
visorchannel_get_clientpartition(VISORCHANNEL *channel)
{
return channel->chan_hdr.partition_handle;
}
uuid_le
visorchannel_get_uuid(VISORCHANNEL *channel)
{
return channel->guid;
}
struct memregion *
visorchannel_get_memregion(VISORCHANNEL *channel)
{
return channel->memregion;
}
int
visorchannel_read(VISORCHANNEL *channel, ulong offset,
void *local, ulong nbytes)
{
int rc = visor_memregion_read(channel->memregion, offset,
local, nbytes);
if ((rc >= 0) && (offset == 0) &&
(nbytes >= sizeof(struct channel_header))) {
memcpy(&channel->chan_hdr, local,
sizeof(struct channel_header));
}
return rc;
}
int
visorchannel_write(VISORCHANNEL *channel, ulong offset,
void *local, ulong nbytes)
{
if (offset == 0 && nbytes >= sizeof(struct channel_header))
memcpy(&channel->chan_hdr, local,
sizeof(struct channel_header));
return visor_memregion_write(channel->memregion, offset, local, nbytes);
}
int
visorchannel_clear(VISORCHANNEL *channel, ulong offset, u8 ch, ulong nbytes)
{
int rc = -1;
int bufsize = 65536;
int written = 0;
u8 *buf = vmalloc(bufsize);
if (buf == NULL) {
ERRDRV("%s failed memory allocation", __func__);
goto cleanup;
}
memset(buf, ch, bufsize);
while (nbytes > 0) {
ulong thisbytes = bufsize;
int x = -1;
if (nbytes < thisbytes)
thisbytes = nbytes;
x = visor_memregion_write(channel->memregion, offset + written,
buf, thisbytes);
if (x < 0) {
rc = x;
goto cleanup;
}
written += thisbytes;
nbytes -= thisbytes;
}
rc = 0;
cleanup:
if (buf != NULL) {
vfree(buf);
buf = NULL;
}
return rc;
}
void __iomem *
visorchannel_get_header(VISORCHANNEL *channel)
{
return (void __iomem *)&channel->chan_hdr;
}
static BOOL
sig_read_header(VISORCHANNEL *channel, u32 queue,
struct signal_queue_header *sig_hdr)
{
BOOL rc = FALSE;
if (channel->chan_hdr.ch_space_offset < sizeof(struct channel_header)) {
ERRDRV("oChannelSpace too small: (status=%d)\n", rc);
goto cleanup;
}
if (visor_memregion_read(channel->memregion,
SIG_QUEUE_OFFSET(&channel->chan_hdr, queue),
sig_hdr,
sizeof(struct signal_queue_header)) < 0) {
ERRDRV("queue=%d SIG_QUEUE_OFFSET=%d",
queue, (int)SIG_QUEUE_OFFSET(&channel->chan_hdr, queue));
ERRDRV("visor_memregion_read of signal queue failed: (status=%d)\n",
rc);
goto cleanup;
}
rc = TRUE;
cleanup:
return rc;
}
static BOOL
sig_do_data(VISORCHANNEL *channel, u32 queue,
struct signal_queue_header *sig_hdr, u32 slot, void *data,
BOOL is_write)
{
BOOL rc = FALSE;
int signal_data_offset = SIG_DATA_OFFSET(&channel->chan_hdr, queue,
sig_hdr, slot);
if (is_write) {
if (visor_memregion_write(channel->memregion,
signal_data_offset,
data, sig_hdr->signal_size) < 0) {
ERRDRV("visor_memregion_write of signal data failed: (status=%d)\n",
rc);
goto cleanup;
}
} else {
if (visor_memregion_read(channel->memregion, signal_data_offset,
data, sig_hdr->signal_size) < 0) {
ERRDRV("visor_memregion_read of signal data failed: (status=%d)\n",
rc);
goto cleanup;
}
}
rc = TRUE;
cleanup:
return rc;
}
static inline BOOL
sig_read_data(VISORCHANNEL *channel, u32 queue,
struct signal_queue_header *sig_hdr, u32 slot, void *data)
{
return sig_do_data(channel, queue, sig_hdr, slot, data, FALSE);
}
static inline BOOL
sig_write_data(VISORCHANNEL *channel, u32 queue,
struct signal_queue_header *sig_hdr, u32 slot, void *data)
{
return sig_do_data(channel, queue, sig_hdr, slot, data, TRUE);
}
static inline unsigned char
safe_sig_queue_validate(struct signal_queue_header *psafe_sqh,
struct signal_queue_header *punsafe_sqh,
u32 *phead, u32 *ptail)
{
if ((*phead >= psafe_sqh->max_slots) ||
(*ptail >= psafe_sqh->max_slots)) {
*phead = 0;
*ptail = 0;
punsafe_sqh->head = *phead;
punsafe_sqh->tail = *ptail;
ERRDRV("safe_sig_queue_validate: head = 0x%x, tail = 0x%x, MaxSlots = 0x%x",
*phead, *ptail, psafe_sqh->max_slots);
return 0;
}
return 1;
}
BOOL
visorchannel_signalremove(VISORCHANNEL *channel, u32 queue, void *msg)
{
BOOL rc = FALSE;
struct signal_queue_header sig_hdr;
if (channel->needs_lock)
spin_lock(&channel->remove_lock);
if (!sig_read_header(channel, queue, &sig_hdr)) {
rc = FALSE;
goto cleanup;
}
if (sig_hdr.head == sig_hdr.tail) {
rc = FALSE;
goto cleanup;
}
sig_hdr.tail = (sig_hdr.tail + 1) % sig_hdr.max_slots;
if (!sig_read_data(channel, queue, &sig_hdr, sig_hdr.tail, msg)) {
ERRDRV("sig_read_data failed: (status=%d)\n", rc);
goto cleanup;
}
sig_hdr.num_received++;
mb();
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, tail)) {
ERRDRV("visor_memregion_write of Tail failed: (status=%d)\n",
rc);
goto cleanup;
}
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, num_received)) {
ERRDRV("visor_memregion_write of NumSignalsReceived failed: (status=%d)\n",
rc);
goto cleanup;
}
rc = TRUE;
cleanup:
if (channel->needs_lock)
spin_unlock(&channel->remove_lock);
return rc;
}
BOOL
visorchannel_signalinsert(VISORCHANNEL *channel, u32 queue, void *msg)
{
BOOL rc = FALSE;
struct signal_queue_header sig_hdr;
if (channel->needs_lock)
spin_lock(&channel->insert_lock);
if (!sig_read_header(channel, queue, &sig_hdr)) {
rc = FALSE;
goto cleanup;
}
sig_hdr.head = ((sig_hdr.head + 1) % sig_hdr.max_slots);
if (sig_hdr.head == sig_hdr.tail) {
sig_hdr.num_overflows++;
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, num_overflows)) {
ERRDRV("visor_memregion_write of NumOverflows failed: (status=%d)\n",
rc);
goto cleanup;
}
rc = FALSE;
goto cleanup;
}
if (!sig_write_data(channel, queue, &sig_hdr, sig_hdr.head, msg)) {
ERRDRV("sig_write_data failed: (status=%d)\n", rc);
goto cleanup;
}
sig_hdr.num_sent++;
mb();
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, head)) {
ERRDRV("visor_memregion_write of Head failed: (status=%d)\n",
rc);
goto cleanup;
}
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, num_sent)) {
ERRDRV("visor_memregion_write of NumSignalsSent failed: (status=%d)\n",
rc);
goto cleanup;
}
rc = TRUE;
cleanup:
if (channel->needs_lock)
spin_unlock(&channel->insert_lock);
return rc;
}
int
visorchannel_signalqueue_slots_avail(VISORCHANNEL *channel, u32 queue)
{
struct signal_queue_header sig_hdr;
u32 slots_avail, slots_used;
u32 head, tail;
if (!sig_read_header(channel, queue, &sig_hdr))
return 0;
head = sig_hdr.head;
tail = sig_hdr.tail;
if (head < tail)
head = head + sig_hdr.max_slots;
slots_used = (head - tail);
slots_avail = sig_hdr.max_signals - slots_used;
return (int)slots_avail;
}
int
visorchannel_signalqueue_max_slots(VISORCHANNEL *channel, u32 queue)
{
struct signal_queue_header sig_hdr;
if (!sig_read_header(channel, queue, &sig_hdr))
return 0;
return (int)sig_hdr.max_signals;
}
static void
sigqueue_debug(struct signal_queue_header *q, int which, struct seq_file *seq)
{
seq_printf(seq, "Signal Queue #%d\n", which);
seq_printf(seq, " VersionId = %lu\n", (ulong)q->version);
seq_printf(seq, " Type = %lu\n", (ulong)q->chtype);
seq_printf(seq, " oSignalBase = %llu\n",
(long long)q->sig_base_offset);
seq_printf(seq, " SignalSize = %lu\n", (ulong)q->signal_size);
seq_printf(seq, " MaxSignalSlots = %lu\n",
(ulong)q->max_slots);
seq_printf(seq, " MaxSignals = %lu\n", (ulong)q->max_signals);
seq_printf(seq, " FeatureFlags = %-16.16Lx\n",
(long long)q->features);
seq_printf(seq, " NumSignalsSent = %llu\n",
(long long)q->num_sent);
seq_printf(seq, " NumSignalsReceived = %llu\n",
(long long)q->num_received);
seq_printf(seq, " NumOverflows = %llu\n",
(long long)q->num_overflows);
seq_printf(seq, " Head = %lu\n", (ulong)q->head);
seq_printf(seq, " Tail = %lu\n", (ulong)q->tail);
}
void
visorchannel_debug(VISORCHANNEL *channel, int nQueues,
struct seq_file *seq, u32 off)
{
HOSTADDRESS addr = 0;
ulong nbytes = 0, nbytes_region = 0;
struct memregion *memregion = NULL;
struct channel_header hdr;
struct channel_header *phdr = &hdr;
int i = 0;
int errcode = 0;
if (channel == NULL) {
ERRDRV("%s no channel", __func__);
return;
}
memregion = channel->memregion;
if (memregion == NULL) {
ERRDRV("%s no memregion", __func__);
return;
}
addr = visor_memregion_get_physaddr(memregion);
nbytes_region = visor_memregion_get_nbytes(memregion);
errcode = visorchannel_read(channel, off,
phdr, sizeof(struct channel_header));
if (errcode < 0) {
seq_printf(seq,
"Read of channel header failed with errcode=%d)\n",
errcode);
if (off == 0) {
phdr = &channel->chan_hdr;
seq_puts(seq, "(following data may be stale)\n");
} else {
return;
}
}
nbytes = (ulong)(phdr->size);
seq_printf(seq, "--- Begin channel @0x%-16.16Lx for 0x%lx bytes (region=0x%lx bytes) ---\n",
addr + off, nbytes, nbytes_region);
seq_printf(seq, "Type = %pUL\n", &phdr->chtype);
seq_printf(seq, "ZoneGuid = %pUL\n", &phdr->zone_uuid);
seq_printf(seq, "Signature = 0x%-16.16Lx\n",
(long long)phdr->signature);
seq_printf(seq, "LegacyState = %lu\n", (ulong)phdr->legacy_state);
seq_printf(seq, "SrvState = %lu\n", (ulong)phdr->srv_state);
seq_printf(seq, "CliStateBoot = %lu\n", (ulong)phdr->cli_state_boot);
seq_printf(seq, "CliStateOS = %lu\n", (ulong)phdr->cli_state_os);
seq_printf(seq, "HeaderSize = %lu\n", (ulong)phdr->header_size);
seq_printf(seq, "Size = %llu\n", (long long)phdr->size);
seq_printf(seq, "Features = 0x%-16.16llx\n",
(long long)phdr->features);
seq_printf(seq, "PartitionHandle = 0x%-16.16llx\n",
(long long)phdr->partition_handle);
seq_printf(seq, "Handle = 0x%-16.16llx\n",
(long long)phdr->handle);
seq_printf(seq, "VersionId = %lu\n", (ulong)phdr->version_id);
seq_printf(seq, "oChannelSpace = %llu\n",
(long long)phdr->ch_space_offset);
if ((phdr->ch_space_offset == 0) || (errcode < 0))
;
else
for (i = 0; i < nQueues; i++) {
struct signal_queue_header q;
errcode = visorchannel_read(channel,
off +
phdr->ch_space_offset +
(i * sizeof(q)),
&q, sizeof(q));
if (errcode < 0) {
seq_printf(seq,
"failed to read signal queue #%d from channel @0x%-16.16Lx errcode=%d\n",
i, addr, errcode);
continue;
}
sigqueue_debug(&q, i, seq);
}
seq_printf(seq, "--- End channel @0x%-16.16Lx for 0x%lx bytes ---\n",
addr + off, nbytes);
}
void
visorchannel_dump_section(VISORCHANNEL *chan, char *s,
int off, int len, struct seq_file *seq)
{
char *buf, *tbuf, *fmtbuf;
int fmtbufsize = 0;
int i;
int errcode = 0;
fmtbufsize = 100 * COVQ(len, 16);
buf = kmalloc(len, GFP_KERNEL|__GFP_NORETRY);
if (!buf)
return;
fmtbuf = kmalloc(fmtbufsize, GFP_KERNEL|__GFP_NORETRY);
if (!fmtbuf)
goto fmt_failed;
errcode = visorchannel_read(chan, off, buf, len);
if (errcode < 0) {
ERRDRV("%s failed to read %s from channel errcode=%d",
s, __func__, errcode);
goto read_failed;
}
seq_printf(seq, "channel %s:\n", s);
tbuf = buf;
while (len > 0) {
i = (len < 16) ? len : 16;
hex_dump_to_buffer(tbuf, i, 16, 1, fmtbuf, fmtbufsize, TRUE);
seq_printf(seq, "%s\n", fmtbuf);
tbuf += 16;
len -= 16;
}
read_failed:
kfree(fmtbuf);
fmt_failed:
kfree(buf);
}
