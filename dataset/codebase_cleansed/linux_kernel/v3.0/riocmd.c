int RIOFoadRta(struct Host *HostP, struct Map *MapP)
{
struct CmdBlk *CmdBlkP;
rio_dprintk(RIO_DEBUG_CMD, "FOAD RTA\n");
CmdBlkP = RIOGetCmdBlk();
if (!CmdBlkP) {
rio_dprintk(RIO_DEBUG_CMD, "FOAD RTA: GetCmdBlk failed\n");
return -ENXIO;
}
CmdBlkP->Packet.dest_unit = MapP->ID;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->Packet.len = 0x84;
CmdBlkP->Packet.data[0] = IFOAD;
CmdBlkP->Packet.data[1] = 0;
CmdBlkP->Packet.data[2] = IFOAD_MAGIC & 0xFF;
CmdBlkP->Packet.data[3] = (IFOAD_MAGIC >> 8) & 0xFF;
if (RIOQueueCmdBlk(HostP, MapP->ID - 1, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "FOAD RTA: Failed to queue foad command\n");
return -EIO;
}
return 0;
}
int RIOZombieRta(struct Host *HostP, struct Map *MapP)
{
struct CmdBlk *CmdBlkP;
rio_dprintk(RIO_DEBUG_CMD, "ZOMBIE RTA\n");
CmdBlkP = RIOGetCmdBlk();
if (!CmdBlkP) {
rio_dprintk(RIO_DEBUG_CMD, "ZOMBIE RTA: GetCmdBlk failed\n");
return -ENXIO;
}
CmdBlkP->Packet.dest_unit = MapP->ID;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->Packet.len = 0x84;
CmdBlkP->Packet.data[0] = ZOMBIE;
CmdBlkP->Packet.data[1] = 0;
CmdBlkP->Packet.data[2] = ZOMBIE_MAGIC & 0xFF;
CmdBlkP->Packet.data[3] = (ZOMBIE_MAGIC >> 8) & 0xFF;
if (RIOQueueCmdBlk(HostP, MapP->ID - 1, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "ZOMBIE RTA: Failed to queue zombie command\n");
return -EIO;
}
return 0;
}
int RIOCommandRta(struct rio_info *p, unsigned long RtaUnique, int (*func) (struct Host * HostP, struct Map * MapP))
{
unsigned int Host;
rio_dprintk(RIO_DEBUG_CMD, "Command RTA 0x%lx func %p\n", RtaUnique, func);
if (!RtaUnique)
return (0);
for (Host = 0; Host < p->RIONumHosts; Host++) {
unsigned int Rta;
struct Host *HostP = &p->RIOHosts[Host];
for (Rta = 0; Rta < RTAS_PER_HOST; Rta++) {
struct Map *MapP = &HostP->Mapping[Rta];
if (MapP->RtaUniqueNum == RtaUnique) {
uint Link;
for (Link = 0; Link < LINKS_PER_UNIT; Link++) {
if (MapP->Topology[Link].Unit <= (u8) MAX_RUP) {
return (*func) (HostP, MapP);
}
}
}
}
}
return -ENXIO;
}
int RIOIdentifyRta(struct rio_info *p, void __user * arg)
{
unsigned int Host;
if (copy_from_user(&IdRta, arg, sizeof(IdRta))) {
rio_dprintk(RIO_DEBUG_CMD, "RIO_IDENTIFY_RTA copy failed\n");
p->RIOError.Error = COPYIN_FAILED;
return -EFAULT;
}
for (Host = 0; Host < p->RIONumHosts; Host++) {
unsigned int Rta;
struct Host *HostP = &p->RIOHosts[Host];
for (Rta = 0; Rta < RTAS_PER_HOST; Rta++) {
struct Map *MapP = &HostP->Mapping[Rta];
if (MapP->RtaUniqueNum == IdRta.RtaUnique) {
uint Link;
for (Link = 0; Link < LINKS_PER_UNIT; Link++) {
if (MapP->Topology[Link].Unit <= (u8) MAX_RUP) {
struct CmdBlk *CmdBlkP;
rio_dprintk(RIO_DEBUG_CMD, "IDENTIFY RTA\n");
CmdBlkP = RIOGetCmdBlk();
if (!CmdBlkP) {
rio_dprintk(RIO_DEBUG_CMD, "IDENTIFY RTA: GetCmdBlk failed\n");
return -ENXIO;
}
CmdBlkP->Packet.dest_unit = MapP->ID;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->Packet.len = 0x84;
CmdBlkP->Packet.data[0] = IDENTIFY;
CmdBlkP->Packet.data[1] = 0;
CmdBlkP->Packet.data[2] = IdRta.ID;
if (RIOQueueCmdBlk(HostP, MapP->ID - 1, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "IDENTIFY RTA: Failed to queue command\n");
return -EIO;
}
return 0;
}
}
}
}
}
return -ENOENT;
}
int RIOKillNeighbour(struct rio_info *p, void __user * arg)
{
uint Host;
uint ID;
struct Host *HostP;
struct CmdBlk *CmdBlkP;
rio_dprintk(RIO_DEBUG_CMD, "KILL HOST NEIGHBOUR\n");
if (copy_from_user(&KillUnit, arg, sizeof(KillUnit))) {
rio_dprintk(RIO_DEBUG_CMD, "RIO_KILL_NEIGHBOUR copy failed\n");
p->RIOError.Error = COPYIN_FAILED;
return -EFAULT;
}
if (KillUnit.Link > 3)
return -ENXIO;
CmdBlkP = RIOGetCmdBlk();
if (!CmdBlkP) {
rio_dprintk(RIO_DEBUG_CMD, "UFOAD: GetCmdBlk failed\n");
return -ENXIO;
}
CmdBlkP->Packet.dest_unit = 0;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->Packet.len = 0x84;
CmdBlkP->Packet.data[0] = UFOAD;
CmdBlkP->Packet.data[1] = KillUnit.Link;
CmdBlkP->Packet.data[2] = UFOAD_MAGIC & 0xFF;
CmdBlkP->Packet.data[3] = (UFOAD_MAGIC >> 8) & 0xFF;
for (Host = 0; Host < p->RIONumHosts; Host++) {
ID = 0;
HostP = &p->RIOHosts[Host];
if (HostP->UniqueNum == KillUnit.UniqueNum) {
if (RIOQueueCmdBlk(HostP, RTAS_PER_HOST + KillUnit.Link, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "UFOAD: Failed queue command\n");
return -EIO;
}
return 0;
}
for (ID = 0; ID < RTAS_PER_HOST; ID++) {
if (HostP->Mapping[ID].RtaUniqueNum == KillUnit.UniqueNum) {
CmdBlkP->Packet.dest_unit = ID + 1;
if (RIOQueueCmdBlk(HostP, ID, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "UFOAD: Failed queue command\n");
return -EIO;
}
return 0;
}
}
}
RIOFreeCmdBlk(CmdBlkP);
return -ENXIO;
}
int RIOSuspendBootRta(struct Host *HostP, int ID, int Link)
{
struct CmdBlk *CmdBlkP;
rio_dprintk(RIO_DEBUG_CMD, "SUSPEND BOOT ON RTA ID %d, link %c\n", ID, 'A' + Link);
CmdBlkP = RIOGetCmdBlk();
if (!CmdBlkP) {
rio_dprintk(RIO_DEBUG_CMD, "SUSPEND BOOT ON RTA: GetCmdBlk failed\n");
return -ENXIO;
}
CmdBlkP->Packet.dest_unit = ID;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->Packet.len = 0x84;
CmdBlkP->Packet.data[0] = IWAIT;
CmdBlkP->Packet.data[1] = Link;
CmdBlkP->Packet.data[2] = IWAIT_MAGIC & 0xFF;
CmdBlkP->Packet.data[3] = (IWAIT_MAGIC >> 8) & 0xFF;
if (RIOQueueCmdBlk(HostP, ID - 1, CmdBlkP) == RIO_FAIL) {
rio_dprintk(RIO_DEBUG_CMD, "SUSPEND BOOT ON RTA: Failed to queue iwait command\n");
return -EIO;
}
return 0;
}
int RIOFoadWakeup(struct rio_info *p)
{
int port;
struct Port *PortP;
unsigned long flags;
for (port = 0; port < RIO_PORTS; port++) {
PortP = p->RIOPortp[port];
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->Config = 0;
PortP->State = 0;
PortP->InUse = NOT_INUSE;
PortP->PortState = 0;
PortP->FlushCmdBodge = 0;
PortP->ModemLines = 0;
PortP->ModemState = 0;
PortP->CookMode = 0;
PortP->ParamSem = 0;
PortP->Mapped = 0;
PortP->WflushFlag = 0;
PortP->MagicFlags = 0;
PortP->RxDataStart = 0;
PortP->TxBufferIn = 0;
PortP->TxBufferOut = 0;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
}
return (0);
}
static int RIOCommandRup(struct rio_info *p, uint Rup, struct Host *HostP, struct PKT __iomem *PacketP)
{
struct PktCmd __iomem *PktCmdP = (struct PktCmd __iomem *)PacketP->data;
struct Port *PortP;
struct UnixRup *UnixRupP;
unsigned short SysPort;
unsigned short ReportedModemStatus;
unsigned short rup;
unsigned short subCommand;
unsigned long flags;
func_enter();
rup = readb(&PktCmdP->PhbNum) / (unsigned short) PORTS_PER_RTA;
UnixRupP = &HostP->UnixRups[rup];
SysPort = UnixRupP->BaseSysPort + (readb(&PktCmdP->PhbNum) % (unsigned short) PORTS_PER_RTA);
rio_dprintk(RIO_DEBUG_CMD, "Command on rup %d, port %d\n", rup, SysPort);
if (UnixRupP->BaseSysPort == NO_PORT) {
rio_dprintk(RIO_DEBUG_CMD, "OBSCURE ERROR!\n");
rio_dprintk(RIO_DEBUG_CMD, "Diagnostics follow. Please WRITE THESE DOWN and report them to Specialix Technical Support\n");
rio_dprintk(RIO_DEBUG_CMD, "CONTROL information: Host number %Zd, name ``%s''\n", HostP - p->RIOHosts, HostP->Name);
rio_dprintk(RIO_DEBUG_CMD, "CONTROL information: Rup number 0x%x\n", rup);
if (Rup < (unsigned short) MAX_RUP) {
rio_dprintk(RIO_DEBUG_CMD, "CONTROL information: This is the RUP for RTA ``%s''\n", HostP->Mapping[Rup].Name);
} else
rio_dprintk(RIO_DEBUG_CMD, "CONTROL information: This is the RUP for link ``%c'' of host ``%s''\n", ('A' + Rup - MAX_RUP), HostP->Name);
rio_dprintk(RIO_DEBUG_CMD, "PACKET information: Destination 0x%x:0x%x\n", readb(&PacketP->dest_unit), readb(&PacketP->dest_port));
rio_dprintk(RIO_DEBUG_CMD, "PACKET information: Source 0x%x:0x%x\n", readb(&PacketP->src_unit), readb(&PacketP->src_port));
rio_dprintk(RIO_DEBUG_CMD, "PACKET information: Length 0x%x (%d)\n", readb(&PacketP->len), readb(&PacketP->len));
rio_dprintk(RIO_DEBUG_CMD, "PACKET information: Control 0x%x (%d)\n", readb(&PacketP->control), readb(&PacketP->control));
rio_dprintk(RIO_DEBUG_CMD, "PACKET information: Check 0x%x (%d)\n", readw(&PacketP->csum), readw(&PacketP->csum));
rio_dprintk(RIO_DEBUG_CMD, "COMMAND information: Host Port Number 0x%x, " "Command Code 0x%x\n", readb(&PktCmdP->PhbNum), readb(&PktCmdP->Command));
return 1;
}
PortP = p->RIOPortp[SysPort];
rio_spin_lock_irqsave(&PortP->portSem, flags);
switch (readb(&PktCmdP->Command)) {
case RIOC_BREAK_RECEIVED:
rio_dprintk(RIO_DEBUG_CMD, "Received a break!\n");
gs_got_break(&PortP->gs);
break;
case RIOC_COMPLETE:
rio_dprintk(RIO_DEBUG_CMD, "Command complete on phb %d host %Zd\n", readb(&PktCmdP->PhbNum), HostP - p->RIOHosts);
subCommand = 1;
switch (readb(&PktCmdP->SubCommand)) {
case RIOC_MEMDUMP:
rio_dprintk(RIO_DEBUG_CMD, "Memory dump cmd (0x%x) from addr 0x%x\n", readb(&PktCmdP->SubCommand), readw(&PktCmdP->SubAddr));
break;
case RIOC_READ_REGISTER:
rio_dprintk(RIO_DEBUG_CMD, "Read register (0x%x)\n", readw(&PktCmdP->SubAddr));
p->CdRegister = (readb(&PktCmdP->ModemStatus) & RIOC_MSVR1_HOST);
break;
default:
subCommand = 0;
break;
}
if (subCommand)
break;
rio_dprintk(RIO_DEBUG_CMD, "New status is 0x%x was 0x%x\n", readb(&PktCmdP->PortStatus), PortP->PortState);
if (PortP->PortState != readb(&PktCmdP->PortStatus)) {
rio_dprintk(RIO_DEBUG_CMD, "Mark status & wakeup\n");
PortP->PortState = readb(&PktCmdP->PortStatus);
} else
rio_dprintk(RIO_DEBUG_CMD, "No change\n");
case RIOC_MODEM_STATUS:
ReportedModemStatus = readb(&PktCmdP->ModemStatus);
if ((PortP->ModemState & RIOC_MSVR1_HOST) ==
(ReportedModemStatus & RIOC_MSVR1_HOST)) {
rio_dprintk(RIO_DEBUG_CMD, "Modem status unchanged 0x%x\n", PortP->ModemState);
PortP->ModemState = ReportedModemStatus;
} else {
rio_dprintk(RIO_DEBUG_CMD, "Modem status change from 0x%x to 0x%x\n", PortP->ModemState, ReportedModemStatus);
PortP->ModemState = ReportedModemStatus;
#ifdef MODEM_SUPPORT
if (PortP->Mapped) {
if (PortP->gs.port.tty == NULL)
break;
if (PortP->gs.port.tty->termios == NULL)
break;
if (!(PortP->gs.port.tty->termios->c_cflag & CLOCAL) && ((PortP->State & (RIO_MOPEN | RIO_WOPEN)))) {
rio_dprintk(RIO_DEBUG_CMD, "Is there a Carrier?\n");
if (PortP->ModemState & RIOC_MSVR1_CD) {
if (!(PortP->State & RIO_CARR_ON)) {
rio_dprintk(RIO_DEBUG_CMD, "Carrier just came up.\n");
PortP->State |= RIO_CARR_ON;
if (PortP->State & (PORT_ISOPEN | RIO_WOPEN))
wake_up_interruptible(&PortP->gs.port.open_wait);
}
} else {
if (PortP->State & RIO_CARR_ON) {
if (PortP->State & (PORT_ISOPEN | RIO_WOPEN | RIO_MOPEN))
tty_hangup(PortP->gs.port.tty);
PortP->State &= ~RIO_CARR_ON;
rio_dprintk(RIO_DEBUG_CMD, "Carrirer just went down\n");
}
}
}
}
#endif
}
break;
default:
rio_dprintk(RIO_DEBUG_CMD, "Unknown command %d on CMD_RUP of host %Zd\n", readb(&PktCmdP->Command), HostP - p->RIOHosts);
break;
}
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
func_exit();
return 1;
}
struct CmdBlk *RIOGetCmdBlk(void)
{
struct CmdBlk *CmdBlkP;
CmdBlkP = kzalloc(sizeof(struct CmdBlk), GFP_ATOMIC);
return CmdBlkP;
}
void RIOFreeCmdBlk(struct CmdBlk *CmdBlkP)
{
kfree(CmdBlkP);
}
int RIOQueueCmdBlk(struct Host *HostP, uint Rup, struct CmdBlk *CmdBlkP)
{
struct CmdBlk **Base;
struct UnixRup *UnixRupP;
unsigned long flags;
if (Rup >= (unsigned short) (MAX_RUP + LINKS_PER_UNIT)) {
rio_dprintk(RIO_DEBUG_CMD, "Illegal rup number %d in RIOQueueCmdBlk\n", Rup);
RIOFreeCmdBlk(CmdBlkP);
return RIO_FAIL;
}
UnixRupP = &HostP->UnixRups[Rup];
rio_spin_lock_irqsave(&UnixRupP->RupLock, flags);
if ((UnixRupP->CmdsWaitingP == NULL) && (UnixRupP->CmdPendingP == NULL) && (readw(&UnixRupP->RupP->txcontrol) == TX_RUP_INACTIVE) && (CmdBlkP->PreFuncP ? (*CmdBlkP->PreFuncP) (CmdBlkP->PreArg, CmdBlkP)
: 1)) {
rio_dprintk(RIO_DEBUG_CMD, "RUP inactive-placing command straight on. Cmd byte is 0x%x\n", CmdBlkP->Packet.data[0]);
HostP->Copy(&CmdBlkP->Packet, RIO_PTR(HostP->Caddr, readw(&UnixRupP->RupP->txpkt)), sizeof(struct PKT));
UnixRupP->CmdPendingP = CmdBlkP;
writew(TX_PACKET_READY, &UnixRupP->RupP->txcontrol);
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
return 0;
}
rio_dprintk(RIO_DEBUG_CMD, "RUP active - en-queing\n");
if (UnixRupP->CmdsWaitingP != NULL)
rio_dprintk(RIO_DEBUG_CMD, "Rup active - command waiting\n");
if (UnixRupP->CmdPendingP != NULL)
rio_dprintk(RIO_DEBUG_CMD, "Rup active - command pending\n");
if (readw(&UnixRupP->RupP->txcontrol) != TX_RUP_INACTIVE)
rio_dprintk(RIO_DEBUG_CMD, "Rup active - command rup not ready\n");
Base = &UnixRupP->CmdsWaitingP;
rio_dprintk(RIO_DEBUG_CMD, "First try to queue cmdblk %p at %p\n", CmdBlkP, Base);
while (*Base) {
rio_dprintk(RIO_DEBUG_CMD, "Command cmdblk %p here\n", *Base);
Base = &((*Base)->NextP);
rio_dprintk(RIO_DEBUG_CMD, "Now try to queue cmd cmdblk %p at %p\n", CmdBlkP, Base);
}
rio_dprintk(RIO_DEBUG_CMD, "Will queue cmdblk %p at %p\n", CmdBlkP, Base);
*Base = CmdBlkP;
CmdBlkP->NextP = NULL;
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
return 0;
}
void RIOPollHostCommands(struct rio_info *p, struct Host *HostP)
{
struct CmdBlk *CmdBlkP;
struct UnixRup *UnixRupP;
struct PKT __iomem *PacketP;
unsigned short Rup;
unsigned long flags;
Rup = MAX_RUP + LINKS_PER_UNIT;
do {
UnixRupP = &HostP->UnixRups[--Rup];
spin_lock_irqsave(&UnixRupP->RupLock, flags);
if (readw(&UnixRupP->RupP->rxcontrol) != RX_RUP_INACTIVE) {
int FreeMe;
PacketP = (struct PKT __iomem *) RIO_PTR(HostP->Caddr, readw(&UnixRupP->RupP->rxpkt));
switch (readb(&PacketP->dest_port)) {
case BOOT_RUP:
rio_dprintk(RIO_DEBUG_CMD, "Incoming Boot %s packet '%x'\n", readb(&PacketP->len) & 0x80 ? "Command" : "Data", readb(&PacketP->data[0]));
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
FreeMe = RIOBootRup(p, Rup, HostP, PacketP);
rio_spin_lock_irqsave(&UnixRupP->RupLock, flags);
break;
case COMMAND_RUP:
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
FreeMe = RIOCommandRup(p, Rup, HostP, PacketP);
if (readb(&PacketP->data[5]) == RIOC_MEMDUMP) {
rio_dprintk(RIO_DEBUG_CMD, "Memdump from 0x%x complete\n", readw(&(PacketP->data[6])));
rio_memcpy_fromio(p->RIOMemDump, &(PacketP->data[8]), 32);
}
rio_spin_lock_irqsave(&UnixRupP->RupLock, flags);
break;
case ROUTE_RUP:
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
FreeMe = RIORouteRup(p, Rup, HostP, PacketP);
rio_spin_lock_irqsave(&UnixRupP->RupLock, flags);
break;
default:
rio_dprintk(RIO_DEBUG_CMD, "Unknown RUP %d\n", readb(&PacketP->dest_port));
FreeMe = 1;
break;
}
if (FreeMe) {
rio_dprintk(RIO_DEBUG_CMD, "Free processed incoming command packet\n");
put_free_end(HostP, PacketP);
writew(RX_RUP_INACTIVE, &UnixRupP->RupP->rxcontrol);
if (readw(&UnixRupP->RupP->handshake) == PHB_HANDSHAKE_SET) {
rio_dprintk(RIO_DEBUG_CMD, "Handshake rup %d\n", Rup);
writew(PHB_HANDSHAKE_SET | PHB_HANDSHAKE_RESET, &UnixRupP->RupP->handshake);
}
}
}
if ((CmdBlkP = UnixRupP->CmdPendingP) &&
(readw(&UnixRupP->RupP->txcontrol) == TX_RUP_INACTIVE)) {
if (CmdBlkP->Packet.dest_port == BOOT_RUP)
rio_dprintk(RIO_DEBUG_CMD, "Free Boot %s Command Block '%x'\n", CmdBlkP->Packet.len & 0x80 ? "Command" : "Data", CmdBlkP->Packet.data[0]);
rio_dprintk(RIO_DEBUG_CMD, "Command %p completed\n", CmdBlkP);
if (CmdBlkP->PostFuncP) {
rio_spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
(*CmdBlkP->PostFuncP) (CmdBlkP->PostArg, CmdBlkP);
rio_spin_lock_irqsave(&UnixRupP->RupLock, flags);
}
UnixRupP->CmdPendingP = NULL;
RIOFreeCmdBlk(CmdBlkP);
}
if ((CmdBlkP = UnixRupP->CmdsWaitingP) &&
(UnixRupP->CmdPendingP == NULL) && (readw(&UnixRupP->RupP->txcontrol) == TX_RUP_INACTIVE)) {
if (!(CmdBlkP->PreFuncP ? (*CmdBlkP->PreFuncP) (CmdBlkP->PreArg, CmdBlkP) : 1)) {
rio_dprintk(RIO_DEBUG_CMD, "Not ready to start command %p\n", CmdBlkP);
} else {
rio_dprintk(RIO_DEBUG_CMD, "Start new command %p Cmd byte is 0x%x\n", CmdBlkP, CmdBlkP->Packet.data[0]);
HostP->Copy(&CmdBlkP->Packet, RIO_PTR(HostP->Caddr, readw(&UnixRupP->RupP->txpkt)), sizeof(struct PKT));
UnixRupP->CmdsWaitingP = CmdBlkP->NextP;
UnixRupP->CmdPendingP = CmdBlkP;
writew(TX_PACKET_READY, &UnixRupP->RupP->txcontrol);
}
}
spin_unlock_irqrestore(&UnixRupP->RupLock, flags);
} while (Rup);
}
int RIOWFlushMark(unsigned long iPortP, struct CmdBlk *CmdBlkP)
{
struct Port *PortP = (struct Port *) iPortP;
unsigned long flags;
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->WflushFlag++;
PortP->MagicFlags |= MAGIC_FLUSH;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return RIOUnUse(iPortP, CmdBlkP);
}
int RIORFlushEnable(unsigned long iPortP, struct CmdBlk *CmdBlkP)
{
struct Port *PortP = (struct Port *) iPortP;
struct PKT __iomem *PacketP;
unsigned long flags;
rio_spin_lock_irqsave(&PortP->portSem, flags);
while (can_remove_receive(&PacketP, PortP)) {
remove_receive(PortP);
put_free_end(PortP->HostP, PacketP);
}
if (readw(&PortP->PhbP->handshake) == PHB_HANDSHAKE_SET) {
rio_dprintk(RIO_DEBUG_CMD, "Util: Set RX handshake bit\n");
writew(PHB_HANDSHAKE_SET | PHB_HANDSHAKE_RESET, &PortP->PhbP->handshake);
}
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return RIOUnUse(iPortP, CmdBlkP);
}
int RIOUnUse(unsigned long iPortP, struct CmdBlk *CmdBlkP)
{
struct Port *PortP = (struct Port *) iPortP;
unsigned long flags;
rio_spin_lock_irqsave(&PortP->portSem, flags);
rio_dprintk(RIO_DEBUG_CMD, "Decrement in use count for port\n");
if (PortP->InUse) {
if (--PortP->InUse != NOT_INUSE) {
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return 0;
}
}
writew(1, &PortP->HostP->ParmMapP->tx_intr);
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
return 0;
}
