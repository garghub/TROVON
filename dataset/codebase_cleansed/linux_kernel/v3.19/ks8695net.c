static inline u32
ks8695_readreg(struct ks8695_priv *ksp, int reg)
{
return readl(ksp->io_regs + reg);
}
static inline void
ks8695_writereg(struct ks8695_priv *ksp, int reg, u32 value)
{
writel(value, ksp->io_regs + reg);
}
static const char *
ks8695_port_type(struct ks8695_priv *ksp)
{
switch (ksp->dtype) {
case KS8695_DTYPE_LAN:
return "LAN";
case KS8695_DTYPE_WAN:
return "WAN";
case KS8695_DTYPE_HPNA:
return "HPNA";
}
return "UNKNOWN";
}
static void
ks8695_update_mac(struct ks8695_priv *ksp)
{
struct net_device *ndev = ksp->ndev;
u32 machigh, maclow;
maclow = ((ndev->dev_addr[2] << 24) | (ndev->dev_addr[3] << 16) |
(ndev->dev_addr[4] << 8) | (ndev->dev_addr[5] << 0));
machigh = ((ndev->dev_addr[0] << 8) | (ndev->dev_addr[1] << 0));
ks8695_writereg(ksp, KS8695_MAL, maclow);
ks8695_writereg(ksp, KS8695_MAH, machigh);
}
static void
ks8695_refill_rxbuffers(struct ks8695_priv *ksp)
{
int buff_n;
for (buff_n = 0; buff_n < MAX_RX_DESC; ++buff_n) {
if (!ksp->rx_buffers[buff_n].skb) {
struct sk_buff *skb =
netdev_alloc_skb(ksp->ndev, MAX_RXBUF_SIZE);
dma_addr_t mapping;
ksp->rx_buffers[buff_n].skb = skb;
if (skb == NULL) {
break;
}
mapping = dma_map_single(ksp->dev, skb->data,
MAX_RXBUF_SIZE,
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(ksp->dev, mapping))) {
dev_kfree_skb_irq(skb);
ksp->rx_buffers[buff_n].skb = NULL;
break;
}
ksp->rx_buffers[buff_n].dma_ptr = mapping;
ksp->rx_buffers[buff_n].length = MAX_RXBUF_SIZE;
ksp->rx_ring[buff_n].data_ptr = cpu_to_le32(mapping);
ksp->rx_ring[buff_n].length =
cpu_to_le32(MAX_RXBUF_SIZE);
wmb();
ksp->rx_ring[buff_n].status = cpu_to_le32(RDES_OWN);
}
}
}
static void
ks8695_init_partial_multicast(struct ks8695_priv *ksp,
struct net_device *ndev)
{
u32 low, high;
int i;
struct netdev_hw_addr *ha;
i = 0;
netdev_for_each_mc_addr(ha, ndev) {
BUG_ON(i == KS8695_NR_ADDRESSES);
low = (ha->addr[2] << 24) | (ha->addr[3] << 16) |
(ha->addr[4] << 8) | (ha->addr[5]);
high = (ha->addr[0] << 8) | (ha->addr[1]);
ks8695_writereg(ksp, KS8695_AAL_(i), low);
ks8695_writereg(ksp, KS8695_AAH_(i), AAH_E | high);
i++;
}
for (; i < KS8695_NR_ADDRESSES; i++) {
ks8695_writereg(ksp, KS8695_AAL_(i), 0);
ks8695_writereg(ksp, KS8695_AAH_(i), 0);
}
}
static irqreturn_t
ks8695_tx_irq(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct ks8695_priv *ksp = netdev_priv(ndev);
int buff_n;
for (buff_n = 0; buff_n < MAX_TX_DESC; ++buff_n) {
if (ksp->tx_buffers[buff_n].skb &&
!(ksp->tx_ring[buff_n].owner & cpu_to_le32(TDES_OWN))) {
rmb();
ndev->stats.tx_packets++;
ndev->stats.tx_bytes += ksp->tx_buffers[buff_n].length;
ksp->tx_ring[buff_n].data_ptr = 0;
dma_unmap_single(ksp->dev,
ksp->tx_buffers[buff_n].dma_ptr,
ksp->tx_buffers[buff_n].length,
DMA_TO_DEVICE);
dev_kfree_skb_irq(ksp->tx_buffers[buff_n].skb);
ksp->tx_buffers[buff_n].skb = NULL;
ksp->tx_ring_used--;
}
}
netif_wake_queue(ndev);
return IRQ_HANDLED;
}
static inline u32 ks8695_get_rx_enable_bit(struct ks8695_priv *ksp)
{
return ksp->rx_irq;
}
static irqreturn_t
ks8695_rx_irq(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct ks8695_priv *ksp = netdev_priv(ndev);
spin_lock(&ksp->rx_lock);
if (napi_schedule_prep(&ksp->napi)) {
unsigned long status = readl(KS8695_IRQ_VA + KS8695_INTEN);
unsigned long mask_bit = 1 << ks8695_get_rx_enable_bit(ksp);
status &= ~mask_bit;
writel(status , KS8695_IRQ_VA + KS8695_INTEN);
__napi_schedule(&ksp->napi);
}
spin_unlock(&ksp->rx_lock);
return IRQ_HANDLED;
}
static int ks8695_rx(struct ks8695_priv *ksp, int budget)
{
struct net_device *ndev = ksp->ndev;
struct sk_buff *skb;
int buff_n;
u32 flags;
int pktlen;
int received = 0;
buff_n = ksp->next_rx_desc_read;
while (received < budget
&& ksp->rx_buffers[buff_n].skb
&& (!(ksp->rx_ring[buff_n].status &
cpu_to_le32(RDES_OWN)))) {
rmb();
flags = le32_to_cpu(ksp->rx_ring[buff_n].status);
if ((flags & (RDES_FS | RDES_LS)) !=
(RDES_FS | RDES_LS)) {
goto rx_failure;
}
if (flags & (RDES_ES | RDES_RE)) {
ndev->stats.rx_errors++;
if (flags & RDES_TL)
ndev->stats.rx_length_errors++;
if (flags & RDES_RF)
ndev->stats.rx_length_errors++;
if (flags & RDES_CE)
ndev->stats.rx_crc_errors++;
if (flags & RDES_RE)
ndev->stats.rx_missed_errors++;
goto rx_failure;
}
pktlen = flags & RDES_FLEN;
pktlen -= 4;
skb = ksp->rx_buffers[buff_n].skb;
ksp->rx_buffers[buff_n].skb = NULL;
ksp->rx_ring[buff_n].data_ptr = 0;
dma_unmap_single(ksp->dev,
ksp->rx_buffers[buff_n].dma_ptr,
ksp->rx_buffers[buff_n].length,
DMA_FROM_DEVICE);
skb_put(skb, pktlen);
skb->protocol = eth_type_trans(skb, ndev);
netif_receive_skb(skb);
ndev->stats.rx_packets++;
ndev->stats.rx_bytes += pktlen;
goto rx_finished;
rx_failure:
ksp->rx_ring[buff_n].status = cpu_to_le32(RDES_OWN);
rx_finished:
received++;
buff_n = (buff_n + 1) & MAX_RX_DESC_MASK;
}
ksp->next_rx_desc_read = buff_n;
ks8695_refill_rxbuffers(ksp);
ks8695_writereg(ksp, KS8695_DRSC, 0);
return received;
}
static int ks8695_poll(struct napi_struct *napi, int budget)
{
struct ks8695_priv *ksp = container_of(napi, struct ks8695_priv, napi);
unsigned long work_done;
unsigned long isr = readl(KS8695_IRQ_VA + KS8695_INTEN);
unsigned long mask_bit = 1 << ks8695_get_rx_enable_bit(ksp);
work_done = ks8695_rx(ksp, budget);
if (work_done < budget) {
unsigned long flags;
spin_lock_irqsave(&ksp->rx_lock, flags);
__napi_complete(napi);
writel(isr | mask_bit, KS8695_IRQ_VA + KS8695_INTEN);
spin_unlock_irqrestore(&ksp->rx_lock, flags);
}
return work_done;
}
static irqreturn_t
ks8695_link_irq(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
if (ctrl & WMC_WLS) {
netif_carrier_on(ndev);
if (netif_msg_link(ksp))
dev_info(ksp->dev,
"%s: Link is now up (10%sMbps/%s-duplex)\n",
ndev->name,
(ctrl & WMC_WSS) ? "0" : "",
(ctrl & WMC_WDS) ? "Full" : "Half");
} else {
netif_carrier_off(ndev);
if (netif_msg_link(ksp))
dev_info(ksp->dev, "%s: Link is now down.\n",
ndev->name);
}
return IRQ_HANDLED;
}
static void
ks8695_reset(struct ks8695_priv *ksp)
{
int reset_timeout = watchdog;
ks8695_writereg(ksp, KS8695_DTXC, DTXC_TRST);
while (reset_timeout--) {
if (!(ks8695_readreg(ksp, KS8695_DTXC) & DTXC_TRST))
break;
msleep(1);
}
if (reset_timeout < 0) {
dev_crit(ksp->dev,
"Timeout waiting for DMA engines to reset\n");
}
msleep(10);
ks8695_writereg(ksp, KS8695_DRXC, DRXC_RU | DRXC_RB);
ks8695_writereg(ksp, KS8695_DTXC, DTXC_TEP | DTXC_TAC);
}
static void
ks8695_shutdown(struct ks8695_priv *ksp)
{
u32 ctrl;
int buff_n;
ctrl = ks8695_readreg(ksp, KS8695_DTXC);
ks8695_writereg(ksp, KS8695_DTXC, ctrl & ~DTXC_TE);
ctrl = ks8695_readreg(ksp, KS8695_DRXC);
ks8695_writereg(ksp, KS8695_DRXC, ctrl & ~DRXC_RE);
free_irq(ksp->rx_irq, ksp->ndev);
free_irq(ksp->tx_irq, ksp->ndev);
if (ksp->link_irq != -1)
free_irq(ksp->link_irq, ksp->ndev);
for (buff_n = 0; buff_n < MAX_TX_DESC; ++buff_n) {
if (ksp->tx_buffers[buff_n].skb) {
ksp->tx_ring[buff_n].owner = 0;
ksp->tx_ring[buff_n].status = 0;
ksp->tx_ring[buff_n].data_ptr = 0;
dma_unmap_single(ksp->dev,
ksp->tx_buffers[buff_n].dma_ptr,
ksp->tx_buffers[buff_n].length,
DMA_TO_DEVICE);
dev_kfree_skb_irq(ksp->tx_buffers[buff_n].skb);
ksp->tx_buffers[buff_n].skb = NULL;
}
}
for (buff_n = 0; buff_n < MAX_RX_DESC; ++buff_n) {
if (ksp->rx_buffers[buff_n].skb) {
ksp->rx_ring[buff_n].status = 0;
ksp->rx_ring[buff_n].data_ptr = 0;
dma_unmap_single(ksp->dev,
ksp->rx_buffers[buff_n].dma_ptr,
ksp->rx_buffers[buff_n].length,
DMA_FROM_DEVICE);
dev_kfree_skb_irq(ksp->rx_buffers[buff_n].skb);
ksp->rx_buffers[buff_n].skb = NULL;
}
}
}
static int
ks8695_setup_irq(int irq, const char *irq_name,
irq_handler_t handler, struct net_device *ndev)
{
int ret;
ret = request_irq(irq, handler, IRQF_SHARED, irq_name, ndev);
if (ret) {
dev_err(&ndev->dev, "failure to request IRQ %d\n", irq);
return ret;
}
return 0;
}
static int
ks8695_init_net(struct ks8695_priv *ksp)
{
int ret;
u32 ctrl;
ks8695_refill_rxbuffers(ksp);
ks8695_writereg(ksp, KS8695_RDLB, (u32) ksp->rx_ring_dma);
ks8695_writereg(ksp, KS8695_TDLB, (u32) ksp->tx_ring_dma);
ret = ks8695_setup_irq(ksp->rx_irq, ksp->rx_irq_name,
ks8695_rx_irq, ksp->ndev);
if (ret)
return ret;
ret = ks8695_setup_irq(ksp->tx_irq, ksp->tx_irq_name,
ks8695_tx_irq, ksp->ndev);
if (ret)
return ret;
if (ksp->link_irq != -1) {
ret = ks8695_setup_irq(ksp->link_irq, ksp->link_irq_name,
ks8695_link_irq, ksp->ndev);
if (ret)
return ret;
}
ksp->next_rx_desc_read = 0;
ksp->tx_ring_next_slot = 0;
ksp->tx_ring_used = 0;
ctrl = ks8695_readreg(ksp, KS8695_DTXC);
ks8695_writereg(ksp, KS8695_DTXC, ctrl | DTXC_TE);
ctrl = ks8695_readreg(ksp, KS8695_DRXC);
ks8695_writereg(ksp, KS8695_DRXC, ctrl | DRXC_RE);
ks8695_writereg(ksp, KS8695_DRSC, 0);
return 0;
}
static void
ks8695_release_device(struct ks8695_priv *ksp)
{
iounmap(ksp->io_regs);
if (ksp->phyiface_regs)
iounmap(ksp->phyiface_regs);
release_resource(ksp->regs_req);
kfree(ksp->regs_req);
if (ksp->phyiface_req) {
release_resource(ksp->phyiface_req);
kfree(ksp->phyiface_req);
}
dma_free_coherent(ksp->dev, RING_DMA_SIZE,
ksp->ring_base, ksp->ring_base_dma);
}
static u32
ks8695_get_msglevel(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
return ksp->msg_enable;
}
static void
ks8695_set_msglevel(struct net_device *ndev, u32 value)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
ksp->msg_enable = value;
}
static int
ks8695_wan_get_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
cmd->supported = (SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_TP | SUPPORTED_MII);
cmd->transceiver = XCVR_INTERNAL;
cmd->advertising = ADVERTISED_TP | ADVERTISED_MII;
cmd->port = PORT_MII;
cmd->supported |= (SUPPORTED_Autoneg | SUPPORTED_Pause);
cmd->phy_address = 0;
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
if ((ctrl & WMC_WAND) == 0) {
cmd->advertising |= ADVERTISED_Autoneg;
if (ctrl & WMC_WANA100F)
cmd->advertising |= ADVERTISED_100baseT_Full;
if (ctrl & WMC_WANA100H)
cmd->advertising |= ADVERTISED_100baseT_Half;
if (ctrl & WMC_WANA10F)
cmd->advertising |= ADVERTISED_10baseT_Full;
if (ctrl & WMC_WANA10H)
cmd->advertising |= ADVERTISED_10baseT_Half;
if (ctrl & WMC_WANAP)
cmd->advertising |= ADVERTISED_Pause;
cmd->autoneg = AUTONEG_ENABLE;
ethtool_cmd_speed_set(cmd,
(ctrl & WMC_WSS) ? SPEED_100 : SPEED_10);
cmd->duplex = (ctrl & WMC_WDS) ?
DUPLEX_FULL : DUPLEX_HALF;
} else {
cmd->autoneg = AUTONEG_DISABLE;
ethtool_cmd_speed_set(cmd, ((ctrl & WMC_WANF100) ?
SPEED_100 : SPEED_10));
cmd->duplex = (ctrl & WMC_WANFF) ?
DUPLEX_FULL : DUPLEX_HALF;
}
return 0;
}
static int
ks8695_wan_set_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
if ((cmd->speed != SPEED_10) && (cmd->speed != SPEED_100))
return -EINVAL;
if ((cmd->duplex != DUPLEX_HALF) && (cmd->duplex != DUPLEX_FULL))
return -EINVAL;
if (cmd->port != PORT_MII)
return -EINVAL;
if (cmd->transceiver != XCVR_INTERNAL)
return -EINVAL;
if ((cmd->autoneg != AUTONEG_DISABLE) &&
(cmd->autoneg != AUTONEG_ENABLE))
return -EINVAL;
if (cmd->autoneg == AUTONEG_ENABLE) {
if ((cmd->advertising & (ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full)) == 0)
return -EINVAL;
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
ctrl &= ~(WMC_WAND | WMC_WANA100F | WMC_WANA100H |
WMC_WANA10F | WMC_WANA10H);
if (cmd->advertising & ADVERTISED_100baseT_Full)
ctrl |= WMC_WANA100F;
if (cmd->advertising & ADVERTISED_100baseT_Half)
ctrl |= WMC_WANA100H;
if (cmd->advertising & ADVERTISED_10baseT_Full)
ctrl |= WMC_WANA10F;
if (cmd->advertising & ADVERTISED_10baseT_Half)
ctrl |= WMC_WANA10H;
ctrl |= WMC_WANR;
writel(ctrl, ksp->phyiface_regs + KS8695_WMC);
} else {
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
ctrl |= WMC_WAND;
ctrl &= ~(WMC_WANF100 | WMC_WANFF);
if (cmd->speed == SPEED_100)
ctrl |= WMC_WANF100;
if (cmd->duplex == DUPLEX_FULL)
ctrl |= WMC_WANFF;
writel(ctrl, ksp->phyiface_regs + KS8695_WMC);
}
return 0;
}
static int
ks8695_wan_nwayreset(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
if ((ctrl & WMC_WAND) == 0)
writel(ctrl | WMC_WANR,
ksp->phyiface_regs + KS8695_WMC);
else
return -EINVAL;
return 0;
}
static void
ks8695_wan_get_pause(struct net_device *ndev, struct ethtool_pauseparam *param)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
ctrl = readl(ksp->phyiface_regs + KS8695_WMC);
param->autoneg = (ctrl & WMC_WANAP);
ctrl = ks8695_readreg(ksp, KS8695_DRXC);
param->rx_pause = (ctrl & DRXC_RFCE);
ctrl = ks8695_readreg(ksp, KS8695_DTXC);
param->tx_pause = (ctrl & DTXC_TFCE);
}
static void
ks8695_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, MODULENAME, sizeof(info->driver));
strlcpy(info->version, MODULEVERSION, sizeof(info->version));
strlcpy(info->bus_info, dev_name(ndev->dev.parent),
sizeof(info->bus_info));
}
static int
ks8695_set_mac(struct net_device *ndev, void *addr)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
struct sockaddr *address = addr;
if (!is_valid_ether_addr(address->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, address->sa_data, ndev->addr_len);
ks8695_update_mac(ksp);
dev_dbg(ksp->dev, "%s: Updated MAC address to %pM\n",
ndev->name, ndev->dev_addr);
return 0;
}
static void
ks8695_set_multicast(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
u32 ctrl;
ctrl = ks8695_readreg(ksp, KS8695_DRXC);
if (ndev->flags & IFF_PROMISC) {
ctrl |= DRXC_RA;
} else if (ndev->flags & ~IFF_PROMISC) {
ctrl &= ~DRXC_RA;
}
if (ndev->flags & IFF_ALLMULTI) {
ctrl |= DRXC_RM;
} else if (netdev_mc_count(ndev) > KS8695_NR_ADDRESSES) {
ctrl |= DRXC_RM;
} else {
ctrl &= ~DRXC_RM;
ks8695_init_partial_multicast(ksp, ndev);
}
ks8695_writereg(ksp, KS8695_DRXC, ctrl);
}
static void
ks8695_timeout(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
netif_stop_queue(ndev);
ks8695_shutdown(ksp);
ks8695_reset(ksp);
ks8695_update_mac(ksp);
ks8695_init_net(ksp);
ks8695_set_multicast(ndev);
netif_start_queue(ndev);
}
static int
ks8695_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
int buff_n;
dma_addr_t dmap;
spin_lock_irq(&ksp->txq_lock);
if (ksp->tx_ring_used == MAX_TX_DESC) {
spin_unlock_irq(&ksp->txq_lock);
return NETDEV_TX_BUSY;
}
buff_n = ksp->tx_ring_next_slot;
BUG_ON(ksp->tx_buffers[buff_n].skb);
dmap = dma_map_single(ksp->dev, skb->data, skb->len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(ksp->dev, dmap))) {
spin_unlock_irq(&ksp->txq_lock);
dev_dbg(ksp->dev, "%s: Could not map DMA memory for "\
"transmission, trying later\n", ndev->name);
return NETDEV_TX_BUSY;
}
ksp->tx_buffers[buff_n].dma_ptr = dmap;
ksp->tx_buffers[buff_n].skb = skb;
ksp->tx_buffers[buff_n].length = skb->len;
ksp->tx_ring[buff_n].data_ptr =
cpu_to_le32(ksp->tx_buffers[buff_n].dma_ptr);
ksp->tx_ring[buff_n].status =
cpu_to_le32(TDES_IC | TDES_FS | TDES_LS |
(skb->len & TDES_TBS));
wmb();
ksp->tx_ring[buff_n].owner = cpu_to_le32(TDES_OWN);
if (++ksp->tx_ring_used == MAX_TX_DESC)
netif_stop_queue(ndev);
ks8695_writereg(ksp, KS8695_DTSC, 0);
ksp->tx_ring_next_slot = (buff_n + 1) & MAX_TX_DESC_MASK;
spin_unlock_irq(&ksp->txq_lock);
return NETDEV_TX_OK;
}
static int
ks8695_stop(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
netif_stop_queue(ndev);
napi_disable(&ksp->napi);
ks8695_shutdown(ksp);
return 0;
}
static int
ks8695_open(struct net_device *ndev)
{
struct ks8695_priv *ksp = netdev_priv(ndev);
int ret;
ks8695_reset(ksp);
ks8695_update_mac(ksp);
ret = ks8695_init_net(ksp);
if (ret) {
ks8695_shutdown(ksp);
return ret;
}
napi_enable(&ksp->napi);
netif_start_queue(ndev);
return 0;
}
static void
ks8695_init_switch(struct ks8695_priv *ksp)
{
u32 ctrl;
ctrl = 0x40819e00;
ctrl &= ~(SEC0_LLED1S | SEC0_LLED0S);
ctrl |= (LLED0S_LINK | LLED1S_LINK_ACTIVITY);
ctrl |= SEC0_ENABLE;
writel(ctrl, ksp->phyiface_regs + KS8695_SEC0);
writel(0x9400100, ksp->phyiface_regs + KS8695_SEC1);
}
static void
ks8695_init_wan_phy(struct ks8695_priv *ksp)
{
u32 ctrl;
ctrl = (WMC_WANAP | WMC_WANA100F | WMC_WANA100H |
WMC_WANA10F | WMC_WANA10H);
ctrl |= (WLED0S_ACTIVITY | WLED1S_LINK);
ctrl |= WMC_WANR;
writel(ctrl, ksp->phyiface_regs + KS8695_WMC);
writel(0, ksp->phyiface_regs + KS8695_WPPM);
writel(0, ksp->phyiface_regs + KS8695_PPS);
}
static int
ks8695_probe(struct platform_device *pdev)
{
struct ks8695_priv *ksp;
struct net_device *ndev;
struct resource *regs_res, *phyiface_res;
struct resource *rxirq_res, *txirq_res, *linkirq_res;
int ret = 0;
int buff_n;
u32 machigh, maclow;
ndev = alloc_etherdev(sizeof(struct ks8695_priv));
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, &pdev->dev);
dev_dbg(&pdev->dev, "ks8695_probe() called\n");
ksp = netdev_priv(ndev);
ksp->dev = &pdev->dev;
ksp->ndev = ndev;
ksp->msg_enable = NETIF_MSG_LINK;
regs_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phyiface_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
rxirq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
txirq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
linkirq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 2);
if (!(regs_res && rxirq_res && txirq_res)) {
dev_err(ksp->dev, "insufficient resources\n");
ret = -ENOENT;
goto failure;
}
ksp->regs_req = request_mem_region(regs_res->start,
resource_size(regs_res),
pdev->name);
if (!ksp->regs_req) {
dev_err(ksp->dev, "cannot claim register space\n");
ret = -EIO;
goto failure;
}
ksp->io_regs = ioremap(regs_res->start, resource_size(regs_res));
if (!ksp->io_regs) {
dev_err(ksp->dev, "failed to ioremap registers\n");
ret = -EINVAL;
goto failure;
}
if (phyiface_res) {
ksp->phyiface_req =
request_mem_region(phyiface_res->start,
resource_size(phyiface_res),
phyiface_res->name);
if (!ksp->phyiface_req) {
dev_err(ksp->dev,
"cannot claim switch register space\n");
ret = -EIO;
goto failure;
}
ksp->phyiface_regs = ioremap(phyiface_res->start,
resource_size(phyiface_res));
if (!ksp->phyiface_regs) {
dev_err(ksp->dev,
"failed to ioremap switch registers\n");
ret = -EINVAL;
goto failure;
}
}
ksp->rx_irq = rxirq_res->start;
ksp->rx_irq_name = rxirq_res->name ? rxirq_res->name : "Ethernet RX";
ksp->tx_irq = txirq_res->start;
ksp->tx_irq_name = txirq_res->name ? txirq_res->name : "Ethernet TX";
ksp->link_irq = (linkirq_res ? linkirq_res->start : -1);
ksp->link_irq_name = (linkirq_res && linkirq_res->name) ?
linkirq_res->name : "Ethernet Link";
ndev->netdev_ops = &ks8695_netdev_ops;
ndev->watchdog_timeo = msecs_to_jiffies(watchdog);
netif_napi_add(ndev, &ksp->napi, ks8695_poll, NAPI_WEIGHT);
machigh = ks8695_readreg(ksp, KS8695_MAH);
maclow = ks8695_readreg(ksp, KS8695_MAL);
ndev->dev_addr[0] = (machigh >> 8) & 0xFF;
ndev->dev_addr[1] = machigh & 0xFF;
ndev->dev_addr[2] = (maclow >> 24) & 0xFF;
ndev->dev_addr[3] = (maclow >> 16) & 0xFF;
ndev->dev_addr[4] = (maclow >> 8) & 0xFF;
ndev->dev_addr[5] = maclow & 0xFF;
if (!is_valid_ether_addr(ndev->dev_addr))
dev_warn(ksp->dev, "%s: Invalid ethernet MAC address. Please "
"set using ifconfig\n", ndev->name);
ksp->ring_base = dma_alloc_coherent(&pdev->dev, RING_DMA_SIZE,
&ksp->ring_base_dma, GFP_KERNEL);
if (!ksp->ring_base) {
ret = -ENOMEM;
goto failure;
}
ksp->tx_ring = ksp->ring_base;
ksp->tx_ring_dma = ksp->ring_base_dma;
spin_lock_init(&ksp->txq_lock);
spin_lock_init(&ksp->rx_lock);
ksp->rx_ring = ksp->ring_base + TX_RING_DMA_SIZE;
ksp->rx_ring_dma = ksp->ring_base_dma + TX_RING_DMA_SIZE;
memset(ksp->tx_ring, 0, TX_RING_DMA_SIZE);
memset(ksp->rx_ring, 0, RX_RING_DMA_SIZE);
for (buff_n = 0; buff_n < MAX_TX_DESC; ++buff_n) {
ksp->tx_ring[buff_n].next_desc =
cpu_to_le32(ksp->tx_ring_dma +
(sizeof(struct tx_ring_desc) *
((buff_n + 1) & MAX_TX_DESC_MASK)));
}
for (buff_n = 0; buff_n < MAX_RX_DESC; ++buff_n) {
ksp->rx_ring[buff_n].next_desc =
cpu_to_le32(ksp->rx_ring_dma +
(sizeof(struct rx_ring_desc) *
((buff_n + 1) & MAX_RX_DESC_MASK)));
}
if (ksp->phyiface_regs && ksp->link_irq == -1) {
ks8695_init_switch(ksp);
ksp->dtype = KS8695_DTYPE_LAN;
ndev->ethtool_ops = &ks8695_ethtool_ops;
} else if (ksp->phyiface_regs && ksp->link_irq != -1) {
ks8695_init_wan_phy(ksp);
ksp->dtype = KS8695_DTYPE_WAN;
ndev->ethtool_ops = &ks8695_wan_ethtool_ops;
} else {
ksp->dtype = KS8695_DTYPE_HPNA;
ndev->ethtool_ops = &ks8695_ethtool_ops;
}
platform_set_drvdata(pdev, ndev);
ret = register_netdev(ndev);
if (ret == 0) {
dev_info(ksp->dev, "ks8695 ethernet (%s) MAC: %pM\n",
ks8695_port_type(ksp), ndev->dev_addr);
} else {
dev_err(ksp->dev, "ks8695net: failed to register netdev.\n");
goto failure;
}
return 0;
failure:
ks8695_release_device(ksp);
free_netdev(ndev);
return ret;
}
static int
ks8695_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct ks8695_priv *ksp = netdev_priv(ndev);
ksp->in_suspend = 1;
if (netif_running(ndev)) {
netif_device_detach(ndev);
ks8695_shutdown(ksp);
}
return 0;
}
static int
ks8695_drv_resume(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct ks8695_priv *ksp = netdev_priv(ndev);
if (netif_running(ndev)) {
ks8695_reset(ksp);
ks8695_init_net(ksp);
ks8695_set_multicast(ndev);
netif_device_attach(ndev);
}
ksp->in_suspend = 0;
return 0;
}
static int
ks8695_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct ks8695_priv *ksp = netdev_priv(ndev);
netif_napi_del(&ksp->napi);
unregister_netdev(ndev);
ks8695_release_device(ksp);
free_netdev(ndev);
dev_dbg(&pdev->dev, "released and freed device\n");
return 0;
}
