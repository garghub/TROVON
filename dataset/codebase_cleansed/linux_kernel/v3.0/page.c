static struct buffer_head *
__nilfs_get_page_block(struct page *page, unsigned long block, pgoff_t index,
int blkbits, unsigned long b_state)
{
unsigned long first_block;
struct buffer_head *bh;
if (!page_has_buffers(page))
create_empty_buffers(page, 1 << blkbits, b_state);
first_block = (unsigned long)index << (PAGE_CACHE_SHIFT - blkbits);
bh = nilfs_page_get_nth_block(page, block - first_block);
touch_buffer(bh);
wait_on_buffer(bh);
return bh;
}
struct buffer_head *nilfs_grab_buffer(struct inode *inode,
struct address_space *mapping,
unsigned long blkoff,
unsigned long b_state)
{
int blkbits = inode->i_blkbits;
pgoff_t index = blkoff >> (PAGE_CACHE_SHIFT - blkbits);
struct page *page;
struct buffer_head *bh;
page = grab_cache_page(mapping, index);
if (unlikely(!page))
return NULL;
bh = __nilfs_get_page_block(page, blkoff, index, blkbits, b_state);
if (unlikely(!bh)) {
unlock_page(page);
page_cache_release(page);
return NULL;
}
return bh;
}
void nilfs_forget_buffer(struct buffer_head *bh)
{
struct page *page = bh->b_page;
lock_buffer(bh);
clear_buffer_nilfs_volatile(bh);
clear_buffer_nilfs_checked(bh);
clear_buffer_nilfs_redirected(bh);
clear_buffer_dirty(bh);
if (nilfs_page_buffers_clean(page))
__nilfs_clear_page_dirty(page);
clear_buffer_uptodate(bh);
clear_buffer_mapped(bh);
bh->b_blocknr = -1;
ClearPageUptodate(page);
ClearPageMappedToDisk(page);
unlock_buffer(bh);
brelse(bh);
}
void nilfs_copy_buffer(struct buffer_head *dbh, struct buffer_head *sbh)
{
void *kaddr0, *kaddr1;
unsigned long bits;
struct page *spage = sbh->b_page, *dpage = dbh->b_page;
struct buffer_head *bh;
kaddr0 = kmap_atomic(spage, KM_USER0);
kaddr1 = kmap_atomic(dpage, KM_USER1);
memcpy(kaddr1 + bh_offset(dbh), kaddr0 + bh_offset(sbh), sbh->b_size);
kunmap_atomic(kaddr1, KM_USER1);
kunmap_atomic(kaddr0, KM_USER0);
dbh->b_state = sbh->b_state & NILFS_BUFFER_INHERENT_BITS;
dbh->b_blocknr = sbh->b_blocknr;
dbh->b_bdev = sbh->b_bdev;
bh = dbh;
bits = sbh->b_state & ((1UL << BH_Uptodate) | (1UL << BH_Mapped));
while ((bh = bh->b_this_page) != dbh) {
lock_buffer(bh);
bits &= bh->b_state;
unlock_buffer(bh);
}
if (bits & (1UL << BH_Uptodate))
SetPageUptodate(dpage);
else
ClearPageUptodate(dpage);
if (bits & (1UL << BH_Mapped))
SetPageMappedToDisk(dpage);
else
ClearPageMappedToDisk(dpage);
}
int nilfs_page_buffers_clean(struct page *page)
{
struct buffer_head *bh, *head;
bh = head = page_buffers(page);
do {
if (buffer_dirty(bh))
return 0;
bh = bh->b_this_page;
} while (bh != head);
return 1;
}
void nilfs_page_bug(struct page *page)
{
struct address_space *m;
unsigned long ino;
if (unlikely(!page)) {
printk(KERN_CRIT "NILFS_PAGE_BUG(NULL)\n");
return;
}
m = page->mapping;
ino = m ? m->host->i_ino : 0;
printk(KERN_CRIT "NILFS_PAGE_BUG(%p): cnt=%d index#=%llu flags=0x%lx "
"mapping=%p ino=%lu\n",
page, atomic_read(&page->_count),
(unsigned long long)page->index, page->flags, m, ino);
if (page_has_buffers(page)) {
struct buffer_head *bh, *head;
int i = 0;
bh = head = page_buffers(page);
do {
printk(KERN_CRIT
" BH[%d] %p: cnt=%d block#=%llu state=0x%lx\n",
i++, bh, atomic_read(&bh->b_count),
(unsigned long long)bh->b_blocknr, bh->b_state);
bh = bh->b_this_page;
} while (bh != head);
}
}
static void nilfs_copy_page(struct page *dst, struct page *src, int copy_dirty)
{
struct buffer_head *dbh, *dbufs, *sbh, *sbufs;
unsigned long mask = NILFS_BUFFER_INHERENT_BITS;
BUG_ON(PageWriteback(dst));
sbh = sbufs = page_buffers(src);
if (!page_has_buffers(dst))
create_empty_buffers(dst, sbh->b_size, 0);
if (copy_dirty)
mask |= (1UL << BH_Dirty);
dbh = dbufs = page_buffers(dst);
do {
lock_buffer(sbh);
lock_buffer(dbh);
dbh->b_state = sbh->b_state & mask;
dbh->b_blocknr = sbh->b_blocknr;
dbh->b_bdev = sbh->b_bdev;
sbh = sbh->b_this_page;
dbh = dbh->b_this_page;
} while (dbh != dbufs);
copy_highpage(dst, src);
if (PageUptodate(src) && !PageUptodate(dst))
SetPageUptodate(dst);
else if (!PageUptodate(src) && PageUptodate(dst))
ClearPageUptodate(dst);
if (PageMappedToDisk(src) && !PageMappedToDisk(dst))
SetPageMappedToDisk(dst);
else if (!PageMappedToDisk(src) && PageMappedToDisk(dst))
ClearPageMappedToDisk(dst);
do {
unlock_buffer(sbh);
unlock_buffer(dbh);
sbh = sbh->b_this_page;
dbh = dbh->b_this_page;
} while (dbh != dbufs);
}
int nilfs_copy_dirty_pages(struct address_space *dmap,
struct address_space *smap)
{
struct pagevec pvec;
unsigned int i;
pgoff_t index = 0;
int err = 0;
pagevec_init(&pvec, 0);
repeat:
if (!pagevec_lookup_tag(&pvec, smap, &index, PAGECACHE_TAG_DIRTY,
PAGEVEC_SIZE))
return 0;
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i], *dpage;
lock_page(page);
if (unlikely(!PageDirty(page)))
NILFS_PAGE_BUG(page, "inconsistent dirty state");
dpage = grab_cache_page(dmap, page->index);
if (unlikely(!dpage)) {
err = -ENOMEM;
unlock_page(page);
break;
}
if (unlikely(!page_has_buffers(page)))
NILFS_PAGE_BUG(page,
"found empty page in dat page cache");
nilfs_copy_page(dpage, page, 1);
__set_page_dirty_nobuffers(dpage);
unlock_page(dpage);
page_cache_release(dpage);
unlock_page(page);
}
pagevec_release(&pvec);
cond_resched();
if (likely(!err))
goto repeat;
return err;
}
void nilfs_copy_back_pages(struct address_space *dmap,
struct address_space *smap)
{
struct pagevec pvec;
unsigned int i, n;
pgoff_t index = 0;
int err;
pagevec_init(&pvec, 0);
repeat:
n = pagevec_lookup(&pvec, smap, index, PAGEVEC_SIZE);
if (!n)
return;
index = pvec.pages[n - 1]->index + 1;
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i], *dpage;
pgoff_t offset = page->index;
lock_page(page);
dpage = find_lock_page(dmap, offset);
if (dpage) {
WARN_ON(PageDirty(dpage));
nilfs_copy_page(dpage, page, 0);
unlock_page(dpage);
page_cache_release(dpage);
} else {
struct page *page2;
spin_lock_irq(&smap->tree_lock);
page2 = radix_tree_delete(&smap->page_tree, offset);
WARN_ON(page2 != page);
smap->nrpages--;
spin_unlock_irq(&smap->tree_lock);
spin_lock_irq(&dmap->tree_lock);
err = radix_tree_insert(&dmap->page_tree, offset, page);
if (unlikely(err < 0)) {
WARN_ON(err == -EEXIST);
page->mapping = NULL;
page_cache_release(page);
} else {
page->mapping = dmap;
dmap->nrpages++;
if (PageDirty(page))
radix_tree_tag_set(&dmap->page_tree,
offset,
PAGECACHE_TAG_DIRTY);
}
spin_unlock_irq(&dmap->tree_lock);
}
unlock_page(page);
}
pagevec_release(&pvec);
cond_resched();
goto repeat;
}
void nilfs_clear_dirty_pages(struct address_space *mapping)
{
struct pagevec pvec;
unsigned int i;
pgoff_t index = 0;
pagevec_init(&pvec, 0);
while (pagevec_lookup_tag(&pvec, mapping, &index, PAGECACHE_TAG_DIRTY,
PAGEVEC_SIZE)) {
for (i = 0; i < pagevec_count(&pvec); i++) {
struct page *page = pvec.pages[i];
struct buffer_head *bh, *head;
lock_page(page);
ClearPageUptodate(page);
ClearPageMappedToDisk(page);
bh = head = page_buffers(page);
do {
lock_buffer(bh);
clear_buffer_dirty(bh);
clear_buffer_nilfs_volatile(bh);
clear_buffer_nilfs_checked(bh);
clear_buffer_nilfs_redirected(bh);
clear_buffer_uptodate(bh);
clear_buffer_mapped(bh);
unlock_buffer(bh);
bh = bh->b_this_page;
} while (bh != head);
__nilfs_clear_page_dirty(page);
unlock_page(page);
}
pagevec_release(&pvec);
cond_resched();
}
}
unsigned nilfs_page_count_clean_buffers(struct page *page,
unsigned from, unsigned to)
{
unsigned block_start, block_end;
struct buffer_head *bh, *head;
unsigned nc = 0;
for (bh = head = page_buffers(page), block_start = 0;
bh != head || !block_start;
block_start = block_end, bh = bh->b_this_page) {
block_end = block_start + bh->b_size;
if (block_end > from && block_start < to && !buffer_dirty(bh))
nc++;
}
return nc;
}
void nilfs_mapping_init(struct address_space *mapping, struct inode *inode,
struct backing_dev_info *bdi)
{
mapping->host = inode;
mapping->flags = 0;
mapping_set_gfp_mask(mapping, GFP_NOFS);
mapping->assoc_mapping = NULL;
mapping->backing_dev_info = bdi;
mapping->a_ops = &empty_aops;
}
int __nilfs_clear_page_dirty(struct page *page)
{
struct address_space *mapping = page->mapping;
if (mapping) {
spin_lock_irq(&mapping->tree_lock);
if (test_bit(PG_dirty, &page->flags)) {
radix_tree_tag_clear(&mapping->page_tree,
page_index(page),
PAGECACHE_TAG_DIRTY);
spin_unlock_irq(&mapping->tree_lock);
return clear_page_dirty_for_io(page);
}
spin_unlock_irq(&mapping->tree_lock);
return 0;
}
return TestClearPageDirty(page);
}
unsigned long nilfs_find_uncommitted_extent(struct inode *inode,
sector_t start_blk,
sector_t *blkoff)
{
unsigned int i;
pgoff_t index;
unsigned int nblocks_in_page;
unsigned long length = 0;
sector_t b;
struct pagevec pvec;
struct page *page;
if (inode->i_mapping->nrpages == 0)
return 0;
index = start_blk >> (PAGE_CACHE_SHIFT - inode->i_blkbits);
nblocks_in_page = 1U << (PAGE_CACHE_SHIFT - inode->i_blkbits);
pagevec_init(&pvec, 0);
repeat:
pvec.nr = find_get_pages_contig(inode->i_mapping, index, PAGEVEC_SIZE,
pvec.pages);
if (pvec.nr == 0)
return length;
if (length > 0 && pvec.pages[0]->index > index)
goto out;
b = pvec.pages[0]->index << (PAGE_CACHE_SHIFT - inode->i_blkbits);
i = 0;
do {
page = pvec.pages[i];
lock_page(page);
if (page_has_buffers(page)) {
struct buffer_head *bh, *head;
bh = head = page_buffers(page);
do {
if (b < start_blk)
continue;
if (buffer_delay(bh)) {
if (length == 0)
*blkoff = b;
length++;
} else if (length > 0) {
goto out_locked;
}
} while (++b, bh = bh->b_this_page, bh != head);
} else {
if (length > 0)
goto out_locked;
b += nblocks_in_page;
}
unlock_page(page);
} while (++i < pagevec_count(&pvec));
index = page->index + 1;
pagevec_release(&pvec);
cond_resched();
goto repeat;
out_locked:
unlock_page(page);
out:
pagevec_release(&pvec);
return length;
}
