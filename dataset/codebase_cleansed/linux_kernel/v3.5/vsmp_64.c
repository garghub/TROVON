static unsigned long vsmp_save_fl(void)
{
unsigned long flags = native_save_fl();
if (!(flags & X86_EFLAGS_IF) || (flags & X86_EFLAGS_AC))
flags &= ~X86_EFLAGS_IF;
return flags;
}
static void vsmp_restore_fl(unsigned long flags)
{
if (flags & X86_EFLAGS_IF)
flags &= ~X86_EFLAGS_AC;
else
flags |= X86_EFLAGS_AC;
native_restore_fl(flags);
}
static void vsmp_irq_disable(void)
{
unsigned long flags = native_save_fl();
native_restore_fl((flags & ~X86_EFLAGS_IF) | X86_EFLAGS_AC);
}
static void vsmp_irq_enable(void)
{
unsigned long flags = native_save_fl();
native_restore_fl((flags | X86_EFLAGS_IF) & (~X86_EFLAGS_AC));
}
static unsigned __init_or_module vsmp_patch(u8 type, u16 clobbers, void *ibuf,
unsigned long addr, unsigned len)
{
switch (type) {
case PARAVIRT_PATCH(pv_irq_ops.irq_enable):
case PARAVIRT_PATCH(pv_irq_ops.irq_disable):
case PARAVIRT_PATCH(pv_irq_ops.save_fl):
case PARAVIRT_PATCH(pv_irq_ops.restore_fl):
return paravirt_patch_default(type, clobbers, ibuf, addr, len);
default:
return native_patch(type, clobbers, ibuf, addr, len);
}
}
static void __init set_vsmp_pv_ops(void)
{
void __iomem *address;
unsigned int cap, ctl, cfg;
cfg = read_pci_config(0, 0x1f, 0, PCI_BASE_ADDRESS_0);
address = early_ioremap(cfg, 8);
cap = readl(address);
ctl = readl(address + 4);
printk(KERN_INFO "vSMP CTL: capabilities:0x%08x control:0x%08x\n",
cap, ctl);
if (cap & ctl & (1 << 4)) {
pv_irq_ops.irq_disable = PV_CALLEE_SAVE(vsmp_irq_disable);
pv_irq_ops.irq_enable = PV_CALLEE_SAVE(vsmp_irq_enable);
pv_irq_ops.save_fl = PV_CALLEE_SAVE(vsmp_save_fl);
pv_irq_ops.restore_fl = PV_CALLEE_SAVE(vsmp_restore_fl);
pv_init_ops.patch = vsmp_patch;
ctl &= ~(1 << 4);
writel(ctl, address + 4);
ctl = readl(address + 4);
printk(KERN_INFO "vSMP CTL: control set to:0x%08x\n", ctl);
}
early_iounmap(address, 8);
}
static void __init set_vsmp_pv_ops(void)
{
}
static void __init detect_vsmp_box(void)
{
is_vsmp = 0;
if (!early_pci_allowed())
return;
if (read_pci_config(0, 0x1f, 0, PCI_VENDOR_ID) ==
(PCI_VENDOR_ID_SCALEMP | (PCI_DEVICE_ID_SCALEMP_VSMP_CTL << 16)))
is_vsmp = 1;
}
int is_vsmp_box(void)
{
if (is_vsmp != -1)
return is_vsmp;
else {
WARN_ON_ONCE(1);
return 0;
}
}
static void __init detect_vsmp_box(void)
{
}
int is_vsmp_box(void)
{
return 0;
}
static void __init vsmp_cap_cpus(void)
{
#if !defined(CONFIG_X86_VSMP) && defined(CONFIG_SMP)
void __iomem *address;
unsigned int cfg, topology, node_shift, maxcpus;
if (setup_max_cpus != NR_CPUS)
return;
cfg = read_pci_config(0, 0x1f, 0, PCI_BASE_ADDRESS_0);
address = early_ioremap(cfg + TOPOLOGY_REGISTER_OFFSET, 4);
if (WARN_ON(!address))
return;
topology = readl(address);
node_shift = (topology >> 16) & 0x7;
if (!node_shift)
node_shift = 8;
maxcpus = (topology & ((1 << node_shift) - 1)) + 1;
pr_info("vSMP CTL: Capping CPUs to %d (CONFIG_X86_VSMP is unset)\n",
maxcpus);
setup_max_cpus = maxcpus;
early_iounmap(address, 4);
#endif
}
void __init vsmp_init(void)
{
detect_vsmp_box();
if (!is_vsmp_box())
return;
vsmp_cap_cpus();
set_vsmp_pv_ops();
return;
}
