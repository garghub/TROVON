static int sis900_get_mac_addr(struct pci_dev *pci_dev,
struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u16 signature;
int i;
signature = (u16) read_eeprom(ioaddr, EEPROMSignature);
if (signature == 0xffff || signature == 0x0000) {
printk (KERN_WARNING "%s: Error EERPOM read %x\n",
pci_name(pci_dev), signature);
return 0;
}
for (i = 0; i < 3; i++)
((u16 *)(net_dev->dev_addr))[i] = read_eeprom(ioaddr, i+EEPROMMACAddr);
return 1;
}
static int sis630e_get_mac_addr(struct pci_dev *pci_dev,
struct net_device *net_dev)
{
struct pci_dev *isa_bridge = NULL;
u8 reg;
int i;
isa_bridge = pci_get_device(PCI_VENDOR_ID_SI, 0x0008, isa_bridge);
if (!isa_bridge)
isa_bridge = pci_get_device(PCI_VENDOR_ID_SI, 0x0018, isa_bridge);
if (!isa_bridge) {
printk(KERN_WARNING "%s: Can not find ISA bridge\n",
pci_name(pci_dev));
return 0;
}
pci_read_config_byte(isa_bridge, 0x48, &reg);
pci_write_config_byte(isa_bridge, 0x48, reg | 0x40);
for (i = 0; i < 6; i++) {
outb(0x09 + i, 0x70);
((u8 *)(net_dev->dev_addr))[i] = inb(0x71);
}
pci_write_config_byte(isa_bridge, 0x48, reg & ~0x40);
pci_dev_put(isa_bridge);
return 1;
}
static int sis635_get_mac_addr(struct pci_dev *pci_dev,
struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u32 rfcrSave;
u32 i;
rfcrSave = sr32(rfcr);
sw32(cr, rfcrSave | RELOAD);
sw32(cr, 0);
sw32(rfcr, rfcrSave & ~RFEN);
for (i = 0 ; i < 3 ; i++) {
sw32(rfcr, (i << RFADDR_shift));
*( ((u16 *)net_dev->dev_addr) + i) = sr16(rfdr);
}
sw32(rfcr, rfcrSave | RFEN);
return 1;
}
static int sis96x_get_mac_addr(struct pci_dev *pci_dev,
struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
int wait, rc = 0;
sw32(mear, EEREQ);
for (wait = 0; wait < 2000; wait++) {
if (sr32(mear) & EEGNT) {
u16 *mac = (u16 *)net_dev->dev_addr;
int i;
for (i = 0; i < 3; i++)
mac[i] = read_eeprom(ioaddr, i + EEPROMMACAddr);
rc = 1;
break;
}
udelay(1);
}
sw32(mear, EEDONE);
return rc;
}
static int sis900_probe(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
struct sis900_private *sis_priv;
struct net_device *net_dev;
struct pci_dev *dev;
dma_addr_t ring_dma;
void *ring_space;
void __iomem *ioaddr;
int i, ret;
const char *card_name = card_names[pci_id->driver_data];
const char *dev_name = pci_name(pci_dev);
#ifndef MODULE
static int printed_version;
if (!printed_version++)
printk(version);
#endif
ret = pci_enable_device(pci_dev);
if(ret) return ret;
i = pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32));
if(i){
printk(KERN_ERR "sis900.c: architecture does not support "
"32bit PCI busmaster DMA\n");
return i;
}
pci_set_master(pci_dev);
net_dev = alloc_etherdev(sizeof(struct sis900_private));
if (!net_dev)
return -ENOMEM;
SET_NETDEV_DEV(net_dev, &pci_dev->dev);
ret = pci_request_regions(pci_dev, "sis900");
if (ret)
goto err_out;
ioaddr = pci_iomap(pci_dev, 0, 0);
if (!ioaddr) {
ret = -ENOMEM;
goto err_out_cleardev;
}
sis_priv = netdev_priv(net_dev);
sis_priv->ioaddr = ioaddr;
sis_priv->pci_dev = pci_dev;
spin_lock_init(&sis_priv->lock);
pci_set_drvdata(pci_dev, net_dev);
ring_space = pci_alloc_consistent(pci_dev, TX_TOTAL_SIZE, &ring_dma);
if (!ring_space) {
ret = -ENOMEM;
goto err_out_unmap;
}
sis_priv->tx_ring = ring_space;
sis_priv->tx_ring_dma = ring_dma;
ring_space = pci_alloc_consistent(pci_dev, RX_TOTAL_SIZE, &ring_dma);
if (!ring_space) {
ret = -ENOMEM;
goto err_unmap_tx;
}
sis_priv->rx_ring = ring_space;
sis_priv->rx_ring_dma = ring_dma;
net_dev->netdev_ops = &sis900_netdev_ops;
net_dev->watchdog_timeo = TX_TIMEOUT;
net_dev->ethtool_ops = &sis900_ethtool_ops;
if (sis900_debug > 0)
sis_priv->msg_enable = sis900_debug;
else
sis_priv->msg_enable = SIS900_DEF_MSG;
sis_priv->mii_info.dev = net_dev;
sis_priv->mii_info.mdio_read = mdio_read;
sis_priv->mii_info.mdio_write = mdio_write;
sis_priv->mii_info.phy_id_mask = 0x1f;
sis_priv->mii_info.reg_num_mask = 0x1f;
sis_priv->chipset_rev = pci_dev->revision;
if(netif_msg_probe(sis_priv))
printk(KERN_DEBUG "%s: detected revision %2.2x, "
"trying to get MAC address...\n",
dev_name, sis_priv->chipset_rev);
ret = 0;
if (sis_priv->chipset_rev == SIS630E_900_REV)
ret = sis630e_get_mac_addr(pci_dev, net_dev);
else if ((sis_priv->chipset_rev > 0x81) && (sis_priv->chipset_rev <= 0x90) )
ret = sis635_get_mac_addr(pci_dev, net_dev);
else if (sis_priv->chipset_rev == SIS96x_900_REV)
ret = sis96x_get_mac_addr(pci_dev, net_dev);
else
ret = sis900_get_mac_addr(pci_dev, net_dev);
if (!ret || !is_valid_ether_addr(net_dev->dev_addr)) {
eth_hw_addr_random(net_dev);
printk(KERN_WARNING "%s: Unreadable or invalid MAC address,"
"using random generated one\n", dev_name);
}
if (sis_priv->chipset_rev == SIS630ET_900_REV)
sw32(cr, ACCESSMODE | sr32(cr));
if (sis900_mii_probe(net_dev) == 0) {
printk(KERN_WARNING "%s: Error probing MII device.\n",
dev_name);
ret = -ENODEV;
goto err_unmap_rx;
}
dev = pci_get_device(PCI_VENDOR_ID_SI, PCI_DEVICE_ID_SI_630, NULL);
if (dev) {
sis_priv->host_bridge_rev = dev->revision;
pci_dev_put(dev);
}
ret = register_netdev(net_dev);
if (ret)
goto err_unmap_rx;
printk(KERN_INFO "%s: %s at 0x%p, IRQ %d, %pM\n",
net_dev->name, card_name, ioaddr, pci_dev->irq,
net_dev->dev_addr);
ret = (sr32(CFGPMC) & PMESP) >> 27;
if (netif_msg_probe(sis_priv) && (ret & PME_D3C) == 0)
printk(KERN_INFO "%s: Wake on LAN only available from suspend to RAM.", net_dev->name);
return 0;
err_unmap_rx:
pci_free_consistent(pci_dev, RX_TOTAL_SIZE, sis_priv->rx_ring,
sis_priv->rx_ring_dma);
err_unmap_tx:
pci_free_consistent(pci_dev, TX_TOTAL_SIZE, sis_priv->tx_ring,
sis_priv->tx_ring_dma);
err_out_unmap:
pci_iounmap(pci_dev, ioaddr);
err_out_cleardev:
pci_set_drvdata(pci_dev, NULL);
pci_release_regions(pci_dev);
err_out:
free_netdev(net_dev);
return ret;
}
static int sis900_mii_probe(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
const char *dev_name = pci_name(sis_priv->pci_dev);
u16 poll_bit = MII_STAT_LINK, status = 0;
unsigned long timeout = jiffies + 5 * HZ;
int phy_addr;
sis_priv->mii = NULL;
for (phy_addr = 0; phy_addr < 32; phy_addr++) {
struct mii_phy * mii_phy = NULL;
u16 mii_status;
int i;
mii_phy = NULL;
for(i = 0; i < 2; i++)
mii_status = mdio_read(net_dev, phy_addr, MII_STATUS);
if (mii_status == 0xffff || mii_status == 0x0000) {
if (netif_msg_probe(sis_priv))
printk(KERN_DEBUG "%s: MII at address %d"
" not accessible\n",
dev_name, phy_addr);
continue;
}
if ((mii_phy = kmalloc(sizeof(struct mii_phy), GFP_KERNEL)) == NULL) {
mii_phy = sis_priv->first_mii;
while (mii_phy) {
struct mii_phy *phy;
phy = mii_phy;
mii_phy = mii_phy->next;
kfree(phy);
}
return 0;
}
mii_phy->phy_id0 = mdio_read(net_dev, phy_addr, MII_PHY_ID0);
mii_phy->phy_id1 = mdio_read(net_dev, phy_addr, MII_PHY_ID1);
mii_phy->phy_addr = phy_addr;
mii_phy->status = mii_status;
mii_phy->next = sis_priv->mii;
sis_priv->mii = mii_phy;
sis_priv->first_mii = mii_phy;
for (i = 0; mii_chip_table[i].phy_id1; i++)
if ((mii_phy->phy_id0 == mii_chip_table[i].phy_id0 ) &&
((mii_phy->phy_id1 & 0xFFF0) == mii_chip_table[i].phy_id1)){
mii_phy->phy_types = mii_chip_table[i].phy_types;
if (mii_chip_table[i].phy_types == MIX)
mii_phy->phy_types =
(mii_status & (MII_STAT_CAN_TX_FDX | MII_STAT_CAN_TX)) ? LAN : HOME;
printk(KERN_INFO "%s: %s transceiver found "
"at address %d.\n",
dev_name,
mii_chip_table[i].name,
phy_addr);
break;
}
if( !mii_chip_table[i].phy_id1 ) {
printk(KERN_INFO "%s: Unknown PHY transceiver found at address %d.\n",
dev_name, phy_addr);
mii_phy->phy_types = UNKNOWN;
}
}
if (sis_priv->mii == NULL) {
printk(KERN_INFO "%s: No MII transceivers found!\n", dev_name);
return 0;
}
sis_priv->mii = NULL;
sis900_default_phy( net_dev );
if ((sis_priv->mii->phy_id0 == 0x001D) &&
((sis_priv->mii->phy_id1&0xFFF0) == 0x8000))
status = sis900_reset_phy(net_dev, sis_priv->cur_phy);
if ((sis_priv->mii->phy_id0 == 0x0015) &&
((sis_priv->mii->phy_id1&0xFFF0) == 0xF440))
mdio_write(net_dev, sis_priv->cur_phy, 0x0018, 0xD200);
if(status & MII_STAT_LINK){
while (poll_bit) {
yield();
poll_bit ^= (mdio_read(net_dev, sis_priv->cur_phy, MII_STATUS) & poll_bit);
if (time_after_eq(jiffies, timeout)) {
printk(KERN_WARNING "%s: reset phy and link down now\n",
dev_name);
return -ETIME;
}
}
}
if (sis_priv->chipset_rev == SIS630E_900_REV) {
mdio_write(net_dev, sis_priv->cur_phy, MII_ANADV, 0x05e1);
mdio_write(net_dev, sis_priv->cur_phy, MII_CONFIG1, 0x22);
mdio_write(net_dev, sis_priv->cur_phy, MII_CONFIG2, 0xff00);
mdio_write(net_dev, sis_priv->cur_phy, MII_MASK, 0xffc0);
}
if (sis_priv->mii->status & MII_STAT_LINK)
netif_carrier_on(net_dev);
else
netif_carrier_off(net_dev);
return 1;
}
static u16 sis900_default_phy(struct net_device * net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
struct mii_phy *phy = NULL, *phy_home = NULL,
*default_phy = NULL, *phy_lan = NULL;
u16 status;
for (phy=sis_priv->first_mii; phy; phy=phy->next) {
status = mdio_read(net_dev, phy->phy_addr, MII_STATUS);
status = mdio_read(net_dev, phy->phy_addr, MII_STATUS);
if ((status & MII_STAT_LINK) && !default_phy &&
(phy->phy_types != UNKNOWN))
default_phy = phy;
else {
status = mdio_read(net_dev, phy->phy_addr, MII_CONTROL);
mdio_write(net_dev, phy->phy_addr, MII_CONTROL,
status | MII_CNTL_AUTO | MII_CNTL_ISOLATE);
if (phy->phy_types == HOME)
phy_home = phy;
else if(phy->phy_types == LAN)
phy_lan = phy;
}
}
if (!default_phy && phy_home)
default_phy = phy_home;
else if (!default_phy && phy_lan)
default_phy = phy_lan;
else if (!default_phy)
default_phy = sis_priv->first_mii;
if (sis_priv->mii != default_phy) {
sis_priv->mii = default_phy;
sis_priv->cur_phy = default_phy->phy_addr;
printk(KERN_INFO "%s: Using transceiver found at address %d as default\n",
pci_name(sis_priv->pci_dev), sis_priv->cur_phy);
}
sis_priv->mii_info.phy_id = sis_priv->cur_phy;
status = mdio_read(net_dev, sis_priv->cur_phy, MII_CONTROL);
status &= (~MII_CNTL_ISOLATE);
mdio_write(net_dev, sis_priv->cur_phy, MII_CONTROL, status);
status = mdio_read(net_dev, sis_priv->cur_phy, MII_STATUS);
status = mdio_read(net_dev, sis_priv->cur_phy, MII_STATUS);
return status;
}
static void sis900_set_capability(struct net_device *net_dev, struct mii_phy *phy)
{
u16 cap;
u16 status;
status = mdio_read(net_dev, phy->phy_addr, MII_STATUS);
status = mdio_read(net_dev, phy->phy_addr, MII_STATUS);
cap = MII_NWAY_CSMA_CD |
((phy->status & MII_STAT_CAN_TX_FDX)? MII_NWAY_TX_FDX:0) |
((phy->status & MII_STAT_CAN_TX) ? MII_NWAY_TX:0) |
((phy->status & MII_STAT_CAN_T_FDX) ? MII_NWAY_T_FDX:0)|
((phy->status & MII_STAT_CAN_T) ? MII_NWAY_T:0);
mdio_write(net_dev, phy->phy_addr, MII_ANADV, cap);
}
static u16 read_eeprom(void __iomem *ioaddr, int location)
{
u32 read_cmd = location | EEread;
int i;
u16 retval = 0;
sw32(mear, 0);
eeprom_delay();
sw32(mear, EECS);
eeprom_delay();
for (i = 8; i >= 0; i--) {
u32 dataval = (read_cmd & (1 << i)) ? EEDI | EECS : EECS;
sw32(mear, dataval);
eeprom_delay();
sw32(mear, dataval | EECLK);
eeprom_delay();
}
sw32(mear, EECS);
eeprom_delay();
for (i = 16; i > 0; i--) {
sw32(mear, EECS);
eeprom_delay();
sw32(mear, EECS | EECLK);
eeprom_delay();
retval = (retval << 1) | ((sr32(mear) & EEDO) ? 1 : 0);
eeprom_delay();
}
sw32(mear, 0);
eeprom_delay();
return retval;
}
static void mdio_idle(struct sis900_private *sp)
{
void __iomem *ioaddr = sp->ioaddr;
sw32(mear, MDIO | MDDIR);
mdio_delay();
sw32(mear, MDIO | MDDIR | MDC);
}
static void mdio_reset(struct sis900_private *sp)
{
void __iomem *ioaddr = sp->ioaddr;
int i;
for (i = 31; i >= 0; i--) {
sw32(mear, MDDIR | MDIO);
mdio_delay();
sw32(mear, MDDIR | MDIO | MDC);
mdio_delay();
}
}
static int mdio_read(struct net_device *net_dev, int phy_id, int location)
{
int mii_cmd = MIIread|(phy_id<<MIIpmdShift)|(location<<MIIregShift);
struct sis900_private *sp = netdev_priv(net_dev);
void __iomem *ioaddr = sp->ioaddr;
u16 retval = 0;
int i;
mdio_reset(sp);
mdio_idle(sp);
for (i = 15; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDDIR | MDIO : MDDIR;
sw32(mear, dataval);
mdio_delay();
sw32(mear, dataval | MDC);
mdio_delay();
}
for (i = 16; i > 0; i--) {
sw32(mear, 0);
mdio_delay();
retval = (retval << 1) | ((sr32(mear) & MDIO) ? 1 : 0);
sw32(mear, MDC);
mdio_delay();
}
sw32(mear, 0x00);
return retval;
}
static void mdio_write(struct net_device *net_dev, int phy_id, int location,
int value)
{
int mii_cmd = MIIwrite|(phy_id<<MIIpmdShift)|(location<<MIIregShift);
struct sis900_private *sp = netdev_priv(net_dev);
void __iomem *ioaddr = sp->ioaddr;
int i;
mdio_reset(sp);
mdio_idle(sp);
for (i = 15; i >= 0; i--) {
int dataval = (mii_cmd & (1 << i)) ? MDDIR | MDIO : MDDIR;
sw8(mear, dataval);
mdio_delay();
sw8(mear, dataval | MDC);
mdio_delay();
}
mdio_delay();
for (i = 15; i >= 0; i--) {
int dataval = (value & (1 << i)) ? MDDIR | MDIO : MDDIR;
sw32(mear, dataval);
mdio_delay();
sw32(mear, dataval | MDC);
mdio_delay();
}
mdio_delay();
for (i = 2; i > 0; i--) {
sw8(mear, 0);
mdio_delay();
sw8(mear, MDC);
mdio_delay();
}
sw32(mear, 0x00);
}
static u16 sis900_reset_phy(struct net_device *net_dev, int phy_addr)
{
int i;
u16 status;
for (i = 0; i < 2; i++)
status = mdio_read(net_dev, phy_addr, MII_STATUS);
mdio_write( net_dev, phy_addr, MII_CONTROL, MII_CNTL_RESET );
return status;
}
static void sis900_poll(struct net_device *dev)
{
struct sis900_private *sp = netdev_priv(dev);
const int irq = sp->pci_dev->irq;
disable_irq(irq);
sis900_interrupt(irq, dev);
enable_irq(irq);
}
static int
sis900_open(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
int ret;
sis900_reset(net_dev);
sis630_set_eq(net_dev, sis_priv->chipset_rev);
ret = request_irq(sis_priv->pci_dev->irq, sis900_interrupt, IRQF_SHARED,
net_dev->name, net_dev);
if (ret)
return ret;
sis900_init_rxfilter(net_dev);
sis900_init_tx_ring(net_dev);
sis900_init_rx_ring(net_dev);
set_rx_mode(net_dev);
netif_start_queue(net_dev);
sis900_set_mode(sis_priv, HW_SPEED_10_MBPS, FDX_CAPABLE_HALF_SELECTED);
sw32(imr, RxSOVR | RxORN | RxERR | RxOK | TxURN | TxERR | TxIDLE);
sw32(cr, RxENA | sr32(cr));
sw32(ier, IE);
sis900_check_mode(net_dev, sis_priv->mii);
init_timer(&sis_priv->timer);
sis_priv->timer.expires = jiffies + HZ;
sis_priv->timer.data = (unsigned long)net_dev;
sis_priv->timer.function = sis900_timer;
add_timer(&sis_priv->timer);
return 0;
}
static void
sis900_init_rxfilter (struct net_device * net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u32 rfcrSave;
u32 i;
rfcrSave = sr32(rfcr);
sw32(rfcr, rfcrSave & ~RFEN);
for (i = 0 ; i < 3 ; i++) {
u32 w = (u32) *((u16 *)(net_dev->dev_addr)+i);
sw32(rfcr, i << RFADDR_shift);
sw32(rfdr, w);
if (netif_msg_hw(sis_priv)) {
printk(KERN_DEBUG "%s: Receive Filter Addrss[%d]=%x\n",
net_dev->name, i, sr32(rfdr));
}
}
sw32(rfcr, rfcrSave | RFEN);
}
static void
sis900_init_tx_ring(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
int i;
sis_priv->tx_full = 0;
sis_priv->dirty_tx = sis_priv->cur_tx = 0;
for (i = 0; i < NUM_TX_DESC; i++) {
sis_priv->tx_skbuff[i] = NULL;
sis_priv->tx_ring[i].link = sis_priv->tx_ring_dma +
((i+1)%NUM_TX_DESC)*sizeof(BufferDesc);
sis_priv->tx_ring[i].cmdsts = 0;
sis_priv->tx_ring[i].bufptr = 0;
}
sw32(txdp, sis_priv->tx_ring_dma);
if (netif_msg_hw(sis_priv))
printk(KERN_DEBUG "%s: TX descriptor register loaded with: %8.8x\n",
net_dev->name, sr32(txdp));
}
static void
sis900_init_rx_ring(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
int i;
sis_priv->cur_rx = 0;
sis_priv->dirty_rx = 0;
for (i = 0; i < NUM_RX_DESC; i++) {
sis_priv->rx_skbuff[i] = NULL;
sis_priv->rx_ring[i].link = sis_priv->rx_ring_dma +
((i+1)%NUM_RX_DESC)*sizeof(BufferDesc);
sis_priv->rx_ring[i].cmdsts = 0;
sis_priv->rx_ring[i].bufptr = 0;
}
for (i = 0; i < NUM_RX_DESC; i++) {
struct sk_buff *skb;
if ((skb = netdev_alloc_skb(net_dev, RX_BUF_SIZE)) == NULL) {
break;
}
sis_priv->rx_skbuff[i] = skb;
sis_priv->rx_ring[i].cmdsts = RX_BUF_SIZE;
sis_priv->rx_ring[i].bufptr = pci_map_single(sis_priv->pci_dev,
skb->data, RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
if (unlikely(pci_dma_mapping_error(sis_priv->pci_dev,
sis_priv->rx_ring[i].bufptr))) {
dev_kfree_skb(skb);
sis_priv->rx_skbuff[i] = NULL;
break;
}
}
sis_priv->dirty_rx = (unsigned int) (i - NUM_RX_DESC);
sw32(rxdp, sis_priv->rx_ring_dma);
if (netif_msg_hw(sis_priv))
printk(KERN_DEBUG "%s: RX descriptor register loaded with: %8.8x\n",
net_dev->name, sr32(rxdp));
}
static void sis630_set_eq(struct net_device *net_dev, u8 revision)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
u16 reg14h, eq_value=0, max_value=0, min_value=0;
int i, maxcount=10;
if ( !(revision == SIS630E_900_REV || revision == SIS630EA1_900_REV ||
revision == SIS630A_900_REV || revision == SIS630ET_900_REV) )
return;
if (netif_carrier_ok(net_dev)) {
reg14h = mdio_read(net_dev, sis_priv->cur_phy, MII_RESV);
mdio_write(net_dev, sis_priv->cur_phy, MII_RESV,
(0x2200 | reg14h) & 0xBFFF);
for (i=0; i < maxcount; i++) {
eq_value = (0x00F8 & mdio_read(net_dev,
sis_priv->cur_phy, MII_RESV)) >> 3;
if (i == 0)
max_value=min_value=eq_value;
max_value = (eq_value > max_value) ?
eq_value : max_value;
min_value = (eq_value < min_value) ?
eq_value : min_value;
}
if (revision == SIS630E_900_REV || revision == SIS630EA1_900_REV ||
revision == SIS630ET_900_REV) {
if (max_value < 5)
eq_value = max_value;
else if (max_value >= 5 && max_value < 15)
eq_value = (max_value == min_value) ?
max_value+2 : max_value+1;
else if (max_value >= 15)
eq_value=(max_value == min_value) ?
max_value+6 : max_value+5;
}
if (revision == SIS630A_900_REV &&
(sis_priv->host_bridge_rev == SIS630B0 ||
sis_priv->host_bridge_rev == SIS630B1)) {
if (max_value == 0)
eq_value = 3;
else
eq_value = (max_value + min_value + 1)/2;
}
reg14h = mdio_read(net_dev, sis_priv->cur_phy, MII_RESV);
reg14h = (reg14h & 0xFF07) | ((eq_value << 3) & 0x00F8);
reg14h = (reg14h | 0x6000) & 0xFDFF;
mdio_write(net_dev, sis_priv->cur_phy, MII_RESV, reg14h);
} else {
reg14h = mdio_read(net_dev, sis_priv->cur_phy, MII_RESV);
if (revision == SIS630A_900_REV &&
(sis_priv->host_bridge_rev == SIS630B0 ||
sis_priv->host_bridge_rev == SIS630B1))
mdio_write(net_dev, sis_priv->cur_phy, MII_RESV,
(reg14h | 0x2200) & 0xBFFF);
else
mdio_write(net_dev, sis_priv->cur_phy, MII_RESV,
(reg14h | 0x2000) & 0xBFFF);
}
}
static void sis900_timer(unsigned long data)
{
struct net_device *net_dev = (struct net_device *)data;
struct sis900_private *sis_priv = netdev_priv(net_dev);
struct mii_phy *mii_phy = sis_priv->mii;
static const int next_tick = 5*HZ;
int speed = 0, duplex = 0;
u16 status;
status = mdio_read(net_dev, sis_priv->cur_phy, MII_STATUS);
status = mdio_read(net_dev, sis_priv->cur_phy, MII_STATUS);
if (!netif_carrier_ok(net_dev)) {
LookForLink:
status = sis900_default_phy(net_dev);
mii_phy = sis_priv->mii;
if (status & MII_STAT_LINK) {
WARN_ON(!(status & MII_STAT_AUTO_DONE));
sis900_read_mode(net_dev, &speed, &duplex);
if (duplex) {
sis900_set_mode(sis_priv, speed, duplex);
sis630_set_eq(net_dev, sis_priv->chipset_rev);
netif_carrier_on(net_dev);
}
}
} else {
if (!(status & MII_STAT_LINK)){
netif_carrier_off(net_dev);
if(netif_msg_link(sis_priv))
printk(KERN_INFO "%s: Media Link Off\n", net_dev->name);
if ((mii_phy->phy_id0 == 0x001D) &&
((mii_phy->phy_id1 & 0xFFF0) == 0x8000))
sis900_reset_phy(net_dev, sis_priv->cur_phy);
sis630_set_eq(net_dev, sis_priv->chipset_rev);
goto LookForLink;
}
}
sis_priv->timer.expires = jiffies + next_tick;
add_timer(&sis_priv->timer);
}
static void sis900_check_mode(struct net_device *net_dev, struct mii_phy *mii_phy)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
int speed, duplex;
if (mii_phy->phy_types == LAN) {
sw32(cfg, ~EXD & sr32(cfg));
sis900_set_capability(net_dev , mii_phy);
sis900_auto_negotiate(net_dev, sis_priv->cur_phy);
} else {
sw32(cfg, EXD | sr32(cfg));
speed = HW_SPEED_HOME;
duplex = FDX_CAPABLE_HALF_SELECTED;
sis900_set_mode(sis_priv, speed, duplex);
sis_priv->autong_complete = 1;
}
}
static void sis900_set_mode(struct sis900_private *sp, int speed, int duplex)
{
void __iomem *ioaddr = sp->ioaddr;
u32 tx_flags = 0, rx_flags = 0;
if (sr32( cfg) & EDB_MASTER_EN) {
tx_flags = TxATP | (DMA_BURST_64 << TxMXDMA_shift) |
(TX_FILL_THRESH << TxFILLT_shift);
rx_flags = DMA_BURST_64 << RxMXDMA_shift;
} else {
tx_flags = TxATP | (DMA_BURST_512 << TxMXDMA_shift) |
(TX_FILL_THRESH << TxFILLT_shift);
rx_flags = DMA_BURST_512 << RxMXDMA_shift;
}
if (speed == HW_SPEED_HOME || speed == HW_SPEED_10_MBPS) {
rx_flags |= (RxDRNT_10 << RxDRNT_shift);
tx_flags |= (TxDRNT_10 << TxDRNT_shift);
} else {
rx_flags |= (RxDRNT_100 << RxDRNT_shift);
tx_flags |= (TxDRNT_100 << TxDRNT_shift);
}
if (duplex == FDX_CAPABLE_FULL_SELECTED) {
tx_flags |= (TxCSI | TxHBI);
rx_flags |= RxATX;
}
#if defined(CONFIG_VLAN_8021Q) || defined(CONFIG_VLAN_8021Q_MODULE)
rx_flags |= RxAJAB;
#endif
sw32(txcfg, tx_flags);
sw32(rxcfg, rx_flags);
}
static void sis900_auto_negotiate(struct net_device *net_dev, int phy_addr)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
int i = 0;
u32 status;
for (i = 0; i < 2; i++)
status = mdio_read(net_dev, phy_addr, MII_STATUS);
if (!(status & MII_STAT_LINK)){
if(netif_msg_link(sis_priv))
printk(KERN_INFO "%s: Media Link Off\n", net_dev->name);
sis_priv->autong_complete = 1;
netif_carrier_off(net_dev);
return;
}
mdio_write(net_dev, phy_addr, MII_CONTROL,
MII_CNTL_AUTO | MII_CNTL_RST_AUTO);
sis_priv->autong_complete = 0;
}
static void sis900_read_mode(struct net_device *net_dev, int *speed, int *duplex)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
struct mii_phy *phy = sis_priv->mii;
int phy_addr = sis_priv->cur_phy;
u32 status;
u16 autoadv, autorec;
int i;
for (i = 0; i < 2; i++)
status = mdio_read(net_dev, phy_addr, MII_STATUS);
if (!(status & MII_STAT_LINK))
return;
autoadv = mdio_read(net_dev, phy_addr, MII_ANADV);
autorec = mdio_read(net_dev, phy_addr, MII_ANLPAR);
status = autoadv & autorec;
*speed = HW_SPEED_10_MBPS;
*duplex = FDX_CAPABLE_HALF_SELECTED;
if (status & (MII_NWAY_TX | MII_NWAY_TX_FDX))
*speed = HW_SPEED_100_MBPS;
if (status & ( MII_NWAY_TX_FDX | MII_NWAY_T_FDX))
*duplex = FDX_CAPABLE_FULL_SELECTED;
sis_priv->autong_complete = 1;
if ((phy->phy_id0 == 0x0000) && ((phy->phy_id1 & 0xFFF0) == 0x8200)) {
if (mdio_read(net_dev, phy_addr, MII_CONTROL) & MII_CNTL_FDX)
*duplex = FDX_CAPABLE_FULL_SELECTED;
if (mdio_read(net_dev, phy_addr, 0x0019) & 0x01)
*speed = HW_SPEED_100_MBPS;
}
if(netif_msg_link(sis_priv))
printk(KERN_INFO "%s: Media Link On %s %s-duplex\n",
net_dev->name,
*speed == HW_SPEED_100_MBPS ?
"100mbps" : "10mbps",
*duplex == FDX_CAPABLE_FULL_SELECTED ?
"full" : "half");
}
static void sis900_tx_timeout(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
unsigned long flags;
int i;
if (netif_msg_tx_err(sis_priv)) {
printk(KERN_INFO "%s: Transmit timeout, status %8.8x %8.8x\n",
net_dev->name, sr32(cr), sr32(isr));
}
sw32(imr, 0x0000);
spin_lock_irqsave(&sis_priv->lock, flags);
sis_priv->dirty_tx = sis_priv->cur_tx = 0;
for (i = 0; i < NUM_TX_DESC; i++) {
struct sk_buff *skb = sis_priv->tx_skbuff[i];
if (skb) {
pci_unmap_single(sis_priv->pci_dev,
sis_priv->tx_ring[i].bufptr, skb->len,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
sis_priv->tx_skbuff[i] = NULL;
sis_priv->tx_ring[i].cmdsts = 0;
sis_priv->tx_ring[i].bufptr = 0;
net_dev->stats.tx_dropped++;
}
}
sis_priv->tx_full = 0;
netif_wake_queue(net_dev);
spin_unlock_irqrestore(&sis_priv->lock, flags);
net_dev->trans_start = jiffies;
sw32(txdp, sis_priv->tx_ring_dma);
sw32(imr, RxSOVR | RxORN | RxERR | RxOK | TxURN | TxERR | TxIDLE);
}
static netdev_tx_t
sis900_start_xmit(struct sk_buff *skb, struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
unsigned int entry;
unsigned long flags;
unsigned int index_cur_tx, index_dirty_tx;
unsigned int count_dirty_tx;
spin_lock_irqsave(&sis_priv->lock, flags);
entry = sis_priv->cur_tx % NUM_TX_DESC;
sis_priv->tx_skbuff[entry] = skb;
sis_priv->tx_ring[entry].bufptr = pci_map_single(sis_priv->pci_dev,
skb->data, skb->len, PCI_DMA_TODEVICE);
if (unlikely(pci_dma_mapping_error(sis_priv->pci_dev,
sis_priv->tx_ring[entry].bufptr))) {
dev_kfree_skb(skb);
sis_priv->tx_skbuff[entry] = NULL;
net_dev->stats.tx_dropped++;
spin_unlock_irqrestore(&sis_priv->lock, flags);
return NETDEV_TX_OK;
}
sis_priv->tx_ring[entry].cmdsts = (OWN | skb->len);
sw32(cr, TxENA | sr32(cr));
sis_priv->cur_tx ++;
index_cur_tx = sis_priv->cur_tx;
index_dirty_tx = sis_priv->dirty_tx;
for (count_dirty_tx = 0; index_cur_tx != index_dirty_tx; index_dirty_tx++)
count_dirty_tx ++;
if (index_cur_tx == index_dirty_tx) {
sis_priv->tx_full = 1;
netif_stop_queue(net_dev);
} else if (count_dirty_tx < NUM_TX_DESC) {
netif_start_queue(net_dev);
} else {
sis_priv->tx_full = 1;
netif_stop_queue(net_dev);
}
spin_unlock_irqrestore(&sis_priv->lock, flags);
if (netif_msg_tx_queued(sis_priv))
printk(KERN_DEBUG "%s: Queued Tx packet at %p size %d "
"to slot %d.\n",
net_dev->name, skb->data, (int)skb->len, entry);
return NETDEV_TX_OK;
}
static irqreturn_t sis900_interrupt(int irq, void *dev_instance)
{
struct net_device *net_dev = dev_instance;
struct sis900_private *sis_priv = netdev_priv(net_dev);
int boguscnt = max_interrupt_work;
void __iomem *ioaddr = sis_priv->ioaddr;
u32 status;
unsigned int handled = 0;
spin_lock (&sis_priv->lock);
do {
status = sr32(isr);
if ((status & (HIBERR|TxURN|TxERR|TxIDLE|RxORN|RxERR|RxOK)) == 0)
break;
handled = 1;
if (status & (RxORN | RxERR | RxOK))
sis900_rx(net_dev);
if (status & (TxURN | TxERR | TxIDLE))
sis900_finish_xmit(net_dev);
if (status & HIBERR) {
if(netif_msg_intr(sis_priv))
printk(KERN_INFO "%s: Abnormal interrupt, "
"status %#8.8x.\n", net_dev->name, status);
break;
}
if (--boguscnt < 0) {
if(netif_msg_intr(sis_priv))
printk(KERN_INFO "%s: Too much work at interrupt, "
"interrupt status = %#8.8x.\n",
net_dev->name, status);
break;
}
} while (1);
if(netif_msg_intr(sis_priv))
printk(KERN_DEBUG "%s: exiting interrupt, "
"interrupt status = %#8.8x\n",
net_dev->name, sr32(isr));
spin_unlock (&sis_priv->lock);
return IRQ_RETVAL(handled);
}
static int sis900_rx(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
unsigned int entry = sis_priv->cur_rx % NUM_RX_DESC;
u32 rx_status = sis_priv->rx_ring[entry].cmdsts;
int rx_work_limit;
if (netif_msg_rx_status(sis_priv))
printk(KERN_DEBUG "sis900_rx, cur_rx:%4.4d, dirty_rx:%4.4d "
"status:0x%8.8x\n",
sis_priv->cur_rx, sis_priv->dirty_rx, rx_status);
rx_work_limit = sis_priv->dirty_rx + NUM_RX_DESC - sis_priv->cur_rx;
while (rx_status & OWN) {
unsigned int rx_size;
unsigned int data_size;
if (--rx_work_limit < 0)
break;
data_size = rx_status & DSIZE;
rx_size = data_size - CRC_SIZE;
#if defined(CONFIG_VLAN_8021Q) || defined(CONFIG_VLAN_8021Q_MODULE)
if ((rx_status & TOOLONG) && data_size <= MAX_FRAME_SIZE)
rx_status &= (~ ((unsigned int)TOOLONG));
#endif
if (rx_status & (ABORT|OVERRUN|TOOLONG|RUNT|RXISERR|CRCERR|FAERR)) {
if (netif_msg_rx_err(sis_priv))
printk(KERN_DEBUG "%s: Corrupted packet "
"received, buffer status = 0x%8.8x/%d.\n",
net_dev->name, rx_status, data_size);
net_dev->stats.rx_errors++;
if (rx_status & OVERRUN)
net_dev->stats.rx_over_errors++;
if (rx_status & (TOOLONG|RUNT))
net_dev->stats.rx_length_errors++;
if (rx_status & (RXISERR | FAERR))
net_dev->stats.rx_frame_errors++;
if (rx_status & CRCERR)
net_dev->stats.rx_crc_errors++;
sis_priv->rx_ring[entry].cmdsts = RX_BUF_SIZE;
} else {
struct sk_buff * skb;
struct sk_buff * rx_skb;
pci_unmap_single(sis_priv->pci_dev,
sis_priv->rx_ring[entry].bufptr, RX_BUF_SIZE,
PCI_DMA_FROMDEVICE);
if ((skb = netdev_alloc_skb(net_dev, RX_BUF_SIZE)) == NULL) {
skb = sis_priv->rx_skbuff[entry];
net_dev->stats.rx_dropped++;
goto refill_rx_ring;
}
if (sis_priv->rx_skbuff[entry] == NULL) {
if (netif_msg_rx_err(sis_priv))
printk(KERN_WARNING "%s: NULL pointer "
"encountered in Rx ring\n"
"cur_rx:%4.4d, dirty_rx:%4.4d\n",
net_dev->name, sis_priv->cur_rx,
sis_priv->dirty_rx);
dev_kfree_skb(skb);
break;
}
rx_skb = sis_priv->rx_skbuff[entry];
skb_put(rx_skb, rx_size);
rx_skb->protocol = eth_type_trans(rx_skb, net_dev);
netif_rx(rx_skb);
if ((rx_status & BCAST) == MCAST)
net_dev->stats.multicast++;
net_dev->stats.rx_bytes += rx_size;
net_dev->stats.rx_packets++;
sis_priv->dirty_rx++;
refill_rx_ring:
sis_priv->rx_skbuff[entry] = skb;
sis_priv->rx_ring[entry].cmdsts = RX_BUF_SIZE;
sis_priv->rx_ring[entry].bufptr =
pci_map_single(sis_priv->pci_dev, skb->data,
RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
if (unlikely(pci_dma_mapping_error(sis_priv->pci_dev,
sis_priv->rx_ring[entry].bufptr))) {
dev_kfree_skb_irq(skb);
sis_priv->rx_skbuff[entry] = NULL;
break;
}
}
sis_priv->cur_rx++;
entry = sis_priv->cur_rx % NUM_RX_DESC;
rx_status = sis_priv->rx_ring[entry].cmdsts;
}
for (; sis_priv->cur_rx != sis_priv->dirty_rx; sis_priv->dirty_rx++) {
struct sk_buff *skb;
entry = sis_priv->dirty_rx % NUM_RX_DESC;
if (sis_priv->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb(net_dev, RX_BUF_SIZE);
if (skb == NULL) {
net_dev->stats.rx_dropped++;
break;
}
sis_priv->rx_skbuff[entry] = skb;
sis_priv->rx_ring[entry].cmdsts = RX_BUF_SIZE;
sis_priv->rx_ring[entry].bufptr =
pci_map_single(sis_priv->pci_dev, skb->data,
RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
if (unlikely(pci_dma_mapping_error(sis_priv->pci_dev,
sis_priv->rx_ring[entry].bufptr))) {
dev_kfree_skb_irq(skb);
sis_priv->rx_skbuff[entry] = NULL;
break;
}
}
}
sw32(cr , RxENA | sr32(cr));
return 0;
}
static void sis900_finish_xmit (struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
for (; sis_priv->dirty_tx != sis_priv->cur_tx; sis_priv->dirty_tx++) {
struct sk_buff *skb;
unsigned int entry;
u32 tx_status;
entry = sis_priv->dirty_tx % NUM_TX_DESC;
tx_status = sis_priv->tx_ring[entry].cmdsts;
if (tx_status & OWN) {
break;
}
if (tx_status & (ABORT | UNDERRUN | OWCOLL)) {
if (netif_msg_tx_err(sis_priv))
printk(KERN_DEBUG "%s: Transmit "
"error, Tx status %8.8x.\n",
net_dev->name, tx_status);
net_dev->stats.tx_errors++;
if (tx_status & UNDERRUN)
net_dev->stats.tx_fifo_errors++;
if (tx_status & ABORT)
net_dev->stats.tx_aborted_errors++;
if (tx_status & NOCARRIER)
net_dev->stats.tx_carrier_errors++;
if (tx_status & OWCOLL)
net_dev->stats.tx_window_errors++;
} else {
net_dev->stats.collisions += (tx_status & COLCNT) >> 16;
net_dev->stats.tx_bytes += tx_status & DSIZE;
net_dev->stats.tx_packets++;
}
skb = sis_priv->tx_skbuff[entry];
pci_unmap_single(sis_priv->pci_dev,
sis_priv->tx_ring[entry].bufptr, skb->len,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
sis_priv->tx_skbuff[entry] = NULL;
sis_priv->tx_ring[entry].bufptr = 0;
sis_priv->tx_ring[entry].cmdsts = 0;
}
if (sis_priv->tx_full && netif_queue_stopped(net_dev) &&
sis_priv->cur_tx - sis_priv->dirty_tx < NUM_TX_DESC - 4) {
sis_priv->tx_full = 0;
netif_wake_queue (net_dev);
}
}
static int sis900_close(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
struct pci_dev *pdev = sis_priv->pci_dev;
void __iomem *ioaddr = sis_priv->ioaddr;
struct sk_buff *skb;
int i;
netif_stop_queue(net_dev);
sw32(imr, 0x0000);
sw32(ier, 0x0000);
sw32(cr, RxDIS | TxDIS | sr32(cr));
del_timer(&sis_priv->timer);
free_irq(pdev->irq, net_dev);
for (i = 0; i < NUM_RX_DESC; i++) {
skb = sis_priv->rx_skbuff[i];
if (skb) {
pci_unmap_single(pdev, sis_priv->rx_ring[i].bufptr,
RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
dev_kfree_skb(skb);
sis_priv->rx_skbuff[i] = NULL;
}
}
for (i = 0; i < NUM_TX_DESC; i++) {
skb = sis_priv->tx_skbuff[i];
if (skb) {
pci_unmap_single(pdev, sis_priv->tx_ring[i].bufptr,
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb(skb);
sis_priv->tx_skbuff[i] = NULL;
}
}
return 0;
}
static void sis900_get_drvinfo(struct net_device *net_dev,
struct ethtool_drvinfo *info)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
strlcpy(info->driver, SIS900_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, SIS900_DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(sis_priv->pci_dev),
sizeof(info->bus_info));
}
static u32 sis900_get_msglevel(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
return sis_priv->msg_enable;
}
static void sis900_set_msglevel(struct net_device *net_dev, u32 value)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
sis_priv->msg_enable = value;
}
static u32 sis900_get_link(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
return mii_link_ok(&sis_priv->mii_info);
}
static int sis900_get_settings(struct net_device *net_dev,
struct ethtool_cmd *cmd)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
spin_lock_irq(&sis_priv->lock);
mii_ethtool_gset(&sis_priv->mii_info, cmd);
spin_unlock_irq(&sis_priv->lock);
return 0;
}
static int sis900_set_settings(struct net_device *net_dev,
struct ethtool_cmd *cmd)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
int rt;
spin_lock_irq(&sis_priv->lock);
rt = mii_ethtool_sset(&sis_priv->mii_info, cmd);
spin_unlock_irq(&sis_priv->lock);
return rt;
}
static int sis900_nway_reset(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
return mii_nway_restart(&sis_priv->mii_info);
}
static int sis900_set_wol(struct net_device *net_dev, struct ethtool_wolinfo *wol)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u32 cfgpmcsr = 0, pmctrl_bits = 0;
if (wol->wolopts == 0) {
pci_read_config_dword(sis_priv->pci_dev, CFGPMCSR, &cfgpmcsr);
cfgpmcsr &= ~PME_EN;
pci_write_config_dword(sis_priv->pci_dev, CFGPMCSR, cfgpmcsr);
sw32(pmctrl, pmctrl_bits);
if (netif_msg_wol(sis_priv))
printk(KERN_DEBUG "%s: Wake on LAN disabled\n", net_dev->name);
return 0;
}
if (wol->wolopts & (WAKE_MAGICSECURE | WAKE_UCAST | WAKE_MCAST
| WAKE_BCAST | WAKE_ARP))
return -EINVAL;
if (wol->wolopts & WAKE_MAGIC)
pmctrl_bits |= MAGICPKT;
if (wol->wolopts & WAKE_PHY)
pmctrl_bits |= LINKON;
sw32(pmctrl, pmctrl_bits);
pci_read_config_dword(sis_priv->pci_dev, CFGPMCSR, &cfgpmcsr);
cfgpmcsr |= PME_EN;
pci_write_config_dword(sis_priv->pci_dev, CFGPMCSR, cfgpmcsr);
if (netif_msg_wol(sis_priv))
printk(KERN_DEBUG "%s: Wake on LAN enabled\n", net_dev->name);
return 0;
}
static void sis900_get_wol(struct net_device *net_dev, struct ethtool_wolinfo *wol)
{
struct sis900_private *sp = netdev_priv(net_dev);
void __iomem *ioaddr = sp->ioaddr;
u32 pmctrl_bits;
pmctrl_bits = sr32(pmctrl);
if (pmctrl_bits & MAGICPKT)
wol->wolopts |= WAKE_MAGIC;
if (pmctrl_bits & LINKON)
wol->wolopts |= WAKE_PHY;
wol->supported = (WAKE_PHY | WAKE_MAGIC);
}
static int mii_ioctl(struct net_device *net_dev, struct ifreq *rq, int cmd)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
struct mii_ioctl_data *data = if_mii(rq);
switch(cmd) {
case SIOCGMIIPHY:
data->phy_id = sis_priv->mii->phy_addr;
case SIOCGMIIREG:
data->val_out = mdio_read(net_dev, data->phy_id & 0x1f, data->reg_num & 0x1f);
return 0;
case SIOCSMIIREG:
mdio_write(net_dev, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in);
return 0;
default:
return -EOPNOTSUPP;
}
}
static int sis900_set_config(struct net_device *dev, struct ifmap *map)
{
struct sis900_private *sis_priv = netdev_priv(dev);
struct mii_phy *mii_phy = sis_priv->mii;
u16 status;
if ((map->port != (u_char)(-1)) && (map->port != dev->if_port)) {
switch(map->port){
case IF_PORT_UNKNOWN:
dev->if_port = map->port;
netif_carrier_off(dev);
status = mdio_read(dev, mii_phy->phy_addr, MII_CONTROL);
mdio_write(dev, mii_phy->phy_addr,
MII_CONTROL, status | MII_CNTL_AUTO | MII_CNTL_RST_AUTO);
break;
case IF_PORT_10BASET:
dev->if_port = map->port;
netif_carrier_off(dev);
status = mdio_read(dev, mii_phy->phy_addr, MII_CONTROL);
mdio_write(dev, mii_phy->phy_addr,
MII_CONTROL, status & ~(MII_CNTL_SPEED |
MII_CNTL_AUTO));
break;
case IF_PORT_100BASET:
case IF_PORT_100BASETX:
dev->if_port = map->port;
netif_carrier_off(dev);
status = mdio_read(dev, mii_phy->phy_addr, MII_CONTROL);
mdio_write(dev, mii_phy->phy_addr,
MII_CONTROL, (status & ~MII_CNTL_SPEED) |
MII_CNTL_SPEED);
break;
case IF_PORT_10BASE2:
case IF_PORT_AUI:
case IF_PORT_100BASEFX:
return -EOPNOTSUPP;
break;
default:
return -EINVAL;
}
}
return 0;
}
static inline u16 sis900_mcast_bitnr(u8 *addr, u8 revision)
{
u32 crc = ether_crc(6, addr);
if ((revision >= SIS635A_900_REV) || (revision == SIS900B_900_REV))
return (int)(crc >> 24);
else
return (int)(crc >> 25);
}
static void set_rx_mode(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u16 mc_filter[16] = {0};
int i, table_entries;
u32 rx_mode;
if((sis_priv->chipset_rev >= SIS635A_900_REV) ||
(sis_priv->chipset_rev == SIS900B_900_REV))
table_entries = 16;
else
table_entries = 8;
if (net_dev->flags & IFF_PROMISC) {
rx_mode = RFPromiscuous;
for (i = 0; i < table_entries; i++)
mc_filter[i] = 0xffff;
} else if ((netdev_mc_count(net_dev) > multicast_filter_limit) ||
(net_dev->flags & IFF_ALLMULTI)) {
rx_mode = RFAAB | RFAAM;
for (i = 0; i < table_entries; i++)
mc_filter[i] = 0xffff;
} else {
struct netdev_hw_addr *ha;
rx_mode = RFAAB;
netdev_for_each_mc_addr(ha, net_dev) {
unsigned int bit_nr;
bit_nr = sis900_mcast_bitnr(ha->addr,
sis_priv->chipset_rev);
mc_filter[bit_nr >> 4] |= (1 << (bit_nr & 0xf));
}
}
for (i = 0; i < table_entries; i++) {
sw32(rfcr, (u32)(0x00000004 + i) << RFADDR_shift);
sw32(rfdr, mc_filter[i]);
}
sw32(rfcr, RFEN | rx_mode);
if (net_dev->flags & IFF_LOOPBACK) {
u32 cr_saved;
cr_saved = sr32(cr);
sw32(cr, cr_saved | TxDIS | RxDIS);
sw32(txcfg, sr32(txcfg) | TxMLB);
sw32(rxcfg, sr32(rxcfg) | RxATX);
sw32(cr, cr_saved);
}
}
static void sis900_reset(struct net_device *net_dev)
{
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
u32 status = TxRCMP | RxRCMP;
int i;
sw32(ier, 0);
sw32(imr, 0);
sw32(rfcr, 0);
sw32(cr, RxRESET | TxRESET | RESET | sr32(cr));
for (i = 0; status && (i < 1000); i++)
status ^= sr32(isr) & status;
if (sis_priv->chipset_rev >= SIS635A_900_REV ||
sis_priv->chipset_rev == SIS900B_900_REV)
sw32(cfg, PESEL | RND_CNT);
else
sw32(cfg, PESEL);
}
static void sis900_remove(struct pci_dev *pci_dev)
{
struct net_device *net_dev = pci_get_drvdata(pci_dev);
struct sis900_private *sis_priv = netdev_priv(net_dev);
unregister_netdev(net_dev);
while (sis_priv->first_mii) {
struct mii_phy *phy = sis_priv->first_mii;
sis_priv->first_mii = phy->next;
kfree(phy);
}
pci_free_consistent(pci_dev, RX_TOTAL_SIZE, sis_priv->rx_ring,
sis_priv->rx_ring_dma);
pci_free_consistent(pci_dev, TX_TOTAL_SIZE, sis_priv->tx_ring,
sis_priv->tx_ring_dma);
pci_iounmap(pci_dev, sis_priv->ioaddr);
free_netdev(net_dev);
pci_release_regions(pci_dev);
pci_set_drvdata(pci_dev, NULL);
}
static int sis900_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
struct net_device *net_dev = pci_get_drvdata(pci_dev);
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
if(!netif_running(net_dev))
return 0;
netif_stop_queue(net_dev);
netif_device_detach(net_dev);
sw32(cr, RxDIS | TxDIS | sr32(cr));
pci_set_power_state(pci_dev, PCI_D3hot);
pci_save_state(pci_dev);
return 0;
}
static int sis900_resume(struct pci_dev *pci_dev)
{
struct net_device *net_dev = pci_get_drvdata(pci_dev);
struct sis900_private *sis_priv = netdev_priv(net_dev);
void __iomem *ioaddr = sis_priv->ioaddr;
if(!netif_running(net_dev))
return 0;
pci_restore_state(pci_dev);
pci_set_power_state(pci_dev, PCI_D0);
sis900_init_rxfilter(net_dev);
sis900_init_tx_ring(net_dev);
sis900_init_rx_ring(net_dev);
set_rx_mode(net_dev);
netif_device_attach(net_dev);
netif_start_queue(net_dev);
sis900_set_mode(sis_priv, HW_SPEED_10_MBPS, FDX_CAPABLE_HALF_SELECTED);
sw32(imr, RxSOVR | RxORN | RxERR | RxOK | TxURN | TxERR | TxIDLE);
sw32(cr, RxENA | sr32(cr));
sw32(ier, IE);
sis900_check_mode(net_dev, sis_priv->mii);
return 0;
}
static int __init sis900_init_module(void)
{
#ifdef MODULE
printk(version);
#endif
return pci_register_driver(&sis900_pci_driver);
}
static void __exit sis900_cleanup_module(void)
{
pci_unregister_driver(&sis900_pci_driver);
}
