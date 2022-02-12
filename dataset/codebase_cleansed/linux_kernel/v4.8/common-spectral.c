static s8 fix_rssi_inv_only(u8 rssi_val)
{
if (rssi_val == 128)
rssi_val = 0;
return (s8) rssi_val;
}
static void ath_debug_send_fft_sample(struct ath_spec_scan_priv *spec_priv,
struct fft_sample_tlv *fft_sample_tlv)
{
int length;
if (!spec_priv->rfs_chan_spec_scan)
return;
length = __be16_to_cpu(fft_sample_tlv->length) +
sizeof(*fft_sample_tlv);
relay_write(spec_priv->rfs_chan_spec_scan, fft_sample_tlv, length);
}
static int
ath_cmn_max_idx_verify_ht20_fft(u8 *sample_end, int bytes_read)
{
struct ath_ht20_mag_info *mag_info;
u8 *sample;
u16 max_magnitude;
u8 max_index;
u8 max_exp;
if (bytes_read < SPECTRAL_HT20_SAMPLE_LEN - 1)
return -1;
mag_info = (struct ath_ht20_mag_info *) (sample_end -
sizeof(struct ath_ht20_mag_info) + 1);
sample = sample_end - SPECTRAL_HT20_SAMPLE_LEN + 1;
max_index = spectral_max_index(mag_info->all_bins,
SPECTRAL_HT20_NUM_BINS);
max_magnitude = spectral_max_magnitude(mag_info->all_bins);
max_exp = mag_info->max_exp & 0xf;
if (bytes_read < SPECTRAL_HT20_SAMPLE_LEN && max_index < 1)
return -1;
if (sample[max_index] != (max_magnitude >> max_exp))
return -1;
else
return 0;
}
static int
ath_cmn_max_idx_verify_ht20_40_fft(u8 *sample_end, int bytes_read)
{
struct ath_ht20_40_mag_info *mag_info;
u8 *sample;
u16 lower_mag, upper_mag;
u8 lower_max_index, upper_max_index;
u8 max_exp;
int dc_pos = SPECTRAL_HT20_40_NUM_BINS / 2;
if (bytes_read < SPECTRAL_HT20_40_SAMPLE_LEN - 1)
return -1;
mag_info = (struct ath_ht20_40_mag_info *) (sample_end -
sizeof(struct ath_ht20_40_mag_info) + 1);
sample = sample_end - SPECTRAL_HT20_40_SAMPLE_LEN + 1;
lower_mag = spectral_max_magnitude(mag_info->lower_bins);
lower_max_index = spectral_max_index(mag_info->lower_bins,
SPECTRAL_HT20_40_NUM_BINS);
upper_mag = spectral_max_magnitude(mag_info->upper_bins);
upper_max_index = spectral_max_index(mag_info->upper_bins,
SPECTRAL_HT20_40_NUM_BINS);
max_exp = mag_info->max_exp & 0xf;
if (bytes_read < SPECTRAL_HT20_40_SAMPLE_LEN &&
((upper_max_index < 1) || (lower_max_index < 1)))
return -1;
if ((upper_max_index - dc_pos > 0) &&
(sample[upper_max_index] == (upper_mag >> max_exp)))
upper_max_index -= dc_pos;
if ((lower_max_index - dc_pos > 0) &&
(sample[lower_max_index - dc_pos] == (lower_mag >> max_exp)))
lower_max_index -= dc_pos;
if ((sample[upper_max_index + dc_pos] != (upper_mag >> max_exp)) ||
(sample[lower_max_index] != (lower_mag >> max_exp)))
return -1;
else
return 0;
}
static int
ath_cmn_process_ht20_fft(struct ath_rx_status *rs,
struct ath_spec_scan_priv *spec_priv,
u8 *sample_buf,
u64 tsf, u16 freq, int chan_type)
{
struct fft_sample_ht20 fft_sample_20;
struct ath_common *common = ath9k_hw_common(spec_priv->ah);
struct ath_hw *ah = spec_priv->ah;
struct ath_ht20_mag_info *mag_info;
struct fft_sample_tlv *tlv;
int i = 0;
int ret = 0;
int dc_pos = SPECTRAL_HT20_NUM_BINS / 2;
u16 magnitude, tmp_mag, length;
u8 max_index, bitmap_w, max_exp;
length = sizeof(fft_sample_20) - sizeof(struct fft_sample_tlv);
fft_sample_20.tlv.type = ATH_FFT_SAMPLE_HT20;
fft_sample_20.tlv.length = __cpu_to_be16(length);
fft_sample_20.freq = __cpu_to_be16(freq);
fft_sample_20.rssi = fix_rssi_inv_only(rs->rs_rssi_ctl[0]);
fft_sample_20.noise = ah->noise;
mag_info = (struct ath_ht20_mag_info *) (sample_buf +
SPECTRAL_HT20_NUM_BINS);
magnitude = spectral_max_magnitude(mag_info->all_bins);
fft_sample_20.max_magnitude = __cpu_to_be16(magnitude);
max_index = spectral_max_index(mag_info->all_bins,
SPECTRAL_HT20_NUM_BINS);
fft_sample_20.max_index = max_index;
bitmap_w = spectral_bitmap_weight(mag_info->all_bins);
fft_sample_20.bitmap_weight = bitmap_w;
max_exp = mag_info->max_exp & 0xf;
fft_sample_20.max_exp = max_exp;
fft_sample_20.tsf = __cpu_to_be64(tsf);
memcpy(fft_sample_20.data, sample_buf, SPECTRAL_HT20_NUM_BINS);
ath_dbg(common, SPECTRAL_SCAN, "FFT HT20 frame: max mag 0x%X,"
"max_mag_idx %i\n",
magnitude >> max_exp,
max_index);
if (fft_sample_20.data[max_index] != (magnitude >> max_exp)) {
ath_dbg(common, SPECTRAL_SCAN, "Magnitude mismatch !\n");
ret = -1;
}
fft_sample_20.data[dc_pos] = (fft_sample_20.data[dc_pos + 1] +
fft_sample_20.data[dc_pos - 1]) / 2;
if (max_index == dc_pos) {
tmp_mag = 0;
for (i = 0; i < dc_pos; i++) {
if (fft_sample_20.data[i] > tmp_mag) {
tmp_mag = fft_sample_20.data[i];
fft_sample_20.max_index = i;
}
}
magnitude = tmp_mag << max_exp;
fft_sample_20.max_magnitude = __cpu_to_be16(magnitude);
ath_dbg(common, SPECTRAL_SCAN,
"Calculated new lower max 0x%X at %i\n",
tmp_mag, fft_sample_20.max_index);
} else
for (i = 0; i < SPECTRAL_HT20_NUM_BINS; i++) {
if (fft_sample_20.data[i] == (magnitude >> max_exp))
ath_dbg(common, SPECTRAL_SCAN,
"Got max: 0x%X at index %i\n",
fft_sample_20.data[i], i);
if (fft_sample_20.data[i] > (magnitude >> max_exp)) {
ath_dbg(common, SPECTRAL_SCAN,
"Got bin %i greater than max: 0x%X\n",
i, fft_sample_20.data[i]);
ret = -1;
}
}
if (ret < 0)
return ret;
tlv = (struct fft_sample_tlv *)&fft_sample_20;
ath_debug_send_fft_sample(spec_priv, tlv);
return 0;
}
static int
ath_cmn_process_ht20_40_fft(struct ath_rx_status *rs,
struct ath_spec_scan_priv *spec_priv,
u8 *sample_buf,
u64 tsf, u16 freq, int chan_type)
{
struct fft_sample_ht20_40 fft_sample_40;
struct ath_common *common = ath9k_hw_common(spec_priv->ah);
struct ath_hw *ah = spec_priv->ah;
struct ath9k_hw_cal_data *caldata = ah->caldata;
struct ath_ht20_40_mag_info *mag_info;
struct fft_sample_tlv *tlv;
int dc_pos = SPECTRAL_HT20_40_NUM_BINS / 2;
int i = 0;
int ret = 0;
s16 ext_nf;
u16 lower_mag, upper_mag, tmp_mag, length;
s8 lower_rssi, upper_rssi;
u8 lower_max_index, upper_max_index;
u8 lower_bitmap_w, upper_bitmap_w, max_exp;
if (caldata)
ext_nf = ath9k_hw_getchan_noise(ah, ah->curchan,
caldata->nfCalHist[3].privNF);
else
ext_nf = ATH_DEFAULT_NOISE_FLOOR;
length = sizeof(fft_sample_40) - sizeof(struct fft_sample_tlv);
fft_sample_40.tlv.type = ATH_FFT_SAMPLE_HT20_40;
fft_sample_40.tlv.length = __cpu_to_be16(length);
fft_sample_40.freq = __cpu_to_be16(freq);
fft_sample_40.channel_type = chan_type;
if (chan_type == NL80211_CHAN_HT40PLUS) {
lower_rssi = fix_rssi_inv_only(rs->rs_rssi_ctl[0]);
upper_rssi = fix_rssi_inv_only(rs->rs_rssi_ext[0]);
fft_sample_40.lower_noise = ah->noise;
fft_sample_40.upper_noise = ext_nf;
} else {
lower_rssi = fix_rssi_inv_only(rs->rs_rssi_ext[0]);
upper_rssi = fix_rssi_inv_only(rs->rs_rssi_ctl[0]);
fft_sample_40.lower_noise = ext_nf;
fft_sample_40.upper_noise = ah->noise;
}
fft_sample_40.lower_rssi = lower_rssi;
fft_sample_40.upper_rssi = upper_rssi;
mag_info = (struct ath_ht20_40_mag_info *) (sample_buf +
SPECTRAL_HT20_40_NUM_BINS);
lower_mag = spectral_max_magnitude(mag_info->lower_bins);
fft_sample_40.lower_max_magnitude = __cpu_to_be16(lower_mag);
upper_mag = spectral_max_magnitude(mag_info->upper_bins);
fft_sample_40.upper_max_magnitude = __cpu_to_be16(upper_mag);
lower_max_index = spectral_max_index(mag_info->lower_bins,
SPECTRAL_HT20_40_NUM_BINS);
fft_sample_40.lower_max_index = lower_max_index;
upper_max_index = spectral_max_index(mag_info->upper_bins,
SPECTRAL_HT20_40_NUM_BINS);
fft_sample_40.upper_max_index = upper_max_index;
lower_bitmap_w = spectral_bitmap_weight(mag_info->lower_bins);
fft_sample_40.lower_bitmap_weight = lower_bitmap_w;
upper_bitmap_w = spectral_bitmap_weight(mag_info->upper_bins);
fft_sample_40.upper_bitmap_weight = upper_bitmap_w;
max_exp = mag_info->max_exp & 0xf;
fft_sample_40.max_exp = max_exp;
fft_sample_40.tsf = __cpu_to_be64(tsf);
memcpy(fft_sample_40.data, sample_buf, SPECTRAL_HT20_40_NUM_BINS);
ath_dbg(common, SPECTRAL_SCAN, "FFT HT20/40 frame: lower mag 0x%X,"
"lower_mag_idx %i, upper mag 0x%X,"
"upper_mag_idx %i\n",
lower_mag >> max_exp,
lower_max_index,
upper_mag >> max_exp,
upper_max_index);
if ((upper_max_index - dc_pos > 0) &&
(fft_sample_40.data[upper_max_index] == (upper_mag >> max_exp))) {
upper_max_index -= dc_pos;
fft_sample_40.upper_max_index = upper_max_index;
}
if ((lower_max_index - dc_pos > 0) &&
(fft_sample_40.data[lower_max_index - dc_pos] ==
(lower_mag >> max_exp))) {
lower_max_index -= dc_pos;
fft_sample_40.lower_max_index = lower_max_index;
}
if ((fft_sample_40.data[upper_max_index + dc_pos]
!= (upper_mag >> max_exp)) ||
(fft_sample_40.data[lower_max_index]
!= (lower_mag >> max_exp))) {
ath_dbg(common, SPECTRAL_SCAN, "Magnitude mismatch !\n");
ret = -1;
}
fft_sample_40.data[dc_pos] = (fft_sample_40.data[dc_pos + 1] +
fft_sample_40.data[dc_pos - 1]) / 2;
if (lower_max_index == dc_pos) {
tmp_mag = 0;
for (i = 0; i < dc_pos; i++) {
if (fft_sample_40.data[i] > tmp_mag) {
tmp_mag = fft_sample_40.data[i];
fft_sample_40.lower_max_index = i;
}
}
lower_mag = tmp_mag << max_exp;
fft_sample_40.lower_max_magnitude = __cpu_to_be16(lower_mag);
ath_dbg(common, SPECTRAL_SCAN,
"Calculated new lower max 0x%X at %i\n",
tmp_mag, fft_sample_40.lower_max_index);
} else
for (i = 0; i < dc_pos; i++) {
if (fft_sample_40.data[i] == (lower_mag >> max_exp))
ath_dbg(common, SPECTRAL_SCAN,
"Got lower mag: 0x%X at index %i\n",
fft_sample_40.data[i], i);
if (fft_sample_40.data[i] > (lower_mag >> max_exp)) {
ath_dbg(common, SPECTRAL_SCAN,
"Got lower bin %i higher than max: 0x%X\n",
i, fft_sample_40.data[i]);
ret = -1;
}
}
if (upper_max_index == dc_pos) {
tmp_mag = 0;
for (i = dc_pos; i < SPECTRAL_HT20_40_NUM_BINS; i++) {
if (fft_sample_40.data[i] > tmp_mag) {
tmp_mag = fft_sample_40.data[i];
fft_sample_40.upper_max_index = i;
}
}
upper_mag = tmp_mag << max_exp;
fft_sample_40.upper_max_magnitude = __cpu_to_be16(upper_mag);
ath_dbg(common, SPECTRAL_SCAN,
"Calculated new upper max 0x%X at %i\n",
tmp_mag, i);
} else
for (i = dc_pos; i < SPECTRAL_HT20_40_NUM_BINS; i++) {
if (fft_sample_40.data[i] == (upper_mag >> max_exp))
ath_dbg(common, SPECTRAL_SCAN,
"Got upper mag: 0x%X at index %i\n",
fft_sample_40.data[i], i);
if (fft_sample_40.data[i] > (upper_mag >> max_exp)) {
ath_dbg(common, SPECTRAL_SCAN,
"Got upper bin %i higher than max: 0x%X\n",
i, fft_sample_40.data[i]);
ret = -1;
}
}
if (ret < 0)
return ret;
tlv = (struct fft_sample_tlv *)&fft_sample_40;
ath_debug_send_fft_sample(spec_priv, tlv);
return 0;
}
static inline void
ath_cmn_copy_fft_frame(u8 *in, u8 *out, int sample_len, int sample_bytes)
{
switch (sample_bytes - sample_len) {
case -1:
memcpy(&out[1], in,
sample_len - 1);
break;
case 0:
memcpy(out, in, sample_len);
break;
case 1:
memcpy(&out[1], in, 30);
out[31] = in[31];
memcpy(&out[32], &in[33],
sample_len - 32);
break;
case 2:
memcpy(out, in, 30);
out[30] = in[31];
memcpy(&out[31], &in[33],
sample_len - 31);
break;
default:
break;
}
}
static int
ath_cmn_is_fft_buf_full(struct ath_spec_scan_priv *spec_priv)
{
int i = 0;
int ret = 0;
struct rchan *rc = spec_priv->rfs_chan_spec_scan;
for_each_online_cpu(i)
ret += relay_buf_full(rc->buf[i]);
i = num_online_cpus();
if (ret == i)
return 1;
else
return 0;
}
int ath_cmn_process_fft(struct ath_spec_scan_priv *spec_priv, struct ieee80211_hdr *hdr,
struct ath_rx_status *rs, u64 tsf)
{
u8 sample_buf[SPECTRAL_SAMPLE_MAX_LEN] = {0};
struct ath_hw *ah = spec_priv->ah;
struct ath_common *common = ath9k_hw_common(spec_priv->ah);
u8 num_bins, *vdata = (u8 *)hdr;
struct ath_radar_info *radar_info;
int len = rs->rs_datalen;
int i;
int got_slen = 0;
u8 *sample_start;
int sample_bytes = 0;
int ret = 0;
u16 fft_len, sample_len, freq = ah->curchan->chan->center_freq;
enum nl80211_channel_type chan_type;
ath_cmn_fft_idx_validator *fft_idx_validator;
ath_cmn_fft_sample_handler *fft_handler;
if (rs->rs_phyerr != ATH9K_PHYERR_RADAR &&
rs->rs_phyerr != ATH9K_PHYERR_FALSE_RADAR_EXT &&
rs->rs_phyerr != ATH9K_PHYERR_SPECTRAL)
return 0;
radar_info = ((struct ath_radar_info *)&vdata[len]) - 1;
if (!(radar_info->pulse_bw_info & SPECTRAL_SCAN_BITMASK))
return 0;
ret = ath_cmn_is_fft_buf_full(spec_priv);
if (ret == 1) {
ath_dbg(common, SPECTRAL_SCAN, "FFT report ignored, no space "
"left on output buffers\n");
return 1;
}
chan_type = cfg80211_get_chandef_type(&common->hw->conf.chandef);
if ((chan_type == NL80211_CHAN_HT40MINUS) ||
(chan_type == NL80211_CHAN_HT40PLUS)) {
fft_len = SPECTRAL_HT20_40_TOTAL_DATA_LEN;
sample_len = SPECTRAL_HT20_40_SAMPLE_LEN;
num_bins = SPECTRAL_HT20_40_NUM_BINS;
fft_idx_validator = &ath_cmn_max_idx_verify_ht20_40_fft;
fft_handler = &ath_cmn_process_ht20_40_fft;
} else {
fft_len = SPECTRAL_HT20_TOTAL_DATA_LEN;
sample_len = SPECTRAL_HT20_SAMPLE_LEN;
num_bins = SPECTRAL_HT20_NUM_BINS;
fft_idx_validator = ath_cmn_max_idx_verify_ht20_fft;
fft_handler = &ath_cmn_process_ht20_fft;
}
ath_dbg(common, SPECTRAL_SCAN, "Got radar dump bw_info: 0x%X,"
"len: %i fft_len: %i\n",
radar_info->pulse_bw_info,
len,
fft_len);
sample_start = vdata;
for (i = 0; i < len - 2; i++) {
sample_bytes++;
if (len <= fft_len + 2) {
sample_bytes = len - sizeof(struct ath_radar_info);
got_slen = 1;
}
if (vdata[i] <= 0x7 && sample_bytes >= sample_len - 1) {
if ((sample_bytes > sample_len + 2) ||
((sample_bytes > sample_len) &&
(sample_start[31] != sample_start[32])))
break;
if (!fft_idx_validator(&vdata[i], i)) {
ath_dbg(common, SPECTRAL_SCAN,
"Found valid fft frame at %i\n", i);
got_slen = 1;
}
else if ((sample_start[31] == sample_start[32]) &&
(sample_bytes >= sample_len) &&
(sample_bytes < sample_len + 2) &&
(vdata[i + 1] <= 0x7))
continue;
else if ((sample_bytes == sample_len - 1) &&
(vdata[i + 1] <= 0x7))
continue;
got_slen = 1;
}
if (got_slen) {
ath_dbg(common, SPECTRAL_SCAN, "FFT frame len: %i\n",
sample_bytes);
if (sample_bytes != sample_len && len <= fft_len + 2) {
ath_cmn_copy_fft_frame(sample_start,
sample_buf, sample_len,
sample_bytes);
fft_handler(rs, spec_priv, sample_buf,
tsf, freq, chan_type);
memset(sample_buf, 0, SPECTRAL_SAMPLE_MAX_LEN);
add_device_randomness(sample_buf, num_bins);
}
if (sample_bytes == sample_len) {
ret = fft_handler(rs, spec_priv, sample_start,
tsf, freq, chan_type);
add_device_randomness(sample_start, num_bins);
}
if (len <= fft_len + 2)
break;
sample_start = &vdata[i + 1];
if (ret == 0) {
i += num_bins - 2;
sample_bytes = num_bins - 2;
}
got_slen = 0;
}
}
i -= num_bins - 2;
if (len - i != sizeof(struct ath_radar_info))
ath_dbg(common, SPECTRAL_SCAN, "FFT report truncated"
"(bytes left: %i)\n",
len - i);
return 1;
}
static ssize_t read_file_spec_scan_ctl(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
char *mode = "";
unsigned int len;
switch (spec_priv->spectral_mode) {
case SPECTRAL_DISABLED:
mode = "disable";
break;
case SPECTRAL_BACKGROUND:
mode = "background";
break;
case SPECTRAL_CHANSCAN:
mode = "chanscan";
break;
case SPECTRAL_MANUAL:
mode = "manual";
break;
}
len = strlen(mode);
return simple_read_from_buffer(user_buf, count, ppos, mode, len);
}
void ath9k_cmn_spectral_scan_trigger(struct ath_common *common,
struct ath_spec_scan_priv *spec_priv)
{
struct ath_hw *ah = spec_priv->ah;
u32 rxfilter;
if (IS_ENABLED(CONFIG_ATH9K_TX99))
return;
if (!ath9k_hw_ops(ah)->spectral_scan_trigger) {
ath_err(common, "spectrum analyzer not implemented on this hardware\n");
return;
}
ath_ps_ops(common)->wakeup(common);
rxfilter = ath9k_hw_getrxfilter(ah);
ath9k_hw_setrxfilter(ah, rxfilter |
ATH9K_RX_FILTER_PHYRADAR |
ATH9K_RX_FILTER_PHYERR);
ath9k_cmn_spectral_scan_config(common, spec_priv, spec_priv->spectral_mode);
ath9k_hw_ops(ah)->spectral_scan_trigger(ah);
ath_ps_ops(common)->restore(common);
}
int ath9k_cmn_spectral_scan_config(struct ath_common *common,
struct ath_spec_scan_priv *spec_priv,
enum spectral_mode spectral_mode)
{
struct ath_hw *ah = spec_priv->ah;
if (!ath9k_hw_ops(ah)->spectral_scan_trigger) {
ath_err(common, "spectrum analyzer not implemented on this hardware\n");
return -1;
}
switch (spectral_mode) {
case SPECTRAL_DISABLED:
spec_priv->spec_config.enabled = 0;
break;
case SPECTRAL_BACKGROUND:
spec_priv->spec_config.endless = 1;
spec_priv->spec_config.enabled = 1;
break;
case SPECTRAL_CHANSCAN:
case SPECTRAL_MANUAL:
spec_priv->spec_config.endless = 0;
spec_priv->spec_config.enabled = 1;
break;
default:
return -1;
}
ath_ps_ops(common)->wakeup(common);
ath9k_hw_ops(ah)->spectral_scan_config(ah, &spec_priv->spec_config);
ath_ps_ops(common)->restore(common);
spec_priv->spectral_mode = spectral_mode;
return 0;
}
static ssize_t write_file_spec_scan_ctl(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
struct ath_common *common = ath9k_hw_common(spec_priv->ah);
char buf[32];
ssize_t len;
if (IS_ENABLED(CONFIG_ATH9K_TX99))
return -EOPNOTSUPP;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (strncmp("trigger", buf, 7) == 0) {
ath9k_cmn_spectral_scan_trigger(common, spec_priv);
} else if (strncmp("background", buf, 10) == 0) {
ath9k_cmn_spectral_scan_config(common, spec_priv, SPECTRAL_BACKGROUND);
ath_dbg(common, CONFIG, "spectral scan: background mode enabled\n");
} else if (strncmp("chanscan", buf, 8) == 0) {
ath9k_cmn_spectral_scan_config(common, spec_priv, SPECTRAL_CHANSCAN);
ath_dbg(common, CONFIG, "spectral scan: channel scan mode enabled\n");
} else if (strncmp("manual", buf, 6) == 0) {
ath9k_cmn_spectral_scan_config(common, spec_priv, SPECTRAL_MANUAL);
ath_dbg(common, CONFIG, "spectral scan: manual mode enabled\n");
} else if (strncmp("disable", buf, 7) == 0) {
ath9k_cmn_spectral_scan_config(common, spec_priv, SPECTRAL_DISABLED);
ath_dbg(common, CONFIG, "spectral scan: disabled\n");
} else {
return -EINVAL;
}
return count;
}
static ssize_t read_file_spectral_short_repeat(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
char buf[32];
unsigned int len;
len = sprintf(buf, "%d\n", spec_priv->spec_config.short_repeat);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t write_file_spectral_short_repeat(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
unsigned long val;
char buf[32];
ssize_t len;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoul(buf, 0, &val))
return -EINVAL;
if (val > 1)
return -EINVAL;
spec_priv->spec_config.short_repeat = val;
return count;
}
static ssize_t read_file_spectral_count(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
char buf[32];
unsigned int len;
len = sprintf(buf, "%d\n", spec_priv->spec_config.count);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t write_file_spectral_count(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
unsigned long val;
char buf[32];
ssize_t len;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoul(buf, 0, &val))
return -EINVAL;
if (val > 255)
return -EINVAL;
spec_priv->spec_config.count = val;
return count;
}
static ssize_t read_file_spectral_period(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
char buf[32];
unsigned int len;
len = sprintf(buf, "%d\n", spec_priv->spec_config.period);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t write_file_spectral_period(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
unsigned long val;
char buf[32];
ssize_t len;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoul(buf, 0, &val))
return -EINVAL;
if (val > 255)
return -EINVAL;
spec_priv->spec_config.period = val;
return count;
}
static ssize_t read_file_spectral_fft_period(struct file *file,
char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
char buf[32];
unsigned int len;
len = sprintf(buf, "%d\n", spec_priv->spec_config.fft_period);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t write_file_spectral_fft_period(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
struct ath_spec_scan_priv *spec_priv = file->private_data;
unsigned long val;
char buf[32];
ssize_t len;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoul(buf, 0, &val))
return -EINVAL;
if (val > 15)
return -EINVAL;
spec_priv->spec_config.fft_period = val;
return count;
}
static struct dentry *create_buf_file_handler(const char *filename,
struct dentry *parent,
umode_t mode,
struct rchan_buf *buf,
int *is_global)
{
struct dentry *buf_file;
buf_file = debugfs_create_file(filename, mode, parent, buf,
&relay_file_operations);
*is_global = 1;
return buf_file;
}
static int remove_buf_file_handler(struct dentry *dentry)
{
debugfs_remove(dentry);
return 0;
}
void ath9k_cmn_spectral_deinit_debug(struct ath_spec_scan_priv *spec_priv)
{
if (IS_ENABLED(CONFIG_ATH9K_DEBUGFS)) {
relay_close(spec_priv->rfs_chan_spec_scan);
spec_priv->rfs_chan_spec_scan = NULL;
}
}
void ath9k_cmn_spectral_init_debug(struct ath_spec_scan_priv *spec_priv,
struct dentry *debugfs_phy)
{
spec_priv->rfs_chan_spec_scan = relay_open("spectral_scan",
debugfs_phy,
1024, 256, &rfs_spec_scan_cb,
NULL);
debugfs_create_file("spectral_scan_ctl",
S_IRUSR | S_IWUSR,
debugfs_phy, spec_priv,
&fops_spec_scan_ctl);
debugfs_create_file("spectral_short_repeat",
S_IRUSR | S_IWUSR,
debugfs_phy, spec_priv,
&fops_spectral_short_repeat);
debugfs_create_file("spectral_count",
S_IRUSR | S_IWUSR,
debugfs_phy, spec_priv,
&fops_spectral_count);
debugfs_create_file("spectral_period",
S_IRUSR | S_IWUSR,
debugfs_phy, spec_priv,
&fops_spectral_period);
debugfs_create_file("spectral_fft_period",
S_IRUSR | S_IWUSR,
debugfs_phy, spec_priv,
&fops_spectral_fft_period);
}
