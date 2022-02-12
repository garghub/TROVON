static int __init ptdump_init(void)
{
return ptdump_debugfs_register(&efi_ptdump_info, "efi_page_tables");
}
static bool __init efi_virtmap_init(void)
{
efi_memory_desc_t *md;
bool systab_found;
efi_mm.pgd = pgd_alloc(&efi_mm);
init_new_context(NULL, &efi_mm);
systab_found = false;
for_each_efi_memory_desc(md) {
phys_addr_t phys = md->phys_addr;
int ret;
if (!(md->attribute & EFI_MEMORY_RUNTIME))
continue;
if (md->virt_addr == 0)
return false;
ret = efi_create_mapping(&efi_mm, md);
if (!ret) {
pr_info(" EFI remap %pa => %p\n",
&phys, (void *)(unsigned long)md->virt_addr);
} else {
pr_warn(" EFI remap %pa: failed to create mapping (%d)\n",
&phys, ret);
return false;
}
if (efi_system_table >= phys &&
efi_system_table < phys + (md->num_pages * EFI_PAGE_SIZE)) {
efi.systab = (void *)(unsigned long)(efi_system_table -
phys + md->virt_addr);
systab_found = true;
}
}
if (!systab_found) {
pr_err("No virtual mapping found for the UEFI System Table\n");
return false;
}
if (efi_memattr_apply_permissions(&efi_mm, efi_set_mapping_permissions))
return false;
return true;
}
static int __init arm_enable_runtime_services(void)
{
u64 mapsize;
if (!efi_enabled(EFI_BOOT)) {
pr_info("EFI services will not be available.\n");
return 0;
}
if (efi_runtime_disabled()) {
pr_info("EFI runtime services will be disabled.\n");
return 0;
}
if (efi_enabled(EFI_RUNTIME_SERVICES)) {
pr_info("EFI runtime services access via paravirt.\n");
return 0;
}
pr_info("Remapping and enabling EFI services.\n");
mapsize = efi.memmap.desc_size * efi.memmap.nr_map;
if (efi_memmap_init_late(efi.memmap.phys_map, mapsize)) {
pr_err("Failed to remap EFI memory map\n");
return -ENOMEM;
}
if (!efi_virtmap_init()) {
pr_err("UEFI virtual mapping missing or invalid -- runtime services will not be available\n");
return -ENOMEM;
}
efi_native_runtime_setup();
set_bit(EFI_RUNTIME_SERVICES, &efi.flags);
return 0;
}
void efi_virtmap_load(void)
{
preempt_disable();
efi_set_pgd(&efi_mm);
}
void efi_virtmap_unload(void)
{
efi_set_pgd(current->active_mm);
preempt_enable();
}
