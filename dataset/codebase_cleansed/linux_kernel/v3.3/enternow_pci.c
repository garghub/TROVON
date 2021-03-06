static unsigned char
ReadByteAmd7930(struct IsdnCardState *cs, unsigned char offset)
{
if(offset < 8)
return (inb(cs->hw.njet.isac + 4*offset));
else {
outb(offset, cs->hw.njet.isac + 4*AMD_CR);
return(inb(cs->hw.njet.isac + 4*AMD_DR));
}
}
static void
WriteByteAmd7930(struct IsdnCardState *cs, unsigned char offset, unsigned char value)
{
if(offset < 8)
outb(value, cs->hw.njet.isac + 4*offset);
else {
outb(offset, cs->hw.njet.isac + 4*AMD_CR);
outb(value, cs->hw.njet.isac + 4*AMD_DR);
}
}
static void
enpci_setIrqMask(struct IsdnCardState *cs, unsigned char val) {
if (!val)
outb(0x00, cs->hw.njet.base+NETJET_IRQMASK1);
else
outb(TJ_AMD_IRQ, cs->hw.njet.base+NETJET_IRQMASK1);
}
static unsigned char dummyrr(struct IsdnCardState *cs, int chan, unsigned char off)
{
return(5);
}
static void dummywr(struct IsdnCardState *cs, int chan, unsigned char off, unsigned char value)
{
}
static void
reset_enpci(struct IsdnCardState *cs)
{
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "enter:now PCI: reset");
cs->hw.njet.ctrl_reg = 0x07;
outb(cs->hw.njet.ctrl_reg, cs->hw.njet.base + NETJET_CTRL);
mdelay(20);
cs->hw.njet.ctrl_reg = 0x30;
outb(cs->hw.njet.ctrl_reg, cs->hw.njet.base + NETJET_CTRL);
mdelay(20);
cs->hw.njet.auxd = 0;
cs->hw.njet.dmactrl = 0;
outb(~TJ_AMD_IRQ, cs->hw.njet.base + NETJET_AUXCTRL);
outb(TJ_AMD_IRQ, cs->hw.njet.base + NETJET_IRQMASK1);
outb(cs->hw.njet.auxd, cs->hw.njet.auxa);
}
static int
enpci_card_msg(struct IsdnCardState *cs, int mt, void *arg)
{
u_long flags;
unsigned char *chan;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "enter:now PCI: card_msg: 0x%04X", mt);
switch (mt) {
case CARD_RESET:
spin_lock_irqsave(&cs->lock, flags);
reset_enpci(cs);
Amd7930_init(cs);
spin_unlock_irqrestore(&cs->lock, flags);
break;
case CARD_RELEASE:
release_io_netjet(cs);
break;
case CARD_INIT:
reset_enpci(cs);
inittiger(cs);
Amd7930_init(cs);
break;
case CARD_TEST:
break;
case MDL_ASSIGN:
cs->hw.njet.auxd = TJ_AMD_IRQ << 1;
outb(cs->hw.njet.auxd, cs->hw.njet.base + NETJET_AUXDATA);
break;
case MDL_REMOVE:
cs->hw.njet.auxd = 0;
outb(0x00, cs->hw.njet.base + NETJET_AUXDATA);
break;
case MDL_BC_ASSIGN:
chan = (unsigned char *)arg;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "enter:now PCI: assign phys. BC %d in AMD LMR1", *chan);
cs->dc.amd7930.ph_command(cs, (cs->dc.amd7930.lmr1 | (*chan + 1)), "MDL_BC_ASSIGN");
cs->hw.njet.auxd |= TJ_AMD_IRQ << 2;
outb(cs->hw.njet.auxd, cs->hw.njet.base + NETJET_AUXDATA);
break;
case MDL_BC_RELEASE:
chan = (unsigned char *)arg;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "enter:now PCI: release phys. BC %d in Amd LMR1", *chan);
cs->dc.amd7930.ph_command(cs, (cs->dc.amd7930.lmr1 & ~(*chan + 1)), "MDL_BC_RELEASE");
if (!(cs->dc.amd7930.lmr1 & 3)) {
cs->hw.njet.auxd &= ~(TJ_AMD_IRQ << 2);
outb(cs->hw.njet.auxd, cs->hw.njet.base + NETJET_AUXDATA);
}
break;
default:
break;
}
return(0);
}
static irqreturn_t
enpci_interrupt(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
unsigned char s0val, s1val, ir;
u_long flags;
spin_lock_irqsave(&cs->lock, flags);
s1val = inb(cs->hw.njet.base + NETJET_IRQSTAT1);
if (!(s1val & TJ_AMD_IRQ)) {
ir = ReadByteAmd7930(cs, 0x00);
Amd7930_interrupt(cs, ir);
s1val = 1;
} else
s1val = 0;
s0val = inb(cs->hw.njet.base + NETJET_IRQSTAT0);
if ((s0val | s1val)==0) {
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_NONE;
}
if (s0val)
outb(s0val, cs->hw.njet.base + NETJET_IRQSTAT0);
if (inl(cs->hw.njet.base + NETJET_DMA_WRITE_ADR) <
inl(cs->hw.njet.base + NETJET_DMA_WRITE_IRQ))
s0val = 0x08;
else
s0val = 0x04;
if (inl(cs->hw.njet.base + NETJET_DMA_READ_ADR) <
inl(cs->hw.njet.base + NETJET_DMA_READ_IRQ))
s0val = s0val | 0x02;
else
s0val = s0val | 0x01;
if (s0val != cs->hw.njet.last_is0)
{
if (test_and_set_bit(FLG_LOCK_ATOMIC, &cs->HW_Flags)) {
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
cs->hw.njet.irqstat0 = s0val;
if ((cs->hw.njet.irqstat0 & NETJET_IRQM0_READ) !=
(cs->hw.njet.last_is0 & NETJET_IRQM0_READ))
read_tiger(cs);
if ((cs->hw.njet.irqstat0 & NETJET_IRQM0_WRITE) !=
(cs->hw.njet.last_is0 & NETJET_IRQM0_WRITE))
write_tiger(cs);
test_and_clear_bit(FLG_LOCK_ATOMIC, &cs->HW_Flags);
}
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
static int __devinit en_pci_probe(struct pci_dev *dev_netjet,
struct IsdnCardState *cs)
{
if (pci_enable_device(dev_netjet))
return(0);
cs->irq = dev_netjet->irq;
if (!cs->irq) {
printk(KERN_WARNING "enter:now PCI: No IRQ for PCI card found\n");
return(0);
}
cs->hw.njet.base = pci_resource_start(dev_netjet, 0);
if (!cs->hw.njet.base) {
printk(KERN_WARNING "enter:now PCI: No IO-Adr for PCI card found\n");
return(0);
}
if ((dev_netjet->subsystem_vendor != 0x55) ||
(dev_netjet->subsystem_device != 0x02)) {
printk(KERN_WARNING "enter:now: You tried to load this driver with an incompatible TigerJet-card\n");
printk(KERN_WARNING "Use type=20 for Traverse NetJet PCI Card.\n");
return(0);
}
return(1);
}
static void __devinit en_cs_init(struct IsdnCard *card,
struct IsdnCardState *cs)
{
cs->hw.njet.auxa = cs->hw.njet.base + NETJET_AUXDATA;
cs->hw.njet.isac = cs->hw.njet.base + 0xC0;
cs->hw.njet.ctrl_reg = 0x07;
outb(cs->hw.njet.ctrl_reg, cs->hw.njet.base + NETJET_CTRL);
mdelay(20);
cs->hw.njet.ctrl_reg = 0x30;
outb(cs->hw.njet.ctrl_reg, cs->hw.njet.base + NETJET_CTRL);
mdelay(10);
cs->hw.njet.auxd = 0x00;
cs->hw.njet.dmactrl = 0;
outb(~TJ_AMD_IRQ, cs->hw.njet.base + NETJET_AUXCTRL);
outb(TJ_AMD_IRQ, cs->hw.njet.base + NETJET_IRQMASK1);
outb(cs->hw.njet.auxd, cs->hw.njet.auxa);
}
static int __devinit en_cs_init_rest(struct IsdnCard *card,
struct IsdnCardState *cs)
{
const int bytecnt = 256;
printk(KERN_INFO
"enter:now PCI: PCI card configured at 0x%lx IRQ %d\n",
cs->hw.njet.base, cs->irq);
if (!request_region(cs->hw.njet.base, bytecnt, "Fn_ISDN")) {
printk(KERN_WARNING
"HiSax: enter:now config port %lx-%lx already in use\n",
cs->hw.njet.base,
cs->hw.njet.base + bytecnt);
return (0);
}
setup_Amd7930(cs);
cs->hw.njet.last_is0 = 0;
cs->readisac = &ReadByteAmd7930;
cs->writeisac = &WriteByteAmd7930;
cs->dc.amd7930.setIrqMask = &enpci_setIrqMask;
cs->BC_Read_Reg = &dummyrr;
cs->BC_Write_Reg = &dummywr;
cs->BC_Send_Data = &netjet_fill_dma;
cs->cardmsg = &enpci_card_msg;
cs->irq_func = &enpci_interrupt;
cs->irq_flags |= IRQF_SHARED;
return (1);
}
int __devinit
setup_enternow_pci(struct IsdnCard *card)
{
int ret;
struct IsdnCardState *cs = card->cs;
char tmp[64];
#ifdef __BIG_ENDIAN
#error "not running on big endian machines now"
#endif
strcpy(tmp, enternow_pci_rev);
printk(KERN_INFO "HiSax: Formula-n Europe AG enter:now ISDN PCI driver Rev. %s\n", HiSax_getrev(tmp));
if (cs->typ != ISDN_CTYPE_ENTERNOW)
return(0);
test_and_clear_bit(FLG_LOCK_ATOMIC, &cs->HW_Flags);
for ( ;; )
{
if ((dev_netjet = hisax_find_pci_device(PCI_VENDOR_ID_TIGERJET,
PCI_DEVICE_ID_TIGERJET_300, dev_netjet))) {
ret = en_pci_probe(dev_netjet, cs);
if (!ret)
return(0);
} else {
printk(KERN_WARNING "enter:now PCI: No PCI card found\n");
return(0);
}
en_cs_init(card, cs);
break;
}
return en_cs_init_rest(card, cs);
}
