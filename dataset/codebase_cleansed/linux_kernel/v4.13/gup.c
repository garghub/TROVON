static inline pte_t gup_get_pte(pte_t *ptep)
{
#if defined(CONFIG_PHYS_ADDR_T_64BIT) && defined(CONFIG_CPU_MIPS32)
pte_t pte;
retry:
pte.pte_low = ptep->pte_low;
smp_rmb();
pte.pte_high = ptep->pte_high;
smp_rmb();
if (unlikely(pte.pte_low != ptep->pte_low))
goto retry;
return pte;
#else
return READ_ONCE(*ptep);
#endif
}
static int gup_pte_range(pmd_t pmd, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
pte_t *ptep = pte_offset_map(&pmd, addr);
do {
pte_t pte = gup_get_pte(ptep);
struct page *page;
if (!pte_present(pte) ||
pte_special(pte) || (write && !pte_write(pte))) {
pte_unmap(ptep);
return 0;
}
VM_BUG_ON(!pfn_valid(pte_pfn(pte)));
page = pte_page(pte);
get_page(page);
SetPageReferenced(page);
pages[*nr] = page;
(*nr)++;
} while (ptep++, addr += PAGE_SIZE, addr != end);
pte_unmap(ptep - 1);
return 1;
}
static inline void get_head_page_multiple(struct page *page, int nr)
{
VM_BUG_ON(page != compound_head(page));
VM_BUG_ON(page_count(page) == 0);
page_ref_add(page, nr);
SetPageReferenced(page);
}
static int gup_huge_pmd(pmd_t pmd, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
pte_t pte = *(pte_t *)&pmd;
struct page *head, *page;
int refs;
if (write && !pte_write(pte))
return 0;
VM_BUG_ON(pte_special(pte));
VM_BUG_ON(!pfn_valid(pte_pfn(pte)));
refs = 0;
head = pte_page(pte);
page = head + ((addr & ~PMD_MASK) >> PAGE_SHIFT);
do {
VM_BUG_ON(compound_head(page) != head);
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
if (unlikely(pmd_huge(pmd))) {
if (!gup_huge_pmd(pmd, addr, next, write, pages,nr))
return 0;
} else {
if (!gup_pte_range(pmd, addr, next, write, pages,nr))
return 0;
}
} while (pmdp++, addr = next, addr != end);
return 1;
}
static int gup_huge_pud(pud_t pud, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
pte_t pte = *(pte_t *)&pud;
struct page *head, *page;
int refs;
if (write && !pte_write(pte))
return 0;
VM_BUG_ON(pte_special(pte));
VM_BUG_ON(!pfn_valid(pte_pfn(pte)));
refs = 0;
head = pte_page(pte);
page = head + ((addr & ~PUD_MASK) >> PAGE_SHIFT);
do {
VM_BUG_ON(compound_head(page) != head);
pages[*nr] = page;
(*nr)++;
page++;
refs++;
} while (addr += PAGE_SIZE, addr != end);
get_head_page_multiple(head, refs);
return 1;
}
static int gup_pud_range(pgd_t pgd, unsigned long addr, unsigned long end,
int write, struct page **pages, int *nr)
{
unsigned long next;
pud_t *pudp;
pudp = pud_offset(&pgd, addr);
do {
pud_t pud = *pudp;
next = pud_addr_end(addr, end);
if (pud_none(pud))
return 0;
if (unlikely(pud_huge(pud))) {
if (!gup_huge_pud(pud, addr, next, write, pages,nr))
return 0;
} else {
if (!gup_pmd_range(pud, addr, next, write, pages,nr))
return 0;
}
} while (pudp++, addr = next, addr != end);
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
if (!gup_pud_range(pgd, addr, next, write, pages, &nr))
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
int ret, nr = 0;
start &= PAGE_MASK;
addr = start;
len = (unsigned long) nr_pages << PAGE_SHIFT;
end = start + len;
if (end < start || cpu_has_dc_aliases)
goto slow_irqon;
local_irq_disable();
pgdp = pgd_offset(mm, addr);
do {
pgd_t pgd = *pgdp;
next = pgd_addr_end(addr, end);
if (pgd_none(pgd))
goto slow;
if (!gup_pud_range(pgd, addr, next, write, pages, &nr))
goto slow;
} while (pgdp++, addr = next, addr != end);
local_irq_enable();
VM_BUG_ON(nr != (end - start) >> PAGE_SHIFT);
return nr;
slow:
local_irq_enable();
slow_irqon:
start += nr << PAGE_SHIFT;
pages += nr;
ret = get_user_pages_unlocked(start, (end - start) >> PAGE_SHIFT,
pages, write ? FOLL_WRITE : 0);
if (nr > 0) {
if (ret < 0)
ret = nr;
else
ret += nr;
}
return ret;
}
