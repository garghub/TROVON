asmlinkage int __kprobes
handle_tlbmiss(struct pt_regs *regs, unsigned long error_code,
unsigned long address)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pte_t entry;
if (address >= P3SEG && address < P3_ADDR_MAX) {
pgd = pgd_offset_k(address);
} else {
if (unlikely(address >= TASK_SIZE || !current->mm))
return 1;
pgd = pgd_offset(current->mm, address);
}
pud = pud_offset(pgd, address);
if (pud_none_or_clear_bad(pud))
return 1;
pmd = pmd_offset(pud, address);
if (pmd_none_or_clear_bad(pmd))
return 1;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (unlikely(pte_none(entry) || pte_not_present(entry)))
return 1;
if (unlikely(error_code && !pte_write(entry)))
return 1;
if (error_code)
entry = pte_mkdirty(entry);
entry = pte_mkyoung(entry);
set_pte(pte, entry);
#if defined(CONFIG_CPU_SH4) && !defined(CONFIG_SMP)
if (error_code == FAULT_CODE_INITIAL)
local_flush_tlb_one(get_asid(), address & PAGE_MASK);
#endif
set_thread_fault_code(error_code);
update_mmu_cache(NULL, address, pte);
return 0;
}
