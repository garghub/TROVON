static inline u32 enet_readl(struct bcm_enet_priv *priv, u32 off)
{
return bcm_readl(priv->base + off);
}
static inline void enet_writel(struct bcm_enet_priv *priv,
u32 val, u32 off)
{
bcm_writel(val, priv->base + off);
}
static inline u32 enet_dma_readl(struct bcm_enet_priv *priv, u32 off)
{
return bcm_readl(bcm_enet_shared_base + off);
}
static inline void enet_dma_writel(struct bcm_enet_priv *priv,
u32 val, u32 off)
{
bcm_writel(val, bcm_enet_shared_base + off);
}
static int do_mdio_op(struct bcm_enet_priv *priv, unsigned int data)
{
int limit;
enet_writel(priv, ENET_IR_MII, ENET_IR_REG);
enet_writel(priv, data, ENET_MIIDATA_REG);
wmb();
limit = 1000;
do {
if (enet_readl(priv, ENET_IR_REG) & ENET_IR_MII)
break;
udelay(1);
} while (limit-- > 0);
return (limit < 0) ? 1 : 0;
}
static int bcm_enet_mdio_read(struct bcm_enet_priv *priv, int mii_id,
int regnum)
{
u32 tmp, val;
tmp = regnum << ENET_MIIDATA_REG_SHIFT;
tmp |= 0x2 << ENET_MIIDATA_TA_SHIFT;
tmp |= mii_id << ENET_MIIDATA_PHYID_SHIFT;
tmp |= ENET_MIIDATA_OP_READ_MASK;
if (do_mdio_op(priv, tmp))
return -1;
val = enet_readl(priv, ENET_MIIDATA_REG);
val &= 0xffff;
return val;
}
static int bcm_enet_mdio_write(struct bcm_enet_priv *priv, int mii_id,
int regnum, u16 value)
{
u32 tmp;
tmp = (value & 0xffff) << ENET_MIIDATA_DATA_SHIFT;
tmp |= 0x2 << ENET_MIIDATA_TA_SHIFT;
tmp |= regnum << ENET_MIIDATA_REG_SHIFT;
tmp |= mii_id << ENET_MIIDATA_PHYID_SHIFT;
tmp |= ENET_MIIDATA_OP_WRITE_MASK;
(void)do_mdio_op(priv, tmp);
return 0;
}
static int bcm_enet_mdio_read_phylib(struct mii_bus *bus, int mii_id,
int regnum)
{
return bcm_enet_mdio_read(bus->priv, mii_id, regnum);
}
static int bcm_enet_mdio_write_phylib(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
return bcm_enet_mdio_write(bus->priv, mii_id, regnum, value);
}
static int bcm_enet_mdio_read_mii(struct net_device *dev, int mii_id,
int regnum)
{
return bcm_enet_mdio_read(netdev_priv(dev), mii_id, regnum);
}
static void bcm_enet_mdio_write_mii(struct net_device *dev, int mii_id,
int regnum, int value)
{
bcm_enet_mdio_write(netdev_priv(dev), mii_id, regnum, value);
}
static int bcm_enet_refill_rx(struct net_device *dev)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
while (priv->rx_desc_count < priv->rx_ring_size) {
struct bcm_enet_desc *desc;
struct sk_buff *skb;
dma_addr_t p;
int desc_idx;
u32 len_stat;
desc_idx = priv->rx_dirty_desc;
desc = &priv->rx_desc_cpu[desc_idx];
if (!priv->rx_skb[desc_idx]) {
skb = netdev_alloc_skb(dev, priv->rx_skb_size);
if (!skb)
break;
priv->rx_skb[desc_idx] = skb;
p = dma_map_single(&priv->pdev->dev, skb->data,
priv->rx_skb_size,
DMA_FROM_DEVICE);
desc->address = p;
}
len_stat = priv->rx_skb_size << DMADESC_LENGTH_SHIFT;
len_stat |= DMADESC_OWNER_MASK;
if (priv->rx_dirty_desc == priv->rx_ring_size - 1) {
len_stat |= DMADESC_WRAP_MASK;
priv->rx_dirty_desc = 0;
} else {
priv->rx_dirty_desc++;
}
wmb();
desc->len_stat = len_stat;
priv->rx_desc_count++;
enet_dma_writel(priv, 1, ENETDMA_BUFALLOC_REG(priv->rx_chan));
}
if (priv->rx_desc_count == 0 && netif_running(dev)) {
dev_warn(&priv->pdev->dev, "unable to refill rx ring\n");
priv->rx_timeout.expires = jiffies + HZ;
add_timer(&priv->rx_timeout);
}
return 0;
}
static void bcm_enet_refill_rx_timer(unsigned long data)
{
struct net_device *dev;
struct bcm_enet_priv *priv;
dev = (struct net_device *)data;
priv = netdev_priv(dev);
spin_lock(&priv->rx_lock);
bcm_enet_refill_rx((struct net_device *)data);
spin_unlock(&priv->rx_lock);
}
static int bcm_enet_receive_queue(struct net_device *dev, int budget)
{
struct bcm_enet_priv *priv;
struct device *kdev;
int processed;
priv = netdev_priv(dev);
kdev = &priv->pdev->dev;
processed = 0;
if (budget > priv->rx_desc_count)
budget = priv->rx_desc_count;
do {
struct bcm_enet_desc *desc;
struct sk_buff *skb;
int desc_idx;
u32 len_stat;
unsigned int len;
desc_idx = priv->rx_curr_desc;
desc = &priv->rx_desc_cpu[desc_idx];
rmb();
len_stat = desc->len_stat;
if (len_stat & DMADESC_OWNER_MASK)
break;
processed++;
priv->rx_curr_desc++;
if (priv->rx_curr_desc == priv->rx_ring_size)
priv->rx_curr_desc = 0;
priv->rx_desc_count--;
if ((len_stat & DMADESC_ESOP_MASK) != DMADESC_ESOP_MASK) {
dev->stats.rx_dropped++;
continue;
}
if (unlikely(len_stat & DMADESC_ERR_MASK)) {
dev->stats.rx_errors++;
if (len_stat & DMADESC_OVSIZE_MASK)
dev->stats.rx_length_errors++;
if (len_stat & DMADESC_CRC_MASK)
dev->stats.rx_crc_errors++;
if (len_stat & DMADESC_UNDER_MASK)
dev->stats.rx_frame_errors++;
if (len_stat & DMADESC_OV_MASK)
dev->stats.rx_fifo_errors++;
continue;
}
skb = priv->rx_skb[desc_idx];
len = (len_stat & DMADESC_LENGTH_MASK) >> DMADESC_LENGTH_SHIFT;
len -= 4;
if (len < copybreak) {
struct sk_buff *nskb;
nskb = netdev_alloc_skb_ip_align(dev, len);
if (!nskb) {
dev->stats.rx_dropped++;
continue;
}
dma_sync_single_for_cpu(kdev, desc->address,
len, DMA_FROM_DEVICE);
memcpy(nskb->data, skb->data, len);
dma_sync_single_for_device(kdev, desc->address,
len, DMA_FROM_DEVICE);
skb = nskb;
} else {
dma_unmap_single(&priv->pdev->dev, desc->address,
priv->rx_skb_size, DMA_FROM_DEVICE);
priv->rx_skb[desc_idx] = NULL;
}
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
netif_receive_skb(skb);
} while (--budget > 0);
if (processed || !priv->rx_desc_count) {
bcm_enet_refill_rx(dev);
enet_dma_writel(priv, ENETDMA_CHANCFG_EN_MASK,
ENETDMA_CHANCFG_REG(priv->rx_chan));
}
return processed;
}
static int bcm_enet_tx_reclaim(struct net_device *dev, int force)
{
struct bcm_enet_priv *priv;
int released;
priv = netdev_priv(dev);
released = 0;
while (priv->tx_desc_count < priv->tx_ring_size) {
struct bcm_enet_desc *desc;
struct sk_buff *skb;
spin_lock(&priv->tx_lock);
desc = &priv->tx_desc_cpu[priv->tx_dirty_desc];
if (!force && (desc->len_stat & DMADESC_OWNER_MASK)) {
spin_unlock(&priv->tx_lock);
break;
}
rmb();
skb = priv->tx_skb[priv->tx_dirty_desc];
priv->tx_skb[priv->tx_dirty_desc] = NULL;
dma_unmap_single(&priv->pdev->dev, desc->address, skb->len,
DMA_TO_DEVICE);
priv->tx_dirty_desc++;
if (priv->tx_dirty_desc == priv->tx_ring_size)
priv->tx_dirty_desc = 0;
priv->tx_desc_count++;
spin_unlock(&priv->tx_lock);
if (desc->len_stat & DMADESC_UNDER_MASK)
dev->stats.tx_errors++;
dev_kfree_skb(skb);
released++;
}
if (netif_queue_stopped(dev) && released)
netif_wake_queue(dev);
return released;
}
static int bcm_enet_poll(struct napi_struct *napi, int budget)
{
struct bcm_enet_priv *priv;
struct net_device *dev;
int tx_work_done, rx_work_done;
priv = container_of(napi, struct bcm_enet_priv, napi);
dev = priv->net_dev;
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IR_REG(priv->rx_chan));
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IR_REG(priv->tx_chan));
tx_work_done = bcm_enet_tx_reclaim(dev, 0);
spin_lock(&priv->rx_lock);
rx_work_done = bcm_enet_receive_queue(dev, budget);
spin_unlock(&priv->rx_lock);
if (rx_work_done >= budget || tx_work_done > 0) {
return rx_work_done;
}
napi_complete(napi);
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IRMASK_REG(priv->rx_chan));
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IRMASK_REG(priv->tx_chan));
return rx_work_done;
}
static irqreturn_t bcm_enet_isr_mac(int irq, void *dev_id)
{
struct net_device *dev;
struct bcm_enet_priv *priv;
u32 stat;
dev = dev_id;
priv = netdev_priv(dev);
stat = enet_readl(priv, ENET_IR_REG);
if (!(stat & ENET_IR_MIB))
return IRQ_NONE;
enet_writel(priv, ENET_IR_MIB, ENET_IR_REG);
enet_writel(priv, 0, ENET_IRMASK_REG);
schedule_work(&priv->mib_update_task);
return IRQ_HANDLED;
}
static irqreturn_t bcm_enet_isr_dma(int irq, void *dev_id)
{
struct net_device *dev;
struct bcm_enet_priv *priv;
dev = dev_id;
priv = netdev_priv(dev);
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->tx_chan));
napi_schedule(&priv->napi);
return IRQ_HANDLED;
}
static int bcm_enet_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bcm_enet_priv *priv;
struct bcm_enet_desc *desc;
u32 len_stat;
int ret;
priv = netdev_priv(dev);
spin_lock(&priv->tx_lock);
if (unlikely(!priv->tx_desc_count)) {
netif_stop_queue(dev);
dev_err(&priv->pdev->dev, "xmit called with no tx desc "
"available?\n");
ret = NETDEV_TX_BUSY;
goto out_unlock;
}
desc = &priv->tx_desc_cpu[priv->tx_curr_desc];
priv->tx_skb[priv->tx_curr_desc] = skb;
desc->address = dma_map_single(&priv->pdev->dev, skb->data, skb->len,
DMA_TO_DEVICE);
len_stat = (skb->len << DMADESC_LENGTH_SHIFT) & DMADESC_LENGTH_MASK;
len_stat |= DMADESC_ESOP_MASK |
DMADESC_APPEND_CRC |
DMADESC_OWNER_MASK;
priv->tx_curr_desc++;
if (priv->tx_curr_desc == priv->tx_ring_size) {
priv->tx_curr_desc = 0;
len_stat |= DMADESC_WRAP_MASK;
}
priv->tx_desc_count--;
wmb();
desc->len_stat = len_stat;
wmb();
enet_dma_writel(priv, ENETDMA_CHANCFG_EN_MASK,
ENETDMA_CHANCFG_REG(priv->tx_chan));
if (!priv->tx_desc_count)
netif_stop_queue(dev);
dev->stats.tx_bytes += skb->len;
dev->stats.tx_packets++;
ret = NETDEV_TX_OK;
out_unlock:
spin_unlock(&priv->tx_lock);
return ret;
}
static int bcm_enet_set_mac_address(struct net_device *dev, void *p)
{
struct bcm_enet_priv *priv;
struct sockaddr *addr = p;
u32 val;
priv = netdev_priv(dev);
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
val = (dev->dev_addr[2] << 24) | (dev->dev_addr[3] << 16) |
(dev->dev_addr[4] << 8) | dev->dev_addr[5];
enet_writel(priv, val, ENET_PML_REG(0));
val = (dev->dev_addr[0] << 8 | dev->dev_addr[1]);
val |= ENET_PMH_DATAVALID_MASK;
enet_writel(priv, val, ENET_PMH_REG(0));
return 0;
}
static void bcm_enet_set_multicast_list(struct net_device *dev)
{
struct bcm_enet_priv *priv;
struct netdev_hw_addr *ha;
u32 val;
int i;
priv = netdev_priv(dev);
val = enet_readl(priv, ENET_RXCFG_REG);
if (dev->flags & IFF_PROMISC)
val |= ENET_RXCFG_PROMISC_MASK;
else
val &= ~ENET_RXCFG_PROMISC_MASK;
if ((dev->flags & IFF_ALLMULTI) || netdev_mc_count(dev) > 3)
val |= ENET_RXCFG_ALLMCAST_MASK;
else
val &= ~ENET_RXCFG_ALLMCAST_MASK;
if (val & ENET_RXCFG_ALLMCAST_MASK) {
enet_writel(priv, val, ENET_RXCFG_REG);
return;
}
i = 0;
netdev_for_each_mc_addr(ha, dev) {
u8 *dmi_addr;
u32 tmp;
if (i == 3)
break;
dmi_addr = ha->addr;
tmp = (dmi_addr[2] << 24) | (dmi_addr[3] << 16) |
(dmi_addr[4] << 8) | dmi_addr[5];
enet_writel(priv, tmp, ENET_PML_REG(i + 1));
tmp = (dmi_addr[0] << 8 | dmi_addr[1]);
tmp |= ENET_PMH_DATAVALID_MASK;
enet_writel(priv, tmp, ENET_PMH_REG(i++ + 1));
}
for (; i < 3; i++) {
enet_writel(priv, 0, ENET_PML_REG(i + 1));
enet_writel(priv, 0, ENET_PMH_REG(i + 1));
}
enet_writel(priv, val, ENET_RXCFG_REG);
}
static void bcm_enet_set_duplex(struct bcm_enet_priv *priv, int fullduplex)
{
u32 val;
val = enet_readl(priv, ENET_TXCTL_REG);
if (fullduplex)
val |= ENET_TXCTL_FD_MASK;
else
val &= ~ENET_TXCTL_FD_MASK;
enet_writel(priv, val, ENET_TXCTL_REG);
}
static void bcm_enet_set_flow(struct bcm_enet_priv *priv, int rx_en, int tx_en)
{
u32 val;
val = enet_readl(priv, ENET_RXCFG_REG);
if (rx_en)
val |= ENET_RXCFG_ENFLOW_MASK;
else
val &= ~ENET_RXCFG_ENFLOW_MASK;
enet_writel(priv, val, ENET_RXCFG_REG);
val = enet_dma_readl(priv, ENETDMA_CFG_REG);
if (tx_en)
val |= ENETDMA_CFG_FLOWCH_MASK(priv->rx_chan);
else
val &= ~ENETDMA_CFG_FLOWCH_MASK(priv->rx_chan);
enet_dma_writel(priv, val, ENETDMA_CFG_REG);
}
static void bcm_enet_adjust_phy_link(struct net_device *dev)
{
struct bcm_enet_priv *priv;
struct phy_device *phydev;
int status_changed;
priv = netdev_priv(dev);
phydev = priv->phydev;
status_changed = 0;
if (priv->old_link != phydev->link) {
status_changed = 1;
priv->old_link = phydev->link;
}
if (phydev->link && phydev->duplex != priv->old_duplex) {
bcm_enet_set_duplex(priv,
(phydev->duplex == DUPLEX_FULL) ? 1 : 0);
status_changed = 1;
priv->old_duplex = phydev->duplex;
}
if (phydev->link && phydev->pause != priv->old_pause) {
int rx_pause_en, tx_pause_en;
if (phydev->pause) {
rx_pause_en = 1;
tx_pause_en = 1;
} else if (!priv->pause_auto) {
rx_pause_en = priv->pause_rx;
tx_pause_en = priv->pause_tx;
} else {
rx_pause_en = 0;
tx_pause_en = 0;
}
bcm_enet_set_flow(priv, rx_pause_en, tx_pause_en);
status_changed = 1;
priv->old_pause = phydev->pause;
}
if (status_changed) {
pr_info("%s: link %s", dev->name, phydev->link ?
"UP" : "DOWN");
if (phydev->link)
pr_cont(" - %d/%s - flow control %s", phydev->speed,
DUPLEX_FULL == phydev->duplex ? "full" : "half",
phydev->pause == 1 ? "rx&tx" : "off");
pr_cont("\n");
}
}
static void bcm_enet_adjust_link(struct net_device *dev)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
bcm_enet_set_duplex(priv, priv->force_duplex_full);
bcm_enet_set_flow(priv, priv->pause_rx, priv->pause_tx);
netif_carrier_on(dev);
pr_info("%s: link forced UP - %d/%s - flow control %s/%s\n",
dev->name,
priv->force_speed_100 ? 100 : 10,
priv->force_duplex_full ? "full" : "half",
priv->pause_rx ? "rx" : "off",
priv->pause_tx ? "tx" : "off");
}
static int bcm_enet_open(struct net_device *dev)
{
struct bcm_enet_priv *priv;
struct sockaddr addr;
struct device *kdev;
struct phy_device *phydev;
int i, ret;
unsigned int size;
char phy_id[MII_BUS_ID_SIZE + 3];
void *p;
u32 val;
priv = netdev_priv(dev);
kdev = &priv->pdev->dev;
if (priv->has_phy) {
snprintf(phy_id, sizeof(phy_id), PHY_ID_FMT,
priv->mac_id ? "1" : "0", priv->phy_id);
phydev = phy_connect(dev, phy_id, bcm_enet_adjust_phy_link, 0,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(phydev)) {
dev_err(kdev, "could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_Pause |
SUPPORTED_MII);
phydev->advertising = phydev->supported;
if (priv->pause_auto && priv->pause_rx && priv->pause_tx)
phydev->advertising |= SUPPORTED_Pause;
else
phydev->advertising &= ~SUPPORTED_Pause;
dev_info(kdev, "attached PHY at address %d [%s]\n",
phydev->addr, phydev->drv->name);
priv->old_link = 0;
priv->old_duplex = -1;
priv->old_pause = -1;
priv->phydev = phydev;
}
enet_writel(priv, 0, ENET_IRMASK_REG);
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->tx_chan));
ret = request_irq(dev->irq, bcm_enet_isr_mac, 0, dev->name, dev);
if (ret)
goto out_phy_disconnect;
ret = request_irq(priv->irq_rx, bcm_enet_isr_dma, IRQF_DISABLED,
dev->name, dev);
if (ret)
goto out_freeirq;
ret = request_irq(priv->irq_tx, bcm_enet_isr_dma,
IRQF_DISABLED, dev->name, dev);
if (ret)
goto out_freeirq_rx;
for (i = 0; i < 4; i++) {
enet_writel(priv, 0, ENET_PML_REG(i));
enet_writel(priv, 0, ENET_PMH_REG(i));
}
memcpy(addr.sa_data, dev->dev_addr, ETH_ALEN);
bcm_enet_set_mac_address(dev, &addr);
size = priv->rx_ring_size * sizeof(struct bcm_enet_desc);
p = dma_alloc_coherent(kdev, size, &priv->rx_desc_dma, GFP_KERNEL);
if (!p) {
dev_err(kdev, "cannot allocate rx ring %u\n", size);
ret = -ENOMEM;
goto out_freeirq_tx;
}
memset(p, 0, size);
priv->rx_desc_alloc_size = size;
priv->rx_desc_cpu = p;
size = priv->tx_ring_size * sizeof(struct bcm_enet_desc);
p = dma_alloc_coherent(kdev, size, &priv->tx_desc_dma, GFP_KERNEL);
if (!p) {
dev_err(kdev, "cannot allocate tx ring\n");
ret = -ENOMEM;
goto out_free_rx_ring;
}
memset(p, 0, size);
priv->tx_desc_alloc_size = size;
priv->tx_desc_cpu = p;
priv->tx_skb = kzalloc(sizeof(struct sk_buff *) * priv->tx_ring_size,
GFP_KERNEL);
if (!priv->tx_skb) {
dev_err(kdev, "cannot allocate rx skb queue\n");
ret = -ENOMEM;
goto out_free_tx_ring;
}
priv->tx_desc_count = priv->tx_ring_size;
priv->tx_dirty_desc = 0;
priv->tx_curr_desc = 0;
spin_lock_init(&priv->tx_lock);
priv->rx_skb = kzalloc(sizeof(struct sk_buff *) * priv->rx_ring_size,
GFP_KERNEL);
if (!priv->rx_skb) {
dev_err(kdev, "cannot allocate rx skb queue\n");
ret = -ENOMEM;
goto out_free_tx_skb;
}
priv->rx_desc_count = 0;
priv->rx_dirty_desc = 0;
priv->rx_curr_desc = 0;
enet_dma_writel(priv, ENETDMA_BUFALLOC_FORCE_MASK | 0,
ENETDMA_BUFALLOC_REG(priv->rx_chan));
if (bcm_enet_refill_rx(dev)) {
dev_err(kdev, "cannot allocate rx skb queue\n");
ret = -ENOMEM;
goto out;
}
enet_dma_writel(priv, priv->rx_desc_dma,
ENETDMA_RSTART_REG(priv->rx_chan));
enet_dma_writel(priv, priv->tx_desc_dma,
ENETDMA_RSTART_REG(priv->tx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM2_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM2_REG(priv->tx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM3_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM3_REG(priv->tx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM4_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_SRAM4_REG(priv->tx_chan));
enet_writel(priv, priv->hw_mtu, ENET_RXMAXLEN_REG);
enet_writel(priv, priv->hw_mtu, ENET_TXMAXLEN_REG);
enet_dma_writel(priv, BCMENET_DMA_MAXBURST,
ENETDMA_MAXBURST_REG(priv->rx_chan));
enet_dma_writel(priv, BCMENET_DMA_MAXBURST,
ENETDMA_MAXBURST_REG(priv->tx_chan));
enet_writel(priv, BCMENET_TX_FIFO_TRESH, ENET_TXWMARK_REG);
val = priv->rx_ring_size / 3;
enet_dma_writel(priv, val, ENETDMA_FLOWCL_REG(priv->rx_chan));
val = (priv->rx_ring_size * 2) / 3;
enet_dma_writel(priv, val, ENETDMA_FLOWCH_REG(priv->rx_chan));
wmb();
val = enet_readl(priv, ENET_CTL_REG);
val |= ENET_CTL_ENABLE_MASK;
enet_writel(priv, val, ENET_CTL_REG);
enet_dma_writel(priv, ENETDMA_CFG_EN_MASK, ENETDMA_CFG_REG);
enet_dma_writel(priv, ENETDMA_CHANCFG_EN_MASK,
ENETDMA_CHANCFG_REG(priv->rx_chan));
enet_writel(priv, ENET_IR_MIB, ENET_IR_REG);
enet_writel(priv, ENET_IR_MIB, ENET_IRMASK_REG);
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IR_REG(priv->rx_chan));
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IR_REG(priv->tx_chan));
napi_enable(&priv->napi);
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IRMASK_REG(priv->rx_chan));
enet_dma_writel(priv, ENETDMA_IR_PKTDONE_MASK,
ENETDMA_IRMASK_REG(priv->tx_chan));
if (priv->has_phy)
phy_start(priv->phydev);
else
bcm_enet_adjust_link(dev);
netif_start_queue(dev);
return 0;
out:
for (i = 0; i < priv->rx_ring_size; i++) {
struct bcm_enet_desc *desc;
if (!priv->rx_skb[i])
continue;
desc = &priv->rx_desc_cpu[i];
dma_unmap_single(kdev, desc->address, priv->rx_skb_size,
DMA_FROM_DEVICE);
kfree_skb(priv->rx_skb[i]);
}
kfree(priv->rx_skb);
out_free_tx_skb:
kfree(priv->tx_skb);
out_free_tx_ring:
dma_free_coherent(kdev, priv->tx_desc_alloc_size,
priv->tx_desc_cpu, priv->tx_desc_dma);
out_free_rx_ring:
dma_free_coherent(kdev, priv->rx_desc_alloc_size,
priv->rx_desc_cpu, priv->rx_desc_dma);
out_freeirq_tx:
free_irq(priv->irq_tx, dev);
out_freeirq_rx:
free_irq(priv->irq_rx, dev);
out_freeirq:
free_irq(dev->irq, dev);
out_phy_disconnect:
phy_disconnect(priv->phydev);
return ret;
}
static void bcm_enet_disable_mac(struct bcm_enet_priv *priv)
{
int limit;
u32 val;
val = enet_readl(priv, ENET_CTL_REG);
val |= ENET_CTL_DISABLE_MASK;
enet_writel(priv, val, ENET_CTL_REG);
limit = 1000;
do {
u32 val;
val = enet_readl(priv, ENET_CTL_REG);
if (!(val & ENET_CTL_DISABLE_MASK))
break;
udelay(1);
} while (limit--);
}
static void bcm_enet_disable_dma(struct bcm_enet_priv *priv, int chan)
{
int limit;
enet_dma_writel(priv, 0, ENETDMA_CHANCFG_REG(chan));
limit = 1000;
do {
u32 val;
val = enet_dma_readl(priv, ENETDMA_CHANCFG_REG(chan));
if (!(val & ENETDMA_CHANCFG_EN_MASK))
break;
udelay(1);
} while (limit--);
}
static int bcm_enet_stop(struct net_device *dev)
{
struct bcm_enet_priv *priv;
struct device *kdev;
int i;
priv = netdev_priv(dev);
kdev = &priv->pdev->dev;
netif_stop_queue(dev);
napi_disable(&priv->napi);
if (priv->has_phy)
phy_stop(priv->phydev);
del_timer_sync(&priv->rx_timeout);
enet_writel(priv, 0, ENET_IRMASK_REG);
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->rx_chan));
enet_dma_writel(priv, 0, ENETDMA_IRMASK_REG(priv->tx_chan));
cancel_work_sync(&priv->mib_update_task);
bcm_enet_disable_dma(priv, priv->tx_chan);
bcm_enet_disable_dma(priv, priv->rx_chan);
bcm_enet_disable_mac(priv);
bcm_enet_tx_reclaim(dev, 1);
for (i = 0; i < priv->rx_ring_size; i++) {
struct bcm_enet_desc *desc;
if (!priv->rx_skb[i])
continue;
desc = &priv->rx_desc_cpu[i];
dma_unmap_single(kdev, desc->address, priv->rx_skb_size,
DMA_FROM_DEVICE);
kfree_skb(priv->rx_skb[i]);
}
kfree(priv->rx_skb);
kfree(priv->tx_skb);
dma_free_coherent(kdev, priv->rx_desc_alloc_size,
priv->rx_desc_cpu, priv->rx_desc_dma);
dma_free_coherent(kdev, priv->tx_desc_alloc_size,
priv->tx_desc_cpu, priv->tx_desc_dma);
free_irq(priv->irq_tx, dev);
free_irq(priv->irq_rx, dev);
free_irq(dev->irq, dev);
if (priv->has_phy) {
phy_disconnect(priv->phydev);
priv->phydev = NULL;
}
return 0;
}
static void bcm_enet_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strncpy(drvinfo->driver, bcm_enet_driver_name, 32);
strncpy(drvinfo->version, bcm_enet_driver_version, 32);
strncpy(drvinfo->fw_version, "N/A", 32);
strncpy(drvinfo->bus_info, "bcm63xx", 32);
drvinfo->n_stats = BCM_ENET_STATS_LEN;
}
static int bcm_enet_get_sset_count(struct net_device *netdev,
int string_set)
{
switch (string_set) {
case ETH_SS_STATS:
return BCM_ENET_STATS_LEN;
default:
return -EINVAL;
}
}
static void bcm_enet_get_strings(struct net_device *netdev,
u32 stringset, u8 *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < BCM_ENET_STATS_LEN; i++) {
memcpy(data + i * ETH_GSTRING_LEN,
bcm_enet_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
}
break;
}
}
static void update_mib_counters(struct bcm_enet_priv *priv)
{
int i;
for (i = 0; i < BCM_ENET_STATS_LEN; i++) {
const struct bcm_enet_stats *s;
u32 val;
char *p;
s = &bcm_enet_gstrings_stats[i];
if (s->mib_reg == -1)
continue;
val = enet_readl(priv, ENET_MIB_REG(s->mib_reg));
p = (char *)priv + s->stat_offset;
if (s->sizeof_stat == sizeof(u64))
*(u64 *)p += val;
else
*(u32 *)p += val;
}
for (i = 0; i < ARRAY_SIZE(unused_mib_regs); i++)
(void)enet_readl(priv, ENET_MIB_REG(unused_mib_regs[i]));
}
static void bcm_enet_update_mib_counters_defer(struct work_struct *t)
{
struct bcm_enet_priv *priv;
priv = container_of(t, struct bcm_enet_priv, mib_update_task);
mutex_lock(&priv->mib_update_lock);
update_mib_counters(priv);
mutex_unlock(&priv->mib_update_lock);
if (netif_running(priv->net_dev))
enet_writel(priv, ENET_IR_MIB, ENET_IRMASK_REG);
}
static void bcm_enet_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats,
u64 *data)
{
struct bcm_enet_priv *priv;
int i;
priv = netdev_priv(netdev);
mutex_lock(&priv->mib_update_lock);
update_mib_counters(priv);
for (i = 0; i < BCM_ENET_STATS_LEN; i++) {
const struct bcm_enet_stats *s;
char *p;
s = &bcm_enet_gstrings_stats[i];
if (s->mib_reg == -1)
p = (char *)&netdev->stats;
else
p = (char *)priv;
p += s->stat_offset;
data[i] = (s->sizeof_stat == sizeof(u64)) ?
*(u64 *)p : *(u32 *)p;
}
mutex_unlock(&priv->mib_update_lock);
}
static int bcm_enet_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
cmd->maxrxpkt = 0;
cmd->maxtxpkt = 0;
if (priv->has_phy) {
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_gset(priv->phydev, cmd);
} else {
cmd->autoneg = 0;
ethtool_cmd_speed_set(cmd, ((priv->force_speed_100)
? SPEED_100 : SPEED_10));
cmd->duplex = (priv->force_duplex_full) ?
DUPLEX_FULL : DUPLEX_HALF;
cmd->supported = ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full;
cmd->advertising = 0;
cmd->port = PORT_MII;
cmd->transceiver = XCVR_EXTERNAL;
}
return 0;
}
static int bcm_enet_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
if (priv->has_phy) {
if (!priv->phydev)
return -ENODEV;
return phy_ethtool_sset(priv->phydev, cmd);
} else {
if (cmd->autoneg ||
(cmd->speed != SPEED_100 && cmd->speed != SPEED_10) ||
cmd->port != PORT_MII)
return -EINVAL;
priv->force_speed_100 = (cmd->speed == SPEED_100) ? 1 : 0;
priv->force_duplex_full = (cmd->duplex == DUPLEX_FULL) ? 1 : 0;
if (netif_running(dev))
bcm_enet_adjust_link(dev);
return 0;
}
}
static void bcm_enet_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
ering->rx_max_pending = 8192;
ering->tx_max_pending = 8192;
ering->rx_pending = priv->rx_ring_size;
ering->tx_pending = priv->tx_ring_size;
}
static int bcm_enet_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct bcm_enet_priv *priv;
int was_running;
priv = netdev_priv(dev);
was_running = 0;
if (netif_running(dev)) {
bcm_enet_stop(dev);
was_running = 1;
}
priv->rx_ring_size = ering->rx_pending;
priv->tx_ring_size = ering->tx_pending;
if (was_running) {
int err;
err = bcm_enet_open(dev);
if (err)
dev_close(dev);
else
bcm_enet_set_multicast_list(dev);
}
return 0;
}
static void bcm_enet_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *ecmd)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
ecmd->autoneg = priv->pause_auto;
ecmd->rx_pause = priv->pause_rx;
ecmd->tx_pause = priv->pause_tx;
}
static int bcm_enet_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *ecmd)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
if (priv->has_phy) {
if (ecmd->autoneg && (ecmd->rx_pause != ecmd->tx_pause)) {
return -EINVAL;
}
} else {
if (ecmd->autoneg)
return -EINVAL;
}
priv->pause_auto = ecmd->autoneg;
priv->pause_rx = ecmd->rx_pause;
priv->pause_tx = ecmd->tx_pause;
return 0;
}
static int bcm_enet_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct bcm_enet_priv *priv;
priv = netdev_priv(dev);
if (priv->has_phy) {
if (!priv->phydev)
return -ENODEV;
return phy_mii_ioctl(priv->phydev, rq, cmd);
} else {
struct mii_if_info mii;
mii.dev = dev;
mii.mdio_read = bcm_enet_mdio_read_mii;
mii.mdio_write = bcm_enet_mdio_write_mii;
mii.phy_id = 0;
mii.phy_id_mask = 0x3f;
mii.reg_num_mask = 0x1f;
return generic_mii_ioctl(&mii, if_mii(rq), cmd, NULL);
}
}
static int compute_hw_mtu(struct bcm_enet_priv *priv, int mtu)
{
int actual_mtu;
actual_mtu = mtu;
actual_mtu += VLAN_ETH_HLEN;
if (actual_mtu < 64 || actual_mtu > BCMENET_MAX_MTU)
return -EINVAL;
priv->hw_mtu = actual_mtu;
priv->rx_skb_size = ALIGN(actual_mtu + ETH_FCS_LEN,
BCMENET_DMA_MAXBURST * 4);
return 0;
}
static int bcm_enet_change_mtu(struct net_device *dev, int new_mtu)
{
int ret;
if (netif_running(dev))
return -EBUSY;
ret = compute_hw_mtu(netdev_priv(dev), new_mtu);
if (ret)
return ret;
dev->mtu = new_mtu;
return 0;
}
static void bcm_enet_hw_preinit(struct bcm_enet_priv *priv)
{
u32 val;
int limit;
bcm_enet_disable_mac(priv);
val = ENET_CTL_SRESET_MASK;
enet_writel(priv, val, ENET_CTL_REG);
wmb();
limit = 1000;
do {
val = enet_readl(priv, ENET_CTL_REG);
if (!(val & ENET_CTL_SRESET_MASK))
break;
udelay(1);
} while (limit--);
val = enet_readl(priv, ENET_CTL_REG);
if (priv->use_external_mii)
val |= ENET_CTL_EPHYSEL_MASK;
else
val &= ~ENET_CTL_EPHYSEL_MASK;
enet_writel(priv, val, ENET_CTL_REG);
enet_writel(priv, (0x1f << ENET_MIISC_MDCFREQDIV_SHIFT) |
ENET_MIISC_PREAMBLEEN_MASK, ENET_MIISC_REG);
val = enet_readl(priv, ENET_MIBCTL_REG);
val |= ENET_MIBCTL_RDCLEAR_MASK;
enet_writel(priv, val, ENET_MIBCTL_REG);
}
static int __devinit bcm_enet_probe(struct platform_device *pdev)
{
struct bcm_enet_priv *priv;
struct net_device *dev;
struct bcm63xx_enet_platform_data *pd;
struct resource *res_mem, *res_irq, *res_irq_rx, *res_irq_tx;
struct mii_bus *bus;
const char *clk_name;
unsigned int iomem_size;
int i, ret;
if (!bcm_enet_shared_base)
return -ENODEV;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
res_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
res_irq_rx = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
res_irq_tx = platform_get_resource(pdev, IORESOURCE_IRQ, 2);
if (!res_mem || !res_irq || !res_irq_rx || !res_irq_tx)
return -ENODEV;
ret = 0;
dev = alloc_etherdev(sizeof(*priv));
if (!dev)
return -ENOMEM;
priv = netdev_priv(dev);
ret = compute_hw_mtu(priv, dev->mtu);
if (ret)
goto out;
iomem_size = resource_size(res_mem);
if (!request_mem_region(res_mem->start, iomem_size, "bcm63xx_enet")) {
ret = -EBUSY;
goto out;
}
priv->base = ioremap(res_mem->start, iomem_size);
if (priv->base == NULL) {
ret = -ENOMEM;
goto out_release_mem;
}
dev->irq = priv->irq = res_irq->start;
priv->irq_rx = res_irq_rx->start;
priv->irq_tx = res_irq_tx->start;
priv->mac_id = pdev->id;
if (priv->mac_id == 0) {
priv->rx_chan = 0;
priv->tx_chan = 1;
clk_name = "enet0";
} else {
priv->rx_chan = 2;
priv->tx_chan = 3;
clk_name = "enet1";
}
priv->mac_clk = clk_get(&pdev->dev, clk_name);
if (IS_ERR(priv->mac_clk)) {
ret = PTR_ERR(priv->mac_clk);
goto out_unmap;
}
clk_enable(priv->mac_clk);
priv->rx_ring_size = BCMENET_DEF_RX_DESC;
priv->tx_ring_size = BCMENET_DEF_TX_DESC;
pd = pdev->dev.platform_data;
if (pd) {
memcpy(dev->dev_addr, pd->mac_addr, ETH_ALEN);
priv->has_phy = pd->has_phy;
priv->phy_id = pd->phy_id;
priv->has_phy_interrupt = pd->has_phy_interrupt;
priv->phy_interrupt = pd->phy_interrupt;
priv->use_external_mii = !pd->use_internal_phy;
priv->pause_auto = pd->pause_auto;
priv->pause_rx = pd->pause_rx;
priv->pause_tx = pd->pause_tx;
priv->force_duplex_full = pd->force_duplex_full;
priv->force_speed_100 = pd->force_speed_100;
}
if (priv->mac_id == 0 && priv->has_phy && !priv->use_external_mii) {
priv->phy_clk = clk_get(&pdev->dev, "ephy");
if (IS_ERR(priv->phy_clk)) {
ret = PTR_ERR(priv->phy_clk);
priv->phy_clk = NULL;
goto out_put_clk_mac;
}
clk_enable(priv->phy_clk);
}
bcm_enet_hw_preinit(priv);
if (priv->has_phy) {
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus) {
ret = -ENOMEM;
goto out_uninit_hw;
}
bus = priv->mii_bus;
bus->name = "bcm63xx_enet MII bus";
bus->parent = &pdev->dev;
bus->priv = priv;
bus->read = bcm_enet_mdio_read_phylib;
bus->write = bcm_enet_mdio_write_phylib;
sprintf(bus->id, "%d", priv->mac_id);
bus->phy_mask = ~(1 << priv->phy_id);
bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!bus->irq) {
ret = -ENOMEM;
goto out_free_mdio;
}
if (priv->has_phy_interrupt)
bus->irq[priv->phy_id] = priv->phy_interrupt;
else
bus->irq[priv->phy_id] = PHY_POLL;
ret = mdiobus_register(bus);
if (ret) {
dev_err(&pdev->dev, "unable to register mdio bus\n");
goto out_free_mdio;
}
} else {
if (pd->mii_config &&
pd->mii_config(dev, 1, bcm_enet_mdio_read_mii,
bcm_enet_mdio_write_mii)) {
dev_err(&pdev->dev, "unable to configure mdio bus\n");
goto out_uninit_hw;
}
}
spin_lock_init(&priv->rx_lock);
init_timer(&priv->rx_timeout);
priv->rx_timeout.function = bcm_enet_refill_rx_timer;
priv->rx_timeout.data = (unsigned long)dev;
mutex_init(&priv->mib_update_lock);
INIT_WORK(&priv->mib_update_task, bcm_enet_update_mib_counters_defer);
for (i = 0; i < ENET_MIB_REG_COUNT; i++)
enet_writel(priv, 0, ENET_MIB_REG(i));
dev->netdev_ops = &bcm_enet_ops;
netif_napi_add(dev, &priv->napi, bcm_enet_poll, 16);
SET_ETHTOOL_OPS(dev, &bcm_enet_ethtool_ops);
SET_NETDEV_DEV(dev, &pdev->dev);
ret = register_netdev(dev);
if (ret)
goto out_unregister_mdio;
netif_carrier_off(dev);
platform_set_drvdata(pdev, dev);
priv->pdev = pdev;
priv->net_dev = dev;
return 0;
out_unregister_mdio:
if (priv->mii_bus) {
mdiobus_unregister(priv->mii_bus);
kfree(priv->mii_bus->irq);
}
out_free_mdio:
if (priv->mii_bus)
mdiobus_free(priv->mii_bus);
out_uninit_hw:
enet_writel(priv, 0, ENET_MIISC_REG);
if (priv->phy_clk) {
clk_disable(priv->phy_clk);
clk_put(priv->phy_clk);
}
out_put_clk_mac:
clk_disable(priv->mac_clk);
clk_put(priv->mac_clk);
out_unmap:
iounmap(priv->base);
out_release_mem:
release_mem_region(res_mem->start, iomem_size);
out:
free_netdev(dev);
return ret;
}
static int __devexit bcm_enet_remove(struct platform_device *pdev)
{
struct bcm_enet_priv *priv;
struct net_device *dev;
struct resource *res;
dev = platform_get_drvdata(pdev);
priv = netdev_priv(dev);
unregister_netdev(dev);
enet_writel(priv, 0, ENET_MIISC_REG);
if (priv->has_phy) {
mdiobus_unregister(priv->mii_bus);
kfree(priv->mii_bus->irq);
mdiobus_free(priv->mii_bus);
} else {
struct bcm63xx_enet_platform_data *pd;
pd = pdev->dev.platform_data;
if (pd && pd->mii_config)
pd->mii_config(dev, 0, bcm_enet_mdio_read_mii,
bcm_enet_mdio_write_mii);
}
iounmap(priv->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
if (priv->phy_clk) {
clk_disable(priv->phy_clk);
clk_put(priv->phy_clk);
}
clk_disable(priv->mac_clk);
clk_put(priv->mac_clk);
platform_set_drvdata(pdev, NULL);
free_netdev(dev);
return 0;
}
static int __devinit bcm_enet_shared_probe(struct platform_device *pdev)
{
struct resource *res;
unsigned int iomem_size;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
iomem_size = resource_size(res);
if (!request_mem_region(res->start, iomem_size, "bcm63xx_enet_dma"))
return -EBUSY;
bcm_enet_shared_base = ioremap(res->start, iomem_size);
if (!bcm_enet_shared_base) {
release_mem_region(res->start, iomem_size);
return -ENOMEM;
}
return 0;
}
static int __devexit bcm_enet_shared_remove(struct platform_device *pdev)
{
struct resource *res;
iounmap(bcm_enet_shared_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
return 0;
}
static int __init bcm_enet_init(void)
{
int ret;
ret = platform_driver_register(&bcm63xx_enet_shared_driver);
if (ret)
return ret;
ret = platform_driver_register(&bcm63xx_enet_driver);
if (ret)
platform_driver_unregister(&bcm63xx_enet_shared_driver);
return ret;
}
static void __exit bcm_enet_exit(void)
{
platform_driver_unregister(&bcm63xx_enet_driver);
platform_driver_unregister(&bcm63xx_enet_shared_driver);
}
