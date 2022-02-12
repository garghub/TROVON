static void pci_process_ISA_OF_ranges(struct device_node *isa_node,
unsigned long phb_io_base_phys)
{
struct pci_address {
u32 a_hi;
u32 a_mid;
u32 a_lo;
};
struct isa_address {
u32 a_hi;
u32 a_lo;
};
struct isa_range {
struct isa_address isa_addr;
struct pci_address pci_addr;
unsigned int size;
};
const struct isa_range *range;
unsigned long pci_addr;
unsigned int isa_addr;
unsigned int size;
int rlen = 0;
range = of_get_property(isa_node, "ranges", &rlen);
if (range == NULL || (rlen < sizeof(struct isa_range)))
goto inval_range;
if ((range->isa_addr.a_hi & ISA_SPACE_MASK) != ISA_SPACE_IO) {
range++;
rlen -= sizeof(struct isa_range);
if (rlen < sizeof(struct isa_range))
goto inval_range;
}
if ((range->isa_addr.a_hi & ISA_SPACE_MASK) != ISA_SPACE_IO)
goto inval_range;
isa_addr = range->isa_addr.a_lo;
pci_addr = (unsigned long) range->pci_addr.a_mid << 32 |
range->pci_addr.a_lo;
if ((pci_addr != 0) || (isa_addr != 0)) {
printk(KERN_ERR "unexpected isa to pci mapping: %s\n",
__func__);
return;
}
size = PAGE_ALIGN(range->size);
if (size > 0x10000)
size = 0x10000;
__ioremap_at(phb_io_base_phys, (void *)ISA_IO_BASE,
size, pgprot_val(pgprot_noncached(__pgprot(0))));
return;
inval_range:
printk(KERN_ERR "no ISA IO ranges or unexpected isa range, "
"mapping 64k\n");
__ioremap_at(phb_io_base_phys, (void *)ISA_IO_BASE,
0x10000, pgprot_val(pgprot_noncached(__pgprot(0))));
}
void __init isa_bridge_find_early(struct pci_controller *hose)
{
struct device_node *np, *parent = NULL, *tmp;
if (isa_bridge_devnode != NULL)
return;
for_each_node_by_type(np, "isa") {
for (parent = of_get_parent(np); parent;) {
if (parent == hose->dn) {
of_node_put(parent);
break;
}
tmp = parent;
parent = of_get_parent(parent);
of_node_put(tmp);
}
if (parent != NULL)
break;
}
if (np == NULL)
return;
isa_bridge_devnode = np;
pci_process_ISA_OF_ranges(np, hose->io_base_phys);
isa_io_base = ISA_IO_BASE;
pr_debug("ISA bridge (early) is %pOF\n", np);
}
void __init isa_bridge_init_non_pci(struct device_node *np)
{
const __be32 *ranges, *pbasep = NULL;
int rlen, i, rs;
u32 na, ns, pna;
u64 cbase, pbase, size = 0;
if (isa_bridge_devnode != NULL)
return;
pna = of_n_addr_cells(np);
if (of_property_read_u32(np, "#address-cells", &na) ||
of_property_read_u32(np, "#size-cells", &ns)) {
pr_warn("ISA: Non-PCI bridge %pOF is missing address format\n",
np);
return;
}
if (na != 2 || ns != 1) {
pr_warn("ISA: Non-PCI bridge %pOF has unsupported address format\n",
np);
return;
}
rs = na + ns + pna;
ranges = of_get_property(np, "ranges", &rlen);
if (ranges == NULL || rlen < rs) {
pr_warn("ISA: Non-PCI bridge %pOF has absent or invalid ranges\n",
np);
return;
}
for (i = 0; (i + rs - 1) < rlen; i += rs) {
if (be32_to_cpup(ranges + i) != 1)
continue;
cbase = be32_to_cpup(ranges + i + 1);
size = of_read_number(ranges + i + na + pna, ns);
pbasep = ranges + i + na;
break;
}
if (!size || !pbasep) {
pr_warn("ISA: Non-PCI bridge %pOF has no usable IO range\n",
np);
return;
}
size = PAGE_ALIGN(size);
if (size > 0x10000)
size = 0x10000;
pbase = of_translate_address(np, pbasep);
if (pbase == OF_BAD_ADDR) {
pr_warn("ISA: Non-PCI bridge %pOF failed to translate IO base\n",
np);
return;
}
if ((cbase & ~PAGE_MASK) || (pbase & ~PAGE_MASK)) {
pr_warn("ISA: Non-PCI bridge %pOF has non aligned IO range\n",
np);
return;
}
isa_bridge_devnode = np;
isa_io_base = ISA_IO_BASE;
__ioremap_at(pbase, (void *)ISA_IO_BASE,
size, pgprot_val(pgprot_noncached(__pgprot(0))));
pr_debug("ISA: Non-PCI bridge is %pOF\n", np);
}
static void isa_bridge_find_late(struct pci_dev *pdev,
struct device_node *devnode)
{
struct pci_controller *hose = pci_bus_to_host(pdev->bus);
isa_bridge_devnode = of_node_get(devnode);
isa_bridge_pcidev = pdev;
pci_process_ISA_OF_ranges(devnode, hose->io_base_phys);
isa_io_base = ISA_IO_BASE;
pr_debug("ISA bridge (late) is %pOF on %s\n",
devnode, pci_name(pdev));
}
static void isa_bridge_remove(void)
{
pr_debug("ISA bridge removed !\n");
isa_io_base = ISA_IO_BASE;
of_node_put(isa_bridge_devnode);
isa_bridge_devnode = NULL;
isa_bridge_pcidev = NULL;
__iounmap_at((void *)ISA_IO_BASE, 0x10000);
}
static int isa_bridge_notify(struct notifier_block *nb, unsigned long action,
void *data)
{
struct device *dev = data;
struct pci_dev *pdev = to_pci_dev(dev);
struct device_node *devnode = pci_device_to_OF_node(pdev);
switch(action) {
case BUS_NOTIFY_ADD_DEVICE:
if (isa_bridge_devnode && isa_bridge_devnode == devnode &&
!isa_bridge_pcidev) {
pr_debug("ISA bridge PCI attached: %s\n",
pci_name(pdev));
isa_bridge_pcidev = pdev;
}
if (!isa_bridge_devnode && devnode && devnode->type &&
!strcmp(devnode->type, "isa"))
isa_bridge_find_late(pdev, devnode);
return 0;
case BUS_NOTIFY_DEL_DEVICE:
if (pdev == isa_bridge_pcidev ||
(devnode && devnode == isa_bridge_devnode))
isa_bridge_remove();
return 0;
}
return 0;
}
static int __init isa_bridge_init(void)
{
bus_register_notifier(&pci_bus_type, &isa_bridge_notifier);
return 0;
}
