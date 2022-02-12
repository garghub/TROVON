static int res_phys_pud_init(pud_t *pud, unsigned long address, unsigned long end)
{
long i, j;
i = pud_index(address);
pud = pud + i;
for (; i < PTRS_PER_PUD; pud++, i++) {
unsigned long paddr;
pmd_t *pmd;
paddr = address + i*PUD_SIZE;
if (paddr >= end)
break;
pmd = (pmd_t *)get_safe_page(GFP_ATOMIC);
if (!pmd)
return -ENOMEM;
set_pud(pud, __pud(__pa(pmd) | _KERNPG_TABLE));
for (j = 0; j < PTRS_PER_PMD; pmd++, j++, paddr += PMD_SIZE) {
unsigned long pe;
if (paddr >= end)
break;
pe = __PAGE_KERNEL_LARGE_EXEC | paddr;
pe &= __supported_pte_mask;
set_pmd(pmd, __pmd(pe));
}
}
return 0;
}
static int set_up_temporary_mappings(void)
{
unsigned long start, end, next;
int error;
temp_level4_pgt = (pgd_t *)get_safe_page(GFP_ATOMIC);
if (!temp_level4_pgt)
return -ENOMEM;
set_pgd(temp_level4_pgt + pgd_index(__START_KERNEL_map),
init_level4_pgt[pgd_index(__START_KERNEL_map)]);
start = (unsigned long)pfn_to_kaddr(0);
end = (unsigned long)pfn_to_kaddr(max_pfn);
for (; start < end; start = next) {
pud_t *pud = (pud_t *)get_safe_page(GFP_ATOMIC);
if (!pud)
return -ENOMEM;
next = start + PGDIR_SIZE;
if (next > end)
next = end;
if ((error = res_phys_pud_init(pud, __pa(start), __pa(next))))
return error;
set_pgd(temp_level4_pgt + pgd_index(start),
mk_kernel_pgd(__pa(pud)));
}
return 0;
}
int swsusp_arch_resume(void)
{
int error;
if ((error = set_up_temporary_mappings()))
return error;
relocated_restore_code = (void *)get_safe_page(GFP_ATOMIC);
if (!relocated_restore_code)
return -ENOMEM;
memcpy(relocated_restore_code, &core_restore_code,
&restore_registers - &core_restore_code);
restore_image();
return 0;
}
int pfn_is_nosave(unsigned long pfn)
{
unsigned long nosave_begin_pfn = __pa_symbol(&__nosave_begin) >> PAGE_SHIFT;
unsigned long nosave_end_pfn = PAGE_ALIGN(__pa_symbol(&__nosave_end)) >> PAGE_SHIFT;
return (pfn >= nosave_begin_pfn) && (pfn < nosave_end_pfn);
}
int arch_hibernation_header_save(void *addr, unsigned int max_size)
{
struct restore_data_record *rdr = addr;
if (max_size < sizeof(struct restore_data_record))
return -EOVERFLOW;
rdr->jump_address = restore_jump_address;
rdr->cr3 = restore_cr3;
rdr->magic = RESTORE_MAGIC;
return 0;
}
int arch_hibernation_header_restore(void *addr)
{
struct restore_data_record *rdr = addr;
restore_jump_address = rdr->jump_address;
restore_cr3 = rdr->cr3;
return (rdr->magic == RESTORE_MAGIC) ? 0 : -EINVAL;
}
