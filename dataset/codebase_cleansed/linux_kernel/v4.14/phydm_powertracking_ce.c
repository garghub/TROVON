void odm_txpowertracking_init(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
odm_txpowertracking_thermal_meter_init(dm);
}
static u8 get_swing_index(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
u8 i = 0;
u32 bb_swing;
u32 swing_table_size;
u32 *swing_table;
if (dm->support_ic_type == ODM_RTL8188E ||
dm->support_ic_type == ODM_RTL8723B ||
dm->support_ic_type == ODM_RTL8192E ||
dm->support_ic_type == ODM_RTL8188F ||
dm->support_ic_type == ODM_RTL8703B) {
bb_swing = odm_get_bb_reg(dm, REG_OFDM_0_XA_TX_IQ_IMBALANCE,
0xFFC00000);
swing_table = ofdm_swing_table_new;
swing_table_size = OFDM_TABLE_SIZE;
} else {
{
bb_swing = 0;
swing_table = ofdm_swing_table;
swing_table_size = OFDM_TABLE_SIZE;
}
}
for (i = 0; i < swing_table_size; ++i) {
u32 table_value = swing_table[i];
if (table_value >= 0x100000)
table_value >>= 22;
if (bb_swing == table_value)
break;
}
return i;
}
void odm_txpowertracking_thermal_meter_init(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
u8 default_swing_index = get_swing_index(dm);
u8 p = 0;
struct dm_rf_calibration_struct *cali_info = &dm->rf_calibrate_info;
struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;
struct rtl_efuse *rtlefu = rtl_efuse(rtlpriv);
cali_info->is_txpowertracking = true;
cali_info->tx_powercount = 0;
cali_info->is_txpowertracking_init = false;
if (!dm->mp_mode)
cali_info->txpowertrack_control = true;
else
cali_info->txpowertrack_control = false;
if (!dm->mp_mode)
cali_info->txpowertrack_control = true;
ODM_RT_TRACE(dm, ODM_COMP_CALIBRATION, "dm txpowertrack_control = %d\n",
cali_info->txpowertrack_control);
cali_info->thermal_value = rtlefu->eeprom_thermalmeter;
cali_info->thermal_value_iqk = rtlefu->eeprom_thermalmeter;
cali_info->thermal_value_lck = rtlefu->eeprom_thermalmeter;
if (!cali_info->default_bb_swing_index_flag) {
if (dm->support_ic_type == ODM_RTL8188E ||
dm->support_ic_type == ODM_RTL8723B ||
dm->support_ic_type == ODM_RTL8192E ||
dm->support_ic_type == ODM_RTL8703B) {
cali_info->default_ofdm_index =
(default_swing_index >= OFDM_TABLE_SIZE) ?
30 :
default_swing_index;
cali_info->default_cck_index = 20;
} else if (dm->support_ic_type ==
ODM_RTL8188F) {
cali_info->default_ofdm_index = 28;
cali_info->default_cck_index = 20;
} else if (dm->support_ic_type ==
ODM_RTL8723D) {
cali_info->default_ofdm_index = 28;
cali_info->default_cck_index = 28;
} else if (dm->support_ic_type ==
ODM_RTL8710B) {
cali_info->default_ofdm_index = 28;
cali_info->default_cck_index = 28;
} else {
cali_info->default_ofdm_index =
(default_swing_index >= TXSCALE_TABLE_SIZE) ?
24 :
default_swing_index;
cali_info->default_cck_index = 24;
}
cali_info->default_bb_swing_index_flag = true;
}
cali_info->bb_swing_idx_cck_base = cali_info->default_cck_index;
cali_info->CCK_index = cali_info->default_cck_index;
for (p = ODM_RF_PATH_A; p < MAX_RF_PATH; ++p) {
cali_info->bb_swing_idx_ofdm_base[p] =
cali_info->default_ofdm_index;
cali_info->OFDM_index[p] = cali_info->default_ofdm_index;
cali_info->delta_power_index[p] = 0;
cali_info->delta_power_index_last[p] = 0;
cali_info->power_index_offset[p] = 0;
}
cali_info->modify_tx_agc_value_ofdm = 0;
cali_info->modify_tx_agc_value_cck = 0;
}
void odm_txpowertracking_check(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
switch (dm->support_platform) {
case ODM_WIN:
odm_txpowertracking_check_mp(dm);
break;
case ODM_CE:
odm_txpowertracking_check_ce(dm);
break;
case ODM_AP:
odm_txpowertracking_check_ap(dm);
break;
default:
break;
}
}
void odm_txpowertracking_check_ce(void *dm_void)
{
struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
void *adapter = dm->adapter;
if (!(dm->support_ability & ODM_RF_TX_PWR_TRACK))
return;
if (!dm->rf_calibrate_info.tm_trigger) {
if (IS_HARDWARE_TYPE_8188E(adapter) ||
IS_HARDWARE_TYPE_8188F(adapter) ||
IS_HARDWARE_TYPE_8192E(adapter) ||
IS_HARDWARE_TYPE_8723B(adapter) ||
IS_HARDWARE_TYPE_JAGUAR(adapter) ||
IS_HARDWARE_TYPE_8814A(adapter) ||
IS_HARDWARE_TYPE_8703B(adapter) ||
IS_HARDWARE_TYPE_8723D(adapter) ||
IS_HARDWARE_TYPE_8822B(adapter) ||
IS_HARDWARE_TYPE_8821C(adapter) ||
(dm->support_ic_type == ODM_RTL8710B))
odm_set_rf_reg(dm, ODM_RF_PATH_A, RF_T_METER_NEW,
(BIT(17) | BIT(16)), 0x03);
else
odm_set_rf_reg(dm, ODM_RF_PATH_A, RF_T_METER_OLD,
RFREGOFFSETMASK, 0x60);
dm->rf_calibrate_info.tm_trigger = 1;
return;
}
odm_txpowertracking_callback_thermal_meter(dm);
dm->rf_calibrate_info.tm_trigger = 0;
}
void odm_txpowertracking_check_mp(void *dm_void) {}
void odm_txpowertracking_check_ap(void *dm_void) {}
