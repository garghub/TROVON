static inline int arc_emac_tx_avail(struct arc_emac_priv *priv)
{
return (priv->txbd_dirty + TX_BD_NUM - priv->txbd_curr - 1) % TX_BD_NUM;
}
static void arc_emac_adjust_link(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
struct phy_device *phy_dev = ndev->phydev;
unsigned int reg, state_changed = 0;
if (priv->link != phy_dev->link) {
priv->link = phy_dev->link;
state_changed = 1;
}
if (priv->speed != phy_dev->speed) {
priv->speed = phy_dev->speed;
state_changed = 1;
if (priv->set_mac_speed)
priv->set_mac_speed(priv, priv->speed);
}
if (priv->duplex != phy_dev->duplex) {
reg = arc_reg_get(priv, R_CTRL);
if (phy_dev->duplex == DUPLEX_FULL)
reg |= ENFL_MASK;
else
reg &= ~ENFL_MASK;
arc_reg_set(priv, R_CTRL, reg);
priv->duplex = phy_dev->duplex;
state_changed = 1;
}
if (state_changed)
phy_print_status(phy_dev);
}
static void arc_emac_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
strlcpy(info->driver, priv->drv_name, sizeof(info->driver));
strlcpy(info->version, priv->drv_version, sizeof(info->version));
}
static void arc_emac_tx_clean(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
unsigned int i;
for (i = 0; i < TX_BD_NUM; i++) {
unsigned int *txbd_dirty = &priv->txbd_dirty;
struct arc_emac_bd *txbd = &priv->txbd[*txbd_dirty];
struct buffer_state *tx_buff = &priv->tx_buff[*txbd_dirty];
struct sk_buff *skb = tx_buff->skb;
unsigned int info = le32_to_cpu(txbd->info);
if ((info & FOR_EMAC) || !txbd->data || !skb)
break;
if (unlikely(info & (DROP | DEFR | LTCL | UFLO))) {
stats->tx_errors++;
stats->tx_dropped++;
if (info & DEFR)
stats->tx_carrier_errors++;
if (info & LTCL)
stats->collisions++;
if (info & UFLO)
stats->tx_fifo_errors++;
} else if (likely(info & FIRST_OR_LAST_MASK)) {
stats->tx_packets++;
stats->tx_bytes += skb->len;
}
dma_unmap_single(&ndev->dev, dma_unmap_addr(tx_buff, addr),
dma_unmap_len(tx_buff, len), DMA_TO_DEVICE);
dev_kfree_skb_irq(skb);
txbd->data = 0;
txbd->info = 0;
tx_buff->skb = NULL;
*txbd_dirty = (*txbd_dirty + 1) % TX_BD_NUM;
}
smp_mb();
if (netif_queue_stopped(ndev) && arc_emac_tx_avail(priv))
netif_wake_queue(ndev);
}
static int arc_emac_rx(struct net_device *ndev, int budget)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int work_done;
for (work_done = 0; work_done < budget; work_done++) {
unsigned int *last_rx_bd = &priv->last_rx_bd;
struct net_device_stats *stats = &ndev->stats;
struct buffer_state *rx_buff = &priv->rx_buff[*last_rx_bd];
struct arc_emac_bd *rxbd = &priv->rxbd[*last_rx_bd];
unsigned int pktlen, info = le32_to_cpu(rxbd->info);
struct sk_buff *skb;
dma_addr_t addr;
if (unlikely((info & OWN_MASK) == FOR_EMAC))
break;
*last_rx_bd = (*last_rx_bd + 1) % RX_BD_NUM;
if (unlikely((info & FIRST_OR_LAST_MASK) !=
FIRST_OR_LAST_MASK)) {
if (net_ratelimit())
netdev_err(ndev, "incomplete packet received\n");
rxbd->info = cpu_to_le32(FOR_EMAC | EMAC_BUFFER_SIZE);
stats->rx_errors++;
stats->rx_length_errors++;
continue;
}
pktlen = info & LEN_MASK;
stats->rx_packets++;
stats->rx_bytes += pktlen;
skb = rx_buff->skb;
skb_put(skb, pktlen);
skb->dev = ndev;
skb->protocol = eth_type_trans(skb, ndev);
dma_unmap_single(&ndev->dev, dma_unmap_addr(rx_buff, addr),
dma_unmap_len(rx_buff, len), DMA_FROM_DEVICE);
rx_buff->skb = netdev_alloc_skb_ip_align(ndev,
EMAC_BUFFER_SIZE);
if (unlikely(!rx_buff->skb)) {
stats->rx_errors++;
stats->rx_dropped++;
continue;
}
netif_receive_skb(skb);
addr = dma_map_single(&ndev->dev, (void *)rx_buff->skb->data,
EMAC_BUFFER_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, addr)) {
if (net_ratelimit())
netdev_err(ndev, "cannot dma map\n");
dev_kfree_skb(rx_buff->skb);
stats->rx_errors++;
continue;
}
dma_unmap_addr_set(rx_buff, addr, addr);
dma_unmap_len_set(rx_buff, len, EMAC_BUFFER_SIZE);
rxbd->data = cpu_to_le32(addr);
wmb();
rxbd->info = cpu_to_le32(FOR_EMAC | EMAC_BUFFER_SIZE);
}
return work_done;
}
static int arc_emac_poll(struct napi_struct *napi, int budget)
{
struct net_device *ndev = napi->dev;
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int work_done;
arc_emac_tx_clean(ndev);
work_done = arc_emac_rx(ndev, budget);
if (work_done < budget) {
napi_complete(napi);
arc_reg_or(priv, R_ENABLE, RXINT_MASK | TXINT_MASK);
}
return work_done;
}
static irqreturn_t arc_emac_intr(int irq, void *dev_instance)
{
struct net_device *ndev = dev_instance;
struct arc_emac_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
unsigned int status;
status = arc_reg_get(priv, R_STATUS);
status &= ~MDIO_MASK;
arc_reg_set(priv, R_STATUS, status);
if (status & (RXINT_MASK | TXINT_MASK)) {
if (likely(napi_schedule_prep(&priv->napi))) {
arc_reg_clr(priv, R_ENABLE, RXINT_MASK | TXINT_MASK);
__napi_schedule(&priv->napi);
}
}
if (status & ERR_MASK) {
if (status & MSER_MASK) {
stats->rx_missed_errors += 0x100;
stats->rx_errors += 0x100;
}
if (status & RXCR_MASK) {
stats->rx_crc_errors += 0x100;
stats->rx_errors += 0x100;
}
if (status & RXFR_MASK) {
stats->rx_frame_errors += 0x100;
stats->rx_errors += 0x100;
}
if (status & RXFL_MASK) {
stats->rx_over_errors += 0x100;
stats->rx_errors += 0x100;
}
}
return IRQ_HANDLED;
}
static void arc_emac_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
arc_emac_intr(dev->irq, dev);
enable_irq(dev->irq);
}
static int arc_emac_open(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
struct phy_device *phy_dev = ndev->phydev;
int i;
phy_dev->autoneg = AUTONEG_ENABLE;
phy_dev->speed = 0;
phy_dev->duplex = 0;
phy_dev->advertising &= phy_dev->supported;
priv->last_rx_bd = 0;
for (i = 0; i < RX_BD_NUM; i++) {
dma_addr_t addr;
unsigned int *last_rx_bd = &priv->last_rx_bd;
struct arc_emac_bd *rxbd = &priv->rxbd[*last_rx_bd];
struct buffer_state *rx_buff = &priv->rx_buff[*last_rx_bd];
rx_buff->skb = netdev_alloc_skb_ip_align(ndev,
EMAC_BUFFER_SIZE);
if (unlikely(!rx_buff->skb))
return -ENOMEM;
addr = dma_map_single(&ndev->dev, (void *)rx_buff->skb->data,
EMAC_BUFFER_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&ndev->dev, addr)) {
netdev_err(ndev, "cannot dma map\n");
dev_kfree_skb(rx_buff->skb);
return -ENOMEM;
}
dma_unmap_addr_set(rx_buff, addr, addr);
dma_unmap_len_set(rx_buff, len, EMAC_BUFFER_SIZE);
rxbd->data = cpu_to_le32(addr);
wmb();
rxbd->info = cpu_to_le32(FOR_EMAC | EMAC_BUFFER_SIZE);
*last_rx_bd = (*last_rx_bd + 1) % RX_BD_NUM;
}
priv->txbd_curr = 0;
priv->txbd_dirty = 0;
memset(priv->txbd, 0, TX_RING_SZ);
arc_reg_set(priv, R_LAFL, 0);
arc_reg_set(priv, R_LAFH, 0);
arc_reg_set(priv, R_RX_RING, (unsigned int)priv->rxbd_dma);
arc_reg_set(priv, R_TX_RING, (unsigned int)priv->txbd_dma);
arc_reg_set(priv, R_ENABLE, RXINT_MASK | TXINT_MASK | ERR_MASK);
arc_reg_set(priv, R_CTRL,
(RX_BD_NUM << 24) |
(TX_BD_NUM << 16) |
TXRN_MASK | RXRN_MASK);
napi_enable(&priv->napi);
arc_reg_or(priv, R_CTRL, EN_MASK);
phy_start_aneg(ndev->phydev);
netif_start_queue(ndev);
return 0;
}
static void arc_emac_set_rx_mode(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
if (ndev->flags & IFF_PROMISC) {
arc_reg_or(priv, R_CTRL, PROM_MASK);
} else {
arc_reg_clr(priv, R_CTRL, PROM_MASK);
if (ndev->flags & IFF_ALLMULTI) {
arc_reg_set(priv, R_LAFL, ~0);
arc_reg_set(priv, R_LAFH, ~0);
} else {
struct netdev_hw_addr *ha;
unsigned int filter[2] = { 0, 0 };
int bit;
netdev_for_each_mc_addr(ha, ndev) {
bit = ether_crc_le(ETH_ALEN, ha->addr) >> 26;
filter[bit >> 5] |= 1 << (bit & 31);
}
arc_reg_set(priv, R_LAFL, filter[0]);
arc_reg_set(priv, R_LAFH, filter[1]);
}
}
}
static void arc_free_tx_queue(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int i;
for (i = 0; i < TX_BD_NUM; i++) {
struct arc_emac_bd *txbd = &priv->txbd[i];
struct buffer_state *tx_buff = &priv->tx_buff[i];
if (tx_buff->skb) {
dma_unmap_single(&ndev->dev,
dma_unmap_addr(tx_buff, addr),
dma_unmap_len(tx_buff, len),
DMA_TO_DEVICE);
dev_kfree_skb_irq(tx_buff->skb);
}
txbd->info = 0;
txbd->data = 0;
tx_buff->skb = NULL;
}
}
static void arc_free_rx_queue(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int i;
for (i = 0; i < RX_BD_NUM; i++) {
struct arc_emac_bd *rxbd = &priv->rxbd[i];
struct buffer_state *rx_buff = &priv->rx_buff[i];
if (rx_buff->skb) {
dma_unmap_single(&ndev->dev,
dma_unmap_addr(rx_buff, addr),
dma_unmap_len(rx_buff, len),
DMA_FROM_DEVICE);
dev_kfree_skb_irq(rx_buff->skb);
}
rxbd->info = 0;
rxbd->data = 0;
rx_buff->skb = NULL;
}
}
static int arc_emac_stop(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
napi_disable(&priv->napi);
netif_stop_queue(ndev);
arc_reg_clr(priv, R_ENABLE, RXINT_MASK | TXINT_MASK | ERR_MASK);
arc_reg_clr(priv, R_CTRL, EN_MASK);
arc_free_tx_queue(ndev);
arc_free_rx_queue(ndev);
return 0;
}
static struct net_device_stats *arc_emac_stats(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
unsigned long miss, rxerr;
u8 rxcrc, rxfram, rxoflow;
rxerr = arc_reg_get(priv, R_RXERR);
miss = arc_reg_get(priv, R_MISS);
rxcrc = rxerr;
rxfram = rxerr >> 8;
rxoflow = rxerr >> 16;
stats->rx_errors += miss;
stats->rx_errors += rxcrc + rxfram + rxoflow;
stats->rx_over_errors += rxoflow;
stats->rx_frame_errors += rxfram;
stats->rx_crc_errors += rxcrc;
stats->rx_missed_errors += miss;
return stats;
}
static int arc_emac_tx(struct sk_buff *skb, struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int len, *txbd_curr = &priv->txbd_curr;
struct net_device_stats *stats = &ndev->stats;
__le32 *info = &priv->txbd[*txbd_curr].info;
dma_addr_t addr;
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
len = max_t(unsigned int, ETH_ZLEN, skb->len);
if (unlikely(!arc_emac_tx_avail(priv))) {
netif_stop_queue(ndev);
netdev_err(ndev, "BUG! Tx Ring full when queue awake!\n");
return NETDEV_TX_BUSY;
}
addr = dma_map_single(&ndev->dev, (void *)skb->data, len,
DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(&ndev->dev, addr))) {
stats->tx_dropped++;
stats->tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
dma_unmap_addr_set(&priv->tx_buff[*txbd_curr], addr, addr);
dma_unmap_len_set(&priv->tx_buff[*txbd_curr], len, len);
priv->txbd[*txbd_curr].data = cpu_to_le32(addr);
wmb();
skb_tx_timestamp(skb);
*info = cpu_to_le32(FOR_EMAC | FIRST_OR_LAST_MASK | len);
wmb();
priv->tx_buff[*txbd_curr].skb = skb;
*txbd_curr = (*txbd_curr + 1) % TX_BD_NUM;
smp_mb();
if (!arc_emac_tx_avail(priv)) {
netif_stop_queue(ndev);
smp_mb();
if (arc_emac_tx_avail(priv))
netif_start_queue(ndev);
}
arc_reg_set(priv, R_STATUS, TXPL_MASK);
return NETDEV_TX_OK;
}
static void arc_emac_set_address_internal(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
unsigned int addr_low, addr_hi;
addr_low = le32_to_cpu(*(__le32 *)&ndev->dev_addr[0]);
addr_hi = le16_to_cpu(*(__le16 *)&ndev->dev_addr[4]);
arc_reg_set(priv, R_ADDRL, addr_low);
arc_reg_set(priv, R_ADDRH, addr_hi);
}
static int arc_emac_set_address(struct net_device *ndev, void *p)
{
struct sockaddr *addr = p;
if (netif_running(ndev))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ndev->addr_len);
arc_emac_set_address_internal(ndev);
return 0;
}
int arc_emac_probe(struct net_device *ndev, int interface)
{
struct device *dev = ndev->dev.parent;
struct resource res_regs;
struct device_node *phy_node;
struct phy_device *phydev = NULL;
struct arc_emac_priv *priv;
const char *mac_addr;
unsigned int id, clock_frequency, irq;
int err;
phy_node = of_parse_phandle(dev->of_node, "phy", 0);
if (!phy_node) {
dev_err(dev, "failed to retrieve phy description from device tree\n");
return -ENODEV;
}
err = of_address_to_resource(dev->of_node, 0, &res_regs);
if (err) {
dev_err(dev, "failed to retrieve registers base from device tree\n");
err = -ENODEV;
goto out_put_node;
}
irq = irq_of_parse_and_map(dev->of_node, 0);
if (!irq) {
dev_err(dev, "failed to retrieve <irq> value from device tree\n");
err = -ENODEV;
goto out_put_node;
}
ndev->netdev_ops = &arc_emac_netdev_ops;
ndev->ethtool_ops = &arc_emac_ethtool_ops;
ndev->watchdog_timeo = TX_TIMEOUT;
ndev->flags &= ~IFF_MULTICAST;
priv = netdev_priv(ndev);
priv->dev = dev;
priv->regs = devm_ioremap_resource(dev, &res_regs);
if (IS_ERR(priv->regs)) {
err = PTR_ERR(priv->regs);
goto out_put_node;
}
dev_dbg(dev, "Registers base address is 0x%p\n", priv->regs);
if (priv->clk) {
err = clk_prepare_enable(priv->clk);
if (err) {
dev_err(dev, "failed to enable clock\n");
goto out_put_node;
}
clock_frequency = clk_get_rate(priv->clk);
} else {
if (of_property_read_u32(dev->of_node, "clock-frequency",
&clock_frequency)) {
dev_err(dev, "failed to retrieve <clock-frequency> from device tree\n");
err = -EINVAL;
goto out_put_node;
}
}
id = arc_reg_get(priv, R_ID);
if (!(id == 0x0005fd02 || id == 0x0007fd02)) {
dev_err(dev, "ARC EMAC not detected, id=0x%x\n", id);
err = -ENODEV;
goto out_clken;
}
dev_info(dev, "ARC EMAC detected with id: 0x%x\n", id);
arc_reg_set(priv, R_POLLRATE, clock_frequency / 1000000);
ndev->irq = irq;
dev_info(dev, "IRQ is %d\n", ndev->irq);
err = devm_request_irq(dev, ndev->irq, arc_emac_intr, 0,
ndev->name, ndev);
if (err) {
dev_err(dev, "could not allocate IRQ\n");
goto out_clken;
}
mac_addr = of_get_mac_address(dev->of_node);
if (mac_addr)
memcpy(ndev->dev_addr, mac_addr, ETH_ALEN);
else
eth_hw_addr_random(ndev);
arc_emac_set_address_internal(ndev);
dev_info(dev, "MAC address is now %pM\n", ndev->dev_addr);
priv->rxbd = dmam_alloc_coherent(dev, RX_RING_SZ + TX_RING_SZ,
&priv->rxbd_dma, GFP_KERNEL);
if (!priv->rxbd) {
dev_err(dev, "failed to allocate data buffers\n");
err = -ENOMEM;
goto out_clken;
}
priv->txbd = priv->rxbd + RX_BD_NUM;
priv->txbd_dma = priv->rxbd_dma + RX_RING_SZ;
dev_dbg(dev, "EMAC Device addr: Rx Ring [0x%x], Tx Ring[%x]\n",
(unsigned int)priv->rxbd_dma, (unsigned int)priv->txbd_dma);
err = arc_mdio_probe(priv);
if (err) {
dev_err(dev, "failed to probe MII bus\n");
goto out_clken;
}
phydev = of_phy_connect(ndev, phy_node, arc_emac_adjust_link, 0,
interface);
if (!phydev) {
dev_err(dev, "of_phy_connect() failed\n");
err = -ENODEV;
goto out_mdio;
}
dev_info(dev, "connected to %s phy with id 0x%x\n",
phydev->drv->name, phydev->phy_id);
netif_napi_add(ndev, &priv->napi, arc_emac_poll, ARC_EMAC_NAPI_WEIGHT);
err = register_netdev(ndev);
if (err) {
dev_err(dev, "failed to register network device\n");
goto out_netif_api;
}
of_node_put(phy_node);
return 0;
out_netif_api:
netif_napi_del(&priv->napi);
phy_disconnect(phydev);
out_mdio:
arc_mdio_remove(priv);
out_clken:
if (priv->clk)
clk_disable_unprepare(priv->clk);
out_put_node:
of_node_put(phy_node);
return err;
}
int arc_emac_remove(struct net_device *ndev)
{
struct arc_emac_priv *priv = netdev_priv(ndev);
phy_disconnect(ndev->phydev);
arc_mdio_remove(priv);
unregister_netdev(ndev);
netif_napi_del(&priv->napi);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return 0;
}
