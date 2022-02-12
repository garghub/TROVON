static void cpsw_intr_enable(struct cpsw_priv *priv)
{
__raw_writel(0xFF, &priv->ss_regs->tx_en);
__raw_writel(0xFF, &priv->ss_regs->rx_en);
cpdma_ctlr_int_ctrl(priv->dma, true);
return;
}
static void cpsw_intr_disable(struct cpsw_priv *priv)
{
__raw_writel(0, &priv->ss_regs->tx_en);
__raw_writel(0, &priv->ss_regs->rx_en);
cpdma_ctlr_int_ctrl(priv->dma, false);
return;
}
void cpsw_tx_handler(void *token, int len, int status)
{
struct sk_buff *skb = token;
struct net_device *ndev = skb->dev;
struct cpsw_priv *priv = netdev_priv(ndev);
if (unlikely(netif_queue_stopped(ndev)))
netif_start_queue(ndev);
priv->stats.tx_packets++;
priv->stats.tx_bytes += len;
dev_kfree_skb_any(skb);
}
void cpsw_rx_handler(void *token, int len, int status)
{
struct sk_buff *skb = token;
struct net_device *ndev = skb->dev;
struct cpsw_priv *priv = netdev_priv(ndev);
int ret = 0;
if (unlikely(!netif_running(ndev)) ||
unlikely(!netif_carrier_ok(ndev))) {
dev_kfree_skb_any(skb);
return;
}
if (likely(status >= 0)) {
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
priv->stats.rx_bytes += len;
priv->stats.rx_packets++;
skb = NULL;
}
if (unlikely(!netif_running(ndev))) {
if (skb)
dev_kfree_skb_any(skb);
return;
}
if (likely(!skb)) {
skb = netdev_alloc_skb_ip_align(ndev, priv->rx_packet_max);
if (WARN_ON(!skb))
return;
ret = cpdma_chan_submit(priv->rxch, skb, skb->data,
skb_tailroom(skb), GFP_KERNEL);
}
WARN_ON(ret < 0);
}
static irqreturn_t cpsw_interrupt(int irq, void *dev_id)
{
struct cpsw_priv *priv = dev_id;
if (likely(netif_running(priv->ndev))) {
cpsw_intr_disable(priv);
cpsw_disable_irq(priv);
napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
static inline int cpsw_get_slave_port(struct cpsw_priv *priv, u32 slave_num)
{
if (priv->host_port == 0)
return slave_num + 1;
else
return slave_num;
}
static int cpsw_poll(struct napi_struct *napi, int budget)
{
struct cpsw_priv *priv = napi_to_priv(napi);
int num_tx, num_rx;
num_tx = cpdma_chan_process(priv->txch, 128);
num_rx = cpdma_chan_process(priv->rxch, budget);
if (num_rx || num_tx)
cpsw_dbg(priv, intr, "poll %d rx, %d tx pkts\n",
num_rx, num_tx);
if (num_rx < budget) {
napi_complete(napi);
cpsw_intr_enable(priv);
cpdma_ctlr_eoi(priv->dma);
cpsw_enable_irq(priv);
}
return num_rx;
}
static inline void soft_reset(const char *module, void __iomem *reg)
{
unsigned long timeout = jiffies + HZ;
__raw_writel(1, reg);
do {
cpu_relax();
} while ((__raw_readl(reg) & 1) && time_after(timeout, jiffies));
WARN(__raw_readl(reg) & 1, "failed to soft-reset %s\n", module);
}
static void cpsw_set_slave_mac(struct cpsw_slave *slave,
struct cpsw_priv *priv)
{
__raw_writel(mac_hi(priv->mac_addr), &slave->regs->sa_hi);
__raw_writel(mac_lo(priv->mac_addr), &slave->regs->sa_lo);
}
static void _cpsw_adjust_link(struct cpsw_slave *slave,
struct cpsw_priv *priv, bool *link)
{
struct phy_device *phy = slave->phy;
u32 mac_control = 0;
u32 slave_port;
if (!phy)
return;
slave_port = cpsw_get_slave_port(priv, slave->slave_num);
if (phy->link) {
mac_control = priv->data.mac_control;
cpsw_ale_control_set(priv->ale, slave_port,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
if (phy->speed == 1000)
mac_control |= BIT(7);
if (phy->duplex)
mac_control |= BIT(0);
*link = true;
} else {
mac_control = 0;
cpsw_ale_control_set(priv->ale, slave_port,
ALE_PORT_STATE, ALE_PORT_STATE_DISABLE);
}
if (mac_control != slave->mac_control) {
phy_print_status(phy);
__raw_writel(mac_control, &slave->sliver->mac_control);
}
slave->mac_control = mac_control;
}
static void cpsw_adjust_link(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
bool link = false;
for_each_slave(priv, _cpsw_adjust_link, priv, &link);
if (link) {
netif_carrier_on(ndev);
if (netif_running(ndev))
netif_wake_queue(ndev);
} else {
netif_carrier_off(ndev);
netif_stop_queue(ndev);
}
}
static inline int __show_stat(char *buf, int maxlen, const char *name, u32 val)
{
static char *leader = "........................................";
if (!val)
return 0;
else
return snprintf(buf, maxlen, "%s %s %10d\n", name,
leader + strlen(name), val);
}
static void cpsw_slave_open(struct cpsw_slave *slave, struct cpsw_priv *priv)
{
char name[32];
u32 slave_port;
sprintf(name, "slave-%d", slave->slave_num);
soft_reset(name, &slave->sliver->soft_reset);
__raw_writel(RX_PRIORITY_MAPPING, &slave->sliver->rx_pri_map);
__raw_writel(TX_PRIORITY_MAPPING, &slave->regs->tx_pri_map);
__raw_writel(priv->rx_packet_max, &slave->sliver->rx_maxlen);
cpsw_set_slave_mac(slave, priv);
slave->mac_control = 0;
slave_port = cpsw_get_slave_port(priv, slave->slave_num);
cpsw_ale_add_mcast(priv->ale, priv->ndev->broadcast,
1 << slave_port, 0, ALE_MCAST_FWD_2);
slave->phy = phy_connect(priv->ndev, slave->data->phy_id,
&cpsw_adjust_link, 0, slave->data->phy_if);
if (IS_ERR(slave->phy)) {
dev_err(priv->dev, "phy %s not found on slave %d\n",
slave->data->phy_id, slave->slave_num);
slave->phy = NULL;
} else {
dev_info(priv->dev, "phy found : id is : 0x%x\n",
slave->phy->phy_id);
phy_start(slave->phy);
}
}
static void cpsw_init_host_port(struct cpsw_priv *priv)
{
soft_reset("cpsw", &priv->regs->soft_reset);
cpsw_ale_start(priv->ale);
cpsw_ale_control_set(priv->ale, 0, ALE_VLAN_AWARE, 0);
__raw_writel(CPDMA_TX_PRIORITY_MAP,
&priv->host_port_regs->cpdma_tx_pri_map);
__raw_writel(0, &priv->host_port_regs->cpdma_rx_chan_map);
cpsw_ale_control_set(priv->ale, priv->host_port,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
cpsw_ale_add_ucast(priv->ale, priv->mac_addr, priv->host_port, 0);
cpsw_ale_add_mcast(priv->ale, priv->ndev->broadcast,
1 << priv->host_port, 0, ALE_MCAST_FWD_2);
}
static int cpsw_ndo_open(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
int i, ret;
u32 reg;
cpsw_intr_disable(priv);
netif_carrier_off(ndev);
pm_runtime_get_sync(&priv->pdev->dev);
reg = __raw_readl(&priv->regs->id_ver);
dev_info(priv->dev, "initializing cpsw version %d.%d (%d)\n",
CPSW_MAJOR_VERSION(reg), CPSW_MINOR_VERSION(reg),
CPSW_RTL_VERSION(reg));
cpsw_init_host_port(priv);
for_each_slave(priv, cpsw_slave_open, priv);
cpdma_control_set(priv->dma, CPDMA_TX_PRIO_FIXED, 1);
cpdma_control_set(priv->dma, CPDMA_RX_BUFFER_OFFSET, 0);
__raw_writel(0, &priv->regs->ptype);
__raw_writel(0x7, &priv->regs->stat_port_en);
if (WARN_ON(!priv->data.rx_descs))
priv->data.rx_descs = 128;
for (i = 0; i < priv->data.rx_descs; i++) {
struct sk_buff *skb;
ret = -ENOMEM;
skb = netdev_alloc_skb_ip_align(priv->ndev,
priv->rx_packet_max);
if (!skb)
break;
ret = cpdma_chan_submit(priv->rxch, skb, skb->data,
skb_tailroom(skb), GFP_KERNEL);
if (WARN_ON(ret < 0))
break;
}
cpsw_info(priv, ifup, "submitted %d rx descriptors\n", i);
cpdma_ctlr_start(priv->dma);
cpsw_intr_enable(priv);
napi_enable(&priv->napi);
cpdma_ctlr_eoi(priv->dma);
return 0;
}
static void cpsw_slave_stop(struct cpsw_slave *slave, struct cpsw_priv *priv)
{
if (!slave->phy)
return;
phy_stop(slave->phy);
phy_disconnect(slave->phy);
slave->phy = NULL;
}
static int cpsw_ndo_stop(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
cpsw_info(priv, ifdown, "shutting down cpsw device\n");
cpsw_intr_disable(priv);
cpdma_ctlr_int_ctrl(priv->dma, false);
cpdma_ctlr_stop(priv->dma);
netif_stop_queue(priv->ndev);
napi_disable(&priv->napi);
netif_carrier_off(priv->ndev);
cpsw_ale_stop(priv->ale);
for_each_slave(priv, cpsw_slave_stop, priv);
pm_runtime_put_sync(&priv->pdev->dev);
return 0;
}
static netdev_tx_t cpsw_ndo_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
int ret;
ndev->trans_start = jiffies;
if (skb_padto(skb, CPSW_MIN_PACKET_SIZE)) {
cpsw_err(priv, tx_err, "packet pad failed\n");
priv->stats.tx_dropped++;
return NETDEV_TX_OK;
}
ret = cpdma_chan_submit(priv->txch, skb, skb->data,
skb->len, GFP_KERNEL);
if (unlikely(ret != 0)) {
cpsw_err(priv, tx_err, "desc submit failed\n");
goto fail;
}
return NETDEV_TX_OK;
fail:
priv->stats.tx_dropped++;
netif_stop_queue(ndev);
return NETDEV_TX_BUSY;
}
static void cpsw_ndo_change_rx_flags(struct net_device *ndev, int flags)
{
if ((flags & IFF_PROMISC) && (ndev->flags & IFF_PROMISC))
dev_err(&ndev->dev, "promiscuity ignored!\n");
if ((flags & IFF_ALLMULTI) && !(ndev->flags & IFF_ALLMULTI))
dev_err(&ndev->dev, "multicast traffic cannot be filtered!\n");
}
static void cpsw_ndo_tx_timeout(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
cpsw_err(priv, tx_err, "transmit timeout, restarting dma\n");
priv->stats.tx_errors++;
cpsw_intr_disable(priv);
cpdma_ctlr_int_ctrl(priv->dma, false);
cpdma_chan_stop(priv->txch);
cpdma_chan_start(priv->txch);
cpdma_ctlr_int_ctrl(priv->dma, true);
cpsw_intr_enable(priv);
cpdma_ctlr_eoi(priv->dma);
}
static struct net_device_stats *cpsw_ndo_get_stats(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
return &priv->stats;
}
static void cpsw_ndo_poll_controller(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
cpsw_intr_disable(priv);
cpdma_ctlr_int_ctrl(priv->dma, false);
cpsw_interrupt(ndev->irq, priv);
cpdma_ctlr_int_ctrl(priv->dma, true);
cpsw_intr_enable(priv);
cpdma_ctlr_eoi(priv->dma);
}
static void cpsw_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct cpsw_priv *priv = netdev_priv(ndev);
strcpy(info->driver, "TI CPSW Driver v1.0");
strcpy(info->version, "1.0");
strcpy(info->bus_info, priv->pdev->name);
}
static u32 cpsw_get_msglevel(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
return priv->msg_enable;
}
static void cpsw_set_msglevel(struct net_device *ndev, u32 value)
{
struct cpsw_priv *priv = netdev_priv(ndev);
priv->msg_enable = value;
}
static void cpsw_slave_init(struct cpsw_slave *slave, struct cpsw_priv *priv)
{
void __iomem *regs = priv->regs;
int slave_num = slave->slave_num;
struct cpsw_slave_data *data = priv->data.slave_data + slave_num;
slave->data = data;
slave->regs = regs + data->slave_reg_ofs;
slave->sliver = regs + data->sliver_reg_ofs;
}
static int __devinit cpsw_probe(struct platform_device *pdev)
{
struct cpsw_platform_data *data = pdev->dev.platform_data;
struct net_device *ndev;
struct cpsw_priv *priv;
struct cpdma_params dma_params;
struct cpsw_ale_params ale_params;
void __iomem *regs;
struct resource *res;
int ret = 0, i, k = 0;
if (!data) {
pr_err("platform data missing\n");
return -ENODEV;
}
ndev = alloc_etherdev(sizeof(struct cpsw_priv));
if (!ndev) {
pr_err("error allocating net_device\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, ndev);
priv = netdev_priv(ndev);
spin_lock_init(&priv->lock);
priv->data = *data;
priv->pdev = pdev;
priv->ndev = ndev;
priv->dev = &ndev->dev;
priv->msg_enable = netif_msg_init(debug_level, CPSW_DEBUG);
priv->rx_packet_max = max(rx_packet_max, 128);
if (is_valid_ether_addr(data->slave_data[0].mac_addr)) {
memcpy(priv->mac_addr, data->slave_data[0].mac_addr, ETH_ALEN);
pr_info("Detected MACID = %pM", priv->mac_addr);
} else {
eth_random_addr(priv->mac_addr);
pr_info("Random MACID = %pM", priv->mac_addr);
}
memcpy(ndev->dev_addr, priv->mac_addr, ETH_ALEN);
priv->slaves = kzalloc(sizeof(struct cpsw_slave) * data->slaves,
GFP_KERNEL);
if (!priv->slaves) {
ret = -EBUSY;
goto clean_ndev_ret;
}
for (i = 0; i < data->slaves; i++)
priv->slaves[i].slave_num = i;
pm_runtime_enable(&pdev->dev);
priv->clk = clk_get(&pdev->dev, "fck");
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "fck is not found\n");
ret = -ENODEV;
goto clean_slave_ret;
}
priv->cpsw_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!priv->cpsw_res) {
dev_err(priv->dev, "error getting i/o resource\n");
ret = -ENOENT;
goto clean_clk_ret;
}
if (!request_mem_region(priv->cpsw_res->start,
resource_size(priv->cpsw_res), ndev->name)) {
dev_err(priv->dev, "failed request i/o region\n");
ret = -ENXIO;
goto clean_clk_ret;
}
regs = ioremap(priv->cpsw_res->start, resource_size(priv->cpsw_res));
if (!regs) {
dev_err(priv->dev, "unable to map i/o region\n");
goto clean_cpsw_iores_ret;
}
priv->regs = regs;
priv->host_port = data->host_port_num;
priv->host_port_regs = regs + data->host_port_reg_ofs;
priv->cpsw_ss_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!priv->cpsw_ss_res) {
dev_err(priv->dev, "error getting i/o resource\n");
ret = -ENOENT;
goto clean_clk_ret;
}
if (!request_mem_region(priv->cpsw_ss_res->start,
resource_size(priv->cpsw_ss_res), ndev->name)) {
dev_err(priv->dev, "failed request i/o region\n");
ret = -ENXIO;
goto clean_clk_ret;
}
regs = ioremap(priv->cpsw_ss_res->start,
resource_size(priv->cpsw_ss_res));
if (!regs) {
dev_err(priv->dev, "unable to map i/o region\n");
goto clean_cpsw_ss_iores_ret;
}
priv->ss_regs = regs;
for_each_slave(priv, cpsw_slave_init, priv);
memset(&dma_params, 0, sizeof(dma_params));
dma_params.dev = &pdev->dev;
dma_params.dmaregs = cpsw_dma_regs((u32)priv->regs,
data->cpdma_reg_ofs);
dma_params.rxthresh = cpsw_dma_rxthresh((u32)priv->regs,
data->cpdma_reg_ofs);
dma_params.rxfree = cpsw_dma_rxfree((u32)priv->regs,
data->cpdma_reg_ofs);
dma_params.txhdp = cpsw_dma_txhdp((u32)priv->regs,
data->cpdma_sram_ofs);
dma_params.rxhdp = cpsw_dma_rxhdp((u32)priv->regs,
data->cpdma_sram_ofs);
dma_params.txcp = cpsw_dma_txcp((u32)priv->regs,
data->cpdma_sram_ofs);
dma_params.rxcp = cpsw_dma_rxcp((u32)priv->regs,
data->cpdma_sram_ofs);
dma_params.num_chan = data->channels;
dma_params.has_soft_reset = true;
dma_params.min_packet_size = CPSW_MIN_PACKET_SIZE;
dma_params.desc_mem_size = data->bd_ram_size;
dma_params.desc_align = 16;
dma_params.has_ext_regs = true;
dma_params.desc_mem_phys = data->no_bd_ram ? 0 :
(u32 __force)priv->cpsw_res->start + data->bd_ram_ofs;
dma_params.desc_hw_addr = data->hw_ram_addr ?
data->hw_ram_addr : dma_params.desc_mem_phys ;
priv->dma = cpdma_ctlr_create(&dma_params);
if (!priv->dma) {
dev_err(priv->dev, "error initializing dma\n");
ret = -ENOMEM;
goto clean_iomap_ret;
}
priv->txch = cpdma_chan_create(priv->dma, tx_chan_num(0),
cpsw_tx_handler);
priv->rxch = cpdma_chan_create(priv->dma, rx_chan_num(0),
cpsw_rx_handler);
if (WARN_ON(!priv->txch || !priv->rxch)) {
dev_err(priv->dev, "error initializing dma channels\n");
ret = -ENOMEM;
goto clean_dma_ret;
}
memset(&ale_params, 0, sizeof(ale_params));
ale_params.dev = &ndev->dev;
ale_params.ale_regs = (void *)((u32)priv->regs) +
((u32)data->ale_reg_ofs);
ale_params.ale_ageout = ale_ageout;
ale_params.ale_entries = data->ale_entries;
ale_params.ale_ports = data->slaves;
priv->ale = cpsw_ale_create(&ale_params);
if (!priv->ale) {
dev_err(priv->dev, "error initializing ale engine\n");
ret = -ENODEV;
goto clean_dma_ret;
}
ndev->irq = platform_get_irq(pdev, 0);
if (ndev->irq < 0) {
dev_err(priv->dev, "error getting irq resource\n");
ret = -ENOENT;
goto clean_ale_ret;
}
while ((res = platform_get_resource(priv->pdev, IORESOURCE_IRQ, k))) {
for (i = res->start; i <= res->end; i++) {
if (request_irq(i, cpsw_interrupt, IRQF_DISABLED,
dev_name(&pdev->dev), priv)) {
dev_err(priv->dev, "error attaching irq\n");
goto clean_ale_ret;
}
priv->irqs_table[k] = i;
priv->num_irqs = k;
}
k++;
}
ndev->flags |= IFF_ALLMULTI;
ndev->netdev_ops = &cpsw_netdev_ops;
SET_ETHTOOL_OPS(ndev, &cpsw_ethtool_ops);
netif_napi_add(ndev, &priv->napi, cpsw_poll, CPSW_POLL_WEIGHT);
SET_NETDEV_DEV(ndev, &pdev->dev);
ret = register_netdev(ndev);
if (ret) {
dev_err(priv->dev, "error registering net device\n");
ret = -ENODEV;
goto clean_irq_ret;
}
cpsw_notice(priv, probe, "initialized device (regs %x, irq %d)\n",
priv->cpsw_res->start, ndev->irq);
return 0;
clean_irq_ret:
free_irq(ndev->irq, priv);
clean_ale_ret:
cpsw_ale_destroy(priv->ale);
clean_dma_ret:
cpdma_chan_destroy(priv->txch);
cpdma_chan_destroy(priv->rxch);
cpdma_ctlr_destroy(priv->dma);
clean_iomap_ret:
iounmap(priv->regs);
clean_cpsw_ss_iores_ret:
release_mem_region(priv->cpsw_ss_res->start,
resource_size(priv->cpsw_ss_res));
clean_cpsw_iores_ret:
release_mem_region(priv->cpsw_res->start,
resource_size(priv->cpsw_res));
clean_clk_ret:
clk_put(priv->clk);
clean_slave_ret:
pm_runtime_disable(&pdev->dev);
kfree(priv->slaves);
clean_ndev_ret:
free_netdev(ndev);
return ret;
}
static int __devexit cpsw_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct cpsw_priv *priv = netdev_priv(ndev);
pr_info("removing device");
platform_set_drvdata(pdev, NULL);
free_irq(ndev->irq, priv);
cpsw_ale_destroy(priv->ale);
cpdma_chan_destroy(priv->txch);
cpdma_chan_destroy(priv->rxch);
cpdma_ctlr_destroy(priv->dma);
iounmap(priv->regs);
release_mem_region(priv->cpsw_res->start,
resource_size(priv->cpsw_res));
release_mem_region(priv->cpsw_ss_res->start,
resource_size(priv->cpsw_ss_res));
pm_runtime_disable(&pdev->dev);
clk_put(priv->clk);
kfree(priv->slaves);
free_netdev(ndev);
return 0;
}
static int cpsw_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
if (netif_running(ndev))
cpsw_ndo_stop(ndev);
pm_runtime_put_sync(&pdev->dev);
return 0;
}
static int cpsw_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
pm_runtime_get_sync(&pdev->dev);
if (netif_running(ndev))
cpsw_ndo_open(ndev);
return 0;
}
static int __init cpsw_init(void)
{
return platform_driver_register(&cpsw_driver);
}
static void __exit cpsw_exit(void)
{
platform_driver_unregister(&cpsw_driver);
}
