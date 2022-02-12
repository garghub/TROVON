static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init linkstation_add_bridge(struct device_node *dev)
{
#ifdef CONFIG_PCI
int len;
struct pci_controller *hose;
const int *bus_range;
printk("Adding PCI host bridge %s\n", dev->full_name);
bus_range = of_get_property(dev, "bus-range", &len);
if (bus_range == NULL || len < 2 * sizeof(int))
printk(KERN_WARNING "Can't get bus-range for %s, assume"
" bus 0\n", dev->full_name);
hose = pcibios_alloc_controller(dev);
if (hose == NULL)
return -ENOMEM;
hose->first_busno = bus_range ? bus_range[0] : 0;
hose->last_busno = bus_range ? bus_range[1] : 0xff;
setup_indirect_pci(hose, 0xfec00000, 0xfee00000, 0);
pci_process_bridge_OF_ranges(hose, dev, 1);
#endif
return 0;
}
static void __init linkstation_setup_arch(void)
{
struct device_node *np;
for_each_compatible_node(np, "pci", "mpc10x-pci")
linkstation_add_bridge(np);
printk(KERN_INFO "BUFFALO Network Attached Storage Series\n");
printk(KERN_INFO "(C) 2002-2005 BUFFALO INC.\n");
}
static void __init linkstation_init_IRQ(void)
{
struct mpic *mpic;
struct device_node *dnp;
const u32 *prop;
int size;
phys_addr_t paddr;
dnp = of_find_node_by_type(NULL, "open-pic");
if (dnp == NULL)
return;
prop = of_get_property(dnp, "reg", &size);
paddr = (phys_addr_t)of_translate_address(dnp, prop);
mpic = mpic_alloc(dnp, paddr, MPIC_PRIMARY | MPIC_WANTS_RESET, 4, 32, " EPIC ");
BUG_ON(mpic == NULL);
mpic_assign_isu(mpic, 0, paddr + 0x10200);
mpic_assign_isu(mpic, 1, paddr + 0x11000);
mpic_assign_isu(mpic, 2, paddr + 0x11100);
mpic_init(mpic);
}
static void linkstation_restart(char *cmd)
{
local_irq_disable();
avr_uart_configure();
avr_uart_send('C');
for(;;)
avr_uart_send('G');
}
static void linkstation_power_off(void)
{
local_irq_disable();
avr_uart_configure();
avr_uart_send('E');
for(;;)
avr_uart_send('G');
}
static void linkstation_halt(void)
{
linkstation_power_off();
}
static void linkstation_show_cpuinfo(struct seq_file *m)
{
seq_printf(m, "vendor\t\t: Buffalo Technology\n");
seq_printf(m, "machine\t\t: Linkstation I/Kurobox(HG)\n");
}
static int __init linkstation_probe(void)
{
unsigned long root;
root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "linkstation"))
return 0;
return 1;
}
