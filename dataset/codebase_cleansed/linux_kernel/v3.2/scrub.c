static void scrub_free_csums(struct scrub_dev *sdev)
{
while (!list_empty(&sdev->csum_list)) {
struct btrfs_ordered_sum *sum;
sum = list_first_entry(&sdev->csum_list,
struct btrfs_ordered_sum, list);
list_del(&sum->list);
kfree(sum);
}
}
static void scrub_free_bio(struct bio *bio)
{
int i;
struct page *last_page = NULL;
if (!bio)
return;
for (i = 0; i < bio->bi_vcnt; ++i) {
if (bio->bi_io_vec[i].bv_page == last_page)
continue;
last_page = bio->bi_io_vec[i].bv_page;
__free_page(last_page);
}
bio_put(bio);
}
static noinline_for_stack void scrub_free_dev(struct scrub_dev *sdev)
{
int i;
if (!sdev)
return;
for (i = 0; i < SCRUB_BIOS_PER_DEV; ++i) {
struct scrub_bio *sbio = sdev->bios[i];
if (!sbio)
break;
scrub_free_bio(sbio->bio);
kfree(sbio);
}
scrub_free_csums(sdev);
kfree(sdev);
}
int scrub_print_warning_inode(u64 inum, u64 offset, u64 root, void *ctx)
{
u64 isize;
u32 nlink;
int ret;
int i;
struct extent_buffer *eb;
struct btrfs_inode_item *inode_item;
struct scrub_warning *swarn = ctx;
struct btrfs_fs_info *fs_info = swarn->dev->dev_root->fs_info;
struct inode_fs_paths *ipath = NULL;
struct btrfs_root *local_root;
struct btrfs_key root_key;
root_key.objectid = root;
root_key.type = BTRFS_ROOT_ITEM_KEY;
root_key.offset = (u64)-1;
local_root = btrfs_read_fs_root_no_name(fs_info, &root_key);
if (IS_ERR(local_root)) {
ret = PTR_ERR(local_root);
goto err;
}
ret = inode_item_info(inum, 0, local_root, swarn->path);
if (ret) {
btrfs_release_path(swarn->path);
goto err;
}
eb = swarn->path->nodes[0];
inode_item = btrfs_item_ptr(eb, swarn->path->slots[0],
struct btrfs_inode_item);
isize = btrfs_inode_size(eb, inode_item);
nlink = btrfs_inode_nlink(eb, inode_item);
btrfs_release_path(swarn->path);
ipath = init_ipath(4096, local_root, swarn->path);
if (IS_ERR(ipath)) {
ret = PTR_ERR(ipath);
ipath = NULL;
goto err;
}
ret = paths_from_inode(inum, ipath);
if (ret < 0)
goto err;
for (i = 0; i < ipath->fspath->elem_cnt; ++i)
printk(KERN_WARNING "btrfs: %s at logical %llu on dev "
"%s, sector %llu, root %llu, inode %llu, offset %llu, "
"length %llu, links %u (path: %s)\n", swarn->errstr,
swarn->logical, swarn->dev->name,
(unsigned long long)swarn->sector, root, inum, offset,
min(isize - offset, (u64)PAGE_SIZE), nlink,
(char *)(unsigned long)ipath->fspath->val[i]);
free_ipath(ipath);
return 0;
err:
printk(KERN_WARNING "btrfs: %s at logical %llu on dev "
"%s, sector %llu, root %llu, inode %llu, offset %llu: path "
"resolving failed with ret=%d\n", swarn->errstr,
swarn->logical, swarn->dev->name,
(unsigned long long)swarn->sector, root, inum, offset, ret);
free_ipath(ipath);
return 0;
}
static void scrub_print_warning(const char *errstr, struct scrub_bio *sbio,
int ix)
{
struct btrfs_device *dev = sbio->sdev->dev;
struct btrfs_fs_info *fs_info = dev->dev_root->fs_info;
struct btrfs_path *path;
struct btrfs_key found_key;
struct extent_buffer *eb;
struct btrfs_extent_item *ei;
struct scrub_warning swarn;
u32 item_size;
int ret;
u64 ref_root;
u8 ref_level;
unsigned long ptr = 0;
const int bufsize = 4096;
u64 extent_offset;
path = btrfs_alloc_path();
swarn.scratch_buf = kmalloc(bufsize, GFP_NOFS);
swarn.msg_buf = kmalloc(bufsize, GFP_NOFS);
swarn.sector = (sbio->physical + ix * PAGE_SIZE) >> 9;
swarn.logical = sbio->logical + ix * PAGE_SIZE;
swarn.errstr = errstr;
swarn.dev = dev;
swarn.msg_bufsize = bufsize;
swarn.scratch_bufsize = bufsize;
if (!path || !swarn.scratch_buf || !swarn.msg_buf)
goto out;
ret = extent_from_logical(fs_info, swarn.logical, path, &found_key);
if (ret < 0)
goto out;
extent_offset = swarn.logical - found_key.objectid;
swarn.extent_item_size = found_key.offset;
eb = path->nodes[0];
ei = btrfs_item_ptr(eb, path->slots[0], struct btrfs_extent_item);
item_size = btrfs_item_size_nr(eb, path->slots[0]);
if (ret & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
do {
ret = tree_backref_for_extent(&ptr, eb, ei, item_size,
&ref_root, &ref_level);
printk(KERN_WARNING "%s at logical %llu on dev %s, "
"sector %llu: metadata %s (level %d) in tree "
"%llu\n", errstr, swarn.logical, dev->name,
(unsigned long long)swarn.sector,
ref_level ? "node" : "leaf",
ret < 0 ? -1 : ref_level,
ret < 0 ? -1 : ref_root);
} while (ret != 1);
} else {
swarn.path = path;
iterate_extent_inodes(fs_info, path, found_key.objectid,
extent_offset,
scrub_print_warning_inode, &swarn);
}
out:
btrfs_free_path(path);
kfree(swarn.scratch_buf);
kfree(swarn.msg_buf);
}
static int scrub_fixup_readpage(u64 inum, u64 offset, u64 root, void *ctx)
{
struct page *page = NULL;
unsigned long index;
struct scrub_fixup_nodatasum *fixup = ctx;
int ret;
int corrected = 0;
struct btrfs_key key;
struct inode *inode = NULL;
u64 end = offset + PAGE_SIZE - 1;
struct btrfs_root *local_root;
key.objectid = root;
key.type = BTRFS_ROOT_ITEM_KEY;
key.offset = (u64)-1;
local_root = btrfs_read_fs_root_no_name(fixup->root->fs_info, &key);
if (IS_ERR(local_root))
return PTR_ERR(local_root);
key.type = BTRFS_INODE_ITEM_KEY;
key.objectid = inum;
key.offset = 0;
inode = btrfs_iget(fixup->root->fs_info->sb, &key, local_root, NULL);
if (IS_ERR(inode))
return PTR_ERR(inode);
index = offset >> PAGE_CACHE_SHIFT;
page = find_or_create_page(inode->i_mapping, index, GFP_NOFS);
if (!page) {
ret = -ENOMEM;
goto out;
}
if (PageUptodate(page)) {
struct btrfs_mapping_tree *map_tree;
if (PageDirty(page)) {
ret = -EIO;
goto out;
}
map_tree = &BTRFS_I(inode)->root->fs_info->mapping_tree;
ret = repair_io_failure(map_tree, offset, PAGE_SIZE,
fixup->logical, page,
fixup->mirror_num);
unlock_page(page);
corrected = !ret;
} else {
ret = set_extent_bits(&BTRFS_I(inode)->io_tree, offset, end,
EXTENT_DAMAGED, GFP_NOFS);
if (ret) {
WARN_ON(ret > 0);
if (ret > 0)
ret = -EFAULT;
goto out;
}
ret = extent_read_full_page(&BTRFS_I(inode)->io_tree, page,
btrfs_get_extent,
fixup->mirror_num);
wait_on_page_locked(page);
corrected = !test_range_bit(&BTRFS_I(inode)->io_tree, offset,
end, EXTENT_DAMAGED, 0, NULL);
if (!corrected)
clear_extent_bits(&BTRFS_I(inode)->io_tree, offset, end,
EXTENT_DAMAGED, GFP_NOFS);
}
out:
if (page)
put_page(page);
if (inode)
iput(inode);
if (ret < 0)
return ret;
if (ret == 0 && corrected) {
return 1;
}
return -EIO;
}
static void scrub_fixup_nodatasum(struct btrfs_work *work)
{
int ret;
struct scrub_fixup_nodatasum *fixup;
struct scrub_dev *sdev;
struct btrfs_trans_handle *trans = NULL;
struct btrfs_fs_info *fs_info;
struct btrfs_path *path;
int uncorrectable = 0;
fixup = container_of(work, struct scrub_fixup_nodatasum, work);
sdev = fixup->sdev;
fs_info = fixup->root->fs_info;
path = btrfs_alloc_path();
if (!path) {
spin_lock(&sdev->stat_lock);
++sdev->stat.malloc_errors;
spin_unlock(&sdev->stat_lock);
uncorrectable = 1;
goto out;
}
trans = btrfs_join_transaction(fixup->root);
if (IS_ERR(trans)) {
uncorrectable = 1;
goto out;
}
ret = iterate_inodes_from_logical(fixup->logical, fixup->root->fs_info,
path, scrub_fixup_readpage,
fixup);
if (ret < 0) {
uncorrectable = 1;
goto out;
}
WARN_ON(ret != 1);
spin_lock(&sdev->stat_lock);
++sdev->stat.corrected_errors;
spin_unlock(&sdev->stat_lock);
out:
if (trans && !IS_ERR(trans))
btrfs_end_transaction(trans, fixup->root);
if (uncorrectable) {
spin_lock(&sdev->stat_lock);
++sdev->stat.uncorrectable_errors;
spin_unlock(&sdev->stat_lock);
printk_ratelimited(KERN_ERR "btrfs: unable to fixup "
"(nodatasum) error at logical %llu\n",
fixup->logical);
}
btrfs_free_path(path);
kfree(fixup);
mutex_lock(&fs_info->scrub_lock);
atomic_dec(&fs_info->scrubs_running);
atomic_dec(&fs_info->scrubs_paused);
mutex_unlock(&fs_info->scrub_lock);
atomic_dec(&sdev->fixup_cnt);
wake_up(&fs_info->scrub_pause_wait);
wake_up(&sdev->list_wait);
}
static int scrub_recheck_error(struct scrub_bio *sbio, int ix)
{
struct scrub_dev *sdev = sbio->sdev;
u64 sector = (sbio->physical + ix * PAGE_SIZE) >> 9;
static DEFINE_RATELIMIT_STATE(_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if (sbio->err) {
if (scrub_fixup_io(READ, sbio->sdev->dev->bdev, sector,
sbio->bio->bi_io_vec[ix].bv_page) == 0) {
if (scrub_fixup_check(sbio, ix) == 0)
return 0;
}
if (__ratelimit(&_rs))
scrub_print_warning("i/o error", sbio, ix);
} else {
if (__ratelimit(&_rs))
scrub_print_warning("checksum error", sbio, ix);
}
spin_lock(&sdev->stat_lock);
++sdev->stat.read_errors;
spin_unlock(&sdev->stat_lock);
scrub_fixup(sbio, ix);
return 1;
}
static int scrub_fixup_check(struct scrub_bio *sbio, int ix)
{
int ret = 1;
struct page *page;
void *buffer;
u64 flags = sbio->spag[ix].flags;
page = sbio->bio->bi_io_vec[ix].bv_page;
buffer = kmap_atomic(page, KM_USER0);
if (flags & BTRFS_EXTENT_FLAG_DATA) {
ret = scrub_checksum_data(sbio->sdev,
sbio->spag + ix, buffer);
} else if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
ret = scrub_checksum_tree_block(sbio->sdev,
sbio->spag + ix,
sbio->logical + ix * PAGE_SIZE,
buffer);
} else {
WARN_ON(1);
}
kunmap_atomic(buffer, KM_USER0);
return ret;
}
static void scrub_fixup_end_io(struct bio *bio, int err)
{
complete((struct completion *)bio->bi_private);
}
static void scrub_fixup(struct scrub_bio *sbio, int ix)
{
struct scrub_dev *sdev = sbio->sdev;
struct btrfs_fs_info *fs_info = sdev->dev->dev_root->fs_info;
struct btrfs_mapping_tree *map_tree = &fs_info->mapping_tree;
struct btrfs_bio *bbio = NULL;
struct scrub_fixup_nodatasum *fixup;
u64 logical = sbio->logical + ix * PAGE_SIZE;
u64 length;
int i;
int ret;
DECLARE_COMPLETION_ONSTACK(complete);
if ((sbio->spag[ix].flags & BTRFS_EXTENT_FLAG_DATA) &&
(sbio->spag[ix].have_csum == 0)) {
fixup = kzalloc(sizeof(*fixup), GFP_NOFS);
if (!fixup)
goto uncorrectable;
fixup->sdev = sdev;
fixup->logical = logical;
fixup->root = fs_info->extent_root;
fixup->mirror_num = sbio->spag[ix].mirror_num;
mutex_lock(&fs_info->scrub_lock);
atomic_inc(&fs_info->scrubs_running);
atomic_inc(&fs_info->scrubs_paused);
mutex_unlock(&fs_info->scrub_lock);
atomic_inc(&sdev->fixup_cnt);
fixup->work.func = scrub_fixup_nodatasum;
btrfs_queue_worker(&fs_info->scrub_workers, &fixup->work);
return;
}
length = PAGE_SIZE;
ret = btrfs_map_block(map_tree, REQ_WRITE, logical, &length,
&bbio, 0);
if (ret || !bbio || length < PAGE_SIZE) {
printk(KERN_ERR
"scrub_fixup: btrfs_map_block failed us for %llu\n",
(unsigned long long)logical);
WARN_ON(1);
kfree(bbio);
return;
}
if (bbio->num_stripes == 1)
goto uncorrectable;
for (i = 0; i < bbio->num_stripes; ++i) {
if (i + 1 == sbio->spag[ix].mirror_num)
continue;
if (scrub_fixup_io(READ, bbio->stripes[i].dev->bdev,
bbio->stripes[i].physical >> 9,
sbio->bio->bi_io_vec[ix].bv_page)) {
continue;
}
if (scrub_fixup_check(sbio, ix) == 0)
break;
}
if (i == bbio->num_stripes)
goto uncorrectable;
if (!sdev->readonly) {
if (scrub_fixup_io(WRITE, sdev->dev->bdev,
(sbio->physical + ix * PAGE_SIZE) >> 9,
sbio->bio->bi_io_vec[ix].bv_page)) {
goto uncorrectable;
}
}
kfree(bbio);
spin_lock(&sdev->stat_lock);
++sdev->stat.corrected_errors;
spin_unlock(&sdev->stat_lock);
printk_ratelimited(KERN_ERR "btrfs: fixed up error at logical %llu\n",
(unsigned long long)logical);
return;
uncorrectable:
kfree(bbio);
spin_lock(&sdev->stat_lock);
++sdev->stat.uncorrectable_errors;
spin_unlock(&sdev->stat_lock);
printk_ratelimited(KERN_ERR "btrfs: unable to fixup (regular) error at "
"logical %llu\n", (unsigned long long)logical);
}
static int scrub_fixup_io(int rw, struct block_device *bdev, sector_t sector,
struct page *page)
{
struct bio *bio = NULL;
int ret;
DECLARE_COMPLETION_ONSTACK(complete);
bio = bio_alloc(GFP_NOFS, 1);
bio->bi_bdev = bdev;
bio->bi_sector = sector;
bio_add_page(bio, page, PAGE_SIZE, 0);
bio->bi_end_io = scrub_fixup_end_io;
bio->bi_private = &complete;
submit_bio(rw, bio);
wait_for_completion(&complete);
ret = !test_bit(BIO_UPTODATE, &bio->bi_flags);
bio_put(bio);
return ret;
}
static void scrub_bio_end_io(struct bio *bio, int err)
{
struct scrub_bio *sbio = bio->bi_private;
struct scrub_dev *sdev = sbio->sdev;
struct btrfs_fs_info *fs_info = sdev->dev->dev_root->fs_info;
sbio->err = err;
sbio->bio = bio;
btrfs_queue_worker(&fs_info->scrub_workers, &sbio->work);
}
static void scrub_checksum(struct btrfs_work *work)
{
struct scrub_bio *sbio = container_of(work, struct scrub_bio, work);
struct scrub_dev *sdev = sbio->sdev;
struct page *page;
void *buffer;
int i;
u64 flags;
u64 logical;
int ret;
if (sbio->err) {
ret = 0;
for (i = 0; i < sbio->count; ++i)
ret |= scrub_recheck_error(sbio, i);
if (!ret) {
spin_lock(&sdev->stat_lock);
++sdev->stat.unverified_errors;
spin_unlock(&sdev->stat_lock);
}
sbio->bio->bi_flags &= ~(BIO_POOL_MASK - 1);
sbio->bio->bi_flags |= 1 << BIO_UPTODATE;
sbio->bio->bi_phys_segments = 0;
sbio->bio->bi_idx = 0;
for (i = 0; i < sbio->count; i++) {
struct bio_vec *bi;
bi = &sbio->bio->bi_io_vec[i];
bi->bv_offset = 0;
bi->bv_len = PAGE_SIZE;
}
goto out;
}
for (i = 0; i < sbio->count; ++i) {
page = sbio->bio->bi_io_vec[i].bv_page;
buffer = kmap_atomic(page, KM_USER0);
flags = sbio->spag[i].flags;
logical = sbio->logical + i * PAGE_SIZE;
ret = 0;
if (flags & BTRFS_EXTENT_FLAG_DATA) {
ret = scrub_checksum_data(sdev, sbio->spag + i, buffer);
} else if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
ret = scrub_checksum_tree_block(sdev, sbio->spag + i,
logical, buffer);
} else if (flags & BTRFS_EXTENT_FLAG_SUPER) {
BUG_ON(i);
(void)scrub_checksum_super(sbio, buffer);
} else {
WARN_ON(1);
}
kunmap_atomic(buffer, KM_USER0);
if (ret) {
ret = scrub_recheck_error(sbio, i);
if (!ret) {
spin_lock(&sdev->stat_lock);
++sdev->stat.unverified_errors;
spin_unlock(&sdev->stat_lock);
}
}
}
out:
scrub_free_bio(sbio->bio);
sbio->bio = NULL;
spin_lock(&sdev->list_lock);
sbio->next_free = sdev->first_free;
sdev->first_free = sbio->index;
spin_unlock(&sdev->list_lock);
atomic_dec(&sdev->in_flight);
wake_up(&sdev->list_wait);
}
static int scrub_checksum_data(struct scrub_dev *sdev,
struct scrub_page *spag, void *buffer)
{
u8 csum[BTRFS_CSUM_SIZE];
u32 crc = ~(u32)0;
int fail = 0;
struct btrfs_root *root = sdev->dev->dev_root;
if (!spag->have_csum)
return 0;
crc = btrfs_csum_data(root, buffer, crc, PAGE_SIZE);
btrfs_csum_final(crc, csum);
if (memcmp(csum, spag->csum, sdev->csum_size))
fail = 1;
spin_lock(&sdev->stat_lock);
++sdev->stat.data_extents_scrubbed;
sdev->stat.data_bytes_scrubbed += PAGE_SIZE;
if (fail)
++sdev->stat.csum_errors;
spin_unlock(&sdev->stat_lock);
return fail;
}
static int scrub_checksum_tree_block(struct scrub_dev *sdev,
struct scrub_page *spag, u64 logical,
void *buffer)
{
struct btrfs_header *h;
struct btrfs_root *root = sdev->dev->dev_root;
struct btrfs_fs_info *fs_info = root->fs_info;
u8 csum[BTRFS_CSUM_SIZE];
u32 crc = ~(u32)0;
int fail = 0;
int crc_fail = 0;
h = (struct btrfs_header *)buffer;
if (logical != le64_to_cpu(h->bytenr))
++fail;
if (spag->generation != le64_to_cpu(h->generation))
++fail;
if (memcmp(h->fsid, fs_info->fsid, BTRFS_UUID_SIZE))
++fail;
if (memcmp(h->chunk_tree_uuid, fs_info->chunk_tree_uuid,
BTRFS_UUID_SIZE))
++fail;
crc = btrfs_csum_data(root, buffer + BTRFS_CSUM_SIZE, crc,
PAGE_SIZE - BTRFS_CSUM_SIZE);
btrfs_csum_final(crc, csum);
if (memcmp(csum, h->csum, sdev->csum_size))
++crc_fail;
spin_lock(&sdev->stat_lock);
++sdev->stat.tree_extents_scrubbed;
sdev->stat.tree_bytes_scrubbed += PAGE_SIZE;
if (crc_fail)
++sdev->stat.csum_errors;
if (fail)
++sdev->stat.verify_errors;
spin_unlock(&sdev->stat_lock);
return fail || crc_fail;
}
static int scrub_checksum_super(struct scrub_bio *sbio, void *buffer)
{
struct btrfs_super_block *s;
u64 logical;
struct scrub_dev *sdev = sbio->sdev;
struct btrfs_root *root = sdev->dev->dev_root;
struct btrfs_fs_info *fs_info = root->fs_info;
u8 csum[BTRFS_CSUM_SIZE];
u32 crc = ~(u32)0;
int fail = 0;
s = (struct btrfs_super_block *)buffer;
logical = sbio->logical;
if (logical != le64_to_cpu(s->bytenr))
++fail;
if (sbio->spag[0].generation != le64_to_cpu(s->generation))
++fail;
if (memcmp(s->fsid, fs_info->fsid, BTRFS_UUID_SIZE))
++fail;
crc = btrfs_csum_data(root, buffer + BTRFS_CSUM_SIZE, crc,
PAGE_SIZE - BTRFS_CSUM_SIZE);
btrfs_csum_final(crc, csum);
if (memcmp(csum, s->csum, sbio->sdev->csum_size))
++fail;
if (fail) {
spin_lock(&sdev->stat_lock);
++sdev->stat.super_errors;
spin_unlock(&sdev->stat_lock);
}
return fail;
}
static int scrub_submit(struct scrub_dev *sdev)
{
struct scrub_bio *sbio;
if (sdev->curr == -1)
return 0;
sbio = sdev->bios[sdev->curr];
sbio->err = 0;
sdev->curr = -1;
atomic_inc(&sdev->in_flight);
submit_bio(READ, sbio->bio);
return 0;
}
static int scrub_page(struct scrub_dev *sdev, u64 logical, u64 len,
u64 physical, u64 flags, u64 gen, int mirror_num,
u8 *csum, int force)
{
struct scrub_bio *sbio;
struct page *page;
int ret;
again:
while (sdev->curr == -1) {
spin_lock(&sdev->list_lock);
sdev->curr = sdev->first_free;
if (sdev->curr != -1) {
sdev->first_free = sdev->bios[sdev->curr]->next_free;
sdev->bios[sdev->curr]->next_free = -1;
sdev->bios[sdev->curr]->count = 0;
spin_unlock(&sdev->list_lock);
} else {
spin_unlock(&sdev->list_lock);
wait_event(sdev->list_wait, sdev->first_free != -1);
}
}
sbio = sdev->bios[sdev->curr];
if (sbio->count == 0) {
struct bio *bio;
sbio->physical = physical;
sbio->logical = logical;
bio = bio_alloc(GFP_NOFS, SCRUB_PAGES_PER_BIO);
if (!bio)
return -ENOMEM;
bio->bi_private = sbio;
bio->bi_end_io = scrub_bio_end_io;
bio->bi_bdev = sdev->dev->bdev;
bio->bi_sector = sbio->physical >> 9;
sbio->err = 0;
sbio->bio = bio;
} else if (sbio->physical + sbio->count * PAGE_SIZE != physical ||
sbio->logical + sbio->count * PAGE_SIZE != logical) {
ret = scrub_submit(sdev);
if (ret)
return ret;
goto again;
}
sbio->spag[sbio->count].flags = flags;
sbio->spag[sbio->count].generation = gen;
sbio->spag[sbio->count].have_csum = 0;
sbio->spag[sbio->count].mirror_num = mirror_num;
page = alloc_page(GFP_NOFS);
if (!page)
return -ENOMEM;
ret = bio_add_page(sbio->bio, page, PAGE_SIZE, 0);
if (!ret) {
__free_page(page);
ret = scrub_submit(sdev);
if (ret)
return ret;
goto again;
}
if (csum) {
sbio->spag[sbio->count].have_csum = 1;
memcpy(sbio->spag[sbio->count].csum, csum, sdev->csum_size);
}
++sbio->count;
if (sbio->count == SCRUB_PAGES_PER_BIO || force) {
int ret;
ret = scrub_submit(sdev);
if (ret)
return ret;
}
return 0;
}
static int scrub_find_csum(struct scrub_dev *sdev, u64 logical, u64 len,
u8 *csum)
{
struct btrfs_ordered_sum *sum = NULL;
int ret = 0;
unsigned long i;
unsigned long num_sectors;
u32 sectorsize = sdev->dev->dev_root->sectorsize;
while (!list_empty(&sdev->csum_list)) {
sum = list_first_entry(&sdev->csum_list,
struct btrfs_ordered_sum, list);
if (sum->bytenr > logical)
return 0;
if (sum->bytenr + sum->len > logical)
break;
++sdev->stat.csum_discards;
list_del(&sum->list);
kfree(sum);
sum = NULL;
}
if (!sum)
return 0;
num_sectors = sum->len / sectorsize;
for (i = 0; i < num_sectors; ++i) {
if (sum->sums[i].bytenr == logical) {
memcpy(csum, &sum->sums[i].sum, sdev->csum_size);
ret = 1;
break;
}
}
if (ret && i == num_sectors - 1) {
list_del(&sum->list);
kfree(sum);
}
return ret;
}
static int scrub_extent(struct scrub_dev *sdev, u64 logical, u64 len,
u64 physical, u64 flags, u64 gen, int mirror_num)
{
int ret;
u8 csum[BTRFS_CSUM_SIZE];
while (len) {
u64 l = min_t(u64, len, PAGE_SIZE);
int have_csum = 0;
if (flags & BTRFS_EXTENT_FLAG_DATA) {
have_csum = scrub_find_csum(sdev, logical, l, csum);
if (have_csum == 0)
++sdev->stat.no_csum;
}
ret = scrub_page(sdev, logical, l, physical, flags, gen,
mirror_num, have_csum ? csum : NULL, 0);
if (ret)
return ret;
len -= l;
logical += l;
physical += l;
}
return 0;
}
static noinline_for_stack int scrub_stripe(struct scrub_dev *sdev,
struct map_lookup *map, int num, u64 base, u64 length)
{
struct btrfs_path *path;
struct btrfs_fs_info *fs_info = sdev->dev->dev_root->fs_info;
struct btrfs_root *root = fs_info->extent_root;
struct btrfs_root *csum_root = fs_info->csum_root;
struct btrfs_extent_item *extent;
struct blk_plug plug;
u64 flags;
int ret;
int slot;
int i;
u64 nstripes;
struct extent_buffer *l;
struct btrfs_key key;
u64 physical;
u64 logical;
u64 generation;
int mirror_num;
struct reada_control *reada1;
struct reada_control *reada2;
struct btrfs_key key_start;
struct btrfs_key key_end;
u64 increment = map->stripe_len;
u64 offset;
nstripes = length;
offset = 0;
do_div(nstripes, map->stripe_len);
if (map->type & BTRFS_BLOCK_GROUP_RAID0) {
offset = map->stripe_len * num;
increment = map->stripe_len * map->num_stripes;
mirror_num = 1;
} else if (map->type & BTRFS_BLOCK_GROUP_RAID10) {
int factor = map->num_stripes / map->sub_stripes;
offset = map->stripe_len * (num / map->sub_stripes);
increment = map->stripe_len * factor;
mirror_num = num % map->sub_stripes + 1;
} else if (map->type & BTRFS_BLOCK_GROUP_RAID1) {
increment = map->stripe_len;
mirror_num = num % map->num_stripes + 1;
} else if (map->type & BTRFS_BLOCK_GROUP_DUP) {
increment = map->stripe_len;
mirror_num = num % map->num_stripes + 1;
} else {
increment = map->stripe_len;
mirror_num = 1;
}
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
path->search_commit_root = 1;
path->skip_locking = 1;
logical = base + offset;
wait_event(sdev->list_wait,
atomic_read(&sdev->in_flight) == 0);
atomic_inc(&fs_info->scrubs_paused);
wake_up(&fs_info->scrub_pause_wait);
key_start.objectid = logical;
key_start.type = BTRFS_EXTENT_ITEM_KEY;
key_start.offset = (u64)0;
key_end.objectid = base + offset + nstripes * increment;
key_end.type = BTRFS_EXTENT_ITEM_KEY;
key_end.offset = (u64)0;
reada1 = btrfs_reada_add(root, &key_start, &key_end);
key_start.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
key_start.type = BTRFS_EXTENT_CSUM_KEY;
key_start.offset = logical;
key_end.objectid = BTRFS_EXTENT_CSUM_OBJECTID;
key_end.type = BTRFS_EXTENT_CSUM_KEY;
key_end.offset = base + offset + nstripes * increment;
reada2 = btrfs_reada_add(csum_root, &key_start, &key_end);
if (!IS_ERR(reada1))
btrfs_reada_wait(reada1);
if (!IS_ERR(reada2))
btrfs_reada_wait(reada2);
mutex_lock(&fs_info->scrub_lock);
while (atomic_read(&fs_info->scrub_pause_req)) {
mutex_unlock(&fs_info->scrub_lock);
wait_event(fs_info->scrub_pause_wait,
atomic_read(&fs_info->scrub_pause_req) == 0);
mutex_lock(&fs_info->scrub_lock);
}
atomic_dec(&fs_info->scrubs_paused);
mutex_unlock(&fs_info->scrub_lock);
wake_up(&fs_info->scrub_pause_wait);
blk_start_plug(&plug);
logical = base + offset;
physical = map->stripes[num].physical;
ret = 0;
for (i = 0; i < nstripes; ++i) {
if (atomic_read(&fs_info->scrub_cancel_req) ||
atomic_read(&sdev->cancel_req)) {
ret = -ECANCELED;
goto out;
}
if (atomic_read(&fs_info->scrub_pause_req)) {
scrub_submit(sdev);
wait_event(sdev->list_wait,
atomic_read(&sdev->in_flight) == 0);
atomic_inc(&fs_info->scrubs_paused);
wake_up(&fs_info->scrub_pause_wait);
mutex_lock(&fs_info->scrub_lock);
while (atomic_read(&fs_info->scrub_pause_req)) {
mutex_unlock(&fs_info->scrub_lock);
wait_event(fs_info->scrub_pause_wait,
atomic_read(&fs_info->scrub_pause_req) == 0);
mutex_lock(&fs_info->scrub_lock);
}
atomic_dec(&fs_info->scrubs_paused);
mutex_unlock(&fs_info->scrub_lock);
wake_up(&fs_info->scrub_pause_wait);
}
ret = btrfs_lookup_csums_range(csum_root, logical,
logical + map->stripe_len - 1,
&sdev->csum_list, 1);
if (ret)
goto out;
key.objectid = logical;
key.type = BTRFS_EXTENT_ITEM_KEY;
key.offset = (u64)0;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto out;
if (ret > 0) {
ret = btrfs_previous_item(root, path, 0,
BTRFS_EXTENT_ITEM_KEY);
if (ret < 0)
goto out;
if (ret > 0) {
btrfs_release_path(path);
ret = btrfs_search_slot(NULL, root, &key,
path, 0, 0);
if (ret < 0)
goto out;
}
}
while (1) {
l = path->nodes[0];
slot = path->slots[0];
if (slot >= btrfs_header_nritems(l)) {
ret = btrfs_next_leaf(root, path);
if (ret == 0)
continue;
if (ret < 0)
goto out;
break;
}
btrfs_item_key_to_cpu(l, &key, slot);
if (key.objectid + key.offset <= logical)
goto next;
if (key.objectid >= logical + map->stripe_len)
break;
if (btrfs_key_type(&key) != BTRFS_EXTENT_ITEM_KEY)
goto next;
extent = btrfs_item_ptr(l, slot,
struct btrfs_extent_item);
flags = btrfs_extent_flags(l, extent);
generation = btrfs_extent_generation(l, extent);
if (key.objectid < logical &&
(flags & BTRFS_EXTENT_FLAG_TREE_BLOCK)) {
printk(KERN_ERR
"btrfs scrub: tree block %llu spanning "
"stripes, ignored. logical=%llu\n",
(unsigned long long)key.objectid,
(unsigned long long)logical);
goto next;
}
if (key.objectid < logical) {
key.offset -= logical - key.objectid;
key.objectid = logical;
}
if (key.objectid + key.offset >
logical + map->stripe_len) {
key.offset = logical + map->stripe_len -
key.objectid;
}
ret = scrub_extent(sdev, key.objectid, key.offset,
key.objectid - logical + physical,
flags, generation, mirror_num);
if (ret)
goto out;
next:
path->slots[0]++;
}
btrfs_release_path(path);
logical += increment;
physical += map->stripe_len;
spin_lock(&sdev->stat_lock);
sdev->stat.last_physical = physical;
spin_unlock(&sdev->stat_lock);
}
scrub_submit(sdev);
out:
blk_finish_plug(&plug);
btrfs_free_path(path);
return ret < 0 ? ret : 0;
}
static noinline_for_stack int scrub_chunk(struct scrub_dev *sdev,
u64 chunk_tree, u64 chunk_objectid, u64 chunk_offset, u64 length)
{
struct btrfs_mapping_tree *map_tree =
&sdev->dev->dev_root->fs_info->mapping_tree;
struct map_lookup *map;
struct extent_map *em;
int i;
int ret = -EINVAL;
read_lock(&map_tree->map_tree.lock);
em = lookup_extent_mapping(&map_tree->map_tree, chunk_offset, 1);
read_unlock(&map_tree->map_tree.lock);
if (!em)
return -EINVAL;
map = (struct map_lookup *)em->bdev;
if (em->start != chunk_offset)
goto out;
if (em->len < length)
goto out;
for (i = 0; i < map->num_stripes; ++i) {
if (map->stripes[i].dev == sdev->dev) {
ret = scrub_stripe(sdev, map, i, chunk_offset, length);
if (ret)
goto out;
}
}
out:
free_extent_map(em);
return ret;
}
static noinline_for_stack
int scrub_enumerate_chunks(struct scrub_dev *sdev, u64 start, u64 end)
{
struct btrfs_dev_extent *dev_extent = NULL;
struct btrfs_path *path;
struct btrfs_root *root = sdev->dev->dev_root;
struct btrfs_fs_info *fs_info = root->fs_info;
u64 length;
u64 chunk_tree;
u64 chunk_objectid;
u64 chunk_offset;
int ret;
int slot;
struct extent_buffer *l;
struct btrfs_key key;
struct btrfs_key found_key;
struct btrfs_block_group_cache *cache;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
path->reada = 2;
path->search_commit_root = 1;
path->skip_locking = 1;
key.objectid = sdev->dev->devid;
key.offset = 0ull;
key.type = BTRFS_DEV_EXTENT_KEY;
while (1) {
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
break;
if (ret > 0) {
if (path->slots[0] >=
btrfs_header_nritems(path->nodes[0])) {
ret = btrfs_next_leaf(root, path);
if (ret)
break;
}
}
l = path->nodes[0];
slot = path->slots[0];
btrfs_item_key_to_cpu(l, &found_key, slot);
if (found_key.objectid != sdev->dev->devid)
break;
if (btrfs_key_type(&found_key) != BTRFS_DEV_EXTENT_KEY)
break;
if (found_key.offset >= end)
break;
if (found_key.offset < key.offset)
break;
dev_extent = btrfs_item_ptr(l, slot, struct btrfs_dev_extent);
length = btrfs_dev_extent_length(l, dev_extent);
if (found_key.offset + length <= start) {
key.offset = found_key.offset + length;
btrfs_release_path(path);
continue;
}
chunk_tree = btrfs_dev_extent_chunk_tree(l, dev_extent);
chunk_objectid = btrfs_dev_extent_chunk_objectid(l, dev_extent);
chunk_offset = btrfs_dev_extent_chunk_offset(l, dev_extent);
cache = btrfs_lookup_block_group(fs_info, chunk_offset);
if (!cache) {
ret = -ENOENT;
break;
}
ret = scrub_chunk(sdev, chunk_tree, chunk_objectid,
chunk_offset, length);
btrfs_put_block_group(cache);
if (ret)
break;
key.offset = found_key.offset + length;
btrfs_release_path(path);
}
btrfs_free_path(path);
return ret < 0 ? ret : 0;
}
static noinline_for_stack int scrub_supers(struct scrub_dev *sdev)
{
int i;
u64 bytenr;
u64 gen;
int ret;
struct btrfs_device *device = sdev->dev;
struct btrfs_root *root = device->dev_root;
gen = root->fs_info->last_trans_committed;
for (i = 0; i < BTRFS_SUPER_MIRROR_MAX; i++) {
bytenr = btrfs_sb_offset(i);
if (bytenr + BTRFS_SUPER_INFO_SIZE >= device->total_bytes)
break;
ret = scrub_page(sdev, bytenr, PAGE_SIZE, bytenr,
BTRFS_EXTENT_FLAG_SUPER, gen, i, NULL, 1);
if (ret)
return ret;
}
wait_event(sdev->list_wait, atomic_read(&sdev->in_flight) == 0);
return 0;
}
static noinline_for_stack int scrub_workers_get(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
int ret = 0;
mutex_lock(&fs_info->scrub_lock);
if (fs_info->scrub_workers_refcnt == 0) {
btrfs_init_workers(&fs_info->scrub_workers, "scrub",
fs_info->thread_pool_size, &fs_info->generic_worker);
fs_info->scrub_workers.idle_thresh = 4;
ret = btrfs_start_workers(&fs_info->scrub_workers);
if (ret)
goto out;
}
++fs_info->scrub_workers_refcnt;
out:
mutex_unlock(&fs_info->scrub_lock);
return ret;
}
static noinline_for_stack void scrub_workers_put(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
mutex_lock(&fs_info->scrub_lock);
if (--fs_info->scrub_workers_refcnt == 0)
btrfs_stop_workers(&fs_info->scrub_workers);
WARN_ON(fs_info->scrub_workers_refcnt < 0);
mutex_unlock(&fs_info->scrub_lock);
}
int btrfs_scrub_dev(struct btrfs_root *root, u64 devid, u64 start, u64 end,
struct btrfs_scrub_progress *progress, int readonly)
{
struct scrub_dev *sdev;
struct btrfs_fs_info *fs_info = root->fs_info;
int ret;
struct btrfs_device *dev;
if (btrfs_fs_closing(root->fs_info))
return -EINVAL;
if (root->sectorsize != PAGE_SIZE ||
root->sectorsize != root->leafsize ||
root->sectorsize != root->nodesize) {
printk(KERN_ERR "btrfs_scrub: size assumptions fail\n");
return -EINVAL;
}
ret = scrub_workers_get(root);
if (ret)
return ret;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
dev = btrfs_find_device(root, devid, NULL, NULL);
if (!dev || dev->missing) {
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
scrub_workers_put(root);
return -ENODEV;
}
mutex_lock(&fs_info->scrub_lock);
if (!dev->in_fs_metadata) {
mutex_unlock(&fs_info->scrub_lock);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
scrub_workers_put(root);
return -ENODEV;
}
if (dev->scrub_device) {
mutex_unlock(&fs_info->scrub_lock);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
scrub_workers_put(root);
return -EINPROGRESS;
}
sdev = scrub_setup_dev(dev);
if (IS_ERR(sdev)) {
mutex_unlock(&fs_info->scrub_lock);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
scrub_workers_put(root);
return PTR_ERR(sdev);
}
sdev->readonly = readonly;
dev->scrub_device = sdev;
atomic_inc(&fs_info->scrubs_running);
mutex_unlock(&fs_info->scrub_lock);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
down_read(&fs_info->scrub_super_lock);
ret = scrub_supers(sdev);
up_read(&fs_info->scrub_super_lock);
if (!ret)
ret = scrub_enumerate_chunks(sdev, start, end);
wait_event(sdev->list_wait, atomic_read(&sdev->in_flight) == 0);
atomic_dec(&fs_info->scrubs_running);
wake_up(&fs_info->scrub_pause_wait);
wait_event(sdev->list_wait, atomic_read(&sdev->fixup_cnt) == 0);
if (progress)
memcpy(progress, &sdev->stat, sizeof(*progress));
mutex_lock(&fs_info->scrub_lock);
dev->scrub_device = NULL;
mutex_unlock(&fs_info->scrub_lock);
scrub_free_dev(sdev);
scrub_workers_put(root);
return ret;
}
int btrfs_scrub_pause(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
mutex_lock(&fs_info->scrub_lock);
atomic_inc(&fs_info->scrub_pause_req);
while (atomic_read(&fs_info->scrubs_paused) !=
atomic_read(&fs_info->scrubs_running)) {
mutex_unlock(&fs_info->scrub_lock);
wait_event(fs_info->scrub_pause_wait,
atomic_read(&fs_info->scrubs_paused) ==
atomic_read(&fs_info->scrubs_running));
mutex_lock(&fs_info->scrub_lock);
}
mutex_unlock(&fs_info->scrub_lock);
return 0;
}
int btrfs_scrub_continue(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
atomic_dec(&fs_info->scrub_pause_req);
wake_up(&fs_info->scrub_pause_wait);
return 0;
}
int btrfs_scrub_pause_super(struct btrfs_root *root)
{
down_write(&root->fs_info->scrub_super_lock);
return 0;
}
int btrfs_scrub_continue_super(struct btrfs_root *root)
{
up_write(&root->fs_info->scrub_super_lock);
return 0;
}
int btrfs_scrub_cancel(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
mutex_lock(&fs_info->scrub_lock);
if (!atomic_read(&fs_info->scrubs_running)) {
mutex_unlock(&fs_info->scrub_lock);
return -ENOTCONN;
}
atomic_inc(&fs_info->scrub_cancel_req);
while (atomic_read(&fs_info->scrubs_running)) {
mutex_unlock(&fs_info->scrub_lock);
wait_event(fs_info->scrub_pause_wait,
atomic_read(&fs_info->scrubs_running) == 0);
mutex_lock(&fs_info->scrub_lock);
}
atomic_dec(&fs_info->scrub_cancel_req);
mutex_unlock(&fs_info->scrub_lock);
return 0;
}
int btrfs_scrub_cancel_dev(struct btrfs_root *root, struct btrfs_device *dev)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct scrub_dev *sdev;
mutex_lock(&fs_info->scrub_lock);
sdev = dev->scrub_device;
if (!sdev) {
mutex_unlock(&fs_info->scrub_lock);
return -ENOTCONN;
}
atomic_inc(&sdev->cancel_req);
while (dev->scrub_device) {
mutex_unlock(&fs_info->scrub_lock);
wait_event(fs_info->scrub_pause_wait,
dev->scrub_device == NULL);
mutex_lock(&fs_info->scrub_lock);
}
mutex_unlock(&fs_info->scrub_lock);
return 0;
}
int btrfs_scrub_cancel_devid(struct btrfs_root *root, u64 devid)
{
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_device *dev;
int ret;
mutex_lock(&fs_info->fs_devices->device_list_mutex);
dev = btrfs_find_device(root, devid, NULL, NULL);
if (!dev) {
mutex_unlock(&fs_info->fs_devices->device_list_mutex);
return -ENODEV;
}
ret = btrfs_scrub_cancel_dev(root, dev);
mutex_unlock(&fs_info->fs_devices->device_list_mutex);
return ret;
}
int btrfs_scrub_progress(struct btrfs_root *root, u64 devid,
struct btrfs_scrub_progress *progress)
{
struct btrfs_device *dev;
struct scrub_dev *sdev = NULL;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
dev = btrfs_find_device(root, devid, NULL, NULL);
if (dev)
sdev = dev->scrub_device;
if (sdev)
memcpy(progress, &sdev->stat, sizeof(*progress));
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
return dev ? (sdev ? 0 : -ENOTCONN) : -ENODEV;
}
