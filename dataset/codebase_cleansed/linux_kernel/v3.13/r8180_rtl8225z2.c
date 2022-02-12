static void write_rtl8225(struct net_device *dev, u8 adr, u16 data)
{
int i;
u16 out, select;
u8 bit;
u32 bangdata = (data << 4) | (adr & 0xf);
out = read_nic_word(dev, RFPinsOutput) & 0xfff3;
write_nic_word(dev, RFPinsEnable,
(read_nic_word(dev, RFPinsEnable) | 0x7));
select = read_nic_word(dev, RFPinsSelect);
write_nic_word(dev, RFPinsSelect, select | 0x7 |
SW_CONTROL_GPIO);
force_pci_posting(dev);
udelay(10);
write_nic_word(dev, RFPinsOutput, out | BB_HOST_BANG_EN);
force_pci_posting(dev);
udelay(2);
write_nic_word(dev, RFPinsOutput, out);
force_pci_posting(dev);
udelay(10);
for (i = 15; i >= 0; i--) {
bit = (bangdata & (1 << i)) >> i;
write_nic_word(dev, RFPinsOutput, bit | out);
write_nic_word(dev, RFPinsOutput, bit | out | BB_HOST_BANG_CLK);
write_nic_word(dev, RFPinsOutput, bit | out | BB_HOST_BANG_CLK);
i--;
bit = (bangdata & (1 << i)) >> i;
write_nic_word(dev, RFPinsOutput, bit | out | BB_HOST_BANG_CLK);
write_nic_word(dev, RFPinsOutput, bit | out | BB_HOST_BANG_CLK);
write_nic_word(dev, RFPinsOutput, bit | out);
}
write_nic_word(dev, RFPinsOutput, out | BB_HOST_BANG_EN);
force_pci_posting(dev);
udelay(10);
write_nic_word(dev, RFPinsOutput, out | BB_HOST_BANG_EN);
write_nic_word(dev, RFPinsSelect, select | SW_CONTROL_GPIO);
rtl8185_rf_pins_enable(dev);
}
static void rtl8225z2_set_gain(struct net_device *dev, short gain)
{
const u8 *rtl8225_gain;
struct r8180_priv *priv = ieee80211_priv(dev);
u8 mode = priv->ieee80211->mode;
if (mode == IEEE_B || mode == IEEE_G)
rtl8225_gain = rtl8225z2_gain_bg;
else
rtl8225_gain = rtl8225z2_gain_a;
write_phy_ofdm(dev, 0x0b, rtl8225_gain[gain * 3]);
write_phy_ofdm(dev, 0x1b, rtl8225_gain[gain * 3 + 1]);
write_phy_ofdm(dev, 0x1d, rtl8225_gain[gain * 3 + 2]);
write_phy_ofdm(dev, 0x21, 0x37);
}
static u32 read_rtl8225(struct net_device *dev, u8 adr)
{
u32 data2Write = ((u32)(adr & 0x1f)) << 27;
u32 dataRead;
u32 mask;
u16 oval, oval2, oval3, tmp;
int i;
short bit, rw;
u8 wLength = 6;
u8 rLength = 12;
u8 low2high = 0;
oval = read_nic_word(dev, RFPinsOutput);
oval2 = read_nic_word(dev, RFPinsEnable);
oval3 = read_nic_word(dev, RFPinsSelect);
write_nic_word(dev, RFPinsEnable, (oval2|0xf));
write_nic_word(dev, RFPinsSelect, (oval3|0xf));
dataRead = 0;
oval &= ~0xf;
write_nic_word(dev, RFPinsOutput, oval | BB_HOST_BANG_EN);
udelay(4);
write_nic_word(dev, RFPinsOutput, oval);
udelay(5);
rw = 0;
mask = (low2high) ? 0x01 : (((u32)0x01)<<(32-1));
for (i = 0; i < wLength/2; i++) {
bit = ((data2Write&mask) != 0) ? 1 : 0;
write_nic_word(dev, RFPinsOutput, bit | oval | rw);
udelay(1);
write_nic_word(dev, RFPinsOutput,
bit | oval | BB_HOST_BANG_CLK | rw);
udelay(2);
write_nic_word(dev, RFPinsOutput,
bit | oval | BB_HOST_BANG_CLK | rw);
udelay(2);
mask = (low2high) ? (mask<<1) : (mask>>1);
if (i == 2) {
rw = BB_HOST_BANG_RW;
write_nic_word(dev, RFPinsOutput,
bit | oval | BB_HOST_BANG_CLK | rw);
udelay(2);
write_nic_word(dev, RFPinsOutput, bit | oval | rw);
udelay(2);
break;
}
bit = ((data2Write&mask) != 0) ? 1 : 0;
write_nic_word(dev, RFPinsOutput,
oval | bit | rw | BB_HOST_BANG_CLK);
udelay(2);
write_nic_word(dev, RFPinsOutput,
oval | bit | rw | BB_HOST_BANG_CLK);
udelay(2);
write_nic_word(dev, RFPinsOutput, oval | bit | rw);
udelay(1);
mask = (low2high) ? (mask<<1) : (mask>>1);
}
write_nic_word(dev, RFPinsOutput, rw|oval);
udelay(2);
mask = (low2high) ? 0x01 : (((u32)0x01) << (12-1));
write_nic_word(dev, RFPinsEnable, (oval2 & (~0x01)));
for (i = 0; i < rLength; i++) {
write_nic_word(dev, RFPinsOutput, rw|oval); udelay(1);
write_nic_word(dev, RFPinsOutput, rw|oval|BB_HOST_BANG_CLK);
udelay(2);
write_nic_word(dev, RFPinsOutput, rw|oval|BB_HOST_BANG_CLK);
udelay(2);
write_nic_word(dev, RFPinsOutput, rw|oval|BB_HOST_BANG_CLK);
udelay(2);
tmp = read_nic_word(dev, RFPinsInput);
dataRead |= (tmp & BB_HOST_BANG_CLK ? mask : 0);
write_nic_word(dev, RFPinsOutput, (rw|oval)); udelay(2);
mask = (low2high) ? (mask<<1) : (mask>>1);
}
write_nic_word(dev, RFPinsOutput,
BB_HOST_BANG_EN | BB_HOST_BANG_RW | oval);
udelay(2);
write_nic_word(dev, RFPinsEnable, oval2);
write_nic_word(dev, RFPinsSelect, oval3);
write_nic_word(dev, RFPinsOutput, 0x3a0);
return dataRead;
}
void rtl8225z2_rf_close(struct net_device *dev)
{
RF_WriteReg(dev, 0x4, 0x1f);
force_pci_posting(dev);
mdelay(1);
rtl8180_set_anaparam(dev, RTL8225z2_ANAPARAM_OFF);
rtl8185_set_anaparam2(dev, RTL8225z2_ANAPARAM2_OFF);
}
static s8 DbmToTxPwrIdx(struct r8180_priv *priv, WIRELESS_MODE WirelessMode,
s32 PowerInDbm)
{
bool bUseDefault = true;
s8 TxPwrIdx = 0;
s32 tmp = 0;
if (WirelessMode == WIRELESS_MODE_G) {
bUseDefault = false;
tmp = (2 * PowerInDbm);
if (tmp < 0)
TxPwrIdx = 0;
else if (tmp > 40)
TxPwrIdx = 40;
else
TxPwrIdx = (s8)tmp;
} else if (WirelessMode == WIRELESS_MODE_B) {
bUseDefault = false;
tmp = (4 * PowerInDbm) - 52;
if (tmp < 0)
TxPwrIdx = 0;
else if (tmp > 28)
TxPwrIdx = 28;
else
TxPwrIdx = (s8)tmp;
}
if (bUseDefault) {
if (PowerInDbm < 0)
TxPwrIdx = 0;
else if (PowerInDbm > 35)
TxPwrIdx = 35;
else
TxPwrIdx = (u8)PowerInDbm;
}
return TxPwrIdx;
}
void rtl8225z2_SetTXPowerLevel(struct net_device *dev, short ch)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u8 max_cck_power_level;
u8 max_ofdm_power_level;
u8 min_ofdm_power_level;
char cck_power_level = (char)(0xff & priv->chtxpwr[ch]);
char ofdm_power_level = (char)(0xff & priv->chtxpwr_ofdm[ch]);
if (IS_DOT11D_ENABLE(priv->ieee80211) &&
IS_DOT11D_STATE_DONE(priv->ieee80211)) {
u8 MaxTxPwrInDbm = DOT11D_GetMaxTxPwrInDbm(priv->ieee80211, ch);
u8 CckMaxPwrIdx = DbmToTxPwrIdx(priv, WIRELESS_MODE_B,
MaxTxPwrInDbm);
u8 OfdmMaxPwrIdx = DbmToTxPwrIdx(priv, WIRELESS_MODE_G,
MaxTxPwrInDbm);
if (cck_power_level > CckMaxPwrIdx)
cck_power_level = CckMaxPwrIdx;
if (ofdm_power_level > OfdmMaxPwrIdx)
ofdm_power_level = OfdmMaxPwrIdx;
}
max_cck_power_level = 15;
max_ofdm_power_level = 25;
min_ofdm_power_level = 10;
if (cck_power_level > 35)
cck_power_level = 35;
write_nic_byte(dev, CCK_TXAGC, cck_power_level);
force_pci_posting(dev);
mdelay(1);
if (ofdm_power_level > 35)
ofdm_power_level = 35;
if (priv->up == 0) {
write_phy_ofdm(dev, 2, 0x42);
write_phy_ofdm(dev, 5, 0x00);
write_phy_ofdm(dev, 6, 0x40);
write_phy_ofdm(dev, 7, 0x00);
write_phy_ofdm(dev, 8, 0x40);
}
write_nic_byte(dev, OFDM_TXAGC, ofdm_power_level);
if (ofdm_power_level <= 11) {
write_phy_ofdm(dev, 0x07, 0x5c);
write_phy_ofdm(dev, 0x09, 0x5c);
}
if (ofdm_power_level <= 17) {
write_phy_ofdm(dev, 0x07, 0x54);
write_phy_ofdm(dev, 0x09, 0x54);
} else {
write_phy_ofdm(dev, 0x07, 0x50);
write_phy_ofdm(dev, 0x09, 0x50);
}
force_pci_posting(dev);
mdelay(1);
}
void rtl8225z2_rf_set_chan(struct net_device *dev, short ch)
{
rtl8225z2_SetTXPowerLevel(dev, ch);
RF_WriteReg(dev, 0x7, rtl8225_chan[ch]);
if ((RF_ReadReg(dev, 0x7) & 0x0F80) != rtl8225_chan[ch])
RF_WriteReg(dev, 0x7, rtl8225_chan[ch]);
mdelay(1);
force_pci_posting(dev);
mdelay(10);
}
static void rtl8225_host_pci_init(struct net_device *dev)
{
write_nic_word(dev, RFPinsOutput, 0x480);
rtl8185_rf_pins_enable(dev);
write_nic_word(dev, RFPinsSelect, 0x88 | SW_CONTROL_GPIO);
write_nic_byte(dev, GP_ENABLE, 0);
force_pci_posting(dev);
mdelay(200);
write_nic_word(dev, GP_ENABLE, 0xff & (~(1 << 6)));
}
void rtl8225z2_rf_init(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
int i;
short channel = 1;
u16 brsr;
u32 data;
priv->chan = channel;
rtl8225_host_pci_init(dev);
write_nic_dword(dev, RF_TIMING, 0x000a8008);
brsr = read_nic_word(dev, BRSR);
write_nic_word(dev, BRSR, 0xffff);
write_nic_dword(dev, RF_PARA, 0x100044);
rtl8180_set_mode(dev, EPROM_CMD_CONFIG);
write_nic_byte(dev, CONFIG3, 0x44);
rtl8180_set_mode(dev, EPROM_CMD_NORMAL);
rtl8185_rf_pins_enable(dev);
write_rtl8225(dev, 0x0, 0x2bf); mdelay(1);
write_rtl8225(dev, 0x1, 0xee0); mdelay(1);
write_rtl8225(dev, 0x2, 0x44d); mdelay(1);
write_rtl8225(dev, 0x3, 0x441); mdelay(1);
write_rtl8225(dev, 0x4, 0x8c3); mdelay(1);
write_rtl8225(dev, 0x5, 0xc72); mdelay(1);
write_rtl8225(dev, 0x6, 0xe6); mdelay(1);
write_rtl8225(dev, 0x7, rtl8225_chan[channel]); mdelay(1);
write_rtl8225(dev, 0x8, 0x3f); mdelay(1);
write_rtl8225(dev, 0x9, 0x335); mdelay(1);
write_rtl8225(dev, 0xa, 0x9d4); mdelay(1);
write_rtl8225(dev, 0xb, 0x7bb); mdelay(1);
write_rtl8225(dev, 0xc, 0x850); mdelay(1);
write_rtl8225(dev, 0xd, 0xcdf); mdelay(1);
write_rtl8225(dev, 0xe, 0x2b); mdelay(1);
write_rtl8225(dev, 0xf, 0x114);
mdelay(100);
write_rtl8225(dev, 0x0, 0x1b7);
for (i = 0; i < ARRAY_SIZE(rtl8225z2_rxgain); i++) {
write_rtl8225(dev, 0x1, i + 1);
write_rtl8225(dev, 0x2, rtl8225z2_rxgain[i]);
}
write_rtl8225(dev, 0x3, 0x80);
write_rtl8225(dev, 0x5, 0x4);
write_rtl8225(dev, 0x0, 0xb7);
write_rtl8225(dev, 0x2, 0xc4d);
data = read_rtl8225(dev, 6);
if (!(data & 0x00000080)) {
write_rtl8225(dev, 0x02, 0x0c4d);
force_pci_posting(dev); mdelay(200);
write_rtl8225(dev, 0x02, 0x044d);
force_pci_posting(dev); mdelay(100);
data = read_rtl8225(dev, 6);
if (!(data & 0x00000080))
DMESGW("RF Calibration Failed!!!!\n");
}
mdelay(200);
write_rtl8225(dev, 0x0, 0x2bf);
for (i = 0; i < ARRAY_SIZE(rtl8225_agc); i++) {
write_phy_ofdm(dev, 0xb, rtl8225_agc[i]);
mdelay(1);
write_phy_ofdm(dev, 0xa, i + 0x80);
mdelay(1);
}
force_pci_posting(dev);
mdelay(1);
write_phy_ofdm(dev, 0x00, 0x01); mdelay(1);
write_phy_ofdm(dev, 0x01, 0x02); mdelay(1);
write_phy_ofdm(dev, 0x02, 0x62); mdelay(1);
write_phy_ofdm(dev, 0x03, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x04, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x05, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x06, 0x40); mdelay(1);
write_phy_ofdm(dev, 0x07, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x08, 0x40); mdelay(1);
write_phy_ofdm(dev, 0x09, 0xfe); mdelay(1);
write_phy_ofdm(dev, 0x0a, 0x08); mdelay(1);
write_phy_ofdm(dev, 0x0b, 0x80); mdelay(1);
write_phy_ofdm(dev, 0x0c, 0x01); mdelay(1);
write_phy_ofdm(dev, 0x0d, 0x43);
write_phy_ofdm(dev, 0x0e, 0xd3); mdelay(1);
write_phy_ofdm(dev, 0x0f, 0x38); mdelay(1);
write_phy_ofdm(dev, 0x10, 0x84); mdelay(1);
write_phy_ofdm(dev, 0x11, 0x07); mdelay(1);
write_phy_ofdm(dev, 0x12, 0x20); mdelay(1);
write_phy_ofdm(dev, 0x13, 0x20); mdelay(1);
write_phy_ofdm(dev, 0x14, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x15, 0x40); mdelay(1);
write_phy_ofdm(dev, 0x16, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x17, 0x40); mdelay(1);
write_phy_ofdm(dev, 0x18, 0xef); mdelay(1);
write_phy_ofdm(dev, 0x19, 0x19); mdelay(1);
write_phy_ofdm(dev, 0x1a, 0x20); mdelay(1);
write_phy_ofdm(dev, 0x1b, 0x15); mdelay(1);
write_phy_ofdm(dev, 0x1c, 0x04); mdelay(1);
write_phy_ofdm(dev, 0x1d, 0xc5); mdelay(1);
write_phy_ofdm(dev, 0x1e, 0x95); mdelay(1);
write_phy_ofdm(dev, 0x1f, 0x75); mdelay(1);
write_phy_ofdm(dev, 0x20, 0x1f); mdelay(1);
write_phy_ofdm(dev, 0x21, 0x17); mdelay(1);
write_phy_ofdm(dev, 0x22, 0x16); mdelay(1);
write_phy_ofdm(dev, 0x23, 0x80); mdelay(1);
write_phy_ofdm(dev, 0x24, 0x46); mdelay(1);
write_phy_ofdm(dev, 0x25, 0x00); mdelay(1);
write_phy_ofdm(dev, 0x26, 0x90); mdelay(1);
write_phy_ofdm(dev, 0x27, 0x88); mdelay(1);
rtl8225z2_set_gain(dev, 4);
write_phy_cck(dev, 0x0, 0x98); mdelay(1);
write_phy_cck(dev, 0x3, 0x20); mdelay(1);
write_phy_cck(dev, 0x4, 0x7e); mdelay(1);
write_phy_cck(dev, 0x5, 0x12); mdelay(1);
write_phy_cck(dev, 0x6, 0xfc); mdelay(1);
write_phy_cck(dev, 0x7, 0x78); mdelay(1);
write_phy_cck(dev, 0x8, 0x2e); mdelay(1);
write_phy_cck(dev, 0x10, 0x93); mdelay(1);
write_phy_cck(dev, 0x11, 0x88); mdelay(1);
write_phy_cck(dev, 0x12, 0x47); mdelay(1);
write_phy_cck(dev, 0x13, 0xd0);
write_phy_cck(dev, 0x19, 0x00);
write_phy_cck(dev, 0x1a, 0xa0);
write_phy_cck(dev, 0x1b, 0x08);
write_phy_cck(dev, 0x40, 0x86);
write_phy_cck(dev, 0x41, 0x8d); mdelay(1);
write_phy_cck(dev, 0x42, 0x15); mdelay(1);
write_phy_cck(dev, 0x43, 0x18); mdelay(1);
write_phy_cck(dev, 0x44, 0x36); mdelay(1);
write_phy_cck(dev, 0x45, 0x35); mdelay(1);
write_phy_cck(dev, 0x46, 0x2e); mdelay(1);
write_phy_cck(dev, 0x47, 0x25); mdelay(1);
write_phy_cck(dev, 0x48, 0x1c); mdelay(1);
write_phy_cck(dev, 0x49, 0x12); mdelay(1);
write_phy_cck(dev, 0x4a, 0x09); mdelay(1);
write_phy_cck(dev, 0x4b, 0x04); mdelay(1);
write_phy_cck(dev, 0x4c, 0x05); mdelay(1);
write_nic_byte(dev, 0x5b, 0x0d); mdelay(1);
rtl8225z2_SetTXPowerLevel(dev, channel);
write_phy_cck(dev, 0x11, 0x9b); mdelay(1);
write_phy_ofdm(dev, 0x26, 0x90); mdelay(1);
rtl8185_tx_antenna(dev, 0x03);
write_nic_dword(dev, 0x94, 0x15c00002);
rtl8185_rf_pins_enable(dev);
rtl8225z2_rf_set_chan(dev, priv->chan);
}
void rtl8225z2_rf_set_mode(struct net_device *dev)
{
struct r8180_priv *priv = ieee80211_priv(dev);
if (priv->ieee80211->mode == IEEE_A) {
write_rtl8225(dev, 0x5, 0x1865);
write_nic_dword(dev, RF_PARA, 0x10084);
write_nic_dword(dev, RF_TIMING, 0xa8008);
write_phy_ofdm(dev, 0x0, 0x0);
write_phy_ofdm(dev, 0xa, 0x6);
write_phy_ofdm(dev, 0xb, 0x99);
write_phy_ofdm(dev, 0xf, 0x20);
write_phy_ofdm(dev, 0x11, 0x7);
rtl8225z2_set_gain(dev, 4);
write_phy_ofdm(dev, 0x15, 0x40);
write_phy_ofdm(dev, 0x17, 0x40);
write_nic_dword(dev, 0x94, 0x10000000);
} else {
write_rtl8225(dev, 0x5, 0x1864);
write_nic_dword(dev, RF_PARA, 0x10044);
write_nic_dword(dev, RF_TIMING, 0xa8008);
write_phy_ofdm(dev, 0x0, 0x1);
write_phy_ofdm(dev, 0xa, 0x6);
write_phy_ofdm(dev, 0xb, 0x99);
write_phy_ofdm(dev, 0xf, 0x20);
write_phy_ofdm(dev, 0x11, 0x7);
rtl8225z2_set_gain(dev, 4);
write_phy_ofdm(dev, 0x15, 0x40);
write_phy_ofdm(dev, 0x17, 0x40);
write_nic_dword(dev, 0x94, 0x04000002);
}
}
bool SetZebraRFPowerState8185(struct net_device *dev,
RT_RF_POWER_STATE eRFPowerState)
{
struct r8180_priv *priv = ieee80211_priv(dev);
u8 btCR9346, btConfig3;
bool bActionAllowed = true, bTurnOffBB = true;
u8 u1bTmp;
int i;
bool bResult = true;
u8 QueueID;
if (priv->SetRFPowerStateInProgress == true)
return false;
priv->SetRFPowerStateInProgress = true;
btCR9346 = read_nic_byte(dev, CR9346);
write_nic_byte(dev, CR9346, (btCR9346 | 0xC0));
btConfig3 = read_nic_byte(dev, CONFIG3);
write_nic_byte(dev, CONFIG3, (btConfig3 | CONFIG3_PARM_En));
switch (eRFPowerState) {
case eRfOn:
write_nic_word(dev, 0x37C, 0x00EC);
write_nic_byte(dev, 0x54, 0x00);
write_nic_byte(dev, 0x62, 0x00);
RF_WriteReg(dev, 0x0, 0x009f); udelay(500);
RF_WriteReg(dev, 0x4, 0x0972); udelay(500);
RF_WriteReg(dev, 0x0, 0x009f); udelay(500);
RF_WriteReg(dev, 0x4, 0x0972); udelay(500);
write_phy_ofdm(dev, 0x10, 0x40);
write_phy_ofdm(dev, 0x12, 0x40);
write_nic_byte(dev, CONFIG4, priv->RFProgType);
u1bTmp = read_nic_byte(dev, 0x24E);
write_nic_byte(dev, 0x24E, (u1bTmp & (~(BIT5 | BIT6))));
break;
case eRfSleep:
for (QueueID = 0, i = 0; QueueID < 6;) {
if (get_curr_tx_free_desc(dev, QueueID) ==
priv->txringcount) {
QueueID++;
continue;
} else {
priv->TxPollingTimes++;
if (priv->TxPollingTimes >=
LPS_MAX_SLEEP_WAITING_TIMES_87SE) {
bActionAllowed = false;
break;
} else
udelay(10);
}
}
if (bActionAllowed) {
write_phy_ofdm(dev, 0x10, 0x00);
write_phy_ofdm(dev, 0x12, 0x00);
RF_WriteReg(dev, 0x4, 0x0000);
RF_WriteReg(dev, 0x0, 0x0000);
write_nic_byte(dev, 0x62, 0xff);
write_nic_byte(dev, 0x54, 0xec);
mdelay(1);
{
int i = 0;
while (true) {
u8 tmp24F = read_nic_byte(dev, 0x24f);
if ((tmp24F == 0x01) ||
(tmp24F == 0x09)) {
bTurnOffBB = true;
break;
} else {
udelay(10);
i++;
priv->TxPollingTimes++;
if (priv->TxPollingTimes >= LPS_MAX_SLEEP_WAITING_TIMES_87SE) {
bTurnOffBB = false;
break;
} else
udelay(10);
}
}
}
if (bTurnOffBB) {
u1bTmp = read_nic_byte(dev, 0x24E);
write_nic_byte(dev, 0x24E,
(u1bTmp | BIT5 | BIT6));
write_nic_byte(dev, 0x54, 0xFC);
write_nic_word(dev, 0x37C, 0x00FC);
}
}
break;
case eRfOff:
for (QueueID = 0, i = 0; QueueID < 6;) {
if (get_curr_tx_free_desc(dev, QueueID) ==
priv->txringcount) {
QueueID++;
continue;
} else {
udelay(10);
i++;
}
if (i >= MAX_DOZE_WAITING_TIMES_85B)
break;
}
write_phy_ofdm(dev, 0x10, 0x00);
write_phy_ofdm(dev, 0x12, 0x00);
RF_WriteReg(dev, 0x4, 0x0000);
RF_WriteReg(dev, 0x0, 0x0000);
write_nic_byte(dev, 0x62, 0xff);
write_nic_byte(dev, 0x54, 0xec);
mdelay(1);
{
int i = 0;
while (true) {
u8 tmp24F = read_nic_byte(dev, 0x24f);
if ((tmp24F == 0x01) || (tmp24F == 0x09)) {
bTurnOffBB = true;
break;
} else {
bTurnOffBB = false;
udelay(10);
i++;
}
if (i > MAX_POLLING_24F_TIMES_87SE)
break;
}
}
if (bTurnOffBB) {
u1bTmp = read_nic_byte(dev, 0x24E);
write_nic_byte(dev, 0x24E, (u1bTmp | BIT5 | BIT6));
write_nic_byte(dev, 0x54, 0xFC);
write_nic_word(dev, 0x37C, 0x00FC);
}
break;
}
btConfig3 &= ~(CONFIG3_PARM_En);
write_nic_byte(dev, CONFIG3, btConfig3);
btCR9346 &= ~(0xC0);
write_nic_byte(dev, CR9346, btCR9346);
if (bResult && bActionAllowed)
priv->eRFPowerState = eRFPowerState;
priv->SetRFPowerStateInProgress = false;
return bResult && bActionAllowed;
}
void rtl8225z4_rf_sleep(struct net_device *dev)
{
MgntActSet_RF_State(dev, eRfSleep, RF_CHANGE_BY_PS);
}
void rtl8225z4_rf_wakeup(struct net_device *dev)
{
MgntActSet_RF_State(dev, eRfOn, RF_CHANGE_BY_PS);
}
