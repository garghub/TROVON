wtap_open_return_val netmon_open(wtap *wth, int *err, gchar **err_info)
{
char magic[MAGIC_SIZE];
struct netmon_hdr hdr;
int file_type;
struct tm tm;
guint32 frame_table_offset;
guint32 frame_table_length;
guint32 frame_table_size;
guint32 *frame_table;
#ifdef WORDS_BIGENDIAN
unsigned int i;
#endif
netmon_t *netmon;
if (!wtap_read_bytes(wth->fh, magic, MAGIC_SIZE, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, netmon_1_x_magic, MAGIC_SIZE) != 0 &&
memcmp(magic, netmon_2_x_magic, MAGIC_SIZE) != 0) {
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &hdr, sizeof hdr, err, err_info))
return WTAP_OPEN_ERROR;
switch (hdr.ver_major) {
case 1:
file_type = WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x;
break;
case 2:
file_type = WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: major version %u unsupported", hdr.ver_major);
return WTAP_OPEN_ERROR;
}
hdr.network = pletoh16(&hdr.network);
if (hdr.network >= NUM_NETMON_ENCAPS
|| netmon_encap[hdr.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
hdr.network);
return WTAP_OPEN_ERROR;
}
wth->file_type_subtype = file_type;
netmon = (netmon_t *)g_malloc(sizeof(netmon_t));
wth->priv = (void *)netmon;
wth->subtype_read = netmon_read;
wth->subtype_seek_read = netmon_seek_read;
wth->subtype_sequential_close = netmon_sequential_close;
if((hdr.ver_major == 2 && hdr.ver_minor >= 1) || hdr.ver_major > 2)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
else
wth->file_encap = netmon_encap[hdr.network];
wth->snapshot_length = 0;
tm.tm_year = pletoh16(&hdr.ts_year) - 1900;
tm.tm_mon = pletoh16(&hdr.ts_month) - 1;
tm.tm_mday = pletoh16(&hdr.ts_day);
tm.tm_hour = pletoh16(&hdr.ts_hour);
tm.tm_min = pletoh16(&hdr.ts_min);
tm.tm_sec = pletoh16(&hdr.ts_sec);
tm.tm_isdst = -1;
netmon->start_secs = mktime(&tm);
netmon->start_nsecs = pletoh16(&hdr.ts_msec)*1000000;
netmon->version_major = hdr.ver_major;
netmon->version_minor = hdr.ver_minor;
netmon->frame_table_size = 0;
netmon->frame_table = NULL;
frame_table_offset = pletoh32(&hdr.frametableoffset);
frame_table_length = pletoh32(&hdr.frametablelength);
frame_table_size = frame_table_length / (guint32)sizeof (guint32);
if ((frame_table_size * sizeof (guint32)) != frame_table_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which is not a multiple of the size of an entry",
frame_table_length);
return WTAP_OPEN_ERROR;
}
if (frame_table_size == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which means it's less than one entry in size",
frame_table_length);
return WTAP_OPEN_ERROR;
}
if (frame_table_size > 512*1024*1024) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which is larger than we support",
frame_table_length);
return WTAP_OPEN_ERROR;
}
if (file_seek(wth->fh, frame_table_offset, SEEK_SET, err) == -1) {
return WTAP_OPEN_ERROR;
}
frame_table = (guint32 *)g_try_malloc(frame_table_length);
if (frame_table_length != 0 && frame_table == NULL) {
*err = ENOMEM;
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, frame_table, frame_table_length,
err, err_info)) {
g_free(frame_table);
return WTAP_OPEN_ERROR;
}
netmon->frame_table_size = frame_table_size;
netmon->frame_table = frame_table;
#ifdef WORDS_BIGENDIAN
for (i = 0; i < frame_table_size; i++)
frame_table[i] = pletoh32(&frame_table[i]);
#endif
netmon->current_frame = 0;
switch (netmon->version_major) {
case 1:
wth->file_tsprec = WTAP_TSPREC_MSEC;
break;
case 2:
wth->file_tsprec = WTAP_TSPREC_NSEC;
break;
}
return WTAP_OPEN_MINE;
}
static void
netmon_set_pseudo_header_info(struct wtap_pkthdr *phdr, Buffer *buf)
{
switch (phdr->pkt_encap) {
case WTAP_ENCAP_ATM_PDUS:
atm_guess_traffic_type(phdr, ws_buffer_start_ptr(buf));
break;
case WTAP_ENCAP_ETHERNET:
phdr->pseudo_header.eth.fcs_len = 0;
break;
case WTAP_ENCAP_IEEE_802_11_NETMON:
memset(&phdr->pseudo_header.ieee_802_11, 0, sizeof(phdr->pseudo_header.ieee_802_11));
phdr->pseudo_header.ieee_802_11.fcs_len = -2;
phdr->pseudo_header.ieee_802_11.decrypted = FALSE;
phdr->pseudo_header.ieee_802_11.datapad = FALSE;
phdr->pseudo_header.ieee_802_11.phy = PHDR_802_11_PHY_UNKNOWN;
break;
}
}
static process_record_retval
netmon_process_record(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
netmon_t *netmon = (netmon_t *)wth->priv;
int hdr_size = 0;
union {
struct netmonrec_1_x_hdr hdr_1_x;
struct netmonrec_2_x_hdr hdr_2_x;
} hdr;
gint64 delta = 0;
gint64 t;
time_t secs;
int nsecs;
guint32 packet_size = 0;
guint32 orig_size = 0;
int trlr_size;
union {
struct netmonrec_2_1_trlr trlr_2_1;
struct netmonrec_2_2_trlr trlr_2_2;
struct netmonrec_2_3_trlr trlr_2_3;
} trlr;
guint16 network;
int pkt_encap;
switch (netmon->version_major) {
case 1:
hdr_size = sizeof (struct netmonrec_1_x_hdr);
break;
case 2:
hdr_size = sizeof (struct netmonrec_2_x_hdr);
break;
}
if (!wtap_read_bytes_or_eof(fh, &hdr, hdr_size, err, err_info))
return FAILURE;
switch (netmon->version_major) {
case 1:
orig_size = pletoh16(&hdr.hdr_1_x.orig_len);
packet_size = pletoh16(&hdr.hdr_1_x.incl_len);
break;
case 2:
orig_size = pletoh32(&hdr.hdr_2_x.orig_len);
packet_size = pletoh32(&hdr.hdr_2_x.incl_len);
break;
}
if (packet_size > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE_STANDARD);
return FAILURE;
}
phdr->rec_type = REC_TYPE_PACKET;
switch (wth->file_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (packet_size < sizeof (struct netmon_atm_hdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: ATM file has a %u-byte packet, too small to have even an ATM pseudo-header",
packet_size);
return FAILURE;
}
if (!netmon_read_atm_pseudoheader(fh, &phdr->pseudo_header,
err, err_info))
return FAILURE;
orig_size -= (guint)sizeof (struct netmon_atm_hdr);
packet_size -= (guint)sizeof (struct netmon_atm_hdr);
break;
default:
break;
}
switch (netmon->version_major) {
case 1:
delta = ((gint64)pletoh32(&hdr.hdr_1_x.ts_delta))*1000000;
break;
case 2:
delta = pletoh64(&hdr.hdr_2_x.ts_delta)*10;
delta *= 100;
break;
}
secs = 0;
t = netmon->start_nsecs + delta;
while (t < 0) {
t += 1000000000;
secs--;
}
secs += (time_t)(t/1000000000);
nsecs = (int)(t%1000000000);
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = netmon->start_secs + secs;
phdr->ts.nsecs = nsecs;
phdr->caplen = packet_size;
phdr->len = orig_size;
if (!wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info))
return FAILURE;
if ((netmon->version_major == 2 && netmon->version_minor >= 1) ||
netmon->version_major > 2) {
if (netmon->version_major > 2) {
trlr_size = (int)sizeof (struct netmonrec_2_3_trlr);
} else {
switch (netmon->version_minor) {
case 1:
trlr_size = (int)sizeof (struct netmonrec_2_1_trlr);
break;
case 2:
trlr_size = (int)sizeof (struct netmonrec_2_2_trlr);
break;
default:
trlr_size = (int)sizeof (struct netmonrec_2_3_trlr);
break;
}
}
if (!wtap_read_bytes(fh, &trlr, trlr_size, err, err_info))
return FAILURE;
network = pletoh16(trlr.trlr_2_1.network);
if ((network & 0xF000) == NETMON_NET_PCAP_BASE) {
network &= 0x0FFF;
pkt_encap = wtap_pcap_encap_to_wtap_encap(network);
if (pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: converted pcap network type %u unknown or unsupported",
network);
return FAILURE;
}
} else if (network < NUM_NETMON_ENCAPS) {
pkt_encap = netmon_encap[network];
if (pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
network);
return FAILURE;
}
} else {
switch (network) {
case NETMON_NET_NETEVENT:
return RETRY;
case NETMON_NET_NETWORK_INFO_EX:
return RETRY;
case NETMON_NET_PAYLOAD_HEADER:
return RETRY;
case NETMON_NET_NETWORK_INFO:
return RETRY;
case NETMON_NET_DNS_CACHE:
return RETRY;
case NETMON_NET_NETMON_FILTER:
return RETRY;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
network);
return FAILURE;
}
}
phdr->pkt_encap = pkt_encap;
if (netmon->version_major > 2 || netmon->version_minor > 2) {
guint64 d;
d = pletoh64(trlr.trlr_2_3.utc_timestamp);
if (!filetime_to_nstime(&phdr->ts, d)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netmon: time stamp outside supported range");
return FAILURE;
}
}
}
netmon_set_pseudo_header_info(phdr, buf);
return SUCCESS;
}
static gboolean netmon_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
netmon_t *netmon = (netmon_t *)wth->priv;
gint64 rec_offset;
for (;;) {
if (netmon->current_frame >= netmon->frame_table_size) {
g_free(netmon->frame_table);
netmon->frame_table = NULL;
*err = 0;
return FALSE;
}
rec_offset = netmon->frame_table[netmon->current_frame];
if (file_tell(wth->fh) != rec_offset) {
if (file_seek(wth->fh, rec_offset, SEEK_SET, err) == -1)
return FALSE;
}
netmon->current_frame++;
*data_offset = file_tell(wth->fh);
switch (netmon_process_record(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info)) {
case RETRY:
continue;
case SUCCESS:
return TRUE;
case FAILURE:
return FALSE;
}
}
}
static gboolean
netmon_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
switch (netmon_process_record(wth, wth->random_fh, phdr, buf, err,
err_info)) {
default:
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netmon: saw metadata in netmon_seek_read");
return FALSE;
case SUCCESS:
return TRUE;
case FAILURE:
return FALSE;
}
}
static gboolean
netmon_read_atm_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info)
{
struct netmon_atm_hdr atm_phdr;
guint16 vpi, vci;
if (!wtap_read_bytes(fh, &atm_phdr, sizeof (struct netmon_atm_hdr),
err, err_info))
return FALSE;
vpi = g_ntohs(atm_phdr.vpi);
vci = g_ntohs(atm_phdr.vci);
pseudo_header->atm.vpi = vpi;
pseudo_header->atm.vci = vci;
pseudo_header->atm.flags = 0;
pseudo_header->atm.channel = 0;
pseudo_header->atm.cells = 0;
pseudo_header->atm.aal5t_u2u = 0;
pseudo_header->atm.aal5t_len = 0;
pseudo_header->atm.aal5t_chksum = 0;
return TRUE;
}
static void
netmon_sequential_close(wtap *wth)
{
netmon_t *netmon = (netmon_t *)wth->priv;
if (netmon->frame_table != NULL) {
g_free(netmon->frame_table);
netmon->frame_table = NULL;
}
}
int netmon_dump_can_write_encap_1_x(int encap)
{
if (encap < 0 || (unsigned) encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
int netmon_dump_can_write_encap_2_x(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return 0;
if (encap < 0 || (unsigned) encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
gboolean netmon_dump_open(wtap_dumper *wdh, int *err)
{
netmon_dump_t *netmon;
if (wtap_dump_file_seek(wdh, CAPTUREFILE_HEADER_SIZE, SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = netmon_dump;
wdh->subtype_finish = netmon_dump_finish;
netmon = (netmon_dump_t *)g_malloc(sizeof(netmon_dump_t));
wdh->priv = (void *)netmon;
netmon->frame_table_offset = CAPTUREFILE_HEADER_SIZE;
netmon->got_first_record_time = FALSE;
netmon->frame_table = NULL;
netmon->frame_table_index = 0;
netmon->frame_table_size = 0;
netmon->no_more_room = FALSE;
return TRUE;
}
static gboolean netmon_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err, gchar **err_info _U_)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
netmon_dump_t *netmon = (netmon_dump_t *)wdh->priv;
struct netmonrec_1_x_hdr rec_1_x_hdr;
struct netmonrec_2_x_hdr rec_2_x_hdr;
void *hdrp;
size_t rec_size;
struct netmonrec_2_1_trlr rec_2_x_trlr;
size_t hdr_size;
struct netmon_atm_hdr atm_hdr;
int atm_hdrsize;
gint64 secs;
gint32 nsecs;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x:
if (phdr->caplen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
break;
case WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x:
if (phdr->caplen > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
break;
default:
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
if (wdh->encap == WTAP_ENCAP_PER_PACKET) {
if (phdr->pkt_encap < 0 ||
(unsigned) phdr->pkt_encap >= NUM_WTAP_ENCAPS ||
wtap_encap[phdr->pkt_encap] == -1) {
*err = WTAP_ERR_UNWRITABLE_ENCAP;
return FALSE;
}
phtoles(rec_2_x_trlr.network, wtap_encap[phdr->pkt_encap]);
}
if (netmon->no_more_room) {
*err = EFBIG;
return FALSE;
}
if (!netmon->got_first_record_time) {
netmon->first_record_time.secs = phdr->ts.secs;
netmon->first_record_time.nsecs =
(phdr->ts.nsecs/1000000)*1000000;
netmon->got_first_record_time = TRUE;
}
if (wdh->encap == WTAP_ENCAP_ATM_PDUS)
atm_hdrsize = sizeof (struct netmon_atm_hdr);
else
atm_hdrsize = 0;
secs = (gint64)(phdr->ts.secs - netmon->first_record_time.secs);
nsecs = phdr->ts.nsecs - netmon->first_record_time.nsecs;
while (nsecs < 0) {
nsecs += 1000000000;
secs--;
}
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x:
rec_1_x_hdr.ts_delta = GUINT32_TO_LE(secs*1000 + (nsecs + 500000)/1000000);
rec_1_x_hdr.orig_len = GUINT16_TO_LE(phdr->len + atm_hdrsize);
rec_1_x_hdr.incl_len = GUINT16_TO_LE(phdr->caplen + atm_hdrsize);
hdrp = &rec_1_x_hdr;
hdr_size = sizeof rec_1_x_hdr;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x:
rec_2_x_hdr.ts_delta = GUINT64_TO_LE(secs*1000000 + (nsecs + 500)/1000);
rec_2_x_hdr.orig_len = GUINT32_TO_LE(phdr->len + atm_hdrsize);
rec_2_x_hdr.incl_len = GUINT32_TO_LE(phdr->caplen + atm_hdrsize);
hdrp = &rec_2_x_hdr;
hdr_size = sizeof rec_2_x_hdr;
break;
default:
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
rec_size = 0;
if (!wtap_dump_file_write(wdh, hdrp, hdr_size, err))
return FALSE;
rec_size += hdr_size;
if (wdh->encap == WTAP_ENCAP_ATM_PDUS) {
memset(&atm_hdr.dest, 0, sizeof atm_hdr.dest);
memset(&atm_hdr.src, 0, sizeof atm_hdr.src);
atm_hdr.vpi = g_htons(pseudo_header->atm.vpi);
atm_hdr.vci = g_htons(pseudo_header->atm.vci);
if (!wtap_dump_file_write(wdh, &atm_hdr, sizeof atm_hdr, err))
return FALSE;
rec_size += sizeof atm_hdr;
}
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
rec_size += phdr->caplen;
if (wdh->encap == WTAP_ENCAP_PER_PACKET) {
if (!wtap_dump_file_write(wdh, &rec_2_x_trlr,
sizeof rec_2_x_trlr, err))
return FALSE;
rec_size += sizeof rec_2_x_trlr;
}
if (netmon->frame_table_size == 0) {
netmon->frame_table = (guint32 *)g_malloc(1024 * sizeof *netmon->frame_table);
netmon->frame_table_size = 1024;
} else {
if (netmon->frame_table_index >= netmon->frame_table_size) {
netmon->frame_table_size *= 2;
netmon->frame_table = (guint32 *)g_realloc(netmon->frame_table,
netmon->frame_table_size * sizeof *netmon->frame_table);
}
}
netmon->frame_table[netmon->frame_table_index] =
GUINT32_TO_LE(netmon->frame_table_offset);
if ((guint64)netmon->frame_table_offset + rec_size > G_MAXUINT32) {
netmon->no_more_room = TRUE;
}
netmon->frame_table_index++;
netmon->frame_table_offset += (guint32) rec_size;
return TRUE;
}
static gboolean netmon_dump_finish(wtap_dumper *wdh, int *err)
{
netmon_dump_t *netmon = (netmon_dump_t *)wdh->priv;
size_t n_to_write;
struct netmon_hdr file_hdr;
const char *magicp;
size_t magic_size;
struct tm *tm;
n_to_write = netmon->frame_table_index * sizeof *netmon->frame_table;
if (!wtap_dump_file_write(wdh, netmon->frame_table, n_to_write, err))
return FALSE;
if (wtap_dump_file_seek(wdh, 0, SEEK_SET, err) == -1)
return FALSE;
memset(&file_hdr, '\0', sizeof file_hdr);
switch (wdh->file_type_subtype) {
case WTAP_FILE_TYPE_SUBTYPE_NETMON_1_x:
magicp = netmon_1_x_magic;
magic_size = sizeof netmon_1_x_magic;
file_hdr.ver_major = 1;
file_hdr.ver_minor = 1;
break;
case WTAP_FILE_TYPE_SUBTYPE_NETMON_2_x:
magicp = netmon_2_x_magic;
magic_size = sizeof netmon_2_x_magic;
file_hdr.ver_major = 2;
file_hdr.ver_minor =
(wdh->encap == WTAP_ENCAP_PER_PACKET) ? 1 : 0;
break;
default:
if (err != NULL)
*err = WTAP_ERR_UNWRITABLE_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, magicp, magic_size, err))
return FALSE;
if (wdh->encap == WTAP_ENCAP_PER_PACKET) {
file_hdr.network = GUINT16_TO_LE(1);
} else
file_hdr.network = GUINT16_TO_LE(wtap_encap[wdh->encap]);
tm = localtime(&netmon->first_record_time.secs);
if (tm != NULL) {
file_hdr.ts_year = GUINT16_TO_LE(1900 + tm->tm_year);
file_hdr.ts_month = GUINT16_TO_LE(tm->tm_mon + 1);
file_hdr.ts_dow = GUINT16_TO_LE(tm->tm_wday);
file_hdr.ts_day = GUINT16_TO_LE(tm->tm_mday);
file_hdr.ts_hour = GUINT16_TO_LE(tm->tm_hour);
file_hdr.ts_min = GUINT16_TO_LE(tm->tm_min);
file_hdr.ts_sec = GUINT16_TO_LE(tm->tm_sec);
} else {
file_hdr.ts_year = GUINT16_TO_LE(1900 + 0);
file_hdr.ts_month = GUINT16_TO_LE(0 + 1);
file_hdr.ts_dow = GUINT16_TO_LE(0);
file_hdr.ts_day = GUINT16_TO_LE(0);
file_hdr.ts_hour = GUINT16_TO_LE(0);
file_hdr.ts_min = GUINT16_TO_LE(0);
file_hdr.ts_sec = GUINT16_TO_LE(0);
}
file_hdr.ts_msec = GUINT16_TO_LE(netmon->first_record_time.nsecs/1000000);
file_hdr.frametableoffset = GUINT32_TO_LE(netmon->frame_table_offset);
file_hdr.frametablelength =
GUINT32_TO_LE(netmon->frame_table_index * sizeof *netmon->frame_table);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
return TRUE;
}
