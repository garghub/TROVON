static inline void D_L1L2(struct isac *isac, int pr, void *arg)
{
struct hisax_if *ifc = (struct hisax_if *) &isac->hisax_d_if;
DBG(DBG_PR, "pr %#x", pr);
ifc->l1l2(ifc, pr, arg);
}
static void ph_command(struct isac *isac, unsigned int command)
{
DBG(DBG_L1M, "ph_command %#x", command);
switch (isac->type) {
case TYPE_ISAC:
isac->write_isac(isac, ISAC_CIX0, (command << 2) | 3);
break;
case TYPE_ISACSX:
isac->write_isac(isac, ISACSX_CIX0, (command << 4) | (7 << 1));
break;
}
}
static void l1_di(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_RESET);
ph_command(isac, ISAC_CMD_DI);
}
static void l1_di_deact_ind(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_RESET);
D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
ph_command(isac, ISAC_CMD_DI);
}
static void l1_go_f3pdown(struct FsmInst *fi, int event, void *arg)
{
FsmChangeState(fi, ST_L1_F3_PDOWN);
}
static void l1_go_f3pend_deact_ind(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_F3_PEND_DEACT);
D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
ph_command(isac, ISAC_CMD_DI);
}
static void l1_go_f3pend(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_F3_PEND_DEACT);
ph_command(isac, ISAC_CMD_DI);
}
static void l1_go_f4(struct FsmInst *fi, int event, void *arg)
{
FsmChangeState(fi, ST_L1_F4);
}
static void l1_go_f5(struct FsmInst *fi, int event, void *arg)
{
FsmChangeState(fi, ST_L1_F5);
}
static void l1_go_f6(struct FsmInst *fi, int event, void *arg)
{
FsmChangeState(fi, ST_L1_F6);
}
static void l1_go_f6_deact_ind(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_F6);
D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
}
static void l1_go_f7_act_ind(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmDelTimer(&isac->timer, 0);
FsmChangeState(fi, ST_L1_F7);
ph_command(isac, ISAC_CMD_AR8);
D_L1L2(isac, PH_ACTIVATE | INDICATION, NULL);
}
static void l1_go_f8(struct FsmInst *fi, int event, void *arg)
{
FsmChangeState(fi, ST_L1_F8);
}
static void l1_go_f8_deact_ind(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmChangeState(fi, ST_L1_F8);
D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
}
static void l1_ar8(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
FsmRestartTimer(&isac->timer, TIMER3_VALUE, EV_TIMER3, NULL, 2);
ph_command(isac, ISAC_CMD_AR8);
}
static void l1_timer3(struct FsmInst *fi, int event, void *arg)
{
struct isac *isac = fi->userdata;
ph_command(isac, ISAC_CMD_DI);
D_L1L2(isac, PH_DEACTIVATE | INDICATION, NULL);
}
static void l1m_debug(struct FsmInst *fi, char *fmt, ...)
{
va_list args;
char buf[256];
va_start(args, fmt);
vsnprintf(buf, sizeof(buf), fmt, args);
DBG(DBG_L1M, "%s", buf);
va_end(args);
}
static void isac_version(struct isac *cs)
{
int val;
val = cs->read_isac(cs, ISAC_RBCH);
DBG(1, "ISAC version (%x): %s", val, ISACVer[(val >> 5) & 3]);
}
static void isac_empty_fifo(struct isac *isac, int count)
{
u_char *ptr;
DBG(DBG_IRQ, "count %d", count);
if ((isac->rcvidx + count) >= MAX_DFRAME_LEN_L1) {
DBG(DBG_WARN, "overrun %d", isac->rcvidx + count);
isac->write_isac(isac, ISAC_CMDR, ISAC_CMDR_RMC);
isac->rcvidx = 0;
return;
}
ptr = isac->rcvbuf + isac->rcvidx;
isac->rcvidx += count;
isac->read_isac_fifo(isac, ptr, count);
isac->write_isac(isac, ISAC_CMDR, ISAC_CMDR_RMC);
DBG_PACKET(DBG_RFIFO, ptr, count);
}
static void isac_fill_fifo(struct isac *isac)
{
int count;
unsigned char cmd;
u_char *ptr;
BUG_ON(!isac->tx_skb);
count = isac->tx_skb->len;
BUG_ON(count <= 0);
DBG(DBG_IRQ, "count %d", count);
if (count > 0x20) {
count = 0x20;
cmd = ISAC_CMDR_XTF;
} else {
cmd = ISAC_CMDR_XTF | ISAC_CMDR_XME;
}
ptr = isac->tx_skb->data;
skb_pull(isac->tx_skb, count);
isac->tx_cnt += count;
DBG_PACKET(DBG_XFIFO, ptr, count);
isac->write_isac_fifo(isac, ptr, count);
isac->write_isac(isac, ISAC_CMDR, cmd);
}
static void isac_retransmit(struct isac *isac)
{
if (!isac->tx_skb) {
DBG(DBG_WARN, "no skb");
return;
}
skb_push(isac->tx_skb, isac->tx_cnt);
isac->tx_cnt = 0;
}
static inline void isac_cisq_interrupt(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISAC_CIR0);
DBG(DBG_IRQ, "CIR0 %#x", val);
if (val & ISAC_CIR0_CIC0) {
DBG(DBG_IRQ, "CODR0 %#x", (val >> 2) & 0xf);
FsmEvent(&isac->l1m, (val >> 2) & 0xf, NULL);
}
if (val & ISAC_CIR0_CIC1) {
val = isac->read_isac(isac, ISAC_CIR1);
DBG(DBG_WARN, "ISAC CIR1 %#x", val );
}
}
static inline void isac_rme_interrupt(struct isac *isac)
{
unsigned char val;
int count;
struct sk_buff *skb;
val = isac->read_isac(isac, ISAC_RSTA);
if ((val & (ISAC_RSTA_RDO | ISAC_RSTA_CRC | ISAC_RSTA_RAB) )
!= ISAC_RSTA_CRC) {
DBG(DBG_WARN, "RSTA %#x, dropped", val);
isac->write_isac(isac, ISAC_CMDR, ISAC_CMDR_RMC);
goto out;
}
count = isac->read_isac(isac, ISAC_RBCL) & 0x1f;
DBG(DBG_IRQ, "RBCL %#x", count);
if (count == 0)
count = 0x20;
isac_empty_fifo(isac, count);
count = isac->rcvidx;
if (count < 1) {
DBG(DBG_WARN, "count %d < 1", count);
goto out;
}
skb = alloc_skb(count, GFP_ATOMIC);
if (!skb) {
DBG(DBG_WARN, "no memory, dropping\n");
goto out;
}
memcpy(skb_put(skb, count), isac->rcvbuf, count);
DBG_SKB(DBG_RPACKET, skb);
D_L1L2(isac, PH_DATA | INDICATION, skb);
out:
isac->rcvidx = 0;
}
static inline void isac_xpr_interrupt(struct isac *isac)
{
if (!isac->tx_skb)
return;
if (isac->tx_skb->len > 0) {
isac_fill_fifo(isac);
return;
}
dev_kfree_skb_irq(isac->tx_skb);
isac->tx_cnt = 0;
isac->tx_skb = NULL;
D_L1L2(isac, PH_DATA | CONFIRM, NULL);
}
static inline void isac_exi_interrupt(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISAC_EXIR);
DBG(2, "EXIR %#x", val);
if (val & ISAC_EXIR_XMR) {
DBG(DBG_WARN, "ISAC XMR");
isac_retransmit(isac);
}
if (val & ISAC_EXIR_XDU) {
DBG(DBG_WARN, "ISAC XDU");
isac_retransmit(isac);
}
if (val & ISAC_EXIR_MOS) {
DBG(DBG_WARN, "MOS");
val = isac->read_isac(isac, ISAC_MOSR);
DBG(2, "ISAC MOSR %#x", val);
}
}
void isac_irq(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISAC_ISTA);
DBG(DBG_IRQ, "ISTA %#x", val);
if (val & ISAC_ISTA_EXI) {
DBG(DBG_IRQ, "EXI");
isac_exi_interrupt(isac);
}
if (val & ISAC_ISTA_XPR) {
DBG(DBG_IRQ, "XPR");
isac_xpr_interrupt(isac);
}
if (val & ISAC_ISTA_RME) {
DBG(DBG_IRQ, "RME");
isac_rme_interrupt(isac);
}
if (val & ISAC_ISTA_RPF) {
DBG(DBG_IRQ, "RPF");
isac_empty_fifo(isac, 0x20);
}
if (val & ISAC_ISTA_CISQ) {
DBG(DBG_IRQ, "CISQ");
isac_cisq_interrupt(isac);
}
if (val & ISAC_ISTA_RSC) {
DBG(DBG_WARN, "RSC");
}
if (val & ISAC_ISTA_SIN) {
DBG(DBG_WARN, "SIN");
}
isac->write_isac(isac, ISAC_MASK, 0xff);
isac->write_isac(isac, ISAC_MASK, 0x00);
}
static inline void isacsx_cic_interrupt(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISACSX_CIR0);
DBG(DBG_IRQ, "CIR0 %#x", val);
if (val & ISACSX_CIR0_CIC0) {
DBG(DBG_IRQ, "CODR0 %#x", val >> 4);
FsmEvent(&isac->l1m, val >> 4, NULL);
}
}
static inline void isacsx_rme_interrupt(struct isac *isac)
{
int count;
struct sk_buff *skb;
unsigned char val;
val = isac->read_isac(isac, ISACSX_RSTAD);
if ((val & (ISACSX_RSTAD_VFR |
ISACSX_RSTAD_RDO |
ISACSX_RSTAD_CRC |
ISACSX_RSTAD_RAB))
!= (ISACSX_RSTAD_VFR | ISACSX_RSTAD_CRC)) {
DBG(DBG_WARN, "RSTAD %#x, dropped", val);
isac->write_isac(isac, ISACSX_CMDRD, ISACSX_CMDRD_RMC);
goto out;
}
count = isac->read_isac(isac, ISACSX_RBCLD) & 0x1f;
DBG(DBG_IRQ, "RBCLD %#x", count);
if (count == 0)
count = 0x20;
isac_empty_fifo(isac, count);
count = isac->rcvidx - 1;
if (count < 1) {
DBG(DBG_WARN, "count %d < 1", count);
goto out;
}
skb = dev_alloc_skb(count);
if (!skb) {
DBG(DBG_WARN, "no memory, dropping");
goto out;
}
memcpy(skb_put(skb, count), isac->rcvbuf, count);
DBG_SKB(DBG_RPACKET, skb);
D_L1L2(isac, PH_DATA | INDICATION, skb);
out:
isac->rcvidx = 0;
}
static inline void isacsx_xpr_interrupt(struct isac *isac)
{
if (!isac->tx_skb)
return;
if (isac->tx_skb->len > 0) {
isac_fill_fifo(isac);
return;
}
dev_kfree_skb_irq(isac->tx_skb);
isac->tx_skb = NULL;
isac->tx_cnt = 0;
D_L1L2(isac, PH_DATA | CONFIRM, NULL);
}
static inline void isacsx_icd_interrupt(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISACSX_ISTAD);
DBG(DBG_IRQ, "ISTAD %#x", val);
if (val & ISACSX_ISTAD_XDU) {
DBG(DBG_WARN, "ISTAD XDU");
isac_retransmit(isac);
}
if (val & ISACSX_ISTAD_XMR) {
DBG(DBG_WARN, "ISTAD XMR");
isac_retransmit(isac);
}
if (val & ISACSX_ISTAD_XPR) {
DBG(DBG_IRQ, "ISTAD XPR");
isacsx_xpr_interrupt(isac);
}
if (val & ISACSX_ISTAD_RFO) {
DBG(DBG_WARN, "ISTAD RFO");
isac->write_isac(isac, ISACSX_CMDRD, ISACSX_CMDRD_RMC);
}
if (val & ISACSX_ISTAD_RME) {
DBG(DBG_IRQ, "ISTAD RME");
isacsx_rme_interrupt(isac);
}
if (val & ISACSX_ISTAD_RPF) {
DBG(DBG_IRQ, "ISTAD RPF");
isac_empty_fifo(isac, 0x20);
}
}
void isacsx_irq(struct isac *isac)
{
unsigned char val;
val = isac->read_isac(isac, ISACSX_ISTA);
DBG(DBG_IRQ, "ISTA %#x", val);
if (val & ISACSX_ISTA_ICD)
isacsx_icd_interrupt(isac);
if (val & ISACSX_ISTA_CIC)
isacsx_cic_interrupt(isac);
}
void isac_init(struct isac *isac)
{
isac->tx_skb = NULL;
isac->l1m.fsm = &l1fsm;
isac->l1m.state = ST_L1_RESET;
#ifdef CONFIG_HISAX_DEBUG
isac->l1m.debug = 1;
#else
isac->l1m.debug = 0;
#endif
isac->l1m.userdata = isac;
isac->l1m.printdebug = l1m_debug;
FsmInitTimer(&isac->l1m, &isac->timer);
}
void isac_setup(struct isac *isac)
{
int val, eval;
isac->type = TYPE_ISAC;
isac_version(isac);
ph_command(isac, ISAC_CMD_RES);
isac->write_isac(isac, ISAC_MASK, 0xff);
isac->mocr = 0xaa;
if (test_bit(ISAC_IOM1, &isac->flags)) {
isac->write_isac(isac, ISAC_ADF2, 0x0);
isac->write_isac(isac, ISAC_SPCR, 0xa);
isac->write_isac(isac, ISAC_ADF1, 0x2);
isac->write_isac(isac, ISAC_STCR, 0x70);
isac->write_isac(isac, ISAC_MODE, 0xc9);
} else {
if (!isac->adf2)
isac->adf2 = 0x80;
isac->write_isac(isac, ISAC_ADF2, isac->adf2);
isac->write_isac(isac, ISAC_SQXR, 0x2f);
isac->write_isac(isac, ISAC_SPCR, 0x00);
isac->write_isac(isac, ISAC_STCR, 0x70);
isac->write_isac(isac, ISAC_MODE, 0xc9);
isac->write_isac(isac, ISAC_TIMR, 0x00);
isac->write_isac(isac, ISAC_ADF1, 0x00);
}
val = isac->read_isac(isac, ISAC_STAR);
DBG(2, "ISAC STAR %x", val);
val = isac->read_isac(isac, ISAC_MODE);
DBG(2, "ISAC MODE %x", val);
val = isac->read_isac(isac, ISAC_ADF2);
DBG(2, "ISAC ADF2 %x", val);
val = isac->read_isac(isac, ISAC_ISTA);
DBG(2, "ISAC ISTA %x", val);
if (val & 0x01) {
eval = isac->read_isac(isac, ISAC_EXIR);
DBG(2, "ISAC EXIR %x", eval);
}
val = isac->read_isac(isac, ISAC_CIR0);
DBG(2, "ISAC CIR0 %x", val);
FsmEvent(&isac->l1m, (val >> 2) & 0xf, NULL);
isac->write_isac(isac, ISAC_MASK, 0x0);
isac->write_isac(isac, ISAC_CMDR, ISAC_CMDR_XRES | ISAC_CMDR_RRES);
}
void isacsx_setup(struct isac *isac)
{
isac->type = TYPE_ISACSX;
isac->write_isac(isac, ISACSX_TR_CONF0, 0x00);
isac->write_isac(isac, ISACSX_TR_CONF2, 0x00);
isac->write_isac(isac, ISACSX_MODED, 0xc9);
isac->write_isac(isac, ISACSX_MASKD, 0x03);
isac->write_isac(isac, ISACSX_MASK,
~(ISACSX_ISTA_ICD | ISACSX_ISTA_CIC));
}
void isac_d_l2l1(struct hisax_if *hisax_d_if, int pr, void *arg)
{
struct isac *isac = hisax_d_if->priv;
struct sk_buff *skb = arg;
DBG(DBG_PR, "pr %#x", pr);
switch (pr) {
case PH_ACTIVATE | REQUEST:
FsmEvent(&isac->l1m, EV_PH_ACTIVATE_REQ, NULL);
break;
case PH_DEACTIVATE | REQUEST:
FsmEvent(&isac->l1m, EV_PH_DEACTIVATE_REQ, NULL);
break;
case PH_DATA | REQUEST:
DBG(DBG_PR, "PH_DATA REQUEST len %d", skb->len);
DBG_SKB(DBG_XPACKET, skb);
if (isac->l1m.state != ST_L1_F7) {
DBG(1, "L1 wrong state %d\n", isac->l1m.state);
dev_kfree_skb(skb);
break;
}
BUG_ON(isac->tx_skb);
isac->tx_skb = skb;
isac_fill_fifo(isac);
break;
}
}
static int __init hisax_isac_init(void)
{
printk(KERN_INFO "hisax_isac: ISAC-S/ISAC-SX ISDN driver v0.1.0\n");
l1fsm.state_count = L1_STATE_COUNT;
l1fsm.event_count = L1_EVENT_COUNT;
l1fsm.strState = strL1State;
l1fsm.strEvent = strL1Event;
return FsmNew(&l1fsm, L1FnList, ARRAY_SIZE(L1FnList));
}
static void __exit hisax_isac_exit(void)
{
FsmFree(&l1fsm);
}
