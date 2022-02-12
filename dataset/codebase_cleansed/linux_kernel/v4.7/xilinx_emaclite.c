static void xemaclite_enable_interrupts(struct net_local *drvdata)
{
u32 reg_data;
reg_data = __raw_readl(drvdata->base_addr + XEL_TSR_OFFSET);
__raw_writel(reg_data | XEL_TSR_XMIT_IE_MASK,
drvdata->base_addr + XEL_TSR_OFFSET);
__raw_writel(XEL_RSR_RECV_IE_MASK, drvdata->base_addr + XEL_RSR_OFFSET);
__raw_writel(XEL_GIER_GIE_MASK, drvdata->base_addr + XEL_GIER_OFFSET);
}
static void xemaclite_disable_interrupts(struct net_local *drvdata)
{
u32 reg_data;
__raw_writel(XEL_GIER_GIE_MASK, drvdata->base_addr + XEL_GIER_OFFSET);
reg_data = __raw_readl(drvdata->base_addr + XEL_TSR_OFFSET);
__raw_writel(reg_data & (~XEL_TSR_XMIT_IE_MASK),
drvdata->base_addr + XEL_TSR_OFFSET);
reg_data = __raw_readl(drvdata->base_addr + XEL_RSR_OFFSET);
__raw_writel(reg_data & (~XEL_RSR_RECV_IE_MASK),
drvdata->base_addr + XEL_RSR_OFFSET);
}
static void xemaclite_aligned_write(void *src_ptr, u32 *dest_ptr,
unsigned length)
{
u32 align_buffer;
u32 *to_u32_ptr;
u16 *from_u16_ptr, *to_u16_ptr;
to_u32_ptr = dest_ptr;
from_u16_ptr = src_ptr;
align_buffer = 0;
for (; length > 3; length -= 4) {
to_u16_ptr = (u16 *)&align_buffer;
*to_u16_ptr++ = *from_u16_ptr++;
*to_u16_ptr++ = *from_u16_ptr++;
wmb();
*to_u32_ptr++ = align_buffer;
}
if (length) {
u8 *from_u8_ptr, *to_u8_ptr;
align_buffer = 0;
to_u8_ptr = (u8 *) &align_buffer;
from_u8_ptr = (u8 *) from_u16_ptr;
for (; length > 0; length--)
*to_u8_ptr++ = *from_u8_ptr++;
wmb();
*to_u32_ptr = align_buffer;
}
}
static void xemaclite_aligned_read(u32 *src_ptr, u8 *dest_ptr,
unsigned length)
{
u16 *to_u16_ptr, *from_u16_ptr;
u32 *from_u32_ptr;
u32 align_buffer;
from_u32_ptr = src_ptr;
to_u16_ptr = (u16 *) dest_ptr;
for (; length > 3; length -= 4) {
align_buffer = *from_u32_ptr++;
from_u16_ptr = (u16 *)&align_buffer;
*to_u16_ptr++ = *from_u16_ptr++;
*to_u16_ptr++ = *from_u16_ptr++;
}
if (length) {
u8 *to_u8_ptr, *from_u8_ptr;
to_u8_ptr = (u8 *) to_u16_ptr;
align_buffer = *from_u32_ptr++;
from_u8_ptr = (u8 *) &align_buffer;
for (; length > 0; length--)
*to_u8_ptr = *from_u8_ptr;
}
}
static int xemaclite_send_data(struct net_local *drvdata, u8 *data,
unsigned int byte_count)
{
u32 reg_data;
void __iomem *addr;
addr = drvdata->base_addr + drvdata->next_tx_buf_to_use;
if (byte_count > ETH_FRAME_LEN)
byte_count = ETH_FRAME_LEN;
reg_data = __raw_readl(addr + XEL_TSR_OFFSET);
if ((reg_data & (XEL_TSR_XMIT_BUSY_MASK |
XEL_TSR_XMIT_ACTIVE_MASK)) == 0) {
if (drvdata->tx_ping_pong != 0)
drvdata->next_tx_buf_to_use ^= XEL_BUFFER_OFFSET;
} else if (drvdata->tx_ping_pong != 0) {
addr = (void __iomem __force *)((u32 __force)addr ^
XEL_BUFFER_OFFSET);
reg_data = __raw_readl(addr + XEL_TSR_OFFSET);
if ((reg_data & (XEL_TSR_XMIT_BUSY_MASK |
XEL_TSR_XMIT_ACTIVE_MASK)) != 0)
return -1;
} else
return -1;
xemaclite_aligned_write(data, (u32 __force *) addr, byte_count);
__raw_writel((byte_count & XEL_TPLR_LENGTH_MASK),
addr + XEL_TPLR_OFFSET);
reg_data = __raw_readl(addr + XEL_TSR_OFFSET);
reg_data |= (XEL_TSR_XMIT_BUSY_MASK | XEL_TSR_XMIT_ACTIVE_MASK);
__raw_writel(reg_data, addr + XEL_TSR_OFFSET);
return 0;
}
static u16 xemaclite_recv_data(struct net_local *drvdata, u8 *data)
{
void __iomem *addr;
u16 length, proto_type;
u32 reg_data;
addr = (drvdata->base_addr + drvdata->next_rx_buf_to_use);
reg_data = __raw_readl(addr + XEL_RSR_OFFSET);
if ((reg_data & XEL_RSR_RECV_DONE_MASK) == XEL_RSR_RECV_DONE_MASK) {
if (drvdata->rx_ping_pong != 0)
drvdata->next_rx_buf_to_use ^= XEL_BUFFER_OFFSET;
} else {
if (drvdata->rx_ping_pong != 0)
addr = (void __iomem __force *)((u32 __force)addr ^
XEL_BUFFER_OFFSET);
else
return 0;
reg_data = __raw_readl(addr + XEL_RSR_OFFSET);
if ((reg_data & XEL_RSR_RECV_DONE_MASK) !=
XEL_RSR_RECV_DONE_MASK)
return 0;
}
proto_type = ((ntohl(__raw_readl(addr + XEL_HEADER_OFFSET +
XEL_RXBUFF_OFFSET)) >> XEL_HEADER_SHIFT) &
XEL_RPLR_LENGTH_MASK);
if (proto_type > (ETH_FRAME_LEN + ETH_FCS_LEN)) {
if (proto_type == ETH_P_IP) {
length = ((ntohl(__raw_readl(addr +
XEL_HEADER_IP_LENGTH_OFFSET +
XEL_RXBUFF_OFFSET)) >>
XEL_HEADER_SHIFT) &
XEL_RPLR_LENGTH_MASK);
length += ETH_HLEN + ETH_FCS_LEN;
} else if (proto_type == ETH_P_ARP)
length = XEL_ARP_PACKET_SIZE + ETH_HLEN + ETH_FCS_LEN;
else
length = ETH_FRAME_LEN + ETH_FCS_LEN;
} else
length = proto_type + ETH_HLEN + ETH_FCS_LEN;
xemaclite_aligned_read((u32 __force *) (addr + XEL_RXBUFF_OFFSET),
data, length);
reg_data = __raw_readl(addr + XEL_RSR_OFFSET);
reg_data &= ~XEL_RSR_RECV_DONE_MASK;
__raw_writel(reg_data, addr + XEL_RSR_OFFSET);
return length;
}
static void xemaclite_update_address(struct net_local *drvdata,
u8 *address_ptr)
{
void __iomem *addr;
u32 reg_data;
addr = drvdata->base_addr + drvdata->next_tx_buf_to_use;
xemaclite_aligned_write(address_ptr, (u32 __force *) addr, ETH_ALEN);
__raw_writel(ETH_ALEN, addr + XEL_TPLR_OFFSET);
reg_data = __raw_readl(addr + XEL_TSR_OFFSET);
__raw_writel(reg_data | XEL_TSR_PROG_MAC_ADDR, addr + XEL_TSR_OFFSET);
while ((__raw_readl(addr + XEL_TSR_OFFSET) &
XEL_TSR_PROG_MAC_ADDR) != 0)
;
}
static int xemaclite_set_mac_address(struct net_device *dev, void *address)
{
struct net_local *lp = netdev_priv(dev);
struct sockaddr *addr = address;
if (netif_running(dev))
return -EBUSY;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
xemaclite_update_address(lp, dev->dev_addr);
return 0;
}
static void xemaclite_tx_timeout(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
dev_err(&lp->ndev->dev, "Exceeded transmit timeout of %lu ms\n",
TX_TIMEOUT * 1000UL / HZ);
dev->stats.tx_errors++;
spin_lock_irqsave(&lp->reset_lock, flags);
netif_stop_queue(dev);
xemaclite_disable_interrupts(lp);
xemaclite_enable_interrupts(lp);
if (lp->deferred_skb) {
dev_kfree_skb(lp->deferred_skb);
lp->deferred_skb = NULL;
dev->stats.tx_errors++;
}
netif_trans_update(dev);
netif_wake_queue(dev);
spin_unlock_irqrestore(&lp->reset_lock, flags);
}
static void xemaclite_tx_handler(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
dev->stats.tx_packets++;
if (lp->deferred_skb) {
if (xemaclite_send_data(lp,
(u8 *) lp->deferred_skb->data,
lp->deferred_skb->len) != 0)
return;
else {
dev->stats.tx_bytes += lp->deferred_skb->len;
dev_kfree_skb_irq(lp->deferred_skb);
lp->deferred_skb = NULL;
netif_trans_update(dev);
netif_wake_queue(dev);
}
}
}
static void xemaclite_rx_handler(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
struct sk_buff *skb;
unsigned int align;
u32 len;
len = ETH_FRAME_LEN + ETH_FCS_LEN;
skb = netdev_alloc_skb(dev, len + ALIGNMENT);
if (!skb) {
dev->stats.rx_dropped++;
dev_err(&lp->ndev->dev, "Could not allocate receive buffer\n");
return;
}
align = BUFFER_ALIGN(skb->data);
if (align)
skb_reserve(skb, align);
skb_reserve(skb, 2);
len = xemaclite_recv_data(lp, (u8 *) skb->data);
if (!len) {
dev->stats.rx_errors++;
dev_kfree_skb_irq(skb);
return;
}
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
skb_checksum_none_assert(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
if (!skb_defer_rx_timestamp(skb))
netif_rx(skb);
}
static irqreturn_t xemaclite_interrupt(int irq, void *dev_id)
{
bool tx_complete = false;
struct net_device *dev = dev_id;
struct net_local *lp = netdev_priv(dev);
void __iomem *base_addr = lp->base_addr;
u32 tx_status;
if ((__raw_readl(base_addr + XEL_RSR_OFFSET) &
XEL_RSR_RECV_DONE_MASK) ||
(__raw_readl(base_addr + XEL_BUFFER_OFFSET + XEL_RSR_OFFSET)
& XEL_RSR_RECV_DONE_MASK))
xemaclite_rx_handler(dev);
tx_status = __raw_readl(base_addr + XEL_TSR_OFFSET);
if (((tx_status & XEL_TSR_XMIT_BUSY_MASK) == 0) &&
(tx_status & XEL_TSR_XMIT_ACTIVE_MASK) != 0) {
tx_status &= ~XEL_TSR_XMIT_ACTIVE_MASK;
__raw_writel(tx_status, base_addr + XEL_TSR_OFFSET);
tx_complete = true;
}
tx_status = __raw_readl(base_addr + XEL_BUFFER_OFFSET + XEL_TSR_OFFSET);
if (((tx_status & XEL_TSR_XMIT_BUSY_MASK) == 0) &&
(tx_status & XEL_TSR_XMIT_ACTIVE_MASK) != 0) {
tx_status &= ~XEL_TSR_XMIT_ACTIVE_MASK;
__raw_writel(tx_status, base_addr + XEL_BUFFER_OFFSET +
XEL_TSR_OFFSET);
tx_complete = true;
}
if (tx_complete != 0)
xemaclite_tx_handler(dev);
return IRQ_HANDLED;
}
static int xemaclite_mdio_wait(struct net_local *lp)
{
unsigned long end = jiffies + 2;
while (__raw_readl(lp->base_addr + XEL_MDIOCTRL_OFFSET) &
XEL_MDIOCTRL_MDIOSTS_MASK) {
if (time_before_eq(end, jiffies)) {
WARN_ON(1);
return -ETIMEDOUT;
}
msleep(1);
}
return 0;
}
static int xemaclite_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
struct net_local *lp = bus->priv;
u32 ctrl_reg;
u32 rc;
if (xemaclite_mdio_wait(lp))
return -ETIMEDOUT;
ctrl_reg = __raw_readl(lp->base_addr + XEL_MDIOCTRL_OFFSET);
__raw_writel(XEL_MDIOADDR_OP_MASK |
((phy_id << XEL_MDIOADDR_PHYADR_SHIFT) | reg),
lp->base_addr + XEL_MDIOADDR_OFFSET);
__raw_writel(ctrl_reg | XEL_MDIOCTRL_MDIOSTS_MASK,
lp->base_addr + XEL_MDIOCTRL_OFFSET);
if (xemaclite_mdio_wait(lp))
return -ETIMEDOUT;
rc = __raw_readl(lp->base_addr + XEL_MDIORD_OFFSET);
dev_dbg(&lp->ndev->dev,
"xemaclite_mdio_read(phy_id=%i, reg=%x) == %x\n",
phy_id, reg, rc);
return rc;
}
static int xemaclite_mdio_write(struct mii_bus *bus, int phy_id, int reg,
u16 val)
{
struct net_local *lp = bus->priv;
u32 ctrl_reg;
dev_dbg(&lp->ndev->dev,
"xemaclite_mdio_write(phy_id=%i, reg=%x, val=%x)\n",
phy_id, reg, val);
if (xemaclite_mdio_wait(lp))
return -ETIMEDOUT;
ctrl_reg = __raw_readl(lp->base_addr + XEL_MDIOCTRL_OFFSET);
__raw_writel(~XEL_MDIOADDR_OP_MASK &
((phy_id << XEL_MDIOADDR_PHYADR_SHIFT) | reg),
lp->base_addr + XEL_MDIOADDR_OFFSET);
__raw_writel(val, lp->base_addr + XEL_MDIOWR_OFFSET);
__raw_writel(ctrl_reg | XEL_MDIOCTRL_MDIOSTS_MASK,
lp->base_addr + XEL_MDIOCTRL_OFFSET);
return 0;
}
static int xemaclite_mdio_setup(struct net_local *lp, struct device *dev)
{
struct mii_bus *bus;
int rc;
struct resource res;
struct device_node *np = of_get_parent(lp->phy_node);
struct device_node *npp;
if (!np) {
dev_err(dev, "Failed to register mdio bus.\n");
return -ENODEV;
}
npp = of_get_parent(np);
of_address_to_resource(npp, 0, &res);
if (lp->ndev->mem_start != res.start) {
struct phy_device *phydev;
phydev = of_phy_find_device(lp->phy_node);
if (!phydev)
dev_info(dev,
"MDIO of the phy is not registered yet\n");
else
put_device(&phydev->mdio.dev);
return 0;
}
__raw_writel(XEL_MDIOCTRL_MDIOEN_MASK,
lp->base_addr + XEL_MDIOCTRL_OFFSET);
bus = mdiobus_alloc();
if (!bus) {
dev_err(dev, "Failed to allocate mdiobus\n");
return -ENOMEM;
}
snprintf(bus->id, MII_BUS_ID_SIZE, "%.8llx",
(unsigned long long)res.start);
bus->priv = lp;
bus->name = "Xilinx Emaclite MDIO";
bus->read = xemaclite_mdio_read;
bus->write = xemaclite_mdio_write;
bus->parent = dev;
lp->mii_bus = bus;
rc = of_mdiobus_register(bus, np);
if (rc) {
dev_err(dev, "Failed to register mdio bus.\n");
goto err_register;
}
return 0;
err_register:
mdiobus_free(bus);
return rc;
}
static void xemaclite_adjust_link(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phy = lp->phy_dev;
int link_state;
link_state = phy->speed | (phy->duplex << 1) | phy->link;
if (lp->last_link != link_state) {
lp->last_link = link_state;
phy_print_status(phy);
}
}
static int xemaclite_open(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int retval;
xemaclite_disable_interrupts(lp);
if (lp->phy_node) {
u32 bmcr;
lp->phy_dev = of_phy_connect(lp->ndev, lp->phy_node,
xemaclite_adjust_link, 0,
PHY_INTERFACE_MODE_MII);
if (!lp->phy_dev) {
dev_err(&lp->ndev->dev, "of_phy_connect() failed\n");
return -ENODEV;
}
lp->phy_dev->supported &= (PHY_BASIC_FEATURES);
lp->phy_dev->advertising = lp->phy_dev->supported;
phy_write(lp->phy_dev, MII_CTRL1000, 0);
phy_write(lp->phy_dev, MII_ADVERTISE, ADVERTISE_ALL |
ADVERTISE_CSMA);
bmcr = phy_read(lp->phy_dev, MII_BMCR);
bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
phy_write(lp->phy_dev, MII_BMCR, bmcr);
phy_start(lp->phy_dev);
}
xemaclite_update_address(lp, dev->dev_addr);
retval = request_irq(dev->irq, xemaclite_interrupt, 0, dev->name, dev);
if (retval) {
dev_err(&lp->ndev->dev, "Could not allocate interrupt %d\n",
dev->irq);
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
lp->phy_dev = NULL;
return retval;
}
xemaclite_enable_interrupts(lp);
netif_start_queue(dev);
return 0;
}
static int xemaclite_close(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
netif_stop_queue(dev);
xemaclite_disable_interrupts(lp);
free_irq(dev->irq, dev);
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
lp->phy_dev = NULL;
return 0;
}
static int xemaclite_send(struct sk_buff *orig_skb, struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
struct sk_buff *new_skb;
unsigned int len;
unsigned long flags;
len = orig_skb->len;
new_skb = orig_skb;
spin_lock_irqsave(&lp->reset_lock, flags);
if (xemaclite_send_data(lp, (u8 *) new_skb->data, len) != 0) {
netif_stop_queue(dev);
lp->deferred_skb = new_skb;
skb_tx_timestamp(new_skb);
spin_unlock_irqrestore(&lp->reset_lock, flags);
return 0;
}
spin_unlock_irqrestore(&lp->reset_lock, flags);
skb_tx_timestamp(new_skb);
dev->stats.tx_bytes += len;
dev_consume_skb_any(new_skb);
return 0;
}
static void xemaclite_remove_ndev(struct net_device *ndev)
{
if (ndev) {
free_netdev(ndev);
}
}
static bool get_bool(struct platform_device *ofdev, const char *s)
{
u32 *p = (u32 *)of_get_property(ofdev->dev.of_node, s, NULL);
if (p) {
return (bool)*p;
} else {
dev_warn(&ofdev->dev, "Parameter %s not found,"
"defaulting to false\n", s);
return false;
}
}
static int xemaclite_of_probe(struct platform_device *ofdev)
{
struct resource *res;
struct net_device *ndev = NULL;
struct net_local *lp = NULL;
struct device *dev = &ofdev->dev;
const void *mac_address;
int rc = 0;
dev_info(dev, "Device Tree Probing\n");
ndev = alloc_etherdev(sizeof(struct net_local));
if (!ndev)
return -ENOMEM;
dev_set_drvdata(dev, ndev);
SET_NETDEV_DEV(ndev, &ofdev->dev);
lp = netdev_priv(ndev);
lp->ndev = ndev;
res = platform_get_resource(ofdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "no IRQ found\n");
rc = -ENXIO;
goto error;
}
ndev->irq = res->start;
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
lp->base_addr = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(lp->base_addr)) {
rc = PTR_ERR(lp->base_addr);
goto error;
}
ndev->mem_start = res->start;
ndev->mem_end = res->end;
spin_lock_init(&lp->reset_lock);
lp->next_tx_buf_to_use = 0x0;
lp->next_rx_buf_to_use = 0x0;
lp->tx_ping_pong = get_bool(ofdev, "xlnx,tx-ping-pong");
lp->rx_ping_pong = get_bool(ofdev, "xlnx,rx-ping-pong");
mac_address = of_get_mac_address(ofdev->dev.of_node);
if (mac_address)
memcpy(ndev->dev_addr, mac_address, ETH_ALEN);
else
dev_warn(dev, "No MAC address found\n");
__raw_writel(0, lp->base_addr + XEL_TSR_OFFSET);
__raw_writel(0, lp->base_addr + XEL_BUFFER_OFFSET + XEL_TSR_OFFSET);
xemaclite_update_address(lp, ndev->dev_addr);
lp->phy_node = of_parse_phandle(ofdev->dev.of_node, "phy-handle", 0);
rc = xemaclite_mdio_setup(lp, &ofdev->dev);
if (rc)
dev_warn(&ofdev->dev, "error registering MDIO bus\n");
dev_info(dev, "MAC address is now %pM\n", ndev->dev_addr);
ndev->netdev_ops = &xemaclite_netdev_ops;
ndev->flags &= ~IFF_MULTICAST;
ndev->watchdog_timeo = TX_TIMEOUT;
rc = register_netdev(ndev);
if (rc) {
dev_err(dev,
"Cannot register network device, aborting\n");
goto error;
}
dev_info(dev,
"Xilinx EmacLite at 0x%08X mapped to 0x%08X, irq=%d\n",
(unsigned int __force)ndev->mem_start,
(unsigned int __force)lp->base_addr, ndev->irq);
return 0;
error:
xemaclite_remove_ndev(ndev);
return rc;
}
static int xemaclite_of_remove(struct platform_device *of_dev)
{
struct net_device *ndev = platform_get_drvdata(of_dev);
struct net_local *lp = netdev_priv(ndev);
if (lp->has_mdio) {
mdiobus_unregister(lp->mii_bus);
mdiobus_free(lp->mii_bus);
lp->mii_bus = NULL;
}
unregister_netdev(ndev);
of_node_put(lp->phy_node);
lp->phy_node = NULL;
xemaclite_remove_ndev(ndev);
return 0;
}
static void
xemaclite_poll_controller(struct net_device *ndev)
{
disable_irq(ndev->irq);
xemaclite_interrupt(ndev->irq, ndev);
enable_irq(ndev->irq);
}
