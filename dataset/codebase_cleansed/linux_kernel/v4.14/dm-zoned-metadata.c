unsigned int dmz_id(struct dmz_metadata *zmd, struct dm_zone *zone)
{
return ((unsigned int)(zone - zmd->zones));
}
sector_t dmz_start_sect(struct dmz_metadata *zmd, struct dm_zone *zone)
{
return (sector_t)dmz_id(zmd, zone) << zmd->dev->zone_nr_sectors_shift;
}
sector_t dmz_start_block(struct dmz_metadata *zmd, struct dm_zone *zone)
{
return (sector_t)dmz_id(zmd, zone) << zmd->dev->zone_nr_blocks_shift;
}
unsigned int dmz_nr_chunks(struct dmz_metadata *zmd)
{
return zmd->nr_chunks;
}
unsigned int dmz_nr_rnd_zones(struct dmz_metadata *zmd)
{
return zmd->nr_rnd;
}
unsigned int dmz_nr_unmap_rnd_zones(struct dmz_metadata *zmd)
{
return atomic_read(&zmd->unmap_nr_rnd);
}
void dmz_lock_map(struct dmz_metadata *zmd)
{
mutex_lock(&zmd->map_lock);
}
void dmz_unlock_map(struct dmz_metadata *zmd)
{
mutex_unlock(&zmd->map_lock);
}
void dmz_lock_metadata(struct dmz_metadata *zmd)
{
down_read(&zmd->mblk_sem);
}
void dmz_unlock_metadata(struct dmz_metadata *zmd)
{
up_read(&zmd->mblk_sem);
}
void dmz_lock_flush(struct dmz_metadata *zmd)
{
mutex_lock(&zmd->mblk_flush_lock);
}
void dmz_unlock_flush(struct dmz_metadata *zmd)
{
mutex_unlock(&zmd->mblk_flush_lock);
}
static struct dmz_mblock *dmz_alloc_mblock(struct dmz_metadata *zmd,
sector_t mblk_no)
{
struct dmz_mblock *mblk = NULL;
if (zmd->max_nr_mblks && atomic_read(&zmd->nr_mblks) > zmd->max_nr_mblks) {
spin_lock(&zmd->mblk_lock);
mblk = list_first_entry_or_null(&zmd->mblk_lru_list,
struct dmz_mblock, link);
if (mblk) {
list_del_init(&mblk->link);
rb_erase(&mblk->node, &zmd->mblk_rbtree);
mblk->no = mblk_no;
}
spin_unlock(&zmd->mblk_lock);
if (mblk)
return mblk;
}
mblk = kmalloc(sizeof(struct dmz_mblock), GFP_NOIO);
if (!mblk)
return NULL;
mblk->page = alloc_page(GFP_NOIO);
if (!mblk->page) {
kfree(mblk);
return NULL;
}
RB_CLEAR_NODE(&mblk->node);
INIT_LIST_HEAD(&mblk->link);
atomic_set(&mblk->ref, 0);
mblk->state = 0;
mblk->no = mblk_no;
mblk->data = page_address(mblk->page);
atomic_inc(&zmd->nr_mblks);
return mblk;
}
static void dmz_free_mblock(struct dmz_metadata *zmd, struct dmz_mblock *mblk)
{
__free_pages(mblk->page, 0);
kfree(mblk);
atomic_dec(&zmd->nr_mblks);
}
static void dmz_insert_mblock(struct dmz_metadata *zmd, struct dmz_mblock *mblk)
{
struct rb_root *root = &zmd->mblk_rbtree;
struct rb_node **new = &(root->rb_node), *parent = NULL;
struct dmz_mblock *b;
while (*new) {
b = container_of(*new, struct dmz_mblock, node);
parent = *new;
new = (b->no < mblk->no) ? &((*new)->rb_left) : &((*new)->rb_right);
}
rb_link_node(&mblk->node, parent, new);
rb_insert_color(&mblk->node, root);
}
static struct dmz_mblock *dmz_lookup_mblock(struct dmz_metadata *zmd,
sector_t mblk_no)
{
struct rb_root *root = &zmd->mblk_rbtree;
struct rb_node *node = root->rb_node;
struct dmz_mblock *mblk;
while (node) {
mblk = container_of(node, struct dmz_mblock, node);
if (mblk->no == mblk_no)
return mblk;
node = (mblk->no < mblk_no) ? node->rb_left : node->rb_right;
}
return NULL;
}
static void dmz_mblock_bio_end_io(struct bio *bio)
{
struct dmz_mblock *mblk = bio->bi_private;
int flag;
if (bio->bi_status)
set_bit(DMZ_META_ERROR, &mblk->state);
if (bio_op(bio) == REQ_OP_WRITE)
flag = DMZ_META_WRITING;
else
flag = DMZ_META_READING;
clear_bit_unlock(flag, &mblk->state);
smp_mb__after_atomic();
wake_up_bit(&mblk->state, flag);
bio_put(bio);
}
static struct dmz_mblock *dmz_fetch_mblock(struct dmz_metadata *zmd,
sector_t mblk_no)
{
struct dmz_mblock *mblk;
sector_t block = zmd->sb[zmd->mblk_primary].block + mblk_no;
struct bio *bio;
mblk = dmz_alloc_mblock(zmd, mblk_no);
if (!mblk)
return NULL;
spin_lock(&zmd->mblk_lock);
atomic_inc(&mblk->ref);
set_bit(DMZ_META_READING, &mblk->state);
dmz_insert_mblock(zmd, mblk);
spin_unlock(&zmd->mblk_lock);
bio = bio_alloc(GFP_NOIO, 1);
if (!bio) {
dmz_free_mblock(zmd, mblk);
return NULL;
}
bio->bi_iter.bi_sector = dmz_blk2sect(block);
bio_set_dev(bio, zmd->dev->bdev);
bio->bi_private = mblk;
bio->bi_end_io = dmz_mblock_bio_end_io;
bio_set_op_attrs(bio, REQ_OP_READ, REQ_META | REQ_PRIO);
bio_add_page(bio, mblk->page, DMZ_BLOCK_SIZE, 0);
submit_bio(bio);
return mblk;
}
static unsigned long dmz_shrink_mblock_cache(struct dmz_metadata *zmd,
unsigned long limit)
{
struct dmz_mblock *mblk;
unsigned long count = 0;
if (!zmd->max_nr_mblks)
return 0;
while (!list_empty(&zmd->mblk_lru_list) &&
atomic_read(&zmd->nr_mblks) > zmd->min_nr_mblks &&
count < limit) {
mblk = list_first_entry(&zmd->mblk_lru_list,
struct dmz_mblock, link);
list_del_init(&mblk->link);
rb_erase(&mblk->node, &zmd->mblk_rbtree);
dmz_free_mblock(zmd, mblk);
count++;
}
return count;
}
static unsigned long dmz_mblock_shrinker_count(struct shrinker *shrink,
struct shrink_control *sc)
{
struct dmz_metadata *zmd = container_of(shrink, struct dmz_metadata, mblk_shrinker);
return atomic_read(&zmd->nr_mblks);
}
static unsigned long dmz_mblock_shrinker_scan(struct shrinker *shrink,
struct shrink_control *sc)
{
struct dmz_metadata *zmd = container_of(shrink, struct dmz_metadata, mblk_shrinker);
unsigned long count;
spin_lock(&zmd->mblk_lock);
count = dmz_shrink_mblock_cache(zmd, sc->nr_to_scan);
spin_unlock(&zmd->mblk_lock);
return count ? count : SHRINK_STOP;
}
static void dmz_release_mblock(struct dmz_metadata *zmd,
struct dmz_mblock *mblk)
{
if (!mblk)
return;
spin_lock(&zmd->mblk_lock);
if (atomic_dec_and_test(&mblk->ref)) {
if (test_bit(DMZ_META_ERROR, &mblk->state)) {
rb_erase(&mblk->node, &zmd->mblk_rbtree);
dmz_free_mblock(zmd, mblk);
} else if (!test_bit(DMZ_META_DIRTY, &mblk->state)) {
list_add_tail(&mblk->link, &zmd->mblk_lru_list);
dmz_shrink_mblock_cache(zmd, 1);
}
}
spin_unlock(&zmd->mblk_lock);
}
static struct dmz_mblock *dmz_get_mblock(struct dmz_metadata *zmd,
sector_t mblk_no)
{
struct dmz_mblock *mblk;
spin_lock(&zmd->mblk_lock);
mblk = dmz_lookup_mblock(zmd, mblk_no);
if (mblk) {
if (atomic_inc_return(&mblk->ref) == 1 &&
!test_bit(DMZ_META_DIRTY, &mblk->state))
list_del_init(&mblk->link);
}
spin_unlock(&zmd->mblk_lock);
if (!mblk) {
mblk = dmz_fetch_mblock(zmd, mblk_no);
if (!mblk)
return ERR_PTR(-ENOMEM);
}
wait_on_bit_io(&mblk->state, DMZ_META_READING,
TASK_UNINTERRUPTIBLE);
if (test_bit(DMZ_META_ERROR, &mblk->state)) {
dmz_release_mblock(zmd, mblk);
return ERR_PTR(-EIO);
}
return mblk;
}
static void dmz_dirty_mblock(struct dmz_metadata *zmd, struct dmz_mblock *mblk)
{
spin_lock(&zmd->mblk_lock);
if (!test_and_set_bit(DMZ_META_DIRTY, &mblk->state))
list_add_tail(&mblk->link, &zmd->mblk_dirty_list);
spin_unlock(&zmd->mblk_lock);
}
static void dmz_write_mblock(struct dmz_metadata *zmd, struct dmz_mblock *mblk,
unsigned int set)
{
sector_t block = zmd->sb[set].block + mblk->no;
struct bio *bio;
bio = bio_alloc(GFP_NOIO, 1);
if (!bio) {
set_bit(DMZ_META_ERROR, &mblk->state);
return;
}
set_bit(DMZ_META_WRITING, &mblk->state);
bio->bi_iter.bi_sector = dmz_blk2sect(block);
bio_set_dev(bio, zmd->dev->bdev);
bio->bi_private = mblk;
bio->bi_end_io = dmz_mblock_bio_end_io;
bio_set_op_attrs(bio, REQ_OP_WRITE, REQ_META | REQ_PRIO);
bio_add_page(bio, mblk->page, DMZ_BLOCK_SIZE, 0);
submit_bio(bio);
}
static int dmz_rdwr_block(struct dmz_metadata *zmd, int op, sector_t block,
struct page *page)
{
struct bio *bio;
int ret;
bio = bio_alloc(GFP_NOIO, 1);
if (!bio)
return -ENOMEM;
bio->bi_iter.bi_sector = dmz_blk2sect(block);
bio_set_dev(bio, zmd->dev->bdev);
bio_set_op_attrs(bio, op, REQ_SYNC | REQ_META | REQ_PRIO);
bio_add_page(bio, page, DMZ_BLOCK_SIZE, 0);
ret = submit_bio_wait(bio);
bio_put(bio);
return ret;
}
static int dmz_write_sb(struct dmz_metadata *zmd, unsigned int set)
{
sector_t block = zmd->sb[set].block;
struct dmz_mblock *mblk = zmd->sb[set].mblk;
struct dmz_super *sb = zmd->sb[set].sb;
u64 sb_gen = zmd->sb_gen + 1;
int ret;
sb->magic = cpu_to_le32(DMZ_MAGIC);
sb->version = cpu_to_le32(DMZ_META_VER);
sb->gen = cpu_to_le64(sb_gen);
sb->sb_block = cpu_to_le64(block);
sb->nr_meta_blocks = cpu_to_le32(zmd->nr_meta_blocks);
sb->nr_reserved_seq = cpu_to_le32(zmd->nr_reserved_seq);
sb->nr_chunks = cpu_to_le32(zmd->nr_chunks);
sb->nr_map_blocks = cpu_to_le32(zmd->nr_map_blocks);
sb->nr_bitmap_blocks = cpu_to_le32(zmd->nr_bitmap_blocks);
sb->crc = 0;
sb->crc = cpu_to_le32(crc32_le(sb_gen, (unsigned char *)sb, DMZ_BLOCK_SIZE));
ret = dmz_rdwr_block(zmd, REQ_OP_WRITE, block, mblk->page);
if (ret == 0)
ret = blkdev_issue_flush(zmd->dev->bdev, GFP_NOIO, NULL);
return ret;
}
static int dmz_write_dirty_mblocks(struct dmz_metadata *zmd,
struct list_head *write_list,
unsigned int set)
{
struct dmz_mblock *mblk;
struct blk_plug plug;
int ret = 0;
blk_start_plug(&plug);
list_for_each_entry(mblk, write_list, link)
dmz_write_mblock(zmd, mblk, set);
blk_finish_plug(&plug);
list_for_each_entry(mblk, write_list, link) {
wait_on_bit_io(&mblk->state, DMZ_META_WRITING,
TASK_UNINTERRUPTIBLE);
if (test_bit(DMZ_META_ERROR, &mblk->state)) {
clear_bit(DMZ_META_ERROR, &mblk->state);
ret = -EIO;
}
}
if (ret == 0)
ret = blkdev_issue_flush(zmd->dev->bdev, GFP_NOIO, NULL);
return ret;
}
static int dmz_log_dirty_mblocks(struct dmz_metadata *zmd,
struct list_head *write_list)
{
unsigned int log_set = zmd->mblk_primary ^ 0x1;
int ret;
ret = dmz_write_dirty_mblocks(zmd, write_list, log_set);
if (ret)
return ret;
ret = dmz_write_sb(zmd, log_set);
if (ret)
return ret;
return 0;
}
int dmz_flush_metadata(struct dmz_metadata *zmd)
{
struct dmz_mblock *mblk;
struct list_head write_list;
int ret;
if (WARN_ON(!zmd))
return 0;
INIT_LIST_HEAD(&write_list);
down_write(&zmd->mblk_sem);
dmz_lock_flush(zmd);
spin_lock(&zmd->mblk_lock);
list_splice_init(&zmd->mblk_dirty_list, &write_list);
spin_unlock(&zmd->mblk_lock);
if (list_empty(&write_list)) {
ret = blkdev_issue_flush(zmd->dev->bdev, GFP_NOIO, NULL);
goto out;
}
ret = dmz_log_dirty_mblocks(zmd, &write_list);
if (ret)
goto out;
ret = dmz_write_dirty_mblocks(zmd, &write_list, zmd->mblk_primary);
if (ret)
goto out;
ret = dmz_write_sb(zmd, zmd->mblk_primary);
if (ret)
goto out;
while (!list_empty(&write_list)) {
mblk = list_first_entry(&write_list, struct dmz_mblock, link);
list_del_init(&mblk->link);
spin_lock(&zmd->mblk_lock);
clear_bit(DMZ_META_DIRTY, &mblk->state);
if (atomic_read(&mblk->ref) == 0)
list_add_tail(&mblk->link, &zmd->mblk_lru_list);
spin_unlock(&zmd->mblk_lock);
}
zmd->sb_gen++;
out:
if (ret && !list_empty(&write_list)) {
spin_lock(&zmd->mblk_lock);
list_splice(&write_list, &zmd->mblk_dirty_list);
spin_unlock(&zmd->mblk_lock);
}
dmz_unlock_flush(zmd);
up_write(&zmd->mblk_sem);
return ret;
}
static int dmz_check_sb(struct dmz_metadata *zmd, struct dmz_super *sb)
{
unsigned int nr_meta_zones, nr_data_zones;
struct dmz_dev *dev = zmd->dev;
u32 crc, stored_crc;
u64 gen;
gen = le64_to_cpu(sb->gen);
stored_crc = le32_to_cpu(sb->crc);
sb->crc = 0;
crc = crc32_le(gen, (unsigned char *)sb, DMZ_BLOCK_SIZE);
if (crc != stored_crc) {
dmz_dev_err(dev, "Invalid checksum (needed 0x%08x, got 0x%08x)",
crc, stored_crc);
return -ENXIO;
}
if (le32_to_cpu(sb->magic) != DMZ_MAGIC) {
dmz_dev_err(dev, "Invalid meta magic (needed 0x%08x, got 0x%08x)",
DMZ_MAGIC, le32_to_cpu(sb->magic));
return -ENXIO;
}
if (le32_to_cpu(sb->version) != DMZ_META_VER) {
dmz_dev_err(dev, "Invalid meta version (needed %d, got %d)",
DMZ_META_VER, le32_to_cpu(sb->version));
return -ENXIO;
}
nr_meta_zones = (le32_to_cpu(sb->nr_meta_blocks) + dev->zone_nr_blocks - 1)
>> dev->zone_nr_blocks_shift;
if (!nr_meta_zones ||
nr_meta_zones >= zmd->nr_rnd_zones) {
dmz_dev_err(dev, "Invalid number of metadata blocks");
return -ENXIO;
}
if (!le32_to_cpu(sb->nr_reserved_seq) ||
le32_to_cpu(sb->nr_reserved_seq) >= (zmd->nr_useable_zones - nr_meta_zones)) {
dmz_dev_err(dev, "Invalid number of reserved sequential zones");
return -ENXIO;
}
nr_data_zones = zmd->nr_useable_zones -
(nr_meta_zones * 2 + le32_to_cpu(sb->nr_reserved_seq));
if (le32_to_cpu(sb->nr_chunks) > nr_data_zones) {
dmz_dev_err(dev, "Invalid number of chunks %u / %u",
le32_to_cpu(sb->nr_chunks), nr_data_zones);
return -ENXIO;
}
zmd->nr_meta_blocks = le32_to_cpu(sb->nr_meta_blocks);
zmd->nr_reserved_seq = le32_to_cpu(sb->nr_reserved_seq);
zmd->nr_chunks = le32_to_cpu(sb->nr_chunks);
zmd->nr_map_blocks = le32_to_cpu(sb->nr_map_blocks);
zmd->nr_bitmap_blocks = le32_to_cpu(sb->nr_bitmap_blocks);
zmd->nr_meta_zones = nr_meta_zones;
zmd->nr_data_zones = nr_data_zones;
return 0;
}
static int dmz_read_sb(struct dmz_metadata *zmd, unsigned int set)
{
return dmz_rdwr_block(zmd, REQ_OP_READ, zmd->sb[set].block,
zmd->sb[set].mblk->page);
}
static int dmz_lookup_secondary_sb(struct dmz_metadata *zmd)
{
unsigned int zone_nr_blocks = zmd->dev->zone_nr_blocks;
struct dmz_mblock *mblk;
int i;
mblk = dmz_alloc_mblock(zmd, 0);
if (!mblk)
return -ENOMEM;
zmd->sb[1].mblk = mblk;
zmd->sb[1].sb = mblk->data;
zmd->sb[1].block = zmd->sb[0].block + zone_nr_blocks;
for (i = 0; i < zmd->nr_rnd_zones - 1; i++) {
if (dmz_read_sb(zmd, 1) != 0)
break;
if (le32_to_cpu(zmd->sb[1].sb->magic) == DMZ_MAGIC)
return 0;
zmd->sb[1].block += zone_nr_blocks;
}
dmz_free_mblock(zmd, mblk);
zmd->sb[1].mblk = NULL;
return -EIO;
}
static int dmz_get_sb(struct dmz_metadata *zmd, unsigned int set)
{
struct dmz_mblock *mblk;
int ret;
mblk = dmz_alloc_mblock(zmd, 0);
if (!mblk)
return -ENOMEM;
zmd->sb[set].mblk = mblk;
zmd->sb[set].sb = mblk->data;
ret = dmz_read_sb(zmd, set);
if (ret) {
dmz_free_mblock(zmd, mblk);
zmd->sb[set].mblk = NULL;
return ret;
}
return 0;
}
static int dmz_recover_mblocks(struct dmz_metadata *zmd, unsigned int dst_set)
{
unsigned int src_set = dst_set ^ 0x1;
struct page *page;
int i, ret;
dmz_dev_warn(zmd->dev, "Metadata set %u invalid: recovering", dst_set);
if (dst_set == 0)
zmd->sb[0].block = dmz_start_block(zmd, zmd->sb_zone);
else {
zmd->sb[1].block = zmd->sb[0].block +
(zmd->nr_meta_zones << zmd->dev->zone_nr_blocks_shift);
}
page = alloc_page(GFP_NOIO);
if (!page)
return -ENOMEM;
for (i = 1; i < zmd->nr_meta_blocks; i++) {
ret = dmz_rdwr_block(zmd, REQ_OP_READ,
zmd->sb[src_set].block + i, page);
if (ret)
goto out;
ret = dmz_rdwr_block(zmd, REQ_OP_WRITE,
zmd->sb[dst_set].block + i, page);
if (ret)
goto out;
}
if (!zmd->sb[dst_set].mblk) {
zmd->sb[dst_set].mblk = dmz_alloc_mblock(zmd, 0);
if (!zmd->sb[dst_set].mblk) {
ret = -ENOMEM;
goto out;
}
zmd->sb[dst_set].sb = zmd->sb[dst_set].mblk->data;
}
ret = dmz_write_sb(zmd, dst_set);
out:
__free_pages(page, 0);
return ret;
}
static int dmz_load_sb(struct dmz_metadata *zmd)
{
bool sb_good[2] = {false, false};
u64 sb_gen[2] = {0, 0};
int ret;
zmd->sb[0].block = dmz_start_block(zmd, zmd->sb_zone);
ret = dmz_get_sb(zmd, 0);
if (ret) {
dmz_dev_err(zmd->dev, "Read primary super block failed");
return ret;
}
ret = dmz_check_sb(zmd, zmd->sb[0].sb);
if (ret == 0) {
sb_good[0] = true;
zmd->sb[1].block = zmd->sb[0].block +
(zmd->nr_meta_zones << zmd->dev->zone_nr_blocks_shift);
ret = dmz_get_sb(zmd, 1);
} else
ret = dmz_lookup_secondary_sb(zmd);
if (ret) {
dmz_dev_err(zmd->dev, "Read secondary super block failed");
return ret;
}
ret = dmz_check_sb(zmd, zmd->sb[1].sb);
if (ret == 0)
sb_good[1] = true;
if (!sb_good[0] && !sb_good[1]) {
dmz_dev_err(zmd->dev, "No valid super block found");
return -EIO;
}
if (sb_good[0])
sb_gen[0] = le64_to_cpu(zmd->sb[0].sb->gen);
else
ret = dmz_recover_mblocks(zmd, 0);
if (sb_good[1])
sb_gen[1] = le64_to_cpu(zmd->sb[1].sb->gen);
else
ret = dmz_recover_mblocks(zmd, 1);
if (ret) {
dmz_dev_err(zmd->dev, "Recovery failed");
return -EIO;
}
if (sb_gen[0] >= sb_gen[1]) {
zmd->sb_gen = sb_gen[0];
zmd->mblk_primary = 0;
} else {
zmd->sb_gen = sb_gen[1];
zmd->mblk_primary = 1;
}
dmz_dev_debug(zmd->dev, "Using super block %u (gen %llu)",
zmd->mblk_primary, zmd->sb_gen);
return 0;
}
static int dmz_init_zone(struct dmz_metadata *zmd, struct dm_zone *zone,
struct blk_zone *blkz)
{
struct dmz_dev *dev = zmd->dev;
if (blkz->len != dev->zone_nr_sectors) {
if (blkz->start + blkz->len == dev->capacity)
return 0;
return -ENXIO;
}
INIT_LIST_HEAD(&zone->link);
atomic_set(&zone->refcount, 0);
zone->chunk = DMZ_MAP_UNMAPPED;
if (blkz->type == BLK_ZONE_TYPE_CONVENTIONAL) {
set_bit(DMZ_RND, &zone->flags);
zmd->nr_rnd_zones++;
} else if (blkz->type == BLK_ZONE_TYPE_SEQWRITE_REQ ||
blkz->type == BLK_ZONE_TYPE_SEQWRITE_PREF) {
set_bit(DMZ_SEQ, &zone->flags);
} else
return -ENXIO;
if (blkz->cond == BLK_ZONE_COND_OFFLINE)
set_bit(DMZ_OFFLINE, &zone->flags);
else if (blkz->cond == BLK_ZONE_COND_READONLY)
set_bit(DMZ_READ_ONLY, &zone->flags);
if (dmz_is_rnd(zone))
zone->wp_block = 0;
else
zone->wp_block = dmz_sect2blk(blkz->wp - blkz->start);
if (!dmz_is_offline(zone) && !dmz_is_readonly(zone)) {
zmd->nr_useable_zones++;
if (dmz_is_rnd(zone)) {
zmd->nr_rnd_zones++;
if (!zmd->sb_zone) {
zmd->sb_zone = zone;
}
}
}
return 0;
}
static void dmz_drop_zones(struct dmz_metadata *zmd)
{
kfree(zmd->zones);
zmd->zones = NULL;
}
static int dmz_init_zones(struct dmz_metadata *zmd)
{
struct dmz_dev *dev = zmd->dev;
struct dm_zone *zone;
struct blk_zone *blkz;
unsigned int nr_blkz;
sector_t sector = 0;
int i, ret = 0;
zmd->zone_bitmap_size = dev->zone_nr_blocks >> 3;
zmd->zone_nr_bitmap_blocks = zmd->zone_bitmap_size >> DMZ_BLOCK_SHIFT;
zmd->zones = kcalloc(dev->nr_zones, sizeof(struct dm_zone), GFP_KERNEL);
if (!zmd->zones)
return -ENOMEM;
dmz_dev_info(dev, "Using %zu B for zone information",
sizeof(struct dm_zone) * dev->nr_zones);
nr_blkz = DMZ_REPORT_NR_ZONES;
blkz = kcalloc(nr_blkz, sizeof(struct blk_zone), GFP_KERNEL);
if (!blkz) {
ret = -ENOMEM;
goto out;
}
zone = zmd->zones;
while (sector < dev->capacity) {
nr_blkz = DMZ_REPORT_NR_ZONES;
ret = blkdev_report_zones(dev->bdev, sector, blkz,
&nr_blkz, GFP_KERNEL);
if (ret) {
dmz_dev_err(dev, "Report zones failed %d", ret);
goto out;
}
for (i = 0; i < nr_blkz; i++) {
ret = dmz_init_zone(zmd, zone, &blkz[i]);
if (ret)
goto out;
sector += dev->zone_nr_sectors;
zone++;
}
}
if (sector < dev->capacity) {
dmz_dev_err(dev, "Failed to get correct zone information");
ret = -ENXIO;
}
out:
kfree(blkz);
if (ret)
dmz_drop_zones(zmd);
return ret;
}
static int dmz_update_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
unsigned int nr_blkz = 1;
struct blk_zone blkz;
int ret;
ret = blkdev_report_zones(zmd->dev->bdev, dmz_start_sect(zmd, zone),
&blkz, &nr_blkz, GFP_NOIO);
if (ret) {
dmz_dev_err(zmd->dev, "Get zone %u report failed",
dmz_id(zmd, zone));
return ret;
}
clear_bit(DMZ_OFFLINE, &zone->flags);
clear_bit(DMZ_READ_ONLY, &zone->flags);
if (blkz.cond == BLK_ZONE_COND_OFFLINE)
set_bit(DMZ_OFFLINE, &zone->flags);
else if (blkz.cond == BLK_ZONE_COND_READONLY)
set_bit(DMZ_READ_ONLY, &zone->flags);
if (dmz_is_seq(zone))
zone->wp_block = dmz_sect2blk(blkz.wp - blkz.start);
else
zone->wp_block = 0;
return 0;
}
static int dmz_handle_seq_write_err(struct dmz_metadata *zmd,
struct dm_zone *zone)
{
unsigned int wp = 0;
int ret;
wp = zone->wp_block;
ret = dmz_update_zone(zmd, zone);
if (ret)
return ret;
dmz_dev_warn(zmd->dev, "Processing zone %u write error (zone wp %u/%u)",
dmz_id(zmd, zone), zone->wp_block, wp);
if (zone->wp_block < wp) {
dmz_invalidate_blocks(zmd, zone, zone->wp_block,
wp - zone->wp_block);
}
return 0;
}
static struct dm_zone *dmz_get(struct dmz_metadata *zmd, unsigned int zone_id)
{
return &zmd->zones[zone_id];
}
static int dmz_reset_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
int ret;
if (dmz_is_offline(zone) ||
dmz_is_readonly(zone) ||
dmz_is_rnd(zone))
return 0;
if (!dmz_is_empty(zone) || dmz_seq_write_err(zone)) {
struct dmz_dev *dev = zmd->dev;
ret = blkdev_reset_zones(dev->bdev,
dmz_start_sect(zmd, zone),
dev->zone_nr_sectors, GFP_NOIO);
if (ret) {
dmz_dev_err(dev, "Reset zone %u failed %d",
dmz_id(zmd, zone), ret);
return ret;
}
}
clear_bit(DMZ_SEQ_WRITE_ERR, &zone->flags);
zone->wp_block = 0;
return 0;
}
static int dmz_load_mapping(struct dmz_metadata *zmd)
{
struct dmz_dev *dev = zmd->dev;
struct dm_zone *dzone, *bzone;
struct dmz_mblock *dmap_mblk = NULL;
struct dmz_map *dmap;
unsigned int i = 0, e = 0, chunk = 0;
unsigned int dzone_id;
unsigned int bzone_id;
zmd->map_mblk = kcalloc(zmd->nr_map_blocks,
sizeof(struct dmz_mblk *), GFP_KERNEL);
if (!zmd->map_mblk)
return -ENOMEM;
while (chunk < zmd->nr_chunks) {
if (!dmap_mblk) {
dmap_mblk = dmz_get_mblock(zmd, i + 1);
if (IS_ERR(dmap_mblk))
return PTR_ERR(dmap_mblk);
zmd->map_mblk[i] = dmap_mblk;
dmap = (struct dmz_map *) dmap_mblk->data;
i++;
e = 0;
}
dzone_id = le32_to_cpu(dmap[e].dzone_id);
if (dzone_id == DMZ_MAP_UNMAPPED)
goto next;
if (dzone_id >= dev->nr_zones) {
dmz_dev_err(dev, "Chunk %u mapping: invalid data zone ID %u",
chunk, dzone_id);
return -EIO;
}
dzone = dmz_get(zmd, dzone_id);
set_bit(DMZ_DATA, &dzone->flags);
dzone->chunk = chunk;
dmz_get_zone_weight(zmd, dzone);
if (dmz_is_rnd(dzone))
list_add_tail(&dzone->link, &zmd->map_rnd_list);
else
list_add_tail(&dzone->link, &zmd->map_seq_list);
bzone_id = le32_to_cpu(dmap[e].bzone_id);
if (bzone_id == DMZ_MAP_UNMAPPED)
goto next;
if (bzone_id >= dev->nr_zones) {
dmz_dev_err(dev, "Chunk %u mapping: invalid buffer zone ID %u",
chunk, bzone_id);
return -EIO;
}
bzone = dmz_get(zmd, bzone_id);
if (!dmz_is_rnd(bzone)) {
dmz_dev_err(dev, "Chunk %u mapping: invalid buffer zone %u",
chunk, bzone_id);
return -EIO;
}
set_bit(DMZ_DATA, &bzone->flags);
set_bit(DMZ_BUF, &bzone->flags);
bzone->chunk = chunk;
bzone->bzone = dzone;
dzone->bzone = bzone;
dmz_get_zone_weight(zmd, bzone);
list_add_tail(&bzone->link, &zmd->map_rnd_list);
next:
chunk++;
e++;
if (e >= DMZ_MAP_ENTRIES)
dmap_mblk = NULL;
}
for (i = 0; i < dev->nr_zones; i++) {
dzone = dmz_get(zmd, i);
if (dmz_is_meta(dzone))
continue;
if (dmz_is_rnd(dzone))
zmd->nr_rnd++;
else
zmd->nr_seq++;
if (dmz_is_data(dzone)) {
continue;
}
set_bit(DMZ_DATA, &dzone->flags);
dzone->chunk = DMZ_MAP_UNMAPPED;
if (dmz_is_rnd(dzone)) {
list_add_tail(&dzone->link, &zmd->unmap_rnd_list);
atomic_inc(&zmd->unmap_nr_rnd);
} else if (atomic_read(&zmd->nr_reserved_seq_zones) < zmd->nr_reserved_seq) {
list_add_tail(&dzone->link, &zmd->reserved_seq_zones_list);
atomic_inc(&zmd->nr_reserved_seq_zones);
zmd->nr_seq--;
} else {
list_add_tail(&dzone->link, &zmd->unmap_seq_list);
atomic_inc(&zmd->unmap_nr_seq);
}
}
return 0;
}
static void dmz_set_chunk_mapping(struct dmz_metadata *zmd, unsigned int chunk,
unsigned int dzone_id, unsigned int bzone_id)
{
struct dmz_mblock *dmap_mblk = zmd->map_mblk[chunk >> DMZ_MAP_ENTRIES_SHIFT];
struct dmz_map *dmap = (struct dmz_map *) dmap_mblk->data;
int map_idx = chunk & DMZ_MAP_ENTRIES_MASK;
dmap[map_idx].dzone_id = cpu_to_le32(dzone_id);
dmap[map_idx].bzone_id = cpu_to_le32(bzone_id);
dmz_dirty_mblock(zmd, dmap_mblk);
}
static void __dmz_lru_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
if (list_empty(&zone->link))
return;
list_del_init(&zone->link);
if (dmz_is_seq(zone)) {
list_add_tail(&zone->link, &zmd->map_seq_list);
} else {
list_add_tail(&zone->link, &zmd->map_rnd_list);
}
}
static void dmz_lru_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
__dmz_lru_zone(zmd, zone);
if (zone->bzone)
__dmz_lru_zone(zmd, zone->bzone);
}
static void dmz_wait_for_free_zones(struct dmz_metadata *zmd)
{
DEFINE_WAIT(wait);
prepare_to_wait(&zmd->free_wq, &wait, TASK_UNINTERRUPTIBLE);
dmz_unlock_map(zmd);
dmz_unlock_metadata(zmd);
io_schedule_timeout(HZ);
dmz_lock_metadata(zmd);
dmz_lock_map(zmd);
finish_wait(&zmd->free_wq, &wait);
}
int dmz_lock_zone_reclaim(struct dm_zone *zone)
{
if (dmz_is_active(zone))
return 0;
return !test_and_set_bit(DMZ_RECLAIM, &zone->flags);
}
void dmz_unlock_zone_reclaim(struct dm_zone *zone)
{
WARN_ON(dmz_is_active(zone));
WARN_ON(!dmz_in_reclaim(zone));
clear_bit_unlock(DMZ_RECLAIM, &zone->flags);
smp_mb__after_atomic();
wake_up_bit(&zone->flags, DMZ_RECLAIM);
}
static void dmz_wait_for_reclaim(struct dmz_metadata *zmd, struct dm_zone *zone)
{
dmz_unlock_map(zmd);
dmz_unlock_metadata(zmd);
wait_on_bit_timeout(&zone->flags, DMZ_RECLAIM, TASK_UNINTERRUPTIBLE, HZ);
dmz_lock_metadata(zmd);
dmz_lock_map(zmd);
}
static struct dm_zone *dmz_get_rnd_zone_for_reclaim(struct dmz_metadata *zmd)
{
struct dm_zone *dzone = NULL;
struct dm_zone *zone;
if (list_empty(&zmd->map_rnd_list))
return NULL;
list_for_each_entry(zone, &zmd->map_rnd_list, link) {
if (dmz_is_buf(zone))
dzone = zone->bzone;
else
dzone = zone;
if (dmz_lock_zone_reclaim(dzone))
return dzone;
}
return NULL;
}
static struct dm_zone *dmz_get_seq_zone_for_reclaim(struct dmz_metadata *zmd)
{
struct dm_zone *zone;
if (list_empty(&zmd->map_seq_list))
return NULL;
list_for_each_entry(zone, &zmd->map_seq_list, link) {
if (!zone->bzone)
continue;
if (dmz_lock_zone_reclaim(zone))
return zone;
}
return NULL;
}
struct dm_zone *dmz_get_zone_for_reclaim(struct dmz_metadata *zmd)
{
struct dm_zone *zone;
dmz_lock_map(zmd);
if (list_empty(&zmd->reserved_seq_zones_list))
zone = dmz_get_seq_zone_for_reclaim(zmd);
else
zone = dmz_get_rnd_zone_for_reclaim(zmd);
dmz_unlock_map(zmd);
return zone;
}
void dmz_activate_zone(struct dm_zone *zone)
{
set_bit(DMZ_ACTIVE, &zone->flags);
atomic_inc(&zone->refcount);
}
void dmz_deactivate_zone(struct dm_zone *zone)
{
if (atomic_dec_and_test(&zone->refcount)) {
WARN_ON(!test_bit(DMZ_ACTIVE, &zone->flags));
clear_bit_unlock(DMZ_ACTIVE, &zone->flags);
smp_mb__after_atomic();
}
}
struct dm_zone *dmz_get_chunk_mapping(struct dmz_metadata *zmd, unsigned int chunk, int op)
{
struct dmz_mblock *dmap_mblk = zmd->map_mblk[chunk >> DMZ_MAP_ENTRIES_SHIFT];
struct dmz_map *dmap = (struct dmz_map *) dmap_mblk->data;
int dmap_idx = chunk & DMZ_MAP_ENTRIES_MASK;
unsigned int dzone_id;
struct dm_zone *dzone = NULL;
int ret = 0;
dmz_lock_map(zmd);
again:
dzone_id = le32_to_cpu(dmap[dmap_idx].dzone_id);
if (dzone_id == DMZ_MAP_UNMAPPED) {
if (op != REQ_OP_WRITE)
goto out;
dzone = dmz_alloc_zone(zmd, DMZ_ALLOC_RND);
if (!dzone) {
dmz_wait_for_free_zones(zmd);
goto again;
}
dmz_map_zone(zmd, dzone, chunk);
} else {
dzone = dmz_get(zmd, dzone_id);
if (dzone->chunk != chunk) {
dzone = ERR_PTR(-EIO);
goto out;
}
if (dmz_seq_write_err(dzone)) {
ret = dmz_handle_seq_write_err(zmd, dzone);
if (ret) {
dzone = ERR_PTR(-EIO);
goto out;
}
clear_bit(DMZ_SEQ_WRITE_ERR, &dzone->flags);
}
}
if (dmz_in_reclaim(dzone)) {
dmz_wait_for_reclaim(zmd, dzone);
goto again;
}
dmz_activate_zone(dzone);
dmz_lru_zone(zmd, dzone);
out:
dmz_unlock_map(zmd);
return dzone;
}
void dmz_put_chunk_mapping(struct dmz_metadata *zmd, struct dm_zone *dzone)
{
struct dm_zone *bzone;
dmz_lock_map(zmd);
bzone = dzone->bzone;
if (bzone) {
if (dmz_weight(bzone))
dmz_lru_zone(zmd, bzone);
else {
dmz_unmap_zone(zmd, bzone);
dmz_free_zone(zmd, bzone);
bzone = NULL;
}
}
dmz_deactivate_zone(dzone);
if (dmz_is_active(dzone) || bzone || dmz_weight(dzone))
dmz_lru_zone(zmd, dzone);
else {
dmz_unmap_zone(zmd, dzone);
dmz_free_zone(zmd, dzone);
}
dmz_unlock_map(zmd);
}
struct dm_zone *dmz_get_chunk_buffer(struct dmz_metadata *zmd,
struct dm_zone *dzone)
{
struct dm_zone *bzone;
dmz_lock_map(zmd);
again:
bzone = dzone->bzone;
if (bzone)
goto out;
bzone = dmz_alloc_zone(zmd, DMZ_ALLOC_RND);
if (!bzone) {
dmz_wait_for_free_zones(zmd);
goto again;
}
dmz_set_chunk_mapping(zmd, dzone->chunk, dmz_id(zmd, dzone),
dmz_id(zmd, bzone));
set_bit(DMZ_BUF, &bzone->flags);
bzone->chunk = dzone->chunk;
bzone->bzone = dzone;
dzone->bzone = bzone;
list_add_tail(&bzone->link, &zmd->map_rnd_list);
out:
dmz_unlock_map(zmd);
return bzone;
}
struct dm_zone *dmz_alloc_zone(struct dmz_metadata *zmd, unsigned long flags)
{
struct list_head *list;
struct dm_zone *zone;
if (flags & DMZ_ALLOC_RND)
list = &zmd->unmap_rnd_list;
else
list = &zmd->unmap_seq_list;
again:
if (list_empty(list)) {
if (!(flags & DMZ_ALLOC_RECLAIM) ||
list_empty(&zmd->reserved_seq_zones_list))
return NULL;
zone = list_first_entry(&zmd->reserved_seq_zones_list,
struct dm_zone, link);
list_del_init(&zone->link);
atomic_dec(&zmd->nr_reserved_seq_zones);
return zone;
}
zone = list_first_entry(list, struct dm_zone, link);
list_del_init(&zone->link);
if (dmz_is_rnd(zone))
atomic_dec(&zmd->unmap_nr_rnd);
else
atomic_dec(&zmd->unmap_nr_seq);
if (dmz_is_offline(zone)) {
dmz_dev_warn(zmd->dev, "Zone %u is offline", dmz_id(zmd, zone));
zone = NULL;
goto again;
}
return zone;
}
void dmz_free_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
if (dmz_is_seq(zone))
dmz_reset_zone(zmd, zone);
if (dmz_is_rnd(zone)) {
list_add_tail(&zone->link, &zmd->unmap_rnd_list);
atomic_inc(&zmd->unmap_nr_rnd);
} else if (atomic_read(&zmd->nr_reserved_seq_zones) <
zmd->nr_reserved_seq) {
list_add_tail(&zone->link, &zmd->reserved_seq_zones_list);
atomic_inc(&zmd->nr_reserved_seq_zones);
} else {
list_add_tail(&zone->link, &zmd->unmap_seq_list);
atomic_inc(&zmd->unmap_nr_seq);
}
wake_up_all(&zmd->free_wq);
}
void dmz_map_zone(struct dmz_metadata *zmd, struct dm_zone *dzone,
unsigned int chunk)
{
dmz_set_chunk_mapping(zmd, chunk, dmz_id(zmd, dzone),
DMZ_MAP_UNMAPPED);
dzone->chunk = chunk;
if (dmz_is_rnd(dzone))
list_add_tail(&dzone->link, &zmd->map_rnd_list);
else
list_add_tail(&dzone->link, &zmd->map_seq_list);
}
void dmz_unmap_zone(struct dmz_metadata *zmd, struct dm_zone *zone)
{
unsigned int chunk = zone->chunk;
unsigned int dzone_id;
if (chunk == DMZ_MAP_UNMAPPED) {
return;
}
if (test_and_clear_bit(DMZ_BUF, &zone->flags)) {
dzone_id = dmz_id(zmd, zone->bzone);
zone->bzone->bzone = NULL;
zone->bzone = NULL;
} else {
if (WARN_ON(zone->bzone)) {
zone->bzone->bzone = NULL;
zone->bzone = NULL;
}
dzone_id = DMZ_MAP_UNMAPPED;
}
dmz_set_chunk_mapping(zmd, chunk, dzone_id, DMZ_MAP_UNMAPPED);
zone->chunk = DMZ_MAP_UNMAPPED;
list_del_init(&zone->link);
}
static unsigned int dmz_set_bits(unsigned long *bitmap,
unsigned int bit, unsigned int nr_bits)
{
unsigned long *addr;
unsigned int end = bit + nr_bits;
unsigned int n = 0;
while (bit < end) {
if (((bit & (BITS_PER_LONG - 1)) == 0) &&
((end - bit) >= BITS_PER_LONG)) {
addr = bitmap + BIT_WORD(bit);
if (*addr == 0) {
*addr = ULONG_MAX;
n += BITS_PER_LONG;
bit += BITS_PER_LONG;
continue;
}
}
if (!test_and_set_bit(bit, bitmap))
n++;
bit++;
}
return n;
}
static struct dmz_mblock *dmz_get_bitmap(struct dmz_metadata *zmd,
struct dm_zone *zone,
sector_t chunk_block)
{
sector_t bitmap_block = 1 + zmd->nr_map_blocks +
(sector_t)(dmz_id(zmd, zone) * zmd->zone_nr_bitmap_blocks) +
(chunk_block >> DMZ_BLOCK_SHIFT_BITS);
return dmz_get_mblock(zmd, bitmap_block);
}
int dmz_copy_valid_blocks(struct dmz_metadata *zmd, struct dm_zone *from_zone,
struct dm_zone *to_zone)
{
struct dmz_mblock *from_mblk, *to_mblk;
sector_t chunk_block = 0;
while (chunk_block < zmd->dev->zone_nr_blocks) {
from_mblk = dmz_get_bitmap(zmd, from_zone, chunk_block);
if (IS_ERR(from_mblk))
return PTR_ERR(from_mblk);
to_mblk = dmz_get_bitmap(zmd, to_zone, chunk_block);
if (IS_ERR(to_mblk)) {
dmz_release_mblock(zmd, from_mblk);
return PTR_ERR(to_mblk);
}
memcpy(to_mblk->data, from_mblk->data, DMZ_BLOCK_SIZE);
dmz_dirty_mblock(zmd, to_mblk);
dmz_release_mblock(zmd, to_mblk);
dmz_release_mblock(zmd, from_mblk);
chunk_block += DMZ_BLOCK_SIZE_BITS;
}
to_zone->weight = from_zone->weight;
return 0;
}
int dmz_merge_valid_blocks(struct dmz_metadata *zmd, struct dm_zone *from_zone,
struct dm_zone *to_zone, sector_t chunk_block)
{
unsigned int nr_blocks;
int ret;
while (chunk_block < zmd->dev->zone_nr_blocks) {
ret = dmz_first_valid_block(zmd, from_zone, &chunk_block);
if (ret <= 0)
return ret;
nr_blocks = ret;
ret = dmz_validate_blocks(zmd, to_zone, chunk_block, nr_blocks);
if (ret)
return ret;
chunk_block += nr_blocks;
}
return 0;
}
int dmz_validate_blocks(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t chunk_block, unsigned int nr_blocks)
{
unsigned int count, bit, nr_bits;
unsigned int zone_nr_blocks = zmd->dev->zone_nr_blocks;
struct dmz_mblock *mblk;
unsigned int n = 0;
dmz_dev_debug(zmd->dev, "=> VALIDATE zone %u, block %llu, %u blocks",
dmz_id(zmd, zone), (unsigned long long)chunk_block,
nr_blocks);
WARN_ON(chunk_block + nr_blocks > zone_nr_blocks);
while (nr_blocks) {
mblk = dmz_get_bitmap(zmd, zone, chunk_block);
if (IS_ERR(mblk))
return PTR_ERR(mblk);
bit = chunk_block & DMZ_BLOCK_MASK_BITS;
nr_bits = min(nr_blocks, DMZ_BLOCK_SIZE_BITS - bit);
count = dmz_set_bits((unsigned long *)mblk->data, bit, nr_bits);
if (count) {
dmz_dirty_mblock(zmd, mblk);
n += count;
}
dmz_release_mblock(zmd, mblk);
nr_blocks -= nr_bits;
chunk_block += nr_bits;
}
if (likely(zone->weight + n <= zone_nr_blocks))
zone->weight += n;
else {
dmz_dev_warn(zmd->dev, "Zone %u: weight %u should be <= %u",
dmz_id(zmd, zone), zone->weight,
zone_nr_blocks - n);
zone->weight = zone_nr_blocks;
}
return 0;
}
static int dmz_clear_bits(unsigned long *bitmap, int bit, int nr_bits)
{
unsigned long *addr;
int end = bit + nr_bits;
int n = 0;
while (bit < end) {
if (((bit & (BITS_PER_LONG - 1)) == 0) &&
((end - bit) >= BITS_PER_LONG)) {
addr = bitmap + BIT_WORD(bit);
if (*addr == ULONG_MAX) {
*addr = 0;
n += BITS_PER_LONG;
bit += BITS_PER_LONG;
continue;
}
}
if (test_and_clear_bit(bit, bitmap))
n++;
bit++;
}
return n;
}
int dmz_invalidate_blocks(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t chunk_block, unsigned int nr_blocks)
{
unsigned int count, bit, nr_bits;
struct dmz_mblock *mblk;
unsigned int n = 0;
dmz_dev_debug(zmd->dev, "=> INVALIDATE zone %u, block %llu, %u blocks",
dmz_id(zmd, zone), (u64)chunk_block, nr_blocks);
WARN_ON(chunk_block + nr_blocks > zmd->dev->zone_nr_blocks);
while (nr_blocks) {
mblk = dmz_get_bitmap(zmd, zone, chunk_block);
if (IS_ERR(mblk))
return PTR_ERR(mblk);
bit = chunk_block & DMZ_BLOCK_MASK_BITS;
nr_bits = min(nr_blocks, DMZ_BLOCK_SIZE_BITS - bit);
count = dmz_clear_bits((unsigned long *)mblk->data,
bit, nr_bits);
if (count) {
dmz_dirty_mblock(zmd, mblk);
n += count;
}
dmz_release_mblock(zmd, mblk);
nr_blocks -= nr_bits;
chunk_block += nr_bits;
}
if (zone->weight >= n)
zone->weight -= n;
else {
dmz_dev_warn(zmd->dev, "Zone %u: weight %u should be >= %u",
dmz_id(zmd, zone), zone->weight, n);
zone->weight = 0;
}
return 0;
}
static int dmz_test_block(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t chunk_block)
{
struct dmz_mblock *mblk;
int ret;
WARN_ON(chunk_block >= zmd->dev->zone_nr_blocks);
mblk = dmz_get_bitmap(zmd, zone, chunk_block);
if (IS_ERR(mblk))
return PTR_ERR(mblk);
ret = test_bit(chunk_block & DMZ_BLOCK_MASK_BITS,
(unsigned long *) mblk->data) != 0;
dmz_release_mblock(zmd, mblk);
return ret;
}
static int dmz_to_next_set_block(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t chunk_block, unsigned int nr_blocks,
int set)
{
struct dmz_mblock *mblk;
unsigned int bit, set_bit, nr_bits;
unsigned long *bitmap;
int n = 0;
WARN_ON(chunk_block + nr_blocks > zmd->dev->zone_nr_blocks);
while (nr_blocks) {
mblk = dmz_get_bitmap(zmd, zone, chunk_block);
if (IS_ERR(mblk))
return PTR_ERR(mblk);
bitmap = (unsigned long *) mblk->data;
bit = chunk_block & DMZ_BLOCK_MASK_BITS;
nr_bits = min(nr_blocks, DMZ_BLOCK_SIZE_BITS - bit);
if (set)
set_bit = find_next_bit(bitmap, DMZ_BLOCK_SIZE_BITS, bit);
else
set_bit = find_next_zero_bit(bitmap, DMZ_BLOCK_SIZE_BITS, bit);
dmz_release_mblock(zmd, mblk);
n += set_bit - bit;
if (set_bit < DMZ_BLOCK_SIZE_BITS)
break;
nr_blocks -= nr_bits;
chunk_block += nr_bits;
}
return n;
}
int dmz_block_valid(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t chunk_block)
{
int valid;
valid = dmz_test_block(zmd, zone, chunk_block);
if (valid <= 0)
return valid;
return dmz_to_next_set_block(zmd, zone, chunk_block,
zmd->dev->zone_nr_blocks - chunk_block, 0);
}
int dmz_first_valid_block(struct dmz_metadata *zmd, struct dm_zone *zone,
sector_t *chunk_block)
{
sector_t start_block = *chunk_block;
int ret;
ret = dmz_to_next_set_block(zmd, zone, start_block,
zmd->dev->zone_nr_blocks - start_block, 1);
if (ret < 0)
return ret;
start_block += ret;
*chunk_block = start_block;
return dmz_to_next_set_block(zmd, zone, start_block,
zmd->dev->zone_nr_blocks - start_block, 0);
}
static int dmz_count_bits(void *bitmap, int bit, int nr_bits)
{
unsigned long *addr;
int end = bit + nr_bits;
int n = 0;
while (bit < end) {
if (((bit & (BITS_PER_LONG - 1)) == 0) &&
((end - bit) >= BITS_PER_LONG)) {
addr = (unsigned long *)bitmap + BIT_WORD(bit);
if (*addr == ULONG_MAX) {
n += BITS_PER_LONG;
bit += BITS_PER_LONG;
continue;
}
}
if (test_bit(bit, bitmap))
n++;
bit++;
}
return n;
}
static void dmz_get_zone_weight(struct dmz_metadata *zmd, struct dm_zone *zone)
{
struct dmz_mblock *mblk;
sector_t chunk_block = 0;
unsigned int bit, nr_bits;
unsigned int nr_blocks = zmd->dev->zone_nr_blocks;
void *bitmap;
int n = 0;
while (nr_blocks) {
mblk = dmz_get_bitmap(zmd, zone, chunk_block);
if (IS_ERR(mblk)) {
n = 0;
break;
}
bitmap = mblk->data;
bit = chunk_block & DMZ_BLOCK_MASK_BITS;
nr_bits = min(nr_blocks, DMZ_BLOCK_SIZE_BITS - bit);
n += dmz_count_bits(bitmap, bit, nr_bits);
dmz_release_mblock(zmd, mblk);
nr_blocks -= nr_bits;
chunk_block += nr_bits;
}
zone->weight = n;
}
static void dmz_cleanup_metadata(struct dmz_metadata *zmd)
{
struct rb_root *root;
struct dmz_mblock *mblk, *next;
int i;
if (zmd->map_mblk) {
for (i = 0; i < zmd->nr_map_blocks; i++)
dmz_release_mblock(zmd, zmd->map_mblk[i]);
kfree(zmd->map_mblk);
zmd->map_mblk = NULL;
}
for (i = 0; i < 2; i++) {
if (zmd->sb[i].mblk) {
dmz_free_mblock(zmd, zmd->sb[i].mblk);
zmd->sb[i].mblk = NULL;
}
}
while (!list_empty(&zmd->mblk_dirty_list)) {
mblk = list_first_entry(&zmd->mblk_dirty_list,
struct dmz_mblock, link);
dmz_dev_warn(zmd->dev, "mblock %llu still in dirty list (ref %u)",
(u64)mblk->no, atomic_read(&mblk->ref));
list_del_init(&mblk->link);
rb_erase(&mblk->node, &zmd->mblk_rbtree);
dmz_free_mblock(zmd, mblk);
}
while (!list_empty(&zmd->mblk_lru_list)) {
mblk = list_first_entry(&zmd->mblk_lru_list,
struct dmz_mblock, link);
list_del_init(&mblk->link);
rb_erase(&mblk->node, &zmd->mblk_rbtree);
dmz_free_mblock(zmd, mblk);
}
root = &zmd->mblk_rbtree;
rbtree_postorder_for_each_entry_safe(mblk, next, root, node) {
dmz_dev_warn(zmd->dev, "mblock %llu ref %u still in rbtree",
(u64)mblk->no, atomic_read(&mblk->ref));
atomic_set(&mblk->ref, 0);
dmz_free_mblock(zmd, mblk);
}
dmz_drop_zones(zmd);
}
int dmz_ctr_metadata(struct dmz_dev *dev, struct dmz_metadata **metadata)
{
struct dmz_metadata *zmd;
unsigned int i, zid;
struct dm_zone *zone;
int ret;
zmd = kzalloc(sizeof(struct dmz_metadata), GFP_KERNEL);
if (!zmd)
return -ENOMEM;
zmd->dev = dev;
zmd->mblk_rbtree = RB_ROOT;
init_rwsem(&zmd->mblk_sem);
mutex_init(&zmd->mblk_flush_lock);
spin_lock_init(&zmd->mblk_lock);
INIT_LIST_HEAD(&zmd->mblk_lru_list);
INIT_LIST_HEAD(&zmd->mblk_dirty_list);
mutex_init(&zmd->map_lock);
atomic_set(&zmd->unmap_nr_rnd, 0);
INIT_LIST_HEAD(&zmd->unmap_rnd_list);
INIT_LIST_HEAD(&zmd->map_rnd_list);
atomic_set(&zmd->unmap_nr_seq, 0);
INIT_LIST_HEAD(&zmd->unmap_seq_list);
INIT_LIST_HEAD(&zmd->map_seq_list);
atomic_set(&zmd->nr_reserved_seq_zones, 0);
INIT_LIST_HEAD(&zmd->reserved_seq_zones_list);
init_waitqueue_head(&zmd->free_wq);
ret = dmz_init_zones(zmd);
if (ret)
goto err;
ret = dmz_load_sb(zmd);
if (ret)
goto err;
zid = dmz_id(zmd, zmd->sb_zone);
for (i = 0; i < zmd->nr_meta_zones << 1; i++) {
zone = dmz_get(zmd, zid + i);
if (!dmz_is_rnd(zone))
goto err;
set_bit(DMZ_META, &zone->flags);
}
ret = dmz_load_mapping(zmd);
if (ret)
goto err;
zmd->min_nr_mblks = 2 + zmd->nr_map_blocks + zmd->zone_nr_bitmap_blocks * 16;
zmd->max_nr_mblks = zmd->min_nr_mblks + 512;
zmd->mblk_shrinker.count_objects = dmz_mblock_shrinker_count;
zmd->mblk_shrinker.scan_objects = dmz_mblock_shrinker_scan;
zmd->mblk_shrinker.seeks = DEFAULT_SEEKS;
ret = register_shrinker(&zmd->mblk_shrinker);
if (ret) {
dmz_dev_err(dev, "Register metadata cache shrinker failed");
goto err;
}
dmz_dev_info(dev, "Host-%s zoned block device",
bdev_zoned_model(dev->bdev) == BLK_ZONED_HA ?
"aware" : "managed");
dmz_dev_info(dev, " %llu 512-byte logical sectors",
(u64)dev->capacity);
dmz_dev_info(dev, " %u zones of %llu 512-byte logical sectors",
dev->nr_zones, (u64)dev->zone_nr_sectors);
dmz_dev_info(dev, " %u metadata zones",
zmd->nr_meta_zones * 2);
dmz_dev_info(dev, " %u data zones for %u chunks",
zmd->nr_data_zones, zmd->nr_chunks);
dmz_dev_info(dev, " %u random zones (%u unmapped)",
zmd->nr_rnd, atomic_read(&zmd->unmap_nr_rnd));
dmz_dev_info(dev, " %u sequential zones (%u unmapped)",
zmd->nr_seq, atomic_read(&zmd->unmap_nr_seq));
dmz_dev_info(dev, " %u reserved sequential data zones",
zmd->nr_reserved_seq);
dmz_dev_debug(dev, "Format:");
dmz_dev_debug(dev, "%u metadata blocks per set (%u max cache)",
zmd->nr_meta_blocks, zmd->max_nr_mblks);
dmz_dev_debug(dev, " %u data zone mapping blocks",
zmd->nr_map_blocks);
dmz_dev_debug(dev, " %u bitmap blocks",
zmd->nr_bitmap_blocks);
*metadata = zmd;
return 0;
err:
dmz_cleanup_metadata(zmd);
kfree(zmd);
*metadata = NULL;
return ret;
}
void dmz_dtr_metadata(struct dmz_metadata *zmd)
{
unregister_shrinker(&zmd->mblk_shrinker);
dmz_cleanup_metadata(zmd);
kfree(zmd);
}
int dmz_resume_metadata(struct dmz_metadata *zmd)
{
struct dmz_dev *dev = zmd->dev;
struct dm_zone *zone;
sector_t wp_block;
unsigned int i;
int ret;
for (i = 0; i < dev->nr_zones; i++) {
zone = dmz_get(zmd, i);
if (!zone) {
dmz_dev_err(dev, "Unable to get zone %u", i);
return -EIO;
}
wp_block = zone->wp_block;
ret = dmz_update_zone(zmd, zone);
if (ret) {
dmz_dev_err(dev, "Broken zone %u", i);
return ret;
}
if (dmz_is_offline(zone)) {
dmz_dev_warn(dev, "Zone %u is offline", i);
continue;
}
if (!dmz_is_seq(zone))
zone->wp_block = 0;
else if (zone->wp_block != wp_block) {
dmz_dev_err(dev, "Zone %u: Invalid wp (%llu / %llu)",
i, (u64)zone->wp_block, (u64)wp_block);
zone->wp_block = wp_block;
dmz_invalidate_blocks(zmd, zone, zone->wp_block,
dev->zone_nr_blocks - zone->wp_block);
}
}
return 0;
}
