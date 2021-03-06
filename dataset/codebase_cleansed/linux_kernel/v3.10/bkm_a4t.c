static inline u_char
readreg(unsigned int ale, unsigned long adr, u_char off)
{
register u_int ret;
unsigned int *po = (unsigned int *) adr;
*po = (GCS_2 | PO_WRITE | off);
__WAITI20__(po);
*po = (ale | PO_READ);
__WAITI20__(po);
ret = *po;
return ((unsigned char) ret);
}
static inline void
readfifo(unsigned int ale, unsigned long adr, u_char off, u_char *data, int size)
{
int i;
for (i = 0; i < size; i++)
*data++ = readreg(ale, adr, off);
}
static inline void
writereg(unsigned int ale, unsigned long adr, u_char off, u_char data)
{
unsigned int *po = (unsigned int *) adr;
*po = (GCS_2 | PO_WRITE | off);
__WAITI20__(po);
*po = (ale | PO_WRITE | data);
__WAITI20__(po);
}
static inline void
writefifo(unsigned int ale, unsigned long adr, u_char off, u_char *data, int size)
{
int i;
for (i = 0; i < size; i++)
writereg(ale, adr, off, *data++);
}
static u_char
ReadISAC(struct IsdnCardState *cs, u_char offset)
{
return (readreg(cs->hw.ax.isac_ale, cs->hw.ax.isac_adr, offset));
}
static void
WriteISAC(struct IsdnCardState *cs, u_char offset, u_char value)
{
writereg(cs->hw.ax.isac_ale, cs->hw.ax.isac_adr, offset, value);
}
static void
ReadISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
readfifo(cs->hw.ax.isac_ale, cs->hw.ax.isac_adr, 0, data, size);
}
static void
WriteISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
writefifo(cs->hw.ax.isac_ale, cs->hw.ax.isac_adr, 0, data, size);
}
static u_char
ReadJADE(struct IsdnCardState *cs, int jade, u_char offset)
{
return (readreg(cs->hw.ax.jade_ale, cs->hw.ax.jade_adr, offset + (jade == -1 ? 0 : (jade ? 0xC0 : 0x80))));
}
static void
WriteJADE(struct IsdnCardState *cs, int jade, u_char offset, u_char value)
{
writereg(cs->hw.ax.jade_ale, cs->hw.ax.jade_adr, offset + (jade == -1 ? 0 : (jade ? 0xC0 : 0x80)), value);
}
static irqreturn_t
bkm_interrupt(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
u_char val = 0;
u_long flags;
I20_REGISTER_FILE *pI20_Regs;
spin_lock_irqsave(&cs->lock, flags);
pI20_Regs = (I20_REGISTER_FILE *) (cs->hw.ax.base);
if (pI20_Regs->i20IntStatus & intISDN) {
pI20_Regs->i20IntStatus = intISDN;
pI20_Regs->i20IntCtrl &= ~intISDN;
val = readreg(cs->hw.ax.jade_ale, cs->hw.ax.jade_adr, jade_HDLC_ISR + 0x80);
if (val) {
jade_int_main(cs, val, 0);
}
val = readreg(cs->hw.ax.jade_ale, cs->hw.ax.jade_adr, jade_HDLC_ISR + 0xC0);
if (val) {
jade_int_main(cs, val, 1);
}
val = readreg(cs->hw.ax.isac_ale, cs->hw.ax.isac_adr, ISAC_ISTA);
if (val) {
isac_interrupt(cs, val);
}
pI20_Regs->i20IntCtrl |= intISDN;
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
} else {
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_NONE;
}
}
static void
release_io_bkm(struct IsdnCardState *cs)
{
if (cs->hw.ax.base) {
iounmap((void *) cs->hw.ax.base);
cs->hw.ax.base = 0;
}
}
static void
enable_bkm_int(struct IsdnCardState *cs, unsigned bEnable)
{
if (cs->typ == ISDN_CTYPE_BKM_A4T) {
I20_REGISTER_FILE *pI20_Regs = (I20_REGISTER_FILE *) (cs->hw.ax.base);
if (bEnable)
pI20_Regs->i20IntCtrl |= (intISDN | intPCI);
else
pI20_Regs->i20IntCtrl &= ~(intISDN | intPCI);
}
}
static void
reset_bkm(struct IsdnCardState *cs)
{
if (cs->typ == ISDN_CTYPE_BKM_A4T) {
I20_REGISTER_FILE *pI20_Regs = (I20_REGISTER_FILE *) (cs->hw.ax.base);
pI20_Regs->i20SysControl = 0xFF;
mdelay(10);
pI20_Regs->i20SysControl = sysRESET | 0xFF;
mdelay(10);
pI20_Regs->i20SysControl = sysRESET | sysCFG;
pI20_Regs->i20GuestControl = guestWAIT_CFG |
g_A4T_JADE_RES |
g_A4T_ISAR_RES |
g_A4T_ISAC_RES |
g_A4T_JADE_BOOTR |
g_A4T_ISAR_BOOTR;
mdelay(10);
pI20_Regs->i20GuestControl &= ~(g_A4T_ISAC_RES |
g_A4T_JADE_RES |
g_A4T_ISAR_RES);
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
enable_bkm_int(cs, 0);
reset_bkm(cs);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_RELEASE:
spin_lock_irqsave(&cs->lock, flags);
enable_bkm_int(cs, 0);
reset_bkm(cs);
spin_unlock_irqrestore(&cs->lock, flags);
release_io_bkm(cs);
return (0);
case CARD_INIT:
spin_lock_irqsave(&cs->lock, flags);
clear_pending_isac_ints(cs);
clear_pending_jade_ints(cs);
initisac(cs);
initjade(cs);
enable_bkm_int(cs, 1);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_TEST:
return (0);
}
return (0);
}
static int a4t_pci_probe(struct pci_dev *dev_a4t, struct IsdnCardState *cs,
u_int *found, u_int *pci_memaddr)
{
u16 sub_sys;
u16 sub_vendor;
sub_vendor = dev_a4t->subsystem_vendor;
sub_sys = dev_a4t->subsystem_device;
if ((sub_sys == PCI_DEVICE_ID_BERKOM_A4T) && (sub_vendor == PCI_VENDOR_ID_BERKOM)) {
if (pci_enable_device(dev_a4t))
return (0);
*found = 1;
*pci_memaddr = pci_resource_start(dev_a4t, 0);
cs->irq = dev_a4t->irq;
return (1);
}
return (-1);
}
static int a4t_cs_init(struct IsdnCard *card, struct IsdnCardState *cs,
u_int pci_memaddr)
{
I20_REGISTER_FILE *pI20_Regs;
if (!cs->irq) {
printk(KERN_WARNING "HiSax: Telekom A4T: No IRQ\n");
return (0);
}
cs->hw.ax.base = (long) ioremap(pci_memaddr, 4096);
pI20_Regs = (I20_REGISTER_FILE *) (cs->hw.ax.base);
if ((pI20_Regs->i20IntStatus & 0x8EFFFFFF) != 0) {
printk(KERN_WARNING "HiSax: Telekom A4T address "
"%lx-%lx suspicious\n",
cs->hw.ax.base, cs->hw.ax.base + 4096);
iounmap((void *) cs->hw.ax.base);
cs->hw.ax.base = 0;
return (0);
}
cs->hw.ax.isac_adr = cs->hw.ax.base + PO_OFFSET;
cs->hw.ax.jade_adr = cs->hw.ax.base + PO_OFFSET;
cs->hw.ax.isac_ale = GCS_1;
cs->hw.ax.jade_ale = GCS_3;
printk(KERN_INFO "HiSax: Telekom A4T: Card configured at "
"0x%lX IRQ %d\n",
cs->hw.ax.base, cs->irq);
setup_isac(cs);
cs->readisac = &ReadISAC;
cs->writeisac = &WriteISAC;
cs->readisacfifo = &ReadISACfifo;
cs->writeisacfifo = &WriteISACfifo;
cs->BC_Read_Reg = &ReadJADE;
cs->BC_Write_Reg = &WriteJADE;
cs->BC_Send_Data = &jade_fill_fifo;
cs->cardmsg = &BKM_card_msg;
cs->irq_func = &bkm_interrupt;
cs->irq_flags |= IRQF_SHARED;
ISACVersion(cs, "Telekom A4T:");
JadeVersion(cs, "Telekom A4T:");
return (1);
}
int setup_bkm_a4t(struct IsdnCard *card)
{
struct IsdnCardState *cs = card->cs;
char tmp[64];
u_int pci_memaddr = 0, found = 0;
int ret;
strcpy(tmp, bkm_a4t_revision);
printk(KERN_INFO "HiSax: T-Berkom driver Rev. %s\n", HiSax_getrev(tmp));
if (cs->typ == ISDN_CTYPE_BKM_A4T) {
cs->subtyp = BKM_A4T;
} else
return (0);
while ((dev_a4t = hisax_find_pci_device(PCI_VENDOR_ID_ZORAN,
PCI_DEVICE_ID_ZORAN_36120, dev_a4t))) {
ret = a4t_pci_probe(dev_a4t, cs, &found, &pci_memaddr);
if (!ret)
return (0);
if (ret > 0)
break;
}
if (!found) {
printk(KERN_WARNING "HiSax: Telekom A4T: Card not found\n");
return (0);
}
if (!pci_memaddr) {
printk(KERN_WARNING "HiSax: Telekom A4T: "
"No Memory base address\n");
return (0);
}
return a4t_cs_init(card, cs, pci_memaddr);
}
