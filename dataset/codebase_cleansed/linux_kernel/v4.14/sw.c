static void rtl92d_init_aspm_vars(struct ieee80211_hw *hw)
{
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
rtlpci->const_amdpci_aspm = 0;
rtlpci->const_pci_aspm = 3;
rtlpci->const_devicepci_aspm_setting = 0x03;
rtlpci->const_hostpci_aspm_setting = 0x02;
rtlpci->const_hwsw_rfoff_d3 = 0;
rtlpci->const_support_pciaspm = 1;
}
static int rtl92d_init_sw_vars(struct ieee80211_hw *hw)
{
int err;
u8 tid;
struct rtl_priv *rtlpriv = rtl_priv(hw);
struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
char *fw_name = "rtlwifi/rtl8192defw.bin";
rtlpriv->dm.dm_initialgain_enable = true;
rtlpriv->dm.dm_flag = 0;
rtlpriv->dm.disable_framebursting = false;
rtlpriv->dm.thermalvalue = 0;
rtlpriv->dm.useramask = true;
if (rtlpriv->rtlhal.current_bandtype == BAND_ON_5G)
rtlpriv->phy.current_channel = 36;
else
rtlpriv->phy.current_channel = 1;
if (rtlpriv->rtlhal.macphymode != SINGLEMAC_SINGLEPHY) {
rtlpriv->rtlhal.disable_amsdu_8k = true;
rtlpci->rxbuffersize = 4096;
}
rtlpci->transmit_config = CFENDFORM | BIT(12) | BIT(13);
rtlpci->receive_config = (
RCR_APPFCS
| RCR_AMF
| RCR_ADF
| RCR_APP_MIC
| RCR_APP_ICV
| RCR_AICV
| RCR_ACRC32
| RCR_AB
| RCR_AM
| RCR_APM
| RCR_APP_PHYST_RXFF
| RCR_HTC_LOC_CTRL
);
rtlpci->irq_mask[0] = (u32) (
IMR_ROK
| IMR_VODOK
| IMR_VIDOK
| IMR_BEDOK
| IMR_BKDOK
| IMR_MGNTDOK
| IMR_HIGHDOK
| IMR_BDOK
| IMR_RDU
| IMR_RXFOVW
);
rtlpci->irq_mask[1] = (u32) (IMR_CPWM | IMR_C2HCMD);
rtlpriv->psc.inactiveps = rtlpriv->cfg->mod_params->inactiveps;
rtlpriv->psc.swctrl_lps = rtlpriv->cfg->mod_params->swctrl_lps;
rtlpriv->psc.fwctrl_lps = rtlpriv->cfg->mod_params->fwctrl_lps;
if (!rtlpriv->psc.inactiveps)
pr_info("Power Save off (module option)\n");
if (!rtlpriv->psc.fwctrl_lps)
pr_info("FW Power Save off (module option)\n");
rtlpriv->psc.reg_fwctrl_lps = 3;
rtlpriv->psc.reg_max_lps_awakeintvl = 5;
rtl92d_init_aspm_vars(hw);
if (rtlpriv->psc.reg_fwctrl_lps == 1)
rtlpriv->psc.fwctrl_psmode = FW_PS_MIN_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 2)
rtlpriv->psc.fwctrl_psmode = FW_PS_MAX_MODE;
else if (rtlpriv->psc.reg_fwctrl_lps == 3)
rtlpriv->psc.fwctrl_psmode = FW_PS_DTIM_MODE;
rtlpriv->rtlhal.earlymode_enable = false;
for (tid = 0; tid < 8; tid++)
skb_queue_head_init(&rtlpriv->mac80211.skb_waitq[tid]);
rtlpriv->rtlhal.pfirmware = vzalloc(0x8000);
if (!rtlpriv->rtlhal.pfirmware) {
pr_err("Can't alloc buffer for fw\n");
return 1;
}
rtlpriv->max_fw_size = 0x8000;
pr_info("Driver for Realtek RTL8192DE WLAN interface\n");
pr_info("Loading firmware file %s\n", fw_name);
err = request_firmware_nowait(THIS_MODULE, 1, fw_name,
rtlpriv->io.dev, GFP_KERNEL, hw,
rtl_fw_cb);
if (err) {
pr_err("Failed to request firmware!\n");
vfree(rtlpriv->rtlhal.pfirmware);
rtlpriv->rtlhal.pfirmware = NULL;
return 1;
}
return 0;
}
static void rtl92d_deinit_sw_vars(struct ieee80211_hw *hw)
{
struct rtl_priv *rtlpriv = rtl_priv(hw);
u8 tid;
if (rtlpriv->rtlhal.pfirmware) {
vfree(rtlpriv->rtlhal.pfirmware);
rtlpriv->rtlhal.pfirmware = NULL;
}
for (tid = 0; tid < 8; tid++)
skb_queue_purge(&rtlpriv->mac80211.skb_waitq[tid]);
}
static int __init rtl92de_module_init(void)
{
int ret = 0;
spin_lock_init(&globalmutex_power);
spin_lock_init(&globalmutex_for_fwdownload);
spin_lock_init(&globalmutex_for_power_and_efuse);
ret = pci_register_driver(&rtl92de_driver);
if (ret)
WARN_ONCE(true, "rtl8192de: No device found\n");
return ret;
}
static void __exit rtl92de_module_exit(void)
{
pci_unregister_driver(&rtl92de_driver);
}
