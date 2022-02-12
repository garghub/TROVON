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
status = efi_low_alloc(sys_table, kernel_memsize + TEXT_OFFSET,
SZ_2M, reserve_addr);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table, "Failed to relocate kernel\n");
return status;
}
memcpy((void *)*reserve_addr + TEXT_OFFSET, (void *)*image_addr,
kernel_size);
*image_addr = *reserve_addr + TEXT_OFFSET;
*reserve_size = kernel_memsize + TEXT_OFFSET;
}
return EFI_SUCCESS;
}
