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
