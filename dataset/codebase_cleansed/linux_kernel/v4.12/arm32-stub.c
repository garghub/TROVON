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
static efi_status_t reserve_kernel_base(efi_system_table_t *sys_table_arg,
unsigned long dram_base,
unsigned long *reserve_addr,
unsigned long *reserve_size)
{
efi_physical_addr_t alloc_addr;
efi_memory_desc_t *memory_map;
unsigned long nr_pages, map_size, desc_size, buff_size;
efi_status_t status;
unsigned long l;
struct efi_boot_memmap map = {
.map = &memory_map,
.map_size = &map_size,
.desc_size = &desc_size,
.desc_ver = NULL,
.key_ptr = NULL,
.buff_size = &buff_size,
};
alloc_addr = dram_base + MAX_UNCOMP_KERNEL_SIZE;
nr_pages = MAX_UNCOMP_KERNEL_SIZE / EFI_PAGE_SIZE;
status = efi_call_early(allocate_pages, EFI_ALLOCATE_MAX_ADDRESS,
EFI_BOOT_SERVICES_DATA, nr_pages, &alloc_addr);
if (status == EFI_SUCCESS) {
if (alloc_addr == dram_base) {
*reserve_addr = alloc_addr;
*reserve_size = MAX_UNCOMP_KERNEL_SIZE;
return EFI_SUCCESS;
}
}
status = efi_get_memory_map(sys_table_arg, &map);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table_arg,
"reserve_kernel_base(): Unable to retrieve memory map.\n");
return status;
}
for (l = 0; l < map_size; l += desc_size) {
efi_memory_desc_t *desc;
u64 start, end;
desc = (void *)memory_map + l;
start = desc->phys_addr;
end = start + desc->num_pages * EFI_PAGE_SIZE;
if (start >= dram_base + MAX_UNCOMP_KERNEL_SIZE ||
end <= dram_base)
continue;
switch (desc->type) {
case EFI_BOOT_SERVICES_CODE:
case EFI_BOOT_SERVICES_DATA:
continue;
case EFI_CONVENTIONAL_MEMORY:
start = max(start, (u64)dram_base);
end = min(end, (u64)dram_base + MAX_UNCOMP_KERNEL_SIZE);
status = efi_call_early(allocate_pages,
EFI_ALLOCATE_ADDRESS,
EFI_LOADER_DATA,
(end - start) / EFI_PAGE_SIZE,
&start);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table_arg,
"reserve_kernel_base(): alloc failed.\n");
goto out;
}
break;
case EFI_LOADER_CODE:
case EFI_LOADER_DATA:
default:
status = EFI_OUT_OF_RESOURCES;
goto out;
}
}
status = EFI_SUCCESS;
out:
efi_call_early(free_pool, memory_map);
return status;
}
efi_status_t handle_kernel_image(efi_system_table_t *sys_table,
unsigned long *image_addr,
unsigned long *image_size,
unsigned long *reserve_addr,
unsigned long *reserve_size,
unsigned long dram_base,
efi_loaded_image_t *image)
{
efi_status_t status;
dram_base = round_up(dram_base, SZ_128M);
status = reserve_kernel_base(sys_table, dram_base, reserve_addr,
reserve_size);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table, "Unable to allocate memory for uncompressed kernel.\n");
return status;
}
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
