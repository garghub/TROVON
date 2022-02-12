bool can_do_mlock(void)
{
if (rlimit(RLIMIT_MEMLOCK) != 0)
return true;
if (capable(CAP_IPC_LOCK))
return true;
return false;
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
VM_BUG_ON_PAGE(PageTail(page), page);
VM_BUG_ON_PAGE(PageCompound(page) && PageDoubleMap(page), page);
if (!TestSetPageMlocked(page)) {
mod_zone_page_state(page_zone(page), NR_MLOCK,
hpage_nr_pages(page));
count_vm_event(UNEVICTABLE_PGMLOCKED);
if (!isolate_lru_page(page))
putback_lru_page(page);
}
}
static bool __munlock_isolate_lru_page(struct page *page, bool getpage)
{
if (PageLRU(page)) {
struct lruvec *lruvec;
lruvec = mem_cgroup_page_lruvec(page, page_pgdat(page));
if (getpage)
get_page(page);
ClearPageLRU(page);
del_page_from_lru_list(page, lruvec, page_lru(page));
return true;
}
return false;
}
static void __munlock_isolated_page(struct page *page)
{
if (page_mapcount(page) > 1)
try_to_munlock(page);
if (!PageMlocked(page))
count_vm_event(UNEVICTABLE_PGMUNLOCKED);
putback_lru_page(page);
}
static void __munlock_isolation_failed(struct page *page)
{
if (PageUnevictable(page))
__count_vm_event(UNEVICTABLE_PGSTRANDED);
else
__count_vm_event(UNEVICTABLE_PGMUNLOCKED);
}
unsigned int munlock_vma_page(struct page *page)
{
int nr_pages;
struct zone *zone = page_zone(page);
BUG_ON(!PageLocked(page));
VM_BUG_ON_PAGE(PageTail(page), page);
spin_lock_irq(zone_lru_lock(zone));
if (!TestClearPageMlocked(page)) {
nr_pages = 1;
goto unlock_out;
}
nr_pages = hpage_nr_pages(page);
__mod_zone_page_state(zone, NR_MLOCK, -nr_pages);
if (__munlock_isolate_lru_page(page, true)) {
spin_unlock_irq(zone_lru_lock(zone));
__munlock_isolated_page(page);
goto out;
}
__munlock_isolation_failed(page);
unlock_out:
spin_unlock_irq(zone_lru_lock(zone));
out:
return nr_pages - 1;
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
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
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
pagevec_init(&pvec_putback, 0);
spin_lock_irq(zone_lru_lock(zone));
for (i = 0; i < nr; i++) {
struct page *page = pvec->pages[i];
if (TestClearPageMlocked(page)) {
if (__munlock_isolate_lru_page(page, false))
continue;
else
__munlock_isolation_failed(page);
} else {
delta_munlocked++;
}
pagevec_add(&pvec_putback, pvec->pages[i]);
pvec->pages[i] = NULL;
}
__mod_zone_page_state(zone, NR_MLOCK, delta_munlocked);
spin_unlock_irq(zone_lru_lock(zone));
pagevec_release(&pvec_putback);
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
end = p4d_addr_end(start, end);
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
if (PageTransCompound(page))
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
vma->vm_flags &= VM_LOCKED_CLEAR_MASK;
while (start < end) {
struct page *page;
unsigned int page_mask = 0;
unsigned long page_increm;
struct pagevec pvec;
struct zone *zone;
int zoneid;
pagevec_init(&pvec, 0);
page = follow_page(vma, start, FOLL_GET | FOLL_DUMP);
if (page && !IS_ERR(page)) {
if (PageTransTail(page)) {
VM_BUG_ON_PAGE(PageMlocked(page), page);
put_page(page);
} else if (PageTransHuge(page)) {
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
page_increm = 1 + page_mask;
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
vm_flags_t old_flags = vma->vm_flags;
if (newflags == vma->vm_flags || (vma->vm_flags & VM_SPECIAL) ||
is_vm_hugetlb_page(vma) || vma == get_gate_vma(current->mm))
goto out;
pgoff = vma->vm_pgoff + ((start - vma->vm_start) >> PAGE_SHIFT);
*prev = vma_merge(mm, *prev, start, end, newflags, vma->anon_vma,
vma->vm_file, pgoff, vma_policy(vma),
vma->vm_userfaultfd_ctx);
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
else if (old_flags & VM_LOCKED)
nr_pages = 0;
mm->locked_vm += nr_pages;
if (lock)
vma->vm_flags = newflags;
else
munlock_vma_pages_range(vma, start, end);
out:
*prev = vma;
return ret;
}
static int apply_vma_lock_flags(unsigned long start, size_t len,
vm_flags_t flags)
{
unsigned long nstart, end, tmp;
struct vm_area_struct * vma, * prev;
int error;
VM_BUG_ON(offset_in_page(start));
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
vm_flags_t newflags = vma->vm_flags & VM_LOCKED_CLEAR_MASK;
newflags |= flags;
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
static int count_mm_mlocked_page_nr(struct mm_struct *mm,
unsigned long start, size_t len)
{
struct vm_area_struct *vma;
int count = 0;
if (mm == NULL)
mm = current->mm;
vma = find_vma(mm, start);
if (vma == NULL)
vma = mm->mmap;
for (; vma ; vma = vma->vm_next) {
if (start >= vma->vm_end)
continue;
if (start + len <= vma->vm_start)
break;
if (vma->vm_flags & VM_LOCKED) {
if (start > vma->vm_start)
count -= (start - vma->vm_start);
if (start + len < vma->vm_end) {
count += start + len - vma->vm_start;
break;
}
count += vma->vm_end - vma->vm_start;
}
}
return count >> PAGE_SHIFT;
}
static __must_check int do_mlock(unsigned long start, size_t len, vm_flags_t flags)
{
unsigned long locked;
unsigned long lock_limit;
int error = -ENOMEM;
if (!can_do_mlock())
return -EPERM;
lru_add_drain_all();
len = PAGE_ALIGN(len + (offset_in_page(start)));
start &= PAGE_MASK;
lock_limit = rlimit(RLIMIT_MEMLOCK);
lock_limit >>= PAGE_SHIFT;
locked = len >> PAGE_SHIFT;
if (down_write_killable(&current->mm->mmap_sem))
return -EINTR;
locked += current->mm->locked_vm;
if ((locked > lock_limit) && (!capable(CAP_IPC_LOCK))) {
locked -= count_mm_mlocked_page_nr(current->mm,
start, len);
}
if ((locked <= lock_limit) || capable(CAP_IPC_LOCK))
error = apply_vma_lock_flags(start, len, flags);
up_write(&current->mm->mmap_sem);
if (error)
return error;
error = __mm_populate(start, len, 0);
if (error)
return __mlock_posix_error_return(error);
return 0;
}
static int apply_mlockall_flags(int flags)
{
struct vm_area_struct * vma, * prev = NULL;
vm_flags_t to_add = 0;
current->mm->def_flags &= VM_LOCKED_CLEAR_MASK;
if (flags & MCL_FUTURE) {
current->mm->def_flags |= VM_LOCKED;
if (flags & MCL_ONFAULT)
current->mm->def_flags |= VM_LOCKONFAULT;
if (!(flags & MCL_CURRENT))
goto out;
}
if (flags & MCL_CURRENT) {
to_add |= VM_LOCKED;
if (flags & MCL_ONFAULT)
to_add |= VM_LOCKONFAULT;
}
for (vma = current->mm->mmap; vma ; vma = prev->vm_next) {
vm_flags_t newflags;
newflags = vma->vm_flags & VM_LOCKED_CLEAR_MASK;
newflags |= to_add;
mlock_fixup(vma, &prev, vma->vm_start, vma->vm_end, newflags);
cond_resched_rcu_qs();
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
