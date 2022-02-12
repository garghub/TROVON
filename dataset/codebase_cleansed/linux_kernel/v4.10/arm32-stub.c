efi_status_t check_platform_features(efi_system_table_t *sys_table_arg)
{
int block;
if (!IS_ENABLED(CONFIG_ARM_LPAE))
return EFI_SUCCESS;
block = cpuid_feature_extract(CPUID_EXT_MMFR0, 0);
if (block < 5) {
pr_efi_err(sys_table_arg, "This LPAE kernel is not supported by your CPU\n");
return EFI_UNSUPPORTED;
}
return EFI_SUCCESS;
}
struct screen_info *alloc_screen_info(efi_system_table_t *sys_table_arg)
{
struct screen_info *si;
efi_status_t status;
status = efi_call_early(allocate_pool, EFI_RUNTIME_SERVICES_DATA,
sizeof(*si), (void **)&si);
if (status != EFI_SUCCESS)
return NULL;
status = efi_call_early(install_configuration_table,
&screen_info_guid, si);
if (status == EFI_SUCCESS)
return si;
efi_call_early(free_pool, si);
return NULL;
}
void free_screen_info(efi_system_table_t *sys_table_arg, struct screen_info *si)
{
if (!si)
return;
efi_call_early(install_configuration_table, &screen_info_guid, NULL);
efi_call_early(free_pool, si);
}
efi_status_t handle_kernel_image(efi_system_table_t *sys_table,
unsigned long *image_addr,
unsigned long *image_size,
unsigned long *reserve_addr,
unsigned long *reserve_size,
unsigned long dram_base,
efi_loaded_image_t *image)
{
unsigned long nr_pages;
efi_status_t status;
efi_physical_addr_t alloc_addr;
dram_base = round_up(dram_base, SZ_128M);
alloc_addr = dram_base;
*reserve_size = MAX_UNCOMP_KERNEL_SIZE;
nr_pages = round_up(*reserve_size, EFI_PAGE_SIZE) / EFI_PAGE_SIZE;
status = sys_table->boottime->allocate_pages(EFI_ALLOCATE_ADDRESS,
EFI_LOADER_DATA,
nr_pages, &alloc_addr);
if (status != EFI_SUCCESS) {
*reserve_size = 0;
pr_efi_err(sys_table, "Unable to allocate memory for uncompressed kernel.\n");
return status;
}
*reserve_addr = alloc_addr;
*image_size = image->image_size;
status = efi_relocate_kernel(sys_table, image_addr, *image_size,
*image_size,
dram_base + MAX_UNCOMP_KERNEL_SIZE, 0);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table, "Failed to relocate kernel.\n");
efi_free(sys_table, *reserve_size, *reserve_addr);
*reserve_size = 0;
return status;
}
if (*image_addr + *image_size > dram_base + ZIMAGE_OFFSET_LIMIT) {
pr_efi_err(sys_table, "Failed to relocate kernel, no low memory available.\n");
efi_free(sys_table, *reserve_size, *reserve_addr);
*reserve_size = 0;
efi_free(sys_table, *image_size, *image_addr);
*image_size = 0;
return EFI_LOAD_ERROR;
}
return EFI_SUCCESS;
}
