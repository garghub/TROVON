void b43legacy_ilt_write(struct b43legacy_wldev *dev, u16 offset, u16 val)
{
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_CTRL, offset);
mmiowb();
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_DATA1, val);
}
void b43legacy_ilt_write32(struct b43legacy_wldev *dev, u16 offset, u32 val)
{
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_CTRL, offset);
mmiowb();
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_DATA2,
(val & 0xFFFF0000) >> 16);
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_DATA1,
val & 0x0000FFFF);
}
u16 b43legacy_ilt_read(struct b43legacy_wldev *dev, u16 offset)
{
b43legacy_phy_write(dev, B43legacy_PHY_ILT_G_CTRL, offset);
return b43legacy_phy_read(dev, B43legacy_PHY_ILT_G_DATA1);
}
