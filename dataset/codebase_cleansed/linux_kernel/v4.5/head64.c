static void __init reset_early_page_tables(void)
{
unsigned long i;
for (i = 0; i < PTRS_PER_PGD-1; i++)
early_level4_pgt[i].pgd = 0;
next_early_pgt = 0;
write_cr3(__pa_nodebug(early_level4_pgt));
}
int __init early_make_pgtable(unsigned long address)
{
unsigned long physaddr = address - __PAGE_OFFSET;
unsigned long i;
pgdval_t pgd, *pgd_p;
pudval_t pud, *pud_p;
pmdval_t pmd, *pmd_p;
if (physaddr >= MAXMEM || read_cr3() != __pa_nodebug(early_level4_pgt))
return -1;
again:
pgd_p = &early_level4_pgt[pgd_index(address)].pgd;
pgd = *pgd_p;
if (pgd)
pud_p = (pudval_t *)((pgd & PTE_PFN_MASK) + __START_KERNEL_map - phys_base);
else {
if (next_early_pgt >= EARLY_DYNAMIC_PAGE_TABLES) {
reset_early_page_tables();
goto again;
}
pud_p = (pudval_t *)early_dynamic_pgts[next_early_pgt++];
for (i = 0; i < PTRS_PER_PUD; i++)
pud_p[i] = 0;
*pgd_p = (pgdval_t)pud_p - __START_KERNEL_map + phys_base + _KERNPG_TABLE;
}
pud_p += pud_index(address);
pud = *pud_p;
if (pud)
pmd_p = (pmdval_t *)((pud & PTE_PFN_MASK) + __START_KERNEL_map - phys_base);
else {
if (next_early_pgt >= EARLY_DYNAMIC_PAGE_TABLES) {
reset_early_page_tables();
goto again;
}
pmd_p = (pmdval_t *)early_dynamic_pgts[next_early_pgt++];
for (i = 0; i < PTRS_PER_PMD; i++)
pmd_p[i] = 0;
*pud_p = (pudval_t)pmd_p - __START_KERNEL_map + phys_base + _KERNPG_TABLE;
}
pmd = (physaddr & PMD_MASK) + early_pmd_flags;
pmd_p[pmd_index(address)] = pmd;
return 0;
}
static void __init clear_bss(void)
{
memset(__bss_start, 0,
(unsigned long) __bss_stop - (unsigned long) __bss_start);
}
static unsigned long get_cmd_line_ptr(void)
{
unsigned long cmd_line_ptr = boot_params.hdr.cmd_line_ptr;
cmd_line_ptr |= (u64)boot_params.ext_cmd_line_ptr << 32;
return cmd_line_ptr;
}
static void __init copy_bootdata(char *real_mode_data)
{
char * command_line;
unsigned long cmd_line_ptr;
memcpy(&boot_params, real_mode_data, sizeof boot_params);
sanitize_boot_params(&boot_params);
cmd_line_ptr = get_cmd_line_ptr();
if (cmd_line_ptr) {
command_line = __va(cmd_line_ptr);
memcpy(boot_command_line, command_line, COMMAND_LINE_SIZE);
}
}
asmlinkage __visible void __init x86_64_start_kernel(char * real_mode_data)
{
int i;
BUILD_BUG_ON(MODULES_VADDR < __START_KERNEL_map);
BUILD_BUG_ON(MODULES_VADDR - __START_KERNEL_map < KERNEL_IMAGE_SIZE);
BUILD_BUG_ON(MODULES_LEN + KERNEL_IMAGE_SIZE > 2*PUD_SIZE);
BUILD_BUG_ON((__START_KERNEL_map & ~PMD_MASK) != 0);
BUILD_BUG_ON((MODULES_VADDR & ~PMD_MASK) != 0);
BUILD_BUG_ON(!(MODULES_VADDR > __START_KERNEL));
BUILD_BUG_ON(!(((MODULES_END - 1) & PGDIR_MASK) ==
(__START_KERNEL & PGDIR_MASK)));
BUILD_BUG_ON(__fix_to_virt(__end_of_fixed_addresses) <= MODULES_END);
cr4_init_shadow();
reset_early_page_tables();
clear_bss();
clear_page(init_level4_pgt);
kasan_early_init();
for (i = 0; i < NUM_EXCEPTION_VECTORS; i++)
set_intr_gate(i, early_idt_handler_array[i]);
load_idt((const struct desc_ptr *)&idt_descr);
copy_bootdata(__va(real_mode_data));
load_ucode_bsp();
init_level4_pgt[511] = early_level4_pgt[511];
x86_64_start_reservations(real_mode_data);
}
void __init x86_64_start_reservations(char *real_mode_data)
{
if (!boot_params.hdr.version)
copy_bootdata(__va(real_mode_data));
reserve_ebda_region();
switch (boot_params.hdr.hardware_subarch) {
case X86_SUBARCH_INTEL_MID:
x86_intel_mid_early_setup();
break;
default:
break;
}
start_kernel();
}
