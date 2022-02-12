void odm_stop_antenna_switch_dm(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
dm->support_ability &= ~ODM_BB_ANT_DIV;
ODM_RT_TRACE(dm, ODM_COMP_ANT_DIV, "STOP Antenna Diversity\n");
}
void phydm_enable_antenna_diversity(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
dm->support_ability |= ODM_BB_ANT_DIV;
ODM_RT_TRACE(dm, ODM_COMP_ANT_DIV,
"AntDiv is enabled & Re-Init AntDiv\n");
odm_antenna_diversity_init(dm);
}
void odm_set_ant_config(void *dm_void, u8 ant_setting
)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
if (dm->support_ic_type == ODM_RTL8723B) {
if (ant_setting == 0)
odm_set_bb_reg(dm, 0x948, MASKDWORD, 0x00000000);
else if (ant_setting == 1)
odm_set_bb_reg(dm, 0x948, MASKDWORD, 0x00000280);
} else if (dm->support_ic_type == ODM_RTL8723D) {
if (ant_setting == 0)
odm_set_bb_reg(dm, 0x948, MASKLWORD, 0x0000);
else if (ant_setting == 1)
odm_set_bb_reg(dm, 0x948, MASKLWORD, 0x0280);
}
}
void odm_sw_ant_div_rest_after_link(void *dm_void) {}
void odm_ant_div_reset(void *dm_void) {}
void odm_antenna_diversity_init(void *dm_void) {}
void odm_antenna_diversity(void *dm_void) {}
