static inline unsigned int xgbe_tx_avail_desc(struct xgbe_ring *ring)
{
return (ring->rdesc_count - (ring->cur - ring->dirty));
}
static int xgbe_calc_rx_buf_size(struct net_device *netdev, unsigned int mtu)
{
unsigned int rx_buf_size;
if (mtu > XGMAC_JUMBO_PACKET_MTU) {
netdev_alert(netdev, "MTU exceeds maximum supported value\n");
return -EINVAL;
}
rx_buf_size = mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
if (rx_buf_size < RX_MIN_BUF_SIZE)
rx_buf_size = RX_MIN_BUF_SIZE;
rx_buf_size = (rx_buf_size + RX_BUF_ALIGN - 1) & ~(RX_BUF_ALIGN - 1);
return rx_buf_size;
}
static void xgbe_enable_rx_tx_ints(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (channel->tx_ring)
hw_if->enable_int(channel,
XGMAC_INT_DMA_CH_SR_TI);
if (channel->rx_ring)
hw_if->enable_int(channel,
XGMAC_INT_DMA_CH_SR_RI);
}
}
static void xgbe_disable_rx_tx_ints(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_channel *channel;
unsigned int i;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (channel->tx_ring)
hw_if->disable_int(channel,
XGMAC_INT_DMA_CH_SR_TI);
if (channel->rx_ring)
hw_if->disable_int(channel,
XGMAC_INT_DMA_CH_SR_RI);
}
}
static irqreturn_t xgbe_isr(int irq, void *data)
{
struct xgbe_prv_data *pdata = data;
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_channel *channel;
unsigned int dma_isr, dma_ch_isr;
unsigned int mac_isr;
unsigned int i;
dma_isr = XGMAC_IOREAD(pdata, DMA_ISR);
if (!dma_isr)
goto isr_done;
DBGPR("-->xgbe_isr\n");
DBGPR(" DMA_ISR = %08x\n", dma_isr);
DBGPR(" DMA_DS0 = %08x\n", XGMAC_IOREAD(pdata, DMA_DSR0));
DBGPR(" DMA_DS1 = %08x\n", XGMAC_IOREAD(pdata, DMA_DSR1));
for (i = 0; i < pdata->channel_count; i++) {
if (!(dma_isr & (1 << i)))
continue;
channel = pdata->channel + i;
dma_ch_isr = XGMAC_DMA_IOREAD(channel, DMA_CH_SR);
DBGPR(" DMA_CH%u_ISR = %08x\n", i, dma_ch_isr);
if (XGMAC_GET_BITS(dma_ch_isr, DMA_CH_SR, TI) ||
XGMAC_GET_BITS(dma_ch_isr, DMA_CH_SR, RI)) {
if (napi_schedule_prep(&pdata->napi)) {
xgbe_disable_rx_tx_ints(pdata);
__napi_schedule(&pdata->napi);
}
}
if (XGMAC_GET_BITS(dma_ch_isr, DMA_CH_SR, FBE))
schedule_work(&pdata->restart_work);
XGMAC_DMA_IOWRITE(channel, DMA_CH_SR, dma_ch_isr);
}
if (XGMAC_GET_BITS(dma_isr, DMA_ISR, MACIS)) {
mac_isr = XGMAC_IOREAD(pdata, MAC_ISR);
if (XGMAC_GET_BITS(mac_isr, MAC_ISR, MMCTXIS))
hw_if->tx_mmc_int(pdata);
if (XGMAC_GET_BITS(mac_isr, MAC_ISR, MMCRXIS))
hw_if->rx_mmc_int(pdata);
}
DBGPR(" DMA_ISR = %08x\n", XGMAC_IOREAD(pdata, DMA_ISR));
DBGPR("<--xgbe_isr\n");
isr_done:
return IRQ_HANDLED;
}
static enum hrtimer_restart xgbe_tx_timer(struct hrtimer *timer)
{
struct xgbe_channel *channel = container_of(timer,
struct xgbe_channel,
tx_timer);
struct xgbe_ring *ring = channel->tx_ring;
struct xgbe_prv_data *pdata = channel->pdata;
unsigned long flags;
DBGPR("-->xgbe_tx_timer\n");
spin_lock_irqsave(&ring->lock, flags);
if (napi_schedule_prep(&pdata->napi)) {
xgbe_disable_rx_tx_ints(pdata);
__napi_schedule(&pdata->napi);
}
channel->tx_timer_active = 0;
spin_unlock_irqrestore(&ring->lock, flags);
DBGPR("<--xgbe_tx_timer\n");
return HRTIMER_NORESTART;
}
static void xgbe_init_tx_timers(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
DBGPR("-->xgbe_init_tx_timers\n");
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
DBGPR(" %s adding tx timer\n", channel->name);
hrtimer_init(&channel->tx_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
channel->tx_timer.function = xgbe_tx_timer;
}
DBGPR("<--xgbe_init_tx_timers\n");
}
static void xgbe_stop_tx_timers(struct xgbe_prv_data *pdata)
{
struct xgbe_channel *channel;
unsigned int i;
DBGPR("-->xgbe_stop_tx_timers\n");
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
if (!channel->tx_ring)
break;
DBGPR(" %s deleting tx timer\n", channel->name);
channel->tx_timer_active = 0;
hrtimer_cancel(&channel->tx_timer);
}
DBGPR("<--xgbe_stop_tx_timers\n");
}
void xgbe_get_all_hw_features(struct xgbe_prv_data *pdata)
{
unsigned int mac_hfr0, mac_hfr1, mac_hfr2;
struct xgbe_hw_features *hw_feat = &pdata->hw_feat;
DBGPR("-->xgbe_get_all_hw_features\n");
mac_hfr0 = XGMAC_IOREAD(pdata, MAC_HWF0R);
mac_hfr1 = XGMAC_IOREAD(pdata, MAC_HWF1R);
mac_hfr2 = XGMAC_IOREAD(pdata, MAC_HWF2R);
memset(hw_feat, 0, sizeof(*hw_feat));
hw_feat->gmii = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, GMIISEL);
hw_feat->vlhash = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, VLHASH);
hw_feat->sma = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, SMASEL);
hw_feat->rwk = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, RWKSEL);
hw_feat->mgk = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, MGKSEL);
hw_feat->mmc = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, MMCSEL);
hw_feat->aoe = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, ARPOFFSEL);
hw_feat->ts = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, TSSEL);
hw_feat->eee = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, EEESEL);
hw_feat->tx_coe = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, TXCOESEL);
hw_feat->rx_coe = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, RXCOESEL);
hw_feat->addn_mac = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R,
ADDMACADRSEL);
hw_feat->ts_src = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, TSSTSSEL);
hw_feat->sa_vlan_ins = XGMAC_GET_BITS(mac_hfr0, MAC_HWF0R, SAVLANINS);
hw_feat->rx_fifo_size = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R,
RXFIFOSIZE);
hw_feat->tx_fifo_size = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R,
TXFIFOSIZE);
hw_feat->dcb = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R, DCBEN);
hw_feat->sph = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R, SPHEN);
hw_feat->tso = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R, TSOEN);
hw_feat->dma_debug = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R, DBGMEMA);
hw_feat->hash_table_size = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R,
HASHTBLSZ);
hw_feat->l3l4_filter_num = XGMAC_GET_BITS(mac_hfr1, MAC_HWF1R,
L3L4FNUM);
hw_feat->rx_q_cnt = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, RXQCNT);
hw_feat->tx_q_cnt = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, TXQCNT);
hw_feat->rx_ch_cnt = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, RXCHCNT);
hw_feat->tx_ch_cnt = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, TXCHCNT);
hw_feat->pps_out_num = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, PPSOUTNUM);
hw_feat->aux_snap_num = XGMAC_GET_BITS(mac_hfr2, MAC_HWF2R, AUXSNAPNUM);
hw_feat->rx_q_cnt++;
hw_feat->tx_q_cnt++;
hw_feat->rx_ch_cnt++;
hw_feat->tx_ch_cnt++;
DBGPR("<--xgbe_get_all_hw_features\n");
}
static void xgbe_napi_enable(struct xgbe_prv_data *pdata, unsigned int add)
{
if (add)
netif_napi_add(pdata->netdev, &pdata->napi, xgbe_poll,
NAPI_POLL_WEIGHT);
napi_enable(&pdata->napi);
}
static void xgbe_napi_disable(struct xgbe_prv_data *pdata)
{
napi_disable(&pdata->napi);
}
void xgbe_init_tx_coalesce(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
DBGPR("-->xgbe_init_tx_coalesce\n");
pdata->tx_usecs = XGMAC_INIT_DMA_TX_USECS;
pdata->tx_frames = XGMAC_INIT_DMA_TX_FRAMES;
hw_if->config_tx_coalesce(pdata);
DBGPR("<--xgbe_init_tx_coalesce\n");
}
void xgbe_init_rx_coalesce(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
DBGPR("-->xgbe_init_rx_coalesce\n");
pdata->rx_riwt = hw_if->usec_to_riwt(pdata, XGMAC_INIT_DMA_RX_USECS);
pdata->rx_frames = XGMAC_INIT_DMA_RX_FRAMES;
hw_if->config_rx_coalesce(pdata);
DBGPR("<--xgbe_init_rx_coalesce\n");
}
static void xgbe_free_tx_skbuff(struct xgbe_prv_data *pdata)
{
struct xgbe_desc_if *desc_if = &pdata->desc_if;
struct xgbe_channel *channel;
struct xgbe_ring *ring;
struct xgbe_ring_data *rdata;
unsigned int i, j;
DBGPR("-->xgbe_free_tx_skbuff\n");
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
ring = channel->tx_ring;
if (!ring)
break;
for (j = 0; j < ring->rdesc_count; j++) {
rdata = GET_DESC_DATA(ring, j);
desc_if->unmap_skb(pdata, rdata);
}
}
DBGPR("<--xgbe_free_tx_skbuff\n");
}
static void xgbe_free_rx_skbuff(struct xgbe_prv_data *pdata)
{
struct xgbe_desc_if *desc_if = &pdata->desc_if;
struct xgbe_channel *channel;
struct xgbe_ring *ring;
struct xgbe_ring_data *rdata;
unsigned int i, j;
DBGPR("-->xgbe_free_rx_skbuff\n");
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++) {
ring = channel->rx_ring;
if (!ring)
break;
for (j = 0; j < ring->rdesc_count; j++) {
rdata = GET_DESC_DATA(ring, j);
desc_if->unmap_skb(pdata, rdata);
}
}
DBGPR("<--xgbe_free_rx_skbuff\n");
}
int xgbe_powerdown(struct net_device *netdev, unsigned int caller)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned long flags;
DBGPR("-->xgbe_powerdown\n");
if (!netif_running(netdev) ||
(caller == XGMAC_IOCTL_CONTEXT && pdata->power_down)) {
netdev_alert(netdev, "Device is already powered down\n");
DBGPR("<--xgbe_powerdown\n");
return -EINVAL;
}
phy_stop(pdata->phydev);
spin_lock_irqsave(&pdata->lock, flags);
if (caller == XGMAC_DRIVER_CONTEXT)
netif_device_detach(netdev);
netif_tx_stop_all_queues(netdev);
xgbe_napi_disable(pdata);
hw_if->powerdown_tx(pdata);
hw_if->powerdown_rx(pdata);
pdata->power_down = 1;
spin_unlock_irqrestore(&pdata->lock, flags);
DBGPR("<--xgbe_powerdown\n");
return 0;
}
int xgbe_powerup(struct net_device *netdev, unsigned int caller)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned long flags;
DBGPR("-->xgbe_powerup\n");
if (!netif_running(netdev) ||
(caller == XGMAC_IOCTL_CONTEXT && !pdata->power_down)) {
netdev_alert(netdev, "Device is already powered up\n");
DBGPR("<--xgbe_powerup\n");
return -EINVAL;
}
spin_lock_irqsave(&pdata->lock, flags);
pdata->power_down = 0;
phy_start(pdata->phydev);
hw_if->powerup_tx(pdata);
hw_if->powerup_rx(pdata);
if (caller == XGMAC_DRIVER_CONTEXT)
netif_device_attach(netdev);
xgbe_napi_enable(pdata, 0);
netif_tx_start_all_queues(netdev);
spin_unlock_irqrestore(&pdata->lock, flags);
DBGPR("<--xgbe_powerup\n");
return 0;
}
static int xgbe_start(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct net_device *netdev = pdata->netdev;
DBGPR("-->xgbe_start\n");
xgbe_set_rx_mode(netdev);
hw_if->init(pdata);
phy_start(pdata->phydev);
hw_if->enable_tx(pdata);
hw_if->enable_rx(pdata);
xgbe_init_tx_timers(pdata);
xgbe_napi_enable(pdata, 1);
netif_tx_start_all_queues(netdev);
DBGPR("<--xgbe_start\n");
return 0;
}
static void xgbe_stop(struct xgbe_prv_data *pdata)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct net_device *netdev = pdata->netdev;
DBGPR("-->xgbe_stop\n");
phy_stop(pdata->phydev);
netif_tx_stop_all_queues(netdev);
xgbe_napi_disable(pdata);
xgbe_stop_tx_timers(pdata);
hw_if->disable_tx(pdata);
hw_if->disable_rx(pdata);
DBGPR("<--xgbe_stop\n");
}
static void xgbe_restart_dev(struct xgbe_prv_data *pdata, unsigned int reset)
{
struct xgbe_hw_if *hw_if = &pdata->hw_if;
DBGPR("-->xgbe_restart_dev\n");
if (!netif_running(pdata->netdev))
return;
xgbe_stop(pdata);
synchronize_irq(pdata->irq_number);
xgbe_free_tx_skbuff(pdata);
xgbe_free_rx_skbuff(pdata);
if (reset)
hw_if->exit(pdata);
xgbe_start(pdata);
DBGPR("<--xgbe_restart_dev\n");
}
static void xgbe_restart(struct work_struct *work)
{
struct xgbe_prv_data *pdata = container_of(work,
struct xgbe_prv_data,
restart_work);
rtnl_lock();
xgbe_restart_dev(pdata, 1);
rtnl_unlock();
}
static void xgbe_prep_vlan(struct sk_buff *skb, struct xgbe_packet_data *packet)
{
if (vlan_tx_tag_present(skb))
packet->vlan_ctag = vlan_tx_tag_get(skb);
}
static int xgbe_prep_tso(struct sk_buff *skb, struct xgbe_packet_data *packet)
{
int ret;
if (!XGMAC_GET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
TSO_ENABLE))
return 0;
ret = skb_cow_head(skb, 0);
if (ret)
return ret;
packet->header_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
packet->tcp_header_len = tcp_hdrlen(skb);
packet->tcp_payload_len = skb->len - packet->header_len;
packet->mss = skb_shinfo(skb)->gso_size;
DBGPR(" packet->header_len=%u\n", packet->header_len);
DBGPR(" packet->tcp_header_len=%u, packet->tcp_payload_len=%u\n",
packet->tcp_header_len, packet->tcp_payload_len);
DBGPR(" packet->mss=%u\n", packet->mss);
return 0;
}
static int xgbe_is_tso(struct sk_buff *skb)
{
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
DBGPR(" TSO packet to be processed\n");
return 1;
}
static void xgbe_packet_info(struct xgbe_ring *ring, struct sk_buff *skb,
struct xgbe_packet_data *packet)
{
struct skb_frag_struct *frag;
unsigned int context_desc;
unsigned int len;
unsigned int i;
context_desc = 0;
packet->rdesc_count = 0;
if (xgbe_is_tso(skb)) {
if (skb_shinfo(skb)->gso_size != ring->tx.cur_mss) {
context_desc = 1;
packet->rdesc_count++;
}
packet->rdesc_count++;
XGMAC_SET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
TSO_ENABLE, 1);
XGMAC_SET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
CSUM_ENABLE, 1);
} else if (skb->ip_summed == CHECKSUM_PARTIAL)
XGMAC_SET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
CSUM_ENABLE, 1);
if (vlan_tx_tag_present(skb)) {
if (vlan_tx_tag_get(skb) != ring->tx.cur_vlan_ctag)
if (!context_desc) {
context_desc = 1;
packet->rdesc_count++;
}
XGMAC_SET_BITS(packet->attributes, TX_PACKET_ATTRIBUTES,
VLAN_CTAG, 1);
}
for (len = skb_headlen(skb); len;) {
packet->rdesc_count++;
len -= min_t(unsigned int, len, TX_MAX_BUF_SIZE);
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
frag = &skb_shinfo(skb)->frags[i];
for (len = skb_frag_size(frag); len; ) {
packet->rdesc_count++;
len -= min_t(unsigned int, len, TX_MAX_BUF_SIZE);
}
}
}
static int xgbe_open(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_desc_if *desc_if = &pdata->desc_if;
int ret;
DBGPR("-->xgbe_open\n");
ret = clk_prepare_enable(pdata->sysclock);
if (ret) {
netdev_alert(netdev, "clk_prepare_enable failed\n");
return ret;
}
ret = xgbe_calc_rx_buf_size(netdev, netdev->mtu);
if (ret < 0)
goto err_clk;
pdata->rx_buf_size = ret;
ret = desc_if->alloc_ring_resources(pdata);
if (ret)
goto err_clk;
INIT_WORK(&pdata->restart_work, xgbe_restart);
ret = devm_request_irq(pdata->dev, netdev->irq, xgbe_isr, 0,
netdev->name, pdata);
if (ret) {
netdev_alert(netdev, "error requesting irq %d\n",
pdata->irq_number);
goto err_irq;
}
pdata->irq_number = netdev->irq;
ret = xgbe_start(pdata);
if (ret)
goto err_start;
DBGPR("<--xgbe_open\n");
return 0;
err_start:
hw_if->exit(pdata);
devm_free_irq(pdata->dev, pdata->irq_number, pdata);
pdata->irq_number = 0;
err_irq:
desc_if->free_ring_resources(pdata);
err_clk:
clk_disable_unprepare(pdata->sysclock);
return ret;
}
static int xgbe_close(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_desc_if *desc_if = &pdata->desc_if;
DBGPR("-->xgbe_close\n");
xgbe_stop(pdata);
hw_if->exit(pdata);
desc_if->free_ring_resources(pdata);
if (pdata->irq_number != 0) {
devm_free_irq(pdata->dev, pdata->irq_number, pdata);
pdata->irq_number = 0;
}
clk_disable_unprepare(pdata->sysclock);
DBGPR("<--xgbe_close\n");
return 0;
}
static int xgbe_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_desc_if *desc_if = &pdata->desc_if;
struct xgbe_channel *channel;
struct xgbe_ring *ring;
struct xgbe_packet_data *packet;
unsigned long flags;
int ret;
DBGPR("-->xgbe_xmit: skb->len = %d\n", skb->len);
channel = pdata->channel + skb->queue_mapping;
ring = channel->tx_ring;
packet = &ring->packet_data;
ret = NETDEV_TX_OK;
spin_lock_irqsave(&ring->lock, flags);
if (skb->len == 0) {
netdev_err(netdev, "empty skb received from stack\n");
dev_kfree_skb_any(skb);
goto tx_netdev_return;
}
memset(packet, 0, sizeof(*packet));
xgbe_packet_info(ring, skb, packet);
if (packet->rdesc_count > xgbe_tx_avail_desc(ring)) {
DBGPR(" Tx queue stopped, not enough descriptors available\n");
netif_stop_subqueue(netdev, channel->queue_index);
ring->tx.queue_stopped = 1;
ret = NETDEV_TX_BUSY;
goto tx_netdev_return;
}
ret = xgbe_prep_tso(skb, packet);
if (ret) {
netdev_err(netdev, "error processing TSO packet\n");
dev_kfree_skb_any(skb);
goto tx_netdev_return;
}
xgbe_prep_vlan(skb, packet);
if (!desc_if->map_tx_skb(channel, skb)) {
dev_kfree_skb_any(skb);
goto tx_netdev_return;
}
hw_if->pre_xmit(channel);
#ifdef XGMAC_ENABLE_TX_PKT_DUMP
xgbe_print_pkt(netdev, skb, true);
#endif
tx_netdev_return:
spin_unlock_irqrestore(&ring->lock, flags);
DBGPR("<--xgbe_xmit\n");
return ret;
}
static void xgbe_set_rx_mode(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int pr_mode, am_mode;
DBGPR("-->xgbe_set_rx_mode\n");
pr_mode = ((netdev->flags & IFF_PROMISC) != 0);
am_mode = ((netdev->flags & IFF_ALLMULTI) != 0);
if (netdev_uc_count(netdev) > pdata->hw_feat.addn_mac)
pr_mode = 1;
if (netdev_mc_count(netdev) > pdata->hw_feat.addn_mac)
am_mode = 1;
if ((netdev_uc_count(netdev) + netdev_mc_count(netdev)) >
pdata->hw_feat.addn_mac)
pr_mode = 1;
hw_if->set_promiscuous_mode(pdata, pr_mode);
hw_if->set_all_multicast_mode(pdata, am_mode);
if (!pr_mode)
hw_if->set_addn_mac_addrs(pdata, am_mode);
DBGPR("<--xgbe_set_rx_mode\n");
}
static int xgbe_set_mac_address(struct net_device *netdev, void *addr)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct sockaddr *saddr = addr;
DBGPR("-->xgbe_set_mac_address\n");
if (!is_valid_ether_addr(saddr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, saddr->sa_data, netdev->addr_len);
hw_if->set_mac_address(pdata, netdev->dev_addr);
DBGPR("<--xgbe_set_mac_address\n");
return 0;
}
static int xgbe_change_mtu(struct net_device *netdev, int mtu)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
int ret;
DBGPR("-->xgbe_change_mtu\n");
ret = xgbe_calc_rx_buf_size(netdev, mtu);
if (ret < 0)
return ret;
pdata->rx_buf_size = ret;
netdev->mtu = mtu;
xgbe_restart_dev(pdata, 0);
DBGPR("<--xgbe_change_mtu\n");
return 0;
}
static struct rtnl_link_stats64 *xgbe_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *s)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_mmc_stats *pstats = &pdata->mmc_stats;
DBGPR("-->%s\n", __func__);
pdata->hw_if.read_mmc_stats(pdata);
s->rx_packets = pstats->rxframecount_gb;
s->rx_bytes = pstats->rxoctetcount_gb;
s->rx_errors = pstats->rxframecount_gb -
pstats->rxbroadcastframes_g -
pstats->rxmulticastframes_g -
pstats->rxunicastframes_g;
s->multicast = pstats->rxmulticastframes_g;
s->rx_length_errors = pstats->rxlengtherror;
s->rx_crc_errors = pstats->rxcrcerror;
s->rx_fifo_errors = pstats->rxfifooverflow;
s->tx_packets = pstats->txframecount_gb;
s->tx_bytes = pstats->txoctetcount_gb;
s->tx_errors = pstats->txframecount_gb - pstats->txframecount_g;
s->tx_dropped = netdev->stats.tx_dropped;
DBGPR("<--%s\n", __func__);
return s;
}
static void xgbe_poll_controller(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
DBGPR("-->xgbe_poll_controller\n");
disable_irq(pdata->irq_number);
xgbe_isr(pdata->irq_number, pdata);
enable_irq(pdata->irq_number);
DBGPR("<--xgbe_poll_controller\n");
}
static int xgbe_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int rxcsum_enabled, rxvlan_enabled;
rxcsum_enabled = !!(pdata->netdev_features & NETIF_F_RXCSUM);
rxvlan_enabled = !!(pdata->netdev_features & NETIF_F_HW_VLAN_CTAG_RX);
if ((features & NETIF_F_RXCSUM) && !rxcsum_enabled) {
hw_if->enable_rx_csum(pdata);
netdev_alert(netdev, "state change - rxcsum enabled\n");
} else if (!(features & NETIF_F_RXCSUM) && rxcsum_enabled) {
hw_if->disable_rx_csum(pdata);
netdev_alert(netdev, "state change - rxcsum disabled\n");
}
if ((features & NETIF_F_HW_VLAN_CTAG_RX) && !rxvlan_enabled) {
hw_if->enable_rx_vlan_stripping(pdata);
netdev_alert(netdev, "state change - rxvlan enabled\n");
} else if (!(features & NETIF_F_HW_VLAN_CTAG_RX) && rxvlan_enabled) {
hw_if->disable_rx_vlan_stripping(pdata);
netdev_alert(netdev, "state change - rxvlan disabled\n");
}
pdata->netdev_features = features;
DBGPR("<--xgbe_set_features\n");
return 0;
}
struct net_device_ops *xgbe_get_netdev_ops(void)
{
return (struct net_device_ops *)&xgbe_netdev_ops;
}
static int xgbe_tx_poll(struct xgbe_channel *channel)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_desc_if *desc_if = &pdata->desc_if;
struct xgbe_ring *ring = channel->tx_ring;
struct xgbe_ring_data *rdata;
struct xgbe_ring_desc *rdesc;
struct net_device *netdev = pdata->netdev;
unsigned long flags;
int processed = 0;
DBGPR("-->xgbe_tx_poll\n");
if (!ring)
return 0;
spin_lock_irqsave(&ring->lock, flags);
while ((processed < TX_DESC_MAX_PROC) && (ring->dirty < ring->cur)) {
rdata = GET_DESC_DATA(ring, ring->dirty);
rdesc = rdata->rdesc;
if (!hw_if->tx_complete(rdesc))
break;
#ifdef XGMAC_ENABLE_TX_DESC_DUMP
xgbe_dump_tx_desc(ring, ring->dirty, 1, 0);
#endif
desc_if->unmap_skb(pdata, rdata);
hw_if->tx_desc_reset(rdata);
processed++;
ring->dirty++;
}
if ((ring->tx.queue_stopped == 1) &&
(xgbe_tx_avail_desc(ring) > TX_DESC_MIN_FREE)) {
ring->tx.queue_stopped = 0;
netif_wake_subqueue(netdev, channel->queue_index);
}
DBGPR("<--xgbe_tx_poll: processed=%d\n", processed);
spin_unlock_irqrestore(&ring->lock, flags);
return processed;
}
static int xgbe_rx_poll(struct xgbe_channel *channel, int budget)
{
struct xgbe_prv_data *pdata = channel->pdata;
struct xgbe_hw_if *hw_if = &pdata->hw_if;
struct xgbe_desc_if *desc_if = &pdata->desc_if;
struct xgbe_ring *ring = channel->rx_ring;
struct xgbe_ring_data *rdata;
struct xgbe_packet_data *packet;
struct net_device *netdev = pdata->netdev;
struct sk_buff *skb;
unsigned int incomplete, error;
unsigned int cur_len, put_len, max_len;
int received = 0;
DBGPR("-->xgbe_rx_poll: budget=%d\n", budget);
if (!ring)
return 0;
packet = &ring->packet_data;
while (received < budget) {
DBGPR(" cur = %d\n", ring->cur);
memset(packet, 0, sizeof(*packet));
skb = NULL;
error = 0;
cur_len = 0;
read_again:
rdata = GET_DESC_DATA(ring, ring->cur);
if (hw_if->dev_read(channel))
break;
received++;
ring->cur++;
ring->dirty++;
dma_unmap_single(pdata->dev, rdata->skb_dma,
rdata->skb_dma_len, DMA_FROM_DEVICE);
rdata->skb_dma = 0;
incomplete = XGMAC_GET_BITS(packet->attributes,
RX_PACKET_ATTRIBUTES,
INCOMPLETE);
if (incomplete && error)
goto read_again;
if (error || packet->errors) {
if (packet->errors)
DBGPR("Error in received packet\n");
dev_kfree_skb(skb);
continue;
}
put_len = rdata->len - cur_len;
if (skb) {
if (pskb_expand_head(skb, 0, put_len, GFP_ATOMIC)) {
DBGPR("pskb_expand_head error\n");
if (incomplete) {
error = 1;
goto read_again;
}
dev_kfree_skb(skb);
continue;
}
memcpy(skb_tail_pointer(skb), rdata->skb->data,
put_len);
} else {
skb = rdata->skb;
rdata->skb = NULL;
}
skb_put(skb, put_len);
cur_len += put_len;
if (incomplete)
goto read_again;
max_len = netdev->mtu + ETH_HLEN;
if (!(netdev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
(skb->protocol == htons(ETH_P_8021Q)))
max_len += VLAN_HLEN;
if (skb->len > max_len) {
DBGPR("packet length exceeds configured MTU\n");
dev_kfree_skb(skb);
continue;
}
#ifdef XGMAC_ENABLE_RX_PKT_DUMP
xgbe_print_pkt(netdev, skb, false);
#endif
skb_checksum_none_assert(skb);
if (XGMAC_GET_BITS(packet->attributes,
RX_PACKET_ATTRIBUTES, CSUM_DONE))
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (XGMAC_GET_BITS(packet->attributes,
RX_PACKET_ATTRIBUTES, VLAN_CTAG))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q),
packet->vlan_ctag);
skb->dev = netdev;
skb->protocol = eth_type_trans(skb, netdev);
skb_record_rx_queue(skb, channel->queue_index);
skb_mark_napi_id(skb, &pdata->napi);
netdev->last_rx = jiffies;
napi_gro_receive(&pdata->napi, skb);
}
if (received) {
desc_if->realloc_skb(channel);
rdata = GET_DESC_DATA(ring, ring->rx.realloc_index - 1);
XGMAC_DMA_IOWRITE(channel, DMA_CH_RDTR_LO,
lower_32_bits(rdata->rdesc_dma));
}
DBGPR("<--xgbe_rx_poll: received = %d\n", received);
return received;
}
static int xgbe_poll(struct napi_struct *napi, int budget)
{
struct xgbe_prv_data *pdata = container_of(napi, struct xgbe_prv_data,
napi);
struct xgbe_channel *channel;
int processed;
unsigned int i;
DBGPR("-->xgbe_poll: budget=%d\n", budget);
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++)
xgbe_tx_poll(channel);
processed = 0;
channel = pdata->channel;
for (i = 0; i < pdata->channel_count; i++, channel++)
processed += xgbe_rx_poll(channel, budget - processed);
if (processed < budget) {
napi_complete(napi);
xgbe_enable_rx_tx_ints(pdata);
}
DBGPR("<--xgbe_poll: received = %d\n", processed);
return processed;
}
void xgbe_dump_tx_desc(struct xgbe_ring *ring, unsigned int idx,
unsigned int count, unsigned int flag)
{
struct xgbe_ring_data *rdata;
struct xgbe_ring_desc *rdesc;
while (count--) {
rdata = GET_DESC_DATA(ring, idx);
rdesc = rdata->rdesc;
DBGPR("TX_NORMAL_DESC[%d %s] = %08x:%08x:%08x:%08x\n", idx,
(flag == 1) ? "QUEUED FOR TX" : "TX BY DEVICE",
le32_to_cpu(rdesc->desc0), le32_to_cpu(rdesc->desc1),
le32_to_cpu(rdesc->desc2), le32_to_cpu(rdesc->desc3));
idx++;
}
}
void xgbe_dump_rx_desc(struct xgbe_ring *ring, struct xgbe_ring_desc *desc,
unsigned int idx)
{
DBGPR("RX_NORMAL_DESC[%d RX BY DEVICE] = %08x:%08x:%08x:%08x\n", idx,
le32_to_cpu(desc->desc0), le32_to_cpu(desc->desc1),
le32_to_cpu(desc->desc2), le32_to_cpu(desc->desc3));
}
void xgbe_print_pkt(struct net_device *netdev, struct sk_buff *skb, bool tx_rx)
{
struct ethhdr *eth = (struct ethhdr *)skb->data;
unsigned char *buf = skb->data;
unsigned char buffer[128];
unsigned int i, j;
netdev_alert(netdev, "\n************** SKB dump ****************\n");
netdev_alert(netdev, "%s packet of %d bytes\n",
(tx_rx ? "TX" : "RX"), skb->len);
netdev_alert(netdev, "Dst MAC addr: %pM\n", eth->h_dest);
netdev_alert(netdev, "Src MAC addr: %pM\n", eth->h_source);
netdev_alert(netdev, "Protocol: 0x%04hx\n", ntohs(eth->h_proto));
for (i = 0, j = 0; i < skb->len;) {
j += snprintf(buffer + j, sizeof(buffer) - j, "%02hhx",
buf[i++]);
if ((i % 32) == 0) {
netdev_alert(netdev, " 0x%04x: %s\n", i - 32, buffer);
j = 0;
} else if ((i % 16) == 0) {
buffer[j++] = ' ';
buffer[j++] = ' ';
} else if ((i % 4) == 0) {
buffer[j++] = ' ';
}
}
if (i % 32)
netdev_alert(netdev, " 0x%04x: %s\n", i - (i % 32), buffer);
netdev_alert(netdev, "\n************** SKB dump ****************\n");
}
