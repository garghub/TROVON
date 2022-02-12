wtap_open_return_val btsnoop_open(wtap *wth, int *err, gchar **err_info)
{
char magic[sizeof btsnoop_magic];
struct btsnoop_hdr hdr;
int file_encap=WTAP_ENCAP_UNKNOWN;
if (!wtap_read_bytes(wth->fh, magic, sizeof magic, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, btsnoop_magic, sizeof btsnoop_magic) != 0) {
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &hdr, sizeof hdr, err, err_info))
return WTAP_OPEN_ERROR;
hdr.version = g_ntohl(hdr.version);
if (hdr.version != 1) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: version %u unsupported", hdr.version);
return WTAP_OPEN_ERROR;
}
hdr.datalink = g_ntohl(hdr.datalink);
switch (hdr.datalink) {
case KHciLoggerDatalinkTypeH1:
file_encap=WTAP_ENCAP_BLUETOOTH_HCI;
break;
case KHciLoggerDatalinkTypeH4:
file_encap=WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR;
break;
case KHciLoggerDatalinkTypeBCSP:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: BCSP capture logs unsupported");
return WTAP_OPEN_ERROR;
case KHciLoggerDatalinkTypeH5:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: H5 capture logs unsupported");
return WTAP_OPEN_ERROR;
case KHciLoggerDatalinkLinuxMonitor:
file_encap=WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR;
break;
case KHciLoggerDatalinkBlueZ5Simulator:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: BlueZ 5 Simulator capture logs unsupported");
return WTAP_OPEN_ERROR;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: datalink type %u unknown or unsupported", hdr.datalink);
return WTAP_OPEN_ERROR;
}
wth->subtype_read = btsnoop_read;
wth->subtype_seek_read = btsnoop_seek_read;
wth->file_encap = file_encap;
wth->snapshot_length = 0;
wth->file_tsprec = WTAP_TSPREC_USEC;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_BTSNOOP;
return WTAP_OPEN_MINE;
}
static gboolean btsnoop_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return btsnoop_read_record(wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean btsnoop_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return btsnoop_read_record(wth, wth->random_fh, phdr, buf, err, err_info);
}
static gboolean btsnoop_read_record(wtap *wth, FILE_T fh,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
struct btsnooprec_hdr hdr;
guint32 packet_size;
guint32 flags;
guint32 orig_size;
gint64 ts;
if (!wtap_read_bytes_or_eof(fh, &hdr, sizeof hdr, err, err_info))
return FALSE;
packet_size = g_ntohl(hdr.incl_len);
orig_size = g_ntohl(hdr.orig_len);
flags = g_ntohl(hdr.flags);
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("btsnoop: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
ts = GINT64_FROM_BE(hdr.ts_usec);
ts -= KUnixTimeBase;
phdr->rec_type = REC_TYPE_PACKET;
phdr->pkt_encap = wth->file_encap;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = (guint)(ts / 1000000);
phdr->ts.nsecs = (guint)((ts % 1000000) * 1000);
phdr->caplen = packet_size;
phdr->len = orig_size;
if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR)
{
phdr->pseudo_header.p2p.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
} else if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_HCI) {
phdr->pseudo_header.bthci.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
if(flags & KHciLoggerCommandOrEvent)
{
if(phdr->pseudo_header.bthci.sent)
{
phdr->pseudo_header.bthci.channel = BTHCI_CHANNEL_COMMAND;
}
else
{
phdr->pseudo_header.bthci.channel = BTHCI_CHANNEL_EVENT;
}
}
else
{
phdr->pseudo_header.bthci.channel = BTHCI_CHANNEL_ACL;
}
} else if (wth->file_encap == WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR) {
phdr->pseudo_header.btmon.opcode = flags & 0xFFFF;
phdr->pseudo_header.btmon.adapter_id = flags >> 16;
}
return wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info);
}
int btsnoop_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap != WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR && encap != WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
static guint8 btsnoop_lookup_flags(guint8 hci_type, gboolean sent, guint8 *flags)
{
guint8 i;
for (i=0; i < G_N_ELEMENTS(hci_flags); ++i)
{
if (hci_flags[i].hci_type == hci_type &&
hci_flags[i].sent == sent)
{
*flags = hci_flags[i].flags;
return TRUE;
}
}
return FALSE;
}
static gboolean btsnoop_format_partial_rec_hdr(
const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header,
const guint8 *pd, int *err, gchar **err_info,
struct btsnooprec_hdr *rec_hdr)
{
gint64 ts_usec;
gint64 nsecs;
guint8 flags = 0;
if (!btsnoop_lookup_flags(*pd, pseudo_header->p2p.sent, &flags)) {
*err = WTAP_ERR_UNWRITABLE_REC_DATA;
*err_info = g_strdup_printf("btsnoop: hci_type 0x%02x for %s data isn't supported",
*pd,
pseudo_header->p2p.sent ? "sent" : "received");
return FALSE;
}
nsecs = phdr->ts.nsecs;
ts_usec = ((gint64) phdr->ts.secs * 1000000) + (nsecs / 1000);
ts_usec += KUnixTimeBase;
rec_hdr->flags = GUINT32_TO_BE(flags);
rec_hdr->cum_drops = GUINT32_TO_BE(0);
rec_hdr->ts_usec = GINT64_TO_BE(ts_usec);
return TRUE;
}
static gboolean btsnoop_dump_h1(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct btsnooprec_hdr rec_hdr;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen-1 > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (!btsnoop_format_partial_rec_hdr(phdr, pseudo_header, pd, err, err_info,
&rec_hdr))
return FALSE;
rec_hdr.incl_len = GUINT32_TO_BE(phdr->caplen-1);
rec_hdr.orig_len = GUINT32_TO_BE(phdr->len-1);
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof rec_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof rec_hdr;
++pd;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen-1, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen-1;
return TRUE;
}
static gboolean btsnoop_dump_h4(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
struct btsnooprec_hdr rec_hdr;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (!btsnoop_format_partial_rec_hdr(phdr, pseudo_header, pd, err, err_info,
&rec_hdr))
return FALSE;
rec_hdr.incl_len = GUINT32_TO_BE(phdr->caplen);
rec_hdr.orig_len = GUINT32_TO_BE(phdr->len);
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof rec_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof rec_hdr;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
wdh->bytes_dumped += phdr->caplen;
return TRUE;
}
gboolean btsnoop_dump_open_h1(wtap_dumper *wdh, int *err)
{
struct btsnoop_hdr file_hdr;
wdh->subtype_write = btsnoop_dump_h1;
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_BTSNOOP:
wdh->tsprecision = WTAP_TSPREC_USEC;
break;
default:
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, btsnoop_magic, sizeof btsnoop_magic, err))
return FALSE;
wdh->bytes_dumped += sizeof btsnoop_magic;
file_hdr.version = GUINT32_TO_BE(1);
file_hdr.datalink = GUINT32_TO_BE(KHciLoggerDatalinkTypeH1);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof file_hdr;
return TRUE;
}
gboolean btsnoop_dump_open_h4(wtap_dumper *wdh, int *err)
{
struct btsnoop_hdr file_hdr;
wdh->subtype_write = btsnoop_dump_h4;
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_BTSNOOP:
wdh->tsprecision = WTAP_TSPREC_USEC;
break;
default:
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, btsnoop_magic, sizeof btsnoop_magic, err))
return FALSE;
wdh->bytes_dumped += sizeof btsnoop_magic;
file_hdr.version = GUINT32_TO_BE(1);
file_hdr.datalink = GUINT32_TO_BE(KHciLoggerDatalinkTypeH4);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
wdh->bytes_dumped += sizeof file_hdr;
return TRUE;
}
