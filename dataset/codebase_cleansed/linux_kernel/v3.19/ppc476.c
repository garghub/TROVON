static void quirk_ppc_currituck_usb_fixup(struct pci_dev *dev)
{
if (of_machine_is_compatible("ibm,currituck")) {
pci_write_config_dword(dev, 0xe0, 0x0114231f);
pci_write_config_dword(dev, 0xe4, 0x00006c40);
}
}
static void avr_halt_system(int pwrctl_flags)
{
i2c_smbus_write_byte_data(avr_i2c_client,
AVR_PWRCTL_CMD, pwrctl_flags);
while (1)
;
}
static void avr_power_off_system(void)
{
avr_halt_system(AVR_PWRCTL_PWROFF);
}
static void avr_reset_system(char *cmd)
{
avr_halt_system(AVR_PWRCTL_RESET);
}
static int avr_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
avr_i2c_client = client;
ppc_md.restart = avr_reset_system;
pm_power_off = avr_power_off_system;
return 0;
}
static int __init ppc47x_device_probe(void)
{
i2c_add_driver(&avr_driver);
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
static void smp_ppc47x_setup_cpu(int cpu)
{
mpic_setup_this_cpu();
}
static int smp_ppc47x_kick_cpu(int cpu)
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
static int __init ppc47x_get_board_rev(void)
{
int reg;
u8 *fpga;
struct device_node *np = NULL;
if (of_machine_is_compatible("ibm,currituck")) {
np = of_find_compatible_node(NULL, NULL, "ibm,currituck-fpga");
reg = 0;
} else if (of_machine_is_compatible("ibm,akebono")) {
np = of_find_compatible_node(NULL, NULL, "ibm,akebono-fpga");
reg = 2;
}
if (!np)
goto fail;
fpga = (u8 *) of_iomap(np, 0);
of_node_put(np);
if (!fpga)
goto fail;
board_rev = ioread8(fpga + reg) & 0x03;
pr_info("%s: Found board revision %d\n", __func__, board_rev);
iounmap(fpga);
return 0;
fail:
pr_info("%s: Unable to find board revision\n", __func__);
return 0;
}
static void ppc47x_pci_irq_fixup(struct pci_dev *dev)
{
if (dev->vendor == 0x1033 && (dev->device == 0x0035 ||
dev->device == 0x00e0)) {
if (board_rev == 0) {
dev->irq = irq_create_mapping(NULL, 47);
pr_info("%s: Mapping irq %d\n", __func__, dev->irq);
} else if (board_rev == 2) {
dev->irq = irq_create_mapping(NULL, 49);
pr_info("%s: Mapping irq %d\n", __func__, dev->irq);
} else {
pr_alert("%s: Unknown board revision\n", __func__);
}
}
}
static int __init ppc47x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "ibm,akebono"))
return 1;
if (of_flat_dt_is_compatible(root, "ibm,currituck")) {
ppc_md.pci_irq_fixup = ppc47x_pci_irq_fixup;
return 1;
}
return 0;
}
