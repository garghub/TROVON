int pmd_huge(pmd_t pmd)
{
return pmd_val(pmd) && !(pmd_val(pmd) & PMD_TABLE_BIT);
}
int pud_huge(pud_t pud)
{
#ifndef __PAGETABLE_PMD_FOLDED
return pud_val(pud) && !(pud_val(pud) & PUD_TABLE_BIT);
#else
return 0;
#endif
}
static inline pgprot_t pte_pgprot(pte_t pte)
{
unsigned long pfn = pte_pfn(pte);
return __pgprot(pte_val(pfn_pte(pfn, __pgprot(0))) ^ pte_val(pte));
}
static int find_num_contig(struct mm_struct *mm, unsigned long addr,
pte_t *ptep, size_t *pgsize)
{
pgd_t *pgd = pgd_offset(mm, addr);
pud_t *pud;
pmd_t *pmd;
*pgsize = PAGE_SIZE;
pud = pud_offset(pgd, addr);
pmd = pmd_offset(pud, addr);
if ((pte_t *)pmd == ptep) {
*pgsize = PMD_SIZE;
return CONT_PMDS;
}
return CONT_PTES;
}
static inline int num_contig_ptes(unsigned long size, size_t *pgsize)
{
int contig_ptes = 0;
*pgsize = size;
switch (size) {
#ifdef CONFIG_ARM64_4K_PAGES
case PUD_SIZE:
#endif
case PMD_SIZE:
contig_ptes = 1;
break;
case CONT_PMD_SIZE:
*pgsize = PMD_SIZE;
contig_ptes = CONT_PMDS;
break;
case CONT_PTE_SIZE:
*pgsize = PAGE_SIZE;
contig_ptes = CONT_PTES;
break;
}
return contig_ptes;
}
static pte_t get_clear_flush(struct mm_struct *mm,
unsigned long addr,
pte_t *ptep,
unsigned long pgsize,
unsigned long ncontig)
{
struct vm_area_struct vma = { .vm_mm = mm };
pte_t orig_pte = huge_ptep_get(ptep);
bool valid = pte_valid(orig_pte);
unsigned long i, saddr = addr;
for (i = 0; i < ncontig; i++, addr += pgsize, ptep++) {
pte_t pte = ptep_get_and_clear(mm, addr, ptep);
if (pte_dirty(pte))
orig_pte = pte_mkdirty(orig_pte);
}
if (valid)
flush_tlb_range(&vma, saddr, addr);
return orig_pte;
}
static void clear_flush(struct mm_struct *mm,
unsigned long addr,
pte_t *ptep,
unsigned long pgsize,
unsigned long ncontig)
{
struct vm_area_struct vma = { .vm_mm = mm };
unsigned long i, saddr = addr;
for (i = 0; i < ncontig; i++, addr += pgsize, ptep++)
pte_clear(mm, addr, ptep);
flush_tlb_range(&vma, saddr, addr);
}
void set_huge_pte_at(struct mm_struct *mm, unsigned long addr,
pte_t *ptep, pte_t pte)
{
size_t pgsize;
int i;
int ncontig;
unsigned long pfn, dpfn;
pgprot_t hugeprot;
WARN_ON(!pte_present(pte));
if (!pte_cont(pte)) {
set_pte_at(mm, addr, ptep, pte);
return;
}
ncontig = find_num_contig(mm, addr, ptep, &pgsize);
pfn = pte_pfn(pte);
dpfn = pgsize >> PAGE_SHIFT;
hugeprot = pte_pgprot(pte);
clear_flush(mm, addr, ptep, pgsize, ncontig);
for (i = 0; i < ncontig; i++, ptep++, addr += pgsize, pfn += dpfn) {
pr_debug("%s: set pte %p to 0x%llx\n", __func__, ptep,
pte_val(pfn_pte(pfn, hugeprot)));
set_pte_at(mm, addr, ptep, pfn_pte(pfn, hugeprot));
}
}
void set_huge_swap_pte_at(struct mm_struct *mm, unsigned long addr,
pte_t *ptep, pte_t pte, unsigned long sz)
{
int i, ncontig;
size_t pgsize;
ncontig = num_contig_ptes(sz, &pgsize);
for (i = 0; i < ncontig; i++, ptep++)
set_pte(ptep, pte);
}
pte_t *huge_pte_alloc(struct mm_struct *mm,
unsigned long addr, unsigned long sz)
{
pgd_t *pgd;
pud_t *pud;
pte_t *pte = NULL;
pr_debug("%s: addr:0x%lx sz:0x%lx\n", __func__, addr, sz);
pgd = pgd_offset(mm, addr);
pud = pud_alloc(mm, pgd, addr);
if (!pud)
return NULL;
if (sz == PUD_SIZE) {
pte = (pte_t *)pud;
} else if (sz == (PAGE_SIZE * CONT_PTES)) {
pmd_t *pmd = pmd_alloc(mm, pud, addr);
WARN_ON(addr & (sz - 1));
pte = pte_alloc_map(mm, pmd, addr);
} else if (sz == PMD_SIZE) {
if (IS_ENABLED(CONFIG_ARCH_WANT_HUGE_PMD_SHARE) &&
pud_none(*pud))
pte = huge_pmd_share(mm, addr, pud);
else
pte = (pte_t *)pmd_alloc(mm, pud, addr);
} else if (sz == (PMD_SIZE * CONT_PMDS)) {
pmd_t *pmd;
pmd = pmd_alloc(mm, pud, addr);
WARN_ON(addr & (sz - 1));
return (pte_t *)pmd;
}
pr_debug("%s: addr:0x%lx sz:0x%lx ret pte=%p/0x%llx\n", __func__, addr,
sz, pte, pte_val(*pte));
return pte;
}
pte_t *huge_pte_offset(struct mm_struct *mm,
unsigned long addr, unsigned long sz)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pgd = pgd_offset(mm, addr);
pr_debug("%s: addr:0x%lx pgd:%p\n", __func__, addr, pgd);
if (!pgd_present(*pgd))
return NULL;
pud = pud_offset(pgd, addr);
if (sz != PUD_SIZE && pud_none(*pud))
return NULL;
if (pud_huge(*pud) || !pud_present(*pud))
return (pte_t *)pud;
if (sz == CONT_PMD_SIZE)
addr &= CONT_PMD_MASK;
pmd = pmd_offset(pud, addr);
if (!(sz == PMD_SIZE || sz == CONT_PMD_SIZE) &&
pmd_none(*pmd))
return NULL;
if (pmd_huge(*pmd) || !pmd_present(*pmd))
return (pte_t *)pmd;
if (sz == CONT_PTE_SIZE) {
pte_t *pte = pte_offset_kernel(pmd, (addr & CONT_PTE_MASK));
return pte;
}
return NULL;
}
pte_t arch_make_huge_pte(pte_t entry, struct vm_area_struct *vma,
struct page *page, int writable)
{
size_t pagesize = huge_page_size(hstate_vma(vma));
if (pagesize == CONT_PTE_SIZE) {
entry = pte_mkcont(entry);
} else if (pagesize == CONT_PMD_SIZE) {
entry = pmd_pte(pmd_mkcont(pte_pmd(entry)));
} else if (pagesize != PUD_SIZE && pagesize != PMD_SIZE) {
pr_warn("%s: unrecognized huge page size 0x%lx\n",
__func__, pagesize);
}
return entry;
}
void huge_pte_clear(struct mm_struct *mm, unsigned long addr,
pte_t *ptep, unsigned long sz)
{
int i, ncontig;
size_t pgsize;
ncontig = num_contig_ptes(sz, &pgsize);
for (i = 0; i < ncontig; i++, addr += pgsize, ptep++)
pte_clear(mm, addr, ptep);
}
pte_t huge_ptep_get_and_clear(struct mm_struct *mm,
unsigned long addr, pte_t *ptep)
{
int ncontig;
size_t pgsize;
pte_t orig_pte = huge_ptep_get(ptep);
if (!pte_cont(orig_pte))
return ptep_get_and_clear(mm, addr, ptep);
ncontig = find_num_contig(mm, addr, ptep, &pgsize);
return get_clear_flush(mm, addr, ptep, pgsize, ncontig);
}
int huge_ptep_set_access_flags(struct vm_area_struct *vma,
unsigned long addr, pte_t *ptep,
pte_t pte, int dirty)
{
int ncontig, i, changed = 0;
size_t pgsize = 0;
unsigned long pfn = pte_pfn(pte), dpfn;
pgprot_t hugeprot;
pte_t orig_pte;
if (!pte_cont(pte))
return ptep_set_access_flags(vma, addr, ptep, pte, dirty);
ncontig = find_num_contig(vma->vm_mm, addr, ptep, &pgsize);
dpfn = pgsize >> PAGE_SHIFT;
orig_pte = get_clear_flush(vma->vm_mm, addr, ptep, pgsize, ncontig);
if (!pte_same(orig_pte, pte))
changed = 1;
if (pte_dirty(orig_pte))
pte = pte_mkdirty(pte);
hugeprot = pte_pgprot(pte);
for (i = 0; i < ncontig; i++, ptep++, addr += pgsize, pfn += dpfn)
set_pte_at(vma->vm_mm, addr, ptep, pfn_pte(pfn, hugeprot));
return changed;
}
void huge_ptep_set_wrprotect(struct mm_struct *mm,
unsigned long addr, pte_t *ptep)
{
unsigned long pfn, dpfn;
pgprot_t hugeprot;
int ncontig, i;
size_t pgsize;
pte_t pte;
if (!pte_cont(*ptep)) {
ptep_set_wrprotect(mm, addr, ptep);
return;
}
ncontig = find_num_contig(mm, addr, ptep, &pgsize);
dpfn = pgsize >> PAGE_SHIFT;
pte = get_clear_flush(mm, addr, ptep, pgsize, ncontig);
pte = pte_wrprotect(pte);
hugeprot = pte_pgprot(pte);
pfn = pte_pfn(pte);
for (i = 0; i < ncontig; i++, ptep++, addr += pgsize, pfn += dpfn)
set_pte_at(mm, addr, ptep, pfn_pte(pfn, hugeprot));
}
void huge_ptep_clear_flush(struct vm_area_struct *vma,
unsigned long addr, pte_t *ptep)
{
size_t pgsize;
int ncontig;
if (!pte_cont(*ptep)) {
ptep_clear_flush(vma, addr, ptep);
return;
}
ncontig = find_num_contig(vma->vm_mm, addr, ptep, &pgsize);
clear_flush(vma->vm_mm, addr, ptep, pgsize, ncontig);
}
static __init int setup_hugepagesz(char *opt)
{
unsigned long ps = memparse(opt, &opt);
switch (ps) {
#ifdef CONFIG_ARM64_4K_PAGES
case PUD_SIZE:
#endif
case PMD_SIZE * CONT_PMDS:
case PMD_SIZE:
case PAGE_SIZE * CONT_PTES:
hugetlb_add_hstate(ilog2(ps) - PAGE_SHIFT);
return 1;
}
hugetlb_bad_size();
pr_err("hugepagesz: Unsupported page size %lu K\n", ps >> 10);
return 0;
}
static __init int add_default_hugepagesz(void)
{
if (size_to_hstate(CONT_PTES * PAGE_SIZE) == NULL)
hugetlb_add_hstate(CONT_PTE_SHIFT);
return 0;
}
