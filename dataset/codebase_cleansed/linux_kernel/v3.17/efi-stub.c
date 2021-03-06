efi_status_t handle_kernel_image(efi_system_table_t *sys_table,
unsigned long *image_addr,
unsigned long *image_size,
unsigned long *reserve_addr,
unsigned long *reserve_size,
unsigned long dram_base,
efi_loaded_image_t *image)
{
efi_status_t status;
unsigned long kernel_size, kernel_memsize = 0;
kernel_size = _edata - _text;
if (*image_addr != (dram_base + TEXT_OFFSET)) {
kernel_memsize = kernel_size + (_end - _edata);
status = efi_relocate_kernel(sys_table, image_addr,
kernel_size, kernel_memsize,
dram_base + TEXT_OFFSET,
PAGE_SIZE);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table, "Failed to relocate kernel\n");
return status;
}
if (*image_addr != (dram_base + TEXT_OFFSET)) {
pr_efi_err(sys_table, "Failed to alloc kernel memory\n");
efi_free(sys_table, kernel_memsize, *image_addr);
return EFI_LOAD_ERROR;
}
*image_size = kernel_memsize;
}
return EFI_SUCCESS;
}
