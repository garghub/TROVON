static void __init zap_identity_mappings(void)
{
pgd_t *pgd = pgd_offset_k(0UL);
pgd_clear(pgd);
__flush_tlb_all();
}
static void __init clear_bss(void)
{
memset(__bss_start, 0,
(unsigned long) __bss_stop - (unsigned long) __bss_start);
}
static void __init copy_bootdata(char *real_mode_data)
{
char * command_line;
memcpy(&boot_params, real_mode_data, sizeof boot_params);
if (boot_params.hdr.cmd_line_ptr) {
command_line = __va(boot_params.hdr.cmd_line_ptr);
memcpy(boot_command_line, command_line, COMMAND_LINE_SIZE);
}
}
void __init x86_64_start_kernel(char * real_mode_data)
{
int i;
BUILD_BUG_ON(MODULES_VADDR < KERNEL_IMAGE_START);
BUILD_BUG_ON(MODULES_VADDR-KERNEL_IMAGE_START < KERNEL_IMAGE_SIZE);
BUILD_BUG_ON(MODULES_LEN + KERNEL_IMAGE_SIZE > 2*PUD_SIZE);
BUILD_BUG_ON((KERNEL_IMAGE_START & ~PMD_MASK) != 0);
BUILD_BUG_ON((MODULES_VADDR & ~PMD_MASK) != 0);
BUILD_BUG_ON(!(MODULES_VADDR > __START_KERNEL));
BUILD_BUG_ON(!(((MODULES_END - 1) & PGDIR_MASK) ==
(__START_KERNEL & PGDIR_MASK)));
BUILD_BUG_ON(__fix_to_virt(__end_of_fixed_addresses) <= MODULES_END);
clear_bss();
zap_identity_mappings();
max_pfn_mapped = KERNEL_IMAGE_SIZE >> PAGE_SHIFT;
for (i = 0; i < NUM_EXCEPTION_VECTORS; i++) {
#ifdef CONFIG_EARLY_PRINTK
set_intr_gate(i, &early_idt_handlers[i]);
#else
set_intr_gate(i, early_idt_handler);
#endif
}
load_idt((const struct desc_ptr *)&idt_descr);
if (console_loglevel == 10)
early_printk("Kernel alive\n");
x86_64_start_reservations(real_mode_data);
}
void __init x86_64_start_reservations(char *real_mode_data)
{
copy_bootdata(__va(real_mode_data));
memblock_reserve(__pa_symbol(&_text),
__pa_symbol(&__bss_stop) - __pa_symbol(&_text));
#ifdef CONFIG_BLK_DEV_INITRD
if (boot_params.hdr.type_of_loader && boot_params.hdr.ramdisk_image) {
unsigned long ramdisk_image = boot_params.hdr.ramdisk_image;
unsigned long ramdisk_size = boot_params.hdr.ramdisk_size;
unsigned long ramdisk_end = PAGE_ALIGN(ramdisk_image + ramdisk_size);
memblock_reserve(ramdisk_image, ramdisk_end - ramdisk_image);
}
#endif
reserve_ebda_region();
start_kernel();
}
