static inline int compressed_bio_size(struct btrfs_fs_info *fs_info,
unsigned long disk_size)
{
u16 csum_size = btrfs_super_csum_size(fs_info->super_copy);
return sizeof(struct compressed_bio) +
(DIV_ROUND_UP(disk_size, fs_info->sectorsize)) * csum_size;
}
static struct bio *compressed_bio_alloc(struct block_device *bdev,
u64 first_byte, gfp_t gfp_flags)
{
return btrfs_bio_alloc(bdev, first_byte >> 9, BIO_MAX_PAGES, gfp_flags);
}
static int check_compressed_csum(struct inode *inode,
struct compressed_bio *cb,
u64 disk_start)
{
int ret;
struct page *page;
unsigned long i;
char *kaddr;
u32 csum;
u32 *cb_sum = &cb->sums;
if (BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM)
return 0;
for (i = 0; i < cb->nr_pages; i++) {
page = cb->compressed_pages[i];
csum = ~(u32)0;
kaddr = kmap_atomic(page);
csum = btrfs_csum_data(kaddr, csum, PAGE_SIZE);
btrfs_csum_final(csum, (u8 *)&csum);
kunmap_atomic(kaddr);
if (csum != *cb_sum) {
btrfs_info(BTRFS_I(inode)->root->fs_info,
"csum failed ino %llu extent %llu csum %u wanted %u mirror %d",
btrfs_ino(inode), disk_start, csum, *cb_sum,
cb->mirror_num);
ret = -EIO;
goto fail;
}
cb_sum++;
}
ret = 0;
fail:
return ret;
}
static void end_compressed_bio_read(struct bio *bio)
{
struct compressed_bio *cb = bio->bi_private;
struct inode *inode;
struct page *page;
unsigned long index;
int ret;
if (bio->bi_error)
cb->errors = 1;
if (!atomic_dec_and_test(&cb->pending_bios))
goto out;
inode = cb->inode;
ret = check_compressed_csum(inode, cb,
(u64)bio->bi_iter.bi_sector << 9);
if (ret)
goto csum_failed;
ret = btrfs_decompress_bio(cb->compress_type,
cb->compressed_pages,
cb->start,
cb->orig_bio,
cb->compressed_len);
csum_failed:
if (ret)
cb->errors = 1;
index = 0;
for (index = 0; index < cb->nr_pages; index++) {
page = cb->compressed_pages[index];
page->mapping = NULL;
put_page(page);
}
if (cb->errors) {
bio_io_error(cb->orig_bio);
} else {
int i;
struct bio_vec *bvec;
bio_for_each_segment_all(bvec, cb->orig_bio, i)
SetPageChecked(bvec->bv_page);
bio_endio(cb->orig_bio);
}
kfree(cb->compressed_pages);
kfree(cb);
out:
bio_put(bio);
}
static noinline void end_compressed_writeback(struct inode *inode,
const struct compressed_bio *cb)
{
unsigned long index = cb->start >> PAGE_SHIFT;
unsigned long end_index = (cb->start + cb->len - 1) >> PAGE_SHIFT;
struct page *pages[16];
unsigned long nr_pages = end_index - index + 1;
int i;
int ret;
if (cb->errors)
mapping_set_error(inode->i_mapping, -EIO);
while (nr_pages > 0) {
ret = find_get_pages_contig(inode->i_mapping, index,
min_t(unsigned long,
nr_pages, ARRAY_SIZE(pages)), pages);
if (ret == 0) {
nr_pages -= 1;
index += 1;
continue;
}
for (i = 0; i < ret; i++) {
if (cb->errors)
SetPageError(pages[i]);
end_page_writeback(pages[i]);
put_page(pages[i]);
}
nr_pages -= ret;
index += ret;
}
}
static void end_compressed_bio_write(struct bio *bio)
{
struct extent_io_tree *tree;
struct compressed_bio *cb = bio->bi_private;
struct inode *inode;
struct page *page;
unsigned long index;
if (bio->bi_error)
cb->errors = 1;
if (!atomic_dec_and_test(&cb->pending_bios))
goto out;
inode = cb->inode;
tree = &BTRFS_I(inode)->io_tree;
cb->compressed_pages[0]->mapping = cb->inode->i_mapping;
tree->ops->writepage_end_io_hook(cb->compressed_pages[0],
cb->start,
cb->start + cb->len - 1,
NULL,
bio->bi_error ? 0 : 1);
cb->compressed_pages[0]->mapping = NULL;
end_compressed_writeback(inode, cb);
index = 0;
for (index = 0; index < cb->nr_pages; index++) {
page = cb->compressed_pages[index];
page->mapping = NULL;
put_page(page);
}
kfree(cb->compressed_pages);
kfree(cb);
out:
bio_put(bio);
}
int btrfs_submit_compressed_write(struct inode *inode, u64 start,
unsigned long len, u64 disk_start,
unsigned long compressed_len,
struct page **compressed_pages,
unsigned long nr_pages)
{
struct btrfs_fs_info *fs_info = btrfs_sb(inode->i_sb);
struct bio *bio = NULL;
struct compressed_bio *cb;
unsigned long bytes_left;
struct extent_io_tree *io_tree = &BTRFS_I(inode)->io_tree;
int pg_index = 0;
struct page *page;
u64 first_byte = disk_start;
struct block_device *bdev;
int ret;
int skip_sum = BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM;
WARN_ON(start & ((u64)PAGE_SIZE - 1));
cb = kmalloc(compressed_bio_size(fs_info, compressed_len), GFP_NOFS);
if (!cb)
return -ENOMEM;
atomic_set(&cb->pending_bios, 0);
cb->errors = 0;
cb->inode = inode;
cb->start = start;
cb->len = len;
cb->mirror_num = 0;
cb->compressed_pages = compressed_pages;
cb->compressed_len = compressed_len;
cb->orig_bio = NULL;
cb->nr_pages = nr_pages;
bdev = fs_info->fs_devices->latest_bdev;
bio = compressed_bio_alloc(bdev, first_byte, GFP_NOFS);
if (!bio) {
kfree(cb);
return -ENOMEM;
}
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
bio->bi_private = cb;
bio->bi_end_io = end_compressed_bio_write;
atomic_inc(&cb->pending_bios);
bytes_left = compressed_len;
for (pg_index = 0; pg_index < cb->nr_pages; pg_index++) {
page = compressed_pages[pg_index];
page->mapping = inode->i_mapping;
if (bio->bi_iter.bi_size)
ret = io_tree->ops->merge_bio_hook(page, 0,
PAGE_SIZE,
bio, 0);
else
ret = 0;
page->mapping = NULL;
if (ret || bio_add_page(bio, page, PAGE_SIZE, 0) <
PAGE_SIZE) {
bio_get(bio);
atomic_inc(&cb->pending_bios);
ret = btrfs_bio_wq_end_io(fs_info, bio,
BTRFS_WQ_ENDIO_DATA);
BUG_ON(ret);
if (!skip_sum) {
ret = btrfs_csum_one_bio(inode, bio, start, 1);
BUG_ON(ret);
}
ret = btrfs_map_bio(fs_info, bio, 0, 1);
if (ret) {
bio->bi_error = ret;
bio_endio(bio);
}
bio_put(bio);
bio = compressed_bio_alloc(bdev, first_byte, GFP_NOFS);
BUG_ON(!bio);
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
bio->bi_private = cb;
bio->bi_end_io = end_compressed_bio_write;
bio_add_page(bio, page, PAGE_SIZE, 0);
}
if (bytes_left < PAGE_SIZE) {
btrfs_info(fs_info,
"bytes left %lu compress len %lu nr %lu",
bytes_left, cb->compressed_len, cb->nr_pages);
}
bytes_left -= PAGE_SIZE;
first_byte += PAGE_SIZE;
cond_resched();
}
bio_get(bio);
ret = btrfs_bio_wq_end_io(fs_info, bio, BTRFS_WQ_ENDIO_DATA);
BUG_ON(ret);
if (!skip_sum) {
ret = btrfs_csum_one_bio(inode, bio, start, 1);
BUG_ON(ret);
}
ret = btrfs_map_bio(fs_info, bio, 0, 1);
if (ret) {
bio->bi_error = ret;
bio_endio(bio);
}
bio_put(bio);
return 0;
}
static u64 bio_end_offset(struct bio *bio)
{
struct bio_vec *last = &bio->bi_io_vec[bio->bi_vcnt - 1];
return page_offset(last->bv_page) + last->bv_len + last->bv_offset;
}
static noinline int add_ra_bio_pages(struct inode *inode,
u64 compressed_end,
struct compressed_bio *cb)
{
unsigned long end_index;
unsigned long pg_index;
u64 last_offset;
u64 isize = i_size_read(inode);
int ret;
struct page *page;
unsigned long nr_pages = 0;
struct extent_map *em;
struct address_space *mapping = inode->i_mapping;
struct extent_map_tree *em_tree;
struct extent_io_tree *tree;
u64 end;
int misses = 0;
last_offset = bio_end_offset(cb->orig_bio);
em_tree = &BTRFS_I(inode)->extent_tree;
tree = &BTRFS_I(inode)->io_tree;
if (isize == 0)
return 0;
end_index = (i_size_read(inode) - 1) >> PAGE_SHIFT;
while (last_offset < compressed_end) {
pg_index = last_offset >> PAGE_SHIFT;
if (pg_index > end_index)
break;
rcu_read_lock();
page = radix_tree_lookup(&mapping->page_tree, pg_index);
rcu_read_unlock();
if (page && !radix_tree_exceptional_entry(page)) {
misses++;
if (misses > 4)
break;
goto next;
}
page = __page_cache_alloc(mapping_gfp_constraint(mapping,
~__GFP_FS));
if (!page)
break;
if (add_to_page_cache_lru(page, mapping, pg_index, GFP_NOFS)) {
put_page(page);
goto next;
}
end = last_offset + PAGE_SIZE - 1;
set_page_extent_mapped(page);
lock_extent(tree, last_offset, end);
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, last_offset,
PAGE_SIZE);
read_unlock(&em_tree->lock);
if (!em || last_offset < em->start ||
(last_offset + PAGE_SIZE > extent_map_end(em)) ||
(em->block_start >> 9) != cb->orig_bio->bi_iter.bi_sector) {
free_extent_map(em);
unlock_extent(tree, last_offset, end);
unlock_page(page);
put_page(page);
break;
}
free_extent_map(em);
if (page->index == end_index) {
char *userpage;
size_t zero_offset = isize & (PAGE_SIZE - 1);
if (zero_offset) {
int zeros;
zeros = PAGE_SIZE - zero_offset;
userpage = kmap_atomic(page);
memset(userpage + zero_offset, 0, zeros);
flush_dcache_page(page);
kunmap_atomic(userpage);
}
}
ret = bio_add_page(cb->orig_bio, page,
PAGE_SIZE, 0);
if (ret == PAGE_SIZE) {
nr_pages++;
put_page(page);
} else {
unlock_extent(tree, last_offset, end);
unlock_page(page);
put_page(page);
break;
}
next:
last_offset += PAGE_SIZE;
}
return 0;
}
int btrfs_submit_compressed_read(struct inode *inode, struct bio *bio,
int mirror_num, unsigned long bio_flags)
{
struct btrfs_fs_info *fs_info = btrfs_sb(inode->i_sb);
struct extent_io_tree *tree;
struct extent_map_tree *em_tree;
struct compressed_bio *cb;
unsigned long compressed_len;
unsigned long nr_pages;
unsigned long pg_index;
struct page *page;
struct block_device *bdev;
struct bio *comp_bio;
u64 cur_disk_byte = (u64)bio->bi_iter.bi_sector << 9;
u64 em_len;
u64 em_start;
struct extent_map *em;
int ret = -ENOMEM;
int faili = 0;
u32 *sums;
tree = &BTRFS_I(inode)->io_tree;
em_tree = &BTRFS_I(inode)->extent_tree;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree,
page_offset(bio->bi_io_vec->bv_page),
PAGE_SIZE);
read_unlock(&em_tree->lock);
if (!em)
return -EIO;
compressed_len = em->block_len;
cb = kmalloc(compressed_bio_size(fs_info, compressed_len), GFP_NOFS);
if (!cb)
goto out;
atomic_set(&cb->pending_bios, 0);
cb->errors = 0;
cb->inode = inode;
cb->mirror_num = mirror_num;
sums = &cb->sums;
cb->start = em->orig_start;
em_len = em->len;
em_start = em->start;
free_extent_map(em);
em = NULL;
cb->len = bio->bi_iter.bi_size;
cb->compressed_len = compressed_len;
cb->compress_type = extent_compress_type(bio_flags);
cb->orig_bio = bio;
nr_pages = DIV_ROUND_UP(compressed_len, PAGE_SIZE);
cb->compressed_pages = kcalloc(nr_pages, sizeof(struct page *),
GFP_NOFS);
if (!cb->compressed_pages)
goto fail1;
bdev = fs_info->fs_devices->latest_bdev;
for (pg_index = 0; pg_index < nr_pages; pg_index++) {
cb->compressed_pages[pg_index] = alloc_page(GFP_NOFS |
__GFP_HIGHMEM);
if (!cb->compressed_pages[pg_index]) {
faili = pg_index - 1;
ret = -ENOMEM;
goto fail2;
}
}
faili = nr_pages - 1;
cb->nr_pages = nr_pages;
add_ra_bio_pages(inode, em_start + em_len, cb);
cb->len = bio->bi_iter.bi_size;
comp_bio = compressed_bio_alloc(bdev, cur_disk_byte, GFP_NOFS);
if (!comp_bio)
goto fail2;
bio_set_op_attrs (comp_bio, REQ_OP_READ, 0);
comp_bio->bi_private = cb;
comp_bio->bi_end_io = end_compressed_bio_read;
atomic_inc(&cb->pending_bios);
for (pg_index = 0; pg_index < nr_pages; pg_index++) {
page = cb->compressed_pages[pg_index];
page->mapping = inode->i_mapping;
page->index = em_start >> PAGE_SHIFT;
if (comp_bio->bi_iter.bi_size)
ret = tree->ops->merge_bio_hook(page, 0,
PAGE_SIZE,
comp_bio, 0);
else
ret = 0;
page->mapping = NULL;
if (ret || bio_add_page(comp_bio, page, PAGE_SIZE, 0) <
PAGE_SIZE) {
bio_get(comp_bio);
ret = btrfs_bio_wq_end_io(fs_info, comp_bio,
BTRFS_WQ_ENDIO_DATA);
BUG_ON(ret);
atomic_inc(&cb->pending_bios);
if (!(BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM)) {
ret = btrfs_lookup_bio_sums(inode, comp_bio,
sums);
BUG_ON(ret);
}
sums += DIV_ROUND_UP(comp_bio->bi_iter.bi_size,
fs_info->sectorsize);
ret = btrfs_map_bio(fs_info, comp_bio, mirror_num, 0);
if (ret) {
comp_bio->bi_error = ret;
bio_endio(comp_bio);
}
bio_put(comp_bio);
comp_bio = compressed_bio_alloc(bdev, cur_disk_byte,
GFP_NOFS);
BUG_ON(!comp_bio);
bio_set_op_attrs(comp_bio, REQ_OP_READ, 0);
comp_bio->bi_private = cb;
comp_bio->bi_end_io = end_compressed_bio_read;
bio_add_page(comp_bio, page, PAGE_SIZE, 0);
}
cur_disk_byte += PAGE_SIZE;
}
bio_get(comp_bio);
ret = btrfs_bio_wq_end_io(fs_info, comp_bio, BTRFS_WQ_ENDIO_DATA);
BUG_ON(ret);
if (!(BTRFS_I(inode)->flags & BTRFS_INODE_NODATASUM)) {
ret = btrfs_lookup_bio_sums(inode, comp_bio, sums);
BUG_ON(ret);
}
ret = btrfs_map_bio(fs_info, comp_bio, mirror_num, 0);
if (ret) {
comp_bio->bi_error = ret;
bio_endio(comp_bio);
}
bio_put(comp_bio);
return 0;
fail2:
while (faili >= 0) {
__free_page(cb->compressed_pages[faili]);
faili--;
}
kfree(cb->compressed_pages);
fail1:
kfree(cb);
out:
free_extent_map(em);
return ret;
}
void __init btrfs_init_compress(void)
{
int i;
for (i = 0; i < BTRFS_COMPRESS_TYPES; i++) {
struct list_head *workspace;
INIT_LIST_HEAD(&btrfs_comp_ws[i].idle_ws);
spin_lock_init(&btrfs_comp_ws[i].ws_lock);
atomic_set(&btrfs_comp_ws[i].total_ws, 0);
init_waitqueue_head(&btrfs_comp_ws[i].ws_wait);
workspace = btrfs_compress_op[i]->alloc_workspace();
if (IS_ERR(workspace)) {
pr_warn("BTRFS: cannot preallocate compression workspace, will try later\n");
} else {
atomic_set(&btrfs_comp_ws[i].total_ws, 1);
btrfs_comp_ws[i].free_ws = 1;
list_add(workspace, &btrfs_comp_ws[i].idle_ws);
}
}
}
static struct list_head *find_workspace(int type)
{
struct list_head *workspace;
int cpus = num_online_cpus();
int idx = type - 1;
struct list_head *idle_ws = &btrfs_comp_ws[idx].idle_ws;
spinlock_t *ws_lock = &btrfs_comp_ws[idx].ws_lock;
atomic_t *total_ws = &btrfs_comp_ws[idx].total_ws;
wait_queue_head_t *ws_wait = &btrfs_comp_ws[idx].ws_wait;
int *free_ws = &btrfs_comp_ws[idx].free_ws;
again:
spin_lock(ws_lock);
if (!list_empty(idle_ws)) {
workspace = idle_ws->next;
list_del(workspace);
(*free_ws)--;
spin_unlock(ws_lock);
return workspace;
}
if (atomic_read(total_ws) > cpus) {
DEFINE_WAIT(wait);
spin_unlock(ws_lock);
prepare_to_wait(ws_wait, &wait, TASK_UNINTERRUPTIBLE);
if (atomic_read(total_ws) > cpus && !*free_ws)
schedule();
finish_wait(ws_wait, &wait);
goto again;
}
atomic_inc(total_ws);
spin_unlock(ws_lock);
workspace = btrfs_compress_op[idx]->alloc_workspace();
if (IS_ERR(workspace)) {
atomic_dec(total_ws);
wake_up(ws_wait);
if (atomic_read(total_ws) == 0) {
static DEFINE_RATELIMIT_STATE(_rs,
60 * HZ,
1);
if (__ratelimit(&_rs)) {
pr_warn("BTRFS: no compression workspaces, low memory, retrying\n");
}
}
goto again;
}
return workspace;
}
static void free_workspace(int type, struct list_head *workspace)
{
int idx = type - 1;
struct list_head *idle_ws = &btrfs_comp_ws[idx].idle_ws;
spinlock_t *ws_lock = &btrfs_comp_ws[idx].ws_lock;
atomic_t *total_ws = &btrfs_comp_ws[idx].total_ws;
wait_queue_head_t *ws_wait = &btrfs_comp_ws[idx].ws_wait;
int *free_ws = &btrfs_comp_ws[idx].free_ws;
spin_lock(ws_lock);
if (*free_ws < num_online_cpus()) {
list_add(workspace, idle_ws);
(*free_ws)++;
spin_unlock(ws_lock);
goto wake;
}
spin_unlock(ws_lock);
btrfs_compress_op[idx]->free_workspace(workspace);
atomic_dec(total_ws);
wake:
smp_mb();
if (waitqueue_active(ws_wait))
wake_up(ws_wait);
}
static void free_workspaces(void)
{
struct list_head *workspace;
int i;
for (i = 0; i < BTRFS_COMPRESS_TYPES; i++) {
while (!list_empty(&btrfs_comp_ws[i].idle_ws)) {
workspace = btrfs_comp_ws[i].idle_ws.next;
list_del(workspace);
btrfs_compress_op[i]->free_workspace(workspace);
atomic_dec(&btrfs_comp_ws[i].total_ws);
}
}
}
int btrfs_compress_pages(int type, struct address_space *mapping,
u64 start, unsigned long len,
struct page **pages,
unsigned long nr_dest_pages,
unsigned long *out_pages,
unsigned long *total_in,
unsigned long *total_out,
unsigned long max_out)
{
struct list_head *workspace;
int ret;
workspace = find_workspace(type);
ret = btrfs_compress_op[type-1]->compress_pages(workspace, mapping,
start, len, pages,
nr_dest_pages, out_pages,
total_in, total_out,
max_out);
free_workspace(type, workspace);
return ret;
}
static int btrfs_decompress_bio(int type, struct page **pages_in,
u64 disk_start, struct bio *orig_bio,
size_t srclen)
{
struct list_head *workspace;
int ret;
workspace = find_workspace(type);
ret = btrfs_compress_op[type-1]->decompress_bio(workspace, pages_in,
disk_start, orig_bio,
srclen);
free_workspace(type, workspace);
return ret;
}
int btrfs_decompress(int type, unsigned char *data_in, struct page *dest_page,
unsigned long start_byte, size_t srclen, size_t destlen)
{
struct list_head *workspace;
int ret;
workspace = find_workspace(type);
ret = btrfs_compress_op[type-1]->decompress(workspace, data_in,
dest_page, start_byte,
srclen, destlen);
free_workspace(type, workspace);
return ret;
}
void btrfs_exit_compress(void)
{
free_workspaces();
}
int btrfs_decompress_buf2page(char *buf, unsigned long buf_start,
unsigned long total_out, u64 disk_start,
struct bio *bio)
{
unsigned long buf_offset;
unsigned long current_buf_start;
unsigned long start_byte;
unsigned long prev_start_byte;
unsigned long working_bytes = total_out - buf_start;
unsigned long bytes;
char *kaddr;
struct bio_vec bvec = bio_iter_iovec(bio, bio->bi_iter);
start_byte = page_offset(bvec.bv_page) - disk_start;
if (total_out <= start_byte)
return 1;
if (total_out > start_byte && buf_start < start_byte) {
buf_offset = start_byte - buf_start;
working_bytes -= buf_offset;
} else {
buf_offset = 0;
}
current_buf_start = buf_start;
while (working_bytes > 0) {
bytes = min_t(unsigned long, bvec.bv_len,
PAGE_SIZE - buf_offset);
bytes = min(bytes, working_bytes);
kaddr = kmap_atomic(bvec.bv_page);
memcpy(kaddr + bvec.bv_offset, buf + buf_offset, bytes);
kunmap_atomic(kaddr);
flush_dcache_page(bvec.bv_page);
buf_offset += bytes;
working_bytes -= bytes;
current_buf_start += bytes;
bio_advance(bio, bytes);
if (!bio->bi_iter.bi_size)
return 0;
bvec = bio_iter_iovec(bio, bio->bi_iter);
prev_start_byte = start_byte;
start_byte = page_offset(bvec.bv_page) - disk_start;
if (start_byte != prev_start_byte) {
if (total_out <= start_byte)
return 1;
if (total_out > start_byte &&
current_buf_start < start_byte) {
buf_offset = start_byte - buf_start;
working_bytes = total_out - start_byte;
current_buf_start = buf_start + buf_offset;
}
}
}
return 1;
}
