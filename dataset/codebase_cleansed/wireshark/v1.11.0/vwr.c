int vwr_open(wtap *wth, int *err, gchar **err_info)
{
int fpgaVer;
vwr_t *vwr;
*err = 0;
fpgaVer = vwr_get_fpga_version(wth, err, err_info);
if (fpgaVer == -1) {
return -1;
}
if (fpgaVer == UNKNOWN_FPGA) {
return 0;
}
vwr = (vwr_t *)g_malloc0(sizeof(vwr_t));
wth->priv = (void *)vwr;
vwr->FPGA_VERSION = fpgaVer;
setup_defaults(vwr, fpgaVer);
wth->snapshot_length = 0;
wth->subtype_read = vwr_read;
wth->subtype_seek_read = vwr_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
wth->file_encap = WTAP_ENCAP_IXVERIWAVE;
if (fpgaVer == S2_W_FPGA || fpgaVer == S1_W_FPGA || fpgaVer == S3_W_FPGA)
wth->file_type = WTAP_FILE_VWR_80211;
else if (fpgaVer == vVW510012_E_FPGA || fpgaVer == vVW510024_E_FPGA)
wth->file_type = WTAP_FILE_VWR_ETH;
return(1);
}
static gboolean vwr_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int rec_size = 0, IS_TX;
if (!vwr_read_rec_header(vwr, wth->fh, &rec_size, &IS_TX, err, err_info))
return(FALSE);
*data_offset = (file_tell(wth->fh) - 16);
if (!vwr_process_rec_data(wth, wth->fh, rec_size,
wth->frame_buffer, vwr, IS_TX, err, err_info))
return(FALSE);
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return(TRUE);
}
static gboolean vwr_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr _U_, Buffer *buf, int pkt_size _U_,
int *err, gchar **err_info)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int rec_size, IS_TX;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return(FALSE);
if (!vwr_read_rec_header(vwr, wth->random_fh, &rec_size, &IS_TX, err, err_info))
return(FALSE);
return vwr_process_rec_data(wth, wth->random_fh, rec_size, buf,
vwr, IS_TX, err, err_info);
}
static gboolean vwr_read_rec_header(vwr_t *vwr, FILE_T fh, int *rec_size, int *IS_TX, int *err, gchar **err_info)
{
int f_len, v_type;
guint8 header[16];
errno = WTAP_ERR_CANT_READ;
*rec_size = 0;
while (1) {
if (file_read(header, 16, fh) != 16) {
*err = file_error(fh, err_info);
return(FALSE);
}
if ((f_len = decode_msg(vwr, header, &v_type, IS_TX)) != 0) {
if (f_len > B_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vwr: Invalid message record length %d", f_len);
return(FALSE);
}
else if (v_type != VT_FRAME) {
if (file_seek(fh, f_len, SEEK_CUR, err) < 0)
return(FALSE);
}
else {
*rec_size = f_len;
return(TRUE);
}
}
}
}
static int vwr_get_fpga_version(wtap *wth, int *err, gchar **err_info)
{
guint8 rec[B_SIZE];
guint8 header[16];
int rec_size = 0;
guint8 i;
guint8 *s_510006_ptr = NULL;
guint8 *s_510024_ptr = NULL;
guint8 *s_510012_ptr = NULL;
gint64 filePos = -1;
guint32 frame_type = 0;
int f_len, v_type;
guint16 data_length = 0;
guint16 fpga_version;
filePos = file_tell(wth->fh);
if (filePos == -1) {
*err = file_error(wth->fh, err_info);
return(-1);
}
fpga_version = 1000;
while ((file_read(header, 16, wth->fh)) == 16) {
if ((f_len = decode_msg(NULL, header, &v_type, NULL)) != 0) {
if (f_len > B_SIZE) {
return(UNKNOWN_FPGA);
}
else if (v_type != VT_FRAME) {
if (file_seek(wth->fh, f_len, SEEK_CUR, err) < 0)
return(-1);
}
else {
rec_size = f_len;
if (file_read(rec, rec_size, wth->fh) != rec_size) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return(-1);
return(UNKNOWN_FPGA);
}
if (rec_size > v22_W_STATS_LEN) {
s_510006_ptr = &(rec[rec_size - v22_W_STATS_LEN]);
data_length = pntohs(&s_510006_ptr[v22_W_OCTET_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
frame_type = pntohl(&s_510006_ptr[v22_W_FRAME_TYPE_OFF]);
if (rec_size == (data_length + v22_W_STATS_LEN + i) && (frame_type & v22_W_IS_80211) == 0x1000000) {
fpga_version = S1_W_FPGA;
}
}
if ((rec_size > v22_E_STATS_LEN) && (fpga_version == 1000)) {
s_510012_ptr = &(rec[rec_size - v22_E_STATS_LEN]);
data_length = pntohs(&s_510012_ptr[v22_E_OCTET_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + v22_E_STATS_LEN + i))
fpga_version = vVW510012_E_FPGA;
}
if ((rec_size > vVW510021_W_STATS_LEN) && (fpga_version == 1000)) {
data_length = (256 * (rec[vVW510021_W_MSDU_LENGTH_OFF + 1] & 0x1f)) + rec[vVW510021_W_MSDU_LENGTH_OFF];
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + vVW510021_W_STATS_LEN +vVW510021_W_AFTERHEADER_LEN+12+i))
fpga_version = S2_W_FPGA;
}
if ((rec_size > vVW510024_E_STATS_LEN) && (fpga_version == 1000)) {
s_510024_ptr = &(rec[rec_size - vVW510024_E_STATS_LEN]);
data_length = pntohs(&s_510024_ptr[vVW510024_E_MSDU_LENGTH_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + vVW510024_E_STATS_LEN + i))
fpga_version = vVW510024_E_FPGA;
}
if ((rec_size > vVW510021_W_STATS_LEN) && (fpga_version == 1000)) {
if (header[8] == 48)
fpga_version = S3_W_FPGA;
}
if ((rec_size > vVW510021_W_STATS_LEN) && (fpga_version == 1000)) {
if (header[8] == 48)
fpga_version = S3_W_FPGA;
}
if (fpga_version != 1000)
{
if (file_seek (wth->fh, filePos, SEEK_SET, err) == -1) {
return (-1);
}
return(fpga_version);
}
}
}
}
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return(-1);
return(UNKNOWN_FPGA);
}
static void vwr_read_rec_data_wlan(wtap *wth, guint8 *data_ptr, guint8 *rec, int rec_size, int IS_TX)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int bytes_written = 0;
ext_rtap_fields er_fields;
stats_common_fields common_fields;
int mpdu_offset;
switch (vwr->FPGA_VERSION) {
case S1_W_FPGA:
mpdu_offset = parse_s1_W_stats(wth, rec, rec_size, &er_fields, &common_fields);
break;
case S2_W_FPGA:
case S3_W_FPGA:
mpdu_offset = parse_s2_W_stats(wth, rec, rec_size, &er_fields, &common_fields, IS_TX);
break;
default:
return;
}
phtoles(&data_ptr[bytes_written], common_fields.vw_port_type);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_fields.it_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_fields.vw_msdu_length);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], common_fields.vw_flowid);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], common_fields.vw_vcid);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_fields.vw_seqnum);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], common_fields.vw_latency);
bytes_written += 4;
phtolel(&data_ptr[bytes_written], common_fields.vw_sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], common_fields.vw_startt);
bytes_written += 8;
phtolell(&data_ptr[bytes_written], common_fields.vw_endt);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], common_fields.vw_pktdur);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], er_fields.it_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], er_fields.flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], er_fields.chanflags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], er_fields.phyRate);
bytes_written += 2;
data_ptr[bytes_written] = er_fields.plcpType;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.mcsIndex;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.nss;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.signal;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.signalb;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.signalc;
bytes_written += 1;
data_ptr[bytes_written] = er_fields.signald;
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
phtoles(&data_ptr[bytes_written], er_fields.vw_flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], er_fields.vw_ht_length);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], er_fields.vw_info);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], er_fields.vw_errors);
bytes_written += 4;
if ( rec_size < ((int)common_fields.vw_msdu_length + (int)vwr->STATS_LEN) )
memcpy(&data_ptr[bytes_written], &rec[mpdu_offset], common_fields.vw_msdu_length);
else if (common_fields.vw_msdu_length >= 4)
memcpy(&data_ptr[bytes_written], &rec[mpdu_offset], common_fields.vw_msdu_length - 4);
else
memcpy(&data_ptr[bytes_written], &rec[mpdu_offset], common_fields.vw_msdu_length);
}
static int parse_s1_W_stats(wtap *wth, guint8 *rec, int rec_size, ext_rtap_fields * er_fields, stats_common_fields * common_fields)
{
vwr_t *vwr = (vwr_t *)wth->priv;
register int i;
register guint8 *s_ptr, *m_ptr;
guint16 octets, msdu_length;
guint64 tmp_len;
guint16 rflags;
guint8 m_type, flow_seq;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint32 latency;
guint64 start_time, s_sec, s_usec = LL_ZERO;
guint64 end_time;
guint32 info;
gint16 rssi;
int f_tx;
guint8 plcp_type, mcs_index, nss;
guint16 vc_id, flow_id, ht_len=0;
guint32 d_time, errors;
guint16 r_hdr_len;
int sig_off, pay_off;
guint64 sig_ts;
float phyRate;
if (rec_size<64)
rec_size = 64;
s_ptr = &(rec[rec_size - 64]);
m_type = s_ptr[1] & 0x7;
f_tx = !(s_ptr[1] & 0x8);
octets = pntohs(&s_ptr[8]);
vc_id = pntohs(&s_ptr[2]) & 0x3ff;
flow_seq = s_ptr[4];
latency = (s_ptr[40 + 6] << 8) | (s_ptr[40 + 7]);
for (i = 0; i < 4; i++)
latency = (latency << 8) | s_ptr[40 + i];
flow_id = pntohs(&s_ptr[6]);
errors = pntohs(&s_ptr[10]);
info = pntohs(&s_ptr[54]);
rssi = (s_ptr[21] & 0x80) ? (-1 * (s_ptr[21] & 0x7f)) : s_ptr[21];
plcp_type = 0;
nss = 1;
if (m_type == vwr->MT_OFDM)
mcs_index = get_ofdm_rate(rec);
else if ((m_type == vwr->MT_CCKL) || (m_type == vwr->MT_CCKS))
mcs_index = get_cck_rate(rec);
else
mcs_index = 1;
rflags = (m_type == vwr->MT_CCKS) ? RADIOTAP_F_SHORTPRE : 0;
phyRate = getRate(plcp_type, mcs_index, rflags, nss);
m_ptr = &(rec[((m_type == vwr->MT_OFDM) ? 4 : 6)]);
tmp_len = (m_type == vwr->MT_OFDM) ? 4 : 6;
if (octets >= tmp_len)
octets -= (guint16) tmp_len;
else
octets = 0;
if (octets > (rec_size - 64))
octets = (rec_size - 64);
msdu_length = octets;
s_time = pcoreytohll(&s_ptr[24]);
e_time = pcoreytohll(&s_ptr[32]);
d_time = (guint32)((e_time - s_time) / NS_IN_US);
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
pay_off = 42;
sig_off = find_signature(m_ptr, rec_size - 6, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= (rec_size - 48)))
sig_ts = get_signature_ts(m_ptr, sig_off);
else
sig_ts = 0;
r_hdr_len = STATS_COMMON_FIELDS_LEN + EXT_RTAP_FIELDS_LEN;
tmp_len = (msdu_length - 4) + r_hdr_len;
wth->phdr.len = tmp_len<=G_MAXUINT32 ? (guint32) tmp_len : 0;
tmp_len = (octets - 4) + r_hdr_len;
wth->phdr.caplen = tmp_len<=G_MAXUINT32 ? (guint32) tmp_len : 0;
wth->phdr.len = (msdu_length - 4) + r_hdr_len;
wth->phdr.caplen = (octets - 4) + r_hdr_len;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = (time_t)s_sec;
wth->phdr.ts.nsecs = (int)(s_usec * 1000);
wth->phdr.pkt_encap = WTAP_ENCAP_IXVERIWAVE;
common_fields->vw_port_type = 0;
common_fields->it_len = STATS_COMMON_FIELDS_LEN;
common_fields->vw_vcid = (guint16)vc_id;
common_fields->vw_flowid = (guint16)flow_id;
common_fields->vw_seqnum = (guint16)flow_seq;
if (!f_tx && sig_ts != 0)
common_fields->vw_latency = (guint32)latency;
else
common_fields->vw_latency = 0;
common_fields->vw_pktdur = (guint32)d_time;
common_fields->vw_msdu_length = (guint16)msdu_length;
common_fields->vw_sig_ts = (guint32)sig_ts;
common_fields->vw_startt = start_time;
common_fields->vw_endt = end_time;
er_fields->it_len = EXT_RTAP_FIELDS_LEN;
er_fields->flags = rflags;
er_fields->phyRate = (guint16)(phyRate * 10);
er_fields->plcpType = plcp_type;
er_fields->mcsIndex = mcs_index;
er_fields->nss = nss;
er_fields->chanflags = (m_type == vwr->MT_OFDM) ? CHAN_OFDM : CHAN_CCK;
er_fields->signal = (gint8)rssi;
er_fields->signalb = 100;
er_fields->signalc = 100;
er_fields->signald = 100;
er_fields->vw_flags = 0;
if (f_tx)
er_fields->vw_flags |= RADIOTAP_VWF_TXF;
if (errors & vwr->FCS_ERROR)
er_fields->vw_flags |= RADIOTAP_VWF_FCSERR;
if (!f_tx && (errors & vwr->CRYPTO_ERR))
er_fields->vw_flags |= RADIOTAP_VWF_DCRERR;
if (!f_tx && (errors & vwr->RETRY_ERR))
er_fields->vw_flags |= RADIOTAP_VWF_RETRERR;
if (info & vwr->WEPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_WEP;
else if (info & vwr->TKIPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_TKIP;
else if (info & vwr->CCMPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_CCMP;
er_fields->vw_errors = (guint32)errors;
er_fields->vw_info = (guint16)info;
er_fields->vw_ht_length = (guint16)ht_len;
return (m_type == vwr->MT_OFDM) ? 4 : 6;
}
static int parse_s2_W_stats(wtap *wth, guint8 *rec, int rec_size, ext_rtap_fields * er_fields, stats_common_fields * common_fields, int IS_TX)
{
vwr_t *vwr = (vwr_t *)wth->priv;
register int i;
register guint8 *s_start_ptr,*s_trail_ptr, *plcp_ptr, *m_ptr;
guint32 msdu_length, actual_octets;
guint64 tmp_len;
guint8 l1p_1,l1p_2, flow_seq, plcp_type, mcs_index, nss;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint64 latency = LL_ZERO;
guint64 start_time, s_sec, s_usec = LL_ZERO;
guint64 end_time;
guint16 info;
guint32 errors;
gint16 rssi[] = {0,0,0,0};
int f_tx;
guint16 vc_id, ht_len=0;
guint32 flow_id, d_time;
guint16 r_hdr_len;
int sig_off, pay_off;
guint64 sig_ts, tsid;
guint16 chanflags = 0;
guint16 radioflags = 0;
guint64 delta_b;
if (rec_size<48)
rec_size = 48;
s_start_ptr = &(rec[0]);
s_trail_ptr = &(rec[rec_size - 48]);
l1p_1 = s_start_ptr[0];
l1p_2 = s_start_ptr[1];
if (vwr->FPGA_VERSION == S2_W_FPGA)
{
mcs_index = l1p_1 & 0x3f;
plcp_type = l1p_2 & 0x03;
msdu_length = ((s_start_ptr[4] & 0x1f) << 8) + s_start_ptr[3];
actual_octets = msdu_length;
vc_id = pntohs(&s_start_ptr[6]);
if (IS_TX)
{
rssi[0] = (s_start_ptr[2] & 0x80) ? -1 * (s_start_ptr[2] & 0x7f) : s_start_ptr[2] & 0x7f;
}
else
{
rssi[0] = (s_start_ptr[2] & 0x80) ? (s_start_ptr[2]- 256) : s_start_ptr[2];
}
rssi[1] = 100;
rssi[2] = 100;
rssi[3] = 100;
nss = 0;
plcp_ptr = &(rec[8]);
}
else
{
plcp_type = l1p_2 & 0xf;
if (plcp_type == vVW510021_W_PLCP_VHT_MIXED)
{
mcs_index = l1p_1 & 0x0f;
nss = (l1p_1 >> 4 & 0x3) + 1;
}
else
{
mcs_index = l1p_1 & 0x3f;
nss = 0;
}
msdu_length = pntoh24(&s_start_ptr[9]);
actual_octets = msdu_length;
vc_id = pntohs(&s_start_ptr[14]) & 0x3ff;
for (i = 0; i < 4; i++)
{
if (IS_TX)
{
rssi[i] = (s_start_ptr[4+i] & 0x80) ? -1 * (s_start_ptr[4+i] & 0x7f) : s_start_ptr[4+i] & 0x7f;
}
else
{
rssi[i] = (s_start_ptr[4+i] >= 128) ? (s_start_ptr[4+i] - 256) : s_start_ptr[4+i];
}
}
plcp_ptr = &(rec[16]);
}
f_tx = IS_TX;
flow_seq = s_trail_ptr[32];
latency = 0x00000000;
flow_id = pntoh24(&s_trail_ptr[33]);
tsid = (s_trail_ptr[36 + 6] << 8) | (s_trail_ptr[36 + 7]);
for (i = 0; i < 4; i++)
tsid = (tsid << 8) | s_trail_ptr[36 + i];
errors = pntohl(&s_trail_ptr[16]);
info = pntohs(&s_trail_ptr[22]);
if ((info & 0xFC00) != 0)
ht_len = pletohs(&s_start_ptr[vwr->PLCP_LENGTH_OFF]);
if (plcp_type == vVW510021_W_PLCP_LEGACY){
if (mcs_index < 4) {
chanflags |= CHAN_CCK;
}
else {
chanflags |= CHAN_OFDM;
}
}
else if (plcp_type == vVW510021_W_PLCP_MIXED) {
radioflags |= RADIOTAP_F_CHAN_HT | ((plcp_ptr[3] & 0x80) ? RADIOTAP_F_CHAN_40MHZ : 0) |
((l1p_1 & 0x40) ? 0 : RADIOTAP_F_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
}
else if (plcp_type == vVW510021_W_PLCP_GREENFIELD) {
radioflags |= RADIOTAP_F_CHAN_HT | ((plcp_ptr[0] & 0x80) ? RADIOTAP_F_CHAN_40MHZ : 0) |
((l1p_1 & 0x40) ? 0 : RADIOTAP_F_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
}
else if (plcp_type == vVW510021_W_PLCP_VHT_MIXED) {
guint8 SBW = l1p_2 >> 4 & 0xf;
radioflags |= RADIOTAP_F_CHAN_VHT | ((l1p_1 & 0x40) ? 0 : RADIOTAP_F_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
if (SBW == 3)
radioflags |= RADIOTAP_F_CHAN_40MHZ;
else if (SBW == 4)
radioflags |= RADIOTAP_F_CHAN_80MHZ;
}
if (msdu_length > (guint32)(rec_size - 48)) {
msdu_length = (guint32)(rec_size - 48);
}
s_time = pcoreytohll(&s_trail_ptr[0]);
e_time = pcoreytohll(&s_trail_ptr[8]);
d_time = (guint32)((e_time - s_time) / NS_IN_US);
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
m_ptr = &(rec[8+12]);
pay_off = 42;
sig_off = find_signature(m_ptr, rec_size - 20, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= (rec_size - 48)))
sig_ts = get_signature_ts(m_ptr, sig_off);
else
sig_ts = 0;
if (!IS_TX) {
if (tsid < s_time) {
latency = s_time - tsid;
} else {
delta_b = tsid - s_time;
if (delta_b > 0x10000000)
latency = 0;
else
latency = delta_b;
}
}
r_hdr_len = STATS_COMMON_FIELDS_LEN + EXT_RTAP_FIELDS_LEN;
tmp_len = (actual_octets - 4) + r_hdr_len;
wth->phdr.len = tmp_len<=G_MAXUINT32 ? (guint32) tmp_len : 0;
tmp_len = (msdu_length - 4) + r_hdr_len;
wth->phdr.caplen = tmp_len<=G_MAXUINT32 ? (guint32) tmp_len : 0;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = (time_t)s_sec;
wth->phdr.ts.nsecs = (int)(s_usec * 1000);
wth->phdr.pkt_encap = WTAP_ENCAP_IXVERIWAVE;
common_fields->vw_port_type = 0;
common_fields->it_len = STATS_COMMON_FIELDS_LEN;
common_fields->vw_vcid = (guint16)vc_id;
common_fields->vw_msdu_length = (guint16)msdu_length;
common_fields->vw_flowid = (guint32)flow_id;
common_fields->vw_seqnum = (guint16)flow_seq;
if (!f_tx && (sig_ts != 0) )
common_fields->vw_latency = (guint32)latency;
else
common_fields->vw_latency = 0;
common_fields->vw_pktdur = (guint32)d_time;
common_fields->vw_startt = start_time;
common_fields->vw_endt = end_time;
common_fields->vw_sig_ts = (guint32)(sig_ts);
er_fields->it_len = EXT_RTAP_FIELDS_LEN;
er_fields->flags = radioflags;
if (info & vVW510021_W_IS_WEP)
er_fields->flags |= RADIOTAP_F_WEP;
if ((l1p_1 & vVW510021_W_PREAMBLE_MASK) != vVW510021_W_IS_LONGPREAMBLE && (plcp_type == vVW510021_W_PLCP_LEGACY))
er_fields->flags |= RADIOTAP_F_SHORTPRE;
er_fields->phyRate = (guint16)(getRate(plcp_type, mcs_index, er_fields->flags, nss) * 10);
er_fields->plcpType = plcp_type;
er_fields->mcsIndex = mcs_index;
er_fields->nss = nss;
er_fields->chanflags = chanflags;
er_fields->signal = (gint8)rssi[0];
er_fields->signalb = (gint8)rssi[1];
er_fields->signalc = (gint8)rssi[2];
er_fields->signald = (gint8)rssi[3];
er_fields->vw_flags = 0;
if (f_tx)
er_fields->vw_flags |= RADIOTAP_VWF_TXF;
if (errors & 0x1f)
er_fields->vw_flags |= RADIOTAP_VWF_FCSERR;
if (!f_tx && (errors & vwr->CRYPTO_ERR))
er_fields->vw_flags |= RADIOTAP_VWF_DCRERR;
if (!f_tx && (errors & vwr->RETRY_ERR))
er_fields->vw_flags |= RADIOTAP_VWF_RETRERR;
if (info & vwr->WEPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_WEP;
else if (info & vwr->TKIPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_TKIP;
else if (info & vwr->CCMPTYPE)
er_fields->vw_flags |= RADIOTAP_VWF_IS_CCMP;
er_fields->vw_errors = (guint32)errors;
er_fields->vw_ht_length = (guint16)ht_len;
er_fields->vw_info = (guint16)info;
return vwr->MPDU_OFF;
}
static void vwr_read_rec_data_ethernet(wtap *wth, guint8 *data_ptr, guint8 *rec, int rec_size, int IS_TX)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int bytes_written = 0;
register int i;
register guint8 *s_ptr, *m_ptr;
guint16 msdu_length,actual_octets;
guint8 flow_seq;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint32 latency = 0;
guint64 start_time, s_sec, s_usec = LL_ZERO;
guint64 end_time;
guint16 l4id, info, validityBits;
guint32 errors;
guint16 vc_id;
guint32 flow_id, d_time;
int f_flow;
guint32 frame_type;
stats_ethernettap_fields etap_hdr;
stats_common_fields common_hdr;
guint16 e_hdr_len;
int mac_len, sig_off, pay_off;
guint64 sig_ts, tsid;
guint64 delta_b;
m_ptr = &(rec[0]);
s_ptr = &(rec[rec_size - vwr->STATS_LEN]);
msdu_length = pntohs(&s_ptr[vwr->OCTET_OFF]);
actual_octets = msdu_length;
if (msdu_length > (rec_size - (int)vwr->STATS_LEN)) {
msdu_length = (rec_size - (int)vwr->STATS_LEN);
}
vc_id = pntohs(&s_ptr[vwr->VCID_OFF]) & vwr->VCID_MASK;
flow_seq = s_ptr[vwr->FLOWSEQ_OFF];
frame_type = pntohl(&s_ptr[vwr->FRAME_TYPE_OFF]);
if (vwr->FPGA_VERSION == vVW510024_E_FPGA) {
validityBits = pntohs(&s_ptr[vwr->VALID_OFF]);
f_flow = validityBits & vwr->FLOW_VALID;
mac_len = (validityBits & vwr->IS_VLAN) ? 16 : 14;
errors = pntohs(&s_ptr[vwr->ERRORS_OFF]);
}
else {
f_flow = s_ptr[vwr->VALID_OFF] & vwr->FLOW_VALID;
mac_len = (frame_type & vwr->IS_VLAN) ? 16 : 14;
errors = pntohs(&s_ptr[vwr->ERRORS_OFF]);
}
info = pntohs(&s_ptr[vwr->INFO_OFF]);
flow_id = pntoh24(&s_ptr[vwr->FLOWID_OFF]);
tsid = (s_ptr[vwr->LATVAL_OFF + 6] << 8) | (s_ptr[vwr->LATVAL_OFF + 7]);
for (i = 0; i < 4; i++)
tsid = (tsid << 8) | s_ptr[vwr->LATVAL_OFF + i];
l4id = pntohs(&s_ptr[vwr->L4ID_OFF]);
s_time = pcoreytohll(&s_ptr[vwr->STARTT_OFF]);
e_time = pcoreytohll(&s_ptr[vwr->ENDT_OFF]);
d_time = (guint32)((e_time - s_time));
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
if (frame_type & vwr->IS_TCP)
{
pay_off = mac_len + 40;
}
else if (frame_type & vwr->IS_UDP)
{
pay_off = mac_len + 28;
}
else if (frame_type & vwr->IS_ICMP)
{
pay_off = mac_len + 24;
}
else if (frame_type & vwr->IS_IGMP)
{
pay_off = mac_len + 28;
}
else
{
pay_off = mac_len + 20;
}
sig_off = find_signature(m_ptr, rec_size, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= msdu_length) && (f_flow != 0))
sig_ts = get_signature_ts(m_ptr, sig_off);
else
sig_ts = 0;
if (!IS_TX) {
if (sig_ts < s_time) {
latency = (guint32)(s_time - sig_ts);
} else {
delta_b = sig_ts - s_time;
if (delta_b > 0x10000000) {
latency = 0;
} else
latency = (guint32)delta_b;
}
}
e_hdr_len = STATS_COMMON_FIELDS_LEN + STATS_ETHERNETTAP_FIELDS_LEN;
wth->phdr.len = (actual_octets - 4) + e_hdr_len;
wth->phdr.caplen = (msdu_length - 4) + e_hdr_len;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = (time_t)s_sec;
wth->phdr.ts.nsecs = (int)(s_usec * 1000);
wth->phdr.pkt_encap = WTAP_ENCAP_IXVERIWAVE;
common_hdr.vw_port_type = 1;
common_hdr.it_len = STATS_COMMON_FIELDS_LEN;
etap_hdr.it_len = STATS_ETHERNETTAP_FIELDS_LEN;
etap_hdr.vw_errors = (guint32)errors;
etap_hdr.vw_info = (guint16)info;
common_hdr.vw_msdu_length = (guint16)msdu_length;
common_hdr.vw_flowid = (guint32)flow_id;
common_hdr.vw_vcid = (guint16)vc_id;
common_hdr.vw_seqnum = (guint16)flow_seq;
if (!IS_TX && (sig_ts != 0))
common_hdr.vw_latency = (guint32)latency;
else
common_hdr.vw_latency = 0;
common_hdr.vw_pktdur = (guint32)d_time;
etap_hdr.vw_l4id = (guint32)l4id;
etap_hdr.vw_flags = 0;
if (IS_TX)
etap_hdr.vw_flags |= RADIOTAP_VWF_TXF;
if (errors & vwr->FCS_ERROR)
etap_hdr.vw_flags |= RADIOTAP_VWF_FCSERR;
common_hdr.vw_startt = start_time;
common_hdr.vw_endt = end_time;
common_hdr.vw_sig_ts = (guint32)(sig_ts);
etap_hdr.it_pad2 = 0;
phtoles(&data_ptr[bytes_written], common_hdr.vw_port_type);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_hdr.it_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_hdr.vw_msdu_length);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], common_hdr.vw_flowid);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], common_hdr.vw_vcid);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], common_hdr.vw_seqnum);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], common_hdr.vw_latency);
bytes_written += 4;
phtolel(&data_ptr[bytes_written], common_hdr.vw_sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], common_hdr.vw_startt);
bytes_written += 8;
phtolell(&data_ptr[bytes_written], common_hdr.vw_endt);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], common_hdr.vw_pktdur);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], etap_hdr.it_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], etap_hdr.vw_flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], etap_hdr.vw_info);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], etap_hdr.vw_errors);
bytes_written += 4;
phtolel(&data_ptr[bytes_written], etap_hdr.vw_l4id);
bytes_written += 4;
bytes_written += 4;
if ( rec_size < ((int)actual_octets + (int)vwr->STATS_LEN) )
memcpy(&data_ptr[bytes_written], m_ptr, msdu_length);
else if (msdu_length >= 4)
memcpy(&data_ptr[bytes_written], m_ptr, msdu_length - 4);
else
memcpy(&data_ptr[bytes_written], m_ptr, msdu_length);
}
static int decode_msg(vwr_t *vwr, guint8 *rec, int *v_type, int *IS_TX)
{
guint8 cmd;
guint32 wd2, wd3;
int v_size = 0;
cmd = rec[0];
wd2 = pntohl(&rec[8]);
wd3 = pntohl(&rec[12]);
if (vwr != NULL) {
if ((cmd & vwr->HEADER_IS_TX) == vwr->HEADER_IS_TX)
*IS_TX = 1;
else if ((cmd & vwr->HEADER_IS_RX) == vwr->HEADER_IS_RX)
*IS_TX = 0;
else *IS_TX = 2;
}
switch (cmd) {
case 0x21:
case 0x31:
v_size = (int)(wd2 & 0xffff);
*v_type = VT_FRAME;
break;
case 0xc1:
case 0x8b:
v_size = (int)(wd2 & 0xffff);
*v_type = VT_CPMSG;
break;
case 0xfe:
v_size = (int)(wd3 & 0xffff);
*v_type = VT_CPMSG;
break;
default:
break;
}
return(v_size);
}
static guint8 get_ofdm_rate(guint8 *plcp)
{
switch (plcp[0] & 0x0f) {
case 0x0b: return 4;
case 0x0f: return 5;
case 0x0a: return 6;
case 0x0e: return 7;
case 0x09: return 8;
case 0x0d: return 9;
case 0x08: return 10;
case 0x0c: return 11;
default: return(0);
}
}
static guint8 get_cck_rate(guint8 *plcp)
{
switch (plcp[0]) {
case 0x0a: return 0;
case 0x14: return 1;
case 0x37: return 2;
case 0x6e: return 3;
default: return 0;
}
}
static void setup_defaults(vwr_t *vwr, guint16 fpga)
{
switch (fpga) {
case S2_W_FPGA:
vwr->STATS_LEN = vVW510021_W_STATS_LEN;
vwr->VALID_OFF = vVW510021_W_VALID_OFF;
vwr->MTYPE_OFF = vVW510021_W_MTYPE_OFF;
vwr->VCID_OFF = vVW510021_W_VCID_OFF;
vwr->FLOWSEQ_OFF = vVW510021_W_FLOWSEQ_OFF;
vwr->FLOWID_OFF = vVW510021_W_FLOWID_OFF;
vwr->ERRORS_OFF = vVW510021_W_ERRORS_OFF;
vwr->PATN_OFF = vVW510021_W_MATCH_OFF;
vwr->RSSI_OFF = vVW510021_W_RSSI_TXPOWER_OFF;
vwr->STARTT_OFF = vVW510021_W_STARTT_OFF;
vwr->ENDT_OFF = vVW510021_W_ENDT_OFF;
vwr->LATVAL_OFF = vVW510021_W_LATVAL_OFF;
vwr->INFO_OFF = vVW510021_W_INFO_OFF;
vwr->FPGA_VERSION_OFF = S2_W_FPGA_VERSION_OFF;
vwr->HEADER_VERSION_OFF = vVW510021_W_HEADER_VERSION_OFF;
vwr->OCTET_OFF = vVW510021_W_MSDU_LENGTH_OFF;
vwr->L1P_1_OFF = vVW510021_W_L1P_1_OFF;
vwr->L1P_2_OFF = vVW510021_W_L1P_2_OFF;
vwr->L4ID_OFF = vVW510021_W_L4ID_OFF;
vwr->IPLEN_OFF = vVW510021_W_IPLEN_OFF;
vwr->PLCP_LENGTH_OFF = vVW510021_W_PLCP_LENGTH_OFF;
vwr->HEADER_IS_RX = vVW510021_W_HEADER_IS_RX;
vwr->HEADER_IS_TX = vVW510021_W_HEADER_IS_TX;
vwr->MT_MASK = vVW510021_W_SEL_MASK;
vwr->MCS_INDEX_MASK = vVW510021_W_MCS_MASK;
vwr->VCID_MASK = 0xffff;
vwr->FLOW_VALID = vVW510021_W_FLOW_VALID;
vwr->STATS_START_OFF = vVW510021_W_HEADER_LEN;
vwr->FCS_ERROR = vVW510021_W_FCS_ERROR;
vwr->CRYPTO_ERR = v22_W_CRYPTO_ERR;
vwr->RETRY_ERR = v22_W_RETRY_ERR;
vwr->RXTX_OFF = vVW510021_W_RXTX_OFF;
vwr->MT_10_HALF = 0;
vwr->MT_10_FULL = 0;
vwr->MT_100_HALF = 0;
vwr->MT_100_FULL = 0;
vwr->MT_1G_HALF = 0;
vwr->MT_1G_FULL = 0;
vwr->MT_CCKL = v22_W_MT_CCKL;
vwr->MT_CCKS = v22_W_MT_CCKS;
vwr->WEPTYPE = vVW510021_W_WEPTYPE;
vwr->TKIPTYPE = vVW510021_W_TKIPTYPE;
vwr->CCMPTYPE = vVW510021_W_CCMPTYPE;
vwr->FRAME_TYPE_OFF = vVW510021_W_FRAME_TYPE_OFF;
vwr->IS_TCP = vVW510021_W_IS_TCP;
vwr->IS_UDP = vVW510021_W_IS_UDP;
vwr->IS_ICMP = vVW510021_W_IS_ICMP;
vwr->IS_IGMP = vVW510021_W_IS_IGMP;
vwr->IS_QOS = vVW510021_W_QOS_VALID;
vwr->MPDU_OFF = 20;
break;
case S3_W_FPGA:
vwr->STATS_LEN = STATS_COMMON_FIELDS_LEN + EXT_RTAP_FIELDS_LEN;
vwr->PLCP_LENGTH_OFF = 16;
vwr->HEADER_IS_RX = vVW510021_W_HEADER_IS_RX;
vwr->HEADER_IS_TX = vVW510021_W_HEADER_IS_TX;
vwr->MPDU_OFF = 32;
break;
case vVW510012_E_FPGA:
vwr->STATS_LEN = v22_E_STATS_LEN;
vwr->VALID_OFF = v22_E_VALID_OFF;
vwr->MTYPE_OFF = v22_E_MTYPE_OFF;
vwr->VCID_OFF = v22_E_VCID_OFF;
vwr->FLOWSEQ_OFF = v22_E_FLOWSEQ_OFF;
vwr->FLOWID_OFF = v22_E_FLOWID_OFF;
vwr->OCTET_OFF = v22_E_OCTET_OFF;
vwr->ERRORS_OFF = v22_E_ERRORS_OFF;
vwr->PATN_OFF = v22_E_PATN_OFF;
vwr->RSSI_OFF = v22_E_RSSI_OFF;
vwr->STARTT_OFF = v22_E_STARTT_OFF;
vwr->ENDT_OFF = v22_E_ENDT_OFF;
vwr->LATVAL_OFF = v22_E_LATVAL_OFF;
vwr->INFO_OFF = v22_E_INFO_OFF;
vwr->L4ID_OFF = v22_E_L4ID_OFF;
vwr->HEADER_IS_RX = v22_E_HEADER_IS_RX;
vwr->HEADER_IS_TX = v22_E_HEADER_IS_TX;
vwr->IS_RX = v22_E_IS_RX;
vwr->MT_MASK = v22_E_MT_MASK;
vwr->VCID_MASK = v22_E_VCID_MASK;
vwr->FLOW_VALID = v22_E_FLOW_VALID;
vwr->FCS_ERROR = v22_E_FCS_ERROR;
vwr->RX_DECRYPTS = v22_E_RX_DECRYPTS;
vwr->TX_DECRYPTS = v22_E_TX_DECRYPTS;
vwr->FC_PROT_BIT = v22_E_FC_PROT_BIT;
vwr->MT_10_HALF = v22_E_MT_10_HALF;
vwr->MT_10_FULL = v22_E_MT_10_FULL;
vwr->MT_100_HALF = v22_E_MT_100_HALF;
vwr->MT_100_FULL = v22_E_MT_100_FULL;
vwr->MT_1G_HALF = v22_E_MT_1G_HALF;
vwr->MT_1G_FULL = v22_E_MT_1G_FULL;
vwr->MT_CCKL = 0;
vwr->MT_CCKS = 0;
vwr->MT_OFDM = 0;
vwr->FRAME_TYPE_OFF = v22_E_FRAME_TYPE_OFF;
vwr->IS_TCP = v22_E_IS_TCP;
vwr->IS_UDP = v22_E_IS_UDP;
vwr->IS_ICMP = v22_E_IS_ICMP;
vwr->IS_IGMP = v22_E_IS_IGMP;
vwr->IS_QOS = v22_E_IS_QOS;
vwr->IS_VLAN = v22_E_IS_VLAN;
break;
case S1_W_FPGA:
vwr->STATS_LEN = v22_W_STATS_LEN;
vwr->MTYPE_OFF = v22_W_MTYPE_OFF;
vwr->VALID_OFF = v22_W_VALID_OFF;
vwr->VCID_OFF = v22_W_VCID_OFF;
vwr->FLOWSEQ_OFF = v22_W_FLOWSEQ_OFF;
vwr->FLOWID_OFF = v22_W_FLOWID_OFF;
vwr->OCTET_OFF = v22_W_OCTET_OFF;
vwr->ERRORS_OFF = v22_W_ERRORS_OFF;
vwr->PATN_OFF = v22_W_PATN_OFF;
vwr->RSSI_OFF = v22_W_RSSI_OFF;
vwr->STARTT_OFF = v22_W_STARTT_OFF;
vwr->ENDT_OFF = v22_W_ENDT_OFF;
vwr->LATVAL_OFF = v22_W_LATVAL_OFF;
vwr->INFO_OFF = v22_W_INFO_OFF;
vwr->L4ID_OFF = v22_W_L4ID_OFF;
vwr->IPLEN_OFF = v22_W_IPLEN_OFF;
vwr->PLCP_LENGTH_OFF = v22_W_PLCP_LENGTH_OFF;
vwr->FCS_ERROR = v22_W_FCS_ERROR;
vwr->CRYPTO_ERR = v22_W_CRYPTO_ERR;
vwr->PAYCHK_ERR = v22_W_PAYCHK_ERR;
vwr->RETRY_ERR = v22_W_RETRY_ERR;
vwr->IS_RX = v22_W_IS_RX;
vwr->MT_MASK = v22_W_MT_MASK;
vwr->VCID_MASK = v22_W_VCID_MASK;
vwr->FLOW_VALID = v22_W_FLOW_VALID;
vwr->HEADER_IS_RX = v22_W_HEADER_IS_RX;
vwr->HEADER_IS_TX = v22_W_HEADER_IS_TX;
vwr->RX_DECRYPTS = v22_W_RX_DECRYPTS;
vwr->TX_DECRYPTS = v22_W_TX_DECRYPTS;
vwr->FC_PROT_BIT = v22_W_FC_PROT_BIT;
vwr->MT_10_HALF = 0;
vwr->MT_10_FULL = 0;
vwr->MT_100_HALF = 0;
vwr->MT_100_FULL = 0;
vwr->MT_1G_HALF = 0;
vwr->MT_1G_FULL = 0;
vwr->MT_CCKL = v22_W_MT_CCKL;
vwr->MT_CCKS = v22_W_MT_CCKS;
vwr->MT_OFDM = v22_W_MT_OFDM;
vwr->WEPTYPE = v22_W_WEPTYPE;
vwr->TKIPTYPE = v22_W_TKIPTYPE;
vwr->CCMPTYPE = v22_W_CCMPTYPE;
vwr->FRAME_TYPE_OFF = v22_W_FRAME_TYPE_OFF;
vwr->IS_TCP = v22_W_IS_TCP;
vwr->IS_UDP = v22_W_IS_UDP;
vwr->IS_ICMP = v22_W_IS_ICMP;
vwr->IS_IGMP = v22_W_IS_IGMP;
vwr->IS_QOS = v22_W_IS_QOS;
break;
case vVW510024_E_FPGA:
vwr->STATS_LEN = vVW510024_E_STATS_LEN;
vwr->VALID_OFF = vVW510024_E_VALID_OFF;
vwr->VCID_OFF = vVW510024_E_VCID_OFF;
vwr->FLOWSEQ_OFF = vVW510024_E_FLOWSEQ_OFF;
vwr->FLOWID_OFF = vVW510024_E_FLOWID_OFF;
vwr->OCTET_OFF = vVW510024_E_MSDU_LENGTH_OFF;
vwr->ERRORS_OFF = vVW510024_E_ERRORS_OFF;
vwr->PATN_OFF = vVW510024_E_MATCH_OFF;
vwr->STARTT_OFF = vVW510024_E_STARTT_OFF;
vwr->ENDT_OFF = vVW510024_E_ENDT_OFF;
vwr->LATVAL_OFF = vVW510024_E_LATVAL_OFF;
vwr->INFO_OFF = vVW510024_E_INFO_OFF;
vwr->L4ID_OFF = vVW510024_E_L4ID_OFF;
vwr->IPLEN_OFF = vVW510024_E_IPLEN_OFF;
vwr->FPGA_VERSION_OFF = vVW510024_E_FPGA_VERSION_OFF;
vwr->HEADER_VERSION_OFF = vVW510024_E_HEADER_VERSION_OFF;
vwr->HEADER_IS_RX = vVW510024_E_HEADER_IS_RX;
vwr->HEADER_IS_TX = vVW510024_E_HEADER_IS_TX;
vwr->VCID_MASK = vVW510024_E_VCID_MASK;
vwr->FLOW_VALID = vVW510024_E_FLOW_VALID;
vwr->FCS_ERROR = v22_E_FCS_ERROR;
vwr->FRAME_TYPE_OFF = vVW510024_E_FRAME_TYPE_OFF;
vwr->IS_TCP = vVW510024_E_IS_TCP;
vwr->IS_UDP = vVW510024_E_IS_UDP;
vwr->IS_ICMP = vVW510024_E_IS_ICMP;
vwr->IS_IGMP = vVW510024_E_IS_IGMP;
vwr->IS_QOS = vVW510024_E_QOS_VALID;
vwr->IS_VLAN = vVW510024_E_IS_VLAN;
break;
}
}
int find_signature(guint8 *m_ptr, int rec_size, int pay_off, guint32 flow_id, guint8 flow_seq)
{
int tgt;
guint32 fid;
if (m_ptr[pay_off] == 0xdd)
return(pay_off);
for (tgt = pay_off; tgt < (rec_size); tgt++) {
if (m_ptr[tgt] == 0xdd) {
if (m_ptr[tgt + 15] == 0xe2) {
if (m_ptr[tgt + 4] != flow_seq)
continue;
fid = pletoh24(&m_ptr[tgt + 1]);
if (fid != flow_id)
continue;
return (tgt);
}
else
{
if (m_ptr[tgt + SIG_FSQ_OFF] != flow_seq)
continue;
fid = pletoh24(&m_ptr[tgt + SIG_FID_OFF]);
if (fid != flow_id)
continue;
return (tgt);
}
}
}
return(pay_off);
}
guint64 get_signature_ts(guint8 *m_ptr,int sig_off)
{
int ts_offset;
guint64 sig_ts;
if (m_ptr[sig_off + 15] == 0xe2)
ts_offset = 5;
else
ts_offset = 8;
sig_ts = pletohl(&m_ptr[sig_off + ts_offset]);
return(sig_ts & 0xffffffff);
}
static float getRate( guint8 plcpType, guint8 mcsIndex, guint16 rflags, guint8 nss )
{
float canonical_rate_legacy[] = {1.0f, 2.0f, 5.5f, 11.0f, 6.0f, 9.0f, 12.0f, 18.0f, 24.0f, 36.0f, 48.0f, 54.0f};
int canonical_ndbps_20_ht[] = {26, 52, 78, 104, 156, 208, 234, 260};
int canonical_ndbps_40_ht[] = {54, 108, 162, 216, 324, 432, 486, 540};
int canonical_ndbps_20_vht[] = {26,52, 78, 104, 156, 208, 234, 260, 312};
int canonical_ndbps_40_vht[] = {54, 108, 162, 216, 324, 432, 486, 540, 648, 720};
int canonical_ndbps_80_vht[] = {117, 234, 351, 468, 702, 936, 1053, 1170, 1404, 1560};
int ndbps;
float symbol_tx_time, bitrate = 0.0f;
if (plcpType == 0)
bitrate = canonical_rate_legacy[mcsIndex];
else if (plcpType == 1 || plcpType == 2)
{
if ( rflags & IEEE80211_RADIOTAP_F_SHORTGI)
symbol_tx_time = 3.6f;
else
symbol_tx_time = 4.0f;
if ( rflags & IEEE80211_RADIOTAP_F_40MHZ )
ndbps = canonical_ndbps_40_ht[ mcsIndex - 8*(int)(mcsIndex/8) ];
else
ndbps = canonical_ndbps_20_ht[ mcsIndex - 8*(int)(mcsIndex/8) ];
bitrate = ( ndbps * (((int)(mcsIndex/8) + 1) )) / symbol_tx_time;
}
else
{
if ( rflags & IEEE80211_RADIOTAP_F_SHORTGI)
symbol_tx_time = 3.6f;
else
symbol_tx_time = 4.0f;
if (mcsIndex > 9) mcsIndex = 9;
if ( rflags & IEEE80211_RADIOTAP_F_40MHZ )
bitrate = (canonical_ndbps_40_vht[ mcsIndex ] * nss) / symbol_tx_time;
else if (rflags & IEEE80211_RADIOTAP_F_80MHZ )
bitrate = (canonical_ndbps_80_vht[ mcsIndex ] * nss) / symbol_tx_time;
else
{
if (mcsIndex == 9 && nss == 3)
bitrate = 1040 / symbol_tx_time;
else if (mcsIndex < 9)
bitrate = (canonical_ndbps_20_vht[ mcsIndex ] * nss) / symbol_tx_time;
}
}
return bitrate;
}
static gboolean
vwr_process_rec_data(wtap *wth, FILE_T fh, int rec_size,
Buffer *buf, vwr_t *vwr,
int IS_TX, int *err, gchar **err_info)
{
guint8 rec[B_SIZE];
guint16 pkt_len;
guint8 *data_ptr;
if (file_read(rec, rec_size, fh) != rec_size) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return(FALSE);
}
if (rec_size < (int)vwr->STATS_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)", rec_size, vwr->STATS_LEN);
*err = WTAP_ERR_BAD_FILE;
return(FALSE);
}
if ((vwr->FPGA_VERSION == S2_W_FPGA) || (vwr->FPGA_VERSION == S1_W_FPGA) || (vwr->FPGA_VERSION == S3_W_FPGA) )
pkt_len = (guint16)(rec_size + STATS_COMMON_FIELDS_LEN + EXT_RTAP_FIELDS_LEN);
else
pkt_len = (guint16)(rec_size + STATS_COMMON_FIELDS_LEN + STATS_ETHERNETTAP_FIELDS_LEN);
buffer_assure_space(buf, pkt_len);
data_ptr = buffer_start_ptr(buf);
switch (vwr->FPGA_VERSION)
{
case S1_W_FPGA:
case S2_W_FPGA:
case S3_W_FPGA:
vwr_read_rec_data_wlan(wth, data_ptr, rec, rec_size, IS_TX);
break;
case vVW510012_E_FPGA:
vwr_read_rec_data_ethernet(wth, data_ptr, rec, rec_size, IS_TX);
break;
case vVW510024_E_FPGA:
vwr_read_rec_data_ethernet(wth, data_ptr, rec, rec_size, IS_TX);
break;
}
return (TRUE);
}
