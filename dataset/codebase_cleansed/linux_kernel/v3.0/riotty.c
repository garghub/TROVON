int riotopen(struct tty_struct *tty, struct file *filp)
{
unsigned int SysPort;
int repeat_this = 250;
struct Port *PortP;
unsigned long flags;
int retval = 0;
func_enter();
tty->driver_data = NULL;
SysPort = rio_minor(tty);
if (p->RIOFailed) {
rio_dprintk(RIO_DEBUG_TTY, "System initialisation failed\n");
func_exit();
return -ENXIO;
}
rio_dprintk(RIO_DEBUG_TTY, "port open SysPort %d (mapped:%d)\n", SysPort, p->RIOPortp[SysPort]->Mapped);
if (SysPort >= RIO_PORTS) {
rio_dprintk(RIO_DEBUG_TTY, "Illegal port number %d\n", SysPort);
func_exit();
return -ENXIO;
}
PortP = p->RIOPortp[SysPort];
rio_dprintk(RIO_DEBUG_TTY, "PortP: %p\n", PortP);
if (!PortP->Mapped) {
rio_dprintk(RIO_DEBUG_TTY, "port not mapped into system\n");
func_exit();
return -ENXIO;
}
tty->driver_data = PortP;
PortP->gs.port.tty = tty;
PortP->gs.port.count++;
rio_dprintk(RIO_DEBUG_TTY, "%d bytes in tx buffer\n", PortP->gs.xmit_cnt);
retval = gs_init_port(&PortP->gs);
if (retval) {
PortP->gs.port.count--;
return -ENXIO;
}
if ((PortP->HostP->Flags & RUN_STATE) != RC_RUNNING) {
rio_dprintk(RIO_DEBUG_TTY, "Host not running\n");
func_exit();
return -ENXIO;
}
rio_dprintk(RIO_DEBUG_TTY, "Checking if RTA has booted... \n");
while (!(PortP->HostP->Mapping[PortP->RupNum].Flags & RTA_BOOTED)) {
if (!PortP->WaitUntilBooted) {
rio_dprintk(RIO_DEBUG_TTY, "RTA never booted\n");
func_exit();
return -ENXIO;
}
if (RIODelay(PortP, HUNDRED_MS) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_TTY, "RTA_wait_for_boot: EINTR in delay \n");
func_exit();
return -EINTR;
}
if (repeat_this-- <= 0) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for RTA to boot timeout\n");
func_exit();
return -EIO;
}
}
rio_dprintk(RIO_DEBUG_TTY, "RTA has been booted\n");
rio_spin_lock_irqsave(&PortP->portSem, flags);
if (p->RIOHalted) {
goto bombout;
}
while ((PortP->State & RIO_CLOSING) && !p->RIOHalted) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for RIO_CLOSING to go away\n");
if (repeat_this-- <= 0) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for not idle closed broken by signal\n");
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
retval = -EINTR;
goto bombout;
}
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (RIODelay(PortP, HUNDRED_MS) == RIO_FAIL) {
rio_spin_lock_irqsave(&PortP->portSem, flags);
retval = -EINTR;
goto bombout;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
if (!PortP->Mapped) {
rio_dprintk(RIO_DEBUG_TTY, "Port unmapped while closing!\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
retval = -ENXIO;
func_exit();
return retval;
}
if (p->RIOHalted) {
goto bombout;
}
if (!(PortP->State & (RIO_LOPEN | RIO_MOPEN))) {
PortP->Config &= ~(RIO_CTSFLOW | RIO_RTSFLOW);
}
if (!(PortP->firstOpen)) {
rio_dprintk(RIO_DEBUG_TTY, "First open for this port\n");
PortP->firstOpen++;
PortP->CookMode = 0;
PortP->InUse = NOT_INUSE;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
RIOParam(PortP, RIOC_OPEN, 1, OK_TO_SLEEP);
rio_spin_lock_irqsave(&PortP->portSem, flags);
while (!(PortP->PortState & PORT_ISOPEN) && !p->RIOHalted) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for PORT_ISOPEN-currently %x\n", PortP->PortState);
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (RIODelay(PortP, HUNDRED_MS) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for open to finish broken by signal\n");
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
func_exit();
return -EINTR;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
if (p->RIOHalted) {
retval = -EIO;
bombout:
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return retval;
}
rio_dprintk(RIO_DEBUG_TTY, "PORT_ISOPEN found\n");
}
rio_dprintk(RIO_DEBUG_TTY, "Modem - test for carrier\n");
if ((PortP->gs.port.tty->termios->c_cflag & CLOCAL) ||
(PortP->ModemState & RIOC_MSVR1_CD)) {
rio_dprintk(RIO_DEBUG_TTY, "open(%d) Modem carr on\n", SysPort);
PortP->State |= RIO_CARR_ON;
wake_up_interruptible(&PortP->gs.port.open_wait);
} else {
while (!(PortP->State & RIO_CARR_ON) && !(filp->f_flags & O_NONBLOCK) && !p->RIOHalted) {
rio_dprintk(RIO_DEBUG_TTY, "open(%d) sleeping for carr on\n", SysPort);
PortP->State |= RIO_WOPEN;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (RIODelay(PortP, HUNDRED_MS) == RIO_FAIL) {
rio_spin_lock_irqsave(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_TTY, "open(%d) sleeping for carr broken by signal\n", SysPort);
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
PortP->State &= ~RIO_WOPEN;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return -EINTR;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
PortP->State &= ~RIO_WOPEN;
}
if (p->RIOHalted)
goto bombout;
rio_dprintk(RIO_DEBUG_TTY, "Setting RIO_MOPEN\n");
PortP->State |= RIO_MOPEN;
if (p->RIOHalted)
goto bombout;
rio_dprintk(RIO_DEBUG_TTY, "high level open done\n");
if (PortP->statsGather)
PortP->opens++;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_TTY, "Returning from open\n");
func_exit();
return 0;
}
int riotclose(void *ptr)
{
struct Port *PortP = ptr;
int deleted = 0;
int try = -1;
int repeat_this = -1;
unsigned long end_time;
struct tty_struct *tty;
unsigned long flags;
int rv = 0;
rio_dprintk(RIO_DEBUG_TTY, "port close SysPort %d\n", PortP->PortNum);
rio_dprintk(RIO_DEBUG_TTY, "Port is at address %p\n", PortP);
tty = PortP->gs.port.tty;
rio_dprintk(RIO_DEBUG_TTY, "TTY is at address %p\n", tty);
if (PortP->gs.closing_wait)
end_time = jiffies + PortP->gs.closing_wait;
else
end_time = jiffies + MAX_SCHEDULE_TIMEOUT;
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->State |= RIO_CLOSING;
if ((PortP->State & RIO_DELETED)) {
rio_dprintk(RIO_DEBUG_TTY, "Close on deleted RTA\n");
deleted = 1;
}
if (p->RIOHalted) {
RIOClearUp(PortP);
rv = -EIO;
goto close_end;
}
rio_dprintk(RIO_DEBUG_TTY, "Clear bits\n");
PortP->State &= ~RIO_MOPEN;
PortP->State &= ~RIO_CARR_ON;
PortP->ModemState &= ~RIOC_MSVR1_CD;
if ((PortP->State & (RIO_LOPEN | RIO_MOPEN))) {
rio_dprintk(RIO_DEBUG_TTY, "Channel %d still open !\n", PortP->PortNum);
PortP->State &= ~RIO_CLOSING;
if (PortP->firstOpen)
PortP->firstOpen--;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return -EIO;
}
rio_dprintk(RIO_DEBUG_TTY, "Closing down - everything must go!\n");
PortP->State &= ~RIO_DYNOROD;
rio_dprintk(RIO_DEBUG_TTY, "Timeout 1 starts\n");
if (!deleted)
while ((PortP->InUse != NOT_INUSE) && !p->RIOHalted && (PortP->TxBufferIn != PortP->TxBufferOut)) {
if (repeat_this-- <= 0) {
rv = -EINTR;
rio_dprintk(RIO_DEBUG_TTY, "Waiting for not idle closed broken by signal\n");
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
goto close_end;
}
rio_dprintk(RIO_DEBUG_TTY, "Calling timeout to flush in closing\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (RIODelay_ni(PortP, HUNDRED_MS * 10) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_TTY, "RTA EINTR in delay \n");
rv = -EINTR;
rio_spin_lock_irqsave(&PortP->portSem, flags);
goto close_end;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
PortP->TxBufferIn = PortP->TxBufferOut = 0;
repeat_this = 0xff;
PortP->InUse = 0;
if ((PortP->State & (RIO_LOPEN | RIO_MOPEN))) {
rio_dprintk(RIO_DEBUG_TTY, "Channel %d re-open!\n", PortP->PortNum);
PortP->State &= ~RIO_CLOSING;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (PortP->firstOpen)
PortP->firstOpen--;
return -EIO;
}
if (p->RIOHalted) {
RIOClearUp(PortP);
goto close_end;
}
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (RIOShortCommand(p, PortP, RIOC_CLOSE, 1, 0) == RIO_FAIL) {
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
rio_spin_lock_irqsave(&PortP->portSem, flags);
goto close_end;
}
if (!deleted)
while (try && (PortP->PortState & PORT_ISOPEN)) {
try--;
if (time_after(jiffies, end_time)) {
rio_dprintk(RIO_DEBUG_TTY, "Run out of tries - force the bugger shut!\n");
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
break;
}
rio_dprintk(RIO_DEBUG_TTY, "Close: PortState:ISOPEN is %d\n", PortP->PortState & PORT_ISOPEN);
if (p->RIOHalted) {
RIOClearUp(PortP);
rio_spin_lock_irqsave(&PortP->portSem, flags);
goto close_end;
}
if (RIODelay(PortP, HUNDRED_MS) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_TTY, "RTA EINTR in delay \n");
RIOPreemptiveCmd(p, PortP, RIOC_FCLOSE);
break;
}
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_TTY, "Close: try was %d on completion\n", try);
PortP->Config &= ~(RIO_CTSFLOW | RIO_RTSFLOW);
if (PortP->statsGather)
PortP->closes++;
close_end:
PortP->State &= ~(RIO_CLOSING | RIO_DELETED);
if (PortP->firstOpen)
PortP->firstOpen--;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_TTY, "Return from close\n");
return rv;
}
static void RIOClearUp(struct Port *PortP)
{
rio_dprintk(RIO_DEBUG_TTY, "RIOHalted set\n");
PortP->Config = 0;
PortP->PortState = 0;
PortP->firstOpen = 0;
PortP->FlushCmdBodge = 0;
PortP->ModemState = PortP->CookMode = 0;
PortP->Mapped = 0;
PortP->WflushFlag = 0;
PortP->MagicFlags = 0;
PortP->RxDataStart = 0;
PortP->TxBufferIn = 0;
PortP->TxBufferOut = 0;
}
int RIOShortCommand(struct rio_info *p, struct Port *PortP, int command, int len, int arg)
{
struct PKT __iomem *PacketP;
int retries = 20;
unsigned long flags;
rio_dprintk(RIO_DEBUG_TTY, "entering shortcommand.\n");
if (PortP->State & RIO_DELETED) {
rio_dprintk(RIO_DEBUG_TTY, "Short command to deleted RTA ignored\n");
return RIO_FAIL;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
while ((PortP->InUse != NOT_INUSE) && !p->RIOHalted) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting for not in use (%d)\n", retries);
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (retries-- <= 0) {
return RIO_FAIL;
}
if (RIODelay_ni(PortP, HUNDRED_MS) == RIO_FAIL) {
return RIO_FAIL;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
if (PortP->State & RIO_DELETED) {
rio_dprintk(RIO_DEBUG_TTY, "Short command to deleted RTA ignored\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return RIO_FAIL;
}
while (!can_add_transmit(&PacketP, PortP) && !p->RIOHalted) {
rio_dprintk(RIO_DEBUG_TTY, "Waiting to add short command to queue (%d)\n", retries);
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (retries-- <= 0) {
rio_dprintk(RIO_DEBUG_TTY, "out of tries. Failing\n");
return RIO_FAIL;
}
if (RIODelay_ni(PortP, HUNDRED_MS) == RIO_FAIL) {
return RIO_FAIL;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
}
if (p->RIOHalted) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return RIO_FAIL;
}
writeb(command, &PacketP->data[0]);
if (len == 2)
writeb(arg, &PacketP->data[1]);
writeb(PKT_CMD_BIT | len, &PacketP->len);
add_transmit(PortP);
if (PortP->statsGather)
PortP->txchars += len;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return p->RIOHalted ? RIO_FAIL : ~RIO_FAIL;
}
