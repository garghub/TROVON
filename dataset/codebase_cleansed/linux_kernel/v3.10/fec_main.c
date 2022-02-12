static struct bufdesc *fec_enet_get_nextdesc(struct bufdesc *bdp, int is_ex)
{
struct bufdesc_ex *ex = (struct bufdesc_ex *)bdp;
if (is_ex)
return (struct bufdesc *)(ex + 1);
else
return bdp + 1;
}
static struct bufdesc *fec_enet_get_prevdesc(struct bufdesc *bdp, int is_ex)
{
struct bufdesc_ex *ex = (struct bufdesc_ex *)bdp;
if (is_ex)
return (struct bufdesc *)(ex - 1);
else
return bdp - 1;
}
static void *swap_buffer(void *bufaddr, int len)
{
int i;
unsigned int *buf = bufaddr;
for (i = 0; i < (len + 3) / 4; i++, buf++)
*buf = cpu_to_be32(*buf);
return bufaddr;
}
static int
fec_enet_clear_csum(struct sk_buff *skb, struct net_device *ndev)
{
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (unlikely(skb_cow_head(skb, 0)))
return -1;
*(__sum16 *)(skb->head + skb->csum_start + skb->csum_offset) = 0;
return 0;
}
static netdev_tx_t
fec_enet_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct bufdesc *bdp;
void *bufaddr;
unsigned short status;
unsigned int index;
if (!fep->link) {
return NETDEV_TX_BUSY;
}
bdp = fep->cur_tx;
status = bdp->cbd_sc;
if (status & BD_ENET_TX_READY) {
netdev_err(ndev, "tx queue full!\n");
return NETDEV_TX_BUSY;
}
if (fec_enet_clear_csum(skb, ndev)) {
kfree_skb(skb);
return NETDEV_TX_OK;
}
status &= ~BD_ENET_TX_STATS;
bufaddr = skb->data;
bdp->cbd_datlen = skb->len;
if (fep->bufdesc_ex)
index = (struct bufdesc_ex *)bdp -
(struct bufdesc_ex *)fep->tx_bd_base;
else
index = bdp - fep->tx_bd_base;
if (((unsigned long) bufaddr) & FEC_ALIGNMENT) {
memcpy(fep->tx_bounce[index], skb->data, skb->len);
bufaddr = fep->tx_bounce[index];
}
if (id_entry->driver_data & FEC_QUIRK_SWAP_FRAME)
swap_buffer(bufaddr, skb->len);
fep->tx_skbuff[index] = skb;
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, bufaddr,
FEC_ENET_TX_FRSIZE, DMA_TO_DEVICE);
status |= (BD_ENET_TX_READY | BD_ENET_TX_INTR
| BD_ENET_TX_LAST | BD_ENET_TX_TC);
bdp->cbd_sc = status;
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_bdu = 0;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP &&
fep->hwts_tx_en)) {
ebdp->cbd_esc = (BD_ENET_TX_TS | BD_ENET_TX_INT);
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
} else {
ebdp->cbd_esc = BD_ENET_TX_INT;
if (skb->ip_summed == CHECKSUM_PARTIAL)
ebdp->cbd_esc |= BD_ENET_TX_PINS;
}
}
if (status & BD_ENET_TX_WRAP)
bdp = fep->tx_bd_base;
else
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
fep->cur_tx = bdp;
if (fep->cur_tx == fep->dirty_tx)
netif_stop_queue(ndev);
writel(0, fep->hwp + FEC_X_DES_ACTIVE);
skb_tx_timestamp(skb);
return NETDEV_TX_OK;
}
static void fec_enet_bd_init(struct net_device *dev)
{
struct fec_enet_private *fep = netdev_priv(dev);
struct bufdesc *bdp;
unsigned int i;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
if (bdp->cbd_bufaddr)
bdp->cbd_sc = BD_ENET_RX_EMPTY;
else
bdp->cbd_sc = 0;
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
}
bdp = fec_enet_get_prevdesc(bdp, fep->bufdesc_ex);
bdp->cbd_sc |= BD_SC_WRAP;
fep->cur_rx = fep->rx_bd_base;
bdp = fep->tx_bd_base;
fep->cur_tx = bdp;
for (i = 0; i < TX_RING_SIZE; i++) {
bdp->cbd_sc = 0;
if (bdp->cbd_bufaddr && fep->tx_skbuff[i]) {
dev_kfree_skb_any(fep->tx_skbuff[i]);
fep->tx_skbuff[i] = NULL;
}
bdp->cbd_bufaddr = 0;
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
}
bdp = fec_enet_get_prevdesc(bdp, fep->bufdesc_ex);
bdp->cbd_sc |= BD_SC_WRAP;
fep->dirty_tx = bdp;
}
static void
fec_restart(struct net_device *ndev, int duplex)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
int i;
u32 val;
u32 temp_mac[2];
u32 rcntl = OPT_FRAME_SIZE | 0x04;
u32 ecntl = 0x2;
if (netif_running(ndev)) {
netif_device_detach(ndev);
napi_disable(&fep->napi);
netif_stop_queue(ndev);
netif_tx_lock_bh(ndev);
}
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
memcpy(&temp_mac, ndev->dev_addr, ETH_ALEN);
writel(cpu_to_be32(temp_mac[0]), fep->hwp + FEC_ADDR_LOW);
writel(cpu_to_be32(temp_mac[1]), fep->hwp + FEC_ADDR_HIGH);
}
writel(0xffc00000, fep->hwp + FEC_IEVENT);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
#ifndef CONFIG_M5272
writel(0, fep->hwp + FEC_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_HASH_TABLE_LOW);
#endif
writel(PKT_MAXBLR_SIZE, fep->hwp + FEC_R_BUFF_SIZE);
fec_enet_bd_init(ndev);
writel(fep->bd_dma, fep->hwp + FEC_R_DES_START);
if (fep->bufdesc_ex)
writel((unsigned long)fep->bd_dma + sizeof(struct bufdesc_ex)
* RX_RING_SIZE, fep->hwp + FEC_X_DES_START);
else
writel((unsigned long)fep->bd_dma + sizeof(struct bufdesc)
* RX_RING_SIZE, fep->hwp + FEC_X_DES_START);
for (i = 0; i <= TX_RING_MOD_MASK; i++) {
if (fep->tx_skbuff[i]) {
dev_kfree_skb_any(fep->tx_skbuff[i]);
fep->tx_skbuff[i] = NULL;
}
}
if (duplex) {
writel(0x04, fep->hwp + FEC_X_CNTRL);
} else {
rcntl |= 0x02;
writel(0x0, fep->hwp + FEC_X_CNTRL);
}
fep->full_duplex = duplex;
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
#if !defined(CONFIG_M5272)
val = readl(fep->hwp + FEC_RACC);
if (fep->csum_flags & FLAG_RX_CSUM_ENABLED)
val |= FEC_RACC_OPTIONS;
else
val &= ~FEC_RACC_OPTIONS;
writel(val, fep->hwp + FEC_RACC);
#endif
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
rcntl |= 0x40000000 | 0x00000020;
if (fep->phy_interface == PHY_INTERFACE_MODE_RGMII)
rcntl |= (1 << 6);
else if (fep->phy_interface == PHY_INTERFACE_MODE_RMII)
rcntl |= (1 << 8);
else
rcntl &= ~(1 << 8);
if (fep->phy_dev) {
if (fep->phy_dev->speed == SPEED_1000)
ecntl |= (1 << 5);
else if (fep->phy_dev->speed == SPEED_100)
rcntl &= ~(1 << 9);
else
rcntl |= (1 << 9);
}
} else {
#ifdef FEC_MIIGSK_ENR
if (id_entry->driver_data & FEC_QUIRK_USE_GASKET) {
u32 cfgr;
writel(0, fep->hwp + FEC_MIIGSK_ENR);
while (readl(fep->hwp + FEC_MIIGSK_ENR) & 4)
udelay(1);
cfgr = (fep->phy_interface == PHY_INTERFACE_MODE_RMII)
? BM_MIIGSK_CFGR_RMII : BM_MIIGSK_CFGR_MII;
if (fep->phy_dev && fep->phy_dev->speed == SPEED_10)
cfgr |= BM_MIIGSK_CFGR_FRCONT_10M;
writel(cfgr, fep->hwp + FEC_MIIGSK_CFGR);
writel(2, fep->hwp + FEC_MIIGSK_ENR);
}
#endif
}
#if !defined(CONFIG_M5272)
if ((fep->pause_flag & FEC_PAUSE_FLAG_ENABLE) ||
((fep->pause_flag & FEC_PAUSE_FLAG_AUTONEG) &&
fep->phy_dev && fep->phy_dev->pause)) {
rcntl |= FEC_ENET_FCE;
writel(FEC_ENET_RSEM_V, fep->hwp + FEC_R_FIFO_RSEM);
writel(FEC_ENET_RSFL_V, fep->hwp + FEC_R_FIFO_RSFL);
writel(FEC_ENET_RAEM_V, fep->hwp + FEC_R_FIFO_RAEM);
writel(FEC_ENET_RAFL_V, fep->hwp + FEC_R_FIFO_RAFL);
writel(FEC_ENET_OPD_V, fep->hwp + FEC_OPD);
} else {
rcntl &= ~FEC_ENET_FCE;
}
#endif
writel(rcntl, fep->hwp + FEC_R_CNTRL);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
ecntl |= (1 << 8);
writel(1 << 8, fep->hwp + FEC_X_WMRK);
}
if (fep->bufdesc_ex)
ecntl |= (1 << 4);
writel(ecntl, fep->hwp + FEC_ECNTRL);
writel(0, fep->hwp + FEC_R_DES_ACTIVE);
if (fep->bufdesc_ex)
fec_ptp_start_cyclecounter(ndev);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
if (netif_running(ndev)) {
netif_tx_unlock_bh(ndev);
netif_wake_queue(ndev);
napi_enable(&fep->napi);
netif_device_attach(ndev);
}
}
static void
fec_stop(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
u32 rmii_mode = readl(fep->hwp + FEC_R_CNTRL) & (1 << 8);
if (fep->link) {
writel(1, fep->hwp + FEC_X_CNTRL);
udelay(10);
if (!(readl(fep->hwp + FEC_IEVENT) & FEC_ENET_GRA))
netdev_err(ndev, "Graceful transmit stop did not complete!\n");
}
writel(1, fep->hwp + FEC_ECNTRL);
udelay(10);
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC) {
writel(2, fep->hwp + FEC_ECNTRL);
writel(rmii_mode, fep->hwp + FEC_R_CNTRL);
}
}
static void
fec_timeout(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
ndev->stats.tx_errors++;
fep->delay_work.timeout = true;
schedule_delayed_work(&(fep->delay_work.delay_work), 0);
}
static void fec_enet_work(struct work_struct *work)
{
struct fec_enet_private *fep =
container_of(work,
struct fec_enet_private,
delay_work.delay_work.work);
if (fep->delay_work.timeout) {
fep->delay_work.timeout = false;
fec_restart(fep->netdev, fep->full_duplex);
netif_wake_queue(fep->netdev);
}
}
static void
fec_enet_tx(struct net_device *ndev)
{
struct fec_enet_private *fep;
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb;
int index = 0;
fep = netdev_priv(ndev);
bdp = fep->dirty_tx;
if (bdp->cbd_sc & BD_ENET_TX_WRAP)
bdp = fep->tx_bd_base;
else
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
while (((status = bdp->cbd_sc) & BD_ENET_TX_READY) == 0) {
if (bdp == fep->cur_tx)
break;
if (fep->bufdesc_ex)
index = (struct bufdesc_ex *)bdp -
(struct bufdesc_ex *)fep->tx_bd_base;
else
index = bdp - fep->tx_bd_base;
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_TX_FRSIZE, DMA_TO_DEVICE);
bdp->cbd_bufaddr = 0;
skb = fep->tx_skbuff[index];
if (status & (BD_ENET_TX_HB | BD_ENET_TX_LC |
BD_ENET_TX_RL | BD_ENET_TX_UN |
BD_ENET_TX_CSL)) {
ndev->stats.tx_errors++;
if (status & BD_ENET_TX_HB)
ndev->stats.tx_heartbeat_errors++;
if (status & BD_ENET_TX_LC)
ndev->stats.tx_window_errors++;
if (status & BD_ENET_TX_RL)
ndev->stats.tx_aborted_errors++;
if (status & BD_ENET_TX_UN)
ndev->stats.tx_fifo_errors++;
if (status & BD_ENET_TX_CSL)
ndev->stats.tx_carrier_errors++;
} else {
ndev->stats.tx_packets++;
}
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS) &&
fep->bufdesc_ex) {
struct skb_shared_hwtstamps shhwtstamps;
unsigned long flags;
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
spin_lock_irqsave(&fep->tmreg_lock, flags);
shhwtstamps.hwtstamp = ns_to_ktime(
timecounter_cyc2time(&fep->tc, ebdp->ts));
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
skb_tstamp_tx(skb, &shhwtstamps);
}
if (status & BD_ENET_TX_READY)
netdev_err(ndev, "HEY! Enet xmit interrupt and TX_READY\n");
if (status & BD_ENET_TX_DEF)
ndev->stats.collisions++;
dev_kfree_skb_any(skb);
fep->tx_skbuff[index] = NULL;
fep->dirty_tx = bdp;
if (status & BD_ENET_TX_WRAP)
bdp = fep->tx_bd_base;
else
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
if (fep->dirty_tx != fep->cur_tx) {
if (netif_queue_stopped(ndev))
netif_wake_queue(ndev);
}
}
return;
}
static int
fec_enet_rx(struct net_device *ndev, int budget)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct bufdesc *bdp;
unsigned short status;
struct sk_buff *skb;
ushort pkt_len;
__u8 *data;
int pkt_received = 0;
#ifdef CONFIG_M532x
flush_cache_all();
#endif
bdp = fep->cur_rx;
while (!((status = bdp->cbd_sc) & BD_ENET_RX_EMPTY)) {
if (pkt_received >= budget)
break;
pkt_received++;
if ((status & BD_ENET_RX_LAST) == 0)
netdev_err(ndev, "rcv is not +last\n");
if (!fep->opened)
goto rx_processing_done;
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH | BD_ENET_RX_NO |
BD_ENET_RX_CR | BD_ENET_RX_OV)) {
ndev->stats.rx_errors++;
if (status & (BD_ENET_RX_LG | BD_ENET_RX_SH)) {
ndev->stats.rx_length_errors++;
}
if (status & BD_ENET_RX_NO)
ndev->stats.rx_frame_errors++;
if (status & BD_ENET_RX_CR)
ndev->stats.rx_crc_errors++;
if (status & BD_ENET_RX_OV)
ndev->stats.rx_fifo_errors++;
}
if (status & BD_ENET_RX_CL) {
ndev->stats.rx_errors++;
ndev->stats.rx_frame_errors++;
goto rx_processing_done;
}
ndev->stats.rx_packets++;
pkt_len = bdp->cbd_datlen;
ndev->stats.rx_bytes += pkt_len;
data = (__u8*)__va(bdp->cbd_bufaddr);
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_TX_FRSIZE, DMA_FROM_DEVICE);
if (id_entry->driver_data & FEC_QUIRK_SWAP_FRAME)
swap_buffer(data, pkt_len);
skb = netdev_alloc_skb(ndev, pkt_len - 4 + NET_IP_ALIGN);
if (unlikely(!skb)) {
ndev->stats.rx_dropped++;
} else {
skb_reserve(skb, NET_IP_ALIGN);
skb_put(skb, pkt_len - 4);
skb_copy_to_linear_data(skb, data, pkt_len - 4);
skb->protocol = eth_type_trans(skb, ndev);
if (fep->hwts_rx_en && fep->bufdesc_ex) {
struct skb_shared_hwtstamps *shhwtstamps =
skb_hwtstamps(skb);
unsigned long flags;
struct bufdesc_ex *ebdp =
(struct bufdesc_ex *)bdp;
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
spin_lock_irqsave(&fep->tmreg_lock, flags);
shhwtstamps->hwtstamp = ns_to_ktime(
timecounter_cyc2time(&fep->tc, ebdp->ts));
spin_unlock_irqrestore(&fep->tmreg_lock, flags);
}
if (fep->bufdesc_ex &&
(fep->csum_flags & FLAG_RX_CSUM_ENABLED)) {
struct bufdesc_ex *ebdp =
(struct bufdesc_ex *)bdp;
if (!(ebdp->cbd_esc & FLAG_RX_CSUM_ERROR)) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
} else {
skb_checksum_none_assert(skb);
}
}
if (!skb_defer_rx_timestamp(skb))
napi_gro_receive(&fep->napi, skb);
}
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, data,
FEC_ENET_TX_FRSIZE, DMA_FROM_DEVICE);
rx_processing_done:
status &= ~BD_ENET_RX_STATS;
status |= BD_ENET_RX_EMPTY;
bdp->cbd_sc = status;
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = BD_ENET_RX_INT;
ebdp->cbd_prot = 0;
ebdp->cbd_bdu = 0;
}
if (status & BD_ENET_RX_WRAP)
bdp = fep->rx_bd_base;
else
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
writel(0, fep->hwp + FEC_R_DES_ACTIVE);
}
fep->cur_rx = bdp;
return pkt_received;
}
static irqreturn_t
fec_enet_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct fec_enet_private *fep = netdev_priv(ndev);
uint int_events;
irqreturn_t ret = IRQ_NONE;
do {
int_events = readl(fep->hwp + FEC_IEVENT);
writel(int_events, fep->hwp + FEC_IEVENT);
if (int_events & (FEC_ENET_RXF | FEC_ENET_TXF)) {
ret = IRQ_HANDLED;
if (napi_schedule_prep(&fep->napi)) {
writel(FEC_RX_DISABLED_IMASK,
fep->hwp + FEC_IMASK);
__napi_schedule(&fep->napi);
}
}
if (int_events & FEC_ENET_MII) {
ret = IRQ_HANDLED;
complete(&fep->mdio_done);
}
} while (int_events);
return ret;
}
static int fec_enet_rx_napi(struct napi_struct *napi, int budget)
{
struct net_device *ndev = napi->dev;
int pkts = fec_enet_rx(ndev, budget);
struct fec_enet_private *fep = netdev_priv(ndev);
fec_enet_tx(ndev);
if (pkts < budget) {
napi_complete(napi);
writel(FEC_DEFAULT_IMASK, fep->hwp + FEC_IMASK);
}
return pkts;
}
static void fec_get_mac(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct fec_platform_data *pdata = fep->pdev->dev.platform_data;
unsigned char *iap, tmpaddr[ETH_ALEN];
iap = macaddr;
if (!is_valid_ether_addr(iap)) {
struct device_node *np = fep->pdev->dev.of_node;
if (np) {
const char *mac = of_get_mac_address(np);
if (mac)
iap = (unsigned char *) mac;
}
}
if (!is_valid_ether_addr(iap)) {
#ifdef CONFIG_M5272
if (FEC_FLASHMAC)
iap = (unsigned char *)FEC_FLASHMAC;
#else
if (pdata)
iap = (unsigned char *)&pdata->mac;
#endif
}
if (!is_valid_ether_addr(iap)) {
*((unsigned long *) &tmpaddr[0]) =
be32_to_cpu(readl(fep->hwp + FEC_ADDR_LOW));
*((unsigned short *) &tmpaddr[4]) =
be16_to_cpu(readl(fep->hwp + FEC_ADDR_HIGH) >> 16);
iap = &tmpaddr[0];
}
if (!is_valid_ether_addr(iap)) {
netdev_err(ndev, "Invalid MAC address: %pM\n", iap);
eth_hw_addr_random(ndev);
netdev_info(ndev, "Using random MAC address: %pM\n",
ndev->dev_addr);
return;
}
memcpy(ndev->dev_addr, iap, ETH_ALEN);
if (iap == macaddr)
ndev->dev_addr[ETH_ALEN-1] = macaddr[ETH_ALEN-1] + fep->dev_id;
}
static void fec_enet_adjust_link(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phy_dev = fep->phy_dev;
int status_change = 0;
if (fep->mii_timeout && phy_dev->state == PHY_HALTED) {
phy_dev->state = PHY_RESUMING;
return;
}
if (phy_dev->link) {
if (!fep->link) {
fep->link = phy_dev->link;
status_change = 1;
}
if (fep->full_duplex != phy_dev->duplex)
status_change = 1;
if (phy_dev->speed != fep->speed) {
fep->speed = phy_dev->speed;
status_change = 1;
}
if (status_change)
fec_restart(ndev, phy_dev->duplex);
} else {
if (fep->link) {
fec_stop(ndev);
fep->link = phy_dev->link;
status_change = 1;
}
}
if (status_change)
phy_print_status(phy_dev);
}
static int fec_enet_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct fec_enet_private *fep = bus->priv;
unsigned long time_left;
fep->mii_timeout = 0;
init_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_READ |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA, fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
netdev_err(fep->netdev, "MDIO read timeout\n");
return -ETIMEDOUT;
}
return FEC_MMFR_DATA(readl(fep->hwp + FEC_MII_DATA));
}
static int fec_enet_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct fec_enet_private *fep = bus->priv;
unsigned long time_left;
fep->mii_timeout = 0;
init_completion(&fep->mdio_done);
writel(FEC_MMFR_ST | FEC_MMFR_OP_WRITE |
FEC_MMFR_PA(mii_id) | FEC_MMFR_RA(regnum) |
FEC_MMFR_TA | FEC_MMFR_DATA(value),
fep->hwp + FEC_MII_DATA);
time_left = wait_for_completion_timeout(&fep->mdio_done,
usecs_to_jiffies(FEC_MII_TIMEOUT));
if (time_left == 0) {
fep->mii_timeout = 1;
netdev_err(fep->netdev, "MDIO write timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int fec_enet_mdio_reset(struct mii_bus *bus)
{
return 0;
}
static int fec_enet_mii_probe(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct phy_device *phy_dev = NULL;
char mdio_bus_id[MII_BUS_ID_SIZE];
char phy_name[MII_BUS_ID_SIZE + 3];
int phy_id;
int dev_id = fep->dev_id;
fep->phy_dev = NULL;
for (phy_id = 0; (phy_id < PHY_MAX_ADDR); phy_id++) {
if ((fep->mii_bus->phy_mask & (1 << phy_id)))
continue;
if (fep->mii_bus->phy_map[phy_id] == NULL)
continue;
if (fep->mii_bus->phy_map[phy_id]->phy_id == 0)
continue;
if (dev_id--)
continue;
strncpy(mdio_bus_id, fep->mii_bus->id, MII_BUS_ID_SIZE);
break;
}
if (phy_id >= PHY_MAX_ADDR) {
netdev_info(ndev, "no PHY, assuming direct connection to switch\n");
strncpy(mdio_bus_id, "fixed-0", MII_BUS_ID_SIZE);
phy_id = 0;
}
snprintf(phy_name, sizeof(phy_name), PHY_ID_FMT, mdio_bus_id, phy_id);
phy_dev = phy_connect(ndev, phy_name, &fec_enet_adjust_link,
fep->phy_interface);
if (IS_ERR(phy_dev)) {
netdev_err(ndev, "could not attach to PHY\n");
return PTR_ERR(phy_dev);
}
if (id_entry->driver_data & FEC_QUIRK_HAS_GBIT) {
phy_dev->supported &= PHY_GBIT_FEATURES;
#if !defined(CONFIG_M5272)
phy_dev->supported |= SUPPORTED_Pause;
#endif
}
else
phy_dev->supported &= PHY_BASIC_FEATURES;
phy_dev->advertising = phy_dev->supported;
fep->phy_dev = phy_dev;
fep->link = 0;
fep->full_duplex = 0;
netdev_info(ndev, "Freescale FEC PHY driver [%s] (mii_bus:phy_addr=%s, irq=%d)\n",
fep->phy_dev->drv->name, dev_name(&fep->phy_dev->dev),
fep->phy_dev->irq);
return 0;
}
static int fec_enet_mii_init(struct platform_device *pdev)
{
static struct mii_bus *fec0_mii_bus;
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
int err = -ENXIO, i;
if ((id_entry->driver_data & FEC_QUIRK_ENET_MAC) && fep->dev_id > 0) {
if (mii_cnt && fec0_mii_bus) {
fep->mii_bus = fec0_mii_bus;
mii_cnt++;
return 0;
}
return -ENOENT;
}
fep->mii_timeout = 0;
fep->phy_speed = DIV_ROUND_UP(clk_get_rate(fep->clk_ahb), 5000000);
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC)
fep->phy_speed--;
fep->phy_speed <<= 1;
writel(fep->phy_speed, fep->hwp + FEC_MII_SPEED);
fep->mii_bus = mdiobus_alloc();
if (fep->mii_bus == NULL) {
err = -ENOMEM;
goto err_out;
}
fep->mii_bus->name = "fec_enet_mii_bus";
fep->mii_bus->read = fec_enet_mdio_read;
fep->mii_bus->write = fec_enet_mdio_write;
fep->mii_bus->reset = fec_enet_mdio_reset;
snprintf(fep->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, fep->dev_id + 1);
fep->mii_bus->priv = fep;
fep->mii_bus->parent = &pdev->dev;
fep->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!fep->mii_bus->irq) {
err = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
fep->mii_bus->irq[i] = PHY_POLL;
if (mdiobus_register(fep->mii_bus))
goto err_out_free_mdio_irq;
mii_cnt++;
if (id_entry->driver_data & FEC_QUIRK_ENET_MAC)
fec0_mii_bus = fep->mii_bus;
return 0;
err_out_free_mdio_irq:
kfree(fep->mii_bus->irq);
err_out_free_mdiobus:
mdiobus_free(fep->mii_bus);
err_out:
return err;
}
static void fec_enet_mii_remove(struct fec_enet_private *fep)
{
if (--mii_cnt == 0) {
mdiobus_unregister(fep->mii_bus);
kfree(fep->mii_bus->irq);
mdiobus_free(fep->mii_bus);
}
}
static int fec_enet_get_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_gset(phydev, cmd);
}
static int fec_enet_set_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, cmd);
}
static void fec_enet_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct fec_enet_private *fep = netdev_priv(ndev);
strlcpy(info->driver, fep->pdev->dev.driver->name,
sizeof(info->driver));
strlcpy(info->version, "Revision: 1.0", sizeof(info->version));
strlcpy(info->bus_info, dev_name(&ndev->dev), sizeof(info->bus_info));
}
static int fec_enet_get_ts_info(struct net_device *ndev,
struct ethtool_ts_info *info)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (fep->bufdesc_ex) {
info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (fep->ptp_clock)
info->phc_index = ptp_clock_index(fep->ptp_clock);
else
info->phc_index = -1;
info->tx_types = (1 << HWTSTAMP_TX_OFF) |
(1 << HWTSTAMP_TX_ON);
info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_ALL);
return 0;
} else {
return ethtool_op_get_ts_info(ndev, info);
}
}
static void fec_enet_get_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct fec_enet_private *fep = netdev_priv(ndev);
pause->autoneg = (fep->pause_flag & FEC_PAUSE_FLAG_AUTONEG) != 0;
pause->tx_pause = (fep->pause_flag & FEC_PAUSE_FLAG_ENABLE) != 0;
pause->rx_pause = pause->tx_pause;
}
static int fec_enet_set_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pause)
{
struct fec_enet_private *fep = netdev_priv(ndev);
if (pause->tx_pause != pause->rx_pause) {
netdev_info(ndev,
"hardware only support enable/disable both tx and rx");
return -EINVAL;
}
fep->pause_flag = 0;
fep->pause_flag |= pause->rx_pause ? FEC_PAUSE_FLAG_ENABLE : 0;
fep->pause_flag |= pause->autoneg ? FEC_PAUSE_FLAG_AUTONEG : 0;
if (pause->rx_pause || pause->autoneg) {
fep->phy_dev->supported |= ADVERTISED_Pause;
fep->phy_dev->advertising |= ADVERTISED_Pause;
} else {
fep->phy_dev->supported &= ~ADVERTISED_Pause;
fep->phy_dev->advertising &= ~ADVERTISED_Pause;
}
if (pause->autoneg) {
if (netif_running(ndev))
fec_stop(ndev);
phy_start_aneg(fep->phy_dev);
}
if (netif_running(ndev))
fec_restart(ndev, 0);
return 0;
}
static int fec_enet_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct phy_device *phydev = fep->phy_dev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
if (cmd == SIOCSHWTSTAMP && fep->bufdesc_ex)
return fec_ptp_ioctl(ndev, rq, cmd);
return phy_mii_ioctl(phydev, rq, cmd);
}
static void fec_enet_free_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
struct sk_buff *skb;
struct bufdesc *bdp;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
skb = fep->rx_skbuff[i];
if (bdp->cbd_bufaddr)
dma_unmap_single(&fep->pdev->dev, bdp->cbd_bufaddr,
FEC_ENET_RX_FRSIZE, DMA_FROM_DEVICE);
if (skb)
dev_kfree_skb(skb);
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
}
bdp = fep->tx_bd_base;
for (i = 0; i < TX_RING_SIZE; i++)
kfree(fep->tx_bounce[i]);
}
static int fec_enet_alloc_buffers(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
unsigned int i;
struct sk_buff *skb;
struct bufdesc *bdp;
bdp = fep->rx_bd_base;
for (i = 0; i < RX_RING_SIZE; i++) {
skb = netdev_alloc_skb(ndev, FEC_ENET_RX_FRSIZE);
if (!skb) {
fec_enet_free_buffers(ndev);
return -ENOMEM;
}
fep->rx_skbuff[i] = skb;
bdp->cbd_bufaddr = dma_map_single(&fep->pdev->dev, skb->data,
FEC_ENET_RX_FRSIZE, DMA_FROM_DEVICE);
bdp->cbd_sc = BD_ENET_RX_EMPTY;
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = BD_ENET_RX_INT;
}
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
}
bdp = fec_enet_get_prevdesc(bdp, fep->bufdesc_ex);
bdp->cbd_sc |= BD_SC_WRAP;
bdp = fep->tx_bd_base;
for (i = 0; i < TX_RING_SIZE; i++) {
fep->tx_bounce[i] = kmalloc(FEC_ENET_TX_FRSIZE, GFP_KERNEL);
bdp->cbd_sc = 0;
bdp->cbd_bufaddr = 0;
if (fep->bufdesc_ex) {
struct bufdesc_ex *ebdp = (struct bufdesc_ex *)bdp;
ebdp->cbd_esc = BD_ENET_TX_INT;
}
bdp = fec_enet_get_nextdesc(bdp, fep->bufdesc_ex);
}
bdp = fec_enet_get_prevdesc(bdp, fep->bufdesc_ex);
bdp->cbd_sc |= BD_SC_WRAP;
return 0;
}
static int
fec_enet_open(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
int ret;
napi_enable(&fep->napi);
ret = fec_enet_alloc_buffers(ndev);
if (ret)
return ret;
ret = fec_enet_mii_probe(ndev);
if (ret) {
fec_enet_free_buffers(ndev);
return ret;
}
phy_start(fep->phy_dev);
netif_start_queue(ndev);
fep->opened = 1;
return 0;
}
static int
fec_enet_close(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
napi_disable(&fep->napi);
fep->opened = 0;
netif_stop_queue(ndev);
fec_stop(ndev);
if (fep->phy_dev) {
phy_stop(fep->phy_dev);
phy_disconnect(fep->phy_dev);
}
fec_enet_free_buffers(ndev);
return 0;
}
static void set_multicast_list(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct netdev_hw_addr *ha;
unsigned int i, bit, data, crc, tmp;
unsigned char hash;
if (ndev->flags & IFF_PROMISC) {
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp |= 0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
return;
}
tmp = readl(fep->hwp + FEC_R_CNTRL);
tmp &= ~0x8;
writel(tmp, fep->hwp + FEC_R_CNTRL);
if (ndev->flags & IFF_ALLMULTI) {
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0xffffffff, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
return;
}
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
writel(0, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
netdev_for_each_mc_addr(ha, ndev) {
crc = 0xffffffff;
for (i = 0; i < ndev->addr_len; i++) {
data = ha->addr[i];
for (bit = 0; bit < 8; bit++, data >>= 1) {
crc = (crc >> 1) ^
(((crc ^ data) & 1) ? CRC32_POLY : 0);
}
}
hash = (crc >> (32 - HASH_BITS)) & 0x3f;
if (hash > 31) {
tmp = readl(fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
tmp |= 1 << (hash - 32);
writel(tmp, fep->hwp + FEC_GRP_HASH_TABLE_HIGH);
} else {
tmp = readl(fep->hwp + FEC_GRP_HASH_TABLE_LOW);
tmp |= 1 << hash;
writel(tmp, fep->hwp + FEC_GRP_HASH_TABLE_LOW);
}
}
}
static int
fec_set_mac_address(struct net_device *ndev, void *p)
{
struct fec_enet_private *fep = netdev_priv(ndev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, addr->sa_data, ndev->addr_len);
writel(ndev->dev_addr[3] | (ndev->dev_addr[2] << 8) |
(ndev->dev_addr[1] << 16) | (ndev->dev_addr[0] << 24),
fep->hwp + FEC_ADDR_LOW);
writel((ndev->dev_addr[5] << 16) | (ndev->dev_addr[4] << 24),
fep->hwp + FEC_ADDR_HIGH);
return 0;
}
static void fec_poll_controller(struct net_device *dev)
{
int i;
struct fec_enet_private *fep = netdev_priv(dev);
for (i = 0; i < FEC_IRQ_NUM; i++) {
if (fep->irq[i] > 0) {
disable_irq(fep->irq[i]);
fec_enet_interrupt(fep->irq[i], dev);
enable_irq(fep->irq[i]);
}
}
}
static int fec_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct fec_enet_private *fep = netdev_priv(netdev);
netdev_features_t changed = features ^ netdev->features;
netdev->features = features;
if (changed & NETIF_F_RXCSUM) {
if (features & NETIF_F_RXCSUM)
fep->csum_flags |= FLAG_RX_CSUM_ENABLED;
else
fep->csum_flags &= ~FLAG_RX_CSUM_ENABLED;
if (netif_running(netdev)) {
fec_stop(netdev);
fec_restart(netdev, fep->phy_dev->duplex);
netif_wake_queue(netdev);
} else {
fec_restart(netdev, fep->phy_dev->duplex);
}
}
return 0;
}
static int fec_enet_init(struct net_device *ndev)
{
struct fec_enet_private *fep = netdev_priv(ndev);
const struct platform_device_id *id_entry =
platform_get_device_id(fep->pdev);
struct bufdesc *cbd_base;
cbd_base = dma_alloc_coherent(NULL, PAGE_SIZE, &fep->bd_dma,
GFP_KERNEL);
if (!cbd_base)
return -ENOMEM;
memset(cbd_base, 0, PAGE_SIZE);
fep->netdev = ndev;
fec_get_mac(ndev);
fep->rx_bd_base = cbd_base;
if (fep->bufdesc_ex)
fep->tx_bd_base = (struct bufdesc *)
(((struct bufdesc_ex *)cbd_base) + RX_RING_SIZE);
else
fep->tx_bd_base = cbd_base + RX_RING_SIZE;
ndev->watchdog_timeo = TX_TIMEOUT;
ndev->netdev_ops = &fec_netdev_ops;
ndev->ethtool_ops = &fec_enet_ethtool_ops;
writel(FEC_RX_DISABLED_IMASK, fep->hwp + FEC_IMASK);
netif_napi_add(ndev, &fep->napi, fec_enet_rx_napi, FEC_NAPI_WEIGHT);
if (id_entry->driver_data & FEC_QUIRK_HAS_CSUM) {
ndev->features |= (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM
| NETIF_F_RXCSUM);
ndev->hw_features |= (NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM
| NETIF_F_RXCSUM);
fep->csum_flags |= FLAG_RX_CSUM_ENABLED;
}
fec_restart(ndev, 0);
return 0;
}
static void fec_reset_phy(struct platform_device *pdev)
{
int err, phy_reset;
int msec = 1;
struct device_node *np = pdev->dev.of_node;
if (!np)
return;
of_property_read_u32(np, "phy-reset-duration", &msec);
if (msec > 1000)
msec = 1;
phy_reset = of_get_named_gpio(np, "phy-reset-gpios", 0);
if (!gpio_is_valid(phy_reset))
return;
err = devm_gpio_request_one(&pdev->dev, phy_reset,
GPIOF_OUT_INIT_LOW, "phy-reset");
if (err) {
dev_err(&pdev->dev, "failed to get phy-reset-gpios: %d\n", err);
return;
}
msleep(msec);
gpio_set_value(phy_reset, 1);
}
static void fec_reset_phy(struct platform_device *pdev)
{
}
static int
fec_probe(struct platform_device *pdev)
{
struct fec_enet_private *fep;
struct fec_platform_data *pdata;
struct net_device *ndev;
int i, irq, ret = 0;
struct resource *r;
const struct of_device_id *of_id;
static int dev_id;
struct pinctrl *pinctrl;
struct regulator *reg_phy;
of_id = of_match_device(fec_dt_ids, &pdev->dev);
if (of_id)
pdev->id_entry = of_id->data;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENXIO;
ndev = alloc_etherdev(sizeof(struct fec_enet_private));
if (!ndev)
return -ENOMEM;
SET_NETDEV_DEV(ndev, &pdev->dev);
fep = netdev_priv(ndev);
#if !defined(CONFIG_M5272)
if (pdev->id_entry &&
(pdev->id_entry->driver_data & FEC_QUIRK_HAS_GBIT))
fep->pause_flag |= FEC_PAUSE_FLAG_AUTONEG;
#endif
fep->hwp = devm_request_and_ioremap(&pdev->dev, r);
fep->pdev = pdev;
fep->dev_id = dev_id++;
fep->bufdesc_ex = 0;
if (!fep->hwp) {
ret = -ENOMEM;
goto failed_ioremap;
}
platform_set_drvdata(pdev, ndev);
ret = of_get_phy_mode(pdev->dev.of_node);
if (ret < 0) {
pdata = pdev->dev.platform_data;
if (pdata)
fep->phy_interface = pdata->phy;
else
fep->phy_interface = PHY_INTERFACE_MODE_MII;
} else {
fep->phy_interface = ret;
}
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
ret = PTR_ERR(pinctrl);
goto failed_pin;
}
fep->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(fep->clk_ipg)) {
ret = PTR_ERR(fep->clk_ipg);
goto failed_clk;
}
fep->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(fep->clk_ahb)) {
ret = PTR_ERR(fep->clk_ahb);
goto failed_clk;
}
fep->clk_enet_out = devm_clk_get(&pdev->dev, "enet_out");
if (IS_ERR(fep->clk_enet_out))
fep->clk_enet_out = NULL;
fep->clk_ptp = devm_clk_get(&pdev->dev, "ptp");
fep->bufdesc_ex =
pdev->id_entry->driver_data & FEC_QUIRK_HAS_BUFDESC_EX;
if (IS_ERR(fep->clk_ptp)) {
fep->clk_ptp = NULL;
fep->bufdesc_ex = 0;
}
clk_prepare_enable(fep->clk_ahb);
clk_prepare_enable(fep->clk_ipg);
clk_prepare_enable(fep->clk_enet_out);
clk_prepare_enable(fep->clk_ptp);
reg_phy = devm_regulator_get(&pdev->dev, "phy");
if (!IS_ERR(reg_phy)) {
ret = regulator_enable(reg_phy);
if (ret) {
dev_err(&pdev->dev,
"Failed to enable phy regulator: %d\n", ret);
goto failed_regulator;
}
}
fec_reset_phy(pdev);
if (fep->bufdesc_ex)
fec_ptp_init(ndev, pdev);
ret = fec_enet_init(ndev);
if (ret)
goto failed_init;
for (i = 0; i < FEC_IRQ_NUM; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0) {
if (i)
break;
ret = irq;
goto failed_irq;
}
ret = request_irq(irq, fec_enet_interrupt, IRQF_DISABLED, pdev->name, ndev);
if (ret) {
while (--i >= 0) {
irq = platform_get_irq(pdev, i);
free_irq(irq, ndev);
}
goto failed_irq;
}
}
ret = fec_enet_mii_init(pdev);
if (ret)
goto failed_mii_init;
netif_carrier_off(ndev);
ret = register_netdev(ndev);
if (ret)
goto failed_register;
if (fep->bufdesc_ex && fep->ptp_clock)
netdev_info(ndev, "registered PHC device %d\n", fep->dev_id);
INIT_DELAYED_WORK(&(fep->delay_work.delay_work), fec_enet_work);
return 0;
failed_register:
fec_enet_mii_remove(fep);
failed_mii_init:
failed_init:
for (i = 0; i < FEC_IRQ_NUM; i++) {
irq = platform_get_irq(pdev, i);
if (irq > 0)
free_irq(irq, ndev);
}
failed_irq:
failed_regulator:
clk_disable_unprepare(fep->clk_ahb);
clk_disable_unprepare(fep->clk_ipg);
clk_disable_unprepare(fep->clk_enet_out);
clk_disable_unprepare(fep->clk_ptp);
failed_pin:
failed_clk:
failed_ioremap:
free_netdev(ndev);
return ret;
}
static int
fec_drv_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct fec_enet_private *fep = netdev_priv(ndev);
int i;
cancel_delayed_work_sync(&(fep->delay_work.delay_work));
unregister_netdev(ndev);
fec_enet_mii_remove(fep);
del_timer_sync(&fep->time_keep);
clk_disable_unprepare(fep->clk_ptp);
if (fep->ptp_clock)
ptp_clock_unregister(fep->ptp_clock);
clk_disable_unprepare(fep->clk_enet_out);
clk_disable_unprepare(fep->clk_ahb);
clk_disable_unprepare(fep->clk_ipg);
for (i = 0; i < FEC_IRQ_NUM; i++) {
int irq = platform_get_irq(pdev, i);
if (irq > 0)
free_irq(irq, ndev);
}
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int
fec_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
if (netif_running(ndev)) {
fec_stop(ndev);
netif_device_detach(ndev);
}
clk_disable_unprepare(fep->clk_enet_out);
clk_disable_unprepare(fep->clk_ahb);
clk_disable_unprepare(fep->clk_ipg);
return 0;
}
static int
fec_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct fec_enet_private *fep = netdev_priv(ndev);
clk_prepare_enable(fep->clk_enet_out);
clk_prepare_enable(fep->clk_ahb);
clk_prepare_enable(fep->clk_ipg);
if (netif_running(ndev)) {
fec_restart(ndev, fep->full_duplex);
netif_device_attach(ndev);
}
return 0;
}
