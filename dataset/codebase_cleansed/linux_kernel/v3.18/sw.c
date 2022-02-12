static void rtl92c_init_aspm_vars(struct ieee80211_hw *hw)
{
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
rtlpci->const_amdpci_aspm = 0;
rtlpci->const_pci_aspm = 3;
rtlpci->const_devicepci_aspm_setting = 0x03;
rtlpci->const_hostpci_aspm_setting = 0x02;
rtlpci->const_hwsw_rfoff_d3 = 0;
rtlpci->const_support_pciaspm = 1;
}
int rtl92c_init_sw_vars(struct ieee80211_hw *hw)
{
int err;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
rtl8192ce_bt_reg_init(hw);
rtlpriv->dm.dm_initialgain_enable = true;
rtlpriv->dm.dm_flag = 0;
rtlpriv->dm.disable_framebursting = false;
rtlpriv->dm.thermalvalue = 0;
rtlpci->transmit_config = CFENDFORM | BIT(12) | BIT(13);
rtlpriv->rtlhal.current_bandtype = BAND_ON_2_4G;
rtlpriv->rtlhal.bandset = BAND_ON_2_4G;
rtlpriv->rtlhal.macphymode = SINGLEMAC_SINGLEPHY;
rtlpci->receive_config = (RCR_APPFCS |
RCR_AMF |
RCR_ADF |
RCR_APP_MIC |
RCR_APP_ICV |
RCR_AICV |
RCR_ACRC32 |
RCR_AB |
RCR_AM |
RCR_APM |
RCR_APP_PHYST_RXFF | RCR_HTC_LOC_CTRL | 0);
rtlpci->irq_mask[0] =
(u32) (IMR_ROK |
IMR_VODOK |
IMR_VIDOK |
IMR_BEDOK |
IMR_BKDOK |
IMR_MGNTDOK |
IMR_HIGHDOK | IMR_BDOK | IMR_RDU | IMR_RXFOVW | 0);
rtlpci->irq_mask[1] = (u32) (IMR_CPWM | IMR_C2HCMD | 0);
rtlpriv->dbg.global_debuglevel = rtlpriv->cfg->mod_params->debug;
rtlpriv->psc.inactiveps = rtlpriv->cfg->mod_params->inactiveps;
rtlpriv->psc.swctrl_lps = rtlpriv->cfg->mod_params->swctrl_lps;
rtlpriv->psc.fwctrl_lps = rtlpriv->cfg->mod_params->fwctrl_lps;
if (!rtlpriv->psc.inactiveps)
pr_info("rtl8192ce: Power Save off (module option)\n");
if (!rtlpriv->psc.fwctrl_lps)
pr_info("rtl8192ce: FW Power Save off (module option)\n");
rtlpriv->psc.reg_fwctrl_lps = 3;
rtlpriv->psc.reg_max_lps_awakeintvl = 5;
rtl92c_init_aspm_vars(hw);
if (rtlpriv->psc.reg_fwctrl_lps == 1)
rtlpriv->psc.fwctrl_psmode = FW_PS_MIN_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 2)
rtlpriv->psc.fwctrl_psmode = FW_PS_MAX_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 3)
rtlpriv->psc.fwctrl_psmode = FW_PS_DTIM_MODE;
rtlpriv->rtlhal.pfirmware = vzalloc(0x4000);
if (!rtlpriv->rtlhal.pfirmware) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Can't alloc buffer for fw\n");
return 1;
}
if (IS_VENDOR_UMC_A_CUT(rtlhal->version) &&
!IS_92C_SERIAL(rtlhal->version))
rtlpriv->cfg->fw_name = "rtlwifi/rtl8192cfwU.bin";
else if (IS_81XXC_VENDOR_UMC_B_CUT(rtlhal->version))
rtlpriv->cfg->fw_name = "rtlwifi/rtl8192cfwU_B.bin";
rtlpriv->max_fw_size = 0x4000;
pr_info("Using firmware %s\n", rtlpriv->cfg->fw_name);
err = request_firmware_nowait(THIS_MODULE, 1, rtlpriv->cfg->fw_name,
rtlpriv->io.dev, GFP_KERNEL, hw,
rtl_fw_cb);
if (err) {
RT_TRACE(rtlpriv, COMP_ERR, DBG_EMERG,
"Failed to request firmware!\n");
return 1;
}
return 0;
}
void rtl92c_deinit_sw_vars(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
if (rtlpriv->rtlhal.pfirmware) {
vfree(rtlpriv->rtlhal.pfirmware);
rtlpriv->rtlhal.pfirmware = NULL;
}
}
