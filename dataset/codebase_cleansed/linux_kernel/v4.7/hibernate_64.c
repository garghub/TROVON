static int set_up_temporary_text_mapping(void)
{
pmd_t *pmd;
pud_t *pud;
pud = (pud_t *)get_safe_page(GFP_ATOMIC);
if (!pud)
return -ENOMEM;
pmd = (pmd_t *)get_safe_page(GFP_ATOMIC);
if (!pmd)
return -ENOMEM;
set_pmd(pmd + pmd_index(restore_jump_address),
__pmd((jump_address_phys & PMD_MASK) | __PAGE_KERNEL_LARGE_EXEC));
set_pud(pud + pud_index(restore_jump_address),
__pud(__pa(pmd) | _KERNPG_TABLE));
set_pgd(temp_level4_pgt + pgd_index(restore_jump_address),
__pgd(__pa(pud) | _KERNPG_TABLE));
return 0;
}
static void *alloc_pgt_page(void *context)
{
return (void *)get_safe_page(GFP_ATOMIC);
}
static int set_up_temporary_mappings(void)
{
struct x86_mapping_info info = {
.alloc_pgt_page = alloc_pgt_page,
.pmd_flag = __PAGE_KERNEL_LARGE_EXEC,
.kernel_mapping = true,
};
unsigned long mstart, mend;
int result;
int i;
temp_level4_pgt = (pgd_t *)get_safe_page(GFP_ATOMIC);
if (!temp_level4_pgt)
return -ENOMEM;
result = set_up_temporary_text_mapping();
if (result)
return result;
for (i = 0; i < nr_pfn_mapped; i++) {
mstart = pfn_mapped[i].start << PAGE_SHIFT;
mend = pfn_mapped[i].end << PAGE_SHIFT;
result = kernel_ident_mapping_init(&info, temp_level4_pgt,
mstart, mend);
if (result)
return result;
}
return 0;
}
static int relocate_restore_code(void)
{
pgd_t *pgd;
pud_t *pud;
relocated_restore_code = get_safe_page(GFP_ATOMIC);
if (!relocated_restore_code)
return -ENOMEM;
memcpy((void *)relocated_restore_code, &core_restore_code, PAGE_SIZE);
pgd = (pgd_t *)__va(read_cr3()) + pgd_index(relocated_restore_code);
pud = pud_offset(pgd, relocated_restore_code);
if (pud_large(*pud)) {
set_pud(pud, __pud(pud_val(*pud) & ~_PAGE_NX));
} else {
pmd_t *pmd = pmd_offset(pud, relocated_restore_code);
if (pmd_large(*pmd)) {
set_pmd(pmd, __pmd(pmd_val(*pmd) & ~_PAGE_NX));
} else {
pte_t *pte = pte_offset_kernel(pmd, relocated_restore_code);
set_pte(pte, __pte(pte_val(*pte) & ~_PAGE_NX));
}
}
__flush_tlb_all();
return 0;
}
int swsusp_arch_resume(void)
{
int error;
error = set_up_temporary_mappings();
if (error)
return error;
error = relocate_restore_code();
if (error)
return error;
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
rdr->jump_address = (unsigned long)&restore_registers;
rdr->jump_address_phys = __pa_symbol(&restore_registers);
rdr->cr3 = restore_cr3;
rdr->magic = RESTORE_MAGIC;
return 0;
}
int arch_hibernation_header_restore(void *addr)
{
struct restore_data_record *rdr = addr;
restore_jump_address = rdr->jump_address;
jump_address_phys = rdr->jump_address_phys;
restore_cr3 = rdr->cr3;
return (rdr->magic == RESTORE_MAGIC) ? 0 : -EINVAL;
}
