static int at91ether_start(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
dma_addr_t addr;
u32 ctl;
int i;
lp->rx_ring = dma_alloc_coherent(&lp->pdev->dev,
(MAX_RX_DESCR *
sizeof(struct macb_dma_desc)),
&lp->rx_ring_dma, GFP_KERNEL);
if (!lp->rx_ring)
return -ENOMEM;
lp->rx_buffers = dma_alloc_coherent(&lp->pdev->dev,
MAX_RX_DESCR * MAX_RBUFF_SZ,
&lp->rx_buffers_dma, GFP_KERNEL);
if (!lp->rx_buffers) {
dma_free_coherent(&lp->pdev->dev,
MAX_RX_DESCR * sizeof(struct macb_dma_desc),
lp->rx_ring, lp->rx_ring_dma);
lp->rx_ring = NULL;
return -ENOMEM;
}
addr = lp->rx_buffers_dma;
for (i = 0; i < MAX_RX_DESCR; i++) {
lp->rx_ring[i].addr = addr;
lp->rx_ring[i].ctrl = 0;
addr += MAX_RBUFF_SZ;
}
lp->rx_ring[MAX_RX_DESCR - 1].addr |= MACB_BIT(RX_WRAP);
lp->rx_tail = 0;
macb_writel(lp, RBQP, lp->rx_ring_dma);
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl | MACB_BIT(RE) | MACB_BIT(TE));
return 0;
}
static int at91ether_open(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
u32 ctl;
int ret;
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl | MACB_BIT(CLRSTAT));
macb_set_hwaddr(lp);
ret = at91ether_start(dev);
if (ret)
return ret;
macb_writel(lp, IER, MACB_BIT(RCOMP) |
MACB_BIT(RXUBR) |
MACB_BIT(ISR_TUND) |
MACB_BIT(ISR_RLE) |
MACB_BIT(TCOMP) |
MACB_BIT(ISR_ROVR) |
MACB_BIT(HRESP));
phy_start(lp->phy_dev);
netif_start_queue(dev);
return 0;
}
static int at91ether_close(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
u32 ctl;
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl & ~(MACB_BIT(TE) | MACB_BIT(RE)));
macb_writel(lp, IDR, MACB_BIT(RCOMP) |
MACB_BIT(RXUBR) |
MACB_BIT(ISR_TUND) |
MACB_BIT(ISR_RLE) |
MACB_BIT(TCOMP) |
MACB_BIT(ISR_ROVR) |
MACB_BIT(HRESP));
netif_stop_queue(dev);
dma_free_coherent(&lp->pdev->dev,
MAX_RX_DESCR * sizeof(struct macb_dma_desc),
lp->rx_ring, lp->rx_ring_dma);
lp->rx_ring = NULL;
dma_free_coherent(&lp->pdev->dev,
MAX_RX_DESCR * MAX_RBUFF_SZ,
lp->rx_buffers, lp->rx_buffers_dma);
lp->rx_buffers = NULL;
return 0;
}
static int at91ether_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
if (macb_readl(lp, TSR) & MACB_BIT(RM9200_BNQ)) {
netif_stop_queue(dev);
lp->skb = skb;
lp->skb_length = skb->len;
lp->skb_physaddr = dma_map_single(NULL, skb->data, skb->len,
DMA_TO_DEVICE);
macb_writel(lp, TAR, lp->skb_physaddr);
macb_writel(lp, TCR, skb->len);
} else {
netdev_err(dev, "%s called, but device is busy!\n", __func__);
return NETDEV_TX_BUSY;
}
return NETDEV_TX_OK;
}
static void at91ether_rx(struct net_device *dev)
{
struct macb *lp = netdev_priv(dev);
unsigned char *p_recv;
struct sk_buff *skb;
unsigned int pktlen;
while (lp->rx_ring[lp->rx_tail].addr & MACB_BIT(RX_USED)) {
p_recv = lp->rx_buffers + lp->rx_tail * MAX_RBUFF_SZ;
pktlen = MACB_BF(RX_FRMLEN, lp->rx_ring[lp->rx_tail].ctrl);
skb = netdev_alloc_skb(dev, pktlen + 2);
if (skb) {
skb_reserve(skb, 2);
memcpy(skb_put(skb, pktlen), p_recv, pktlen);
skb->protocol = eth_type_trans(skb, dev);
lp->stats.rx_packets++;
lp->stats.rx_bytes += pktlen;
netif_rx(skb);
} else {
lp->stats.rx_dropped++;
}
if (lp->rx_ring[lp->rx_tail].ctrl & MACB_BIT(RX_MHASH_MATCH))
lp->stats.multicast++;
lp->rx_ring[lp->rx_tail].addr &= ~MACB_BIT(RX_USED);
if (lp->rx_tail == MAX_RX_DESCR - 1)
lp->rx_tail = 0;
else
lp->rx_tail++;
}
}
static irqreturn_t at91ether_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct macb *lp = netdev_priv(dev);
u32 intstatus, ctl;
intstatus = macb_readl(lp, ISR);
if (intstatus & MACB_BIT(RCOMP))
at91ether_rx(dev);
if (intstatus & MACB_BIT(TCOMP)) {
if (intstatus & (MACB_BIT(ISR_TUND) | MACB_BIT(ISR_RLE)))
lp->stats.tx_errors++;
if (lp->skb) {
dev_kfree_skb_irq(lp->skb);
lp->skb = NULL;
dma_unmap_single(NULL, lp->skb_physaddr, lp->skb_length, DMA_TO_DEVICE);
lp->stats.tx_packets++;
lp->stats.tx_bytes += lp->skb_length;
}
netif_wake_queue(dev);
}
if (intstatus & MACB_BIT(RXUBR)) {
ctl = macb_readl(lp, NCR);
macb_writel(lp, NCR, ctl & ~MACB_BIT(RE));
macb_writel(lp, NCR, ctl | MACB_BIT(RE));
}
if (intstatus & MACB_BIT(ISR_ROVR))
netdev_err(dev, "ROVR error\n");
return IRQ_HANDLED;
}
static void at91ether_poll_controller(struct net_device *dev)
{
unsigned long flags;
local_irq_save(flags);
at91ether_interrupt(dev->irq, dev);
local_irq_restore(flags);
}
static int __init at91ether_probe(struct platform_device *pdev)
{
struct macb_platform_data *board_data = pdev->dev.platform_data;
struct resource *regs;
struct net_device *dev;
struct phy_device *phydev;
struct macb *lp;
int res;
u32 reg;
const char *mac;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs)
return -ENOENT;
dev = alloc_etherdev(sizeof(struct macb));
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
lp->pdev = pdev;
lp->dev = dev;
spin_lock_init(&lp->lock);
dev->base_addr = regs->start;
lp->regs = devm_ioremap(&pdev->dev, regs->start, resource_size(regs));
if (!lp->regs) {
res = -ENOMEM;
goto err_free_dev;
}
lp->pclk = devm_clk_get(&pdev->dev, "ether_clk");
if (IS_ERR(lp->pclk)) {
res = PTR_ERR(lp->pclk);
goto err_free_dev;
}
clk_enable(lp->pclk);
dev->irq = platform_get_irq(pdev, 0);
res = devm_request_irq(&pdev->dev, dev->irq, at91ether_interrupt, 0, dev->name, dev);
if (res)
goto err_disable_clock;
ether_setup(dev);
dev->netdev_ops = &at91ether_netdev_ops;
dev->ethtool_ops = &macb_ethtool_ops;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
mac = of_get_mac_address(pdev->dev.of_node);
if (mac)
memcpy(lp->dev->dev_addr, mac, ETH_ALEN);
else
macb_get_hwaddr(lp);
res = of_get_phy_mode(pdev->dev.of_node);
if (res < 0) {
if (board_data && board_data->is_rmii)
lp->phy_interface = PHY_INTERFACE_MODE_RMII;
else
lp->phy_interface = PHY_INTERFACE_MODE_MII;
} else {
lp->phy_interface = res;
}
macb_writel(lp, NCR, 0);
reg = MACB_BF(CLK, MACB_CLK_DIV32) | MACB_BIT(BIG);
if (lp->phy_interface == PHY_INTERFACE_MODE_RMII)
reg |= MACB_BIT(RM9200_RMII);
macb_writel(lp, NCFGR, reg);
res = register_netdev(dev);
if (res)
goto err_disable_clock;
res = macb_mii_init(lp);
if (res)
goto err_out_unregister_netdev;
netif_carrier_off(dev);
phydev = lp->phy_dev;
netdev_info(dev, "attached PHY driver [%s] (mii_bus:phy_addr=%s, irq=%d)\n",
phydev->drv->name, dev_name(&phydev->dev),
phydev->irq);
netdev_info(dev, "AT91 ethernet at 0x%08lx int=%d (%pM)\n",
dev->base_addr, dev->irq, dev->dev_addr);
return 0;
err_out_unregister_netdev:
unregister_netdev(dev);
err_disable_clock:
clk_disable(lp->pclk);
err_free_dev:
free_netdev(dev);
return res;
}
static int at91ether_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct macb *lp = netdev_priv(dev);
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
mdiobus_unregister(lp->mii_bus);
kfree(lp->mii_bus->irq);
mdiobus_free(lp->mii_bus);
unregister_netdev(dev);
clk_disable(lp->pclk);
free_netdev(dev);
return 0;
}
static int at91ether_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct net_device *net_dev = platform_get_drvdata(pdev);
struct macb *lp = netdev_priv(net_dev);
if (netif_running(net_dev)) {
netif_stop_queue(net_dev);
netif_device_detach(net_dev);
clk_disable(lp->pclk);
}
return 0;
}
static int at91ether_resume(struct platform_device *pdev)
{
struct net_device *net_dev = platform_get_drvdata(pdev);
struct macb *lp = netdev_priv(net_dev);
if (netif_running(net_dev)) {
clk_enable(lp->pclk);
netif_device_attach(net_dev);
netif_start_queue(net_dev);
}
return 0;
}
