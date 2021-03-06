static inline void korina_start_dma(struct dma_reg *ch, u32 dma_addr)
{
writel(0, &ch->dmandptr);
writel(dma_addr, &ch->dmadptr);
}
static inline void korina_abort_dma(struct net_device *dev,
struct dma_reg *ch)
{
if (readl(&ch->dmac) & DMA_CHAN_RUN_BIT) {
writel(0x10, &ch->dmac);
while (!(readl(&ch->dmas) & DMA_STAT_HALT))
dev->trans_start = jiffies;
writel(0, &ch->dmas);
}
writel(0, &ch->dmadptr);
writel(0, &ch->dmandptr);
}
static inline void korina_chain_dma(struct dma_reg *ch, u32 dma_addr)
{
writel(dma_addr, &ch->dmandptr);
}
static void korina_abort_tx(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
korina_abort_dma(dev, lp->tx_dma_regs);
}
static void korina_abort_rx(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
korina_abort_dma(dev, lp->rx_dma_regs);
}
static void korina_start_rx(struct korina_private *lp,
struct dma_desc *rd)
{
korina_start_dma(lp->rx_dma_regs, CPHYSADDR(rd));
}
static void korina_chain_rx(struct korina_private *lp,
struct dma_desc *rd)
{
korina_chain_dma(lp->rx_dma_regs, CPHYSADDR(rd));
}
static int korina_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
unsigned long flags;
u32 length;
u32 chain_prev, chain_next;
struct dma_desc *td;
spin_lock_irqsave(&lp->lock, flags);
td = &lp->td_ring[lp->tx_chain_tail];
if (lp->tx_count >= (KORINA_NUM_TDS - 2)) {
lp->tx_full = 1;
if (lp->tx_count == (KORINA_NUM_TDS - 2))
netif_stop_queue(dev);
else {
dev->stats.tx_dropped++;
dev_kfree_skb_any(skb);
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_BUSY;
}
}
lp->tx_count++;
lp->tx_skb[lp->tx_chain_tail] = skb;
length = skb->len;
dma_cache_wback((u32)skb->data, skb->len);
dma_cache_inv((u32) td, sizeof(*td));
td->ca = CPHYSADDR(skb->data);
chain_prev = (lp->tx_chain_tail - 1) & KORINA_TDS_MASK;
chain_next = (lp->tx_chain_tail + 1) & KORINA_TDS_MASK;
if (readl(&(lp->tx_dma_regs->dmandptr)) == 0) {
if (lp->tx_chain_status == desc_empty) {
td->control = DMA_COUNT(length) |
DMA_DESC_COF | DMA_DESC_IOF;
lp->tx_chain_tail = chain_next;
writel(CPHYSADDR(&lp->td_ring[lp->tx_chain_head]),
&lp->tx_dma_regs->dmandptr);
lp->tx_chain_head = lp->tx_chain_tail;
} else {
td->control = DMA_COUNT(length) |
DMA_DESC_COF | DMA_DESC_IOF;
lp->td_ring[chain_prev].control &=
~DMA_DESC_COF;
lp->td_ring[chain_prev].link = CPHYSADDR(td);
lp->tx_chain_tail = chain_next;
writel(CPHYSADDR(&lp->td_ring[lp->tx_chain_head]),
&(lp->tx_dma_regs->dmandptr));
lp->tx_chain_head = lp->tx_chain_tail;
lp->tx_chain_status = desc_empty;
}
} else {
if (lp->tx_chain_status == desc_empty) {
td->control = DMA_COUNT(length) |
DMA_DESC_COF | DMA_DESC_IOF;
lp->tx_chain_tail = chain_next;
lp->tx_chain_status = desc_filled;
} else {
td->control = DMA_COUNT(length) |
DMA_DESC_COF | DMA_DESC_IOF;
lp->td_ring[chain_prev].control &=
~DMA_DESC_COF;
lp->td_ring[chain_prev].link = CPHYSADDR(td);
lp->tx_chain_tail = chain_next;
}
}
dma_cache_wback((u32) td, sizeof(*td));
dev->trans_start = jiffies;
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
}
static int mdio_read(struct net_device *dev, int mii_id, int reg)
{
struct korina_private *lp = netdev_priv(dev);
int ret;
mii_id = ((lp->rx_irq == 0x2c ? 1 : 0) << 8);
writel(0, &lp->eth_regs->miimcfg);
writel(0, &lp->eth_regs->miimcmd);
writel(mii_id | reg, &lp->eth_regs->miimaddr);
writel(ETH_MII_CMD_SCN, &lp->eth_regs->miimcmd);
ret = (int)(readl(&lp->eth_regs->miimrdd));
return ret;
}
static void mdio_write(struct net_device *dev, int mii_id, int reg, int val)
{
struct korina_private *lp = netdev_priv(dev);
mii_id = ((lp->rx_irq == 0x2c ? 1 : 0) << 8);
writel(0, &lp->eth_regs->miimcfg);
writel(1, &lp->eth_regs->miimcmd);
writel(mii_id | reg, &lp->eth_regs->miimaddr);
writel(ETH_MII_CMD_SCN, &lp->eth_regs->miimcmd);
writel(val, &lp->eth_regs->miimwtd);
}
static irqreturn_t korina_rx_dma_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct korina_private *lp = netdev_priv(dev);
u32 dmas, dmasm;
irqreturn_t retval;
dmas = readl(&lp->rx_dma_regs->dmas);
if (dmas & (DMA_STAT_DONE | DMA_STAT_HALT | DMA_STAT_ERR)) {
dmasm = readl(&lp->rx_dma_regs->dmasm);
writel(dmasm | (DMA_STAT_DONE |
DMA_STAT_HALT | DMA_STAT_ERR),
&lp->rx_dma_regs->dmasm);
napi_schedule(&lp->napi);
if (dmas & DMA_STAT_ERR)
printk(KERN_ERR "%s: DMA error\n", dev->name);
retval = IRQ_HANDLED;
} else
retval = IRQ_NONE;
return retval;
}
static int korina_rx(struct net_device *dev, int limit)
{
struct korina_private *lp = netdev_priv(dev);
struct dma_desc *rd = &lp->rd_ring[lp->rx_next_done];
struct sk_buff *skb, *skb_new;
u8 *pkt_buf;
u32 devcs, pkt_len, dmas;
int count;
dma_cache_inv((u32)rd, sizeof(*rd));
for (count = 0; count < limit; count++) {
skb = lp->rx_skb[lp->rx_next_done];
skb_new = NULL;
devcs = rd->devcs;
if ((KORINA_RBSIZE - (u32)DMA_COUNT(rd->control)) == 0)
break;
if (devcs & ETH_RX_CRC)
dev->stats.rx_crc_errors++;
if (devcs & ETH_RX_LOR)
dev->stats.rx_length_errors++;
if (devcs & ETH_RX_LE)
dev->stats.rx_length_errors++;
if (devcs & ETH_RX_OVR)
dev->stats.rx_fifo_errors++;
if (devcs & ETH_RX_CV)
dev->stats.rx_frame_errors++;
if (devcs & ETH_RX_CES)
dev->stats.rx_length_errors++;
if (devcs & ETH_RX_MP)
dev->stats.multicast++;
if ((devcs & ETH_RX_LD) != ETH_RX_LD) {
dev->stats.rx_errors++;
dev->stats.rx_dropped++;
} else if ((devcs & ETH_RX_ROK)) {
pkt_len = RCVPKT_LENGTH(devcs);
pkt_buf = (u8 *)lp->rx_skb[lp->rx_next_done]->data;
dma_cache_inv((unsigned long)pkt_buf, pkt_len - 4);
skb_new = netdev_alloc_skb_ip_align(dev, KORINA_RBSIZE);
if (!skb_new)
break;
skb_put(skb, pkt_len - 4);
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
if (devcs & ETH_RX_MP)
dev->stats.multicast++;
lp->rx_skb[lp->rx_next_done] = skb_new;
}
rd->devcs = 0;
if (skb_new)
rd->ca = CPHYSADDR(skb_new->data);
else
rd->ca = CPHYSADDR(skb->data);
rd->control = DMA_COUNT(KORINA_RBSIZE) |
DMA_DESC_COD | DMA_DESC_IOD;
lp->rd_ring[(lp->rx_next_done - 1) &
KORINA_RDS_MASK].control &=
~DMA_DESC_COD;
lp->rx_next_done = (lp->rx_next_done + 1) & KORINA_RDS_MASK;
dma_cache_wback((u32)rd, sizeof(*rd));
rd = &lp->rd_ring[lp->rx_next_done];
writel(~DMA_STAT_DONE, &lp->rx_dma_regs->dmas);
}
dmas = readl(&lp->rx_dma_regs->dmas);
if (dmas & DMA_STAT_HALT) {
writel(~(DMA_STAT_HALT | DMA_STAT_ERR),
&lp->rx_dma_regs->dmas);
lp->dma_halt_cnt++;
rd->devcs = 0;
skb = lp->rx_skb[lp->rx_next_done];
rd->ca = CPHYSADDR(skb->data);
dma_cache_wback((u32)rd, sizeof(*rd));
korina_chain_rx(lp, rd);
}
return count;
}
static int korina_poll(struct napi_struct *napi, int budget)
{
struct korina_private *lp =
container_of(napi, struct korina_private, napi);
struct net_device *dev = lp->dev;
int work_done;
work_done = korina_rx(dev, budget);
if (work_done < budget) {
napi_complete(napi);
writel(readl(&lp->rx_dma_regs->dmasm) &
~(DMA_STAT_DONE | DMA_STAT_HALT | DMA_STAT_ERR),
&lp->rx_dma_regs->dmasm);
}
return work_done;
}
static void korina_multicast_list(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
unsigned long flags;
struct netdev_hw_addr *ha;
u32 recognise = ETH_ARC_AB;
if (dev->flags & IFF_PROMISC)
recognise |= ETH_ARC_PRO;
else if ((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 4))
recognise |= ETH_ARC_AM;
if (netdev_mc_count(dev) > 4) {
u16 hash_table[4] = { 0 };
u32 crc;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (15 - (crc & 0xf));
}
recognise |= ETH_ARC_AFM;
writel((u32)(hash_table[1] << 16 | hash_table[0]),
&lp->eth_regs->ethhash0);
writel((u32)(hash_table[3] << 16 | hash_table[2]),
&lp->eth_regs->ethhash1);
}
spin_lock_irqsave(&lp->lock, flags);
writel(recognise, &lp->eth_regs->etharc);
spin_unlock_irqrestore(&lp->lock, flags);
}
static void korina_tx(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
struct dma_desc *td = &lp->td_ring[lp->tx_next_done];
u32 devcs;
u32 dmas;
spin_lock(&lp->lock);
while (IS_DMA_FINISHED(td->control)) {
if (lp->tx_full == 1) {
netif_wake_queue(dev);
lp->tx_full = 0;
}
devcs = lp->td_ring[lp->tx_next_done].devcs;
if ((devcs & (ETH_TX_FD | ETH_TX_LD)) !=
(ETH_TX_FD | ETH_TX_LD)) {
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
printk(KERN_ERR "%s: split tx ignored\n",
dev->name);
} else if (devcs & ETH_TX_TOK) {
dev->stats.tx_packets++;
dev->stats.tx_bytes +=
lp->tx_skb[lp->tx_next_done]->len;
} else {
dev->stats.tx_errors++;
dev->stats.tx_dropped++;
if (devcs & ETH_TX_UND)
dev->stats.tx_fifo_errors++;
if (devcs & ETH_TX_OF)
dev->stats.tx_aborted_errors++;
if (devcs & ETH_TX_ED)
dev->stats.tx_carrier_errors++;
if (devcs & ETH_TX_EC)
dev->stats.collisions++;
if (devcs & ETH_TX_LC)
dev->stats.tx_window_errors++;
}
if (lp->tx_skb[lp->tx_next_done]) {
dev_kfree_skb_any(lp->tx_skb[lp->tx_next_done]);
lp->tx_skb[lp->tx_next_done] = NULL;
}
lp->td_ring[lp->tx_next_done].control = DMA_DESC_IOF;
lp->td_ring[lp->tx_next_done].devcs = ETH_TX_FD | ETH_TX_LD;
lp->td_ring[lp->tx_next_done].link = 0;
lp->td_ring[lp->tx_next_done].ca = 0;
lp->tx_count--;
lp->tx_next_done = (lp->tx_next_done + 1) & KORINA_TDS_MASK;
td = &lp->td_ring[lp->tx_next_done];
}
dmas = readl(&lp->tx_dma_regs->dmas);
writel(~dmas, &lp->tx_dma_regs->dmas);
writel(readl(&lp->tx_dma_regs->dmasm) &
~(DMA_STAT_FINI | DMA_STAT_ERR),
&lp->tx_dma_regs->dmasm);
spin_unlock(&lp->lock);
}
static irqreturn_t
korina_tx_dma_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct korina_private *lp = netdev_priv(dev);
u32 dmas, dmasm;
irqreturn_t retval;
dmas = readl(&lp->tx_dma_regs->dmas);
if (dmas & (DMA_STAT_FINI | DMA_STAT_ERR)) {
dmasm = readl(&lp->tx_dma_regs->dmasm);
writel(dmasm | (DMA_STAT_FINI | DMA_STAT_ERR),
&lp->tx_dma_regs->dmasm);
korina_tx(dev);
if (lp->tx_chain_status == desc_filled &&
(readl(&(lp->tx_dma_regs->dmandptr)) == 0)) {
writel(CPHYSADDR(&lp->td_ring[lp->tx_chain_head]),
&(lp->tx_dma_regs->dmandptr));
lp->tx_chain_status = desc_empty;
lp->tx_chain_head = lp->tx_chain_tail;
dev->trans_start = jiffies;
}
if (dmas & DMA_STAT_ERR)
printk(KERN_ERR "%s: DMA error\n", dev->name);
retval = IRQ_HANDLED;
} else
retval = IRQ_NONE;
return retval;
}
static void korina_check_media(struct net_device *dev, unsigned int init_media)
{
struct korina_private *lp = netdev_priv(dev);
mii_check_media(&lp->mii_if, 0, init_media);
if (lp->mii_if.full_duplex)
writel(readl(&lp->eth_regs->ethmac2) | ETH_MAC2_FD,
&lp->eth_regs->ethmac2);
else
writel(readl(&lp->eth_regs->ethmac2) & ~ETH_MAC2_FD,
&lp->eth_regs->ethmac2);
}
static void korina_poll_media(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct korina_private *lp = netdev_priv(dev);
korina_check_media(dev, 0);
mod_timer(&lp->media_check_timer, jiffies + HZ);
}
static void korina_set_carrier(struct mii_if_info *mii)
{
if (mii->force_media) {
if (!netif_carrier_ok(mii->dev))
netif_carrier_on(mii->dev);
} else
korina_check_media(mii->dev, 0);
}
static int korina_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct korina_private *lp = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(rq);
int rc;
if (!netif_running(dev))
return -EINVAL;
spin_lock_irq(&lp->lock);
rc = generic_mii_ioctl(&lp->mii_if, data, cmd, NULL);
spin_unlock_irq(&lp->lock);
korina_set_carrier(&lp->mii_if);
return rc;
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct korina_private *lp = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, lp->dev->name, sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct korina_private *lp = netdev_priv(dev);
int rc;
spin_lock_irq(&lp->lock);
rc = mii_ethtool_gset(&lp->mii_if, cmd);
spin_unlock_irq(&lp->lock);
return rc;
}
static int netdev_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct korina_private *lp = netdev_priv(dev);
int rc;
spin_lock_irq(&lp->lock);
rc = mii_ethtool_sset(&lp->mii_if, cmd);
spin_unlock_irq(&lp->lock);
korina_set_carrier(&lp->mii_if);
return rc;
}
static u32 netdev_get_link(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
return mii_link_ok(&lp->mii_if);
}
static int korina_alloc_ring(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
struct sk_buff *skb;
int i;
for (i = 0; i < KORINA_NUM_TDS; i++) {
lp->td_ring[i].control = DMA_DESC_IOF;
lp->td_ring[i].devcs = ETH_TX_FD | ETH_TX_LD;
lp->td_ring[i].ca = 0;
lp->td_ring[i].link = 0;
}
lp->tx_next_done = lp->tx_chain_head = lp->tx_chain_tail =
lp->tx_full = lp->tx_count = 0;
lp->tx_chain_status = desc_empty;
for (i = 0; i < KORINA_NUM_RDS; i++) {
skb = netdev_alloc_skb_ip_align(dev, KORINA_RBSIZE);
if (!skb)
return -ENOMEM;
lp->rx_skb[i] = skb;
lp->rd_ring[i].control = DMA_DESC_IOD |
DMA_COUNT(KORINA_RBSIZE);
lp->rd_ring[i].devcs = 0;
lp->rd_ring[i].ca = CPHYSADDR(skb->data);
lp->rd_ring[i].link = CPHYSADDR(&lp->rd_ring[i+1]);
}
lp->rd_ring[i - 1].link = CPHYSADDR(&lp->rd_ring[0]);
lp->rd_ring[i - 1].control |= DMA_DESC_COD;
lp->rx_next_done = 0;
lp->rx_chain_head = 0;
lp->rx_chain_tail = 0;
lp->rx_chain_status = desc_empty;
return 0;
}
static void korina_free_ring(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
int i;
for (i = 0; i < KORINA_NUM_RDS; i++) {
lp->rd_ring[i].control = 0;
if (lp->rx_skb[i])
dev_kfree_skb_any(lp->rx_skb[i]);
lp->rx_skb[i] = NULL;
}
for (i = 0; i < KORINA_NUM_TDS; i++) {
lp->td_ring[i].control = 0;
if (lp->tx_skb[i])
dev_kfree_skb_any(lp->tx_skb[i]);
lp->tx_skb[i] = NULL;
}
}
static int korina_init(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
korina_abort_tx(dev);
korina_abort_rx(dev);
writel(0, &lp->eth_regs->ethintfc);
while ((readl(&lp->eth_regs->ethintfc) & ETH_INT_FC_RIP))
dev->trans_start = jiffies;
writel(ETH_INT_FC_EN, &lp->eth_regs->ethintfc);
if (korina_alloc_ring(dev)) {
printk(KERN_ERR "%s: descriptor allocation failed\n", dev->name);
korina_free_ring(dev);
return -ENOMEM;
}
writel(0, &lp->rx_dma_regs->dmas);
korina_start_rx(lp, &lp->rd_ring[0]);
writel(readl(&lp->tx_dma_regs->dmasm) &
~(DMA_STAT_FINI | DMA_STAT_ERR),
&lp->tx_dma_regs->dmasm);
writel(readl(&lp->rx_dma_regs->dmasm) &
~(DMA_STAT_DONE | DMA_STAT_HALT | DMA_STAT_ERR),
&lp->rx_dma_regs->dmasm);
writel(ETH_ARC_AB, &lp->eth_regs->etharc);
writel(STATION_ADDRESS_LOW(dev), &lp->eth_regs->ethsal0);
writel(STATION_ADDRESS_HIGH(dev), &lp->eth_regs->ethsah0);
writel(STATION_ADDRESS_LOW(dev), &lp->eth_regs->ethsal1);
writel(STATION_ADDRESS_HIGH(dev), &lp->eth_regs->ethsah1);
writel(STATION_ADDRESS_LOW(dev), &lp->eth_regs->ethsal2);
writel(STATION_ADDRESS_HIGH(dev), &lp->eth_regs->ethsah2);
writel(STATION_ADDRESS_LOW(dev), &lp->eth_regs->ethsal3);
writel(STATION_ADDRESS_HIGH(dev), &lp->eth_regs->ethsah3);
writel(ETH_MAC2_PE | ETH_MAC2_CEN | ETH_MAC2_FD,
&lp->eth_regs->ethmac2);
writel(0x15, &lp->eth_regs->ethipgt);
writel(0x12, &lp->eth_regs->ethipgr);
writel(((idt_cpu_freq) / MII_CLOCK + 1) & ~1,
&lp->eth_regs->ethmcp);
writel(48, &lp->eth_regs->ethfifott);
writel(ETH_MAC1_RE, &lp->eth_regs->ethmac1);
napi_enable(&lp->napi);
netif_start_queue(dev);
return 0;
}
static void korina_restart_task(struct work_struct *work)
{
struct korina_private *lp = container_of(work,
struct korina_private, restart_task);
struct net_device *dev = lp->dev;
disable_irq(lp->rx_irq);
disable_irq(lp->tx_irq);
disable_irq(lp->ovr_irq);
disable_irq(lp->und_irq);
writel(readl(&lp->tx_dma_regs->dmasm) |
DMA_STAT_FINI | DMA_STAT_ERR,
&lp->tx_dma_regs->dmasm);
writel(readl(&lp->rx_dma_regs->dmasm) |
DMA_STAT_DONE | DMA_STAT_HALT | DMA_STAT_ERR,
&lp->rx_dma_regs->dmasm);
korina_free_ring(dev);
napi_disable(&lp->napi);
if (korina_init(dev) < 0) {
printk(KERN_ERR "%s: cannot restart device\n", dev->name);
return;
}
korina_multicast_list(dev);
enable_irq(lp->und_irq);
enable_irq(lp->ovr_irq);
enable_irq(lp->tx_irq);
enable_irq(lp->rx_irq);
}
static void korina_clear_and_restart(struct net_device *dev, u32 value)
{
struct korina_private *lp = netdev_priv(dev);
netif_stop_queue(dev);
writel(value, &lp->eth_regs->ethintfc);
schedule_work(&lp->restart_task);
}
static irqreturn_t korina_und_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct korina_private *lp = netdev_priv(dev);
unsigned int und;
spin_lock(&lp->lock);
und = readl(&lp->eth_regs->ethintfc);
if (und & ETH_INT_FC_UND)
korina_clear_and_restart(dev, und & ~ETH_INT_FC_UND);
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static void korina_tx_timeout(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
schedule_work(&lp->restart_task);
}
static irqreturn_t
korina_ovr_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct korina_private *lp = netdev_priv(dev);
unsigned int ovr;
spin_lock(&lp->lock);
ovr = readl(&lp->eth_regs->ethintfc);
if (ovr & ETH_INT_FC_OVR)
korina_clear_and_restart(dev, ovr & ~ETH_INT_FC_OVR);
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
static void korina_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
korina_tx_dma_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static int korina_open(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
int ret;
ret = korina_init(dev);
if (ret < 0) {
printk(KERN_ERR "%s: cannot open device\n", dev->name);
goto out;
}
ret = request_irq(lp->rx_irq, korina_rx_dma_interrupt,
IRQF_DISABLED, "Korina ethernet Rx", dev);
if (ret < 0) {
printk(KERN_ERR "%s: unable to get Rx DMA IRQ %d\n",
dev->name, lp->rx_irq);
goto err_release;
}
ret = request_irq(lp->tx_irq, korina_tx_dma_interrupt,
IRQF_DISABLED, "Korina ethernet Tx", dev);
if (ret < 0) {
printk(KERN_ERR "%s: unable to get Tx DMA IRQ %d\n",
dev->name, lp->tx_irq);
goto err_free_rx_irq;
}
ret = request_irq(lp->ovr_irq, korina_ovr_interrupt,
IRQF_DISABLED, "Ethernet Overflow", dev);
if (ret < 0) {
printk(KERN_ERR "%s: unable to get OVR IRQ %d\n",
dev->name, lp->ovr_irq);
goto err_free_tx_irq;
}
ret = request_irq(lp->und_irq, korina_und_interrupt,
IRQF_DISABLED, "Ethernet Underflow", dev);
if (ret < 0) {
printk(KERN_ERR "%s: unable to get UND IRQ %d\n",
dev->name, lp->und_irq);
goto err_free_ovr_irq;
}
mod_timer(&lp->media_check_timer, jiffies + 1);
out:
return ret;
err_free_ovr_irq:
free_irq(lp->ovr_irq, dev);
err_free_tx_irq:
free_irq(lp->tx_irq, dev);
err_free_rx_irq:
free_irq(lp->rx_irq, dev);
err_release:
korina_free_ring(dev);
goto out;
}
static int korina_close(struct net_device *dev)
{
struct korina_private *lp = netdev_priv(dev);
u32 tmp;
del_timer(&lp->media_check_timer);
disable_irq(lp->rx_irq);
disable_irq(lp->tx_irq);
disable_irq(lp->ovr_irq);
disable_irq(lp->und_irq);
korina_abort_tx(dev);
tmp = readl(&lp->tx_dma_regs->dmasm);
tmp = tmp | DMA_STAT_FINI | DMA_STAT_ERR;
writel(tmp, &lp->tx_dma_regs->dmasm);
korina_abort_rx(dev);
tmp = readl(&lp->rx_dma_regs->dmasm);
tmp = tmp | DMA_STAT_DONE | DMA_STAT_HALT | DMA_STAT_ERR;
writel(tmp, &lp->rx_dma_regs->dmasm);
korina_free_ring(dev);
napi_disable(&lp->napi);
cancel_work_sync(&lp->restart_task);
free_irq(lp->rx_irq, dev);
free_irq(lp->tx_irq, dev);
free_irq(lp->ovr_irq, dev);
free_irq(lp->und_irq, dev);
return 0;
}
static int korina_probe(struct platform_device *pdev)
{
struct korina_device *bif = platform_get_drvdata(pdev);
struct korina_private *lp;
struct net_device *dev;
struct resource *r;
int rc;
dev = alloc_etherdev(sizeof(struct korina_private));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
lp = netdev_priv(dev);
bif->dev = dev;
memcpy(dev->dev_addr, bif->mac, 6);
lp->rx_irq = platform_get_irq_byname(pdev, "korina_rx");
lp->tx_irq = platform_get_irq_byname(pdev, "korina_tx");
lp->ovr_irq = platform_get_irq_byname(pdev, "korina_ovr");
lp->und_irq = platform_get_irq_byname(pdev, "korina_und");
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "korina_regs");
dev->base_addr = r->start;
lp->eth_regs = ioremap_nocache(r->start, resource_size(r));
if (!lp->eth_regs) {
printk(KERN_ERR DRV_NAME ": cannot remap registers\n");
rc = -ENXIO;
goto probe_err_out;
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "korina_dma_rx");
lp->rx_dma_regs = ioremap_nocache(r->start, resource_size(r));
if (!lp->rx_dma_regs) {
printk(KERN_ERR DRV_NAME ": cannot remap Rx DMA registers\n");
rc = -ENXIO;
goto probe_err_dma_rx;
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "korina_dma_tx");
lp->tx_dma_regs = ioremap_nocache(r->start, resource_size(r));
if (!lp->tx_dma_regs) {
printk(KERN_ERR DRV_NAME ": cannot remap Tx DMA registers\n");
rc = -ENXIO;
goto probe_err_dma_tx;
}
lp->td_ring = kmalloc(TD_RING_SIZE + RD_RING_SIZE, GFP_KERNEL);
if (!lp->td_ring) {
rc = -ENXIO;
goto probe_err_td_ring;
}
dma_cache_inv((unsigned long)(lp->td_ring),
TD_RING_SIZE + RD_RING_SIZE);
lp->td_ring = (struct dma_desc *)KSEG1ADDR(lp->td_ring);
lp->rd_ring = &lp->td_ring[KORINA_NUM_TDS];
spin_lock_init(&lp->lock);
dev->irq = lp->rx_irq;
lp->dev = dev;
dev->netdev_ops = &korina_netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &lp->napi, korina_poll, 64);
lp->phy_addr = (((lp->rx_irq == 0x2c? 1:0) << 8) | 0x05);
lp->mii_if.dev = dev;
lp->mii_if.mdio_read = mdio_read;
lp->mii_if.mdio_write = mdio_write;
lp->mii_if.phy_id = lp->phy_addr;
lp->mii_if.phy_id_mask = 0x1f;
lp->mii_if.reg_num_mask = 0x1f;
rc = register_netdev(dev);
if (rc < 0) {
printk(KERN_ERR DRV_NAME
": cannot register net device: %d\n", rc);
goto probe_err_register;
}
setup_timer(&lp->media_check_timer, korina_poll_media, (unsigned long) dev);
INIT_WORK(&lp->restart_task, korina_restart_task);
printk(KERN_INFO "%s: " DRV_NAME "-" DRV_VERSION " " DRV_RELDATE "\n",
dev->name);
out:
return rc;
probe_err_register:
kfree(lp->td_ring);
probe_err_td_ring:
iounmap(lp->tx_dma_regs);
probe_err_dma_tx:
iounmap(lp->rx_dma_regs);
probe_err_dma_rx:
iounmap(lp->eth_regs);
probe_err_out:
free_netdev(dev);
goto out;
}
static int korina_remove(struct platform_device *pdev)
{
struct korina_device *bif = platform_get_drvdata(pdev);
struct korina_private *lp = netdev_priv(bif->dev);
iounmap(lp->eth_regs);
iounmap(lp->rx_dma_regs);
iounmap(lp->tx_dma_regs);
unregister_netdev(bif->dev);
free_netdev(bif->dev);
return 0;
}
