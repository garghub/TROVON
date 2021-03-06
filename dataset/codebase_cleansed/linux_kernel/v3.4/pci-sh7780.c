static irqreturn_t sh7780_pci_err_irq(int irq, void *dev_id)
{
struct pci_channel *hose = dev_id;
unsigned long addr;
unsigned int status;
unsigned int cmd;
int i;
addr = __raw_readl(hose->reg_base + SH4_PCIALR);
status = __raw_readw(hose->reg_base + PCI_STATUS);
if (status & (PCI_STATUS_PARITY |
PCI_STATUS_DETECTED_PARITY |
PCI_STATUS_SIG_TARGET_ABORT |
PCI_STATUS_REC_TARGET_ABORT |
PCI_STATUS_REC_MASTER_ABORT)) {
cmd = pcibios_handle_status_errors(addr, status, hose);
if (likely(cmd))
__raw_writew(cmd, hose->reg_base + PCI_STATUS);
}
status = __raw_readl(hose->reg_base + SH4_PCIAINT);
for (i = cmd = 0; i < ARRAY_SIZE(pci_arbiter_errors); i++) {
if (status & pci_arbiter_errors[i].mask) {
printk(KERN_DEBUG "PCI: %s, addr=%08lx\n",
pci_arbiter_errors[i].str, addr);
cmd |= pci_arbiter_errors[i].mask;
}
}
__raw_writel(cmd, hose->reg_base + SH4_PCIAINT);
status = __raw_readl(hose->reg_base + SH4_PCIINT);
for (i = cmd = 0; i < ARRAY_SIZE(pci_interrupt_errors); i++) {
if (status & pci_interrupt_errors[i].mask) {
printk(KERN_DEBUG "PCI: %s, addr=%08lx\n",
pci_interrupt_errors[i].str, addr);
cmd |= pci_interrupt_errors[i].mask;
}
}
__raw_writel(cmd, hose->reg_base + SH4_PCIINT);
return IRQ_HANDLED;
}
static irqreturn_t sh7780_pci_serr_irq(int irq, void *dev_id)
{
struct pci_channel *hose = dev_id;
printk(KERN_DEBUG "PCI: system error received: ");
pcibios_report_status(PCI_STATUS_SIG_SYSTEM_ERROR, 1);
printk("\n");
__raw_writel(SH4_PCIINTM_SDIM, hose->reg_base + SH4_PCIINTM);
disable_irq_nosync(irq);
hose->serr_timer.expires = jiffies + HZ;
add_timer(&hose->serr_timer);
return IRQ_HANDLED;
}
static int __init sh7780_pci_setup_irqs(struct pci_channel *hose)
{
int ret;
__raw_writel(0, hose->reg_base + SH4_PCIAINT);
__raw_writew(PCI_STATUS_DETECTED_PARITY | \
PCI_STATUS_SIG_SYSTEM_ERROR | \
PCI_STATUS_REC_MASTER_ABORT | \
PCI_STATUS_REC_TARGET_ABORT | \
PCI_STATUS_SIG_TARGET_ABORT | \
PCI_STATUS_PARITY, hose->reg_base + PCI_STATUS);
ret = request_irq(hose->serr_irq, sh7780_pci_serr_irq, 0,
"PCI SERR interrupt", hose);
if (unlikely(ret)) {
printk(KERN_ERR "PCI: Failed hooking SERR IRQ\n");
return ret;
}
ret = request_irq(hose->err_irq, sh7780_pci_err_irq, IRQF_SHARED,
"PCI ERR interrupt", hose);
if (unlikely(ret)) {
free_irq(hose->serr_irq, hose);
return ret;
}
__raw_writel(SH4_PCIAINT_MBKN | SH4_PCIAINT_TBTO | SH4_PCIAINT_MBTO | \
SH4_PCIAINT_TABT | SH4_PCIAINT_MABT | SH4_PCIAINT_RDPE | \
SH4_PCIAINT_WDPE, hose->reg_base + SH4_PCIAINTM);
__raw_writel(SH4_PCIINTM_TTADIM | SH4_PCIINTM_TMTOIM | \
SH4_PCIINTM_MDEIM | SH4_PCIINTM_APEDIM | \
SH4_PCIINTM_SDIM | SH4_PCIINTM_DPEITWM | \
SH4_PCIINTM_PEDITRM | SH4_PCIINTM_TADIMM | \
SH4_PCIINTM_MADIMM | SH4_PCIINTM_MWPDIM | \
SH4_PCIINTM_MRDPEIM, hose->reg_base + SH4_PCIINTM);
return ret;
}
static inline void __init sh7780_pci_teardown_irqs(struct pci_channel *hose)
{
free_irq(hose->err_irq, hose);
free_irq(hose->serr_irq, hose);
}
static void __init sh7780_pci66_init(struct pci_channel *hose)
{
unsigned int tmp;
if (!pci_is_66mhz_capable(hose, 0, 0))
return;
tmp = __raw_readl(hose->reg_base + SH4_PCICR);
tmp |= SH4_PCICR_PREFIX;
__raw_writel(tmp, hose->reg_base + SH4_PCICR);
tmp = __raw_readw(hose->reg_base + PCI_STATUS);
tmp |= PCI_STATUS_66MHZ;
__raw_writew(tmp, hose->reg_base + PCI_STATUS);
tmp = __raw_readl(hose->reg_base + SH4_PCICR);
tmp |= SH4_PCICR_PREFIX | SH4_PCICR_CFIN;
__raw_writel(tmp, hose->reg_base + SH4_PCICR);
}
static int __init sh7780_pci_init(void)
{
struct pci_channel *chan = &sh7780_pci_controller;
phys_addr_t memphys;
size_t memsize;
unsigned int id;
const char *type;
int ret, i;
printk(KERN_NOTICE "PCI: Starting initialization.\n");
chan->reg_base = 0xfe040000;
__raw_writel(PCIECR_ENBL, PCIECR);
__raw_writel(SH4_PCICR_PREFIX | SH4_PCICR_PRST | PCICR_ENDIANNESS,
chan->reg_base + SH4_PCICR);
mdelay(100);
id = __raw_readw(chan->reg_base + PCI_VENDOR_ID);
if (id != PCI_VENDOR_ID_RENESAS) {
printk(KERN_ERR "PCI: Unknown vendor ID 0x%04x.\n", id);
return -ENODEV;
}
id = __raw_readw(chan->reg_base + PCI_DEVICE_ID);
type = (id == PCI_DEVICE_ID_RENESAS_SH7763) ? "SH7763" :
(id == PCI_DEVICE_ID_RENESAS_SH7780) ? "SH7780" :
(id == PCI_DEVICE_ID_RENESAS_SH7781) ? "SH7781" :
(id == PCI_DEVICE_ID_RENESAS_SH7785) ? "SH7785" :
NULL;
if (unlikely(!type)) {
printk(KERN_ERR "PCI: Found an unsupported Renesas host "
"controller, device id 0x%04x.\n", id);
return -EINVAL;
}
printk(KERN_NOTICE "PCI: Found a Renesas %s host "
"controller, revision %d.\n", type,
__raw_readb(chan->reg_base + PCI_REVISION_ID));
__raw_writel(SH4_PCICR_PREFIX | PCICR_ENDIANNESS,
chan->reg_base + SH4_PCICR);
memphys = __pa(memory_start);
memsize = roundup_pow_of_two(memory_end - memory_start);
if (memsize > SZ_512M) {
__raw_writel(memphys + SZ_512M, chan->reg_base + SH4_PCILAR1);
__raw_writel((((memsize - SZ_512M) - SZ_1M) & 0x1ff00000) | 1,
chan->reg_base + SH4_PCILSR1);
memsize = SZ_512M;
} else {
__raw_writel(0, chan->reg_base + SH4_PCILAR1);
__raw_writel(0, chan->reg_base + SH4_PCILSR1);
}
__raw_writel(memphys, chan->reg_base + SH4_PCILAR0);
__raw_writel(((memsize - SZ_1M) & 0x1ff00000) | 1,
chan->reg_base + SH4_PCILSR0);
ret = sh7780_pci_setup_irqs(chan);
if (unlikely(ret))
return ret;
__raw_writel(0, chan->reg_base + SH7780_PCICSCR0);
__raw_writel(0, chan->reg_base + SH7780_PCICSAR0);
__raw_writel(0, chan->reg_base + SH7780_PCICSCR1);
__raw_writel(0, chan->reg_base + SH7780_PCICSAR1);
for (i = 1; i < chan->nr_resources; i++) {
struct resource *res = chan->resources + i;
resource_size_t size;
if (unlikely(res->flags & IORESOURCE_IO))
continue;
if ((res->flags & IORESOURCE_MEM_32BIT) && __in_29bit_mode()) {
chan->nr_resources--;
continue;
}
size = resource_size(res);
__raw_writel(((roundup_pow_of_two(size) / SZ_256K) - 1) << 18,
chan->reg_base + SH7780_PCIMBMR(i - 1));
__raw_writel(res->start, chan->reg_base + SH7780_PCIMBR(i - 1));
}
__raw_writel(0, chan->reg_base + PCI_BASE_ADDRESS_0);
__raw_writel(0, chan->reg_base + SH7780_PCIIOBR);
__raw_writel(0, chan->reg_base + SH7780_PCIIOBMR);
__raw_writew(PCI_COMMAND_SERR | PCI_COMMAND_WAIT | \
PCI_COMMAND_PARITY | PCI_COMMAND_MASTER | \
PCI_COMMAND_MEMORY, chan->reg_base + PCI_COMMAND);
__raw_writel(SH4_PCICR_PREFIX | SH4_PCICR_CFIN | SH4_PCICR_FTO |
PCICR_ENDIANNESS,
chan->reg_base + SH4_PCICR);
ret = register_pci_controller(chan);
if (unlikely(ret))
goto err;
sh7780_pci66_init(chan);
printk(KERN_NOTICE "PCI: Running at %dMHz.\n",
(__raw_readw(chan->reg_base + PCI_STATUS) & PCI_STATUS_66MHZ) ?
66 : 33);
return 0;
err:
sh7780_pci_teardown_irqs(chan);
return ret;
}
