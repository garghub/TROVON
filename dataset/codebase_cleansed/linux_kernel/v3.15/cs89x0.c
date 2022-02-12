static int __init dma_fn(char *str)
{
g_cs89x0_dma = simple_strtol(str, NULL, 0);
return 1;
}
static int __init media_fn(char *str)
{
if (!strcmp(str, "rj45"))
g_cs89x0_media__force = FORCE_RJ45;
else if (!strcmp(str, "aui"))
g_cs89x0_media__force = FORCE_AUI;
else if (!strcmp(str, "bnc"))
g_cs89x0_media__force = FORCE_BNC;
return 1;
}
static void readwords(struct net_local *lp, int portno, void *buf, int length)
{
u8 *buf8 = (u8 *)buf;
do {
u16 tmp16;
tmp16 = ioread16(lp->virt_addr + portno);
*buf8++ = (u8)tmp16;
*buf8++ = (u8)(tmp16 >> 8);
} while (--length);
}
static void writewords(struct net_local *lp, int portno, void *buf, int length)
{
u8 *buf8 = (u8 *)buf;
do {
u16 tmp16;
tmp16 = *buf8++;
tmp16 |= (*buf8++) << 8;
iowrite16(tmp16, lp->virt_addr + portno);
} while (--length);
}
static u16
readreg(struct net_device *dev, u16 regno)
{
struct net_local *lp = netdev_priv(dev);
iowrite16(regno, lp->virt_addr + ADD_PORT);
return ioread16(lp->virt_addr + DATA_PORT);
}
static void
writereg(struct net_device *dev, u16 regno, u16 value)
{
struct net_local *lp = netdev_priv(dev);
iowrite16(regno, lp->virt_addr + ADD_PORT);
iowrite16(value, lp->virt_addr + DATA_PORT);
}
static int __init
wait_eeprom_ready(struct net_device *dev)
{
int timeout = jiffies;
while (readreg(dev, PP_SelfST) & SI_BUSY)
if (jiffies - timeout >= 40)
return -1;
return 0;
}
static int __init
get_eeprom_data(struct net_device *dev, int off, int len, int *buffer)
{
int i;
cs89_dbg(3, info, "EEPROM data from %x for %x:", off, len);
for (i = 0; i < len; i++) {
if (wait_eeprom_ready(dev) < 0)
return -1;
writereg(dev, PP_EECMD, (off + i) | EEPROM_READ_CMD);
if (wait_eeprom_ready(dev) < 0)
return -1;
buffer[i] = readreg(dev, PP_EEData);
cs89_dbg(3, cont, " %04x", buffer[i]);
}
cs89_dbg(3, cont, "\n");
return 0;
}
static int __init
get_eeprom_cksum(int off, int len, int *buffer)
{
int i, cksum;
cksum = 0;
for (i = 0; i < len; i++)
cksum += buffer[i];
cksum &= 0xffff;
if (cksum == 0)
return 0;
return -1;
}
static void
write_irq(struct net_device *dev, int chip_type, int irq)
{
int i;
if (chip_type == CS8900) {
#ifndef CONFIG_CS89x0_PLATFORM
for (i = 0; i != ARRAY_SIZE(cs8900_irq_map); i++)
if (cs8900_irq_map[i] == irq)
break;
if (i == ARRAY_SIZE(cs8900_irq_map))
i = 3;
#else
i = 0;
#endif
writereg(dev, PP_CS8900_ISAINT, i);
} else {
writereg(dev, PP_CS8920_ISAINT, irq);
}
}
static void
count_rx_errors(int status, struct net_device *dev)
{
dev->stats.rx_errors++;
if (status & RX_RUNT)
dev->stats.rx_length_errors++;
if (status & RX_EXTRA_DATA)
dev->stats.rx_length_errors++;
if ((status & RX_CRC_ERROR) && !(status & (RX_EXTRA_DATA | RX_RUNT)))
dev->stats.rx_crc_errors++;
if (status & RX_DRIBBLE)
dev->stats.rx_frame_errors++;
}
static void
get_dma_channel(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
if (lp->dma) {
dev->dma = lp->dma;
lp->isa_config |= ISA_RxDMA;
} else {
if ((lp->isa_config & ANY_ISA_DMA) == 0)
return;
dev->dma = lp->isa_config & DMA_NO_MASK;
if (lp->chip_type == CS8900)
dev->dma += 5;
if (dev->dma < 5 || dev->dma > 7) {
lp->isa_config &= ~ANY_ISA_DMA;
return;
}
}
}
static void
write_dma(struct net_device *dev, int chip_type, int dma)
{
struct net_local *lp = netdev_priv(dev);
if ((lp->isa_config & ANY_ISA_DMA) == 0)
return;
if (chip_type == CS8900)
writereg(dev, PP_CS8900_ISADMA, dma - 5);
else
writereg(dev, PP_CS8920_ISADMA, dma);
}
static void
set_dma_cfg(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
if (lp->use_dma) {
if ((lp->isa_config & ANY_ISA_DMA) == 0) {
cs89_dbg(3, err, "set_dma_cfg(): no DMA\n");
return;
}
if (lp->isa_config & ISA_RxDMA) {
lp->curr_rx_cfg |= RX_DMA_ONLY;
cs89_dbg(3, info, "set_dma_cfg(): RX_DMA_ONLY\n");
} else {
lp->curr_rx_cfg |= AUTO_RX_DMA;
cs89_dbg(3, info, "set_dma_cfg(): AUTO_RX_DMA\n");
}
}
}
static int
dma_bufcfg(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
if (lp->use_dma)
return (lp->isa_config & ANY_ISA_DMA) ? RX_DMA_ENBL : 0;
else
return 0;
}
static int
dma_busctl(struct net_device *dev)
{
int retval = 0;
struct net_local *lp = netdev_priv(dev);
if (lp->use_dma) {
if (lp->isa_config & ANY_ISA_DMA)
retval |= RESET_RX_DMA;
if (lp->isa_config & DMA_BURST)
retval |= DMA_BURST_MODE;
if (lp->dmasize == 64)
retval |= RX_DMA_SIZE_64K;
retval |= MEMORY_ON;
}
return retval;
}
static void
dma_rx(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
struct sk_buff *skb;
int status, length;
unsigned char *bp = lp->rx_dma_ptr;
status = bp[0] + (bp[1] << 8);
length = bp[2] + (bp[3] << 8);
bp += 4;
cs89_dbg(5, debug, "%s: receiving DMA packet at %lx, status %x, length %x\n",
dev->name, (unsigned long)bp, status, length);
if ((status & RX_OK) == 0) {
count_rx_errors(status, dev);
goto skip_this_frame;
}
skb = netdev_alloc_skb(dev, length + 2);
if (skb == NULL) {
dev->stats.rx_dropped++;
skip_this_frame:
bp += (length + 3) & ~3;
if (bp >= lp->end_dma_buff)
bp -= lp->dmasize * 1024;
lp->rx_dma_ptr = bp;
return;
}
skb_reserve(skb, 2);
if (bp + length > lp->end_dma_buff) {
int semi_cnt = lp->end_dma_buff - bp;
memcpy(skb_put(skb, semi_cnt), bp, semi_cnt);
memcpy(skb_put(skb, length - semi_cnt), lp->dma_buff,
length - semi_cnt);
} else {
memcpy(skb_put(skb, length), bp, length);
}
bp += (length + 3) & ~3;
if (bp >= lp->end_dma_buff)
bp -= lp->dmasize*1024;
lp->rx_dma_ptr = bp;
cs89_dbg(3, info, "%s: received %d byte DMA packet of type %x\n",
dev->name, length,
((skb->data[ETH_ALEN + ETH_ALEN] << 8) |
skb->data[ETH_ALEN + ETH_ALEN + 1]));
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += length;
}
static void release_dma_buff(struct net_local *lp)
{
if (lp->dma_buff) {
free_pages((unsigned long)(lp->dma_buff),
get_order(lp->dmasize * 1024));
lp->dma_buff = NULL;
}
}
static void
control_dc_dc(struct net_device *dev, int on_not_off)
{
struct net_local *lp = netdev_priv(dev);
unsigned int selfcontrol;
int timenow = jiffies;
selfcontrol = HCB1_ENBL;
if (((lp->adapter_cnf & A_CNF_DC_DC_POLARITY) != 0) ^ on_not_off)
selfcontrol |= HCB1;
else
selfcontrol &= ~HCB1;
writereg(dev, PP_SelfCTL, selfcontrol);
while (jiffies - timenow < HZ)
;
}
static int
send_test_pkt(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
char test_packet[] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 46,
0, 0,
0xf3, 0
};
long timenow = jiffies;
writereg(dev, PP_LineCTL, readreg(dev, PP_LineCTL) | SERIAL_TX_ON);
memcpy(test_packet, dev->dev_addr, ETH_ALEN);
memcpy(test_packet + ETH_ALEN, dev->dev_addr, ETH_ALEN);
iowrite16(TX_AFTER_ALL, lp->virt_addr + TX_CMD_PORT);
iowrite16(ETH_ZLEN, lp->virt_addr + TX_LEN_PORT);
while (jiffies - timenow < 5)
if (readreg(dev, PP_BusST) & READY_FOR_TX_NOW)
break;
if (jiffies - timenow >= 5)
return 0;
writewords(lp, TX_FRAME_PORT, test_packet, (ETH_ZLEN + 1) >> 1);
cs89_dbg(1, debug, "Sending test packet ");
for (timenow = jiffies; jiffies - timenow < 3;)
;
if ((readreg(dev, PP_TxEvent) & TX_SEND_OK_BITS) == TX_OK) {
cs89_dbg(1, cont, "succeeded\n");
return 1;
}
cs89_dbg(1, cont, "failed\n");
return 0;
}
static int
detect_tp(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int timenow = jiffies;
int fdx;
cs89_dbg(1, debug, "%s: Attempting TP\n", dev->name);
writereg(dev, PP_LineCTL, lp->linectl & ~AUI_ONLY);
control_dc_dc(dev, 0);
for (timenow = jiffies; jiffies - timenow < 15;)
;
if ((readreg(dev, PP_LineST) & LINK_OK) == 0)
return DETECTED_NONE;
if (lp->chip_type == CS8900) {
switch (lp->force & 0xf0) {
#if 0
case FORCE_AUTO:
pr_info("%s: cs8900 doesn't autonegotiate\n",
dev->name);
return DETECTED_NONE;
#endif
case FORCE_AUTO:
lp->force &= ~FORCE_AUTO;
lp->force |= FORCE_HALF;
break;
case FORCE_HALF:
break;
case FORCE_FULL:
writereg(dev, PP_TestCTL,
readreg(dev, PP_TestCTL) | FDX_8900);
break;
}
fdx = readreg(dev, PP_TestCTL) & FDX_8900;
} else {
switch (lp->force & 0xf0) {
case FORCE_AUTO:
lp->auto_neg_cnf = AUTO_NEG_ENABLE;
break;
case FORCE_HALF:
lp->auto_neg_cnf = 0;
break;
case FORCE_FULL:
lp->auto_neg_cnf = RE_NEG_NOW | ALLOW_FDX;
break;
}
writereg(dev, PP_AutoNegCTL, lp->auto_neg_cnf & AUTO_NEG_MASK);
if ((lp->auto_neg_cnf & AUTO_NEG_BITS) == AUTO_NEG_ENABLE) {
pr_info("%s: negotiating duplex...\n", dev->name);
while (readreg(dev, PP_AutoNegST) & AUTO_NEG_BUSY) {
if (jiffies - timenow > 4000) {
pr_err("**** Full / half duplex auto-negotiation timed out ****\n");
break;
}
}
}
fdx = readreg(dev, PP_AutoNegST) & FDX_ACTIVE;
}
if (fdx)
return DETECTED_RJ45F;
else
return DETECTED_RJ45H;
}
static int
detect_bnc(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
cs89_dbg(1, debug, "%s: Attempting BNC\n", dev->name);
control_dc_dc(dev, 1);
writereg(dev, PP_LineCTL, (lp->linectl & ~AUTO_AUI_10BASET) | AUI_ONLY);
if (send_test_pkt(dev))
return DETECTED_BNC;
else
return DETECTED_NONE;
}
static int
detect_aui(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
cs89_dbg(1, debug, "%s: Attempting AUI\n", dev->name);
control_dc_dc(dev, 0);
writereg(dev, PP_LineCTL, (lp->linectl & ~AUTO_AUI_10BASET) | AUI_ONLY);
if (send_test_pkt(dev))
return DETECTED_AUI;
else
return DETECTED_NONE;
}
static void
net_rx(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
struct sk_buff *skb;
int status, length;
status = ioread16(lp->virt_addr + RX_FRAME_PORT);
length = ioread16(lp->virt_addr + RX_FRAME_PORT);
if ((status & RX_OK) == 0) {
count_rx_errors(status, dev);
return;
}
skb = netdev_alloc_skb(dev, length + 2);
if (skb == NULL) {
dev->stats.rx_dropped++;
return;
}
skb_reserve(skb, 2);
readwords(lp, RX_FRAME_PORT, skb_put(skb, length), length >> 1);
if (length & 1)
skb->data[length-1] = ioread16(lp->virt_addr + RX_FRAME_PORT);
cs89_dbg(3, debug, "%s: received %d byte packet of type %x\n",
dev->name, length,
(skb->data[ETH_ALEN + ETH_ALEN] << 8) |
skb->data[ETH_ALEN + ETH_ALEN + 1]);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += length;
}
static irqreturn_t net_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct net_local *lp;
int status;
int handled = 0;
lp = netdev_priv(dev);
while ((status = ioread16(lp->virt_addr + ISQ_PORT))) {
cs89_dbg(4, debug, "%s: event=%04x\n", dev->name, status);
handled = 1;
switch (status & ISQ_EVENT_MASK) {
case ISQ_RECEIVER_EVENT:
net_rx(dev);
break;
case ISQ_TRANSMITTER_EVENT:
dev->stats.tx_packets++;
netif_wake_queue(dev);
if ((status & (TX_OK |
TX_LOST_CRS |
TX_SQE_ERROR |
TX_LATE_COL |
TX_16_COL)) != TX_OK) {
if ((status & TX_OK) == 0)
dev->stats.tx_errors++;
if (status & TX_LOST_CRS)
dev->stats.tx_carrier_errors++;
if (status & TX_SQE_ERROR)
dev->stats.tx_heartbeat_errors++;
if (status & TX_LATE_COL)
dev->stats.tx_window_errors++;
if (status & TX_16_COL)
dev->stats.tx_aborted_errors++;
}
break;
case ISQ_BUFFER_EVENT:
if (status & READY_FOR_TX) {
netif_wake_queue(dev);
}
if (status & TX_UNDERRUN) {
cs89_dbg(0, err, "%s: transmit underrun\n",
dev->name);
lp->send_underrun++;
if (lp->send_underrun == 3)
lp->send_cmd = TX_AFTER_381;
else if (lp->send_underrun == 6)
lp->send_cmd = TX_AFTER_ALL;
netif_wake_queue(dev);
}
#if ALLOW_DMA
if (lp->use_dma && (status & RX_DMA)) {
int count = readreg(dev, PP_DmaFrameCnt);
while (count) {
cs89_dbg(5, debug,
"%s: receiving %d DMA frames\n",
dev->name, count);
if (count > 1)
cs89_dbg(2, debug,
"%s: receiving %d DMA frames\n",
dev->name, count);
dma_rx(dev);
if (--count == 0)
count = readreg(dev, PP_DmaFrameCnt);
if (count > 0)
cs89_dbg(2, debug,
"%s: continuing with %d DMA frames\n",
dev->name, count);
}
}
#endif
break;
case ISQ_RX_MISS_EVENT:
dev->stats.rx_missed_errors += (status >> 6);
break;
case ISQ_TX_COL_EVENT:
dev->stats.collisions += (status >> 6);
break;
}
}
return IRQ_RETVAL(handled);
}
static int
net_open(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int result = 0;
int i;
int ret;
if (dev->irq < 2) {
#if 0
writereg(dev, PP_BusCTL, readreg(dev, PP_BusCTL) | ENABLE_IRQ);
#endif
writereg(dev, PP_BusCTL, ENABLE_IRQ | MEMORY_ON);
for (i = 2; i < CS8920_NO_INTS; i++) {
if ((1 << i) & lp->irq_map) {
if (request_irq(i, net_interrupt, 0, dev->name,
dev) == 0) {
dev->irq = i;
write_irq(dev, lp->chip_type, i);
break;
}
}
}
if (i >= CS8920_NO_INTS) {
writereg(dev, PP_BusCTL, 0);
pr_err("can't get an interrupt\n");
ret = -EAGAIN;
goto bad_out;
}
} else {
#if !defined(CONFIG_CS89x0_PLATFORM)
if (((1 << dev->irq) & lp->irq_map) == 0) {
pr_err("%s: IRQ %d is not in our map of allowable IRQs, which is %x\n",
dev->name, dev->irq, lp->irq_map);
ret = -EAGAIN;
goto bad_out;
}
#endif
writereg(dev, PP_BusCTL, readreg(dev, PP_BusCTL)|ENABLE_IRQ);
#if 0
writereg(dev, PP_BusCTL, ENABLE_IRQ | MEMORY_ON);
#endif
write_irq(dev, lp->chip_type, dev->irq);
ret = request_irq(dev->irq, net_interrupt, 0, dev->name, dev);
if (ret) {
pr_err("request_irq(%d) failed\n", dev->irq);
goto bad_out;
}
}
#if ALLOW_DMA
if (lp->use_dma && (lp->isa_config & ANY_ISA_DMA)) {
unsigned long flags;
lp->dma_buff = (unsigned char *)__get_dma_pages(GFP_KERNEL,
get_order(lp->dmasize * 1024));
if (!lp->dma_buff) {
pr_err("%s: cannot get %dK memory for DMA\n",
dev->name, lp->dmasize);
goto release_irq;
}
cs89_dbg(1, debug, "%s: dma %lx %lx\n",
dev->name,
(unsigned long)lp->dma_buff,
(unsigned long)isa_virt_to_bus(lp->dma_buff));
if ((unsigned long)lp->dma_buff >= MAX_DMA_ADDRESS ||
!dma_page_eq(lp->dma_buff,
lp->dma_buff + lp->dmasize * 1024 - 1)) {
pr_err("%s: not usable as DMA buffer\n", dev->name);
goto release_irq;
}
memset(lp->dma_buff, 0, lp->dmasize * 1024);
if (request_dma(dev->dma, dev->name)) {
pr_err("%s: cannot get dma channel %d\n",
dev->name, dev->dma);
goto release_irq;
}
write_dma(dev, lp->chip_type, dev->dma);
lp->rx_dma_ptr = lp->dma_buff;
lp->end_dma_buff = lp->dma_buff + lp->dmasize * 1024;
spin_lock_irqsave(&lp->lock, flags);
disable_dma(dev->dma);
clear_dma_ff(dev->dma);
set_dma_mode(dev->dma, DMA_RX_MODE);
set_dma_addr(dev->dma, isa_virt_to_bus(lp->dma_buff));
set_dma_count(dev->dma, lp->dmasize * 1024);
enable_dma(dev->dma);
spin_unlock_irqrestore(&lp->lock, flags);
}
#endif
for (i = 0; i < ETH_ALEN / 2; i++)
writereg(dev, PP_IA + i * 2,
(dev->dev_addr[i * 2] |
(dev->dev_addr[i * 2 + 1] << 8)));
writereg(dev, PP_BusCTL, MEMORY_ON);
if ((lp->adapter_cnf & A_CNF_EXTND_10B_2) &&
(lp->adapter_cnf & A_CNF_LOW_RX_SQUELCH))
lp->linectl = LOW_RX_SQUELCH;
else
lp->linectl = 0;
switch (lp->adapter_cnf & A_CNF_MEDIA_TYPE) {
case A_CNF_MEDIA_10B_T:
result = lp->adapter_cnf & A_CNF_10B_T;
break;
case A_CNF_MEDIA_AUI:
result = lp->adapter_cnf & A_CNF_AUI;
break;
case A_CNF_MEDIA_10B_2:
result = lp->adapter_cnf & A_CNF_10B_2;
break;
default:
result = lp->adapter_cnf & (A_CNF_10B_T |
A_CNF_AUI |
A_CNF_10B_2);
}
if (!result) {
pr_err("%s: EEPROM is configured for unavailable media\n",
dev->name);
release_dma:
#if ALLOW_DMA
free_dma(dev->dma);
release_irq:
release_dma_buff(lp);
#endif
writereg(dev, PP_LineCTL,
readreg(dev, PP_LineCTL) & ~(SERIAL_TX_ON | SERIAL_RX_ON));
free_irq(dev->irq, dev);
ret = -EAGAIN;
goto bad_out;
}
switch (lp->adapter_cnf & A_CNF_MEDIA_TYPE) {
case A_CNF_MEDIA_10B_T:
result = detect_tp(dev);
if (result == DETECTED_NONE) {
pr_warn("%s: 10Base-T (RJ-45) has no cable\n",
dev->name);
if (lp->auto_neg_cnf & IMM_BIT)
result = DETECTED_RJ45H;
}
break;
case A_CNF_MEDIA_AUI:
result = detect_aui(dev);
if (result == DETECTED_NONE) {
pr_warn("%s: 10Base-5 (AUI) has no cable\n", dev->name);
if (lp->auto_neg_cnf & IMM_BIT)
result = DETECTED_AUI;
}
break;
case A_CNF_MEDIA_10B_2:
result = detect_bnc(dev);
if (result == DETECTED_NONE) {
pr_warn("%s: 10Base-2 (BNC) has no cable\n", dev->name);
if (lp->auto_neg_cnf & IMM_BIT)
result = DETECTED_BNC;
}
break;
case A_CNF_MEDIA_AUTO:
writereg(dev, PP_LineCTL, lp->linectl | AUTO_AUI_10BASET);
if (lp->adapter_cnf & A_CNF_10B_T) {
result = detect_tp(dev);
if (result != DETECTED_NONE)
break;
}
if (lp->adapter_cnf & A_CNF_AUI) {
result = detect_aui(dev);
if (result != DETECTED_NONE)
break;
}
if (lp->adapter_cnf & A_CNF_10B_2) {
result = detect_bnc(dev);
if (result != DETECTED_NONE)
break;
}
pr_err("%s: no media detected\n", dev->name);
goto release_dma;
}
switch (result) {
case DETECTED_NONE:
pr_err("%s: no network cable attached to configured media\n",
dev->name);
goto release_dma;
case DETECTED_RJ45H:
pr_info("%s: using half-duplex 10Base-T (RJ-45)\n", dev->name);
break;
case DETECTED_RJ45F:
pr_info("%s: using full-duplex 10Base-T (RJ-45)\n", dev->name);
break;
case DETECTED_AUI:
pr_info("%s: using 10Base-5 (AUI)\n", dev->name);
break;
case DETECTED_BNC:
pr_info("%s: using 10Base-2 (BNC)\n", dev->name);
break;
}
writereg(dev, PP_LineCTL,
readreg(dev, PP_LineCTL) | SERIAL_RX_ON | SERIAL_TX_ON);
lp->rx_mode = 0;
writereg(dev, PP_RxCTL, DEF_RX_ACCEPT);
lp->curr_rx_cfg = RX_OK_ENBL | RX_CRC_ERROR_ENBL;
if (lp->isa_config & STREAM_TRANSFER)
lp->curr_rx_cfg |= RX_STREAM_ENBL;
#if ALLOW_DMA
set_dma_cfg(dev);
#endif
writereg(dev, PP_RxCFG, lp->curr_rx_cfg);
writereg(dev, PP_TxCFG, (TX_LOST_CRS_ENBL |
TX_SQE_ERROR_ENBL |
TX_OK_ENBL |
TX_LATE_COL_ENBL |
TX_JBR_ENBL |
TX_ANY_COL_ENBL |
TX_16_COL_ENBL));
writereg(dev, PP_BufCFG, (READY_FOR_TX_ENBL |
RX_MISS_COUNT_OVRFLOW_ENBL |
#if ALLOW_DMA
dma_bufcfg(dev) |
#endif
TX_COL_COUNT_OVRFLOW_ENBL |
TX_UNDERRUN_ENBL));
writereg(dev, PP_BusCTL, (ENABLE_IRQ
| (dev->mem_start ? MEMORY_ON : 0)
#if ALLOW_DMA
| dma_busctl(dev)
#endif
));
netif_start_queue(dev);
cs89_dbg(1, debug, "net_open() succeeded\n");
return 0;
bad_out:
return ret;
}
static int
net_close(struct net_device *dev)
{
#if ALLOW_DMA
struct net_local *lp = netdev_priv(dev);
#endif
netif_stop_queue(dev);
writereg(dev, PP_RxCFG, 0);
writereg(dev, PP_TxCFG, 0);
writereg(dev, PP_BufCFG, 0);
writereg(dev, PP_BusCTL, 0);
free_irq(dev->irq, dev);
#if ALLOW_DMA
if (lp->use_dma && lp->dma) {
free_dma(dev->dma);
release_dma_buff(lp);
}
#endif
return 0;
}
static struct net_device_stats *
net_get_stats(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
dev->stats.rx_missed_errors += (readreg(dev, PP_RxMiss) >> 6);
dev->stats.collisions += (readreg(dev, PP_TxCol) >> 6);
spin_unlock_irqrestore(&lp->lock, flags);
return &dev->stats;
}
static void net_timeout(struct net_device *dev)
{
cs89_dbg(0, err, "%s: transmit timed out, %s?\n",
dev->name,
tx_done(dev) ? "IRQ conflict" : "network cable problem");
netif_wake_queue(dev);
}
static netdev_tx_t net_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
cs89_dbg(3, debug, "%s: sent %d byte packet of type %x\n",
dev->name, skb->len,
((skb->data[ETH_ALEN + ETH_ALEN] << 8) |
skb->data[ETH_ALEN + ETH_ALEN + 1]));
spin_lock_irqsave(&lp->lock, flags);
netif_stop_queue(dev);
iowrite16(lp->send_cmd, lp->virt_addr + TX_CMD_PORT);
iowrite16(skb->len, lp->virt_addr + TX_LEN_PORT);
if ((readreg(dev, PP_BusST) & READY_FOR_TX_NOW) == 0) {
spin_unlock_irqrestore(&lp->lock, flags);
cs89_dbg(0, err, "Tx buffer not free!\n");
return NETDEV_TX_BUSY;
}
writewords(lp, TX_FRAME_PORT, skb->data, (skb->len + 1) >> 1);
spin_unlock_irqrestore(&lp->lock, flags);
dev->stats.tx_bytes += skb->len;
dev_consume_skb_any(skb);
return NETDEV_TX_OK;
}
static void set_multicast_list(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
u16 cfg;
spin_lock_irqsave(&lp->lock, flags);
if (dev->flags & IFF_PROMISC)
lp->rx_mode = RX_ALL_ACCEPT;
else if ((dev->flags & IFF_ALLMULTI) || !netdev_mc_empty(dev))
lp->rx_mode = RX_MULTCAST_ACCEPT;
else
lp->rx_mode = 0;
writereg(dev, PP_RxCTL, DEF_RX_ACCEPT | lp->rx_mode);
cfg = lp->curr_rx_cfg;
if (lp->rx_mode == RX_ALL_ACCEPT)
cfg |= RX_CRC_ERROR_ENBL | RX_RUNT_ENBL | RX_EXTRA_DATA_ENBL;
writereg(dev, PP_RxCFG, cfg);
spin_unlock_irqrestore(&lp->lock, flags);
}
static int set_mac_address(struct net_device *dev, void *p)
{
int i;
struct sockaddr *addr = p;
if (netif_running(dev))
return -EBUSY;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
cs89_dbg(0, debug, "%s: Setting MAC address to %pM\n",
dev->name, dev->dev_addr);
for (i = 0; i < ETH_ALEN / 2; i++)
writereg(dev, PP_IA + i * 2,
(dev->dev_addr[i * 2] |
(dev->dev_addr[i * 2 + 1] << 8)));
return 0;
}
static void net_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
net_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static void __init reset_chip(struct net_device *dev)
{
#if !defined(CONFIG_MACH_MX31ADS)
struct net_local *lp = netdev_priv(dev);
int reset_start_time;
writereg(dev, PP_SelfCTL, readreg(dev, PP_SelfCTL) | POWER_ON_RESET);
msleep(30);
if (lp->chip_type != CS8900) {
iowrite16(PP_CS8920_ISAINT, lp->virt_addr + ADD_PORT);
iowrite8(dev->irq, lp->virt_addr + DATA_PORT);
iowrite8(0, lp->virt_addr + DATA_PORT + 1);
iowrite16(PP_CS8920_ISAMemB, lp->virt_addr + ADD_PORT);
iowrite8((dev->mem_start >> 16) & 0xff,
lp->virt_addr + DATA_PORT);
iowrite8((dev->mem_start >> 8) & 0xff,
lp->virt_addr + DATA_PORT + 1);
}
reset_start_time = jiffies;
while ((readreg(dev, PP_SelfST) & INIT_DONE) == 0 &&
jiffies - reset_start_time < 2)
;
#endif
}
static int __init
cs89x0_probe1(struct net_device *dev, void __iomem *ioaddr, int modular)
{
struct net_local *lp = netdev_priv(dev);
int i;
int tmp;
unsigned rev_type = 0;
int eeprom_buff[CHKSUM_LEN];
int retval;
if (!modular) {
memset(lp, 0, sizeof(*lp));
spin_lock_init(&lp->lock);
#ifndef MODULE
#if ALLOW_DMA
if (g_cs89x0_dma) {
lp->use_dma = 1;
lp->dma = g_cs89x0_dma;
lp->dmasize = 16;
}
#endif
lp->force = g_cs89x0_media__force;
#endif
}
pr_debug("PP_addr at %p[%x]: 0x%x\n",
ioaddr, ADD_PORT, ioread16(ioaddr + ADD_PORT));
iowrite16(PP_ChipID, ioaddr + ADD_PORT);
tmp = ioread16(ioaddr + DATA_PORT);
if (tmp != CHIP_EISA_ID_SIG) {
pr_debug("%s: incorrect signature at %p[%x]: 0x%x!="
CHIP_EISA_ID_SIG_STR "\n",
dev->name, ioaddr, DATA_PORT, tmp);
retval = -ENODEV;
goto out1;
}
lp->virt_addr = ioaddr;
rev_type = readreg(dev, PRODUCT_ID_ADD);
lp->chip_type = rev_type & ~REVISON_BITS;
lp->chip_revision = ((rev_type & REVISON_BITS) >> 8) + 'A';
lp->send_cmd = TX_AFTER_381;
if (lp->chip_type == CS8900 && lp->chip_revision >= 'F')
lp->send_cmd = TX_NOW;
if (lp->chip_type != CS8900 && lp->chip_revision >= 'C')
lp->send_cmd = TX_NOW;
pr_info_once("%s\n", version);
pr_info("%s: cs89%c0%s rev %c found at %p ",
dev->name,
lp->chip_type == CS8900 ? '0' : '2',
lp->chip_type == CS8920M ? "M" : "",
lp->chip_revision,
lp->virt_addr);
reset_chip(dev);
if ((readreg(dev, PP_SelfST) & (EEPROM_OK | EEPROM_PRESENT)) ==
(EEPROM_OK | EEPROM_PRESENT)) {
for (i = 0; i < ETH_ALEN / 2; i++) {
unsigned int Addr;
Addr = readreg(dev, PP_IA + i * 2);
dev->dev_addr[i * 2] = Addr & 0xFF;
dev->dev_addr[i * 2 + 1] = Addr >> 8;
}
lp->adapter_cnf = 0;
i = readreg(dev, PP_LineCTL);
if ((i & (HCB1 | HCB1_ENBL)) == (HCB1 | HCB1_ENBL))
lp->adapter_cnf |= A_CNF_DC_DC_POLARITY;
if ((i & LOW_RX_SQUELCH) == LOW_RX_SQUELCH)
lp->adapter_cnf |= A_CNF_EXTND_10B_2 | A_CNF_LOW_RX_SQUELCH;
if ((i & (AUI_ONLY | AUTO_AUI_10BASET)) == 0)
lp->adapter_cnf |= A_CNF_10B_T | A_CNF_MEDIA_10B_T;
if ((i & (AUI_ONLY | AUTO_AUI_10BASET)) == AUI_ONLY)
lp->adapter_cnf |= A_CNF_AUI | A_CNF_MEDIA_AUI;
if ((i & (AUI_ONLY | AUTO_AUI_10BASET)) == AUTO_AUI_10BASET)
lp->adapter_cnf |= A_CNF_AUI | A_CNF_10B_T |
A_CNF_MEDIA_AUI | A_CNF_MEDIA_10B_T | A_CNF_MEDIA_AUTO;
cs89_dbg(1, info, "%s: PP_LineCTL=0x%x, adapter_cnf=0x%x\n",
dev->name, i, lp->adapter_cnf);
if (lp->chip_type == CS8900)
lp->isa_config = readreg(dev, PP_CS8900_ISAINT) & INT_NO_MASK;
pr_cont("[Cirrus EEPROM] ");
}
pr_cont("\n");
if ((readreg(dev, PP_SelfST) & EEPROM_PRESENT) == 0)
pr_warn("No EEPROM, relying on command line....\n");
else if (get_eeprom_data(dev, START_EEPROM_DATA, CHKSUM_LEN, eeprom_buff) < 0) {
pr_warn("EEPROM read failed, relying on command line\n");
} else if (get_eeprom_cksum(START_EEPROM_DATA, CHKSUM_LEN, eeprom_buff) < 0) {
if ((readreg(dev, PP_SelfST) & (EEPROM_OK | EEPROM_PRESENT)) !=
(EEPROM_OK | EEPROM_PRESENT))
pr_warn("Extended EEPROM checksum bad and no Cirrus EEPROM, relying on command line\n");
} else {
if (!lp->auto_neg_cnf)
lp->auto_neg_cnf = eeprom_buff[AUTO_NEG_CNF_OFFSET / 2];
if (!lp->adapter_cnf)
lp->adapter_cnf = eeprom_buff[ADAPTER_CNF_OFFSET / 2];
lp->isa_config = eeprom_buff[ISA_CNF_OFFSET / 2];
dev->mem_start = eeprom_buff[PACKET_PAGE_OFFSET / 2] << 8;
for (i = 0; i < ETH_ALEN / 2; i++) {
dev->dev_addr[i * 2] = eeprom_buff[i];
dev->dev_addr[i * 2 + 1] = eeprom_buff[i] >> 8;
}
cs89_dbg(1, debug, "%s: new adapter_cnf: 0x%x\n",
dev->name, lp->adapter_cnf);
}
{
int count = 0;
if (lp->force & FORCE_RJ45) {
lp->adapter_cnf |= A_CNF_10B_T;
count++;
}
if (lp->force & FORCE_AUI) {
lp->adapter_cnf |= A_CNF_AUI;
count++;
}
if (lp->force & FORCE_BNC) {
lp->adapter_cnf |= A_CNF_10B_2;
count++;
}
if (count > 1)
lp->adapter_cnf |= A_CNF_MEDIA_AUTO;
else if (lp->force & FORCE_RJ45)
lp->adapter_cnf |= A_CNF_MEDIA_10B_T;
else if (lp->force & FORCE_AUI)
lp->adapter_cnf |= A_CNF_MEDIA_AUI;
else if (lp->force & FORCE_BNC)
lp->adapter_cnf |= A_CNF_MEDIA_10B_2;
}
cs89_dbg(1, debug, "%s: after force 0x%x, adapter_cnf=0x%x\n",
dev->name, lp->force, lp->adapter_cnf);
pr_info("media %s%s%s",
(lp->adapter_cnf & A_CNF_10B_T) ? "RJ-45," : "",
(lp->adapter_cnf & A_CNF_AUI) ? "AUI," : "",
(lp->adapter_cnf & A_CNF_10B_2) ? "BNC," : "");
lp->irq_map = 0xffff;
if (lp->chip_type != CS8900 &&
(i = readreg(dev, PP_CS8920_ISAINT) & 0xff,
(i != 0 && i < CS8920_NO_INTS))) {
if (!dev->irq)
dev->irq = i;
} else {
i = lp->isa_config & INT_NO_MASK;
#ifndef CONFIG_CS89x0_PLATFORM
if (lp->chip_type == CS8900) {
if (i >= ARRAY_SIZE(cs8900_irq_map))
pr_err("invalid ISA interrupt number %d\n", i);
else
i = cs8900_irq_map[i];
lp->irq_map = CS8900_IRQ_MAP;
} else {
int irq_map_buff[IRQ_MAP_LEN/2];
if (get_eeprom_data(dev, IRQ_MAP_EEPROM_DATA,
IRQ_MAP_LEN / 2,
irq_map_buff) >= 0) {
if ((irq_map_buff[0] & 0xff) == PNP_IRQ_FRMT)
lp->irq_map = ((irq_map_buff[0] >> 8) |
(irq_map_buff[1] << 8));
}
}
#endif
if (!dev->irq)
dev->irq = i;
}
pr_cont(" IRQ %d", dev->irq);
#if ALLOW_DMA
if (lp->use_dma) {
get_dma_channel(dev);
pr_cont(", DMA %d", dev->dma);
} else
#endif
pr_cont(", programmed I/O");
pr_cont(", MAC %pM\n", dev->dev_addr);
dev->netdev_ops = &net_ops;
dev->watchdog_timeo = HZ;
cs89_dbg(0, info, "cs89x0_probe1() successful\n");
retval = register_netdev(dev);
if (retval)
goto out2;
return 0;
out2:
iowrite16(PP_ChipID, lp->virt_addr + ADD_PORT);
out1:
return retval;
}
static int __init
cs89x0_ioport_probe(struct net_device *dev, unsigned long ioport, int modular)
{
struct net_local *lp = netdev_priv(dev);
int ret;
void __iomem *io_mem;
if (!lp)
return -ENOMEM;
dev->base_addr = ioport;
if (!request_region(ioport, NETCARD_IO_EXTENT, DRV_NAME)) {
ret = -EBUSY;
goto out;
}
io_mem = ioport_map(ioport & ~3, NETCARD_IO_EXTENT);
if (!io_mem) {
ret = -ENOMEM;
goto release;
}
if (ioport & 1) {
cs89_dbg(1, info, "%s: odd ioaddr 0x%lx\n", dev->name, ioport);
if ((ioport & 2) != 2) {
if ((ioread16(io_mem + ADD_PORT) & ADD_MASK) !=
ADD_SIG) {
pr_err("%s: bad signature 0x%x\n",
dev->name, ioread16(io_mem + ADD_PORT));
ret = -ENODEV;
goto unmap;
}
}
}
ret = cs89x0_probe1(dev, io_mem, modular);
if (!ret)
goto out;
unmap:
ioport_unmap(io_mem);
release:
release_region(ioport, NETCARD_IO_EXTENT);
out:
return ret;
}
struct net_device * __init cs89x0_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct net_local));
unsigned *port;
int err = 0;
int irq;
int io;
if (!dev)
return ERR_PTR(-ENODEV);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
io = dev->base_addr;
irq = dev->irq;
cs89_dbg(0, info, "cs89x0_probe(0x%x)\n", io);
if (io > 0x1ff) {
err = cs89x0_ioport_probe(dev, io, 0);
} else if (io != 0) {
err = -ENXIO;
} else {
for (port = netcard_portlist; *port; port++) {
if (cs89x0_ioport_probe(dev, *port, 0) == 0)
break;
dev->irq = irq;
}
if (!*port)
err = -ENODEV;
}
if (err)
goto out;
return dev;
out:
free_netdev(dev);
pr_warn("no cs8900 or cs8920 detected. Be sure to disable PnP with SETUP\n");
return ERR_PTR(err);
}
int __init init_module(void)
{
struct net_device *dev = alloc_etherdev(sizeof(struct net_local));
struct net_local *lp;
int ret = 0;
#if DEBUGGING
net_debug = debug;
#else
debug = 0;
#endif
if (!dev)
return -ENOMEM;
dev->irq = irq;
dev->base_addr = io;
lp = netdev_priv(dev);
#if ALLOW_DMA
if (use_dma) {
lp->use_dma = use_dma;
lp->dma = dma;
lp->dmasize = dmasize;
}
#endif
spin_lock_init(&lp->lock);
if (!strcmp(media, "rj45"))
lp->adapter_cnf = A_CNF_MEDIA_10B_T | A_CNF_10B_T;
else if (!strcmp(media, "aui"))
lp->adapter_cnf = A_CNF_MEDIA_AUI | A_CNF_AUI;
else if (!strcmp(media, "bnc"))
lp->adapter_cnf = A_CNF_MEDIA_10B_2 | A_CNF_10B_2;
else
lp->adapter_cnf = A_CNF_MEDIA_10B_T | A_CNF_10B_T;
if (duplex == -1)
lp->auto_neg_cnf = AUTO_NEG_ENABLE;
if (io == 0) {
pr_err("Module autoprobing not allowed\n");
pr_err("Append io=0xNNN\n");
ret = -EPERM;
goto out;
} else if (io <= 0x1ff) {
ret = -ENXIO;
goto out;
}
#if ALLOW_DMA
if (use_dma && dmasize != 16 && dmasize != 64) {
pr_err("dma size must be either 16K or 64K, not %dK\n",
dmasize);
ret = -EPERM;
goto out;
}
#endif
ret = cs89x0_ioport_probe(dev, io, 1);
if (ret)
goto out;
dev_cs89x0 = dev;
return 0;
out:
free_netdev(dev);
return ret;
}
void __exit
cleanup_module(void)
{
struct net_local *lp = netdev_priv(dev_cs89x0);
unregister_netdev(dev_cs89x0);
iowrite16(PP_ChipID, lp->virt_addr + ADD_PORT);
ioport_unmap(lp->virt_addr);
release_region(dev_cs89x0->base_addr, NETCARD_IO_EXTENT);
free_netdev(dev_cs89x0);
}
static int __init cs89x0_platform_probe(struct platform_device *pdev)
{
struct net_device *dev = alloc_etherdev(sizeof(struct net_local));
struct net_local *lp;
struct resource *mem_res;
void __iomem *virt_addr;
int err;
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->irq = platform_get_irq(pdev, 0);
if (mem_res == NULL || dev->irq <= 0) {
dev_warn(&dev->dev, "memory/interrupt resource missing\n");
err = -ENXIO;
goto free;
}
lp->size = resource_size(mem_res);
if (!request_mem_region(mem_res->start, lp->size, DRV_NAME)) {
dev_warn(&dev->dev, "request_mem_region() failed\n");
err = -EBUSY;
goto free;
}
virt_addr = ioremap(mem_res->start, lp->size);
if (!virt_addr) {
dev_warn(&dev->dev, "ioremap() failed\n");
err = -ENOMEM;
goto release;
}
err = cs89x0_probe1(dev, virt_addr, 0);
if (err) {
dev_warn(&dev->dev, "no cs8900 or cs8920 detected\n");
goto unmap;
}
platform_set_drvdata(pdev, dev);
return 0;
unmap:
iounmap(virt_addr);
release:
release_mem_region(mem_res->start, lp->size);
free:
free_netdev(dev);
return err;
}
static int cs89x0_platform_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct net_local *lp = netdev_priv(dev);
struct resource *mem_res;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
unregister_netdev(dev);
iounmap(lp->virt_addr);
release_mem_region(mem_res->start, lp->size);
free_netdev(dev);
return 0;
}
