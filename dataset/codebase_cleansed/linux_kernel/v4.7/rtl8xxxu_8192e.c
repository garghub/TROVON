static void
rtl8192e_set_tx_power(struct rtl8xxxu_priv *priv, int channel, bool ht40)
{
u32 val32, ofdm, mcs;
u8 cck, ofdmbase, mcsbase;
int group, tx_idx;
tx_idx = 0;
group = rtl8xxxu_gen2_channel_to_group(channel);
cck = priv->cck_tx_power_index_A[group];
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_A_CCK1_MCS32);
val32 &= 0xffff00ff;
val32 |= (cck << 8);
rtl8xxxu_write32(priv, REG_TX_AGC_A_CCK1_MCS32, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11);
val32 &= 0xff;
val32 |= ((cck << 8) | (cck << 16) | (cck << 24));
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11, val32);
ofdmbase = priv->ht40_1s_tx_power_index_A[group];
ofdmbase += priv->ofdm_tx_power_diff[tx_idx].a;
ofdm = ofdmbase | ofdmbase << 8 | ofdmbase << 16 | ofdmbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE18_06, ofdm);
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE54_24, ofdm);
mcsbase = priv->ht40_1s_tx_power_index_A[group];
if (ht40)
mcsbase += priv->ht40_tx_power_diff[tx_idx++].a;
else
mcsbase += priv->ht20_tx_power_diff[tx_idx++].a;
mcs = mcsbase | mcsbase << 8 | mcsbase << 16 | mcsbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS03_MCS00, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS07_MCS04, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS11_MCS08, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS15_MCS12, mcs);
if (priv->tx_paths > 1) {
cck = priv->cck_tx_power_index_B[group];
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK1_55_MCS32);
val32 &= 0xff;
val32 |= ((cck << 8) | (cck << 16) | (cck << 24));
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK1_55_MCS32, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11);
val32 &= 0xffffff00;
val32 |= cck;
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11, val32);
ofdmbase = priv->ht40_1s_tx_power_index_B[group];
ofdmbase += priv->ofdm_tx_power_diff[tx_idx].b;
ofdm = ofdmbase | ofdmbase << 8 |
ofdmbase << 16 | ofdmbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_B_RATE18_06, ofdm);
rtl8xxxu_write32(priv, REG_TX_AGC_B_RATE54_24, ofdm);
mcsbase = priv->ht40_1s_tx_power_index_B[group];
if (ht40)
mcsbase += priv->ht40_tx_power_diff[tx_idx++].b;
else
mcsbase += priv->ht20_tx_power_diff[tx_idx++].b;
mcs = mcsbase | mcsbase << 8 | mcsbase << 16 | mcsbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS03_MCS00, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS07_MCS04, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS11_MCS08, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS15_MCS12, mcs);
}
}
static int rtl8192eu_parse_efuse(struct rtl8xxxu_priv *priv)
{
struct rtl8192eu_efuse *efuse = &priv->efuse_wifi.efuse8192eu;
int i;
if (efuse->rtl_id != cpu_to_le16(0x8129))
return -EINVAL;
ether_addr_copy(priv->mac_addr, efuse->mac_addr);
memcpy(priv->cck_tx_power_index_A, efuse->tx_power_index_A.cck_base,
sizeof(efuse->tx_power_index_A.cck_base));
memcpy(priv->cck_tx_power_index_B, efuse->tx_power_index_B.cck_base,
sizeof(efuse->tx_power_index_B.cck_base));
memcpy(priv->ht40_1s_tx_power_index_A,
efuse->tx_power_index_A.ht40_base,
sizeof(efuse->tx_power_index_A.ht40_base));
memcpy(priv->ht40_1s_tx_power_index_B,
efuse->tx_power_index_B.ht40_base,
sizeof(efuse->tx_power_index_B.ht40_base));
priv->ht20_tx_power_diff[0].a =
efuse->tx_power_index_A.ht20_ofdm_1s_diff.b;
priv->ht20_tx_power_diff[0].b =
efuse->tx_power_index_B.ht20_ofdm_1s_diff.b;
priv->ht40_tx_power_diff[0].a = 0;
priv->ht40_tx_power_diff[0].b = 0;
for (i = 1; i < RTL8723B_TX_COUNT; i++) {
priv->ofdm_tx_power_diff[i].a =
efuse->tx_power_index_A.pwr_diff[i - 1].ofdm;
priv->ofdm_tx_power_diff[i].b =
efuse->tx_power_index_B.pwr_diff[i - 1].ofdm;
priv->ht20_tx_power_diff[i].a =
efuse->tx_power_index_A.pwr_diff[i - 1].ht20;
priv->ht20_tx_power_diff[i].b =
efuse->tx_power_index_B.pwr_diff[i - 1].ht20;
priv->ht40_tx_power_diff[i].a =
efuse->tx_power_index_A.pwr_diff[i - 1].ht40;
priv->ht40_tx_power_diff[i].b =
efuse->tx_power_index_B.pwr_diff[i - 1].ht40;
}
priv->has_xtalk = 1;
priv->xtalk = priv->efuse_wifi.efuse8192eu.xtal_k & 0x3f;
dev_info(&priv->udev->dev, "Vendor: %.7s\n", efuse->vendor_name);
dev_info(&priv->udev->dev, "Product: %.11s\n", efuse->device_name);
dev_info(&priv->udev->dev, "Serial: %.11s\n", efuse->serial);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_EFUSE) {
unsigned char *raw = priv->efuse_wifi.raw;
dev_info(&priv->udev->dev,
"%s: dumping efuse (0x%02zx bytes):\n",
__func__, sizeof(struct rtl8192eu_efuse));
for (i = 0; i < sizeof(struct rtl8192eu_efuse); i += 8) {
dev_info(&priv->udev->dev, "%02x: "
"%02x %02x %02x %02x %02x %02x %02x %02x\n", i,
raw[i], raw[i + 1], raw[i + 2],
raw[i + 3], raw[i + 4], raw[i + 5],
raw[i + 6], raw[i + 7]);
}
}
return 0;
}
static int rtl8192eu_load_firmware(struct rtl8xxxu_priv *priv)
{
char *fw_name;
int ret;
fw_name = "rtlwifi/rtl8192eu_nic.bin";
ret = rtl8xxxu_load_firmware(priv, fw_name);
return ret;
}
static void rtl8192eu_init_phy_bb(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= SYS_FUNC_BB_GLB_RSTN | SYS_FUNC_BBRSTB | SYS_FUNC_DIO_RF;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
val8 = RF_ENABLE | RF_RSTB | RF_SDMRSTB;
rtl8xxxu_write8(priv, REG_RF_CTRL, val8);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= (SYS_FUNC_USBA | SYS_FUNC_USBD | SYS_FUNC_DIO_RF |
SYS_FUNC_BB_GLB_RSTN | SYS_FUNC_BBRSTB);
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
val8 = RF_ENABLE | RF_RSTB | RF_SDMRSTB;
rtl8xxxu_write8(priv, REG_RF_CTRL, val8);
rtl8xxxu_init_phy_regs(priv, rtl8192eu_phy_init_table);
if (priv->hi_pa)
rtl8xxxu_init_phy_regs(priv, rtl8xxx_agc_8192eu_highpa_table);
else
rtl8xxxu_init_phy_regs(priv, rtl8xxx_agc_8192eu_std_table);
}
static int rtl8192eu_init_phy_rf(struct rtl8xxxu_priv *priv)
{
int ret;
ret = rtl8xxxu_init_phy_rf(priv, rtl8192eu_radioa_init_table, RF_A);
if (ret)
goto exit;
ret = rtl8xxxu_init_phy_rf(priv, rtl8192eu_radiob_init_table, RF_B);
exit:
return ret;
}
static int rtl8192eu_iqk_path_a(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_e94, reg_e9c;
int result = 0;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x00180);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82140303);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x68160000);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x00462911);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf9000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(10);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_e94 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_A);
reg_e9c = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_A);
if (!(reg_eac & BIT(28)) &&
((reg_e94 & 0x03ff0000) != 0x01420000) &&
((reg_e9c & 0x03ff0000) != 0x00420000))
result |= 0x01;
return result;
}
static int rtl8192eu_rx_iqk_path_a(struct rtl8xxxu_priv *priv)
{
u32 reg_ea4, reg_eac, reg_e94, reg_e9c, val32;
int result = 0;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, 0x800a0);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0000f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xf117b);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x00980);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_56, 0x51000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82160c1f);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x68160c1f);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a911);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xfa000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(10);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_e94 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_A);
reg_e9c = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_A);
if (!(reg_eac & BIT(28)) &&
((reg_e94 & 0x03ff0000) != 0x01420000) &&
((reg_e9c & 0x03ff0000) != 0x00420000)) {
result |= 0x01;
} else {
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x180);
goto out;
}
val32 = 0x80007c00 |
(reg_e94 & 0x03ff0000) | ((reg_e9c >> 16) & 0x03ff);
rtl8xxxu_write32(priv, REG_TX_IQK, val32);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, 0x800a0);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0000f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xf7ffa);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x00980);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_56, 0x51000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82160c1f);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x28160c1f);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a891);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xfa000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(10);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_ea4 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_A_2);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x180);
if (!(reg_eac & BIT(27)) &&
((reg_ea4 & 0x03ff0000) != 0x01320000) &&
((reg_eac & 0x03ff0000) != 0x00360000))
result |= 0x02;
else
dev_warn(&priv->udev->dev, "%s: Path A RX IQK failed!\n",
__func__);
out:
return result;
}
static int rtl8192eu_iqk_path_b(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_eb4, reg_ebc;
int result = 0;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_DF, 0x00180);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x821403e2);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x68160000);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x00492911);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xfa000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(1);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_eb4 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
reg_ebc = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
if (!(reg_eac & BIT(31)) &&
((reg_eb4 & 0x03ff0000) != 0x01420000) &&
((reg_ebc & 0x03ff0000) != 0x00420000))
result |= 0x01;
else
dev_warn(&priv->udev->dev, "%s: Path B IQK failed!\n",
__func__);
return result;
}
static int rtl8192eu_rx_iqk_path_b(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_eb4, reg_ebc, reg_ec4, reg_ecc, val32;
int result = 0;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_WE_LUT, 0x800a0);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_TXPA_G1, 0x0000f);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_TXPA_G2, 0xf117b);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_DF, 0x00980);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_56, 0x51000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x82160c1f);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x68160c1f);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a911);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xfa000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(10);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_eb4 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
reg_ebc = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
if (!(reg_eac & BIT(31)) &&
((reg_eb4 & 0x03ff0000) != 0x01420000) &&
((reg_ebc & 0x03ff0000) != 0x00420000)) {
result |= 0x01;
} else {
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_DF, 0x180);
goto out;
}
val32 = 0x80007c00 |
(reg_eb4 & 0x03ff0000) | ((reg_ebc >> 16) & 0x03ff);
rtl8xxxu_write32(priv, REG_TX_IQK, val32);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_WE_LUT, 0x800a0);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_TXPA_G1, 0x0000f);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_TXPA_G2, 0xf7ffa);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_DF, 0x00980);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_56, 0x51000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x18008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82160c1f);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x28160c1f);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a891);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xfa000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(10);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_ec4 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_B_2);
reg_ecc = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_B_2);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_UNKNOWN_DF, 0x180);
if (!(reg_eac & BIT(30)) &&
((reg_ec4 & 0x03ff0000) != 0x01320000) &&
((reg_ecc & 0x03ff0000) != 0x00360000))
result |= 0x02;
else
dev_warn(&priv->udev->dev, "%s: Path B RX IQK failed!\n",
__func__);
out:
return result;
}
static void rtl8192eu_phy_iqcalibrate(struct rtl8xxxu_priv *priv,
int result[][8], int t)
{
struct device *dev = &priv->udev->dev;
u32 i, val32;
int path_a_ok, path_b_ok;
int retry = 2;
const u32 adda_regs[RTL8XXXU_ADDA_REGS] = {
REG_FPGA0_XCD_SWITCH_CTRL, REG_BLUETOOTH,
REG_RX_WAIT_CCA, REG_TX_CCK_RFON,
REG_TX_CCK_BBON, REG_TX_OFDM_RFON,
REG_TX_OFDM_BBON, REG_TX_TO_RX,
REG_TX_TO_TX, REG_RX_CCK,
REG_RX_OFDM, REG_RX_WAIT_RIFS,
REG_RX_TO_RX, REG_STANDBY,
REG_SLEEP, REG_PMPD_ANAEN
};
const u32 iqk_mac_regs[RTL8XXXU_MAC_REGS] = {
REG_TXPAUSE, REG_BEACON_CTRL,
REG_BEACON_CTRL_1, REG_GPIO_MUXCFG
};
const u32 iqk_bb_regs[RTL8XXXU_BB_REGS] = {
REG_OFDM0_TRX_PATH_ENABLE, REG_OFDM0_TR_MUX_PAR,
REG_FPGA0_XCD_RF_SW_CTRL, REG_CONFIG_ANT_A, REG_CONFIG_ANT_B,
REG_FPGA0_XAB_RF_SW_CTRL, REG_FPGA0_XA_RF_INT_OE,
REG_FPGA0_XB_RF_INT_OE, REG_CCK0_AFE_SETTING
};
u8 xa_agc = rtl8xxxu_read32(priv, REG_OFDM0_XA_AGC_CORE1) & 0xff;
u8 xb_agc = rtl8xxxu_read32(priv, REG_OFDM0_XB_AGC_CORE1) & 0xff;
if (t == 0) {
rtl8xxxu_save_regs(priv, adda_regs, priv->adda_backup,
RTL8XXXU_ADDA_REGS);
rtl8xxxu_save_mac_regs(priv, iqk_mac_regs, priv->mac_backup);
rtl8xxxu_save_regs(priv, iqk_bb_regs,
priv->bb_backup, RTL8XXXU_BB_REGS);
}
rtl8xxxu_path_adda_on(priv, adda_regs, true);
rtl8xxxu_mac_calibration(priv, iqk_mac_regs, priv->mac_backup);
val32 = rtl8xxxu_read32(priv, REG_CCK0_AFE_SETTING);
val32 |= 0x0f000000;
rtl8xxxu_write32(priv, REG_CCK0_AFE_SETTING, val32);
rtl8xxxu_write32(priv, REG_OFDM0_TRX_PATH_ENABLE, 0x03a05600);
rtl8xxxu_write32(priv, REG_OFDM0_TR_MUX_PAR, 0x000800e4);
rtl8xxxu_write32(priv, REG_FPGA0_XCD_RF_SW_CTRL, 0x22208200);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XAB_RF_SW_CTRL);
val32 |= (FPGA0_RF_PAPE | (FPGA0_RF_PAPE << FPGA0_RF_BD_CTRL_SHIFT));
rtl8xxxu_write32(priv, REG_FPGA0_XAB_RF_SW_CTRL, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XA_RF_INT_OE);
val32 |= BIT(10);
rtl8xxxu_write32(priv, REG_FPGA0_XA_RF_INT_OE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XB_RF_INT_OE);
val32 |= BIT(10);
rtl8xxxu_write32(priv, REG_FPGA0_XB_RF_INT_OE, val32);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
for (i = 0; i < retry; i++) {
path_a_ok = rtl8192eu_iqk_path_a(priv);
if (path_a_ok == 0x01) {
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_BEFORE_IQK_A);
result[t][0] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_AFTER_IQK_A);
result[t][1] = (val32 >> 16) & 0x3ff;
break;
}
}
if (!path_a_ok)
dev_dbg(dev, "%s: Path A TX IQK failed!\n", __func__);
for (i = 0; i < retry; i++) {
path_a_ok = rtl8192eu_rx_iqk_path_a(priv);
if (path_a_ok == 0x03) {
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_BEFORE_IQK_A_2);
result[t][2] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_AFTER_IQK_A_2);
result[t][3] = (val32 >> 16) & 0x3ff;
break;
}
}
if (!path_a_ok)
dev_dbg(dev, "%s: Path A RX IQK failed!\n", __func__);
if (priv->rf_paths > 1) {
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC, 0x10000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_path_adda_on(priv, adda_regs, false);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
for (i = 0; i < retry; i++) {
path_b_ok = rtl8192eu_iqk_path_b(priv);
if (path_b_ok == 0x01) {
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
result[t][4] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
result[t][5] = (val32 >> 16) & 0x3ff;
break;
}
}
if (!path_b_ok)
dev_dbg(dev, "%s: Path B IQK failed!\n", __func__);
for (i = 0; i < retry; i++) {
path_b_ok = rtl8192eu_rx_iqk_path_b(priv);
if (path_b_ok == 0x03) {
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_BEFORE_IQK_B_2);
result[t][6] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_AFTER_IQK_B_2);
result[t][7] = (val32 >> 16) & 0x3ff;
break;
}
}
if (!path_b_ok)
dev_dbg(dev, "%s: Path B RX IQK failed!\n", __func__);
}
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x00000000);
if (t) {
rtl8xxxu_restore_regs(priv, adda_regs, priv->adda_backup,
RTL8XXXU_ADDA_REGS);
rtl8xxxu_restore_mac_regs(priv, iqk_mac_regs, priv->mac_backup);
rtl8xxxu_restore_regs(priv, iqk_bb_regs,
priv->bb_backup, RTL8XXXU_BB_REGS);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_AGC_CORE1);
val32 &= 0xffffff00;
rtl8xxxu_write32(priv, REG_OFDM0_XA_AGC_CORE1, val32 | 0x50);
rtl8xxxu_write32(priv, REG_OFDM0_XA_AGC_CORE1, val32 | xa_agc);
if (priv->rf_paths > 1) {
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_AGC_CORE1);
val32 &= 0xffffff00;
rtl8xxxu_write32(priv, REG_OFDM0_XB_AGC_CORE1,
val32 | 0x50);
rtl8xxxu_write32(priv, REG_OFDM0_XB_AGC_CORE1,
val32 | xb_agc);
}
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x01008c00);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x01008c00);
}
}
static void rtl8192eu_phy_iq_calibrate(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
int result[4][8];
int i, candidate;
bool path_a_ok, path_b_ok;
u32 reg_e94, reg_e9c, reg_ea4, reg_eac;
u32 reg_eb4, reg_ebc, reg_ec4, reg_ecc;
bool simu;
memset(result, 0, sizeof(result));
candidate = -1;
path_a_ok = false;
path_b_ok = false;
for (i = 0; i < 3; i++) {
rtl8192eu_phy_iqcalibrate(priv, result, i);
if (i == 1) {
simu = rtl8xxxu_gen2_simularity_compare(priv,
result, 0, 1);
if (simu) {
candidate = 0;
break;
}
}
if (i == 2) {
simu = rtl8xxxu_gen2_simularity_compare(priv,
result, 0, 2);
if (simu) {
candidate = 0;
break;
}
simu = rtl8xxxu_gen2_simularity_compare(priv,
result, 1, 2);
if (simu)
candidate = 1;
else
candidate = 3;
}
}
for (i = 0; i < 4; i++) {
reg_e94 = result[i][0];
reg_e9c = result[i][1];
reg_ea4 = result[i][2];
reg_eac = result[i][3];
reg_eb4 = result[i][4];
reg_ebc = result[i][5];
reg_ec4 = result[i][6];
reg_ecc = result[i][7];
}
if (candidate >= 0) {
reg_e94 = result[candidate][0];
priv->rege94 = reg_e94;
reg_e9c = result[candidate][1];
priv->rege9c = reg_e9c;
reg_ea4 = result[candidate][2];
reg_eac = result[candidate][3];
reg_eb4 = result[candidate][4];
priv->regeb4 = reg_eb4;
reg_ebc = result[candidate][5];
priv->regebc = reg_ebc;
reg_ec4 = result[candidate][6];
reg_ecc = result[candidate][7];
dev_dbg(dev, "%s: candidate is %x\n", __func__, candidate);
dev_dbg(dev,
"%s: e94 =%x e9c=%x ea4=%x eac=%x eb4=%x ebc=%x ec4=%x "
"ecc=%x\n ", __func__, reg_e94, reg_e9c,
reg_ea4, reg_eac, reg_eb4, reg_ebc, reg_ec4, reg_ecc);
path_a_ok = true;
path_b_ok = true;
} else {
reg_e94 = reg_eb4 = priv->rege94 = priv->regeb4 = 0x100;
reg_e9c = reg_ebc = priv->rege9c = priv->regebc = 0x0;
}
if (reg_e94 && candidate >= 0)
rtl8xxxu_fill_iqk_matrix_a(priv, path_a_ok, result,
candidate, (reg_ea4 == 0));
if (priv->rf_paths > 1)
rtl8xxxu_fill_iqk_matrix_b(priv, path_b_ok, result,
candidate, (reg_ec4 == 0));
rtl8xxxu_save_regs(priv, rtl8xxxu_iqk_phy_iq_bb_reg,
priv->bb_recovery_backup, RTL8XXXU_BB_REGS);
}
static void rtl8192e_crystal_afe_adjust(struct rtl8xxxu_priv *priv)
{
u8 val8;
u32 val32;
val8 = rtl8xxxu_read8(priv, REG_AFE_PLL_CTRL);
val8 &= 0xfb;
rtl8xxxu_write8(priv, REG_AFE_PLL_CTRL, val8);
val32 = rtl8xxxu_read32(priv, REG_AFE_CTRL4);
val32 &= 0xfffffc7f;
rtl8xxxu_write32(priv, REG_AFE_CTRL4, val32);
val8 = rtl8xxxu_read8(priv, REG_AFE_PLL_CTRL);
val8 &= 0xbf;
rtl8xxxu_write8(priv, REG_AFE_PLL_CTRL, val8);
val32 = rtl8xxxu_read32(priv, REG_AFE_CTRL4);
val32 &= 0xffdfffff;
rtl8xxxu_write32(priv, REG_AFE_CTRL4, val32);
}
static void rtl8192e_disabled_to_emu(struct rtl8xxxu_priv *priv)
{
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~(BIT(3) | BIT(4));
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
}
static int rtl8192e_emu_to_active(struct rtl8xxxu_priv *priv)
{
u8 val8;
u32 val32;
int count, ret = 0;
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~BIT(7);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~BIT(2);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~(BIT(3) | BIT(4));
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
exit:
return ret;
}
static int rtl8192eu_power_on(struct rtl8xxxu_priv *priv)
{
u16 val16;
u32 val32;
int ret;
ret = 0;
val32 = rtl8xxxu_read32(priv, REG_SYS_CFG);
if (val32 & SYS_CFG_SPS_LDO_SEL) {
rtl8xxxu_write8(priv, REG_LDO_SW_CTRL, 0xc3);
} else {
val32 = rtl8xxxu_read32(priv, REG_8192E_LDOV12_CTRL);
val32 &= 0xff0fffff;
val32 |= 0x00500000;
rtl8xxxu_write32(priv, REG_8192E_LDOV12_CTRL, val32);
rtl8xxxu_write8(priv, REG_LDO_SW_CTRL, 0x83);
}
rtl8192e_crystal_afe_adjust(priv);
rtl8192e_disabled_to_emu(priv);
ret = rtl8192e_emu_to_active(priv);
if (ret)
goto exit;
rtl8xxxu_write16(priv, REG_CR, 0x0000);
val16 = rtl8xxxu_read16(priv, REG_CR);
val16 |= (CR_HCI_TXDMA_ENABLE | CR_HCI_RXDMA_ENABLE |
CR_TXDMA_ENABLE | CR_RXDMA_ENABLE |
CR_PROTOCOL_ENABLE | CR_SCHEDULE_ENABLE |
CR_MAC_TX_ENABLE | CR_MAC_RX_ENABLE |
CR_SECURITY_ENABLE | CR_CALTIMER_ENABLE);
rtl8xxxu_write16(priv, REG_CR, val16);
exit:
return ret;
}
static void rtl8192e_enable_rf(struct rtl8xxxu_priv *priv)
{
u32 val32;
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_GPIO_MUXCFG);
val8 |= BIT(5);
rtl8xxxu_write8(priv, REG_GPIO_MUXCFG, val8);
rtl8xxxu_write8(priv, REG_WLAN_ACT_CONTROL_8723B, 0x04);
val32 = rtl8xxxu_read32(priv, REG_PWR_DATA);
val32 |= PWR_DATA_EEPRPAD_RFE_CTRL_EN;
rtl8xxxu_write32(priv, REG_PWR_DATA, val32);
val32 = rtl8xxxu_read32(priv, REG_RFE_BUFFER);
val32 |= (BIT(0) | BIT(1));
rtl8xxxu_write32(priv, REG_RFE_BUFFER, val32);
rtl8xxxu_write8(priv, REG_RFE_CTRL_ANTA_SRC, 0x77);
val32 = rtl8xxxu_read32(priv, REG_LEDCFG0);
val32 &= ~BIT(24);
val32 |= BIT(23);
rtl8xxxu_write32(priv, REG_LEDCFG0, val32);
val8 = rtl8xxxu_read8(priv, REG_PAD_CTRL1);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_PAD_CTRL1, val8);
}
