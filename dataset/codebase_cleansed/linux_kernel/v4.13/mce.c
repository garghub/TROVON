static int nfit_handle_mce(struct notifier_block *nb, unsigned long val,
void *data)
{
struct mce *mce = (struct mce *)data;
struct acpi_nfit_desc *acpi_desc;
struct nfit_spa *nfit_spa;
if (!mce_is_memory_error(mce))
return NOTIFY_DONE;
mutex_lock(&acpi_desc_lock);
list_for_each_entry(acpi_desc, &acpi_descs, list) {
struct device *dev = acpi_desc->dev;
int found_match = 0;
mutex_lock(&acpi_desc->init_mutex);
list_for_each_entry(nfit_spa, &acpi_desc->spas, list) {
struct acpi_nfit_system_address *spa = nfit_spa->spa;
if (nfit_spa_type(spa) != NFIT_SPA_PM)
continue;
if (spa->address > mce->addr)
continue;
if ((spa->address + spa->length - 1) < mce->addr)
continue;
found_match = 1;
dev_dbg(dev, "%s: addr in SPA %d (0x%llx, 0x%llx)\n",
__func__, spa->range_index, spa->address,
spa->length);
break;
}
mutex_unlock(&acpi_desc->init_mutex);
if (!found_match)
continue;
nvdimm_bus_add_poison(acpi_desc->nvdimm_bus,
ALIGN(mce->addr, L1_CACHE_BYTES),
L1_CACHE_BYTES);
nvdimm_region_notify(nfit_spa->nd_region,
NVDIMM_REVALIDATE_POISON);
if (acpi_desc->scrub_mode == HW_ERROR_SCRUB_ON) {
acpi_nfit_ars_rescan(acpi_desc, 0);
}
break;
}
mutex_unlock(&acpi_desc_lock);
return NOTIFY_DONE;
}
void nfit_mce_register(void)
{
mce_register_decode_chain(&nfit_mce_dec);
}
void nfit_mce_unregister(void)
{
mce_unregister_decode_chain(&nfit_mce_dec);
}
