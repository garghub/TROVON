int can_do_mlock(void)
{
if (capable(CAP_IPC_LOCK))
return 1;
if (rlimit(RLIMIT_MEMLOCK) != 0)
return 1;
return 0;
}
void clear_page_mlock(struct page *page)
{
if (!TestClearPageMlocked(page))
return;
mod_zone_page_state(page_zone(page), NR_MLOCK,
-hpage_nr_pages(page));
count_vm_event(UNEVICTABLE_PGCLEARED);
if (!isolate_lru_page(page)) {
putback_lru_page(page);
} else {
if (PageUnevictable(page))
count_vm_event(UNEVICTABLE_PGSTRANDED);
}
}
void mlock_vma_page(struct page *page)
{
BUG_ON(!PageLocked(page));
if (!TestSetPageMlocked(page)) {
mod_zone_page_state(page_zone(page), NR_MLOCK,
hpage_nr_pages(page));
count_vm_event(UNEVICTABLE_PGMLOCKED);
if (!isolate_lru_page(page))
putback_lru_page(page);
}
}
static void __munlock_isolated_page(struct page *page)
{
int ret = SWAP_AGAIN;
if (page_mapcount(page) > 1)
ret = try_to_munlock(page);
if (ret != SWAP_MLOCK)
count_vm_event(UNEVICTABLE_PGMUNLOCKED);
putback_lru_page(page);
}
static void __munlock_isolation_failed(struct page *page)
{
if (PageUnevictable(page))
count_vm_event(UNEVICTABLE_PGSTRANDED);
else
count_vm_event(UNEVICTABLE_PGMUNLOCKED);
}
unsigned int munlock_vma_page(struct page *page)
{
unsigned int page_mask = 0;
BUG_ON(!PageLocked(page));
if (TestClearPageMlocked(page)) {
unsigned int nr_pages = hpage_nr_pages(page);
mod_zone_page_state(page_zone(page), NR_MLOCK, -nr_pages);
page_mask = nr_pages - 1;
if (!isolate_lru_page(page))
__munlock_isolated_page(page);
else
__munlock_isolation_failed(page);
}
return page_mask;
}
long __mlock_vma_pages_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end, int *nonblocking)
{
struct mm_struct *mm = vma->vm_mm;
unsigned long nr_pages = (end - start) / PAGE_SIZE;
int gup_flags;
VM_BUG_ON(start & ~PAGE_MASK);
VM_BUG_ON(end & ~PAGE_MASK);
VM_BUG_ON(start < vma->vm_start);
VM_BUG_ON(end > vma->vm_end);
VM_BUG_ON(!rwsem_is_locked(&mm->mmap_sem));
gup_flags = FOLL_TOUCH | FOLL_MLOCK;
if ((vma->vm_flags & (VM_WRITE | VM_SHARED)) == VM_WRITE)
gup_flags |= FOLL_WRITE;
if (vma->vm_flags & (VM_READ | VM_WRITE | VM_EXEC))
gup_flags |= FOLL_FORCE;
return __get_user_pages(current, mm, start, nr_pages, gup_flags,
NULL, NULL, nonblocking);
}
static int __mlock_posix_error_return(long retval)
{
if (retval == -EFAULT)
retval = -ENOMEM;
else if (retval == -ENOMEM)
retval = -EAGAIN;
return retval;
}
static bool __putback_lru_fast_prepare(struct page *page, struct pagevec *pvec,
int *pgrescued)
{
VM_BUG_ON(PageLRU(page));
VM_BUG_ON(!PageLocked(page));
if (page_mapcount(page) <= 1 && page_evictable(page)) {
pagevec_add(pvec, page);
if (TestClearPageUnevictable(page))
(*pgrescued)++;
unlock_page(page);
return true;
}
return false;
}
static void __putback_lru_fast(struct pagevec *pvec, int pgrescued)
{
count_vm_events(UNEVICTABLE_PGMUNLOCKED, pagevec_count(pvec));
__pagevec_lru_add(pvec);
count_vm_events(UNEVICTABLE_PGRESCUED, pgrescued);
}
static void __munlock_pagevec(struct pagevec *pvec, struct zone *zone)
{
int i;
int nr = pagevec_count(pvec);
int delta_munlocked = -nr;
struct pagevec pvec_putback;
int pgrescued = 0;
spin_lock_irq(&zone->lru_lock);
for (i = 0; i < nr; i++) {
struct page *page = pvec->pages[i];
if (TestClearPageMlocked(page)) {
struct lruvec *lruvec;
int lru;
if (PageLRU(page)) {
lruvec = mem_cgroup_page_lruvec(page, zone);
lru = page_lru(page);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, lru);
} else {
__munlock_isolation_failed(page);
goto skip_munlock;
}
} else {
skip_munlock:
pvec->pages[i] = NULL;
put_page(page);
delta_munlocked++;
}
}
__mod_zone_page_state(zone, NR_MLOCK, delta_munlocked);
spin_unlock_irq(&zone->lru_lock);
pagevec_init(&pvec_putback, 0);
for (i = 0; i < nr; i++) {
struct page *page = pvec->pages[i];
if (page) {
lock_page(page);
if (!__putback_lru_fast_prepare(page, &pvec_putback,
&pgrescued)) {
get_page(page);
__munlock_isolated_page(page);
unlock_page(page);
put_page(page);
}
}
}
if (pagevec_count(&pvec_putback))
__putback_lru_fast(&pvec_putback, pgrescued);
}
static unsigned long __munlock_pagevec_fill(struct pagevec *pvec,
struct vm_area_struct *vma, int zoneid, unsigned long start,
unsigned long end)
{
pte_t *pte;
spinlock_t *ptl;
pte = get_locked_pte(vma->vm_mm, start, &ptl);
end = pgd_addr_end(start, end);
end = pud_addr_end(start, end);
end = pmd_addr_end(start, end);
start += PAGE_SIZE;
while (start < end) {
struct page *page = NULL;
pte++;
if (pte_present(*pte))
page = vm_normal_page(vma, start, *pte);
if (!page || page_zone_id(page) != zoneid)
break;
get_page(page);
start += PAGE_SIZE;
if (pagevec_add(pvec, page) == 0)
break;
}
pte_unmap_unlock(pte, ptl);
return start;
}
void munlock_vma_pages_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
vma->vm_flags &= ~VM_LOCKED;
while (start < end) {
struct page *page = NULL;
unsigned int page_mask, page_increm;
struct pagevec pvec;
struct zone *zone;
int zoneid;
pagevec_init(&pvec, 0);
page = follow_page_mask(vma, start, FOLL_GET | FOLL_DUMP,
&page_mask);
if (page && !IS_ERR(page)) {
if (PageTransHuge(page)) {
lock_page(page);
page_mask = munlock_vma_page(page);
unlock_page(page);
put_page(page);
} else {
pagevec_add(&pvec, page);
zone = page_zone(page);
zoneid = page_zone_id(page);
start = __munlock_pagevec_fill(&pvec, vma,
zoneid, start, end);
__munlock_pagevec(&pvec, zone);
goto next;
}
}
page_increm = 1 + (~(start >> PAGE_SHIFT) & page_mask);
start += page_increm * PAGE_SIZE;
next:
cond_resched();
}
}
static int mlock_fixup(struct vm_area_struct *vma, struct vm_area_struct **prev,
unsigned long start, unsigned long end, vm_flags_t newflags)
{
struct mm_struct *mm = vma->vm_mm;
pgoff_t pgoff;
int nr_pages;
int ret = 0;
int lock = !!(newflags & VM_LOCKED);
if (newflags == vma->vm_flags || (vma->vm_flags & VM_SPECIAL) ||
is_vm_hugetlb_page(vma) || vma == get_gate_vma(current->mm))
goto out;
pgoff = vma->vm_pgoff + ((start - vma->vm_start) >> PAGE_SHIFT);
*prev = vma_merge(mm, *prev, start, end, newflags, vma->anon_vma,
vma->vm_file, pgoff, vma_policy(vma));
if (*prev) {
vma = *prev;
goto success;
}
if (start != vma->vm_start) {
ret = split_vma(mm, vma, start, 1);
if (ret)
goto out;
}
if (end != vma->vm_end) {
ret = split_vma(mm, vma, end, 0);
if (ret)
goto out;
}
success:
nr_pages = (end - start) >> PAGE_SHIFT;
if (!lock)
nr_pages = -nr_pages;
mm->locked_vm += nr_pages;
if (lock)
vma->vm_flags = newflags;
else
munlock_vma_pages_range(vma, start, end);
out:
*prev = vma;
return ret;
}
static int do_mlock(unsigned long start, size_t len, int on)
{
unsigned long nstart, end, tmp;
struct vm_area_struct * vma, * prev;
int error;
VM_BUG_ON(start & ~PAGE_MASK);
VM_BUG_ON(len != PAGE_ALIGN(len));
end = start + len;
if (end < start)
return -EINVAL;
if (end == start)
return 0;
vma = find_vma(current->mm, start);
if (!vma || vma->vm_start > start)
return -ENOMEM;
prev = vma->vm_prev;
if (start > vma->vm_start)
prev = vma;
for (nstart = start ; ; ) {
vm_flags_t newflags;
newflags = vma->vm_flags & ~VM_LOCKED;
if (on)
newflags |= VM_LOCKED;
tmp = vma->vm_end;
if (tmp > end)
tmp = end;
error = mlock_fixup(vma, &prev, nstart, tmp, newflags);
if (error)
break;
nstart = tmp;
if (nstart < prev->vm_end)
nstart = prev->vm_end;
if (nstart >= end)
break;
vma = prev->vm_next;
if (!vma || vma->vm_start != nstart) {
error = -ENOMEM;
break;
}
}
return error;
}
int __mm_populate(unsigned long start, unsigned long len, int ignore_errors)
{
struct mm_struct *mm = current->mm;
unsigned long end, nstart, nend;
struct vm_area_struct *vma = NULL;
int locked = 0;
long ret = 0;
VM_BUG_ON(start & ~PAGE_MASK);
VM_BUG_ON(len != PAGE_ALIGN(len));
end = start + len;
for (nstart = start; nstart < end; nstart = nend) {
if (!locked) {
locked = 1;
down_read(&mm->mmap_sem);
vma = find_vma(mm, nstart);
} else if (nstart >= vma->vm_end)
vma = vma->vm_next;
if (!vma || vma->vm_start >= end)
break;
nend = min(end, vma->vm_end);
if (vma->vm_flags & (VM_IO | VM_PFNMAP))
continue;
if (nstart < vma->vm_start)
nstart = vma->vm_start;
ret = __mlock_vma_pages_range(vma, nstart, nend, &locked);
if (ret < 0) {
if (ignore_errors) {
ret = 0;
continue;
}
ret = __mlock_posix_error_return(ret);
break;
}
nend = nstart + ret * PAGE_SIZE;
ret = 0;
}
if (locked)
up_read(&mm->mmap_sem);
return ret;
}
static int do_mlockall(int flags)
{
struct vm_area_struct * vma, * prev = NULL;
if (flags & MCL_FUTURE)
current->mm->def_flags |= VM_LOCKED;
else
current->mm->def_flags &= ~VM_LOCKED;
if (flags == MCL_FUTURE)
goto out;
for (vma = current->mm->mmap; vma ; vma = prev->vm_next) {
vm_flags_t newflags;
newflags = vma->vm_flags & ~VM_LOCKED;
if (flags & MCL_CURRENT)
newflags |= VM_LOCKED;
mlock_fixup(vma, &prev, vma->vm_start, vma->vm_end, newflags);
cond_resched();
}
out:
return 0;
}
int user_shm_lock(size_t size, struct user_struct *user)
{
unsigned long lock_limit, locked;
int allowed = 0;
locked = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
lock_limit = rlimit(RLIMIT_MEMLOCK);
if (lock_limit == RLIM_INFINITY)
allowed = 1;
lock_limit >>= PAGE_SHIFT;
spin_lock(&shmlock_user_lock);
if (!allowed &&
locked + user->locked_shm > lock_limit && !capable(CAP_IPC_LOCK))
goto out;
get_uid(user);
user->locked_shm += locked;
allowed = 1;
out:
spin_unlock(&shmlock_user_lock);
return allowed;
}
void user_shm_unlock(size_t size, struct user_struct *user)
{
spin_lock(&shmlock_user_lock);
user->locked_shm -= (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
spin_unlock(&shmlock_user_lock);
free_uid(user);
}
