int
ngsniffer_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic[sizeof ngsniffer_magic];
char record_type[2];
char record_length[4];
guint16 type;
struct vers_rec version;
guint16 maj_vers;
guint16 start_date;
#if 0
guint16 start_time;
#endif
static const int sniffer_encap[] = {
WTAP_ENCAP_TOKEN_RING,
WTAP_ENCAP_ETHERNET,
WTAP_ENCAP_ARCNET,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_UNKNOWN,
WTAP_ENCAP_PER_PACKET,
WTAP_ENCAP_PER_PACKET,
WTAP_ENCAP_FDDI_BITSWAPPED,
WTAP_ENCAP_ATM_PDUS
};
#define NUM_NGSNIFF_ENCAPS (sizeof sniffer_encap / sizeof sniffer_encap[0])
struct tm tm;
gint64 current_offset;
ngsniffer_t *ngsniffer;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
if (memcmp(magic, ngsniffer_magic, sizeof ngsniffer_magic)) {
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(record_type, 2, wth->fh);
if (bytes_read != 2) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
bytes_read = file_read(record_length, 4, wth->fh);
if (bytes_read != 4) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
type = pletohs(record_type);
if (type != REC_VERS) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ngsniffer: Sniffer file doesn't start with a version record");
return -1;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&version, sizeof version, wth->fh);
if (bytes_read != sizeof version) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
if (version.network >= NUM_NGSNIFF_ENCAPS
|| sniffer_encap[version.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("ngsniffer: network type %u unknown or unsupported",
version.network);
return -1;
}
if (version.timeunit >= NUM_NGSNIFF_TIMEUNITS) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("ngsniffer: Unknown timeunit %u", version.timeunit);
return -1;
}
if (version.format != 1) {
wth->file_type = WTAP_FILE_NGSNIFFER_COMPRESSED;
} else {
wth->file_type = WTAP_FILE_NGSNIFFER_UNCOMPRESSED;
}
wth->file_encap = sniffer_encap[version.network];
maj_vers = pletohs(&version.maj_vers);
if (process_header_records(wth, err, err_info, maj_vers,
version.network) < 0)
return -1;
if ((version.network == NETWORK_SYNCHRO ||
version.network == NETWORK_ASYNC) &&
wth->file_encap == WTAP_ENCAP_PER_PACKET) {
switch (maj_vers) {
case 1:
switch (pletohs(&version.rsvd[0])) {
case 1:
case 2:
wth->file_encap = WTAP_ENCAP_ISDN;
break;
}
break;
case 3:
wth->file_encap = WTAP_ENCAP_FRELAY_WITH_PHDR;
break;
}
}
current_offset = file_tell(wth->fh);
if (wth->random_fh != NULL) {
if (file_seek(wth->random_fh, current_offset, SEEK_SET, err) == -1)
return -1;
}
ngsniffer = (ngsniffer_t *)g_malloc(sizeof(ngsniffer_t));
wth->priv = (void *)ngsniffer;
ngsniffer->maj_vers = maj_vers;
ngsniffer->min_vers = pletohs(&version.min_vers);
ngsniffer->seq.buf = NULL;
ngsniffer->rand.buf = NULL;
ngsniffer->seq.uncomp_offset = current_offset;
ngsniffer->seq.comp_offset = current_offset;
ngsniffer->rand.uncomp_offset = current_offset;
ngsniffer->rand.comp_offset = current_offset;
ngsniffer->first_blob = NULL;
ngsniffer->last_blob = NULL;
ngsniffer->current_blob = NULL;
wth->subtype_read = ngsniffer_read;
wth->subtype_seek_read = ngsniffer_seek_read;
wth->subtype_sequential_close = ngsniffer_sequential_close;
wth->subtype_close = ngsniffer_close;
wth->snapshot_length = 0;
ngsniffer->timeunit = Psec[version.timeunit];
ngsniffer->network = version.network;
start_date = pletohs(&version.date);
tm.tm_year = ((start_date&0xfe00)>>9) + 1980 - 1900;
tm.tm_mon = ((start_date&0x1e0)>>5) - 1;
tm.tm_mday = (start_date&0x1f);
#if 0
start_time = pletohs(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
tm.tm_hour = 0;
tm.tm_min = 0;
tm.tm_sec = 0;
tm.tm_isdst = -1;
ngsniffer->start = mktime(&tm);
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
return 1;
}
static int
process_header_records(wtap *wth, int *err, gchar **err_info, gint16 maj_vers,
guint8 network)
{
int bytes_read;
char record_type[2];
char record_length[4];
guint16 type, length;
int bytes_to_read;
unsigned char buffer[256];
for (;;) {
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(record_type, 2, wth->fh);
if (bytes_read != 2) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
type = pletohs(record_type);
if ((type != REC_HEADER1) && (type != REC_HEADER2)
&& (type != REC_HEADER3) && (type != REC_HEADER4)
&& (type != REC_HEADER5) && (type != REC_HEADER6)
&& (type != REC_HEADER7)
&& ((type != REC_V2DESC) || (maj_vers > 2)) ) {
if (file_seek(wth->fh, -2, SEEK_CUR, err) == -1)
return -1;
return 0;
}
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(record_length, 4, wth->fh);
if (bytes_read != 4) {
*err = file_error(wth->fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
length = pletohs(record_length);
if ((network == NETWORK_SYNCHRO || network == NETWORK_ASYNC) &&
type == REC_HEADER2) {
bytes_to_read = MIN(length, (int)sizeof buffer);
bytes_read = file_read(buffer, bytes_to_read,
wth->fh);
if (bytes_read != bytes_to_read) {
*err = file_error(wth->fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
}
switch (maj_vers) {
case 2:
if (process_rec_header2_v2(wth, buffer,
length, err, err_info) < 0)
return -1;
break;
case 1:
case 4:
case 5:
if (process_rec_header2_v145(wth, buffer,
length, maj_vers, err, err_info) < 0)
return -1;
break;
}
if (length > sizeof buffer) {
if (file_seek(wth->fh, length - sizeof buffer,
SEEK_CUR, err) == -1)
return -1;
}
} else {
if (file_seek(wth->fh, length, SEEK_CUR, err) == -1)
return -1;
}
}
}
static int
process_rec_header2_v2(wtap *wth, unsigned char *buffer, guint16 length,
int *err, gchar **err_info)
{
static const char x_25_str[] = "HDLC\nX.25\n";
if (length < sizeof x_25_str - 1) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("ngsniffer: WAN capture has too-short protocol list");
return -1;
}
if (strncmp((char *)buffer, x_25_str, sizeof x_25_str - 1) == 0) {
wth->file_encap = WTAP_ENCAP_LAPB;
} else {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("ngsniffer: WAN capture protocol string %.*s unknown",
length, buffer);
return -1;
}
return 0;
}
static int
process_rec_header2_v145(wtap *wth, unsigned char *buffer, guint16 length,
gint16 maj_vers, int *err, gchar **err_info)
{
if (length < 5) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup("ngsniffer: WAN capture has no network subtype");
return -1;
}
switch (buffer[4]) {
case NET_SDLC:
wth->file_encap = WTAP_ENCAP_SDLC;
break;
case NET_HDLC:
wth->file_encap = WTAP_ENCAP_PER_PACKET;
break;
case NET_FRAME_RELAY:
wth->file_encap = WTAP_ENCAP_FRELAY_WITH_PHDR;
break;
case NET_ROUTER:
wth->file_encap = WTAP_ENCAP_PER_PACKET;
switch (maj_vers) {
case 4:
if (buffer[1] == 0xfa)
wth->file_encap = WTAP_ENCAP_ISDN;
break;
case 5:
if (length < 7) {
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup("ngsniffer: WAN bridge/router capture has no ISDN flag");
return -1;
}
if (buffer[6] == 0x01)
wth->file_encap = WTAP_ENCAP_ISDN;
break;
}
break;
case NET_PPP:
wth->file_encap = WTAP_ENCAP_PPP_WITH_PHDR;
break;
default:
*err = WTAP_ERR_UNSUPPORTED_ENCAP;
*err_info = g_strdup_printf("ngsniffer: WAN network subtype %u unknown or unsupported",
buffer[4]);
return -1;
}
return 0;
}
static gboolean
ngsniffer_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
ngsniffer_t *ngsniffer;
int ret;
guint16 type, length;
struct frame2_rec frame2;
struct frame4_rec frame4;
struct frame6_rec frame6;
guint16 time_low, time_med, true_size, size;
guint8 time_high, time_day;
guint64 t, tsecs, tpsecs;
guint8 *pd;
ngsniffer = (ngsniffer_t *)wth->priv;
for (;;) {
*data_offset = ngsniffer->seq.uncomp_offset;
ret = ngsniffer_read_rec_header(wth, FALSE, &type, &length,
err, err_info);
if (ret <= 0) {
return FALSE;
}
switch (type) {
case REC_FRAME2:
if (ngsniffer->network == NETWORK_ATM) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: REC_FRAME2 record in an ATM Sniffer file");
return FALSE;
}
if (!ngsniffer_read_frame2(wth, FALSE, &frame2, err,
err_info)) {
return FALSE;
}
time_low = pletohs(&frame2.time_low);
time_med = pletohs(&frame2.time_med);
time_high = frame2.time_high;
time_day = frame2.time_day;
size = pletohs(&frame2.size);
true_size = pletohs(&frame2.true_size);
length -= sizeof frame2;
set_pseudo_header_frame2(wth, &wth->pseudo_header,
&frame2);
goto found;
case REC_FRAME4:
if (ngsniffer->network != NETWORK_ATM) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: REC_FRAME4 record in a non-ATM Sniffer file");
return FALSE;
}
if (!ngsniffer_read_frame4(wth, FALSE, &frame4, err,
err_info)) {
return FALSE;
}
time_low = pletohs(&frame4.time_low);
time_med = pletohs(&frame4.time_med);
time_high = frame4.time_high;
time_day = frame4.time_day;
size = pletohs(&frame4.size);
true_size = pletohs(&frame4.true_size);
if (ngsniffer->maj_vers >= 5)
length -= sizeof frame4;
else {
if (ngsniffer->min_vers >= 95)
length -= sizeof frame2;
else
length -= sizeof frame4;
}
set_pseudo_header_frame4(&wth->pseudo_header, &frame4);
goto found;
case REC_FRAME6:
if (!ngsniffer_read_frame6(wth, FALSE, &frame6, err,
err_info)) {
return FALSE;
}
time_low = pletohs(&frame6.time_low);
time_med = pletohs(&frame6.time_med);
time_high = frame6.time_high;
time_day = frame6.time_day;
size = pletohs(&frame6.size);
true_size = pletohs(&frame6.true_size);
length -= sizeof frame6;
set_pseudo_header_frame6(wth, &wth->pseudo_header,
&frame6);
goto found;
case REC_EOF:
*err = 0;
return FALSE;
default:
break;
}
if (!ng_file_skip_seq(wth, length, err, err_info))
return FALSE;
}
found:
if (size > length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: Record length is less than packet size");
return FALSE;
}
wth->phdr.presence_flags = true_size ? WTAP_HAS_TS|WTAP_HAS_CAP_LEN : WTAP_HAS_TS;
wth->phdr.len = true_size ? true_size : size;
wth->phdr.caplen = size;
buffer_assure_space(wth->frame_buffer, length);
pd = buffer_start_ptr(wth->frame_buffer);
if (!ngsniffer_read_rec_data(wth, FALSE, pd, length, err, err_info))
return FALSE;
wth->phdr.pkt_encap = fix_pseudo_header(wth->file_encap, pd, length,
&wth->pseudo_header);
t = (((guint64)time_high)<<32) | (((guint64)time_med) << 16) | time_low;
t *= ngsniffer->timeunit;
tsecs = t/G_GINT64_CONSTANT(1000000000000U);
tpsecs = t - tsecs*G_GINT64_CONSTANT(1000000000000U);
tsecs += time_day*86400;
tsecs += ngsniffer->start;
wth->phdr.ts.secs = (time_t)tsecs;
wth->phdr.ts.nsecs = (int)(tpsecs/1000);
return TRUE;
}
static gboolean
ngsniffer_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int packet_size,
int *err, gchar **err_info)
{
int ret;
guint16 type, length;
struct frame2_rec frame2;
struct frame4_rec frame4;
struct frame6_rec frame6;
if (!ng_file_seek_rand(wth, seek_off, err, err_info))
return FALSE;
ret = ngsniffer_read_rec_header(wth, TRUE, &type, &length, err,
err_info);
if (ret <= 0) {
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
switch (type) {
case REC_FRAME2:
if (!ngsniffer_read_frame2(wth, TRUE, &frame2, err, err_info)) {
return FALSE;
}
length -= sizeof frame2;
set_pseudo_header_frame2(wth, pseudo_header, &frame2);
break;
case REC_FRAME4:
if (!ngsniffer_read_frame4(wth, TRUE, &frame4, err, err_info)) {
return FALSE;
}
length -= sizeof frame4;
set_pseudo_header_frame4(pseudo_header, &frame4);
break;
case REC_FRAME6:
if (!ngsniffer_read_frame6(wth, TRUE, &frame6, err, err_info)) {
return FALSE;
}
length -= sizeof frame6;
set_pseudo_header_frame6(wth, pseudo_header, &frame6);
break;
default:
g_assert_not_reached();
return FALSE;
}
if (!ngsniffer_read_rec_data(wth, TRUE, pd, packet_size, err, err_info))
return FALSE;
fix_pseudo_header(wth->file_encap, pd, packet_size, pseudo_header);
return TRUE;
}
static int
ngsniffer_read_rec_header(wtap *wth, gboolean is_random, guint16 *typep,
guint16 *lengthp, int *err, gchar **err_info)
{
gint64 bytes_read;
char record_type[2];
char record_length[4];
bytes_read = ng_file_read(record_type, 2, wth, is_random, err,
err_info);
if (bytes_read != 2) {
if (*err != 0)
return -1;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
bytes_read = ng_file_read(record_length, 4, wth, is_random, err,
err_info);
if (bytes_read != 4) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
*typep = pletohs(record_type);
*lengthp = pletohs(record_length);
return 1;
}
static gboolean
ngsniffer_read_frame2(wtap *wth, gboolean is_random, struct frame2_rec *frame2,
int *err, gchar **err_info)
{
gint64 bytes_read;
bytes_read = ng_file_read(frame2, (unsigned int)sizeof *frame2, wth,
is_random, err, err_info);
if (bytes_read != sizeof *frame2) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static void
set_pseudo_header_frame2(wtap *wth, union wtap_pseudo_header *pseudo_header,
struct frame2_rec *frame2)
{
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = 0;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_SDLC:
pseudo_header->p2p.sent = (frame2->fs & FS_WAN_DTE) ? TRUE : FALSE;
break;
case WTAP_ENCAP_LAPB:
case WTAP_ENCAP_FRELAY_WITH_PHDR:
case WTAP_ENCAP_PER_PACKET:
pseudo_header->x25.flags = (frame2->fs & FS_WAN_DTE) ? 0x00 : FROM_DCE;
break;
case WTAP_ENCAP_ISDN:
pseudo_header->isdn.uton = (frame2->fs & FS_WAN_DTE) ? FALSE : TRUE;
switch (frame2->fs & FS_ISDN_CHAN_MASK) {
case FS_ISDN_CHAN_D:
pseudo_header->isdn.channel = 0;
break;
case FS_ISDN_CHAN_B1:
pseudo_header->isdn.channel = 1;
break;
case FS_ISDN_CHAN_B2:
pseudo_header->isdn.channel = 2;
break;
default:
pseudo_header->isdn.channel = 30;
break;
}
}
}
static gboolean
ngsniffer_read_frame4(wtap *wth, gboolean is_random, struct frame4_rec *frame4,
int *err, gchar **err_info)
{
gint64 bytes_read;
bytes_read = ng_file_read(frame4, (unsigned int)sizeof *frame4, wth,
is_random, err, err_info);
if (bytes_read != sizeof *frame4) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static void
set_pseudo_header_frame4(union wtap_pseudo_header *pseudo_header,
struct frame4_rec *frame4)
{
guint32 StatusWord;
guint8 aal_type, hl_type;
guint16 vpi, vci;
pseudo_header->atm.flags = 0;
StatusWord = pletohl(&frame4->atm_info.StatusWord);
if (StatusWord & SW_RAW_CELL)
pseudo_header->atm.flags |= ATM_RAW_CELL;
aal_type = frame4->atm_info.AppTrafType & ATT_AALTYPE;
hl_type = frame4->atm_info.AppTrafType & ATT_HLTYPE;
vpi = pletohs(&frame4->atm_info.Vpi);
vci = pletohs(&frame4->atm_info.Vci);
switch (aal_type) {
case ATT_AAL_UNKNOWN:
if (vpi == 0 && vci == 5)
pseudo_header->atm.aal = AAL_SIGNALLING;
else
pseudo_header->atm.aal = AAL_UNKNOWN;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_AAL1:
pseudo_header->atm.aal = AAL_1;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_AAL3_4:
pseudo_header->atm.aal = AAL_3_4;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_AAL5:
pseudo_header->atm.aal = AAL_5;
switch (hl_type) {
case ATT_HL_UNKNOWN:
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_HL_LLCMX:
pseudo_header->atm.type = TRAF_LLCMX;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_HL_VCMX:
pseudo_header->atm.type = TRAF_VCMX;
switch (frame4->atm_info.AppHLType) {
case AHLT_UNKNOWN:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case AHLT_VCMX_802_3_FCS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_802_3_FCS;
break;
case AHLT_VCMX_802_4_FCS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_802_4_FCS;
break;
case AHLT_VCMX_802_5_FCS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_802_5_FCS;
break;
case AHLT_VCMX_FDDI_FCS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_FDDI_FCS;
break;
case AHLT_VCMX_802_6_FCS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_802_6_FCS;
break;
case AHLT_VCMX_802_3:
pseudo_header->atm.subtype = TRAF_ST_VCMX_802_3;
break;
case AHLT_VCMX_802_4:
pseudo_header->atm.subtype = TRAF_ST_VCMX_802_4;
break;
case AHLT_VCMX_802_5:
pseudo_header->atm.subtype = TRAF_ST_VCMX_802_5;
break;
case AHLT_VCMX_FDDI:
pseudo_header->atm.subtype = TRAF_ST_VCMX_FDDI;
break;
case AHLT_VCMX_802_6:
pseudo_header->atm.subtype = TRAF_ST_VCMX_802_6;
break;
case AHLT_VCMX_FRAGMENTS:
pseudo_header->atm.subtype =
TRAF_ST_VCMX_FRAGMENTS;
break;
case AHLT_VCMX_BPDU:
pseudo_header->atm.subtype = TRAF_ST_VCMX_BPDU;
break;
default:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
case ATT_HL_LANE:
pseudo_header->atm.type = TRAF_LANE;
switch (frame4->atm_info.AppHLType) {
case AHLT_UNKNOWN:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case AHLT_LANE_LE_CTRL:
pseudo_header->atm.subtype =
TRAF_ST_LANE_LE_CTRL;
break;
case AHLT_LANE_802_3:
pseudo_header->atm.subtype = TRAF_ST_LANE_802_3;
break;
case AHLT_LANE_802_5:
pseudo_header->atm.subtype = TRAF_ST_LANE_802_5;
break;
case AHLT_LANE_802_3_MC:
pseudo_header->atm.subtype =
TRAF_ST_LANE_802_3_MC;
break;
case AHLT_LANE_802_5_MC:
pseudo_header->atm.subtype =
TRAF_ST_LANE_802_5_MC;
break;
default:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
case ATT_HL_ILMI:
pseudo_header->atm.type = TRAF_ILMI;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_HL_FRMR:
pseudo_header->atm.type = TRAF_FR;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_HL_SPANS:
pseudo_header->atm.type = TRAF_SPANS;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_HL_IPSILON:
pseudo_header->atm.type = TRAF_IPSILON;
switch (frame4->atm_info.AppHLType) {
case AHLT_UNKNOWN:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case AHLT_IPSILON_FT0:
pseudo_header->atm.subtype =
TRAF_ST_IPSILON_FT0;
break;
case AHLT_IPSILON_FT1:
pseudo_header->atm.subtype =
TRAF_ST_IPSILON_FT1;
break;
case AHLT_IPSILON_FT2:
pseudo_header->atm.subtype =
TRAF_ST_IPSILON_FT2;
break;
default:
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
default:
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
break;
case ATT_AAL_USER:
pseudo_header->atm.aal = AAL_USER;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_AAL_SIGNALLING:
pseudo_header->atm.aal = AAL_SIGNALLING;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
case ATT_OAMCELL:
pseudo_header->atm.aal = AAL_OAMCELL;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
default:
pseudo_header->atm.aal = AAL_UNKNOWN;
pseudo_header->atm.type = TRAF_UNKNOWN;
pseudo_header->atm.subtype = TRAF_ST_UNKNOWN;
break;
}
pseudo_header->atm.vpi = vpi;
pseudo_header->atm.vci = vci;
pseudo_header->atm.channel = pletohs(&frame4->atm_info.channel);
pseudo_header->atm.cells = pletohs(&frame4->atm_info.cells);
pseudo_header->atm.aal5t_u2u = pletohs(&frame4->atm_info.Trailer.aal5t_u2u);
pseudo_header->atm.aal5t_len = pletohs(&frame4->atm_info.Trailer.aal5t_len);
pseudo_header->atm.aal5t_chksum = pntohl(&frame4->atm_info.Trailer.aal5t_chksum);
}
static gboolean
ngsniffer_read_frame6(wtap *wth, gboolean is_random, struct frame6_rec *frame6,
int *err, gchar **err_info)
{
gint64 bytes_read;
bytes_read = ng_file_read(frame6, (unsigned int)sizeof *frame6, wth,
is_random, err, err_info);
if (bytes_read != sizeof *frame6) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static void
set_pseudo_header_frame6(wtap *wth, union wtap_pseudo_header *pseudo_header,
struct frame6_rec *frame6 _U_)
{
switch (wth->file_encap) {
case WTAP_ENCAP_ETHERNET:
pseudo_header->eth.fcs_len = -1;
break;
}
}
static gboolean
ngsniffer_read_rec_data(wtap *wth, gboolean is_random, guint8 *pd,
unsigned int length, int *err, gchar **err_info)
{
gint64 bytes_read;
bytes_read = ng_file_read(pd, length, wth, is_random, err, err_info);
if (bytes_read != (gint64) length) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int
infer_pkt_encap(const guint8 *pd, int len)
{
int i;
if (len <= 0) {
return WTAP_ENCAP_PPP_WITH_PHDR;
}
if (pd[0] == 0xFF) {
return WTAP_ENCAP_PPP_WITH_PHDR;
}
if (len >= 2) {
if (pd[0] == 0x07 && pd[1] == 0x03) {
return WTAP_ENCAP_WFLEET_HDLC;
} else if ((pd[0] == 0x0F && pd[1] == 0x00) ||
(pd[0] == 0x8F && pd[1] == 0x00)) {
return WTAP_ENCAP_CHDLC_WITH_PHDR;
}
for (i = 0; i < len && (pd[i] & 0x01) == 0; i++)
;
i++;
if (i == len) {
return WTAP_ENCAP_LAPB;
}
if (pd[i] == 0x03)
return WTAP_ENCAP_FRELAY_WITH_PHDR;
}
return WTAP_ENCAP_LAPB;
}
static int
fix_pseudo_header(int encap, const guint8 *pd, int len,
union wtap_pseudo_header *pseudo_header)
{
switch (encap) {
case WTAP_ENCAP_PER_PACKET:
encap = infer_pkt_encap(pd, len);
switch (encap) {
case WTAP_ENCAP_WFLEET_HDLC:
case WTAP_ENCAP_CHDLC_WITH_PHDR:
case WTAP_ENCAP_PPP_WITH_PHDR:
if (pseudo_header->x25.flags == 0)
pseudo_header->p2p.sent = TRUE;
else
pseudo_header->p2p.sent = FALSE;
break;
case WTAP_ENCAP_ISDN:
if (pseudo_header->x25.flags == 0x00)
pseudo_header->isdn.uton = FALSE;
else
pseudo_header->isdn.uton = TRUE;
pseudo_header->isdn.channel = 0;
break;
}
break;
case WTAP_ENCAP_ATM_PDUS:
if (pseudo_header->atm.type == TRAF_LANE && len >= 2) {
if (pd[0] == 0xff && pd[1] == 0x00) {
pseudo_header->atm.subtype =
TRAF_ST_LANE_LE_CTRL;
} else {
if (pseudo_header->atm.subtype ==
TRAF_ST_LANE_LE_CTRL) {
pseudo_header->atm.subtype =
TRAF_ST_LANE_802_3;
}
}
}
break;
}
return encap;
}
static void
ngsniffer_sequential_close(wtap *wth)
{
ngsniffer_t *ngsniffer;
ngsniffer = (ngsniffer_t *)wth->priv;
if (ngsniffer->seq.buf != NULL) {
g_free(ngsniffer->seq.buf);
ngsniffer->seq.buf = NULL;
}
}
static void
free_blob(gpointer data, gpointer user_data _U_)
{
g_free(data);
}
static void
ngsniffer_close(wtap *wth)
{
ngsniffer_t *ngsniffer;
ngsniffer = (ngsniffer_t *)wth->priv;
if (ngsniffer->rand.buf != NULL)
g_free(ngsniffer->rand.buf);
if (ngsniffer->first_blob != NULL) {
g_list_foreach(ngsniffer->first_blob, free_blob, NULL);
g_list_free(ngsniffer->first_blob);
}
}
int
ngsniffer_dump_can_write_encap(int encap)
{
if (encap == WTAP_ENCAP_PER_PACKET)
return WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED;
if (encap < 0 || (unsigned)encap >= NUM_WTAP_ENCAPS || wtap_encap[encap] == -1)
return WTAP_ERR_UNSUPPORTED_ENCAP;
return 0;
}
gboolean
ngsniffer_dump_open(wtap_dumper *wdh, int *err)
{
ngsniffer_dump_t *ngsniffer;
char buf[6] = {REC_VERS, 0x00, 0x12, 0x00, 0x00, 0x00};
wdh->subtype_write = ngsniffer_dump;
wdh->subtype_close = ngsniffer_dump_close;
ngsniffer = (ngsniffer_dump_t *)g_malloc(sizeof(ngsniffer_dump_t));
wdh->priv = (void *)ngsniffer;
ngsniffer->first_frame = TRUE;
ngsniffer->start = 0;
if (!wtap_dump_file_write(wdh, ngsniffer_magic, sizeof ngsniffer_magic,
err))
return FALSE;
if (!wtap_dump_file_write(wdh, buf, 6, err))
return FALSE;
return TRUE;
}
static gboolean
ngsniffer_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const union wtap_pseudo_header *pseudo_header, const guint8 *pd, int *err)
{
ngsniffer_dump_t *ngsniffer = (ngsniffer_dump_t *)wdh->priv;
struct frame2_rec rec_hdr;
char buf[6];
time_t tsecs;
guint64 t;
guint16 t_low, t_med;
guint8 t_high;
struct vers_rec version;
gint16 maj_vers, min_vers;
guint16 start_date;
struct tm *tm;
if (ngsniffer->first_frame) {
ngsniffer->first_frame=FALSE;
#ifdef _MSC_VER
if (phdr->ts.secs > 2000000000)
tm = NULL;
else
#endif
tm = localtime(&phdr->ts.secs);
if (tm != NULL && tm->tm_year >= 1980) {
start_date = (tm->tm_year - (1980 - 1900)) << 9;
start_date |= (tm->tm_mon + 1) << 5;
start_date |= tm->tm_mday;
ngsniffer->start = phdr->ts.secs - (3600*tm->tm_hour + 60*tm->tm_min + tm->tm_sec);
} else {
start_date = 0;
ngsniffer->start = 0;
}
maj_vers = 4;
min_vers = 0;
version.maj_vers = htoles(maj_vers);
version.min_vers = htoles(min_vers);
version.time = 0;
version.date = htoles(start_date);
version.type = 4;
version.network = wtap_encap[wdh->encap];
version.format = 1;
version.timeunit = 1;
version.cmprs_vers = 0;
version.cmprs_level = 0;
version.rsvd[0] = 0;
version.rsvd[1] = 0;
if (!wtap_dump_file_write(wdh, &version, sizeof version, err))
return FALSE;
}
buf[0] = REC_FRAME2;
buf[1] = 0x00;
buf[2] = (char)((phdr->caplen + sizeof(struct frame2_rec))%256);
buf[3] = (char)((phdr->caplen + sizeof(struct frame2_rec))/256);
buf[4] = 0x00;
buf[5] = 0x00;
if (!wtap_dump_file_write(wdh, buf, 6, err))
return FALSE;
tsecs = phdr->ts.secs - ngsniffer->start;
rec_hdr.time_day = (guint8)(tsecs / 86400);
tsecs -= rec_hdr.time_day * 86400;
t = tsecs*G_GINT64_CONSTANT(1000000000000U) +
phdr->ts.nsecs*G_GINT64_CONSTANT(1000U);
t /= Psec[1];
t_low = (guint16)((t >> 0) & 0xFFFF);
t_med = (guint16)((t >> 16) & 0xFFFF);
t_high = (guint8)((t >> 32) & 0xFF);
rec_hdr.time_low = htoles(t_low);
rec_hdr.time_med = htoles(t_med);
rec_hdr.time_high = t_high;
rec_hdr.size = htoles(phdr->caplen);
switch (wdh->encap) {
case WTAP_ENCAP_LAPB:
case WTAP_ENCAP_FRELAY_WITH_PHDR:
rec_hdr.fs = (pseudo_header->x25.flags & FROM_DCE) ? 0x00 : FS_WAN_DTE;
break;
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_SDLC:
rec_hdr.fs = pseudo_header->p2p.sent ? 0x00 : FS_WAN_DTE;
break;
case WTAP_ENCAP_ISDN:
rec_hdr.fs = pseudo_header->isdn.uton ? FS_WAN_DTE : 0x00;
switch (pseudo_header->isdn.channel) {
case 0:
rec_hdr.fs |= FS_ISDN_CHAN_D;
break;
case 1:
rec_hdr.fs |= FS_ISDN_CHAN_B1;
break;
case 2:
rec_hdr.fs |= FS_ISDN_CHAN_B2;
break;
}
break;
default:
rec_hdr.fs = 0;
break;
}
rec_hdr.flags = 0;
rec_hdr.true_size = phdr->len != phdr->caplen ? htoles(phdr->len) : 0;
rec_hdr.rsvd = 0;
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof rec_hdr, err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
return TRUE;
}
static gboolean
ngsniffer_dump_close(wtap_dumper *wdh, int *err)
{
char buf[6] = {REC_EOF, 0x00, 0x00, 0x00, 0x00, 0x00};
if (!wtap_dump_file_write(wdh, buf, 6, err))
return FALSE;
return TRUE;
}
static int
SnifferDecompress(unsigned char *inbuf, size_t inlen, unsigned char *outbuf,
size_t outlen, int *err)
{
unsigned char * pin = inbuf;
unsigned char * pout = outbuf;
unsigned char * pin_end = pin + inlen;
unsigned char * pout_end = pout + outlen;
unsigned int bit_mask;
unsigned int bit_value = 0;
unsigned int code_type;
unsigned int code_low;
int length;
int offset;
if (inlen > G_MAXUINT16) {
return ( -1 );
}
bit_mask = 0;
while (1)
{
bit_mask = bit_mask >> 1;
if ( 0 == bit_mask )
{
bit_mask = 0x8000;
bit_value = pletohs(pin);
pin += 2;
if ( pin >= pin_end )
{
*err = WTAP_ERR_UNC_TRUNCATED;
return ( -1 );
}
}
if ( !(bit_mask & bit_value) )
{
*(pout++) = *(pin++);
}
else
{
code_type = (unsigned int) ((*pin) >> 4 ) & 0xF;
code_low = (unsigned int) ((*pin) & 0xF );
pin++;
if ( pin >= pin_end )
{
*err = WTAP_ERR_UNC_TRUNCATED;
return ( -1 );
}
switch ( code_type )
{
case 0 :
length = code_low + 3;
if ( pout + length > pout_end )
{
*err = WTAP_ERR_UNC_OVERFLOW;
return ( -1 );
}
memset( pout, *pin++, length );
pout += length;
break;
case 1 :
length = code_low + ((unsigned int)(*pin++) << 4) + 19;
if ( pin >= pin_end )
{
*err = WTAP_ERR_UNC_TRUNCATED;
return ( -1 );
}
if ( pout + length > pout_end )
{
*err = WTAP_ERR_UNC_OVERFLOW;
return ( -1 );
}
memset( pout, *pin++, length );
pout += length;
break;
case 2 :
offset = code_low + ((unsigned int)(*pin++) << 4) + 3;
if ( pin >= pin_end )
{
*err = WTAP_ERR_UNC_TRUNCATED;
return ( -1 );
}
if ( pout - offset < outbuf )
{
*err = WTAP_ERR_UNC_BAD_OFFSET;
return ( -1 );
}
length = (unsigned int)(*pin++) + 16;
if ( pout + length > pout_end )
{
*err = WTAP_ERR_UNC_OVERFLOW;
return ( -1 );
}
memcpy( pout, pout - offset, length );
pout += length;
break;
default :
offset = code_low + ((unsigned int)(*pin++) << 4) + 3;
if ( pout - offset < outbuf )
{
*err = WTAP_ERR_UNC_BAD_OFFSET;
return ( -1 );
}
length = code_type;
if ( pout + length > pout_end )
{
*err = WTAP_ERR_UNC_OVERFLOW;
return ( -1 );
}
memcpy( pout, pout - offset, length );
pout += length;
break;
}
}
if ( pin >= pin_end )
break;
}
return (int) ( pout - outbuf );
}
static gint64
ng_file_read(void *buffer, unsigned int nbytes, wtap *wth, gboolean is_random,
int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
FILE_T infile;
ngsniffer_comp_stream_t *comp_stream;
unsigned int copybytes = nbytes;
gint64 copied_bytes = 0;
unsigned char *outbuffer = (unsigned char *)buffer;
blob_info_t *blob;
unsigned int bytes_to_copy;
unsigned int bytes_left;
ngsniffer = (ngsniffer_t *)wth->priv;
if (is_random) {
infile = wth->random_fh;
comp_stream = &ngsniffer->rand;
} else {
infile = wth->fh;
comp_stream = &ngsniffer->seq;
}
if (wth->file_type == WTAP_FILE_NGSNIFFER_UNCOMPRESSED) {
errno = WTAP_ERR_CANT_READ;
copied_bytes = file_read(buffer, copybytes, infile);
if ((unsigned int) copied_bytes != copybytes)
*err = file_error(infile, err_info);
if (copied_bytes != -1) {
comp_stream->uncomp_offset += copied_bytes;
comp_stream->comp_offset += copied_bytes;
}
return copied_bytes;
}
if (comp_stream->buf == NULL) {
comp_stream->buf = (unsigned char *)g_malloc(OUTBUF_SIZE);
if (is_random) {
ngsniffer->current_blob = ngsniffer->first_blob;
} else {
if (wth->random_fh != NULL) {
g_assert(ngsniffer->first_blob == NULL);
blob = g_new(blob_info_t,1);
blob->blob_comp_offset = comp_stream->comp_offset;
blob->blob_uncomp_offset = comp_stream->uncomp_offset;
ngsniffer->first_blob = g_list_append(ngsniffer->first_blob,
blob);
ngsniffer->last_blob = ngsniffer->first_blob;
}
}
if (read_blob(infile, comp_stream, err, err_info) < 0)
return -1;
}
while (copybytes > 0) {
bytes_left = comp_stream->nbytes - comp_stream->nextout;
if (bytes_left == 0) {
if (is_random) {
ngsniffer->current_blob = g_list_next(ngsniffer->current_blob);
if (!ngsniffer->current_blob) {
*err = WTAP_ERR_CANT_SEEK;
return -1;
}
blob = (blob_info_t *)ngsniffer->current_blob->data;
} else {
if (wth->random_fh != NULL) {
blob = g_new(blob_info_t,1);
blob->blob_comp_offset = comp_stream->comp_offset;
blob->blob_uncomp_offset = comp_stream->uncomp_offset;
ngsniffer->last_blob = g_list_append(ngsniffer->last_blob,
blob);
}
}
if (read_blob(infile, comp_stream, err, err_info) < 0)
return -1;
bytes_left = comp_stream->nbytes - comp_stream->nextout;
}
bytes_to_copy = copybytes;
if (bytes_to_copy > bytes_left)
bytes_to_copy = bytes_left;
memcpy(outbuffer, &comp_stream->buf[comp_stream->nextout],
bytes_to_copy);
copybytes -= bytes_to_copy;
copied_bytes += bytes_to_copy;
outbuffer += bytes_to_copy;
comp_stream->nextout += bytes_to_copy;
comp_stream->uncomp_offset += bytes_to_copy;
}
return copied_bytes;
}
static int
read_blob(FILE_T infile, ngsniffer_comp_stream_t *comp_stream, int *err,
gchar **err_info)
{
int in_len;
size_t read_len;
unsigned short blob_len;
gint16 blob_len_host;
gboolean uncompressed;
unsigned char *file_inbuf;
int out_len;
errno = WTAP_ERR_CANT_READ;
read_len = file_read(&blob_len, 2, infile);
if (2 != read_len) {
*err = file_error(infile, err_info);
return -1;
}
comp_stream->comp_offset += 2;
blob_len_host = pletohs(&blob_len);
if (blob_len_host < 0) {
in_len = -blob_len_host;
uncompressed = TRUE;
} else {
in_len = blob_len_host;
uncompressed = FALSE;
}
file_inbuf = (unsigned char *)g_malloc(INBUF_SIZE);
errno = WTAP_ERR_CANT_READ;
read_len = file_read(file_inbuf, in_len, infile);
if ((size_t) in_len != read_len) {
*err = file_error(infile, err_info);
g_free(file_inbuf);
return -1;
}
comp_stream->comp_offset += in_len;
if (uncompressed) {
memcpy(comp_stream->buf, file_inbuf, in_len);
out_len = in_len;
} else {
out_len = SnifferDecompress(file_inbuf, in_len,
comp_stream->buf, OUTBUF_SIZE, err);
if (out_len < 0) {
g_free(file_inbuf);
return -1;
}
}
g_free(file_inbuf);
comp_stream->nextout = 0;
comp_stream->nbytes = out_len;
return 0;
}
static gboolean
ng_file_skip_seq(wtap *wth, gint64 delta, int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
char *buf;
unsigned int amount_to_read;
ngsniffer = (ngsniffer_t *)wth->priv;
if (wth->file_type == WTAP_FILE_NGSNIFFER_UNCOMPRESSED) {
ngsniffer->seq.uncomp_offset += delta;
if (file_skip(wth->fh, delta, err) == -1)
return FALSE;
return TRUE;
}
g_assert(delta >= 0);
buf = (char *)g_malloc(INBUF_SIZE);
while (delta != 0) {
if (delta > INBUF_SIZE)
amount_to_read = INBUF_SIZE;
else
amount_to_read = (unsigned int) delta;
if (ng_file_read(buf, amount_to_read, wth, FALSE, err, err_info) < 0) {
g_free(buf);
return FALSE;
}
delta -= amount_to_read;
}
g_free(buf);
return TRUE;
}
static gboolean
ng_file_seek_rand(wtap *wth, gint64 offset, int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
gint64 delta;
GList *new_list, *next_list;
blob_info_t *next_blob, *new_blob;
ngsniffer = (ngsniffer_t *)wth->priv;
if (wth->file_type == WTAP_FILE_NGSNIFFER_UNCOMPRESSED) {
if (file_seek(wth->random_fh, offset, SEEK_SET, err) == -1)
return FALSE;
return TRUE;
}
delta = offset - ngsniffer->rand.uncomp_offset;
new_list = NULL;
if (delta > 0) {
if ((size_t)(ngsniffer->rand.nextout + delta) >= ngsniffer->rand.nbytes) {
new_list = g_list_next(ngsniffer->current_blob);
while (new_list) {
next_list = g_list_next(new_list);
if (next_list == NULL) {
break;
}
next_blob = (blob_info_t *)next_list->data;
if (next_blob->blob_uncomp_offset > offset)
break;
new_list = next_list;
}
}
} else if (delta < 0) {
if (ngsniffer->rand.nextout + delta < 0) {
new_list = g_list_previous(ngsniffer->current_blob);
while (new_list) {
new_blob = (blob_info_t *)new_list->data;
if (new_blob->blob_uncomp_offset <= offset)
break;
new_list = g_list_previous(new_list);
}
}
}
if (new_list != NULL) {
new_blob = (blob_info_t *)new_list->data;
if (file_seek(wth->random_fh, new_blob->blob_comp_offset, SEEK_SET, err) == -1)
return FALSE;
ngsniffer->current_blob = new_list;
ngsniffer->rand.uncomp_offset = new_blob->blob_uncomp_offset;
ngsniffer->rand.comp_offset = new_blob->blob_comp_offset;
if (read_blob(wth->random_fh, &ngsniffer->rand, err, err_info) < 0)
return FALSE;
delta = offset - ngsniffer->rand.uncomp_offset;
g_assert(delta >= 0 && (unsigned long)delta < ngsniffer->rand.nbytes);
}
ngsniffer->rand.nextout += (int) delta;
ngsniffer->rand.uncomp_offset += delta;
return TRUE;
}
