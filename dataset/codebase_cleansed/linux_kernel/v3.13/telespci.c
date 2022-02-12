static inline u_char
readisac(void __iomem *adr, u_char off)
{
register unsigned int portdata;
ZORAN_WAIT_NOBUSY;
writel(WRITE_ADDR_ISAC | off, adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(READ_DATA_ISAC, adr + 0x200);
ZORAN_WAIT_NOBUSY;
return ((u_char)(portdata & ZORAN_PO_DMASK));
}
static inline void
writeisac(void __iomem *adr, u_char off, u_char data)
{
register unsigned int portdata;
ZORAN_WAIT_NOBUSY;
writel(WRITE_ADDR_ISAC | off, adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(WRITE_DATA_ISAC | data, adr + 0x200);
ZORAN_WAIT_NOBUSY;
}
static inline u_char
readhscx(void __iomem *adr, int hscx, u_char off)
{
register unsigned int portdata;
ZORAN_WAIT_NOBUSY;
writel(WRITE_ADDR_HSCX | ((hscx ? 0x40 : 0) + off), adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(READ_DATA_HSCX, adr + 0x200);
ZORAN_WAIT_NOBUSY;
return ((u_char)(portdata & ZORAN_PO_DMASK));
}
static inline void
writehscx(void __iomem *adr, int hscx, u_char off, u_char data)
{
register unsigned int portdata;
ZORAN_WAIT_NOBUSY;
writel(WRITE_ADDR_HSCX | ((hscx ? 0x40 : 0) + off), adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(WRITE_DATA_HSCX | data, adr + 0x200);
ZORAN_WAIT_NOBUSY;
}
static inline void
read_fifo_isac(void __iomem *adr, u_char *data, int size)
{
register unsigned int portdata;
register int i;
ZORAN_WAIT_NOBUSY;
for (i = 0; i < size; i++) {
writel(WRITE_ADDR_ISAC | 0x1E, adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(READ_DATA_ISAC, adr + 0x200);
ZORAN_WAIT_NOBUSY;
data[i] = (u_char)(portdata & ZORAN_PO_DMASK);
}
}
static void
write_fifo_isac(void __iomem *adr, u_char *data, int size)
{
register unsigned int portdata;
register int i;
ZORAN_WAIT_NOBUSY;
for (i = 0; i < size; i++) {
writel(WRITE_ADDR_ISAC | 0x1E, adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(WRITE_DATA_ISAC | data[i], adr + 0x200);
ZORAN_WAIT_NOBUSY;
}
}
static inline void
read_fifo_hscx(void __iomem *adr, int hscx, u_char *data, int size)
{
register unsigned int portdata;
register int i;
ZORAN_WAIT_NOBUSY;
for (i = 0; i < size; i++) {
writel(WRITE_ADDR_HSCX | (hscx ? 0x5F : 0x1F), adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(READ_DATA_HSCX, adr + 0x200);
ZORAN_WAIT_NOBUSY;
data[i] = (u_char) (portdata & ZORAN_PO_DMASK);
}
}
static inline void
write_fifo_hscx(void __iomem *adr, int hscx, u_char *data, int size)
{
unsigned int portdata;
register int i;
ZORAN_WAIT_NOBUSY;
for (i = 0; i < size; i++) {
writel(WRITE_ADDR_HSCX | (hscx ? 0x5F : 0x1F), adr + 0x200);
ZORAN_WAIT_NOBUSY;
writel(WRITE_DATA_HSCX | data[i], adr + 0x200);
ZORAN_WAIT_NOBUSY;
udelay(10);
}
}
static u_char
ReadISAC(struct IsdnCardState *cs, u_char offset)
{
return (readisac(cs->hw.teles0.membase, offset));
}
static void
WriteISAC(struct IsdnCardState *cs, u_char offset, u_char value)
{
writeisac(cs->hw.teles0.membase, offset, value);
}
static void
ReadISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
read_fifo_isac(cs->hw.teles0.membase, data, size);
}
static void
WriteISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
write_fifo_isac(cs->hw.teles0.membase, data, size);
}
static u_char
ReadHSCX(struct IsdnCardState *cs, int hscx, u_char offset)
{
return (readhscx(cs->hw.teles0.membase, hscx, offset));
}
static void
WriteHSCX(struct IsdnCardState *cs, int hscx, u_char offset, u_char value)
{
writehscx(cs->hw.teles0.membase, hscx, offset, value);
}
static irqreturn_t
telespci_interrupt(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
u_char hval, ival;
u_long flags;
spin_lock_irqsave(&cs->lock, flags);
hval = readhscx(cs->hw.teles0.membase, 1, HSCX_ISTA);
if (hval)
hscx_int_main(cs, hval);
ival = readisac(cs->hw.teles0.membase, ISAC_ISTA);
if ((hval | ival) == 0) {
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_NONE;
}
if (ival)
isac_interrupt(cs, ival);
writel(0x70000000, cs->hw.teles0.membase + 0x3C);
writehscx(cs->hw.teles0.membase, 0, HSCX_MASK, 0xFF);
writehscx(cs->hw.teles0.membase, 1, HSCX_MASK, 0xFF);
writeisac(cs->hw.teles0.membase, ISAC_MASK, 0xFF);
writeisac(cs->hw.teles0.membase, ISAC_MASK, 0x0);
writehscx(cs->hw.teles0.membase, 0, HSCX_MASK, 0x0);
writehscx(cs->hw.teles0.membase, 1, HSCX_MASK, 0x0);
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
static void
release_io_telespci(struct IsdnCardState *cs)
{
iounmap(cs->hw.teles0.membase);
}
static int
TelesPCI_card_msg(struct IsdnCardState *cs, int mt, void *arg)
{
u_long flags;
switch (mt) {
case CARD_RESET:
return (0);
case CARD_RELEASE:
release_io_telespci(cs);
return (0);
case CARD_INIT:
spin_lock_irqsave(&cs->lock, flags);
inithscxisac(cs, 3);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_TEST:
return (0);
}
return (0);
}
int setup_telespci(struct IsdnCard *card)
{
struct IsdnCardState *cs = card->cs;
char tmp[64];
strcpy(tmp, telespci_revision);
printk(KERN_INFO "HiSax: Teles/PCI driver Rev. %s\n", HiSax_getrev(tmp));
if (cs->typ != ISDN_CTYPE_TELESPCI)
return (0);
if ((dev_tel = hisax_find_pci_device(PCI_VENDOR_ID_ZORAN, PCI_DEVICE_ID_ZORAN_36120, dev_tel))) {
if (pci_enable_device(dev_tel))
return (0);
cs->irq = dev_tel->irq;
if (!cs->irq) {
printk(KERN_WARNING "Teles: No IRQ for PCI card found\n");
return (0);
}
cs->hw.teles0.membase = ioremap(pci_resource_start(dev_tel, 0),
PAGE_SIZE);
printk(KERN_INFO "Found: Zoran, base-address: 0x%llx, irq: 0x%x\n",
(unsigned long long)pci_resource_start(dev_tel, 0),
dev_tel->irq);
} else {
printk(KERN_WARNING "TelesPCI: No PCI card found\n");
return (0);
}
writel(0x00000000, cs->hw.teles0.membase + 0x28);
writel(0x01000000, cs->hw.teles0.membase + 0x28);
writel(0x01000000, cs->hw.teles0.membase + 0x28);
writel(0x7BFFFFFF, cs->hw.teles0.membase + 0x2C);
writel(0x70000000, cs->hw.teles0.membase + 0x3C);
writel(0x61000000, cs->hw.teles0.membase + 0x40);
printk(KERN_INFO
"HiSax: Teles PCI config irq:%d mem:%p\n",
cs->irq,
cs->hw.teles0.membase);
setup_isac(cs);
cs->readisac = &ReadISAC;
cs->writeisac = &WriteISAC;
cs->readisacfifo = &ReadISACfifo;
cs->writeisacfifo = &WriteISACfifo;
cs->BC_Read_Reg = &ReadHSCX;
cs->BC_Write_Reg = &WriteHSCX;
cs->BC_Send_Data = &hscx_fill_fifo;
cs->cardmsg = &TelesPCI_card_msg;
cs->irq_func = &telespci_interrupt;
cs->irq_flags |= IRQF_SHARED;
ISACVersion(cs, "TelesPCI:");
if (HscxVersion(cs, "TelesPCI:")) {
printk(KERN_WARNING
"TelesPCI: wrong HSCX versions check IO/MEM addresses\n");
release_io_telespci(cs);
return (0);
}
return (1);
}
