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
void odm_read_and_config_mp_8822b_agc_tab(struct phy_dm_struct *dm)
{
u32 i = 0;
u8 c_cond;
bool is_matched = true, is_skipped = false;
u32 array_len = sizeof(array_mp_8822b_agc_tab) / sizeof(u32);
u32 *array = array_mp_8822b_agc_tab;
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
odm_config_bb_agc_8822b(dm, v1, MASKDWORD, v2);
}
}
}
u32 odm_get_version_mp_8822b_agc_tab(void) { return 67; }
void odm_read_and_config_mp_8822b_phy_reg(struct phy_dm_struct *dm)
{
u32 i = 0;
u8 c_cond;
bool is_matched = true, is_skipped = false;
u32 array_len = sizeof(array_mp_8822b_phy_reg) / sizeof(u32);
u32 *array = array_mp_8822b_phy_reg;
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
odm_config_bb_phy_8822b(dm, v1, MASKDWORD, v2);
}
}
}
u32 odm_get_version_mp_8822b_phy_reg(void) { return 67; }
void odm_read_and_config_mp_8822b_phy_reg_pg(struct phy_dm_struct *dm)
{
u32 i = 0;
u32 array_len = sizeof(array_mp_8822b_phy_reg_pg) / sizeof(u32);
u32 *array = array_mp_8822b_phy_reg_pg;
ODM_RT_TRACE(dm, ODM_COMP_INIT,
"===> %s\n", __func__);
dm->phy_reg_pg_version = 1;
dm->phy_reg_pg_value_type = PHY_REG_PG_EXACT_VALUE;
for (i = 0; i < array_len; i += 6) {
u32 v1 = array[i];
u32 v2 = array[i + 1];
u32 v3 = array[i + 2];
u32 v4 = array[i + 3];
u32 v5 = array[i + 4];
u32 v6 = array[i + 5];
odm_config_bb_phy_reg_pg_8822b(dm, v1, v2, v3, v4, v5, v6);
}
}
