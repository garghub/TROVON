static inline phys_addr
va_to_pa(void *x) {
return x ? virt_to_bus(x) : I596_NULL;
}
static inline void *
pa_to_va(phys_addr x) {
return (x == I596_NULL) ? NULL : bus_to_virt(x);
}
static int
i596_timeout(struct net_device *dev, char *msg, int ct) {
struct i596_private *lp;
int boguscnt = ct;
lp = netdev_priv(dev);
while (lp->scb.command) {
if (--boguscnt == 0) {
printk("%s: %s timed out - stat %4.4x, cmd %4.4x\n",
dev->name, msg,
lp->scb.status, lp->scb.command);
return 1;
}
udelay(5);
barrier();
}
return 0;
}
static inline int
init_rx_bufs(struct net_device *dev, int num) {
struct i596_private *lp;
struct i596_rfd *rfd;
int i;
lp = netdev_priv(dev);
lp->scb.pa_rfd = I596_NULL;
for (i = 0; i < num; i++) {
rfd = kmalloc(sizeof(struct i596_rfd), GFP_KERNEL);
if (rfd == NULL)
break;
rfd->stat = 0;
rfd->pa_rbd = I596_NULL;
rfd->count = 0;
rfd->size = 1532;
if (i == 0) {
rfd->cmd = CMD_EOL;
lp->rx_tail = rfd;
} else {
rfd->cmd = 0;
}
rfd->pa_next = lp->scb.pa_rfd;
lp->scb.pa_rfd = va_to_pa(rfd);
lp->rx_tail->pa_next = lp->scb.pa_rfd;
}
#if 0
for (i = 0; i<RX_RBD_SIZE; i++) {
rbd = kmalloc(sizeof(struct i596_rbd), GFP_KERNEL);
if (rbd) {
rbd->pad = 0;
rbd->count = 0;
rbd->skb = dev_alloc_skb(RX_SKBSIZE);
if (!rbd->skb) {
printk("dev_alloc_skb failed");
}
rbd->next = rfd->rbd;
if (i) {
rfd->rbd->prev = rbd;
rbd->size = RX_SKBSIZE;
} else {
rbd->size = (RX_SKBSIZE | RBD_EL);
lp->rbd_tail = rbd;
}
rfd->rbd = rbd;
}
}
lp->rbd_tail->next = rfd->rbd;
#endif
return i;
}
static inline void
remove_rx_bufs(struct net_device *dev) {
struct i596_private *lp;
struct i596_rfd *rfd;
lp = netdev_priv(dev);
lp->rx_tail->pa_next = I596_NULL;
do {
rfd = pa_to_va(lp->scb.pa_rfd);
lp->scb.pa_rfd = rfd->pa_next;
kfree(rfd);
} while (rfd != lp->rx_tail);
lp->rx_tail = NULL;
#if 0
for (lp->rbd_list) {
}
#endif
}
static inline void
PORT(phys_addr a, unsigned int cmd) {
if (a & 0xf)
printk("lp486e.c: PORT: address not aligned\n");
outw(((a & 0xffff) | cmd), IOADDR);
outw(((a>>16) & 0xffff), IOADDR+2);
}
static inline void
CA(void) {
outb(0, IOADDR+4);
udelay(8);
}
static inline void
CLEAR_INT(void) {
outb(0, IOADDR+8);
}
static int
i596_scp_setup(struct net_device *dev) {
struct i596_private *lp = netdev_priv(dev);
int boguscnt;
lp->scp.sysbus = 0x00440000;
lp->scp.pad = 0;
lp->scp.pa_iscp = va_to_pa(&(lp->iscp));
lp->iscp.busy = 0x0001;
lp->iscp.pa_scb = va_to_pa(&(lp->scb));
lp->scb.command = 0;
lp->scb.status = 0;
lp->scb.pa_cmd = I596_NULL;
lp->last_cmd = jiffies;
lp->cmd_backlog = 0;
lp->cmd_head = NULL;
PORT(0, PORT_RESET);
udelay(100);
PORT(va_to_pa(&lp->scp), PORT_ALTSCP);
CA();
boguscnt = 100;
while (lp->iscp.busy) {
if (--boguscnt == 0) {
printk("%s: i82596 initialization timed out\n",
dev->name);
return 1;
}
udelay(5);
barrier();
}
return 0;
}
static int
init_i596(struct net_device *dev) {
struct i596_private *lp;
if (i596_scp_setup(dev))
return 1;
lp = netdev_priv(dev);
lp->scb.command = 0;
memcpy ((void *)lp->i596_config, init_setup, 14);
lp->set_conf.command = CmdConfigure;
i596_add_cmd(dev, (void *)&lp->set_conf);
memcpy ((void *)lp->eth_addr, dev->dev_addr, 6);
lp->set_add.command = CmdIASetup;
i596_add_cmd(dev, (struct i596_cmd *)&lp->set_add);
lp->tdr.command = CmdTDR;
i596_add_cmd(dev, (struct i596_cmd *)&lp->tdr);
if (lp->scb.command && i596_timeout(dev, "i82596 init", 200))
return 1;
lp->scb.command = RX_START;
CA();
barrier();
if (lp->scb.command && i596_timeout(dev, "Receive Unit start", 100))
return 1;
return 0;
}
static inline int
i596_rx_one(struct net_device *dev, struct i596_private *lp,
struct i596_rfd *rfd, int *frames) {
if (rfd->stat & RFD_STAT_OK) {
int pkt_len = (rfd->count & 0x3fff);
struct sk_buff *skb = netdev_alloc_skb(dev, pkt_len);
(*frames)++;
if (rfd->cmd & CMD_EOL)
printk("Received on EOL\n");
if (skb == NULL) {
printk ("%s: i596_rx Memory squeeze, "
"dropping packet.\n", dev->name);
dev->stats.rx_dropped++;
return 1;
}
memcpy(skb_put(skb,pkt_len), rfd->data, pkt_len);
skb->protocol = eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_packets++;
} else {
#if 0
printk("Frame reception error status %04x\n",
rfd->stat);
#endif
dev->stats.rx_errors++;
if (rfd->stat & RFD_COLLISION)
dev->stats.collisions++;
if (rfd->stat & RFD_SHORT_FRAME_ERR)
dev->stats.rx_length_errors++;
if (rfd->stat & RFD_DMA_ERR)
dev->stats.rx_over_errors++;
if (rfd->stat & RFD_NOBUFS_ERR)
dev->stats.rx_fifo_errors++;
if (rfd->stat & RFD_ALIGN_ERR)
dev->stats.rx_frame_errors++;
if (rfd->stat & RFD_CRC_ERR)
dev->stats.rx_crc_errors++;
if (rfd->stat & RFD_LENGTH_ERR)
dev->stats.rx_length_errors++;
}
rfd->stat = rfd->count = 0;
return 0;
}
static int
i596_rx(struct net_device *dev) {
struct i596_private *lp = netdev_priv(dev);
struct i596_rfd *rfd;
int frames = 0;
while (1) {
rfd = pa_to_va(lp->scb.pa_rfd);
if (!rfd) {
printk(KERN_ERR "i596_rx: NULL rfd?\n");
return 0;
}
#if 1
if (rfd->stat && !(rfd->stat & (RFD_STAT_C | RFD_STAT_B)))
printk("SF:%p-%04x\n", rfd, rfd->stat);
#endif
if (!(rfd->stat & RFD_STAT_C))
break;
if (i596_rx_one(dev, lp, rfd, &frames))
break;
rfd->cmd = CMD_EOL;
lp->rx_tail->cmd = 0;
lp->rx_tail = rfd;
lp->scb.pa_rfd = rfd->pa_next;
barrier();
}
return frames;
}
static void
i596_cleanup_cmd(struct net_device *dev) {
struct i596_private *lp;
struct i596_cmd *cmd;
lp = netdev_priv(dev);
while (lp->cmd_head) {
cmd = (struct i596_cmd *)lp->cmd_head;
lp->cmd_head = pa_to_va(lp->cmd_head->pa_next);
lp->cmd_backlog--;
switch ((cmd->command) & 0x7) {
case CmdTx: {
struct tx_cmd *tx_cmd = (struct tx_cmd *) cmd;
struct i596_tbd * tx_cmd_tbd;
tx_cmd_tbd = pa_to_va(tx_cmd->pa_tbd);
dev_kfree_skb_any(tx_cmd_tbd->skb);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
cmd->pa_next = I596_NULL;
kfree((unsigned char *)tx_cmd);
netif_wake_queue(dev);
break;
}
case CmdMulticastList: {
cmd->pa_next = I596_NULL;
kfree((unsigned char *)cmd);
break;
}
default: {
cmd->pa_next = I596_NULL;
break;
}
}
barrier();
}
if (lp->scb.command && i596_timeout(dev, "i596_cleanup_cmd", 100))
;
lp->scb.pa_cmd = va_to_pa(lp->cmd_head);
}
static void i596_reset(struct net_device *dev, struct i596_private *lp, int ioaddr) {
if (lp->scb.command && i596_timeout(dev, "i596_reset", 100))
;
netif_stop_queue(dev);
lp->scb.command = CUC_ABORT | RX_ABORT;
CA();
barrier();
if (lp->scb.command && i596_timeout(dev, "i596_reset(2)", 400))
;
i596_cleanup_cmd(dev);
i596_rx(dev);
netif_start_queue(dev);
init_i596(dev);
}
static void i596_add_cmd(struct net_device *dev, struct i596_cmd *cmd) {
struct i596_private *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned long flags;
cmd->status = 0;
cmd->command |= (CMD_EOL | CMD_INTR);
cmd->pa_next = I596_NULL;
spin_lock_irqsave(&lp->cmd_lock, flags);
if (lp->cmd_head) {
lp->cmd_tail->pa_next = va_to_pa(cmd);
} else {
lp->cmd_head = cmd;
if (lp->scb.command && i596_timeout(dev, "i596_add_cmd", 100))
;
lp->scb.pa_cmd = va_to_pa(cmd);
lp->scb.command = CUC_START;
CA();
}
lp->cmd_tail = cmd;
lp->cmd_backlog++;
lp->cmd_head = pa_to_va(lp->scb.pa_cmd);
spin_unlock_irqrestore(&lp->cmd_lock, flags);
if (lp->cmd_backlog > 16) {
int tickssofar = jiffies - lp->last_cmd;
if (tickssofar < HZ/4)
return;
printk(KERN_WARNING "%s: command unit timed out, status resetting.\n", dev->name);
i596_reset(dev, lp, ioaddr);
}
}
static int i596_open(struct net_device *dev)
{
int i;
i = request_irq(dev->irq, i596_interrupt, IRQF_SHARED, dev->name, dev);
if (i) {
printk(KERN_ERR "%s: IRQ %d not free\n", dev->name, dev->irq);
return i;
}
if ((i = init_rx_bufs(dev, RX_RING_SIZE)) < RX_RING_SIZE)
printk(KERN_ERR "%s: only able to allocate %d receive buffers\n", dev->name, i);
if (i < 4) {
free_irq(dev->irq, dev);
return -EAGAIN;
}
netif_start_queue(dev);
init_i596(dev);
return 0;
}
static netdev_tx_t i596_start_xmit (struct sk_buff *skb, struct net_device *dev) {
struct tx_cmd *tx_cmd;
short length;
length = skb->len;
if (length < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
tx_cmd = kmalloc((sizeof (struct tx_cmd) + sizeof (struct i596_tbd)), GFP_ATOMIC);
if (tx_cmd == NULL) {
printk(KERN_WARNING "%s: i596_xmit Memory squeeze, dropping packet.\n", dev->name);
dev->stats.tx_dropped++;
dev_kfree_skb (skb);
} else {
struct i596_tbd *tx_cmd_tbd;
tx_cmd_tbd = (struct i596_tbd *) (tx_cmd + 1);
tx_cmd->pa_tbd = va_to_pa (tx_cmd_tbd);
tx_cmd_tbd->pa_next = I596_NULL;
tx_cmd->cmd.command = (CMD_FLEX | CmdTx);
tx_cmd->pad = 0;
tx_cmd->size = 0;
tx_cmd_tbd->pad = 0;
tx_cmd_tbd->size = (EOF | length);
tx_cmd_tbd->pa_data = va_to_pa (skb->data);
tx_cmd_tbd->skb = skb;
if (i596_debug & LOG_SRCDST)
print_eth (skb->data);
i596_add_cmd (dev, (struct i596_cmd *) tx_cmd);
dev->stats.tx_packets++;
}
return NETDEV_TX_OK;
}
static void
i596_tx_timeout (struct net_device *dev) {
struct i596_private *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
printk(KERN_WARNING "%s: transmit timed out, status resetting.\n", dev->name);
dev->stats.tx_errors++;
if (lp->last_restart == dev->stats.tx_packets) {
printk ("Resetting board.\n");
i596_reset (dev, lp, ioaddr);
} else {
printk ("Kicking board.\n");
lp->scb.command = (CUC_START | RX_START);
CA();
lp->last_restart = dev->stats.tx_packets;
}
netif_wake_queue(dev);
}
static void print_eth(char *add)
{
int i;
printk ("Dest ");
for (i = 0; i < 6; i++)
printk(" %2.2X", (unsigned char) add[i]);
printk ("\n");
printk ("Source");
for (i = 0; i < 6; i++)
printk(" %2.2X", (unsigned char) add[i+6]);
printk ("\n");
printk ("type %2.2X%2.2X\n",
(unsigned char) add[12], (unsigned char) add[13]);
}
static int __init lp486e_probe(struct net_device *dev) {
struct i596_private *lp;
unsigned char eth_addr[6] = { 0, 0xaa, 0, 0, 0, 0 };
unsigned char *bios;
int i, j;
int ret = -ENOMEM;
static int probed;
if (probed)
return -ENODEV;
probed++;
if (!request_region(IOADDR, LP486E_TOTAL_SIZE, DRV_NAME)) {
printk(KERN_ERR "lp486e: IO address 0x%x in use\n", IOADDR);
return -EBUSY;
}
lp = netdev_priv(dev);
spin_lock_init(&lp->cmd_lock);
if (i596_scp_setup(dev)) {
ret = -ENODEV;
goto err_out_kfree;
}
dev->base_addr = IOADDR;
dev->irq = IRQ;
bios = bus_to_virt(0xe8000);
for (j = 0; j < 0x2000; j++) {
if (bios[j] == 0 && bios[j+1] == 0xaa && bios[j+2] == 0) {
printk("%s: maybe address at BIOS 0x%x:",
dev->name, 0xe8000+j);
for (i = 0; i < 6; i++) {
eth_addr[i] = bios[i+j];
printk(" %2.2X", eth_addr[i]);
}
printk("\n");
}
}
printk("%s: lp486e 82596 at %#3lx, IRQ %d,",
dev->name, dev->base_addr, dev->irq);
for (i = 0; i < 6; i++)
printk(" %2.2X", dev->dev_addr[i] = eth_addr[i]);
printk("\n");
dev->netdev_ops = &i596_netdev_ops;
dev->watchdog_timeo = 5*HZ;
#if 0
i596_port_do(dev, PORT_SELFTEST, "selftest");
i596_port_do(dev, PORT_DUMP, "dump");
#endif
return 0;
err_out_kfree:
release_region(IOADDR, LP486E_TOTAL_SIZE);
return ret;
}
static inline void
i596_handle_CU_completion(struct net_device *dev,
struct i596_private *lp,
unsigned short status,
unsigned short *ack_cmdp) {
struct i596_cmd *cmd;
int frames_out = 0;
int commands_done = 0;
int cmd_val;
unsigned long flags;
spin_lock_irqsave(&lp->cmd_lock, flags);
cmd = lp->cmd_head;
while (lp->cmd_head && (lp->cmd_head->status & CMD_STAT_C)) {
cmd = lp->cmd_head;
lp->cmd_head = pa_to_va(lp->cmd_head->pa_next);
lp->cmd_backlog--;
commands_done++;
cmd_val = cmd->command & 0x7;
#if 0
printk("finished CU %s command (%d)\n",
CUcmdnames[cmd_val], cmd_val);
#endif
switch (cmd_val) {
case CmdTx:
{
struct tx_cmd *tx_cmd;
struct i596_tbd *tx_cmd_tbd;
tx_cmd = (struct tx_cmd *) cmd;
tx_cmd_tbd = pa_to_va(tx_cmd->pa_tbd);
frames_out++;
if (cmd->status & CMD_STAT_OK) {
if (i596_debug)
print_eth(pa_to_va(tx_cmd_tbd->pa_data));
} else {
dev->stats.tx_errors++;
if (i596_debug)
printk("transmission failure:%04x\n",
cmd->status);
if (cmd->status & 0x0020)
dev->stats.collisions++;
if (!(cmd->status & 0x0040))
dev->stats.tx_heartbeat_errors++;
if (cmd->status & 0x0400)
dev->stats.tx_carrier_errors++;
if (cmd->status & 0x0800)
dev->stats.collisions++;
if (cmd->status & 0x1000)
dev->stats.tx_aborted_errors++;
}
dev_kfree_skb_irq(tx_cmd_tbd->skb);
cmd->pa_next = I596_NULL;
kfree((unsigned char *)tx_cmd);
netif_wake_queue(dev);
break;
}
case CmdMulticastList:
cmd->pa_next = I596_NULL;
kfree((unsigned char *)cmd);
break;
case CmdTDR:
{
unsigned long status = *((unsigned long *) (cmd + 1));
if (status & 0x8000) {
if (i596_debug)
printk("%s: link ok.\n", dev->name);
} else {
if (status & 0x4000)
printk("%s: Transceiver problem.\n",
dev->name);
if (status & 0x2000)
printk("%s: Termination problem.\n",
dev->name);
if (status & 0x1000)
printk("%s: Short circuit.\n",
dev->name);
printk("%s: Time %ld.\n",
dev->name, status & 0x07ff);
}
}
default:
cmd->pa_next = I596_NULL;
lp->last_cmd = jiffies;
}
barrier();
}
cmd = lp->cmd_head;
while (cmd && (cmd != lp->cmd_tail)) {
cmd->command &= 0x1fff;
cmd = pa_to_va(cmd->pa_next);
barrier();
}
if (lp->cmd_head)
*ack_cmdp |= CUC_START;
lp->scb.pa_cmd = va_to_pa(lp->cmd_head);
spin_unlock_irqrestore(&lp->cmd_lock, flags);
}
static irqreturn_t
i596_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct i596_private *lp = netdev_priv(dev);
unsigned short status, ack_cmd = 0;
int frames_in = 0;
if (lp->scb.command && i596_timeout(dev, "interrupt", 40))
;
status = lp->scb.status;
#if 0
if (i596_debug) {
printk("%s: i596 interrupt, ", dev->name);
i596_out_status(status);
}
#endif
if (status == 0xffff) {
printk("%s: i596_interrupt: got status 0xffff\n", dev->name);
goto out;
}
ack_cmd = (status & STAT_ACK);
if (status & (STAT_CX | STAT_CNA))
i596_handle_CU_completion(dev, lp, status, &ack_cmd);
if (status & (STAT_FR | STAT_RNR)) {
if ((status & STAT_RNR) && netif_running(dev))
ack_cmd |= RX_START;
if (status & STAT_FR) {
frames_in = i596_rx(dev);
if (!frames_in)
printk("receive frame reported, but no frames\n");
}
}
if (lp->scb.command && i596_timeout(dev, "i596 interrupt", 100))
;
lp->scb.command = ack_cmd;
CLEAR_INT();
CA();
out:
return IRQ_HANDLED;
}
static int i596_close(struct net_device *dev) {
struct i596_private *lp = netdev_priv(dev);
netif_stop_queue(dev);
if (i596_debug)
printk("%s: Shutting down ethercard, status was %4.4x.\n",
dev->name, lp->scb.status);
lp->scb.command = (CUC_ABORT | RX_ABORT);
CA();
i596_cleanup_cmd(dev);
if (lp->scb.command && i596_timeout(dev, "i596_close", 200))
;
free_irq(dev->irq, dev);
remove_rx_bufs(dev);
return 0;
}
static void set_multicast_list(struct net_device *dev) {
struct i596_private *lp = netdev_priv(dev);
struct i596_cmd *cmd;
if (i596_debug > 1)
printk ("%s: set multicast list %d\n",
dev->name, netdev_mc_count(dev));
if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
char *cp;
cmd = kmalloc(sizeof(struct i596_cmd) + 2 +
netdev_mc_count(dev) * 6, GFP_ATOMIC);
if (cmd == NULL) {
printk (KERN_ERR "%s: set_multicast Memory squeeze.\n", dev->name);
return;
}
cmd->command = CmdMulticastList;
*((unsigned short *) (cmd + 1)) = netdev_mc_count(dev) * 6;
cp = ((char *)(cmd + 1))+2;
netdev_for_each_mc_addr(ha, dev) {
memcpy(cp, ha->addr, 6);
cp += 6;
}
if (i596_debug & LOG_SRCDST)
print_eth (((char *)(cmd + 1)) + 2);
i596_add_cmd(dev, cmd);
} else {
if (lp->set_conf.pa_next != I596_NULL) {
return;
}
if (netdev_mc_empty(dev) &&
!(dev->flags & (IFF_PROMISC | IFF_ALLMULTI))) {
lp->i596_config[8] &= ~0x01;
} else {
lp->i596_config[8] |= 0x01;
}
i596_add_cmd(dev, (struct i596_cmd *) &lp->set_conf);
}
}
static int __init lp486e_init_module(void) {
int err;
struct net_device *dev = alloc_etherdev(sizeof(struct i596_private));
if (!dev)
return -ENOMEM;
dev->irq = irq;
dev->base_addr = io;
err = lp486e_probe(dev);
if (err) {
free_netdev(dev);
return err;
}
err = register_netdev(dev);
if (err) {
release_region(dev->base_addr, LP486E_TOTAL_SIZE);
free_netdev(dev);
return err;
}
dev_lp486e = dev;
full_duplex = 0;
options = 0;
return 0;
}
static void __exit lp486e_cleanup_module(void) {
unregister_netdev(dev_lp486e);
release_region(dev_lp486e->base_addr, LP486E_TOTAL_SIZE);
free_netdev(dev_lp486e);
}
