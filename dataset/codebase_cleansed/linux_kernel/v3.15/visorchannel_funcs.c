static VISORCHANNEL *
visorchannel_create_guts(HOSTADDRESS physaddr, ulong channelBytes,
VISORCHANNEL *parent, ulong off, GUID guid,
BOOL needs_lock)
{
VISORCHANNEL *p = NULL;
void *rc = NULL;
p = kmalloc(sizeof(VISORCHANNEL), GFP_KERNEL|__GFP_NORETRY);
if (p == NULL) {
ERRDRV("allocation failed: (status=0)\n");
rc = NULL;
goto Away;
}
p->memregion = NULL;
p->needs_lock = needs_lock;
spin_lock_init(&p->insert_lock);
spin_lock_init(&p->remove_lock);
if (parent == NULL)
p->memregion =
visor_memregion_create(physaddr, sizeof(CHANNEL_HEADER));
else
p->memregion =
visor_memregion_create_overlapped(parent->memregion,
off,
sizeof(CHANNEL_HEADER));
if (p->memregion == NULL) {
ERRDRV("visor_memregion_create failed failed: (status=0)\n");
rc = NULL;
goto Away;
}
if (visor_memregion_read(p->memregion, 0, &p->chan_hdr,
sizeof(CHANNEL_HEADER)) < 0) {
ERRDRV("visor_memregion_read failed: (status=0)\n");
rc = NULL;
goto Away;
}
if (channelBytes == 0)
channelBytes = (ulong) p->chan_hdr.Size;
if (STRUCTSEQUAL(guid, Guid0))
guid = p->chan_hdr.Type;
if (visor_memregion_resize(p->memregion, channelBytes) < 0) {
ERRDRV("visor_memregion_resize failed: (status=0)\n");
rc = NULL;
goto Away;
}
p->size = channelBytes;
p->guid = guid;
rc = p;
Away:
if (rc == NULL) {
if (p != NULL) {
visorchannel_destroy(p);
p = NULL;
}
}
return rc;
}
VISORCHANNEL *
visorchannel_create(HOSTADDRESS physaddr, ulong channelBytes, GUID guid)
{
return visorchannel_create_guts(physaddr, channelBytes, NULL, 0, guid,
FALSE);
}
VISORCHANNEL *
visorchannel_create_with_lock(HOSTADDRESS physaddr, ulong channelBytes,
GUID guid)
{
return visorchannel_create_guts(physaddr, channelBytes, NULL, 0, guid,
TRUE);
}
VISORCHANNEL *
visorchannel_create_overlapped(ulong channelBytes,
VISORCHANNEL *parent, ulong off, GUID guid)
{
return visorchannel_create_guts(0, channelBytes, parent, off, guid,
FALSE);
}
VISORCHANNEL *
visorchannel_create_overlapped_with_lock(ulong channelBytes,
VISORCHANNEL *parent, ulong off,
GUID guid)
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
visorchannel_GUID_id(GUID *guid, char *s)
{
return GUID_format1(guid, s);
}
char *
visorchannel_id(VISORCHANNEL *channel, char *s)
{
return visorchannel_GUID_id(&channel->guid, s);
}
char *
visorchannel_zoneid(VISORCHANNEL *channel, char *s)
{
return visorchannel_GUID_id(&channel->chan_hdr.ZoneGuid, s);
}
HOSTADDRESS
visorchannel_get_clientpartition(VISORCHANNEL *channel)
{
return channel->chan_hdr.PartitionHandle;
}
GUID
visorchannel_get_GUID(VISORCHANNEL *channel)
{
return channel->guid;
}
MEMREGION *
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
if ((rc >= 0) && (offset == 0) && (nbytes >= sizeof(CHANNEL_HEADER)))
memcpy(&channel->chan_hdr, local, sizeof(CHANNEL_HEADER));
return rc;
}
int
visorchannel_write(VISORCHANNEL *channel, ulong offset,
void *local, ulong nbytes)
{
if (offset == 0 && nbytes >= sizeof(CHANNEL_HEADER))
memcpy(&channel->chan_hdr, local, sizeof(CHANNEL_HEADER));
return visor_memregion_write(channel->memregion, offset, local, nbytes);
}
int
visorchannel_clear(VISORCHANNEL *channel, ulong offset, U8 ch, ulong nbytes)
{
int rc = -1;
int bufsize = 65536;
int written = 0;
U8 *buf = vmalloc(bufsize);
if (buf == NULL) {
ERRDRV("%s failed memory allocation", __func__);
goto Away;
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
goto Away;
}
written += thisbytes;
nbytes -= thisbytes;
}
rc = 0;
Away:
if (buf != NULL) {
vfree(buf);
buf = NULL;
}
return rc;
}
void *
visorchannel_get_header(VISORCHANNEL *channel)
{
return (void *) &(channel->chan_hdr);
}
static BOOL
sig_read_header(VISORCHANNEL *channel, U32 queue,
SIGNAL_QUEUE_HEADER *sig_hdr)
{
BOOL rc = FALSE;
if (channel->chan_hdr.oChannelSpace < sizeof(CHANNEL_HEADER)) {
ERRDRV("oChannelSpace too small: (status=%d)\n", rc);
goto Away;
}
if (visor_memregion_read(channel->memregion,
SIG_QUEUE_OFFSET(&channel->chan_hdr, queue),
sig_hdr, sizeof(SIGNAL_QUEUE_HEADER)) < 0) {
ERRDRV("queue=%d SIG_QUEUE_OFFSET=%d",
queue, (int)SIG_QUEUE_OFFSET(&channel->chan_hdr, queue));
ERRDRV("visor_memregion_read of signal queue failed: (status=%d)\n", rc);
goto Away;
}
rc = TRUE;
Away:
return rc;
}
static BOOL
sig_do_data(VISORCHANNEL *channel, U32 queue,
SIGNAL_QUEUE_HEADER *sig_hdr, U32 slot, void *data, BOOL is_write)
{
BOOL rc = FALSE;
int signal_data_offset = SIG_DATA_OFFSET(&channel->chan_hdr, queue,
sig_hdr, slot);
if (is_write) {
if (visor_memregion_write(channel->memregion,
signal_data_offset,
data, sig_hdr->SignalSize) < 0) {
ERRDRV("visor_memregion_write of signal data failed: (status=%d)\n", rc);
goto Away;
}
} else {
if (visor_memregion_read(channel->memregion, signal_data_offset,
data, sig_hdr->SignalSize) < 0) {
ERRDRV("visor_memregion_read of signal data failed: (status=%d)\n", rc);
goto Away;
}
}
rc = TRUE;
Away:
return rc;
}
static inline BOOL
sig_read_data(VISORCHANNEL *channel, U32 queue,
SIGNAL_QUEUE_HEADER *sig_hdr, U32 slot, void *data)
{
return sig_do_data(channel, queue, sig_hdr, slot, data, FALSE);
}
static inline BOOL
sig_write_data(VISORCHANNEL *channel, U32 queue,
SIGNAL_QUEUE_HEADER *sig_hdr, U32 slot, void *data)
{
return sig_do_data(channel, queue, sig_hdr, slot, data, TRUE);
}
static inline unsigned char
safe_sig_queue_validate(pSIGNAL_QUEUE_HEADER psafe_sqh,
pSIGNAL_QUEUE_HEADER punsafe_sqh,
U32 *phead, U32 *ptail)
{
if ((*phead >= psafe_sqh->MaxSignalSlots)
|| (*ptail >= psafe_sqh->MaxSignalSlots)) {
*phead = 0;
*ptail = 0;
punsafe_sqh->Head = *phead;
punsafe_sqh->Tail = *ptail;
ERRDRV("safe_sig_queue_validate: head = 0x%x, tail = 0x%x, MaxSlots = 0x%x",
*phead, *ptail, psafe_sqh->MaxSignalSlots);
return 0;
}
return 1;
}
BOOL
visorchannel_signalremove(VISORCHANNEL *channel, U32 queue, void *msg)
{
BOOL rc = FALSE;
SIGNAL_QUEUE_HEADER sig_hdr;
if (channel->needs_lock)
spin_lock(&channel->remove_lock);
if (!sig_read_header(channel, queue, &sig_hdr)) {
rc = FALSE;
goto Away;
}
if (sig_hdr.Head == sig_hdr.Tail) {
rc = FALSE;
goto Away;
}
sig_hdr.Tail = (sig_hdr.Tail + 1) % sig_hdr.MaxSignalSlots;
if (!sig_read_data(channel, queue, &sig_hdr, sig_hdr.Tail, msg)) {
ERRDRV("sig_read_data failed: (status=%d)\n", rc);
goto Away;
}
sig_hdr.NumSignalsReceived++;
MEMORYBARRIER;
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, Tail)) {
ERRDRV("visor_memregion_write of Tail failed: (status=%d)\n",
rc);
goto Away;
}
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, NumSignalsReceived)) {
ERRDRV("visor_memregion_write of NumSignalsReceived failed: (status=%d)\n", rc);
goto Away;
}
rc = TRUE;
Away:
if (channel->needs_lock)
spin_unlock(&channel->remove_lock);
return rc;
}
BOOL
visorchannel_signalinsert(VISORCHANNEL *channel, U32 queue, void *msg)
{
BOOL rc = FALSE;
SIGNAL_QUEUE_HEADER sig_hdr;
if (channel->needs_lock)
spin_lock(&channel->insert_lock);
if (!sig_read_header(channel, queue, &sig_hdr)) {
rc = FALSE;
goto Away;
}
sig_hdr.Head = ((sig_hdr.Head + 1) % sig_hdr.MaxSignalSlots);
if (sig_hdr.Head == sig_hdr.Tail) {
sig_hdr.NumOverflows++;
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, NumOverflows)) {
ERRDRV("visor_memregion_write of NumOverflows failed: (status=%d)\n", rc);
goto Away;
}
rc = FALSE;
goto Away;
}
if (!sig_write_data(channel, queue, &sig_hdr, sig_hdr.Head, msg)) {
ERRDRV("sig_write_data failed: (status=%d)\n", rc);
goto Away;
}
sig_hdr.NumSignalsSent++;
MEMORYBARRIER;
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, Head)) {
ERRDRV("visor_memregion_write of Head failed: (status=%d)\n",
rc);
goto Away;
}
if (!SIG_WRITE_FIELD(channel, queue, &sig_hdr, NumSignalsSent)) {
ERRDRV("visor_memregion_write of NumSignalsSent failed: (status=%d)\n", rc);
goto Away;
}
rc = TRUE;
Away:
if (channel->needs_lock)
spin_unlock(&channel->insert_lock);
return rc;
}
int
visorchannel_signalqueue_slots_avail(VISORCHANNEL *channel, U32 queue)
{
SIGNAL_QUEUE_HEADER sig_hdr;
U32 slots_avail, slots_used;
U32 head, tail;
if (!sig_read_header(channel, queue, &sig_hdr))
return 0;
head = sig_hdr.Head;
tail = sig_hdr.Tail;
if (head < tail)
head = head + sig_hdr.MaxSignalSlots;
slots_used = (head - tail);
slots_avail = sig_hdr.MaxSignals - slots_used;
return (int) slots_avail;
}
int
visorchannel_signalqueue_max_slots(VISORCHANNEL *channel, U32 queue)
{
SIGNAL_QUEUE_HEADER sig_hdr;
if (!sig_read_header(channel, queue, &sig_hdr))
return 0;
return (int) sig_hdr.MaxSignals;
}
static void
sigqueue_debug(SIGNAL_QUEUE_HEADER *q, int which, struct seq_file *seq)
{
seq_printf(seq, "Signal Queue #%d\n", which);
seq_printf(seq, " VersionId = %lu\n", (ulong) q->VersionId);
seq_printf(seq, " Type = %lu\n", (ulong) q->Type);
seq_printf(seq, " oSignalBase = %llu\n",
(long long) q->oSignalBase);
seq_printf(seq, " SignalSize = %lu\n", (ulong) q->SignalSize);
seq_printf(seq, " MaxSignalSlots = %lu\n",
(ulong) q->MaxSignalSlots);
seq_printf(seq, " MaxSignals = %lu\n", (ulong) q->MaxSignals);
seq_printf(seq, " FeatureFlags = %-16.16Lx\n",
(long long) q->FeatureFlags);
seq_printf(seq, " NumSignalsSent = %llu\n",
(long long) q->NumSignalsSent);
seq_printf(seq, " NumSignalsReceived = %llu\n",
(long long) q->NumSignalsReceived);
seq_printf(seq, " NumOverflows = %llu\n",
(long long) q->NumOverflows);
seq_printf(seq, " Head = %lu\n", (ulong) q->Head);
seq_printf(seq, " Tail = %lu\n", (ulong) q->Tail);
}
void
visorchannel_debug(VISORCHANNEL *channel, int nQueues,
struct seq_file *seq, U32 off)
{
HOSTADDRESS addr = 0;
ulong nbytes = 0, nbytes_region = 0;
MEMREGION *memregion = NULL;
CHANNEL_HEADER hdr;
CHANNEL_HEADER *phdr = &hdr;
char s[99];
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
phdr, sizeof(CHANNEL_HEADER));
if (errcode < 0) {
seq_printf(seq,
"Read of channel header failed with errcode=%d)\n",
errcode);
if (off == 0) {
phdr = &channel->chan_hdr;
seq_puts(seq, "(following data may be stale)\n");
} else
return;
}
nbytes = (ulong) (phdr->Size);
seq_printf(seq, "--- Begin channel @0x%-16.16Lx for 0x%lx bytes (region=0x%lx bytes) ---\n",
addr + off, nbytes, nbytes_region);
seq_printf(seq, "Type = %s\n", GUID_format2(&phdr->Type, s));
seq_printf(seq, "ZoneGuid = %s\n",
GUID_format2(&phdr->ZoneGuid, s));
seq_printf(seq, "Signature = 0x%-16.16Lx\n",
(long long) phdr->Signature);
seq_printf(seq, "LegacyState = %lu\n", (ulong) phdr->LegacyState);
seq_printf(seq, "SrvState = %lu\n", (ulong) phdr->SrvState);
seq_printf(seq, "CliStateBoot = %lu\n", (ulong) phdr->CliStateBoot);
seq_printf(seq, "CliStateOS = %lu\n", (ulong) phdr->CliStateOS);
seq_printf(seq, "HeaderSize = %lu\n", (ulong) phdr->HeaderSize);
seq_printf(seq, "Size = %llu\n", (long long) phdr->Size);
seq_printf(seq, "Features = 0x%-16.16llx\n",
(long long) phdr->Features);
seq_printf(seq, "PartitionHandle = 0x%-16.16llx\n",
(long long) phdr->PartitionHandle);
seq_printf(seq, "Handle = 0x%-16.16llx\n",
(long long) phdr->Handle);
seq_printf(seq, "VersionId = %lu\n", (ulong) phdr->VersionId);
seq_printf(seq, "oChannelSpace = %llu\n",
(long long) phdr->oChannelSpace);
if ((phdr->oChannelSpace == 0) || (errcode < 0))
;
else
for (i = 0; i < nQueues; i++) {
SIGNAL_QUEUE_HEADER q;
errcode = visorchannel_read(channel,
off + phdr->oChannelSpace +
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
fmtbuf = kmalloc(fmtbufsize, GFP_KERNEL|__GFP_NORETRY);
if (buf == NULL || fmtbuf == NULL)
goto Away;
errcode = visorchannel_read(chan, off, buf, len);
if (errcode < 0) {
ERRDRV("%s failed to read %s from channel errcode=%d",
s, __func__, errcode);
goto Away;
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
Away:
if (buf != NULL) {
kfree(buf);
buf = NULL;
}
if (fmtbuf != NULL) {
kfree(fmtbuf);
fmtbuf = NULL;
}
}
