static void rtl8821ae_init_aspm_vars(struct ieee80211_hw *hw)
{
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
rtlpci->const_amdpci_aspm = 0;
rtlpci->const_pci_aspm = 3;
rtlpci->const_devicepci_aspm_setting = 0x03;
rtlpci->const_hostpci_aspm_setting = 0x02;
rtlpci->const_hwsw_rfoff_d3 = 0;
rtlpci->const_support_pciaspm = 1;
}
int rtl8821ae_init_sw_vars(struct ieee80211_hw *hw)
{
int err = 0;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
rtl8821ae_bt_reg_init(hw);
rtlpci->msi_support = rtlpriv->cfg->mod_params->msi_support;
rtlpci->int_clear = rtlpriv->cfg->mod_params->int_clear;
rtlpriv->btcoexist.btc_ops = rtl_btc_get_ops_pointer();
rtlpriv->dm.dm_initialgain_enable = 1;
rtlpriv->dm.dm_flag = 0;
rtlpriv->dm.disable_framebursting = 0;
rtlpriv->dm.thermalvalue = 0;
rtlpci->transmit_config = CFENDFORM | BIT(15) | BIT(24) | BIT(25);
mac->ht_enable = true;
mac->ht_cur_stbc = 0;
mac->ht_stbc_cap = 0;
mac->vht_cur_ldpc = 0;
mac->vht_ldpc_cap = 0;
mac->vht_cur_stbc = 0;
mac->vht_stbc_cap = 0;
rtlpriv->rtlhal.current_bandtype = BAND_ON_2_4G;
rtlpriv->rtlhal.bandset = BAND_ON_BOTH;
rtlpriv->rtlhal.macphymode = SINGLEMAC_SINGLEPHY;
rtlpci->receive_config = (RCR_APPFCS |
RCR_APP_MIC |
RCR_APP_ICV |
RCR_APP_PHYST_RXFF |
RCR_NONQOS_VHT |
RCR_HTC_LOC_CTRL |
RCR_AMF |
RCR_ACF |
RCR_ADF |
RCR_AICV |
RCR_ACRC32 |
RCR_AB |
RCR_AM |
RCR_APM |
0);
rtlpci->irq_mask[0] =
(u32)(IMR_PSTIMEOUT |
IMR_GTINT3 |
IMR_HSISR_IND_ON_INT |
IMR_C2HCMD |
IMR_HIGHDOK |
IMR_MGNTDOK |
IMR_BKDOK |
IMR_BEDOK |
IMR_VIDOK |
IMR_VODOK |
IMR_RDU |
IMR_ROK |
0);
rtlpci->irq_mask[1] =
(u32)(IMR_RXFOVW |
IMR_TXFOVW |
0);
rtlpci->sys_irq_mask = (u32)(HSIMR_PDN_INT_EN |
HSIMR_RON_INT_EN |
0);
rtlpriv->psc.wo_wlan_mode = WAKE_ON_MAGIC_PACKET |
WAKE_ON_PATTERN_MATCH;
rtlpriv->dbg.global_debuglevel = rtlpriv->cfg->mod_params->debug;
rtlpriv->psc.inactiveps = rtlpriv->cfg->mod_params->inactiveps;
rtlpriv->psc.swctrl_lps = rtlpriv->cfg->mod_params->swctrl_lps;
rtlpriv->psc.fwctrl_lps = rtlpriv->cfg->mod_params->fwctrl_lps;
rtlpci->msi_support = rtlpriv->cfg->mod_params->msi_support;
rtlpci->msi_support = rtlpriv->cfg->mod_params->int_clear;
if (rtlpriv->cfg->mod_params->disable_watchdog)
pr_info("watchdog disabled\n");
rtlpriv->psc.reg_fwctrl_lps = 3;
rtlpriv->psc.reg_max_lps_awakeintvl = 5;
rtlpci->msi_support = rtlpriv->cfg->mod_params->msi_support;
rtl8821ae_init_aspm_vars(hw);
if (rtlpriv->psc.reg_fwctrl_lps == 1)
rtlpriv->psc.fwctrl_psmode = FW_PS_MIN_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 2)
rtlpriv->psc.fwctrl_psmode = FW_PS_MAX_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 3)
rtlpriv->psc.fwctrl_psmode = FW_PS_DTIM_MODE;
rtlpriv->rtlhal.pfirmware = vzalloc(0x8000);
if (!rtlpriv->rtlhal.pfirmware) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Can't alloc buffer for fw.\n");
return 1;
}
rtlpriv->rtlhal.wowlan_firmware = vzalloc(0x8000);
if (!rtlpriv->rtlhal.wowlan_firmware) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Can't alloc buffer for wowlan fw.\n");
return 1;
}
if (rtlhal->hw_type == HARDWARE_TYPE_RTL8812AE) {
rtlpriv->cfg->fw_name = "rtlwifi/rtl8812aefw.bin";
rtlpriv->cfg->wowlan_fw_name = "rtlwifi/rtl8812aefw_wowlan.bin";
} else {
rtlpriv->cfg->fw_name = "rtlwifi/rtl8821aefw.bin";
rtlpriv->cfg->wowlan_fw_name = "rtlwifi/rtl8821aefw_wowlan.bin";
}
rtlpriv->max_fw_size = 0x8000;
pr_info("Using firmware %s\n", rtlpriv->cfg->fw_name);
err = request_firmware_nowait(THIS_MODULE, 1, rtlpriv->cfg->fw_name,
rtlpriv->io.dev, GFP_KERNEL, hw,
rtl_fw_cb);
if (err) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Failed to request normal firmware!\n");
return 1;
}
pr_info("Using firmware %s\n", rtlpriv->cfg->wowlan_fw_name);
err = request_firmware_nowait(THIS_MODULE, 1,
rtlpriv->cfg->wowlan_fw_name,
rtlpriv->io.dev, GFP_KERNEL, hw,
rtl_wowlan_fw_cb);
if (err) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Failed to request wowlan firmware!\n");
return 1;
}
return 0;
}
void rtl8821ae_deinit_sw_vars(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
if (rtlpriv->rtlhal.pfirmware) {
vfree(rtlpriv->rtlhal.pfirmware);
rtlpriv->rtlhal.pfirmware = NULL;
}
#if (USE_SPECIFIC_FW_TO_SUPPORT_WOWLAN == 1)
if (rtlpriv->rtlhal.wowlan_firmware) {
vfree(rtlpriv->rtlhal.wowlan_firmware);
rtlpriv->rtlhal.wowlan_firmware = NULL;
}
#endif
}
bool rtl8821ae_get_btc_status(void)
{
return true;
}
