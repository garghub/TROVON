static inline pte_t gup_get_pte(pte_t *ptep)
{
#ifndef CONFIG_X86_PAE
return READ_ONCE(*ptep);
#else
pte_t pte;
retry:
pte.pte_low = ptep->pte_low;
smp_rmb();
pte.pte_high = ptep->pte_high;
smp_rmb();
if (unlikely(pte.pte_low != ptep->pte_low))
goto retry;
return pte;
#endif
}
static void undo_dev_pagemap(int *nr, int nr_start, struct page **pages)
{
while ((*nr) - nr_start) {
struct page *page = pages[--(*nr)];
ClearPageReferenced(page);
put_page(page);
}
}
static inline int pte_allows_gup(unsigned long pteval, int write)
{
unsigned long need_pte_bits = _PAGE_PRESENT|_PAGE_USER;
if (write)
need_pte_bits |= _PAGE_RW;
if ((pteval & need_pte_bits) != need_pte_bits)
return 0;
if (!__pkru_allows_pkey(pte_flags_pkey(pteval), write))
return 0;
return 1;
}
static noinline int gup_pte_range(pmd_t pmd, unsigned long addr,
unsigned long end, int write, struct page **pages, int *nr)
{
struct dev_pagemap *pgmap = NULL;
int nr_start = *nr, ret = 0;
pte_t *ptep, *ptem;
ptem = ptep = pte_offset_map(&pmd, addr);
do {
pte_t pte = gup_get_pte(ptep);
struct page *page;
if (pte_protnone(pte))
break;
if (!pte_allows_gup(pte_val(pte), write))
break;
if (pte_devmap(pte)) {
pgmap = get_dev_pagemap(pte_pfn(pte), pgmap);
if (unlikely(!pgmap)) {
undo_dev_pagemap(nr, nr_start, pages);
break;
}
} else if (pte_special(pte))
break;
VM_BUG_ON(!pfn_valid(pte_pfn(pte)));
page = pte_page(pte);
get_page(page);
put_dev_pagemap(pgmap);
SetPageReferenced(page);
pages[*nr] = page;
(*nr)++;
} while (ptep++, addr += PAGE_SIZE, addr != end);
if (addr == end)
ret = 1;
pte_unmap(ptem);
return ret;
}
static inline void get_head_page_multiple(struct page *page, int nr)
{
VM_BUG_ON_PAGE(page != compound_head(page), page);
VM_BUG_ON_PAGE(page_count(page) == 0, page);
page_ref_add(page, nr);
SetPageReferenced(page);
}
static int __gup_device_huge(unsigned long pfn, unsigned long addr,
unsigned long end, struct page **pages, int *nr)
{
int nr_start = *nr;
struct dev_pagemap *pgmap = NULL;
do {
struct page *page = pfn_to_page(pfn);
pgmap = get_dev_pagemap(pfn, pgmap);
if (unlikely(!pgmap)) {
undo_dev_pagemap(nr, nr_start, pages);
return 0;
}
SetPageReferenced(page);
pages[*nr] = page;
get_page(page);
put_dev_pagemap(pgmap);
(*nr)++;
pfn++;
} while (addr += PAGE_SIZE, addr != end);
return 1;
}
static int __gup_device_huge_pmd(pmd_t pmd, unsigned long addr,
unsigned long end, struct page **pages, int *nr)
{
unsigned long fault_pfn;
fault_pfn = pmd_pfn(pmd) + ((addr & ~PMD_MASK) >> PAGE_SHIFT);
return __gup_device_huge(fault_pfn, addr, end, pages, nr);
}
static int __gup_device_huge_pud(pud_t pud, unsigned long addr,
unsigned long end, struct page **pages, int *nr)
{
unsigned long fault_pfn;
fault_pfn = pud_pfn(pud) + ((addr & ~PUD_MASK) >> PAGE_SHIFT);
return __gup_device_huge(fault_pfn, addr, end, pages, nr);
}
static noinline int gup_huge_pmd(pmd_t pmd, unsigned long addr,
unsigned long end, int write, struct page **pages, int *nr)
{
struct page *head, *page;
int refs;
if (!pte_allows_gup(pmd_val(pmd), write))
return 0;
VM_BUG_ON(!pfn_valid(pmd_pfn(pmd)));
if (pmd_devmap(pmd))
return __gup_device_huge_pmd(pmd, addr, end, pages, nr);
VM_BUG_ON(pmd_flags(pmd) & _PAGE_SPECIAL);
refs = 0;
head = pmd_page(pmd);
page = head + ((addr & ~PMD_MASK) >> PAGE_SHIFT);
do {
VM_BUG_ON_PAGE(compound_head(page) != head, page);
pages[*nr] = page;
(*nr)++;
page++;
refs++;
} while (addr += PAGE_SIZE, addr != end);
get_head_page_multiple(head, refs);
return 1;
}
static int gup_pmd_range(pud_t pud, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
unsigned long next;
pmd_t *pmdp;
pmdp = pmd_offset(&pud, addr);
do {
pmd_t pmd = *pmdp;
next = pmd_addr_end(addr, end);
if (pmd_none(pmd))
return 0;
if (unlikely(pmd_large(pmd) || !pmd_present(pmd))) {
if (pmd_protnone(pmd))
return 0;
if (!gup_huge_pmd(pmd, addr, next, write, pages, nr))
return 0;
} else {
if (!gup_pte_range(pmd, addr, next, write, pages, nr))
return 0;
}
} while (pmdp++, addr = next, addr != end);
return 1;
}
static noinline int gup_huge_pud(pud_t pud, unsigned long addr,
unsigned long end, int write, struct page **pages, int *nr)
{
struct page *head, *page;
int refs;
if (!pte_allows_gup(pud_val(pud), write))
return 0;
VM_BUG_ON(!pfn_valid(pud_pfn(pud)));
if (pud_devmap(pud))
return __gup_device_huge_pud(pud, addr, end, pages, nr);
VM_BUG_ON(pud_flags(pud) & _PAGE_SPECIAL);
refs = 0;
head = pud_page(pud);
page = head + ((addr & ~PUD_MASK) >> PAGE_SHIFT);
do {
VM_BUG_ON_PAGE(compound_head(page) != head, page);
pages[*nr] = page;
(*nr)++;
page++;
refs++;
} while (addr += PAGE_SIZE, addr != end);
get_head_page_multiple(head, refs);
return 1;
}
static int gup_pud_range(p4d_t p4d, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
unsigned long next;
pud_t *pudp;
pudp = pud_offset(&p4d, addr);
do {
pud_t pud = *pudp;
next = pud_addr_end(addr, end);
if (pud_none(pud))
return 0;
if (unlikely(pud_large(pud))) {
if (!gup_huge_pud(pud, addr, next, write, pages, nr))
return 0;
} else {
if (!gup_pmd_range(pud, addr, next, write, pages, nr))
return 0;
}
} while (pudp++, addr = next, addr != end);
return 1;
}
static int gup_p4d_range(pgd_t pgd, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
unsigned long next;
p4d_t *p4dp;
p4dp = p4d_offset(&pgd, addr);
do {
p4d_t p4d = *p4dp;
next = p4d_addr_end(addr, end);
if (p4d_none(p4d))
return 0;
BUILD_BUG_ON(p4d_large(p4d));
if (!gup_pud_range(p4d, addr, next, write, pages, nr))
return 0;
} while (p4dp++, addr = next, addr != end);
return 1;
}
int __get_user_pages_fast(unsigned long start, int nr_pages, int write,
struct page **pages)
{
struct mm_struct *mm = current->mm;
unsigned long addr, len, end;
unsigned long next;
unsigned long flags;
pgd_t *pgdp;
int nr = 0;
start &= PAGE_MASK;
addr = start;
len = (unsigned long) nr_pages << PAGE_SHIFT;
end = start + len;
if (unlikely(!access_ok(write ? VERIFY_WRITE : VERIFY_READ,
(void __user *)start, len)))
return 0;
local_irq_save(flags);
pgdp = pgd_offset(mm, addr);
do {
pgd_t pgd = *pgdp;
next = pgd_addr_end(addr, end);
if (pgd_none(pgd))
break;
if (!gup_p4d_range(pgd, addr, next, write, pages, &nr))
break;
} while (pgdp++, addr = next, addr != end);
local_irq_restore(flags);
return nr;
}
int get_user_pages_fast(unsigned long start, int nr_pages, int write,
struct page **pages)
{
struct mm_struct *mm = current->mm;
unsigned long addr, len, end;
unsigned long next;
pgd_t *pgdp;
int nr = 0;
start &= PAGE_MASK;
addr = start;
len = (unsigned long) nr_pages << PAGE_SHIFT;
end = start + len;
if (end < start)
goto slow_irqon;
#ifdef CONFIG_X86_64
if (end >> __VIRTUAL_MASK_SHIFT)
goto slow_irqon;
#endif
local_irq_disable();
pgdp = pgd_offset(mm, addr);
do {
pgd_t pgd = *pgdp;
next = pgd_addr_end(addr, end);
if (pgd_none(pgd))
goto slow;
if (!gup_p4d_range(pgd, addr, next, write, pages, &nr))
goto slow;
} while (pgdp++, addr = next, addr != end);
local_irq_enable();
VM_BUG_ON(nr != (end - start) >> PAGE_SHIFT);
return nr;
{
int ret;
slow:
local_irq_enable();
slow_irqon:
start += nr << PAGE_SHIFT;
pages += nr;
ret = get_user_pages_unlocked(start,
(end - start) >> PAGE_SHIFT,
pages, write ? FOLL_WRITE : 0);
if (nr > 0) {
if (ret < 0)
ret = nr;
else
ret += nr;
}
return ret;
}
}
