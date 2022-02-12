efi_status_t __init handle_kernel_image(efi_system_table_t *sys_table_arg,
unsigned long *image_addr,
unsigned long *image_size,
unsigned long *reserve_addr,
unsigned long *reserve_size,
unsigned long dram_base,
efi_loaded_image_t *image)
{
efi_status_t status;
unsigned long kernel_size, kernel_memsize = 0;
unsigned long nr_pages;
void *old_image_addr = (void *)*image_addr;
unsigned long preferred_offset;
preferred_offset = round_down(dram_base, SZ_2M) + TEXT_OFFSET;
if (preferred_offset < dram_base)
preferred_offset += SZ_2M;
kernel_size = _edata - _text;
if (*image_addr != preferred_offset) {
kernel_memsize = kernel_size + (_end - _edata);
*image_addr = *reserve_addr = preferred_offset;
nr_pages = round_up(kernel_memsize, EFI_ALLOC_ALIGN) /
EFI_PAGE_SIZE;
status = efi_call_early(allocate_pages, EFI_ALLOCATE_ADDRESS,
EFI_LOADER_DATA, nr_pages,
(efi_physical_addr_t *)reserve_addr);
if (status != EFI_SUCCESS) {
kernel_memsize += TEXT_OFFSET;
status = efi_low_alloc(sys_table_arg, kernel_memsize,
SZ_2M, reserve_addr);
if (status != EFI_SUCCESS) {
pr_efi_err(sys_table_arg, "Failed to relocate kernel\n");
return status;
}
*image_addr = *reserve_addr + TEXT_OFFSET;
}
memcpy((void *)*image_addr, old_image_addr, kernel_size);
*reserve_size = kernel_memsize;
}
return EFI_SUCCESS;
}
