static void my_hd (void *addr, int len)
{
int j, ch;
unsigned char *ptr = addr;
while (len > 0) {
printk ("%p ", ptr);
for (j=0;j < ((len < 16)?len:16);j++) {
printk ("%02x %s", ptr[j], (j==7)?" ":"");
}
for ( ;j < 16;j++) {
printk (" %s", (j==7)?" ":"");
}
for (j=0;j < ((len < 16)?len:16);j++) {
ch = ptr[j];
printk ("%c", (ch < 0x20)?'.':((ch > 0x7f)?'.':ch));
}
printk ("\n");
ptr += 16;
len -= 16;
}
}
static void my_hd (void *addr, int len){}
static inline void fs_kfree_skb (struct sk_buff * skb)
{
if (ATM_SKB(skb)->vcc->pop)
ATM_SKB(skb)->vcc->pop (ATM_SKB(skb)->vcc, skb);
else
dev_kfree_skb_any (skb);
}
static int make_rate(unsigned int rate, int r,
u16 *bits, unsigned int *actual)
{
unsigned char exp = -1;
unsigned int man = -1;
fs_dprintk (FS_DEBUG_QOS, "make_rate %u", rate);
if (rate > 0xffc00000U) {
if (r == ROUND_UP) {
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
case ROUND_DOWN: {
man = man>>(32-9);
break;
}
case ROUND_UP: {
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
case ROUND_NEAREST: {
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
if (r == ROUND_DOWN) {
return -EINVAL;
} else {
exp = 0;
man = 0;
}
}
fs_dprintk (FS_DEBUG_QOS, "rate: man=%u, exp=%hu", man, exp);
if (bits)
*bits = (exp<<9) | man;
if (actual)
*actual = (exp >= 9)
? (1 << exp) + (man << (exp-9))
: (1 << exp) + ((man + (1<<(9-exp-1))) >> (9-exp));
return 0;
}
static inline void write_fs (struct fs_dev *dev, int offset, u32 val)
{
writel (val, dev->base + offset);
}
static inline u32 read_fs (struct fs_dev *dev, int offset)
{
return readl (dev->base + offset);
}
static inline struct FS_QENTRY *get_qentry (struct fs_dev *dev, struct queue *q)
{
return bus_to_virt (read_fs (dev, Q_WP(q->offset)) & Q_ADDR_MASK);
}
static void submit_qentry (struct fs_dev *dev, struct queue *q, struct FS_QENTRY *qe)
{
u32 wp;
struct FS_QENTRY *cqe;
while ((wp = read_fs (dev, Q_WP (q->offset))) & Q_FULL) {
fs_dprintk (FS_DEBUG_TXQ, "Found queue at %x full. Waiting.\n",
q->offset);
schedule ();
}
wp &= ~0xf;
cqe = bus_to_virt (wp);
if (qe != cqe) {
fs_dprintk (FS_DEBUG_TXQ, "q mismatch! %p %p\n", qe, cqe);
}
write_fs (dev, Q_WP(q->offset), Q_INCWRAP);
{
static int c;
if (!(c++ % 100))
{
int rp, wp;
rp = read_fs (dev, Q_RP(q->offset));
wp = read_fs (dev, Q_WP(q->offset));
fs_dprintk (FS_DEBUG_TXQ, "q at %d: %x-%x: %x entries.\n",
q->offset, rp, wp, wp-rp);
}
}
}
static void submit_queue (struct fs_dev *dev, struct queue *q,
u32 cmd, u32 p1, u32 p2, u32 p3)
{
struct FS_QENTRY *qe;
qe = get_qentry (dev, q);
qe->cmd = cmd;
qe->p0 = p1;
qe->p1 = p2;
qe->p2 = p3;
submit_qentry (dev, q, qe);
#ifdef DEBUG_EXTRA
pq[qp].cmd = cmd;
pq[qp].p0 = p1;
pq[qp].p1 = p2;
pq[qp].p2 = p3;
qp++;
if (qp >= 60) qp = 0;
#endif
}
static void submit_command (struct fs_dev *dev, struct queue *q,
u32 cmd, u32 p1, u32 p2, u32 p3)
{
write_fs (dev, CMDR0, cmd);
write_fs (dev, CMDR1, p1);
write_fs (dev, CMDR2, p2);
write_fs (dev, CMDR3, p3);
}
static void process_return_queue (struct fs_dev *dev, struct queue *q)
{
long rq;
struct FS_QENTRY *qe;
void *tc;
while (!((rq = read_fs (dev, Q_RP(q->offset))) & Q_EMPTY)) {
fs_dprintk (FS_DEBUG_QUEUE, "reaping return queue entry at %lx\n", rq);
qe = bus_to_virt (rq);
fs_dprintk (FS_DEBUG_QUEUE, "queue entry: %08x %08x %08x %08x. (%d)\n",
qe->cmd, qe->p0, qe->p1, qe->p2, STATUS_CODE (qe));
switch (STATUS_CODE (qe)) {
case 5:
tc = bus_to_virt (qe->p0);
fs_dprintk (FS_DEBUG_ALLOC, "Free tc: %p\n", tc);
kfree (tc);
break;
}
write_fs (dev, Q_RP(q->offset), Q_INCWRAP);
}
}
static void process_txdone_queue (struct fs_dev *dev, struct queue *q)
{
long rq;
long tmp;
struct FS_QENTRY *qe;
struct sk_buff *skb;
struct FS_BPENTRY *td;
while (!((rq = read_fs (dev, Q_RP(q->offset))) & Q_EMPTY)) {
fs_dprintk (FS_DEBUG_QUEUE, "reaping txdone entry at %lx\n", rq);
qe = bus_to_virt (rq);
fs_dprintk (FS_DEBUG_QUEUE, "queue entry: %08x %08x %08x %08x: %d\n",
qe->cmd, qe->p0, qe->p1, qe->p2, STATUS_CODE (qe));
if (STATUS_CODE (qe) != 2)
fs_dprintk (FS_DEBUG_TXMEM, "queue entry: %08x %08x %08x %08x: %d\n",
qe->cmd, qe->p0, qe->p1, qe->p2, STATUS_CODE (qe));
switch (STATUS_CODE (qe)) {
case 0x01:
case 0x02:
tmp = qe->p0;
if (tmp & 0x0f)
printk (KERN_WARNING "td not aligned: %ld\n", tmp);
tmp &= ~0x0f;
td = bus_to_virt (tmp);
fs_dprintk (FS_DEBUG_QUEUE, "Pool entry: %08x %08x %08x %08x %p.\n",
td->flags, td->next, td->bsa, td->aal_bufsize, td->skb );
skb = td->skb;
if (skb == FS_VCC (ATM_SKB(skb)->vcc)->last_skb) {
wake_up_interruptible (& FS_VCC (ATM_SKB(skb)->vcc)->close_wait);
FS_VCC (ATM_SKB(skb)->vcc)->last_skb = NULL;
}
td->dev->ntxpckts--;
{
static int c=0;
if (!(c++ % 100)) {
fs_dprintk (FS_DEBUG_QSIZE, "[%d]", td->dev->ntxpckts);
}
}
atomic_inc(&ATM_SKB(skb)->vcc->stats->tx);
fs_dprintk (FS_DEBUG_TXMEM, "i");
fs_dprintk (FS_DEBUG_ALLOC, "Free t-skb: %p\n", skb);
fs_kfree_skb (skb);
fs_dprintk (FS_DEBUG_ALLOC, "Free trans-d: %p\n", td);
memset (td, ATM_POISON_FREE, sizeof(struct FS_BPENTRY));
kfree (td);
break;
default:
;
}
write_fs (dev, Q_RP(q->offset), Q_INCWRAP);
}
}
static void process_incoming (struct fs_dev *dev, struct queue *q)
{
long rq;
struct FS_QENTRY *qe;
struct FS_BPENTRY *pe;
struct sk_buff *skb;
unsigned int channo;
struct atm_vcc *atm_vcc;
while (!((rq = read_fs (dev, Q_RP(q->offset))) & Q_EMPTY)) {
fs_dprintk (FS_DEBUG_QUEUE, "reaping incoming queue entry at %lx\n", rq);
qe = bus_to_virt (rq);
fs_dprintk (FS_DEBUG_QUEUE, "queue entry: %08x %08x %08x %08x. ",
qe->cmd, qe->p0, qe->p1, qe->p2);
fs_dprintk (FS_DEBUG_QUEUE, "-> %x: %s\n",
STATUS_CODE (qe),
res_strings[STATUS_CODE(qe)]);
pe = bus_to_virt (qe->p0);
fs_dprintk (FS_DEBUG_QUEUE, "Pool entry: %08x %08x %08x %08x %p %p.\n",
pe->flags, pe->next, pe->bsa, pe->aal_bufsize,
pe->skb, pe->fp);
channo = qe->cmd & 0xffff;
if (channo < dev->nchannels)
atm_vcc = dev->atm_vccs[channo];
else
atm_vcc = NULL;
switch (STATUS_CODE (qe)) {
case 0x1:
case 0x2:
if (atm_vcc) {
skb = pe->skb;
pe->fp->n--;
#if 0
fs_dprintk (FS_DEBUG_QUEUE, "Got skb: %p\n", skb);
if (FS_DEBUG_QUEUE & fs_debug) my_hd (bus_to_virt (pe->bsa), 0x20);
#endif
skb_put (skb, qe->p1 & 0xffff);
ATM_SKB(skb)->vcc = atm_vcc;
atomic_inc(&atm_vcc->stats->rx);
__net_timestamp(skb);
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-skb: %p (pushed)\n", skb);
atm_vcc->push (atm_vcc, skb);
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-d: %p\n", pe);
kfree (pe);
} else {
printk (KERN_ERR "Got a receive on a non-open channel %d.\n", channo);
}
break;
case 0x17:
if (qe->p1 & 0xffff) {
pe = bus_to_virt (qe->p0);
pe->fp->n--;
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-skb: %p\n", pe->skb);
dev_kfree_skb_any (pe->skb);
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-d: %p\n", pe);
kfree (pe);
}
if (atm_vcc)
atomic_inc(&atm_vcc->stats->rx_drop);
break;
case 0x1f:
if (atm_vcc)
atomic_inc(&atm_vcc->stats->rx_drop);
break;
default:
printk (KERN_WARNING "Don't know what to do with RX status %x: %s.\n",
STATUS_CODE(qe), res_strings[STATUS_CODE (qe)]);
}
write_fs (dev, Q_RP(q->offset), Q_INCWRAP);
}
}
static int fs_open(struct atm_vcc *atm_vcc)
{
struct fs_dev *dev;
struct fs_vcc *vcc;
struct fs_transmit_config *tc;
struct atm_trafprm * txtp;
struct atm_trafprm * rxtp;
int error;
int bfp;
int to;
unsigned short tmc0;
short vpi = atm_vcc->vpi;
int vci = atm_vcc->vci;
func_enter ();
dev = FS_DEV(atm_vcc->dev);
fs_dprintk (FS_DEBUG_OPEN, "fs: open on dev: %p, vcc at %p\n",
dev, atm_vcc);
if (vci != ATM_VPI_UNSPEC && vpi != ATM_VCI_UNSPEC)
set_bit(ATM_VF_ADDR, &atm_vcc->flags);
if ((atm_vcc->qos.aal != ATM_AAL5) &&
(atm_vcc->qos.aal != ATM_AAL2))
return -EINVAL;
fs_dprintk (FS_DEBUG_OPEN, "fs: (itf %d): open %d.%d\n",
atm_vcc->dev->number, atm_vcc->vpi, atm_vcc->vci);
vcc = kmalloc(sizeof(struct fs_vcc), GFP_KERNEL);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc VCC: %p(%Zd)\n", vcc, sizeof(struct fs_vcc));
if (!vcc) {
clear_bit(ATM_VF_ADDR, &atm_vcc->flags);
return -ENOMEM;
}
atm_vcc->dev_data = vcc;
vcc->last_skb = NULL;
init_waitqueue_head (&vcc->close_wait);
txtp = &atm_vcc->qos.txtp;
rxtp = &atm_vcc->qos.rxtp;
if (!test_bit(ATM_VF_PARTIAL, &atm_vcc->flags)) {
if (IS_FS50(dev)) {
for (to=33;to;to--, dev->channo++) {
if (dev->channo >= 32)
dev->channo = 0;
if (DO_DIRECTION(rxtp) && dev->atm_vccs[dev->channo])
continue;
if (DO_DIRECTION(txtp) && test_bit (dev->channo, dev->tx_inuse))
continue;
break;
}
if (!to) {
printk ("No more free channels for FS50..\n");
return -EBUSY;
}
vcc->channo = dev->channo;
dev->channo &= dev->channel_mask;
} else {
vcc->channo = (vpi << FS155_VCI_BITS) | (vci);
if (((DO_DIRECTION(rxtp) && dev->atm_vccs[vcc->channo])) ||
( DO_DIRECTION(txtp) && test_bit (vcc->channo, dev->tx_inuse))) {
printk ("Channel is in use for FS155.\n");
return -EBUSY;
}
}
fs_dprintk (FS_DEBUG_OPEN, "OK. Allocated channel %x(%d).\n",
vcc->channo, vcc->channo);
}
if (DO_DIRECTION (txtp)) {
tc = kmalloc (sizeof (struct fs_transmit_config), GFP_KERNEL);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc tc: %p(%Zd)\n",
tc, sizeof (struct fs_transmit_config));
if (!tc) {
fs_dprintk (FS_DEBUG_OPEN, "fs: can't alloc transmit_config.\n");
return -ENOMEM;
}
switch (atm_vcc->qos.aal) {
case ATM_AAL2:
case ATM_AAL0:
tc->flags = 0
| TC_FLAGS_TRANSPARENT_PAYLOAD
| TC_FLAGS_PACKET
| (1 << 28)
| TC_FLAGS_TYPE_UBR
| TC_FLAGS_CAL0;
break;
case ATM_AAL5:
tc->flags = 0
| TC_FLAGS_AAL5
| TC_FLAGS_PACKET
| TC_FLAGS_TYPE_CBR
| TC_FLAGS_CAL0;
break;
default:
printk ("Unknown aal: %d\n", atm_vcc->qos.aal);
tc->flags = 0;
}
tc->atm_hdr = (vpi << 20) | (vci << 4);
tmc0 = 0;
{
int pcr = atm_pcr_goal (txtp);
fs_dprintk (FS_DEBUG_OPEN, "pcr = %d.\n", pcr);
if (IS_FS50(dev)) {
if (pcr > 51840000/53/8) pcr = 51840000/53/8;
} else {
if (pcr > 155520000/53/8) pcr = 155520000/53/8;
}
if (!pcr) {
tmc0 = IS_FS50(dev)?0x61BE:0x64c9;
} else {
int r;
if (pcr < 0) {
r = ROUND_DOWN;
pcr = -pcr;
} else {
r = ROUND_UP;
}
error = make_rate (pcr, r, &tmc0, NULL);
if (error) {
kfree(tc);
return error;
}
}
fs_dprintk (FS_DEBUG_OPEN, "pcr = %d.\n", pcr);
}
tc->TMC[0] = tmc0 | 0x4000;
tc->TMC[1] = 0;
tc->TMC[2] = 0;
tc->TMC[3] = 0;
tc->spec = 0;
tc->rtag[0] = 0;
tc->rtag[1] = 0;
tc->rtag[2] = 0;
if (fs_debug & FS_DEBUG_OPEN) {
fs_dprintk (FS_DEBUG_OPEN, "TX config record:\n");
my_hd (tc, sizeof (*tc));
}
submit_command (dev, &dev->hp_txq,
QE_CMD_CONFIG_TX | QE_CMD_IMM_INQ | vcc->channo,
virt_to_bus (tc), 0, 0);
submit_command (dev, &dev->hp_txq,
QE_CMD_TX_EN | QE_CMD_IMM_INQ | vcc->channo,
0, 0, 0);
set_bit (vcc->channo, dev->tx_inuse);
}
if (DO_DIRECTION (rxtp)) {
dev->atm_vccs[vcc->channo] = atm_vcc;
for (bfp = 0;bfp < FS_NR_FREE_POOLS; bfp++)
if (atm_vcc->qos.rxtp.max_sdu <= dev->rx_fp[bfp].bufsize) break;
if (bfp >= FS_NR_FREE_POOLS) {
fs_dprintk (FS_DEBUG_OPEN, "No free pool fits sdu: %d.\n",
atm_vcc->qos.rxtp.max_sdu);
dev->atm_vccs[vcc->channo] = NULL;
kfree (vcc);
return -EINVAL;
}
switch (atm_vcc->qos.aal) {
case ATM_AAL0:
case ATM_AAL2:
submit_command (dev, &dev->hp_txq,
QE_CMD_CONFIG_RX | QE_CMD_IMM_INQ | vcc->channo,
RC_FLAGS_TRANSP |
RC_FLAGS_BFPS_BFP * bfp |
RC_FLAGS_RXBM_PSB, 0, 0);
break;
case ATM_AAL5:
submit_command (dev, &dev->hp_txq,
QE_CMD_CONFIG_RX | QE_CMD_IMM_INQ | vcc->channo,
RC_FLAGS_AAL5 |
RC_FLAGS_BFPS_BFP * bfp |
RC_FLAGS_RXBM_PSB, 0, 0);
break;
};
if (IS_FS50 (dev)) {
submit_command (dev, &dev->hp_txq,
QE_CMD_REG_WR | QE_CMD_IMM_INQ,
0x80 + vcc->channo,
(vpi << 16) | vci, 0 );
}
submit_command (dev, &dev->hp_txq,
QE_CMD_RX_EN | QE_CMD_IMM_INQ | vcc->channo,
0, 0, 0);
}
set_bit(ATM_VF_READY, &atm_vcc->flags);
func_exit ();
return 0;
}
static void fs_close(struct atm_vcc *atm_vcc)
{
struct fs_dev *dev = FS_DEV (atm_vcc->dev);
struct fs_vcc *vcc = FS_VCC (atm_vcc);
struct atm_trafprm * txtp;
struct atm_trafprm * rxtp;
func_enter ();
clear_bit(ATM_VF_READY, &atm_vcc->flags);
fs_dprintk (FS_DEBUG_QSIZE, "--==**[%d]**==--", dev->ntxpckts);
if (vcc->last_skb) {
fs_dprintk (FS_DEBUG_QUEUE, "Waiting for skb %p to be sent.\n",
vcc->last_skb);
interruptible_sleep_on (& vcc->close_wait);
}
txtp = &atm_vcc->qos.txtp;
rxtp = &atm_vcc->qos.rxtp;
if (DO_DIRECTION (txtp)) {
submit_command (dev, &dev->hp_txq,
QE_CMD_TX_PURGE_INH | vcc->channo, 0,0,0);
clear_bit (vcc->channo, dev->tx_inuse);
}
if (DO_DIRECTION (rxtp)) {
submit_command (dev, &dev->hp_txq,
QE_CMD_RX_PURGE_INH | QE_CMD_IMM_INQ | vcc->channo, 0,0,0);
dev->atm_vccs [vcc->channo] = NULL;
if (IS_FS50 (dev)) {
submit_command (dev, &dev->hp_txq,
QE_CMD_REG_WR | QE_CMD_IMM_INQ,
0x80 + vcc->channo, -1, 0 );
}
}
fs_dprintk (FS_DEBUG_ALLOC, "Free vcc: %p\n", vcc);
kfree (vcc);
func_exit ();
}
static int fs_send (struct atm_vcc *atm_vcc, struct sk_buff *skb)
{
struct fs_dev *dev = FS_DEV (atm_vcc->dev);
struct fs_vcc *vcc = FS_VCC (atm_vcc);
struct FS_BPENTRY *td;
func_enter ();
fs_dprintk (FS_DEBUG_TXMEM, "I");
fs_dprintk (FS_DEBUG_SEND, "Send: atm_vcc %p skb %p vcc %p dev %p\n",
atm_vcc, skb, vcc, dev);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc t-skb: %p (atm_send)\n", skb);
ATM_SKB(skb)->vcc = atm_vcc;
vcc->last_skb = skb;
td = kmalloc (sizeof (struct FS_BPENTRY), GFP_ATOMIC);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc transd: %p(%Zd)\n", td, sizeof (struct FS_BPENTRY));
if (!td) {
return -ENOMEM;
}
fs_dprintk (FS_DEBUG_SEND, "first word in buffer: %x\n",
*(int *) skb->data);
td->flags = TD_EPI | TD_DATA | skb->len;
td->next = 0;
td->bsa = virt_to_bus (skb->data);
td->skb = skb;
td->dev = dev;
dev->ntxpckts++;
#ifdef DEBUG_EXTRA
da[qd] = td;
dq[qd].flags = td->flags;
dq[qd].next = td->next;
dq[qd].bsa = td->bsa;
dq[qd].skb = td->skb;
dq[qd].dev = td->dev;
qd++;
if (qd >= 60) qd = 0;
#endif
submit_queue (dev, &dev->hp_txq,
QE_TRANSMIT_DE | vcc->channo,
virt_to_bus (td), 0,
virt_to_bus (td));
fs_dprintk (FS_DEBUG_QUEUE, "in send: txq %d txrq %d\n",
read_fs (dev, Q_EA (dev->hp_txq.offset)) -
read_fs (dev, Q_SA (dev->hp_txq.offset)),
read_fs (dev, Q_EA (dev->tx_relq.offset)) -
read_fs (dev, Q_SA (dev->tx_relq.offset)));
func_exit ();
return 0;
}
static void undocumented_pci_fix(struct pci_dev *pdev)
{
u32 tint;
pci_read_config_dword (pdev, 0x28, &tint);
if (tint != 0x80) {
tint = 0x80;
pci_write_config_dword (pdev, 0x28, tint);
}
}
static void write_phy(struct fs_dev *dev, int regnum, int val)
{
submit_command (dev, &dev->hp_txq, QE_CMD_PRP_WR | QE_CMD_IMM_INQ,
regnum, val, 0);
}
static int init_phy(struct fs_dev *dev, struct reginit_item *reginit)
{
int i;
func_enter ();
while (reginit->reg != PHY_EOF) {
if (reginit->reg == PHY_CLEARALL) {
for (i=0;i<reginit->val;i++) {
write_phy (dev, i, 0);
}
} else {
write_phy (dev, reginit->reg, reginit->val);
}
reginit++;
}
func_exit ();
return 0;
}
static void reset_chip (struct fs_dev *dev)
{
int i;
write_fs (dev, SARMODE0, SARMODE0_SRTS0);
udelay (128);
for (i=0;i < FS_NR_FREE_POOLS;i++) {
write_fs (dev, FP_CNF (RXB_FP(i)), 0);
write_fs (dev, FP_SA (RXB_FP(i)), 0);
write_fs (dev, FP_EA (RXB_FP(i)), 0);
write_fs (dev, FP_CNT (RXB_FP(i)), 0);
write_fs (dev, FP_CTU (RXB_FP(i)), 0);
}
if (IS_FS50 (dev)) {
for (i=0;i<FS50_NR_CHANNELS;i++) {
write_fs (dev, 0x200 + i * 4, -1);
}
}
}
static void *aligned_kmalloc(int size, gfp_t flags, int alignment)
{
void *t;
if (alignment <= 0x10) {
t = kmalloc (size, flags);
if ((unsigned long)t & (alignment-1)) {
printk ("Kmalloc doesn't align things correctly! %p\n", t);
kfree (t);
return aligned_kmalloc (size, flags, alignment * 4);
}
return t;
}
printk (KERN_ERR "Request for > 0x10 alignment not yet implemented (hard!)\n");
return NULL;
}
static int init_q(struct fs_dev *dev, struct queue *txq, int queue,
int nentries, int is_rq)
{
int sz = nentries * sizeof (struct FS_QENTRY);
struct FS_QENTRY *p;
func_enter ();
fs_dprintk (FS_DEBUG_INIT, "Inititing queue at %x: %d entries:\n",
queue, nentries);
p = aligned_kmalloc (sz, GFP_KERNEL, 0x10);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc queue: %p(%d)\n", p, sz);
if (!p) return 0;
write_fs (dev, Q_SA(queue), virt_to_bus(p));
write_fs (dev, Q_EA(queue), virt_to_bus(p+nentries-1));
write_fs (dev, Q_WP(queue), virt_to_bus(p));
write_fs (dev, Q_RP(queue), virt_to_bus(p));
if (is_rq) {
write_fs (dev, Q_CNF(queue), 0 );
}
txq->sa = p;
txq->ea = p;
txq->offset = queue;
func_exit ();
return 1;
}
static int init_fp(struct fs_dev *dev, struct freepool *fp, int queue,
int bufsize, int nr_buffers)
{
func_enter ();
fs_dprintk (FS_DEBUG_INIT, "Inititing free pool at %x:\n", queue);
write_fs (dev, FP_CNF(queue), (bufsize * RBFP_RBS) | RBFP_RBSVAL | RBFP_CME);
write_fs (dev, FP_SA(queue), 0);
write_fs (dev, FP_EA(queue), 0);
write_fs (dev, FP_CTU(queue), 0);
write_fs (dev, FP_CNT(queue), 0);
fp->offset = queue;
fp->bufsize = bufsize;
fp->nr_buffers = nr_buffers;
func_exit ();
return 1;
}
static inline int nr_buffers_in_freepool (struct fs_dev *dev, struct freepool *fp)
{
#if 0
return read_fs (dev, FP_CNT (fp->offset));
#else
return fp->n;
#endif
}
static void top_off_fp (struct fs_dev *dev, struct freepool *fp,
gfp_t gfp_flags)
{
struct FS_BPENTRY *qe, *ne;
struct sk_buff *skb;
int n = 0;
u32 qe_tmp;
fs_dprintk (FS_DEBUG_QUEUE, "Topping off queue at %x (%d-%d/%d)\n",
fp->offset, read_fs (dev, FP_CNT (fp->offset)), fp->n,
fp->nr_buffers);
while (nr_buffers_in_freepool(dev, fp) < fp->nr_buffers) {
skb = alloc_skb (fp->bufsize, gfp_flags);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc rec-skb: %p(%d)\n", skb, fp->bufsize);
if (!skb) break;
ne = kmalloc (sizeof (struct FS_BPENTRY), gfp_flags);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc rec-d: %p(%Zd)\n", ne, sizeof (struct FS_BPENTRY));
if (!ne) {
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-skb: %p\n", skb);
dev_kfree_skb_any (skb);
break;
}
fs_dprintk (FS_DEBUG_QUEUE, "Adding skb %p desc %p -> %p(%p) ",
skb, ne, skb->data, skb->head);
n++;
ne->flags = FP_FLAGS_EPI | fp->bufsize;
ne->next = virt_to_bus (NULL);
ne->bsa = virt_to_bus (skb->data);
ne->aal_bufsize = fp->bufsize;
ne->skb = skb;
ne->fp = fp;
qe_tmp = read_fs (dev, FP_EA(fp->offset));
fs_dprintk (FS_DEBUG_QUEUE, "link at %x\n", qe_tmp);
if (qe_tmp) {
qe = bus_to_virt ((long) qe_tmp);
qe->next = virt_to_bus(ne);
qe->flags &= ~FP_FLAGS_EPI;
} else
write_fs (dev, FP_SA(fp->offset), virt_to_bus(ne));
write_fs (dev, FP_EA(fp->offset), virt_to_bus (ne));
fp->n++;
write_fs (dev, FP_CTU(fp->offset), 1);
}
fs_dprintk (FS_DEBUG_QUEUE, "Added %d entries. \n", n);
}
static void free_queue(struct fs_dev *dev, struct queue *txq)
{
func_enter ();
write_fs (dev, Q_SA(txq->offset), 0);
write_fs (dev, Q_EA(txq->offset), 0);
write_fs (dev, Q_RP(txq->offset), 0);
write_fs (dev, Q_WP(txq->offset), 0);
fs_dprintk (FS_DEBUG_ALLOC, "Free queue: %p\n", txq->sa);
kfree (txq->sa);
func_exit ();
}
static void free_freepool(struct fs_dev *dev, struct freepool *fp)
{
func_enter ();
write_fs (dev, FP_CNF(fp->offset), 0);
write_fs (dev, FP_SA (fp->offset), 0);
write_fs (dev, FP_EA (fp->offset), 0);
write_fs (dev, FP_CNT(fp->offset), 0);
write_fs (dev, FP_CTU(fp->offset), 0);
func_exit ();
}
static irqreturn_t fs_irq (int irq, void *dev_id)
{
int i;
u32 status;
struct fs_dev *dev = dev_id;
status = read_fs (dev, ISR);
if (!status)
return IRQ_NONE;
func_enter ();
#ifdef IRQ_RATE_LIMIT
{
static int lastjif;
static int nintr=0;
if (lastjif == jiffies) {
if (++nintr > IRQ_RATE_LIMIT) {
free_irq (dev->irq, dev_id);
printk (KERN_ERR "fs: Too many interrupts. Turning off interrupt %d.\n",
dev->irq);
}
} else {
lastjif = jiffies;
nintr = 0;
}
}
#endif
fs_dprintk (FS_DEBUG_QUEUE, "in intr: txq %d txrq %d\n",
read_fs (dev, Q_EA (dev->hp_txq.offset)) -
read_fs (dev, Q_SA (dev->hp_txq.offset)),
read_fs (dev, Q_EA (dev->tx_relq.offset)) -
read_fs (dev, Q_SA (dev->tx_relq.offset)));
if (fs_debug & FS_DEBUG_IRQ) {
fs_dprintk (FS_DEBUG_IRQ, "IRQ status:");
for (i=0;i<27;i++)
if (status & (1 << i))
fs_dprintk (FS_DEBUG_IRQ, " %s", irq_bitname[i]);
fs_dprintk (FS_DEBUG_IRQ, "\n");
}
if (status & ISR_RBRQ0_W) {
fs_dprintk (FS_DEBUG_IRQ, "Iiiin-coming (0)!!!!\n");
process_incoming (dev, &dev->rx_rq[0]);
top_off_fp (dev, &dev->rx_fp[0], GFP_ATOMIC);
top_off_fp (dev, &dev->rx_fp[1], GFP_ATOMIC);
}
if (status & ISR_RBRQ1_W) {
fs_dprintk (FS_DEBUG_IRQ, "Iiiin-coming (1)!!!!\n");
process_incoming (dev, &dev->rx_rq[1]);
top_off_fp (dev, &dev->rx_fp[2], GFP_ATOMIC);
top_off_fp (dev, &dev->rx_fp[3], GFP_ATOMIC);
}
if (status & ISR_RBRQ2_W) {
fs_dprintk (FS_DEBUG_IRQ, "Iiiin-coming (2)!!!!\n");
process_incoming (dev, &dev->rx_rq[2]);
top_off_fp (dev, &dev->rx_fp[4], GFP_ATOMIC);
top_off_fp (dev, &dev->rx_fp[5], GFP_ATOMIC);
}
if (status & ISR_RBRQ3_W) {
fs_dprintk (FS_DEBUG_IRQ, "Iiiin-coming (3)!!!!\n");
process_incoming (dev, &dev->rx_rq[3]);
top_off_fp (dev, &dev->rx_fp[6], GFP_ATOMIC);
top_off_fp (dev, &dev->rx_fp[7], GFP_ATOMIC);
}
if (status & ISR_CSQ_W) {
fs_dprintk (FS_DEBUG_IRQ, "Command executed ok!\n");
process_return_queue (dev, &dev->st_q);
}
if (status & ISR_TBRQ_W) {
fs_dprintk (FS_DEBUG_IRQ, "Data tramsitted!\n");
process_txdone_queue (dev, &dev->tx_relq);
}
func_exit ();
return IRQ_HANDLED;
}
static void fs_poll (unsigned long data)
{
struct fs_dev *dev = (struct fs_dev *) data;
fs_irq (0, dev);
dev->timer.expires = jiffies + FS_POLL_FREQ;
add_timer (&dev->timer);
}
static int fs_init(struct fs_dev *dev)
{
struct pci_dev *pci_dev;
int isr, to;
int i;
func_enter ();
pci_dev = dev->pci_dev;
printk (KERN_INFO "found a FireStream %d card, base %16llx, irq%d.\n",
IS_FS50(dev)?50:155,
(unsigned long long)pci_resource_start(pci_dev, 0),
dev->pci_dev->irq);
if (fs_debug & FS_DEBUG_INIT)
my_hd ((unsigned char *) dev, sizeof (*dev));
undocumented_pci_fix (pci_dev);
dev->hw_base = pci_resource_start(pci_dev, 0);
dev->base = ioremap(dev->hw_base, 0x1000);
reset_chip (dev);
write_fs (dev, SARMODE0, 0
| (0 * SARMODE0_SHADEN)
| (1 * SARMODE0_INTMODE_READCLEAR)
| (1 * SARMODE0_CWRE)
| (IS_FS50(dev) ? SARMODE0_PRPWT_FS50_5:
SARMODE0_PRPWT_FS155_3)
| (1 * SARMODE0_CALSUP_1)
| (IS_FS50(dev) ? (0
| SARMODE0_RXVCS_32
| SARMODE0_ABRVCS_32
| SARMODE0_TXVCS_32):
(0
| SARMODE0_RXVCS_1k
| SARMODE0_ABRVCS_1k
| SARMODE0_TXVCS_1k)));
to = 100;
while (--to) {
isr = read_fs (dev, ISR);
if (isr & ISR_INIT_ERR) {
printk (KERN_ERR "Error initializing the FS... \n");
goto unmap;
}
if (isr & ISR_INIT) {
fs_dprintk (FS_DEBUG_INIT, "Ha! Initialized OK!\n");
break;
}
msleep(10);
}
if (!to) {
printk (KERN_ERR "timeout initializing the FS... \n");
goto unmap;
}
dev->channel_mask = 0x1f;
dev->channo = 0;
write_fs (dev, SARMODE1, 0
| (fs_keystream * SARMODE1_DEFHEC)
| ((loopback == 1) * SARMODE1_TSTLP)
| (1 * SARMODE1_DCRM)
| (1 * SARMODE1_DCOAM)
| (0 * SARMODE1_OAMCRC)
| (0 * SARMODE1_DUMPE)
| (0 * SARMODE1_GPLEN)
| (0 * SARMODE1_GNAM)
| (0 * SARMODE1_GVAS)
| (0 * SARMODE1_GPAS)
| (1 * SARMODE1_GPRI)
| (0 * SARMODE1_PMS)
| (0 * SARMODE1_GFCR)
| (1 * SARMODE1_HECM2)
| (1 * SARMODE1_HECM1)
| (1 * SARMODE1_HECM0)
| (1 << 12)
| (0 * 0xff) );
write_fs (dev, TMCONF, 0x0000000f);
write_fs (dev, CALPRESCALE, 0x01010101 * num);
write_fs (dev, 0x80, 0x000F00E4);
write_fs (dev, CELLOSCONF, 0
| ( 0 * CELLOSCONF_CEN)
| ( CELLOSCONF_SC1)
| (0x80 * CELLOSCONF_COBS)
| (num * CELLOSCONF_COPK)
| (num * CELLOSCONF_COST));
write_fs (dev, CELLOSCONF_COST, 0x0B809191);
if (IS_FS50 (dev)) {
write_fs (dev, RAS0, RAS0_DCD_XHLT);
dev->atm_dev->ci_range.vpi_bits = 12;
dev->atm_dev->ci_range.vci_bits = 16;
dev->nchannels = FS50_NR_CHANNELS;
} else {
write_fs (dev, RAS0, RAS0_DCD_XHLT
| (((1 << FS155_VPI_BITS) - 1) * RAS0_VPSEL)
| (((1 << FS155_VCI_BITS) - 1) * RAS0_VCSEL));
dev->atm_dev->ci_range.vpi_bits = FS155_VPI_BITS;
dev->atm_dev->ci_range.vci_bits = FS155_VCI_BITS;
write_fs (dev, RAC, 0);
write_fs (dev, RAM, (1 << (28 - FS155_VPI_BITS - FS155_VCI_BITS)) - 1);
dev->nchannels = FS155_NR_CHANNELS;
}
dev->atm_vccs = kcalloc (dev->nchannels, sizeof (struct atm_vcc *),
GFP_KERNEL);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc atmvccs: %p(%Zd)\n",
dev->atm_vccs, dev->nchannels * sizeof (struct atm_vcc *));
if (!dev->atm_vccs) {
printk (KERN_WARNING "Couldn't allocate memory for VCC buffers. Woops!\n");
goto unmap;
}
dev->tx_inuse = kzalloc (dev->nchannels / 8 , GFP_KERNEL);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc tx_inuse: %p(%d)\n",
dev->atm_vccs, dev->nchannels / 8);
if (!dev->tx_inuse) {
printk (KERN_WARNING "Couldn't allocate memory for tx_inuse bits!\n");
goto unmap;
}
write_fs (dev, DMAMR, DMAMR_TX_MODE_FULL);
init_q (dev, &dev->hp_txq, TX_PQ(TXQ_HP), TXQ_NENTRIES, 0);
init_q (dev, &dev->lp_txq, TX_PQ(TXQ_LP), TXQ_NENTRIES, 0);
init_q (dev, &dev->tx_relq, TXB_RQ, TXQ_NENTRIES, 1);
init_q (dev, &dev->st_q, ST_Q, TXQ_NENTRIES, 1);
for (i=0;i < FS_NR_FREE_POOLS;i++) {
init_fp (dev, &dev->rx_fp[i], RXB_FP(i),
rx_buf_sizes[i], rx_pool_sizes[i]);
top_off_fp (dev, &dev->rx_fp[i], GFP_KERNEL);
}
for (i=0;i < FS_NR_RX_QUEUES;i++)
init_q (dev, &dev->rx_rq[i], RXB_RQ(i), RXRQ_NENTRIES, 1);
dev->irq = pci_dev->irq;
if (request_irq (dev->irq, fs_irq, IRQF_SHARED, "firestream", dev)) {
printk (KERN_WARNING "couldn't get irq %d for firestream.\n", pci_dev->irq);
goto unmap;
}
fs_dprintk (FS_DEBUG_INIT, "Grabbed irq %d for dev at %p.\n", dev->irq, dev);
write_fs (dev, IMR, 0
| ISR_RBRQ0_W
| ISR_RBRQ1_W
| ISR_RBRQ2_W
| ISR_RBRQ3_W
| ISR_TBRQ_W
| ISR_CSQ_W);
write_fs (dev, SARMODE0, 0
| (0 * SARMODE0_SHADEN)
| (1 * SARMODE0_GINT)
| (1 * SARMODE0_INTMODE_READCLEAR)
| (0 * SARMODE0_CWRE)
| (IS_FS50(dev)?SARMODE0_PRPWT_FS50_5:
SARMODE0_PRPWT_FS155_3)
| (1 * SARMODE0_CALSUP_1)
| (IS_FS50 (dev)?(0
| SARMODE0_RXVCS_32
| SARMODE0_ABRVCS_32
| SARMODE0_TXVCS_32):
(0
| SARMODE0_RXVCS_1k
| SARMODE0_ABRVCS_1k
| SARMODE0_TXVCS_1k))
| (1 * SARMODE0_RUN));
init_phy (dev, PHY_NTC_INIT);
if (loopback == 2) {
write_phy (dev, 0x39, 0x000e);
}
#ifdef FS_POLL_FREQ
init_timer (&dev->timer);
dev->timer.data = (unsigned long) dev;
dev->timer.function = fs_poll;
dev->timer.expires = jiffies + FS_POLL_FREQ;
add_timer (&dev->timer);
#endif
dev->atm_dev->dev_data = dev;
func_exit ();
return 0;
unmap:
iounmap(dev->base);
return 1;
}
static int firestream_init_one(struct pci_dev *pci_dev,
const struct pci_device_id *ent)
{
struct atm_dev *atm_dev;
struct fs_dev *fs_dev;
if (pci_enable_device(pci_dev))
goto err_out;
fs_dev = kzalloc (sizeof (struct fs_dev), GFP_KERNEL);
fs_dprintk (FS_DEBUG_ALLOC, "Alloc fs-dev: %p(%Zd)\n",
fs_dev, sizeof (struct fs_dev));
if (!fs_dev)
goto err_out;
atm_dev = atm_dev_register("fs", &pci_dev->dev, &ops, -1, NULL);
if (!atm_dev)
goto err_out_free_fs_dev;
fs_dev->pci_dev = pci_dev;
fs_dev->atm_dev = atm_dev;
fs_dev->flags = ent->driver_data;
if (fs_init(fs_dev))
goto err_out_free_atm_dev;
fs_dev->next = fs_boards;
fs_boards = fs_dev;
return 0;
err_out_free_atm_dev:
atm_dev_deregister(atm_dev);
err_out_free_fs_dev:
kfree(fs_dev);
err_out:
return -ENODEV;
}
static void firestream_remove_one(struct pci_dev *pdev)
{
int i;
struct fs_dev *dev, *nxtdev;
struct fs_vcc *vcc;
struct FS_BPENTRY *fp, *nxt;
func_enter ();
#if 0
printk ("hptxq:\n");
for (i=0;i<60;i++) {
printk ("%d: %08x %08x %08x %08x \n",
i, pq[qp].cmd, pq[qp].p0, pq[qp].p1, pq[qp].p2);
qp++;
if (qp >= 60) qp = 0;
}
printk ("descriptors:\n");
for (i=0;i<60;i++) {
printk ("%d: %p: %08x %08x %p %p\n",
i, da[qd], dq[qd].flags, dq[qd].bsa, dq[qd].skb, dq[qd].dev);
qd++;
if (qd >= 60) qd = 0;
}
#endif
for (dev = fs_boards;dev != NULL;dev=nxtdev) {
fs_dprintk (FS_DEBUG_CLEANUP, "Releasing resources for dev at %p.\n", dev);
for (i=0;i < dev->nchannels;i++) {
if (dev->atm_vccs[i]) {
vcc = FS_VCC (dev->atm_vccs[i]);
submit_command (dev, &dev->hp_txq,
QE_CMD_TX_PURGE_INH | QE_CMD_IMM_INQ | vcc->channo, 0,0,0);
submit_command (dev, &dev->hp_txq,
QE_CMD_RX_PURGE_INH | QE_CMD_IMM_INQ | vcc->channo, 0,0,0);
}
}
for (i=0;i < FS_NR_FREE_POOLS;i++) {
for (fp=bus_to_virt (read_fs (dev, FP_SA(dev->rx_fp[i].offset)));
!(fp->flags & FP_FLAGS_EPI);fp = nxt) {
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-skb: %p\n", fp->skb);
dev_kfree_skb_any (fp->skb);
nxt = bus_to_virt (fp->next);
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-d: %p\n", fp);
kfree (fp);
}
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-skb: %p\n", fp->skb);
dev_kfree_skb_any (fp->skb);
fs_dprintk (FS_DEBUG_ALLOC, "Free rec-d: %p\n", fp);
kfree (fp);
}
reset_chip (dev);
fs_dprintk (FS_DEBUG_CLEANUP, "Freeing irq%d.\n", dev->irq);
free_irq (dev->irq, dev);
del_timer (&dev->timer);
atm_dev_deregister(dev->atm_dev);
free_queue (dev, &dev->hp_txq);
free_queue (dev, &dev->lp_txq);
free_queue (dev, &dev->tx_relq);
free_queue (dev, &dev->st_q);
fs_dprintk (FS_DEBUG_ALLOC, "Free atmvccs: %p\n", dev->atm_vccs);
kfree (dev->atm_vccs);
for (i=0;i< FS_NR_FREE_POOLS;i++)
free_freepool (dev, &dev->rx_fp[i]);
for (i=0;i < FS_NR_RX_QUEUES;i++)
free_queue (dev, &dev->rx_rq[i]);
iounmap(dev->base);
fs_dprintk (FS_DEBUG_ALLOC, "Free fs-dev: %p\n", dev);
nxtdev = dev->next;
kfree (dev);
}
func_exit ();
}
static int __init firestream_init_module (void)
{
int error;
func_enter ();
error = pci_register_driver(&firestream_driver);
func_exit ();
return error;
}
static void __exit firestream_cleanup_module(void)
{
pci_unregister_driver(&firestream_driver);
}
