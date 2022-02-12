static inline unsigned int tx_count(unsigned int head, unsigned int tail)
{
return (head - tail) % (TX_DESC_NUM - 1);
}
static void hip04_config_port(struct net_device *ndev, u32 speed, u32 duplex)
{
struct hip04_priv *priv = netdev_priv(ndev);
u32 val;
priv->speed = speed;
priv->duplex = duplex;
switch (priv->phy_mode) {
case PHY_INTERFACE_MODE_SGMII:
if (speed == SPEED_1000)
val = SGMII_SPEED_1000;
else if (speed == SPEED_100)
val = SGMII_SPEED_100;
else
val = SGMII_SPEED_10;
break;
case PHY_INTERFACE_MODE_MII:
if (speed == SPEED_100)
val = MII_SPEED_100;
else
val = MII_SPEED_10;
break;
default:
netdev_warn(ndev, "not supported mode\n");
val = MII_SPEED_10;
break;
}
writel_relaxed(val, priv->base + GE_PORT_MODE);
val = duplex ? GE_DUPLEX_FULL : GE_DUPLEX_HALF;
writel_relaxed(val, priv->base + GE_DUPLEX_TYPE);
val = GE_MODE_CHANGE_EN;
writel_relaxed(val, priv->base + GE_MODE_CHANGE_REG);
}
static void hip04_reset_ppe(struct hip04_priv *priv)
{
u32 val, tmp, timeout = 0;
do {
regmap_read(priv->map, priv->port * 4 + PPE_CURR_BUF_CNT, &val);
regmap_read(priv->map, priv->port * 4 + PPE_CFG_RX_ADDR, &tmp);
if (timeout++ > RESET_TIMEOUT)
break;
} while (val & 0xfff);
}
static void hip04_config_fifo(struct hip04_priv *priv)
{
u32 val;
val = readl_relaxed(priv->base + PPE_CFG_STS_MODE);
val |= PPE_CFG_STS_RX_PKT_CNT_RC;
writel_relaxed(val, priv->base + PPE_CFG_STS_MODE);
val = BIT(priv->port);
regmap_write(priv->map, priv->port * 4 + PPE_CFG_POOL_GRP, val);
val = priv->port << PPE_CFG_QOS_VMID_GRP_SHIFT;
val |= PPE_CFG_QOS_VMID_MODE;
writel_relaxed(val, priv->base + PPE_CFG_QOS_VMID_GEN);
val = RX_BUF_SIZE;
regmap_write(priv->map, priv->port * 4 + PPE_CFG_RX_BUF_SIZE, val);
val = RX_DESC_NUM << PPE_CFG_RX_DEPTH_SHIFT;
val |= PPE_CFG_RX_FIFO_FSFU;
val |= priv->chan << PPE_CFG_RX_START_SHIFT;
regmap_write(priv->map, priv->port * 4 + PPE_CFG_RX_FIFO_SIZE, val);
val = NET_IP_ALIGN << PPE_CFG_RX_CTRL_ALIGN_SHIFT;
writel_relaxed(val, priv->base + PPE_CFG_RX_CTRL_REG);
val = PPE_CFG_RX_PKT_ALIGN;
writel_relaxed(val, priv->base + PPE_CFG_RX_PKT_MODE_REG);
val = PPE_CFG_BUS_LOCAL_REL | PPE_CFG_BUS_BIG_ENDIEN;
writel_relaxed(val, priv->base + PPE_CFG_BUS_CTRL_REG);
val = GMAC_PPE_RX_PKT_MAX_LEN;
writel_relaxed(val, priv->base + PPE_CFG_MAX_FRAME_LEN_REG);
val = GMAC_MAX_PKT_LEN;
writel_relaxed(val, priv->base + GE_MAX_FRM_SIZE_REG);
val = GMAC_MIN_PKT_LEN;
writel_relaxed(val, priv->base + GE_SHORT_RUNTS_THR_REG);
val = readl_relaxed(priv->base + GE_TRANSMIT_CONTROL_REG);
val |= GE_TX_AUTO_NEG | GE_TX_ADD_CRC | GE_TX_SHORT_PAD_THROUGH;
writel_relaxed(val, priv->base + GE_TRANSMIT_CONTROL_REG);
val = GE_RX_STRIP_CRC;
writel_relaxed(val, priv->base + GE_CF_CRC_STRIP_REG);
val = readl_relaxed(priv->base + GE_RECV_CONTROL_REG);
val |= GE_RX_STRIP_PAD | GE_RX_PAD_EN;
writel_relaxed(val, priv->base + GE_RECV_CONTROL_REG);
val = GE_AUTO_NEG_CTL;
writel_relaxed(val, priv->base + GE_TX_LOCAL_PAGE_REG);
}
static void hip04_mac_enable(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
u32 val;
val = readl_relaxed(priv->base + GE_PORT_EN);
val |= GE_RX_PORT_EN | GE_TX_PORT_EN;
writel_relaxed(val, priv->base + GE_PORT_EN);
val = RCV_INT;
writel_relaxed(val, priv->base + PPE_RINT);
val = GE_RX_INT_THRESHOLD | GE_RX_TIMEOUT;
writel_relaxed(val, priv->base + PPE_CFG_RX_PKT_INT);
priv->reg_inten = DEF_INT_MASK;
writel_relaxed(priv->reg_inten, priv->base + PPE_INTEN);
}
static void hip04_mac_disable(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
u32 val;
priv->reg_inten &= ~(DEF_INT_MASK);
writel_relaxed(priv->reg_inten, priv->base + PPE_INTEN);
val = readl_relaxed(priv->base + GE_PORT_EN);
val &= ~(GE_RX_PORT_EN | GE_TX_PORT_EN);
writel_relaxed(val, priv->base + GE_PORT_EN);
}
static void hip04_set_xmit_desc(struct hip04_priv *priv, dma_addr_t phys)
{
writel(phys, priv->base + PPE_CFG_CPU_ADD_ADDR);
}
static void hip04_set_recv_desc(struct hip04_priv *priv, dma_addr_t phys)
{
regmap_write(priv->map, priv->port * 4 + PPE_CFG_RX_ADDR, phys);
}
static u32 hip04_recv_cnt(struct hip04_priv *priv)
{
return readl(priv->base + PPE_HIS_RX_PKT_CNT);
}
static void hip04_update_mac_address(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
writel_relaxed(((ndev->dev_addr[0] << 8) | (ndev->dev_addr[1])),
priv->base + GE_STATION_MAC_ADDRESS);
writel_relaxed(((ndev->dev_addr[2] << 24) | (ndev->dev_addr[3] << 16) |
(ndev->dev_addr[4] << 8) | (ndev->dev_addr[5])),
priv->base + GE_STATION_MAC_ADDRESS + 4);
}
static int hip04_set_mac_address(struct net_device *ndev, void *addr)
{
eth_mac_addr(ndev, addr);
hip04_update_mac_address(ndev);
return 0;
}
static int hip04_tx_reclaim(struct net_device *ndev, bool force)
{
struct hip04_priv *priv = netdev_priv(ndev);
unsigned tx_tail = priv->tx_tail;
struct tx_desc *desc;
unsigned int bytes_compl = 0, pkts_compl = 0;
unsigned int count;
smp_rmb();
count = tx_count(ACCESS_ONCE(priv->tx_head), tx_tail);
if (count == 0)
goto out;
while (count) {
desc = &priv->tx_desc[tx_tail];
if (desc->send_addr != 0) {
if (force)
desc->send_addr = 0;
else
break;
}
if (priv->tx_phys[tx_tail]) {
dma_unmap_single(&ndev->dev, priv->tx_phys[tx_tail],
priv->tx_skb[tx_tail]->len,
DMA_TO_DEVICE);
priv->tx_phys[tx_tail] = 0;
}
pkts_compl++;
bytes_compl += priv->tx_skb[tx_tail]->len;
dev_kfree_skb(priv->tx_skb[tx_tail]);
priv->tx_skb[tx_tail] = NULL;
tx_tail = TX_NEXT(tx_tail);
count--;
}
priv->tx_tail = tx_tail;
smp_wmb();
out:
if (pkts_compl || bytes_compl)
netdev_completed_queue(ndev, pkts_compl, bytes_compl);
if (unlikely(netif_queue_stopped(ndev)) && (count < (TX_DESC_NUM - 1)))
netif_wake_queue(ndev);
return count;
}
static void hip04_start_tx_timer(struct hip04_priv *priv)
{
unsigned long ns = priv->tx_coalesce_usecs * NSEC_PER_USEC / 2;
hrtimer_start_range_ns(&priv->tx_coalesce_timer, ns_to_ktime(ns),
ns, HRTIMER_MODE_REL);
}
static int hip04_mac_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
unsigned int tx_head = priv->tx_head, count;
struct tx_desc *desc = &priv->tx_desc[tx_head];
dma_addr_t phys;
smp_rmb();
count = tx_count(tx_head, ACCESS_ONCE(priv->tx_tail));
if (count == (TX_DESC_NUM - 1)) {
netif_stop_queue(ndev);
return NETDEV_TX_BUSY;
}
phys = dma_map_single(&ndev->dev, skb->data, skb->len, DMA_TO_DEVICE);
if (dma_mapping_error(&ndev->dev, phys)) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
priv->tx_skb[tx_head] = skb;
priv->tx_phys[tx_head] = phys;
desc->send_addr = cpu_to_be32(phys);
desc->send_size = cpu_to_be32(skb->len);
desc->cfg = cpu_to_be32(TX_CLEAR_WB | TX_FINISH_CACHE_INV);
phys = priv->tx_desc_dma + tx_head * sizeof(struct tx_desc);
desc->wb_addr = cpu_to_be32(phys);
skb_tx_timestamp(skb);
hip04_set_xmit_desc(priv, phys);
priv->tx_head = TX_NEXT(tx_head);
count++;
netdev_sent_queue(ndev, skb->len);
stats->tx_bytes += skb->len;
stats->tx_packets++;
smp_wmb();
if (count >= priv->tx_coalesce_frames) {
if (napi_schedule_prep(&priv->napi)) {
priv->reg_inten &= ~(RCV_INT);
writel_relaxed(DEF_INT_MASK & ~RCV_INT,
priv->base + PPE_INTEN);
hrtimer_cancel(&priv->tx_coalesce_timer);
__napi_schedule(&priv->napi);
}
} else if (!hrtimer_is_queued(&priv->tx_coalesce_timer)) {
hip04_start_tx_timer(priv);
}
return NETDEV_TX_OK;
}
static int hip04_rx_poll(struct napi_struct *napi, int budget)
{
struct hip04_priv *priv = container_of(napi, struct hip04_priv, napi);
struct net_device *ndev = priv->ndev;
struct net_device_stats *stats = &ndev->stats;
unsigned int cnt = hip04_recv_cnt(priv);
struct rx_desc *desc;
struct sk_buff *skb;
unsigned char *buf;
bool last = false;
dma_addr_t phys;
int rx = 0;
int tx_remaining;
u16 len;
u32 err;
while (cnt && !last) {
buf = priv->rx_buf[priv->rx_head];
skb = build_skb(buf, priv->rx_buf_size);
if (unlikely(!skb))
net_dbg_ratelimited("build_skb failed\n");
dma_unmap_single(&ndev->dev, priv->rx_phys[priv->rx_head],
RX_BUF_SIZE, DMA_FROM_DEVICE);
priv->rx_phys[priv->rx_head] = 0;
desc = (struct rx_desc *)skb->data;
len = be16_to_cpu(desc->pkt_len);
err = be32_to_cpu(desc->pkt_err);
if (0 == len) {
dev_kfree_skb_any(skb);
last = true;
} else if ((err & RX_PKT_ERR) || (len >= GMAC_MAX_PKT_LEN)) {
dev_kfree_skb_any(skb);
stats->rx_dropped++;
stats->rx_errors++;
} else {
skb_reserve(skb, NET_SKB_PAD + NET_IP_ALIGN);
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, ndev);
napi_gro_receive(&priv->napi, skb);
stats->rx_packets++;
stats->rx_bytes += len;
rx++;
}
buf = netdev_alloc_frag(priv->rx_buf_size);
if (!buf)
goto done;
phys = dma_map_single(&ndev->dev, buf,
RX_BUF_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, phys))
goto done;
priv->rx_buf[priv->rx_head] = buf;
priv->rx_phys[priv->rx_head] = phys;
hip04_set_recv_desc(priv, phys);
priv->rx_head = RX_NEXT(priv->rx_head);
if (rx >= budget)
goto done;
if (--cnt == 0)
cnt = hip04_recv_cnt(priv);
}
if (!(priv->reg_inten & RCV_INT)) {
priv->reg_inten |= RCV_INT;
writel_relaxed(priv->reg_inten, priv->base + PPE_INTEN);
}
napi_complete(napi);
done:
tx_remaining = hip04_tx_reclaim(ndev, false);
if (rx < budget && tx_remaining)
hip04_start_tx_timer(priv);
return rx;
}
static irqreturn_t hip04_mac_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct hip04_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
u32 ists = readl_relaxed(priv->base + PPE_INTSTS);
if (!ists)
return IRQ_NONE;
writel_relaxed(DEF_INT_MASK, priv->base + PPE_RINT);
if (unlikely(ists & DEF_INT_ERR)) {
if (ists & (RCV_NOBUF | RCV_DROP)) {
stats->rx_errors++;
stats->rx_dropped++;
netdev_err(ndev, "rx drop\n");
}
if (ists & TX_DROP) {
stats->tx_dropped++;
netdev_err(ndev, "tx drop\n");
}
}
if (ists & RCV_INT && napi_schedule_prep(&priv->napi)) {
priv->reg_inten &= ~(RCV_INT);
writel_relaxed(DEF_INT_MASK & ~RCV_INT, priv->base + PPE_INTEN);
hrtimer_cancel(&priv->tx_coalesce_timer);
__napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
enum hrtimer_restart tx_done(struct hrtimer *hrtimer)
{
struct hip04_priv *priv;
priv = container_of(hrtimer, struct hip04_priv, tx_coalesce_timer);
if (napi_schedule_prep(&priv->napi)) {
priv->reg_inten &= ~(RCV_INT);
writel_relaxed(DEF_INT_MASK & ~RCV_INT, priv->base + PPE_INTEN);
__napi_schedule(&priv->napi);
}
return HRTIMER_NORESTART;
}
static void hip04_adjust_link(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
struct phy_device *phy = priv->phy;
if ((priv->speed != phy->speed) || (priv->duplex != phy->duplex)) {
hip04_config_port(ndev, phy->speed, phy->duplex);
phy_print_status(phy);
}
}
static int hip04_mac_open(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
int i;
priv->rx_head = 0;
priv->tx_head = 0;
priv->tx_tail = 0;
hip04_reset_ppe(priv);
for (i = 0; i < RX_DESC_NUM; i++) {
dma_addr_t phys;
phys = dma_map_single(&ndev->dev, priv->rx_buf[i],
RX_BUF_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, phys))
return -EIO;
priv->rx_phys[i] = phys;
hip04_set_recv_desc(priv, phys);
}
if (priv->phy)
phy_start(priv->phy);
netdev_reset_queue(ndev);
netif_start_queue(ndev);
hip04_mac_enable(ndev);
napi_enable(&priv->napi);
return 0;
}
static int hip04_mac_stop(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
int i;
napi_disable(&priv->napi);
netif_stop_queue(ndev);
hip04_mac_disable(ndev);
hip04_tx_reclaim(ndev, true);
hip04_reset_ppe(priv);
if (priv->phy)
phy_stop(priv->phy);
for (i = 0; i < RX_DESC_NUM; i++) {
if (priv->rx_phys[i]) {
dma_unmap_single(&ndev->dev, priv->rx_phys[i],
RX_BUF_SIZE, DMA_FROM_DEVICE);
priv->rx_phys[i] = 0;
}
}
return 0;
}
static void hip04_timeout(struct net_device *ndev)
{
struct hip04_priv *priv = netdev_priv(ndev);
schedule_work(&priv->tx_timeout_task);
}
static void hip04_tx_timeout_task(struct work_struct *work)
{
struct hip04_priv *priv;
priv = container_of(work, struct hip04_priv, tx_timeout_task);
hip04_mac_stop(priv->ndev);
hip04_mac_open(priv->ndev);
}
static struct net_device_stats *hip04_get_stats(struct net_device *ndev)
{
return &ndev->stats;
}
static int hip04_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct hip04_priv *priv = netdev_priv(netdev);
ec->tx_coalesce_usecs = priv->tx_coalesce_usecs;
ec->tx_max_coalesced_frames = priv->tx_coalesce_frames;
return 0;
}
static int hip04_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct hip04_priv *priv = netdev_priv(netdev);
if ((ec->rx_max_coalesced_frames) || (ec->rx_coalesce_usecs_irq) ||
(ec->rx_max_coalesced_frames_irq) || (ec->tx_coalesce_usecs_irq) ||
(ec->use_adaptive_rx_coalesce) || (ec->use_adaptive_tx_coalesce) ||
(ec->pkt_rate_low) || (ec->rx_coalesce_usecs_low) ||
(ec->rx_max_coalesced_frames_low) || (ec->tx_coalesce_usecs_high) ||
(ec->tx_max_coalesced_frames_low) || (ec->pkt_rate_high) ||
(ec->tx_coalesce_usecs_low) || (ec->rx_coalesce_usecs_high) ||
(ec->rx_max_coalesced_frames_high) || (ec->rx_coalesce_usecs) ||
(ec->tx_max_coalesced_frames_irq) ||
(ec->stats_block_coalesce_usecs) ||
(ec->tx_max_coalesced_frames_high) || (ec->rate_sample_interval))
return -EOPNOTSUPP;
if ((ec->tx_coalesce_usecs > HIP04_MAX_TX_COALESCE_USECS ||
ec->tx_coalesce_usecs < HIP04_MIN_TX_COALESCE_USECS) ||
(ec->tx_max_coalesced_frames > HIP04_MAX_TX_COALESCE_FRAMES ||
ec->tx_max_coalesced_frames < HIP04_MIN_TX_COALESCE_FRAMES))
return -EINVAL;
priv->tx_coalesce_usecs = ec->tx_coalesce_usecs;
priv->tx_coalesce_frames = ec->tx_max_coalesced_frames;
return 0;
}
static void hip04_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, DRV_VERSION, sizeof(drvinfo->version));
}
static int hip04_alloc_ring(struct net_device *ndev, struct device *d)
{
struct hip04_priv *priv = netdev_priv(ndev);
int i;
priv->tx_desc = dma_alloc_coherent(d,
TX_DESC_NUM * sizeof(struct tx_desc),
&priv->tx_desc_dma, GFP_KERNEL);
if (!priv->tx_desc)
return -ENOMEM;
priv->rx_buf_size = RX_BUF_SIZE +
SKB_DATA_ALIGN(sizeof(struct skb_shared_info));
for (i = 0; i < RX_DESC_NUM; i++) {
priv->rx_buf[i] = netdev_alloc_frag(priv->rx_buf_size);
if (!priv->rx_buf[i])
return -ENOMEM;
}
return 0;
}
static void hip04_free_ring(struct net_device *ndev, struct device *d)
{
struct hip04_priv *priv = netdev_priv(ndev);
int i;
for (i = 0; i < RX_DESC_NUM; i++)
if (priv->rx_buf[i])
skb_free_frag(priv->rx_buf[i]);
for (i = 0; i < TX_DESC_NUM; i++)
if (priv->tx_skb[i])
dev_kfree_skb_any(priv->tx_skb[i]);
dma_free_coherent(d, TX_DESC_NUM * sizeof(struct tx_desc),
priv->tx_desc, priv->tx_desc_dma);
}
static int hip04_mac_probe(struct platform_device *pdev)
{
struct device *d = &pdev->dev;
struct device_node *node = d->of_node;
struct of_phandle_args arg;
struct net_device *ndev;
struct hip04_priv *priv;
struct resource *res;
unsigned int irq;
int ret;
ndev = alloc_etherdev(sizeof(struct hip04_priv));
if (!ndev)
return -ENOMEM;
priv = netdev_priv(ndev);
priv->ndev = ndev;
platform_set_drvdata(pdev, ndev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(d, res);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto init_fail;
}
ret = of_parse_phandle_with_fixed_args(node, "port-handle", 2, 0, &arg);
if (ret < 0) {
dev_warn(d, "no port-handle\n");
goto init_fail;
}
priv->port = arg.args[0];
priv->chan = arg.args[1] * RX_DESC_NUM;
hrtimer_init(&priv->tx_coalesce_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
priv->tx_coalesce_frames = TX_DESC_NUM * 3 / 4;
priv->tx_coalesce_usecs = 200;
priv->tx_coalesce_timer.function = tx_done;
priv->map = syscon_node_to_regmap(arg.np);
if (IS_ERR(priv->map)) {
dev_warn(d, "no syscon hisilicon,hip04-ppe\n");
ret = PTR_ERR(priv->map);
goto init_fail;
}
priv->phy_mode = of_get_phy_mode(node);
if (priv->phy_mode < 0) {
dev_warn(d, "not find phy-mode\n");
ret = -EINVAL;
goto init_fail;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
ret = -EINVAL;
goto init_fail;
}
ret = devm_request_irq(d, irq, hip04_mac_interrupt,
0, pdev->name, ndev);
if (ret) {
netdev_err(ndev, "devm_request_irq failed\n");
goto init_fail;
}
priv->phy_node = of_parse_phandle(node, "phy-handle", 0);
if (priv->phy_node) {
priv->phy = of_phy_connect(ndev, priv->phy_node,
&hip04_adjust_link,
0, priv->phy_mode);
if (!priv->phy) {
ret = -EPROBE_DEFER;
goto init_fail;
}
}
INIT_WORK(&priv->tx_timeout_task, hip04_tx_timeout_task);
ether_setup(ndev);
ndev->netdev_ops = &hip04_netdev_ops;
ndev->ethtool_ops = &hip04_ethtool_ops;
ndev->watchdog_timeo = TX_TIMEOUT;
ndev->priv_flags |= IFF_UNICAST_FLT;
ndev->irq = irq;
netif_napi_add(ndev, &priv->napi, hip04_rx_poll, NAPI_POLL_WEIGHT);
SET_NETDEV_DEV(ndev, &pdev->dev);
hip04_reset_ppe(priv);
if (priv->phy_mode == PHY_INTERFACE_MODE_MII)
hip04_config_port(ndev, SPEED_100, DUPLEX_FULL);
hip04_config_fifo(priv);
random_ether_addr(ndev->dev_addr);
hip04_update_mac_address(ndev);
ret = hip04_alloc_ring(ndev, d);
if (ret) {
netdev_err(ndev, "alloc ring fail\n");
goto alloc_fail;
}
ret = register_netdev(ndev);
if (ret) {
free_netdev(ndev);
goto alloc_fail;
}
return 0;
alloc_fail:
hip04_free_ring(ndev, d);
init_fail:
of_node_put(priv->phy_node);
free_netdev(ndev);
return ret;
}
static int hip04_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct hip04_priv *priv = netdev_priv(ndev);
struct device *d = &pdev->dev;
if (priv->phy)
phy_disconnect(priv->phy);
hip04_free_ring(ndev, d);
unregister_netdev(ndev);
free_irq(ndev->irq, ndev);
of_node_put(priv->phy_node);
cancel_work_sync(&priv->tx_timeout_task);
free_netdev(ndev);
return 0;
}
