bool wlc_phy_bist_check_phy(struct brcms_phy_pub *pih)
{
struct brcms_phy *pi = (struct brcms_phy *) pih;
u32 phybist0, phybist1, phybist2, phybist3, phybist4;
if (NREV_GE(pi->pubpi.phy_rev, 16))
return true;
phybist0 = read_phy_reg(pi, 0x0e);
phybist1 = read_phy_reg(pi, 0x0f);
phybist2 = read_phy_reg(pi, 0xea);
phybist3 = read_phy_reg(pi, 0xeb);
phybist4 = read_phy_reg(pi, 0x156);
if ((phybist0 == 0) && (phybist1 == 0x4000) && (phybist2 == 0x1fe0) &&
(phybist3 == 0) && (phybist4 == 0))
return true;
return false;
}
static void wlc_phy_bphy_init_nphy(struct brcms_phy *pi)
{
u16 addr, val;
val = 0x1e1f;
for (addr = (NPHY_TO_BPHY_OFF + BPHY_RSSI_LUT);
addr <= (NPHY_TO_BPHY_OFF + BPHY_RSSI_LUT_END); addr++) {
write_phy_reg(pi, addr, val);
if (addr == (NPHY_TO_BPHY_OFF + 0x97))
val = 0x3e3f;
else
val -= 0x0202;
}
write_phy_reg(pi, NPHY_TO_BPHY_OFF + BPHY_STEP, 0x668);
}
void
wlc_phy_table_write_nphy(struct brcms_phy *pi, u32 id, u32 len, u32 offset,
u32 width, const void *data)
{
struct phytbl_info tbl;
tbl.tbl_id = id;
tbl.tbl_len = len;
tbl.tbl_offset = offset;
tbl.tbl_width = width;
tbl.tbl_ptr = data;
wlc_phy_write_table_nphy(pi, &tbl);
}
void
wlc_phy_table_read_nphy(struct brcms_phy *pi, u32 id, u32 len, u32 offset,
u32 width, void *data)
{
struct phytbl_info tbl;
tbl.tbl_id = id;
tbl.tbl_len = len;
tbl.tbl_offset = offset;
tbl.tbl_width = width;
tbl.tbl_ptr = data;
wlc_phy_read_table_nphy(pi, &tbl);
}
static void
wlc_phy_static_table_download_nphy(struct brcms_phy *pi)
{
uint idx;
if (NREV_GE(pi->pubpi.phy_rev, 16)) {
for (idx = 0; idx < mimophytbl_info_sz_rev16; idx++)
wlc_phy_write_table_nphy(pi,
&mimophytbl_info_rev16[idx]);
} else if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (idx = 0; idx < mimophytbl_info_sz_rev7; idx++)
wlc_phy_write_table_nphy(pi,
&mimophytbl_info_rev7[idx]);
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
for (idx = 0; idx < mimophytbl_info_sz_rev3; idx++)
wlc_phy_write_table_nphy(pi,
&mimophytbl_info_rev3[idx]);
} else {
for (idx = 0; idx < mimophytbl_info_sz_rev0; idx++)
wlc_phy_write_table_nphy(pi,
&mimophytbl_info_rev0[idx]);
}
}
static void wlc_phy_tbl_init_nphy(struct brcms_phy *pi)
{
uint idx = 0;
u8 antswctrllut;
if (pi->phy_init_por)
wlc_phy_static_table_download_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
antswctrllut = CHSPEC_IS2G(pi->radio_chanspec) ?
pi->srom_fem2g.antswctrllut : pi->srom_fem5g.
antswctrllut;
switch (antswctrllut) {
case 0:
break;
case 1:
if (pi->aa2g == 7)
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x21, 8,
&ant_sw_ctrl_tbl_rev8_2o3[0]);
else
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x21, 8,
&ant_sw_ctrl_tbl_rev8
[0]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x25, 8,
&ant_sw_ctrl_tbl_rev8[2]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x29, 8,
&ant_sw_ctrl_tbl_rev8[4]);
break;
case 2:
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x1, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core0[0]);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x5, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core0[2]);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x9, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core0[4]);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x21, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core1[0]);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x25, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core1[2]);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_ANTSWCTRLLUT,
2, 0x29, 8,
&ant_sw_ctrl_tbl_rev8_2057v7_core1[4]);
break;
default:
break;
}
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
for (idx = 0; idx < mimophytbl_info_sz_rev3_volatile; idx++) {
if (idx == ANT_SWCTRL_TBL_REV3_IDX) {
antswctrllut =
CHSPEC_IS2G(pi->radio_chanspec) ?
pi->srom_fem2g.antswctrllut :
pi->srom_fem5g.antswctrllut;
switch (antswctrllut) {
case 0:
wlc_phy_write_table_nphy(
pi,
&mimophytbl_info_rev3_volatile
[idx]);
break;
case 1:
wlc_phy_write_table_nphy(
pi,
&mimophytbl_info_rev3_volatile1
[idx]);
break;
case 2:
wlc_phy_write_table_nphy(
pi,
&mimophytbl_info_rev3_volatile2
[idx]);
break;
case 3:
wlc_phy_write_table_nphy(
pi,
&mimophytbl_info_rev3_volatile3
[idx]);
break;
default:
break;
}
} else {
wlc_phy_write_table_nphy(
pi,
&mimophytbl_info_rev3_volatile[idx]);
}
}
} else {
for (idx = 0; idx < mimophytbl_info_sz_rev0_volatile; idx++)
wlc_phy_write_table_nphy(pi,
&mimophytbl_info_rev0_volatile
[idx]);
}
}
static void
wlc_phy_write_txmacreg_nphy(struct brcms_phy *pi, u16 holdoff, u16 delay)
{
write_phy_reg(pi, 0x77, holdoff);
write_phy_reg(pi, 0xb4, delay);
}
void wlc_phy_nphy_tkip_rifs_war(struct brcms_phy *pi, u8 rifs)
{
u16 holdoff, delay;
if (rifs) {
holdoff = 0x10;
delay = 0x258;
} else {
holdoff = 0x15;
delay = 0x320;
}
wlc_phy_write_txmacreg_nphy(pi, holdoff, delay);
if (pi->sh && (pi->sh->_rifs_phy != rifs))
pi->sh->_rifs_phy = rifs;
}
static void wlc_phy_txpwrctrl_config_nphy(struct brcms_phy *pi)
{
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->nphy_txpwrctrl = PHY_TPC_HW_ON;
pi->phy_5g_pwrgain = true;
return;
}
pi->nphy_txpwrctrl = PHY_TPC_HW_OFF;
pi->phy_5g_pwrgain = false;
if ((pi->sh->boardflags2 & BFL2_TXPWRCTRL_EN) &&
NREV_GE(pi->pubpi.phy_rev, 2) && (pi->sh->sromrev >= 4))
pi->nphy_txpwrctrl = PHY_TPC_HW_ON;
else if ((pi->sh->sromrev >= 4)
&& (pi->sh->boardflags2 & BFL2_5G_PWRGAIN))
pi->phy_5g_pwrgain = true;
}
static void wlc_phy_txpwr_srom_read_ppr_nphy(struct brcms_phy *pi)
{
u16 bw40po, cddpo, stbcpo, bwduppo;
uint band_num;
struct ssb_sprom *sprom = &pi->d11core->bus->sprom;
if (pi->sh->sromrev >= 9)
return;
bw40po = sprom->bw40po;
pi->bw402gpo = bw40po & 0xf;
pi->bw405gpo = (bw40po & 0xf0) >> 4;
pi->bw405glpo = (bw40po & 0xf00) >> 8;
pi->bw405ghpo = (bw40po & 0xf000) >> 12;
cddpo = sprom->cddpo;
pi->cdd2gpo = cddpo & 0xf;
pi->cdd5gpo = (cddpo & 0xf0) >> 4;
pi->cdd5glpo = (cddpo & 0xf00) >> 8;
pi->cdd5ghpo = (cddpo & 0xf000) >> 12;
stbcpo = sprom->stbcpo;
pi->stbc2gpo = stbcpo & 0xf;
pi->stbc5gpo = (stbcpo & 0xf0) >> 4;
pi->stbc5glpo = (stbcpo & 0xf00) >> 8;
pi->stbc5ghpo = (stbcpo & 0xf000) >> 12;
bwduppo = sprom->bwduppo;
pi->bwdup2gpo = bwduppo & 0xf;
pi->bwdup5gpo = (bwduppo & 0xf0) >> 4;
pi->bwdup5glpo = (bwduppo & 0xf00) >> 8;
pi->bwdup5ghpo = (bwduppo & 0xf000) >> 12;
for (band_num = 0; band_num < (CH_2G_GROUP + CH_5G_GROUP);
band_num++) {
switch (band_num) {
case 0:
pi->nphy_pwrctrl_info[PHY_CORE_0].max_pwr_2g =
sprom->core_pwr_info[0].maxpwr_2g;
pi->nphy_pwrctrl_info[PHY_CORE_1].max_pwr_2g =
sprom->core_pwr_info[1].maxpwr_2g;
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_2g_a1 =
sprom->core_pwr_info[0].pa_2g[0];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_2g_a1 =
sprom->core_pwr_info[1].pa_2g[0];
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_2g_b0 =
sprom->core_pwr_info[0].pa_2g[1];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_2g_b0 =
sprom->core_pwr_info[1].pa_2g[1];
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_2g_b1 =
sprom->core_pwr_info[0].pa_2g[2];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_2g_b1 =
sprom->core_pwr_info[1].pa_2g[2];
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_targ_2g =
sprom->core_pwr_info[0].itssi_2g;
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_targ_2g =
sprom->core_pwr_info[1].itssi_2g;
pi->cck2gpo = sprom->cck2gpo;
pi->ofdm2gpo = sprom->ofdm2gpo;
pi->mcs2gpo[0] = sprom->mcs2gpo[0];
pi->mcs2gpo[1] = sprom->mcs2gpo[1];
pi->mcs2gpo[2] = sprom->mcs2gpo[2];
pi->mcs2gpo[3] = sprom->mcs2gpo[3];
pi->mcs2gpo[4] = sprom->mcs2gpo[4];
pi->mcs2gpo[5] = sprom->mcs2gpo[5];
pi->mcs2gpo[6] = sprom->mcs2gpo[6];
pi->mcs2gpo[7] = sprom->mcs2gpo[7];
break;
case 1:
pi->nphy_pwrctrl_info[PHY_CORE_0].max_pwr_5gm =
sprom->core_pwr_info[0].maxpwr_5g;
pi->nphy_pwrctrl_info[PHY_CORE_1].max_pwr_5gm =
sprom->core_pwr_info[1].maxpwr_5g;
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_5gm_a1 =
sprom->core_pwr_info[0].pa_5g[0];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_5gm_a1 =
sprom->core_pwr_info[1].pa_5g[0];
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_5gm_b0 =
sprom->core_pwr_info[0].pa_5g[1];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_5gm_b0 =
sprom->core_pwr_info[1].pa_5g[1];
pi->nphy_pwrctrl_info[PHY_CORE_0].pwrdet_5gm_b1 =
sprom->core_pwr_info[0].pa_5g[2];
pi->nphy_pwrctrl_info[PHY_CORE_1].pwrdet_5gm_b1 =
sprom->core_pwr_info[1].pa_5g[2];
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_targ_5gm =
sprom->core_pwr_info[0].itssi_5g;
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_targ_5gm =
sprom->core_pwr_info[1].itssi_5g;
pi->ofdm5gpo = sprom->ofdm5gpo;
pi->mcs5gpo[0] = sprom->mcs5gpo[0];
pi->mcs5gpo[1] = sprom->mcs5gpo[1];
pi->mcs5gpo[2] = sprom->mcs5gpo[2];
pi->mcs5gpo[3] = sprom->mcs5gpo[3];
pi->mcs5gpo[4] = sprom->mcs5gpo[4];
pi->mcs5gpo[5] = sprom->mcs5gpo[5];
pi->mcs5gpo[6] = sprom->mcs5gpo[6];
pi->mcs5gpo[7] = sprom->mcs5gpo[7];
break;
case 2:
pi->nphy_pwrctrl_info[0].max_pwr_5gl =
sprom->core_pwr_info[0].maxpwr_5gl;
pi->nphy_pwrctrl_info[1].max_pwr_5gl =
sprom->core_pwr_info[1].maxpwr_5gl;
pi->nphy_pwrctrl_info[0].pwrdet_5gl_a1 =
sprom->core_pwr_info[0].pa_5gl[0];
pi->nphy_pwrctrl_info[1].pwrdet_5gl_a1 =
sprom->core_pwr_info[1].pa_5gl[0];
pi->nphy_pwrctrl_info[0].pwrdet_5gl_b0 =
sprom->core_pwr_info[0].pa_5gl[1];
pi->nphy_pwrctrl_info[1].pwrdet_5gl_b0 =
sprom->core_pwr_info[1].pa_5gl[1];
pi->nphy_pwrctrl_info[0].pwrdet_5gl_b1 =
sprom->core_pwr_info[0].pa_5gl[2];
pi->nphy_pwrctrl_info[1].pwrdet_5gl_b1 =
sprom->core_pwr_info[1].pa_5gl[2];
pi->nphy_pwrctrl_info[0].idle_targ_5gl = 0;
pi->nphy_pwrctrl_info[1].idle_targ_5gl = 0;
pi->ofdm5glpo = sprom->ofdm5glpo;
pi->mcs5glpo[0] = sprom->mcs5glpo[0];
pi->mcs5glpo[1] = sprom->mcs5glpo[1];
pi->mcs5glpo[2] = sprom->mcs5glpo[2];
pi->mcs5glpo[3] = sprom->mcs5glpo[3];
pi->mcs5glpo[4] = sprom->mcs5glpo[4];
pi->mcs5glpo[5] = sprom->mcs5glpo[5];
pi->mcs5glpo[6] = sprom->mcs5glpo[6];
pi->mcs5glpo[7] = sprom->mcs5glpo[7];
break;
case 3:
pi->nphy_pwrctrl_info[0].max_pwr_5gh =
sprom->core_pwr_info[0].maxpwr_5gh;
pi->nphy_pwrctrl_info[1].max_pwr_5gh =
sprom->core_pwr_info[1].maxpwr_5gh;
pi->nphy_pwrctrl_info[0].pwrdet_5gh_a1 =
sprom->core_pwr_info[0].pa_5gh[0];
pi->nphy_pwrctrl_info[1].pwrdet_5gh_a1 =
sprom->core_pwr_info[1].pa_5gh[0];
pi->nphy_pwrctrl_info[0].pwrdet_5gh_b0 =
sprom->core_pwr_info[0].pa_5gh[1];
pi->nphy_pwrctrl_info[1].pwrdet_5gh_b0 =
sprom->core_pwr_info[1].pa_5gh[1];
pi->nphy_pwrctrl_info[0].pwrdet_5gh_b1 =
sprom->core_pwr_info[0].pa_5gh[2];
pi->nphy_pwrctrl_info[1].pwrdet_5gh_b1 =
sprom->core_pwr_info[1].pa_5gh[2];
pi->nphy_pwrctrl_info[0].idle_targ_5gh = 0;
pi->nphy_pwrctrl_info[1].idle_targ_5gh = 0;
pi->ofdm5ghpo = sprom->ofdm5ghpo;
pi->mcs5ghpo[0] = sprom->mcs5ghpo[0];
pi->mcs5ghpo[1] = sprom->mcs5ghpo[1];
pi->mcs5ghpo[2] = sprom->mcs5ghpo[2];
pi->mcs5ghpo[3] = sprom->mcs5ghpo[3];
pi->mcs5ghpo[4] = sprom->mcs5ghpo[4];
pi->mcs5ghpo[5] = sprom->mcs5ghpo[5];
pi->mcs5ghpo[6] = sprom->mcs5ghpo[6];
pi->mcs5ghpo[7] = sprom->mcs5ghpo[7];
break;
}
}
wlc_phy_txpwr_apply_nphy(pi);
}
static bool wlc_phy_txpwr_srom_read_nphy(struct brcms_phy *pi)
{
struct ssb_sprom *sprom = &pi->d11core->bus->sprom;
pi->antswitch = sprom->antswitch;
pi->aa2g = sprom->ant_available_bg;
pi->aa5g = sprom->ant_available_a;
pi->srom_fem2g.tssipos = sprom->fem.ghz2.tssipos;
pi->srom_fem2g.extpagain = sprom->fem.ghz2.extpa_gain;
pi->srom_fem2g.pdetrange = sprom->fem.ghz2.pdet_range;
pi->srom_fem2g.triso = sprom->fem.ghz2.tr_iso;
pi->srom_fem2g.antswctrllut = sprom->fem.ghz2.antswlut;
pi->srom_fem5g.tssipos = sprom->fem.ghz5.tssipos;
pi->srom_fem5g.extpagain = sprom->fem.ghz5.extpa_gain;
pi->srom_fem5g.pdetrange = sprom->fem.ghz5.pdet_range;
pi->srom_fem5g.triso = sprom->fem.ghz5.tr_iso;
if (sprom->fem.ghz5.antswlut)
pi->srom_fem5g.antswctrllut = sprom->fem.ghz5.antswlut;
else
pi->srom_fem5g.antswctrllut = sprom->fem.ghz2.antswlut;
wlc_phy_txpower_ipa_upd(pi);
pi->phy_txcore_disable_temp = sprom->tempthresh;
if (pi->phy_txcore_disable_temp == 0)
pi->phy_txcore_disable_temp = PHY_CHAIN_TX_DISABLE_TEMP;
pi->phy_tempsense_offset = sprom->tempoffset;
if (pi->phy_tempsense_offset != 0) {
if (pi->phy_tempsense_offset >
(NPHY_SROM_TEMPSHIFT + NPHY_SROM_MAXTEMPOFFSET))
pi->phy_tempsense_offset = NPHY_SROM_MAXTEMPOFFSET;
else if (pi->phy_tempsense_offset < (NPHY_SROM_TEMPSHIFT +
NPHY_SROM_MINTEMPOFFSET))
pi->phy_tempsense_offset = NPHY_SROM_MINTEMPOFFSET;
else
pi->phy_tempsense_offset -= NPHY_SROM_TEMPSHIFT;
}
pi->phy_txcore_enable_temp =
pi->phy_txcore_disable_temp - PHY_HYSTERESIS_DELTATEMP;
pi->phycal_tempdelta = sprom->phycal_tempdelta;
if (pi->phycal_tempdelta > NPHY_CAL_MAXTEMPDELTA)
pi->phycal_tempdelta = 0;
wlc_phy_txpwr_srom_read_ppr_nphy(pi);
return true;
}
bool wlc_phy_attach_nphy(struct brcms_phy *pi)
{
uint i;
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LT(pi->pubpi.phy_rev, 6))
pi->phyhang_avoid = true;
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LT(pi->pubpi.phy_rev, 7)) {
pi->nphy_gband_spurwar_en = true;
if (pi->sh->boardflags2 & BFL2_SPUR_WAR)
pi->nphy_aband_spurwar_en = true;
}
if (NREV_GE(pi->pubpi.phy_rev, 6) && NREV_LT(pi->pubpi.phy_rev, 7)) {
if (pi->sh->boardflags2 & BFL2_2G_SPUR_WAR)
pi->nphy_gband_spurwar2_en = true;
}
pi->n_preamble_override = AUTO;
if (NREV_IS(pi->pubpi.phy_rev, 3) || NREV_IS(pi->pubpi.phy_rev, 4))
pi->n_preamble_override = BRCMS_N_PREAMBLE_MIXEDMODE;
pi->nphy_txrx_chain = AUTO;
pi->phy_scraminit = AUTO;
pi->nphy_rxcalparams = 0x010100B5;
pi->nphy_perical = PHY_PERICAL_MPHASE;
pi->mphase_cal_phase_id = MPHASE_CAL_STATE_IDLE;
pi->mphase_txcal_numcmds = MPHASE_TXCAL_NUMCMDS;
pi->nphy_gain_boost = true;
pi->nphy_elna_gain_config = false;
pi->radio_is_on = false;
for (i = 0; i < pi->pubpi.phy_corenum; i++)
pi->nphy_txpwrindex[i].index = AUTO;
wlc_phy_txpwrctrl_config_nphy(pi);
if (pi->nphy_txpwrctrl == PHY_TPC_HW_ON)
pi->hwpwrctrl_capable = true;
pi->pi_fptr.init = wlc_phy_init_nphy;
pi->pi_fptr.calinit = wlc_phy_cal_init_nphy;
pi->pi_fptr.chanset = wlc_phy_chanspec_set_nphy;
pi->pi_fptr.txpwrrecalc = wlc_phy_txpower_recalc_target_nphy;
if (!wlc_phy_txpwr_srom_read_nphy(pi))
return false;
return true;
}
static s32 get_rf_pwr_offset(struct brcms_phy *pi, s16 pga_gn, s16 pad_gn)
{
s32 rfpwr_offset = 0;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
rfpwr_offset = (s16)
nphy_papd_padgain_dlt_2g_2057rev3n4
[pad_gn];
else if (pi->pubpi.radiorev == 5)
rfpwr_offset = (s16)
nphy_papd_padgain_dlt_2g_2057rev5
[pad_gn];
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev ==
8))
rfpwr_offset = (s16)
nphy_papd_padgain_dlt_2g_2057rev7
[pad_gn];
} else {
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
rfpwr_offset = (s16)
nphy_papd_pgagain_dlt_5g_2057
[pga_gn];
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev ==
8))
rfpwr_offset = (s16)
nphy_papd_pgagain_dlt_5g_2057rev7
[pga_gn];
}
return rfpwr_offset;
}
static void wlc_phy_update_mimoconfig_nphy(struct brcms_phy *pi, s32 preamble)
{
bool gf_preamble = false;
u16 val;
if (preamble == BRCMS_N_PREAMBLE_GF)
gf_preamble = true;
val = read_phy_reg(pi, 0xed);
val |= RX_GF_MM_AUTO;
val &= ~RX_GF_OR_MM;
if (gf_preamble)
val |= RX_GF_OR_MM;
write_phy_reg(pi, 0xed, val);
}
static void wlc_phy_ipa_set_tx_digi_filts_nphy(struct brcms_phy *pi)
{
int j, type;
u16 addr_offset[] = { 0x186, 0x195, 0x2c5};
for (type = 0; type < 3; type++) {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, addr_offset[type] + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[type][j]);
}
if (pi->bw == WL_CHANSPEC_BW_40) {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, 0x186 + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[3][j]);
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, 0x186 + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[5][j]);
}
if (CHSPEC_CHANNEL(pi->radio_chanspec) == 14) {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, 0x2c5 + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[6][j]);
}
}
}
static void wlc_phy_ipa_restore_tx_digi_filts_nphy(struct brcms_phy *pi)
{
int j;
if (pi->bw == WL_CHANSPEC_BW_40) {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, 0x195 + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[4][j]);
} else {
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, 0x186 + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[3][j]);
}
}
static void
wlc_phy_set_rfseq_nphy(struct brcms_phy *pi, u8 cmd, u8 *events, u8 *dlys,
u8 len)
{
u32 t1_offset, t2_offset;
u8 ctr;
u8 end_event =
NREV_GE(pi->pubpi.phy_rev,
3) ? NPHY_REV3_RFSEQ_CMD_END : NPHY_RFSEQ_CMD_END;
u8 end_dly = 1;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
t1_offset = cmd << 4;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, len, t1_offset, 8,
events);
t2_offset = t1_offset + 0x080;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, len, t2_offset, 8,
dlys);
for (ctr = len; ctr < 16; ctr++) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 1,
t1_offset + ctr, 8, &end_event);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 1,
t2_offset + ctr, 8, &end_dly);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static u16 wlc_phy_read_lpf_bw_ctl_nphy(struct brcms_phy *pi, u16 offset)
{
u16 lpf_bw_ctl_val = 0;
u16 rx2tx_lpf_rc_lut_offset = 0;
if (offset == 0) {
if (CHSPEC_IS40(pi->radio_chanspec))
rx2tx_lpf_rc_lut_offset = 0x159;
else
rx2tx_lpf_rc_lut_offset = 0x154;
} else {
rx2tx_lpf_rc_lut_offset = offset;
}
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 1,
(u32) rx2tx_lpf_rc_lut_offset, 16,
&lpf_bw_ctl_val);
lpf_bw_ctl_val = lpf_bw_ctl_val & 0x7;
return lpf_bw_ctl_val;
}
static void
wlc_phy_rfctrl_override_nphy_rev7(struct brcms_phy *pi, u16 field, u16 value,
u8 core_mask, u8 off, u8 override_id)
{
u8 core_num;
u16 addr = 0, en_addr = 0, val_addr = 0, en_mask = 0, val_mask = 0;
u8 val_shift = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
en_mask = field;
for (core_num = 0; core_num < 2; core_num++) {
if (override_id == NPHY_REV7_RFCTRLOVERRIDE_ID0) {
switch (field) {
case (0x1 << 2):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 1);
val_shift = 1;
break;
case (0x1 << 3):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 2);
val_shift = 2;
break;
case (0x1 << 4):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 4);
val_shift = 4;
break;
case (0x1 << 5):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 5);
val_shift = 5;
break;
case (0x1 << 6):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 6);
val_shift = 6;
break;
case (0x1 << 7):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a :
0x7d;
val_mask = (0x1 << 7);
val_shift = 7;
break;
case (0x1 << 10):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0xf8 :
0xfa;
val_mask = (0x7 << 4);
val_shift = 4;
break;
case (0x1 << 11):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7b :
0x7e;
val_mask = (0xffff << 0);
val_shift = 0;
break;
case (0x1 << 12):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7c :
0x7f;
val_mask = (0xffff << 0);
val_shift = 0;
break;
case (0x3 << 13):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x348 :
0x349;
val_mask = (0xff << 0);
val_shift = 0;
break;
case (0x1 << 13):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x348 :
0x349;
val_mask = (0xf << 0);
val_shift = 0;
break;
default:
addr = 0xffff;
break;
}
} else if (override_id ==
NPHY_REV7_RFCTRLOVERRIDE_ID1) {
switch (field) {
case (0x1 << 1):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 1);
val_shift = 1;
break;
case (0x1 << 3):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 3);
val_shift = 3;
break;
case (0x1 << 5):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 5);
val_shift = 5;
break;
case (0x1 << 4):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 4);
val_shift = 4;
break;
case (0x1 << 2):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 2);
val_shift = 2;
break;
case (0x1 << 7):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x7 << 8);
val_shift = 8;
break;
case (0x1 << 11):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 14);
val_shift = 14;
break;
case (0x1 << 10):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 13);
val_shift = 13;
break;
case (0x1 << 9):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 12);
val_shift = 12;
break;
case (0x1 << 8):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 11);
val_shift = 11;
break;
case (0x1 << 6):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 6);
val_shift = 6;
break;
case (0x1 << 0):
en_addr = (core_num == 0) ? 0x342 :
0x343;
val_addr = (core_num == 0) ? 0x340 :
0x341;
val_mask = (0x1 << 0);
val_shift = 0;
break;
default:
addr = 0xffff;
break;
}
} else if (override_id ==
NPHY_REV7_RFCTRLOVERRIDE_ID2) {
switch (field) {
case (0x1 << 3):
en_addr = (core_num == 0) ? 0x346 :
0x347;
val_addr = (core_num == 0) ? 0x344 :
0x345;
val_mask = (0x1 << 3);
val_shift = 3;
break;
case (0x1 << 1):
en_addr = (core_num == 0) ? 0x346 :
0x347;
val_addr = (core_num == 0) ? 0x344 :
0x345;
val_mask = (0x1 << 1);
val_shift = 1;
break;
case (0x1 << 0):
en_addr = (core_num == 0) ? 0x346 :
0x347;
val_addr = (core_num == 0) ? 0x344 :
0x345;
val_mask = (0x1 << 0);
val_shift = 0;
break;
case (0x1 << 2):
en_addr = (core_num == 0) ? 0x346 :
0x347;
val_addr = (core_num == 0) ? 0x344 :
0x345;
val_mask = (0x1 << 2);
val_shift = 2;
break;
case (0x1 << 4):
en_addr = (core_num == 0) ? 0x346 :
0x347;
val_addr = (core_num == 0) ? 0x344 :
0x345;
val_mask = (0x1 << 4);
val_shift = 4;
break;
default:
addr = 0xffff;
break;
}
}
if (off) {
and_phy_reg(pi, en_addr, ~en_mask);
and_phy_reg(pi, val_addr, ~val_mask);
} else {
if ((core_mask == 0)
|| (core_mask & (1 << core_num))) {
or_phy_reg(pi, en_addr, en_mask);
if (addr != 0xffff)
mod_phy_reg(pi, val_addr,
val_mask,
(value <<
val_shift));
}
}
}
}
}
static void wlc_phy_adjust_lnagaintbl_nphy(struct brcms_phy *pi)
{
uint core;
int ctr;
s16 gain_delta[2];
u8 curr_channel;
u16 minmax_gain[2];
u16 regval[4];
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (pi->nphy_gain_boost) {
if ((CHSPEC_IS2G(pi->radio_chanspec))) {
gain_delta[0] = 6;
gain_delta[1] = 6;
} else {
curr_channel = CHSPEC_CHANNEL(pi->radio_chanspec);
gain_delta[0] =
(s16)
PHY_HW_ROUND(((nphy_lnagain_est0[0] *
curr_channel) +
nphy_lnagain_est0[1]), 13);
gain_delta[1] =
(s16)
PHY_HW_ROUND(((nphy_lnagain_est1[0] *
curr_channel) +
nphy_lnagain_est1[1]), 13);
}
} else {
gain_delta[0] = 0;
gain_delta[1] = 0;
}
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (pi->nphy_elna_gain_config) {
regval[0] = nphy_def_lnagains[2] + gain_delta[core];
regval[1] = nphy_def_lnagains[3] + gain_delta[core];
regval[2] = nphy_def_lnagains[3] + gain_delta[core];
regval[3] = nphy_def_lnagains[3] + gain_delta[core];
} else {
for (ctr = 0; ctr < 4; ctr++)
regval[ctr] =
nphy_def_lnagains[ctr] +
gain_delta[core];
}
wlc_phy_table_write_nphy(pi, core, 4, 8, 16, regval);
minmax_gain[core] =
(u16) (nphy_def_lnagains[2] + gain_delta[core] + 4);
}
mod_phy_reg(pi, 0x1e, (0xff << 0), (minmax_gain[0] << 0));
mod_phy_reg(pi, 0x34, (0xff << 0), (minmax_gain[1] << 0));
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void
wlc_phy_war_force_trsw_to_R_cliplo_nphy(struct brcms_phy *pi, u8 core)
{
if (core == PHY_CORE_0) {
write_phy_reg(pi, 0x38, 0x4);
if (CHSPEC_IS2G(pi->radio_chanspec))
write_phy_reg(pi, 0x37, 0x0060);
else
write_phy_reg(pi, 0x37, 0x1080);
} else if (core == PHY_CORE_1) {
write_phy_reg(pi, 0x2ae, 0x4);
if (CHSPEC_IS2G(pi->radio_chanspec))
write_phy_reg(pi, 0x2ad, 0x0060);
else
write_phy_reg(pi, 0x2ad, 0x1080);
}
}
static void wlc_phy_war_txchain_upd_nphy(struct brcms_phy *pi, u8 txchain)
{
u8 txchain0, txchain1;
txchain0 = txchain & 0x1;
txchain1 = (txchain & 0x2) >> 1;
if (!txchain0)
wlc_phy_war_force_trsw_to_R_cliplo_nphy(pi, PHY_CORE_0);
if (!txchain1)
wlc_phy_war_force_trsw_to_R_cliplo_nphy(pi, PHY_CORE_1);
}
static void wlc_phy_workarounds_nphy_gainctrl_2057_rev5(struct brcms_phy *pi)
{
s8 lna1_gain_db[] = { 8, 13, 17, 22 };
s8 lna2_gain_db[] = { -2, 7, 11, 15 };
s8 tia_gain_db[] = { -4, -1, 2, 5, 5, 5, 5, 5, 5, 5 };
s8 tia_gainbits[] = {
0x0, 0x01, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 };
mod_phy_reg(pi, 0x1c, (0x1 << 13), (1 << 13));
mod_phy_reg(pi, 0x32, (0x1 << 13), (1 << 13));
mod_phy_reg(pi, 0x289, (0xff << 0), (0x46 << 0));
mod_phy_reg(pi, 0x283, (0xff << 0), (0x3c << 0));
mod_phy_reg(pi, 0x280, (0xff << 0), (0x3c << 0));
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 0x8, 8,
lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 0x8, 8,
lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 0x10, 8,
lna2_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 0x10, 8,
lna2_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 10, 0x20, 8,
tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 10, 0x20, 8,
tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS1, 10, 0x20, 8,
tia_gainbits);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS2, 10, 0x20, 8,
tia_gainbits);
write_phy_reg(pi, 0x37, 0x74);
write_phy_reg(pi, 0x2ad, 0x74);
write_phy_reg(pi, 0x38, 0x18);
write_phy_reg(pi, 0x2ae, 0x18);
write_phy_reg(pi, 0x2b, 0xe8);
write_phy_reg(pi, 0x41, 0xe8);
if (CHSPEC_IS20(pi->radio_chanspec)) {
mod_phy_reg(pi, 0x300, (0x3f << 0), (0x12 << 0));
mod_phy_reg(pi, 0x301, (0x3f << 0), (0x12 << 0));
} else {
mod_phy_reg(pi, 0x300, (0x3f << 0), (0x10 << 0));
mod_phy_reg(pi, 0x301, (0x3f << 0), (0x10 << 0));
}
}
static void wlc_phy_workarounds_nphy_gainctrl_2057_rev6(struct brcms_phy *pi)
{
u16 currband;
s8 lna1G_gain_db_rev7[] = { 9, 14, 19, 24 };
s8 *lna1_gain_db = NULL;
s8 *lna1_gain_db_2 = NULL;
s8 *lna2_gain_db = NULL;
s8 tiaA_gain_db_rev7[] = { -9, -6, -3, 0, 3, 3, 3, 3, 3, 3 };
s8 *tia_gain_db;
s8 tiaA_gainbits_rev7[] = { 0, 1, 2, 3, 4, 4, 4, 4, 4, 4 };
s8 *tia_gainbits;
u16 rfseqA_init_gain_rev7[] = { 0x624f, 0x624f };
u16 *rfseq_init_gain;
u16 init_gaincode;
u16 clip1hi_gaincode;
u16 clip1md_gaincode = 0;
u16 clip1md_gaincode_B;
u16 clip1lo_gaincode;
u16 clip1lo_gaincode_B;
u8 crsminl_th = 0;
u8 crsminu_th;
u16 nbclip_th = 0;
u8 w1clip_th;
u16 freq;
s8 nvar_baseline_offset0 = 0, nvar_baseline_offset1 = 0;
u8 chg_nbclip_th = 0;
mod_phy_reg(pi, 0x1c, (0x1 << 13), (1 << 13));
mod_phy_reg(pi, 0x32, (0x1 << 13), (1 << 13));
currband = read_phy_reg(pi, 0x09) & NPHY_BandControl_currentBand;
if (currband == 0) {
lna1_gain_db = lna1G_gain_db_rev7;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 8, 8,
lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 8, 8,
lna1_gain_db);
mod_phy_reg(pi, 0x283, (0xff << 0), (0x40 << 0));
if (CHSPEC_IS40(pi->radio_chanspec)) {
mod_phy_reg(pi, 0x280, (0xff << 0), (0x3e << 0));
mod_phy_reg(pi, 0x283, (0xff << 0), (0x3e << 0));
}
mod_phy_reg(pi, 0x289, (0xff << 0), (0x46 << 0));
if (CHSPEC_IS20(pi->radio_chanspec)) {
mod_phy_reg(pi, 0x300, (0x3f << 0), (13 << 0));
mod_phy_reg(pi, 0x301, (0x3f << 0), (13 << 0));
}
} else {
init_gaincode = 0x9e;
clip1hi_gaincode = 0x9e;
clip1md_gaincode_B = 0x24;
clip1lo_gaincode = 0x8a;
clip1lo_gaincode_B = 8;
rfseq_init_gain = rfseqA_init_gain_rev7;
tia_gain_db = tiaA_gain_db_rev7;
tia_gainbits = tiaA_gainbits_rev7;
freq = CHAN5G_FREQ(CHSPEC_CHANNEL(pi->radio_chanspec));
if (CHSPEC_IS20(pi->radio_chanspec)) {
w1clip_th = 25;
clip1md_gaincode = 0x82;
if ((freq <= 5080) || (freq == 5825)) {
s8 lna1A_gain_db_rev7[] = { 11, 16, 20, 24 };
s8 lna1A_gain_db_2_rev7[] = {
11, 17, 22, 25};
s8 lna2A_gain_db_rev7[] = { -1, 6, 10, 14 };
crsminu_th = 0x3e;
lna1_gain_db = lna1A_gain_db_rev7;
lna1_gain_db_2 = lna1A_gain_db_2_rev7;
lna2_gain_db = lna2A_gain_db_rev7;
} else if ((freq >= 5500) && (freq <= 5700)) {
s8 lna1A_gain_db_rev7[] = { 11, 17, 21, 25 };
s8 lna1A_gain_db_2_rev7[] = {
12, 18, 22, 26};
s8 lna2A_gain_db_rev7[] = { 1, 8, 12, 16 };
crsminu_th = 0x45;
clip1md_gaincode_B = 0x14;
nbclip_th = 0xff;
chg_nbclip_th = 1;
lna1_gain_db = lna1A_gain_db_rev7;
lna1_gain_db_2 = lna1A_gain_db_2_rev7;
lna2_gain_db = lna2A_gain_db_rev7;
} else {
s8 lna1A_gain_db_rev7[] = { 12, 18, 22, 26 };
s8 lna1A_gain_db_2_rev7[] = {
12, 18, 22, 26};
s8 lna2A_gain_db_rev7[] = { -1, 6, 10, 14 };
crsminu_th = 0x41;
lna1_gain_db = lna1A_gain_db_rev7;
lna1_gain_db_2 = lna1A_gain_db_2_rev7;
lna2_gain_db = lna2A_gain_db_rev7;
}
if (freq <= 4920) {
nvar_baseline_offset0 = 5;
nvar_baseline_offset1 = 5;
} else if ((freq > 4920) && (freq <= 5320)) {
nvar_baseline_offset0 = 3;
nvar_baseline_offset1 = 5;
} else if ((freq > 5320) && (freq <= 5700)) {
nvar_baseline_offset0 = 3;
nvar_baseline_offset1 = 2;
} else {
nvar_baseline_offset0 = 4;
nvar_baseline_offset1 = 0;
}
} else {
crsminu_th = 0x3a;
crsminl_th = 0x3a;
w1clip_th = 20;
if ((freq >= 4920) && (freq <= 5320)) {
nvar_baseline_offset0 = 4;
nvar_baseline_offset1 = 5;
} else if ((freq > 5320) && (freq <= 5550)) {
nvar_baseline_offset0 = 4;
nvar_baseline_offset1 = 2;
} else {
nvar_baseline_offset0 = 5;
nvar_baseline_offset1 = 3;
}
}
write_phy_reg(pi, 0x20, init_gaincode);
write_phy_reg(pi, 0x2a7, init_gaincode);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ,
pi->pubpi.phy_corenum, 0x106, 16,
rfseq_init_gain);
write_phy_reg(pi, 0x22, clip1hi_gaincode);
write_phy_reg(pi, 0x2a9, clip1hi_gaincode);
write_phy_reg(pi, 0x36, clip1md_gaincode_B);
write_phy_reg(pi, 0x2ac, clip1md_gaincode_B);
write_phy_reg(pi, 0x37, clip1lo_gaincode);
write_phy_reg(pi, 0x2ad, clip1lo_gaincode);
write_phy_reg(pi, 0x38, clip1lo_gaincode_B);
write_phy_reg(pi, 0x2ae, clip1lo_gaincode_B);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 10, 0x20, 8,
tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 10, 0x20, 8,
tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS1, 10, 0x20, 8,
tia_gainbits);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS2, 10, 0x20, 8,
tia_gainbits);
mod_phy_reg(pi, 0x283, (0xff << 0), (crsminu_th << 0));
if (chg_nbclip_th == 1) {
write_phy_reg(pi, 0x2b, nbclip_th);
write_phy_reg(pi, 0x41, nbclip_th);
}
mod_phy_reg(pi, 0x300, (0x3f << 0), (w1clip_th << 0));
mod_phy_reg(pi, 0x301, (0x3f << 0), (w1clip_th << 0));
mod_phy_reg(pi, 0x2e4,
(0x3f << 0), (nvar_baseline_offset0 << 0));
mod_phy_reg(pi, 0x2e4,
(0x3f << 6), (nvar_baseline_offset1 << 6));
if (CHSPEC_IS20(pi->radio_chanspec)) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 8, 8,
lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 8, 8,
lna1_gain_db_2);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 0x10,
8, lna2_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 0x10,
8, lna2_gain_db);
write_phy_reg(pi, 0x24, clip1md_gaincode);
write_phy_reg(pi, 0x2ab, clip1md_gaincode);
} else {
mod_phy_reg(pi, 0x280, (0xff << 0), (crsminl_th << 0));
}
}
}
static void wlc_phy_workarounds_nphy_gainctrl(struct brcms_phy *pi)
{
u16 w1th, hpf_code, currband;
int ctr;
u8 rfseq_updategainu_events[] = {
NPHY_RFSEQ_CMD_RX_GAIN,
NPHY_RFSEQ_CMD_CLR_HIQ_DIS,
NPHY_RFSEQ_CMD_SET_HPF_BW
};
u8 rfseq_updategainu_dlys[] = { 10, 30, 1 };
s8 lna1G_gain_db[] = { 7, 11, 16, 23 };
s8 lna1G_gain_db_rev4[] = { 8, 12, 17, 25 };
s8 lna1G_gain_db_rev5[] = { 9, 13, 18, 26 };
s8 lna1G_gain_db_rev6[] = { 8, 13, 18, 25 };
s8 lna1G_gain_db_rev6_224B0[] = { 10, 14, 19, 27 };
s8 lna1A_gain_db[] = { 7, 11, 17, 23 };
s8 lna1A_gain_db_rev4[] = { 8, 12, 18, 23 };
s8 lna1A_gain_db_rev5[] = { 6, 10, 16, 21 };
s8 lna1A_gain_db_rev6[] = { 6, 10, 16, 21 };
s8 *lna1_gain_db = NULL;
s8 lna2G_gain_db[] = { -5, 6, 10, 14 };
s8 lna2G_gain_db_rev5[] = { -3, 7, 11, 16 };
s8 lna2G_gain_db_rev6[] = { -5, 6, 10, 14 };
s8 lna2G_gain_db_rev6_224B0[] = { -5, 6, 10, 15 };
s8 lna2A_gain_db[] = { -6, 2, 6, 10 };
s8 lna2A_gain_db_rev4[] = { -5, 2, 6, 10 };
s8 lna2A_gain_db_rev5[] = { -7, 0, 4, 8 };
s8 lna2A_gain_db_rev6[] = { -7, 0, 4, 8 };
s8 *lna2_gain_db = NULL;
s8 tiaG_gain_db[] = {
0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A };
s8 tiaA_gain_db[] = {
0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13 };
s8 tiaA_gain_db_rev4[] = {
0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d };
s8 tiaA_gain_db_rev5[] = {
0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d };
s8 tiaA_gain_db_rev6[] = {
0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d };
s8 *tia_gain_db;
s8 tiaG_gainbits[] = {
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 };
s8 tiaA_gainbits[] = {
0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06 };
s8 tiaA_gainbits_rev4[] = {
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 };
s8 tiaA_gainbits_rev5[] = {
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 };
s8 tiaA_gainbits_rev6[] = {
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 };
s8 *tia_gainbits;
s8 lpf_gain_db[] = { 0x00, 0x06, 0x0c, 0x12, 0x12, 0x12 };
s8 lpf_gainbits[] = { 0x00, 0x01, 0x02, 0x03, 0x03, 0x03 };
u16 rfseqG_init_gain[] = { 0x613f, 0x613f, 0x613f, 0x613f };
u16 rfseqG_init_gain_rev4[] = { 0x513f, 0x513f, 0x513f, 0x513f };
u16 rfseqG_init_gain_rev5[] = { 0x413f, 0x413f, 0x413f, 0x413f };
u16 rfseqG_init_gain_rev5_elna[] = {
0x013f, 0x013f, 0x013f, 0x013f };
u16 rfseqG_init_gain_rev6[] = { 0x513f, 0x513f };
u16 rfseqG_init_gain_rev6_224B0[] = { 0x413f, 0x413f };
u16 rfseqG_init_gain_rev6_elna[] = { 0x113f, 0x113f };
u16 rfseqA_init_gain[] = { 0x516f, 0x516f, 0x516f, 0x516f };
u16 rfseqA_init_gain_rev4[] = { 0x614f, 0x614f, 0x614f, 0x614f };
u16 rfseqA_init_gain_rev4_elna[] = {
0x314f, 0x314f, 0x314f, 0x314f };
u16 rfseqA_init_gain_rev5[] = { 0x714f, 0x714f, 0x714f, 0x714f };
u16 rfseqA_init_gain_rev6[] = { 0x714f, 0x714f };
u16 *rfseq_init_gain;
u16 initG_gaincode = 0x627e;
u16 initG_gaincode_rev4 = 0x527e;
u16 initG_gaincode_rev5 = 0x427e;
u16 initG_gaincode_rev5_elna = 0x027e;
u16 initG_gaincode_rev6 = 0x527e;
u16 initG_gaincode_rev6_224B0 = 0x427e;
u16 initG_gaincode_rev6_elna = 0x127e;
u16 initA_gaincode = 0x52de;
u16 initA_gaincode_rev4 = 0x629e;
u16 initA_gaincode_rev4_elna = 0x329e;
u16 initA_gaincode_rev5 = 0x729e;
u16 initA_gaincode_rev6 = 0x729e;
u16 init_gaincode;
u16 clip1hiG_gaincode = 0x107e;
u16 clip1hiG_gaincode_rev4 = 0x007e;
u16 clip1hiG_gaincode_rev5 = 0x1076;
u16 clip1hiG_gaincode_rev6 = 0x007e;
u16 clip1hiA_gaincode = 0x00de;
u16 clip1hiA_gaincode_rev4 = 0x029e;
u16 clip1hiA_gaincode_rev5 = 0x029e;
u16 clip1hiA_gaincode_rev6 = 0x029e;
u16 clip1hi_gaincode;
u16 clip1mdG_gaincode = 0x0066;
u16 clip1mdA_gaincode = 0x00ca;
u16 clip1mdA_gaincode_rev4 = 0x1084;
u16 clip1mdA_gaincode_rev5 = 0x2084;
u16 clip1mdA_gaincode_rev6 = 0x2084;
u16 clip1md_gaincode = 0;
u16 clip1loG_gaincode = 0x0074;
u16 clip1loG_gaincode_rev5[] = {
0x0062, 0x0064, 0x006a, 0x106a, 0x106c, 0x1074, 0x107c, 0x207c
};
u16 clip1loG_gaincode_rev6[] = {
0x106a, 0x106c, 0x1074, 0x107c, 0x007e, 0x107e, 0x207e, 0x307e
};
u16 clip1loG_gaincode_rev6_224B0 = 0x1074;
u16 clip1loA_gaincode = 0x00cc;
u16 clip1loA_gaincode_rev4 = 0x0086;
u16 clip1loA_gaincode_rev5 = 0x2086;
u16 clip1loA_gaincode_rev6 = 0x2086;
u16 clip1lo_gaincode;
u8 crsminG_th = 0x18;
u8 crsminG_th_rev5 = 0x18;
u8 crsminG_th_rev6 = 0x18;
u8 crsminA_th = 0x1e;
u8 crsminA_th_rev4 = 0x24;
u8 crsminA_th_rev5 = 0x24;
u8 crsminA_th_rev6 = 0x24;
u8 crsmin_th;
u8 crsminlG_th = 0x18;
u8 crsminlG_th_rev5 = 0x18;
u8 crsminlG_th_rev6 = 0x18;
u8 crsminlA_th = 0x1e;
u8 crsminlA_th_rev4 = 0x24;
u8 crsminlA_th_rev5 = 0x24;
u8 crsminlA_th_rev6 = 0x24;
u8 crsminl_th = 0;
u8 crsminuG_th = 0x18;
u8 crsminuG_th_rev5 = 0x18;
u8 crsminuG_th_rev6 = 0x18;
u8 crsminuA_th = 0x1e;
u8 crsminuA_th_rev4 = 0x24;
u8 crsminuA_th_rev5 = 0x24;
u8 crsminuA_th_rev6 = 0x24;
u8 crsminuA_th_rev6_224B0 = 0x2d;
u8 crsminu_th;
u16 nbclipG_th = 0x20d;
u16 nbclipG_th_rev4 = 0x1a1;
u16 nbclipG_th_rev5 = 0x1d0;
u16 nbclipG_th_rev6 = 0x1d0;
u16 nbclipA_th = 0x1a1;
u16 nbclipA_th_rev4 = 0x107;
u16 nbclipA_th_rev5 = 0x0a9;
u16 nbclipA_th_rev6 = 0x0f0;
u16 nbclip_th = 0;
u8 w1clipG_th = 5;
u8 w1clipG_th_rev5 = 9;
u8 w1clipG_th_rev6 = 5;
u8 w1clipA_th = 25, w1clip_th;
u8 rssi_gain_default = 0x50;
u8 rssiG_gain_rev6_224B0 = 0x50;
u8 rssiA_gain_rev5 = 0x90;
u8 rssiA_gain_rev6 = 0x90;
u8 rssi_gain;
u16 regval[21];
u8 triso;
triso = (CHSPEC_IS5G(pi->radio_chanspec)) ? pi->srom_fem5g.triso :
pi->srom_fem2g.triso;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (pi->pubpi.radiorev == 5) {
wlc_phy_workarounds_nphy_gainctrl_2057_rev5(pi);
} else if (pi->pubpi.radiorev == 7) {
wlc_phy_workarounds_nphy_gainctrl_2057_rev6(pi);
mod_phy_reg(pi, 0x283, (0xff << 0), (0x44 << 0));
mod_phy_reg(pi, 0x280, (0xff << 0), (0x44 << 0));
} else if ((pi->pubpi.radiorev == 3)
|| (pi->pubpi.radiorev == 8)) {
wlc_phy_workarounds_nphy_gainctrl_2057_rev6(pi);
if (pi->pubpi.radiorev == 8) {
mod_phy_reg(pi, 0x283,
(0xff << 0), (0x44 << 0));
mod_phy_reg(pi, 0x280,
(0xff << 0), (0x44 << 0));
}
} else {
wlc_phy_workarounds_nphy_gainctrl_2057_rev6(pi);
}
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
mod_phy_reg(pi, 0xa0, (0x1 << 6), (1 << 6));
mod_phy_reg(pi, 0x1c, (0x1 << 13), (1 << 13));
mod_phy_reg(pi, 0x32, (0x1 << 13), (1 << 13));
currband =
read_phy_reg(pi, 0x09) & NPHY_BandControl_currentBand;
if (currband == 0) {
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
if (pi->pubpi.radiorev == 11) {
lna1_gain_db = lna1G_gain_db_rev6_224B0;
lna2_gain_db = lna2G_gain_db_rev6_224B0;
rfseq_init_gain =
rfseqG_init_gain_rev6_224B0;
init_gaincode =
initG_gaincode_rev6_224B0;
clip1hi_gaincode =
clip1hiG_gaincode_rev6;
clip1lo_gaincode =
clip1loG_gaincode_rev6_224B0;
nbclip_th = nbclipG_th_rev6;
w1clip_th = w1clipG_th_rev6;
crsmin_th = crsminG_th_rev6;
crsminl_th = crsminlG_th_rev6;
crsminu_th = crsminuG_th_rev6;
rssi_gain = rssiG_gain_rev6_224B0;
} else {
lna1_gain_db = lna1G_gain_db_rev6;
lna2_gain_db = lna2G_gain_db_rev6;
if (pi->sh->boardflags & BFL_EXTLNA) {
rfseq_init_gain =
rfseqG_init_gain_rev6_elna;
init_gaincode =
initG_gaincode_rev6_elna;
} else {
rfseq_init_gain =
rfseqG_init_gain_rev6;
init_gaincode =
initG_gaincode_rev6;
}
clip1hi_gaincode =
clip1hiG_gaincode_rev6;
switch (triso) {
case 0:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[0];
break;
case 1:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[1];
break;
case 2:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[2];
break;
case 3:
default:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[3];
break;
case 4:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[4];
break;
case 5:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[5];
break;
case 6:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[6];
break;
case 7:
clip1lo_gaincode =
clip1loG_gaincode_rev6
[7];
break;
}
nbclip_th = nbclipG_th_rev6;
w1clip_th = w1clipG_th_rev6;
crsmin_th = crsminG_th_rev6;
crsminl_th = crsminlG_th_rev6;
crsminu_th = crsminuG_th_rev6;
rssi_gain = rssi_gain_default;
}
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
lna1_gain_db = lna1G_gain_db_rev5;
lna2_gain_db = lna2G_gain_db_rev5;
if (pi->sh->boardflags & BFL_EXTLNA) {
rfseq_init_gain =
rfseqG_init_gain_rev5_elna;
init_gaincode =
initG_gaincode_rev5_elna;
} else {
rfseq_init_gain = rfseqG_init_gain_rev5;
init_gaincode = initG_gaincode_rev5;
}
clip1hi_gaincode = clip1hiG_gaincode_rev5;
switch (triso) {
case 0:
clip1lo_gaincode =
clip1loG_gaincode_rev5[0];
break;
case 1:
clip1lo_gaincode =
clip1loG_gaincode_rev5[1];
break;
case 2:
clip1lo_gaincode =
clip1loG_gaincode_rev5[2];
break;
case 3:
clip1lo_gaincode =
clip1loG_gaincode_rev5[3];
break;
case 4:
clip1lo_gaincode =
clip1loG_gaincode_rev5[4];
break;
case 5:
clip1lo_gaincode =
clip1loG_gaincode_rev5[5];
break;
case 6:
clip1lo_gaincode =
clip1loG_gaincode_rev5[6];
break;
case 7:
clip1lo_gaincode =
clip1loG_gaincode_rev5[7];
break;
default:
clip1lo_gaincode =
clip1loG_gaincode_rev5[3];
break;
}
nbclip_th = nbclipG_th_rev5;
w1clip_th = w1clipG_th_rev5;
crsmin_th = crsminG_th_rev5;
crsminl_th = crsminlG_th_rev5;
crsminu_th = crsminuG_th_rev5;
rssi_gain = rssi_gain_default;
} else if (NREV_IS(pi->pubpi.phy_rev, 4)) {
lna1_gain_db = lna1G_gain_db_rev4;
lna2_gain_db = lna2G_gain_db;
rfseq_init_gain = rfseqG_init_gain_rev4;
init_gaincode = initG_gaincode_rev4;
clip1hi_gaincode = clip1hiG_gaincode_rev4;
clip1lo_gaincode = clip1loG_gaincode;
nbclip_th = nbclipG_th_rev4;
w1clip_th = w1clipG_th;
crsmin_th = crsminG_th;
crsminl_th = crsminlG_th;
crsminu_th = crsminuG_th;
rssi_gain = rssi_gain_default;
} else {
lna1_gain_db = lna1G_gain_db;
lna2_gain_db = lna2G_gain_db;
rfseq_init_gain = rfseqG_init_gain;
init_gaincode = initG_gaincode;
clip1hi_gaincode = clip1hiG_gaincode;
clip1lo_gaincode = clip1loG_gaincode;
nbclip_th = nbclipG_th;
w1clip_th = w1clipG_th;
crsmin_th = crsminG_th;
crsminl_th = crsminlG_th;
crsminu_th = crsminuG_th;
rssi_gain = rssi_gain_default;
}
tia_gain_db = tiaG_gain_db;
tia_gainbits = tiaG_gainbits;
clip1md_gaincode = clip1mdG_gaincode;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
lna1_gain_db = lna1A_gain_db_rev6;
lna2_gain_db = lna2A_gain_db_rev6;
tia_gain_db = tiaA_gain_db_rev6;
tia_gainbits = tiaA_gainbits_rev6;
rfseq_init_gain = rfseqA_init_gain_rev6;
init_gaincode = initA_gaincode_rev6;
clip1hi_gaincode = clip1hiA_gaincode_rev6;
clip1md_gaincode = clip1mdA_gaincode_rev6;
clip1lo_gaincode = clip1loA_gaincode_rev6;
crsmin_th = crsminA_th_rev6;
crsminl_th = crsminlA_th_rev6;
if ((pi->pubpi.radiorev == 11) &&
(CHSPEC_IS40(pi->radio_chanspec) == 0))
crsminu_th = crsminuA_th_rev6_224B0;
else
crsminu_th = crsminuA_th_rev6;
nbclip_th = nbclipA_th_rev6;
rssi_gain = rssiA_gain_rev6;
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
lna1_gain_db = lna1A_gain_db_rev5;
lna2_gain_db = lna2A_gain_db_rev5;
tia_gain_db = tiaA_gain_db_rev5;
tia_gainbits = tiaA_gainbits_rev5;
rfseq_init_gain = rfseqA_init_gain_rev5;
init_gaincode = initA_gaincode_rev5;
clip1hi_gaincode = clip1hiA_gaincode_rev5;
clip1md_gaincode = clip1mdA_gaincode_rev5;
clip1lo_gaincode = clip1loA_gaincode_rev5;
crsmin_th = crsminA_th_rev5;
crsminl_th = crsminlA_th_rev5;
crsminu_th = crsminuA_th_rev5;
nbclip_th = nbclipA_th_rev5;
rssi_gain = rssiA_gain_rev5;
} else if (NREV_IS(pi->pubpi.phy_rev, 4)) {
lna1_gain_db = lna1A_gain_db_rev4;
lna2_gain_db = lna2A_gain_db_rev4;
tia_gain_db = tiaA_gain_db_rev4;
tia_gainbits = tiaA_gainbits_rev4;
if (pi->sh->boardflags & BFL_EXTLNA_5GHz) {
rfseq_init_gain =
rfseqA_init_gain_rev4_elna;
init_gaincode =
initA_gaincode_rev4_elna;
} else {
rfseq_init_gain = rfseqA_init_gain_rev4;
init_gaincode = initA_gaincode_rev4;
}
clip1hi_gaincode = clip1hiA_gaincode_rev4;
clip1md_gaincode = clip1mdA_gaincode_rev4;
clip1lo_gaincode = clip1loA_gaincode_rev4;
crsmin_th = crsminA_th_rev4;
crsminl_th = crsminlA_th_rev4;
crsminu_th = crsminuA_th_rev4;
nbclip_th = nbclipA_th_rev4;
rssi_gain = rssi_gain_default;
} else {
lna1_gain_db = lna1A_gain_db;
lna2_gain_db = lna2A_gain_db;
tia_gain_db = tiaA_gain_db;
tia_gainbits = tiaA_gainbits;
rfseq_init_gain = rfseqA_init_gain;
init_gaincode = initA_gaincode;
clip1hi_gaincode = clip1hiA_gaincode;
clip1md_gaincode = clip1mdA_gaincode;
clip1lo_gaincode = clip1loA_gaincode;
crsmin_th = crsminA_th;
crsminl_th = crsminlA_th;
crsminu_th = crsminuA_th;
nbclip_th = nbclipA_th;
rssi_gain = rssi_gain_default;
}
w1clip_th = w1clipA_th;
}
write_radio_reg(pi,
(RADIO_2056_RX_BIASPOLE_LNAG1_IDAC |
RADIO_2056_RX0), 0x17);
write_radio_reg(pi,
(RADIO_2056_RX_BIASPOLE_LNAG1_IDAC |
RADIO_2056_RX1), 0x17);
write_radio_reg(pi, (RADIO_2056_RX_LNAG2_IDAC | RADIO_2056_RX0),
0xf0);
write_radio_reg(pi, (RADIO_2056_RX_LNAG2_IDAC | RADIO_2056_RX1),
0xf0);
write_radio_reg(pi, (RADIO_2056_RX_RSSI_POLE | RADIO_2056_RX0),
0x0);
write_radio_reg(pi, (RADIO_2056_RX_RSSI_POLE | RADIO_2056_RX1),
0x0);
write_radio_reg(pi, (RADIO_2056_RX_RSSI_GAIN | RADIO_2056_RX0),
rssi_gain);
write_radio_reg(pi, (RADIO_2056_RX_RSSI_GAIN | RADIO_2056_RX1),
rssi_gain);
write_radio_reg(pi,
(RADIO_2056_RX_BIASPOLE_LNAA1_IDAC |
RADIO_2056_RX0), 0x17);
write_radio_reg(pi,
(RADIO_2056_RX_BIASPOLE_LNAA1_IDAC |
RADIO_2056_RX1), 0x17);
write_radio_reg(pi, (RADIO_2056_RX_LNAA2_IDAC | RADIO_2056_RX0),
0xFF);
write_radio_reg(pi, (RADIO_2056_RX_LNAA2_IDAC | RADIO_2056_RX1),
0xFF);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 8,
8, lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 8,
8, lna1_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 4, 0x10,
8, lna2_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 4, 0x10,
8, lna2_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 10, 0x20,
8, tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 10, 0x20,
8, tia_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS1, 10, 0x20,
8, tia_gainbits);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS2, 10, 0x20,
8, tia_gainbits);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN1, 6, 0x40,
8, &lpf_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAIN2, 6, 0x40,
8, &lpf_gain_db);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS1, 6, 0x40,
8, &lpf_gainbits);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_GAINBITS2, 6, 0x40,
8, &lpf_gainbits);
write_phy_reg(pi, 0x20, init_gaincode);
write_phy_reg(pi, 0x2a7, init_gaincode);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ,
pi->pubpi.phy_corenum, 0x106, 16,
rfseq_init_gain);
write_phy_reg(pi, 0x22, clip1hi_gaincode);
write_phy_reg(pi, 0x2a9, clip1hi_gaincode);
write_phy_reg(pi, 0x24, clip1md_gaincode);
write_phy_reg(pi, 0x2ab, clip1md_gaincode);
write_phy_reg(pi, 0x37, clip1lo_gaincode);
write_phy_reg(pi, 0x2ad, clip1lo_gaincode);
mod_phy_reg(pi, 0x27d, (0xff << 0), (crsmin_th << 0));
mod_phy_reg(pi, 0x280, (0xff << 0), (crsminl_th << 0));
mod_phy_reg(pi, 0x283, (0xff << 0), (crsminu_th << 0));
write_phy_reg(pi, 0x2b, nbclip_th);
write_phy_reg(pi, 0x41, nbclip_th);
mod_phy_reg(pi, 0x27, (0x3f << 0), (w1clip_th << 0));
mod_phy_reg(pi, 0x3d, (0x3f << 0), (w1clip_th << 0));
write_phy_reg(pi, 0x150, 0x809c);
} else {
mod_phy_reg(pi, 0x1c, (0x1 << 13), (1 << 13));
mod_phy_reg(pi, 0x32, (0x1 << 13), (1 << 13));
write_phy_reg(pi, 0x2b, 0x84);
write_phy_reg(pi, 0x41, 0x84);
if (CHSPEC_IS20(pi->radio_chanspec)) {
write_phy_reg(pi, 0x6b, 0x2b);
write_phy_reg(pi, 0x6c, 0x2b);
write_phy_reg(pi, 0x6d, 0x9);
write_phy_reg(pi, 0x6e, 0x9);
}
w1th = NPHY_RSSICAL_W1_TARGET - 4;
mod_phy_reg(pi, 0x27, (0x3f << 0), (w1th << 0));
mod_phy_reg(pi, 0x3d, (0x3f << 0), (w1th << 0));
if (CHSPEC_IS20(pi->radio_chanspec)) {
mod_phy_reg(pi, 0x1c, (0x1f << 0), (0x1 << 0));
mod_phy_reg(pi, 0x32, (0x1f << 0), (0x1 << 0));
mod_phy_reg(pi, 0x1d, (0x1f << 0), (0x1 << 0));
mod_phy_reg(pi, 0x33, (0x1f << 0), (0x1 << 0));
}
write_phy_reg(pi, 0x150, 0x809c);
if (pi->nphy_gain_boost)
if ((CHSPEC_IS2G(pi->radio_chanspec)) &&
(CHSPEC_IS40(pi->radio_chanspec)))
hpf_code = 4;
else
hpf_code = 5;
else if (CHSPEC_IS40(pi->radio_chanspec))
hpf_code = 6;
else
hpf_code = 7;
mod_phy_reg(pi, 0x20, (0x1f << 7), (hpf_code << 7));
mod_phy_reg(pi, 0x36, (0x1f << 7), (hpf_code << 7));
for (ctr = 0; ctr < 4; ctr++)
regval[ctr] = (hpf_code << 8) | 0x7c;
wlc_phy_table_write_nphy(pi, 7, 4, 0x106, 16, regval);
wlc_phy_adjust_lnagaintbl_nphy(pi);
if (pi->nphy_elna_gain_config) {
regval[0] = 0;
regval[1] = 1;
regval[2] = 1;
regval[3] = 1;
wlc_phy_table_write_nphy(pi, 2, 4, 8, 16, regval);
wlc_phy_table_write_nphy(pi, 3, 4, 8, 16, regval);
for (ctr = 0; ctr < 4; ctr++)
regval[ctr] = (hpf_code << 8) | 0x74;
wlc_phy_table_write_nphy(pi, 7, 4, 0x106, 16, regval);
}
if (NREV_IS(pi->pubpi.phy_rev, 2)) {
for (ctr = 0; ctr < 21; ctr++)
regval[ctr] = 3 * ctr;
wlc_phy_table_write_nphy(pi, 0, 21, 32, 16, regval);
wlc_phy_table_write_nphy(pi, 1, 21, 32, 16, regval);
for (ctr = 0; ctr < 21; ctr++)
regval[ctr] = (u16) ctr;
wlc_phy_table_write_nphy(pi, 2, 21, 32, 16, regval);
wlc_phy_table_write_nphy(pi, 3, 21, 32, 16, regval);
}
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_UPDATEGAINU,
rfseq_updategainu_events,
rfseq_updategainu_dlys,
sizeof(rfseq_updategainu_events) /
sizeof(rfseq_updategainu_events[0]));
mod_phy_reg(pi, 0x153, (0xff << 8), (90 << 8));
if (CHSPEC_IS2G(pi->radio_chanspec))
mod_phy_reg(pi,
(NPHY_TO_BPHY_OFF + BPHY_OPTIONAL_MODES),
0x7f, 0x4);
}
}
static void wlc_phy_workarounds_nphy(struct brcms_phy *pi)
{
u8 rfseq_rx2tx_events[] = {
NPHY_RFSEQ_CMD_NOP,
NPHY_RFSEQ_CMD_RXG_FBW,
NPHY_RFSEQ_CMD_TR_SWITCH,
NPHY_RFSEQ_CMD_CLR_HIQ_DIS,
NPHY_RFSEQ_CMD_RXPD_TXPD,
NPHY_RFSEQ_CMD_TX_GAIN,
NPHY_RFSEQ_CMD_EXT_PA
};
u8 rfseq_rx2tx_dlys[] = { 8, 6, 6, 2, 4, 60, 1 };
u8 rfseq_tx2rx_events[] = {
NPHY_RFSEQ_CMD_NOP,
NPHY_RFSEQ_CMD_EXT_PA,
NPHY_RFSEQ_CMD_TX_GAIN,
NPHY_RFSEQ_CMD_RXPD_TXPD,
NPHY_RFSEQ_CMD_TR_SWITCH,
NPHY_RFSEQ_CMD_RXG_FBW,
NPHY_RFSEQ_CMD_CLR_HIQ_DIS
};
u8 rfseq_tx2rx_dlys[] = { 8, 6, 2, 4, 4, 6, 1 };
u8 rfseq_tx2rx_events_rev3[] = {
NPHY_REV3_RFSEQ_CMD_EXT_PA,
NPHY_REV3_RFSEQ_CMD_INT_PA_PU,
NPHY_REV3_RFSEQ_CMD_TX_GAIN,
NPHY_REV3_RFSEQ_CMD_RXPD_TXPD,
NPHY_REV3_RFSEQ_CMD_TR_SWITCH,
NPHY_REV3_RFSEQ_CMD_RXG_FBW,
NPHY_REV3_RFSEQ_CMD_CLR_HIQ_DIS,
NPHY_REV3_RFSEQ_CMD_END
};
u8 rfseq_tx2rx_dlys_rev3[] = { 8, 4, 2, 2, 4, 4, 6, 1 };
u8 rfseq_rx2tx_events_rev3[] = {
NPHY_REV3_RFSEQ_CMD_NOP,
NPHY_REV3_RFSEQ_CMD_RXG_FBW,
NPHY_REV3_RFSEQ_CMD_TR_SWITCH,
NPHY_REV3_RFSEQ_CMD_CLR_HIQ_DIS,
NPHY_REV3_RFSEQ_CMD_RXPD_TXPD,
NPHY_REV3_RFSEQ_CMD_TX_GAIN,
NPHY_REV3_RFSEQ_CMD_INT_PA_PU,
NPHY_REV3_RFSEQ_CMD_EXT_PA,
NPHY_REV3_RFSEQ_CMD_END
};
u8 rfseq_rx2tx_dlys_rev3[] = { 8, 6, 6, 4, 4, 18, 42, 1, 1 };
u8 rfseq_rx2tx_events_rev3_ipa[] = {
NPHY_REV3_RFSEQ_CMD_NOP,
NPHY_REV3_RFSEQ_CMD_RXG_FBW,
NPHY_REV3_RFSEQ_CMD_TR_SWITCH,
NPHY_REV3_RFSEQ_CMD_CLR_HIQ_DIS,
NPHY_REV3_RFSEQ_CMD_RXPD_TXPD,
NPHY_REV3_RFSEQ_CMD_TX_GAIN,
NPHY_REV3_RFSEQ_CMD_CLR_RXRX_BIAS,
NPHY_REV3_RFSEQ_CMD_INT_PA_PU,
NPHY_REV3_RFSEQ_CMD_END
};
u8 rfseq_rx2tx_dlys_rev3_ipa[] = { 8, 6, 6, 4, 4, 16, 43, 1, 1 };
u16 rfseq_rx2tx_dacbufpu_rev7[] = { 0x10f, 0x10f };
s16 alpha0, alpha1, alpha2;
s16 beta0, beta1, beta2;
u32 leg_data_weights, ht_data_weights, nss1_data_weights,
stbc_data_weights;
u8 chan_freq_range = 0;
u16 dac_control = 0x0002;
u16 aux_adc_vmid_rev7_core0[] = { 0x8e, 0x96, 0x96, 0x96 };
u16 aux_adc_vmid_rev7_core1[] = { 0x8f, 0x9f, 0x9f, 0x96 };
u16 aux_adc_vmid_rev4[] = { 0xa2, 0xb4, 0xb4, 0x89 };
u16 aux_adc_vmid_rev3[] = { 0xa2, 0xb4, 0xb4, 0x89 };
u16 *aux_adc_vmid;
u16 aux_adc_gain_rev7[] = { 0x02, 0x02, 0x02, 0x02 };
u16 aux_adc_gain_rev4[] = { 0x02, 0x02, 0x02, 0x00 };
u16 aux_adc_gain_rev3[] = { 0x02, 0x02, 0x02, 0x00 };
u16 *aux_adc_gain;
u16 sk_adc_vmid[] = { 0xb4, 0xb4, 0xb4, 0x24 };
u16 sk_adc_gain[] = { 0x02, 0x02, 0x02, 0x02 };
s32 min_nvar_val = 0x18d;
s32 min_nvar_offset_6mbps = 20;
u8 pdetrange;
u8 triso;
u16 regval;
u16 afectrl_adc_ctrl1_rev7 = 0x20;
u16 afectrl_adc_ctrl2_rev7 = 0x0;
u16 rfseq_rx2tx_lpf_h_hpc_rev7 = 0x77;
u16 rfseq_tx2rx_lpf_h_hpc_rev7 = 0x77;
u16 rfseq_pktgn_lpf_h_hpc_rev7 = 0x77;
u16 rfseq_htpktgn_lpf_hpc_rev7[] = { 0x77, 0x11, 0x11 };
u16 rfseq_pktgn_lpf_hpc_rev7[] = { 0x11, 0x11 };
u16 rfseq_cckpktgn_lpf_hpc_rev7[] = { 0x11, 0x11 };
u16 ipalvlshift_3p3_war_en = 0;
u16 rccal_bcap_val, rccal_scap_val;
u16 rccal_tx20_11b_bcap = 0;
u16 rccal_tx20_11b_scap = 0;
u16 rccal_tx20_11n_bcap = 0;
u16 rccal_tx20_11n_scap = 0;
u16 rccal_tx40_11n_bcap = 0;
u16 rccal_tx40_11n_scap = 0;
u16 rx2tx_lpf_rc_lut_tx20_11b = 0;
u16 rx2tx_lpf_rc_lut_tx20_11n = 0;
u16 rx2tx_lpf_rc_lut_tx40_11n = 0;
u16 tx_lpf_bw_ofdm_20mhz = 0;
u16 tx_lpf_bw_ofdm_40mhz = 0;
u16 tx_lpf_bw_11b = 0;
u16 ipa2g_mainbias, ipa2g_casconv, ipa2g_biasfilt;
u16 txgm_idac_bleed = 0;
bool rccal_ovrd = false;
u16 freq;
int coreNum;
if (CHSPEC_IS5G(pi->radio_chanspec))
wlc_phy_classifier_nphy(pi, NPHY_ClassifierCtrl_cck_en, 0);
else
wlc_phy_classifier_nphy(pi, NPHY_ClassifierCtrl_cck_en, 1);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
or_phy_reg(pi, 0xb1, NPHY_IQFlip_ADC1 | NPHY_IQFlip_ADC2);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (NREV_IS(pi->pubpi.phy_rev, 7)) {
mod_phy_reg(pi, 0x221, (0x1 << 4), (1 << 4));
mod_phy_reg(pi, 0x160, (0x7f << 0), (32 << 0));
mod_phy_reg(pi, 0x160, (0x7f << 8), (39 << 8));
mod_phy_reg(pi, 0x161, (0x7f << 0), (46 << 0));
mod_phy_reg(pi, 0x161, (0x7f << 8), (51 << 8));
mod_phy_reg(pi, 0x162, (0x7f << 0), (55 << 0));
mod_phy_reg(pi, 0x162, (0x7f << 8), (58 << 8));
mod_phy_reg(pi, 0x163, (0x7f << 0), (60 << 0));
mod_phy_reg(pi, 0x163, (0x7f << 8), (62 << 8));
mod_phy_reg(pi, 0x164, (0x7f << 0), (62 << 0));
mod_phy_reg(pi, 0x164, (0x7f << 8), (63 << 8));
mod_phy_reg(pi, 0x165, (0x7f << 0), (63 << 0));
mod_phy_reg(pi, 0x165, (0x7f << 8), (64 << 8));
mod_phy_reg(pi, 0x166, (0x7f << 0), (64 << 0));
mod_phy_reg(pi, 0x166, (0x7f << 8), (64 << 8));
mod_phy_reg(pi, 0x167, (0x7f << 0), (64 << 0));
mod_phy_reg(pi, 0x167, (0x7f << 8), (64 << 8));
}
if (NREV_LE(pi->pubpi.phy_rev, 8)) {
write_phy_reg(pi, 0x23f, 0x1b0);
write_phy_reg(pi, 0x240, 0x1b0);
}
if (NREV_GE(pi->pubpi.phy_rev, 8))
mod_phy_reg(pi, 0xbd, (0xff << 0), (114 << 0));
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x00, 16,
&dac_control);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x10, 16,
&dac_control);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 0, 32, &leg_data_weights);
leg_data_weights = leg_data_weights & 0xffffff;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 0, 32, &leg_data_weights);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ,
2, 0x15e, 16,
rfseq_rx2tx_dacbufpu_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x16e, 16,
rfseq_rx2tx_dacbufpu_rev7);
if (PHY_IPA(pi))
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_RX2TX,
rfseq_rx2tx_events_rev3_ipa,
rfseq_rx2tx_dlys_rev3_ipa,
ARRAY_SIZE(rfseq_rx2tx_events_rev3_ipa));
mod_phy_reg(pi, 0x299, (0x3 << 14), (0x1 << 14));
mod_phy_reg(pi, 0x29d, (0x3 << 14), (0x1 << 14));
tx_lpf_bw_ofdm_20mhz = wlc_phy_read_lpf_bw_ctl_nphy(pi, 0x154);
tx_lpf_bw_ofdm_40mhz = wlc_phy_read_lpf_bw_ctl_nphy(pi, 0x159);
tx_lpf_bw_11b = wlc_phy_read_lpf_bw_ctl_nphy(pi, 0x152);
if (PHY_IPA(pi)) {
if (((pi->pubpi.radiorev == 5)
&& (CHSPEC_IS40(pi->radio_chanspec) == 1))
|| (pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
rccal_bcap_val =
read_radio_reg(
pi,
RADIO_2057_RCCAL_BCAP_VAL);
rccal_scap_val =
read_radio_reg(
pi,
RADIO_2057_RCCAL_SCAP_VAL);
rccal_tx20_11b_bcap = rccal_bcap_val;
rccal_tx20_11b_scap = rccal_scap_val;
if ((pi->pubpi.radiorev == 5) &&
(CHSPEC_IS40(pi->radio_chanspec) == 1)) {
rccal_tx20_11n_bcap = rccal_bcap_val;
rccal_tx20_11n_scap = rccal_scap_val;
rccal_tx40_11n_bcap = 0xc;
rccal_tx40_11n_scap = 0xc;
rccal_ovrd = true;
} else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
tx_lpf_bw_ofdm_20mhz = 4;
tx_lpf_bw_11b = 1;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
rccal_tx20_11n_bcap = 0xc;
rccal_tx20_11n_scap = 0xc;
rccal_tx40_11n_bcap = 0xa;
rccal_tx40_11n_scap = 0xa;
} else {
rccal_tx20_11n_bcap = 0x14;
rccal_tx20_11n_scap = 0x14;
rccal_tx40_11n_bcap = 0xf;
rccal_tx40_11n_scap = 0xf;
}
rccal_ovrd = true;
}
}
} else {
if (pi->pubpi.radiorev == 5) {
tx_lpf_bw_ofdm_20mhz = 1;
tx_lpf_bw_ofdm_40mhz = 3;
rccal_bcap_val =
read_radio_reg(
pi,
RADIO_2057_RCCAL_BCAP_VAL);
rccal_scap_val =
read_radio_reg(
pi,
RADIO_2057_RCCAL_SCAP_VAL);
rccal_tx20_11b_bcap = rccal_bcap_val;
rccal_tx20_11b_scap = rccal_scap_val;
rccal_tx20_11n_bcap = 0x13;
rccal_tx20_11n_scap = 0x11;
rccal_tx40_11n_bcap = 0x13;
rccal_tx40_11n_scap = 0x11;
rccal_ovrd = true;
}
}
if (rccal_ovrd) {
rx2tx_lpf_rc_lut_tx20_11b =
(rccal_tx20_11b_bcap << 8) |
(rccal_tx20_11b_scap << 3) |
tx_lpf_bw_11b;
rx2tx_lpf_rc_lut_tx20_11n =
(rccal_tx20_11n_bcap << 8) |
(rccal_tx20_11n_scap << 3) |
tx_lpf_bw_ofdm_20mhz;
rx2tx_lpf_rc_lut_tx40_11n =
(rccal_tx40_11n_bcap << 8) |
(rccal_tx40_11n_scap << 3) |
tx_lpf_bw_ofdm_40mhz;
for (coreNum = 0; coreNum <= 1; coreNum++) {
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x152 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx20_11b);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x153 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx20_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x154 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx20_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x155 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx40_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x156 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx40_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x157 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx40_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x158 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx40_11n);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_RFSEQ,
1,
0x159 + coreNum * 0x10,
16,
&rx2tx_lpf_rc_lut_tx40_11n);
}
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 4),
1, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
}
write_phy_reg(pi, 0x32f, 0x3);
if ((pi->pubpi.radiorev == 4) || (pi->pubpi.radiorev == 6))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2),
1, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
if ((pi->pubpi.radiorev == 3) || (pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6)) {
if ((pi->sh->sromrev >= 8)
&& (pi->sh->boardflags2 & BFL2_IPALVLSHIFT_3P3))
ipalvlshift_3p3_war_en = 1;
if (ipalvlshift_3p3_war_en) {
write_radio_reg(pi, RADIO_2057_GPAIO_CONFIG,
0x5);
write_radio_reg(pi, RADIO_2057_GPAIO_SEL1,
0x30);
write_radio_reg(pi, RADIO_2057_GPAIO_SEL0, 0x0);
or_radio_reg(pi,
RADIO_2057_RXTXBIAS_CONFIG_CORE0,
0x1);
or_radio_reg(pi,
RADIO_2057_RXTXBIAS_CONFIG_CORE1,
0x1);
ipa2g_mainbias = 0x1f;
ipa2g_casconv = 0x6f;
ipa2g_biasfilt = 0xaa;
} else {
ipa2g_mainbias = 0x2b;
ipa2g_casconv = 0x7f;
ipa2g_biasfilt = 0xee;
}
if (CHSPEC_IS2G(pi->radio_chanspec)) {
for (coreNum = 0; coreNum <= 1; coreNum++) {
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
coreNum, IPA2G_IMAIN,
ipa2g_mainbias);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
coreNum, IPA2G_CASCONV,
ipa2g_casconv);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
coreNum,
IPA2G_BIAS_FILTER,
ipa2g_biasfilt);
}
}
}
if (PHY_IPA(pi)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((pi->pubpi.radiorev == 3)
|| (pi->pubpi.radiorev == 4)
|| (pi->pubpi.radiorev == 6))
txgm_idac_bleed = 0x7f;
for (coreNum = 0; coreNum <= 1; coreNum++) {
if (txgm_idac_bleed != 0)
WRITE_RADIO_REG4(
pi, RADIO_2057,
CORE, coreNum,
TXGM_IDAC_BLEED,
txgm_idac_bleed);
}
if (pi->pubpi.radiorev == 5) {
for (coreNum = 0; coreNum <= 1;
coreNum++) {
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, coreNum,
IPA2G_CASCONV,
0x13);
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, coreNum,
IPA2G_IMAIN,
0x1f);
WRITE_RADIO_REG4(
pi, RADIO_2057,
CORE, coreNum,
IPA2G_BIAS_FILTER,
0xee);
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, coreNum,
PAD2G_IDACS,
0x8a);
WRITE_RADIO_REG4(
pi, RADIO_2057,
CORE, coreNum,
PAD_BIAS_FILTER_BWS,
0x3e);
}
} else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
if (CHSPEC_IS40(pi->radio_chanspec) ==
0) {
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, 0,
IPA2G_IMAIN,
0x14);
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, 1,
IPA2G_IMAIN,
0x12);
} else {
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, 0,
IPA2G_IMAIN,
0x16);
WRITE_RADIO_REG4(pi, RADIO_2057,
CORE, 1,
IPA2G_IMAIN,
0x16);
}
}
} else {
freq = CHAN5G_FREQ(CHSPEC_CHANNEL(
pi->radio_chanspec));
if (((freq >= 5180) && (freq <= 5230))
|| ((freq >= 5745) && (freq <= 5805))) {
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
0, IPA5G_BIAS_FILTER,
0xff);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
1, IPA5G_BIAS_FILTER,
0xff);
}
}
} else {
if (pi->pubpi.radiorev != 5) {
for (coreNum = 0; coreNum <= 1; coreNum++) {
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
coreNum,
TXMIX2G_TUNE_BOOST_PU,
0x61);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE,
coreNum,
TXGM_IDAC_BLEED, 0x70);
}
}
}
if (pi->pubpi.radiorev == 4) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1,
0x05, 16,
&afectrl_adc_ctrl1_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1,
0x15, 16,
&afectrl_adc_ctrl1_rev7);
for (coreNum = 0; coreNum <= 1; coreNum++) {
WRITE_RADIO_REG4(pi, RADIO_2057, CORE, coreNum,
AFE_VCM_CAL_MASTER, 0x0);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE, coreNum,
AFE_SET_VCM_I, 0x3f);
WRITE_RADIO_REG4(pi, RADIO_2057, CORE, coreNum,
AFE_SET_VCM_Q, 0x3f);
}
} else {
mod_phy_reg(pi, 0xa6, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0x8f, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0xa7, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0xa5, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0xa6, (0x1 << 0), 0);
mod_phy_reg(pi, 0x8f, (0x1 << 0), (0x1 << 0));
mod_phy_reg(pi, 0xa7, (0x1 << 0), 0);
mod_phy_reg(pi, 0xa5, (0x1 << 0), (0x1 << 0));
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1,
0x05, 16,
&afectrl_adc_ctrl2_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1,
0x15, 16,
&afectrl_adc_ctrl2_rev7);
mod_phy_reg(pi, 0xa6, (0x1 << 2), 0);
mod_phy_reg(pi, 0x8f, (0x1 << 2), 0);
mod_phy_reg(pi, 0xa7, (0x1 << 2), 0);
mod_phy_reg(pi, 0xa5, (0x1 << 2), 0);
}
write_phy_reg(pi, 0x6a, 0x2);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1, 256, 32,
&min_nvar_offset_6mbps);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x138, 16,
&rfseq_pktgn_lpf_hpc_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 1, 0x141, 16,
&rfseq_pktgn_lpf_h_hpc_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 3, 0x133, 16,
&rfseq_htpktgn_lpf_hpc_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x146, 16,
&rfseq_cckpktgn_lpf_hpc_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 1, 0x123, 16,
&rfseq_tx2rx_lpf_h_hpc_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 1, 0x12A, 16,
&rfseq_rx2tx_lpf_h_hpc_rev7);
if (CHSPEC_IS40(pi->radio_chanspec) == 0) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1, 3,
32, &min_nvar_val);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
127, 32, &min_nvar_val);
} else {
min_nvar_val = noise_var_tbl_rev7[3];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1, 3,
32, &min_nvar_val);
min_nvar_val = noise_var_tbl_rev7[127];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
127, 32, &min_nvar_val);
}
wlc_phy_workarounds_nphy_gainctrl(pi);
pdetrange =
(CHSPEC_IS5G(pi->radio_chanspec)) ? pi->srom_fem5g.
pdetrange : pi->srom_fem2g.pdetrange;
if (pdetrange == 0) {
chan_freq_range =
wlc_phy_get_chan_freq_range_nphy(pi, 0);
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
aux_adc_vmid_rev7_core0[3] = 0x70;
aux_adc_vmid_rev7_core1[3] = 0x70;
aux_adc_gain_rev7[3] = 2;
} else {
aux_adc_vmid_rev7_core0[3] = 0x80;
aux_adc_vmid_rev7_core1[3] = 0x80;
aux_adc_gain_rev7[3] = 3;
}
} else if (pdetrange == 1) {
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
aux_adc_vmid_rev7_core0[3] = 0x7c;
aux_adc_vmid_rev7_core1[3] = 0x7c;
aux_adc_gain_rev7[3] = 2;
} else {
aux_adc_vmid_rev7_core0[3] = 0x8c;
aux_adc_vmid_rev7_core1[3] = 0x8c;
aux_adc_gain_rev7[3] = 1;
}
} else if (pdetrange == 2) {
if (pi->pubpi.radioid == BCM2057_ID) {
if ((pi->pubpi.radiorev == 5)
|| (pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
if (chan_freq_range ==
WL_CHAN_FREQ_RANGE_2G) {
aux_adc_vmid_rev7_core0[3] =
0x8c;
aux_adc_vmid_rev7_core1[3] =
0x8c;
aux_adc_gain_rev7[3] = 0;
} else {
aux_adc_vmid_rev7_core0[3] =
0x96;
aux_adc_vmid_rev7_core1[3] =
0x96;
aux_adc_gain_rev7[3] = 0;
}
}
}
} else if (pdetrange == 3) {
if (chan_freq_range == WL_CHAN_FREQ_RANGE_2G) {
aux_adc_vmid_rev7_core0[3] = 0x89;
aux_adc_vmid_rev7_core1[3] = 0x89;
aux_adc_gain_rev7[3] = 0;
}
} else if (pdetrange == 5) {
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
aux_adc_vmid_rev7_core0[3] = 0x80;
aux_adc_vmid_rev7_core1[3] = 0x80;
aux_adc_gain_rev7[3] = 3;
} else {
aux_adc_vmid_rev7_core0[3] = 0x70;
aux_adc_vmid_rev7_core1[3] = 0x70;
aux_adc_gain_rev7[3] = 2;
}
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4, 0x08, 16,
&aux_adc_vmid_rev7_core0);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4, 0x18, 16,
&aux_adc_vmid_rev7_core1);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4, 0x0c, 16,
&aux_adc_gain_rev7);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4, 0x1c, 16,
&aux_adc_gain_rev7);
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_phy_reg(pi, 0x23f, 0x1f8);
write_phy_reg(pi, 0x240, 0x1f8);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 0, 32, &leg_data_weights);
leg_data_weights = leg_data_weights & 0xffffff;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 0, 32, &leg_data_weights);
alpha0 = 293;
alpha1 = 435;
alpha2 = 261;
beta0 = 366;
beta1 = 205;
beta2 = 32;
write_phy_reg(pi, 0x145, alpha0);
write_phy_reg(pi, 0x146, alpha1);
write_phy_reg(pi, 0x147, alpha2);
write_phy_reg(pi, 0x148, beta0);
write_phy_reg(pi, 0x149, beta1);
write_phy_reg(pi, 0x14a, beta2);
write_phy_reg(pi, 0x38, 0xC);
write_phy_reg(pi, 0x2ae, 0xC);
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_TX2RX,
rfseq_tx2rx_events_rev3,
rfseq_tx2rx_dlys_rev3,
ARRAY_SIZE(rfseq_tx2rx_events_rev3));
if (PHY_IPA(pi))
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_RX2TX,
rfseq_rx2tx_events_rev3_ipa,
rfseq_rx2tx_dlys_rev3_ipa,
ARRAY_SIZE(rfseq_rx2tx_events_rev3_ipa));
if ((pi->sh->hw_phyrxchain != 0x3) &&
(pi->sh->hw_phyrxchain != pi->sh->hw_phytxchain)) {
if (PHY_IPA(pi)) {
rfseq_rx2tx_dlys_rev3[5] = 59;
rfseq_rx2tx_dlys_rev3[6] = 1;
rfseq_rx2tx_events_rev3[7] =
NPHY_REV3_RFSEQ_CMD_END;
}
wlc_phy_set_rfseq_nphy(
pi, NPHY_RFSEQ_RX2TX,
rfseq_rx2tx_events_rev3,
rfseq_rx2tx_dlys_rev3,
ARRAY_SIZE(rfseq_rx2tx_events_rev3));
}
if (CHSPEC_IS2G(pi->radio_chanspec))
write_phy_reg(pi, 0x6a, 0x2);
else
write_phy_reg(pi, 0x6a, 0x9c40);
mod_phy_reg(pi, 0x294, (0xf << 8), (7 << 8));
if (CHSPEC_IS40(pi->radio_chanspec) == 0) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1, 3,
32, &min_nvar_val);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
127, 32, &min_nvar_val);
} else {
min_nvar_val = noise_var_tbl_rev3[3];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1, 3,
32, &min_nvar_val);
min_nvar_val = noise_var_tbl_rev3[127];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
127, 32, &min_nvar_val);
}
wlc_phy_workarounds_nphy_gainctrl(pi);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x00, 16,
&dac_control);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x10, 16,
&dac_control);
pdetrange =
(CHSPEC_IS5G(pi->radio_chanspec)) ? pi->srom_fem5g.
pdetrange : pi->srom_fem2g.pdetrange;
if (pdetrange == 0) {
if (NREV_GE(pi->pubpi.phy_rev, 4)) {
aux_adc_vmid = aux_adc_vmid_rev4;
aux_adc_gain = aux_adc_gain_rev4;
} else {
aux_adc_vmid = aux_adc_vmid_rev3;
aux_adc_gain = aux_adc_gain_rev3;
}
chan_freq_range =
wlc_phy_get_chan_freq_range_nphy(pi, 0);
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
switch (chan_freq_range) {
case WL_CHAN_FREQ_RANGE_5GL:
aux_adc_vmid[3] = 0x89;
aux_adc_gain[3] = 0;
break;
case WL_CHAN_FREQ_RANGE_5GM:
aux_adc_vmid[3] = 0x89;
aux_adc_gain[3] = 0;
break;
case WL_CHAN_FREQ_RANGE_5GH:
aux_adc_vmid[3] = 0x89;
aux_adc_gain[3] = 0;
break;
default:
break;
}
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x08, 16, aux_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x18, 16, aux_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x0c, 16, aux_adc_gain);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x1c, 16, aux_adc_gain);
} else if (pdetrange == 1) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x08, 16, sk_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x18, 16, sk_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x0c, 16, sk_adc_gain);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x1c, 16, sk_adc_gain);
} else if (pdetrange == 2) {
u16 bcm_adc_vmid[] = { 0xa2, 0xb4, 0xb4, 0x74 };
u16 bcm_adc_gain[] = { 0x02, 0x02, 0x02, 0x04 };
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
chan_freq_range =
wlc_phy_get_chan_freq_range_nphy(pi, 0);
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
bcm_adc_vmid[3] = 0x8e;
bcm_adc_gain[3] = 0x03;
} else {
bcm_adc_vmid[3] = 0x94;
bcm_adc_gain[3] = 0x03;
}
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
bcm_adc_vmid[3] = 0x84;
bcm_adc_gain[3] = 0x02;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x08, 16, bcm_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x18, 16, bcm_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x0c, 16, bcm_adc_gain);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x1c, 16, bcm_adc_gain);
} else if (pdetrange == 3) {
chan_freq_range =
wlc_phy_get_chan_freq_range_nphy(pi, 0);
if ((NREV_GE(pi->pubpi.phy_rev, 4))
&& (chan_freq_range == WL_CHAN_FREQ_RANGE_2G)) {
u16 auxadc_vmid[] = {
0xa2, 0xb4, 0xb4, 0x270
};
u16 auxadc_gain[] = {
0x02, 0x02, 0x02, 0x00
};
wlc_phy_table_write_nphy(pi,
NPHY_TBL_ID_AFECTRL, 4,
0x08, 16, auxadc_vmid);
wlc_phy_table_write_nphy(pi,
NPHY_TBL_ID_AFECTRL, 4,
0x18, 16, auxadc_vmid);
wlc_phy_table_write_nphy(pi,
NPHY_TBL_ID_AFECTRL, 4,
0x0c, 16, auxadc_gain);
wlc_phy_table_write_nphy(pi,
NPHY_TBL_ID_AFECTRL, 4,
0x1c, 16, auxadc_gain);
}
} else if ((pdetrange == 4) || (pdetrange == 5)) {
u16 bcm_adc_vmid[] = { 0xa2, 0xb4, 0xb4, 0x0 };
u16 bcm_adc_gain[] = { 0x02, 0x02, 0x02, 0x0 };
u16 Vmid[2], Av[2];
chan_freq_range =
wlc_phy_get_chan_freq_range_nphy(pi, 0);
if (chan_freq_range != WL_CHAN_FREQ_RANGE_2G) {
Vmid[0] = (pdetrange == 4) ? 0x8e : 0x89;
Vmid[1] = (pdetrange == 4) ? 0x96 : 0x89;
Av[0] = (pdetrange == 4) ? 2 : 0;
Av[1] = (pdetrange == 4) ? 2 : 0;
} else {
Vmid[0] = (pdetrange == 4) ? 0x89 : 0x74;
Vmid[1] = (pdetrange == 4) ? 0x8b : 0x70;
Av[0] = (pdetrange == 4) ? 2 : 0;
Av[1] = (pdetrange == 4) ? 2 : 0;
}
bcm_adc_vmid[3] = Vmid[0];
bcm_adc_gain[3] = Av[0];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x08, 16, bcm_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x0c, 16, bcm_adc_gain);
bcm_adc_vmid[3] = Vmid[1];
bcm_adc_gain[3] = Av[1];
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x18, 16, bcm_adc_vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 4,
0x1c, 16, bcm_adc_gain);
}
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_MAST_BIAS | RADIO_2056_RX0),
0x0);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_MAST_BIAS | RADIO_2056_RX1),
0x0);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_BIAS_MAIN | RADIO_2056_RX0),
0x6);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_BIAS_MAIN | RADIO_2056_RX1),
0x6);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_BIAS_AUX | RADIO_2056_RX0),
0x7);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_BIAS_AUX | RADIO_2056_RX1),
0x7);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_LOB_BIAS | RADIO_2056_RX0),
0x88);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_LOB_BIAS | RADIO_2056_RX1),
0x88);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_CMFB_IDAC | RADIO_2056_RX0),
0x0);
write_radio_reg(pi,
(RADIO_2056_RX_MIXA_CMFB_IDAC | RADIO_2056_RX1),
0x0);
write_radio_reg(pi,
(RADIO_2056_RX_MIXG_CMFB_IDAC | RADIO_2056_RX0),
0x0);
write_radio_reg(pi,
(RADIO_2056_RX_MIXG_CMFB_IDAC | RADIO_2056_RX1),
0x0);
triso =
(CHSPEC_IS5G(pi->radio_chanspec)) ? pi->srom_fem5g.
triso : pi->srom_fem2g.triso;
if (triso == 7) {
wlc_phy_war_force_trsw_to_R_cliplo_nphy(pi, PHY_CORE_0);
wlc_phy_war_force_trsw_to_R_cliplo_nphy(pi, PHY_CORE_1);
}
wlc_phy_war_txchain_upd_nphy(pi, pi->sh->hw_phytxchain);
if (((pi->sh->boardflags2 & BFL2_APLL_WAR) &&
(CHSPEC_IS5G(pi->radio_chanspec))) ||
(((pi->sh->boardflags2 & BFL2_GPLL_WAR) ||
(pi->sh->boardflags2 & BFL2_GPLL_WAR2)) &&
(CHSPEC_IS2G(pi->radio_chanspec)))) {
nss1_data_weights = 0x00088888;
ht_data_weights = 0x00088888;
stbc_data_weights = 0x00088888;
} else {
nss1_data_weights = 0x88888888;
ht_data_weights = 0x88888888;
stbc_data_weights = 0x88888888;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 1, 32, &nss1_data_weights);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 2, 32, &ht_data_weights);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CMPMETRICDATAWEIGHTTBL,
1, 3, 32, &stbc_data_weights);
if (NREV_IS(pi->pubpi.phy_rev, 4)) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
write_radio_reg(pi,
RADIO_2056_TX_GMBB_IDAC |
RADIO_2056_TX0, 0x70);
write_radio_reg(pi,
RADIO_2056_TX_GMBB_IDAC |
RADIO_2056_TX1, 0x70);
}
}
if (!pi->edcrs_threshold_lock) {
write_phy_reg(pi, 0x224, 0x3eb);
write_phy_reg(pi, 0x225, 0x3eb);
write_phy_reg(pi, 0x226, 0x341);
write_phy_reg(pi, 0x227, 0x341);
write_phy_reg(pi, 0x228, 0x42b);
write_phy_reg(pi, 0x229, 0x42b);
write_phy_reg(pi, 0x22a, 0x381);
write_phy_reg(pi, 0x22b, 0x381);
write_phy_reg(pi, 0x22c, 0x42b);
write_phy_reg(pi, 0x22d, 0x42b);
write_phy_reg(pi, 0x22e, 0x381);
write_phy_reg(pi, 0x22f, 0x381);
}
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
if (pi->sh->boardflags2 & BFL2_SINGLEANT_CCK)
wlapi_bmac_mhf(pi->sh->physhim, MHF4,
MHF4_BPHY_TXCORE0,
MHF4_BPHY_TXCORE0, BRCM_BAND_ALL);
}
} else {
if (pi->sh->boardflags2 & BFL2_SKWRKFEM_BRD ||
(pi->sh->boardtype == 0x8b)) {
uint i;
u8 war_dlys[] = { 1, 6, 6, 2, 4, 20, 1 };
for (i = 0; i < ARRAY_SIZE(rfseq_rx2tx_dlys); i++)
rfseq_rx2tx_dlys[i] = war_dlys[i];
}
if (CHSPEC_IS5G(pi->radio_chanspec) && pi->phy_5g_pwrgain) {
and_radio_reg(pi, RADIO_2055_CORE1_TX_RF_SPARE, 0xf7);
and_radio_reg(pi, RADIO_2055_CORE2_TX_RF_SPARE, 0xf7);
} else {
or_radio_reg(pi, RADIO_2055_CORE1_TX_RF_SPARE, 0x8);
or_radio_reg(pi, RADIO_2055_CORE2_TX_RF_SPARE, 0x8);
}
regval = 0x000a;
wlc_phy_table_write_nphy(pi, 8, 1, 0, 16, &regval);
wlc_phy_table_write_nphy(pi, 8, 1, 0x10, 16, &regval);
if (NREV_LT(pi->pubpi.phy_rev, 3)) {
regval = 0xcdaa;
wlc_phy_table_write_nphy(pi, 8, 1, 0x02, 16, &regval);
wlc_phy_table_write_nphy(pi, 8, 1, 0x12, 16, &regval);
}
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
regval = 0x0000;
wlc_phy_table_write_nphy(pi, 8, 1, 0x08, 16, &regval);
wlc_phy_table_write_nphy(pi, 8, 1, 0x18, 16, &regval);
regval = 0x7aab;
wlc_phy_table_write_nphy(pi, 8, 1, 0x07, 16, &regval);
wlc_phy_table_write_nphy(pi, 8, 1, 0x17, 16, &regval);
regval = 0x0800;
wlc_phy_table_write_nphy(pi, 8, 1, 0x06, 16, &regval);
wlc_phy_table_write_nphy(pi, 8, 1, 0x16, 16, &regval);
}
write_phy_reg(pi, 0xf8, 0x02d8);
write_phy_reg(pi, 0xf9, 0x0301);
write_phy_reg(pi, 0xfa, 0x02d8);
write_phy_reg(pi, 0xfb, 0x0301);
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_RX2TX, rfseq_rx2tx_events,
rfseq_rx2tx_dlys,
ARRAY_SIZE(rfseq_rx2tx_events));
wlc_phy_set_rfseq_nphy(pi, NPHY_RFSEQ_TX2RX, rfseq_tx2rx_events,
rfseq_tx2rx_dlys,
ARRAY_SIZE(rfseq_tx2rx_events));
wlc_phy_workarounds_nphy_gainctrl(pi);
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
if (read_phy_reg(pi, 0xa0) & NPHY_MLenable)
wlapi_bmac_mhf(pi->sh->physhim, MHF3,
MHF3_NPHY_MLADV_WAR,
MHF3_NPHY_MLADV_WAR,
BRCM_BAND_ALL);
} else if (NREV_IS(pi->pubpi.phy_rev, 2)) {
write_phy_reg(pi, 0x1e3, 0x0);
write_phy_reg(pi, 0x1e4, 0x0);
}
if (NREV_LT(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0x90, (0x1 << 7), 0);
alpha0 = 293;
alpha1 = 435;
alpha2 = 261;
beta0 = 366;
beta1 = 205;
beta2 = 32;
write_phy_reg(pi, 0x145, alpha0);
write_phy_reg(pi, 0x146, alpha1);
write_phy_reg(pi, 0x147, alpha2);
write_phy_reg(pi, 0x148, beta0);
write_phy_reg(pi, 0x149, beta1);
write_phy_reg(pi, 0x14a, beta2);
if (NREV_LT(pi->pubpi.phy_rev, 3)) {
mod_phy_reg(pi, 0x142, (0xf << 12), 0);
write_phy_reg(pi, 0x192, 0xb5);
write_phy_reg(pi, 0x193, 0xa4);
write_phy_reg(pi, 0x194, 0x0);
}
if (NREV_IS(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0x221,
NPHY_FORCESIG_DECODEGATEDCLKS,
NPHY_FORCESIG_DECODEGATEDCLKS);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void wlc_phy_extpa_set_tx_digi_filts_nphy(struct brcms_phy *pi)
{
int j, type = 2;
u16 addr_offset = 0x2c5;
for (j = 0; j < NPHY_NUM_DIG_FILT_COEFFS; j++)
write_phy_reg(pi, addr_offset + j,
NPHY_IPA_REV4_txdigi_filtcoeffs[type][j]);
}
static void wlc_phy_clip_det_nphy(struct brcms_phy *pi, u8 write, u16 *vals)
{
if (write == 0) {
vals[0] = read_phy_reg(pi, 0x2c);
vals[1] = read_phy_reg(pi, 0x42);
} else {
write_phy_reg(pi, 0x2c, vals[0]);
write_phy_reg(pi, 0x42, vals[1]);
}
}
static void wlc_phy_ipa_internal_tssi_setup_nphy(struct brcms_phy *pi)
{
u8 core;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER, 0x5);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MUX, 0xe);
if (pi->pubpi.radiorev != 5)
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TSSIA, 0);
if (!NREV_IS(pi->pubpi.phy_rev, 7))
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TSSIG, 0x1);
else
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TSSIG, 0x31);
} else {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER, 0x9);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MUX, 0xc);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSIG, 0);
if (pi->pubpi.radiorev != 5) {
if (!NREV_IS(pi->pubpi.phy_rev, 7))
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIA, 0x1);
else
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIA, 0x31);
}
}
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, IQCAL_VCM_HG,
0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, IQCAL_IDAC,
0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TSSI_VCM,
0x3);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TSSI_MISC1,
0x0);
}
} else {
WRITE_RADIO_SYN(pi, RADIO_2056, RESERVED_ADDR31,
(CHSPEC_IS2G(pi->radio_chanspec)) ? 0x128 :
0x80);
WRITE_RADIO_SYN(pi, RADIO_2056, RESERVED_ADDR30, 0x0);
WRITE_RADIO_SYN(pi, RADIO_2056, GPIO_MASTER1, 0x29);
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, IQCAL_VCM_HG,
0x0);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, IQCAL_IDAC,
0x0);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, TSSI_VCM,
0x3);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, TX_AMP_DET,
0x0);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, TSSI_MISC1,
0x8);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, TSSI_MISC2,
0x0);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, TSSI_MISC3,
0x0);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TX_SSI_MASTER, 0x5);
if (pi->pubpi.radiorev != 5)
WRITE_RADIO_REG2(pi, RADIO_2056, TX,
core, TSSIA, 0x0);
if (NREV_GE(pi->pubpi.phy_rev, 5))
WRITE_RADIO_REG2(pi, RADIO_2056, TX,
core, TSSIG, 0x31);
else
WRITE_RADIO_REG2(pi, RADIO_2056, TX,
core, TSSIG, 0x11);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TX_SSI_MUX, 0xe);
} else {
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TX_SSI_MASTER, 0x9);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TSSIA, 0x31);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TSSIG, 0x0);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TX_SSI_MUX, 0xc);
}
}
}
}
static void
wlc_phy_rfctrl_override_nphy(struct brcms_phy *pi, u16 field, u16 value,
u8 core_mask, u8 off)
{
u8 core_num;
u16 addr = 0, mask = 0, en_addr = 0, val_addr = 0, en_mask =
0, val_mask = 0;
u8 shift = 0, val_shift = 0;
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LT(pi->pubpi.phy_rev, 7)) {
en_mask = field;
for (core_num = 0; core_num < 2; core_num++) {
switch (field) {
case (0x1 << 1):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 0);
val_shift = 0;
break;
case (0x1 << 2):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 1);
val_shift = 1;
break;
case (0x1 << 3):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 2);
val_shift = 2;
break;
case (0x1 << 4):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 4);
val_shift = 4;
break;
case (0x1 << 5):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 5);
val_shift = 5;
break;
case (0x1 << 6):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 6);
val_shift = 6;
break;
case (0x1 << 7):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x1 << 7);
val_shift = 7;
break;
case (0x1 << 8):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x7 << 8);
val_shift = 8;
break;
case (0x1 << 11):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7a : 0x7d;
val_mask = (0x7 << 13);
val_shift = 13;
break;
case (0x1 << 9):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0xf8 : 0xfa;
val_mask = (0x7 << 0);
val_shift = 0;
break;
case (0x1 << 10):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0xf8 : 0xfa;
val_mask = (0x7 << 4);
val_shift = 4;
break;
case (0x1 << 12):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7b : 0x7e;
val_mask = (0xffff << 0);
val_shift = 0;
break;
case (0x1 << 13):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0x7c : 0x7f;
val_mask = (0xffff << 0);
val_shift = 0;
break;
case (0x1 << 14):
en_addr = (core_num == 0) ? 0xe7 : 0xec;
val_addr = (core_num == 0) ? 0xf9 : 0xfb;
val_mask = (0x3 << 6);
val_shift = 6;
break;
case (0x1 << 0):
en_addr = (core_num == 0) ? 0xe5 : 0xe6;
val_addr = (core_num == 0) ? 0xf9 : 0xfb;
val_mask = (0x1 << 15);
val_shift = 15;
break;
default:
addr = 0xffff;
break;
}
if (off) {
and_phy_reg(pi, en_addr, ~en_mask);
and_phy_reg(pi, val_addr, ~val_mask);
} else {
if ((core_mask == 0)
|| (core_mask & (1 << core_num))) {
or_phy_reg(pi, en_addr, en_mask);
if (addr != 0xffff)
mod_phy_reg(pi, val_addr,
val_mask,
(value <<
val_shift));
}
}
}
} else {
if (off) {
and_phy_reg(pi, 0xec, ~field);
value = 0x0;
} else {
or_phy_reg(pi, 0xec, field);
}
for (core_num = 0; core_num < 2; core_num++) {
switch (field) {
case (0x1 << 1):
case (0x1 << 9):
case (0x1 << 12):
case (0x1 << 13):
case (0x1 << 14):
addr = 0x78;
core_mask = 0x1;
break;
case (0x1 << 2):
case (0x1 << 3):
case (0x1 << 4):
case (0x1 << 5):
case (0x1 << 6):
case (0x1 << 7):
case (0x1 << 8):
addr = (core_num == 0) ? 0x7a : 0x7d;
break;
case (0x1 << 10):
addr = (core_num == 0) ? 0x7b : 0x7e;
break;
case (0x1 << 11):
addr = (core_num == 0) ? 0x7c : 0x7f;
break;
default:
addr = 0xffff;
}
switch (field) {
case (0x1 << 1):
mask = (0x7 << 3);
shift = 3;
break;
case (0x1 << 9):
mask = (0x1 << 2);
shift = 2;
break;
case (0x1 << 12):
mask = (0x1 << 8);
shift = 8;
break;
case (0x1 << 13):
mask = (0x1 << 9);
shift = 9;
break;
case (0x1 << 14):
mask = (0xf << 12);
shift = 12;
break;
case (0x1 << 2):
mask = (0x1 << 0);
shift = 0;
break;
case (0x1 << 3):
mask = (0x1 << 1);
shift = 1;
break;
case (0x1 << 4):
mask = (0x1 << 2);
shift = 2;
break;
case (0x1 << 5):
mask = (0x3 << 4);
shift = 4;
break;
case (0x1 << 6):
mask = (0x3 << 6);
shift = 6;
break;
case (0x1 << 7):
mask = (0x1 << 8);
shift = 8;
break;
case (0x1 << 8):
mask = (0x1 << 9);
shift = 9;
break;
case (0x1 << 10):
mask = 0x1fff;
shift = 0x0;
break;
case (0x1 << 11):
mask = 0x1fff;
shift = 0x0;
break;
default:
mask = 0x0;
shift = 0x0;
break;
}
if ((addr != 0xffff) && (core_mask & (1 << core_num)))
mod_phy_reg(pi, addr, mask, (value << shift));
}
or_phy_reg(pi, 0xec, (0x1 << 0));
or_phy_reg(pi, 0x78, (0x1 << 0));
udelay(1);
and_phy_reg(pi, 0xec, ~(0x1 << 0));
}
}
static void wlc_phy_txpwrctrl_idle_tssi_nphy(struct brcms_phy *pi)
{
s32 rssi_buf[4];
s32 int_val;
if (SCAN_RM_IN_PROGRESS(pi) || PLT_INPROG_PHY(pi) || PHY_MUTED(pi))
return;
if (PHY_IPA(pi))
wlc_phy_ipa_internal_tssi_setup_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 12),
0, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
else if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 13), 0, 3, 0);
wlc_phy_stopplayback_nphy(pi);
wlc_phy_tx_tone_nphy(pi, 4000, 0, 0, 0, false);
udelay(20);
int_val =
wlc_phy_poll_rssi_nphy(pi, (u8) NPHY_RSSI_SEL_TSSI_2G, rssi_buf,
1);
wlc_phy_stopplayback_nphy(pi);
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_OFF, 0);
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 12),
0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
else if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 13), 0, 3, 1);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_tssi_2g =
(u8) ((int_val >> 24) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_tssi_5g =
(u8) ((int_val >> 24) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_tssi_2g =
(u8) ((int_val >> 8) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_tssi_5g =
(u8) ((int_val >> 8) & 0xff);
} else {
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_tssi_2g =
(u8) ((int_val >> 24) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_tssi_2g =
(u8) ((int_val >> 8) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_0].idle_tssi_5g =
(u8) ((int_val >> 16) & 0xff);
pi->nphy_pwrctrl_info[PHY_CORE_1].idle_tssi_5g =
(u8) ((int_val) & 0xff);
}
}
static void wlc_phy_txpwr_limit_to_tbl_nphy(struct brcms_phy *pi)
{
u8 idx, idx2, i, delta_ind;
for (idx = TXP_FIRST_CCK; idx <= TXP_LAST_CCK; idx++)
pi->adj_pwr_tbl_nphy[idx] = pi->tx_power_offset[idx];
for (i = 0; i < 4; i++) {
idx2 = 0;
delta_ind = 0;
switch (i) {
case 0:
if (CHSPEC_IS40(pi->radio_chanspec)
&& NPHY_IS_SROM_REINTERPRET) {
idx = TXP_FIRST_MCS_40_SISO;
} else {
idx = (CHSPEC_IS40(pi->radio_chanspec)) ?
TXP_FIRST_OFDM_40_SISO : TXP_FIRST_OFDM;
delta_ind = 1;
}
break;
case 1:
idx = (CHSPEC_IS40(pi->radio_chanspec)) ?
TXP_FIRST_MCS_40_CDD : TXP_FIRST_MCS_20_CDD;
break;
case 2:
idx = (CHSPEC_IS40(pi->radio_chanspec)) ?
TXP_FIRST_MCS_40_STBC : TXP_FIRST_MCS_20_STBC;
break;
case 3:
idx = (CHSPEC_IS40(pi->radio_chanspec)) ?
TXP_FIRST_MCS_40_SDM : TXP_FIRST_MCS_20_SDM;
break;
}
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
idx = idx + delta_ind;
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx++];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
idx = idx + 1 - delta_ind;
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
pi->adj_pwr_tbl_nphy[4 + 4 * (idx2++) + i] =
pi->tx_power_offset[idx];
}
}
static void wlc_phy_txpwrctrl_pwr_setup_nphy(struct brcms_phy *pi)
{
u32 idx;
s16 a1[2], b0[2], b1[2];
s8 target_pwr_qtrdbm[2];
s32 num, den, pwr_est;
u8 chan_freq_range;
u8 idle_tssi[2];
u32 tbl_id, tbl_len, tbl_offset;
u32 regval[64];
u8 core;
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12)) {
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, MCTL_PHYLOCK);
(void)bcma_read32(pi->d11core, D11REGOFFS(maccontrol));
udelay(1);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
or_phy_reg(pi, 0x122, (0x1 << 0));
if (NREV_GE(pi->pubpi.phy_rev, 3))
and_phy_reg(pi, 0x1e7, (u16) (~(0x1 << 15)));
else
or_phy_reg(pi, 0x1e7, (0x1 << 15));
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12))
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, 0);
if (pi->sh->sromrev < 4) {
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_2g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_2g;
a1[0] = -424;
a1[1] = -424;
b0[0] = 5612;
b0[1] = 5612;
b1[1] = -1393;
b1[0] = -1393;
} else {
chan_freq_range = wlc_phy_get_chan_freq_range_nphy(pi, 0);
switch (chan_freq_range) {
case WL_CHAN_FREQ_RANGE_2G:
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_2g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_2g;
a1[0] = pi->nphy_pwrctrl_info[0].pwrdet_2g_a1;
a1[1] = pi->nphy_pwrctrl_info[1].pwrdet_2g_a1;
b0[0] = pi->nphy_pwrctrl_info[0].pwrdet_2g_b0;
b0[1] = pi->nphy_pwrctrl_info[1].pwrdet_2g_b0;
b1[0] = pi->nphy_pwrctrl_info[0].pwrdet_2g_b1;
b1[1] = pi->nphy_pwrctrl_info[1].pwrdet_2g_b1;
break;
case WL_CHAN_FREQ_RANGE_5GL:
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_5g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_5g;
a1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gl_a1;
a1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gl_a1;
b0[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gl_b0;
b0[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gl_b0;
b1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gl_b1;
b1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gl_b1;
break;
case WL_CHAN_FREQ_RANGE_5GM:
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_5g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_5g;
a1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gm_a1;
a1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gm_a1;
b0[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gm_b0;
b0[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gm_b0;
b1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gm_b1;
b1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gm_b1;
break;
case WL_CHAN_FREQ_RANGE_5GH:
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_5g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_5g;
a1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gh_a1;
a1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gh_a1;
b0[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gh_b0;
b0[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gh_b0;
b1[0] = pi->nphy_pwrctrl_info[0].pwrdet_5gh_b1;
b1[1] = pi->nphy_pwrctrl_info[1].pwrdet_5gh_b1;
break;
default:
idle_tssi[0] = pi->nphy_pwrctrl_info[0].idle_tssi_2g;
idle_tssi[1] = pi->nphy_pwrctrl_info[1].idle_tssi_2g;
a1[0] = -424;
a1[1] = -424;
b0[0] = 5612;
b0[1] = 5612;
b1[1] = -1393;
b1[0] = -1393;
break;
}
}
target_pwr_qtrdbm[0] = (s8) pi->tx_power_max;
target_pwr_qtrdbm[1] = (s8) pi->tx_power_max;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (pi->srom_fem2g.tssipos)
or_phy_reg(pi, 0x1e9, (0x1 << 14));
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (core = 0; core <= 1; core++) {
if (PHY_IPA(pi)) {
if (CHSPEC_IS2G(pi->radio_chanspec))
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TX_SSI_MUX,
0xe);
else
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TX_SSI_MUX,
0xc);
}
}
} else {
if (PHY_IPA(pi)) {
write_radio_reg(pi, RADIO_2056_TX_TX_SSI_MUX |
RADIO_2056_TX0,
(CHSPEC_IS5G
(pi->radio_chanspec)) ?
0xc : 0xe);
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MUX |
RADIO_2056_TX1,
(CHSPEC_IS5G
(pi->radio_chanspec)) ?
0xc : 0xe);
} else {
write_radio_reg(pi, RADIO_2056_TX_TX_SSI_MUX |
RADIO_2056_TX0, 0x11);
write_radio_reg(pi, RADIO_2056_TX_TX_SSI_MUX |
RADIO_2056_TX1, 0x11);
}
}
}
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12)) {
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, MCTL_PHYLOCK);
(void)bcma_read32(pi->d11core, D11REGOFFS(maccontrol));
udelay(1);
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
mod_phy_reg(pi, 0x1e7, (0x7f << 0),
(NPHY_TxPwrCtrlCmd_pwrIndex_init_rev7 << 0));
else
mod_phy_reg(pi, 0x1e7, (0x7f << 0),
(NPHY_TxPwrCtrlCmd_pwrIndex_init << 0));
if (NREV_GE(pi->pubpi.phy_rev, 7))
mod_phy_reg(pi, 0x222, (0xff << 0),
(NPHY_TxPwrCtrlCmd_pwrIndex_init_rev7 << 0));
else if (NREV_GT(pi->pubpi.phy_rev, 1))
mod_phy_reg(pi, 0x222, (0xff << 0),
(NPHY_TxPwrCtrlCmd_pwrIndex_init << 0));
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12))
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, 0);
write_phy_reg(pi, 0x1e8, (0x3 << 8) | (240 << 0));
write_phy_reg(pi, 0x1e9,
(1 << 15) | (idle_tssi[0] << 0) | (idle_tssi[1] << 8));
write_phy_reg(pi, 0x1ea,
(target_pwr_qtrdbm[0] << 0) |
(target_pwr_qtrdbm[1] << 8));
tbl_len = 64;
tbl_offset = 0;
for (tbl_id = NPHY_TBL_ID_CORE1TXPWRCTL;
tbl_id <= NPHY_TBL_ID_CORE2TXPWRCTL; tbl_id++) {
for (idx = 0; idx < tbl_len; idx++) {
num = 8 *
(16 * b0[tbl_id - 26] + b1[tbl_id - 26] * idx);
den = 32768 + a1[tbl_id - 26] * idx;
pwr_est = max(((4 * num + den / 2) / den), -8);
if (NREV_LT(pi->pubpi.phy_rev, 3)) {
if (idx <=
(uint) (31 - idle_tssi[tbl_id - 26] + 1))
pwr_est =
max(pwr_est,
target_pwr_qtrdbm
[tbl_id - 26] + 1);
}
regval[idx] = (u32) pwr_est;
}
wlc_phy_table_write_nphy(pi, tbl_id, tbl_len, tbl_offset, 32,
regval);
}
wlc_phy_txpwr_limit_to_tbl_nphy(pi);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE1TXPWRCTL, 84, 64, 8,
pi->adj_pwr_tbl_nphy);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE2TXPWRCTL, 84, 64, 8,
pi->adj_pwr_tbl_nphy);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static u32 *wlc_phy_get_ipa_gaintbl_nphy(struct brcms_phy *pi)
{
u32 *tx_pwrctrl_tbl = NULL;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if ((pi->pubpi.radiorev == 4)
|| (pi->pubpi.radiorev == 6))
tx_pwrctrl_tbl =
nphy_tpc_txgain_ipa_2g_2057rev4n6;
else if (pi->pubpi.radiorev == 3)
tx_pwrctrl_tbl =
nphy_tpc_txgain_ipa_2g_2057rev3;
else if (pi->pubpi.radiorev == 5)
tx_pwrctrl_tbl =
nphy_tpc_txgain_ipa_2g_2057rev5;
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
tx_pwrctrl_tbl =
nphy_tpc_txgain_ipa_2g_2057rev7;
} else if (NREV_IS(pi->pubpi.phy_rev, 6)) {
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa_rev6;
if (pi->sh->chip == BCMA_CHIP_ID_BCM47162)
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa_rev5;
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa_rev5;
} else {
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa;
}
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa_5g_2057;
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
tx_pwrctrl_tbl =
nphy_tpc_txgain_ipa_5g_2057rev7;
} else {
tx_pwrctrl_tbl = nphy_tpc_txgain_ipa_5g;
}
}
return tx_pwrctrl_tbl;
}
static void wlc_phy_restore_rssical_nphy(struct brcms_phy *pi)
{
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (pi->nphy_rssical_chanspec_2G == 0)
return;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mod_radio_reg(pi, RADIO_2057_NB_MASTER_CORE0,
RADIO_2057_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_2G[0]);
mod_radio_reg(pi, RADIO_2057_NB_MASTER_CORE1,
RADIO_2057_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_2G[1]);
} else {
mod_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC | RADIO_2056_RX0,
RADIO_2056_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_2G[0]);
mod_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC | RADIO_2056_RX1,
RADIO_2056_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_2G[1]);
}
write_phy_reg(pi, 0x1a6,
pi->rssical_cache.rssical_phyregs_2G[0]);
write_phy_reg(pi, 0x1ac,
pi->rssical_cache.rssical_phyregs_2G[1]);
write_phy_reg(pi, 0x1b2,
pi->rssical_cache.rssical_phyregs_2G[2]);
write_phy_reg(pi, 0x1b8,
pi->rssical_cache.rssical_phyregs_2G[3]);
write_phy_reg(pi, 0x1a4,
pi->rssical_cache.rssical_phyregs_2G[4]);
write_phy_reg(pi, 0x1aa,
pi->rssical_cache.rssical_phyregs_2G[5]);
write_phy_reg(pi, 0x1b0,
pi->rssical_cache.rssical_phyregs_2G[6]);
write_phy_reg(pi, 0x1b6,
pi->rssical_cache.rssical_phyregs_2G[7]);
write_phy_reg(pi, 0x1a5,
pi->rssical_cache.rssical_phyregs_2G[8]);
write_phy_reg(pi, 0x1ab,
pi->rssical_cache.rssical_phyregs_2G[9]);
write_phy_reg(pi, 0x1b1,
pi->rssical_cache.rssical_phyregs_2G[10]);
write_phy_reg(pi, 0x1b7,
pi->rssical_cache.rssical_phyregs_2G[11]);
} else {
if (pi->nphy_rssical_chanspec_5G == 0)
return;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mod_radio_reg(pi, RADIO_2057_NB_MASTER_CORE0,
RADIO_2057_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_5G[0]);
mod_radio_reg(pi, RADIO_2057_NB_MASTER_CORE1,
RADIO_2057_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_5G[1]);
} else {
mod_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC | RADIO_2056_RX0,
RADIO_2056_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_5G[0]);
mod_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC | RADIO_2056_RX1,
RADIO_2056_VCM_MASK,
pi->rssical_cache.
rssical_radio_regs_5G[1]);
}
write_phy_reg(pi, 0x1a6,
pi->rssical_cache.rssical_phyregs_5G[0]);
write_phy_reg(pi, 0x1ac,
pi->rssical_cache.rssical_phyregs_5G[1]);
write_phy_reg(pi, 0x1b2,
pi->rssical_cache.rssical_phyregs_5G[2]);
write_phy_reg(pi, 0x1b8,
pi->rssical_cache.rssical_phyregs_5G[3]);
write_phy_reg(pi, 0x1a4,
pi->rssical_cache.rssical_phyregs_5G[4]);
write_phy_reg(pi, 0x1aa,
pi->rssical_cache.rssical_phyregs_5G[5]);
write_phy_reg(pi, 0x1b0,
pi->rssical_cache.rssical_phyregs_5G[6]);
write_phy_reg(pi, 0x1b6,
pi->rssical_cache.rssical_phyregs_5G[7]);
write_phy_reg(pi, 0x1a5,
pi->rssical_cache.rssical_phyregs_5G[8]);
write_phy_reg(pi, 0x1ab,
pi->rssical_cache.rssical_phyregs_5G[9]);
write_phy_reg(pi, 0x1b1,
pi->rssical_cache.rssical_phyregs_5G[10]);
write_phy_reg(pi, 0x1b7,
pi->rssical_cache.rssical_phyregs_5G[11]);
}
}
static void wlc_phy_internal_cal_txgain_nphy(struct brcms_phy *pi)
{
u16 txcal_gain[2];
pi->nphy_txcal_pwr_idx[0] = pi->nphy_cal_orig_pwr_idx[0];
pi->nphy_txcal_pwr_idx[1] = pi->nphy_cal_orig_pwr_idx[0];
wlc_phy_txpwr_index_nphy(pi, 1, pi->nphy_cal_orig_pwr_idx[0], true);
wlc_phy_txpwr_index_nphy(pi, 2, pi->nphy_cal_orig_pwr_idx[1], true);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
txcal_gain);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
txcal_gain[0] = (txcal_gain[0] & 0xF000) | 0x0F40;
txcal_gain[1] = (txcal_gain[1] & 0xF000) | 0x0F40;
} else {
txcal_gain[0] = (txcal_gain[0] & 0xF000) | 0x0F60;
txcal_gain[1] = (txcal_gain[1] & 0xF000) | 0x0F60;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
txcal_gain);
}
static void wlc_phy_precal_txgain_nphy(struct brcms_phy *pi)
{
bool save_bbmult = false;
u8 txcal_index_2057_rev5n7 = 0;
u8 txcal_index_2057_rev3n4n6 = 10;
if (pi->use_int_tx_iqlo_cal_nphy) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6)) {
pi->nphy_txcal_pwr_idx[0] =
txcal_index_2057_rev3n4n6;
pi->nphy_txcal_pwr_idx[1] =
txcal_index_2057_rev3n4n6;
wlc_phy_txpwr_index_nphy(
pi, 3,
txcal_index_2057_rev3n4n6,
false);
} else {
pi->nphy_txcal_pwr_idx[0] =
txcal_index_2057_rev5n7;
pi->nphy_txcal_pwr_idx[1] =
txcal_index_2057_rev5n7;
wlc_phy_txpwr_index_nphy(
pi, 3,
txcal_index_2057_rev5n7,
false);
}
save_bbmult = true;
} else if (NREV_LT(pi->pubpi.phy_rev, 5)) {
wlc_phy_cal_txgainctrl_nphy(pi, 11, false);
if (pi->sh->hw_phytxchain != 3) {
pi->nphy_txcal_pwr_idx[1] =
pi->nphy_txcal_pwr_idx[0];
wlc_phy_txpwr_index_nphy(pi, 3,
pi->
nphy_txcal_pwr_idx[0],
true);
save_bbmult = true;
}
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
if (PHY_IPA(pi)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
wlc_phy_cal_txgainctrl_nphy(pi, 12,
false);
} else {
pi->nphy_txcal_pwr_idx[0] = 80;
pi->nphy_txcal_pwr_idx[1] = 80;
wlc_phy_txpwr_index_nphy(pi, 3, 80,
false);
save_bbmult = true;
}
} else {
wlc_phy_internal_cal_txgain_nphy(pi);
save_bbmult = true;
}
} else if (NREV_IS(pi->pubpi.phy_rev, 6)) {
if (PHY_IPA(pi)) {
if (CHSPEC_IS2G(pi->radio_chanspec))
wlc_phy_cal_txgainctrl_nphy(pi, 12,
false);
else
wlc_phy_cal_txgainctrl_nphy(pi, 14,
false);
} else {
wlc_phy_internal_cal_txgain_nphy(pi);
save_bbmult = true;
}
}
} else {
wlc_phy_cal_txgainctrl_nphy(pi, 10, false);
}
if (save_bbmult)
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16,
&pi->nphy_txcal_bbmult);
}
static void
wlc_phy_rfctrlintc_override_nphy(struct brcms_phy *pi, u8 field, u16 value,
u8 core_code)
{
u16 mask;
u16 val;
u8 core;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (core_code == RADIO_MIMO_CORESEL_CORE1
&& core == PHY_CORE_1)
continue;
else if (core_code == RADIO_MIMO_CORESEL_CORE2
&& core == PHY_CORE_0)
continue;
if (NREV_LT(pi->pubpi.phy_rev, 7)) {
mask = (0x1 << 10);
val = 1 << 10;
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x91 :
0x92, mask, val);
}
if (field == NPHY_RfctrlIntc_override_OFF) {
write_phy_reg(pi, (core == PHY_CORE_0) ? 0x91 :
0x92, 0);
wlc_phy_force_rfseq_nphy(pi,
NPHY_RFSEQ_RESET2RX);
} else if (field == NPHY_RfctrlIntc_override_TRSW) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mask = (0x1 << 6) | (0x1 << 7);
val = value << 6;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
or_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
(0x1 << 10));
and_phy_reg(pi, 0x2ff, (u16)
~(0x3 << 14));
or_phy_reg(pi, 0x2ff, (0x1 << 13));
or_phy_reg(pi, 0x2ff, (0x1 << 0));
} else {
mask = (0x1 << 6) |
(0x1 << 7) |
(0x1 << 8) | (0x1 << 9);
val = value << 6;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
mask = (0x1 << 0);
val = 1 << 0;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xe7 : 0xec,
mask, val);
mask = (core == PHY_CORE_0) ?
(0x1 << 0) : (0x1 << 1);
val = 1 << ((core == PHY_CORE_0) ?
0 : 1);
mod_phy_reg(pi, 0x78, mask, val);
SPINWAIT(((read_phy_reg(pi, 0x78) & val)
!= 0), 10000);
if (WARN(read_phy_reg(pi, 0x78) & val,
"HW error: override failed"))
return;
mask = (0x1 << 0);
val = 0 << 0;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xe7 : 0xec,
mask, val);
}
} else if (field == NPHY_RfctrlIntc_override_PA) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mask = (0x1 << 4) | (0x1 << 5);
if (CHSPEC_IS5G(pi->radio_chanspec))
val = value << 5;
else
val = value << 4;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
or_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
(0x1 << 12));
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
mask = (0x1 << 5);
val = value << 5;
} else {
mask = (0x1 << 4);
val = value << 4;
}
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
}
} else if (field ==
NPHY_RfctrlIntc_override_EXT_LNA_PU) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
mask = (0x1 << 0);
val = value << 0;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, val);
mask = (0x1 << 2);
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, 0);
} else {
mask = (0x1 << 2);
val = value << 2;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, val);
mask = (0x1 << 0);
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, 0);
}
mask = (0x1 << 11);
val = 1 << 11;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
mask = (0x1 << 0);
val = value << 0;
} else {
mask = (0x1 << 2);
val = value << 2;
}
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
}
} else if (field ==
NPHY_RfctrlIntc_override_EXT_LNA_GAIN) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
mask = (0x1 << 1);
val = value << 1;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, val);
mask = (0x1 << 3);
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, 0);
} else {
mask = (0x1 << 3);
val = value << 3;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, val);
mask = (0x1 << 1);
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91
: 0x92, mask, 0);
}
mask = (0x1 << 11);
val = 1 << 11;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
mask = (0x1 << 1);
val = value << 1;
} else {
mask = (0x1 << 3);
val = value << 3;
}
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x91 : 0x92,
mask, val);
}
}
}
}
}
void
wlc_phy_cal_txgainctrl_nphy(struct brcms_phy *pi, s32 dBm_targetpower,
bool debug)
{
int gainctrl_loopidx;
uint core;
u16 m0m1, curr_m0m1;
s32 delta_power;
s32 txpwrindex;
s32 qdBm_power[2];
u16 orig_BBConfig;
u16 phy_saveregs[4];
u32 freq_test;
u16 ampl_test = 250;
uint stepsize;
bool phyhang_avoid_state = false;
if (NREV_GE(pi->pubpi.phy_rev, 7))
stepsize = 2;
else
stepsize = 1;
if (CHSPEC_IS40(pi->radio_chanspec))
freq_test = 5000;
else
freq_test = 2500;
wlc_phy_txpwr_index_nphy(pi, 1, pi->nphy_cal_orig_pwr_idx[0], true);
wlc_phy_txpwr_index_nphy(pi, 2, pi->nphy_cal_orig_pwr_idx[1], true);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
phyhang_avoid_state = pi->phyhang_avoid;
pi->phyhang_avoid = false;
phy_saveregs[0] = read_phy_reg(pi, 0x91);
phy_saveregs[1] = read_phy_reg(pi, 0x92);
phy_saveregs[2] = read_phy_reg(pi, 0xe7);
phy_saveregs[3] = read_phy_reg(pi, 0xec);
wlc_phy_rfctrlintc_override_nphy(pi, NPHY_RfctrlIntc_override_PA, 1,
RADIO_MIMO_CORESEL_CORE1 |
RADIO_MIMO_CORESEL_CORE2);
if (!debug) {
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x2, RADIO_MIMO_CORESEL_CORE1);
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x8, RADIO_MIMO_CORESEL_CORE2);
} else {
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x1, RADIO_MIMO_CORESEL_CORE1);
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x7, RADIO_MIMO_CORESEL_CORE2);
}
orig_BBConfig = read_phy_reg(pi, 0x01);
mod_phy_reg(pi, 0x01, (0x1 << 15), 0);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &m0m1);
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
txpwrindex = (s32) pi->nphy_cal_orig_pwr_idx[core];
for (gainctrl_loopidx = 0; gainctrl_loopidx < 2;
gainctrl_loopidx++) {
wlc_phy_tx_tone_nphy(pi, freq_test, ampl_test, 0, 0,
false);
if (core == PHY_CORE_0)
curr_m0m1 = m0m1 & 0xff00;
else
curr_m0m1 = m0m1 & 0x00ff;
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &curr_m0m1);
wlc_phy_table_write_nphy(pi, 15, 1, 95, 16, &curr_m0m1);
udelay(50);
wlc_phy_est_tonepwr_nphy(pi, qdBm_power,
NPHY_CAL_TSSISAMPS);
pi->nphy_bb_mult_save = 0;
wlc_phy_stopplayback_nphy(pi);
delta_power = (dBm_targetpower * 4) - qdBm_power[core];
txpwrindex -= stepsize * delta_power;
if (txpwrindex < 0)
txpwrindex = 0;
else if (txpwrindex > 127)
txpwrindex = 127;
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_IS(pi->pubpi.phy_rev, 4) &&
(pi->srom_fem5g.extpagain == 3)) {
if (txpwrindex < 30)
txpwrindex = 30;
}
} else {
if (NREV_GE(pi->pubpi.phy_rev, 5) &&
(pi->srom_fem2g.extpagain == 3)) {
if (txpwrindex < 50)
txpwrindex = 50;
}
}
wlc_phy_txpwr_index_nphy(pi, (1 << core),
(u8) txpwrindex, true);
}
pi->nphy_txcal_pwr_idx[core] = (u8) txpwrindex;
if (debug) {
u16 radio_gain;
u16 dbg_m0m1;
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &dbg_m0m1);
wlc_phy_tx_tone_nphy(pi, freq_test, ampl_test, 0, 0,
false);
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &dbg_m0m1);
wlc_phy_table_write_nphy(pi, 15, 1, 95, 16, &dbg_m0m1);
udelay(100);
wlc_phy_est_tonepwr_nphy(pi, qdBm_power,
NPHY_CAL_TSSISAMPS);
wlc_phy_table_read_nphy(pi, 7, 1, (0x110 + core), 16,
&radio_gain);
mdelay(4000);
pi->nphy_bb_mult_save = 0;
wlc_phy_stopplayback_nphy(pi);
}
}
wlc_phy_txpwr_index_nphy(pi, 1, pi->nphy_txcal_pwr_idx[0], true);
wlc_phy_txpwr_index_nphy(pi, 2, pi->nphy_txcal_pwr_idx[1], true);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &pi->nphy_txcal_bbmult);
write_phy_reg(pi, 0x01, orig_BBConfig);
write_phy_reg(pi, 0x91, phy_saveregs[0]);
write_phy_reg(pi, 0x92, phy_saveregs[1]);
write_phy_reg(pi, 0xe7, phy_saveregs[2]);
write_phy_reg(pi, 0xec, phy_saveregs[3]);
pi->phyhang_avoid = phyhang_avoid_state;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void wlc_phy_savecal_nphy(struct brcms_phy *pi)
{
void *tbl_ptr;
int coreNum;
u16 *txcal_radio_regs = NULL;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
wlc_phy_rx_iq_coeffs_nphy(pi, 0,
&pi->calibration_cache.
rxcal_coeffs_2G);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
txcal_radio_regs =
pi->calibration_cache.txcal_radio_regs_2G;
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->calibration_cache.txcal_radio_regs_2G[0] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_2G[1] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_2G[2] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_2G[3] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_2G[4] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_2G[5] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_2G[6] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_2G[7] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX1);
} else {
pi->calibration_cache.txcal_radio_regs_2G[0] =
read_radio_reg(pi, RADIO_2055_CORE1_TX_VOS_CNCL);
pi->calibration_cache.txcal_radio_regs_2G[1] =
read_radio_reg(pi, RADIO_2055_CORE2_TX_VOS_CNCL);
pi->calibration_cache.txcal_radio_regs_2G[2] =
read_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM);
pi->calibration_cache.txcal_radio_regs_2G[3] =
read_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM);
}
pi->nphy_iqcal_chanspec_2G = pi->radio_chanspec;
tbl_ptr = pi->calibration_cache.txcal_coeffs_2G;
} else {
wlc_phy_rx_iq_coeffs_nphy(pi, 0,
&pi->calibration_cache.
rxcal_coeffs_5G);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
txcal_radio_regs =
pi->calibration_cache.txcal_radio_regs_5G;
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->calibration_cache.txcal_radio_regs_5G[0] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_5G[1] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_5G[2] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_5G[3] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_5G[4] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_5G[5] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX0);
pi->calibration_cache.txcal_radio_regs_5G[6] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX1);
pi->calibration_cache.txcal_radio_regs_5G[7] =
read_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX1);
} else {
pi->calibration_cache.txcal_radio_regs_5G[0] =
read_radio_reg(pi, RADIO_2055_CORE1_TX_VOS_CNCL);
pi->calibration_cache.txcal_radio_regs_5G[1] =
read_radio_reg(pi, RADIO_2055_CORE2_TX_VOS_CNCL);
pi->calibration_cache.txcal_radio_regs_5G[2] =
read_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM);
pi->calibration_cache.txcal_radio_regs_5G[3] =
read_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM);
}
pi->nphy_iqcal_chanspec_5G = pi->radio_chanspec;
tbl_ptr = pi->calibration_cache.txcal_coeffs_5G;
}
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (coreNum = 0; coreNum <= 1; coreNum++) {
txcal_radio_regs[2 * coreNum] =
READ_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_FINE_I);
txcal_radio_regs[2 * coreNum + 1] =
READ_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_FINE_Q);
txcal_radio_regs[2 * coreNum + 4] =
READ_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_COARSE_I);
txcal_radio_regs[2 * coreNum + 5] =
READ_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_COARSE_Q);
}
}
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL, 8, 80, 16, tbl_ptr);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void wlc_phy_tx_iq_war_nphy(struct brcms_phy *pi)
{
struct nphy_iq_comp tx_comp;
wlc_phy_table_read_nphy(pi, 15, 4, 0x50, 16, &tx_comp);
wlapi_bmac_write_shm(pi->sh->physhim, M_20IN40_IQ, tx_comp.a0);
wlapi_bmac_write_shm(pi->sh->physhim, M_20IN40_IQ + 2, tx_comp.b0);
wlapi_bmac_write_shm(pi->sh->physhim, M_20IN40_IQ + 4, tx_comp.a1);
wlapi_bmac_write_shm(pi->sh->physhim, M_20IN40_IQ + 6, tx_comp.b1);
}
static void wlc_phy_restorecal_nphy(struct brcms_phy *pi)
{
u16 *loft_comp;
u16 txcal_coeffs_bphy[4];
u16 *tbl_ptr;
int coreNum;
u16 *txcal_radio_regs = NULL;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (pi->nphy_iqcal_chanspec_2G == 0)
return;
tbl_ptr = pi->calibration_cache.txcal_coeffs_2G;
loft_comp = &pi->calibration_cache.txcal_coeffs_2G[5];
} else {
if (pi->nphy_iqcal_chanspec_5G == 0)
return;
tbl_ptr = pi->calibration_cache.txcal_coeffs_5G;
loft_comp = &pi->calibration_cache.txcal_coeffs_5G[5];
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 80, 16, tbl_ptr);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
txcal_coeffs_bphy[0] = tbl_ptr[0];
txcal_coeffs_bphy[1] = tbl_ptr[1];
txcal_coeffs_bphy[2] = tbl_ptr[2];
txcal_coeffs_bphy[3] = tbl_ptr[3];
} else {
txcal_coeffs_bphy[0] = 0;
txcal_coeffs_bphy[1] = 0;
txcal_coeffs_bphy[2] = 0;
txcal_coeffs_bphy[3] = 0;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 88, 16,
txcal_coeffs_bphy);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 85, 16, loft_comp);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 93, 16, loft_comp);
if (NREV_LT(pi->pubpi.phy_rev, 2))
wlc_phy_tx_iq_war_nphy(pi);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
txcal_radio_regs =
pi->calibration_cache.txcal_radio_regs_2G;
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_2G[0]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_2G[1]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_2G[2]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_2G[3]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_2G[4]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_2G[5]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_2G[6]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_2G[7]);
} else {
write_radio_reg(pi, RADIO_2055_CORE1_TX_VOS_CNCL,
pi->calibration_cache.
txcal_radio_regs_2G[0]);
write_radio_reg(pi, RADIO_2055_CORE2_TX_VOS_CNCL,
pi->calibration_cache.
txcal_radio_regs_2G[1]);
write_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM,
pi->calibration_cache.
txcal_radio_regs_2G[2]);
write_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM,
pi->calibration_cache.
txcal_radio_regs_2G[3]);
}
wlc_phy_rx_iq_coeffs_nphy(pi, 1,
&pi->calibration_cache.
rxcal_coeffs_2G);
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
txcal_radio_regs =
pi->calibration_cache.txcal_radio_regs_5G;
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_5G[0]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_5G[1]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_I |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_5G[2]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_FINE_Q |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_5G[3]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_5G[4]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX0,
pi->calibration_cache.
txcal_radio_regs_5G[5]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_I |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_5G[6]);
write_radio_reg(pi,
RADIO_2056_TX_LOFT_COARSE_Q |
RADIO_2056_TX1,
pi->calibration_cache.
txcal_radio_regs_5G[7]);
} else {
write_radio_reg(pi, RADIO_2055_CORE1_TX_VOS_CNCL,
pi->calibration_cache.
txcal_radio_regs_5G[0]);
write_radio_reg(pi, RADIO_2055_CORE2_TX_VOS_CNCL,
pi->calibration_cache.
txcal_radio_regs_5G[1]);
write_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM,
pi->calibration_cache.
txcal_radio_regs_5G[2]);
write_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM,
pi->calibration_cache.
txcal_radio_regs_5G[3]);
}
wlc_phy_rx_iq_coeffs_nphy(pi, 1,
&pi->calibration_cache.
rxcal_coeffs_5G);
}
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (coreNum = 0; coreNum <= 1; coreNum++) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_FINE_I,
txcal_radio_regs[2 * coreNum]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_FINE_Q,
txcal_radio_regs[2 * coreNum + 1]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_COARSE_I,
txcal_radio_regs[2 * coreNum + 4]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, coreNum,
LOFT_COARSE_Q,
txcal_radio_regs[2 * coreNum + 5]);
}
}
}
static void wlc_phy_txpwrctrl_coeff_setup_nphy(struct brcms_phy *pi)
{
u32 idx;
u16 iqloCalbuf[7];
u32 iqcomp, locomp, curr_locomp;
s8 locomp_i, locomp_q;
s8 curr_locomp_i, curr_locomp_q;
u32 tbl_id, tbl_len, tbl_offset;
u32 regval[128];
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
wlc_phy_table_read_nphy(pi, 15, 7, 80, 16, iqloCalbuf);
tbl_len = 128;
tbl_offset = 320;
for (tbl_id = NPHY_TBL_ID_CORE1TXPWRCTL;
tbl_id <= NPHY_TBL_ID_CORE2TXPWRCTL; tbl_id++) {
iqcomp =
(tbl_id ==
26) ? (((u32) (iqloCalbuf[0] & 0x3ff)) << 10) |
(iqloCalbuf[1] & 0x3ff)
: (((u32) (iqloCalbuf[2] & 0x3ff)) << 10) |
(iqloCalbuf[3] & 0x3ff);
for (idx = 0; idx < tbl_len; idx++)
regval[idx] = iqcomp;
wlc_phy_table_write_nphy(pi, tbl_id, tbl_len, tbl_offset, 32,
regval);
}
tbl_offset = 448;
for (tbl_id = NPHY_TBL_ID_CORE1TXPWRCTL;
tbl_id <= NPHY_TBL_ID_CORE2TXPWRCTL; tbl_id++) {
locomp =
(u32) ((tbl_id == 26) ? iqloCalbuf[5] : iqloCalbuf[6]);
locomp_i = (s8) ((locomp >> 8) & 0xff);
locomp_q = (s8) ((locomp) & 0xff);
for (idx = 0; idx < tbl_len; idx++) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
curr_locomp_i = locomp_i;
curr_locomp_q = locomp_q;
} else {
curr_locomp_i = (s8) ((locomp_i *
nphy_tpc_loscale[idx] +
128) >> 8);
curr_locomp_q =
(s8) ((locomp_q *
nphy_tpc_loscale[idx] +
128) >> 8);
}
curr_locomp = (u32) ((curr_locomp_i & 0xff) << 8);
curr_locomp |= (u32) (curr_locomp_q & 0xff);
regval[idx] = curr_locomp;
}
wlc_phy_table_write_nphy(pi, tbl_id, tbl_len, tbl_offset, 32,
regval);
}
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
wlapi_bmac_write_shm(pi->sh->physhim, M_CURR_IDX1, 0xFFFF);
wlapi_bmac_write_shm(pi->sh->physhim, M_CURR_IDX2, 0xFFFF);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void wlc_phy_txlpfbw_nphy(struct brcms_phy *pi)
{
u8 tx_lpf_bw = 0;
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LT(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS40(pi->radio_chanspec))
tx_lpf_bw = 3;
else
tx_lpf_bw = 1;
if (PHY_IPA(pi)) {
if (CHSPEC_IS40(pi->radio_chanspec))
tx_lpf_bw = 5;
else
tx_lpf_bw = 4;
}
write_phy_reg(pi, 0xe8,
(tx_lpf_bw << 0) |
(tx_lpf_bw << 3) |
(tx_lpf_bw << 6) | (tx_lpf_bw << 9));
if (PHY_IPA(pi)) {
if (CHSPEC_IS40(pi->radio_chanspec))
tx_lpf_bw = 4;
else
tx_lpf_bw = 1;
write_phy_reg(pi, 0xe9,
(tx_lpf_bw << 0) |
(tx_lpf_bw << 3) |
(tx_lpf_bw << 6) | (tx_lpf_bw << 9));
}
}
}
static void
wlc_phy_adjust_rx_analpfbw_nphy(struct brcms_phy *pi, u16 reduction_factr)
{
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LT(pi->pubpi.phy_rev, 7)) {
if ((CHSPEC_CHANNEL(pi->radio_chanspec) == 11) &&
CHSPEC_IS40(pi->radio_chanspec)) {
if (!pi->nphy_anarxlpf_adjusted) {
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_LPC |
RADIO_2056_RX0),
((pi->nphy_rccal_value +
reduction_factr) | 0x80));
pi->nphy_anarxlpf_adjusted = true;
}
} else {
if (pi->nphy_anarxlpf_adjusted) {
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_LPC |
RADIO_2056_RX0),
(pi->nphy_rccal_value | 0x80));
pi->nphy_anarxlpf_adjusted = false;
}
}
}
}
static void
wlc_phy_adjust_min_noisevar_nphy(struct brcms_phy *pi, int ntones,
int *tone_id_buf, u32 *noise_var_buf)
{
int i;
u32 offset;
int tone_id;
int tbllen =
CHSPEC_IS40(pi->radio_chanspec) ?
NPHY_NOISEVAR_TBLLEN40 : NPHY_NOISEVAR_TBLLEN20;
if (pi->nphy_noisevars_adjusted) {
for (i = 0; i < pi->nphy_saved_noisevars.bufcount; i++) {
tone_id = pi->nphy_saved_noisevars.tone_id[i];
offset = (tone_id >= 0) ?
((tone_id *
2) + 1) : (tbllen + (tone_id * 2) + 1);
wlc_phy_table_write_nphy(
pi, NPHY_TBL_ID_NOISEVAR, 1,
offset, 32,
&pi->nphy_saved_noisevars.min_noise_vars[i]);
}
pi->nphy_saved_noisevars.bufcount = 0;
pi->nphy_noisevars_adjusted = false;
}
if ((noise_var_buf != NULL) && (tone_id_buf != NULL)) {
pi->nphy_saved_noisevars.bufcount = 0;
for (i = 0; i < ntones; i++) {
tone_id = tone_id_buf[i];
offset = (tone_id >= 0) ?
((tone_id * 2) + 1) :
(tbllen + (tone_id * 2) + 1);
pi->nphy_saved_noisevars.tone_id[i] = tone_id;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
offset, 32,
&pi->nphy_saved_noisevars.
min_noise_vars[i]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_NOISEVAR, 1,
offset, 32, &noise_var_buf[i]);
pi->nphy_saved_noisevars.bufcount++;
}
pi->nphy_noisevars_adjusted = true;
}
}
static void wlc_phy_adjust_crsminpwr_nphy(struct brcms_phy *pi, u8 minpwr)
{
u16 regval;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if ((CHSPEC_CHANNEL(pi->radio_chanspec) == 11) &&
CHSPEC_IS40(pi->radio_chanspec)) {
if (!pi->nphy_crsminpwr_adjusted) {
regval = read_phy_reg(pi, 0x27d);
pi->nphy_crsminpwr[0] = regval & 0xff;
regval &= 0xff00;
regval |= (u16) minpwr;
write_phy_reg(pi, 0x27d, regval);
regval = read_phy_reg(pi, 0x280);
pi->nphy_crsminpwr[1] = regval & 0xff;
regval &= 0xff00;
regval |= (u16) minpwr;
write_phy_reg(pi, 0x280, regval);
regval = read_phy_reg(pi, 0x283);
pi->nphy_crsminpwr[2] = regval & 0xff;
regval &= 0xff00;
regval |= (u16) minpwr;
write_phy_reg(pi, 0x283, regval);
pi->nphy_crsminpwr_adjusted = true;
}
} else {
if (pi->nphy_crsminpwr_adjusted) {
regval = read_phy_reg(pi, 0x27d);
regval &= 0xff00;
regval |= pi->nphy_crsminpwr[0];
write_phy_reg(pi, 0x27d, regval);
regval = read_phy_reg(pi, 0x280);
regval &= 0xff00;
regval |= pi->nphy_crsminpwr[1];
write_phy_reg(pi, 0x280, regval);
regval = read_phy_reg(pi, 0x283);
regval &= 0xff00;
regval |= pi->nphy_crsminpwr[2];
write_phy_reg(pi, 0x283, regval);
pi->nphy_crsminpwr_adjusted = false;
}
}
}
}
static void wlc_phy_spurwar_nphy(struct brcms_phy *pi)
{
u16 cur_channel = 0;
int nphy_adj_tone_id_buf[] = { 57, 58 };
u32 nphy_adj_noise_var_buf[] = { 0x3ff, 0x3ff };
bool isAdjustNoiseVar = false;
uint numTonesAdjust = 0;
u32 tempval = 0;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
cur_channel = CHSPEC_CHANNEL(pi->radio_chanspec);
if (pi->nphy_gband_spurwar_en) {
wlc_phy_adjust_rx_analpfbw_nphy(
pi,
NPHY_ANARXLPFBW_REDUCTIONFACT);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((cur_channel == 11)
&& CHSPEC_IS40(pi->radio_chanspec))
wlc_phy_adjust_min_noisevar_nphy(
pi, 2,
nphy_adj_tone_id_buf,
nphy_adj_noise_var_buf);
else
wlc_phy_adjust_min_noisevar_nphy(pi, 0,
NULL,
NULL);
}
wlc_phy_adjust_crsminpwr_nphy(pi,
NPHY_ADJUSTED_MINCRSPOWER);
}
if ((pi->nphy_gband_spurwar2_en)
&& CHSPEC_IS2G(pi->radio_chanspec)) {
if (CHSPEC_IS40(pi->radio_chanspec)) {
switch (cur_channel) {
case 3:
nphy_adj_tone_id_buf[0] = 57;
nphy_adj_tone_id_buf[1] = 58;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x25f;
isAdjustNoiseVar = true;
break;
case 4:
nphy_adj_tone_id_buf[0] = 41;
nphy_adj_tone_id_buf[1] = 42;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x25f;
isAdjustNoiseVar = true;
break;
case 5:
nphy_adj_tone_id_buf[0] = 25;
nphy_adj_tone_id_buf[1] = 26;
nphy_adj_noise_var_buf[0] = 0x24f;
nphy_adj_noise_var_buf[1] = 0x25f;
isAdjustNoiseVar = true;
break;
case 6:
nphy_adj_tone_id_buf[0] = 9;
nphy_adj_tone_id_buf[1] = 10;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x24f;
isAdjustNoiseVar = true;
break;
case 7:
nphy_adj_tone_id_buf[0] = 121;
nphy_adj_tone_id_buf[1] = 122;
nphy_adj_noise_var_buf[0] = 0x18f;
nphy_adj_noise_var_buf[1] = 0x24f;
isAdjustNoiseVar = true;
break;
case 8:
nphy_adj_tone_id_buf[0] = 105;
nphy_adj_tone_id_buf[1] = 106;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x25f;
isAdjustNoiseVar = true;
break;
case 9:
nphy_adj_tone_id_buf[0] = 89;
nphy_adj_tone_id_buf[1] = 90;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x24f;
isAdjustNoiseVar = true;
break;
case 10:
nphy_adj_tone_id_buf[0] = 73;
nphy_adj_tone_id_buf[1] = 74;
nphy_adj_noise_var_buf[0] = 0x22f;
nphy_adj_noise_var_buf[1] = 0x24f;
isAdjustNoiseVar = true;
break;
default:
isAdjustNoiseVar = false;
break;
}
}
if (isAdjustNoiseVar) {
numTonesAdjust = ARRAY_SIZE(nphy_adj_tone_id_buf);
wlc_phy_adjust_min_noisevar_nphy(
pi,
numTonesAdjust,
nphy_adj_tone_id_buf,
nphy_adj_noise_var_buf);
tempval = 0;
} else {
wlc_phy_adjust_min_noisevar_nphy(pi, 0, NULL,
NULL);
}
}
if ((pi->nphy_aband_spurwar_en) &&
(CHSPEC_IS5G(pi->radio_chanspec))) {
switch (cur_channel) {
case 54:
nphy_adj_tone_id_buf[0] = 32;
nphy_adj_noise_var_buf[0] = 0x25f;
break;
case 38:
case 102:
case 118:
if ((pi->sh->chip == BCMA_CHIP_ID_BCM4716) &&
(pi->sh->chippkg == BCMA_PKG_ID_BCM4717)) {
nphy_adj_tone_id_buf[0] = 32;
nphy_adj_noise_var_buf[0] = 0x21f;
} else {
nphy_adj_tone_id_buf[0] = 0;
nphy_adj_noise_var_buf[0] = 0x0;
}
break;
case 134:
nphy_adj_tone_id_buf[0] = 32;
nphy_adj_noise_var_buf[0] = 0x21f;
break;
case 151:
nphy_adj_tone_id_buf[0] = 16;
nphy_adj_noise_var_buf[0] = 0x23f;
break;
case 153:
case 161:
nphy_adj_tone_id_buf[0] = 48;
nphy_adj_noise_var_buf[0] = 0x23f;
break;
default:
nphy_adj_tone_id_buf[0] = 0;
nphy_adj_noise_var_buf[0] = 0x0;
break;
}
if (nphy_adj_tone_id_buf[0]
&& nphy_adj_noise_var_buf[0])
wlc_phy_adjust_min_noisevar_nphy(
pi, 1,
nphy_adj_tone_id_buf,
nphy_adj_noise_var_buf);
else
wlc_phy_adjust_min_noisevar_nphy(pi, 0, NULL,
NULL);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
}
void wlc_phy_init_nphy(struct brcms_phy *pi)
{
u16 val;
u16 clip1_ths[2];
struct nphy_txgains target_gain;
u8 tx_pwr_ctrl_state;
bool do_nphy_cal = false;
uint core;
u32 d11_clk_ctl_st;
bool do_rssi_cal = false;
core = 0;
if (!(pi->measure_hold & PHY_HOLD_FOR_SCAN))
pi->measure_hold |= PHY_HOLD_FOR_NOT_ASSOC;
if ((ISNPHY(pi)) && (NREV_GE(pi->pubpi.phy_rev, 5)) &&
((pi->sh->chippkg == BCMA_PKG_ID_BCM4717) ||
(pi->sh->chippkg == BCMA_PKG_ID_BCM4718))) {
if ((pi->sh->boardflags & BFL_EXTLNA) &&
(CHSPEC_IS2G(pi->radio_chanspec)))
bcma_cc_set32(&pi->d11core->bus->drv_cc,
BCMA_CC_CHIPCTL, 0x40);
}
if ((!PHY_IPA(pi)) && (pi->sh->chip == BCMA_CHIP_ID_BCM5357))
bcma_chipco_chipctl_maskset(&pi->d11core->bus->drv_cc, 1,
~CCTRL5357_EXTPA, CCTRL5357_EXTPA);
if ((pi->nphy_gband_spurwar2_en) && CHSPEC_IS2G(pi->radio_chanspec) &&
CHSPEC_IS40(pi->radio_chanspec)) {
d11_clk_ctl_st = bcma_read32(pi->d11core,
D11REGOFFS(clk_ctl_st));
bcma_mask32(pi->d11core, D11REGOFFS(clk_ctl_st),
~(CCS_FORCEHT | CCS_HTAREQ));
bcma_write32(pi->d11core, D11REGOFFS(clk_ctl_st),
d11_clk_ctl_st);
}
pi->use_int_tx_iqlo_cal_nphy =
(PHY_IPA(pi) ||
(NREV_GE(pi->pubpi.phy_rev, 7) ||
(NREV_GE(pi->pubpi.phy_rev, 5)
&& pi->sh->boardflags2 & BFL2_INTERNDET_TXIQCAL)));
pi->internal_tx_iqlo_cal_tapoff_intpa_nphy = false;
pi->nphy_deaf_count = 0;
wlc_phy_tbl_init_nphy(pi);
pi->nphy_crsminpwr_adjusted = false;
pi->nphy_noisevars_adjusted = false;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_phy_reg(pi, 0xe7, 0);
write_phy_reg(pi, 0xec, 0);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
write_phy_reg(pi, 0x342, 0);
write_phy_reg(pi, 0x343, 0);
write_phy_reg(pi, 0x346, 0);
write_phy_reg(pi, 0x347, 0);
}
write_phy_reg(pi, 0xe5, 0);
write_phy_reg(pi, 0xe6, 0);
} else {
write_phy_reg(pi, 0xec, 0);
}
write_phy_reg(pi, 0x91, 0);
write_phy_reg(pi, 0x92, 0);
if (NREV_LT(pi->pubpi.phy_rev, 6)) {
write_phy_reg(pi, 0x93, 0);
write_phy_reg(pi, 0x94, 0);
}
and_phy_reg(pi, 0xa1, ~3);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_phy_reg(pi, 0x8f, 0);
write_phy_reg(pi, 0xa5, 0);
} else {
write_phy_reg(pi, 0xa5, 0);
}
if (NREV_IS(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x3b);
else if (NREV_LT(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x40);
write_phy_reg(pi, 0x203, 32);
write_phy_reg(pi, 0x201, 32);
if (pi->sh->boardflags2 & BFL2_SKWRKFEM_BRD)
write_phy_reg(pi, 0x20d, 160);
else
write_phy_reg(pi, 0x20d, 184);
write_phy_reg(pi, 0x13a, 200);
write_phy_reg(pi, 0x70, 80);
write_phy_reg(pi, 0x1ff, 48);
if (NREV_LT(pi->pubpi.phy_rev, 8))
wlc_phy_update_mimoconfig_nphy(pi, pi->n_preamble_override);
wlc_phy_stf_chain_upd_nphy(pi);
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
write_phy_reg(pi, 0x180, 0xaa8);
write_phy_reg(pi, 0x181, 0x9a4);
}
if (PHY_IPA(pi)) {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (1) << 0);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x298 :
0x29c, (0x1ff << 7),
(pi->nphy_papd_epsilon_offset[core]) << 7);
}
wlc_phy_ipa_set_tx_digi_filts_nphy(pi);
} else if (NREV_GE(pi->pubpi.phy_rev, 5)) {
wlc_phy_extpa_set_tx_digi_filts_nphy(pi);
}
wlc_phy_workarounds_nphy(pi);
wlapi_bmac_phyclk_fgc(pi->sh->physhim, ON);
val = read_phy_reg(pi, 0x01);
write_phy_reg(pi, 0x01, val | BBCFG_RESETCCA);
write_phy_reg(pi, 0x01, val & (~BBCFG_RESETCCA));
wlapi_bmac_phyclk_fgc(pi->sh->physhim, OFF);
wlapi_bmac_macphyclk_set(pi->sh->physhim, ON);
wlc_phy_pa_override_nphy(pi, OFF);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RX2TX);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
wlc_phy_pa_override_nphy(pi, ON);
wlc_phy_classifier_nphy(pi, 0, 0);
wlc_phy_clip_det_nphy(pi, 0, clip1_ths);
if (CHSPEC_IS2G(pi->radio_chanspec))
wlc_phy_bphy_init_nphy(pi);
tx_pwr_ctrl_state = pi->nphy_txpwrctrl;
wlc_phy_txpwrctrl_enable_nphy(pi, PHY_TPC_HW_OFF);
wlc_phy_txpwr_fixpower_nphy(pi);
wlc_phy_txpwrctrl_idle_tssi_nphy(pi);
wlc_phy_txpwrctrl_pwr_setup_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
u32 *tx_pwrctrl_tbl = NULL;
u16 idx;
s16 pga_gn = 0;
s16 pad_gn = 0;
s32 rfpwr_offset;
if (PHY_IPA(pi)) {
tx_pwrctrl_tbl = wlc_phy_get_ipa_gaintbl_nphy(pi);
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_IS(pi->pubpi.phy_rev, 3))
tx_pwrctrl_tbl =
nphy_tpc_5GHz_txgain_rev3;
else if (NREV_IS(pi->pubpi.phy_rev, 4))
tx_pwrctrl_tbl =
(pi->srom_fem5g.extpagain ==
3) ?
nphy_tpc_5GHz_txgain_HiPwrEPA :
nphy_tpc_5GHz_txgain_rev4;
else
tx_pwrctrl_tbl =
nphy_tpc_5GHz_txgain_rev5;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (pi->pubpi.radiorev == 5)
tx_pwrctrl_tbl =
nphy_tpc_txgain_epa_2057rev5;
else if (pi->pubpi.radiorev == 3)
tx_pwrctrl_tbl =
nphy_tpc_txgain_epa_2057rev3;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 5) &&
(pi->srom_fem2g.extpagain == 3))
tx_pwrctrl_tbl =
nphy_tpc_txgain_HiPwrEPA;
else
tx_pwrctrl_tbl =
nphy_tpc_txgain_rev3;
}
}
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE1TXPWRCTL, 128,
192, 32, tx_pwrctrl_tbl);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE2TXPWRCTL, 128,
192, 32, tx_pwrctrl_tbl);
pi->nphy_gmval = (u16) ((*tx_pwrctrl_tbl >> 16) & 0x7000);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (idx = 0; idx < 128; idx++) {
pga_gn = (tx_pwrctrl_tbl[idx] >> 24) & 0xf;
pad_gn = (tx_pwrctrl_tbl[idx] >> 19) & 0x1f;
rfpwr_offset = get_rf_pwr_offset(pi, pga_gn,
pad_gn);
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_CORE1TXPWRCTL,
1, 576 + idx, 32,
&rfpwr_offset);
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_CORE2TXPWRCTL,
1, 576 + idx, 32,
&rfpwr_offset);
}
} else {
for (idx = 0; idx < 128; idx++) {
pga_gn = (tx_pwrctrl_tbl[idx] >> 24) & 0xf;
if (CHSPEC_IS2G(pi->radio_chanspec))
rfpwr_offset = (s16)
nphy_papd_pga_gain_delta_ipa_2g
[pga_gn];
else
rfpwr_offset = (s16)
nphy_papd_pga_gain_delta_ipa_5g
[pga_gn];
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_CORE1TXPWRCTL,
1, 576 + idx, 32,
&rfpwr_offset);
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_CORE2TXPWRCTL,
1, 576 + idx, 32,
&rfpwr_offset);
}
}
} else {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE1TXPWRCTL, 128,
192, 32, nphy_tpc_txgain);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE2TXPWRCTL, 128,
192, 32, nphy_tpc_txgain);
}
if (pi->sh->phyrxchain != 0x3)
wlc_phy_rxcore_setstate_nphy((struct brcms_phy_pub *) pi,
pi->sh->phyrxchain);
if (PHY_PERICAL_MPHASE_PENDING(pi))
wlc_phy_cal_perical_mphase_restart(pi);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
do_rssi_cal = (CHSPEC_IS2G(pi->radio_chanspec)) ?
(pi->nphy_rssical_chanspec_2G == 0) :
(pi->nphy_rssical_chanspec_5G == 0);
if (do_rssi_cal)
wlc_phy_rssi_cal_nphy(pi);
else
wlc_phy_restore_rssical_nphy(pi);
} else {
wlc_phy_rssi_cal_nphy(pi);
}
if (!SCAN_RM_IN_PROGRESS(pi))
do_nphy_cal = (CHSPEC_IS2G(pi->radio_chanspec)) ?
(pi->nphy_iqcal_chanspec_2G == 0) :
(pi->nphy_iqcal_chanspec_5G == 0);
if (!pi->do_initcal)
do_nphy_cal = false;
if (do_nphy_cal) {
target_gain = wlc_phy_get_tx_gain_nphy(pi);
if (pi->antsel_type == ANTSEL_2x3)
wlc_phy_antsel_init((struct brcms_phy_pub *) pi,
true);
if (pi->nphy_perical != PHY_PERICAL_MPHASE) {
wlc_phy_rssi_cal_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->nphy_cal_orig_pwr_idx[0] =
pi->nphy_txpwrindex[PHY_CORE_0]
.
index_internal;
pi->nphy_cal_orig_pwr_idx[1] =
pi->nphy_txpwrindex[PHY_CORE_1]
.
index_internal;
wlc_phy_precal_txgain_nphy(pi);
target_gain =
wlc_phy_get_tx_gain_nphy(pi);
}
if (wlc_phy_cal_txiqlo_nphy
(pi, target_gain, true,
false) == 0) {
if (wlc_phy_cal_rxiq_nphy
(pi, target_gain, 2,
false) == 0)
wlc_phy_savecal_nphy(pi);
}
} else if (pi->mphase_cal_phase_id ==
MPHASE_CAL_STATE_IDLE) {
wlc_phy_cal_perical((struct brcms_phy_pub *) pi,
PHY_PERICAL_PHYINIT);
}
} else {
wlc_phy_restorecal_nphy(pi);
}
wlc_phy_txpwrctrl_coeff_setup_nphy(pi);
wlc_phy_txpwrctrl_enable_nphy(pi, tx_pwr_ctrl_state);
wlc_phy_nphy_tkip_rifs_war(pi, pi->sh->_rifs_phy);
if (NREV_GE(pi->pubpi.phy_rev, 3) && NREV_LE(pi->pubpi.phy_rev, 6))
write_phy_reg(pi, 0x70, 50);
wlc_phy_txlpfbw_nphy(pi);
wlc_phy_spurwar_nphy(pi);
}
static void wlc_phy_resetcca_nphy(struct brcms_phy *pi)
{
u16 val;
wlapi_bmac_phyclk_fgc(pi->sh->physhim, ON);
val = read_phy_reg(pi, 0x01);
write_phy_reg(pi, 0x01, val | BBCFG_RESETCCA);
udelay(1);
write_phy_reg(pi, 0x01, val & (~BBCFG_RESETCCA));
wlapi_bmac_phyclk_fgc(pi->sh->physhim, OFF);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
}
void wlc_phy_pa_override_nphy(struct brcms_phy *pi, bool en)
{
u16 rfctrlintc_override_val;
if (!en) {
pi->rfctrlIntc1_save = read_phy_reg(pi, 0x91);
pi->rfctrlIntc2_save = read_phy_reg(pi, 0x92);
if (NREV_GE(pi->pubpi.phy_rev, 7))
rfctrlintc_override_val = 0x1480;
else if (NREV_GE(pi->pubpi.phy_rev, 3))
rfctrlintc_override_val =
CHSPEC_IS5G(pi->radio_chanspec) ? 0x600 : 0x480;
else
rfctrlintc_override_val =
CHSPEC_IS5G(pi->radio_chanspec) ? 0x180 : 0x120;
write_phy_reg(pi, 0x91, rfctrlintc_override_val);
write_phy_reg(pi, 0x92, rfctrlintc_override_val);
} else {
write_phy_reg(pi, 0x91, pi->rfctrlIntc1_save);
write_phy_reg(pi, 0x92, pi->rfctrlIntc2_save);
}
}
void wlc_phy_stf_chain_upd_nphy(struct brcms_phy *pi)
{
u16 txrx_chain =
(NPHY_RfseqCoreActv_TxRxChain0 | NPHY_RfseqCoreActv_TxRxChain1);
bool CoreActv_override = false;
if (pi->nphy_txrx_chain == BRCMS_N_TXRX_CHAIN0) {
txrx_chain = NPHY_RfseqCoreActv_TxRxChain0;
CoreActv_override = true;
if (NREV_LE(pi->pubpi.phy_rev, 2))
and_phy_reg(pi, 0xa0, ~0x20);
} else if (pi->nphy_txrx_chain == BRCMS_N_TXRX_CHAIN1) {
txrx_chain = NPHY_RfseqCoreActv_TxRxChain1;
CoreActv_override = true;
if (NREV_LE(pi->pubpi.phy_rev, 2))
or_phy_reg(pi, 0xa0, 0x20);
}
mod_phy_reg(pi, 0xa2, ((0xf << 0) | (0xf << 4)), txrx_chain);
if (CoreActv_override) {
pi->nphy_perical = PHY_PERICAL_DISABLE;
or_phy_reg(pi, 0xa1, NPHY_RfseqMode_CoreActv_override);
} else {
pi->nphy_perical = PHY_PERICAL_MPHASE;
and_phy_reg(pi, 0xa1, ~NPHY_RfseqMode_CoreActv_override);
}
}
void wlc_phy_rxcore_setstate_nphy(struct brcms_phy_pub *pih, u8 rxcore_bitmask)
{
u16 regval;
u16 tbl_buf[16];
uint i;
struct brcms_phy *pi = (struct brcms_phy *) pih;
u16 tbl_opcode;
bool suspend;
pi->sh->phyrxchain = rxcore_bitmask;
if (!pi->sh->clk)
return;
suspend = (0 == (bcma_read32(pi->d11core, D11REGOFFS(maccontrol)) &
MCTL_EN_MAC));
if (!suspend)
wlapi_suspend_mac_and_wait(pi->sh->physhim);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
regval = read_phy_reg(pi, 0xa2);
regval &= ~(0xf << 4);
regval |= ((u16) (rxcore_bitmask & 0x3)) << 4;
write_phy_reg(pi, 0xa2, regval);
if ((rxcore_bitmask & 0x3) != 0x3) {
write_phy_reg(pi, 0x20e, 1);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (pi->rx2tx_biasentry == -1) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ,
ARRAY_SIZE(tbl_buf), 80,
16, tbl_buf);
for (i = 0; i < ARRAY_SIZE(tbl_buf); i++) {
if (tbl_buf[i] ==
NPHY_REV3_RFSEQ_CMD_CLR_RXRX_BIAS) {
pi->rx2tx_biasentry = (u8) i;
tbl_opcode =
NPHY_REV3_RFSEQ_CMD_NOP;
wlc_phy_table_write_nphy(
pi,
NPHY_TBL_ID_RFSEQ,
1, i,
16,
&tbl_opcode);
break;
} else if (tbl_buf[i] ==
NPHY_REV3_RFSEQ_CMD_END)
break;
}
}
}
} else {
write_phy_reg(pi, 0x20e, 30);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (pi->rx2tx_biasentry != -1) {
tbl_opcode = NPHY_REV3_RFSEQ_CMD_CLR_RXRX_BIAS;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ,
1, pi->rx2tx_biasentry,
16, &tbl_opcode);
pi->rx2tx_biasentry = -1;
}
}
}
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
if (!suspend)
wlapi_enable_mac(pi->sh->physhim);
}
u8 wlc_phy_rxcore_getstate_nphy(struct brcms_phy_pub *pih)
{
u16 regval, rxen_bits;
struct brcms_phy *pi = (struct brcms_phy *) pih;
regval = read_phy_reg(pi, 0xa2);
rxen_bits = (regval >> 4) & 0xf;
return (u8) rxen_bits;
}
bool wlc_phy_n_txpower_ipa_ison(struct brcms_phy *pi)
{
return PHY_IPA(pi);
}
void wlc_phy_cal_init_nphy(struct brcms_phy *pi)
{
}
static void wlc_phy_radio_preinit_205x(struct brcms_phy *pi)
{
and_phy_reg(pi, 0x78, ~RFCC_CHIP0_PU);
and_phy_reg(pi, 0x78, RFCC_OE_POR_FORCE);
or_phy_reg(pi, 0x78, ~RFCC_OE_POR_FORCE);
or_phy_reg(pi, 0x78, RFCC_CHIP0_PU);
}
static void wlc_phy_radio_init_2057(struct brcms_phy *pi)
{
struct radio_20xx_regs *regs_2057_ptr = NULL;
if (NREV_IS(pi->pubpi.phy_rev, 7)) {
regs_2057_ptr = regs_2057_rev4;
} else if (NREV_IS(pi->pubpi.phy_rev, 8)
|| NREV_IS(pi->pubpi.phy_rev, 9)) {
switch (pi->pubpi.radiorev) {
case 5:
if (NREV_IS(pi->pubpi.phy_rev, 8))
regs_2057_ptr = regs_2057_rev5;
else if (NREV_IS(pi->pubpi.phy_rev, 9))
regs_2057_ptr = regs_2057_rev5v1;
break;
case 7:
regs_2057_ptr = regs_2057_rev7;
break;
case 8:
regs_2057_ptr = regs_2057_rev8;
break;
default:
break;
}
}
wlc_phy_init_radio_regs_allbands(pi, regs_2057_ptr);
}
static u16 wlc_phy_radio205x_rcal(struct brcms_phy *pi)
{
u16 rcal_reg = 0;
int i;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (pi->pubpi.radiorev == 5) {
and_phy_reg(pi, 0x342, ~(0x1 << 1));
udelay(10);
mod_radio_reg(pi, RADIO_2057_IQTEST_SEL_PU, 0x1, 0x1);
mod_radio_reg(pi, RADIO_2057v7_IQTEST_SEL_PU2, 0x2,
0x1);
}
mod_radio_reg(pi, RADIO_2057_RCAL_CONFIG, 0x1, 0x1);
udelay(10);
mod_radio_reg(pi, RADIO_2057_RCAL_CONFIG, 0x3, 0x3);
for (i = 0; i < MAX_205x_RCAL_WAITLOOPS; i++) {
rcal_reg = read_radio_reg(pi, RADIO_2057_RCAL_STATUS);
if (rcal_reg & 0x1)
break;
udelay(100);
}
if (WARN(i == MAX_205x_RCAL_WAITLOOPS,
"HW error: radio calib2"))
return 0;
mod_radio_reg(pi, RADIO_2057_RCAL_CONFIG, 0x2, 0x0);
rcal_reg = read_radio_reg(pi, RADIO_2057_RCAL_STATUS) & 0x3e;
mod_radio_reg(pi, RADIO_2057_RCAL_CONFIG, 0x1, 0x0);
if (pi->pubpi.radiorev == 5) {
mod_radio_reg(pi, RADIO_2057_IQTEST_SEL_PU, 0x1, 0x0);
mod_radio_reg(pi, RADIO_2057v7_IQTEST_SEL_PU2, 0x2,
0x0);
}
if ((pi->pubpi.radiorev <= 4) || (pi->pubpi.radiorev == 6)) {
mod_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG, 0x3c,
rcal_reg);
mod_radio_reg(pi, RADIO_2057_BANDGAP_RCAL_TRIM, 0xf0,
rcal_reg << 2);
}
} else if (NREV_IS(pi->pubpi.phy_rev, 3)) {
u16 savereg;
savereg =
read_radio_reg(
pi,
RADIO_2056_SYN_PLL_MAST2 |
RADIO_2056_SYN);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST2 | RADIO_2056_SYN,
savereg | 0x7);
udelay(10);
write_radio_reg(pi, RADIO_2056_SYN_RCAL_MASTER | RADIO_2056_SYN,
0x1);
udelay(10);
write_radio_reg(pi, RADIO_2056_SYN_RCAL_MASTER | RADIO_2056_SYN,
0x9);
for (i = 0; i < MAX_205x_RCAL_WAITLOOPS; i++) {
rcal_reg = read_radio_reg(
pi,
RADIO_2056_SYN_RCAL_CODE_OUT |
RADIO_2056_SYN);
if (rcal_reg & 0x80)
break;
udelay(100);
}
if (WARN(i == MAX_205x_RCAL_WAITLOOPS,
"HW error: radio calib3"))
return 0;
write_radio_reg(pi, RADIO_2056_SYN_RCAL_MASTER | RADIO_2056_SYN,
0x1);
rcal_reg =
read_radio_reg(pi,
RADIO_2056_SYN_RCAL_CODE_OUT |
RADIO_2056_SYN);
write_radio_reg(pi, RADIO_2056_SYN_RCAL_MASTER | RADIO_2056_SYN,
0x0);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST2 | RADIO_2056_SYN,
savereg);
return rcal_reg & 0x1f;
}
return rcal_reg & 0x3e;
}
static u16 wlc_phy_radio2057_rccal(struct brcms_phy *pi)
{
u16 rccal_valid;
int i;
bool chip43226_6362A0;
chip43226_6362A0 = ((pi->pubpi.radiorev == 3)
|| (pi->pubpi.radiorev == 4)
|| (pi->pubpi.radiorev == 6));
rccal_valid = 0;
if (chip43226_6362A0) {
write_radio_reg(pi, RADIO_2057_RCCAL_MASTER, 0x61);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0xc0);
} else {
write_radio_reg(pi, RADIO_2057v7_RCCAL_MASTER, 0x61);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0xe9);
}
write_radio_reg(pi, RADIO_2057_RCCAL_X1, 0x6e);
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x55);
for (i = 0; i < MAX_205x_RCAL_WAITLOOPS; i++) {
rccal_valid = read_radio_reg(pi, RADIO_2057_RCCAL_DONE_OSCCAP);
if (rccal_valid & 0x2)
break;
udelay(500);
}
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x15);
rccal_valid = 0;
if (chip43226_6362A0) {
write_radio_reg(pi, RADIO_2057_RCCAL_MASTER, 0x69);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0xb0);
} else {
write_radio_reg(pi, RADIO_2057v7_RCCAL_MASTER, 0x69);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0xd5);
}
write_radio_reg(pi, RADIO_2057_RCCAL_X1, 0x6e);
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x55);
for (i = 0; i < MAX_205x_RCAL_WAITLOOPS; i++) {
rccal_valid = read_radio_reg(pi, RADIO_2057_RCCAL_DONE_OSCCAP);
if (rccal_valid & 0x2)
break;
udelay(500);
}
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x15);
rccal_valid = 0;
if (chip43226_6362A0) {
write_radio_reg(pi, RADIO_2057_RCCAL_MASTER, 0x73);
write_radio_reg(pi, RADIO_2057_RCCAL_X1, 0x28);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0xb0);
} else {
write_radio_reg(pi, RADIO_2057v7_RCCAL_MASTER, 0x73);
write_radio_reg(pi, RADIO_2057_RCCAL_X1, 0x6e);
write_radio_reg(pi, RADIO_2057_RCCAL_TRC0, 0x99);
}
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x55);
for (i = 0; i < MAX_205x_RCAL_WAITLOOPS; i++) {
rccal_valid = read_radio_reg(pi, RADIO_2057_RCCAL_DONE_OSCCAP);
if (rccal_valid & 0x2)
break;
udelay(500);
}
if (WARN(!(rccal_valid & 0x2), "HW error: radio calib4"))
return 0;
write_radio_reg(pi, RADIO_2057_RCCAL_START_R1_Q1_P1, 0x15);
return rccal_valid;
}
static void wlc_phy_radio_postinit_2057(struct brcms_phy *pi)
{
mod_radio_reg(pi, RADIO_2057_XTALPUOVR_PINCTRL, 0x1, 0x1);
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_CAL_RESETN, 0x78, 0x78);
mod_radio_reg(pi, RADIO_2057_XTAL_CONFIG2, 0x80, 0x80);
mdelay(2);
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_CAL_RESETN, 0x78, 0x0);
mod_radio_reg(pi, RADIO_2057_XTAL_CONFIG2, 0x80, 0x0);
if (pi->phy_init_por) {
wlc_phy_radio205x_rcal(pi);
wlc_phy_radio2057_rccal(pi);
}
mod_radio_reg(pi, RADIO_2057_RFPLL_MASTER, 0x8, 0x0);
}
static void wlc_phy_radio_init_2056(struct brcms_phy *pi)
{
const struct radio_regs *regs_SYN_2056_ptr = NULL;
const struct radio_regs *regs_TX_2056_ptr = NULL;
const struct radio_regs *regs_RX_2056_ptr = NULL;
if (NREV_IS(pi->pubpi.phy_rev, 3)) {
regs_SYN_2056_ptr = regs_SYN_2056;
regs_TX_2056_ptr = regs_TX_2056;
regs_RX_2056_ptr = regs_RX_2056;
} else if (NREV_IS(pi->pubpi.phy_rev, 4)) {
regs_SYN_2056_ptr = regs_SYN_2056_A1;
regs_TX_2056_ptr = regs_TX_2056_A1;
regs_RX_2056_ptr = regs_RX_2056_A1;
} else {
switch (pi->pubpi.radiorev) {
case 5:
regs_SYN_2056_ptr = regs_SYN_2056_rev5;
regs_TX_2056_ptr = regs_TX_2056_rev5;
regs_RX_2056_ptr = regs_RX_2056_rev5;
break;
case 6:
regs_SYN_2056_ptr = regs_SYN_2056_rev6;
regs_TX_2056_ptr = regs_TX_2056_rev6;
regs_RX_2056_ptr = regs_RX_2056_rev6;
break;
case 7:
case 9:
regs_SYN_2056_ptr = regs_SYN_2056_rev7;
regs_TX_2056_ptr = regs_TX_2056_rev7;
regs_RX_2056_ptr = regs_RX_2056_rev7;
break;
case 8:
regs_SYN_2056_ptr = regs_SYN_2056_rev8;
regs_TX_2056_ptr = regs_TX_2056_rev8;
regs_RX_2056_ptr = regs_RX_2056_rev8;
break;
case 11:
regs_SYN_2056_ptr = regs_SYN_2056_rev11;
regs_TX_2056_ptr = regs_TX_2056_rev11;
regs_RX_2056_ptr = regs_RX_2056_rev11;
break;
default:
break;
}
}
wlc_phy_init_radio_regs(pi, regs_SYN_2056_ptr, (u16) RADIO_2056_SYN);
wlc_phy_init_radio_regs(pi, regs_TX_2056_ptr, (u16) RADIO_2056_TX0);
wlc_phy_init_radio_regs(pi, regs_TX_2056_ptr, (u16) RADIO_2056_TX1);
wlc_phy_init_radio_regs(pi, regs_RX_2056_ptr, (u16) RADIO_2056_RX0);
wlc_phy_init_radio_regs(pi, regs_RX_2056_ptr, (u16) RADIO_2056_RX1);
}
static void wlc_phy_radio_postinit_2056(struct brcms_phy *pi)
{
mod_radio_reg(pi, RADIO_2056_SYN_COM_CTRL, 0xb, 0xb);
mod_radio_reg(pi, RADIO_2056_SYN_COM_PU, 0x2, 0x2);
mod_radio_reg(pi, RADIO_2056_SYN_COM_RESET, 0x2, 0x2);
udelay(1000);
mod_radio_reg(pi, RADIO_2056_SYN_COM_RESET, 0x2, 0x0);
if ((pi->sh->boardflags2 & BFL2_LEGACY)
|| (pi->sh->boardflags2 & BFL2_XTALBUFOUTEN))
mod_radio_reg(pi, RADIO_2056_SYN_PLL_MAST2, 0xf4, 0x0);
else
mod_radio_reg(pi, RADIO_2056_SYN_PLL_MAST2, 0xfc, 0x0);
mod_radio_reg(pi, RADIO_2056_SYN_RCCAL_CTRL0, 0x1, 0x0);
if (pi->phy_init_por)
wlc_phy_radio205x_rcal(pi);
}
static void wlc_phy_radio_preinit_2055(struct brcms_phy *pi)
{
and_phy_reg(pi, 0x78, ~RFCC_POR_FORCE);
or_phy_reg(pi, 0x78, RFCC_CHIP0_PU | RFCC_OE_POR_FORCE);
or_phy_reg(pi, 0x78, RFCC_POR_FORCE);
}
static void wlc_phy_radio_init_2055(struct brcms_phy *pi)
{
wlc_phy_init_radio_regs(pi, regs_2055, RADIO_DEFAULT_CORE);
}
static void wlc_phy_radio_postinit_2055(struct brcms_phy *pi)
{
and_radio_reg(pi, RADIO_2055_MASTER_CNTRL1,
~(RADIO_2055_JTAGCTRL_MASK | RADIO_2055_JTAGSYNC_MASK));
if (((pi->sh->sromrev >= 4)
&& !(pi->sh->boardflags2 & BFL2_RXBB_INT_REG_DIS))
|| ((pi->sh->sromrev < 4))) {
and_radio_reg(pi, RADIO_2055_CORE1_RXBB_REGULATOR, 0x7F);
and_radio_reg(pi, RADIO_2055_CORE2_RXBB_REGULATOR, 0x7F);
}
mod_radio_reg(pi, RADIO_2055_RRCCAL_N_OPT_SEL, 0x3F, 0x2C);
write_radio_reg(pi, RADIO_2055_CAL_MISC, 0x3C);
and_radio_reg(pi, RADIO_2055_CAL_MISC,
~(RADIO_2055_RRCAL_START | RADIO_2055_RRCAL_RST_N));
or_radio_reg(pi, RADIO_2055_CAL_LPO_CNTRL, RADIO_2055_CAL_LPO_ENABLE);
or_radio_reg(pi, RADIO_2055_CAL_MISC, RADIO_2055_RRCAL_RST_N);
udelay(1000);
or_radio_reg(pi, RADIO_2055_CAL_MISC, RADIO_2055_RRCAL_START);
SPINWAIT(((read_radio_reg(pi, RADIO_2055_CAL_COUNTER_OUT2) &
RADIO_2055_RCAL_DONE) != RADIO_2055_RCAL_DONE), 2000);
if (WARN((read_radio_reg(pi, RADIO_2055_CAL_COUNTER_OUT2) &
RADIO_2055_RCAL_DONE) != RADIO_2055_RCAL_DONE,
"HW error: radio calibration1\n"))
return;
and_radio_reg(pi, RADIO_2055_CAL_LPO_CNTRL,
~(RADIO_2055_CAL_LPO_ENABLE));
wlc_phy_chanspec_set((struct brcms_phy_pub *) pi, pi->radio_chanspec);
write_radio_reg(pi, RADIO_2055_CORE1_RXBB_LPF, 9);
write_radio_reg(pi, RADIO_2055_CORE2_RXBB_LPF, 9);
write_radio_reg(pi, RADIO_2055_CORE1_RXBB_MIDAC_HIPAS, 0x83);
write_radio_reg(pi, RADIO_2055_CORE2_RXBB_MIDAC_HIPAS, 0x83);
mod_radio_reg(pi, RADIO_2055_CORE1_LNA_GAINBST,
RADIO_2055_GAINBST_VAL_MASK, RADIO_2055_GAINBST_CODE);
mod_radio_reg(pi, RADIO_2055_CORE2_LNA_GAINBST,
RADIO_2055_GAINBST_VAL_MASK, RADIO_2055_GAINBST_CODE);
if (pi->nphy_gain_boost) {
and_radio_reg(pi, RADIO_2055_CORE1_RXRF_SPC1,
~(RADIO_2055_GAINBST_DISABLE));
and_radio_reg(pi, RADIO_2055_CORE2_RXRF_SPC1,
~(RADIO_2055_GAINBST_DISABLE));
} else {
or_radio_reg(pi, RADIO_2055_CORE1_RXRF_SPC1,
RADIO_2055_GAINBST_DISABLE);
or_radio_reg(pi, RADIO_2055_CORE2_RXRF_SPC1,
RADIO_2055_GAINBST_DISABLE);
}
udelay(2);
}
void wlc_phy_switch_radio_nphy(struct brcms_phy *pi, bool on)
{
if (on) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (!pi->radio_is_on) {
wlc_phy_radio_preinit_205x(pi);
wlc_phy_radio_init_2057(pi);
wlc_phy_radio_postinit_2057(pi);
}
wlc_phy_chanspec_set((struct brcms_phy_pub *) pi,
pi->radio_chanspec);
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
wlc_phy_radio_preinit_205x(pi);
wlc_phy_radio_init_2056(pi);
wlc_phy_radio_postinit_2056(pi);
wlc_phy_chanspec_set((struct brcms_phy_pub *) pi,
pi->radio_chanspec);
} else {
wlc_phy_radio_preinit_2055(pi);
wlc_phy_radio_init_2055(pi);
wlc_phy_radio_postinit_2055(pi);
}
pi->radio_is_on = true;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 3)
&& NREV_LT(pi->pubpi.phy_rev, 7)) {
and_phy_reg(pi, 0x78, ~RFCC_CHIP0_PU);
mod_radio_reg(pi, RADIO_2056_SYN_COM_PU, 0x2, 0x0);
write_radio_reg(pi,
RADIO_2056_TX_PADA_BOOST_TUNE |
RADIO_2056_TX0, 0);
write_radio_reg(pi,
RADIO_2056_TX_PADG_BOOST_TUNE |
RADIO_2056_TX0, 0);
write_radio_reg(pi,
RADIO_2056_TX_PGAA_BOOST_TUNE |
RADIO_2056_TX0, 0);
write_radio_reg(pi,
RADIO_2056_TX_PGAG_BOOST_TUNE |
RADIO_2056_TX0, 0);
mod_radio_reg(pi,
RADIO_2056_TX_MIXA_BOOST_TUNE |
RADIO_2056_TX0, 0xf0, 0);
write_radio_reg(pi,
RADIO_2056_TX_MIXG_BOOST_TUNE |
RADIO_2056_TX0, 0);
write_radio_reg(pi,
RADIO_2056_TX_PADA_BOOST_TUNE |
RADIO_2056_TX1, 0);
write_radio_reg(pi,
RADIO_2056_TX_PADG_BOOST_TUNE |
RADIO_2056_TX1, 0);
write_radio_reg(pi,
RADIO_2056_TX_PGAA_BOOST_TUNE |
RADIO_2056_TX1, 0);
write_radio_reg(pi,
RADIO_2056_TX_PGAG_BOOST_TUNE |
RADIO_2056_TX1, 0);
mod_radio_reg(pi,
RADIO_2056_TX_MIXA_BOOST_TUNE |
RADIO_2056_TX1, 0xf0, 0);
write_radio_reg(pi,
RADIO_2056_TX_MIXG_BOOST_TUNE |
RADIO_2056_TX1, 0);
pi->radio_is_on = false;
}
if (NREV_GE(pi->pubpi.phy_rev, 8)) {
and_phy_reg(pi, 0x78, ~RFCC_CHIP0_PU);
pi->radio_is_on = false;
}
}
}
static bool
wlc_phy_chan2freq_nphy(struct brcms_phy *pi, uint channel, int *f,
const struct chan_info_nphy_radio2057 **t0,
const struct chan_info_nphy_radio205x **t1,
const struct chan_info_nphy_radio2057_rev5 **t2,
const struct chan_info_nphy_2055 **t3)
{
uint i;
const struct chan_info_nphy_radio2057 *chan_info_tbl_p_0 = NULL;
const struct chan_info_nphy_radio205x *chan_info_tbl_p_1 = NULL;
const struct chan_info_nphy_radio2057_rev5 *chan_info_tbl_p_2 = NULL;
u32 tbl_len = 0;
int freq = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (NREV_IS(pi->pubpi.phy_rev, 7)) {
chan_info_tbl_p_0 = chan_info_nphyrev7_2057_rev4;
tbl_len = ARRAY_SIZE(chan_info_nphyrev7_2057_rev4);
} else if (NREV_IS(pi->pubpi.phy_rev, 8)
|| NREV_IS(pi->pubpi.phy_rev, 9)) {
switch (pi->pubpi.radiorev) {
case 5:
if (pi->pubpi.radiover == 0x0) {
chan_info_tbl_p_2 =
chan_info_nphyrev8_2057_rev5;
tbl_len = ARRAY_SIZE(
chan_info_nphyrev8_2057_rev5);
} else if (pi->pubpi.radiover == 0x1) {
chan_info_tbl_p_2 =
chan_info_nphyrev9_2057_rev5v1;
tbl_len = ARRAY_SIZE(
chan_info_nphyrev9_2057_rev5v1);
}
break;
case 7:
chan_info_tbl_p_0 =
chan_info_nphyrev8_2057_rev7;
tbl_len = ARRAY_SIZE(
chan_info_nphyrev8_2057_rev7);
break;
case 8:
chan_info_tbl_p_0 =
chan_info_nphyrev8_2057_rev8;
tbl_len = ARRAY_SIZE(
chan_info_nphyrev8_2057_rev8);
break;
default:
break;
}
} else if (NREV_IS(pi->pubpi.phy_rev, 16)) {
chan_info_tbl_p_0 = chan_info_nphyrev8_2057_rev8;
tbl_len = ARRAY_SIZE(chan_info_nphyrev8_2057_rev8);
} else {
goto fail;
}
for (i = 0; i < tbl_len; i++) {
if (pi->pubpi.radiorev == 5) {
if (chan_info_tbl_p_2[i].chan == channel)
break;
} else {
if (chan_info_tbl_p_0[i].chan == channel)
break;
}
}
if (i >= tbl_len)
goto fail;
if (pi->pubpi.radiorev == 5) {
*t2 = &chan_info_tbl_p_2[i];
freq = chan_info_tbl_p_2[i].freq;
} else {
*t0 = &chan_info_tbl_p_0[i];
freq = chan_info_tbl_p_0[i].freq;
}
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (NREV_IS(pi->pubpi.phy_rev, 3)) {
chan_info_tbl_p_1 = chan_info_nphyrev3_2056;
tbl_len = ARRAY_SIZE(chan_info_nphyrev3_2056);
} else if (NREV_IS(pi->pubpi.phy_rev, 4)) {
chan_info_tbl_p_1 = chan_info_nphyrev4_2056_A1;
tbl_len = ARRAY_SIZE(chan_info_nphyrev4_2056_A1);
} else if (NREV_IS(pi->pubpi.phy_rev, 5)
|| NREV_IS(pi->pubpi.phy_rev, 6)) {
switch (pi->pubpi.radiorev) {
case 5:
chan_info_tbl_p_1 = chan_info_nphyrev5_2056v5;
tbl_len = ARRAY_SIZE(chan_info_nphyrev5_2056v5);
break;
case 6:
chan_info_tbl_p_1 = chan_info_nphyrev6_2056v6;
tbl_len = ARRAY_SIZE(chan_info_nphyrev6_2056v6);
break;
case 7:
case 9:
chan_info_tbl_p_1 = chan_info_nphyrev5n6_2056v7;
tbl_len =
ARRAY_SIZE(chan_info_nphyrev5n6_2056v7);
break;
case 8:
chan_info_tbl_p_1 = chan_info_nphyrev6_2056v8;
tbl_len = ARRAY_SIZE(chan_info_nphyrev6_2056v8);
break;
case 11:
chan_info_tbl_p_1 = chan_info_nphyrev6_2056v11;
tbl_len = ARRAY_SIZE(
chan_info_nphyrev6_2056v11);
break;
default:
break;
}
}
for (i = 0; i < tbl_len; i++) {
if (chan_info_tbl_p_1[i].chan == channel)
break;
}
if (i >= tbl_len)
goto fail;
*t1 = &chan_info_tbl_p_1[i];
freq = chan_info_tbl_p_1[i].freq;
} else {
for (i = 0; i < ARRAY_SIZE(chan_info_nphy_2055); i++)
if (chan_info_nphy_2055[i].chan == channel)
break;
if (i >= ARRAY_SIZE(chan_info_nphy_2055))
goto fail;
*t3 = &chan_info_nphy_2055[i];
freq = chan_info_nphy_2055[i].freq;
}
*f = freq;
return true;
fail:
*f = WL_CHAN_FREQ_RANGE_2G;
return false;
}
u8 wlc_phy_get_chan_freq_range_nphy(struct brcms_phy *pi, uint channel)
{
int freq;
const struct chan_info_nphy_radio2057 *t0 = NULL;
const struct chan_info_nphy_radio205x *t1 = NULL;
const struct chan_info_nphy_radio2057_rev5 *t2 = NULL;
const struct chan_info_nphy_2055 *t3 = NULL;
if (channel == 0)
channel = CHSPEC_CHANNEL(pi->radio_chanspec);
wlc_phy_chan2freq_nphy(pi, channel, &freq, &t0, &t1, &t2, &t3);
if (CHSPEC_IS2G(pi->radio_chanspec))
return WL_CHAN_FREQ_RANGE_2G;
if ((freq >= BASE_LOW_5G_CHAN) && (freq < BASE_MID_5G_CHAN))
return WL_CHAN_FREQ_RANGE_5GL;
else if ((freq >= BASE_MID_5G_CHAN) && (freq < BASE_HIGH_5G_CHAN))
return WL_CHAN_FREQ_RANGE_5GM;
else
return WL_CHAN_FREQ_RANGE_5GH;
}
static void
wlc_phy_chanspec_radio2055_setup(struct brcms_phy *pi,
const struct chan_info_nphy_2055 *ci)
{
write_radio_reg(pi, RADIO_2055_PLL_REF, ci->RF_pll_ref);
write_radio_reg(pi, RADIO_2055_RF_PLL_MOD0, ci->RF_rf_pll_mod0);
write_radio_reg(pi, RADIO_2055_RF_PLL_MOD1, ci->RF_rf_pll_mod1);
write_radio_reg(pi, RADIO_2055_VCO_CAP_TAIL, ci->RF_vco_cap_tail);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_VCO_CAL1, ci->RF_vco_cal1);
write_radio_reg(pi, RADIO_2055_VCO_CAL2, ci->RF_vco_cal2);
write_radio_reg(pi, RADIO_2055_PLL_LF_C1, ci->RF_pll_lf_c1);
write_radio_reg(pi, RADIO_2055_PLL_LF_R1, ci->RF_pll_lf_r1);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_PLL_LF_C2, ci->RF_pll_lf_c2);
write_radio_reg(pi, RADIO_2055_LGBUF_CEN_BUF, ci->RF_lgbuf_cen_buf);
write_radio_reg(pi, RADIO_2055_LGEN_TUNE1, ci->RF_lgen_tune1);
write_radio_reg(pi, RADIO_2055_LGEN_TUNE2, ci->RF_lgen_tune2);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_CORE1_LGBUF_A_TUNE,
ci->RF_core1_lgbuf_a_tune);
write_radio_reg(pi, RADIO_2055_CORE1_LGBUF_G_TUNE,
ci->RF_core1_lgbuf_g_tune);
write_radio_reg(pi, RADIO_2055_CORE1_RXRF_REG1, ci->RF_core1_rxrf_reg1);
write_radio_reg(pi, RADIO_2055_CORE1_TX_PGA_PAD_TN,
ci->RF_core1_tx_pga_pad_tn);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_CORE1_TX_MX_BGTRIM,
ci->RF_core1_tx_mx_bgtrim);
write_radio_reg(pi, RADIO_2055_CORE2_LGBUF_A_TUNE,
ci->RF_core2_lgbuf_a_tune);
write_radio_reg(pi, RADIO_2055_CORE2_LGBUF_G_TUNE,
ci->RF_core2_lgbuf_g_tune);
write_radio_reg(pi, RADIO_2055_CORE2_RXRF_REG1, ci->RF_core2_rxrf_reg1);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_CORE2_TX_PGA_PAD_TN,
ci->RF_core2_tx_pga_pad_tn);
write_radio_reg(pi, RADIO_2055_CORE2_TX_MX_BGTRIM,
ci->RF_core2_tx_mx_bgtrim);
udelay(50);
write_radio_reg(pi, RADIO_2055_VCO_CAL10, 0x05);
write_radio_reg(pi, RADIO_2055_VCO_CAL10, 0x45);
BRCMS_PHY_WAR_PR51571(pi);
write_radio_reg(pi, RADIO_2055_VCO_CAL10, 0x65);
udelay(300);
}
static void
wlc_phy_chanspec_radio2056_setup(struct brcms_phy *pi,
const struct chan_info_nphy_radio205x *ci)
{
const struct radio_regs *regs_SYN_2056_ptr = NULL;
write_radio_reg(pi,
RADIO_2056_SYN_PLL_VCOCAL1 | RADIO_2056_SYN,
ci->RF_SYN_pll_vcocal1);
write_radio_reg(pi, RADIO_2056_SYN_PLL_VCOCAL2 | RADIO_2056_SYN,
ci->RF_SYN_pll_vcocal2);
write_radio_reg(pi, RADIO_2056_SYN_PLL_REFDIV | RADIO_2056_SYN,
ci->RF_SYN_pll_refdiv);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MMD2 | RADIO_2056_SYN,
ci->RF_SYN_pll_mmd2);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MMD1 | RADIO_2056_SYN,
ci->RF_SYN_pll_mmd1);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER1 | RADIO_2056_SYN,
ci->RF_SYN_pll_loopfilter1);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER2 | RADIO_2056_SYN,
ci->RF_SYN_pll_loopfilter2);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER3 | RADIO_2056_SYN,
ci->RF_SYN_pll_loopfilter3);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER4 | RADIO_2056_SYN,
ci->RF_SYN_pll_loopfilter4);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER5 | RADIO_2056_SYN,
ci->RF_SYN_pll_loopfilter5);
write_radio_reg(pi, RADIO_2056_SYN_RESERVED_ADDR27 | RADIO_2056_SYN,
ci->RF_SYN_reserved_addr27);
write_radio_reg(pi, RADIO_2056_SYN_RESERVED_ADDR28 | RADIO_2056_SYN,
ci->RF_SYN_reserved_addr28);
write_radio_reg(pi, RADIO_2056_SYN_RESERVED_ADDR29 | RADIO_2056_SYN,
ci->RF_SYN_reserved_addr29);
write_radio_reg(pi, RADIO_2056_SYN_LOGEN_VCOBUF1 | RADIO_2056_SYN,
ci->RF_SYN_logen_VCOBUF1);
write_radio_reg(pi, RADIO_2056_SYN_LOGEN_MIXER2 | RADIO_2056_SYN,
ci->RF_SYN_logen_MIXER2);
write_radio_reg(pi, RADIO_2056_SYN_LOGEN_BUF3 | RADIO_2056_SYN,
ci->RF_SYN_logen_BUF3);
write_radio_reg(pi, RADIO_2056_SYN_LOGEN_BUF4 | RADIO_2056_SYN,
ci->RF_SYN_logen_BUF4);
write_radio_reg(pi,
RADIO_2056_RX_LNAA_TUNE | RADIO_2056_RX0,
ci->RF_RX0_lnaa_tune);
write_radio_reg(pi, RADIO_2056_RX_LNAG_TUNE | RADIO_2056_RX0,
ci->RF_RX0_lnag_tune);
write_radio_reg(pi, RADIO_2056_TX_INTPAA_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_intpaa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_INTPAG_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_intpag_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PADA_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_pada_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PADG_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_padg_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PGAA_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_pgaa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PGAG_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_pgag_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_MIXA_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_mixa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_MIXG_BOOST_TUNE | RADIO_2056_TX0,
ci->RF_TX0_mixg_boost_tune);
write_radio_reg(pi,
RADIO_2056_RX_LNAA_TUNE | RADIO_2056_RX1,
ci->RF_RX1_lnaa_tune);
write_radio_reg(pi, RADIO_2056_RX_LNAG_TUNE | RADIO_2056_RX1,
ci->RF_RX1_lnag_tune);
write_radio_reg(pi, RADIO_2056_TX_INTPAA_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_intpaa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_INTPAG_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_intpag_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PADA_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_pada_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PADG_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_padg_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PGAA_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_pgaa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_PGAG_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_pgag_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_MIXA_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_mixa_boost_tune);
write_radio_reg(pi, RADIO_2056_TX_MIXG_BOOST_TUNE | RADIO_2056_TX1,
ci->RF_TX1_mixg_boost_tune);
if (NREV_IS(pi->pubpi.phy_rev, 3))
regs_SYN_2056_ptr = regs_SYN_2056;
else if (NREV_IS(pi->pubpi.phy_rev, 4))
regs_SYN_2056_ptr = regs_SYN_2056_A1;
else {
switch (pi->pubpi.radiorev) {
case 5:
regs_SYN_2056_ptr = regs_SYN_2056_rev5;
break;
case 6:
regs_SYN_2056_ptr = regs_SYN_2056_rev6;
break;
case 7:
case 9:
regs_SYN_2056_ptr = regs_SYN_2056_rev7;
break;
case 8:
regs_SYN_2056_ptr = regs_SYN_2056_rev8;
break;
case 11:
regs_SYN_2056_ptr = regs_SYN_2056_rev11;
break;
}
}
if (CHSPEC_IS2G(pi->radio_chanspec))
write_radio_reg(pi, RADIO_2056_SYN_PLL_CP2 |
RADIO_2056_SYN,
(u16) regs_SYN_2056_ptr[0x49 - 2].init_g);
else
write_radio_reg(pi, RADIO_2056_SYN_PLL_CP2 |
RADIO_2056_SYN,
(u16) regs_SYN_2056_ptr[0x49 - 2].init_a);
if (pi->sh->boardflags2 & BFL2_GPLL_WAR) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER1 |
RADIO_2056_SYN, 0x1f);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER2 |
RADIO_2056_SYN, 0x1f);
if ((pi->sh->chip == BCMA_CHIP_ID_BCM4716) ||
(pi->sh->chip == BCMA_CHIP_ID_BCM47162)) {
write_radio_reg(pi,
RADIO_2056_SYN_PLL_LOOPFILTER4 |
RADIO_2056_SYN, 0x14);
write_radio_reg(pi,
RADIO_2056_SYN_PLL_CP2 |
RADIO_2056_SYN, 0x00);
} else {
write_radio_reg(pi,
RADIO_2056_SYN_PLL_LOOPFILTER4 |
RADIO_2056_SYN, 0xb);
write_radio_reg(pi,
RADIO_2056_SYN_PLL_CP2 |
RADIO_2056_SYN, 0x14);
}
}
}
if ((pi->sh->boardflags2 & BFL2_GPLL_WAR2) &&
(CHSPEC_IS2G(pi->radio_chanspec))) {
write_radio_reg(pi,
RADIO_2056_SYN_PLL_LOOPFILTER1 | RADIO_2056_SYN,
0x1f);
write_radio_reg(pi,
RADIO_2056_SYN_PLL_LOOPFILTER2 | RADIO_2056_SYN,
0x1f);
write_radio_reg(pi,
RADIO_2056_SYN_PLL_LOOPFILTER4 | RADIO_2056_SYN,
0xb);
write_radio_reg(pi, RADIO_2056_SYN_PLL_CP2 | RADIO_2056_SYN,
0x20);
}
if (pi->sh->boardflags2 & BFL2_APLL_WAR) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER1 |
RADIO_2056_SYN, 0x1f);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER2 |
RADIO_2056_SYN, 0x1f);
write_radio_reg(pi, RADIO_2056_SYN_PLL_LOOPFILTER4 |
RADIO_2056_SYN, 0x5);
write_radio_reg(pi, RADIO_2056_SYN_PLL_CP2 |
RADIO_2056_SYN, 0xc);
}
}
if (PHY_IPA(pi) && CHSPEC_IS2G(pi->radio_chanspec)) {
u16 pag_boost_tune;
u16 padg_boost_tune;
u16 pgag_boost_tune;
u16 mixg_boost_tune;
u16 bias, cascbias;
uint core;
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (NREV_GE(pi->pubpi.phy_rev, 5)) {
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PADG_IDAC, 0xcc);
if ((pi->sh->chip == BCMA_CHIP_ID_BCM4716) ||
(pi->sh->chip == BCMA_CHIP_ID_BCM47162)) {
bias = 0x40;
cascbias = 0x45;
pag_boost_tune = 0x5;
pgag_boost_tune = 0x33;
padg_boost_tune = 0x77;
mixg_boost_tune = 0x55;
} else {
bias = 0x25;
cascbias = 0x20;
if ((pi->sh->chip == BCMA_CHIP_ID_BCM43224 ||
pi->sh->chip == BCMA_CHIP_ID_BCM43225) &&
pi->sh->chippkg == BCMA_PKG_ID_BCM43224_FAB_SMIC) {
bias = 0x2a;
cascbias = 0x38;
}
pag_boost_tune = 0x4;
pgag_boost_tune = 0x03;
padg_boost_tune = 0x77;
mixg_boost_tune = 0x65;
}
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_IMAIN_STAT, bias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_IAUX_STAT, bias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_CASCBIAS, cascbias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_BOOST_TUNE,
pag_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PGAG_BOOST_TUNE,
pgag_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PADG_BOOST_TUNE,
padg_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
MIXG_BOOST_TUNE,
mixg_boost_tune);
} else {
bias = (pi->bw == WL_CHANSPEC_BW_40) ?
0x40 : 0x20;
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_IMAIN_STAT, bias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_IAUX_STAT, bias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_CASCBIAS, 0x30);
}
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core, PA_SPARE1,
0xee);
}
}
if (PHY_IPA(pi) && NREV_IS(pi->pubpi.phy_rev, 6)
&& CHSPEC_IS5G(pi->radio_chanspec)) {
u16 paa_boost_tune;
u16 pada_boost_tune;
u16 pgaa_boost_tune;
u16 mixa_boost_tune;
u16 freq, pabias, cascbias;
uint core;
freq = CHAN5G_FREQ(CHSPEC_CHANNEL(pi->radio_chanspec));
if (freq < 5150) {
paa_boost_tune = 0xa;
pada_boost_tune = 0x77;
pgaa_boost_tune = 0xf;
mixa_boost_tune = 0xf;
} else if (freq < 5340) {
paa_boost_tune = 0x8;
pada_boost_tune = 0x77;
pgaa_boost_tune = 0xfb;
mixa_boost_tune = 0xf;
} else if (freq < 5650) {
paa_boost_tune = 0x0;
pada_boost_tune = 0x77;
pgaa_boost_tune = 0xb;
mixa_boost_tune = 0xf;
} else {
paa_boost_tune = 0x0;
pada_boost_tune = 0x77;
if (freq != 5825)
pgaa_boost_tune = -(int)(freq - 18) / 36 + 168;
else
pgaa_boost_tune = 6;
mixa_boost_tune = 0xf;
}
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_BOOST_TUNE, paa_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PADA_BOOST_TUNE, pada_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PGAA_BOOST_TUNE, pgaa_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
MIXA_BOOST_TUNE, mixa_boost_tune);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
TXSPARE1, 0x30);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PA_SPARE2, 0xee);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
PADA_CASCBIAS, 0x3);
cascbias = 0x30;
if ((pi->sh->chip == BCMA_CHIP_ID_BCM43224 ||
pi->sh->chip == BCMA_CHIP_ID_BCM43225) &&
pi->sh->chippkg == BCMA_PKG_ID_BCM43224_FAB_SMIC)
cascbias = 0x35;
pabias = (pi->phy_pabias == 0) ? 0x30 : pi->phy_pabias;
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_IAUX_STAT, pabias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_IMAIN_STAT, pabias);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_CASCBIAS, cascbias);
}
}
udelay(50);
wlc_phy_radio205x_vcocal_nphy(pi);
}
void wlc_phy_radio205x_vcocal_nphy(struct brcms_phy *pi)
{
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_EN, 0x01, 0x0);
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_CAL_RESETN, 0x04, 0x0);
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_CAL_RESETN, 0x04,
(1 << 2));
mod_radio_reg(pi, RADIO_2057_RFPLL_MISC_EN, 0x01, 0x01);
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_radio_reg(pi, RADIO_2056_SYN_PLL_VCOCAL12, 0x0);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST3, 0x38);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST3, 0x18);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST3, 0x38);
write_radio_reg(pi, RADIO_2056_SYN_PLL_MAST3, 0x39);
}
udelay(300);
}
static void
wlc_phy_chanspec_radio2057_setup(
struct brcms_phy *pi,
const struct chan_info_nphy_radio2057 *ci,
const struct chan_info_nphy_radio2057_rev5 *
ci2)
{
int coreNum;
u16 txmix2g_tune_boost_pu = 0;
u16 pad2g_tune_pus = 0;
if (pi->pubpi.radiorev == 5) {
write_radio_reg(pi,
RADIO_2057_VCOCAL_COUNTVAL0,
ci2->RF_vcocal_countval0);
write_radio_reg(pi, RADIO_2057_VCOCAL_COUNTVAL1,
ci2->RF_vcocal_countval1);
write_radio_reg(pi, RADIO_2057_RFPLL_REFMASTER_SPAREXTALSIZE,
ci2->RF_rfpll_refmaster_sparextalsize);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
ci2->RF_rfpll_loopfilter_r1);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
ci2->RF_rfpll_loopfilter_c2);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
ci2->RF_rfpll_loopfilter_c1);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC,
ci2->RF_cp_kpd_idac);
write_radio_reg(pi, RADIO_2057_RFPLL_MMD0, ci2->RF_rfpll_mmd0);
write_radio_reg(pi, RADIO_2057_RFPLL_MMD1, ci2->RF_rfpll_mmd1);
write_radio_reg(pi,
RADIO_2057_VCOBUF_TUNE, ci2->RF_vcobuf_tune);
write_radio_reg(pi,
RADIO_2057_LOGEN_MX2G_TUNE,
ci2->RF_logen_mx2g_tune);
write_radio_reg(pi, RADIO_2057_LOGEN_INDBUF2G_TUNE,
ci2->RF_logen_indbuf2g_tune);
write_radio_reg(pi,
RADIO_2057_TXMIX2G_TUNE_BOOST_PU_CORE0,
ci2->RF_txmix2g_tune_boost_pu_core0);
write_radio_reg(pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE0,
ci2->RF_pad2g_tune_pus_core0);
write_radio_reg(pi, RADIO_2057_LNA2G_TUNE_CORE0,
ci2->RF_lna2g_tune_core0);
write_radio_reg(pi,
RADIO_2057_TXMIX2G_TUNE_BOOST_PU_CORE1,
ci2->RF_txmix2g_tune_boost_pu_core1);
write_radio_reg(pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE1,
ci2->RF_pad2g_tune_pus_core1);
write_radio_reg(pi, RADIO_2057_LNA2G_TUNE_CORE1,
ci2->RF_lna2g_tune_core1);
} else {
write_radio_reg(pi,
RADIO_2057_VCOCAL_COUNTVAL0,
ci->RF_vcocal_countval0);
write_radio_reg(pi, RADIO_2057_VCOCAL_COUNTVAL1,
ci->RF_vcocal_countval1);
write_radio_reg(pi, RADIO_2057_RFPLL_REFMASTER_SPAREXTALSIZE,
ci->RF_rfpll_refmaster_sparextalsize);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
ci->RF_rfpll_loopfilter_r1);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
ci->RF_rfpll_loopfilter_c2);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
ci->RF_rfpll_loopfilter_c1);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC, ci->RF_cp_kpd_idac);
write_radio_reg(pi, RADIO_2057_RFPLL_MMD0, ci->RF_rfpll_mmd0);
write_radio_reg(pi, RADIO_2057_RFPLL_MMD1, ci->RF_rfpll_mmd1);
write_radio_reg(pi, RADIO_2057_VCOBUF_TUNE, ci->RF_vcobuf_tune);
write_radio_reg(pi,
RADIO_2057_LOGEN_MX2G_TUNE,
ci->RF_logen_mx2g_tune);
write_radio_reg(pi, RADIO_2057_LOGEN_MX5G_TUNE,
ci->RF_logen_mx5g_tune);
write_radio_reg(pi, RADIO_2057_LOGEN_INDBUF2G_TUNE,
ci->RF_logen_indbuf2g_tune);
write_radio_reg(pi, RADIO_2057_LOGEN_INDBUF5G_TUNE,
ci->RF_logen_indbuf5g_tune);
write_radio_reg(pi,
RADIO_2057_TXMIX2G_TUNE_BOOST_PU_CORE0,
ci->RF_txmix2g_tune_boost_pu_core0);
write_radio_reg(pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE0,
ci->RF_pad2g_tune_pus_core0);
write_radio_reg(pi, RADIO_2057_PGA_BOOST_TUNE_CORE0,
ci->RF_pga_boost_tune_core0);
write_radio_reg(pi, RADIO_2057_TXMIX5G_BOOST_TUNE_CORE0,
ci->RF_txmix5g_boost_tune_core0);
write_radio_reg(pi, RADIO_2057_PAD5G_TUNE_MISC_PUS_CORE0,
ci->RF_pad5g_tune_misc_pus_core0);
write_radio_reg(pi, RADIO_2057_LNA2G_TUNE_CORE0,
ci->RF_lna2g_tune_core0);
write_radio_reg(pi, RADIO_2057_LNA5G_TUNE_CORE0,
ci->RF_lna5g_tune_core0);
write_radio_reg(pi,
RADIO_2057_TXMIX2G_TUNE_BOOST_PU_CORE1,
ci->RF_txmix2g_tune_boost_pu_core1);
write_radio_reg(pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE1,
ci->RF_pad2g_tune_pus_core1);
write_radio_reg(pi, RADIO_2057_PGA_BOOST_TUNE_CORE1,
ci->RF_pga_boost_tune_core1);
write_radio_reg(pi, RADIO_2057_TXMIX5G_BOOST_TUNE_CORE1,
ci->RF_txmix5g_boost_tune_core1);
write_radio_reg(pi, RADIO_2057_PAD5G_TUNE_MISC_PUS_CORE1,
ci->RF_pad5g_tune_misc_pus_core1);
write_radio_reg(pi, RADIO_2057_LNA2G_TUNE_CORE1,
ci->RF_lna2g_tune_core1);
write_radio_reg(pi, RADIO_2057_LNA5G_TUNE_CORE1,
ci->RF_lna5g_tune_core1);
}
if ((pi->pubpi.radiorev <= 4) || (pi->pubpi.radiorev == 6)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
0x3f);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC, 0x3f);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
0x8);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
0x8);
} else {
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
0x1f);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC, 0x3f);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
0x8);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
0x8);
}
} else if ((pi->pubpi.radiorev == 5) || (pi->pubpi.radiorev == 7) ||
(pi->pubpi.radiorev == 8)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
0x1b);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC, 0x30);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
0xa);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
0xa);
} else {
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_R1,
0x1f);
write_radio_reg(pi, RADIO_2057_CP_KPD_IDAC, 0x3f);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C1,
0x8);
write_radio_reg(pi, RADIO_2057_RFPLL_LOOPFILTER_C2,
0x8);
}
}
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (PHY_IPA(pi)) {
if (pi->pubpi.radiorev == 3)
txmix2g_tune_boost_pu = 0x6b;
if (pi->pubpi.radiorev == 5)
pad2g_tune_pus = 0x73;
} else {
if (pi->pubpi.radiorev != 5) {
pad2g_tune_pus = 0x3;
txmix2g_tune_boost_pu = 0x61;
}
}
for (coreNum = 0; coreNum <= 1; coreNum++) {
if (txmix2g_tune_boost_pu != 0)
WRITE_RADIO_REG4(pi, RADIO_2057, CORE, coreNum,
TXMIX2G_TUNE_BOOST_PU,
txmix2g_tune_boost_pu);
if (pad2g_tune_pus != 0)
WRITE_RADIO_REG4(pi, RADIO_2057, CORE, coreNum,
PAD2G_TUNE_PUS,
pad2g_tune_pus);
}
}
udelay(50);
wlc_phy_radio205x_vcocal_nphy(pi);
}
static void
wlc_phy_chanspec_nphy_setup(struct brcms_phy *pi, u16 chanspec,
const struct nphy_sfo_cfg *ci)
{
u16 val;
val = read_phy_reg(pi, 0x09) & NPHY_BandControl_currentBand;
if (CHSPEC_IS5G(chanspec) && !val) {
val = bcma_read16(pi->d11core, D11REGOFFS(psm_phy_hdr_param));
bcma_write16(pi->d11core, D11REGOFFS(psm_phy_hdr_param),
(val | MAC_PHY_FORCE_CLK));
or_phy_reg(pi, (NPHY_TO_BPHY_OFF + BPHY_BB_CONFIG),
(BBCFG_RESETCCA | BBCFG_RESETRX));
bcma_write16(pi->d11core, D11REGOFFS(psm_phy_hdr_param), val);
or_phy_reg(pi, 0x09, NPHY_BandControl_currentBand);
} else if (!CHSPEC_IS5G(chanspec) && val) {
and_phy_reg(pi, 0x09, ~NPHY_BandControl_currentBand);
val = bcma_read16(pi->d11core, D11REGOFFS(psm_phy_hdr_param));
bcma_write16(pi->d11core, D11REGOFFS(psm_phy_hdr_param),
(val | MAC_PHY_FORCE_CLK));
and_phy_reg(pi, (NPHY_TO_BPHY_OFF + BPHY_BB_CONFIG),
(u16) (~(BBCFG_RESETCCA | BBCFG_RESETRX)));
bcma_write16(pi->d11core, D11REGOFFS(psm_phy_hdr_param), val);
}
write_phy_reg(pi, 0x1ce, ci->PHY_BW1a);
write_phy_reg(pi, 0x1cf, ci->PHY_BW2);
write_phy_reg(pi, 0x1d0, ci->PHY_BW3);
write_phy_reg(pi, 0x1d1, ci->PHY_BW4);
write_phy_reg(pi, 0x1d2, ci->PHY_BW5);
write_phy_reg(pi, 0x1d3, ci->PHY_BW6);
if (CHSPEC_CHANNEL(pi->radio_chanspec) == 14) {
wlc_phy_classifier_nphy(pi, NPHY_ClassifierCtrl_ofdm_en, 0);
or_phy_reg(pi, NPHY_TO_BPHY_OFF + BPHY_TEST, 0x800);
} else {
wlc_phy_classifier_nphy(pi, NPHY_ClassifierCtrl_ofdm_en,
NPHY_ClassifierCtrl_ofdm_en);
if (CHSPEC_IS2G(chanspec))
and_phy_reg(pi, NPHY_TO_BPHY_OFF + BPHY_TEST, ~0x840);
}
if (pi->nphy_txpwrctrl == PHY_TPC_HW_OFF)
wlc_phy_txpwr_fixpower_nphy(pi);
if (NREV_LT(pi->pubpi.phy_rev, 3))
wlc_phy_adjust_lnagaintbl_nphy(pi);
wlc_phy_txlpfbw_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 3)
&& (pi->phy_spuravoid != SPURAVOID_DISABLE)) {
u8 spuravoid = 0;
val = CHSPEC_CHANNEL(chanspec);
if (!CHSPEC_IS40(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if ((val == 13) || (val == 14) || (val == 153))
spuravoid = 1;
} else if (((val >= 5) && (val <= 8)) || (val == 13)
|| (val == 14)) {
spuravoid = 1;
}
} else if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (val == 54)
spuravoid = 1;
} else if (pi->nphy_aband_spurwar_en &&
((val == 38) || (val == 102) || (val == 118))) {
if ((pi->sh->chip == BCMA_CHIP_ID_BCM4716)
&& (pi->sh->chippkg == BCMA_PKG_ID_BCM4717)) {
spuravoid = 0;
} else {
spuravoid = 1;
}
}
if (pi->phy_spuravoid == SPURAVOID_FORCEON)
spuravoid = 1;
if ((pi->sh->chip == BCMA_CHIP_ID_BCM4716) ||
(pi->sh->chip == BCMA_CHIP_ID_BCM43225)) {
bcma_pmu_spuravoid_pllupdate(&pi->d11core->bus->drv_cc,
spuravoid);
} else {
wlapi_bmac_core_phypll_ctl(pi->sh->physhim, false);
bcma_pmu_spuravoid_pllupdate(&pi->d11core->bus->drv_cc,
spuravoid);
wlapi_bmac_core_phypll_ctl(pi->sh->physhim, true);
}
if ((pi->sh->chip == BCMA_CHIP_ID_BCM43224) ||
(pi->sh->chip == BCMA_CHIP_ID_BCM43225)) {
if (spuravoid == 1) {
bcma_write16(pi->d11core,
D11REGOFFS(tsf_clk_frac_l),
0x5341);
bcma_write16(pi->d11core,
D11REGOFFS(tsf_clk_frac_h), 0x8);
} else {
bcma_write16(pi->d11core,
D11REGOFFS(tsf_clk_frac_l),
0x8889);
bcma_write16(pi->d11core,
D11REGOFFS(tsf_clk_frac_h), 0x8);
}
}
if (!((pi->sh->chip == BCMA_CHIP_ID_BCM4716) ||
(pi->sh->chip == BCMA_CHIP_ID_BCM47162)))
wlapi_bmac_core_phypll_reset(pi->sh->physhim);
mod_phy_reg(pi, 0x01, (0x1 << 15),
((spuravoid > 0) ? (0x1 << 15) : 0));
wlc_phy_resetcca_nphy(pi);
pi->phy_isspuravoid = (spuravoid > 0);
}
if (NREV_LT(pi->pubpi.phy_rev, 7))
write_phy_reg(pi, 0x17e, 0x3830);
wlc_phy_spurwar_nphy(pi);
}
void wlc_phy_chanspec_set_nphy(struct brcms_phy *pi, u16 chanspec)
{
int freq;
const struct chan_info_nphy_radio2057 *t0 = NULL;
const struct chan_info_nphy_radio205x *t1 = NULL;
const struct chan_info_nphy_radio2057_rev5 *t2 = NULL;
const struct chan_info_nphy_2055 *t3 = NULL;
if (!wlc_phy_chan2freq_nphy
(pi, CHSPEC_CHANNEL(chanspec), &freq, &t0, &t1, &t2, &t3))
return;
wlc_phy_chanspec_radio_set((struct brcms_phy_pub *) pi, chanspec);
if (CHSPEC_BW(chanspec) != pi->bw)
wlapi_bmac_bw_set(pi->sh->physhim, CHSPEC_BW(chanspec));
if (CHSPEC_IS40(chanspec)) {
if (CHSPEC_SB_UPPER(chanspec)) {
or_phy_reg(pi, 0xa0, BPHY_BAND_SEL_UP20);
if (NREV_GE(pi->pubpi.phy_rev, 7))
or_phy_reg(pi, 0x310, PRIM_SEL_UP20);
} else {
and_phy_reg(pi, 0xa0, ~BPHY_BAND_SEL_UP20);
if (NREV_GE(pi->pubpi.phy_rev, 7))
and_phy_reg(pi, 0x310,
(~PRIM_SEL_UP20 & 0xffff));
}
}
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if ((pi->pubpi.radiorev <= 4)
|| (pi->pubpi.radiorev == 6)) {
mod_radio_reg(pi, RADIO_2057_TIA_CONFIG_CORE0,
0x2,
(CHSPEC_IS5G(chanspec) ? (1 << 1)
: 0));
mod_radio_reg(pi, RADIO_2057_TIA_CONFIG_CORE1,
0x2,
(CHSPEC_IS5G(chanspec) ? (1 << 1)
: 0));
}
wlc_phy_chanspec_radio2057_setup(pi, t0, t2);
wlc_phy_chanspec_nphy_setup(pi, chanspec,
(pi->pubpi.radiorev == 5) ?
(const struct nphy_sfo_cfg *)&(t2->PHY_BW1a) :
(const struct nphy_sfo_cfg *)&(t0->PHY_BW1a));
} else {
mod_radio_reg(pi,
RADIO_2056_SYN_COM_CTRL | RADIO_2056_SYN,
0x4,
(CHSPEC_IS5G(chanspec) ? (0x1 << 2) : 0));
wlc_phy_chanspec_radio2056_setup(pi, t1);
wlc_phy_chanspec_nphy_setup(pi, chanspec,
(const struct nphy_sfo_cfg *) &(t1->PHY_BW1a));
}
} else {
mod_radio_reg(pi, RADIO_2055_MASTER_CNTRL1, 0x70,
(CHSPEC_IS5G(chanspec) ? (0x02 << 4)
: (0x05 << 4)));
wlc_phy_chanspec_radio2055_setup(pi, t3);
wlc_phy_chanspec_nphy_setup(pi, chanspec,
(const struct nphy_sfo_cfg *)
&(t3->PHY_BW1a));
}
}
void wlc_phy_antsel_init(struct brcms_phy_pub *ppi, bool lut_init)
{
struct brcms_phy *pi = (struct brcms_phy *) ppi;
u16 mask = 0xfc00;
u32 mc = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7))
return;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
u16 v0 = 0x211, v1 = 0x222, v2 = 0x144, v3 = 0x188;
if (!lut_init)
return;
if (pi->srom_fem2g.antswctrllut == 0) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x02, 16, &v0);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x03, 16, &v1);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x08, 16, &v2);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x0C, 16, &v3);
}
if (pi->srom_fem5g.antswctrllut == 0) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x12, 16, &v0);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x13, 16, &v1);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x18, 16, &v2);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_ANTSWCTRLLUT,
1, 0x1C, 16, &v3);
}
} else {
write_phy_reg(pi, 0xc8, 0x0);
write_phy_reg(pi, 0xc9, 0x0);
bcma_chipco_gpio_control(&pi->d11core->bus->drv_cc, mask, mask);
mc = bcma_read32(pi->d11core, D11REGOFFS(maccontrol));
mc &= ~MCTL_GPOUT_SEL_MASK;
bcma_write32(pi->d11core, D11REGOFFS(maccontrol), mc);
bcma_set16(pi->d11core, D11REGOFFS(psm_gpio_oe), mask);
bcma_mask16(pi->d11core, D11REGOFFS(psm_gpio_out), ~mask);
if (lut_init) {
write_phy_reg(pi, 0xf8, 0x02d8);
write_phy_reg(pi, 0xf9, 0x0301);
write_phy_reg(pi, 0xfa, 0x02d8);
write_phy_reg(pi, 0xfb, 0x0301);
}
}
}
u16 wlc_phy_classifier_nphy(struct brcms_phy *pi, u16 mask, u16 val)
{
u16 curr_ctl, new_ctl;
bool suspended = false;
if (D11REV_IS(pi->sh->corerev, 16)) {
suspended = (bcma_read32(pi->d11core, D11REGOFFS(maccontrol)) &
MCTL_EN_MAC) ? false : true;
if (!suspended)
wlapi_suspend_mac_and_wait(pi->sh->physhim);
}
curr_ctl = read_phy_reg(pi, 0xb0) & (0x7 << 0);
new_ctl = (curr_ctl & (~mask)) | (val & mask);
mod_phy_reg(pi, 0xb0, (0x7 << 0), new_ctl);
if (D11REV_IS(pi->sh->corerev, 16) && !suspended)
wlapi_enable_mac(pi->sh->physhim);
return new_ctl;
}
void wlc_phy_force_rfseq_nphy(struct brcms_phy *pi, u8 cmd)
{
u16 trigger_mask, status_mask;
u16 orig_RfseqCoreActv;
switch (cmd) {
case NPHY_RFSEQ_RX2TX:
trigger_mask = NPHY_RfseqTrigger_rx2tx;
status_mask = NPHY_RfseqStatus_rx2tx;
break;
case NPHY_RFSEQ_TX2RX:
trigger_mask = NPHY_RfseqTrigger_tx2rx;
status_mask = NPHY_RfseqStatus_tx2rx;
break;
case NPHY_RFSEQ_RESET2RX:
trigger_mask = NPHY_RfseqTrigger_reset2rx;
status_mask = NPHY_RfseqStatus_reset2rx;
break;
case NPHY_RFSEQ_UPDATEGAINH:
trigger_mask = NPHY_RfseqTrigger_updategainh;
status_mask = NPHY_RfseqStatus_updategainh;
break;
case NPHY_RFSEQ_UPDATEGAINL:
trigger_mask = NPHY_RfseqTrigger_updategainl;
status_mask = NPHY_RfseqStatus_updategainl;
break;
case NPHY_RFSEQ_UPDATEGAINU:
trigger_mask = NPHY_RfseqTrigger_updategainu;
status_mask = NPHY_RfseqStatus_updategainu;
break;
default:
return;
}
orig_RfseqCoreActv = read_phy_reg(pi, 0xa1);
or_phy_reg(pi, 0xa1,
(NPHY_RfseqMode_CoreActv_override |
NPHY_RfseqMode_Trigger_override));
or_phy_reg(pi, 0xa3, trigger_mask);
SPINWAIT((read_phy_reg(pi, 0xa4) & status_mask), 200000);
write_phy_reg(pi, 0xa1, orig_RfseqCoreActv);
WARN(read_phy_reg(pi, 0xa4) & status_mask, "HW error in rf");
}
static void
wlc_phy_rfctrl_override_1tomany_nphy(struct brcms_phy *pi, u16 cmd, u16 value,
u8 core_mask, u8 off)
{
u16 rfmxgain = 0, lpfgain = 0;
u16 tgain = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
switch (cmd) {
case NPHY_REV7_RfctrlOverride_cmd_rxrf_pu:
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 5),
value, core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 4), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 3), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
break;
case NPHY_REV7_RfctrlOverride_cmd_rx_pu:
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2),
value, core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 1), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 0), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 1), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 11), 0,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
break;
case NPHY_REV7_RfctrlOverride_cmd_tx_pu:
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2),
value, core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 1), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 0), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2), value,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 11), 1,
core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
break;
case NPHY_REV7_RfctrlOverride_cmd_rxgain:
rfmxgain = value & 0x000ff;
lpfgain = value & 0x0ff00;
lpfgain = lpfgain >> 8;
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 11),
rfmxgain, core_mask,
off,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x3 << 13),
lpfgain, core_mask,
off,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
break;
case NPHY_REV7_RfctrlOverride_cmd_txgain:
tgain = value & 0x7fff;
lpfgain = value & 0x8000;
lpfgain = lpfgain >> 14;
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 12),
tgain, core_mask, off,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 13),
lpfgain, core_mask,
off,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
break;
}
}
}
static void
wlc_phy_scale_offset_rssi_nphy(struct brcms_phy *pi, u16 scale, s8 offset,
u8 coresel, u8 rail, u8 rssi_type)
{
u16 valuetostuff;
offset = (offset > NPHY_RSSICAL_MAXREAD) ?
NPHY_RSSICAL_MAXREAD : offset;
offset = (offset < (-NPHY_RSSICAL_MAXREAD - 1)) ?
-NPHY_RSSICAL_MAXREAD - 1 : offset;
valuetostuff = ((scale & 0x3f) << 8) | (offset & 0x3f);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_NB))
write_phy_reg(pi, 0x1a6, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_NB))
write_phy_reg(pi, 0x1ac, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_NB))
write_phy_reg(pi, 0x1b2, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_NB))
write_phy_reg(pi, 0x1b8, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_W1))
write_phy_reg(pi, 0x1a4, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_W1))
write_phy_reg(pi, 0x1aa, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_W1))
write_phy_reg(pi, 0x1b0, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_W1))
write_phy_reg(pi, 0x1b6, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_W2))
write_phy_reg(pi, 0x1a5, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_W2))
write_phy_reg(pi, 0x1ab, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_W2))
write_phy_reg(pi, 0x1b1, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_W2))
write_phy_reg(pi, 0x1b7, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_TBD))
write_phy_reg(pi, 0x1a7, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_TBD))
write_phy_reg(pi, 0x1ad, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_TBD))
write_phy_reg(pi, 0x1b3, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_TBD))
write_phy_reg(pi, 0x1b9, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_IQ))
write_phy_reg(pi, 0x1a8, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_IQ))
write_phy_reg(pi, 0x1ae, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_I) && (rssi_type == NPHY_RSSI_SEL_IQ))
write_phy_reg(pi, 0x1b4, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rail == NPHY_RAIL_Q) && (rssi_type == NPHY_RSSI_SEL_IQ))
write_phy_reg(pi, 0x1ba, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rssi_type == NPHY_RSSI_SEL_TSSI_2G))
write_phy_reg(pi, 0x1a9, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rssi_type == NPHY_RSSI_SEL_TSSI_2G))
write_phy_reg(pi, 0x1b5, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE1) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rssi_type == NPHY_RSSI_SEL_TSSI_5G))
write_phy_reg(pi, 0x1af, valuetostuff);
if (((coresel == RADIO_MIMO_CORESEL_CORE2) ||
(coresel == RADIO_MIMO_CORESEL_ALLRX)) &&
(rssi_type == NPHY_RSSI_SEL_TSSI_5G))
write_phy_reg(pi, 0x1bb, valuetostuff);
}
static void brcms_phy_wr_tx_mux(struct brcms_phy *pi, u8 core)
{
if (PHY_IPA(pi)) {
if (NREV_GE(pi->pubpi.phy_rev, 7))
write_radio_reg(pi,
((core == PHY_CORE_0) ?
RADIO_2057_TX0_TX_SSI_MUX :
RADIO_2057_TX1_TX_SSI_MUX),
(CHSPEC_IS5G(pi->radio_chanspec) ?
0xc : 0xe));
else
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MUX |
((core == PHY_CORE_0) ?
RADIO_2056_TX0 : RADIO_2056_TX1),
(CHSPEC_IS5G(pi->radio_chanspec) ?
0xc : 0xe));
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
write_radio_reg(pi,
((core == PHY_CORE_0) ?
RADIO_2057_TX0_TX_SSI_MUX :
RADIO_2057_TX1_TX_SSI_MUX),
0x11);
if (pi->pubpi.radioid == BCM2057_ID)
write_radio_reg(pi,
RADIO_2057_IQTEST_SEL_PU, 0x1);
} else {
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MUX |
((core == PHY_CORE_0) ?
RADIO_2056_TX0 : RADIO_2056_TX1),
0x11);
}
}
}
void wlc_phy_rssisel_nphy(struct brcms_phy *pi, u8 core_code, u8 rssi_type)
{
u16 mask, val;
u16 afectrlovr_rssi_val, rfctrlcmd_rxen_val, rfctrlcmd_coresel_val,
startseq;
u16 rfctrlovr_rssi_val, rfctrlovr_rxen_val, rfctrlovr_coresel_val,
rfctrlovr_trigger_val;
u16 afectrlovr_rssi_mask, rfctrlcmd_mask, rfctrlovr_mask;
u16 rfctrlcmd_val, rfctrlovr_val;
u8 core;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (core_code == RADIO_MIMO_CORESEL_OFF) {
mod_phy_reg(pi, 0x8f, (0x1 << 9), 0);
mod_phy_reg(pi, 0xa5, (0x1 << 9), 0);
mod_phy_reg(pi, 0xa6, (0x3 << 8), 0);
mod_phy_reg(pi, 0xa7, (0x3 << 8), 0);
mod_phy_reg(pi, 0xe5, (0x1 << 5), 0);
mod_phy_reg(pi, 0xe6, (0x1 << 5), 0);
mask = (0x1 << 2) |
(0x1 << 3) | (0x1 << 4) | (0x1 << 5);
mod_phy_reg(pi, 0xf9, mask, 0);
mod_phy_reg(pi, 0xfb, mask, 0);
} else {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (core_code == RADIO_MIMO_CORESEL_CORE1
&& core == PHY_CORE_1)
continue;
else if (core_code == RADIO_MIMO_CORESEL_CORE2
&& core == PHY_CORE_0)
continue;
mod_phy_reg(pi, (core == PHY_CORE_0) ?
0x8f : 0xa5, (0x1 << 9), 1 << 9);
if (rssi_type == NPHY_RSSI_SEL_W1 ||
rssi_type == NPHY_RSSI_SEL_W2 ||
rssi_type == NPHY_RSSI_SEL_NB) {
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6 : 0xa7,
(0x3 << 8), 0);
mask = (0x1 << 2) |
(0x1 << 3) |
(0x1 << 4) | (0x1 << 5);
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xf9 : 0xfb,
mask, 0);
if (rssi_type == NPHY_RSSI_SEL_W1) {
if (CHSPEC_IS5G(
pi->radio_chanspec)) {
mask = (0x1 << 2);
val = 1 << 2;
} else {
mask = (0x1 << 3);
val = 1 << 3;
}
} else if (rssi_type ==
NPHY_RSSI_SEL_W2) {
mask = (0x1 << 4);
val = 1 << 4;
} else {
mask = (0x1 << 5);
val = 1 << 5;
}
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xf9 : 0xfb,
mask, val);
mask = (0x1 << 5);
val = 1 << 5;
mod_phy_reg(pi, (core == PHY_CORE_0) ?
0xe5 : 0xe6, mask, val);
} else {
if (rssi_type == NPHY_RSSI_SEL_TBD) {
mask = (0x3 << 8);
val = 1 << 8;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
mask = (0x3 << 10);
val = 1 << 10;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
} else if (rssi_type ==
NPHY_RSSI_SEL_IQ) {
mask = (0x3 << 8);
val = 2 << 8;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
mask = (0x3 << 10);
val = 2 << 10;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
} else {
mask = (0x3 << 8);
val = 3 << 8;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
mask = (0x3 << 10);
val = 3 << 10;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0xa6
: 0xa7, mask, val);
brcms_phy_wr_tx_mux(pi, core);
afectrlovr_rssi_val = 1 << 9;
mod_phy_reg(pi,
(core ==
PHY_CORE_0) ? 0x8f
: 0xa5, (0x1 << 9),
afectrlovr_rssi_val);
}
}
}
}
} else {
if ((rssi_type == NPHY_RSSI_SEL_W1) ||
(rssi_type == NPHY_RSSI_SEL_W2) ||
(rssi_type == NPHY_RSSI_SEL_NB))
val = 0x0;
else if (rssi_type == NPHY_RSSI_SEL_TBD)
val = 0x1;
else if (rssi_type == NPHY_RSSI_SEL_IQ)
val = 0x2;
else
val = 0x3;
mask = ((0x3 << 12) | (0x3 << 14));
val = (val << 12) | (val << 14);
mod_phy_reg(pi, 0xa6, mask, val);
mod_phy_reg(pi, 0xa7, mask, val);
if ((rssi_type == NPHY_RSSI_SEL_W1) ||
(rssi_type == NPHY_RSSI_SEL_W2) ||
(rssi_type == NPHY_RSSI_SEL_NB)) {
if (rssi_type == NPHY_RSSI_SEL_W1)
val = 0x1;
if (rssi_type == NPHY_RSSI_SEL_W2)
val = 0x2;
if (rssi_type == NPHY_RSSI_SEL_NB)
val = 0x3;
mask = (0x3 << 4);
val = (val << 4);
mod_phy_reg(pi, 0x7a, mask, val);
mod_phy_reg(pi, 0x7d, mask, val);
}
if (core_code == RADIO_MIMO_CORESEL_OFF) {
afectrlovr_rssi_val = 0;
rfctrlcmd_rxen_val = 0;
rfctrlcmd_coresel_val = 0;
rfctrlovr_rssi_val = 0;
rfctrlovr_rxen_val = 0;
rfctrlovr_coresel_val = 0;
rfctrlovr_trigger_val = 0;
startseq = 0;
} else {
afectrlovr_rssi_val = 1;
rfctrlcmd_rxen_val = 1;
rfctrlcmd_coresel_val = core_code;
rfctrlovr_rssi_val = 1;
rfctrlovr_rxen_val = 1;
rfctrlovr_coresel_val = 1;
rfctrlovr_trigger_val = 1;
startseq = 1;
}
afectrlovr_rssi_mask = ((0x1 << 12) | (0x1 << 13));
afectrlovr_rssi_val = (afectrlovr_rssi_val <<
12) | (afectrlovr_rssi_val << 13);
mod_phy_reg(pi, 0xa5, afectrlovr_rssi_mask,
afectrlovr_rssi_val);
if ((rssi_type == NPHY_RSSI_SEL_W1) ||
(rssi_type == NPHY_RSSI_SEL_W2) ||
(rssi_type == NPHY_RSSI_SEL_NB)) {
rfctrlcmd_mask = ((0x1 << 8) | (0x7 << 3));
rfctrlcmd_val = (rfctrlcmd_rxen_val << 8) |
(rfctrlcmd_coresel_val << 3);
rfctrlovr_mask = ((0x1 << 5) |
(0x1 << 12) |
(0x1 << 1) | (0x1 << 0));
rfctrlovr_val = (rfctrlovr_rssi_val <<
5) |
(rfctrlovr_rxen_val << 12) |
(rfctrlovr_coresel_val << 1) |
(rfctrlovr_trigger_val << 0);
mod_phy_reg(pi, 0x78, rfctrlcmd_mask, rfctrlcmd_val);
mod_phy_reg(pi, 0xec, rfctrlovr_mask, rfctrlovr_val);
mod_phy_reg(pi, 0x78, (0x1 << 0), (startseq << 0));
udelay(20);
mod_phy_reg(pi, 0xec, (0x1 << 0), 0);
}
}
}
int
wlc_phy_poll_rssi_nphy(struct brcms_phy *pi, u8 rssi_type, s32 *rssi_buf,
u8 nsamps)
{
s16 rssi0, rssi1;
u16 afectrlCore1_save = 0;
u16 afectrlCore2_save = 0;
u16 afectrlOverride1_save = 0;
u16 afectrlOverride2_save = 0;
u16 rfctrlOverrideAux0_save = 0;
u16 rfctrlOverrideAux1_save = 0;
u16 rfctrlMiscReg1_save = 0;
u16 rfctrlMiscReg2_save = 0;
u16 rfctrlcmd_save = 0;
u16 rfctrloverride_save = 0;
u16 rfctrlrssiothers1_save = 0;
u16 rfctrlrssiothers2_save = 0;
s8 tmp_buf[4];
u8 ctr = 0, samp = 0;
s32 rssi_out_val;
u16 gpiosel_orig;
afectrlCore1_save = read_phy_reg(pi, 0xa6);
afectrlCore2_save = read_phy_reg(pi, 0xa7);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
rfctrlMiscReg1_save = read_phy_reg(pi, 0xf9);
rfctrlMiscReg2_save = read_phy_reg(pi, 0xfb);
afectrlOverride1_save = read_phy_reg(pi, 0x8f);
afectrlOverride2_save = read_phy_reg(pi, 0xa5);
rfctrlOverrideAux0_save = read_phy_reg(pi, 0xe5);
rfctrlOverrideAux1_save = read_phy_reg(pi, 0xe6);
} else {
afectrlOverride1_save = read_phy_reg(pi, 0xa5);
rfctrlcmd_save = read_phy_reg(pi, 0x78);
rfctrloverride_save = read_phy_reg(pi, 0xec);
rfctrlrssiothers1_save = read_phy_reg(pi, 0x7a);
rfctrlrssiothers2_save = read_phy_reg(pi, 0x7d);
}
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_ALLRX, rssi_type);
gpiosel_orig = read_phy_reg(pi, 0xca);
if (NREV_LT(pi->pubpi.phy_rev, 2))
write_phy_reg(pi, 0xca, 5);
for (ctr = 0; ctr < 4; ctr++)
rssi_buf[ctr] = 0;
for (samp = 0; samp < nsamps; samp++) {
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
rssi0 = read_phy_reg(pi, 0x1c9);
rssi1 = read_phy_reg(pi, 0x1ca);
} else {
rssi0 = read_phy_reg(pi, 0x219);
rssi1 = read_phy_reg(pi, 0x21a);
}
ctr = 0;
tmp_buf[ctr++] = ((s8) ((rssi0 & 0x3f) << 2)) >> 2;
tmp_buf[ctr++] = ((s8) (((rssi0 >> 8) & 0x3f) << 2)) >> 2;
tmp_buf[ctr++] = ((s8) ((rssi1 & 0x3f) << 2)) >> 2;
tmp_buf[ctr++] = ((s8) (((rssi1 >> 8) & 0x3f) << 2)) >> 2;
for (ctr = 0; ctr < 4; ctr++)
rssi_buf[ctr] += tmp_buf[ctr];
}
rssi_out_val = rssi_buf[3] & 0xff;
rssi_out_val |= (rssi_buf[2] & 0xff) << 8;
rssi_out_val |= (rssi_buf[1] & 0xff) << 16;
rssi_out_val |= (rssi_buf[0] & 0xff) << 24;
if (NREV_LT(pi->pubpi.phy_rev, 2))
write_phy_reg(pi, 0xca, gpiosel_orig);
write_phy_reg(pi, 0xa6, afectrlCore1_save);
write_phy_reg(pi, 0xa7, afectrlCore2_save);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_phy_reg(pi, 0xf9, rfctrlMiscReg1_save);
write_phy_reg(pi, 0xfb, rfctrlMiscReg2_save);
write_phy_reg(pi, 0x8f, afectrlOverride1_save);
write_phy_reg(pi, 0xa5, afectrlOverride2_save);
write_phy_reg(pi, 0xe5, rfctrlOverrideAux0_save);
write_phy_reg(pi, 0xe6, rfctrlOverrideAux1_save);
} else {
write_phy_reg(pi, 0xa5, afectrlOverride1_save);
write_phy_reg(pi, 0x78, rfctrlcmd_save);
write_phy_reg(pi, 0xec, rfctrloverride_save);
write_phy_reg(pi, 0x7a, rfctrlrssiothers1_save);
write_phy_reg(pi, 0x7d, rfctrlrssiothers2_save);
}
return rssi_out_val;
}
s16 wlc_phy_tempsense_nphy(struct brcms_phy *pi)
{
u16 core1_txrf_iqcal1_save, core1_txrf_iqcal2_save;
u16 core2_txrf_iqcal1_save, core2_txrf_iqcal2_save;
u16 pwrdet_rxtx_core1_save;
u16 pwrdet_rxtx_core2_save;
u16 afectrlCore1_save;
u16 afectrlCore2_save;
u16 afectrlOverride_save;
u16 afectrlOverride2_save;
u16 pd_pll_ts_save;
u16 gpioSel_save;
s32 radio_temp[4];
s32 radio_temp2[4];
u16 syn_tempprocsense_save;
s16 offset = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
u16 auxADC_Vmid, auxADC_Av, auxADC_Vmid_save, auxADC_Av_save;
u16 auxADC_rssi_ctrlL_save, auxADC_rssi_ctrlH_save;
u16 auxADC_rssi_ctrlL, auxADC_rssi_ctrlH;
s32 auxADC_Vl;
u16 RfctrlOverride5_save, RfctrlOverride6_save;
u16 RfctrlMiscReg5_save, RfctrlMiscReg6_save;
u16 RSSIMultCoef0QPowerDet_save;
u16 tempsense_Rcal;
syn_tempprocsense_save =
read_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG);
afectrlCore1_save = read_phy_reg(pi, 0xa6);
afectrlCore2_save = read_phy_reg(pi, 0xa7);
afectrlOverride_save = read_phy_reg(pi, 0x8f);
afectrlOverride2_save = read_phy_reg(pi, 0xa5);
RSSIMultCoef0QPowerDet_save = read_phy_reg(pi, 0x1ae);
RfctrlOverride5_save = read_phy_reg(pi, 0x346);
RfctrlOverride6_save = read_phy_reg(pi, 0x347);
RfctrlMiscReg5_save = read_phy_reg(pi, 0x344);
RfctrlMiscReg6_save = read_phy_reg(pi, 0x345);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0A, 16,
&auxADC_Vmid_save);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0E, 16,
&auxADC_Av_save);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x02, 16,
&auxADC_rssi_ctrlL_save);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x03, 16,
&auxADC_rssi_ctrlH_save);
write_phy_reg(pi, 0x1ae, 0x0);
auxADC_rssi_ctrlL = 0x0;
auxADC_rssi_ctrlH = 0x20;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x02, 16,
&auxADC_rssi_ctrlL);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x03, 16,
&auxADC_rssi_ctrlH);
tempsense_Rcal = syn_tempprocsense_save & 0x1c;
write_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG,
tempsense_Rcal | 0x01);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 1),
1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
mod_phy_reg(pi, 0xa6, (0x1 << 7), 0);
mod_phy_reg(pi, 0xa7, (0x1 << 7), 0);
mod_phy_reg(pi, 0x8f, (0x1 << 7), (0x1 << 7));
mod_phy_reg(pi, 0xa5, (0x1 << 7), (0x1 << 7));
mod_phy_reg(pi, 0xa6, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0xa7, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0x8f, (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, 0xa5, (0x1 << 2), (0x1 << 2));
udelay(5);
mod_phy_reg(pi, 0xa6, (0x1 << 2), 0);
mod_phy_reg(pi, 0xa7, (0x1 << 2), 0);
mod_phy_reg(pi, 0xa6, (0x1 << 3), 0);
mod_phy_reg(pi, 0xa7, (0x1 << 3), 0);
mod_phy_reg(pi, 0x8f, (0x1 << 3), (0x1 << 3));
mod_phy_reg(pi, 0xa5, (0x1 << 3), (0x1 << 3));
mod_phy_reg(pi, 0xa6, (0x1 << 6), 0);
mod_phy_reg(pi, 0xa7, (0x1 << 6), 0);
mod_phy_reg(pi, 0x8f, (0x1 << 6), (0x1 << 6));
mod_phy_reg(pi, 0xa5, (0x1 << 6), (0x1 << 6));
auxADC_Vmid = 0xA3;
auxADC_Av = 0x0;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0A, 16,
&auxADC_Vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0E, 16,
&auxADC_Av);
udelay(3);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp, 1);
write_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG,
tempsense_Rcal | 0x03);
udelay(5);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp2, 1);
auxADC_Av = 0x7;
if (radio_temp[1] + radio_temp2[1] < -30) {
auxADC_Vmid = 0x45;
auxADC_Vl = 263;
} else if (radio_temp[1] + radio_temp2[1] < -9) {
auxADC_Vmid = 0x200;
auxADC_Vl = 467;
} else if (radio_temp[1] + radio_temp2[1] < 11) {
auxADC_Vmid = 0x266;
auxADC_Vl = 634;
} else {
auxADC_Vmid = 0x2D5;
auxADC_Vl = 816;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0A, 16,
&auxADC_Vmid);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0E, 16,
&auxADC_Av);
udelay(3);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp2, 1);
write_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG,
tempsense_Rcal | 0x01);
udelay(5);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp, 1);
write_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG,
syn_tempprocsense_save);
write_phy_reg(pi, 0xa6, afectrlCore1_save);
write_phy_reg(pi, 0xa7, afectrlCore2_save);
write_phy_reg(pi, 0x8f, afectrlOverride_save);
write_phy_reg(pi, 0xa5, afectrlOverride2_save);
write_phy_reg(pi, 0x1ae, RSSIMultCoef0QPowerDet_save);
write_phy_reg(pi, 0x346, RfctrlOverride5_save);
write_phy_reg(pi, 0x347, RfctrlOverride6_save);
write_phy_reg(pi, 0x344, RfctrlMiscReg5_save);
write_phy_reg(pi, 0x345, RfctrlMiscReg5_save);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0A, 16,
&auxADC_Vmid_save);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x0E, 16,
&auxADC_Av_save);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x02, 16,
&auxADC_rssi_ctrlL_save);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 0x03, 16,
&auxADC_rssi_ctrlH_save);
if (pi->sh->chip == BCMA_CHIP_ID_BCM5357) {
radio_temp[0] = (193 * (radio_temp[1] + radio_temp2[1])
+ 88 * (auxADC_Vl) - 27111 +
128) / 256;
} else {
radio_temp[0] = (179 * (radio_temp[1] + radio_temp2[1])
+ 82 * (auxADC_Vl) - 28861 +
128) / 256;
}
offset = (s16) pi->phy_tempsense_offset;
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
syn_tempprocsense_save =
read_radio_reg(pi, RADIO_2056_SYN_TEMPPROCSENSE);
afectrlCore1_save = read_phy_reg(pi, 0xa6);
afectrlCore2_save = read_phy_reg(pi, 0xa7);
afectrlOverride_save = read_phy_reg(pi, 0x8f);
afectrlOverride2_save = read_phy_reg(pi, 0xa5);
gpioSel_save = read_phy_reg(pi, 0xca);
write_radio_reg(pi, RADIO_2056_SYN_TEMPPROCSENSE, 0x01);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp, 1);
if (NREV_LT(pi->pubpi.phy_rev, 7))
write_radio_reg(pi, RADIO_2056_SYN_TEMPPROCSENSE, 0x05);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp2, 1);
if (NREV_GE(pi->pubpi.phy_rev, 7))
write_radio_reg(pi, RADIO_2057_TEMPSENSE_CONFIG, 0x01);
else
write_radio_reg(pi, RADIO_2056_SYN_TEMPPROCSENSE, 0x01);
radio_temp[0] =
(126 * (radio_temp[1] + radio_temp2[1]) + 3987) / 64;
write_radio_reg(pi, RADIO_2056_SYN_TEMPPROCSENSE,
syn_tempprocsense_save);
write_phy_reg(pi, 0xca, gpioSel_save);
write_phy_reg(pi, 0xa6, afectrlCore1_save);
write_phy_reg(pi, 0xa7, afectrlCore2_save);
write_phy_reg(pi, 0x8f, afectrlOverride_save);
write_phy_reg(pi, 0xa5, afectrlOverride2_save);
offset = (s16) pi->phy_tempsense_offset;
} else {
pwrdet_rxtx_core1_save =
read_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1);
pwrdet_rxtx_core2_save =
read_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2);
core1_txrf_iqcal1_save =
read_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1);
core1_txrf_iqcal2_save =
read_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2);
core2_txrf_iqcal1_save =
read_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1);
core2_txrf_iqcal2_save =
read_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2);
pd_pll_ts_save = read_radio_reg(pi, RADIO_2055_PD_PLL_TS);
afectrlCore1_save = read_phy_reg(pi, 0xa6);
afectrlCore2_save = read_phy_reg(pi, 0xa7);
afectrlOverride_save = read_phy_reg(pi, 0xa5);
gpioSel_save = read_phy_reg(pi, 0xca);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1, 0x01);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1, 0x01);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2, 0x08);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2, 0x08);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1, 0x04);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2, 0x04);
write_radio_reg(pi, RADIO_2055_PD_PLL_TS, 0x00);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp, 1);
xor_radio_reg(pi, RADIO_2055_CAL_TS, 0x80);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp, 1);
xor_radio_reg(pi, RADIO_2055_CAL_TS, 0x80);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_IQ, radio_temp2, 1);
xor_radio_reg(pi, RADIO_2055_CAL_TS, 0x80);
radio_temp[0] = (radio_temp[0] + radio_temp2[0]);
radio_temp[1] = (radio_temp[1] + radio_temp2[1]);
radio_temp[2] = (radio_temp[2] + radio_temp2[2]);
radio_temp[3] = (radio_temp[3] + radio_temp2[3]);
radio_temp[0] =
(radio_temp[0] + radio_temp[1] + radio_temp[2] +
radio_temp[3]);
radio_temp[0] =
(radio_temp[0] +
(8 * 32)) * (950 - 350) / 63 + (350 * 8);
radio_temp[0] = (radio_temp[0] - (8 * 420)) / 38;
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1,
pwrdet_rxtx_core1_save);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2,
pwrdet_rxtx_core2_save);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1,
core1_txrf_iqcal1_save);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1,
core2_txrf_iqcal1_save);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2,
core1_txrf_iqcal2_save);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2,
core2_txrf_iqcal2_save);
write_radio_reg(pi, RADIO_2055_PD_PLL_TS, pd_pll_ts_save);
write_phy_reg(pi, 0xca, gpioSel_save);
write_phy_reg(pi, 0xa6, afectrlCore1_save);
write_phy_reg(pi, 0xa7, afectrlCore2_save);
write_phy_reg(pi, 0xa5, afectrlOverride_save);
}
return (s16) radio_temp[0] + offset;
}
static void
wlc_phy_set_rssi_2055_vcm(struct brcms_phy *pi, u8 rssi_type, u8 *vcm_buf)
{
u8 core;
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (rssi_type == NPHY_RSSI_SEL_NB) {
if (core == PHY_CORE_0) {
mod_radio_reg(pi,
RADIO_2055_CORE1_B0_NBRSSI_VCM,
RADIO_2055_NBRSSI_VCM_I_MASK,
vcm_buf[2 *
core] <<
RADIO_2055_NBRSSI_VCM_I_SHIFT);
mod_radio_reg(pi,
RADIO_2055_CORE1_RXBB_RSSI_CTRL5,
RADIO_2055_NBRSSI_VCM_Q_MASK,
vcm_buf[2 * core +
1] <<
RADIO_2055_NBRSSI_VCM_Q_SHIFT);
} else {
mod_radio_reg(pi,
RADIO_2055_CORE2_B0_NBRSSI_VCM,
RADIO_2055_NBRSSI_VCM_I_MASK,
vcm_buf[2 *
core] <<
RADIO_2055_NBRSSI_VCM_I_SHIFT);
mod_radio_reg(pi,
RADIO_2055_CORE2_RXBB_RSSI_CTRL5,
RADIO_2055_NBRSSI_VCM_Q_MASK,
vcm_buf[2 * core +
1] <<
RADIO_2055_NBRSSI_VCM_Q_SHIFT);
}
} else {
if (core == PHY_CORE_0)
mod_radio_reg(pi,
RADIO_2055_CORE1_RXBB_RSSI_CTRL5,
RADIO_2055_WBRSSI_VCM_IQ_MASK,
vcm_buf[2 *
core] <<
RADIO_2055_WBRSSI_VCM_IQ_SHIFT);
else
mod_radio_reg(pi,
RADIO_2055_CORE2_RXBB_RSSI_CTRL5,
RADIO_2055_WBRSSI_VCM_IQ_MASK,
vcm_buf[2 *
core] <<
RADIO_2055_WBRSSI_VCM_IQ_SHIFT);
}
}
}
static void wlc_phy_rssi_cal_nphy_rev3(struct brcms_phy *pi)
{
u16 classif_state;
u16 clip_state[2];
u16 clip_off[] = { 0xffff, 0xffff };
s32 target_code;
u8 vcm, min_vcm;
u8 vcm_final = 0;
u8 result_idx;
s32 poll_results[8][4] = {
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};
s32 poll_result_core[4] = { 0, 0, 0, 0 };
s32 min_d = NPHY_RSSICAL_MAXD, curr_d;
s32 fine_digital_offset[4];
s32 poll_results_min[4] = { 0, 0, 0, 0 };
s32 min_poll;
u8 vcm_level_max;
u8 core;
u8 wb_cnt;
u8 rssi_type;
u16 NPHY_Rfctrlintc1_save, NPHY_Rfctrlintc2_save;
u16 NPHY_AfectrlOverride1_save, NPHY_AfectrlOverride2_save;
u16 NPHY_AfectrlCore1_save, NPHY_AfectrlCore2_save;
u16 NPHY_RfctrlOverride0_save, NPHY_RfctrlOverride1_save;
u16 NPHY_RfctrlOverrideAux0_save, NPHY_RfctrlOverrideAux1_save;
u16 NPHY_RfctrlCmd_save;
u16 NPHY_RfctrlMiscReg1_save, NPHY_RfctrlMiscReg2_save;
u16 NPHY_RfctrlRSSIOTHERS1_save, NPHY_RfctrlRSSIOTHERS2_save;
u8 rxcore_state;
u16 NPHY_REV7_RfctrlOverride3_save, NPHY_REV7_RfctrlOverride4_save;
u16 NPHY_REV7_RfctrlOverride5_save, NPHY_REV7_RfctrlOverride6_save;
u16 NPHY_REV7_RfctrlMiscReg3_save, NPHY_REV7_RfctrlMiscReg4_save;
u16 NPHY_REV7_RfctrlMiscReg5_save, NPHY_REV7_RfctrlMiscReg6_save;
NPHY_REV7_RfctrlOverride3_save =
NPHY_REV7_RfctrlOverride4_save =
NPHY_REV7_RfctrlOverride5_save =
NPHY_REV7_RfctrlOverride6_save =
NPHY_REV7_RfctrlMiscReg3_save =
NPHY_REV7_RfctrlMiscReg4_save =
NPHY_REV7_RfctrlMiscReg5_save =
NPHY_REV7_RfctrlMiscReg6_save = 0;
classif_state = wlc_phy_classifier_nphy(pi, 0, 0);
wlc_phy_classifier_nphy(pi, (0x7 << 0), 4);
wlc_phy_clip_det_nphy(pi, 0, clip_state);
wlc_phy_clip_det_nphy(pi, 1, clip_off);
NPHY_Rfctrlintc1_save = read_phy_reg(pi, 0x91);
NPHY_Rfctrlintc2_save = read_phy_reg(pi, 0x92);
NPHY_AfectrlOverride1_save = read_phy_reg(pi, 0x8f);
NPHY_AfectrlOverride2_save = read_phy_reg(pi, 0xa5);
NPHY_AfectrlCore1_save = read_phy_reg(pi, 0xa6);
NPHY_AfectrlCore2_save = read_phy_reg(pi, 0xa7);
NPHY_RfctrlOverride0_save = read_phy_reg(pi, 0xe7);
NPHY_RfctrlOverride1_save = read_phy_reg(pi, 0xec);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
NPHY_REV7_RfctrlOverride3_save = read_phy_reg(pi, 0x342);
NPHY_REV7_RfctrlOverride4_save = read_phy_reg(pi, 0x343);
NPHY_REV7_RfctrlOverride5_save = read_phy_reg(pi, 0x346);
NPHY_REV7_RfctrlOverride6_save = read_phy_reg(pi, 0x347);
}
NPHY_RfctrlOverrideAux0_save = read_phy_reg(pi, 0xe5);
NPHY_RfctrlOverrideAux1_save = read_phy_reg(pi, 0xe6);
NPHY_RfctrlCmd_save = read_phy_reg(pi, 0x78);
NPHY_RfctrlMiscReg1_save = read_phy_reg(pi, 0xf9);
NPHY_RfctrlMiscReg2_save = read_phy_reg(pi, 0xfb);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
NPHY_REV7_RfctrlMiscReg3_save = read_phy_reg(pi, 0x340);
NPHY_REV7_RfctrlMiscReg4_save = read_phy_reg(pi, 0x341);
NPHY_REV7_RfctrlMiscReg5_save = read_phy_reg(pi, 0x344);
NPHY_REV7_RfctrlMiscReg6_save = read_phy_reg(pi, 0x345);
}
NPHY_RfctrlRSSIOTHERS1_save = read_phy_reg(pi, 0x7a);
NPHY_RfctrlRSSIOTHERS2_save = read_phy_reg(pi, 0x7d);
wlc_phy_rfctrlintc_override_nphy(pi, NPHY_RfctrlIntc_override_OFF, 0,
RADIO_MIMO_CORESEL_ALLRXTX);
wlc_phy_rfctrlintc_override_nphy(pi, NPHY_RfctrlIntc_override_TRSW, 1,
RADIO_MIMO_CORESEL_ALLRXTX);
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_rxrf_pu,
0, 0, 0);
else
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 0), 0, 0, 0);
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_rx_pu,
1, 0, 0);
else
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 1), 1, 0, 0);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 7),
1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 6), 1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 7), 1, 0, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 6), 1, 0, 0);
}
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 5),
0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 4), 1, 0,
0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 5), 0, 0, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 4), 1, 0, 0);
}
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 4),
0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 5), 1, 0,
0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 4), 0, 0, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 5), 1, 0, 0);
}
}
rxcore_state = wlc_phy_rxcore_getstate_nphy(
(struct brcms_phy_pub *) pi);
vcm_level_max = 8;
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if ((rxcore_state & (1 << core)) == 0)
continue;
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0,
core ==
PHY_CORE_0 ?
RADIO_MIMO_CORESEL_CORE1 :
RADIO_MIMO_CORESEL_CORE2,
NPHY_RAIL_I, NPHY_RSSI_SEL_NB);
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0,
core ==
PHY_CORE_0 ?
RADIO_MIMO_CORESEL_CORE1 :
RADIO_MIMO_CORESEL_CORE2,
NPHY_RAIL_Q, NPHY_RSSI_SEL_NB);
for (vcm = 0; vcm < vcm_level_max; vcm++) {
if (NREV_GE(pi->pubpi.phy_rev, 7))
mod_radio_reg(pi, (core == PHY_CORE_0) ?
RADIO_2057_NB_MASTER_CORE0 :
RADIO_2057_NB_MASTER_CORE1,
RADIO_2057_VCM_MASK, vcm);
else
mod_radio_reg(pi, RADIO_2056_RX_RSSI_MISC |
((core ==
PHY_CORE_0) ? RADIO_2056_RX0 :
RADIO_2056_RX1),
RADIO_2056_VCM_MASK,
vcm << RADIO_2056_RSSI_VCM_SHIFT);
wlc_phy_poll_rssi_nphy(pi, NPHY_RSSI_SEL_NB,
&poll_results[vcm][0],
NPHY_RSSICAL_NPOLL);
}
for (result_idx = 0; result_idx < 4; result_idx++) {
if ((core == result_idx / 2) &&
(result_idx % 2 == 0)) {
min_d = NPHY_RSSICAL_MAXD;
min_vcm = 0;
min_poll =
NPHY_RSSICAL_MAXREAD *
NPHY_RSSICAL_NPOLL + 1;
for (vcm = 0; vcm < vcm_level_max; vcm++) {
curr_d =
poll_results[vcm][result_idx] *
poll_results[vcm][result_idx] +
poll_results[vcm][result_idx +
1] *
poll_results[vcm][result_idx +
1];
if (curr_d < min_d) {
min_d = curr_d;
min_vcm = vcm;
}
if (poll_results[vcm][result_idx] <
min_poll)
min_poll =
poll_results[vcm]
[result_idx];
}
vcm_final = min_vcm;
poll_results_min[result_idx] = min_poll;
}
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
mod_radio_reg(pi, (core == PHY_CORE_0) ?
RADIO_2057_NB_MASTER_CORE0 :
RADIO_2057_NB_MASTER_CORE1,
RADIO_2057_VCM_MASK, vcm_final);
else
mod_radio_reg(pi, RADIO_2056_RX_RSSI_MISC |
((core ==
PHY_CORE_0) ? RADIO_2056_RX0 :
RADIO_2056_RX1), RADIO_2056_VCM_MASK,
vcm_final << RADIO_2056_RSSI_VCM_SHIFT);
for (result_idx = 0; result_idx < 4; result_idx++) {
if (core == result_idx / 2) {
fine_digital_offset[result_idx] =
(NPHY_RSSICAL_NB_TARGET *
NPHY_RSSICAL_NPOLL) -
poll_results[vcm_final][result_idx];
if (fine_digital_offset[result_idx] < 0) {
fine_digital_offset[result_idx] =
abs(fine_digital_offset
[result_idx]);
fine_digital_offset[result_idx] +=
(NPHY_RSSICAL_NPOLL / 2);
fine_digital_offset[result_idx] /=
NPHY_RSSICAL_NPOLL;
fine_digital_offset[result_idx] =
-fine_digital_offset[
result_idx];
} else {
fine_digital_offset[result_idx] +=
(NPHY_RSSICAL_NPOLL / 2);
fine_digital_offset[result_idx] /=
NPHY_RSSICAL_NPOLL;
}
if (poll_results_min[result_idx] ==
NPHY_RSSICAL_MAXREAD * NPHY_RSSICAL_NPOLL)
fine_digital_offset[result_idx] =
(NPHY_RSSICAL_NB_TARGET -
NPHY_RSSICAL_MAXREAD - 1);
wlc_phy_scale_offset_rssi_nphy(
pi, 0x0,
(s8)
fine_digital_offset
[result_idx],
(result_idx / 2 == 0) ?
RADIO_MIMO_CORESEL_CORE1 :
RADIO_MIMO_CORESEL_CORE2,
(result_idx % 2 == 0) ?
NPHY_RAIL_I : NPHY_RAIL_Q,
NPHY_RSSI_SEL_NB);
}
}
}
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if ((rxcore_state & (1 << core)) == 0)
continue;
for (wb_cnt = 0; wb_cnt < 2; wb_cnt++) {
if (wb_cnt == 0) {
rssi_type = NPHY_RSSI_SEL_W1;
target_code = NPHY_RSSICAL_W1_TARGET_REV3;
} else {
rssi_type = NPHY_RSSI_SEL_W2;
target_code = NPHY_RSSICAL_W2_TARGET_REV3;
}
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0,
core ==
PHY_CORE_0 ?
RADIO_MIMO_CORESEL_CORE1
:
RADIO_MIMO_CORESEL_CORE2,
NPHY_RAIL_I, rssi_type);
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0,
core ==
PHY_CORE_0 ?
RADIO_MIMO_CORESEL_CORE1
:
RADIO_MIMO_CORESEL_CORE2,
NPHY_RAIL_Q, rssi_type);
wlc_phy_poll_rssi_nphy(pi, rssi_type, poll_result_core,
NPHY_RSSICAL_NPOLL);
for (result_idx = 0; result_idx < 4; result_idx++) {
if (core == result_idx / 2) {
fine_digital_offset[result_idx] =
(target_code *
NPHY_RSSICAL_NPOLL) -
poll_result_core[result_idx];
if (fine_digital_offset[result_idx] <
0) {
fine_digital_offset[result_idx]
= abs(
fine_digital_offset
[result_idx]);
fine_digital_offset[result_idx]
+= (NPHY_RSSICAL_NPOLL
/ 2);
fine_digital_offset[result_idx]
/= NPHY_RSSICAL_NPOLL;
fine_digital_offset[result_idx]
= -fine_digital_offset
[result_idx];
} else {
fine_digital_offset[result_idx]
+= (NPHY_RSSICAL_NPOLL
/ 2);
fine_digital_offset[result_idx]
/= NPHY_RSSICAL_NPOLL;
}
wlc_phy_scale_offset_rssi_nphy(
pi, 0x0,
(s8)
fine_digital_offset
[core *
2],
(core == PHY_CORE_0) ?
RADIO_MIMO_CORESEL_CORE1 :
RADIO_MIMO_CORESEL_CORE2,
(result_idx % 2 == 0) ?
NPHY_RAIL_I :
NPHY_RAIL_Q,
rssi_type);
}
}
}
}
write_phy_reg(pi, 0x91, NPHY_Rfctrlintc1_save);
write_phy_reg(pi, 0x92, NPHY_Rfctrlintc2_save);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
mod_phy_reg(pi, 0xe7, (0x1 << 0), 1 << 0);
mod_phy_reg(pi, 0x78, (0x1 << 0), 1 << 0);
mod_phy_reg(pi, 0xe7, (0x1 << 0), 0);
mod_phy_reg(pi, 0xec, (0x1 << 0), 1 << 0);
mod_phy_reg(pi, 0x78, (0x1 << 1), 1 << 1);
mod_phy_reg(pi, 0xec, (0x1 << 0), 0);
write_phy_reg(pi, 0x8f, NPHY_AfectrlOverride1_save);
write_phy_reg(pi, 0xa5, NPHY_AfectrlOverride2_save);
write_phy_reg(pi, 0xa6, NPHY_AfectrlCore1_save);
write_phy_reg(pi, 0xa7, NPHY_AfectrlCore2_save);
write_phy_reg(pi, 0xe7, NPHY_RfctrlOverride0_save);
write_phy_reg(pi, 0xec, NPHY_RfctrlOverride1_save);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
write_phy_reg(pi, 0x342, NPHY_REV7_RfctrlOverride3_save);
write_phy_reg(pi, 0x343, NPHY_REV7_RfctrlOverride4_save);
write_phy_reg(pi, 0x346, NPHY_REV7_RfctrlOverride5_save);
write_phy_reg(pi, 0x347, NPHY_REV7_RfctrlOverride6_save);
}
write_phy_reg(pi, 0xe5, NPHY_RfctrlOverrideAux0_save);
write_phy_reg(pi, 0xe6, NPHY_RfctrlOverrideAux1_save);
write_phy_reg(pi, 0x78, NPHY_RfctrlCmd_save);
write_phy_reg(pi, 0xf9, NPHY_RfctrlMiscReg1_save);
write_phy_reg(pi, 0xfb, NPHY_RfctrlMiscReg2_save);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
write_phy_reg(pi, 0x340, NPHY_REV7_RfctrlMiscReg3_save);
write_phy_reg(pi, 0x341, NPHY_REV7_RfctrlMiscReg4_save);
write_phy_reg(pi, 0x344, NPHY_REV7_RfctrlMiscReg5_save);
write_phy_reg(pi, 0x345, NPHY_REV7_RfctrlMiscReg6_save);
}
write_phy_reg(pi, 0x7a, NPHY_RfctrlRSSIOTHERS1_save);
write_phy_reg(pi, 0x7d, NPHY_RfctrlRSSIOTHERS2_save);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
pi->rssical_cache.rssical_radio_regs_2G[0] =
read_radio_reg(pi, RADIO_2057_NB_MASTER_CORE0);
pi->rssical_cache.rssical_radio_regs_2G[1] =
read_radio_reg(pi, RADIO_2057_NB_MASTER_CORE1);
} else {
pi->rssical_cache.rssical_radio_regs_2G[0] =
read_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC |
RADIO_2056_RX0);
pi->rssical_cache.rssical_radio_regs_2G[1] =
read_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC |
RADIO_2056_RX1);
}
pi->rssical_cache.rssical_phyregs_2G[0] =
read_phy_reg(pi, 0x1a6);
pi->rssical_cache.rssical_phyregs_2G[1] =
read_phy_reg(pi, 0x1ac);
pi->rssical_cache.rssical_phyregs_2G[2] =
read_phy_reg(pi, 0x1b2);
pi->rssical_cache.rssical_phyregs_2G[3] =
read_phy_reg(pi, 0x1b8);
pi->rssical_cache.rssical_phyregs_2G[4] =
read_phy_reg(pi, 0x1a4);
pi->rssical_cache.rssical_phyregs_2G[5] =
read_phy_reg(pi, 0x1aa);
pi->rssical_cache.rssical_phyregs_2G[6] =
read_phy_reg(pi, 0x1b0);
pi->rssical_cache.rssical_phyregs_2G[7] =
read_phy_reg(pi, 0x1b6);
pi->rssical_cache.rssical_phyregs_2G[8] =
read_phy_reg(pi, 0x1a5);
pi->rssical_cache.rssical_phyregs_2G[9] =
read_phy_reg(pi, 0x1ab);
pi->rssical_cache.rssical_phyregs_2G[10] =
read_phy_reg(pi, 0x1b1);
pi->rssical_cache.rssical_phyregs_2G[11] =
read_phy_reg(pi, 0x1b7);
pi->nphy_rssical_chanspec_2G = pi->radio_chanspec;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
pi->rssical_cache.rssical_radio_regs_5G[0] =
read_radio_reg(pi, RADIO_2057_NB_MASTER_CORE0);
pi->rssical_cache.rssical_radio_regs_5G[1] =
read_radio_reg(pi, RADIO_2057_NB_MASTER_CORE1);
} else {
pi->rssical_cache.rssical_radio_regs_5G[0] =
read_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC |
RADIO_2056_RX0);
pi->rssical_cache.rssical_radio_regs_5G[1] =
read_radio_reg(pi,
RADIO_2056_RX_RSSI_MISC |
RADIO_2056_RX1);
}
pi->rssical_cache.rssical_phyregs_5G[0] =
read_phy_reg(pi, 0x1a6);
pi->rssical_cache.rssical_phyregs_5G[1] =
read_phy_reg(pi, 0x1ac);
pi->rssical_cache.rssical_phyregs_5G[2] =
read_phy_reg(pi, 0x1b2);
pi->rssical_cache.rssical_phyregs_5G[3] =
read_phy_reg(pi, 0x1b8);
pi->rssical_cache.rssical_phyregs_5G[4] =
read_phy_reg(pi, 0x1a4);
pi->rssical_cache.rssical_phyregs_5G[5] =
read_phy_reg(pi, 0x1aa);
pi->rssical_cache.rssical_phyregs_5G[6] =
read_phy_reg(pi, 0x1b0);
pi->rssical_cache.rssical_phyregs_5G[7] =
read_phy_reg(pi, 0x1b6);
pi->rssical_cache.rssical_phyregs_5G[8] =
read_phy_reg(pi, 0x1a5);
pi->rssical_cache.rssical_phyregs_5G[9] =
read_phy_reg(pi, 0x1ab);
pi->rssical_cache.rssical_phyregs_5G[10] =
read_phy_reg(pi, 0x1b1);
pi->rssical_cache.rssical_phyregs_5G[11] =
read_phy_reg(pi, 0x1b7);
pi->nphy_rssical_chanspec_5G = pi->radio_chanspec;
}
wlc_phy_classifier_nphy(pi, (0x7 << 0), classif_state);
wlc_phy_clip_det_nphy(pi, 1, clip_state);
}
static void wlc_phy_rssi_cal_nphy_rev2(struct brcms_phy *pi, u8 rssi_type)
{
s32 target_code;
u16 classif_state;
u16 clip_state[2];
u16 rssi_ctrl_state[2], pd_state[2];
u16 rfctrlintc_state[2], rfpdcorerxtx_state[2];
u16 rfctrlintc_override_val;
u16 clip_off[] = { 0xffff, 0xffff };
u16 rf_pd_val, pd_mask, rssi_ctrl_mask;
u8 vcm, min_vcm, vcm_tmp[4];
u8 vcm_final[4] = { 0, 0, 0, 0 };
u8 result_idx, ctr;
s32 poll_results[4][4] = {
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};
s32 poll_miniq[4][2] = {
{0, 0},
{0, 0},
{0, 0},
{0, 0}
};
s32 min_d, curr_d;
s32 fine_digital_offset[4];
s32 poll_results_min[4] = { 0, 0, 0, 0 };
s32 min_poll;
switch (rssi_type) {
case NPHY_RSSI_SEL_NB:
target_code = NPHY_RSSICAL_NB_TARGET;
break;
case NPHY_RSSI_SEL_W1:
target_code = NPHY_RSSICAL_W1_TARGET;
break;
case NPHY_RSSI_SEL_W2:
target_code = NPHY_RSSICAL_W2_TARGET;
break;
default:
return;
}
classif_state = wlc_phy_classifier_nphy(pi, 0, 0);
wlc_phy_classifier_nphy(pi, (0x7 << 0), 4);
wlc_phy_clip_det_nphy(pi, 0, clip_state);
wlc_phy_clip_det_nphy(pi, 1, clip_off);
rf_pd_val = (rssi_type == NPHY_RSSI_SEL_NB) ? 0x6 : 0x4;
rfctrlintc_override_val =
CHSPEC_IS5G(pi->radio_chanspec) ? 0x140 : 0x110;
rfctrlintc_state[0] = read_phy_reg(pi, 0x91);
rfpdcorerxtx_state[0] = read_radio_reg(pi, RADIO_2055_PD_CORE1_RXTX);
write_phy_reg(pi, 0x91, rfctrlintc_override_val);
write_radio_reg(pi, RADIO_2055_PD_CORE1_RXTX, rf_pd_val);
rfctrlintc_state[1] = read_phy_reg(pi, 0x92);
rfpdcorerxtx_state[1] = read_radio_reg(pi, RADIO_2055_PD_CORE2_RXTX);
write_phy_reg(pi, 0x92, rfctrlintc_override_val);
write_radio_reg(pi, RADIO_2055_PD_CORE2_RXTX, rf_pd_val);
pd_mask = RADIO_2055_NBRSSI_PD | RADIO_2055_WBRSSI_G1_PD |
RADIO_2055_WBRSSI_G2_PD;
pd_state[0] =
read_radio_reg(pi, RADIO_2055_PD_CORE1_RSSI_MISC) & pd_mask;
pd_state[1] =
read_radio_reg(pi, RADIO_2055_PD_CORE2_RSSI_MISC) & pd_mask;
mod_radio_reg(pi, RADIO_2055_PD_CORE1_RSSI_MISC, pd_mask, 0);
mod_radio_reg(pi, RADIO_2055_PD_CORE2_RSSI_MISC, pd_mask, 0);
rssi_ctrl_mask = RADIO_2055_NBRSSI_SEL | RADIO_2055_WBRSSI_G1_SEL |
RADIO_2055_WBRSSI_G2_SEL;
rssi_ctrl_state[0] =
read_radio_reg(pi, RADIO_2055_SP_RSSI_CORE1) & rssi_ctrl_mask;
rssi_ctrl_state[1] =
read_radio_reg(pi, RADIO_2055_SP_RSSI_CORE2) & rssi_ctrl_mask;
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_ALLRX, rssi_type);
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0, RADIO_MIMO_CORESEL_ALLRX,
NPHY_RAIL_I, rssi_type);
wlc_phy_scale_offset_rssi_nphy(pi, 0x0, 0x0, RADIO_MIMO_CORESEL_ALLRX,
NPHY_RAIL_Q, rssi_type);
for (vcm = 0; vcm < 4; vcm++) {
vcm_tmp[0] = vcm_tmp[1] = vcm_tmp[2] = vcm_tmp[3] = vcm;
if (rssi_type != NPHY_RSSI_SEL_W2)
wlc_phy_set_rssi_2055_vcm(pi, rssi_type, vcm_tmp);
wlc_phy_poll_rssi_nphy(pi, rssi_type, &poll_results[vcm][0],
NPHY_RSSICAL_NPOLL);
if ((rssi_type == NPHY_RSSI_SEL_W1)
|| (rssi_type == NPHY_RSSI_SEL_W2)) {
for (ctr = 0; ctr < 2; ctr++)
poll_miniq[vcm][ctr] =
min(poll_results[vcm][ctr * 2 + 0],
poll_results[vcm][ctr * 2 + 1]);
}
}
for (result_idx = 0; result_idx < 4; result_idx++) {
min_d = NPHY_RSSICAL_MAXD;
min_vcm = 0;
min_poll = NPHY_RSSICAL_MAXREAD * NPHY_RSSICAL_NPOLL + 1;
for (vcm = 0; vcm < 4; vcm++) {
curr_d = abs(((rssi_type == NPHY_RSSI_SEL_NB) ?
poll_results[vcm][result_idx] :
poll_miniq[vcm][result_idx / 2]) -
(target_code * NPHY_RSSICAL_NPOLL));
if (curr_d < min_d) {
min_d = curr_d;
min_vcm = vcm;
}
if (poll_results[vcm][result_idx] < min_poll)
min_poll = poll_results[vcm][result_idx];
}
vcm_final[result_idx] = min_vcm;
poll_results_min[result_idx] = min_poll;
}
if (rssi_type != NPHY_RSSI_SEL_W2)
wlc_phy_set_rssi_2055_vcm(pi, rssi_type, vcm_final);
for (result_idx = 0; result_idx < 4; result_idx++) {
fine_digital_offset[result_idx] =
(target_code * NPHY_RSSICAL_NPOLL) -
poll_results[vcm_final[result_idx]][result_idx];
if (fine_digital_offset[result_idx] < 0) {
fine_digital_offset[result_idx] =
abs(fine_digital_offset[result_idx]);
fine_digital_offset[result_idx] +=
(NPHY_RSSICAL_NPOLL / 2);
fine_digital_offset[result_idx] /= NPHY_RSSICAL_NPOLL;
fine_digital_offset[result_idx] =
-fine_digital_offset[result_idx];
} else {
fine_digital_offset[result_idx] +=
(NPHY_RSSICAL_NPOLL / 2);
fine_digital_offset[result_idx] /= NPHY_RSSICAL_NPOLL;
}
if (poll_results_min[result_idx] ==
NPHY_RSSICAL_MAXREAD * NPHY_RSSICAL_NPOLL)
fine_digital_offset[result_idx] =
(target_code - NPHY_RSSICAL_MAXREAD - 1);
wlc_phy_scale_offset_rssi_nphy(pi, 0x0,
(s8)
fine_digital_offset[result_idx],
(result_idx / 2 ==
0) ? RADIO_MIMO_CORESEL_CORE1 :
RADIO_MIMO_CORESEL_CORE2,
(result_idx % 2 ==
0) ? NPHY_RAIL_I : NPHY_RAIL_Q,
rssi_type);
}
mod_radio_reg(pi, RADIO_2055_PD_CORE1_RSSI_MISC, pd_mask, pd_state[0]);
mod_radio_reg(pi, RADIO_2055_PD_CORE2_RSSI_MISC, pd_mask, pd_state[1]);
if (rssi_ctrl_state[0] == RADIO_2055_NBRSSI_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE1,
NPHY_RSSI_SEL_NB);
else if (rssi_ctrl_state[0] == RADIO_2055_WBRSSI_G1_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE1,
NPHY_RSSI_SEL_W1);
else if (rssi_ctrl_state[0] == RADIO_2055_WBRSSI_G2_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE1,
NPHY_RSSI_SEL_W2);
else
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE1,
NPHY_RSSI_SEL_W2);
if (rssi_ctrl_state[1] == RADIO_2055_NBRSSI_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE2,
NPHY_RSSI_SEL_NB);
else if (rssi_ctrl_state[1] == RADIO_2055_WBRSSI_G1_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE2,
NPHY_RSSI_SEL_W1);
else if (rssi_ctrl_state[1] == RADIO_2055_WBRSSI_G2_SEL)
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE2,
NPHY_RSSI_SEL_W2);
else
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_CORE2,
NPHY_RSSI_SEL_W2);
wlc_phy_rssisel_nphy(pi, RADIO_MIMO_CORESEL_OFF, rssi_type);
write_phy_reg(pi, 0x91, rfctrlintc_state[0]);
write_radio_reg(pi, RADIO_2055_PD_CORE1_RXTX, rfpdcorerxtx_state[0]);
write_phy_reg(pi, 0x92, rfctrlintc_state[1]);
write_radio_reg(pi, RADIO_2055_PD_CORE2_RXTX, rfpdcorerxtx_state[1]);
wlc_phy_classifier_nphy(pi, (0x7 << 0), classif_state);
wlc_phy_clip_det_nphy(pi, 1, clip_state);
wlc_phy_resetcca_nphy(pi);
}
void wlc_phy_rssi_cal_nphy(struct brcms_phy *pi)
{
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
wlc_phy_rssi_cal_nphy_rev3(pi);
} else {
wlc_phy_rssi_cal_nphy_rev2(pi, NPHY_RSSI_SEL_NB);
wlc_phy_rssi_cal_nphy_rev2(pi, NPHY_RSSI_SEL_W1);
wlc_phy_rssi_cal_nphy_rev2(pi, NPHY_RSSI_SEL_W2);
}
}
int
wlc_phy_rssi_compute_nphy(struct brcms_phy *pi, struct d11rxhdr *rxh)
{
s16 rxpwr, rxpwr0, rxpwr1;
s16 phyRx0_l, phyRx2_l;
rxpwr = 0;
rxpwr0 = rxh->PhyRxStatus_1 & PRXS1_nphy_PWR0_MASK;
rxpwr1 = (rxh->PhyRxStatus_1 & PRXS1_nphy_PWR1_MASK) >> 8;
if (rxpwr0 > 127)
rxpwr0 -= 256;
if (rxpwr1 > 127)
rxpwr1 -= 256;
phyRx0_l = rxh->PhyRxStatus_0 & 0x00ff;
phyRx2_l = rxh->PhyRxStatus_2 & 0x00ff;
if (phyRx2_l > 127)
phyRx2_l -= 256;
if (((rxpwr0 == 16) || (rxpwr0 == 32))) {
rxpwr0 = rxpwr1;
rxpwr1 = phyRx2_l;
}
if (pi->sh->rssi_mode == RSSI_ANT_MERGE_MAX)
rxpwr = (rxpwr0 > rxpwr1) ? rxpwr0 : rxpwr1;
else if (pi->sh->rssi_mode == RSSI_ANT_MERGE_MIN)
rxpwr = (rxpwr0 < rxpwr1) ? rxpwr0 : rxpwr1;
else if (pi->sh->rssi_mode == RSSI_ANT_MERGE_AVG)
rxpwr = (rxpwr0 + rxpwr1) >> 1;
return rxpwr;
}
static void
wlc_phy_loadsampletable_nphy(struct brcms_phy *pi, struct cordic_iq *tone_buf,
u16 num_samps)
{
u16 t;
u32 *data_buf = NULL;
data_buf = kmalloc(sizeof(u32) * num_samps, GFP_ATOMIC);
if (data_buf == NULL)
return;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
for (t = 0; t < num_samps; t++)
data_buf[t] = ((((unsigned int)tone_buf[t].i) & 0x3ff) << 10) |
(((unsigned int)tone_buf[t].q) & 0x3ff);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_SAMPLEPLAY, num_samps, 0, 32,
data_buf);
kfree(data_buf);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static u16
wlc_phy_gen_load_samples_nphy(struct brcms_phy *pi, u32 f_kHz, u16 max_val,
u8 dac_test_mode)
{
u8 phy_bw, is_phybw40;
u16 num_samps, t, spur;
s32 theta = 0, rot = 0;
u32 tbl_len;
struct cordic_iq *tone_buf = NULL;
is_phybw40 = CHSPEC_IS40(pi->radio_chanspec);
phy_bw = (is_phybw40 == 1) ? 40 : 20;
tbl_len = (phy_bw << 3);
if (dac_test_mode == 1) {
spur = read_phy_reg(pi, 0x01);
spur = (spur >> 15) & 1;
phy_bw = (spur == 1) ? 82 : 80;
phy_bw = (is_phybw40 == 1) ? (phy_bw << 1) : phy_bw;
tbl_len = (phy_bw << 1);
}
tone_buf = kmalloc(sizeof(struct cordic_iq) * tbl_len, GFP_ATOMIC);
if (tone_buf == NULL)
return 0;
num_samps = (u16) tbl_len;
rot = ((f_kHz * 36) / phy_bw) / 100;
theta = 0;
for (t = 0; t < num_samps; t++) {
tone_buf[t] = cordic_calc_iq(theta);
theta += rot;
tone_buf[t].q = (s32) FLOAT(tone_buf[t].q * max_val);
tone_buf[t].i = (s32) FLOAT(tone_buf[t].i * max_val);
}
wlc_phy_loadsampletable_nphy(pi, tone_buf, num_samps);
kfree(tone_buf);
return num_samps;
}
static void
wlc_phy_runsamples_nphy(struct brcms_phy *pi, u16 num_samps, u16 loops,
u16 wait, u8 iqmode, u8 dac_test_mode,
bool modify_bbmult)
{
u16 bb_mult;
u8 phy_bw, sample_cmd;
u16 orig_RfseqCoreActv;
u16 lpf_bw_ctl_override3, lpf_bw_ctl_override4, lpf_bw_ctl_miscreg3,
lpf_bw_ctl_miscreg4;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
phy_bw = 20;
if (CHSPEC_IS40(pi->radio_chanspec))
phy_bw = 40;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
lpf_bw_ctl_override3 = read_phy_reg(pi, 0x342) & (0x1 << 7);
lpf_bw_ctl_override4 = read_phy_reg(pi, 0x343) & (0x1 << 7);
if (lpf_bw_ctl_override3 | lpf_bw_ctl_override4) {
lpf_bw_ctl_miscreg3 = read_phy_reg(pi, 0x340) &
(0x7 << 8);
lpf_bw_ctl_miscreg4 = read_phy_reg(pi, 0x341) &
(0x7 << 8);
} else {
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 7),
wlc_phy_read_lpf_bw_ctl_nphy
(pi,
0), 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
pi->nphy_sample_play_lpf_bw_ctl_ovr = true;
lpf_bw_ctl_miscreg3 = read_phy_reg(pi, 0x340) &
(0x7 << 8);
lpf_bw_ctl_miscreg4 = read_phy_reg(pi, 0x341) &
(0x7 << 8);
}
}
if ((pi->nphy_bb_mult_save & BB_MULT_VALID_MASK) == 0) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL, 1, 87, 16,
&bb_mult);
pi->nphy_bb_mult_save =
BB_MULT_VALID_MASK | (bb_mult & BB_MULT_MASK);
}
if (modify_bbmult) {
bb_mult = (phy_bw == 20) ? 100 : 71;
bb_mult = (bb_mult << 8) + bb_mult;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 1, 87, 16,
&bb_mult);
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
write_phy_reg(pi, 0xc6, num_samps - 1);
if (loops != 0xffff)
write_phy_reg(pi, 0xc4, loops - 1);
else
write_phy_reg(pi, 0xc4, loops);
write_phy_reg(pi, 0xc5, wait);
orig_RfseqCoreActv = read_phy_reg(pi, 0xa1);
or_phy_reg(pi, 0xa1, NPHY_RfseqMode_CoreActv_override);
if (iqmode) {
and_phy_reg(pi, 0xc2, 0x7FFF);
or_phy_reg(pi, 0xc2, 0x8000);
} else {
sample_cmd = (dac_test_mode == 1) ? 0x5 : 0x1;
write_phy_reg(pi, 0xc3, sample_cmd);
}
SPINWAIT(((read_phy_reg(pi, 0xa4) & 0x1) == 1), 1000);
write_phy_reg(pi, 0xa1, orig_RfseqCoreActv);
}
int
wlc_phy_tx_tone_nphy(struct brcms_phy *pi, u32 f_kHz, u16 max_val,
u8 iqmode, u8 dac_test_mode, bool modify_bbmult)
{
u16 num_samps;
u16 loops = 0xffff;
u16 wait = 0;
num_samps = wlc_phy_gen_load_samples_nphy(pi, f_kHz, max_val,
dac_test_mode);
if (num_samps == 0)
return -EBADE;
wlc_phy_runsamples_nphy(pi, num_samps, loops, wait, iqmode,
dac_test_mode, modify_bbmult);
return 0;
}
void wlc_phy_stopplayback_nphy(struct brcms_phy *pi)
{
u16 playback_status;
u16 bb_mult;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
playback_status = read_phy_reg(pi, 0xc7);
if (playback_status & 0x1)
or_phy_reg(pi, 0xc3, NPHY_sampleCmd_STOP);
else if (playback_status & 0x2)
and_phy_reg(pi, 0xc2,
(u16) ~NPHY_iqloCalCmdGctl_IQLO_CAL_EN);
and_phy_reg(pi, 0xc3, (u16) ~(0x1 << 2));
if ((pi->nphy_bb_mult_save & BB_MULT_VALID_MASK) != 0) {
bb_mult = pi->nphy_bb_mult_save & BB_MULT_MASK;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 1, 87, 16,
&bb_mult);
pi->nphy_bb_mult_save = 0;
}
if (NREV_IS(pi->pubpi.phy_rev, 7) || NREV_GE(pi->pubpi.phy_rev, 8)) {
if (pi->nphy_sample_play_lpf_bw_ctl_ovr) {
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 7),
0, 0, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
pi->nphy_sample_play_lpf_bw_ctl_ovr = false;
}
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static u32 *brcms_phy_get_tx_pwrctrl_tbl(struct brcms_phy *pi)
{
u32 *tx_pwrctrl_tbl = NULL;
uint phyrev = pi->pubpi.phy_rev;
if (PHY_IPA(pi)) {
tx_pwrctrl_tbl =
wlc_phy_get_ipa_gaintbl_nphy(pi);
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_IS(phyrev, 3))
tx_pwrctrl_tbl = nphy_tpc_5GHz_txgain_rev3;
else if (NREV_IS(phyrev, 4))
tx_pwrctrl_tbl =
(pi->srom_fem5g.extpagain == 3) ?
nphy_tpc_5GHz_txgain_HiPwrEPA :
nphy_tpc_5GHz_txgain_rev4;
else
tx_pwrctrl_tbl = nphy_tpc_5GHz_txgain_rev5;
} else {
if (NREV_GE(phyrev, 7)) {
if (pi->pubpi.radiorev == 3)
tx_pwrctrl_tbl =
nphy_tpc_txgain_epa_2057rev3;
else if (pi->pubpi.radiorev == 5)
tx_pwrctrl_tbl =
nphy_tpc_txgain_epa_2057rev5;
} else {
if (NREV_GE(phyrev, 5) &&
(pi->srom_fem2g.extpagain == 3))
tx_pwrctrl_tbl =
nphy_tpc_txgain_HiPwrEPA;
else
tx_pwrctrl_tbl =
nphy_tpc_txgain_rev3;
}
}
}
return tx_pwrctrl_tbl;
}
struct nphy_txgains wlc_phy_get_tx_gain_nphy(struct brcms_phy *pi)
{
u16 base_idx[2], curr_gain[2];
u8 core_no;
struct nphy_txgains target_gain;
u32 *tx_pwrctrl_tbl = NULL;
if (pi->nphy_txpwrctrl == PHY_TPC_HW_OFF) {
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
curr_gain);
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
for (core_no = 0; core_no < 2; core_no++) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
target_gain.ipa[core_no] =
curr_gain[core_no] & 0x0007;
target_gain.pad[core_no] =
((curr_gain[core_no] & 0x00F8) >> 3);
target_gain.pga[core_no] =
((curr_gain[core_no] & 0x0F00) >> 8);
target_gain.txgm[core_no] =
((curr_gain[core_no] & 0x7000) >> 12);
target_gain.txlpf[core_no] =
((curr_gain[core_no] & 0x8000) >> 15);
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
target_gain.ipa[core_no] =
curr_gain[core_no] & 0x000F;
target_gain.pad[core_no] =
((curr_gain[core_no] & 0x00F0) >> 4);
target_gain.pga[core_no] =
((curr_gain[core_no] & 0x0F00) >> 8);
target_gain.txgm[core_no] =
((curr_gain[core_no] & 0x7000) >> 12);
} else {
target_gain.ipa[core_no] =
curr_gain[core_no] & 0x0003;
target_gain.pad[core_no] =
((curr_gain[core_no] & 0x000C) >> 2);
target_gain.pga[core_no] =
((curr_gain[core_no] & 0x0070) >> 4);
target_gain.txgm[core_no] =
((curr_gain[core_no] & 0x0380) >> 7);
}
}
} else {
uint phyrev = pi->pubpi.phy_rev;
base_idx[0] = (read_phy_reg(pi, 0x1ed) >> 8) & 0x7f;
base_idx[1] = (read_phy_reg(pi, 0x1ee) >> 8) & 0x7f;
for (core_no = 0; core_no < 2; core_no++) {
if (NREV_GE(phyrev, 3)) {
tx_pwrctrl_tbl =
brcms_phy_get_tx_pwrctrl_tbl(pi);
if (NREV_GE(phyrev, 7)) {
target_gain.ipa[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 16) & 0x7;
target_gain.pad[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 19) & 0x1f;
target_gain.pga[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 24) & 0xf;
target_gain.txgm[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 28) & 0x7;
target_gain.txlpf[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 31) & 0x1;
} else {
target_gain.ipa[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 16) & 0xf;
target_gain.pad[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 20) & 0xf;
target_gain.pga[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 24) & 0xf;
target_gain.txgm[core_no] =
(tx_pwrctrl_tbl
[base_idx[core_no]]
>> 28) & 0x7;
}
} else {
target_gain.ipa[core_no] =
(nphy_tpc_txgain[base_idx[core_no]] >>
16) & 0x3;
target_gain.pad[core_no] =
(nphy_tpc_txgain[base_idx[core_no]] >>
18) & 0x3;
target_gain.pga[core_no] =
(nphy_tpc_txgain[base_idx[core_no]] >>
20) & 0x7;
target_gain.txgm[core_no] =
(nphy_tpc_txgain[base_idx[core_no]] >>
23) & 0x7;
}
}
}
return target_gain;
}
static void
wlc_phy_iqcal_gainparams_nphy(struct brcms_phy *pi, u16 core_no,
struct nphy_txgains target_gain,
struct nphy_iqcal_params *params)
{
u8 k;
int idx;
u16 gain_index;
u8 band_idx = (CHSPEC_IS5G(pi->radio_chanspec) ? 1 : 0);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (NREV_GE(pi->pubpi.phy_rev, 7))
params->txlpf = target_gain.txlpf[core_no];
params->txgm = target_gain.txgm[core_no];
params->pga = target_gain.pga[core_no];
params->pad = target_gain.pad[core_no];
params->ipa = target_gain.ipa[core_no];
if (NREV_GE(pi->pubpi.phy_rev, 7))
params->cal_gain =
((params->txlpf << 15) | (params->txgm << 12) |
(params->pga << 8) |
(params->pad << 3) | (params->ipa));
else
params->cal_gain =
((params->txgm << 12) | (params->pga << 8) |
(params->pad << 4) | (params->ipa));
params->ncorr[0] = 0x79;
params->ncorr[1] = 0x79;
params->ncorr[2] = 0x79;
params->ncorr[3] = 0x79;
params->ncorr[4] = 0x79;
} else {
gain_index = ((target_gain.pad[core_no] << 0) |
(target_gain.pga[core_no] << 4) |
(target_gain.txgm[core_no] << 8));
idx = -1;
for (k = 0; k < NPHY_IQCAL_NUMGAINS; k++) {
if (tbl_iqcal_gainparams_nphy[band_idx][k][0] ==
gain_index) {
idx = k;
break;
}
}
params->txgm = tbl_iqcal_gainparams_nphy[band_idx][k][1];
params->pga = tbl_iqcal_gainparams_nphy[band_idx][k][2];
params->pad = tbl_iqcal_gainparams_nphy[band_idx][k][3];
params->cal_gain = ((params->txgm << 7) | (params->pga << 4) |
(params->pad << 2));
params->ncorr[0] = tbl_iqcal_gainparams_nphy[band_idx][k][4];
params->ncorr[1] = tbl_iqcal_gainparams_nphy[band_idx][k][5];
params->ncorr[2] = tbl_iqcal_gainparams_nphy[band_idx][k][6];
params->ncorr[3] = tbl_iqcal_gainparams_nphy[band_idx][k][7];
}
}
static void wlc_phy_txcal_radio_setup_nphy(struct brcms_phy *pi)
{
u16 jtag_core, core;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (core = 0; core <= 1; core++) {
pi->tx_rx_cal_radio_saveregs[(core * 11) + 0] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 1] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_VCM_HG);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 2] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_IDAC);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 3] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_VCM);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 4] = 0;
pi->tx_rx_cal_radio_saveregs[(core * 11) + 5] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MUX);
if (pi->pubpi.radiorev != 5)
pi->tx_rx_cal_radio_saveregs[(core * 11) + 6] =
READ_RADIO_REG3(pi, RADIO_2057, TX,
core,
TSSIA);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 7] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core, TSSIG);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 8] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_MISC1);
if (CHSPEC_IS5G(pi->radio_chanspec)) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER, 0x0a);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_VCM_HG, 0x43);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_IDAC, 0x55);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_VCM, 0x00);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSIG, 0x00);
if (pi->use_int_tx_iqlo_cal_nphy) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TX_SSI_MUX, 0x4);
if (!(pi->
internal_tx_iqlo_cal_tapoff_intpa_nphy))
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIA, 0x31);
else
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIA, 0x21);
}
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_MISC1, 0x00);
} else {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER, 0x06);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_VCM_HG, 0x43);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
IQCAL_IDAC, 0x55);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_VCM, 0x00);
if (pi->pubpi.radiorev != 5)
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TSSIA, 0x00);
if (pi->use_int_tx_iqlo_cal_nphy) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX,
core, TX_SSI_MUX,
0x06);
if (!(pi->
internal_tx_iqlo_cal_tapoff_intpa_nphy))
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIG, 0x31);
else
WRITE_RADIO_REG3(pi, RADIO_2057,
TX, core,
TSSIG, 0x21);
}
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSI_MISC1, 0x00);
}
}
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
for (core = 0; core <= 1; core++) {
jtag_core =
(core ==
PHY_CORE_0) ? RADIO_2056_TX0 : RADIO_2056_TX1;
pi->tx_rx_cal_radio_saveregs[(core * 11) + 0] =
read_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MASTER |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 1] =
read_radio_reg(pi,
RADIO_2056_TX_IQCAL_VCM_HG |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 2] =
read_radio_reg(pi,
RADIO_2056_TX_IQCAL_IDAC |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 3] =
read_radio_reg(
pi,
RADIO_2056_TX_TSSI_VCM |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 4] =
read_radio_reg(pi,
RADIO_2056_TX_TX_AMP_DET |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 5] =
read_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MUX |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 6] =
read_radio_reg(pi,
RADIO_2056_TX_TSSIA | jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 7] =
read_radio_reg(pi,
RADIO_2056_TX_TSSIG | jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 8] =
read_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC1 |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 9] =
read_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC2 |
jtag_core);
pi->tx_rx_cal_radio_saveregs[(core * 11) + 10] =
read_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC3 |
jtag_core);
if (CHSPEC_IS5G(pi->radio_chanspec)) {
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MASTER |
jtag_core, 0x0a);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_VCM_HG |
jtag_core, 0x40);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_IDAC |
jtag_core, 0x55);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_VCM |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TX_AMP_DET |
jtag_core, 0x00);
if (PHY_IPA(pi)) {
write_radio_reg(
pi,
RADIO_2056_TX_TX_SSI_MUX
| jtag_core, 0x4);
write_radio_reg(pi,
RADIO_2056_TX_TSSIA |
jtag_core, 0x1);
} else {
write_radio_reg(
pi,
RADIO_2056_TX_TX_SSI_MUX
| jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSIA |
jtag_core, 0x2f);
}
write_radio_reg(pi,
RADIO_2056_TX_TSSIG | jtag_core,
0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC1 |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC2 |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC3 |
jtag_core, 0x00);
} else {
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MASTER |
jtag_core, 0x06);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_VCM_HG |
jtag_core, 0x40);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_IDAC |
jtag_core, 0x55);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_VCM |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TX_AMP_DET |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSIA | jtag_core,
0x00);
if (PHY_IPA(pi)) {
write_radio_reg(
pi,
RADIO_2056_TX_TX_SSI_MUX
| jtag_core, 0x06);
if (NREV_LT(pi->pubpi.phy_rev, 5))
write_radio_reg(
pi,
RADIO_2056_TX_TSSIG
| jtag_core,
0x11);
else
write_radio_reg(
pi,
RADIO_2056_TX_TSSIG
| jtag_core,
0x1);
} else {
write_radio_reg(
pi,
RADIO_2056_TX_TX_SSI_MUX
| jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSIG |
jtag_core, 0x20);
}
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC1 |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC2 |
jtag_core, 0x00);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC3 |
jtag_core, 0x00);
}
}
} else {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1, 0x29);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2, 0x54);
pi->tx_rx_cal_radio_saveregs[2] =
read_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1, 0x29);
pi->tx_rx_cal_radio_saveregs[3] =
read_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2, 0x54);
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1);
pi->tx_rx_cal_radio_saveregs[5] =
read_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2);
if ((read_phy_reg(pi, 0x09) & NPHY_BandControl_currentBand) ==
0) {
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1, 0x04);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2, 0x04);
} else {
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1, 0x20);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2, 0x20);
}
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
or_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM, 0x20);
or_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM, 0x20);
} else {
and_radio_reg(pi, RADIO_2055_CORE1_TX_BB_MXGM, 0xdf);
and_radio_reg(pi, RADIO_2055_CORE2_TX_BB_MXGM, 0xdf);
}
}
}
static void wlc_phy_txcal_radio_cleanup_nphy(struct brcms_phy *pi)
{
u16 jtag_core, core;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (core = 0; core <= 1; core++) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TX_SSI_MASTER,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
0]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, IQCAL_VCM_HG,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
1]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, IQCAL_IDAC,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
2]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TSSI_VCM,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
3]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TX_SSI_MUX,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
5]);
if (pi->pubpi.radiorev != 5)
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TSSIA,
pi->tx_rx_cal_radio_saveregs
[(core * 11) + 6]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TSSIG,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
7]);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core, TSSI_MISC1,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
8]);
}
} else if (NREV_GE(pi->pubpi.phy_rev, 3)) {
for (core = 0; core <= 1; core++) {
jtag_core = (core == PHY_CORE_0) ?
RADIO_2056_TX0 : RADIO_2056_TX1;
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MASTER | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
0]);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_VCM_HG | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
1]);
write_radio_reg(pi,
RADIO_2056_TX_IQCAL_IDAC | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
2]);
write_radio_reg(pi, RADIO_2056_TX_TSSI_VCM | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
3]);
write_radio_reg(pi,
RADIO_2056_TX_TX_AMP_DET | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
4]);
write_radio_reg(pi,
RADIO_2056_TX_TX_SSI_MUX | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
5]);
write_radio_reg(pi, RADIO_2056_TX_TSSIA | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
6]);
write_radio_reg(pi, RADIO_2056_TX_TSSIG | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
7]);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC1 | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
8]);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC2 | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
9]);
write_radio_reg(pi,
RADIO_2056_TX_TSSI_MISC3 | jtag_core,
pi->
tx_rx_cal_radio_saveregs[(core * 11) +
10]);
}
} else {
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL1,
pi->tx_rx_cal_radio_saveregs[0]);
write_radio_reg(pi, RADIO_2055_CORE1_TXRF_IQCAL2,
pi->tx_rx_cal_radio_saveregs[1]);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL1,
pi->tx_rx_cal_radio_saveregs[2]);
write_radio_reg(pi, RADIO_2055_CORE2_TXRF_IQCAL2,
pi->tx_rx_cal_radio_saveregs[3]);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE1,
pi->tx_rx_cal_radio_saveregs[4]);
write_radio_reg(pi, RADIO_2055_PWRDET_RXTX_CORE2,
pi->tx_rx_cal_radio_saveregs[5]);
}
}
static void wlc_phy_txcal_physetup_nphy(struct brcms_phy *pi)
{
u16 val, mask;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
pi->tx_rx_cal_phy_saveregs[0] = read_phy_reg(pi, 0xa6);
pi->tx_rx_cal_phy_saveregs[1] = read_phy_reg(pi, 0xa7);
mask = ((0x3 << 8) | (0x3 << 10));
val = (0x2 << 8);
val |= (0x2 << 10);
mod_phy_reg(pi, 0xa6, mask, val);
mod_phy_reg(pi, 0xa7, mask, val);
val = read_phy_reg(pi, 0x8f);
pi->tx_rx_cal_phy_saveregs[2] = val;
val |= ((0x1 << 9) | (0x1 << 10));
write_phy_reg(pi, 0x8f, val);
val = read_phy_reg(pi, 0xa5);
pi->tx_rx_cal_phy_saveregs[3] = val;
val |= ((0x1 << 9) | (0x1 << 10));
write_phy_reg(pi, 0xa5, val);
pi->tx_rx_cal_phy_saveregs[4] = read_phy_reg(pi, 0x01);
mod_phy_reg(pi, 0x01, (0x1 << 15), 0);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 3, 16,
&val);
pi->tx_rx_cal_phy_saveregs[5] = val;
val = 0;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 3, 16,
&val);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 19, 16,
&val);
pi->tx_rx_cal_phy_saveregs[6] = val;
val = 0;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 19, 16,
&val);
pi->tx_rx_cal_phy_saveregs[7] = read_phy_reg(pi, 0x91);
pi->tx_rx_cal_phy_saveregs[8] = read_phy_reg(pi, 0x92);
if (!(pi->use_int_tx_iqlo_cal_nphy))
wlc_phy_rfctrlintc_override_nphy(
pi,
NPHY_RfctrlIntc_override_PA,
1,
RADIO_MIMO_CORESEL_CORE1
|
RADIO_MIMO_CORESEL_CORE2);
else
wlc_phy_rfctrlintc_override_nphy(
pi,
NPHY_RfctrlIntc_override_PA,
0,
RADIO_MIMO_CORESEL_CORE1
|
RADIO_MIMO_CORESEL_CORE2);
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x2, RADIO_MIMO_CORESEL_CORE1);
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x8, RADIO_MIMO_CORESEL_CORE2);
pi->tx_rx_cal_phy_saveregs[9] = read_phy_reg(pi, 0x297);
pi->tx_rx_cal_phy_saveregs[10] = read_phy_reg(pi, 0x29b);
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
if (NREV_IS(pi->pubpi.phy_rev, 7)
|| NREV_GE(pi->pubpi.phy_rev, 8))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 7),
wlc_phy_read_lpf_bw_ctl_nphy
(pi,
0), 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
if (pi->use_int_tx_iqlo_cal_nphy
&& !(pi->internal_tx_iqlo_cal_tapoff_intpa_nphy)) {
if (NREV_IS(pi->pubpi.phy_rev, 7)) {
mod_radio_reg(pi, RADIO_2057_OVR_REG0, 1 << 4,
1 << 4);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
mod_radio_reg(
pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE0,
1, 0);
mod_radio_reg(
pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE1,
1, 0);
} else {
mod_radio_reg(
pi,
RADIO_2057_IPA5G_CASCOFFV_PU_CORE0,
1, 0);
mod_radio_reg(
pi,
RADIO_2057_IPA5G_CASCOFFV_PU_CORE1,
1, 0);
}
} else if (NREV_GE(pi->pubpi.phy_rev, 8)) {
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 3), 0,
0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
}
}
} else {
pi->tx_rx_cal_phy_saveregs[0] = read_phy_reg(pi, 0xa6);
pi->tx_rx_cal_phy_saveregs[1] = read_phy_reg(pi, 0xa7);
mask = ((0x3 << 12) | (0x3 << 14));
val = (0x2 << 12);
val |= (0x2 << 14);
mod_phy_reg(pi, 0xa6, mask, val);
mod_phy_reg(pi, 0xa7, mask, val);
val = read_phy_reg(pi, 0xa5);
pi->tx_rx_cal_phy_saveregs[2] = val;
val |= ((0x1 << 12) | (0x1 << 13));
write_phy_reg(pi, 0xa5, val);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 2, 16,
&val);
pi->tx_rx_cal_phy_saveregs[3] = val;
val |= 0x2000;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 2, 16,
&val);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 18, 16,
&val);
pi->tx_rx_cal_phy_saveregs[4] = val;
val |= 0x2000;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 18, 16,
&val);
pi->tx_rx_cal_phy_saveregs[5] = read_phy_reg(pi, 0x91);
pi->tx_rx_cal_phy_saveregs[6] = read_phy_reg(pi, 0x92);
val = CHSPEC_IS5G(pi->radio_chanspec) ? 0x180 : 0x120;
write_phy_reg(pi, 0x91, val);
write_phy_reg(pi, 0x92, val);
}
}
static void wlc_phy_txcal_phycleanup_nphy(struct brcms_phy *pi)
{
u16 mask;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
write_phy_reg(pi, 0xa6, pi->tx_rx_cal_phy_saveregs[0]);
write_phy_reg(pi, 0xa7, pi->tx_rx_cal_phy_saveregs[1]);
write_phy_reg(pi, 0x8f, pi->tx_rx_cal_phy_saveregs[2]);
write_phy_reg(pi, 0xa5, pi->tx_rx_cal_phy_saveregs[3]);
write_phy_reg(pi, 0x01, pi->tx_rx_cal_phy_saveregs[4]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 3, 16,
&pi->tx_rx_cal_phy_saveregs[5]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 19, 16,
&pi->tx_rx_cal_phy_saveregs[6]);
write_phy_reg(pi, 0x91, pi->tx_rx_cal_phy_saveregs[7]);
write_phy_reg(pi, 0x92, pi->tx_rx_cal_phy_saveregs[8]);
write_phy_reg(pi, 0x297, pi->tx_rx_cal_phy_saveregs[9]);
write_phy_reg(pi, 0x29b, pi->tx_rx_cal_phy_saveregs[10]);
if (NREV_IS(pi->pubpi.phy_rev, 7)
|| NREV_GE(pi->pubpi.phy_rev, 8))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 7), 0, 0,
1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_resetcca_nphy(pi);
if (pi->use_int_tx_iqlo_cal_nphy
&& !(pi->internal_tx_iqlo_cal_tapoff_intpa_nphy)) {
if (NREV_IS(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
mod_radio_reg(
pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE0,
1, 1);
mod_radio_reg(
pi,
RADIO_2057_PAD2G_TUNE_PUS_CORE1,
1, 1);
} else {
mod_radio_reg(
pi,
RADIO_2057_IPA5G_CASCOFFV_PU_CORE0,
1, 1);
mod_radio_reg(
pi,
RADIO_2057_IPA5G_CASCOFFV_PU_CORE1,
1, 1);
}
mod_radio_reg(pi, RADIO_2057_OVR_REG0, 1 << 4,
0);
} else if (NREV_GE(pi->pubpi.phy_rev, 8)) {
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 3), 0,
0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
}
}
} else {
mask = ((0x3 << 12) | (0x3 << 14));
mod_phy_reg(pi, 0xa6, mask, pi->tx_rx_cal_phy_saveregs[0]);
mod_phy_reg(pi, 0xa7, mask, pi->tx_rx_cal_phy_saveregs[1]);
write_phy_reg(pi, 0xa5, pi->tx_rx_cal_phy_saveregs[2]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 2, 16,
&pi->tx_rx_cal_phy_saveregs[3]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_AFECTRL, 1, 18, 16,
&pi->tx_rx_cal_phy_saveregs[4]);
write_phy_reg(pi, 0x91, pi->tx_rx_cal_phy_saveregs[5]);
write_phy_reg(pi, 0x92, pi->tx_rx_cal_phy_saveregs[6]);
}
}
void
wlc_phy_est_tonepwr_nphy(struct brcms_phy *pi, s32 *qdBm_pwrbuf, u8 num_samps)
{
u16 tssi_reg;
s32 temp, pwrindex[2];
s32 idle_tssi[2];
s32 rssi_buf[4];
s32 tssival[2];
u8 tssi_type;
tssi_reg = read_phy_reg(pi, 0x1e9);
temp = (s32) (tssi_reg & 0x3f);
idle_tssi[0] = (temp <= 31) ? temp : (temp - 64);
temp = (s32) ((tssi_reg >> 8) & 0x3f);
idle_tssi[1] = (temp <= 31) ? temp : (temp - 64);
tssi_type =
CHSPEC_IS5G(pi->radio_chanspec) ?
(u8)NPHY_RSSI_SEL_TSSI_5G : (u8)NPHY_RSSI_SEL_TSSI_2G;
wlc_phy_poll_rssi_nphy(pi, tssi_type, rssi_buf, num_samps);
tssival[0] = rssi_buf[0] / ((s32) num_samps);
tssival[1] = rssi_buf[2] / ((s32) num_samps);
pwrindex[0] = idle_tssi[0] - tssival[0] + 64;
pwrindex[1] = idle_tssi[1] - tssival[1] + 64;
if (pwrindex[0] < 0)
pwrindex[0] = 0;
else if (pwrindex[0] > 63)
pwrindex[0] = 63;
if (pwrindex[1] < 0)
pwrindex[1] = 0;
else if (pwrindex[1] > 63)
pwrindex[1] = 63;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_CORE1TXPWRCTL, 1,
(u32) pwrindex[0], 32, &qdBm_pwrbuf[0]);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_CORE2TXPWRCTL, 1,
(u32) pwrindex[1], 32, &qdBm_pwrbuf[1]);
}
static void wlc_phy_update_txcal_ladder_nphy(struct brcms_phy *pi, u16 core)
{
int index;
u32 bbmult_scale;
u16 bbmult;
u16 tblentry;
struct nphy_txiqcal_ladder ladder_lo[] = {
{3, 0}, {4, 0}, {6, 0}, {9, 0}, {13, 0}, {18, 0},
{25, 0}, {25, 1}, {25, 2}, {25, 3}, {25, 4}, {25, 5},
{25, 6}, {25, 7}, {35, 7}, {50, 7}, {71, 7}, {100, 7}
};
struct nphy_txiqcal_ladder ladder_iq[] = {
{3, 0}, {4, 0}, {6, 0}, {9, 0}, {13, 0}, {18, 0},
{25, 0}, {35, 0}, {50, 0}, {71, 0}, {100, 0}, {100, 1},
{100, 2}, {100, 3}, {100, 4}, {100, 5}, {100, 6}, {100, 7}
};
bbmult = (core == PHY_CORE_0) ?
((pi->nphy_txcal_bbmult >> 8) & 0xff) :
(pi->nphy_txcal_bbmult & 0xff);
for (index = 0; index < 18; index++) {
bbmult_scale = ladder_lo[index].percent * bbmult;
bbmult_scale /= 100;
tblentry =
((bbmult_scale & 0xff) << 8) | ladder_lo[index].g_env;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 1, index, 16,
&tblentry);
bbmult_scale = ladder_iq[index].percent * bbmult;
bbmult_scale /= 100;
tblentry =
((bbmult_scale & 0xff) << 8) | ladder_iq[index].g_env;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 1, index + 32,
16, &tblentry);
}
}
static u8 wlc_phy_txpwr_idx_cur_get_nphy(struct brcms_phy *pi, u8 core)
{
u16 tmp;
tmp = read_phy_reg(pi, ((core == PHY_CORE_0) ? 0x1ed : 0x1ee));
tmp = (tmp & (0x7f << 8)) >> 8;
return (u8) tmp;
}
static void
wlc_phy_txpwr_idx_cur_set_nphy(struct brcms_phy *pi, u8 idx0, u8 idx1)
{
mod_phy_reg(pi, 0x1e7, (0x7f << 0), idx0);
if (NREV_GT(pi->pubpi.phy_rev, 1))
mod_phy_reg(pi, 0x222, (0xff << 0), idx1);
}
static u16 wlc_phy_ipa_get_bbmult_nphy(struct brcms_phy *pi)
{
u16 m0m1;
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &m0m1);
return m0m1;
}
static void wlc_phy_ipa_set_bbmult_nphy(struct brcms_phy *pi, u8 m0, u8 m1)
{
u16 m0m1 = (u16) ((m0 << 8) | m1);
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &m0m1);
wlc_phy_table_write_nphy(pi, 15, 1, 95, 16, &m0m1);
}
static void
wlc_phy_papd_cal_setup_nphy(struct brcms_phy *pi,
struct nphy_papd_restore_state *state, u8 core)
{
s32 tone_freq;
u8 off_core;
u16 mixgain = 0;
off_core = core ^ 0x1;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (NREV_IS(pi->pubpi.phy_rev, 7)
|| NREV_GE(pi->pubpi.phy_rev, 8))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 7),
wlc_phy_read_lpf_bw_ctl_nphy
(pi,
0), 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev == 5)
mixgain = (core == 0) ? 0x20 : 0x00;
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
mixgain = 0x00;
else if ((pi->pubpi.radiorev <= 4)
|| (pi->pubpi.radiorev == 6))
mixgain = 0x00;
} else {
if ((pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
mixgain = 0x50;
else if ((pi->pubpi.radiorev == 3)
|| (pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
mixgain = 0x0;
}
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 11),
mixgain, (1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_tx_pu,
1, (1 << core), 0);
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_tx_pu,
0, (1 << off_core), 0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3),
0, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 2), 1,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 0), 0,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 1), 1,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 8), 0,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 9), 1,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 10), 0,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3), 1,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 5),
0, (1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 4), 0,
(1 << core), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
state->afectrl[core] = read_phy_reg(pi, (core == PHY_CORE_0) ?
0xa6 : 0xa7);
state->afeoverride[core] =
read_phy_reg(pi, (core == PHY_CORE_0) ? 0x8f : 0xa5);
state->afectrl[off_core] =
read_phy_reg(pi, (core == PHY_CORE_0) ? 0xa7 : 0xa6);
state->afeoverride[off_core] =
read_phy_reg(pi, (core == PHY_CORE_0) ? 0xa5 : 0x8f);
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0xa6 : 0xa7),
(0x1 << 2), 0);
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0x8f :
0xa5), (0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0xa7 : 0xa6),
(0x1 << 2), (0x1 << 2));
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0xa5 :
0x8f), (0x1 << 2), (0x1 << 2));
if (CHSPEC_IS2G(pi->radio_chanspec)) {
state->pwrup[core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_PWRUP);
state->atten[core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_ATTEN);
state->pwrup[off_core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_2G_PWRUP);
state->atten[off_core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_2G_ATTEN);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_PWRUP, 0xc);
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_ATTEN, 0xf0);
else if (pi->pubpi.radiorev == 5)
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_ATTEN,
(core == 0) ? 0xf7 : 0xf2);
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_ATTEN, 0xf0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_2G_PWRUP, 0x0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_2G_ATTEN, 0xff);
} else {
state->pwrup[core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_PWRUP);
state->atten[core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_ATTEN);
state->pwrup[off_core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_5G_PWRUP);
state->atten[off_core] =
READ_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_5G_ATTEN);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_PWRUP, 0xc);
if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_ATTEN, 0xf4);
else
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_ATTEN, 0xf0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_5G_PWRUP, 0x0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, off_core,
TXRXCOUPLE_5G_ATTEN, 0xff);
}
tone_freq = 4000;
wlc_phy_tx_tone_nphy(pi, tone_freq, 181, 0, 0, false);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (NPHY_PAPD_COMP_ON) << 0);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (1) << 13);
mod_phy_reg(pi, (off_core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (NPHY_PAPD_COMP_OFF) << 0);
mod_phy_reg(pi, (off_core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (0) << 13);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 12), 0, 0x3, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 1, 0, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 0), 0, 0x3, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 2), 1, 0x3, 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 1), 1, 0x3, 0);
state->afectrl[core] = read_phy_reg(pi, (core == PHY_CORE_0) ?
0xa6 : 0xa7);
state->afeoverride[core] =
read_phy_reg(pi, (core == PHY_CORE_0) ? 0x8f : 0xa5);
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0xa6 : 0xa7),
(0x1 << 0) | (0x1 << 1) | (0x1 << 2), 0);
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0x8f :
0xa5),
(0x1 << 0) |
(0x1 << 1) |
(0x1 << 2), (0x1 << 0) | (0x1 << 1) | (0x1 << 2));
state->vga_master[core] =
READ_RADIO_REG2(pi, RADIO_2056, RX, core, VGA_MASTER);
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core, VGA_MASTER, 0x2b);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
state->fbmix[core] =
READ_RADIO_REG2(pi, RADIO_2056, RX, core,
TXFBMIX_G);
state->intpa_master[core] =
READ_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_MASTER);
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core, TXFBMIX_G,
0x03);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_MASTER, 0x04);
} else {
state->fbmix[core] =
READ_RADIO_REG2(pi, RADIO_2056, RX, core,
TXFBMIX_A);
state->intpa_master[core] =
READ_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_MASTER);
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core, TXFBMIX_A,
0x03);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_MASTER, 0x04);
}
tone_freq = 4000;
wlc_phy_tx_tone_nphy(pi, tone_freq, 181, 0, 0, false);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (1) << 0);
mod_phy_reg(pi, (off_core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 0, 0x3, 0);
}
}
static void
wlc_phy_papd_cal_cleanup_nphy(struct brcms_phy *pi,
struct nphy_papd_restore_state *state)
{
u8 core;
wlc_phy_stopplayback_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_PWRUP, 0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_2G_ATTEN,
state->atten[core]);
} else {
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_PWRUP, 0);
WRITE_RADIO_REG3(pi, RADIO_2057, TX, core,
TXRXCOUPLE_5G_ATTEN,
state->atten[core]);
}
}
if ((pi->pubpi.radiorev == 4) || (pi->pubpi.radiorev == 6))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2),
1, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
else
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 2),
0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 1),
0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 0), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 2), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 11), 1, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 11), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 12), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 2), 1, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 0), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 1), 1, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 8), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 9), 1, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 10), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3), 1, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 5), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 4), 0, 0x3, 1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
write_phy_reg(pi, (core == PHY_CORE_0) ?
0xa6 : 0xa7, state->afectrl[core]);
write_phy_reg(pi, (core == PHY_CORE_0) ? 0x8f :
0xa5, state->afeoverride[core]);
}
wlc_phy_ipa_set_bbmult_nphy(pi, (state->mm >> 8) & 0xff,
(state->mm & 0xff));
if (NREV_IS(pi->pubpi.phy_rev, 7)
|| NREV_GE(pi->pubpi.phy_rev, 8))
wlc_phy_rfctrl_override_nphy_rev7(
pi, (0x1 << 7), 0, 0,
1,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 12), 0, 0x3, 1);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 13), 0, 0x3, 1);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 0), 0, 0x3, 1);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 2), 0, 0x3, 1);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 1), 0, 0x3, 1);
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core, VGA_MASTER,
state->vga_master[core]);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core,
TXFBMIX_G, state->fbmix[core]);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAG_MASTER,
state->intpa_master[core]);
} else {
WRITE_RADIO_REG2(pi, RADIO_2056, RX, core,
TXFBMIX_A, state->fbmix[core]);
WRITE_RADIO_REG2(pi, RADIO_2056, TX, core,
INTPAA_MASTER,
state->intpa_master[core]);
}
write_phy_reg(pi, (core == PHY_CORE_0) ?
0xa6 : 0xa7, state->afectrl[core]);
write_phy_reg(pi, (core == PHY_CORE_0) ? 0x8f :
0xa5, state->afeoverride[core]);
}
wlc_phy_ipa_set_bbmult_nphy(pi, (state->mm >> 8) & 0xff,
(state->mm & 0xff));
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 0, 0x3, 1);
}
}
static void
wlc_phy_a1_nphy(struct brcms_phy *pi, u8 core, u32 winsz, u32 start,
u32 end)
{
u32 *buf, *src, *dst, sz;
sz = end - start + 1;
buf = kmalloc(2 * sizeof(u32) * NPHY_PAPD_EPS_TBL_SIZE, GFP_ATOMIC);
if (NULL == buf)
return;
src = buf;
dst = buf + NPHY_PAPD_EPS_TBL_SIZE;
wlc_phy_table_read_nphy(pi,
(core ==
PHY_CORE_0 ? NPHY_TBL_ID_EPSILONTBL0 :
NPHY_TBL_ID_EPSILONTBL1),
NPHY_PAPD_EPS_TBL_SIZE, 0, 32, src);
do {
u32 phy_a1, phy_a2;
s32 phy_a3, phy_a4, phy_a5, phy_a6, phy_a7;
phy_a1 = end - min(end, (winsz >> 1));
phy_a2 = min_t(u32, NPHY_PAPD_EPS_TBL_SIZE - 1,
end + (winsz >> 1));
phy_a3 = phy_a2 - phy_a1 + 1;
phy_a6 = 0;
phy_a7 = 0;
do {
wlc_phy_papd_decode_epsilon(src[phy_a2], &phy_a4,
&phy_a5);
phy_a6 += phy_a4;
phy_a7 += phy_a5;
} while (phy_a2-- != phy_a1);
phy_a6 /= phy_a3;
phy_a7 /= phy_a3;
dst[end] = ((u32) phy_a7 << 13) | ((u32) phy_a6 & 0x1fff);
} while (end-- != start);
wlc_phy_table_write_nphy(pi,
(core ==
PHY_CORE_0) ? NPHY_TBL_ID_EPSILONTBL0 :
NPHY_TBL_ID_EPSILONTBL1, sz, start, 32, dst);
kfree(buf);
}
static void
wlc_phy_a2_nphy(struct brcms_phy *pi, struct nphy_ipa_txcalgains *txgains,
enum phy_cal_mode cal_mode, u8 core)
{
u16 phy_a1, phy_a2, phy_a3;
u16 phy_a4, phy_a5;
bool phy_a6;
u8 phy_a7, m[2];
u32 phy_a8 = 0;
struct nphy_txgains phy_a9;
if (NREV_LT(pi->pubpi.phy_rev, 3))
return;
phy_a7 = (core == PHY_CORE_0) ? 1 : 0;
phy_a6 = ((cal_mode == CAL_GCTRL)
|| (cal_mode == CAL_SOFT)) ? true : false;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
phy_a9 = wlc_phy_get_tx_gain_nphy(pi);
if (CHSPEC_IS2G(pi->radio_chanspec))
phy_a5 = ((phy_a9.txlpf[core] << 15) |
(phy_a9.txgm[core] << 12) |
(phy_a9.pga[core] << 8) |
(txgains->gains.pad[core] << 3) |
(phy_a9.ipa[core]));
else
phy_a5 = ((phy_a9.txlpf[core] << 15) |
(phy_a9.txgm[core] << 12) |
(txgains->gains.pga[core] << 8) |
(phy_a9.pad[core] << 3) | (phy_a9.ipa[core]));
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_txgain,
phy_a5, (1 << core), 0);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((pi->pubpi.radiorev <= 4)
|| (pi->pubpi.radiorev == 6))
m[core] = (pi->bw == WL_CHANSPEC_BW_40) ?
60 : 79;
else
m[core] = (pi->bw == WL_CHANSPEC_BW_40) ?
45 : 64;
} else {
m[core] = (pi->bw == WL_CHANSPEC_BW_40) ? 75 : 107;
}
m[phy_a7] = 0;
wlc_phy_ipa_set_bbmult_nphy(pi, m[0], m[1]);
phy_a2 = 63;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((pi->pubpi.radiorev == 4)
|| (pi->pubpi.radiorev == 6)) {
phy_a1 = 30;
phy_a3 = 30;
} else {
phy_a1 = 25;
phy_a3 = 25;
}
} else {
if ((pi->pubpi.radiorev == 5)
|| (pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
phy_a1 = 25;
phy_a3 = 25;
} else {
phy_a1 = 35;
phy_a3 = 35;
}
}
if (cal_mode == CAL_GCTRL) {
if ((pi->pubpi.radiorev == 5)
&& (CHSPEC_IS2G(pi->radio_chanspec)))
phy_a1 = 55;
else if (((pi->pubpi.radiorev == 7) &&
(CHSPEC_IS2G(pi->radio_chanspec))) ||
((pi->pubpi.radiorev == 8) &&
(CHSPEC_IS2G(pi->radio_chanspec))))
phy_a1 = 60;
else
phy_a1 = 63;
} else if ((cal_mode != CAL_FULL) && (cal_mode != CAL_SOFT)) {
phy_a1 = 35;
phy_a3 = 35;
}
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (1) << 0);
mod_phy_reg(pi, (phy_a7 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (1) << 13);
mod_phy_reg(pi, (phy_a7 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (0) << 13);
write_phy_reg(pi, 0x2a1, 0x80);
write_phy_reg(pi, 0x2a2, 0x100);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 4), (11) << 4);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 8), (11) << 8);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 0), (0x3) << 0);
write_phy_reg(pi, 0x2e5, 0x20);
mod_phy_reg(pi, 0x2a0, (0x3f << 0), (phy_a3) << 0);
mod_phy_reg(pi, 0x29f, (0x3f << 0), (phy_a1) << 0);
mod_phy_reg(pi, 0x29f, (0x3f << 8), (phy_a2) << 8);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3),
1, ((core == 0) ? 1 : 2), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3),
0, ((core == 0) ? 2 : 1), 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
write_phy_reg(pi, 0x2be, 1);
SPINWAIT(read_phy_reg(pi, 0x2be), 10 * 1000 * 1000);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3),
0, 0x3, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_table_write_nphy(pi,
(core ==
PHY_CORE_0) ? NPHY_TBL_ID_EPSILONTBL0
: NPHY_TBL_ID_EPSILONTBL1, 1, phy_a3,
32, &phy_a8);
if (cal_mode != CAL_GCTRL) {
if (CHSPEC_IS5G(pi->radio_chanspec))
wlc_phy_a1_nphy(pi, core, 5, 0, 35);
}
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_txgain,
phy_a5, (1 << core), 1);
} else {
if (txgains) {
if (txgains->useindex) {
phy_a4 = 15 - ((txgains->index) >> 3);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 6) &&
pi->sh->chip == BCMA_CHIP_ID_BCM47162) {
phy_a5 = 0x10f7 | (phy_a4 << 8);
} else if (NREV_GE(pi->pubpi.phy_rev, 6)) {
phy_a5 = 0x00f7 | (phy_a4 << 8);
} else if (NREV_IS(pi->pubpi.phy_rev, 5)) {
phy_a5 = 0x10f7 | (phy_a4 << 8);
} else {
phy_a5 = 0x50f7 | (phy_a4 << 8);
}
} else {
phy_a5 = 0x70f7 | (phy_a4 << 8);
}
wlc_phy_rfctrl_override_nphy(pi,
(0x1 << 13),
phy_a5,
(1 << core), 0);
} else {
wlc_phy_rfctrl_override_nphy(pi,
(0x1 << 13),
0x5bf7,
(1 << core), 0);
}
}
if (CHSPEC_IS2G(pi->radio_chanspec))
m[core] = (pi->bw == WL_CHANSPEC_BW_40) ? 45 : 64;
else
m[core] = (pi->bw == WL_CHANSPEC_BW_40) ? 75 : 107;
m[phy_a7] = 0;
wlc_phy_ipa_set_bbmult_nphy(pi, m[0], m[1]);
phy_a2 = 63;
if (cal_mode == CAL_FULL) {
phy_a1 = 25;
phy_a3 = 25;
} else if (cal_mode == CAL_SOFT) {
phy_a1 = 25;
phy_a3 = 25;
} else if (cal_mode == CAL_GCTRL) {
phy_a1 = 63;
phy_a3 = 25;
} else {
phy_a1 = 25;
phy_a3 = 25;
}
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (1) << 0);
mod_phy_reg(pi, (phy_a7 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (1) << 13);
mod_phy_reg(pi, (phy_a7 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (0) << 13);
write_phy_reg(pi, 0x2a1, 0x20);
write_phy_reg(pi, 0x2a2, 0x60);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0xf << 4), (9) << 4);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0xf << 8), (9) << 8);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0xf << 0), (0x2) << 0);
write_phy_reg(pi, 0x2e5, 0x20);
} else {
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 11), (1) << 11);
mod_phy_reg(pi, (phy_a7 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 11), (0) << 11);
write_phy_reg(pi, 0x2a1, 0x80);
write_phy_reg(pi, 0x2a2, 0x600);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 4), (0) << 4);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 8), (0) << 8);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x7 << 0), (0x3) << 0);
mod_phy_reg(pi, 0x2a0, (0x3f << 8), (0x20) << 8);
}
mod_phy_reg(pi, 0x2a0, (0x3f << 0), (phy_a3) << 0);
mod_phy_reg(pi, 0x29f, (0x3f << 0), (phy_a1) << 0);
mod_phy_reg(pi, 0x29f, (0x3f << 8), (phy_a2) << 8);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 1, 0x3, 0);
write_phy_reg(pi, 0x2be, 1);
SPINWAIT(read_phy_reg(pi, 0x2be), 10 * 1000 * 1000);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 0, 0x3, 0);
wlc_phy_table_write_nphy(pi,
(core ==
PHY_CORE_0) ? NPHY_TBL_ID_EPSILONTBL0
: NPHY_TBL_ID_EPSILONTBL1, 1, phy_a3,
32, &phy_a8);
if (cal_mode != CAL_GCTRL)
wlc_phy_a1_nphy(pi, core, 5, 0, 40);
}
}
static u8 wlc_phy_a3_nphy(struct brcms_phy *pi, u8 start_gain, u8 core)
{
int phy_a1;
int phy_a2;
bool phy_a3;
struct nphy_ipa_txcalgains phy_a4;
bool phy_a5 = false;
bool phy_a6 = true;
s32 phy_a7, phy_a8;
u32 phy_a9;
int phy_a10;
bool phy_a11 = false;
int phy_a12;
u8 phy_a13 = 0;
u8 phy_a14;
u8 *phy_a15 = NULL;
phy_a4.useindex = true;
phy_a12 = start_gain;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
phy_a2 = 20;
phy_a1 = 1;
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev == 5) {
phy_a15 = pad_gain_codes_used_2057rev5;
phy_a13 =
ARRAY_SIZE(pad_gain_codes_used_2057rev5) - 1;
} else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
phy_a15 = pad_gain_codes_used_2057rev7;
phy_a13 =
ARRAY_SIZE(pad_gain_codes_used_2057rev7) - 1;
} else {
phy_a15 = pad_all_gain_codes_2057;
phy_a13 = ARRAY_SIZE(pad_all_gain_codes_2057) -
1;
}
} else {
phy_a15 = pga_all_gain_codes_2057;
phy_a13 = ARRAY_SIZE(pga_all_gain_codes_2057) - 1;
}
phy_a14 = 0;
for (phy_a10 = 0; phy_a10 < phy_a2; phy_a10++) {
if (CHSPEC_IS2G(pi->radio_chanspec))
phy_a4.gains.pad[core] =
(u16) phy_a15[phy_a12];
else
phy_a4.gains.pga[core] =
(u16) phy_a15[phy_a12];
wlc_phy_a2_nphy(pi, &phy_a4, CAL_GCTRL, core);
wlc_phy_table_read_nphy(pi,
(core ==
PHY_CORE_0 ?
NPHY_TBL_ID_EPSILONTBL0 :
NPHY_TBL_ID_EPSILONTBL1), 1,
63, 32, &phy_a9);
wlc_phy_papd_decode_epsilon(phy_a9, &phy_a7, &phy_a8);
phy_a3 = ((phy_a7 == 4095) || (phy_a7 == -4096) ||
(phy_a8 == 4095) || (phy_a8 == -4096));
if (!phy_a6 && (phy_a3 != phy_a5)) {
if (!phy_a3)
phy_a12 -= (u8) phy_a1;
phy_a11 = true;
break;
}
if (phy_a3)
phy_a12 += (u8) phy_a1;
else
phy_a12 -= (u8) phy_a1;
if ((phy_a12 < phy_a14) || (phy_a12 > phy_a13)) {
if (phy_a12 < phy_a14)
phy_a12 = phy_a14;
else
phy_a12 = phy_a13;
phy_a11 = true;
break;
}
phy_a6 = false;
phy_a5 = phy_a3;
}
} else {
phy_a2 = 10;
phy_a1 = 8;
for (phy_a10 = 0; phy_a10 < phy_a2; phy_a10++) {
phy_a4.index = (u8) phy_a12;
wlc_phy_a2_nphy(pi, &phy_a4, CAL_GCTRL, core);
wlc_phy_table_read_nphy(pi,
(core ==
PHY_CORE_0 ?
NPHY_TBL_ID_EPSILONTBL0 :
NPHY_TBL_ID_EPSILONTBL1), 1,
63, 32, &phy_a9);
wlc_phy_papd_decode_epsilon(phy_a9, &phy_a7, &phy_a8);
phy_a3 = ((phy_a7 == 4095) || (phy_a7 == -4096) ||
(phy_a8 == 4095) || (phy_a8 == -4096));
if (!phy_a6 && (phy_a3 != phy_a5)) {
if (!phy_a3)
phy_a12 -= (u8) phy_a1;
phy_a11 = true;
break;
}
if (phy_a3)
phy_a12 += (u8) phy_a1;
else
phy_a12 -= (u8) phy_a1;
if ((phy_a12 < 0) || (phy_a12 > 127)) {
if (phy_a12 < 0)
phy_a12 = 0;
else
phy_a12 = 127;
phy_a11 = true;
break;
}
phy_a6 = false;
phy_a5 = phy_a3;
}
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
return (u8) phy_a15[phy_a12];
else
return (u8) phy_a12;
}
static void wlc_phy_a4(struct brcms_phy *pi, bool full_cal)
{
struct nphy_ipa_txcalgains phy_b1[2];
struct nphy_papd_restore_state phy_b2;
bool phy_b3;
u8 phy_b4;
u8 phy_b5;
s16 phy_b6, phy_b7, phy_b8;
u16 phy_b9;
s16 phy_b10, phy_b11, phy_b12;
phy_b11 = 0;
phy_b12 = 0;
phy_b7 = 0;
phy_b8 = 0;
phy_b6 = 0;
if (pi->nphy_papd_skip == 1)
return;
phy_b3 = (0 == (bcma_read32(pi->d11core, D11REGOFFS(maccontrol)) &
MCTL_EN_MAC));
if (!phy_b3)
wlapi_suspend_mac_and_wait(pi->sh->physhim);
wlc_phy_stay_in_carriersearch_nphy(pi, true);
pi->nphy_force_papd_cal = false;
for (phy_b5 = 0; phy_b5 < pi->pubpi.phy_corenum; phy_b5++)
pi->nphy_papd_tx_gain_at_last_cal[phy_b5] =
wlc_phy_txpwr_idx_cur_get_nphy(pi, phy_b5);
pi->nphy_papd_last_cal = pi->sh->now;
pi->nphy_papd_recal_counter++;
phy_b4 = pi->nphy_txpwrctrl;
wlc_phy_txpwrctrl_enable_nphy(pi, PHY_TPC_HW_OFF);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_SCALARTBL0, 64, 0, 32,
nphy_papd_scaltbl);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_SCALARTBL1, 64, 0, 32,
nphy_papd_scaltbl);
phy_b9 = read_phy_reg(pi, 0x01);
mod_phy_reg(pi, 0x01, (0x1 << 15), 0);
for (phy_b5 = 0; phy_b5 < pi->pubpi.phy_corenum; phy_b5++) {
s32 i, val = 0;
for (i = 0; i < 64; i++)
wlc_phy_table_write_nphy(pi,
((phy_b5 ==
PHY_CORE_0) ?
NPHY_TBL_ID_EPSILONTBL0 :
NPHY_TBL_ID_EPSILONTBL1), 1,
i, 32, &val);
}
wlc_phy_ipa_restore_tx_digi_filts_nphy(pi);
phy_b2.mm = wlc_phy_ipa_get_bbmult_nphy(pi);
for (phy_b5 = 0; phy_b5 < pi->pubpi.phy_corenum; phy_b5++) {
wlc_phy_papd_cal_setup_nphy(pi, &phy_b2, phy_b5);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if ((pi->pubpi.radiorev == 3)
|| (pi->pubpi.radiorev == 4)
|| (pi->pubpi.radiorev == 6)) {
pi->nphy_papd_cal_gain_index[phy_b5] =
23;
} else if (pi->pubpi.radiorev == 5) {
pi->nphy_papd_cal_gain_index[phy_b5] =
0;
pi->nphy_papd_cal_gain_index[phy_b5] =
wlc_phy_a3_nphy(
pi,
pi->
nphy_papd_cal_gain_index
[phy_b5],
phy_b5);
} else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8)) {
pi->nphy_papd_cal_gain_index[phy_b5] =
0;
pi->nphy_papd_cal_gain_index[phy_b5] =
wlc_phy_a3_nphy(
pi,
pi->
nphy_papd_cal_gain_index
[phy_b5],
phy_b5);
}
phy_b1[phy_b5].gains.pad[phy_b5] =
pi->nphy_papd_cal_gain_index[phy_b5];
} else {
pi->nphy_papd_cal_gain_index[phy_b5] = 0;
pi->nphy_papd_cal_gain_index[phy_b5] =
wlc_phy_a3_nphy(
pi,
pi->
nphy_papd_cal_gain_index
[phy_b5], phy_b5);
phy_b1[phy_b5].gains.pga[phy_b5] =
pi->nphy_papd_cal_gain_index[phy_b5];
}
} else {
phy_b1[phy_b5].useindex = true;
phy_b1[phy_b5].index = 16;
phy_b1[phy_b5].index =
wlc_phy_a3_nphy(pi, phy_b1[phy_b5].index,
phy_b5);
pi->nphy_papd_cal_gain_index[phy_b5] =
15 - ((phy_b1[phy_b5].index) >> 3);
}
switch (pi->nphy_papd_cal_type) {
case 0:
wlc_phy_a2_nphy(pi, &phy_b1[phy_b5], CAL_FULL, phy_b5);
break;
case 1:
wlc_phy_a2_nphy(pi, &phy_b1[phy_b5], CAL_SOFT, phy_b5);
break;
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_papd_cal_cleanup_nphy(pi, &phy_b2);
}
if (NREV_LT(pi->pubpi.phy_rev, 7))
wlc_phy_papd_cal_cleanup_nphy(pi, &phy_b2);
for (phy_b5 = 0; phy_b5 < pi->pubpi.phy_corenum; phy_b5++) {
int eps_offset = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (CHSPEC_IS2G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev == 3)
eps_offset = -2;
else if (pi->pubpi.radiorev == 5)
eps_offset = 3;
else
eps_offset = -1;
} else {
eps_offset = 2;
}
if (CHSPEC_IS2G(pi->radio_chanspec)) {
phy_b8 = phy_b1[phy_b5].gains.pad[phy_b5];
phy_b10 = 0;
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6)) {
phy_b12 = -(
nphy_papd_padgain_dlt_2g_2057rev3n4
[phy_b8] + 1) / 2;
phy_b10 = -1;
} else if (pi->pubpi.radiorev == 5) {
phy_b12 = -(
nphy_papd_padgain_dlt_2g_2057rev5
[phy_b8] + 1) / 2;
} else if ((pi->pubpi.radiorev == 7) ||
(pi->pubpi.radiorev == 8)) {
phy_b12 = -(
nphy_papd_padgain_dlt_2g_2057rev7
[phy_b8] + 1) / 2;
}
} else {
phy_b7 = phy_b1[phy_b5].gains.pga[phy_b5];
if ((pi->pubpi.radiorev == 3) ||
(pi->pubpi.radiorev == 4) ||
(pi->pubpi.radiorev == 6))
phy_b11 =
-(nphy_papd_pgagain_dlt_5g_2057
[phy_b7]
+ 1) / 2;
else if ((pi->pubpi.radiorev == 7)
|| (pi->pubpi.radiorev == 8))
phy_b11 = -(
nphy_papd_pgagain_dlt_5g_2057rev7
[phy_b7] + 1) / 2;
phy_b10 = -9;
}
if (CHSPEC_IS2G(pi->radio_chanspec))
phy_b6 =
-60 + 27 + eps_offset + phy_b12 +
phy_b10;
else
phy_b6 =
-60 + 27 + eps_offset + phy_b11 +
phy_b10;
mod_phy_reg(pi, (phy_b5 == PHY_CORE_0) ? 0x298 :
0x29c, (0x1ff << 7), (phy_b6) << 7);
pi->nphy_papd_epsilon_offset[phy_b5] = phy_b6;
} else {
if (NREV_LT(pi->pubpi.phy_rev, 5))
eps_offset = 4;
else
eps_offset = 2;
phy_b7 = 15 - ((phy_b1[phy_b5].index) >> 3);
if (CHSPEC_IS2G(pi->radio_chanspec)) {
phy_b11 =
-(nphy_papd_pga_gain_delta_ipa_2g[
phy_b7] +
1) / 2;
phy_b10 = 0;
} else {
phy_b11 =
-(nphy_papd_pga_gain_delta_ipa_5g[
phy_b7] +
1) / 2;
phy_b10 = -9;
}
phy_b6 = -60 + 27 + eps_offset + phy_b11 + phy_b10;
mod_phy_reg(pi, (phy_b5 == PHY_CORE_0) ? 0x298 :
0x29c, (0x1ff << 7), (phy_b6) << 7);
pi->nphy_papd_epsilon_offset[phy_b5] = phy_b6;
}
}
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (NPHY_PAPD_COMP_ON) << 0);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (NPHY_PAPD_COMP_ON) << 0);
if (NREV_GE(pi->pubpi.phy_rev, 6)) {
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (0) << 13);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 13), (0) << 13);
} else {
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 11), (0) << 11);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x2a3 :
0x2a4, (0x1 << 11), (0) << 11);
}
pi->nphy_papdcomp = NPHY_PAPD_COMP_ON;
write_phy_reg(pi, 0x01, phy_b9);
wlc_phy_ipa_set_tx_digi_filts_nphy(pi);
wlc_phy_txpwrctrl_enable_nphy(pi, phy_b4);
if (phy_b4 == PHY_TPC_HW_OFF) {
wlc_phy_txpwr_index_nphy(pi, (1 << 0),
(s8) (pi->nphy_txpwrindex[0].
index_internal), false);
wlc_phy_txpwr_index_nphy(pi, (1 << 1),
(s8) (pi->nphy_txpwrindex[1].
index_internal), false);
}
wlc_phy_stay_in_carriersearch_nphy(pi, false);
if (!phy_b3)
wlapi_enable_mac(pi->sh->physhim);
}
void wlc_phy_cal_perical_nphy_run(struct brcms_phy *pi, u8 caltype)
{
struct nphy_txgains target_gain;
u8 tx_pwr_ctrl_state;
bool fullcal = true;
bool restore_tx_gain = false;
bool mphase;
if (PHY_MUTED(pi))
return;
if (caltype == PHY_PERICAL_AUTO)
fullcal = (pi->radio_chanspec != pi->nphy_txiqlocal_chanspec);
else if (caltype == PHY_PERICAL_PARTIAL)
fullcal = false;
if (pi->cal_type_override != PHY_PERICAL_AUTO)
fullcal =
(pi->cal_type_override ==
PHY_PERICAL_FULL) ? true : false;
if ((pi->mphase_cal_phase_id > MPHASE_CAL_STATE_INIT)) {
if (pi->nphy_txiqlocal_chanspec != pi->radio_chanspec)
wlc_phy_cal_perical_mphase_restart(pi);
}
if ((pi->mphase_cal_phase_id == MPHASE_CAL_STATE_RXCAL))
wlapi_bmac_write_shm(pi->sh->physhim, M_CTS_DURATION, 10000);
wlapi_suspend_mac_and_wait(pi->sh->physhim);
wlc_phyreg_enter((struct brcms_phy_pub *) pi);
if ((pi->mphase_cal_phase_id == MPHASE_CAL_STATE_IDLE) ||
(pi->mphase_cal_phase_id == MPHASE_CAL_STATE_INIT)) {
pi->nphy_cal_orig_pwr_idx[0] =
(u8) ((read_phy_reg(pi, 0x1ed) >> 8) & 0x7f);
pi->nphy_cal_orig_pwr_idx[1] =
(u8) ((read_phy_reg(pi, 0x1ee) >> 8) & 0x7f);
if (pi->nphy_txpwrctrl != PHY_TPC_HW_OFF) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2,
0x110, 16,
pi->nphy_cal_orig_tx_gain);
} else {
pi->nphy_cal_orig_tx_gain[0] = 0;
pi->nphy_cal_orig_tx_gain[1] = 0;
}
}
target_gain = wlc_phy_get_tx_gain_nphy(pi);
tx_pwr_ctrl_state = pi->nphy_txpwrctrl;
wlc_phy_txpwrctrl_enable_nphy(pi, PHY_TPC_HW_OFF);
if (pi->antsel_type == ANTSEL_2x3)
wlc_phy_antsel_init((struct brcms_phy_pub *) pi, true);
mphase = (pi->mphase_cal_phase_id != MPHASE_CAL_STATE_IDLE);
if (!mphase) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
wlc_phy_precal_txgain_nphy(pi);
pi->nphy_cal_target_gain = wlc_phy_get_tx_gain_nphy(pi);
restore_tx_gain = true;
target_gain = pi->nphy_cal_target_gain;
}
if (0 ==
wlc_phy_cal_txiqlo_nphy(pi, target_gain, fullcal,
mphase)) {
if (PHY_IPA(pi))
wlc_phy_a4(pi, true);
wlc_phyreg_exit((struct brcms_phy_pub *) pi);
wlapi_enable_mac(pi->sh->physhim);
wlapi_bmac_write_shm(pi->sh->physhim, M_CTS_DURATION,
10000);
wlapi_suspend_mac_and_wait(pi->sh->physhim);
wlc_phyreg_enter((struct brcms_phy_pub *) pi);
if (0 == wlc_phy_cal_rxiq_nphy(pi, target_gain,
(pi->first_cal_after_assoc ||
(pi->cal_type_override ==
PHY_PERICAL_FULL)) ? 2 : 0, false)) {
wlc_phy_savecal_nphy(pi);
wlc_phy_txpwrctrl_coeff_setup_nphy(pi);
pi->nphy_perical_last = pi->sh->now;
}
}
if (caltype != PHY_PERICAL_AUTO)
wlc_phy_rssi_cal_nphy(pi);
if (pi->first_cal_after_assoc
|| (pi->cal_type_override == PHY_PERICAL_FULL)) {
pi->first_cal_after_assoc = false;
wlc_phy_txpwrctrl_idle_tssi_nphy(pi);
wlc_phy_txpwrctrl_pwr_setup_nphy(pi);
}
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_radio205x_vcocal_nphy(pi);
} else {
switch (pi->mphase_cal_phase_id) {
case MPHASE_CAL_STATE_INIT:
pi->nphy_perical_last = pi->sh->now;
pi->nphy_txiqlocal_chanspec = pi->radio_chanspec;
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_precal_txgain_nphy(pi);
pi->nphy_cal_target_gain = wlc_phy_get_tx_gain_nphy(pi);
pi->mphase_cal_phase_id++;
break;
case MPHASE_CAL_STATE_TXPHASE0:
case MPHASE_CAL_STATE_TXPHASE1:
case MPHASE_CAL_STATE_TXPHASE2:
case MPHASE_CAL_STATE_TXPHASE3:
case MPHASE_CAL_STATE_TXPHASE4:
case MPHASE_CAL_STATE_TXPHASE5:
if ((pi->radar_percal_mask & 0x10) != 0)
pi->nphy_rxcal_active = true;
if (wlc_phy_cal_txiqlo_nphy
(pi, pi->nphy_cal_target_gain, fullcal,
true) != 0) {
wlc_phy_cal_perical_mphase_reset(pi);
break;
}
if (NREV_LE(pi->pubpi.phy_rev, 2) &&
(pi->mphase_cal_phase_id ==
MPHASE_CAL_STATE_TXPHASE4))
pi->mphase_cal_phase_id += 2;
else
pi->mphase_cal_phase_id++;
break;
case MPHASE_CAL_STATE_PAPDCAL:
if ((pi->radar_percal_mask & 0x2) != 0)
pi->nphy_rxcal_active = true;
if (PHY_IPA(pi))
wlc_phy_a4(pi, true);
pi->mphase_cal_phase_id++;
break;
case MPHASE_CAL_STATE_RXCAL:
if ((pi->radar_percal_mask & 0x1) != 0)
pi->nphy_rxcal_active = true;
if (wlc_phy_cal_rxiq_nphy(pi, target_gain,
(pi->first_cal_after_assoc ||
(pi->cal_type_override ==
PHY_PERICAL_FULL)) ? 2 : 0,
false) == 0)
wlc_phy_savecal_nphy(pi);
pi->mphase_cal_phase_id++;
break;
case MPHASE_CAL_STATE_RSSICAL:
if ((pi->radar_percal_mask & 0x4) != 0)
pi->nphy_rxcal_active = true;
wlc_phy_txpwrctrl_coeff_setup_nphy(pi);
wlc_phy_rssi_cal_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_radio205x_vcocal_nphy(pi);
restore_tx_gain = true;
if (pi->first_cal_after_assoc)
pi->mphase_cal_phase_id++;
else
wlc_phy_cal_perical_mphase_reset(pi);
break;
case MPHASE_CAL_STATE_IDLETSSI:
if ((pi->radar_percal_mask & 0x8) != 0)
pi->nphy_rxcal_active = true;
if (pi->first_cal_after_assoc) {
pi->first_cal_after_assoc = false;
wlc_phy_txpwrctrl_idle_tssi_nphy(pi);
wlc_phy_txpwrctrl_pwr_setup_nphy(pi);
}
wlc_phy_cal_perical_mphase_reset(pi);
break;
default:
wlc_phy_cal_perical_mphase_reset(pi);
break;
}
}
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (restore_tx_gain) {
if (tx_pwr_ctrl_state != PHY_TPC_HW_OFF) {
wlc_phy_txpwr_index_nphy(pi, 1,
pi->
nphy_cal_orig_pwr_idx
[0], false);
wlc_phy_txpwr_index_nphy(pi, 2,
pi->
nphy_cal_orig_pwr_idx
[1], false);
pi->nphy_txpwrindex[0].index = -1;
pi->nphy_txpwrindex[1].index = -1;
} else {
wlc_phy_txpwr_index_nphy(pi, (1 << 0),
(s8) (pi->
nphy_txpwrindex
[0].
index_internal),
false);
wlc_phy_txpwr_index_nphy(pi, (1 << 1),
(s8) (pi->
nphy_txpwrindex
[1].
index_internal),
false);
}
}
}
wlc_phy_txpwrctrl_enable_nphy(pi, tx_pwr_ctrl_state);
wlc_phyreg_exit((struct brcms_phy_pub *) pi);
wlapi_enable_mac(pi->sh->physhim);
}
int
wlc_phy_cal_txiqlo_nphy(struct brcms_phy *pi, struct nphy_txgains target_gain,
bool fullcal, bool mphase)
{
u16 val;
u16 tbl_buf[11];
u8 cal_cnt;
u16 cal_cmd;
u8 num_cals, max_cal_cmds;
u16 core_no, cal_type;
u16 diq_start = 0;
u8 phy_bw;
u16 max_val;
u16 tone_freq;
u16 gain_save[2];
u16 cal_gain[2];
struct nphy_iqcal_params cal_params[2];
u32 tbl_len;
void *tbl_ptr;
bool ladder_updated[2];
u8 mphase_cal_lastphase = 0;
int bcmerror = 0;
bool phyhang_avoid_state = false;
u16 tbl_tx_iqlo_cal_loft_ladder_20[] = {
0x0300, 0x0500, 0x0700, 0x0900, 0x0d00, 0x1100, 0x1900, 0x1901,
0x1902,
0x1903, 0x1904, 0x1905, 0x1906, 0x1907, 0x2407, 0x3207, 0x4607,
0x6407
};
u16 tbl_tx_iqlo_cal_iqimb_ladder_20[] = {
0x0200, 0x0300, 0x0600, 0x0900, 0x0d00, 0x1100, 0x1900, 0x2400,
0x3200,
0x4600, 0x6400, 0x6401, 0x6402, 0x6403, 0x6404, 0x6405, 0x6406,
0x6407
};
u16 tbl_tx_iqlo_cal_loft_ladder_40[] = {
0x0200, 0x0300, 0x0400, 0x0700, 0x0900, 0x0c00, 0x1200, 0x1201,
0x1202,
0x1203, 0x1204, 0x1205, 0x1206, 0x1207, 0x1907, 0x2307, 0x3207,
0x4707
};
u16 tbl_tx_iqlo_cal_iqimb_ladder_40[] = {
0x0100, 0x0200, 0x0400, 0x0700, 0x0900, 0x0c00, 0x1200, 0x1900,
0x2300,
0x3200, 0x4700, 0x4701, 0x4702, 0x4703, 0x4704, 0x4705, 0x4706,
0x4707
};
u16 tbl_tx_iqlo_cal_startcoefs[] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000
};
u16 tbl_tx_iqlo_cal_cmds_fullcal[] = {
0x8123, 0x8264, 0x8086, 0x8245, 0x8056,
0x9123, 0x9264, 0x9086, 0x9245, 0x9056
};
u16 tbl_tx_iqlo_cal_cmds_recal[] = {
0x8101, 0x8253, 0x8053, 0x8234, 0x8034,
0x9101, 0x9253, 0x9053, 0x9234, 0x9034
};
u16 tbl_tx_iqlo_cal_startcoefs_nphyrev3[] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000
};
u16 tbl_tx_iqlo_cal_cmds_fullcal_nphyrev3[] = {
0x8434, 0x8334, 0x8084, 0x8267, 0x8056, 0x8234,
0x9434, 0x9334, 0x9084, 0x9267, 0x9056, 0x9234
};
u16 tbl_tx_iqlo_cal_cmds_recal_nphyrev3[] = {
0x8423, 0x8323, 0x8073, 0x8256, 0x8045, 0x8223,
0x9423, 0x9323, 0x9073, 0x9256, 0x9045, 0x9223
};
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (NREV_GE(pi->pubpi.phy_rev, 4)) {
phyhang_avoid_state = pi->phyhang_avoid;
pi->phyhang_avoid = false;
}
if (CHSPEC_IS40(pi->radio_chanspec))
phy_bw = 40;
else
phy_bw = 20;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, gain_save);
for (core_no = 0; core_no <= 1; core_no++) {
wlc_phy_iqcal_gainparams_nphy(pi, core_no, target_gain,
&cal_params[core_no]);
cal_gain[core_no] = cal_params[core_no].cal_gain;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, cal_gain);
wlc_phy_txcal_radio_setup_nphy(pi);
wlc_phy_txcal_physetup_nphy(pi);
ladder_updated[0] = ladder_updated[1] = false;
if (!(NREV_GE(pi->pubpi.phy_rev, 6) ||
(NREV_IS(pi->pubpi.phy_rev, 5) && PHY_IPA(pi)
&& (CHSPEC_IS2G(pi->radio_chanspec))))) {
if (phy_bw == 40) {
tbl_ptr = tbl_tx_iqlo_cal_loft_ladder_40;
tbl_len = ARRAY_SIZE(tbl_tx_iqlo_cal_loft_ladder_40);
} else {
tbl_ptr = tbl_tx_iqlo_cal_loft_ladder_20;
tbl_len = ARRAY_SIZE(tbl_tx_iqlo_cal_loft_ladder_20);
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, tbl_len, 0,
16, tbl_ptr);
if (phy_bw == 40) {
tbl_ptr = tbl_tx_iqlo_cal_iqimb_ladder_40;
tbl_len = ARRAY_SIZE(tbl_tx_iqlo_cal_iqimb_ladder_40);
} else {
tbl_ptr = tbl_tx_iqlo_cal_iqimb_ladder_20;
tbl_len = ARRAY_SIZE(tbl_tx_iqlo_cal_iqimb_ladder_20);
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, tbl_len, 32,
16, tbl_ptr);
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
write_phy_reg(pi, 0xc2, 0x8ad9);
else
write_phy_reg(pi, 0xc2, 0x8aa9);
max_val = 250;
tone_freq = (phy_bw == 20) ? 2500 : 5000;
if (pi->mphase_cal_phase_id > MPHASE_CAL_STATE_TXPHASE0) {
wlc_phy_runsamples_nphy(pi, phy_bw * 8, 0xffff, 0, 1, 0, false);
bcmerror = 0;
} else {
bcmerror =
wlc_phy_tx_tone_nphy(pi, tone_freq, max_val, 1, 0,
false);
}
if (bcmerror == 0) {
if (pi->mphase_cal_phase_id > MPHASE_CAL_STATE_TXPHASE0) {
tbl_ptr = pi->mphase_txcal_bestcoeffs;
tbl_len = ARRAY_SIZE(pi->mphase_txcal_bestcoeffs);
if (NREV_LT(pi->pubpi.phy_rev, 3))
tbl_len -= 2;
} else {
if ((!fullcal) && (pi->nphy_txiqlocal_coeffsvalid)) {
tbl_ptr = pi->nphy_txiqlocal_bestc;
tbl_len = ARRAY_SIZE(pi->nphy_txiqlocal_bestc);
if (NREV_LT(pi->pubpi.phy_rev, 3))
tbl_len -= 2;
} else {
fullcal = true;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
tbl_ptr =
tbl_tx_iqlo_cal_startcoefs_nphyrev3;
tbl_len = ARRAY_SIZE(
tbl_tx_iqlo_cal_startcoefs_nphyrev3);
} else {
tbl_ptr = tbl_tx_iqlo_cal_startcoefs;
tbl_len = ARRAY_SIZE(
tbl_tx_iqlo_cal_startcoefs);
}
}
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, tbl_len, 64,
16, tbl_ptr);
if (fullcal) {
max_cal_cmds = (NREV_GE(pi->pubpi.phy_rev, 3)) ?
ARRAY_SIZE(
tbl_tx_iqlo_cal_cmds_fullcal_nphyrev3) :
ARRAY_SIZE(tbl_tx_iqlo_cal_cmds_fullcal);
} else {
max_cal_cmds = (NREV_GE(pi->pubpi.phy_rev, 3)) ?
ARRAY_SIZE(
tbl_tx_iqlo_cal_cmds_recal_nphyrev3) :
ARRAY_SIZE(tbl_tx_iqlo_cal_cmds_recal);
}
if (mphase) {
cal_cnt = pi->mphase_txcal_cmdidx;
if ((cal_cnt + pi->mphase_txcal_numcmds) < max_cal_cmds)
num_cals = cal_cnt + pi->mphase_txcal_numcmds;
else
num_cals = max_cal_cmds;
} else {
cal_cnt = 0;
num_cals = max_cal_cmds;
}
for (; cal_cnt < num_cals; cal_cnt++) {
if (fullcal) {
cal_cmd = (NREV_GE(pi->pubpi.phy_rev, 3)) ?
tbl_tx_iqlo_cal_cmds_fullcal_nphyrev3
[cal_cnt] :
tbl_tx_iqlo_cal_cmds_fullcal[cal_cnt];
} else {
cal_cmd = (NREV_GE(pi->pubpi.phy_rev, 3)) ?
tbl_tx_iqlo_cal_cmds_recal_nphyrev3[
cal_cnt]
: tbl_tx_iqlo_cal_cmds_recal[cal_cnt];
}
core_no = ((cal_cmd & 0x3000) >> 12);
cal_type = ((cal_cmd & 0x0F00) >> 8);
if (NREV_GE(pi->pubpi.phy_rev, 6) ||
(NREV_IS(pi->pubpi.phy_rev, 5) &&
PHY_IPA(pi)
&& (CHSPEC_IS2G(pi->radio_chanspec)))) {
if (!ladder_updated[core_no]) {
wlc_phy_update_txcal_ladder_nphy(
pi,
core_no);
ladder_updated[core_no] = true;
}
}
val =
(cal_params[core_no].
ncorr[cal_type] << 8) | NPHY_N_GCTL;
write_phy_reg(pi, 0xc1, val);
if ((cal_type == 1) || (cal_type == 3)
|| (cal_type == 4)) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL,
1, 69 + core_no, 16,
tbl_buf);
diq_start = tbl_buf[0];
tbl_buf[0] = 0;
wlc_phy_table_write_nphy(pi,
NPHY_TBL_ID_IQLOCAL, 1,
69 + core_no, 16,
tbl_buf);
}
write_phy_reg(pi, 0xc0, cal_cmd);
SPINWAIT(((read_phy_reg(pi, 0xc0) & 0xc000) != 0),
20000);
if (WARN(read_phy_reg(pi, 0xc0) & 0xc000,
"HW error: txiq calib"))
return -EIO;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL,
tbl_len, 96, 16, tbl_buf);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL,
tbl_len, 64, 16, tbl_buf);
if ((cal_type == 1) || (cal_type == 3)
|| (cal_type == 4)) {
tbl_buf[0] = diq_start;
}
}
if (mphase) {
pi->mphase_txcal_cmdidx = num_cals;
if (pi->mphase_txcal_cmdidx >= max_cal_cmds)
pi->mphase_txcal_cmdidx = 0;
}
mphase_cal_lastphase =
(NREV_LE(pi->pubpi.phy_rev, 2)) ?
MPHASE_CAL_STATE_TXPHASE4 : MPHASE_CAL_STATE_TXPHASE5;
if (!mphase
|| (pi->mphase_cal_phase_id == mphase_cal_lastphase)) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 96,
16, tbl_buf);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 80,
16, tbl_buf);
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
tbl_buf[0] = 0;
tbl_buf[1] = 0;
tbl_buf[2] = 0;
tbl_buf[3] = 0;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 88,
16, tbl_buf);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 101,
16, tbl_buf);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 85,
16, tbl_buf);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 93,
16, tbl_buf);
tbl_len = ARRAY_SIZE(pi->nphy_txiqlocal_bestc);
if (NREV_LT(pi->pubpi.phy_rev, 3))
tbl_len -= 2;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL,
tbl_len, 96, 16,
pi->nphy_txiqlocal_bestc);
pi->nphy_txiqlocal_coeffsvalid = true;
pi->nphy_txiqlocal_chanspec = pi->radio_chanspec;
} else {
tbl_len = ARRAY_SIZE(pi->mphase_txcal_bestcoeffs);
if (NREV_LT(pi->pubpi.phy_rev, 3))
tbl_len -= 2;
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL,
tbl_len, 96, 16,
pi->mphase_txcal_bestcoeffs);
}
wlc_phy_stopplayback_nphy(pi);
write_phy_reg(pi, 0xc2, 0x0000);
}
wlc_phy_txcal_phycleanup_nphy(pi);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
gain_save);
wlc_phy_txcal_radio_cleanup_nphy(pi);
if (NREV_LT(pi->pubpi.phy_rev, 2)) {
if (!mphase
|| (pi->mphase_cal_phase_id == mphase_cal_lastphase))
wlc_phy_tx_iq_war_nphy(pi);
}
if (NREV_GE(pi->pubpi.phy_rev, 4))
pi->phyhang_avoid = phyhang_avoid_state;
wlc_phy_stay_in_carriersearch_nphy(pi, false);
return bcmerror;
}
static void wlc_phy_reapply_txcal_coeffs_nphy(struct brcms_phy *pi)
{
u16 tbl_buf[7];
if ((pi->nphy_txiqlocal_chanspec == pi->radio_chanspec) &&
(pi->nphy_txiqlocal_coeffsvalid)) {
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_IQLOCAL,
ARRAY_SIZE(tbl_buf), 80, 16, tbl_buf);
if ((pi->nphy_txiqlocal_bestc[0] != tbl_buf[0]) ||
(pi->nphy_txiqlocal_bestc[1] != tbl_buf[1]) ||
(pi->nphy_txiqlocal_bestc[2] != tbl_buf[2]) ||
(pi->nphy_txiqlocal_bestc[3] != tbl_buf[3])) {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 80,
16, pi->nphy_txiqlocal_bestc);
tbl_buf[0] = 0;
tbl_buf[1] = 0;
tbl_buf[2] = 0;
tbl_buf[3] = 0;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 4, 88,
16, tbl_buf);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 85,
16,
&pi->nphy_txiqlocal_bestc[5]);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_IQLOCAL, 2, 93,
16,
&pi->nphy_txiqlocal_bestc[5]);
}
}
}
void
wlc_phy_rx_iq_coeffs_nphy(struct brcms_phy *pi, u8 write,
struct nphy_iq_comp *pcomp)
{
if (write) {
write_phy_reg(pi, 0x9a, pcomp->a0);
write_phy_reg(pi, 0x9b, pcomp->b0);
write_phy_reg(pi, 0x9c, pcomp->a1);
write_phy_reg(pi, 0x9d, pcomp->b1);
} else {
pcomp->a0 = read_phy_reg(pi, 0x9a);
pcomp->b0 = read_phy_reg(pi, 0x9b);
pcomp->a1 = read_phy_reg(pi, 0x9c);
pcomp->b1 = read_phy_reg(pi, 0x9d);
}
}
void
wlc_phy_rx_iq_est_nphy(struct brcms_phy *pi, struct phy_iq_est *est,
u16 num_samps, u8 wait_time, u8 wait_for_crs)
{
u8 core;
write_phy_reg(pi, 0x12b, num_samps);
mod_phy_reg(pi, 0x12a, (0xff << 0), (wait_time << 0));
mod_phy_reg(pi, 0x129, NPHY_IqestCmd_iqMode,
(wait_for_crs) ? NPHY_IqestCmd_iqMode : 0);
mod_phy_reg(pi, 0x129, NPHY_IqestCmd_iqstart, NPHY_IqestCmd_iqstart);
SPINWAIT(((read_phy_reg(pi, 0x129) & NPHY_IqestCmd_iqstart) != 0),
10000);
if (WARN(read_phy_reg(pi, 0x129) & NPHY_IqestCmd_iqstart,
"HW error: rxiq est"))
return;
if ((read_phy_reg(pi, 0x129) & NPHY_IqestCmd_iqstart) == 0) {
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
est[core].i_pwr =
(read_phy_reg(pi,
NPHY_IqestipwrAccHi(core)) << 16)
| read_phy_reg(pi, NPHY_IqestipwrAccLo(core));
est[core].q_pwr =
(read_phy_reg(pi,
NPHY_IqestqpwrAccHi(core)) << 16)
| read_phy_reg(pi, NPHY_IqestqpwrAccLo(core));
est[core].iq_prod =
(read_phy_reg(pi,
NPHY_IqestIqAccHi(core)) << 16) |
read_phy_reg(pi, NPHY_IqestIqAccLo(core));
}
}
}
static void wlc_phy_calc_rx_iq_comp_nphy(struct brcms_phy *pi, u8 core_mask)
{
u8 curr_core;
struct phy_iq_est est[PHY_CORE_MAX];
struct nphy_iq_comp old_comp, new_comp;
s32 iq = 0;
u32 ii = 0, qq = 0;
s16 iq_nbits, qq_nbits, brsh, arsh;
s32 a, b, temp;
int bcmerror = 0;
uint cal_retry = 0;
if (core_mask == 0x0)
return;
wlc_phy_rx_iq_coeffs_nphy(pi, 0, &old_comp);
new_comp.a0 = new_comp.b0 = new_comp.a1 = new_comp.b1 = 0x0;
wlc_phy_rx_iq_coeffs_nphy(pi, 1, &new_comp);
cal_try:
wlc_phy_rx_iq_est_nphy(pi, est, 0x4000, 32, 0);
new_comp = old_comp;
for (curr_core = 0; curr_core < pi->pubpi.phy_corenum; curr_core++) {
if ((curr_core == PHY_CORE_0) && (core_mask & 0x1)) {
iq = est[curr_core].iq_prod;
ii = est[curr_core].i_pwr;
qq = est[curr_core].q_pwr;
} else if ((curr_core == PHY_CORE_1) && (core_mask & 0x2)) {
iq = est[curr_core].iq_prod;
ii = est[curr_core].i_pwr;
qq = est[curr_core].q_pwr;
} else {
continue;
}
if ((ii + qq) < NPHY_MIN_RXIQ_PWR) {
bcmerror = -EBADE;
break;
}
iq_nbits = wlc_phy_nbits(iq);
qq_nbits = wlc_phy_nbits(qq);
arsh = 10 - (30 - iq_nbits);
if (arsh >= 0) {
a = (-(iq << (30 - iq_nbits)) + (ii >> (1 + arsh)));
temp = (s32) (ii >> arsh);
if (temp == 0) {
bcmerror = -EBADE;
break;
}
} else {
a = (-(iq << (30 - iq_nbits)) + (ii << (-1 - arsh)));
temp = (s32) (ii << -arsh);
if (temp == 0) {
bcmerror = -EBADE;
break;
}
}
a /= temp;
brsh = qq_nbits - 31 + 20;
if (brsh >= 0) {
b = (qq << (31 - qq_nbits));
temp = (s32) (ii >> brsh);
if (temp == 0) {
bcmerror = -EBADE;
break;
}
} else {
b = (qq << (31 - qq_nbits));
temp = (s32) (ii << -brsh);
if (temp == 0) {
bcmerror = -EBADE;
break;
}
}
b /= temp;
b -= a * a;
b = (s32) int_sqrt((unsigned long) b);
b -= (1 << 10);
if ((curr_core == PHY_CORE_0) && (core_mask & 0x1)) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
new_comp.a0 = (s16) a & 0x3ff;
new_comp.b0 = (s16) b & 0x3ff;
} else {
new_comp.a0 = (s16) b & 0x3ff;
new_comp.b0 = (s16) a & 0x3ff;
}
}
if ((curr_core == PHY_CORE_1) && (core_mask & 0x2)) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
new_comp.a1 = (s16) a & 0x3ff;
new_comp.b1 = (s16) b & 0x3ff;
} else {
new_comp.a1 = (s16) b & 0x3ff;
new_comp.b1 = (s16) a & 0x3ff;
}
}
}
if (bcmerror != 0) {
pr_debug("%s: Failed, cnt = %d\n", __func__, cal_retry);
if (cal_retry < CAL_RETRY_CNT) {
cal_retry++;
goto cal_try;
}
new_comp = old_comp;
}
wlc_phy_rx_iq_coeffs_nphy(pi, 1, &new_comp);
}
static void wlc_phy_rxcal_radio_setup_nphy(struct brcms_phy *pi, u8 rx_core)
{
u16 offtune_val;
u16 bias_g = 0;
u16 bias_a = 0;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (rx_core == PHY_CORE_0) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_PWRUP);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_ATTEN);
write_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_PWRUP,
0x3);
write_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_ATTEN,
0xaf);
} else {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_PWRUP);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_ATTEN);
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_PWRUP,
0x3);
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_ATTEN,
0x7f);
}
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_PWRUP);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_ATTEN);
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_PWRUP,
0x3);
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_ATTEN,
0xaf);
} else {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_PWRUP);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_ATTEN);
write_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_PWRUP,
0x3);
write_radio_reg(pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_ATTEN,
0x7f);
}
}
} else {
if (rx_core == PHY_CORE_0) {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX1);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX0);
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[2] =
read_radio_reg(pi,
RADIO_2056_RX_RXSPARE2 |
RADIO_2056_RX0);
pi->tx_rx_cal_radio_saveregs[3] =
read_radio_reg(pi,
RADIO_2056_TX_TXSPARE2 |
RADIO_2056_TX1);
}
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(pi,
RADIO_2056_RX_LNAA_MASTER
| RADIO_2056_RX0);
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_MASTER
| RADIO_2056_RX0, 0x40);
write_radio_reg(pi,
RADIO_2056_TX_TXSPARE2 |
RADIO_2056_TX1, bias_a);
write_radio_reg(pi,
RADIO_2056_RX_RXSPARE2 |
RADIO_2056_RX0, bias_a);
} else {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(pi,
RADIO_2056_RX_LNAA_TUNE
| RADIO_2056_RX0);
offtune_val =
(pi->tx_rx_cal_radio_saveregs
[2] & 0xF0) >> 8;
offtune_val =
(offtune_val <= 0x7) ? 0xF : 0;
mod_radio_reg(pi,
RADIO_2056_RX_LNAA_TUNE |
RADIO_2056_RX0, 0xF0,
(offtune_val << 8));
}
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX1, 0x9);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX0, 0x9);
} else {
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX0);
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX0, 0x40);
write_radio_reg(
pi,
RADIO_2056_TX_TXSPARE2
|
RADIO_2056_TX1, bias_g);
write_radio_reg(
pi,
RADIO_2056_RX_RXSPARE2
|
RADIO_2056_RX0, bias_g);
} else {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAG_TUNE
| RADIO_2056_RX0);
offtune_val =
(pi->
tx_rx_cal_radio_saveregs[2] &
0xF0) >> 8;
offtune_val =
(offtune_val <= 0x7) ? 0xF : 0;
mod_radio_reg(pi,
RADIO_2056_RX_LNAG_TUNE |
RADIO_2056_RX0, 0xF0,
(offtune_val << 8));
}
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX1, 0x6);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX0, 0x6);
}
} else {
pi->tx_rx_cal_radio_saveregs[0] =
read_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX0);
pi->tx_rx_cal_radio_saveregs[1] =
read_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX1);
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[2] =
read_radio_reg(pi,
RADIO_2056_RX_RXSPARE2 |
RADIO_2056_RX1);
pi->tx_rx_cal_radio_saveregs[3] =
read_radio_reg(pi,
RADIO_2056_TX_TXSPARE2 |
RADIO_2056_TX0);
}
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAA_MASTER
| RADIO_2056_RX1);
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_MASTER |
RADIO_2056_RX1, 0x40);
write_radio_reg(
pi,
RADIO_2056_TX_TXSPARE2
|
RADIO_2056_TX0, bias_a);
write_radio_reg(
pi,
RADIO_2056_RX_RXSPARE2
|
RADIO_2056_RX1, bias_a);
} else {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAA_TUNE
| RADIO_2056_RX1);
offtune_val =
(pi->
tx_rx_cal_radio_saveregs[2] &
0xF0) >> 8;
offtune_val =
(offtune_val <= 0x7) ? 0xF : 0;
mod_radio_reg(pi,
RADIO_2056_RX_LNAA_TUNE |
RADIO_2056_RX1, 0xF0,
(offtune_val << 8));
}
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX0, 0x9);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX1, 0x9);
} else {
if (pi->pubpi.radiorev >= 5) {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX1);
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX1, 0x40);
write_radio_reg(
pi,
RADIO_2056_TX_TXSPARE2
|
RADIO_2056_TX0, bias_g);
write_radio_reg(
pi,
RADIO_2056_RX_RXSPARE2
|
RADIO_2056_RX1, bias_g);
} else {
pi->tx_rx_cal_radio_saveregs[4] =
read_radio_reg(
pi,
RADIO_2056_RX_LNAG_TUNE
| RADIO_2056_RX1);
offtune_val =
(pi->
tx_rx_cal_radio_saveregs[2] &
0xF0) >> 8;
offtune_val =
(offtune_val <= 0x7) ? 0xF : 0;
mod_radio_reg(pi,
RADIO_2056_RX_LNAG_TUNE |
RADIO_2056_RX1, 0xF0,
(offtune_val << 8));
}
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX0, 0x6);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX1, 0x6);
}
}
}
}
static void wlc_phy_rxcal_radio_cleanup_nphy(struct brcms_phy *pi, u8 rx_core)
{
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
if (rx_core == PHY_CORE_0) {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_PWRUP,
pi->
tx_rx_cal_radio_saveregs[0]);
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_5G_ATTEN,
pi->
tx_rx_cal_radio_saveregs[1]);
} else {
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_PWRUP,
pi->
tx_rx_cal_radio_saveregs[0]);
write_radio_reg(
pi,
RADIO_2057_TX0_TXRXCOUPLE_2G_ATTEN,
pi->
tx_rx_cal_radio_saveregs[1]);
}
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_PWRUP,
pi->
tx_rx_cal_radio_saveregs[0]);
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_5G_ATTEN,
pi->
tx_rx_cal_radio_saveregs[1]);
} else {
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_PWRUP,
pi->
tx_rx_cal_radio_saveregs[0]);
write_radio_reg(
pi,
RADIO_2057_TX1_TXRXCOUPLE_2G_ATTEN,
pi->
tx_rx_cal_radio_saveregs[1]);
}
}
} else {
if (rx_core == PHY_CORE_0) {
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX1,
pi->tx_rx_cal_radio_saveregs[0]);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX0,
pi->tx_rx_cal_radio_saveregs[1]);
if (pi->pubpi.radiorev >= 5) {
write_radio_reg(pi,
RADIO_2056_RX_RXSPARE2 |
RADIO_2056_RX0,
pi->
tx_rx_cal_radio_saveregs[2]);
write_radio_reg(pi,
RADIO_2056_TX_TXSPARE2 |
RADIO_2056_TX1,
pi->
tx_rx_cal_radio_saveregs[3]);
}
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev >= 5)
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_MASTER
| RADIO_2056_RX0,
pi->
tx_rx_cal_radio_saveregs
[4]);
else
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_TUNE
| RADIO_2056_RX0,
pi->
tx_rx_cal_radio_saveregs
[4]);
} else {
if (pi->pubpi.radiorev >= 5)
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX0,
pi->
tx_rx_cal_radio_saveregs
[4]);
else
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_TUNE
| RADIO_2056_RX0,
pi->
tx_rx_cal_radio_saveregs
[4]);
}
} else {
write_radio_reg(pi,
RADIO_2056_TX_RXIQCAL_TXMUX |
RADIO_2056_TX0,
pi->tx_rx_cal_radio_saveregs[0]);
write_radio_reg(pi,
RADIO_2056_RX_RXIQCAL_RXMUX |
RADIO_2056_RX1,
pi->tx_rx_cal_radio_saveregs[1]);
if (pi->pubpi.radiorev >= 5) {
write_radio_reg(pi,
RADIO_2056_RX_RXSPARE2 |
RADIO_2056_RX1,
pi->
tx_rx_cal_radio_saveregs[2]);
write_radio_reg(pi,
RADIO_2056_TX_TXSPARE2 |
RADIO_2056_TX0,
pi->
tx_rx_cal_radio_saveregs[3]);
}
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (pi->pubpi.radiorev >= 5)
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_MASTER
| RADIO_2056_RX1,
pi->
tx_rx_cal_radio_saveregs
[4]);
else
write_radio_reg(
pi,
RADIO_2056_RX_LNAA_TUNE
| RADIO_2056_RX1,
pi->
tx_rx_cal_radio_saveregs
[4]);
} else {
if (pi->pubpi.radiorev >= 5)
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_MASTER
| RADIO_2056_RX1,
pi->
tx_rx_cal_radio_saveregs
[4]);
else
write_radio_reg(
pi,
RADIO_2056_RX_LNAG_TUNE
| RADIO_2056_RX1,
pi->
tx_rx_cal_radio_saveregs
[4]);
}
}
}
}
static void wlc_phy_rxcal_physetup_nphy(struct brcms_phy *pi, u8 rx_core)
{
u8 tx_core;
u16 rx_antval, tx_antval;
if (NREV_GE(pi->pubpi.phy_rev, 7))
tx_core = rx_core;
else
tx_core = (rx_core == PHY_CORE_0) ? 1 : 0;
pi->tx_rx_cal_phy_saveregs[0] = read_phy_reg(pi, 0xa2);
pi->tx_rx_cal_phy_saveregs[1] =
read_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0xa6 : 0xa7);
pi->tx_rx_cal_phy_saveregs[2] =
read_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0x8f : 0xa5);
pi->tx_rx_cal_phy_saveregs[3] = read_phy_reg(pi, 0x91);
pi->tx_rx_cal_phy_saveregs[4] = read_phy_reg(pi, 0x92);
pi->tx_rx_cal_phy_saveregs[5] = read_phy_reg(pi, 0x7a);
pi->tx_rx_cal_phy_saveregs[6] = read_phy_reg(pi, 0x7d);
pi->tx_rx_cal_phy_saveregs[7] = read_phy_reg(pi, 0xe7);
pi->tx_rx_cal_phy_saveregs[8] = read_phy_reg(pi, 0xec);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
pi->tx_rx_cal_phy_saveregs[11] = read_phy_reg(pi, 0x342);
pi->tx_rx_cal_phy_saveregs[12] = read_phy_reg(pi, 0x343);
pi->tx_rx_cal_phy_saveregs[13] = read_phy_reg(pi, 0x346);
pi->tx_rx_cal_phy_saveregs[14] = read_phy_reg(pi, 0x347);
}
pi->tx_rx_cal_phy_saveregs[9] = read_phy_reg(pi, 0x297);
pi->tx_rx_cal_phy_saveregs[10] = read_phy_reg(pi, 0x29b);
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 0), (0) << 0);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mod_phy_reg(pi, 0xa2, (0xf << 0), (1 << tx_core) << 0);
mod_phy_reg(pi, 0xa2, (0xf << 12), (1 << (1 - rx_core)) << 12);
} else {
mod_phy_reg(pi, 0xa2, (0xf << 12), (1 << tx_core) << 12);
mod_phy_reg(pi, 0xa2, (0xf << 0), (1 << tx_core) << 0);
mod_phy_reg(pi, 0xa2, (0xf << 4), (1 << rx_core) << 4);
mod_phy_reg(pi, 0xa2, (0xf << 8), (1 << rx_core) << 8);
}
mod_phy_reg(pi, ((rx_core == PHY_CORE_0) ? 0xa6 : 0xa7), (0x1 << 2), 0);
mod_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0x8f : 0xa5,
(0x1 << 2), (0x1 << 2));
if (NREV_LT(pi->pubpi.phy_rev, 7)) {
mod_phy_reg(pi, ((rx_core == PHY_CORE_0) ? 0xa6 : 0xa7),
(0x1 << 0) | (0x1 << 1), 0);
mod_phy_reg(pi, (rx_core == PHY_CORE_0) ?
0x8f : 0xa5,
(0x1 << 0) | (0x1 << 1), (0x1 << 0) | (0x1 << 1));
}
wlc_phy_rfctrlintc_override_nphy(pi, NPHY_RfctrlIntc_override_PA, 0,
RADIO_MIMO_CORESEL_CORE1 |
RADIO_MIMO_CORESEL_CORE2);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 3),
0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID0);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 9), 0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 10), 1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 0), 1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 1), 1, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID2);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 11), 0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
if (CHSPEC_IS40(pi->radio_chanspec))
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 7),
2, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
else
wlc_phy_rfctrl_override_nphy_rev7(
pi,
(0x1 << 7),
0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 7),
0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
wlc_phy_rfctrl_override_nphy_rev7(pi, (0x1 << 5), 0, 0, 0,
NPHY_REV7_RFCTRLOVERRIDE_ID1);
} else {
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 3), 0, 3, 0);
}
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RX2TX);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
0x1, rx_core + 1);
} else {
if (rx_core == PHY_CORE_0) {
rx_antval = 0x1;
tx_antval = 0x8;
} else {
rx_antval = 0x4;
tx_antval = 0x2;
}
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
rx_antval, rx_core + 1);
wlc_phy_rfctrlintc_override_nphy(pi,
NPHY_RfctrlIntc_override_TRSW,
tx_antval, tx_core + 1);
}
}
static void wlc_phy_rxcal_phycleanup_nphy(struct brcms_phy *pi, u8 rx_core)
{
write_phy_reg(pi, 0xa2, pi->tx_rx_cal_phy_saveregs[0]);
write_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0xa6 : 0xa7,
pi->tx_rx_cal_phy_saveregs[1]);
write_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0x8f : 0xa5,
pi->tx_rx_cal_phy_saveregs[2]);
write_phy_reg(pi, 0x91, pi->tx_rx_cal_phy_saveregs[3]);
write_phy_reg(pi, 0x92, pi->tx_rx_cal_phy_saveregs[4]);
write_phy_reg(pi, 0x7a, pi->tx_rx_cal_phy_saveregs[5]);
write_phy_reg(pi, 0x7d, pi->tx_rx_cal_phy_saveregs[6]);
write_phy_reg(pi, 0xe7, pi->tx_rx_cal_phy_saveregs[7]);
write_phy_reg(pi, 0xec, pi->tx_rx_cal_phy_saveregs[8]);
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
write_phy_reg(pi, 0x342, pi->tx_rx_cal_phy_saveregs[11]);
write_phy_reg(pi, 0x343, pi->tx_rx_cal_phy_saveregs[12]);
write_phy_reg(pi, 0x346, pi->tx_rx_cal_phy_saveregs[13]);
write_phy_reg(pi, 0x347, pi->tx_rx_cal_phy_saveregs[14]);
}
write_phy_reg(pi, 0x297, pi->tx_rx_cal_phy_saveregs[9]);
write_phy_reg(pi, 0x29b, pi->tx_rx_cal_phy_saveregs[10]);
}
static void
wlc_phy_rxcal_gainctrl_nphy_rev5(struct brcms_phy *pi, u8 rx_core,
u16 *rxgain, u8 cal_type)
{
u16 num_samps;
struct phy_iq_est est[PHY_CORE_MAX];
u8 tx_core;
struct nphy_iq_comp save_comp, zero_comp;
u32 i_pwr, q_pwr, curr_pwr, optim_pwr = 0, prev_pwr = 0,
thresh_pwr = 10000;
s16 desired_log2_pwr, actual_log2_pwr, delta_pwr;
bool gainctrl_done = false;
u8 mix_tia_gain = 3;
s8 optim_gaintbl_index = 0, prev_gaintbl_index = 0;
s8 curr_gaintbl_index = 3;
u8 gainctrl_dirn = NPHY_RXCAL_GAIN_INIT;
const struct nphy_ipa_txrxgain *nphy_rxcal_gaintbl;
u16 hpvga, lpf_biq1, lpf_biq0, lna2, lna1;
int fine_gain_idx;
s8 txpwrindex;
u16 nphy_rxcal_txgain[2];
if (NREV_GE(pi->pubpi.phy_rev, 7))
tx_core = rx_core;
else
tx_core = 1 - rx_core;
num_samps = 1024;
desired_log2_pwr = (cal_type == 0) ? 13 : 13;
wlc_phy_rx_iq_coeffs_nphy(pi, 0, &save_comp);
zero_comp.a0 = zero_comp.b0 = zero_comp.a1 = zero_comp.b1 = 0x0;
wlc_phy_rx_iq_coeffs_nphy(pi, 1, &zero_comp);
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7))
mix_tia_gain = 3;
else if (NREV_GE(pi->pubpi.phy_rev, 4))
mix_tia_gain = 4;
else
mix_tia_gain = 6;
if (NREV_GE(pi->pubpi.phy_rev, 7))
nphy_rxcal_gaintbl = nphy_ipa_rxcal_gaintbl_5GHz_rev7;
else
nphy_rxcal_gaintbl = nphy_ipa_rxcal_gaintbl_5GHz;
} else {
if (NREV_GE(pi->pubpi.phy_rev, 7))
nphy_rxcal_gaintbl = nphy_ipa_rxcal_gaintbl_2GHz_rev7;
else
nphy_rxcal_gaintbl = nphy_ipa_rxcal_gaintbl_2GHz;
}
do {
hpvga = (NREV_GE(pi->pubpi.phy_rev, 7)) ?
0 : nphy_rxcal_gaintbl[curr_gaintbl_index].hpvga;
lpf_biq1 = nphy_rxcal_gaintbl[curr_gaintbl_index].lpf_biq1;
lpf_biq0 = nphy_rxcal_gaintbl[curr_gaintbl_index].lpf_biq0;
lna2 = nphy_rxcal_gaintbl[curr_gaintbl_index].lna2;
lna1 = nphy_rxcal_gaintbl[curr_gaintbl_index].lna1;
txpwrindex = nphy_rxcal_gaintbl[curr_gaintbl_index].txpwrindex;
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_rxgain,
((lpf_biq1 << 12) |
(lpf_biq0 << 8) |
(mix_tia_gain << 4) | (lna2 << 2)
| lna1), 0x3, 0);
else
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 12),
((hpvga << 12) |
(lpf_biq1 << 10) |
(lpf_biq0 << 8) |
(mix_tia_gain << 4) |
(lna2 << 2) | lna1), 0x3,
0);
pi->nphy_rxcal_pwr_idx[tx_core] = txpwrindex;
if (txpwrindex == -1) {
nphy_rxcal_txgain[0] = 0x8ff0 | pi->nphy_gmval;
nphy_rxcal_txgain[1] = 0x8ff0 | pi->nphy_gmval;
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ,
2, 0x110, 16,
nphy_rxcal_txgain);
} else {
wlc_phy_txpwr_index_nphy(pi, tx_core + 1, txpwrindex,
false);
}
wlc_phy_tx_tone_nphy(pi, (CHSPEC_IS40(pi->radio_chanspec)) ?
NPHY_RXCAL_TONEFREQ_40MHz :
NPHY_RXCAL_TONEFREQ_20MHz,
NPHY_RXCAL_TONEAMP, 0, cal_type, false);
wlc_phy_rx_iq_est_nphy(pi, est, num_samps, 32, 0);
i_pwr = (est[rx_core].i_pwr + num_samps / 2) / num_samps;
q_pwr = (est[rx_core].q_pwr + num_samps / 2) / num_samps;
curr_pwr = i_pwr + q_pwr;
switch (gainctrl_dirn) {
case NPHY_RXCAL_GAIN_INIT:
if (curr_pwr > thresh_pwr) {
gainctrl_dirn = NPHY_RXCAL_GAIN_DOWN;
prev_gaintbl_index = curr_gaintbl_index;
curr_gaintbl_index--;
} else {
gainctrl_dirn = NPHY_RXCAL_GAIN_UP;
prev_gaintbl_index = curr_gaintbl_index;
curr_gaintbl_index++;
}
break;
case NPHY_RXCAL_GAIN_UP:
if (curr_pwr > thresh_pwr) {
gainctrl_done = true;
optim_pwr = prev_pwr;
optim_gaintbl_index = prev_gaintbl_index;
} else {
prev_gaintbl_index = curr_gaintbl_index;
curr_gaintbl_index++;
}
break;
case NPHY_RXCAL_GAIN_DOWN:
if (curr_pwr > thresh_pwr) {
prev_gaintbl_index = curr_gaintbl_index;
curr_gaintbl_index--;
} else {
gainctrl_done = true;
optim_pwr = curr_pwr;
optim_gaintbl_index = curr_gaintbl_index;
}
break;
default:
break;
}
if ((curr_gaintbl_index < 0) ||
(curr_gaintbl_index > NPHY_IPA_RXCAL_MAXGAININDEX)) {
gainctrl_done = true;
optim_pwr = curr_pwr;
optim_gaintbl_index = prev_gaintbl_index;
} else {
prev_pwr = curr_pwr;
}
wlc_phy_stopplayback_nphy(pi);
} while (!gainctrl_done);
hpvga = nphy_rxcal_gaintbl[optim_gaintbl_index].hpvga;
lpf_biq1 = nphy_rxcal_gaintbl[optim_gaintbl_index].lpf_biq1;
lpf_biq0 = nphy_rxcal_gaintbl[optim_gaintbl_index].lpf_biq0;
lna2 = nphy_rxcal_gaintbl[optim_gaintbl_index].lna2;
lna1 = nphy_rxcal_gaintbl[optim_gaintbl_index].lna1;
txpwrindex = nphy_rxcal_gaintbl[optim_gaintbl_index].txpwrindex;
actual_log2_pwr = wlc_phy_nbits(optim_pwr);
delta_pwr = desired_log2_pwr - actual_log2_pwr;
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
fine_gain_idx = (int)lpf_biq1 + delta_pwr;
if (fine_gain_idx + (int)lpf_biq0 > 10)
lpf_biq1 = 10 - lpf_biq0;
else
lpf_biq1 = (u16) max(fine_gain_idx, 0);
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_rxgain,
((lpf_biq1 << 12) |
(lpf_biq0 << 8) |
(mix_tia_gain << 4) |
(lna2 << 2) | lna1), 0x3,
0);
} else {
hpvga = (u16) max(min(((int)hpvga) + delta_pwr, 10), 0);
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 12),
((hpvga << 12) |
(lpf_biq1 << 10) |
(lpf_biq0 << 8) |
(mix_tia_gain << 4) |
(lna2 << 2) |
lna1), 0x3, 0);
}
if (rxgain != NULL) {
*rxgain++ = lna1;
*rxgain++ = lna2;
*rxgain++ = mix_tia_gain;
*rxgain++ = lpf_biq0;
*rxgain++ = lpf_biq1;
*rxgain = hpvga;
}
wlc_phy_rx_iq_coeffs_nphy(pi, 1, &save_comp);
}
static void
wlc_phy_rxcal_gainctrl_nphy(struct brcms_phy *pi, u8 rx_core, u16 *rxgain,
u8 cal_type)
{
wlc_phy_rxcal_gainctrl_nphy_rev5(pi, rx_core, rxgain, cal_type);
}
static u8
wlc_phy_rc_sweep_nphy(struct brcms_phy *pi, u8 core_idx, u8 loopback_type)
{
u32 target_bws[2] = { 9500, 21000 };
u32 ref_tones[2] = { 3000, 6000 };
u32 target_bw, ref_tone;
u32 target_pwr_ratios[2] = { 28606, 18468 };
u32 target_pwr_ratio, pwr_ratio, last_pwr_ratio = 0;
u16 start_rccal_ovr_val = 128;
u16 txlpf_rccal_lpc_ovr_val = 128;
u16 rxlpf_rccal_hpc_ovr_val = 159;
u16 orig_txlpf_rccal_lpc_ovr_val;
u16 orig_rxlpf_rccal_hpc_ovr_val;
u16 radio_addr_offset_rx;
u16 radio_addr_offset_tx;
u16 orig_dcBypass;
u16 orig_RxStrnFilt40Num[6];
u16 orig_RxStrnFilt40Den[4];
u16 orig_rfctrloverride[2];
u16 orig_rfctrlauxreg[2];
u16 orig_rfctrlrssiothers;
u16 tx_lpf_bw = 4;
u16 rx_lpf_bw, rx_lpf_bws[2] = { 2, 4 };
u16 lpf_hpc = 7, hpvga_hpc = 7;
s8 rccal_stepsize;
u16 rccal_val, last_rccal_val = 0, best_rccal_val = 0;
u32 ref_iq_vals = 0, target_iq_vals = 0;
u16 num_samps, log_num_samps = 10;
struct phy_iq_est est[PHY_CORE_MAX];
if (NREV_GE(pi->pubpi.phy_rev, 7))
return 0;
num_samps = (1 << log_num_samps);
if (CHSPEC_IS40(pi->radio_chanspec)) {
target_bw = target_bws[1];
target_pwr_ratio = target_pwr_ratios[1];
ref_tone = ref_tones[1];
rx_lpf_bw = rx_lpf_bws[1];
} else {
target_bw = target_bws[0];
target_pwr_ratio = target_pwr_ratios[0];
ref_tone = ref_tones[0];
rx_lpf_bw = rx_lpf_bws[0];
}
if (core_idx == 0) {
radio_addr_offset_rx = RADIO_2056_RX0;
radio_addr_offset_tx =
(loopback_type == 0) ? RADIO_2056_TX0 : RADIO_2056_TX1;
} else {
radio_addr_offset_rx = RADIO_2056_RX1;
radio_addr_offset_tx =
(loopback_type == 0) ? RADIO_2056_TX1 : RADIO_2056_TX0;
}
orig_txlpf_rccal_lpc_ovr_val =
read_radio_reg(pi,
(RADIO_2056_TX_TXLPF_RCCAL |
radio_addr_offset_tx));
orig_rxlpf_rccal_hpc_ovr_val =
read_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_HPC |
radio_addr_offset_rx));
orig_dcBypass = ((read_phy_reg(pi, 0x48) >> 8) & 1);
orig_RxStrnFilt40Num[0] = read_phy_reg(pi, 0x267);
orig_RxStrnFilt40Num[1] = read_phy_reg(pi, 0x268);
orig_RxStrnFilt40Num[2] = read_phy_reg(pi, 0x269);
orig_RxStrnFilt40Den[0] = read_phy_reg(pi, 0x26a);
orig_RxStrnFilt40Den[1] = read_phy_reg(pi, 0x26b);
orig_RxStrnFilt40Num[3] = read_phy_reg(pi, 0x26c);
orig_RxStrnFilt40Num[4] = read_phy_reg(pi, 0x26d);
orig_RxStrnFilt40Num[5] = read_phy_reg(pi, 0x26e);
orig_RxStrnFilt40Den[2] = read_phy_reg(pi, 0x26f);
orig_RxStrnFilt40Den[3] = read_phy_reg(pi, 0x270);
orig_rfctrloverride[0] = read_phy_reg(pi, 0xe7);
orig_rfctrloverride[1] = read_phy_reg(pi, 0xec);
orig_rfctrlauxreg[0] = read_phy_reg(pi, 0xf8);
orig_rfctrlauxreg[1] = read_phy_reg(pi, 0xfa);
orig_rfctrlrssiothers = read_phy_reg(pi, (core_idx == 0) ? 0x7a : 0x7d);
write_radio_reg(pi, (RADIO_2056_TX_TXLPF_RCCAL | radio_addr_offset_tx),
txlpf_rccal_lpc_ovr_val);
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_HPC | radio_addr_offset_rx),
rxlpf_rccal_hpc_ovr_val);
mod_phy_reg(pi, 0x48, (0x1 << 8), (0x1 << 8));
write_phy_reg(pi, 0x267, 0x02d4);
write_phy_reg(pi, 0x268, 0x0000);
write_phy_reg(pi, 0x269, 0x0000);
write_phy_reg(pi, 0x26a, 0x0000);
write_phy_reg(pi, 0x26b, 0x0000);
write_phy_reg(pi, 0x26c, 0x02d4);
write_phy_reg(pi, 0x26d, 0x0000);
write_phy_reg(pi, 0x26e, 0x0000);
write_phy_reg(pi, 0x26f, 0x0000);
write_phy_reg(pi, 0x270, 0x0000);
or_phy_reg(pi, (core_idx == 0) ? 0xe7 : 0xec, (0x1 << 8));
or_phy_reg(pi, (core_idx == 0) ? 0xec : 0xe7, (0x1 << 15));
or_phy_reg(pi, (core_idx == 0) ? 0xe7 : 0xec, (0x1 << 9));
or_phy_reg(pi, (core_idx == 0) ? 0xe7 : 0xec, (0x1 << 10));
mod_phy_reg(pi, (core_idx == 0) ? 0xfa : 0xf8,
(0x7 << 10), (tx_lpf_bw << 10));
mod_phy_reg(pi, (core_idx == 0) ? 0xf8 : 0xfa,
(0x7 << 0), (hpvga_hpc << 0));
mod_phy_reg(pi, (core_idx == 0) ? 0xf8 : 0xfa,
(0x7 << 4), (lpf_hpc << 4));
mod_phy_reg(pi, (core_idx == 0) ? 0x7a : 0x7d,
(0x7 << 8), (rx_lpf_bw << 8));
rccal_stepsize = 16;
rccal_val = start_rccal_ovr_val + rccal_stepsize;
while (rccal_stepsize >= 0) {
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_LPC |
radio_addr_offset_rx), rccal_val);
if (rccal_stepsize == 16) {
wlc_phy_tx_tone_nphy(pi, ref_tone, NPHY_RXCAL_TONEAMP,
0, 1, false);
udelay(2);
wlc_phy_rx_iq_est_nphy(pi, est, num_samps, 32, 0);
if (core_idx == 0)
ref_iq_vals =
max_t(u32, (est[0].i_pwr +
est[0].q_pwr) >>
(log_num_samps + 1),
1);
else
ref_iq_vals =
max_t(u32, (est[1].i_pwr +
est[1].q_pwr) >>
(log_num_samps + 1),
1);
wlc_phy_tx_tone_nphy(pi, target_bw, NPHY_RXCAL_TONEAMP,
0, 1, false);
udelay(2);
}
wlc_phy_rx_iq_est_nphy(pi, est, num_samps, 32, 0);
if (core_idx == 0)
target_iq_vals = (est[0].i_pwr + est[0].q_pwr) >>
(log_num_samps + 1);
else
target_iq_vals =
(est[1].i_pwr +
est[1].q_pwr) >> (log_num_samps + 1);
pwr_ratio = (uint) ((target_iq_vals << 16) / ref_iq_vals);
if (rccal_stepsize == 0)
rccal_stepsize--;
else if (rccal_stepsize == 1) {
last_rccal_val = rccal_val;
rccal_val += (pwr_ratio > target_pwr_ratio) ? 1 : -1;
last_pwr_ratio = pwr_ratio;
rccal_stepsize--;
} else {
rccal_stepsize = (rccal_stepsize >> 1);
rccal_val += ((pwr_ratio > target_pwr_ratio) ?
rccal_stepsize : (-rccal_stepsize));
}
if (rccal_stepsize == -1) {
best_rccal_val =
(abs((int)last_pwr_ratio -
(int)target_pwr_ratio) <
abs((int)pwr_ratio -
(int)target_pwr_ratio)) ? last_rccal_val :
rccal_val;
if (CHSPEC_IS40(pi->radio_chanspec)) {
if ((best_rccal_val > 140)
|| (best_rccal_val < 135))
best_rccal_val = 138;
} else {
if ((best_rccal_val > 142)
|| (best_rccal_val < 137))
best_rccal_val = 140;
}
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_LPC |
radio_addr_offset_rx), best_rccal_val);
}
}
wlc_phy_stopplayback_nphy(pi);
write_radio_reg(pi, (RADIO_2056_TX_TXLPF_RCCAL | radio_addr_offset_tx),
orig_txlpf_rccal_lpc_ovr_val);
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_HPC | radio_addr_offset_rx),
orig_rxlpf_rccal_hpc_ovr_val);
mod_phy_reg(pi, 0x48, (0x1 << 8), (orig_dcBypass << 8));
write_phy_reg(pi, 0x267, orig_RxStrnFilt40Num[0]);
write_phy_reg(pi, 0x268, orig_RxStrnFilt40Num[1]);
write_phy_reg(pi, 0x269, orig_RxStrnFilt40Num[2]);
write_phy_reg(pi, 0x26a, orig_RxStrnFilt40Den[0]);
write_phy_reg(pi, 0x26b, orig_RxStrnFilt40Den[1]);
write_phy_reg(pi, 0x26c, orig_RxStrnFilt40Num[3]);
write_phy_reg(pi, 0x26d, orig_RxStrnFilt40Num[4]);
write_phy_reg(pi, 0x26e, orig_RxStrnFilt40Num[5]);
write_phy_reg(pi, 0x26f, orig_RxStrnFilt40Den[2]);
write_phy_reg(pi, 0x270, orig_RxStrnFilt40Den[3]);
write_phy_reg(pi, 0xe7, orig_rfctrloverride[0]);
write_phy_reg(pi, 0xec, orig_rfctrloverride[1]);
write_phy_reg(pi, 0xf8, orig_rfctrlauxreg[0]);
write_phy_reg(pi, 0xfa, orig_rfctrlauxreg[1]);
write_phy_reg(pi, (core_idx == 0) ? 0x7a : 0x7d, orig_rfctrlrssiothers);
pi->nphy_anarxlpf_adjusted = false;
return best_rccal_val - 0x80;
}
static int wlc_phy_cal_rxiq_nphy_rev3(struct brcms_phy *pi,
struct nphy_txgains target_gain,
u8 cal_type, bool debug)
{
u16 orig_BBConfig;
u8 core_no, rx_core;
u8 best_rccal[2];
u16 gain_save[2];
u16 cal_gain[2];
struct nphy_iqcal_params cal_params[2];
u8 rxcore_state;
s8 rxlpf_rccal_hpc, txlpf_rccal_lpc;
s8 txlpf_idac;
bool phyhang_avoid_state = false;
bool skip_rxiqcal = false;
orig_BBConfig = read_phy_reg(pi, 0x01);
mod_phy_reg(pi, 0x01, (0x1 << 15), 0);
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (NREV_GE(pi->pubpi.phy_rev, 4)) {
phyhang_avoid_state = pi->phyhang_avoid;
pi->phyhang_avoid = false;
}
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, gain_save);
for (core_no = 0; core_no <= 1; core_no++) {
wlc_phy_iqcal_gainparams_nphy(pi, core_no, target_gain,
&cal_params[core_no]);
cal_gain[core_no] = cal_params[core_no].cal_gain;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, cal_gain);
rxcore_state = wlc_phy_rxcore_getstate_nphy(
(struct brcms_phy_pub *) pi);
for (rx_core = 0; rx_core < pi->pubpi.phy_corenum; rx_core++) {
skip_rxiqcal =
((rxcore_state & (1 << rx_core)) == 0) ? true : false;
wlc_phy_rxcal_physetup_nphy(pi, rx_core);
wlc_phy_rxcal_radio_setup_nphy(pi, rx_core);
if ((!skip_rxiqcal) && ((cal_type == 0) || (cal_type == 2))) {
wlc_phy_rxcal_gainctrl_nphy(pi, rx_core, NULL, 0);
wlc_phy_tx_tone_nphy(pi,
(CHSPEC_IS40(
pi->radio_chanspec)) ?
NPHY_RXCAL_TONEFREQ_40MHz :
NPHY_RXCAL_TONEFREQ_20MHz,
NPHY_RXCAL_TONEAMP, 0, cal_type,
false);
if (debug)
mdelay(WAIT_FOR_SCOPE);
wlc_phy_calc_rx_iq_comp_nphy(pi, rx_core + 1);
wlc_phy_stopplayback_nphy(pi);
}
if (((cal_type == 1) || (cal_type == 2))
&& NREV_LT(pi->pubpi.phy_rev, 7)) {
if (rx_core == PHY_CORE_1) {
if (rxcore_state == 1)
wlc_phy_rxcore_setstate_nphy(
(struct brcms_phy_pub *) pi, 3);
wlc_phy_rxcal_gainctrl_nphy(pi, rx_core, NULL,
1);
best_rccal[rx_core] =
wlc_phy_rc_sweep_nphy(pi, rx_core, 1);
pi->nphy_rccal_value = best_rccal[rx_core];
if (rxcore_state == 1)
wlc_phy_rxcore_setstate_nphy(
(struct brcms_phy_pub *) pi,
rxcore_state);
}
}
wlc_phy_rxcal_radio_cleanup_nphy(pi, rx_core);
wlc_phy_rxcal_phycleanup_nphy(pi, rx_core);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
}
if ((cal_type == 1) || (cal_type == 2)) {
best_rccal[0] = best_rccal[1];
write_radio_reg(pi,
(RADIO_2056_RX_RXLPF_RCCAL_LPC |
RADIO_2056_RX0), (best_rccal[0] | 0x80));
for (rx_core = 0; rx_core < pi->pubpi.phy_corenum; rx_core++) {
rxlpf_rccal_hpc =
(((int)best_rccal[rx_core] - 12) >> 1) + 10;
txlpf_rccal_lpc = ((int)best_rccal[rx_core] - 12) + 10;
if (PHY_IPA(pi)) {
txlpf_rccal_lpc +=
(pi->bw == WL_CHANSPEC_BW_40) ? 24 : 12;
txlpf_idac = (pi->bw == WL_CHANSPEC_BW_40) ?
0x0e : 0x13;
WRITE_RADIO_REG2(pi, RADIO_2056, TX, rx_core,
TXLPF_IDAC_4, txlpf_idac);
}
rxlpf_rccal_hpc = max(min_t(u8, rxlpf_rccal_hpc, 31),
0);
txlpf_rccal_lpc = max(min_t(u8, txlpf_rccal_lpc, 31),
0);
write_radio_reg(pi, (RADIO_2056_RX_RXLPF_RCCAL_HPC |
((rx_core ==
PHY_CORE_0) ? RADIO_2056_RX0 :
RADIO_2056_RX1)),
(rxlpf_rccal_hpc | 0x80));
write_radio_reg(pi, (RADIO_2056_TX_TXLPF_RCCAL |
((rx_core ==
PHY_CORE_0) ? RADIO_2056_TX0 :
RADIO_2056_TX1)),
(txlpf_rccal_lpc | 0x80));
}
}
write_phy_reg(pi, 0x01, orig_BBConfig);
wlc_phy_resetcca_nphy(pi);
if (NREV_GE(pi->pubpi.phy_rev, 7))
wlc_phy_rfctrl_override_1tomany_nphy(
pi,
NPHY_REV7_RfctrlOverride_cmd_rxgain,
0, 0x3, 1);
else
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 12), 0, 0x3, 1);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
gain_save);
if (NREV_GE(pi->pubpi.phy_rev, 4))
pi->phyhang_avoid = phyhang_avoid_state;
wlc_phy_stay_in_carriersearch_nphy(pi, false);
return 0;
}
static int
wlc_phy_cal_rxiq_nphy_rev2(struct brcms_phy *pi,
struct nphy_txgains target_gain, bool debug)
{
struct phy_iq_est est[PHY_CORE_MAX];
u8 core_num, rx_core, tx_core;
u16 lna_vals[] = { 0x3, 0x3, 0x1 };
u16 hpf1_vals[] = { 0x7, 0x2, 0x0 };
u16 hpf2_vals[] = { 0x2, 0x0, 0x0 };
s16 curr_hpf1, curr_hpf2, curr_hpf, curr_lna;
s16 desired_log2_pwr, actual_log2_pwr, hpf_change;
u16 orig_RfseqCoreActv, orig_AfectrlCore, orig_AfectrlOverride;
u16 orig_RfctrlIntcRx, orig_RfctrlIntcTx;
u16 num_samps;
u32 i_pwr, q_pwr, tot_pwr[3];
u8 gain_pass, use_hpf_num;
u16 mask, val1, val2;
u16 core_no;
u16 gain_save[2];
u16 cal_gain[2];
struct nphy_iqcal_params cal_params[2];
u8 phy_bw;
int bcmerror = 0;
bool first_playtone = true;
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (NREV_LT(pi->pubpi.phy_rev, 2))
wlc_phy_reapply_txcal_coeffs_nphy(pi);
wlc_phy_table_read_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, gain_save);
for (core_no = 0; core_no <= 1; core_no++) {
wlc_phy_iqcal_gainparams_nphy(pi, core_no, target_gain,
&cal_params[core_no]);
cal_gain[core_no] = cal_params[core_no].cal_gain;
}
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16, cal_gain);
num_samps = 1024;
desired_log2_pwr = 13;
for (core_num = 0; core_num < 2; core_num++) {
rx_core = core_num;
tx_core = 1 - core_num;
orig_RfseqCoreActv = read_phy_reg(pi, 0xa2);
orig_AfectrlCore = read_phy_reg(pi, (rx_core == PHY_CORE_0) ?
0xa6 : 0xa7);
orig_AfectrlOverride = read_phy_reg(pi, 0xa5);
orig_RfctrlIntcRx = read_phy_reg(pi, (rx_core == PHY_CORE_0) ?
0x91 : 0x92);
orig_RfctrlIntcTx = read_phy_reg(pi, (tx_core == PHY_CORE_0) ?
0x91 : 0x92);
mod_phy_reg(pi, 0xa2, (0xf << 12), (1 << tx_core) << 12);
mod_phy_reg(pi, 0xa2, (0xf << 0), (1 << tx_core) << 0);
or_phy_reg(pi, ((rx_core == PHY_CORE_0) ? 0xa6 : 0xa7),
((0x1 << 1) | (0x1 << 2)));
or_phy_reg(pi, 0xa5, ((0x1 << 1) | (0x1 << 2)));
if (((pi->nphy_rxcalparams) & 0xff000000))
write_phy_reg(pi,
(rx_core == PHY_CORE_0) ? 0x91 : 0x92,
(CHSPEC_IS5G(pi->radio_chanspec) ?
0x140 : 0x110));
else
write_phy_reg(pi,
(rx_core == PHY_CORE_0) ? 0x91 : 0x92,
(CHSPEC_IS5G(pi->radio_chanspec) ?
0x180 : 0x120));
write_phy_reg(pi, (tx_core == PHY_CORE_0) ? 0x91 : 0x92,
(CHSPEC_IS5G(pi->radio_chanspec) ? 0x148 :
0x114));
mask = RADIO_2055_COUPLE_RX_MASK | RADIO_2055_COUPLE_TX_MASK;
if (rx_core == PHY_CORE_0) {
val1 = RADIO_2055_COUPLE_RX_MASK;
val2 = RADIO_2055_COUPLE_TX_MASK;
} else {
val1 = RADIO_2055_COUPLE_TX_MASK;
val2 = RADIO_2055_COUPLE_RX_MASK;
}
if ((pi->nphy_rxcalparams & 0x10000)) {
mod_radio_reg(pi, RADIO_2055_CORE1_GEN_SPARE2, mask,
val1);
mod_radio_reg(pi, RADIO_2055_CORE2_GEN_SPARE2, mask,
val2);
}
for (gain_pass = 0; gain_pass < 4; gain_pass++) {
if (debug)
mdelay(WAIT_FOR_SCOPE);
if (gain_pass < 3) {
curr_lna = lna_vals[gain_pass];
curr_hpf1 = hpf1_vals[gain_pass];
curr_hpf2 = hpf2_vals[gain_pass];
} else {
if (tot_pwr[1] > 10000) {
curr_lna = lna_vals[2];
curr_hpf1 = hpf1_vals[2];
curr_hpf2 = hpf2_vals[2];
use_hpf_num = 1;
curr_hpf = curr_hpf1;
actual_log2_pwr =
wlc_phy_nbits(tot_pwr[2]);
} else {
if (tot_pwr[0] > 10000) {
curr_lna = lna_vals[1];
curr_hpf1 = hpf1_vals[1];
curr_hpf2 = hpf2_vals[1];
use_hpf_num = 1;
curr_hpf = curr_hpf1;
actual_log2_pwr =
wlc_phy_nbits(
tot_pwr[1]);
} else {
curr_lna = lna_vals[0];
curr_hpf1 = hpf1_vals[0];
curr_hpf2 = hpf2_vals[0];
use_hpf_num = 2;
curr_hpf = curr_hpf2;
actual_log2_pwr =
wlc_phy_nbits(
tot_pwr[0]);
}
}
hpf_change = desired_log2_pwr - actual_log2_pwr;
curr_hpf += hpf_change;
curr_hpf = max(min_t(u16, curr_hpf, 10), 0);
if (use_hpf_num == 1)
curr_hpf1 = curr_hpf;
else
curr_hpf2 = curr_hpf;
}
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 10),
((curr_hpf2 << 8) |
(curr_hpf1 << 4) |
(curr_lna << 2)), 0x3, 0);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
wlc_phy_stopplayback_nphy(pi);
if (first_playtone) {
bcmerror = wlc_phy_tx_tone_nphy(pi, 4000,
(u16) (pi->nphy_rxcalparams &
0xffff), 0, 0, true);
first_playtone = false;
} else {
phy_bw = (CHSPEC_IS40(pi->radio_chanspec)) ?
40 : 20;
wlc_phy_runsamples_nphy(pi, phy_bw * 8, 0xffff,
0, 0, 0, true);
}
if (bcmerror == 0) {
if (gain_pass < 3) {
wlc_phy_rx_iq_est_nphy(pi, est,
num_samps, 32,
0);
i_pwr = (est[rx_core].i_pwr +
num_samps / 2) / num_samps;
q_pwr = (est[rx_core].q_pwr +
num_samps / 2) / num_samps;
tot_pwr[gain_pass] = i_pwr + q_pwr;
} else {
wlc_phy_calc_rx_iq_comp_nphy(pi,
(1 <<
rx_core));
}
wlc_phy_stopplayback_nphy(pi);
}
if (bcmerror != 0)
break;
}
and_radio_reg(pi, RADIO_2055_CORE1_GEN_SPARE2, ~mask);
and_radio_reg(pi, RADIO_2055_CORE2_GEN_SPARE2, ~mask);
write_phy_reg(pi, (tx_core == PHY_CORE_0) ? 0x91 :
0x92, orig_RfctrlIntcTx);
write_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0x91 :
0x92, orig_RfctrlIntcRx);
write_phy_reg(pi, 0xa5, orig_AfectrlOverride);
write_phy_reg(pi, (rx_core == PHY_CORE_0) ? 0xa6 :
0xa7, orig_AfectrlCore);
write_phy_reg(pi, 0xa2, orig_RfseqCoreActv);
if (bcmerror != 0)
break;
}
wlc_phy_rfctrl_override_nphy(pi, (0x1 << 10), 0, 0x3, 1);
wlc_phy_force_rfseq_nphy(pi, NPHY_RFSEQ_RESET2RX);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_RFSEQ, 2, 0x110, 16,
gain_save);
wlc_phy_stay_in_carriersearch_nphy(pi, false);
return bcmerror;
}
int
wlc_phy_cal_rxiq_nphy(struct brcms_phy *pi, struct nphy_txgains target_gain,
u8 cal_type, bool debug)
{
if (NREV_GE(pi->pubpi.phy_rev, 7))
cal_type = 0;
if (NREV_GE(pi->pubpi.phy_rev, 3))
return wlc_phy_cal_rxiq_nphy_rev3(pi, target_gain, cal_type,
debug);
else
return wlc_phy_cal_rxiq_nphy_rev2(pi, target_gain, debug);
}
void wlc_phy_txpwr_fixpower_nphy(struct brcms_phy *pi)
{
uint core;
u32 txgain;
u16 rad_gain, dac_gain, bbmult, m1m2;
u8 txpi[2], chan_freq_range;
s32 rfpwr_offset;
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
if (pi->sh->sromrev < 4) {
txpi[0] = txpi[1] = 72;
} else {
chan_freq_range = wlc_phy_get_chan_freq_range_nphy(pi, 0);
switch (chan_freq_range) {
case WL_CHAN_FREQ_RANGE_2G:
case WL_CHAN_FREQ_RANGE_5GL:
case WL_CHAN_FREQ_RANGE_5GM:
case WL_CHAN_FREQ_RANGE_5GH:
txpi[0] = 0;
txpi[1] = 0;
break;
default:
txpi[0] = txpi[1] = 91;
break;
}
}
if (NREV_GE(pi->pubpi.phy_rev, 7))
txpi[0] = txpi[1] = 30;
else if (NREV_GE(pi->pubpi.phy_rev, 3))
txpi[0] = txpi[1] = 40;
if (NREV_LT(pi->pubpi.phy_rev, 7)) {
if ((txpi[0] < 40) || (txpi[0] > 100) ||
(txpi[1] < 40) || (txpi[1] > 100))
txpi[0] = txpi[1] = 91;
}
pi->nphy_txpwrindex[PHY_CORE_0].index_internal = txpi[0];
pi->nphy_txpwrindex[PHY_CORE_1].index_internal = txpi[1];
pi->nphy_txpwrindex[PHY_CORE_0].index_internal_save = txpi[0];
pi->nphy_txpwrindex[PHY_CORE_1].index_internal_save = txpi[1];
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
uint phyrev = pi->pubpi.phy_rev;
if (NREV_GE(phyrev, 3)) {
if (PHY_IPA(pi)) {
u32 *tx_gaintbl =
wlc_phy_get_ipa_gaintbl_nphy(pi);
txgain = tx_gaintbl[txpi[core]];
} else {
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_IS(phyrev, 3)) {
txgain =
nphy_tpc_5GHz_txgain_rev3
[txpi[core]];
} else if (NREV_IS(phyrev, 4)) {
txgain = (
pi->srom_fem5g.extpagain ==
3) ?
nphy_tpc_5GHz_txgain_HiPwrEPA
[txpi[core]] :
nphy_tpc_5GHz_txgain_rev4
[txpi[core]];
} else {
txgain =
nphy_tpc_5GHz_txgain_rev5
[txpi[core]];
}
} else {
if (NREV_GE(phyrev, 5) &&
(pi->srom_fem2g.extpagain == 3)) {
txgain =
nphy_tpc_txgain_HiPwrEPA
[txpi[core]];
} else {
txgain = nphy_tpc_txgain_rev3
[txpi[core]];
}
}
}
} else {
txgain = nphy_tpc_txgain[txpi[core]];
}
if (NREV_GE(phyrev, 3))
rad_gain = (txgain >> 16) & ((1 << (32 - 16 + 1)) - 1);
else
rad_gain = (txgain >> 16) & ((1 << (28 - 16 + 1)) - 1);
if (NREV_GE(phyrev, 7))
dac_gain = (txgain >> 8) & ((1 << (10 - 8 + 1)) - 1);
else
dac_gain = (txgain >> 8) & ((1 << (13 - 8 + 1)) - 1);
bbmult = (txgain >> 0) & ((1 << (7 - 0 + 1)) - 1);
if (NREV_GE(phyrev, 3))
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0x8f :
0xa5), (0x1 << 8), (0x1 << 8));
else
mod_phy_reg(pi, 0xa5, (0x1 << 14), (0x1 << 14));
write_phy_reg(pi, (core == PHY_CORE_0) ? 0xaa : 0xab, dac_gain);
wlc_phy_table_write_nphy(pi, 7, 1, (0x110 + core), 16,
&rad_gain);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &m1m2);
m1m2 &= ((core == PHY_CORE_0) ? 0x00ff : 0xff00);
m1m2 |= ((core == PHY_CORE_0) ? (bbmult << 8) : (bbmult << 0));
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &m1m2);
if (PHY_IPA(pi)) {
wlc_phy_table_read_nphy(pi,
(core ==
PHY_CORE_0 ?
NPHY_TBL_ID_CORE1TXPWRCTL :
NPHY_TBL_ID_CORE2TXPWRCTL), 1,
576 + txpi[core], 32,
&rfpwr_offset);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1ff << 4),
((s16) rfpwr_offset) << 4);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 2), (1) << 2);
}
}
and_phy_reg(pi, 0xbf, (u16) (~(0x1f << 0)));
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
static void
wlc_phy_txpwr_nphy_srom_convert(u8 *srom_max, u16 *pwr_offset,
u8 tmp_max_pwr, u8 rate_start,
u8 rate_end)
{
u8 rate;
u8 word_num, nibble_num;
u8 tmp_nibble;
for (rate = rate_start; rate <= rate_end; rate++) {
word_num = (rate - rate_start) >> 2;
nibble_num = (rate - rate_start) & 0x3;
tmp_nibble = (pwr_offset[word_num] >> 4 * nibble_num) & 0xf;
srom_max[rate] = tmp_max_pwr - 2 * tmp_nibble;
}
}
static void
wlc_phy_txpwr_nphy_po_apply(u8 *srom_max, u8 pwr_offset,
u8 rate_start, u8 rate_end)
{
u8 rate;
for (rate = rate_start; rate <= rate_end; rate++)
srom_max[rate] -= 2 * pwr_offset;
}
void
wlc_phy_ofdm_to_mcs_powers_nphy(u8 *power, u8 rate_mcs_start,
u8 rate_mcs_end, u8 rate_ofdm_start)
{
u8 rate1, rate2;
rate2 = rate_ofdm_start;
for (rate1 = rate_mcs_start; rate1 <= rate_mcs_end - 1; rate1++) {
power[rate1] = power[rate2];
rate2 += (rate1 == rate_mcs_start) ? 2 : 1;
}
power[rate_mcs_end] = power[rate_mcs_end - 1];
}
void
wlc_phy_mcs_to_ofdm_powers_nphy(u8 *power, u8 rate_ofdm_start,
u8 rate_ofdm_end, u8 rate_mcs_start)
{
u8 rate1, rate2;
for (rate1 = rate_ofdm_start, rate2 = rate_mcs_start;
rate1 <= rate_ofdm_end; rate1++, rate2++) {
power[rate1] = power[rate2];
if (rate1 == rate_ofdm_start)
power[++rate1] = power[rate2];
}
}
void wlc_phy_txpwr_apply_nphy(struct brcms_phy *pi)
{
uint rate1, rate2, band_num;
u8 tmp_bw40po = 0, tmp_cddpo = 0, tmp_stbcpo = 0;
u8 tmp_max_pwr = 0;
u16 pwr_offsets1[2], *pwr_offsets2 = NULL;
u8 *tx_srom_max_rate = NULL;
for (band_num = 0; band_num < (CH_2G_GROUP + CH_5G_GROUP);
band_num++) {
switch (band_num) {
case 0:
tmp_max_pwr = min(pi->nphy_pwrctrl_info[0].max_pwr_2g,
pi->nphy_pwrctrl_info[1].max_pwr_2g);
pwr_offsets1[0] = pi->cck2gpo;
wlc_phy_txpwr_nphy_srom_convert(pi->tx_srom_max_rate_2g,
pwr_offsets1,
tmp_max_pwr,
TXP_FIRST_CCK,
TXP_LAST_CCK);
pwr_offsets1[0] = (u16) (pi->ofdm2gpo & 0xffff);
pwr_offsets1[1] =
(u16) (pi->ofdm2gpo >> 16) & 0xffff;
pwr_offsets2 = pi->mcs2gpo;
tmp_cddpo = pi->cdd2gpo;
tmp_stbcpo = pi->stbc2gpo;
tmp_bw40po = pi->bw402gpo;
tx_srom_max_rate = pi->tx_srom_max_rate_2g;
break;
case 1:
tmp_max_pwr = min(pi->nphy_pwrctrl_info[0].max_pwr_5gm,
pi->nphy_pwrctrl_info[1].max_pwr_5gm);
pwr_offsets1[0] = (u16) (pi->ofdm5gpo & 0xffff);
pwr_offsets1[1] =
(u16) (pi->ofdm5gpo >> 16) & 0xffff;
pwr_offsets2 = pi->mcs5gpo;
tmp_cddpo = pi->cdd5gpo;
tmp_stbcpo = pi->stbc5gpo;
tmp_bw40po = pi->bw405gpo;
tx_srom_max_rate = pi->tx_srom_max_rate_5g_mid;
break;
case 2:
tmp_max_pwr = min(pi->nphy_pwrctrl_info[0].max_pwr_5gl,
pi->nphy_pwrctrl_info[1].max_pwr_5gl);
pwr_offsets1[0] = (u16) (pi->ofdm5glpo & 0xffff);
pwr_offsets1[1] =
(u16) (pi->ofdm5glpo >> 16) & 0xffff;
pwr_offsets2 = pi->mcs5glpo;
tmp_cddpo = pi->cdd5glpo;
tmp_stbcpo = pi->stbc5glpo;
tmp_bw40po = pi->bw405glpo;
tx_srom_max_rate = pi->tx_srom_max_rate_5g_low;
break;
case 3:
tmp_max_pwr = min(pi->nphy_pwrctrl_info[0].max_pwr_5gh,
pi->nphy_pwrctrl_info[1].max_pwr_5gh);
pwr_offsets1[0] = (u16) (pi->ofdm5ghpo & 0xffff);
pwr_offsets1[1] =
(u16) (pi->ofdm5ghpo >> 16) & 0xffff;
pwr_offsets2 = pi->mcs5ghpo;
tmp_cddpo = pi->cdd5ghpo;
tmp_stbcpo = pi->stbc5ghpo;
tmp_bw40po = pi->bw405ghpo;
tx_srom_max_rate = pi->tx_srom_max_rate_5g_hi;
break;
}
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate, pwr_offsets1,
tmp_max_pwr, TXP_FIRST_OFDM,
TXP_LAST_OFDM);
wlc_phy_ofdm_to_mcs_powers_nphy(tx_srom_max_rate,
TXP_FIRST_MCS_20_SISO,
TXP_LAST_MCS_20_SISO,
TXP_FIRST_OFDM);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate, pwr_offsets2,
tmp_max_pwr,
TXP_FIRST_MCS_20_CDD,
TXP_LAST_MCS_20_CDD);
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_txpwr_nphy_po_apply(tx_srom_max_rate, tmp_cddpo,
TXP_FIRST_MCS_20_CDD,
TXP_LAST_MCS_20_CDD);
wlc_phy_mcs_to_ofdm_powers_nphy(tx_srom_max_rate,
TXP_FIRST_OFDM_20_CDD,
TXP_LAST_OFDM_20_CDD,
TXP_FIRST_MCS_20_CDD);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate, pwr_offsets2,
tmp_max_pwr,
TXP_FIRST_MCS_20_STBC,
TXP_LAST_MCS_20_STBC);
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_txpwr_nphy_po_apply(tx_srom_max_rate,
tmp_stbcpo,
TXP_FIRST_MCS_20_STBC,
TXP_LAST_MCS_20_STBC);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate,
&pwr_offsets2[2], tmp_max_pwr,
TXP_FIRST_MCS_20_SDM,
TXP_LAST_MCS_20_SDM);
if (NPHY_IS_SROM_REINTERPRET) {
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate,
&pwr_offsets2[4],
tmp_max_pwr,
TXP_FIRST_MCS_40_SISO,
TXP_LAST_MCS_40_SISO);
wlc_phy_mcs_to_ofdm_powers_nphy(tx_srom_max_rate,
TXP_FIRST_OFDM_40_SISO,
TXP_LAST_OFDM_40_SISO,
TXP_FIRST_MCS_40_SISO);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate,
&pwr_offsets2[4],
tmp_max_pwr,
TXP_FIRST_MCS_40_CDD,
TXP_LAST_MCS_40_CDD);
wlc_phy_txpwr_nphy_po_apply(tx_srom_max_rate, tmp_cddpo,
TXP_FIRST_MCS_40_CDD,
TXP_LAST_MCS_40_CDD);
wlc_phy_mcs_to_ofdm_powers_nphy(tx_srom_max_rate,
TXP_FIRST_OFDM_40_CDD,
TXP_LAST_OFDM_40_CDD,
TXP_FIRST_MCS_40_CDD);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate,
&pwr_offsets2[4],
tmp_max_pwr,
TXP_FIRST_MCS_40_STBC,
TXP_LAST_MCS_40_STBC);
wlc_phy_txpwr_nphy_po_apply(tx_srom_max_rate,
tmp_stbcpo,
TXP_FIRST_MCS_40_STBC,
TXP_LAST_MCS_40_STBC);
wlc_phy_txpwr_nphy_srom_convert(tx_srom_max_rate,
&pwr_offsets2[6],
tmp_max_pwr,
TXP_FIRST_MCS_40_SDM,
TXP_LAST_MCS_40_SDM);
} else {
for (rate1 = TXP_FIRST_OFDM_40_SISO, rate2 =
TXP_FIRST_OFDM;
rate1 <= TXP_LAST_MCS_40_SDM;
rate1++, rate2++)
tx_srom_max_rate[rate1] =
tx_srom_max_rate[rate2];
}
if (NREV_GE(pi->pubpi.phy_rev, 3))
wlc_phy_txpwr_nphy_po_apply(tx_srom_max_rate,
tmp_bw40po,
TXP_FIRST_OFDM_40_SISO,
TXP_LAST_MCS_40_SDM);
tx_srom_max_rate[TXP_MCS_32] =
tx_srom_max_rate[TXP_FIRST_MCS_40_CDD];
}
return;
}
void wlc_phy_txpower_recalc_target_nphy(struct brcms_phy *pi)
{
u8 tx_pwr_ctrl_state;
wlc_phy_txpwr_limit_to_tbl_nphy(pi);
wlc_phy_txpwrctrl_pwr_setup_nphy(pi);
tx_pwr_ctrl_state = pi->nphy_txpwrctrl;
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12)) {
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, MCTL_PHYLOCK);
(void)bcma_read32(pi->d11core, D11REGOFFS(maccontrol));
udelay(1);
}
wlc_phy_txpwrctrl_enable_nphy(pi, tx_pwr_ctrl_state);
if (D11REV_IS(pi->sh->corerev, 11) || D11REV_IS(pi->sh->corerev, 12))
wlapi_bmac_mctrl(pi->sh->physhim, MCTL_PHYLOCK, 0);
}
static bool wlc_phy_txpwr_ison_nphy(struct brcms_phy *pi)
{
return read_phy_reg((pi), 0x1e7) & ((0x1 << 15) |
(0x1 << 14) | (0x1 << 13));
}
u16 wlc_phy_txpwr_idx_get_nphy(struct brcms_phy *pi)
{
u16 tmp;
u16 pwr_idx[2];
if (wlc_phy_txpwr_ison_nphy(pi)) {
pwr_idx[0] = wlc_phy_txpwr_idx_cur_get_nphy(pi, PHY_CORE_0);
pwr_idx[1] = wlc_phy_txpwr_idx_cur_get_nphy(pi, PHY_CORE_1);
tmp = (pwr_idx[0] << 8) | pwr_idx[1];
} else {
tmp = ((pi->nphy_txpwrindex[PHY_CORE_0].index_internal & 0xff)
<< 8) |
(pi->nphy_txpwrindex[PHY_CORE_1].index_internal & 0xff);
}
return tmp;
}
void wlc_phy_txpwr_papd_cal_nphy(struct brcms_phy *pi)
{
if (PHY_IPA(pi)
&& (pi->nphy_force_papd_cal
|| (wlc_phy_txpwr_ison_nphy(pi)
&&
(((u32)
abs(wlc_phy_txpwr_idx_cur_get_nphy(pi, 0) -
pi->nphy_papd_tx_gain_at_last_cal[0]) >= 4)
|| ((u32)
abs(wlc_phy_txpwr_idx_cur_get_nphy(pi, 1) -
pi->nphy_papd_tx_gain_at_last_cal[1]) >= 4)))))
wlc_phy_a4(pi, true);
}
void wlc_phy_txpwrctrl_enable_nphy(struct brcms_phy *pi, u8 ctrl_type)
{
u16 mask = 0, val = 0, ishw = 0;
u8 ctr;
uint core;
u32 tbl_offset;
u32 tbl_len;
u16 regval[84];
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
switch (ctrl_type) {
case PHY_TPC_HW_OFF:
case PHY_TPC_HW_ON:
pi->nphy_txpwrctrl = ctrl_type;
break;
default:
break;
}
if (ctrl_type == PHY_TPC_HW_OFF) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if (wlc_phy_txpwr_ison_nphy(pi)) {
for (core = 0; core < pi->pubpi.phy_corenum;
core++)
pi->nphy_txpwr_idx[core] =
wlc_phy_txpwr_idx_cur_get_nphy(
pi,
(u8) core);
}
}
tbl_len = 84;
tbl_offset = 64;
for (ctr = 0; ctr < tbl_len; ctr++)
regval[ctr] = 0;
wlc_phy_table_write_nphy(pi, 26, tbl_len, tbl_offset, 16,
regval);
wlc_phy_table_write_nphy(pi, 27, tbl_len, tbl_offset, 16,
regval);
if (NREV_GE(pi->pubpi.phy_rev, 3))
and_phy_reg(pi, 0x1e7,
(u16) (~((0x1 << 15) |
(0x1 << 14) | (0x1 << 13))));
else
and_phy_reg(pi, 0x1e7,
(u16) (~((0x1 << 14) | (0x1 << 13))));
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
or_phy_reg(pi, 0x8f, (0x1 << 8));
or_phy_reg(pi, 0xa5, (0x1 << 8));
} else {
or_phy_reg(pi, 0xa5, (0x1 << 14));
}
if (NREV_IS(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x53);
else if (NREV_LT(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x5a);
if (NREV_LT(pi->pubpi.phy_rev, 2) &&
pi->bw == WL_CHANSPEC_BW_40)
wlapi_bmac_mhf(pi->sh->physhim, MHF1, MHF1_IQSWAP_WAR,
MHF1_IQSWAP_WAR, BRCM_BAND_ALL);
} else {
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE1TXPWRCTL, 84, 64,
8, pi->adj_pwr_tbl_nphy);
wlc_phy_table_write_nphy(pi, NPHY_TBL_ID_CORE2TXPWRCTL, 84, 64,
8, pi->adj_pwr_tbl_nphy);
ishw = (ctrl_type == PHY_TPC_HW_ON) ? 0x1 : 0x0;
mask = (0x1 << 14) | (0x1 << 13);
val = (ishw << 14) | (ishw << 13);
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
mask |= (0x1 << 15);
val |= (ishw << 15);
}
mod_phy_reg(pi, 0x1e7, mask, val);
if (CHSPEC_IS5G(pi->radio_chanspec)) {
if (NREV_GE(pi->pubpi.phy_rev, 7)) {
mod_phy_reg(pi, 0x1e7, (0x7f << 0), 0x32);
mod_phy_reg(pi, 0x222, (0xff << 0), 0x32);
} else {
mod_phy_reg(pi, 0x1e7, (0x7f << 0), 0x64);
if (NREV_GT(pi->pubpi.phy_rev, 1))
mod_phy_reg(pi, 0x222,
(0xff << 0), 0x64);
}
}
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
if ((pi->nphy_txpwr_idx[0] != 128)
&& (pi->nphy_txpwr_idx[1] != 128))
wlc_phy_txpwr_idx_cur_set_nphy(pi,
pi->
nphy_txpwr_idx
[0],
pi->
nphy_txpwr_idx
[1]);
}
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
and_phy_reg(pi, 0x8f, ~(0x1 << 8));
and_phy_reg(pi, 0xa5, ~(0x1 << 8));
} else {
and_phy_reg(pi, 0xa5, ~(0x1 << 14));
}
if (NREV_IS(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x3b);
else if (NREV_LT(pi->pubpi.phy_rev, 2))
mod_phy_reg(pi, 0xdc, 0x00ff, 0x40);
if (NREV_LT(pi->pubpi.phy_rev, 2) &&
pi->bw == WL_CHANSPEC_BW_40)
wlapi_bmac_mhf(pi->sh->physhim, MHF1, MHF1_IQSWAP_WAR,
0x0, BRCM_BAND_ALL);
if (PHY_IPA(pi)) {
mod_phy_reg(pi, (0 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 2), (0) << 2);
mod_phy_reg(pi, (1 == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 2), (0) << 2);
}
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
void
wlc_phy_txpwr_index_nphy(struct brcms_phy *pi, u8 core_mask, s8 txpwrindex,
bool restore_cals)
{
u8 core, txpwrctl_tbl;
u16 tx_ind0, iq_ind0, lo_ind0;
u16 m1m2;
u32 txgain;
u16 rad_gain, dac_gain;
u8 bbmult;
u32 iqcomp;
u16 iqcomp_a, iqcomp_b;
u32 locomp;
u16 tmpval;
u8 tx_pwr_ctrl_state;
s32 rfpwr_offset;
u16 regval[2];
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
tx_ind0 = 192;
iq_ind0 = 320;
lo_ind0 = 448;
for (core = 0; core < pi->pubpi.phy_corenum; core++) {
if ((core_mask & (1 << core)) == 0)
continue;
txpwrctl_tbl = (core == PHY_CORE_0) ? 26 : 27;
if (txpwrindex < 0) {
if (pi->nphy_txpwrindex[core].index < 0)
continue;
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
mod_phy_reg(pi, 0x8f,
(0x1 << 8),
pi->nphy_txpwrindex[core].
AfectrlOverride);
mod_phy_reg(pi, 0xa5, (0x1 << 8),
pi->nphy_txpwrindex[core].
AfectrlOverride);
} else {
mod_phy_reg(pi, 0xa5,
(0x1 << 14),
pi->nphy_txpwrindex[core].
AfectrlOverride);
}
write_phy_reg(pi, (core == PHY_CORE_0) ?
0xaa : 0xab,
pi->nphy_txpwrindex[core].AfeCtrlDacGain);
wlc_phy_table_write_nphy(pi, 7, 1, (0x110 + core), 16,
&pi->nphy_txpwrindex[core].
rad_gain);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &m1m2);
m1m2 &= ((core == PHY_CORE_0) ? 0x00ff : 0xff00);
m1m2 |= ((core == PHY_CORE_0) ?
(pi->nphy_txpwrindex[core].bbmult << 8) :
(pi->nphy_txpwrindex[core].bbmult << 0));
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &m1m2);
if (restore_cals) {
wlc_phy_table_write_nphy(
pi, 15, 2, (80 + 2 * core), 16,
&pi->nphy_txpwrindex[core].iqcomp_a);
wlc_phy_table_write_nphy(
pi, 15, 1, (85 + core), 16,
&pi->nphy_txpwrindex[core].locomp);
wlc_phy_table_write_nphy(
pi, 15, 1, (93 + core), 16,
&pi->nphy_txpwrindex[core].locomp);
}
wlc_phy_txpwrctrl_enable_nphy(pi, pi->nphy_txpwrctrl);
pi->nphy_txpwrindex[core].index_internal =
pi->nphy_txpwrindex[core].index_internal_save;
} else {
if (pi->nphy_txpwrindex[core].index < 0) {
if (NREV_GE(pi->pubpi.phy_rev, 3)) {
mod_phy_reg(pi, 0x8f,
(0x1 << 8),
pi->nphy_txpwrindex[core].
AfectrlOverride);
mod_phy_reg(pi, 0xa5, (0x1 << 8),
pi->nphy_txpwrindex[core].
AfectrlOverride);
} else {
pi->nphy_txpwrindex[core].
AfectrlOverride =
read_phy_reg(pi, 0xa5);
}
pi->nphy_txpwrindex[core].AfeCtrlDacGain =
read_phy_reg(pi, (core == PHY_CORE_0) ?
0xaa : 0xab);
wlc_phy_table_read_nphy(pi, 7, 1,
(0x110 + core), 16,
&pi->
nphy_txpwrindex[core].
rad_gain);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16,
&tmpval);
tmpval >>= ((core == PHY_CORE_0) ? 8 : 0);
tmpval &= 0xff;
pi->nphy_txpwrindex[core].bbmult = (u8) tmpval;
wlc_phy_table_read_nphy(pi, 15, 2,
(80 + 2 * core), 16,
&pi->
nphy_txpwrindex[core].
iqcomp_a);
wlc_phy_table_read_nphy(pi, 15, 1, (85 + core),
16,
&pi->
nphy_txpwrindex[core].
locomp);
pi->nphy_txpwrindex[core].index_internal_save =
pi->nphy_txpwrindex[core].
index_internal;
}
tx_pwr_ctrl_state = pi->nphy_txpwrctrl;
wlc_phy_txpwrctrl_enable_nphy(pi, PHY_TPC_HW_OFF);
if (NREV_IS(pi->pubpi.phy_rev, 1))
wlapi_bmac_phyclk_fgc(pi->sh->physhim, ON);
wlc_phy_table_read_nphy(pi, txpwrctl_tbl, 1,
(tx_ind0 + txpwrindex), 32,
&txgain);
if (NREV_GE(pi->pubpi.phy_rev, 3))
rad_gain = (txgain >> 16) &
((1 << (32 - 16 + 1)) - 1);
else
rad_gain = (txgain >> 16) &
((1 << (28 - 16 + 1)) - 1);
dac_gain = (txgain >> 8) & ((1 << (13 - 8 + 1)) - 1);
bbmult = (txgain >> 0) & ((1 << (7 - 0 + 1)) - 1);
if (NREV_GE(pi->pubpi.phy_rev, 3))
mod_phy_reg(pi, ((core == PHY_CORE_0) ? 0x8f :
0xa5), (0x1 << 8), (0x1 << 8));
else
mod_phy_reg(pi, 0xa5, (0x1 << 14), (0x1 << 14));
write_phy_reg(pi, (core == PHY_CORE_0) ?
0xaa : 0xab, dac_gain);
wlc_phy_table_write_nphy(pi, 7, 1, (0x110 + core), 16,
&rad_gain);
wlc_phy_table_read_nphy(pi, 15, 1, 87, 16, &m1m2);
m1m2 &= ((core == PHY_CORE_0) ? 0x00ff : 0xff00);
m1m2 |= ((core == PHY_CORE_0) ?
(bbmult << 8) : (bbmult << 0));
wlc_phy_table_write_nphy(pi, 15, 1, 87, 16, &m1m2);
wlc_phy_table_read_nphy(pi, txpwrctl_tbl, 1,
(iq_ind0 + txpwrindex), 32,
&iqcomp);
iqcomp_a = (iqcomp >> 10) & ((1 << (19 - 10 + 1)) - 1);
iqcomp_b = (iqcomp >> 0) & ((1 << (9 - 0 + 1)) - 1);
if (restore_cals) {
regval[0] = (u16) iqcomp_a;
regval[1] = (u16) iqcomp_b;
wlc_phy_table_write_nphy(pi, 15, 2,
(80 + 2 * core), 16,
regval);
}
wlc_phy_table_read_nphy(pi, txpwrctl_tbl, 1,
(lo_ind0 + txpwrindex), 32,
&locomp);
if (restore_cals)
wlc_phy_table_write_nphy(pi, 15, 1, (85 + core),
16, &locomp);
if (NREV_IS(pi->pubpi.phy_rev, 1))
wlapi_bmac_phyclk_fgc(pi->sh->physhim, OFF);
if (PHY_IPA(pi)) {
wlc_phy_table_read_nphy(pi,
(core == PHY_CORE_0 ?
NPHY_TBL_ID_CORE1TXPWRCTL :
NPHY_TBL_ID_CORE2TXPWRCTL),
1, 576 + txpwrindex, 32,
&rfpwr_offset);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1ff << 4),
((s16) rfpwr_offset) << 4);
mod_phy_reg(pi, (core == PHY_CORE_0) ? 0x297 :
0x29b, (0x1 << 2), (1) << 2);
}
wlc_phy_txpwrctrl_enable_nphy(pi, tx_pwr_ctrl_state);
}
pi->nphy_txpwrindex[core].index = txpwrindex;
}
if (pi->phyhang_avoid)
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
void
wlc_phy_txpower_sromlimit_get_nphy(struct brcms_phy *pi, uint chan, u8 *max_pwr,
u8 txp_rate_idx)
{
u8 chan_freq_range;
chan_freq_range = wlc_phy_get_chan_freq_range_nphy(pi, chan);
switch (chan_freq_range) {
case WL_CHAN_FREQ_RANGE_2G:
*max_pwr = pi->tx_srom_max_rate_2g[txp_rate_idx];
break;
case WL_CHAN_FREQ_RANGE_5GM:
*max_pwr = pi->tx_srom_max_rate_5g_mid[txp_rate_idx];
break;
case WL_CHAN_FREQ_RANGE_5GL:
*max_pwr = pi->tx_srom_max_rate_5g_low[txp_rate_idx];
break;
case WL_CHAN_FREQ_RANGE_5GH:
*max_pwr = pi->tx_srom_max_rate_5g_hi[txp_rate_idx];
break;
default:
*max_pwr = pi->tx_srom_max_rate_2g[txp_rate_idx];
break;
}
return;
}
void wlc_phy_stay_in_carriersearch_nphy(struct brcms_phy *pi, bool enable)
{
u16 clip_off[] = { 0xffff, 0xffff };
if (enable) {
if (pi->nphy_deaf_count == 0) {
pi->classifier_state =
wlc_phy_classifier_nphy(pi, 0, 0);
wlc_phy_classifier_nphy(pi, (0x7 << 0), 4);
wlc_phy_clip_det_nphy(pi, 0, pi->clip_state);
wlc_phy_clip_det_nphy(pi, 1, clip_off);
}
pi->nphy_deaf_count++;
wlc_phy_resetcca_nphy(pi);
} else {
pi->nphy_deaf_count--;
if (pi->nphy_deaf_count == 0) {
wlc_phy_classifier_nphy(pi, (0x7 << 0),
pi->classifier_state);
wlc_phy_clip_det_nphy(pi, 1, pi->clip_state);
}
}
}
void wlc_nphy_deaf_mode(struct brcms_phy *pi, bool mode)
{
wlapi_suspend_mac_and_wait(pi->sh->physhim);
if (mode) {
if (pi->nphy_deaf_count == 0)
wlc_phy_stay_in_carriersearch_nphy(pi, true);
} else if (pi->nphy_deaf_count > 0) {
wlc_phy_stay_in_carriersearch_nphy(pi, false);
}
wlapi_enable_mac(pi->sh->physhim);
}
