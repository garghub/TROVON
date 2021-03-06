static int mcopy_atomic_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr,
unsigned long src_addr,
struct page **pagep)
{
struct mem_cgroup *memcg;
pte_t _dst_pte, *dst_pte;
spinlock_t *ptl;
void *page_kaddr;
int ret;
struct page *page;
if (!*pagep) {
ret = -ENOMEM;
page = alloc_page_vma(GFP_HIGHUSER_MOVABLE, dst_vma, dst_addr);
if (!page)
goto out;
page_kaddr = kmap_atomic(page);
ret = copy_from_user(page_kaddr,
(const void __user *) src_addr,
PAGE_SIZE);
kunmap_atomic(page_kaddr);
if (unlikely(ret)) {
ret = -EFAULT;
*pagep = page;
goto out;
}
} else {
page = *pagep;
*pagep = NULL;
}
__SetPageUptodate(page);
ret = -ENOMEM;
if (mem_cgroup_try_charge(page, dst_mm, GFP_KERNEL, &memcg, false))
goto out_release;
_dst_pte = mk_pte(page, dst_vma->vm_page_prot);
if (dst_vma->vm_flags & VM_WRITE)
_dst_pte = pte_mkwrite(pte_mkdirty(_dst_pte));
ret = -EEXIST;
dst_pte = pte_offset_map_lock(dst_mm, dst_pmd, dst_addr, &ptl);
if (!pte_none(*dst_pte))
goto out_release_uncharge_unlock;
inc_mm_counter(dst_mm, MM_ANONPAGES);
page_add_new_anon_rmap(page, dst_vma, dst_addr, false);
mem_cgroup_commit_charge(page, memcg, false, false);
lru_cache_add_active_or_unevictable(page, dst_vma);
set_pte_at(dst_mm, dst_addr, dst_pte, _dst_pte);
update_mmu_cache(dst_vma, dst_addr, dst_pte);
pte_unmap_unlock(dst_pte, ptl);
ret = 0;
out:
return ret;
out_release_uncharge_unlock:
pte_unmap_unlock(dst_pte, ptl);
mem_cgroup_cancel_charge(page, memcg, false);
out_release:
put_page(page);
goto out;
}
static int mfill_zeropage_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr)
{
pte_t _dst_pte, *dst_pte;
spinlock_t *ptl;
int ret;
_dst_pte = pte_mkspecial(pfn_pte(my_zero_pfn(dst_addr),
dst_vma->vm_page_prot));
ret = -EEXIST;
dst_pte = pte_offset_map_lock(dst_mm, dst_pmd, dst_addr, &ptl);
if (!pte_none(*dst_pte))
goto out_unlock;
set_pte_at(dst_mm, dst_addr, dst_pte, _dst_pte);
update_mmu_cache(dst_vma, dst_addr, dst_pte);
ret = 0;
out_unlock:
pte_unmap_unlock(dst_pte, ptl);
return ret;
}
static pmd_t *mm_alloc_pmd(struct mm_struct *mm, unsigned long address)
{
pgd_t *pgd;
p4d_t *p4d;
pud_t *pud;
pgd = pgd_offset(mm, address);
p4d = p4d_alloc(mm, pgd, address);
if (!p4d)
return NULL;
pud = pud_alloc(mm, p4d, address);
if (!pud)
return NULL;
return pmd_alloc(mm, pud, address);
}
static __always_inline ssize_t __mcopy_atomic_hugetlb(struct mm_struct *dst_mm,
struct vm_area_struct *dst_vma,
unsigned long dst_start,
unsigned long src_start,
unsigned long len,
bool zeropage)
{
int vm_alloc_shared = dst_vma->vm_flags & VM_SHARED;
int vm_shared = dst_vma->vm_flags & VM_SHARED;
ssize_t err;
pte_t *dst_pte;
unsigned long src_addr, dst_addr;
long copied;
struct page *page;
struct hstate *h;
unsigned long vma_hpagesize;
pgoff_t idx;
u32 hash;
struct address_space *mapping;
if (zeropage) {
up_read(&dst_mm->mmap_sem);
return -EINVAL;
}
src_addr = src_start;
dst_addr = dst_start;
copied = 0;
page = NULL;
vma_hpagesize = vma_kernel_pagesize(dst_vma);
err = -EINVAL;
if (dst_start & (vma_hpagesize - 1) || len & (vma_hpagesize - 1))
goto out_unlock;
retry:
if (!dst_vma) {
err = -ENOENT;
dst_vma = find_vma(dst_mm, dst_start);
if (!dst_vma || !is_vm_hugetlb_page(dst_vma))
goto out_unlock;
if (!dst_vma->vm_userfaultfd_ctx.ctx)
goto out_unlock;
if (dst_start < dst_vma->vm_start ||
dst_start + len > dst_vma->vm_end)
goto out_unlock;
err = -EINVAL;
if (vma_hpagesize != vma_kernel_pagesize(dst_vma))
goto out_unlock;
vm_shared = dst_vma->vm_flags & VM_SHARED;
}
if (WARN_ON(dst_addr & (vma_hpagesize - 1) ||
(len - copied) & (vma_hpagesize - 1)))
goto out_unlock;
err = -ENOMEM;
if (!vm_shared) {
if (unlikely(anon_vma_prepare(dst_vma)))
goto out_unlock;
}
h = hstate_vma(dst_vma);
while (src_addr < src_start + len) {
pte_t dst_pteval;
BUG_ON(dst_addr >= dst_start + len);
VM_BUG_ON(dst_addr & ~huge_page_mask(h));
idx = linear_page_index(dst_vma, dst_addr);
mapping = dst_vma->vm_file->f_mapping;
hash = hugetlb_fault_mutex_hash(h, dst_mm, dst_vma, mapping,
idx, dst_addr);
mutex_lock(&hugetlb_fault_mutex_table[hash]);
err = -ENOMEM;
dst_pte = huge_pte_alloc(dst_mm, dst_addr, huge_page_size(h));
if (!dst_pte) {
mutex_unlock(&hugetlb_fault_mutex_table[hash]);
goto out_unlock;
}
err = -EEXIST;
dst_pteval = huge_ptep_get(dst_pte);
if (!huge_pte_none(dst_pteval)) {
mutex_unlock(&hugetlb_fault_mutex_table[hash]);
goto out_unlock;
}
err = hugetlb_mcopy_atomic_pte(dst_mm, dst_pte, dst_vma,
dst_addr, src_addr, &page);
mutex_unlock(&hugetlb_fault_mutex_table[hash]);
vm_alloc_shared = vm_shared;
cond_resched();
if (unlikely(err == -EFAULT)) {
up_read(&dst_mm->mmap_sem);
BUG_ON(!page);
err = copy_huge_page_from_user(page,
(const void __user *)src_addr,
pages_per_huge_page(h), true);
if (unlikely(err)) {
err = -EFAULT;
goto out;
}
down_read(&dst_mm->mmap_sem);
dst_vma = NULL;
goto retry;
} else
BUG_ON(page);
if (!err) {
dst_addr += vma_hpagesize;
src_addr += vma_hpagesize;
copied += vma_hpagesize;
if (fatal_signal_pending(current))
err = -EINTR;
}
if (err)
break;
}
out_unlock:
up_read(&dst_mm->mmap_sem);
out:
if (page) {
if (vm_alloc_shared)
SetPagePrivate(page);
else
ClearPagePrivate(page);
put_page(page);
}
BUG_ON(copied < 0);
BUG_ON(err > 0);
BUG_ON(!copied && !err);
return copied ? copied : err;
}
static __always_inline ssize_t mfill_atomic_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr,
unsigned long src_addr,
struct page **page,
bool zeropage)
{
ssize_t err;
if (vma_is_anonymous(dst_vma)) {
if (!zeropage)
err = mcopy_atomic_pte(dst_mm, dst_pmd, dst_vma,
dst_addr, src_addr, page);
else
err = mfill_zeropage_pte(dst_mm, dst_pmd,
dst_vma, dst_addr);
} else {
if (!zeropage)
err = shmem_mcopy_atomic_pte(dst_mm, dst_pmd,
dst_vma, dst_addr,
src_addr, page);
else
err = shmem_mfill_zeropage_pte(dst_mm, dst_pmd,
dst_vma, dst_addr);
}
return err;
}
static __always_inline ssize_t __mcopy_atomic(struct mm_struct *dst_mm,
unsigned long dst_start,
unsigned long src_start,
unsigned long len,
bool zeropage)
{
struct vm_area_struct *dst_vma;
ssize_t err;
pmd_t *dst_pmd;
unsigned long src_addr, dst_addr;
long copied;
struct page *page;
BUG_ON(dst_start & ~PAGE_MASK);
BUG_ON(len & ~PAGE_MASK);
BUG_ON(src_start + len <= src_start);
BUG_ON(dst_start + len <= dst_start);
src_addr = src_start;
dst_addr = dst_start;
copied = 0;
page = NULL;
retry:
down_read(&dst_mm->mmap_sem);
err = -ENOENT;
dst_vma = find_vma(dst_mm, dst_start);
if (!dst_vma)
goto out_unlock;
if (!dst_vma->vm_userfaultfd_ctx.ctx)
goto out_unlock;
if (dst_start < dst_vma->vm_start ||
dst_start + len > dst_vma->vm_end)
goto out_unlock;
err = -EINVAL;
if (WARN_ON_ONCE(vma_is_anonymous(dst_vma) &&
dst_vma->vm_flags & VM_SHARED))
goto out_unlock;
if (is_vm_hugetlb_page(dst_vma))
return __mcopy_atomic_hugetlb(dst_mm, dst_vma, dst_start,
src_start, len, zeropage);
if (!vma_is_anonymous(dst_vma) && !vma_is_shmem(dst_vma))
goto out_unlock;
err = -ENOMEM;
if (vma_is_anonymous(dst_vma) && unlikely(anon_vma_prepare(dst_vma)))
goto out_unlock;
while (src_addr < src_start + len) {
pmd_t dst_pmdval;
BUG_ON(dst_addr >= dst_start + len);
dst_pmd = mm_alloc_pmd(dst_mm, dst_addr);
if (unlikely(!dst_pmd)) {
err = -ENOMEM;
break;
}
dst_pmdval = pmd_read_atomic(dst_pmd);
if (unlikely(pmd_trans_huge(dst_pmdval))) {
err = -EEXIST;
break;
}
if (unlikely(pmd_none(dst_pmdval)) &&
unlikely(__pte_alloc(dst_mm, dst_pmd, dst_addr))) {
err = -ENOMEM;
break;
}
if (unlikely(pmd_trans_huge(*dst_pmd))) {
err = -EFAULT;
break;
}
BUG_ON(pmd_none(*dst_pmd));
BUG_ON(pmd_trans_huge(*dst_pmd));
err = mfill_atomic_pte(dst_mm, dst_pmd, dst_vma, dst_addr,
src_addr, &page, zeropage);
cond_resched();
if (unlikely(err == -EFAULT)) {
void *page_kaddr;
up_read(&dst_mm->mmap_sem);
BUG_ON(!page);
page_kaddr = kmap(page);
err = copy_from_user(page_kaddr,
(const void __user *) src_addr,
PAGE_SIZE);
kunmap(page);
if (unlikely(err)) {
err = -EFAULT;
goto out;
}
goto retry;
} else
BUG_ON(page);
if (!err) {
dst_addr += PAGE_SIZE;
src_addr += PAGE_SIZE;
copied += PAGE_SIZE;
if (fatal_signal_pending(current))
err = -EINTR;
}
if (err)
break;
}
out_unlock:
up_read(&dst_mm->mmap_sem);
out:
if (page)
put_page(page);
BUG_ON(copied < 0);
BUG_ON(err > 0);
BUG_ON(!copied && !err);
return copied ? copied : err;
}
ssize_t mcopy_atomic(struct mm_struct *dst_mm, unsigned long dst_start,
unsigned long src_start, unsigned long len)
{
return __mcopy_atomic(dst_mm, dst_start, src_start, len, false);
}
ssize_t mfill_zeropage(struct mm_struct *dst_mm, unsigned long start,
unsigned long len)
{
return __mcopy_atomic(dst_mm, start, 0, len, true);
}
