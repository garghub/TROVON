void
file_ra_state_init(struct file_ra_state *ra, struct address_space *mapping)
{
ra->ra_pages = inode_to_bdi(mapping->host)->ra_pages;
ra->prev_pos = -1;
}
static void read_cache_pages_invalidate_page(struct address_space *mapping,
struct page *page)
{
if (page_has_private(page)) {
if (!trylock_page(page))
BUG();
page->mapping = mapping;
do_invalidatepage(page, 0, PAGE_CACHE_SIZE);
page->mapping = NULL;
unlock_page(page);
}
page_cache_release(page);
}
static void read_cache_pages_invalidate_pages(struct address_space *mapping,
struct list_head *pages)
{
struct page *victim;
while (!list_empty(pages)) {
victim = lru_to_page(pages);
list_del(&victim->lru);
read_cache_pages_invalidate_page(mapping, victim);
}
}
int read_cache_pages(struct address_space *mapping, struct list_head *pages,
int (*filler)(void *, struct page *), void *data)
{
struct page *page;
int ret = 0;
while (!list_empty(pages)) {
page = lru_to_page(pages);
list_del(&page->lru);
if (add_to_page_cache_lru(page, mapping, page->index,
mapping_gfp_constraint(mapping, GFP_KERNEL))) {
read_cache_pages_invalidate_page(mapping, page);
continue;
}
page_cache_release(page);
ret = filler(data, page);
if (unlikely(ret)) {
read_cache_pages_invalidate_pages(mapping, pages);
break;
}
task_io_account_read(PAGE_CACHE_SIZE);
}
return ret;
}
static int read_pages(struct address_space *mapping, struct file *filp,
struct list_head *pages, unsigned nr_pages)
{
struct blk_plug plug;
unsigned page_idx;
int ret;
blk_start_plug(&plug);
if (mapping->a_ops->readpages) {
ret = mapping->a_ops->readpages(filp, mapping, pages, nr_pages);
put_pages_list(pages);
goto out;
}
for (page_idx = 0; page_idx < nr_pages; page_idx++) {
struct page *page = lru_to_page(pages);
list_del(&page->lru);
if (!add_to_page_cache_lru(page, mapping, page->index,
mapping_gfp_constraint(mapping, GFP_KERNEL))) {
mapping->a_ops->readpage(filp, page);
}
page_cache_release(page);
}
ret = 0;
out:
blk_finish_plug(&plug);
return ret;
}
int __do_page_cache_readahead(struct address_space *mapping, struct file *filp,
pgoff_t offset, unsigned long nr_to_read,
unsigned long lookahead_size)
{
struct inode *inode = mapping->host;
struct page *page;
unsigned long end_index;
LIST_HEAD(page_pool);
int page_idx;
int ret = 0;
loff_t isize = i_size_read(inode);
if (isize == 0)
goto out;
end_index = ((isize - 1) >> PAGE_CACHE_SHIFT);
for (page_idx = 0; page_idx < nr_to_read; page_idx++) {
pgoff_t page_offset = offset + page_idx;
if (page_offset > end_index)
break;
rcu_read_lock();
page = radix_tree_lookup(&mapping->page_tree, page_offset);
rcu_read_unlock();
if (page && !radix_tree_exceptional_entry(page))
continue;
page = page_cache_alloc_readahead(mapping);
if (!page)
break;
page->index = page_offset;
list_add(&page->lru, &page_pool);
if (page_idx == nr_to_read - lookahead_size)
SetPageReadahead(page);
ret++;
}
if (ret)
read_pages(mapping, filp, &page_pool, ret);
BUG_ON(!list_empty(&page_pool));
out:
return ret;
}
int force_page_cache_readahead(struct address_space *mapping, struct file *filp,
pgoff_t offset, unsigned long nr_to_read)
{
if (unlikely(!mapping->a_ops->readpage && !mapping->a_ops->readpages))
return -EINVAL;
nr_to_read = min(nr_to_read, inode_to_bdi(mapping->host)->ra_pages);
while (nr_to_read) {
int err;
unsigned long this_chunk = (2 * 1024 * 1024) / PAGE_CACHE_SIZE;
if (this_chunk > nr_to_read)
this_chunk = nr_to_read;
err = __do_page_cache_readahead(mapping, filp,
offset, this_chunk, 0);
if (err < 0)
return err;
offset += this_chunk;
nr_to_read -= this_chunk;
}
return 0;
}
static unsigned long get_init_ra_size(unsigned long size, unsigned long max)
{
unsigned long newsize = roundup_pow_of_two(size);
if (newsize <= max / 32)
newsize = newsize * 4;
else if (newsize <= max / 4)
newsize = newsize * 2;
else
newsize = max;
return newsize;
}
static unsigned long get_next_ra_size(struct file_ra_state *ra,
unsigned long max)
{
unsigned long cur = ra->size;
unsigned long newsize;
if (cur < max / 16)
newsize = 4 * cur;
else
newsize = 2 * cur;
return min(newsize, max);
}
static pgoff_t count_history_pages(struct address_space *mapping,
pgoff_t offset, unsigned long max)
{
pgoff_t head;
rcu_read_lock();
head = page_cache_prev_hole(mapping, offset - 1, max);
rcu_read_unlock();
return offset - 1 - head;
}
static int try_context_readahead(struct address_space *mapping,
struct file_ra_state *ra,
pgoff_t offset,
unsigned long req_size,
unsigned long max)
{
pgoff_t size;
size = count_history_pages(mapping, offset, max);
if (size <= req_size)
return 0;
if (size >= offset)
size *= 2;
ra->start = offset;
ra->size = min(size + req_size, max);
ra->async_size = 1;
return 1;
}
static unsigned long
ondemand_readahead(struct address_space *mapping,
struct file_ra_state *ra, struct file *filp,
bool hit_readahead_marker, pgoff_t offset,
unsigned long req_size)
{
unsigned long max = ra->ra_pages;
pgoff_t prev_offset;
if (!offset)
goto initial_readahead;
if ((offset == (ra->start + ra->size - ra->async_size) ||
offset == (ra->start + ra->size))) {
ra->start += ra->size;
ra->size = get_next_ra_size(ra, max);
ra->async_size = ra->size;
goto readit;
}
if (hit_readahead_marker) {
pgoff_t start;
rcu_read_lock();
start = page_cache_next_hole(mapping, offset + 1, max);
rcu_read_unlock();
if (!start || start - offset > max)
return 0;
ra->start = start;
ra->size = start - offset;
ra->size += req_size;
ra->size = get_next_ra_size(ra, max);
ra->async_size = ra->size;
goto readit;
}
if (req_size > max)
goto initial_readahead;
prev_offset = (unsigned long long)ra->prev_pos >> PAGE_CACHE_SHIFT;
if (offset - prev_offset <= 1UL)
goto initial_readahead;
if (try_context_readahead(mapping, ra, offset, req_size, max))
goto readit;
return __do_page_cache_readahead(mapping, filp, offset, req_size, 0);
initial_readahead:
ra->start = offset;
ra->size = get_init_ra_size(req_size, max);
ra->async_size = ra->size > req_size ? ra->size - req_size : ra->size;
readit:
if (offset == ra->start && ra->size == ra->async_size) {
ra->async_size = get_next_ra_size(ra, max);
ra->size += ra->async_size;
}
return ra_submit(ra, mapping, filp);
}
void page_cache_sync_readahead(struct address_space *mapping,
struct file_ra_state *ra, struct file *filp,
pgoff_t offset, unsigned long req_size)
{
if (!ra->ra_pages)
return;
if (filp && (filp->f_mode & FMODE_RANDOM)) {
force_page_cache_readahead(mapping, filp, offset, req_size);
return;
}
ondemand_readahead(mapping, ra, filp, false, offset, req_size);
}
void
page_cache_async_readahead(struct address_space *mapping,
struct file_ra_state *ra, struct file *filp,
struct page *page, pgoff_t offset,
unsigned long req_size)
{
if (!ra->ra_pages)
return;
if (PageWriteback(page))
return;
ClearPageReadahead(page);
if (inode_read_congested(mapping->host))
return;
ondemand_readahead(mapping, ra, filp, true, offset, req_size);
}
static ssize_t
do_readahead(struct address_space *mapping, struct file *filp,
pgoff_t index, unsigned long nr)
{
if (!mapping || !mapping->a_ops)
return -EINVAL;
return force_page_cache_readahead(mapping, filp, index, nr);
}
