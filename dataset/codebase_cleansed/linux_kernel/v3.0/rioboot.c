int RIOBootCodeRTA(struct rio_info *p, struct DownLoad * rbp)
{
int offset;
func_enter();
rio_dprintk(RIO_DEBUG_BOOT, "Data at user address %p\n", rbp->DataP);
if (rbp->Count > SIXTY_FOUR_K) {
rio_dprintk(RIO_DEBUG_BOOT, "RTA Boot Code Too Large!\n");
p->RIOError.Error = HOST_FILE_TOO_LARGE;
func_exit();
return -ENOMEM;
}
if (p->RIOBooting) {
rio_dprintk(RIO_DEBUG_BOOT, "RTA Boot Code : BUSY BUSY BUSY!\n");
p->RIOError.Error = BOOT_IN_PROGRESS;
func_exit();
return -EBUSY;
}
offset = (RTA_BOOT_DATA_SIZE - (rbp->Count % RTA_BOOT_DATA_SIZE)) % RTA_BOOT_DATA_SIZE;
memset(p->RIOBootPackets, 0, offset);
if (copy_from_user(((u8 *)p->RIOBootPackets) + offset, rbp->DataP, rbp->Count)) {
rio_dprintk(RIO_DEBUG_BOOT, "Bad data copy from user space\n");
p->RIOError.Error = COPYIN_FAILED;
func_exit();
return -EFAULT;
}
p->RIONumBootPkts = (rbp->Count + offset) / RTA_BOOT_DATA_SIZE;
p->RIOBootCount = rbp->Count;
func_exit();
return 0;
}
void rio_start_card_running(struct Host *HostP)
{
switch (HostP->Type) {
case RIO_AT:
rio_dprintk(RIO_DEBUG_BOOT, "Start ISA card running\n");
writeb(BOOT_FROM_RAM | EXTERNAL_BUS_ON | HostP->Mode | RIOAtVec2Ctrl[HostP->Ivec & 0xF], &HostP->Control);
break;
case RIO_PCI:
rio_dprintk(RIO_DEBUG_BOOT, "Start PCI card running\n");
writeb(PCITpBootFromRam | PCITpBusEnable | HostP->Mode, &HostP->Control);
break;
default:
rio_dprintk(RIO_DEBUG_BOOT, "Unknown host type %d\n", HostP->Type);
break;
}
return;
}
int RIOBootCodeHOST(struct rio_info *p, struct DownLoad *rbp)
{
struct Host *HostP;
u8 __iomem *Cad;
PARM_MAP __iomem *ParmMapP;
int RupN;
int PortN;
unsigned int host;
u8 __iomem *StartP;
u8 __iomem *DestP;
int wait_count;
u16 OldParmMap;
u16 offset;
u8 *DownCode = NULL;
unsigned long flags;
HostP = NULL;
for (host = 0; host < p->RIONumHosts; host++) {
rio_dprintk(RIO_DEBUG_BOOT, "Attempt to boot host %d\n", host);
HostP = &p->RIOHosts[host];
rio_dprintk(RIO_DEBUG_BOOT, "Host Type = 0x%x, Mode = 0x%x, IVec = 0x%x\n", HostP->Type, HostP->Mode, HostP->Ivec);
if ((HostP->Flags & RUN_STATE) != RC_WAITING) {
rio_dprintk(RIO_DEBUG_BOOT, "%s %d already running\n", "Host", host);
continue;
}
Cad = HostP->Caddr;
StartP = &Cad[p->RIOConf.HostLoadBase - rbp->Count];
rio_dprintk(RIO_DEBUG_BOOT, "kernel virtual address for host is %p\n", Cad);
rio_dprintk(RIO_DEBUG_BOOT, "kernel virtual address for download is %p\n", StartP);
rio_dprintk(RIO_DEBUG_BOOT, "host loadbase is 0x%x\n", p->RIOConf.HostLoadBase);
rio_dprintk(RIO_DEBUG_BOOT, "size of download is 0x%x\n", rbp->Count);
if (p->RIOConf.HostLoadBase < rbp->Count) {
rio_dprintk(RIO_DEBUG_BOOT, "Bin too large\n");
p->RIOError.Error = HOST_FILE_TOO_LARGE;
func_exit();
return -EFBIG;
}
RIOHostReset(HostP->Type, HostP->CardP, HostP->Slot);
rio_dprintk(RIO_DEBUG_BOOT, "Copy in code\n");
DownCode = vmalloc(rbp->Count);
if (!DownCode) {
p->RIOError.Error = NOT_ENOUGH_CORE_FOR_PCI_COPY;
func_exit();
return -ENOMEM;
}
if (copy_from_user(DownCode, rbp->DataP, rbp->Count)) {
kfree(DownCode);
p->RIOError.Error = COPYIN_FAILED;
func_exit();
return -EFAULT;
}
HostP->Copy(DownCode, StartP, rbp->Count);
vfree(DownCode);
rio_dprintk(RIO_DEBUG_BOOT, "Copy completed\n");
DestP = &Cad[0x7FF8];
#define NFIX(N) (0x60 | (N))
#define PFIX(N) (0x20 | (N))
#define JUMP(N) (0x00 | (N))
offset = (p->RIOConf.HostLoadBase - 2) - 0x7FFC;
writeb(NFIX(((unsigned short) (~offset) >> (unsigned short) 12) & 0xF), DestP);
writeb(PFIX((offset >> 8) & 0xF), DestP + 1);
writeb(PFIX((offset >> 4) & 0xF), DestP + 2);
writeb(JUMP(offset & 0xF), DestP + 3);
writeb(NFIX(0), DestP + 6);
writeb(JUMP(8), DestP + 7);
rio_dprintk(RIO_DEBUG_BOOT, "host loadbase is 0x%x\n", p->RIOConf.HostLoadBase);
rio_dprintk(RIO_DEBUG_BOOT, "startup offset is 0x%x\n", offset);
HostP->Flags &= ~RUN_STATE;
HostP->Flags |= RC_STARTUP;
OldParmMap = readw(&HostP->__ParmMapR);
rio_dprintk(RIO_DEBUG_BOOT, "Original parmmap is 0x%x\n", OldParmMap);
rio_dprintk(RIO_DEBUG_BOOT, "Host Type = 0x%x, Mode = 0x%x, IVec = 0x%x\n", HostP->Type, HostP->Mode, HostP->Ivec);
rio_start_card_running(HostP);
rio_dprintk(RIO_DEBUG_BOOT, "Set control port\n");
for (wait_count = 0; (wait_count < p->RIOConf.StartupTime) && (readw(&HostP->__ParmMapR) == OldParmMap); wait_count++) {
rio_dprintk(RIO_DEBUG_BOOT, "Checkout %d, 0x%x\n", wait_count, readw(&HostP->__ParmMapR));
mdelay(100);
}
if (readw(&HostP->__ParmMapR) == OldParmMap) {
rio_dprintk(RIO_DEBUG_BOOT, "parmmap 0x%x\n", readw(&HostP->__ParmMapR));
rio_dprintk(RIO_DEBUG_BOOT, "RIO Mesg Run Fail\n");
HostP->Flags &= ~RUN_STATE;
HostP->Flags |= RC_STUFFED;
RIOHostReset( HostP->Type, HostP->CardP, HostP->Slot );
continue;
}
rio_dprintk(RIO_DEBUG_BOOT, "Running 0x%x\n", readw(&HostP->__ParmMapR));
ParmMapP = (PARM_MAP __iomem *) RIO_PTR(Cad, readw(&HostP->__ParmMapR));
rio_dprintk(RIO_DEBUG_BOOT, "ParmMapP : %p\n", ParmMapP);
ParmMapP = (PARM_MAP __iomem *)(Cad + readw(&HostP->__ParmMapR));
rio_dprintk(RIO_DEBUG_BOOT, "ParmMapP : %p\n", ParmMapP);
if (readw(&ParmMapP->links) != 0xFFFF) {
rio_dprintk(RIO_DEBUG_BOOT, "RIO Mesg Run Fail %s\n", HostP->Name);
rio_dprintk(RIO_DEBUG_BOOT, "Links = 0x%x\n", readw(&ParmMapP->links));
HostP->Flags &= ~RUN_STATE;
HostP->Flags |= RC_STUFFED;
RIOHostReset( HostP->Type, HostP->CardP, HostP->Slot );
continue;
}
writew(RIO_LINK_ENABLE, &ParmMapP->links);
rio_dprintk(RIO_DEBUG_BOOT, "Looking for init_done - %d ticks\n", p->RIOConf.StartupTime);
HostP->timeout_id = 0;
for (wait_count = 0; (wait_count < p->RIOConf.StartupTime) && !readw(&ParmMapP->init_done); wait_count++) {
rio_dprintk(RIO_DEBUG_BOOT, "Waiting for init_done\n");
mdelay(100);
}
rio_dprintk(RIO_DEBUG_BOOT, "OK! init_done!\n");
if (readw(&ParmMapP->error) != E_NO_ERROR || !readw(&ParmMapP->init_done)) {
rio_dprintk(RIO_DEBUG_BOOT, "RIO Mesg Run Fail %s\n", HostP->Name);
rio_dprintk(RIO_DEBUG_BOOT, "Timedout waiting for init_done\n");
HostP->Flags &= ~RUN_STATE;
HostP->Flags |= RC_STUFFED;
RIOHostReset( HostP->Type, HostP->CardP, HostP->Slot );
continue;
}
rio_dprintk(RIO_DEBUG_BOOT, "Got init_done\n");
rio_dprintk(RIO_DEBUG_BOOT, "Host ID %x Running\n", HostP->UniqueNum);
writew(p->RIOConf.Timer, &ParmMapP->timer);
HostP->ParmMapP = ParmMapP;
HostP->PhbP = (struct PHB __iomem *) RIO_PTR(Cad, readw(&ParmMapP->phb_ptr));
HostP->RupP = (struct RUP __iomem *) RIO_PTR(Cad, readw(&ParmMapP->rups));
HostP->PhbNumP = (unsigned short __iomem *) RIO_PTR(Cad, readw(&ParmMapP->phb_num_ptr));
HostP->LinkStrP = (struct LPB __iomem *) RIO_PTR(Cad, readw(&ParmMapP->link_str_ptr));
for (RupN = 0; RupN < MAX_RUP; RupN++) {
HostP->UnixRups[RupN].RupP = &HostP->RupP[RupN];
HostP->UnixRups[RupN].Id = RupN + 1;
HostP->UnixRups[RupN].BaseSysPort = NO_PORT;
spin_lock_init(&HostP->UnixRups[RupN].RupLock);
}
for (RupN = 0; RupN < LINKS_PER_UNIT; RupN++) {
HostP->UnixRups[RupN + MAX_RUP].RupP = &HostP->LinkStrP[RupN].rup;
HostP->UnixRups[RupN + MAX_RUP].Id = 0;
HostP->UnixRups[RupN + MAX_RUP].BaseSysPort = NO_PORT;
spin_lock_init(&HostP->UnixRups[RupN + MAX_RUP].RupLock);
}
for (PortN = p->RIOFirstPortsMapped; PortN < p->RIOLastPortsMapped + PORTS_PER_RTA; PortN++) {
if (p->RIOPortp[PortN]->HostP == HostP) {
struct Port *PortP = p->RIOPortp[PortN];
struct PHB __iomem *PhbP;
if (!PortP->Mapped)
continue;
PhbP = &HostP->PhbP[PortP->HostPort];
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->PhbP = PhbP;
PortP->TxAdd = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->tx_add));
PortP->TxStart = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->tx_start));
PortP->TxEnd = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->tx_end));
PortP->RxRemove = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->rx_remove));
PortP->RxStart = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->rx_start));
PortP->RxEnd = (u16 __iomem *) RIO_PTR(Cad, readw(&PhbP->rx_end));
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
if (!(PortN % PORTS_PER_RTA))
HostP->UnixRups[PortP->RupNum].BaseSysPort = PortN;
}
}
rio_dprintk(RIO_DEBUG_BOOT, "Set the card running... \n");
HostP->Flags &= ~RUN_STATE;
HostP->Flags |= RC_RUNNING;
}
p->RIOPolling = 1;
p->RIOSystemUp++;
rio_dprintk(RIO_DEBUG_BOOT, "Done everything %x\n", HostP->Ivec);
func_exit();
return 0;
}
int RIOBootRup(struct rio_info *p, unsigned int Rup, struct Host *HostP, struct PKT __iomem *PacketP)
{
struct PktCmd __iomem *PktCmdP = (struct PktCmd __iomem *) PacketP->data;
struct PktCmd_M *PktReplyP;
struct CmdBlk *CmdBlkP;
unsigned int sequence;
if (p->RIONumBootPkts == 0) {
rio_dprintk(RIO_DEBUG_BOOT, "No RTA code to download yet\n");
return 0;
}
if ((readb(&PacketP->len) & PKT_CMD_BIT) && (readb(&PktCmdP->Command) == BOOT_COMPLETED))
return RIOBootComplete(p, HostP, Rup, PktCmdP);
if (!(CmdBlkP = RIOGetCmdBlk())) {
rio_dprintk(RIO_DEBUG_BOOT, "No command blocks to boot RTA! come back later.\n");
return 0;
}
CmdBlkP->Packet.dest_unit = Rup < (unsigned short) MAX_RUP ? Rup : 0;
CmdBlkP->Packet.dest_port = BOOT_RUP;
CmdBlkP->Packet.src_unit = 0;
CmdBlkP->Packet.src_port = BOOT_RUP;
CmdBlkP->PreFuncP = CmdBlkP->PostFuncP = NULL;
PktReplyP = (struct PktCmd_M *) CmdBlkP->Packet.data;
if (readb(&PacketP->len) & PKT_CMD_BIT) {
if (readb(&PktCmdP->Command) != BOOT_REQUEST) {
rio_dprintk(RIO_DEBUG_BOOT, "Unexpected command %d on BOOT RUP %d of host %Zd\n", readb(&PktCmdP->Command), Rup, HostP - p->RIOHosts);
RIOFreeCmdBlk(CmdBlkP);
return 1;
}
PktReplyP->Command = BOOT_SEQUENCE;
PktReplyP->BootSequence.NumPackets = p->RIONumBootPkts;
PktReplyP->BootSequence.LoadBase = p->RIOConf.RtaLoadBase;
PktReplyP->BootSequence.CodeSize = p->RIOBootCount;
CmdBlkP->Packet.len = BOOT_SEQUENCE_LEN | PKT_CMD_BIT;
memcpy((void *) &CmdBlkP->Packet.data[BOOT_SEQUENCE_LEN], "BOOT", 4);
rio_dprintk(RIO_DEBUG_BOOT, "Boot RTA on Host %Zd Rup %d - %d (0x%x) packets to 0x%x\n", HostP - p->RIOHosts, Rup, p->RIONumBootPkts, p->RIONumBootPkts, p->RIOConf.RtaLoadBase);
p->RIOBooting++;
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
return 1;
}
sequence = readw(&PktCmdP->Sequence);
rio_dprintk(RIO_DEBUG_BOOT, "Boot block %d on Host %Zd Rup%d\n", sequence, HostP - p->RIOHosts, Rup);
if (sequence >= p->RIONumBootPkts) {
rio_dprintk(RIO_DEBUG_BOOT, "Got a request for packet %d, max is %d\n", sequence, p->RIONumBootPkts);
}
PktReplyP->Sequence = sequence;
memcpy(PktReplyP->BootData, p->RIOBootPackets[p->RIONumBootPkts - sequence - 1], RTA_BOOT_DATA_SIZE);
CmdBlkP->Packet.len = PKT_MAX_DATA_LEN;
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
return 1;
}
static int RIOBootComplete(struct rio_info *p, struct Host *HostP, unsigned int Rup, struct PktCmd __iomem *PktCmdP)
{
struct Map *MapP = NULL;
struct Map *MapP2 = NULL;
int Flag;
int found;
int host, rta;
int EmptySlot = -1;
int entry, entry2;
char *MyType, *MyName;
unsigned int MyLink;
unsigned short RtaType;
u32 RtaUniq = (readb(&PktCmdP->UniqNum[0])) + (readb(&PktCmdP->UniqNum[1]) << 8) + (readb(&PktCmdP->UniqNum[2]) << 16) + (readb(&PktCmdP->UniqNum[3]) << 24);
p->RIOBooting = 0;
rio_dprintk(RIO_DEBUG_BOOT, "RTA Boot completed - BootInProgress now %d\n", p->RIOBooting);
RtaType = GetUnitType(RtaUniq);
if (Rup >= (unsigned short) MAX_RUP)
rio_dprintk(RIO_DEBUG_BOOT, "RIO: Host %s has booted an RTA(%d) on link %c\n", HostP->Name, 8 * RtaType, readb(&PktCmdP->LinkNum) + 'A');
else
rio_dprintk(RIO_DEBUG_BOOT, "RIO: RTA %s has booted an RTA(%d) on link %c\n", HostP->Mapping[Rup].Name, 8 * RtaType, readb(&PktCmdP->LinkNum) + 'A');
rio_dprintk(RIO_DEBUG_BOOT, "UniqNum is 0x%x\n", RtaUniq);
if (RtaUniq == 0x00000000 || RtaUniq == 0xffffffff) {
rio_dprintk(RIO_DEBUG_BOOT, "Illegal RTA Uniq Number\n");
return 1;
}
if (!RIOBootOk(p, HostP, RtaUniq)) {
MyLink = readb(&PktCmdP->LinkNum);
if (Rup < (unsigned short) MAX_RUP) {
if (RIOSuspendBootRta(HostP, HostP->Mapping[Rup].ID, MyLink)) {
rio_dprintk(RIO_DEBUG_BOOT, "RTA failed to suspend booting on link %c\n", 'A' + MyLink);
}
} else
writew(30, &HostP->LinkStrP[MyLink].WaitNoBoot);
rio_dprintk(RIO_DEBUG_BOOT, "RTA %x not owned - suspend booting down link %c on unit %x\n", RtaUniq, 'A' + MyLink, HostP->Mapping[Rup].RtaUniqueNum);
return 1;
}
for (entry = 0; entry < MAX_RUP; entry++) {
unsigned int sysport;
if ((HostP->Mapping[entry].Flags & SLOT_IN_USE) && (HostP->Mapping[entry].RtaUniqueNum == RtaUniq)) {
HostP->Mapping[entry].Flags |= RTA_BOOTED | RTA_NEWBOOT;
if ((sysport = HostP->Mapping[entry].SysPort) != NO_PORT) {
if (sysport < p->RIOFirstPortsBooted)
p->RIOFirstPortsBooted = sysport;
if (sysport > p->RIOLastPortsBooted)
p->RIOLastPortsBooted = sysport;
if (RtaType == TYPE_RTA16) {
entry2 = HostP->Mapping[entry].ID2 - 1;
HostP->Mapping[entry2].Flags |= RTA_BOOTED | RTA_NEWBOOT;
sysport = HostP->Mapping[entry2].SysPort;
if (sysport < p->RIOFirstPortsBooted)
p->RIOFirstPortsBooted = sysport;
if (sysport > p->RIOLastPortsBooted)
p->RIOLastPortsBooted = sysport;
}
}
if (RtaType == TYPE_RTA16)
rio_dprintk(RIO_DEBUG_BOOT, "RTA will be given IDs %d+%d\n", entry + 1, entry2 + 1);
else
rio_dprintk(RIO_DEBUG_BOOT, "RTA will be given ID %d\n", entry + 1);
return 1;
}
}
rio_dprintk(RIO_DEBUG_BOOT, "RTA not configured for this host\n");
if (Rup >= (unsigned short) MAX_RUP) {
MyType = "Host";
MyName = HostP->Name;
} else {
MyType = "RTA";
MyName = HostP->Mapping[Rup].Name;
}
MyLink = readb(&PktCmdP->LinkNum);
for (entry = 0; entry < MAX_RUP; entry++) {
if ((HostP->Mapping[entry].Flags & SLOT_TENTATIVE) && (HostP->Mapping[entry].RtaUniqueNum == RtaUniq)) {
if (RtaType == TYPE_RTA16) {
entry2 = HostP->Mapping[entry].ID2 - 1;
if ((HostP->Mapping[entry2].Flags & SLOT_TENTATIVE) && (HostP->Mapping[entry2].RtaUniqueNum == RtaUniq))
rio_dprintk(RIO_DEBUG_BOOT, "Found previous tentative slots (%d+%d)\n", entry, entry2);
else
continue;
} else
rio_dprintk(RIO_DEBUG_BOOT, "Found previous tentative slot (%d)\n", entry);
if (!p->RIONoMessage)
printk("RTA connected to %s '%s' (%c) not configured.\n", MyType, MyName, MyLink + 'A');
return 1;
}
}
rio_dprintk(RIO_DEBUG_BOOT, "Have we seen RTA %x before?\n", RtaUniq);
found = 0;
Flag = 0;
for (host = 0; !found && (host < p->RIONumHosts); host++) {
for (rta = 0; rta < MAX_RUP; rta++) {
if ((p->RIOHosts[host].Mapping[rta].Flags & (SLOT_IN_USE | SLOT_TENTATIVE)) && (p->RIOHosts[host].Mapping[rta].RtaUniqueNum == RtaUniq)) {
Flag = p->RIOHosts[host].Mapping[rta].Flags;
MapP = &p->RIOHosts[host].Mapping[rta];
if (RtaType == TYPE_RTA16) {
MapP2 = &p->RIOHosts[host].Mapping[MapP->ID2 - 1];
rio_dprintk(RIO_DEBUG_BOOT, "This RTA is units %d+%d from host %s\n", rta + 1, MapP->ID2, p->RIOHosts[host].Name);
} else
rio_dprintk(RIO_DEBUG_BOOT, "This RTA is unit %d from host %s\n", rta + 1, p->RIOHosts[host].Name);
found = 1;
break;
}
}
}
if (!MapP) {
rio_dprintk(RIO_DEBUG_BOOT, "Look for RTA %x in RIOSavedTable\n", RtaUniq);
for (rta = 0; rta < TOTAL_MAP_ENTRIES; rta++) {
rio_dprintk(RIO_DEBUG_BOOT, "Check table entry %d (%x)", rta, p->RIOSavedTable[rta].RtaUniqueNum);
if ((p->RIOSavedTable[rta].Flags & SLOT_IN_USE) && (p->RIOSavedTable[rta].RtaUniqueNum == RtaUniq)) {
MapP = &p->RIOSavedTable[rta];
Flag = p->RIOSavedTable[rta].Flags;
if (RtaType == TYPE_RTA16) {
for (entry2 = rta + 1; entry2 < TOTAL_MAP_ENTRIES; entry2++) {
if (p->RIOSavedTable[entry2].RtaUniqueNum == RtaUniq)
break;
}
MapP2 = &p->RIOSavedTable[entry2];
rio_dprintk(RIO_DEBUG_BOOT, "This RTA is from table entries %d+%d\n", rta, entry2);
} else
rio_dprintk(RIO_DEBUG_BOOT, "This RTA is from table entry %d\n", rta);
break;
}
}
}
EmptySlot = 1;
if (RtaType == TYPE_RTA16) {
if (RIOFindFreeID(p, HostP, &entry, &entry2) == 0) {
RIODefaultName(p, HostP, entry);
rio_fill_host_slot(entry, entry2, RtaUniq, HostP);
EmptySlot = 0;
}
} else {
if (RIOFindFreeID(p, HostP, &entry, NULL) == 0) {
RIODefaultName(p, HostP, entry);
rio_fill_host_slot(entry, 0, RtaUniq, HostP);
EmptySlot = 0;
}
}
if (EmptySlot == 0) {
if (MapP) {
if (Flag & SLOT_IN_USE) {
rio_dprintk(RIO_DEBUG_BOOT, "This RTA configured on another host - move entry to current host (1)\n");
HostP->Mapping[entry].SysPort = MapP->SysPort;
memcpy(HostP->Mapping[entry].Name, MapP->Name, MAX_NAME_LEN);
HostP->Mapping[entry].Flags = SLOT_IN_USE | RTA_BOOTED | RTA_NEWBOOT;
RIOReMapPorts(p, HostP, &HostP->Mapping[entry]);
if (HostP->Mapping[entry].SysPort < p->RIOFirstPortsBooted)
p->RIOFirstPortsBooted = HostP->Mapping[entry].SysPort;
if (HostP->Mapping[entry].SysPort > p->RIOLastPortsBooted)
p->RIOLastPortsBooted = HostP->Mapping[entry].SysPort;
rio_dprintk(RIO_DEBUG_BOOT, "SysPort %d, Name %s\n", (int) MapP->SysPort, MapP->Name);
} else {
rio_dprintk(RIO_DEBUG_BOOT, "This RTA has a tentative entry on another host - delete that entry (1)\n");
HostP->Mapping[entry].Flags = SLOT_TENTATIVE | RTA_BOOTED | RTA_NEWBOOT;
}
if (RtaType == TYPE_RTA16) {
if (Flag & SLOT_IN_USE) {
HostP->Mapping[entry2].Flags = SLOT_IN_USE | RTA_BOOTED | RTA_NEWBOOT | RTA16_SECOND_SLOT;
HostP->Mapping[entry2].SysPort = MapP2->SysPort;
RIOReMapPorts(p, HostP, &HostP->Mapping[entry2]);
if (HostP->Mapping[entry2].SysPort < p->RIOFirstPortsBooted)
p->RIOFirstPortsBooted = HostP->Mapping[entry2].SysPort;
if (HostP->Mapping[entry2].SysPort > p->RIOLastPortsBooted)
p->RIOLastPortsBooted = HostP->Mapping[entry2].SysPort;
rio_dprintk(RIO_DEBUG_BOOT, "SysPort %d, Name %s\n", (int) HostP->Mapping[entry2].SysPort, HostP->Mapping[entry].Name);
} else
HostP->Mapping[entry2].Flags = SLOT_TENTATIVE | RTA_BOOTED | RTA_NEWBOOT | RTA16_SECOND_SLOT;
memset(MapP2, 0, sizeof(struct Map));
}
memset(MapP, 0, sizeof(struct Map));
if (!p->RIONoMessage)
printk("An orphaned RTA has been adopted by %s '%s' (%c).\n", MyType, MyName, MyLink + 'A');
} else if (!p->RIONoMessage)
printk("RTA connected to %s '%s' (%c) not configured.\n", MyType, MyName, MyLink + 'A');
RIOSetChange(p);
return 1;
}
if (!p->RIONoMessage)
printk("The RTA connected to %s '%s' (%c) cannot be configured. You cannot configure more than 128 ports to one host card.\n", MyType, MyName, MyLink + 'A');
for (entry = 0; entry < HostP->NumExtraBooted; entry++) {
if (HostP->ExtraUnits[entry] == RtaUniq) {
return 1;
}
}
if (HostP->NumExtraBooted < MAX_EXTRA_UNITS)
HostP->ExtraUnits[HostP->NumExtraBooted++] = RtaUniq;
return 1;
}
int RIOBootOk(struct rio_info *p, struct Host *HostP, unsigned long RtaUniq)
{
int Entry;
unsigned int HostUniq = HostP->UniqueNum;
for (Entry = 0; (Entry < MAX_RTA_BINDINGS) && (p->RIOBindTab[Entry] != 0); Entry++) {
if ((p->RIOBindTab[Entry] == HostUniq) || (p->RIOBindTab[Entry] == RtaUniq))
return 0;
}
return 1;
}
void rio_fill_host_slot(int entry, int entry2, unsigned int rta_uniq, struct Host *host)
{
int link;
rio_dprintk(RIO_DEBUG_BOOT, "rio_fill_host_slot(%d, %d, 0x%x...)\n", entry, entry2, rta_uniq);
host->Mapping[entry].Flags = (RTA_BOOTED | RTA_NEWBOOT | SLOT_TENTATIVE);
host->Mapping[entry].SysPort = NO_PORT;
host->Mapping[entry].RtaUniqueNum = rta_uniq;
host->Mapping[entry].HostUniqueNum = host->UniqueNum;
host->Mapping[entry].ID = entry + 1;
host->Mapping[entry].ID2 = 0;
if (entry2) {
host->Mapping[entry2].Flags = (RTA_BOOTED | RTA_NEWBOOT | SLOT_TENTATIVE | RTA16_SECOND_SLOT);
host->Mapping[entry2].SysPort = NO_PORT;
host->Mapping[entry2].RtaUniqueNum = rta_uniq;
host->Mapping[entry2].HostUniqueNum = host->UniqueNum;
host->Mapping[entry2].Name[0] = '\0';
host->Mapping[entry2].ID = entry2 + 1;
host->Mapping[entry2].ID2 = entry + 1;
host->Mapping[entry].ID2 = entry2 + 1;
}
for (link = 0; link < LINKS_PER_UNIT; link++) {
host->Mapping[entry].Topology[link].Unit = ROUTE_DISCONNECT;
host->Mapping[entry].Topology[link].Link = NO_LINK;
if (entry2) {
host->Mapping[entry2].Topology[link].Unit = ROUTE_DISCONNECT;
host->Mapping[entry2].Topology[link].Link = NO_LINK;
}
}
}
