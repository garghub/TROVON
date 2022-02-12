wtap_open_return_val vwr_open(wtap *wth, int *err, gchar **err_info)
{
int fpgaVer;
vwr_t *vwr;
*err = 0;
fpgaVer = vwr_get_fpga_version(wth, err, err_info);
if (fpgaVer == -1) {
return WTAP_OPEN_ERROR;
}
if (fpgaVer == UNKNOWN_FPGA) {
return WTAP_OPEN_NOT_MINE;
}
vwr = (vwr_t *)g_malloc0(sizeof(vwr_t));
wth->priv = (void *)vwr;
vwr->FPGA_VERSION = fpgaVer;
setup_defaults(vwr, fpgaVer);
wth->snapshot_length = 0;
wth->subtype_read = vwr_read;
wth->subtype_seek_read = vwr_seek_read;
wth->file_tsprec = WTAP_TSPREC_USEC;
wth->file_encap = WTAP_ENCAP_IXVERIWAVE;
if (fpgaVer == S2_W_FPGA || fpgaVer == S1_W_FPGA || fpgaVer == S3_W_FPGA)
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_VWR_80211;
else if (fpgaVer == vVW510012_E_FPGA || fpgaVer == vVW510024_E_FPGA)
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_VWR_ETH;
return WTAP_OPEN_MINE;
}
static gboolean vwr_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int rec_size = 0, IS_TX, log_mode;
if (!vwr_read_rec_header(vwr, wth->fh, &rec_size, &IS_TX, &log_mode, err, err_info))
return FALSE;
*data_offset = (file_tell(wth->fh) - VW_RECORD_HEADER_LENGTH);
if (!vwr_process_rec_data(wth->fh, rec_size, &wth->phdr,
wth->frame_buffer, vwr, IS_TX, log_mode, err, err_info))
return FALSE;
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
return TRUE;
}
static gboolean vwr_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
vwr_t *vwr = (vwr_t *)wth->priv;
int rec_size, IS_TX, log_mode;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!vwr_read_rec_header(vwr, wth->random_fh, &rec_size, &IS_TX, &log_mode, err, err_info))
return FALSE;
return vwr_process_rec_data(wth->random_fh, rec_size, phdr, buf,
vwr, IS_TX, log_mode, err, err_info);
}
static gboolean vwr_read_rec_header(vwr_t *vwr, FILE_T fh, int *rec_size, int *IS_TX, int *log_mode, int *err, gchar **err_info)
{
int f_len, v_type;
guint8 header[VW_RECORD_HEADER_LENGTH];
*rec_size = 0;
while (1) {
if (!wtap_read_bytes_or_eof(fh, header, VW_RECORD_HEADER_LENGTH, err, err_info))
return FALSE;
if ((f_len = decode_msg(vwr, header, &v_type, IS_TX, log_mode)) != 0) {
if (f_len > B_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vwr: Invalid message record length %d", f_len);
return FALSE;
}
else if (v_type != VT_FRAME) {
if (!wtap_read_bytes(fh, NULL, f_len, err, err_info))
return FALSE;
}
else {
*rec_size = f_len;
return TRUE;
}
}
}
}
static int vwr_get_fpga_version(wtap *wth, int *err, gchar **err_info)
{
guint8 *rec;
guint8 header[VW_RECORD_HEADER_LENGTH];
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
int valid_but_empty_file = -1;
filePos = file_tell(wth->fh);
if (filePos == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
fpga_version = 1000;
rec = (guint8*)g_malloc(B_SIZE);
while (wtap_read_bytes(wth->fh, header, VW_RECORD_HEADER_LENGTH, err, err_info)) {
if ((f_len = decode_msg(NULL, header, &v_type, NULL, NULL)) != 0) {
if (f_len > B_SIZE) {
g_free(rec);
return UNKNOWN_FPGA;
}
else if (v_type != VT_FRAME) {
if (!wtap_read_bytes(wth->fh, NULL, f_len, err, err_info)) {
g_free(rec);
return -1;
}
else if (v_type == VT_CPMSG)
valid_but_empty_file = 1;
}
else {
rec_size = f_len;
if (!wtap_read_bytes(wth->fh, rec, rec_size, err, err_info)) {
g_free(rec);
if (*err == WTAP_ERR_SHORT_READ)
return UNKNOWN_FPGA;
return -1;
}
if (rec_size > v22_W_STATS_LEN) {
s_510006_ptr = &(rec[rec_size - v22_W_STATS_LEN]);
data_length = pntoh16(&s_510006_ptr[v22_W_OCTET_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
frame_type = pntoh32(&s_510006_ptr[v22_W_FRAME_TYPE_OFF]);
if (rec_size == (data_length + v22_W_STATS_LEN + i) && (frame_type & v22_W_IS_80211) == 0x1000000) {
fpga_version = S1_W_FPGA;
}
}
if ((rec_size > v22_E_STATS_LEN) && (fpga_version == 1000)) {
s_510012_ptr = &(rec[rec_size - v22_E_STATS_LEN]);
data_length = pntoh16(&s_510012_ptr[v22_E_OCTET_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + v22_E_STATS_LEN + i))
fpga_version = vVW510012_E_FPGA;
}
if ((rec_size > vVW510021_W_STATS_TRAILER_LEN) && (fpga_version == 1000)) {
if ((header[8] == 48) || (header[8] == 61) || (header[8] == 68))
fpga_version = S3_W_FPGA;
else {
data_length = (256 * (rec[vVW510021_W_MSDU_LENGTH_OFF + 1] & 0x1f)) + rec[vVW510021_W_MSDU_LENGTH_OFF];
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + vVW510021_W_STATS_TRAILER_LEN +vVW510021_W_AFTERHEADER_LEN+12+i))
fpga_version = S2_W_FPGA;
}
}
if ((rec_size > vVW510024_E_STATS_LEN) && (fpga_version == 1000)) {
s_510024_ptr = &(rec[rec_size - vVW510024_E_STATS_LEN]);
data_length = pntoh16(&s_510024_ptr[vVW510024_E_MSDU_LENGTH_OFF]);
i = 0;
while (((data_length + i) % 4) != 0)
i = i + 1;
if (rec_size == (data_length + vVW510024_E_STATS_LEN + i))
fpga_version = vVW510024_E_FPGA;
}
if (fpga_version != 1000)
{
if (file_seek (wth->fh, filePos, SEEK_SET, err) == -1) {
g_free(rec);
return (-1);
}
g_free(rec);
return fpga_version;
}
}
}
}
if (valid_but_empty_file > 0) {
g_free(rec);
return(S3_W_FPGA);
}
if (*err == WTAP_ERR_SHORT_READ) {
g_free(rec);
return UNKNOWN_FPGA;
}
g_free(rec);
return -1;
}
static gboolean vwr_read_s1_W_rec(vwr_t *vwr, struct wtap_pkthdr *phdr,
Buffer *buf, const guint8 *rec, int rec_size,
int *err, gchar **err_info)
{
guint8 *data_ptr;
int bytes_written = 0;
const guint8 *s_ptr, *m_ptr;
guint16 msdu_length, actual_octets;
guint16 plcp_hdr_len;
guint16 rflags;
guint8 m_type;
guint flow_seq;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint32 latency;
guint64 start_time, s_sec, s_usec = LL_ZERO;
guint64 end_time;
guint32 info;
gint8 rssi;
int f_tx;
guint8 rate_index;
guint16 vc_id, ht_len=0;
guint flow_id;
guint32 d_time, errors;
int sig_off, pay_off;
guint64 sig_ts;
guint16 phyRate;
guint16 vw_flags;
if (rec_size < v22_W_STATS_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)",
rec_size, v22_W_STATS_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
s_ptr = &(rec[rec_size - v22_W_STATS_LEN]);
m_type = s_ptr[v22_W_MTYPE_OFF] & v22_E_MT_MASK;
f_tx = !(s_ptr[v22_W_MTYPE_OFF] & v22_E_IS_RX);
actual_octets = pntoh16(&s_ptr[v22_W_OCTET_OFF]);
vc_id = pntoh16(&s_ptr[v22_W_VCID_OFF]) & v22_E_VCID_MASK;
flow_seq = s_ptr[v22_W_FLOWSEQ_OFF];
latency = (guint32)pcorey48tohll(&s_ptr[v22_W_LATVAL_OFF]);
flow_id = pntoh16(&s_ptr[v22_W_FLOWID_OFF+1]);
errors = pntoh16(&s_ptr[v22_W_ERRORS_OFF]);
info = pntoh16(&s_ptr[v22_W_INFO_OFF]);
rssi = (s_ptr[v22_W_RSSI_OFF] & 0x80) ? (-1 * (s_ptr[v22_W_RSSI_OFF] & 0x7f)) : s_ptr[v22_W_RSSI_OFF];
if (actual_octets > rec_size - v22_W_STATS_LEN) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (runs past the end of the record)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
if (m_type == vwr->MT_OFDM)
rate_index = get_ofdm_rate(rec);
else if ((m_type == vwr->MT_CCKL) || (m_type == vwr->MT_CCKS))
rate_index = get_cck_rate(rec);
else
rate_index = 1;
rflags = (m_type == vwr->MT_CCKS) ? FLAGS_SHORTPRE : 0;
plcp_hdr_len = (m_type == vwr->MT_OFDM) ? 4 : 6;
if (actual_octets >= plcp_hdr_len)
actual_octets -= plcp_hdr_len;
else {
*err_info = g_strdup_printf("vwr: Invalid data length %u (too short to include %u-byte PLCP header)",
actual_octets, plcp_hdr_len);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
m_ptr = &rec[plcp_hdr_len];
msdu_length = actual_octets;
if (actual_octets < 4) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (too short to include %u-byte PLCP header and 4 bytes of FCS)",
actual_octets, plcp_hdr_len);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
actual_octets -= 4;
s_time = pcoreytohll(&s_ptr[v22_W_STARTT_OFF]);
e_time = pcoreytohll(&s_ptr[v22_W_ENDT_OFF]);
d_time = (guint32)((e_time - s_time) / NS_IN_US);
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
pay_off = 42;
sig_off = find_signature(m_ptr, rec_size - 6, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= (rec_size - v22_W_STATS_LEN)))
sig_ts = get_signature_ts(m_ptr, sig_off);
else
sig_ts = 0;
phdr->len = STATS_COMMON_FIELDS_LEN + EXT_WLAN_FIELDS_LEN + actual_octets;
phdr->caplen = STATS_COMMON_FIELDS_LEN + EXT_WLAN_FIELDS_LEN + actual_octets;
phdr->ts.secs = (time_t)s_sec;
phdr->ts.nsecs = (int)(s_usec * 1000);
phdr->pkt_encap = WTAP_ENCAP_IXVERIWAVE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ws_buffer_assure_space(buf, phdr->caplen);
data_ptr = ws_buffer_start_ptr(buf);
phtole8(&data_ptr[bytes_written], WLAN_PORT);
bytes_written += 1;
phtole8(&data_ptr[bytes_written], 0);
bytes_written += 1;
phtoles(&data_ptr[bytes_written], STATS_COMMON_FIELDS_LEN);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], msdu_length);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], flow_id);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], vc_id);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], flow_seq);
bytes_written += 2;
if (!f_tx && sig_ts != 0) {
phtolel(&data_ptr[bytes_written], latency);
} else {
phtolel(&data_ptr[bytes_written], 0);
}
bytes_written += 4;
phtolel(&data_ptr[bytes_written], sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], start_time);
bytes_written += 8;
phtolell(&data_ptr[bytes_written], end_time);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], d_time);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], EXT_WLAN_FIELDS_LEN);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], rflags);
bytes_written += 2;
if (m_type == vwr->MT_OFDM) {
phtoles(&data_ptr[bytes_written], CHAN_OFDM);
} else {
phtoles(&data_ptr[bytes_written], CHAN_CCK);
}
bytes_written += 2;
phyRate = (guint16)(get_legacy_rate(rate_index) * 10);
phtoles(&data_ptr[bytes_written], phyRate);
bytes_written += 2;
data_ptr[bytes_written] = vVW510021_W_PLCP_LEGACY;
bytes_written += 1;
data_ptr[bytes_written] = rate_index;
bytes_written += 1;
data_ptr[bytes_written] = 1;
bytes_written += 1;
data_ptr[bytes_written] = rssi;
bytes_written += 1;
data_ptr[bytes_written] = 100;
bytes_written += 1;
data_ptr[bytes_written] = 100;
bytes_written += 1;
data_ptr[bytes_written] = 100;
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
vw_flags = 0;
if (f_tx)
vw_flags |= VW_FLAGS_TXF;
if (errors & vwr->FCS_ERROR)
vw_flags |= VW_FLAGS_FCSERR;
if (!f_tx && (errors & vwr->CRYPTO_ERR))
vw_flags |= VW_FLAGS_DCRERR;
if (!f_tx && (errors & vwr->RETRY_ERR))
vw_flags |= VW_FLAGS_RETRERR;
if (info & vwr->WEPTYPE)
vw_flags |= VW_FLAGS_IS_WEP;
else if (info & vwr->TKIPTYPE)
vw_flags |= VW_FLAGS_IS_TKIP;
else if (info & vwr->CCMPTYPE)
vw_flags |= VW_FLAGS_IS_CCMP;
phtoles(&data_ptr[bytes_written], vw_flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], ht_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], info);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], errors);
bytes_written += 4;
memcpy(&data_ptr[bytes_written], &rec[plcp_hdr_len], actual_octets);
return TRUE;
}
static gboolean vwr_read_s2_W_rec(vwr_t *vwr, struct wtap_pkthdr *phdr,
Buffer *buf, const guint8 *rec, int rec_size,
int IS_TX, int *err, gchar **err_info)
{
guint8 *data_ptr;
int bytes_written = 0;
const guint8 *s_start_ptr,*s_trail_ptr, *plcp_ptr, *m_ptr;
guint32 msdu_length, actual_octets;
guint8 l1p_1, l1p_2, plcp_type, rate_mcs_index, nss;
guint flow_seq;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint64 latency = LL_ZERO;
guint64 start_time, s_sec, s_usec = LL_ZERO;
guint64 end_time;
guint16 info;
guint32 errors;
gint8 rssi[] = {0,0,0,0};
int f_tx;
guint16 vc_id, ht_len=0;
guint32 flow_id, d_time;
int sig_off, pay_off;
guint64 sig_ts, tsid;
guint16 chanflags = 0;
guint16 radioflags = 0;
guint64 delta_b;
float rate;
guint16 phyRate;
guint16 vw_flags;
if ((guint)rec_size < vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)",
rec_size,
vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
s_start_ptr = &(rec[0]);
s_trail_ptr = &(rec[rec_size - vVW510021_W_STATS_TRAILER_LEN]);
l1p_1 = s_start_ptr[vVW510021_W_L1P_1_OFF];
l1p_2 = s_start_ptr[vVW510021_W_L1P_2_OFF];
plcp_type = vVW510021_W_S2_PLCP_TYPE(l1p_2);
msdu_length = ((s_start_ptr[vVW510021_W_MSDU_LENGTH_OFF+1] & 0x1f) << 8)
+ s_start_ptr[vVW510021_W_MSDU_LENGTH_OFF];
vc_id = pntoh16(&s_start_ptr[vVW510021_W_VCID_OFF]);
if (IS_TX)
{
rssi[0] = (s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF] & 0x80) ?
-1 * (s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF] & 0x7f) :
s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF] & 0x7f;
}
else
{
rssi[0] = (s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF] & 0x80) ?
(s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF]- 256) :
s_start_ptr[vVW510021_W_RSSI_TXPOWER_OFF];
}
rssi[1] = 100;
rssi[2] = 100;
rssi[3] = 100;
plcp_ptr = &(rec[8]);
actual_octets = msdu_length;
if (actual_octets > rec_size - (vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN)) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (runs past the end of the record)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
f_tx = IS_TX;
flow_seq = s_trail_ptr[vVW510021_W_FLOWSEQ_OFF];
latency = 0x00000000;
flow_id = pntoh24(&s_trail_ptr[vVW510021_W_FLOWID_OFF]);
tsid = pcorey48tohll(&s_trail_ptr[vVW510021_W_LATVAL_OFF]);
errors = pntoh32(&s_trail_ptr[vVW510021_W_ERRORS_OFF]);
info = pntoh16(&s_trail_ptr[vVW510021_W_INFO_OFF]);
if ((info & v22_W_AGGREGATE_FLAGS) != 0)
ht_len = pletoh16(&s_start_ptr[vwr->PLCP_LENGTH_OFF]);
switch (plcp_type)
{
case vVW510021_W_PLCP_LEGACY:
rate_mcs_index = vVW510021_W_S2_RATE_INDEX(l1p_1);
if (rate_mcs_index < 4) {
chanflags |= CHAN_CCK;
}
else {
chanflags |= CHAN_OFDM;
}
rate = get_legacy_rate(rate_mcs_index);
nss = 0;
break;
case vVW510021_W_PLCP_MIXED:
rate_mcs_index = vVW510021_W_S2_MCS_INDEX_HT(l1p_1);
radioflags |= FLAGS_CHAN_HT | ((plcp_ptr[3] & 0x80) ? FLAGS_CHAN_40MHZ : 0) |
((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
nss = (rate_mcs_index < MAX_HT_MCS) ? nss_for_mcs[rate_mcs_index] : 0;
rate = get_ht_rate(rate_mcs_index, radioflags);
break;
case vVW510021_W_PLCP_GREENFIELD:
rate_mcs_index = vVW510021_W_S2_MCS_INDEX_HT(l1p_1);
radioflags |= FLAGS_CHAN_HT | ((plcp_ptr[0] & 0x80) ? FLAGS_CHAN_40MHZ : 0) |
((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
nss = (rate_mcs_index < MAX_HT_MCS) ? nss_for_mcs[rate_mcs_index] : 0;
rate = get_ht_rate(rate_mcs_index, radioflags);
break;
case vVW510021_W_PLCP_VHT_MIXED:
{
guint8 SBW = vVW510021_W_BANDWIDTH_VHT(l1p_2);
rate_mcs_index = vVW510021_W_S2_MCS_INDEX_VHT(l1p_1);
radioflags |= FLAGS_CHAN_VHT | ((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
chanflags |= CHAN_OFDM;
if (SBW == 3)
radioflags |= FLAGS_CHAN_40MHZ;
else if (SBW == 4)
radioflags |= FLAGS_CHAN_80MHZ;
nss = vVW510021_W_S2_NSS_VHT(l1p_1);
rate = get_vht_rate(rate_mcs_index, radioflags, nss);
}
break;
default:
rate_mcs_index = 0;
nss = 0;
rate = 0.0f;
break;
}
if (actual_octets < 4) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (too short to include 4 bytes of FCS)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
if (actual_octets > 4) {
actual_octets -= 4;
}
s_time = pcoreytohll(&s_trail_ptr[vVW510021_W_STARTT_OFF]);
e_time = pcoreytohll(&s_trail_ptr[vVW510021_W_ENDT_OFF]);
d_time = (guint32)((e_time - s_time) / NS_IN_US);
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
m_ptr = &(rec[8+12]);
pay_off = 42;
sig_off = find_signature(m_ptr, rec_size - 20, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= (rec_size - vVW510021_W_STATS_TRAILER_LEN)))
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
phdr->len = STATS_COMMON_FIELDS_LEN + EXT_WLAN_FIELDS_LEN + actual_octets;
phdr->caplen = STATS_COMMON_FIELDS_LEN + EXT_WLAN_FIELDS_LEN + actual_octets;
phdr->ts.secs = (time_t)s_sec;
phdr->ts.nsecs = (int)(s_usec * 1000);
phdr->pkt_encap = WTAP_ENCAP_IXVERIWAVE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ws_buffer_assure_space(buf, phdr->caplen);
data_ptr = ws_buffer_start_ptr(buf);
phtole8(&data_ptr[bytes_written], WLAN_PORT);
bytes_written += 1;
phtole8(&data_ptr[bytes_written], 0);
bytes_written += 1;
phtoles(&data_ptr[bytes_written], STATS_COMMON_FIELDS_LEN);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], msdu_length);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], flow_id);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], vc_id);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], flow_seq);
bytes_written += 2;
if (!f_tx && sig_ts != 0) {
phtolel(&data_ptr[bytes_written], latency);
} else {
phtolel(&data_ptr[bytes_written], 0);
}
bytes_written += 4;
phtolel(&data_ptr[bytes_written], sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], start_time);
bytes_written += 8;
phtolell(&data_ptr[bytes_written], end_time);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], d_time);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], EXT_WLAN_FIELDS_LEN);
bytes_written += 2;
if (info & vVW510021_W_IS_WEP)
radioflags |= FLAGS_WEP;
if (!(l1p_1 & vVW510021_W_IS_LONGPREAMBLE) && (plcp_type == vVW510021_W_PLCP_LEGACY))
radioflags |= FLAGS_SHORTPRE;
phtoles(&data_ptr[bytes_written], radioflags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], chanflags);
bytes_written += 2;
phyRate = (guint16)(rate * 10);
phtoles(&data_ptr[bytes_written], phyRate);
bytes_written += 2;
data_ptr[bytes_written] = plcp_type;
bytes_written += 1;
data_ptr[bytes_written] = rate_mcs_index;
bytes_written += 1;
data_ptr[bytes_written] = nss;
bytes_written += 1;
data_ptr[bytes_written] = rssi[0];
bytes_written += 1;
data_ptr[bytes_written] = rssi[1];
bytes_written += 1;
data_ptr[bytes_written] = rssi[2];
bytes_written += 1;
data_ptr[bytes_written] = rssi[3];
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
vw_flags = 0;
if (f_tx)
vw_flags |= VW_FLAGS_TXF;
if (errors & 0x1f)
vw_flags |= VW_FLAGS_FCSERR;
if (!f_tx && (errors & vwr->CRYPTO_ERR))
vw_flags |= VW_FLAGS_DCRERR;
if (!f_tx && (errors & vwr->RETRY_ERR))
vw_flags |= VW_FLAGS_RETRERR;
if (info & vwr->WEPTYPE)
vw_flags |= VW_FLAGS_IS_WEP;
else if (info & vwr->TKIPTYPE)
vw_flags |= VW_FLAGS_IS_TKIP;
else if (info & vwr->CCMPTYPE)
vw_flags |= VW_FLAGS_IS_CCMP;
phtoles(&data_ptr[bytes_written], vw_flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], ht_len);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], info);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], errors);
bytes_written += 4;
memcpy(&data_ptr[bytes_written], &rec[vwr->MPDU_OFF], actual_octets);
return TRUE;
}
static gboolean vwr_read_s3_W_rec(vwr_t *vwr, struct wtap_pkthdr *phdr,
Buffer *buf, const guint8 *rec, int rec_size,
int IS_TX, int log_mode, int *err,
gchar **err_info)
{
guint8 *data_ptr;
int bytes_written = 0;
int i;
int stats_offset = 0;
const guint8 *s_start_ptr = NULL,*s_trail_ptr = NULL, *plcp_ptr, *m_ptr;
guint32 msdu_length = 0, actual_octets = 0;
guint8 l1p_1 = 0,l1p_2 = 0, plcp_type, rate_mcs_index, nss;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint64 latency = LL_ZERO;
guint64 start_time = 0, s_sec = 0, s_usec = LL_ZERO;
guint64 end_time = 0;
guint16 info = 0;
guint32 errors = 0;
gint8 info_2nd = 0,rssi[] = {0,0,0,0};
int frame_size;
guint32 d_time = 0, flow_id = 0;
int sig_off, pay_off;
guint64 sig_ts = 0, tsid;
guint64 delta_b;
guint8 L1InfoC,port_type,ver_fpga = 0;
guint8 flow_seq =0,plcp_hdr_flag = 0,rf_id = 0;
const guint8 *rf_ptr = NULL;
float rate;
guint16 phyRate;
if (IS_TX == 3) {
if ((guint)rec_size < OCTO_MODIFIED_RF_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)",
rec_size,
OCTO_MODIFIED_RF_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
rf_ptr = &(rec[0]);
rf_id = rf_ptr[0];
phdr->len = OCTO_MODIFIED_RF_LEN + 1;
phdr->caplen = OCTO_MODIFIED_RF_LEN + 1;
phdr->ts.secs = (time_t)s_sec;
phdr->ts.nsecs = (int)(s_usec * 1000);
phdr->pkt_encap = WTAP_ENCAP_IXVERIWAVE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ws_buffer_assure_space(buf, phdr->caplen);
data_ptr = ws_buffer_start_ptr(buf);
port_type = IS_TX << 4;
nss = 0;
phyRate = 0;
}
else {
if (IS_TX == 4)
{
stats_offset = OCTO_RF_MOD_ACTUAL_LEN;
if ((guint)rec_size < stats_offset + vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)",
rec_size,
stats_offset + vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
rf_ptr = &(rec[0]);
rf_id = rf_ptr[0];
}
else
{
stats_offset = 0;
if ((guint)rec_size < vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)",
rec_size,
vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
}
s_start_ptr = &(rec[stats_offset]);
s_trail_ptr = &(rec[rec_size - vVW510021_W_STATS_TRAILER_LEN] );
l1p_1 = s_start_ptr[vVW510021_W_L1P_1_OFF];
l1p_2 = s_start_ptr[vVW510021_W_L1P_2_OFF];
plcp_type = vVW510021_W_S3_PLCP_TYPE(l1p_2);
switch (plcp_type)
{
case vVW510021_W_PLCP_LEGACY:
rate_mcs_index = vVW510021_W_S3_RATE_INDEX(l1p_1);
nss = 0;
break;
case vVW510021_W_PLCP_MIXED:
case vVW510021_W_PLCP_GREENFIELD:
rate_mcs_index = vVW510021_W_S3_MCS_INDEX_HT(l1p_1);
nss = (rate_mcs_index < MAX_HT_MCS) ? nss_for_mcs[rate_mcs_index] : 0;
break;
case vVW510021_W_PLCP_VHT_MIXED:
rate_mcs_index = vVW510021_W_S3_MCS_INDEX_VHT(l1p_1);
nss = vVW510021_W_S3_NSS_VHT(l1p_1);
plcp_hdr_flag = 1;
break;
default:
rate_mcs_index = 0;
nss = 0;
plcp_hdr_flag = 0;
break;
}
for (i = 0; i < 4; i++)
{
if (IS_TX == 1)
{
rssi[i] = (s_start_ptr[4+i] & 0x80) ? -1 * (s_start_ptr[4+i] & 0x7f) : s_start_ptr[4+i] & 0x7f;
}
else
{
rssi[i] = (s_start_ptr[4+i] >= 128) ? (s_start_ptr[4+i] - 256) : s_start_ptr[4+i];
}
}
if (IS_TX == 0 || IS_TX == 4){
L1InfoC = s_start_ptr[8];
}
msdu_length = pntoh24(&s_start_ptr[9]);
plcp_ptr = &(rec[stats_offset+16]);
if (log_mode == 3) {
frame_size = rec_size - 80 - stats_offset;
if (frame_size > ((int) msdu_length))
actual_octets = msdu_length;
else
actual_octets = frame_size;
}
else
{
actual_octets = msdu_length;
}
if (actual_octets > rec_size - (stats_offset + vwr->MPDU_OFF + vVW510021_W_STATS_TRAILER_LEN)) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (runs past the end of the record)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
flow_seq = s_trail_ptr[vVW510021_W_FLOWSEQ_OFF];
latency = 0x00000000;
flow_id = pntoh24(&s_trail_ptr[vVW510021_W_FLOWID_OFF]);
tsid = pcorey48tohll(&s_trail_ptr[vVW510021_W_LATVAL_OFF]);
errors = pntoh32(&s_trail_ptr[vVW510021_W_ERRORS_OFF]);
info = pntoh16(&s_trail_ptr[vVW510021_W_INFO_OFF]);
if (IS_TX == 0 || IS_TX == 4)
info_2nd = s_trail_ptr[41];
switch (plcp_type)
{
case vVW510021_W_PLCP_LEGACY:
rate = get_legacy_rate(rate_mcs_index);
break;
case vVW510021_W_PLCP_MIXED:
{
guint16 radioflags = FLAGS_CHAN_HT | ((plcp_ptr[3] & 0x80) ? FLAGS_CHAN_40MHZ : 0) |
((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
rate = get_ht_rate(rate_mcs_index, radioflags);
}
break;
case vVW510021_W_PLCP_GREENFIELD:
{
guint16 radioflags = FLAGS_CHAN_HT | ((plcp_ptr[0] & 0x80) ? FLAGS_CHAN_40MHZ : 0) |
((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
rate = get_ht_rate(rate_mcs_index, radioflags);
}
break;
case vVW510021_W_PLCP_VHT_MIXED:
{
guint8 SBW = vVW510021_W_BANDWIDTH_VHT(l1p_2);
guint16 radioflags = FLAGS_CHAN_VHT | ((l1p_1 & vVW510021_W_IS_LONGGI) ? 0 : FLAGS_CHAN_SHORTGI);
if (SBW == 3)
radioflags |= FLAGS_CHAN_40MHZ;
else if (SBW == 4)
radioflags |= FLAGS_CHAN_80MHZ;
rate = get_vht_rate(rate_mcs_index, radioflags, nss);
}
break;
default:
rate = 0.0f;
break;
}
phyRate = (guint16)(rate * 10);
if (log_mode == 3) {
if (actual_octets < 4) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (too short to include 4 bytes of FCS)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
if (actual_octets > 4 && (frame_size >= (int) msdu_length))
actual_octets -=4;
ver_fpga = 0x11;
}
else {
ver_fpga = 0x01;
}
s_time = pcoreytohll(&s_trail_ptr[vVW510021_W_STARTT_OFF]);
e_time = pcoreytohll(&s_trail_ptr[vVW510021_W_ENDT_OFF]);
d_time = (guint32)((e_time - s_time) / NS_IN_US);
start_time = s_time / NS_IN_US;
s_sec = (start_time / US_IN_SEC);
s_usec = start_time - (s_sec * US_IN_SEC);
end_time = e_time / NS_IN_US;
m_ptr = &(rec[stats_offset+8+12]);
pay_off = 42;
sig_off = find_signature(m_ptr, rec_size - 20, pay_off, flow_id, flow_seq);
if ((m_ptr[sig_off] == 0xdd) && (sig_off + 15 <= (rec_size - vVW510021_W_STATS_TRAILER_LEN)))
sig_ts = get_signature_ts(m_ptr, sig_off);
else
sig_ts = 0;
if (IS_TX == 0 || IS_TX == 4) {
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
port_type = IS_TX << 4;
if (IS_TX == 4) {
phdr->len = OCTO_MODIFIED_RF_LEN + OCTO_TIMESTAMP_FIELDS_LEN + OCTO_LAYER1TO4_LEN + actual_octets;
phdr->caplen = OCTO_MODIFIED_RF_LEN + OCTO_TIMESTAMP_FIELDS_LEN + OCTO_LAYER1TO4_LEN + actual_octets;
} else {
phdr->len = OCTO_TIMESTAMP_FIELDS_LEN + OCTO_LAYER1TO4_LEN + actual_octets;
phdr->caplen = OCTO_TIMESTAMP_FIELDS_LEN + OCTO_LAYER1TO4_LEN + actual_octets;
}
if (phdr->caplen > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err_info = g_strdup_printf("vwr: File has %u-byte packet, bigger than maximum of %u",
phdr->caplen, WTAP_MAX_PACKET_SIZE_STANDARD);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
phdr->ts.secs = (time_t)s_sec;
phdr->ts.nsecs = (int)(s_usec * 1000);
phdr->pkt_encap = WTAP_ENCAP_IXVERIWAVE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ws_buffer_assure_space(buf, phdr->caplen);
data_ptr = ws_buffer_start_ptr(buf);
}
phtole8(&data_ptr[bytes_written], port_type);
bytes_written += 1;
if (IS_TX != 3) {
phtole8(&data_ptr[bytes_written], ver_fpga);
bytes_written += 1;
phtoles(&data_ptr[bytes_written], OCTO_TIMESTAMP_FIELDS_LEN);
bytes_written += 2;
if (IS_TX == 1 && sig_ts != 0) {
phtolel(&data_ptr[bytes_written], latency);
} else {
phtolel(&data_ptr[bytes_written], 0);
}
bytes_written += 4;
phtolel(&data_ptr[bytes_written], sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], start_time);
bytes_written += 8;
phtolell(&data_ptr[bytes_written], end_time);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], d_time);
bytes_written += 4;
}
if (IS_TX == 3 || IS_TX == 4) {
phtole8(&data_ptr[bytes_written], rf_id);
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
data_ptr[bytes_written] = 0;
bytes_written += 1;
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_NOISE_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_NOISE_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_NOISE_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_SNR_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_SNR_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_SNR_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_PFE_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_PFE_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_PFE_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_EVM_SD_SIG_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SD_SIG_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SD_SIG_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_EVM_SP_SIG_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SP_SIG_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SP_SIG_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_EVM_SD_DATA_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SD_DATA_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SD_DATA_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_EVM_SP_DATA_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SP_DATA_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_EVM_SP_DATA_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_DSYMBOL_IDX_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_DSYMBOL_IDX_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_DSYMBOL_IDX_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
for (i = 0; i < RF_NUMBER_OF_PORTS; i++)
{
if (pntoh16(&rf_ptr[RF_PORT_1_CONTEXT_OFF+i*RF_INTER_PORT_GAP_OFF]) == 0) {
phtoles(&data_ptr[bytes_written], 0);
bytes_written += 2;
} else {
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_CONTEXT_OFF+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
data_ptr[bytes_written] = rf_ptr[RF_PORT_1_CONTEXT_OFF+1+i*RF_INTER_PORT_GAP_OFF];
bytes_written += 1;
}
}
}
if (IS_TX != 3) {
phtoles(&data_ptr[bytes_written], OCTO_LAYER1TO4_LEN);
bytes_written += 2;
data_ptr[bytes_written] = l1p_1;
bytes_written += 1;
data_ptr[bytes_written] = (nss << 4) | IS_TX;
bytes_written += 1;
phtoles(&data_ptr[bytes_written], phyRate);
bytes_written += 2;
data_ptr[bytes_written] = l1p_2;
bytes_written += 1;
data_ptr[bytes_written] = rssi[0];
bytes_written += 1;
data_ptr[bytes_written] = rssi[1];
bytes_written += 1;
data_ptr[bytes_written] = rssi[2];
bytes_written += 1;
data_ptr[bytes_written] = rssi[3];
bytes_written += 1;
data_ptr[bytes_written] = s_start_ptr[2];
bytes_written += 1;
data_ptr[bytes_written] = s_start_ptr[3];
bytes_written += 1;
if (plcp_hdr_flag == 1 && (IS_TX == 0 || IS_TX == 4)) {
data_ptr[bytes_written] = L1InfoC;
} else {
data_ptr[bytes_written] = 0;
}
bytes_written += 1;
phtoles(&data_ptr[bytes_written], msdu_length);
bytes_written += 2;
memcpy(&data_ptr[bytes_written], &rec[stats_offset+16], 16);
bytes_written += 16;
phtolel(&data_ptr[bytes_written], pntoh32(&s_start_ptr[12]));
bytes_written += 4;
phtoles(&data_ptr[bytes_written], pntoh16(&s_trail_ptr[20]));
bytes_written += 2;
data_ptr[bytes_written] = flow_seq;
bytes_written += 1;
phtole24(&data_ptr[bytes_written], flow_id);
bytes_written += 3;
phtoles(&data_ptr[bytes_written], pntoh16(&s_trail_ptr[28]));
bytes_written += 2;
phtolel(&data_ptr[bytes_written], pntoh32(&s_trail_ptr[24]));
bytes_written += 4;
if (IS_TX == 0 || IS_TX == 4) {
phtoles(&data_ptr[bytes_written], info);
bytes_written += 2;
data_ptr[bytes_written] = info_2nd;
bytes_written += 1;
}
else {
phtoles(&data_ptr[bytes_written], info);
bytes_written += 2;
data_ptr[bytes_written] = 0;
bytes_written += 1;
}
phtolel(&data_ptr[bytes_written], errors);
bytes_written += 4;
memcpy(&data_ptr[bytes_written], &rec[stats_offset+(vwr->MPDU_OFF)], actual_octets);
}
return TRUE;
}
static gboolean vwr_read_rec_data_ethernet(vwr_t *vwr, struct wtap_pkthdr *phdr,
Buffer *buf, const guint8 *rec,
int rec_size, int IS_TX, int *err,
gchar **err_info)
{
guint8 *data_ptr;
int bytes_written = 0;
const guint8 *s_ptr, *m_ptr;
guint16 msdu_length, actual_octets;
guint flow_seq;
guint64 s_time = LL_ZERO, e_time = LL_ZERO;
guint32 latency = 0;
guint64 start_time, s_sec = LL_ZERO, s_usec = LL_ZERO;
guint64 end_time;
guint l4id;
guint16 info, validityBits;
guint32 errors;
guint16 vc_id;
guint32 flow_id, d_time;
int f_flow;
guint32 frame_type;
int mac_len, sig_off, pay_off;
guint64 sig_ts;
guint64 delta_b;
guint16 vw_flags;
if ((guint)rec_size < vwr->STATS_LEN) {
*err_info = g_strdup_printf("vwr: Invalid record length %d (must be at least %u)", rec_size, vwr->STATS_LEN);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
m_ptr = &(rec[0]);
s_ptr = &(rec[rec_size - vwr->STATS_LEN]);
msdu_length = pntoh16(&s_ptr[vwr->OCTET_OFF]);
actual_octets = msdu_length;
if (actual_octets > rec_size - vwr->STATS_LEN) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (runs past the end of the record)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
vc_id = pntoh16(&s_ptr[vwr->VCID_OFF]) & vwr->VCID_MASK;
flow_seq = s_ptr[vwr->FLOWSEQ_OFF];
frame_type = pntoh32(&s_ptr[vwr->FRAME_TYPE_OFF]);
if (vwr->FPGA_VERSION == vVW510024_E_FPGA) {
validityBits = pntoh16(&s_ptr[vwr->VALID_OFF]);
f_flow = validityBits & vwr->FLOW_VALID;
mac_len = (validityBits & vwr->IS_VLAN) ? 16 : 14;
errors = pntoh16(&s_ptr[vwr->ERRORS_OFF]);
}
else {
f_flow = s_ptr[vwr->VALID_OFF] & vwr->FLOW_VALID;
mac_len = (frame_type & vwr->IS_VLAN) ? 16 : 14;
errors = pntoh16(&s_ptr[vwr->ERRORS_OFF]);
}
info = pntoh16(&s_ptr[vwr->INFO_OFF]);
flow_id = pntoh24(&s_ptr[vwr->FLOWID_OFF]);
#if 0
tsid = pcorey48tohll(&s_ptr[vwr->LATVAL_OFF]);
#endif
l4id = pntoh16(&s_ptr[vwr->L4ID_OFF]);
if (actual_octets < 4) {
*err_info = g_strdup_printf("vwr: Invalid data length %u (too short to include 4 bytes of FCS)",
actual_octets);
*err = WTAP_ERR_BAD_FILE;
return FALSE;
}
actual_octets -= 4;
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
phdr->len = STATS_COMMON_FIELDS_LEN + EXT_ETHERNET_FIELDS_LEN + actual_octets;
phdr->caplen = STATS_COMMON_FIELDS_LEN + EXT_ETHERNET_FIELDS_LEN + actual_octets;
phdr->ts.secs = (time_t)s_sec;
phdr->ts.nsecs = (int)(s_usec * 1000);
phdr->pkt_encap = WTAP_ENCAP_IXVERIWAVE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
ws_buffer_assure_space(buf, phdr->caplen);
data_ptr = ws_buffer_start_ptr(buf);
phtole8(&data_ptr[bytes_written], ETHERNET_PORT);
bytes_written += 1;
phtole8(&data_ptr[bytes_written], 0);
bytes_written += 1;
phtoles(&data_ptr[bytes_written], STATS_COMMON_FIELDS_LEN);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], msdu_length);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], flow_id);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], vc_id);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], flow_seq);
bytes_written += 2;
if (!IS_TX && (sig_ts != 0)) {
phtolel(&data_ptr[bytes_written], latency);
} else {
phtolel(&data_ptr[bytes_written], 0);
}
bytes_written += 4;
phtolel(&data_ptr[bytes_written], sig_ts);
bytes_written += 4;
phtolell(&data_ptr[bytes_written], start_time)
bytes_written += 8;
phtolell(&data_ptr[bytes_written], end_time);
bytes_written += 8;
phtolel(&data_ptr[bytes_written], d_time);
bytes_written += 4;
phtoles(&data_ptr[bytes_written], EXT_ETHERNET_FIELDS_LEN);
bytes_written += 2;
vw_flags = 0;
if (IS_TX)
vw_flags |= VW_FLAGS_TXF;
if (errors & vwr->FCS_ERROR)
vw_flags |= VW_FLAGS_FCSERR;
phtoles(&data_ptr[bytes_written], vw_flags);
bytes_written += 2;
phtoles(&data_ptr[bytes_written], info);
bytes_written += 2;
phtolel(&data_ptr[bytes_written], errors);
bytes_written += 4;
phtolel(&data_ptr[bytes_written], l4id);
bytes_written += 4;
phtolel(&data_ptr[bytes_written], 0);
bytes_written += 4;
memcpy(&data_ptr[bytes_written], m_ptr, actual_octets);
return TRUE;
}
static int decode_msg(vwr_t *vwr, guint8 *rec, int *v_type, int *IS_TX, int *log_mode)
{
guint8 cmd,fpga_log_mode;
guint32 wd2, wd3;
int v_size;
cmd = rec[0];
fpga_log_mode = rec[1];
fpga_log_mode = ((fpga_log_mode & 0x30) >> 4);
wd2 = pntoh32(&rec[8]);
wd3 = pntoh32(&rec[12]);
if (vwr != NULL)
*log_mode = fpga_log_mode;
switch (cmd) {
case COMMAND_RX:
if (vwr != NULL) {
*IS_TX = 0;
}
v_size = (int)(wd2 & 0xffff);
*v_type = VT_FRAME;
break;
case COMMAND_TX:
if (vwr != NULL) {
*IS_TX = 1;
}
v_size = (int)(wd2 & 0xffff);
*v_type = VT_FRAME;
break;
case COMMAND_RF:
if (vwr != NULL) {
*IS_TX = 3;
}
v_size = (int)(wd2 & 0xffff);
*v_type = VT_FRAME;
break;
case COMMAND_RFRX:
if (vwr != NULL) {
*IS_TX = 4;
}
v_size = (int)(wd2 & 0xffff);
*v_type = VT_FRAME;
break;
case 0xc1:
case 0x8b:
case 0xbb:
if (vwr != NULL) {
*IS_TX = 2;
}
v_size = (int)(wd2 & 0xffff);
*v_type = VT_CPMSG;
break;
case 0xfe:
if (vwr != NULL) {
*IS_TX = 2;
}
v_size = (int)(wd3 & 0xffff);
*v_type = VT_CPMSG;
break;
default:
if (vwr != NULL) {
*IS_TX = 2;
}
v_size = 0;
*v_type = VT_UNKNOWN;
break;
}
return v_size;
}
static guint8 get_ofdm_rate(const guint8 *plcp)
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
default: return 0;
}
}
static guint8 get_cck_rate(const guint8 *plcp)
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
vwr->STATS_LEN = vVW510021_W_STATS_TRAILER_LEN;
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
vwr->MPDU_OFF = vVW510021_W_STATS_HEADER_LEN + 12;
break;
case S3_W_FPGA:
vwr->STATS_LEN = vVW510021_W_STATS_TRAILER_LEN;
vwr->PLCP_LENGTH_OFF = 16;
vwr->MPDU_OFF = 16 + 16;
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
int find_signature(const guint8 *m_ptr, int rec_size, int pay_off, guint32 flow_id, guint8 flow_seq)
{
int tgt;
guint32 fid;
if (m_ptr[pay_off] == 0xdd)
return pay_off;
for (tgt = pay_off; tgt < (rec_size); tgt++) {
if (m_ptr[tgt] == 0xdd) {
if ((tgt + 15 < rec_size) && (m_ptr[tgt + 15] == 0xe2)) {
if (m_ptr[tgt + 4] != flow_seq)
continue;
fid = pletoh24(&m_ptr[tgt + 1]);
if (fid != flow_id)
continue;
return (tgt);
}
else if (tgt + SIG_FSQ_OFF < rec_size)
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
return pay_off;
}
guint64 get_signature_ts(const guint8 *m_ptr,int sig_off)
{
int ts_offset;
guint64 sig_ts;
if (m_ptr[sig_off + 15] == 0xe2)
ts_offset = 5;
else
ts_offset = 8;
sig_ts = pletoh32(&m_ptr[sig_off + ts_offset]);
return (sig_ts & 0xffffffff);
}
static float
get_legacy_rate(guint8 rate_index)
{
static const float canonical_rate_legacy[] = {1.0f, 2.0f, 5.5f, 11.0f, 6.0f, 9.0f, 12.0f, 18.0f, 24.0f, 36.0f, 48.0f, 54.0f};
float bitrate = 0.0f;
if (rate_index < G_N_ELEMENTS(canonical_rate_legacy))
bitrate = canonical_rate_legacy[rate_index];
return bitrate;
}
static float
get_ht_rate(guint8 mcs_index, guint16 rflags)
{
static const int canonical_ndbps_20_ht[8] = {26, 52, 78, 104, 156, 208, 234, 260};
static const int canonical_ndbps_40_ht[8] = {54, 108, 162, 216, 324, 432, 486, 540};
float symbol_tx_time, bitrate;
int ndbps;
if (rflags & FLAGS_CHAN_SHORTGI)
symbol_tx_time = 3.6f;
else
symbol_tx_time = 4.0f;
if (rflags & FLAGS_CHAN_40MHZ)
ndbps = canonical_ndbps_40_ht[mcs_index - 8*(int)(mcs_index/8)];
else
ndbps = canonical_ndbps_20_ht[mcs_index - 8*(int)(mcs_index/8)];
bitrate = (ndbps * (((int)(mcs_index >> 3) + 1))) / symbol_tx_time;
return bitrate;
}
static float
get_vht_rate(guint8 mcs_index, guint16 rflags, guint8 nss)
{
static const int canonical_ndbps_20_vht[9] = {26, 52, 78, 104, 156, 208, 234, 260, 312};
static const int canonical_ndbps_40_vht[10] = {54, 108, 162, 216, 324, 432, 486, 540, 648, 720};
static const int canonical_ndbps_80_vht[10] = {117, 234, 351, 468, 702, 936, 1053, 1170, 1404, 1560};
float symbol_tx_time, bitrate;
if (rflags & FLAGS_CHAN_SHORTGI)
symbol_tx_time = 3.6f;
else
symbol_tx_time = 4.0f;
if (mcs_index > 9)
return 0.0f;
if (rflags & FLAGS_CHAN_40MHZ)
bitrate = (canonical_ndbps_40_vht[mcs_index] * nss) / symbol_tx_time;
else if (rflags & FLAGS_CHAN_80MHZ)
bitrate = (canonical_ndbps_80_vht[mcs_index] * nss) / symbol_tx_time;
else
{
if (mcs_index == 9)
{
if (nss == 3)
bitrate = 1040 / symbol_tx_time;
else if (nss == 6)
bitrate = 2080 / symbol_tx_time;
else
bitrate = 0.0f;
}
else
bitrate = (canonical_ndbps_20_vht[mcs_index] * nss) / symbol_tx_time;
}
return bitrate;
}
static gboolean
vwr_process_rec_data(FILE_T fh, int rec_size,
struct wtap_pkthdr *phdr, Buffer *buf, vwr_t *vwr,
int IS_TX, int log_mode, int *err, gchar **err_info)
{
guint8* rec;
gboolean ret = FALSE;
rec = (guint8*)g_malloc(B_SIZE);
if (!wtap_read_bytes(fh, rec, rec_size, err, err_info))
{
g_free(rec);
return FALSE;
}
switch (vwr->FPGA_VERSION)
{
case S1_W_FPGA:
ret = vwr_read_s1_W_rec(vwr, phdr, buf, rec, rec_size, err, err_info);
break;
case S2_W_FPGA:
ret = vwr_read_s2_W_rec(vwr, phdr, buf, rec, rec_size, IS_TX, err, err_info);
break;
case S3_W_FPGA:
ret = vwr_read_s3_W_rec(vwr, phdr, buf, rec, rec_size, IS_TX, log_mode, err, err_info);
break;
case vVW510012_E_FPGA:
case vVW510024_E_FPGA:
ret = vwr_read_rec_data_ethernet(vwr, phdr, buf, rec, rec_size, IS_TX, err, err_info);
break;
default:
g_free(rec);
g_assert_not_reached();
return ret;
}
g_free(rec);
return ret;
}
