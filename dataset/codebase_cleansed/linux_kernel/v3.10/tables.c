static inline void assert_sizes(void)
{
BUILD_BUG_ON(B43_TAB_ROTOR_SIZE != ARRAY_SIZE(b43_tab_rotor));
BUILD_BUG_ON(B43_TAB_RETARD_SIZE != ARRAY_SIZE(b43_tab_retard));
BUILD_BUG_ON(B43_TAB_FINEFREQA_SIZE != ARRAY_SIZE(b43_tab_finefreqa));
BUILD_BUG_ON(B43_TAB_FINEFREQG_SIZE != ARRAY_SIZE(b43_tab_finefreqg));
BUILD_BUG_ON(B43_TAB_NOISEA2_SIZE != ARRAY_SIZE(b43_tab_noisea2));
BUILD_BUG_ON(B43_TAB_NOISEA3_SIZE != ARRAY_SIZE(b43_tab_noisea3));
BUILD_BUG_ON(B43_TAB_NOISEG1_SIZE != ARRAY_SIZE(b43_tab_noiseg1));
BUILD_BUG_ON(B43_TAB_NOISEG2_SIZE != ARRAY_SIZE(b43_tab_noiseg2));
BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
ARRAY_SIZE(b43_tab_noisescalea2));
BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
ARRAY_SIZE(b43_tab_noisescalea3));
BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
ARRAY_SIZE(b43_tab_noisescaleg1));
BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
ARRAY_SIZE(b43_tab_noisescaleg2));
BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
ARRAY_SIZE(b43_tab_noisescaleg3));
BUILD_BUG_ON(B43_TAB_SIGMASQR_SIZE != ARRAY_SIZE(b43_tab_sigmasqr1));
BUILD_BUG_ON(B43_TAB_SIGMASQR_SIZE != ARRAY_SIZE(b43_tab_sigmasqr2));
BUILD_BUG_ON(B43_TAB_RSSIAGC1_SIZE != ARRAY_SIZE(b43_tab_rssiagc1));
BUILD_BUG_ON(B43_TAB_RSSIAGC2_SIZE != ARRAY_SIZE(b43_tab_rssiagc2));
}
u16 b43_ofdmtab_read16(struct b43_wldev *dev, u16 table, u16 offset)
{
struct b43_phy_g *gphy = dev->phy.g;
u16 addr;
addr = table + offset;
if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_READ) ||
(addr - 1 != gphy->ofdmtab_addr)) {
b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_READ;
}
gphy->ofdmtab_addr = addr;
return b43_phy_read(dev, B43_PHY_OTABLEI);
assert_sizes();
}
void b43_ofdmtab_write16(struct b43_wldev *dev, u16 table,
u16 offset, u16 value)
{
struct b43_phy_g *gphy = dev->phy.g;
u16 addr;
addr = table + offset;
if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_WRITE) ||
(addr - 1 != gphy->ofdmtab_addr)) {
b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_WRITE;
}
gphy->ofdmtab_addr = addr;
b43_phy_write(dev, B43_PHY_OTABLEI, value);
}
u32 b43_ofdmtab_read32(struct b43_wldev *dev, u16 table, u16 offset)
{
struct b43_phy_g *gphy = dev->phy.g;
u32 ret;
u16 addr;
addr = table + offset;
if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_READ) ||
(addr - 1 != gphy->ofdmtab_addr)) {
b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_READ;
}
gphy->ofdmtab_addr = addr;
ret = b43_phy_read(dev, B43_PHY_OTABLEQ);
ret <<= 16;
ret |= b43_phy_read(dev, B43_PHY_OTABLEI);
return ret;
}
void b43_ofdmtab_write32(struct b43_wldev *dev, u16 table,
u16 offset, u32 value)
{
struct b43_phy_g *gphy = dev->phy.g;
u16 addr;
addr = table + offset;
if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_WRITE) ||
(addr - 1 != gphy->ofdmtab_addr)) {
b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_WRITE;
}
gphy->ofdmtab_addr = addr;
b43_phy_write(dev, B43_PHY_OTABLEI, value);
b43_phy_write(dev, B43_PHY_OTABLEQ, (value >> 16));
}
u16 b43_gtab_read(struct b43_wldev *dev, u16 table, u16 offset)
{
b43_phy_write(dev, B43_PHY_GTABCTL, table + offset);
return b43_phy_read(dev, B43_PHY_GTABDATA);
}
void b43_gtab_write(struct b43_wldev *dev, u16 table, u16 offset, u16 value)
{
b43_phy_write(dev, B43_PHY_GTABCTL, table + offset);
b43_phy_write(dev, B43_PHY_GTABDATA, value);
}
