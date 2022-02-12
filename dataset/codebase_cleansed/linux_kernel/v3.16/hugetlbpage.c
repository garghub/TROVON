int huge_pmd_unshare(struct mm_struct *mm, unsigned long *addr, pte_t *ptep)
{
return 0;
}
struct page *follow_huge_addr(struct mm_struct *mm, unsigned long address,
int write)
{
return ERR_PTR(-EINVAL);
}
int pmd_huge(pmd_t pmd)
{
return !(pmd_val(pmd) & PMD_TABLE_BIT);
}
int pud_huge(pud_t pud)
{
#ifndef __PAGETABLE_PMD_FOLDED
return !(pud_val(pud) & PUD_TABLE_BIT);
#else
return 0;
#endif
}
static __init int setup_hugepagesz(char *opt)
{
unsigned long ps = memparse(opt, &opt);
if (ps == PMD_SIZE) {
hugetlb_add_hstate(PMD_SHIFT - PAGE_SHIFT);
} else if (ps == PUD_SIZE) {
hugetlb_add_hstate(PUD_SHIFT - PAGE_SHIFT);
} else {
pr_err("hugepagesz: Unsupported page size %lu M\n", ps >> 20);
return 0;
}
return 1;
}
