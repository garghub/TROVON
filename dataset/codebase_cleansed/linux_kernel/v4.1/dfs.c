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
ath_dbg(common, DFS,
"ath9k_dfs_process_phyerr: type=%d, freq=%d, ts=%llu, "
"width=%d, rssi=%d, delta_ts=%llu\n",
ard.pulse_bw_info, pe.freq, pe.ts, pe.width, pe.rssi,
pe.ts - sc->dfs_prev_pulse_ts);
sc->dfs_prev_pulse_ts = pe.ts;
if (ard.pulse_bw_info & PRI_CH_RADAR_FOUND)
ath9k_dfs_process_radar_pulse(sc, &pe);
if (ard.pulse_bw_info & EXT_CH_RADAR_FOUND) {
pe.freq += IS_CHAN_HT40PLUS(ah->curchan) ? 20 : -20;
ath9k_dfs_process_radar_pulse(sc, &pe);
}
}
