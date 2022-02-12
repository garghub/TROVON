static void rtl8723bu_write_btreg(struct rtl8xxxu_priv *priv, u8 reg, u8 data)
{
struct h2c_cmd h2c;
int reqnum = 0;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.bt_mp_oper.cmd = H2C_8723B_BT_MP_OPER;
h2c.bt_mp_oper.operreq = 0 | (reqnum << 4);
h2c.bt_mp_oper.opcode = BT_MP_OP_WRITE_REG_VALUE;
h2c.bt_mp_oper.data = data;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.bt_mp_oper));
reqnum++;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.bt_mp_oper.cmd = H2C_8723B_BT_MP_OPER;
h2c.bt_mp_oper.operreq = 0 | (reqnum << 4);
h2c.bt_mp_oper.opcode = BT_MP_OP_WRITE_REG_VALUE;
h2c.bt_mp_oper.addr = reg;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.bt_mp_oper));
}
static void rtl8723bu_reset_8051(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 sys_func;
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL);
val8 &= ~BIT(1);
rtl8xxxu_write8(priv, REG_RSV_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
sys_func = rtl8xxxu_read16(priv, REG_SYS_FUNC);
sys_func &= ~SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, sys_func);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL);
val8 &= ~BIT(1);
rtl8xxxu_write8(priv, REG_RSV_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
sys_func |= SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, sys_func);
}
static void
rtl8723b_set_tx_power(struct rtl8xxxu_priv *priv, int channel, bool ht40)
{
u32 val32, ofdm, mcs;
u8 cck, ofdmbase, mcsbase;
int group, tx_idx;
tx_idx = 0;
group = rtl8xxxu_gen2_channel_to_group(channel);
cck = priv->cck_tx_power_index_B[group];
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_A_CCK1_MCS32);
val32 &= 0xffff00ff;
val32 |= (cck << 8);
rtl8xxxu_write32(priv, REG_TX_AGC_A_CCK1_MCS32, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11);
val32 &= 0xff;
val32 |= ((cck << 8) | (cck << 16) | (cck << 24));
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11, val32);
ofdmbase = priv->ht40_1s_tx_power_index_B[group];
ofdmbase += priv->ofdm_tx_power_diff[tx_idx].b;
ofdm = ofdmbase | ofdmbase << 8 | ofdmbase << 16 | ofdmbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE18_06, ofdm);
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE54_24, ofdm);
mcsbase = priv->ht40_1s_tx_power_index_B[group];
if (ht40)
mcsbase += priv->ht40_tx_power_diff[tx_idx++].b;
else
mcsbase += priv->ht20_tx_power_diff[tx_idx++].b;
mcs = mcsbase | mcsbase << 8 | mcsbase << 16 | mcsbase << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS03_MCS00, mcs);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS07_MCS04, mcs);
}
static int rtl8723bu_parse_efuse(struct rtl8xxxu_priv *priv)
{
struct rtl8723bu_efuse *efuse = &priv->efuse_wifi.efuse8723bu;
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
priv->ofdm_tx_power_diff[0].a =
efuse->tx_power_index_A.ht20_ofdm_1s_diff.a;
priv->ofdm_tx_power_diff[0].b =
efuse->tx_power_index_B.ht20_ofdm_1s_diff.a;
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
priv->xtalk = priv->efuse_wifi.efuse8723bu.xtal_k & 0x3f;
dev_info(&priv->udev->dev, "Vendor: %.7s\n", efuse->vendor_name);
dev_info(&priv->udev->dev, "Product: %.41s\n", efuse->device_name);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_EFUSE) {
int i;
unsigned char *raw = priv->efuse_wifi.raw;
dev_info(&priv->udev->dev,
"%s: dumping efuse (0x%02zx bytes):\n",
__func__, sizeof(struct rtl8723bu_efuse));
for (i = 0; i < sizeof(struct rtl8723bu_efuse); i += 8) {
dev_info(&priv->udev->dev, "%02x: "
"%02x %02x %02x %02x %02x %02x %02x %02x\n", i,
raw[i], raw[i + 1], raw[i + 2],
raw[i + 3], raw[i + 4], raw[i + 5],
raw[i + 6], raw[i + 7]);
}
}
return 0;
}
static int rtl8723bu_load_firmware(struct rtl8xxxu_priv *priv)
{
char *fw_name;
int ret;
if (priv->enable_bluetooth)
fw_name = "rtlwifi/rtl8723bu_bt.bin";
else
fw_name = "rtlwifi/rtl8723bu_nic.bin";
ret = rtl8xxxu_load_firmware(priv, fw_name);
return ret;
}
static void rtl8723bu_init_phy_bb(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= SYS_FUNC_BB_GLB_RSTN | SYS_FUNC_BBRSTB | SYS_FUNC_DIO_RF;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00);
val8 = RF_ENABLE | RF_RSTB | RF_SDMRSTB;
rtl8xxxu_write8(priv, REG_RF_CTRL, val8);
rtl8xxxu_write8(priv, REG_SYS_FUNC, 0xe3);
rtl8xxxu_write8(priv, REG_AFE_XTAL_CTRL + 1, 0x80);
rtl8xxxu_init_phy_regs(priv, rtl8723b_phy_1t_init_table);
rtl8xxxu_init_phy_regs(priv, rtl8xxx_agc_8723bu_table);
}
static int rtl8723bu_init_phy_rf(struct rtl8xxxu_priv *priv)
{
int ret;
ret = rtl8xxxu_init_phy_rf(priv, rtl8723bu_radioa_1t_init_table, RF_A);
rtl8xxxu_write_rfreg(priv, RF_A, 0xb0, 0xdfbe0);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_MODE_AG, 0x8c01);
msleep(200);
rtl8xxxu_write_rfreg(priv, RF_A, 0xb0, 0xdffe0);
return ret;
}
static void rtl8723bu_phy_init_antenna_selection(struct rtl8xxxu_priv *priv)
{
u32 val32;
val32 = rtl8xxxu_read32(priv, REG_PAD_CTRL1);
val32 &= ~(BIT(20) | BIT(24));
rtl8xxxu_write32(priv, REG_PAD_CTRL1, val32);
val32 = rtl8xxxu_read32(priv, REG_GPIO_MUXCFG);
val32 &= ~BIT(4);
rtl8xxxu_write32(priv, REG_GPIO_MUXCFG, val32);
val32 = rtl8xxxu_read32(priv, REG_GPIO_MUXCFG);
val32 |= BIT(3);
rtl8xxxu_write32(priv, REG_GPIO_MUXCFG, val32);
val32 = rtl8xxxu_read32(priv, REG_LEDCFG0);
val32 |= BIT(24);
rtl8xxxu_write32(priv, REG_LEDCFG0, val32);
val32 = rtl8xxxu_read32(priv, REG_LEDCFG0);
val32 &= ~BIT(23);
rtl8xxxu_write32(priv, REG_LEDCFG0, val32);
val32 = rtl8xxxu_read32(priv, REG_RFE_BUFFER);
val32 |= (BIT(0) | BIT(1));
rtl8xxxu_write32(priv, REG_RFE_BUFFER, val32);
val32 = rtl8xxxu_read32(priv, REG_RFE_CTRL_ANTA_SRC);
val32 &= 0xffffff00;
val32 |= 0x77;
rtl8xxxu_write32(priv, REG_RFE_CTRL_ANTA_SRC, val32);
val32 = rtl8xxxu_read32(priv, REG_PWR_DATA);
val32 |= PWR_DATA_EEPRPAD_RFE_CTRL_EN;
rtl8xxxu_write32(priv, REG_PWR_DATA, val32);
}
static int rtl8723bu_iqk_path_a(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_e94, reg_e9c, path_sel, val32;
int result = 0;
path_sel = rtl8xxxu_read32(priv, REG_S0S1_PATH_SWITCH);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_WE_LUT);
val32 |= 0x80000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x20000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0003f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xc7f87);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x821403ea);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x28110000);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x82110000);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x28110000);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x00462911);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
val32 |= 0x80800000;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
if (priv->rf_paths > 1)
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000000);
else
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000280);
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00000800);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf9000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(1);
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, path_sel);
#ifdef RTL8723BU_BT
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00001800);
#endif
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_e94 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_A);
reg_e9c = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_A);
val32 = (reg_e9c >> 16) & 0x3ff;
if (val32 & 0x200)
val32 = 0x400 - val32;
if (!(reg_eac & BIT(28)) &&
((reg_e94 & 0x03ff0000) != 0x01420000) &&
((reg_e9c & 0x03ff0000) != 0x00420000) &&
((reg_e94 & 0x03ff0000) < 0x01100000) &&
((reg_e94 & 0x03ff0000) > 0x00f00000) &&
val32 < 0xf)
result |= 0x01;
else
goto out;
out:
return result;
}
static int rtl8723bu_rx_iqk_path_a(struct rtl8xxxu_priv *priv)
{
u32 reg_ea4, reg_eac, reg_e94, reg_e9c, path_sel, val32;
int result = 0;
path_sel = rtl8xxxu_read32(priv, REG_S0S1_PATH_SWITCH);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_WE_LUT);
val32 |= 0x80000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0001f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xf7fb7);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82160ff0);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x28110000);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x82110000);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x28110000);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a911);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
val32 |= 0x80800000;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
if (priv->rf_paths > 1)
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000000);
else
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000280);
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00000800);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf9000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(1);
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, path_sel);
#ifdef RTL8723BU_BT
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00001800);
#endif
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_e94 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_A);
reg_e9c = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_A);
val32 = (reg_e9c >> 16) & 0x3ff;
if (val32 & 0x200)
val32 = 0x400 - val32;
if (!(reg_eac & BIT(28)) &&
((reg_e94 & 0x03ff0000) != 0x01420000) &&
((reg_e9c & 0x03ff0000) != 0x00420000) &&
((reg_e94 & 0x03ff0000) < 0x01100000) &&
((reg_e94 & 0x03ff0000) > 0x00f00000) &&
val32 < 0xf)
result |= 0x01;
else
goto out;
val32 = 0x80007c00 | (reg_e94 &0x3ff0000) |
((reg_e9c & 0x3ff0000) >> 16);
rtl8xxxu_write32(priv, REG_TX_IQK, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_WE_LUT);
val32 |= 0x80000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0001f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xf7d77);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0xf80);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_55, 0x4021f);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x18008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x38008c1c);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82110000);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, 0x2816001f);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x82110000);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x28110000);
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x0046a8d1);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
val32 |= 0x80800000;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
if (priv->rf_paths > 1)
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000000);
else
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00000280);
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00000800);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf9000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(1);
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, path_sel);
#ifdef RTL8723BU_BT
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, 0x00001800);
#endif
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_ea4 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_A_2);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_DF, 0x780);
val32 = (reg_eac >> 16) & 0x3ff;
if (val32 & 0x200)
val32 = 0x400 - val32;
if (!(reg_eac & BIT(27)) &&
((reg_ea4 & 0x03ff0000) != 0x01320000) &&
((reg_eac & 0x03ff0000) != 0x00360000) &&
((reg_ea4 & 0x03ff0000) < 0x01100000) &&
((reg_ea4 & 0x03ff0000) > 0x00f00000) &&
val32 < 0xf)
result |= 0x02;
else
goto out;
out:
return result;
}
static void rtl8723bu_phy_iqcalibrate(struct rtl8xxxu_priv *priv,
int result[][8], int t)
{
struct device *dev = &priv->udev->dev;
u32 i, val32;
int path_a_ok ;
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
REG_FPGA0_XB_RF_INT_OE, REG_FPGA0_RF_MODE
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
rtl8xxxu_write32(priv, REG_FPGA0_XCD_RF_SW_CTRL, 0x22204000);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_WE_LUT);
val32 |= 0x80000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x30000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0001f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xf7fb7);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_ED);
val32 |= 0x20;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_ED, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_43, 0x60fbd);
for (i = 0; i < retry; i++) {
path_a_ok = rtl8723bu_iqk_path_a(priv);
if (path_a_ok == 0x01) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
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
path_a_ok = rtl8723bu_rx_iqk_path_a(priv);
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
if (priv->tx_paths > 1) {
#if 1
dev_warn(dev, "%s: Path B not supported\n", __func__);
#else
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC, 0x10000);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
val32 |= 0x80800000;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
rtl8xxxu_path_adda_on(priv, adda_regs, false);
for (i = 0; i < retry; i++) {
path_b_ok = rtl8xxxu_iqk_path_b(priv);
if (path_b_ok == 0x03) {
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
path_b_ok = rtl8723bu_rx_iqk_path_b(priv);
if (path_a_ok == 0x03) {
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
#endif
}
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 &= 0x000000ff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
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
if (priv->tx_paths > 1) {
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
static void rtl8723bu_phy_iq_calibrate(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
int result[4][8];
int i, candidate;
bool path_a_ok, path_b_ok;
u32 reg_e94, reg_e9c, reg_ea4, reg_eac;
u32 reg_eb4, reg_ebc, reg_ec4, reg_ecc;
u32 val32, bt_control;
s32 reg_tmp = 0;
bool simu;
rtl8xxxu_gen2_prepare_calibrate(priv, 1);
memset(result, 0, sizeof(result));
candidate = -1;
path_a_ok = false;
path_b_ok = false;
bt_control = rtl8xxxu_read32(priv, REG_BT_CONTROL_8723BU);
for (i = 0; i < 3; i++) {
rtl8723bu_phy_iqcalibrate(priv, result, i);
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
if (simu) {
candidate = 1;
} else {
for (i = 0; i < 8; i++)
reg_tmp += result[3][i];
if (reg_tmp)
candidate = 3;
else
candidate = -1;
}
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
if (priv->tx_paths > 1 && reg_eb4)
rtl8xxxu_fill_iqk_matrix_b(priv, path_b_ok, result,
candidate, (reg_ec4 == 0));
rtl8xxxu_save_regs(priv, rtl8xxxu_iqk_phy_iq_bb_reg,
priv->bb_recovery_backup, RTL8XXXU_BB_REGS);
rtl8xxxu_write32(priv, REG_BT_CONTROL_8723BU, bt_control);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_WE_LUT);
val32 |= 0x80000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_WE_LUT, val32);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_RCK_OS, 0x18000);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G1, 0x0001f);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_TXPA_G2, 0xe6177);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_ED);
val32 |= 0x20;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_UNKNOWN_ED, val32);
rtl8xxxu_write_rfreg(priv, RF_A, 0x43, 0x300bd);
if (priv->rf_paths > 1)
dev_dbg(dev, "%s: 8723BU 2T not supported\n", __func__);
rtl8xxxu_gen2_prepare_calibrate(priv, 0);
}
static int rtl8723bu_active_to_emu(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
u32 val32;
int count, ret = 0;
rtl8xxxu_write8(priv, REG_RF_CTRL, 0);
val16 = rtl8xxxu_read16(priv, REG_GPIO_INTM);
val16 &= ~GPIO_INTM_EDGE_TRIG_IRQ;
rtl8xxxu_write16(priv, REG_GPIO_INTM, val16);
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
val32 |= APS_FSMCO_WLON_RESET;
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 |= BIT(1);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
for (count = RTL8XXXU_MAX_REG_POLL; count; count--) {
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
if ((val8 & BIT(1)) == 0)
break;
udelay(10);
}
if (!count) {
dev_warn(&priv->udev->dev, "%s: Disabling MAC timed out\n",
__func__);
ret = -EBUSY;
goto exit;
}
val8 = rtl8xxxu_read8(priv, REG_AFE_MISC);
val8 &= ~AFE_MISC_WL_XTAL_CTRL;
rtl8xxxu_write8(priv, REG_AFE_MISC, val8);
val8 = rtl8xxxu_read8(priv, REG_SYS_ISO_CTRL);
val8 |= SYS_ISO_ANALOG_IPS;
rtl8xxxu_write8(priv, REG_SYS_ISO_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_LDOA15_CTRL);
val8 &= ~LDOA15_ENABLE;
rtl8xxxu_write8(priv, REG_LDOA15_CTRL, val8);
exit:
return ret;
}
static int rtl8723b_emu_to_active(struct rtl8xxxu_priv *priv)
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
val32 = rtl8xxxu_read8(priv, REG_APS_FSMCO);
val32 &= ~APS_FSMCO_SW_LPS;
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
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
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
val32 |= APS_FSMCO_WLON_RESET;
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
val32 &= ~APS_FSMCO_HW_POWERDOWN;
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
val32 = rtl8xxxu_read32(priv, REG_APS_FSMCO);
val32 &= ~(APS_FSMCO_HW_SUSPEND | APS_FSMCO_PCIE);
rtl8xxxu_write32(priv, REG_APS_FSMCO, val32);
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
val8 = rtl8xxxu_read8(priv, REG_AFE_MISC);
val8 |= AFE_MISC_WL_XTAL_CTRL;
rtl8xxxu_write8(priv, REG_AFE_MISC, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_INTM + 1);
val8 |= BIT(1);
rtl8xxxu_write8(priv, REG_GPIO_INTM + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_IO_SEL_2 + 1);
val8 |= BIT(1);
rtl8xxxu_write8(priv, REG_GPIO_IO_SEL_2 + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_IO_SEL_2);
val8 &= ~BIT(1);
rtl8xxxu_write8(priv, REG_GPIO_IO_SEL_2, val8);
val8 = rtl8xxxu_read8(priv, REG_HSIMR);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_HSIMR, val8);
val8 = rtl8xxxu_read8(priv, REG_HSIMR + 2);
val8 |= BIT(1);
rtl8xxxu_write8(priv, REG_HSIMR + 2, val8);
val8 = rtl8xxxu_read8(priv, REG_MULTI_FUNC_CTRL);
val8 |= MULTI_WIFI_HW_ROF_EN;
rtl8xxxu_write8(priv, REG_MULTI_FUNC_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_MULTI_FUNC_CTRL + 1);
val8 |= BIT(6);
rtl8xxxu_write8(priv, REG_MULTI_FUNC_CTRL + 1, val8);
exit:
return ret;
}
static int rtl8723bu_power_on(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
u32 val32;
int ret;
rtl8xxxu_disabled_to_emu(priv);
ret = rtl8723b_emu_to_active(priv);
if (ret)
goto exit;
val16 = rtl8xxxu_read16(priv, REG_CR);
val16 |= (CR_HCI_TXDMA_ENABLE | CR_HCI_RXDMA_ENABLE |
CR_TXDMA_ENABLE | CR_RXDMA_ENABLE |
CR_PROTOCOL_ENABLE | CR_SCHEDULE_ENABLE |
CR_MAC_TX_ENABLE | CR_MAC_RX_ENABLE |
CR_SECURITY_ENABLE | CR_CALTIMER_ENABLE);
rtl8xxxu_write16(priv, REG_CR, val16);
rtl8xxxu_write8(priv, REG_PAD_CTRL1 + 3, 0x20);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= SYS_FUNC_BBRSTB | SYS_FUNC_BB_GLB_RSTN;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
rtl8xxxu_write8(priv, REG_BT_CONTROL_8723BU + 1, 0x18);
rtl8xxxu_write8(priv, REG_WLAN_ACT_CONTROL_8723B, 0x04);
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00);
rtl8xxxu_write8(priv, 0xfe08, 0x01);
val16 = rtl8xxxu_read16(priv, REG_PWR_DATA);
val16 |= PWR_DATA_EEPRPAD_RFE_CTRL_EN;
rtl8xxxu_write16(priv, REG_PWR_DATA, val16);
val32 = rtl8xxxu_read32(priv, REG_LEDCFG0);
val32 |= LEDCFG0_DPDT_SELECT;
rtl8xxxu_write32(priv, REG_LEDCFG0, val32);
val8 = rtl8xxxu_read8(priv, REG_PAD_CTRL1);
val8 &= ~PAD_CTRL1_SW_DPDT_SEL_DATA;
rtl8xxxu_write8(priv, REG_PAD_CTRL1, val8);
exit:
return ret;
}
static void rtl8723bu_power_off(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
rtl8xxxu_flush_fifo(priv);
val8 = rtl8xxxu_read8(priv, REG_TX_REPORT_CTRL);
val8 &= ~TX_REPORT_CTRL_TIMER_ENABLE;
rtl8xxxu_write8(priv, REG_TX_REPORT_CTRL, val8);
rtl8xxxu_write8(priv, REG_CR, 0x0000);
rtl8xxxu_active_to_lps(priv);
if (rtl8xxxu_read8(priv, REG_MCU_FW_DL) & MCU_FW_RAM_SEL)
rtl8xxxu_firmware_self_reset(priv);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 &= ~SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
rtl8xxxu_write8(priv, REG_MCU_FW_DL, 0x00);
rtl8723bu_active_to_emu(priv);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 |= BIT(3);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_INTM + 2);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_GPIO_INTM + 2, val8);
}
static void rtl8723b_enable_rf(struct rtl8xxxu_priv *priv)
{
struct h2c_cmd h2c;
u32 val32;
u8 val8;
rtl8xxxu_write8(priv, 0x0790, 0x05);
rtl8xxxu_write8(priv, 0x0778, 0x01);
val8 = rtl8xxxu_read8(priv, REG_GPIO_MUXCFG);
val8 |= BIT(5);
rtl8xxxu_write8(priv, REG_GPIO_MUXCFG, val8);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_IQADJ_G1, 0x780);
rtl8723bu_write_btreg(priv, 0x3c, 0x15);
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.bt_grant.cmd = H2C_8723B_BT_GRANT;
h2c.bt_grant.data = 0;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.bt_grant));
rtl8xxxu_write8(priv, REG_WLAN_ACT_CONTROL_8723B, 0x04);
val8 = rtl8xxxu_read8(priv, 0x0067);
val8 |= BIT(5);
rtl8xxxu_write8(priv, 0x0067, val8);
val32 = rtl8xxxu_read32(priv, REG_PWR_DATA);
val32 |= PWR_DATA_EEPRPAD_RFE_CTRL_EN;
rtl8xxxu_write32(priv, REG_PWR_DATA, val32);
rtl8xxxu_write8(priv, 0x0974, 0xff);
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
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.ant_sel_rsv.cmd = H2C_8723B_ANT_SEL_RSV;
h2c.ant_sel_rsv.ant_inverse = 1;
h2c.ant_sel_rsv.int_switch_type = 0;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.ant_sel_rsv));
rtl8xxxu_write32(priv, REG_S0S1_PATH_SWITCH, 0x00);
#ifdef NEED_PS_TDMA
rtl8723bu_set_ps_tdma(priv, 0x08, 0x00, 0x00, 0x00, 0x00);
#endif
rtl8xxxu_write32(priv, REG_BT_COEX_TABLE1, 0x55555555);
rtl8xxxu_write32(priv, REG_BT_COEX_TABLE2, 0x55555555);
rtl8xxxu_write32(priv, REG_BT_COEX_TABLE3, 0x00ffffff);
rtl8xxxu_write8(priv, REG_BT_COEX_TABLE4, 0x03);
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.bt_info.cmd = H2C_8723B_BT_INFO;
h2c.bt_info.data = BIT(0);
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.bt_info));
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.ignore_wlan.cmd = H2C_8723B_BT_IGNORE_WLANACT;
h2c.ignore_wlan.data = 0;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.ignore_wlan));
}
static void rtl8723bu_init_aggregation(struct rtl8xxxu_priv *priv)
{
u32 agg_rx;
u8 agg_ctrl;
agg_ctrl = rtl8xxxu_read8(priv, REG_TRXDMA_CTRL);
agg_ctrl &= ~TRXDMA_CTRL_RXDMA_AGG_EN;
agg_rx = rtl8xxxu_read32(priv, REG_RXDMA_AGG_PG_TH);
agg_rx &= ~RXDMA_USB_AGG_ENABLE;
agg_rx &= ~0xff0f;
rtl8xxxu_write8(priv, REG_TRXDMA_CTRL, agg_ctrl);
rtl8xxxu_write32(priv, REG_RXDMA_AGG_PG_TH, agg_rx);
}
static void rtl8723bu_init_statistics(struct rtl8xxxu_priv *priv)
{
u32 val32;
rtl8xxxu_write16(priv, REG_NHM_TIMER_8723B + 2, 0x2710);
rtl8xxxu_write16(priv, REG_NHM_TH9_TH10_8723B + 2, 0xffff);
rtl8xxxu_write32(priv, REG_NHM_TH3_TO_TH0_8723B, 0xffffff52);
rtl8xxxu_write32(priv, REG_NHM_TH7_TO_TH4_8723B, 0xffffffff);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_IQK);
val32 |= 0xff;
rtl8xxxu_write32(priv, REG_FPGA0_IQK, val32);
val32 = rtl8xxxu_read32(priv, REG_NHM_TH9_TH10_8723B);
val32 |= BIT(8) | BIT(9) | BIT(10);
rtl8xxxu_write32(priv, REG_NHM_TH9_TH10_8723B, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_FA_RSTC);
val32 |= BIT(7);
rtl8xxxu_write32(priv, REG_OFDM0_FA_RSTC, val32);
}
