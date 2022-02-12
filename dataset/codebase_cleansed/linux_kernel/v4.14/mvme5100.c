static void mvme5100_8259_cascade(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq = i8259_irq();
if (cascade_irq)
generic_handle_irq(cascade_irq);
chip->irq_eoi(&desc->irq_data);
}
static void __init mvme5100_pic_init(void)
{
struct mpic *mpic;
struct device_node *np;
struct device_node *cp = NULL;
unsigned int cirq;
unsigned long intack = 0;
const u32 *prop = NULL;
np = of_find_node_by_type(NULL, "open-pic");
if (!np) {
pr_err("Could not find open-pic node\n");
return;
}
mpic = mpic_alloc(np, pci_membase, 0, 16, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_assign_isu(mpic, 0, pci_membase + 0x10000);
mpic_init(mpic);
cp = of_find_compatible_node(NULL, NULL, "chrp,iic");
if (cp == NULL) {
pr_warn("mvme5100_pic_init: couldn't find i8259\n");
return;
}
cirq = irq_of_parse_and_map(cp, 0);
if (!cirq) {
pr_warn("mvme5100_pic_init: no cascade interrupt?\n");
return;
}
np = of_find_compatible_node(NULL, "pci", "mpc10x-pci");
if (np) {
prop = of_get_property(np, "8259-interrupt-acknowledge", NULL);
if (prop)
intack = prop[0];
of_node_put(np);
}
if (intack)
pr_debug("mvme5100_pic_init: PCI 8259 intack at 0x%016lx\n",
intack);
i8259_init(cp, intack);
of_node_put(cp);
irq_set_chained_handler(cirq, mvme5100_8259_cascade);
}
static int __init mvme5100_add_bridge(struct device_node *dev)
{
const int *bus_range;
int len;
struct pci_controller *hose;
unsigned short devid;
pr_info("Adding PCI host bridge %pOF\n", dev);
bus_range = of_get_property(dev, "bus-range", &len);
hose = pcibios_alloc_controller(dev);
if (hose == NULL)
return -ENOMEM;
hose->first_busno = bus_range ? bus_range[0] : 0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
setup_indirect_pci(hose, 0xfe000cf8, 0xfe000cfc, 0);
pci_process_bridge_OF_ranges(hose, dev, 1);
early_read_config_word(hose, 0, 0, PCI_DEVICE_ID, &devid);
if (devid != PCI_DEVICE_ID_MOTOROLA_HAWK) {
pr_err("HAWK PHB not present?\n");
return 0;
}
early_read_config_dword(hose, 0, 0, PCI_BASE_ADDRESS_1, &pci_membase);
if (pci_membase == 0) {
pr_err("HAWK PHB mibar not correctly set?\n");
return 0;
}
pr_info("mvme5100_pic_init: pci_membase: %x\n", pci_membase);
return 0;
}
static void __init mvme5100_setup_arch(void)
{
struct device_node *np;
if (ppc_md.progress)
ppc_md.progress("mvme5100_setup_arch()", 0);
for_each_compatible_node(np, "pci", "hawk-pci")
mvme5100_add_bridge(np);
restart = ioremap(BOARD_MODRST_REG, 4);
}
static void mvme5100_show_cpuinfo(struct seq_file *m)
{
seq_puts(m, "Vendor\t\t: Motorola/Emerson\n");
seq_puts(m, "Machine\t\t: MVME5100\n");
}
static void __noreturn mvme5100_restart(char *cmd)
{
local_irq_disable();
mtmsr(mfmsr() | MSR_IP);
out_8((u_char *) restart, 0x01);
while (1)
;
}
static int __init mvme5100_probe(void)
{
return of_machine_is_compatible("MVME5100");
}
static int __init probe_of_platform_devices(void)
{
of_platform_bus_probe(NULL, mvme5100_of_bus_ids, NULL);
return 0;
}
