static void netx_eth_set_multicast_list(struct net_device *ndev)
{
}
static int
netx_eth_hard_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
unsigned char *buf = skb->data;
unsigned int len = skb->len;
spin_lock_irq(&priv->lock);
memcpy_toio(priv->sram_base + 1560, (void *)buf, len);
if (len < 60) {
memset_io(priv->sram_base + 1560 + len, 0, 60 - len);
len = 60;
}
pfifo_push(REQ_FIFO_PORT_LO(priv->id),
FIFO_PTR_SEGMENT(priv->id) |
FIFO_PTR_FRAMENO(1) |
FIFO_PTR_FRAMELEN(len));
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += skb->len;
netif_stop_queue(ndev);
spin_unlock_irq(&priv->lock);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void netx_eth_receive(struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
unsigned int val, frameno, seg, len;
unsigned char *data;
struct sk_buff *skb;
val = pfifo_pop(IND_FIFO_PORT_LO(priv->id));
frameno = (val & FIFO_PTR_FRAMENO_MASK) >> FIFO_PTR_FRAMENO_SHIFT;
seg = (val & FIFO_PTR_SEGMENT_MASK) >> FIFO_PTR_SEGMENT_SHIFT;
len = (val & FIFO_PTR_FRAMELEN_MASK) >> FIFO_PTR_FRAMELEN_SHIFT;
skb = netdev_alloc_skb(ndev, len);
if (unlikely(skb == NULL)) {
ndev->stats.rx_dropped++;
return;
}
data = skb_put(skb, len);
memcpy_fromio(data, priv->sram_base + frameno * 1560, len);
pfifo_push(EMPTY_PTR_FIFO(priv->id),
FIFO_PTR_SEGMENT(seg) | FIFO_PTR_FRAMENO(frameno));
skb->protocol = eth_type_trans(skb, ndev);
netif_rx(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += len;
}
static irqreturn_t
netx_eth_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct netx_eth_priv *priv = netdev_priv(ndev);
int status;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
status = readl(NETX_PFIFO_XPEC_ISR(priv->id));
while (status) {
int fill_level;
writel(status, NETX_PFIFO_XPEC_ISR(priv->id));
if ((status & ISR_CON_HI) || (status & ISR_IND_HI))
printk("%s: unexpected status: 0x%08x\n",
__func__, status);
fill_level =
readl(NETX_PFIFO_FILL_LEVEL(IND_FIFO_PORT_LO(priv->id)));
while (fill_level--)
netx_eth_receive(ndev);
if (status & ISR_CON_LO)
netif_wake_queue(ndev);
if (status & ISR_LINK_STATUS_CHANGE)
mii_check_media(&priv->mii, netif_msg_link(priv), 1);
status = readl(NETX_PFIFO_XPEC_ISR(priv->id));
}
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
}
static int netx_eth_open(struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
if (request_irq
(ndev->irq, netx_eth_interrupt, IRQF_SHARED, ndev->name, ndev))
return -EAGAIN;
writel(ndev->dev_addr[0] |
ndev->dev_addr[1]<<8 |
ndev->dev_addr[2]<<16 |
ndev->dev_addr[3]<<24,
priv->xpec_base + NETX_XPEC_RAM_START_OFS + ETH_MAC_4321);
writel(ndev->dev_addr[4] |
ndev->dev_addr[5]<<8,
priv->xpec_base + NETX_XPEC_RAM_START_OFS + ETH_MAC_65);
writel(LOCAL_CONFIG_LINK_STATUS_IRQ_EN |
LOCAL_CONFIG_CON_LO_IRQ_EN |
LOCAL_CONFIG_CON_HI_IRQ_EN |
LOCAL_CONFIG_IND_LO_IRQ_EN |
LOCAL_CONFIG_IND_HI_IRQ_EN,
priv->xpec_base + NETX_XPEC_RAM_START_OFS +
ETH_MAC_LOCAL_CONFIG);
mii_check_media(&priv->mii, netif_msg_link(priv), 1);
netif_start_queue(ndev);
return 0;
}
static int netx_eth_close(struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
writel(0,
priv->xpec_base + NETX_XPEC_RAM_START_OFS + ETH_MAC_LOCAL_CONFIG);
free_irq(ndev->irq, ndev);
return 0;
}
static void netx_eth_timeout(struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
int i;
printk(KERN_ERR "%s: transmit timed out, resetting\n", ndev->name);
spin_lock_irq(&priv->lock);
xc_reset(priv->xc);
xc_start(priv->xc);
for (i=2; i<=18; i++)
pfifo_push(EMPTY_PTR_FIFO(priv->id),
FIFO_PTR_FRAMENO(i) | FIFO_PTR_SEGMENT(priv->id));
spin_unlock_irq(&priv->lock);
netif_wake_queue(ndev);
}
static int
netx_eth_phy_read(struct net_device *ndev, int phy_id, int reg)
{
unsigned int val;
val = MIIMU_SNRDY | MIIMU_PREAMBLE | MIIMU_PHYADDR(phy_id) |
MIIMU_REGADDR(reg) | MIIMU_PHY_NRES;
writel(val, NETX_MIIMU);
while (readl(NETX_MIIMU) & MIIMU_SNRDY);
return readl(NETX_MIIMU) >> 16;
}
static void
netx_eth_phy_write(struct net_device *ndev, int phy_id, int reg, int value)
{
unsigned int val;
val = MIIMU_SNRDY | MIIMU_PREAMBLE | MIIMU_PHYADDR(phy_id) |
MIIMU_REGADDR(reg) | MIIMU_PHY_NRES | MIIMU_OPMODE_WRITE |
MIIMU_DATA(value);
writel(val, NETX_MIIMU);
while (readl(NETX_MIIMU) & MIIMU_SNRDY);
}
static int netx_eth_enable(struct net_device *ndev)
{
struct netx_eth_priv *priv = netdev_priv(ndev);
unsigned int mac4321, mac65;
int running, i;
ether_setup(ndev);
ndev->netdev_ops = &netx_eth_netdev_ops;
ndev->watchdog_timeo = msecs_to_jiffies(5000);
priv->msg_enable = NETIF_MSG_LINK;
priv->mii.phy_id_mask = 0x1f;
priv->mii.reg_num_mask = 0x1f;
priv->mii.force_media = 0;
priv->mii.full_duplex = 0;
priv->mii.dev = ndev;
priv->mii.mdio_read = netx_eth_phy_read;
priv->mii.mdio_write = netx_eth_phy_write;
priv->mii.phy_id = INTERNAL_PHY_ADR + priv->id;
running = xc_running(priv->xc);
xc_stop(priv->xc);
if (running) {
mac4321 = readl(priv->xpec_base +
NETX_XPEC_RAM_START_OFS + ETH_MAC_4321);
mac65 = readl(priv->xpec_base +
NETX_XPEC_RAM_START_OFS + ETH_MAC_65);
ndev->dev_addr[0] = mac4321 & 0xff;
ndev->dev_addr[1] = (mac4321 >> 8) & 0xff;
ndev->dev_addr[2] = (mac4321 >> 16) & 0xff;
ndev->dev_addr[3] = (mac4321 >> 24) & 0xff;
ndev->dev_addr[4] = mac65 & 0xff;
ndev->dev_addr[5] = (mac65 >> 8) & 0xff;
} else {
if (xc_request_firmware(priv->xc)) {
printk(CARDNAME ": requesting firmware failed\n");
return -ENODEV;
}
}
xc_reset(priv->xc);
xc_start(priv->xc);
if (!is_valid_ether_addr(ndev->dev_addr))
printk("%s: Invalid ethernet MAC address. Please "
"set using ifconfig\n", ndev->name);
for (i=2; i<=18; i++)
pfifo_push(EMPTY_PTR_FIFO(priv->id),
FIFO_PTR_FRAMENO(i) | FIFO_PTR_SEGMENT(priv->id));
return register_netdev(ndev);
}
static int netx_eth_drv_probe(struct platform_device *pdev)
{
struct netx_eth_priv *priv;
struct net_device *ndev;
struct netxeth_platform_data *pdata;
int ret;
ndev = alloc_etherdev(sizeof (struct netx_eth_priv));
if (!ndev) {
ret = -ENOMEM;
goto exit;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
platform_set_drvdata(pdev, ndev);
priv = netdev_priv(ndev);
pdata = (struct netxeth_platform_data *)pdev->dev.platform_data;
priv->xc = request_xc(pdata->xcno, &pdev->dev);
if (!priv->xc) {
dev_err(&pdev->dev, "unable to request xc engine\n");
ret = -ENODEV;
goto exit_free_netdev;
}
ndev->irq = priv->xc->irq;
priv->id = pdev->id;
priv->xpec_base = priv->xc->xpec_base;
priv->xmac_base = priv->xc->xmac_base;
priv->sram_base = priv->xc->sram_base;
spin_lock_init(&priv->lock);
ret = pfifo_request(PFIFO_MASK(priv->id));
if (ret) {
printk("unable to request PFIFO\n");
goto exit_free_xc;
}
ret = netx_eth_enable(ndev);
if (ret)
goto exit_free_pfifo;
return 0;
exit_free_pfifo:
pfifo_free(PFIFO_MASK(priv->id));
exit_free_xc:
free_xc(priv->xc);
exit_free_netdev:
platform_set_drvdata(pdev, NULL);
free_netdev(ndev);
exit:
return ret;
}
static int netx_eth_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = dev_get_drvdata(&pdev->dev);
struct netx_eth_priv *priv = netdev_priv(ndev);
platform_set_drvdata(pdev, NULL);
unregister_netdev(ndev);
xc_stop(priv->xc);
free_xc(priv->xc);
free_netdev(ndev);
pfifo_free(PFIFO_MASK(priv->id));
return 0;
}
static int netx_eth_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
dev_err(&pdev->dev, "suspend not implemented\n");
return 0;
}
static int netx_eth_drv_resume(struct platform_device *pdev)
{
dev_err(&pdev->dev, "resume not implemented\n");
return 0;
}
static int __init netx_eth_init(void)
{
unsigned int phy_control, val;
printk("NetX Ethernet driver\n");
phy_control = PHY_CONTROL_PHY_ADDRESS(INTERNAL_PHY_ADR>>1) |
PHY_CONTROL_PHY1_MODE(PHY_MODE_ALL) |
PHY_CONTROL_PHY1_AUTOMDIX |
PHY_CONTROL_PHY1_EN |
PHY_CONTROL_PHY0_MODE(PHY_MODE_ALL) |
PHY_CONTROL_PHY0_AUTOMDIX |
PHY_CONTROL_PHY0_EN |
PHY_CONTROL_CLK_XLATIN;
val = readl(NETX_SYSTEM_IOC_ACCESS_KEY);
writel(val, NETX_SYSTEM_IOC_ACCESS_KEY);
writel(phy_control | PHY_CONTROL_RESET, NETX_SYSTEM_PHY_CONTROL);
udelay(100);
val = readl(NETX_SYSTEM_IOC_ACCESS_KEY);
writel(val, NETX_SYSTEM_IOC_ACCESS_KEY);
writel(phy_control, NETX_SYSTEM_PHY_CONTROL);
return platform_driver_register(&netx_eth_driver);
}
static void __exit netx_eth_cleanup(void)
{
platform_driver_unregister(&netx_eth_driver);
}
