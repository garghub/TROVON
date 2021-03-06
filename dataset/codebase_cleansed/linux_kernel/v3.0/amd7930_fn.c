static void
WriteWordAmd7930(struct IsdnCardState *cs, BYTE reg, WORD val)
{
wByteAMD(cs, 0x00, reg);
wByteAMD(cs, 0x01, LOBYTE(val));
wByteAMD(cs, 0x01, HIBYTE(val));
}
static WORD
ReadWordAmd7930(struct IsdnCardState *cs, BYTE reg)
{
WORD res;
if(reg < 8) {
res = rByteAMD(cs, reg);
res += 256*rByteAMD(cs, reg);
}
else {
wByteAMD(cs, 0x00, reg);
res = rByteAMD(cs, 0x01);
res += 256*rByteAMD(cs, 0x01);
}
return (res);
}
static void
Amd7930_ph_command(struct IsdnCardState *cs, u_char command, char *s)
{
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "AMD7930: %s: ph_command 0x%02X", s, command);
cs->dc.amd7930.lmr1 = command;
wByteAMD(cs, 0xA3, command);
}
static void
Amd7930_get_state(struct IsdnCardState *cs) {
BYTE lsr = rByteAMD(cs, 0xA1);
cs->dc.amd7930.ph_state = (lsr & 0x7) + 2;
Amd7930_new_ph(cs);
}
static void
Amd7930_new_ph(struct IsdnCardState *cs)
{
u_char index = stateHelper[cs->dc.amd7930.old_state]*8 + stateHelper[cs->dc.amd7930.ph_state]-1;
u_char message = i430States[index];
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "AMD7930: new_ph %d, old_ph %d, message %d, index %d",
cs->dc.amd7930.ph_state, cs->dc.amd7930.old_state, message & 0x0f, index);
cs->dc.amd7930.old_state = cs->dc.amd7930.ph_state;
if ((message & 0xf0) && (cs->tx_skb)) {
wByteAMD(cs, 0x21, 0xC2);
wByteAMD(cs, 0x21, 0x02);
}
switch (message & 0x0f) {
case (1):
l1_msg(cs, HW_RESET | INDICATION, NULL);
Amd7930_get_state(cs);
break;
case (2):
l1_msg(cs, HW_DEACTIVATE | CONFIRM, NULL);
break;
case (3):
l1_msg(cs, HW_DEACTIVATE | INDICATION, NULL);
break;
case (4):
l1_msg(cs, HW_POWERUP | CONFIRM, NULL);
Amd7930_ph_command(cs, 0x50, "HW_ENABLE REQUEST");
break;
case (5):
l1_msg(cs, HW_RSYNC | INDICATION, NULL);
break;
case (6):
l1_msg(cs, HW_INFO4_P8 | INDICATION, NULL);
break;
case (7):
l1_msg(cs, HW_RSYNC | INDICATION, NULL);
l1_msg(cs, HW_INFO4_P8 | INDICATION, NULL);
break;
case (8):
l1_msg(cs, HW_POWERUP | CONFIRM, NULL);
case (9):
Amd7930_ph_command(cs, 0x40, "HW_ENABLE REQ cleared if set");
l1_msg(cs, HW_RSYNC | INDICATION, NULL);
l1_msg(cs, HW_INFO2 | INDICATION, NULL);
l1_msg(cs, HW_INFO4_P8 | INDICATION, NULL);
break;
case (10):
Amd7930_ph_command(cs, 0x40, "T3 expired, HW_ENABLE REQ cleared");
cs->dc.amd7930.old_state = 3;
break;
case (11):
l1_msg(cs, HW_INFO2 | INDICATION, NULL);
break;
default:
break;
}
}
static void
Amd7930_bh(struct work_struct *work)
{
struct IsdnCardState *cs =
container_of(work, struct IsdnCardState, tqueue);
struct PStack *stptr;
if (test_and_clear_bit(D_CLEARBUSY, &cs->event)) {
if (cs->debug)
debugl1(cs, "Amd7930: bh, D-Channel Busy cleared");
stptr = cs->stlist;
while (stptr != NULL) {
stptr->l1.l1l2(stptr, PH_PAUSE | CONFIRM, NULL);
stptr = stptr->next;
}
}
if (test_and_clear_bit(D_L1STATECHANGE, &cs->event)) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "AMD7930: bh, D_L1STATECHANGE");
Amd7930_new_ph(cs);
}
if (test_and_clear_bit(D_RCVBUFREADY, &cs->event)) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "AMD7930: bh, D_RCVBUFREADY");
DChannel_proc_rcv(cs);
}
if (test_and_clear_bit(D_XMTBUFREADY, &cs->event)) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "AMD7930: bh, D_XMTBUFREADY");
DChannel_proc_xmt(cs);
}
}
static void
Amd7930_empty_Dfifo(struct IsdnCardState *cs, int flag)
{
BYTE stat, der;
BYTE *ptr;
struct sk_buff *skb;
if ((cs->debug & L1_DEB_ISAC) && !(cs->debug & L1_DEB_ISAC_FIFO))
debugl1(cs, "Amd7930: empty_Dfifo");
ptr = cs->rcvbuf + cs->rcvidx;
AmdIrqOff(cs);
stat = rByteAMD(cs, 0x07);
while ( (stat & 2) && ((ptr-cs->rcvbuf) < MAX_DFRAME_LEN_L1) ) {
*ptr = rByteAMD(cs, 0x04);
ptr++;
stat = rByteAMD(cs, 0x07);
cs->rcvidx = ptr - cs->rcvbuf;
if (stat & 1) {
der = rWordAMD(cs, 0x03);
if(!der && !flag) {
rWordAMD(cs, 0x89);
if ((cs->rcvidx) > 0) {
if (!(skb = alloc_skb(cs->rcvidx, GFP_ATOMIC)))
printk(KERN_WARNING "HiSax: Amd7930: empty_Dfifo, D receive out of memory!\n");
else {
if (cs->debug & L1_DEB_ISAC_FIFO) {
char *t = cs->dlog;
t += sprintf(t, "Amd7930: empty_Dfifo cnt: %d |", cs->rcvidx);
QuickHex(t, cs->rcvbuf, cs->rcvidx);
debugl1(cs, cs->dlog);
}
memcpy(skb_put(skb, cs->rcvidx), cs->rcvbuf, cs->rcvidx);
skb_queue_tail(&cs->rq, skb);
}
}
}
ptr = cs->rcvbuf;
cs->rcvidx = 0;
schedule_event(cs, D_RCVBUFREADY);
}
}
if(cs->rcvidx >= MAX_DFRAME_LEN_L1) {
if (cs->debug & L1_DEB_WARN)
debugl1(cs, "AMD7930: empty_Dfifo L2-Framelength overrun");
cs->rcvidx = 0;
return;
}
AmdIrqOn(cs);
}
static void
Amd7930_fill_Dfifo(struct IsdnCardState *cs)
{
WORD dtcrr, dtcrw, len, count;
BYTE txstat, dmr3;
BYTE *ptr, *deb_ptr;
if ((cs->debug & L1_DEB_ISAC) && !(cs->debug & L1_DEB_ISAC_FIFO))
debugl1(cs, "Amd7930: fill_Dfifo");
if ((!cs->tx_skb) || (cs->tx_skb->len <= 0))
return;
dtcrw = 0;
if(!cs->dc.amd7930.tx_xmtlen)
len = dtcrw = cs->tx_skb->len;
else len = cs->dc.amd7930.tx_xmtlen;
AmdIrqOff(cs);
deb_ptr = ptr = cs->tx_skb->data;
txstat = 0x10;
while((txstat & 0x10) && (cs->tx_cnt < len)) {
wByteAMD(cs, 0x04, *ptr);
ptr++;
cs->tx_cnt++;
txstat= rByteAMD(cs, 0x07);
}
count = ptr - cs->tx_skb->data;
skb_pull(cs->tx_skb, count);
dtcrr = rWordAMD(cs, 0x85);
dmr3 = rByteAMD(cs, 0x8E);
if (cs->debug & L1_DEB_ISAC) {
debugl1(cs, "Amd7930: fill_Dfifo, DMR3: 0x%02X, DTCR read: 0x%04X write: 0x%02X 0x%02X", dmr3, dtcrr, LOBYTE(dtcrw), HIBYTE(dtcrw));
}
if(!cs->dc.amd7930.tx_xmtlen) {
wWordAMD(cs, 0x85, dtcrw);
cs->dc.amd7930.tx_xmtlen = dtcrw;
}
if (test_and_set_bit(FLG_DBUSY_TIMER, &cs->HW_Flags)) {
debugl1(cs, "Amd7930: fill_Dfifo dbusytimer running");
del_timer(&cs->dbusytimer);
}
init_timer(&cs->dbusytimer);
cs->dbusytimer.expires = jiffies + ((DBUSY_TIMER_VALUE * HZ) / 1000);
add_timer(&cs->dbusytimer);
if (cs->debug & L1_DEB_ISAC_FIFO) {
char *t = cs->dlog;
t += sprintf(t, "Amd7930: fill_Dfifo cnt: %d |", count);
QuickHex(t, deb_ptr, count);
debugl1(cs, cs->dlog);
}
AmdIrqOn(cs);
}
void Amd7930_interrupt(struct IsdnCardState *cs, BYTE irflags)
{
BYTE dsr1, dsr2, lsr;
WORD der;
while (irflags)
{
dsr1 = rByteAMD(cs, 0x02);
der = rWordAMD(cs, 0x03);
dsr2 = rByteAMD(cs, 0x07);
lsr = rByteAMD(cs, 0xA1);
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: interrupt: flags: 0x%02X, DSR1: 0x%02X, DSR2: 0x%02X, LSR: 0x%02X, DER=0x%04X", irflags, dsr1, dsr2, lsr, der);
if (der || (dsr2 & 4)) {
if (cs->debug & L1_DEB_WARN)
debugl1(cs, "Amd7930: interrupt: D error DER=0x%04X", der);
if (der & 2) {
wByteAMD(cs, 0x21, 0xC2);
wByteAMD(cs, 0x21, 0x02);
if (test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags))
del_timer(&cs->dbusytimer);
if (test_and_clear_bit(FLG_L1_DBUSY, &cs->HW_Flags))
schedule_event(cs, D_CLEARBUSY);
if (cs->tx_skb) {
skb_push(cs->tx_skb, cs->tx_cnt);
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen = 0;
Amd7930_fill_Dfifo(cs);
} else {
printk(KERN_WARNING "HiSax: Amd7930 D-Collision, no skb\n");
debugl1(cs, "Amd7930: interrupt: D-Collision, no skb");
}
}
Amd7930_empty_Dfifo(cs, 1);
if (test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags))
del_timer(&cs->dbusytimer);
if (test_and_clear_bit(FLG_L1_DBUSY, &cs->HW_Flags))
schedule_event(cs, D_CLEARBUSY);
if (cs->tx_skb) {
skb_push(cs->tx_skb, cs->tx_cnt);
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen = 0;
Amd7930_fill_Dfifo(cs);
}
}
if (irflags & 1) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: interrupt: clear Timer and fill D-TX-FIFO if data");
AmdIrqOff(cs);
if (test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags))
del_timer(&cs->dbusytimer);
if (test_and_clear_bit(FLG_L1_DBUSY, &cs->HW_Flags))
schedule_event(cs, D_CLEARBUSY);
if (cs->tx_skb) {
if (cs->tx_skb->len)
Amd7930_fill_Dfifo(cs);
}
AmdIrqOn(cs);
}
if ((irflags & 2) || (dsr1 & 2)) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: interrupt: empty D-FIFO");
Amd7930_empty_Dfifo(cs, 0);
}
if (dsr1 & 64) {
if (cs->debug & L1_DEB_ISAC) {
debugl1(cs, "Amd7930: interrupt: transmit packet ready");
}
AmdIrqOff(cs);
if (test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags))
del_timer(&cs->dbusytimer);
if (test_and_clear_bit(FLG_L1_DBUSY, &cs->HW_Flags))
schedule_event(cs, D_CLEARBUSY);
if (cs->tx_skb) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: interrupt: TX-Packet ready, freeing skb");
dev_kfree_skb_irq(cs->tx_skb);
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen=0;
cs->tx_skb = NULL;
}
if ((cs->tx_skb = skb_dequeue(&cs->sq))) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: interrupt: TX-Packet ready, next packet dequeued");
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen=0;
Amd7930_fill_Dfifo(cs);
}
else
schedule_event(cs, D_XMTBUFREADY);
AmdIrqOn(cs);
}
if (lsr & 0x38) {
AmdIrqOff(cs);
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd: interrupt: LSR=0x%02X, LIU is in state %d", lsr, ((lsr & 0x7) +2));
cs->dc.amd7930.ph_state = (lsr & 0x7) + 2;
schedule_event(cs, D_L1STATECHANGE);
AmdIrqOn(cs);
}
irflags = rByteAMD(cs, 0x00);
}
}
static void
Amd7930_l1hw(struct PStack *st, int pr, void *arg)
{
struct IsdnCardState *cs = (struct IsdnCardState *) st->l1.hardware;
struct sk_buff *skb = arg;
u_long flags;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: l1hw called, pr: 0x%04X", pr);
switch (pr) {
case (PH_DATA | REQUEST):
if (cs->debug & DEB_DLOG_HEX)
LogFrame(cs, skb->data, skb->len);
if (cs->debug & DEB_DLOG_VERBOSE)
dlogframe(cs, skb, 0);
spin_lock_irqsave(&cs->lock, flags);
if (cs->tx_skb) {
skb_queue_tail(&cs->sq, skb);
#ifdef L2FRAME_DEBUG
if (cs->debug & L1_DEB_LAPD)
Logl2Frame(cs, skb, "Amd7930: l1hw: PH_DATA Queued", 0);
#endif
} else {
cs->tx_skb = skb;
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen=0;
#ifdef L2FRAME_DEBUG
if (cs->debug & L1_DEB_LAPD)
Logl2Frame(cs, skb, "Amd7930: l1hw: PH_DATA", 0);
#endif
Amd7930_fill_Dfifo(cs);
}
spin_unlock_irqrestore(&cs->lock, flags);
break;
case (PH_PULL | INDICATION):
spin_lock_irqsave(&cs->lock, flags);
if (cs->tx_skb) {
if (cs->debug & L1_DEB_WARN)
debugl1(cs, "Amd7930: l1hw: l2l1 tx_skb exist this shouldn't happen");
skb_queue_tail(&cs->sq, skb);
spin_unlock_irqrestore(&cs->lock, flags);
break;
}
if (cs->debug & DEB_DLOG_HEX)
LogFrame(cs, skb->data, skb->len);
if (cs->debug & DEB_DLOG_VERBOSE)
dlogframe(cs, skb, 0);
cs->tx_skb = skb;
cs->tx_cnt = 0;
cs->dc.amd7930.tx_xmtlen=0;
#ifdef L2FRAME_DEBUG
if (cs->debug & L1_DEB_LAPD)
Logl2Frame(cs, skb, "Amd7930: l1hw: PH_DATA_PULLED", 0);
#endif
Amd7930_fill_Dfifo(cs);
spin_unlock_irqrestore(&cs->lock, flags);
break;
case (PH_PULL | REQUEST):
#ifdef L2FRAME_DEBUG
if (cs->debug & L1_DEB_LAPD)
debugl1(cs, "Amd7930: l1hw: -> PH_REQUEST_PULL, skb: %s", (cs->tx_skb)? "yes":"no");
#endif
if (!cs->tx_skb) {
test_and_clear_bit(FLG_L1_PULL_REQ, &st->l1.Flags);
st->l1.l1l2(st, PH_PULL | CONFIRM, NULL);
} else
test_and_set_bit(FLG_L1_PULL_REQ, &st->l1.Flags);
break;
case (HW_RESET | REQUEST):
spin_lock_irqsave(&cs->lock, flags);
if ((cs->dc.amd7930.ph_state == 8)) {
Amd7930_ph_command(cs, 0x20, "HW_RESET REQEST");
spin_unlock_irqrestore(&cs->lock, flags);
} else {
Amd7930_ph_command(cs, 0x40, "HW_RESET REQUEST");
cs->dc.amd7930.ph_state = 2;
spin_unlock_irqrestore(&cs->lock, flags);
Amd7930_new_ph(cs);
}
break;
case (HW_ENABLE | REQUEST):
cs->dc.amd7930.ph_state = 9;
Amd7930_new_ph(cs);
break;
case (HW_INFO3 | REQUEST):
break;
case (HW_TESTLOOP | REQUEST):
break;
case (HW_DEACTIVATE | RESPONSE):
skb_queue_purge(&cs->rq);
skb_queue_purge(&cs->sq);
if (cs->tx_skb) {
dev_kfree_skb(cs->tx_skb);
cs->tx_skb = NULL;
}
if (test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags))
del_timer(&cs->dbusytimer);
if (test_and_clear_bit(FLG_L1_DBUSY, &cs->HW_Flags))
schedule_event(cs, D_CLEARBUSY);
break;
default:
if (cs->debug & L1_DEB_WARN)
debugl1(cs, "Amd7930: l1hw: unknown %04x", pr);
break;
}
}
static void
setstack_Amd7930(struct PStack *st, struct IsdnCardState *cs)
{
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: setstack called");
st->l1.l1hw = Amd7930_l1hw;
}
static void
DC_Close_Amd7930(struct IsdnCardState *cs) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: DC_Close called");
}
static void
dbusy_timer_handler(struct IsdnCardState *cs)
{
u_long flags;
struct PStack *stptr;
WORD dtcr, der;
BYTE dsr1, dsr2;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: dbusy_timer expired!");
if (test_bit(FLG_DBUSY_TIMER, &cs->HW_Flags)) {
spin_lock_irqsave(&cs->lock, flags);
dtcr = rWordAMD(cs, 0x85);
dsr1 = rByteAMD(cs, 0x02);
dsr2 = rByteAMD(cs, 0x07);
der = rWordAMD(cs, 0x03);
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: dbusy_timer_handler: DSR1=0x%02X, DSR2=0x%02X, DER=0x%04X, cs->tx_skb->len=%u, tx_stat=%u, dtcr=%u, cs->tx_cnt=%u", dsr1, dsr2, der, cs->tx_skb->len, cs->dc.amd7930.tx_xmtlen, dtcr, cs->tx_cnt);
if ((cs->dc.amd7930.tx_xmtlen - dtcr) < cs->tx_cnt) {
test_and_set_bit(FLG_L1_DBUSY, &cs->HW_Flags);
stptr = cs->stlist;
spin_unlock_irqrestore(&cs->lock, flags);
while (stptr != NULL) {
stptr->l1.l1l2(stptr, PH_PAUSE | INDICATION, NULL);
stptr = stptr->next;
}
} else {
test_and_clear_bit(FLG_DBUSY_TIMER, &cs->HW_Flags);
if (cs->tx_skb) {
dev_kfree_skb_any(cs->tx_skb);
cs->tx_cnt = 0;
cs->tx_skb = NULL;
cs->dc.amd7930.tx_xmtlen = 0;
} else {
printk(KERN_WARNING "HiSax: Amd7930: D-Channel Busy no skb\n");
debugl1(cs, "Amd7930: D-Channel Busy no skb");
}
wByteAMD(cs, 0x21, 0x82);
wByteAMD(cs, 0x21, 0x02);
spin_unlock_irqrestore(&cs->lock, flags);
cs->irq_func(cs->irq, cs);
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: dbusy_timer_handler: Transmitter reset");
}
}
}
void Amd7930_init(struct IsdnCardState *cs)
{
WORD *ptr;
BYTE cmd, cnt;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "Amd7930: initamd called");
cs->dc.amd7930.tx_xmtlen = 0;
cs->dc.amd7930.old_state = 0;
cs->dc.amd7930.lmr1 = 0x40;
cs->dc.amd7930.ph_command = Amd7930_ph_command;
cs->setstack_d = setstack_Amd7930;
cs->DC_Close = DC_Close_Amd7930;
for (ptr = initAMD; *ptr != 0xFFFF; ) {
cmd = LOBYTE(*ptr);
if (*ptr++ >= 0x100) {
if (cmd < 8)
rByteAMD(cs, cmd);
else {
wByteAMD(cs, 0x00, cmd);
for (cnt = *ptr++; cnt > 0; cnt--)
rByteAMD(cs, 0x01);
}
}
else if (cmd < 8)
wByteAMD(cs, cmd, LOBYTE(*ptr++));
else {
wByteAMD(cs, 0x00, cmd);
for (cnt = *ptr++; cnt > 0; cnt--)
wByteAMD(cs, 0x01, LOBYTE(*ptr++));
}
}
}
void __devinit
setup_Amd7930(struct IsdnCardState *cs)
{
INIT_WORK(&cs->tqueue, Amd7930_bh);
cs->dbusytimer.function = (void *) dbusy_timer_handler;
cs->dbusytimer.data = (long) cs;
init_timer(&cs->dbusytimer);
}
