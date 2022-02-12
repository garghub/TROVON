static int
pin_page_for_write(const void __user *_addr, pte_t **ptep, spinlock_t **ptlp)
{
unsigned long addr = (unsigned long)_addr;
pgd_t *pgd;
pmd_t *pmd;
pte_t *pte;
pud_t *pud;
spinlock_t *ptl;
pgd = pgd_offset(current->mm, addr);
if (unlikely(pgd_none(*pgd) || pgd_bad(*pgd)))
return 0;
pud = pud_offset(pgd, addr);
if (unlikely(pud_none(*pud) || pud_bad(*pud)))
return 0;
pmd = pmd_offset(pud, addr);
if (unlikely(pmd_none(*pmd)))
return 0;
if (unlikely(pmd_thp_or_huge(*pmd))) {
ptl = &current->mm->page_table_lock;
spin_lock(ptl);
if (unlikely(!pmd_thp_or_huge(*pmd)
|| pmd_hugewillfault(*pmd)
|| pmd_trans_splitting(*pmd))) {
spin_unlock(ptl);
return 0;
}
*ptep = NULL;
*ptlp = ptl;
return 1;
}
if (unlikely(pmd_bad(*pmd)))
return 0;
pte = pte_offset_map_lock(current->mm, pmd, addr, &ptl);
if (unlikely(!pte_present(*pte) || !pte_young(*pte) ||
!pte_write(*pte) || !pte_dirty(*pte))) {
pte_unmap_unlock(pte, ptl);
return 0;
}
*ptep = pte;
*ptlp = ptl;
return 1;
}
static unsigned long noinline
__copy_to_user_memcpy(void __user *to, const void *from, unsigned long n)
{
int atomic;
if (unlikely(segment_eq(get_fs(), KERNEL_DS))) {
memcpy((void *)to, from, n);
return 0;
}
atomic = faulthandler_disabled();
if (!atomic)
down_read(&current->mm->mmap_sem);
while (n) {
pte_t *pte;
spinlock_t *ptl;
int tocopy;
while (!pin_page_for_write(to, &pte, &ptl)) {
if (!atomic)
up_read(&current->mm->mmap_sem);
if (__put_user(0, (char __user *)to))
goto out;
if (!atomic)
down_read(&current->mm->mmap_sem);
}
tocopy = (~(unsigned long)to & ~PAGE_MASK) + 1;
if (tocopy > n)
tocopy = n;
memcpy((void *)to, from, tocopy);
to += tocopy;
from += tocopy;
n -= tocopy;
if (pte)
pte_unmap_unlock(pte, ptl);
else
spin_unlock(ptl);
}
if (!atomic)
up_read(&current->mm->mmap_sem);
out:
return n;
}
unsigned long
arm_copy_to_user(void __user *to, const void *from, unsigned long n)
{
if (n < 64)
return __copy_to_user_std(to, from, n);
return __copy_to_user_memcpy(to, from, n);
}
static unsigned long noinline
__clear_user_memset(void __user *addr, unsigned long n)
{
if (unlikely(segment_eq(get_fs(), KERNEL_DS))) {
memset((void *)addr, 0, n);
return 0;
}
down_read(&current->mm->mmap_sem);
while (n) {
pte_t *pte;
spinlock_t *ptl;
int tocopy;
while (!pin_page_for_write(addr, &pte, &ptl)) {
up_read(&current->mm->mmap_sem);
if (__put_user(0, (char __user *)addr))
goto out;
down_read(&current->mm->mmap_sem);
}
tocopy = (~(unsigned long)addr & ~PAGE_MASK) + 1;
if (tocopy > n)
tocopy = n;
memset((void *)addr, 0, tocopy);
addr += tocopy;
n -= tocopy;
if (pte)
pte_unmap_unlock(pte, ptl);
else
spin_unlock(ptl);
}
up_read(&current->mm->mmap_sem);
out:
return n;
}
unsigned long arm_clear_user(void __user *addr, unsigned long n)
{
if (n < 64)
return __clear_user_std(addr, n);
return __clear_user_memset(addr, n);
}
