static void clear_shadow_entry(struct address_space *mapping, pgoff_t index,
void *entry)
{
struct radix_tree_node *node;
void **slot;
spin_lock_irq(&mapping->tree_lock);
if (!__radix_tree_lookup(&mapping->page_tree, index, &node, &slot))
goto unlock;
if (*slot != entry)
goto unlock;
__radix_tree_replace(&mapping->page_tree, node, slot, NULL,
workingset_update_node, mapping);
mapping->nrexceptional--;
unlock:
spin_unlock_irq(&mapping->tree_lock);
}
static void truncate_exceptional_entry(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (shmem_mapping(mapping))
return;
if (dax_mapping(mapping)) {
dax_delete_mapping_entry(mapping, index);
return;
}
clear_shadow_entry(mapping, index, entry);
}
static int invalidate_exceptional_entry(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (shmem_mapping(mapping) || dax_mapping(mapping))
return 1;
clear_shadow_entry(mapping, index, entry);
return 1;
}
static int invalidate_exceptional_entry2(struct address_space *mapping,
pgoff_t index, void *entry)
{
if (shmem_mapping(mapping))
return 1;
if (dax_mapping(mapping))
return dax_invalidate_mapping_entry_sync(mapping, index);
clear_shadow_entry(mapping, index, entry);
return 1;
}
void do_invalidatepage(struct page *page, unsigned int offset,
unsigned int length)
{
void (*invalidatepage)(struct page *, unsigned int, unsigned int);
invalidatepage = page->mapping->a_ops->invalidatepage;
#ifdef CONFIG_BLOCK
if (!invalidatepage)
invalidatepage = block_invalidatepage;
#endif
if (invalidatepage)
(*invalidatepage)(page, offset, length);
}
static int
truncate_complete_page(struct address_space *mapping, struct page *page)
{
if (page->mapping != mapping)
return -EIO;
if (page_has_private(page))
do_invalidatepage(page, 0, PAGE_SIZE);
cancel_dirty_page(page);
ClearPageMappedToDisk(page);
delete_from_page_cache(page);
return 0;
}
static int
invalidate_complete_page(struct address_space *mapping, struct page *page)
{
int ret;
if (page->mapping != mapping)
return 0;
if (page_has_private(page) && !try_to_release_page(page, 0))
return 0;
ret = remove_mapping(mapping, page);
return ret;
}
int truncate_inode_page(struct address_space *mapping, struct page *page)
{
loff_t holelen;
VM_BUG_ON_PAGE(PageTail(page), page);
holelen = PageTransHuge(page) ? HPAGE_PMD_SIZE : PAGE_SIZE;
if (page_mapped(page)) {
unmap_mapping_range(mapping,
(loff_t)page->index << PAGE_SHIFT,
holelen, 0);
}
return truncate_complete_page(mapping, page);
}
int generic_error_remove_page(struct address_space *mapping, struct page *page)
{
if (!mapping)
return -EINVAL;
if (!S_ISREG(mapping->host->i_mode))
return -EIO;
return truncate_inode_page(mapping, page);
}
int invalidate_inode_page(struct page *page)
{
struct address_space *mapping = page_mapping(page);
if (!mapping)
return 0;
if (PageDirty(page) || PageWriteback(page))
return 0;
if (page_mapped(page))
return 0;
return invalidate_complete_page(mapping, page);
}
void truncate_inode_pages_range(struct address_space *mapping,
loff_t lstart, loff_t lend)
{
pgoff_t start;
pgoff_t end;
unsigned int partial_start;
unsigned int partial_end;
struct pagevec pvec;
pgoff_t indices[PAGEVEC_SIZE];
pgoff_t index;
int i;
if (mapping->nrpages == 0 && mapping->nrexceptional == 0)
goto out;
partial_start = lstart & (PAGE_SIZE - 1);
partial_end = (lend + 1) & (PAGE_SIZE - 1);
start = (lstart + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (lend == -1)
end = -1;
else
end = (lend + 1) >> PAGE_SHIFT;
pagevec_init(&pvec, 0);
index = start;
while (index < end && pagevec_lookup_entries(&pvec, mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE),
indices)) {
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index >= end)
break;
if (radix_tree_exceptional_entry(page)) {
truncate_exceptional_entry(mapping, index,
page);
continue;
}
if (!trylock_page(page))
continue;
WARN_ON(page_to_index(page) != index);
if (PageWriteback(page)) {
unlock_page(page);
continue;
}
truncate_inode_page(mapping, page);
unlock_page(page);
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
cond_resched();
index++;
}
if (partial_start) {
struct page *page = find_lock_page(mapping, start - 1);
if (page) {
unsigned int top = PAGE_SIZE;
if (start > end) {
top = partial_end;
partial_end = 0;
}
wait_on_page_writeback(page);
zero_user_segment(page, partial_start, top);
cleancache_invalidate_page(mapping, page);
if (page_has_private(page))
do_invalidatepage(page, partial_start,
top - partial_start);
unlock_page(page);
put_page(page);
}
}
if (partial_end) {
struct page *page = find_lock_page(mapping, end);
if (page) {
wait_on_page_writeback(page);
zero_user_segment(page, 0, partial_end);
cleancache_invalidate_page(mapping, page);
if (page_has_private(page))
do_invalidatepage(page, 0,
partial_end);
unlock_page(page);
put_page(page);
}
}
if (start >= end)
goto out;
index = start;
for ( ; ; ) {
cond_resched();
if (!pagevec_lookup_entries(&pvec, mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE), indices)) {
if (index == start)
break;
index = start;
continue;
}
if (index == start && indices[0] >= end) {
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
break;
}
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index >= end) {
index = start - 1;
break;
}
if (radix_tree_exceptional_entry(page)) {
truncate_exceptional_entry(mapping, index,
page);
continue;
}
lock_page(page);
WARN_ON(page_to_index(page) != index);
wait_on_page_writeback(page);
truncate_inode_page(mapping, page);
unlock_page(page);
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
index++;
}
out:
cleancache_invalidate_inode(mapping);
}
void truncate_inode_pages(struct address_space *mapping, loff_t lstart)
{
truncate_inode_pages_range(mapping, lstart, (loff_t)-1);
}
void truncate_inode_pages_final(struct address_space *mapping)
{
unsigned long nrexceptional;
unsigned long nrpages;
mapping_set_exiting(mapping);
nrpages = mapping->nrpages;
smp_rmb();
nrexceptional = mapping->nrexceptional;
if (nrpages || nrexceptional) {
spin_lock_irq(&mapping->tree_lock);
spin_unlock_irq(&mapping->tree_lock);
truncate_inode_pages(mapping, 0);
}
}
unsigned long invalidate_mapping_pages(struct address_space *mapping,
pgoff_t start, pgoff_t end)
{
pgoff_t indices[PAGEVEC_SIZE];
struct pagevec pvec;
pgoff_t index = start;
unsigned long ret;
unsigned long count = 0;
int i;
pagevec_init(&pvec, 0);
while (index <= end && pagevec_lookup_entries(&pvec, mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE - 1) + 1,
indices)) {
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index > end)
break;
if (radix_tree_exceptional_entry(page)) {
invalidate_exceptional_entry(mapping, index,
page);
continue;
}
if (!trylock_page(page))
continue;
WARN_ON(page_to_index(page) != index);
if (PageTransTail(page)) {
unlock_page(page);
continue;
} else if (PageTransHuge(page)) {
index += HPAGE_PMD_NR - 1;
i += HPAGE_PMD_NR - 1;
if (index > end) {
unlock_page(page);
continue;
}
}
ret = invalidate_inode_page(page);
unlock_page(page);
if (!ret)
deactivate_file_page(page);
count += ret;
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
cond_resched();
index++;
}
return count;
}
static int
invalidate_complete_page2(struct address_space *mapping, struct page *page)
{
unsigned long flags;
if (page->mapping != mapping)
return 0;
if (page_has_private(page) && !try_to_release_page(page, GFP_KERNEL))
return 0;
spin_lock_irqsave(&mapping->tree_lock, flags);
if (PageDirty(page))
goto failed;
BUG_ON(page_has_private(page));
__delete_from_page_cache(page, NULL);
spin_unlock_irqrestore(&mapping->tree_lock, flags);
if (mapping->a_ops->freepage)
mapping->a_ops->freepage(page);
put_page(page);
return 1;
failed:
spin_unlock_irqrestore(&mapping->tree_lock, flags);
return 0;
}
static int do_launder_page(struct address_space *mapping, struct page *page)
{
if (!PageDirty(page))
return 0;
if (page->mapping != mapping || mapping->a_ops->launder_page == NULL)
return 0;
return mapping->a_ops->launder_page(page);
}
int invalidate_inode_pages2_range(struct address_space *mapping,
pgoff_t start, pgoff_t end)
{
pgoff_t indices[PAGEVEC_SIZE];
struct pagevec pvec;
pgoff_t index;
int i;
int ret = 0;
int ret2 = 0;
int did_range_unmap = 0;
if (mapping->nrpages == 0 && mapping->nrexceptional == 0)
goto out;
pagevec_init(&pvec, 0);
index = start;
while (index <= end && pagevec_lookup_entries(&pvec, mapping, index,
min(end - index, (pgoff_t)PAGEVEC_SIZE - 1) + 1,
indices)) {
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
index = indices[i];
if (index > end)
break;
if (radix_tree_exceptional_entry(page)) {
if (!invalidate_exceptional_entry2(mapping,
index, page))
ret = -EBUSY;
continue;
}
lock_page(page);
WARN_ON(page_to_index(page) != index);
if (page->mapping != mapping) {
unlock_page(page);
continue;
}
wait_on_page_writeback(page);
if (page_mapped(page)) {
if (!did_range_unmap) {
unmap_mapping_range(mapping,
(loff_t)index << PAGE_SHIFT,
(loff_t)(1 + end - index)
<< PAGE_SHIFT,
0);
did_range_unmap = 1;
} else {
unmap_mapping_range(mapping,
(loff_t)index << PAGE_SHIFT,
PAGE_SIZE, 0);
}
}
BUG_ON(page_mapped(page));
ret2 = do_launder_page(mapping, page);
if (ret2 == 0) {
if (!invalidate_complete_page2(mapping, page))
ret2 = -EBUSY;
}
if (ret2 < 0)
ret = ret2;
unlock_page(page);
}
pagevec_remove_exceptionals(&pvec);
pagevec_release(&pvec);
cond_resched();
index++;
}
if (dax_mapping(mapping)) {
unmap_mapping_range(mapping, (loff_t)start << PAGE_SHIFT,
(loff_t)(end - start + 1) << PAGE_SHIFT, 0);
}
out:
cleancache_invalidate_inode(mapping);
return ret;
}
int invalidate_inode_pages2(struct address_space *mapping)
{
return invalidate_inode_pages2_range(mapping, 0, -1);
}
void truncate_pagecache(struct inode *inode, loff_t newsize)
{
struct address_space *mapping = inode->i_mapping;
loff_t holebegin = round_up(newsize, PAGE_SIZE);
unmap_mapping_range(mapping, holebegin, 0, 1);
truncate_inode_pages(mapping, newsize);
unmap_mapping_range(mapping, holebegin, 0, 1);
}
void truncate_setsize(struct inode *inode, loff_t newsize)
{
loff_t oldsize = inode->i_size;
i_size_write(inode, newsize);
if (newsize > oldsize)
pagecache_isize_extended(inode, oldsize, newsize);
truncate_pagecache(inode, newsize);
}
void pagecache_isize_extended(struct inode *inode, loff_t from, loff_t to)
{
int bsize = i_blocksize(inode);
loff_t rounded_from;
struct page *page;
pgoff_t index;
WARN_ON(to > inode->i_size);
if (from >= to || bsize == PAGE_SIZE)
return;
rounded_from = round_up(from, bsize);
if (to <= rounded_from || !(rounded_from & (PAGE_SIZE - 1)))
return;
index = from >> PAGE_SHIFT;
page = find_lock_page(inode->i_mapping, index);
if (!page)
return;
if (page_mkclean(page))
set_page_dirty(page);
unlock_page(page);
put_page(page);
}
void truncate_pagecache_range(struct inode *inode, loff_t lstart, loff_t lend)
{
struct address_space *mapping = inode->i_mapping;
loff_t unmap_start = round_up(lstart, PAGE_SIZE);
loff_t unmap_end = round_down(1 + lend, PAGE_SIZE) - 1;
if ((u64)unmap_end > (u64)unmap_start)
unmap_mapping_range(mapping, unmap_start,
1 + unmap_end - unmap_start, 0);
truncate_inode_pages_range(mapping, lstart, lend);
}
