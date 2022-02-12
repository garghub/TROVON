int RIOAssignAT(struct rio_info *p, int Base, void __iomem *virtAddr, int mode)
{
int bits;
struct DpRam __iomem *cardp = (struct DpRam __iomem *)virtAddr;
if ((Base < ONE_MEG) || (mode & BYTE_ACCESS_MODE))
bits = BYTE_OPERATION;
else
bits = WORD_OPERATION;
p->RIOHosts[p->RIONumHosts].Caddr = virtAddr;
p->RIOHosts[p->RIONumHosts].CardP = virtAddr;
if (readb(&cardp->DpRevision) == 01)
bits = BYTE_OPERATION;
p->RIOHosts[p->RIONumHosts].Type = RIO_AT;
p->RIOHosts[p->RIONumHosts].Copy = rio_copy_to_card;
p->RIOHosts[p->RIONumHosts].Slot = -1;
p->RIOHosts[p->RIONumHosts].Mode = SLOW_LINKS | SLOW_AT_BUS | bits;
writeb(BOOT_FROM_RAM | EXTERNAL_BUS_OFF | p->RIOHosts[p->RIONumHosts].Mode | INTERRUPT_DISABLE ,
&p->RIOHosts[p->RIONumHosts].Control);
writeb(0xFF, &p->RIOHosts[p->RIONumHosts].ResetInt);
writeb(BOOT_FROM_RAM | EXTERNAL_BUS_OFF | p->RIOHosts[p->RIONumHosts].Mode | INTERRUPT_DISABLE,
&p->RIOHosts[p->RIONumHosts].Control);
writeb(0xFF, &p->RIOHosts[p->RIONumHosts].ResetInt);
p->RIOHosts[p->RIONumHosts].UniqueNum =
((readb(&p->RIOHosts[p->RIONumHosts].Unique[0])&0xFF)<<0)|
((readb(&p->RIOHosts[p->RIONumHosts].Unique[1])&0xFF)<<8)|
((readb(&p->RIOHosts[p->RIONumHosts].Unique[2])&0xFF)<<16)|
((readb(&p->RIOHosts[p->RIONumHosts].Unique[3])&0xFF)<<24);
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Uniquenum 0x%x\n",p->RIOHosts[p->RIONumHosts].UniqueNum);
p->RIONumHosts++;
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Tests Passed at 0x%x\n", Base);
return(1);
}
int RIOBoardTest(unsigned long paddr, void __iomem *caddr, unsigned char type, int slot)
{
struct DpRam __iomem *DpRam = caddr;
void __iomem *ram[4];
int size[4];
int op, bank;
int nbanks;
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Reset host type=%d, DpRam=%p, slot=%d\n",
type, DpRam, slot);
RIOHostReset(type, DpRam, slot);
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Setup ram/size arrays\n");
size[0] = DP_SRAM1_SIZE;
size[1] = DP_SRAM2_SIZE;
size[2] = DP_SRAM3_SIZE;
size[3] = DP_SCRATCH_SIZE;
ram[0] = DpRam->DpSram1;
ram[1] = DpRam->DpSram2;
ram[2] = DpRam->DpSram3;
nbanks = (type == RIO_PCI) ? 3 : 4;
if (nbanks == 4)
ram[3] = DpRam->DpScratch;
if (nbanks == 3) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Memory: %p(0x%x), %p(0x%x), %p(0x%x)\n",
ram[0], size[0], ram[1], size[1], ram[2], size[2]);
} else {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: %p(0x%x), %p(0x%x), %p(0x%x), %p(0x%x)\n",
ram[0], size[0], ram[1], size[1], ram[2], size[2], ram[3], size[3]);
}
for (op=0; op<TEST_END; op++) {
for (bank=0; bank<nbanks; bank++) {
if (RIOScrub(op, ram[bank], size[bank]) == RIO_FAIL) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: RIOScrub band %d, op %d failed\n",
bank, op);
return RIO_FAIL;
}
}
}
rio_dprintk (RIO_DEBUG_INIT, "Test completed\n");
return 0;
}
static int RIOScrub(int op, u8 __iomem *ram, int size)
{
int off;
unsigned char oldbyte;
unsigned char newbyte;
unsigned char invbyte;
unsigned short oldword;
unsigned short newword;
unsigned short invword;
unsigned short swapword;
if (op) {
oldbyte = val[op-1];
oldword = oldbyte | (oldbyte<<8);
} else
oldbyte = oldword = 0;
newbyte = val[op];
newword = newbyte | (newbyte<<8);
invbyte = ~newbyte;
invword = invbyte | (invbyte<<8);
if (op) {
for (off=0; off<size; off++) {
if (readb(ram + off) != oldbyte) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Byte Pre Check 1: BYTE at offset 0x%x should have been=%x, was=%x\n", off, oldbyte, readb(ram + off));
return RIO_FAIL;
}
}
for (off=0; off<size; off+=2) {
if (readw(ram + off) != oldword) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Word Pre Check: WORD at offset 0x%x should have been=%x, was=%x\n",off,oldword, readw(ram + off));
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Word Pre Check: BYTE at offset 0x%x is %x BYTE at offset 0x%x is %x\n", off, readb(ram + off), off+1, readb(ram+off+1));
return RIO_FAIL;
}
}
}
for (off=0; off<size; off++) {
if (op && (readb(ram + off) != oldbyte)) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Byte Pre Check 2: BYTE at offset 0x%x should have been=%x, was=%x\n", off, oldbyte, readb(ram + off));
return RIO_FAIL;
}
writeb(invbyte, ram + off);
if (readb(ram + off) != invbyte) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Byte Inv Check: BYTE at offset 0x%x should have been=%x, was=%x\n", off, invbyte, readb(ram + off));
return RIO_FAIL;
}
}
for (off=0; off<size; off+=2) {
if (readw(ram + off) != invword) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Word Inv Check: WORD at offset 0x%x should have been=%x, was=%x\n", off, invword, readw(ram + off));
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Word Inv Check: BYTE at offset 0x%x is %x BYTE at offset 0x%x is %x\n", off, readb(ram + off), off+1, readb(ram+off+1));
return RIO_FAIL;
}
writew(newword, ram + off);
if ( readw(ram + off) != newword ) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Post Word Check 1: WORD at offset 0x%x should have been=%x, was=%x\n", off, newword, readw(ram + off));
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Post Word Check 1: BYTE at offset 0x%x is %x BYTE at offset 0x%x is %x\n", off, readb(ram + off), off+1, readb(ram + off + 1));
return RIO_FAIL;
}
}
for (off=0; off<size; off++) {
if (readb(ram + off) != newbyte) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Post Byte Check: BYTE at offset 0x%x should have been=%x, was=%x\n", off, newbyte, readb(ram + off));
return RIO_FAIL;
}
}
for (off=0; off<size; off+=2) {
if (readw(ram + off) != newword ) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Post Word Check 2: WORD at offset 0x%x should have been=%x, was=%x\n", off, newword, readw(ram + off));
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: Post Word Check 2: BYTE at offset 0x%x is %x BYTE at offset 0x%x is %x\n", off, readb(ram + off), off+1, readb(ram + off + 1));
return RIO_FAIL;
}
}
swapword = invbyte | (newbyte << 8);
for (off=0; off<size; off+=2) {
writeb(invbyte, &ram[off]);
writeb(newbyte, &ram[off+1]);
}
for ( off=0; off<size; off+=2 ) {
if (readw(ram + off) != swapword) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: SwapWord Check 1: WORD at offset 0x%x should have been=%x, was=%x\n", off, swapword, readw(ram + off));
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: SwapWord Check 1: BYTE at offset 0x%x is %x BYTE at offset 0x%x is %x\n", off, readb(ram + off), off+1, readb(ram + off + 1));
return RIO_FAIL;
}
writew(~swapword, ram + off);
}
for (off=0; off<size; off+=2) {
if (readb(ram + off) != newbyte) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: SwapWord Check 2: BYTE at offset 0x%x should have been=%x, was=%x\n", off, newbyte, readb(ram + off));
return RIO_FAIL;
}
if (readb(ram + off + 1) != invbyte) {
rio_dprintk (RIO_DEBUG_INIT, "RIO-init: SwapWord Check 2: BYTE at offset 0x%x should have been=%x, was=%x\n", off+1, invbyte, readb(ram + off + 1));
return RIO_FAIL;
}
writew(newword, ram + off);
}
return 0;
}
int RIODefaultName(struct rio_info *p, struct Host *HostP, unsigned int UnitId)
{
memcpy(HostP->Mapping[UnitId].Name, "UNKNOWN RTA X-XX", 17);
HostP->Mapping[UnitId].Name[12]='1'+(HostP-p->RIOHosts);
if ((UnitId+1) > 9) {
HostP->Mapping[UnitId].Name[14]='0'+((UnitId+1)/10);
HostP->Mapping[UnitId].Name[15]='0'+((UnitId+1)%10);
}
else {
HostP->Mapping[UnitId].Name[14]='1'+UnitId;
HostP->Mapping[UnitId].Name[15]=0;
}
return 0;
}
struct rioVersion *RIOVersid(void)
{
strlcpy(stVersion.version, "RIO driver for linux V1.0",
sizeof(stVersion.version));
strlcpy(stVersion.buildDate, "Aug 15 2010",
sizeof(stVersion.buildDate));
return &stVersion;
}
void RIOHostReset(unsigned int Type, struct DpRam __iomem *DpRamP, unsigned int Slot)
{
rio_dprintk (RIO_DEBUG_INIT, "RIOHostReset: type 0x%x", Type);
switch ( Type ) {
case RIO_AT:
rio_dprintk (RIO_DEBUG_INIT, " (RIO_AT)\n");
writeb(BOOT_FROM_RAM | EXTERNAL_BUS_OFF | INTERRUPT_DISABLE | BYTE_OPERATION |
SLOW_LINKS | SLOW_AT_BUS, &DpRamP->DpControl);
writeb(0xFF, &DpRamP->DpResetTpu);
udelay(3);
rio_dprintk (RIO_DEBUG_INIT, "RIOHostReset: Don't know if it worked. Try reset again\n");
writeb(BOOT_FROM_RAM | EXTERNAL_BUS_OFF | INTERRUPT_DISABLE |
BYTE_OPERATION | SLOW_LINKS | SLOW_AT_BUS, &DpRamP->DpControl);
writeb(0xFF, &DpRamP->DpResetTpu);
udelay(3);
break;
case RIO_PCI:
rio_dprintk (RIO_DEBUG_INIT, " (RIO_PCI)\n");
writeb(RIO_PCI_BOOT_FROM_RAM, &DpRamP->DpControl);
writeb(0xFF, &DpRamP->DpResetInt);
writeb(0xFF, &DpRamP->DpResetTpu);
udelay(100);
break;
default:
rio_dprintk (RIO_DEBUG_INIT, " (UNKNOWN)\n");
break;
}
return;
}
