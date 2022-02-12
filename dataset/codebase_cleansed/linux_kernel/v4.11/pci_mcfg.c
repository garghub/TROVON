static int pci_mcfg_quirk_matches(struct mcfg_fixup *f, u16 segment,
struct resource *bus_range)
{
if (!memcmp(f->oem_id, mcfg_oem_id, ACPI_OEM_ID_SIZE) &&
!memcmp(f->oem_table_id, mcfg_oem_table_id,
ACPI_OEM_TABLE_ID_SIZE) &&
f->oem_revision == mcfg_oem_revision &&
f->segment == segment &&
resource_contains(&f->bus_range, bus_range))
return 1;
return 0;
}
static void pci_mcfg_apply_quirks(struct acpi_pci_root *root,
struct resource *cfgres,
struct pci_ecam_ops **ecam_ops)
{
#ifdef CONFIG_PCI_QUIRKS
u16 segment = root->segment;
struct resource *bus_range = &root->secondary;
struct mcfg_fixup *f;
int i;
for (i = 0, f = mcfg_quirks; i < ARRAY_SIZE(mcfg_quirks); i++, f++) {
if (pci_mcfg_quirk_matches(f, segment, bus_range)) {
if (f->cfgres.start)
*cfgres = f->cfgres;
if (f->ops)
*ecam_ops = f->ops;
dev_info(&root->device->dev, "MCFG quirk: ECAM at %pR for %pR with %ps\n",
cfgres, bus_range, *ecam_ops);
return;
}
}
#endif
}
int pci_mcfg_lookup(struct acpi_pci_root *root, struct resource *cfgres,
struct pci_ecam_ops **ecam_ops)
{
struct pci_ecam_ops *ops = &pci_generic_ecam_ops;
struct resource *bus_res = &root->secondary;
u16 seg = root->segment;
struct mcfg_entry *e;
struct resource res;
if (root->mcfg_addr)
goto skip_lookup;
list_for_each_entry(e, &pci_mcfg_list, list) {
if (e->segment == seg && e->bus_start <= bus_res->start &&
e->bus_end >= bus_res->end) {
root->mcfg_addr = e->addr;
}
}
skip_lookup:
memset(&res, 0, sizeof(res));
if (root->mcfg_addr) {
res.start = root->mcfg_addr + (bus_res->start << 20);
res.end = res.start + (resource_size(bus_res) << 20) - 1;
res.flags = IORESOURCE_MEM;
}
pci_mcfg_apply_quirks(root, &res, &ops);
if (!res.start)
return -ENXIO;
*cfgres = res;
*ecam_ops = ops;
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
#ifdef CONFIG_PCI_QUIRKS
memcpy(mcfg_oem_id, header->oem_id, ACPI_OEM_ID_SIZE);
memcpy(mcfg_oem_table_id, header->oem_table_id, ACPI_OEM_TABLE_ID_SIZE);
mcfg_oem_revision = header->oem_revision;
#endif
pr_info("MCFG table detected, %d entries\n", n);
return 0;
}
void __init pci_mmcfg_late_init(void)
{
int err = acpi_table_parse(ACPI_SIG_MCFG, pci_mcfg_parse);
if (err)
pr_err("Failed to parse MCFG (%d)\n", err);
}
