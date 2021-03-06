static void mod_wired_entry(int entry, unsigned long entrylo0,
unsigned long entrylo1, unsigned long entryhi,
unsigned long pagemask)
{
unsigned long old_pagemask;
unsigned long old_ctx;
old_ctx = read_c0_entryhi() & 0xff;
old_pagemask = read_c0_pagemask();
write_c0_index(entry);
write_c0_pagemask(pagemask);
write_c0_entryhi(entryhi);
write_c0_entrylo0(entrylo0);
write_c0_entrylo1(entrylo1);
tlb_write_indexed();
write_c0_entryhi(old_ctx);
write_c0_pagemask(old_pagemask);
}
static void alchemy_pci_wired_entry(struct alchemy_pci_context *ctx)
{
ctx->wired_entry = read_c0_wired();
add_wired_entry(0, 0, (unsigned long)ctx->pci_cfg_vm->addr, PM_4K);
ctx->last_elo0 = ctx->last_elo1 = ~0;
}
static int config_access(unsigned char access_type, struct pci_bus *bus,
unsigned int dev_fn, unsigned char where, u32 *data)
{
struct alchemy_pci_context *ctx = bus->sysdata;
unsigned int device = PCI_SLOT(dev_fn);
unsigned int function = PCI_FUNC(dev_fn);
unsigned long offset, status, cfg_base, flags, entryLo0, entryLo1, r;
int error = PCIBIOS_SUCCESSFUL;
if (device > 19) {
*data = 0xffffffff;
return -1;
}
local_irq_save(flags);
r = __raw_readl(ctx->regs + PCI_REG_STATCMD) & 0x0000ffff;
r |= PCI_STATCMD_STATUS(0x2000);
__raw_writel(r, ctx->regs + PCI_REG_STATCMD);
wmb();
if (ctx->board_pci_idsel(device, 1) == 0) {
*data = 0xffffffff;
local_irq_restore(flags);
return -1;
}
if (bus->number == 0)
cfg_base = (1 << device) << 11;
else
cfg_base = 0x80000000 | (bus->number << 16) | (device << 11);
offset = (function << 8) | (where & ~0x3);
offset |= cfg_base & ~PAGE_MASK;
cfg_base = cfg_base & PAGE_MASK;
entryLo0 = (6 << 26) | (cfg_base >> 6) | (2 << 3) | 7;
entryLo1 = (6 << 26) | (cfg_base >> 6) | (0x1000 >> 6) | (2 << 3) | 7;
if ((entryLo0 != ctx->last_elo0) || (entryLo1 != ctx->last_elo1)) {
mod_wired_entry(ctx->wired_entry, entryLo0, entryLo1,
(unsigned long)ctx->pci_cfg_vm->addr, PM_4K);
ctx->last_elo0 = entryLo0;
ctx->last_elo1 = entryLo1;
}
if (access_type == PCI_ACCESS_WRITE)
__raw_writel(*data, ctx->pci_cfg_vm->addr + offset);
else
*data = __raw_readl(ctx->pci_cfg_vm->addr + offset);
wmb();
DBG("alchemy-pci: cfg access %d bus %u dev %u at %x dat %x conf %lx\n",
access_type, bus->number, device, where, *data, offset);
status = __raw_readl(ctx->regs + PCI_REG_STATCMD);
if (status & (1 << 29)) {
*data = 0xffffffff;
error = -1;
DBG("alchemy-pci: master abort on cfg access %d bus %d dev %d\n",
access_type, bus->number, device);
} else if ((status >> 28) & 0xf) {
DBG("alchemy-pci: PCI ERR detected: dev %d, status %lx\n",
device, (status >> 28) & 0xf);
__raw_writel(status & 0xf000ffff, ctx->regs + PCI_REG_STATCMD);
*data = 0xffffffff;
error = -1;
}
(void)ctx->board_pci_idsel(device, 0);
local_irq_restore(flags);
return error;
}
static int read_config_byte(struct pci_bus *bus, unsigned int devfn,
int where, u8 *val)
{
u32 data;
int ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
if (where & 1)
data >>= 8;
if (where & 2)
data >>= 16;
*val = data & 0xff;
return ret;
}
static int read_config_word(struct pci_bus *bus, unsigned int devfn,
int where, u16 *val)
{
u32 data;
int ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
if (where & 2)
data >>= 16;
*val = data & 0xffff;
return ret;
}
static int read_config_dword(struct pci_bus *bus, unsigned int devfn,
int where, u32 *val)
{
return config_access(PCI_ACCESS_READ, bus, devfn, where, val);
}
static int write_config_byte(struct pci_bus *bus, unsigned int devfn,
int where, u8 val)
{
u32 data = 0;
if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
return -1;
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
static int write_config_word(struct pci_bus *bus, unsigned int devfn,
int where, u16 val)
{
u32 data = 0;
if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
return -1;
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
static int write_config_dword(struct pci_bus *bus, unsigned int devfn,
int where, u32 val)
{
return config_access(PCI_ACCESS_WRITE, bus, devfn, where, &val);
}
static int alchemy_pci_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
switch (size) {
case 1: {
u8 _val;
int rc = read_config_byte(bus, devfn, where, &_val);
*val = _val;
return rc;
}
case 2: {
u16 _val;
int rc = read_config_word(bus, devfn, where, &_val);
*val = _val;
return rc;
}
default:
return read_config_dword(bus, devfn, where, val);
}
}
static int alchemy_pci_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
switch (size) {
case 1:
return write_config_byte(bus, devfn, where, (u8) val);
case 2:
return write_config_word(bus, devfn, where, (u16) val);
default:
return write_config_dword(bus, devfn, where, val);
}
}
static int alchemy_pci_def_idsel(unsigned int devsel, int assert)
{
return 1;
}
static int alchemy_pci_suspend(void)
{
struct alchemy_pci_context *ctx = __alchemy_pci_ctx;
if (!ctx)
return 0;
ctx->pm[0] = __raw_readl(ctx->regs + PCI_REG_CMEM);
ctx->pm[1] = __raw_readl(ctx->regs + PCI_REG_CONFIG) & 0x0009ffff;
ctx->pm[2] = __raw_readl(ctx->regs + PCI_REG_B2BMASK_CCH);
ctx->pm[3] = __raw_readl(ctx->regs + PCI_REG_B2BBASE0_VID);
ctx->pm[4] = __raw_readl(ctx->regs + PCI_REG_B2BBASE1_SID);
ctx->pm[5] = __raw_readl(ctx->regs + PCI_REG_MWMASK_DEV);
ctx->pm[6] = __raw_readl(ctx->regs + PCI_REG_MWBASE_REV_CCL);
ctx->pm[7] = __raw_readl(ctx->regs + PCI_REG_ID);
ctx->pm[8] = __raw_readl(ctx->regs + PCI_REG_CLASSREV);
ctx->pm[9] = __raw_readl(ctx->regs + PCI_REG_PARAM);
ctx->pm[10] = __raw_readl(ctx->regs + PCI_REG_MBAR);
ctx->pm[11] = __raw_readl(ctx->regs + PCI_REG_TIMEOUT);
return 0;
}
static void alchemy_pci_resume(void)
{
struct alchemy_pci_context *ctx = __alchemy_pci_ctx;
if (!ctx)
return;
__raw_writel(ctx->pm[0], ctx->regs + PCI_REG_CMEM);
__raw_writel(ctx->pm[2], ctx->regs + PCI_REG_B2BMASK_CCH);
__raw_writel(ctx->pm[3], ctx->regs + PCI_REG_B2BBASE0_VID);
__raw_writel(ctx->pm[4], ctx->regs + PCI_REG_B2BBASE1_SID);
__raw_writel(ctx->pm[5], ctx->regs + PCI_REG_MWMASK_DEV);
__raw_writel(ctx->pm[6], ctx->regs + PCI_REG_MWBASE_REV_CCL);
__raw_writel(ctx->pm[7], ctx->regs + PCI_REG_ID);
__raw_writel(ctx->pm[8], ctx->regs + PCI_REG_CLASSREV);
__raw_writel(ctx->pm[9], ctx->regs + PCI_REG_PARAM);
__raw_writel(ctx->pm[10], ctx->regs + PCI_REG_MBAR);
__raw_writel(ctx->pm[11], ctx->regs + PCI_REG_TIMEOUT);
wmb();
__raw_writel(ctx->pm[1], ctx->regs + PCI_REG_CONFIG);
wmb();
ctx->wired_entry = 8191;
alchemy_pci_wired_entry(ctx);
}
static int alchemy_pci_probe(struct platform_device *pdev)
{
struct alchemy_pci_platdata *pd = pdev->dev.platform_data;
struct alchemy_pci_context *ctx;
void __iomem *virt_io;
unsigned long val;
struct resource *r;
int ret;
if (!pd) {
dev_err(&pdev->dev, "need platform data for PCI setup\n");
ret = -ENODEV;
goto out;
}
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
dev_err(&pdev->dev, "no memory for pcictl context\n");
ret = -ENOMEM;
goto out;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no pcictl ctrl regs resource\n");
ret = -ENODEV;
goto out1;
}
if (!request_mem_region(r->start, resource_size(r), pdev->name)) {
dev_err(&pdev->dev, "cannot claim pci regs\n");
ret = -ENODEV;
goto out1;
}
ctx->regs = ioremap_nocache(r->start, resource_size(r));
if (!ctx->regs) {
dev_err(&pdev->dev, "cannot map pci regs\n");
ret = -ENODEV;
goto out2;
}
virt_io = ioremap(AU1500_PCI_IO_PHYS_ADDR, 0x00100000);
if (!virt_io) {
dev_err(&pdev->dev, "cannot remap pci io space\n");
ret = -ENODEV;
goto out3;
}
ctx->alchemy_pci_ctrl.io_map_base = (unsigned long)virt_io;
if ((alchemy_get_cputype() == ALCHEMY_CPU_AU1500) &&
(read_c0_prid() < 0x01030202) && !coherentio) {
val = __raw_readl(ctx->regs + PCI_REG_CONFIG);
val |= PCI_CONFIG_NC;
__raw_writel(val, ctx->regs + PCI_REG_CONFIG);
wmb();
dev_info(&pdev->dev, "non-coherent PCI on Au1500 AA/AB/AC\n");
}
if (pd->board_map_irq)
ctx->board_map_irq = pd->board_map_irq;
if (pd->board_pci_idsel)
ctx->board_pci_idsel = pd->board_pci_idsel;
else
ctx->board_pci_idsel = alchemy_pci_def_idsel;
ctx->alchemy_pci_ctrl.pci_ops = &alchemy_pci_ops;
ctx->alchemy_pci_ctrl.mem_resource = &alchemy_pci_def_memres;
ctx->alchemy_pci_ctrl.io_resource = &alchemy_pci_def_iores;
ctx->pci_cfg_vm = get_vm_area(0x2000, VM_IOREMAP);
if (!ctx->pci_cfg_vm) {
dev_err(&pdev->dev, "unable to get vm area\n");
ret = -ENOMEM;
goto out4;
}
ctx->wired_entry = 8191;
alchemy_pci_wired_entry(ctx);
set_io_port_base((unsigned long)ctx->alchemy_pci_ctrl.io_map_base);
val = __raw_readl(ctx->regs + PCI_REG_CONFIG);
val &= ~pd->pci_cfg_clr;
val |= pd->pci_cfg_set;
val &= ~PCI_CONFIG_PD;
__raw_writel(val, ctx->regs + PCI_REG_CONFIG);
wmb();
__alchemy_pci_ctx = ctx;
platform_set_drvdata(pdev, ctx);
register_syscore_ops(&alchemy_pci_pmops);
register_pci_controller(&ctx->alchemy_pci_ctrl);
return 0;
out4:
iounmap(virt_io);
out3:
iounmap(ctx->regs);
out2:
release_mem_region(r->start, resource_size(r));
out1:
kfree(ctx);
out:
return ret;
}
static int __init alchemy_pci_init(void)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1500:
case ALCHEMY_CPU_AU1550:
return platform_driver_register(&alchemy_pcictl_driver);
}
return 0;
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct alchemy_pci_context *ctx = dev->sysdata;
if (ctx && ctx->board_map_irq)
return ctx->board_map_irq(dev, slot, pin);
return -1;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
