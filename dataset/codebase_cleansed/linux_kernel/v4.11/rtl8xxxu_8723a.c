static int rtl8723au_parse_efuse(struct rtl8xxxu_priv *priv)
{
struct rtl8723au_efuse *efuse = &priv->efuse_wifi.efuse8723;
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
if (priv->efuse_wifi.efuse8723.version >= 0x01) {
priv->has_xtalk = 1;
priv->xtalk = priv->efuse_wifi.efuse8723.xtal_k & 0x3f;
}
priv->power_base = &rtl8723a_power_base;
dev_info(&priv->udev->dev, "Vendor: %.7s\n",
efuse->vendor_name);
dev_info(&priv->udev->dev, "Product: %.41s\n",
efuse->device_name);
return 0;
}
static int rtl8723au_load_firmware(struct rtl8xxxu_priv *priv)
{
char *fw_name;
int ret;
switch (priv->chip_cut) {
case 0:
fw_name = "rtlwifi/rtl8723aufw_A.bin";
break;
case 1:
if (priv->enable_bluetooth)
fw_name = "rtlwifi/rtl8723aufw_B.bin";
else
fw_name = "rtlwifi/rtl8723aufw_B_NoBT.bin";
break;
default:
return -EINVAL;
}
ret = rtl8xxxu_load_firmware(priv, fw_name);
return ret;
}
static int rtl8723au_init_phy_rf(struct rtl8xxxu_priv *priv)
{
int ret;
ret = rtl8xxxu_init_phy_rf(priv, rtl8723au_radioa_1t_init_table, RF_A);
rtl8xxxu_write32(priv, REG_AFE_XTAL_CTRL, 0x0381808d);
rtl8xxxu_write32(priv, REG_AFE_PLL_CTRL, 0xf0ffff83);
rtl8xxxu_write32(priv, REG_AFE_PLL_CTRL, 0xf0ffff82);
rtl8xxxu_write32(priv, REG_AFE_PLL_CTRL, 0xf0ffff83);
return ret;
}
static int rtl8723a_emu_to_active(struct rtl8xxxu_priv *priv)
{
u8 val8;
u32 val32;
int count, ret = 0;
val8 = rtl8xxxu_read8(priv, REG_LDOA15_CTRL);
val8 |= LDOA15_ENABLE;
rtl8xxxu_write8(priv, REG_LDOA15_CTRL, val8);
val8 = rtl8xxxu_read8(priv, 0x0067);
val8 &= ~BIT(4);
rtl8xxxu_write8(priv, 0x0067, val8);
mdelay(1);
val8 = rtl8xxxu_read8(priv, REG_SYS_ISO_CTRL);
val8 &= ~SYS_ISO_ANALOG_IPS;
rtl8xxxu_write8(priv, REG_SYS_ISO_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~BIT(2);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
for (count = RTL8XXXU_MAX_REG_POLL; count; count--) {
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
if (val32 & BIT(17))
break;
udelay(10);
}
if (!count) {
ret = -EBUSY;
goto exit;
}
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 2);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 2, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~BIT(7);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~(BIT(3) | BIT(4));
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
val32 |= APS_FSMCO_MAC_ENABLE;
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
for (count = RTL8XXXU_MAX_REG_POLL; count; count--) {
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
if ((val32 & APS_FSMCO_MAC_ENABLE) == 0) {
ret = 0;
break;
}
udelay(10);
}
if (!count) {
ret = -EBUSY;
goto exit;
}
val8 = rtl8xxxu_read8(priv, REG_LEDCFG2);
val8 |= LEDCFG2_DPDT_SELECT;
val8 &= ~LEDCFG2_DPDT_SELECT;
rtl8xxxu_write8(priv, REG_LEDCFG2, val8);
exit:
return ret;
}
static int rtl8723au_power_on(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
u32 val32;
int ret;
rtl8xxxu_write8(priv, REG_RSV_CTRL, 0x0);
rtl8xxxu_disabled_to_emu(priv);
ret = rtl8723a_emu_to_active(priv);
if (ret)
goto exit;
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 2);
val8 |= BIT(3);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 2, val8);
val16 = rtl8xxxu_read16(priv, REG_CR);
val16 |= (CR_HCI_TXDMA_ENABLE | CR_HCI_RXDMA_ENABLE |
CR_TXDMA_ENABLE | CR_RXDMA_ENABLE |
CR_PROTOCOL_ENABLE | CR_SCHEDULE_ENABLE |
CR_MAC_TX_ENABLE | CR_MAC_RX_ENABLE |
CR_SECURITY_ENABLE | CR_CALTIMER_ENABLE);
rtl8xxxu_write16(priv, REG_CR, val16);
val32 = rtl8xxxu_read32(priv, REG_EFUSE_CTRL);
val32 &= ~(BIT(28) | BIT(29) | BIT(30));
val32 |= (0x06 << 28);
rtl8xxxu_write32(priv, REG_EFUSE_CTRL, val32);
exit:
return ret;
}
