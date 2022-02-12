static bool __init efi_virtmap_init(void)
{
efi_memory_desc_t *md;
efi_mm.pgd = pgd_alloc(&efi_mm);
init_new_context(NULL, &efi_mm);
for_each_efi_memory_desc(&memmap, md) {
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
}
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
pr_info("Remapping and enabling EFI services.\n");
mapsize = memmap.map_end - memmap.map;
memmap.map = (__force void *)ioremap_cache(memmap.phys_map,
mapsize);
if (!memmap.map) {
pr_err("Failed to remap EFI memory map\n");
return -ENOMEM;
}
memmap.map_end = memmap.map + mapsize;
efi.memmap = &memmap;
efi.systab = (__force void *)ioremap_cache(efi_system_table,
sizeof(efi_system_table_t));
if (!efi.systab) {
pr_err("Failed to remap EFI System Table\n");
return -ENOMEM;
}
set_bit(EFI_SYSTEM_TABLES, &efi.flags);
if (!efi_virtmap_init()) {
pr_err("No UEFI virtual mapping was installed -- runtime services will not be available\n");
return -ENOMEM;
}
efi_native_runtime_setup();
set_bit(EFI_RUNTIME_SERVICES, &efi.flags);
efi.runtime_version = efi.systab->hdr.revision;
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
