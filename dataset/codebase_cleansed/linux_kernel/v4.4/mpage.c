static void mpage_end_io(struct bio *bio)
{
struct bio_vec *bv;
int i;
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
page_endio(page, bio_data_dir(bio), bio->bi_error);
}
bio_put(bio);
}
static struct bio *mpage_bio_submit(int rw, struct bio *bio)
{
bio->bi_end_io = mpage_end_io;
guard_bio_eod(rw, bio);
submit_bio(rw, bio);
return NULL;
}
static struct bio *
mpage_alloc(struct block_device *bdev,
sector_t first_sector, int nr_vecs,
gfp_t gfp_flags)
{
struct bio *bio;
bio = bio_alloc(gfp_flags, nr_vecs);
if (bio == NULL && (current->flags & PF_MEMALLOC)) {
while (!bio && (nr_vecs /= 2))
bio = bio_alloc(gfp_flags, nr_vecs);
}
if (bio) {
bio->bi_bdev = bdev;
bio->bi_iter.bi_sector = first_sector;
}
return bio;
}
static void
map_buffer_to_page(struct page *page, struct buffer_head *bh, int page_block)
{
struct inode *inode = page->mapping->host;
struct buffer_head *page_bh, *head;
int block = 0;
if (!page_has_buffers(page)) {
if (inode->i_blkbits == PAGE_CACHE_SHIFT &&
buffer_uptodate(bh)) {
SetPageUptodate(page);
return;
}
create_empty_buffers(page, 1 << inode->i_blkbits, 0);
}
head = page_buffers(page);
page_bh = head;
do {
if (block == page_block) {
page_bh->b_state = bh->b_state;
page_bh->b_bdev = bh->b_bdev;
page_bh->b_blocknr = bh->b_blocknr;
break;
}
page_bh = page_bh->b_this_page;
block++;
} while (page_bh != head);
}
static struct bio *
do_mpage_readpage(struct bio *bio, struct page *page, unsigned nr_pages,
sector_t *last_block_in_bio, struct buffer_head *map_bh,
unsigned long *first_logical_block, get_block_t get_block,
gfp_t gfp)
{
struct inode *inode = page->mapping->host;
const unsigned blkbits = inode->i_blkbits;
const unsigned blocks_per_page = PAGE_CACHE_SIZE >> blkbits;
const unsigned blocksize = 1 << blkbits;
sector_t block_in_file;
sector_t last_block;
sector_t last_block_in_file;
sector_t blocks[MAX_BUF_PER_PAGE];
unsigned page_block;
unsigned first_hole = blocks_per_page;
struct block_device *bdev = NULL;
int length;
int fully_mapped = 1;
unsigned nblocks;
unsigned relative_block;
if (page_has_buffers(page))
goto confused;
block_in_file = (sector_t)page->index << (PAGE_CACHE_SHIFT - blkbits);
last_block = block_in_file + nr_pages * blocks_per_page;
last_block_in_file = (i_size_read(inode) + blocksize - 1) >> blkbits;
if (last_block > last_block_in_file)
last_block = last_block_in_file;
page_block = 0;
nblocks = map_bh->b_size >> blkbits;
if (buffer_mapped(map_bh) && block_in_file > *first_logical_block &&
block_in_file < (*first_logical_block + nblocks)) {
unsigned map_offset = block_in_file - *first_logical_block;
unsigned last = nblocks - map_offset;
for (relative_block = 0; ; relative_block++) {
if (relative_block == last) {
clear_buffer_mapped(map_bh);
break;
}
if (page_block == blocks_per_page)
break;
blocks[page_block] = map_bh->b_blocknr + map_offset +
relative_block;
page_block++;
block_in_file++;
}
bdev = map_bh->b_bdev;
}
map_bh->b_page = page;
while (page_block < blocks_per_page) {
map_bh->b_state = 0;
map_bh->b_size = 0;
if (block_in_file < last_block) {
map_bh->b_size = (last_block-block_in_file) << blkbits;
if (get_block(inode, block_in_file, map_bh, 0))
goto confused;
*first_logical_block = block_in_file;
}
if (!buffer_mapped(map_bh)) {
fully_mapped = 0;
if (first_hole == blocks_per_page)
first_hole = page_block;
page_block++;
block_in_file++;
continue;
}
if (buffer_uptodate(map_bh)) {
map_buffer_to_page(page, map_bh, page_block);
goto confused;
}
if (first_hole != blocks_per_page)
goto confused;
if (page_block && blocks[page_block-1] != map_bh->b_blocknr-1)
goto confused;
nblocks = map_bh->b_size >> blkbits;
for (relative_block = 0; ; relative_block++) {
if (relative_block == nblocks) {
clear_buffer_mapped(map_bh);
break;
} else if (page_block == blocks_per_page)
break;
blocks[page_block] = map_bh->b_blocknr+relative_block;
page_block++;
block_in_file++;
}
bdev = map_bh->b_bdev;
}
if (first_hole != blocks_per_page) {
zero_user_segment(page, first_hole << blkbits, PAGE_CACHE_SIZE);
if (first_hole == 0) {
SetPageUptodate(page);
unlock_page(page);
goto out;
}
} else if (fully_mapped) {
SetPageMappedToDisk(page);
}
if (fully_mapped && blocks_per_page == 1 && !PageUptodate(page) &&
cleancache_get_page(page) == 0) {
SetPageUptodate(page);
goto confused;
}
if (bio && (*last_block_in_bio != blocks[0] - 1))
bio = mpage_bio_submit(READ, bio);
alloc_new:
if (bio == NULL) {
if (first_hole == blocks_per_page) {
if (!bdev_read_page(bdev, blocks[0] << (blkbits - 9),
page))
goto out;
}
bio = mpage_alloc(bdev, blocks[0] << (blkbits - 9),
min_t(int, nr_pages, BIO_MAX_PAGES), gfp);
if (bio == NULL)
goto confused;
}
length = first_hole << blkbits;
if (bio_add_page(bio, page, length, 0) < length) {
bio = mpage_bio_submit(READ, bio);
goto alloc_new;
}
relative_block = block_in_file - *first_logical_block;
nblocks = map_bh->b_size >> blkbits;
if ((buffer_boundary(map_bh) && relative_block == nblocks) ||
(first_hole != blocks_per_page))
bio = mpage_bio_submit(READ, bio);
else
*last_block_in_bio = blocks[blocks_per_page - 1];
out:
return bio;
confused:
if (bio)
bio = mpage_bio_submit(READ, bio);
if (!PageUptodate(page))
block_read_full_page(page, get_block);
else
unlock_page(page);
goto out;
}
int
mpage_readpages(struct address_space *mapping, struct list_head *pages,
unsigned nr_pages, get_block_t get_block)
{
struct bio *bio = NULL;
unsigned page_idx;
sector_t last_block_in_bio = 0;
struct buffer_head map_bh;
unsigned long first_logical_block = 0;
gfp_t gfp = mapping_gfp_constraint(mapping, GFP_KERNEL);
map_bh.b_state = 0;
map_bh.b_size = 0;
for (page_idx = 0; page_idx < nr_pages; page_idx++) {
struct page *page = list_entry(pages->prev, struct page, lru);
prefetchw(&page->flags);
list_del(&page->lru);
if (!add_to_page_cache_lru(page, mapping,
page->index,
gfp)) {
bio = do_mpage_readpage(bio, page,
nr_pages - page_idx,
&last_block_in_bio, &map_bh,
&first_logical_block,
get_block, gfp);
}
page_cache_release(page);
}
BUG_ON(!list_empty(pages));
if (bio)
mpage_bio_submit(READ, bio);
return 0;
}
int mpage_readpage(struct page *page, get_block_t get_block)
{
struct bio *bio = NULL;
sector_t last_block_in_bio = 0;
struct buffer_head map_bh;
unsigned long first_logical_block = 0;
gfp_t gfp = mapping_gfp_constraint(page->mapping, GFP_KERNEL);
map_bh.b_state = 0;
map_bh.b_size = 0;
bio = do_mpage_readpage(bio, page, 1, &last_block_in_bio,
&map_bh, &first_logical_block, get_block, gfp);
if (bio)
mpage_bio_submit(READ, bio);
return 0;
}
static void clean_buffers(struct page *page, unsigned first_unmapped)
{
unsigned buffer_counter = 0;
struct buffer_head *bh, *head;
if (!page_has_buffers(page))
return;
head = page_buffers(page);
bh = head;
do {
if (buffer_counter++ == first_unmapped)
break;
clear_buffer_dirty(bh);
bh = bh->b_this_page;
} while (bh != head);
if (buffer_heads_over_limit && PageUptodate(page))
try_to_free_buffers(page);
}
static int __mpage_writepage(struct page *page, struct writeback_control *wbc,
void *data)
{
struct mpage_data *mpd = data;
struct bio *bio = mpd->bio;
struct address_space *mapping = page->mapping;
struct inode *inode = page->mapping->host;
const unsigned blkbits = inode->i_blkbits;
unsigned long end_index;
const unsigned blocks_per_page = PAGE_CACHE_SIZE >> blkbits;
sector_t last_block;
sector_t block_in_file;
sector_t blocks[MAX_BUF_PER_PAGE];
unsigned page_block;
unsigned first_unmapped = blocks_per_page;
struct block_device *bdev = NULL;
int boundary = 0;
sector_t boundary_block = 0;
struct block_device *boundary_bdev = NULL;
int length;
struct buffer_head map_bh;
loff_t i_size = i_size_read(inode);
int ret = 0;
int wr = (wbc->sync_mode == WB_SYNC_ALL ? WRITE_SYNC : WRITE);
if (page_has_buffers(page)) {
struct buffer_head *head = page_buffers(page);
struct buffer_head *bh = head;
page_block = 0;
do {
BUG_ON(buffer_locked(bh));
if (!buffer_mapped(bh)) {
if (buffer_dirty(bh))
goto confused;
if (first_unmapped == blocks_per_page)
first_unmapped = page_block;
continue;
}
if (first_unmapped != blocks_per_page)
goto confused;
if (!buffer_dirty(bh) || !buffer_uptodate(bh))
goto confused;
if (page_block) {
if (bh->b_blocknr != blocks[page_block-1] + 1)
goto confused;
}
blocks[page_block++] = bh->b_blocknr;
boundary = buffer_boundary(bh);
if (boundary) {
boundary_block = bh->b_blocknr;
boundary_bdev = bh->b_bdev;
}
bdev = bh->b_bdev;
} while ((bh = bh->b_this_page) != head);
if (first_unmapped)
goto page_is_mapped;
goto confused;
}
BUG_ON(!PageUptodate(page));
block_in_file = (sector_t)page->index << (PAGE_CACHE_SHIFT - blkbits);
last_block = (i_size - 1) >> blkbits;
map_bh.b_page = page;
for (page_block = 0; page_block < blocks_per_page; ) {
map_bh.b_state = 0;
map_bh.b_size = 1 << blkbits;
if (mpd->get_block(inode, block_in_file, &map_bh, 1))
goto confused;
if (buffer_new(&map_bh))
unmap_underlying_metadata(map_bh.b_bdev,
map_bh.b_blocknr);
if (buffer_boundary(&map_bh)) {
boundary_block = map_bh.b_blocknr;
boundary_bdev = map_bh.b_bdev;
}
if (page_block) {
if (map_bh.b_blocknr != blocks[page_block-1] + 1)
goto confused;
}
blocks[page_block++] = map_bh.b_blocknr;
boundary = buffer_boundary(&map_bh);
bdev = map_bh.b_bdev;
if (block_in_file == last_block)
break;
block_in_file++;
}
BUG_ON(page_block == 0);
first_unmapped = page_block;
page_is_mapped:
end_index = i_size >> PAGE_CACHE_SHIFT;
if (page->index >= end_index) {
unsigned offset = i_size & (PAGE_CACHE_SIZE - 1);
if (page->index > end_index || !offset)
goto confused;
zero_user_segment(page, offset, PAGE_CACHE_SIZE);
}
if (bio && mpd->last_block_in_bio != blocks[0] - 1)
bio = mpage_bio_submit(wr, bio);
alloc_new:
if (bio == NULL) {
if (first_unmapped == blocks_per_page) {
if (!bdev_write_page(bdev, blocks[0] << (blkbits - 9),
page, wbc)) {
clean_buffers(page, first_unmapped);
goto out;
}
}
bio = mpage_alloc(bdev, blocks[0] << (blkbits - 9),
BIO_MAX_PAGES, GFP_NOFS|__GFP_HIGH);
if (bio == NULL)
goto confused;
wbc_init_bio(wbc, bio);
}
wbc_account_io(wbc, page, PAGE_SIZE);
length = first_unmapped << blkbits;
if (bio_add_page(bio, page, length, 0) < length) {
bio = mpage_bio_submit(wr, bio);
goto alloc_new;
}
clean_buffers(page, first_unmapped);
BUG_ON(PageWriteback(page));
set_page_writeback(page);
unlock_page(page);
if (boundary || (first_unmapped != blocks_per_page)) {
bio = mpage_bio_submit(wr, bio);
if (boundary_block) {
write_boundary_block(boundary_bdev,
boundary_block, 1 << blkbits);
}
} else {
mpd->last_block_in_bio = blocks[blocks_per_page - 1];
}
goto out;
confused:
if (bio)
bio = mpage_bio_submit(wr, bio);
if (mpd->use_writepage) {
ret = mapping->a_ops->writepage(page, wbc);
} else {
ret = -EAGAIN;
goto out;
}
mapping_set_error(mapping, ret);
out:
mpd->bio = bio;
return ret;
}
int
mpage_writepages(struct address_space *mapping,
struct writeback_control *wbc, get_block_t get_block)
{
struct blk_plug plug;
int ret;
blk_start_plug(&plug);
if (!get_block)
ret = generic_writepages(mapping, wbc);
else {
struct mpage_data mpd = {
.bio = NULL,
.last_block_in_bio = 0,
.get_block = get_block,
.use_writepage = 1,
};
ret = write_cache_pages(mapping, wbc, __mpage_writepage, &mpd);
if (mpd.bio) {
int wr = (wbc->sync_mode == WB_SYNC_ALL ?
WRITE_SYNC : WRITE);
mpage_bio_submit(wr, mpd.bio);
}
}
blk_finish_plug(&plug);
return ret;
}
int mpage_writepage(struct page *page, get_block_t get_block,
struct writeback_control *wbc)
{
struct mpage_data mpd = {
.bio = NULL,
.last_block_in_bio = 0,
.get_block = get_block,
.use_writepage = 0,
};
int ret = __mpage_writepage(page, wbc, &mpd);
if (mpd.bio) {
int wr = (wbc->sync_mode == WB_SYNC_ALL ?
WRITE_SYNC : WRITE);
mpage_bio_submit(wr, mpd.bio);
}
return ret;
}
