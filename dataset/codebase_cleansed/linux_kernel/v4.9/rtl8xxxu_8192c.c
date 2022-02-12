static int rtl8192cu_load_firmware(struct rtl8xxxu_priv *priv)
{
char *fw_name;
int ret;
if (!priv->vendor_umc)
fw_name = "rtlwifi/rtl8192cufw_TMSC.bin";
else if (priv->chip_cut || priv->rtl_chip == RTL8192C)
fw_name = "rtlwifi/rtl8192cufw_B.bin";
else
fw_name = "rtlwifi/rtl8192cufw_A.bin";
ret = rtl8xxxu_load_firmware(priv, fw_name);
return ret;
}
static int rtl8192cu_parse_efuse(struct rtl8xxxu_priv *priv)
{
struct rtl8192cu_efuse *efuse = &priv->efuse_wifi.efuse8192;
int i;
if (efuse->rtl_id != cpu_to_le16(0x8129))
return -EINVAL;
ether_addr_copy(priv->mac_addr, efuse->mac_addr);
memcpy(priv->cck_tx_power_index_A,
efuse->cck_tx_power_index_A,
sizeof(efuse->cck_tx_power_index_A));
memcpy(priv->cck_tx_power_index_B,
efuse->cck_tx_power_index_B,
sizeof(efuse->cck_tx_power_index_B));
memcpy(priv->ht40_1s_tx_power_index_A,
efuse->ht40_1s_tx_power_index_A,
sizeof(efuse->ht40_1s_tx_power_index_A));
memcpy(priv->ht40_1s_tx_power_index_B,
efuse->ht40_1s_tx_power_index_B,
sizeof(efuse->ht40_1s_tx_power_index_B));
memcpy(priv->ht40_2s_tx_power_index_diff,
efuse->ht40_2s_tx_power_index_diff,
sizeof(efuse->ht40_2s_tx_power_index_diff));
memcpy(priv->ht20_tx_power_index_diff,
efuse->ht20_tx_power_index_diff,
sizeof(efuse->ht20_tx_power_index_diff));
memcpy(priv->ofdm_tx_power_index_diff,
efuse->ofdm_tx_power_index_diff,
sizeof(efuse->ofdm_tx_power_index_diff));
memcpy(priv->ht40_max_power_offset,
efuse->ht40_max_power_offset,
sizeof(efuse->ht40_max_power_offset));
memcpy(priv->ht20_max_power_offset,
efuse->ht20_max_power_offset,
sizeof(efuse->ht20_max_power_offset));
dev_info(&priv->udev->dev, "Vendor: %.7s\n",
efuse->vendor_name);
dev_info(&priv->udev->dev, "Product: %.20s\n",
efuse->device_name);
priv->power_base = &rtl8192c_power_base;
if (efuse->rf_regulatory & 0x20) {
sprintf(priv->chip_name, "8188RU");
priv->rtl_chip = RTL8188R;
priv->hi_pa = 1;
priv->no_pape = 1;
priv->power_base = &rtl8188r_power_base;
}
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_EFUSE) {
unsigned char *raw = priv->efuse_wifi.raw;
dev_info(&priv->udev->dev,
"%s: dumping efuse (0x%02zx bytes):\n",
__func__, sizeof(struct rtl8192cu_efuse));
for (i = 0; i < sizeof(struct rtl8192cu_efuse); i += 8)
dev_info(&priv->udev->dev, "%02x: %8ph\n", i, &raw[i]);
}
return 0;
}
static int rtl8192cu_init_phy_rf(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_rfregval *rftable;
int ret;
if (priv->rtl_chip == RTL8188R) {
rftable = rtl8188ru_radioa_1t_highpa_table;
ret = rtl8xxxu_init_phy_rf(priv, rftable, RF_A);
} else if (priv->rf_paths == 1) {
rftable = rtl8192cu_radioa_1t_init_table;
ret = rtl8xxxu_init_phy_rf(priv, rftable, RF_A);
} else {
rftable = rtl8192cu_radioa_2t_init_table;
ret = rtl8xxxu_init_phy_rf(priv, rftable, RF_A);
if (ret)
goto exit;
rftable = rtl8192cu_radiob_2t_init_table;
ret = rtl8xxxu_init_phy_rf(priv, rftable, RF_B);
}
exit:
return ret;
}
static int rtl8192cu_power_on(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
u32 val32;
int i;
for (i = 100; i; i--) {
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO);
if (val8 & APS_FSMCO_PFM_ALDN)
break;
}
if (!i) {
pr_info("%s: Poll failed\n", __func__);
return -ENODEV;
}
rtl8xxxu_write8(priv, REG_RSV_CTRL, 0x0);
rtl8xxxu_write8(priv, REG_SPS0_CTRL, 0x2b);
udelay(100);
val8 = rtl8xxxu_read8(priv, REG_LDOV12D_CTRL);
if (!(val8 & LDOV12D_ENABLE)) {
pr_info("%s: Enabling LDOV12D (%02x)\n", __func__, val8);
val8 |= LDOV12D_ENABLE;
rtl8xxxu_write8(priv, REG_LDOV12D_CTRL, val8);
udelay(100);
val8 = rtl8xxxu_read8(priv, REG_SYS_ISO_CTRL);
val8 &= ~SYS_ISO_MD2PP;
rtl8xxxu_write8(priv, REG_SYS_ISO_CTRL, val8);
}
val16 = rtl8xxxu_read16(priv, REG_APS_FSMCO);
val16 |= APS_FSMCO_MAC_ENABLE;
rtl8xxxu_write16(priv, REG_APS_FSMCO, val16);
for (i = 1000; i; i--) {
val16 = rtl8xxxu_read16(priv, REG_APS_FSMCO);
if (!(val16 & APS_FSMCO_MAC_ENABLE))
break;
}
if (!i) {
pr_info("%s: FSMCO_MAC_ENABLE poll failed\n", __func__);
return -EBUSY;
}
val16 = APS_FSMCO_HW_SUSPEND | APS_FSMCO_ENABLE_POWERDOWN |
APS_FSMCO_PFM_ALDN;
rtl8xxxu_write16(priv, REG_APS_FSMCO, val16);
val16 = rtl8xxxu_read16(priv, REG_SYS_ISO_CTRL);
val16 &= ~SYS_ISO_DIOR;
rtl8xxxu_write16(priv, REG_SYS_ISO_CTRL, val16);
val8 = rtl8xxxu_read8(priv, REG_APSD_CTRL);
val8 &= ~APSD_CTRL_OFF;
rtl8xxxu_write8(priv, REG_APSD_CTRL, val8);
for (i = 200; i; i--) {
val8 = rtl8xxxu_read8(priv, REG_APSD_CTRL);
if (!(val8 & APSD_CTRL_OFF_STATUS))
break;
}
if (!i) {
pr_info("%s: APSD_CTRL poll failed\n", __func__);
return -EBUSY;
}
val16 = rtl8xxxu_read16(priv, REG_CR);
val16 |= CR_HCI_TXDMA_ENABLE | CR_HCI_RXDMA_ENABLE |
CR_TXDMA_ENABLE | CR_RXDMA_ENABLE | CR_PROTOCOL_ENABLE |
CR_SCHEDULE_ENABLE | CR_MAC_TX_ENABLE | CR_MAC_RX_ENABLE;
rtl8xxxu_write16(priv, REG_CR, val16);
rtl8xxxu_write8(priv, 0xfe10, 0x19);
if (priv->rtl_chip == RTL8188R) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XCD_RF_PARM);
val32 &= ~BIT(1);
rtl8xxxu_write32(priv, REG_FPGA0_XCD_RF_PARM, val32);
}
return 0;
}
