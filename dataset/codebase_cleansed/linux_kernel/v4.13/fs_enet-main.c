static void fs_set_multicast_list(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
(*fep->ops->set_multicast_list)(dev);
}
static void skb_align(struct sk_buff *skb, int align)
{
int off = ((unsigned long)skb->data) & (align - 1);
if (off)
skb_reserve(skb, align - off);
}
static int fs_enet_napi(struct napi_struct *napi, int budget)
{
struct fs_enet_private *fep = container_of(napi, struct fs_enet_private, napi);
struct net_device *dev = fep->ndev;
const struct fs_platform_info *fpi = fep->fpi;
cbd_t __iomem *bdp;
struct sk_buff *skb, *skbn;
int received = 0;
u16 pkt_len, sc;
int curidx;
int dirtyidx, do_wake, do_restart;
int tx_left = TX_RING_SIZE;
spin_lock(&fep->tx_lock);
bdp = fep->dirty_tx;
(*fep->ops->napi_clear_event)(dev);
do_wake = do_restart = 0;
while (((sc = CBDR_SC(bdp)) & BD_ENET_TX_READY) == 0 && tx_left) {
dirtyidx = bdp - fep->tx_bd_base;
if (fep->tx_free == fep->tx_ring)
break;
skb = fep->tx_skbuff[dirtyidx];
if (sc & (BD_ENET_TX_HB | BD_ENET_TX_LC |
BD_ENET_TX_RL | BD_ENET_TX_UN | BD_ENET_TX_CSL)) {
if (sc & BD_ENET_TX_HB)
dev->stats.tx_heartbeat_errors++;
if (sc & BD_ENET_TX_LC)
dev->stats.tx_window_errors++;
if (sc & BD_ENET_TX_RL)
dev->stats.tx_aborted_errors++;
if (sc & BD_ENET_TX_UN)
dev->stats.tx_fifo_errors++;
if (sc & BD_ENET_TX_CSL)
dev->stats.tx_carrier_errors++;
if (sc & (BD_ENET_TX_LC | BD_ENET_TX_RL | BD_ENET_TX_UN)) {
dev->stats.tx_errors++;
do_restart = 1;
}
} else
dev->stats.tx_packets++;
if (sc & BD_ENET_TX_READY) {
dev_warn(fep->dev,
"HEY! Enet xmit interrupt and TX_READY.\n");
}
if (sc & BD_ENET_TX_DEF)
dev->stats.collisions++;
if (fep->mapped_as_page[dirtyidx])
dma_unmap_page(fep->dev, CBDR_BUFADDR(bdp),
CBDR_DATLEN(bdp), DMA_TO_DEVICE);
else
dma_unmap_single(fep->dev, CBDR_BUFADDR(bdp),
CBDR_DATLEN(bdp), DMA_TO_DEVICE);
if (skb) {
dev_kfree_skb(skb);
fep->tx_skbuff[dirtyidx] = NULL;
}
if ((sc & BD_ENET_TX_WRAP) == 0)
bdp++;
else
bdp = fep->tx_bd_base;
if (++fep->tx_free == MAX_SKB_FRAGS)
do_wake = 1;
tx_left--;
}
fep->dirty_tx = bdp;
if (do_restart)
(*fep->ops->tx_restart)(dev);
spin_unlock(&fep->tx_lock);
if (do_wake)
netif_wake_queue(dev);
bdp = fep->cur_rx;
while (((sc = CBDR_SC(bdp)) & BD_ENET_RX_EMPTY) == 0 &&
received < budget) {
curidx = bdp - fep->rx_bd_base;
if ((sc & BD_ENET_RX_LAST) == 0)
dev_warn(fep->dev, "rcv is not +last\n");
if (sc & (BD_ENET_RX_LG | BD_ENET_RX_SH | BD_ENET_RX_CL |
BD_ENET_RX_NO | BD_ENET_RX_CR | BD_ENET_RX_OV)) {
dev->stats.rx_errors++;
if (sc & (BD_ENET_RX_LG | BD_ENET_RX_SH))
dev->stats.rx_length_errors++;
if (sc & (BD_ENET_RX_NO | BD_ENET_RX_CL))
dev->stats.rx_frame_errors++;
if (sc & BD_ENET_RX_CR)
dev->stats.rx_crc_errors++;
if (sc & BD_ENET_RX_OV)
dev->stats.rx_crc_errors++;
skbn = fep->rx_skbuff[curidx];
} else {
skb = fep->rx_skbuff[curidx];
dev->stats.rx_packets++;
pkt_len = CBDR_DATLEN(bdp) - 4;
dev->stats.rx_bytes += pkt_len + 4;
if (pkt_len <= fpi->rx_copybreak) {
skbn = netdev_alloc_skb(dev, pkt_len + 2);
if (skbn != NULL) {
skb_reserve(skbn, 2);
skb_copy_from_linear_data(skb,
skbn->data, pkt_len);
swap(skb, skbn);
dma_sync_single_for_cpu(fep->dev,
CBDR_BUFADDR(bdp),
L1_CACHE_ALIGN(pkt_len),
DMA_FROM_DEVICE);
}
} else {
skbn = netdev_alloc_skb(dev, ENET_RX_FRSIZE);
if (skbn) {
dma_addr_t dma;
skb_align(skbn, ENET_RX_ALIGN);
dma_unmap_single(fep->dev,
CBDR_BUFADDR(bdp),
L1_CACHE_ALIGN(PKT_MAXBUF_SIZE),
DMA_FROM_DEVICE);
dma = dma_map_single(fep->dev,
skbn->data,
L1_CACHE_ALIGN(PKT_MAXBUF_SIZE),
DMA_FROM_DEVICE);
CBDW_BUFADDR(bdp, dma);
}
}
if (skbn != NULL) {
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, dev);
received++;
netif_receive_skb(skb);
} else {
dev->stats.rx_dropped++;
skbn = skb;
}
}
fep->rx_skbuff[curidx] = skbn;
CBDW_DATLEN(bdp, 0);
CBDW_SC(bdp, (sc & ~BD_ENET_RX_STATS) | BD_ENET_RX_EMPTY);
if ((sc & BD_ENET_RX_WRAP) == 0)
bdp++;
else
bdp = fep->rx_bd_base;
(*fep->ops->rx_bd_done)(dev);
}
fep->cur_rx = bdp;
if (received < budget && tx_left) {
napi_complete_done(napi, received);
(*fep->ops->napi_enable)(dev);
return received;
}
return budget;
}
static irqreturn_t
fs_enet_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct fs_enet_private *fep;
const struct fs_platform_info *fpi;
u32 int_events;
u32 int_clr_events;
int nr, napi_ok;
int handled;
fep = netdev_priv(dev);
fpi = fep->fpi;
nr = 0;
while ((int_events = (*fep->ops->get_int_events)(dev)) != 0) {
nr++;
int_clr_events = int_events;
int_clr_events &= ~fep->ev_napi;
(*fep->ops->clear_int_events)(dev, int_clr_events);
if (int_events & fep->ev_err)
(*fep->ops->ev_error)(dev, int_events);
if (int_events & fep->ev) {
napi_ok = napi_schedule_prep(&fep->napi);
(*fep->ops->napi_disable)(dev);
(*fep->ops->clear_int_events)(dev, fep->ev_napi);
if (napi_ok)
__napi_schedule(&fep->napi);
}
}
handled = nr > 0;
return IRQ_RETVAL(handled);
}
void fs_init_bds(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
cbd_t __iomem *bdp;
struct sk_buff *skb;
int i;
fs_cleanup_bds(dev);
fep->dirty_tx = fep->cur_tx = fep->tx_bd_base;
fep->tx_free = fep->tx_ring;
fep->cur_rx = fep->rx_bd_base;
for (i = 0, bdp = fep->rx_bd_base; i < fep->rx_ring; i++, bdp++) {
skb = netdev_alloc_skb(dev, ENET_RX_FRSIZE);
if (skb == NULL)
break;
skb_align(skb, ENET_RX_ALIGN);
fep->rx_skbuff[i] = skb;
CBDW_BUFADDR(bdp,
dma_map_single(fep->dev, skb->data,
L1_CACHE_ALIGN(PKT_MAXBUF_SIZE),
DMA_FROM_DEVICE));
CBDW_DATLEN(bdp, 0);
CBDW_SC(bdp, BD_ENET_RX_EMPTY |
((i < fep->rx_ring - 1) ? 0 : BD_SC_WRAP));
}
for (; i < fep->rx_ring; i++, bdp++) {
fep->rx_skbuff[i] = NULL;
CBDW_SC(bdp, (i < fep->rx_ring - 1) ? 0 : BD_SC_WRAP);
}
for (i = 0, bdp = fep->tx_bd_base; i < fep->tx_ring; i++, bdp++) {
fep->tx_skbuff[i] = NULL;
CBDW_BUFADDR(bdp, 0);
CBDW_DATLEN(bdp, 0);
CBDW_SC(bdp, (i < fep->tx_ring - 1) ? 0 : BD_SC_WRAP);
}
}
void fs_cleanup_bds(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct sk_buff *skb;
cbd_t __iomem *bdp;
int i;
for (i = 0, bdp = fep->tx_bd_base; i < fep->tx_ring; i++, bdp++) {
if ((skb = fep->tx_skbuff[i]) == NULL)
continue;
dma_unmap_single(fep->dev, CBDR_BUFADDR(bdp),
skb->len, DMA_TO_DEVICE);
fep->tx_skbuff[i] = NULL;
dev_kfree_skb(skb);
}
for (i = 0, bdp = fep->rx_bd_base; i < fep->rx_ring; i++, bdp++) {
if ((skb = fep->rx_skbuff[i]) == NULL)
continue;
dma_unmap_single(fep->dev, CBDR_BUFADDR(bdp),
L1_CACHE_ALIGN(PKT_MAXBUF_SIZE),
DMA_FROM_DEVICE);
fep->rx_skbuff[i] = NULL;
dev_kfree_skb(skb);
}
}
static struct sk_buff *tx_skb_align_workaround(struct net_device *dev,
struct sk_buff *skb)
{
struct sk_buff *new_skb;
if (skb_linearize(skb))
return NULL;
new_skb = netdev_alloc_skb(dev, skb->len + 4);
if (!new_skb)
return NULL;
skb_align(new_skb, 4);
skb_copy_from_linear_data(skb, new_skb->data, skb->len);
skb_put(new_skb, skb->len);
dev_kfree_skb_any(skb);
return new_skb;
}
static int fs_enet_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
cbd_t __iomem *bdp;
int curidx;
u16 sc;
int nr_frags;
skb_frag_t *frag;
int len;
#ifdef CONFIG_FS_ENET_MPC5121_FEC
int is_aligned = 1;
int i;
if (!IS_ALIGNED((unsigned long)skb->data, 4)) {
is_aligned = 0;
} else {
nr_frags = skb_shinfo(skb)->nr_frags;
frag = skb_shinfo(skb)->frags;
for (i = 0; i < nr_frags; i++, frag++) {
if (!IS_ALIGNED(frag->page_offset, 4)) {
is_aligned = 0;
break;
}
}
}
if (!is_aligned) {
skb = tx_skb_align_workaround(dev, skb);
if (!skb) {
return NETDEV_TX_BUSY;
}
}
#endif
spin_lock(&fep->tx_lock);
bdp = fep->cur_tx;
nr_frags = skb_shinfo(skb)->nr_frags;
if (fep->tx_free <= nr_frags || (CBDR_SC(bdp) & BD_ENET_TX_READY)) {
netif_stop_queue(dev);
spin_unlock(&fep->tx_lock);
dev_warn(fep->dev, "tx queue full!.\n");
return NETDEV_TX_BUSY;
}
curidx = bdp - fep->tx_bd_base;
len = skb->len;
dev->stats.tx_bytes += len;
if (nr_frags)
len -= skb->data_len;
fep->tx_free -= nr_frags + 1;
CBDW_BUFADDR(bdp, dma_map_single(fep->dev,
skb->data, len, DMA_TO_DEVICE));
CBDW_DATLEN(bdp, len);
fep->mapped_as_page[curidx] = 0;
frag = skb_shinfo(skb)->frags;
while (nr_frags) {
CBDC_SC(bdp,
BD_ENET_TX_STATS | BD_ENET_TX_INTR | BD_ENET_TX_LAST |
BD_ENET_TX_TC);
CBDS_SC(bdp, BD_ENET_TX_READY);
if ((CBDR_SC(bdp) & BD_ENET_TX_WRAP) == 0)
bdp++, curidx++;
else
bdp = fep->tx_bd_base, curidx = 0;
len = skb_frag_size(frag);
CBDW_BUFADDR(bdp, skb_frag_dma_map(fep->dev, frag, 0, len,
DMA_TO_DEVICE));
CBDW_DATLEN(bdp, len);
fep->tx_skbuff[curidx] = NULL;
fep->mapped_as_page[curidx] = 1;
frag++;
nr_frags--;
}
sc = BD_ENET_TX_READY | BD_ENET_TX_INTR |
BD_ENET_TX_LAST | BD_ENET_TX_TC;
if (skb->len <= 60)
sc |= BD_ENET_TX_PAD;
CBDC_SC(bdp, BD_ENET_TX_STATS);
CBDS_SC(bdp, sc);
fep->tx_skbuff[curidx] = skb;
if ((CBDR_SC(bdp) & BD_ENET_TX_WRAP) == 0)
bdp++;
else
bdp = fep->tx_bd_base;
fep->cur_tx = bdp;
if (fep->tx_free < MAX_SKB_FRAGS)
netif_stop_queue(dev);
skb_tx_timestamp(skb);
(*fep->ops->tx_kickstart)(dev);
spin_unlock(&fep->tx_lock);
return NETDEV_TX_OK;
}
static void fs_timeout(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
unsigned long flags;
int wake = 0;
dev->stats.tx_errors++;
spin_lock_irqsave(&fep->lock, flags);
if (dev->flags & IFF_UP) {
phy_stop(dev->phydev);
(*fep->ops->stop)(dev);
(*fep->ops->restart)(dev);
phy_start(dev->phydev);
}
phy_start(dev->phydev);
wake = fep->tx_free >= MAX_SKB_FRAGS &&
!(CBDR_SC(fep->cur_tx) & BD_ENET_TX_READY);
spin_unlock_irqrestore(&fep->lock, flags);
if (wake)
netif_wake_queue(dev);
}
static void generic_adjust_link(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct phy_device *phydev = dev->phydev;
int new_state = 0;
if (phydev->link) {
if (phydev->duplex != fep->oldduplex) {
new_state = 1;
fep->oldduplex = phydev->duplex;
}
if (phydev->speed != fep->oldspeed) {
new_state = 1;
fep->oldspeed = phydev->speed;
}
if (!fep->oldlink) {
new_state = 1;
fep->oldlink = 1;
}
if (new_state)
fep->ops->restart(dev);
} else if (fep->oldlink) {
new_state = 1;
fep->oldlink = 0;
fep->oldspeed = 0;
fep->oldduplex = -1;
}
if (new_state && netif_msg_link(fep))
phy_print_status(phydev);
}
static void fs_adjust_link(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&fep->lock, flags);
if(fep->ops->adjust_link)
fep->ops->adjust_link(dev);
else
generic_adjust_link(dev);
spin_unlock_irqrestore(&fep->lock, flags);
}
static int fs_init_phy(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct phy_device *phydev;
phy_interface_t iface;
fep->oldlink = 0;
fep->oldspeed = 0;
fep->oldduplex = -1;
iface = fep->fpi->use_rmii ?
PHY_INTERFACE_MODE_RMII : PHY_INTERFACE_MODE_MII;
phydev = of_phy_connect(dev, fep->fpi->phy_node, &fs_adjust_link, 0,
iface);
if (!phydev) {
dev_err(&dev->dev, "Could not attach to PHY\n");
return -ENODEV;
}
return 0;
}
static int fs_enet_open(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
int r;
int err;
fs_init_bds(fep->ndev);
napi_enable(&fep->napi);
r = request_irq(fep->interrupt, fs_enet_interrupt, IRQF_SHARED,
"fs_enet-mac", dev);
if (r != 0) {
dev_err(fep->dev, "Could not allocate FS_ENET IRQ!");
napi_disable(&fep->napi);
return -EINVAL;
}
err = fs_init_phy(dev);
if (err) {
free_irq(fep->interrupt, dev);
napi_disable(&fep->napi);
return err;
}
phy_start(dev->phydev);
netif_start_queue(dev);
return 0;
}
static int fs_enet_close(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
unsigned long flags;
netif_stop_queue(dev);
netif_carrier_off(dev);
napi_disable(&fep->napi);
phy_stop(dev->phydev);
spin_lock_irqsave(&fep->lock, flags);
spin_lock(&fep->tx_lock);
(*fep->ops->stop)(dev);
spin_unlock(&fep->tx_lock);
spin_unlock_irqrestore(&fep->lock, flags);
phy_disconnect(dev->phydev);
free_irq(fep->interrupt, dev);
return 0;
}
static void fs_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
}
static int fs_get_regs_len(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
return (*fep->ops->get_regs_len)(dev);
}
static void fs_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *p)
{
struct fs_enet_private *fep = netdev_priv(dev);
unsigned long flags;
int r, len;
len = regs->len;
spin_lock_irqsave(&fep->lock, flags);
r = (*fep->ops->get_regs)(dev, p, &len);
spin_unlock_irqrestore(&fep->lock, flags);
if (r == 0)
regs->version = 0;
}
static u32 fs_get_msglevel(struct net_device *dev)
{
struct fs_enet_private *fep = netdev_priv(dev);
return fep->msg_enable;
}
static void fs_set_msglevel(struct net_device *dev, u32 value)
{
struct fs_enet_private *fep = netdev_priv(dev);
fep->msg_enable = value;
}
static int fs_get_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna, void *data)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fs_platform_info *fpi = fep->fpi;
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
*(u32 *)data = fpi->rx_copybreak;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int fs_set_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna, const void *data)
{
struct fs_enet_private *fep = netdev_priv(dev);
struct fs_platform_info *fpi = fep->fpi;
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
fpi->rx_copybreak = *(u32 *)data;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int fs_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
if (!netif_running(dev))
return -EINVAL;
return phy_mii_ioctl(dev->phydev, rq, cmd);
}
static int fs_enet_probe(struct platform_device *ofdev)
{
const struct of_device_id *match;
struct net_device *ndev;
struct fs_enet_private *fep;
struct fs_platform_info *fpi;
const u32 *data;
struct clk *clk;
int err;
const u8 *mac_addr;
const char *phy_connection_type;
int privsize, len, ret = -ENODEV;
match = of_match_device(fs_enet_match, &ofdev->dev);
if (!match)
return -EINVAL;
fpi = kzalloc(sizeof(*fpi), GFP_KERNEL);
if (!fpi)
return -ENOMEM;
if (!IS_FEC(match)) {
data = of_get_property(ofdev->dev.of_node, "fsl,cpm-command", &len);
if (!data || len != 4)
goto out_free_fpi;
fpi->cp_command = *data;
}
fpi->rx_ring = RX_RING_SIZE;
fpi->tx_ring = TX_RING_SIZE;
fpi->rx_copybreak = 240;
fpi->napi_weight = 17;
fpi->phy_node = of_parse_phandle(ofdev->dev.of_node, "phy-handle", 0);
if (!fpi->phy_node && of_phy_is_fixed_link(ofdev->dev.of_node)) {
err = of_phy_register_fixed_link(ofdev->dev.of_node);
if (err)
goto out_free_fpi;
fpi->phy_node = of_node_get(ofdev->dev.of_node);
}
if (of_device_is_compatible(ofdev->dev.of_node, "fsl,mpc5125-fec")) {
phy_connection_type = of_get_property(ofdev->dev.of_node,
"phy-connection-type", NULL);
if (phy_connection_type && !strcmp("rmii", phy_connection_type))
fpi->use_rmii = 1;
}
clk = devm_clk_get(&ofdev->dev, "per");
if (!IS_ERR(clk)) {
ret = clk_prepare_enable(clk);
if (ret)
goto out_deregister_fixed_link;
fpi->clk_per = clk;
}
privsize = sizeof(*fep) +
sizeof(struct sk_buff **) *
(fpi->rx_ring + fpi->tx_ring) +
sizeof(char) * fpi->tx_ring;
ndev = alloc_etherdev(privsize);
if (!ndev) {
ret = -ENOMEM;
goto out_put;
}
SET_NETDEV_DEV(ndev, &ofdev->dev);
platform_set_drvdata(ofdev, ndev);
fep = netdev_priv(ndev);
fep->dev = &ofdev->dev;
fep->ndev = ndev;
fep->fpi = fpi;
fep->ops = match->data;
ret = fep->ops->setup_data(ndev);
if (ret)
goto out_free_dev;
fep->rx_skbuff = (struct sk_buff **)&fep[1];
fep->tx_skbuff = fep->rx_skbuff + fpi->rx_ring;
fep->mapped_as_page = (char *)(fep->rx_skbuff + fpi->rx_ring +
fpi->tx_ring);
spin_lock_init(&fep->lock);
spin_lock_init(&fep->tx_lock);
mac_addr = of_get_mac_address(ofdev->dev.of_node);
if (mac_addr)
memcpy(ndev->dev_addr, mac_addr, ETH_ALEN);
ret = fep->ops->allocate_bd(ndev);
if (ret)
goto out_cleanup_data;
fep->rx_bd_base = fep->ring_base;
fep->tx_bd_base = fep->rx_bd_base + fpi->rx_ring;
fep->tx_ring = fpi->tx_ring;
fep->rx_ring = fpi->rx_ring;
ndev->netdev_ops = &fs_enet_netdev_ops;
ndev->watchdog_timeo = 2 * HZ;
netif_napi_add(ndev, &fep->napi, fs_enet_napi, fpi->napi_weight);
ndev->ethtool_ops = &fs_ethtool_ops;
init_timer(&fep->phy_timer_list);
netif_carrier_off(ndev);
ndev->features |= NETIF_F_SG;
ret = register_netdev(ndev);
if (ret)
goto out_free_bd;
pr_info("%s: fs_enet: %pM\n", ndev->name, ndev->dev_addr);
return 0;
out_free_bd:
fep->ops->free_bd(ndev);
out_cleanup_data:
fep->ops->cleanup_data(ndev);
out_free_dev:
free_netdev(ndev);
out_put:
if (fpi->clk_per)
clk_disable_unprepare(fpi->clk_per);
out_deregister_fixed_link:
of_node_put(fpi->phy_node);
if (of_phy_is_fixed_link(ofdev->dev.of_node))
of_phy_deregister_fixed_link(ofdev->dev.of_node);
out_free_fpi:
kfree(fpi);
return ret;
}
static int fs_enet_remove(struct platform_device *ofdev)
{
struct net_device *ndev = platform_get_drvdata(ofdev);
struct fs_enet_private *fep = netdev_priv(ndev);
unregister_netdev(ndev);
fep->ops->free_bd(ndev);
fep->ops->cleanup_data(ndev);
dev_set_drvdata(fep->dev, NULL);
of_node_put(fep->fpi->phy_node);
if (fep->fpi->clk_per)
clk_disable_unprepare(fep->fpi->clk_per);
if (of_phy_is_fixed_link(ofdev->dev.of_node))
of_phy_deregister_fixed_link(ofdev->dev.of_node);
free_netdev(ndev);
return 0;
}
static void fs_enet_netpoll(struct net_device *dev)
{
disable_irq(dev->irq);
fs_enet_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
