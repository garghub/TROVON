void odm_dynamic_tx_power_init(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
dm->last_dtp_lvl = tx_high_pwr_level_normal;
dm->dynamic_tx_high_power_lvl = tx_high_pwr_level_normal;
dm->tx_agc_ofdm_18_6 =
odm_get_bb_reg(dm, 0xC24, MASKDWORD);
}
void odm_dynamic_tx_power_save_power_index(void *dm_void) {}
void odm_dynamic_tx_power_restore_power_index(void *dm_void) {}
void odm_dynamic_tx_power_write_power_index(void *dm_void, u8 value)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
u8 index;
u32 power_index_reg[6] = {0xc90, 0xc91, 0xc92, 0xc98, 0xc99, 0xc9a};
for (index = 0; index < 6; index++)
odm_write_1byte(dm, power_index_reg[index], value);
}
static void odm_dynamic_tx_power_nic_ce(void *dm_void) {}
void odm_dynamic_tx_power(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
if (!(dm->support_ability & ODM_BB_DYNAMIC_TXPWR))
return;
switch (dm->support_platform) {
case ODM_WIN:
odm_dynamic_tx_power_nic(dm);
break;
case ODM_CE:
odm_dynamic_tx_power_nic_ce(dm);
break;
case ODM_AP:
odm_dynamic_tx_power_ap(dm);
break;
default:
break;
}
}
void odm_dynamic_tx_power_nic(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
if (!(dm->support_ability & ODM_BB_DYNAMIC_TXPWR))
return;
}
void odm_dynamic_tx_power_ap(void *dm_void
)
{
}
void odm_dynamic_tx_power_8821(void *dm_void, u8 *desc, u8 mac_id) {}
