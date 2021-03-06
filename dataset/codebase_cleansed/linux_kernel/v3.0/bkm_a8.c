static inline u_char
readreg(unsigned int ale, unsigned int adr, u_char off)
{
register u_char ret;
wordout(ale, off);
ret = wordin(adr) & 0xFF;
return (ret);
}
static inline void
readfifo(unsigned int ale, unsigned int adr, u_char off, u_char * data, int size)
{
int i;
wordout(ale, off);
for (i = 0; i < size; i++)
data[i] = wordin(adr) & 0xFF;
}
static inline void
writereg(unsigned int ale, unsigned int adr, u_char off, u_char data)
{
wordout(ale, off);
wordout(adr, data);
}
static inline void
writefifo(unsigned int ale, unsigned int adr, u_char off, u_char * data, int size)
{
int i;
wordout(ale, off);
for (i = 0; i < size; i++)
wordout(adr, data[i]);
}
static u_char
ReadISAC(struct IsdnCardState *cs, u_char offset)
{
return (readreg(cs->hw.ax.base, cs->hw.ax.data_adr, offset | 0x80));
}
static void
WriteISAC(struct IsdnCardState *cs, u_char offset, u_char value)
{
writereg(cs->hw.ax.base, cs->hw.ax.data_adr, offset | 0x80, value);
}
static void
ReadISACfifo(struct IsdnCardState *cs, u_char * data, int size)
{
readfifo(cs->hw.ax.base, cs->hw.ax.data_adr, 0x80, data, size);
}
static void
WriteISACfifo(struct IsdnCardState *cs, u_char * data, int size)
{
writefifo(cs->hw.ax.base, cs->hw.ax.data_adr, 0x80, data, size);
}
static u_char
ReadHSCX(struct IsdnCardState *cs, int hscx, u_char offset)
{
return (readreg(cs->hw.ax.base, cs->hw.ax.data_adr, offset + (hscx ? 0x40 : 0)));
}
static void
WriteHSCX(struct IsdnCardState *cs, int hscx, u_char offset, u_char value)
{
writereg(cs->hw.ax.base, cs->hw.ax.data_adr, offset + (hscx ? 0x40 : 0), value);
}
static void
set_ipac_active(struct IsdnCardState *cs, u_int active)
{
writereg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_MASK,
active ? 0xc0 : 0xff);
}
static irqreturn_t
bkm_interrupt_ipac(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
u_char ista, val, icnt = 5;
u_long flags;
spin_lock_irqsave(&cs->lock, flags);
ista = readreg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_ISTA);
if (!(ista & 0x3f)) {
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_NONE;
}
Start_IPAC:
if (cs->debug & L1_DEB_IPAC)
debugl1(cs, "IPAC ISTA %02X", ista);
if (ista & 0x0f) {
val = readreg(cs->hw.ax.base, cs->hw.ax.data_adr, HSCX_ISTA + 0x40);
if (ista & 0x01)
val |= 0x01;
if (ista & 0x04)
val |= 0x02;
if (ista & 0x08)
val |= 0x04;
if (val) {
hscx_int_main(cs, val);
}
}
if (ista & 0x20) {
val = 0xfe & readreg(cs->hw.ax.base, cs->hw.ax.data_adr, ISAC_ISTA | 0x80);
if (val) {
isac_interrupt(cs, val);
}
}
if (ista & 0x10) {
val = 0x01;
isac_interrupt(cs, val);
}
ista = readreg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_ISTA);
if ((ista & 0x3f) && icnt) {
icnt--;
goto Start_IPAC;
}
if (!icnt)
printk(KERN_WARNING "HiSax: Scitel Quadro (%s) IRQ LOOP\n",
sct_quadro_subtypes[cs->subtyp]);
writereg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_MASK, 0xFF);
writereg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_MASK, 0xC0);
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
static void
release_io_sct_quadro(struct IsdnCardState *cs)
{
release_region(cs->hw.ax.base & 0xffffffc0, 128);
if (cs->subtyp == SCT_1)
release_region(cs->hw.ax.plx_adr, 64);
}
static void
enable_bkm_int(struct IsdnCardState *cs, unsigned bEnable)
{
if (cs->typ == ISDN_CTYPE_SCT_QUADRO) {
if (bEnable)
wordout(cs->hw.ax.plx_adr + 0x4C, (wordin(cs->hw.ax.plx_adr + 0x4C) | 0x41));
else
wordout(cs->hw.ax.plx_adr + 0x4C, (wordin(cs->hw.ax.plx_adr + 0x4C) & ~0x41));
}
}
static void
reset_bkm(struct IsdnCardState *cs)
{
if (cs->subtyp == SCT_1) {
wordout(cs->hw.ax.plx_adr + 0x50, (wordin(cs->hw.ax.plx_adr + 0x50) & ~4));
mdelay(10);
wordout(cs->hw.ax.plx_adr + 0x50, (wordin(cs->hw.ax.plx_adr + 0x50) | 4));
mdelay(10);
}
}
static int
BKM_card_msg(struct IsdnCardState *cs, int mt, void *arg)
{
u_long flags;
switch (mt) {
case CARD_RESET:
spin_lock_irqsave(&cs->lock, flags);
set_ipac_active(cs, 0);
enable_bkm_int(cs, 0);
reset_bkm(cs);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_RELEASE:
spin_lock_irqsave(&cs->lock, flags);
set_ipac_active(cs, 0);
enable_bkm_int(cs, 0);
spin_unlock_irqrestore(&cs->lock, flags);
release_io_sct_quadro(cs);
return (0);
case CARD_INIT:
spin_lock_irqsave(&cs->lock, flags);
cs->debug |= L1_DEB_IPAC;
set_ipac_active(cs, 1);
inithscxisac(cs, 3);
enable_bkm_int(cs, 1);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_TEST:
return (0);
}
return (0);
}
static int __devinit
sct_alloc_io(u_int adr, u_int len)
{
if (!request_region(adr, len, "scitel")) {
printk(KERN_WARNING
"HiSax: Scitel port %#x-%#x already in use\n",
adr, adr + len);
return (1);
}
return(0);
}
int __devinit
setup_sct_quadro(struct IsdnCard *card)
{
struct IsdnCardState *cs = card->cs;
char tmp[64];
u_int found = 0;
u_int pci_ioaddr1, pci_ioaddr2, pci_ioaddr3, pci_ioaddr4, pci_ioaddr5;
strcpy(tmp, sct_quadro_revision);
printk(KERN_INFO "HiSax: T-Berkom driver Rev. %s\n", HiSax_getrev(tmp));
if (cs->typ == ISDN_CTYPE_SCT_QUADRO) {
cs->subtyp = SCT_1;
} else
return (0);
if (card->para[0] >= SCT_1 && card->para[0] <= SCT_4)
cs->subtyp = card->para[0];
else {
printk(KERN_WARNING "HiSax: Scitel Quadro: Invalid "
"subcontroller in configuration, default to 1\n");
return (0);
}
if ((cs->subtyp != SCT_1) && ((sub_sys_id != PCI_DEVICE_ID_BERKOM_SCITEL_QUADRO) ||
(sub_vendor_id != PCI_VENDOR_ID_BERKOM)))
return (0);
if (cs->subtyp == SCT_1) {
while ((dev_a8 = hisax_find_pci_device(PCI_VENDOR_ID_PLX,
PCI_DEVICE_ID_PLX_9050, dev_a8))) {
sub_vendor_id = dev_a8->subsystem_vendor;
sub_sys_id = dev_a8->subsystem_device;
if ((sub_sys_id == PCI_DEVICE_ID_BERKOM_SCITEL_QUADRO) &&
(sub_vendor_id == PCI_VENDOR_ID_BERKOM)) {
if (pci_enable_device(dev_a8))
return(0);
pci_ioaddr1 = pci_resource_start(dev_a8, 1);
pci_irq = dev_a8->irq;
pci_bus = dev_a8->bus->number;
pci_device_fn = dev_a8->devfn;
found = 1;
break;
}
}
if (!found) {
printk(KERN_WARNING "HiSax: Scitel Quadro (%s): "
"Card not found\n",
sct_quadro_subtypes[cs->subtyp]);
return (0);
}
#ifdef ATTEMPT_PCI_REMAPPING
if ((pci_ioaddr1 & 0x80) && (dev_a8->revision == 1)) {
printk(KERN_WARNING "HiSax: Scitel Quadro (%s): "
"PLX rev 1, remapping required!\n",
sct_quadro_subtypes[cs->subtyp]);
pci_write_config_dword(dev_a8, PCI_BASE_ADDRESS_1, (u_int) - 1);
pci_ioaddr1 += 0x80;
pci_ioaddr1 &= PCI_BASE_ADDRESS_IO_MASK;
pci_write_config_dword(dev_a8, PCI_BASE_ADDRESS_1, pci_ioaddr1);
dev_a8->resource[ 1].start = pci_ioaddr1;
}
#endif
}
if (!pci_irq) {
printk(KERN_WARNING "HiSax: Scitel Quadro (%s): No IRQ\n",
sct_quadro_subtypes[cs->subtyp]);
return (0);
}
pci_read_config_dword(dev_a8, PCI_BASE_ADDRESS_1, &pci_ioaddr1);
pci_read_config_dword(dev_a8, PCI_BASE_ADDRESS_2, &pci_ioaddr2);
pci_read_config_dword(dev_a8, PCI_BASE_ADDRESS_3, &pci_ioaddr3);
pci_read_config_dword(dev_a8, PCI_BASE_ADDRESS_4, &pci_ioaddr4);
pci_read_config_dword(dev_a8, PCI_BASE_ADDRESS_5, &pci_ioaddr5);
if (!pci_ioaddr1 || !pci_ioaddr2 || !pci_ioaddr3 || !pci_ioaddr4 || !pci_ioaddr5) {
printk(KERN_WARNING "HiSax: Scitel Quadro (%s): "
"No IO base address(es)\n",
sct_quadro_subtypes[cs->subtyp]);
return (0);
}
pci_ioaddr1 &= PCI_BASE_ADDRESS_IO_MASK;
pci_ioaddr2 &= PCI_BASE_ADDRESS_IO_MASK;
pci_ioaddr3 &= PCI_BASE_ADDRESS_IO_MASK;
pci_ioaddr4 &= PCI_BASE_ADDRESS_IO_MASK;
pci_ioaddr5 &= PCI_BASE_ADDRESS_IO_MASK;
cs->irq = pci_irq;
cs->irq_flags |= IRQF_SHARED;
cs->hw.ax.plx_adr = pci_ioaddr1;
switch(cs->subtyp) {
case 1:
cs->hw.ax.base = pci_ioaddr5 + 0x00;
if (sct_alloc_io(pci_ioaddr1, 128))
return(0);
if (sct_alloc_io(pci_ioaddr5, 64))
return(0);
writereg(pci_ioaddr5, pci_ioaddr5 + 4,
IPAC_MASK, 0xFF);
writereg(pci_ioaddr4 + 0x08, pci_ioaddr4 + 0x0c,
IPAC_MASK, 0xFF);
writereg(pci_ioaddr3 + 0x10, pci_ioaddr3 + 0x14,
IPAC_MASK, 0xFF);
writereg(pci_ioaddr2 + 0x20, pci_ioaddr2 + 0x24,
IPAC_MASK, 0xFF);
break;
case 2:
cs->hw.ax.base = pci_ioaddr4 + 0x08;
if (sct_alloc_io(pci_ioaddr4, 64))
return(0);
break;
case 3:
cs->hw.ax.base = pci_ioaddr3 + 0x10;
if (sct_alloc_io(pci_ioaddr3, 64))
return(0);
break;
case 4:
cs->hw.ax.base = pci_ioaddr2 + 0x20;
if (sct_alloc_io(pci_ioaddr2, 64))
return(0);
break;
}
cs->hw.ax.data_adr = cs->hw.ax.base + 4;
printk(KERN_INFO "HiSax: Scitel Quadro (%s) configured at "
"0x%.4lX, 0x%.4lX, 0x%.4lX and IRQ %d\n",
sct_quadro_subtypes[cs->subtyp],
cs->hw.ax.plx_adr,
cs->hw.ax.base,
cs->hw.ax.data_adr,
cs->irq);
test_and_set_bit(HW_IPAC, &cs->HW_Flags);
cs->readisac = &ReadISAC;
cs->writeisac = &WriteISAC;
cs->readisacfifo = &ReadISACfifo;
cs->writeisacfifo = &WriteISACfifo;
cs->BC_Read_Reg = &ReadHSCX;
cs->BC_Write_Reg = &WriteHSCX;
cs->BC_Send_Data = &hscx_fill_fifo;
cs->cardmsg = &BKM_card_msg;
cs->irq_func = &bkm_interrupt_ipac;
printk(KERN_INFO "HiSax: Scitel Quadro (%s): IPAC Version %d\n",
sct_quadro_subtypes[cs->subtyp],
readreg(cs->hw.ax.base, cs->hw.ax.data_adr, IPAC_ID));
return (1);
}
