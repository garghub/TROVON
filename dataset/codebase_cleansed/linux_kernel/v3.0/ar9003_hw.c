static void ar9003_hw_init_mode_regs(struct ath_hw *ah)
{
if (AR_SREV_9340(ah)) {
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_CORE],
ar9340_1p0_mac_core,
ARRAY_SIZE(ar9340_1p0_mac_core), 2);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_POST],
ar9340_1p0_mac_postamble,
ARRAY_SIZE(ar9340_1p0_mac_postamble), 5);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_CORE],
ar9340_1p0_baseband_core,
ARRAY_SIZE(ar9340_1p0_baseband_core), 2);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_POST],
ar9340_1p0_baseband_postamble,
ARRAY_SIZE(ar9340_1p0_baseband_postamble), 5);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_CORE],
ar9340_1p0_radio_core,
ARRAY_SIZE(ar9340_1p0_radio_core), 2);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_POST],
ar9340_1p0_radio_postamble,
ARRAY_SIZE(ar9340_1p0_radio_postamble), 5);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_PRE],
ar9340_1p0_soc_preamble,
ARRAY_SIZE(ar9340_1p0_soc_preamble), 2);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_CORE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_POST],
ar9340_1p0_soc_postamble,
ARRAY_SIZE(ar9340_1p0_soc_postamble), 5);
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9340Common_wo_xlna_rx_gain_table_1p0,
ARRAY_SIZE(ar9340Common_wo_xlna_rx_gain_table_1p0),
5);
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9340Modes_high_ob_db_tx_gain_table_1p0,
ARRAY_SIZE(ar9340Modes_high_ob_db_tx_gain_table_1p0),
5);
INIT_INI_ARRAY(&ah->iniModesAdditional,
ar9340Modes_fast_clock_1p0,
ARRAY_SIZE(ar9340Modes_fast_clock_1p0),
3);
INIT_INI_ARRAY(&ah->iniModesAdditional_40M,
ar9340_1p0_radio_core_40M,
ARRAY_SIZE(ar9340_1p0_radio_core_40M),
2);
} else if (AR_SREV_9485_11(ah)) {
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_CORE],
ar9485_1_1_mac_core,
ARRAY_SIZE(ar9485_1_1_mac_core), 2);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_POST],
ar9485_1_1_mac_postamble,
ARRAY_SIZE(ar9485_1_1_mac_postamble), 5);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_PRE], ar9485_1_1,
ARRAY_SIZE(ar9485_1_1), 2);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_CORE],
ar9485_1_1_baseband_core,
ARRAY_SIZE(ar9485_1_1_baseband_core), 2);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_POST],
ar9485_1_1_baseband_postamble,
ARRAY_SIZE(ar9485_1_1_baseband_postamble), 5);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_CORE],
ar9485_1_1_radio_core,
ARRAY_SIZE(ar9485_1_1_radio_core), 2);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_POST],
ar9485_1_1_radio_postamble,
ARRAY_SIZE(ar9485_1_1_radio_postamble), 2);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_PRE],
ar9485_1_1_soc_preamble,
ARRAY_SIZE(ar9485_1_1_soc_preamble), 2);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_CORE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_POST], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9485Common_wo_xlna_rx_gain_1_1,
ARRAY_SIZE(ar9485Common_wo_xlna_rx_gain_1_1), 2);
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9485_modes_lowest_ob_db_tx_gain_1_1,
ARRAY_SIZE(ar9485_modes_lowest_ob_db_tx_gain_1_1),
5);
INIT_INI_ARRAY(&ah->iniPcieSerdes,
ar9485_1_1_pcie_phy_clkreq_disable_L1,
ARRAY_SIZE(ar9485_1_1_pcie_phy_clkreq_disable_L1),
2);
INIT_INI_ARRAY(&ah->iniPcieSerdesLowPower,
ar9485_1_1_pcie_phy_clkreq_disable_L1,
ARRAY_SIZE(ar9485_1_1_pcie_phy_clkreq_disable_L1),
2);
} else {
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_CORE],
ar9300_2p2_mac_core,
ARRAY_SIZE(ar9300_2p2_mac_core), 2);
INIT_INI_ARRAY(&ah->iniMac[ATH_INI_POST],
ar9300_2p2_mac_postamble,
ARRAY_SIZE(ar9300_2p2_mac_postamble), 5);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_CORE],
ar9300_2p2_baseband_core,
ARRAY_SIZE(ar9300_2p2_baseband_core), 2);
INIT_INI_ARRAY(&ah->iniBB[ATH_INI_POST],
ar9300_2p2_baseband_postamble,
ARRAY_SIZE(ar9300_2p2_baseband_postamble), 5);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_PRE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_CORE],
ar9300_2p2_radio_core,
ARRAY_SIZE(ar9300_2p2_radio_core), 2);
INIT_INI_ARRAY(&ah->iniRadio[ATH_INI_POST],
ar9300_2p2_radio_postamble,
ARRAY_SIZE(ar9300_2p2_radio_postamble), 5);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_PRE],
ar9300_2p2_soc_preamble,
ARRAY_SIZE(ar9300_2p2_soc_preamble), 2);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_CORE], NULL, 0, 0);
INIT_INI_ARRAY(&ah->iniSOC[ATH_INI_POST],
ar9300_2p2_soc_postamble,
ARRAY_SIZE(ar9300_2p2_soc_postamble), 5);
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9300Common_rx_gain_table_2p2,
ARRAY_SIZE(ar9300Common_rx_gain_table_2p2), 2);
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9300Modes_lowest_ob_db_tx_gain_table_2p2,
ARRAY_SIZE(ar9300Modes_lowest_ob_db_tx_gain_table_2p2),
5);
INIT_INI_ARRAY(&ah->iniPcieSerdes,
ar9300PciePhy_pll_on_clkreq_disable_L1_2p2,
ARRAY_SIZE(ar9300PciePhy_pll_on_clkreq_disable_L1_2p2),
2);
INIT_INI_ARRAY(&ah->iniPcieSerdesLowPower,
ar9300PciePhy_pll_on_clkreq_disable_L1_2p2,
ARRAY_SIZE(ar9300PciePhy_pll_on_clkreq_disable_L1_2p2),
2);
INIT_INI_ARRAY(&ah->iniModesAdditional,
ar9300Modes_fast_clock_2p2,
ARRAY_SIZE(ar9300Modes_fast_clock_2p2),
3);
}
}
static void ar9003_tx_gain_table_apply(struct ath_hw *ah)
{
switch (ar9003_hw_get_tx_gain_idx(ah)) {
case 0:
default:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9340Modes_lowest_ob_db_tx_gain_table_1p0,
ARRAY_SIZE(ar9340Modes_lowest_ob_db_tx_gain_table_1p0),
5);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9485_modes_lowest_ob_db_tx_gain_1_1,
ARRAY_SIZE(ar9485_modes_lowest_ob_db_tx_gain_1_1),
5);
else
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9300Modes_lowest_ob_db_tx_gain_table_2p2,
ARRAY_SIZE(ar9300Modes_lowest_ob_db_tx_gain_table_2p2),
5);
break;
case 1:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9340Modes_lowest_ob_db_tx_gain_table_1p0,
ARRAY_SIZE(ar9340Modes_lowest_ob_db_tx_gain_table_1p0),
5);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9485Modes_high_ob_db_tx_gain_1_1,
ARRAY_SIZE(ar9485Modes_high_ob_db_tx_gain_1_1),
5);
else
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9300Modes_high_ob_db_tx_gain_table_2p2,
ARRAY_SIZE(ar9300Modes_high_ob_db_tx_gain_table_2p2),
5);
break;
case 2:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9340Modes_lowest_ob_db_tx_gain_table_1p0,
ARRAY_SIZE(ar9340Modes_lowest_ob_db_tx_gain_table_1p0),
5);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9485Modes_low_ob_db_tx_gain_1_1,
ARRAY_SIZE(ar9485Modes_low_ob_db_tx_gain_1_1),
5);
else
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9300Modes_low_ob_db_tx_gain_table_2p2,
ARRAY_SIZE(ar9300Modes_low_ob_db_tx_gain_table_2p2),
5);
break;
case 3:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9340Modes_lowest_ob_db_tx_gain_table_1p0,
ARRAY_SIZE(ar9340Modes_lowest_ob_db_tx_gain_table_1p0),
5);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9485Modes_high_power_tx_gain_1_1,
ARRAY_SIZE(ar9485Modes_high_power_tx_gain_1_1),
5);
else
INIT_INI_ARRAY(&ah->iniModesTxGain,
ar9300Modes_high_power_tx_gain_table_2p2,
ARRAY_SIZE(ar9300Modes_high_power_tx_gain_table_2p2),
5);
break;
}
}
static void ar9003_rx_gain_table_apply(struct ath_hw *ah)
{
switch (ar9003_hw_get_rx_gain_idx(ah)) {
case 0:
default:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9340Common_rx_gain_table_1p0,
ARRAY_SIZE(ar9340Common_rx_gain_table_1p0),
2);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9485Common_wo_xlna_rx_gain_1_1,
ARRAY_SIZE(ar9485Common_wo_xlna_rx_gain_1_1),
2);
else
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9300Common_rx_gain_table_2p2,
ARRAY_SIZE(ar9300Common_rx_gain_table_2p2),
2);
break;
case 1:
if (AR_SREV_9340(ah))
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9340Common_wo_xlna_rx_gain_table_1p0,
ARRAY_SIZE(ar9340Common_wo_xlna_rx_gain_table_1p0),
2);
else if (AR_SREV_9485_11(ah))
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9485Common_wo_xlna_rx_gain_1_1,
ARRAY_SIZE(ar9485Common_wo_xlna_rx_gain_1_1),
2);
else
INIT_INI_ARRAY(&ah->iniModesRxGain,
ar9300Common_wo_xlna_rx_gain_table_2p2,
ARRAY_SIZE(ar9300Common_wo_xlna_rx_gain_table_2p2),
2);
break;
}
}
static void ar9003_hw_init_mode_gain_regs(struct ath_hw *ah)
{
ar9003_tx_gain_table_apply(ah);
ar9003_rx_gain_table_apply(ah);
}
static void ar9003_hw_configpcipowersave(struct ath_hw *ah,
int restore,
int power_off)
{
if (ah->is_pciexpress != true)
return;
if (ah->config.pcie_powersave_enable == 2)
return;
if (!restore) {
REG_SET_BIT(ah, AR_PCIE_PM_CTRL, AR_PCIE_PM_CTRL_ENA);
if (ah->config.pcie_waen)
REG_WRITE(ah, AR_WA, ah->config.pcie_waen);
else
REG_WRITE(ah, AR_WA, ah->WARegVal);
}
if (ah->config.pcieSerDesWrite) {
unsigned int i;
struct ar5416IniArray *array;
array = power_off ? &ah->iniPcieSerdes :
&ah->iniPcieSerdesLowPower;
for (i = 0; i < array->ia_rows; i++) {
REG_WRITE(ah,
INI_RA(array, i, 0),
INI_RA(array, i, 1));
}
}
}
void ar9003_hw_attach_ops(struct ath_hw *ah)
{
struct ath_hw_private_ops *priv_ops = ath9k_hw_private_ops(ah);
struct ath_hw_ops *ops = ath9k_hw_ops(ah);
priv_ops->init_mode_regs = ar9003_hw_init_mode_regs;
priv_ops->init_mode_gain_regs = ar9003_hw_init_mode_gain_regs;
ops->config_pci_powersave = ar9003_hw_configpcipowersave;
ar9003_hw_attach_phy_ops(ah);
ar9003_hw_attach_calib_ops(ah);
ar9003_hw_attach_mac_ops(ah);
}
