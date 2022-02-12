static void mpc85xx_8259_cascade(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int cascade_irq = i8259_irq();
if (cascade_irq != NO_IRQ) {
generic_handle_irq(cascade_irq);
}
chip->irq_eoi(&desc->irq_data);
}
void __init mpc85xx_ds_pic_init(void)
{
struct mpic *mpic;
struct resource r;
struct device_node *np;
#ifdef CONFIG_PPC_I8259
struct device_node *cascade_node = NULL;
int cascade_irq;
#endif
unsigned long root = of_get_flat_dt_root();
np = of_find_node_by_type(NULL, "open-pic");
if (np == NULL) {
printk(KERN_ERR "Could not find open-pic node\n");
return;
}
if (of_address_to_resource(np, 0, &r)) {
printk(KERN_ERR "Failed to map mpic register space\n");
of_node_put(np);
return;
}
if (of_flat_dt_is_compatible(root, "fsl,MPC8572DS-CAMP")) {
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
} else {
mpic = mpic_alloc(np, r.start,
MPIC_PRIMARY | MPIC_WANTS_RESET |
MPIC_BIG_ENDIAN | MPIC_BROKEN_FRR_NIRQS |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
}
BUG_ON(mpic == NULL);
of_node_put(np);
mpic_init(mpic);
#ifdef CONFIG_PPC_I8259
for_each_node_by_type(np, "interrupt-controller")
if (of_device_is_compatible(np, "chrp,iic")) {
cascade_node = np;
break;
}
if (cascade_node == NULL) {
printk(KERN_DEBUG "Could not find i8259 PIC\n");
return;
}
cascade_irq = irq_of_parse_and_map(cascade_node, 0);
if (cascade_irq == NO_IRQ) {
printk(KERN_ERR "Failed to map cascade interrupt\n");
return;
}
DBG("mpc85xxds: cascade mapped to irq %d\n", cascade_irq);
i8259_init(cascade_node, 0);
of_node_put(cascade_node);
irq_set_chained_handler(cascade_irq, mpc85xx_8259_cascade);
#endif
}
static int mpc85xx_exclude_device(struct pci_controller *hose,
u_char bus, u_char devfn)
{
struct device_node* node;
struct resource rsrc;
node = hose->dn;
of_address_to_resource(node, 0, &rsrc);
if ((rsrc.start & 0xfffff) == primary_phb_addr) {
return uli_exclude_device(hose, bus, devfn);
}
return PCIBIOS_SUCCESSFUL;
}
static void __init mpc85xx_ds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
struct pci_controller *hose;
#endif
dma_addr_t max = 0xffffffff;
if (ppc_md.progress)
ppc_md.progress("mpc85xx_ds_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8540-pci") ||
of_device_is_compatible(np, "fsl,mpc8548-pcie") ||
of_device_is_compatible(np, "fsl,p2020-pcie")) {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == primary_phb_addr)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
}
ppc_md.pci_exclude_device = mpc85xx_exclude_device;
#endif
#ifdef CONFIG_SMP
mpc85xx_smp_init();
#endif
#ifdef CONFIG_SWIOTLB
if (memblock_end_of_DRAM() > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
printk("MPC85xx DS board from Freescale Semiconductor\n");
}
static int __init mpc8544_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "MPC8544DS")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0xb000;
#endif
return 1;
}
return 0;
}
static int __init mpc85xxds_publish_devices(void)
{
return of_platform_bus_probe(NULL, mpc85xxds_ids, NULL);
}
static int __init mpc8572_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,MPC8572DS")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0x8000;
#endif
return 1;
}
return 0;
}
static int __init p2020_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P2020DS")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0x9000;
#endif
return 1;
}
return 0;
}
