static void wlc_stf_stbc_rx_ht_update(struct wlc_info *wlc, int val)
{
if (WLC_STF_SS_STBC_RX(wlc)) {
if ((wlc->stf->rxstreams == 1) && (val != HT_CAP_RX_STBC_NO))
return;
}
wlc->ht_cap.cap_info &= ~IEEE80211_HT_CAP_RX_STBC;
wlc->ht_cap.cap_info |= (val << IEEE80211_HT_CAP_RX_STBC_SHIFT);
if (wlc->pub->up) {
wlc_update_beacon(wlc);
wlc_update_probe_resp(wlc, true);
}
}
void wlc_tempsense_upd(struct wlc_info *wlc)
{
wlc_phy_t *pi = wlc->band->pi;
uint active_chains, txchain;
active_chains = wlc_phy_stf_chain_active_get(pi);
txchain = active_chains & 0xf;
if (wlc->stf->txchain == wlc->stf->hw_txchain) {
if (txchain && (txchain < wlc->stf->hw_txchain)) {
wlc_stf_txchain_set(wlc, txchain, true);
}
} else if (wlc->stf->txchain < wlc->stf->hw_txchain) {
if (txchain == wlc->stf->hw_txchain) {
wlc_stf_txchain_set(wlc, txchain, true);
}
}
}
void
wlc_stf_ss_algo_channel_get(struct wlc_info *wlc, u16 *ss_algo_channel,
chanspec_t chanspec)
{
tx_power_t power;
u8 siso_mcs_id, cdd_mcs_id, stbc_mcs_id;
*ss_algo_channel = 0;
if (!wlc->pub->up) {
*ss_algo_channel = (u16) -1;
return;
}
wlc_phy_txpower_get_current(wlc->band->pi, &power,
CHSPEC_CHANNEL(chanspec));
siso_mcs_id = (CHSPEC_IS40(chanspec)) ?
WL_TX_POWER_MCS40_SISO_FIRST : WL_TX_POWER_MCS20_SISO_FIRST;
cdd_mcs_id = (CHSPEC_IS40(chanspec)) ?
WL_TX_POWER_MCS40_CDD_FIRST : WL_TX_POWER_MCS20_CDD_FIRST;
stbc_mcs_id = (CHSPEC_IS40(chanspec)) ?
WL_TX_POWER_MCS40_STBC_FIRST : WL_TX_POWER_MCS20_STBC_FIRST;
if (power.target[siso_mcs_id] > (power.target[cdd_mcs_id] + 12))
setbit(ss_algo_channel, PHY_TXC1_MODE_SISO);
else
setbit(ss_algo_channel, PHY_TXC1_MODE_CDD);
if (power.target[siso_mcs_id] <= (power.target[stbc_mcs_id] + 12))
setbit(ss_algo_channel, PHY_TXC1_MODE_STBC);
}
static bool wlc_stf_stbc_tx_set(struct wlc_info *wlc, s32 int_val)
{
if ((int_val != AUTO) && (int_val != OFF) && (int_val != ON)) {
return false;
}
if ((int_val == ON) && (wlc->stf->txstreams == 1))
return false;
if ((int_val == OFF) || (wlc->stf->txstreams == 1)
|| !WLC_STBC_CAP_PHY(wlc))
wlc->ht_cap.cap_info &= ~IEEE80211_HT_CAP_TX_STBC;
else
wlc->ht_cap.cap_info |= IEEE80211_HT_CAP_TX_STBC;
wlc->bandstate[BAND_2G_INDEX]->band_stf_stbc_tx = (s8) int_val;
wlc->bandstate[BAND_5G_INDEX]->band_stf_stbc_tx = (s8) int_val;
return true;
}
bool wlc_stf_stbc_rx_set(struct wlc_info *wlc, s32 int_val)
{
if ((int_val != HT_CAP_RX_STBC_NO)
&& (int_val != HT_CAP_RX_STBC_ONE_STREAM)) {
return false;
}
if (WLC_STF_SS_STBC_RX(wlc)) {
if ((int_val != HT_CAP_RX_STBC_NO)
&& (wlc->stf->rxstreams == 1))
return false;
}
wlc_stf_stbc_rx_ht_update(wlc, int_val);
return true;
}
static int wlc_stf_txcore_set(struct wlc_info *wlc, u8 Nsts, u8 core_mask)
{
BCMMSG(wlc->wiphy, "wl%d: Nsts %d core_mask %x\n",
wlc->pub->unit, Nsts, core_mask);
if (WLC_BITSCNT(core_mask) > wlc->stf->txstreams) {
core_mask = 0;
}
if ((WLC_BITSCNT(core_mask) == wlc->stf->txstreams) &&
((core_mask & ~wlc->stf->txchain)
|| !(core_mask & wlc->stf->txchain))) {
core_mask = wlc->stf->txchain;
}
wlc->stf->txcore[Nsts] = core_mask;
if (Nsts == 1) {
wlc->stf->phytxant = core_mask << PHY_TXC_ANT_SHIFT;
wlc_bmac_txant_set(wlc->hw, wlc->stf->phytxant);
if (wlc->clk) {
wlc_suspend_mac_and_wait(wlc);
wlc_beacon_phytxctl_txant_upd(wlc, wlc->bcn_rspec);
wlc_enable_mac(wlc);
}
}
return 0;
}
static int wlc_stf_spatial_policy_set(struct wlc_info *wlc, int val)
{
int i;
u8 core_mask = 0;
BCMMSG(wlc->wiphy, "wl%d: val %x\n", wlc->pub->unit, val);
wlc->stf->spatial_policy = (s8) val;
for (i = 1; i <= MAX_STREAMS_SUPPORTED; i++) {
core_mask = (val == MAX_SPATIAL_EXPANSION) ?
wlc->stf->txchain : txcore_default[i];
wlc_stf_txcore_set(wlc, (u8) i, core_mask);
}
return 0;
}
int wlc_stf_txchain_set(struct wlc_info *wlc, s32 int_val, bool force)
{
u8 txchain = (u8) int_val;
u8 txstreams;
uint i;
if (wlc->stf->txchain == txchain)
return 0;
if ((txchain & ~wlc->stf->hw_txchain)
|| !(txchain & wlc->stf->hw_txchain))
return -EINVAL;
txstreams = (u8) WLC_BITSCNT(txchain);
if (txstreams > MAX_STREAMS_SUPPORTED)
return -EINVAL;
if (txstreams == 1) {
for (i = 0; i < NBANDS(wlc); i++)
if ((RSPEC_STF(wlc->bandstate[i]->rspec_override) !=
PHY_TXC1_MODE_SISO)
|| (RSPEC_STF(wlc->bandstate[i]->mrspec_override) !=
PHY_TXC1_MODE_SISO)) {
if (!force)
return -EBADE;
if (RSPEC_STF(wlc->bandstate[i]->rspec_override)
!= PHY_TXC1_MODE_SISO) {
wlc->bandstate[i]->rspec_override = 0;
wiphy_err(wlc->wiphy, "%s(): temp "
"sense override non-SISO "
"rspec_override\n",
__func__);
}
if (RSPEC_STF
(wlc->bandstate[i]->mrspec_override) !=
PHY_TXC1_MODE_SISO) {
wlc->bandstate[i]->mrspec_override = 0;
wiphy_err(wlc->wiphy, "%s(): temp "
"sense override non-SISO "
"mrspec_override\n",
__func__);
}
}
}
wlc->stf->txchain = txchain;
wlc->stf->txstreams = txstreams;
wlc_stf_stbc_tx_set(wlc, wlc->band->band_stf_stbc_tx);
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_2G_INDEX]);
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_5G_INDEX]);
wlc->stf->txant =
(wlc->stf->txstreams == 1) ? ANT_TX_FORCE_0 : ANT_TX_DEF;
_wlc_stf_phy_txant_upd(wlc);
wlc_phy_stf_chain_set(wlc->band->pi, wlc->stf->txchain,
wlc->stf->rxchain);
for (i = 1; i <= MAX_STREAMS_SUPPORTED; i++)
wlc_stf_txcore_set(wlc, (u8) i, txcore_default[i]);
return 0;
}
int wlc_stf_ss_update(struct wlc_info *wlc, struct wlcband *band)
{
int ret_code = 0;
u8 prev_stf_ss;
u8 upd_stf_ss;
prev_stf_ss = wlc->stf->ss_opmode;
if (WLC_STBC_CAP_PHY(wlc) &&
wlc->stf->ss_algosel_auto
&& (wlc->stf->ss_algo_channel != (u16) -1)) {
upd_stf_ss = (wlc->stf->no_cddstbc || (wlc->stf->txstreams == 1)
|| isset(&wlc->stf->ss_algo_channel,
PHY_TXC1_MODE_SISO)) ? PHY_TXC1_MODE_SISO
: PHY_TXC1_MODE_CDD;
} else {
if (wlc->band != band)
return ret_code;
upd_stf_ss = (wlc->stf->no_cddstbc
|| (wlc->stf->txstreams ==
1)) ? PHY_TXC1_MODE_SISO : band->
band_stf_ss_mode;
}
if (prev_stf_ss != upd_stf_ss) {
wlc->stf->ss_opmode = upd_stf_ss;
wlc_bmac_band_stf_ss_set(wlc->hw, upd_stf_ss);
}
return ret_code;
}
int wlc_stf_attach(struct wlc_info *wlc)
{
wlc->bandstate[BAND_2G_INDEX]->band_stf_ss_mode = PHY_TXC1_MODE_SISO;
wlc->bandstate[BAND_5G_INDEX]->band_stf_ss_mode = PHY_TXC1_MODE_CDD;
if (WLCISNPHY(wlc->band) &&
(wlc_phy_txpower_hw_ctrl_get(wlc->band->pi) != PHY_TPC_HW_ON))
wlc->bandstate[BAND_2G_INDEX]->band_stf_ss_mode =
PHY_TXC1_MODE_CDD;
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_2G_INDEX]);
wlc_stf_ss_update(wlc, wlc->bandstate[BAND_5G_INDEX]);
wlc_stf_stbc_rx_ht_update(wlc, HT_CAP_RX_STBC_NO);
wlc->bandstate[BAND_2G_INDEX]->band_stf_stbc_tx = OFF;
wlc->bandstate[BAND_5G_INDEX]->band_stf_stbc_tx = OFF;
if (WLC_STBC_CAP_PHY(wlc)) {
wlc->stf->ss_algosel_auto = true;
wlc->stf->ss_algo_channel = (u16) -1;
}
return 0;
}
void wlc_stf_detach(struct wlc_info *wlc)
{
}
int wlc_stf_ant_txant_validate(struct wlc_info *wlc, s8 val)
{
int bcmerror = 0;
if (WLCISNPHY(wlc->band) && (wlc->stf->txstreams == 1))
return ((val == wlc->stf->txant) ? bcmerror : -EINVAL);
switch (val) {
case -1:
val = ANT_TX_DEF;
break;
case 0:
val = ANT_TX_FORCE_0;
break;
case 1:
val = ANT_TX_FORCE_1;
break;
case 3:
val = ANT_TX_LAST_RX;
break;
default:
bcmerror = -EINVAL;
break;
}
if (bcmerror == 0)
wlc->stf->txant = (s8) val;
return bcmerror;
}
static void _wlc_stf_phy_txant_upd(struct wlc_info *wlc)
{
s8 txant;
txant = (s8) wlc->stf->txant;
if (WLC_PHY_11N_CAP(wlc->band)) {
if (txant == ANT_TX_FORCE_0) {
wlc->stf->phytxant = PHY_TXC_ANT_0;
} else if (txant == ANT_TX_FORCE_1) {
wlc->stf->phytxant = PHY_TXC_ANT_1;
if (WLCISNPHY(wlc->band) &&
NREV_GE(wlc->band->phyrev, 3)
&& NREV_LT(wlc->band->phyrev, 7)) {
wlc->stf->phytxant = PHY_TXC_ANT_2;
}
} else {
if (WLCISLCNPHY(wlc->band) || WLCISSSLPNPHY(wlc->band))
wlc->stf->phytxant = PHY_TXC_LCNPHY_ANT_LAST;
else {
WARN_ON(wlc->stf->txchain <= 0);
wlc->stf->phytxant =
wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
}
}
} else {
if (txant == ANT_TX_FORCE_0)
wlc->stf->phytxant = PHY_TXC_OLD_ANT_0;
else if (txant == ANT_TX_FORCE_1)
wlc->stf->phytxant = PHY_TXC_OLD_ANT_1;
else
wlc->stf->phytxant = PHY_TXC_OLD_ANT_LAST;
}
wlc_bmac_txant_set(wlc->hw, wlc->stf->phytxant);
}
void wlc_stf_phy_txant_upd(struct wlc_info *wlc)
{
_wlc_stf_phy_txant_upd(wlc);
}
void wlc_stf_phy_chain_calc(struct wlc_info *wlc)
{
wlc->stf->hw_txchain = (u8) getintvar(wlc->pub->vars, "txchain");
wlc->stf->hw_rxchain = (u8) getintvar(wlc->pub->vars, "rxchain");
if (wlc->stf->hw_txchain == 0 || wlc->stf->hw_txchain == 0xf) {
if (WLCISNPHY(wlc->band)) {
wlc->stf->hw_txchain = TXCHAIN_DEF_NPHY;
} else {
wlc->stf->hw_txchain = TXCHAIN_DEF;
}
}
wlc->stf->txchain = wlc->stf->hw_txchain;
wlc->stf->txstreams = (u8) WLC_BITSCNT(wlc->stf->hw_txchain);
if (wlc->stf->hw_rxchain == 0 || wlc->stf->hw_rxchain == 0xf) {
if (WLCISNPHY(wlc->band)) {
wlc->stf->hw_rxchain = RXCHAIN_DEF_NPHY;
} else {
wlc->stf->hw_rxchain = RXCHAIN_DEF;
}
}
wlc->stf->rxchain = wlc->stf->hw_rxchain;
wlc->stf->rxstreams = (u8) WLC_BITSCNT(wlc->stf->hw_rxchain);
memcpy(wlc->stf->txcore, txcore_default, sizeof(wlc->stf->txcore));
wlc->stf->spatial_policy = MIN_SPATIAL_EXPANSION;
wlc_stf_spatial_policy_set(wlc, MIN_SPATIAL_EXPANSION);
}
static u16 _wlc_stf_phytxchain_sel(struct wlc_info *wlc, ratespec_t rspec)
{
u16 phytxant = wlc->stf->phytxant;
if (RSPEC_STF(rspec) != PHY_TXC1_MODE_SISO) {
phytxant = wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
} else if (wlc->stf->txant == ANT_TX_DEF)
phytxant = wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
phytxant &= PHY_TXC_ANT_MASK;
return phytxant;
}
u16 wlc_stf_phytxchain_sel(struct wlc_info *wlc, ratespec_t rspec)
{
return _wlc_stf_phytxchain_sel(wlc, rspec);
}
u16 wlc_stf_d11hdrs_phyctl_txant(struct wlc_info *wlc, ratespec_t rspec)
{
u16 phytxant = wlc->stf->phytxant;
u16 mask = PHY_TXC_ANT_MASK;
if (WLCISNPHY(wlc->band)) {
phytxant = _wlc_stf_phytxchain_sel(wlc, rspec);
mask = PHY_TXC_HTANT_MASK;
}
phytxant |= phytxant & mask;
return phytxant;
}
