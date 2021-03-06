static inline int rocket_paranoia_check(struct r_port *info,
const char *routine)
{
#ifdef ROCKET_PARANOIA_CHECK
if (!info)
return 1;
if (info->magic != RPORT_MAGIC) {
printk(KERN_WARNING "Warning: bad magic number for rocketport "
"struct in %s\n", routine);
return 1;
}
#endif
return 0;
}
static void rp_do_receive(struct r_port *info, CHANNEL_t *cp,
unsigned int ChanStatus)
{
unsigned int CharNStat;
int ToRecv, wRecv, space;
unsigned char *cbuf;
ToRecv = sGetRxCnt(cp);
#ifdef ROCKET_DEBUG_INTR
printk(KERN_INFO "rp_do_receive(%d)...\n", ToRecv);
#endif
if (ToRecv == 0)
return;
if (ChanStatus & (RXFOVERFL | RXBREAK | RXFRAME | RXPARITY)) {
if (!(ChanStatus & STATMODE)) {
#ifdef ROCKET_DEBUG_RECEIVE
printk(KERN_INFO "Entering STATMODE...\n");
#endif
ChanStatus |= STATMODE;
sEnRxStatusMode(cp);
}
}
if (ChanStatus & STATMODE) {
#ifdef ROCKET_DEBUG_RECEIVE
printk(KERN_INFO "Ignore %x, read %x...\n",
info->ignore_status_mask, info->read_status_mask);
#endif
while (ToRecv) {
char flag;
CharNStat = sInW(sGetTxRxDataIO(cp));
#ifdef ROCKET_DEBUG_RECEIVE
printk(KERN_INFO "%x...\n", CharNStat);
#endif
if (CharNStat & STMBREAKH)
CharNStat &= ~(STMFRAMEH | STMPARITYH);
if (CharNStat & info->ignore_status_mask) {
ToRecv--;
continue;
}
CharNStat &= info->read_status_mask;
if (CharNStat & STMBREAKH)
flag = TTY_BREAK;
else if (CharNStat & STMPARITYH)
flag = TTY_PARITY;
else if (CharNStat & STMFRAMEH)
flag = TTY_FRAME;
else if (CharNStat & STMRCVROVRH)
flag = TTY_OVERRUN;
else
flag = TTY_NORMAL;
tty_insert_flip_char(&info->port, CharNStat & 0xff,
flag);
ToRecv--;
}
if (sGetRxCnt(cp) == 0) {
#ifdef ROCKET_DEBUG_RECEIVE
printk(KERN_INFO "Status mode off.\n");
#endif
sDisRxStatusMode(cp);
}
} else {
space = tty_prepare_flip_string(&info->port, &cbuf, ToRecv);
if (space < ToRecv) {
#ifdef ROCKET_DEBUG_RECEIVE
printk(KERN_INFO "rp_do_receive:insufficient space ToRecv=%d space=%d\n", ToRecv, space);
#endif
if (space <= 0)
return;
ToRecv = space;
}
wRecv = ToRecv >> 1;
if (wRecv)
sInStrW(sGetTxRxDataIO(cp), (unsigned short *) cbuf, wRecv);
if (ToRecv & 1)
cbuf[ToRecv - 1] = sInB(sGetTxRxDataIO(cp));
}
tty_flip_buffer_push(&info->port);
}
static void rp_do_transmit(struct r_port *info)
{
int c;
CHANNEL_t *cp = &info->channel;
struct tty_struct *tty;
unsigned long flags;
#ifdef ROCKET_DEBUG_INTR
printk(KERN_DEBUG "%s\n", __func__);
#endif
if (!info)
return;
tty = tty_port_tty_get(&info->port);
if (tty == NULL) {
printk(KERN_WARNING "rp: WARNING %s called with tty==NULL\n", __func__);
clear_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
return;
}
spin_lock_irqsave(&info->slock, flags);
info->xmit_fifo_room = TXFIFO_SIZE - sGetTxCnt(cp);
while (1) {
if (tty->stopped)
break;
c = min(info->xmit_fifo_room, info->xmit_cnt);
c = min(c, XMIT_BUF_SIZE - info->xmit_tail);
if (c <= 0 || info->xmit_fifo_room <= 0)
break;
sOutStrW(sGetTxRxDataIO(cp), (unsigned short *) (info->xmit_buf + info->xmit_tail), c / 2);
if (c & 1)
sOutB(sGetTxRxDataIO(cp), info->xmit_buf[info->xmit_tail + c - 1]);
info->xmit_tail += c;
info->xmit_tail &= XMIT_BUF_SIZE - 1;
info->xmit_cnt -= c;
info->xmit_fifo_room -= c;
#ifdef ROCKET_DEBUG_INTR
printk(KERN_INFO "tx %d chars...\n", c);
#endif
}
if (info->xmit_cnt == 0)
clear_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
if (info->xmit_cnt < WAKEUP_CHARS) {
tty_wakeup(tty);
#ifdef ROCKETPORT_HAVE_POLL_WAIT
wake_up_interruptible(&tty->poll_wait);
#endif
}
spin_unlock_irqrestore(&info->slock, flags);
tty_kref_put(tty);
#ifdef ROCKET_DEBUG_INTR
printk(KERN_DEBUG "(%d,%d,%d,%d)...\n", info->xmit_cnt, info->xmit_head,
info->xmit_tail, info->xmit_fifo_room);
#endif
}
static void rp_handle_port(struct r_port *info)
{
CHANNEL_t *cp;
unsigned int IntMask, ChanStatus;
if (!info)
return;
if ((info->port.flags & ASYNC_INITIALIZED) == 0) {
printk(KERN_WARNING "rp: WARNING: rp_handle_port called with "
"info->flags & NOT_INIT\n");
return;
}
cp = &info->channel;
IntMask = sGetChanIntID(cp) & info->intmask;
#ifdef ROCKET_DEBUG_INTR
printk(KERN_INFO "rp_interrupt %02x...\n", IntMask);
#endif
ChanStatus = sGetChanStatus(cp);
if (IntMask & RXF_TRIG) {
rp_do_receive(info, cp, ChanStatus);
}
if (IntMask & DELTA_CD) {
#if (defined(ROCKET_DEBUG_OPEN) || defined(ROCKET_DEBUG_INTR) || defined(ROCKET_DEBUG_HANGUP))
printk(KERN_INFO "ttyR%d CD now %s...\n", info->line,
(ChanStatus & CD_ACT) ? "on" : "off");
#endif
if (!(ChanStatus & CD_ACT) && info->cd_status) {
#ifdef ROCKET_DEBUG_HANGUP
printk(KERN_INFO "CD drop, calling hangup.\n");
#endif
tty_port_tty_hangup(&info->port, false);
}
info->cd_status = (ChanStatus & CD_ACT) ? 1 : 0;
wake_up_interruptible(&info->port.open_wait);
}
#ifdef ROCKET_DEBUG_INTR
if (IntMask & DELTA_CTS) {
printk(KERN_INFO "CTS change...\n");
}
if (IntMask & DELTA_DSR) {
printk(KERN_INFO "DSR change...\n");
}
#endif
}
static void rp_do_poll(unsigned long dummy)
{
CONTROLLER_t *ctlp;
int ctrl, aiop, ch, line;
unsigned int xmitmask, i;
unsigned int CtlMask;
unsigned char AiopMask;
Word_t bit;
for (ctrl = 0; ctrl < max_board; ctrl++) {
if (rcktpt_io_addr[ctrl] <= 0)
continue;
ctlp = sCtlNumToCtlPtr(ctrl);
#ifdef CONFIG_PCI
if (ctlp->BusType == isPCI)
CtlMask = sPCIGetControllerIntStatus(ctlp);
else
#endif
CtlMask = sGetControllerIntStatus(ctlp);
for (aiop = 0; CtlMask; aiop++) {
bit = ctlp->AiopIntrBits[aiop];
if (CtlMask & bit) {
CtlMask &= ~bit;
AiopMask = sGetAiopIntStatus(ctlp, aiop);
for (ch = 0; AiopMask; AiopMask >>= 1, ch++) {
if (AiopMask & 1) {
line = GetLineNumber(ctrl, aiop, ch);
rp_handle_port(rp_table[line]);
}
}
}
}
xmitmask = xmit_flags[ctrl];
if (xmitmask) {
for (i = 0; i < rocketModel[ctrl].numPorts; i++) {
if (xmitmask & (1 << i)) {
aiop = (i & 0x18) >> 3;
ch = i & 0x07;
line = GetLineNumber(ctrl, aiop, ch);
rp_do_transmit(rp_table[line]);
}
}
}
}
if (atomic_read(&rp_num_ports_open))
mod_timer(&rocket_timer, jiffies + POLL_PERIOD);
}
static void init_r_port(int board, int aiop, int chan, struct pci_dev *pci_dev)
{
unsigned rocketMode;
struct r_port *info;
int line;
CONTROLLER_T *ctlp;
line = SetLineNumber(board, aiop, chan);
ctlp = sCtlNumToCtlPtr(board);
info = kzalloc(sizeof (struct r_port), GFP_KERNEL);
if (!info) {
printk(KERN_ERR "Couldn't allocate info struct for line #%d\n",
line);
return;
}
info->magic = RPORT_MAGIC;
info->line = line;
info->ctlp = ctlp;
info->board = board;
info->aiop = aiop;
info->chan = chan;
tty_port_init(&info->port);
info->port.ops = &rocket_port_ops;
init_completion(&info->close_wait);
info->flags &= ~ROCKET_MODE_MASK;
switch (pc104[board][line]) {
case 422:
info->flags |= ROCKET_MODE_RS422;
break;
case 485:
info->flags |= ROCKET_MODE_RS485;
break;
case 232:
default:
info->flags |= ROCKET_MODE_RS232;
break;
}
info->intmask = RXF_TRIG | TXFIFO_MT | SRC_INT | DELTA_CD | DELTA_CTS | DELTA_DSR;
if (sInitChan(ctlp, &info->channel, aiop, chan) == 0) {
printk(KERN_ERR "RocketPort sInitChan(%d, %d, %d) failed!\n",
board, aiop, chan);
tty_port_destroy(&info->port);
kfree(info);
return;
}
rocketMode = info->flags & ROCKET_MODE_MASK;
if ((info->flags & ROCKET_RTS_TOGGLE) || (rocketMode == ROCKET_MODE_RS485))
sEnRTSToggle(&info->channel);
else
sDisRTSToggle(&info->channel);
if (ctlp->boardType == ROCKET_TYPE_PC104) {
switch (rocketMode) {
case ROCKET_MODE_RS485:
sSetInterfaceMode(&info->channel, InterfaceModeRS485);
break;
case ROCKET_MODE_RS422:
sSetInterfaceMode(&info->channel, InterfaceModeRS422);
break;
case ROCKET_MODE_RS232:
default:
if (info->flags & ROCKET_RTS_TOGGLE)
sSetInterfaceMode(&info->channel, InterfaceModeRS232T);
else
sSetInterfaceMode(&info->channel, InterfaceModeRS232);
break;
}
}
spin_lock_init(&info->slock);
mutex_init(&info->write_mtx);
rp_table[line] = info;
tty_port_register_device(&info->port, rocket_driver, line,
pci_dev ? &pci_dev->dev : NULL);
}
static void configure_r_port(struct tty_struct *tty, struct r_port *info,
struct ktermios *old_termios)
{
unsigned cflag;
unsigned long flags;
unsigned rocketMode;
int bits, baud, divisor;
CHANNEL_t *cp;
struct ktermios *t = &tty->termios;
cp = &info->channel;
cflag = t->c_cflag;
if ((cflag & CSIZE) == CS8) {
sSetData8(cp);
bits = 10;
} else {
sSetData7(cp);
bits = 9;
}
if (cflag & CSTOPB) {
sSetStop2(cp);
bits++;
} else {
sSetStop1(cp);
}
if (cflag & PARENB) {
sEnParity(cp);
bits++;
if (cflag & PARODD) {
sSetOddParity(cp);
} else {
sSetEvenParity(cp);
}
} else {
sDisParity(cp);
}
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
divisor = ((rp_baud_base[info->board] + (baud >> 1)) / baud) - 1;
if ((divisor >= 8192 || divisor < 0) && old_termios) {
baud = tty_termios_baud_rate(old_termios);
if (!baud)
baud = 9600;
divisor = (rp_baud_base[info->board] / baud) - 1;
}
if (divisor >= 8192 || divisor < 0) {
baud = 9600;
divisor = (rp_baud_base[info->board] / baud) - 1;
}
info->cps = baud / bits;
sSetBaud(cp, divisor);
tty_encode_baud_rate(tty, baud, baud);
if (cflag & CRTSCTS) {
info->intmask |= DELTA_CTS;
sEnCTSFlowCtl(cp);
} else {
info->intmask &= ~DELTA_CTS;
sDisCTSFlowCtl(cp);
}
if (cflag & CLOCAL) {
info->intmask &= ~DELTA_CD;
} else {
spin_lock_irqsave(&info->slock, flags);
if (sGetChanStatus(cp) & CD_ACT)
info->cd_status = 1;
else
info->cd_status = 0;
info->intmask |= DELTA_CD;
spin_unlock_irqrestore(&info->slock, flags);
}
#ifdef ROCKET_SOFT_FLOW
if (I_IXON(tty)) {
sEnTxSoftFlowCtl(cp);
if (I_IXANY(tty)) {
sEnIXANY(cp);
} else {
sDisIXANY(cp);
}
sSetTxXONChar(cp, START_CHAR(tty));
sSetTxXOFFChar(cp, STOP_CHAR(tty));
} else {
sDisTxSoftFlowCtl(cp);
sDisIXANY(cp);
sClrTxXOFF(cp);
}
#endif
info->read_status_mask = STMRCVROVRH | 0xFF;
if (I_INPCK(tty))
info->read_status_mask |= STMFRAMEH | STMPARITYH;
if (I_BRKINT(tty) || I_PARMRK(tty))
info->read_status_mask |= STMBREAKH;
info->ignore_status_mask = 0;
if (I_IGNPAR(tty))
info->ignore_status_mask |= STMFRAMEH | STMPARITYH;
if (I_IGNBRK(tty)) {
info->ignore_status_mask |= STMBREAKH;
if (I_IGNPAR(tty))
info->ignore_status_mask |= STMRCVROVRH;
}
rocketMode = info->flags & ROCKET_MODE_MASK;
if ((info->flags & ROCKET_RTS_TOGGLE)
|| (rocketMode == ROCKET_MODE_RS485))
sEnRTSToggle(cp);
else
sDisRTSToggle(cp);
sSetRTS(&info->channel);
if (cp->CtlP->boardType == ROCKET_TYPE_PC104) {
switch (rocketMode) {
case ROCKET_MODE_RS485:
sSetInterfaceMode(cp, InterfaceModeRS485);
break;
case ROCKET_MODE_RS422:
sSetInterfaceMode(cp, InterfaceModeRS422);
break;
case ROCKET_MODE_RS232:
default:
if (info->flags & ROCKET_RTS_TOGGLE)
sSetInterfaceMode(cp, InterfaceModeRS232T);
else
sSetInterfaceMode(cp, InterfaceModeRS232);
break;
}
}
}
static int carrier_raised(struct tty_port *port)
{
struct r_port *info = container_of(port, struct r_port, port);
return (sGetChanStatusLo(&info->channel) & CD_ACT) ? 1 : 0;
}
static void dtr_rts(struct tty_port *port, int on)
{
struct r_port *info = container_of(port, struct r_port, port);
if (on) {
sSetDTR(&info->channel);
sSetRTS(&info->channel);
} else {
sClrDTR(&info->channel);
sClrRTS(&info->channel);
}
}
static int rp_open(struct tty_struct *tty, struct file *filp)
{
struct r_port *info;
struct tty_port *port;
int retval;
CHANNEL_t *cp;
unsigned long page;
info = rp_table[tty->index];
if (info == NULL)
return -ENXIO;
port = &info->port;
page = __get_free_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
if (info->xmit_buf)
free_page(page);
else
info->xmit_buf = (unsigned char *) page;
tty->driver_data = info;
tty_port_tty_set(port, tty);
if (port->count++ == 0) {
atomic_inc(&rp_num_ports_open);
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "rocket mod++ = %d...\n",
atomic_read(&rp_num_ports_open));
#endif
}
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "rp_open ttyR%d, count=%d\n", info->line, info->port.count);
#endif
if (!test_bit(ASYNCB_INITIALIZED, &port->flags)) {
cp = &info->channel;
sSetRxTrigger(cp, TRIG_1);
if (sGetChanStatus(cp) & CD_ACT)
info->cd_status = 1;
else
info->cd_status = 0;
sDisRxStatusMode(cp);
sFlushRxFIFO(cp);
sFlushTxFIFO(cp);
sEnInterrupts(cp, (TXINT_EN | MCINT_EN | RXINT_EN | SRCINT_EN | CHANINT_EN));
sSetRxTrigger(cp, TRIG_1);
sGetChanStatus(cp);
sDisRxStatusMode(cp);
sClrTxXOFF(cp);
sDisCTSFlowCtl(cp);
sDisTxSoftFlowCtl(cp);
sEnRxFIFO(cp);
sEnTransmit(cp);
set_bit(ASYNCB_INITIALIZED, &info->port.flags);
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_HI)
tty->alt_speed = 57600;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_VHI)
tty->alt_speed = 115200;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_SHI)
tty->alt_speed = 230400;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_WARP)
tty->alt_speed = 460800;
configure_r_port(tty, info, NULL);
if (tty->termios.c_cflag & CBAUD) {
sSetDTR(cp);
sSetRTS(cp);
}
}
mod_timer(&rocket_timer, jiffies + POLL_PERIOD);
retval = tty_port_block_til_ready(port, tty, filp);
if (retval) {
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "rp_open returning after block_til_ready with %d\n", retval);
#endif
return retval;
}
return 0;
}
static void rp_close(struct tty_struct *tty, struct file *filp)
{
struct r_port *info = tty->driver_data;
struct tty_port *port = &info->port;
int timeout;
CHANNEL_t *cp;
if (rocket_paranoia_check(info, "rp_close"))
return;
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "rp_close ttyR%d, count = %d\n", info->line, info->port.count);
#endif
if (tty_port_close_start(port, tty, filp) == 0)
return;
mutex_lock(&port->mutex);
cp = &info->channel;
timeout = (sGetTxCnt(cp) + 1) * HZ / info->cps;
if (timeout == 0)
timeout = 1;
rp_wait_until_sent(tty, timeout);
clear_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
sDisTransmit(cp);
sDisInterrupts(cp, (TXINT_EN | MCINT_EN | RXINT_EN | SRCINT_EN | CHANINT_EN));
sDisCTSFlowCtl(cp);
sDisTxSoftFlowCtl(cp);
sClrTxXOFF(cp);
sFlushRxFIFO(cp);
sFlushTxFIFO(cp);
sClrRTS(cp);
if (C_HUPCL(tty))
sClrDTR(cp);
rp_flush_buffer(tty);
tty_ldisc_flush(tty);
clear_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
if (port->blocked_open) {
if (port->close_delay) {
msleep_interruptible(jiffies_to_msecs(port->close_delay));
}
wake_up_interruptible(&port->open_wait);
} else {
if (info->xmit_buf) {
free_page((unsigned long) info->xmit_buf);
info->xmit_buf = NULL;
}
}
spin_lock_irq(&port->lock);
info->port.flags &= ~(ASYNC_INITIALIZED | ASYNC_CLOSING | ASYNC_NORMAL_ACTIVE);
tty->closing = 0;
spin_unlock_irq(&port->lock);
mutex_unlock(&port->mutex);
tty_port_tty_set(port, NULL);
complete_all(&info->close_wait);
atomic_dec(&rp_num_ports_open);
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "rocket mod-- = %d...\n",
atomic_read(&rp_num_ports_open));
printk(KERN_INFO "rp_close ttyR%d complete shutdown\n", info->line);
#endif
}
static void rp_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
unsigned cflag;
if (rocket_paranoia_check(info, "rp_set_termios"))
return;
cflag = tty->termios.c_cflag;
if (((cflag & CSIZE) == CS5) || ((cflag & CSIZE) == CS6))
tty->termios.c_cflag =
((cflag & ~CSIZE) | (old_termios->c_cflag & CSIZE));
tty->termios.c_cflag &= ~CMSPAR;
configure_r_port(tty, info, old_termios);
cp = &info->channel;
if ((old_termios->c_cflag & CBAUD) && !(tty->termios.c_cflag & CBAUD)) {
sClrDTR(cp);
sClrRTS(cp);
}
if (!(old_termios->c_cflag & CBAUD) && (tty->termios.c_cflag & CBAUD)) {
sSetRTS(cp);
sSetDTR(cp);
}
if ((old_termios->c_cflag & CRTSCTS) && !(tty->termios.c_cflag & CRTSCTS))
rp_start(tty);
}
static int rp_break(struct tty_struct *tty, int break_state)
{
struct r_port *info = tty->driver_data;
unsigned long flags;
if (rocket_paranoia_check(info, "rp_break"))
return -EINVAL;
spin_lock_irqsave(&info->slock, flags);
if (break_state == -1)
sSendBreak(&info->channel);
else
sClrBreak(&info->channel);
spin_unlock_irqrestore(&info->slock, flags);
return 0;
}
static int sGetChanRI(CHANNEL_T * ChP)
{
CONTROLLER_t *CtlP = ChP->CtlP;
int ChanNum = ChP->ChanNum;
int RingInd = 0;
if (CtlP->UPCIRingInd)
RingInd = !(sInB(CtlP->UPCIRingInd) & sBitMapSetTbl[ChanNum]);
else if (CtlP->AltChanRingIndicator)
RingInd = sInB((ByteIO_t) (ChP->ChanStat + 8)) & DSR_ACT;
else if (CtlP->boardType == ROCKET_TYPE_PC104)
RingInd = !(sInB(CtlP->AiopIO[3]) & sBitMapSetTbl[ChanNum]);
return RingInd;
}
static int rp_tiocmget(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
unsigned int control, result, ChanStatus;
ChanStatus = sGetChanStatusLo(&info->channel);
control = info->channel.TxControl[3];
result = ((control & SET_RTS) ? TIOCM_RTS : 0) |
((control & SET_DTR) ? TIOCM_DTR : 0) |
((ChanStatus & CD_ACT) ? TIOCM_CAR : 0) |
(sGetChanRI(&info->channel) ? TIOCM_RNG : 0) |
((ChanStatus & DSR_ACT) ? TIOCM_DSR : 0) |
((ChanStatus & CTS_ACT) ? TIOCM_CTS : 0);
return result;
}
static int rp_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct r_port *info = tty->driver_data;
if (set & TIOCM_RTS)
info->channel.TxControl[3] |= SET_RTS;
if (set & TIOCM_DTR)
info->channel.TxControl[3] |= SET_DTR;
if (clear & TIOCM_RTS)
info->channel.TxControl[3] &= ~SET_RTS;
if (clear & TIOCM_DTR)
info->channel.TxControl[3] &= ~SET_DTR;
out32(info->channel.IndexAddr, info->channel.TxControl);
return 0;
}
static int get_config(struct r_port *info, struct rocket_config __user *retinfo)
{
struct rocket_config tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof (tmp));
mutex_lock(&info->port.mutex);
tmp.line = info->line;
tmp.flags = info->flags;
tmp.close_delay = info->port.close_delay;
tmp.closing_wait = info->port.closing_wait;
tmp.port = rcktpt_io_addr[(info->line >> 5) & 3];
mutex_unlock(&info->port.mutex);
if (copy_to_user(retinfo, &tmp, sizeof (*retinfo)))
return -EFAULT;
return 0;
}
static int set_config(struct tty_struct *tty, struct r_port *info,
struct rocket_config __user *new_info)
{
struct rocket_config new_serial;
if (copy_from_user(&new_serial, new_info, sizeof (new_serial)))
return -EFAULT;
mutex_lock(&info->port.mutex);
if (!capable(CAP_SYS_ADMIN))
{
if ((new_serial.flags & ~ROCKET_USR_MASK) != (info->flags & ~ROCKET_USR_MASK)) {
mutex_unlock(&info->port.mutex);
return -EPERM;
}
info->flags = ((info->flags & ~ROCKET_USR_MASK) | (new_serial.flags & ROCKET_USR_MASK));
configure_r_port(tty, info, NULL);
mutex_unlock(&info->port.mutex);
return 0;
}
info->flags = ((info->flags & ~ROCKET_FLAGS) | (new_serial.flags & ROCKET_FLAGS));
info->port.close_delay = new_serial.close_delay;
info->port.closing_wait = new_serial.closing_wait;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_HI)
tty->alt_speed = 57600;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_VHI)
tty->alt_speed = 115200;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_SHI)
tty->alt_speed = 230400;
if ((info->flags & ROCKET_SPD_MASK) == ROCKET_SPD_WARP)
tty->alt_speed = 460800;
mutex_unlock(&info->port.mutex);
configure_r_port(tty, info, NULL);
return 0;
}
static int get_ports(struct r_port *info, struct rocket_ports __user *retports)
{
struct rocket_ports tmp;
int board;
if (!retports)
return -EFAULT;
memset(&tmp, 0, sizeof (tmp));
tmp.tty_major = rocket_driver->major;
for (board = 0; board < 4; board++) {
tmp.rocketModel[board].model = rocketModel[board].model;
strcpy(tmp.rocketModel[board].modelString, rocketModel[board].modelString);
tmp.rocketModel[board].numPorts = rocketModel[board].numPorts;
tmp.rocketModel[board].loadrm2 = rocketModel[board].loadrm2;
tmp.rocketModel[board].startingPortNumber = rocketModel[board].startingPortNumber;
}
if (copy_to_user(retports, &tmp, sizeof (*retports)))
return -EFAULT;
return 0;
}
static int reset_rm2(struct r_port *info, void __user *arg)
{
int reset;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (copy_from_user(&reset, arg, sizeof (int)))
return -EFAULT;
if (reset)
reset = 1;
if (rcktpt_type[info->board] != ROCKET_TYPE_MODEMII &&
rcktpt_type[info->board] != ROCKET_TYPE_MODEMIII)
return -EINVAL;
if (info->ctlp->BusType == isISA)
sModemReset(info->ctlp, info->chan, reset);
else
sPCIModemReset(info->ctlp, info->chan, reset);
return 0;
}
static int get_version(struct r_port *info, struct rocket_version __user *retvers)
{
if (copy_to_user(retvers, &driver_version, sizeof (*retvers)))
return -EFAULT;
return 0;
}
static int rp_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct r_port *info = tty->driver_data;
void __user *argp = (void __user *)arg;
int ret = 0;
if (cmd != RCKP_GET_PORTS && rocket_paranoia_check(info, "rp_ioctl"))
return -ENXIO;
switch (cmd) {
case RCKP_GET_STRUCT:
if (copy_to_user(argp, info, sizeof (struct r_port)))
ret = -EFAULT;
break;
case RCKP_GET_CONFIG:
ret = get_config(info, argp);
break;
case RCKP_SET_CONFIG:
ret = set_config(tty, info, argp);
break;
case RCKP_GET_PORTS:
ret = get_ports(info, argp);
break;
case RCKP_RESET_RM2:
ret = reset_rm2(info, argp);
break;
case RCKP_GET_VERSION:
ret = get_version(info, argp);
break;
default:
ret = -ENOIOCTLCMD;
}
return ret;
}
static void rp_send_xchar(struct tty_struct *tty, char ch)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
if (rocket_paranoia_check(info, "rp_send_xchar"))
return;
cp = &info->channel;
if (sGetTxCnt(cp))
sWriteTxPrioByte(cp, ch);
else
sWriteTxByte(sGetTxRxDataIO(cp), ch);
}
static void rp_throttle(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
#ifdef ROCKET_DEBUG_THROTTLE
printk(KERN_INFO "throttle %s: %d....\n", tty->name,
tty->ldisc.chars_in_buffer(tty));
#endif
if (rocket_paranoia_check(info, "rp_throttle"))
return;
if (I_IXOFF(tty))
rp_send_xchar(tty, STOP_CHAR(tty));
sClrRTS(&info->channel);
}
static void rp_unthrottle(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
#ifdef ROCKET_DEBUG_THROTTLE
printk(KERN_INFO "unthrottle %s: %d....\n", tty->name,
tty->ldisc.chars_in_buffer(tty));
#endif
if (rocket_paranoia_check(info, "rp_unthrottle"))
return;
if (I_IXOFF(tty))
rp_send_xchar(tty, START_CHAR(tty));
sSetRTS(&info->channel);
}
static void rp_stop(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
#ifdef ROCKET_DEBUG_FLOW
printk(KERN_INFO "stop %s: %d %d....\n", tty->name,
info->xmit_cnt, info->xmit_fifo_room);
#endif
if (rocket_paranoia_check(info, "rp_stop"))
return;
if (sGetTxCnt(&info->channel))
sDisTransmit(&info->channel);
}
static void rp_start(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
#ifdef ROCKET_DEBUG_FLOW
printk(KERN_INFO "start %s: %d %d....\n", tty->name,
info->xmit_cnt, info->xmit_fifo_room);
#endif
if (rocket_paranoia_check(info, "rp_stop"))
return;
sEnTransmit(&info->channel);
set_bit((info->aiop * 8) + info->chan,
(void *) &xmit_flags[info->board]);
}
static void rp_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
unsigned long orig_jiffies;
int check_time, exit_time;
int txcnt;
if (rocket_paranoia_check(info, "rp_wait_until_sent"))
return;
cp = &info->channel;
orig_jiffies = jiffies;
#ifdef ROCKET_DEBUG_WAIT_UNTIL_SENT
printk(KERN_INFO "In %s(%d) (jiff=%lu)...\n", __func__, timeout,
jiffies);
printk(KERN_INFO "cps=%d...\n", info->cps);
#endif
while (1) {
txcnt = sGetTxCnt(cp);
if (!txcnt) {
if (sGetChanStatusLo(cp) & TXSHRMT)
break;
check_time = (HZ / info->cps) / 5;
} else {
check_time = HZ * txcnt / info->cps;
}
if (timeout) {
exit_time = orig_jiffies + timeout - jiffies;
if (exit_time <= 0)
break;
if (exit_time < check_time)
check_time = exit_time;
}
if (check_time == 0)
check_time = 1;
#ifdef ROCKET_DEBUG_WAIT_UNTIL_SENT
printk(KERN_INFO "txcnt = %d (jiff=%lu,check=%d)...\n", txcnt,
jiffies, check_time);
#endif
msleep_interruptible(jiffies_to_msecs(check_time));
if (signal_pending(current))
break;
}
__set_current_state(TASK_RUNNING);
#ifdef ROCKET_DEBUG_WAIT_UNTIL_SENT
printk(KERN_INFO "txcnt = %d (jiff=%lu)...done\n", txcnt, jiffies);
#endif
}
static void rp_hangup(struct tty_struct *tty)
{
CHANNEL_t *cp;
struct r_port *info = tty->driver_data;
unsigned long flags;
if (rocket_paranoia_check(info, "rp_hangup"))
return;
#if (defined(ROCKET_DEBUG_OPEN) || defined(ROCKET_DEBUG_HANGUP))
printk(KERN_INFO "rp_hangup of ttyR%d...\n", info->line);
#endif
rp_flush_buffer(tty);
spin_lock_irqsave(&info->port.lock, flags);
if (info->port.count)
atomic_dec(&rp_num_ports_open);
clear_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
spin_unlock_irqrestore(&info->port.lock, flags);
tty_port_hangup(&info->port);
cp = &info->channel;
sDisRxFIFO(cp);
sDisTransmit(cp);
sDisInterrupts(cp, (TXINT_EN | MCINT_EN | RXINT_EN | SRCINT_EN | CHANINT_EN));
sDisCTSFlowCtl(cp);
sDisTxSoftFlowCtl(cp);
sClrTxXOFF(cp);
clear_bit(ASYNCB_INITIALIZED, &info->port.flags);
wake_up_interruptible(&info->port.open_wait);
}
static int rp_put_char(struct tty_struct *tty, unsigned char ch)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
unsigned long flags;
if (rocket_paranoia_check(info, "rp_put_char"))
return 0;
mutex_lock(&info->write_mtx);
#ifdef ROCKET_DEBUG_WRITE
printk(KERN_INFO "rp_put_char %c...\n", ch);
#endif
spin_lock_irqsave(&info->slock, flags);
cp = &info->channel;
if (!tty->stopped && info->xmit_fifo_room == 0)
info->xmit_fifo_room = TXFIFO_SIZE - sGetTxCnt(cp);
if (tty->stopped || info->xmit_fifo_room == 0 || info->xmit_cnt != 0) {
info->xmit_buf[info->xmit_head++] = ch;
info->xmit_head &= XMIT_BUF_SIZE - 1;
info->xmit_cnt++;
set_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
} else {
sOutB(sGetTxRxDataIO(cp), ch);
info->xmit_fifo_room--;
}
spin_unlock_irqrestore(&info->slock, flags);
mutex_unlock(&info->write_mtx);
return 1;
}
static int rp_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
const unsigned char *b;
int c, retval = 0;
unsigned long flags;
if (count <= 0 || rocket_paranoia_check(info, "rp_write"))
return 0;
if (mutex_lock_interruptible(&info->write_mtx))
return -ERESTARTSYS;
#ifdef ROCKET_DEBUG_WRITE
printk(KERN_INFO "rp_write %d chars...\n", count);
#endif
cp = &info->channel;
if (!tty->stopped && info->xmit_fifo_room < count)
info->xmit_fifo_room = TXFIFO_SIZE - sGetTxCnt(cp);
if (!tty->stopped && info->xmit_cnt == 0 && info->xmit_fifo_room > 0) {
c = min(count, info->xmit_fifo_room);
b = buf;
sOutStrW(sGetTxRxDataIO(cp), (unsigned short *) b, c / 2);
if (c & 1)
sOutB(sGetTxRxDataIO(cp), b[c - 1]);
retval += c;
buf += c;
count -= c;
spin_lock_irqsave(&info->slock, flags);
info->xmit_fifo_room -= c;
spin_unlock_irqrestore(&info->slock, flags);
}
if (!count)
goto end;
while (1) {
if (!test_bit(ASYNCB_NORMAL_ACTIVE, &info->port.flags))
goto end;
c = min(count, XMIT_BUF_SIZE - info->xmit_cnt - 1);
c = min(c, XMIT_BUF_SIZE - info->xmit_head);
if (c <= 0)
break;
b = buf;
memcpy(info->xmit_buf + info->xmit_head, b, c);
spin_lock_irqsave(&info->slock, flags);
info->xmit_head =
(info->xmit_head + c) & (XMIT_BUF_SIZE - 1);
info->xmit_cnt += c;
spin_unlock_irqrestore(&info->slock, flags);
buf += c;
count -= c;
retval += c;
}
if ((retval > 0) && !tty->stopped)
set_bit((info->aiop * 8) + info->chan, (void *) &xmit_flags[info->board]);
end:
if (info->xmit_cnt < WAKEUP_CHARS) {
tty_wakeup(tty);
#ifdef ROCKETPORT_HAVE_POLL_WAIT
wake_up_interruptible(&tty->poll_wait);
#endif
}
mutex_unlock(&info->write_mtx);
return retval;
}
static int rp_write_room(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
int ret;
if (rocket_paranoia_check(info, "rp_write_room"))
return 0;
ret = XMIT_BUF_SIZE - info->xmit_cnt - 1;
if (ret < 0)
ret = 0;
#ifdef ROCKET_DEBUG_WRITE
printk(KERN_INFO "rp_write_room returns %d...\n", ret);
#endif
return ret;
}
static int rp_chars_in_buffer(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
if (rocket_paranoia_check(info, "rp_chars_in_buffer"))
return 0;
#ifdef ROCKET_DEBUG_WRITE
printk(KERN_INFO "rp_chars_in_buffer returns %d...\n", info->xmit_cnt);
#endif
return info->xmit_cnt;
}
static void rp_flush_buffer(struct tty_struct *tty)
{
struct r_port *info = tty->driver_data;
CHANNEL_t *cp;
unsigned long flags;
if (rocket_paranoia_check(info, "rp_flush_buffer"))
return;
spin_lock_irqsave(&info->slock, flags);
info->xmit_cnt = info->xmit_head = info->xmit_tail = 0;
spin_unlock_irqrestore(&info->slock, flags);
#ifdef ROCKETPORT_HAVE_POLL_WAIT
wake_up_interruptible(&tty->poll_wait);
#endif
tty_wakeup(tty);
cp = &info->channel;
sFlushTxFIFO(cp);
}
static void rmSpeakerReset(CONTROLLER_T * CtlP, unsigned long model)
{
ByteIO_t addr;
if ((model == MODEL_RP4M) || (model == MODEL_RP6M)) {
addr = CtlP->AiopIO[0] + 0x4F;
sOutB(addr, 0);
}
if ((model == MODEL_UPCI_RM3_8PORT)
|| (model == MODEL_UPCI_RM3_4PORT)) {
addr = CtlP->AiopIO[0] + 0x88;
sOutB(addr, 0);
}
}
static int sPCIInitController(CONTROLLER_T * CtlP, int CtlNum,
ByteIO_t * AiopIOList, int AiopIOListSize,
WordIO_t ConfigIO, int IRQNum, Byte_t Frequency,
int PeriodicOnly, int altChanRingIndicator,
int UPCIRingInd)
{
int i;
ByteIO_t io;
CtlP->AltChanRingIndicator = altChanRingIndicator;
CtlP->UPCIRingInd = UPCIRingInd;
CtlP->CtlNum = CtlNum;
CtlP->CtlID = CTLID_0001;
CtlP->BusType = isPCI;
if (ConfigIO) {
CtlP->isUPCI = 1;
CtlP->PCIIO = ConfigIO + _PCI_9030_INT_CTRL;
CtlP->PCIIO2 = ConfigIO + _PCI_9030_GPIO_CTRL;
CtlP->AiopIntrBits = upci_aiop_intr_bits;
} else {
CtlP->isUPCI = 0;
CtlP->PCIIO =
(WordIO_t) ((ByteIO_t) AiopIOList[0] + _PCI_INT_FUNC);
CtlP->AiopIntrBits = aiop_intr_bits;
}
sPCIControllerEOI(CtlP);
CtlP->NumAiop = 0;
for (i = 0; i < AiopIOListSize; i++) {
io = AiopIOList[i];
CtlP->AiopIO[i] = (WordIO_t) io;
CtlP->AiopIntChanIO[i] = io + _INT_CHAN;
CtlP->AiopID[i] = sReadAiopID(io);
if (CtlP->AiopID[i] == AIOPID_NULL)
break;
CtlP->AiopNumChan[i] = sReadAiopNumChan((WordIO_t) io);
sOutW((WordIO_t) io + _INDX_ADDR, _CLK_PRE);
sOutB(io + _INDX_DATA, sClockPrescale);
CtlP->NumAiop++;
}
if (CtlP->NumAiop == 0)
return (-1);
else
return (CtlP->NumAiop);
}
static __init int register_PCI(int i, struct pci_dev *dev)
{
int num_aiops, aiop, max_num_aiops, num_chan, chan;
unsigned int aiopio[MAX_AIOPS_PER_BOARD];
CONTROLLER_t *ctlp;
int fast_clock = 0;
int altChanRingIndicator = 0;
int ports_per_aiop = 8;
WordIO_t ConfigIO = 0;
ByteIO_t UPCIRingInd = 0;
if (!dev || !pci_match_id(rocket_pci_ids, dev) ||
pci_enable_device(dev))
return 0;
rcktpt_io_addr[i] = pci_resource_start(dev, 0);
rcktpt_type[i] = ROCKET_TYPE_NORMAL;
rocketModel[i].loadrm2 = 0;
rocketModel[i].startingPortNumber = nextLineNumber;
switch (dev->device) {
case PCI_DEVICE_ID_RP4QUAD:
max_num_aiops = 1;
ports_per_aiop = 4;
rocketModel[i].model = MODEL_RP4QUAD;
strcpy(rocketModel[i].modelString, "RocketPort 4 port w/quad cable");
rocketModel[i].numPorts = 4;
break;
case PCI_DEVICE_ID_RP8OCTA:
max_num_aiops = 1;
rocketModel[i].model = MODEL_RP8OCTA;
strcpy(rocketModel[i].modelString, "RocketPort 8 port w/octa cable");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_URP8OCTA:
max_num_aiops = 1;
rocketModel[i].model = MODEL_UPCI_RP8OCTA;
strcpy(rocketModel[i].modelString, "RocketPort UPCI 8 port w/octa cable");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_RP8INTF:
max_num_aiops = 1;
rocketModel[i].model = MODEL_RP8INTF;
strcpy(rocketModel[i].modelString, "RocketPort 8 port w/external I/F");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_URP8INTF:
max_num_aiops = 1;
rocketModel[i].model = MODEL_UPCI_RP8INTF;
strcpy(rocketModel[i].modelString, "RocketPort UPCI 8 port w/external I/F");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_RP8J:
max_num_aiops = 1;
rocketModel[i].model = MODEL_RP8J;
strcpy(rocketModel[i].modelString, "RocketPort 8 port w/RJ11 connectors");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_RP4J:
max_num_aiops = 1;
ports_per_aiop = 4;
rocketModel[i].model = MODEL_RP4J;
strcpy(rocketModel[i].modelString, "RocketPort 4 port w/RJ45 connectors");
rocketModel[i].numPorts = 4;
break;
case PCI_DEVICE_ID_RP8SNI:
max_num_aiops = 1;
rocketModel[i].model = MODEL_RP8SNI;
strcpy(rocketModel[i].modelString, "RocketPort 8 port w/ custom DB78");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_RP16SNI:
max_num_aiops = 2;
rocketModel[i].model = MODEL_RP16SNI;
strcpy(rocketModel[i].modelString, "RocketPort 16 port w/ custom DB78");
rocketModel[i].numPorts = 16;
break;
case PCI_DEVICE_ID_RP16INTF:
max_num_aiops = 2;
rocketModel[i].model = MODEL_RP16INTF;
strcpy(rocketModel[i].modelString, "RocketPort 16 port w/external I/F");
rocketModel[i].numPorts = 16;
break;
case PCI_DEVICE_ID_URP16INTF:
max_num_aiops = 2;
rocketModel[i].model = MODEL_UPCI_RP16INTF;
strcpy(rocketModel[i].modelString, "RocketPort UPCI 16 port w/external I/F");
rocketModel[i].numPorts = 16;
break;
case PCI_DEVICE_ID_CRP16INTF:
max_num_aiops = 2;
rocketModel[i].model = MODEL_CPCI_RP16INTF;
strcpy(rocketModel[i].modelString, "RocketPort Compact PCI 16 port w/external I/F");
rocketModel[i].numPorts = 16;
break;
case PCI_DEVICE_ID_RP32INTF:
max_num_aiops = 4;
rocketModel[i].model = MODEL_RP32INTF;
strcpy(rocketModel[i].modelString, "RocketPort 32 port w/external I/F");
rocketModel[i].numPorts = 32;
break;
case PCI_DEVICE_ID_URP32INTF:
max_num_aiops = 4;
rocketModel[i].model = MODEL_UPCI_RP32INTF;
strcpy(rocketModel[i].modelString, "RocketPort UPCI 32 port w/external I/F");
rocketModel[i].numPorts = 32;
break;
case PCI_DEVICE_ID_RPP4:
max_num_aiops = 1;
ports_per_aiop = 4;
altChanRingIndicator++;
fast_clock++;
rocketModel[i].model = MODEL_RPP4;
strcpy(rocketModel[i].modelString, "RocketPort Plus 4 port");
rocketModel[i].numPorts = 4;
break;
case PCI_DEVICE_ID_RPP8:
max_num_aiops = 2;
ports_per_aiop = 4;
altChanRingIndicator++;
fast_clock++;
rocketModel[i].model = MODEL_RPP8;
strcpy(rocketModel[i].modelString, "RocketPort Plus 8 port");
rocketModel[i].numPorts = 8;
break;
case PCI_DEVICE_ID_RP2_232:
max_num_aiops = 1;
ports_per_aiop = 2;
altChanRingIndicator++;
fast_clock++;
rocketModel[i].model = MODEL_RP2_232;
strcpy(rocketModel[i].modelString, "RocketPort Plus 2 port RS232");
rocketModel[i].numPorts = 2;
break;
case PCI_DEVICE_ID_RP2_422:
max_num_aiops = 1;
ports_per_aiop = 2;
altChanRingIndicator++;
fast_clock++;
rocketModel[i].model = MODEL_RP2_422;
strcpy(rocketModel[i].modelString, "RocketPort Plus 2 port RS422");
rocketModel[i].numPorts = 2;
break;
case PCI_DEVICE_ID_RP6M:
max_num_aiops = 1;
ports_per_aiop = 6;
if (dev->revision == 1) {
rcktpt_type[i] = ROCKET_TYPE_MODEMII;
rocketModel[i].loadrm2 = 1;
} else {
rcktpt_type[i] = ROCKET_TYPE_MODEM;
}
rocketModel[i].model = MODEL_RP6M;
strcpy(rocketModel[i].modelString, "RocketModem 6 port");
rocketModel[i].numPorts = 6;
break;
case PCI_DEVICE_ID_RP4M:
max_num_aiops = 1;
ports_per_aiop = 4;
if (dev->revision == 1) {
rcktpt_type[i] = ROCKET_TYPE_MODEMII;
rocketModel[i].loadrm2 = 1;
} else {
rcktpt_type[i] = ROCKET_TYPE_MODEM;
}
rocketModel[i].model = MODEL_RP4M;
strcpy(rocketModel[i].modelString, "RocketModem 4 port");
rocketModel[i].numPorts = 4;
break;
default:
max_num_aiops = 0;
break;
}
switch (dev->device) {
case PCI_DEVICE_ID_URP32INTF:
case PCI_DEVICE_ID_URP8INTF:
case PCI_DEVICE_ID_URP16INTF:
case PCI_DEVICE_ID_CRP16INTF:
case PCI_DEVICE_ID_URP8OCTA:
rcktpt_io_addr[i] = pci_resource_start(dev, 2);
ConfigIO = pci_resource_start(dev, 1);
if (dev->device == PCI_DEVICE_ID_URP8OCTA) {
UPCIRingInd = rcktpt_io_addr[i] + _PCI_9030_RING_IND;
if (!
(sInW(ConfigIO + _PCI_9030_GPIO_CTRL) &
PCI_GPIO_CTRL_8PORT)) {
ports_per_aiop = 4;
rocketModel[i].numPorts = 4;
}
}
break;
case PCI_DEVICE_ID_UPCI_RM3_8PORT:
max_num_aiops = 1;
rocketModel[i].model = MODEL_UPCI_RM3_8PORT;
strcpy(rocketModel[i].modelString, "RocketModem III 8 port");
rocketModel[i].numPorts = 8;
rcktpt_io_addr[i] = pci_resource_start(dev, 2);
UPCIRingInd = rcktpt_io_addr[i] + _PCI_9030_RING_IND;
ConfigIO = pci_resource_start(dev, 1);
rcktpt_type[i] = ROCKET_TYPE_MODEMIII;
break;
case PCI_DEVICE_ID_UPCI_RM3_4PORT:
max_num_aiops = 1;
rocketModel[i].model = MODEL_UPCI_RM3_4PORT;
strcpy(rocketModel[i].modelString, "RocketModem III 4 port");
rocketModel[i].numPorts = 4;
rcktpt_io_addr[i] = pci_resource_start(dev, 2);
UPCIRingInd = rcktpt_io_addr[i] + _PCI_9030_RING_IND;
ConfigIO = pci_resource_start(dev, 1);
rcktpt_type[i] = ROCKET_TYPE_MODEMIII;
break;
default:
break;
}
if (fast_clock) {
sClockPrescale = 0x12;
rp_baud_base[i] = 921600;
} else {
if (support_low_speed) {
sClockPrescale = 0x19;
rp_baud_base[i] = 230400;
} else {
sClockPrescale = 0x14;
rp_baud_base[i] = 460800;
}
}
for (aiop = 0; aiop < max_num_aiops; aiop++)
aiopio[aiop] = rcktpt_io_addr[i] + (aiop * 0x40);
ctlp = sCtlNumToCtlPtr(i);
num_aiops = sPCIInitController(ctlp, i, aiopio, max_num_aiops, ConfigIO, 0, FREQ_DIS, 0, altChanRingIndicator, UPCIRingInd);
for (aiop = 0; aiop < max_num_aiops; aiop++)
ctlp->AiopNumChan[aiop] = ports_per_aiop;
dev_info(&dev->dev, "comtrol PCI controller #%d found at "
"address %04lx, %d AIOP(s) (%s), creating ttyR%d - %ld\n",
i, rcktpt_io_addr[i], num_aiops, rocketModel[i].modelString,
rocketModel[i].startingPortNumber,
rocketModel[i].startingPortNumber + rocketModel[i].numPorts-1);
if (num_aiops <= 0) {
rcktpt_io_addr[i] = 0;
return (0);
}
is_PCI[i] = 1;
for (aiop = 0; aiop < num_aiops; aiop++) {
sResetAiopByNum(ctlp, aiop);
num_chan = ports_per_aiop;
for (chan = 0; chan < num_chan; chan++)
init_r_port(i, aiop, chan, dev);
}
if ((rcktpt_type[i] == ROCKET_TYPE_MODEM) ||
(rcktpt_type[i] == ROCKET_TYPE_MODEMII) ||
(rcktpt_type[i] == ROCKET_TYPE_MODEMIII)) {
num_chan = ports_per_aiop;
for (chan = 0; chan < num_chan; chan++)
sPCIModemReset(ctlp, chan, 1);
msleep(500);
for (chan = 0; chan < num_chan; chan++)
sPCIModemReset(ctlp, chan, 0);
msleep(500);
rmSpeakerReset(ctlp, rocketModel[i].model);
}
return (1);
}
static int __init init_PCI(int boards_found)
{
struct pci_dev *dev = NULL;
int count = 0;
while ((dev = pci_get_device(PCI_VENDOR_ID_RP, PCI_ANY_ID, dev))) {
if (register_PCI(count + boards_found, dev))
count++;
}
return (count);
}
static int __init init_ISA(int i)
{
int num_aiops, num_chan = 0, total_num_chan = 0;
int aiop, chan;
unsigned int aiopio[MAX_AIOPS_PER_BOARD];
CONTROLLER_t *ctlp;
char *type_string;
if (rcktpt_io_addr[i] == 0)
return (0);
if (!request_region(rcktpt_io_addr[i], 64, "Comtrol RocketPort")) {
printk(KERN_ERR "Unable to reserve IO region for configured "
"ISA RocketPort at address 0x%lx, board not "
"installed...\n", rcktpt_io_addr[i]);
rcktpt_io_addr[i] = 0;
return (0);
}
ctlp = sCtlNumToCtlPtr(i);
ctlp->boardType = rcktpt_type[i];
switch (rcktpt_type[i]) {
case ROCKET_TYPE_PC104:
type_string = "(PC104)";
break;
case ROCKET_TYPE_MODEM:
type_string = "(RocketModem)";
break;
case ROCKET_TYPE_MODEMII:
type_string = "(RocketModem II)";
break;
default:
type_string = "";
break;
}
if (support_low_speed) {
sClockPrescale = 0x19;
rp_baud_base[i] = 230400;
} else {
sClockPrescale = 0x14;
rp_baud_base[i] = 460800;
}
for (aiop = 0; aiop < MAX_AIOPS_PER_BOARD; aiop++)
aiopio[aiop] = rcktpt_io_addr[i] + (aiop * 0x400);
num_aiops = sInitController(ctlp, i, controller + (i * 0x400), aiopio, MAX_AIOPS_PER_BOARD, 0, FREQ_DIS, 0);
if (ctlp->boardType == ROCKET_TYPE_PC104) {
sEnAiop(ctlp, 2);
sEnAiop(ctlp, 3);
}
if (num_aiops <= 0) {
release_region(rcktpt_io_addr[i], 64);
rcktpt_io_addr[i] = 0;
return (0);
}
rocketModel[i].startingPortNumber = nextLineNumber;
for (aiop = 0; aiop < num_aiops; aiop++) {
sResetAiopByNum(ctlp, aiop);
sEnAiop(ctlp, aiop);
num_chan = sGetAiopNumChan(ctlp, aiop);
total_num_chan += num_chan;
for (chan = 0; chan < num_chan; chan++)
init_r_port(i, aiop, chan, NULL);
}
is_PCI[i] = 0;
if ((rcktpt_type[i] == ROCKET_TYPE_MODEM) || (rcktpt_type[i] == ROCKET_TYPE_MODEMII)) {
num_chan = sGetAiopNumChan(ctlp, 0);
total_num_chan = num_chan;
for (chan = 0; chan < num_chan; chan++)
sModemReset(ctlp, chan, 1);
msleep(500);
for (chan = 0; chan < num_chan; chan++)
sModemReset(ctlp, chan, 0);
msleep(500);
strcpy(rocketModel[i].modelString, "RocketModem ISA");
} else {
strcpy(rocketModel[i].modelString, "RocketPort ISA");
}
rocketModel[i].numPorts = total_num_chan;
rocketModel[i].model = MODEL_ISA;
printk(KERN_INFO "RocketPort ISA card #%d found at 0x%lx - %d AIOPs %s\n",
i, rcktpt_io_addr[i], num_aiops, type_string);
printk(KERN_INFO "Installing %s, creating /dev/ttyR%d - %ld\n",
rocketModel[i].modelString,
rocketModel[i].startingPortNumber,
rocketModel[i].startingPortNumber +
rocketModel[i].numPorts - 1);
return (1);
}
static int __init rp_init(void)
{
int ret = -ENOMEM, pci_boards_found, isa_boards_found, i;
printk(KERN_INFO "RocketPort device driver module, version %s, %s\n",
ROCKET_VERSION, ROCKET_DATE);
rocket_driver = alloc_tty_driver(MAX_RP_PORTS);
if (!rocket_driver)
goto err;
if (board1) {
if (controller == 0)
controller = board1 + 0x40;
} else {
controller = 0;
}
if (controller && (!request_region(controller, 4, "Comtrol RocketPort"))) {
printk(KERN_ERR "Unable to reserve IO region for first "
"configured ISA RocketPort controller 0x%lx. "
"Driver exiting\n", controller);
ret = -EBUSY;
goto err_tty;
}
rcktpt_io_addr[0] = board1;
rcktpt_io_addr[1] = board2;
rcktpt_io_addr[2] = board3;
rcktpt_io_addr[3] = board4;
rcktpt_type[0] = modem1 ? ROCKET_TYPE_MODEM : ROCKET_TYPE_NORMAL;
rcktpt_type[0] = pc104_1[0] ? ROCKET_TYPE_PC104 : rcktpt_type[0];
rcktpt_type[1] = modem2 ? ROCKET_TYPE_MODEM : ROCKET_TYPE_NORMAL;
rcktpt_type[1] = pc104_2[0] ? ROCKET_TYPE_PC104 : rcktpt_type[1];
rcktpt_type[2] = modem3 ? ROCKET_TYPE_MODEM : ROCKET_TYPE_NORMAL;
rcktpt_type[2] = pc104_3[0] ? ROCKET_TYPE_PC104 : rcktpt_type[2];
rcktpt_type[3] = modem4 ? ROCKET_TYPE_MODEM : ROCKET_TYPE_NORMAL;
rcktpt_type[3] = pc104_4[0] ? ROCKET_TYPE_PC104 : rcktpt_type[3];
rocket_driver->flags = TTY_DRIVER_DYNAMIC_DEV;
rocket_driver->name = "ttyR";
rocket_driver->driver_name = "Comtrol RocketPort";
rocket_driver->major = TTY_ROCKET_MAJOR;
rocket_driver->minor_start = 0;
rocket_driver->type = TTY_DRIVER_TYPE_SERIAL;
rocket_driver->subtype = SERIAL_TYPE_NORMAL;
rocket_driver->init_termios = tty_std_termios;
rocket_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
rocket_driver->init_termios.c_ispeed = 9600;
rocket_driver->init_termios.c_ospeed = 9600;
#ifdef ROCKET_SOFT_FLOW
rocket_driver->flags |= TTY_DRIVER_REAL_RAW;
#endif
tty_set_operations(rocket_driver, &rocket_ops);
ret = tty_register_driver(rocket_driver);
if (ret < 0) {
printk(KERN_ERR "Couldn't install tty RocketPort driver\n");
goto err_controller;
}
#ifdef ROCKET_DEBUG_OPEN
printk(KERN_INFO "RocketPort driver is major %d\n", rocket_driver.major);
#endif
isa_boards_found = 0;
pci_boards_found = 0;
for (i = 0; i < NUM_BOARDS; i++) {
if (init_ISA(i))
isa_boards_found++;
}
#ifdef CONFIG_PCI
if (isa_boards_found < NUM_BOARDS)
pci_boards_found = init_PCI(isa_boards_found);
#endif
max_board = pci_boards_found + isa_boards_found;
if (max_board == 0) {
printk(KERN_ERR "No rocketport ports found; unloading driver\n");
ret = -ENXIO;
goto err_ttyu;
}
return 0;
err_ttyu:
tty_unregister_driver(rocket_driver);
err_controller:
if (controller)
release_region(controller, 4);
err_tty:
put_tty_driver(rocket_driver);
err:
return ret;
}
static void rp_cleanup_module(void)
{
int retval;
int i;
del_timer_sync(&rocket_timer);
retval = tty_unregister_driver(rocket_driver);
if (retval)
printk(KERN_ERR "Error %d while trying to unregister "
"rocketport driver\n", -retval);
for (i = 0; i < MAX_RP_PORTS; i++)
if (rp_table[i]) {
tty_unregister_device(rocket_driver, i);
tty_port_destroy(&rp_table[i]->port);
kfree(rp_table[i]);
}
put_tty_driver(rocket_driver);
for (i = 0; i < NUM_BOARDS; i++) {
if (rcktpt_io_addr[i] <= 0 || is_PCI[i])
continue;
release_region(rcktpt_io_addr[i], 64);
}
if (controller)
release_region(controller, 4);
}
static int sInitController(CONTROLLER_T * CtlP, int CtlNum, ByteIO_t MudbacIO,
ByteIO_t * AiopIOList, int AiopIOListSize,
int IRQNum, Byte_t Frequency, int PeriodicOnly)
{
int i;
ByteIO_t io;
int done;
CtlP->AiopIntrBits = aiop_intr_bits;
CtlP->AltChanRingIndicator = 0;
CtlP->CtlNum = CtlNum;
CtlP->CtlID = CTLID_0001;
CtlP->BusType = isISA;
CtlP->MBaseIO = MudbacIO;
CtlP->MReg1IO = MudbacIO + 1;
CtlP->MReg2IO = MudbacIO + 2;
CtlP->MReg3IO = MudbacIO + 3;
#if 1
CtlP->MReg2 = 0;
CtlP->MReg3 = 0;
#else
if (sIRQMap[IRQNum] == 0) {
CtlP->MReg2 = 0;
CtlP->MReg3 = 0;
} else {
CtlP->MReg2 = sIRQMap[IRQNum];
CtlP->MReg3 = Frequency;
if (PeriodicOnly) {
CtlP->MReg3 |= PERIODIC_ONLY;
}
}
#endif
sOutB(CtlP->MReg2IO, CtlP->MReg2);
sOutB(CtlP->MReg3IO, CtlP->MReg3);
sControllerEOI(CtlP);
CtlP->NumAiop = 0;
for (i = done = 0; i < AiopIOListSize; i++) {
io = AiopIOList[i];
CtlP->AiopIO[i] = (WordIO_t) io;
CtlP->AiopIntChanIO[i] = io + _INT_CHAN;
sOutB(CtlP->MReg2IO, CtlP->MReg2 | (i & 0x03));
sOutB(MudbacIO, (Byte_t) (io >> 6));
if (done)
continue;
sEnAiop(CtlP, i);
CtlP->AiopID[i] = sReadAiopID(io);
if (CtlP->AiopID[i] == AIOPID_NULL)
done = 1;
else {
CtlP->AiopNumChan[i] = sReadAiopNumChan((WordIO_t) io);
sOutW((WordIO_t) io + _INDX_ADDR, _CLK_PRE);
sOutB(io + _INDX_DATA, sClockPrescale);
CtlP->NumAiop++;
}
sDisAiop(CtlP, i);
}
if (CtlP->NumAiop == 0)
return (-1);
else
return (CtlP->NumAiop);
}
static int sReadAiopID(ByteIO_t io)
{
Byte_t AiopID;
sOutB(io + _CMD_REG, RESET_ALL);
sOutB(io + _CMD_REG, 0x0);
AiopID = sInW(io + _CHN_STAT0) & 0x07;
if (AiopID == 0x06)
return (1);
else
return (-1);
}
static int sReadAiopNumChan(WordIO_t io)
{
Word_t x;
static Byte_t R[4] = { 0x00, 0x00, 0x34, 0x12 };
out32((DWordIO_t) io + _INDX_ADDR, R);
sOutW(io + _INDX_ADDR, 0);
x = sInW(io + _INDX_DATA);
sOutW(io + _INDX_ADDR, 0x4000);
if (x != sInW(io + _INDX_DATA))
return (8);
else
return (4);
}
static int sInitChan(CONTROLLER_T * CtlP, CHANNEL_T * ChP, int AiopNum,
int ChanNum)
{
int i;
WordIO_t AiopIO;
WordIO_t ChIOOff;
Byte_t *ChR;
Word_t ChOff;
static Byte_t R[4];
int brd9600;
if (ChanNum >= CtlP->AiopNumChan[AiopNum])
return 0;
ChP->CtlP = CtlP;
ChP->ChanID = CtlP->AiopID[AiopNum];
ChP->AiopNum = AiopNum;
ChP->ChanNum = ChanNum;
AiopIO = CtlP->AiopIO[AiopNum];
ChP->Cmd = (ByteIO_t) AiopIO + _CMD_REG;
ChP->IntChan = (ByteIO_t) AiopIO + _INT_CHAN;
ChP->IntMask = (ByteIO_t) AiopIO + _INT_MASK;
ChP->IndexAddr = (DWordIO_t) AiopIO + _INDX_ADDR;
ChP->IndexData = AiopIO + _INDX_DATA;
ChIOOff = AiopIO + ChP->ChanNum * 2;
ChP->TxRxData = ChIOOff + _TD0;
ChP->ChanStat = ChIOOff + _CHN_STAT0;
ChP->TxRxCount = ChIOOff + _FIFO_CNT0;
ChP->IntID = (ByteIO_t) AiopIO + ChP->ChanNum + _INT_ID0;
for (i = 0; i < RDATASIZE; i += 4) {
R[0] = RData[i];
R[1] = RData[i + 1] + 0x10 * ChanNum;
R[2] = RData[i + 2];
R[3] = RData[i + 3];
out32(ChP->IndexAddr, R);
}
ChR = ChP->R;
for (i = 0; i < RREGDATASIZE; i += 4) {
ChR[i] = RRegData[i];
ChR[i + 1] = RRegData[i + 1] + 0x10 * ChanNum;
ChR[i + 2] = RRegData[i + 2];
ChR[i + 3] = RRegData[i + 3];
}
ChOff = (Word_t) ChanNum *0x1000;
if (sClockPrescale == 0x14)
brd9600 = 47;
else
brd9600 = 23;
ChP->BaudDiv[0] = (Byte_t) (ChOff + _BAUD);
ChP->BaudDiv[1] = (Byte_t) ((ChOff + _BAUD) >> 8);
ChP->BaudDiv[2] = (Byte_t) brd9600;
ChP->BaudDiv[3] = (Byte_t) (brd9600 >> 8);
out32(ChP->IndexAddr, ChP->BaudDiv);
ChP->TxControl[0] = (Byte_t) (ChOff + _TX_CTRL);
ChP->TxControl[1] = (Byte_t) ((ChOff + _TX_CTRL) >> 8);
ChP->TxControl[2] = 0;
ChP->TxControl[3] = 0;
out32(ChP->IndexAddr, ChP->TxControl);
ChP->RxControl[0] = (Byte_t) (ChOff + _RX_CTRL);
ChP->RxControl[1] = (Byte_t) ((ChOff + _RX_CTRL) >> 8);
ChP->RxControl[2] = 0;
ChP->RxControl[3] = 0;
out32(ChP->IndexAddr, ChP->RxControl);
ChP->TxEnables[0] = (Byte_t) (ChOff + _TX_ENBLS);
ChP->TxEnables[1] = (Byte_t) ((ChOff + _TX_ENBLS) >> 8);
ChP->TxEnables[2] = 0;
ChP->TxEnables[3] = 0;
out32(ChP->IndexAddr, ChP->TxEnables);
ChP->TxCompare[0] = (Byte_t) (ChOff + _TXCMP1);
ChP->TxCompare[1] = (Byte_t) ((ChOff + _TXCMP1) >> 8);
ChP->TxCompare[2] = 0;
ChP->TxCompare[3] = 0;
out32(ChP->IndexAddr, ChP->TxCompare);
ChP->TxReplace1[0] = (Byte_t) (ChOff + _TXREP1B1);
ChP->TxReplace1[1] = (Byte_t) ((ChOff + _TXREP1B1) >> 8);
ChP->TxReplace1[2] = 0;
ChP->TxReplace1[3] = 0;
out32(ChP->IndexAddr, ChP->TxReplace1);
ChP->TxReplace2[0] = (Byte_t) (ChOff + _TXREP2);
ChP->TxReplace2[1] = (Byte_t) ((ChOff + _TXREP2) >> 8);
ChP->TxReplace2[2] = 0;
ChP->TxReplace2[3] = 0;
out32(ChP->IndexAddr, ChP->TxReplace2);
ChP->TxFIFOPtrs = ChOff + _TXF_OUTP;
ChP->TxFIFO = ChOff + _TX_FIFO;
sOutB(ChP->Cmd, (Byte_t) ChanNum | RESTXFCNT);
sOutB(ChP->Cmd, (Byte_t) ChanNum);
sOutW((WordIO_t) ChP->IndexAddr, ChP->TxFIFOPtrs);
sOutW(ChP->IndexData, 0);
ChP->RxFIFOPtrs = ChOff + _RXF_OUTP;
ChP->RxFIFO = ChOff + _RX_FIFO;
sOutB(ChP->Cmd, (Byte_t) ChanNum | RESRXFCNT);
sOutB(ChP->Cmd, (Byte_t) ChanNum);
sOutW((WordIO_t) ChP->IndexAddr, ChP->RxFIFOPtrs);
sOutW(ChP->IndexData, 0);
sOutW((WordIO_t) ChP->IndexAddr, ChP->RxFIFOPtrs + 2);
sOutW(ChP->IndexData, 0);
ChP->TxPrioCnt = ChOff + _TXP_CNT;
sOutW((WordIO_t) ChP->IndexAddr, ChP->TxPrioCnt);
sOutB(ChP->IndexData, 0);
ChP->TxPrioPtr = ChOff + _TXP_PNTR;
sOutW((WordIO_t) ChP->IndexAddr, ChP->TxPrioPtr);
sOutB(ChP->IndexData, 0);
ChP->TxPrioBuf = ChOff + _TXP_BUF;
sEnRxProcessor(ChP);
return 1;
}
static void sStopRxProcessor(CHANNEL_T * ChP)
{
Byte_t R[4];
R[0] = ChP->R[0];
R[1] = ChP->R[1];
R[2] = 0x0a;
R[3] = ChP->R[3];
out32(ChP->IndexAddr, R);
}
static void sFlushRxFIFO(CHANNEL_T * ChP)
{
int i;
Byte_t Ch;
int RxFIFOEnabled;
if (sGetRxCnt(ChP) == 0)
return;
RxFIFOEnabled = 0;
if (ChP->R[0x32] == 0x08) {
RxFIFOEnabled = 1;
sDisRxFIFO(ChP);
for (i = 0; i < 2000 / 200; i++)
sInB(ChP->IntChan);
}
sGetChanStatus(ChP);
Ch = (Byte_t) sGetChanNum(ChP);
sOutB(ChP->Cmd, Ch | RESRXFCNT);
sOutB(ChP->Cmd, Ch);
sOutW((WordIO_t) ChP->IndexAddr, ChP->RxFIFOPtrs);
sOutW(ChP->IndexData, 0);
sOutW((WordIO_t) ChP->IndexAddr, ChP->RxFIFOPtrs + 2);
sOutW(ChP->IndexData, 0);
if (RxFIFOEnabled)
sEnRxFIFO(ChP);
}
static void sFlushTxFIFO(CHANNEL_T * ChP)
{
int i;
Byte_t Ch;
int TxEnabled;
if (sGetTxCnt(ChP) == 0)
return;
TxEnabled = 0;
if (ChP->TxControl[3] & TX_ENABLE) {
TxEnabled = 1;
sDisTransmit(ChP);
}
sStopRxProcessor(ChP);
for (i = 0; i < 4000 / 200; i++)
sInB(ChP->IntChan);
Ch = (Byte_t) sGetChanNum(ChP);
sOutB(ChP->Cmd, Ch | RESTXFCNT);
sOutB(ChP->Cmd, Ch);
sOutW((WordIO_t) ChP->IndexAddr, ChP->TxFIFOPtrs);
sOutW(ChP->IndexData, 0);
if (TxEnabled)
sEnTransmit(ChP);
sStartRxProcessor(ChP);
}
static int sWriteTxPrioByte(CHANNEL_T * ChP, Byte_t Data)
{
Byte_t DWBuf[4];
Word_t *WordPtr;
register DWordIO_t IndexAddr;
if (sGetTxCnt(ChP) > 1) {
IndexAddr = ChP->IndexAddr;
sOutW((WordIO_t) IndexAddr, ChP->TxPrioCnt);
if (sInB((ByteIO_t) ChP->IndexData) & PRI_PEND)
return (0);
WordPtr = (Word_t *) (&DWBuf[0]);
*WordPtr = ChP->TxPrioBuf;
DWBuf[2] = Data;
out32(IndexAddr, DWBuf);
*WordPtr = ChP->TxPrioCnt;
DWBuf[2] = PRI_PEND + 1;
DWBuf[3] = 0;
out32(IndexAddr, DWBuf);
} else {
sWriteTxByte(sGetTxRxDataIO(ChP), Data);
}
return (1);
}
static void sEnInterrupts(CHANNEL_T * ChP, Word_t Flags)
{
Byte_t Mask;
ChP->RxControl[2] |=
((Byte_t) Flags & (RXINT_EN | SRCINT_EN | MCINT_EN));
out32(ChP->IndexAddr, ChP->RxControl);
ChP->TxControl[2] |= ((Byte_t) Flags & TXINT_EN);
out32(ChP->IndexAddr, ChP->TxControl);
if (Flags & CHANINT_EN) {
Mask = sInB(ChP->IntMask) | sBitMapSetTbl[ChP->ChanNum];
sOutB(ChP->IntMask, Mask);
}
}
static void sDisInterrupts(CHANNEL_T * ChP, Word_t Flags)
{
Byte_t Mask;
ChP->RxControl[2] &=
~((Byte_t) Flags & (RXINT_EN | SRCINT_EN | MCINT_EN));
out32(ChP->IndexAddr, ChP->RxControl);
ChP->TxControl[2] &= ~((Byte_t) Flags & TXINT_EN);
out32(ChP->IndexAddr, ChP->TxControl);
if (Flags & CHANINT_EN) {
Mask = sInB(ChP->IntMask) & sBitMapClrTbl[ChP->ChanNum];
sOutB(ChP->IntMask, Mask);
}
}
static void sSetInterfaceMode(CHANNEL_T * ChP, Byte_t mode)
{
sOutB(ChP->CtlP->AiopIO[2], (mode & 0x18) | ChP->ChanNum);
}
static void sModemReset(CONTROLLER_T * CtlP, int chan, int on)
{
ByteIO_t addr;
Byte_t val;
addr = CtlP->AiopIO[0] + 0x400;
val = sInB(CtlP->MReg3IO);
if ((val & 2) == 0) {
val = sInB(CtlP->MReg2IO);
sOutB(CtlP->MReg2IO, (val & 0xfc) | (1 & 0x03));
sOutB(CtlP->MBaseIO, (unsigned char) (addr >> 6));
}
sEnAiop(CtlP, 1);
if (!on)
addr += 8;
sOutB(addr + chan, 0);
sDisAiop(CtlP, 1);
}
static void sPCIModemReset(CONTROLLER_T * CtlP, int chan, int on)
{
ByteIO_t addr;
addr = CtlP->AiopIO[0] + 0x40;
if (!on)
addr += 8;
sOutB(addr + chan, 0);
}
static unsigned char GetLineNumber(int ctrl, int aiop, int ch)
{
return lineNumbers[(ctrl << 5) | (aiop << 3) | ch];
}
static unsigned char SetLineNumber(int ctrl, int aiop, int ch)
{
lineNumbers[(ctrl << 5) | (aiop << 3) | ch] = nextLineNumber++;
return (nextLineNumber - 1);
}
