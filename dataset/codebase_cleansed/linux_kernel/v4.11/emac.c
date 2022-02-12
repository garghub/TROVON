void emac_reg_update32(void __iomem *addr, u32 mask, u32 val)
{
u32 data = readl(addr);
writel(((data & ~mask) | val), addr);
}
int emac_reinit_locked(struct emac_adapter *adpt)
{
int ret;
mutex_lock(&adpt->reset_lock);
emac_mac_down(adpt);
emac_sgmii_reset(adpt);
ret = emac_mac_up(adpt);
mutex_unlock(&adpt->reset_lock);
return ret;
}
static int emac_napi_rtx(struct napi_struct *napi, int budget)
{
struct emac_rx_queue *rx_q =
container_of(napi, struct emac_rx_queue, napi);
struct emac_adapter *adpt = netdev_priv(rx_q->netdev);
struct emac_irq *irq = rx_q->irq;
int work_done = 0;
emac_mac_rx_process(adpt, rx_q, &work_done, budget);
if (work_done < budget) {
napi_complete_done(napi, work_done);
irq->mask |= rx_q->intr;
writel(irq->mask, adpt->base + EMAC_INT_MASK);
}
return work_done;
}
static int emac_start_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
return emac_mac_tx_buf_send(adpt, &adpt->tx_q, skb);
}
irqreturn_t emac_isr(int _irq, void *data)
{
struct emac_irq *irq = data;
struct emac_adapter *adpt =
container_of(irq, struct emac_adapter, irq);
struct emac_rx_queue *rx_q = &adpt->rx_q;
u32 isr, status;
writel(0, adpt->base + EMAC_INT_MASK);
isr = readl_relaxed(adpt->base + EMAC_INT_STATUS);
status = isr & irq->mask;
if (status == 0)
goto exit;
if (status & ISR_ERROR) {
netif_warn(adpt, intr, adpt->netdev,
"warning: error irq status 0x%lx\n",
status & ISR_ERROR);
schedule_work(&adpt->work_thread);
}
if (status & rx_q->intr) {
if (napi_schedule_prep(&rx_q->napi)) {
irq->mask &= ~rx_q->intr;
__napi_schedule(&rx_q->napi);
}
}
if (status & TX_PKT_INT)
emac_mac_tx_process(adpt, &adpt->tx_q);
if (status & ISR_OVER)
net_warn_ratelimited("warning: TX/RX overflow\n");
if (status & ISR_GPHY_LINK)
phy_mac_interrupt(adpt->phydev, !!(status & GPHY_LINK_UP_INT));
exit:
writel(irq->mask, adpt->base + EMAC_INT_MASK);
return IRQ_HANDLED;
}
static int emac_set_features(struct net_device *netdev,
netdev_features_t features)
{
netdev_features_t changed = features ^ netdev->features;
struct emac_adapter *adpt = netdev_priv(netdev);
if (!(changed & (NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX)))
return 0;
if (!netif_running(netdev))
return 0;
netdev->features = features;
return emac_reinit_locked(adpt);
}
static void emac_rx_mode_set(struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
struct netdev_hw_addr *ha;
emac_mac_mode_config(adpt);
emac_mac_multicast_addr_clear(adpt);
netdev_for_each_mc_addr(ha, netdev)
emac_mac_multicast_addr_set(adpt, ha->addr);
}
static int emac_change_mtu(struct net_device *netdev, int new_mtu)
{
struct emac_adapter *adpt = netdev_priv(netdev);
netif_info(adpt, hw, adpt->netdev,
"changing MTU from %d to %d\n", netdev->mtu,
new_mtu);
netdev->mtu = new_mtu;
if (netif_running(netdev))
return emac_reinit_locked(adpt);
return 0;
}
static int emac_open(struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
struct emac_irq *irq = &adpt->irq;
int ret;
ret = request_irq(irq->irq, emac_isr, 0, "emac-core0", irq);
if (ret) {
netdev_err(adpt->netdev, "could not request emac-core0 irq\n");
return ret;
}
ret = emac_mac_rx_tx_rings_alloc_all(adpt);
if (ret) {
netdev_err(adpt->netdev, "error allocating rx/tx rings\n");
free_irq(irq->irq, irq);
return ret;
}
ret = emac_mac_up(adpt);
if (ret) {
emac_mac_rx_tx_rings_free_all(adpt);
free_irq(irq->irq, irq);
return ret;
}
ret = adpt->phy.open(adpt);
if (ret) {
emac_mac_down(adpt);
emac_mac_rx_tx_rings_free_all(adpt);
free_irq(irq->irq, irq);
return ret;
}
return 0;
}
static int emac_close(struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
mutex_lock(&adpt->reset_lock);
adpt->phy.close(adpt);
emac_mac_down(adpt);
emac_mac_rx_tx_rings_free_all(adpt);
free_irq(adpt->irq.irq, &adpt->irq);
mutex_unlock(&adpt->reset_lock);
return 0;
}
static void emac_tx_timeout(struct net_device *netdev)
{
struct emac_adapter *adpt = netdev_priv(netdev);
schedule_work(&adpt->work_thread);
}
static int emac_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
if (!netif_running(netdev))
return -EINVAL;
if (!netdev->phydev)
return -ENODEV;
return phy_mii_ioctl(netdev->phydev, ifr, cmd);
}
void emac_update_hw_stats(struct emac_adapter *adpt)
{
struct emac_stats *stats = &adpt->stats;
u64 *stats_itr = &adpt->stats.rx_ok;
void __iomem *base = adpt->base;
unsigned int addr;
addr = REG_MAC_RX_STATUS_BIN;
while (addr <= REG_MAC_RX_STATUS_END) {
*stats_itr += readl_relaxed(base + addr);
stats_itr++;
addr += sizeof(u32);
}
stats->rx_crc_align += readl_relaxed(base + EMAC_RXMAC_STATC_REG23);
stats->rx_jabbers += readl_relaxed(base + EMAC_RXMAC_STATC_REG24);
addr = REG_MAC_TX_STATUS_BIN;
stats_itr = &stats->tx_ok;
while (addr <= REG_MAC_TX_STATUS_END) {
*stats_itr += readl_relaxed(base + addr);
stats_itr++;
addr += sizeof(u32);
}
stats->tx_col += readl_relaxed(base + EMAC_TXMAC_STATC_REG25);
}
static void emac_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *net_stats)
{
struct emac_adapter *adpt = netdev_priv(netdev);
struct emac_stats *stats = &adpt->stats;
spin_lock(&stats->lock);
emac_update_hw_stats(adpt);
net_stats->rx_packets = stats->rx_ok;
net_stats->tx_packets = stats->tx_ok;
net_stats->rx_bytes = stats->rx_byte_cnt;
net_stats->tx_bytes = stats->tx_byte_cnt;
net_stats->multicast = stats->rx_mcast;
net_stats->collisions = stats->tx_1_col + stats->tx_2_col * 2 +
stats->tx_late_col + stats->tx_abort_col;
net_stats->rx_errors = stats->rx_frag + stats->rx_fcs_err +
stats->rx_len_err + stats->rx_sz_ov +
stats->rx_align_err;
net_stats->rx_fifo_errors = stats->rx_rxf_ov;
net_stats->rx_length_errors = stats->rx_len_err;
net_stats->rx_crc_errors = stats->rx_fcs_err;
net_stats->rx_frame_errors = stats->rx_align_err;
net_stats->rx_over_errors = stats->rx_rxf_ov;
net_stats->rx_missed_errors = stats->rx_rxf_ov;
net_stats->tx_errors = stats->tx_late_col + stats->tx_abort_col +
stats->tx_underrun + stats->tx_trunc;
net_stats->tx_fifo_errors = stats->tx_underrun;
net_stats->tx_aborted_errors = stats->tx_abort_col;
net_stats->tx_window_errors = stats->tx_late_col;
spin_unlock(&stats->lock);
}
static void emac_work_thread(struct work_struct *work)
{
struct emac_adapter *adpt =
container_of(work, struct emac_adapter, work_thread);
emac_reinit_locked(adpt);
}
static void emac_init_adapter(struct emac_adapter *adpt)
{
u32 reg;
adpt->rrd_size = EMAC_RRD_SIZE;
adpt->tpd_size = EMAC_TPD_SIZE;
adpt->rfd_size = EMAC_RFD_SIZE;
adpt->tx_desc_cnt = EMAC_DEF_TX_DESCS;
adpt->rx_desc_cnt = EMAC_DEF_RX_DESCS;
adpt->dma_order = emac_dma_ord_out;
adpt->dmar_block = emac_dma_req_4096;
adpt->dmaw_block = emac_dma_req_128;
adpt->dmar_dly_cnt = DMAR_DLY_CNT_DEF;
adpt->dmaw_dly_cnt = DMAW_DLY_CNT_DEF;
adpt->tpd_burst = TXQ0_NUM_TPD_PREF_DEF;
adpt->rfd_burst = RXQ0_NUM_RFD_PREF_DEF;
reg = ((EMAC_DEF_RX_IRQ_MOD >> 1) << IRQ_MODERATOR2_INIT_SHFT) |
((EMAC_DEF_TX_IRQ_MOD >> 1) << IRQ_MODERATOR_INIT_SHFT);
adpt->irq_mod = reg;
adpt->preamble = EMAC_PREAMBLE_DEF;
adpt->automatic = true;
}
static int emac_clks_get(struct platform_device *pdev,
struct emac_adapter *adpt)
{
unsigned int i;
for (i = 0; i < EMAC_CLK_CNT; i++) {
struct clk *clk = devm_clk_get(&pdev->dev, emac_clk_name[i]);
if (IS_ERR(clk)) {
dev_err(&pdev->dev,
"could not claim clock %s (error=%li)\n",
emac_clk_name[i], PTR_ERR(clk));
return PTR_ERR(clk);
}
adpt->clk[i] = clk;
}
return 0;
}
static int emac_clks_phase1_init(struct platform_device *pdev,
struct emac_adapter *adpt)
{
int ret;
if (has_acpi_companion(&pdev->dev))
return 0;
ret = emac_clks_get(pdev, adpt);
if (ret)
return ret;
ret = clk_prepare_enable(adpt->clk[EMAC_CLK_AXI]);
if (ret)
return ret;
ret = clk_prepare_enable(adpt->clk[EMAC_CLK_CFG_AHB]);
if (ret)
return ret;
ret = clk_set_rate(adpt->clk[EMAC_CLK_HIGH_SPEED], 19200000);
if (ret)
return ret;
return clk_prepare_enable(adpt->clk[EMAC_CLK_HIGH_SPEED]);
}
static int emac_clks_phase2_init(struct platform_device *pdev,
struct emac_adapter *adpt)
{
int ret;
if (has_acpi_companion(&pdev->dev))
return 0;
ret = clk_set_rate(adpt->clk[EMAC_CLK_TX], 125000000);
if (ret)
return ret;
ret = clk_prepare_enable(adpt->clk[EMAC_CLK_TX]);
if (ret)
return ret;
ret = clk_set_rate(adpt->clk[EMAC_CLK_HIGH_SPEED], 125000000);
if (ret)
return ret;
ret = clk_set_rate(adpt->clk[EMAC_CLK_MDIO], 25000000);
if (ret)
return ret;
ret = clk_prepare_enable(adpt->clk[EMAC_CLK_MDIO]);
if (ret)
return ret;
ret = clk_prepare_enable(adpt->clk[EMAC_CLK_RX]);
if (ret)
return ret;
return clk_prepare_enable(adpt->clk[EMAC_CLK_SYS]);
}
static void emac_clks_teardown(struct emac_adapter *adpt)
{
unsigned int i;
for (i = 0; i < EMAC_CLK_CNT; i++)
clk_disable_unprepare(adpt->clk[i]);
}
static int emac_probe_resources(struct platform_device *pdev,
struct emac_adapter *adpt)
{
struct net_device *netdev = adpt->netdev;
struct resource *res;
char maddr[ETH_ALEN];
int ret = 0;
if (device_get_mac_address(&pdev->dev, maddr, ETH_ALEN))
ether_addr_copy(netdev->dev_addr, maddr);
else
eth_hw_addr_random(netdev);
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev,
"error: missing core0 irq resource (error=%i)\n", ret);
return ret;
}
adpt->irq.irq = ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
adpt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(adpt->base))
return PTR_ERR(adpt->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
adpt->csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(adpt->csr))
return PTR_ERR(adpt->csr);
netdev->base_addr = (unsigned long)adpt->base;
return 0;
}
static int emac_probe(struct platform_device *pdev)
{
struct net_device *netdev;
struct emac_adapter *adpt;
struct emac_sgmii *phy;
u16 devid, revid;
u32 reg;
int ret;
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (ret) {
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(&pdev->dev, "could not set DMA mask\n");
return ret;
}
}
netdev = alloc_etherdev(sizeof(struct emac_adapter));
if (!netdev)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, netdev);
SET_NETDEV_DEV(netdev, &pdev->dev);
emac_set_ethtool_ops(netdev);
adpt = netdev_priv(netdev);
adpt->netdev = netdev;
adpt->msg_enable = EMAC_MSG_DEFAULT;
phy = &adpt->phy;
atomic_set(&phy->decode_error_count, 0);
mutex_init(&adpt->reset_lock);
spin_lock_init(&adpt->stats.lock);
adpt->irq.mask = RX_PKT_INT0 | IMR_NORMAL_MASK;
ret = emac_probe_resources(pdev, adpt);
if (ret)
goto err_undo_netdev;
ret = emac_clks_phase1_init(pdev, adpt);
if (ret) {
dev_err(&pdev->dev, "could not initialize clocks\n");
goto err_undo_netdev;
}
netdev->watchdog_timeo = EMAC_WATCHDOG_TIME;
netdev->irq = adpt->irq.irq;
netdev->netdev_ops = &emac_netdev_ops;
emac_init_adapter(adpt);
ret = emac_phy_config(pdev, adpt);
if (ret)
goto err_undo_clocks;
ret = emac_sgmii_config(pdev, adpt);
if (ret)
goto err_undo_mdiobus;
ret = emac_clks_phase2_init(pdev, adpt);
if (ret) {
dev_err(&pdev->dev, "could not initialize clocks\n");
goto err_undo_mdiobus;
}
emac_mac_reset(adpt);
netdev->features = NETIF_F_SG | NETIF_F_HW_CSUM | NETIF_F_RXCSUM |
NETIF_F_TSO | NETIF_F_TSO6 | NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->hw_features = netdev->features;
netdev->vlan_features |= NETIF_F_SG | NETIF_F_HW_CSUM |
NETIF_F_TSO | NETIF_F_TSO6;
netdev->min_mtu = EMAC_MIN_ETH_FRAME_SIZE -
(ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN);
netdev->max_mtu = EMAC_MAX_ETH_FRAME_SIZE -
(ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN);
INIT_WORK(&adpt->work_thread, emac_work_thread);
emac_mac_rx_tx_ring_init_all(pdev, adpt);
netif_napi_add(netdev, &adpt->rx_q.napi, emac_napi_rtx,
NAPI_POLL_WEIGHT);
ret = register_netdev(netdev);
if (ret) {
dev_err(&pdev->dev, "could not register net device\n");
goto err_undo_napi;
}
reg = readl_relaxed(adpt->base + EMAC_DMA_MAS_CTRL);
devid = (reg & DEV_ID_NUM_BMSK) >> DEV_ID_NUM_SHFT;
revid = (reg & DEV_REV_NUM_BMSK) >> DEV_REV_NUM_SHFT;
reg = readl_relaxed(adpt->base + EMAC_CORE_HW_VERSION);
netif_info(adpt, probe, netdev,
"hardware id %d.%d, hardware version %d.%d.%d\n",
devid, revid,
(reg & MAJOR_BMSK) >> MAJOR_SHFT,
(reg & MINOR_BMSK) >> MINOR_SHFT,
(reg & STEP_BMSK) >> STEP_SHFT);
return 0;
err_undo_napi:
netif_napi_del(&adpt->rx_q.napi);
err_undo_mdiobus:
put_device(&adpt->phydev->mdio.dev);
mdiobus_unregister(adpt->mii_bus);
err_undo_clocks:
emac_clks_teardown(adpt);
err_undo_netdev:
free_netdev(netdev);
return ret;
}
static int emac_remove(struct platform_device *pdev)
{
struct net_device *netdev = dev_get_drvdata(&pdev->dev);
struct emac_adapter *adpt = netdev_priv(netdev);
unregister_netdev(netdev);
netif_napi_del(&adpt->rx_q.napi);
emac_clks_teardown(adpt);
put_device(&adpt->phydev->mdio.dev);
mdiobus_unregister(adpt->mii_bus);
free_netdev(netdev);
if (adpt->phy.digital)
iounmap(adpt->phy.digital);
iounmap(adpt->phy.base);
return 0;
}
