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
static noinline_for_stack void scrub_free_dev(struct scrub_dev *sdev)
{
int i;
if (!sdev)
return;
if (sdev->curr != -1) {
struct scrub_bio *sbio = sdev->bios[sdev->curr];
for (i = 0; i < sbio->page_count; i++) {
BUG_ON(!sbio->pagev[i]);
BUG_ON(!sbio->pagev[i]->page);
scrub_block_put(sbio->pagev[i]->sblock);
}
bio_put(sbio->bio);
}
for (i = 0; i < SCRUB_BIOS_PER_DEV; ++i) {
struct scrub_bio *sbio = sdev->bios[i];
if (!sbio)
break;
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
printk_in_rcu(KERN_WARNING "btrfs: %s at logical %llu on dev "
"%s, sector %llu, root %llu, inode %llu, offset %llu, "
"length %llu, links %u (path: %s)\n", swarn->errstr,
swarn->logical, rcu_str_deref(swarn->dev->name),
(unsigned long long)swarn->sector, root, inum, offset,
min(isize - offset, (u64)PAGE_SIZE), nlink,
(char *)(unsigned long)ipath->fspath->val[i]);
free_ipath(ipath);
return 0;
err:
printk_in_rcu(KERN_WARNING "btrfs: %s at logical %llu on dev "
"%s, sector %llu, root %llu, inode %llu, offset %llu: path "
"resolving failed with ret=%d\n", swarn->errstr,
swarn->logical, rcu_str_deref(swarn->dev->name),
(unsigned long long)swarn->sector, root, inum, offset, ret);
free_ipath(ipath);
return 0;
}
static void scrub_print_warning(const char *errstr, struct scrub_block *sblock)
{
struct btrfs_device *dev = sblock->sdev->dev;
struct btrfs_fs_info *fs_info = dev->dev_root->fs_info;
struct btrfs_path *path;
struct btrfs_key found_key;
struct extent_buffer *eb;
struct btrfs_extent_item *ei;
struct scrub_warning swarn;
unsigned long ptr = 0;
u64 extent_item_pos;
u64 flags = 0;
u64 ref_root;
u32 item_size;
u8 ref_level;
const int bufsize = 4096;
int ret;
path = btrfs_alloc_path();
swarn.scratch_buf = kmalloc(bufsize, GFP_NOFS);
swarn.msg_buf = kmalloc(bufsize, GFP_NOFS);
BUG_ON(sblock->page_count < 1);
swarn.sector = (sblock->pagev[0].physical) >> 9;
swarn.logical = sblock->pagev[0].logical;
swarn.errstr = errstr;
swarn.dev = dev;
swarn.msg_bufsize = bufsize;
swarn.scratch_bufsize = bufsize;
if (!path || !swarn.scratch_buf || !swarn.msg_buf)
goto out;
ret = extent_from_logical(fs_info, swarn.logical, path, &found_key,
&flags);
if (ret < 0)
goto out;
extent_item_pos = swarn.logical - found_key.objectid;
swarn.extent_item_size = found_key.offset;
eb = path->nodes[0];
ei = btrfs_item_ptr(eb, path->slots[0], struct btrfs_extent_item);
item_size = btrfs_item_size_nr(eb, path->slots[0]);
btrfs_release_path(path);
if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
do {
ret = tree_backref_for_extent(&ptr, eb, ei, item_size,
&ref_root, &ref_level);
printk_in_rcu(KERN_WARNING
"btrfs: %s at logical %llu on dev %s, "
"sector %llu: metadata %s (level %d) in tree "
"%llu\n", errstr, swarn.logical,
rcu_str_deref(dev->name),
(unsigned long long)swarn.sector,
ref_level ? "node" : "leaf",
ret < 0 ? -1 : ref_level,
ret < 0 ? -1 : ref_root);
} while (ret != 1);
} else {
swarn.path = path;
iterate_extent_inodes(fs_info, found_key.objectid,
extent_item_pos, 1,
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
printk_ratelimited_in_rcu(KERN_ERR
"btrfs: unable to fixup (nodatasum) error at logical %llu on dev %s\n",
(unsigned long long)fixup->logical,
rcu_str_deref(sdev->dev->name));
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
static int scrub_handle_errored_block(struct scrub_block *sblock_to_check)
{
struct scrub_dev *sdev = sblock_to_check->sdev;
struct btrfs_fs_info *fs_info;
u64 length;
u64 logical;
u64 generation;
unsigned int failed_mirror_index;
unsigned int is_metadata;
unsigned int have_csum;
u8 *csum;
struct scrub_block *sblocks_for_recheck;
struct scrub_block *sblock_bad;
int ret;
int mirror_index;
int page_num;
int success;
static DEFINE_RATELIMIT_STATE(_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
BUG_ON(sblock_to_check->page_count < 1);
fs_info = sdev->dev->dev_root->fs_info;
length = sblock_to_check->page_count * PAGE_SIZE;
logical = sblock_to_check->pagev[0].logical;
generation = sblock_to_check->pagev[0].generation;
BUG_ON(sblock_to_check->pagev[0].mirror_num < 1);
failed_mirror_index = sblock_to_check->pagev[0].mirror_num - 1;
is_metadata = !(sblock_to_check->pagev[0].flags &
BTRFS_EXTENT_FLAG_DATA);
have_csum = sblock_to_check->pagev[0].have_csum;
csum = sblock_to_check->pagev[0].csum;
sblocks_for_recheck = kzalloc(BTRFS_MAX_MIRRORS *
sizeof(*sblocks_for_recheck),
GFP_NOFS);
if (!sblocks_for_recheck) {
spin_lock(&sdev->stat_lock);
sdev->stat.malloc_errors++;
sdev->stat.read_errors++;
sdev->stat.uncorrectable_errors++;
spin_unlock(&sdev->stat_lock);
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_READ_ERRS);
goto out;
}
ret = scrub_setup_recheck_block(sdev, &fs_info->mapping_tree, length,
logical, sblocks_for_recheck);
if (ret) {
spin_lock(&sdev->stat_lock);
sdev->stat.read_errors++;
sdev->stat.uncorrectable_errors++;
spin_unlock(&sdev->stat_lock);
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_READ_ERRS);
goto out;
}
BUG_ON(failed_mirror_index >= BTRFS_MAX_MIRRORS);
sblock_bad = sblocks_for_recheck + failed_mirror_index;
ret = scrub_recheck_block(fs_info, sblock_bad, is_metadata, have_csum,
csum, generation, sdev->csum_size);
if (ret) {
spin_lock(&sdev->stat_lock);
sdev->stat.read_errors++;
sdev->stat.uncorrectable_errors++;
spin_unlock(&sdev->stat_lock);
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_READ_ERRS);
goto out;
}
if (!sblock_bad->header_error && !sblock_bad->checksum_error &&
sblock_bad->no_io_error_seen) {
spin_lock(&sdev->stat_lock);
sdev->stat.unverified_errors++;
spin_unlock(&sdev->stat_lock);
goto out;
}
if (!sblock_bad->no_io_error_seen) {
spin_lock(&sdev->stat_lock);
sdev->stat.read_errors++;
spin_unlock(&sdev->stat_lock);
if (__ratelimit(&_rs))
scrub_print_warning("i/o error", sblock_to_check);
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_READ_ERRS);
} else if (sblock_bad->checksum_error) {
spin_lock(&sdev->stat_lock);
sdev->stat.csum_errors++;
spin_unlock(&sdev->stat_lock);
if (__ratelimit(&_rs))
scrub_print_warning("checksum error", sblock_to_check);
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_CORRUPTION_ERRS);
} else if (sblock_bad->header_error) {
spin_lock(&sdev->stat_lock);
sdev->stat.verify_errors++;
spin_unlock(&sdev->stat_lock);
if (__ratelimit(&_rs))
scrub_print_warning("checksum/header error",
sblock_to_check);
if (sblock_bad->generation_error)
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_GENERATION_ERRS);
else
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_CORRUPTION_ERRS);
}
if (sdev->readonly)
goto did_not_correct_error;
if (!is_metadata && !have_csum) {
struct scrub_fixup_nodatasum *fixup_nodatasum;
fixup_nodatasum = kzalloc(sizeof(*fixup_nodatasum), GFP_NOFS);
if (!fixup_nodatasum)
goto did_not_correct_error;
fixup_nodatasum->sdev = sdev;
fixup_nodatasum->logical = logical;
fixup_nodatasum->root = fs_info->extent_root;
fixup_nodatasum->mirror_num = failed_mirror_index + 1;
mutex_lock(&fs_info->scrub_lock);
atomic_inc(&fs_info->scrubs_running);
atomic_inc(&fs_info->scrubs_paused);
mutex_unlock(&fs_info->scrub_lock);
atomic_inc(&sdev->fixup_cnt);
fixup_nodatasum->work.func = scrub_fixup_nodatasum;
btrfs_queue_worker(&fs_info->scrub_workers,
&fixup_nodatasum->work);
goto out;
}
for (mirror_index = 0;
mirror_index < BTRFS_MAX_MIRRORS &&
sblocks_for_recheck[mirror_index].page_count > 0;
mirror_index++) {
if (mirror_index == failed_mirror_index)
continue;
ret = scrub_recheck_block(fs_info,
sblocks_for_recheck + mirror_index,
is_metadata, have_csum, csum,
generation, sdev->csum_size);
if (ret)
goto did_not_correct_error;
}
for (mirror_index = 0;
mirror_index < BTRFS_MAX_MIRRORS &&
sblocks_for_recheck[mirror_index].page_count > 0;
mirror_index++) {
struct scrub_block *sblock_other = sblocks_for_recheck +
mirror_index;
if (!sblock_other->header_error &&
!sblock_other->checksum_error &&
sblock_other->no_io_error_seen) {
int force_write = is_metadata || have_csum;
ret = scrub_repair_block_from_good_copy(sblock_bad,
sblock_other,
force_write);
if (0 == ret)
goto corrected_error;
}
}
if (sblock_bad->no_io_error_seen)
goto did_not_correct_error;
success = 1;
for (page_num = 0; page_num < sblock_bad->page_count; page_num++) {
struct scrub_page *page_bad = sblock_bad->pagev + page_num;
if (!page_bad->io_error)
continue;
for (mirror_index = 0;
mirror_index < BTRFS_MAX_MIRRORS &&
sblocks_for_recheck[mirror_index].page_count > 0;
mirror_index++) {
struct scrub_block *sblock_other = sblocks_for_recheck +
mirror_index;
struct scrub_page *page_other = sblock_other->pagev +
page_num;
if (!page_other->io_error) {
ret = scrub_repair_page_from_good_copy(
sblock_bad, sblock_other, page_num, 0);
if (0 == ret) {
page_bad->io_error = 0;
break;
}
}
}
if (page_bad->io_error) {
success = 0;
}
}
if (success) {
if (is_metadata || have_csum) {
ret = scrub_recheck_block(fs_info, sblock_bad,
is_metadata, have_csum, csum,
generation, sdev->csum_size);
if (!ret && !sblock_bad->header_error &&
!sblock_bad->checksum_error &&
sblock_bad->no_io_error_seen)
goto corrected_error;
else
goto did_not_correct_error;
} else {
corrected_error:
spin_lock(&sdev->stat_lock);
sdev->stat.corrected_errors++;
spin_unlock(&sdev->stat_lock);
printk_ratelimited_in_rcu(KERN_ERR
"btrfs: fixed up error at logical %llu on dev %s\n",
(unsigned long long)logical,
rcu_str_deref(sdev->dev->name));
}
} else {
did_not_correct_error:
spin_lock(&sdev->stat_lock);
sdev->stat.uncorrectable_errors++;
spin_unlock(&sdev->stat_lock);
printk_ratelimited_in_rcu(KERN_ERR
"btrfs: unable to fixup (regular) error at logical %llu on dev %s\n",
(unsigned long long)logical,
rcu_str_deref(sdev->dev->name));
}
out:
if (sblocks_for_recheck) {
for (mirror_index = 0; mirror_index < BTRFS_MAX_MIRRORS;
mirror_index++) {
struct scrub_block *sblock = sblocks_for_recheck +
mirror_index;
int page_index;
for (page_index = 0; page_index < SCRUB_PAGES_PER_BIO;
page_index++)
if (sblock->pagev[page_index].page)
__free_page(
sblock->pagev[page_index].page);
}
kfree(sblocks_for_recheck);
}
return 0;
}
static int scrub_setup_recheck_block(struct scrub_dev *sdev,
struct btrfs_mapping_tree *map_tree,
u64 length, u64 logical,
struct scrub_block *sblocks_for_recheck)
{
int page_index;
int mirror_index;
int ret;
page_index = 0;
while (length > 0) {
u64 sublen = min_t(u64, length, PAGE_SIZE);
u64 mapped_length = sublen;
struct btrfs_bio *bbio = NULL;
ret = btrfs_map_block(map_tree, WRITE, logical, &mapped_length,
&bbio, 0);
if (ret || !bbio || mapped_length < sublen) {
kfree(bbio);
return -EIO;
}
BUG_ON(page_index >= SCRUB_PAGES_PER_BIO);
for (mirror_index = 0; mirror_index < (int)bbio->num_stripes;
mirror_index++) {
struct scrub_block *sblock;
struct scrub_page *page;
if (mirror_index >= BTRFS_MAX_MIRRORS)
continue;
sblock = sblocks_for_recheck + mirror_index;
page = sblock->pagev + page_index;
page->logical = logical;
page->physical = bbio->stripes[mirror_index].physical;
page->dev = bbio->stripes[mirror_index].dev;
page->mirror_num = mirror_index + 1;
page->page = alloc_page(GFP_NOFS);
if (!page->page) {
spin_lock(&sdev->stat_lock);
sdev->stat.malloc_errors++;
spin_unlock(&sdev->stat_lock);
kfree(bbio);
return -ENOMEM;
}
sblock->page_count++;
}
kfree(bbio);
length -= sublen;
logical += sublen;
page_index++;
}
return 0;
}
static int scrub_recheck_block(struct btrfs_fs_info *fs_info,
struct scrub_block *sblock, int is_metadata,
int have_csum, u8 *csum, u64 generation,
u16 csum_size)
{
int page_num;
sblock->no_io_error_seen = 1;
sblock->header_error = 0;
sblock->checksum_error = 0;
for (page_num = 0; page_num < sblock->page_count; page_num++) {
struct bio *bio;
int ret;
struct scrub_page *page = sblock->pagev + page_num;
DECLARE_COMPLETION_ONSTACK(complete);
if (page->dev->bdev == NULL) {
page->io_error = 1;
sblock->no_io_error_seen = 0;
continue;
}
BUG_ON(!page->page);
bio = bio_alloc(GFP_NOFS, 1);
if (!bio)
return -EIO;
bio->bi_bdev = page->dev->bdev;
bio->bi_sector = page->physical >> 9;
bio->bi_end_io = scrub_complete_bio_end_io;
bio->bi_private = &complete;
ret = bio_add_page(bio, page->page, PAGE_SIZE, 0);
if (PAGE_SIZE != ret) {
bio_put(bio);
return -EIO;
}
btrfsic_submit_bio(READ, bio);
wait_for_completion(&complete);
page->io_error = !test_bit(BIO_UPTODATE, &bio->bi_flags);
if (!test_bit(BIO_UPTODATE, &bio->bi_flags))
sblock->no_io_error_seen = 0;
bio_put(bio);
}
if (sblock->no_io_error_seen)
scrub_recheck_block_checksum(fs_info, sblock, is_metadata,
have_csum, csum, generation,
csum_size);
return 0;
}
static void scrub_recheck_block_checksum(struct btrfs_fs_info *fs_info,
struct scrub_block *sblock,
int is_metadata, int have_csum,
const u8 *csum, u64 generation,
u16 csum_size)
{
int page_num;
u8 calculated_csum[BTRFS_CSUM_SIZE];
u32 crc = ~(u32)0;
struct btrfs_root *root = fs_info->extent_root;
void *mapped_buffer;
BUG_ON(!sblock->pagev[0].page);
if (is_metadata) {
struct btrfs_header *h;
mapped_buffer = kmap_atomic(sblock->pagev[0].page);
h = (struct btrfs_header *)mapped_buffer;
if (sblock->pagev[0].logical != le64_to_cpu(h->bytenr) ||
memcmp(h->fsid, fs_info->fsid, BTRFS_UUID_SIZE) ||
memcmp(h->chunk_tree_uuid, fs_info->chunk_tree_uuid,
BTRFS_UUID_SIZE)) {
sblock->header_error = 1;
} else if (generation != le64_to_cpu(h->generation)) {
sblock->header_error = 1;
sblock->generation_error = 1;
}
csum = h->csum;
} else {
if (!have_csum)
return;
mapped_buffer = kmap_atomic(sblock->pagev[0].page);
}
for (page_num = 0;;) {
if (page_num == 0 && is_metadata)
crc = btrfs_csum_data(root,
((u8 *)mapped_buffer) + BTRFS_CSUM_SIZE,
crc, PAGE_SIZE - BTRFS_CSUM_SIZE);
else
crc = btrfs_csum_data(root, mapped_buffer, crc,
PAGE_SIZE);
kunmap_atomic(mapped_buffer);
page_num++;
if (page_num >= sblock->page_count)
break;
BUG_ON(!sblock->pagev[page_num].page);
mapped_buffer = kmap_atomic(sblock->pagev[page_num].page);
}
btrfs_csum_final(crc, calculated_csum);
if (memcmp(calculated_csum, csum, csum_size))
sblock->checksum_error = 1;
}
static void scrub_complete_bio_end_io(struct bio *bio, int err)
{
complete((struct completion *)bio->bi_private);
}
static int scrub_repair_block_from_good_copy(struct scrub_block *sblock_bad,
struct scrub_block *sblock_good,
int force_write)
{
int page_num;
int ret = 0;
for (page_num = 0; page_num < sblock_bad->page_count; page_num++) {
int ret_sub;
ret_sub = scrub_repair_page_from_good_copy(sblock_bad,
sblock_good,
page_num,
force_write);
if (ret_sub)
ret = ret_sub;
}
return ret;
}
static int scrub_repair_page_from_good_copy(struct scrub_block *sblock_bad,
struct scrub_block *sblock_good,
int page_num, int force_write)
{
struct scrub_page *page_bad = sblock_bad->pagev + page_num;
struct scrub_page *page_good = sblock_good->pagev + page_num;
BUG_ON(sblock_bad->pagev[page_num].page == NULL);
BUG_ON(sblock_good->pagev[page_num].page == NULL);
if (force_write || sblock_bad->header_error ||
sblock_bad->checksum_error || page_bad->io_error) {
struct bio *bio;
int ret;
DECLARE_COMPLETION_ONSTACK(complete);
bio = bio_alloc(GFP_NOFS, 1);
if (!bio)
return -EIO;
bio->bi_bdev = page_bad->dev->bdev;
bio->bi_sector = page_bad->physical >> 9;
bio->bi_end_io = scrub_complete_bio_end_io;
bio->bi_private = &complete;
ret = bio_add_page(bio, page_good->page, PAGE_SIZE, 0);
if (PAGE_SIZE != ret) {
bio_put(bio);
return -EIO;
}
btrfsic_submit_bio(WRITE, bio);
wait_for_completion(&complete);
if (!bio_flagged(bio, BIO_UPTODATE)) {
btrfs_dev_stat_inc_and_print(page_bad->dev,
BTRFS_DEV_STAT_WRITE_ERRS);
bio_put(bio);
return -EIO;
}
bio_put(bio);
}
return 0;
}
static void scrub_checksum(struct scrub_block *sblock)
{
u64 flags;
int ret;
BUG_ON(sblock->page_count < 1);
flags = sblock->pagev[0].flags;
ret = 0;
if (flags & BTRFS_EXTENT_FLAG_DATA)
ret = scrub_checksum_data(sblock);
else if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK)
ret = scrub_checksum_tree_block(sblock);
else if (flags & BTRFS_EXTENT_FLAG_SUPER)
(void)scrub_checksum_super(sblock);
else
WARN_ON(1);
if (ret)
scrub_handle_errored_block(sblock);
}
static int scrub_checksum_data(struct scrub_block *sblock)
{
struct scrub_dev *sdev = sblock->sdev;
u8 csum[BTRFS_CSUM_SIZE];
u8 *on_disk_csum;
struct page *page;
void *buffer;
u32 crc = ~(u32)0;
int fail = 0;
struct btrfs_root *root = sdev->dev->dev_root;
u64 len;
int index;
BUG_ON(sblock->page_count < 1);
if (!sblock->pagev[0].have_csum)
return 0;
on_disk_csum = sblock->pagev[0].csum;
page = sblock->pagev[0].page;
buffer = kmap_atomic(page);
len = sdev->sectorsize;
index = 0;
for (;;) {
u64 l = min_t(u64, len, PAGE_SIZE);
crc = btrfs_csum_data(root, buffer, crc, l);
kunmap_atomic(buffer);
len -= l;
if (len == 0)
break;
index++;
BUG_ON(index >= sblock->page_count);
BUG_ON(!sblock->pagev[index].page);
page = sblock->pagev[index].page;
buffer = kmap_atomic(page);
}
btrfs_csum_final(crc, csum);
if (memcmp(csum, on_disk_csum, sdev->csum_size))
fail = 1;
return fail;
}
static int scrub_checksum_tree_block(struct scrub_block *sblock)
{
struct scrub_dev *sdev = sblock->sdev;
struct btrfs_header *h;
struct btrfs_root *root = sdev->dev->dev_root;
struct btrfs_fs_info *fs_info = root->fs_info;
u8 calculated_csum[BTRFS_CSUM_SIZE];
u8 on_disk_csum[BTRFS_CSUM_SIZE];
struct page *page;
void *mapped_buffer;
u64 mapped_size;
void *p;
u32 crc = ~(u32)0;
int fail = 0;
int crc_fail = 0;
u64 len;
int index;
BUG_ON(sblock->page_count < 1);
page = sblock->pagev[0].page;
mapped_buffer = kmap_atomic(page);
h = (struct btrfs_header *)mapped_buffer;
memcpy(on_disk_csum, h->csum, sdev->csum_size);
if (sblock->pagev[0].logical != le64_to_cpu(h->bytenr))
++fail;
if (sblock->pagev[0].generation != le64_to_cpu(h->generation))
++fail;
if (memcmp(h->fsid, fs_info->fsid, BTRFS_UUID_SIZE))
++fail;
if (memcmp(h->chunk_tree_uuid, fs_info->chunk_tree_uuid,
BTRFS_UUID_SIZE))
++fail;
BUG_ON(sdev->nodesize != sdev->leafsize);
len = sdev->nodesize - BTRFS_CSUM_SIZE;
mapped_size = PAGE_SIZE - BTRFS_CSUM_SIZE;
p = ((u8 *)mapped_buffer) + BTRFS_CSUM_SIZE;
index = 0;
for (;;) {
u64 l = min_t(u64, len, mapped_size);
crc = btrfs_csum_data(root, p, crc, l);
kunmap_atomic(mapped_buffer);
len -= l;
if (len == 0)
break;
index++;
BUG_ON(index >= sblock->page_count);
BUG_ON(!sblock->pagev[index].page);
page = sblock->pagev[index].page;
mapped_buffer = kmap_atomic(page);
mapped_size = PAGE_SIZE;
p = mapped_buffer;
}
btrfs_csum_final(crc, calculated_csum);
if (memcmp(calculated_csum, on_disk_csum, sdev->csum_size))
++crc_fail;
return fail || crc_fail;
}
static int scrub_checksum_super(struct scrub_block *sblock)
{
struct btrfs_super_block *s;
struct scrub_dev *sdev = sblock->sdev;
struct btrfs_root *root = sdev->dev->dev_root;
struct btrfs_fs_info *fs_info = root->fs_info;
u8 calculated_csum[BTRFS_CSUM_SIZE];
u8 on_disk_csum[BTRFS_CSUM_SIZE];
struct page *page;
void *mapped_buffer;
u64 mapped_size;
void *p;
u32 crc = ~(u32)0;
int fail_gen = 0;
int fail_cor = 0;
u64 len;
int index;
BUG_ON(sblock->page_count < 1);
page = sblock->pagev[0].page;
mapped_buffer = kmap_atomic(page);
s = (struct btrfs_super_block *)mapped_buffer;
memcpy(on_disk_csum, s->csum, sdev->csum_size);
if (sblock->pagev[0].logical != le64_to_cpu(s->bytenr))
++fail_cor;
if (sblock->pagev[0].generation != le64_to_cpu(s->generation))
++fail_gen;
if (memcmp(s->fsid, fs_info->fsid, BTRFS_UUID_SIZE))
++fail_cor;
len = BTRFS_SUPER_INFO_SIZE - BTRFS_CSUM_SIZE;
mapped_size = PAGE_SIZE - BTRFS_CSUM_SIZE;
p = ((u8 *)mapped_buffer) + BTRFS_CSUM_SIZE;
index = 0;
for (;;) {
u64 l = min_t(u64, len, mapped_size);
crc = btrfs_csum_data(root, p, crc, l);
kunmap_atomic(mapped_buffer);
len -= l;
if (len == 0)
break;
index++;
BUG_ON(index >= sblock->page_count);
BUG_ON(!sblock->pagev[index].page);
page = sblock->pagev[index].page;
mapped_buffer = kmap_atomic(page);
mapped_size = PAGE_SIZE;
p = mapped_buffer;
}
btrfs_csum_final(crc, calculated_csum);
if (memcmp(calculated_csum, on_disk_csum, sdev->csum_size))
++fail_cor;
if (fail_cor + fail_gen) {
spin_lock(&sdev->stat_lock);
++sdev->stat.super_errors;
spin_unlock(&sdev->stat_lock);
if (fail_cor)
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_CORRUPTION_ERRS);
else
btrfs_dev_stat_inc_and_print(sdev->dev,
BTRFS_DEV_STAT_GENERATION_ERRS);
}
return fail_cor + fail_gen;
}
static void scrub_block_get(struct scrub_block *sblock)
{
atomic_inc(&sblock->ref_count);
}
static void scrub_block_put(struct scrub_block *sblock)
{
if (atomic_dec_and_test(&sblock->ref_count)) {
int i;
for (i = 0; i < sblock->page_count; i++)
if (sblock->pagev[i].page)
__free_page(sblock->pagev[i].page);
kfree(sblock);
}
}
static void scrub_submit(struct scrub_dev *sdev)
{
struct scrub_bio *sbio;
if (sdev->curr == -1)
return;
sbio = sdev->bios[sdev->curr];
sdev->curr = -1;
atomic_inc(&sdev->in_flight);
btrfsic_submit_bio(READ, sbio->bio);
}
static int scrub_add_page_to_bio(struct scrub_dev *sdev,
struct scrub_page *spage)
{
struct scrub_block *sblock = spage->sblock;
struct scrub_bio *sbio;
int ret;
again:
while (sdev->curr == -1) {
spin_lock(&sdev->list_lock);
sdev->curr = sdev->first_free;
if (sdev->curr != -1) {
sdev->first_free = sdev->bios[sdev->curr]->next_free;
sdev->bios[sdev->curr]->next_free = -1;
sdev->bios[sdev->curr]->page_count = 0;
spin_unlock(&sdev->list_lock);
} else {
spin_unlock(&sdev->list_lock);
wait_event(sdev->list_wait, sdev->first_free != -1);
}
}
sbio = sdev->bios[sdev->curr];
if (sbio->page_count == 0) {
struct bio *bio;
sbio->physical = spage->physical;
sbio->logical = spage->logical;
bio = sbio->bio;
if (!bio) {
bio = bio_alloc(GFP_NOFS, sdev->pages_per_bio);
if (!bio)
return -ENOMEM;
sbio->bio = bio;
}
bio->bi_private = sbio;
bio->bi_end_io = scrub_bio_end_io;
bio->bi_bdev = sdev->dev->bdev;
bio->bi_sector = spage->physical >> 9;
sbio->err = 0;
} else if (sbio->physical + sbio->page_count * PAGE_SIZE !=
spage->physical ||
sbio->logical + sbio->page_count * PAGE_SIZE !=
spage->logical) {
scrub_submit(sdev);
goto again;
}
sbio->pagev[sbio->page_count] = spage;
ret = bio_add_page(sbio->bio, spage->page, PAGE_SIZE, 0);
if (ret != PAGE_SIZE) {
if (sbio->page_count < 1) {
bio_put(sbio->bio);
sbio->bio = NULL;
return -EIO;
}
scrub_submit(sdev);
goto again;
}
scrub_block_get(sblock);
atomic_inc(&sblock->outstanding_pages);
sbio->page_count++;
if (sbio->page_count == sdev->pages_per_bio)
scrub_submit(sdev);
return 0;
}
static int scrub_pages(struct scrub_dev *sdev, u64 logical, u64 len,
u64 physical, u64 flags, u64 gen, int mirror_num,
u8 *csum, int force)
{
struct scrub_block *sblock;
int index;
sblock = kzalloc(sizeof(*sblock), GFP_NOFS);
if (!sblock) {
spin_lock(&sdev->stat_lock);
sdev->stat.malloc_errors++;
spin_unlock(&sdev->stat_lock);
return -ENOMEM;
}
atomic_set(&sblock->ref_count, 1);
sblock->sdev = sdev;
sblock->no_io_error_seen = 1;
for (index = 0; len > 0; index++) {
struct scrub_page *spage = sblock->pagev + index;
u64 l = min_t(u64, len, PAGE_SIZE);
BUG_ON(index >= SCRUB_MAX_PAGES_PER_BLOCK);
spage->page = alloc_page(GFP_NOFS);
if (!spage->page) {
spin_lock(&sdev->stat_lock);
sdev->stat.malloc_errors++;
spin_unlock(&sdev->stat_lock);
while (index > 0) {
index--;
__free_page(sblock->pagev[index].page);
}
kfree(sblock);
return -ENOMEM;
}
spage->sblock = sblock;
spage->dev = sdev->dev;
spage->flags = flags;
spage->generation = gen;
spage->logical = logical;
spage->physical = physical;
spage->mirror_num = mirror_num;
if (csum) {
spage->have_csum = 1;
memcpy(spage->csum, csum, sdev->csum_size);
} else {
spage->have_csum = 0;
}
sblock->page_count++;
len -= l;
logical += l;
physical += l;
}
BUG_ON(sblock->page_count == 0);
for (index = 0; index < sblock->page_count; index++) {
struct scrub_page *spage = sblock->pagev + index;
int ret;
ret = scrub_add_page_to_bio(sdev, spage);
if (ret) {
scrub_block_put(sblock);
return ret;
}
}
if (force)
scrub_submit(sdev);
scrub_block_put(sblock);
return 0;
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
static void scrub_bio_end_io_worker(struct btrfs_work *work)
{
struct scrub_bio *sbio = container_of(work, struct scrub_bio, work);
struct scrub_dev *sdev = sbio->sdev;
int i;
BUG_ON(sbio->page_count > SCRUB_PAGES_PER_BIO);
if (sbio->err) {
for (i = 0; i < sbio->page_count; i++) {
struct scrub_page *spage = sbio->pagev[i];
spage->io_error = 1;
spage->sblock->no_io_error_seen = 0;
}
}
for (i = 0; i < sbio->page_count; i++) {
struct scrub_page *spage = sbio->pagev[i];
struct scrub_block *sblock = spage->sblock;
if (atomic_dec_and_test(&sblock->outstanding_pages))
scrub_block_complete(sblock);
scrub_block_put(sblock);
}
bio_put(sbio->bio);
sbio->bio = NULL;
spin_lock(&sdev->list_lock);
sbio->next_free = sdev->first_free;
sdev->first_free = sbio->index;
spin_unlock(&sdev->list_lock);
atomic_dec(&sdev->in_flight);
wake_up(&sdev->list_wait);
}
static void scrub_block_complete(struct scrub_block *sblock)
{
if (!sblock->no_io_error_seen)
scrub_handle_errored_block(sblock);
else
scrub_checksum(sblock);
}
static int scrub_find_csum(struct scrub_dev *sdev, u64 logical, u64 len,
u8 *csum)
{
struct btrfs_ordered_sum *sum = NULL;
int ret = 0;
unsigned long i;
unsigned long num_sectors;
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
num_sectors = sum->len / sdev->sectorsize;
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
u32 blocksize;
if (flags & BTRFS_EXTENT_FLAG_DATA) {
blocksize = sdev->sectorsize;
spin_lock(&sdev->stat_lock);
sdev->stat.data_extents_scrubbed++;
sdev->stat.data_bytes_scrubbed += len;
spin_unlock(&sdev->stat_lock);
} else if (flags & BTRFS_EXTENT_FLAG_TREE_BLOCK) {
BUG_ON(sdev->nodesize != sdev->leafsize);
blocksize = sdev->nodesize;
spin_lock(&sdev->stat_lock);
sdev->stat.tree_extents_scrubbed++;
sdev->stat.tree_bytes_scrubbed += len;
spin_unlock(&sdev->stat_lock);
} else {
blocksize = sdev->sectorsize;
BUG_ON(1);
}
while (len) {
u64 l = min_t(u64, len, blocksize);
int have_csum = 0;
if (flags & BTRFS_EXTENT_FLAG_DATA) {
have_csum = scrub_find_csum(sdev, logical, l, csum);
if (have_csum == 0)
++sdev->stat.no_csum;
}
ret = scrub_pages(sdev, logical, l, physical, flags, gen,
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
u64 chunk_tree, u64 chunk_objectid, u64 chunk_offset, u64 length,
u64 dev_offset)
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
if (map->stripes[i].dev == sdev->dev &&
map->stripes[i].physical == dev_offset) {
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
chunk_offset, length, found_key.offset);
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
if (root->fs_info->fs_state & BTRFS_SUPER_FLAG_ERROR)
return -EIO;
gen = root->fs_info->last_trans_committed;
for (i = 0; i < BTRFS_SUPER_MIRROR_MAX; i++) {
bytenr = btrfs_sb_offset(i);
if (bytenr + BTRFS_SUPER_INFO_SIZE > device->total_bytes)
break;
ret = scrub_pages(sdev, bytenr, BTRFS_SUPER_INFO_SIZE, bytenr,
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
if (root->nodesize != root->leafsize) {
printk(KERN_ERR
"btrfs_scrub: size assumption nodesize == leafsize (%d == %d) fails\n",
root->nodesize, root->leafsize);
return -EINVAL;
}
if (root->nodesize > BTRFS_STRIPE_LEN) {
printk(KERN_ERR
"btrfs_scrub: size assumption nodesize <= BTRFS_STRIPE_LEN (%d <= %d) fails\n",
root->nodesize, BTRFS_STRIPE_LEN);
return -EINVAL;
}
if (root->sectorsize != PAGE_SIZE) {
printk(KERN_ERR
"btrfs_scrub: size assumption sectorsize != PAGE_SIZE (%d != %lld) fails\n",
root->sectorsize, (unsigned long long)PAGE_SIZE);
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
void btrfs_scrub_pause(struct btrfs_root *root)
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
}
void btrfs_scrub_continue(struct btrfs_root *root)
{
struct btrfs_fs_info *fs_info = root->fs_info;
atomic_dec(&fs_info->scrub_pause_req);
wake_up(&fs_info->scrub_pause_wait);
}
void btrfs_scrub_pause_super(struct btrfs_root *root)
{
down_write(&root->fs_info->scrub_super_lock);
}
void btrfs_scrub_continue_super(struct btrfs_root *root)
{
up_write(&root->fs_info->scrub_super_lock);
}
int __btrfs_scrub_cancel(struct btrfs_fs_info *fs_info)
{
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
int btrfs_scrub_cancel(struct btrfs_root *root)
{
return __btrfs_scrub_cancel(root->fs_info);
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
