static inline int fft_max_index(u8 *bins)
{
return (bins[2] & 0xfc) >> 2;
}
static inline int fft_max_magnitude(u8 *bins)
{
return (bins[0] & 0xc0) >> 6 | bins[1] << 2 | (bins[2] & 0x03) << 10;
}
static inline u8 fft_bitmap_weight(u8 *bins)
{
return bins[0] & 0x3f;
}
static int ath9k_get_max_index_ht40(struct ath9k_dfs_fft_40 *fft,
bool is_ctl, bool is_ext)
{
const int DFS_UPPER_BIN_OFFSET = 64;
if (is_ctl && is_ext) {
is_ctl = fft_bitmap_weight(fft->lower_bins) != 0;
is_ext = fft_bitmap_weight(fft->upper_bins) != 0;
if (is_ctl && is_ext) {
int mag_lower = fft_max_magnitude(fft->lower_bins);
int mag_upper = fft_max_magnitude(fft->upper_bins);
if (mag_upper > mag_lower)
is_ctl = false;
else
is_ext = false;
}
}
if (is_ctl)
return fft_max_index(fft->lower_bins);
return fft_max_index(fft->upper_bins) + DFS_UPPER_BIN_OFFSET;
}
static bool ath9k_check_chirping(struct ath_softc *sc, u8 *data,
int datalen, bool is_ctl, bool is_ext)
{
int i;
int max_bin[FFT_NUM_SAMPLES];
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
int prev_delta;
if (IS_CHAN_HT40(ah->curchan)) {
struct ath9k_dfs_fft_40 *fft = (struct ath9k_dfs_fft_40 *) data;
int num_fft_packets = datalen / sizeof(*fft);
if (num_fft_packets == 0)
return false;
ath_dbg(common, DFS, "HT40: datalen=%d, num_fft_packets=%d\n",
datalen, num_fft_packets);
if (num_fft_packets < (FFT_NUM_SAMPLES)) {
ath_dbg(common, DFS, "not enough packets for chirp\n");
return false;
}
if ((datalen % sizeof(*fft)) == 2) {
fft = (struct ath9k_dfs_fft_40 *) (data + 2);
ath_dbg(common, DFS, "fixing datalen by 2\n");
}
if (IS_CHAN_HT40MINUS(ah->curchan)) {
int temp = is_ctl;
is_ctl = is_ext;
is_ext = temp;
}
for (i = 0; i < FFT_NUM_SAMPLES; i++)
max_bin[i] = ath9k_get_max_index_ht40(fft + i, is_ctl,
is_ext);
} else {
struct ath9k_dfs_fft_20 *fft = (struct ath9k_dfs_fft_20 *) data;
int num_fft_packets = datalen / sizeof(*fft);
if (num_fft_packets == 0)
return false;
ath_dbg(common, DFS, "HT20: datalen=%d, num_fft_packets=%d\n",
datalen, num_fft_packets);
if (num_fft_packets < (FFT_NUM_SAMPLES)) {
ath_dbg(common, DFS, "not enough packets for chirp\n");
return false;
}
for (i = 0; i < FFT_NUM_SAMPLES; i++)
max_bin[i] = fft_max_index(fft[i].lower_bins) ^ 0x20;
}
ath_dbg(common, DFS, "bin_max = [%d, %d, %d, %d]\n",
max_bin[0], max_bin[1], max_bin[2], max_bin[3]);
prev_delta = 0;
for (i = 0; i < NUM_DIFFS; i++) {
int ddelta = -1;
int delta = max_bin[i + 1] - max_bin[i];
if (abs(delta) < BIN_DELTA_MIN || abs(delta) > BIN_DELTA_MAX) {
ath_dbg(common, DFS, "CHIRP: invalid delta %d "
"in sample %d\n", delta, i);
return false;
}
if (i == 0)
goto done;
ddelta = delta - prev_delta;
if (abs(ddelta) > MAX_DIFF) {
ath_dbg(common, DFS, "CHIRP: ddelta %d too high\n",
ddelta);
return false;
}
done:
ath_dbg(common, DFS, "CHIRP - %d: delta=%d, ddelta=%d\n",
i, delta, ddelta);
prev_delta = delta;
}
return true;
}
static u32 dur_to_usecs(struct ath_hw *ah, u32 dur)
{
const u32 AR93X_NSECS_PER_DUR = 800;
const u32 AR93X_NSECS_PER_DUR_FAST = (8000 / 11);
u32 nsecs;
if (IS_CHAN_A_FAST_CLOCK(ah, ah->curchan))
nsecs = dur * AR93X_NSECS_PER_DUR_FAST;
else
nsecs = dur * AR93X_NSECS_PER_DUR;
return (nsecs + 500) / 1000;
}
static bool
ath9k_postprocess_radar_event(struct ath_softc *sc,
struct ath_radar_data *ard,
struct pulse_event *pe)
{
u8 rssi;
u16 dur;
ard->pulse_bw_info &= 0x03;
switch (ard->pulse_bw_info) {
case PRI_CH_RADAR_FOUND:
dur = ard->pulse_length_pri;
DFS_STAT_INC(sc, pri_phy_errors);
rssi = (ard->ext_rssi >= (ard->rssi + 3)) ? 0 : ard->rssi;
break;
case EXT_CH_RADAR_FOUND:
dur = ard->pulse_length_ext;
DFS_STAT_INC(sc, ext_phy_errors);
rssi = (ard->rssi >= (ard->ext_rssi + 12)) ? 0 : ard->ext_rssi;
break;
case (PRI_CH_RADAR_FOUND | EXT_CH_RADAR_FOUND):
if (ard->pulse_length_ext >= ard->pulse_length_pri)
dur = ard->pulse_length_ext;
else
dur = ard->pulse_length_pri;
DFS_STAT_INC(sc, dc_phy_errors);
rssi = (ard->rssi < ard->ext_rssi) ? ard->ext_rssi : ard->rssi;
break;
default:
DFS_STAT_INC(sc, bwinfo_discards);
return false;
}
if (rssi == 0) {
DFS_STAT_INC(sc, rssi_discards);
return false;
}
pe->width = dur_to_usecs(sc->sc_ah, dur);
pe->rssi = rssi;
DFS_STAT_INC(sc, pulses_detected);
return true;
}
static void
ath9k_dfs_process_radar_pulse(struct ath_softc *sc, struct pulse_event *pe)
{
struct dfs_pattern_detector *pd = sc->dfs_detector;
DFS_STAT_INC(sc, pulses_processed);
if (pd == NULL)
return;
if (!pd->add_pulse(pd, pe))
return;
DFS_STAT_INC(sc, radar_detected);
ieee80211_radar_detected(sc->hw);
}
void ath9k_dfs_process_phyerr(struct ath_softc *sc, void *data,
struct ath_rx_status *rs, u64 mactime)
{
struct ath_radar_data ard;
u16 datalen;
char *vdata_end;
struct pulse_event pe;
struct ath_hw *ah = sc->sc_ah;
struct ath_common *common = ath9k_hw_common(ah);
DFS_STAT_INC(sc, pulses_total);
if ((rs->rs_phyerr != ATH9K_PHYERR_RADAR) &&
(rs->rs_phyerr != ATH9K_PHYERR_FALSE_RADAR_EXT)) {
ath_dbg(common, DFS,
"Error: rs_phyer=0x%x not a radar error\n",
rs->rs_phyerr);
DFS_STAT_INC(sc, pulses_no_dfs);
return;
}
datalen = rs->rs_datalen;
if (datalen == 0) {
DFS_STAT_INC(sc, datalen_discards);
return;
}
ard.rssi = rs->rs_rssi_ctl[0];
ard.ext_rssi = rs->rs_rssi_ext[0];
if (ard.rssi & 0x80)
ard.rssi = 0;
if (ard.ext_rssi & 0x80)
ard.ext_rssi = 0;
vdata_end = (char *)data + datalen;
ard.pulse_bw_info = vdata_end[-1];
ard.pulse_length_ext = vdata_end[-2];
ard.pulse_length_pri = vdata_end[-3];
pe.freq = ah->curchan->channel;
pe.ts = mactime;
if (!ath9k_postprocess_radar_event(sc, &ard, &pe))
return;
if (pe.width > MIN_CHIRP_PULSE_WIDTH &&
pe.width < MAX_CHIRP_PULSE_WIDTH) {
bool is_ctl = !!(ard.pulse_bw_info & PRI_CH_RADAR_FOUND);
bool is_ext = !!(ard.pulse_bw_info & EXT_CH_RADAR_FOUND);
int clen = datalen - 3;
pe.chirp = ath9k_check_chirping(sc, data, clen, is_ctl, is_ext);
} else {
pe.chirp = false;
}
ath_dbg(common, DFS,
"ath9k_dfs_process_phyerr: type=%d, freq=%d, ts=%llu, "
"width=%d, rssi=%d, delta_ts=%llu\n",
ard.pulse_bw_info, pe.freq, pe.ts, pe.width, pe.rssi,
pe.ts - sc->dfs_prev_pulse_ts);
sc->dfs_prev_pulse_ts = pe.ts;
if (ard.pulse_bw_info & PRI_CH_RADAR_FOUND)
ath9k_dfs_process_radar_pulse(sc, &pe);
if (IS_CHAN_HT40(ah->curchan) &&
ard.pulse_bw_info & EXT_CH_RADAR_FOUND) {
pe.freq += IS_CHAN_HT40PLUS(ah->curchan) ? 20 : -20;
ath9k_dfs_process_radar_pulse(sc, &pe);
}
}
