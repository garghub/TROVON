phys_addr_t pci_mcfg_lookup(u16 seg, struct resource *bus_res)
{
struct mcfg_entry *e;
list_for_each_entry(e, &pci_mcfg_list, list) {
if (e->segment == seg && e->bus_start == bus_res->start &&
e->bus_end >= bus_res->end)
return e->addr;
}
return 0;
}
static __init int pci_mcfg_parse(struct acpi_table_header *header)
{
struct acpi_table_mcfg *mcfg;
struct acpi_mcfg_allocation *mptr;
struct mcfg_entry *e, *arr;
int i, n;
if (header->length < sizeof(struct acpi_table_mcfg))
return -EINVAL;
n = (header->length - sizeof(struct acpi_table_mcfg)) /
sizeof(struct acpi_mcfg_allocation);
mcfg = (struct acpi_table_mcfg *)header;
mptr = (struct acpi_mcfg_allocation *) &mcfg[1];
arr = kcalloc(n, sizeof(*arr), GFP_KERNEL);
if (!arr)
return -ENOMEM;
for (i = 0, e = arr; i < n; i++, mptr++, e++) {
e->segment = mptr->pci_segment;
e->addr = mptr->address;
e->bus_start = mptr->start_bus_number;
e->bus_end = mptr->end_bus_number;
list_add(&e->list, &pci_mcfg_list);
}
pr_info("MCFG table detected, %d entries\n", n);
return 0;
}
void __init pci_mmcfg_late_init(void)
{
int err = acpi_table_parse(ACPI_SIG_MCFG, pci_mcfg_parse);
if (err)
pr_err("Failed to parse MCFG (%d)\n", err);
}
