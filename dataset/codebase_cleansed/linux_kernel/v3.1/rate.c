static bool brcms_c_rateset_valid(wlc_rateset_t *rs, bool check_brate)
{
uint idx;
if (!rs->count)
return false;
if (!check_brate)
return true;
for (idx = 0; idx < rs->count; idx++) {
if (rs->rates[idx] & BRCMS_RATE_FLAG)
return true;
}
return false;
}
void brcms_c_rateset_mcs_upd(wlc_rateset_t *rs, u8 txstreams)
{
int i;
for (i = txstreams; i < MAX_STREAMS_SUPPORTED; i++)
rs->mcs[i] = 0;
}
bool
brcms_c_rate_hwrs_filter_sort_validate(wlc_rateset_t *rs,
const wlc_rateset_t *hw_rs,
bool check_brate, u8 txstreams)
{
u8 rateset[BRCM_MAXRATE + 1];
u8 r;
uint count;
uint i;
memset(rateset, 0, sizeof(rateset));
count = rs->count;
for (i = 0; i < count; i++) {
r = (int)rs->rates[i] & BRCMS_RATE_MASK;
if ((r > BRCM_MAXRATE) || (rate_info[r] == 0))
continue;
rateset[r] = rs->rates[i];
}
count = 0;
for (i = 0; i < hw_rs->count; i++) {
r = hw_rs->rates[i] & BRCMS_RATE_MASK;
if (rateset[r])
rs->rates[count++] = rateset[r];
}
rs->count = count;
for (i = 0; i < MCSSET_LEN; i++)
rs->mcs[i] = (rs->mcs[i] & hw_rs->mcs[i]);
if (brcms_c_rateset_valid(rs, check_brate))
return true;
else
return false;
}
ratespec_t brcms_c_compute_rspec(struct d11rxhdr *rxh, u8 *plcp)
{
int phy_type;
ratespec_t rspec = PHY_TXC1_BW_20MHZ << RSPEC_BW_SHIFT;
phy_type =
((rxh->RxChan & RXS_CHAN_PHYTYPE_MASK) >> RXS_CHAN_PHYTYPE_SHIFT);
if ((phy_type == PHY_TYPE_N) || (phy_type == PHY_TYPE_SSN) ||
(phy_type == PHY_TYPE_LCN) || (phy_type == PHY_TYPE_HT)) {
switch (rxh->PhyRxStatus_0 & PRXS0_FT_MASK) {
case PRXS0_CCK:
rspec =
CCK_PHY2MAC_RATE(
((struct cck_phy_hdr *) plcp)->signal);
break;
case PRXS0_OFDM:
rspec =
OFDM_PHY2MAC_RATE(
((struct ofdm_phy_hdr *) plcp)->rlpt[0]);
break;
case PRXS0_PREN:
rspec = (plcp[0] & MIMO_PLCP_MCS_MASK) | RSPEC_MIMORATE;
if (plcp[0] & MIMO_PLCP_40MHZ) {
rspec &= ~RSPEC_BW_MASK;
rspec |= (PHY_TXC1_BW_40MHZ << RSPEC_BW_SHIFT);
}
break;
case PRXS0_STDN:
default:
break;
}
if (PLCP3_ISSGI(plcp[3]))
rspec |= RSPEC_SHORT_GI;
} else
if ((phy_type == PHY_TYPE_A) || (rxh->PhyRxStatus_0 & PRXS0_OFDM))
rspec = OFDM_PHY2MAC_RATE(
((struct ofdm_phy_hdr *) plcp)->rlpt[0]);
else
rspec = CCK_PHY2MAC_RATE(
((struct cck_phy_hdr *) plcp)->signal);
return rspec;
}
void brcms_c_rateset_copy(const wlc_rateset_t *src, wlc_rateset_t *dst)
{
memcpy(dst, src, sizeof(wlc_rateset_t));
}
void
brcms_c_rateset_filter(wlc_rateset_t *src, wlc_rateset_t *dst, bool basic_only,
u8 rates, uint xmask, bool mcsallow)
{
uint i;
uint r;
uint count;
count = 0;
for (i = 0; i < src->count; i++) {
r = src->rates[i];
if (basic_only && !(r & BRCMS_RATE_FLAG))
continue;
if (rates == BRCMS_RATES_CCK && IS_OFDM((r & BRCMS_RATE_MASK)))
continue;
if (rates == BRCMS_RATES_OFDM && IS_CCK((r & BRCMS_RATE_MASK)))
continue;
dst->rates[count++] = r & xmask;
}
dst->count = count;
dst->htphy_membership = src->htphy_membership;
if (mcsallow && rates != BRCMS_RATES_CCK)
memcpy(&dst->mcs[0], &src->mcs[0], MCSSET_LEN);
else
brcms_c_rateset_mcs_clear(dst);
}
void
brcms_c_rateset_default(wlc_rateset_t *rs_tgt, const wlc_rateset_t *rs_hw,
uint phy_type, int bandtype, bool cck_only, uint rate_mask,
bool mcsallow, u8 bw, u8 txstreams)
{
const wlc_rateset_t *rs_dflt;
wlc_rateset_t rs_sel;
if ((PHYTYPE_IS(phy_type, PHY_TYPE_HT)) ||
(PHYTYPE_IS(phy_type, PHY_TYPE_N)) ||
(PHYTYPE_IS(phy_type, PHY_TYPE_LCN)) ||
(PHYTYPE_IS(phy_type, PHY_TYPE_SSN))) {
if (BAND_5G(bandtype)) {
rs_dflt = (bw == BRCMS_20_MHZ ?
&ofdm_mimo_rates : &ofdm_40bw_mimo_rates);
} else {
rs_dflt = (bw == BRCMS_20_MHZ ?
&cck_ofdm_mimo_rates :
&cck_ofdm_40bw_mimo_rates);
}
} else if (PHYTYPE_IS(phy_type, PHY_TYPE_LP)) {
rs_dflt = (BAND_5G(bandtype)) ? &ofdm_rates : &cck_ofdm_rates;
} else if (PHYTYPE_IS(phy_type, PHY_TYPE_A)) {
rs_dflt = &ofdm_rates;
} else if (PHYTYPE_IS(phy_type, PHY_TYPE_G)) {
rs_dflt = &cck_ofdm_rates;
} else {
rs_dflt = &cck_rates;
}
if (!rs_hw)
rs_hw = rs_dflt;
brcms_c_rateset_copy(rs_dflt, &rs_sel);
brcms_c_rateset_mcs_upd(&rs_sel, txstreams);
brcms_c_rateset_filter(&rs_sel, rs_tgt, false,
cck_only ? BRCMS_RATES_CCK : BRCMS_RATES_CCK_OFDM,
rate_mask, mcsallow);
brcms_c_rate_hwrs_filter_sort_validate(rs_tgt, rs_hw, false,
mcsallow ? txstreams : 1);
}
s16 brcms_c_rate_legacy_phyctl(uint rate)
{
uint i;
for (i = 0; i < LEGACY_PHYCFG_TABLE_SIZE; i++)
if (rate == legacy_phycfg_table[i].rate_ofdm)
return legacy_phycfg_table[i].tx_phy_ctl3;
return -1;
}
void brcms_c_rateset_mcs_clear(wlc_rateset_t *rateset)
{
uint i;
for (i = 0; i < MCSSET_LEN; i++)
rateset->mcs[i] = 0;
}
void brcms_c_rateset_mcs_build(wlc_rateset_t *rateset, u8 txstreams)
{
memcpy(&rateset->mcs[0], &cck_ofdm_mimo_rates.mcs[0], MCSSET_LEN);
brcms_c_rateset_mcs_upd(rateset, txstreams);
}
void brcms_c_rateset_bw_mcs_filter(wlc_rateset_t *rateset, u8 bw)
{
if (bw == BRCMS_40_MHZ)
setbit(rateset->mcs, 32);
else
clrbit(rateset->mcs, 32);
}
