static inline u32 slave_read(struct cpsw_slave *slave, u32 offset)
{
return __raw_readl(slave->regs + offset);
}
static inline void slave_write(struct cpsw_slave *slave, u32 val, u32 offset)
{
__raw_writel(val, slave->regs + offset);
}
static inline int cpsw_get_slave_port(u32 slave_num)
{
return slave_num + 1;
}
static void cpsw_set_promiscious(struct net_device *ndev, bool enable)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
struct cpsw_ale *ale = cpsw->ale;
int i;
if (cpsw->data.dual_emac) {
bool flag = false;
for (i = 0; i < cpsw->data.slaves; i++)
if (cpsw->slaves[i].ndev->flags & IFF_PROMISC)
flag = true;
if (!enable && flag) {
enable = true;
dev_err(&ndev->dev, "promiscuity not disabled as the other interface is still in promiscuity mode\n");
}
if (enable) {
cpsw_ale_control_set(ale, 0, ALE_BYPASS, 1);
dev_dbg(&ndev->dev, "promiscuity enabled\n");
} else {
cpsw_ale_control_set(ale, 0, ALE_BYPASS, 0);
dev_dbg(&ndev->dev, "promiscuity disabled\n");
}
} else {
if (enable) {
unsigned long timeout = jiffies + HZ;
for (i = 0; i <= cpsw->data.slaves; i++) {
cpsw_ale_control_set(ale, i,
ALE_PORT_NOLEARN, 1);
cpsw_ale_control_set(ale, i,
ALE_PORT_NO_SA_UPDATE, 1);
}
cpsw_ale_control_set(ale, 0, ALE_AGEOUT, 1);
do {
cpu_relax();
if (cpsw_ale_control_get(ale, 0, ALE_AGEOUT))
break;
} while (time_after(timeout, jiffies));
cpsw_ale_control_set(ale, 0, ALE_AGEOUT, 1);
cpsw_ale_flush_multicast(ale, ALE_ALL_PORTS, -1);
cpsw_ale_control_set(ale, 0, ALE_P0_UNI_FLOOD, 1);
dev_dbg(&ndev->dev, "promiscuity enabled\n");
} else {
cpsw_ale_control_set(ale, 0, ALE_P0_UNI_FLOOD, 0);
for (i = 0; i <= cpsw->data.slaves; i++) {
cpsw_ale_control_set(ale, i,
ALE_PORT_NOLEARN, 0);
cpsw_ale_control_set(ale, i,
ALE_PORT_NO_SA_UPDATE, 0);
}
dev_dbg(&ndev->dev, "promiscuity disabled\n");
}
}
}
static void cpsw_ndo_set_rx_mode(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int vid;
if (cpsw->data.dual_emac)
vid = cpsw->slaves[priv->emac_port].port_vlan;
else
vid = cpsw->data.default_vlan;
if (ndev->flags & IFF_PROMISC) {
cpsw_set_promiscious(ndev, true);
cpsw_ale_set_allmulti(cpsw->ale, IFF_ALLMULTI);
return;
} else {
cpsw_set_promiscious(ndev, false);
}
cpsw_ale_set_allmulti(cpsw->ale, priv->ndev->flags & IFF_ALLMULTI);
cpsw_ale_flush_multicast(cpsw->ale, ALE_ALL_PORTS, vid);
if (!netdev_mc_empty(ndev)) {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, ndev) {
cpsw_add_mcast(cpsw, priv, (u8 *)ha->addr);
}
}
}
static void cpsw_intr_enable(struct cpsw_common *cpsw)
{
__raw_writel(0xFF, &cpsw->wr_regs->tx_en);
__raw_writel(0xFF, &cpsw->wr_regs->rx_en);
cpdma_ctlr_int_ctrl(cpsw->dma, true);
return;
}
static void cpsw_intr_disable(struct cpsw_common *cpsw)
{
__raw_writel(0, &cpsw->wr_regs->tx_en);
__raw_writel(0, &cpsw->wr_regs->rx_en);
cpdma_ctlr_int_ctrl(cpsw->dma, false);
return;
}
static void cpsw_tx_handler(void *token, int len, int status)
{
struct netdev_queue *txq;
struct sk_buff *skb = token;
struct net_device *ndev = skb->dev;
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
txq = netdev_get_tx_queue(ndev, skb_get_queue_mapping(skb));
if (unlikely(netif_tx_queue_stopped(txq)))
netif_tx_wake_queue(txq);
cpts_tx_timestamp(cpsw->cpts, skb);
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += len;
dev_kfree_skb_any(skb);
}
static void cpsw_rx_handler(void *token, int len, int status)
{
struct cpdma_chan *ch;
struct sk_buff *skb = token;
struct sk_buff *new_skb;
struct net_device *ndev = skb->dev;
int ret = 0;
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
cpsw_dual_emac_src_port_detect(cpsw, status, ndev, skb);
if (unlikely(status < 0) || unlikely(!netif_running(ndev))) {
if (cpsw->data.dual_emac && cpsw->usage_count &&
(status >= 0)) {
new_skb = skb;
goto requeue;
}
dev_kfree_skb_any(skb);
return;
}
new_skb = netdev_alloc_skb_ip_align(ndev, cpsw->rx_packet_max);
if (new_skb) {
skb_copy_queue_mapping(new_skb, skb);
skb_put(skb, len);
cpts_rx_timestamp(cpsw->cpts, skb);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_bytes += len;
ndev->stats.rx_packets++;
kmemleak_not_leak(new_skb);
} else {
ndev->stats.rx_dropped++;
new_skb = skb;
}
requeue:
if (netif_dormant(ndev)) {
dev_kfree_skb_any(new_skb);
return;
}
ch = cpsw->rxv[skb_get_queue_mapping(new_skb)].ch;
ret = cpdma_chan_submit(ch, new_skb, new_skb->data,
skb_tailroom(new_skb), 0);
if (WARN_ON(ret < 0))
dev_kfree_skb_any(new_skb);
}
static void cpsw_split_res(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
u32 consumed_rate = 0, bigest_rate = 0;
struct cpsw_common *cpsw = priv->cpsw;
struct cpsw_vector *txv = cpsw->txv;
int i, ch_weight, rlim_ch_num = 0;
int budget, bigest_rate_ch = 0;
u32 ch_rate, max_rate;
int ch_budget = 0;
for (i = 0; i < cpsw->tx_ch_num; i++) {
ch_rate = cpdma_chan_get_rate(txv[i].ch);
if (!ch_rate)
continue;
rlim_ch_num++;
consumed_rate += ch_rate;
}
if (cpsw->tx_ch_num == rlim_ch_num) {
max_rate = consumed_rate;
} else if (!rlim_ch_num) {
ch_budget = CPSW_POLL_WEIGHT / cpsw->tx_ch_num;
bigest_rate = 0;
max_rate = consumed_rate;
} else {
max_rate = cpsw->speed * 1000;
if (max_rate < consumed_rate)
max_rate *= 10;
if (max_rate < consumed_rate)
max_rate *= 10;
ch_budget = (consumed_rate * CPSW_POLL_WEIGHT) / max_rate;
ch_budget = (CPSW_POLL_WEIGHT - ch_budget) /
(cpsw->tx_ch_num - rlim_ch_num);
bigest_rate = (max_rate - consumed_rate) /
(cpsw->tx_ch_num - rlim_ch_num);
}
budget = CPSW_POLL_WEIGHT;
for (i = 0; i < cpsw->tx_ch_num; i++) {
ch_rate = cpdma_chan_get_rate(txv[i].ch);
if (ch_rate) {
txv[i].budget = (ch_rate * CPSW_POLL_WEIGHT) / max_rate;
if (!txv[i].budget)
txv[i].budget++;
if (ch_rate > bigest_rate) {
bigest_rate_ch = i;
bigest_rate = ch_rate;
}
ch_weight = (ch_rate * 100) / max_rate;
if (!ch_weight)
ch_weight++;
cpdma_chan_set_weight(cpsw->txv[i].ch, ch_weight);
} else {
txv[i].budget = ch_budget;
if (!bigest_rate_ch)
bigest_rate_ch = i;
cpdma_chan_set_weight(cpsw->txv[i].ch, 0);
}
budget -= txv[i].budget;
}
if (budget)
txv[bigest_rate_ch].budget += budget;
budget = CPSW_POLL_WEIGHT;
ch_budget = budget / cpsw->rx_ch_num;
for (i = 0; i < cpsw->rx_ch_num; i++) {
cpsw->rxv[i].budget = ch_budget;
budget -= ch_budget;
}
if (budget)
cpsw->rxv[0].budget += budget;
}
static irqreturn_t cpsw_tx_interrupt(int irq, void *dev_id)
{
struct cpsw_common *cpsw = dev_id;
writel(0, &cpsw->wr_regs->tx_en);
cpdma_ctlr_eoi(cpsw->dma, CPDMA_EOI_TX);
if (cpsw->quirk_irq) {
disable_irq_nosync(cpsw->irqs_table[1]);
cpsw->tx_irq_disabled = true;
}
napi_schedule(&cpsw->napi_tx);
return IRQ_HANDLED;
}
static irqreturn_t cpsw_rx_interrupt(int irq, void *dev_id)
{
struct cpsw_common *cpsw = dev_id;
cpdma_ctlr_eoi(cpsw->dma, CPDMA_EOI_RX);
writel(0, &cpsw->wr_regs->rx_en);
if (cpsw->quirk_irq) {
disable_irq_nosync(cpsw->irqs_table[0]);
cpsw->rx_irq_disabled = true;
}
napi_schedule(&cpsw->napi_rx);
return IRQ_HANDLED;
}
static int cpsw_tx_poll(struct napi_struct *napi_tx, int budget)
{
u32 ch_map;
int num_tx, cur_budget, ch;
struct cpsw_common *cpsw = napi_to_cpsw(napi_tx);
struct cpsw_vector *txv;
ch_map = cpdma_ctrl_txchs_state(cpsw->dma);
for (ch = 0, num_tx = 0; ch_map; ch_map >>= 1, ch++) {
if (!(ch_map & 0x01))
continue;
txv = &cpsw->txv[ch];
if (unlikely(txv->budget > budget - num_tx))
cur_budget = budget - num_tx;
else
cur_budget = txv->budget;
num_tx += cpdma_chan_process(txv->ch, cur_budget);
if (num_tx >= budget)
break;
}
if (num_tx < budget) {
napi_complete(napi_tx);
writel(0xff, &cpsw->wr_regs->tx_en);
if (cpsw->quirk_irq && cpsw->tx_irq_disabled) {
cpsw->tx_irq_disabled = false;
enable_irq(cpsw->irqs_table[1]);
}
}
return num_tx;
}
static int cpsw_rx_poll(struct napi_struct *napi_rx, int budget)
{
u32 ch_map;
int num_rx, cur_budget, ch;
struct cpsw_common *cpsw = napi_to_cpsw(napi_rx);
struct cpsw_vector *rxv;
ch_map = cpdma_ctrl_rxchs_state(cpsw->dma);
for (ch = 0, num_rx = 0; ch_map; ch_map >>= 1, ch++) {
if (!(ch_map & 0x01))
continue;
rxv = &cpsw->rxv[ch];
if (unlikely(rxv->budget > budget - num_rx))
cur_budget = budget - num_rx;
else
cur_budget = rxv->budget;
num_rx += cpdma_chan_process(rxv->ch, cur_budget);
if (num_rx >= budget)
break;
}
if (num_rx < budget) {
napi_complete_done(napi_rx, num_rx);
writel(0xff, &cpsw->wr_regs->rx_en);
if (cpsw->quirk_irq && cpsw->rx_irq_disabled) {
cpsw->rx_irq_disabled = false;
enable_irq(cpsw->irqs_table[0]);
}
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
slave_write(slave, mac_hi(priv->mac_addr), SA_HI);
slave_write(slave, mac_lo(priv->mac_addr), SA_LO);
}
static void _cpsw_adjust_link(struct cpsw_slave *slave,
struct cpsw_priv *priv, bool *link)
{
struct phy_device *phy = slave->phy;
u32 mac_control = 0;
u32 slave_port;
struct cpsw_common *cpsw = priv->cpsw;
if (!phy)
return;
slave_port = cpsw_get_slave_port(slave->slave_num);
if (phy->link) {
mac_control = cpsw->data.mac_control;
cpsw_ale_control_set(cpsw->ale, slave_port,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
if (phy->speed == 1000)
mac_control |= BIT(7);
if (phy->duplex)
mac_control |= BIT(0);
if (phy->speed == 100)
mac_control |= BIT(15);
else if (phy->speed == 10)
mac_control |= BIT(18);
if (priv->rx_pause)
mac_control |= BIT(3);
if (priv->tx_pause)
mac_control |= BIT(4);
*link = true;
} else {
mac_control = 0;
cpsw_ale_control_set(cpsw->ale, slave_port,
ALE_PORT_STATE, ALE_PORT_STATE_DISABLE);
}
if (mac_control != slave->mac_control) {
phy_print_status(phy);
__raw_writel(mac_control, &slave->sliver->mac_control);
}
slave->mac_control = mac_control;
}
static int cpsw_get_common_speed(struct cpsw_common *cpsw)
{
int i, speed;
for (i = 0, speed = 0; i < cpsw->data.slaves; i++)
if (cpsw->slaves[i].phy && cpsw->slaves[i].phy->link)
speed += cpsw->slaves[i].phy->speed;
return speed;
}
static int cpsw_need_resplit(struct cpsw_common *cpsw)
{
int i, rlim_ch_num;
int speed, ch_rate;
speed = cpsw_get_common_speed(cpsw);
if (speed == cpsw->speed || !speed)
return 0;
cpsw->speed = speed;
for (i = 0, rlim_ch_num = 0; i < cpsw->tx_ch_num; i++) {
ch_rate = cpdma_chan_get_rate(cpsw->txv[i].ch);
if (!ch_rate)
break;
rlim_ch_num++;
}
if (!rlim_ch_num || rlim_ch_num == cpsw->tx_ch_num)
return 0;
return 1;
}
static void cpsw_adjust_link(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
bool link = false;
for_each_slave(priv, _cpsw_adjust_link, priv, &link);
if (link) {
if (cpsw_need_resplit(cpsw))
cpsw_split_res(ndev);
netif_carrier_on(ndev);
if (netif_running(ndev))
netif_tx_wake_all_queues(ndev);
} else {
netif_carrier_off(ndev);
netif_tx_stop_all_queues(ndev);
}
}
static int cpsw_get_coalesce(struct net_device *ndev,
struct ethtool_coalesce *coal)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
coal->rx_coalesce_usecs = cpsw->coal_intvl;
return 0;
}
static int cpsw_set_coalesce(struct net_device *ndev,
struct ethtool_coalesce *coal)
{
struct cpsw_priv *priv = netdev_priv(ndev);
u32 int_ctrl;
u32 num_interrupts = 0;
u32 prescale = 0;
u32 addnl_dvdr = 1;
u32 coal_intvl = 0;
struct cpsw_common *cpsw = priv->cpsw;
coal_intvl = coal->rx_coalesce_usecs;
int_ctrl = readl(&cpsw->wr_regs->int_control);
prescale = cpsw->bus_freq_mhz * 4;
if (!coal->rx_coalesce_usecs) {
int_ctrl &= ~(CPSW_INTPRESCALE_MASK | CPSW_INTPACEEN);
goto update_return;
}
if (coal_intvl < CPSW_CMINTMIN_INTVL)
coal_intvl = CPSW_CMINTMIN_INTVL;
if (coal_intvl > CPSW_CMINTMAX_INTVL) {
addnl_dvdr = CPSW_INTPRESCALE_MASK / prescale;
if (addnl_dvdr > 1) {
prescale *= addnl_dvdr;
if (coal_intvl > (CPSW_CMINTMAX_INTVL * addnl_dvdr))
coal_intvl = (CPSW_CMINTMAX_INTVL
* addnl_dvdr);
} else {
addnl_dvdr = 1;
coal_intvl = CPSW_CMINTMAX_INTVL;
}
}
num_interrupts = (1000 * addnl_dvdr) / coal_intvl;
writel(num_interrupts, &cpsw->wr_regs->rx_imax);
writel(num_interrupts, &cpsw->wr_regs->tx_imax);
int_ctrl |= CPSW_INTPACEEN;
int_ctrl &= (~CPSW_INTPRESCALE_MASK);
int_ctrl |= (prescale & CPSW_INTPRESCALE_MASK);
update_return:
writel(int_ctrl, &cpsw->wr_regs->int_control);
cpsw_notice(priv, timer, "Set coalesce to %d usecs.\n", coal_intvl);
cpsw->coal_intvl = coal_intvl;
return 0;
}
static int cpsw_get_sset_count(struct net_device *ndev, int sset)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
switch (sset) {
case ETH_SS_STATS:
return (CPSW_STATS_COMMON_LEN +
(cpsw->rx_ch_num + cpsw->tx_ch_num) *
CPSW_STATS_CH_LEN);
default:
return -EOPNOTSUPP;
}
}
static void cpsw_add_ch_strings(u8 **p, int ch_num, int rx_dir)
{
int ch_stats_len;
int line;
int i;
ch_stats_len = CPSW_STATS_CH_LEN * ch_num;
for (i = 0; i < ch_stats_len; i++) {
line = i % CPSW_STATS_CH_LEN;
snprintf(*p, ETH_GSTRING_LEN,
"%s DMA chan %d: %s", rx_dir ? "Rx" : "Tx",
i / CPSW_STATS_CH_LEN,
cpsw_gstrings_ch_stats[line].stat_string);
*p += ETH_GSTRING_LEN;
}
}
static void cpsw_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < CPSW_STATS_COMMON_LEN; i++) {
memcpy(p, cpsw_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
cpsw_add_ch_strings(&p, cpsw->rx_ch_num, 1);
cpsw_add_ch_strings(&p, cpsw->tx_ch_num, 0);
break;
}
}
static void cpsw_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
u8 *p;
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
struct cpdma_chan_stats ch_stats;
int i, l, ch;
for (l = 0; l < CPSW_STATS_COMMON_LEN; l++)
data[l] = readl(cpsw->hw_stats +
cpsw_gstrings_stats[l].stat_offset);
for (ch = 0; ch < cpsw->rx_ch_num; ch++) {
cpdma_chan_get_stats(cpsw->rxv[ch].ch, &ch_stats);
for (i = 0; i < CPSW_STATS_CH_LEN; i++, l++) {
p = (u8 *)&ch_stats +
cpsw_gstrings_ch_stats[i].stat_offset;
data[l] = *(u32 *)p;
}
}
for (ch = 0; ch < cpsw->tx_ch_num; ch++) {
cpdma_chan_get_stats(cpsw->txv[ch].ch, &ch_stats);
for (i = 0; i < CPSW_STATS_CH_LEN; i++, l++) {
p = (u8 *)&ch_stats +
cpsw_gstrings_ch_stats[i].stat_offset;
data[l] = *(u32 *)p;
}
}
}
static inline int cpsw_tx_packet_submit(struct cpsw_priv *priv,
struct sk_buff *skb,
struct cpdma_chan *txch)
{
struct cpsw_common *cpsw = priv->cpsw;
return cpdma_chan_submit(txch, skb, skb->data, skb->len,
priv->emac_port + cpsw->data.dual_emac);
}
static inline void cpsw_add_dual_emac_def_ale_entries(
struct cpsw_priv *priv, struct cpsw_slave *slave,
u32 slave_port)
{
struct cpsw_common *cpsw = priv->cpsw;
u32 port_mask = 1 << slave_port | ALE_PORT_HOST;
if (cpsw->version == CPSW_VERSION_1)
slave_write(slave, slave->port_vlan, CPSW1_PORT_VLAN);
else
slave_write(slave, slave->port_vlan, CPSW2_PORT_VLAN);
cpsw_ale_add_vlan(cpsw->ale, slave->port_vlan, port_mask,
port_mask, port_mask, 0);
cpsw_ale_add_mcast(cpsw->ale, priv->ndev->broadcast,
port_mask, ALE_VLAN, slave->port_vlan, 0);
cpsw_ale_add_ucast(cpsw->ale, priv->mac_addr,
HOST_PORT_NUM, ALE_VLAN |
ALE_SECURE, slave->port_vlan);
}
static void soft_reset_slave(struct cpsw_slave *slave)
{
char name[32];
snprintf(name, sizeof(name), "slave-%d", slave->slave_num);
soft_reset(name, &slave->sliver->soft_reset);
}
static void cpsw_slave_open(struct cpsw_slave *slave, struct cpsw_priv *priv)
{
u32 slave_port;
struct phy_device *phy;
struct cpsw_common *cpsw = priv->cpsw;
soft_reset_slave(slave);
__raw_writel(RX_PRIORITY_MAPPING, &slave->sliver->rx_pri_map);
switch (cpsw->version) {
case CPSW_VERSION_1:
slave_write(slave, TX_PRIORITY_MAPPING, CPSW1_TX_PRI_MAP);
break;
case CPSW_VERSION_2:
case CPSW_VERSION_3:
case CPSW_VERSION_4:
slave_write(slave, TX_PRIORITY_MAPPING, CPSW2_TX_PRI_MAP);
break;
}
__raw_writel(cpsw->rx_packet_max, &slave->sliver->rx_maxlen);
cpsw_set_slave_mac(slave, priv);
slave->mac_control = 0;
slave_port = cpsw_get_slave_port(slave->slave_num);
if (cpsw->data.dual_emac)
cpsw_add_dual_emac_def_ale_entries(priv, slave, slave_port);
else
cpsw_ale_add_mcast(cpsw->ale, priv->ndev->broadcast,
1 << slave_port, 0, 0, ALE_MCAST_FWD_2);
if (slave->data->phy_node) {
phy = of_phy_connect(priv->ndev, slave->data->phy_node,
&cpsw_adjust_link, 0, slave->data->phy_if);
if (!phy) {
dev_err(priv->dev, "phy \"%s\" not found on slave %d\n",
slave->data->phy_node->full_name,
slave->slave_num);
return;
}
} else {
phy = phy_connect(priv->ndev, slave->data->phy_id,
&cpsw_adjust_link, slave->data->phy_if);
if (IS_ERR(phy)) {
dev_err(priv->dev,
"phy \"%s\" not found on slave %d, err %ld\n",
slave->data->phy_id, slave->slave_num,
PTR_ERR(phy));
return;
}
}
slave->phy = phy;
phy_attached_info(slave->phy);
phy_start(slave->phy);
cpsw_phy_sel(cpsw->dev, slave->phy->interface, slave->slave_num);
}
static inline void cpsw_add_default_vlan(struct cpsw_priv *priv)
{
struct cpsw_common *cpsw = priv->cpsw;
const int vlan = cpsw->data.default_vlan;
u32 reg;
int i;
int unreg_mcast_mask;
reg = (cpsw->version == CPSW_VERSION_1) ? CPSW1_PORT_VLAN :
CPSW2_PORT_VLAN;
writel(vlan, &cpsw->host_port_regs->port_vlan);
for (i = 0; i < cpsw->data.slaves; i++)
slave_write(cpsw->slaves + i, vlan, reg);
if (priv->ndev->flags & IFF_ALLMULTI)
unreg_mcast_mask = ALE_ALL_PORTS;
else
unreg_mcast_mask = ALE_PORT_1 | ALE_PORT_2;
cpsw_ale_add_vlan(cpsw->ale, vlan, ALE_ALL_PORTS,
ALE_ALL_PORTS, ALE_ALL_PORTS,
unreg_mcast_mask);
}
static void cpsw_init_host_port(struct cpsw_priv *priv)
{
u32 fifo_mode;
u32 control_reg;
struct cpsw_common *cpsw = priv->cpsw;
soft_reset("cpsw", &cpsw->regs->soft_reset);
cpsw_ale_start(cpsw->ale);
cpsw_ale_control_set(cpsw->ale, HOST_PORT_NUM, ALE_VLAN_AWARE,
CPSW_ALE_VLAN_AWARE);
control_reg = readl(&cpsw->regs->control);
control_reg |= CPSW_VLAN_AWARE;
writel(control_reg, &cpsw->regs->control);
fifo_mode = (cpsw->data.dual_emac) ? CPSW_FIFO_DUAL_MAC_MODE :
CPSW_FIFO_NORMAL_MODE;
writel(fifo_mode, &cpsw->host_port_regs->tx_in_ctl);
__raw_writel(CPDMA_TX_PRIORITY_MAP,
&cpsw->host_port_regs->cpdma_tx_pri_map);
__raw_writel(0, &cpsw->host_port_regs->cpdma_rx_chan_map);
cpsw_ale_control_set(cpsw->ale, HOST_PORT_NUM,
ALE_PORT_STATE, ALE_PORT_STATE_FORWARD);
if (!cpsw->data.dual_emac) {
cpsw_ale_add_ucast(cpsw->ale, priv->mac_addr, HOST_PORT_NUM,
0, 0);
cpsw_ale_add_mcast(cpsw->ale, priv->ndev->broadcast,
ALE_PORT_HOST, 0, 0, ALE_MCAST_FWD_2);
}
}
static int cpsw_fill_rx_channels(struct cpsw_priv *priv)
{
struct cpsw_common *cpsw = priv->cpsw;
struct sk_buff *skb;
int ch_buf_num;
int ch, i, ret;
for (ch = 0; ch < cpsw->rx_ch_num; ch++) {
ch_buf_num = cpdma_chan_get_rx_buf_num(cpsw->rxv[ch].ch);
for (i = 0; i < ch_buf_num; i++) {
skb = __netdev_alloc_skb_ip_align(priv->ndev,
cpsw->rx_packet_max,
GFP_KERNEL);
if (!skb) {
cpsw_err(priv, ifup, "cannot allocate skb\n");
return -ENOMEM;
}
skb_set_queue_mapping(skb, ch);
ret = cpdma_chan_submit(cpsw->rxv[ch].ch, skb,
skb->data, skb_tailroom(skb),
0);
if (ret < 0) {
cpsw_err(priv, ifup,
"cannot submit skb to channel %d rx, error %d\n",
ch, ret);
kfree_skb(skb);
return ret;
}
kmemleak_not_leak(skb);
}
cpsw_info(priv, ifup, "ch %d rx, submitted %d descriptors\n",
ch, ch_buf_num);
}
return 0;
}
static void cpsw_slave_stop(struct cpsw_slave *slave, struct cpsw_common *cpsw)
{
u32 slave_port;
slave_port = cpsw_get_slave_port(slave->slave_num);
if (!slave->phy)
return;
phy_stop(slave->phy);
phy_disconnect(slave->phy);
slave->phy = NULL;
cpsw_ale_control_set(cpsw->ale, slave_port,
ALE_PORT_STATE, ALE_PORT_STATE_DISABLE);
soft_reset_slave(slave);
}
static int cpsw_ndo_open(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ret;
u32 reg;
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
pm_runtime_put_noidle(cpsw->dev);
return ret;
}
netif_carrier_off(ndev);
ret = netif_set_real_num_tx_queues(ndev, cpsw->tx_ch_num);
if (ret) {
dev_err(priv->dev, "cannot set real number of tx queues\n");
goto err_cleanup;
}
ret = netif_set_real_num_rx_queues(ndev, cpsw->rx_ch_num);
if (ret) {
dev_err(priv->dev, "cannot set real number of rx queues\n");
goto err_cleanup;
}
reg = cpsw->version;
dev_info(priv->dev, "initializing cpsw version %d.%d (%d)\n",
CPSW_MAJOR_VERSION(reg), CPSW_MINOR_VERSION(reg),
CPSW_RTL_VERSION(reg));
if (!cpsw->usage_count)
cpsw_init_host_port(priv);
for_each_slave(priv, cpsw_slave_open, priv);
if (!cpsw->data.dual_emac)
cpsw_add_default_vlan(priv);
else
cpsw_ale_add_vlan(cpsw->ale, cpsw->data.default_vlan,
ALE_ALL_PORTS, ALE_ALL_PORTS, 0, 0);
if (!cpsw->usage_count) {
__raw_writel(0, &cpsw->regs->ptype);
__raw_writel(0x7, &cpsw->regs->stat_port_en);
writel(0x7, &cpsw->regs->flow_control);
napi_enable(&cpsw->napi_rx);
napi_enable(&cpsw->napi_tx);
if (cpsw->tx_irq_disabled) {
cpsw->tx_irq_disabled = false;
enable_irq(cpsw->irqs_table[1]);
}
if (cpsw->rx_irq_disabled) {
cpsw->rx_irq_disabled = false;
enable_irq(cpsw->irqs_table[0]);
}
ret = cpsw_fill_rx_channels(priv);
if (ret < 0)
goto err_cleanup;
if (cpts_register(cpsw->cpts))
dev_err(priv->dev, "error registering cpts device\n");
}
if (cpsw->coal_intvl != 0) {
struct ethtool_coalesce coal;
coal.rx_coalesce_usecs = cpsw->coal_intvl;
cpsw_set_coalesce(ndev, &coal);
}
cpdma_ctlr_start(cpsw->dma);
cpsw_intr_enable(cpsw);
cpsw->usage_count++;
return 0;
err_cleanup:
cpdma_ctlr_stop(cpsw->dma);
for_each_slave(priv, cpsw_slave_stop, cpsw);
pm_runtime_put_sync(cpsw->dev);
netif_carrier_off(priv->ndev);
return ret;
}
static int cpsw_ndo_stop(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
cpsw_info(priv, ifdown, "shutting down cpsw device\n");
netif_tx_stop_all_queues(priv->ndev);
netif_carrier_off(priv->ndev);
if (cpsw->usage_count <= 1) {
napi_disable(&cpsw->napi_rx);
napi_disable(&cpsw->napi_tx);
cpts_unregister(cpsw->cpts);
cpsw_intr_disable(cpsw);
cpdma_ctlr_stop(cpsw->dma);
cpsw_ale_stop(cpsw->ale);
}
for_each_slave(priv, cpsw_slave_stop, cpsw);
if (cpsw_need_resplit(cpsw))
cpsw_split_res(ndev);
cpsw->usage_count--;
pm_runtime_put_sync(cpsw->dev);
return 0;
}
static netdev_tx_t cpsw_ndo_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
struct netdev_queue *txq;
struct cpdma_chan *txch;
int ret, q_idx;
if (skb_padto(skb, CPSW_MIN_PACKET_SIZE)) {
cpsw_err(priv, tx_err, "packet pad failed\n");
ndev->stats.tx_dropped++;
return NET_XMIT_DROP;
}
if (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP &&
cpts_is_tx_enabled(cpsw->cpts))
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
skb_tx_timestamp(skb);
q_idx = skb_get_queue_mapping(skb);
if (q_idx >= cpsw->tx_ch_num)
q_idx = q_idx % cpsw->tx_ch_num;
txch = cpsw->txv[q_idx].ch;
ret = cpsw_tx_packet_submit(priv, skb, txch);
if (unlikely(ret != 0)) {
cpsw_err(priv, tx_err, "desc submit failed\n");
goto fail;
}
if (unlikely(!cpdma_check_free_tx_desc(txch))) {
txq = netdev_get_tx_queue(ndev, q_idx);
netif_tx_stop_queue(txq);
}
return NETDEV_TX_OK;
fail:
ndev->stats.tx_dropped++;
txq = netdev_get_tx_queue(ndev, skb_get_queue_mapping(skb));
netif_tx_stop_queue(txq);
return NETDEV_TX_BUSY;
}
static void cpsw_hwtstamp_v1(struct cpsw_common *cpsw)
{
struct cpsw_slave *slave = &cpsw->slaves[cpsw->data.active_slave];
u32 ts_en, seq_id;
if (!cpts_is_tx_enabled(cpsw->cpts) &&
!cpts_is_rx_enabled(cpsw->cpts)) {
slave_write(slave, 0, CPSW1_TS_CTL);
return;
}
seq_id = (30 << CPSW_V1_SEQ_ID_OFS_SHIFT) | ETH_P_1588;
ts_en = EVENT_MSG_BITS << CPSW_V1_MSG_TYPE_OFS;
if (cpts_is_tx_enabled(cpsw->cpts))
ts_en |= CPSW_V1_TS_TX_EN;
if (cpts_is_rx_enabled(cpsw->cpts))
ts_en |= CPSW_V1_TS_RX_EN;
slave_write(slave, ts_en, CPSW1_TS_CTL);
slave_write(slave, seq_id, CPSW1_TS_SEQ_LTYPE);
}
static void cpsw_hwtstamp_v2(struct cpsw_priv *priv)
{
struct cpsw_slave *slave;
struct cpsw_common *cpsw = priv->cpsw;
u32 ctrl, mtype;
slave = &cpsw->slaves[cpsw_slave_index(cpsw, priv)];
ctrl = slave_read(slave, CPSW2_CONTROL);
switch (cpsw->version) {
case CPSW_VERSION_2:
ctrl &= ~CTRL_V2_ALL_TS_MASK;
if (cpts_is_tx_enabled(cpsw->cpts))
ctrl |= CTRL_V2_TX_TS_BITS;
if (cpts_is_rx_enabled(cpsw->cpts))
ctrl |= CTRL_V2_RX_TS_BITS;
break;
case CPSW_VERSION_3:
default:
ctrl &= ~CTRL_V3_ALL_TS_MASK;
if (cpts_is_tx_enabled(cpsw->cpts))
ctrl |= CTRL_V3_TX_TS_BITS;
if (cpts_is_rx_enabled(cpsw->cpts))
ctrl |= CTRL_V3_RX_TS_BITS;
break;
}
mtype = (30 << TS_SEQ_ID_OFFSET_SHIFT) | EVENT_MSG_BITS;
slave_write(slave, mtype, CPSW2_TS_SEQ_MTYPE);
slave_write(slave, ctrl, CPSW2_CONTROL);
__raw_writel(ETH_P_1588, &cpsw->regs->ts_ltype);
}
static int cpsw_hwtstamp_set(struct net_device *dev, struct ifreq *ifr)
{
struct cpsw_priv *priv = netdev_priv(dev);
struct hwtstamp_config cfg;
struct cpsw_common *cpsw = priv->cpsw;
struct cpts *cpts = cpsw->cpts;
if (cpsw->version != CPSW_VERSION_1 &&
cpsw->version != CPSW_VERSION_2 &&
cpsw->version != CPSW_VERSION_3)
return -EOPNOTSUPP;
if (copy_from_user(&cfg, ifr->ifr_data, sizeof(cfg)))
return -EFAULT;
if (cfg.flags)
return -EINVAL;
if (cfg.tx_type != HWTSTAMP_TX_OFF && cfg.tx_type != HWTSTAMP_TX_ON)
return -ERANGE;
switch (cfg.rx_filter) {
case HWTSTAMP_FILTER_NONE:
cpts_rx_enable(cpts, 0);
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
return -ERANGE;
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
cpts_rx_enable(cpts, 1);
cfg.rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
break;
default:
return -ERANGE;
}
cpts_tx_enable(cpts, cfg.tx_type == HWTSTAMP_TX_ON);
switch (cpsw->version) {
case CPSW_VERSION_1:
cpsw_hwtstamp_v1(cpsw);
break;
case CPSW_VERSION_2:
case CPSW_VERSION_3:
cpsw_hwtstamp_v2(priv);
break;
default:
WARN_ON(1);
}
return copy_to_user(ifr->ifr_data, &cfg, sizeof(cfg)) ? -EFAULT : 0;
}
static int cpsw_hwtstamp_get(struct net_device *dev, struct ifreq *ifr)
{
struct cpsw_common *cpsw = ndev_to_cpsw(dev);
struct cpts *cpts = cpsw->cpts;
struct hwtstamp_config cfg;
if (cpsw->version != CPSW_VERSION_1 &&
cpsw->version != CPSW_VERSION_2 &&
cpsw->version != CPSW_VERSION_3)
return -EOPNOTSUPP;
cfg.flags = 0;
cfg.tx_type = cpts_is_tx_enabled(cpts) ?
HWTSTAMP_TX_ON : HWTSTAMP_TX_OFF;
cfg.rx_filter = (cpts_is_rx_enabled(cpts) ?
HWTSTAMP_FILTER_PTP_V2_EVENT : HWTSTAMP_FILTER_NONE);
return copy_to_user(ifr->ifr_data, &cfg, sizeof(cfg)) ? -EFAULT : 0;
}
static int cpsw_hwtstamp_get(struct net_device *dev, struct ifreq *ifr)
{
return -EOPNOTSUPP;
}
static int cpsw_hwtstamp_set(struct net_device *dev, struct ifreq *ifr)
{
return -EOPNOTSUPP;
}
static int cpsw_ndo_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
struct cpsw_priv *priv = netdev_priv(dev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (!netif_running(dev))
return -EINVAL;
switch (cmd) {
case SIOCSHWTSTAMP:
return cpsw_hwtstamp_set(dev, req);
case SIOCGHWTSTAMP:
return cpsw_hwtstamp_get(dev, req);
}
if (!cpsw->slaves[slave_no].phy)
return -EOPNOTSUPP;
return phy_mii_ioctl(cpsw->slaves[slave_no].phy, req, cmd);
}
static void cpsw_ndo_tx_timeout(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ch;
cpsw_err(priv, tx_err, "transmit timeout, restarting dma\n");
ndev->stats.tx_errors++;
cpsw_intr_disable(cpsw);
for (ch = 0; ch < cpsw->tx_ch_num; ch++) {
cpdma_chan_stop(cpsw->txv[ch].ch);
cpdma_chan_start(cpsw->txv[ch].ch);
}
cpsw_intr_enable(cpsw);
netif_trans_update(ndev);
netif_tx_wake_all_queues(ndev);
}
static int cpsw_ndo_set_mac_address(struct net_device *ndev, void *p)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct sockaddr *addr = (struct sockaddr *)p;
struct cpsw_common *cpsw = priv->cpsw;
int flags = 0;
u16 vid = 0;
int ret;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
pm_runtime_put_noidle(cpsw->dev);
return ret;
}
if (cpsw->data.dual_emac) {
vid = cpsw->slaves[priv->emac_port].port_vlan;
flags = ALE_VLAN;
}
cpsw_ale_del_ucast(cpsw->ale, priv->mac_addr, HOST_PORT_NUM,
flags, vid);
cpsw_ale_add_ucast(cpsw->ale, addr->sa_data, HOST_PORT_NUM,
flags, vid);
memcpy(priv->mac_addr, addr->sa_data, ETH_ALEN);
memcpy(ndev->dev_addr, priv->mac_addr, ETH_ALEN);
for_each_slave(priv, cpsw_set_slave_mac, priv);
pm_runtime_put(cpsw->dev);
return 0;
}
static void cpsw_ndo_poll_controller(struct net_device *ndev)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
cpsw_intr_disable(cpsw);
cpsw_rx_interrupt(cpsw->irqs_table[0], cpsw);
cpsw_tx_interrupt(cpsw->irqs_table[1], cpsw);
cpsw_intr_enable(cpsw);
}
static inline int cpsw_add_vlan_ale_entry(struct cpsw_priv *priv,
unsigned short vid)
{
int ret;
int unreg_mcast_mask = 0;
u32 port_mask;
struct cpsw_common *cpsw = priv->cpsw;
if (cpsw->data.dual_emac) {
port_mask = (1 << (priv->emac_port + 1)) | ALE_PORT_HOST;
if (priv->ndev->flags & IFF_ALLMULTI)
unreg_mcast_mask = port_mask;
} else {
port_mask = ALE_ALL_PORTS;
if (priv->ndev->flags & IFF_ALLMULTI)
unreg_mcast_mask = ALE_ALL_PORTS;
else
unreg_mcast_mask = ALE_PORT_1 | ALE_PORT_2;
}
ret = cpsw_ale_add_vlan(cpsw->ale, vid, port_mask, 0, port_mask,
unreg_mcast_mask);
if (ret != 0)
return ret;
ret = cpsw_ale_add_ucast(cpsw->ale, priv->mac_addr,
HOST_PORT_NUM, ALE_VLAN, vid);
if (ret != 0)
goto clean_vid;
ret = cpsw_ale_add_mcast(cpsw->ale, priv->ndev->broadcast,
port_mask, ALE_VLAN, vid, 0);
if (ret != 0)
goto clean_vlan_ucast;
return 0;
clean_vlan_ucast:
cpsw_ale_del_ucast(cpsw->ale, priv->mac_addr,
HOST_PORT_NUM, ALE_VLAN, vid);
clean_vid:
cpsw_ale_del_vlan(cpsw->ale, vid, 0);
return ret;
}
static int cpsw_ndo_vlan_rx_add_vid(struct net_device *ndev,
__be16 proto, u16 vid)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ret;
if (vid == cpsw->data.default_vlan)
return 0;
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
pm_runtime_put_noidle(cpsw->dev);
return ret;
}
if (cpsw->data.dual_emac) {
int i;
for (i = 0; i < cpsw->data.slaves; i++) {
if (vid == cpsw->slaves[i].port_vlan)
return -EINVAL;
}
}
dev_info(priv->dev, "Adding vlanid %d to vlan filter\n", vid);
ret = cpsw_add_vlan_ale_entry(priv, vid);
pm_runtime_put(cpsw->dev);
return ret;
}
static int cpsw_ndo_vlan_rx_kill_vid(struct net_device *ndev,
__be16 proto, u16 vid)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ret;
if (vid == cpsw->data.default_vlan)
return 0;
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
pm_runtime_put_noidle(cpsw->dev);
return ret;
}
if (cpsw->data.dual_emac) {
int i;
for (i = 0; i < cpsw->data.slaves; i++) {
if (vid == cpsw->slaves[i].port_vlan)
return -EINVAL;
}
}
dev_info(priv->dev, "removing vlanid %d from vlan filter\n", vid);
ret = cpsw_ale_del_vlan(cpsw->ale, vid, 0);
if (ret != 0)
return ret;
ret = cpsw_ale_del_ucast(cpsw->ale, priv->mac_addr,
HOST_PORT_NUM, ALE_VLAN, vid);
if (ret != 0)
return ret;
ret = cpsw_ale_del_mcast(cpsw->ale, priv->ndev->broadcast,
0, ALE_VLAN, vid);
pm_runtime_put(cpsw->dev);
return ret;
}
static int cpsw_ndo_set_tx_maxrate(struct net_device *ndev, int queue, u32 rate)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
struct cpsw_slave *slave;
u32 min_rate;
u32 ch_rate;
int i, ret;
ch_rate = netdev_get_tx_queue(ndev, queue)->tx_maxrate;
if (ch_rate == rate)
return 0;
ch_rate = rate * 1000;
min_rate = cpdma_chan_get_min_rate(cpsw->dma);
if ((ch_rate < min_rate && ch_rate)) {
dev_err(priv->dev, "The channel rate cannot be less than %dMbps",
min_rate);
return -EINVAL;
}
if (rate > cpsw->speed) {
dev_err(priv->dev, "The channel rate cannot be more than 2Gbps");
return -EINVAL;
}
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
pm_runtime_put_noidle(cpsw->dev);
return ret;
}
ret = cpdma_chan_set_rate(cpsw->txv[queue].ch, ch_rate);
pm_runtime_put(cpsw->dev);
if (ret)
return ret;
for (i = 0; i < cpsw->data.slaves; i++) {
slave = &cpsw->slaves[i];
if (!slave->ndev)
continue;
netdev_get_tx_queue(slave->ndev, queue)->tx_maxrate = rate;
}
cpsw_split_res(ndev);
return ret;
}
static int cpsw_get_regs_len(struct net_device *ndev)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
return cpsw->data.ale_entries * ALE_ENTRY_WORDS * sizeof(u32);
}
static void cpsw_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *p)
{
u32 *reg = p;
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
regs->version = cpsw->version;
cpsw_ale_dump(cpsw->ale, reg);
}
static void cpsw_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
struct platform_device *pdev = to_platform_device(cpsw->dev);
strlcpy(info->driver, "cpsw", sizeof(info->driver));
strlcpy(info->version, "1.0", sizeof(info->version));
strlcpy(info->bus_info, pdev->name, sizeof(info->bus_info));
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
static int cpsw_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
info->so_timestamping =
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
info->phc_index = cpsw->cpts->phc_index;
info->tx_types =
(1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters =
(1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V2_EVENT);
return 0;
}
static int cpsw_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
info->so_timestamping =
SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE;
info->phc_index = -1;
info->tx_types = 0;
info->rx_filters = 0;
return 0;
}
static int cpsw_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *ecmd)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return phy_ethtool_ksettings_get(cpsw->slaves[slave_no].phy,
ecmd);
else
return -EOPNOTSUPP;
}
static int cpsw_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *ecmd)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return phy_ethtool_ksettings_set(cpsw->slaves[slave_no].phy,
ecmd);
else
return -EOPNOTSUPP;
}
static void cpsw_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
wol->supported = 0;
wol->wolopts = 0;
if (cpsw->slaves[slave_no].phy)
phy_ethtool_get_wol(cpsw->slaves[slave_no].phy, wol);
}
static int cpsw_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return phy_ethtool_set_wol(cpsw->slaves[slave_no].phy, wol);
else
return -EOPNOTSUPP;
}
static void cpsw_get_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct cpsw_priv *priv = netdev_priv(ndev);
pause->autoneg = AUTONEG_DISABLE;
pause->rx_pause = priv->rx_pause ? true : false;
pause->tx_pause = priv->tx_pause ? true : false;
}
static int cpsw_set_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct cpsw_priv *priv = netdev_priv(ndev);
bool link;
priv->rx_pause = pause->rx_pause ? true : false;
priv->tx_pause = pause->tx_pause ? true : false;
for_each_slave(priv, _cpsw_adjust_link, priv, &link);
return 0;
}
static int cpsw_ethtool_op_begin(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ret;
ret = pm_runtime_get_sync(cpsw->dev);
if (ret < 0) {
cpsw_err(priv, drv, "ethtool begin failed %d\n", ret);
pm_runtime_put_noidle(cpsw->dev);
}
return ret;
}
static void cpsw_ethtool_op_complete(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
int ret;
ret = pm_runtime_put(priv->cpsw->dev);
if (ret < 0)
cpsw_err(priv, drv, "ethtool complete failed %d\n", ret);
}
static void cpsw_get_channels(struct net_device *ndev,
struct ethtool_channels *ch)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
ch->max_combined = 0;
ch->max_rx = CPSW_MAX_QUEUES;
ch->max_tx = CPSW_MAX_QUEUES;
ch->max_other = 0;
ch->other_count = 0;
ch->rx_count = cpsw->rx_ch_num;
ch->tx_count = cpsw->tx_ch_num;
ch->combined_count = 0;
}
static int cpsw_check_ch_settings(struct cpsw_common *cpsw,
struct ethtool_channels *ch)
{
if (ch->combined_count)
return -EINVAL;
if (!ch->rx_count || !ch->tx_count)
return -EINVAL;
if (ch->rx_count > cpsw->data.channels ||
ch->tx_count > cpsw->data.channels)
return -EINVAL;
return 0;
}
static int cpsw_update_channels_res(struct cpsw_priv *priv, int ch_num, int rx)
{
int (*poll)(struct napi_struct *, int);
struct cpsw_common *cpsw = priv->cpsw;
void (*handler)(void *, int, int);
struct netdev_queue *queue;
struct cpsw_vector *vec;
int ret, *ch;
if (rx) {
ch = &cpsw->rx_ch_num;
vec = cpsw->rxv;
handler = cpsw_rx_handler;
poll = cpsw_rx_poll;
} else {
ch = &cpsw->tx_ch_num;
vec = cpsw->txv;
handler = cpsw_tx_handler;
poll = cpsw_tx_poll;
}
while (*ch < ch_num) {
vec[*ch].ch = cpdma_chan_create(cpsw->dma, *ch, handler, rx);
queue = netdev_get_tx_queue(priv->ndev, *ch);
queue->tx_maxrate = 0;
if (IS_ERR(vec[*ch].ch))
return PTR_ERR(vec[*ch].ch);
if (!vec[*ch].ch)
return -EINVAL;
cpsw_info(priv, ifup, "created new %d %s channel\n", *ch,
(rx ? "rx" : "tx"));
(*ch)++;
}
while (*ch > ch_num) {
(*ch)--;
ret = cpdma_chan_destroy(vec[*ch].ch);
if (ret)
return ret;
cpsw_info(priv, ifup, "destroyed %d %s channel\n", *ch,
(rx ? "rx" : "tx"));
}
return 0;
}
static int cpsw_update_channels(struct cpsw_priv *priv,
struct ethtool_channels *ch)
{
int ret;
ret = cpsw_update_channels_res(priv, ch->rx_count, 1);
if (ret)
return ret;
ret = cpsw_update_channels_res(priv, ch->tx_count, 0);
if (ret)
return ret;
return 0;
}
static void cpsw_suspend_data_pass(struct net_device *ndev)
{
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
struct cpsw_slave *slave;
int i;
cpsw_intr_disable(cpsw);
for (i = cpsw->data.slaves, slave = cpsw->slaves; i; i--, slave++) {
if (!(slave->ndev && netif_running(slave->ndev)))
continue;
netif_tx_stop_all_queues(slave->ndev);
netif_dormant_on(slave->ndev);
}
cpdma_ctlr_stop(cpsw->dma);
}
static int cpsw_resume_data_pass(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
struct cpsw_slave *slave;
int i, ret;
for (i = cpsw->data.slaves, slave = cpsw->slaves; i; i--, slave++)
if (slave->ndev && netif_running(slave->ndev))
netif_dormant_off(slave->ndev);
if (cpsw->usage_count) {
ret = cpsw_fill_rx_channels(priv);
if (ret)
return ret;
cpdma_ctlr_start(cpsw->dma);
cpsw_intr_enable(cpsw);
}
for (i = cpsw->data.slaves, slave = cpsw->slaves; i; i--, slave++)
if (slave->ndev && netif_running(slave->ndev))
netif_tx_start_all_queues(slave->ndev);
return 0;
}
static int cpsw_set_channels(struct net_device *ndev,
struct ethtool_channels *chs)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
struct cpsw_slave *slave;
int i, ret;
ret = cpsw_check_ch_settings(cpsw, chs);
if (ret < 0)
return ret;
cpsw_suspend_data_pass(ndev);
ret = cpsw_update_channels(priv, chs);
if (ret)
goto err;
for (i = cpsw->data.slaves, slave = cpsw->slaves; i; i--, slave++) {
if (!(slave->ndev && netif_running(slave->ndev)))
continue;
ret = netif_set_real_num_tx_queues(slave->ndev,
cpsw->tx_ch_num);
if (ret) {
dev_err(priv->dev, "cannot set real number of tx queues\n");
goto err;
}
ret = netif_set_real_num_rx_queues(slave->ndev,
cpsw->rx_ch_num);
if (ret) {
dev_err(priv->dev, "cannot set real number of rx queues\n");
goto err;
}
}
if (cpsw->usage_count)
cpsw_split_res(ndev);
ret = cpsw_resume_data_pass(ndev);
if (!ret)
return 0;
err:
dev_err(priv->dev, "cannot update channels number, closing device\n");
dev_close(ndev);
return ret;
}
static int cpsw_get_eee(struct net_device *ndev, struct ethtool_eee *edata)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return phy_ethtool_get_eee(cpsw->slaves[slave_no].phy, edata);
else
return -EOPNOTSUPP;
}
static int cpsw_set_eee(struct net_device *ndev, struct ethtool_eee *edata)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return phy_ethtool_set_eee(cpsw->slaves[slave_no].phy, edata);
else
return -EOPNOTSUPP;
}
static int cpsw_nway_reset(struct net_device *ndev)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int slave_no = cpsw_slave_index(cpsw, priv);
if (cpsw->slaves[slave_no].phy)
return genphy_restart_aneg(cpsw->slaves[slave_no].phy);
else
return -EOPNOTSUPP;
}
static void cpsw_get_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ering)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
ering->tx_max_pending = 0;
ering->tx_pending = cpdma_get_num_tx_descs(cpsw->dma);
ering->rx_max_pending = descs_pool_size - CPSW_MAX_QUEUES;
ering->rx_pending = cpdma_get_num_rx_descs(cpsw->dma);
}
static int cpsw_set_ringparam(struct net_device *ndev,
struct ethtool_ringparam *ering)
{
struct cpsw_priv *priv = netdev_priv(ndev);
struct cpsw_common *cpsw = priv->cpsw;
int ret;
if (ering->rx_mini_pending || ering->rx_jumbo_pending ||
ering->rx_pending < CPSW_MAX_QUEUES ||
ering->rx_pending > (descs_pool_size - CPSW_MAX_QUEUES))
return -EINVAL;
if (ering->rx_pending == cpdma_get_num_rx_descs(cpsw->dma))
return 0;
cpsw_suspend_data_pass(ndev);
cpdma_set_num_rx_descs(cpsw->dma, ering->rx_pending);
if (cpsw->usage_count)
cpdma_chan_split_pool(cpsw->dma);
ret = cpsw_resume_data_pass(ndev);
if (!ret)
return 0;
dev_err(&ndev->dev, "cannot set ring params, closing device\n");
dev_close(ndev);
return ret;
}
static void cpsw_slave_init(struct cpsw_slave *slave, struct cpsw_common *cpsw,
u32 slave_reg_ofs, u32 sliver_reg_ofs)
{
void __iomem *regs = cpsw->regs;
int slave_num = slave->slave_num;
struct cpsw_slave_data *data = cpsw->data.slave_data + slave_num;
slave->data = data;
slave->regs = regs + slave_reg_ofs;
slave->sliver = regs + sliver_reg_ofs;
slave->port_vlan = data->dual_emac_res_vlan;
}
static int cpsw_probe_dt(struct cpsw_platform_data *data,
struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device_node *slave_node;
int i = 0, ret;
u32 prop;
if (!node)
return -EINVAL;
if (of_property_read_u32(node, "slaves", &prop)) {
dev_err(&pdev->dev, "Missing slaves property in the DT.\n");
return -EINVAL;
}
data->slaves = prop;
if (of_property_read_u32(node, "active_slave", &prop)) {
dev_err(&pdev->dev, "Missing active_slave property in the DT.\n");
return -EINVAL;
}
data->active_slave = prop;
data->slave_data = devm_kzalloc(&pdev->dev, data->slaves
* sizeof(struct cpsw_slave_data),
GFP_KERNEL);
if (!data->slave_data)
return -ENOMEM;
if (of_property_read_u32(node, "cpdma_channels", &prop)) {
dev_err(&pdev->dev, "Missing cpdma_channels property in the DT.\n");
return -EINVAL;
}
data->channels = prop;
if (of_property_read_u32(node, "ale_entries", &prop)) {
dev_err(&pdev->dev, "Missing ale_entries property in the DT.\n");
return -EINVAL;
}
data->ale_entries = prop;
if (of_property_read_u32(node, "bd_ram_size", &prop)) {
dev_err(&pdev->dev, "Missing bd_ram_size property in the DT.\n");
return -EINVAL;
}
data->bd_ram_size = prop;
if (of_property_read_u32(node, "mac_control", &prop)) {
dev_err(&pdev->dev, "Missing mac_control property in the DT.\n");
return -EINVAL;
}
data->mac_control = prop;
if (of_property_read_bool(node, "dual_emac"))
data->dual_emac = 1;
ret = of_platform_populate(node, NULL, NULL, &pdev->dev);
if (ret)
dev_warn(&pdev->dev, "Doesn't have any child node\n");
for_each_available_child_of_node(node, slave_node) {
struct cpsw_slave_data *slave_data = data->slave_data + i;
const void *mac_addr = NULL;
int lenp;
const __be32 *parp;
if (strcmp(slave_node->name, "slave"))
continue;
slave_data->phy_node = of_parse_phandle(slave_node,
"phy-handle", 0);
parp = of_get_property(slave_node, "phy_id", &lenp);
if (slave_data->phy_node) {
dev_dbg(&pdev->dev,
"slave[%d] using phy-handle=\"%s\"\n",
i, slave_data->phy_node->full_name);
} else if (of_phy_is_fixed_link(slave_node)) {
ret = of_phy_register_fixed_link(slave_node);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "failed to register fixed-link phy: %d\n", ret);
return ret;
}
slave_data->phy_node = of_node_get(slave_node);
} else if (parp) {
u32 phyid;
struct device_node *mdio_node;
struct platform_device *mdio;
if (lenp != (sizeof(__be32) * 2)) {
dev_err(&pdev->dev, "Invalid slave[%d] phy_id property\n", i);
goto no_phy_slave;
}
mdio_node = of_find_node_by_phandle(be32_to_cpup(parp));
phyid = be32_to_cpup(parp+1);
mdio = of_find_device_by_node(mdio_node);
of_node_put(mdio_node);
if (!mdio) {
dev_err(&pdev->dev, "Missing mdio platform device\n");
return -EINVAL;
}
snprintf(slave_data->phy_id, sizeof(slave_data->phy_id),
PHY_ID_FMT, mdio->name, phyid);
put_device(&mdio->dev);
} else {
dev_err(&pdev->dev,
"No slave[%d] phy_id, phy-handle, or fixed-link property\n",
i);
goto no_phy_slave;
}
slave_data->phy_if = of_get_phy_mode(slave_node);
if (slave_data->phy_if < 0) {
dev_err(&pdev->dev, "Missing or malformed slave[%d] phy-mode property\n",
i);
return slave_data->phy_if;
}
no_phy_slave:
mac_addr = of_get_mac_address(slave_node);
if (mac_addr) {
memcpy(slave_data->mac_addr, mac_addr, ETH_ALEN);
} else {
ret = ti_cm_get_macid(&pdev->dev, i,
slave_data->mac_addr);
if (ret)
return ret;
}
if (data->dual_emac) {
if (of_property_read_u32(slave_node, "dual_emac_res_vlan",
&prop)) {
dev_err(&pdev->dev, "Missing dual_emac_res_vlan in DT.\n");
slave_data->dual_emac_res_vlan = i+1;
dev_err(&pdev->dev, "Using %d as Reserved VLAN for %d slave\n",
slave_data->dual_emac_res_vlan, i);
} else {
slave_data->dual_emac_res_vlan = prop;
}
}
i++;
if (i == data->slaves)
break;
}
return 0;
}
static void cpsw_remove_dt(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
struct cpsw_platform_data *data = &cpsw->data;
struct device_node *node = pdev->dev.of_node;
struct device_node *slave_node;
int i = 0;
for_each_available_child_of_node(node, slave_node) {
struct cpsw_slave_data *slave_data = &data->slave_data[i];
if (strcmp(slave_node->name, "slave"))
continue;
if (of_phy_is_fixed_link(slave_node))
of_phy_deregister_fixed_link(slave_node);
of_node_put(slave_data->phy_node);
i++;
if (i == data->slaves)
break;
}
of_platform_depopulate(&pdev->dev);
}
static int cpsw_probe_dual_emac(struct cpsw_priv *priv)
{
struct cpsw_common *cpsw = priv->cpsw;
struct cpsw_platform_data *data = &cpsw->data;
struct net_device *ndev;
struct cpsw_priv *priv_sl2;
int ret = 0;
ndev = alloc_etherdev_mq(sizeof(struct cpsw_priv), CPSW_MAX_QUEUES);
if (!ndev) {
dev_err(cpsw->dev, "cpsw: error allocating net_device\n");
return -ENOMEM;
}
priv_sl2 = netdev_priv(ndev);
priv_sl2->cpsw = cpsw;
priv_sl2->ndev = ndev;
priv_sl2->dev = &ndev->dev;
priv_sl2->msg_enable = netif_msg_init(debug_level, CPSW_DEBUG);
if (is_valid_ether_addr(data->slave_data[1].mac_addr)) {
memcpy(priv_sl2->mac_addr, data->slave_data[1].mac_addr,
ETH_ALEN);
dev_info(cpsw->dev, "cpsw: Detected MACID = %pM\n",
priv_sl2->mac_addr);
} else {
random_ether_addr(priv_sl2->mac_addr);
dev_info(cpsw->dev, "cpsw: Random MACID = %pM\n",
priv_sl2->mac_addr);
}
memcpy(ndev->dev_addr, priv_sl2->mac_addr, ETH_ALEN);
priv_sl2->emac_port = 1;
cpsw->slaves[1].ndev = ndev;
ndev->features |= NETIF_F_HW_VLAN_CTAG_FILTER;
ndev->netdev_ops = &cpsw_netdev_ops;
ndev->ethtool_ops = &cpsw_ethtool_ops;
SET_NETDEV_DEV(ndev, cpsw->dev);
ret = register_netdev(ndev);
if (ret) {
dev_err(cpsw->dev, "cpsw: error registering net device\n");
free_netdev(ndev);
ret = -ENODEV;
}
return ret;
}
static int cpsw_probe(struct platform_device *pdev)
{
struct clk *clk;
struct cpsw_platform_data *data;
struct net_device *ndev;
struct cpsw_priv *priv;
struct cpdma_params dma_params;
struct cpsw_ale_params ale_params;
void __iomem *ss_regs;
void __iomem *cpts_regs;
struct resource *res, *ss_res;
const struct of_device_id *of_id;
struct gpio_descs *mode;
u32 slave_offset, sliver_offset, slave_size;
struct cpsw_common *cpsw;
int ret = 0, i;
int irq;
cpsw = devm_kzalloc(&pdev->dev, sizeof(struct cpsw_common), GFP_KERNEL);
if (!cpsw)
return -ENOMEM;
cpsw->dev = &pdev->dev;
ndev = alloc_etherdev_mq(sizeof(struct cpsw_priv), CPSW_MAX_QUEUES);
if (!ndev) {
dev_err(&pdev->dev, "error allocating net_device\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, ndev);
priv = netdev_priv(ndev);
priv->cpsw = cpsw;
priv->ndev = ndev;
priv->dev = &ndev->dev;
priv->msg_enable = netif_msg_init(debug_level, CPSW_DEBUG);
cpsw->rx_packet_max = max(rx_packet_max, 128);
mode = devm_gpiod_get_array_optional(&pdev->dev, "mode", GPIOD_OUT_LOW);
if (IS_ERR(mode)) {
ret = PTR_ERR(mode);
dev_err(&pdev->dev, "gpio request failed, ret %d\n", ret);
goto clean_ndev_ret;
}
pm_runtime_enable(&pdev->dev);
pinctrl_pm_select_default_state(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
pm_runtime_put_noidle(&pdev->dev);
goto clean_runtime_disable_ret;
}
ret = cpsw_probe_dt(&cpsw->data, pdev);
if (ret)
goto clean_dt_ret;
data = &cpsw->data;
cpsw->rx_ch_num = 1;
cpsw->tx_ch_num = 1;
if (is_valid_ether_addr(data->slave_data[0].mac_addr)) {
memcpy(priv->mac_addr, data->slave_data[0].mac_addr, ETH_ALEN);
dev_info(&pdev->dev, "Detected MACID = %pM\n", priv->mac_addr);
} else {
eth_random_addr(priv->mac_addr);
dev_info(&pdev->dev, "Random MACID = %pM\n", priv->mac_addr);
}
memcpy(ndev->dev_addr, priv->mac_addr, ETH_ALEN);
cpsw->slaves = devm_kzalloc(&pdev->dev,
sizeof(struct cpsw_slave) * data->slaves,
GFP_KERNEL);
if (!cpsw->slaves) {
ret = -ENOMEM;
goto clean_dt_ret;
}
for (i = 0; i < data->slaves; i++)
cpsw->slaves[i].slave_num = i;
cpsw->slaves[0].ndev = ndev;
priv->emac_port = 0;
clk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(clk)) {
dev_err(priv->dev, "fck is not found\n");
ret = -ENODEV;
goto clean_dt_ret;
}
cpsw->bus_freq_mhz = clk_get_rate(clk) / 1000000;
ss_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ss_regs = devm_ioremap_resource(&pdev->dev, ss_res);
if (IS_ERR(ss_regs)) {
ret = PTR_ERR(ss_regs);
goto clean_dt_ret;
}
cpsw->regs = ss_regs;
cpsw->version = readl(&cpsw->regs->id_ver);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
cpsw->wr_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(cpsw->wr_regs)) {
ret = PTR_ERR(cpsw->wr_regs);
goto clean_dt_ret;
}
memset(&dma_params, 0, sizeof(dma_params));
memset(&ale_params, 0, sizeof(ale_params));
switch (cpsw->version) {
case CPSW_VERSION_1:
cpsw->host_port_regs = ss_regs + CPSW1_HOST_PORT_OFFSET;
cpts_regs = ss_regs + CPSW1_CPTS_OFFSET;
cpsw->hw_stats = ss_regs + CPSW1_HW_STATS;
dma_params.dmaregs = ss_regs + CPSW1_CPDMA_OFFSET;
dma_params.txhdp = ss_regs + CPSW1_STATERAM_OFFSET;
ale_params.ale_regs = ss_regs + CPSW1_ALE_OFFSET;
slave_offset = CPSW1_SLAVE_OFFSET;
slave_size = CPSW1_SLAVE_SIZE;
sliver_offset = CPSW1_SLIVER_OFFSET;
dma_params.desc_mem_phys = 0;
break;
case CPSW_VERSION_2:
case CPSW_VERSION_3:
case CPSW_VERSION_4:
cpsw->host_port_regs = ss_regs + CPSW2_HOST_PORT_OFFSET;
cpts_regs = ss_regs + CPSW2_CPTS_OFFSET;
cpsw->hw_stats = ss_regs + CPSW2_HW_STATS;
dma_params.dmaregs = ss_regs + CPSW2_CPDMA_OFFSET;
dma_params.txhdp = ss_regs + CPSW2_STATERAM_OFFSET;
ale_params.ale_regs = ss_regs + CPSW2_ALE_OFFSET;
slave_offset = CPSW2_SLAVE_OFFSET;
slave_size = CPSW2_SLAVE_SIZE;
sliver_offset = CPSW2_SLIVER_OFFSET;
dma_params.desc_mem_phys =
(u32 __force) ss_res->start + CPSW2_BD_OFFSET;
break;
default:
dev_err(priv->dev, "unknown version 0x%08x\n", cpsw->version);
ret = -ENODEV;
goto clean_dt_ret;
}
for (i = 0; i < cpsw->data.slaves; i++) {
struct cpsw_slave *slave = &cpsw->slaves[i];
cpsw_slave_init(slave, cpsw, slave_offset, sliver_offset);
slave_offset += slave_size;
sliver_offset += SLIVER_SIZE;
}
dma_params.dev = &pdev->dev;
dma_params.rxthresh = dma_params.dmaregs + CPDMA_RXTHRESH;
dma_params.rxfree = dma_params.dmaregs + CPDMA_RXFREE;
dma_params.rxhdp = dma_params.txhdp + CPDMA_RXHDP;
dma_params.txcp = dma_params.txhdp + CPDMA_TXCP;
dma_params.rxcp = dma_params.txhdp + CPDMA_RXCP;
dma_params.num_chan = data->channels;
dma_params.has_soft_reset = true;
dma_params.min_packet_size = CPSW_MIN_PACKET_SIZE;
dma_params.desc_mem_size = data->bd_ram_size;
dma_params.desc_align = 16;
dma_params.has_ext_regs = true;
dma_params.desc_hw_addr = dma_params.desc_mem_phys;
dma_params.bus_freq_mhz = cpsw->bus_freq_mhz;
dma_params.descs_pool_size = descs_pool_size;
cpsw->dma = cpdma_ctlr_create(&dma_params);
if (!cpsw->dma) {
dev_err(priv->dev, "error initializing dma\n");
ret = -ENOMEM;
goto clean_dt_ret;
}
cpsw->txv[0].ch = cpdma_chan_create(cpsw->dma, 0, cpsw_tx_handler, 0);
cpsw->rxv[0].ch = cpdma_chan_create(cpsw->dma, 0, cpsw_rx_handler, 1);
if (WARN_ON(!cpsw->rxv[0].ch || !cpsw->txv[0].ch)) {
dev_err(priv->dev, "error initializing dma channels\n");
ret = -ENOMEM;
goto clean_dma_ret;
}
ale_params.dev = &pdev->dev;
ale_params.ale_ageout = ale_ageout;
ale_params.ale_entries = data->ale_entries;
ale_params.ale_ports = data->slaves;
cpsw->ale = cpsw_ale_create(&ale_params);
if (!cpsw->ale) {
dev_err(priv->dev, "error initializing ale engine\n");
ret = -ENODEV;
goto clean_dma_ret;
}
cpsw->cpts = cpts_create(cpsw->dev, cpts_regs, cpsw->dev->of_node);
if (IS_ERR(cpsw->cpts)) {
ret = PTR_ERR(cpsw->cpts);
goto clean_ale_ret;
}
ndev->irq = platform_get_irq(pdev, 1);
if (ndev->irq < 0) {
dev_err(priv->dev, "error getting irq resource\n");
ret = ndev->irq;
goto clean_ale_ret;
}
of_id = of_match_device(cpsw_of_mtable, &pdev->dev);
if (of_id) {
pdev->id_entry = of_id->data;
if (pdev->id_entry->driver_data)
cpsw->quirk_irq = true;
}
irq = platform_get_irq(pdev, 1);
if (irq < 0) {
ret = irq;
goto clean_ale_ret;
}
cpsw->irqs_table[0] = irq;
ret = devm_request_irq(&pdev->dev, irq, cpsw_rx_interrupt,
0, dev_name(&pdev->dev), cpsw);
if (ret < 0) {
dev_err(priv->dev, "error attaching irq (%d)\n", ret);
goto clean_ale_ret;
}
irq = platform_get_irq(pdev, 2);
if (irq < 0) {
ret = irq;
goto clean_ale_ret;
}
cpsw->irqs_table[1] = irq;
ret = devm_request_irq(&pdev->dev, irq, cpsw_tx_interrupt,
0, dev_name(&pdev->dev), cpsw);
if (ret < 0) {
dev_err(priv->dev, "error attaching irq (%d)\n", ret);
goto clean_ale_ret;
}
ndev->features |= NETIF_F_HW_VLAN_CTAG_FILTER;
ndev->netdev_ops = &cpsw_netdev_ops;
ndev->ethtool_ops = &cpsw_ethtool_ops;
netif_napi_add(ndev, &cpsw->napi_rx, cpsw_rx_poll, CPSW_POLL_WEIGHT);
netif_tx_napi_add(ndev, &cpsw->napi_tx, cpsw_tx_poll, CPSW_POLL_WEIGHT);
cpsw_split_res(ndev);
SET_NETDEV_DEV(ndev, &pdev->dev);
ret = register_netdev(ndev);
if (ret) {
dev_err(priv->dev, "error registering net device\n");
ret = -ENODEV;
goto clean_ale_ret;
}
cpsw_notice(priv, probe,
"initialized device (regs %pa, irq %d, pool size %d)\n",
&ss_res->start, ndev->irq, dma_params.descs_pool_size);
if (cpsw->data.dual_emac) {
ret = cpsw_probe_dual_emac(priv);
if (ret) {
cpsw_err(priv, probe, "error probe slave 2 emac interface\n");
goto clean_unregister_netdev_ret;
}
}
pm_runtime_put(&pdev->dev);
return 0;
clean_unregister_netdev_ret:
unregister_netdev(ndev);
clean_ale_ret:
cpsw_ale_destroy(cpsw->ale);
clean_dma_ret:
cpdma_ctlr_destroy(cpsw->dma);
clean_dt_ret:
cpsw_remove_dt(pdev);
pm_runtime_put_sync(&pdev->dev);
clean_runtime_disable_ret:
pm_runtime_disable(&pdev->dev);
clean_ndev_ret:
free_netdev(priv->ndev);
return ret;
}
static int cpsw_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
int ret;
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
pm_runtime_put_noidle(&pdev->dev);
return ret;
}
if (cpsw->data.dual_emac)
unregister_netdev(cpsw->slaves[1].ndev);
unregister_netdev(ndev);
cpts_release(cpsw->cpts);
cpsw_ale_destroy(cpsw->ale);
cpdma_ctlr_destroy(cpsw->dma);
cpsw_remove_dt(pdev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (cpsw->data.dual_emac)
free_netdev(cpsw->slaves[1].ndev);
free_netdev(ndev);
return 0;
}
static int cpsw_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
if (cpsw->data.dual_emac) {
int i;
for (i = 0; i < cpsw->data.slaves; i++) {
if (netif_running(cpsw->slaves[i].ndev))
cpsw_ndo_stop(cpsw->slaves[i].ndev);
}
} else {
if (netif_running(ndev))
cpsw_ndo_stop(ndev);
}
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int cpsw_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct net_device *ndev = platform_get_drvdata(pdev);
struct cpsw_common *cpsw = ndev_to_cpsw(ndev);
pinctrl_pm_select_default_state(dev);
rtnl_lock();
if (cpsw->data.dual_emac) {
int i;
for (i = 0; i < cpsw->data.slaves; i++) {
if (netif_running(cpsw->slaves[i].ndev))
cpsw_ndo_open(cpsw->slaves[i].ndev);
}
} else {
if (netif_running(ndev))
cpsw_ndo_open(ndev);
}
rtnl_unlock();
return 0;
}
