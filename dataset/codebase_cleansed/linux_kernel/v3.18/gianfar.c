static void gfar_init_rxbdp(struct gfar_priv_rx_q *rx_queue, struct rxbd8 *bdp,
dma_addr_t buf)
{
u32 lstatus;
bdp->bufPtr = buf;
lstatus = BD_LFLAG(RXBD_EMPTY | RXBD_INTERRUPT);
if (bdp == rx_queue->rx_bd_base + rx_queue->rx_ring_size - 1)
lstatus |= BD_LFLAG(RXBD_WRAP);
gfar_wmb();
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
struct device *dev = priv->dev;
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
priv->total_tx_ring_size = 0;
for (i = 0; i < priv->num_tx_queues; i++)
priv->total_tx_ring_size += priv->tx_queue[i]->tx_ring_size;
priv->total_rx_ring_size = 0;
for (i = 0; i < priv->num_rx_queues; i++)
priv->total_rx_ring_size += priv->rx_queue[i]->rx_ring_size;
vaddr = dma_alloc_coherent(dev,
(priv->total_tx_ring_size *
sizeof(struct txbd8)) +
(priv->total_rx_ring_size *
sizeof(struct rxbd8)),
&addr, GFP_KERNEL);
if (!vaddr)
return -ENOMEM;
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
tx_queue->tx_skbuff =
kmalloc_array(tx_queue->tx_ring_size,
sizeof(*tx_queue->tx_skbuff),
GFP_KERNEL);
if (!tx_queue->tx_skbuff)
goto cleanup;
for (k = 0; k < tx_queue->tx_ring_size; k++)
tx_queue->tx_skbuff[k] = NULL;
}
for (i = 0; i < priv->num_rx_queues; i++) {
rx_queue = priv->rx_queue[i];
rx_queue->rx_skbuff =
kmalloc_array(rx_queue->rx_ring_size,
sizeof(*rx_queue->rx_skbuff),
GFP_KERNEL);
if (!rx_queue->rx_skbuff)
goto cleanup;
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
static void gfar_rx_buff_size_config(struct gfar_private *priv)
{
int frame_size = priv->ndev->mtu + ETH_HLEN + ETH_FCS_LEN;
priv->uses_rxfcb = 0;
if (priv->ndev->features & (NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_RX))
priv->uses_rxfcb = 1;
if (priv->hwts_rx_en)
priv->uses_rxfcb = 1;
if (priv->uses_rxfcb)
frame_size += GMAC_FCB_LEN;
frame_size += priv->padding;
frame_size = (frame_size & ~(INCREMENTAL_BUFFER_SIZE - 1)) +
INCREMENTAL_BUFFER_SIZE;
priv->rx_buffer_size = frame_size;
}
static void gfar_mac_rx_config(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 rctrl = 0;
if (priv->rx_filer_enable) {
rctrl |= RCTRL_FILREN;
if (priv->poll_mode == GFAR_SQ_POLLING)
gfar_write(&regs->rir0, DEFAULT_2RXQ_RIR0);
else
gfar_write(&regs->rir0, DEFAULT_8RXQ_RIR0);
}
if (priv->ndev->flags & IFF_PROMISC)
rctrl |= RCTRL_PROM;
if (priv->ndev->features & NETIF_F_RXCSUM)
rctrl |= RCTRL_CHECKSUMMING;
if (priv->extended_hash)
rctrl |= RCTRL_EXTHASH | RCTRL_EMEN;
if (priv->padding) {
rctrl &= ~RCTRL_PAL_MASK;
rctrl |= RCTRL_PADDING(priv->padding);
}
if (priv->hwts_rx_en)
rctrl |= RCTRL_PRSDEP_INIT | RCTRL_TS_ENABLE;
if (priv->ndev->features & NETIF_F_HW_VLAN_CTAG_RX)
rctrl |= RCTRL_VLEX | RCTRL_PRSDEP_INIT;
gfar_write(&regs->rctrl, rctrl);
}
static void gfar_mac_tx_config(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tctrl = 0;
if (priv->ndev->features & NETIF_F_IP_CSUM)
tctrl |= TCTRL_INIT_CSUM;
if (priv->prio_sched_en)
tctrl |= TCTRL_TXSCHED_PRIO;
else {
tctrl |= TCTRL_TXSCHED_WRRS;
gfar_write(&regs->tr03wt, DEFAULT_WRRS_WEIGHT);
gfar_write(&regs->tr47wt, DEFAULT_WRRS_WEIGHT);
}
if (priv->ndev->features & NETIF_F_HW_VLAN_CTAG_TX)
tctrl |= TCTRL_VLINS;
gfar_write(&regs->tctrl, tctrl);
}
static void gfar_configure_coalescing(struct gfar_private *priv,
unsigned long tx_mask, unsigned long rx_mask)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 __iomem *baddr;
if (priv->mode == MQ_MG_MODE) {
int i = 0;
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
} else {
gfar_write(&regs->txic, 0);
if (likely(priv->tx_queue[0]->txcoalescing))
gfar_write(&regs->txic, priv->tx_queue[0]->txic);
gfar_write(&regs->rxic, 0);
if (unlikely(priv->rx_queue[0]->rxcoalescing))
gfar_write(&regs->rxic, priv->rx_queue[0]->rxic);
}
}
void gfar_configure_coalescing_all(struct gfar_private *priv)
{
gfar_configure_coalescing(priv, 0xFF, 0xFF);
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
static void gfar_ints_disable(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++) {
struct gfar __iomem *regs = priv->gfargrp[i].regs;
gfar_write(&regs->ievent, IEVENT_INIT_CLEAR);
gfar_write(&regs->imask, IMASK_INIT_CLEAR);
}
}
static void gfar_ints_enable(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++) {
struct gfar __iomem *regs = priv->gfargrp[i].regs;
gfar_write(&regs->imask, IMASK_DEFAULT);
}
}
void lock_tx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
spin_lock(&priv->tx_queue[i]->txlock);
}
void unlock_tx_qs(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
spin_unlock(&priv->tx_queue[i]->txlock);
}
static int gfar_alloc_tx_queues(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++) {
priv->tx_queue[i] = kzalloc(sizeof(struct gfar_priv_tx_q),
GFP_KERNEL);
if (!priv->tx_queue[i])
return -ENOMEM;
priv->tx_queue[i]->tx_skbuff = NULL;
priv->tx_queue[i]->qindex = i;
priv->tx_queue[i]->dev = priv->ndev;
spin_lock_init(&(priv->tx_queue[i]->txlock));
}
return 0;
}
static int gfar_alloc_rx_queues(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_rx_queues; i++) {
priv->rx_queue[i] = kzalloc(sizeof(struct gfar_priv_rx_q),
GFP_KERNEL);
if (!priv->rx_queue[i])
return -ENOMEM;
priv->rx_queue[i]->rx_skbuff = NULL;
priv->rx_queue[i]->qindex = i;
priv->rx_queue[i]->dev = priv->ndev;
}
return 0;
}
static void gfar_free_tx_queues(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_tx_queues; i++)
kfree(priv->tx_queue[i]);
}
static void gfar_free_rx_queues(struct gfar_private *priv)
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
static void free_gfar_dev(struct gfar_private *priv)
{
int i, j;
for (i = 0; i < priv->num_grps; i++)
for (j = 0; j < GFAR_NUM_IRQS; j++) {
kfree(priv->gfargrp[i].irqinfo[j]);
priv->gfargrp[i].irqinfo[j] = NULL;
}
free_netdev(priv->ndev);
}
static void disable_napi(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++) {
napi_disable(&priv->gfargrp[i].napi_rx);
napi_disable(&priv->gfargrp[i].napi_tx);
}
}
static void enable_napi(struct gfar_private *priv)
{
int i;
for (i = 0; i < priv->num_grps; i++) {
napi_enable(&priv->gfargrp[i].napi_rx);
napi_enable(&priv->gfargrp[i].napi_tx);
}
}
static int gfar_parse_group(struct device_node *np,
struct gfar_private *priv, const char *model)
{
struct gfar_priv_grp *grp = &priv->gfargrp[priv->num_grps];
int i;
for (i = 0; i < GFAR_NUM_IRQS; i++) {
grp->irqinfo[i] = kzalloc(sizeof(struct gfar_irqinfo),
GFP_KERNEL);
if (!grp->irqinfo[i])
return -ENOMEM;
}
grp->regs = of_iomap(np, 0);
if (!grp->regs)
return -ENOMEM;
gfar_irq(grp, TX)->irq = irq_of_parse_and_map(np, 0);
if (model && strcasecmp(model, "FEC")) {
gfar_irq(grp, RX)->irq = irq_of_parse_and_map(np, 1);
gfar_irq(grp, ER)->irq = irq_of_parse_and_map(np, 2);
if (gfar_irq(grp, TX)->irq == NO_IRQ ||
gfar_irq(grp, RX)->irq == NO_IRQ ||
gfar_irq(grp, ER)->irq == NO_IRQ)
return -EINVAL;
}
grp->priv = priv;
spin_lock_init(&grp->grplock);
if (priv->mode == MQ_MG_MODE) {
u32 *rxq_mask, *txq_mask;
rxq_mask = (u32 *)of_get_property(np, "fsl,rx-bit-map", NULL);
txq_mask = (u32 *)of_get_property(np, "fsl,tx-bit-map", NULL);
if (priv->poll_mode == GFAR_SQ_POLLING) {
grp->rx_bit_map = (DEFAULT_MAPPING >> priv->num_grps);
grp->tx_bit_map = (DEFAULT_MAPPING >> priv->num_grps);
} else {
grp->rx_bit_map = rxq_mask ?
*rxq_mask : (DEFAULT_MAPPING >> priv->num_grps);
grp->tx_bit_map = txq_mask ?
*txq_mask : (DEFAULT_MAPPING >> priv->num_grps);
}
} else {
grp->rx_bit_map = 0xFF;
grp->tx_bit_map = 0xFF;
}
grp->rx_bit_map = bitrev8(grp->rx_bit_map);
grp->tx_bit_map = bitrev8(grp->tx_bit_map);
for_each_set_bit(i, &grp->rx_bit_map, priv->num_rx_queues) {
if (!grp->rx_queue)
grp->rx_queue = priv->rx_queue[i];
grp->num_rx_queues++;
grp->rstat |= (RSTAT_CLEAR_RHALT >> i);
priv->rqueue |= ((RQUEUE_EN0 | RQUEUE_EX0) >> i);
priv->rx_queue[i]->grp = grp;
}
for_each_set_bit(i, &grp->tx_bit_map, priv->num_tx_queues) {
if (!grp->tx_queue)
grp->tx_queue = priv->tx_queue[i];
grp->num_tx_queues++;
grp->tstat |= (TSTAT_CLEAR_THALT >> i);
priv->tqueue |= (TQUEUE_EN0 >> i);
priv->tx_queue[i]->grp = grp;
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
unsigned short mode, poll_mode;
if (!np || !of_device_is_available(np))
return -ENODEV;
if (of_device_is_compatible(np, "fsl,etsec2")) {
mode = MQ_MG_MODE;
poll_mode = GFAR_SQ_POLLING;
} else {
mode = SQ_SG_MODE;
poll_mode = GFAR_SQ_POLLING;
}
tx_queues = (u32 *)of_get_property(np, "fsl,num_tx_queues", NULL);
rx_queues = (u32 *)of_get_property(np, "fsl,num_rx_queues", NULL);
if (mode == SQ_SG_MODE) {
num_tx_qs = 1;
num_rx_qs = 1;
} else {
unsigned int num_grps = of_get_available_child_count(np);
if (num_grps == 0 || num_grps > MAXGROUPS) {
dev_err(&ofdev->dev, "Invalid # of int groups(%d)\n",
num_grps);
pr_err("Cannot do alloc_etherdev, aborting\n");
return -EINVAL;
}
if (poll_mode == GFAR_SQ_POLLING) {
num_tx_qs = num_grps;
num_rx_qs = num_grps;
} else {
num_tx_qs = tx_queues ? *tx_queues : 1;
num_rx_qs = rx_queues ? *rx_queues : 1;
}
}
if (num_tx_qs > MAX_TX_QS) {
pr_err("num_tx_qs(=%d) greater than MAX_TX_QS(=%d)\n",
num_tx_qs, MAX_TX_QS);
pr_err("Cannot do alloc_etherdev, aborting\n");
return -EINVAL;
}
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
priv->ndev = dev;
priv->mode = mode;
priv->poll_mode = poll_mode;
priv->num_tx_queues = num_tx_qs;
netif_set_real_num_rx_queues(dev, num_rx_qs);
priv->num_rx_queues = num_rx_qs;
err = gfar_alloc_tx_queues(priv);
if (err)
goto tx_alloc_failed;
err = gfar_alloc_rx_queues(priv);
if (err)
goto rx_alloc_failed;
INIT_LIST_HEAD(&priv->rx_list.list);
priv->rx_list.count = 0;
mutex_init(&priv->rx_queue_access);
model = of_get_property(np, "model", NULL);
for (i = 0; i < MAXGROUPS; i++)
priv->gfargrp[i].regs = NULL;
if (priv->mode == MQ_MG_MODE) {
for_each_child_of_node(np, child) {
err = gfar_parse_group(child, priv, model);
if (err)
goto err_grp_init;
}
} else {
err = gfar_parse_group(np, priv, model);
if (err)
goto err_grp_init;
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
priv->device_flags |= FSL_GIANFAR_DEV_HAS_GIGABIT |
FSL_GIANFAR_DEV_HAS_COALESCE |
FSL_GIANFAR_DEV_HAS_RMON |
FSL_GIANFAR_DEV_HAS_MULTI_INTR;
if (model && !strcasecmp(model, "eTSEC"))
priv->device_flags |= FSL_GIANFAR_DEV_HAS_GIGABIT |
FSL_GIANFAR_DEV_HAS_COALESCE |
FSL_GIANFAR_DEV_HAS_RMON |
FSL_GIANFAR_DEV_HAS_MULTI_INTR |
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
if (!priv->phy_node && of_phy_is_fixed_link(np)) {
err = of_phy_register_fixed_link(np);
if (err)
goto err_grp_init;
priv->phy_node = of_node_get(np);
}
priv->tbi_node = of_parse_phandle(np, "tbi-handle", 0);
return 0;
err_grp_init:
unmap_group_regs(priv);
rx_alloc_failed:
gfar_free_rx_queues(priv);
tx_alloc_failed:
gfar_free_tx_queues(priv);
free_gfar_dev(priv);
return err;
}
static int gfar_hwtstamp_set(struct net_device *netdev, struct ifreq *ifr)
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
priv->hwts_rx_en = 0;
reset_gfar(netdev);
}
break;
default:
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER))
return -ERANGE;
if (!priv->hwts_rx_en) {
priv->hwts_rx_en = 1;
reset_gfar(netdev);
}
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
}
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int gfar_hwtstamp_get(struct net_device *netdev, struct ifreq *ifr)
{
struct hwtstamp_config config;
struct gfar_private *priv = netdev_priv(netdev);
config.flags = 0;
config.tx_type = priv->hwts_tx_en ? HWTSTAMP_TX_ON : HWTSTAMP_TX_OFF;
config.rx_filter = (priv->hwts_rx_en ?
HWTSTAMP_FILTER_ALL : HWTSTAMP_FILTER_NONE);
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int gfar_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct gfar_private *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (cmd == SIOCSHWTSTAMP)
return gfar_hwtstamp_set(dev, rq);
if (cmd == SIOCGHWTSTAMP)
return gfar_hwtstamp_get(dev, rq);
if (!priv->phydev)
return -ENODEV;
return phy_mii_ioctl(priv->phydev, rq, cmd);
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
static void __gfar_detect_errata_83xx(struct gfar_private *priv)
{
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
if (pvr == 0x80850010 && mod == 0x80b0 && rev < 0x0020)
priv->errata |= GFAR_ERRATA_12;
}
static void __gfar_detect_errata_85xx(struct gfar_private *priv)
{
unsigned int svr = mfspr(SPRN_SVR);
if ((SVR_SOC_VER(svr) == SVR_8548) && (SVR_REV(svr) == 0x20))
priv->errata |= GFAR_ERRATA_12;
if (((SVR_SOC_VER(svr) == SVR_P2020) && (SVR_REV(svr) < 0x20)) ||
((SVR_SOC_VER(svr) == SVR_P2010) && (SVR_REV(svr) < 0x20)))
priv->errata |= GFAR_ERRATA_76;
}
static void gfar_detect_errata(struct gfar_private *priv)
{
struct device *dev = &priv->ofdev->dev;
priv->errata |= GFAR_ERRATA_A002;
#ifdef CONFIG_PPC
if (pvr_version_is(PVR_VER_E500V1) || pvr_version_is(PVR_VER_E500V2))
__gfar_detect_errata_85xx(priv);
else
__gfar_detect_errata_83xx(priv);
#endif
if (priv->errata)
dev_info(dev, "enabled errata workarounds, flags: 0x%x\n",
priv->errata);
}
void gfar_mac_reset(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
gfar_write(&regs->maccfg1, MACCFG1_SOFT_RESET);
udelay(3);
gfar_write(&regs->maccfg1, 0);
udelay(3);
gfar_rx_buff_size_config(priv);
gfar_write(&regs->maxfrm, priv->rx_buffer_size);
gfar_write(&regs->mrblr, priv->rx_buffer_size);
gfar_write(&regs->minflr, MINFLR_INIT_SETTINGS);
tempval = MACCFG2_INIT_SETTINGS;
if (priv->rx_buffer_size > DEFAULT_RX_BUFFER_SIZE ||
gfar_has_errata(priv, GFAR_ERRATA_74))
tempval |= MACCFG2_HUGEFRAME | MACCFG2_LENGTHCHECK;
gfar_write(&regs->maccfg2, tempval);
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
if (priv->extended_hash)
gfar_clear_exact_match(priv->ndev);
gfar_mac_rx_config(priv);
gfar_mac_tx_config(priv);
gfar_set_mac_address(priv->ndev);
gfar_set_multi(priv->ndev);
gfar_ints_disable(priv);
gfar_configure_coalescing_all(priv);
}
static void gfar_hw_init(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 attrs;
gfar_halt(priv);
gfar_mac_reset(priv);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_RMON) {
memset_io(&(regs->rmon), 0, sizeof(struct rmon_mib));
gfar_write(&regs->rmon.cam1, 0xffffffff);
gfar_write(&regs->rmon.cam2, 0xffffffff);
}
gfar_write(&regs->ecntrl, ECNTRL_INIT_SETTINGS);
attrs = ATTRELI_EL(priv->rx_stash_size) |
ATTRELI_EI(priv->rx_stash_index);
gfar_write(&regs->attreli, attrs);
attrs = ATTR_INIT_SETTINGS;
if (priv->bd_stash_en)
attrs |= ATTR_BDSTASH;
if (priv->rx_stash_size != 0)
attrs |= ATTR_BUFSTASH;
gfar_write(&regs->attr, attrs);
gfar_write(&regs->fifo_tx_thr, DEFAULT_FIFO_TX_THR);
gfar_write(&regs->fifo_tx_starve, DEFAULT_FIFO_TX_STARVE);
gfar_write(&regs->fifo_tx_starve_shutoff, DEFAULT_FIFO_TX_STARVE_OFF);
if (priv->num_grps > 1)
gfar_write_isrg(priv);
}
static void gfar_init_addr_hash_table(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
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
}
static int gfar_probe(struct platform_device *ofdev)
{
struct net_device *dev = NULL;
struct gfar_private *priv = NULL;
int err = 0, i;
err = gfar_of_init(ofdev, &dev);
if (err)
return err;
priv = netdev_priv(dev);
priv->ndev = dev;
priv->ofdev = ofdev;
priv->dev = &ofdev->dev;
SET_NETDEV_DEV(dev, &ofdev->dev);
spin_lock_init(&priv->bflock);
INIT_WORK(&priv->reset_task, gfar_reset_task);
platform_set_drvdata(ofdev, priv);
gfar_detect_errata(priv);
dev->base_addr = (unsigned long) priv->gfargrp[0].regs;
dev->watchdog_timeo = TX_TIMEOUT;
dev->mtu = 1500;
dev->netdev_ops = &gfar_netdev_ops;
dev->ethtool_ops = &gfar_ethtool_ops;
for (i = 0; i < priv->num_grps; i++) {
if (priv->poll_mode == GFAR_SQ_POLLING) {
netif_napi_add(dev, &priv->gfargrp[i].napi_rx,
gfar_poll_rx_sq, GFAR_DEV_WEIGHT);
netif_napi_add(dev, &priv->gfargrp[i].napi_tx,
gfar_poll_tx_sq, 2);
} else {
netif_napi_add(dev, &priv->gfargrp[i].napi_rx,
gfar_poll_rx, GFAR_DEV_WEIGHT);
netif_napi_add(dev, &priv->gfargrp[i].napi_tx,
gfar_poll_tx, 2);
}
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_CSUM) {
dev->hw_features = NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_RXCSUM;
dev->features |= NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_RXCSUM | NETIF_F_HIGHDMA;
}
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_VLAN) {
dev->hw_features |= NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX;
dev->features |= NETIF_F_HW_VLAN_CTAG_RX;
}
gfar_init_addr_hash_table(priv);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER)
priv->padding = 8;
if (dev->features & NETIF_F_IP_CSUM ||
priv->device_flags & FSL_GIANFAR_DEV_HAS_TIMER)
dev->needed_headroom = GMAC_FCB_LEN;
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
set_bit(GFAR_DOWN, &priv->state);
gfar_hw_init(priv);
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
struct gfar_priv_grp *grp = &priv->gfargrp[i];
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
sprintf(gfar_irq(grp, TX)->name, "%s%s%c%s",
dev->name, "_g", '0' + i, "_tx");
sprintf(gfar_irq(grp, RX)->name, "%s%s%c%s",
dev->name, "_g", '0' + i, "_rx");
sprintf(gfar_irq(grp, ER)->name, "%s%s%c%s",
dev->name, "_g", '0' + i, "_er");
} else
strcpy(gfar_irq(grp, TX)->name, dev->name);
}
gfar_init_filer_table(priv);
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
gfar_free_rx_queues(priv);
gfar_free_tx_queues(priv);
of_node_put(priv->phy_node);
of_node_put(priv->tbi_node);
free_gfar_dev(priv);
return err;
}
static int gfar_remove(struct platform_device *ofdev)
{
struct gfar_private *priv = platform_get_drvdata(ofdev);
of_node_put(priv->phy_node);
of_node_put(priv->tbi_node);
unregister_netdev(priv->ndev);
unmap_group_regs(priv);
gfar_free_rx_queues(priv);
gfar_free_tx_queues(priv);
free_gfar_dev(priv);
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
gfar_halt_nodisable(priv);
tempval = gfar_read(&regs->maccfg1);
tempval &= ~MACCFG1_TX_EN;
if (!magic_packet)
tempval &= ~MACCFG1_RX_EN;
gfar_write(&regs->maccfg1, tempval);
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
tempval = gfar_read(&regs->maccfg2);
tempval &= ~MACCFG2_MPEN;
gfar_write(&regs->maccfg2, tempval);
gfar_start(priv);
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
gfar_mac_reset(priv);
gfar_init_tx_rx_base(priv);
gfar_start(priv);
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
GFAR_SUPPORTED_GBIT : 0;
phy_interface_t interface;
priv->oldlink = 0;
priv->oldspeed = 0;
priv->oldduplex = -1;
interface = gfar_get_interface(dev);
priv->phydev = of_phy_connect(dev, priv->phy_node, &adjust_link, 0,
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
static int __gfar_is_rx_idle(struct gfar_private *priv)
{
u32 res;
if (!gfar_has_errata(priv, GFAR_ERRATA_A002))
return 0;
res = gfar_read((void __iomem *)priv->gfargrp[0].regs + 0xd1c);
res &= 0x7f807f80;
if ((res & 0xffff) == (res >> 16))
return 1;
return 0;
}
static void gfar_halt_nodisable(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
unsigned int timeout;
int stopped;
gfar_ints_disable(priv);
if (gfar_is_dma_stopped(priv))
return;
tempval = gfar_read(&regs->dmactrl);
tempval |= (DMACTRL_GRS | DMACTRL_GTS);
gfar_write(&regs->dmactrl, tempval);
retry:
timeout = 1000;
while (!(stopped = gfar_is_dma_stopped(priv)) && timeout) {
cpu_relax();
timeout--;
}
if (!timeout)
stopped = gfar_is_dma_stopped(priv);
if (!stopped && !gfar_is_rx_dma_stopped(priv) &&
!__gfar_is_rx_idle(priv))
goto retry;
}
void gfar_halt(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
gfar_write(&regs->rqueue, 0);
gfar_write(&regs->tqueue, 0);
mdelay(10);
gfar_halt_nodisable(priv);
tempval = gfar_read(&regs->maccfg1);
tempval &= ~(MACCFG1_RX_EN | MACCFG1_TX_EN);
gfar_write(&regs->maccfg1, tempval);
}
void stop_gfar(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
netif_tx_stop_all_queues(dev);
smp_mb__before_atomic();
set_bit(GFAR_DOWN, &priv->state);
smp_mb__after_atomic();
disable_napi(priv);
gfar_halt(priv);
phy_stop(priv->phydev);
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
dma_unmap_single(priv->dev, txbdp->bufPtr,
txbdp->length, DMA_TO_DEVICE);
txbdp->lstatus = 0;
for (j = 0; j < skb_shinfo(tx_queue->tx_skbuff[i])->nr_frags;
j++) {
txbdp++;
dma_unmap_page(priv->dev, txbdp->bufPtr,
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
dma_unmap_single(priv->dev, rxbdp->bufPtr,
priv->rx_buffer_size,
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
dma_free_coherent(priv->dev,
sizeof(struct txbd8) * priv->total_tx_ring_size +
sizeof(struct rxbd8) * priv->total_rx_ring_size,
priv->tx_queue[0]->tx_bd_base,
priv->tx_queue[0]->tx_bd_dma_base);
}
void gfar_start(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u32 tempval;
int i = 0;
gfar_write(&regs->rqueue, priv->rqueue);
gfar_write(&regs->tqueue, priv->tqueue);
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
}
tempval = gfar_read(&regs->maccfg1);
tempval |= (MACCFG1_RX_EN | MACCFG1_TX_EN);
gfar_write(&regs->maccfg1, tempval);
gfar_ints_enable(priv);
priv->ndev->trans_start = jiffies;
}
static void free_grp_irqs(struct gfar_priv_grp *grp)
{
free_irq(gfar_irq(grp, TX)->irq, grp);
free_irq(gfar_irq(grp, RX)->irq, grp);
free_irq(gfar_irq(grp, ER)->irq, grp);
}
static int register_grp_irqs(struct gfar_priv_grp *grp)
{
struct gfar_private *priv = grp->priv;
struct net_device *dev = priv->ndev;
int err;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
err = request_irq(gfar_irq(grp, ER)->irq, gfar_error, 0,
gfar_irq(grp, ER)->name, grp);
if (err < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
gfar_irq(grp, ER)->irq);
goto err_irq_fail;
}
err = request_irq(gfar_irq(grp, TX)->irq, gfar_transmit, 0,
gfar_irq(grp, TX)->name, grp);
if (err < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
gfar_irq(grp, TX)->irq);
goto tx_irq_fail;
}
err = request_irq(gfar_irq(grp, RX)->irq, gfar_receive, 0,
gfar_irq(grp, RX)->name, grp);
if (err < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
gfar_irq(grp, RX)->irq);
goto rx_irq_fail;
}
} else {
err = request_irq(gfar_irq(grp, TX)->irq, gfar_interrupt, 0,
gfar_irq(grp, TX)->name, grp);
if (err < 0) {
netif_err(priv, intr, dev, "Can't get IRQ %d\n",
gfar_irq(grp, TX)->irq);
goto err_irq_fail;
}
}
return 0;
rx_irq_fail:
free_irq(gfar_irq(grp, TX)->irq, grp);
tx_irq_fail:
free_irq(gfar_irq(grp, ER)->irq, grp);
err_irq_fail:
return err;
}
static void gfar_free_irq(struct gfar_private *priv)
{
int i;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
for (i = 0; i < priv->num_grps; i++)
free_grp_irqs(&priv->gfargrp[i]);
} else {
for (i = 0; i < priv->num_grps; i++)
free_irq(gfar_irq(&priv->gfargrp[i], TX)->irq,
&priv->gfargrp[i]);
}
}
static int gfar_request_irq(struct gfar_private *priv)
{
int err, i, j;
for (i = 0; i < priv->num_grps; i++) {
err = register_grp_irqs(&priv->gfargrp[i]);
if (err) {
for (j = 0; j < i; j++)
free_grp_irqs(&priv->gfargrp[j]);
return err;
}
}
return 0;
}
int startup_gfar(struct net_device *ndev)
{
struct gfar_private *priv = netdev_priv(ndev);
int err;
gfar_mac_reset(priv);
err = gfar_alloc_skb_resources(ndev);
if (err)
return err;
gfar_init_tx_rx_base(priv);
smp_mb__before_atomic();
clear_bit(GFAR_DOWN, &priv->state);
smp_mb__after_atomic();
gfar_start(priv);
phy_start(priv->phydev);
enable_napi(priv);
netif_tx_wake_all_queues(ndev);
return 0;
}
static int gfar_enet_open(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
int err;
err = init_phy(dev);
if (err)
return err;
err = gfar_request_irq(priv);
if (err)
return err;
err = startup_gfar(dev);
if (err)
return err;
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
static inline bool gfar_csum_errata_12(struct gfar_private *priv,
unsigned long fcb_addr)
{
return (gfar_has_errata(priv, GFAR_ERRATA_12) &&
(fcb_addr % 0x20) > 0x18);
}
static inline bool gfar_csum_errata_76(struct gfar_private *priv,
unsigned int len)
{
return (gfar_has_errata(priv, GFAR_ERRATA_76) &&
(len > 2500));
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
int i, rq = 0;
int do_tstamp, do_csum, do_vlan;
u32 bufaddr;
unsigned long flags;
unsigned int nr_frags, nr_txbds, bytes_sent, fcb_len = 0;
rq = skb->queue_mapping;
tx_queue = priv->tx_queue[rq];
txq = netdev_get_tx_queue(dev, rq);
base = tx_queue->tx_bd_base;
regs = tx_queue->grp->regs;
do_csum = (CHECKSUM_PARTIAL == skb->ip_summed);
do_vlan = vlan_tx_tag_present(skb);
do_tstamp = (skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
priv->hwts_tx_en;
if (do_csum || do_vlan)
fcb_len = GMAC_FCB_LEN;
if (unlikely(do_tstamp))
fcb_len = GMAC_FCB_LEN + GMAC_TXPAL_LEN;
if (fcb_len && unlikely(skb_headroom(skb) < fcb_len)) {
struct sk_buff *skb_new;
skb_new = skb_realloc_headroom(skb, fcb_len);
if (!skb_new) {
dev->stats.tx_errors++;
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (skb->sk)
skb_set_owner_w(skb_new, skb->sk);
dev_consume_skb_any(skb);
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
bytes_sent = skb->len;
tx_queue->stats.tx_bytes += bytes_sent;
GFAR_CB(skb)->bytes_sent = bytes_sent;
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
unsigned int frag_len;
txbdp = next_txbd(txbdp, base, tx_queue->tx_ring_size);
frag_len = skb_shinfo(skb)->frags[i].size;
lstatus = txbdp->lstatus | frag_len |
BD_LFLAG(TXBD_READY);
if (i == nr_frags - 1)
lstatus |= BD_LFLAG(TXBD_LAST | TXBD_INTERRUPT);
bufaddr = skb_frag_dma_map(priv->dev,
&skb_shinfo(skb)->frags[i],
0,
frag_len,
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
if (fcb_len) {
fcb = gfar_add_fcb(skb);
lstatus |= BD_LFLAG(TXBD_TOE);
}
if (do_csum) {
gfar_tx_checksum(skb, fcb, fcb_len);
if (unlikely(gfar_csum_errata_12(priv, (unsigned long)fcb)) ||
unlikely(gfar_csum_errata_76(priv, skb->len))) {
__skb_pull(skb, GMAC_FCB_LEN);
skb_checksum_help(skb);
if (do_vlan || do_tstamp) {
fcb = gfar_add_fcb(skb);
} else {
lstatus &= ~(BD_LFLAG(TXBD_TOE));
fcb = NULL;
}
}
}
if (do_vlan)
gfar_tx_vlan(skb, fcb);
if (unlikely(do_tstamp)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
fcb->ptp = 1;
}
txbdp_start->bufPtr = dma_map_single(priv->dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
if (unlikely(do_tstamp)) {
txbdp_tstamp->bufPtr = txbdp_start->bufPtr + fcb_len;
txbdp_tstamp->lstatus |= BD_LFLAG(TXBD_READY) |
(skb_headlen(skb) - fcb_len);
lstatus |= BD_LFLAG(TXBD_CRC | TXBD_READY) | GMAC_FCB_LEN;
} else {
lstatus |= BD_LFLAG(TXBD_CRC | TXBD_READY) | skb_headlen(skb);
}
netdev_tx_sent_queue(txq, bytes_sent);
spin_lock_irqsave(&tx_queue->txlock, flags);
gfar_wmb();
txbdp_start->lstatus = lstatus;
gfar_wmb();
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
cancel_work_sync(&priv->reset_task);
stop_gfar(dev);
phy_disconnect(priv->phydev);
priv->phydev = NULL;
gfar_free_irq(priv);
return 0;
}
static int gfar_set_mac_address(struct net_device *dev)
{
gfar_set_mac_for_addr(dev, 0, dev->dev_addr);
return 0;
}
static int gfar_change_mtu(struct net_device *dev, int new_mtu)
{
struct gfar_private *priv = netdev_priv(dev);
int frame_size = new_mtu + ETH_HLEN;
if ((frame_size < 64) || (frame_size > JUMBO_FRAME_SIZE)) {
netif_err(priv, drv, dev, "Invalid MTU setting\n");
return -EINVAL;
}
while (test_and_set_bit_lock(GFAR_RESETTING, &priv->state))
cpu_relax();
if (dev->flags & IFF_UP)
stop_gfar(dev);
dev->mtu = new_mtu;
if (dev->flags & IFF_UP)
startup_gfar(dev);
clear_bit_unlock(GFAR_RESETTING, &priv->state);
return 0;
}
void reset_gfar(struct net_device *ndev)
{
struct gfar_private *priv = netdev_priv(ndev);
while (test_and_set_bit_lock(GFAR_RESETTING, &priv->state))
cpu_relax();
stop_gfar(ndev);
startup_gfar(ndev);
clear_bit_unlock(GFAR_RESETTING, &priv->state);
}
static void gfar_reset_task(struct work_struct *work)
{
struct gfar_private *priv = container_of(work, struct gfar_private,
reset_task);
reset_gfar(priv->ndev);
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
static void gfar_clean_tx_ring(struct gfar_priv_tx_q *tx_queue)
{
struct net_device *dev = tx_queue->dev;
struct netdev_queue *txq;
struct gfar_private *priv = netdev_priv(dev);
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
dma_unmap_single(priv->dev, bdp->bufPtr,
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
dma_unmap_page(priv->dev, bdp->bufPtr,
bdp->length, DMA_TO_DEVICE);
bdp->lstatus &= BD_LFLAG(TXBD_WRAP);
bdp = next_txbd(bdp, base, tx_ring_size);
}
bytes_sent += GFAR_CB(skb)->bytes_sent;
dev_kfree_skb_any(skb);
tx_queue->tx_skbuff[skb_dirtytx] = NULL;
skb_dirtytx = (skb_dirtytx + 1) &
TX_RING_MOD_MASK(tx_ring_size);
howmany++;
spin_lock_irqsave(&tx_queue->txlock, flags);
tx_queue->num_txbdfree += nr_txbds;
spin_unlock_irqrestore(&tx_queue->txlock, flags);
}
if (tx_queue->num_txbdfree &&
netif_tx_queue_stopped(txq) &&
!(test_bit(GFAR_DOWN, &priv->state)))
netif_wake_subqueue(priv->ndev, tqi);
tx_queue->skb_dirtytx = skb_dirtytx;
tx_queue->dirty_tx = bdp;
netdev_tx_completed_queue(txq, howmany, bytes_sent);
}
static void gfar_new_rxbdp(struct gfar_priv_rx_q *rx_queue, struct rxbd8 *bdp,
struct sk_buff *skb)
{
struct net_device *dev = rx_queue->dev;
struct gfar_private *priv = netdev_priv(dev);
dma_addr_t buf;
buf = dma_map_single(priv->dev, skb->data,
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
atomic64_inc(&estats->rx_trunc);
return;
}
if (status & (RXBD_LARGE | RXBD_SHORT)) {
stats->rx_length_errors++;
if (status & RXBD_LARGE)
atomic64_inc(&estats->rx_large);
else
atomic64_inc(&estats->rx_short);
}
if (status & RXBD_NONOCTET) {
stats->rx_frame_errors++;
atomic64_inc(&estats->rx_nonoctet);
}
if (status & RXBD_CRCERR) {
atomic64_inc(&estats->rx_crcerr);
stats->rx_crc_errors++;
}
if (status & RXBD_OVERRUN) {
atomic64_inc(&estats->rx_overrun);
stats->rx_crc_errors++;
}
}
irqreturn_t gfar_receive(int irq, void *grp_id)
{
struct gfar_priv_grp *grp = (struct gfar_priv_grp *)grp_id;
unsigned long flags;
u32 imask;
if (likely(napi_schedule_prep(&grp->napi_rx))) {
spin_lock_irqsave(&grp->grplock, flags);
imask = gfar_read(&grp->regs->imask);
imask &= IMASK_RX_DISABLED;
gfar_write(&grp->regs->imask, imask);
spin_unlock_irqrestore(&grp->grplock, flags);
__napi_schedule(&grp->napi_rx);
} else {
gfar_write(&grp->regs->ievent, IEVENT_RX_MASK);
}
return IRQ_HANDLED;
}
static irqreturn_t gfar_transmit(int irq, void *grp_id)
{
struct gfar_priv_grp *grp = (struct gfar_priv_grp *)grp_id;
unsigned long flags;
u32 imask;
if (likely(napi_schedule_prep(&grp->napi_tx))) {
spin_lock_irqsave(&grp->grplock, flags);
imask = gfar_read(&grp->regs->imask);
imask &= IMASK_TX_DISABLED;
gfar_write(&grp->regs->imask, imask);
spin_unlock_irqrestore(&grp->grplock, flags);
__napi_schedule(&grp->napi_tx);
} else {
gfar_write(&grp->regs->ievent, IEVENT_TX_MASK);
}
return IRQ_HANDLED;
}
static inline void gfar_rx_checksum(struct sk_buff *skb, struct rxfcb *fcb)
{
if ((fcb->flags & RXFCB_CSUM_MASK) == (RXFCB_CIP | RXFCB_CTU))
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb_checksum_none_assert(skb);
}
static void gfar_process_frame(struct net_device *dev, struct sk_buff *skb,
int amount_pull, struct napi_struct *napi)
{
struct gfar_private *priv = netdev_priv(dev);
struct rxfcb *fcb = NULL;
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
if (dev->features & NETIF_F_HW_VLAN_CTAG_RX &&
fcb->flags & RXFCB_VLN)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), fcb->vlctl);
napi_gro_receive(napi, skb);
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
amount_pull = priv->uses_rxfcb ? GMAC_FCB_LEN : 0;
while (!((bdp->status & RXBD_EMPTY) || (--rx_work_limit < 0))) {
struct sk_buff *newskb;
rmb();
newskb = gfar_new_skb(dev);
skb = rx_queue->rx_skbuff[rx_queue->skb_currx];
dma_unmap_single(priv->dev, bdp->bufPtr,
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
&rx_queue->grp->napi_rx);
} else {
netif_warn(priv, rx_err, dev, "Missing skb!\n");
rx_queue->stats.rx_dropped++;
atomic64_inc(&priv->extra_stats.rx_skbmissing);
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
static int gfar_poll_rx_sq(struct napi_struct *napi, int budget)
{
struct gfar_priv_grp *gfargrp =
container_of(napi, struct gfar_priv_grp, napi_rx);
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_priv_rx_q *rx_queue = gfargrp->rx_queue;
int work_done = 0;
gfar_write(&regs->ievent, IEVENT_RX_MASK);
work_done = gfar_clean_rx_ring(rx_queue, budget);
if (work_done < budget) {
u32 imask;
napi_complete(napi);
gfar_write(&regs->rstat, gfargrp->rstat);
spin_lock_irq(&gfargrp->grplock);
imask = gfar_read(&regs->imask);
imask |= IMASK_RX_DEFAULT;
gfar_write(&regs->imask, imask);
spin_unlock_irq(&gfargrp->grplock);
}
return work_done;
}
static int gfar_poll_tx_sq(struct napi_struct *napi, int budget)
{
struct gfar_priv_grp *gfargrp =
container_of(napi, struct gfar_priv_grp, napi_tx);
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_priv_tx_q *tx_queue = gfargrp->tx_queue;
u32 imask;
gfar_write(&regs->ievent, IEVENT_TX_MASK);
if (tx_queue->tx_skbuff[tx_queue->skb_dirtytx])
gfar_clean_tx_ring(tx_queue);
napi_complete(napi);
spin_lock_irq(&gfargrp->grplock);
imask = gfar_read(&regs->imask);
imask |= IMASK_TX_DEFAULT;
gfar_write(&regs->imask, imask);
spin_unlock_irq(&gfargrp->grplock);
return 0;
}
static int gfar_poll_rx(struct napi_struct *napi, int budget)
{
struct gfar_priv_grp *gfargrp =
container_of(napi, struct gfar_priv_grp, napi_rx);
struct gfar_private *priv = gfargrp->priv;
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_priv_rx_q *rx_queue = NULL;
int work_done = 0, work_done_per_q = 0;
int i, budget_per_q = 0;
unsigned long rstat_rxf;
int num_act_queues;
gfar_write(&regs->ievent, IEVENT_RX_MASK);
rstat_rxf = gfar_read(&regs->rstat) & RSTAT_RXF_MASK;
num_act_queues = bitmap_weight(&rstat_rxf, MAX_RX_QS);
if (num_act_queues)
budget_per_q = budget/num_act_queues;
for_each_set_bit(i, &gfargrp->rx_bit_map, priv->num_rx_queues) {
if (!(rstat_rxf & (RSTAT_CLEAR_RXF0 >> i)))
continue;
rx_queue = priv->rx_queue[i];
work_done_per_q =
gfar_clean_rx_ring(rx_queue, budget_per_q);
work_done += work_done_per_q;
if (work_done_per_q < budget_per_q) {
gfar_write(&regs->rstat,
RSTAT_CLEAR_RXF0 >> i);
num_act_queues--;
if (!num_act_queues)
break;
}
}
if (!num_act_queues) {
u32 imask;
napi_complete(napi);
gfar_write(&regs->rstat, gfargrp->rstat);
spin_lock_irq(&gfargrp->grplock);
imask = gfar_read(&regs->imask);
imask |= IMASK_RX_DEFAULT;
gfar_write(&regs->imask, imask);
spin_unlock_irq(&gfargrp->grplock);
}
return work_done;
}
static int gfar_poll_tx(struct napi_struct *napi, int budget)
{
struct gfar_priv_grp *gfargrp =
container_of(napi, struct gfar_priv_grp, napi_tx);
struct gfar_private *priv = gfargrp->priv;
struct gfar __iomem *regs = gfargrp->regs;
struct gfar_priv_tx_q *tx_queue = NULL;
int has_tx_work = 0;
int i;
gfar_write(&regs->ievent, IEVENT_TX_MASK);
for_each_set_bit(i, &gfargrp->tx_bit_map, priv->num_tx_queues) {
tx_queue = priv->tx_queue[i];
if (tx_queue->tx_skbuff[tx_queue->skb_dirtytx]) {
gfar_clean_tx_ring(tx_queue);
has_tx_work = 1;
}
}
if (!has_tx_work) {
u32 imask;
napi_complete(napi);
spin_lock_irq(&gfargrp->grplock);
imask = gfar_read(&regs->imask);
imask |= IMASK_TX_DEFAULT;
gfar_write(&regs->imask, imask);
spin_unlock_irq(&gfargrp->grplock);
}
return 0;
}
static void gfar_netpoll(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
int i;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MULTI_INTR) {
for (i = 0; i < priv->num_grps; i++) {
struct gfar_priv_grp *grp = &priv->gfargrp[i];
disable_irq(gfar_irq(grp, TX)->irq);
disable_irq(gfar_irq(grp, RX)->irq);
disable_irq(gfar_irq(grp, ER)->irq);
gfar_interrupt(gfar_irq(grp, TX)->irq, grp);
enable_irq(gfar_irq(grp, ER)->irq);
enable_irq(gfar_irq(grp, RX)->irq);
enable_irq(gfar_irq(grp, TX)->irq);
}
} else {
for (i = 0; i < priv->num_grps; i++) {
struct gfar_priv_grp *grp = &priv->gfargrp[i];
disable_irq(gfar_irq(grp, TX)->irq);
gfar_interrupt(gfar_irq(grp, TX)->irq, grp);
enable_irq(gfar_irq(grp, TX)->irq);
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
struct phy_device *phydev = priv->phydev;
if (unlikely(phydev->link != priv->oldlink ||
phydev->duplex != priv->oldduplex ||
phydev->speed != priv->oldspeed))
gfar_update_link_state(priv);
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
u32 tempval;
u32 __iomem *macptr = &regs->macstnaddr1;
macptr += num*2;
tempval = (addr[5] << 24) | (addr[4] << 16) |
(addr[3] << 8) | addr[2];
gfar_write(macptr, tempval);
tempval = (addr[1] << 24) | (addr[0] << 16);
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
atomic64_inc(&priv->extra_stats.tx_underrun);
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
atomic64_inc(&priv->extra_stats.rx_bsy);
gfar_receive(irq, grp_id);
netif_dbg(priv, rx_err, dev, "busy error (rstat: %x)\n",
gfar_read(&regs->rstat));
}
if (events & IEVENT_BABR) {
dev->stats.rx_errors++;
atomic64_inc(&priv->extra_stats.rx_babr);
netif_dbg(priv, rx_err, dev, "babbling RX error\n");
}
if (events & IEVENT_EBERR) {
atomic64_inc(&priv->extra_stats.eberr);
netif_dbg(priv, rx_err, dev, "bus error\n");
}
if (events & IEVENT_RXC)
netif_dbg(priv, rx_status, dev, "control frame\n");
if (events & IEVENT_BABT) {
atomic64_inc(&priv->extra_stats.tx_babt);
netif_dbg(priv, tx_err, dev, "babbling TX error\n");
}
return IRQ_HANDLED;
}
static u32 gfar_get_flowctrl_cfg(struct gfar_private *priv)
{
struct phy_device *phydev = priv->phydev;
u32 val = 0;
if (!phydev->duplex)
return val;
if (!priv->pause_aneg_en) {
if (priv->tx_pause_en)
val |= MACCFG1_TX_FLOW;
if (priv->rx_pause_en)
val |= MACCFG1_RX_FLOW;
} else {
u16 lcl_adv, rmt_adv;
u8 flowctrl;
rmt_adv = 0;
if (phydev->pause)
rmt_adv = LPA_PAUSE_CAP;
if (phydev->asym_pause)
rmt_adv |= LPA_PAUSE_ASYM;
lcl_adv = mii_advertise_flowctrl(phydev->advertising);
flowctrl = mii_resolve_flowctrl_fdx(lcl_adv, rmt_adv);
if (flowctrl & FLOW_CTRL_TX)
val |= MACCFG1_TX_FLOW;
if (flowctrl & FLOW_CTRL_RX)
val |= MACCFG1_RX_FLOW;
}
return val;
}
static noinline void gfar_update_link_state(struct gfar_private *priv)
{
struct gfar __iomem *regs = priv->gfargrp[0].regs;
struct phy_device *phydev = priv->phydev;
if (unlikely(test_bit(GFAR_RESETTING, &priv->state)))
return;
if (phydev->link) {
u32 tempval1 = gfar_read(&regs->maccfg1);
u32 tempval = gfar_read(&regs->maccfg2);
u32 ecntrl = gfar_read(&regs->ecntrl);
if (phydev->duplex != priv->oldduplex) {
if (!(phydev->duplex))
tempval &= ~(MACCFG2_FULL_DUPLEX);
else
tempval |= MACCFG2_FULL_DUPLEX;
priv->oldduplex = phydev->duplex;
}
if (phydev->speed != priv->oldspeed) {
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
netif_warn(priv, link, priv->ndev,
"Ack! Speed (%d) is not 10/100/1000!\n",
phydev->speed);
break;
}
priv->oldspeed = phydev->speed;
}
tempval1 &= ~(MACCFG1_TX_FLOW | MACCFG1_RX_FLOW);
tempval1 |= gfar_get_flowctrl_cfg(priv);
gfar_write(&regs->maccfg1, tempval1);
gfar_write(&regs->maccfg2, tempval);
gfar_write(&regs->ecntrl, ecntrl);
if (!priv->oldlink)
priv->oldlink = 1;
} else if (priv->oldlink) {
priv->oldlink = 0;
priv->oldspeed = 0;
priv->oldduplex = -1;
}
if (netif_msg_link(priv))
phy_print_status(phydev);
}
