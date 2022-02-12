static inline unsigned char swap_count(unsigned char ent)
{
return ent & ~SWAP_HAS_CACHE;
}
static int
__try_to_reclaim_swap(struct swap_info_struct *si, unsigned long offset)
{
swp_entry_t entry = swp_entry(si->type, offset);
struct page *page;
int ret = 0;
page = find_get_page(swap_address_space(entry), entry.val);
if (!page)
return 0;
if (trylock_page(page)) {
ret = try_to_free_swap(page);
unlock_page(page);
}
page_cache_release(page);
return ret;
}
static int discard_swap(struct swap_info_struct *si)
{
struct swap_extent *se;
sector_t start_block;
sector_t nr_blocks;
int err = 0;
se = &si->first_swap_extent;
start_block = (se->start_block + 1) << (PAGE_SHIFT - 9);
nr_blocks = ((sector_t)se->nr_pages - 1) << (PAGE_SHIFT - 9);
if (nr_blocks) {
err = blkdev_issue_discard(si->bdev, start_block,
nr_blocks, GFP_KERNEL, 0);
if (err)
return err;
cond_resched();
}
list_for_each_entry(se, &si->first_swap_extent.list, list) {
start_block = se->start_block << (PAGE_SHIFT - 9);
nr_blocks = (sector_t)se->nr_pages << (PAGE_SHIFT - 9);
err = blkdev_issue_discard(si->bdev, start_block,
nr_blocks, GFP_KERNEL, 0);
if (err)
break;
cond_resched();
}
return err;
}
static void discard_swap_cluster(struct swap_info_struct *si,
pgoff_t start_page, pgoff_t nr_pages)
{
struct swap_extent *se = si->curr_swap_extent;
int found_extent = 0;
while (nr_pages) {
struct list_head *lh;
if (se->start_page <= start_page &&
start_page < se->start_page + se->nr_pages) {
pgoff_t offset = start_page - se->start_page;
sector_t start_block = se->start_block + offset;
sector_t nr_blocks = se->nr_pages - offset;
if (nr_blocks > nr_pages)
nr_blocks = nr_pages;
start_page += nr_blocks;
nr_pages -= nr_blocks;
if (!found_extent++)
si->curr_swap_extent = se;
start_block <<= PAGE_SHIFT - 9;
nr_blocks <<= PAGE_SHIFT - 9;
if (blkdev_issue_discard(si->bdev, start_block,
nr_blocks, GFP_NOIO, 0))
break;
}
lh = se->list.next;
se = list_entry(lh, struct swap_extent, list);
}
}
static inline void cluster_set_flag(struct swap_cluster_info *info,
unsigned int flag)
{
info->flags = flag;
}
static inline unsigned int cluster_count(struct swap_cluster_info *info)
{
return info->data;
}
static inline void cluster_set_count(struct swap_cluster_info *info,
unsigned int c)
{
info->data = c;
}
static inline void cluster_set_count_flag(struct swap_cluster_info *info,
unsigned int c, unsigned int f)
{
info->flags = f;
info->data = c;
}
static inline unsigned int cluster_next(struct swap_cluster_info *info)
{
return info->data;
}
static inline void cluster_set_next(struct swap_cluster_info *info,
unsigned int n)
{
info->data = n;
}
static inline void cluster_set_next_flag(struct swap_cluster_info *info,
unsigned int n, unsigned int f)
{
info->flags = f;
info->data = n;
}
static inline bool cluster_is_free(struct swap_cluster_info *info)
{
return info->flags & CLUSTER_FLAG_FREE;
}
static inline bool cluster_is_null(struct swap_cluster_info *info)
{
return info->flags & CLUSTER_FLAG_NEXT_NULL;
}
static inline void cluster_set_null(struct swap_cluster_info *info)
{
info->flags = CLUSTER_FLAG_NEXT_NULL;
info->data = 0;
}
static void swap_cluster_schedule_discard(struct swap_info_struct *si,
unsigned int idx)
{
memset(si->swap_map + idx * SWAPFILE_CLUSTER,
SWAP_MAP_BAD, SWAPFILE_CLUSTER);
if (cluster_is_null(&si->discard_cluster_head)) {
cluster_set_next_flag(&si->discard_cluster_head,
idx, 0);
cluster_set_next_flag(&si->discard_cluster_tail,
idx, 0);
} else {
unsigned int tail = cluster_next(&si->discard_cluster_tail);
cluster_set_next(&si->cluster_info[tail], idx);
cluster_set_next_flag(&si->discard_cluster_tail,
idx, 0);
}
schedule_work(&si->discard_work);
}
static void swap_do_scheduled_discard(struct swap_info_struct *si)
{
struct swap_cluster_info *info;
unsigned int idx;
info = si->cluster_info;
while (!cluster_is_null(&si->discard_cluster_head)) {
idx = cluster_next(&si->discard_cluster_head);
cluster_set_next_flag(&si->discard_cluster_head,
cluster_next(&info[idx]), 0);
if (cluster_next(&si->discard_cluster_tail) == idx) {
cluster_set_null(&si->discard_cluster_head);
cluster_set_null(&si->discard_cluster_tail);
}
spin_unlock(&si->lock);
discard_swap_cluster(si, idx * SWAPFILE_CLUSTER,
SWAPFILE_CLUSTER);
spin_lock(&si->lock);
cluster_set_flag(&info[idx], CLUSTER_FLAG_FREE);
if (cluster_is_null(&si->free_cluster_head)) {
cluster_set_next_flag(&si->free_cluster_head,
idx, 0);
cluster_set_next_flag(&si->free_cluster_tail,
idx, 0);
} else {
unsigned int tail;
tail = cluster_next(&si->free_cluster_tail);
cluster_set_next(&info[tail], idx);
cluster_set_next_flag(&si->free_cluster_tail,
idx, 0);
}
memset(si->swap_map + idx * SWAPFILE_CLUSTER,
0, SWAPFILE_CLUSTER);
}
}
static void swap_discard_work(struct work_struct *work)
{
struct swap_info_struct *si;
si = container_of(work, struct swap_info_struct, discard_work);
spin_lock(&si->lock);
swap_do_scheduled_discard(si);
spin_unlock(&si->lock);
}
static void inc_cluster_info_page(struct swap_info_struct *p,
struct swap_cluster_info *cluster_info, unsigned long page_nr)
{
unsigned long idx = page_nr / SWAPFILE_CLUSTER;
if (!cluster_info)
return;
if (cluster_is_free(&cluster_info[idx])) {
VM_BUG_ON(cluster_next(&p->free_cluster_head) != idx);
cluster_set_next_flag(&p->free_cluster_head,
cluster_next(&cluster_info[idx]), 0);
if (cluster_next(&p->free_cluster_tail) == idx) {
cluster_set_null(&p->free_cluster_tail);
cluster_set_null(&p->free_cluster_head);
}
cluster_set_count_flag(&cluster_info[idx], 0, 0);
}
VM_BUG_ON(cluster_count(&cluster_info[idx]) >= SWAPFILE_CLUSTER);
cluster_set_count(&cluster_info[idx],
cluster_count(&cluster_info[idx]) + 1);
}
static void dec_cluster_info_page(struct swap_info_struct *p,
struct swap_cluster_info *cluster_info, unsigned long page_nr)
{
unsigned long idx = page_nr / SWAPFILE_CLUSTER;
if (!cluster_info)
return;
VM_BUG_ON(cluster_count(&cluster_info[idx]) == 0);
cluster_set_count(&cluster_info[idx],
cluster_count(&cluster_info[idx]) - 1);
if (cluster_count(&cluster_info[idx]) == 0) {
if ((p->flags & (SWP_WRITEOK | SWP_PAGE_DISCARD)) ==
(SWP_WRITEOK | SWP_PAGE_DISCARD)) {
swap_cluster_schedule_discard(p, idx);
return;
}
cluster_set_flag(&cluster_info[idx], CLUSTER_FLAG_FREE);
if (cluster_is_null(&p->free_cluster_head)) {
cluster_set_next_flag(&p->free_cluster_head, idx, 0);
cluster_set_next_flag(&p->free_cluster_tail, idx, 0);
} else {
unsigned int tail = cluster_next(&p->free_cluster_tail);
cluster_set_next(&cluster_info[tail], idx);
cluster_set_next_flag(&p->free_cluster_tail, idx, 0);
}
}
}
static bool
scan_swap_map_ssd_cluster_conflict(struct swap_info_struct *si,
unsigned long offset)
{
struct percpu_cluster *percpu_cluster;
bool conflict;
offset /= SWAPFILE_CLUSTER;
conflict = !cluster_is_null(&si->free_cluster_head) &&
offset != cluster_next(&si->free_cluster_head) &&
cluster_is_free(&si->cluster_info[offset]);
if (!conflict)
return false;
percpu_cluster = this_cpu_ptr(si->percpu_cluster);
cluster_set_null(&percpu_cluster->index);
return true;
}
static void scan_swap_map_try_ssd_cluster(struct swap_info_struct *si,
unsigned long *offset, unsigned long *scan_base)
{
struct percpu_cluster *cluster;
bool found_free;
unsigned long tmp;
new_cluster:
cluster = this_cpu_ptr(si->percpu_cluster);
if (cluster_is_null(&cluster->index)) {
if (!cluster_is_null(&si->free_cluster_head)) {
cluster->index = si->free_cluster_head;
cluster->next = cluster_next(&cluster->index) *
SWAPFILE_CLUSTER;
} else if (!cluster_is_null(&si->discard_cluster_head)) {
swap_do_scheduled_discard(si);
*scan_base = *offset = si->cluster_next;
goto new_cluster;
} else
return;
}
found_free = false;
tmp = cluster->next;
while (tmp < si->max && tmp < (cluster_next(&cluster->index) + 1) *
SWAPFILE_CLUSTER) {
if (!si->swap_map[tmp]) {
found_free = true;
break;
}
tmp++;
}
if (!found_free) {
cluster_set_null(&cluster->index);
goto new_cluster;
}
cluster->next = tmp + 1;
*offset = tmp;
*scan_base = tmp;
}
static unsigned long scan_swap_map(struct swap_info_struct *si,
unsigned char usage)
{
unsigned long offset;
unsigned long scan_base;
unsigned long last_in_cluster = 0;
int latency_ration = LATENCY_LIMIT;
si->flags += SWP_SCANNING;
scan_base = offset = si->cluster_next;
if (si->cluster_info) {
scan_swap_map_try_ssd_cluster(si, &offset, &scan_base);
goto checks;
}
if (unlikely(!si->cluster_nr--)) {
if (si->pages - si->inuse_pages < SWAPFILE_CLUSTER) {
si->cluster_nr = SWAPFILE_CLUSTER - 1;
goto checks;
}
spin_unlock(&si->lock);
if (!(si->flags & SWP_SOLIDSTATE))
scan_base = offset = si->lowest_bit;
last_in_cluster = offset + SWAPFILE_CLUSTER - 1;
for (; last_in_cluster <= si->highest_bit; offset++) {
if (si->swap_map[offset])
last_in_cluster = offset + SWAPFILE_CLUSTER;
else if (offset == last_in_cluster) {
spin_lock(&si->lock);
offset -= SWAPFILE_CLUSTER - 1;
si->cluster_next = offset;
si->cluster_nr = SWAPFILE_CLUSTER - 1;
goto checks;
}
if (unlikely(--latency_ration < 0)) {
cond_resched();
latency_ration = LATENCY_LIMIT;
}
}
offset = si->lowest_bit;
last_in_cluster = offset + SWAPFILE_CLUSTER - 1;
for (; last_in_cluster < scan_base; offset++) {
if (si->swap_map[offset])
last_in_cluster = offset + SWAPFILE_CLUSTER;
else if (offset == last_in_cluster) {
spin_lock(&si->lock);
offset -= SWAPFILE_CLUSTER - 1;
si->cluster_next = offset;
si->cluster_nr = SWAPFILE_CLUSTER - 1;
goto checks;
}
if (unlikely(--latency_ration < 0)) {
cond_resched();
latency_ration = LATENCY_LIMIT;
}
}
offset = scan_base;
spin_lock(&si->lock);
si->cluster_nr = SWAPFILE_CLUSTER - 1;
}
checks:
if (si->cluster_info) {
while (scan_swap_map_ssd_cluster_conflict(si, offset))
scan_swap_map_try_ssd_cluster(si, &offset, &scan_base);
}
if (!(si->flags & SWP_WRITEOK))
goto no_page;
if (!si->highest_bit)
goto no_page;
if (offset > si->highest_bit)
scan_base = offset = si->lowest_bit;
if (vm_swap_full() && si->swap_map[offset] == SWAP_HAS_CACHE) {
int swap_was_freed;
spin_unlock(&si->lock);
swap_was_freed = __try_to_reclaim_swap(si, offset);
spin_lock(&si->lock);
if (swap_was_freed)
goto checks;
goto scan;
}
if (si->swap_map[offset])
goto scan;
if (offset == si->lowest_bit)
si->lowest_bit++;
if (offset == si->highest_bit)
si->highest_bit--;
si->inuse_pages++;
if (si->inuse_pages == si->pages) {
si->lowest_bit = si->max;
si->highest_bit = 0;
}
si->swap_map[offset] = usage;
inc_cluster_info_page(si, si->cluster_info, offset);
si->cluster_next = offset + 1;
si->flags -= SWP_SCANNING;
return offset;
scan:
spin_unlock(&si->lock);
while (++offset <= si->highest_bit) {
if (!si->swap_map[offset]) {
spin_lock(&si->lock);
goto checks;
}
if (vm_swap_full() && si->swap_map[offset] == SWAP_HAS_CACHE) {
spin_lock(&si->lock);
goto checks;
}
if (unlikely(--latency_ration < 0)) {
cond_resched();
latency_ration = LATENCY_LIMIT;
}
}
offset = si->lowest_bit;
while (offset < scan_base) {
if (!si->swap_map[offset]) {
spin_lock(&si->lock);
goto checks;
}
if (vm_swap_full() && si->swap_map[offset] == SWAP_HAS_CACHE) {
spin_lock(&si->lock);
goto checks;
}
if (unlikely(--latency_ration < 0)) {
cond_resched();
latency_ration = LATENCY_LIMIT;
}
offset++;
}
spin_lock(&si->lock);
no_page:
si->flags -= SWP_SCANNING;
return 0;
}
swp_entry_t get_swap_page(void)
{
struct swap_info_struct *si;
pgoff_t offset;
int type, next;
int wrapped = 0;
int hp_index;
spin_lock(&swap_lock);
if (atomic_long_read(&nr_swap_pages) <= 0)
goto noswap;
atomic_long_dec(&nr_swap_pages);
for (type = swap_list.next; type >= 0 && wrapped < 2; type = next) {
hp_index = atomic_xchg(&highest_priority_index, -1);
if (hp_index != -1 && hp_index != type &&
swap_info[type]->prio < swap_info[hp_index]->prio &&
(swap_info[hp_index]->flags & SWP_WRITEOK)) {
type = hp_index;
swap_list.next = type;
}
si = swap_info[type];
next = si->next;
if (next < 0 ||
(!wrapped && si->prio != swap_info[next]->prio)) {
next = swap_list.head;
wrapped++;
}
spin_lock(&si->lock);
if (!si->highest_bit) {
spin_unlock(&si->lock);
continue;
}
if (!(si->flags & SWP_WRITEOK)) {
spin_unlock(&si->lock);
continue;
}
swap_list.next = next;
spin_unlock(&swap_lock);
offset = scan_swap_map(si, SWAP_HAS_CACHE);
spin_unlock(&si->lock);
if (offset)
return swp_entry(type, offset);
spin_lock(&swap_lock);
next = swap_list.next;
}
atomic_long_inc(&nr_swap_pages);
noswap:
spin_unlock(&swap_lock);
return (swp_entry_t) {0};
}
swp_entry_t get_swap_page_of_type(int type)
{
struct swap_info_struct *si;
pgoff_t offset;
si = swap_info[type];
spin_lock(&si->lock);
if (si && (si->flags & SWP_WRITEOK)) {
atomic_long_dec(&nr_swap_pages);
offset = scan_swap_map(si, 1);
if (offset) {
spin_unlock(&si->lock);
return swp_entry(type, offset);
}
atomic_long_inc(&nr_swap_pages);
}
spin_unlock(&si->lock);
return (swp_entry_t) {0};
}
static struct swap_info_struct *swap_info_get(swp_entry_t entry)
{
struct swap_info_struct *p;
unsigned long offset, type;
if (!entry.val)
goto out;
type = swp_type(entry);
if (type >= nr_swapfiles)
goto bad_nofile;
p = swap_info[type];
if (!(p->flags & SWP_USED))
goto bad_device;
offset = swp_offset(entry);
if (offset >= p->max)
goto bad_offset;
if (!p->swap_map[offset])
goto bad_free;
spin_lock(&p->lock);
return p;
bad_free:
pr_err("swap_free: %s%08lx\n", Unused_offset, entry.val);
goto out;
bad_offset:
pr_err("swap_free: %s%08lx\n", Bad_offset, entry.val);
goto out;
bad_device:
pr_err("swap_free: %s%08lx\n", Unused_file, entry.val);
goto out;
bad_nofile:
pr_err("swap_free: %s%08lx\n", Bad_file, entry.val);
out:
return NULL;
}
static void set_highest_priority_index(int type)
{
int old_hp_index, new_hp_index;
do {
old_hp_index = atomic_read(&highest_priority_index);
if (old_hp_index != -1 &&
swap_info[old_hp_index]->prio >= swap_info[type]->prio)
break;
new_hp_index = type;
} while (atomic_cmpxchg(&highest_priority_index,
old_hp_index, new_hp_index) != old_hp_index);
}
static unsigned char swap_entry_free(struct swap_info_struct *p,
swp_entry_t entry, unsigned char usage)
{
unsigned long offset = swp_offset(entry);
unsigned char count;
unsigned char has_cache;
count = p->swap_map[offset];
has_cache = count & SWAP_HAS_CACHE;
count &= ~SWAP_HAS_CACHE;
if (usage == SWAP_HAS_CACHE) {
VM_BUG_ON(!has_cache);
has_cache = 0;
} else if (count == SWAP_MAP_SHMEM) {
count = 0;
} else if ((count & ~COUNT_CONTINUED) <= SWAP_MAP_MAX) {
if (count == COUNT_CONTINUED) {
if (swap_count_continued(p, offset, count))
count = SWAP_MAP_MAX | COUNT_CONTINUED;
else
count = SWAP_MAP_MAX;
} else
count--;
}
if (!count)
mem_cgroup_uncharge_swap(entry);
usage = count | has_cache;
p->swap_map[offset] = usage;
if (!usage) {
dec_cluster_info_page(p, p->cluster_info, offset);
if (offset < p->lowest_bit)
p->lowest_bit = offset;
if (offset > p->highest_bit)
p->highest_bit = offset;
set_highest_priority_index(p->type);
atomic_long_inc(&nr_swap_pages);
p->inuse_pages--;
frontswap_invalidate_page(p->type, offset);
if (p->flags & SWP_BLKDEV) {
struct gendisk *disk = p->bdev->bd_disk;
if (disk->fops->swap_slot_free_notify)
disk->fops->swap_slot_free_notify(p->bdev,
offset);
}
}
return usage;
}
void swap_free(swp_entry_t entry)
{
struct swap_info_struct *p;
p = swap_info_get(entry);
if (p) {
swap_entry_free(p, entry, 1);
spin_unlock(&p->lock);
}
}
void swapcache_free(swp_entry_t entry, struct page *page)
{
struct swap_info_struct *p;
unsigned char count;
p = swap_info_get(entry);
if (p) {
count = swap_entry_free(p, entry, SWAP_HAS_CACHE);
if (page)
mem_cgroup_uncharge_swapcache(page, entry, count != 0);
spin_unlock(&p->lock);
}
}
int page_swapcount(struct page *page)
{
int count = 0;
struct swap_info_struct *p;
swp_entry_t entry;
entry.val = page_private(page);
p = swap_info_get(entry);
if (p) {
count = swap_count(p->swap_map[swp_offset(entry)]);
spin_unlock(&p->lock);
}
return count;
}
int reuse_swap_page(struct page *page)
{
int count;
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (unlikely(PageKsm(page)))
return 0;
count = page_mapcount(page);
if (count <= 1 && PageSwapCache(page)) {
count += page_swapcount(page);
if (count == 1 && !PageWriteback(page)) {
delete_from_swap_cache(page);
SetPageDirty(page);
}
}
return count <= 1;
}
int try_to_free_swap(struct page *page)
{
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (!PageSwapCache(page))
return 0;
if (PageWriteback(page))
return 0;
if (page_swapcount(page))
return 0;
if (pm_suspended_storage())
return 0;
delete_from_swap_cache(page);
SetPageDirty(page);
return 1;
}
int free_swap_and_cache(swp_entry_t entry)
{
struct swap_info_struct *p;
struct page *page = NULL;
if (non_swap_entry(entry))
return 1;
p = swap_info_get(entry);
if (p) {
if (swap_entry_free(p, entry, 1) == SWAP_HAS_CACHE) {
page = find_get_page(swap_address_space(entry),
entry.val);
if (page && !trylock_page(page)) {
page_cache_release(page);
page = NULL;
}
}
spin_unlock(&p->lock);
}
if (page) {
if (PageSwapCache(page) && !PageWriteback(page) &&
(!page_mapped(page) || vm_swap_full())) {
delete_from_swap_cache(page);
SetPageDirty(page);
}
unlock_page(page);
page_cache_release(page);
}
return p != NULL;
}
int swap_type_of(dev_t device, sector_t offset, struct block_device **bdev_p)
{
struct block_device *bdev = NULL;
int type;
if (device)
bdev = bdget(device);
spin_lock(&swap_lock);
for (type = 0; type < nr_swapfiles; type++) {
struct swap_info_struct *sis = swap_info[type];
if (!(sis->flags & SWP_WRITEOK))
continue;
if (!bdev) {
if (bdev_p)
*bdev_p = bdgrab(sis->bdev);
spin_unlock(&swap_lock);
return type;
}
if (bdev == sis->bdev) {
struct swap_extent *se = &sis->first_swap_extent;
if (se->start_block == offset) {
if (bdev_p)
*bdev_p = bdgrab(sis->bdev);
spin_unlock(&swap_lock);
bdput(bdev);
return type;
}
}
}
spin_unlock(&swap_lock);
if (bdev)
bdput(bdev);
return -ENODEV;
}
sector_t swapdev_block(int type, pgoff_t offset)
{
struct block_device *bdev;
if ((unsigned int)type >= nr_swapfiles)
return 0;
if (!(swap_info[type]->flags & SWP_WRITEOK))
return 0;
return map_swap_entry(swp_entry(type, offset), &bdev);
}
unsigned int count_swap_pages(int type, int free)
{
unsigned int n = 0;
spin_lock(&swap_lock);
if ((unsigned int)type < nr_swapfiles) {
struct swap_info_struct *sis = swap_info[type];
spin_lock(&sis->lock);
if (sis->flags & SWP_WRITEOK) {
n = sis->pages;
if (free)
n -= sis->inuse_pages;
}
spin_unlock(&sis->lock);
}
spin_unlock(&swap_lock);
return n;
}
static inline int maybe_same_pte(pte_t pte, pte_t swp_pte)
{
#ifdef CONFIG_MEM_SOFT_DIRTY
pte_t swp_pte_dirty = pte_swp_mksoft_dirty(swp_pte);
return pte_same(pte, swp_pte) || pte_same(pte, swp_pte_dirty);
#else
return pte_same(pte, swp_pte);
#endif
}
static int unuse_pte(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, swp_entry_t entry, struct page *page)
{
struct page *swapcache;
struct mem_cgroup *memcg;
spinlock_t *ptl;
pte_t *pte;
int ret = 1;
swapcache = page;
page = ksm_might_need_to_copy(page, vma, addr);
if (unlikely(!page))
return -ENOMEM;
if (mem_cgroup_try_charge_swapin(vma->vm_mm, page,
GFP_KERNEL, &memcg)) {
ret = -ENOMEM;
goto out_nolock;
}
pte = pte_offset_map_lock(vma->vm_mm, pmd, addr, &ptl);
if (unlikely(!maybe_same_pte(*pte, swp_entry_to_pte(entry)))) {
mem_cgroup_cancel_charge_swapin(memcg);
ret = 0;
goto out;
}
dec_mm_counter(vma->vm_mm, MM_SWAPENTS);
inc_mm_counter(vma->vm_mm, MM_ANONPAGES);
get_page(page);
set_pte_at(vma->vm_mm, addr, pte,
pte_mkold(mk_pte(page, vma->vm_page_prot)));
if (page == swapcache)
page_add_anon_rmap(page, vma, addr);
else
page_add_new_anon_rmap(page, vma, addr);
mem_cgroup_commit_charge_swapin(page, memcg);
swap_free(entry);
activate_page(page);
out:
pte_unmap_unlock(pte, ptl);
out_nolock:
if (page != swapcache) {
unlock_page(page);
put_page(page);
}
return ret;
}
static int unuse_pte_range(struct vm_area_struct *vma, pmd_t *pmd,
unsigned long addr, unsigned long end,
swp_entry_t entry, struct page *page)
{
pte_t swp_pte = swp_entry_to_pte(entry);
pte_t *pte;
int ret = 0;
pte = pte_offset_map(pmd, addr);
do {
if (unlikely(maybe_same_pte(*pte, swp_pte))) {
pte_unmap(pte);
ret = unuse_pte(vma, pmd, addr, entry, page);
if (ret)
goto out;
pte = pte_offset_map(pmd, addr);
}
} while (pte++, addr += PAGE_SIZE, addr != end);
pte_unmap(pte - 1);
out:
return ret;
}
static inline int unuse_pmd_range(struct vm_area_struct *vma, pud_t *pud,
unsigned long addr, unsigned long end,
swp_entry_t entry, struct page *page)
{
pmd_t *pmd;
unsigned long next;
int ret;
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
if (pmd_none_or_trans_huge_or_clear_bad(pmd))
continue;
ret = unuse_pte_range(vma, pmd, addr, next, entry, page);
if (ret)
return ret;
} while (pmd++, addr = next, addr != end);
return 0;
}
static inline int unuse_pud_range(struct vm_area_struct *vma, pgd_t *pgd,
unsigned long addr, unsigned long end,
swp_entry_t entry, struct page *page)
{
pud_t *pud;
unsigned long next;
int ret;
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
if (pud_none_or_clear_bad(pud))
continue;
ret = unuse_pmd_range(vma, pud, addr, next, entry, page);
if (ret)
return ret;
} while (pud++, addr = next, addr != end);
return 0;
}
static int unuse_vma(struct vm_area_struct *vma,
swp_entry_t entry, struct page *page)
{
pgd_t *pgd;
unsigned long addr, end, next;
int ret;
if (page_anon_vma(page)) {
addr = page_address_in_vma(page, vma);
if (addr == -EFAULT)
return 0;
else
end = addr + PAGE_SIZE;
} else {
addr = vma->vm_start;
end = vma->vm_end;
}
pgd = pgd_offset(vma->vm_mm, addr);
do {
next = pgd_addr_end(addr, end);
if (pgd_none_or_clear_bad(pgd))
continue;
ret = unuse_pud_range(vma, pgd, addr, next, entry, page);
if (ret)
return ret;
} while (pgd++, addr = next, addr != end);
return 0;
}
static int unuse_mm(struct mm_struct *mm,
swp_entry_t entry, struct page *page)
{
struct vm_area_struct *vma;
int ret = 0;
if (!down_read_trylock(&mm->mmap_sem)) {
activate_page(page);
unlock_page(page);
down_read(&mm->mmap_sem);
lock_page(page);
}
for (vma = mm->mmap; vma; vma = vma->vm_next) {
if (vma->anon_vma && (ret = unuse_vma(vma, entry, page)))
break;
}
up_read(&mm->mmap_sem);
return (ret < 0)? ret: 0;
}
static unsigned int find_next_to_unuse(struct swap_info_struct *si,
unsigned int prev, bool frontswap)
{
unsigned int max = si->max;
unsigned int i = prev;
unsigned char count;
for (;;) {
if (++i >= max) {
if (!prev) {
i = 0;
break;
}
max = prev + 1;
prev = 0;
i = 1;
}
if (frontswap) {
if (frontswap_test(si, i))
break;
else
continue;
}
count = ACCESS_ONCE(si->swap_map[i]);
if (count && swap_count(count) != SWAP_MAP_BAD)
break;
}
return i;
}
int try_to_unuse(unsigned int type, bool frontswap,
unsigned long pages_to_unuse)
{
struct swap_info_struct *si = swap_info[type];
struct mm_struct *start_mm;
volatile unsigned char *swap_map;
unsigned char swcount;
struct page *page;
swp_entry_t entry;
unsigned int i = 0;
int retval = 0;
start_mm = &init_mm;
atomic_inc(&init_mm.mm_users);
while ((i = find_next_to_unuse(si, i, frontswap)) != 0) {
if (signal_pending(current)) {
retval = -EINTR;
break;
}
swap_map = &si->swap_map[i];
entry = swp_entry(type, i);
page = read_swap_cache_async(entry,
GFP_HIGHUSER_MOVABLE, NULL, 0);
if (!page) {
swcount = *swap_map;
if (!swcount || swcount == SWAP_MAP_BAD)
continue;
retval = -ENOMEM;
break;
}
if (atomic_read(&start_mm->mm_users) == 1) {
mmput(start_mm);
start_mm = &init_mm;
atomic_inc(&init_mm.mm_users);
}
wait_on_page_locked(page);
wait_on_page_writeback(page);
lock_page(page);
wait_on_page_writeback(page);
swcount = *swap_map;
if (swap_count(swcount) == SWAP_MAP_SHMEM) {
retval = shmem_unuse(entry, page);
if (retval < 0)
break;
continue;
}
if (swap_count(swcount) && start_mm != &init_mm)
retval = unuse_mm(start_mm, entry, page);
if (swap_count(*swap_map)) {
int set_start_mm = (*swap_map >= swcount);
struct list_head *p = &start_mm->mmlist;
struct mm_struct *new_start_mm = start_mm;
struct mm_struct *prev_mm = start_mm;
struct mm_struct *mm;
atomic_inc(&new_start_mm->mm_users);
atomic_inc(&prev_mm->mm_users);
spin_lock(&mmlist_lock);
while (swap_count(*swap_map) && !retval &&
(p = p->next) != &start_mm->mmlist) {
mm = list_entry(p, struct mm_struct, mmlist);
if (!atomic_inc_not_zero(&mm->mm_users))
continue;
spin_unlock(&mmlist_lock);
mmput(prev_mm);
prev_mm = mm;
cond_resched();
swcount = *swap_map;
if (!swap_count(swcount))
;
else if (mm == &init_mm)
set_start_mm = 1;
else
retval = unuse_mm(mm, entry, page);
if (set_start_mm && *swap_map < swcount) {
mmput(new_start_mm);
atomic_inc(&mm->mm_users);
new_start_mm = mm;
set_start_mm = 0;
}
spin_lock(&mmlist_lock);
}
spin_unlock(&mmlist_lock);
mmput(prev_mm);
mmput(start_mm);
start_mm = new_start_mm;
}
if (retval) {
unlock_page(page);
page_cache_release(page);
break;
}
if (swap_count(*swap_map) &&
PageDirty(page) && PageSwapCache(page)) {
struct writeback_control wbc = {
.sync_mode = WB_SYNC_NONE,
};
swap_writepage(page, &wbc);
lock_page(page);
wait_on_page_writeback(page);
}
if (PageSwapCache(page) &&
likely(page_private(page) == entry.val))
delete_from_swap_cache(page);
SetPageDirty(page);
unlock_page(page);
page_cache_release(page);
cond_resched();
if (frontswap && pages_to_unuse > 0) {
if (!--pages_to_unuse)
break;
}
}
mmput(start_mm);
return retval;
}
static void drain_mmlist(void)
{
struct list_head *p, *next;
unsigned int type;
for (type = 0; type < nr_swapfiles; type++)
if (swap_info[type]->inuse_pages)
return;
spin_lock(&mmlist_lock);
list_for_each_safe(p, next, &init_mm.mmlist)
list_del_init(p);
spin_unlock(&mmlist_lock);
}
static sector_t map_swap_entry(swp_entry_t entry, struct block_device **bdev)
{
struct swap_info_struct *sis;
struct swap_extent *start_se;
struct swap_extent *se;
pgoff_t offset;
sis = swap_info[swp_type(entry)];
*bdev = sis->bdev;
offset = swp_offset(entry);
start_se = sis->curr_swap_extent;
se = start_se;
for ( ; ; ) {
struct list_head *lh;
if (se->start_page <= offset &&
offset < (se->start_page + se->nr_pages)) {
return se->start_block + (offset - se->start_page);
}
lh = se->list.next;
se = list_entry(lh, struct swap_extent, list);
sis->curr_swap_extent = se;
BUG_ON(se == start_se);
}
}
sector_t map_swap_page(struct page *page, struct block_device **bdev)
{
swp_entry_t entry;
entry.val = page_private(page);
return map_swap_entry(entry, bdev);
}
static void destroy_swap_extents(struct swap_info_struct *sis)
{
while (!list_empty(&sis->first_swap_extent.list)) {
struct swap_extent *se;
se = list_entry(sis->first_swap_extent.list.next,
struct swap_extent, list);
list_del(&se->list);
kfree(se);
}
if (sis->flags & SWP_FILE) {
struct file *swap_file = sis->swap_file;
struct address_space *mapping = swap_file->f_mapping;
sis->flags &= ~SWP_FILE;
mapping->a_ops->swap_deactivate(swap_file);
}
}
int
add_swap_extent(struct swap_info_struct *sis, unsigned long start_page,
unsigned long nr_pages, sector_t start_block)
{
struct swap_extent *se;
struct swap_extent *new_se;
struct list_head *lh;
if (start_page == 0) {
se = &sis->first_swap_extent;
sis->curr_swap_extent = se;
se->start_page = 0;
se->nr_pages = nr_pages;
se->start_block = start_block;
return 1;
} else {
lh = sis->first_swap_extent.list.prev;
se = list_entry(lh, struct swap_extent, list);
BUG_ON(se->start_page + se->nr_pages != start_page);
if (se->start_block + se->nr_pages == start_block) {
se->nr_pages += nr_pages;
return 0;
}
}
new_se = kmalloc(sizeof(*se), GFP_KERNEL);
if (new_se == NULL)
return -ENOMEM;
new_se->start_page = start_page;
new_se->nr_pages = nr_pages;
new_se->start_block = start_block;
list_add_tail(&new_se->list, &sis->first_swap_extent.list);
return 1;
}
static int setup_swap_extents(struct swap_info_struct *sis, sector_t *span)
{
struct file *swap_file = sis->swap_file;
struct address_space *mapping = swap_file->f_mapping;
struct inode *inode = mapping->host;
int ret;
if (S_ISBLK(inode->i_mode)) {
ret = add_swap_extent(sis, 0, sis->max, 0);
*span = sis->pages;
return ret;
}
if (mapping->a_ops->swap_activate) {
ret = mapping->a_ops->swap_activate(sis, swap_file, span);
if (!ret) {
sis->flags |= SWP_FILE;
ret = add_swap_extent(sis, 0, sis->max, 0);
*span = sis->pages;
}
return ret;
}
return generic_swapfile_activate(sis, swap_file, span);
}
static void _enable_swap_info(struct swap_info_struct *p, int prio,
unsigned char *swap_map,
struct swap_cluster_info *cluster_info)
{
int i, prev;
if (prio >= 0)
p->prio = prio;
else
p->prio = --least_priority;
p->swap_map = swap_map;
p->cluster_info = cluster_info;
p->flags |= SWP_WRITEOK;
atomic_long_add(p->pages, &nr_swap_pages);
total_swap_pages += p->pages;
prev = -1;
for (i = swap_list.head; i >= 0; i = swap_info[i]->next) {
if (p->prio >= swap_info[i]->prio)
break;
prev = i;
}
p->next = i;
if (prev < 0)
swap_list.head = swap_list.next = p->type;
else
swap_info[prev]->next = p->type;
}
static void enable_swap_info(struct swap_info_struct *p, int prio,
unsigned char *swap_map,
struct swap_cluster_info *cluster_info,
unsigned long *frontswap_map)
{
frontswap_init(p->type, frontswap_map);
spin_lock(&swap_lock);
spin_lock(&p->lock);
_enable_swap_info(p, prio, swap_map, cluster_info);
spin_unlock(&p->lock);
spin_unlock(&swap_lock);
}
static void reinsert_swap_info(struct swap_info_struct *p)
{
spin_lock(&swap_lock);
spin_lock(&p->lock);
_enable_swap_info(p, p->prio, p->swap_map, p->cluster_info);
spin_unlock(&p->lock);
spin_unlock(&swap_lock);
}
static unsigned swaps_poll(struct file *file, poll_table *wait)
{
struct seq_file *seq = file->private_data;
poll_wait(file, &proc_poll_wait, wait);
if (seq->poll_event != atomic_read(&proc_poll_event)) {
seq->poll_event = atomic_read(&proc_poll_event);
return POLLIN | POLLRDNORM | POLLERR | POLLPRI;
}
return POLLIN | POLLRDNORM;
}
static void *swap_start(struct seq_file *swap, loff_t *pos)
{
struct swap_info_struct *si;
int type;
loff_t l = *pos;
mutex_lock(&swapon_mutex);
if (!l)
return SEQ_START_TOKEN;
for (type = 0; type < nr_swapfiles; type++) {
smp_rmb();
si = swap_info[type];
if (!(si->flags & SWP_USED) || !si->swap_map)
continue;
if (!--l)
return si;
}
return NULL;
}
static void *swap_next(struct seq_file *swap, void *v, loff_t *pos)
{
struct swap_info_struct *si = v;
int type;
if (v == SEQ_START_TOKEN)
type = 0;
else
type = si->type + 1;
for (; type < nr_swapfiles; type++) {
smp_rmb();
si = swap_info[type];
if (!(si->flags & SWP_USED) || !si->swap_map)
continue;
++*pos;
return si;
}
return NULL;
}
static void swap_stop(struct seq_file *swap, void *v)
{
mutex_unlock(&swapon_mutex);
}
static int swap_show(struct seq_file *swap, void *v)
{
struct swap_info_struct *si = v;
struct file *file;
int len;
if (si == SEQ_START_TOKEN) {
seq_puts(swap,"Filename\t\t\t\tType\t\tSize\tUsed\tPriority\n");
return 0;
}
file = si->swap_file;
len = seq_path(swap, &file->f_path, " \t\n\\");
seq_printf(swap, "%*s%s\t%u\t%u\t%d\n",
len < 40 ? 40 - len : 1, " ",
S_ISBLK(file_inode(file)->i_mode) ?
"partition" : "file\t",
si->pages << (PAGE_SHIFT - 10),
si->inuse_pages << (PAGE_SHIFT - 10),
si->prio);
return 0;
}
static int swaps_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int ret;
ret = seq_open(file, &swaps_op);
if (ret)
return ret;
seq = file->private_data;
seq->poll_event = atomic_read(&proc_poll_event);
return 0;
}
static int __init procswaps_init(void)
{
proc_create("swaps", 0, NULL, &proc_swaps_operations);
return 0;
}
static int __init max_swapfiles_check(void)
{
MAX_SWAPFILES_CHECK();
return 0;
}
static struct swap_info_struct *alloc_swap_info(void)
{
struct swap_info_struct *p;
unsigned int type;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return ERR_PTR(-ENOMEM);
spin_lock(&swap_lock);
for (type = 0; type < nr_swapfiles; type++) {
if (!(swap_info[type]->flags & SWP_USED))
break;
}
if (type >= MAX_SWAPFILES) {
spin_unlock(&swap_lock);
kfree(p);
return ERR_PTR(-EPERM);
}
if (type >= nr_swapfiles) {
p->type = type;
swap_info[type] = p;
smp_wmb();
nr_swapfiles++;
} else {
kfree(p);
p = swap_info[type];
}
INIT_LIST_HEAD(&p->first_swap_extent.list);
p->flags = SWP_USED;
p->next = -1;
spin_unlock(&swap_lock);
spin_lock_init(&p->lock);
return p;
}
static int claim_swapfile(struct swap_info_struct *p, struct inode *inode)
{
int error;
if (S_ISBLK(inode->i_mode)) {
p->bdev = bdgrab(I_BDEV(inode));
error = blkdev_get(p->bdev,
FMODE_READ | FMODE_WRITE | FMODE_EXCL,
sys_swapon);
if (error < 0) {
p->bdev = NULL;
return -EINVAL;
}
p->old_block_size = block_size(p->bdev);
error = set_blocksize(p->bdev, PAGE_SIZE);
if (error < 0)
return error;
p->flags |= SWP_BLKDEV;
} else if (S_ISREG(inode->i_mode)) {
p->bdev = inode->i_sb->s_bdev;
mutex_lock(&inode->i_mutex);
if (IS_SWAPFILE(inode))
return -EBUSY;
} else
return -EINVAL;
return 0;
}
static unsigned long read_swap_header(struct swap_info_struct *p,
union swap_header *swap_header,
struct inode *inode)
{
int i;
unsigned long maxpages;
unsigned long swapfilepages;
unsigned long last_page;
if (memcmp("SWAPSPACE2", swap_header->magic.magic, 10)) {
pr_err("Unable to find swap-space signature\n");
return 0;
}
if (swab32(swap_header->info.version) == 1) {
swab32s(&swap_header->info.version);
swab32s(&swap_header->info.last_page);
swab32s(&swap_header->info.nr_badpages);
for (i = 0; i < swap_header->info.nr_badpages; i++)
swab32s(&swap_header->info.badpages[i]);
}
if (swap_header->info.version != 1) {
pr_warn("Unable to handle swap header version %d\n",
swap_header->info.version);
return 0;
}
p->lowest_bit = 1;
p->cluster_next = 1;
p->cluster_nr = 0;
maxpages = swp_offset(pte_to_swp_entry(
swp_entry_to_pte(swp_entry(0, ~0UL)))) + 1;
last_page = swap_header->info.last_page;
if (last_page > maxpages) {
pr_warn("Truncating oversized swap area, only using %luk out of %luk\n",
maxpages << (PAGE_SHIFT - 10),
last_page << (PAGE_SHIFT - 10));
}
if (maxpages > last_page) {
maxpages = last_page + 1;
if ((unsigned int)maxpages == 0)
maxpages = UINT_MAX;
}
p->highest_bit = maxpages - 1;
if (!maxpages)
return 0;
swapfilepages = i_size_read(inode) >> PAGE_SHIFT;
if (swapfilepages && maxpages > swapfilepages) {
pr_warn("Swap area shorter than signature indicates\n");
return 0;
}
if (swap_header->info.nr_badpages && S_ISREG(inode->i_mode))
return 0;
if (swap_header->info.nr_badpages > MAX_SWAP_BADPAGES)
return 0;
return maxpages;
}
static int setup_swap_map_and_extents(struct swap_info_struct *p,
union swap_header *swap_header,
unsigned char *swap_map,
struct swap_cluster_info *cluster_info,
unsigned long maxpages,
sector_t *span)
{
int i;
unsigned int nr_good_pages;
int nr_extents;
unsigned long nr_clusters = DIV_ROUND_UP(maxpages, SWAPFILE_CLUSTER);
unsigned long idx = p->cluster_next / SWAPFILE_CLUSTER;
nr_good_pages = maxpages - 1;
cluster_set_null(&p->free_cluster_head);
cluster_set_null(&p->free_cluster_tail);
cluster_set_null(&p->discard_cluster_head);
cluster_set_null(&p->discard_cluster_tail);
for (i = 0; i < swap_header->info.nr_badpages; i++) {
unsigned int page_nr = swap_header->info.badpages[i];
if (page_nr == 0 || page_nr > swap_header->info.last_page)
return -EINVAL;
if (page_nr < maxpages) {
swap_map[page_nr] = SWAP_MAP_BAD;
nr_good_pages--;
inc_cluster_info_page(p, cluster_info, page_nr);
}
}
for (i = maxpages; i < round_up(maxpages, SWAPFILE_CLUSTER); i++)
inc_cluster_info_page(p, cluster_info, i);
if (nr_good_pages) {
swap_map[0] = SWAP_MAP_BAD;
inc_cluster_info_page(p, cluster_info, 0);
p->max = maxpages;
p->pages = nr_good_pages;
nr_extents = setup_swap_extents(p, span);
if (nr_extents < 0)
return nr_extents;
nr_good_pages = p->pages;
}
if (!nr_good_pages) {
pr_warn("Empty swap-file\n");
return -EINVAL;
}
if (!cluster_info)
return nr_extents;
for (i = 0; i < nr_clusters; i++) {
if (!cluster_count(&cluster_info[idx])) {
cluster_set_flag(&cluster_info[idx], CLUSTER_FLAG_FREE);
if (cluster_is_null(&p->free_cluster_head)) {
cluster_set_next_flag(&p->free_cluster_head,
idx, 0);
cluster_set_next_flag(&p->free_cluster_tail,
idx, 0);
} else {
unsigned int tail;
tail = cluster_next(&p->free_cluster_tail);
cluster_set_next(&cluster_info[tail], idx);
cluster_set_next_flag(&p->free_cluster_tail,
idx, 0);
}
}
idx++;
if (idx == nr_clusters)
idx = 0;
}
return nr_extents;
}
static bool swap_discardable(struct swap_info_struct *si)
{
struct request_queue *q = bdev_get_queue(si->bdev);
if (!q || !blk_queue_discard(q))
return false;
return true;
}
void si_swapinfo(struct sysinfo *val)
{
unsigned int type;
unsigned long nr_to_be_unused = 0;
spin_lock(&swap_lock);
for (type = 0; type < nr_swapfiles; type++) {
struct swap_info_struct *si = swap_info[type];
if ((si->flags & SWP_USED) && !(si->flags & SWP_WRITEOK))
nr_to_be_unused += si->inuse_pages;
}
val->freeswap = atomic_long_read(&nr_swap_pages) + nr_to_be_unused;
val->totalswap = total_swap_pages + nr_to_be_unused;
spin_unlock(&swap_lock);
}
static int __swap_duplicate(swp_entry_t entry, unsigned char usage)
{
struct swap_info_struct *p;
unsigned long offset, type;
unsigned char count;
unsigned char has_cache;
int err = -EINVAL;
if (non_swap_entry(entry))
goto out;
type = swp_type(entry);
if (type >= nr_swapfiles)
goto bad_file;
p = swap_info[type];
offset = swp_offset(entry);
spin_lock(&p->lock);
if (unlikely(offset >= p->max))
goto unlock_out;
count = p->swap_map[offset];
if (unlikely(swap_count(count) == SWAP_MAP_BAD)) {
err = -ENOENT;
goto unlock_out;
}
has_cache = count & SWAP_HAS_CACHE;
count &= ~SWAP_HAS_CACHE;
err = 0;
if (usage == SWAP_HAS_CACHE) {
if (!has_cache && count)
has_cache = SWAP_HAS_CACHE;
else if (has_cache)
err = -EEXIST;
else
err = -ENOENT;
} else if (count || has_cache) {
if ((count & ~COUNT_CONTINUED) < SWAP_MAP_MAX)
count += usage;
else if ((count & ~COUNT_CONTINUED) > SWAP_MAP_MAX)
err = -EINVAL;
else if (swap_count_continued(p, offset, count))
count = COUNT_CONTINUED;
else
err = -ENOMEM;
} else
err = -ENOENT;
p->swap_map[offset] = count | has_cache;
unlock_out:
spin_unlock(&p->lock);
out:
return err;
bad_file:
pr_err("swap_dup: %s%08lx\n", Bad_file, entry.val);
goto out;
}
void swap_shmem_alloc(swp_entry_t entry)
{
__swap_duplicate(entry, SWAP_MAP_SHMEM);
}
int swap_duplicate(swp_entry_t entry)
{
int err = 0;
while (!err && __swap_duplicate(entry, 1) == -ENOMEM)
err = add_swap_count_continuation(entry, GFP_ATOMIC);
return err;
}
int swapcache_prepare(swp_entry_t entry)
{
return __swap_duplicate(entry, SWAP_HAS_CACHE);
}
struct swap_info_struct *page_swap_info(struct page *page)
{
swp_entry_t swap = { .val = page_private(page) };
BUG_ON(!PageSwapCache(page));
return swap_info[swp_type(swap)];
}
struct address_space *__page_file_mapping(struct page *page)
{
VM_BUG_ON_PAGE(!PageSwapCache(page), page);
return page_swap_info(page)->swap_file->f_mapping;
}
pgoff_t __page_file_index(struct page *page)
{
swp_entry_t swap = { .val = page_private(page) };
VM_BUG_ON_PAGE(!PageSwapCache(page), page);
return swp_offset(swap);
}
int add_swap_count_continuation(swp_entry_t entry, gfp_t gfp_mask)
{
struct swap_info_struct *si;
struct page *head;
struct page *page;
struct page *list_page;
pgoff_t offset;
unsigned char count;
page = alloc_page(gfp_mask | __GFP_HIGHMEM);
si = swap_info_get(entry);
if (!si) {
goto outer;
}
offset = swp_offset(entry);
count = si->swap_map[offset] & ~SWAP_HAS_CACHE;
if ((count & ~COUNT_CONTINUED) != SWAP_MAP_MAX) {
goto out;
}
if (!page) {
spin_unlock(&si->lock);
return -ENOMEM;
}
head = vmalloc_to_page(si->swap_map + offset);
offset &= ~PAGE_MASK;
if (!page_private(head)) {
BUG_ON(count & COUNT_CONTINUED);
INIT_LIST_HEAD(&head->lru);
set_page_private(head, SWP_CONTINUED);
si->flags |= SWP_CONTINUED;
}
list_for_each_entry(list_page, &head->lru, lru) {
unsigned char *map;
if (!(count & COUNT_CONTINUED))
goto out;
map = kmap_atomic(list_page) + offset;
count = *map;
kunmap_atomic(map);
if ((count & ~COUNT_CONTINUED) != SWAP_CONT_MAX)
goto out;
}
list_add_tail(&page->lru, &head->lru);
page = NULL;
out:
spin_unlock(&si->lock);
outer:
if (page)
__free_page(page);
return 0;
}
static bool swap_count_continued(struct swap_info_struct *si,
pgoff_t offset, unsigned char count)
{
struct page *head;
struct page *page;
unsigned char *map;
head = vmalloc_to_page(si->swap_map + offset);
if (page_private(head) != SWP_CONTINUED) {
BUG_ON(count & COUNT_CONTINUED);
return false;
}
offset &= ~PAGE_MASK;
page = list_entry(head->lru.next, struct page, lru);
map = kmap_atomic(page) + offset;
if (count == SWAP_MAP_MAX)
goto init_map;
if (count == (SWAP_MAP_MAX | COUNT_CONTINUED)) {
while (*map == (SWAP_CONT_MAX | COUNT_CONTINUED)) {
kunmap_atomic(map);
page = list_entry(page->lru.next, struct page, lru);
BUG_ON(page == head);
map = kmap_atomic(page) + offset;
}
if (*map == SWAP_CONT_MAX) {
kunmap_atomic(map);
page = list_entry(page->lru.next, struct page, lru);
if (page == head)
return false;
map = kmap_atomic(page) + offset;
init_map: *map = 0;
}
*map += 1;
kunmap_atomic(map);
page = list_entry(page->lru.prev, struct page, lru);
while (page != head) {
map = kmap_atomic(page) + offset;
*map = COUNT_CONTINUED;
kunmap_atomic(map);
page = list_entry(page->lru.prev, struct page, lru);
}
return true;
} else {
BUG_ON(count != COUNT_CONTINUED);
while (*map == COUNT_CONTINUED) {
kunmap_atomic(map);
page = list_entry(page->lru.next, struct page, lru);
BUG_ON(page == head);
map = kmap_atomic(page) + offset;
}
BUG_ON(*map == 0);
*map -= 1;
if (*map == 0)
count = 0;
kunmap_atomic(map);
page = list_entry(page->lru.prev, struct page, lru);
while (page != head) {
map = kmap_atomic(page) + offset;
*map = SWAP_CONT_MAX | count;
count = COUNT_CONTINUED;
kunmap_atomic(map);
page = list_entry(page->lru.prev, struct page, lru);
}
return count == COUNT_CONTINUED;
}
}
static void free_swap_count_continuations(struct swap_info_struct *si)
{
pgoff_t offset;
for (offset = 0; offset < si->max; offset += PAGE_SIZE) {
struct page *head;
head = vmalloc_to_page(si->swap_map + offset);
if (page_private(head)) {
struct list_head *this, *next;
list_for_each_safe(this, next, &head->lru) {
struct page *page;
page = list_entry(this, struct page, lru);
list_del(this);
__free_page(page);
}
}
}
}
