bool wlc_ps_allowed(struct wlc_info *wlc)
{
int idx;
struct wlc_bsscfg *cfg;
if (!wlc->pub->associated || !wlc->PMenabled || wlc->PM_override)
return false;
if (!wlc->PMblocked) {
if (AP_ACTIVE(wlc) || wlc->monitor)
return false;
}
FOREACH_AS_STA(wlc, idx, cfg) {
if (!cfg->BSS || !WLC_PORTOPEN(cfg))
return false;
if (!cfg->dtim_programmed)
return false;
}
return true;
}
void wlc_reset(struct wlc_info *wlc)
{
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
wlc->check_for_unaligned_tbtt = false;
wlc_statsupd(wlc);
memset((char *)wlc->core->macstat_snapshot, 0,
sizeof(macstat_t));
wlc_bmac_reset(wlc->hw);
wlc->txretried = 0;
}
void wlc_fatal_error(struct wlc_info *wlc)
{
wiphy_err(wlc->wiphy, "wl%d: fatal error, reinitializing\n",
wlc->pub->unit);
wl_init(wlc->wl);
}
static chanspec_t wlc_init_chanspec(struct wlc_info *wlc)
{
chanspec_t chanspec =
1 | WL_CHANSPEC_BW_20 | WL_CHANSPEC_CTL_SB_NONE |
WL_CHANSPEC_BAND_2G;
return chanspec;
}
static void wlc_init_scb(struct wlc_info *wlc, struct scb *scb)
{
int i;
scb->flags = SCB_WMECAP | SCB_HTCAP;
for (i = 0; i < NUMPRIO; i++)
scb->seqnum[i] = 0;
}
void wlc_init(struct wlc_info *wlc)
{
d11regs_t *regs;
chanspec_t chanspec;
int i;
struct wlc_bsscfg *bsscfg;
bool mute = false;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
regs = wlc->regs;
if (wlc->pub->associated)
chanspec = wlc->home_chanspec;
else
chanspec = wlc_init_chanspec(wlc);
wlc_bmac_init(wlc->hw, chanspec, mute);
wlc->seckeys = wlc_bmac_read_shm(wlc->hw, M_SECRXKEYS_PTR) * 2;
if (wlc->machwcap & MCAP_TKIPMIC)
wlc->tkmickeys =
wlc_bmac_read_shm(wlc->hw, M_TKMICKEYS_PTR) * 2;
wlc_bcn_li_upd(wlc);
wlc->bcn_wait_prd =
(u8) (wlc_bmac_read_shm(wlc->hw, M_NOSLPZNATDTIM) >> 10);
wlc_reprate_init(wlc);
FOREACH_BSS(wlc, i, bsscfg) {
wlc_set_mac(bsscfg);
wlc_set_bssid(bsscfg);
}
if (wlc->pub->associated) {
FOREACH_BSS(wlc, i, bsscfg) {
if (bsscfg->up) {
u32 bi;
bi = bsscfg->current_bss->beacon_period << 10;
W_REG(&regs->tsf_cfprep,
(bi << CFPREP_CBI_SHIFT));
wlc_set_ps_ctrl(wlc);
break;
}
}
}
wlc_key_hw_init_all(wlc);
wlc_bandinit_ordered(wlc, chanspec);
wlc_init_scb(wlc, &global_scb);
wlc_write_shm(wlc, M_PRS_MAXTIME, wlc->prb_resp_timeout);
wlc_write_shm(wlc, M_MBURST_TXOP,
(wlc->
_rifs ? (EDCF_AC_VO_TXOP_AP << 5) : MAXFRAMEBURST_TXOP));
wlc_duty_cycle_set(wlc, wlc->tx_duty_cycle_ofdm, true, true);
wlc_duty_cycle_set(wlc, wlc->tx_duty_cycle_cck, false, true);
wlc_ampdu_shm_upd(wlc->ampdu);
wlc_bsinit(wlc);
if (EDCF_ENAB(wlc->pub)) {
OR_REG(&regs->ifs_ctl, IFS_USEEDCF);
wlc_edcf_setparams(wlc, false);
}
wlc_tx_prec_map_init(wlc);
if (wlc->ucode_rev == 0) {
wlc->ucode_rev =
wlc_read_shm(wlc, M_BOM_REV_MAJOR) << NBITS(u16);
wlc->ucode_rev |= wlc_read_shm(wlc, M_BOM_REV_MINOR);
}
wlc_enable_mac(wlc);
wlc_txflowcontrol_reset(wlc);
wlc->tx_suspended = false;
W_REG(&wlc->regs->rfdisabledly, RFDISABLE_DEFAULT);
wlc->mpc_delay_off = wlc->mpc_dlycnt = WLC_MPC_MIN_DELAYCNT;
if (WLC_WME_RETRY_SHORT_GET(wlc, 0) == 0) {
int ac;
for (ac = 0; ac < AC_COUNT; ac++) {
wlc->wme_retries[ac] =
wlc_read_shm(wlc, M_AC_TXLMT_ADDR(ac));
}
}
}
void wlc_mac_bcn_promisc_change(struct wlc_info *wlc, bool promisc)
{
wlc->bcnmisc_monitor = promisc;
wlc_mac_bcn_promisc(wlc);
}
void wlc_mac_bcn_promisc(struct wlc_info *wlc)
{
if ((AP_ENAB(wlc->pub) && (N_ENAB(wlc->pub) || wlc->band->gmode)) ||
wlc->bcnmisc_ibss || wlc->bcnmisc_scan || wlc->bcnmisc_monitor)
wlc_mctrl(wlc, MCTL_BCNS_PROMISC, MCTL_BCNS_PROMISC);
else
wlc_mctrl(wlc, MCTL_BCNS_PROMISC, 0);
}
void wlc_mac_promisc(struct wlc_info *wlc)
{
u32 promisc_bits = 0;
if (PROMISC_ENAB(wlc->pub) && !AP_ENAB(wlc->pub) && !wlc->wet)
promisc_bits |= MCTL_PROMISC;
if (MONITOR_ENAB(wlc))
promisc_bits |= MCTL_PROMISC | MCTL_KEEPCONTROL;
wlc_mctrl(wlc, MCTL_PROMISC | MCTL_KEEPCONTROL, promisc_bits);
}
void wlc_set_ps_ctrl(struct wlc_info *wlc)
{
u32 v1, v2;
bool hps;
bool awake_before;
hps = PS_ALLOWED(wlc);
BCMMSG(wlc->wiphy, "wl%d: hps %d\n", wlc->pub->unit, hps);
v1 = R_REG(&wlc->regs->maccontrol);
v2 = MCTL_WAKE;
if (hps)
v2 |= MCTL_HPS;
wlc_mctrl(wlc, MCTL_WAKE | MCTL_HPS, v2);
awake_before = ((v1 & MCTL_WAKE) || ((v1 & MCTL_HPS) == 0));
if (!awake_before)
wlc_bmac_wait_for_wake(wlc->hw);
}
int wlc_set_mac(struct wlc_bsscfg *cfg)
{
int err = 0;
struct wlc_info *wlc = cfg->wlc;
if (cfg == wlc->cfg) {
wlc_set_addrmatch(wlc, RCM_MAC_OFFSET, cfg->cur_etheraddr);
}
wlc_ampdu_macaddr_upd(wlc);
return err;
}
void wlc_set_bssid(struct wlc_bsscfg *cfg)
{
struct wlc_info *wlc = cfg->wlc;
if (cfg == wlc->cfg) {
wlc_set_addrmatch(wlc, RCM_BSSID_OFFSET, cfg->BSSID);
}
#ifdef SUPPORT_HWKEYS
else if (BSSCFG_STA(cfg) && cfg->BSS) {
wlc_rcmta_add_bssid(wlc, cfg);
}
#endif
}
void wlc_switch_shortslot(struct wlc_info *wlc, bool shortslot)
{
int idx;
struct wlc_bsscfg *cfg;
if (wlc->shortslot_override != WLC_SHORTSLOT_AUTO)
shortslot = (wlc->shortslot_override == WLC_SHORTSLOT_ON);
if (wlc->shortslot == shortslot)
return;
wlc->shortslot = shortslot;
FOREACH_BSS(wlc, idx, cfg) {
if (!cfg->associated)
continue;
cfg->current_bss->capability &=
~WLAN_CAPABILITY_SHORT_SLOT_TIME;
if (wlc->shortslot)
cfg->current_bss->capability |=
WLAN_CAPABILITY_SHORT_SLOT_TIME;
}
wlc_bmac_set_shortslot(wlc->hw, shortslot);
}
static u8 wlc_local_constraint_qdbm(struct wlc_info *wlc)
{
u8 local;
s16 local_max;
local = WLC_TXPWR_MAX;
if (wlc->pub->associated &&
(bcm_chspec_ctlchan(wlc->chanspec) ==
bcm_chspec_ctlchan(wlc->home_chanspec))) {
local_max =
(wlc->txpwr_local_max -
wlc->txpwr_local_constraint) * WLC_TXPWR_DB_FACTOR;
if (local_max > 0 && local_max < WLC_TXPWR_MAX)
return (u8) local_max;
if (local_max < 0)
return 0;
}
return local;
}
void wlc_set_home_chanspec(struct wlc_info *wlc, chanspec_t chanspec)
{
if (wlc->home_chanspec != chanspec) {
int idx;
struct wlc_bsscfg *cfg;
wlc->home_chanspec = chanspec;
FOREACH_BSS(wlc, idx, cfg) {
if (!cfg->associated)
continue;
cfg->current_bss->chanspec = chanspec;
}
}
}
static void wlc_set_phy_chanspec(struct wlc_info *wlc, chanspec_t chanspec)
{
wlc->chanspec = chanspec;
wlc_channel_set_chanspec(wlc->cmi, chanspec,
wlc_local_constraint_qdbm(wlc));
if (wlc->stf->ss_algosel_auto)
wlc_stf_ss_algo_channel_get(wlc, &wlc->stf->ss_algo_channel,
chanspec);
wlc_stf_ss_update(wlc, wlc->band);
}
void wlc_set_chanspec(struct wlc_info *wlc, chanspec_t chanspec)
{
uint bandunit;
bool switchband = false;
chanspec_t old_chanspec = wlc->chanspec;
if (!wlc_valid_chanspec_db(wlc->cmi, chanspec)) {
wiphy_err(wlc->wiphy, "wl%d: %s: Bad channel %d\n",
wlc->pub->unit, __func__, CHSPEC_CHANNEL(chanspec));
return;
}
if (NBANDS(wlc) > 1) {
bandunit = CHSPEC_WLCBANDUNIT(chanspec);
if (wlc->band->bandunit != bandunit || wlc->bandinit_pending) {
switchband = true;
if (wlc->bandlocked) {
wiphy_err(wlc->wiphy, "wl%d: %s: chspec %d "
"band is locked!\n",
wlc->pub->unit, __func__,
CHSPEC_CHANNEL(chanspec));
return;
}
wlc_setband(wlc, bandunit);
}
}
wlc_set_phy_chanspec(wlc, chanspec);
if (CHSPEC_WLC_BW(old_chanspec) != CHSPEC_WLC_BW(chanspec)) {
wlc_antsel_init(wlc->asi);
wlc_rateset_bw_mcs_filter(&wlc->band->hw_rateset,
wlc->band->
mimo_cap_40 ? CHSPEC_WLC_BW(chanspec)
: 0);
}
wlc_ucode_mac_upd(wlc);
}
static int wlc_get_current_txpwr(struct wlc_info *wlc, void *pwr, uint len)
{
txpwr_limits_t txpwr;
tx_power_t power;
tx_power_legacy_t *old_power = NULL;
int r, c;
uint qdbm;
bool override;
if (len == sizeof(tx_power_legacy_t))
old_power = (tx_power_legacy_t *) pwr;
else if (len < sizeof(tx_power_t))
return -EOVERFLOW;
memset(&power, 0, sizeof(tx_power_t));
power.chanspec = WLC_BAND_PI_RADIO_CHANSPEC;
if (wlc->pub->associated)
power.local_chanspec = wlc->home_chanspec;
wlc_phy_txpower_get(wlc->band->pi, &qdbm, &override);
for (r = 0; r < WL_TX_POWER_RATES; r++) {
power.user_limit[r] = (u8) qdbm;
}
power.local_max = wlc->txpwr_local_max * WLC_TXPWR_DB_FACTOR;
power.local_constraint =
wlc->txpwr_local_constraint * WLC_TXPWR_DB_FACTOR;
power.antgain[0] = wlc->bandstate[BAND_2G_INDEX]->antgain;
power.antgain[1] = wlc->bandstate[BAND_5G_INDEX]->antgain;
wlc_channel_reg_limits(wlc->cmi, power.chanspec, &txpwr);
#if WL_TX_POWER_CCK_NUM != WLC_NUM_RATES_CCK
#error "WL_TX_POWER_CCK_NUM != WLC_NUM_RATES_CCK"
#endif
for (c = 0, r = WL_TX_POWER_CCK_FIRST; c < WL_TX_POWER_CCK_NUM;
c++, r++)
power.reg_limit[r] = txpwr.cck[c];
#if WL_TX_POWER_OFDM_NUM != WLC_NUM_RATES_OFDM
#error "WL_TX_POWER_OFDM_NUM != WLC_NUM_RATES_OFDM"
#endif
for (c = 0, r = WL_TX_POWER_OFDM_FIRST; c < WL_TX_POWER_OFDM_NUM;
c++, r++)
power.reg_limit[r] = txpwr.ofdm[c];
if (WLC_PHY_11N_CAP(wlc->band)) {
for (c = 0, r = WL_TX_POWER_OFDM20_CDD_FIRST;
c < WL_TX_POWER_OFDM_NUM; c++, r++)
power.reg_limit[r] = txpwr.ofdm_cdd[c];
for (c = 0, r = WL_TX_POWER_OFDM40_SISO_FIRST;
c < WL_TX_POWER_OFDM_NUM; c++, r++)
power.reg_limit[r] = txpwr.ofdm_40_siso[c];
for (c = 0, r = WL_TX_POWER_OFDM40_CDD_FIRST;
c < WL_TX_POWER_OFDM_NUM; c++, r++)
power.reg_limit[r] = txpwr.ofdm_40_cdd[c];
#if WL_TX_POWER_MCS_1_STREAM_NUM != WLC_NUM_RATES_MCS_1_STREAM
#error "WL_TX_POWER_MCS_1_STREAM_NUM != WLC_NUM_RATES_MCS_1_STREAM"
#endif
for (c = 0, r = WL_TX_POWER_MCS20_SISO_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_20_siso[c];
for (c = 0, r = WL_TX_POWER_MCS20_CDD_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_20_cdd[c];
for (c = 0, r = WL_TX_POWER_MCS20_STBC_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_20_stbc[c];
for (c = 0, r = WL_TX_POWER_MCS40_SISO_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_40_siso[c];
for (c = 0, r = WL_TX_POWER_MCS40_CDD_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_40_cdd[c];
for (c = 0, r = WL_TX_POWER_MCS40_STBC_FIRST;
c < WLC_NUM_RATES_MCS_1_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_40_stbc[c];
#if WL_TX_POWER_MCS_2_STREAM_NUM != WLC_NUM_RATES_MCS_2_STREAM
#error "WL_TX_POWER_MCS_2_STREAM_NUM != WLC_NUM_RATES_MCS_2_STREAM"
#endif
for (c = 0, r = WL_TX_POWER_MCS20_SDM_FIRST;
c < WLC_NUM_RATES_MCS_2_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_20_mimo[c];
for (c = 0, r = WL_TX_POWER_MCS40_SDM_FIRST;
c < WLC_NUM_RATES_MCS_2_STREAM; c++, r++)
power.reg_limit[r] = txpwr.mcs_40_mimo[c];
power.reg_limit[WL_TX_POWER_MCS_32] = txpwr.mcs32;
}
wlc_phy_txpower_get_current(wlc->band->pi, &power,
CHSPEC_CHANNEL(power.chanspec));
if (!old_power) {
memcpy(pwr, &power, sizeof(tx_power_t));
} else {
int band_idx = CHSPEC_IS2G(power.chanspec) ? 0 : 1;
memset(old_power, 0, sizeof(tx_power_legacy_t));
old_power->txpwr_local_max = power.local_max;
old_power->txpwr_local_constraint = power.local_constraint;
if (CHSPEC_IS2G(power.chanspec)) {
old_power->txpwr_chan_reg_max = txpwr.cck[0];
old_power->txpwr_est_Pout[band_idx] =
power.est_Pout_cck;
old_power->txpwr_est_Pout_gofdm = power.est_Pout[0];
} else {
old_power->txpwr_chan_reg_max = txpwr.ofdm[0];
old_power->txpwr_est_Pout[band_idx] = power.est_Pout[0];
}
old_power->txpwr_antgain[0] = power.antgain[0];
old_power->txpwr_antgain[1] = power.antgain[1];
for (r = 0; r < NUM_PWRCTRL_RATES; r++) {
old_power->txpwr_band_max[r] = power.user_limit[r];
old_power->txpwr_limit[r] = power.reg_limit[r];
old_power->txpwr_target[band_idx][r] = power.target[r];
if (CHSPEC_IS2G(power.chanspec))
old_power->txpwr_bphy_cck_max[r] =
power.board_limit[r];
else
old_power->txpwr_aphy_max[r] =
power.board_limit[r];
}
}
return 0;
}
static u32 wlc_watchdog_backup_bi(struct wlc_info *wlc)
{
u32 bi;
bi = 2 * wlc->cfg->current_bss->dtim_period *
wlc->cfg->current_bss->beacon_period;
if (wlc->bcn_li_dtim)
bi *= wlc->bcn_li_dtim;
else if (wlc->bcn_li_bcn)
bi = 2 * wlc->bcn_li_bcn * wlc->cfg->current_bss->beacon_period;
if (bi < 2 * TIMER_INTERVAL_WATCHDOG)
bi = 2 * TIMER_INTERVAL_WATCHDOG;
return bi;
}
void wlc_watchdog_upd(struct wlc_info *wlc, bool tbtt)
{
if (!wlc->pub->up || !wlc->pub->align_wd_tbtt)
return;
if (!tbtt && wlc->WDarmed) {
wl_del_timer(wlc->wl, wlc->wdtimer);
wlc->WDarmed = false;
}
if (tbtt && wlc->WDarmed) {
wl_del_timer(wlc->wl, wlc->wdtimer);
wlc->WDarmed = false;
wlc->WDlast = OSL_SYSUPTIME();
}
else if (!tbtt && !wlc->WDarmed) {
wl_add_timer(wlc->wl, wlc->wdtimer, TIMER_INTERVAL_WATCHDOG,
true);
wlc->WDarmed = true;
}
if (tbtt && !wlc->WDarmed) {
wl_add_timer(wlc->wl, wlc->wdtimer, wlc_watchdog_backup_bi(wlc),
true);
wlc->WDarmed = true;
}
}
ratespec_t wlc_lowest_basic_rspec(struct wlc_info *wlc, wlc_rateset_t *rs)
{
ratespec_t lowest_basic_rspec;
uint i;
lowest_basic_rspec = rs->rates[0] & WLC_RATE_MASK;
for (i = 0; i < rs->count; i++) {
if (rs->rates[i] & WLC_RATE_FLAG) {
lowest_basic_rspec = rs->rates[i] & WLC_RATE_MASK;
break;
}
}
#if NCONF
if (IS_OFDM(lowest_basic_rspec)) {
lowest_basic_rspec |= (wlc->stf->ss_opmode << RSPEC_STF_SHIFT);
}
#endif
return lowest_basic_rspec;
}
void wlc_beacon_phytxctl_txant_upd(struct wlc_info *wlc, ratespec_t bcn_rspec)
{
u16 phyctl;
u16 phytxant = wlc->stf->phytxant;
u16 mask = PHY_TXC_ANT_MASK;
if (WLC_PHY_11N_CAP(wlc->band)) {
phytxant = wlc_stf_phytxchain_sel(wlc, bcn_rspec);
}
phyctl = wlc_read_shm(wlc, M_BCN_PCTLWD);
phyctl = (phyctl & ~mask) | phytxant;
wlc_write_shm(wlc, M_BCN_PCTLWD, phyctl);
}
void wlc_protection_upd(struct wlc_info *wlc, uint idx, int val)
{
BCMMSG(wlc->wiphy, "idx %d, val %d\n", idx, val);
switch (idx) {
case WLC_PROT_G_SPEC:
wlc->protection->_g = (bool) val;
break;
case WLC_PROT_G_OVR:
wlc->protection->g_override = (s8) val;
break;
case WLC_PROT_G_USER:
wlc->protection->gmode_user = (u8) val;
break;
case WLC_PROT_OVERLAP:
wlc->protection->overlap = (s8) val;
break;
case WLC_PROT_N_USER:
wlc->protection->nmode_user = (s8) val;
break;
case WLC_PROT_N_CFG:
wlc->protection->n_cfg = (s8) val;
break;
case WLC_PROT_N_CFG_OVR:
wlc->protection->n_cfg_override = (s8) val;
break;
case WLC_PROT_N_NONGF:
wlc->protection->nongf = (bool) val;
break;
case WLC_PROT_N_NONGF_OVR:
wlc->protection->nongf_override = (s8) val;
break;
case WLC_PROT_N_PAM_OVR:
wlc->protection->n_pam_override = (s8) val;
break;
case WLC_PROT_N_OBSS:
wlc->protection->n_obss = (bool) val;
break;
default:
break;
}
}
static void wlc_ht_update_sgi_rx(struct wlc_info *wlc, int val)
{
wlc->ht_cap.cap_info &= ~(IEEE80211_HT_CAP_SGI_20 |
IEEE80211_HT_CAP_SGI_40);
wlc->ht_cap.cap_info |= (val & WLC_N_SGI_20) ?
IEEE80211_HT_CAP_SGI_20 : 0;
wlc->ht_cap.cap_info |= (val & WLC_N_SGI_40) ?
IEEE80211_HT_CAP_SGI_40 : 0;
if (wlc->pub->up) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, true);
}
}
static void wlc_ht_update_ldpc(struct wlc_info *wlc, s8 val)
{
wlc->stf->ldpc = val;
wlc->ht_cap.cap_info &= ~IEEE80211_HT_CAP_LDPC_CODING;
if (wlc->stf->ldpc != OFF)
wlc->ht_cap.cap_info |= IEEE80211_HT_CAP_LDPC_CODING;
if (wlc->pub->up) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, true);
wlc_phy_ldpc_override_set(wlc->band->pi, (val ? true : false));
}
}
static void wlc_ucode_mac_upd(struct wlc_info *wlc)
{
if (wlc->home_chanspec == WLC_BAND_PI_RADIO_CHANSPEC) {
if (wlc->pub->associated) {
if (WLC_PHY_11N_CAP(wlc->band)) {
wlc_write_shm(wlc, M_BCN_TXTSF_OFFSET,
wlc->band->bcntsfoff);
}
}
} else {
}
wlc_mac_bcn_promisc(wlc);
wlc_mac_promisc(wlc);
}
static void wlc_bandinit_ordered(struct wlc_info *wlc, chanspec_t chanspec)
{
wlc_rateset_t default_rateset;
uint parkband;
uint i, band_order[2];
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
if (wlc->bandlocked || NBANDS(wlc) == 1) {
parkband = wlc->band->bandunit;
band_order[0] = band_order[1] = parkband;
} else {
parkband = CHSPEC_WLCBANDUNIT(chanspec);
band_order[0] = parkband ^ 1;
band_order[1] = parkband;
}
for (i = 0; i < NBANDS(wlc); i++) {
uint j = band_order[i];
wlc->band = wlc->bandstate[j];
wlc_default_rateset(wlc, &default_rateset);
wlc_rateset_filter(&default_rateset, &wlc->band->hw_rateset,
false, WLC_RATES_CCK_OFDM, WLC_RATE_MASK,
(bool) N_ENAB(wlc->pub));
wlc_rate_lookup_init(wlc, &default_rateset);
}
wlc_set_phy_chanspec(wlc, chanspec);
}
static void WLBANDINITFN(wlc_bsinit) (struct wlc_info *wlc)
{
BCMMSG(wlc->wiphy, "wl%d: bandunit %d\n",
wlc->pub->unit, wlc->band->bandunit);
wlc_set_ratetable(wlc);
wlc_ucode_mac_upd(wlc);
wlc_antsel_init(wlc->asi);
}
static void WLBANDINITFN(wlc_setband) (struct wlc_info *wlc, uint bandunit)
{
int idx;
struct wlc_bsscfg *cfg;
wlc->band = wlc->bandstate[bandunit];
if (!wlc->pub->up)
return;
wlc->PMawakebcn = true;
FOREACH_AS_STA(wlc, idx, cfg)
cfg->PMawakebcn = true;
wlc_set_ps_ctrl(wlc);
wlc_bsinit(wlc);
}
void wlc_wme_initparams_sta(struct wlc_info *wlc, wme_param_ie_t *pe)
{
static const wme_param_ie_t stadef = {
WME_OUI,
WME_TYPE,
WME_SUBTYPE_PARAM_IE,
WME_VER,
0,
0,
{
{EDCF_AC_BE_ACI_STA, EDCF_AC_BE_ECW_STA,
cpu_to_le16(EDCF_AC_BE_TXOP_STA)},
{EDCF_AC_BK_ACI_STA, EDCF_AC_BK_ECW_STA,
cpu_to_le16(EDCF_AC_BK_TXOP_STA)},
{EDCF_AC_VI_ACI_STA, EDCF_AC_VI_ECW_STA,
cpu_to_le16(EDCF_AC_VI_TXOP_STA)},
{EDCF_AC_VO_ACI_STA, EDCF_AC_VO_ECW_STA,
cpu_to_le16(EDCF_AC_VO_TXOP_STA)}
}
};
memcpy(pe, &stadef, sizeof(*pe));
}
void wlc_wme_setparams(struct wlc_info *wlc, u16 aci,
const struct ieee80211_tx_queue_params *params,
bool suspend)
{
int i;
shm_acparams_t acp_shm;
u16 *shm_entry;
if (!wlc->clk) {
wiphy_err(wlc->wiphy, "wl%d: %s : no-clock\n", wlc->pub->unit,
__func__);
return;
}
wlc->wme_admctl = 0;
do {
memset((char *)&acp_shm, 0, sizeof(shm_acparams_t));
acp_shm.txop = le16_to_cpu(params->txop);
wlc->edcf_txop[aci & 0x3] = acp_shm.txop =
EDCF_TXOP2USEC(acp_shm.txop);
acp_shm.aifs = (params->aifs & EDCF_AIFSN_MASK);
if (aci == AC_VI && acp_shm.txop == 0
&& acp_shm.aifs < EDCF_AIFSN_MAX)
acp_shm.aifs++;
if (acp_shm.aifs < EDCF_AIFSN_MIN
|| acp_shm.aifs > EDCF_AIFSN_MAX) {
wiphy_err(wlc->wiphy, "wl%d: wlc_edcf_setparams: bad "
"aifs %d\n", wlc->pub->unit, acp_shm.aifs);
continue;
}
acp_shm.cwmin = params->cw_min;
acp_shm.cwmax = params->cw_max;
acp_shm.cwcur = acp_shm.cwmin;
acp_shm.bslots =
R_REG(&wlc->regs->tsf_random) & acp_shm.cwcur;
acp_shm.reggap = acp_shm.bslots + acp_shm.aifs;
acp_shm.status = wlc_read_shm(wlc, (M_EDCF_QINFO +
wme_shmemacindex(aci) *
M_EDCF_QLEN +
M_EDCF_STATUS_OFF));
acp_shm.status |= WME_STATUS_NEWAC;
shm_entry = (u16 *) &acp_shm;
for (i = 0; i < (int)sizeof(shm_acparams_t); i += 2)
wlc_write_shm(wlc,
M_EDCF_QINFO +
wme_shmemacindex(aci) * M_EDCF_QLEN + i,
*shm_entry++);
} while (0);
if (suspend)
wlc_suspend_mac_and_wait(wlc);
if (suspend)
wlc_enable_mac(wlc);
}
void wlc_edcf_setparams(struct wlc_info *wlc, bool suspend)
{
u16 aci;
int i_ac;
edcf_acparam_t *edcf_acp;
struct ieee80211_tx_queue_params txq_pars;
struct ieee80211_tx_queue_params *params = &txq_pars;
edcf_acp = (edcf_acparam_t *) &wlc->wme_param_ie.acparam[0];
for (i_ac = 0; i_ac < AC_COUNT; i_ac++, edcf_acp++) {
aci = (edcf_acp->ACI & EDCF_ACI_MASK) >> EDCF_ACI_SHIFT;
if (edcf_acp->ACI & EDCF_ACM_MASK) {
wlc->wme_admctl |= 1 << aci;
}
params->txop = edcf_acp->TXOP;
params->aifs = edcf_acp->ACI;
params->cw_min = EDCF_ECW2CW(edcf_acp->ECW & EDCF_ECWMIN_MASK);
params->cw_max = EDCF_ECW2CW((edcf_acp->ECW & EDCF_ECWMAX_MASK)
>> EDCF_ECWMAX_SHIFT);
wlc_wme_setparams(wlc, aci, params, suspend);
}
if (suspend)
wlc_suspend_mac_and_wait(wlc);
if (AP_ENAB(wlc->pub) && WME_ENAB(wlc->pub)) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, false);
}
if (suspend)
wlc_enable_mac(wlc);
}
bool wlc_timers_init(struct wlc_info *wlc, int unit)
{
wlc->wdtimer = wl_init_timer(wlc->wl, wlc_watchdog_by_timer,
wlc, "watchdog");
if (!wlc->wdtimer) {
wiphy_err(wlc->wiphy, "wl%d: wl_init_timer for wdtimer "
"failed\n", unit);
goto fail;
}
wlc->radio_timer = wl_init_timer(wlc->wl, wlc_radio_timer,
wlc, "radio");
if (!wlc->radio_timer) {
wiphy_err(wlc->wiphy, "wl%d: wl_init_timer for radio_timer "
"failed\n", unit);
goto fail;
}
return true;
fail:
return false;
}
void wlc_info_init(struct wlc_info *wlc, int unit)
{
int i;
wlc->device_present = true;
wlc->txpwr_percent = 100;
wlc->chanspec = CH20MHZ_CHSPEC(1);
wlc->shortpreamble = false;
wlc->legacy_probe = true;
wlc->shortslot = false;
wlc->shortslot_override = WLC_SHORTSLOT_AUTO;
wlc->barker_overlap_control = true;
wlc->barker_preamble = WLC_BARKER_SHORT_ALLOWED;
wlc->txburst_limit_override = AUTO;
wlc_protection_upd(wlc, WLC_PROT_G_OVR, WLC_PROTECTION_AUTO);
wlc_protection_upd(wlc, WLC_PROT_G_SPEC, false);
wlc_protection_upd(wlc, WLC_PROT_N_CFG_OVR, WLC_PROTECTION_AUTO);
wlc_protection_upd(wlc, WLC_PROT_N_CFG, WLC_N_PROTECTION_OFF);
wlc_protection_upd(wlc, WLC_PROT_N_NONGF_OVR, WLC_PROTECTION_AUTO);
wlc_protection_upd(wlc, WLC_PROT_N_NONGF, false);
wlc_protection_upd(wlc, WLC_PROT_N_PAM_OVR, AUTO);
wlc_protection_upd(wlc, WLC_PROT_OVERLAP, WLC_PROTECTION_CTL_OVERLAP);
wlc->include_legacy_erp = true;
wlc->stf->ant_rx_ovr = ANT_RX_DIV_DEF;
wlc->stf->txant = ANT_TX_DEF;
wlc->prb_resp_timeout = WLC_PRB_RESP_TIMEOUT;
wlc->usr_fragthresh = DOT11_DEFAULT_FRAG_LEN;
for (i = 0; i < NFIFO; i++)
wlc->fragthresh[i] = DOT11_DEFAULT_FRAG_LEN;
wlc->RTSThresh = DOT11_DEFAULT_RTS_LEN;
wlc->SFBL = RETRY_SHORT_FB;
wlc->LFBL = RETRY_LONG_FB;
wlc->SRL = RETRY_SHORT_DEF;
wlc->LRL = RETRY_LONG_DEF;
wlc->PM = PM_OFF;
wlc->PM_override = false;
wlc->PMenabled = false;
wlc->PMpending = false;
wlc->PMblocked = false;
wlc->WME_PM_blocked = false;
wlc->wme_prec_queuing = false;
wlc->wake = false;
wlc->PSpoll = false;
wlc->wme_apsd = true;
wlc->apsd_sta_usp = false;
wlc->apsd_trigger_timeout = 0;
wlc->apsd_trigger_ac = AC_BITMAP_ALL;
wlc->wsec_swkeys = false;
for (i = 0; i < WSEC_MAX_DEFAULT_KEYS; i++) {
wlc->wsec_keys[i] = wlc->wsec_def_keys[i];
wlc->wsec_keys[i]->idx = (u8) i;
}
wlc->_regulatory_domain = false;
wlc->pub->_wme = AUTO;
#ifdef BCMSDIODEV_ENABLED
wlc->pub->_priofc = true;
#endif
wlc->pub->_ampdu = AMPDU_AGG_HOST;
wlc->pub->bcmerror = 0;
wlc->ibss_allowed = true;
wlc->ibss_coalesce_allowed = true;
wlc->pub->_coex = ON;
wlc->mpc_delay_off = wlc->mpc_dlycnt = WLC_MPC_MIN_DELAYCNT;
wlc->pr80838_war = true;
}
static bool wlc_state_bmac_sync(struct wlc_info *wlc)
{
wlc_bmac_state_t state_bmac;
if (wlc_bmac_state_get(wlc->hw, &state_bmac) != 0)
return false;
wlc->machwcap = state_bmac.machwcap;
wlc_protection_upd(wlc, WLC_PROT_N_PAM_OVR,
(s8) state_bmac.preamble_ovr);
return true;
}
static uint wlc_attach_module(struct wlc_info *wlc)
{
uint err = 0;
uint unit;
unit = wlc->pub->unit;
wlc->asi = wlc_antsel_attach(wlc);
if (wlc->asi == NULL) {
wiphy_err(wlc->wiphy, "wl%d: wlc_attach: wlc_antsel_attach "
"failed\n", unit);
err = 44;
goto fail;
}
wlc->ampdu = wlc_ampdu_attach(wlc);
if (wlc->ampdu == NULL) {
wiphy_err(wlc->wiphy, "wl%d: wlc_attach: wlc_ampdu_attach "
"failed\n", unit);
err = 50;
goto fail;
}
if ((wlc_stf_attach(wlc) != 0)) {
wiphy_err(wlc->wiphy, "wl%d: wlc_attach: wlc_stf_attach "
"failed\n", unit);
err = 68;
goto fail;
}
fail:
return err;
}
struct wlc_pub *wlc_pub(void *wlc)
{
return ((struct wlc_info *) wlc)->pub;
}
void *wlc_attach(struct wl_info *wl, u16 vendor, u16 device, uint unit,
bool piomode, void *regsva, uint bustype, void *btparam,
uint *perr)
{
struct wlc_info *wlc;
uint err = 0;
uint j;
struct wlc_pub *pub;
uint n_disabled;
wlc = (struct wlc_info *) wlc_attach_malloc(unit, &err, device);
if (wlc == NULL)
goto fail;
wlc->wiphy = wl->wiphy;
pub = wlc->pub;
#if defined(BCMDBG)
wlc_info_dbg = wlc;
#endif
wlc->band = wlc->bandstate[0];
wlc->core = wlc->corestate;
wlc->wl = wl;
pub->unit = unit;
wlc->btparam = btparam;
pub->_piomode = piomode;
wlc->bandinit_pending = false;
wlc->ht_wsec_restriction = WLC_HT_TKIP_RESTRICT;
wlc_info_init(wlc, unit);
wlc_ap_upd(wlc);
n_disabled = getintvar(pub->vars, "11n_disable");
wlc_module_register(wlc->pub, wlc_iovars, "wlc_iovars", wlc,
wlc_doiovar, NULL, NULL);
err = wlc_bmac_attach(wlc, vendor, device, unit, piomode, regsva,
bustype, btparam);
if (err)
goto fail;
if (!wlc_state_bmac_sync(wlc)) {
err = 20;
goto fail;
}
pub->phy_11ncapable = WLC_PHY_11N_CAP(wlc->band);
wlc_bmac_copyfrom_vars(wlc->hw, &pub->vars, &wlc->vars_size);
wlc->tx_duty_cycle_ofdm =
(u16) getintvar(pub->vars, "tx_duty_cycle_ofdm");
wlc->tx_duty_cycle_cck =
(u16) getintvar(pub->vars, "tx_duty_cycle_cck");
wlc_stf_phy_chain_calc(wlc);
if (WLCISNPHY(wlc->band) && (wlc->stf->txstreams == 1))
wlc->stf->txant = wlc->stf->hw_txchain - 1;
wlc_phy_stf_chain_init(wlc->band->pi, wlc->stf->hw_txchain,
wlc->stf->hw_rxchain);
{
int i;
for (i = 0; i < NFIFO; i++)
wlc->core->txavail[i] = wlc->hw->txavail[i];
}
wlc_bmac_hw_etheraddr(wlc->hw, wlc->perm_etheraddr);
memcpy(&pub->cur_etheraddr, &wlc->perm_etheraddr, ETH_ALEN);
for (j = 0; j < NBANDS(wlc); j++) {
if (IS_SINGLEBAND_5G(wlc->deviceid))
j = BAND_5G_INDEX;
wlc->band = wlc->bandstate[j];
if (!wlc_attach_stf_ant_init(wlc)) {
err = 24;
goto fail;
}
wlc->band->CWmin = APHY_CWMIN;
wlc->band->CWmax = PHY_CWMAX;
if (BAND_2G(wlc->band->bandtype)) {
wlc->band->gmode = GMODE_AUTO;
wlc_protection_upd(wlc, WLC_PROT_G_USER,
wlc->band->gmode);
}
if (WLC_PHY_11N_CAP(wlc->band) && CHIP_SUPPORTS_11N(wlc)) {
if (n_disabled & WLFEATURE_DISABLE_11N) {
pub->_n_enab = OFF;
wlc_protection_upd(wlc, WLC_PROT_N_USER, OFF);
} else {
pub->_n_enab = SUPPORT_11N;
wlc_protection_upd(wlc, WLC_PROT_N_USER,
((pub->_n_enab ==
SUPPORT_11N) ? WL_11N_2x2 :
WL_11N_3x3));
}
}
wlc_default_rateset(wlc, &wlc->band->defrateset);
wlc_rateset_filter(&wlc->band->defrateset,
&wlc->band->hw_rateset, false,
WLC_RATES_CCK_OFDM, WLC_RATE_MASK,
(bool) N_ENAB(wlc->pub));
}
wlc_stf_phy_txant_upd(wlc);
err = wlc_attach_module(wlc);
if (err != 0)
goto fail;
if (!wlc_timers_init(wlc, unit)) {
wiphy_err(wl->wiphy, "wl%d: %s: wlc_init_timer failed\n", unit,
__func__);
err = 32;
goto fail;
}
wlc->cmi = wlc_channel_mgr_attach(wlc);
if (!wlc->cmi) {
wiphy_err(wl->wiphy, "wl%d: %s: wlc_channel_mgr_attach failed"
"\n", unit, __func__);
err = 33;
goto fail;
}
wlc_bss_default_init(wlc);
wlc->pkt_queue = wlc_txq_alloc(wlc);
if (wlc->pkt_queue == NULL) {
wiphy_err(wl->wiphy, "wl%d: %s: failed to malloc tx queue\n",
unit, __func__);
err = 100;
goto fail;
}
wlc->bsscfg[0] = wlc->cfg;
wlc->cfg->_idx = 0;
wlc->cfg->wlc = wlc;
pub->txmaxpkts = MAXTXPKTS;
wlc_wme_initparams_sta(wlc, &wlc->wme_param_ie);
wlc->mimoft = FT_HT;
wlc->ht_cap.cap_info = HT_CAP;
if (HT_ENAB(wlc->pub))
wlc->stf->ldpc = AUTO;
wlc->mimo_40txbw = AUTO;
wlc->ofdm_40txbw = AUTO;
wlc->cck_40txbw = AUTO;
wlc_update_mimo_band_bwcap(wlc, WLC_N_BW_20IN2G_40IN5G);
wlc->rifs_advert = AUTO;
if (WLC_SGI_CAP_PHY(wlc)) {
wlc_ht_update_sgi_rx(wlc, (WLC_N_SGI_20 | WLC_N_SGI_40));
wlc->sgi_tx = AUTO;
} else if (WLCISSSLPNPHY(wlc->band)) {
wlc_ht_update_sgi_rx(wlc, (WLC_N_SGI_20 | WLC_N_SGI_40));
wlc->sgi_tx = AUTO;
} else {
wlc_ht_update_sgi_rx(wlc, 0);
wlc->sgi_tx = OFF;
}
if (n_disabled & WLFEATURE_DISABLE_11N_SGI_TX)
wlc->sgi_tx = OFF;
if (n_disabled & WLFEATURE_DISABLE_11N_SGI_RX)
wlc_ht_update_sgi_rx(wlc, 0);
if (n_disabled & WLFEATURE_DISABLE_11N_STBC_TX) {
wlc->bandstate[BAND_2G_INDEX]->band_stf_stbc_tx = OFF;
wlc->bandstate[BAND_5G_INDEX]->band_stf_stbc_tx = OFF;
wlc->ht_cap.cap_info &= ~IEEE80211_HT_CAP_TX_STBC;
}
if (n_disabled & WLFEATURE_DISABLE_11N_STBC_RX)
wlc_stf_stbc_rx_set(wlc, HT_CAP_RX_STBC_NO);
if (n_disabled & WLFEATURE_DISABLE_11N_GF)
wlc->ht_cap.cap_info &= ~IEEE80211_HT_CAP_GRN_FLD;
wlc_radio_mpc_upd(wlc);
if ((wlc->pub->sih->chip) == BCM43235_CHIP_ID) {
if ((getintvar(wlc->pub->vars, "aa2g") == 7) ||
(getintvar(wlc->pub->vars, "aa5g") == 7)) {
wlc_bmac_antsel_set(wlc->hw, 1);
}
} else {
wlc_bmac_antsel_set(wlc->hw, wlc->asi->antsel_avail);
}
if (perr)
*perr = 0;
return (void *)wlc;
fail:
wiphy_err(wl->wiphy, "wl%d: %s: failed with err %d\n",
unit, __func__, err);
if (wlc)
wlc_detach(wlc);
if (perr)
*perr = err;
return NULL;
}
static void wlc_attach_antgain_init(struct wlc_info *wlc)
{
uint unit;
unit = wlc->pub->unit;
if ((wlc->band->antgain == -1) && (wlc->pub->sromrev == 1)) {
wlc->band->antgain = 8;
} else if (wlc->band->antgain == -1) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid antennas available in"
" srom, using 2dB\n", unit, __func__);
wlc->band->antgain = 8;
} else {
s8 gain, fract;
gain = wlc->band->antgain & 0x3f;
gain <<= 2;
gain >>= 2;
fract = (wlc->band->antgain & 0xc0) >> 6;
wlc->band->antgain = 4 * gain + fract;
}
}
static bool wlc_attach_stf_ant_init(struct wlc_info *wlc)
{
int aa;
uint unit;
char *vars;
int bandtype;
unit = wlc->pub->unit;
vars = wlc->pub->vars;
bandtype = wlc->band->bandtype;
aa = (s8) getintvar(vars, (BAND_5G(bandtype) ? "aa5g" : "aa2g"));
if (aa == 0)
aa = (s8) getintvar(vars,
(BAND_5G(bandtype) ? "aa1" : "aa0"));
if ((aa < 1) || (aa > 15)) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid antennas available in"
" srom (0x%x), using 3\n", unit, __func__, aa);
aa = 3;
}
if (aa == 1) {
wlc->stf->ant_rx_ovr = ANT_RX_DIV_FORCE_0;
wlc->stf->txant = ANT_TX_FORCE_0;
} else if (aa == 2) {
wlc->stf->ant_rx_ovr = ANT_RX_DIV_FORCE_1;
wlc->stf->txant = ANT_TX_FORCE_1;
} else {
}
wlc->band->antgain =
(s8) getintvar(vars, (BAND_5G(bandtype) ? "ag1" : "ag0"));
wlc_attach_antgain_init(wlc);
return true;
}
static void wlc_timers_deinit(struct wlc_info *wlc)
{
if (wlc->wdtimer) {
wl_free_timer(wlc->wl, wlc->wdtimer);
wlc->wdtimer = NULL;
}
if (wlc->radio_timer) {
wl_free_timer(wlc->wl, wlc->radio_timer);
wlc->radio_timer = NULL;
}
}
static void wlc_detach_module(struct wlc_info *wlc)
{
if (wlc->asi) {
wlc_antsel_detach(wlc->asi);
wlc->asi = NULL;
}
if (wlc->ampdu) {
wlc_ampdu_detach(wlc->ampdu);
wlc->ampdu = NULL;
}
wlc_stf_detach(wlc);
}
uint wlc_detach(struct wlc_info *wlc)
{
uint callbacks = 0;
if (wlc == NULL)
return 0;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
callbacks += wlc_bmac_detach(wlc);
if (!wlc_radio_monitor_stop(wlc))
callbacks++;
wlc_channel_mgr_detach(wlc->cmi);
wlc_timers_deinit(wlc);
wlc_detach_module(wlc);
#ifdef BCMDBG
kfree(wlc->country_ie_override);
wlc->country_ie_override = NULL;
#endif
{
struct dumpcb_s *prev, *ptr;
prev = ptr = wlc->dumpcb_head;
while (ptr) {
ptr = prev->next;
kfree(prev);
prev = ptr;
}
wlc->dumpcb_head = NULL;
}
wlc_module_unregister(wlc->pub, "wlc_iovars", wlc);
while (wlc->tx_queues != NULL)
wlc_txq_free(wlc, wlc->tx_queues);
wlc_detach_mfree(wlc);
return callbacks;
}
void wlc_ap_upd(struct wlc_info *wlc)
{
if (AP_ENAB(wlc->pub))
wlc->PLCPHdr_override = WLC_PLCP_AUTO;
else
wlc->PLCPHdr_override = WLC_PLCP_SHORT;
wlc->vlan_mode = AP_ENAB(wlc->pub) ? OFF : AUTO;
wlc->mpc = true;
}
static void wlc_radio_hwdisable_upd(struct wlc_info *wlc)
{
if (wlc->pub->wlfeatureflag & WL_SWFL_NOHWRADIO || wlc->pub->hw_off)
return;
if (wlc_bmac_radio_read_hwdisabled(wlc->hw)) {
mboolset(wlc->pub->radio_disabled, WL_RADIO_HW_DISABLE);
} else {
mboolclr(wlc->pub->radio_disabled, WL_RADIO_HW_DISABLE);
}
}
bool wlc_is_non_delay_mpc(struct wlc_info *wlc)
{
return false;
}
bool wlc_ismpc(struct wlc_info *wlc)
{
return (wlc->mpc_delay_off == 0) && (wlc_is_non_delay_mpc(wlc));
}
void wlc_radio_mpc_upd(struct wlc_info *wlc)
{
bool mpc_radio, radio_state;
if (!wlc->mpc) {
if (!wlc->pub->radio_disabled)
return;
mboolclr(wlc->pub->radio_disabled, WL_RADIO_MPC_DISABLE);
wlc_radio_upd(wlc);
if (!wlc->pub->radio_disabled)
wlc_radio_monitor_stop(wlc);
return;
}
radio_state =
(mboolisset(wlc->pub->radio_disabled, WL_RADIO_MPC_DISABLE) ? OFF :
ON);
mpc_radio = (wlc_ismpc(wlc) == true) ? OFF : ON;
if (radio_state == ON && mpc_radio == OFF)
wlc->mpc_delay_off = wlc->mpc_dlycnt;
else if (radio_state == OFF && mpc_radio == ON) {
mboolclr(wlc->pub->radio_disabled, WL_RADIO_MPC_DISABLE);
wlc_radio_upd(wlc);
if (wlc->mpc_offcnt < WLC_MPC_THRESHOLD) {
wlc->mpc_dlycnt = WLC_MPC_MAX_DELAYCNT;
} else
wlc->mpc_dlycnt = WLC_MPC_MIN_DELAYCNT;
wlc->mpc_dur += OSL_SYSUPTIME() - wlc->mpc_laston_ts;
}
if ((wlc->prev_non_delay_mpc == false) &&
(wlc_is_non_delay_mpc(wlc) == true) && wlc->mpc_delay_off) {
wlc->mpc_delay_off = wlc->mpc_dlycnt;
}
wlc->prev_non_delay_mpc = wlc_is_non_delay_mpc(wlc);
}
static void wlc_radio_upd(struct wlc_info *wlc)
{
if (wlc->pub->radio_disabled) {
wlc_radio_disable(wlc);
} else {
wlc_radio_enable(wlc);
}
}
static void wlc_down_led_upd(struct wlc_info *wlc)
{
if (!AP_ENAB(wlc->pub)) {
wlc_pllreq(wlc, true, WLC_PLLREQ_FLIP);
wlc_pllreq(wlc, false, WLC_PLLREQ_FLIP);
}
}
bool wlc_check_radio_disabled(struct wlc_info *wlc)
{
wlc_radio_hwdisable_upd(wlc);
return mboolisset(wlc->pub->radio_disabled, WL_RADIO_HW_DISABLE) ? true : false;
}
void wlc_radio_disable(struct wlc_info *wlc)
{
if (!wlc->pub->up) {
wlc_down_led_upd(wlc);
return;
}
wlc_radio_monitor_start(wlc);
wl_down(wlc->wl);
}
static void wlc_radio_enable(struct wlc_info *wlc)
{
if (wlc->pub->up)
return;
if (DEVICEREMOVED(wlc))
return;
if (!wlc->down_override) {
wl_up(wlc->wl);
}
}
static void wlc_radio_timer(void *arg)
{
struct wlc_info *wlc = (struct wlc_info *) arg;
if (DEVICEREMOVED(wlc)) {
wiphy_err(wlc->wiphy, "wl%d: %s: dead chip\n", wlc->pub->unit,
__func__);
wl_down(wlc->wl);
return;
}
if (wlc->mpc_offcnt < WLC_MPC_MAX_DELAYCNT)
wlc->mpc_offcnt++;
wlc_radio_hwdisable_upd(wlc);
wlc_radio_upd(wlc);
}
static bool wlc_radio_monitor_start(struct wlc_info *wlc)
{
if (wlc->radio_monitor || (wlc->pub->wlfeatureflag & WL_SWFL_NOHWRADIO))
return true;
wlc->radio_monitor = true;
wlc_pllreq(wlc, true, WLC_PLLREQ_RADIO_MON);
wl_add_timer(wlc->wl, wlc->radio_timer, TIMER_INTERVAL_RADIOCHK, true);
return true;
}
bool wlc_radio_monitor_stop(struct wlc_info *wlc)
{
if (!wlc->radio_monitor)
return true;
wlc->radio_monitor = false;
wlc_pllreq(wlc, false, WLC_PLLREQ_RADIO_MON);
return wl_del_timer(wlc->wl, wlc->radio_timer);
}
static void wlc_watchdog_by_timer(void *arg)
{
struct wlc_info *wlc = (struct wlc_info *) arg;
wlc_watchdog(arg);
if (WLC_WATCHDOG_TBTT(wlc)) {
wl_del_timer(wlc->wl, wlc->wdtimer);
wl_add_timer(wlc->wl, wlc->wdtimer, TIMER_INTERVAL_WATCHDOG,
true);
}
}
static void wlc_watchdog(void *arg)
{
struct wlc_info *wlc = (struct wlc_info *) arg;
int i;
struct wlc_bsscfg *cfg;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
if (!wlc->pub->up)
return;
if (DEVICEREMOVED(wlc)) {
wiphy_err(wlc->wiphy, "wl%d: %s: dead chip\n", wlc->pub->unit,
__func__);
wl_down(wlc->wl);
return;
}
wlc->pub->now++;
if (wlc->mpc_delay_off) {
if (--wlc->mpc_delay_off == 0) {
mboolset(wlc->pub->radio_disabled,
WL_RADIO_MPC_DISABLE);
if (wlc->mpc && wlc_ismpc(wlc))
wlc->mpc_offcnt = 0;
wlc->mpc_laston_ts = OSL_SYSUPTIME();
}
}
wlc_radio_mpc_upd(wlc);
wlc_radio_hwdisable_upd(wlc);
wlc_radio_upd(wlc);
if (wlc->pub->radio_disabled)
return;
wlc_bmac_watchdog(wlc);
if ((wlc->pub->now % SW_TIMER_MAC_STAT_UPD) == 0)
wlc_statsupd(wlc);
FOREACH_BSS(wlc, i, cfg) {
if (cfg->tk_cm_dt) {
cfg->tk_cm_dt--;
}
if (cfg->tk_cm_bt) {
cfg->tk_cm_bt--;
}
}
for (i = 0; i < WLC_MAXMODULES; i++) {
if (wlc->modulecb[i].watchdog_fn)
wlc->modulecb[i].watchdog_fn(wlc->modulecb[i].hdl);
}
if (WLCISNPHY(wlc->band) && !wlc->pub->tempsense_disable &&
((wlc->pub->now - wlc->tempsense_lasttime) >=
WLC_TEMPSENSE_PERIOD)) {
wlc->tempsense_lasttime = wlc->pub->now;
wlc_tempsense_upd(wlc);
}
}
int wlc_up(struct wlc_info *wlc)
{
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
if (wlc->pub->hw_off || DEVICEREMOVED(wlc))
return -ENOMEDIUM;
if (!wlc->pub->hw_up) {
wlc_bmac_hw_up(wlc->hw);
wlc->pub->hw_up = true;
}
if ((wlc->pub->boardflags & BFL_FEM)
&& (wlc->pub->sih->chip == BCM4313_CHIP_ID)) {
if (wlc->pub->boardrev >= 0x1250
&& (wlc->pub->boardflags & BFL_FEM_BT)) {
wlc_mhf(wlc, MHF5, MHF5_4313_GPIOCTRL,
MHF5_4313_GPIOCTRL, WLC_BAND_ALL);
} else {
wlc_mhf(wlc, MHF4, MHF4_EXTPA_ENABLE, MHF4_EXTPA_ENABLE,
WLC_BAND_ALL);
}
}
if (!wlc->pub->radio_disabled) {
int status = wlc_bmac_up_prep(wlc->hw);
if (status == -ENOMEDIUM) {
if (!mboolisset
(wlc->pub->radio_disabled, WL_RADIO_HW_DISABLE)) {
int idx;
struct wlc_bsscfg *bsscfg;
mboolset(wlc->pub->radio_disabled,
WL_RADIO_HW_DISABLE);
FOREACH_BSS(wlc, idx, bsscfg) {
if (!BSSCFG_STA(bsscfg)
|| !bsscfg->enable || !bsscfg->BSS)
continue;
wiphy_err(wlc->wiphy, "wl%d.%d: wlc_up"
": rfdisable -> "
"wlc_bsscfg_disable()\n",
wlc->pub->unit, idx);
}
}
}
}
if (wlc->pub->radio_disabled) {
wlc_radio_monitor_start(wlc);
return 0;
}
wlc->clk = true;
wlc_radio_monitor_stop(wlc);
if (EDCF_ENAB(wlc->pub)) {
wlc_mhf(wlc, MHF1, MHF1_EDCF, MHF1_EDCF, WLC_BAND_ALL);
} else {
wlc_mhf(wlc, MHF1, MHF1_EDCF, 0, WLC_BAND_ALL);
}
if (WLC_WAR16165(wlc))
wlc_mhf(wlc, MHF2, MHF2_PCISLOWCLKWAR, MHF2_PCISLOWCLKWAR,
WLC_BAND_ALL);
wl_init(wlc->wl);
wlc->pub->up = true;
if (wlc->bandinit_pending) {
wlc_suspend_mac_and_wait(wlc);
wlc_set_chanspec(wlc, wlc->default_bss->chanspec);
wlc->bandinit_pending = false;
wlc_enable_mac(wlc);
}
wlc_bmac_up_finish(wlc->hw);
wlc_wme_retries_write(wlc);
wl_add_timer(wlc->wl, wlc->wdtimer, TIMER_INTERVAL_WATCHDOG, true);
wlc->WDarmed = true;
wlc_stf_phy_txant_upd(wlc);
wlc_ht_update_ldpc(wlc, wlc->stf->ldpc);
return 0;
}
static void wlc_tx_prec_map_init(struct wlc_info *wlc)
{
wlc->tx_prec_map = WLC_PREC_BMP_ALL;
memset(wlc->fifo2prec_map, 0, NFIFO * sizeof(u16));
if (!EDCF_ENAB(wlc->pub)) {
wlc->fifo2prec_map[TX_DATA_FIFO] = WLC_PREC_BMP_ALL;
wlc->fifo2prec_map[TX_CTL_FIFO] = WLC_PREC_BMP_ALL;
} else {
wlc->fifo2prec_map[TX_AC_BK_FIFO] = WLC_PREC_BMP_AC_BK;
wlc->fifo2prec_map[TX_AC_BE_FIFO] = WLC_PREC_BMP_AC_BE;
wlc->fifo2prec_map[TX_AC_VI_FIFO] = WLC_PREC_BMP_AC_VI;
wlc->fifo2prec_map[TX_AC_VO_FIFO] = WLC_PREC_BMP_AC_VO;
}
}
static uint wlc_down_del_timer(struct wlc_info *wlc)
{
uint callbacks = 0;
return callbacks;
}
uint wlc_down(struct wlc_info *wlc)
{
uint callbacks = 0;
int i;
bool dev_gone = false;
struct wlc_txq_info *qi;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
if (wlc->going_down) {
wiphy_err(wlc->wiphy, "wl%d: %s: Driver going down so return"
"\n", wlc->pub->unit, __func__);
return 0;
}
if (!wlc->pub->up)
return callbacks;
wlc->going_down = true;
callbacks += wlc_bmac_down_prep(wlc->hw);
dev_gone = DEVICEREMOVED(wlc);
for (i = 0; i < WLC_MAXMODULES; i++) {
if (wlc->modulecb[i].down_fn)
callbacks +=
wlc->modulecb[i].down_fn(wlc->modulecb[i].hdl);
}
if (wlc->WDarmed) {
if (!wl_del_timer(wlc->wl, wlc->wdtimer))
callbacks++;
wlc->WDarmed = false;
}
callbacks += wlc_down_del_timer(wlc);
wlc->pub->up = false;
wlc_phy_mute_upd(wlc->band->pi, false, PHY_MUTE_ALL);
wlc_txflowcontrol_reset(wlc);
for (qi = wlc->tx_queues; qi != NULL; qi = qi->next) {
bcm_pktq_flush(&qi->q, true, NULL, NULL);
}
callbacks += wlc_bmac_down_finish(wlc->hw);
wlc->clk = false;
wlc->going_down = false;
return callbacks;
}
int wlc_set_gmode(struct wlc_info *wlc, u8 gmode, bool config)
{
int ret = 0;
uint i;
wlc_rateset_t rs;
s8 shortslot = WLC_SHORTSLOT_AUTO;
bool shortslot_restrict = false;
bool ignore_bcns = true;
bool ofdm_basic = false;
int preamble = WLC_PLCP_LONG;
bool preamble_restrict = false;
struct wlcband *band;
if (N_ENAB(wlc->pub) && gmode == GMODE_LEGACY_B)
return -ENOTSUPP;
if (wlc->band->bandtype == WLC_BAND_2G)
band = wlc->band;
else if ((NBANDS(wlc) > 1) &&
(wlc->bandstate[OTHERBANDUNIT(wlc)]->bandtype == WLC_BAND_2G))
band = wlc->bandstate[OTHERBANDUNIT(wlc)];
else
return -EINVAL;
if ((wlc_channel_locale_flags_in_band(wlc->cmi, band->bandunit) &
WLC_NO_OFDM) && (gmode != GMODE_LEGACY_B))
return -EINVAL;
if (config == true)
wlc_protection_upd(wlc, WLC_PROT_G_USER, gmode);
memset(&wlc->sup_rates_override, 0, sizeof(wlc_rateset_t));
memset(&rs, 0, sizeof(wlc_rateset_t));
switch (gmode) {
case GMODE_LEGACY_B:
shortslot = WLC_SHORTSLOT_OFF;
wlc_rateset_copy(&gphy_legacy_rates, &rs);
break;
case GMODE_LRS:
if (AP_ENAB(wlc->pub))
wlc_rateset_copy(&cck_rates, &wlc->sup_rates_override);
break;
case GMODE_AUTO:
break;
case GMODE_ONLY:
ofdm_basic = true;
preamble = WLC_PLCP_SHORT;
preamble_restrict = true;
break;
case GMODE_PERFORMANCE:
if (AP_ENAB(wlc->pub))
wlc_rateset_copy(&cck_ofdm_rates,
&wlc->sup_rates_override);
shortslot = WLC_SHORTSLOT_ON;
shortslot_restrict = true;
ofdm_basic = true;
preamble = WLC_PLCP_SHORT;
preamble_restrict = true;
break;
default:
wiphy_err(wlc->wiphy, "wl%d: %s: invalid gmode %d\n",
wlc->pub->unit, __func__, gmode);
return -ENOTSUPP;
}
if ((gmode == GMODE_LEGACY_B) && (band->gmode != GMODE_LEGACY_B)) {
band->gmode = gmode;
if (band->rspec_override && !IS_CCK(band->rspec_override)) {
band->rspec_override = 0;
wlc_reprate_init(wlc);
}
if (band->mrspec_override && !IS_CCK(band->mrspec_override)) {
band->mrspec_override = 0;
}
}
band->gmode = gmode;
wlc->ignore_bcns = ignore_bcns;
wlc->shortslot_override = shortslot;
if (AP_ENAB(wlc->pub)) {
wlc->PLCPHdr_override =
(preamble !=
WLC_PLCP_LONG) ? WLC_PLCP_SHORT : WLC_PLCP_AUTO;
}
if ((AP_ENAB(wlc->pub) && preamble != WLC_PLCP_LONG)
|| preamble == WLC_PLCP_SHORT)
wlc->default_bss->capability |= WLAN_CAPABILITY_SHORT_PREAMBLE;
else
wlc->default_bss->capability &= ~WLAN_CAPABILITY_SHORT_PREAMBLE;
if ((AP_ENAB(wlc->pub) && shortslot == WLC_SHORTSLOT_AUTO) ||
shortslot == WLC_SHORTSLOT_ON)
wlc->default_bss->capability |= WLAN_CAPABILITY_SHORT_SLOT_TIME;
else
wlc->default_bss->capability &=
~WLAN_CAPABILITY_SHORT_SLOT_TIME;
if (!rs.count)
wlc_rateset_copy(&cck_ofdm_rates, &rs);
if (ofdm_basic) {
for (i = 0; i < rs.count; i++) {
if (rs.rates[i] == WLC_RATE_6M
|| rs.rates[i] == WLC_RATE_12M
|| rs.rates[i] == WLC_RATE_24M)
rs.rates[i] |= WLC_RATE_FLAG;
}
}
wlc->default_bss->rateset.count = rs.count;
memcpy(wlc->default_bss->rateset.rates, rs.rates,
sizeof(wlc->default_bss->rateset.rates));
return ret;
}
static int wlc_nmode_validate(struct wlc_info *wlc, s32 nmode)
{
int err = 0;
switch (nmode) {
case OFF:
break;
case AUTO:
case WL_11N_2x2:
case WL_11N_3x3:
if (!(WLC_PHY_11N_CAP(wlc->band)))
err = -EINVAL;
break;
default:
err = -EINVAL;
break;
}
return err;
}
int wlc_set_nmode(struct wlc_info *wlc, s32 nmode)
{
uint i;
int err;
err = wlc_nmode_validate(wlc, nmode);
if (err)
return err;
switch (nmode) {
case OFF:
wlc->pub->_n_enab = OFF;
wlc->default_bss->flags &= ~WLC_BSS_HT;
wlc_rateset_mcs_clear(&wlc->default_bss->rateset);
for (i = 0; i < NBANDS(wlc); i++) {
memset(wlc->bandstate[i]->hw_rateset.mcs, 0,
MCSSET_LEN);
if (IS_MCS(wlc->band->rspec_override)) {
wlc->bandstate[i]->rspec_override = 0;
wlc_reprate_init(wlc);
}
if (IS_MCS(wlc->band->mrspec_override))
wlc->bandstate[i]->mrspec_override = 0;
}
break;
case AUTO:
if (wlc->stf->txstreams == WL_11N_3x3)
nmode = WL_11N_3x3;
else
nmode = WL_11N_2x2;
case WL_11N_2x2:
case WL_11N_3x3:
wlc_set_gmode(wlc, GMODE_AUTO, true);
if (nmode == WL_11N_3x3)
wlc->pub->_n_enab = SUPPORT_HT;
else
wlc->pub->_n_enab = SUPPORT_11N;
wlc->default_bss->flags |= WLC_BSS_HT;
wlc_rateset_mcs_build(&wlc->default_bss->rateset,
wlc->stf->txstreams);
for (i = 0; i < NBANDS(wlc); i++)
memcpy(wlc->bandstate[i]->hw_rateset.mcs,
wlc->default_bss->rateset.mcs, MCSSET_LEN);
break;
default:
break;
}
return err;
}
static int wlc_set_rateset(struct wlc_info *wlc, wlc_rateset_t *rs_arg)
{
wlc_rateset_t rs, new;
uint bandunit;
memcpy(&rs, rs_arg, sizeof(wlc_rateset_t));
if ((rs.count == 0) || (rs.count > WLC_NUMRATES))
return -EINVAL;
bandunit = wlc->band->bandunit;
memcpy(&new, &rs, sizeof(wlc_rateset_t));
if (wlc_rate_hwrs_filter_sort_validate
(&new, &wlc->bandstate[bandunit]->hw_rateset, true,
wlc->stf->txstreams))
goto good;
if (IS_MBAND_UNLOCKED(wlc)) {
bandunit = OTHERBANDUNIT(wlc);
memcpy(&new, &rs, sizeof(wlc_rateset_t));
if (wlc_rate_hwrs_filter_sort_validate(&new,
&wlc->
bandstate[bandunit]->
hw_rateset, true,
wlc->stf->txstreams))
goto good;
}
return -EBADE;
good:
memcpy(&wlc->default_bss->rateset, &new, sizeof(wlc_rateset_t));
memcpy(&wlc->bandstate[bandunit]->defrateset, &new,
sizeof(wlc_rateset_t));
return 0;
}
int wlc_set(struct wlc_info *wlc, int cmd, int arg)
{
return wlc_ioctl(wlc, cmd, (void *)&arg, sizeof(arg), NULL);
}
int wlc_get(struct wlc_info *wlc, int cmd, int *arg)
{
return wlc_ioctl(wlc, cmd, arg, sizeof(int), NULL);
}
static void wlc_ofdm_rateset_war(struct wlc_info *wlc)
{
u8 r;
bool war = false;
if (wlc->cfg->associated)
r = wlc->cfg->current_bss->rateset.rates[0];
else
r = wlc->default_bss->rateset.rates[0];
wlc_phy_ofdm_rateset_war(wlc->band->pi, war);
return;
}
int
wlc_ioctl(struct wlc_info *wlc, int cmd, void *arg, int len,
struct wlc_if *wlcif)
{
return _wlc_ioctl(wlc, cmd, arg, len, wlcif);
}
static int
_wlc_ioctl(struct wlc_info *wlc, int cmd, void *arg, int len,
struct wlc_if *wlcif)
{
int val, *pval;
bool bool_val;
int bcmerror;
d11regs_t *regs;
uint i;
struct scb *nextscb;
bool ta_ok;
uint band;
rw_reg_t *r;
struct wlc_bsscfg *bsscfg;
wlc_bss_info_t *current_bss;
bsscfg = wlc->cfg;
current_bss = bsscfg->current_bss;
nextscb = NULL;
ta_ok = false;
band = 0;
r = NULL;
if (!wlc->pub->hw_off && DEVICEREMOVED(wlc)) {
wiphy_err(wlc->wiphy, "wl%d: %s: dead chip\n", wlc->pub->unit,
__func__);
wl_down(wlc->wl);
return -EBADE;
}
pval = arg ? (int *)arg:NULL;
if (pval && (u32) len >= sizeof(val))
memcpy(&val, pval, sizeof(val));
else
val = 0;
bool_val = val != 0;
bcmerror = 0;
regs = wlc->regs;
switch (cmd) {
case WLC_UP:
case WLC_OUT:
case WLC_DOWN:
case WLC_DISASSOC:
case WLC_RESTART:
case WLC_REBOOT:
case WLC_START_CHANNEL_QA:
case WLC_INIT:
break;
default:
if ((arg == NULL) || (len <= 0)) {
wiphy_err(wlc->wiphy, "wl%d: %s: Command %d needs "
"arguments\n",
wlc->pub->unit, __func__, cmd);
bcmerror = -EINVAL;
goto done;
}
}
switch (cmd) {
#if defined(BCMDBG)
case WLC_GET_MSGLEVEL:
*pval = wl_msg_level;
break;
case WLC_SET_MSGLEVEL:
wl_msg_level = val;
break;
#endif
case WLC_GET_INSTANCE:
*pval = wlc->pub->unit;
break;
case WLC_GET_CHANNEL:{
channel_info_t *ci = (channel_info_t *) arg;
if (len <= (int)sizeof(ci)) {
bcmerror = EOVERFLOW;
goto done;
}
ci->hw_channel =
CHSPEC_CHANNEL(WLC_BAND_PI_RADIO_CHANSPEC);
ci->target_channel =
CHSPEC_CHANNEL(wlc->default_bss->chanspec);
ci->scan_channel = 0;
break;
}
case WLC_SET_CHANNEL:{
chanspec_t chspec = CH20MHZ_CHSPEC(val);
if (val < 0 || val > MAXCHANNEL) {
bcmerror = -EINVAL;
break;
}
if (!wlc_valid_chanspec_db(wlc->cmi, chspec)) {
bcmerror = -EINVAL;
break;
}
if (!wlc->pub->up && IS_MBAND_UNLOCKED(wlc)) {
if (wlc->band->bandunit !=
CHSPEC_WLCBANDUNIT(chspec))
wlc->bandinit_pending = true;
else
wlc->bandinit_pending = false;
}
wlc->default_bss->chanspec = chspec;
if (wlc->pub->up &&
(WLC_BAND_PI_RADIO_CHANSPEC != chspec)) {
wlc_set_home_chanspec(wlc, chspec);
wlc_suspend_mac_and_wait(wlc);
wlc_set_chanspec(wlc, chspec);
wlc_enable_mac(wlc);
}
break;
}
#if defined(BCMDBG)
case WLC_GET_UCFLAGS:
if (!wlc->pub->up) {
bcmerror = -ENOLINK;
break;
}
band =
(len <
(int)(2 * sizeof(int))) ? WLC_BAND_AUTO : ((int *)arg)[1];
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
if (val >= MHFMAX) {
bcmerror = -EINVAL;
break;
}
*pval = wlc_bmac_mhf_get(wlc->hw, (u8) val, WLC_BAND_AUTO);
break;
case WLC_SET_UCFLAGS:
if (!wlc->pub->up) {
bcmerror = -ENOLINK;
break;
}
band =
(len <
(int)(2 * sizeof(int))) ? WLC_BAND_AUTO : ((int *)arg)[1];
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
i = (u16) val;
if (i >= MHFMAX) {
bcmerror = -EINVAL;
break;
}
wlc_mhf(wlc, (u8) i, 0xffff, (u16) (val >> NBITS(u16)),
WLC_BAND_AUTO);
break;
case WLC_GET_SHMEM:
ta_ok = true;
band =
(len <
(int)(2 * sizeof(int))) ? WLC_BAND_AUTO : ((int *)arg)[1];
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
if (val & 1) {
bcmerror = -EINVAL;
break;
}
*pval = wlc_read_shm(wlc, (u16) val);
break;
case WLC_SET_SHMEM:
ta_ok = true;
band =
(len <
(int)(2 * sizeof(int))) ? WLC_BAND_AUTO : ((int *)arg)[1];
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
if (val & 1) {
bcmerror = -EINVAL;
break;
}
wlc_write_shm(wlc, (u16) val,
(u16) (val >> NBITS(u16)));
break;
case WLC_R_REG:
ta_ok = true;
r = (rw_reg_t *) arg;
band = WLC_BAND_AUTO;
if (len < (int)(sizeof(rw_reg_t) - sizeof(uint))) {
bcmerror = -EOVERFLOW;
break;
}
if (len >= (int)sizeof(rw_reg_t))
band = r->band;
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
if ((r->byteoff + r->size) > sizeof(d11regs_t)) {
bcmerror = -EINVAL;
break;
}
if (r->size == sizeof(u32))
r->val =
R_REG((u32 *)((unsigned char *)(unsigned long)regs +
r->byteoff));
else if (r->size == sizeof(u16))
r->val =
R_REG((u16 *)((unsigned char *)(unsigned long)regs +
r->byteoff));
else
bcmerror = -EINVAL;
break;
case WLC_W_REG:
ta_ok = true;
r = (rw_reg_t *) arg;
band = WLC_BAND_AUTO;
if (len < (int)(sizeof(rw_reg_t) - sizeof(uint))) {
bcmerror = -EOVERFLOW;
break;
}
if (len >= (int)sizeof(rw_reg_t))
band = r->band;
bcmerror = wlc_iocregchk(wlc, band);
if (bcmerror)
break;
if (r->byteoff + r->size > sizeof(d11regs_t)) {
bcmerror = -EINVAL;
break;
}
if (r->size == sizeof(u32))
W_REG((u32 *)((unsigned char *)(unsigned long) regs +
r->byteoff), r->val);
else if (r->size == sizeof(u16))
W_REG((u16 *)((unsigned char *)(unsigned long) regs +
r->byteoff), r->val);
else
bcmerror = -EINVAL;
break;
#endif
case WLC_GET_TXANT:
*pval = wlc->stf->txant;
break;
case WLC_SET_TXANT:
bcmerror = wlc_stf_ant_txant_validate(wlc, (s8) val);
if (bcmerror < 0)
break;
wlc->stf->txant = (s8) val;
if (!wlc->pub->up)
break;
wlc_suspend_mac_and_wait(wlc);
wlc_stf_phy_txant_upd(wlc);
wlc_beacon_phytxctl_txant_upd(wlc, wlc->bcn_rspec);
wlc_enable_mac(wlc);
break;
case WLC_GET_ANTDIV:{
u8 phy_antdiv;
if (!wlc->pub->up) {
*pval = wlc->stf->ant_rx_ovr;
} else {
if (wlc_phy_ant_rxdiv_get
(wlc->band->pi, &phy_antdiv))
*pval = (int)phy_antdiv;
else
*pval = (int)wlc->stf->ant_rx_ovr;
}
break;
}
case WLC_SET_ANTDIV:
if ((val < -1) || (val > 3)) {
bcmerror = -EINVAL;
break;
}
if (val == -1)
val = ANT_RX_DIV_DEF;
wlc->stf->ant_rx_ovr = (u8) val;
wlc_phy_ant_rxdiv_set(wlc->band->pi, (u8) val);
break;
case WLC_GET_RX_ANT:{
u16 rxstatus;
if (!wlc->pub->up) {
bcmerror = -ENOLINK;
break;
}
rxstatus = R_REG(&wlc->regs->phyrxstatus0);
if (rxstatus == 0xdead || rxstatus == (u16) -1) {
bcmerror = -EBADE;
break;
}
*pval = (rxstatus & PRXS0_RXANT_UPSUBBAND) ? 1 : 0;
break;
}
#if defined(BCMDBG)
case WLC_GET_UCANTDIV:
if (!wlc->clk) {
bcmerror = -EIO;
break;
}
*pval =
(wlc_bmac_mhf_get(wlc->hw, MHF1, WLC_BAND_AUTO) &
MHF1_ANTDIV);
break;
case WLC_SET_UCANTDIV:{
if (!wlc->pub->up) {
bcmerror = -ENOLINK;
break;
}
if (IS_MBAND_UNLOCKED(wlc)) {
bcmerror = -ENOMEDIUM;
break;
}
wlc_mhf(wlc, MHF1, MHF1_ANTDIV,
(val ? MHF1_ANTDIV : 0), WLC_BAND_AUTO);
break;
}
#endif
case WLC_GET_SRL:
*pval = wlc->SRL;
break;
case WLC_SET_SRL:
if (val >= 1 && val <= RETRY_SHORT_MAX) {
int ac;
wlc->SRL = (u16) val;
wlc_bmac_retrylimit_upd(wlc->hw, wlc->SRL, wlc->LRL);
for (ac = 0; ac < AC_COUNT; ac++) {
WLC_WME_RETRY_SHORT_SET(wlc, ac, wlc->SRL);
}
wlc_wme_retries_write(wlc);
} else
bcmerror = -EINVAL;
break;
case WLC_GET_LRL:
*pval = wlc->LRL;
break;
case WLC_SET_LRL:
if (val >= 1 && val <= 255) {
int ac;
wlc->LRL = (u16) val;
wlc_bmac_retrylimit_upd(wlc->hw, wlc->SRL, wlc->LRL);
for (ac = 0; ac < AC_COUNT; ac++) {
WLC_WME_RETRY_LONG_SET(wlc, ac, wlc->LRL);
}
wlc_wme_retries_write(wlc);
} else
bcmerror = -EINVAL;
break;
case WLC_GET_CWMIN:
*pval = wlc->band->CWmin;
break;
case WLC_SET_CWMIN:
if (!wlc->clk) {
bcmerror = -EIO;
break;
}
if (val >= 1 && val <= 255) {
wlc_set_cwmin(wlc, (u16) val);
} else
bcmerror = -EINVAL;
break;
case WLC_GET_CWMAX:
*pval = wlc->band->CWmax;
break;
case WLC_SET_CWMAX:
if (!wlc->clk) {
bcmerror = -EIO;
break;
}
if (val >= 255 && val <= 2047) {
wlc_set_cwmax(wlc, (u16) val);
} else
bcmerror = -EINVAL;
break;
case WLC_GET_RADIO:
*pval = wlc->pub->radio_disabled;
break;
case WLC_SET_RADIO:{
u16 radiomask, radioval;
uint validbits =
WL_RADIO_SW_DISABLE | WL_RADIO_HW_DISABLE;
mbool new = 0;
radiomask = (val & 0xffff0000) >> 16;
radioval = val & 0x0000ffff;
if ((radiomask == 0) || (radiomask & ~validbits)
|| (radioval & ~validbits)
|| ((radioval & ~radiomask) != 0)) {
wiphy_err(wlc->wiphy, "SET_RADIO with wrong "
"bits 0x%x\n", val);
bcmerror = -EINVAL;
break;
}
new =
(wlc->pub->radio_disabled & ~radiomask) | radioval;
wlc->pub->radio_disabled = new;
wlc_radio_hwdisable_upd(wlc);
wlc_radio_upd(wlc);
break;
}
case WLC_GET_PHYTYPE:
*pval = WLC_PHYTYPE(wlc->band->phytype);
break;
#if defined(BCMDBG)
case WLC_GET_KEY:
if ((val >= 0) && (val < WLC_MAX_WSEC_KEYS(wlc))) {
wl_wsec_key_t key;
wsec_key_t *src_key = wlc->wsec_keys[val];
if (len < (int)sizeof(key)) {
bcmerror = -EOVERFLOW;
break;
}
memset((char *)&key, 0, sizeof(key));
if (src_key) {
key.index = src_key->id;
key.len = src_key->len;
memcpy(key.data, src_key->data, key.len);
key.algo = src_key->algo;
if (WSEC_SOFTKEY(wlc, src_key, bsscfg))
key.flags |= WL_SOFT_KEY;
if (src_key->flags & WSEC_PRIMARY_KEY)
key.flags |= WL_PRIMARY_KEY;
memcpy(key.ea, src_key->ea, ETH_ALEN);
}
memcpy(arg, &key, sizeof(key));
} else
bcmerror = -EINVAL;
break;
#endif
case WLC_SET_KEY:
bcmerror =
wlc_iovar_op(wlc, "wsec_key", NULL, 0, arg, len, IOV_SET,
wlcif);
break;
case WLC_GET_KEY_SEQ:{
wsec_key_t *key;
if (len < DOT11_WPA_KEY_RSC_LEN) {
bcmerror = -EOVERFLOW;
break;
}
key = WSEC_KEY(wlc, val);
if ((val >= 0) && (val < WLC_MAX_WSEC_KEYS(wlc)) &&
(key != NULL)) {
u8 seq[DOT11_WPA_KEY_RSC_LEN];
u16 lo;
u32 hi;
if ((bsscfg->WPA_auth & WPA_AUTH_NONE) &&
is_zero_ether_addr(key->ea)) {
lo = bsscfg->wpa_none_txiv.lo;
hi = bsscfg->wpa_none_txiv.hi;
} else {
lo = key->txiv.lo;
hi = key->txiv.hi;
}
seq[0] = lo & 0xff;
seq[1] = (lo >> 8) & 0xff;
seq[2] = hi & 0xff;
seq[3] = (hi >> 8) & 0xff;
seq[4] = (hi >> 16) & 0xff;
seq[5] = (hi >> 24) & 0xff;
seq[6] = 0;
seq[7] = 0;
memcpy(arg, seq, sizeof(seq));
} else {
bcmerror = -EINVAL;
}
break;
}
case WLC_GET_CURR_RATESET:{
wl_rateset_t *ret_rs = (wl_rateset_t *) arg;
wlc_rateset_t *rs;
if (wlc->pub->associated)
rs = &current_bss->rateset;
else
rs = &wlc->default_bss->rateset;
if (len < (int)(rs->count + sizeof(rs->count))) {
bcmerror = -EOVERFLOW;
break;
}
ret_rs->count = rs->count;
memcpy(&ret_rs->rates, &rs->rates, rs->count);
break;
}
case WLC_GET_RATESET:{
wlc_rateset_t rs;
wl_rateset_t *ret_rs = (wl_rateset_t *) arg;
memset(&rs, 0, sizeof(wlc_rateset_t));
wlc_default_rateset(wlc, (wlc_rateset_t *) &rs);
if (len < (int)(rs.count + sizeof(rs.count))) {
bcmerror = -EOVERFLOW;
break;
}
ret_rs->count = rs.count;
memcpy(&ret_rs->rates, &rs.rates, rs.count);
break;
}
case WLC_SET_RATESET:{
wlc_rateset_t rs;
wl_rateset_t *in_rs = (wl_rateset_t *) arg;
if (len < (int)(in_rs->count + sizeof(in_rs->count))) {
bcmerror = -EOVERFLOW;
break;
}
if (in_rs->count > WLC_NUMRATES) {
bcmerror = -ENOBUFS;
break;
}
memset(&rs, 0, sizeof(wlc_rateset_t));
rs.count = in_rs->count;
memcpy(&rs.rates, &in_rs->rates, rs.count);
if (N_ENAB(wlc->pub)) {
if (bsscfg->associated)
memcpy(rs.mcs,
&current_bss->rateset.mcs[0],
MCSSET_LEN);
else
memcpy(rs.mcs,
&wlc->default_bss->rateset.mcs[0],
MCSSET_LEN);
}
bcmerror = wlc_set_rateset(wlc, &rs);
if (!bcmerror)
wlc_ofdm_rateset_war(wlc);
break;
}
case WLC_GET_BCNPRD:
if (BSSCFG_STA(bsscfg) && bsscfg->BSS && bsscfg->associated)
*pval = current_bss->beacon_period;
else
*pval = wlc->default_bss->beacon_period;
break;
case WLC_SET_BCNPRD:
if (val >= DOT11_MIN_BEACON_PERIOD
&& val <= DOT11_MAX_BEACON_PERIOD) {
wlc->default_bss->beacon_period = (u16) val;
} else
bcmerror = -EINVAL;
break;
case WLC_GET_DTIMPRD:
if (BSSCFG_STA(bsscfg) && bsscfg->BSS && bsscfg->associated)
*pval = current_bss->dtim_period;
else
*pval = wlc->default_bss->dtim_period;
break;
case WLC_SET_DTIMPRD:
if (val >= DOT11_MIN_DTIM_PERIOD
&& val <= DOT11_MAX_DTIM_PERIOD) {
wlc->default_bss->dtim_period = (u8) val;
} else
bcmerror = -EINVAL;
break;
#ifdef SUPPORT_PS
case WLC_GET_PM:
*pval = wlc->PM;
break;
case WLC_SET_PM:
if ((val >= PM_OFF) && (val <= PM_MAX)) {
wlc->PM = (u8) val;
if (wlc->pub->up) {
}
wlc_watchdog_upd(wlc, PS_ALLOWED(wlc));
} else
bcmerror = -EBADE;
break;
#endif
#ifdef SUPPORT_PS
#ifdef BCMDBG
case WLC_GET_WAKE:
if (AP_ENAB(wlc->pub)) {
bcmerror = -BCME_NOTSTA;
break;
}
*pval = wlc->wake;
break;
case WLC_SET_WAKE:
if (AP_ENAB(wlc->pub)) {
bcmerror = -BCME_NOTSTA;
break;
}
wlc->wake = val ? true : false;
if (!wlc->pub->up)
break;
wlc_set_ps_ctrl(wlc);
break;
#endif
#endif
case WLC_GET_REVINFO:
bcmerror = wlc_get_revision_info(wlc, arg, (uint) len);
break;
case WLC_GET_AP:
*pval = (int)AP_ENAB(wlc->pub);
break;
case WLC_GET_ATIM:
if (bsscfg->associated)
*pval = (int)current_bss->atim_window;
else
*pval = (int)wlc->default_bss->atim_window;
break;
case WLC_SET_ATIM:
wlc->default_bss->atim_window = (u32) val;
break;
#ifdef SUPPORT_HWKEY
case WLC_GET_WSEC:
bcmerror =
wlc_iovar_op(wlc, "wsec", NULL, 0, arg, len, IOV_GET,
wlcif);
break;
case WLC_SET_WSEC:
bcmerror =
wlc_iovar_op(wlc, "wsec", NULL, 0, arg, len, IOV_SET,
wlcif);
break;
case WLC_GET_WPA_AUTH:
*pval = (int)bsscfg->WPA_auth;
break;
case WLC_SET_WPA_AUTH:
if (BSSCFG_STA(bsscfg)) {
bsscfg->WPA_auth = (u16) val;
} else
bsscfg->WPA_auth = (u16) val;
break;
#endif
case WLC_GET_BANDLIST:
*pval++ = NBANDS(wlc);
*pval++ = wlc->band->bandtype;
if (NBANDS(wlc) > 1)
*pval++ = wlc->bandstate[OTHERBANDUNIT(wlc)]->bandtype;
break;
case WLC_GET_BAND:
*pval = wlc->bandlocked ? wlc->band->bandtype : WLC_BAND_AUTO;
break;
case WLC_GET_PHYLIST:
{
unsigned char *cp = arg;
if (len < 3) {
bcmerror = -EOVERFLOW;
break;
}
if (WLCISNPHY(wlc->band)) {
*cp++ = 'n';
} else if (WLCISLCNPHY(wlc->band)) {
*cp++ = 'c';
} else if (WLCISSSLPNPHY(wlc->band)) {
*cp++ = 's';
}
*cp = '\0';
break;
}
case WLC_GET_SHORTSLOT:
*pval = wlc->shortslot;
break;
case WLC_GET_SHORTSLOT_OVERRIDE:
*pval = wlc->shortslot_override;
break;
case WLC_SET_SHORTSLOT_OVERRIDE:
if ((val != WLC_SHORTSLOT_AUTO) &&
(val != WLC_SHORTSLOT_OFF) && (val != WLC_SHORTSLOT_ON)) {
bcmerror = -EINVAL;
break;
}
wlc->shortslot_override = (s8) val;
if (BAND_5G(wlc->band->bandtype))
break;
if (wlc->pub->up && wlc->pub->associated) {
} else if (wlc->pub->up) {
wlc_switch_shortslot(wlc, false);
} else {
if (wlc->shortslot_override == WLC_SHORTSLOT_AUTO) {
wlc->shortslot = false;
} else {
wlc->shortslot =
(wlc->shortslot_override ==
WLC_SHORTSLOT_ON);
}
}
break;
case WLC_GET_LEGACY_ERP:
*pval = wlc->include_legacy_erp;
break;
case WLC_SET_LEGACY_ERP:
if (wlc->include_legacy_erp == bool_val)
break;
wlc->include_legacy_erp = bool_val;
if (AP_ENAB(wlc->pub) && wlc->clk) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, true);
}
break;
case WLC_GET_GMODE:
if (wlc->band->bandtype == WLC_BAND_2G)
*pval = wlc->band->gmode;
else if (NBANDS(wlc) > 1)
*pval = wlc->bandstate[OTHERBANDUNIT(wlc)]->gmode;
break;
case WLC_SET_GMODE:
if (!wlc->pub->associated)
bcmerror = wlc_set_gmode(wlc, (u8) val, true);
else {
bcmerror = -EISCONN;
break;
}
break;
case WLC_GET_GMODE_PROTECTION:
*pval = wlc->protection->_g;
break;
case WLC_GET_PROTECTION_CONTROL:
*pval = wlc->protection->overlap;
break;
case WLC_SET_PROTECTION_CONTROL:
if ((val != WLC_PROTECTION_CTL_OFF) &&
(val != WLC_PROTECTION_CTL_LOCAL) &&
(val != WLC_PROTECTION_CTL_OVERLAP)) {
bcmerror = -EINVAL;
break;
}
wlc_protection_upd(wlc, WLC_PROT_OVERLAP, (s8) val);
break;
case WLC_GET_GMODE_PROTECTION_OVERRIDE:
*pval = wlc->protection->g_override;
break;
case WLC_SET_GMODE_PROTECTION_OVERRIDE:
if ((val != WLC_PROTECTION_AUTO) &&
(val != WLC_PROTECTION_OFF) && (val != WLC_PROTECTION_ON)) {
bcmerror = -EINVAL;
break;
}
wlc_protection_upd(wlc, WLC_PROT_G_OVR, (s8) val);
break;
case WLC_SET_SUP_RATESET_OVERRIDE:{
wlc_rateset_t rs, new;
if (len < (int)sizeof(wlc_rateset_t)) {
bcmerror = -EOVERFLOW;
break;
}
memcpy(&rs, arg, sizeof(wlc_rateset_t));
if (rs.count > WLC_NUMRATES) {
bcmerror = -EINVAL;
break;
}
if (!(wlc->band->gmode ||
((NBANDS(wlc) > 1)
&& wlc->bandstate[OTHERBANDUNIT(wlc)]->gmode))) {
bcmerror = -EINVAL;
break;
}
if (rs.count == 0) {
memset(&wlc->sup_rates_override, 0,
sizeof(wlc_rateset_t));
break;
}
wlc_rateset_filter(&rs, &new, false,
WLC_RATES_CCK_OFDM, WLC_RATE_MASK,
BSS_N_ENAB(wlc, bsscfg));
wlc_rate_hwrs_filter_sort_validate(&new,
&cck_ofdm_rates,
false,
wlc->stf->txstreams);
if (rs.count != new.count) {
bcmerror = -EINVAL;
break;
}
memcpy(&wlc->sup_rates_override, &new,
sizeof(wlc_rateset_t));
if (wlc->pub->up && AP_ENAB(wlc->pub)
&& wlc->pub->associated) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, true);
}
break;
}
case WLC_GET_SUP_RATESET_OVERRIDE:
if (!(wlc->band->gmode ||
((NBANDS(wlc) > 1)
&& wlc->bandstate[OTHERBANDUNIT(wlc)]->gmode))) {
bcmerror = -EINVAL;
break;
}
if (len < (int)sizeof(wlc_rateset_t)) {
bcmerror = -EOVERFLOW;
break;
}
memcpy(arg, &wlc->sup_rates_override, sizeof(wlc_rateset_t));
break;
case WLC_GET_PRB_RESP_TIMEOUT:
*pval = wlc->prb_resp_timeout;
break;
case WLC_SET_PRB_RESP_TIMEOUT:
if (wlc->pub->up) {
bcmerror = -EISCONN;
break;
}
if (val < 0 || val >= 0xFFFF) {
bcmerror = -EINVAL;
break;
}
wlc->prb_resp_timeout = (u16) val;
break;
case WLC_GET_KEY_PRIMARY:{
wsec_key_t *key;
key = WSEC_BSS_DEFAULT_KEY(bsscfg);
if (key != NULL) {
*pval = key->id == val ? true : false;
} else {
bcmerror = -EINVAL;
}
break;
}
case WLC_SET_KEY_PRIMARY:{
wsec_key_t *key, *old_key;
bcmerror = -EINVAL;
for (i = 0; i < WSEC_MAX_DEFAULT_KEYS; i++) {
key = bsscfg->bss_def_keys[i];
if (key != NULL && key->id == val) {
old_key = WSEC_BSS_DEFAULT_KEY(bsscfg);
if (old_key != NULL)
old_key->flags &=
~WSEC_PRIMARY_KEY;
key->flags |= WSEC_PRIMARY_KEY;
bsscfg->wsec_index = i;
bcmerror = 0;
}
}
break;
}
#ifdef BCMDBG
case WLC_INIT:
wl_init(wlc->wl);
break;
#endif
case WLC_SET_VAR:
case WLC_GET_VAR:{
char *name;
name = (char *)arg;
for (i = 0; i < (uint) len && *name != '\0';
i++, name++)
;
if (i == (uint) len) {
bcmerror = -EOVERFLOW;
break;
}
i++;
if (cmd == WLC_GET_VAR) {
bcmerror =
wlc_iovar_op(wlc, arg,
(void *)((s8 *) arg + i),
len - i, arg, len, IOV_GET,
wlcif);
} else
bcmerror =
wlc_iovar_op(wlc, arg, NULL, 0,
(void *)((s8 *) arg + i),
len - i, IOV_SET, wlcif);
break;
}
case WLC_SET_WSEC_PMK:
bcmerror = -ENOTSUPP;
break;
#if defined(BCMDBG)
case WLC_CURRENT_PWR:
if (!wlc->pub->up)
bcmerror = -ENOLINK;
else
bcmerror = wlc_get_current_txpwr(wlc, arg, len);
break;
#endif
case WLC_LAST:
wiphy_err(wlc->wiphy, "%s: WLC_LAST\n", __func__);
}
done:
if (bcmerror)
wlc->pub->bcmerror = bcmerror;
return bcmerror;
}
int wlc_iocregchk(struct wlc_info *wlc, uint band)
{
if ((band != WLC_BAND_AUTO) && (band != (uint) wlc->band->bandtype))
return -EINVAL;
if ((band == WLC_BAND_AUTO) && IS_MBAND_UNLOCKED(wlc))
return -ENOMEDIUM;
if (!wlc->clk)
return -EIO;
return 0;
}
static const bcm_iovar_t *wlc_iovar_lookup(const bcm_iovar_t *table,
const char *name)
{
const bcm_iovar_t *vi;
const char *lookup_name;
lookup_name = strrchr(name, ':');
if (lookup_name != NULL)
lookup_name++;
else
lookup_name = name;
for (vi = table; vi->name; vi++) {
if (!strcmp(vi->name, lookup_name))
return vi;
}
return NULL;
}
int wlc_iovar_getint(struct wlc_info *wlc, const char *name, int *arg)
{
return wlc_iovar_op(wlc, name, NULL, 0, arg, sizeof(s32), IOV_GET,
NULL);
}
int wlc_iovar_setint(struct wlc_info *wlc, const char *name, int arg)
{
return wlc_iovar_op(wlc, name, NULL, 0, (void *)&arg, sizeof(arg),
IOV_SET, NULL);
}
int wlc_module_register(struct wlc_pub *pub, const bcm_iovar_t *iovars,
const char *name, void *hdl, iovar_fn_t i_fn,
watchdog_fn_t w_fn, down_fn_t d_fn)
{
struct wlc_info *wlc = (struct wlc_info *) pub->wlc;
int i;
for (i = 0; i < WLC_MAXMODULES; i++) {
if (wlc->modulecb[i].name[0] == '\0') {
strncpy(wlc->modulecb[i].name, name,
sizeof(wlc->modulecb[i].name) - 1);
wlc->modulecb[i].iovars = iovars;
wlc->modulecb[i].hdl = hdl;
wlc->modulecb[i].iovar_fn = i_fn;
wlc->modulecb[i].watchdog_fn = w_fn;
wlc->modulecb[i].down_fn = d_fn;
return 0;
}
}
return -ENOSR;
}
int wlc_module_unregister(struct wlc_pub *pub, const char *name, void *hdl)
{
struct wlc_info *wlc = (struct wlc_info *) pub->wlc;
int i;
if (wlc == NULL)
return -ENODATA;
for (i = 0; i < WLC_MAXMODULES; i++) {
if (!strcmp(wlc->modulecb[i].name, name) &&
(wlc->modulecb[i].hdl == hdl)) {
memset(&wlc->modulecb[i], 0, sizeof(struct modulecb));
return 0;
}
}
return -ENODATA;
}
static void wlc_wme_retries_write(struct wlc_info *wlc)
{
int ac;
if (!wlc->clk)
return;
for (ac = 0; ac < AC_COUNT; ac++) {
wlc_write_shm(wlc, M_AC_TXLMT_ADDR(ac), wlc->wme_retries[ac]);
}
}
int
wlc_iovar_op(struct wlc_info *wlc, const char *name,
void *params, int p_len, void *arg, int len,
bool set, struct wlc_if *wlcif)
{
int err = 0;
int val_size;
const bcm_iovar_t *vi = NULL;
u32 actionid;
int i;
if (!set && (len == sizeof(int)) &&
!(IS_ALIGNED((unsigned long)(arg), (uint) sizeof(int)))) {
wiphy_err(wlc->wiphy, "wl%d: %s unaligned get ptr for %s\n",
wlc->pub->unit, __func__, name);
return -ENOTSUPP;
}
for (i = 0; i < WLC_MAXMODULES; i++) {
if (!wlc->modulecb[i].iovars)
continue;
vi = wlc_iovar_lookup(wlc->modulecb[i].iovars, name);
if (vi)
break;
}
if (i >= WLC_MAXMODULES) {
return -ENOTSUPP;
}
if (params == NULL) {
params = arg;
p_len = len;
}
if (vi->type == IOVT_VOID)
val_size = 0;
else if (vi->type == IOVT_BUFFER)
val_size = len;
else
val_size = sizeof(int);
actionid = set ? IOV_SVAL(vi->varid) : IOV_GVAL(vi->varid);
err = wlc->modulecb[i].iovar_fn(wlc->modulecb[i].hdl, vi, actionid,
name, params, p_len, arg, len, val_size,
wlcif);
return err;
}
int
wlc_iovar_check(struct wlc_pub *pub, const bcm_iovar_t *vi, void *arg, int len,
bool set)
{
struct wlc_info *wlc = (struct wlc_info *) pub->wlc;
int err = 0;
s32 int_val = 0;
if (set) {
if (((vi->flags & IOVF_SET_DOWN) && wlc->pub->up) ||
((vi->flags & IOVF_SET_UP) && !wlc->pub->up)) {
err = (wlc->pub->up ? -EISCONN : -ENOLINK);
} else if ((vi->flags & IOVF_SET_BAND)
&& IS_MBAND_UNLOCKED(wlc)) {
err = -ENOMEDIUM;
} else if ((vi->flags & IOVF_SET_CLK) && !wlc->clk) {
err = -EIO;
}
} else {
if (((vi->flags & IOVF_GET_DOWN) && wlc->pub->up) ||
((vi->flags & IOVF_GET_UP) && !wlc->pub->up)) {
err = (wlc->pub->up ? -EISCONN : -ENOLINK);
} else if ((vi->flags & IOVF_GET_BAND)
&& IS_MBAND_UNLOCKED(wlc)) {
err = -ENOMEDIUM;
} else if ((vi->flags & IOVF_GET_CLK) && !wlc->clk) {
err = -EIO;
}
}
if (err)
goto exit;
err = bcm_iovar_lencheck(vi, arg, len, set);
if (err)
goto exit;
if (set) {
switch (vi->type) {
case IOVT_BOOL:
case IOVT_INT8:
case IOVT_INT16:
case IOVT_INT32:
case IOVT_UINT8:
case IOVT_UINT16:
case IOVT_UINT32:
memcpy(&int_val, arg, sizeof(int));
err = wlc_iovar_rangecheck(wlc, int_val, vi);
break;
}
}
exit:
return err;
}
int
wlc_doiovar(void *hdl, const bcm_iovar_t *vi, u32 actionid,
const char *name, void *params, uint p_len, void *arg, int len,
int val_size, struct wlc_if *wlcif)
{
struct wlc_info *wlc = hdl;
struct wlc_bsscfg *bsscfg;
int err = 0;
s32 int_val = 0;
s32 int_val2 = 0;
s32 *ret_int_ptr;
bool bool_val;
bool bool_val2;
wlc_bss_info_t *current_bss;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
bsscfg = NULL;
current_bss = NULL;
err = wlc_iovar_check(wlc->pub, vi, arg, len, IOV_ISSET(actionid));
if (err != 0)
return err;
if (p_len >= (int)sizeof(int_val))
memcpy(&int_val, params, sizeof(int_val));
if (p_len >= (int)sizeof(int_val) * 2)
memcpy(&int_val2,
(void *)((unsigned long)params + sizeof(int_val)),
sizeof(int_val));
ret_int_ptr = (s32 *) arg;
bool_val = (int_val != 0) ? true : false;
bool_val2 = (int_val2 != 0) ? true : false;
BCMMSG(wlc->wiphy, "wl%d: id %d\n", wlc->pub->unit, IOV_ID(actionid));
switch (actionid) {
case IOV_SVAL(IOV_RTSTHRESH):
wlc->RTSThresh = int_val;
break;
case IOV_GVAL(IOV_QTXPOWER):{
uint qdbm;
bool override;
err = wlc_phy_txpower_get(wlc->band->pi, &qdbm,
&override);
if (err != 0)
return err;
*ret_int_ptr =
qdbm | (override ? WL_TXPWR_OVERRIDE : 0);
break;
}
case IOV_SVAL(IOV_QTXPOWER):{
u8 qdbm;
bool override;
qdbm = (u8)min_t(u32, (int_val & ~WL_TXPWR_OVERRIDE), 0xff);
override = (int_val & WL_TXPWR_OVERRIDE) ? true : false;
err =
wlc_phy_txpower_set(wlc->band->pi, qdbm, override);
break;
}
case IOV_GVAL(IOV_MPC):
*ret_int_ptr = (s32) wlc->mpc;
break;
case IOV_SVAL(IOV_MPC):
wlc->mpc = bool_val;
wlc_radio_mpc_upd(wlc);
break;
case IOV_GVAL(IOV_BCN_LI_BCN):
*ret_int_ptr = wlc->bcn_li_bcn;
break;
case IOV_SVAL(IOV_BCN_LI_BCN):
wlc->bcn_li_bcn = (u8) int_val;
if (wlc->pub->up)
wlc_bcn_li_upd(wlc);
break;
default:
wiphy_err(wlc->wiphy, "wl%d: %s: unsupported\n",
wlc->pub->unit, __func__);
err = -ENOTSUPP;
break;
}
goto exit;
exit:
return err;
}
static int
wlc_iovar_rangecheck(struct wlc_info *wlc, u32 val, const bcm_iovar_t *vi)
{
int err = 0;
u32 min_val = 0;
u32 max_val = 0;
switch (vi->type) {
case IOVT_INT32:
max_val |= 0x7fffffff;
case IOVT_INT16:
max_val |= 0x00007fff;
case IOVT_INT8:
max_val |= 0x0000007f;
min_val = ~max_val;
if (vi->flags & IOVF_NTRL)
min_val = 1;
else if (vi->flags & IOVF_WHL)
min_val = 0;
if ((s32) val < (s32) min_val
|| (s32) val > (s32) max_val)
err = -EINVAL;
break;
case IOVT_UINT32:
max_val |= 0xffffffff;
case IOVT_UINT16:
max_val |= 0x0000ffff;
case IOVT_UINT8:
max_val |= 0x000000ff;
if (vi->flags & IOVF_NTRL)
min_val = 1;
if ((val < min_val) || (val > max_val))
err = -EINVAL;
break;
}
return err;
}
static void wlc_print_txs_status(u16 s)
{
printk(KERN_DEBUG "[15:12] %d frame attempts\n",
(s & TX_STATUS_FRM_RTX_MASK) >> TX_STATUS_FRM_RTX_SHIFT);
printk(KERN_DEBUG " [11:8] %d rts attempts\n",
(s & TX_STATUS_RTS_RTX_MASK) >> TX_STATUS_RTS_RTX_SHIFT);
printk(KERN_DEBUG " [7] %d PM mode indicated\n",
((s & TX_STATUS_PMINDCTD) ? 1 : 0));
printk(KERN_DEBUG " [6] %d intermediate status\n",
((s & TX_STATUS_INTERMEDIATE) ? 1 : 0));
printk(KERN_DEBUG " [5] %d AMPDU\n",
(s & TX_STATUS_AMPDU) ? 1 : 0);
printk(KERN_DEBUG " [4:2] %d Frame Suppressed Reason (%s)\n",
((s & TX_STATUS_SUPR_MASK) >> TX_STATUS_SUPR_SHIFT),
supr_reason[(s & TX_STATUS_SUPR_MASK) >> TX_STATUS_SUPR_SHIFT]);
printk(KERN_DEBUG " [1] %d acked\n",
((s & TX_STATUS_ACK_RCV) ? 1 : 0));
}
void wlc_print_txstatus(tx_status_t *txs)
{
#if defined(BCMDBG)
u16 s = txs->status;
u16 ackphyrxsh = txs->ackphyrxsh;
printk(KERN_DEBUG "\ntxpkt (MPDU) Complete\n");
printk(KERN_DEBUG "FrameID: %04x ", txs->frameid);
printk(KERN_DEBUG "TxStatus: %04x", s);
printk(KERN_DEBUG "\n");
wlc_print_txs_status(s);
printk(KERN_DEBUG "LastTxTime: %04x ", txs->lasttxtime);
printk(KERN_DEBUG "Seq: %04x ", txs->sequence);
printk(KERN_DEBUG "PHYTxStatus: %04x ", txs->phyerr);
printk(KERN_DEBUG "RxAckRSSI: %04x ",
(ackphyrxsh & PRXS1_JSSI_MASK) >> PRXS1_JSSI_SHIFT);
printk(KERN_DEBUG "RxAckSQ: %04x",
(ackphyrxsh & PRXS1_SQ_MASK) >> PRXS1_SQ_SHIFT);
printk(KERN_DEBUG "\n");
#endif
}
void wlc_statsupd(struct wlc_info *wlc)
{
int i;
macstat_t macstats;
#ifdef BCMDBG
u16 delta;
u16 rxf0ovfl;
u16 txfunfl[NFIFO];
#endif
if (!wlc->pub->up)
return;
#ifdef BCMDBG
rxf0ovfl = wlc->core->macstat_snapshot->rxf0ovfl;
for (i = 0; i < NFIFO; i++)
txfunfl[i] = wlc->core->macstat_snapshot->txfunfl[i];
#endif
wlc_bmac_copyfrom_shm(wlc->hw, M_UCODE_MACSTAT,
&macstats, sizeof(macstat_t));
#ifdef BCMDBG
delta = (u16) (wlc->core->macstat_snapshot->rxf0ovfl - rxf0ovfl);
if (delta)
wiphy_err(wlc->wiphy, "wl%d: %u rx fifo 0 overflows!\n",
wlc->pub->unit, delta);
for (i = 0; i < NFIFO; i++) {
delta =
(u16) (wlc->core->macstat_snapshot->txfunfl[i] -
txfunfl[i]);
if (delta)
wiphy_err(wlc->wiphy, "wl%d: %u tx fifo %d underflows!"
"\n", wlc->pub->unit, delta, i);
}
#endif
for (i = 0; i < NFIFO; i++) {
if (wlc->hw->di[i]) {
dma_counterreset(wlc->hw->di[i]);
}
}
}
bool wlc_chipmatch(u16 vendor, u16 device)
{
if (vendor != PCI_VENDOR_ID_BROADCOM) {
pr_err("wlc_chipmatch: unknown vendor id %04x\n", vendor);
return false;
}
if ((device == BCM43224_D11N_ID) || (device == BCM43225_D11N2G_ID))
return true;
if (device == BCM4313_D11N2G_ID)
return true;
if ((device == BCM43236_D11N_ID) || (device == BCM43236_D11N2G_ID))
return true;
pr_err("wlc_chipmatch: unknown device id %04x\n", device);
return false;
}
void wlc_print_txdesc(d11txh_t *txh)
{
u16 mtcl = le16_to_cpu(txh->MacTxControlLow);
u16 mtch = le16_to_cpu(txh->MacTxControlHigh);
u16 mfc = le16_to_cpu(txh->MacFrameControl);
u16 tfest = le16_to_cpu(txh->TxFesTimeNormal);
u16 ptcw = le16_to_cpu(txh->PhyTxControlWord);
u16 ptcw_1 = le16_to_cpu(txh->PhyTxControlWord_1);
u16 ptcw_1_Fbr = le16_to_cpu(txh->PhyTxControlWord_1_Fbr);
u16 ptcw_1_Rts = le16_to_cpu(txh->PhyTxControlWord_1_Rts);
u16 ptcw_1_FbrRts = le16_to_cpu(txh->PhyTxControlWord_1_FbrRts);
u16 mainrates = le16_to_cpu(txh->MainRates);
u16 xtraft = le16_to_cpu(txh->XtraFrameTypes);
u8 *iv = txh->IV;
u8 *ra = txh->TxFrameRA;
u16 tfestfb = le16_to_cpu(txh->TxFesTimeFallback);
u8 *rtspfb = txh->RTSPLCPFallback;
u16 rtsdfb = le16_to_cpu(txh->RTSDurFallback);
u8 *fragpfb = txh->FragPLCPFallback;
u16 fragdfb = le16_to_cpu(txh->FragDurFallback);
u16 mmodelen = le16_to_cpu(txh->MModeLen);
u16 mmodefbrlen = le16_to_cpu(txh->MModeFbrLen);
u16 tfid = le16_to_cpu(txh->TxFrameID);
u16 txs = le16_to_cpu(txh->TxStatus);
u16 mnmpdu = le16_to_cpu(txh->MaxNMpdus);
u16 mabyte = le16_to_cpu(txh->MaxABytes_MRT);
u16 mabyte_f = le16_to_cpu(txh->MaxABytes_FBR);
u16 mmbyte = le16_to_cpu(txh->MinMBytes);
u8 *rtsph = txh->RTSPhyHeader;
struct ieee80211_rts rts = txh->rts_frame;
char hexbuf[256];
printk(KERN_DEBUG "Raw TxDesc + plcp header:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
txh, sizeof(d11txh_t) + 48);
printk(KERN_DEBUG "TxCtlLow: %04x ", mtcl);
printk(KERN_DEBUG "TxCtlHigh: %04x ", mtch);
printk(KERN_DEBUG "FC: %04x ", mfc);
printk(KERN_DEBUG "FES Time: %04x\n", tfest);
printk(KERN_DEBUG "PhyCtl: %04x%s ", ptcw,
(ptcw & PHY_TXC_SHORT_HDR) ? " short" : "");
printk(KERN_DEBUG "PhyCtl_1: %04x ", ptcw_1);
printk(KERN_DEBUG "PhyCtl_1_Fbr: %04x\n", ptcw_1_Fbr);
printk(KERN_DEBUG "PhyCtl_1_Rts: %04x ", ptcw_1_Rts);
printk(KERN_DEBUG "PhyCtl_1_Fbr_Rts: %04x\n", ptcw_1_FbrRts);
printk(KERN_DEBUG "MainRates: %04x ", mainrates);
printk(KERN_DEBUG "XtraFrameTypes: %04x ", xtraft);
printk(KERN_DEBUG "\n");
bcm_format_hex(hexbuf, iv, sizeof(txh->IV));
printk(KERN_DEBUG "SecIV: %s\n", hexbuf);
bcm_format_hex(hexbuf, ra, sizeof(txh->TxFrameRA));
printk(KERN_DEBUG "RA: %s\n", hexbuf);
printk(KERN_DEBUG "Fb FES Time: %04x ", tfestfb);
bcm_format_hex(hexbuf, rtspfb, sizeof(txh->RTSPLCPFallback));
printk(KERN_DEBUG "RTS PLCP: %s ", hexbuf);
printk(KERN_DEBUG "RTS DUR: %04x ", rtsdfb);
bcm_format_hex(hexbuf, fragpfb, sizeof(txh->FragPLCPFallback));
printk(KERN_DEBUG "PLCP: %s ", hexbuf);
printk(KERN_DEBUG "DUR: %04x", fragdfb);
printk(KERN_DEBUG "\n");
printk(KERN_DEBUG "MModeLen: %04x ", mmodelen);
printk(KERN_DEBUG "MModeFbrLen: %04x\n", mmodefbrlen);
printk(KERN_DEBUG "FrameID: %04x\n", tfid);
printk(KERN_DEBUG "TxStatus: %04x\n", txs);
printk(KERN_DEBUG "MaxNumMpdu: %04x\n", mnmpdu);
printk(KERN_DEBUG "MaxAggbyte: %04x\n", mabyte);
printk(KERN_DEBUG "MaxAggbyte_fb: %04x\n", mabyte_f);
printk(KERN_DEBUG "MinByte: %04x\n", mmbyte);
bcm_format_hex(hexbuf, rtsph, sizeof(txh->RTSPhyHeader));
printk(KERN_DEBUG "RTS PLCP: %s ", hexbuf);
bcm_format_hex(hexbuf, (u8 *) &rts, sizeof(txh->rts_frame));
printk(KERN_DEBUG "RTS Frame: %s", hexbuf);
printk(KERN_DEBUG "\n");
}
void wlc_print_rxh(d11rxhdr_t *rxh)
{
u16 len = rxh->RxFrameSize;
u16 phystatus_0 = rxh->PhyRxStatus_0;
u16 phystatus_1 = rxh->PhyRxStatus_1;
u16 phystatus_2 = rxh->PhyRxStatus_2;
u16 phystatus_3 = rxh->PhyRxStatus_3;
u16 macstatus1 = rxh->RxStatus1;
u16 macstatus2 = rxh->RxStatus2;
char flagstr[64];
char lenbuf[20];
static const bcm_bit_desc_t macstat_flags[] = {
{RXS_FCSERR, "FCSErr"},
{RXS_RESPFRAMETX, "Reply"},
{RXS_PBPRES, "PADDING"},
{RXS_DECATMPT, "DeCr"},
{RXS_DECERR, "DeCrErr"},
{RXS_BCNSENT, "Bcn"},
{0, NULL}
};
printk(KERN_DEBUG "Raw RxDesc:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, rxh, sizeof(d11rxhdr_t));
bcm_format_flags(macstat_flags, macstatus1, flagstr, 64);
snprintf(lenbuf, sizeof(lenbuf), "0x%x", len);
printk(KERN_DEBUG "RxFrameSize: %6s (%d)%s\n", lenbuf, len,
(rxh->PhyRxStatus_0 & PRXS0_SHORTH) ? " short preamble" : "");
printk(KERN_DEBUG "RxPHYStatus: %04x %04x %04x %04x\n",
phystatus_0, phystatus_1, phystatus_2, phystatus_3);
printk(KERN_DEBUG "RxMACStatus: %x %s\n", macstatus1, flagstr);
printk(KERN_DEBUG "RXMACaggtype: %x\n",
(macstatus2 & RXS_AGGTYPE_MASK));
printk(KERN_DEBUG "RxTSFTime: %04x\n", rxh->RxTSFTime);
}
int wlc_format_ssid(char *buf, const unsigned char ssid[], uint ssid_len)
{
uint i, c;
char *p = buf;
char *endp = buf + SSID_FMT_BUF_LEN;
if (ssid_len > IEEE80211_MAX_SSID_LEN)
ssid_len = IEEE80211_MAX_SSID_LEN;
for (i = 0; i < ssid_len; i++) {
c = (uint) ssid[i];
if (c == '\\') {
*p++ = '\\';
*p++ = '\\';
} else if (isprint((unsigned char) c)) {
*p++ = (char)c;
} else {
p += snprintf(p, (endp - p), "\\x%02X", c);
}
}
*p = '\0';
return (int)(p - buf);
}
static u16 wlc_rate_shm_offset(struct wlc_info *wlc, u8 rate)
{
return wlc_bmac_rate_shm_offset(wlc->hw, rate);
}
bool
wlc_prec_enq(struct wlc_info *wlc, struct pktq *q, void *pkt, int prec)
{
return wlc_prec_enq_head(wlc, q, pkt, prec, false);
}
bool
wlc_prec_enq_head(struct wlc_info *wlc, struct pktq *q, struct sk_buff *pkt,
int prec, bool head)
{
struct sk_buff *p;
int eprec = -1;
if (pktq_pfull(q, prec))
eprec = prec;
else if (pktq_full(q)) {
p = bcm_pktq_peek_tail(q, &eprec);
if (eprec > prec) {
wiphy_err(wlc->wiphy, "%s: Failing: eprec %d > prec %d"
"\n", __func__, eprec, prec);
return false;
}
}
if (eprec >= 0) {
bool discard_oldest;
discard_oldest = AC_BITMAP_TST(wlc->wme_dp, eprec);
if (eprec == prec && !discard_oldest) {
wiphy_err(wlc->wiphy, "%s: No where to go, prec == %d"
"\n", __func__, prec);
return false;
}
p = discard_oldest ? bcm_pktq_pdeq(q, eprec) :
bcm_pktq_pdeq_tail(q, eprec);
bcm_pkt_buf_free_skb(p);
}
if (head)
p = bcm_pktq_penq_head(q, prec, pkt);
else
p = bcm_pktq_penq(q, prec, pkt);
return true;
}
void wlc_txq_enq(void *ctx, struct scb *scb, struct sk_buff *sdu,
uint prec)
{
struct wlc_info *wlc = (struct wlc_info *) ctx;
struct wlc_txq_info *qi = wlc->pkt_queue;
struct pktq *q = &qi->q;
int prio;
prio = sdu->priority;
if (!wlc_prec_enq(wlc, q, sdu, prec)) {
if (!EDCF_ENAB(wlc->pub)
|| (wlc->pub->wlfeatureflag & WL_SWFL_FLOWCONTROL))
wiphy_err(wlc->wiphy, "wl%d: wlc_txq_enq: txq overflow"
"\n", wlc->pub->unit);
bcm_pkt_buf_free_skb(sdu);
}
if (!EDCF_ENAB(wlc->pub)
|| (wlc->pub->wlfeatureflag & WL_SWFL_FLOWCONTROL)) {
if (pktq_len(q) >= wlc->pub->tunables->datahiwat) {
wlc_txflowcontrol(wlc, qi, ON, ALLPRIO);
}
} else if (wlc->pub->_priofc) {
if (pktq_plen(q, wlc_prio2prec_map[prio]) >=
wlc->pub->tunables->datahiwat) {
wlc_txflowcontrol(wlc, qi, ON, prio);
}
}
}
bool
wlc_sendpkt_mac80211(struct wlc_info *wlc, struct sk_buff *sdu,
struct ieee80211_hw *hw)
{
u8 prio;
uint fifo;
void *pkt;
struct scb *scb = &global_scb;
struct ieee80211_hdr *d11_header = (struct ieee80211_hdr *)(sdu->data);
prio = ieee80211_is_data(d11_header->frame_control) ? sdu->priority :
MAXPRIO;
fifo = prio2fifo[prio];
pkt = sdu;
if (unlikely
(wlc_d11hdrs_mac80211(wlc, hw, pkt, scb, 0, 1, fifo, 0, NULL, 0)))
return -EINVAL;
wlc_txq_enq(wlc, scb, pkt, WLC_PRIO_TO_PREC(prio));
wlc_send_q(wlc);
return 0;
}
void wlc_send_q(struct wlc_info *wlc)
{
struct sk_buff *pkt[DOT11_MAXNUMFRAGS];
int prec;
u16 prec_map;
int err = 0, i, count;
uint fifo;
struct wlc_txq_info *qi = wlc->pkt_queue;
struct pktq *q = &qi->q;
struct ieee80211_tx_info *tx_info;
if (in_send_q)
return;
else
in_send_q = true;
prec_map = wlc->tx_prec_map;
while (prec_map && (pkt[0] = bcm_pktq_mdeq(q, prec_map, &prec))) {
tx_info = IEEE80211_SKB_CB(pkt[0]);
if (tx_info->flags & IEEE80211_TX_CTL_AMPDU) {
err = wlc_sendampdu(wlc->ampdu, qi, pkt, prec);
} else {
count = 1;
err = wlc_prep_pdu(wlc, pkt[0], &fifo);
if (!err) {
for (i = 0; i < count; i++) {
wlc_txfifo(wlc, fifo, pkt[i], true, 1);
}
}
}
if (err == -EBUSY) {
bcm_pktq_penq_head(q, prec, pkt[0]);
if (prec_map == wlc->tx_prec_map)
break;
prec_map = wlc->tx_prec_map;
}
}
if (!EDCF_ENAB(wlc->pub)
|| (wlc->pub->wlfeatureflag & WL_SWFL_FLOWCONTROL)) {
if (wlc_txflowcontrol_prio_isset(wlc, qi, ALLPRIO)
&& (pktq_len(q) < wlc->pub->tunables->datahiwat / 2)) {
wlc_txflowcontrol(wlc, qi, OFF, ALLPRIO);
}
} else if (wlc->pub->_priofc) {
int prio;
for (prio = MAXPRIO; prio >= 0; prio--) {
if (wlc_txflowcontrol_prio_isset(wlc, qi, prio) &&
(pktq_plen(q, wlc_prio2prec_map[prio]) <
wlc->pub->tunables->datahiwat / 2)) {
wlc_txflowcontrol(wlc, qi, OFF, prio);
}
}
}
in_send_q = false;
}
static inline u16
bcmc_fid_generate(struct wlc_info *wlc, struct wlc_bsscfg *bsscfg,
d11txh_t *txh)
{
u16 frameid;
frameid = le16_to_cpu(txh->TxFrameID) & ~(TXFID_SEQ_MASK |
TXFID_QUEUE_MASK);
frameid |=
(((wlc->
mc_fid_counter++) << TXFID_SEQ_SHIFT) & TXFID_SEQ_MASK) |
TX_BCMC_FIFO;
return frameid;
}
void
wlc_txfifo(struct wlc_info *wlc, uint fifo, struct sk_buff *p, bool commit,
s8 txpktpend)
{
u16 frameid = INVALIDFID;
d11txh_t *txh;
txh = (d11txh_t *) (p->data);
if (fifo == TX_BCMC_FIFO) {
frameid = le16_to_cpu(txh->TxFrameID);
}
if (WLC_WAR16165(wlc))
wlc_war16165(wlc, true);
if (commit) {
TXPKTPENDINC(wlc, fifo, txpktpend);
BCMMSG(wlc->wiphy, "pktpend inc %d to %d\n",
txpktpend, TXPKTPENDGET(wlc, fifo));
}
if (frameid != INVALIDFID)
BCMCFID(wlc, frameid);
if (dma_txfast(wlc->hw->di[fifo], p, commit) < 0) {
wiphy_err(wlc->wiphy, "wlc_txfifo: fatal, toss frames !!!\n");
}
}
void
wlc_compute_plcp(struct wlc_info *wlc, ratespec_t rspec, uint length, u8 *plcp)
{
if (IS_MCS(rspec)) {
wlc_compute_mimo_plcp(rspec, length, plcp);
} else if (IS_OFDM(rspec)) {
wlc_compute_ofdm_plcp(rspec, length, plcp);
} else {
wlc_compute_cck_plcp(wlc, rspec, length, plcp);
}
return;
}
static void wlc_compute_mimo_plcp(ratespec_t rspec, uint length, u8 *plcp)
{
u8 mcs = (u8) (rspec & RSPEC_RATE_MASK);
plcp[0] = mcs;
if (RSPEC_IS40MHZ(rspec) || (mcs == 32))
plcp[0] |= MIMO_PLCP_40MHZ;
WLC_SET_MIMO_PLCP_LEN(plcp, length);
plcp[3] = RSPEC_MIMOPLCP3(rspec);
plcp[3] |= 0x7;
plcp[4] = 0;
plcp[5] = 0;
}
static void
wlc_compute_ofdm_plcp(ratespec_t rspec, u32 length, u8 *plcp)
{
u8 rate_signal;
u32 tmp = 0;
int rate = RSPEC2RATE(rspec);
rate_signal = rate_info[rate] & WLC_RATE_MASK;
memset(plcp, 0, D11_PHY_HDR_LEN);
D11A_PHY_HDR_SRATE((ofdm_phy_hdr_t *) plcp, rate_signal);
tmp = (length & 0xfff) << 5;
plcp[2] |= (tmp >> 16) & 0xff;
plcp[1] |= (tmp >> 8) & 0xff;
plcp[0] |= tmp & 0xff;
return;
}
static void wlc_cck_plcp_set(struct wlc_info *wlc, int rate_500, uint length,
u8 *plcp)
{
u16 usec = 0;
u8 le = 0;
switch (rate_500) {
case WLC_RATE_1M:
usec = length << 3;
break;
case WLC_RATE_2M:
usec = length << 2;
break;
case WLC_RATE_5M5:
usec = (length << 4) / 11;
if ((length << 4) - (usec * 11) > 0)
usec++;
break;
case WLC_RATE_11M:
usec = (length << 3) / 11;
if ((length << 3) - (usec * 11) > 0) {
usec++;
if ((usec * 11) - (length << 3) >= 8)
le = D11B_PLCP_SIGNAL_LE;
}
break;
default:
wiphy_err(wlc->wiphy, "wlc_cck_plcp_set: unsupported rate %d"
"\n", rate_500);
rate_500 = WLC_RATE_1M;
usec = length << 3;
break;
}
plcp[0] = rate_500 * 5;
plcp[1] = (u8) (le | D11B_PLCP_SIGNAL_LOCKED);
plcp[2] = usec & 0xff;
plcp[3] = (usec >> 8) & 0xff;
plcp[4] = 0;
plcp[5] = 0;
}
static void wlc_compute_cck_plcp(struct wlc_info *wlc, ratespec_t rspec,
uint length, u8 *plcp)
{
int rate = RSPEC2RATE(rspec);
wlc_cck_plcp_set(wlc, rate, length, plcp);
}
static u16
wlc_compute_frame_dur(struct wlc_info *wlc, ratespec_t rate, u8 preamble_type,
uint next_frag_len)
{
u16 dur, sifs;
sifs = SIFS(wlc->band);
dur = sifs;
dur += (u16) wlc_calc_ack_time(wlc, rate, preamble_type);
if (next_frag_len) {
dur *= 2;
dur += sifs;
dur +=
(u16) wlc_calc_frame_time(wlc, rate, preamble_type,
next_frag_len);
}
return dur;
}
u16
wlc_compute_rtscts_dur(struct wlc_info *wlc, bool cts_only, ratespec_t rts_rate,
ratespec_t frame_rate, u8 rts_preamble_type,
u8 frame_preamble_type, uint frame_len, bool ba)
{
u16 dur, sifs;
sifs = SIFS(wlc->band);
if (!cts_only) {
dur = 3 * sifs;
dur +=
(u16) wlc_calc_cts_time(wlc, rts_rate,
rts_preamble_type);
} else {
dur = 2 * sifs;
}
dur +=
(u16) wlc_calc_frame_time(wlc, frame_rate, frame_preamble_type,
frame_len);
if (ba)
dur +=
(u16) wlc_calc_ba_time(wlc, frame_rate,
WLC_SHORT_PREAMBLE);
else
dur +=
(u16) wlc_calc_ack_time(wlc, frame_rate,
frame_preamble_type);
return dur;
}
u16 wlc_phytxctl1_calc(struct wlc_info *wlc, ratespec_t rspec)
{
u16 phyctl1 = 0;
u16 bw;
if (WLCISLCNPHY(wlc->band)) {
bw = PHY_TXC1_BW_20MHZ;
} else {
bw = RSPEC_GET_BW(rspec);
if (bw < PHY_TXC1_BW_20MHZ) {
wiphy_err(wlc->wiphy, "wlc_phytxctl1_calc: bw %d is "
"not supported yet, set to 20L\n", bw);
bw = PHY_TXC1_BW_20MHZ;
}
}
if (IS_MCS(rspec)) {
uint mcs = rspec & RSPEC_RATE_MASK;
phyctl1 = RSPEC_PHYTXBYTE2(rspec);
phyctl1 |= (mcs_table[mcs].tx_phy_ctl3 << 8);
} else if (IS_CCK(rspec) && !WLCISLCNPHY(wlc->band)
&& !WLCISSSLPNPHY(wlc->band)) {
phyctl1 = (bw | (RSPEC_STF(rspec) << PHY_TXC1_MODE_SHIFT));
} else {
s16 phycfg;
phycfg = wlc_rate_legacy_phyctl(RSPEC2RATE(rspec));
if (phycfg == -1) {
wiphy_err(wlc->wiphy, "wlc_phytxctl1_calc: wrong "
"legacy OFDM/CCK rate\n");
phycfg = 0;
}
phyctl1 =
(bw | (phycfg << 8) |
(RSPEC_STF(rspec) << PHY_TXC1_MODE_SHIFT));
}
return phyctl1;
}
ratespec_t
wlc_rspec_to_rts_rspec(struct wlc_info *wlc, ratespec_t rspec, bool use_rspec,
u16 mimo_ctlchbw)
{
ratespec_t rts_rspec = 0;
if (use_rspec) {
rts_rspec = rspec;
} else if (wlc->band->gmode && wlc->protection->_g && !IS_CCK(rspec)) {
rts_rspec = WLC_BASIC_RATE(wlc, WLC_RATE_11M);
} else {
rts_rspec = WLC_BASIC_RATE(wlc, rspec);
}
if (WLC_PHY_11N_CAP(wlc->band)) {
rts_rspec &= ~RSPEC_BW_MASK;
if (RSPEC_IS40MHZ(rspec) && !IS_CCK(rts_rspec))
rts_rspec |= (PHY_TXC1_BW_40MHZ_DUP << RSPEC_BW_SHIFT);
else
rts_rspec |= (mimo_ctlchbw << RSPEC_BW_SHIFT);
if (IS_OFDM(rts_rspec)) {
rts_rspec &= ~RSPEC_STF_MASK;
rts_rspec |= (wlc->stf->ss_opmode << RSPEC_STF_SHIFT);
}
}
return rts_rspec;
}
static u16
wlc_d11hdrs_mac80211(struct wlc_info *wlc, struct ieee80211_hw *hw,
struct sk_buff *p, struct scb *scb, uint frag,
uint nfrags, uint queue, uint next_frag_len,
wsec_key_t *key, ratespec_t rspec_override)
{
struct ieee80211_hdr *h;
d11txh_t *txh;
u8 *plcp, plcp_fallback[D11_PHY_HDR_LEN];
int len, phylen, rts_phylen;
u16 mch, phyctl, xfts, mainrates;
u16 seq = 0, mcl = 0, status = 0, frameid = 0;
ratespec_t rspec[2] = { WLC_RATE_1M, WLC_RATE_1M }, rts_rspec[2] = {
WLC_RATE_1M, WLC_RATE_1M};
bool use_rts = false;
bool use_cts = false;
bool use_rifs = false;
bool short_preamble[2] = { false, false };
u8 preamble_type[2] = { WLC_LONG_PREAMBLE, WLC_LONG_PREAMBLE };
u8 rts_preamble_type[2] = { WLC_LONG_PREAMBLE, WLC_LONG_PREAMBLE };
u8 *rts_plcp, rts_plcp_fallback[D11_PHY_HDR_LEN];
struct ieee80211_rts *rts = NULL;
bool qos;
uint ac;
u32 rate_val[2];
bool hwtkmic = false;
u16 mimo_ctlchbw = PHY_TXC1_BW_20MHZ;
#define ANTCFG_NONE 0xFF
u8 antcfg = ANTCFG_NONE;
u8 fbantcfg = ANTCFG_NONE;
uint phyctl1_stf = 0;
u16 durid = 0;
struct ieee80211_tx_rate *txrate[2];
int k;
struct ieee80211_tx_info *tx_info;
bool is_mcs[2];
u16 mimo_txbw;
u8 mimo_preamble_type;
h = (struct ieee80211_hdr *)(p->data);
qos = ieee80211_is_data_qos(h->frame_control);
len = bcm_pkttotlen(p);
phylen = len + FCS_LEN;
if (key) {
phylen += key->icv_len;
}
tx_info = IEEE80211_SKB_CB(p);
plcp = skb_push(p, D11_PHY_HDR_LEN);
txh = (d11txh_t *) skb_push(p, D11_TXH_LEN);
memset(txh, 0, D11_TXH_LEN);
if (tx_info->flags & IEEE80211_TX_CTL_ASSIGN_SEQ) {
if (queue == TX_BCMC_FIFO) {
wiphy_err(wlc->wiphy, "wl%d: %s: ASSERT queue == "
"TX_BCMC!\n", WLCWLUNIT(wlc), __func__);
frameid = bcmc_fid_generate(wlc, NULL, txh);
} else {
if (tx_info->flags & IEEE80211_TX_CTL_FIRST_FRAGMENT) {
SCB_SEQNUM(scb, p->priority)++;
}
seq = le16_to_cpu(seq) & FRAGNUM_MASK;
seq |= (SCB_SEQNUM(scb, p->priority) << SEQNUM_SHIFT);
h->seq_ctrl = cpu_to_le16(seq);
frameid = ((seq << TXFID_SEQ_SHIFT) & TXFID_SEQ_MASK) |
(queue & TXFID_QUEUE_MASK);
}
}
frameid |= queue & TXFID_QUEUE_MASK;
if (SCB_PS(scb) || ieee80211_is_beacon(h->frame_control))
mcl |= TXC_IGNOREPMQ;
txrate[0] = tx_info->control.rates;
txrate[1] = txrate[0] + 1;
if (txrate[1]->idx < 0) {
txrate[1] = txrate[0];
}
for (k = 0; k < hw->max_rates; k++) {
is_mcs[k] =
txrate[k]->flags & IEEE80211_TX_RC_MCS ? true : false;
if (!is_mcs[k]) {
if ((txrate[k]->idx >= 0)
&& (txrate[k]->idx <
hw->wiphy->bands[tx_info->band]->n_bitrates)) {
rate_val[k] =
hw->wiphy->bands[tx_info->band]->
bitrates[txrate[k]->idx].hw_value;
short_preamble[k] =
txrate[k]->
flags & IEEE80211_TX_RC_USE_SHORT_PREAMBLE ?
true : false;
} else {
rate_val[k] = WLC_RATE_1M;
}
} else {
rate_val[k] = txrate[k]->idx;
}
use_rts |=
txrate[k]->
flags & IEEE80211_TX_RC_USE_RTS_CTS ? true : false;
use_cts |=
txrate[k]->
flags & IEEE80211_TX_RC_USE_CTS_PROTECT ? true : false;
if (is_mcs[k])
rate_val[k] |= NRATE_MCS_INUSE;
rspec[k] = mac80211_wlc_set_nrate(wlc, wlc->band, rate_val[k]);
if (!RSPEC_ACTIVE(rspec[k])) {
rspec[k] = WLC_RATE_1M;
} else {
if (!is_multicast_ether_addr(h->addr1)) {
wlc_antsel_antcfg_get(wlc->asi, false, false, 0,
0, &antcfg, &fbantcfg);
}
}
}
phyctl1_stf = wlc->stf->ss_opmode;
if (N_ENAB(wlc->pub)) {
for (k = 0; k < hw->max_rates; k++) {
if (((IS_MCS(rspec[k]) &&
IS_SINGLE_STREAM(rspec[k] & RSPEC_RATE_MASK)) ||
IS_OFDM(rspec[k]))
&& ((rspec[k] & RSPEC_OVERRIDE_MCS_ONLY)
|| !(rspec[k] & RSPEC_OVERRIDE))) {
rspec[k] &= ~(RSPEC_STF_MASK | RSPEC_STC_MASK);
if (IS_MCS(rspec[k])
&& WLC_STF_SS_STBC_TX(wlc, scb)) {
u8 stc;
stc = 1;
rspec[k] |=
(PHY_TXC1_MODE_STBC <<
RSPEC_STF_SHIFT) | (stc <<
RSPEC_STC_SHIFT);
} else
rspec[k] |=
(phyctl1_stf << RSPEC_STF_SHIFT);
}
if (CHSPEC_WLC_BW(wlc->chanspec) == WLC_40_MHZ) {
mimo_ctlchbw = mimo_txbw =
CHSPEC_SB_UPPER(WLC_BAND_PI_RADIO_CHANSPEC)
? PHY_TXC1_BW_20MHZ_UP : PHY_TXC1_BW_20MHZ;
if (IS_MCS(rspec[k])) {
if ((rspec[k] & RSPEC_RATE_MASK) == 32) {
mimo_txbw =
PHY_TXC1_BW_40MHZ_DUP;
} else if (wlc->mimo_40txbw != AUTO)
mimo_txbw = wlc->mimo_40txbw;
else if (scb->flags & SCB_IS40)
mimo_txbw = PHY_TXC1_BW_40MHZ;
} else if (IS_OFDM(rspec[k])) {
if (wlc->ofdm_40txbw != AUTO)
mimo_txbw = wlc->ofdm_40txbw;
} else {
if (wlc->cck_40txbw != AUTO)
mimo_txbw = wlc->cck_40txbw;
}
} else {
if ((rspec[k] & RSPEC_RATE_MASK) == 32) {
rspec[k] = RSPEC_MIMORATE;
}
mimo_txbw = PHY_TXC1_BW_20MHZ;
}
rspec[k] &= ~RSPEC_BW_MASK;
if ((k == 0) || ((k > 0) && IS_MCS(rspec[k])))
rspec[k] |= (mimo_txbw << RSPEC_BW_SHIFT);
else
rspec[k] |= (mimo_ctlchbw << RSPEC_BW_SHIFT);
#ifdef NOSGIYET
if (IS_MCS(rspec[k])
&& (txrate[k]->flags & IEEE80211_TX_RC_SHORT_GI))
rspec[k] |= RSPEC_SHORT_GI;
else if (!(txrate[k]->flags & IEEE80211_TX_RC_SHORT_GI))
rspec[k] &= ~RSPEC_SHORT_GI;
#else
rspec[k] &= ~RSPEC_SHORT_GI;
#endif
mimo_preamble_type = WLC_MM_PREAMBLE;
if (txrate[k]->flags & IEEE80211_TX_RC_GREEN_FIELD)
mimo_preamble_type = WLC_GF_PREAMBLE;
if ((txrate[k]->flags & IEEE80211_TX_RC_MCS)
&& (!IS_MCS(rspec[k]))) {
wiphy_err(wlc->wiphy, "wl%d: %s: IEEE80211_TX_"
"RC_MCS != IS_MCS(rspec)\n",
WLCWLUNIT(wlc), __func__);
}
if (IS_MCS(rspec[k])) {
preamble_type[k] = mimo_preamble_type;
if ((rspec[k] & RSPEC_SHORT_GI)
&& IS_SINGLE_STREAM(rspec[k] &
RSPEC_RATE_MASK)) {
preamble_type[k] = WLC_MM_PREAMBLE;
}
}
if (!IS_MCS(rspec[0])
&& (tx_info->control.rates[0].
flags & IEEE80211_TX_RC_USE_SHORT_PREAMBLE))
preamble_type[k] = WLC_SHORT_PREAMBLE;
}
} else {
for (k = 0; k < hw->max_rates; k++) {
rspec[k] &= ~RSPEC_BW_MASK;
rspec[k] |= (PHY_TXC1_BW_20MHZ << RSPEC_BW_SHIFT);
if (WLCISNPHY(wlc->band) && IS_OFDM(rspec[k])) {
rspec[k] &= ~RSPEC_STF_MASK;
rspec[k] |= phyctl1_stf << RSPEC_STF_SHIFT;
}
}
}
txrate[0]->count = 0;
txrate[1]->count = 0;
if ((ieee80211_is_data(h->frame_control) ||
ieee80211_is_mgmt(h->frame_control)) &&
(phylen > wlc->RTSThresh) && !is_multicast_ether_addr(h->addr1))
use_rts = true;
wlc_compute_plcp(wlc, rspec[0], phylen, plcp);
wlc_compute_plcp(wlc, rspec[1], phylen, plcp_fallback);
memcpy(&txh->FragPLCPFallback,
plcp_fallback, sizeof(txh->FragPLCPFallback));
if (IS_CCK(rspec[1])) {
txh->FragPLCPFallback[4] = phylen & 0xff;
txh->FragPLCPFallback[5] = (phylen & 0xff00) >> 8;
}
mainrates =
IS_OFDM(rspec[0]) ? D11A_PHY_HDR_GRATE((ofdm_phy_hdr_t *) plcp) :
plcp[0];
if (!ieee80211_is_pspoll(h->frame_control) &&
!is_multicast_ether_addr(h->addr1) && !use_rifs) {
durid =
wlc_compute_frame_dur(wlc, rspec[0], preamble_type[0],
next_frag_len);
h->duration_id = cpu_to_le16(durid);
} else if (use_rifs) {
durid =
(u16) wlc_calc_frame_time(wlc, rspec[0],
preamble_type[0],
DOT11_MAX_FRAG_LEN);
durid += RIFS_11N_TIME;
h->duration_id = cpu_to_le16(durid);
}
if (ieee80211_is_pspoll(h->frame_control))
txh->FragDurFallback = h->duration_id;
else if (is_multicast_ether_addr(h->addr1) || use_rifs)
txh->FragDurFallback = 0;
else {
durid = wlc_compute_frame_dur(wlc, rspec[1],
preamble_type[1], next_frag_len);
txh->FragDurFallback = cpu_to_le16(durid);
}
if (frag == 0)
mcl |= TXC_STARTMSDU;
if (!is_multicast_ether_addr(h->addr1))
mcl |= TXC_IMMEDACK;
if (BAND_5G(wlc->band->bandtype))
mcl |= TXC_FREQBAND_5G;
if (CHSPEC_IS40(WLC_BAND_PI_RADIO_CHANSPEC))
mcl |= TXC_BW_40;
if (hwtkmic)
mcl |= TXC_AMIC;
txh->MacTxControlLow = cpu_to_le16(mcl);
mch = 0;
if ((preamble_type[1] == WLC_SHORT_PREAMBLE) ||
(preamble_type[1] == WLC_GF_PREAMBLE)) {
if (RSPEC2RATE(rspec[1]) != WLC_RATE_1M)
mch |= TXC_PREAMBLE_DATA_FB_SHORT;
}
memcpy(&txh->MacFrameControl, &h->frame_control, sizeof(u16));
txh->TxFesTimeNormal = cpu_to_le16(0);
txh->TxFesTimeFallback = cpu_to_le16(0);
memcpy(&txh->TxFrameRA, &h->addr1, ETH_ALEN);
txh->TxFrameID = cpu_to_le16(frameid);
txh->TxStatus = cpu_to_le16(status);
txh->MaxNMpdus = cpu_to_le16(0);
txh->MaxABytes_MRT = cpu_to_le16(0);
txh->MaxABytes_FBR = cpu_to_le16(0);
txh->MinMBytes = cpu_to_le16(0);
if (use_rts || use_cts) {
if (use_rts && use_cts)
use_cts = false;
for (k = 0; k < 2; k++) {
rts_rspec[k] = wlc_rspec_to_rts_rspec(wlc, rspec[k],
false,
mimo_ctlchbw);
}
if (!IS_OFDM(rts_rspec[0]) &&
!((RSPEC2RATE(rts_rspec[0]) == WLC_RATE_1M) ||
(wlc->PLCPHdr_override == WLC_PLCP_LONG))) {
rts_preamble_type[0] = WLC_SHORT_PREAMBLE;
mch |= TXC_PREAMBLE_RTS_MAIN_SHORT;
}
if (!IS_OFDM(rts_rspec[1]) &&
!((RSPEC2RATE(rts_rspec[1]) == WLC_RATE_1M) ||
(wlc->PLCPHdr_override == WLC_PLCP_LONG))) {
rts_preamble_type[1] = WLC_SHORT_PREAMBLE;
mch |= TXC_PREAMBLE_RTS_FB_SHORT;
}
if (use_cts) {
txh->MacTxControlLow |= cpu_to_le16(TXC_SENDCTS);
} else {
txh->MacTxControlLow |= cpu_to_le16(TXC_SENDRTS);
txh->MacTxControlLow |= cpu_to_le16(TXC_LONGFRAME);
}
rts_plcp = txh->RTSPhyHeader;
if (use_cts)
rts_phylen = DOT11_CTS_LEN + FCS_LEN;
else
rts_phylen = DOT11_RTS_LEN + FCS_LEN;
wlc_compute_plcp(wlc, rts_rspec[0], rts_phylen, rts_plcp);
wlc_compute_plcp(wlc, rts_rspec[1], rts_phylen,
rts_plcp_fallback);
memcpy(&txh->RTSPLCPFallback, rts_plcp_fallback,
sizeof(txh->RTSPLCPFallback));
rts = (struct ieee80211_rts *)&txh->rts_frame;
durid = wlc_compute_rtscts_dur(wlc, use_cts, rts_rspec[0],
rspec[0], rts_preamble_type[0],
preamble_type[0], phylen, false);
rts->duration = cpu_to_le16(durid);
durid = wlc_compute_rtscts_dur(wlc, use_cts,
rts_rspec[1], rspec[1],
rts_preamble_type[1],
preamble_type[1], phylen, false);
txh->RTSDurFallback = cpu_to_le16(durid);
if (use_cts) {
rts->frame_control = cpu_to_le16(IEEE80211_FTYPE_CTL |
IEEE80211_STYPE_CTS);
memcpy(&rts->ra, &h->addr2, ETH_ALEN);
} else {
rts->frame_control = cpu_to_le16(IEEE80211_FTYPE_CTL |
IEEE80211_STYPE_RTS);
memcpy(&rts->ra, &h->addr1, 2 * ETH_ALEN);
}
mainrates |= (IS_OFDM(rts_rspec[0]) ?
D11A_PHY_HDR_GRATE((ofdm_phy_hdr_t *) rts_plcp) :
rts_plcp[0]) << 8;
} else {
memset((char *)txh->RTSPhyHeader, 0, D11_PHY_HDR_LEN);
memset((char *)&txh->rts_frame, 0,
sizeof(struct ieee80211_rts));
memset((char *)txh->RTSPLCPFallback, 0,
sizeof(txh->RTSPLCPFallback));
txh->RTSDurFallback = 0;
}
#ifdef SUPPORT_40MHZ
if ((tx_info->flags & IEEE80211_TX_CTL_AMPDU) && IS_MCS(rspec)) {
txh->RTSPLCPFallback[AMPDU_FBR_NULL_DELIM] =
wlc_ampdu_null_delim_cnt(wlc->ampdu, scb, rspec, phylen);
}
#endif
txh->MacTxControlHigh = cpu_to_le16(mch);
txh->MainRates = cpu_to_le16(mainrates);
xfts = FRAMETYPE(rspec[1], wlc->mimoft);
xfts |= (FRAMETYPE(rts_rspec[0], wlc->mimoft) << XFTS_RTS_FT_SHIFT);
xfts |= (FRAMETYPE(rts_rspec[1], wlc->mimoft) << XFTS_FBRRTS_FT_SHIFT);
xfts |=
CHSPEC_CHANNEL(WLC_BAND_PI_RADIO_CHANSPEC) << XFTS_CHANNEL_SHIFT;
txh->XtraFrameTypes = cpu_to_le16(xfts);
phyctl = FRAMETYPE(rspec[0], wlc->mimoft);
if ((preamble_type[0] == WLC_SHORT_PREAMBLE) ||
(preamble_type[0] == WLC_GF_PREAMBLE)) {
if (RSPEC2RATE(rspec[0]) != WLC_RATE_1M)
phyctl |= PHY_TXC_SHORT_HDR;
}
phyctl |= wlc_stf_d11hdrs_phyctl_txant(wlc, rspec[0]);
txh->PhyTxControlWord = cpu_to_le16(phyctl);
if (WLC_PHY_11N_CAP(wlc->band)) {
u16 phyctl1 = 0;
phyctl1 = wlc_phytxctl1_calc(wlc, rspec[0]);
txh->PhyTxControlWord_1 = cpu_to_le16(phyctl1);
phyctl1 = wlc_phytxctl1_calc(wlc, rspec[1]);
txh->PhyTxControlWord_1_Fbr = cpu_to_le16(phyctl1);
if (use_rts || use_cts) {
phyctl1 = wlc_phytxctl1_calc(wlc, rts_rspec[0]);
txh->PhyTxControlWord_1_Rts = cpu_to_le16(phyctl1);
phyctl1 = wlc_phytxctl1_calc(wlc, rts_rspec[1]);
txh->PhyTxControlWord_1_FbrRts = cpu_to_le16(phyctl1);
}
if (IS_MCS(rspec[0]) && (preamble_type[0] == WLC_MM_PREAMBLE)) {
u16 mmodelen =
wlc_calc_lsig_len(wlc, rspec[0], phylen);
txh->MModeLen = cpu_to_le16(mmodelen);
}
if (IS_MCS(rspec[1]) && (preamble_type[1] == WLC_MM_PREAMBLE)) {
u16 mmodefbrlen =
wlc_calc_lsig_len(wlc, rspec[1], phylen);
txh->MModeFbrLen = cpu_to_le16(mmodefbrlen);
}
}
ac = skb_get_queue_mapping(p);
if (SCB_WME(scb) && qos && wlc->edcf_txop[ac]) {
uint frag_dur, dur, dur_fallback;
if ((!(tx_info->flags & IEEE80211_TX_CTL_AMPDU)) && (frag == 0)) {
frag_dur =
wlc_calc_frame_time(wlc, rspec[0], preamble_type[0],
phylen);
if (rts) {
dur =
wlc_calc_cts_time(wlc, rts_rspec[0],
rts_preamble_type[0]);
dur_fallback =
wlc_calc_cts_time(wlc, rts_rspec[1],
rts_preamble_type[1]);
dur += le16_to_cpu(rts->duration);
dur_fallback +=
le16_to_cpu(txh->RTSDurFallback);
} else if (use_rifs) {
dur = frag_dur;
dur_fallback = 0;
} else {
dur = frag_dur;
dur +=
wlc_compute_frame_dur(wlc, rspec[0],
preamble_type[0], 0);
dur_fallback =
wlc_calc_frame_time(wlc, rspec[1],
preamble_type[1],
phylen);
dur_fallback +=
wlc_compute_frame_dur(wlc, rspec[1],
preamble_type[1], 0);
}
txh->TxFesTimeNormal = cpu_to_le16((u16) dur);
txh->TxFesTimeFallback =
cpu_to_le16((u16) dur_fallback);
if (wlc->edcf_txop[ac] >= (dur - frag_dur)) {
{
uint newfragthresh;
newfragthresh =
wlc_calc_frame_len(wlc, rspec[0],
preamble_type[0],
(wlc->
edcf_txop[ac] -
(dur -
frag_dur)));
if (newfragthresh < DOT11_MIN_FRAG_LEN)
newfragthresh =
DOT11_MIN_FRAG_LEN;
else if (newfragthresh >
wlc->usr_fragthresh)
newfragthresh =
wlc->usr_fragthresh;
if (wlc->fragthresh[queue] !=
(u16) newfragthresh) {
wlc->fragthresh[queue] =
(u16) newfragthresh;
}
}
} else
wiphy_err(wlc->wiphy, "wl%d: %s txop invalid "
"for rate %d\n",
wlc->pub->unit, fifo_names[queue],
RSPEC2RATE(rspec[0]));
if (dur > wlc->edcf_txop[ac])
wiphy_err(wlc->wiphy, "wl%d: %s: %s txop "
"exceeded phylen %d/%d dur %d/%d\n",
wlc->pub->unit, __func__,
fifo_names[queue],
phylen, wlc->fragthresh[queue],
dur, wlc->edcf_txop[ac]);
}
}
return 0;
}
void wlc_tbtt(struct wlc_info *wlc, d11regs_t *regs)
{
struct wlc_bsscfg *cfg = wlc->cfg;
if (BSSCFG_STA(cfg)) {
if (WLC_WATCHDOG_TBTT(wlc)) {
u32 cur, delta;
if (wlc->WDarmed) {
wl_del_timer(wlc->wl, wlc->wdtimer);
wlc->WDarmed = false;
}
cur = OSL_SYSUPTIME();
delta = cur > wlc->WDlast ? cur - wlc->WDlast :
(u32) ~0 - wlc->WDlast + cur + 1;
if (delta >= TIMER_INTERVAL_WATCHDOG) {
wlc_watchdog((void *)wlc);
wlc->WDlast = cur;
}
wl_add_timer(wlc->wl, wlc->wdtimer,
wlc_watchdog_backup_bi(wlc), true);
wlc->WDarmed = true;
}
}
if (!cfg->BSS) {
wlc->qvalid |= MCMD_DIRFRMQVAL;
}
}
static void wlc_war16165(struct wlc_info *wlc, bool tx)
{
if (tx) {
if (wlc->txpend16165war++ == 0)
wlc_set_ps_ctrl(wlc);
} else {
wlc->txpend16165war--;
if (wlc->txpend16165war == 0)
wlc_set_ps_ctrl(wlc);
}
}
bool
wlc_dotxstatus(struct wlc_info *wlc, tx_status_t *txs, u32 frm_tx2)
{
struct sk_buff *p;
uint queue;
d11txh_t *txh;
struct scb *scb = NULL;
bool free_pdu;
int tx_rts, tx_frame_count, tx_rts_count;
uint totlen, supr_status;
bool lastframe;
struct ieee80211_hdr *h;
u16 mcl;
struct ieee80211_tx_info *tx_info;
struct ieee80211_tx_rate *txrate;
int i;
(void)(frm_tx2);
if (!(txs->status & TX_STATUS_AMPDU)
&& (txs->status & TX_STATUS_INTERMEDIATE)) {
wiphy_err(wlc->wiphy, "%s: INTERMEDIATE but not AMPDU\n",
__func__);
return false;
}
queue = txs->frameid & TXFID_QUEUE_MASK;
if (queue >= NFIFO) {
p = NULL;
goto fatal;
}
p = GETNEXTTXP(wlc, queue);
if (WLC_WAR16165(wlc))
wlc_war16165(wlc, false);
if (p == NULL)
goto fatal;
txh = (d11txh_t *) (p->data);
mcl = le16_to_cpu(txh->MacTxControlLow);
if (txs->phyerr) {
if (WL_ERROR_ON()) {
wiphy_err(wlc->wiphy, "phyerr 0x%x, rate 0x%x\n",
txs->phyerr, txh->MainRates);
wlc_print_txdesc(txh);
}
wlc_print_txstatus(txs);
}
if (txs->frameid != cpu_to_le16(txh->TxFrameID))
goto fatal;
tx_info = IEEE80211_SKB_CB(p);
h = (struct ieee80211_hdr *)((u8 *) (txh + 1) + D11_PHY_HDR_LEN);
if (tx_info->control.sta)
scb = (struct scb *)tx_info->control.sta->drv_priv;
if (tx_info->flags & IEEE80211_TX_CTL_AMPDU) {
wlc_ampdu_dotxstatus(wlc->ampdu, scb, p, txs);
return false;
}
supr_status = txs->status & TX_STATUS_SUPR_MASK;
if (supr_status == TX_STATUS_SUPR_BADCH)
BCMMSG(wlc->wiphy,
"%s: Pkt tx suppressed, possibly channel %d\n",
__func__, CHSPEC_CHANNEL(wlc->default_bss->chanspec));
tx_rts = cpu_to_le16(txh->MacTxControlLow) & TXC_SENDRTS;
tx_frame_count =
(txs->status & TX_STATUS_FRM_RTX_MASK) >> TX_STATUS_FRM_RTX_SHIFT;
tx_rts_count =
(txs->status & TX_STATUS_RTS_RTX_MASK) >> TX_STATUS_RTS_RTX_SHIFT;
lastframe = !ieee80211_has_morefrags(h->frame_control);
if (!lastframe) {
wiphy_err(wlc->wiphy, "Not last frame!\n");
} else {
u16 sfbl, lfbl;
ieee80211_tx_info_clear_status(tx_info);
if (queue < AC_COUNT) {
sfbl = WLC_WME_RETRY_SFB_GET(wlc, wme_fifo2ac[queue]);
lfbl = WLC_WME_RETRY_LFB_GET(wlc, wme_fifo2ac[queue]);
} else {
sfbl = wlc->SFBL;
lfbl = wlc->LFBL;
}
txrate = tx_info->status.rates;
if ((tx_frame_count > sfbl) && (txrate[1].idx >= 0)) {
txrate->count = lfbl;
txrate[1].count = tx_frame_count - lfbl;
} else {
txrate->count = tx_frame_count;
txrate[1].idx = -1;
txrate[1].count = 0;
}
for (i = 2; i < IEEE80211_TX_MAX_RATES; i++) {
txrate[i].idx = -1;
txrate[i].count = 0;
}
if (txs->status & TX_STATUS_ACK_RCV)
tx_info->flags |= IEEE80211_TX_STAT_ACK;
}
totlen = bcm_pkttotlen(p);
free_pdu = true;
wlc_txfifo_complete(wlc, queue, 1);
if (lastframe) {
p->next = NULL;
p->prev = NULL;
wlc->txretried = 0;
skb_pull(p, D11_PHY_HDR_LEN);
skb_pull(p, D11_TXH_LEN);
ieee80211_tx_status_irqsafe(wlc->pub->ieee_hw, p);
} else {
wiphy_err(wlc->wiphy, "%s: Not last frame => not calling "
"tx_status\n", __func__);
}
return false;
fatal:
if (p)
bcm_pkt_buf_free_skb(p);
return true;
}
void
wlc_txfifo_complete(struct wlc_info *wlc, uint fifo, s8 txpktpend)
{
TXPKTPENDDEC(wlc, fifo, txpktpend);
BCMMSG(wlc->wiphy, "pktpend dec %d to %d\n", txpktpend,
TXPKTPENDGET(wlc, fifo));
WLC_TX_FIFO_ENAB(wlc, fifo);
if (!TXPKTPENDTOT(wlc)) {
if (wlc->block_datafifo & DATA_BLOCK_TX_SUPR)
wlc_bsscfg_tx_check(wlc);
}
if (AP_ENAB(wlc->pub) &&
wlc->bcmcfifo_drain && !TXPKTPENDGET(wlc, TX_BCMC_FIFO)) {
wlc->bcmcfifo_drain = false;
wlc_mhf(wlc, MHF2, MHF2_TXBCMC_NOW, 0, WLC_BAND_AUTO);
}
}
void wlc_bcn_li_upd(struct wlc_info *wlc)
{
if (AP_ENAB(wlc->pub))
return;
if (wlc->bcn_li_dtim == 1)
wlc_write_shm(wlc, M_BCN_LI, 0);
else
wlc_write_shm(wlc, M_BCN_LI,
(wlc->bcn_li_dtim << 8) | wlc->bcn_li_bcn);
}
static u64 wlc_recover_tsf64(struct wlc_info *wlc, struct wlc_d11rxhdr *rxh)
{
u32 tsf_h, tsf_l;
u16 rx_tsf_0_15, rx_tsf_16_31;
wlc_bmac_read_tsf(wlc->hw, &tsf_l, &tsf_h);
rx_tsf_16_31 = (u16)(tsf_l >> 16);
rx_tsf_0_15 = rxh->rxhdr.RxTSFTime;
if ((u16)tsf_l < rx_tsf_0_15) {
rx_tsf_16_31 -= 1;
if (rx_tsf_16_31 == 0xffff)
tsf_h -= 1;
}
return ((u64)tsf_h << 32) | (((u32)rx_tsf_16_31 << 16) + rx_tsf_0_15);
}
static void
prep_mac80211_status(struct wlc_info *wlc, d11rxhdr_t *rxh, struct sk_buff *p,
struct ieee80211_rx_status *rx_status)
{
wlc_d11rxhdr_t *wlc_rxh = (wlc_d11rxhdr_t *) rxh;
int preamble;
int channel;
ratespec_t rspec;
unsigned char *plcp;
rx_status->mactime = wlc_recover_tsf64(wlc, wlc_rxh);
rx_status->flag |= RX_FLAG_MACTIME_MPDU;
channel = WLC_CHAN_CHANNEL(rxh->RxChan);
if (channel > 14) {
rx_status->band = IEEE80211_BAND_5GHZ;
rx_status->freq = ieee80211_ofdm_chan_to_freq(
WF_CHAN_FACTOR_5_G/2, channel);
} else {
rx_status->band = IEEE80211_BAND_2GHZ;
rx_status->freq = ieee80211_dsss_chan_to_freq(channel);
}
rx_status->signal = wlc_rxh->rssi;
rx_status->antenna = (rxh->PhyRxStatus_0 & PRXS0_RXANT_UPSUBBAND) ? 1 : 0;
plcp = p->data;
rspec = wlc_compute_rspec(rxh, plcp);
if (IS_MCS(rspec)) {
rx_status->rate_idx = rspec & RSPEC_RATE_MASK;
rx_status->flag |= RX_FLAG_HT;
if (RSPEC_IS40MHZ(rspec))
rx_status->flag |= RX_FLAG_40MHZ;
} else {
switch (RSPEC2RATE(rspec)) {
case WLC_RATE_1M:
rx_status->rate_idx = 0;
break;
case WLC_RATE_2M:
rx_status->rate_idx = 1;
break;
case WLC_RATE_5M5:
rx_status->rate_idx = 2;
break;
case WLC_RATE_11M:
rx_status->rate_idx = 3;
break;
case WLC_RATE_6M:
rx_status->rate_idx = 4;
break;
case WLC_RATE_9M:
rx_status->rate_idx = 5;
break;
case WLC_RATE_12M:
rx_status->rate_idx = 6;
break;
case WLC_RATE_18M:
rx_status->rate_idx = 7;
break;
case WLC_RATE_24M:
rx_status->rate_idx = 8;
break;
case WLC_RATE_36M:
rx_status->rate_idx = 9;
break;
case WLC_RATE_48M:
rx_status->rate_idx = 10;
break;
case WLC_RATE_54M:
rx_status->rate_idx = 11;
break;
default:
wiphy_err(wlc->wiphy, "%s: Unknown rate\n", __func__);
}
preamble = 0;
if (IS_CCK(rspec)) {
if (rxh->PhyRxStatus_0 & PRXS0_SHORTH)
rx_status->flag |= RX_FLAG_SHORTPRE;
} else if (IS_OFDM(rspec)) {
rx_status->flag |= RX_FLAG_SHORTPRE;
} else {
wiphy_err(wlc->wiphy, "%s: Unknown modulation\n",
__func__);
}
}
if (PLCP3_ISSGI(plcp[3]))
rx_status->flag |= RX_FLAG_SHORT_GI;
if (rxh->RxStatus1 & RXS_DECERR) {
rx_status->flag |= RX_FLAG_FAILED_PLCP_CRC;
wiphy_err(wlc->wiphy, "%s: RX_FLAG_FAILED_PLCP_CRC\n",
__func__);
}
if (rxh->RxStatus1 & RXS_FCSERR) {
rx_status->flag |= RX_FLAG_FAILED_FCS_CRC;
wiphy_err(wlc->wiphy, "%s: RX_FLAG_FAILED_FCS_CRC\n",
__func__);
}
}
static void
wlc_recvctl(struct wlc_info *wlc, d11rxhdr_t *rxh, struct sk_buff *p)
{
int len_mpdu;
struct ieee80211_rx_status rx_status;
memset(&rx_status, 0, sizeof(rx_status));
prep_mac80211_status(wlc, rxh, p, &rx_status);
len_mpdu = p->len - D11_PHY_HDR_LEN - FCS_LEN;
skb_pull(p, D11_PHY_HDR_LEN);
__skb_trim(p, len_mpdu);
memcpy(IEEE80211_SKB_RXCB(p), &rx_status, sizeof(rx_status));
ieee80211_rx_irqsafe(wlc->pub->ieee_hw, p);
return;
}
void wlc_recv(struct wlc_info *wlc, struct sk_buff *p)
{
d11rxhdr_t *rxh;
struct ieee80211_hdr *h;
uint len;
bool is_amsdu;
BCMMSG(wlc->wiphy, "wl%d\n", wlc->pub->unit);
rxh = (d11rxhdr_t *) (p->data);
skb_pull(p, wlc->hwrxoff);
rxh->RxFrameSize = le16_to_cpu(rxh->RxFrameSize);
rxh->PhyRxStatus_0 = le16_to_cpu(rxh->PhyRxStatus_0);
rxh->PhyRxStatus_1 = le16_to_cpu(rxh->PhyRxStatus_1);
rxh->PhyRxStatus_2 = le16_to_cpu(rxh->PhyRxStatus_2);
rxh->PhyRxStatus_3 = le16_to_cpu(rxh->PhyRxStatus_3);
rxh->PhyRxStatus_4 = le16_to_cpu(rxh->PhyRxStatus_4);
rxh->PhyRxStatus_5 = le16_to_cpu(rxh->PhyRxStatus_5);
rxh->RxStatus1 = le16_to_cpu(rxh->RxStatus1);
rxh->RxStatus2 = le16_to_cpu(rxh->RxStatus2);
rxh->RxTSFTime = le16_to_cpu(rxh->RxTSFTime);
rxh->RxChan = le16_to_cpu(rxh->RxChan);
if (rxh->RxStatus1 & RXS_PBPRES) {
if (p->len < 2) {
wiphy_err(wlc->wiphy, "wl%d: wlc_recv: rcvd runt of "
"len %d\n", wlc->pub->unit, p->len);
goto toss;
}
skb_pull(p, 2);
}
h = (struct ieee80211_hdr *)(p->data + D11_PHY_HDR_LEN);
len = p->len;
if (rxh->RxStatus1 & RXS_FCSERR) {
if (wlc->pub->mac80211_state & MAC80211_PROMISC_BCNS) {
wiphy_err(wlc->wiphy, "FCSERR while scanning******* -"
" tossing\n");
goto toss;
} else {
wiphy_err(wlc->wiphy, "RCSERR!!!\n");
goto toss;
}
}
if (len < D11_PHY_HDR_LEN + sizeof(h->frame_control)) {
goto toss;
}
is_amsdu = rxh->RxStatus2 & RXS_AMSDU_MASK;
if (!is_amsdu) {
if (ieee80211_is_data(h->frame_control) ||
ieee80211_is_mgmt(h->frame_control)) {
if ((is_zero_ether_addr(h->addr2) ||
is_multicast_ether_addr(h->addr2))) {
wiphy_err(wlc->wiphy, "wl%d: %s: dropping a "
"frame with invalid src mac address,"
" a2: %pM\n",
wlc->pub->unit, __func__, h->addr2);
goto toss;
}
}
}
if (ieee80211_is_probe_req(h->frame_control))
goto toss;
if (is_amsdu)
goto toss;
wlc_recvctl(wlc, rxh, p);
return;
toss:
bcm_pkt_buf_free_skb(p);
}
u16
wlc_calc_lsig_len(struct wlc_info *wlc, ratespec_t ratespec, uint mac_len)
{
uint nsyms, len = 0, kNdps;
BCMMSG(wlc->wiphy, "wl%d: rate %d, len%d\n",
wlc->pub->unit, RSPEC2RATE(ratespec), mac_len);
if (IS_MCS(ratespec)) {
uint mcs = ratespec & RSPEC_RATE_MASK;
int tot_streams = (MCS_TXS(mcs) + 1) + RSPEC_STC(ratespec);
kNdps =
MCS_RATE(mcs, RSPEC_IS40MHZ(ratespec),
RSPEC_ISSGI(ratespec)) * 4;
if (RSPEC_STC(ratespec) == 0)
nsyms =
CEIL((APHY_SERVICE_NBITS + 8 * mac_len +
APHY_TAIL_NBITS) * 1000, kNdps);
else
nsyms =
2 *
CEIL((APHY_SERVICE_NBITS + 8 * mac_len +
APHY_TAIL_NBITS) * 1000, 2 * kNdps);
nsyms += (tot_streams + 3);
len = (3 * nsyms) - 3;
}
return (u16) len;
}
uint
wlc_calc_frame_time(struct wlc_info *wlc, ratespec_t ratespec, u8 preamble_type,
uint mac_len)
{
uint nsyms, dur = 0, Ndps, kNdps;
uint rate = RSPEC2RATE(ratespec);
if (rate == 0) {
wiphy_err(wlc->wiphy, "wl%d: WAR: using rate of 1 mbps\n",
wlc->pub->unit);
rate = WLC_RATE_1M;
}
BCMMSG(wlc->wiphy, "wl%d: rspec 0x%x, preamble_type %d, len%d\n",
wlc->pub->unit, ratespec, preamble_type, mac_len);
if (IS_MCS(ratespec)) {
uint mcs = ratespec & RSPEC_RATE_MASK;
int tot_streams = MCS_TXS(mcs) + RSPEC_STC(ratespec);
dur = PREN_PREAMBLE + (tot_streams * PREN_PREAMBLE_EXT);
if (preamble_type == WLC_MM_PREAMBLE)
dur += PREN_MM_EXT;
kNdps =
MCS_RATE(mcs, RSPEC_IS40MHZ(ratespec),
RSPEC_ISSGI(ratespec)) * 4;
if (RSPEC_STC(ratespec) == 0)
nsyms =
CEIL((APHY_SERVICE_NBITS + 8 * mac_len +
APHY_TAIL_NBITS) * 1000, kNdps);
else
nsyms =
2 *
CEIL((APHY_SERVICE_NBITS + 8 * mac_len +
APHY_TAIL_NBITS) * 1000, 2 * kNdps);
dur += APHY_SYMBOL_TIME * nsyms;
if (BAND_2G(wlc->band->bandtype))
dur += DOT11_OFDM_SIGNAL_EXTENSION;
} else if (IS_OFDM(rate)) {
dur = APHY_PREAMBLE_TIME;
dur += APHY_SIGNAL_TIME;
Ndps = rate * 2;
nsyms =
CEIL((APHY_SERVICE_NBITS + 8 * mac_len + APHY_TAIL_NBITS),
Ndps);
dur += APHY_SYMBOL_TIME * nsyms;
if (BAND_2G(wlc->band->bandtype))
dur += DOT11_OFDM_SIGNAL_EXTENSION;
} else {
mac_len = mac_len * 8 * 2;
dur = (mac_len + rate - 1) / rate;
if (preamble_type & WLC_SHORT_PREAMBLE)
dur += BPHY_PLCP_SHORT_TIME;
else
dur += BPHY_PLCP_TIME;
}
return dur;
}
static uint
wlc_calc_frame_len(struct wlc_info *wlc, ratespec_t ratespec, u8 preamble_type,
uint dur)
{
uint nsyms, mac_len, Ndps, kNdps;
uint rate = RSPEC2RATE(ratespec);
BCMMSG(wlc->wiphy, "wl%d: rspec 0x%x, preamble_type %d, dur %d\n",
wlc->pub->unit, ratespec, preamble_type, dur);
if (IS_MCS(ratespec)) {
uint mcs = ratespec & RSPEC_RATE_MASK;
int tot_streams = MCS_TXS(mcs) + RSPEC_STC(ratespec);
dur -= PREN_PREAMBLE + (tot_streams * PREN_PREAMBLE_EXT);
if (BAND_2G(wlc->band->bandtype))
dur -= DOT11_OFDM_SIGNAL_EXTENSION;
kNdps =
MCS_RATE(mcs, RSPEC_IS40MHZ(ratespec),
RSPEC_ISSGI(ratespec)) * 4;
nsyms = dur / APHY_SYMBOL_TIME;
mac_len =
((nsyms * kNdps) -
((APHY_SERVICE_NBITS + APHY_TAIL_NBITS) * 1000)) / 8000;
} else if (IS_OFDM(ratespec)) {
dur -= APHY_PREAMBLE_TIME;
dur -= APHY_SIGNAL_TIME;
Ndps = rate * 2;
nsyms = dur / APHY_SYMBOL_TIME;
mac_len =
((nsyms * Ndps) -
(APHY_SERVICE_NBITS + APHY_TAIL_NBITS)) / 8;
} else {
if (preamble_type & WLC_SHORT_PREAMBLE)
dur -= BPHY_PLCP_SHORT_TIME;
else
dur -= BPHY_PLCP_TIME;
mac_len = dur * rate;
mac_len = mac_len / 8 / 2;
}
return mac_len;
}
static uint
wlc_calc_ba_time(struct wlc_info *wlc, ratespec_t rspec, u8 preamble_type)
{
BCMMSG(wlc->wiphy, "wl%d: rspec 0x%x, "
"preamble_type %d\n", wlc->pub->unit, rspec, preamble_type);
rspec = WLC_BASIC_RATE(wlc, rspec);
return wlc_calc_frame_time(wlc, rspec, preamble_type,
(DOT11_BA_LEN + DOT11_BA_BITMAP_LEN +
FCS_LEN));
}
static uint
wlc_calc_ack_time(struct wlc_info *wlc, ratespec_t rspec, u8 preamble_type)
{
uint dur = 0;
BCMMSG(wlc->wiphy, "wl%d: rspec 0x%x, preamble_type %d\n",
wlc->pub->unit, rspec, preamble_type);
rspec = WLC_BASIC_RATE(wlc, rspec);
dur =
wlc_calc_frame_time(wlc, rspec, preamble_type,
(DOT11_ACK_LEN + FCS_LEN));
return dur;
}
static uint
wlc_calc_cts_time(struct wlc_info *wlc, ratespec_t rspec, u8 preamble_type)
{
BCMMSG(wlc->wiphy, "wl%d: ratespec 0x%x, preamble_type %d\n",
wlc->pub->unit, rspec, preamble_type);
return wlc_calc_ack_time(wlc, rspec, preamble_type);
}
void wlc_rate_lookup_init(struct wlc_info *wlc, wlc_rateset_t *rateset)
{
u8 rate;
u8 mandatory;
u8 cck_basic = 0;
u8 ofdm_basic = 0;
u8 *br = wlc->band->basic_rate;
uint i;
memset(br, 0, WLC_MAXRATE + 1);
for (i = 0; i < rateset->count; i++) {
if (!(rateset->rates[i] & WLC_RATE_FLAG))
continue;
rate = (rateset->rates[i] & WLC_RATE_MASK);
if (rate > WLC_MAXRATE) {
wiphy_err(wlc->wiphy, "wlc_rate_lookup_init: invalid "
"rate 0x%X in rate set\n",
rateset->rates[i]);
continue;
}
br[rate] = rate;
}
for (i = 0; i < wlc->band->hw_rateset.count; i++) {
rate = wlc->band->hw_rateset.rates[i];
if (br[rate] != 0) {
if (IS_OFDM(rate))
ofdm_basic = rate;
else
cck_basic = rate;
continue;
}
br[rate] = IS_OFDM(rate) ? ofdm_basic : cck_basic;
if (br[rate] != 0)
continue;
if (IS_OFDM(rate)) {
if (rate >= WLC_RATE_24M)
mandatory = WLC_RATE_24M;
else if (rate >= WLC_RATE_12M)
mandatory = WLC_RATE_12M;
else
mandatory = WLC_RATE_6M;
} else {
mandatory = rate;
}
br[rate] = mandatory;
}
}
static void wlc_write_rate_shm(struct wlc_info *wlc, u8 rate, u8 basic_rate)
{
u8 phy_rate, index;
u8 basic_phy_rate, basic_index;
u16 dir_table, basic_table;
u16 basic_ptr;
dir_table = IS_OFDM(basic_rate) ? M_RT_DIRMAP_A : M_RT_DIRMAP_B;
basic_table = IS_OFDM(rate) ? M_RT_BBRSMAP_A : M_RT_BBRSMAP_B;
phy_rate = rate_info[rate] & WLC_RATE_MASK;
basic_phy_rate = rate_info[basic_rate] & WLC_RATE_MASK;
index = phy_rate & 0xf;
basic_index = basic_phy_rate & 0xf;
basic_ptr = wlc_read_shm(wlc, (dir_table + basic_index * 2));
wlc_write_shm(wlc, (basic_table + index * 2), basic_ptr);
}
static const wlc_rateset_t *wlc_rateset_get_hwrs(struct wlc_info *wlc)
{
const wlc_rateset_t *rs_dflt;
if (WLC_PHY_11N_CAP(wlc->band)) {
if (BAND_5G(wlc->band->bandtype))
rs_dflt = &ofdm_mimo_rates;
else
rs_dflt = &cck_ofdm_mimo_rates;
} else if (wlc->band->gmode)
rs_dflt = &cck_ofdm_rates;
else
rs_dflt = &cck_rates;
return rs_dflt;
}
void wlc_set_ratetable(struct wlc_info *wlc)
{
const wlc_rateset_t *rs_dflt;
wlc_rateset_t rs;
u8 rate, basic_rate;
uint i;
rs_dflt = wlc_rateset_get_hwrs(wlc);
wlc_rateset_copy(rs_dflt, &rs);
wlc_rateset_mcs_upd(&rs, wlc->stf->txstreams);
for (i = 0; i < rs.count; i++) {
rate = rs.rates[i] & WLC_RATE_MASK;
basic_rate = WLC_BASIC_RATE(wlc, rate);
if (basic_rate == 0) {
basic_rate = rs.rates[0] & WLC_RATE_MASK;
}
wlc_write_rate_shm(wlc, rate, basic_rate);
}
}
bool wlc_valid_rate(struct wlc_info *wlc, ratespec_t rspec, int band,
bool verbose)
{
wlc_rateset_t *hw_rateset;
uint i;
if ((band == WLC_BAND_AUTO) || (band == wlc->band->bandtype)) {
hw_rateset = &wlc->band->hw_rateset;
} else if (NBANDS(wlc) > 1) {
hw_rateset = &wlc->bandstate[OTHERBANDUNIT(wlc)]->hw_rateset;
} else {
return false;
}
if (IS_MCS(rspec)) {
if (!VALID_MCS((rspec & RSPEC_RATE_MASK)))
goto error;
return isset(hw_rateset->mcs, (rspec & RSPEC_RATE_MASK));
}
for (i = 0; i < hw_rateset->count; i++)
if (hw_rateset->rates[i] == RSPEC2RATE(rspec))
return true;
error:
if (verbose) {
wiphy_err(wlc->wiphy, "wl%d: wlc_valid_rate: rate spec 0x%x "
"not in hw_rateset\n", wlc->pub->unit, rspec);
}
return false;
}
static void wlc_update_mimo_band_bwcap(struct wlc_info *wlc, u8 bwcap)
{
uint i;
struct wlcband *band;
for (i = 0; i < NBANDS(wlc); i++) {
if (IS_SINGLEBAND_5G(wlc->deviceid))
i = BAND_5G_INDEX;
band = wlc->bandstate[i];
if (band->bandtype == WLC_BAND_5G) {
if ((bwcap == WLC_N_BW_40ALL)
|| (bwcap == WLC_N_BW_20IN2G_40IN5G))
band->mimo_cap_40 = true;
else
band->mimo_cap_40 = false;
} else {
if (bwcap == WLC_N_BW_40ALL)
band->mimo_cap_40 = true;
else
band->mimo_cap_40 = false;
}
}
wlc->mimo_band_bwcap = bwcap;
}
void wlc_mod_prb_rsp_rate_table(struct wlc_info *wlc, uint frame_len)
{
const wlc_rateset_t *rs_dflt;
wlc_rateset_t rs;
u8 rate;
u16 entry_ptr;
u8 plcp[D11_PHY_HDR_LEN];
u16 dur, sifs;
uint i;
sifs = SIFS(wlc->band);
rs_dflt = wlc_rateset_get_hwrs(wlc);
wlc_rateset_copy(rs_dflt, &rs);
wlc_rateset_mcs_upd(&rs, wlc->stf->txstreams);
for (i = 0; i < rs.count; i++) {
rate = rs.rates[i] & WLC_RATE_MASK;
entry_ptr = wlc_rate_shm_offset(wlc, rate);
wlc_compute_plcp(wlc, rate, frame_len, plcp);
dur =
(u16) wlc_calc_frame_time(wlc, rate, WLC_LONG_PREAMBLE,
frame_len);
dur += sifs;
wlc_write_shm(wlc, entry_ptr + M_RT_PRS_PLCP_POS,
(u16) (plcp[0] + (plcp[1] << 8)));
wlc_write_shm(wlc, entry_ptr + M_RT_PRS_PLCP_POS + 2,
(u16) (plcp[2] + (plcp[3] << 8)));
wlc_write_shm(wlc, entry_ptr + M_RT_PRS_DUR_POS, dur);
}
}
static void
wlc_bcn_prb_template(struct wlc_info *wlc, u16 type, ratespec_t bcn_rspec,
struct wlc_bsscfg *cfg, u16 *buf, int *len)
{
static const u8 ether_bcast[ETH_ALEN] = {255, 255, 255, 255, 255, 255};
cck_phy_hdr_t *plcp;
struct ieee80211_mgmt *h;
int hdr_len, body_len;
if (MBSS_BCN_ENAB(cfg) && type == IEEE80211_STYPE_BEACON)
hdr_len = DOT11_MAC_HDR_LEN;
else
hdr_len = D11_PHY_HDR_LEN + DOT11_MAC_HDR_LEN;
body_len = *len - hdr_len;
*len = hdr_len + body_len;
memset((char *)buf, 0, hdr_len);
plcp = (cck_phy_hdr_t *) buf;
if (type == IEEE80211_STYPE_BEACON && !MBSS_BCN_ENAB(cfg)) {
wlc_compute_plcp(wlc, bcn_rspec,
(DOT11_MAC_HDR_LEN + body_len + FCS_LEN),
(u8 *) plcp);
}
if (!SOFTBCN_ENAB(cfg))
wlc_beacon_phytxctl_txant_upd(wlc, bcn_rspec);
if (MBSS_BCN_ENAB(cfg) && type == IEEE80211_STYPE_BEACON)
h = (struct ieee80211_mgmt *)&plcp[0];
else
h = (struct ieee80211_mgmt *)&plcp[1];
h->frame_control = cpu_to_le16(IEEE80211_FTYPE_MGMT | type);
if (type == IEEE80211_STYPE_BEACON)
memcpy(&h->da, &ether_bcast, ETH_ALEN);
memcpy(&h->sa, &cfg->cur_etheraddr, ETH_ALEN);
memcpy(&h->bssid, &cfg->BSSID, ETH_ALEN);
return;
}
int wlc_get_header_len()
{
return TXOFF;
}
void wlc_bss_update_beacon(struct wlc_info *wlc, struct wlc_bsscfg *cfg)
{
int len = BCN_TMPL_LEN;
wlc->defmacintmask &= ~MI_BCNTPL;
if (!cfg->up) {
return;
}
if (!MBSS_BCN_ENAB(cfg) && HWBCN_ENAB(cfg)) {
u16 bcn[BCN_TMPL_LEN / 2];
u32 both_valid = MCMD_BCN0VLD | MCMD_BCN1VLD;
d11regs_t *regs = wlc->regs;
if ((R_REG(&regs->maccommand) & both_valid) == both_valid) {
W_REG(&regs->macintstatus, MI_BCNTPL);
}
if ((R_REG(&regs->maccommand) & both_valid) == both_valid) {
wlc->defmacintmask |= MI_BCNTPL;
return;
}
wlc->bcn_rspec =
wlc_lowest_basic_rspec(wlc, &cfg->current_bss->rateset);
wlc_bcn_prb_template(wlc, IEEE80211_STYPE_BEACON,
wlc->bcn_rspec, cfg, bcn, &len);
wlc_write_hw_bcntemplates(wlc, bcn, len, false);
}
}
void wlc_update_beacon(struct wlc_info *wlc)
{
int idx;
struct wlc_bsscfg *bsscfg;
FOREACH_BSS(wlc, idx, bsscfg) {
if (bsscfg->up && (BSSCFG_AP(bsscfg) || !bsscfg->BSS))
wlc_bss_update_beacon(wlc, bsscfg);
}
}
void wlc_shm_ssid_upd(struct wlc_info *wlc, struct wlc_bsscfg *cfg)
{
u8 *ssidptr = cfg->SSID;
u16 base = M_SSID;
u8 ssidbuf[IEEE80211_MAX_SSID_LEN];
memset(ssidbuf, 0, IEEE80211_MAX_SSID_LEN);
memcpy(ssidbuf, ssidptr, cfg->SSID_len);
wlc_copyto_shm(wlc, base, ssidbuf, IEEE80211_MAX_SSID_LEN);
if (!MBSS_BCN_ENAB(cfg))
wlc_write_shm(wlc, M_SSIDLEN, (u16) cfg->SSID_len);
}
void wlc_update_probe_resp(struct wlc_info *wlc, bool suspend)
{
int idx;
struct wlc_bsscfg *bsscfg;
FOREACH_BSS(wlc, idx, bsscfg) {
if (bsscfg->up && (BSSCFG_AP(bsscfg) || !bsscfg->BSS))
wlc_bss_update_probe_resp(wlc, bsscfg, suspend);
}
}
void
wlc_bss_update_probe_resp(struct wlc_info *wlc, struct wlc_bsscfg *cfg,
bool suspend)
{
u16 prb_resp[BCN_TMPL_LEN / 2];
int len = BCN_TMPL_LEN;
if (!MBSS_PRB_ENAB(cfg)) {
wlc_bcn_prb_template(wlc, IEEE80211_STYPE_PROBE_RESP, 0, cfg,
prb_resp, &len);
if (suspend)
wlc_suspend_mac_and_wait(wlc);
wlc_bmac_write_template_ram(wlc->hw, T_PRS_TPL_BASE,
(len + 3) & ~3, prb_resp);
wlc_write_shm(wlc, M_PRB_RESP_FRM_LEN, (u16) len);
wlc_shm_ssid_upd(wlc, cfg);
len += (-D11_PHY_HDR_LEN + FCS_LEN);
wlc_mod_prb_rsp_rate_table(wlc, (u16) len);
if (suspend)
wlc_enable_mac(wlc);
} else {
}
}
int wlc_prep_pdu(struct wlc_info *wlc, struct sk_buff *pdu, uint *fifop)
{
uint fifo;
d11txh_t *txh;
struct ieee80211_hdr *h;
struct scb *scb;
txh = (d11txh_t *) (pdu->data);
h = (struct ieee80211_hdr *)((u8 *) (txh + 1) + D11_PHY_HDR_LEN);
fifo = le16_to_cpu(txh->TxFrameID) & TXFID_QUEUE_MASK;
scb = NULL;
*fifop = fifo;
if (TXAVAIL(wlc, fifo) < MAX_DMA_SEGS) {
WLC_TX_FIFO_CLEAR(wlc, fifo);
return -EBUSY;
}
return 0;
}
void wlc_reprate_init(struct wlc_info *wlc)
{
int i;
struct wlc_bsscfg *bsscfg;
FOREACH_BSS(wlc, i, bsscfg) {
wlc_bsscfg_reprate_init(bsscfg);
}
}
void wlc_bsscfg_reprate_init(struct wlc_bsscfg *bsscfg)
{
bsscfg->txrspecidx = 0;
memset((char *)bsscfg->txrspec, 0, sizeof(bsscfg->txrspec));
}
int wlc_get_revision_info(struct wlc_info *wlc, void *buf, uint len)
{
wlc_rev_info_t *rinfo = (wlc_rev_info_t *) buf;
if (len < WL_REV_INFO_LEGACY_LENGTH)
return -EOVERFLOW;
rinfo->vendorid = wlc->vendorid;
rinfo->deviceid = wlc->deviceid;
rinfo->radiorev = (wlc->band->radiorev << IDCODE_REV_SHIFT) |
(wlc->band->radioid << IDCODE_ID_SHIFT);
rinfo->chiprev = wlc->pub->sih->chiprev;
rinfo->corerev = wlc->pub->corerev;
rinfo->boardid = wlc->pub->sih->boardtype;
rinfo->boardvendor = wlc->pub->sih->boardvendor;
rinfo->boardrev = wlc->pub->boardrev;
rinfo->ucoderev = wlc->ucode_rev;
rinfo->driverrev = EPI_VERSION_NUM;
rinfo->bus = wlc->pub->sih->bustype;
rinfo->chipnum = wlc->pub->sih->chip;
if (len >= (offsetof(wlc_rev_info_t, chippkg))) {
rinfo->phytype = wlc->band->phytype;
rinfo->phyrev = wlc->band->phyrev;
rinfo->anarev = 0;
}
if (len >= sizeof(*rinfo)) {
rinfo->chippkg = wlc->pub->sih->chippkg;
}
return 0;
}
void wlc_default_rateset(struct wlc_info *wlc, wlc_rateset_t *rs)
{
wlc_rateset_default(rs, NULL, wlc->band->phytype, wlc->band->bandtype,
false, WLC_RATE_MASK_FULL, (bool) N_ENAB(wlc->pub),
CHSPEC_WLC_BW(wlc->default_bss->chanspec),
wlc->stf->txstreams);
}
static void wlc_bss_default_init(struct wlc_info *wlc)
{
chanspec_t chanspec;
struct wlcband *band;
wlc_bss_info_t *bi = wlc->default_bss;
memset((char *)(bi), 0, sizeof(wlc_bss_info_t));
bi->beacon_period = ISSIM_ENAB(wlc->pub->sih) ? BEACON_INTERVAL_DEF_QT :
BEACON_INTERVAL_DEFAULT;
bi->dtim_period = ISSIM_ENAB(wlc->pub->sih) ? DTIM_INTERVAL_DEF_QT :
DTIM_INTERVAL_DEFAULT;
chanspec = CH20MHZ_CHSPEC(1);
wlc->home_chanspec = bi->chanspec = chanspec;
band = wlc->band;
if (NBANDS(wlc) > 1 && band->bandunit != CHSPEC_WLCBANDUNIT(chanspec))
band = wlc->bandstate[OTHERBANDUNIT(wlc)];
wlc_rateset_default(&bi->rateset, NULL, band->phytype, band->bandtype,
false, WLC_RATE_MASK_FULL, (bool) N_ENAB(wlc->pub),
CHSPEC_WLC_BW(chanspec), wlc->stf->txstreams);
if (N_ENAB(wlc->pub))
bi->flags |= WLC_BSS_HT;
}
static ratespec_t
mac80211_wlc_set_nrate(struct wlc_info *wlc, struct wlcband *cur_band,
u32 int_val)
{
u8 stf = (int_val & NRATE_STF_MASK) >> NRATE_STF_SHIFT;
u8 rate = int_val & NRATE_RATE_MASK;
ratespec_t rspec;
bool ismcs = ((int_val & NRATE_MCS_INUSE) == NRATE_MCS_INUSE);
bool issgi = ((int_val & NRATE_SGI_MASK) >> NRATE_SGI_SHIFT);
bool override_mcs_only = ((int_val & NRATE_OVERRIDE_MCS_ONLY)
== NRATE_OVERRIDE_MCS_ONLY);
int bcmerror = 0;
if (!ismcs) {
return (ratespec_t) rate;
}
if (N_ENAB(wlc->pub) && ismcs) {
if (stf > PHY_TXC1_MODE_SDM) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid stf\n",
WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
if (rate == 32) {
if (!CHSPEC_IS40(wlc->home_chanspec) ||
((stf != PHY_TXC1_MODE_SISO)
&& (stf != PHY_TXC1_MODE_CDD))) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid mcs "
"32\n", WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
} else if (rate > HIGHEST_SINGLE_STREAM_MCS) {
if (stf != PHY_TXC1_MODE_SDM) {
BCMMSG(wlc->wiphy, "wl%d: enabling "
"SDM mode for mcs %d\n",
WLCWLUNIT(wlc), rate);
stf = PHY_TXC1_MODE_SDM;
}
} else {
if ((stf > PHY_TXC1_MODE_STBC) ||
(!WLC_STBC_CAP_PHY(wlc)
&& (stf == PHY_TXC1_MODE_STBC))) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid STBC"
"\n", WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
}
} else if (IS_OFDM(rate)) {
if ((stf != PHY_TXC1_MODE_CDD) && (stf != PHY_TXC1_MODE_SISO)) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid OFDM\n",
WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
} else if (IS_CCK(rate)) {
if ((cur_band->bandtype != WLC_BAND_2G)
|| (stf != PHY_TXC1_MODE_SISO)) {
wiphy_err(wlc->wiphy, "wl%d: %s: Invalid CCK\n",
WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
} else {
wiphy_err(wlc->wiphy, "wl%d: %s: Unknown rate type\n",
WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
if ((stf != PHY_TXC1_MODE_SISO) && (wlc->stf->txstreams == 1)) {
wiphy_err(wlc->wiphy, "wl%d: %s: SISO antenna but !SISO "
"request\n", WLCWLUNIT(wlc), __func__);
bcmerror = -EINVAL;
goto done;
}
rspec = rate;
if (ismcs) {
rspec |= RSPEC_MIMORATE;
if (stf == PHY_TXC1_MODE_STBC) {
u8 stc;
stc = 1;
rspec |= (stc << RSPEC_STC_SHIFT);
}
}
rspec |= (stf << RSPEC_STF_SHIFT);
if (override_mcs_only)
rspec |= RSPEC_OVERRIDE_MCS_ONLY;
if (issgi)
rspec |= RSPEC_SHORT_GI;
if ((rate != 0)
&& !wlc_valid_rate(wlc, rspec, cur_band->bandtype, true)) {
return rate;
}
return rspec;
done:
return rate;
}
static int
wlc_duty_cycle_set(struct wlc_info *wlc, int duty_cycle, bool isOFDM,
bool writeToShm)
{
int idle_busy_ratio_x_16 = 0;
uint offset =
isOFDM ? M_TX_IDLE_BUSY_RATIO_X_16_OFDM :
M_TX_IDLE_BUSY_RATIO_X_16_CCK;
if (duty_cycle > 100 || duty_cycle < 0) {
wiphy_err(wlc->wiphy, "wl%d: duty cycle value off limit\n",
wlc->pub->unit);
return -EINVAL;
}
if (duty_cycle)
idle_busy_ratio_x_16 = (100 - duty_cycle) * 16 / duty_cycle;
if (writeToShm)
wlc_write_shm(wlc, offset, (u16) idle_busy_ratio_x_16);
if (isOFDM)
wlc->tx_duty_cycle_ofdm = (u16) duty_cycle;
else
wlc->tx_duty_cycle_cck = (u16) duty_cycle;
return 0;
}
u16 wlc_read_shm(struct wlc_info *wlc, uint offset)
{
return wlc_bmac_read_shm(wlc->hw, offset);
}
void wlc_write_shm(struct wlc_info *wlc, uint offset, u16 v)
{
wlc_bmac_write_shm(wlc->hw, offset, v);
}
void wlc_copyto_shm(struct wlc_info *wlc, uint offset, const void *buf, int len)
{
if (len <= 0 || (offset & 1) || (len & 1))
return;
wlc_bmac_copyto_objmem(wlc->hw, offset, buf, len, OBJADDR_SHM_SEL);
}
void wlc_mctrl(struct wlc_info *wlc, u32 mask, u32 val)
{
wlc_bmac_mctrl(wlc->hw, mask, val);
}
void wlc_mhf(struct wlc_info *wlc, u8 idx, u16 mask, u16 val, int bands)
{
wlc_bmac_mhf(wlc->hw, idx, mask, val, bands);
}
int wlc_xmtfifo_sz_get(struct wlc_info *wlc, uint fifo, uint *blocks)
{
return wlc_bmac_xmtfifo_sz_get(wlc->hw, fifo, blocks);
}
void wlc_write_template_ram(struct wlc_info *wlc, int offset, int len,
void *buf)
{
wlc_bmac_write_template_ram(wlc->hw, offset, len, buf);
}
void wlc_write_hw_bcntemplates(struct wlc_info *wlc, void *bcn, int len,
bool both)
{
wlc_bmac_write_hw_bcntemplates(wlc->hw, bcn, len, both);
}
void
wlc_set_addrmatch(struct wlc_info *wlc, int match_reg_offset,
const u8 *addr)
{
wlc_bmac_set_addrmatch(wlc->hw, match_reg_offset, addr);
if (match_reg_offset == RCM_BSSID_OFFSET)
memcpy(wlc->cfg->BSSID, addr, ETH_ALEN);
}
void wlc_set_cwmin(struct wlc_info *wlc, u16 newmin)
{
wlc->band->CWmin = newmin;
wlc_bmac_set_cwmin(wlc->hw, newmin);
}
void wlc_set_cwmax(struct wlc_info *wlc, u16 newmax)
{
wlc->band->CWmax = newmax;
wlc_bmac_set_cwmax(wlc->hw, newmax);
}
void wlc_pllreq(struct wlc_info *wlc, bool set, mbool req_bit)
{
wlc_bmac_pllreq(wlc->hw, set, req_bit);
}
void wlc_reset_bmac_done(struct wlc_info *wlc)
{
}
bool
wlc_txflowcontrol_prio_isset(struct wlc_info *wlc, struct wlc_txq_info *q,
int prio)
{
uint prio_mask;
if (prio == ALLPRIO) {
prio_mask = TXQ_STOP_FOR_PRIOFC_MASK;
} else {
prio_mask = NBITVAL(prio);
}
return (q->stopped & prio_mask) == prio_mask;
}
void wlc_txflowcontrol(struct wlc_info *wlc, struct wlc_txq_info *qi,
bool on, int prio)
{
uint prio_bits;
uint cur_bits;
BCMMSG(wlc->wiphy, "flow control kicks in\n");
if (prio == ALLPRIO) {
prio_bits = TXQ_STOP_FOR_PRIOFC_MASK;
} else {
prio_bits = NBITVAL(prio);
}
cur_bits = qi->stopped & prio_bits;
if (on) {
if (cur_bits == prio_bits) {
return;
}
mboolset(qi->stopped, prio_bits);
} else {
if (cur_bits == 0) {
return;
}
mboolclr(qi->stopped, prio_bits);
}
if (qi->stopped & ~TXQ_STOP_FOR_PRIOFC_MASK) {
return;
}
wlc_txflowcontrol_signal(wlc, qi, on, prio);
}
void
wlc_txflowcontrol_override(struct wlc_info *wlc, struct wlc_txq_info *qi,
bool on, uint override)
{
uint prev_override;
prev_override = (qi->stopped & ~TXQ_STOP_FOR_PRIOFC_MASK);
if (on) {
mboolset(qi->stopped, override);
if (prev_override) {
return;
}
wlc_txflowcontrol_signal(wlc, qi, ON, ALLPRIO);
} else {
mboolclr(qi->stopped, override);
if (prev_override != override) {
return;
}
if (qi->stopped == 0) {
wlc_txflowcontrol_signal(wlc, qi, OFF, ALLPRIO);
} else {
int prio;
for (prio = MAXPRIO; prio >= 0; prio--) {
if (!mboolisset(qi->stopped, NBITVAL(prio)))
wlc_txflowcontrol_signal(wlc, qi, OFF,
prio);
}
}
}
}
static void wlc_txflowcontrol_reset(struct wlc_info *wlc)
{
struct wlc_txq_info *qi;
for (qi = wlc->tx_queues; qi != NULL; qi = qi->next) {
if (qi->stopped) {
wlc_txflowcontrol_signal(wlc, qi, OFF, ALLPRIO);
qi->stopped = 0;
}
}
}
static void
wlc_txflowcontrol_signal(struct wlc_info *wlc, struct wlc_txq_info *qi, bool on,
int prio)
{
struct wlc_if *wlcif;
for (wlcif = wlc->wlcif_list; wlcif != NULL; wlcif = wlcif->next) {
if (wlcif->qi == qi && wlcif->flags & WLC_IF_LINKED)
wl_txflowcontrol(wlc->wl, wlcif->wlif, on, prio);
}
}
static struct wlc_txq_info *wlc_txq_alloc(struct wlc_info *wlc)
{
struct wlc_txq_info *qi, *p;
qi = kzalloc(sizeof(struct wlc_txq_info), GFP_ATOMIC);
if (qi != NULL) {
bcm_pktq_init(&qi->q, WLC_PREC_COUNT,
(2 * wlc->pub->tunables->datahiwat) + PKTQ_LEN_DEFAULT
+ wlc->pub->psq_pkts_total);
p = wlc->tx_queues;
if (p == NULL) {
wlc->tx_queues = qi;
} else {
while (p->next != NULL)
p = p->next;
p->next = qi;
}
}
return qi;
}
static void wlc_txq_free(struct wlc_info *wlc, struct wlc_txq_info *qi)
{
struct wlc_txq_info *p;
if (qi == NULL)
return;
p = wlc->tx_queues;
if (p == qi)
wlc->tx_queues = p->next;
else {
while (p != NULL && p->next != qi)
p = p->next;
if (p != NULL)
p->next = p->next->next;
}
kfree(qi);
}
void wlc_scan_start(struct wlc_info *wlc)
{
wlc_phy_hold_upd(wlc->band->pi, PHY_HOLD_FOR_SCAN, true);
}
void wlc_scan_stop(struct wlc_info *wlc)
{
wlc_phy_hold_upd(wlc->band->pi, PHY_HOLD_FOR_SCAN, false);
}
void wlc_associate_upd(struct wlc_info *wlc, bool state)
{
wlc->pub->associated = state;
wlc->cfg->associated = state;
}
int wlc_get_curband(struct wlc_info *wlc)
{
return wlc->band->bandunit;
}
void wlc_wait_for_tx_completion(struct wlc_info *wlc, bool drop)
{
if (drop)
bcm_pktq_flush(&wlc->pkt_queue->q, false, NULL, NULL);
while (!pktq_empty(&wlc->pkt_queue->q) ||
TXPKTPENDTOT(wlc) > 0) {
wl_msleep(wlc->wl, 1);
}
}
