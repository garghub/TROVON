static int
ltq_etop_alloc_skb(struct ltq_etop_chan *ch)
{
ch->skb[ch->dma.desc] = netdev_alloc_skb(ch->netdev, MAX_DMA_DATA_LEN);
if (!ch->skb[ch->dma.desc])
return -ENOMEM;
ch->dma.desc_base[ch->dma.desc].addr = dma_map_single(NULL,
ch->skb[ch->dma.desc]->data, MAX_DMA_DATA_LEN,
DMA_FROM_DEVICE);
ch->dma.desc_base[ch->dma.desc].addr =
CPHYSADDR(ch->skb[ch->dma.desc]->data);
ch->dma.desc_base[ch->dma.desc].ctl =
LTQ_DMA_OWN | LTQ_DMA_RX_OFFSET(NET_IP_ALIGN) |
MAX_DMA_DATA_LEN;
skb_reserve(ch->skb[ch->dma.desc], NET_IP_ALIGN);
return 0;
}
static void
ltq_etop_hw_receive(struct ltq_etop_chan *ch)
{
struct ltq_etop_priv *priv = netdev_priv(ch->netdev);
struct ltq_dma_desc *desc = &ch->dma.desc_base[ch->dma.desc];
struct sk_buff *skb = ch->skb[ch->dma.desc];
int len = (desc->ctl & LTQ_DMA_SIZE_MASK) - MAX_DMA_CRC_LEN;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (ltq_etop_alloc_skb(ch)) {
netdev_err(ch->netdev,
"failed to allocate new rx buffer, stopping DMA\n");
ltq_dma_close(&ch->dma);
}
ch->dma.desc++;
ch->dma.desc %= LTQ_DESC_NUM;
spin_unlock_irqrestore(&priv->lock, flags);
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, ch->netdev);
netif_receive_skb(skb);
}
static int
ltq_etop_poll_rx(struct napi_struct *napi, int budget)
{
struct ltq_etop_chan *ch = container_of(napi,
struct ltq_etop_chan, napi);
int rx = 0;
int complete = 0;
while ((rx < budget) && !complete) {
struct ltq_dma_desc *desc = &ch->dma.desc_base[ch->dma.desc];
if ((desc->ctl & (LTQ_DMA_OWN | LTQ_DMA_C)) == LTQ_DMA_C) {
ltq_etop_hw_receive(ch);
rx++;
} else {
complete = 1;
}
}
if (complete || !rx) {
napi_complete(&ch->napi);
ltq_dma_ack_irq(&ch->dma);
}
return rx;
}
static int
ltq_etop_poll_tx(struct napi_struct *napi, int budget)
{
struct ltq_etop_chan *ch =
container_of(napi, struct ltq_etop_chan, napi);
struct ltq_etop_priv *priv = netdev_priv(ch->netdev);
struct netdev_queue *txq =
netdev_get_tx_queue(ch->netdev, ch->idx >> 1);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
while ((ch->dma.desc_base[ch->tx_free].ctl &
(LTQ_DMA_OWN | LTQ_DMA_C)) == LTQ_DMA_C) {
dev_kfree_skb_any(ch->skb[ch->tx_free]);
ch->skb[ch->tx_free] = NULL;
memset(&ch->dma.desc_base[ch->tx_free], 0,
sizeof(struct ltq_dma_desc));
ch->tx_free++;
ch->tx_free %= LTQ_DESC_NUM;
}
spin_unlock_irqrestore(&priv->lock, flags);
if (netif_tx_queue_stopped(txq))
netif_tx_start_queue(txq);
napi_complete(&ch->napi);
ltq_dma_ack_irq(&ch->dma);
return 1;
}
static irqreturn_t
ltq_etop_dma_irq(int irq, void *_priv)
{
struct ltq_etop_priv *priv = _priv;
int ch = irq - LTQ_DMA_CH0_INT;
napi_schedule(&priv->ch[ch].napi);
return IRQ_HANDLED;
}
static void
ltq_etop_free_channel(struct net_device *dev, struct ltq_etop_chan *ch)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
ltq_dma_free(&ch->dma);
if (ch->dma.irq)
free_irq(ch->dma.irq, priv);
if (IS_RX(ch->idx)) {
int desc;
for (desc = 0; desc < LTQ_DESC_NUM; desc++)
dev_kfree_skb_any(ch->skb[ch->dma.desc]);
}
}
static void
ltq_etop_hw_exit(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
int i;
ltq_pmu_disable(PMU_PPE);
for (i = 0; i < MAX_DMA_CHAN; i++)
if (IS_TX(i) || IS_RX(i))
ltq_etop_free_channel(dev, &priv->ch[i]);
}
static int
ltq_etop_hw_init(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
int i;
ltq_pmu_enable(PMU_PPE);
switch (priv->pldata->mii_mode) {
case PHY_INTERFACE_MODE_RMII:
ltq_etop_w32_mask(ETOP_MII_MASK,
ETOP_MII_REVERSE, LTQ_ETOP_CFG);
break;
case PHY_INTERFACE_MODE_MII:
ltq_etop_w32_mask(ETOP_MII_MASK,
ETOP_MII_NORMAL, LTQ_ETOP_CFG);
break;
default:
netdev_err(dev, "unknown mii mode %d\n",
priv->pldata->mii_mode);
return -ENOTSUPP;
}
ltq_etop_w32(PPE32_CGEN, LQ_PPE32_ENET_MAC_CFG);
ltq_dma_init_port(DMA_PORT_ETOP);
for (i = 0; i < MAX_DMA_CHAN; i++) {
int irq = LTQ_DMA_CH0_INT + i;
struct ltq_etop_chan *ch = &priv->ch[i];
ch->idx = ch->dma.nr = i;
if (IS_TX(i)) {
ltq_dma_alloc_tx(&ch->dma);
request_irq(irq, ltq_etop_dma_irq, 0, "etop_tx", priv);
} else if (IS_RX(i)) {
ltq_dma_alloc_rx(&ch->dma);
for (ch->dma.desc = 0; ch->dma.desc < LTQ_DESC_NUM;
ch->dma.desc++)
if (ltq_etop_alloc_skb(ch))
return -ENOMEM;
ch->dma.desc = 0;
request_irq(irq, ltq_etop_dma_irq, 0, "etop_rx", priv);
}
ch->dma.irq = irq;
}
return 0;
}
static void
ltq_etop_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "Lantiq ETOP", sizeof(info->driver));
strlcpy(info->bus_info, "internal", sizeof(info->bus_info));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
static int
ltq_etop_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
return phy_ethtool_gset(priv->phydev, cmd);
}
static int
ltq_etop_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
return phy_ethtool_sset(priv->phydev, cmd);
}
static int
ltq_etop_nway_reset(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
return phy_start_aneg(priv->phydev);
}
static int
ltq_etop_mdio_wr(struct mii_bus *bus, int phy_addr, int phy_reg, u16 phy_data)
{
u32 val = MDIO_REQUEST |
((phy_addr & MDIO_ADDR_MASK) << MDIO_ADDR_OFFSET) |
((phy_reg & MDIO_REG_MASK) << MDIO_REG_OFFSET) |
phy_data;
while (ltq_etop_r32(LTQ_ETOP_MDIO) & MDIO_REQUEST)
;
ltq_etop_w32(val, LTQ_ETOP_MDIO);
return 0;
}
static int
ltq_etop_mdio_rd(struct mii_bus *bus, int phy_addr, int phy_reg)
{
u32 val = MDIO_REQUEST | MDIO_READ |
((phy_addr & MDIO_ADDR_MASK) << MDIO_ADDR_OFFSET) |
((phy_reg & MDIO_REG_MASK) << MDIO_REG_OFFSET);
while (ltq_etop_r32(LTQ_ETOP_MDIO) & MDIO_REQUEST)
;
ltq_etop_w32(val, LTQ_ETOP_MDIO);
while (ltq_etop_r32(LTQ_ETOP_MDIO) & MDIO_REQUEST)
;
val = ltq_etop_r32(LTQ_ETOP_MDIO) & MDIO_VAL_MASK;
return val;
}
static void
ltq_etop_mdio_link(struct net_device *dev)
{
}
static int
ltq_etop_mdio_probe(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
struct phy_device *phydev = NULL;
int phy_addr;
for (phy_addr = 0; phy_addr < PHY_MAX_ADDR; phy_addr++) {
if (priv->mii_bus->phy_map[phy_addr]) {
phydev = priv->mii_bus->phy_map[phy_addr];
break;
}
}
if (!phydev) {
netdev_err(dev, "no PHY found\n");
return -ENODEV;
}
phydev = phy_connect(dev, dev_name(&phydev->dev),
&ltq_etop_mdio_link, priv->pldata->mii_mode);
if (IS_ERR(phydev)) {
netdev_err(dev, "Could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (SUPPORTED_10baseT_Half
| SUPPORTED_10baseT_Full
| SUPPORTED_100baseT_Half
| SUPPORTED_100baseT_Full
| SUPPORTED_Autoneg
| SUPPORTED_MII
| SUPPORTED_TP);
phydev->advertising = phydev->supported;
priv->phydev = phydev;
pr_info("%s: attached PHY [%s] (phy_addr=%s, irq=%d)\n",
dev->name, phydev->drv->name,
dev_name(&phydev->dev), phydev->irq);
return 0;
}
static int
ltq_etop_mdio_init(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
int i;
int err;
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus) {
netdev_err(dev, "failed to allocate mii bus\n");
err = -ENOMEM;
goto err_out;
}
priv->mii_bus->priv = dev;
priv->mii_bus->read = ltq_etop_mdio_rd;
priv->mii_bus->write = ltq_etop_mdio_wr;
priv->mii_bus->name = "ltq_mii";
snprintf(priv->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
priv->pdev->name, priv->pdev->id);
priv->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!priv->mii_bus->irq) {
err = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; ++i)
priv->mii_bus->irq[i] = PHY_POLL;
if (mdiobus_register(priv->mii_bus)) {
err = -ENXIO;
goto err_out_free_mdio_irq;
}
if (ltq_etop_mdio_probe(dev)) {
err = -ENXIO;
goto err_out_unregister_bus;
}
return 0;
err_out_unregister_bus:
mdiobus_unregister(priv->mii_bus);
err_out_free_mdio_irq:
kfree(priv->mii_bus->irq);
err_out_free_mdiobus:
mdiobus_free(priv->mii_bus);
err_out:
return err;
}
static void
ltq_etop_mdio_cleanup(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
phy_disconnect(priv->phydev);
mdiobus_unregister(priv->mii_bus);
kfree(priv->mii_bus->irq);
mdiobus_free(priv->mii_bus);
}
static int
ltq_etop_open(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
int i;
for (i = 0; i < MAX_DMA_CHAN; i++) {
struct ltq_etop_chan *ch = &priv->ch[i];
if (!IS_TX(i) && (!IS_RX(i)))
continue;
ltq_dma_open(&ch->dma);
napi_enable(&ch->napi);
}
phy_start(priv->phydev);
netif_tx_start_all_queues(dev);
return 0;
}
static int
ltq_etop_stop(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
int i;
netif_tx_stop_all_queues(dev);
phy_stop(priv->phydev);
for (i = 0; i < MAX_DMA_CHAN; i++) {
struct ltq_etop_chan *ch = &priv->ch[i];
if (!IS_RX(i) && !IS_TX(i))
continue;
napi_disable(&ch->napi);
ltq_dma_close(&ch->dma);
}
return 0;
}
static int
ltq_etop_tx(struct sk_buff *skb, struct net_device *dev)
{
int queue = skb_get_queue_mapping(skb);
struct netdev_queue *txq = netdev_get_tx_queue(dev, queue);
struct ltq_etop_priv *priv = netdev_priv(dev);
struct ltq_etop_chan *ch = &priv->ch[(queue << 1) | 1];
struct ltq_dma_desc *desc = &ch->dma.desc_base[ch->dma.desc];
int len;
unsigned long flags;
u32 byte_offset;
len = skb->len < ETH_ZLEN ? ETH_ZLEN : skb->len;
if ((desc->ctl & (LTQ_DMA_OWN | LTQ_DMA_C)) || ch->skb[ch->dma.desc]) {
dev_kfree_skb_any(skb);
netdev_err(dev, "tx ring full\n");
netif_tx_stop_queue(txq);
return NETDEV_TX_BUSY;
}
byte_offset = CPHYSADDR(skb->data) % 16;
ch->skb[ch->dma.desc] = skb;
dev->trans_start = jiffies;
spin_lock_irqsave(&priv->lock, flags);
desc->addr = ((unsigned int) dma_map_single(NULL, skb->data, len,
DMA_TO_DEVICE)) - byte_offset;
wmb();
desc->ctl = LTQ_DMA_OWN | LTQ_DMA_SOP | LTQ_DMA_EOP |
LTQ_DMA_TX_OFFSET(byte_offset) | (len & LTQ_DMA_SIZE_MASK);
ch->dma.desc++;
ch->dma.desc %= LTQ_DESC_NUM;
spin_unlock_irqrestore(&priv->lock, flags);
if (ch->dma.desc_base[ch->dma.desc].ctl & LTQ_DMA_OWN)
netif_tx_stop_queue(txq);
return NETDEV_TX_OK;
}
static int
ltq_etop_change_mtu(struct net_device *dev, int new_mtu)
{
int ret = eth_change_mtu(dev, new_mtu);
if (!ret) {
struct ltq_etop_priv *priv = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
ltq_etop_w32((ETOP_PLEN_UNDER << 16) | new_mtu,
LTQ_ETOP_IGPLEN);
spin_unlock_irqrestore(&priv->lock, flags);
}
return ret;
}
static int
ltq_etop_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
return phy_mii_ioctl(priv->phydev, rq, cmd);
}
static int
ltq_etop_set_mac_address(struct net_device *dev, void *p)
{
int ret = eth_mac_addr(dev, p);
if (!ret) {
struct ltq_etop_priv *priv = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
ltq_etop_w32(*((u32 *)dev->dev_addr), LTQ_ETOP_MAC_DA0);
ltq_etop_w32(*((u16 *)&dev->dev_addr[4]) << 16,
LTQ_ETOP_MAC_DA1);
spin_unlock_irqrestore(&priv->lock, flags);
}
return ret;
}
static void
ltq_etop_set_multicast_list(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if ((dev->flags & IFF_PROMISC) || (dev->flags & IFF_ALLMULTI))
ltq_etop_w32_mask(ETOP_FTCU, 0, LTQ_ETOP_ENETS0);
else
ltq_etop_w32_mask(0, ETOP_FTCU, LTQ_ETOP_ENETS0);
spin_unlock_irqrestore(&priv->lock, flags);
}
static u16
ltq_etop_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
return 0;
}
static int
ltq_etop_init(struct net_device *dev)
{
struct ltq_etop_priv *priv = netdev_priv(dev);
struct sockaddr mac;
int err;
bool random_mac = false;
ether_setup(dev);
dev->watchdog_timeo = 10 * HZ;
err = ltq_etop_hw_init(dev);
if (err)
goto err_hw;
ltq_etop_change_mtu(dev, 1500);
memcpy(&mac, &priv->pldata->mac, sizeof(struct sockaddr));
if (!is_valid_ether_addr(mac.sa_data)) {
pr_warn("etop: invalid MAC, using random\n");
eth_random_addr(mac.sa_data);
random_mac = true;
}
err = ltq_etop_set_mac_address(dev, &mac);
if (err)
goto err_netdev;
if (random_mac)
dev->addr_assign_type = NET_ADDR_RANDOM;
ltq_etop_set_multicast_list(dev);
err = ltq_etop_mdio_init(dev);
if (err)
goto err_netdev;
return 0;
err_netdev:
unregister_netdev(dev);
free_netdev(dev);
err_hw:
ltq_etop_hw_exit(dev);
return err;
}
static void
ltq_etop_tx_timeout(struct net_device *dev)
{
int err;
ltq_etop_hw_exit(dev);
err = ltq_etop_hw_init(dev);
if (err)
goto err_hw;
dev->trans_start = jiffies;
netif_wake_queue(dev);
return;
err_hw:
ltq_etop_hw_exit(dev);
netdev_err(dev, "failed to restart etop after TX timeout\n");
}
static int __init
ltq_etop_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct ltq_etop_priv *priv;
struct resource *res;
int err;
int i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get etop resource\n");
err = -ENOENT;
goto err_out;
}
res = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), dev_name(&pdev->dev));
if (!res) {
dev_err(&pdev->dev, "failed to request etop resource\n");
err = -EBUSY;
goto err_out;
}
ltq_etop_membase = devm_ioremap_nocache(&pdev->dev,
res->start, resource_size(res));
if (!ltq_etop_membase) {
dev_err(&pdev->dev, "failed to remap etop engine %d\n",
pdev->id);
err = -ENOMEM;
goto err_out;
}
dev = alloc_etherdev_mq(sizeof(struct ltq_etop_priv), 4);
if (!dev) {
err = -ENOMEM;
goto err_out;
}
strcpy(dev->name, "eth%d");
dev->netdev_ops = &ltq_eth_netdev_ops;
dev->ethtool_ops = &ltq_etop_ethtool_ops;
priv = netdev_priv(dev);
priv->res = res;
priv->pdev = pdev;
priv->pldata = dev_get_platdata(&pdev->dev);
priv->netdev = dev;
spin_lock_init(&priv->lock);
for (i = 0; i < MAX_DMA_CHAN; i++) {
if (IS_TX(i))
netif_napi_add(dev, &priv->ch[i].napi,
ltq_etop_poll_tx, 8);
else if (IS_RX(i))
netif_napi_add(dev, &priv->ch[i].napi,
ltq_etop_poll_rx, 32);
priv->ch[i].netdev = dev;
}
err = register_netdev(dev);
if (err)
goto err_free;
platform_set_drvdata(pdev, dev);
return 0;
err_free:
free_netdev(dev);
err_out:
return err;
}
static int
ltq_etop_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
if (dev) {
netif_tx_stop_all_queues(dev);
ltq_etop_hw_exit(dev);
ltq_etop_mdio_cleanup(dev);
unregister_netdev(dev);
}
return 0;
}
int __init
init_ltq_etop(void)
{
int ret = platform_driver_probe(&ltq_mii_driver, ltq_etop_probe);
if (ret)
pr_err("ltq_etop: Error registering platform driver!");
return ret;
}
static void __exit
exit_ltq_etop(void)
{
platform_driver_unregister(&ltq_mii_driver);
}
