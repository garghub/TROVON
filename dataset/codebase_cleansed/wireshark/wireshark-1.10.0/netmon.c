int netmon_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
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
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, MAGIC_SIZE, wth->fh);
if (bytes_read != MAGIC_SIZE) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (memcmp(magic, netmon_1_x_magic, MAGIC_SIZE) != 0 &&
memcmp(magic, netmon_2_x_magic, MAGIC_SIZE) != 0) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof hdr, wth->fh);
if (bytes_read != sizeof hdr) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
switch (hdr.ver_major) {
case 1:
file_type = WTAP_FILE_NETMON_1_x;
break;
case 2:
file_type = WTAP_FILE_NETMON_2_x;
break;
default:
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("netmon: major version %u unsupported", hdr.ver_major);
return -1;
}
hdr.network = pletohs(&hdr.network);
if (hdr.network >= NUM_NETMON_ENCAPS
|| netmon_encap[hdr.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
hdr.network);
return -1;
}
wth->file_type = file_type;
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
tm.tm_year = pletohs(&hdr.ts_year) - 1900;
tm.tm_mon = pletohs(&hdr.ts_month) - 1;
tm.tm_mday = pletohs(&hdr.ts_day);
tm.tm_hour = pletohs(&hdr.ts_hour);
tm.tm_min = pletohs(&hdr.ts_min);
tm.tm_sec = pletohs(&hdr.ts_sec);
tm.tm_isdst = -1;
netmon->start_secs = mktime(&tm);
netmon->start_nsecs = pletohs(&hdr.ts_msec)*1000000;
netmon->version_major = hdr.ver_major;
netmon->version_minor = hdr.ver_minor;
frame_table_offset = pletohl(&hdr.frametableoffset);
frame_table_length = pletohl(&hdr.frametablelength);
frame_table_size = frame_table_length / (guint32)sizeof (guint32);
if ((frame_table_size * sizeof (guint32)) != frame_table_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which is not a multiple of the size of an entry",
frame_table_length);
return -1;
}
if (frame_table_size == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which means it's less than one entry in size",
frame_table_length);
return -1;
}
if (frame_table_size > 512*1024*1024) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: frame table length is %u, which is larger than we support",
frame_table_length);
return -1;
}
if (file_seek(wth->fh, frame_table_offset, SEEK_SET, err) == -1) {
return -1;
}
frame_table = (guint32 *)g_malloc(frame_table_length);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(frame_table, frame_table_length, wth->fh);
if ((guint32)bytes_read != frame_table_length) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
g_free(frame_table);
return -1;
}
netmon->frame_table_size = frame_table_size;
netmon->frame_table = frame_table;
#ifdef WORDS_BIGENDIAN
for (i = 0; i < frame_table_size; i++)
frame_table[i] = pletohl(&frame_table[i]);
#endif
netmon->current_frame = 0;
switch (netmon->version_major) {
case 1:
wth->tsprecision = WTAP_FILE_TSPREC_MSEC;
break;
case 2:
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
break;
}
return 1;
}
static size_t
netmon_trailer_size(netmon_t *netmon)
{
if ((netmon->version_major == 2 && netmon->version_minor >= 1) ||
netmon->version_major > 2) {
if (netmon->version_major > 2) {
return sizeof (struct netmonrec_2_3_trlr);
} else {
switch (netmon->version_minor) {
case 1:
return sizeof (struct netmonrec_2_1_trlr);
case 2:
return sizeof (struct netmonrec_2_2_trlr);
default:
return sizeof (struct netmonrec_2_3_trlr);
}
}
}
return 0;
}
static void
netmon_set_pseudo_header_info(int pkt_encap,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length)
{
switch (pkt_encap) {
case WTAP_ENCAP_ATM_PDUS:
atm_guess_traffic_type(pd, length, pseudo_header);
break;
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
case WTAP_ENCAP_IEEE_802_11_NETMON:
pseudo_header->ieee_802_11.fcs_len = -2;
pseudo_header->ieee_802_11.decrypted = FALSE;
break;
}
}
static gboolean netmon_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
netmon_t *netmon = (netmon_t *)wth->priv;
guint32 packet_size = 0;
guint32 orig_size = 0;
int bytes_read;
union {
struct netmonrec_1_x_hdr hdr_1_x;
struct netmonrec_2_x_hdr hdr_2_x;
} hdr;
int hdr_size = 0;
int trlr_size;
gint64 rec_offset;
guint8 *data_ptr;
gint64 delta = 0;
gint64 t;
time_t secs;
guint32 nsecs;
again:
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
switch (netmon->version_major) {
case 1:
hdr_size = sizeof (struct netmonrec_1_x_hdr);
break;
case 2:
hdr_size = sizeof (struct netmonrec_2_x_hdr);
break;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, hdr_size, wth->fh);
if (bytes_read != hdr_size) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
switch (netmon->version_major) {
case 1:
orig_size = pletohs(&hdr.hdr_1_x.orig_len);
packet_size = pletohs(&hdr.hdr_1_x.incl_len);
break;
case 2:
orig_size = pletohl(&hdr.hdr_2_x.orig_len);
packet_size = pletohl(&hdr.hdr_2_x.incl_len);
break;
}
if (packet_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: File has %u-byte packet, bigger than maximum of %u",
packet_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
*data_offset = file_tell(wth->fh);
switch (wth->file_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (packet_size < sizeof (struct netmon_atm_hdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netmon: ATM file has a %u-byte packet, too small to have even an ATM pseudo-header",
packet_size);
return FALSE;
}
if (!netmon_read_atm_pseudoheader(wth->fh, &wth->phdr.pseudo_header,
err, err_info))
return FALSE;
orig_size -= (guint)sizeof (struct netmon_atm_hdr);
packet_size -= (guint)sizeof (struct netmon_atm_hdr);
break;
default:
break;
}
buffer_assure_space(wth->frame_buffer, packet_size);
data_ptr = buffer_start_ptr(wth->frame_buffer);
if (!netmon_read_rec_data(wth->fh, data_ptr, packet_size, err,
err_info))
return FALSE;
switch (netmon->version_major) {
case 1:
delta = ((gint64)pletohl(&hdr.hdr_1_x.ts_delta))*1000000;
break;
case 2:
delta = pletohll(&hdr.hdr_2_x.ts_delta)*10;
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
nsecs = (guint32)(t%1000000000);
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.ts.secs = netmon->start_secs + secs;
wth->phdr.ts.nsecs = nsecs;
wth->phdr.caplen = packet_size;
wth->phdr.len = orig_size;
trlr_size = (int)netmon_trailer_size(netmon);
if (trlr_size != 0) {
wth->phdr.pkt_encap = netmon_read_rec_trailer(wth->fh,
trlr_size, err, err_info);
if (wth->phdr.pkt_encap == -1)
return FALSE;
if (wth->phdr.pkt_encap == 0)
goto again;
netmon_set_pseudo_header_info(wth->phdr.pkt_encap,
&wth->phdr.pseudo_header, data_ptr, packet_size);
} else {
netmon_set_pseudo_header_info(wth->file_encap,
&wth->phdr.pseudo_header, data_ptr, packet_size);
}
return TRUE;
}
static gboolean
netmon_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, guint8 *pd, int length,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
netmon_t *netmon = (netmon_t *)wth->priv;
int trlr_size;
int pkt_encap;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
switch (wth->file_encap) {
case WTAP_ENCAP_ATM_PDUS:
if (!netmon_read_atm_pseudoheader(wth->random_fh, pseudo_header,
err, err_info)) {
return FALSE;
}
break;
}
if (!netmon_read_rec_data(wth->random_fh, pd, length, err, err_info))
return FALSE;
trlr_size = (int)netmon_trailer_size(netmon);
if (trlr_size != 0) {
pkt_encap = netmon_read_rec_trailer(wth->random_fh,
trlr_size, err, err_info);
if (pkt_encap == -1)
return FALSE;
if (pkt_encap == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netmon: saw metadata in netmon_seek_read");
return FALSE;
}
netmon_set_pseudo_header_info(pkt_encap, pseudo_header,
pd, length);
} else {
netmon_set_pseudo_header_info(wth->file_encap, pseudo_header,
pd, length);
}
return TRUE;
}
static gboolean
netmon_read_atm_pseudoheader(FILE_T fh, union wtap_pseudo_header *pseudo_header,
int *err, gchar **err_info)
{
struct netmon_atm_hdr atm_phdr;
int bytes_read;
guint16 vpi, vci;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&atm_phdr, sizeof (struct netmon_atm_hdr), fh);
if (bytes_read != sizeof (struct netmon_atm_hdr)) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
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
static gboolean
netmon_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err,
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
static int
netmon_read_rec_trailer(FILE_T fh, int trlr_size, int *err, gchar **err_info)
{
int bytes_read;
union {
struct netmonrec_2_1_trlr trlr_2_1;
struct netmonrec_2_2_trlr trlr_2_2;
struct netmonrec_2_3_trlr trlr_2_3;
} trlr;
guint16 network;
int pkt_encap;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&trlr, trlr_size, fh);
if (bytes_read != trlr_size) {
*err = file_error(fh, err_info);
if (*err == 0 && bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
network = pletohs(trlr.trlr_2_1.network);
if ((network & 0xF000) == NETMON_NET_PCAP_BASE) {
network &= 0x0FFF;
pkt_encap = wtap_pcap_encap_to_wtap_encap(network);
if (pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netmon: converted pcap network type %u unknown or unsupported",
network);
return -1;
}
} else if (network < NUM_NETMON_ENCAPS) {
pkt_encap = netmon_encap[network];
if (pkt_encap == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
network);
return -1;
}
} else {
switch (network) {
case NETMON_NET_NETEVENT:
case NETMON_NET_NETWORK_INFO_EX:
case NETMON_NET_PAYLOAD_HEADER:
case NETMON_NET_NETWORK_INFO:
case NETMON_NET_DNS_CACHE:
case NETMON_NET_NETMON_FILTER:
return 0;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("netmon: network type %u unknown or unsupported",
network);
return -1;
}
}
return pkt_encap;
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
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
int netmon_dump_can_write_encap_2_x(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return 0;
if (encap < 0 || (unsigned) encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean netmon_dump_open(wtap_dumper *wdh, int *err)
{
netmon_dump_t *netmon;
if (wtap_dump_file_seek(wdh, CAPTUREFILE_HEADER_SIZE, SEEK_SET, err) == -1)
return FALSE;
wdh->subtype_write = netmon_dump;
wdh->subtype_close = netmon_dump_close;
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
const guint8 *pd, int *err)
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
if (wdh->encap == WTAP_ENCAP_PER_PACKET) {
if (phdr->pkt_encap < 0 ||
(unsigned) phdr->pkt_encap >= NUM_WTAP_ENCAPS ||
wtap_encap[phdr->pkt_encap] == -1) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
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
switch (wdh->file_type) {
case WTAP_FILE_NETMON_1_x:
rec_1_x_hdr.ts_delta = htolel(secs*1000 + (nsecs + 500000)/1000000);
rec_1_x_hdr.orig_len = htoles(phdr->len + atm_hdrsize);
rec_1_x_hdr.incl_len = htoles(phdr->caplen + atm_hdrsize);
hdrp = &rec_1_x_hdr;
hdr_size = sizeof rec_1_x_hdr;
break;
case WTAP_FILE_NETMON_2_x:
rec_2_x_hdr.ts_delta = htolell(secs*1000000 + (nsecs + 500)/1000);
rec_2_x_hdr.orig_len = htolel(phdr->len + atm_hdrsize);
rec_2_x_hdr.incl_len = htolel(phdr->caplen + atm_hdrsize);
hdrp = &rec_2_x_hdr;
hdr_size = sizeof rec_2_x_hdr;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
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
htolel(netmon->frame_table_offset);
if ((guint64)netmon->frame_table_offset + rec_size > G_MAXUINT32) {
netmon->no_more_room = TRUE;
}
netmon->frame_table_index++;
netmon->frame_table_offset += (guint32) rec_size;
return TRUE;
}
static gboolean netmon_dump_close(wtap_dumper *wdh, int *err)
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
switch (wdh->file_type) {
case WTAP_FILE_NETMON_1_x:
magicp = netmon_1_x_magic;
magic_size = sizeof netmon_1_x_magic;
file_hdr.ver_major = 1;
file_hdr.ver_minor = 1;
break;
case WTAP_FILE_NETMON_2_x:
magicp = netmon_2_x_magic;
magic_size = sizeof netmon_2_x_magic;
file_hdr.ver_major = 2;
file_hdr.ver_minor =
(wdh->encap == WTAP_ENCAP_PER_PACKET) ? 1 : 0;
break;
default:
if (err != NULL)
*err = WTAP_ERR_UNSUPPORTED_FILE_TYPE;
return FALSE;
}
if (!wtap_dump_file_write(wdh, magicp, magic_size, err))
return FALSE;
if (wdh->encap == WTAP_ENCAP_PER_PACKET) {
file_hdr.network = htoles(1);
} else
file_hdr.network = htoles(wtap_encap[wdh->encap]);
tm = localtime(&netmon->first_record_time.secs);
if (tm != NULL) {
file_hdr.ts_year = htoles(1900 + tm->tm_year);
file_hdr.ts_month = htoles(tm->tm_mon + 1);
file_hdr.ts_dow = htoles(tm->tm_wday);
file_hdr.ts_day = htoles(tm->tm_mday);
file_hdr.ts_hour = htoles(tm->tm_hour);
file_hdr.ts_min = htoles(tm->tm_min);
file_hdr.ts_sec = htoles(tm->tm_sec);
} else {
file_hdr.ts_year = htoles(1900 + 0);
file_hdr.ts_month = htoles(0 + 1);
file_hdr.ts_dow = htoles(0);
file_hdr.ts_day = htoles(0);
file_hdr.ts_hour = htoles(0);
file_hdr.ts_min = htoles(0);
file_hdr.ts_sec = htoles(0);
}
file_hdr.ts_msec = htoles(netmon->first_record_time.nsecs/1000000);
file_hdr.frametableoffset = htolel(netmon->frame_table_offset);
file_hdr.frametablelength =
htolel(netmon->frame_table_index * sizeof *netmon->frame_table);
if (!wtap_dump_file_write(wdh, &file_hdr, sizeof file_hdr, err))
return FALSE;
return TRUE;
}
