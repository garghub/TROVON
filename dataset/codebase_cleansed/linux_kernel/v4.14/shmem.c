static unsigned long shmem_default_max_blocks(void)
{
return totalram_pages / 2;
}
static unsigned long shmem_default_max_inodes(void)
{
return min(totalram_pages - totalhigh_pages, totalram_pages / 2);
}
int shmem_getpage(struct inode *inode, pgoff_t index,
struct page **pagep, enum sgp_type sgp)
{
return shmem_getpage_gfp(inode, index, pagep, sgp,
mapping_gfp_mask(inode->i_mapping), NULL, NULL, NULL);
}
static inline struct shmem_sb_info *SHMEM_SB(struct super_block *sb)
{
return sb->s_fs_info;
}
static inline int shmem_acct_size(unsigned long flags, loff_t size)
{
return (flags & VM_NORESERVE) ?
0 : security_vm_enough_memory_mm(current->mm, VM_ACCT(size));
}
static inline void shmem_unacct_size(unsigned long flags, loff_t size)
{
if (!(flags & VM_NORESERVE))
vm_unacct_memory(VM_ACCT(size));
}
static inline int shmem_reacct_size(unsigned long flags,
loff_t oldsize, loff_t newsize)
{
if (!(flags & VM_NORESERVE)) {
if (VM_ACCT(newsize) > VM_ACCT(oldsize))
return security_vm_enough_memory_mm(current->mm,
VM_ACCT(newsize) - VM_ACCT(oldsize));
else if (VM_ACCT(newsize) < VM_ACCT(oldsize))
vm_unacct_memory(VM_ACCT(oldsize) - VM_ACCT(newsize));
}
return 0;
}
static inline int shmem_acct_block(unsigned long flags, long pages)
{
if (!(flags & VM_NORESERVE))
return 0;
return security_vm_enough_memory_mm(current->mm,
pages * VM_ACCT(PAGE_SIZE));
}
static inline void shmem_unacct_blocks(unsigned long flags, long pages)
{
if (flags & VM_NORESERVE)
vm_unacct_memory(pages * VM_ACCT(PAGE_SIZE));
}
static inline bool shmem_inode_acct_block(struct inode *inode, long pages)
{
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
if (shmem_acct_block(info->flags, pages))
return false;
if (sbinfo->max_blocks) {
if (percpu_counter_compare(&sbinfo->used_blocks,
sbinfo->max_blocks - pages) > 0)
goto unacct;
percpu_counter_add(&sbinfo->used_blocks, pages);
}
return true;
unacct:
shmem_unacct_blocks(info->flags, pages);
return false;
}
static inline void shmem_inode_unacct_blocks(struct inode *inode, long pages)
{
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
if (sbinfo->max_blocks)
percpu_counter_sub(&sbinfo->used_blocks, pages);
shmem_unacct_blocks(info->flags, pages);
}
bool vma_is_shmem(struct vm_area_struct *vma)
{
return vma->vm_ops == &shmem_vm_ops;
}
static int shmem_reserve_inode(struct super_block *sb)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
if (sbinfo->max_inodes) {
spin_lock(&sbinfo->stat_lock);
if (!sbinfo->free_inodes) {
spin_unlock(&sbinfo->stat_lock);
return -ENOSPC;
}
sbinfo->free_inodes--;
spin_unlock(&sbinfo->stat_lock);
}
return 0;
}
static void shmem_free_inode(struct super_block *sb)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
if (sbinfo->max_inodes) {
spin_lock(&sbinfo->stat_lock);
sbinfo->free_inodes++;
spin_unlock(&sbinfo->stat_lock);
}
}
static void shmem_recalc_inode(struct inode *inode)
{
struct shmem_inode_info *info = SHMEM_I(inode);
long freed;
freed = info->alloced - info->swapped - inode->i_mapping->nrpages;
if (freed > 0) {
info->alloced -= freed;
inode->i_blocks -= freed * BLOCKS_PER_PAGE;
shmem_inode_unacct_blocks(inode, freed);
}
}
bool shmem_charge(struct inode *inode, long pages)
{
struct shmem_inode_info *info = SHMEM_I(inode);
unsigned long flags;
if (!shmem_inode_acct_block(inode, pages))
return false;
spin_lock_irqsave(&info->lock, flags);
info->alloced += pages;
inode->i_blocks += pages * BLOCKS_PER_PAGE;
shmem_recalc_inode(inode);
spin_unlock_irqrestore(&info->lock, flags);
inode->i_mapping->nrpages += pages;
return true;
}
void shmem_uncharge(struct inode *inode, long pages)
{
struct shmem_inode_info *info = SHMEM_I(inode);
unsigned long flags;
spin_lock_irqsave(&info->lock, flags);
info->alloced -= pages;
inode->i_blocks -= pages * BLOCKS_PER_PAGE;
shmem_recalc_inode(inode);
spin_unlock_irqrestore(&info->lock, flags);
shmem_inode_unacct_blocks(inode, pages);
}
static int shmem_radix_tree_replace(struct address_space *mapping,
pgoff_t index, void *expected, void *replacement)
{
struct radix_tree_node *node;
void **pslot;
void *item;
VM_BUG_ON(!expected);
VM_BUG_ON(!replacement);
item = __radix_tree_lookup(&mapping->page_tree, index, &node, &pslot);
if (!item)
return -ENOENT;
if (item != expected)
return -ENOENT;
__radix_tree_replace(&mapping->page_tree, node, pslot,
replacement, NULL, NULL);
return 0;
}
static bool shmem_confirm_swap(struct address_space *mapping,
pgoff_t index, swp_entry_t swap)
{
void *item;
rcu_read_lock();
item = radix_tree_lookup(&mapping->page_tree, index);
rcu_read_unlock();
return item == swp_to_radix_entry(swap);
}
static int shmem_parse_huge(const char *str)
{
if (!strcmp(str, "never"))
return SHMEM_HUGE_NEVER;
if (!strcmp(str, "always"))
return SHMEM_HUGE_ALWAYS;
if (!strcmp(str, "within_size"))
return SHMEM_HUGE_WITHIN_SIZE;
if (!strcmp(str, "advise"))
return SHMEM_HUGE_ADVISE;
if (!strcmp(str, "deny"))
return SHMEM_HUGE_DENY;
if (!strcmp(str, "force"))
return SHMEM_HUGE_FORCE;
return -EINVAL;
}
static const char *shmem_format_huge(int huge)
{
switch (huge) {
case SHMEM_HUGE_NEVER:
return "never";
case SHMEM_HUGE_ALWAYS:
return "always";
case SHMEM_HUGE_WITHIN_SIZE:
return "within_size";
case SHMEM_HUGE_ADVISE:
return "advise";
case SHMEM_HUGE_DENY:
return "deny";
case SHMEM_HUGE_FORCE:
return "force";
default:
VM_BUG_ON(1);
return "bad_val";
}
}
static unsigned long shmem_unused_huge_shrink(struct shmem_sb_info *sbinfo,
struct shrink_control *sc, unsigned long nr_to_split)
{
LIST_HEAD(list), *pos, *next;
LIST_HEAD(to_remove);
struct inode *inode;
struct shmem_inode_info *info;
struct page *page;
unsigned long batch = sc ? sc->nr_to_scan : 128;
int removed = 0, split = 0;
if (list_empty(&sbinfo->shrinklist))
return SHRINK_STOP;
spin_lock(&sbinfo->shrinklist_lock);
list_for_each_safe(pos, next, &sbinfo->shrinklist) {
info = list_entry(pos, struct shmem_inode_info, shrinklist);
inode = igrab(&info->vfs_inode);
if (!inode) {
list_del_init(&info->shrinklist);
removed++;
goto next;
}
if (round_up(inode->i_size, PAGE_SIZE) ==
round_up(inode->i_size, HPAGE_PMD_SIZE)) {
list_move(&info->shrinklist, &to_remove);
removed++;
goto next;
}
list_move(&info->shrinklist, &list);
next:
if (!--batch)
break;
}
spin_unlock(&sbinfo->shrinklist_lock);
list_for_each_safe(pos, next, &to_remove) {
info = list_entry(pos, struct shmem_inode_info, shrinklist);
inode = &info->vfs_inode;
list_del_init(&info->shrinklist);
iput(inode);
}
list_for_each_safe(pos, next, &list) {
int ret;
info = list_entry(pos, struct shmem_inode_info, shrinklist);
inode = &info->vfs_inode;
if (nr_to_split && split >= nr_to_split) {
iput(inode);
continue;
}
page = find_lock_page(inode->i_mapping,
(inode->i_size & HPAGE_PMD_MASK) >> PAGE_SHIFT);
if (!page)
goto drop;
if (!PageTransHuge(page)) {
unlock_page(page);
put_page(page);
goto drop;
}
ret = split_huge_page(page);
unlock_page(page);
put_page(page);
if (ret) {
iput(inode);
continue;
}
split++;
drop:
list_del_init(&info->shrinklist);
removed++;
iput(inode);
}
spin_lock(&sbinfo->shrinklist_lock);
list_splice_tail(&list, &sbinfo->shrinklist);
sbinfo->shrinklist_len -= removed;
spin_unlock(&sbinfo->shrinklist_lock);
return split;
}
static long shmem_unused_huge_scan(struct super_block *sb,
struct shrink_control *sc)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
if (!READ_ONCE(sbinfo->shrinklist_len))
return SHRINK_STOP;
return shmem_unused_huge_shrink(sbinfo, sc, 0);
}
static long shmem_unused_huge_count(struct super_block *sb,
struct shrink_control *sc)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
return READ_ONCE(sbinfo->shrinklist_len);
}
static unsigned long shmem_unused_huge_shrink(struct shmem_sb_info *sbinfo,
struct shrink_control *sc, unsigned long nr_to_split)
{
return 0;
}
static int shmem_add_to_page_cache(struct page *page,
struct address_space *mapping,
pgoff_t index, void *expected)
{
int error, nr = hpage_nr_pages(page);
VM_BUG_ON_PAGE(PageTail(page), page);
VM_BUG_ON_PAGE(index != round_down(index, nr), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageSwapBacked(page), page);
VM_BUG_ON(expected && PageTransHuge(page));
page_ref_add(page, nr);
page->mapping = mapping;
page->index = index;
spin_lock_irq(&mapping->tree_lock);
if (PageTransHuge(page)) {
void __rcu **results;
pgoff_t idx;
int i;
error = 0;
if (radix_tree_gang_lookup_slot(&mapping->page_tree,
&results, &idx, index, 1) &&
idx < index + HPAGE_PMD_NR) {
error = -EEXIST;
}
if (!error) {
for (i = 0; i < HPAGE_PMD_NR; i++) {
error = radix_tree_insert(&mapping->page_tree,
index + i, page + i);
VM_BUG_ON(error);
}
count_vm_event(THP_FILE_ALLOC);
}
} else if (!expected) {
error = radix_tree_insert(&mapping->page_tree, index, page);
} else {
error = shmem_radix_tree_replace(mapping, index, expected,
page);
}
if (!error) {
mapping->nrpages += nr;
if (PageTransHuge(page))
__inc_node_page_state(page, NR_SHMEM_THPS);
__mod_node_page_state(page_pgdat(page), NR_FILE_PAGES, nr);
__mod_node_page_state(page_pgdat(page), NR_SHMEM, nr);
spin_unlock_irq(&mapping->tree_lock);
} else {
page->mapping = NULL;
spin_unlock_irq(&mapping->tree_lock);
page_ref_sub(page, nr);
}
return error;
}
static void shmem_delete_from_page_cache(struct page *page, void *radswap)
{
struct address_space *mapping = page->mapping;
int error;
VM_BUG_ON_PAGE(PageCompound(page), page);
spin_lock_irq(&mapping->tree_lock);
error = shmem_radix_tree_replace(mapping, page->index, page, radswap);
page->mapping = NULL;
mapping->nrpages--;
__dec_node_page_state(page, NR_FILE_PAGES);
__dec_node_page_state(page, NR_SHMEM);
spin_unlock_irq(&mapping->tree_lock);
put_page(page);
BUG_ON(error);
}
static int shmem_free_swap(struct address_space *mapping,
pgoff_t index, void *radswap)
{
void *old;
spin_lock_irq(&mapping->tree_lock);
old = radix_tree_delete_item(&mapping->page_tree, index, radswap);
spin_unlock_irq(&mapping->tree_lock);
if (old != radswap)
return -ENOENT;
free_swap_and_cache(radix_to_swp_entry(radswap));
return 0;
}
unsigned long shmem_partial_swap_usage(struct address_space *mapping,
pgoff_t start, pgoff_t end)
{
struct radix_tree_iter iter;
void **slot;
struct page *page;
unsigned long swapped = 0;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
if (iter.index >= end)
break;
page = radix_tree_deref_slot(slot);
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
if (radix_tree_exceptional_entry(page))
swapped++;
if (need_resched()) {
slot = radix_tree_iter_resume(slot, &iter);
cond_resched_rcu();
}
}
rcu_read_unlock();
return swapped << PAGE_SHIFT;
}
unsigned long shmem_swap_usage(struct vm_area_struct *vma)
{
struct inode *inode = file_inode(vma->vm_file);
struct shmem_inode_info *info = SHMEM_I(inode);
struct address_space *mapping = inode->i_mapping;
unsigned long swapped;
swapped = READ_ONCE(info->swapped);
if (!swapped)
return 0;
if (!vma->vm_pgoff && vma->vm_end - vma->vm_start >= inode->i_size)
return swapped << PAGE_SHIFT;
return shmem_partial_swap_usage(mapping,
linear_page_index(vma, vma->vm_start),
linear_page_index(vma, vma->vm_end));
}
void shmem_unlock_mapping(struct address_space *mapping)
{
struct pagevec pvec;
pgoff_t indices[PAGEVEC_SIZE];
pgoff_t index = 0;
pagevec_init(&pvec, 0);
while (!mapping_unevictable(mapping)) {
pvec.nr = find_get_entries(mapping, index,
PAGEVEC_SIZE, pvec.pages, indices);
if (!pvec.nr)
break;
index = indices[pvec.nr - 1] + 1;
pagevec_remove_exceptionals(&pvec);
check_move_unevictable_pages(pvec.pages, pvec.nr);
pagevec_release(&pvec);
cond_resched();
}
}
static void shmem_undo_range(struct inode *inode, loff_t lstart, loff_t lend,
bool unfalloc)
{
struct address_space *mapping = inode->i_mapping;
struct shmem_inode_info *info = SHMEM_I(inode);
pgoff_t start = (lstart + PAGE_SIZE - 1) >> PAGE_SHIFT;
pgoff_t end = (lend + 1) >> PAGE_SHIFT;
unsigned int partial_start = lstart & (PAGE_SIZE - 1);
unsigned int partial_end = (lend + 1) & (PAGE_SIZE - 1);
struct pagevec pvec;
pgoff_t indices[PAGEVEC_SIZE];
long nr_swaps_freed = 0;
pgoff_t index;
int i;
if (lend == -1)
end = -1;
pagevec_init(&pvec, 0);
index = start;
while (index < end) {
pvec.nr = find_get_entries(mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE),
pvec.pages, indices);
if (!pvec.nr)
break;
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index >= end)
break;
if (radix_tree_exceptional_entry(page)) {
if (unfalloc)
continue;
nr_swaps_freed += !shmem_free_swap(mapping,
index, page);
continue;
}
VM_BUG_ON_PAGE(page_to_pgoff(page) != index, page);
if (!trylock_page(page))
continue;
if (PageTransTail(page)) {
clear_highpage(page);
unlock_page(page);
continue;
} else if (PageTransHuge(page)) {
if (index == round_down(end, HPAGE_PMD_NR)) {
clear_highpage(page);
unlock_page(page);
continue;
}
index += HPAGE_PMD_NR - 1;
i += HPAGE_PMD_NR - 1;
}
if (!unfalloc || !PageUptodate(page)) {
VM_BUG_ON_PAGE(PageTail(page), page);
if (page_mapping(page) == mapping) {
VM_BUG_ON_PAGE(PageWriteback(page), page);
truncate_inode_page(mapping, page);
}
}
unlock_page(page);
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
cond_resched();
index++;
}
if (partial_start) {
struct page *page = NULL;
shmem_getpage(inode, start - 1, &page, SGP_READ);
if (page) {
unsigned int top = PAGE_SIZE;
if (start > end) {
top = partial_end;
partial_end = 0;
}
zero_user_segment(page, partial_start, top);
set_page_dirty(page);
unlock_page(page);
put_page(page);
}
}
if (partial_end) {
struct page *page = NULL;
shmem_getpage(inode, end, &page, SGP_READ);
if (page) {
zero_user_segment(page, 0, partial_end);
set_page_dirty(page);
unlock_page(page);
put_page(page);
}
}
if (start >= end)
return;
index = start;
while (index < end) {
cond_resched();
pvec.nr = find_get_entries(mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE),
pvec.pages, indices);
if (!pvec.nr) {
if (index == start || end != -1)
break;
index = start;
continue;
}
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index >= end)
break;
if (radix_tree_exceptional_entry(page)) {
if (unfalloc)
continue;
if (shmem_free_swap(mapping, index, page)) {
index--;
break;
}
nr_swaps_freed++;
continue;
}
lock_page(page);
if (PageTransTail(page)) {
clear_highpage(page);
unlock_page(page);
if (index != round_down(end, HPAGE_PMD_NR))
start++;
continue;
} else if (PageTransHuge(page)) {
if (index == round_down(end, HPAGE_PMD_NR)) {
clear_highpage(page);
unlock_page(page);
continue;
}
index += HPAGE_PMD_NR - 1;
i += HPAGE_PMD_NR - 1;
}
if (!unfalloc || !PageUptodate(page)) {
VM_BUG_ON_PAGE(PageTail(page), page);
if (page_mapping(page) == mapping) {
VM_BUG_ON_PAGE(PageWriteback(page), page);
truncate_inode_page(mapping, page);
} else {
unlock_page(page);
index--;
break;
}
}
unlock_page(page);
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
index++;
}
spin_lock_irq(&info->lock);
info->swapped -= nr_swaps_freed;
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
}
void shmem_truncate_range(struct inode *inode, loff_t lstart, loff_t lend)
{
shmem_undo_range(inode, lstart, lend, false);
inode->i_ctime = inode->i_mtime = current_time(inode);
}
static int shmem_getattr(const struct path *path, struct kstat *stat,
u32 request_mask, unsigned int query_flags)
{
struct inode *inode = path->dentry->d_inode;
struct shmem_inode_info *info = SHMEM_I(inode);
if (info->alloced - info->swapped != inode->i_mapping->nrpages) {
spin_lock_irq(&info->lock);
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
}
generic_fillattr(inode, stat);
return 0;
}
static int shmem_setattr(struct dentry *dentry, struct iattr *attr)
{
struct inode *inode = d_inode(dentry);
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
int error;
error = setattr_prepare(dentry, attr);
if (error)
return error;
if (S_ISREG(inode->i_mode) && (attr->ia_valid & ATTR_SIZE)) {
loff_t oldsize = inode->i_size;
loff_t newsize = attr->ia_size;
if ((newsize < oldsize && (info->seals & F_SEAL_SHRINK)) ||
(newsize > oldsize && (info->seals & F_SEAL_GROW)))
return -EPERM;
if (newsize != oldsize) {
error = shmem_reacct_size(SHMEM_I(inode)->flags,
oldsize, newsize);
if (error)
return error;
i_size_write(inode, newsize);
inode->i_ctime = inode->i_mtime = current_time(inode);
}
if (newsize <= oldsize) {
loff_t holebegin = round_up(newsize, PAGE_SIZE);
if (oldsize > holebegin)
unmap_mapping_range(inode->i_mapping,
holebegin, 0, 1);
if (info->alloced)
shmem_truncate_range(inode,
newsize, (loff_t)-1);
if (oldsize > holebegin)
unmap_mapping_range(inode->i_mapping,
holebegin, 0, 1);
if (IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE)) {
spin_lock(&sbinfo->shrinklist_lock);
if (list_empty_careful(&info->shrinklist)) {
list_add_tail(&info->shrinklist,
&sbinfo->shrinklist);
sbinfo->shrinklist_len++;
}
spin_unlock(&sbinfo->shrinklist_lock);
}
}
}
setattr_copy(inode, attr);
if (attr->ia_valid & ATTR_MODE)
error = posix_acl_chmod(inode, inode->i_mode);
return error;
}
static void shmem_evict_inode(struct inode *inode)
{
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
if (inode->i_mapping->a_ops == &shmem_aops) {
shmem_unacct_size(info->flags, inode->i_size);
inode->i_size = 0;
shmem_truncate_range(inode, 0, (loff_t)-1);
if (!list_empty(&info->shrinklist)) {
spin_lock(&sbinfo->shrinklist_lock);
if (!list_empty(&info->shrinklist)) {
list_del_init(&info->shrinklist);
sbinfo->shrinklist_len--;
}
spin_unlock(&sbinfo->shrinklist_lock);
}
if (!list_empty(&info->swaplist)) {
mutex_lock(&shmem_swaplist_mutex);
list_del_init(&info->swaplist);
mutex_unlock(&shmem_swaplist_mutex);
}
}
simple_xattrs_free(&info->xattrs);
WARN_ON(inode->i_blocks);
shmem_free_inode(inode->i_sb);
clear_inode(inode);
}
static unsigned long find_swap_entry(struct radix_tree_root *root, void *item)
{
struct radix_tree_iter iter;
void **slot;
unsigned long found = -1;
unsigned int checked = 0;
rcu_read_lock();
radix_tree_for_each_slot(slot, root, &iter, 0) {
if (*slot == item) {
found = iter.index;
break;
}
checked++;
if ((checked % 4096) != 0)
continue;
slot = radix_tree_iter_resume(slot, &iter);
cond_resched_rcu();
}
rcu_read_unlock();
return found;
}
static int shmem_unuse_inode(struct shmem_inode_info *info,
swp_entry_t swap, struct page **pagep)
{
struct address_space *mapping = info->vfs_inode.i_mapping;
void *radswap;
pgoff_t index;
gfp_t gfp;
int error = 0;
radswap = swp_to_radix_entry(swap);
index = find_swap_entry(&mapping->page_tree, radswap);
if (index == -1)
return -EAGAIN;
if (shmem_swaplist.next != &info->swaplist)
list_move_tail(&shmem_swaplist, &info->swaplist);
gfp = mapping_gfp_mask(mapping);
if (shmem_should_replace_page(*pagep, gfp)) {
mutex_unlock(&shmem_swaplist_mutex);
error = shmem_replace_page(pagep, gfp, info, index);
mutex_lock(&shmem_swaplist_mutex);
if (!page_swapcount(*pagep))
error = -ENOENT;
}
if (!error)
error = shmem_add_to_page_cache(*pagep, mapping, index,
radswap);
if (error != -ENOMEM) {
delete_from_swap_cache(*pagep);
set_page_dirty(*pagep);
if (!error) {
spin_lock_irq(&info->lock);
info->swapped--;
spin_unlock_irq(&info->lock);
swap_free(swap);
}
}
return error;
}
int shmem_unuse(swp_entry_t swap, struct page *page)
{
struct list_head *this, *next;
struct shmem_inode_info *info;
struct mem_cgroup *memcg;
int error = 0;
if (unlikely(!PageSwapCache(page) || page_private(page) != swap.val))
goto out;
error = mem_cgroup_try_charge(page, current->mm, GFP_KERNEL, &memcg,
false);
if (error)
goto out;
error = -EAGAIN;
mutex_lock(&shmem_swaplist_mutex);
list_for_each_safe(this, next, &shmem_swaplist) {
info = list_entry(this, struct shmem_inode_info, swaplist);
if (info->swapped)
error = shmem_unuse_inode(info, swap, &page);
else
list_del_init(&info->swaplist);
cond_resched();
if (error != -EAGAIN)
break;
}
mutex_unlock(&shmem_swaplist_mutex);
if (error) {
if (error != -ENOMEM)
error = 0;
mem_cgroup_cancel_charge(page, memcg, false);
} else
mem_cgroup_commit_charge(page, memcg, true, false);
out:
unlock_page(page);
put_page(page);
return error;
}
static int shmem_writepage(struct page *page, struct writeback_control *wbc)
{
struct shmem_inode_info *info;
struct address_space *mapping;
struct inode *inode;
swp_entry_t swap;
pgoff_t index;
VM_BUG_ON_PAGE(PageCompound(page), page);
BUG_ON(!PageLocked(page));
mapping = page->mapping;
index = page->index;
inode = mapping->host;
info = SHMEM_I(inode);
if (info->flags & VM_LOCKED)
goto redirty;
if (!total_swap_pages)
goto redirty;
if (!wbc->for_reclaim) {
WARN_ON_ONCE(1);
goto redirty;
}
if (!PageUptodate(page)) {
if (inode->i_private) {
struct shmem_falloc *shmem_falloc;
spin_lock(&inode->i_lock);
shmem_falloc = inode->i_private;
if (shmem_falloc &&
!shmem_falloc->waitq &&
index >= shmem_falloc->start &&
index < shmem_falloc->next)
shmem_falloc->nr_unswapped++;
else
shmem_falloc = NULL;
spin_unlock(&inode->i_lock);
if (shmem_falloc)
goto redirty;
}
clear_highpage(page);
flush_dcache_page(page);
SetPageUptodate(page);
}
swap = get_swap_page(page);
if (!swap.val)
goto redirty;
if (mem_cgroup_try_charge_swap(page, swap))
goto free_swap;
mutex_lock(&shmem_swaplist_mutex);
if (list_empty(&info->swaplist))
list_add_tail(&info->swaplist, &shmem_swaplist);
if (add_to_swap_cache(page, swap, GFP_ATOMIC) == 0) {
spin_lock_irq(&info->lock);
shmem_recalc_inode(inode);
info->swapped++;
spin_unlock_irq(&info->lock);
swap_shmem_alloc(swap);
shmem_delete_from_page_cache(page, swp_to_radix_entry(swap));
mutex_unlock(&shmem_swaplist_mutex);
BUG_ON(page_mapped(page));
swap_writepage(page, wbc);
return 0;
}
mutex_unlock(&shmem_swaplist_mutex);
free_swap:
put_swap_page(page, swap);
redirty:
set_page_dirty(page);
if (wbc->for_reclaim)
return AOP_WRITEPAGE_ACTIVATE;
unlock_page(page);
return 0;
}
static void shmem_show_mpol(struct seq_file *seq, struct mempolicy *mpol)
{
char buffer[64];
if (!mpol || mpol->mode == MPOL_DEFAULT)
return;
mpol_to_str(buffer, sizeof(buffer), mpol);
seq_printf(seq, ",mpol=%s", buffer);
}
static struct mempolicy *shmem_get_sbmpol(struct shmem_sb_info *sbinfo)
{
struct mempolicy *mpol = NULL;
if (sbinfo->mpol) {
spin_lock(&sbinfo->stat_lock);
mpol = sbinfo->mpol;
mpol_get(mpol);
spin_unlock(&sbinfo->stat_lock);
}
return mpol;
}
static inline void shmem_show_mpol(struct seq_file *seq, struct mempolicy *mpol)
{
}
static inline struct mempolicy *shmem_get_sbmpol(struct shmem_sb_info *sbinfo)
{
return NULL;
}
static void shmem_pseudo_vma_init(struct vm_area_struct *vma,
struct shmem_inode_info *info, pgoff_t index)
{
vma->vm_start = 0;
vma->vm_pgoff = index + info->vfs_inode.i_ino;
vma->vm_ops = NULL;
vma->vm_policy = mpol_shared_policy_lookup(&info->policy, index);
}
static void shmem_pseudo_vma_destroy(struct vm_area_struct *vma)
{
mpol_cond_put(vma->vm_policy);
}
static struct page *shmem_swapin(swp_entry_t swap, gfp_t gfp,
struct shmem_inode_info *info, pgoff_t index)
{
struct vm_area_struct pvma;
struct page *page;
shmem_pseudo_vma_init(&pvma, info, index);
page = swapin_readahead(swap, gfp, &pvma, 0);
shmem_pseudo_vma_destroy(&pvma);
return page;
}
static struct page *shmem_alloc_hugepage(gfp_t gfp,
struct shmem_inode_info *info, pgoff_t index)
{
struct vm_area_struct pvma;
struct inode *inode = &info->vfs_inode;
struct address_space *mapping = inode->i_mapping;
pgoff_t idx, hindex;
void __rcu **results;
struct page *page;
if (!IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE))
return NULL;
hindex = round_down(index, HPAGE_PMD_NR);
rcu_read_lock();
if (radix_tree_gang_lookup_slot(&mapping->page_tree, &results, &idx,
hindex, 1) && idx < hindex + HPAGE_PMD_NR) {
rcu_read_unlock();
return NULL;
}
rcu_read_unlock();
shmem_pseudo_vma_init(&pvma, info, hindex);
page = alloc_pages_vma(gfp | __GFP_COMP | __GFP_NORETRY | __GFP_NOWARN,
HPAGE_PMD_ORDER, &pvma, 0, numa_node_id(), true);
shmem_pseudo_vma_destroy(&pvma);
if (page)
prep_transhuge_page(page);
return page;
}
static struct page *shmem_alloc_page(gfp_t gfp,
struct shmem_inode_info *info, pgoff_t index)
{
struct vm_area_struct pvma;
struct page *page;
shmem_pseudo_vma_init(&pvma, info, index);
page = alloc_page_vma(gfp, &pvma, 0);
shmem_pseudo_vma_destroy(&pvma);
return page;
}
static struct page *shmem_alloc_and_acct_page(gfp_t gfp,
struct inode *inode,
pgoff_t index, bool huge)
{
struct shmem_inode_info *info = SHMEM_I(inode);
struct page *page;
int nr;
int err = -ENOSPC;
if (!IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE))
huge = false;
nr = huge ? HPAGE_PMD_NR : 1;
if (!shmem_inode_acct_block(inode, nr))
goto failed;
if (huge)
page = shmem_alloc_hugepage(gfp, info, index);
else
page = shmem_alloc_page(gfp, info, index);
if (page) {
__SetPageLocked(page);
__SetPageSwapBacked(page);
return page;
}
err = -ENOMEM;
shmem_inode_unacct_blocks(inode, nr);
failed:
return ERR_PTR(err);
}
static bool shmem_should_replace_page(struct page *page, gfp_t gfp)
{
return page_zonenum(page) > gfp_zone(gfp);
}
static int shmem_replace_page(struct page **pagep, gfp_t gfp,
struct shmem_inode_info *info, pgoff_t index)
{
struct page *oldpage, *newpage;
struct address_space *swap_mapping;
pgoff_t swap_index;
int error;
oldpage = *pagep;
swap_index = page_private(oldpage);
swap_mapping = page_mapping(oldpage);
gfp &= ~GFP_CONSTRAINT_MASK;
newpage = shmem_alloc_page(gfp, info, index);
if (!newpage)
return -ENOMEM;
get_page(newpage);
copy_highpage(newpage, oldpage);
flush_dcache_page(newpage);
__SetPageLocked(newpage);
__SetPageSwapBacked(newpage);
SetPageUptodate(newpage);
set_page_private(newpage, swap_index);
SetPageSwapCache(newpage);
spin_lock_irq(&swap_mapping->tree_lock);
error = shmem_radix_tree_replace(swap_mapping, swap_index, oldpage,
newpage);
if (!error) {
__inc_node_page_state(newpage, NR_FILE_PAGES);
__dec_node_page_state(oldpage, NR_FILE_PAGES);
}
spin_unlock_irq(&swap_mapping->tree_lock);
if (unlikely(error)) {
oldpage = newpage;
} else {
mem_cgroup_migrate(oldpage, newpage);
lru_cache_add_anon(newpage);
*pagep = newpage;
}
ClearPageSwapCache(oldpage);
set_page_private(oldpage, 0);
unlock_page(oldpage);
put_page(oldpage);
put_page(oldpage);
return error;
}
static int shmem_getpage_gfp(struct inode *inode, pgoff_t index,
struct page **pagep, enum sgp_type sgp, gfp_t gfp,
struct vm_area_struct *vma, struct vm_fault *vmf, int *fault_type)
{
struct address_space *mapping = inode->i_mapping;
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_sb_info *sbinfo;
struct mm_struct *charge_mm;
struct mem_cgroup *memcg;
struct page *page;
swp_entry_t swap;
enum sgp_type sgp_huge = sgp;
pgoff_t hindex = index;
int error;
int once = 0;
int alloced = 0;
if (index > (MAX_LFS_FILESIZE >> PAGE_SHIFT))
return -EFBIG;
if (sgp == SGP_NOHUGE || sgp == SGP_HUGE)
sgp = SGP_CACHE;
repeat:
swap.val = 0;
page = find_lock_entry(mapping, index);
if (radix_tree_exceptional_entry(page)) {
swap = radix_to_swp_entry(page);
page = NULL;
}
if (sgp <= SGP_CACHE &&
((loff_t)index << PAGE_SHIFT) >= i_size_read(inode)) {
error = -EINVAL;
goto unlock;
}
if (page && sgp == SGP_WRITE)
mark_page_accessed(page);
if (page && !PageUptodate(page)) {
if (sgp != SGP_READ)
goto clear;
unlock_page(page);
put_page(page);
page = NULL;
}
if (page || (sgp == SGP_READ && !swap.val)) {
*pagep = page;
return 0;
}
sbinfo = SHMEM_SB(inode->i_sb);
charge_mm = vma ? vma->vm_mm : current->mm;
if (swap.val) {
page = lookup_swap_cache(swap, NULL, 0);
if (!page) {
if (fault_type) {
*fault_type |= VM_FAULT_MAJOR;
count_vm_event(PGMAJFAULT);
count_memcg_event_mm(charge_mm, PGMAJFAULT);
}
page = shmem_swapin(swap, gfp, info, index);
if (!page) {
error = -ENOMEM;
goto failed;
}
}
lock_page(page);
if (!PageSwapCache(page) || page_private(page) != swap.val ||
!shmem_confirm_swap(mapping, index, swap)) {
error = -EEXIST;
goto unlock;
}
if (!PageUptodate(page)) {
error = -EIO;
goto failed;
}
wait_on_page_writeback(page);
if (shmem_should_replace_page(page, gfp)) {
error = shmem_replace_page(&page, gfp, info, index);
if (error)
goto failed;
}
error = mem_cgroup_try_charge(page, charge_mm, gfp, &memcg,
false);
if (!error) {
error = shmem_add_to_page_cache(page, mapping, index,
swp_to_radix_entry(swap));
if (error) {
mem_cgroup_cancel_charge(page, memcg, false);
delete_from_swap_cache(page);
}
}
if (error)
goto failed;
mem_cgroup_commit_charge(page, memcg, true, false);
spin_lock_irq(&info->lock);
info->swapped--;
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
if (sgp == SGP_WRITE)
mark_page_accessed(page);
delete_from_swap_cache(page);
set_page_dirty(page);
swap_free(swap);
} else {
if (vma && userfaultfd_missing(vma)) {
*fault_type = handle_userfault(vmf, VM_UFFD_MISSING);
return 0;
}
if (mapping->a_ops != &shmem_aops)
goto alloc_nohuge;
if (shmem_huge == SHMEM_HUGE_DENY || sgp_huge == SGP_NOHUGE)
goto alloc_nohuge;
if (shmem_huge == SHMEM_HUGE_FORCE)
goto alloc_huge;
switch (sbinfo->huge) {
loff_t i_size;
pgoff_t off;
case SHMEM_HUGE_NEVER:
goto alloc_nohuge;
case SHMEM_HUGE_WITHIN_SIZE:
off = round_up(index, HPAGE_PMD_NR);
i_size = round_up(i_size_read(inode), PAGE_SIZE);
if (i_size >= HPAGE_PMD_SIZE &&
i_size >> PAGE_SHIFT >= off)
goto alloc_huge;
case SHMEM_HUGE_ADVISE:
if (sgp_huge == SGP_HUGE)
goto alloc_huge;
goto alloc_nohuge;
}
alloc_huge:
page = shmem_alloc_and_acct_page(gfp, inode, index, true);
if (IS_ERR(page)) {
alloc_nohuge: page = shmem_alloc_and_acct_page(gfp, inode,
index, false);
}
if (IS_ERR(page)) {
int retry = 5;
error = PTR_ERR(page);
page = NULL;
if (error != -ENOSPC)
goto failed;
while (retry--) {
int ret;
ret = shmem_unused_huge_shrink(sbinfo, NULL, 1);
if (ret == SHRINK_STOP)
break;
if (ret)
goto alloc_nohuge;
}
goto failed;
}
if (PageTransHuge(page))
hindex = round_down(index, HPAGE_PMD_NR);
else
hindex = index;
if (sgp == SGP_WRITE)
__SetPageReferenced(page);
error = mem_cgroup_try_charge(page, charge_mm, gfp, &memcg,
PageTransHuge(page));
if (error)
goto unacct;
error = radix_tree_maybe_preload_order(gfp & GFP_RECLAIM_MASK,
compound_order(page));
if (!error) {
error = shmem_add_to_page_cache(page, mapping, hindex,
NULL);
radix_tree_preload_end();
}
if (error) {
mem_cgroup_cancel_charge(page, memcg,
PageTransHuge(page));
goto unacct;
}
mem_cgroup_commit_charge(page, memcg, false,
PageTransHuge(page));
lru_cache_add_anon(page);
spin_lock_irq(&info->lock);
info->alloced += 1 << compound_order(page);
inode->i_blocks += BLOCKS_PER_PAGE << compound_order(page);
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
alloced = true;
if (PageTransHuge(page) &&
DIV_ROUND_UP(i_size_read(inode), PAGE_SIZE) <
hindex + HPAGE_PMD_NR - 1) {
spin_lock(&sbinfo->shrinklist_lock);
if (list_empty_careful(&info->shrinklist)) {
list_add_tail(&info->shrinklist,
&sbinfo->shrinklist);
sbinfo->shrinklist_len++;
}
spin_unlock(&sbinfo->shrinklist_lock);
}
if (sgp == SGP_FALLOC)
sgp = SGP_WRITE;
clear:
if (sgp != SGP_WRITE && !PageUptodate(page)) {
struct page *head = compound_head(page);
int i;
for (i = 0; i < (1 << compound_order(head)); i++) {
clear_highpage(head + i);
flush_dcache_page(head + i);
}
SetPageUptodate(head);
}
}
if (sgp <= SGP_CACHE &&
((loff_t)index << PAGE_SHIFT) >= i_size_read(inode)) {
if (alloced) {
ClearPageDirty(page);
delete_from_page_cache(page);
spin_lock_irq(&info->lock);
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
}
error = -EINVAL;
goto unlock;
}
*pagep = page + index - hindex;
return 0;
unacct:
shmem_inode_unacct_blocks(inode, 1 << compound_order(page));
if (PageTransHuge(page)) {
unlock_page(page);
put_page(page);
goto alloc_nohuge;
}
failed:
if (swap.val && !shmem_confirm_swap(mapping, index, swap))
error = -EEXIST;
unlock:
if (page) {
unlock_page(page);
put_page(page);
}
if (error == -ENOSPC && !once++) {
spin_lock_irq(&info->lock);
shmem_recalc_inode(inode);
spin_unlock_irq(&info->lock);
goto repeat;
}
if (error == -EEXIST)
goto repeat;
return error;
}
static int synchronous_wake_function(wait_queue_entry_t *wait, unsigned mode, int sync, void *key)
{
int ret = default_wake_function(wait, mode, sync, key);
list_del_init(&wait->entry);
return ret;
}
static int shmem_fault(struct vm_fault *vmf)
{
struct vm_area_struct *vma = vmf->vma;
struct inode *inode = file_inode(vma->vm_file);
gfp_t gfp = mapping_gfp_mask(inode->i_mapping);
enum sgp_type sgp;
int error;
int ret = VM_FAULT_LOCKED;
if (unlikely(inode->i_private)) {
struct shmem_falloc *shmem_falloc;
spin_lock(&inode->i_lock);
shmem_falloc = inode->i_private;
if (shmem_falloc &&
shmem_falloc->waitq &&
vmf->pgoff >= shmem_falloc->start &&
vmf->pgoff < shmem_falloc->next) {
wait_queue_head_t *shmem_falloc_waitq;
DEFINE_WAIT_FUNC(shmem_fault_wait, synchronous_wake_function);
ret = VM_FAULT_NOPAGE;
if ((vmf->flags & FAULT_FLAG_ALLOW_RETRY) &&
!(vmf->flags & FAULT_FLAG_RETRY_NOWAIT)) {
up_read(&vma->vm_mm->mmap_sem);
ret = VM_FAULT_RETRY;
}
shmem_falloc_waitq = shmem_falloc->waitq;
prepare_to_wait(shmem_falloc_waitq, &shmem_fault_wait,
TASK_UNINTERRUPTIBLE);
spin_unlock(&inode->i_lock);
schedule();
spin_lock(&inode->i_lock);
finish_wait(shmem_falloc_waitq, &shmem_fault_wait);
spin_unlock(&inode->i_lock);
return ret;
}
spin_unlock(&inode->i_lock);
}
sgp = SGP_CACHE;
if ((vma->vm_flags & VM_NOHUGEPAGE) ||
test_bit(MMF_DISABLE_THP, &vma->vm_mm->flags))
sgp = SGP_NOHUGE;
else if (vma->vm_flags & VM_HUGEPAGE)
sgp = SGP_HUGE;
error = shmem_getpage_gfp(inode, vmf->pgoff, &vmf->page, sgp,
gfp, vma, vmf, &ret);
if (error)
return ((error == -ENOMEM) ? VM_FAULT_OOM : VM_FAULT_SIGBUS);
return ret;
}
unsigned long shmem_get_unmapped_area(struct file *file,
unsigned long uaddr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
unsigned long (*get_area)(struct file *,
unsigned long, unsigned long, unsigned long, unsigned long);
unsigned long addr;
unsigned long offset;
unsigned long inflated_len;
unsigned long inflated_addr;
unsigned long inflated_offset;
if (len > TASK_SIZE)
return -ENOMEM;
get_area = current->mm->get_unmapped_area;
addr = get_area(file, uaddr, len, pgoff, flags);
if (!IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE))
return addr;
if (IS_ERR_VALUE(addr))
return addr;
if (addr & ~PAGE_MASK)
return addr;
if (addr > TASK_SIZE - len)
return addr;
if (shmem_huge == SHMEM_HUGE_DENY)
return addr;
if (len < HPAGE_PMD_SIZE)
return addr;
if (flags & MAP_FIXED)
return addr;
if (uaddr)
return addr;
if (shmem_huge != SHMEM_HUGE_FORCE) {
struct super_block *sb;
if (file) {
VM_BUG_ON(file->f_op != &shmem_file_operations);
sb = file_inode(file)->i_sb;
} else {
if (IS_ERR(shm_mnt))
return addr;
sb = shm_mnt->mnt_sb;
}
if (SHMEM_SB(sb)->huge == SHMEM_HUGE_NEVER)
return addr;
}
offset = (pgoff << PAGE_SHIFT) & (HPAGE_PMD_SIZE-1);
if (offset && offset + len < 2 * HPAGE_PMD_SIZE)
return addr;
if ((addr & (HPAGE_PMD_SIZE-1)) == offset)
return addr;
inflated_len = len + HPAGE_PMD_SIZE - PAGE_SIZE;
if (inflated_len > TASK_SIZE)
return addr;
if (inflated_len < len)
return addr;
inflated_addr = get_area(NULL, 0, inflated_len, 0, flags);
if (IS_ERR_VALUE(inflated_addr))
return addr;
if (inflated_addr & ~PAGE_MASK)
return addr;
inflated_offset = inflated_addr & (HPAGE_PMD_SIZE-1);
inflated_addr += offset - inflated_offset;
if (inflated_offset > offset)
inflated_addr += HPAGE_PMD_SIZE;
if (inflated_addr > TASK_SIZE - len)
return addr;
return inflated_addr;
}
static int shmem_set_policy(struct vm_area_struct *vma, struct mempolicy *mpol)
{
struct inode *inode = file_inode(vma->vm_file);
return mpol_set_shared_policy(&SHMEM_I(inode)->policy, vma, mpol);
}
static struct mempolicy *shmem_get_policy(struct vm_area_struct *vma,
unsigned long addr)
{
struct inode *inode = file_inode(vma->vm_file);
pgoff_t index;
index = ((addr - vma->vm_start) >> PAGE_SHIFT) + vma->vm_pgoff;
return mpol_shared_policy_lookup(&SHMEM_I(inode)->policy, index);
}
int shmem_lock(struct file *file, int lock, struct user_struct *user)
{
struct inode *inode = file_inode(file);
struct shmem_inode_info *info = SHMEM_I(inode);
int retval = -ENOMEM;
spin_lock_irq(&info->lock);
if (lock && !(info->flags & VM_LOCKED)) {
if (!user_shm_lock(inode->i_size, user))
goto out_nomem;
info->flags |= VM_LOCKED;
mapping_set_unevictable(file->f_mapping);
}
if (!lock && (info->flags & VM_LOCKED) && user) {
user_shm_unlock(inode->i_size, user);
info->flags &= ~VM_LOCKED;
mapping_clear_unevictable(file->f_mapping);
}
retval = 0;
out_nomem:
spin_unlock_irq(&info->lock);
return retval;
}
static int shmem_mmap(struct file *file, struct vm_area_struct *vma)
{
file_accessed(file);
vma->vm_ops = &shmem_vm_ops;
if (IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE) &&
((vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK) <
(vma->vm_end & HPAGE_PMD_MASK)) {
khugepaged_enter(vma, vma->vm_flags);
}
return 0;
}
static struct inode *shmem_get_inode(struct super_block *sb, const struct inode *dir,
umode_t mode, dev_t dev, unsigned long flags)
{
struct inode *inode;
struct shmem_inode_info *info;
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
if (shmem_reserve_inode(sb))
return NULL;
inode = new_inode(sb);
if (inode) {
inode->i_ino = get_next_ino();
inode_init_owner(inode, dir, mode);
inode->i_blocks = 0;
inode->i_atime = inode->i_mtime = inode->i_ctime = current_time(inode);
inode->i_generation = get_seconds();
info = SHMEM_I(inode);
memset(info, 0, (char *)inode - (char *)info);
spin_lock_init(&info->lock);
info->seals = F_SEAL_SEAL;
info->flags = flags & VM_NORESERVE;
INIT_LIST_HEAD(&info->shrinklist);
INIT_LIST_HEAD(&info->swaplist);
simple_xattrs_init(&info->xattrs);
cache_no_acl(inode);
switch (mode & S_IFMT) {
default:
inode->i_op = &shmem_special_inode_operations;
init_special_inode(inode, mode, dev);
break;
case S_IFREG:
inode->i_mapping->a_ops = &shmem_aops;
inode->i_op = &shmem_inode_operations;
inode->i_fop = &shmem_file_operations;
mpol_shared_policy_init(&info->policy,
shmem_get_sbmpol(sbinfo));
break;
case S_IFDIR:
inc_nlink(inode);
inode->i_size = 2 * BOGO_DIRENT_SIZE;
inode->i_op = &shmem_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
break;
case S_IFLNK:
mpol_shared_policy_init(&info->policy, NULL);
break;
}
} else
shmem_free_inode(sb);
return inode;
}
bool shmem_mapping(struct address_space *mapping)
{
return mapping->a_ops == &shmem_aops;
}
static int shmem_mfill_atomic_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr,
unsigned long src_addr,
bool zeropage,
struct page **pagep)
{
struct inode *inode = file_inode(dst_vma->vm_file);
struct shmem_inode_info *info = SHMEM_I(inode);
struct address_space *mapping = inode->i_mapping;
gfp_t gfp = mapping_gfp_mask(mapping);
pgoff_t pgoff = linear_page_index(dst_vma, dst_addr);
struct mem_cgroup *memcg;
spinlock_t *ptl;
void *page_kaddr;
struct page *page;
pte_t _dst_pte, *dst_pte;
int ret;
ret = -ENOMEM;
if (!shmem_inode_acct_block(inode, 1))
goto out;
if (!*pagep) {
page = shmem_alloc_page(gfp, info, pgoff);
if (!page)
goto out_unacct_blocks;
if (!zeropage) {
page_kaddr = kmap_atomic(page);
ret = copy_from_user(page_kaddr,
(const void __user *)src_addr,
PAGE_SIZE);
kunmap_atomic(page_kaddr);
if (unlikely(ret)) {
*pagep = page;
shmem_inode_unacct_blocks(inode, 1);
return -EFAULT;
}
} else {
clear_highpage(page);
}
} else {
page = *pagep;
*pagep = NULL;
}
VM_BUG_ON(PageLocked(page) || PageSwapBacked(page));
__SetPageLocked(page);
__SetPageSwapBacked(page);
__SetPageUptodate(page);
ret = mem_cgroup_try_charge(page, dst_mm, gfp, &memcg, false);
if (ret)
goto out_release;
ret = radix_tree_maybe_preload(gfp & GFP_RECLAIM_MASK);
if (!ret) {
ret = shmem_add_to_page_cache(page, mapping, pgoff, NULL);
radix_tree_preload_end();
}
if (ret)
goto out_release_uncharge;
mem_cgroup_commit_charge(page, memcg, false, false);
_dst_pte = mk_pte(page, dst_vma->vm_page_prot);
if (dst_vma->vm_flags & VM_WRITE)
_dst_pte = pte_mkwrite(pte_mkdirty(_dst_pte));
ret = -EEXIST;
dst_pte = pte_offset_map_lock(dst_mm, dst_pmd, dst_addr, &ptl);
if (!pte_none(*dst_pte))
goto out_release_uncharge_unlock;
lru_cache_add_anon(page);
spin_lock(&info->lock);
info->alloced++;
inode->i_blocks += BLOCKS_PER_PAGE;
shmem_recalc_inode(inode);
spin_unlock(&info->lock);
inc_mm_counter(dst_mm, mm_counter_file(page));
page_add_file_rmap(page, false);
set_pte_at(dst_mm, dst_addr, dst_pte, _dst_pte);
update_mmu_cache(dst_vma, dst_addr, dst_pte);
unlock_page(page);
pte_unmap_unlock(dst_pte, ptl);
ret = 0;
out:
return ret;
out_release_uncharge_unlock:
pte_unmap_unlock(dst_pte, ptl);
out_release_uncharge:
mem_cgroup_cancel_charge(page, memcg, false);
out_release:
unlock_page(page);
put_page(page);
out_unacct_blocks:
shmem_inode_unacct_blocks(inode, 1);
goto out;
}
int shmem_mcopy_atomic_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr,
unsigned long src_addr,
struct page **pagep)
{
return shmem_mfill_atomic_pte(dst_mm, dst_pmd, dst_vma,
dst_addr, src_addr, false, pagep);
}
int shmem_mfill_zeropage_pte(struct mm_struct *dst_mm,
pmd_t *dst_pmd,
struct vm_area_struct *dst_vma,
unsigned long dst_addr)
{
struct page *page = NULL;
return shmem_mfill_atomic_pte(dst_mm, dst_pmd, dst_vma,
dst_addr, 0, true, &page);
}
static int
shmem_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
struct inode *inode = mapping->host;
struct shmem_inode_info *info = SHMEM_I(inode);
pgoff_t index = pos >> PAGE_SHIFT;
if (unlikely(info->seals & (F_SEAL_WRITE | F_SEAL_GROW))) {
if (info->seals & F_SEAL_WRITE)
return -EPERM;
if ((info->seals & F_SEAL_GROW) && pos + len > inode->i_size)
return -EPERM;
}
return shmem_getpage(inode, index, pagep, SGP_WRITE);
}
static int
shmem_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
struct inode *inode = mapping->host;
if (pos + copied > inode->i_size)
i_size_write(inode, pos + copied);
if (!PageUptodate(page)) {
struct page *head = compound_head(page);
if (PageTransCompound(page)) {
int i;
for (i = 0; i < HPAGE_PMD_NR; i++) {
if (head + i == page)
continue;
clear_highpage(head + i);
flush_dcache_page(head + i);
}
}
if (copied < PAGE_SIZE) {
unsigned from = pos & (PAGE_SIZE - 1);
zero_user_segments(page, 0, from,
from + copied, PAGE_SIZE);
}
SetPageUptodate(head);
}
set_page_dirty(page);
unlock_page(page);
put_page(page);
return copied;
}
static ssize_t shmem_file_read_iter(struct kiocb *iocb, struct iov_iter *to)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file_inode(file);
struct address_space *mapping = inode->i_mapping;
pgoff_t index;
unsigned long offset;
enum sgp_type sgp = SGP_READ;
int error = 0;
ssize_t retval = 0;
loff_t *ppos = &iocb->ki_pos;
if (!iter_is_iovec(to))
sgp = SGP_CACHE;
index = *ppos >> PAGE_SHIFT;
offset = *ppos & ~PAGE_MASK;
for (;;) {
struct page *page = NULL;
pgoff_t end_index;
unsigned long nr, ret;
loff_t i_size = i_size_read(inode);
end_index = i_size >> PAGE_SHIFT;
if (index > end_index)
break;
if (index == end_index) {
nr = i_size & ~PAGE_MASK;
if (nr <= offset)
break;
}
error = shmem_getpage(inode, index, &page, sgp);
if (error) {
if (error == -EINVAL)
error = 0;
break;
}
if (page) {
if (sgp == SGP_CACHE)
set_page_dirty(page);
unlock_page(page);
}
nr = PAGE_SIZE;
i_size = i_size_read(inode);
end_index = i_size >> PAGE_SHIFT;
if (index == end_index) {
nr = i_size & ~PAGE_MASK;
if (nr <= offset) {
if (page)
put_page(page);
break;
}
}
nr -= offset;
if (page) {
if (mapping_writably_mapped(mapping))
flush_dcache_page(page);
if (!offset)
mark_page_accessed(page);
} else {
page = ZERO_PAGE(0);
get_page(page);
}
ret = copy_page_to_iter(page, offset, nr, to);
retval += ret;
offset += ret;
index += offset >> PAGE_SHIFT;
offset &= ~PAGE_MASK;
put_page(page);
if (!iov_iter_count(to))
break;
if (ret < nr) {
error = -EFAULT;
break;
}
cond_resched();
}
*ppos = ((loff_t) index << PAGE_SHIFT) + offset;
file_accessed(file);
return retval ? retval : error;
}
static pgoff_t shmem_seek_hole_data(struct address_space *mapping,
pgoff_t index, pgoff_t end, int whence)
{
struct page *page;
struct pagevec pvec;
pgoff_t indices[PAGEVEC_SIZE];
bool done = false;
int i;
pagevec_init(&pvec, 0);
pvec.nr = 1;
while (!done) {
pvec.nr = find_get_entries(mapping, index,
pvec.nr, pvec.pages, indices);
if (!pvec.nr) {
if (whence == SEEK_DATA)
index = end;
break;
}
for (i = 0; i < pvec.nr; i++, index++) {
if (index < indices[i]) {
if (whence == SEEK_HOLE) {
done = true;
break;
}
index = indices[i];
}
page = pvec.pages[i];
if (page && !radix_tree_exceptional_entry(page)) {
if (!PageUptodate(page))
page = NULL;
}
if (index >= end ||
(page && whence == SEEK_DATA) ||
(!page && whence == SEEK_HOLE)) {
done = true;
break;
}
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
pvec.nr = PAGEVEC_SIZE;
cond_resched();
}
return index;
}
static loff_t shmem_file_llseek(struct file *file, loff_t offset, int whence)
{
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
pgoff_t start, end;
loff_t new_offset;
if (whence != SEEK_DATA && whence != SEEK_HOLE)
return generic_file_llseek_size(file, offset, whence,
MAX_LFS_FILESIZE, i_size_read(inode));
inode_lock(inode);
if (offset < 0)
offset = -EINVAL;
else if (offset >= inode->i_size)
offset = -ENXIO;
else {
start = offset >> PAGE_SHIFT;
end = (inode->i_size + PAGE_SIZE - 1) >> PAGE_SHIFT;
new_offset = shmem_seek_hole_data(mapping, start, end, whence);
new_offset <<= PAGE_SHIFT;
if (new_offset > offset) {
if (new_offset < inode->i_size)
offset = new_offset;
else if (whence == SEEK_DATA)
offset = -ENXIO;
else
offset = inode->i_size;
}
}
if (offset >= 0)
offset = vfs_setpos(file, offset, MAX_LFS_FILESIZE);
inode_unlock(inode);
return offset;
}
static void shmem_tag_pins(struct address_space *mapping)
{
struct radix_tree_iter iter;
void **slot;
pgoff_t start;
struct page *page;
lru_add_drain();
start = 0;
rcu_read_lock();
radix_tree_for_each_slot(slot, &mapping->page_tree, &iter, start) {
page = radix_tree_deref_slot(slot);
if (!page || radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
} else if (page_count(page) - page_mapcount(page) > 1) {
spin_lock_irq(&mapping->tree_lock);
radix_tree_tag_set(&mapping->page_tree, iter.index,
SHMEM_TAG_PINNED);
spin_unlock_irq(&mapping->tree_lock);
}
if (need_resched()) {
slot = radix_tree_iter_resume(slot, &iter);
cond_resched_rcu();
}
}
rcu_read_unlock();
}
static int shmem_wait_for_pins(struct address_space *mapping)
{
struct radix_tree_iter iter;
void **slot;
pgoff_t start;
struct page *page;
int error, scan;
shmem_tag_pins(mapping);
error = 0;
for (scan = 0; scan <= LAST_SCAN; scan++) {
if (!radix_tree_tagged(&mapping->page_tree, SHMEM_TAG_PINNED))
break;
if (!scan)
lru_add_drain_all();
else if (schedule_timeout_killable((HZ << scan) / 200))
scan = LAST_SCAN;
start = 0;
rcu_read_lock();
radix_tree_for_each_tagged(slot, &mapping->page_tree, &iter,
start, SHMEM_TAG_PINNED) {
page = radix_tree_deref_slot(slot);
if (radix_tree_exception(page)) {
if (radix_tree_deref_retry(page)) {
slot = radix_tree_iter_retry(&iter);
continue;
}
page = NULL;
}
if (page &&
page_count(page) - page_mapcount(page) != 1) {
if (scan < LAST_SCAN)
goto continue_resched;
error = -EBUSY;
}
spin_lock_irq(&mapping->tree_lock);
radix_tree_tag_clear(&mapping->page_tree,
iter.index, SHMEM_TAG_PINNED);
spin_unlock_irq(&mapping->tree_lock);
continue_resched:
if (need_resched()) {
slot = radix_tree_iter_resume(slot, &iter);
cond_resched_rcu();
}
}
rcu_read_unlock();
}
return error;
}
int shmem_add_seals(struct file *file, unsigned int seals)
{
struct inode *inode = file_inode(file);
struct shmem_inode_info *info = SHMEM_I(inode);
int error;
if (file->f_op != &shmem_file_operations)
return -EINVAL;
if (!(file->f_mode & FMODE_WRITE))
return -EPERM;
if (seals & ~(unsigned int)F_ALL_SEALS)
return -EINVAL;
inode_lock(inode);
if (info->seals & F_SEAL_SEAL) {
error = -EPERM;
goto unlock;
}
if ((seals & F_SEAL_WRITE) && !(info->seals & F_SEAL_WRITE)) {
error = mapping_deny_writable(file->f_mapping);
if (error)
goto unlock;
error = shmem_wait_for_pins(file->f_mapping);
if (error) {
mapping_allow_writable(file->f_mapping);
goto unlock;
}
}
info->seals |= seals;
error = 0;
unlock:
inode_unlock(inode);
return error;
}
int shmem_get_seals(struct file *file)
{
if (file->f_op != &shmem_file_operations)
return -EINVAL;
return SHMEM_I(file_inode(file))->seals;
}
long shmem_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
long error;
switch (cmd) {
case F_ADD_SEALS:
if (arg > UINT_MAX)
return -EINVAL;
error = shmem_add_seals(file, arg);
break;
case F_GET_SEALS:
error = shmem_get_seals(file);
break;
default:
error = -EINVAL;
break;
}
return error;
}
static long shmem_fallocate(struct file *file, int mode, loff_t offset,
loff_t len)
{
struct inode *inode = file_inode(file);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
struct shmem_inode_info *info = SHMEM_I(inode);
struct shmem_falloc shmem_falloc;
pgoff_t start, index, end;
int error;
if (mode & ~(FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE))
return -EOPNOTSUPP;
inode_lock(inode);
if (mode & FALLOC_FL_PUNCH_HOLE) {
struct address_space *mapping = file->f_mapping;
loff_t unmap_start = round_up(offset, PAGE_SIZE);
loff_t unmap_end = round_down(offset + len, PAGE_SIZE) - 1;
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(shmem_falloc_waitq);
if (info->seals & F_SEAL_WRITE) {
error = -EPERM;
goto out;
}
shmem_falloc.waitq = &shmem_falloc_waitq;
shmem_falloc.start = unmap_start >> PAGE_SHIFT;
shmem_falloc.next = (unmap_end + 1) >> PAGE_SHIFT;
spin_lock(&inode->i_lock);
inode->i_private = &shmem_falloc;
spin_unlock(&inode->i_lock);
if ((u64)unmap_end > (u64)unmap_start)
unmap_mapping_range(mapping, unmap_start,
1 + unmap_end - unmap_start, 0);
shmem_truncate_range(inode, offset, offset + len - 1);
spin_lock(&inode->i_lock);
inode->i_private = NULL;
wake_up_all(&shmem_falloc_waitq);
WARN_ON_ONCE(!list_empty(&shmem_falloc_waitq.head));
spin_unlock(&inode->i_lock);
error = 0;
goto out;
}
error = inode_newsize_ok(inode, offset + len);
if (error)
goto out;
if ((info->seals & F_SEAL_GROW) && offset + len > inode->i_size) {
error = -EPERM;
goto out;
}
start = offset >> PAGE_SHIFT;
end = (offset + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (sbinfo->max_blocks && end - start > sbinfo->max_blocks) {
error = -ENOSPC;
goto out;
}
shmem_falloc.waitq = NULL;
shmem_falloc.start = start;
shmem_falloc.next = start;
shmem_falloc.nr_falloced = 0;
shmem_falloc.nr_unswapped = 0;
spin_lock(&inode->i_lock);
inode->i_private = &shmem_falloc;
spin_unlock(&inode->i_lock);
for (index = start; index < end; index++) {
struct page *page;
if (signal_pending(current))
error = -EINTR;
else if (shmem_falloc.nr_unswapped > shmem_falloc.nr_falloced)
error = -ENOMEM;
else
error = shmem_getpage(inode, index, &page, SGP_FALLOC);
if (error) {
if (index > start) {
shmem_undo_range(inode,
(loff_t)start << PAGE_SHIFT,
((loff_t)index << PAGE_SHIFT) - 1, true);
}
goto undone;
}
shmem_falloc.next++;
if (!PageUptodate(page))
shmem_falloc.nr_falloced++;
set_page_dirty(page);
unlock_page(page);
put_page(page);
cond_resched();
}
if (!(mode & FALLOC_FL_KEEP_SIZE) && offset + len > inode->i_size)
i_size_write(inode, offset + len);
inode->i_ctime = current_time(inode);
undone:
spin_lock(&inode->i_lock);
inode->i_private = NULL;
spin_unlock(&inode->i_lock);
out:
inode_unlock(inode);
return error;
}
static int shmem_statfs(struct dentry *dentry, struct kstatfs *buf)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(dentry->d_sb);
buf->f_type = TMPFS_MAGIC;
buf->f_bsize = PAGE_SIZE;
buf->f_namelen = NAME_MAX;
if (sbinfo->max_blocks) {
buf->f_blocks = sbinfo->max_blocks;
buf->f_bavail =
buf->f_bfree = sbinfo->max_blocks -
percpu_counter_sum(&sbinfo->used_blocks);
}
if (sbinfo->max_inodes) {
buf->f_files = sbinfo->max_inodes;
buf->f_ffree = sbinfo->free_inodes;
}
return 0;
}
static int
shmem_mknod(struct inode *dir, struct dentry *dentry, umode_t mode, dev_t dev)
{
struct inode *inode;
int error = -ENOSPC;
inode = shmem_get_inode(dir->i_sb, dir, mode, dev, VM_NORESERVE);
if (inode) {
error = simple_acl_create(dir, inode);
if (error)
goto out_iput;
error = security_inode_init_security(inode, dir,
&dentry->d_name,
shmem_initxattrs, NULL);
if (error && error != -EOPNOTSUPP)
goto out_iput;
error = 0;
dir->i_size += BOGO_DIRENT_SIZE;
dir->i_ctime = dir->i_mtime = current_time(dir);
d_instantiate(dentry, inode);
dget(dentry);
}
return error;
out_iput:
iput(inode);
return error;
}
static int
shmem_tmpfile(struct inode *dir, struct dentry *dentry, umode_t mode)
{
struct inode *inode;
int error = -ENOSPC;
inode = shmem_get_inode(dir->i_sb, dir, mode, 0, VM_NORESERVE);
if (inode) {
error = security_inode_init_security(inode, dir,
NULL,
shmem_initxattrs, NULL);
if (error && error != -EOPNOTSUPP)
goto out_iput;
error = simple_acl_create(dir, inode);
if (error)
goto out_iput;
d_tmpfile(dentry, inode);
}
return error;
out_iput:
iput(inode);
return error;
}
static int shmem_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
int error;
if ((error = shmem_mknod(dir, dentry, mode | S_IFDIR, 0)))
return error;
inc_nlink(dir);
return 0;
}
static int shmem_create(struct inode *dir, struct dentry *dentry, umode_t mode,
bool excl)
{
return shmem_mknod(dir, dentry, mode | S_IFREG, 0);
}
static int shmem_link(struct dentry *old_dentry, struct inode *dir, struct dentry *dentry)
{
struct inode *inode = d_inode(old_dentry);
int ret;
ret = shmem_reserve_inode(inode->i_sb);
if (ret)
goto out;
dir->i_size += BOGO_DIRENT_SIZE;
inode->i_ctime = dir->i_ctime = dir->i_mtime = current_time(inode);
inc_nlink(inode);
ihold(inode);
dget(dentry);
d_instantiate(dentry, inode);
out:
return ret;
}
static int shmem_unlink(struct inode *dir, struct dentry *dentry)
{
struct inode *inode = d_inode(dentry);
if (inode->i_nlink > 1 && !S_ISDIR(inode->i_mode))
shmem_free_inode(inode->i_sb);
dir->i_size -= BOGO_DIRENT_SIZE;
inode->i_ctime = dir->i_ctime = dir->i_mtime = current_time(inode);
drop_nlink(inode);
dput(dentry);
return 0;
}
static int shmem_rmdir(struct inode *dir, struct dentry *dentry)
{
if (!simple_empty(dentry))
return -ENOTEMPTY;
drop_nlink(d_inode(dentry));
drop_nlink(dir);
return shmem_unlink(dir, dentry);
}
static int shmem_exchange(struct inode *old_dir, struct dentry *old_dentry, struct inode *new_dir, struct dentry *new_dentry)
{
bool old_is_dir = d_is_dir(old_dentry);
bool new_is_dir = d_is_dir(new_dentry);
if (old_dir != new_dir && old_is_dir != new_is_dir) {
if (old_is_dir) {
drop_nlink(old_dir);
inc_nlink(new_dir);
} else {
drop_nlink(new_dir);
inc_nlink(old_dir);
}
}
old_dir->i_ctime = old_dir->i_mtime =
new_dir->i_ctime = new_dir->i_mtime =
d_inode(old_dentry)->i_ctime =
d_inode(new_dentry)->i_ctime = current_time(old_dir);
return 0;
}
static int shmem_whiteout(struct inode *old_dir, struct dentry *old_dentry)
{
struct dentry *whiteout;
int error;
whiteout = d_alloc(old_dentry->d_parent, &old_dentry->d_name);
if (!whiteout)
return -ENOMEM;
error = shmem_mknod(old_dir, whiteout,
S_IFCHR | WHITEOUT_MODE, WHITEOUT_DEV);
dput(whiteout);
if (error)
return error;
d_rehash(whiteout);
return 0;
}
static int shmem_rename2(struct inode *old_dir, struct dentry *old_dentry, struct inode *new_dir, struct dentry *new_dentry, unsigned int flags)
{
struct inode *inode = d_inode(old_dentry);
int they_are_dirs = S_ISDIR(inode->i_mode);
if (flags & ~(RENAME_NOREPLACE | RENAME_EXCHANGE | RENAME_WHITEOUT))
return -EINVAL;
if (flags & RENAME_EXCHANGE)
return shmem_exchange(old_dir, old_dentry, new_dir, new_dentry);
if (!simple_empty(new_dentry))
return -ENOTEMPTY;
if (flags & RENAME_WHITEOUT) {
int error;
error = shmem_whiteout(old_dir, old_dentry);
if (error)
return error;
}
if (d_really_is_positive(new_dentry)) {
(void) shmem_unlink(new_dir, new_dentry);
if (they_are_dirs) {
drop_nlink(d_inode(new_dentry));
drop_nlink(old_dir);
}
} else if (they_are_dirs) {
drop_nlink(old_dir);
inc_nlink(new_dir);
}
old_dir->i_size -= BOGO_DIRENT_SIZE;
new_dir->i_size += BOGO_DIRENT_SIZE;
old_dir->i_ctime = old_dir->i_mtime =
new_dir->i_ctime = new_dir->i_mtime =
inode->i_ctime = current_time(old_dir);
return 0;
}
static int shmem_symlink(struct inode *dir, struct dentry *dentry, const char *symname)
{
int error;
int len;
struct inode *inode;
struct page *page;
struct shmem_inode_info *info;
len = strlen(symname) + 1;
if (len > PAGE_SIZE)
return -ENAMETOOLONG;
inode = shmem_get_inode(dir->i_sb, dir, S_IFLNK|S_IRWXUGO, 0, VM_NORESERVE);
if (!inode)
return -ENOSPC;
error = security_inode_init_security(inode, dir, &dentry->d_name,
shmem_initxattrs, NULL);
if (error) {
if (error != -EOPNOTSUPP) {
iput(inode);
return error;
}
error = 0;
}
info = SHMEM_I(inode);
inode->i_size = len-1;
if (len <= SHORT_SYMLINK_LEN) {
inode->i_link = kmemdup(symname, len, GFP_KERNEL);
if (!inode->i_link) {
iput(inode);
return -ENOMEM;
}
inode->i_op = &shmem_short_symlink_operations;
} else {
inode_nohighmem(inode);
error = shmem_getpage(inode, 0, &page, SGP_WRITE);
if (error) {
iput(inode);
return error;
}
inode->i_mapping->a_ops = &shmem_aops;
inode->i_op = &shmem_symlink_inode_operations;
memcpy(page_address(page), symname, len);
SetPageUptodate(page);
set_page_dirty(page);
unlock_page(page);
put_page(page);
}
dir->i_size += BOGO_DIRENT_SIZE;
dir->i_ctime = dir->i_mtime = current_time(dir);
d_instantiate(dentry, inode);
dget(dentry);
return 0;
}
static void shmem_put_link(void *arg)
{
mark_page_accessed(arg);
put_page(arg);
}
static const char *shmem_get_link(struct dentry *dentry,
struct inode *inode,
struct delayed_call *done)
{
struct page *page = NULL;
int error;
if (!dentry) {
page = find_get_page(inode->i_mapping, 0);
if (!page)
return ERR_PTR(-ECHILD);
if (!PageUptodate(page)) {
put_page(page);
return ERR_PTR(-ECHILD);
}
} else {
error = shmem_getpage(inode, 0, &page, SGP_READ);
if (error)
return ERR_PTR(error);
unlock_page(page);
}
set_delayed_call(done, shmem_put_link, page);
return page_address(page);
}
static int shmem_initxattrs(struct inode *inode,
const struct xattr *xattr_array,
void *fs_info)
{
struct shmem_inode_info *info = SHMEM_I(inode);
const struct xattr *xattr;
struct simple_xattr *new_xattr;
size_t len;
for (xattr = xattr_array; xattr->name != NULL; xattr++) {
new_xattr = simple_xattr_alloc(xattr->value, xattr->value_len);
if (!new_xattr)
return -ENOMEM;
len = strlen(xattr->name) + 1;
new_xattr->name = kmalloc(XATTR_SECURITY_PREFIX_LEN + len,
GFP_KERNEL);
if (!new_xattr->name) {
kfree(new_xattr);
return -ENOMEM;
}
memcpy(new_xattr->name, XATTR_SECURITY_PREFIX,
XATTR_SECURITY_PREFIX_LEN);
memcpy(new_xattr->name + XATTR_SECURITY_PREFIX_LEN,
xattr->name, len);
simple_xattr_list_add(&info->xattrs, new_xattr);
}
return 0;
}
static int shmem_xattr_handler_get(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, void *buffer, size_t size)
{
struct shmem_inode_info *info = SHMEM_I(inode);
name = xattr_full_name(handler, name);
return simple_xattr_get(&info->xattrs, name, buffer, size);
}
static int shmem_xattr_handler_set(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, const void *value,
size_t size, int flags)
{
struct shmem_inode_info *info = SHMEM_I(inode);
name = xattr_full_name(handler, name);
return simple_xattr_set(&info->xattrs, name, value, size, flags);
}
static ssize_t shmem_listxattr(struct dentry *dentry, char *buffer, size_t size)
{
struct shmem_inode_info *info = SHMEM_I(d_inode(dentry));
return simple_xattr_list(d_inode(dentry), &info->xattrs, buffer, size);
}
static struct dentry *shmem_get_parent(struct dentry *child)
{
return ERR_PTR(-ESTALE);
}
static int shmem_match(struct inode *ino, void *vfh)
{
__u32 *fh = vfh;
__u64 inum = fh[2];
inum = (inum << 32) | fh[1];
return ino->i_ino == inum && fh[0] == ino->i_generation;
}
static struct dentry *shmem_fh_to_dentry(struct super_block *sb,
struct fid *fid, int fh_len, int fh_type)
{
struct inode *inode;
struct dentry *dentry = NULL;
u64 inum;
if (fh_len < 3)
return NULL;
inum = fid->raw[2];
inum = (inum << 32) | fid->raw[1];
inode = ilookup5(sb, (unsigned long)(inum + fid->raw[0]),
shmem_match, fid->raw);
if (inode) {
dentry = d_find_alias(inode);
iput(inode);
}
return dentry;
}
static int shmem_encode_fh(struct inode *inode, __u32 *fh, int *len,
struct inode *parent)
{
if (*len < 3) {
*len = 3;
return FILEID_INVALID;
}
if (inode_unhashed(inode)) {
static DEFINE_SPINLOCK(lock);
spin_lock(&lock);
if (inode_unhashed(inode))
__insert_inode_hash(inode,
inode->i_ino + inode->i_generation);
spin_unlock(&lock);
}
fh[0] = inode->i_generation;
fh[1] = inode->i_ino;
fh[2] = ((__u64)inode->i_ino) >> 32;
*len = 3;
return 1;
}
static int shmem_parse_options(char *options, struct shmem_sb_info *sbinfo,
bool remount)
{
char *this_char, *value, *rest;
struct mempolicy *mpol = NULL;
uid_t uid;
gid_t gid;
while (options != NULL) {
this_char = options;
for (;;) {
options = strchr(options, ',');
if (options == NULL)
break;
options++;
if (!isdigit(*options)) {
options[-1] = '\0';
break;
}
}
if (!*this_char)
continue;
if ((value = strchr(this_char,'=')) != NULL) {
*value++ = 0;
} else {
pr_err("tmpfs: No value for mount option '%s'\n",
this_char);
goto error;
}
if (!strcmp(this_char,"size")) {
unsigned long long size;
size = memparse(value,&rest);
if (*rest == '%') {
size <<= PAGE_SHIFT;
size *= totalram_pages;
do_div(size, 100);
rest++;
}
if (*rest)
goto bad_val;
sbinfo->max_blocks =
DIV_ROUND_UP(size, PAGE_SIZE);
} else if (!strcmp(this_char,"nr_blocks")) {
sbinfo->max_blocks = memparse(value, &rest);
if (*rest)
goto bad_val;
} else if (!strcmp(this_char,"nr_inodes")) {
sbinfo->max_inodes = memparse(value, &rest);
if (*rest)
goto bad_val;
} else if (!strcmp(this_char,"mode")) {
if (remount)
continue;
sbinfo->mode = simple_strtoul(value, &rest, 8) & 07777;
if (*rest)
goto bad_val;
} else if (!strcmp(this_char,"uid")) {
if (remount)
continue;
uid = simple_strtoul(value, &rest, 0);
if (*rest)
goto bad_val;
sbinfo->uid = make_kuid(current_user_ns(), uid);
if (!uid_valid(sbinfo->uid))
goto bad_val;
} else if (!strcmp(this_char,"gid")) {
if (remount)
continue;
gid = simple_strtoul(value, &rest, 0);
if (*rest)
goto bad_val;
sbinfo->gid = make_kgid(current_user_ns(), gid);
if (!gid_valid(sbinfo->gid))
goto bad_val;
#ifdef CONFIG_TRANSPARENT_HUGE_PAGECACHE
} else if (!strcmp(this_char, "huge")) {
int huge;
huge = shmem_parse_huge(value);
if (huge < 0)
goto bad_val;
if (!has_transparent_hugepage() &&
huge != SHMEM_HUGE_NEVER)
goto bad_val;
sbinfo->huge = huge;
#endif
#ifdef CONFIG_NUMA
} else if (!strcmp(this_char,"mpol")) {
mpol_put(mpol);
mpol = NULL;
if (mpol_parse_str(value, &mpol))
goto bad_val;
#endif
} else {
pr_err("tmpfs: Bad mount option %s\n", this_char);
goto error;
}
}
sbinfo->mpol = mpol;
return 0;
bad_val:
pr_err("tmpfs: Bad value '%s' for mount option '%s'\n",
value, this_char);
error:
mpol_put(mpol);
return 1;
}
static int shmem_remount_fs(struct super_block *sb, int *flags, char *data)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
struct shmem_sb_info config = *sbinfo;
unsigned long inodes;
int error = -EINVAL;
config.mpol = NULL;
if (shmem_parse_options(data, &config, true))
return error;
spin_lock(&sbinfo->stat_lock);
inodes = sbinfo->max_inodes - sbinfo->free_inodes;
if (percpu_counter_compare(&sbinfo->used_blocks, config.max_blocks) > 0)
goto out;
if (config.max_inodes < inodes)
goto out;
if (config.max_blocks && !sbinfo->max_blocks)
goto out;
if (config.max_inodes && !sbinfo->max_inodes)
goto out;
error = 0;
sbinfo->huge = config.huge;
sbinfo->max_blocks = config.max_blocks;
sbinfo->max_inodes = config.max_inodes;
sbinfo->free_inodes = config.max_inodes - inodes;
if (config.mpol) {
mpol_put(sbinfo->mpol);
sbinfo->mpol = config.mpol;
}
out:
spin_unlock(&sbinfo->stat_lock);
return error;
}
static int shmem_show_options(struct seq_file *seq, struct dentry *root)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(root->d_sb);
if (sbinfo->max_blocks != shmem_default_max_blocks())
seq_printf(seq, ",size=%luk",
sbinfo->max_blocks << (PAGE_SHIFT - 10));
if (sbinfo->max_inodes != shmem_default_max_inodes())
seq_printf(seq, ",nr_inodes=%lu", sbinfo->max_inodes);
if (sbinfo->mode != (S_IRWXUGO | S_ISVTX))
seq_printf(seq, ",mode=%03ho", sbinfo->mode);
if (!uid_eq(sbinfo->uid, GLOBAL_ROOT_UID))
seq_printf(seq, ",uid=%u",
from_kuid_munged(&init_user_ns, sbinfo->uid));
if (!gid_eq(sbinfo->gid, GLOBAL_ROOT_GID))
seq_printf(seq, ",gid=%u",
from_kgid_munged(&init_user_ns, sbinfo->gid));
#ifdef CONFIG_TRANSPARENT_HUGE_PAGECACHE
if (sbinfo->huge)
seq_printf(seq, ",huge=%s", shmem_format_huge(sbinfo->huge));
#endif
shmem_show_mpol(seq, sbinfo->mpol);
return 0;
}
static void shmem_put_super(struct super_block *sb)
{
struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
percpu_counter_destroy(&sbinfo->used_blocks);
mpol_put(sbinfo->mpol);
kfree(sbinfo);
sb->s_fs_info = NULL;
}
int shmem_fill_super(struct super_block *sb, void *data, int silent)
{
struct inode *inode;
struct shmem_sb_info *sbinfo;
int err = -ENOMEM;
sbinfo = kzalloc(max((int)sizeof(struct shmem_sb_info),
L1_CACHE_BYTES), GFP_KERNEL);
if (!sbinfo)
return -ENOMEM;
sbinfo->mode = S_IRWXUGO | S_ISVTX;
sbinfo->uid = current_fsuid();
sbinfo->gid = current_fsgid();
sb->s_fs_info = sbinfo;
#ifdef CONFIG_TMPFS
if (!(sb->s_flags & MS_KERNMOUNT)) {
sbinfo->max_blocks = shmem_default_max_blocks();
sbinfo->max_inodes = shmem_default_max_inodes();
if (shmem_parse_options(data, sbinfo, false)) {
err = -EINVAL;
goto failed;
}
} else {
sb->s_flags |= MS_NOUSER;
}
sb->s_export_op = &shmem_export_ops;
sb->s_flags |= MS_NOSEC;
#else
sb->s_flags |= MS_NOUSER;
#endif
spin_lock_init(&sbinfo->stat_lock);
if (percpu_counter_init(&sbinfo->used_blocks, 0, GFP_KERNEL))
goto failed;
sbinfo->free_inodes = sbinfo->max_inodes;
spin_lock_init(&sbinfo->shrinklist_lock);
INIT_LIST_HEAD(&sbinfo->shrinklist);
sb->s_maxbytes = MAX_LFS_FILESIZE;
sb->s_blocksize = PAGE_SIZE;
sb->s_blocksize_bits = PAGE_SHIFT;
sb->s_magic = TMPFS_MAGIC;
sb->s_op = &shmem_ops;
sb->s_time_gran = 1;
#ifdef CONFIG_TMPFS_XATTR
sb->s_xattr = shmem_xattr_handlers;
#endif
#ifdef CONFIG_TMPFS_POSIX_ACL
sb->s_flags |= MS_POSIXACL;
#endif
uuid_gen(&sb->s_uuid);
inode = shmem_get_inode(sb, NULL, S_IFDIR | sbinfo->mode, 0, VM_NORESERVE);
if (!inode)
goto failed;
inode->i_uid = sbinfo->uid;
inode->i_gid = sbinfo->gid;
sb->s_root = d_make_root(inode);
if (!sb->s_root)
goto failed;
return 0;
failed:
shmem_put_super(sb);
return err;
}
static struct inode *shmem_alloc_inode(struct super_block *sb)
{
struct shmem_inode_info *info;
info = kmem_cache_alloc(shmem_inode_cachep, GFP_KERNEL);
if (!info)
return NULL;
return &info->vfs_inode;
}
static void shmem_destroy_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
if (S_ISLNK(inode->i_mode))
kfree(inode->i_link);
kmem_cache_free(shmem_inode_cachep, SHMEM_I(inode));
}
static void shmem_destroy_inode(struct inode *inode)
{
if (S_ISREG(inode->i_mode))
mpol_free_shared_policy(&SHMEM_I(inode)->policy);
call_rcu(&inode->i_rcu, shmem_destroy_callback);
}
static void shmem_init_inode(void *foo)
{
struct shmem_inode_info *info = foo;
inode_init_once(&info->vfs_inode);
}
static int shmem_init_inodecache(void)
{
shmem_inode_cachep = kmem_cache_create("shmem_inode_cache",
sizeof(struct shmem_inode_info),
0, SLAB_PANIC|SLAB_ACCOUNT, shmem_init_inode);
return 0;
}
static void shmem_destroy_inodecache(void)
{
kmem_cache_destroy(shmem_inode_cachep);
}
static struct dentry *shmem_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_nodev(fs_type, flags, data, shmem_fill_super);
}
int __init shmem_init(void)
{
int error;
if (shmem_inode_cachep)
return 0;
error = shmem_init_inodecache();
if (error)
goto out3;
error = register_filesystem(&shmem_fs_type);
if (error) {
pr_err("Could not register tmpfs\n");
goto out2;
}
shm_mnt = kern_mount(&shmem_fs_type);
if (IS_ERR(shm_mnt)) {
error = PTR_ERR(shm_mnt);
pr_err("Could not kern_mount tmpfs\n");
goto out1;
}
#ifdef CONFIG_TRANSPARENT_HUGE_PAGECACHE
if (has_transparent_hugepage() && shmem_huge > SHMEM_HUGE_DENY)
SHMEM_SB(shm_mnt->mnt_sb)->huge = shmem_huge;
else
shmem_huge = 0;
#endif
return 0;
out1:
unregister_filesystem(&shmem_fs_type);
out2:
shmem_destroy_inodecache();
out3:
shm_mnt = ERR_PTR(error);
return error;
}
static ssize_t shmem_enabled_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
int values[] = {
SHMEM_HUGE_ALWAYS,
SHMEM_HUGE_WITHIN_SIZE,
SHMEM_HUGE_ADVISE,
SHMEM_HUGE_NEVER,
SHMEM_HUGE_DENY,
SHMEM_HUGE_FORCE,
};
int i, count;
for (i = 0, count = 0; i < ARRAY_SIZE(values); i++) {
const char *fmt = shmem_huge == values[i] ? "[%s] " : "%s ";
count += sprintf(buf + count, fmt,
shmem_format_huge(values[i]));
}
buf[count - 1] = '\n';
return count;
}
static ssize_t shmem_enabled_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
char tmp[16];
int huge;
if (count + 1 > sizeof(tmp))
return -EINVAL;
memcpy(tmp, buf, count);
tmp[count] = '\0';
if (count && tmp[count - 1] == '\n')
tmp[count - 1] = '\0';
huge = shmem_parse_huge(tmp);
if (huge == -EINVAL)
return -EINVAL;
if (!has_transparent_hugepage() &&
huge != SHMEM_HUGE_NEVER && huge != SHMEM_HUGE_DENY)
return -EINVAL;
shmem_huge = huge;
if (shmem_huge > SHMEM_HUGE_DENY)
SHMEM_SB(shm_mnt->mnt_sb)->huge = shmem_huge;
return count;
}
bool shmem_huge_enabled(struct vm_area_struct *vma)
{
struct inode *inode = file_inode(vma->vm_file);
struct shmem_sb_info *sbinfo = SHMEM_SB(inode->i_sb);
loff_t i_size;
pgoff_t off;
if (shmem_huge == SHMEM_HUGE_FORCE)
return true;
if (shmem_huge == SHMEM_HUGE_DENY)
return false;
switch (sbinfo->huge) {
case SHMEM_HUGE_NEVER:
return false;
case SHMEM_HUGE_ALWAYS:
return true;
case SHMEM_HUGE_WITHIN_SIZE:
off = round_up(vma->vm_pgoff, HPAGE_PMD_NR);
i_size = round_up(i_size_read(inode), PAGE_SIZE);
if (i_size >= HPAGE_PMD_SIZE &&
i_size >> PAGE_SHIFT >= off)
return true;
case SHMEM_HUGE_ADVISE:
return (vma->vm_flags & VM_HUGEPAGE);
default:
VM_BUG_ON(1);
return false;
}
}
int __init shmem_init(void)
{
BUG_ON(register_filesystem(&shmem_fs_type) != 0);
shm_mnt = kern_mount(&shmem_fs_type);
BUG_ON(IS_ERR(shm_mnt));
return 0;
}
int shmem_unuse(swp_entry_t swap, struct page *page)
{
return 0;
}
int shmem_lock(struct file *file, int lock, struct user_struct *user)
{
return 0;
}
void shmem_unlock_mapping(struct address_space *mapping)
{
}
unsigned long shmem_get_unmapped_area(struct file *file,
unsigned long addr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
return current->mm->get_unmapped_area(file, addr, len, pgoff, flags);
}
void shmem_truncate_range(struct inode *inode, loff_t lstart, loff_t lend)
{
truncate_inode_pages_range(inode->i_mapping, lstart, lend);
}
static struct file *__shmem_file_setup(const char *name, loff_t size,
unsigned long flags, unsigned int i_flags)
{
struct file *res;
struct inode *inode;
struct path path;
struct super_block *sb;
struct qstr this;
if (IS_ERR(shm_mnt))
return ERR_CAST(shm_mnt);
if (size < 0 || size > MAX_LFS_FILESIZE)
return ERR_PTR(-EINVAL);
if (shmem_acct_size(flags, size))
return ERR_PTR(-ENOMEM);
res = ERR_PTR(-ENOMEM);
this.name = name;
this.len = strlen(name);
this.hash = 0;
sb = shm_mnt->mnt_sb;
path.mnt = mntget(shm_mnt);
path.dentry = d_alloc_pseudo(sb, &this);
if (!path.dentry)
goto put_memory;
d_set_d_op(path.dentry, &anon_ops);
res = ERR_PTR(-ENOSPC);
inode = shmem_get_inode(sb, NULL, S_IFREG | S_IRWXUGO, 0, flags);
if (!inode)
goto put_memory;
inode->i_flags |= i_flags;
d_instantiate(path.dentry, inode);
inode->i_size = size;
clear_nlink(inode);
res = ERR_PTR(ramfs_nommu_expand_for_mapping(inode, size));
if (IS_ERR(res))
goto put_path;
res = alloc_file(&path, FMODE_WRITE | FMODE_READ,
&shmem_file_operations);
if (IS_ERR(res))
goto put_path;
return res;
put_memory:
shmem_unacct_size(flags, size);
put_path:
path_put(&path);
return res;
}
struct file *shmem_kernel_file_setup(const char *name, loff_t size, unsigned long flags)
{
return __shmem_file_setup(name, size, flags, S_PRIVATE);
}
struct file *shmem_file_setup(const char *name, loff_t size, unsigned long flags)
{
return __shmem_file_setup(name, size, flags, 0);
}
int shmem_zero_setup(struct vm_area_struct *vma)
{
struct file *file;
loff_t size = vma->vm_end - vma->vm_start;
file = __shmem_file_setup("dev/zero", size, vma->vm_flags, S_PRIVATE);
if (IS_ERR(file))
return PTR_ERR(file);
if (vma->vm_file)
fput(vma->vm_file);
vma->vm_file = file;
vma->vm_ops = &shmem_vm_ops;
if (IS_ENABLED(CONFIG_TRANSPARENT_HUGE_PAGECACHE) &&
((vma->vm_start + ~HPAGE_PMD_MASK) & HPAGE_PMD_MASK) <
(vma->vm_end & HPAGE_PMD_MASK)) {
khugepaged_enter(vma, vma->vm_flags);
}
return 0;
}
struct page *shmem_read_mapping_page_gfp(struct address_space *mapping,
pgoff_t index, gfp_t gfp)
{
#ifdef CONFIG_SHMEM
struct inode *inode = mapping->host;
struct page *page;
int error;
BUG_ON(mapping->a_ops != &shmem_aops);
error = shmem_getpage_gfp(inode, index, &page, SGP_CACHE,
gfp, NULL, NULL, NULL);
if (error)
page = ERR_PTR(error);
else
unlock_page(page);
return page;
#else
return read_cache_page_gfp(mapping, index, gfp);
#endif
}
