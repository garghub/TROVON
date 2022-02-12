int RIORouteRup(struct rio_info *p, unsigned int Rup, struct Host *HostP, struct PKT __iomem * PacketP)
{
struct PktCmd __iomem *PktCmdP = (struct PktCmd __iomem *) PacketP->data;
struct PktCmd_M *PktReplyP;
struct CmdBlk *CmdBlkP;
struct Port *PortP;
struct Map *MapP;
struct Top *TopP;
int ThisLink, ThisLinkMin, ThisLinkMax;
int port;
int Mod, Mod1, Mod2;
unsigned short RtaType;
unsigned int RtaUniq;
unsigned int ThisUnit, ThisUnit2;
unsigned int OldUnit, NewUnit, OldLink, NewLink;
char *MyType, *MyName;
int Lies;
unsigned long flags;
if (readb(&PktCmdP->Command) == ROUTE_TOPOLOGY) {
MapP = HostP->Mapping;
if (Rup >= (unsigned short) MAX_RUP) {
ThisUnit = HOST_ID;
TopP = HostP->Topology;
MyType = "Host";
MyName = HostP->Name;
ThisLinkMin = ThisLinkMax = Rup - MAX_RUP;
} else {
ThisUnit = Rup + 1;
TopP = HostP->Mapping[Rup].Topology;
MyType = "RTA";
MyName = HostP->Mapping[Rup].Name;
ThisLinkMin = 0;
ThisLinkMax = LINKS_PER_UNIT - 1;
}
Lies = 0;
for (ThisLink = ThisLinkMin + 1; ThisLink <= ThisLinkMax; ThisLink++) {
if (readb(&PktCmdP->RouteTopology[ThisLink].Unit) > (unsigned short) MAX_RUP)
continue;
for (NewLink = ThisLinkMin; NewLink < ThisLink; NewLink++) {
if ((readb(&PktCmdP->RouteTopology[ThisLink].Unit) == readb(&PktCmdP->RouteTopology[NewLink].Unit)) && (readb(&PktCmdP->RouteTopology[ThisLink].Link) == readb(&PktCmdP->RouteTopology[NewLink].Link))) {
Lies++;
}
}
}
if (Lies) {
rio_dprintk(RIO_DEBUG_ROUTE, "LIES! DAMN LIES! %d LIES!\n", Lies);
rio_dprintk(RIO_DEBUG_ROUTE, "%d:%c %d:%c %d:%c %d:%c\n",
readb(&PktCmdP->RouteTopology[0].Unit),
'A' + readb(&PktCmdP->RouteTopology[0].Link),
readb(&PktCmdP->RouteTopology[1].Unit),
'A' + readb(&PktCmdP->RouteTopology[1].Link), readb(&PktCmdP->RouteTopology[2].Unit), 'A' + readb(&PktCmdP->RouteTopology[2].Link), readb(&PktCmdP->RouteTopology[3].Unit), 'A' + readb(&PktCmdP->RouteTopology[3].Link));
return 1;
}
for (ThisLink = ThisLinkMin; ThisLink <= ThisLinkMax; ThisLink++) {
OldUnit = TopP[ThisLink].Unit;
OldLink = TopP[ThisLink].Link;
NewUnit = readb(&PktCmdP->RouteTopology[ThisLink].Unit);
NewLink = readb(&PktCmdP->RouteTopology[ThisLink].Link);
if (OldUnit != NewUnit || OldLink != NewLink) {
if (NewUnit > MAX_RUP && NewUnit != ROUTE_DISCONNECT && NewUnit != ROUTE_NO_ID && NewUnit != ROUTE_INTERCONNECT) {
rio_dprintk(RIO_DEBUG_ROUTE, "I have a link from %s %s to unit %d:%d - I don't like it.\n", MyType, MyName, NewUnit, NewLink);
} else {
TopP[ThisLink].Unit = NewUnit;
TopP[ThisLink].Link = NewLink;
RIOSetChange(p);
if (OldUnit <= MAX_RUP) {
if (!p->RIONoMessage)
RIOConCon(p, HostP, ThisUnit, ThisLink, OldUnit, OldLink, DISCONNECT);
}
if ((NewUnit <= MAX_RUP) && !p->RIONoMessage)
RIOConCon(p, HostP, ThisUnit, ThisLink, NewUnit, NewLink, CONNECT);
if (NewUnit == ROUTE_NO_ID)
rio_dprintk(RIO_DEBUG_ROUTE, "%s %s (%c) is connected to an unconfigured unit.\n", MyType, MyName, 'A' + ThisLink);
if (NewUnit == ROUTE_INTERCONNECT) {
if (!p->RIONoMessage)
printk(KERN_DEBUG "rio: %s '%s' (%c) is connected to another network.\n", MyType, MyName, 'A' + ThisLink);
}
if (OldUnit == HOST_ID) {
if (HostP->Topology[OldLink].Unit == ThisUnit && HostP->Topology[OldLink].Link == ThisLink) {
rio_dprintk(RIO_DEBUG_ROUTE, "SETTING HOST (%c) TO DISCONNECTED!\n", OldLink + 'A');
HostP->Topology[OldLink].Unit = ROUTE_DISCONNECT;
HostP->Topology[OldLink].Link = NO_LINK;
} else {
rio_dprintk(RIO_DEBUG_ROUTE, "HOST(%c) WAS NOT CONNECTED TO %s (%c)!\n", OldLink + 'A', HostP->Mapping[ThisUnit - 1].Name, ThisLink + 'A');
}
} else if (OldUnit <= MAX_RUP) {
if (HostP->Mapping[OldUnit - 1].Topology[OldLink].Unit == ThisUnit && HostP->Mapping[OldUnit - 1].Topology[OldLink].Link == ThisLink) {
rio_dprintk(RIO_DEBUG_ROUTE, "SETTING RTA %s (%c) TO DISCONNECTED!\n", HostP->Mapping[OldUnit - 1].Name, OldLink + 'A');
HostP->Mapping[OldUnit - 1].Topology[OldLink].Unit = ROUTE_DISCONNECT;
HostP->Mapping[OldUnit - 1].Topology[OldLink].Link = NO_LINK;
} else {
rio_dprintk(RIO_DEBUG_ROUTE, "RTA %s (%c) WAS NOT CONNECTED TO %s (%c)\n", HostP->Mapping[OldUnit - 1].Name, OldLink + 'A', HostP->Mapping[ThisUnit - 1].Name, ThisLink + 'A');
}
}
if (NewUnit == HOST_ID) {
rio_dprintk(RIO_DEBUG_ROUTE, "MARKING HOST (%c) CONNECTED TO %s (%c)\n", NewLink + 'A', MyName, ThisLink + 'A');
HostP->Topology[NewLink].Unit = ThisUnit;
HostP->Topology[NewLink].Link = ThisLink;
} else if (NewUnit <= MAX_RUP) {
rio_dprintk(RIO_DEBUG_ROUTE, "MARKING RTA %s (%c) CONNECTED TO %s (%c)\n", HostP->Mapping[NewUnit - 1].Name, NewLink + 'A', MyName, ThisLink + 'A');
HostP->Mapping[NewUnit - 1].Topology[NewLink].Unit = ThisUnit;
HostP->Mapping[NewUnit - 1].Topology[NewLink].Link = ThisLink;
}
}
RIOSetChange(p);
RIOCheckIsolated(p, HostP, OldUnit);
}
}
return 1;
}
if (readb(&PktCmdP->Command) != ROUTE_REQUEST) {
rio_dprintk(RIO_DEBUG_ROUTE, "Unknown command %d received on rup %d host %p ROUTE_RUP\n", readb(&PktCmdP->Command), Rup, HostP);
return 1;
}
RtaUniq = (readb(&PktCmdP->UniqNum[0])) + (readb(&PktCmdP->UniqNum[1]) << 8) + (readb(&PktCmdP->UniqNum[2]) << 16) + (readb(&PktCmdP->UniqNum[3]) << 24);
RtaType = GetUnitType(RtaUniq);
rio_dprintk(RIO_DEBUG_ROUTE, "Received a request for an ID for serial number %x\n", RtaUniq);
Mod = readb(&PktCmdP->ModuleTypes);
Mod1 = LONYBLE(Mod);
if (RtaType == TYPE_RTA16) {
Mod2 = Mod1;
rio_dprintk(RIO_DEBUG_ROUTE, "Backplane type is %s (all ports)\n", p->RIOModuleTypes[Mod1].Name);
} else {
Mod2 = HINYBLE(Mod);
rio_dprintk(RIO_DEBUG_ROUTE, "Module types are %s (ports 0-3) and %s (ports 4-7)\n", p->RIOModuleTypes[Mod1].Name, p->RIOModuleTypes[Mod2].Name);
}
if (!(CmdBlkP = RIOGetCmdBlk())) {
rio_dprintk(RIO_DEBUG_ROUTE, "No command blocks to route RTA! come back later.\n");
return 0;
}
CmdBlkP->Packet.dest_unit = Rup;
CmdBlkP->Packet.dest_port = ROUTE_RUP;
CmdBlkP->Packet.src_unit = HOST_ID;
CmdBlkP->Packet.src_port = ROUTE_RUP;
CmdBlkP->Packet.len = PKT_CMD_BIT | 1;
CmdBlkP->PreFuncP = CmdBlkP->PostFuncP = NULL;
PktReplyP = (struct PktCmd_M *) CmdBlkP->Packet.data;
if (!RIOBootOk(p, HostP, RtaUniq)) {
rio_dprintk(RIO_DEBUG_ROUTE, "RTA %x tried to get an ID, but does not belong - FOAD it!\n", RtaUniq);
PktReplyP->Command = ROUTE_FOAD;
memcpy(PktReplyP->CommandText, "RT_FOAD", 7);
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
return 1;
}
for (ThisUnit = 0; ThisUnit < MAX_RUP; ThisUnit++) {
rio_dprintk(RIO_DEBUG_ROUTE, "Entry %d Flags=%s %s UniqueNum=0x%x\n",
ThisUnit, HostP->Mapping[ThisUnit].Flags & SLOT_IN_USE ? "Slot-In-Use" : "Not In Use", HostP->Mapping[ThisUnit].Flags & SLOT_TENTATIVE ? "Slot-Tentative" : "Not Tentative", HostP->Mapping[ThisUnit].RtaUniqueNum);
if ((HostP->Mapping[ThisUnit].Flags & (SLOT_IN_USE | SLOT_TENTATIVE)) && (HostP->Mapping[ThisUnit].RtaUniqueNum == RtaUniq)) {
if (RtaType == TYPE_RTA16) {
ThisUnit2 = HostP->Mapping[ThisUnit].ID2 - 1;
rio_dprintk(RIO_DEBUG_ROUTE, "Found unit 0x%x at slots %d+%d\n", RtaUniq, ThisUnit, ThisUnit2);
} else
rio_dprintk(RIO_DEBUG_ROUTE, "Found unit 0x%x at slot %d\n", RtaUniq, ThisUnit);
if ((HostP->Mapping[ThisUnit].Flags & SLOT_IN_USE) && !(HostP->Mapping[ThisUnit].Flags & RTA_BOOTED)) {
if (!(HostP->Mapping[ThisUnit].Flags & MSG_DONE)) {
if (!p->RIONoMessage)
printk(KERN_DEBUG "rio: RTA '%s' is being updated.\n", HostP->Mapping[ThisUnit].Name);
HostP->Mapping[ThisUnit].Flags |= MSG_DONE;
}
PktReplyP->Command = ROUTE_FOAD;
memcpy(PktReplyP->CommandText, "RT_FOAD", 7);
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
return 1;
}
PktReplyP->Command = ROUTE_ALLOCATE;
PktReplyP->IDNum = ThisUnit + 1;
if (RtaType == TYPE_RTA16) {
if (HostP->Mapping[ThisUnit].Flags & SLOT_IN_USE)
RIOFixPhbs(p, HostP, ThisUnit2);
PktReplyP->IDNum2 = ThisUnit2 + 1;
rio_dprintk(RIO_DEBUG_ROUTE, "RTA '%s' has been allocated IDs %d+%d\n", HostP->Mapping[ThisUnit].Name, PktReplyP->IDNum, PktReplyP->IDNum2);
} else {
PktReplyP->IDNum2 = ROUTE_NO_ID;
rio_dprintk(RIO_DEBUG_ROUTE, "RTA '%s' has been allocated ID %d\n", HostP->Mapping[ThisUnit].Name, PktReplyP->IDNum);
}
memcpy(PktReplyP->CommandText, "RT_ALLOCAT", 10);
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
if ((HostP->Mapping[ThisUnit].Flags & RTA_NEWBOOT) && (HostP->Mapping[ThisUnit].SysPort != NO_PORT)) {
for (port = 0; port < PORTS_PER_RTA; port++) {
PortP = p->RIOPortp[port + HostP->Mapping[ThisUnit].SysPort];
if (PortP->State & (RIO_MOPEN | RIO_LOPEN)) {
rio_dprintk(RIO_DEBUG_ROUTE, "Re-opened this port\n");
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->MagicFlags |= MAGIC_REBOOT;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
}
}
if (RtaType == TYPE_RTA16) {
for (port = 0; port < PORTS_PER_RTA; port++) {
PortP = p->RIOPortp[port + HostP->Mapping[ThisUnit2].SysPort];
if (PortP->State & (RIO_MOPEN | RIO_LOPEN)) {
rio_dprintk(RIO_DEBUG_ROUTE, "Re-opened this port\n");
rio_spin_lock_irqsave(&PortP->portSem, flags);
PortP->MagicFlags |= MAGIC_REBOOT;
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
}
}
}
}
HostP->UnixRups[ThisUnit].ModTypes = Mod;
if (RtaType == TYPE_RTA16)
HostP->UnixRups[ThisUnit2].ModTypes = Mod;
if (HostP->Mapping[ThisUnit].SysPort != NO_PORT) {
for (port = 0; port < PORTS_PER_MODULE; port++) {
p->RIOPortp[port + HostP->Mapping[ThisUnit].SysPort]->Config &= ~RIO_NOMASK;
p->RIOPortp[port + HostP->Mapping[ThisUnit].SysPort]->Config |= p->RIOModuleTypes[Mod1].Flags[port];
p->RIOPortp[port + PORTS_PER_MODULE + HostP->Mapping[ThisUnit].SysPort]->Config &= ~RIO_NOMASK;
p->RIOPortp[port + PORTS_PER_MODULE + HostP->Mapping[ThisUnit].SysPort]->Config |= p->RIOModuleTypes[Mod2].Flags[port];
}
if (RtaType == TYPE_RTA16) {
for (port = 0; port < PORTS_PER_MODULE; port++) {
p->RIOPortp[port + HostP->Mapping[ThisUnit2].SysPort]->Config &= ~RIO_NOMASK;
p->RIOPortp[port + HostP->Mapping[ThisUnit2].SysPort]->Config |= p->RIOModuleTypes[Mod1].Flags[port];
p->RIOPortp[port + PORTS_PER_MODULE + HostP->Mapping[ThisUnit2].SysPort]->Config &= ~RIO_NOMASK;
p->RIOPortp[port + PORTS_PER_MODULE + HostP->Mapping[ThisUnit2].SysPort]->Config |= p->RIOModuleTypes[Mod2].Flags[port];
}
}
}
return 1;
}
}
for (ThisUnit = 0; ThisUnit < HostP->NumExtraBooted; ThisUnit++)
if (HostP->ExtraUnits[ThisUnit] == RtaUniq)
break;
if (ThisUnit == HostP->NumExtraBooted && ThisUnit != MAX_EXTRA_UNITS) {
static int UnknownMesgDone = 0;
if (!UnknownMesgDone) {
if (!p->RIONoMessage)
printk(KERN_DEBUG "rio: One or more unknown RTAs are being updated.\n");
UnknownMesgDone = 1;
}
PktReplyP->Command = ROUTE_FOAD;
memcpy(PktReplyP->CommandText, "RT_FOAD", 7);
} else {
if (RtaType == TYPE_RTA16) {
if (RIOFindFreeID(p, HostP, &ThisUnit, &ThisUnit2) == 0) {
RIODefaultName(p, HostP, ThisUnit);
rio_fill_host_slot(ThisUnit, ThisUnit2, RtaUniq, HostP);
}
} else {
if (RIOFindFreeID(p, HostP, &ThisUnit, NULL) == 0) {
RIODefaultName(p, HostP, ThisUnit);
rio_fill_host_slot(ThisUnit, 0, RtaUniq, HostP);
}
}
PktReplyP->Command = ROUTE_USED;
memcpy(PktReplyP->CommandText, "RT_USED", 7);
}
RIOQueueCmdBlk(HostP, Rup, CmdBlkP);
return 1;
}
void RIOFixPhbs(struct rio_info *p, struct Host *HostP, unsigned int unit)
{
unsigned short link, port;
struct Port *PortP;
unsigned long flags;
int PortN = HostP->Mapping[unit].SysPort;
rio_dprintk(RIO_DEBUG_ROUTE, "RIOFixPhbs unit %d sysport %d\n", unit, PortN);
if (PortN != -1) {
unsigned short dest_unit = HostP->Mapping[unit].ID2;
PortP = p->RIOPortp[HostP->Mapping[dest_unit - 1].SysPort];
link = readw(&PortP->PhbP->link);
for (port = 0; port < PORTS_PER_RTA; port++, PortN++) {
unsigned short dest_port = port + 8;
u16 __iomem *TxPktP;
struct PKT __iomem *Pkt;
PortP = p->RIOPortp[PortN];
rio_spin_lock_irqsave(&PortP->portSem, flags);
if (!PortP->TxStart) {
rio_dprintk(RIO_DEBUG_ROUTE, "Tx pkts not set up yet\n");
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
break;
}
for (TxPktP = PortP->TxStart; TxPktP <= PortP->TxEnd; TxPktP++) {
Pkt = (struct PKT __iomem *) RIO_PTR(HostP->Caddr, readw(TxPktP));
Pkt = (struct PKT __iomem *) ((unsigned long) Pkt & ~PKT_IN_USE);
writeb(dest_unit, &Pkt->dest_unit);
writeb(dest_port, &Pkt->dest_port);
}
rio_dprintk(RIO_DEBUG_ROUTE, "phb dest: Old %x:%x New %x:%x\n", readw(&PortP->PhbP->destination) & 0xff, (readw(&PortP->PhbP->destination) >> 8) & 0xff, dest_unit, dest_port);
writew(dest_unit + (dest_port << 8), &PortP->PhbP->destination);
writew(link, &PortP->PhbP->link);
rio_spin_unlock_irqrestore(&PortP->portSem, flags);
}
if (link > 3)
return;
if (((unit * 8) + 7) > readw(&HostP->LinkStrP[link].last_port)) {
rio_dprintk(RIO_DEBUG_ROUTE, "last port on host link %d: %d\n", link, (unit * 8) + 7);
writew((unit * 8) + 7, &HostP->LinkStrP[link].last_port);
}
}
}
static int RIOCheckIsolated(struct rio_info *p, struct Host *HostP, unsigned int UnitId)
{
unsigned long flags;
rio_spin_lock_irqsave(&HostP->HostLock, flags);
if (RIOCheck(HostP, UnitId)) {
rio_dprintk(RIO_DEBUG_ROUTE, "Unit %d is NOT isolated\n", UnitId);
rio_spin_unlock_irqrestore(&HostP->HostLock, flags);
return (0);
}
RIOIsolate(p, HostP, UnitId);
RIOSetChange(p);
rio_spin_unlock_irqrestore(&HostP->HostLock, flags);
return 1;
}
static int RIOIsolate(struct rio_info *p, struct Host *HostP, unsigned int UnitId)
{
unsigned int link, unit;
UnitId--;
if (UnitId >= MAX_RUP)
return (0);
if (HostP->Mapping[UnitId].Flags & BEEN_HERE)
return (0);
HostP->Mapping[UnitId].Flags |= BEEN_HERE;
if (p->RIOPrintDisabled == DO_PRINT)
rio_dprintk(RIO_DEBUG_ROUTE, "RIOMesgIsolated %s", HostP->Mapping[UnitId].Name);
for (link = 0; link < LINKS_PER_UNIT; link++) {
unit = HostP->Mapping[UnitId].Topology[link].Unit;
HostP->Mapping[UnitId].Topology[link].Unit = ROUTE_DISCONNECT;
HostP->Mapping[UnitId].Topology[link].Link = NO_LINK;
RIOIsolate(p, HostP, unit);
}
HostP->Mapping[UnitId].Flags &= ~BEEN_HERE;
return 1;
}
static int RIOCheck(struct Host *HostP, unsigned int UnitId)
{
unsigned char link;
rio_dprintk(RIO_DEBUG_ROUTE, "RIOCheck : UnitID = %d\n", UnitId);
if (UnitId == HOST_ID) {
return 1;
}
UnitId--;
if (UnitId >= MAX_RUP) {
return 0;
}
for (link = 0; link < LINKS_PER_UNIT; link++) {
if (HostP->Mapping[UnitId].Topology[link].Unit == HOST_ID) {
return 1;
}
}
if (HostP->Mapping[UnitId].Flags & BEEN_HERE) {
return 0;
}
HostP->Mapping[UnitId].Flags |= BEEN_HERE;
for (link = 0; link < LINKS_PER_UNIT; link++) {
if (RIOCheck(HostP, HostP->Mapping[UnitId].Topology[link].Unit)) {
HostP->Mapping[UnitId].Flags &= ~BEEN_HERE;
return 1;
}
}
HostP->Mapping[UnitId].Flags &= ~BEEN_HERE;
return 0;
}
unsigned int GetUnitType(unsigned int Uniq)
{
switch ((Uniq >> 28) & 0xf) {
case RIO_AT:
case RIO_MCA:
case RIO_EISA:
case RIO_PCI:
rio_dprintk(RIO_DEBUG_ROUTE, "Unit type: Host\n");
return (TYPE_HOST);
case RIO_RTA_16:
rio_dprintk(RIO_DEBUG_ROUTE, "Unit type: 16 port RTA\n");
return (TYPE_RTA16);
case RIO_RTA:
rio_dprintk(RIO_DEBUG_ROUTE, "Unit type: 8 port RTA\n");
return (TYPE_RTA8);
default:
rio_dprintk(RIO_DEBUG_ROUTE, "Unit type: Unrecognised\n");
return (99);
}
}
int RIOSetChange(struct rio_info *p)
{
if (p->RIOQuickCheck != NOT_CHANGED)
return (0);
p->RIOQuickCheck = CHANGED;
if (p->RIOSignalProcess) {
rio_dprintk(RIO_DEBUG_ROUTE, "Send SIG-HUP");
}
return (0);
}
static void RIOConCon(struct rio_info *p,
struct Host *HostP,
unsigned int FromId,
unsigned int FromLink,
unsigned int ToId,
unsigned int ToLink,
int Change)
{
char *FromName;
char *FromType;
char *ToName;
char *ToType;
unsigned int tp;
if (Change == CONNECT) {
if (p->RIORtaDisCons)
p->RIORtaDisCons--;
} else {
p->RIORtaDisCons++;
}
if (p->RIOPrintDisabled == DONT_PRINT)
return;
if (FromId > ToId) {
tp = FromId;
FromId = ToId;
ToId = tp;
tp = FromLink;
FromLink = ToLink;
ToLink = tp;
}
FromName = FromId ? HostP->Mapping[FromId - 1].Name : HostP->Name;
FromType = FromId ? "RTA" : "HOST";
ToName = ToId ? HostP->Mapping[ToId - 1].Name : HostP->Name;
ToType = ToId ? "RTA" : "HOST";
rio_dprintk(RIO_DEBUG_ROUTE, "Link between %s '%s' (%c) and %s '%s' (%c) %s.\n", FromType, FromName, 'A' + FromLink, ToType, ToName, 'A' + ToLink, (Change == CONNECT) ? "established" : "disconnected");
printk(KERN_DEBUG "rio: Link between %s '%s' (%c) and %s '%s' (%c) %s.\n", FromType, FromName, 'A' + FromLink, ToType, ToName, 'A' + ToLink, (Change == CONNECT) ? "established" : "disconnected");
}
static int RIORemoveFromSavedTable(struct rio_info *p, struct Map *pMap)
{
int entry;
for (entry = 0; entry < TOTAL_MAP_ENTRIES; entry++) {
if (p->RIOSavedTable[entry].RtaUniqueNum == pMap->RtaUniqueNum) {
memset(&p->RIOSavedTable[entry], 0, sizeof(struct Map));
}
}
return 0;
}
static int RIOFreeDisconnected(struct rio_info *p, struct Host *HostP, int unit)
{
int link;
rio_dprintk(RIO_DEBUG_ROUTE, "RIOFreeDisconnect unit %d\n", unit);
for (link = 0; link < LINKS_PER_UNIT; link++) {
if (HostP->Mapping[unit].Topology[link].Unit != ROUTE_DISCONNECT)
break;
}
if (link < LINKS_PER_UNIT)
return 1;
#ifdef NEED_TO_FIX_THIS
rio_dprintk(RIO_DEBUG_ROUTE, "Just about to check LBOLT on entry %d\n", unit);
if (drv_getparm(LBOLT, (ulong_t *) & current_time))
rio_dprintk(RIO_DEBUG_ROUTE, "drv_getparm(LBOLT,....) Failed.\n");
elapse_time = current_time - TentTime[unit];
rio_dprintk(RIO_DEBUG_ROUTE, "elapse %d = current %d - tent %d (%d usec)\n", elapse_time, current_time, TentTime[unit], drv_hztousec(elapse_time));
if (drv_hztousec(elapse_time) < WAIT_TO_FINISH) {
rio_dprintk(RIO_DEBUG_ROUTE, "Skipping slot %d, not timed out yet %d\n", unit, drv_hztousec(elapse_time));
return 1;
}
#endif
if (HostP->Mapping[unit].ID2 != 0) {
int nOther = (HostP->Mapping[unit].ID2) - 1;
rio_dprintk(RIO_DEBUG_ROUTE, "RioFreedis second slot %d.\n", nOther);
memset(&HostP->Mapping[nOther], 0, sizeof(struct Map));
}
RIORemoveFromSavedTable(p, &HostP->Mapping[unit]);
return 0;
}
int RIOFindFreeID(struct rio_info *p, struct Host *HostP, unsigned int * pID1, unsigned int * pID2)
{
int unit, tempID;
*pID1 = MAX_RUP;
if (pID2 != NULL)
*pID2 = MAX_RUP;
for (unit = 0; unit < MAX_RUP; unit++) {
rio_dprintk(RIO_DEBUG_ROUTE, "Scanning unit %d\n", unit);
if (HostP->Mapping[unit].Flags == 0) {
rio_dprintk(RIO_DEBUG_ROUTE, " This slot is empty.\n");
if (*pID1 == MAX_RUP) {
rio_dprintk(RIO_DEBUG_ROUTE, "Make tentative entry for first unit %d\n", unit);
*pID1 = unit;
if (pID2 == NULL)
return 0;
} else {
rio_dprintk(RIO_DEBUG_ROUTE, "Make tentative entry for second unit %d\n", unit);
*pID2 = unit;
return 0;
}
}
}
rio_dprintk(RIO_DEBUG_ROUTE, "Starting to scan for tentative slots\n");
for (unit = 0; unit < MAX_RUP; unit++) {
if (((HostP->Mapping[unit].Flags & SLOT_TENTATIVE) || (HostP->Mapping[unit].Flags == 0)) && !(HostP->Mapping[unit].Flags & RTA16_SECOND_SLOT)) {
rio_dprintk(RIO_DEBUG_ROUTE, " Slot %d looks promising.\n", unit);
if (unit == *pID1) {
rio_dprintk(RIO_DEBUG_ROUTE, " No it isn't, its the 1st half\n");
continue;
}
if (HostP->Mapping[unit].Flags != 0)
if (RIOFreeDisconnected(p, HostP, unit) != 0)
continue;
if (*pID1 == MAX_RUP) {
rio_dprintk(RIO_DEBUG_ROUTE, "Grab tentative entry for first unit %d\n", unit);
*pID1 = unit;
memset(&HostP->Mapping[unit], 0, sizeof(struct Map));
if (pID2 == NULL)
return 0;
} else {
rio_dprintk(RIO_DEBUG_ROUTE, "Grab tentative/empty entry for second unit %d\n", unit);
*pID2 = unit;
memset(&HostP->Mapping[unit], 0, sizeof(struct Map));
if (*pID1 > *pID2) {
rio_dprintk(RIO_DEBUG_ROUTE, "Swapping IDS %d %d\n", *pID1, *pID2);
tempID = *pID1;
*pID1 = *pID2;
*pID2 = tempID;
}
return 0;
}
}
}
return 1;
}
