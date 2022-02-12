static bool check_positive(struct phy_dm_struct *dm, const u32 condition1,
const u32 condition2, const u32 condition3,
const u32 condition4)
{
u8 _board_type = ((dm->board_type & BIT(4)) >> 4) << 0 |
((dm->board_type & BIT(3)) >> 3) << 1 |
((dm->board_type & BIT(7)) >> 7) << 2 |
((dm->board_type & BIT(6)) >> 6) << 3 |
((dm->board_type & BIT(2)) >> 2) << 4;
u32 cond1 = condition1, cond2 = condition2, cond3 = condition3,
cond4 = condition4;
u8 cut_version_for_para =
(dm->cut_version == ODM_CUT_A) ? 14 : dm->cut_version;
u8 pkg_type_for_para = (dm->package_type == 0) ? 14 : dm->package_type;
u32 driver1 = cut_version_for_para << 24 |
(dm->support_interface & 0xF0) << 16 |
dm->support_platform << 16 | pkg_type_for_para << 12 |
(dm->support_interface & 0x0F) << 8 | _board_type;
u32 driver2 = (dm->type_glna & 0xFF) << 0 | (dm->type_gpa & 0xFF) << 8 |
(dm->type_alna & 0xFF) << 16 |
(dm->type_apa & 0xFF) << 24;
u32 driver3 = 0;
u32 driver4 = (dm->type_glna & 0xFF00) >> 8 | (dm->type_gpa & 0xFF00) |
(dm->type_alna & 0xFF00) << 8 |
(dm->type_apa & 0xFF00) << 16;
ODM_RT_TRACE(
dm, ODM_COMP_INIT,
"===> %s (cond1, cond2, cond3, cond4) = (0x%X 0x%X 0x%X 0x%X)\n",
__func__, cond1, cond2, cond3, cond4);
ODM_RT_TRACE(
dm, ODM_COMP_INIT,
"===> %s (driver1, driver2, driver3, driver4) = (0x%X 0x%X 0x%X 0x%X)\n",
__func__, driver1, driver2, driver3, driver4);
ODM_RT_TRACE(dm, ODM_COMP_INIT,
" (Platform, Interface) = (0x%X, 0x%X)\n",
dm->support_platform, dm->support_interface);
ODM_RT_TRACE(dm, ODM_COMP_INIT,
" (Board, Package) = (0x%X, 0x%X)\n",
dm->board_type, dm->package_type);
if (((cond1 & 0x0000F000) != 0) &&
((cond1 & 0x0000F000) != (driver1 & 0x0000F000)))
return false;
if (((cond1 & 0x0F000000) != 0) &&
((cond1 & 0x0F000000) != (driver1 & 0x0F000000)))
return false;
cond1 &= 0x00FF0FFF;
driver1 &= 0x00FF0FFF;
if ((cond1 & driver1) == cond1) {
u32 bit_mask = 0;
if ((cond1 & 0x0F) == 0)
return true;
if ((cond1 & BIT(0)) != 0)
bit_mask |= 0x000000FF;
if ((cond1 & BIT(1)) != 0)
bit_mask |= 0x0000FF00;
if ((cond1 & BIT(2)) != 0)
bit_mask |= 0x00FF0000;
if ((cond1 & BIT(3)) != 0)
bit_mask |= 0xFF000000;
if (((cond2 & bit_mask) == (driver2 & bit_mask)) &&
((cond4 & bit_mask) ==
(driver4 &
bit_mask)))
return true;
else
return false;
} else {
return false;
}
}
void odm_read_and_config_mp_8822b_radioa(struct phy_dm_struct *dm)
{
u32 i = 0;
u8 c_cond;
bool is_matched = true, is_skipped = false;
u32 array_len = sizeof(array_mp_8822b_radioa) / sizeof(u32);
u32 *array = array_mp_8822b_radioa;
u32 v1 = 0, v2 = 0, pre_v1 = 0, pre_v2 = 0;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"===> %s\n", __func__);
for (; (i + 1) < array_len; i = i + 2) {
v1 = array[i];
v2 = array[i + 1];
if (v1 & BIT(31)) {
c_cond = (u8)((v1 & (BIT(29) | BIT(28))) >> 28);
if (c_cond == COND_ENDIF) {
is_matched = true;
is_skipped = false;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "ENDIF\n");
} else if (c_cond == COND_ELSE) {
is_matched = is_skipped ? false : true;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "ELSE\n");
} else {
pre_v1 = v1;
pre_v2 = v2;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"IF or ELSE IF\n");
}
} else if (v1 & BIT(30)) {
if (is_skipped) {
is_matched = false;
continue;
}
if (check_positive(dm, pre_v1, pre_v2, v1, v2)) {
is_matched = true;
is_skipped = true;
} else {
is_matched = false;
is_skipped = false;
}
} else if (is_matched) {
odm_config_rf_radio_a_8822b(dm, v1, v2);
}
}
}
u32 odm_get_version_mp_8822b_radioa(void) { return 67; }
void odm_read_and_config_mp_8822b_radiob(struct phy_dm_struct *dm)
{
u32 i = 0;
u8 c_cond;
bool is_matched = true, is_skipped = false;
u32 array_len = sizeof(array_mp_8822b_radiob) / sizeof(u32);
u32 *array = array_mp_8822b_radiob;
u32 v1 = 0, v2 = 0, pre_v1 = 0, pre_v2 = 0;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"===> %s\n", __func__);
for (; (i + 1) < array_len; i = i + 2) {
v1 = array[i];
v2 = array[i + 1];
if (v1 & BIT(31)) {
c_cond = (u8)((v1 & (BIT(29) | BIT(28))) >> 28);
if (c_cond == COND_ENDIF) {
is_matched = true;
is_skipped = false;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "ENDIF\n");
} else if (c_cond == COND_ELSE) {
is_matched = is_skipped ? false : true;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "ELSE\n");
} else {
pre_v1 = v1;
pre_v2 = v2;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"IF or ELSE IF\n");
}
} else if (v1 & BIT(30)) {
if (is_skipped) {
is_matched = false;
continue;
}
if (check_positive(dm, pre_v1, pre_v2, v1, v2)) {
is_matched = true;
is_skipped = true;
} else {
is_matched = false;
is_skipped = false;
}
} else if (is_matched) {
odm_config_rf_radio_b_8822b(dm, v1, v2);
}
}
}
u32 odm_get_version_mp_8822b_radiob(void) { return 67; }
void odm_read_and_config_mp_8822b_txpowertrack(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type0(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type0_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type1(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type1_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type2(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type2_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type3_type5(
struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(
dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(
dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(
dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(
dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type3_type5_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type4(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type4_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type6(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type6_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type7(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type7_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type8(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type8_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpowertrack_type9(struct phy_dm_struct *dm)
{
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
ODM_RT_TRACE(dm, ODM_COMP_INIT, "===> ODM_ReadAndConfig_MP_mp_8822b\n");
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_p,
delta_swing_index_mp_2ga_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2ga_n,
delta_swing_index_mp_2ga_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_p,
delta_swing_index_mp_2gb_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2gb_n,
delta_swing_index_mp_2gb_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_p,
delta_swing_index_mp_2g_cck_a_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_a_n,
delta_swing_index_mp_2g_cck_a_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_p,
delta_swing_index_mp_2g_cck_b_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_2g_cck_b_n,
delta_swing_index_mp_2g_cck_b_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_p,
delta_swing_index_mp_5ga_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5ga_n,
delta_swing_index_mp_5ga_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_p,
delta_swing_index_mp_5gb_p_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE * 3);
odm_move_memory(dm, cali_info->delta_swing_table_idx_5gb_n,
delta_swing_index_mp_5gb_n_txpwrtrack_type9_8822b,
DELTA_SWINGIDX_SIZE * 3);
}
void odm_read_and_config_mp_8822b_txpwr_lmt(struct phy_dm_struct *dm)
{
u32 i = 0;
u32 array_len = sizeof(array_mp_8822b_txpwr_lmt) / sizeof(u8 *);
u8 **array = (u8 **)array_mp_8822b_txpwr_lmt;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"===> %s\n", __func__);
for (i = 0; i < array_len; i += 7) {
u8 *regulation = array[i];
u8 *band = array[i + 1];
u8 *bandwidth = array[i + 2];
u8 *rate = array[i + 3];
u8 *rf_path = array[i + 4];
u8 *chnl = array[i + 5];
u8 *val = array[i + 6];
odm_config_bb_txpwr_lmt_8822b(dm, regulation, band, bandwidth,
rate, rf_path, chnl, val);
}
}
void odm_read_and_config_mp_8822b_txpwr_lmt_type5(struct phy_dm_struct *dm)
{
u32 i = 0;
u32 array_len = sizeof(array_mp_8822b_txpwr_lmt_type5) / sizeof(u8 *);
u8 **array = (u8 **)array_mp_8822b_txpwr_lmt_type5;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"===> odm_read_and_config_mp_8822b_txpwr_lmt_type5\n");
for (i = 0; i < array_len; i += 7) {
u8 *regulation = array[i];
u8 *band = array[i + 1];
u8 *bandwidth = array[i + 2];
u8 *rate = array[i + 3];
u8 *rf_path = array[i + 4];
u8 *chnl = array[i + 5];
u8 *val = array[i + 6];
odm_config_bb_txpwr_lmt_8822b(dm, regulation, band, bandwidth,
rate, rf_path, chnl, val);
}
}
