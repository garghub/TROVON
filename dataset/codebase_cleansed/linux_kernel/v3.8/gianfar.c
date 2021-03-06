static void gfar_init_rxbdp(struct gfar_priv_rx_q *rx_queue, struct rxbd8 *bdp,
dma_addr_t buf)
{
u32 lstatus;
bdp->bufPtr = buf;
lstatus = BD_LFLAG(RXBD_EMPTY | RXBD_INTERRUPT);
if (bdp == rx_queue->rx_bd_base + rx_queue->rx_ring_size - 1)
lstatus |= BD_LFLAG(RXBD_WRAP);
eieio();
bdp->lstatus = lstatus;
}
static int gfar_init_bds(struct net_device *ndev)
{
struct gfar_private *priv = netdev_priv(ndev);
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
struct txbd8 *txbdp;
struct rxbd8 *rxbdp;
int i, j;
for (i = 0; i < priv->num_tx_queues; i++) {
tx_queue = priv->tx_queue[i];
tx_queue->num_txbdfree = tx_queue->tx_ring_size;
tx_queue->dirty_tx = tx_queue->tx_bd_base;
tx_queue->cur_tx = tx_queue->tx_bd_base;
tx_queue->skb_curtx = 0;
tx_queue->skb_dirtytx = 0;
txbdp = tx_queue->tx_bd_base;
for (j = 0; j < tx_queue->tx_ring_size; j++) {
txbdp->lstatus = 0;
txbdp->bufPtr = 0;
txbdp++;
}
txbdp--;
txbdp->status |= TXBD_WRAP;
}
for (i = 0; i < priv->num_rx_queues; i++) {
rx_queue = priv->rx_queue[i];
rx_queue->cur_rx = rx_queue->rx_bd_base;
rx_queue->skb_currx = 0;
rxbdp = rx_queue->rx_bd_base;
for (j = 0; j < rx_queue->rx_ring_size; j++) {
struct sk_buff *skb = rx_queue->rx_skbuff[j];
if (skb) {
gfar_init_rxbdp(rx_queue, rxbdp,
rxbdp->bufPtr);
} else {
skb = gfar_new_skb(ndev);
if (!skb) {
netdev_err(ndev, "Can't allocate RX buffers\n");
return -ENOMEM;
}
rx_queue->rx_skbuff[j] = skb;
gfar_new_rxbdp(rx_queue, rxbdp, skb);
}
rxbdp++;
}
}
return 0;
}
static int gfar_alloc_skb_resources(struct net_device *ndev)
{
void *vaddr;
dma_addr_t addr;
int i, j, k;
struct gfar_private *priv = netdev_priv(ndev);
struct device *dev = &priv->ofdev->dev;
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
priv->total_tx_ring_size = 0;
for (i = 0; i < priv->num_tx_queues; i++)
priv->total_tx_ring_size += priv->tx_queue[i]->tx_ring_size;
priv->total_rx_ring_size = 0;
for (i = 0; i < priv->num_rx_queues; i++)
priv->total_rx_ring_size += priv->rx_queue[i]->rx_ring_size;
vaddr = dma_alloc_coherent(dev,
sizeof(struct txbd8) * priv->total_tx_ring_size +
sizeof(struct rxbd8) * priv->total_rx_ring_size,
&addr, GFP_KERNEL);
if (!vaddr) {
netif_err(priv, ifup, ndev,
"Could not allocate buffer descriptors!\n");
return -ENOMEM;
}
for (i = 0; i < priv->num_tx_queues; i++) {
tx_queue = priv->tx_queue[i];
tx_queue->tx_bd_base = vaddr;
tx_queue->tx_bd_dma_base = addr;
tx_queue->dev = ndev;
addr += sizeof(struct txbd8) * tx_queue->tx_ring_size;
vaddr += sizeof(struct txbd8) * tx_queue->tx_ring_size;
}
for (i = 0; i < priv->num_rx_queues; i++) {
rx_queue = priv->rx_queue[i];
rx_queue->rx_bd_base = vaddr;
rx_queue->rx_bd_dma_base = addr;
rx_queue->dev = ndev;
addr += sizeof(struct rxbd8) * rx_queue->rx_ring_size;
vaddr += sizeof(struct rxbd8) * rx_queue->rx_ring_size;
}
for (i = 0; i < priv->num_tx_queues; i++) {
tx_queue = priv->tx_queue[i];
tx_queue->tx_skbuff = kmalloc(sizeof(*tx_queue->tx_skbuff) *
tx_queue->tx_ring_size,
GFP_KERNEL);
if (!tx_queue->tx_skbuff) {
netif_err(priv, ifup, ndev,
"Could not allocate tx_skbuff\n");
goto cleanup;
}
for (k = 0; k < tx_queue->tx_ring_size; k++)
tx_queue->tx_skbuff[k] = NULL;
}
for (i = 0; i < priv->num_rx_queues; i++) {
rx_queue = priv->rx_queue[i];
rx_queue->rx_skbuff = kmalloc(sizeof(*rx_queue->rx_skbuff) *
rx_queue->rx_ring_size,
GFP_KERNEL);
if (!rx_queue->rx_skbuff) {
netif_err(priv, ifup, ndev,
"Could not allocate rx_skbuff\n");
goto cleanup;
}
for (j = 0; j < rx_queue->rx_ring_size; j++)
rx_queue->rx_skbuff[j] = NULL;
}
if (gfar_init_bds(ndev))
goto cleanup;
return 0;
cleanup:
free_skb_resources(priv);
return -ENOMEM;
}
static void gfar_init_tx_rx_base(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 __iomem *baddr;
int i;
baddr = &regs->tbase0;
for (i = 0; i < priv->num_tx_queues; i++) {
gfar_write(baddr, priv->tx_queue[i]->tx_bd_dma_base);
baddr += 2;
}
baddr = &regs->rbase0;
for (i = 0; i < priv->num_rx_queues; i++) {
gfar_write(baddr, priv->rx_queue[i]->rx_bd_dma_base);
baddr += 2;
}
}
static void gfar_init_mac(struct net_device *ndev)
{
struct gfar_private *priv = netdev_priv(ndev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 rctrl = 0;
u32 tctrl = 0;
u32 attrs = 0;
gfar_init_tx_rx_base(priv);
gfar_configure_coalescing(priv, 0xFF, 0xFF);
if (priv->rx_filer_enable) {
rctrl |= RCTRL_FILREN;
gfar_write(&regs->rir0, DEFAULT_RIR0);
}
if (ndev->features & NETIF_F_RXCSUM)
rctrl |= RCTRL_CHECKSUMMING;
if (priv->extended_hash) {
rctrl |= RCTRL_EXTHASH;
gfar_clear_exact_match(ndev);
rctrl |= RCTRL_EMEN;
}
if (priv->padding) {
rctrl &= ~RCTRL_PAL_MASK;
rctrl |= RCTRL_PADDING(priv->padding);
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER) {
rctrl &= ~RCTRL_PAL_MASK;
rctrl |= RCTRL_PADDING(8);
priv->padding = 8;
}
if (priv->hwts_rx_en)
rctrl |= RCTRL_PRSDEP_INIT | RCTRL_TS_ENABLE;
if (ndev->features & NETIF_F_HW_VLAN_RX)
rctrl |= RCTRL_VLEX | RCTRL_PRSDEP_INIT;
gfar_write(&regs->rctrl, rctrl);
if (ndev->features & NETIF_F_IP_CSUM)
tctrl |= TCTRL_INIT_CSUM;
if (priv->prio_sched_en)
tctrl |= TCTRL_TXSCHED_PRIO;
else {
tctrl |= TCTRL_TXSCHED_WRRS;
gfar_write(&regs->tr03wt, DEFAULT_WRRS_WEIGHT);
gfar_write(&regs->tr47wt, DEFAULT_WRRS_WEIGHT);
}
gfar_write(&regs->tctrl, tctrl);
attrs = ATTRELI_EL(priv->rx_stash_size) |
ATTRELI_EI(priv->rx_stash_index);
gfar_write(&regs->attreli, attrs);
attrs = ATTR_INIT_SETTINGS;
if (priv->bd_stash_en)
attrs |= ATTR_BDSTASH;
if (priv->rx_stash_size != 0)
attrs |= ATTR_BUFSTASH;
gfar_write(&regs->attr, attrs);
gfar_write(&regs->fifo_tx_thr, priv->fifo_threshold);
gfar_write(&regs->fifo_tx_starve, priv->fifo_starve);
gfar_write(&regs->fifo_tx_starve_shutoff, priv->fifo_starve_off);
}
static struct net_device_stats *gfar_get_stats(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
unsigned long rx_packets = 0, rx_bytes = 0, rx_dropped = 0;
unsigned long tx_packets = 0, tx_bytes = 0;
int i;
for (i = 0; i < priv->num_rx_queues; i++) {
rx_packets += priv->rx_queue[i]->stats.rx_packets;
rx_bytes += priv->rx_queue[i]->stats.rx_bytes;
rx_dropped += priv->rx_queue[i]->stats.rx_dropped;
}
dev->stats.rx_packets = rx_packets;
dev->stats.rx_bytes = rx_bytes;
dev->stats.rx_dropped = rx_dropped;
for (i = 0; i < priv->num_tx_queues; i++) {
tx_bytes += priv->tx_queue[i]->stats.tx_bytes;
tx_packets += priv->tx_queue[i]->stats.tx_packets;
}
dev->stats.tx_bytes = tx_bytes;
dev->stats.tx_packets = tx_packets;
return &dev->stats;
}
void lock_rx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_rx_queues; i++)
spin_lock(&priv->rx_queue[i]->rxlock);
}
void lock_tx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
spin_lock(&priv->tx_queue[i]->txlock);
}
void unlock_rx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_rx_queues; i++)
spin_unlock(&priv->rx_queue[i]->rxlock);
}
void unlock_tx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
spin_unlock(&priv->tx_queue[i]->txlock);
}
static bool gfar_is_vlan_on(struct gfar_private *priv)
{
return (priv->ndev->features & NETIF_F_HW_VLAN_RX) ||
(priv->ndev->features & NETIF_F_HW_VLAN_TX);
}
static inline int gfar_uses_fcb(struct gfar_private *priv)
{
return gfar_is_vlan_on(priv) ||
(priv->ndev->features & NETIF_F_RXCSUM) ||
(priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER);
}
static void free_tx_pointers(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
kfree(priv->tx_queue[i]);
}
static void free_rx_pointers(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_rx_queues; i++)
kfree(priv->rx_queue[i]);
}
static void unmap_group_regs(struct gfar_private *priv)
{
int i;
for (i = 0; i < MAXGROUPS; i++)
if (priv->gfargrp[i].regs)
iounmap(priv->gfargrp[i].regs);
}
static void disable_napi(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++)
napi_disable(&priv->gfargrp[i].napi);
}
static void enable_napi(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++)
napi_enable(&priv->gfargrp[i].napi);
}
static int gfar_parse_group(struct device_node *np,
struct gfar_private *priv, const char *model)
{
u32 *queue_mask;
priv->gfargrp[priv->num_grps].regs = of_iomap(np, 0);
if (!priv->gfargrp[priv->num_grps].regs)
return -ENOMEM;
priv->gfargrp[priv->num_grps].interruptTransmit =
irq_of_parse_and_map(np, 0);
if (model && strcasecmp(model, "FEC")) {
priv->gfargrp[priv->num_grps].interruptReceive =
irq_of_parse_and_map(np, 1);
priv->gfargrp[priv->num_grps].interruptError =
irq_of_parse_and_map(np,2);
if (priv->gfargrp[priv->num_grps].interruptTransmit == NO_IRQ ||
priv->gfargrp[priv->num_grps].interruptReceive == NO_IRQ ||
priv->gfargrp[priv->num_grps].interruptError == NO_IRQ)
return -EINVAL;
}
priv->gfargrp[priv->num_grps].grp_id = priv->num_grps;
priv->gfargrp[priv->num_grps].priv = priv;
spin_lock_init(&priv->gfargrp[priv->num_grps].grplock);
if (priv->mode == MQ_MG_MODE) {
queue_mask = (u32 *)of_get_property(np, "fsl,rx-bit-map", NULL);
priv->gfargrp[priv->num_grps].rx_bit_map = queue_mask ?
*queue_mask : (DEFAULT_MAPPING >> priv->num_grps);
queue_mask = (u32 *)of_get_property(np, "fsl,tx-bit-map", NULL);
priv->gfargrp[priv->num_grps].tx_bit_map = queue_mask ?
*queue_mask : (DEFAULT_MAPPING >> priv->num_grps);
} else {
priv->gfargrp[priv->num_grps].rx_bit_map = 0xFF;
priv->gfargrp[priv->num_grps].tx_bit_map = 0xFF;
}
priv->num_grps++;
return 0;
}
static int gfar_of_init(struct platform_device *ofdev, struct net_device **pdev)
{
const char *model;
const char *ctype;
const void *mac_addr;
int err = 0, i;
struct net_device *dev = NULL;
struct gfar_private *priv = NULL;
struct device_node *np = ofdev->dev.of_node;
struct device_node *child = NULL;
const u32 *stash;
const u32 *stash_len;
const u32 *stash_idx;
unsigned int num_tx_qs, num_rx_qs;
u32 *tx_queues, *rx_queues;
if (!np || !of_device_is_available(np))
return -ENODEV;
tx_queues = (u32 *)of_get_property(np, "fsl,num_tx_queues", NULL);
num_tx_qs = tx_queues ? *tx_queues : 1;
if (num_tx_qs > MAX_TX_QS) {
pr_err("num_tx_qs(=%d) greater than MAX_TX_QS(=%d)\n",
num_tx_qs, MAX_TX_QS);
pr_err("Cannot do alloc_etherdev, aborting\n");
return -EINVAL;
}
rx_queues = (u32 *)of_get_property(np, "fsl,num_rx_queues", NULL);
num_rx_qs = rx_queues ? *rx_queues : 1;
if (num_rx_qs > MAX_RX_QS) {
pr_err("num_rx_qs(=%d) greater than MAX_RX_QS(=%d)\n",
num_rx_qs, MAX_RX_QS);
pr_err("Cannot do alloc_etherdev, aborting\n");
return -EINVAL;
}
*pdev = alloc_etherdev_mq(sizeof(*priv), num_tx_qs);
dev = *pdev;
if (NULL == dev)
return -ENOMEM;
priv = netdev_priv(dev);
priv->node = ofdev->dev.of_node;
priv->ndev = dev;
priv->num_tx_queues = num_tx_qs;
netif_set_real_num_rx_queues(dev, num_rx_qs);
priv->num_rx_queues = num_rx_qs;
priv->num_grps = 0x0;
INIT_LIST_HEAD(&priv->rx_list.list);
priv->rx_list.count = 0;
mutex_init(&priv->rx_queue_access);
model = of_get_property(np, "model", NULL);
for (i = 0; i < MAXGROUPS; i++)
priv->gfargrp[i].regs = NULL;
if (of_device_is_compatible(np, "fsl,etsec2")) {
priv->mode = MQ_MG_MODE;
for_each_child_of_node(np, child) {
err = gfar_parse_group(child, priv, model);
if (err)
goto err_grp_init;
}
} else {
priv->mode = SQ_SG_MODE;
err = gfar_parse_group(np, priv, model);
if (err)
goto err_grp_init;
}
for (i = 0; i < priv->num_tx_queues; i++)
priv->tx_queue[i] = NULL;
for (i = 0; i < priv->num_rx_queues; i++)
priv->rx_queue[i] = NULL;
for (i = 0; i < priv->num_tx_queues; i++) {
priv->tx_queue[i] = kzalloc(sizeof(struct gfar_priv_tx_q),
GFP_KERNEL);
if (!priv->tx_queue[i]) {
err = -ENOMEM;
goto tx_alloc_failed;
}
priv->tx_queue[i]->tx_skbuff = NULL;
priv->tx_queue[i]->qindex = i;
priv->tx_queue[i]->dev = dev;
spin_lock_init(&(priv->tx_queue[i]->txlock));
}
for (i = 0; i < priv->num_rx_queues; i++) {
priv->rx_queue[i] = kzalloc(sizeof(struct gfar_priv_rx_q),
GFP_KERNEL);
if (!priv->rx_queue[i]) {
err = -ENOMEM;
goto rx_alloc_failed;
}
priv->rx_queue[i]->rx_skbuff = NULL;
priv->rx_queue[i]->qindex = i;
priv->rx_queue[i]->dev = dev;
spin_lock_init(&(priv->rx_queue[i]->rxlock));
}
stash = of_get_property(np, "bd-stash", NULL);
if (stash) {
priv->device_flags |= FSL_GIANFAR_DEV_HAS_BD_STASHING;
priv->bd_stash_en = 1;
}
stash_len = of_get_property(np, "rx-stash-len", NULL);
if (stash_len)
priv->rx_stash_size = *stash_len;
stash_idx = of_get_property(np, "rx-stash-idx", NULL);
if (stash_idx)
priv->rx_stash_index = *stash_idx;
if (stash_len || stash_idx)
priv->device_flags |= FSL_GIANFAR_DEV_HAS_BUF_STASHING;
mac_addr = of_get_mac_address(np);
if (mac_addr)
memcpy(dev->dev_addr, mac_addr, ETH_ALEN);
if (model && !strcasecmp(model, "TSEC"))
priv->device_flags = FSL_GIANFAR_DEV_HAS_GIGABIT |
FSL_GIANFAR_DEV_HAS_COALESCE |
FSL_GIANFAR_DEV_HAS_RMON |
FSL_GIANFAR_DEV_HAS_MULTI_INTR;
if (model && !strcasecmp(model, "eTSEC"))
priv->device_flags = FSL_GIANFAR_DEV_HAS_GIGABIT |
FSL_GIANFAR_DEV_HAS_COALESCE |
FSL_GIANFAR_DEV_HAS_RMON |
FSL_GIANFAR_DEV_HAS_MULTI_INTR |
FSL_GIANFAR_DEV_HAS_PADDING |
FSL_GIANFAR_DEV_HAS_CSUM |
FSL_GIANFAR_DEV_HAS_VLAN |
FSL_GIANFAR_DEV_HAS_MAGIC_PACKET |
FSL_GIANFAR_DEV_HAS_EXTENDED_HASH |
FSL_GIANFAR_DEV_HAS_TIMER;
ctype = of_get_property(np, "phy-connection-type", NULL);
if (ctype && !strcmp(ctype, "rgmii-id"))
priv->interface = PHY_INTERFACE_MODE_RGMII_ID;
else
priv->interface = PHY_INTERFACE_MODE_MII;
if (of_get_property(np, "fsl,magic-packet", NULL))
priv->device_flags |= FSL_GIANFAR_DEV_HAS_MAGIC_PACKET;
priv->phy_node = of_parse_phandle(np, "phy-handle", 0);
priv->tbi_node = of_parse_phandle(np, "tbi-handle", 0);
return 0;
rx_alloc_failed:
free_rx_pointers(priv);
tx_alloc_failed:
free_tx_pointers(priv);
err_grp_init:
unmap_group_regs(priv);
free_netdev(dev);
return err;
}
static int gfar_hwtstamp_ioctl(struct net_device *netdev,
struct ifreq *ifr, int cmd)
{
struct hwtstamp_config config;
struct gfar_private *priv = netdev_priv(netdev);
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
priv->hwts_tx_en = 0;
break;
case HWTSTAMP_TX_ON:
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER))
return -ERANGE;
priv->hwts_tx_en = 1;
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
if (priv->hwts_rx_en) {
stop_gfar(netdev);
priv->hwts_rx_en = 0;
startup_gfar(netdev);
}
break;
default:
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER))
return -ERANGE;
if (!priv->hwts_rx_en) {
stop_gfar(netdev);
priv->hwts_rx_en = 1;
startup_gfar(netdev);
}
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
}
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int gfar_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct gfar_private *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (cmd == SIOCSHWTSTAMP)
return gfar_hwtstamp_ioctl(dev, rq, cmd);
if (!priv->phydev)
return -ENODEV;
return phy_mii_ioctl(priv->phydev, rq, cmd);
}
static unsigned int reverse_bitmap(unsigned int bit_map, unsigned int max_qs)
{
unsigned int new_bit_map = 0x0;
int mask = 0x1 << (max_qs - 1), i;
for (i = 0; i < max_qs; i++) {
if (bit_map & mask)
new_bit_map = new_bit_map + (1 << i);
mask = mask >> 0x1;
}
return new_bit_map;
}
static u32 cluster_entry_per_class(struct gfar_private *priv, u32 rqfar,
u32 class)
{
u32 rqfpr = FPR_FILER_MASK;
u32 rqfcr = 0x0;
rqfar--;
rqfcr = RQFCR_CLE | RQFCR_PID_MASK | RQFCR_CMP_EXACT;
priv->ftp_rqfpr[rqfar] = rqfpr;
priv->ftp_rqfcr[rqfar] = rqfcr;
gfar_write_filer(priv, rqfar, rqfcr, rqfpr);
rqfar--;
rqfcr = RQFCR_CMP_NOMATCH;
priv->ftp_rqfpr[rqfar] = rqfpr;
priv->ftp_rqfcr[rqfar] = rqfcr;
gfar_write_filer(priv, rqfar, rqfcr, rqfpr);
rqfar--;
rqfcr = RQFCR_CMP_EXACT | RQFCR_PID_PARSE | RQFCR_CLE | RQFCR_AND;
rqfpr = class;
priv->ftp_rqfcr[rqfar] = rqfcr;
priv->ftp_rqfpr[rqfar] = rqfpr;
gfar_write_filer(priv, rqfar, rqfcr, rqfpr);
rqfar--;
rqfcr = RQFCR_CMP_EXACT | RQFCR_PID_MASK | RQFCR_AND;
rqfpr = class;
priv->ftp_rqfcr[rqfar] = rqfcr;
priv->ftp_rqfpr[rqfar] = rqfpr;
gfar_write_filer(priv, rqfar, rqfcr, rqfpr);
return rqfar;
}
static void gfar_init_filer_table(struct gfar_private *priv)
{
int i = 0x0;
u32 rqfar = MAX_FILER_IDX;
u32 rqfcr = 0x0;
u32 rqfpr = FPR_FILER_MASK;
rqfcr = RQFCR_CMP_MATCH;
priv->ftp_rqfcr[rqfar] = rqfcr;
priv->ftp_rqfpr[rqfar] = rqfpr;
gfar_write_filer(priv, rqfar, rqfcr, rqfpr);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV6);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV6 | RQFPR_UDP);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV6 | RQFPR_TCP);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV4);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV4 | RQFPR_UDP);
rqfar = cluster_entry_per_class(priv, rqfar, RQFPR_IPV4 | RQFPR_TCP);
priv->cur_filer_idx = rqfar;
rqfcr = RQFCR_CMP_NOMATCH;
for (i = 0; i < rqfar; i++) {
priv->ftp_rqfcr[i] = rqfcr;
priv->ftp_rqfpr[i] = rqfpr;
gfar_write_filer(priv, i, rqfcr, rqfpr);
}
}
static void gfar_detect_errata(struct gfar_private *priv)
{
struct device *dev = &priv->ofdev->dev;
unsigned int pvr = mfspr(SPRN_PVR);
unsigned int svr = mfspr(SPRN_SVR);
unsigned int mod = (svr >> 16) & 0xfff6;
unsigned int rev = svr & 0xffff;
if ((pvr == 0x80850010 && mod == 0x80b0 && rev >= 0x0020) ||
(pvr == 0x80861010 && (mod & 0xfff9) == 0x80c0))
priv->errata |= GFAR_ERRATA_74;
if ((pvr == 0x80850010 && mod == 0x80b0) ||
(pvr == 0x80861010 && (mod & 0xfff9) == 0x80c0))
priv->errata |= GFAR_ERRATA_76;
if ((pvr == 0x80850010 && mod == 0x80b0) ||
(pvr == 0x80861010 && (mod & 0xfff9) == 0x80c0))
priv->errata |= GFAR_ERRATA_A002;
if ((pvr == 0x80850010 && mod == 0x80b0 && rev < 0x0020) ||
(pvr == 0x80210020 && mod == 0x8030 && rev == 0x0020))
priv->errata |= GFAR_ERRATA_12;
if (priv->errata)
dev_info(dev, "enabled errata workarounds, flags: 0x%x\n",
priv->errata);
}
static int gfar_probe(struct platform_device *ofdev)
{
u32 tempval;
struct net_device *dev = NULL;
struct gfar_private *priv = NULL;
struct gfar __iomem *regs = NULL;
int err = 0, i, grp_idx = 0;
u32 rstat = 0, tstat = 0, rqueue = 0, tqueue = 0;
u32 isrg = 0;
u32 __iomem *baddr;
err = gfar_of_init(ofdev, &dev);
if (err)
return err;
priv = netdev_priv(dev);
priv->ndev = dev;
priv->ofdev = ofdev;
priv->node = ofdev->dev.of_node;
SET_NETDEV_DEV(dev, &ofdev->dev);
spin_lock_init(&priv->bflock);
INIT_WORK(&priv->reset_task, gfar_reset_task);
dev_set_drvdata(&ofdev->dev, priv);
regs = priv->gfargrp[0].regs;
gfar_detect_errata(priv);
gfar_halt(dev);
gfar_write(&regs->maccfg1, MACCFG1_SOFT_RESET);
udelay(2);
tempval = (MACCFG1_TX_FLOW | MACCFG1_RX_FLOW);
gfar_write(&regs->maccfg1, tempval);
tempval = MACCFG2_INIT_SETTINGS;
if (gfar_has_errata(priv, GFAR_ERRATA_74))
tempval |= MACCFG2_HUGEFRAME | MACCFG2_LENGTHCHECK;
gfar_write(&regs->maccfg2, tempval);
gfar_write(&regs->ecntrl, ECNTRL_INIT_SETTINGS);
dev->base_addr = (unsigned long) regs;
SET_NETDEV_DEV(dev, &ofdev->dev);
dev->watchdog_timeo = TX_TIMEOUT;
dev->mtu = 1500;
dev->netdev_ops = &gfar_netdev_ops;
dev->ethtool_ops = &gfar_ethtool_ops;
for (i = 0; i < priv->num_grps; i++)
netif_napi_add(dev, &priv->gfargrp[i].napi, gfar_poll,
GFAR_DEV_WEIGHT);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_CSUM) {
dev->hw_features = NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_RXCSUM;
dev->features |= NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_RXCSUM | NETIF_F_HIGHDMA;
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_VLAN) {
dev->hw_features |= NETIF_F_HW_VLAN_TX | NETIF_F_HW_VLAN_RX;
dev->features |= NETIF_F_HW_VLAN_RX;
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_EXTENDED_HASH) {
priv->extended_hash = 1;
priv->hash_width = 9;
priv->hash_regs[0] = &regs->igaddr0;
priv->hash_regs[1] = &regs->igaddr1;
priv->hash_regs[2] = &regs->igaddr2;
priv->hash_regs[3] = &regs->igaddr3;
priv->hash_regs[4] = &regs->igaddr4;
priv->hash_regs[5] = &regs->igaddr5;
priv->hash_regs[6] = &regs->igaddr6;
priv->hash_regs[7] = &regs->igaddr7;
priv->hash_regs[8] = &regs->gaddr0;
priv->hash_regs[9] = &regs->gaddr1;
priv->hash_regs[10] = &regs->gaddr2;
priv->hash_regs[11] = &regs->gaddr3;
priv->hash_regs[12] = &regs->gaddr4;
priv->hash_regs[13] = &regs->gaddr5;
priv->hash_regs[14] = &regs->gaddr6;
priv->hash_regs[15] = &regs->gaddr7;
} else {
priv->extended_hash = 0;
priv->hash_width = 8;
priv->hash_regs[0] = &regs->gaddr0;
priv->hash_regs[1] = &regs->gaddr1;
priv->hash_regs[2] = &regs->gaddr2;
priv->hash_regs[3] = &regs->gaddr3;
priv->hash_regs[4] = &regs->gaddr4;
priv->hash_regs[5] = &regs->gaddr5;
priv->hash_regs[6] = &regs->gaddr6;
priv->hash_regs[7] = &regs->gaddr7;
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_PADDING)
priv->padding = DEFAULT_PADDING;
else
priv->padding = 0;
if (dev->features & NETIF_F_IP_CSUM ||
priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER)
dev->needed_headroom = GMAC_FCB_LEN;
if (priv->num_grps > 1) {
baddr = &regs->isrg0;
for (i = 0; i < priv->num_grps; i++) {
isrg |= (priv->gfargrp[i].rx_bit_map << ISRG_SHIFT_RX);
isrg |= (priv->gfargrp[i].tx_bit_map << ISRG_SHIFT_TX);
gfar_write(baddr, isrg);
baddr++;
isrg = 0x0;
}
}
for (i = 0; i< priv->num_grps; i++) {
priv->gfargrp[i].tx_bit_map =
reverse_bitmap(priv->gfargrp[i].tx_bit_map, MAX_TX_QS);
priv->gfargrp[i].rx_bit_map =
reverse_bitmap(priv->gfargrp[i].rx_bit_map, MAX_RX_QS);
}
for (grp_idx = 0; grp_idx < priv->num_grps; grp_idx++) {
priv->gfargrp[grp_idx].num_rx_queues = 0x0;
for_each_set_bit(i, &priv->gfargrp[grp_idx].rx_bit_map,
priv->num_rx_queues) {
priv->gfargrp[grp_idx].num_rx_queues++;
priv->rx_queue[i]->grp = &priv->gfargrp[grp_idx];
rstat = rstat | (RSTAT_CLEAR_RHALT >> i);
rqueue = rqueue | ((RQUEUE_EN0 | RQUEUE_EX0) >> i);
}
priv->gfargrp[grp_idx].num_tx_queues = 0x0;
for_each_set_bit(i, &priv->gfargrp[grp_idx].tx_bit_map,
priv->num_tx_queues) {
priv->gfargrp[grp_idx].num_tx_queues++;
priv->tx_queue[i]->grp = &priv->gfargrp[grp_idx];
tstat = tstat | (TSTAT_CLEAR_THALT >> i);
tqueue = tqueue | (TQUEUE_EN0 >> i);
}
priv->gfargrp[grp_idx].rstat = rstat;
priv->gfargrp[grp_idx].tstat = tstat;
rstat = tstat =0;
}
gfar_write(&regs->rqueue, rqueue);
gfar_write(&regs->tqueue, tqueue);
priv->rx_buffer_size = DEFAULT_RX_BUFFER_SIZE;
for (i = 0; i < priv->num_tx_queues; i++) {
priv->tx_queue[i]->tx_ring_size = DEFAULT_TX_RING_SIZE;
priv->tx_queue[i]->num_txbdfree = DEFAULT_TX_RING_SIZE;
priv->tx_queue[i]->txcoalescing = DEFAULT_TX_COALESCE;
priv->tx_queue[i]->txic = DEFAULT_TXIC;
}
for (i = 0; i < priv->num_rx_queues; i++) {
priv->rx_queue[i]->rx_ring_size = DEFAULT_RX_RING_SIZE;
priv->rx_queue[i]->rxcoalescing = DEFAULT_RX_COALESCE;
priv->rx_queue[i]->rxic = DEFAULT_RXIC;
}
priv->rx_filer_enable = 1;
priv->msg_enable = (NETIF_MSG_IFUP << 1 ) - 1;
if (priv->num_tx_queues == 1)
priv->prio_sched_en = 1;
netif_carrier_off(dev);
err = register_netdev(dev);
if (err) {
pr_err("%s: Cannot register net device, aborting\n", dev->name);
goto register_fail;
}
device_init_wakeup(&dev->dev,
priv->device_flags &
FSL_GIANFAR_DEV_HAS_MAGIC_PACKET);
for (i = 0; i < priv->num_grps; i++) {
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
sprintf(priv->gfargrp[i].int_name_tx, "%s%s%c%s",
dev->name, "_g", '0' + i, "_tx");
sprintf(priv->gfargrp[i].int_name_rx, "%s%s%c%s",
dev->name, "_g", '0' + i, "_rx");
sprintf(priv->gfargrp[i].int_name_er, "%s%s%c%s",
dev->name, "_g", '0' + i, "_er");
} else
strcpy(priv->gfargrp[i].int_name_tx, dev->name);
}
gfar_init_filer_table(priv);
gfar_init_sysfs(dev);
netdev_info(dev, "mac: %pM\n", dev->dev_addr);
netdev_info(dev, "Running with NAPI enabled\n");
for (i = 0; i < priv->num_rx_queues; i++)
netdev_info(dev, "RX BD ring size for Q[%d]: %d\n",
i, priv->rx_queue[i]->rx_ring_size);
for (i = 0; i < priv->num_tx_queues; i++)
netdev_info(dev, "TX BD ring size for Q[%d]: %d\n",
i, priv->tx_queue[i]->tx_ring_size);
return 0;
register_fail:
unmap_group_regs(priv);
free_tx_pointers(priv);
free_rx_pointers(priv);
if (priv->phy_node)
of_node_put(priv->phy_node);
if (priv->tbi_node)
of_node_put(priv->tbi_node);
free_netdev(dev);
return err;
}
static int gfar_remove(struct platform_device *ofdev)
{
struct gfar_private *priv = dev_get_drvdata(&ofdev->dev);
if (priv->phy_node)
of_node_put(priv->phy_node);
if (priv->tbi_node)
of_node_put(priv->tbi_node);
dev_set_drvdata(&ofdev->dev, NULL);
unregister_netdev(priv->ndev);
unmap_group_regs(priv);
free_netdev(priv->ndev);
return 0;
}
static int gfar_suspend(struct device *dev)
{
struct gfar_private *priv = dev_get_drvdata(dev);
struct net_device *ndev = priv->ndev;
struct gfar __iomem *regs = priv->gfargrp[0].regs;
unsigned long flags;
u32 tempval;
int magic_packet = priv->wol_en &&
(priv->device_flags &
FSL_GIANFAR_DEV_HAS_MAGIC_PACKET);
netif_device_detach(ndev);
if (netif_running(ndev)) {
local_irq_save(flags);
lock_tx_qs(priv);
lock_rx_qs(priv);
gfar_halt_nodisable(ndev);
tempval = gfar_read(&regs->maccfg1);
tempval &= ~MACCFG1_TX_EN;
if (!magic_packet)
tempval &= ~MACCFG1_RX_EN;
gfar_write(&regs->maccfg1, tempval);
unlock_rx_qs(priv);
unlock_tx_qs(priv);
local_irq_restore(flags);
disable_napi(priv);
if (magic_packet) {
gfar_write(&regs->imask, IMASK_MAG);
tempval = gfar_read(&regs->maccfg2);
tempval |= MACCFG2_MPEN;
gfar_write(&regs->maccfg2, tempval);
} else {
phy_stop(priv->phydev);
}
}
return 0;
}
static int gfar_resume(struct device *dev)
{
struct gfar_private *priv = dev_get_drvdata(dev);
struct net_device *ndev = priv->ndev;
struct gfar __iomem *regs = priv->gfargrp[0].regs;
unsigned long flags;
u32 tempval;
int magic_packet = priv->wol_en &&
(priv->device_flags &
FSL_GIANFAR_DEV_HAS_MAGIC_PACKET);
if (!netif_running(ndev)) {
netif_device_attach(ndev);
return 0;
}
if (!magic_packet && priv->phydev)
phy_start(priv->phydev);
local_irq_save(flags);
lock_tx_qs(priv);
lock_rx_qs(priv);
tempval = gfar_read(&regs->maccfg2);
tempval &= ~MACCFG2_MPEN;
gfar_write(&regs->maccfg2, tempval);
gfar_start(ndev);
unlock_rx_qs(priv);
unlock_tx_qs(priv);
local_irq_restore(flags);
netif_device_attach(ndev);
enable_napi(priv);
return 0;
}
static int gfar_restore(struct device *dev)
{
struct gfar_private *priv = dev_get_drvdata(dev);
struct net_device *ndev = priv->ndev;
if (!netif_running(ndev)) {
netif_device_attach(ndev);
return 0;
}
if (gfar_init_bds(ndev)) {
free_skb_resources(priv);
return -ENOMEM;
}
init_registers(ndev);
gfar_set_mac_address(ndev);
gfar_init_mac(ndev);
gfar_start(ndev);
priv->oldlink = 0;
priv->oldspeed = 0;
priv->oldduplex = -1;
if (priv->phydev)
phy_start(priv->phydev);
netif_device_attach(ndev);
enable_napi(priv);
return 0;
}
static phy_interface_t gfar_get_interface(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 ecntrl;
ecntrl = gfar_read(&regs->ecntrl);
if (ecntrl & ECNTRL_SGMII_MODE)
return PHY_INTERFACE_MODE_SGMII;
if (ecntrl & ECNTRL_TBI_MODE) {
if (ecntrl & ECNTRL_REDUCED_MODE)
return PHY_INTERFACE_MODE_RTBI;
else
return PHY_INTERFACE_MODE_TBI;
}
if (ecntrl & ECNTRL_REDUCED_MODE) {
if (ecntrl & ECNTRL_REDUCED_MII_MODE) {
return PHY_INTERFACE_MODE_RMII;
}
else {
phy_interface_t interface = priv->interface;
if (interface == PHY_INTERFACE_MODE_RGMII_ID)
return PHY_INTERFACE_MODE_RGMII_ID;
return PHY_INTERFACE_MODE_RGMII;
}
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_GIGABIT)
return PHY_INTERFACE_MODE_GMII;
return PHY_INTERFACE_MODE_MII;
}
static int init_phy(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
uint gigabit_support =
priv->device_flags & FSL_GIANFAR_DEV_HAS_GIGABIT ?
SUPPORTED_1000baseT_Full : 0;
phy_interface_t interface;
priv->oldlink = 0;
priv->oldspeed = 0;
priv->oldduplex = -1;
interface = gfar_get_interface(dev);
priv->phydev = of_phy_connect(dev, priv->phy_node, &adjust_link, 0,
interface);
if (!priv->phydev)
priv->phydev = of_phy_connect_fixed_link(dev, &adjust_link,
interface);
if (!priv->phydev) {
dev_err(&dev->dev, "could not attach to PHY\n");
return -ENODEV;
}
if (interface == PHY_INTERFACE_MODE_SGMII)
gfar_configure_serdes(dev);
priv->phydev->supported &= (GFAR_SUPPORTED | gigabit_support);
priv->phydev->advertising = priv->phydev->supported;
return 0;
}
static void gfar_configure_serdes(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct phy_device *tbiphy;
if (!priv->tbi_node) {
dev_warn(&dev->dev, "error: SGMII mode requires that the "
"device tree specify a tbi-handle\n");
return;
}
tbiphy = of_phy_find_device(priv->tbi_node);
if (!tbiphy) {
dev_err(&dev->dev, "error: Could not get TBI device\n");
return;
}
if (phy_read(tbiphy, MII_BMSR) & BMSR_LSTATUS)
return;
phy_write(tbiphy, MII_TBICON, TBICON_CLK_SELECT);
phy_write(tbiphy, MII_ADVERTISE,
ADVERTISE_1000XFULL | ADVERTISE_1000XPAUSE |
ADVERTISE_1000XPSE_ASYM);
phy_write(tbiphy, MII_BMCR,
BMCR_ANENABLE | BMCR_ANRESTART | BMCR_FULLDPLX |
BMCR_SPEED1000);
}
static void init_registers(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = NULL;
int i;
for (i = 0; i < priv->num_grps; i++) {
regs = priv->gfargrp[i].regs;
gfar_write(&regs->ievent, IEVENT_INIT_CLEAR);
gfar_write(&regs->imask, IMASK_INIT_CLEAR);
}
regs = priv->gfargrp[0].regs;
gfar_write(&regs->igaddr0, 0);
gfar_write(&regs->igaddr1, 0);
gfar_write(&regs->igaddr2, 0);
gfar_write(&regs->igaddr3, 0);
gfar_write(&regs->igaddr4, 0);
gfar_write(&regs->igaddr5, 0);
gfar_write(&regs->igaddr6, 0);
gfar_write(&regs->igaddr7, 0);
gfar_write(&regs->gaddr0, 0);
gfar_write(&regs->gaddr1, 0);
gfar_write(&regs->gaddr2, 0);
gfar_write(&regs->gaddr3, 0);
gfar_write(&regs->gaddr4, 0);
gfar_write(&regs->gaddr5, 0);
gfar_write(&regs->gaddr6, 0);
gfar_write(&regs->gaddr7, 0);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_RMON) {
memset_io(&(regs->rmon), 0, sizeof (struct rmon_mib));
gfar_write(&regs->rmon.cam1, 0xffffffff);
gfar_write(&regs->rmon.cam2, 0xffffffff);
}
gfar_write(&regs->mrblr, priv->rx_buffer_size);
gfar_write(&regs->minflr, MINFLR_INIT_SETTINGS);
}
static int __gfar_is_rx_idle(struct gfar_private *priv)
{
u32 res;
if (likely(!gfar_has_errata(priv, GFAR_ERRATA_A002)))
return 0;
res = gfar_read((void __iomem *)priv->gfargrp[0].regs + 0xd1c);
res &= 0x7f807f80;
if ((res & 0xffff) == (res >> 16))
return 1;
return 0;
}
static void gfar_halt_nodisable(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = NULL;
u32 tempval;
int i;
for (i = 0; i < priv->num_grps; i++) {
regs = priv->gfargrp[i].regs;
gfar_write(&regs->imask, IMASK_INIT_CLEAR);
gfar_write(&regs->ievent, IEVENT_INIT_CLEAR);
}
regs = priv->gfargrp[0].regs;
tempval = gfar_read(&regs->dmactrl);
if ((tempval & (DMACTRL_GRS | DMACTRL_GTS)) !=
(DMACTRL_GRS | DMACTRL_GTS)) {
int ret;
tempval |= (DMACTRL_GRS | DMACTRL_GTS);
gfar_write(&regs->dmactrl, tempval);
do {
ret = spin_event_timeout(((gfar_read(&regs->ievent) &
(IEVENT_GRSC | IEVENT_GTSC)) ==
(IEVENT_GRSC | IEVENT_GTSC)), 1000000, 0);
if (!ret && !(gfar_read(&regs->ievent) & IEVENT_GRSC))
ret = __gfar_is_rx_idle(priv);
} while (!ret);
}
}
void gfar_halt(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
gfar_halt_nodisable(dev);
tempval = gfar_read(&regs->maccfg1);
tempval &= ~(MACCFG1_RX_EN | MACCFG1_TX_EN);
gfar_write(&regs->maccfg1, tempval);
}
static void free_grp_irqs(struct gfar_priv_grp *grp)
{
free_irq(grp->interruptError, grp);
free_irq(grp->interruptTransmit, grp);
free_irq(grp->interruptReceive, grp);
}
void stop_gfar(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
unsigned long flags;
int i;
phy_stop(priv->phydev);
local_irq_save(flags);
lock_tx_qs(priv);
lock_rx_qs(priv);
gfar_halt(dev);
unlock_rx_qs(priv);
unlock_tx_qs(priv);
local_irq_restore(flags);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
for (i = 0; i < priv->num_grps; i++)
free_grp_irqs(&priv->gfargrp[i]);
} else {
for (i = 0; i < priv->num_grps; i++)
free_irq(priv->gfargrp[i].interruptTransmit,
&priv->gfargrp[i]);
}
free_skb_resources(priv);
}
static void free_skb_tx_queue(struct gfar_priv_tx_q *tx_queue)
{
struct txbd8 *txbdp;
struct gfar_private *priv = netdev_priv(tx_queue->dev);
int i, j;
txbdp = tx_queue->tx_bd_base;
for (i = 0; i < tx_queue->tx_ring_size; i++) {
if (!tx_queue->tx_skbuff[i])
continue;
dma_unmap_single(&priv->ofdev->dev, txbdp->bufPtr,
txbdp->length, DMA_TO_DEVICE);
txbdp->lstatus = 0;
for (j = 0; j < skb_shinfo(tx_queue->tx_skbuff[i])->nr_frags;
j++) {
txbdp++;
dma_unmap_page(&priv->ofdev->dev, txbdp->bufPtr,
txbdp->length, DMA_TO_DEVICE);
}
txbdp++;
dev_kfree_skb_any(tx_queue->tx_skbuff[i]);
tx_queue->tx_skbuff[i] = NULL;
}
kfree(tx_queue->tx_skbuff);
tx_queue->tx_skbuff = NULL;
}
static void free_skb_rx_queue(struct gfar_priv_rx_q *rx_queue)
{
struct rxbd8 *rxbdp;
struct gfar_private *priv = netdev_priv(rx_queue->dev);
int i;
rxbdp = rx_queue->rx_bd_base;
for (i = 0; i < rx_queue->rx_ring_size; i++) {
if (rx_queue->rx_skbuff[i]) {
dma_unmap_single(&priv->ofdev->dev,
rxbdp->bufPtr, priv->rx_buffer_size,
DMA_FROM_DEVICE);
dev_kfree_skb_any(rx_queue->rx_skbuff[i]);
rx_queue->rx_skbuff[i] = NULL;
}
rxbdp->lstatus = 0;
rxbdp->bufPtr = 0;
rxbdp++;
}
kfree(rx_queue->rx_skbuff);
rx_queue->rx_skbuff = NULL;
}
static void free_skb_resources(struct gfar_private *priv)
{
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
int i;
for (i = 0; i < priv->num_tx_queues; i++) {
struct netdev_queue *txq;
tx_queue = priv->tx_queue[i];
txq = netdev_get_tx_queue(tx_queue->dev, tx_queue->qindex);
if (tx_queue->tx_skbuff)
free_skb_tx_queue(tx_queue);
netdev_tx_reset_queue(txq);
}
for (i = 0; i < priv->num_rx_queues; i++) {
rx_queue = priv->rx_queue[i];
if (rx_queue->rx_skbuff)
free_skb_rx_queue(rx_queue);
}
dma_free_coherent(&priv->ofdev->dev,
sizeof(struct txbd8) * priv->total_tx_ring_size +
sizeof(struct rxbd8) * priv->total_rx_ring_size,
priv->tx_queue[0]->tx_bd_base,
priv->tx_queue[0]->tx_bd_dma_base);
}
void gfar_start(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
int i = 0;
tempval = gfar_read(&regs->maccfg1);
tempval |= (MACCFG1_RX_EN | MACCFG1_TX_EN);
gfar_write(&regs->maccfg1, tempval);
tempval = gfar_read(&regs->dmactrl);
tempval |= DMACTRL_INIT_SETTINGS;
gfar_write(&regs->dmactrl, tempval);
tempval = gfar_read(&regs->dmactrl);
tempval &= ~(DMACTRL_GRS | DMACTRL_GTS);
gfar_write(&regs->dmactrl, tempval);
for (i = 0; i < priv->num_grps; i++) {
regs = priv->gfargrp[i].regs;
gfar_write(&regs->tstat, priv->gfargrp[i].tstat);
gfar_write(&regs->rstat, priv->gfargrp[i].rstat);
gfar_write(&regs->imask, IMASK_DEFAULT);
}
dev->trans_start = jiffies;
}
void gfar_configure_coalescing(struct gfar_private *priv,
unsigned long tx_mask, unsigned long rx_mask)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 __iomem *baddr;
int i = 0;
gfar_write(&regs->txic, 0);
if (likely(priv->tx_queue[0]->txcoalescing))
gfar_write(&regs->txic, priv->tx_queue[0]->txic);
gfar_write(&regs->rxic, 0);
if (unlikely(priv->rx_queue[0]->rxcoalescing))
gfar_write(&regs->rxic, priv->rx_queue[0]->rxic);
if (priv->mode == MQ_MG_MODE) {
baddr = &regs->txic0;
for_each_set_bit(i, &tx_mask, priv->num_tx_queues) {
gfar_write(baddr + i, 0);
if (likely(priv->tx_queue[i]->txcoalescing))
gfar_write(baddr + i, priv->tx_queue[i]->txic);
}
baddr = &regs->rxic0;
for_each_set_bit(i, &rx_mask, priv->num_rx_queues) {
gfar_write(baddr + i, 0);
if (likely(priv->rx_queue[i]->rxcoalescing))
gfar_write(baddr + i, priv->rx_queue[i]->rxic);
}
}
}
static int register_grp_irqs(struct gfar_priv_grp *grp)
{
struct gfar_private *priv = grp->priv;
struct net_device *dev = priv->ndev;
int err;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
if ((err = request_irq(grp->interruptError, gfar_error,
0, grp->int_name_er, grp)) < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
grp->interruptError);
goto err_irq_fail;
}
if ((err = request_irq(grp->interruptTransmit, gfar_transmit,
0, grp->int_name_tx, grp)) < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
grp->interruptTransmit);
goto tx_irq_fail;
}
if ((err = request_irq(grp->interruptReceive, gfar_receive,
0, grp->int_name_rx, grp)) < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
grp->interruptReceive);
goto rx_irq_fail;
}
} else {
if ((err = request_irq(grp->interruptTransmit, gfar_interrupt,
0, grp->int_name_tx, grp)) < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
grp->interruptTransmit);
goto err_irq_fail;
}
}
return 0;
rx_irq_fail:
free_irq(grp->interruptTransmit, grp);
tx_irq_fail:
free_irq(grp->interruptError, grp);
err_irq_fail:
return err;
}
int startup_gfar(struct net_device *ndev)
{
struct gfar_private *priv = netdev_priv(ndev);
struct gfar __iomem *regs = NULL;
int err, i, j;
for (i = 0; i < priv->num_grps; i++) {
regs= priv->gfargrp[i].regs;
gfar_write(&regs->imask, IMASK_INIT_CLEAR);
}
regs= priv->gfargrp[0].regs;
err = gfar_alloc_skb_resources(ndev);
if (err)
return err;
gfar_init_mac(ndev);
for (i = 0; i < priv->num_grps; i++) {
err = register_grp_irqs(&priv->gfargrp[i]);
if (err) {
for (j = 0; j < i; j++)
free_grp_irqs(&priv->gfargrp[j]);
goto irq_fail;
}
}
gfar_start(ndev);
phy_start(priv->phydev);
gfar_configure_coalescing(priv, 0xFF, 0xFF);
return 0;
irq_fail:
free_skb_resources(priv);
return err;
}
static int gfar_enet_open(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
int err;
enable_napi(priv);
init_registers(dev);
gfar_set_mac_address(dev);
err = init_phy(dev);
if (err) {
disable_napi(priv);
return err;
}
err = startup_gfar(dev);
if (err) {
disable_napi(priv);
return err;
}
netif_tx_start_all_queues(dev);
device_set_wakeup_enable(&dev->dev, priv->wol_en);
return err;
}
static inline struct txfcb *gfar_add_fcb(struct sk_buff *skb)
{
struct txfcb *fcb = (struct txfcb *)skb_push(skb, GMAC_FCB_LEN);
memset(fcb, 0, GMAC_FCB_LEN);
return fcb;
}
static inline void gfar_tx_checksum(struct sk_buff *skb, struct txfcb *fcb,
int fcb_length)
{
u8 flags = TXFCB_DEFAULT;
if (ip_hdr(skb)->protocol == IPPROTO_UDP) {
flags |= TXFCB_UDP;
fcb->phcs = udp_hdr(skb)->check;
} else
fcb->phcs = tcp_hdr(skb)->check;
fcb->l3os = (u16)(skb_network_offset(skb) - fcb_length);
fcb->l4os = skb_network_header_len(skb);
fcb->flags = flags;
}
void inline gfar_tx_vlan(struct sk_buff *skb, struct txfcb *fcb)
{
fcb->flags |= TXFCB_VLN;
fcb->vlctl = vlan_tx_tag_get(skb);
}
static inline struct txbd8 *skip_txbd(struct txbd8 *bdp, int stride,
struct txbd8 *base, int ring_size)
{
struct txbd8 *new_bd = bdp + stride;
return (new_bd >= (base + ring_size)) ? (new_bd - ring_size) : new_bd;
}
static inline struct txbd8 *next_txbd(struct txbd8 *bdp, struct txbd8 *base,
int ring_size)
{
return skip_txbd(bdp, 1, base, ring_size);
}
static int gfar_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar_priv_tx_q *tx_queue = NULL;
struct netdev_queue *txq;
struct gfar __iomem *regs = NULL;
struct txfcb *fcb = NULL;
struct txbd8 *txbdp, *txbdp_start, *base, *txbdp_tstamp = NULL;
u32 lstatus;
int i, rq = 0, do_tstamp = 0;
u32 bufaddr;
unsigned long flags;
unsigned int nr_frags, nr_txbds, length, fcb_length = GMAC_FCB_LEN;
if (unlikely(gfar_has_errata(priv, GFAR_ERRATA_76) &&
skb->ip_summed == CHECKSUM_PARTIAL &&
skb->len > 2500)) {
int ret;
ret = skb_checksum_help(skb);
if (ret)
return ret;
}
rq = skb->queue_mapping;
tx_queue = priv->tx_queue[rq];
txq = netdev_get_tx_queue(dev, rq);
base = tx_queue->tx_bd_base;
regs = tx_queue->grp->regs;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP &&
priv->hwts_tx_en)) {
do_tstamp = 1;
fcb_length = GMAC_FCB_LEN + GMAC_TXPAL_LEN;
}
if (((skb->ip_summed == CHECKSUM_PARTIAL) ||
vlan_tx_tag_present(skb) ||
unlikely(do_tstamp)) &&
(skb_headroom(skb) < fcb_length)) {
struct sk_buff *skb_new;
skb_new = skb_realloc_headroom(skb, fcb_length);
if (!skb_new) {
dev->stats.tx_errors++;
kfree_skb(skb);
return NETDEV_TX_OK;
}
if (skb->sk)
skb_set_owner_w(skb_new, skb->sk);
consume_skb(skb);
skb = skb_new;
}
nr_frags = skb_shinfo(skb)->nr_frags;
if (unlikely(do_tstamp))
nr_txbds = nr_frags + 2;
else
nr_txbds = nr_frags + 1;
if (nr_txbds > tx_queue->num_txbdfree) {
netif_tx_stop_queue(txq);
dev->stats.tx_fifo_errors++;
return NETDEV_TX_BUSY;
}
tx_queue->stats.tx_bytes += skb->len;
tx_queue->stats.tx_packets++;
txbdp = txbdp_start = tx_queue->cur_tx;
lstatus = txbdp->lstatus;
if (unlikely(do_tstamp))
txbdp_tstamp = txbdp = next_txbd(txbdp, base,
tx_queue->tx_ring_size);
if (nr_frags == 0) {
if (unlikely(do_tstamp))
txbdp_tstamp->lstatus |= BD_LFLAG(TXBD_LAST |
TXBD_INTERRUPT);
else
lstatus |= BD_LFLAG(TXBD_LAST | TXBD_INTERRUPT);
} else {
for (i = 0; i < nr_frags; i++) {
txbdp = next_txbd(txbdp, base, tx_queue->tx_ring_size);
length = skb_shinfo(skb)->frags[i].size;
lstatus = txbdp->lstatus | length |
BD_LFLAG(TXBD_READY);
if (i == nr_frags - 1)
lstatus |= BD_LFLAG(TXBD_LAST | TXBD_INTERRUPT);
bufaddr = skb_frag_dma_map(&priv->ofdev->dev,
&skb_shinfo(skb)->frags[i],
0,
length,
DMA_TO_DEVICE);
txbdp->bufPtr = bufaddr;
txbdp->lstatus = lstatus;
}
lstatus = txbdp_start->lstatus;
}
if (unlikely(do_tstamp)) {
skb_push(skb, GMAC_TXPAL_LEN);
memset(skb->data, 0, GMAC_TXPAL_LEN);
}
if (CHECKSUM_PARTIAL == skb->ip_summed) {
fcb = gfar_add_fcb(skb);
if (unlikely(gfar_has_errata(priv, GFAR_ERRATA_12) &&
((unsigned long)fcb % 0x20) > 0x18)) {
__skb_pull(skb, GMAC_FCB_LEN);
skb_checksum_help(skb);
} else {
lstatus |= BD_LFLAG(TXBD_TOE);
gfar_tx_checksum(skb, fcb, fcb_length);
}
}
if (vlan_tx_tag_present(skb)) {
if (unlikely(NULL == fcb)) {
fcb = gfar_add_fcb(skb);
lstatus |= BD_LFLAG(TXBD_TOE);
}
gfar_tx_vlan(skb, fcb);
}
if (unlikely(do_tstamp)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
if (fcb == NULL)
fcb = gfar_add_fcb(skb);
fcb->ptp = 1;
lstatus |= BD_LFLAG(TXBD_TOE);
}
txbdp_start->bufPtr = dma_map_single(&priv->ofdev->dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
if (unlikely(do_tstamp)) {
txbdp_tstamp->bufPtr = txbdp_start->bufPtr + fcb_length;
txbdp_tstamp->lstatus |= BD_LFLAG(TXBD_READY) |
(skb_headlen(skb) - fcb_length);
lstatus |= BD_LFLAG(TXBD_CRC | TXBD_READY) | GMAC_FCB_LEN;
} else {
lstatus |= BD_LFLAG(TXBD_CRC | TXBD_READY) | skb_headlen(skb);
}
netdev_tx_sent_queue(txq, skb->len);
spin_lock_irqsave(&tx_queue->txlock, flags);
eieio();
txbdp_start->lstatus = lstatus;
eieio();
tx_queue->tx_skbuff[tx_queue->skb_curtx] = skb;
tx_queue->skb_curtx = (tx_queue->skb_curtx + 1) &
TX_RING_MOD_MASK(tx_queue->tx_ring_size);
tx_queue->cur_tx = next_txbd(txbdp, base, tx_queue->tx_ring_size);
tx_queue->num_txbdfree -= (nr_txbds);
if (!tx_queue->num_txbdfree) {
netif_tx_stop_queue(txq);
dev->stats.tx_fifo_errors++;
}
gfar_write(&regs->tstat, TSTAT_CLEAR_THALT >> tx_queue->qindex);
spin_unlock_irqrestore(&tx_queue->txlock, flags);
return NETDEV_TX_OK;
}
static int gfar_close(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
disable_napi(priv);
cancel_work_sync(&priv->reset_task);
stop_gfar(dev);
phy_disconnect(priv->phydev);
priv->phydev = NULL;
netif_tx_stop_all_queues(dev);
return 0;
}
static int gfar_set_mac_address(struct net_device *dev)
{
gfar_set_mac_for_addr(dev, 0, dev->dev_addr);
return 0;
}
void gfar_check_rx_parser_mode(struct gfar_private *priv)
{
struct gfar __iomem *regs;
u32 tempval;
regs = priv->gfargrp[0].regs;
tempval = gfar_read(&regs->rctrl);
if (tempval & RCTRL_REQ_PARSER)
tempval |= RCTRL_PRSDEP_INIT;
else
tempval &= ~RCTRL_PRSDEP_INIT;
gfar_write(&regs->rctrl, tempval);
}
void gfar_vlan_mode(struct net_device *dev, netdev_features_t features)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = NULL;
unsigned long flags;
u32 tempval;
regs = priv->gfargrp[0].regs;
local_irq_save(flags);
lock_rx_qs(priv);
if (features & NETIF_F_HW_VLAN_TX) {
tempval = gfar_read(&regs->tctrl);
tempval |= TCTRL_VLINS;
gfar_write(&regs->tctrl, tempval);
} else {
tempval = gfar_read(&regs->tctrl);
tempval &= ~TCTRL_VLINS;
gfar_write(&regs->tctrl, tempval);
}
if (features & NETIF_F_HW_VLAN_RX) {
tempval = gfar_read(&regs->rctrl);
tempval |= (RCTRL_VLEX | RCTRL_PRSDEP_INIT);
gfar_write(&regs->rctrl, tempval);
} else {
tempval = gfar_read(&regs->rctrl);
tempval &= ~RCTRL_VLEX;
gfar_write(&regs->rctrl, tempval);
gfar_check_rx_parser_mode(priv);
}
gfar_change_mtu(dev, dev->mtu);
unlock_rx_qs(priv);
local_irq_restore(flags);
}
static int gfar_change_mtu(struct net_device *dev, int new_mtu)
{
int tempsize, tempval;
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
int oldsize = priv->rx_buffer_size;
int frame_size = new_mtu + ETH_HLEN;
if (gfar_is_vlan_on(priv))
frame_size += VLAN_HLEN;
if ((frame_size < 64) || (frame_size > JUMBO_FRAME_SIZE)) {
netif_err(priv, drv, dev, "Invalid MTU setting\n");
return -EINVAL;
}
if (gfar_uses_fcb(priv))
frame_size += GMAC_FCB_LEN;
frame_size += priv->padding;
tempsize = (frame_size & ~(INCREMENTAL_BUFFER_SIZE - 1)) +
INCREMENTAL_BUFFER_SIZE;
if ((oldsize != tempsize) && (dev->flags & IFF_UP))
stop_gfar(dev);
priv->rx_buffer_size = tempsize;
dev->mtu = new_mtu;
gfar_write(&regs->mrblr, priv->rx_buffer_size);
gfar_write(&regs->maxfrm, priv->rx_buffer_size);
tempval = gfar_read(&regs->maccfg2);
if (priv->rx_buffer_size > DEFAULT_RX_BUFFER_SIZE ||
gfar_has_errata(priv, GFAR_ERRATA_74))
tempval |= (MACCFG2_HUGEFRAME | MACCFG2_LENGTHCHECK);
else
tempval &= ~(MACCFG2_HUGEFRAME | MACCFG2_LENGTHCHECK);
gfar_write(&regs->maccfg2, tempval);
if ((oldsize != tempsize) && (dev->flags & IFF_UP))
startup_gfar(dev);
return 0;
}
static void gfar_reset_task(struct work_struct *work)
{
struct gfar_private *priv = container_of(work, struct gfar_private,
reset_task);
struct net_device *dev = priv->ndev;
if (dev->flags & IFF_UP) {
netif_tx_stop_all_queues(dev);
stop_gfar(dev);
startup_gfar(dev);
netif_tx_start_all_queues(dev);
}
netif_tx_schedule_all(dev);
}
static void gfar_timeout(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
dev->stats.tx_errors++;
schedule_work(&priv->reset_task);
}
static void gfar_align_skb(struct sk_buff *skb)
{
skb_reserve(skb, RXBUF_ALIGNMENT -
(((unsigned long) skb->data) & (RXBUF_ALIGNMENT - 1)));
}
static int gfar_clean_tx_ring(struct gfar_priv_tx_q *tx_queue)
{
struct net_device *dev = tx_queue->dev;
struct netdev_queue *txq;
struct gfar_private *priv = netdev_priv(dev);
struct gfar_priv_rx_q *rx_queue = NULL;
struct txbd8 *bdp, *next = NULL;
struct txbd8 *lbdp = NULL;
struct txbd8 *base = tx_queue->tx_bd_base;
struct sk_buff *skb;
int skb_dirtytx;
int tx_ring_size = tx_queue->tx_ring_size;
int frags = 0, nr_txbds = 0;
int i;
int howmany = 0;
int tqi = tx_queue->qindex;
unsigned int bytes_sent = 0;
u32 lstatus;
size_t buflen;
rx_queue = priv->rx_queue[tqi];
txq = netdev_get_tx_queue(dev, tqi);
bdp = tx_queue->dirty_tx;
skb_dirtytx = tx_queue->skb_dirtytx;
while ((skb = tx_queue->tx_skbuff[skb_dirtytx])) {
unsigned long flags;
frags = skb_shinfo(skb)->nr_frags;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS))
nr_txbds = frags + 2;
else
nr_txbds = frags + 1;
lbdp = skip_txbd(bdp, nr_txbds - 1, base, tx_ring_size);
lstatus = lbdp->lstatus;
if ((lstatus & BD_LFLAG(TXBD_READY)) &&
(lstatus & BD_LENGTH_MASK))
break;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS)) {
next = next_txbd(bdp, base, tx_ring_size);
buflen = next->length + GMAC_FCB_LEN + GMAC_TXPAL_LEN;
} else
buflen = bdp->length;
dma_unmap_single(&priv->ofdev->dev, bdp->bufPtr,
buflen, DMA_TO_DEVICE);
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS)) {
struct skb_shared_hwtstamps shhwtstamps;
u64 *ns = (u64*) (((u32)skb->data + 0x10) & ~0x7);
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = ns_to_ktime(*ns);
skb_pull(skb, GMAC_FCB_LEN + GMAC_TXPAL_LEN);
skb_tstamp_tx(skb, &shhwtstamps);
bdp->lstatus &= BD_LFLAG(TXBD_WRAP);
bdp = next;
}
bdp->lstatus &= BD_LFLAG(TXBD_WRAP);
bdp = next_txbd(bdp, base, tx_ring_size);
for (i = 0; i < frags; i++) {
dma_unmap_page(&priv->ofdev->dev, bdp->bufPtr,
bdp->length, DMA_TO_DEVICE);
bdp->lstatus &= BD_LFLAG(TXBD_WRAP);
bdp = next_txbd(bdp, base, tx_ring_size);
}
bytes_sent += skb->len;
dev_kfree_skb_any(skb);
tx_queue->tx_skbuff[skb_dirtytx] = NULL;
skb_dirtytx = (skb_dirtytx + 1) &
TX_RING_MOD_MASK(tx_ring_size);
howmany++;
spin_lock_irqsave(&tx_queue->txlock, flags);
tx_queue->num_txbdfree += nr_txbds;
spin_unlock_irqrestore(&tx_queue->txlock, flags);
}
if (netif_tx_queue_stopped(txq) && tx_queue->num_txbdfree)
netif_wake_subqueue(dev, tqi);
tx_queue->skb_dirtytx = skb_dirtytx;
tx_queue->dirty_tx = bdp;
netdev_tx_completed_queue(txq, howmany, bytes_sent);
return howmany;
}
static void gfar_schedule_cleanup(struct gfar_priv_grp *gfargrp)
{
unsigned long flags;
spin_lock_irqsave(&gfargrp->grplock, flags);
if (napi_schedule_prep(&gfargrp->napi)) {
gfar_write(&gfargrp->regs->imask, IMASK_RTX_DISABLED);
__napi_schedule(&gfargrp->napi);
} else {
gfar_write(&gfargrp->regs->ievent, IEVENT_RTX_MASK);
}
spin_unlock_irqrestore(&gfargrp->grplock, flags);
}
static irqreturn_t gfar_transmit(int irq, void *grp_id)
{
gfar_schedule_cleanup((struct gfar_priv_grp *)grp_id);
return IRQ_HANDLED;
}
static void gfar_new_rxbdp(struct gfar_priv_rx_q *rx_queue, struct rxbd8 *bdp,
struct sk_buff *skb)
{
struct net_device *dev = rx_queue->dev;
struct gfar_private *priv = netdev_priv(dev);
dma_addr_t buf;
buf = dma_map_single(&priv->ofdev->dev, skb->data,
priv->rx_buffer_size, DMA_FROM_DEVICE);
gfar_init_rxbdp(rx_queue, bdp, buf);
}
static struct sk_buff *gfar_alloc_skb(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, priv->rx_buffer_size + RXBUF_ALIGNMENT);
if (!skb)
return NULL;
gfar_align_skb(skb);
return skb;
}
struct sk_buff *gfar_new_skb(struct net_device *dev)
{
return gfar_alloc_skb(dev);
}
static inline void count_errors(unsigned short status, struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct gfar_extra_stats *estats = &priv->extra_stats;
if (status & RXBD_TRUNCATED) {
stats->rx_length_errors++;
estats->rx_trunc++;
return;
}
if (status & (RXBD_LARGE | RXBD_SHORT)) {
stats->rx_length_errors++;
if (status & RXBD_LARGE)
estats->rx_large++;
else
estats->rx_short++;
}
if (status & RXBD_NONOCTET) {
stats->rx_frame_errors++;
estats->rx_nonoctet++;
}
if (status & RXBD_CRCERR) {
estats->rx_crcerr++;
stats->rx_crc_errors++;
}
if (status & RXBD_OVERRUN) {
estats->rx_overrun++;
stats->rx_crc_errors++;
}
}
irqreturn_t gfar_receive(int irq, void *grp_id)
{
gfar_schedule_cleanup((struct gfar_priv_grp *)grp_id);
return IRQ_HANDLED;
}
static inline void gfar_rx_checksum(struct sk_buff *skb, struct rxfcb *fcb)
{
if ((fcb->flags & RXFCB_CSUM_MASK) == (RXFCB_CIP | RXFCB_CTU))
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb_checksum_none_assert(skb);
}
static int gfar_process_frame(struct net_device *dev, struct sk_buff *skb,
int amount_pull, struct napi_struct *napi)
{
struct gfar_private *priv = netdev_priv(dev);
struct rxfcb *fcb = NULL;
gro_result_t ret;
fcb = (struct rxfcb *)skb->data;
if (amount_pull) {
skb_record_rx_queue(skb, fcb->rq);
skb_pull(skb, amount_pull);
}
if (priv->hwts_rx_en) {
struct skb_shared_hwtstamps *shhwtstamps = skb_hwtstamps(skb);
u64 *ns = (u64 *) skb->data;
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
shhwtstamps->hwtstamp = ns_to_ktime(*ns);
}
if (priv->padding)
skb_pull(skb, priv->padding);
if (dev->features & NETIF_F_RXCSUM)
gfar_rx_checksum(skb, fcb);
skb->protocol = eth_type_trans(skb, dev);
if (dev->features & NETIF_F_HW_VLAN_RX &&
fcb->flags & RXFCB_VLN)
__vlan_hwaccel_put_tag(skb, fcb->vlctl);
ret = napi_gro_receive(napi, skb);
if (GRO_DROP == ret)
priv->extra_stats.kernel_dropped++;
return 0;
}
int gfar_clean_rx_ring(struct gfar_priv_rx_q *rx_queue, int rx_work_limit)
{
struct net_device *dev = rx_queue->dev;
struct rxbd8 *bdp, *base;
struct sk_buff *skb;
int pkt_len;
int amount_pull;
int howmany = 0;
struct gfar_private *priv = netdev_priv(dev);
bdp = rx_queue->cur_rx;
base = rx_queue->rx_bd_base;
amount_pull = (gfar_uses_fcb(priv) ? GMAC_FCB_LEN : 0);
while (!((bdp->status & RXBD_EMPTY) || (--rx_work_limit < 0))) {
struct sk_buff *newskb;
rmb();
newskb = gfar_new_skb(dev);
skb = rx_queue->rx_skbuff[rx_queue->skb_currx];
dma_unmap_single(&priv->ofdev->dev, bdp->bufPtr,
priv->rx_buffer_size, DMA_FROM_DEVICE);
if (unlikely(!(bdp->status & RXBD_ERR) &&
bdp->length > priv->rx_buffer_size))
bdp->status = RXBD_LARGE;
if (unlikely(!newskb || !(bdp->status & RXBD_LAST) ||
bdp->status & RXBD_ERR)) {
count_errors(bdp->status, dev);
if (unlikely(!newskb))
newskb = skb;
else if (skb)
dev_kfree_skb(skb);
} else {
rx_queue->stats.rx_packets++;
howmany++;
if (likely(skb)) {
pkt_len = bdp->length - ETH_FCS_LEN;
skb_put(skb, pkt_len);
rx_queue->stats.rx_bytes += pkt_len;
skb_record_rx_queue(skb, rx_queue->qindex);
gfar_process_frame(dev, skb, amount_pull,
&rx_queue->grp->napi);
} else {
netif_warn(priv, rx_err, dev, "Missing skb!\n");
rx_queue->stats.rx_dropped++;
priv->extra_stats.rx_skbmissing++;
}
}
rx_queue->rx_skbuff[rx_queue->skb_currx] = newskb;
gfar_new_rxbdp(rx_queue, bdp, newskb);
bdp = next_bd(bdp, base, rx_queue->rx_ring_size);
rx_queue->skb_currx = (rx_queue->skb_currx + 1) &
RX_RING_MOD_MASK(rx_queue->rx_ring_size);
}
rx_queue->cur_rx = bdp;
return howmany;
}
static int gfar_poll(struct napi_struct *napi, int budget)
{
struct gfar_priv_grp *gfargrp =
container_of(napi, struct gfar_priv_grp, napi);
struct gfar_private *priv = gfargrp->priv;
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
int rx_cleaned = 0, budget_per_queue = 0, rx_cleaned_per_queue = 0;
int tx_cleaned = 0, i, left_over_budget = budget;
unsigned long serviced_queues = 0;
int num_queues = 0;
num_queues = gfargrp->num_rx_queues;
budget_per_queue = budget/num_queues;
gfar_write(&regs->ievent, IEVENT_RTX_MASK);
while (num_queues && left_over_budget) {
budget_per_queue = left_over_budget/num_queues;
left_over_budget = 0;
for_each_set_bit(i, &gfargrp->rx_bit_map, priv->num_rx_queues) {
if (test_bit(i, &serviced_queues))
continue;
rx_queue = priv->rx_queue[i];
tx_queue = priv->tx_queue[rx_queue->qindex];
tx_cleaned += gfar_clean_tx_ring(tx_queue);
rx_cleaned_per_queue =
gfar_clean_rx_ring(rx_queue, budget_per_queue);
rx_cleaned += rx_cleaned_per_queue;
if (rx_cleaned_per_queue < budget_per_queue) {
left_over_budget = left_over_budget +
(budget_per_queue -
rx_cleaned_per_queue);
set_bit(i, &serviced_queues);
num_queues--;
}
}
}
if (tx_cleaned)
return budget;
if (rx_cleaned < budget) {
napi_complete(napi);
gfar_write(&regs->rstat, gfargrp->rstat);
gfar_write(&regs->imask, IMASK_DEFAULT);
gfar_configure_coalescing(priv, gfargrp->rx_bit_map,
gfargrp->tx_bit_map);
}
return rx_cleaned;
}
static void gfar_netpoll(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
int i;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
for (i = 0; i < priv->num_grps; i++) {
disable_irq(priv->gfargrp[i].interruptTransmit);
disable_irq(priv->gfargrp[i].interruptReceive);
disable_irq(priv->gfargrp[i].interruptError);
gfar_interrupt(priv->gfargrp[i].interruptTransmit,
&priv->gfargrp[i]);
enable_irq(priv->gfargrp[i].interruptError);
enable_irq(priv->gfargrp[i].interruptReceive);
enable_irq(priv->gfargrp[i].interruptTransmit);
}
} else {
for (i = 0; i < priv->num_grps; i++) {
disable_irq(priv->gfargrp[i].interruptTransmit);
gfar_interrupt(priv->gfargrp[i].interruptTransmit,
&priv->gfargrp[i]);
enable_irq(priv->gfargrp[i].interruptTransmit);
}
}
}
static irqreturn_t gfar_interrupt(int irq, void *grp_id)
{
struct gfar_priv_grp *gfargrp = grp_id;
u32 events = gfar_read(&gfargrp->regs->ievent);
if (events & IEVENT_RX_MASK)
gfar_receive(irq, grp_id);
if (events & IEVENT_TX_MASK)
gfar_transmit(irq, grp_id);
if (events & IEVENT_ERR_MASK)
gfar_error(irq, grp_id);
return IRQ_HANDLED;
}
static void adjust_link(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
unsigned long flags;
struct phy_device *phydev = priv->phydev;
int new_state = 0;
local_irq_save(flags);
lock_tx_qs(priv);
if (phydev->link) {
u32 tempval = gfar_read(&regs->maccfg2);
u32 ecntrl = gfar_read(&regs->ecntrl);
if (phydev->duplex != priv->oldduplex) {
new_state = 1;
if (!(phydev->duplex))
tempval &= ~(MACCFG2_FULL_DUPLEX);
else
tempval |= MACCFG2_FULL_DUPLEX;
priv->oldduplex = phydev->duplex;
}
if (phydev->speed != priv->oldspeed) {
new_state = 1;
switch (phydev->speed) {
case 1000:
tempval =
((tempval & ~(MACCFG2_IF)) | MACCFG2_GMII);
ecntrl &= ~(ECNTRL_R100);
break;
case 100:
case 10:
tempval =
((tempval & ~(MACCFG2_IF)) | MACCFG2_MII);
if (phydev->speed == SPEED_100)
ecntrl |= ECNTRL_R100;
else
ecntrl &= ~(ECNTRL_R100);
break;
default:
netif_warn(priv, link, dev,
"Ack! Speed (%d) is not 10/100/1000!\n",
phydev->speed);
break;
}
priv->oldspeed = phydev->speed;
}
gfar_write(&regs->maccfg2, tempval);
gfar_write(&regs->ecntrl, ecntrl);
if (!priv->oldlink) {
new_state = 1;
priv->oldlink = 1;
}
} else if (priv->oldlink) {
new_state = 1;
priv->oldlink = 0;
priv->oldspeed = 0;
priv->oldduplex = -1;
}
if (new_state && netif_msg_link(priv))
phy_print_status(phydev);
unlock_tx_qs(priv);
local_irq_restore(flags);
}
static void gfar_set_multi(struct net_device *dev)
{
struct netdev_hw_addr *ha;
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
if (dev->flags & IFF_PROMISC) {
tempval = gfar_read(&regs->rctrl);
tempval |= RCTRL_PROM;
gfar_write(&regs->rctrl, tempval);
} else {
tempval = gfar_read(&regs->rctrl);
tempval &= ~(RCTRL_PROM);
gfar_write(&regs->rctrl, tempval);
}
if (dev->flags & IFF_ALLMULTI) {
gfar_write(&regs->igaddr0, 0xffffffff);
gfar_write(&regs->igaddr1, 0xffffffff);
gfar_write(&regs->igaddr2, 0xffffffff);
gfar_write(&regs->igaddr3, 0xffffffff);
gfar_write(&regs->igaddr4, 0xffffffff);
gfar_write(&regs->igaddr5, 0xffffffff);
gfar_write(&regs->igaddr6, 0xffffffff);
gfar_write(&regs->igaddr7, 0xffffffff);
gfar_write(&regs->gaddr0, 0xffffffff);
gfar_write(&regs->gaddr1, 0xffffffff);
gfar_write(&regs->gaddr2, 0xffffffff);
gfar_write(&regs->gaddr3, 0xffffffff);
gfar_write(&regs->gaddr4, 0xffffffff);
gfar_write(&regs->gaddr5, 0xffffffff);
gfar_write(&regs->gaddr6, 0xffffffff);
gfar_write(&regs->gaddr7, 0xffffffff);
} else {
int em_num;
int idx;
gfar_write(&regs->igaddr0, 0x0);
gfar_write(&regs->igaddr1, 0x0);
gfar_write(&regs->igaddr2, 0x0);
gfar_write(&regs->igaddr3, 0x0);
gfar_write(&regs->igaddr4, 0x0);
gfar_write(&regs->igaddr5, 0x0);
gfar_write(&regs->igaddr6, 0x0);
gfar_write(&regs->igaddr7, 0x0);
gfar_write(&regs->gaddr0, 0x0);
gfar_write(&regs->gaddr1, 0x0);
gfar_write(&regs->gaddr2, 0x0);
gfar_write(&regs->gaddr3, 0x0);
gfar_write(&regs->gaddr4, 0x0);
gfar_write(&regs->gaddr5, 0x0);
gfar_write(&regs->gaddr6, 0x0);
gfar_write(&regs->gaddr7, 0x0);
if (priv->extended_hash) {
em_num = GFAR_EM_NUM + 1;
gfar_clear_exact_match(dev);
idx = 1;
} else {
idx = 0;
em_num = 0;
}
if (netdev_mc_empty(dev))
return;
netdev_for_each_mc_addr(ha, dev) {
if (idx < em_num) {
gfar_set_mac_for_addr(dev, idx, ha->addr);
idx++;
} else
gfar_set_hash_for_addr(dev, ha->addr);
}
}
}
static void gfar_clear_exact_match(struct net_device *dev)
{
int idx;
static const u8 zero_arr[ETH_ALEN] = {0, 0, 0, 0, 0, 0};
for (idx = 1; idx < GFAR_EM_NUM + 1; idx++)
gfar_set_mac_for_addr(dev, idx, zero_arr);
}
static void gfar_set_hash_for_addr(struct net_device *dev, u8 *addr)
{
u32 tempval;
struct gfar_private *priv = netdev_priv(dev);
u32 result = ether_crc(ETH_ALEN, addr);
int width = priv->hash_width;
u8 whichbit = (result >> (32 - width)) & 0x1f;
u8 whichreg = result >> (32 - width + 5);
u32 value = (1 << (31-whichbit));
tempval = gfar_read(priv->hash_regs[whichreg]);
tempval |= value;
gfar_write(priv->hash_regs[whichreg], tempval);
}
static void gfar_set_mac_for_addr(struct net_device *dev, int num,
const u8 *addr)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
int idx;
char tmpbuf[ETH_ALEN];
u32 tempval;
u32 __iomem *macptr = &regs->macstnaddr1;
macptr += num*2;
for (idx = 0; idx < ETH_ALEN; idx++)
tmpbuf[ETH_ALEN - 1 - idx] = addr[idx];
gfar_write(macptr, *((u32 *) (tmpbuf)));
tempval = *((u32 *) (tmpbuf + 4));
gfar_write(macptr+1, tempval);
}
static irqreturn_t gfar_error(int irq, void *grp_id)
{
struct gfar_priv_grp *gfargrp = grp_id;
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_private *priv= gfargrp->priv;
struct net_device *dev = priv->ndev;
u32 events = gfar_read(&regs->ievent);
gfar_write(&regs->ievent, events & IEVENT_ERR_MASK);
if ((priv->device_flags & FSL_GIANFAR_DEV_HAS_MAGIC_PACKET) &&
(events & IEVENT_MAG))
events &= ~IEVENT_MAG;
if (netif_msg_rx_err(priv) || netif_msg_tx_err(priv))
netdev_dbg(dev,
"error interrupt (ievent=0x%08x imask=0x%08x)\n",
events, gfar_read(&regs->imask));
if (events & IEVENT_TXE) {
dev->stats.tx_errors++;
if (events & IEVENT_LC)
dev->stats.tx_window_errors++;
if (events & IEVENT_CRL)
dev->stats.tx_aborted_errors++;
if (events & IEVENT_XFUN) {
unsigned long flags;
netif_dbg(priv, tx_err, dev,
"TX FIFO underrun, packet dropped\n");
dev->stats.tx_dropped++;
priv->extra_stats.tx_underrun++;
local_irq_save(flags);
lock_tx_qs(priv);
gfar_write(&regs->tstat, gfargrp->tstat);
unlock_tx_qs(priv);
local_irq_restore(flags);
}
netif_dbg(priv, tx_err, dev, "Transmit Error\n");
}
if (events & IEVENT_BSY) {
dev->stats.rx_errors++;
priv->extra_stats.rx_bsy++;
gfar_receive(irq, grp_id);
netif_dbg(priv, rx_err, dev, "busy error (rstat: %x)\n",
gfar_read(&regs->rstat));
}
if (events & IEVENT_BABR) {
dev->stats.rx_errors++;
priv->extra_stats.rx_babr++;
netif_dbg(priv, rx_err, dev, "babbling RX error\n");
}
if (events & IEVENT_EBERR) {
priv->extra_stats.eberr++;
netif_dbg(priv, rx_err, dev, "bus error\n");
}
if (events & IEVENT_RXC)
netif_dbg(priv, rx_status, dev, "control frame\n");
if (events & IEVENT_BABT) {
priv->extra_stats.tx_babt++;
netif_dbg(priv, tx_err, dev, "babbling TX error\n");
}
return IRQ_HANDLED;
}
