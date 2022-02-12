wtap_open_return_val
ngsniffer_open(wtap *wth, int *err, gchar **err_info)
{
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
if (!wtap_read_bytes(wth->fh, magic, sizeof magic, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (memcmp(magic, ngsniffer_magic, sizeof ngsniffer_magic)) {
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, record_type, 2, err, err_info))
return WTAP_OPEN_ERROR;
if (!wtap_read_bytes(wth->fh, record_length, 4, err, err_info))
return WTAP_OPEN_ERROR;
type = pletoh16(record_type);
if (type != REC_VERS) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ngsniffer: Sniffer file doesn't start with a version record");
return WTAP_OPEN_ERROR;
}
if (!wtap_read_bytes(wth->fh, &version, sizeof version, err, err_info))
return WTAP_OPEN_ERROR;
if (version.network >= NUM_NGSNIFF_ENCAPS
|| sniffer_encap[version.network] == WTAP_ENCAP_UNKNOWN) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("ngsniffer: network type %u unknown or unsupported",
version.network);
return WTAP_OPEN_ERROR;
}
if (version.timeunit >= NUM_NGSNIFF_TIMEUNITS) {
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("ngsniffer: Unknown timeunit %u", version.timeunit);
return WTAP_OPEN_ERROR;
}
if (version.format != 1) {
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_COMPRESSED;
} else {
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_UNCOMPRESSED;
}
wth->file_encap = sniffer_encap[version.network];
maj_vers = pletoh16(&version.maj_vers);
if (process_header_records(wth, err, err_info, maj_vers,
version.network) < 0)
return WTAP_OPEN_ERROR;
if ((version.network == NETWORK_SYNCHRO ||
version.network == NETWORK_ASYNC) &&
wth->file_encap == WTAP_ENCAP_PER_PACKET) {
switch (maj_vers) {
case 1:
switch (pletoh16(&version.rsvd[0])) {
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
return WTAP_OPEN_ERROR;
}
ngsniffer = (ngsniffer_t *)g_malloc(sizeof(ngsniffer_t));
wth->priv = (void *)ngsniffer;
ngsniffer->maj_vers = maj_vers;
ngsniffer->min_vers = pletoh16(&version.min_vers);
ngsniffer->seq.buf = NULL;
ngsniffer->seq.nbytes = 0;
ngsniffer->seq.nextout = 0;
ngsniffer->rand.buf = NULL;
ngsniffer->rand.nbytes = 0;
ngsniffer->rand.nextout = 0;
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
start_date = pletoh16(&version.date);
tm.tm_year = ((start_date&DOS_YEAR_MASK)>>DOS_YEAR_SHIFT) + DOS_YEAR_OFFSET;
tm.tm_mon = ((start_date&DOS_MONTH_MASK)>>DOS_MONTH_SHIFT) + DOS_MONTH_OFFSET;
tm.tm_mday = ((start_date&DOS_DAY_MASK)>>DOS_DAY_SHIFT);
#if 0
start_time = pletoh16(&version.time);
tm.tm_hour = (start_time&0xf800)>>11;
tm.tm_min = (start_time&0x7e0)>>5;
tm.tm_sec = (start_time&0x1f)<<1;
#endif
tm.tm_hour = 0;
tm.tm_min = 0;
tm.tm_sec = 0;
tm.tm_isdst = -1;
ngsniffer->start = mktime(&tm);
wth->file_tsprec = WTAP_TSPREC_NSEC;
return WTAP_OPEN_MINE;
}
static int
process_header_records(wtap *wth, int *err, gchar **err_info, gint16 maj_vers,
guint8 network)
{
char record_type[2];
char record_length[4];
guint16 type, length;
int bytes_to_read;
unsigned char buffer[256];
for (;;) {
if (!wtap_read_bytes_or_eof(wth->fh, record_type, 2, err, err_info)) {
if (*err != 0)
return -1;
return 0;
}
type = pletoh16(record_type);
if ((type != REC_HEADER1) && (type != REC_HEADER2)
&& (type != REC_HEADER3) && (type != REC_HEADER4)
&& (type != REC_HEADER5) && (type != REC_HEADER6)
&& (type != REC_HEADER7)
&& ((type != REC_V2DESC) || (maj_vers > 2)) ) {
if (file_seek(wth->fh, -2, SEEK_CUR, err) == -1)
return -1;
return 0;
}
if (!wtap_read_bytes(wth->fh, record_length, 4,
err, err_info))
return -1;
length = pletoh16(record_length);
if ((network == NETWORK_SYNCHRO || network == NETWORK_ASYNC) &&
type == REC_HEADER2) {
bytes_to_read = MIN(length, (int)sizeof buffer);
if (!wtap_read_bytes(wth->fh, buffer,
bytes_to_read, err, err_info))
return -1;
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
*err = WTAP_ERR_UNSUPPORTED;
*err_info = g_strdup_printf("ngsniffer: WAN capture has too-short protocol list");
return -1;
}
if (strncmp((char *)buffer, x_25_str, sizeof x_25_str - 1) == 0) {
wth->file_encap = WTAP_ENCAP_LAPB;
} else {
*err = WTAP_ERR_UNSUPPORTED;
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
*err = WTAP_ERR_UNSUPPORTED;
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
*err = WTAP_ERR_UNSUPPORTED;
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
*err = WTAP_ERR_UNSUPPORTED;
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
guint padding;
ngsniffer = (ngsniffer_t *)wth->priv;
for (;;) {
*data_offset = ngsniffer->seq.uncomp_offset;
ret = ngsniffer_process_record(wth, FALSE, &padding,
&wth->phdr, wth->frame_buffer, err, err_info);
if (ret < 0) {
return FALSE;
}
switch (ret) {
case REC_FRAME2:
case REC_FRAME4:
case REC_FRAME6:
if (padding != 0) {
if (!ng_file_skip_seq(wth, padding, err,
err_info))
return FALSE;
}
return TRUE;
case REC_EOF:
*err = 0;
return FALSE;
default:
if (padding != 0) {
if (!ng_file_skip_seq(wth, padding, err,
err_info))
return FALSE;
}
break;
}
}
}
static gboolean
ngsniffer_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
int ret;
if (!ng_file_seek_rand(wth, seek_off, err, err_info))
return FALSE;
ret = ngsniffer_process_record(wth, TRUE, NULL, phdr, buf, err, err_info);
if (ret < 0) {
return FALSE;
}
switch (ret) {
case REC_FRAME2:
case REC_FRAME4:
case REC_FRAME6:
break;
default:
g_assert_not_reached();
return FALSE;
}
return TRUE;
}
static int
ngsniffer_process_record(wtap *wth, gboolean is_random, guint *padding,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
char record_type[2];
char record_length[4];
guint16 type, length;
struct frame2_rec frame2;
struct frame4_rec frame4;
struct frame6_rec frame6;
guint16 time_low, time_med, true_size, size;
guint8 time_high, time_day;
guint64 t, tsecs, tpsecs;
if (!ng_read_bytes_or_eof(wth, record_type, 2, is_random, err, err_info)) {
if (*err != 0)
return -1;
return REC_EOF;
}
if (!ng_read_bytes(wth, record_length, 4, is_random, err, err_info))
return -1;
type = pletoh16(record_type);
length = pletoh16(record_length);
ngsniffer = (ngsniffer_t *)wth->priv;
switch (type) {
case REC_FRAME2:
if (ngsniffer->network == NETWORK_ATM) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: REC_FRAME2 record in an ATM Sniffer file");
return -1;
}
if (!ng_read_bytes(wth, &frame2, (unsigned int)sizeof frame2,
is_random, err, err_info))
return -1;
time_low = pletoh16(&frame2.time_low);
time_med = pletoh16(&frame2.time_med);
time_high = frame2.time_high;
time_day = frame2.time_day;
size = pletoh16(&frame2.size);
true_size = pletoh16(&frame2.true_size);
length -= sizeof frame2;
set_pseudo_header_frame2(wth, &phdr->pseudo_header, &frame2);
break;
case REC_FRAME4:
if (ngsniffer->network != NETWORK_ATM) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: REC_FRAME4 record in a non-ATM Sniffer file");
return -1;
}
if (!ng_read_bytes(wth, &frame4, (unsigned int)sizeof frame4,
is_random, err, err_info))
return -1;
time_low = pletoh16(&frame4.time_low);
time_med = pletoh16(&frame4.time_med);
time_high = frame4.time_high;
time_day = frame4.time_day;
size = pletoh16(&frame4.size);
true_size = pletoh16(&frame4.true_size);
if (ngsniffer->maj_vers >= 5)
length -= sizeof frame4;
else {
if (ngsniffer->min_vers >= 95)
length -= sizeof frame2;
else
length -= sizeof frame4;
}
set_pseudo_header_frame4(&phdr->pseudo_header, &frame4);
break;
case REC_FRAME6:
if (!ng_read_bytes(wth, &frame6, (unsigned int)sizeof frame6,
is_random, err, err_info))
return -1;
time_low = pletoh16(&frame6.time_low);
time_med = pletoh16(&frame6.time_med);
time_high = frame6.time_high;
time_day = frame6.time_day;
size = pletoh16(&frame6.size);
true_size = pletoh16(&frame6.true_size);
length -= sizeof frame6;
set_pseudo_header_frame6(wth, &phdr->pseudo_header, &frame6);
break;
case REC_EOF:
*err = 0;
return REC_EOF;
default:
if (padding != NULL) {
*padding = length;
}
return type;
}
if (size > length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("ngsniffer: Record length is less than packet size");
return -1;
}
if (padding != NULL) {
*padding = length - size;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = true_size ? WTAP_HAS_TS|WTAP_HAS_CAP_LEN : WTAP_HAS_TS;
phdr->len = true_size ? true_size : size;
phdr->caplen = size;
ws_buffer_assure_space(buf, size);
if (!ng_read_bytes(wth, ws_buffer_start_ptr(buf), size, is_random,
err, err_info))
return -1;
phdr->pkt_encap = fix_pseudo_header(wth->file_encap,
buf, length, &phdr->pseudo_header);
t = (((guint64)time_high)<<32) | (((guint64)time_med) << 16) | time_low;
t *= ngsniffer->timeunit;
tsecs = t/G_GUINT64_CONSTANT(1000000000000);
tpsecs = t - tsecs*G_GUINT64_CONSTANT(1000000000000);
tsecs += time_day*86400;
tsecs += ngsniffer->start;
phdr->ts.secs = (time_t)tsecs;
phdr->ts.nsecs = (int)(tpsecs/1000);
return type;
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
static void
set_pseudo_header_frame4(union wtap_pseudo_header *pseudo_header,
struct frame4_rec *frame4)
{
guint32 StatusWord;
guint8 aal_type, hl_type;
guint16 vpi, vci;
pseudo_header->atm.flags = 0;
StatusWord = pletoh32(&frame4->atm_info.StatusWord);
if (StatusWord & SW_RAW_CELL)
pseudo_header->atm.flags |= ATM_RAW_CELL;
aal_type = frame4->atm_info.AppTrafType & ATT_AALTYPE;
hl_type = frame4->atm_info.AppTrafType & ATT_HLTYPE;
vpi = pletoh16(&frame4->atm_info.Vpi);
vci = pletoh16(&frame4->atm_info.Vci);
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
pseudo_header->atm.channel = pletoh16(&frame4->atm_info.channel);
pseudo_header->atm.cells = pletoh16(&frame4->atm_info.cells);
pseudo_header->atm.aal5t_u2u = pletoh16(&frame4->atm_info.Trailer.aal5t_u2u);
pseudo_header->atm.aal5t_len = pletoh16(&frame4->atm_info.Trailer.aal5t_len);
pseudo_header->atm.aal5t_chksum = pntoh32(&frame4->atm_info.Trailer.aal5t_chksum);
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
fix_pseudo_header(int encap, Buffer *buf, int len,
union wtap_pseudo_header *pseudo_header)
{
const guint8 *pd;
pd = ws_buffer_start_ptr(buf);
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
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
gboolean
ngsniffer_dump_open(wtap_dumper *wdh, int *err)
{
ngsniffer_dump_t *ngsniffer;
char buf[6] = {REC_VERS, 0x00, 0x12, 0x00, 0x00, 0x00};
wdh->subtype_write = ngsniffer_dump;
wdh->subtype_finish = ngsniffer_dump_finish;
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
const guint8 *pd, int *err, gchar **err_info _U_)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
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
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if (phdr->caplen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if (ngsniffer->first_frame) {
ngsniffer->first_frame=FALSE;
tm = localtime(&phdr->ts.secs);
if (tm != NULL && tm->tm_year >= DOS_YEAR_OFFSET) {
start_date = (tm->tm_year - DOS_YEAR_OFFSET) << DOS_YEAR_SHIFT;
start_date |= (tm->tm_mon - DOS_MONTH_OFFSET) << DOS_MONTH_SHIFT;
start_date |= tm->tm_mday << DOS_DAY_SHIFT;
ngsniffer->start = phdr->ts.secs - (3600*tm->tm_hour + 60*tm->tm_min + tm->tm_sec);
} else {
start_date = 0;
ngsniffer->start = 0;
}
maj_vers = 4;
min_vers = 0;
version.maj_vers = GUINT16_TO_LE(maj_vers);
version.min_vers = GUINT16_TO_LE(min_vers);
version.time = 0;
version.date = GUINT16_TO_LE(start_date);
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
t = tsecs*G_GUINT64_CONSTANT(1000000000000) +
phdr->ts.nsecs*G_GUINT64_CONSTANT(1000);
t /= Psec[1];
t_low = (guint16)((t >> 0) & 0xFFFF);
t_med = (guint16)((t >> 16) & 0xFFFF);
t_high = (guint8)((t >> 32) & 0xFF);
rec_hdr.time_low = GUINT16_TO_LE(t_low);
rec_hdr.time_med = GUINT16_TO_LE(t_med);
rec_hdr.time_high = t_high;
rec_hdr.size = GUINT16_TO_LE(phdr->caplen);
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
rec_hdr.true_size = phdr->len != phdr->caplen ? GUINT16_TO_LE(phdr->len) : 0;
rec_hdr.rsvd = 0;
if (!wtap_dump_file_write(wdh, &rec_hdr, sizeof rec_hdr, err))
return FALSE;
if (!wtap_dump_file_write(wdh, pd, phdr->caplen, err))
return FALSE;
return TRUE;
}
static gboolean
ngsniffer_dump_finish(wtap_dumper *wdh, int *err)
{
char buf[6] = {REC_EOF, 0x00, 0x00, 0x00, 0x00, 0x00};
if (!wtap_dump_file_write(wdh, buf, 6, err))
return FALSE;
return TRUE;
}
static int
SnifferDecompress(unsigned char *inbuf, size_t inlen, unsigned char *outbuf,
size_t outlen, int *err, gchar **err_info)
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
while (pin < pin_end)
{
bit_mask = bit_mask >> 1;
if ( 0 == bit_mask )
{
CHECK_INPUT_POINTER( 3 );
bit_mask = 0x8000;
bit_value = pletoh16(pin);
pin += 2;
}
if ( !(bit_mask & bit_value) )
{
CHECK_OUTPUT_LENGTH( 1 );
*(pout++) = *(pin++);
}
else
{
code_type = (unsigned int) ((*pin) >> 4 ) & 0xF;
code_low = (unsigned int) ((*pin) & 0xF );
pin++;
switch ( code_type )
{
case 0 :
length = code_low + 3;
APPEND_RLE_BYTE( length );
break;
case 1 :
CHECK_INPUT_POINTER( 1 );
length = code_low + ((unsigned int)(*pin++) << 4) + 19;
APPEND_RLE_BYTE( length );
break;
case 2 :
FETCH_OFFSET_HIGH;
CHECK_INPUT_POINTER( 1 );
length = (unsigned int)(*pin++) + 16;
APPEND_LZW_STRING( offset, length );
break;
default :
FETCH_OFFSET_HIGH;
length = code_type;
APPEND_LZW_STRING( offset, length );
break;
}
}
}
return (int) ( pout - outbuf );
}
static gboolean
ng_read_bytes_or_eof(wtap *wth, void *buffer, unsigned int nbytes, gboolean is_random,
int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
FILE_T infile;
ngsniffer_comp_stream_t *comp_stream;
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
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_UNCOMPRESSED) {
if (!wtap_read_bytes_or_eof(infile, buffer, nbytes, err, err_info))
return FALSE;
comp_stream->uncomp_offset += nbytes;
comp_stream->comp_offset += nbytes;
return TRUE;
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
if (!read_blob(infile, comp_stream, err, err_info))
return FALSE;
}
while (nbytes > 0) {
bytes_left = comp_stream->nbytes - comp_stream->nextout;
if (bytes_left == 0) {
if (is_random) {
ngsniffer->current_blob = g_list_next(ngsniffer->current_blob);
if (!ngsniffer->current_blob) {
*err = WTAP_ERR_CANT_SEEK;
return FALSE;
}
} else {
if (wth->random_fh != NULL) {
blob = g_new(blob_info_t,1);
blob->blob_comp_offset = comp_stream->comp_offset;
blob->blob_uncomp_offset = comp_stream->uncomp_offset;
ngsniffer->last_blob = g_list_append(ngsniffer->last_blob,
blob);
}
}
if (!read_blob(infile, comp_stream, err, err_info))
return FALSE;
bytes_left = comp_stream->nbytes - comp_stream->nextout;
}
bytes_to_copy = nbytes;
if (bytes_to_copy > bytes_left)
bytes_to_copy = bytes_left;
memcpy(outbuffer, &comp_stream->buf[comp_stream->nextout],
bytes_to_copy);
nbytes -= bytes_to_copy;
copied_bytes += bytes_to_copy;
outbuffer += bytes_to_copy;
comp_stream->nextout += bytes_to_copy;
comp_stream->uncomp_offset += bytes_to_copy;
}
return TRUE;
}
static gboolean
ng_read_bytes(wtap *wth, void *buffer, unsigned int nbytes, gboolean is_random,
int *err, gchar **err_info)
{
if (!ng_read_bytes_or_eof(wth, buffer, nbytes, is_random, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
read_blob(FILE_T infile, ngsniffer_comp_stream_t *comp_stream, int *err,
gchar **err_info)
{
int in_len;
unsigned short blob_len;
gint16 blob_len_host;
gboolean uncompressed;
unsigned char *file_inbuf;
int out_len;
if (!wtap_read_bytes_or_eof(infile, &blob_len, 2, err, err_info))
return FALSE;
comp_stream->comp_offset += 2;
blob_len_host = pletoh16(&blob_len);
if (blob_len_host < 0) {
in_len = -blob_len_host;
uncompressed = TRUE;
} else {
in_len = blob_len_host;
uncompressed = FALSE;
}
file_inbuf = (unsigned char *)g_malloc(INBUF_SIZE);
if (!wtap_read_bytes(infile, file_inbuf, in_len, err, err_info)) {
g_free(file_inbuf);
return FALSE;
}
comp_stream->comp_offset += in_len;
if (uncompressed) {
memcpy(comp_stream->buf, file_inbuf, in_len);
out_len = in_len;
} else {
out_len = SnifferDecompress(file_inbuf, in_len,
comp_stream->buf, OUTBUF_SIZE, err,
err_info);
if (out_len < 0) {
g_free(file_inbuf);
return FALSE;
}
}
g_free(file_inbuf);
comp_stream->nextout = 0;
comp_stream->nbytes = out_len;
return TRUE;
}
static gboolean
ng_file_skip_seq(wtap *wth, gint64 delta, int *err, gchar **err_info)
{
ngsniffer_t *ngsniffer;
char *buf;
unsigned int amount_to_read;
ngsniffer = (ngsniffer_t *)wth->priv;
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_UNCOMPRESSED) {
ngsniffer->seq.uncomp_offset += delta;
return file_skip(wth->fh, delta, err);
}
g_assert(delta >= 0);
buf = (char *)g_malloc(INBUF_SIZE);
while (delta != 0) {
if (delta > INBUF_SIZE)
amount_to_read = INBUF_SIZE;
else
amount_to_read = (unsigned int) delta;
if (!ng_read_bytes(wth, buf, amount_to_read, FALSE, err, err_info)) {
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
if (wth->file_type_subtype == WTAP_FILE_TYPE_SUBTYPE_NGSNIFFER_UNCOMPRESSED) {
if (file_seek(wth->random_fh, offset, SEEK_SET, err) == -1)
return FALSE;
return TRUE;
}
delta = offset - ngsniffer->rand.uncomp_offset;
new_list = NULL;
if (delta > 0) {
if ((size_t)(ngsniffer->rand.nextout + delta) >= ngsniffer->rand.nbytes) {
if (ngsniffer->current_blob == NULL) {
new_list = ngsniffer->first_blob;
} else {
new_list = g_list_next(ngsniffer->current_blob);
}
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
if (new_list == NULL) {
*err = WTAP_ERR_CANT_SEEK;
return FALSE;
}
}
} else if (delta < 0) {
if (ngsniffer->rand.nextout + delta < 0) {
if (ngsniffer->current_blob == NULL) {
new_list = ngsniffer->last_blob;
} else {
new_list = g_list_previous(ngsniffer->current_blob);
}
while (new_list) {
new_blob = (blob_info_t *)new_list->data;
if (new_blob->blob_uncomp_offset <= offset)
break;
new_list = g_list_previous(new_list);
}
if (new_list == NULL) {
*err = WTAP_ERR_CANT_SEEK;
return FALSE;
}
}
}
if (new_list != NULL) {
new_blob = (blob_info_t *)new_list->data;
if (file_seek(wth->random_fh, new_blob->blob_comp_offset, SEEK_SET, err) == -1)
return FALSE;
if (ngsniffer->rand.buf == NULL) {
ngsniffer->rand.buf = (unsigned char *)g_malloc(OUTBUF_SIZE);
}
ngsniffer->current_blob = new_list;
ngsniffer->rand.uncomp_offset = new_blob->blob_uncomp_offset;
ngsniffer->rand.comp_offset = new_blob->blob_comp_offset;
if (!read_blob(wth->random_fh, &ngsniffer->rand, err, err_info))
return FALSE;
delta = offset - ngsniffer->rand.uncomp_offset;
g_assert(delta >= 0 && (unsigned long)delta < ngsniffer->rand.nbytes);
}
ngsniffer->rand.nextout += (int) delta;
ngsniffer->rand.uncomp_offset += delta;
return TRUE;
}
