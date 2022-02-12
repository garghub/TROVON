static void quirk_ppc_currituck_usb_fixup(struct pci_dev *dev)
{
if (of_machine_is_compatible("ibm,currituck")) {
pci_write_config_dword(dev, 0xe0, 0x0114231f);
pci_write_config_dword(dev, 0xe4, 0x00006c40);
}
}
static int __init ppc47x_device_probe(void)
{
of_platform_bus_probe(NULL, ppc47x_of_bus, NULL);
return 0;
}
static void __init ppc47x_init_irq(void)
{
struct device_node *np;
for_each_node_with_property(np, "interrupt-controller") {
if (of_get_property(np, "interrupts", NULL) == NULL)
break;
}
if (np == NULL)
panic("Can't find top level interrupt controller");
if (of_device_is_compatible(np, "chrp,open-pic")) {
struct mpic *mpic =
mpic_alloc(np, 0, MPIC_NO_RESET, 0, 0, " MPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
ppc_md.get_irq = mpic_get_irq;
} else
panic("Unrecognized top level interrupt controller");
}
static void __cpuinit smp_ppc47x_setup_cpu(int cpu)
{
mpic_setup_this_cpu();
}
static int __cpuinit smp_ppc47x_kick_cpu(int cpu)
{
struct device_node *cpunode = of_get_cpu_node(cpu, NULL);
const u64 *spin_table_addr_prop;
u32 *spin_table;
extern void start_secondary_47x(void);
BUG_ON(cpunode == NULL);
spin_table_addr_prop =
of_get_property(cpunode, "cpu-release-addr", NULL);
if (spin_table_addr_prop == NULL) {
pr_err("CPU%d: Can't start, missing cpu-release-addr !\n",
cpu);
return 1;
}
spin_table = (u32 *)__va(*spin_table_addr_prop);
pr_debug("CPU%d: Spin table mapped at %p\n", cpu, spin_table);
spin_table[3] = cpu;
smp_wmb();
spin_table[1] = __pa(start_secondary_47x);
mb();
return 0;
}
static void __init ppc47x_smp_init(void)
{
if (mmu_has_feature(MMU_FTR_TYPE_47x))
smp_ops = &ppc47x_smp_ops;
}
static void __init ppc47x_smp_init(void) { }
static void __init ppc47x_setup_arch(void)
{
swiotlb_detect_4g();
ppc47x_smp_init();
}
static int __init ppc47x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,currituck"))
return 0;
return 1;
}
static void ppc47x_pci_irq_fixup(struct pci_dev *dev)
{
if (dev->vendor == 0x1033 && (dev->device == 0x0035 ||
dev->device == 0x00e0)) {
dev->irq = irq_create_mapping(NULL, 47);
pr_info("%s: Mapping irq 47 %d\n", __func__, dev->irq);
}
}
