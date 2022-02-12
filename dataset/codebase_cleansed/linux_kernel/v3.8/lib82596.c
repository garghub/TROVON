static inline int wait_istat(struct net_device *dev, struct i596_dma *dma, int delcnt, char *str)
{
DMA_INV(dev, &(dma->iscp), sizeof(struct i596_iscp));
while (--delcnt && dma->iscp.stat) {
udelay(10);
DMA_INV(dev, &(dma->iscp), sizeof(struct i596_iscp));
}
if (!delcnt) {
printk(KERN_ERR "%s: %s, iscp.stat %04x, didn't clear\n",
dev->name, str, SWAP16(dma->iscp.stat));
return -1;
} else
return 0;
}
static inline int wait_cmd(struct net_device *dev, struct i596_dma *dma, int delcnt, char *str)
{
DMA_INV(dev, &(dma->scb), sizeof(struct i596_scb));
while (--delcnt && dma->scb.command) {
udelay(10);
DMA_INV(dev, &(dma->scb), sizeof(struct i596_scb));
}
if (!delcnt) {
printk(KERN_ERR "%s: %s, status %4.4x, cmd %4.4x.\n",
dev->name, str,
SWAP16(dma->scb.status),
SWAP16(dma->scb.command));
return -1;
} else
return 0;
}
static void i596_display_data(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
struct i596_cmd *cmd;
struct i596_rfd *rfd;
struct i596_rbd *rbd;
printk(KERN_DEBUG "lp and scp at %p, .sysbus = %08x, .iscp = %08x\n",
&dma->scp, dma->scp.sysbus, SWAP32(dma->scp.iscp));
printk(KERN_DEBUG "iscp at %p, iscp.stat = %08x, .scb = %08x\n",
&dma->iscp, SWAP32(dma->iscp.stat), SWAP32(dma->iscp.scb));
printk(KERN_DEBUG "scb at %p, scb.status = %04x, .command = %04x,"
" .cmd = %08x, .rfd = %08x\n",
&dma->scb, SWAP16(dma->scb.status), SWAP16(dma->scb.command),
SWAP16(dma->scb.cmd), SWAP32(dma->scb.rfd));
printk(KERN_DEBUG " errors: crc %x, align %x, resource %x,"
" over %x, rcvdt %x, short %x\n",
SWAP32(dma->scb.crc_err), SWAP32(dma->scb.align_err),
SWAP32(dma->scb.resource_err), SWAP32(dma->scb.over_err),
SWAP32(dma->scb.rcvdt_err), SWAP32(dma->scb.short_err));
cmd = lp->cmd_head;
while (cmd != NULL) {
printk(KERN_DEBUG
"cmd at %p, .status = %04x, .command = %04x,"
" .b_next = %08x\n",
cmd, SWAP16(cmd->status), SWAP16(cmd->command),
SWAP32(cmd->b_next));
cmd = cmd->v_next;
}
rfd = lp->rfd_head;
printk(KERN_DEBUG "rfd_head = %p\n", rfd);
do {
printk(KERN_DEBUG
" %p .stat %04x, .cmd %04x, b_next %08x, rbd %08x,"
" count %04x\n",
rfd, SWAP16(rfd->stat), SWAP16(rfd->cmd),
SWAP32(rfd->b_next), SWAP32(rfd->rbd),
SWAP16(rfd->count));
rfd = rfd->v_next;
} while (rfd != lp->rfd_head);
rbd = lp->rbd_head;
printk(KERN_DEBUG "rbd_head = %p\n", rbd);
do {
printk(KERN_DEBUG
" %p .count %04x, b_next %08x, b_data %08x,"
" size %04x\n",
rbd, SWAP16(rbd->count), SWAP32(rbd->b_next),
SWAP32(rbd->b_data), SWAP16(rbd->size));
rbd = rbd->v_next;
} while (rbd != lp->rbd_head);
DMA_INV(dev, dma, sizeof(struct i596_dma));
}
static inline int init_rx_bufs(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
int i;
struct i596_rfd *rfd;
struct i596_rbd *rbd;
for (i = 0, rbd = dma->rbds; i < rx_ring_size; i++, rbd++) {
dma_addr_t dma_addr;
struct sk_buff *skb;
skb = netdev_alloc_skb_ip_align(dev, PKT_BUF_SZ);
if (skb == NULL)
return -1;
dma_addr = dma_map_single(dev->dev.parent, skb->data,
PKT_BUF_SZ, DMA_FROM_DEVICE);
rbd->v_next = rbd+1;
rbd->b_next = SWAP32(virt_to_dma(lp, rbd+1));
rbd->b_addr = SWAP32(virt_to_dma(lp, rbd));
rbd->skb = skb;
rbd->v_data = skb->data;
rbd->b_data = SWAP32(dma_addr);
rbd->size = SWAP16(PKT_BUF_SZ);
}
lp->rbd_head = dma->rbds;
rbd = dma->rbds + rx_ring_size - 1;
rbd->v_next = dma->rbds;
rbd->b_next = SWAP32(virt_to_dma(lp, dma->rbds));
for (i = 0, rfd = dma->rfds; i < rx_ring_size; i++, rfd++) {
rfd->rbd = I596_NULL;
rfd->v_next = rfd+1;
rfd->v_prev = rfd-1;
rfd->b_next = SWAP32(virt_to_dma(lp, rfd+1));
rfd->cmd = SWAP16(CMD_FLEX);
}
lp->rfd_head = dma->rfds;
dma->scb.rfd = SWAP32(virt_to_dma(lp, dma->rfds));
rfd = dma->rfds;
rfd->rbd = SWAP32(virt_to_dma(lp, lp->rbd_head));
rfd->v_prev = dma->rfds + rx_ring_size - 1;
rfd = dma->rfds + rx_ring_size - 1;
rfd->v_next = dma->rfds;
rfd->b_next = SWAP32(virt_to_dma(lp, dma->rfds));
rfd->cmd = SWAP16(CMD_EOL|CMD_FLEX);
DMA_WBACK_INV(dev, dma, sizeof(struct i596_dma));
return 0;
}
static inline void remove_rx_bufs(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_rbd *rbd;
int i;
for (i = 0, rbd = lp->dma->rbds; i < rx_ring_size; i++, rbd++) {
if (rbd->skb == NULL)
break;
dma_unmap_single(dev->dev.parent,
(dma_addr_t)SWAP32(rbd->b_data),
PKT_BUF_SZ, DMA_FROM_DEVICE);
dev_kfree_skb(rbd->skb);
}
}
static void rebuild_rx_bufs(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
int i;
for (i = 0; i < rx_ring_size; i++) {
dma->rfds[i].rbd = I596_NULL;
dma->rfds[i].cmd = SWAP16(CMD_FLEX);
}
dma->rfds[rx_ring_size-1].cmd = SWAP16(CMD_EOL|CMD_FLEX);
lp->rfd_head = dma->rfds;
dma->scb.rfd = SWAP32(virt_to_dma(lp, dma->rfds));
lp->rbd_head = dma->rbds;
dma->rfds[0].rbd = SWAP32(virt_to_dma(lp, dma->rbds));
DMA_WBACK_INV(dev, dma, sizeof(struct i596_dma));
}
static int init_i596_mem(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
unsigned long flags;
mpu_port(dev, PORT_RESET, 0);
udelay(100);
lp->last_cmd = jiffies;
dma->scp.sysbus = SYSBUS;
dma->scp.iscp = SWAP32(virt_to_dma(lp, &(dma->iscp)));
dma->iscp.scb = SWAP32(virt_to_dma(lp, &(dma->scb)));
dma->iscp.stat = SWAP32(ISCP_BUSY);
lp->cmd_backlog = 0;
lp->cmd_head = NULL;
dma->scb.cmd = I596_NULL;
DEB(DEB_INIT, printk(KERN_DEBUG "%s: starting i82596.\n", dev->name));
DMA_WBACK(dev, &(dma->scp), sizeof(struct i596_scp));
DMA_WBACK(dev, &(dma->iscp), sizeof(struct i596_iscp));
DMA_WBACK(dev, &(dma->scb), sizeof(struct i596_scb));
mpu_port(dev, PORT_ALTSCP, virt_to_dma(lp, &dma->scp));
ca(dev);
if (wait_istat(dev, dma, 1000, "initialization timed out"))
goto failed;
DEB(DEB_INIT, printk(KERN_DEBUG
"%s: i82596 initialization successful\n",
dev->name));
if (request_irq(dev->irq, i596_interrupt, 0, "i82596", dev)) {
printk(KERN_ERR "%s: IRQ %d not free\n", dev->name, dev->irq);
goto failed;
}
rebuild_rx_bufs(dev);
dma->scb.command = 0;
DMA_WBACK(dev, &(dma->scb), sizeof(struct i596_scb));
DEB(DEB_INIT, printk(KERN_DEBUG
"%s: queuing CmdConfigure\n", dev->name));
memcpy(dma->cf_cmd.i596_config, init_setup, 14);
dma->cf_cmd.cmd.command = SWAP16(CmdConfigure);
DMA_WBACK(dev, &(dma->cf_cmd), sizeof(struct cf_cmd));
i596_add_cmd(dev, &dma->cf_cmd.cmd);
DEB(DEB_INIT, printk(KERN_DEBUG "%s: queuing CmdSASetup\n", dev->name));
memcpy(dma->sa_cmd.eth_addr, dev->dev_addr, 6);
dma->sa_cmd.cmd.command = SWAP16(CmdSASetup);
DMA_WBACK(dev, &(dma->sa_cmd), sizeof(struct sa_cmd));
i596_add_cmd(dev, &dma->sa_cmd.cmd);
DEB(DEB_INIT, printk(KERN_DEBUG "%s: queuing CmdTDR\n", dev->name));
dma->tdr_cmd.cmd.command = SWAP16(CmdTDR);
DMA_WBACK(dev, &(dma->tdr_cmd), sizeof(struct tdr_cmd));
i596_add_cmd(dev, &dma->tdr_cmd.cmd);
spin_lock_irqsave (&lp->lock, flags);
if (wait_cmd(dev, dma, 1000, "timed out waiting to issue RX_START")) {
spin_unlock_irqrestore (&lp->lock, flags);
goto failed_free_irq;
}
DEB(DEB_INIT, printk(KERN_DEBUG "%s: Issuing RX_START\n", dev->name));
dma->scb.command = SWAP16(RX_START);
dma->scb.rfd = SWAP32(virt_to_dma(lp, dma->rfds));
DMA_WBACK(dev, &(dma->scb), sizeof(struct i596_scb));
ca(dev);
spin_unlock_irqrestore (&lp->lock, flags);
if (wait_cmd(dev, dma, 1000, "RX_START not processed"))
goto failed_free_irq;
DEB(DEB_INIT, printk(KERN_DEBUG
"%s: Receive unit started OK\n", dev->name));
return 0;
failed_free_irq:
free_irq(dev->irq, dev);
failed:
printk(KERN_ERR "%s: Failed to initialise 82596\n", dev->name);
mpu_port(dev, PORT_RESET, 0);
return -1;
}
static inline int i596_rx(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_rfd *rfd;
struct i596_rbd *rbd;
int frames = 0;
DEB(DEB_RXFRAME, printk(KERN_DEBUG
"i596_rx(), rfd_head %p, rbd_head %p\n",
lp->rfd_head, lp->rbd_head));
rfd = lp->rfd_head;
DMA_INV(dev, rfd, sizeof(struct i596_rfd));
while (rfd->stat & SWAP16(STAT_C)) {
if (rfd->rbd == I596_NULL)
rbd = NULL;
else if (rfd->rbd == lp->rbd_head->b_addr) {
rbd = lp->rbd_head;
DMA_INV(dev, rbd, sizeof(struct i596_rbd));
} else {
printk(KERN_ERR "%s: rbd chain broken!\n", dev->name);
rbd = NULL;
}
DEB(DEB_RXFRAME, printk(KERN_DEBUG
" rfd %p, rfd.rbd %08x, rfd.stat %04x\n",
rfd, rfd->rbd, rfd->stat));
if (rbd != NULL && (rfd->stat & SWAP16(STAT_OK))) {
int pkt_len = SWAP16(rbd->count) & 0x3fff;
struct sk_buff *skb = rbd->skb;
int rx_in_place = 0;
DEB(DEB_RXADDR, print_eth(rbd->v_data, "received"));
frames++;
if (pkt_len > rx_copybreak) {
struct sk_buff *newskb;
dma_addr_t dma_addr;
dma_unmap_single(dev->dev.parent,
(dma_addr_t)SWAP32(rbd->b_data),
PKT_BUF_SZ, DMA_FROM_DEVICE);
newskb = netdev_alloc_skb_ip_align(dev,
PKT_BUF_SZ);
if (newskb == NULL) {
skb = NULL;
goto memory_squeeze;
}
skb_put(skb, pkt_len);
rx_in_place = 1;
rbd->skb = newskb;
dma_addr = dma_map_single(dev->dev.parent,
newskb->data,
PKT_BUF_SZ,
DMA_FROM_DEVICE);
rbd->v_data = newskb->data;
rbd->b_data = SWAP32(dma_addr);
DMA_WBACK_INV(dev, rbd, sizeof(struct i596_rbd));
} else
skb = netdev_alloc_skb_ip_align(dev, pkt_len);
memory_squeeze:
if (skb == NULL) {
printk(KERN_ERR
"%s: i596_rx Memory squeeze, dropping packet.\n",
dev->name);
dev->stats.rx_dropped++;
} else {
if (!rx_in_place) {
dma_sync_single_for_cpu(dev->dev.parent,
(dma_addr_t)SWAP32(rbd->b_data),
PKT_BUF_SZ, DMA_FROM_DEVICE);
memcpy(skb_put(skb, pkt_len), rbd->v_data, pkt_len);
dma_sync_single_for_device(dev->dev.parent,
(dma_addr_t)SWAP32(rbd->b_data),
PKT_BUF_SZ, DMA_FROM_DEVICE);
}
skb->len = pkt_len;
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
} else {
DEB(DEB_ERRORS, printk(KERN_DEBUG
"%s: Error, rfd.stat = 0x%04x\n",
dev->name, rfd->stat));
dev->stats.rx_errors++;
if (rfd->stat & SWAP16(0x0100))
dev->stats.collisions++;
if (rfd->stat & SWAP16(0x8000))
dev->stats.rx_length_errors++;
if (rfd->stat & SWAP16(0x0001))
dev->stats.rx_over_errors++;
if (rfd->stat & SWAP16(0x0002))
dev->stats.rx_fifo_errors++;
if (rfd->stat & SWAP16(0x0004))
dev->stats.rx_frame_errors++;
if (rfd->stat & SWAP16(0x0008))
dev->stats.rx_crc_errors++;
if (rfd->stat & SWAP16(0x0010))
dev->stats.rx_length_errors++;
}
if (rbd != NULL && (rbd->count & SWAP16(0x4000))) {
rbd->count = 0;
lp->rbd_head = rbd->v_next;
DMA_WBACK_INV(dev, rbd, sizeof(struct i596_rbd));
}
rfd->rbd = I596_NULL;
rfd->stat = 0;
rfd->cmd = SWAP16(CMD_EOL|CMD_FLEX);
rfd->count = 0;
lp->dma->scb.rfd = rfd->b_next;
lp->rfd_head = rfd->v_next;
DMA_WBACK_INV(dev, rfd, sizeof(struct i596_rfd));
rfd->v_prev->cmd = SWAP16(CMD_FLEX);
DMA_WBACK_INV(dev, rfd->v_prev, sizeof(struct i596_rfd));
rfd = lp->rfd_head;
DMA_INV(dev, rfd, sizeof(struct i596_rfd));
}
DEB(DEB_RXFRAME, printk(KERN_DEBUG "frames %d\n", frames));
return 0;
}
static inline void i596_cleanup_cmd(struct net_device *dev, struct i596_private *lp)
{
struct i596_cmd *ptr;
while (lp->cmd_head != NULL) {
ptr = lp->cmd_head;
lp->cmd_head = ptr->v_next;
lp->cmd_backlog--;
switch (SWAP16(ptr->command) & 0x7) {
case CmdTx:
{
struct tx_cmd *tx_cmd = (struct tx_cmd *) ptr;
struct sk_buff *skb = tx_cmd->skb;
dma_unmap_single(dev->dev.parent,
tx_cmd->dma_addr,
skb->len, DMA_TO_DEVICE);
dev_kfree_skb(skb);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
ptr->v_next = NULL;
ptr->b_next = I596_NULL;
tx_cmd->cmd.command = 0;
break;
}
default:
ptr->v_next = NULL;
ptr->b_next = I596_NULL;
}
DMA_WBACK_INV(dev, ptr, sizeof(struct i596_cmd));
}
wait_cmd(dev, lp->dma, 100, "i596_cleanup_cmd timed out");
lp->dma->scb.cmd = I596_NULL;
DMA_WBACK(dev, &(lp->dma->scb), sizeof(struct i596_scb));
}
static inline void i596_reset(struct net_device *dev, struct i596_private *lp)
{
unsigned long flags;
DEB(DEB_RESET, printk(KERN_DEBUG "i596_reset\n"));
spin_lock_irqsave (&lp->lock, flags);
wait_cmd(dev, lp->dma, 100, "i596_reset timed out");
netif_stop_queue(dev);
lp->dma->scb.command = SWAP16(CUC_ABORT | RX_ABORT);
DMA_WBACK(dev, &(lp->dma->scb), sizeof(struct i596_scb));
ca(dev);
wait_cmd(dev, lp->dma, 1000, "i596_reset 2 timed out");
spin_unlock_irqrestore (&lp->lock, flags);
i596_cleanup_cmd(dev, lp);
i596_rx(dev);
netif_start_queue(dev);
init_i596_mem(dev);
}
static void i596_add_cmd(struct net_device *dev, struct i596_cmd *cmd)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
unsigned long flags;
DEB(DEB_ADDCMD, printk(KERN_DEBUG "i596_add_cmd cmd_head %p\n",
lp->cmd_head));
cmd->status = 0;
cmd->command |= SWAP16(CMD_EOL | CMD_INTR);
cmd->v_next = NULL;
cmd->b_next = I596_NULL;
DMA_WBACK(dev, cmd, sizeof(struct i596_cmd));
spin_lock_irqsave (&lp->lock, flags);
if (lp->cmd_head != NULL) {
lp->cmd_tail->v_next = cmd;
lp->cmd_tail->b_next = SWAP32(virt_to_dma(lp, &cmd->status));
DMA_WBACK(dev, lp->cmd_tail, sizeof(struct i596_cmd));
} else {
lp->cmd_head = cmd;
wait_cmd(dev, dma, 100, "i596_add_cmd timed out");
dma->scb.cmd = SWAP32(virt_to_dma(lp, &cmd->status));
dma->scb.command = SWAP16(CUC_START);
DMA_WBACK(dev, &(dma->scb), sizeof(struct i596_scb));
ca(dev);
}
lp->cmd_tail = cmd;
lp->cmd_backlog++;
spin_unlock_irqrestore (&lp->lock, flags);
if (lp->cmd_backlog > max_cmd_backlog) {
unsigned long tickssofar = jiffies - lp->last_cmd;
if (tickssofar < ticks_limit)
return;
printk(KERN_ERR
"%s: command unit timed out, status resetting.\n",
dev->name);
#if 1
i596_reset(dev, lp);
#endif
}
}
static int i596_open(struct net_device *dev)
{
DEB(DEB_OPEN, printk(KERN_DEBUG
"%s: i596_open() irq %d.\n", dev->name, dev->irq));
if (init_rx_bufs(dev)) {
printk(KERN_ERR "%s: Failed to init rx bufs\n", dev->name);
return -EAGAIN;
}
if (init_i596_mem(dev)) {
printk(KERN_ERR "%s: Failed to init memory\n", dev->name);
goto out_remove_rx_bufs;
}
netif_start_queue(dev);
return 0;
out_remove_rx_bufs:
remove_rx_bufs(dev);
return -EAGAIN;
}
static void i596_tx_timeout (struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
DEB(DEB_ERRORS, printk(KERN_DEBUG
"%s: transmit timed out, status resetting.\n",
dev->name));
dev->stats.tx_errors++;
if (lp->last_restart == dev->stats.tx_packets) {
DEB(DEB_ERRORS, printk(KERN_DEBUG "Resetting board.\n"));
i596_reset (dev, lp);
} else {
DEB(DEB_ERRORS, printk(KERN_DEBUG "Kicking board.\n"));
lp->dma->scb.command = SWAP16(CUC_START | RX_START);
DMA_WBACK_INV(dev, &(lp->dma->scb), sizeof(struct i596_scb));
ca (dev);
lp->last_restart = dev->stats.tx_packets;
}
dev->trans_start = jiffies;
netif_wake_queue (dev);
}
static int i596_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct tx_cmd *tx_cmd;
struct i596_tbd *tbd;
short length = skb->len;
DEB(DEB_STARTTX, printk(KERN_DEBUG
"%s: i596_start_xmit(%x,%p) called\n",
dev->name, skb->len, skb->data));
if (length < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
netif_stop_queue(dev);
tx_cmd = lp->dma->tx_cmds + lp->next_tx_cmd;
tbd = lp->dma->tbds + lp->next_tx_cmd;
if (tx_cmd->cmd.command) {
DEB(DEB_ERRORS, printk(KERN_DEBUG
"%s: xmit ring full, dropping packet.\n",
dev->name));
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
} else {
if (++lp->next_tx_cmd == TX_RING_SIZE)
lp->next_tx_cmd = 0;
tx_cmd->tbd = SWAP32(virt_to_dma(lp, tbd));
tbd->next = I596_NULL;
tx_cmd->cmd.command = SWAP16(CMD_FLEX | CmdTx);
tx_cmd->skb = skb;
tx_cmd->pad = 0;
tx_cmd->size = 0;
tbd->pad = 0;
tbd->size = SWAP16(EOF | length);
tx_cmd->dma_addr = dma_map_single(dev->dev.parent, skb->data,
skb->len, DMA_TO_DEVICE);
tbd->data = SWAP32(tx_cmd->dma_addr);
DEB(DEB_TXADDR, print_eth(skb->data, "tx-queued"));
DMA_WBACK_INV(dev, tx_cmd, sizeof(struct tx_cmd));
DMA_WBACK_INV(dev, tbd, sizeof(struct i596_tbd));
i596_add_cmd(dev, &tx_cmd->cmd);
dev->stats.tx_packets++;
dev->stats.tx_bytes += length;
}
netif_start_queue(dev);
return NETDEV_TX_OK;
}
static void print_eth(unsigned char *add, char *str)
{
printk(KERN_DEBUG "i596 0x%p, %pM --> %pM %02X%02X, %s\n",
add, add + 6, add, add[12], add[13], str);
}
static int i82596_probe(struct net_device *dev)
{
int i;
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma;
BUILD_BUG_ON(sizeof(struct i596_rfd) != 32);
BUILD_BUG_ON(sizeof(struct i596_rbd) & 31);
BUILD_BUG_ON(sizeof(struct tx_cmd) & 31);
BUILD_BUG_ON(sizeof(struct i596_tbd) != 32);
#ifndef __LP64__
BUILD_BUG_ON(sizeof(struct i596_dma) > 4096);
#endif
if (!dev->base_addr || !dev->irq)
return -ENODEV;
dma = (struct i596_dma *) DMA_ALLOC(dev->dev.parent,
sizeof(struct i596_dma), &lp->dma_addr, GFP_KERNEL);
if (!dma) {
printk(KERN_ERR "%s: Couldn't get shared memory\n", __FILE__);
return -ENOMEM;
}
dev->netdev_ops = &i596_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
memset(dma, 0, sizeof(struct i596_dma));
lp->dma = dma;
dma->scb.command = 0;
dma->scb.cmd = I596_NULL;
dma->scb.rfd = I596_NULL;
spin_lock_init(&lp->lock);
DMA_WBACK_INV(dev, dma, sizeof(struct i596_dma));
i = register_netdev(dev);
if (i) {
DMA_FREE(dev->dev.parent, sizeof(struct i596_dma),
(void *)dma, lp->dma_addr);
return i;
}
DEB(DEB_PROBE, printk(KERN_INFO "%s: 82596 at %#3lx, %pM IRQ %d.\n",
dev->name, dev->base_addr, dev->dev_addr,
dev->irq));
DEB(DEB_INIT, printk(KERN_INFO
"%s: dma at 0x%p (%d bytes), lp->scb at 0x%p\n",
dev->name, dma, (int)sizeof(struct i596_dma),
&dma->scb));
return 0;
}
static void i596_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
i596_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static irqreturn_t i596_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct i596_private *lp;
struct i596_dma *dma;
unsigned short status, ack_cmd = 0;
lp = netdev_priv(dev);
dma = lp->dma;
spin_lock (&lp->lock);
wait_cmd(dev, dma, 100, "i596 interrupt, timeout");
status = SWAP16(dma->scb.status);
DEB(DEB_INTS, printk(KERN_DEBUG
"%s: i596 interrupt, IRQ %d, status %4.4x.\n",
dev->name, dev->irq, status));
ack_cmd = status & 0xf000;
if (!ack_cmd) {
DEB(DEB_ERRORS, printk(KERN_DEBUG
"%s: interrupt with no events\n",
dev->name));
spin_unlock (&lp->lock);
return IRQ_NONE;
}
if ((status & 0x8000) || (status & 0x2000)) {
struct i596_cmd *ptr;
if ((status & 0x8000))
DEB(DEB_INTS,
printk(KERN_DEBUG
"%s: i596 interrupt completed command.\n",
dev->name));
if ((status & 0x2000))
DEB(DEB_INTS,
printk(KERN_DEBUG
"%s: i596 interrupt command unit inactive %x.\n",
dev->name, status & 0x0700));
while (lp->cmd_head != NULL) {
DMA_INV(dev, lp->cmd_head, sizeof(struct i596_cmd));
if (!(lp->cmd_head->status & SWAP16(STAT_C)))
break;
ptr = lp->cmd_head;
DEB(DEB_STATUS,
printk(KERN_DEBUG
"cmd_head->status = %04x, ->command = %04x\n",
SWAP16(lp->cmd_head->status),
SWAP16(lp->cmd_head->command)));
lp->cmd_head = ptr->v_next;
lp->cmd_backlog--;
switch (SWAP16(ptr->command) & 0x7) {
case CmdTx:
{
struct tx_cmd *tx_cmd = (struct tx_cmd *) ptr;
struct sk_buff *skb = tx_cmd->skb;
if (ptr->status & SWAP16(STAT_OK)) {
DEB(DEB_TXADDR,
print_eth(skb->data, "tx-done"));
} else {
dev->stats.tx_errors++;
if (ptr->status & SWAP16(0x0020))
dev->stats.collisions++;
if (!(ptr->status & SWAP16(0x0040)))
dev->stats.tx_heartbeat_errors++;
if (ptr->status & SWAP16(0x0400))
dev->stats.tx_carrier_errors++;
if (ptr->status & SWAP16(0x0800))
dev->stats.collisions++;
if (ptr->status & SWAP16(0x1000))
dev->stats.tx_aborted_errors++;
}
dma_unmap_single(dev->dev.parent,
tx_cmd->dma_addr,
skb->len, DMA_TO_DEVICE);
dev_kfree_skb_irq(skb);
tx_cmd->cmd.command = 0;
break;
}
case CmdTDR:
{
unsigned short status = SWAP16(((struct tdr_cmd *)ptr)->status);
if (status & 0x8000) {
DEB(DEB_ANY,
printk(KERN_DEBUG "%s: link ok.\n",
dev->name));
} else {
if (status & 0x4000)
printk(KERN_ERR
"%s: Transceiver problem.\n",
dev->name);
if (status & 0x2000)
printk(KERN_ERR
"%s: Termination problem.\n",
dev->name);
if (status & 0x1000)
printk(KERN_ERR
"%s: Short circuit.\n",
dev->name);
DEB(DEB_TDR,
printk(KERN_DEBUG "%s: Time %d.\n",
dev->name, status & 0x07ff));
}
break;
}
case CmdConfigure:
ptr->command = 0;
break;
}
ptr->v_next = NULL;
ptr->b_next = I596_NULL;
DMA_WBACK(dev, ptr, sizeof(struct i596_cmd));
lp->last_cmd = jiffies;
}
ptr = lp->cmd_head;
while ((ptr != NULL) && (ptr != lp->cmd_tail)) {
struct i596_cmd *prev = ptr;
ptr->command &= SWAP16(0x1fff);
ptr = ptr->v_next;
DMA_WBACK_INV(dev, prev, sizeof(struct i596_cmd));
}
if (lp->cmd_head != NULL)
ack_cmd |= CUC_START;
dma->scb.cmd = SWAP32(virt_to_dma(lp, &lp->cmd_head->status));
DMA_WBACK_INV(dev, &dma->scb, sizeof(struct i596_scb));
}
if ((status & 0x1000) || (status & 0x4000)) {
if ((status & 0x4000))
DEB(DEB_INTS,
printk(KERN_DEBUG
"%s: i596 interrupt received a frame.\n",
dev->name));
i596_rx(dev);
if (status & 0x1000) {
if (netif_running(dev)) {
DEB(DEB_ERRORS,
printk(KERN_DEBUG
"%s: i596 interrupt receive unit inactive, status 0x%x\n",
dev->name, status));
ack_cmd |= RX_START;
dev->stats.rx_errors++;
dev->stats.rx_fifo_errors++;
rebuild_rx_bufs(dev);
}
}
}
wait_cmd(dev, dma, 100, "i596 interrupt, timeout");
dma->scb.command = SWAP16(ack_cmd);
DMA_WBACK(dev, &dma->scb, sizeof(struct i596_scb));
ca(dev);
wait_cmd(dev, dma, 100, "i596 interrupt, exit timeout");
DEB(DEB_INTS, printk(KERN_DEBUG "%s: exiting interrupt.\n", dev->name));
spin_unlock (&lp->lock);
return IRQ_HANDLED;
}
static int i596_close(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
unsigned long flags;
netif_stop_queue(dev);
DEB(DEB_INIT,
printk(KERN_DEBUG
"%s: Shutting down ethercard, status was %4.4x.\n",
dev->name, SWAP16(lp->dma->scb.status)));
spin_lock_irqsave(&lp->lock, flags);
wait_cmd(dev, lp->dma, 100, "close1 timed out");
lp->dma->scb.command = SWAP16(CUC_ABORT | RX_ABORT);
DMA_WBACK(dev, &lp->dma->scb, sizeof(struct i596_scb));
ca(dev);
wait_cmd(dev, lp->dma, 100, "close2 timed out");
spin_unlock_irqrestore(&lp->lock, flags);
DEB(DEB_STRUCT, i596_display_data(dev));
i596_cleanup_cmd(dev, lp);
free_irq(dev->irq, dev);
remove_rx_bufs(dev);
return 0;
}
static void set_multicast_list(struct net_device *dev)
{
struct i596_private *lp = netdev_priv(dev);
struct i596_dma *dma = lp->dma;
int config = 0, cnt;
DEB(DEB_MULTI,
printk(KERN_DEBUG
"%s: set multicast list, %d entries, promisc %s, allmulti %s\n",
dev->name, netdev_mc_count(dev),
dev->flags & IFF_PROMISC ? "ON" : "OFF",
dev->flags & IFF_ALLMULTI ? "ON" : "OFF"));
if ((dev->flags & IFF_PROMISC) &&
!(dma->cf_cmd.i596_config[8] & 0x01)) {
dma->cf_cmd.i596_config[8] |= 0x01;
config = 1;
}
if (!(dev->flags & IFF_PROMISC) &&
(dma->cf_cmd.i596_config[8] & 0x01)) {
dma->cf_cmd.i596_config[8] &= ~0x01;
config = 1;
}
if ((dev->flags & IFF_ALLMULTI) &&
(dma->cf_cmd.i596_config[11] & 0x20)) {
dma->cf_cmd.i596_config[11] &= ~0x20;
config = 1;
}
if (!(dev->flags & IFF_ALLMULTI) &&
!(dma->cf_cmd.i596_config[11] & 0x20)) {
dma->cf_cmd.i596_config[11] |= 0x20;
config = 1;
}
if (config) {
if (dma->cf_cmd.cmd.command)
printk(KERN_INFO
"%s: config change request already queued\n",
dev->name);
else {
dma->cf_cmd.cmd.command = SWAP16(CmdConfigure);
DMA_WBACK_INV(dev, &dma->cf_cmd, sizeof(struct cf_cmd));
i596_add_cmd(dev, &dma->cf_cmd.cmd);
}
}
cnt = netdev_mc_count(dev);
if (cnt > MAX_MC_CNT) {
cnt = MAX_MC_CNT;
printk(KERN_NOTICE "%s: Only %d multicast addresses supported",
dev->name, cnt);
}
if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
unsigned char *cp;
struct mc_cmd *cmd;
cmd = &dma->mc_cmd;
cmd->cmd.command = SWAP16(CmdMulticastList);
cmd->mc_cnt = SWAP16(netdev_mc_count(dev) * 6);
cp = cmd->mc_addrs;
netdev_for_each_mc_addr(ha, dev) {
if (!cnt--)
break;
memcpy(cp, ha->addr, 6);
if (i596_debug > 1)
DEB(DEB_MULTI,
printk(KERN_DEBUG
"%s: Adding address %pM\n",
dev->name, cp));
cp += 6;
}
DMA_WBACK_INV(dev, &dma->mc_cmd, sizeof(struct mc_cmd));
i596_add_cmd(dev, &cmd->cmd);
}
}
