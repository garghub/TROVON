static int __devinit
de4x5_hw_init(struct net_device *dev, u_long iobase, struct device *gendev)
{
char name[DE4X5_NAME_LENGTH + 1];
struct de4x5_private *lp = netdev_priv(dev);
struct pci_dev *pdev = NULL;
int i, status=0;
dev_set_drvdata(gendev, dev);
if (lp->bus == EISA) {
outb(WAKEUP, PCI_CFPM);
} else {
pdev = to_pci_dev (gendev);
pci_write_config_byte(pdev, PCI_CFDA_PSM, WAKEUP);
}
mdelay(10);
RESET_DE4X5;
if ((inl(DE4X5_STS) & (STS_TS | STS_RS)) != 0) {
return -ENXIO;
}
lp->useSROM = false;
if (lp->bus == PCI) {
PCI_signature(name, lp);
} else {
EISA_signature(name, gendev);
}
if (*name == '\0') {
return -ENXIO;
}
dev->base_addr = iobase;
printk ("%s: %s at 0x%04lx", dev_name(gendev), name, iobase);
status = get_hw_addr(dev);
printk(", h/w address %pM\n", dev->dev_addr);
if (status != 0) {
printk(" which has an Ethernet PROM CRC error.\n");
return -ENXIO;
} else {
skb_queue_head_init(&lp->cache.queue);
lp->cache.gepc = GEP_INIT;
lp->asBit = GEP_SLNK;
lp->asPolarity = GEP_SLNK;
lp->asBitValid = ~0;
lp->timeout = -1;
lp->gendev = gendev;
spin_lock_init(&lp->lock);
init_timer(&lp->timer);
lp->timer.function = (void (*)(unsigned long))de4x5_ast;
lp->timer.data = (unsigned long)dev;
de4x5_parse_params(dev);
lp->autosense = lp->params.autosense;
if (lp->chipset != DC21140) {
if ((lp->chipset==DC21040) && (lp->params.autosense&TP_NW)) {
lp->params.autosense = TP;
}
if ((lp->chipset==DC21041) && (lp->params.autosense&BNC_AUI)) {
lp->params.autosense = BNC;
}
}
lp->fdx = lp->params.fdx;
sprintf(lp->adapter_name,"%s (%s)", name, dev_name(gendev));
lp->dma_size = (NUM_RX_DESC + NUM_TX_DESC) * sizeof(struct de4x5_desc);
#if defined(__alpha__) || defined(__powerpc__) || defined(CONFIG_SPARC) || defined(DE4X5_DO_MEMCPY)
lp->dma_size += RX_BUFF_SZ * NUM_RX_DESC + DE4X5_ALIGN;
#endif
lp->rx_ring = dma_alloc_coherent(gendev, lp->dma_size,
&lp->dma_rings, GFP_ATOMIC);
if (lp->rx_ring == NULL) {
return -ENOMEM;
}
lp->tx_ring = lp->rx_ring + NUM_RX_DESC;
#if !defined(__alpha__) && !defined(__powerpc__) && !defined(CONFIG_SPARC) && !defined(DE4X5_DO_MEMCPY)
for (i=0; i<NUM_RX_DESC; i++) {
lp->rx_ring[i].status = 0;
lp->rx_ring[i].des1 = cpu_to_le32(RX_BUFF_SZ);
lp->rx_ring[i].buf = 0;
lp->rx_ring[i].next = 0;
lp->rx_skb[i] = (struct sk_buff *) 1;
}
#else
{
dma_addr_t dma_rx_bufs;
dma_rx_bufs = lp->dma_rings + (NUM_RX_DESC + NUM_TX_DESC)
* sizeof(struct de4x5_desc);
dma_rx_bufs = (dma_rx_bufs + DE4X5_ALIGN) & ~DE4X5_ALIGN;
lp->rx_bufs = (char *)(((long)(lp->rx_ring + NUM_RX_DESC
+ NUM_TX_DESC) + DE4X5_ALIGN) & ~DE4X5_ALIGN);
for (i=0; i<NUM_RX_DESC; i++) {
lp->rx_ring[i].status = 0;
lp->rx_ring[i].des1 = cpu_to_le32(RX_BUFF_SZ);
lp->rx_ring[i].buf =
cpu_to_le32(dma_rx_bufs+i*RX_BUFF_SZ);
lp->rx_ring[i].next = 0;
lp->rx_skb[i] = (struct sk_buff *) 1;
}
}
#endif
barrier();
lp->rxRingSize = NUM_RX_DESC;
lp->txRingSize = NUM_TX_DESC;
lp->rx_ring[lp->rxRingSize - 1].des1 |= cpu_to_le32(RD_RER);
lp->tx_ring[lp->txRingSize - 1].des1 |= cpu_to_le32(TD_TER);
outl(lp->dma_rings, DE4X5_RRBA);
outl(lp->dma_rings + NUM_RX_DESC * sizeof(struct de4x5_desc),
DE4X5_TRBA);
lp->irq_mask = IMR_RIM | IMR_TIM | IMR_TUM | IMR_UNM;
lp->irq_en = IMR_NIM | IMR_AIM;
create_packet(dev, lp->frame, sizeof(lp->frame));
i = lp->cfrv & 0x000000fe;
if ((lp->chipset == DC21140) && (i == 0x20)) {
lp->rx_ovf = 1;
}
if (lp->useSROM) {
lp->state = INITIALISED;
if (srom_infoleaf_info(dev)) {
dma_free_coherent (gendev, lp->dma_size,
lp->rx_ring, lp->dma_rings);
return -ENXIO;
}
srom_init(dev);
}
lp->state = CLOSED;
if ((lp->chipset != DC21040) && (lp->chipset != DC21041)) {
mii_get_phy(dev);
}
printk(" and requires IRQ%d (provided by %s).\n", dev->irq,
((lp->bus == PCI) ? "PCI BIOS" : "EISA CNFG"));
}
if (de4x5_debug & DEBUG_VERSION) {
printk(version);
}
SET_NETDEV_DEV(dev, gendev);
dev->netdev_ops = &de4x5_netdev_ops;
dev->mem_start = 0;
if ((status = register_netdev (dev))) {
dma_free_coherent (gendev, lp->dma_size,
lp->rx_ring, lp->dma_rings);
return status;
}
yawn(dev, SLEEP);
return status;
}
static int
de4x5_open(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int i, status = 0;
s32 omr;
for (i=0; i<lp->rxRingSize; i++) {
if (de4x5_alloc_rx_buff(dev, i, 0) == NULL) {
de4x5_free_rx_buffs(dev);
return -EAGAIN;
}
}
yawn(dev, WAKEUP);
status = de4x5_init(dev);
spin_lock_init(&lp->lock);
lp->state = OPEN;
de4x5_dbg_open(dev);
if (request_irq(dev->irq, de4x5_interrupt, IRQF_SHARED,
lp->adapter_name, dev)) {
printk("de4x5_open(): Requested IRQ%d is busy - attemping FAST/SHARE...", dev->irq);
if (request_irq(dev->irq, de4x5_interrupt, IRQF_DISABLED | IRQF_SHARED,
lp->adapter_name, dev)) {
printk("\n Cannot get IRQ- reconfigure your hardware.\n");
disable_ast(dev);
de4x5_free_rx_buffs(dev);
de4x5_free_tx_buffs(dev);
yawn(dev, SLEEP);
lp->state = CLOSED;
return -EAGAIN;
} else {
printk("\n Succeeded, but you should reconfigure your hardware to avoid this.\n");
printk("WARNING: there may be IRQ related problems in heavily loaded systems.\n");
}
}
lp->interrupt = UNMASK_INTERRUPTS;
dev->trans_start = jiffies;
START_DE4X5;
de4x5_setup_intr(dev);
if (de4x5_debug & DEBUG_OPEN) {
printk("\tsts: 0x%08x\n", inl(DE4X5_STS));
printk("\tbmr: 0x%08x\n", inl(DE4X5_BMR));
printk("\timr: 0x%08x\n", inl(DE4X5_IMR));
printk("\tomr: 0x%08x\n", inl(DE4X5_OMR));
printk("\tsisr: 0x%08x\n", inl(DE4X5_SISR));
printk("\tsicr: 0x%08x\n", inl(DE4X5_SICR));
printk("\tstrr: 0x%08x\n", inl(DE4X5_STRR));
printk("\tsigr: 0x%08x\n", inl(DE4X5_SIGR));
}
return status;
}
static int
de4x5_init(struct net_device *dev)
{
netif_stop_queue(dev);
de4x5_sw_reset(dev);
autoconf_media(dev);
return 0;
}
static int
de4x5_sw_reset(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int i, j, status = 0;
s32 bmr, omr;
if (!lp->useSROM) {
if (lp->phy[lp->active].id != 0) {
lp->infoblock_csr6 = OMR_SDP | OMR_PS | OMR_HBD;
} else {
lp->infoblock_csr6 = OMR_SDP | OMR_TTM;
}
de4x5_switch_mac_port(dev);
}
bmr = (lp->chipset==DC21140 ? PBL_8 : PBL_4) | DESC_SKIP_LEN | DE4X5_CACHE_ALIGN;
bmr |= ((lp->chipset & ~0x00ff)==DC2114x ? BMR_RML : 0);
outl(bmr, DE4X5_BMR);
omr = inl(DE4X5_OMR) & ~OMR_PR;
if (lp->chipset == DC21140) {
omr |= (OMR_SDP | OMR_SB);
}
lp->setup_f = PERFECT;
outl(lp->dma_rings, DE4X5_RRBA);
outl(lp->dma_rings + NUM_RX_DESC * sizeof(struct de4x5_desc),
DE4X5_TRBA);
lp->rx_new = lp->rx_old = 0;
lp->tx_new = lp->tx_old = 0;
for (i = 0; i < lp->rxRingSize; i++) {
lp->rx_ring[i].status = cpu_to_le32(R_OWN);
}
for (i = 0; i < lp->txRingSize; i++) {
lp->tx_ring[i].status = cpu_to_le32(0);
}
barrier();
SetMulticastFilter(dev);
load_packet(dev, lp->setup_frame, PERFECT_F|TD_SET|SETUP_FRAME_LEN, (struct sk_buff *)1);
outl(omr|OMR_ST, DE4X5_OMR);
for (j=0, i=0;(i<500) && (j==0);i++) {
mdelay(1);
if ((s32)le32_to_cpu(lp->tx_ring[lp->tx_new].status) >= 0) j=1;
}
outl(omr, DE4X5_OMR);
if (j == 0) {
printk("%s: Setup frame timed out, status %08x\n", dev->name,
inl(DE4X5_STS));
status = -EIO;
}
lp->tx_new = (lp->tx_new + 1) % lp->txRingSize;
lp->tx_old = lp->tx_new;
return status;
}
static netdev_tx_t
de4x5_queue_pkt(struct sk_buff *skb, struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_long flags = 0;
netif_stop_queue(dev);
if (!lp->tx_enable)
return NETDEV_TX_LOCKED;
spin_lock_irqsave(&lp->lock, flags);
de4x5_tx(dev);
spin_unlock_irqrestore(&lp->lock, flags);
if (test_and_set_bit(0, (void *)&lp->cache.lock) && !lp->interrupt)
return NETDEV_TX_LOCKED;
if (netif_queue_stopped(dev) || (u_long) lp->tx_skb[lp->tx_new] > 1) {
if (lp->interrupt) {
de4x5_putb_cache(dev, skb);
} else {
de4x5_put_cache(dev, skb);
}
if (de4x5_debug & DEBUG_TX) {
printk("%s: transmit busy, lost media or stale skb found:\n STS:%08x\n tbusy:%d\n IMR:%08x\n OMR:%08x\n Stale skb: %s\n",dev->name, inl(DE4X5_STS), netif_queue_stopped(dev), inl(DE4X5_IMR), inl(DE4X5_OMR), ((u_long) lp->tx_skb[lp->tx_new] > 1) ? "YES" : "NO");
}
} else if (skb->len > 0) {
if (!skb_queue_empty(&lp->cache.queue) && !lp->interrupt) {
de4x5_put_cache(dev, skb);
skb = de4x5_get_cache(dev);
}
while (skb && !netif_queue_stopped(dev) &&
(u_long) lp->tx_skb[lp->tx_new] <= 1) {
spin_lock_irqsave(&lp->lock, flags);
netif_stop_queue(dev);
load_packet(dev, skb->data, TD_IC | TD_LS | TD_FS | skb->len, skb);
lp->stats.tx_bytes += skb->len;
outl(POLL_DEMAND, DE4X5_TPD);
lp->tx_new = (lp->tx_new + 1) % lp->txRingSize;
if (TX_BUFFS_AVAIL) {
netif_start_queue(dev);
}
skb = de4x5_get_cache(dev);
spin_unlock_irqrestore(&lp->lock, flags);
}
if (skb) de4x5_putb_cache(dev, skb);
}
lp->cache.lock = 0;
return NETDEV_TX_OK;
}
static irqreturn_t
de4x5_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct de4x5_private *lp;
s32 imr, omr, sts, limit;
u_long iobase;
unsigned int handled = 0;
lp = netdev_priv(dev);
spin_lock(&lp->lock);
iobase = dev->base_addr;
DISABLE_IRQs;
if (test_and_set_bit(MASK_INTERRUPTS, (void*) &lp->interrupt))
printk("%s: Re-entering the interrupt handler.\n", dev->name);
synchronize_irq(dev->irq);
for (limit=0; limit<8; limit++) {
sts = inl(DE4X5_STS);
outl(sts, DE4X5_STS);
if (!(sts & lp->irq_mask)) break;
handled = 1;
if (sts & (STS_RI | STS_RU))
de4x5_rx(dev);
if (sts & (STS_TI | STS_TU))
de4x5_tx(dev);
if (sts & STS_LNF) {
lp->irq_mask &= ~IMR_LFM;
}
if (sts & STS_UNF) {
de4x5_txur(dev);
}
if (sts & STS_SE) {
STOP_DE4X5;
printk("%s: Fatal bus error occurred, sts=%#8x, device stopped.\n",
dev->name, sts);
spin_unlock(&lp->lock);
return IRQ_HANDLED;
}
}
if (!test_and_set_bit(0, (void *)&lp->cache.lock)) {
while (!skb_queue_empty(&lp->cache.queue) && !netif_queue_stopped(dev) && lp->tx_enable) {
de4x5_queue_pkt(de4x5_get_cache(dev), dev);
}
lp->cache.lock = 0;
}
lp->interrupt = UNMASK_INTERRUPTS;
ENABLE_IRQs;
spin_unlock(&lp->lock);
return IRQ_RETVAL(handled);
}
static int
de4x5_rx(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int entry;
s32 status;
for (entry=lp->rx_new; (s32)le32_to_cpu(lp->rx_ring[entry].status)>=0;
entry=lp->rx_new) {
status = (s32)le32_to_cpu(lp->rx_ring[entry].status);
if (lp->rx_ovf) {
if (inl(DE4X5_MFC) & MFC_FOCM) {
de4x5_rx_ovfc(dev);
break;
}
}
if (status & RD_FS) {
lp->rx_old = entry;
}
if (status & RD_LS) {
if (lp->tx_enable) lp->linkOK++;
if (status & RD_ES) {
lp->stats.rx_errors++;
if (status & (RD_RF | RD_TL)) lp->stats.rx_frame_errors++;
if (status & RD_CE) lp->stats.rx_crc_errors++;
if (status & RD_OF) lp->stats.rx_fifo_errors++;
if (status & RD_TL) lp->stats.rx_length_errors++;
if (status & RD_RF) lp->pktStats.rx_runt_frames++;
if (status & RD_CS) lp->pktStats.rx_collision++;
if (status & RD_DB) lp->pktStats.rx_dribble++;
if (status & RD_OF) lp->pktStats.rx_overflow++;
} else {
struct sk_buff *skb;
short pkt_len = (short)(le32_to_cpu(lp->rx_ring[entry].status)
>> 16) - 4;
if ((skb = de4x5_alloc_rx_buff(dev, entry, pkt_len)) == NULL) {
printk("%s: Insufficient memory; nuking packet.\n",
dev->name);
lp->stats.rx_dropped++;
} else {
de4x5_dbg_rx(skb, pkt_len);
skb->protocol=eth_type_trans(skb,dev);
de4x5_local_stats(dev, skb->data, pkt_len);
netif_rx(skb);
lp->stats.rx_packets++;
lp->stats.rx_bytes += pkt_len;
}
}
for (;lp->rx_old!=entry;lp->rx_old=(lp->rx_old + 1)%lp->rxRingSize) {
lp->rx_ring[lp->rx_old].status = cpu_to_le32(R_OWN);
barrier();
}
lp->rx_ring[entry].status = cpu_to_le32(R_OWN);
barrier();
}
lp->rx_new = (lp->rx_new + 1) % lp->rxRingSize;
}
return 0;
}
static inline void
de4x5_free_tx_buff(struct de4x5_private *lp, int entry)
{
dma_unmap_single(lp->gendev, le32_to_cpu(lp->tx_ring[entry].buf),
le32_to_cpu(lp->tx_ring[entry].des1) & TD_TBS1,
DMA_TO_DEVICE);
if ((u_long) lp->tx_skb[entry] > 1)
dev_kfree_skb_irq(lp->tx_skb[entry]);
lp->tx_skb[entry] = NULL;
}
static int
de4x5_tx(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int entry;
s32 status;
for (entry = lp->tx_old; entry != lp->tx_new; entry = lp->tx_old) {
status = (s32)le32_to_cpu(lp->tx_ring[entry].status);
if (status < 0) {
break;
} else if (status != 0x7fffffff) {
if (status & TD_ES) {
lp->stats.tx_errors++;
if (status & TD_NC) lp->stats.tx_carrier_errors++;
if (status & TD_LC) lp->stats.tx_window_errors++;
if (status & TD_UF) lp->stats.tx_fifo_errors++;
if (status & TD_EC) lp->pktStats.excessive_collisions++;
if (status & TD_DE) lp->stats.tx_aborted_errors++;
if (TX_PKT_PENDING) {
outl(POLL_DEMAND, DE4X5_TPD);
}
} else {
lp->stats.tx_packets++;
if (lp->tx_enable) lp->linkOK++;
}
lp->stats.collisions += ((status & TD_EC) ? 16 :
((status & TD_CC) >> 3));
if (lp->tx_skb[entry] != NULL)
de4x5_free_tx_buff(lp, entry);
}
lp->tx_old = (lp->tx_old + 1) % lp->txRingSize;
}
if (TX_BUFFS_AVAIL && netif_queue_stopped(dev)) {
if (lp->interrupt)
netif_wake_queue(dev);
else
netif_start_queue(dev);
}
return 0;
}
static void
de4x5_ast(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int next_tick = DE4X5_AUTOSENSE_MS;
int dt;
if (lp->useSROM)
next_tick = srom_autoconf(dev);
else if (lp->chipset == DC21140)
next_tick = dc21140m_autoconf(dev);
else if (lp->chipset == DC21041)
next_tick = dc21041_autoconf(dev);
else if (lp->chipset == DC21040)
next_tick = dc21040_autoconf(dev);
lp->linkOK = 0;
dt = (next_tick * HZ) / 1000;
if (!dt)
dt = 1;
mod_timer(&lp->timer, jiffies + dt);
}
static int
de4x5_txur(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int omr;
omr = inl(DE4X5_OMR);
if (!(omr & OMR_SF) || (lp->chipset==DC21041) || (lp->chipset==DC21040)) {
omr &= ~(OMR_ST|OMR_SR);
outl(omr, DE4X5_OMR);
while (inl(DE4X5_STS) & STS_TS);
if ((omr & OMR_TR) < OMR_TR) {
omr += 0x4000;
} else {
omr |= OMR_SF;
}
outl(omr | OMR_ST | OMR_SR, DE4X5_OMR);
}
return 0;
}
static int
de4x5_rx_ovfc(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int omr;
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_SR, DE4X5_OMR);
while (inl(DE4X5_STS) & STS_RS);
for (; (s32)le32_to_cpu(lp->rx_ring[lp->rx_new].status)>=0;) {
lp->rx_ring[lp->rx_new].status = cpu_to_le32(R_OWN);
lp->rx_new = (lp->rx_new + 1) % lp->rxRingSize;
}
outl(omr, DE4X5_OMR);
return 0;
}
static int
de4x5_close(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 imr, omr;
disable_ast(dev);
netif_stop_queue(dev);
if (de4x5_debug & DEBUG_CLOSE) {
printk("%s: Shutting down ethercard, status was %8.8x.\n",
dev->name, inl(DE4X5_STS));
}
DISABLE_IRQs;
STOP_DE4X5;
free_irq(dev->irq, dev);
lp->state = CLOSED;
de4x5_free_rx_buffs(dev);
de4x5_free_tx_buffs(dev);
yawn(dev, SLEEP);
return 0;
}
static struct net_device_stats *
de4x5_get_stats(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
lp->stats.rx_missed_errors = (int)(inl(DE4X5_MFC) & (MFC_OVFL | MFC_CNTR));
return &lp->stats;
}
static void
de4x5_local_stats(struct net_device *dev, char *buf, int pkt_len)
{
struct de4x5_private *lp = netdev_priv(dev);
int i;
for (i=1; i<DE4X5_PKT_STAT_SZ-1; i++) {
if (pkt_len < (i*DE4X5_PKT_BIN_SZ)) {
lp->pktStats.bins[i]++;
i = DE4X5_PKT_STAT_SZ;
}
}
if (is_multicast_ether_addr(buf)) {
if (is_broadcast_ether_addr(buf)) {
lp->pktStats.broadcast++;
} else {
lp->pktStats.multicast++;
}
} else if (compare_ether_addr(buf, dev->dev_addr) == 0) {
lp->pktStats.unicast++;
}
lp->pktStats.bins[0]++;
if (lp->pktStats.bins[0] == 0) {
memset((char *)&lp->pktStats, 0, sizeof(lp->pktStats));
}
}
static void
load_packet(struct net_device *dev, char *buf, u32 flags, struct sk_buff *skb)
{
struct de4x5_private *lp = netdev_priv(dev);
int entry = (lp->tx_new ? lp->tx_new-1 : lp->txRingSize-1);
dma_addr_t buf_dma = dma_map_single(lp->gendev, buf, flags & TD_TBS1, DMA_TO_DEVICE);
lp->tx_ring[lp->tx_new].buf = cpu_to_le32(buf_dma);
lp->tx_ring[lp->tx_new].des1 &= cpu_to_le32(TD_TER);
lp->tx_ring[lp->tx_new].des1 |= cpu_to_le32(flags);
lp->tx_skb[lp->tx_new] = skb;
lp->tx_ring[entry].des1 &= cpu_to_le32(~TD_IC);
barrier();
lp->tx_ring[lp->tx_new].status = cpu_to_le32(T_OWN);
barrier();
}
static void
set_multicast_list(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->state == OPEN) {
if (dev->flags & IFF_PROMISC) {
u32 omr;
omr = inl(DE4X5_OMR);
omr |= OMR_PR;
outl(omr, DE4X5_OMR);
} else {
SetMulticastFilter(dev);
load_packet(dev, lp->setup_frame, TD_IC | PERFECT_F | TD_SET |
SETUP_FRAME_LEN, (struct sk_buff *)1);
lp->tx_new = (lp->tx_new + 1) % lp->txRingSize;
outl(POLL_DEMAND, DE4X5_TPD);
dev->trans_start = jiffies;
}
}
}
static void
SetMulticastFilter(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
struct netdev_hw_addr *ha;
u_long iobase = dev->base_addr;
int i, bit, byte;
u16 hashcode;
u32 omr, crc;
char *pa;
unsigned char *addrs;
omr = inl(DE4X5_OMR);
omr &= ~(OMR_PR | OMR_PM);
pa = build_setup_frame(dev, ALL);
if ((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 14)) {
omr |= OMR_PM;
} else if (lp->setup_f == HASH_PERF) {
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(ETH_ALEN, ha->addr);
hashcode = crc & HASH_BITS;
byte = hashcode >> 3;
bit = 1 << (hashcode & 0x07);
byte <<= 1;
if (byte & 0x02) {
byte -= 1;
}
lp->setup_frame[byte] |= bit;
}
} else {
netdev_for_each_mc_addr(ha, dev) {
addrs = ha->addr;
for (i=0; i<ETH_ALEN; i++) {
*(pa + (i&1)) = *addrs++;
if (i & 0x01) pa += 4;
}
}
}
outl(omr, DE4X5_OMR);
}
static int __init de4x5_eisa_probe (struct device *gendev)
{
struct eisa_device *edev;
u_long iobase;
u_char irq, regval;
u_short vendor;
u32 cfid;
int status, device;
struct net_device *dev;
struct de4x5_private *lp;
edev = to_eisa_device (gendev);
iobase = edev->base_addr;
if (!request_region (iobase, DE4X5_EISA_TOTAL_SIZE, "de4x5"))
return -EBUSY;
if (!request_region (iobase + DE4X5_EISA_IO_PORTS,
DE4X5_EISA_TOTAL_SIZE, "de4x5")) {
status = -EBUSY;
goto release_reg_1;
}
if (!(dev = alloc_etherdev (sizeof (struct de4x5_private)))) {
status = -ENOMEM;
goto release_reg_2;
}
lp = netdev_priv(dev);
cfid = (u32) inl(PCI_CFID);
lp->cfrv = (u_short) inl(PCI_CFRV);
device = (cfid >> 8) & 0x00ffff00;
vendor = (u_short) cfid;
regval = inb(EISA_REG0) & (ER0_INTL | ER0_INTT);
#ifdef CONFIG_ALPHA
outb (ER1_IAM | 1, EISA_REG1);
mdelay (1);
outb (ER1_IAM, EISA_REG1);
mdelay (1);
outb (ER3_BWE | ER3_BRE, EISA_REG3);
outb (ER0_BSW | ER0_BMW | ER0_EPT | regval, EISA_REG0);
#endif
irq = de4x5_irq[(regval >> 1) & 0x03];
if (is_DC2114x) {
device = ((lp->cfrv & CFRV_RN) < DC2114x_BRK ? DC21142 : DC21143);
}
lp->chipset = device;
lp->bus = EISA;
outl(PCI_COMMAND_IO | PCI_COMMAND_MASTER, PCI_CFCS);
outl(0x00006000, PCI_CFLT);
outl(iobase, PCI_CBIO);
DevicePresent(dev, EISA_APROM);
dev->irq = irq;
if (!(status = de4x5_hw_init (dev, iobase, gendev))) {
return 0;
}
free_netdev (dev);
release_reg_2:
release_region (iobase + DE4X5_EISA_IO_PORTS, DE4X5_EISA_TOTAL_SIZE);
release_reg_1:
release_region (iobase, DE4X5_EISA_TOTAL_SIZE);
return status;
}
static int __devexit de4x5_eisa_remove (struct device *device)
{
struct net_device *dev;
u_long iobase;
dev = dev_get_drvdata(device);
iobase = dev->base_addr;
unregister_netdev (dev);
free_netdev (dev);
release_region (iobase + DE4X5_EISA_IO_PORTS, DE4X5_EISA_TOTAL_SIZE);
release_region (iobase, DE4X5_EISA_TOTAL_SIZE);
return 0;
}
static void __devinit
srom_search(struct net_device *dev, struct pci_dev *pdev)
{
u_char pb;
u_short vendor, status;
u_int irq = 0, device;
u_long iobase = 0;
int i, j;
struct de4x5_private *lp = netdev_priv(dev);
struct pci_dev *this_dev;
list_for_each_entry(this_dev, &pdev->bus->devices, bus_list) {
vendor = this_dev->vendor;
device = this_dev->device << 8;
if (!(is_DC21040 || is_DC21041 || is_DC21140 || is_DC2114x)) continue;
pb = this_dev->bus->number;
lp->device = PCI_SLOT(this_dev->devfn);
lp->bus_num = pb;
if (is_DC2114x) {
device = ((this_dev->revision & CFRV_RN) < DC2114x_BRK
? DC21142 : DC21143);
}
lp->chipset = device;
iobase = pci_resource_start(this_dev, 0);
irq = this_dev->irq;
if ((irq == 0) || (irq == 0xff) || ((int)irq == -1)) continue;
pci_read_config_word(this_dev, PCI_COMMAND, &status);
if (!(status & PCI_COMMAND_IO)) continue;
DevicePresent(dev, DE4X5_APROM);
for (j=0, i=0; i<ETH_ALEN; i++) {
j += (u_char) *((u_char *)&lp->srom + SROM_HWADD + i);
}
if (j != 0 && j != 6 * 0xff) {
last.chipset = device;
last.bus = pb;
last.irq = irq;
for (i=0; i<ETH_ALEN; i++) {
last.addr[i] = (u_char)*((u_char *)&lp->srom + SROM_HWADD + i);
}
return;
}
}
}
static int __devinit de4x5_pci_probe (struct pci_dev *pdev,
const struct pci_device_id *ent)
{
u_char pb, pbus = 0, dev_num, dnum = 0, timer;
u_short vendor, status;
u_int irq = 0, device;
u_long iobase = 0;
int error;
struct net_device *dev;
struct de4x5_private *lp;
dev_num = PCI_SLOT(pdev->devfn);
pb = pdev->bus->number;
if (io) {
pbus = (u_short)(io >> 8);
dnum = (u_short)(io & 0xff);
if ((pbus != pb) || (dnum != dev_num))
return -ENODEV;
}
vendor = pdev->vendor;
device = pdev->device << 8;
if (!(is_DC21040 || is_DC21041 || is_DC21140 || is_DC2114x))
return -ENODEV;
if ((error = pci_enable_device (pdev)))
return error;
if (!(dev = alloc_etherdev (sizeof (struct de4x5_private)))) {
error = -ENOMEM;
goto disable_dev;
}
lp = netdev_priv(dev);
lp->bus = PCI;
lp->bus_num = 0;
if (lp->bus_num != pb) {
lp->bus_num = pb;
srom_search(dev, pdev);
}
lp->cfrv = pdev->revision;
lp->device = dev_num;
lp->bus_num = pb;
if (is_DC2114x) {
device = ((lp->cfrv & CFRV_RN) < DC2114x_BRK ? DC21142 : DC21143);
}
lp->chipset = device;
iobase = pci_resource_start(pdev, 0);
irq = pdev->irq;
if ((irq == 0) || (irq == 0xff) || ((int)irq == -1)) {
error = -ENODEV;
goto free_dev;
}
pci_read_config_word(pdev, PCI_COMMAND, &status);
#ifdef __powerpc__
if (!(status & PCI_COMMAND_IO)) {
status |= PCI_COMMAND_IO;
pci_write_config_word(pdev, PCI_COMMAND, status);
pci_read_config_word(pdev, PCI_COMMAND, &status);
}
#endif
if (!(status & PCI_COMMAND_IO)) {
error = -ENODEV;
goto free_dev;
}
if (!(status & PCI_COMMAND_MASTER)) {
status |= PCI_COMMAND_MASTER;
pci_write_config_word(pdev, PCI_COMMAND, status);
pci_read_config_word(pdev, PCI_COMMAND, &status);
}
if (!(status & PCI_COMMAND_MASTER)) {
error = -ENODEV;
goto free_dev;
}
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &timer);
if (timer < 0x60) {
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x60);
}
DevicePresent(dev, DE4X5_APROM);
if (!request_region (iobase, DE4X5_PCI_TOTAL_SIZE, "de4x5")) {
error = -EBUSY;
goto free_dev;
}
dev->irq = irq;
if ((error = de4x5_hw_init(dev, iobase, &pdev->dev))) {
goto release;
}
return 0;
release:
release_region (iobase, DE4X5_PCI_TOTAL_SIZE);
free_dev:
free_netdev (dev);
disable_dev:
pci_disable_device (pdev);
return error;
}
static void __devexit de4x5_pci_remove (struct pci_dev *pdev)
{
struct net_device *dev;
u_long iobase;
dev = dev_get_drvdata(&pdev->dev);
iobase = dev->base_addr;
unregister_netdev (dev);
free_netdev (dev);
release_region (iobase, DE4X5_PCI_TOTAL_SIZE);
pci_disable_device (pdev);
}
static int
autoconf_media(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
disable_ast(dev);
lp->c_media = AUTO;
inl(DE4X5_MFC);
lp->media = INIT;
lp->tcount = 0;
de4x5_ast(dev);
return lp->media;
}
static int
dc21040_autoconf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int next_tick = DE4X5_AUTOSENSE_MS;
s32 imr;
switch (lp->media) {
case INIT:
DISABLE_IRQs;
lp->tx_enable = false;
lp->timeout = -1;
de4x5_save_skbs(dev);
if ((lp->autosense == AUTO) || (lp->autosense == TP)) {
lp->media = TP;
} else if ((lp->autosense == BNC) || (lp->autosense == AUI) || (lp->autosense == BNC_AUI)) {
lp->media = BNC_AUI;
} else if (lp->autosense == EXT_SIA) {
lp->media = EXT_SIA;
} else {
lp->media = NC;
}
lp->local_state = 0;
next_tick = dc21040_autoconf(dev);
break;
case TP:
next_tick = dc21040_state(dev, 0x8f01, 0xffff, 0x0000, 3000, BNC_AUI,
TP_SUSPECT, test_tp);
break;
case TP_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, TP, test_tp, dc21040_autoconf);
break;
case BNC:
case AUI:
case BNC_AUI:
next_tick = dc21040_state(dev, 0x8f09, 0x0705, 0x0006, 3000, EXT_SIA,
BNC_AUI_SUSPECT, ping_media);
break;
case BNC_AUI_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, BNC_AUI, ping_media, dc21040_autoconf);
break;
case EXT_SIA:
next_tick = dc21040_state(dev, 0x3041, 0x0000, 0x0006, 3000,
NC, EXT_SIA_SUSPECT, ping_media);
break;
case EXT_SIA_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, EXT_SIA, ping_media, dc21040_autoconf);
break;
case NC:
reset_init_sia(dev, 0x8f01, 0xffff, 0x0000);
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tx_enable = false;
break;
}
return next_tick;
}
static int
dc21040_state(struct net_device *dev, int csr13, int csr14, int csr15, int timeout,
int next_state, int suspect_state,
int (*fn)(struct net_device *, int))
{
struct de4x5_private *lp = netdev_priv(dev);
int next_tick = DE4X5_AUTOSENSE_MS;
int linkBad;
switch (lp->local_state) {
case 0:
reset_init_sia(dev, csr13, csr14, csr15);
lp->local_state++;
next_tick = 500;
break;
case 1:
if (!lp->tx_enable) {
linkBad = fn(dev, timeout);
if (linkBad < 0) {
next_tick = linkBad & ~TIMER_CB;
} else {
if (linkBad && (lp->autosense == AUTO)) {
lp->local_state = 0;
lp->media = next_state;
} else {
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = suspect_state;
next_tick = 3000;
}
break;
}
return next_tick;
}
static int
de4x5_suspect_state(struct net_device *dev, int timeout, int prev_state,
int (*fn)(struct net_device *, int),
int (*asfn)(struct net_device *))
{
struct de4x5_private *lp = netdev_priv(dev);
int next_tick = DE4X5_AUTOSENSE_MS;
int linkBad;
switch (lp->local_state) {
case 1:
if (lp->linkOK) {
lp->media = prev_state;
} else {
lp->local_state++;
next_tick = asfn(dev);
}
break;
case 2:
linkBad = fn(dev, timeout);
if (linkBad < 0) {
next_tick = linkBad & ~TIMER_CB;
} else if (!linkBad) {
lp->local_state--;
lp->media = prev_state;
} else {
lp->media = INIT;
lp->tcount++;
}
}
return next_tick;
}
static int
dc21041_autoconf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 sts, irqs, irq_mask, imr, omr;
int next_tick = DE4X5_AUTOSENSE_MS;
switch (lp->media) {
case INIT:
DISABLE_IRQs;
lp->tx_enable = false;
lp->timeout = -1;
de4x5_save_skbs(dev);
if ((lp->autosense == AUTO) || (lp->autosense == TP_NW)) {
lp->media = TP;
} else if (lp->autosense == TP) {
lp->media = TP;
} else if (lp->autosense == BNC) {
lp->media = BNC;
} else if (lp->autosense == AUI) {
lp->media = AUI;
} else {
lp->media = NC;
}
lp->local_state = 0;
next_tick = dc21041_autoconf(dev);
break;
case TP_NW:
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr | OMR_FDX, DE4X5_OMR);
}
irqs = STS_LNF | STS_LNP;
irq_mask = IMR_LFM | IMR_LPM;
sts = test_media(dev, irqs, irq_mask, 0xef01, 0xffff, 0x0008, 2400);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (sts & STS_LNP) {
lp->media = ANS;
} else {
lp->media = AUI;
}
next_tick = dc21041_autoconf(dev);
}
break;
case ANS:
if (!lp->tx_enable) {
irqs = STS_LNP;
irq_mask = IMR_LPM;
sts = test_ans(dev, irqs, irq_mask, 3000);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (!(sts & STS_LNP) && (lp->autosense == AUTO)) {
lp->media = TP;
next_tick = dc21041_autoconf(dev);
} else {
lp->local_state = 1;
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = ANS_SUSPECT;
next_tick = 3000;
}
break;
case ANS_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, ANS, test_tp, dc21041_autoconf);
break;
case TP:
if (!lp->tx_enable) {
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_FDX, DE4X5_OMR);
}
irqs = STS_LNF | STS_LNP;
irq_mask = IMR_LFM | IMR_LPM;
sts = test_media(dev,irqs, irq_mask, 0xef01, 0xff3f, 0x0008, 2400);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (!(sts & STS_LNP) && (lp->autosense == AUTO)) {
if (inl(DE4X5_SISR) & SISR_NRA) {
lp->media = AUI;
} else {
lp->media = BNC;
}
next_tick = dc21041_autoconf(dev);
} else {
lp->local_state = 1;
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = TP_SUSPECT;
next_tick = 3000;
}
break;
case TP_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, TP, test_tp, dc21041_autoconf);
break;
case AUI:
if (!lp->tx_enable) {
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_FDX, DE4X5_OMR);
}
irqs = 0;
irq_mask = 0;
sts = test_media(dev,irqs, irq_mask, 0xef09, 0xf73d, 0x000e, 1000);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (!(inl(DE4X5_SISR) & SISR_SRA) && (lp->autosense == AUTO)) {
lp->media = BNC;
next_tick = dc21041_autoconf(dev);
} else {
lp->local_state = 1;
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = AUI_SUSPECT;
next_tick = 3000;
}
break;
case AUI_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, AUI, ping_media, dc21041_autoconf);
break;
case BNC:
switch (lp->local_state) {
case 0:
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_FDX, DE4X5_OMR);
}
irqs = 0;
irq_mask = 0;
sts = test_media(dev,irqs, irq_mask, 0xef09, 0xf73d, 0x0006, 1000);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
lp->local_state++;
next_tick = dc21041_autoconf(dev);
}
break;
case 1:
if (!lp->tx_enable) {
if ((sts = ping_media(dev, 3000)) < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (sts) {
lp->local_state = 0;
lp->media = NC;
} else {
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = BNC_SUSPECT;
next_tick = 3000;
}
break;
}
break;
case BNC_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, BNC, ping_media, dc21041_autoconf);
break;
case NC:
omr = inl(DE4X5_OMR);
outl(omr | OMR_FDX, DE4X5_OMR);
reset_init_sia(dev, 0xef01, 0xffff, 0x0008);
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tx_enable = false;
break;
}
return next_tick;
}
static int
dc21140m_autoconf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int ana, anlpa, cap, cr, slnk, sr;
int next_tick = DE4X5_AUTOSENSE_MS;
u_long imr, omr, iobase = dev->base_addr;
switch(lp->media) {
case INIT:
if (lp->timeout < 0) {
DISABLE_IRQs;
lp->tx_enable = false;
lp->linkOK = 0;
de4x5_save_skbs(dev);
}
if ((next_tick = de4x5_reset_phy(dev)) < 0) {
next_tick &= ~TIMER_CB;
} else {
if (lp->useSROM) {
if (srom_map_media(dev) < 0) {
lp->tcount++;
return next_tick;
}
srom_exec(dev, lp->phy[lp->active].gep);
if (lp->infoblock_media == ANS) {
ana = lp->phy[lp->active].ana | MII_ANA_CSMA;
mii_wr(ana, MII_ANA, lp->phy[lp->active].addr, DE4X5_MII);
}
} else {
lp->tmp = MII_SR_ASSC;
SET_10Mb;
if (lp->autosense == _100Mb) {
lp->media = _100Mb;
} else if (lp->autosense == _10Mb) {
lp->media = _10Mb;
} else if ((lp->autosense == AUTO) &&
((sr=is_anc_capable(dev)) & MII_SR_ANC)) {
ana = (((sr >> 6) & MII_ANA_TAF) | MII_ANA_CSMA);
ana &= (lp->fdx ? ~0 : ~MII_ANA_FDAM);
mii_wr(ana, MII_ANA, lp->phy[lp->active].addr, DE4X5_MII);
lp->media = ANS;
} else if (lp->autosense == AUTO) {
lp->media = SPD_DET;
} else if (is_spd_100(dev) && is_100_up(dev)) {
lp->media = _100Mb;
} else {
lp->media = NC;
}
}
lp->local_state = 0;
next_tick = dc21140m_autoconf(dev);
}
break;
case ANS:
switch (lp->local_state) {
case 0:
if (lp->timeout < 0) {
mii_wr(MII_CR_ASSE | MII_CR_RAN, MII_CR, lp->phy[lp->active].addr, DE4X5_MII);
}
cr = test_mii_reg(dev, MII_CR, MII_CR_RAN, false, 500);
if (cr < 0) {
next_tick = cr & ~TIMER_CB;
} else {
if (cr) {
lp->local_state = 0;
lp->media = SPD_DET;
} else {
lp->local_state++;
}
next_tick = dc21140m_autoconf(dev);
}
break;
case 1:
if ((sr=test_mii_reg(dev, MII_SR, MII_SR_ASSC, true, 2000)) < 0) {
next_tick = sr & ~TIMER_CB;
} else {
lp->media = SPD_DET;
lp->local_state = 0;
if (sr) {
lp->tmp = MII_SR_ASSC;
anlpa = mii_rd(MII_ANLPA, lp->phy[lp->active].addr, DE4X5_MII);
ana = mii_rd(MII_ANA, lp->phy[lp->active].addr, DE4X5_MII);
if (!(anlpa & MII_ANLPA_RF) &&
(cap = anlpa & MII_ANLPA_TAF & ana)) {
if (cap & MII_ANA_100M) {
lp->fdx = (ana & anlpa & MII_ANA_FDAM & MII_ANA_100M) != 0;
lp->media = _100Mb;
} else if (cap & MII_ANA_10M) {
lp->fdx = (ana & anlpa & MII_ANA_FDAM & MII_ANA_10M) != 0;
lp->media = _10Mb;
}
}
}
next_tick = dc21140m_autoconf(dev);
}
break;
}
break;
case SPD_DET:
if (lp->timeout < 0) {
lp->tmp = (lp->phy[lp->active].id ? MII_SR_LKS :
(~gep_rd(dev) & GEP_LNP));
SET_100Mb_PDET;
}
if ((slnk = test_for_100Mb(dev, 6500)) < 0) {
next_tick = slnk & ~TIMER_CB;
} else {
if (is_spd_100(dev) && is_100_up(dev)) {
lp->media = _100Mb;
} else if ((!is_spd_100(dev) && (is_10_up(dev) & lp->tmp))) {
lp->media = _10Mb;
} else {
lp->media = NC;
}
next_tick = dc21140m_autoconf(dev);
}
break;
case _100Mb:
next_tick = 3000;
if (!lp->tx_enable) {
SET_100Mb;
de4x5_init_connection(dev);
} else {
if (!lp->linkOK && (lp->autosense == AUTO)) {
if (!is_100_up(dev) || (!lp->useSROM && !is_spd_100(dev))) {
lp->media = INIT;
lp->tcount++;
next_tick = DE4X5_AUTOSENSE_MS;
}
}
}
break;
case BNC:
case AUI:
case _10Mb:
next_tick = 3000;
if (!lp->tx_enable) {
SET_10Mb;
de4x5_init_connection(dev);
} else {
if (!lp->linkOK && (lp->autosense == AUTO)) {
if (!is_10_up(dev) || (!lp->useSROM && is_spd_100(dev))) {
lp->media = INIT;
lp->tcount++;
next_tick = DE4X5_AUTOSENSE_MS;
}
}
}
break;
case NC:
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tx_enable = false;
break;
}
return next_tick;
}
static int
dc2114x_autoconf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 cr, anlpa, ana, cap, irqs, irq_mask, imr, omr, slnk, sr, sts;
int next_tick = DE4X5_AUTOSENSE_MS;
switch (lp->media) {
case INIT:
if (lp->timeout < 0) {
DISABLE_IRQs;
lp->tx_enable = false;
lp->linkOK = 0;
lp->timeout = -1;
de4x5_save_skbs(dev);
if (lp->params.autosense & ~AUTO) {
srom_map_media(dev);
if (lp->media != lp->params.autosense) {
lp->tcount++;
lp->media = INIT;
return next_tick;
}
lp->media = INIT;
}
}
if ((next_tick = de4x5_reset_phy(dev)) < 0) {
next_tick &= ~TIMER_CB;
} else {
if (lp->autosense == _100Mb) {
lp->media = _100Mb;
} else if (lp->autosense == _10Mb) {
lp->media = _10Mb;
} else if (lp->autosense == TP) {
lp->media = TP;
} else if (lp->autosense == BNC) {
lp->media = BNC;
} else if (lp->autosense == AUI) {
lp->media = AUI;
} else {
lp->media = SPD_DET;
if ((lp->infoblock_media == ANS) &&
((sr=is_anc_capable(dev)) & MII_SR_ANC)) {
ana = (((sr >> 6) & MII_ANA_TAF) | MII_ANA_CSMA);
ana &= (lp->fdx ? ~0 : ~MII_ANA_FDAM);
mii_wr(ana, MII_ANA, lp->phy[lp->active].addr, DE4X5_MII);
lp->media = ANS;
}
}
lp->local_state = 0;
next_tick = dc2114x_autoconf(dev);
}
break;
case ANS:
switch (lp->local_state) {
case 0:
if (lp->timeout < 0) {
mii_wr(MII_CR_ASSE | MII_CR_RAN, MII_CR, lp->phy[lp->active].addr, DE4X5_MII);
}
cr = test_mii_reg(dev, MII_CR, MII_CR_RAN, false, 500);
if (cr < 0) {
next_tick = cr & ~TIMER_CB;
} else {
if (cr) {
lp->local_state = 0;
lp->media = SPD_DET;
} else {
lp->local_state++;
}
next_tick = dc2114x_autoconf(dev);
}
break;
case 1:
sr = test_mii_reg(dev, MII_SR, MII_SR_ASSC, true, 2000);
if (sr < 0) {
next_tick = sr & ~TIMER_CB;
} else {
lp->media = SPD_DET;
lp->local_state = 0;
if (sr) {
lp->tmp = MII_SR_ASSC;
anlpa = mii_rd(MII_ANLPA, lp->phy[lp->active].addr, DE4X5_MII);
ana = mii_rd(MII_ANA, lp->phy[lp->active].addr, DE4X5_MII);
if (!(anlpa & MII_ANLPA_RF) &&
(cap = anlpa & MII_ANLPA_TAF & ana)) {
if (cap & MII_ANA_100M) {
lp->fdx = (ana & anlpa & MII_ANA_FDAM & MII_ANA_100M) != 0;
lp->media = _100Mb;
} else if (cap & MII_ANA_10M) {
lp->fdx = (ana & anlpa & MII_ANA_FDAM & MII_ANA_10M) != 0;
lp->media = _10Mb;
}
}
}
next_tick = dc2114x_autoconf(dev);
}
break;
}
break;
case AUI:
if (!lp->tx_enable) {
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_FDX, DE4X5_OMR);
}
irqs = 0;
irq_mask = 0;
sts = test_media(dev,irqs, irq_mask, 0, 0, 0, 1000);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (!(inl(DE4X5_SISR) & SISR_SRA) && (lp->autosense == AUTO)) {
lp->media = BNC;
next_tick = dc2114x_autoconf(dev);
} else {
lp->local_state = 1;
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = AUI_SUSPECT;
next_tick = 3000;
}
break;
case AUI_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, AUI, ping_media, dc2114x_autoconf);
break;
case BNC:
switch (lp->local_state) {
case 0:
if (lp->timeout < 0) {
omr = inl(DE4X5_OMR);
outl(omr & ~OMR_FDX, DE4X5_OMR);
}
irqs = 0;
irq_mask = 0;
sts = test_media(dev,irqs, irq_mask, 0, 0, 0, 1000);
if (sts < 0) {
next_tick = sts & ~TIMER_CB;
} else {
lp->local_state++;
next_tick = dc2114x_autoconf(dev);
}
break;
case 1:
if (!lp->tx_enable) {
if ((sts = ping_media(dev, 3000)) < 0) {
next_tick = sts & ~TIMER_CB;
} else {
if (sts) {
lp->local_state = 0;
lp->tcount++;
lp->media = INIT;
} else {
de4x5_init_connection(dev);
}
}
} else if (!lp->linkOK && (lp->autosense == AUTO)) {
lp->media = BNC_SUSPECT;
next_tick = 3000;
}
break;
}
break;
case BNC_SUSPECT:
next_tick = de4x5_suspect_state(dev, 1000, BNC, ping_media, dc2114x_autoconf);
break;
case SPD_DET:
if (srom_map_media(dev) < 0) {
lp->tcount++;
lp->media = INIT;
return next_tick;
}
if (lp->media == _100Mb) {
if ((slnk = test_for_100Mb(dev, 6500)) < 0) {
lp->media = SPD_DET;
return slnk & ~TIMER_CB;
}
} else {
if (wait_for_link(dev) < 0) {
lp->media = SPD_DET;
return PDET_LINK_WAIT;
}
}
if (lp->media == ANS) {
if (is_spd_100(dev)) {
lp->media = _100Mb;
} else {
lp->media = _10Mb;
}
next_tick = dc2114x_autoconf(dev);
} else if (((lp->media == _100Mb) && is_100_up(dev)) ||
(((lp->media == _10Mb) || (lp->media == TP) ||
(lp->media == BNC) || (lp->media == AUI)) &&
is_10_up(dev))) {
next_tick = dc2114x_autoconf(dev);
} else {
lp->tcount++;
lp->media = INIT;
}
break;
case _10Mb:
next_tick = 3000;
if (!lp->tx_enable) {
SET_10Mb;
de4x5_init_connection(dev);
} else {
if (!lp->linkOK && (lp->autosense == AUTO)) {
if (!is_10_up(dev) || (!lp->useSROM && is_spd_100(dev))) {
lp->media = INIT;
lp->tcount++;
next_tick = DE4X5_AUTOSENSE_MS;
}
}
}
break;
case _100Mb:
next_tick = 3000;
if (!lp->tx_enable) {
SET_100Mb;
de4x5_init_connection(dev);
} else {
if (!lp->linkOK && (lp->autosense == AUTO)) {
if (!is_100_up(dev) || (!lp->useSROM && !is_spd_100(dev))) {
lp->media = INIT;
lp->tcount++;
next_tick = DE4X5_AUTOSENSE_MS;
}
}
}
break;
default:
lp->tcount++;
printk("Huh?: media:%02x\n", lp->media);
lp->media = INIT;
break;
}
return next_tick;
}
static int
srom_autoconf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
return lp->infoleaf_fn(dev);
}
static int
srom_map_media(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
lp->fdx = false;
if (lp->infoblock_media == lp->media)
return 0;
switch(lp->infoblock_media) {
case SROM_10BASETF:
if (!lp->params.fdx) return -1;
lp->fdx = true;
case SROM_10BASET:
if (lp->params.fdx && !lp->fdx) return -1;
if ((lp->chipset == DC21140) || ((lp->chipset & ~0x00ff) == DC2114x)) {
lp->media = _10Mb;
} else {
lp->media = TP;
}
break;
case SROM_10BASE2:
lp->media = BNC;
break;
case SROM_10BASE5:
lp->media = AUI;
break;
case SROM_100BASETF:
if (!lp->params.fdx) return -1;
lp->fdx = true;
case SROM_100BASET:
if (lp->params.fdx && !lp->fdx) return -1;
lp->media = _100Mb;
break;
case SROM_100BASET4:
lp->media = _100Mb;
break;
case SROM_100BASEFF:
if (!lp->params.fdx) return -1;
lp->fdx = true;
case SROM_100BASEF:
if (lp->params.fdx && !lp->fdx) return -1;
lp->media = _100Mb;
break;
case ANS:
lp->media = ANS;
lp->fdx = lp->params.fdx;
break;
default:
printk("%s: Bad media code [%d] detected in SROM!\n", dev->name,
lp->infoblock_media);
return -1;
break;
}
return 0;
}
static void
de4x5_init_connection(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_long flags = 0;
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
spin_lock_irqsave(&lp->lock, flags);
de4x5_rst_desc_ring(dev);
de4x5_setup_intr(dev);
lp->tx_enable = true;
spin_unlock_irqrestore(&lp->lock, flags);
outl(POLL_DEMAND, DE4X5_TPD);
netif_wake_queue(dev);
}
static int
de4x5_reset_phy(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int next_tick = 0;
if ((lp->useSROM) || (lp->phy[lp->active].id)) {
if (lp->timeout < 0) {
if (lp->useSROM) {
if (lp->phy[lp->active].rst) {
srom_exec(dev, lp->phy[lp->active].rst);
srom_exec(dev, lp->phy[lp->active].rst);
} else if (lp->rst) {
srom_exec(dev, lp->rst);
srom_exec(dev, lp->rst);
}
} else {
PHY_HARD_RESET;
}
if (lp->useMII) {
mii_wr(MII_CR_RST, MII_CR, lp->phy[lp->active].addr, DE4X5_MII);
}
}
if (lp->useMII) {
next_tick = test_mii_reg(dev, MII_CR, MII_CR_RST, false, 500);
}
} else if (lp->chipset == DC21140) {
PHY_HARD_RESET;
}
return next_tick;
}
static int
test_media(struct net_device *dev, s32 irqs, s32 irq_mask, s32 csr13, s32 csr14, s32 csr15, s32 msec)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 sts, csr12;
if (lp->timeout < 0) {
lp->timeout = msec/100;
if (!lp->useSROM) {
reset_init_sia(dev, csr13, csr14, csr15);
}
outl(irq_mask, DE4X5_IMR);
sts = inl(DE4X5_STS);
outl(sts, DE4X5_STS);
if ((lp->chipset == DC21041) || lp->useSROM) {
csr12 = inl(DE4X5_SISR);
outl(csr12, DE4X5_SISR);
}
}
sts = inl(DE4X5_STS) & ~TIMER_CB;
if (!(sts & irqs) && --lp->timeout) {
sts = 100 | TIMER_CB;
} else {
lp->timeout = -1;
}
return sts;
}
static int
test_tp(struct net_device *dev, s32 msec)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int sisr;
if (lp->timeout < 0) {
lp->timeout = msec/100;
}
sisr = (inl(DE4X5_SISR) & ~TIMER_CB) & (SISR_LKF | SISR_NCR);
if (sisr && --lp->timeout) {
sisr = 100 | TIMER_CB;
} else {
lp->timeout = -1;
}
return sisr;
}
static int
test_for_100Mb(struct net_device *dev, int msec)
{
struct de4x5_private *lp = netdev_priv(dev);
int gep = 0, ret = ((lp->chipset & ~0x00ff)==DC2114x? -1 :GEP_SLNK);
if (lp->timeout < 0) {
if ((msec/SAMPLE_INTERVAL) <= 0) return 0;
if (msec > SAMPLE_DELAY) {
lp->timeout = (msec - SAMPLE_DELAY)/SAMPLE_INTERVAL;
gep = SAMPLE_DELAY | TIMER_CB;
return gep;
} else {
lp->timeout = msec/SAMPLE_INTERVAL;
}
}
if (lp->phy[lp->active].id || lp->useSROM) {
gep = is_100_up(dev) | is_spd_100(dev);
} else {
gep = (~gep_rd(dev) & (GEP_SLNK | GEP_LNP));
}
if (!(gep & ret) && --lp->timeout) {
gep = SAMPLE_INTERVAL | TIMER_CB;
} else {
lp->timeout = -1;
}
return gep;
}
static int
wait_for_link(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
if (lp->timeout < 0) {
lp->timeout = 1;
}
if (lp->timeout--) {
return TIMER_CB;
} else {
lp->timeout = -1;
}
return 0;
}
static int
test_mii_reg(struct net_device *dev, int reg, int mask, bool pol, long msec)
{
struct de4x5_private *lp = netdev_priv(dev);
int test;
u_long iobase = dev->base_addr;
if (lp->timeout < 0) {
lp->timeout = msec/100;
}
reg = mii_rd((u_char)reg, lp->phy[lp->active].addr, DE4X5_MII) & mask;
test = (reg ^ (pol ? ~0 : 0)) & mask;
if (test && --lp->timeout) {
reg = 100 | TIMER_CB;
} else {
lp->timeout = -1;
}
return reg;
}
static int
is_spd_100(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int spd;
if (lp->useMII) {
spd = mii_rd(lp->phy[lp->active].spd.reg, lp->phy[lp->active].addr, DE4X5_MII);
spd = ~(spd ^ lp->phy[lp->active].spd.value);
spd &= lp->phy[lp->active].spd.mask;
} else if (!lp->useSROM) {
spd = ((~gep_rd(dev)) & GEP_SLNK);
} else {
if ((lp->ibn == 2) || !lp->asBitValid)
return (lp->chipset == DC21143) ? (~inl(DE4X5_SISR)&SISR_LS100) : 0;
spd = (lp->asBitValid & (lp->asPolarity ^ (gep_rd(dev) & lp->asBit))) |
(lp->linkOK & ~lp->asBitValid);
}
return spd;
}
static int
is_100_up(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->useMII) {
mii_rd(MII_SR, lp->phy[lp->active].addr, DE4X5_MII);
return mii_rd(MII_SR, lp->phy[lp->active].addr, DE4X5_MII) & MII_SR_LKS;
} else if (!lp->useSROM) {
return (~gep_rd(dev)) & GEP_SLNK;
} else {
if ((lp->ibn == 2) || !lp->asBitValid)
return (lp->chipset == DC21143) ? (~inl(DE4X5_SISR)&SISR_LS100) : 0;
return (lp->asBitValid&(lp->asPolarity^(gep_rd(dev)&lp->asBit))) |
(lp->linkOK & ~lp->asBitValid);
}
}
static int
is_10_up(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->useMII) {
mii_rd(MII_SR, lp->phy[lp->active].addr, DE4X5_MII);
return mii_rd(MII_SR, lp->phy[lp->active].addr, DE4X5_MII) & MII_SR_LKS;
} else if (!lp->useSROM) {
return (~gep_rd(dev)) & GEP_LNP;
} else {
if ((lp->ibn == 2) || !lp->asBitValid)
return ((lp->chipset & ~0x00ff) == DC2114x) ?
(~inl(DE4X5_SISR)&SISR_LS10):
0;
return (lp->asBitValid&(lp->asPolarity^(gep_rd(dev)&lp->asBit))) |
(lp->linkOK & ~lp->asBitValid);
}
}
static int
is_anc_capable(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->phy[lp->active].id && (!lp->useSROM || lp->useMII)) {
return mii_rd(MII_SR, lp->phy[lp->active].addr, DE4X5_MII);
} else if ((lp->chipset & ~0x00ff) == DC2114x) {
return (inl(DE4X5_SISR) & SISR_LPN) >> 12;
} else {
return 0;
}
}
static int
ping_media(struct net_device *dev, int msec)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int sisr;
if (lp->timeout < 0) {
lp->timeout = msec/100;
lp->tmp = lp->tx_new;
load_packet(dev, lp->frame, TD_LS | TD_FS | sizeof(lp->frame), (struct sk_buff *)1);
lp->tx_new = (lp->tx_new + 1) % lp->txRingSize;
outl(POLL_DEMAND, DE4X5_TPD);
}
sisr = inl(DE4X5_SISR);
if ((!(sisr & SISR_NCR)) &&
((s32)le32_to_cpu(lp->tx_ring[lp->tmp].status) < 0) &&
(--lp->timeout)) {
sisr = 100 | TIMER_CB;
} else {
if ((!(sisr & SISR_NCR)) &&
!(le32_to_cpu(lp->tx_ring[lp->tmp].status) & (T_OWN | TD_ES)) &&
lp->timeout) {
sisr = 0;
} else {
sisr = 1;
}
lp->timeout = -1;
}
return sisr;
}
static struct sk_buff *
de4x5_alloc_rx_buff(struct net_device *dev, int index, int len)
{
struct de4x5_private *lp = netdev_priv(dev);
struct sk_buff *p;
#if !defined(__alpha__) && !defined(__powerpc__) && !defined(CONFIG_SPARC) && !defined(DE4X5_DO_MEMCPY)
struct sk_buff *ret;
u_long i=0, tmp;
p = netdev_alloc_skb(dev, IEEE802_3_SZ + DE4X5_ALIGN + 2);
if (!p) return NULL;
tmp = virt_to_bus(p->data);
i = ((tmp + DE4X5_ALIGN) & ~DE4X5_ALIGN) - tmp;
skb_reserve(p, i);
lp->rx_ring[index].buf = cpu_to_le32(tmp + i);
ret = lp->rx_skb[index];
lp->rx_skb[index] = p;
if ((u_long) ret > 1) {
skb_put(ret, len);
}
return ret;
#else
if (lp->state != OPEN) return (struct sk_buff *)1;
p = netdev_alloc_skb(dev, len + 2);
if (!p) return NULL;
skb_reserve(p, 2);
if (index < lp->rx_old) {
short tlen = (lp->rxRingSize - lp->rx_old) * RX_BUFF_SZ;
memcpy(skb_put(p,tlen),lp->rx_bufs + lp->rx_old * RX_BUFF_SZ,tlen);
memcpy(skb_put(p,len-tlen),lp->rx_bufs,len-tlen);
} else {
memcpy(skb_put(p,len),lp->rx_bufs + lp->rx_old * RX_BUFF_SZ,len);
}
return p;
#endif
}
static void
de4x5_free_rx_buffs(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int i;
for (i=0; i<lp->rxRingSize; i++) {
if ((u_long) lp->rx_skb[i] > 1) {
dev_kfree_skb(lp->rx_skb[i]);
}
lp->rx_ring[i].status = 0;
lp->rx_skb[i] = (struct sk_buff *)1;
}
}
static void
de4x5_free_tx_buffs(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int i;
for (i=0; i<lp->txRingSize; i++) {
if (lp->tx_skb[i])
de4x5_free_tx_buff(lp, i);
lp->tx_ring[i].status = 0;
}
__skb_queue_purge(&lp->cache.queue);
}
static void
de4x5_save_skbs(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 omr;
if (!lp->cache.save_cnt) {
STOP_DE4X5;
de4x5_tx(dev);
de4x5_free_tx_buffs(dev);
de4x5_cache_state(dev, DE4X5_SAVE_STATE);
de4x5_sw_reset(dev);
de4x5_cache_state(dev, DE4X5_RESTORE_STATE);
lp->cache.save_cnt++;
START_DE4X5;
}
}
static void
de4x5_rst_desc_ring(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int i;
s32 omr;
if (lp->cache.save_cnt) {
STOP_DE4X5;
outl(lp->dma_rings, DE4X5_RRBA);
outl(lp->dma_rings + NUM_RX_DESC * sizeof(struct de4x5_desc),
DE4X5_TRBA);
lp->rx_new = lp->rx_old = 0;
lp->tx_new = lp->tx_old = 0;
for (i = 0; i < lp->rxRingSize; i++) {
lp->rx_ring[i].status = cpu_to_le32(R_OWN);
}
for (i = 0; i < lp->txRingSize; i++) {
lp->tx_ring[i].status = cpu_to_le32(0);
}
barrier();
lp->cache.save_cnt--;
START_DE4X5;
}
}
static void
de4x5_cache_state(struct net_device *dev, int flag)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
switch(flag) {
case DE4X5_SAVE_STATE:
lp->cache.csr0 = inl(DE4X5_BMR);
lp->cache.csr6 = (inl(DE4X5_OMR) & ~(OMR_ST | OMR_SR));
lp->cache.csr7 = inl(DE4X5_IMR);
break;
case DE4X5_RESTORE_STATE:
outl(lp->cache.csr0, DE4X5_BMR);
outl(lp->cache.csr6, DE4X5_OMR);
outl(lp->cache.csr7, DE4X5_IMR);
if (lp->chipset == DC21140) {
gep_wr(lp->cache.gepc, dev);
gep_wr(lp->cache.gep, dev);
} else {
reset_init_sia(dev, lp->cache.csr13, lp->cache.csr14,
lp->cache.csr15);
}
break;
}
}
static void
de4x5_put_cache(struct net_device *dev, struct sk_buff *skb)
{
struct de4x5_private *lp = netdev_priv(dev);
__skb_queue_tail(&lp->cache.queue, skb);
}
static void
de4x5_putb_cache(struct net_device *dev, struct sk_buff *skb)
{
struct de4x5_private *lp = netdev_priv(dev);
__skb_queue_head(&lp->cache.queue, skb);
}
static struct sk_buff *
de4x5_get_cache(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
return __skb_dequeue(&lp->cache.queue);
}
static int
test_ans(struct net_device *dev, s32 irqs, s32 irq_mask, s32 msec)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 sts, ans;
if (lp->timeout < 0) {
lp->timeout = msec/100;
outl(irq_mask, DE4X5_IMR);
sts = inl(DE4X5_STS);
outl(sts, DE4X5_STS);
}
ans = inl(DE4X5_SISR) & SISR_ANS;
sts = inl(DE4X5_STS) & ~TIMER_CB;
if (!(sts & irqs) && (ans ^ ANS_NWOK) && --lp->timeout) {
sts = 100 | TIMER_CB;
} else {
lp->timeout = -1;
}
return sts;
}
static void
de4x5_setup_intr(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 imr, sts;
if (inl(DE4X5_OMR) & OMR_SR) {
imr = 0;
UNMASK_IRQs;
sts = inl(DE4X5_STS);
outl(sts, DE4X5_STS);
ENABLE_IRQs;
}
}
static void
reset_init_sia(struct net_device *dev, s32 csr13, s32 csr14, s32 csr15)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
RESET_SIA;
if (lp->useSROM) {
if (lp->ibn == 3) {
srom_exec(dev, lp->phy[lp->active].rst);
srom_exec(dev, lp->phy[lp->active].gep);
outl(1, DE4X5_SICR);
return;
} else {
csr15 = lp->cache.csr15;
csr14 = lp->cache.csr14;
csr13 = lp->cache.csr13;
outl(csr15 | lp->cache.gepc, DE4X5_SIGR);
outl(csr15 | lp->cache.gep, DE4X5_SIGR);
}
} else {
outl(csr15, DE4X5_SIGR);
}
outl(csr14, DE4X5_STRR);
outl(csr13, DE4X5_SICR);
mdelay(10);
}
static void
create_packet(struct net_device *dev, char *frame, int len)
{
int i;
char *buf = frame;
for (i=0; i<ETH_ALEN; i++) {
*buf++ = dev->dev_addr[i];
}
for (i=0; i<ETH_ALEN; i++) {
*buf++ = dev->dev_addr[i];
}
*buf++ = 0;
*buf++ = 1;
}
static int
EISA_signature(char *name, struct device *device)
{
int i, status = 0, siglen = ARRAY_SIZE(de4x5_signatures);
struct eisa_device *edev;
*name = '\0';
edev = to_eisa_device (device);
i = edev->id.driver_data;
if (i >= 0 && i < siglen) {
strcpy (name, de4x5_signatures[i]);
status = 1;
}
return status;
}
static int
PCI_signature(char *name, struct de4x5_private *lp)
{
int i, status = 0, siglen = ARRAY_SIZE(de4x5_signatures);
if (lp->chipset == DC21040) {
strcpy(name, "DE434/5");
return status;
} else {
int tmp = *((char *)&lp->srom + 19) * 3;
strncpy(name, (char *)&lp->srom + 26 + tmp, 8);
}
name[8] = '\0';
for (i=0; i<siglen; i++) {
if (strstr(name,de4x5_signatures[i])!=NULL) break;
}
if (i == siglen) {
if (dec_only) {
*name = '\0';
} else {
strcpy(name, (((lp->chipset == DC21040) ? "DC21040" :
((lp->chipset == DC21041) ? "DC21041" :
((lp->chipset == DC21140) ? "DC21140" :
((lp->chipset == DC21142) ? "DC21142" :
((lp->chipset == DC21143) ? "DC21143" : "UNKNOWN"
)))))));
}
if (lp->chipset != DC21041) {
lp->useSROM = true;
}
} else if ((lp->chipset & ~0x00ff) == DC2114x) {
lp->useSROM = true;
}
return status;
}
static void
DevicePresent(struct net_device *dev, u_long aprom_addr)
{
int i, j=0;
struct de4x5_private *lp = netdev_priv(dev);
if (lp->chipset == DC21040) {
if (lp->bus == EISA) {
enet_addr_rst(aprom_addr);
} else {
outl(0, aprom_addr);
}
} else {
u_short tmp;
__le16 *p = (__le16 *)((char *)&lp->srom + SROM_HWADD);
for (i=0; i<(ETH_ALEN>>1); i++) {
tmp = srom_rd(aprom_addr, (SROM_HWADD>>1) + i);
j += tmp;
*p = cpu_to_le16(tmp);
}
if (j == 0 || j == 3 * 0xffff) {
return;
}
p = (__le16 *)&lp->srom;
for (i=0; i<(sizeof(struct de4x5_srom)>>1); i++) {
tmp = srom_rd(aprom_addr, i);
*p++ = cpu_to_le16(tmp);
}
de4x5_dbg_srom((struct de4x5_srom *)&lp->srom);
}
}
static void
enet_addr_rst(u_long aprom_addr)
{
union {
struct {
u32 a;
u32 b;
} llsig;
char Sig[sizeof(u32) << 1];
} dev;
short sigLength=0;
s8 data;
int i, j;
dev.llsig.a = ETH_PROM_SIG;
dev.llsig.b = ETH_PROM_SIG;
sigLength = sizeof(u32) << 1;
for (i=0,j=0;j<sigLength && i<PROBE_LENGTH+sigLength-1;i++) {
data = inb(aprom_addr);
if (dev.Sig[j] == data) {
j++;
} else {
if (data == dev.Sig[0]) {
j=1;
} else {
j=0;
}
}
}
}
static int
get_hw_addr(struct net_device *dev)
{
u_long iobase = dev->base_addr;
int broken, i, k, tmp, status = 0;
u_short j,chksum;
struct de4x5_private *lp = netdev_priv(dev);
broken = de4x5_bad_srom(lp);
for (i=0,k=0,j=0;j<3;j++) {
k <<= 1;
if (k > 0xffff) k-=0xffff;
if (lp->bus == PCI) {
if (lp->chipset == DC21040) {
while ((tmp = inl(DE4X5_APROM)) < 0);
k += (u_char) tmp;
dev->dev_addr[i++] = (u_char) tmp;
while ((tmp = inl(DE4X5_APROM)) < 0);
k += (u_short) (tmp << 8);
dev->dev_addr[i++] = (u_char) tmp;
} else if (!broken) {
dev->dev_addr[i] = (u_char) lp->srom.ieee_addr[i]; i++;
dev->dev_addr[i] = (u_char) lp->srom.ieee_addr[i]; i++;
} else if ((broken == SMC) || (broken == ACCTON)) {
dev->dev_addr[i] = *((u_char *)&lp->srom + i); i++;
dev->dev_addr[i] = *((u_char *)&lp->srom + i); i++;
}
} else {
k += (u_char) (tmp = inb(EISA_APROM));
dev->dev_addr[i++] = (u_char) tmp;
k += (u_short) ((tmp = inb(EISA_APROM)) << 8);
dev->dev_addr[i++] = (u_char) tmp;
}
if (k > 0xffff) k-=0xffff;
}
if (k == 0xffff) k=0;
if (lp->bus == PCI) {
if (lp->chipset == DC21040) {
while ((tmp = inl(DE4X5_APROM)) < 0);
chksum = (u_char) tmp;
while ((tmp = inl(DE4X5_APROM)) < 0);
chksum |= (u_short) (tmp << 8);
if ((k != chksum) && (dec_only)) status = -1;
}
} else {
chksum = (u_char) inb(EISA_APROM);
chksum |= (u_short) (inb(EISA_APROM) << 8);
if ((k != chksum) && (dec_only)) status = -1;
}
srom_repair(dev, broken);
#ifdef CONFIG_PPC_PMAC
if ( machine_is(powermac) &&
(dev->dev_addr[0] == 0) &&
(dev->dev_addr[1] == 0xa0) )
{
for (i = 0; i < ETH_ALEN; ++i)
{
int x = dev->dev_addr[i];
x = ((x & 0xf) << 4) + ((x & 0xf0) >> 4);
x = ((x & 0x33) << 2) + ((x & 0xcc) >> 2);
dev->dev_addr[i] = ((x & 0x55) << 1) + ((x & 0xaa) >> 1);
}
}
#endif
status = test_bad_enet(dev, status);
return status;
}
static int
de4x5_bad_srom(struct de4x5_private *lp)
{
int i, status = 0;
for (i = 0; i < ARRAY_SIZE(enet_det); i++) {
if (!de4x5_strncmp((char *)&lp->srom, (char *)&enet_det[i], 3) &&
!de4x5_strncmp((char *)&lp->srom+0x10, (char *)&enet_det[i], 3)) {
if (i == 0) {
status = SMC;
} else if (i == 1) {
status = ACCTON;
}
break;
}
}
return status;
}
static int
de4x5_strncmp(char *a, char *b, int n)
{
int ret=0;
for (;n && !ret; n--) {
ret = *a++ - *b++;
}
return ret;
}
static void
srom_repair(struct net_device *dev, int card)
{
struct de4x5_private *lp = netdev_priv(dev);
switch(card) {
case SMC:
memset((char *)&lp->srom, 0, sizeof(struct de4x5_srom));
memcpy(lp->srom.ieee_addr, (char *)dev->dev_addr, ETH_ALEN);
memcpy(lp->srom.info, (char *)&srom_repair_info[SMC-1], 100);
lp->useSROM = true;
break;
}
}
static int
test_bad_enet(struct net_device *dev, int status)
{
struct de4x5_private *lp = netdev_priv(dev);
int i, tmp;
for (tmp=0,i=0; i<ETH_ALEN; i++) tmp += (u_char)dev->dev_addr[i];
if ((tmp == 0) || (tmp == 0x5fa)) {
if ((lp->chipset == last.chipset) &&
(lp->bus_num == last.bus) && (lp->bus_num > 0)) {
for (i=0; i<ETH_ALEN; i++) dev->dev_addr[i] = last.addr[i];
for (i=ETH_ALEN-1; i>2; --i) {
dev->dev_addr[i] += 1;
if (dev->dev_addr[i] != 0) break;
}
for (i=0; i<ETH_ALEN; i++) last.addr[i] = dev->dev_addr[i];
if (!an_exception(lp)) {
dev->irq = last.irq;
}
status = 0;
}
} else if (!status) {
last.chipset = lp->chipset;
last.bus = lp->bus_num;
last.irq = dev->irq;
for (i=0; i<ETH_ALEN; i++) last.addr[i] = dev->dev_addr[i];
}
return status;
}
static int
an_exception(struct de4x5_private *lp)
{
if ((*(u_short *)lp->srom.sub_vendor_id == 0x00c0) &&
(*(u_short *)lp->srom.sub_system_id == 0x95e0)) {
return -1;
}
return 0;
}
static short
srom_rd(u_long addr, u_char offset)
{
sendto_srom(SROM_RD | SROM_SR, addr);
srom_latch(SROM_RD | SROM_SR | DT_CS, addr);
srom_command(SROM_RD | SROM_SR | DT_IN | DT_CS, addr);
srom_address(SROM_RD | SROM_SR | DT_CS, addr, offset);
return srom_data(SROM_RD | SROM_SR | DT_CS, addr);
}
static void
srom_latch(u_int command, u_long addr)
{
sendto_srom(command, addr);
sendto_srom(command | DT_CLK, addr);
sendto_srom(command, addr);
}
static void
srom_command(u_int command, u_long addr)
{
srom_latch(command, addr);
srom_latch(command, addr);
srom_latch((command & 0x0000ff00) | DT_CS, addr);
}
static void
srom_address(u_int command, u_long addr, u_char offset)
{
int i, a;
a = offset << 2;
for (i=0; i<6; i++, a <<= 1) {
srom_latch(command | ((a & 0x80) ? DT_IN : 0), addr);
}
udelay(1);
i = (getfrom_srom(addr) >> 3) & 0x01;
}
static short
srom_data(u_int command, u_long addr)
{
int i;
short word = 0;
s32 tmp;
for (i=0; i<16; i++) {
sendto_srom(command | DT_CLK, addr);
tmp = getfrom_srom(addr);
sendto_srom(command, addr);
word = (word << 1) | ((tmp >> 3) & 0x01);
}
sendto_srom(command & 0x0000ff00, addr);
return word;
}
static void
sendto_srom(u_int command, u_long addr)
{
outl(command, addr);
udelay(1);
}
static int
getfrom_srom(u_long addr)
{
s32 tmp;
tmp = inl(addr);
udelay(1);
return tmp;
}
static int
srom_infoleaf_info(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int i, count;
u_char *p;
for (i=0; i<INFOLEAF_SIZE; i++) {
if (lp->chipset == infoleaf_array[i].chipset) break;
}
if (i == INFOLEAF_SIZE) {
lp->useSROM = false;
printk("%s: Cannot find correct chipset for SROM decoding!\n",
dev->name);
return -ENXIO;
}
lp->infoleaf_fn = infoleaf_array[i].fn;
count = *((u_char *)&lp->srom + 19);
p = (u_char *)&lp->srom + 26;
if (count > 1) {
for (i=count; i; --i, p+=3) {
if (lp->device == *p) break;
}
if (i == 0) {
lp->useSROM = false;
printk("%s: Cannot find correct PCI device [%d] for SROM decoding!\n",
dev->name, lp->device);
return -ENXIO;
}
}
lp->infoleaf_offset = get_unaligned_le16(p + 1);
return 0;
}
static void
srom_init(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char *p = (u_char *)&lp->srom + lp->infoleaf_offset;
u_char count;
p+=2;
if (lp->chipset == DC21140) {
lp->cache.gepc = (*p++ | GEP_CTRL);
gep_wr(lp->cache.gepc, dev);
}
count = *p++;
for (;count; --count) {
if (*p < 128) {
p += COMPACT_LEN;
} else if (*(p+1) == 5) {
type5_infoblock(dev, 1, p);
p += ((*p & BLOCK_LEN) + 1);
} else if (*(p+1) == 4) {
p += ((*p & BLOCK_LEN) + 1);
} else if (*(p+1) == 3) {
type3_infoblock(dev, 1, p);
p += ((*p & BLOCK_LEN) + 1);
} else if (*(p+1) == 2) {
p += ((*p & BLOCK_LEN) + 1);
} else if (*(p+1) == 1) {
type1_infoblock(dev, 1, p);
p += ((*p & BLOCK_LEN) + 1);
} else {
p += ((*p & BLOCK_LEN) + 1);
}
}
}
static void
srom_exec(struct net_device *dev, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
u_char count = (p ? *p++ : 0);
u_short *w = (u_short *)p;
if (((lp->ibn != 1) && (lp->ibn != 3) && (lp->ibn != 5)) || !count) return;
if (lp->chipset != DC21140) RESET_SIA;
while (count--) {
gep_wr(((lp->chipset==DC21140) && (lp->ibn!=5) ?
*p++ : get_unaligned_le16(w++)), dev);
mdelay(2);
}
if (lp->chipset != DC21140) {
outl(lp->cache.csr14, DE4X5_STRR);
outl(lp->cache.csr13, DE4X5_SICR);
}
}
static int
dc21041_infoleaf(struct net_device *dev)
{
return DE4X5_AUTOSENSE_MS;
}
static int
dc21140_infoleaf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char count = 0;
u_char *p = (u_char *)&lp->srom + lp->infoleaf_offset;
int next_tick = DE4X5_AUTOSENSE_MS;
p+=2;
lp->cache.gepc = (*p++ | GEP_CTRL);
count = *p++;
if (*p < 128) {
next_tick = dc_infoblock[COMPACT](dev, count, p);
} else {
next_tick = dc_infoblock[*(p+1)](dev, count, p);
}
if (lp->tcount == count) {
lp->media = NC;
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tcount = 0;
lp->tx_enable = false;
}
return next_tick & ~TIMER_CB;
}
static int
dc21142_infoleaf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char count = 0;
u_char *p = (u_char *)&lp->srom + lp->infoleaf_offset;
int next_tick = DE4X5_AUTOSENSE_MS;
p+=2;
count = *p++;
if (*p < 128) {
next_tick = dc_infoblock[COMPACT](dev, count, p);
} else {
next_tick = dc_infoblock[*(p+1)](dev, count, p);
}
if (lp->tcount == count) {
lp->media = NC;
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tcount = 0;
lp->tx_enable = false;
}
return next_tick & ~TIMER_CB;
}
static int
dc21143_infoleaf(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char count = 0;
u_char *p = (u_char *)&lp->srom + lp->infoleaf_offset;
int next_tick = DE4X5_AUTOSENSE_MS;
p+=2;
count = *p++;
if (*p < 128) {
next_tick = dc_infoblock[COMPACT](dev, count, p);
} else {
next_tick = dc_infoblock[*(p+1)](dev, count, p);
}
if (lp->tcount == count) {
lp->media = NC;
if (lp->media != lp->c_media) {
de4x5_dbg_media(dev);
lp->c_media = lp->media;
}
lp->media = INIT;
lp->tcount = 0;
lp->tx_enable = false;
}
return next_tick & ~TIMER_CB;
}
static int
compact_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char flags, csr6;
if (--count > lp->tcount) {
if (*(p+COMPACT_LEN) < 128) {
return dc_infoblock[COMPACT](dev, count, p+COMPACT_LEN);
} else {
return dc_infoblock[*(p+COMPACT_LEN+1)](dev, count, p+COMPACT_LEN);
}
}
if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = COMPACT;
lp->active = 0;
gep_wr(lp->cache.gepc, dev);
lp->infoblock_media = (*p++) & COMPACT_MC;
lp->cache.gep = *p++;
csr6 = *p++;
flags = *p++;
lp->asBitValid = (flags & 0x80) ? 0 : -1;
lp->defMedium = (flags & 0x40) ? -1 : 0;
lp->asBit = 1 << ((csr6 >> 1) & 0x07);
lp->asPolarity = ((csr6 & 0x80) ? -1 : 0) & lp->asBit;
lp->infoblock_csr6 = OMR_DEF | ((csr6 & 0x71) << 18);
lp->useMII = false;
de4x5_switch_mac_port(dev);
}
return dc21140m_autoconf(dev);
}
static int
type0_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char flags, csr6, len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = 0;
lp->active = 0;
gep_wr(lp->cache.gepc, dev);
p+=2;
lp->infoblock_media = (*p++) & BLOCK0_MC;
lp->cache.gep = *p++;
csr6 = *p++;
flags = *p++;
lp->asBitValid = (flags & 0x80) ? 0 : -1;
lp->defMedium = (flags & 0x40) ? -1 : 0;
lp->asBit = 1 << ((csr6 >> 1) & 0x07);
lp->asPolarity = ((csr6 & 0x80) ? -1 : 0) & lp->asBit;
lp->infoblock_csr6 = OMR_DEF | ((csr6 & 0x71) << 18);
lp->useMII = false;
de4x5_switch_mac_port(dev);
}
return dc21140m_autoconf(dev);
}
static int
type1_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
p += 2;
if (lp->state == INITIALISED) {
lp->ibn = 1;
lp->active = *p++;
lp->phy[lp->active].gep = (*p ? p : NULL); p += (*p + 1);
lp->phy[lp->active].rst = (*p ? p : NULL); p += (*p + 1);
lp->phy[lp->active].mc = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].ana = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].fdx = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].ttm = get_unaligned_le16(p);
return 0;
} else if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = 1;
lp->active = *p;
lp->infoblock_csr6 = OMR_MII_100;
lp->useMII = true;
lp->infoblock_media = ANS;
de4x5_switch_mac_port(dev);
}
return dc21140m_autoconf(dev);
}
static int
type2_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = 2;
lp->active = 0;
p += 2;
lp->infoblock_media = (*p) & MEDIA_CODE;
if ((*p++) & EXT_FIELD) {
lp->cache.csr13 = get_unaligned_le16(p); p += 2;
lp->cache.csr14 = get_unaligned_le16(p); p += 2;
lp->cache.csr15 = get_unaligned_le16(p); p += 2;
} else {
lp->cache.csr13 = CSR13;
lp->cache.csr14 = CSR14;
lp->cache.csr15 = CSR15;
}
lp->cache.gepc = ((s32)(get_unaligned_le16(p)) << 16); p += 2;
lp->cache.gep = ((s32)(get_unaligned_le16(p)) << 16);
lp->infoblock_csr6 = OMR_SIA;
lp->useMII = false;
de4x5_switch_mac_port(dev);
}
return dc2114x_autoconf(dev);
}
static int
type3_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
p += 2;
if (lp->state == INITIALISED) {
lp->ibn = 3;
lp->active = *p++;
if (MOTO_SROM_BUG) lp->active = 0;
lp->phy[lp->active].gep = (*p ? p : NULL); p += (2 * (*p) + 1);
lp->phy[lp->active].rst = (*p ? p : NULL); p += (2 * (*p) + 1);
lp->phy[lp->active].mc = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].ana = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].fdx = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].ttm = get_unaligned_le16(p); p += 2;
lp->phy[lp->active].mci = *p;
return 0;
} else if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = 3;
lp->active = *p;
if (MOTO_SROM_BUG) lp->active = 0;
lp->infoblock_csr6 = OMR_MII_100;
lp->useMII = true;
lp->infoblock_media = ANS;
de4x5_switch_mac_port(dev);
}
return dc2114x_autoconf(dev);
}
static int
type4_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char flags, csr6, len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
if ((lp->media == INIT) && (lp->timeout < 0)) {
lp->ibn = 4;
lp->active = 0;
p+=2;
lp->infoblock_media = (*p++) & MEDIA_CODE;
lp->cache.csr13 = CSR13;
lp->cache.csr14 = CSR14;
lp->cache.csr15 = CSR15;
lp->cache.gepc = ((s32)(get_unaligned_le16(p)) << 16); p += 2;
lp->cache.gep = ((s32)(get_unaligned_le16(p)) << 16); p += 2;
csr6 = *p++;
flags = *p++;
lp->asBitValid = (flags & 0x80) ? 0 : -1;
lp->defMedium = (flags & 0x40) ? -1 : 0;
lp->asBit = 1 << ((csr6 >> 1) & 0x07);
lp->asPolarity = ((csr6 & 0x80) ? -1 : 0) & lp->asBit;
lp->infoblock_csr6 = OMR_DEF | ((csr6 & 0x71) << 18);
lp->useMII = false;
de4x5_switch_mac_port(dev);
}
return dc2114x_autoconf(dev);
}
static int
type5_infoblock(struct net_device *dev, u_char count, u_char *p)
{
struct de4x5_private *lp = netdev_priv(dev);
u_char len = (*p & BLOCK_LEN)+1;
if (--count > lp->tcount) {
if (*(p+len) < 128) {
return dc_infoblock[COMPACT](dev, count, p+len);
} else {
return dc_infoblock[*(p+len+1)](dev, count, p+len);
}
}
if ((lp->state == INITIALISED) || (lp->media == INIT)) {
p+=2;
lp->rst = p;
srom_exec(dev, lp->rst);
}
return DE4X5_AUTOSENSE_MS;
}
static int
mii_rd(u_char phyreg, u_char phyaddr, u_long ioaddr)
{
mii_wdata(MII_PREAMBLE, 2, ioaddr);
mii_wdata(MII_PREAMBLE, 32, ioaddr);
mii_wdata(MII_STRD, 4, ioaddr);
mii_address(phyaddr, ioaddr);
mii_address(phyreg, ioaddr);
mii_ta(MII_STRD, ioaddr);
return mii_rdata(ioaddr);
}
static void
mii_wr(int data, u_char phyreg, u_char phyaddr, u_long ioaddr)
{
mii_wdata(MII_PREAMBLE, 2, ioaddr);
mii_wdata(MII_PREAMBLE, 32, ioaddr);
mii_wdata(MII_STWR, 4, ioaddr);
mii_address(phyaddr, ioaddr);
mii_address(phyreg, ioaddr);
mii_ta(MII_STWR, ioaddr);
data = mii_swap(data, 16);
mii_wdata(data, 16, ioaddr);
}
static int
mii_rdata(u_long ioaddr)
{
int i;
s32 tmp = 0;
for (i=0; i<16; i++) {
tmp <<= 1;
tmp |= getfrom_mii(MII_MRD | MII_RD, ioaddr);
}
return tmp;
}
static void
mii_wdata(int data, int len, u_long ioaddr)
{
int i;
for (i=0; i<len; i++) {
sendto_mii(MII_MWR | MII_WR, data, ioaddr);
data >>= 1;
}
}
static void
mii_address(u_char addr, u_long ioaddr)
{
int i;
addr = mii_swap(addr, 5);
for (i=0; i<5; i++) {
sendto_mii(MII_MWR | MII_WR, addr, ioaddr);
addr >>= 1;
}
}
static void
mii_ta(u_long rw, u_long ioaddr)
{
if (rw == MII_STWR) {
sendto_mii(MII_MWR | MII_WR, 1, ioaddr);
sendto_mii(MII_MWR | MII_WR, 0, ioaddr);
} else {
getfrom_mii(MII_MRD | MII_RD, ioaddr);
}
}
static int
mii_swap(int data, int len)
{
int i, tmp = 0;
for (i=0; i<len; i++) {
tmp <<= 1;
tmp |= (data & 1);
data >>= 1;
}
return tmp;
}
static void
sendto_mii(u32 command, int data, u_long ioaddr)
{
u32 j;
j = (data & 1) << 17;
outl(command | j, ioaddr);
udelay(1);
outl(command | MII_MDC | j, ioaddr);
udelay(1);
}
static int
getfrom_mii(u32 command, u_long ioaddr)
{
outl(command, ioaddr);
udelay(1);
outl(command | MII_MDC, ioaddr);
udelay(1);
return (inl(ioaddr) >> 19) & 1;
}
static int
mii_get_oui(u_char phyaddr, u_long ioaddr)
{
int r2, r3;
r2 = mii_rd(MII_ID0, phyaddr, ioaddr);
r3 = mii_rd(MII_ID1, phyaddr, ioaddr);
return r2;
}
static int
mii_get_phy(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
int i, j, k, n, limit=ARRAY_SIZE(phy_info);
int id;
lp->active = 0;
lp->useMII = true;
for (n=0, lp->mii_cnt=0, i=1; !((i==1) && (n==1)); i=(i+1)%DE4X5_MAX_MII) {
lp->phy[lp->active].addr = i;
if (i==0) n++;
while (de4x5_reset_phy(dev)<0) udelay(100);
id = mii_get_oui(i, DE4X5_MII);
if ((id == 0) || (id == 65535)) continue;
for (j=0; j<limit; j++) {
if (id != phy_info[j].id) continue;
for (k=0; k < DE4X5_MAX_PHY && lp->phy[k].id; k++);
if (k < DE4X5_MAX_PHY) {
memcpy((char *)&lp->phy[k],
(char *)&phy_info[j], sizeof(struct phy_table));
lp->phy[k].addr = i;
lp->mii_cnt++;
lp->active++;
} else {
goto purgatory;
}
break;
}
if ((j == limit) && (i < DE4X5_MAX_MII)) {
for (k=0; k < DE4X5_MAX_PHY && lp->phy[k].id; k++);
lp->phy[k].addr = i;
lp->phy[k].id = id;
lp->phy[k].spd.reg = GENERIC_REG;
lp->phy[k].spd.mask = GENERIC_MASK;
lp->phy[k].spd.value = GENERIC_VALUE;
lp->mii_cnt++;
lp->active++;
printk("%s: Using generic MII device control. If the board doesn't operate,\nplease mail the following dump to the author:\n", dev->name);
j = de4x5_debug;
de4x5_debug |= DEBUG_MII;
de4x5_dbg_mii(dev, k);
de4x5_debug = j;
printk("\n");
}
}
purgatory:
lp->active = 0;
if (lp->phy[0].id) {
for (k=0; k < DE4X5_MAX_PHY && lp->phy[k].id; k++) {
mii_wr(MII_CR_RST, MII_CR, lp->phy[k].addr, DE4X5_MII);
while (mii_rd(MII_CR, lp->phy[k].addr, DE4X5_MII) & MII_CR_RST);
de4x5_dbg_mii(dev, k);
}
}
if (!lp->mii_cnt) lp->useMII = false;
return lp->mii_cnt;
}
static char *
build_setup_frame(struct net_device *dev, int mode)
{
struct de4x5_private *lp = netdev_priv(dev);
int i;
char *pa = lp->setup_frame;
if (mode == ALL) {
memset(lp->setup_frame, 0, SETUP_FRAME_LEN);
}
if (lp->setup_f == HASH_PERF) {
for (pa=lp->setup_frame+IMPERF_PA_OFFSET, i=0; i<ETH_ALEN; i++) {
*(pa + i) = dev->dev_addr[i];
if (i & 0x01) pa += 2;
}
*(lp->setup_frame + (HASH_TABLE_LEN >> 3) - 3) = 0x80;
} else {
for (i=0; i<ETH_ALEN; i++) {
*(pa + (i&1)) = dev->dev_addr[i];
if (i & 0x01) pa += 4;
}
for (i=0; i<ETH_ALEN; i++) {
*(pa + (i&1)) = (char) 0xff;
if (i & 0x01) pa += 4;
}
}
return pa;
}
static void
disable_ast(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
del_timer_sync(&lp->timer);
}
static long
de4x5_switch_mac_port(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
s32 omr;
STOP_DE4X5;
omr = (inl(DE4X5_OMR) & ~(OMR_PS | OMR_HBD | OMR_TTM | OMR_PCS | OMR_SCR |
OMR_FDX));
omr |= lp->infoblock_csr6;
if (omr & OMR_PS) omr |= OMR_HBD;
outl(omr, DE4X5_OMR);
RESET_DE4X5;
if (lp->chipset == DC21140) {
gep_wr(lp->cache.gepc, dev);
gep_wr(lp->cache.gep, dev);
} else if ((lp->chipset & ~0x0ff) == DC2114x) {
reset_init_sia(dev, lp->cache.csr13, lp->cache.csr14, lp->cache.csr15);
}
outl(omr, DE4X5_OMR);
inl(DE4X5_MFC);
return omr;
}
static void
gep_wr(s32 data, struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->chipset == DC21140) {
outl(data, DE4X5_GEP);
} else if ((lp->chipset & ~0x00ff) == DC2114x) {
outl((data<<16) | lp->cache.csr15, DE4X5_SIGR);
}
}
static int
gep_rd(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (lp->chipset == DC21140) {
return inl(DE4X5_GEP);
} else if ((lp->chipset & ~0x00ff) == DC2114x) {
return inl(DE4X5_SIGR) & 0x000fffff;
}
return 0;
}
static void
yawn(struct net_device *dev, int state)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if ((lp->chipset == DC21040) || (lp->chipset == DC21140)) return;
if(lp->bus == EISA) {
switch(state) {
case WAKEUP:
outb(WAKEUP, PCI_CFPM);
mdelay(10);
break;
case SNOOZE:
outb(SNOOZE, PCI_CFPM);
break;
case SLEEP:
outl(0, DE4X5_SICR);
outb(SLEEP, PCI_CFPM);
break;
}
} else {
struct pci_dev *pdev = to_pci_dev (lp->gendev);
switch(state) {
case WAKEUP:
pci_write_config_byte(pdev, PCI_CFDA_PSM, WAKEUP);
mdelay(10);
break;
case SNOOZE:
pci_write_config_byte(pdev, PCI_CFDA_PSM, SNOOZE);
break;
case SLEEP:
outl(0, DE4X5_SICR);
pci_write_config_byte(pdev, PCI_CFDA_PSM, SLEEP);
break;
}
}
}
static void
de4x5_parse_params(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
char *p, *q, t;
lp->params.fdx = false;
lp->params.autosense = AUTO;
if (args == NULL) return;
if ((p = strstr(args, dev->name))) {
if (!(q = strstr(p+strlen(dev->name), "eth"))) q = p + strlen(p);
t = *q;
*q = '\0';
if (strstr(p, "fdx") || strstr(p, "FDX")) lp->params.fdx = true;
if (strstr(p, "autosense") || strstr(p, "AUTOSENSE")) {
if (strstr(p, "TP")) {
lp->params.autosense = TP;
} else if (strstr(p, "TP_NW")) {
lp->params.autosense = TP_NW;
} else if (strstr(p, "BNC")) {
lp->params.autosense = BNC;
} else if (strstr(p, "AUI")) {
lp->params.autosense = AUI;
} else if (strstr(p, "BNC_AUI")) {
lp->params.autosense = BNC;
} else if (strstr(p, "10Mb")) {
lp->params.autosense = _10Mb;
} else if (strstr(p, "100Mb")) {
lp->params.autosense = _100Mb;
} else if (strstr(p, "AUTO")) {
lp->params.autosense = AUTO;
}
}
*q = t;
}
}
static void
de4x5_dbg_open(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
int i;
if (de4x5_debug & DEBUG_OPEN) {
printk("%s: de4x5 opening with irq %d\n",dev->name,dev->irq);
printk("\tphysical address: %pM\n", dev->dev_addr);
printk("Descriptor head addresses:\n");
printk("\t0x%8.8lx 0x%8.8lx\n",(u_long)lp->rx_ring,(u_long)lp->tx_ring);
printk("Descriptor addresses:\nRX: ");
for (i=0;i<lp->rxRingSize-1;i++){
if (i < 3) {
printk("0x%8.8lx ",(u_long)&lp->rx_ring[i].status);
}
}
printk("...0x%8.8lx\n",(u_long)&lp->rx_ring[i].status);
printk("TX: ");
for (i=0;i<lp->txRingSize-1;i++){
if (i < 3) {
printk("0x%8.8lx ", (u_long)&lp->tx_ring[i].status);
}
}
printk("...0x%8.8lx\n", (u_long)&lp->tx_ring[i].status);
printk("Descriptor buffers:\nRX: ");
for (i=0;i<lp->rxRingSize-1;i++){
if (i < 3) {
printk("0x%8.8x ",le32_to_cpu(lp->rx_ring[i].buf));
}
}
printk("...0x%8.8x\n",le32_to_cpu(lp->rx_ring[i].buf));
printk("TX: ");
for (i=0;i<lp->txRingSize-1;i++){
if (i < 3) {
printk("0x%8.8x ", le32_to_cpu(lp->tx_ring[i].buf));
}
}
printk("...0x%8.8x\n", le32_to_cpu(lp->tx_ring[i].buf));
printk("Ring size:\nRX: %d\nTX: %d\n",
(short)lp->rxRingSize,
(short)lp->txRingSize);
}
}
static void
de4x5_dbg_mii(struct net_device *dev, int k)
{
struct de4x5_private *lp = netdev_priv(dev);
u_long iobase = dev->base_addr;
if (de4x5_debug & DEBUG_MII) {
printk("\nMII device address: %d\n", lp->phy[k].addr);
printk("MII CR: %x\n",mii_rd(MII_CR,lp->phy[k].addr,DE4X5_MII));
printk("MII SR: %x\n",mii_rd(MII_SR,lp->phy[k].addr,DE4X5_MII));
printk("MII ID0: %x\n",mii_rd(MII_ID0,lp->phy[k].addr,DE4X5_MII));
printk("MII ID1: %x\n",mii_rd(MII_ID1,lp->phy[k].addr,DE4X5_MII));
if (lp->phy[k].id != BROADCOM_T4) {
printk("MII ANA: %x\n",mii_rd(0x04,lp->phy[k].addr,DE4X5_MII));
printk("MII ANC: %x\n",mii_rd(0x05,lp->phy[k].addr,DE4X5_MII));
}
printk("MII 16: %x\n",mii_rd(0x10,lp->phy[k].addr,DE4X5_MII));
if (lp->phy[k].id != BROADCOM_T4) {
printk("MII 17: %x\n",mii_rd(0x11,lp->phy[k].addr,DE4X5_MII));
printk("MII 18: %x\n",mii_rd(0x12,lp->phy[k].addr,DE4X5_MII));
} else {
printk("MII 20: %x\n",mii_rd(0x14,lp->phy[k].addr,DE4X5_MII));
}
}
}
static void
de4x5_dbg_media(struct net_device *dev)
{
struct de4x5_private *lp = netdev_priv(dev);
if (lp->media != lp->c_media) {
if (de4x5_debug & DEBUG_MEDIA) {
printk("%s: media is %s%s\n", dev->name,
(lp->media == NC ? "unconnected, link down or incompatible connection" :
(lp->media == TP ? "TP" :
(lp->media == ANS ? "TP/Nway" :
(lp->media == BNC ? "BNC" :
(lp->media == AUI ? "AUI" :
(lp->media == BNC_AUI ? "BNC/AUI" :
(lp->media == EXT_SIA ? "EXT SIA" :
(lp->media == _100Mb ? "100Mb/s" :
(lp->media == _10Mb ? "10Mb/s" :
"???"
))))))))), (lp->fdx?" full duplex.":"."));
}
lp->c_media = lp->media;
}
}
static void
de4x5_dbg_srom(struct de4x5_srom *p)
{
int i;
if (de4x5_debug & DEBUG_SROM) {
printk("Sub-system Vendor ID: %04x\n", *((u_short *)p->sub_vendor_id));
printk("Sub-system ID: %04x\n", *((u_short *)p->sub_system_id));
printk("ID Block CRC: %02x\n", (u_char)(p->id_block_crc));
printk("SROM version: %02x\n", (u_char)(p->version));
printk("# controllers: %02x\n", (u_char)(p->num_controllers));
printk("Hardware Address: %pM\n", p->ieee_addr);
printk("CRC checksum: %04x\n", (u_short)(p->chksum));
for (i=0; i<64; i++) {
printk("%3d %04x\n", i<<1, (u_short)*((u_short *)p+i));
}
}
}
static void
de4x5_dbg_rx(struct sk_buff *skb, int len)
{
int i, j;
if (de4x5_debug & DEBUG_RX) {
printk("R: %pM <- %pM len/SAP:%02x%02x [%d]\n",
skb->data, &skb->data[6],
(u_char)skb->data[12],
(u_char)skb->data[13],
len);
for (j=0; len>0;j+=16, len-=16) {
printk(" %03x: ",j);
for (i=0; i<16 && i<len; i++) {
printk("%02x ",(u_char)skb->data[i+j]);
}
printk("\n");
}
}
}
static int
de4x5_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct de4x5_private *lp = netdev_priv(dev);
struct de4x5_ioctl *ioc = (struct de4x5_ioctl *) &rq->ifr_ifru;
u_long iobase = dev->base_addr;
int i, j, status = 0;
s32 omr;
union {
u8 addr[144];
u16 sval[72];
u32 lval[36];
} tmp;
u_long flags = 0;
switch(ioc->cmd) {
case DE4X5_GET_HWADDR:
ioc->len = ETH_ALEN;
for (i=0; i<ETH_ALEN; i++) {
tmp.addr[i] = dev->dev_addr[i];
}
if (copy_to_user(ioc->data, tmp.addr, ioc->len)) return -EFAULT;
break;
case DE4X5_SET_HWADDR:
if (!capable(CAP_NET_ADMIN)) return -EPERM;
if (copy_from_user(tmp.addr, ioc->data, ETH_ALEN)) return -EFAULT;
if (netif_queue_stopped(dev))
return -EBUSY;
netif_stop_queue(dev);
for (i=0; i<ETH_ALEN; i++) {
dev->dev_addr[i] = tmp.addr[i];
}
build_setup_frame(dev, PHYS_ADDR_ONLY);
load_packet(dev, lp->setup_frame, TD_IC | PERFECT_F | TD_SET |
SETUP_FRAME_LEN, (struct sk_buff *)1);
lp->tx_new = (lp->tx_new + 1) % lp->txRingSize;
outl(POLL_DEMAND, DE4X5_TPD);
netif_wake_queue(dev);
break;
case DE4X5_SAY_BOO:
if (!capable(CAP_NET_ADMIN)) return -EPERM;
printk("%s: Boo!\n", dev->name);
break;
case DE4X5_MCA_EN:
if (!capable(CAP_NET_ADMIN)) return -EPERM;
omr = inl(DE4X5_OMR);
omr |= OMR_PM;
outl(omr, DE4X5_OMR);
break;
case DE4X5_GET_STATS:
{
struct pkt_stats statbuf;
ioc->len = sizeof(statbuf);
spin_lock_irqsave(&lp->lock, flags);
memcpy(&statbuf, &lp->pktStats, ioc->len);
spin_unlock_irqrestore(&lp->lock, flags);
if (copy_to_user(ioc->data, &statbuf, ioc->len))
return -EFAULT;
break;
}
case DE4X5_CLR_STATS:
if (!capable(CAP_NET_ADMIN)) return -EPERM;
spin_lock_irqsave(&lp->lock, flags);
memset(&lp->pktStats, 0, sizeof(lp->pktStats));
spin_unlock_irqrestore(&lp->lock, flags);
break;
case DE4X5_GET_OMR:
tmp.addr[0] = inl(DE4X5_OMR);
if (copy_to_user(ioc->data, tmp.addr, 1)) return -EFAULT;
break;
case DE4X5_SET_OMR:
if (!capable(CAP_NET_ADMIN)) return -EPERM;
if (copy_from_user(tmp.addr, ioc->data, 1)) return -EFAULT;
outl(tmp.addr[0], DE4X5_OMR);
break;
case DE4X5_GET_REG:
j = 0;
tmp.lval[0] = inl(DE4X5_STS); j+=4;
tmp.lval[1] = inl(DE4X5_BMR); j+=4;
tmp.lval[2] = inl(DE4X5_IMR); j+=4;
tmp.lval[3] = inl(DE4X5_OMR); j+=4;
tmp.lval[4] = inl(DE4X5_SISR); j+=4;
tmp.lval[5] = inl(DE4X5_SICR); j+=4;
tmp.lval[6] = inl(DE4X5_STRR); j+=4;
tmp.lval[7] = inl(DE4X5_SIGR); j+=4;
ioc->len = j;
if (copy_to_user(ioc->data, tmp.lval, ioc->len))
return -EFAULT;
break;
#define DE4X5_DUMP 0x0f
default:
return -EOPNOTSUPP;
}
return status;
}
static int __init de4x5_module_init (void)
{
int err = 0;
#ifdef CONFIG_PCI
err = pci_register_driver(&de4x5_pci_driver);
#endif
#ifdef CONFIG_EISA
err |= eisa_driver_register (&de4x5_eisa_driver);
#endif
return err;
}
static void __exit de4x5_module_exit (void)
{
#ifdef CONFIG_PCI
pci_unregister_driver (&de4x5_pci_driver);
#endif
#ifdef CONFIG_EISA
eisa_driver_unregister (&de4x5_eisa_driver);
#endif
}
