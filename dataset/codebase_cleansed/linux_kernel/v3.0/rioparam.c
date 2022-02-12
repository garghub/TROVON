int RIOParam(struct Port *PortP, int cmd, int Modem, int SleepFlag)
{
struct tty_struct *TtyP;
int retval;
struct phb_param __iomem *phb_param_ptr;
struct PKT __iomem *PacketP;
int res;
u8 Cor1 = 0, Cor2 = 0, Cor4 = 0, Cor5 = 0;
u8 TxXon = 0, TxXoff = 0, RxXon = 0, RxXoff = 0;
u8 LNext = 0, TxBaud = 0, RxBaud = 0;
int retries = 0xff;
unsigned long flags;
func_enter();
TtyP = PortP->gs.port.tty;
rio_dprintk(RIO_DEBUG_PARAM, "RIOParam: Port:%d cmd:%d Modem:%d SleepFlag:%d Mapped: %d, tty=%p\n", PortP->PortNum, cmd, Modem, SleepFlag, PortP->Mapped, TtyP);
if (!TtyP) {
rio_dprintk(RIO_DEBUG_PARAM, "Can't call rioparam with null tty.\n");
func_exit();
return RIO_FAIL;
}
rio_spin_lock_irqsave(&PortP->portSem, flags);
if (cmd == RIOC_OPEN) {
}
while (!(res = can_add_transmit(&PacketP, PortP)) || (PortP->InUse != NOT_INUSE)) {
if (retries-- <= 0) {
break;
}
if (PortP->InUse != NOT_INUSE) {
rio_dprintk(RIO_DEBUG_PARAM, "Port IN_USE for pre-emptive command\n");
}
if (!res) {
rio_dprintk(RIO_DEBUG_PARAM, "Port has no space on transmit queue\n");
}
if (SleepFlag != OK_TO_SLEEP) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return RIO_FAIL;
}
rio_dprintk(RIO_DEBUG_PARAM, "wait for can_add_transmit\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
retval = RIODelay(PortP, HUNDRED_MS);
rio_spin_lock_irqsave(&PortP->portSem, flags);
if (retval == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_PARAM, "wait for can_add_transmit broken by signal\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return -EINTR;
}
if (PortP->State & RIO_DELETED) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return 0;
}
}
if (!res) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return RIO_FAIL;
}
rio_dprintk(RIO_DEBUG_PARAM, "can_add_transmit() returns %x\n", res);
rio_dprintk(RIO_DEBUG_PARAM, "Packet is %p\n", PacketP);
phb_param_ptr = (struct phb_param __iomem *) PacketP->data;
switch (TtyP->termios->c_cflag & CSIZE) {
case CS5:
{
rio_dprintk(RIO_DEBUG_PARAM, "5 bit data\n");
Cor1 |= RIOC_COR1_5BITS;
break;
}
case CS6:
{
rio_dprintk(RIO_DEBUG_PARAM, "6 bit data\n");
Cor1 |= RIOC_COR1_6BITS;
break;
}
case CS7:
{
rio_dprintk(RIO_DEBUG_PARAM, "7 bit data\n");
Cor1 |= RIOC_COR1_7BITS;
break;
}
case CS8:
{
rio_dprintk(RIO_DEBUG_PARAM, "8 bit data\n");
Cor1 |= RIOC_COR1_8BITS;
break;
}
}
if (TtyP->termios->c_cflag & CSTOPB) {
rio_dprintk(RIO_DEBUG_PARAM, "2 stop bits\n");
Cor1 |= RIOC_COR1_2STOP;
} else {
rio_dprintk(RIO_DEBUG_PARAM, "1 stop bit\n");
Cor1 |= RIOC_COR1_1STOP;
}
if (TtyP->termios->c_cflag & PARENB) {
rio_dprintk(RIO_DEBUG_PARAM, "Enable parity\n");
Cor1 |= RIOC_COR1_NORMAL;
} else {
rio_dprintk(RIO_DEBUG_PARAM, "Disable parity\n");
Cor1 |= RIOC_COR1_NOP;
}
if (TtyP->termios->c_cflag & PARODD) {
rio_dprintk(RIO_DEBUG_PARAM, "Odd parity\n");
Cor1 |= RIOC_COR1_ODD;
} else {
rio_dprintk(RIO_DEBUG_PARAM, "Even parity\n");
Cor1 |= RIOC_COR1_EVEN;
}
if (TtyP->termios->c_iflag & IXON) {
rio_dprintk(RIO_DEBUG_PARAM, "Enable start/stop output control\n");
Cor2 |= RIOC_COR2_IXON;
} else {
if (PortP->Config & RIO_IXON) {
rio_dprintk(RIO_DEBUG_PARAM, "Force enable start/stop output control\n");
Cor2 |= RIOC_COR2_IXON;
} else
rio_dprintk(RIO_DEBUG_PARAM, "IXON has been disabled.\n");
}
if (TtyP->termios->c_iflag & IXANY) {
if (PortP->Config & RIO_IXANY) {
rio_dprintk(RIO_DEBUG_PARAM, "Enable any key to restart output\n");
Cor2 |= RIOC_COR2_IXANY;
} else
rio_dprintk(RIO_DEBUG_PARAM, "IXANY has been disabled due to sanity reasons.\n");
}
if (TtyP->termios->c_iflag & IXOFF) {
rio_dprintk(RIO_DEBUG_PARAM, "Enable start/stop input control 2\n");
Cor2 |= RIOC_COR2_IXOFF;
}
if (TtyP->termios->c_cflag & HUPCL) {
rio_dprintk(RIO_DEBUG_PARAM, "Hangup on last close\n");
Cor2 |= RIOC_COR2_HUPCL;
}
if (C_CRTSCTS(TtyP)) {
rio_dprintk(RIO_DEBUG_PARAM, "Rx hardware flow control enabled\n");
Cor2 |= RIOC_COR2_CTSFLOW;
Cor2 |= RIOC_COR2_RTSFLOW;
} else {
rio_dprintk(RIO_DEBUG_PARAM, "Rx hardware flow control disabled\n");
Cor2 &= ~RIOC_COR2_CTSFLOW;
Cor2 &= ~RIOC_COR2_RTSFLOW;
}
if (TtyP->termios->c_cflag & CLOCAL) {
rio_dprintk(RIO_DEBUG_PARAM, "Local line\n");
} else {
rio_dprintk(RIO_DEBUG_PARAM, "Possible Modem line\n");
}
if (TtyP->termios->c_iflag & IGNBRK) {
rio_dprintk(RIO_DEBUG_PARAM, "Ignore break condition\n");
Cor4 |= RIOC_COR4_IGNBRK;
}
if (!(TtyP->termios->c_iflag & BRKINT)) {
rio_dprintk(RIO_DEBUG_PARAM, "Break generates NULL condition\n");
Cor4 |= RIOC_COR4_NBRKINT;
} else {
rio_dprintk(RIO_DEBUG_PARAM, "Interrupt on break condition\n");
}
if (TtyP->termios->c_iflag & INLCR) {
rio_dprintk(RIO_DEBUG_PARAM, "Map newline to carriage return on input\n");
Cor4 |= RIOC_COR4_INLCR;
}
if (TtyP->termios->c_iflag & IGNCR) {
rio_dprintk(RIO_DEBUG_PARAM, "Ignore carriage return on input\n");
Cor4 |= RIOC_COR4_IGNCR;
}
if (TtyP->termios->c_iflag & ICRNL) {
rio_dprintk(RIO_DEBUG_PARAM, "Map carriage return to newline on input\n");
Cor4 |= RIOC_COR4_ICRNL;
}
if (TtyP->termios->c_iflag & IGNPAR) {
rio_dprintk(RIO_DEBUG_PARAM, "Ignore characters with parity errors\n");
Cor4 |= RIOC_COR4_IGNPAR;
}
if (TtyP->termios->c_iflag & PARMRK) {
rio_dprintk(RIO_DEBUG_PARAM, "Mark parity errors\n");
Cor4 |= RIOC_COR4_PARMRK;
}
Cor4 |= RIOC_COR4_RAISEMOD;
Cor5 = RIOC_COR5_CMOE;
if (PortP->MonitorTstate)
Cor5 |= RIOC_COR5_TSTATE_ON;
else
Cor5 |= RIOC_COR5_TSTATE_OFF;
if (TtyP->termios->c_iflag & ISTRIP) {
rio_dprintk(RIO_DEBUG_PARAM, "Strip input characters\n");
if (!(PortP->State & RIO_TRIAD_MODE)) {
Cor5 |= RIOC_COR5_ISTRIP;
}
}
if (TtyP->termios->c_oflag & ONLCR) {
rio_dprintk(RIO_DEBUG_PARAM, "Map newline to carriage-return, newline on output\n");
if (PortP->CookMode == COOK_MEDIUM)
Cor5 |= RIOC_COR5_ONLCR;
}
if (TtyP->termios->c_oflag & OCRNL) {
rio_dprintk(RIO_DEBUG_PARAM, "Map carriage return to newline on output\n");
if (PortP->CookMode == COOK_MEDIUM)
Cor5 |= RIOC_COR5_OCRNL;
}
if ((TtyP->termios->c_oflag & TABDLY) == TAB3) {
rio_dprintk(RIO_DEBUG_PARAM, "Tab delay 3 set\n");
if (PortP->CookMode == COOK_MEDIUM)
Cor5 |= RIOC_COR5_TAB3;
}
TxXon = TtyP->termios->c_cc[VSTART];
TxXoff = TtyP->termios->c_cc[VSTOP];
RxXon = TtyP->termios->c_cc[VSTART];
RxXoff = TtyP->termios->c_cc[VSTOP];
LNext = 0;
rio_dprintk(RIO_DEBUG_PARAM, "Mapping of rx/tx baud %x (%x)\n", TtyP->termios->c_cflag, CBAUD);
switch (TtyP->termios->c_cflag & CBAUD) {
#define e(b) case B ## b : RxBaud = TxBaud = RIO_B ## b ;break
e(50);
e(75);
e(110);
e(134);
e(150);
e(200);
e(300);
e(600);
e(1200);
e(1800);
e(2400);
e(4800);
e(9600);
e(19200);
e(38400);
e(57600);
e(115200);
}
rio_dprintk(RIO_DEBUG_PARAM, "tx baud 0x%x, rx baud 0x%x\n", TxBaud, RxBaud);
if (TtyP->termios->c_cflag & CREAD)
rio_dprintk(RIO_DEBUG_PARAM, "Enable receiver\n");
#ifdef RCV1EN
if (TtyP->termios->c_cflag & RCV1EN)
rio_dprintk(RIO_DEBUG_PARAM, "RCV1EN (?)\n");
#endif
#ifdef XMT1EN
if (TtyP->termios->c_cflag & XMT1EN)
rio_dprintk(RIO_DEBUG_PARAM, "XMT1EN (?)\n");
#endif
if (TtyP->termios->c_lflag & ISIG)
rio_dprintk(RIO_DEBUG_PARAM, "Input character signal generating enabled\n");
if (TtyP->termios->c_lflag & ICANON)
rio_dprintk(RIO_DEBUG_PARAM, "Canonical input: erase and kill enabled\n");
if (TtyP->termios->c_lflag & XCASE)
rio_dprintk(RIO_DEBUG_PARAM, "Canonical upper/lower presentation\n");
if (TtyP->termios->c_lflag & ECHO)
rio_dprintk(RIO_DEBUG_PARAM, "Enable input echo\n");
if (TtyP->termios->c_lflag & ECHOE)
rio_dprintk(RIO_DEBUG_PARAM, "Enable echo erase\n");
if (TtyP->termios->c_lflag & ECHOK)
rio_dprintk(RIO_DEBUG_PARAM, "Enable echo kill\n");
if (TtyP->termios->c_lflag & ECHONL)
rio_dprintk(RIO_DEBUG_PARAM, "Enable echo newline\n");
if (TtyP->termios->c_lflag & NOFLSH)
rio_dprintk(RIO_DEBUG_PARAM, "Disable flush after interrupt or quit\n");
#ifdef TOSTOP
if (TtyP->termios->c_lflag & TOSTOP)
rio_dprintk(RIO_DEBUG_PARAM, "Send SIGTTOU for background output\n");
#endif
#ifdef XCLUDE
if (TtyP->termios->c_lflag & XCLUDE)
rio_dprintk(RIO_DEBUG_PARAM, "Exclusive use of this line\n");
#endif
if (TtyP->termios->c_iflag & IUCLC)
rio_dprintk(RIO_DEBUG_PARAM, "Map uppercase to lowercase on input\n");
if (TtyP->termios->c_oflag & OPOST)
rio_dprintk(RIO_DEBUG_PARAM, "Enable output post-processing\n");
if (TtyP->termios->c_oflag & OLCUC)
rio_dprintk(RIO_DEBUG_PARAM, "Map lowercase to uppercase on output\n");
if (TtyP->termios->c_oflag & ONOCR)
rio_dprintk(RIO_DEBUG_PARAM, "No carriage return output at column 0\n");
if (TtyP->termios->c_oflag & ONLRET)
rio_dprintk(RIO_DEBUG_PARAM, "Newline performs carriage return function\n");
if (TtyP->termios->c_oflag & OFILL)
rio_dprintk(RIO_DEBUG_PARAM, "Use fill characters for delay\n");
if (TtyP->termios->c_oflag & OFDEL)
rio_dprintk(RIO_DEBUG_PARAM, "Fill character is DEL\n");
if (TtyP->termios->c_oflag & NLDLY)
rio_dprintk(RIO_DEBUG_PARAM, "Newline delay set\n");
if (TtyP->termios->c_oflag & CRDLY)
rio_dprintk(RIO_DEBUG_PARAM, "Carriage return delay set\n");
if (TtyP->termios->c_oflag & TABDLY)
rio_dprintk(RIO_DEBUG_PARAM, "Tab delay set\n");
PortP->Cor2Copy = Cor2;
if (PortP->State & RIO_DELETED) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return RIO_FAIL;
}
writeb(cmd, &phb_param_ptr->Cmd);
writeb(Cor1, &phb_param_ptr->Cor1);
writeb(Cor2, &phb_param_ptr->Cor2);
writeb(Cor4, &phb_param_ptr->Cor4);
writeb(Cor5, &phb_param_ptr->Cor5);
writeb(TxXon, &phb_param_ptr->TxXon);
writeb(RxXon, &phb_param_ptr->RxXon);
writeb(TxXoff, &phb_param_ptr->TxXoff);
writeb(RxXoff, &phb_param_ptr->RxXoff);
writeb(LNext, &phb_param_ptr->LNext);
writeb(TxBaud, &phb_param_ptr->TxBaud);
writeb(RxBaud, &phb_param_ptr->RxBaud);
writeb(12 | PKT_CMD_BIT, &PacketP->len);
add_transmit(PortP);
if (PortP->statsGather)
PortP->txchars += 12;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_PARAM, "add_transmit returned.\n");
func_exit();
return 0;
}
int can_add_transmit(struct PKT __iomem **PktP, struct Port *PortP)
{
struct PKT __iomem *tp;
*PktP = tp = (struct PKT __iomem *) RIO_PTR(PortP->Caddr, readw(PortP->TxAdd));
return !((unsigned long) tp & PKT_IN_USE);
}
void add_transmit(struct Port *PortP)
{
if (readw(PortP->TxAdd) & PKT_IN_USE) {
rio_dprintk(RIO_DEBUG_PARAM, "add_transmit: Packet has been stolen!");
}
writew(readw(PortP->TxAdd) | PKT_IN_USE, PortP->TxAdd);
PortP->TxAdd = (PortP->TxAdd == PortP->TxEnd) ? PortP->TxStart : PortP->TxAdd + 1;
writew(RIO_OFF(PortP->Caddr, PortP->TxAdd), &PortP->PhbP->tx_add);
}
void put_free_end(struct Host *HostP, struct PKT __iomem *PktP)
{
struct rio_free_list __iomem *tmp_pointer;
unsigned short old_end, new_end;
unsigned long flags;
rio_spin_lock_irqsave(&HostP->HostLock, flags);
rio_dprintk(RIO_DEBUG_PFE, "put_free_end(PktP=%p)\n", PktP);
if ((old_end = readw(&HostP->ParmMapP->free_list_end)) != TPNULL) {
new_end = RIO_OFF(HostP->Caddr, PktP);
tmp_pointer = (struct rio_free_list __iomem *) RIO_PTR(HostP->Caddr, old_end);
writew(new_end, &tmp_pointer->next);
writew(old_end, &((struct rio_free_list __iomem *) PktP)->prev);
writew(TPNULL, &((struct rio_free_list __iomem *) PktP)->next);
writew(new_end, &HostP->ParmMapP->free_list_end);
} else {
rio_dprintk(RIO_DEBUG_PFE, "put_free_end(): This should never happen\n");
writew(RIO_OFF(HostP->Caddr, PktP), &HostP->ParmMapP->free_list_end);
tmp_pointer = (struct rio_free_list __iomem *) PktP;
writew(TPNULL, &tmp_pointer->prev);
writew(TPNULL, &tmp_pointer->next);
}
rio_dprintk(RIO_DEBUG_CMD, "Before unlock: %p\n", &HostP->HostLock);
rio_spin_unlock_irqrestore(&HostP->HostLock, flags);
}
int can_remove_receive(struct PKT __iomem **PktP, struct Port *PortP)
{
if (readw(PortP->RxRemove) & PKT_IN_USE) {
*PktP = (struct PKT __iomem *) RIO_PTR(PortP->Caddr, readw(PortP->RxRemove) & ~PKT_IN_USE);
return 1;
}
return 0;
}
void remove_receive(struct Port *PortP)
{
writew(readw(PortP->RxRemove) & ~PKT_IN_USE, PortP->RxRemove);
PortP->RxRemove = (PortP->RxRemove == PortP->RxEnd) ? PortP->RxStart : PortP->RxRemove + 1;
writew(RIO_OFF(PortP->Caddr, PortP->RxRemove), &PortP->PhbP->rx_remove);
}
