int tulip_mdio_read(struct net_device *dev, int phy_id, int location)
{
struct tulip_private *tp = netdev_priv(dev);
int i;
int read_cmd = (0xf6 << 10) | ((phy_id & 0x1f) << 5) | location;
int retval = 0;
void __iomem *ioaddr = tp->base_addr;
void __iomem *mdio_addr = ioaddr + CSR9;
unsigned long flags;
if (location & ~0x1f)
return 0xffff;
if (tp->chip_id == COMET && phy_id == 30) {
if (comet_miireg2offset[location])
return ioread32(ioaddr + comet_miireg2offset[location]);
return 0xffff;
}
spin_lock_irqsave(&tp->mii_lock, flags);
if (tp->chip_id == LC82C168) {
iowrite32(0x60020000 + (phy_id<<23) + (location<<18), ioaddr + 0xA0);
ioread32(ioaddr + 0xA0);
ioread32(ioaddr + 0xA0);
for (i = 1000; i >= 0; --i) {
barrier();
if ( ! ((retval = ioread32(ioaddr + 0xA0)) & 0x80000000))
break;
}
spin_unlock_irqrestore(&tp->mii_lock, flags);
return retval & 0xffff;
}
for (i = 32; i >= 0; i--) {
iowrite32(MDIO_ENB | MDIO_DATA_WRITE1, mdio_addr);
mdio_delay();
iowrite32(MDIO_ENB | MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
for (i = 15; i >= 0; i--) {
int dataval = (read_cmd & (1 << i)) ? MDIO_DATA_WRITE1 : 0;
iowrite32(MDIO_ENB | dataval, mdio_addr);
mdio_delay();
iowrite32(MDIO_ENB | dataval | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
for (i = 19; i > 0; i--) {
iowrite32(MDIO_ENB_IN, mdio_addr);
mdio_delay();
retval = (retval << 1) | ((ioread32(mdio_addr) & MDIO_DATA_READ) ? 1 : 0);
iowrite32(MDIO_ENB_IN | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
spin_unlock_irqrestore(&tp->mii_lock, flags);
return (retval>>1) & 0xffff;
}
void tulip_mdio_write(struct net_device *dev, int phy_id, int location, int val)
{
struct tulip_private *tp = netdev_priv(dev);
int i;
int cmd = (0x5002 << 16) | ((phy_id & 0x1f) << 23) | (location<<18) | (val & 0xffff);
void __iomem *ioaddr = tp->base_addr;
void __iomem *mdio_addr = ioaddr + CSR9;
unsigned long flags;
if (location & ~0x1f)
return;
if (tp->chip_id == COMET && phy_id == 30) {
if (comet_miireg2offset[location])
iowrite32(val, ioaddr + comet_miireg2offset[location]);
return;
}
spin_lock_irqsave(&tp->mii_lock, flags);
if (tp->chip_id == LC82C168) {
iowrite32(cmd, ioaddr + 0xA0);
for (i = 1000; i >= 0; --i) {
barrier();
if ( ! (ioread32(ioaddr + 0xA0) & 0x80000000))
break;
}
spin_unlock_irqrestore(&tp->mii_lock, flags);
return;
}
for (i = 32; i >= 0; i--) {
iowrite32(MDIO_ENB | MDIO_DATA_WRITE1, mdio_addr);
mdio_delay();
iowrite32(MDIO_ENB | MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
for (i = 31; i >= 0; i--) {
int dataval = (cmd & (1 << i)) ? MDIO_DATA_WRITE1 : 0;
iowrite32(MDIO_ENB | dataval, mdio_addr);
mdio_delay();
iowrite32(MDIO_ENB | dataval | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
for (i = 2; i > 0; i--) {
iowrite32(MDIO_ENB_IN, mdio_addr);
mdio_delay();
iowrite32(MDIO_ENB_IN | MDIO_SHIFT_CLK, mdio_addr);
mdio_delay();
}
spin_unlock_irqrestore(&tp->mii_lock, flags);
}
void tulip_select_media(struct net_device *dev, int startup)
{
struct tulip_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->base_addr;
struct mediatable *mtable = tp->mtable;
u32 new_csr6;
int i;
if (mtable) {
struct medialeaf *mleaf = &mtable->mleaf[tp->cur_index];
unsigned char *p = mleaf->leafdata;
switch (mleaf->type) {
case 0:
if (tulip_debug > 1)
netdev_dbg(dev, "Using a 21140 non-MII transceiver with control setting %02x\n",
p[1]);
dev->if_port = p[0];
if (startup)
iowrite32(mtable->csr12dir | 0x100, ioaddr + CSR12);
iowrite32(p[1], ioaddr + CSR12);
new_csr6 = 0x02000000 | ((p[2] & 0x71) << 18);
break;
case 2: case 4: {
u16 setup[5];
u32 csr13val, csr14val, csr15dir, csr15val;
for (i = 0; i < 5; i++)
setup[i] = get_u16(&p[i*2 + 1]);
dev->if_port = p[0] & MEDIA_MASK;
if (tulip_media_cap[dev->if_port] & MediaAlwaysFD)
tp->full_duplex = 1;
if (startup && mtable->has_reset) {
struct medialeaf *rleaf = &mtable->mleaf[mtable->has_reset];
unsigned char *rst = rleaf->leafdata;
if (tulip_debug > 1)
netdev_dbg(dev, "Resetting the transceiver\n");
for (i = 0; i < rst[0]; i++)
iowrite32(get_u16(rst + 1 + (i<<1)) << 16, ioaddr + CSR15);
}
if (tulip_debug > 1)
netdev_dbg(dev, "21143 non-MII %s transceiver control %04x/%04x\n",
medianame[dev->if_port],
setup[0], setup[1]);
if (p[0] & 0x40) {
csr13val = setup[0];
csr14val = setup[1];
csr15dir = (setup[3]<<16) | setup[2];
csr15val = (setup[4]<<16) | setup[2];
iowrite32(0, ioaddr + CSR13);
iowrite32(csr14val, ioaddr + CSR14);
iowrite32(csr15dir, ioaddr + CSR15);
iowrite32(csr15val, ioaddr + CSR15);
iowrite32(csr13val, ioaddr + CSR13);
} else {
csr13val = 1;
csr14val = 0;
csr15dir = (setup[0]<<16) | 0x0008;
csr15val = (setup[1]<<16) | 0x0008;
if (dev->if_port <= 4)
csr14val = t21142_csr14[dev->if_port];
if (startup) {
iowrite32(0, ioaddr + CSR13);
iowrite32(csr14val, ioaddr + CSR14);
}
iowrite32(csr15dir, ioaddr + CSR15);
iowrite32(csr15val, ioaddr + CSR15);
if (startup) iowrite32(csr13val, ioaddr + CSR13);
}
if (tulip_debug > 1)
netdev_dbg(dev, "Setting CSR15 to %08x/%08x\n",
csr15dir, csr15val);
if (mleaf->type == 4)
new_csr6 = 0x82020000 | ((setup[2] & 0x71) << 18);
else
new_csr6 = 0x82420000;
break;
}
case 1: case 3: {
int phy_num = p[0];
int init_length = p[1];
u16 *misc_info, tmp_info;
dev->if_port = 11;
new_csr6 = 0x020E0000;
if (mleaf->type == 3) {
u16 *init_sequence = (u16*)(p+2);
u16 *reset_sequence = &((u16*)(p+3))[init_length];
int reset_length = p[2 + init_length*2];
misc_info = reset_sequence + reset_length;
if (startup) {
int timeout = 10;
for (i = 0; i < reset_length; i++)
iowrite32(get_u16(&reset_sequence[i]) << 16, ioaddr + CSR15);
ioread32(ioaddr + CSR15);
udelay(500);
while (timeout-- &&
(tulip_mdio_read (dev, phy_num, MII_BMCR) & BMCR_RESET))
udelay(100);
}
for (i = 0; i < init_length; i++)
iowrite32(get_u16(&init_sequence[i]) << 16, ioaddr + CSR15);
ioread32(ioaddr + CSR15);
} else {
u8 *init_sequence = p + 2;
u8 *reset_sequence = p + 3 + init_length;
int reset_length = p[2 + init_length];
misc_info = (u16*)(reset_sequence + reset_length);
if (startup) {
int timeout = 10;
iowrite32(mtable->csr12dir | 0x100, ioaddr + CSR12);
for (i = 0; i < reset_length; i++)
iowrite32(reset_sequence[i], ioaddr + CSR12);
ioread32(ioaddr + CSR12);
udelay(500);
while (timeout-- &&
(tulip_mdio_read (dev, phy_num, MII_BMCR) & BMCR_RESET))
udelay(100);
}
for (i = 0; i < init_length; i++)
iowrite32(init_sequence[i], ioaddr + CSR12);
ioread32(ioaddr + CSR12);
}
tmp_info = get_u16(&misc_info[1]);
if (tmp_info)
tp->advertising[phy_num] = tmp_info | 1;
if (tmp_info && startup < 2) {
if (tp->mii_advertise == 0)
tp->mii_advertise = tp->advertising[phy_num];
if (tulip_debug > 1)
netdev_dbg(dev, " Advertising %04x on MII %d\n",
tp->mii_advertise,
tp->phys[phy_num]);
tulip_mdio_write(dev, tp->phys[phy_num], 4, tp->mii_advertise);
}
break;
}
case 5: case 6: {
u16 setup[5];
new_csr6 = 0;
for (i = 0; i < 5; i++)
setup[i] = get_u16(&p[i*2 + 1]);
if (startup && mtable->has_reset) {
struct medialeaf *rleaf = &mtable->mleaf[mtable->has_reset];
unsigned char *rst = rleaf->leafdata;
if (tulip_debug > 1)
netdev_dbg(dev, "Resetting the transceiver\n");
for (i = 0; i < rst[0]; i++)
iowrite32(get_u16(rst + 1 + (i<<1)) << 16, ioaddr + CSR15);
}
break;
}
default:
netdev_dbg(dev, " Invalid media table selection %d\n",
mleaf->type);
new_csr6 = 0x020E0000;
}
if (tulip_debug > 1)
netdev_dbg(dev, "Using media type %s, CSR12 is %02x\n",
medianame[dev->if_port],
ioread32(ioaddr + CSR12) & 0xff);
} else if (tp->chip_id == LC82C168) {
if (startup && ! tp->medialock)
dev->if_port = tp->mii_cnt ? 11 : 0;
if (tulip_debug > 1)
netdev_dbg(dev, "PNIC PHY status is %3.3x, media %s\n",
ioread32(ioaddr + 0xB8),
medianame[dev->if_port]);
if (tp->mii_cnt) {
new_csr6 = 0x810C0000;
iowrite32(0x0001, ioaddr + CSR15);
iowrite32(0x0201B07A, ioaddr + 0xB8);
} else if (startup) {
iowrite32(0x32, ioaddr + CSR12);
new_csr6 = 0x00420000;
iowrite32(0x0001B078, ioaddr + 0xB8);
iowrite32(0x0201B078, ioaddr + 0xB8);
} else if (dev->if_port == 3 || dev->if_port == 5) {
iowrite32(0x33, ioaddr + CSR12);
new_csr6 = 0x01860000;
iowrite32(startup ? 0x0201F868 : 0x0001F868, ioaddr + 0xB8);
} else {
iowrite32(0x32, ioaddr + CSR12);
new_csr6 = 0x00420000;
iowrite32(0x1F078, ioaddr + 0xB8);
}
} else {
if (tp->default_port == 0)
dev->if_port = tp->mii_cnt ? 11 : 3;
if (tulip_media_cap[dev->if_port] & MediaIsMII) {
new_csr6 = 0x020E0000;
} else if (tulip_media_cap[dev->if_port] & MediaIsFx) {
new_csr6 = 0x02860000;
} else
new_csr6 = 0x03860000;
if (tulip_debug > 1)
netdev_dbg(dev, "No media description table, assuming %s transceiver, CSR12 %02x\n",
medianame[dev->if_port],
ioread32(ioaddr + CSR12));
}
tp->csr6 = new_csr6 | (tp->csr6 & 0xfdff) | (tp->full_duplex ? 0x0200 : 0);
mdelay(1);
}
int tulip_check_duplex(struct net_device *dev)
{
struct tulip_private *tp = netdev_priv(dev);
unsigned int bmsr, lpa, negotiated, new_csr6;
bmsr = tulip_mdio_read(dev, tp->phys[0], MII_BMSR);
lpa = tulip_mdio_read(dev, tp->phys[0], MII_LPA);
if (tulip_debug > 1)
dev_info(&dev->dev, "MII status %04x, Link partner report %04x\n",
bmsr, lpa);
if (bmsr == 0xffff)
return -2;
if ((bmsr & BMSR_LSTATUS) == 0) {
int new_bmsr = tulip_mdio_read(dev, tp->phys[0], MII_BMSR);
if ((new_bmsr & BMSR_LSTATUS) == 0) {
if (tulip_debug > 1)
dev_info(&dev->dev,
"No link beat on the MII interface, status %04x\n",
new_bmsr);
return -1;
}
}
negotiated = lpa & tp->advertising[0];
tp->full_duplex = mii_duplex(tp->full_duplex_lock, negotiated);
new_csr6 = tp->csr6;
if (negotiated & LPA_100) new_csr6 &= ~TxThreshold;
else new_csr6 |= TxThreshold;
if (tp->full_duplex) new_csr6 |= FullDuplex;
else new_csr6 &= ~FullDuplex;
if (new_csr6 != tp->csr6) {
tp->csr6 = new_csr6;
tulip_restart_rxtx(tp);
if (tulip_debug > 0)
dev_info(&dev->dev,
"Setting %s-duplex based on MII#%d link partner capability of %04x\n",
tp->full_duplex ? "full" : "half",
tp->phys[0], lpa);
return 1;
}
return 0;
}
void tulip_find_mii(struct net_device *dev, int board_idx)
{
struct tulip_private *tp = netdev_priv(dev);
int phyn, phy_idx = 0;
int mii_reg0;
int mii_advert;
unsigned int to_advert, new_bmcr, ane_switch;
for (phyn = 1; phyn <= 32 && phy_idx < sizeof (tp->phys); phyn++) {
int phy = phyn & 0x1f;
int mii_status = tulip_mdio_read (dev, phy, MII_BMSR);
if ((mii_status & 0x8301) == 0x8001 ||
((mii_status & BMSR_100BASE4) == 0 &&
(mii_status & 0x7800) != 0)) {
} else {
continue;
}
mii_reg0 = tulip_mdio_read (dev, phy, MII_BMCR);
mii_advert = tulip_mdio_read (dev, phy, MII_ADVERTISE);
ane_switch = 0;
if ((mii_advert & ADVERTISE_ALL) == 0) {
unsigned int tmpadv = tulip_mdio_read (dev, phy, MII_BMSR);
mii_advert = ((tmpadv >> 6) & 0x3e0) | 1;
}
if (tp->mii_advertise) {
tp->advertising[phy_idx] =
to_advert = tp->mii_advertise;
} else if (tp->advertising[phy_idx]) {
to_advert = tp->advertising[phy_idx];
} else {
tp->advertising[phy_idx] =
tp->mii_advertise =
to_advert = mii_advert;
}
tp->phys[phy_idx++] = phy;
pr_info("tulip%d: MII transceiver #%d config %04x status %04x advertising %04x\n",
board_idx, phy, mii_reg0, mii_status, mii_advert);
if (mii_advert != to_advert) {
pr_debug("tulip%d: Advertising %04x on PHY %d, previously advertising %04x\n",
board_idx, to_advert, phy, mii_advert);
tulip_mdio_write (dev, phy, 4, to_advert);
}
if (tp->default_port == 0) {
new_bmcr = mii_reg0 | BMCR_ANENABLE;
if (new_bmcr != mii_reg0) {
new_bmcr |= BMCR_ANRESTART;
ane_switch = 1;
}
}
else {
new_bmcr = mii_reg0 & ~BMCR_ANENABLE;
if (new_bmcr != mii_reg0)
ane_switch = 1;
}
new_bmcr &= ~(BMCR_CTST | BMCR_FULLDPLX | BMCR_ISOLATE |
BMCR_PDOWN | BMCR_SPEED100 | BMCR_LOOPBACK |
BMCR_RESET);
if (tp->full_duplex)
new_bmcr |= BMCR_FULLDPLX;
if (tulip_media_cap[tp->default_port] & MediaIs100)
new_bmcr |= BMCR_SPEED100;
if (new_bmcr != mii_reg0) {
if (ane_switch) {
tulip_mdio_write (dev, phy, MII_BMCR, new_bmcr);
udelay (10);
}
tulip_mdio_write (dev, phy, MII_BMCR, new_bmcr);
}
}
tp->mii_cnt = phy_idx;
if (tp->mtable && tp->mtable->has_mii && phy_idx == 0) {
pr_info("tulip%d: ***WARNING***: No MII transceiver found!\n",
board_idx);
tp->phys[0] = 1;
}
}
