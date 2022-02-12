static void completion_pages(struct work_struct *work)
{
#ifdef CONFIG_EXT4_FS_ENCRYPTION
struct ext4_crypto_ctx *ctx =
container_of(work, struct ext4_crypto_ctx, r.work);
struct bio *bio = ctx->r.bio;
struct bio_vec *bv;
int i;
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
int ret = ext4_decrypt(ctx, page);
if (ret) {
WARN_ON_ONCE(1);
SetPageError(page);
} else
SetPageUptodate(page);
unlock_page(page);
}
ext4_release_crypto_ctx(ctx);
bio_put(bio);
#else
BUG();
#endif
}
static inline bool ext4_bio_encrypted(struct bio *bio)
{
#ifdef CONFIG_EXT4_FS_ENCRYPTION
return unlikely(bio->bi_private != NULL);
#else
return false;
#endif
}
static void mpage_end_io(struct bio *bio, int err)
{
struct bio_vec *bv;
int i;
if (ext4_bio_encrypted(bio)) {
struct ext4_crypto_ctx *ctx = bio->bi_private;
if (err) {
ext4_release_crypto_ctx(ctx);
} else {
INIT_WORK(&ctx->r.work, completion_pages);
ctx->r.bio = bio;
queue_work(ext4_read_workqueue, &ctx->r.work);
return;
}
}
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
if (!err) {
SetPageUptodate(page);
} else {
ClearPageUptodate(page);
SetPageError(page);
}
unlock_page(page);
}
bio_put(bio);
}
int ext4_mpage_readpages(struct address_space *mapping,
struct list_head *pages, struct page *page,
unsigned nr_pages)
{
struct bio *bio = NULL;
unsigned page_idx;
sector_t last_block_in_bio = 0;
struct inode *inode = mapping->host;
const unsigned blkbits = inode->i_blkbits;
const unsigned blocks_per_page = PAGE_CACHE_SIZE >> blkbits;
const unsigned blocksize = 1 << blkbits;
sector_t block_in_file;
sector_t last_block;
sector_t last_block_in_file;
sector_t blocks[MAX_BUF_PER_PAGE];
unsigned page_block;
struct block_device *bdev = inode->i_sb->s_bdev;
int length;
unsigned relative_block = 0;
struct ext4_map_blocks map;
map.m_pblk = 0;
map.m_lblk = 0;
map.m_len = 0;
map.m_flags = 0;
for (page_idx = 0; nr_pages; page_idx++, nr_pages--) {
int fully_mapped = 1;
unsigned first_hole = blocks_per_page;
prefetchw(&page->flags);
if (pages) {
page = list_entry(pages->prev, struct page, lru);
list_del(&page->lru);
if (add_to_page_cache_lru(page, mapping,
page->index, GFP_KERNEL))
goto next_page;
}
if (page_has_buffers(page))
goto confused;
block_in_file = (sector_t)page->index << (PAGE_CACHE_SHIFT - blkbits);
last_block = block_in_file + nr_pages * blocks_per_page;
last_block_in_file = (i_size_read(inode) + blocksize - 1) >> blkbits;
if (last_block > last_block_in_file)
last_block = last_block_in_file;
page_block = 0;
if ((map.m_flags & EXT4_MAP_MAPPED) &&
block_in_file > map.m_lblk &&
block_in_file < (map.m_lblk + map.m_len)) {
unsigned map_offset = block_in_file - map.m_lblk;
unsigned last = map.m_len - map_offset;
for (relative_block = 0; ; relative_block++) {
if (relative_block == last) {
map.m_flags &= ~EXT4_MAP_MAPPED;
break;
}
if (page_block == blocks_per_page)
break;
blocks[page_block] = map.m_pblk + map_offset +
relative_block;
page_block++;
block_in_file++;
}
}
while (page_block < blocks_per_page) {
if (block_in_file < last_block) {
map.m_lblk = block_in_file;
map.m_len = last_block - block_in_file;
if (ext4_map_blocks(NULL, inode, &map, 0) < 0) {
set_error_page:
SetPageError(page);
zero_user_segment(page, 0,
PAGE_CACHE_SIZE);
unlock_page(page);
goto next_page;
}
}
if ((map.m_flags & EXT4_MAP_MAPPED) == 0) {
fully_mapped = 0;
if (first_hole == blocks_per_page)
first_hole = page_block;
page_block++;
block_in_file++;
continue;
}
if (first_hole != blocks_per_page)
goto confused;
if (page_block && blocks[page_block-1] != map.m_pblk-1)
goto confused;
for (relative_block = 0; ; relative_block++) {
if (relative_block == map.m_len) {
map.m_flags &= ~EXT4_MAP_MAPPED;
break;
} else if (page_block == blocks_per_page)
break;
blocks[page_block] = map.m_pblk+relative_block;
page_block++;
block_in_file++;
}
}
if (first_hole != blocks_per_page) {
zero_user_segment(page, first_hole << blkbits,
PAGE_CACHE_SIZE);
if (first_hole == 0) {
SetPageUptodate(page);
unlock_page(page);
goto next_page;
}
} else if (fully_mapped) {
SetPageMappedToDisk(page);
}
if (fully_mapped && blocks_per_page == 1 &&
!PageUptodate(page) && cleancache_get_page(page) == 0) {
SetPageUptodate(page);
goto confused;
}
if (bio && (last_block_in_bio != blocks[0] - 1)) {
submit_and_realloc:
submit_bio(READ, bio);
bio = NULL;
}
if (bio == NULL) {
struct ext4_crypto_ctx *ctx = NULL;
if (ext4_encrypted_inode(inode) &&
S_ISREG(inode->i_mode)) {
ctx = ext4_get_crypto_ctx(inode);
if (IS_ERR(ctx))
goto set_error_page;
}
bio = bio_alloc(GFP_KERNEL,
min_t(int, nr_pages, bio_get_nr_vecs(bdev)));
if (!bio) {
if (ctx)
ext4_release_crypto_ctx(ctx);
goto set_error_page;
}
bio->bi_bdev = bdev;
bio->bi_iter.bi_sector = blocks[0] << (blkbits - 9);
bio->bi_end_io = mpage_end_io;
bio->bi_private = ctx;
}
length = first_hole << blkbits;
if (bio_add_page(bio, page, length, 0) < length)
goto submit_and_realloc;
if (((map.m_flags & EXT4_MAP_BOUNDARY) &&
(relative_block == map.m_len)) ||
(first_hole != blocks_per_page)) {
submit_bio(READ, bio);
bio = NULL;
} else
last_block_in_bio = blocks[blocks_per_page - 1];
goto next_page;
confused:
if (bio) {
submit_bio(READ, bio);
bio = NULL;
}
if (!PageUptodate(page))
block_read_full_page(page, ext4_get_block);
else
unlock_page(page);
next_page:
if (pages)
page_cache_release(page);
}
BUG_ON(pages && !list_empty(pages));
if (bio)
submit_bio(READ, bio);
return 0;
}
