static void *swap_buffer(void *bufaddr, int len)
{
int i;
unsigned int *buf = bufaddr;
for (i = 0; i < (len + 3) / 4; i++, buf++)
*buf = cpu_to_be32(*buf);
return bufaddr;
}
static netdev_tx_t
fec_enet_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct bufdesc *bdp;
void *bufaddr;
unsigned short status;
unsigned long flags;
if (!fep->link) {
return NETDEV_TX_BUSY;
}
spin_lock_irqsave(&fep->hw_lock, flags);
bdp = fep->cur_tx;
status = bdp->cbd_sc;
if (status & BD_ENET_TX_READY) {
printk("%s: tx queue full!.\n", ndev->name);
spin_unlock_irqrestore(&fep->hw_lock, flags);
return NETDEV_TX_BUSY;
}
status &= ~BD_ENET_TX_STATS;
bufaddr = skb->data;
bdp->cbd_datlen = skb->len;
if (((unsigned long) bufaddr) & FEC_ALIGNMENT) {
unsigned int index;
index = bdp - fep->tx_bd_base;
memcpy(fep->tx_bounce[index], skb->data, skb->len);
bufaddr = fep->tx_bounce[index];
}
if (id_entry->driver_data & FEC_QUIRK_SWAP_FRAME)
swap_buffer(bufaddr, skb->len);
fep->tx_skbuff[fep->skb_cur] = skb;
ndev->stats.tx_bytes += skb->len;
fep->skb_cur = (fep->skb_cur+1) & TX_RING_MOD_MASK;
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, bufaddr,
FEC_ENET_TX_FRSIZE, DMA_TO_DEVICE);
status |= (BD_ENET_TX_READY | BD_ENET_TX_INTR
| BD_ENET_TX_LAST | BD_ENET_TX_TC);
bdp->cbd_sc = status;
writel(0, fep->hwp + FEC_X_DES_ACTIVE);
if (status & BD_ENET_TX_WRAP)
bdp = fep->tx_bd_base;
else
bdp++;
if (bdp == fep->dirty_tx) {
fep->tx_full = 1;
netif_stop_queue(ndev);
}
fep->cur_tx = bdp;
skb_tx_timestamp(skb);
spin_unlock_irqrestore(&fep->hw_lock, flags);
return NETDEV_TX_OK;
}
static void
fec_restart(struct net_device *ndev, int duplex)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
int i;
u32 temp_mac[2];
u32 rcntl = OPT_FRAME_SIZE | 0x04;
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
memcpy(&temp_mac, ndev->dev_addr, ETH_ALEN);
writel(cpu_to_be32(temp_mac[0]), fep->hwp + FEC_ADDR_LOW);
writel(cpu_to_be32(temp_mac[1]), fep->hwp + FEC_ADDR_HIGH);
}
writel(0xffc00000, fep->hwp + FEC_IEVENT);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
#ifndef CONFIG_M5272
writel(0, fep->hwp + FEC_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_HASH_TABLE_LOW);
#endif
writel(PKT_MAXBLR_SIZE, fep->hwp + FEC_R_BUFF_SIZE);
writel(fep->bd_dma, fep->hwp + FEC_R_DES_START);
writel((unsigned long)fep->bd_dma + sizeof(struct bufdesc) * RX_RING_SIZE,
fep->hwp + FEC_X_DES_START);
fep->dirty_tx = fep->cur_tx = fep->tx_bd_base;
fep->cur_rx = fep->rx_bd_base;
fep->skb_cur = fep->skb_dirty = 0;
for (i = 0; i <= TX_RING_MOD_MASK; i++) {
if (fep->tx_skbuff[i]) {
dev_kfree_skb_any(fep->tx_skbuff[i]);
fep->tx_skbuff[i] = NULL;
}
}
if (duplex) {
writel(0x04, fep->hwp + FEC_X_CNTRL);
} else {
rcntl |= 0x02;
writel(0x0, fep->hwp + FEC_X_CNTRL);
}
fep->full_duplex = duplex;
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
rcntl |= 0x40000000 | 0x00000020;
if (fep->phy_interface == PHY_INTERFACE_MODE_RMII)
rcntl |= (1 << 8);
else
rcntl &= ~(1 << 8);
if (fep->phy_dev && fep->phy_dev->speed == SPEED_100)
rcntl &= ~(1 << 9);
else
rcntl |= (1 << 9);
} else {
#ifdef FEC_MIIGSK_ENR
if (id_entry->driver_data & FEC_QUIRK_USE_GASKET) {
writel(0, fep->hwp + FEC_MIIGSK_ENR);
while (readl(fep->hwp + FEC_MIIGSK_ENR) & 4)
udelay(1);
writel((fep->phy_interface == PHY_INTERFACE_MODE_RMII) ?
1 : 0, fep->hwp + FEC_MIIGSK_CFGR);
writel(2, fep->hwp + FEC_MIIGSK_ENR);
}
#endif
}
writel(rcntl, fep->hwp + FEC_R_CNTRL);
writel(2, fep->hwp + FEC_ECNTRL);
writel(0, fep->hwp + FEC_R_DES_ACTIVE);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
}
static void
fec_stop(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (fep->link) {
writel(1, fep->hwp + FEC_X_CNTRL);
udelay(10);
if (!(readl(fep->hwp + FEC_IEVENT) & FEC_ENET_GRA))
printk("fec_stop : Graceful transmit stop did not complete !\n");
}
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
}
static void
fec_timeout(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
ndev->stats.tx_errors++;
fec_restart(ndev, fep->full_duplex);
netif_wake_queue(ndev);
}
static void
fec_enet_tx(struct net_device *ndev)
{
struct fec_enet_private *fep;
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb;
fep = netdev_priv(ndev);
spin_lock(&fep->hw_lock);
bdp = fep->dirty_tx;
while (((status = bdp->cbd_sc) & BD_ENET_TX_READY) == 0) {
if (bdp == fep->cur_tx && fep->tx_full == 0)
break;
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_TX_FRSIZE, DMA_TO_DEVICE);
bdp->cbd_bufaddr = 0;
skb = fep->tx_skbuff[fep->skb_dirty];
if (status & (BD_ENET_TX_HB | BD_ENET_TX_LC |
BD_ENET_TX_RL | BD_ENET_TX_UN |
BD_ENET_TX_CSL)) {
ndev->stats.tx_errors++;
if (status & BD_ENET_TX_HB)
ndev->stats.tx_heartbeat_errors++;
if (status & BD_ENET_TX_LC)
ndev->stats.tx_window_errors++;
if (status & BD_ENET_TX_RL)
ndev->stats.tx_aborted_errors++;
if (status & BD_ENET_TX_UN)
ndev->stats.tx_fifo_errors++;
if (status & BD_ENET_TX_CSL)
ndev->stats.tx_carrier_errors++;
} else {
ndev->stats.tx_packets++;
}
if (status & BD_ENET_TX_READY)
printk("HEY! Enet xmit interrupt and TX_READY.\n");
if (status & BD_ENET_TX_DEF)
ndev->stats.collisions++;
dev_kfree_skb_any(skb);
fep->tx_skbuff[fep->skb_dirty] = NULL;
fep->skb_dirty = (fep->skb_dirty + 1) & TX_RING_MOD_MASK;
if (status & BD_ENET_TX_WRAP)
bdp = fep->tx_bd_base;
else
bdp++;
if (fep->tx_full) {
fep->tx_full = 0;
if (netif_queue_stopped(ndev))
netif_wake_queue(ndev);
}
}
fep->dirty_tx = bdp;
spin_unlock(&fep->hw_lock);
}
static void
fec_enet_rx(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb;
ushort pkt_len;
__u8 *data;
#ifdef CONFIG_M532x
flush_cache_all();
#endif
spin_lock(&fep->hw_lock);
bdp = fep->cur_rx;
while (!((status = bdp->cbd_sc) & BD_ENET_RX_EMPTY)) {
if ((status & BD_ENET_RX_LAST) == 0)
printk("FEC ENET: rcv is not +last\n");
if (!fep->opened)
goto rx_processing_done;
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH | BD_ENET_RX_NO |
BD_ENET_RX_CR | BD_ENET_RX_OV)) {
ndev->stats.rx_errors++;
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH)) {
ndev->stats.rx_length_errors++;
}
if (status & BD_ENET_RX_NO)
ndev->stats.rx_frame_errors++;
if (status & BD_ENET_RX_CR)
ndev->stats.rx_crc_errors++;
if (status & BD_ENET_RX_OV)
ndev->stats.rx_fifo_errors++;
}
if (status & BD_ENET_RX_CL) {
ndev->stats.rx_errors++;
ndev->stats.rx_frame_errors++;
goto rx_processing_done;
}
ndev->stats.rx_packets++;
pkt_len = bdp->cbd_datlen;
ndev->stats.rx_bytes += pkt_len;
data = (__u8*)__va(bdp->cbd_bufaddr);
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_TX_FRSIZE, DMA_FROM_DEVICE);
if (id_entry->driver_data & FEC_QUIRK_SWAP_FRAME)
swap_buffer(data, pkt_len);
skb = dev_alloc_skb(pkt_len - 4 + NET_IP_ALIGN);
if (unlikely(!skb)) {
printk("%s: Memory squeeze, dropping packet.\n",
ndev->name);
ndev->stats.rx_dropped++;
} else {
skb_reserve(skb, NET_IP_ALIGN);
skb_put(skb, pkt_len - 4);
skb_copy_to_linear_data(skb, data, pkt_len - 4);
skb->protocol = eth_type_trans(skb, ndev);
if (!skb_defer_rx_timestamp(skb))
netif_rx(skb);
}
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, data,
FEC_ENET_TX_FRSIZE, DMA_FROM_DEVICE);
rx_processing_done:
status &= ~BD_ENET_RX_STATS;
status |= BD_ENET_RX_EMPTY;
bdp->cbd_sc = status;
if (status & BD_ENET_RX_WRAP)
bdp = fep->rx_bd_base;
else
bdp++;
writel(0, fep->hwp + FEC_R_DES_ACTIVE);
}
fep->cur_rx = bdp;
spin_unlock(&fep->hw_lock);
}
static irqreturn_t
fec_enet_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct fec_enet_private *fep = netdev_priv(ndev);
uint int_events;
irqreturn_t ret = IRQ_NONE;
do {
int_events = readl(fep->hwp + FEC_IEVENT);
writel(int_events, fep->hwp + FEC_IEVENT);
if (int_events & FEC_ENET_RXF) {
ret = IRQ_HANDLED;
fec_enet_rx(ndev);
}
if (int_events & FEC_ENET_TXF) {
ret = IRQ_HANDLED;
fec_enet_tx(ndev);
}
if (int_events & FEC_ENET_MII) {
ret = IRQ_HANDLED;
complete(&fep->mdio_done);
}
} while (int_events);
return ret;
}
static void __inline__ fec_get_mac(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_platform_data *pdata = fep->pdev->dev.platform_data;
unsigned char *iap, tmpaddr[ETH_ALEN];
iap = macaddr;
#ifdef CONFIG_OF
if (!is_valid_ether_addr(iap)) {
struct device_node *np = fep->pdev->dev.of_node;
if (np) {
const char *mac = of_get_mac_address(np);
if (mac)
iap = (unsigned char *) mac;
}
}
#endif
if (!is_valid_ether_addr(iap)) {
#ifdef CONFIG_M5272
if (FEC_FLASHMAC)
iap = (unsigned char *)FEC_FLASHMAC;
#else
if (pdata)
memcpy(iap, pdata->mac, ETH_ALEN);
#endif
}
if (!is_valid_ether_addr(iap)) {
*((unsigned long *) &tmpaddr[0]) =
be32_to_cpu(readl(fep->hwp + FEC_ADDR_LOW));
*((unsigned short *) &tmpaddr[4]) =
be16_to_cpu(readl(fep->hwp + FEC_ADDR_HIGH) >> 16);
iap = &tmpaddr[0];
}
memcpy(ndev->dev_addr, iap, ETH_ALEN);
if (iap == macaddr)
ndev->dev_addr[ETH_ALEN-1] = macaddr[ETH_ALEN-1] + fep->pdev->id;
}
static void fec_enet_adjust_link(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phy_dev = fep->phy_dev;
unsigned long flags;
int status_change = 0;
spin_lock_irqsave(&fep->hw_lock, flags);
if (fep->mii_timeout && phy_dev->state == PHY_HALTED) {
phy_dev->state = PHY_RESUMING;
goto spin_unlock;
}
if (phy_dev->link) {
if (fep->full_duplex != phy_dev->duplex) {
fec_restart(ndev, phy_dev->duplex);
status_change = 1;
}
}
if (phy_dev->link != fep->link) {
fep->link = phy_dev->link;
if (phy_dev->link)
fec_restart(ndev, phy_dev->duplex);
else
fec_stop(ndev);
status_change = 1;
}
spin_unlock:
spin_unlock_irqrestore(&fep->hw_lock, flags);
if (status_change)
phy_print_status(phy_dev);
}
static int fec_enet_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct fec_enet_private *fep = bus->priv;
unsigned long time_left;
fep->mii_timeout = 0;
init_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_READ |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA, fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
printk(KERN_ERR "FEC: MDIO read timeout\n");
return -ETIMEDOUT;
}
return FEC_MMFR_DATA(readl(fep->hwp + FEC_MII_DATA));
}
static int fec_enet_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct fec_enet_private *fep = bus->priv;
unsigned long time_left;
fep->mii_timeout = 0;
init_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_WRITE |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA | FEC_MMFR_DATA(value),
fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
printk(KERN_ERR "FEC: MDIO write timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int fec_enet_mdio_reset(struct mii_bus *bus)
{
return 0;
}
static int fec_enet_mii_probe(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phy_dev = NULL;
char mdio_bus_id[MII_BUS_ID_SIZE];
char phy_name[MII_BUS_ID_SIZE + 3];
int phy_id;
int dev_id = fep->pdev->id;
fep->phy_dev = NULL;
for (phy_id = 0; (phy_id < PHY_MAX_ADDR); phy_id++) {
if ((fep->mii_bus->phy_mask & (1 << phy_id)))
continue;
if (fep->mii_bus->phy_map[phy_id] == NULL)
continue;
if (fep->mii_bus->phy_map[phy_id]->phy_id == 0)
continue;
if (dev_id--)
continue;
strncpy(mdio_bus_id, fep->mii_bus->id, MII_BUS_ID_SIZE);
break;
}
if (phy_id >= PHY_MAX_ADDR) {
printk(KERN_INFO "%s: no PHY, assuming direct connection "
"to switch\n", ndev->name);
strncpy(mdio_bus_id, "0", MII_BUS_ID_SIZE);
phy_id = 0;
}
snprintf(phy_name, MII_BUS_ID_SIZE, PHY_ID_FMT, mdio_bus_id, phy_id);
phy_dev = phy_connect(ndev, phy_name, &fec_enet_adjust_link, 0,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(phy_dev)) {
printk(KERN_ERR "%s: could not attach to PHY\n", ndev->name);
return PTR_ERR(phy_dev);
}
phy_dev->supported &= PHY_BASIC_FEATURES;
phy_dev->advertising = phy_dev->supported;
fep->phy_dev = phy_dev;
fep->link = 0;
fep->full_duplex = 0;
printk(KERN_INFO "%s: Freescale FEC PHY driver [%s] "
"(mii_bus:phy_addr=%s, irq=%d)\n", ndev->name,
fep->phy_dev->drv->name, dev_name(&fep->phy_dev->dev),
fep->phy_dev->irq);
return 0;
}
static int fec_enet_mii_init(struct platform_device *pdev)
{
static struct mii_bus *fec0_mii_bus;
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
int err = -ENXIO, i;
if ((id_entry->driver_data & FEC_QUIRK_ENET_MAC) && pdev->id) {
fep->mii_bus = fec0_mii_bus;
return 0;
}
fep->mii_timeout = 0;
fep->phy_speed = DIV_ROUND_UP(clk_get_rate(fep->clk), 5000000) << 1;
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
fep->mii_bus = mdiobus_alloc();
if (fep->mii_bus == NULL) {
err = -ENOMEM;
goto err_out;
}
fep->mii_bus->name = "fec_enet_mii_bus";
fep->mii_bus->read = fec_enet_mdio_read;
fep->mii_bus->write = fec_enet_mdio_write;
fep->mii_bus->reset = fec_enet_mdio_reset;
snprintf(fep->mii_bus->id, MII_BUS_ID_SIZE, "%x", pdev->id + 1);
fep->mii_bus->priv = fep;
fep->mii_bus->parent = &pdev->dev;
fep->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!fep->mii_bus->irq) {
err = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
fep->mii_bus->irq[i] = PHY_POLL;
if (mdiobus_register(fep->mii_bus))
goto err_out_free_mdio_irq;
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC)
fec0_mii_bus = fep->mii_bus;
return 0;
err_out_free_mdio_irq:
kfree(fep->mii_bus->irq);
err_out_free_mdiobus:
mdiobus_free(fep->mii_bus);
err_out:
return err;
}
static void fec_enet_mii_remove(struct fec_enet_private *fep)
{
if (fep->phy_dev)
phy_disconnect(fep->phy_dev);
mdiobus_unregister(fep->mii_bus);
kfree(fep->mii_bus->irq);
mdiobus_free(fep->mii_bus);
}
static int fec_enet_get_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_gset(phydev, cmd);
}
static int fec_enet_set_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, cmd);
}
static void fec_enet_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct fec_enet_private *fep = netdev_priv(ndev);
strcpy(info->driver, fep->pdev->dev.driver->name);
strcpy(info->version, "Revision: 1.0");
strcpy(info->bus_info, dev_name(&ndev->dev));
}
static int fec_enet_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
return phy_mii_ioctl(phydev, rq, cmd);
}
static void fec_enet_free_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
struct sk_buff *skb;
struct bufdesc *bdp;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
skb = fep->rx_skbuff[i];
if (bdp->cbd_bufaddr)
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_RX_FRSIZE, DMA_FROM_DEVICE);
if (skb)
dev_kfree_skb(skb);
bdp++;
}
bdp = fep->tx_bd_base;
for (i = 0; i < TX_RING_SIZE; i++)
kfree(fep->tx_bounce[i]);
}
static int fec_enet_alloc_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
struct sk_buff *skb;
struct bufdesc *bdp;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
skb = dev_alloc_skb(FEC_ENET_RX_FRSIZE);
if (!skb) {
fec_enet_free_buffers(ndev);
return -ENOMEM;
}
fep->rx_skbuff[i] = skb;
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, skb->data,
FEC_ENET_RX_FRSIZE, DMA_FROM_DEVICE);
bdp->cbd_sc = BD_ENET_RX_EMPTY;
bdp++;
}
bdp--;
bdp->cbd_sc |= BD_SC_WRAP;
bdp = fep->tx_bd_base;
for (i = 0; i < TX_RING_SIZE; i++) {
fep->tx_bounce[i] = kmalloc(FEC_ENET_TX_FRSIZE, GFP_KERNEL);
bdp->cbd_sc = 0;
bdp->cbd_bufaddr = 0;
bdp++;
}
bdp--;
bdp->cbd_sc |= BD_SC_WRAP;
return 0;
}
static int
fec_enet_open(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int ret;
ret = fec_enet_alloc_buffers(ndev);
if (ret)
return ret;
ret = fec_enet_mii_probe(ndev);
if (ret) {
fec_enet_free_buffers(ndev);
return ret;
}
phy_start(fep->phy_dev);
netif_start_queue(ndev);
fep->opened = 1;
return 0;
}
static int
fec_enet_close(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
fep->opened = 0;
netif_stop_queue(ndev);
fec_stop(ndev);
if (fep->phy_dev) {
phy_stop(fep->phy_dev);
phy_disconnect(fep->phy_dev);
}
fec_enet_free_buffers(ndev);
return 0;
}
static void set_multicast_list(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct netdev_hw_addr *ha;
unsigned int i, bit, data, crc, tmp;
unsigned char hash;
if (ndev->flags & IFF_PROMISC) {
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp |= 0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
return;
}
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp &= ~0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
if (ndev->flags & IFF_ALLMULTI) {
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
return;
}
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
netdev_for_each_mc_addr(ha, ndev) {
crc = 0xffffffff;
for (i = 0; i < ndev->addr_len; i++) {
data = ha->addr[i];
for (bit = 0; bit < 8; bit++, data >>= 1) {
crc = (crc >> 1) ^
(((crc ^ data) & 1) ? CRC32_POLY : 0);
}
}
hash = (crc >> (32 - HASH_BITS)) & 0x3f;
if (hash > 31) {
tmp = readl(fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
tmp |= 1 << (hash - 32);
writel(tmp, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
} else {
tmp = readl(fep->hwp + FEC_GRP_HASH_TABLE_LOW);
tmp |= 1 << hash;
writel(tmp, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
}
}
}
static int
fec_set_mac_address(struct net_device *ndev, void *p)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ndev->addr_len);
writel(ndev->dev_addr[3] | (ndev->dev_addr[2] << 8) |
(ndev->dev_addr[1] << 16) | (ndev->dev_addr[0] << 24),
fep->hwp + FEC_ADDR_LOW);
writel((ndev->dev_addr[5] << 16) | (ndev->dev_addr[4] << 24),
fep->hwp + FEC_ADDR_HIGH);
return 0;
}
static int fec_enet_init(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct bufdesc *cbd_base;
struct bufdesc *bdp;
int i;
cbd_base = dma_alloc_coherent(NULL, PAGE_SIZE, &fep->bd_dma,
GFP_KERNEL);
if (!cbd_base) {
printk("FEC: allocate descriptor memory failed?\n");
return -ENOMEM;
}
spin_lock_init(&fep->hw_lock);
fep->netdev = ndev;
fec_get_mac(ndev);
fep->rx_bd_base = cbd_base;
fep->tx_bd_base = cbd_base + RX_RING_SIZE;
ndev->watchdog_timeo = TX_TIMEOUT;
ndev->netdev_ops = &fec_netdev_ops;
ndev->ethtool_ops = &fec_enet_ethtool_ops;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
bdp->cbd_sc = 0;
bdp++;
}
bdp--;
bdp->cbd_sc |= BD_SC_WRAP;
bdp = fep->tx_bd_base;
for (i = 0; i < TX_RING_SIZE; i++) {
bdp->cbd_sc = 0;
bdp->cbd_bufaddr = 0;
bdp++;
}
bdp--;
bdp->cbd_sc |= BD_SC_WRAP;
fec_restart(ndev, 0);
return 0;
}
static int __devinit fec_get_phy_mode_dt(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
if (np)
return of_get_phy_mode(np);
return -ENODEV;
}
static int __devinit fec_reset_phy(struct platform_device *pdev)
{
int err, phy_reset;
struct device_node *np = pdev->dev.of_node;
if (!np)
return -ENODEV;
phy_reset = of_get_named_gpio(np, "phy-reset-gpios", 0);
err = gpio_request_one(phy_reset, GPIOF_OUT_INIT_LOW, "phy-reset");
if (err) {
pr_warn("FEC: failed to get gpio phy-reset: %d\n", err);
return err;
}
msleep(1);
gpio_set_value(phy_reset, 1);
return 0;
}
static inline int fec_get_phy_mode_dt(struct platform_device *pdev)
{
return -ENODEV;
}
static inline int fec_reset_phy(struct platform_device *pdev)
{
return 0;
}
static int __devinit
fec_probe(struct platform_device *pdev)
{
struct fec_enet_private *fep;
struct fec_platform_data *pdata;
struct net_device *ndev;
int i, irq, ret = 0;
struct resource *r;
const struct of_device_id *of_id;
of_id = of_match_device(fec_dt_ids, &pdev->dev);
if (of_id)
pdev->id_entry = of_id->data;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENXIO;
r = request_mem_region(r->start, resource_size(r), pdev->name);
if (!r)
return -EBUSY;
ndev = alloc_etherdev(sizeof(struct fec_enet_private));
if (!ndev) {
ret = -ENOMEM;
goto failed_alloc_etherdev;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
fep = netdev_priv(ndev);
fep->hwp = ioremap(r->start, resource_size(r));
fep->pdev = pdev;
if (!fep->hwp) {
ret = -ENOMEM;
goto failed_ioremap;
}
platform_set_drvdata(pdev, ndev);
ret = fec_get_phy_mode_dt(pdev);
if (ret < 0) {
pdata = pdev->dev.platform_data;
if (pdata)
fep->phy_interface = pdata->phy;
else
fep->phy_interface = PHY_INTERFACE_MODE_MII;
} else {
fep->phy_interface = ret;
}
fec_reset_phy(pdev);
for (i = 0; i < 3; i++) {
irq = platform_get_irq(pdev, i);
if (i && irq < 0)
break;
ret = request_irq(irq, fec_enet_interrupt, IRQF_DISABLED, pdev->name, ndev);
if (ret) {
while (--i >= 0) {
irq = platform_get_irq(pdev, i);
free_irq(irq, ndev);
}
goto failed_irq;
}
}
fep->clk = clk_get(&pdev->dev, "fec_clk");
if (IS_ERR(fep->clk)) {
ret = PTR_ERR(fep->clk);
goto failed_clk;
}
clk_enable(fep->clk);
ret = fec_enet_init(ndev);
if (ret)
goto failed_init;
ret = fec_enet_mii_init(pdev);
if (ret)
goto failed_mii_init;
netif_carrier_off(ndev);
ret = register_netdev(ndev);
if (ret)
goto failed_register;
return 0;
failed_register:
fec_enet_mii_remove(fep);
failed_mii_init:
failed_init:
clk_disable(fep->clk);
clk_put(fep->clk);
failed_clk:
for (i = 0; i < 3; i++) {
irq = platform_get_irq(pdev, i);
if (irq > 0)
free_irq(irq, ndev);
}
failed_irq:
iounmap(fep->hwp);
failed_ioremap:
free_netdev(ndev);
failed_alloc_etherdev:
release_mem_region(r->start, resource_size(r));
return ret;
}
static int __devexit
fec_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
struct resource *r;
fec_stop(ndev);
fec_enet_mii_remove(fep);
clk_disable(fep->clk);
clk_put(fep->clk);
iounmap(fep->hwp);
unregister_netdev(ndev);
free_netdev(ndev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
BUG_ON(!r);
release_mem_region(r->start, resource_size(r));
platform_set_drvdata(pdev, NULL);
return 0;
}
static int
fec_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
if (netif_running(ndev)) {
fec_stop(ndev);
netif_device_detach(ndev);
}
clk_disable(fep->clk);
return 0;
}
static int
fec_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
clk_enable(fep->clk);
if (netif_running(ndev)) {
fec_restart(ndev, fep->full_duplex);
netif_device_attach(ndev);
}
return 0;
}
static int __init
fec_enet_module_init(void)
{
printk(KERN_INFO "FEC Ethernet Driver\n");
return platform_driver_register(&fec_driver);
}
static void __exit
fec_enet_cleanup(void)
{
platform_driver_unregister(&fec_driver);
}
