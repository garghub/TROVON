bool acpi_has_watchdog(void)
{
struct acpi_table_header hdr;
if (acpi_disabled)
return false;
return ACPI_SUCCESS(acpi_get_table_header(ACPI_SIG_WDAT, 0, &hdr));
}
void __init acpi_watchdog_init(void)
{
const struct acpi_wdat_entry *entries;
const struct acpi_table_wdat *wdat;
struct list_head resource_list;
struct resource_entry *rentry;
struct platform_device *pdev;
struct resource *resources;
size_t nresources = 0;
acpi_status status;
int i;
status = acpi_get_table(ACPI_SIG_WDAT, 0,
(struct acpi_table_header **)&wdat);
if (ACPI_FAILURE(status)) {
return;
}
if (!(wdat->flags & ACPI_WDAT_ENABLED))
return;
if (wdat->pci_segment != 0xff || wdat->pci_bus != 0xff ||
wdat->pci_device != 0xff || wdat->pci_function != 0xff)
return;
INIT_LIST_HEAD(&resource_list);
entries = (struct acpi_wdat_entry *)(wdat + 1);
for (i = 0; i < wdat->entries; i++) {
const struct acpi_generic_address *gas;
struct resource_entry *rentry;
struct resource res;
bool found;
gas = &entries[i].register_region;
res.start = gas->address;
if (gas->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
res.flags = IORESOURCE_MEM;
res.end = res.start + ALIGN(gas->access_width, 4);
} else if (gas->space_id == ACPI_ADR_SPACE_SYSTEM_IO) {
res.flags = IORESOURCE_IO;
res.end = res.start + gas->access_width;
} else {
pr_warn("Unsupported address space: %u\n",
gas->space_id);
goto fail_free_resource_list;
}
found = false;
resource_list_for_each_entry(rentry, &resource_list) {
if (resource_contains(rentry->res, &res)) {
found = true;
break;
}
}
if (!found) {
rentry = resource_list_create_entry(NULL, 0);
if (!rentry)
goto fail_free_resource_list;
*rentry->res = res;
resource_list_add_tail(rentry, &resource_list);
nresources++;
}
}
resources = kcalloc(nresources, sizeof(*resources), GFP_KERNEL);
if (!resources)
goto fail_free_resource_list;
i = 0;
resource_list_for_each_entry(rentry, &resource_list)
resources[i++] = *rentry->res;
pdev = platform_device_register_simple("wdat_wdt", PLATFORM_DEVID_NONE,
resources, nresources);
if (IS_ERR(pdev))
pr_err("Device creation failed: %ld\n", PTR_ERR(pdev));
kfree(resources);
fail_free_resource_list:
resource_list_free(&resource_list);
}
