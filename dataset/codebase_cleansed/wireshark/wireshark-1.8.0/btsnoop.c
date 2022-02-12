int btsnoop_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[sizeof btsnoop_magic];
struct btsnoop_hdr hdr;
int file_encap=WTAP_ENCAP_UNKNOWN;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
if (memcmp(magic, btsnoop_magic, sizeof btsnoop_magic) != 0) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, wth->fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
hdr.version = g_ntohl(hdr.version);
if (hdr.version != 1) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: version %u unsupported", hdr.version);
return -1;
}
hdr.datalink = g_ntohl(hdr.datalink);
switch (hdr.datalink) {
case KHciLoggerDatalinkTypeH1:
file_encap=WTAP_ENCAP_BLUETOOTH_HCI;
break;
case KHciLoggerDatalinkTypeBCSP:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: BCSP capture logs unsupported");
return -1;
case KHciLoggerDatalinkTypeH5:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: H5 capture logs unsupported");
return -1;
case KHciLoggerDatalinkTypeH4:
file_encap=WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("btsnoop: datalink type %u unknown or unsupported", hdr.datalink);
return -1;
}
wth->subtype_read = btsnoop_read;
wth->subtype_seek_read = btsnoop_seek_read;
wth->file_encap = file_encap;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
wth->file_type = WTAP_FILE_BTSNOOP;
return 1;
}
static gboolean btsnoop_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
guint32 packet_size;
guint32 flags;
guint32 orig_size;
int bytes_read;
struct btsnooprec_hdr hdr;
gint64 ts;
*data_offset = file_tell(wth->fh);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, wth->fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
packet_size = g_ntohl(hdr.incl_len);
orig_size = g_ntohl(hdr.orig_len);
flags = g_ntohl(hdr.flags);
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("btsnoop: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space(wth->frame_buffer, packet_size);
if (!snoop_read_rec_data(wth->fh, buffer_start_ptr(wth->frame_buffer),
packet_size, err, err_info)) {
return FALSE;
}
ts = GINT64_FROM_BE(hdr.ts_usec);
ts -= KUnixTimeBase;
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.ts.secs = (guint)(ts / 1000000);
wth->phdr.ts.nsecs = (guint)((ts % 1000000) * 1000);
wth->phdr.caplen = packet_size;
wth->phdr.len = orig_size;
if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR)
{
wth->pseudo_header.p2p.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
}
else if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_HCI)
{
wth->pseudo_header.bthci.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
if(flags & KHciLoggerCommandOrEvent)
{
if(wth->pseudo_header.bthci.sent)
{
wth->pseudo_header.bthci.channel = BTHCI_CHANNEL_COMMAND;
}
else
{
wth->pseudo_header.bthci.channel = BTHCI_CHANNEL_EVENT;
}
}
else
{
wth->pseudo_header.bthci.channel = BTHCI_CHANNEL_ACL;
}
}
return TRUE;
}
static gboolean btsnoop_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length,
int *err, gchar **err_info) {
int bytes_read;
struct btsnooprec_hdr hdr;
guint32 flags;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, wth->random_fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
flags = g_ntohl(hdr.flags);
if (!snoop_read_rec_data(wth->random_fh, pd, length, err, err_info))
return FALSE;
if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR)
{
pseudo_header->p2p.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
}
else if(wth->file_encap == WTAP_ENCAP_BLUETOOTH_HCI)
{
pseudo_header->bthci.sent = (flags & KHciLoggerControllerToHost) ? FALSE : TRUE;
if(flags & KHciLoggerCommandOrEvent)
{
if(pseudo_header->bthci.sent)
{
pseudo_header->bthci.channel = BTHCI_CHANNEL_COMMAND;
}
else
{
pseudo_header->bthci.channel = BTHCI_CHANNEL_EVENT;
}
}
else
{
pseudo_header->bthci.channel = BTHCI_CHANNEL_ACL;
}
}
return TRUE;
}
static gboolean
snoop_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err,
gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(pd, length, fh);
if (bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
int btsnoop_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap != WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR)
return WTAP_ERR_UNSUPPORTED_ENCAP;
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
static gboolean btsnoop_dump_partial_rec_hdr(wtap_dumper *wdh _U_,
const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header,
const guint8 *pd, int *err,
struct btsnooprec_hdr *rec_hdr)
{
gint64 ts_usec;
guint8 flags = 0;
if (!btsnoop_lookup_flags(*pd, pseudo_header->p2p.sent, &flags)) {
*err = WTAP_ERR_UNSUPPORTED;
return FALSE;
}
ts_usec = ((gint64) phdr->ts.secs * 1000000) + ((gint64) phdr->ts.nsecs / 1000);
ts_usec += KUnixTimeBase;
rec_hdr->flags = GUINT32_TO_BE(flags);
rec_hdr->cum_drops = GUINT32_TO_BE(0);
rec_hdr->ts_usec = GINT64_TO_BE(ts_usec);
return TRUE;
}
static gboolean btsnoop_dump_h1(wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header,
const guint8 *pd, int *err)
{
struct btsnooprec_hdr rec_hdr;
if (!btsnoop_dump_partial_rec_hdr(wdh, phdr, pseudo_header, pd, err, &rec_hdr))
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
const union wtap_pseudo_header *pseudo_header,
const guint8 *pd, int *err)
{
struct btsnooprec_hdr rec_hdr;
if (!btsnoop_dump_partial_rec_hdr(wdh, phdr, pseudo_header, pd, err, &rec_hdr))
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
wdh->subtype_close = NULL;
switch (wdh->file_type) {
case WTAP_FILE_BTSNOOP:
wdh->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
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
wdh->subtype_close = NULL;
switch (wdh->file_type) {
case WTAP_FILE_BTSNOOP:
wdh->tsprecision = WTAP_FILE_TSPREC_USEC;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
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
