static inline bool init_done(struct zram *zram)
{
return zram->disksize;
}
static inline struct zram *dev_to_zram(struct device *dev)
{
return (struct zram *)dev_to_disk(dev)->private_data;
}
static unsigned long zram_get_handle(struct zram *zram, u32 index)
{
return zram->table[index].handle;
}
static void zram_set_handle(struct zram *zram, u32 index, unsigned long handle)
{
zram->table[index].handle = handle;
}
static int zram_test_flag(struct zram *zram, u32 index,
enum zram_pageflags flag)
{
return zram->table[index].value & BIT(flag);
}
static void zram_set_flag(struct zram *zram, u32 index,
enum zram_pageflags flag)
{
zram->table[index].value |= BIT(flag);
}
static void zram_clear_flag(struct zram *zram, u32 index,
enum zram_pageflags flag)
{
zram->table[index].value &= ~BIT(flag);
}
static inline void zram_set_element(struct zram *zram, u32 index,
unsigned long element)
{
zram->table[index].element = element;
}
static unsigned long zram_get_element(struct zram *zram, u32 index)
{
return zram->table[index].element;
}
static size_t zram_get_obj_size(struct zram *zram, u32 index)
{
return zram->table[index].value & (BIT(ZRAM_FLAG_SHIFT) - 1);
}
static void zram_set_obj_size(struct zram *zram,
u32 index, size_t size)
{
unsigned long flags = zram->table[index].value >> ZRAM_FLAG_SHIFT;
zram->table[index].value = (flags << ZRAM_FLAG_SHIFT) | size;
}
static inline bool is_partial_io(struct bio_vec *bvec)
{
return bvec->bv_len != PAGE_SIZE;
}
static inline bool is_partial_io(struct bio_vec *bvec)
{
return false;
}
static void zram_revalidate_disk(struct zram *zram)
{
revalidate_disk(zram->disk);
zram->disk->queue->backing_dev_info->capabilities |=
BDI_CAP_STABLE_WRITES;
}
static inline bool valid_io_request(struct zram *zram,
sector_t start, unsigned int size)
{
u64 end, bound;
if (unlikely(start & (ZRAM_SECTOR_PER_LOGICAL_BLOCK - 1)))
return false;
if (unlikely(size & (ZRAM_LOGICAL_BLOCK_SIZE - 1)))
return false;
end = start + (size >> SECTOR_SHIFT);
bound = zram->disksize >> SECTOR_SHIFT;
if (unlikely(start >= bound || end > bound || start > end))
return false;
return true;
}
static void update_position(u32 *index, int *offset, struct bio_vec *bvec)
{
*index += (*offset + bvec->bv_len) / PAGE_SIZE;
*offset = (*offset + bvec->bv_len) % PAGE_SIZE;
}
static inline void update_used_max(struct zram *zram,
const unsigned long pages)
{
unsigned long old_max, cur_max;
old_max = atomic_long_read(&zram->stats.max_used_pages);
do {
cur_max = old_max;
if (pages > cur_max)
old_max = atomic_long_cmpxchg(
&zram->stats.max_used_pages, cur_max, pages);
} while (old_max != cur_max);
}
static inline void zram_fill_page(char *ptr, unsigned long len,
unsigned long value)
{
int i;
unsigned long *page = (unsigned long *)ptr;
WARN_ON_ONCE(!IS_ALIGNED(len, sizeof(unsigned long)));
if (likely(value == 0)) {
memset(ptr, 0, len);
} else {
for (i = 0; i < len / sizeof(*page); i++)
page[i] = value;
}
}
static bool page_same_filled(void *ptr, unsigned long *element)
{
unsigned int pos;
unsigned long *page;
unsigned long val;
page = (unsigned long *)ptr;
val = page[0];
for (pos = 1; pos < PAGE_SIZE / sizeof(*page); pos++) {
if (val != page[pos])
return false;
}
*element = val;
return true;
}
static ssize_t initstate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 val;
struct zram *zram = dev_to_zram(dev);
down_read(&zram->init_lock);
val = init_done(zram);
up_read(&zram->init_lock);
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static ssize_t disksize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return scnprintf(buf, PAGE_SIZE, "%llu\n", zram->disksize);
}
static ssize_t mem_limit_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
u64 limit;
char *tmp;
struct zram *zram = dev_to_zram(dev);
limit = memparse(buf, &tmp);
if (buf == tmp)
return -EINVAL;
down_write(&zram->init_lock);
zram->limit_pages = PAGE_ALIGN(limit) >> PAGE_SHIFT;
up_write(&zram->init_lock);
return len;
}
static ssize_t mem_used_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
int err;
unsigned long val;
struct zram *zram = dev_to_zram(dev);
err = kstrtoul(buf, 10, &val);
if (err || val != 0)
return -EINVAL;
down_read(&zram->init_lock);
if (init_done(zram)) {
atomic_long_set(&zram->stats.max_used_pages,
zs_get_total_pages(zram->mem_pool));
}
up_read(&zram->init_lock);
return len;
}
static ssize_t max_comp_streams_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "%d\n", num_online_cpus());
}
static ssize_t max_comp_streams_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
return len;
}
static ssize_t comp_algorithm_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
size_t sz;
struct zram *zram = dev_to_zram(dev);
down_read(&zram->init_lock);
sz = zcomp_available_show(zram->compressor, buf);
up_read(&zram->init_lock);
return sz;
}
static ssize_t comp_algorithm_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct zram *zram = dev_to_zram(dev);
char compressor[CRYPTO_MAX_ALG_NAME];
size_t sz;
strlcpy(compressor, buf, sizeof(compressor));
sz = strlen(compressor);
if (sz > 0 && compressor[sz - 1] == '\n')
compressor[sz - 1] = 0x00;
if (!zcomp_available_algorithm(compressor))
return -EINVAL;
down_write(&zram->init_lock);
if (init_done(zram)) {
up_write(&zram->init_lock);
pr_info("Can't change algorithm for initialized device\n");
return -EBUSY;
}
strlcpy(zram->compressor, compressor, sizeof(compressor));
up_write(&zram->init_lock);
return len;
}
static ssize_t compact_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct zram *zram = dev_to_zram(dev);
down_read(&zram->init_lock);
if (!init_done(zram)) {
up_read(&zram->init_lock);
return -EINVAL;
}
zs_compact(zram->mem_pool);
up_read(&zram->init_lock);
return len;
}
static ssize_t io_stat_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
ssize_t ret;
down_read(&zram->init_lock);
ret = scnprintf(buf, PAGE_SIZE,
"%8llu %8llu %8llu %8llu\n",
(u64)atomic64_read(&zram->stats.failed_reads),
(u64)atomic64_read(&zram->stats.failed_writes),
(u64)atomic64_read(&zram->stats.invalid_io),
(u64)atomic64_read(&zram->stats.notify_free));
up_read(&zram->init_lock);
return ret;
}
static ssize_t mm_stat_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
struct zs_pool_stats pool_stats;
u64 orig_size, mem_used = 0;
long max_used;
ssize_t ret;
memset(&pool_stats, 0x00, sizeof(struct zs_pool_stats));
down_read(&zram->init_lock);
if (init_done(zram)) {
mem_used = zs_get_total_pages(zram->mem_pool);
zs_pool_stats(zram->mem_pool, &pool_stats);
}
orig_size = atomic64_read(&zram->stats.pages_stored);
max_used = atomic_long_read(&zram->stats.max_used_pages);
ret = scnprintf(buf, PAGE_SIZE,
"%8llu %8llu %8llu %8lu %8ld %8llu %8lu\n",
orig_size << PAGE_SHIFT,
(u64)atomic64_read(&zram->stats.compr_data_size),
mem_used << PAGE_SHIFT,
zram->limit_pages << PAGE_SHIFT,
max_used << PAGE_SHIFT,
(u64)atomic64_read(&zram->stats.same_pages),
pool_stats.pages_compacted);
up_read(&zram->init_lock);
return ret;
}
static ssize_t debug_stat_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int version = 1;
struct zram *zram = dev_to_zram(dev);
ssize_t ret;
down_read(&zram->init_lock);
ret = scnprintf(buf, PAGE_SIZE,
"version: %d\n%8llu\n",
version,
(u64)atomic64_read(&zram->stats.writestall));
up_read(&zram->init_lock);
return ret;
}
static void zram_slot_lock(struct zram *zram, u32 index)
{
bit_spin_lock(ZRAM_ACCESS, &zram->table[index].value);
}
static void zram_slot_unlock(struct zram *zram, u32 index)
{
bit_spin_unlock(ZRAM_ACCESS, &zram->table[index].value);
}
static bool zram_same_page_read(struct zram *zram, u32 index,
struct page *page,
unsigned int offset, unsigned int len)
{
zram_slot_lock(zram, index);
if (unlikely(!zram_get_handle(zram, index) ||
zram_test_flag(zram, index, ZRAM_SAME))) {
void *mem;
zram_slot_unlock(zram, index);
mem = kmap_atomic(page);
zram_fill_page(mem + offset, len,
zram_get_element(zram, index));
kunmap_atomic(mem);
return true;
}
zram_slot_unlock(zram, index);
return false;
}
static bool zram_same_page_write(struct zram *zram, u32 index,
struct page *page)
{
unsigned long element;
void *mem = kmap_atomic(page);
if (page_same_filled(mem, &element)) {
kunmap_atomic(mem);
zram_slot_lock(zram, index);
zram_free_page(zram, index);
zram_set_flag(zram, index, ZRAM_SAME);
zram_set_element(zram, index, element);
zram_slot_unlock(zram, index);
atomic64_inc(&zram->stats.same_pages);
return true;
}
kunmap_atomic(mem);
return false;
}
static void zram_meta_free(struct zram *zram, u64 disksize)
{
size_t num_pages = disksize >> PAGE_SHIFT;
size_t index;
for (index = 0; index < num_pages; index++)
zram_free_page(zram, index);
zs_destroy_pool(zram->mem_pool);
vfree(zram->table);
}
static bool zram_meta_alloc(struct zram *zram, u64 disksize)
{
size_t num_pages;
num_pages = disksize >> PAGE_SHIFT;
zram->table = vzalloc(num_pages * sizeof(*zram->table));
if (!zram->table)
return false;
zram->mem_pool = zs_create_pool(zram->disk->disk_name);
if (!zram->mem_pool) {
vfree(zram->table);
return false;
}
return true;
}
static void zram_free_page(struct zram *zram, size_t index)
{
unsigned long handle = zram_get_handle(zram, index);
if (zram_test_flag(zram, index, ZRAM_SAME)) {
zram_clear_flag(zram, index, ZRAM_SAME);
zram_set_element(zram, index, 0);
atomic64_dec(&zram->stats.same_pages);
return;
}
if (!handle)
return;
zs_free(zram->mem_pool, handle);
atomic64_sub(zram_get_obj_size(zram, index),
&zram->stats.compr_data_size);
atomic64_dec(&zram->stats.pages_stored);
zram_set_handle(zram, index, 0);
zram_set_obj_size(zram, index, 0);
}
static int zram_decompress_page(struct zram *zram, struct page *page, u32 index)
{
int ret;
unsigned long handle;
unsigned int size;
void *src, *dst;
if (zram_same_page_read(zram, index, page, 0, PAGE_SIZE))
return 0;
zram_slot_lock(zram, index);
handle = zram_get_handle(zram, index);
size = zram_get_obj_size(zram, index);
src = zs_map_object(zram->mem_pool, handle, ZS_MM_RO);
if (size == PAGE_SIZE) {
dst = kmap_atomic(page);
memcpy(dst, src, PAGE_SIZE);
kunmap_atomic(dst);
ret = 0;
} else {
struct zcomp_strm *zstrm = zcomp_stream_get(zram->comp);
dst = kmap_atomic(page);
ret = zcomp_decompress(zstrm, src, size, dst);
kunmap_atomic(dst);
zcomp_stream_put(zram->comp);
}
zs_unmap_object(zram->mem_pool, handle);
zram_slot_unlock(zram, index);
if (unlikely(ret))
pr_err("Decompression failed! err=%d, page=%u\n", ret, index);
return ret;
}
static int zram_bvec_read(struct zram *zram, struct bio_vec *bvec,
u32 index, int offset)
{
int ret;
struct page *page;
page = bvec->bv_page;
if (is_partial_io(bvec)) {
page = alloc_page(GFP_NOIO|__GFP_HIGHMEM);
if (!page)
return -ENOMEM;
}
ret = zram_decompress_page(zram, page, index);
if (unlikely(ret))
goto out;
if (is_partial_io(bvec)) {
void *dst = kmap_atomic(bvec->bv_page);
void *src = kmap_atomic(page);
memcpy(dst + bvec->bv_offset, src + offset, bvec->bv_len);
kunmap_atomic(src);
kunmap_atomic(dst);
}
out:
if (is_partial_io(bvec))
__free_page(page);
return ret;
}
static int zram_compress(struct zram *zram, struct zcomp_strm **zstrm,
struct page *page,
unsigned long *out_handle, unsigned int *out_comp_len)
{
int ret;
unsigned int comp_len;
void *src;
unsigned long alloced_pages;
unsigned long handle = 0;
compress_again:
src = kmap_atomic(page);
ret = zcomp_compress(*zstrm, src, &comp_len);
kunmap_atomic(src);
if (unlikely(ret)) {
pr_err("Compression failed! err=%d\n", ret);
if (handle)
zs_free(zram->mem_pool, handle);
return ret;
}
if (unlikely(comp_len > max_zpage_size))
comp_len = PAGE_SIZE;
if (!handle)
handle = zs_malloc(zram->mem_pool, comp_len,
__GFP_KSWAPD_RECLAIM |
__GFP_NOWARN |
__GFP_HIGHMEM |
__GFP_MOVABLE);
if (!handle) {
zcomp_stream_put(zram->comp);
atomic64_inc(&zram->stats.writestall);
handle = zs_malloc(zram->mem_pool, comp_len,
GFP_NOIO | __GFP_HIGHMEM |
__GFP_MOVABLE);
*zstrm = zcomp_stream_get(zram->comp);
if (handle)
goto compress_again;
return -ENOMEM;
}
alloced_pages = zs_get_total_pages(zram->mem_pool);
update_used_max(zram, alloced_pages);
if (zram->limit_pages && alloced_pages > zram->limit_pages) {
zs_free(zram->mem_pool, handle);
return -ENOMEM;
}
*out_handle = handle;
*out_comp_len = comp_len;
return 0;
}
static int __zram_bvec_write(struct zram *zram, struct bio_vec *bvec, u32 index)
{
int ret;
unsigned long handle;
unsigned int comp_len;
void *src, *dst;
struct zcomp_strm *zstrm;
struct page *page = bvec->bv_page;
if (zram_same_page_write(zram, index, page))
return 0;
zstrm = zcomp_stream_get(zram->comp);
ret = zram_compress(zram, &zstrm, page, &handle, &comp_len);
if (ret) {
zcomp_stream_put(zram->comp);
return ret;
}
dst = zs_map_object(zram->mem_pool, handle, ZS_MM_WO);
src = zstrm->buffer;
if (comp_len == PAGE_SIZE)
src = kmap_atomic(page);
memcpy(dst, src, comp_len);
if (comp_len == PAGE_SIZE)
kunmap_atomic(src);
zcomp_stream_put(zram->comp);
zs_unmap_object(zram->mem_pool, handle);
zram_slot_lock(zram, index);
zram_free_page(zram, index);
zram_set_handle(zram, index, handle);
zram_set_obj_size(zram, index, comp_len);
zram_slot_unlock(zram, index);
atomic64_add(comp_len, &zram->stats.compr_data_size);
atomic64_inc(&zram->stats.pages_stored);
return 0;
}
static int zram_bvec_write(struct zram *zram, struct bio_vec *bvec,
u32 index, int offset)
{
int ret;
struct page *page = NULL;
void *src;
struct bio_vec vec;
vec = *bvec;
if (is_partial_io(bvec)) {
void *dst;
page = alloc_page(GFP_NOIO|__GFP_HIGHMEM);
if (!page)
return -ENOMEM;
ret = zram_decompress_page(zram, page, index);
if (ret)
goto out;
src = kmap_atomic(bvec->bv_page);
dst = kmap_atomic(page);
memcpy(dst + offset, src + bvec->bv_offset, bvec->bv_len);
kunmap_atomic(dst);
kunmap_atomic(src);
vec.bv_page = page;
vec.bv_len = PAGE_SIZE;
vec.bv_offset = 0;
}
ret = __zram_bvec_write(zram, &vec, index);
out:
if (is_partial_io(bvec))
__free_page(page);
return ret;
}
static void zram_bio_discard(struct zram *zram, u32 index,
int offset, struct bio *bio)
{
size_t n = bio->bi_iter.bi_size;
if (offset) {
if (n <= (PAGE_SIZE - offset))
return;
n -= (PAGE_SIZE - offset);
index++;
}
while (n >= PAGE_SIZE) {
zram_slot_lock(zram, index);
zram_free_page(zram, index);
zram_slot_unlock(zram, index);
atomic64_inc(&zram->stats.notify_free);
index++;
n -= PAGE_SIZE;
}
}
static int zram_bvec_rw(struct zram *zram, struct bio_vec *bvec, u32 index,
int offset, bool is_write)
{
unsigned long start_time = jiffies;
int rw_acct = is_write ? REQ_OP_WRITE : REQ_OP_READ;
int ret;
generic_start_io_acct(rw_acct, bvec->bv_len >> SECTOR_SHIFT,
&zram->disk->part0);
if (!is_write) {
atomic64_inc(&zram->stats.num_reads);
ret = zram_bvec_read(zram, bvec, index, offset);
flush_dcache_page(bvec->bv_page);
} else {
atomic64_inc(&zram->stats.num_writes);
ret = zram_bvec_write(zram, bvec, index, offset);
}
generic_end_io_acct(rw_acct, &zram->disk->part0, start_time);
if (unlikely(ret)) {
if (!is_write)
atomic64_inc(&zram->stats.failed_reads);
else
atomic64_inc(&zram->stats.failed_writes);
}
return ret;
}
static void __zram_make_request(struct zram *zram, struct bio *bio)
{
int offset;
u32 index;
struct bio_vec bvec;
struct bvec_iter iter;
index = bio->bi_iter.bi_sector >> SECTORS_PER_PAGE_SHIFT;
offset = (bio->bi_iter.bi_sector &
(SECTORS_PER_PAGE - 1)) << SECTOR_SHIFT;
switch (bio_op(bio)) {
case REQ_OP_DISCARD:
case REQ_OP_WRITE_ZEROES:
zram_bio_discard(zram, index, offset, bio);
bio_endio(bio);
return;
default:
break;
}
bio_for_each_segment(bvec, bio, iter) {
struct bio_vec bv = bvec;
unsigned int unwritten = bvec.bv_len;
do {
bv.bv_len = min_t(unsigned int, PAGE_SIZE - offset,
unwritten);
if (zram_bvec_rw(zram, &bv, index, offset,
op_is_write(bio_op(bio))) < 0)
goto out;
bv.bv_offset += bv.bv_len;
unwritten -= bv.bv_len;
update_position(&index, &offset, &bv);
} while (unwritten);
}
bio_endio(bio);
return;
out:
bio_io_error(bio);
}
static blk_qc_t zram_make_request(struct request_queue *queue, struct bio *bio)
{
struct zram *zram = queue->queuedata;
if (!valid_io_request(zram, bio->bi_iter.bi_sector,
bio->bi_iter.bi_size)) {
atomic64_inc(&zram->stats.invalid_io);
goto error;
}
__zram_make_request(zram, bio);
return BLK_QC_T_NONE;
error:
bio_io_error(bio);
return BLK_QC_T_NONE;
}
static void zram_slot_free_notify(struct block_device *bdev,
unsigned long index)
{
struct zram *zram;
zram = bdev->bd_disk->private_data;
zram_slot_lock(zram, index);
zram_free_page(zram, index);
zram_slot_unlock(zram, index);
atomic64_inc(&zram->stats.notify_free);
}
static int zram_rw_page(struct block_device *bdev, sector_t sector,
struct page *page, bool is_write)
{
int offset, err = -EIO;
u32 index;
struct zram *zram;
struct bio_vec bv;
zram = bdev->bd_disk->private_data;
if (!valid_io_request(zram, sector, PAGE_SIZE)) {
atomic64_inc(&zram->stats.invalid_io);
err = -EINVAL;
goto out;
}
index = sector >> SECTORS_PER_PAGE_SHIFT;
offset = (sector & (SECTORS_PER_PAGE - 1)) << SECTOR_SHIFT;
bv.bv_page = page;
bv.bv_len = PAGE_SIZE;
bv.bv_offset = 0;
err = zram_bvec_rw(zram, &bv, index, offset, is_write);
out:
if (err == 0)
page_endio(page, is_write, 0);
return err;
}
static void zram_reset_device(struct zram *zram)
{
struct zcomp *comp;
u64 disksize;
down_write(&zram->init_lock);
zram->limit_pages = 0;
if (!init_done(zram)) {
up_write(&zram->init_lock);
return;
}
comp = zram->comp;
disksize = zram->disksize;
zram->disksize = 0;
set_capacity(zram->disk, 0);
part_stat_set_all(&zram->disk->part0, 0);
up_write(&zram->init_lock);
zram_meta_free(zram, disksize);
memset(&zram->stats, 0, sizeof(zram->stats));
zcomp_destroy(comp);
}
static ssize_t disksize_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
u64 disksize;
struct zcomp *comp;
struct zram *zram = dev_to_zram(dev);
int err;
disksize = memparse(buf, NULL);
if (!disksize)
return -EINVAL;
down_write(&zram->init_lock);
if (init_done(zram)) {
pr_info("Cannot change disksize for initialized device\n");
err = -EBUSY;
goto out_unlock;
}
disksize = PAGE_ALIGN(disksize);
if (!zram_meta_alloc(zram, disksize)) {
err = -ENOMEM;
goto out_unlock;
}
comp = zcomp_create(zram->compressor);
if (IS_ERR(comp)) {
pr_err("Cannot initialise %s compressing backend\n",
zram->compressor);
err = PTR_ERR(comp);
goto out_free_meta;
}
zram->comp = comp;
zram->disksize = disksize;
set_capacity(zram->disk, zram->disksize >> SECTOR_SHIFT);
zram_revalidate_disk(zram);
up_write(&zram->init_lock);
return len;
out_free_meta:
zram_meta_free(zram, disksize);
out_unlock:
up_write(&zram->init_lock);
return err;
}
static ssize_t reset_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
int ret;
unsigned short do_reset;
struct zram *zram;
struct block_device *bdev;
ret = kstrtou16(buf, 10, &do_reset);
if (ret)
return ret;
if (!do_reset)
return -EINVAL;
zram = dev_to_zram(dev);
bdev = bdget_disk(zram->disk, 0);
if (!bdev)
return -ENOMEM;
mutex_lock(&bdev->bd_mutex);
if (bdev->bd_openers || zram->claim) {
mutex_unlock(&bdev->bd_mutex);
bdput(bdev);
return -EBUSY;
}
zram->claim = true;
mutex_unlock(&bdev->bd_mutex);
fsync_bdev(bdev);
zram_reset_device(zram);
zram_revalidate_disk(zram);
bdput(bdev);
mutex_lock(&bdev->bd_mutex);
zram->claim = false;
mutex_unlock(&bdev->bd_mutex);
return len;
}
static int zram_open(struct block_device *bdev, fmode_t mode)
{
int ret = 0;
struct zram *zram;
WARN_ON(!mutex_is_locked(&bdev->bd_mutex));
zram = bdev->bd_disk->private_data;
if (zram->claim)
ret = -EBUSY;
return ret;
}
static int zram_add(void)
{
struct zram *zram;
struct request_queue *queue;
int ret, device_id;
zram = kzalloc(sizeof(struct zram), GFP_KERNEL);
if (!zram)
return -ENOMEM;
ret = idr_alloc(&zram_index_idr, zram, 0, 0, GFP_KERNEL);
if (ret < 0)
goto out_free_dev;
device_id = ret;
init_rwsem(&zram->init_lock);
queue = blk_alloc_queue(GFP_KERNEL);
if (!queue) {
pr_err("Error allocating disk queue for device %d\n",
device_id);
ret = -ENOMEM;
goto out_free_idr;
}
blk_queue_make_request(queue, zram_make_request);
zram->disk = alloc_disk(1);
if (!zram->disk) {
pr_err("Error allocating disk structure for device %d\n",
device_id);
ret = -ENOMEM;
goto out_free_queue;
}
zram->disk->major = zram_major;
zram->disk->first_minor = device_id;
zram->disk->fops = &zram_devops;
zram->disk->queue = queue;
zram->disk->queue->queuedata = zram;
zram->disk->private_data = zram;
snprintf(zram->disk->disk_name, 16, "zram%d", device_id);
set_capacity(zram->disk, 0);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, zram->disk->queue);
queue_flag_clear_unlocked(QUEUE_FLAG_ADD_RANDOM, zram->disk->queue);
blk_queue_physical_block_size(zram->disk->queue, PAGE_SIZE);
blk_queue_logical_block_size(zram->disk->queue,
ZRAM_LOGICAL_BLOCK_SIZE);
blk_queue_io_min(zram->disk->queue, PAGE_SIZE);
blk_queue_io_opt(zram->disk->queue, PAGE_SIZE);
zram->disk->queue->limits.discard_granularity = PAGE_SIZE;
blk_queue_max_discard_sectors(zram->disk->queue, UINT_MAX);
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, zram->disk->queue);
if (ZRAM_LOGICAL_BLOCK_SIZE == PAGE_SIZE)
blk_queue_max_write_zeroes_sectors(zram->disk->queue, UINT_MAX);
add_disk(zram->disk);
ret = sysfs_create_group(&disk_to_dev(zram->disk)->kobj,
&zram_disk_attr_group);
if (ret < 0) {
pr_err("Error creating sysfs group for device %d\n",
device_id);
goto out_free_disk;
}
strlcpy(zram->compressor, default_compressor, sizeof(zram->compressor));
pr_info("Added device: %s\n", zram->disk->disk_name);
return device_id;
out_free_disk:
del_gendisk(zram->disk);
put_disk(zram->disk);
out_free_queue:
blk_cleanup_queue(queue);
out_free_idr:
idr_remove(&zram_index_idr, device_id);
out_free_dev:
kfree(zram);
return ret;
}
static int zram_remove(struct zram *zram)
{
struct block_device *bdev;
bdev = bdget_disk(zram->disk, 0);
if (!bdev)
return -ENOMEM;
mutex_lock(&bdev->bd_mutex);
if (bdev->bd_openers || zram->claim) {
mutex_unlock(&bdev->bd_mutex);
bdput(bdev);
return -EBUSY;
}
zram->claim = true;
mutex_unlock(&bdev->bd_mutex);
sysfs_remove_group(&disk_to_dev(zram->disk)->kobj,
&zram_disk_attr_group);
fsync_bdev(bdev);
zram_reset_device(zram);
bdput(bdev);
pr_info("Removed device: %s\n", zram->disk->disk_name);
blk_cleanup_queue(zram->disk->queue);
del_gendisk(zram->disk);
put_disk(zram->disk);
kfree(zram);
return 0;
}
static ssize_t hot_add_show(struct class *class,
struct class_attribute *attr,
char *buf)
{
int ret;
mutex_lock(&zram_index_mutex);
ret = zram_add();
mutex_unlock(&zram_index_mutex);
if (ret < 0)
return ret;
return scnprintf(buf, PAGE_SIZE, "%d\n", ret);
}
static ssize_t hot_remove_store(struct class *class,
struct class_attribute *attr,
const char *buf,
size_t count)
{
struct zram *zram;
int ret, dev_id;
ret = kstrtoint(buf, 10, &dev_id);
if (ret)
return ret;
if (dev_id < 0)
return -EINVAL;
mutex_lock(&zram_index_mutex);
zram = idr_find(&zram_index_idr, dev_id);
if (zram) {
ret = zram_remove(zram);
if (!ret)
idr_remove(&zram_index_idr, dev_id);
} else {
ret = -ENODEV;
}
mutex_unlock(&zram_index_mutex);
return ret ? ret : count;
}
static int zram_remove_cb(int id, void *ptr, void *data)
{
zram_remove(ptr);
return 0;
}
static void destroy_devices(void)
{
class_unregister(&zram_control_class);
idr_for_each(&zram_index_idr, &zram_remove_cb, NULL);
idr_destroy(&zram_index_idr);
unregister_blkdev(zram_major, "zram");
cpuhp_remove_multi_state(CPUHP_ZCOMP_PREPARE);
}
static int __init zram_init(void)
{
int ret;
ret = cpuhp_setup_state_multi(CPUHP_ZCOMP_PREPARE, "block/zram:prepare",
zcomp_cpu_up_prepare, zcomp_cpu_dead);
if (ret < 0)
return ret;
ret = class_register(&zram_control_class);
if (ret) {
pr_err("Unable to register zram-control class\n");
cpuhp_remove_multi_state(CPUHP_ZCOMP_PREPARE);
return ret;
}
zram_major = register_blkdev(0, "zram");
if (zram_major <= 0) {
pr_err("Unable to get major number\n");
class_unregister(&zram_control_class);
cpuhp_remove_multi_state(CPUHP_ZCOMP_PREPARE);
return -EBUSY;
}
while (num_devices != 0) {
mutex_lock(&zram_index_mutex);
ret = zram_add();
mutex_unlock(&zram_index_mutex);
if (ret < 0)
goto out_error;
num_devices--;
}
return 0;
out_error:
destroy_devices();
return ret;
}
static void __exit zram_exit(void)
{
destroy_devices();
}
