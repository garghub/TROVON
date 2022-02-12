static char *firstchars(char *p, int nch)
{
static char buf[2][128];
static int t = 0;
t = !t;
memcpy(buf[t], p, nch);
buf[t][nch] = 0;
return buf[t];
}
void RIOTxEnable(char *en)
{
struct Port *PortP;
struct rio_info *p;
struct tty_struct *tty;
int c;
struct PKT __iomem *PacketP;
unsigned long flags;
PortP = (struct Port *) en;
p = (struct rio_info *) PortP->p;
tty = PortP->gs.port.tty;
rio_dprintk(RIO_DEBUG_INTR, "tx port %d: %d chars queued.\n", PortP->PortNum, PortP->gs.xmit_cnt);
if (!PortP->gs.xmit_cnt)
return;
rio_spin_lock_irqsave(&PortP->portSem, flags);
while (can_add_transmit(&PacketP, PortP)) {
c = PortP->gs.xmit_cnt;
if (c > PKT_MAX_DATA_LEN)
c = PKT_MAX_DATA_LEN;
if (c > SERIAL_XMIT_SIZE - PortP->gs.xmit_tail)
c = SERIAL_XMIT_SIZE - PortP->gs.xmit_tail;
{
int t;
t = (c > 10) ? 10 : c;
rio_dprintk(RIO_DEBUG_INTR, "rio: tx port %d: copying %d chars: %s - %s\n", PortP->PortNum, c, firstchars(PortP->gs.xmit_buf + PortP->gs.xmit_tail, t), firstchars(PortP->gs.xmit_buf + PortP->gs.xmit_tail + c - t, t));
}
if (c == 0)
break;
rio_memcpy_toio(PortP->HostP->Caddr, PacketP->data, PortP->gs.xmit_buf + PortP->gs.xmit_tail, c);
writeb(c, &(PacketP->len));
if (!(PortP->State & RIO_DELETED)) {
add_transmit(PortP);
if (PortP->statsGather)
PortP->txchars += c;
}
PortP->gs.xmit_tail = (PortP->gs.xmit_tail + c) & (SERIAL_XMIT_SIZE - 1);
PortP->gs.xmit_cnt -= c;
}
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (PortP->gs.xmit_cnt <= (PortP->gs.wakeup_chars + 2 * PKT_MAX_DATA_LEN))
tty_wakeup(PortP->gs.port.tty);
}
void RIOServiceHost(struct rio_info *p, struct Host *HostP)
{
rio_spin_lock(&HostP->HostLock);
if ((HostP->Flags & RUN_STATE) != RC_RUNNING) {
static int t = 0;
rio_spin_unlock(&HostP->HostLock);
if ((t++ % 200) == 0)
rio_dprintk(RIO_DEBUG_INTR, "Interrupt but host not running. flags=%x.\n", (int) HostP->Flags);
return;
}
rio_spin_unlock(&HostP->HostLock);
if (readw(&HostP->ParmMapP->rup_intr)) {
writew(0, &HostP->ParmMapP->rup_intr);
p->RIORupCount++;
RupIntr++;
rio_dprintk(RIO_DEBUG_INTR, "rio: RUP interrupt on host %Zd\n", HostP - p->RIOHosts);
RIOPollHostCommands(p, HostP);
}
if (readw(&HostP->ParmMapP->rx_intr)) {
int port;
writew(0, &HostP->ParmMapP->rx_intr);
p->RIORxCount++;
RxIntr++;
rio_dprintk(RIO_DEBUG_INTR, "rio: RX interrupt on host %Zd\n", HostP - p->RIOHosts);
for (port = p->RIOFirstPortsBooted; port < p->RIOLastPortsBooted + PORTS_PER_RTA; port++) {
struct Port *PortP = p->RIOPortp[port];
struct tty_struct *ttyP;
struct PKT __iomem *PacketP;
if (!PortP->Mapped) {
port += 7;
continue;
}
if (PortP->HostP != HostP) {
port += 7;
continue;
}
if (!(PortP->PortState & PORT_ISOPEN)) {
continue;
}
ttyP = PortP->gs.port.tty;
rio_spin_lock(&PortP->portSem);
if (can_remove_receive(&PacketP, PortP))
RIOReceive(p, PortP);
if (!can_remove_receive(&PacketP, PortP) && (readw(&PortP->PhbP->handshake) == PHB_HANDSHAKE_SET)) {
rio_dprintk(RIO_DEBUG_INTR, "Set RX handshake bit\n");
writew(PHB_HANDSHAKE_SET | PHB_HANDSHAKE_RESET, &PortP->PhbP->handshake);
}
rio_spin_unlock(&PortP->portSem);
}
}
if (readw(&HostP->ParmMapP->tx_intr)) {
int port;
writew(0, &HostP->ParmMapP->tx_intr);
p->RIOTxCount++;
TxIntr++;
rio_dprintk(RIO_DEBUG_INTR, "rio: TX interrupt on host %Zd\n", HostP - p->RIOHosts);
for (port = p->RIOFirstPortsBooted; port < p->RIOLastPortsBooted + PORTS_PER_RTA; port++) {
struct Port *PortP = p->RIOPortp[port];
struct tty_struct *ttyP;
struct PKT __iomem *PacketP;
if (!PortP->Mapped) {
port += 7;
continue;
}
if (PortP->HostP != HostP) {
port += 7;
continue;
}
if (!(PortP->PortState & PORT_ISOPEN)) {
continue;
}
rio_dprintk(RIO_DEBUG_INTR, "rio: Looking into port %d.\n", port);
rio_spin_lock(&PortP->portSem);
if (!can_add_transmit(&PacketP, PortP)) {
rio_dprintk(RIO_DEBUG_INTR, "Can't add to port, so skipping.\n");
rio_spin_unlock(&PortP->portSem);
continue;
}
ttyP = PortP->gs.port.tty;
if (!ttyP) {
rio_dprintk(RIO_DEBUG_INTR, "no tty, so skipping.\n");
rio_spin_unlock(&PortP->portSem);
continue;
}
if (PortP->MagicFlags) {
if (PortP->MagicFlags & MAGIC_REBOOT) {
PortP->InUse = NOT_INUSE;
rio_spin_unlock(&PortP->portSem);
if (RIOParam(PortP, RIOC_OPEN, ((PortP->Cor2Copy & (RIOC_COR2_RTSFLOW | RIOC_COR2_CTSFLOW)) == (RIOC_COR2_RTSFLOW | RIOC_COR2_CTSFLOW)) ? 1 : 0, DONT_SLEEP) == RIO_FAIL)
continue;
rio_spin_lock(&PortP->portSem);
PortP->MagicFlags &= ~MAGIC_REBOOT;
}
if (PortP->WflushFlag) {
rio_dprintk(RIO_DEBUG_INTR, "Want to WFLUSH mark this port\n");
if (PortP->InUse)
rio_dprintk(RIO_DEBUG_INTR, "FAILS - PORT IS IN USE\n");
}
while (PortP->WflushFlag && can_add_transmit(&PacketP, PortP) && (PortP->InUse == NOT_INUSE)) {
int p;
struct PktCmd __iomem *PktCmdP;
rio_dprintk(RIO_DEBUG_INTR, "Add WFLUSH marker to data queue\n");
PktCmdP = (struct PktCmd __iomem *) &PacketP->data[0];
writeb(RIOC_WFLUSH, &PktCmdP->Command);
p = PortP->HostPort % (u16) PORTS_PER_RTA;
if (PortP->SecondBlock)
p += PORTS_PER_RTA;
writeb(p, &PktCmdP->PhbNum);
writeb('W', &PacketP->data[2]);
writeb('F', &PacketP->data[3]);
writeb('L', &PacketP->data[4]);
writeb('U', &PacketP->data[5]);
writeb('S', &PacketP->data[6]);
writeb('H', &PacketP->data[7]);
writeb(' ', &PacketP->data[8]);
writeb('0' + PortP->WflushFlag, &PacketP->data[9]);
writeb(' ', &PacketP->data[10]);
writeb(' ', &PacketP->data[11]);
writeb('\0', &PacketP->data[12]);
writeb(PKT_CMD_BIT | 2, &PacketP->len);
if (!(PortP->State & RIO_DELETED)) {
add_transmit(PortP);
if (PortP->statsGather)
PortP->txchars += 2;
}
if (--(PortP->WflushFlag) == 0) {
PortP->MagicFlags &= ~MAGIC_FLUSH;
}
rio_dprintk(RIO_DEBUG_INTR, "Wflush count now stands at %d\n", PortP->WflushFlag);
}
if (PortP->MagicFlags & MORE_OUTPUT_EYGOR) {
if (PortP->MagicFlags & MAGIC_FLUSH) {
PortP->MagicFlags |= MORE_OUTPUT_EYGOR;
} else {
if (!can_add_transmit(&PacketP, PortP)) {
rio_spin_unlock(&PortP->portSem);
continue;
}
rio_spin_unlock(&PortP->portSem);
RIOTxEnable((char *) PortP);
rio_spin_lock(&PortP->portSem);
PortP->MagicFlags &= ~MORE_OUTPUT_EYGOR;
}
}
}
if (!can_add_transmit(&PacketP, PortP)) {
rio_spin_unlock(&PortP->portSem);
continue;
}
rio_spin_unlock(&PortP->portSem);
RIOTxEnable((char *) PortP);
}
}
}
static void RIOReceive(struct rio_info *p, struct Port *PortP)
{
struct tty_struct *TtyP;
unsigned short transCount;
struct PKT __iomem *PacketP;
register unsigned int DataCnt;
unsigned char __iomem *ptr;
unsigned char *buf;
int copied = 0;
static int intCount, RxIntCnt;
intCount++;
TtyP = PortP->gs.port.tty;
if (!TtyP) {
rio_dprintk(RIO_DEBUG_INTR, "RIOReceive: tty is null. \n");
return;
}
if (PortP->State & RIO_THROTTLE_RX) {
rio_dprintk(RIO_DEBUG_INTR, "RIOReceive: Throttled. Can't handle more input.\n");
return;
}
if (PortP->State & RIO_DELETED) {
while (can_remove_receive(&PacketP, PortP)) {
remove_receive(PortP);
put_free_end(PortP->HostP, PacketP);
}
} else {
transCount = 1;
while (can_remove_receive(&PacketP, PortP)
&& transCount) {
RxIntCnt++;
if (readb(&PacketP->len) & PKT_CMD_BIT) {
rio_dprintk(RIO_DEBUG_INTR, "RIO: unexpected command packet received on PHB\n");
rio_dprintk(RIO_DEBUG_INTR, " dest_unit = %d\n", readb(&PacketP->dest_unit));
rio_dprintk(RIO_DEBUG_INTR, " dest_port = %d\n", readb(&PacketP->dest_port));
rio_dprintk(RIO_DEBUG_INTR, " src_unit = %d\n", readb(&PacketP->src_unit));
rio_dprintk(RIO_DEBUG_INTR, " src_port = %d\n", readb(&PacketP->src_port));
rio_dprintk(RIO_DEBUG_INTR, " len = %d\n", readb(&PacketP->len));
rio_dprintk(RIO_DEBUG_INTR, " control = %d\n", readb(&PacketP->control));
rio_dprintk(RIO_DEBUG_INTR, " csum = %d\n", readw(&PacketP->csum));
rio_dprintk(RIO_DEBUG_INTR, " data bytes: ");
for (DataCnt = 0; DataCnt < PKT_MAX_DATA_LEN; DataCnt++)
rio_dprintk(RIO_DEBUG_INTR, "%d\n", readb(&PacketP->data[DataCnt]));
remove_receive(PortP);
put_free_end(PortP->HostP, PacketP);
continue;
}
transCount = tty_buffer_request_room(TtyP, readb(&PacketP->len) & PKT_LEN_MASK);
rio_dprintk(RIO_DEBUG_REC, "port %d: Copy %d bytes\n", PortP->PortNum, transCount);
ptr = (unsigned char __iomem *) PacketP->data + PortP->RxDataStart;
tty_prepare_flip_string(TtyP, &buf, transCount);
rio_memcpy_fromio(buf, ptr, transCount);
PortP->RxDataStart += transCount;
writeb(readb(&PacketP->len)-transCount, &PacketP->len);
copied += transCount;
if (readb(&PacketP->len) == 0) {
remove_receive(PortP);
put_free_end(PortP->HostP, PacketP);
PortP->RxDataStart = 0;
}
}
}
if (copied) {
rio_dprintk(RIO_DEBUG_REC, "port %d: pushing tty flip buffer: %d total bytes copied.\n", PortP->PortNum, copied);
tty_flip_buffer_push(TtyP);
}
return;
}
