inline void __do_tlb_refill(unsigned long address,
unsigned long long is_text_not_data, pte_t *pte)
{
unsigned long long ptel;
unsigned long long pteh=0;
struct tlb_info *tlbp;
unsigned long long next;
ptel = pte_val(*pte);
pteh = neff_sign_extend(address & MMU_VPN_MASK);
pteh |= get_asid() << PTEH_ASID_SHIFT;
pteh |= PTEH_VALID;
ptel &= _PAGE_FLAGS_HARDWARE_MASK;
tlbp = is_text_not_data ? &(cpu_data->itlb) : &(cpu_data->dtlb);
next = tlbp->next;
__flush_tlb_slot(next);
asm volatile ("putcfg %0,1,%2\n\n\t"
"putcfg %0,0,%1\n"
: : "r" (next), "r" (pteh), "r" (ptel) );
next += TLB_STEP;
if (next > tlbp->last) next = tlbp->first;
tlbp->next = next;
}
static int handle_vmalloc_fault(struct mm_struct *mm,
unsigned long protection_flags,
unsigned long long textaccess,
unsigned long address)
{
pgd_t *dir;
pud_t *pud;
pmd_t *pmd;
static pte_t *pte;
pte_t entry;
dir = pgd_offset_k(address);
pud = pud_offset(dir, address);
if (pud_none_or_clear_bad(pud))
return 0;
pmd = pmd_offset(pud, address);
if (pmd_none_or_clear_bad(pmd))
return 0;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (pte_none(entry) || !pte_present(entry))
return 0;
if ((pte_val(entry) & protection_flags) != protection_flags)
return 0;
__do_tlb_refill(address, textaccess, pte);
return 1;
}
static int handle_tlbmiss(struct mm_struct *mm,
unsigned long long protection_flags,
unsigned long long textaccess,
unsigned long address)
{
pgd_t *dir;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pte_t entry;
if (address >= (unsigned long) TASK_SIZE)
return 0;
dir = pgd_offset(mm, address);
if (pgd_none(*dir) || !pgd_present(*dir))
return 0;
if (!pgd_present(*dir))
return 0;
pud = pud_offset(dir, address);
if (pud_none(*pud) || !pud_present(*pud))
return 0;
pmd = pmd_offset(pud, address);
if (pmd_none(*pmd) || !pmd_present(*pmd))
return 0;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (pte_none(entry) || !pte_present(entry))
return 0;
if ((pte_val(entry) & protection_flags) != protection_flags)
return 0;
__do_tlb_refill(address, textaccess, pte);
return 1;
}
asmlinkage int do_fast_page_fault(unsigned long long ssr_md,
unsigned long long expevt,
unsigned long address)
{
struct task_struct *tsk;
struct mm_struct *mm;
unsigned long long textaccess;
unsigned long long protection_flags;
unsigned long long index;
unsigned long long expevt4;
expevt4 = (expevt >> 4);
index = expevt4 ^ (expevt4 >> 5);
index &= 7;
protection_flags = expevt_lookup_table.protection_flags[index];
textaccess = expevt_lookup_table.is_text_access[index];
tsk = current;
mm = tsk->mm;
if ((address >= VMALLOC_START && address < VMALLOC_END) ||
(address >= IOBASE_VADDR && address < IOBASE_END)) {
if (ssr_md)
if (handle_vmalloc_fault(mm, protection_flags,
textaccess, address))
return 1;
} else if (!in_interrupt() && mm) {
if (handle_tlbmiss(mm, protection_flags, textaccess, address))
return 1;
}
return 0;
}
