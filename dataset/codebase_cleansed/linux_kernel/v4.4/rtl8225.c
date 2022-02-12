static void rtl8225_write(struct ieee80211_hw *dev, u8 addr, u16 data)
{
struct rtl8180_priv *priv = dev->priv;
u16 reg80, reg84, reg82;
u32 bangdata;
int i;
bangdata = (data << 4) | (addr & 0xf);
reg80 = rtl818x_ioread16(priv, &priv->map->RFPinsOutput) & 0xfff3;
reg82 = rtl818x_ioread16(priv, &priv->map->RFPinsEnable);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82 | 0x7);
reg84 = rtl818x_ioread16(priv, &priv->map->RFPinsSelect);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x7 | 0x400);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(10);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(10);
for (i = 15; i >= 0; i--) {
u16 reg = reg80;
if (bangdata & (1 << i))
reg |= 1;
if (i & 1)
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg | (1 << 1));
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg | (1 << 1));
if (!(i & 1))
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
}
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(10);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x400);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
}
static u16 rtl8225_read(struct ieee80211_hw *dev, u8 addr)
{
struct rtl8180_priv *priv = dev->priv;
u16 reg80, reg82, reg84, out;
int i;
reg80 = rtl818x_ioread16(priv, &priv->map->RFPinsOutput);
reg82 = rtl818x_ioread16(priv, &priv->map->RFPinsEnable);
reg84 = rtl818x_ioread16(priv, &priv->map->RFPinsSelect) | 0x400;
reg80 &= ~0xF;
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82 | 0x000F);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84 | 0x000F);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80 | (1 << 2));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(4);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg80);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(5);
for (i = 4; i >= 0; i--) {
u16 reg = reg80 | ((addr >> i) & 1);
if (!(i & 1)) {
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(1);
}
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
if (i & 1) {
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, reg);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(1);
}
}
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x000E);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x040E);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3) | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
out = 0;
for (i = 11; i >= 0; i--) {
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(1);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3) | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3) | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3) | (1 << 1));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
if (rtl818x_ioread16(priv, &priv->map->RFPinsInput) & (1 << 1))
out |= 1 << i;
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
}
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput,
reg80 | (1 << 3) | (1 << 2));
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
udelay(2);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, reg82);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, reg84);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x03A0);
return out;
}
static void rtl8225_rf_set_tx_power(struct ieee80211_hw *dev, int channel)
{
struct rtl8180_priv *priv = dev->priv;
u8 cck_power, ofdm_power;
const u8 *tmp;
u32 reg;
int i;
cck_power = priv->channels[channel - 1].hw_value & 0xFF;
ofdm_power = priv->channels[channel - 1].hw_value >> 8;
cck_power = min(cck_power, (u8)35);
ofdm_power = min(ofdm_power, (u8)35);
rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK,
rtl8225_tx_gain_cck_ofdm[cck_power / 6] >> 1);
if (channel == 14)
tmp = &rtl8225_tx_power_cck_ch14[(cck_power % 6) * 8];
else
tmp = &rtl8225_tx_power_cck[(cck_power % 6) * 8];
for (i = 0; i < 8; i++)
rtl8225_write_phy_cck(dev, 0x44 + i, *tmp++);
msleep(1);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG3);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg | RTL818X_CONFIG3_ANAPARAM_WRITE);
rtl818x_iowrite32(priv, &priv->map->ANAPARAM2, RTL8225_ANAPARAM2_ON);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg & ~RTL818X_CONFIG3_ANAPARAM_WRITE);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM,
rtl8225_tx_gain_cck_ofdm[ofdm_power/6] >> 1);
tmp = &rtl8225_tx_power_ofdm[ofdm_power % 6];
rtl8225_write_phy_ofdm(dev, 5, *tmp);
rtl8225_write_phy_ofdm(dev, 7, *tmp);
msleep(1);
}
static void rtl8225_rf_init(struct ieee80211_hw *dev)
{
struct rtl8180_priv *priv = dev->priv;
int i;
rtl8180_set_anaparam(priv, RTL8225_ANAPARAM_ON);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x0480);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x0488);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
msleep(200);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0xFF & ~(1 << 6));
rtl818x_iowrite32(priv, &priv->map->RF_TIMING, 0x000a8008);
rtl818x_ioread16(priv, &priv->map->BRSR);
rtl818x_iowrite16(priv, &priv->map->BRSR, 0xFFFF);
rtl818x_iowrite32(priv, &priv->map->RF_PARA, 0x00100044);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, 0x44);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
rtl8225_write(dev, 0x0, 0x067);
rtl8225_write(dev, 0x1, 0xFE0);
rtl8225_write(dev, 0x2, 0x44D);
rtl8225_write(dev, 0x3, 0x441);
rtl8225_write(dev, 0x4, 0x8BE);
rtl8225_write(dev, 0x5, 0xBF0);
rtl8225_write(dev, 0x6, 0xAE6);
rtl8225_write(dev, 0x7, rtl8225_chan[0]);
rtl8225_write(dev, 0x8, 0x01F);
rtl8225_write(dev, 0x9, 0x334);
rtl8225_write(dev, 0xA, 0xFD4);
rtl8225_write(dev, 0xB, 0x391);
rtl8225_write(dev, 0xC, 0x050);
rtl8225_write(dev, 0xD, 0x6DB);
rtl8225_write(dev, 0xE, 0x029);
rtl8225_write(dev, 0xF, 0x914); msleep(1);
rtl8225_write(dev, 0x2, 0xC4D); msleep(100);
rtl8225_write(dev, 0x0, 0x127);
for (i = 0; i < ARRAY_SIZE(rtl8225bcd_rxgain); i++) {
rtl8225_write(dev, 0x1, i + 1);
rtl8225_write(dev, 0x2, rtl8225bcd_rxgain[i]);
}
rtl8225_write(dev, 0x0, 0x027);
rtl8225_write(dev, 0x0, 0x22F);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
for (i = 0; i < ARRAY_SIZE(rtl8225_agc); i++) {
rtl8225_write_phy_ofdm(dev, 0xB, rtl8225_agc[i]);
msleep(1);
rtl8225_write_phy_ofdm(dev, 0xA, 0x80 + i);
msleep(1);
}
msleep(1);
rtl8225_write_phy_ofdm(dev, 0x00, 0x01); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x01, 0x02); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x02, 0x62); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x03, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x04, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x05, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x06, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x07, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x08, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x09, 0xfe); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0a, 0x09); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0b, 0x80); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0c, 0x01); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0e, 0xd3); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0f, 0x38); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x10, 0x84); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x11, 0x03); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x12, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x13, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x14, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x15, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x16, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x17, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x18, 0xef); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x19, 0x19); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1a, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1b, 0x76); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1c, 0x04); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1e, 0x95); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1f, 0x75); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x20, 0x1f); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x21, 0x27); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x22, 0x16); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x24, 0x46); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x25, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x26, 0x90); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x27, 0x88); msleep(1);
rtl8225_write_phy_cck(dev, 0x00, 0x98); msleep(1);
rtl8225_write_phy_cck(dev, 0x03, 0x20); msleep(1);
rtl8225_write_phy_cck(dev, 0x04, 0x7e); msleep(1);
rtl8225_write_phy_cck(dev, 0x05, 0x12); msleep(1);
rtl8225_write_phy_cck(dev, 0x06, 0xfc); msleep(1);
rtl8225_write_phy_cck(dev, 0x07, 0x78); msleep(1);
rtl8225_write_phy_cck(dev, 0x08, 0x2e); msleep(1);
rtl8225_write_phy_cck(dev, 0x10, 0x93); msleep(1);
rtl8225_write_phy_cck(dev, 0x11, 0x88); msleep(1);
rtl8225_write_phy_cck(dev, 0x12, 0x47); msleep(1);
rtl8225_write_phy_cck(dev, 0x13, 0xd0);
rtl8225_write_phy_cck(dev, 0x19, 0x00);
rtl8225_write_phy_cck(dev, 0x1a, 0xa0);
rtl8225_write_phy_cck(dev, 0x1b, 0x08);
rtl8225_write_phy_cck(dev, 0x40, 0x86);
rtl8225_write_phy_cck(dev, 0x41, 0x8d); msleep(1);
rtl8225_write_phy_cck(dev, 0x42, 0x15); msleep(1);
rtl8225_write_phy_cck(dev, 0x43, 0x18); msleep(1);
rtl8225_write_phy_cck(dev, 0x44, 0x1f); msleep(1);
rtl8225_write_phy_cck(dev, 0x45, 0x1e); msleep(1);
rtl8225_write_phy_cck(dev, 0x46, 0x1a); msleep(1);
rtl8225_write_phy_cck(dev, 0x47, 0x15); msleep(1);
rtl8225_write_phy_cck(dev, 0x48, 0x10); msleep(1);
rtl8225_write_phy_cck(dev, 0x49, 0x0a); msleep(1);
rtl8225_write_phy_cck(dev, 0x4a, 0x05); msleep(1);
rtl8225_write_phy_cck(dev, 0x4b, 0x02); msleep(1);
rtl8225_write_phy_cck(dev, 0x4c, 0x05); msleep(1);
rtl818x_iowrite8(priv, &priv->map->TESTR, 0x0D); msleep(1);
rtl8225_rf_set_tx_power(dev, 1);
rtl8225_write_phy_cck(dev, 0x10, 0x9b); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x26, 0x90); msleep(1);
rtl818x_iowrite8(priv, &priv->map->TX_ANTENNA, 0x03);
msleep(1);
rtl818x_iowrite32(priv, (__le32 __iomem *)((void __iomem *)priv->map + 0x94), 0x15c00002);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
rtl8225_write(dev, 0x0c, 0x50);
rtl8225_write_phy_ofdm(dev, 0x0d, rtl8225_gain[4 * 4]);
rtl8225_write_phy_ofdm(dev, 0x23, rtl8225_gain[4 * 4 + 1]);
rtl8225_write_phy_ofdm(dev, 0x1b, rtl8225_gain[4 * 4 + 2]);
rtl8225_write_phy_ofdm(dev, 0x1d, rtl8225_gain[4 * 4 + 3]);
rtl8225_write_phy_cck(dev, 0x41, rtl8225_threshold[0]);
}
static void rtl8225z2_rf_set_tx_power(struct ieee80211_hw *dev, int channel)
{
struct rtl8180_priv *priv = dev->priv;
u8 cck_power, ofdm_power;
const u8 *tmp;
int i;
cck_power = priv->channels[channel - 1].hw_value & 0xFF;
ofdm_power = priv->channels[channel - 1].hw_value >> 8;
if (channel == 14)
tmp = rtl8225z2_tx_power_cck_ch14;
else if (cck_power == 12)
tmp = rtl8225z2_tx_power_cck_B;
else if (cck_power == 13)
tmp = rtl8225z2_tx_power_cck_A;
else
tmp = rtl8225z2_tx_power_cck;
for (i = 0; i < 8; i++)
rtl8225_write_phy_cck(dev, 0x44 + i, *tmp++);
cck_power = min(cck_power, (u8)35);
if (cck_power == 13 || cck_power == 14)
cck_power = 12;
if (cck_power >= 15)
cck_power -= 2;
rtl818x_iowrite8(priv, &priv->map->TX_GAIN_CCK, cck_power);
rtl818x_ioread8(priv, &priv->map->TX_GAIN_CCK);
msleep(1);
ofdm_power = min(ofdm_power, (u8)35);
rtl818x_iowrite8(priv, &priv->map->TX_GAIN_OFDM, ofdm_power);
rtl8225_write_phy_ofdm(dev, 2, 0x62);
rtl8225_write_phy_ofdm(dev, 5, 0x00);
rtl8225_write_phy_ofdm(dev, 6, 0x40);
rtl8225_write_phy_ofdm(dev, 7, 0x00);
rtl8225_write_phy_ofdm(dev, 8, 0x40);
msleep(1);
}
static void rtl8225z2_rf_init(struct ieee80211_hw *dev)
{
struct rtl8180_priv *priv = dev->priv;
int i;
rtl8180_set_anaparam(priv, RTL8225_ANAPARAM_ON);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x0480);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x0488);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
msleep(200);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0xFF & ~(1 << 6));
rtl818x_iowrite32(priv, &priv->map->RF_TIMING, 0x00088008);
rtl818x_ioread16(priv, &priv->map->BRSR);
rtl818x_iowrite16(priv, &priv->map->BRSR, 0xFFFF);
rtl818x_iowrite32(priv, &priv->map->RF_PARA, 0x00100044);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, 0x44);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
rtl8225_write(dev, 0x0, 0x0B7); msleep(1);
rtl8225_write(dev, 0x1, 0xEE0); msleep(1);
rtl8225_write(dev, 0x2, 0x44D); msleep(1);
rtl8225_write(dev, 0x3, 0x441); msleep(1);
rtl8225_write(dev, 0x4, 0x8C3); msleep(1);
rtl8225_write(dev, 0x5, 0xC72); msleep(1);
rtl8225_write(dev, 0x6, 0x0E6); msleep(1);
rtl8225_write(dev, 0x7, 0x82A); msleep(1);
rtl8225_write(dev, 0x8, 0x03F); msleep(1);
rtl8225_write(dev, 0x9, 0x335); msleep(1);
rtl8225_write(dev, 0xa, 0x9D4); msleep(1);
rtl8225_write(dev, 0xb, 0x7BB); msleep(1);
rtl8225_write(dev, 0xc, 0x850); msleep(1);
rtl8225_write(dev, 0xd, 0xCDF); msleep(1);
rtl8225_write(dev, 0xe, 0x02B); msleep(1);
rtl8225_write(dev, 0xf, 0x114); msleep(100);
if (!(rtl8225_read(dev, 6) & (1 << 7))) {
rtl8225_write(dev, 0x02, 0x0C4D);
msleep(200);
rtl8225_write(dev, 0x02, 0x044D);
msleep(100);
}
rtl8225_write(dev, 0x0, 0x1B7);
rtl8225_write(dev, 0x3, 0x002);
rtl8225_write(dev, 0x5, 0x004);
for (i = 0; i < ARRAY_SIZE(rtl8225z2_rxgain); i++) {
rtl8225_write(dev, 0x1, i + 1);
rtl8225_write(dev, 0x2, rtl8225z2_rxgain[i]);
}
rtl8225_write(dev, 0x0, 0x0B7); msleep(100);
rtl8225_write(dev, 0x2, 0xC4D);
msleep(200);
rtl8225_write(dev, 0x2, 0x44D);
msleep(100);
rtl8225_write(dev, 0x00, 0x2BF);
rtl8225_write(dev, 0xFF, 0xFFFF);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
for (i = 0; i < ARRAY_SIZE(rtl8225_agc); i++) {
rtl8225_write_phy_ofdm(dev, 0xB, rtl8225_agc[i]);
msleep(1);
rtl8225_write_phy_ofdm(dev, 0xA, 0x80 + i);
msleep(1);
}
msleep(1);
rtl8225_write_phy_ofdm(dev, 0x00, 0x01); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x01, 0x02); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x02, 0x62); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x03, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x04, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x05, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x06, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x07, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x08, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x09, 0xfe); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0a, 0x09); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x18, 0xef); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0b, 0x80); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0c, 0x01); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0d, 0x43);
rtl8225_write_phy_ofdm(dev, 0x0e, 0xd3); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x0f, 0x38); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x10, 0x84); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x11, 0x06); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x12, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x13, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x14, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x15, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x16, 0x00); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x17, 0x40); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x18, 0xef); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x19, 0x19); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1a, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1b, 0x11); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1c, 0x04); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1d, 0xc5); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1e, 0xb3); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x1f, 0x75); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x20, 0x1f); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x21, 0x27); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x22, 0x16); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x23, 0x80); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x24, 0x46); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x25, 0x20); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x26, 0x90); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x27, 0x88); msleep(1);
rtl8225_write_phy_cck(dev, 0x00, 0x98); msleep(1);
rtl8225_write_phy_cck(dev, 0x03, 0x20); msleep(1);
rtl8225_write_phy_cck(dev, 0x04, 0x7e); msleep(1);
rtl8225_write_phy_cck(dev, 0x05, 0x12); msleep(1);
rtl8225_write_phy_cck(dev, 0x06, 0xfc); msleep(1);
rtl8225_write_phy_cck(dev, 0x07, 0x78); msleep(1);
rtl8225_write_phy_cck(dev, 0x08, 0x2e); msleep(1);
rtl8225_write_phy_cck(dev, 0x10, 0x93); msleep(1);
rtl8225_write_phy_cck(dev, 0x11, 0x88); msleep(1);
rtl8225_write_phy_cck(dev, 0x12, 0x47); msleep(1);
rtl8225_write_phy_cck(dev, 0x13, 0xd0);
rtl8225_write_phy_cck(dev, 0x19, 0x00);
rtl8225_write_phy_cck(dev, 0x1a, 0xa0);
rtl8225_write_phy_cck(dev, 0x1b, 0x08);
rtl8225_write_phy_cck(dev, 0x40, 0x86);
rtl8225_write_phy_cck(dev, 0x41, 0x8a); msleep(1);
rtl8225_write_phy_cck(dev, 0x42, 0x15); msleep(1);
rtl8225_write_phy_cck(dev, 0x43, 0x18); msleep(1);
rtl8225_write_phy_cck(dev, 0x44, 0x36); msleep(1);
rtl8225_write_phy_cck(dev, 0x45, 0x35); msleep(1);
rtl8225_write_phy_cck(dev, 0x46, 0x2e); msleep(1);
rtl8225_write_phy_cck(dev, 0x47, 0x25); msleep(1);
rtl8225_write_phy_cck(dev, 0x48, 0x1c); msleep(1);
rtl8225_write_phy_cck(dev, 0x49, 0x12); msleep(1);
rtl8225_write_phy_cck(dev, 0x4a, 0x09); msleep(1);
rtl8225_write_phy_cck(dev, 0x4b, 0x04); msleep(1);
rtl8225_write_phy_cck(dev, 0x4c, 0x05); msleep(1);
rtl818x_iowrite8(priv, (u8 __iomem *)((void __iomem *)priv->map + 0x5B), 0x0D); msleep(1);
rtl8225z2_rf_set_tx_power(dev, 1);
rtl8225_write_phy_cck(dev, 0x10, 0x9b); msleep(1);
rtl8225_write_phy_ofdm(dev, 0x26, 0x90); msleep(1);
rtl818x_iowrite8(priv, &priv->map->TX_ANTENNA, 0x03);
msleep(1);
rtl818x_iowrite32(priv, (__le32 __iomem *)((void __iomem *)priv->map + 0x94), 0x15c00002);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
}
static void rtl8225_rf_stop(struct ieee80211_hw *dev)
{
struct rtl8180_priv *priv = dev->priv;
u8 reg;
rtl8225_write(dev, 0x4, 0x1f); msleep(1);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG3);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg | RTL818X_CONFIG3_ANAPARAM_WRITE);
rtl818x_iowrite32(priv, &priv->map->ANAPARAM2, RTL8225_ANAPARAM2_OFF);
rtl818x_iowrite32(priv, &priv->map->ANAPARAM, RTL8225_ANAPARAM_OFF);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg & ~RTL818X_CONFIG3_ANAPARAM_WRITE);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
}
static void rtl8225_rf_set_channel(struct ieee80211_hw *dev,
struct ieee80211_conf *conf)
{
struct rtl8180_priv *priv = dev->priv;
int chan =
ieee80211_frequency_to_channel(conf->chandef.chan->center_freq);
if (priv->rf->init == rtl8225_rf_init)
rtl8225_rf_set_tx_power(dev, chan);
else
rtl8225z2_rf_set_tx_power(dev, chan);
rtl8225_write(dev, 0x7, rtl8225_chan[chan - 1]);
msleep(10);
}
const struct rtl818x_rf_ops * rtl8180_detect_rf(struct ieee80211_hw *dev)
{
struct rtl8180_priv *priv = dev->priv;
u16 reg8, reg9;
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x0480);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x0488);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
msleep(100);
rtl8225_write(dev, 0, 0x1B7);
reg8 = rtl8225_read(dev, 8);
reg9 = rtl8225_read(dev, 9);
rtl8225_write(dev, 0, 0x0B7);
if (reg8 != 0x588 || reg9 != 0x700)
return &rtl8225_ops;
return &rtl8225z2_ops;
}
