static inline void __init show_version (void) {
printk ("%s version %s\n", description_string, version_string);
}
static inline void wr_plain (const amb_dev * dev, size_t addr, u32 data) {
PRINTD (DBG_FLOW|DBG_REGS, "wr: %08zx <- %08x", addr, data);
#ifdef AMB_MMIO
dev->membase[addr / sizeof(u32)] = data;
#else
outl (data, dev->iobase + addr);
#endif
}
static inline u32 rd_plain (const amb_dev * dev, size_t addr) {
#ifdef AMB_MMIO
u32 data = dev->membase[addr / sizeof(u32)];
#else
u32 data = inl (dev->iobase + addr);
#endif
PRINTD (DBG_FLOW|DBG_REGS, "rd: %08zx -> %08x", addr, data);
return data;
}
static inline void wr_mem (const amb_dev * dev, size_t addr, u32 data) {
__be32 be = cpu_to_be32 (data);
PRINTD (DBG_FLOW|DBG_REGS, "wr: %08zx <- %08x b[%08x]", addr, data, be);
#ifdef AMB_MMIO
dev->membase[addr / sizeof(u32)] = be;
#else
outl (be, dev->iobase + addr);
#endif
}
static inline u32 rd_mem (const amb_dev * dev, size_t addr) {
#ifdef AMB_MMIO
__be32 be = dev->membase[addr / sizeof(u32)];
#else
__be32 be = inl (dev->iobase + addr);
#endif
u32 data = be32_to_cpu (be);
PRINTD (DBG_FLOW|DBG_REGS, "rd: %08zx -> %08x b[%08x]", addr, data, be);
return data;
}
static inline void dump_registers (const amb_dev * dev) {
#ifdef DEBUG_AMBASSADOR
if (debug & DBG_REGS) {
size_t i;
PRINTD (DBG_REGS, "reading PLX control: ");
for (i = 0x00; i < 0x30; i += sizeof(u32))
rd_mem (dev, i);
PRINTD (DBG_REGS, "reading mailboxes: ");
for (i = 0x40; i < 0x60; i += sizeof(u32))
rd_mem (dev, i);
PRINTD (DBG_REGS, "reading doorb irqev irqen reset:");
for (i = 0x60; i < 0x70; i += sizeof(u32))
rd_mem (dev, i);
}
#else
(void) dev;
#endif
return;
}
static inline void dump_loader_block (volatile loader_block * lb) {
#ifdef DEBUG_AMBASSADOR
unsigned int i;
PRINTDB (DBG_LOAD, "lb @ %p; res: %d, cmd: %d, pay:",
lb, be32_to_cpu (lb->result), be32_to_cpu (lb->command));
for (i = 0; i < MAX_COMMAND_DATA; ++i)
PRINTDM (DBG_LOAD, " %08x", be32_to_cpu (lb->payload.data[i]));
PRINTDE (DBG_LOAD, ", vld: %08x", be32_to_cpu (lb->valid));
#else
(void) lb;
#endif
return;
}
static inline void dump_command (command * cmd) {
#ifdef DEBUG_AMBASSADOR
unsigned int i;
PRINTDB (DBG_CMD, "cmd @ %p, req: %08x, pars:",
cmd, (cmd->request));
for (i = 0; i < 3; ++i)
PRINTDM (DBG_CMD, " %08x", (cmd->args.par[i]));
PRINTDE (DBG_CMD, "");
#else
(void) cmd;
#endif
return;
}
static inline void dump_skb (char * prefix, unsigned int vc, struct sk_buff * skb) {
#ifdef DEBUG_AMBASSADOR
unsigned int i;
unsigned char * data = skb->data;
PRINTDB (DBG_DATA, "%s(%u) ", prefix, vc);
for (i=0; i<skb->len && i < 256;i++)
PRINTDM (DBG_DATA, "%02x ", data[i]);
PRINTDE (DBG_DATA,"");
#else
(void) prefix;
(void) vc;
(void) skb;
#endif
return;
}
static int check_area (void * start, size_t length) {
const u32 fourmegmask = -1 << 22;
const u32 twofivesixmask = -1 << 8;
const u32 starthole = 0xE0000000;
u32 startaddress = virt_to_bus (start);
u32 lastaddress = startaddress+length-1;
if ((startaddress ^ lastaddress) & fourmegmask ||
(startaddress & twofivesixmask) == starthole) {
PRINTK (KERN_ERR, "check_area failure: [%x,%x] - mail maintainer!",
startaddress, lastaddress);
return -1;
} else {
return 0;
}
}
static void amb_kfree_skb (struct sk_buff * skb) {
if (ATM_SKB(skb)->vcc->pop) {
ATM_SKB(skb)->vcc->pop (ATM_SKB(skb)->vcc, skb);
} else {
dev_kfree_skb_any (skb);
}
}
static void tx_complete (amb_dev * dev, tx_out * tx) {
tx_simple * tx_descr = bus_to_virt (tx->handle);
struct sk_buff * skb = tx_descr->skb;
PRINTD (DBG_FLOW|DBG_TX, "tx_complete %p %p", dev, tx);
atomic_inc(&ATM_SKB(skb)->vcc->stats->tx);
kfree (tx_descr);
amb_kfree_skb (skb);
dev->stats.tx_ok++;
return;
}
static void rx_complete (amb_dev * dev, rx_out * rx) {
struct sk_buff * skb = bus_to_virt (rx->handle);
u16 vc = be16_to_cpu (rx->vc);
u16 status = be16_to_cpu (rx->status);
u16 rx_len = be16_to_cpu (rx->length);
PRINTD (DBG_FLOW|DBG_RX, "rx_complete %p %p (len=%hu)", dev, rx, rx_len);
if (!status) {
struct atm_vcc * atm_vcc = dev->rxer[vc];
dev->stats.rx.ok++;
if (atm_vcc) {
if (rx_len <= atm_vcc->qos.rxtp.max_sdu) {
if (atm_charge (atm_vcc, skb->truesize)) {
ATM_SKB(skb)->vcc = atm_vcc;
skb_put (skb, rx_len);
dump_skb ("<<<", vc, skb);
atomic_inc(&atm_vcc->stats->rx);
__net_timestamp(skb);
atm_vcc->push (atm_vcc, skb);
return;
} else {
PRINTD (DBG_INFO|DBG_RX, "dropped thanks to atm_charge (vc %hu, truesize %u)", vc, skb->truesize);
}
} else {
PRINTK (KERN_INFO, "dropped over-size frame");
atomic_inc(&atm_vcc->stats->rx_drop);
}
} else {
PRINTD (DBG_WARN|DBG_RX, "got frame but RX closed for channel %hu", vc);
}
} else {
dev->stats.rx.error++;
if (status & CRC_ERR)
dev->stats.rx.badcrc++;
if (status & LEN_ERR)
dev->stats.rx.toolong++;
if (status & ABORT_ERR)
dev->stats.rx.aborted++;
if (status & UNUSED_ERR)
dev->stats.rx.unused++;
}
dev_kfree_skb_any (skb);
return;
}
static int command_do (amb_dev * dev, command * cmd) {
amb_cq * cq = &dev->cq;
volatile amb_cq_ptrs * ptrs = &cq->ptrs;
command * my_slot;
PRINTD (DBG_FLOW|DBG_CMD, "command_do %p", dev);
if (test_bit (dead, &dev->flags))
return 0;
spin_lock (&cq->lock);
if (cq->pending < cq->maximum) {
my_slot = ptrs->in;
PRINTD (DBG_CMD, "command in slot %p", my_slot);
dump_command (cmd);
*ptrs->in = *cmd;
cq->pending++;
ptrs->in = NEXTQ (ptrs->in, ptrs->start, ptrs->limit);
wr_mem (dev, offsetof(amb_mem, mb.adapter.cmd_address), virt_to_bus (ptrs->in));
if (cq->pending > cq->high)
cq->high = cq->pending;
spin_unlock (&cq->lock);
msleep(cq->pending);
while (ptrs->out != my_slot) {
PRINTD (DBG_CMD, "wait: command slot (now at %p)", ptrs->out);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
while (ptrs->out->request != cpu_to_be32 (SRB_COMPLETE)) {
PRINTD (DBG_CMD, "wait: command slot completion");
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
PRINTD (DBG_CMD, "command complete");
spin_lock (&cq->lock);
cq->pending--;
*cmd = *ptrs->out;
ptrs->out = NEXTQ (ptrs->out, ptrs->start, ptrs->limit);
spin_unlock (&cq->lock);
return 0;
} else {
cq->filled++;
spin_unlock (&cq->lock);
return -EAGAIN;
}
}
static int tx_give (amb_dev * dev, tx_in * tx) {
amb_txq * txq = &dev->txq;
unsigned long flags;
PRINTD (DBG_FLOW|DBG_TX, "tx_give %p", dev);
if (test_bit (dead, &dev->flags))
return 0;
spin_lock_irqsave (&txq->lock, flags);
if (txq->pending < txq->maximum) {
PRINTD (DBG_TX, "TX in slot %p", txq->in.ptr);
*txq->in.ptr = *tx;
txq->pending++;
txq->in.ptr = NEXTQ (txq->in.ptr, txq->in.start, txq->in.limit);
wr_mem (dev, offsetof(amb_mem, mb.adapter.tx_address), virt_to_bus (txq->in.ptr));
wr_mem (dev, offsetof(amb_mem, doorbell), TX_FRAME);
if (txq->pending > txq->high)
txq->high = txq->pending;
spin_unlock_irqrestore (&txq->lock, flags);
return 0;
} else {
txq->filled++;
spin_unlock_irqrestore (&txq->lock, flags);
return -EAGAIN;
}
}
static int tx_take (amb_dev * dev) {
amb_txq * txq = &dev->txq;
unsigned long flags;
PRINTD (DBG_FLOW|DBG_TX, "tx_take %p", dev);
spin_lock_irqsave (&txq->lock, flags);
if (txq->pending && txq->out.ptr->handle) {
tx_complete (dev, txq->out.ptr);
txq->out.ptr->handle = 0;
txq->pending--;
txq->out.ptr = NEXTQ (txq->out.ptr, txq->out.start, txq->out.limit);
spin_unlock_irqrestore (&txq->lock, flags);
return 0;
} else {
spin_unlock_irqrestore (&txq->lock, flags);
return -1;
}
}
static int rx_give (amb_dev * dev, rx_in * rx, unsigned char pool) {
amb_rxq * rxq = &dev->rxq[pool];
unsigned long flags;
PRINTD (DBG_FLOW|DBG_RX, "rx_give %p[%hu]", dev, pool);
spin_lock_irqsave (&rxq->lock, flags);
if (rxq->pending < rxq->maximum) {
PRINTD (DBG_RX, "RX in slot %p", rxq->in.ptr);
*rxq->in.ptr = *rx;
rxq->pending++;
rxq->in.ptr = NEXTQ (rxq->in.ptr, rxq->in.start, rxq->in.limit);
wr_mem (dev, offsetof(amb_mem, mb.adapter.rx_address[pool]), virt_to_bus (rxq->in.ptr));
spin_unlock_irqrestore (&rxq->lock, flags);
return 0;
} else {
spin_unlock_irqrestore (&rxq->lock, flags);
return -1;
}
}
static int rx_take (amb_dev * dev, unsigned char pool) {
amb_rxq * rxq = &dev->rxq[pool];
unsigned long flags;
PRINTD (DBG_FLOW|DBG_RX, "rx_take %p[%hu]", dev, pool);
spin_lock_irqsave (&rxq->lock, flags);
if (rxq->pending && (rxq->out.ptr->status || rxq->out.ptr->length)) {
rx_complete (dev, rxq->out.ptr);
rxq->out.ptr->status = 0;
rxq->out.ptr->length = 0;
rxq->pending--;
rxq->out.ptr = NEXTQ (rxq->out.ptr, rxq->out.start, rxq->out.limit);
if (rxq->pending < rxq->low)
rxq->low = rxq->pending;
spin_unlock_irqrestore (&rxq->lock, flags);
return 0;
} else {
if (!rxq->pending && rxq->buffers_wanted)
rxq->emptied++;
spin_unlock_irqrestore (&rxq->lock, flags);
return -1;
}
}
static void drain_rx_pool (amb_dev * dev, unsigned char pool) {
amb_rxq * rxq = &dev->rxq[pool];
PRINTD (DBG_FLOW|DBG_POOL, "drain_rx_pool %p %hu", dev, pool);
if (test_bit (dead, &dev->flags))
return;
if (rxq->pending > rxq->buffers_wanted) {
command cmd;
cmd.request = cpu_to_be32 (SRB_FLUSH_BUFFER_Q);
cmd.args.flush.flags = cpu_to_be32 (pool << SRB_POOL_SHIFT);
while (command_do (dev, &cmd))
schedule();
while (rxq->pending > rxq->buffers_wanted)
if (rx_take (dev, pool))
schedule();
}
return;
}
static void drain_rx_pools (amb_dev * dev) {
unsigned char pool;
PRINTD (DBG_FLOW|DBG_POOL, "drain_rx_pools %p", dev);
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
drain_rx_pool (dev, pool);
}
static void fill_rx_pool (amb_dev * dev, unsigned char pool,
gfp_t priority)
{
rx_in rx;
amb_rxq * rxq;
PRINTD (DBG_FLOW|DBG_POOL, "fill_rx_pool %p %hu %x", dev, pool, priority);
if (test_bit (dead, &dev->flags))
return;
rxq = &dev->rxq[pool];
while (rxq->pending < rxq->maximum && rxq->pending < rxq->buffers_wanted) {
struct sk_buff * skb = alloc_skb (rxq->buffer_size, priority);
if (!skb) {
PRINTD (DBG_SKB|DBG_POOL, "failed to allocate skb for RX pool %hu", pool);
return;
}
if (check_area (skb->data, skb->truesize)) {
dev_kfree_skb_any (skb);
return;
}
PRINTD (DBG_SKB, "allocated skb at %p, head %p, area %li",
skb, skb->head, (long) skb_end_offset(skb));
rx.handle = virt_to_bus (skb);
rx.host_address = cpu_to_be32 (virt_to_bus (skb->data));
if (rx_give (dev, &rx, pool))
dev_kfree_skb_any (skb);
}
return;
}
static void fill_rx_pools (amb_dev * dev) {
unsigned char pool;
PRINTD (DBG_FLOW|DBG_POOL, "fill_rx_pools %p", dev);
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
fill_rx_pool (dev, pool, GFP_ATOMIC);
return;
}
static void interrupts_on (amb_dev * dev) {
wr_plain (dev, offsetof(amb_mem, interrupt_control),
rd_plain (dev, offsetof(amb_mem, interrupt_control))
| AMB_INTERRUPT_BITS);
}
static void interrupts_off (amb_dev * dev) {
wr_plain (dev, offsetof(amb_mem, interrupt_control),
rd_plain (dev, offsetof(amb_mem, interrupt_control))
&~ AMB_INTERRUPT_BITS);
}
static irqreturn_t interrupt_handler(int irq, void *dev_id) {
amb_dev * dev = dev_id;
PRINTD (DBG_IRQ|DBG_FLOW, "interrupt_handler: %p", dev_id);
{
u32 interrupt = rd_plain (dev, offsetof(amb_mem, interrupt));
if (!interrupt) {
PRINTD (DBG_IRQ, "irq not for me: %d", irq);
return IRQ_NONE;
}
PRINTD (DBG_IRQ, "FYI: interrupt was %08x", interrupt);
wr_plain (dev, offsetof(amb_mem, interrupt), -1);
}
{
unsigned int irq_work = 0;
unsigned char pool;
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
while (!rx_take (dev, pool))
++irq_work;
while (!tx_take (dev))
++irq_work;
if (irq_work) {
fill_rx_pools (dev);
PRINTD (DBG_IRQ, "work done: %u", irq_work);
} else {
PRINTD (DBG_IRQ|DBG_WARN, "no work done");
}
}
PRINTD (DBG_IRQ|DBG_FLOW, "interrupt_handler done: %p", dev_id);
return IRQ_HANDLED;
}
static int make_rate (unsigned int rate, rounding r,
u16 * bits, unsigned int * actual) {
unsigned char exp = -1;
unsigned int man = -1;
PRINTD (DBG_FLOW|DBG_QOS, "make_rate %u", rate);
if (rate > 0xffc00000U) {
if (r == round_up) {
return -EINVAL;
} else {
exp = 31;
man = 511;
}
} else if (rate) {
exp = 31;
man = rate;
while (!(man & (1<<31))) {
exp = exp - 1;
man = man<<1;
}
man = man<<1;
man &= 0xffffffffU;
switch (r) {
case round_down: {
man = man>>(32-9);
break;
}
case round_up: {
if (man & (~0U>>9)) {
man = (man>>(32-9)) + 1;
if (man == (1<<9)) {
man = 0;
exp += 1;
}
} else {
man = (man>>(32-9));
}
break;
}
case round_nearest: {
if (man & (1<<(32-9-1))) {
man = (man>>(32-9)) + 1;
if (man == (1<<9)) {
man = 0;
exp += 1;
}
} else {
man = (man>>(32-9));
}
break;
}
}
} else {
if (r == round_down) {
return -EINVAL;
} else {
exp = 0;
man = 0;
}
}
PRINTD (DBG_QOS, "rate: man=%u, exp=%hu", man, exp);
if (bits)
*bits = (exp<<9) | man;
if (actual)
*actual = (exp >= 9)
? (1 << exp) + (man << (exp-9))
: (1 << exp) + ((man + (1<<(9-exp-1))) >> (9-exp));
return 0;
}
static int amb_open (struct atm_vcc * atm_vcc)
{
int error;
struct atm_qos * qos;
struct atm_trafprm * txtp;
struct atm_trafprm * rxtp;
u16 tx_rate_bits = -1;
u16 tx_vc_bits = -1;
u16 tx_frame_bits = -1;
amb_dev * dev = AMB_DEV(atm_vcc->dev);
amb_vcc * vcc;
unsigned char pool = -1;
short vpi = atm_vcc->vpi;
int vci = atm_vcc->vci;
PRINTD (DBG_FLOW|DBG_VCC, "amb_open %x %x", vpi, vci);
#ifdef ATM_VPI_UNSPEC
if (vpi == ATM_VPI_UNSPEC || vci == ATM_VCI_UNSPEC) {
PRINTK (KERN_WARNING, "rejecting open with unspecified VPI/VCI (deprecated)");
return -EINVAL;
}
#endif
if (!(0 <= vpi && vpi < (1<<NUM_VPI_BITS) &&
0 <= vci && vci < (1<<NUM_VCI_BITS))) {
PRINTD (DBG_WARN|DBG_VCC, "VPI/VCI out of range: %hd/%d", vpi, vci);
return -EINVAL;
}
qos = &atm_vcc->qos;
if (qos->aal != ATM_AAL5) {
PRINTD (DBG_QOS, "AAL not supported");
return -EINVAL;
}
PRINTD (DBG_QOS, "TX:");
txtp = &qos->txtp;
if (txtp->traffic_class != ATM_NONE) {
switch (txtp->traffic_class) {
case ATM_UBR: {
int pcr = atm_pcr_goal (txtp);
if (!pcr) {
tx_rate_bits = 0;
tx_vc_bits = TX_UBR;
tx_frame_bits = TX_FRAME_NOTCAP;
} else {
rounding r;
if (pcr < 0) {
r = round_down;
pcr = -pcr;
} else {
r = round_up;
}
error = make_rate (pcr, r, &tx_rate_bits, NULL);
if (error)
return error;
tx_vc_bits = TX_UBR_CAPPED;
tx_frame_bits = TX_FRAME_CAPPED;
}
break;
}
#if 0
case ATM_ABR: {
pcr = atm_pcr_goal (txtp);
PRINTD (DBG_QOS, "pcr goal = %d", pcr);
break;
}
#endif
default: {
PRINTD (DBG_QOS, "request for non-UBR denied");
return -EINVAL;
}
}
PRINTD (DBG_QOS, "tx_rate_bits=%hx, tx_vc_bits=%hx",
tx_rate_bits, tx_vc_bits);
}
PRINTD (DBG_QOS, "RX:");
rxtp = &qos->rxtp;
if (rxtp->traffic_class == ATM_NONE) {
} else {
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
if ((unsigned int) rxtp->max_sdu <= dev->rxq[pool].buffer_size) {
PRINTD (DBG_VCC|DBG_QOS|DBG_POOL, "chose pool %hu (max_sdu %u <= %u)",
pool, rxtp->max_sdu, dev->rxq[pool].buffer_size);
break;
}
if (pool == NUM_RX_POOLS) {
PRINTD (DBG_WARN|DBG_VCC|DBG_QOS|DBG_POOL,
"no pool suitable for VC (RX max_sdu %d is too large)",
rxtp->max_sdu);
return -EINVAL;
}
switch (rxtp->traffic_class) {
case ATM_UBR: {
break;
}
#if 0
case ATM_ABR: {
pcr = atm_pcr_goal (rxtp);
PRINTD (DBG_QOS, "pcr goal = %d", pcr);
break;
}
#endif
default: {
PRINTD (DBG_QOS, "request for non-UBR denied");
return -EINVAL;
}
}
}
vcc = kmalloc (sizeof(amb_vcc), GFP_KERNEL);
if (!vcc) {
PRINTK (KERN_ERR, "out of memory!");
return -ENOMEM;
}
atm_vcc->dev_data = (void *) vcc;
set_bit(ATM_VF_ADDR,&atm_vcc->flags);
if (txtp->traffic_class != ATM_NONE) {
command cmd;
vcc->tx_frame_bits = tx_frame_bits;
mutex_lock(&dev->vcc_sf);
if (dev->rxer[vci]) {
cmd.request = cpu_to_be32 (SRB_MODIFY_VC_RATE);
cmd.args.modify_rate.vc = cpu_to_be32 (vci);
cmd.args.modify_rate.rate = cpu_to_be32 (tx_rate_bits << SRB_RATE_SHIFT);
while (command_do (dev, &cmd))
schedule();
cmd.request = cpu_to_be32 (SRB_MODIFY_VC_FLAGS);
cmd.args.modify_flags.vc = cpu_to_be32 (vci);
cmd.args.modify_flags.flags = cpu_to_be32
( (AMB_VCC(dev->rxer[vci])->rx_info.pool << SRB_POOL_SHIFT)
| (tx_vc_bits << SRB_FLAGS_SHIFT) );
while (command_do (dev, &cmd))
schedule();
} else {
cmd.request = cpu_to_be32 (SRB_OPEN_VC);
cmd.args.open.vc = cpu_to_be32 (vci);
cmd.args.open.flags = cpu_to_be32 (tx_vc_bits << SRB_FLAGS_SHIFT);
cmd.args.open.rate = cpu_to_be32 (tx_rate_bits << SRB_RATE_SHIFT);
while (command_do (dev, &cmd))
schedule();
}
dev->txer[vci].tx_present = 1;
mutex_unlock(&dev->vcc_sf);
}
if (rxtp->traffic_class != ATM_NONE) {
command cmd;
vcc->rx_info.pool = pool;
mutex_lock(&dev->vcc_sf);
if (!dev->rxq[pool].buffers_wanted)
dev->rxq[pool].buffers_wanted = rx_lats;
dev->rxq[pool].buffers_wanted += 1;
fill_rx_pool (dev, pool, GFP_KERNEL);
if (dev->txer[vci].tx_present) {
cmd.request = cpu_to_be32 (SRB_MODIFY_VC_FLAGS);
cmd.args.modify_flags.vc = cpu_to_be32 (vci);
cmd.args.modify_flags.flags = cpu_to_be32
( (pool << SRB_POOL_SHIFT)
| (dev->txer[vci].tx_vc_bits << SRB_FLAGS_SHIFT) );
} else {
cmd.request = cpu_to_be32 (SRB_OPEN_VC);
cmd.args.open.vc = cpu_to_be32 (vci);
cmd.args.open.flags = cpu_to_be32 (pool << SRB_POOL_SHIFT);
cmd.args.open.rate = cpu_to_be32 (0);
}
while (command_do (dev, &cmd))
schedule();
dev->rxer[vci] = atm_vcc;
mutex_unlock(&dev->vcc_sf);
}
set_bit(ATM_VF_READY,&atm_vcc->flags);
return 0;
}
static void amb_close (struct atm_vcc * atm_vcc) {
amb_dev * dev = AMB_DEV (atm_vcc->dev);
amb_vcc * vcc = AMB_VCC (atm_vcc);
u16 vci = atm_vcc->vci;
PRINTD (DBG_VCC|DBG_FLOW, "amb_close");
clear_bit(ATM_VF_READY,&atm_vcc->flags);
if (atm_vcc->qos.txtp.traffic_class != ATM_NONE) {
command cmd;
mutex_lock(&dev->vcc_sf);
if (dev->rxer[vci]) {
cmd.request = cpu_to_be32 (SRB_MODIFY_VC_RATE);
cmd.args.modify_rate.vc = cpu_to_be32 (vci);
cmd.args.modify_rate.rate = cpu_to_be32 (0);
} else {
cmd.request = cpu_to_be32 (SRB_CLOSE_VC);
cmd.args.close.vc = cpu_to_be32 (vci);
}
dev->txer[vci].tx_present = 0;
while (command_do (dev, &cmd))
schedule();
mutex_unlock(&dev->vcc_sf);
}
if (atm_vcc->qos.rxtp.traffic_class != ATM_NONE) {
command cmd;
unsigned char pool = vcc->rx_info.pool;
mutex_lock(&dev->vcc_sf);
if (dev->txer[vci].tx_present) {
cmd.request = cpu_to_be32 (SRB_MODIFY_VC_FLAGS);
cmd.args.modify_flags.vc = cpu_to_be32 (vci);
cmd.args.modify_flags.flags = cpu_to_be32
(dev->txer[vci].tx_vc_bits << SRB_FLAGS_SHIFT);
} else {
cmd.request = cpu_to_be32 (SRB_CLOSE_VC);
cmd.args.close.vc = cpu_to_be32 (vci);
}
if (atm_vcc != dev->rxer[vci])
PRINTK (KERN_ERR, "%s vcc=%p rxer[vci]=%p",
"arghhh! we're going to die!",
vcc, dev->rxer[vci]);
dev->rxer[vci] = NULL;
while (command_do (dev, &cmd))
schedule();
dev->rxq[pool].buffers_wanted -= 1;
if (dev->rxq[pool].buffers_wanted == rx_lats) {
dev->rxq[pool].buffers_wanted = 0;
drain_rx_pool (dev, pool);
}
mutex_unlock(&dev->vcc_sf);
}
kfree (vcc);
clear_bit(ATM_VF_ADDR,&atm_vcc->flags);
return;
}
static int amb_send (struct atm_vcc * atm_vcc, struct sk_buff * skb) {
amb_dev * dev = AMB_DEV(atm_vcc->dev);
amb_vcc * vcc = AMB_VCC(atm_vcc);
u16 vc = atm_vcc->vci;
unsigned int tx_len = skb->len;
unsigned char * tx_data = skb->data;
tx_simple * tx_descr;
tx_in tx;
if (test_bit (dead, &dev->flags))
return -EIO;
PRINTD (DBG_FLOW|DBG_TX, "amb_send vc %x data %p len %u",
vc, tx_data, tx_len);
dump_skb (">>>", vc, skb);
if (!dev->txer[vc].tx_present) {
PRINTK (KERN_ERR, "attempt to send on RX-only VC %x", vc);
return -EBADFD;
}
ATM_SKB(skb)->vcc = atm_vcc;
if (skb->len > (size_t) atm_vcc->qos.txtp.max_sdu) {
PRINTK (KERN_ERR, "sk_buff length greater than agreed max_sdu, dropping...");
return -EIO;
}
if (check_area (skb->data, skb->len)) {
atomic_inc(&atm_vcc->stats->tx_err);
return -ENOMEM;
}
tx_descr = kmalloc (sizeof(tx_simple), GFP_KERNEL);
if (!tx_descr) {
PRINTK (KERN_ERR, "could not allocate TX descriptor");
return -ENOMEM;
}
if (check_area (tx_descr, sizeof(tx_simple))) {
kfree (tx_descr);
return -ENOMEM;
}
PRINTD (DBG_TX, "fragment list allocated at %p", tx_descr);
tx_descr->skb = skb;
tx_descr->tx_frag.bytes = cpu_to_be32 (tx_len);
tx_descr->tx_frag.address = cpu_to_be32 (virt_to_bus (tx_data));
tx_descr->tx_frag_end.handle = virt_to_bus (tx_descr);
tx_descr->tx_frag_end.vc = 0;
tx_descr->tx_frag_end.next_descriptor_length = 0;
tx_descr->tx_frag_end.next_descriptor = 0;
#ifdef AMB_NEW_MICROCODE
tx_descr->tx_frag_end.cpcs_uu = 0;
tx_descr->tx_frag_end.cpi = 0;
tx_descr->tx_frag_end.pad = 0;
#endif
tx.vc = cpu_to_be16 (vcc->tx_frame_bits | vc);
tx.tx_descr_length = cpu_to_be16 (sizeof(tx_frag)+sizeof(tx_frag_end));
tx.tx_descr_addr = cpu_to_be32 (virt_to_bus (&tx_descr->tx_frag));
while (tx_give (dev, &tx))
schedule();
return 0;
}
static int amb_proc_read (struct atm_dev * atm_dev, loff_t * pos, char * page) {
amb_dev * dev = AMB_DEV (atm_dev);
int left = *pos;
unsigned char pool;
PRINTD (DBG_FLOW, "amb_proc_read");
if (!left--) {
amb_stats * s = &dev->stats;
return sprintf (page,
"frames: TX OK %lu, RX OK %lu, RX bad %lu "
"(CRC %lu, long %lu, aborted %lu, unused %lu).\n",
s->tx_ok, s->rx.ok, s->rx.error,
s->rx.badcrc, s->rx.toolong,
s->rx.aborted, s->rx.unused);
}
if (!left--) {
amb_cq * c = &dev->cq;
return sprintf (page, "cmd queue [cur/hi/max]: %u/%u/%u. ",
c->pending, c->high, c->maximum);
}
if (!left--) {
amb_txq * t = &dev->txq;
return sprintf (page, "TX queue [cur/max high full]: %u/%u %u %u.\n",
t->pending, t->maximum, t->high, t->filled);
}
if (!left--) {
unsigned int count = sprintf (page, "RX queues [cur/max/req low empty]:");
for (pool = 0; pool < NUM_RX_POOLS; ++pool) {
amb_rxq * r = &dev->rxq[pool];
count += sprintf (page+count, " %u/%u/%u %u %u",
r->pending, r->maximum, r->buffers_wanted, r->low, r->emptied);
}
count += sprintf (page+count, ".\n");
return count;
}
if (!left--) {
unsigned int count = sprintf (page, "RX buffer sizes:");
for (pool = 0; pool < NUM_RX_POOLS; ++pool) {
amb_rxq * r = &dev->rxq[pool];
count += sprintf (page+count, " %u", r->buffer_size);
}
count += sprintf (page+count, ".\n");
return count;
}
#if 0
if (!left--) {
}
#endif
return 0;
}
static void do_housekeeping (unsigned long arg) {
amb_dev * dev = (amb_dev *) arg;
fill_rx_pools (dev);
mod_timer(&dev->housekeeping, jiffies + 10*HZ);
return;
}
static int create_queues(amb_dev *dev, unsigned int cmds, unsigned int txs,
unsigned int *rxs, unsigned int *rx_buffer_sizes)
{
unsigned char pool;
size_t total = 0;
void * memory;
void * limit;
PRINTD (DBG_FLOW, "create_queues %p", dev);
total += cmds * sizeof(command);
total += txs * (sizeof(tx_in) + sizeof(tx_out));
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
total += rxs[pool] * (sizeof(rx_in) + sizeof(rx_out));
memory = kmalloc (total, GFP_KERNEL);
if (!memory) {
PRINTK (KERN_ERR, "could not allocate queues");
return -ENOMEM;
}
if (check_area (memory, total)) {
PRINTK (KERN_ERR, "queues allocated in nasty area");
kfree (memory);
return -ENOMEM;
}
limit = memory + total;
PRINTD (DBG_INIT, "queues from %p to %p", memory, limit);
PRINTD (DBG_CMD, "command queue at %p", memory);
{
command * cmd = memory;
amb_cq * cq = &dev->cq;
cq->pending = 0;
cq->high = 0;
cq->maximum = cmds - 1;
cq->ptrs.start = cmd;
cq->ptrs.in = cmd;
cq->ptrs.out = cmd;
cq->ptrs.limit = cmd + cmds;
memory = cq->ptrs.limit;
}
PRINTD (DBG_TX, "TX queue pair at %p", memory);
{
tx_in * in = memory;
tx_out * out;
amb_txq * txq = &dev->txq;
txq->pending = 0;
txq->high = 0;
txq->filled = 0;
txq->maximum = txs - 1;
txq->in.start = in;
txq->in.ptr = in;
txq->in.limit = in + txs;
memory = txq->in.limit;
out = memory;
txq->out.start = out;
txq->out.ptr = out;
txq->out.limit = out + txs;
memory = txq->out.limit;
}
PRINTD (DBG_RX, "RX queue pairs at %p", memory);
for (pool = 0; pool < NUM_RX_POOLS; ++pool) {
rx_in * in = memory;
rx_out * out;
amb_rxq * rxq = &dev->rxq[pool];
rxq->buffer_size = rx_buffer_sizes[pool];
rxq->buffers_wanted = 0;
rxq->pending = 0;
rxq->low = rxs[pool] - 1;
rxq->emptied = 0;
rxq->maximum = rxs[pool] - 1;
rxq->in.start = in;
rxq->in.ptr = in;
rxq->in.limit = in + rxs[pool];
memory = rxq->in.limit;
out = memory;
rxq->out.start = out;
rxq->out.ptr = out;
rxq->out.limit = out + rxs[pool];
memory = rxq->out.limit;
}
if (memory == limit) {
return 0;
} else {
PRINTK (KERN_ERR, "bad queue alloc %p != %p (tell maintainer)", memory, limit);
kfree (limit - total);
return -ENOMEM;
}
}
static void destroy_queues (amb_dev * dev) {
void * memory = dev->cq.ptrs.start;
PRINTD (DBG_FLOW, "destroy_queues %p", dev);
PRINTD (DBG_INIT, "freeing queues at %p", memory);
kfree (memory);
return;
}
static int decode_loader_result (loader_command cmd, u32 result)
{
int res;
const char *msg;
if (result == command_successes[cmd])
return 0;
switch (result) {
case BAD_COMMAND:
res = -EINVAL;
msg = "bad command";
break;
case COMMAND_IN_PROGRESS:
res = -ETIMEDOUT;
msg = "command in progress";
break;
case COMMAND_PASSED_TEST:
res = 0;
msg = "command passed test";
break;
case COMMAND_FAILED_TEST:
res = -EIO;
msg = "command failed test";
break;
case COMMAND_READ_DATA_OK:
res = 0;
msg = "command read data ok";
break;
case COMMAND_READ_BAD_ADDRESS:
res = -EINVAL;
msg = "command read bad address";
break;
case COMMAND_WRITE_DATA_OK:
res = 0;
msg = "command write data ok";
break;
case COMMAND_WRITE_BAD_ADDRESS:
res = -EINVAL;
msg = "command write bad address";
break;
case COMMAND_WRITE_FLASH_FAILURE:
res = -EIO;
msg = "command write flash failure";
break;
case COMMAND_COMPLETE:
res = 0;
msg = "command complete";
break;
case COMMAND_FLASH_ERASE_FAILURE:
res = -EIO;
msg = "command flash erase failure";
break;
case COMMAND_WRITE_BAD_DATA:
res = -EINVAL;
msg = "command write bad data";
break;
default:
res = -EINVAL;
msg = "unknown error";
PRINTD (DBG_LOAD|DBG_ERR,
"decode_loader_result got %d=%x !",
result, result);
break;
}
PRINTK (KERN_ERR, "%s", msg);
return res;
}
static int do_loader_command(volatile loader_block *lb, const amb_dev *dev,
loader_command cmd)
{
unsigned long timeout;
PRINTD (DBG_FLOW|DBG_LOAD, "do_loader_command");
lb->result = 0;
lb->command = cpu_to_be32 (cmd);
lb->valid = cpu_to_be32 (DMA_VALID);
wr_mem (dev, offsetof(amb_mem, doorbell), virt_to_bus (lb) & ~onegigmask);
timeout = command_timeouts[cmd] * 10;
while (!lb->result || lb->result == cpu_to_be32 (COMMAND_IN_PROGRESS))
if (timeout) {
timeout = msleep_interruptible(timeout);
} else {
PRINTD (DBG_LOAD|DBG_ERR, "command %d timed out", cmd);
dump_registers (dev);
dump_loader_block (lb);
return -ETIMEDOUT;
}
if (cmd == adapter_start) {
timeout = 100;
while (rd_plain (dev, offsetof(amb_mem, doorbell)))
if (timeout) {
timeout = msleep_interruptible(timeout);
} else {
PRINTD (DBG_LOAD|DBG_ERR, "start command did not clear doorbell, res=%08x",
be32_to_cpu (lb->result));
dump_registers (dev);
return -ETIMEDOUT;
}
return 0;
} else {
return decode_loader_result (cmd, be32_to_cpu (lb->result));
}
}
static int get_loader_version(loader_block *lb, const amb_dev *dev,
u32 *version)
{
int res;
PRINTD (DBG_FLOW|DBG_LOAD, "get_loader_version");
res = do_loader_command (lb, dev, get_version_number);
if (res)
return res;
if (version)
*version = be32_to_cpu (lb->payload.version);
return 0;
}
static int loader_write(loader_block *lb, const amb_dev *dev,
const struct ihex_binrec *rec)
{
transfer_block * tb = &lb->payload.transfer;
PRINTD (DBG_FLOW|DBG_LOAD, "loader_write");
tb->address = rec->addr;
tb->count = cpu_to_be32(be16_to_cpu(rec->len) / 4);
memcpy(tb->data, rec->data, be16_to_cpu(rec->len));
return do_loader_command (lb, dev, write_adapter_memory);
}
static int loader_verify(loader_block *lb, const amb_dev *dev,
const struct ihex_binrec *rec)
{
transfer_block * tb = &lb->payload.transfer;
int res;
PRINTD (DBG_FLOW|DBG_LOAD, "loader_verify");
tb->address = rec->addr;
tb->count = cpu_to_be32(be16_to_cpu(rec->len) / 4);
res = do_loader_command (lb, dev, read_adapter_memory);
if (!res && memcmp(tb->data, rec->data, be16_to_cpu(rec->len)))
res = -EINVAL;
return res;
}
static int loader_start(loader_block *lb, const amb_dev *dev, u32 address)
{
PRINTD (DBG_FLOW|DBG_LOAD, "loader_start");
lb->payload.start = cpu_to_be32 (address);
return do_loader_command (lb, dev, adapter_start);
}
static inline void sf (const char * msg)
{
PRINTK (KERN_ERR, "self-test failed: %s", msg);
}
static int amb_reset (amb_dev * dev, int diags) {
u32 word;
PRINTD (DBG_FLOW|DBG_LOAD, "amb_reset");
word = rd_plain (dev, offsetof(amb_mem, reset_control));
wr_plain (dev, offsetof(amb_mem, reset_control), word | AMB_RESET_BITS);
udelay (10);
#if 1
wr_plain (dev, offsetof(amb_mem, interrupt_control), AMB_DOORBELL_BITS);
wr_plain (dev, offsetof(amb_mem, interrupt), -1);
#endif
wr_plain (dev, offsetof(amb_mem, mb.loader.ready), 0);
wr_plain (dev, offsetof(amb_mem, reset_control), word &~ AMB_RESET_BITS);
if (diags) {
unsigned long timeout;
msleep(4200);
timeout = 500;
while (!rd_plain (dev, offsetof(amb_mem, mb.loader.ready)))
if (timeout) {
timeout = msleep_interruptible(timeout);
} else {
PRINTD (DBG_LOAD|DBG_ERR, "reset timed out");
return -ETIMEDOUT;
}
word = rd_mem (dev, offsetof(amb_mem, mb.loader.result));
if (word & SELF_TEST_FAILURE) {
if (word & GPINT_TST_FAILURE)
sf ("interrupt");
if (word & SUNI_DATA_PATTERN_FAILURE)
sf ("SUNI data pattern");
if (word & SUNI_DATA_BITS_FAILURE)
sf ("SUNI data bits");
if (word & SUNI_UTOPIA_FAILURE)
sf ("SUNI UTOPIA interface");
if (word & SUNI_FIFO_FAILURE)
sf ("SUNI cell buffer FIFO");
if (word & SRAM_FAILURE)
sf ("bad SRAM");
return -EIO;
}
}
return 0;
}
static int ucode_init(loader_block *lb, amb_dev *dev)
{
const struct firmware *fw;
unsigned long start_address;
const struct ihex_binrec *rec;
const char *errmsg = NULL;
int res;
res = request_ihex_firmware(&fw, "atmsar11.fw", &dev->pci_dev->dev);
if (res) {
PRINTK (KERN_ERR, "Cannot load microcode data");
return res;
}
rec = (const struct ihex_binrec *)fw->data;
if (be16_to_cpu(rec->len) != sizeof(__be32) || be32_to_cpu(rec->addr)) {
errmsg = "no start record";
goto fail;
}
start_address = be32_to_cpup((__be32 *)rec->data);
rec = ihex_next_binrec(rec);
PRINTD (DBG_FLOW|DBG_LOAD, "ucode_init");
while (rec) {
PRINTD (DBG_LOAD, "starting region (%x, %u)", be32_to_cpu(rec->addr),
be16_to_cpu(rec->len));
if (be16_to_cpu(rec->len) > 4 * MAX_TRANSFER_DATA) {
errmsg = "record too long";
goto fail;
}
if (be16_to_cpu(rec->len) & 3) {
errmsg = "odd number of bytes";
goto fail;
}
res = loader_write(lb, dev, rec);
if (res)
break;
res = loader_verify(lb, dev, rec);
if (res)
break;
rec = ihex_next_binrec(rec);
}
release_firmware(fw);
if (!res)
res = loader_start(lb, dev, start_address);
return res;
fail:
release_firmware(fw);
PRINTK(KERN_ERR, "Bad microcode data (%s)", errmsg);
return -EINVAL;
}
static inline __be32 bus_addr(void * addr) {
return cpu_to_be32 (virt_to_bus (addr));
}
static int amb_talk(amb_dev *dev)
{
adap_talk_block a;
unsigned char pool;
unsigned long timeout;
PRINTD (DBG_FLOW, "amb_talk %p", dev);
a.command_start = bus_addr (dev->cq.ptrs.start);
a.command_end = bus_addr (dev->cq.ptrs.limit);
a.tx_start = bus_addr (dev->txq.in.start);
a.tx_end = bus_addr (dev->txq.in.limit);
a.txcom_start = bus_addr (dev->txq.out.start);
a.txcom_end = bus_addr (dev->txq.out.limit);
for (pool = 0; pool < NUM_RX_POOLS; ++pool) {
a.rec_struct[pool].buffer_start = bus_addr (dev->rxq[pool].in.start);
a.rec_struct[pool].buffer_end = bus_addr (dev->rxq[pool].in.limit);
a.rec_struct[pool].rx_start = bus_addr (dev->rxq[pool].out.start);
a.rec_struct[pool].rx_end = bus_addr (dev->rxq[pool].out.limit);
a.rec_struct[pool].buffer_size = cpu_to_be32 (dev->rxq[pool].buffer_size);
}
#ifdef AMB_NEW_MICROCODE
a.init_flags = 0;
#endif
wr_mem (dev, offsetof(amb_mem, doorbell), virt_to_bus (&a));
msleep(2200);
timeout = 500;
while (rd_plain (dev, offsetof(amb_mem, doorbell)))
if (timeout) {
timeout = msleep_interruptible(timeout);
} else {
PRINTD (DBG_INIT|DBG_ERR, "adapter init timed out");
return -ETIMEDOUT;
}
return 0;
}
static void amb_ucode_version(amb_dev *dev)
{
u32 major;
u32 minor;
command cmd;
cmd.request = cpu_to_be32 (SRB_GET_VERSION);
while (command_do (dev, &cmd)) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
major = be32_to_cpu (cmd.args.version.major);
minor = be32_to_cpu (cmd.args.version.minor);
PRINTK (KERN_INFO, "microcode version is %u.%u", major, minor);
}
static void amb_esi(amb_dev *dev, u8 *esi)
{
u32 lower4;
u16 upper2;
command cmd;
cmd.request = cpu_to_be32 (SRB_GET_BIA);
while (command_do (dev, &cmd)) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule();
}
lower4 = be32_to_cpu (cmd.args.bia.lower4);
upper2 = be32_to_cpu (cmd.args.bia.upper2);
PRINTD (DBG_LOAD, "BIA: lower4: %08x, upper2 %04x", lower4, upper2);
if (esi) {
unsigned int i;
PRINTDB (DBG_INIT, "ESI:");
for (i = 0; i < ESI_LEN; ++i) {
if (i < 4)
esi[i] = bitrev8(lower4>>(8*i));
else
esi[i] = bitrev8(upper2>>(8*(i-4)));
PRINTDM (DBG_INIT, " %02x", esi[i]);
}
PRINTDE (DBG_INIT, "");
}
return;
}
static void fixup_plx_window (amb_dev *dev, loader_block *lb)
{
unsigned long blb;
u32 mapreg;
blb = virt_to_bus(lb);
mapreg = rd_plain (dev, offsetof(amb_mem, stuff[10]));
mapreg &= ~onegigmask;
mapreg |= blb & onegigmask;
wr_plain (dev, offsetof(amb_mem, stuff[10]), mapreg);
return;
}
static int amb_init(amb_dev *dev)
{
loader_block lb;
u32 version;
if (amb_reset (dev, 1)) {
PRINTK (KERN_ERR, "card reset failed!");
} else {
fixup_plx_window (dev, &lb);
if (get_loader_version (&lb, dev, &version)) {
PRINTK (KERN_INFO, "failed to get loader version");
} else {
PRINTK (KERN_INFO, "loader version is %08x", version);
if (ucode_init (&lb, dev)) {
PRINTK (KERN_ERR, "microcode failure");
} else if (create_queues (dev, cmds, txs, rxs, rxs_bs)) {
PRINTK (KERN_ERR, "failed to get memory for queues");
} else {
if (amb_talk (dev)) {
PRINTK (KERN_ERR, "adapter did not accept queues");
} else {
amb_ucode_version (dev);
return 0;
}
destroy_queues (dev);
}
amb_reset (dev, 0);
}
}
return -EINVAL;
}
static void setup_dev(amb_dev *dev, struct pci_dev *pci_dev)
{
unsigned char pool;
dev->pci_dev = pci_dev;
pci_set_drvdata(pci_dev, dev);
dev->iobase = pci_resource_start (pci_dev, 1);
dev->irq = pci_dev->irq;
dev->membase = bus_to_virt(pci_resource_start(pci_dev, 0));
dev->flags = 0;
dev->tx_avail = ATM_OC3_PCR;
dev->rx_avail = ATM_OC3_PCR;
mutex_init(&dev->vcc_sf);
spin_lock_init (&dev->cq.lock);
spin_lock_init (&dev->txq.lock);
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
spin_lock_init (&dev->rxq[pool].lock);
}
static void setup_pci_dev(struct pci_dev *pci_dev)
{
unsigned char lat;
pci_set_master(pci_dev);
pci_read_config_byte (pci_dev, PCI_LATENCY_TIMER, &lat);
if (!pci_lat)
pci_lat = (lat < MIN_PCI_LATENCY) ? MIN_PCI_LATENCY : lat;
if (lat != pci_lat) {
PRINTK (KERN_INFO, "Changing PCI latency timer from %hu to %hu",
lat, pci_lat);
pci_write_config_byte(pci_dev, PCI_LATENCY_TIMER, pci_lat);
}
}
static int amb_probe(struct pci_dev *pci_dev,
const struct pci_device_id *pci_ent)
{
amb_dev * dev;
int err;
unsigned int irq;
err = pci_enable_device(pci_dev);
if (err < 0) {
PRINTK (KERN_ERR, "skipped broken (PLX rev 2) card");
goto out;
}
irq = pci_dev->irq;
if (pci_dev->device == PCI_DEVICE_ID_MADGE_AMBASSADOR_BAD) {
PRINTK (KERN_ERR, "skipped broken (PLX rev 2) card");
err = -EINVAL;
goto out_disable;
}
PRINTD (DBG_INFO, "found Madge ATM adapter (amb) at"
" IO %llx, IRQ %u, MEM %p",
(unsigned long long)pci_resource_start(pci_dev, 1),
irq, bus_to_virt(pci_resource_start(pci_dev, 0)));
err = pci_request_region(pci_dev, 1, DEV_LABEL);
if (err < 0) {
PRINTK (KERN_ERR, "IO range already in use!");
goto out_disable;
}
dev = kzalloc(sizeof(amb_dev), GFP_KERNEL);
if (!dev) {
PRINTK (KERN_ERR, "out of memory!");
err = -ENOMEM;
goto out_release;
}
setup_dev(dev, pci_dev);
err = amb_init(dev);
if (err < 0) {
PRINTK (KERN_ERR, "adapter initialisation failure");
goto out_free;
}
setup_pci_dev(pci_dev);
err = request_irq(irq, interrupt_handler, IRQF_SHARED, DEV_LABEL, dev);
if (err < 0) {
PRINTK (KERN_ERR, "request IRQ failed!");
goto out_reset;
}
dev->atm_dev = atm_dev_register (DEV_LABEL, &pci_dev->dev, &amb_ops, -1,
NULL);
if (!dev->atm_dev) {
PRINTD (DBG_ERR, "failed to register Madge ATM adapter");
err = -EINVAL;
goto out_free_irq;
}
PRINTD (DBG_INFO, "registered Madge ATM adapter (no. %d) (%p) at %p",
dev->atm_dev->number, dev, dev->atm_dev);
dev->atm_dev->dev_data = (void *) dev;
amb_esi (dev, dev->atm_dev->esi);
dev->atm_dev->ci_range.vpi_bits = NUM_VPI_BITS;
dev->atm_dev->ci_range.vci_bits = NUM_VCI_BITS;
setup_timer(&dev->housekeeping, do_housekeeping,
(unsigned long)dev);
mod_timer(&dev->housekeeping, jiffies);
interrupts_on (dev);
out:
return err;
out_free_irq:
free_irq(irq, dev);
out_reset:
amb_reset(dev, 0);
out_free:
kfree(dev);
out_release:
pci_release_region(pci_dev, 1);
out_disable:
pci_disable_device(pci_dev);
goto out;
}
static void amb_remove_one(struct pci_dev *pci_dev)
{
struct amb_dev *dev;
dev = pci_get_drvdata(pci_dev);
PRINTD(DBG_INFO|DBG_INIT, "closing %p (atm_dev = %p)", dev, dev->atm_dev);
del_timer_sync(&dev->housekeeping);
drain_rx_pools(dev);
interrupts_off(dev);
amb_reset(dev, 0);
free_irq(dev->irq, dev);
pci_disable_device(pci_dev);
destroy_queues(dev);
atm_dev_deregister(dev->atm_dev);
kfree(dev);
pci_release_region(pci_dev, 1);
}
static void __init amb_check_args (void) {
unsigned char pool;
unsigned int max_rx_size;
#ifdef DEBUG_AMBASSADOR
PRINTK (KERN_NOTICE, "debug bitmap is %hx", debug &= DBG_MASK);
#else
if (debug)
PRINTK (KERN_NOTICE, "no debugging support");
#endif
if (cmds < MIN_QUEUE_SIZE)
PRINTK (KERN_NOTICE, "cmds has been raised to %u",
cmds = MIN_QUEUE_SIZE);
if (txs < MIN_QUEUE_SIZE)
PRINTK (KERN_NOTICE, "txs has been raised to %u",
txs = MIN_QUEUE_SIZE);
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
if (rxs[pool] < MIN_QUEUE_SIZE)
PRINTK (KERN_NOTICE, "rxs[%hu] has been raised to %u",
pool, rxs[pool] = MIN_QUEUE_SIZE);
max_rx_size = 0;
for (pool = 0; pool < NUM_RX_POOLS; ++pool)
if (rxs_bs[pool] <= max_rx_size)
PRINTK (KERN_NOTICE, "useless pool (rxs_bs[%hu] = %u)",
pool, rxs_bs[pool]);
else
max_rx_size = rxs_bs[pool];
if (rx_lats < MIN_RX_BUFFERS)
PRINTK (KERN_NOTICE, "rx_lats has been raised to %u",
rx_lats = MIN_RX_BUFFERS);
return;
}
static int __init amb_module_init (void)
{
PRINTD (DBG_FLOW|DBG_INIT, "init_module");
BUILD_BUG_ON(sizeof(amb_mem) != 4*16 + 4*12);
show_version();
amb_check_args();
return pci_register_driver(&amb_driver);
}
static void __exit amb_module_exit (void)
{
PRINTD (DBG_FLOW|DBG_INIT, "cleanup_module");
pci_unregister_driver(&amb_driver);
}
