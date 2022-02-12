static int handle_tlbmiss(unsigned long long protection_flags,
unsigned long address)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pte_t entry;
if (is_vmalloc_addr((void *)address)) {
pgd = pgd_offset_k(address);
} else {
if (unlikely(address >= TASK_SIZE || !current->mm))
return 1;
pgd = pgd_offset(current->mm, address);
}
pud = pud_offset(pgd, address);
if (pud_none(*pud) || !pud_present(*pud))
return 1;
pmd = pmd_offset(pud, address);
if (pmd_none(*pmd) || !pmd_present(*pmd))
return 1;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (pte_none(entry) || !pte_present(entry))
return 1;
if ((pte_val(entry) & protection_flags) != protection_flags)
return 1;
update_mmu_cache(NULL, address, pte);
return 0;
}
static inline unsigned int
expevt_to_fault_code(unsigned long expevt)
{
if (expevt == 0xa40)
return FAULT_CODE_ITLB;
else if (expevt == 0x060)
return FAULT_CODE_WRITE;
return 0;
}
asmlinkage int __kprobes
do_fast_page_fault(unsigned long long ssr_md, unsigned long long expevt,
unsigned long address)
{
unsigned long long protection_flags;
unsigned long long index;
unsigned long long expevt4;
unsigned int fault_code;
expevt4 = (expevt >> 4);
index = expevt4 ^ (expevt4 >> 5);
index &= 7;
fault_code = expevt_to_fault_code(expevt);
protection_flags = expevt_lookup_table.protection_flags[index];
if (expevt_lookup_table.is_text_access[index])
fault_code |= FAULT_CODE_ITLB;
if (!ssr_md)
fault_code |= FAULT_CODE_USER;
set_thread_fault_code(fault_code);
return handle_tlbmiss(protection_flags, address);
}
