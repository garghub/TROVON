static inline u16 channel2freq_a(u8 channel)
{
B43_WARN_ON(channel > 200);
return (5000 + 5 * channel);
}
static inline u16 freq_r3A_value(u16 frequency)
{
u16 value;
if (frequency < 5091)
value = 0x0040;
else if (frequency < 5321)
value = 0x0000;
else if (frequency < 5806)
value = 0x0080;
else
value = 0x0040;
return value;
}
static void b43_radio_set_tx_iq(struct b43_wldev *dev)
{
static const u8 data_high[5] = { 0x00, 0x40, 0x80, 0x90, 0xD0 };
static const u8 data_low[5] = { 0x00, 0x01, 0x05, 0x06, 0x0A };
u16 tmp = b43_radio_read16(dev, 0x001E);
int i, j;
for (i = 0; i < 5; i++) {
for (j = 0; j < 5; j++) {
if (tmp == (data_high[i] << 4 | data_low[j])) {
b43_phy_write(dev, 0x0069,
(i - j) << 8 | 0x00C0);
return;
}
}
}
}
static void aphy_channel_switch(struct b43_wldev *dev, unsigned int channel)
{
u16 freq, r8, tmp;
freq = channel2freq_a(channel);
r8 = b43_radio_read16(dev, 0x0008);
b43_write16(dev, 0x03F0, freq);
b43_radio_write16(dev, 0x0008, r8);
tmp = b43_radio_read16(dev, 0x002E);
tmp &= 0x0080;
b43_radio_write16(dev, 0x002E, tmp);
if (freq >= 4920 && freq <= 5500) {
r8 = 3 * freq / 116;
}
b43_radio_write16(dev, 0x0007, (r8 << 4) | r8);
b43_radio_write16(dev, 0x0020, (r8 << 4) | r8);
b43_radio_write16(dev, 0x0021, (r8 << 4) | r8);
b43_radio_maskset(dev, 0x0022, 0x000F, (r8 << 4));
b43_radio_write16(dev, 0x002A, (r8 << 4));
b43_radio_write16(dev, 0x002B, (r8 << 4));
b43_radio_maskset(dev, 0x0008, 0x00F0, (r8 << 4));
b43_radio_maskset(dev, 0x0029, 0xFF0F, 0x00B0);
b43_radio_write16(dev, 0x0035, 0x00AA);
b43_radio_write16(dev, 0x0036, 0x0085);
b43_radio_maskset(dev, 0x003A, 0xFF20, freq_r3A_value(freq));
b43_radio_mask(dev, 0x003D, 0x00FF);
b43_radio_maskset(dev, 0x0081, 0xFF7F, 0x0080);
b43_radio_mask(dev, 0x0035, 0xFFEF);
b43_radio_maskset(dev, 0x0035, 0xFFEF, 0x0010);
b43_radio_set_tx_iq(dev);
}
static void b43_radio_init2060(struct b43_wldev *dev)
{
b43_radio_write16(dev, 0x0004, 0x00C0);
b43_radio_write16(dev, 0x0005, 0x0008);
b43_radio_write16(dev, 0x0009, 0x0040);
b43_radio_write16(dev, 0x0005, 0x00AA);
b43_radio_write16(dev, 0x0032, 0x008F);
b43_radio_write16(dev, 0x0006, 0x008F);
b43_radio_write16(dev, 0x0034, 0x008F);
b43_radio_write16(dev, 0x002C, 0x0007);
b43_radio_write16(dev, 0x0082, 0x0080);
b43_radio_write16(dev, 0x0080, 0x0000);
b43_radio_write16(dev, 0x003F, 0x00DA);
b43_radio_mask(dev, 0x0005, ~0x0008);
b43_radio_mask(dev, 0x0081, ~0x0010);
b43_radio_mask(dev, 0x0081, ~0x0020);
b43_radio_mask(dev, 0x0081, ~0x0020);
msleep(1);
b43_radio_maskset(dev, 0x0081, ~0x0020, 0x0010);
msleep(1);
b43_radio_maskset(dev, 0x0005, ~0x0008, 0x0008);
b43_radio_mask(dev, 0x0085, ~0x0010);
b43_radio_mask(dev, 0x0005, ~0x0008);
b43_radio_mask(dev, 0x0081, ~0x0040);
b43_radio_maskset(dev, 0x0081, ~0x0040, 0x0040);
b43_radio_write16(dev, 0x0005,
(b43_radio_read16(dev, 0x0081) & ~0x0008) | 0x0008);
b43_phy_write(dev, 0x0063, 0xDDC6);
b43_phy_write(dev, 0x0069, 0x07BE);
b43_phy_write(dev, 0x006A, 0x0000);
aphy_channel_switch(dev, dev->phy.ops->get_default_chan(dev));
msleep(1);
}
static void b43_phy_rssiagc(struct b43_wldev *dev, u8 enable)
{
int i;
if (dev->phy.rev < 3) {
if (enable)
for (i = 0; i < B43_TAB_RSSIAGC1_SIZE; i++) {
b43_ofdmtab_write16(dev,
B43_OFDMTAB_LNAHPFGAIN1, i, 0xFFF8);
b43_ofdmtab_write16(dev,
B43_OFDMTAB_WRSSI, i, 0xFFF8);
}
else
for (i = 0; i < B43_TAB_RSSIAGC1_SIZE; i++) {
b43_ofdmtab_write16(dev,
B43_OFDMTAB_LNAHPFGAIN1, i, b43_tab_rssiagc1[i]);
b43_ofdmtab_write16(dev,
B43_OFDMTAB_WRSSI, i, b43_tab_rssiagc1[i]);
}
} else {
if (enable)
for (i = 0; i < B43_TAB_RSSIAGC1_SIZE; i++)
b43_ofdmtab_write16(dev,
B43_OFDMTAB_WRSSI, i, 0x0820);
else
for (i = 0; i < B43_TAB_RSSIAGC2_SIZE; i++)
b43_ofdmtab_write16(dev,
B43_OFDMTAB_WRSSI, i, b43_tab_rssiagc2[i]);
}
}
static void b43_phy_ww(struct b43_wldev *dev)
{
u16 b, curr_s, best_s = 0xFFFF;
int i;
b43_phy_mask(dev, B43_PHY_CRS0, ~B43_PHY_CRS0_EN);
b43_phy_set(dev, B43_PHY_OFDM(0x1B), 0x1000);
b43_phy_maskset(dev, B43_PHY_OFDM(0x82), 0xF0FF, 0x0300);
b43_radio_set(dev, 0x0009, 0x0080);
b43_radio_maskset(dev, 0x0012, 0xFFFC, 0x0002);
b43_wa_initgains(dev);
b43_phy_write(dev, B43_PHY_OFDM(0xBA), 0x3ED5);
b = b43_phy_read(dev, B43_PHY_PWRDOWN);
b43_phy_write(dev, B43_PHY_PWRDOWN, (b & 0xFFF8) | 0x0005);
b43_radio_set(dev, 0x0004, 0x0004);
for (i = 0x10; i <= 0x20; i++) {
b43_radio_write16(dev, 0x0013, i);
curr_s = b43_phy_read(dev, B43_PHY_OTABLEQ) & 0x00FF;
if (!curr_s) {
best_s = 0x0000;
break;
} else if (curr_s >= 0x0080)
curr_s = 0x0100 - curr_s;
if (curr_s < best_s)
best_s = curr_s;
}
b43_phy_write(dev, B43_PHY_PWRDOWN, b);
b43_radio_mask(dev, 0x0004, 0xFFFB);
b43_radio_write16(dev, 0x0013, best_s);
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1_R1, 0, 0xFFEC);
b43_phy_write(dev, B43_PHY_OFDM(0xB7), 0x1E80);
b43_phy_write(dev, B43_PHY_OFDM(0xB6), 0x1C00);
b43_phy_write(dev, B43_PHY_OFDM(0xB5), 0x0EC0);
b43_phy_write(dev, B43_PHY_OFDM(0xB2), 0x00C0);
b43_phy_write(dev, B43_PHY_OFDM(0xB9), 0x1FFF);
b43_phy_maskset(dev, B43_PHY_OFDM(0xBB), 0xF000, 0x0053);
b43_phy_maskset(dev, B43_PHY_OFDM61, 0xFE1F, 0x0120);
b43_phy_maskset(dev, B43_PHY_OFDM(0x13), 0x0FFF, 0x3000);
b43_phy_maskset(dev, B43_PHY_OFDM(0x14), 0x0FFF, 0x3000);
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 6, 0x0017);
for (i = 0; i < 6; i++)
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, i, 0x000F);
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 0x0D, 0x000E);
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 0x0E, 0x0011);
b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 0x0F, 0x0013);
b43_phy_write(dev, B43_PHY_OFDM(0x33), 0x5030);
b43_phy_set(dev, B43_PHY_CRS0, B43_PHY_CRS0_EN);
}
static void hardware_pctl_init_aphy(struct b43_wldev *dev)
{
}
void b43_phy_inita(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
B43_WARN_ON((phy->type != B43_PHYTYPE_A) &&
(phy->type != B43_PHYTYPE_G));
might_sleep();
if (phy->rev >= 6) {
if (phy->type == B43_PHYTYPE_A)
b43_phy_mask(dev, B43_PHY_OFDM(0x1B), ~0x1000);
if (b43_phy_read(dev, B43_PHY_ENCORE) & B43_PHY_ENCORE_EN)
b43_phy_set(dev, B43_PHY_ENCORE, 0x0010);
else
b43_phy_mask(dev, B43_PHY_ENCORE, ~0x1010);
}
b43_wa_all(dev);
if (phy->type == B43_PHYTYPE_A) {
if (phy->gmode && (phy->rev < 3))
b43_phy_set(dev, 0x0034, 0x0001);
b43_phy_rssiagc(dev, 0);
b43_phy_set(dev, B43_PHY_CRS0, B43_PHY_CRS0_EN);
b43_radio_init2060(dev);
if ((dev->dev->board_vendor == SSB_BOARDVENDOR_BCM) &&
((dev->dev->board_type == SSB_BOARD_BU4306) ||
(dev->dev->board_type == SSB_BOARD_BU4309))) {
;
}
if (phy->rev >= 3)
b43_phy_ww(dev);
hardware_pctl_init_aphy(dev);
}
if ((phy->type == B43_PHYTYPE_G) &&
(dev->dev->bus_sprom->boardflags_lo & B43_BFL_PACTRL)) {
b43_phy_maskset(dev, B43_PHY_OFDM(0x6E), 0xE000, 0x3CF);
}
}
static int b43_aphy_init_tssi2dbm_table(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
struct b43_phy_a *aphy = phy->a;
s16 pab0, pab1, pab2;
pab0 = (s16) (dev->dev->bus_sprom->pa1b0);
pab1 = (s16) (dev->dev->bus_sprom->pa1b1);
pab2 = (s16) (dev->dev->bus_sprom->pa1b2);
if (pab0 != 0 && pab1 != 0 && pab2 != 0 &&
pab0 != -1 && pab1 != -1 && pab2 != -1) {
if ((s8) dev->dev->bus_sprom->itssi_a != 0 &&
(s8) dev->dev->bus_sprom->itssi_a != -1)
aphy->tgt_idle_tssi =
(s8) (dev->dev->bus_sprom->itssi_a);
else
aphy->tgt_idle_tssi = 62;
aphy->tssi2dbm = b43_generate_dyn_tssi2dbm_tab(dev, pab0,
pab1, pab2);
if (!aphy->tssi2dbm)
return -ENOMEM;
} else {
aphy->tssi2dbm = NULL;
b43err(dev->wl, "Could not generate tssi2dBm "
"table (wrong SPROM info)!\n");
return -ENODEV;
}
return 0;
}
static int b43_aphy_op_allocate(struct b43_wldev *dev)
{
struct b43_phy_a *aphy;
int err;
aphy = kzalloc(sizeof(*aphy), GFP_KERNEL);
if (!aphy)
return -ENOMEM;
dev->phy.a = aphy;
err = b43_aphy_init_tssi2dbm_table(dev);
if (err)
goto err_free_aphy;
return 0;
err_free_aphy:
kfree(aphy);
dev->phy.a = NULL;
return err;
}
static void b43_aphy_op_prepare_structs(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
struct b43_phy_a *aphy = phy->a;
const void *tssi2dbm;
int tgt_idle_tssi;
tssi2dbm = aphy->tssi2dbm;
tgt_idle_tssi = aphy->tgt_idle_tssi;
memset(aphy, 0, sizeof(*aphy));
aphy->tssi2dbm = tssi2dbm;
aphy->tgt_idle_tssi = tgt_idle_tssi;
}
static void b43_aphy_op_free(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
struct b43_phy_a *aphy = phy->a;
kfree(aphy->tssi2dbm);
aphy->tssi2dbm = NULL;
kfree(aphy);
dev->phy.a = NULL;
}
static int b43_aphy_op_init(struct b43_wldev *dev)
{
b43_phy_inita(dev);
return 0;
}
static inline u16 adjust_phyreg(struct b43_wldev *dev, u16 offset)
{
if ((offset & B43_PHYROUTE) == B43_PHYROUTE_OFDM_GPHY) {
offset &= ~B43_PHYROUTE;
offset |= B43_PHYROUTE_BASE;
}
#if B43_DEBUG
if ((offset & B43_PHYROUTE) == B43_PHYROUTE_EXT_GPHY) {
b43err(dev->wl, "Invalid EXT-G PHY access at "
"0x%04X on A-PHY\n", offset);
dump_stack();
}
if ((offset & B43_PHYROUTE) == B43_PHYROUTE_N_BMODE) {
b43err(dev->wl, "Invalid N-BMODE PHY access at "
"0x%04X on A-PHY\n", offset);
dump_stack();
}
#endif
return offset;
}
static u16 b43_aphy_op_read(struct b43_wldev *dev, u16 reg)
{
reg = adjust_phyreg(dev, reg);
b43_write16(dev, B43_MMIO_PHY_CONTROL, reg);
return b43_read16(dev, B43_MMIO_PHY_DATA);
}
static void b43_aphy_op_write(struct b43_wldev *dev, u16 reg, u16 value)
{
reg = adjust_phyreg(dev, reg);
b43_write16(dev, B43_MMIO_PHY_CONTROL, reg);
b43_write16(dev, B43_MMIO_PHY_DATA, value);
}
static u16 b43_aphy_op_radio_read(struct b43_wldev *dev, u16 reg)
{
B43_WARN_ON(reg == 1);
reg |= 0x40;
b43_write16(dev, B43_MMIO_RADIO_CONTROL, reg);
return b43_read16(dev, B43_MMIO_RADIO_DATA_LOW);
}
static void b43_aphy_op_radio_write(struct b43_wldev *dev, u16 reg, u16 value)
{
B43_WARN_ON(reg == 1);
b43_write16(dev, B43_MMIO_RADIO_CONTROL, reg);
b43_write16(dev, B43_MMIO_RADIO_DATA_LOW, value);
}
static bool b43_aphy_op_supports_hwpctl(struct b43_wldev *dev)
{
return (dev->phy.rev >= 5);
}
static void b43_aphy_op_software_rfkill(struct b43_wldev *dev,
bool blocked)
{
struct b43_phy *phy = &dev->phy;
if (!blocked) {
if (phy->radio_on)
return;
b43_radio_write16(dev, 0x0004, 0x00C0);
b43_radio_write16(dev, 0x0005, 0x0008);
b43_phy_mask(dev, 0x0010, 0xFFF7);
b43_phy_mask(dev, 0x0011, 0xFFF7);
b43_radio_init2060(dev);
} else {
b43_radio_write16(dev, 0x0004, 0x00FF);
b43_radio_write16(dev, 0x0005, 0x00FB);
b43_phy_set(dev, 0x0010, 0x0008);
b43_phy_set(dev, 0x0011, 0x0008);
}
}
static int b43_aphy_op_switch_channel(struct b43_wldev *dev,
unsigned int new_channel)
{
if (new_channel > 200)
return -EINVAL;
aphy_channel_switch(dev, new_channel);
return 0;
}
static unsigned int b43_aphy_op_get_default_chan(struct b43_wldev *dev)
{
return 36;
}
static void b43_aphy_op_set_rx_antenna(struct b43_wldev *dev, int antenna)
{
struct b43_phy *phy = &dev->phy;
u16 tmp;
int autodiv = 0;
if (antenna == B43_ANTENNA_AUTO0 || antenna == B43_ANTENNA_AUTO1)
autodiv = 1;
b43_hf_write(dev, b43_hf_read(dev) & ~B43_HF_ANTDIVHELP);
b43_phy_maskset(dev, B43_PHY_BBANDCFG, ~B43_PHY_BBANDCFG_RXANT,
(autodiv ? B43_ANTENNA_AUTO1 : antenna) <<
B43_PHY_BBANDCFG_RXANT_SHIFT);
if (autodiv) {
tmp = b43_phy_read(dev, B43_PHY_ANTDWELL);
if (antenna == B43_ANTENNA_AUTO1)
tmp &= ~B43_PHY_ANTDWELL_AUTODIV1;
else
tmp |= B43_PHY_ANTDWELL_AUTODIV1;
b43_phy_write(dev, B43_PHY_ANTDWELL, tmp);
}
if (phy->rev < 3)
b43_phy_maskset(dev, B43_PHY_ANTDWELL, 0xFF00, 0x24);
else {
b43_phy_set(dev, B43_PHY_OFDM61, 0x10);
if (phy->rev == 3) {
b43_phy_write(dev, B43_PHY_CLIPPWRDOWNT, 0x1D);
b43_phy_write(dev, B43_PHY_ADIVRELATED, 8);
} else {
b43_phy_write(dev, B43_PHY_CLIPPWRDOWNT, 0x3A);
b43_phy_maskset(dev, B43_PHY_ADIVRELATED, 0xFF00, 8);
}
}
b43_hf_write(dev, b43_hf_read(dev) | B43_HF_ANTDIVHELP);
}
static void b43_aphy_op_adjust_txpower(struct b43_wldev *dev)
{
}
static enum b43_txpwr_result b43_aphy_op_recalc_txpower(struct b43_wldev *dev,
bool ignore_tssi)
{
return B43_TXPWR_RES_DONE;
}
static void b43_aphy_op_pwork_15sec(struct b43_wldev *dev)
{
}
static void b43_aphy_op_pwork_60sec(struct b43_wldev *dev)
{
}
