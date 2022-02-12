static void odm_set_crystal_cap(void *dm_void, u8 crystal_cap)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
if (cfo_track->crystal_cap == crystal_cap)
return;
cfo_track->crystal_cap = crystal_cap;
if (dm->support_ic_type & (ODM_RTL8188E | ODM_RTL8188F)) {
crystal_cap = crystal_cap & 0x3F;
odm_set_bb_reg(dm, REG_AFE_XTAL_CTRL, 0x007ff800,
(crystal_cap | (crystal_cap << 6)));
} else if (dm->support_ic_type & ODM_RTL8812) {
crystal_cap = crystal_cap & 0x3F;
odm_set_bb_reg(dm, REG_MAC_PHY_CTRL, 0x7FF80000,
(crystal_cap | (crystal_cap << 6)));
} else if ((dm->support_ic_type & (ODM_RTL8703B | ODM_RTL8723B |
ODM_RTL8192E | ODM_RTL8821))) {
crystal_cap = crystal_cap & 0x3F;
odm_set_bb_reg(dm, REG_MAC_PHY_CTRL, 0x00FFF000,
(crystal_cap | (crystal_cap << 6)));
} else if (dm->support_ic_type & ODM_RTL8814A) {
crystal_cap = crystal_cap & 0x3F;
odm_set_bb_reg(dm, REG_MAC_PHY_CTRL, 0x07FF8000,
(crystal_cap | (crystal_cap << 6)));
} else if (dm->support_ic_type & (ODM_RTL8822B | ODM_RTL8821C)) {
crystal_cap = crystal_cap & 0x3F;
odm_set_bb_reg(dm, REG_AFE_XTAL_CTRL, 0x7e000000, crystal_cap);
odm_set_bb_reg(dm, REG_AFE_PLL_CTRL, 0x7e, crystal_cap);
} else {
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): Use default setting.\n", __func__);
odm_set_bb_reg(dm, REG_MAC_PHY_CTRL, 0xFFF000,
(crystal_cap | (crystal_cap << 6)));
}
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING, "%s(): crystal_cap = 0x%x\n",
__func__, crystal_cap);
}
static u8 odm_get_default_crytaltal_cap(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
u8 crystal_cap = 0x20;
struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;
struct rtl_efuse *rtlefuse = rtl_efuse(rtlpriv);
crystal_cap = rtlefuse->crystalcap;
crystal_cap = crystal_cap & 0x3f;
return crystal_cap;
}
static void odm_set_atc_status(void *dm_void, bool atc_status)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
if (cfo_track->is_atc_status == atc_status)
return;
odm_set_bb_reg(dm, ODM_REG(BB_ATC, dm), ODM_BIT(BB_ATC, dm),
atc_status);
cfo_track->is_atc_status = atc_status;
}
static bool odm_get_atc_status(void *dm_void)
{
bool atc_status;
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
atc_status = (bool)odm_get_bb_reg(dm, ODM_REG(BB_ATC, dm),
ODM_BIT(BB_ATC, dm));
return atc_status;
}
void odm_cfo_tracking_reset(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
cfo_track->def_x_cap = odm_get_default_crytaltal_cap(dm);
cfo_track->is_adjust = true;
if (cfo_track->crystal_cap > cfo_track->def_x_cap) {
odm_set_crystal_cap(dm, cfo_track->crystal_cap - 1);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): approch default value (0x%x)\n", __func__,
cfo_track->crystal_cap);
} else if (cfo_track->crystal_cap < cfo_track->def_x_cap) {
odm_set_crystal_cap(dm, cfo_track->crystal_cap + 1);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): approch default value (0x%x)\n", __func__,
cfo_track->crystal_cap);
}
odm_set_atc_status(dm, true);
}
void odm_cfo_tracking_init(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
cfo_track->crystal_cap = odm_get_default_crytaltal_cap(dm);
cfo_track->def_x_cap = cfo_track->crystal_cap;
cfo_track->is_atc_status = odm_get_atc_status(dm);
cfo_track->is_adjust = true;
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING, "%s()=========>\n", __func__);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): is_atc_status = %d, crystal_cap = 0x%x\n", __func__,
cfo_track->is_atc_status, cfo_track->def_x_cap);
if (dm->support_ic_type & ODM_RTL8822B)
odm_set_bb_reg(dm, 0x10, 0x40, 0x1);
}
void odm_cfo_tracking(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
s32 cfo_ave = 0;
u32 cfo_rpt_sum, cfo_khz_avg[4] = {0};
s32 cfo_ave_diff;
s8 crystal_cap = cfo_track->crystal_cap;
u8 adjust_xtal = 1, i, valid_path_cnt = 0;
if (!(dm->support_ability & ODM_BB_CFO_TRACKING)) {
ODM_RT_TRACE(
dm, ODM_COMP_CFO_TRACKING,
"%s(): Return: support_ability ODM_BB_CFO_TRACKING is disabled\n",
__func__);
return;
}
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING, "%s()=========>\n", __func__);
if (!dm->is_linked || !dm->is_one_entry_only) {
odm_cfo_tracking_reset(dm);
ODM_RT_TRACE(
dm, ODM_COMP_CFO_TRACKING,
"%s(): Reset: is_linked = %d, is_one_entry_only = %d\n",
__func__, dm->is_linked, dm->is_one_entry_only);
} else {
if (cfo_track->packet_count == cfo_track->packet_count_pre) {
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): packet counter doesn't change\n",
__func__);
return;
}
cfo_track->packet_count_pre = cfo_track->packet_count;
for (i = 0; i < dm->num_rf_path; i++) {
if (cfo_track->CFO_cnt[i] == 0)
continue;
valid_path_cnt++;
cfo_rpt_sum =
(u32)((cfo_track->CFO_tail[i] < 0) ?
(0 - cfo_track->CFO_tail[i]) :
cfo_track->CFO_tail[i]);
cfo_khz_avg[i] = CFO_HW_RPT_2_MHZ(cfo_rpt_sum) /
cfo_track->CFO_cnt[i];
ODM_RT_TRACE(
dm, ODM_COMP_CFO_TRACKING,
"[path %d] cfo_rpt_sum = (( %d )), CFO_cnt = (( %d )) , CFO_avg= (( %s%d )) kHz\n",
i, cfo_rpt_sum, cfo_track->CFO_cnt[i],
((cfo_track->CFO_tail[i] < 0) ? "-" : " "),
cfo_khz_avg[i]);
}
for (i = 0; i < valid_path_cnt; i++) {
if (cfo_track->CFO_tail[i] < 0) {
cfo_ave += (0 - (s32)cfo_khz_avg[i]);
} else {
cfo_ave += (s32)cfo_khz_avg[i];
}
}
if (valid_path_cnt >= 2)
cfo_ave = cfo_ave / valid_path_cnt;
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"valid_path_cnt = ((%d)), cfo_ave = ((%d kHz))\n",
valid_path_cnt, cfo_ave);
for (i = 0; i < dm->num_rf_path; i++) {
cfo_track->CFO_tail[i] = 0;
cfo_track->CFO_cnt[i] = 0;
}
cfo_ave_diff = (cfo_track->CFO_ave_pre >= cfo_ave) ?
(cfo_track->CFO_ave_pre - cfo_ave) :
(cfo_ave - cfo_track->CFO_ave_pre);
if (cfo_ave_diff > 20 && cfo_track->large_cfo_hit == 0 &&
!cfo_track->is_adjust) {
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): first large CFO hit\n", __func__);
cfo_track->large_cfo_hit = 1;
return;
}
cfo_track->large_cfo_hit = 0;
cfo_track->CFO_ave_pre = cfo_ave;
if (!cfo_track->is_adjust) {
if (cfo_ave > CFO_TH_XTAL_HIGH ||
cfo_ave < (-CFO_TH_XTAL_HIGH))
cfo_track->is_adjust = true;
} else {
if (cfo_ave < CFO_TH_XTAL_LOW &&
cfo_ave > (-CFO_TH_XTAL_LOW))
cfo_track->is_adjust = false;
}
if (dm->is_bt_enabled) {
cfo_track->is_adjust = false;
odm_set_crystal_cap(dm, cfo_track->def_x_cap);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): Disable CFO tracking for BT!!\n",
__func__);
}
if (cfo_track->is_adjust) {
if (cfo_ave > CFO_TH_XTAL_LOW)
crystal_cap = crystal_cap + adjust_xtal;
else if (cfo_ave < (-CFO_TH_XTAL_LOW))
crystal_cap = crystal_cap - adjust_xtal;
if (crystal_cap > 0x3f)
crystal_cap = 0x3f;
else if (crystal_cap < 0)
crystal_cap = 0;
odm_set_crystal_cap(dm, (u8)crystal_cap);
}
ODM_RT_TRACE(
dm, ODM_COMP_CFO_TRACKING,
"%s(): Crystal cap = 0x%x, Default Crystal cap = 0x%x\n",
__func__, cfo_track->crystal_cap, cfo_track->def_x_cap);
if (dm->support_ic_type & ODM_IC_11AC_SERIES)
return;
if (cfo_ave < CFO_TH_ATC && cfo_ave > -CFO_TH_ATC) {
odm_set_atc_status(dm, false);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): Disable ATC!!\n", __func__);
} else {
odm_set_atc_status(dm, true);
ODM_RT_TRACE(dm, ODM_COMP_CFO_TRACKING,
"%s(): Enable ATC!!\n", __func__);
}
}
}
void odm_parsing_cfo(void *dm_void, void *pktinfo_void, s8 *pcfotail, u8 num_ss)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
struct dm_per_pkt_info *pktinfo =
(struct dm_per_pkt_info *)pktinfo_void;
struct cfo_tracking *cfo_track =
(struct cfo_tracking *)phydm_get_structure(dm, PHYDM_CFOTRACK);
u8 i;
if (!(dm->support_ability & ODM_BB_CFO_TRACKING))
return;
if (pktinfo->is_packet_match_bssid) {
if (num_ss > dm->num_rf_path)
num_ss = dm->num_rf_path;
for (i = 0; i < num_ss; i++) {
cfo_track->CFO_tail[i] += pcfotail[i];
cfo_track->CFO_cnt[i]++;
}
if (cfo_track->packet_count == 0xffffffff)
cfo_track->packet_count = 0;
else
cfo_track->packet_count++;
}
}
