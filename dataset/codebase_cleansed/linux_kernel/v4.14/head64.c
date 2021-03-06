static void __head *fixup_pointer(void *ptr, unsigned long physaddr)
{
return ptr - (void *)_text + (void *)physaddr;
}
unsigned long __head __startup_64(unsigned long physaddr,
struct boot_params *bp)
{
unsigned long load_delta, *p;
unsigned long pgtable_flags;
pgdval_t *pgd;
p4dval_t *p4d;
pudval_t *pud;
pmdval_t *pmd, pmd_entry;
int i;
unsigned int *next_pgt_ptr;
if (physaddr >> MAX_PHYSMEM_BITS)
for (;;);
load_delta = physaddr - (unsigned long)(_text - __START_KERNEL_map);
if (load_delta & ~PMD_PAGE_MASK)
for (;;);
sme_enable(bp);
load_delta += sme_get_me_mask();
pgd = fixup_pointer(&early_top_pgt, physaddr);
pgd[pgd_index(__START_KERNEL_map)] += load_delta;
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d = fixup_pointer(&level4_kernel_pgt, physaddr);
p4d[511] += load_delta;
}
pud = fixup_pointer(&level3_kernel_pgt, physaddr);
pud[510] += load_delta;
pud[511] += load_delta;
pmd = fixup_pointer(level2_fixmap_pgt, physaddr);
pmd[506] += load_delta;
next_pgt_ptr = fixup_pointer(&next_early_pgt, physaddr);
pud = fixup_pointer(early_dynamic_pgts[(*next_pgt_ptr)++], physaddr);
pmd = fixup_pointer(early_dynamic_pgts[(*next_pgt_ptr)++], physaddr);
pgtable_flags = _KERNPG_TABLE_NOENC + sme_get_me_mask();
if (IS_ENABLED(CONFIG_X86_5LEVEL)) {
p4d = fixup_pointer(early_dynamic_pgts[next_early_pgt++], physaddr);
i = (physaddr >> PGDIR_SHIFT) % PTRS_PER_PGD;
pgd[i + 0] = (pgdval_t)p4d + pgtable_flags;
pgd[i + 1] = (pgdval_t)p4d + pgtable_flags;
i = (physaddr >> P4D_SHIFT) % PTRS_PER_P4D;
p4d[i + 0] = (pgdval_t)pud + pgtable_flags;
p4d[i + 1] = (pgdval_t)pud + pgtable_flags;
} else {
i = (physaddr >> PGDIR_SHIFT) % PTRS_PER_PGD;
pgd[i + 0] = (pgdval_t)pud + pgtable_flags;
pgd[i + 1] = (pgdval_t)pud + pgtable_flags;
}
i = (physaddr >> PUD_SHIFT) % PTRS_PER_PUD;
pud[i + 0] = (pudval_t)pmd + pgtable_flags;
pud[i + 1] = (pudval_t)pmd + pgtable_flags;
pmd_entry = __PAGE_KERNEL_LARGE_EXEC & ~_PAGE_GLOBAL;
pmd_entry += sme_get_me_mask();
pmd_entry += physaddr;
for (i = 0; i < DIV_ROUND_UP(_end - _text, PMD_SIZE); i++) {
int idx = i + (physaddr >> PMD_SHIFT) % PTRS_PER_PMD;
pmd[idx] = pmd_entry + i * PMD_SIZE;
}
pmd = fixup_pointer(level2_kernel_pgt, physaddr);
for (i = 0; i < PTRS_PER_PMD; i++) {
if (pmd[i] & _PAGE_PRESENT)
pmd[i] += load_delta;
}
p = fixup_pointer(&phys_base, physaddr);
*p += load_delta - sme_get_me_mask();
sme_encrypt_kernel();
return sme_get_me_mask();
}
unsigned long __startup_secondary_64(void)
{
return sme_get_me_mask();
}
static void __init reset_early_page_tables(void)
{
memset(early_top_pgt, 0, sizeof(pgd_t)*(PTRS_PER_PGD-1));
next_early_pgt = 0;
write_cr3(__sme_pa_nodebug(early_top_pgt));
}
int __init __early_make_pgtable(unsigned long address, pmdval_t pmd)
{
unsigned long physaddr = address - __PAGE_OFFSET;
pgdval_t pgd, *pgd_p;
p4dval_t p4d, *p4d_p;
pudval_t pud, *pud_p;
pmdval_t *pmd_p;
if (physaddr >= MAXMEM || read_cr3_pa() != __pa_nodebug(early_top_pgt))
return -1;
again:
pgd_p = &early_top_pgt[pgd_index(address)].pgd;
pgd = *pgd_p;
if (!IS_ENABLED(CONFIG_X86_5LEVEL))
p4d_p = pgd_p;
else if (pgd)
p4d_p = (p4dval_t *)((pgd & PTE_PFN_MASK) + __START_KERNEL_map - phys_base);
else {
if (next_early_pgt >= EARLY_DYNAMIC_PAGE_TABLES) {
reset_early_page_tables();
goto again;
}
p4d_p = (p4dval_t *)early_dynamic_pgts[next_early_pgt++];
memset(p4d_p, 0, sizeof(*p4d_p) * PTRS_PER_P4D);
*pgd_p = (pgdval_t)p4d_p - __START_KERNEL_map + phys_base + _KERNPG_TABLE;
}
p4d_p += p4d_index(address);
p4d = *p4d_p;
if (p4d)
pud_p = (pudval_t *)((p4d & PTE_PFN_MASK) + __START_KERNEL_map - phys_base);
else {
if (next_early_pgt >= EARLY_DYNAMIC_PAGE_TABLES) {
reset_early_page_tables();
goto again;
}
pud_p = (pudval_t *)early_dynamic_pgts[next_early_pgt++];
memset(pud_p, 0, sizeof(*pud_p) * PTRS_PER_PUD);
*p4d_p = (p4dval_t)pud_p - __START_KERNEL_map + phys_base + _KERNPG_TABLE;
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
memset(pmd_p, 0, sizeof(*pmd_p) * PTRS_PER_PMD);
*pud_p = (pudval_t)pmd_p - __START_KERNEL_map + phys_base + _KERNPG_TABLE;
}
pmd_p[pmd_index(address)] = pmd;
return 0;
}
int __init early_make_pgtable(unsigned long address)
{
unsigned long physaddr = address - __PAGE_OFFSET;
pmdval_t pmd;
pmd = (physaddr & PMD_MASK) + early_pmd_flags;
return __early_make_pgtable(address, pmd);
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
sme_map_bootdata(real_mode_data);
memcpy(&boot_params, real_mode_data, sizeof boot_params);
sanitize_boot_params(&boot_params);
cmd_line_ptr = get_cmd_line_ptr();
if (cmd_line_ptr) {
command_line = __va(cmd_line_ptr);
memcpy(boot_command_line, command_line, COMMAND_LINE_SIZE);
}
sme_unmap_bootdata(real_mode_data);
}
asmlinkage __visible void __init x86_64_start_kernel(char * real_mode_data)
{
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
clear_page(init_top_pgt);
sme_early_init();
kasan_early_init();
idt_setup_early_handler();
copy_bootdata(__va(real_mode_data));
load_ucode_bsp();
init_top_pgt[511] = early_top_pgt[511];
x86_64_start_reservations(real_mode_data);
}
void __init x86_64_start_reservations(char *real_mode_data)
{
if (!boot_params.hdr.version)
copy_bootdata(__va(real_mode_data));
x86_early_init_platform_quirks();
switch (boot_params.hdr.hardware_subarch) {
case X86_SUBARCH_INTEL_MID:
x86_intel_mid_early_setup();
break;
default:
break;
}
start_kernel();
}
