static void build_data_key(struct dm_thin_device *td,
dm_block_t b, struct dm_cell_key *key)
{
key->virtual = 0;
key->dev = dm_thin_dev_id(td);
key->block = b;
}
static void build_virtual_key(struct dm_thin_device *td, dm_block_t b,
struct dm_cell_key *key)
{
key->virtual = 1;
key->dev = dm_thin_dev_id(td);
key->block = b;
}
static void wake_worker(struct pool *pool)
{
queue_work(pool->wq, &pool->worker);
}
static int bio_detain(struct pool *pool, struct dm_cell_key *key, struct bio *bio,
struct dm_bio_prison_cell **cell_result)
{
int r;
struct dm_bio_prison_cell *cell_prealloc;
cell_prealloc = dm_bio_prison_alloc_cell(pool->prison, GFP_NOIO);
r = dm_bio_detain(pool->prison, key, bio, cell_prealloc, cell_result);
if (r)
dm_bio_prison_free_cell(pool->prison, cell_prealloc);
return r;
}
static void cell_release(struct pool *pool,
struct dm_bio_prison_cell *cell,
struct bio_list *bios)
{
dm_cell_release(pool->prison, cell, bios);
dm_bio_prison_free_cell(pool->prison, cell);
}
static void cell_release_no_holder(struct pool *pool,
struct dm_bio_prison_cell *cell,
struct bio_list *bios)
{
dm_cell_release_no_holder(pool->prison, cell, bios);
dm_bio_prison_free_cell(pool->prison, cell);
}
static void cell_defer_no_holder_no_free(struct thin_c *tc,
struct dm_bio_prison_cell *cell)
{
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&tc->lock, flags);
dm_cell_release_no_holder(pool->prison, cell, &tc->deferred_bio_list);
spin_unlock_irqrestore(&tc->lock, flags);
wake_worker(pool);
}
static void cell_error_with_code(struct pool *pool,
struct dm_bio_prison_cell *cell, int error_code)
{
dm_cell_error(pool->prison, cell, error_code);
dm_bio_prison_free_cell(pool->prison, cell);
}
static void cell_error(struct pool *pool, struct dm_bio_prison_cell *cell)
{
cell_error_with_code(pool, cell, -EIO);
}
static void pool_table_init(void)
{
mutex_init(&dm_thin_pool_table.mutex);
INIT_LIST_HEAD(&dm_thin_pool_table.pools);
}
static void __pool_table_insert(struct pool *pool)
{
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
list_add(&pool->list, &dm_thin_pool_table.pools);
}
static void __pool_table_remove(struct pool *pool)
{
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
list_del(&pool->list);
}
static struct pool *__pool_table_lookup(struct mapped_device *md)
{
struct pool *pool = NULL, *tmp;
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
list_for_each_entry(tmp, &dm_thin_pool_table.pools, list) {
if (tmp->pool_md == md) {
pool = tmp;
break;
}
}
return pool;
}
static struct pool *__pool_table_lookup_metadata_dev(struct block_device *md_dev)
{
struct pool *pool = NULL, *tmp;
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
list_for_each_entry(tmp, &dm_thin_pool_table.pools, list) {
if (tmp->md_dev == md_dev) {
pool = tmp;
break;
}
}
return pool;
}
static void requeue_bio_list(struct thin_c *tc, struct bio_list *master)
{
struct bio *bio;
struct bio_list bios;
unsigned long flags;
bio_list_init(&bios);
spin_lock_irqsave(&tc->lock, flags);
bio_list_merge(&bios, master);
bio_list_init(master);
spin_unlock_irqrestore(&tc->lock, flags);
while ((bio = bio_list_pop(&bios)))
bio_endio(bio, DM_ENDIO_REQUEUE);
}
static void requeue_io(struct thin_c *tc)
{
requeue_bio_list(tc, &tc->deferred_bio_list);
requeue_bio_list(tc, &tc->retry_on_resume_list);
}
static void error_thin_retry_list(struct thin_c *tc)
{
struct bio *bio;
unsigned long flags;
struct bio_list bios;
bio_list_init(&bios);
spin_lock_irqsave(&tc->lock, flags);
bio_list_merge(&bios, &tc->retry_on_resume_list);
bio_list_init(&tc->retry_on_resume_list);
spin_unlock_irqrestore(&tc->lock, flags);
while ((bio = bio_list_pop(&bios)))
bio_io_error(bio);
}
static void error_retry_list(struct pool *pool)
{
struct thin_c *tc;
rcu_read_lock();
list_for_each_entry_rcu(tc, &pool->active_thins, list)
error_thin_retry_list(tc);
rcu_read_unlock();
}
static bool block_size_is_power_of_two(struct pool *pool)
{
return pool->sectors_per_block_shift >= 0;
}
static dm_block_t get_bio_block(struct thin_c *tc, struct bio *bio)
{
struct pool *pool = tc->pool;
sector_t block_nr = bio->bi_iter.bi_sector;
if (block_size_is_power_of_two(pool))
block_nr >>= pool->sectors_per_block_shift;
else
(void) sector_div(block_nr, pool->sectors_per_block);
return block_nr;
}
static void remap(struct thin_c *tc, struct bio *bio, dm_block_t block)
{
struct pool *pool = tc->pool;
sector_t bi_sector = bio->bi_iter.bi_sector;
bio->bi_bdev = tc->pool_dev->bdev;
if (block_size_is_power_of_two(pool))
bio->bi_iter.bi_sector =
(block << pool->sectors_per_block_shift) |
(bi_sector & (pool->sectors_per_block - 1));
else
bio->bi_iter.bi_sector = (block * pool->sectors_per_block) +
sector_div(bi_sector, pool->sectors_per_block);
}
static void remap_to_origin(struct thin_c *tc, struct bio *bio)
{
bio->bi_bdev = tc->origin_dev->bdev;
}
static int bio_triggers_commit(struct thin_c *tc, struct bio *bio)
{
return (bio->bi_rw & (REQ_FLUSH | REQ_FUA)) &&
dm_thin_changed_this_transaction(tc->td);
}
static void inc_all_io_entry(struct pool *pool, struct bio *bio)
{
struct dm_thin_endio_hook *h;
if (bio->bi_rw & REQ_DISCARD)
return;
h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
h->all_io_entry = dm_deferred_entry_inc(pool->all_io_ds);
}
static void issue(struct thin_c *tc, struct bio *bio)
{
struct pool *pool = tc->pool;
unsigned long flags;
if (!bio_triggers_commit(tc, bio)) {
generic_make_request(bio);
return;
}
if (dm_thin_aborted_changes(tc->td)) {
bio_io_error(bio);
return;
}
spin_lock_irqsave(&pool->lock, flags);
bio_list_add(&pool->deferred_flush_bios, bio);
spin_unlock_irqrestore(&pool->lock, flags);
}
static void remap_to_origin_and_issue(struct thin_c *tc, struct bio *bio)
{
remap_to_origin(tc, bio);
issue(tc, bio);
}
static void remap_and_issue(struct thin_c *tc, struct bio *bio,
dm_block_t block)
{
remap(tc, bio, block);
issue(tc, bio);
}
static void __complete_mapping_preparation(struct dm_thin_new_mapping *m)
{
struct pool *pool = m->tc->pool;
if (atomic_dec_and_test(&m->prepare_actions)) {
list_add_tail(&m->list, &pool->prepared_mappings);
wake_worker(pool);
}
}
static void complete_mapping_preparation(struct dm_thin_new_mapping *m)
{
unsigned long flags;
struct pool *pool = m->tc->pool;
spin_lock_irqsave(&pool->lock, flags);
__complete_mapping_preparation(m);
spin_unlock_irqrestore(&pool->lock, flags);
}
static void copy_complete(int read_err, unsigned long write_err, void *context)
{
struct dm_thin_new_mapping *m = context;
m->err = read_err || write_err ? -EIO : 0;
complete_mapping_preparation(m);
}
static void overwrite_endio(struct bio *bio, int err)
{
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
struct dm_thin_new_mapping *m = h->overwrite_mapping;
m->err = err;
complete_mapping_preparation(m);
}
static void cell_defer(struct thin_c *tc, struct dm_bio_prison_cell *cell)
{
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&tc->lock, flags);
cell_release(pool, cell, &tc->deferred_bio_list);
spin_unlock_irqrestore(&tc->lock, flags);
wake_worker(pool);
}
static void cell_defer_no_holder(struct thin_c *tc, struct dm_bio_prison_cell *cell)
{
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&tc->lock, flags);
cell_release_no_holder(pool, cell, &tc->deferred_bio_list);
spin_unlock_irqrestore(&tc->lock, flags);
wake_worker(pool);
}
static void process_prepared_mapping_fail(struct dm_thin_new_mapping *m)
{
if (m->bio) {
m->bio->bi_end_io = m->saved_bi_end_io;
atomic_inc(&m->bio->bi_remaining);
}
cell_error(m->tc->pool, m->cell);
list_del(&m->list);
mempool_free(m, m->tc->pool->mapping_pool);
}
static void process_prepared_mapping(struct dm_thin_new_mapping *m)
{
struct thin_c *tc = m->tc;
struct pool *pool = tc->pool;
struct bio *bio;
int r;
bio = m->bio;
if (bio) {
bio->bi_end_io = m->saved_bi_end_io;
atomic_inc(&bio->bi_remaining);
}
if (m->err) {
cell_error(pool, m->cell);
goto out;
}
r = dm_thin_insert_block(tc->td, m->virt_block, m->data_block);
if (r) {
metadata_operation_failed(pool, "dm_thin_insert_block", r);
cell_error(pool, m->cell);
goto out;
}
if (bio) {
cell_defer_no_holder(tc, m->cell);
bio_endio(bio, 0);
} else
cell_defer(tc, m->cell);
out:
list_del(&m->list);
mempool_free(m, pool->mapping_pool);
}
static void process_prepared_discard_fail(struct dm_thin_new_mapping *m)
{
struct thin_c *tc = m->tc;
bio_io_error(m->bio);
cell_defer_no_holder(tc, m->cell);
cell_defer_no_holder(tc, m->cell2);
mempool_free(m, tc->pool->mapping_pool);
}
static void process_prepared_discard_passdown(struct dm_thin_new_mapping *m)
{
struct thin_c *tc = m->tc;
inc_all_io_entry(tc->pool, m->bio);
cell_defer_no_holder(tc, m->cell);
cell_defer_no_holder(tc, m->cell2);
if (m->pass_discard)
if (m->definitely_not_shared)
remap_and_issue(tc, m->bio, m->data_block);
else {
bool used = false;
if (dm_pool_block_is_used(tc->pool->pmd, m->data_block, &used) || used)
bio_endio(m->bio, 0);
else
remap_and_issue(tc, m->bio, m->data_block);
}
else
bio_endio(m->bio, 0);
mempool_free(m, tc->pool->mapping_pool);
}
static void process_prepared_discard(struct dm_thin_new_mapping *m)
{
int r;
struct thin_c *tc = m->tc;
r = dm_thin_remove_block(tc->td, m->virt_block);
if (r)
DMERR_LIMIT("dm_thin_remove_block() failed");
process_prepared_discard_passdown(m);
}
static void process_prepared(struct pool *pool, struct list_head *head,
process_mapping_fn *fn)
{
unsigned long flags;
struct list_head maps;
struct dm_thin_new_mapping *m, *tmp;
INIT_LIST_HEAD(&maps);
spin_lock_irqsave(&pool->lock, flags);
list_splice_init(head, &maps);
spin_unlock_irqrestore(&pool->lock, flags);
list_for_each_entry_safe(m, tmp, &maps, list)
(*fn)(m);
}
static int io_overlaps_block(struct pool *pool, struct bio *bio)
{
return bio->bi_iter.bi_size ==
(pool->sectors_per_block << SECTOR_SHIFT);
}
static int io_overwrites_block(struct pool *pool, struct bio *bio)
{
return (bio_data_dir(bio) == WRITE) &&
io_overlaps_block(pool, bio);
}
static void save_and_set_endio(struct bio *bio, bio_end_io_t **save,
bio_end_io_t *fn)
{
*save = bio->bi_end_io;
bio->bi_end_io = fn;
}
static int ensure_next_mapping(struct pool *pool)
{
if (pool->next_mapping)
return 0;
pool->next_mapping = mempool_alloc(pool->mapping_pool, GFP_ATOMIC);
return pool->next_mapping ? 0 : -ENOMEM;
}
static struct dm_thin_new_mapping *get_next_mapping(struct pool *pool)
{
struct dm_thin_new_mapping *m = pool->next_mapping;
BUG_ON(!pool->next_mapping);
memset(m, 0, sizeof(struct dm_thin_new_mapping));
INIT_LIST_HEAD(&m->list);
m->bio = NULL;
pool->next_mapping = NULL;
return m;
}
static void ll_zero(struct thin_c *tc, struct dm_thin_new_mapping *m,
sector_t begin, sector_t end)
{
int r;
struct dm_io_region to;
to.bdev = tc->pool_dev->bdev;
to.sector = begin;
to.count = end - begin;
r = dm_kcopyd_zero(tc->pool->copier, 1, &to, 0, copy_complete, m);
if (r < 0) {
DMERR_LIMIT("dm_kcopyd_zero() failed");
copy_complete(1, 1, m);
}
}
static void schedule_copy(struct thin_c *tc, dm_block_t virt_block,
struct dm_dev *origin, dm_block_t data_origin,
dm_block_t data_dest,
struct dm_bio_prison_cell *cell, struct bio *bio,
sector_t len)
{
int r;
struct pool *pool = tc->pool;
struct dm_thin_new_mapping *m = get_next_mapping(pool);
m->tc = tc;
m->virt_block = virt_block;
m->data_block = data_dest;
m->cell = cell;
atomic_set(&m->prepare_actions, 3);
if (!dm_deferred_set_add_work(pool->shared_read_ds, &m->list))
complete_mapping_preparation(m);
if (io_overwrites_block(pool, bio)) {
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
h->overwrite_mapping = m;
m->bio = bio;
save_and_set_endio(bio, &m->saved_bi_end_io, overwrite_endio);
inc_all_io_entry(pool, bio);
remap_and_issue(tc, bio, data_dest);
} else {
struct dm_io_region from, to;
from.bdev = origin->bdev;
from.sector = data_origin * pool->sectors_per_block;
from.count = len;
to.bdev = tc->pool_dev->bdev;
to.sector = data_dest * pool->sectors_per_block;
to.count = len;
r = dm_kcopyd_copy(pool->copier, &from, 1, &to,
0, copy_complete, m);
if (r < 0) {
DMERR_LIMIT("dm_kcopyd_copy() failed");
copy_complete(1, 1, m);
}
if (len < pool->sectors_per_block && pool->pf.zero_new_blocks) {
atomic_inc(&m->prepare_actions);
ll_zero(tc, m,
data_dest * pool->sectors_per_block + len,
(data_dest + 1) * pool->sectors_per_block);
}
}
complete_mapping_preparation(m);
}
static void schedule_internal_copy(struct thin_c *tc, dm_block_t virt_block,
dm_block_t data_origin, dm_block_t data_dest,
struct dm_bio_prison_cell *cell, struct bio *bio)
{
schedule_copy(tc, virt_block, tc->pool_dev,
data_origin, data_dest, cell, bio,
tc->pool->sectors_per_block);
}
static void schedule_zero(struct thin_c *tc, dm_block_t virt_block,
dm_block_t data_block, struct dm_bio_prison_cell *cell,
struct bio *bio)
{
struct pool *pool = tc->pool;
struct dm_thin_new_mapping *m = get_next_mapping(pool);
atomic_set(&m->prepare_actions, 1);
m->tc = tc;
m->virt_block = virt_block;
m->data_block = data_block;
m->cell = cell;
if (!pool->pf.zero_new_blocks)
process_prepared_mapping(m);
else if (io_overwrites_block(pool, bio)) {
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
h->overwrite_mapping = m;
m->bio = bio;
save_and_set_endio(bio, &m->saved_bi_end_io, overwrite_endio);
inc_all_io_entry(pool, bio);
remap_and_issue(tc, bio, data_block);
} else
ll_zero(tc, m,
data_block * pool->sectors_per_block,
(data_block + 1) * pool->sectors_per_block);
}
static void schedule_external_copy(struct thin_c *tc, dm_block_t virt_block,
dm_block_t data_dest,
struct dm_bio_prison_cell *cell, struct bio *bio)
{
struct pool *pool = tc->pool;
sector_t virt_block_begin = virt_block * pool->sectors_per_block;
sector_t virt_block_end = (virt_block + 1) * pool->sectors_per_block;
if (virt_block_end <= tc->origin_size)
schedule_copy(tc, virt_block, tc->origin_dev,
virt_block, data_dest, cell, bio,
pool->sectors_per_block);
else if (virt_block_begin < tc->origin_size)
schedule_copy(tc, virt_block, tc->origin_dev,
virt_block, data_dest, cell, bio,
tc->origin_size - virt_block_begin);
else
schedule_zero(tc, virt_block, data_dest, cell, bio);
}
static int commit(struct pool *pool)
{
int r;
if (get_pool_mode(pool) >= PM_READ_ONLY)
return -EINVAL;
r = dm_pool_commit_metadata(pool->pmd);
if (r)
metadata_operation_failed(pool, "dm_pool_commit_metadata", r);
return r;
}
static void check_low_water_mark(struct pool *pool, dm_block_t free_blocks)
{
unsigned long flags;
if (free_blocks <= pool->low_water_blocks && !pool->low_water_triggered) {
DMWARN("%s: reached low water mark for data device: sending event.",
dm_device_name(pool->pool_md));
spin_lock_irqsave(&pool->lock, flags);
pool->low_water_triggered = true;
spin_unlock_irqrestore(&pool->lock, flags);
dm_table_event(pool->ti->table);
}
}
static int alloc_data_block(struct thin_c *tc, dm_block_t *result)
{
int r;
dm_block_t free_blocks;
struct pool *pool = tc->pool;
if (WARN_ON(get_pool_mode(pool) != PM_WRITE))
return -EINVAL;
r = dm_pool_get_free_block_count(pool->pmd, &free_blocks);
if (r) {
metadata_operation_failed(pool, "dm_pool_get_free_block_count", r);
return r;
}
check_low_water_mark(pool, free_blocks);
if (!free_blocks) {
r = commit(pool);
if (r)
return r;
r = dm_pool_get_free_block_count(pool->pmd, &free_blocks);
if (r) {
metadata_operation_failed(pool, "dm_pool_get_free_block_count", r);
return r;
}
if (!free_blocks) {
set_pool_mode(pool, PM_OUT_OF_DATA_SPACE);
return -ENOSPC;
}
}
r = dm_pool_alloc_data_block(pool->pmd, result);
if (r) {
metadata_operation_failed(pool, "dm_pool_alloc_data_block", r);
return r;
}
return 0;
}
static void retry_on_resume(struct bio *bio)
{
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
struct thin_c *tc = h->tc;
unsigned long flags;
spin_lock_irqsave(&tc->lock, flags);
bio_list_add(&tc->retry_on_resume_list, bio);
spin_unlock_irqrestore(&tc->lock, flags);
}
static int should_error_unserviceable_bio(struct pool *pool)
{
enum pool_mode m = get_pool_mode(pool);
switch (m) {
case PM_WRITE:
DMERR_LIMIT("bio unserviceable, yet pool is in PM_WRITE mode");
return -EIO;
case PM_OUT_OF_DATA_SPACE:
return pool->pf.error_if_no_space ? -ENOSPC : 0;
case PM_READ_ONLY:
case PM_FAIL:
return -EIO;
default:
DMERR_LIMIT("bio unserviceable, yet pool has an unknown mode");
return -EIO;
}
}
static void handle_unserviceable_bio(struct pool *pool, struct bio *bio)
{
int error = should_error_unserviceable_bio(pool);
if (error)
bio_endio(bio, error);
else
retry_on_resume(bio);
}
static void retry_bios_on_resume(struct pool *pool, struct dm_bio_prison_cell *cell)
{
struct bio *bio;
struct bio_list bios;
int error;
error = should_error_unserviceable_bio(pool);
if (error) {
cell_error_with_code(pool, cell, error);
return;
}
bio_list_init(&bios);
cell_release(pool, cell, &bios);
error = should_error_unserviceable_bio(pool);
if (error)
while ((bio = bio_list_pop(&bios)))
bio_endio(bio, error);
else
while ((bio = bio_list_pop(&bios)))
retry_on_resume(bio);
}
static void process_discard(struct thin_c *tc, struct bio *bio)
{
int r;
unsigned long flags;
struct pool *pool = tc->pool;
struct dm_bio_prison_cell *cell, *cell2;
struct dm_cell_key key, key2;
dm_block_t block = get_bio_block(tc, bio);
struct dm_thin_lookup_result lookup_result;
struct dm_thin_new_mapping *m;
build_virtual_key(tc->td, block, &key);
if (bio_detain(tc->pool, &key, bio, &cell))
return;
r = dm_thin_find_block(tc->td, block, 1, &lookup_result);
switch (r) {
case 0:
build_data_key(tc->td, lookup_result.block, &key2);
if (bio_detain(tc->pool, &key2, bio, &cell2)) {
cell_defer_no_holder(tc, cell);
break;
}
if (io_overlaps_block(pool, bio)) {
m = get_next_mapping(pool);
m->tc = tc;
m->pass_discard = pool->pf.discard_passdown;
m->definitely_not_shared = !lookup_result.shared;
m->virt_block = block;
m->data_block = lookup_result.block;
m->cell = cell;
m->cell2 = cell2;
m->bio = bio;
if (!dm_deferred_set_add_work(pool->all_io_ds, &m->list)) {
spin_lock_irqsave(&pool->lock, flags);
list_add_tail(&m->list, &pool->prepared_discards);
spin_unlock_irqrestore(&pool->lock, flags);
wake_worker(pool);
}
} else {
inc_all_io_entry(pool, bio);
cell_defer_no_holder(tc, cell);
cell_defer_no_holder(tc, cell2);
if ((!lookup_result.shared) && pool->pf.discard_passdown)
remap_and_issue(tc, bio, lookup_result.block);
else
bio_endio(bio, 0);
}
break;
case -ENODATA:
cell_defer_no_holder(tc, cell);
bio_endio(bio, 0);
break;
default:
DMERR_LIMIT("%s: dm_thin_find_block() failed: error = %d",
__func__, r);
cell_defer_no_holder(tc, cell);
bio_io_error(bio);
break;
}
}
static void break_sharing(struct thin_c *tc, struct bio *bio, dm_block_t block,
struct dm_cell_key *key,
struct dm_thin_lookup_result *lookup_result,
struct dm_bio_prison_cell *cell)
{
int r;
dm_block_t data_block;
struct pool *pool = tc->pool;
r = alloc_data_block(tc, &data_block);
switch (r) {
case 0:
schedule_internal_copy(tc, block, lookup_result->block,
data_block, cell, bio);
break;
case -ENOSPC:
retry_bios_on_resume(pool, cell);
break;
default:
DMERR_LIMIT("%s: alloc_data_block() failed: error = %d",
__func__, r);
cell_error(pool, cell);
break;
}
}
static void process_shared_bio(struct thin_c *tc, struct bio *bio,
dm_block_t block,
struct dm_thin_lookup_result *lookup_result)
{
struct dm_bio_prison_cell *cell;
struct pool *pool = tc->pool;
struct dm_cell_key key;
build_data_key(tc->td, lookup_result->block, &key);
if (bio_detain(pool, &key, bio, &cell))
return;
if (bio_data_dir(bio) == WRITE && bio->bi_iter.bi_size)
break_sharing(tc, bio, block, &key, lookup_result, cell);
else {
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
h->shared_read_entry = dm_deferred_entry_inc(pool->shared_read_ds);
inc_all_io_entry(pool, bio);
cell_defer_no_holder(tc, cell);
remap_and_issue(tc, bio, lookup_result->block);
}
}
static void provision_block(struct thin_c *tc, struct bio *bio, dm_block_t block,
struct dm_bio_prison_cell *cell)
{
int r;
dm_block_t data_block;
struct pool *pool = tc->pool;
if (!bio->bi_iter.bi_size) {
inc_all_io_entry(pool, bio);
cell_defer_no_holder(tc, cell);
remap_and_issue(tc, bio, 0);
return;
}
if (bio_data_dir(bio) == READ) {
zero_fill_bio(bio);
cell_defer_no_holder(tc, cell);
bio_endio(bio, 0);
return;
}
r = alloc_data_block(tc, &data_block);
switch (r) {
case 0:
if (tc->origin_dev)
schedule_external_copy(tc, block, data_block, cell, bio);
else
schedule_zero(tc, block, data_block, cell, bio);
break;
case -ENOSPC:
retry_bios_on_resume(pool, cell);
break;
default:
DMERR_LIMIT("%s: alloc_data_block() failed: error = %d",
__func__, r);
cell_error(pool, cell);
break;
}
}
static void process_bio(struct thin_c *tc, struct bio *bio)
{
int r;
struct pool *pool = tc->pool;
dm_block_t block = get_bio_block(tc, bio);
struct dm_bio_prison_cell *cell;
struct dm_cell_key key;
struct dm_thin_lookup_result lookup_result;
build_virtual_key(tc->td, block, &key);
if (bio_detain(pool, &key, bio, &cell))
return;
r = dm_thin_find_block(tc->td, block, 1, &lookup_result);
switch (r) {
case 0:
if (lookup_result.shared) {
process_shared_bio(tc, bio, block, &lookup_result);
cell_defer_no_holder(tc, cell);
} else {
inc_all_io_entry(pool, bio);
cell_defer_no_holder(tc, cell);
remap_and_issue(tc, bio, lookup_result.block);
}
break;
case -ENODATA:
if (bio_data_dir(bio) == READ && tc->origin_dev) {
inc_all_io_entry(pool, bio);
cell_defer_no_holder(tc, cell);
if (bio_end_sector(bio) <= tc->origin_size)
remap_to_origin_and_issue(tc, bio);
else if (bio->bi_iter.bi_sector < tc->origin_size) {
zero_fill_bio(bio);
bio->bi_iter.bi_size = (tc->origin_size - bio->bi_iter.bi_sector) << SECTOR_SHIFT;
remap_to_origin_and_issue(tc, bio);
} else {
zero_fill_bio(bio);
bio_endio(bio, 0);
}
} else
provision_block(tc, bio, block, cell);
break;
default:
DMERR_LIMIT("%s: dm_thin_find_block() failed: error = %d",
__func__, r);
cell_defer_no_holder(tc, cell);
bio_io_error(bio);
break;
}
}
static void process_bio_read_only(struct thin_c *tc, struct bio *bio)
{
int r;
int rw = bio_data_dir(bio);
dm_block_t block = get_bio_block(tc, bio);
struct dm_thin_lookup_result lookup_result;
r = dm_thin_find_block(tc->td, block, 1, &lookup_result);
switch (r) {
case 0:
if (lookup_result.shared && (rw == WRITE) && bio->bi_iter.bi_size)
handle_unserviceable_bio(tc->pool, bio);
else {
inc_all_io_entry(tc->pool, bio);
remap_and_issue(tc, bio, lookup_result.block);
}
break;
case -ENODATA:
if (rw != READ) {
handle_unserviceable_bio(tc->pool, bio);
break;
}
if (tc->origin_dev) {
inc_all_io_entry(tc->pool, bio);
remap_to_origin_and_issue(tc, bio);
break;
}
zero_fill_bio(bio);
bio_endio(bio, 0);
break;
default:
DMERR_LIMIT("%s: dm_thin_find_block() failed: error = %d",
__func__, r);
bio_io_error(bio);
break;
}
}
static void process_bio_success(struct thin_c *tc, struct bio *bio)
{
bio_endio(bio, 0);
}
static void process_bio_fail(struct thin_c *tc, struct bio *bio)
{
bio_io_error(bio);
}
static int need_commit_due_to_time(struct pool *pool)
{
return jiffies < pool->last_commit_jiffies ||
jiffies > pool->last_commit_jiffies + COMMIT_PERIOD;
}
static void __thin_bio_rb_add(struct thin_c *tc, struct bio *bio)
{
struct rb_node **rbp, *parent;
struct dm_thin_endio_hook *pbd;
sector_t bi_sector = bio->bi_iter.bi_sector;
rbp = &tc->sort_bio_list.rb_node;
parent = NULL;
while (*rbp) {
parent = *rbp;
pbd = thin_pbd(parent);
if (bi_sector < thin_bio(pbd)->bi_iter.bi_sector)
rbp = &(*rbp)->rb_left;
else
rbp = &(*rbp)->rb_right;
}
pbd = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
rb_link_node(&pbd->rb_node, parent, rbp);
rb_insert_color(&pbd->rb_node, &tc->sort_bio_list);
}
static void __extract_sorted_bios(struct thin_c *tc)
{
struct rb_node *node;
struct dm_thin_endio_hook *pbd;
struct bio *bio;
for (node = rb_first(&tc->sort_bio_list); node; node = rb_next(node)) {
pbd = thin_pbd(node);
bio = thin_bio(pbd);
bio_list_add(&tc->deferred_bio_list, bio);
rb_erase(&pbd->rb_node, &tc->sort_bio_list);
}
WARN_ON(!RB_EMPTY_ROOT(&tc->sort_bio_list));
}
static void __sort_thin_deferred_bios(struct thin_c *tc)
{
struct bio *bio;
struct bio_list bios;
bio_list_init(&bios);
bio_list_merge(&bios, &tc->deferred_bio_list);
bio_list_init(&tc->deferred_bio_list);
while ((bio = bio_list_pop(&bios)))
__thin_bio_rb_add(tc, bio);
__extract_sorted_bios(tc);
}
static void process_thin_deferred_bios(struct thin_c *tc)
{
struct pool *pool = tc->pool;
unsigned long flags;
struct bio *bio;
struct bio_list bios;
struct blk_plug plug;
if (tc->requeue_mode) {
requeue_bio_list(tc, &tc->deferred_bio_list);
return;
}
bio_list_init(&bios);
spin_lock_irqsave(&tc->lock, flags);
if (bio_list_empty(&tc->deferred_bio_list)) {
spin_unlock_irqrestore(&tc->lock, flags);
return;
}
__sort_thin_deferred_bios(tc);
bio_list_merge(&bios, &tc->deferred_bio_list);
bio_list_init(&tc->deferred_bio_list);
spin_unlock_irqrestore(&tc->lock, flags);
blk_start_plug(&plug);
while ((bio = bio_list_pop(&bios))) {
if (ensure_next_mapping(pool)) {
spin_lock_irqsave(&tc->lock, flags);
bio_list_add(&tc->deferred_bio_list, bio);
bio_list_merge(&tc->deferred_bio_list, &bios);
spin_unlock_irqrestore(&tc->lock, flags);
break;
}
if (bio->bi_rw & REQ_DISCARD)
pool->process_discard(tc, bio);
else
pool->process_bio(tc, bio);
}
blk_finish_plug(&plug);
}
static struct thin_c *get_first_thin(struct pool *pool)
{
struct thin_c *tc = NULL;
rcu_read_lock();
if (!list_empty(&pool->active_thins)) {
tc = list_entry_rcu(pool->active_thins.next, struct thin_c, list);
thin_get(tc);
}
rcu_read_unlock();
return tc;
}
static struct thin_c *get_next_thin(struct pool *pool, struct thin_c *tc)
{
struct thin_c *old_tc = tc;
rcu_read_lock();
list_for_each_entry_continue_rcu(tc, &pool->active_thins, list) {
thin_get(tc);
thin_put(old_tc);
rcu_read_unlock();
return tc;
}
thin_put(old_tc);
rcu_read_unlock();
return NULL;
}
static void process_deferred_bios(struct pool *pool)
{
unsigned long flags;
struct bio *bio;
struct bio_list bios;
struct thin_c *tc;
tc = get_first_thin(pool);
while (tc) {
process_thin_deferred_bios(tc);
tc = get_next_thin(pool, tc);
}
bio_list_init(&bios);
spin_lock_irqsave(&pool->lock, flags);
bio_list_merge(&bios, &pool->deferred_flush_bios);
bio_list_init(&pool->deferred_flush_bios);
spin_unlock_irqrestore(&pool->lock, flags);
if (bio_list_empty(&bios) &&
!(dm_pool_changed_this_transaction(pool->pmd) && need_commit_due_to_time(pool)))
return;
if (commit(pool)) {
while ((bio = bio_list_pop(&bios)))
bio_io_error(bio);
return;
}
pool->last_commit_jiffies = jiffies;
while ((bio = bio_list_pop(&bios)))
generic_make_request(bio);
}
static void do_worker(struct work_struct *ws)
{
struct pool *pool = container_of(ws, struct pool, worker);
process_prepared(pool, &pool->prepared_mappings, &pool->process_prepared_mapping);
process_prepared(pool, &pool->prepared_discards, &pool->process_prepared_discard);
process_deferred_bios(pool);
}
static void do_waker(struct work_struct *ws)
{
struct pool *pool = container_of(to_delayed_work(ws), struct pool, waker);
wake_worker(pool);
queue_delayed_work(pool->wq, &pool->waker, COMMIT_PERIOD);
}
static void do_no_space_timeout(struct work_struct *ws)
{
struct pool *pool = container_of(to_delayed_work(ws), struct pool,
no_space_timeout);
if (get_pool_mode(pool) == PM_OUT_OF_DATA_SPACE && !pool->pf.error_if_no_space)
set_pool_mode(pool, PM_READ_ONLY);
}
static struct pool_work *to_pool_work(struct work_struct *ws)
{
return container_of(ws, struct pool_work, worker);
}
static void pool_work_complete(struct pool_work *pw)
{
complete(&pw->complete);
}
static void pool_work_wait(struct pool_work *pw, struct pool *pool,
void (*fn)(struct work_struct *))
{
INIT_WORK_ONSTACK(&pw->worker, fn);
init_completion(&pw->complete);
queue_work(pool->wq, &pw->worker);
wait_for_completion(&pw->complete);
}
static struct noflush_work *to_noflush(struct work_struct *ws)
{
return container_of(to_pool_work(ws), struct noflush_work, pw);
}
static void do_noflush_start(struct work_struct *ws)
{
struct noflush_work *w = to_noflush(ws);
w->tc->requeue_mode = true;
requeue_io(w->tc);
pool_work_complete(&w->pw);
}
static void do_noflush_stop(struct work_struct *ws)
{
struct noflush_work *w = to_noflush(ws);
w->tc->requeue_mode = false;
pool_work_complete(&w->pw);
}
static void noflush_work(struct thin_c *tc, void (*fn)(struct work_struct *))
{
struct noflush_work w;
w.tc = tc;
pool_work_wait(&w.pw, tc->pool, fn);
}
static enum pool_mode get_pool_mode(struct pool *pool)
{
return pool->pf.mode;
}
static void notify_of_pool_mode_change(struct pool *pool, const char *new_mode)
{
dm_table_event(pool->ti->table);
DMINFO("%s: switching pool to %s mode",
dm_device_name(pool->pool_md), new_mode);
}
static void set_pool_mode(struct pool *pool, enum pool_mode new_mode)
{
struct pool_c *pt = pool->ti->private;
bool needs_check = dm_pool_metadata_needs_check(pool->pmd);
enum pool_mode old_mode = get_pool_mode(pool);
unsigned long no_space_timeout = ACCESS_ONCE(no_space_timeout_secs) * HZ;
if (new_mode == PM_WRITE && needs_check) {
DMERR("%s: unable to switch pool to write mode until repaired.",
dm_device_name(pool->pool_md));
if (old_mode != new_mode)
new_mode = old_mode;
else
new_mode = PM_READ_ONLY;
}
if (old_mode == PM_FAIL)
new_mode = old_mode;
switch (new_mode) {
case PM_FAIL:
if (old_mode != new_mode)
notify_of_pool_mode_change(pool, "failure");
dm_pool_metadata_read_only(pool->pmd);
pool->process_bio = process_bio_fail;
pool->process_discard = process_bio_fail;
pool->process_prepared_mapping = process_prepared_mapping_fail;
pool->process_prepared_discard = process_prepared_discard_fail;
error_retry_list(pool);
break;
case PM_READ_ONLY:
if (old_mode != new_mode)
notify_of_pool_mode_change(pool, "read-only");
dm_pool_metadata_read_only(pool->pmd);
pool->process_bio = process_bio_read_only;
pool->process_discard = process_bio_success;
pool->process_prepared_mapping = process_prepared_mapping_fail;
pool->process_prepared_discard = process_prepared_discard_passdown;
error_retry_list(pool);
break;
case PM_OUT_OF_DATA_SPACE:
if (old_mode != new_mode)
notify_of_pool_mode_change(pool, "out-of-data-space");
pool->process_bio = process_bio_read_only;
pool->process_discard = process_discard;
pool->process_prepared_mapping = process_prepared_mapping;
pool->process_prepared_discard = process_prepared_discard_passdown;
if (!pool->pf.error_if_no_space && no_space_timeout)
queue_delayed_work(pool->wq, &pool->no_space_timeout, no_space_timeout);
break;
case PM_WRITE:
if (old_mode != new_mode)
notify_of_pool_mode_change(pool, "write");
dm_pool_metadata_read_write(pool->pmd);
pool->process_bio = process_bio;
pool->process_discard = process_discard;
pool->process_prepared_mapping = process_prepared_mapping;
pool->process_prepared_discard = process_prepared_discard;
break;
}
pool->pf.mode = new_mode;
pt->adjusted_pf.mode = new_mode;
}
static void abort_transaction(struct pool *pool)
{
const char *dev_name = dm_device_name(pool->pool_md);
DMERR_LIMIT("%s: aborting current metadata transaction", dev_name);
if (dm_pool_abort_metadata(pool->pmd)) {
DMERR("%s: failed to abort metadata transaction", dev_name);
set_pool_mode(pool, PM_FAIL);
}
if (dm_pool_metadata_set_needs_check(pool->pmd)) {
DMERR("%s: failed to set 'needs_check' flag in metadata", dev_name);
set_pool_mode(pool, PM_FAIL);
}
}
static void metadata_operation_failed(struct pool *pool, const char *op, int r)
{
DMERR_LIMIT("%s: metadata operation '%s' failed: error = %d",
dm_device_name(pool->pool_md), op, r);
abort_transaction(pool);
set_pool_mode(pool, PM_READ_ONLY);
}
static void thin_defer_bio(struct thin_c *tc, struct bio *bio)
{
unsigned long flags;
struct pool *pool = tc->pool;
spin_lock_irqsave(&tc->lock, flags);
bio_list_add(&tc->deferred_bio_list, bio);
spin_unlock_irqrestore(&tc->lock, flags);
wake_worker(pool);
}
static void thin_hook_bio(struct thin_c *tc, struct bio *bio)
{
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
h->tc = tc;
h->shared_read_entry = NULL;
h->all_io_entry = NULL;
h->overwrite_mapping = NULL;
}
static int thin_bio_map(struct dm_target *ti, struct bio *bio)
{
int r;
struct thin_c *tc = ti->private;
dm_block_t block = get_bio_block(tc, bio);
struct dm_thin_device *td = tc->td;
struct dm_thin_lookup_result result;
struct dm_bio_prison_cell cell1, cell2;
struct dm_bio_prison_cell *cell_result;
struct dm_cell_key key;
thin_hook_bio(tc, bio);
if (tc->requeue_mode) {
bio_endio(bio, DM_ENDIO_REQUEUE);
return DM_MAPIO_SUBMITTED;
}
if (get_pool_mode(tc->pool) == PM_FAIL) {
bio_io_error(bio);
return DM_MAPIO_SUBMITTED;
}
if (bio->bi_rw & (REQ_DISCARD | REQ_FLUSH | REQ_FUA)) {
thin_defer_bio(tc, bio);
return DM_MAPIO_SUBMITTED;
}
build_virtual_key(tc->td, block, &key);
if (dm_bio_detain(tc->pool->prison, &key, bio, &cell1, &cell_result))
return DM_MAPIO_SUBMITTED;
r = dm_thin_find_block(td, block, 0, &result);
switch (r) {
case 0:
if (unlikely(result.shared)) {
thin_defer_bio(tc, bio);
cell_defer_no_holder_no_free(tc, &cell1);
return DM_MAPIO_SUBMITTED;
}
build_data_key(tc->td, result.block, &key);
if (dm_bio_detain(tc->pool->prison, &key, bio, &cell2, &cell_result)) {
cell_defer_no_holder_no_free(tc, &cell1);
return DM_MAPIO_SUBMITTED;
}
inc_all_io_entry(tc->pool, bio);
cell_defer_no_holder_no_free(tc, &cell2);
cell_defer_no_holder_no_free(tc, &cell1);
remap(tc, bio, result.block);
return DM_MAPIO_REMAPPED;
case -ENODATA:
if (get_pool_mode(tc->pool) == PM_READ_ONLY) {
handle_unserviceable_bio(tc->pool, bio);
cell_defer_no_holder_no_free(tc, &cell1);
return DM_MAPIO_SUBMITTED;
}
case -EWOULDBLOCK:
thin_defer_bio(tc, bio);
cell_defer_no_holder_no_free(tc, &cell1);
return DM_MAPIO_SUBMITTED;
default:
bio_io_error(bio);
cell_defer_no_holder_no_free(tc, &cell1);
return DM_MAPIO_SUBMITTED;
}
}
static int pool_is_congested(struct dm_target_callbacks *cb, int bdi_bits)
{
struct pool_c *pt = container_of(cb, struct pool_c, callbacks);
struct request_queue *q;
if (get_pool_mode(pt->pool) == PM_OUT_OF_DATA_SPACE)
return 1;
q = bdev_get_queue(pt->data_dev->bdev);
return bdi_congested(&q->backing_dev_info, bdi_bits);
}
static void requeue_bios(struct pool *pool)
{
unsigned long flags;
struct thin_c *tc;
rcu_read_lock();
list_for_each_entry_rcu(tc, &pool->active_thins, list) {
spin_lock_irqsave(&tc->lock, flags);
bio_list_merge(&tc->deferred_bio_list, &tc->retry_on_resume_list);
bio_list_init(&tc->retry_on_resume_list);
spin_unlock_irqrestore(&tc->lock, flags);
}
rcu_read_unlock();
}
static bool data_dev_supports_discard(struct pool_c *pt)
{
struct request_queue *q = bdev_get_queue(pt->data_dev->bdev);
return q && blk_queue_discard(q);
}
static bool is_factor(sector_t block_size, uint32_t n)
{
return !sector_div(block_size, n);
}
static void disable_passdown_if_not_supported(struct pool_c *pt)
{
struct pool *pool = pt->pool;
struct block_device *data_bdev = pt->data_dev->bdev;
struct queue_limits *data_limits = &bdev_get_queue(data_bdev)->limits;
sector_t block_size = pool->sectors_per_block << SECTOR_SHIFT;
const char *reason = NULL;
char buf[BDEVNAME_SIZE];
if (!pt->adjusted_pf.discard_passdown)
return;
if (!data_dev_supports_discard(pt))
reason = "discard unsupported";
else if (data_limits->max_discard_sectors < pool->sectors_per_block)
reason = "max discard sectors smaller than a block";
else if (data_limits->discard_granularity > block_size)
reason = "discard granularity larger than a block";
else if (!is_factor(block_size, data_limits->discard_granularity))
reason = "discard granularity not a factor of block size";
if (reason) {
DMWARN("Data device (%s) %s: Disabling discard passdown.", bdevname(data_bdev, buf), reason);
pt->adjusted_pf.discard_passdown = false;
}
}
static int bind_control_target(struct pool *pool, struct dm_target *ti)
{
struct pool_c *pt = ti->private;
enum pool_mode old_mode = get_pool_mode(pool);
enum pool_mode new_mode = pt->adjusted_pf.mode;
pt->adjusted_pf.mode = old_mode;
pool->ti = ti;
pool->pf = pt->adjusted_pf;
pool->low_water_blocks = pt->low_water_blocks;
set_pool_mode(pool, new_mode);
return 0;
}
static void unbind_control_target(struct pool *pool, struct dm_target *ti)
{
if (pool->ti == ti)
pool->ti = NULL;
}
static void pool_features_init(struct pool_features *pf)
{
pf->mode = PM_WRITE;
pf->zero_new_blocks = true;
pf->discard_enabled = true;
pf->discard_passdown = true;
pf->error_if_no_space = false;
}
static void __pool_destroy(struct pool *pool)
{
__pool_table_remove(pool);
if (dm_pool_metadata_close(pool->pmd) < 0)
DMWARN("%s: dm_pool_metadata_close() failed.", __func__);
dm_bio_prison_destroy(pool->prison);
dm_kcopyd_client_destroy(pool->copier);
if (pool->wq)
destroy_workqueue(pool->wq);
if (pool->next_mapping)
mempool_free(pool->next_mapping, pool->mapping_pool);
mempool_destroy(pool->mapping_pool);
dm_deferred_set_destroy(pool->shared_read_ds);
dm_deferred_set_destroy(pool->all_io_ds);
kfree(pool);
}
static struct pool *pool_create(struct mapped_device *pool_md,
struct block_device *metadata_dev,
unsigned long block_size,
int read_only, char **error)
{
int r;
void *err_p;
struct pool *pool;
struct dm_pool_metadata *pmd;
bool format_device = read_only ? false : true;
pmd = dm_pool_metadata_open(metadata_dev, block_size, format_device);
if (IS_ERR(pmd)) {
*error = "Error creating metadata object";
return (struct pool *)pmd;
}
pool = kmalloc(sizeof(*pool), GFP_KERNEL);
if (!pool) {
*error = "Error allocating memory for pool";
err_p = ERR_PTR(-ENOMEM);
goto bad_pool;
}
pool->pmd = pmd;
pool->sectors_per_block = block_size;
if (block_size & (block_size - 1))
pool->sectors_per_block_shift = -1;
else
pool->sectors_per_block_shift = __ffs(block_size);
pool->low_water_blocks = 0;
pool_features_init(&pool->pf);
pool->prison = dm_bio_prison_create(PRISON_CELLS);
if (!pool->prison) {
*error = "Error creating pool's bio prison";
err_p = ERR_PTR(-ENOMEM);
goto bad_prison;
}
pool->copier = dm_kcopyd_client_create(&dm_kcopyd_throttle);
if (IS_ERR(pool->copier)) {
r = PTR_ERR(pool->copier);
*error = "Error creating pool's kcopyd client";
err_p = ERR_PTR(r);
goto bad_kcopyd_client;
}
pool->wq = alloc_ordered_workqueue("dm-" DM_MSG_PREFIX, WQ_MEM_RECLAIM);
if (!pool->wq) {
*error = "Error creating pool's workqueue";
err_p = ERR_PTR(-ENOMEM);
goto bad_wq;
}
INIT_WORK(&pool->worker, do_worker);
INIT_DELAYED_WORK(&pool->waker, do_waker);
INIT_DELAYED_WORK(&pool->no_space_timeout, do_no_space_timeout);
spin_lock_init(&pool->lock);
bio_list_init(&pool->deferred_flush_bios);
INIT_LIST_HEAD(&pool->prepared_mappings);
INIT_LIST_HEAD(&pool->prepared_discards);
INIT_LIST_HEAD(&pool->active_thins);
pool->low_water_triggered = false;
pool->shared_read_ds = dm_deferred_set_create();
if (!pool->shared_read_ds) {
*error = "Error creating pool's shared read deferred set";
err_p = ERR_PTR(-ENOMEM);
goto bad_shared_read_ds;
}
pool->all_io_ds = dm_deferred_set_create();
if (!pool->all_io_ds) {
*error = "Error creating pool's all io deferred set";
err_p = ERR_PTR(-ENOMEM);
goto bad_all_io_ds;
}
pool->next_mapping = NULL;
pool->mapping_pool = mempool_create_slab_pool(MAPPING_POOL_SIZE,
_new_mapping_cache);
if (!pool->mapping_pool) {
*error = "Error creating pool's mapping mempool";
err_p = ERR_PTR(-ENOMEM);
goto bad_mapping_pool;
}
pool->ref_count = 1;
pool->last_commit_jiffies = jiffies;
pool->pool_md = pool_md;
pool->md_dev = metadata_dev;
__pool_table_insert(pool);
return pool;
bad_mapping_pool:
dm_deferred_set_destroy(pool->all_io_ds);
bad_all_io_ds:
dm_deferred_set_destroy(pool->shared_read_ds);
bad_shared_read_ds:
destroy_workqueue(pool->wq);
bad_wq:
dm_kcopyd_client_destroy(pool->copier);
bad_kcopyd_client:
dm_bio_prison_destroy(pool->prison);
bad_prison:
kfree(pool);
bad_pool:
if (dm_pool_metadata_close(pmd))
DMWARN("%s: dm_pool_metadata_close() failed.", __func__);
return err_p;
}
static void __pool_inc(struct pool *pool)
{
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
pool->ref_count++;
}
static void __pool_dec(struct pool *pool)
{
BUG_ON(!mutex_is_locked(&dm_thin_pool_table.mutex));
BUG_ON(!pool->ref_count);
if (!--pool->ref_count)
__pool_destroy(pool);
}
static struct pool *__pool_find(struct mapped_device *pool_md,
struct block_device *metadata_dev,
unsigned long block_size, int read_only,
char **error, int *created)
{
struct pool *pool = __pool_table_lookup_metadata_dev(metadata_dev);
if (pool) {
if (pool->pool_md != pool_md) {
*error = "metadata device already in use by a pool";
return ERR_PTR(-EBUSY);
}
__pool_inc(pool);
} else {
pool = __pool_table_lookup(pool_md);
if (pool) {
if (pool->md_dev != metadata_dev) {
*error = "different pool cannot replace a pool";
return ERR_PTR(-EINVAL);
}
__pool_inc(pool);
} else {
pool = pool_create(pool_md, metadata_dev, block_size, read_only, error);
*created = 1;
}
}
return pool;
}
static void pool_dtr(struct dm_target *ti)
{
struct pool_c *pt = ti->private;
mutex_lock(&dm_thin_pool_table.mutex);
unbind_control_target(pt->pool, ti);
__pool_dec(pt->pool);
dm_put_device(ti, pt->metadata_dev);
dm_put_device(ti, pt->data_dev);
kfree(pt);
mutex_unlock(&dm_thin_pool_table.mutex);
}
static int parse_pool_features(struct dm_arg_set *as, struct pool_features *pf,
struct dm_target *ti)
{
int r;
unsigned argc;
const char *arg_name;
static struct dm_arg _args[] = {
{0, 4, "Invalid number of pool feature arguments"},
};
if (!as->argc)
return 0;
r = dm_read_arg_group(_args, as, &argc, &ti->error);
if (r)
return -EINVAL;
while (argc && !r) {
arg_name = dm_shift_arg(as);
argc--;
if (!strcasecmp(arg_name, "skip_block_zeroing"))
pf->zero_new_blocks = false;
else if (!strcasecmp(arg_name, "ignore_discard"))
pf->discard_enabled = false;
else if (!strcasecmp(arg_name, "no_discard_passdown"))
pf->discard_passdown = false;
else if (!strcasecmp(arg_name, "read_only"))
pf->mode = PM_READ_ONLY;
else if (!strcasecmp(arg_name, "error_if_no_space"))
pf->error_if_no_space = true;
else {
ti->error = "Unrecognised pool feature requested";
r = -EINVAL;
break;
}
}
return r;
}
static void metadata_low_callback(void *context)
{
struct pool *pool = context;
DMWARN("%s: reached low water mark for metadata device: sending event.",
dm_device_name(pool->pool_md));
dm_table_event(pool->ti->table);
}
static sector_t get_dev_size(struct block_device *bdev)
{
return i_size_read(bdev->bd_inode) >> SECTOR_SHIFT;
}
static void warn_if_metadata_device_too_big(struct block_device *bdev)
{
sector_t metadata_dev_size = get_dev_size(bdev);
char buffer[BDEVNAME_SIZE];
if (metadata_dev_size > THIN_METADATA_MAX_SECTORS_WARNING)
DMWARN("Metadata device %s is larger than %u sectors: excess space will not be used.",
bdevname(bdev, buffer), THIN_METADATA_MAX_SECTORS);
}
static sector_t get_metadata_dev_size(struct block_device *bdev)
{
sector_t metadata_dev_size = get_dev_size(bdev);
if (metadata_dev_size > THIN_METADATA_MAX_SECTORS)
metadata_dev_size = THIN_METADATA_MAX_SECTORS;
return metadata_dev_size;
}
static dm_block_t get_metadata_dev_size_in_blocks(struct block_device *bdev)
{
sector_t metadata_dev_size = get_metadata_dev_size(bdev);
sector_div(metadata_dev_size, THIN_METADATA_BLOCK_SIZE);
return metadata_dev_size;
}
static dm_block_t calc_metadata_threshold(struct pool_c *pt)
{
dm_block_t quarter = get_metadata_dev_size_in_blocks(pt->metadata_dev->bdev) / 4;
return min((dm_block_t)1024ULL , quarter);
}
static int pool_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
int r, pool_created = 0;
struct pool_c *pt;
struct pool *pool;
struct pool_features pf;
struct dm_arg_set as;
struct dm_dev *data_dev;
unsigned long block_size;
dm_block_t low_water_blocks;
struct dm_dev *metadata_dev;
fmode_t metadata_mode;
mutex_lock(&dm_thin_pool_table.mutex);
if (argc < 4) {
ti->error = "Invalid argument count";
r = -EINVAL;
goto out_unlock;
}
as.argc = argc;
as.argv = argv;
pool_features_init(&pf);
dm_consume_args(&as, 4);
r = parse_pool_features(&as, &pf, ti);
if (r)
goto out_unlock;
metadata_mode = FMODE_READ | ((pf.mode == PM_READ_ONLY) ? 0 : FMODE_WRITE);
r = dm_get_device(ti, argv[0], metadata_mode, &metadata_dev);
if (r) {
ti->error = "Error opening metadata block device";
goto out_unlock;
}
warn_if_metadata_device_too_big(metadata_dev->bdev);
r = dm_get_device(ti, argv[1], FMODE_READ | FMODE_WRITE, &data_dev);
if (r) {
ti->error = "Error getting data device";
goto out_metadata;
}
if (kstrtoul(argv[2], 10, &block_size) || !block_size ||
block_size < DATA_DEV_BLOCK_SIZE_MIN_SECTORS ||
block_size > DATA_DEV_BLOCK_SIZE_MAX_SECTORS ||
block_size & (DATA_DEV_BLOCK_SIZE_MIN_SECTORS - 1)) {
ti->error = "Invalid block size";
r = -EINVAL;
goto out;
}
if (kstrtoull(argv[3], 10, (unsigned long long *)&low_water_blocks)) {
ti->error = "Invalid low water mark";
r = -EINVAL;
goto out;
}
pt = kzalloc(sizeof(*pt), GFP_KERNEL);
if (!pt) {
r = -ENOMEM;
goto out;
}
pool = __pool_find(dm_table_get_md(ti->table), metadata_dev->bdev,
block_size, pf.mode == PM_READ_ONLY, &ti->error, &pool_created);
if (IS_ERR(pool)) {
r = PTR_ERR(pool);
goto out_free_pt;
}
if (!pool_created && pf.discard_enabled != pool->pf.discard_enabled) {
ti->error = "Discard support cannot be disabled once enabled";
r = -EINVAL;
goto out_flags_changed;
}
pt->pool = pool;
pt->ti = ti;
pt->metadata_dev = metadata_dev;
pt->data_dev = data_dev;
pt->low_water_blocks = low_water_blocks;
pt->adjusted_pf = pt->requested_pf = pf;
ti->num_flush_bios = 1;
ti->discard_zeroes_data_unsupported = true;
if (pf.discard_enabled && pf.discard_passdown) {
ti->num_discard_bios = 1;
ti->discards_supported = true;
}
ti->private = pt;
r = dm_pool_register_metadata_threshold(pt->pool->pmd,
calc_metadata_threshold(pt),
metadata_low_callback,
pool);
if (r)
goto out_free_pt;
pt->callbacks.congested_fn = pool_is_congested;
dm_table_add_target_callbacks(ti->table, &pt->callbacks);
mutex_unlock(&dm_thin_pool_table.mutex);
return 0;
out_flags_changed:
__pool_dec(pool);
out_free_pt:
kfree(pt);
out:
dm_put_device(ti, data_dev);
out_metadata:
dm_put_device(ti, metadata_dev);
out_unlock:
mutex_unlock(&dm_thin_pool_table.mutex);
return r;
}
static int pool_map(struct dm_target *ti, struct bio *bio)
{
int r;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
bio->bi_bdev = pt->data_dev->bdev;
r = DM_MAPIO_REMAPPED;
spin_unlock_irqrestore(&pool->lock, flags);
return r;
}
static int maybe_resize_data_dev(struct dm_target *ti, bool *need_commit)
{
int r;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
sector_t data_size = ti->len;
dm_block_t sb_data_size;
*need_commit = false;
(void) sector_div(data_size, pool->sectors_per_block);
r = dm_pool_get_data_dev_size(pool->pmd, &sb_data_size);
if (r) {
DMERR("%s: failed to retrieve data device size",
dm_device_name(pool->pool_md));
return r;
}
if (data_size < sb_data_size) {
DMERR("%s: pool target (%llu blocks) too small: expected %llu",
dm_device_name(pool->pool_md),
(unsigned long long)data_size, sb_data_size);
return -EINVAL;
} else if (data_size > sb_data_size) {
if (dm_pool_metadata_needs_check(pool->pmd)) {
DMERR("%s: unable to grow the data device until repaired.",
dm_device_name(pool->pool_md));
return 0;
}
if (sb_data_size)
DMINFO("%s: growing the data device from %llu to %llu blocks",
dm_device_name(pool->pool_md),
sb_data_size, (unsigned long long)data_size);
r = dm_pool_resize_data_dev(pool->pmd, data_size);
if (r) {
metadata_operation_failed(pool, "dm_pool_resize_data_dev", r);
return r;
}
*need_commit = true;
}
return 0;
}
static int maybe_resize_metadata_dev(struct dm_target *ti, bool *need_commit)
{
int r;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
dm_block_t metadata_dev_size, sb_metadata_dev_size;
*need_commit = false;
metadata_dev_size = get_metadata_dev_size_in_blocks(pool->md_dev);
r = dm_pool_get_metadata_dev_size(pool->pmd, &sb_metadata_dev_size);
if (r) {
DMERR("%s: failed to retrieve metadata device size",
dm_device_name(pool->pool_md));
return r;
}
if (metadata_dev_size < sb_metadata_dev_size) {
DMERR("%s: metadata device (%llu blocks) too small: expected %llu",
dm_device_name(pool->pool_md),
metadata_dev_size, sb_metadata_dev_size);
return -EINVAL;
} else if (metadata_dev_size > sb_metadata_dev_size) {
if (dm_pool_metadata_needs_check(pool->pmd)) {
DMERR("%s: unable to grow the metadata device until repaired.",
dm_device_name(pool->pool_md));
return 0;
}
warn_if_metadata_device_too_big(pool->md_dev);
DMINFO("%s: growing the metadata device from %llu to %llu blocks",
dm_device_name(pool->pool_md),
sb_metadata_dev_size, metadata_dev_size);
r = dm_pool_resize_metadata_dev(pool->pmd, metadata_dev_size);
if (r) {
metadata_operation_failed(pool, "dm_pool_resize_metadata_dev", r);
return r;
}
*need_commit = true;
}
return 0;
}
static int pool_preresume(struct dm_target *ti)
{
int r;
bool need_commit1, need_commit2;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
r = bind_control_target(pool, ti);
if (r)
return r;
r = maybe_resize_data_dev(ti, &need_commit1);
if (r)
return r;
r = maybe_resize_metadata_dev(ti, &need_commit2);
if (r)
return r;
if (need_commit1 || need_commit2)
(void) commit(pool);
return 0;
}
static void pool_resume(struct dm_target *ti)
{
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
pool->low_water_triggered = false;
spin_unlock_irqrestore(&pool->lock, flags);
requeue_bios(pool);
do_waker(&pool->waker.work);
}
static void pool_postsuspend(struct dm_target *ti)
{
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
cancel_delayed_work(&pool->waker);
cancel_delayed_work(&pool->no_space_timeout);
flush_workqueue(pool->wq);
(void) commit(pool);
}
static int check_arg_count(unsigned argc, unsigned args_required)
{
if (argc != args_required) {
DMWARN("Message received with %u arguments instead of %u.",
argc, args_required);
return -EINVAL;
}
return 0;
}
static int read_dev_id(char *arg, dm_thin_id *dev_id, int warning)
{
if (!kstrtoull(arg, 10, (unsigned long long *)dev_id) &&
*dev_id <= MAX_DEV_ID)
return 0;
if (warning)
DMWARN("Message received with invalid device id: %s", arg);
return -EINVAL;
}
static int process_create_thin_mesg(unsigned argc, char **argv, struct pool *pool)
{
dm_thin_id dev_id;
int r;
r = check_arg_count(argc, 2);
if (r)
return r;
r = read_dev_id(argv[1], &dev_id, 1);
if (r)
return r;
r = dm_pool_create_thin(pool->pmd, dev_id);
if (r) {
DMWARN("Creation of new thinly-provisioned device with id %s failed.",
argv[1]);
return r;
}
return 0;
}
static int process_create_snap_mesg(unsigned argc, char **argv, struct pool *pool)
{
dm_thin_id dev_id;
dm_thin_id origin_dev_id;
int r;
r = check_arg_count(argc, 3);
if (r)
return r;
r = read_dev_id(argv[1], &dev_id, 1);
if (r)
return r;
r = read_dev_id(argv[2], &origin_dev_id, 1);
if (r)
return r;
r = dm_pool_create_snap(pool->pmd, dev_id, origin_dev_id);
if (r) {
DMWARN("Creation of new snapshot %s of device %s failed.",
argv[1], argv[2]);
return r;
}
return 0;
}
static int process_delete_mesg(unsigned argc, char **argv, struct pool *pool)
{
dm_thin_id dev_id;
int r;
r = check_arg_count(argc, 2);
if (r)
return r;
r = read_dev_id(argv[1], &dev_id, 1);
if (r)
return r;
r = dm_pool_delete_thin_device(pool->pmd, dev_id);
if (r)
DMWARN("Deletion of thin device %s failed.", argv[1]);
return r;
}
static int process_set_transaction_id_mesg(unsigned argc, char **argv, struct pool *pool)
{
dm_thin_id old_id, new_id;
int r;
r = check_arg_count(argc, 3);
if (r)
return r;
if (kstrtoull(argv[1], 10, (unsigned long long *)&old_id)) {
DMWARN("set_transaction_id message: Unrecognised id %s.", argv[1]);
return -EINVAL;
}
if (kstrtoull(argv[2], 10, (unsigned long long *)&new_id)) {
DMWARN("set_transaction_id message: Unrecognised new id %s.", argv[2]);
return -EINVAL;
}
r = dm_pool_set_metadata_transaction_id(pool->pmd, old_id, new_id);
if (r) {
DMWARN("Failed to change transaction id from %s to %s.",
argv[1], argv[2]);
return r;
}
return 0;
}
static int process_reserve_metadata_snap_mesg(unsigned argc, char **argv, struct pool *pool)
{
int r;
r = check_arg_count(argc, 1);
if (r)
return r;
(void) commit(pool);
r = dm_pool_reserve_metadata_snap(pool->pmd);
if (r)
DMWARN("reserve_metadata_snap message failed.");
return r;
}
static int process_release_metadata_snap_mesg(unsigned argc, char **argv, struct pool *pool)
{
int r;
r = check_arg_count(argc, 1);
if (r)
return r;
r = dm_pool_release_metadata_snap(pool->pmd);
if (r)
DMWARN("release_metadata_snap message failed.");
return r;
}
static int pool_message(struct dm_target *ti, unsigned argc, char **argv)
{
int r = -EINVAL;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
if (!strcasecmp(argv[0], "create_thin"))
r = process_create_thin_mesg(argc, argv, pool);
else if (!strcasecmp(argv[0], "create_snap"))
r = process_create_snap_mesg(argc, argv, pool);
else if (!strcasecmp(argv[0], "delete"))
r = process_delete_mesg(argc, argv, pool);
else if (!strcasecmp(argv[0], "set_transaction_id"))
r = process_set_transaction_id_mesg(argc, argv, pool);
else if (!strcasecmp(argv[0], "reserve_metadata_snap"))
r = process_reserve_metadata_snap_mesg(argc, argv, pool);
else if (!strcasecmp(argv[0], "release_metadata_snap"))
r = process_release_metadata_snap_mesg(argc, argv, pool);
else
DMWARN("Unrecognised thin pool target message received: %s", argv[0]);
if (!r)
(void) commit(pool);
return r;
}
static void emit_flags(struct pool_features *pf, char *result,
unsigned sz, unsigned maxlen)
{
unsigned count = !pf->zero_new_blocks + !pf->discard_enabled +
!pf->discard_passdown + (pf->mode == PM_READ_ONLY) +
pf->error_if_no_space;
DMEMIT("%u ", count);
if (!pf->zero_new_blocks)
DMEMIT("skip_block_zeroing ");
if (!pf->discard_enabled)
DMEMIT("ignore_discard ");
if (!pf->discard_passdown)
DMEMIT("no_discard_passdown ");
if (pf->mode == PM_READ_ONLY)
DMEMIT("read_only ");
if (pf->error_if_no_space)
DMEMIT("error_if_no_space ");
}
static void pool_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
int r;
unsigned sz = 0;
uint64_t transaction_id;
dm_block_t nr_free_blocks_data;
dm_block_t nr_free_blocks_metadata;
dm_block_t nr_blocks_data;
dm_block_t nr_blocks_metadata;
dm_block_t held_root;
char buf[BDEVNAME_SIZE];
char buf2[BDEVNAME_SIZE];
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
switch (type) {
case STATUSTYPE_INFO:
if (get_pool_mode(pool) == PM_FAIL) {
DMEMIT("Fail");
break;
}
if (!(status_flags & DM_STATUS_NOFLUSH_FLAG) && !dm_suspended(ti))
(void) commit(pool);
r = dm_pool_get_metadata_transaction_id(pool->pmd, &transaction_id);
if (r) {
DMERR("%s: dm_pool_get_metadata_transaction_id returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
r = dm_pool_get_free_metadata_block_count(pool->pmd, &nr_free_blocks_metadata);
if (r) {
DMERR("%s: dm_pool_get_free_metadata_block_count returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
r = dm_pool_get_metadata_dev_size(pool->pmd, &nr_blocks_metadata);
if (r) {
DMERR("%s: dm_pool_get_metadata_dev_size returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
r = dm_pool_get_free_block_count(pool->pmd, &nr_free_blocks_data);
if (r) {
DMERR("%s: dm_pool_get_free_block_count returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
r = dm_pool_get_data_dev_size(pool->pmd, &nr_blocks_data);
if (r) {
DMERR("%s: dm_pool_get_data_dev_size returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
r = dm_pool_get_metadata_snap(pool->pmd, &held_root);
if (r) {
DMERR("%s: dm_pool_get_metadata_snap returned %d",
dm_device_name(pool->pool_md), r);
goto err;
}
DMEMIT("%llu %llu/%llu %llu/%llu ",
(unsigned long long)transaction_id,
(unsigned long long)(nr_blocks_metadata - nr_free_blocks_metadata),
(unsigned long long)nr_blocks_metadata,
(unsigned long long)(nr_blocks_data - nr_free_blocks_data),
(unsigned long long)nr_blocks_data);
if (held_root)
DMEMIT("%llu ", held_root);
else
DMEMIT("- ");
if (pool->pf.mode == PM_OUT_OF_DATA_SPACE)
DMEMIT("out_of_data_space ");
else if (pool->pf.mode == PM_READ_ONLY)
DMEMIT("ro ");
else
DMEMIT("rw ");
if (!pool->pf.discard_enabled)
DMEMIT("ignore_discard ");
else if (pool->pf.discard_passdown)
DMEMIT("discard_passdown ");
else
DMEMIT("no_discard_passdown ");
if (pool->pf.error_if_no_space)
DMEMIT("error_if_no_space ");
else
DMEMIT("queue_if_no_space ");
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %s %lu %llu ",
format_dev_t(buf, pt->metadata_dev->bdev->bd_dev),
format_dev_t(buf2, pt->data_dev->bdev->bd_dev),
(unsigned long)pool->sectors_per_block,
(unsigned long long)pt->low_water_blocks);
emit_flags(&pt->requested_pf, result, sz, maxlen);
break;
}
return;
err:
DMEMIT("Error");
}
static int pool_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
struct pool_c *pt = ti->private;
return fn(ti, pt->data_dev, 0, ti->len, data);
}
static int pool_merge(struct dm_target *ti, struct bvec_merge_data *bvm,
struct bio_vec *biovec, int max_size)
{
struct pool_c *pt = ti->private;
struct request_queue *q = bdev_get_queue(pt->data_dev->bdev);
if (!q->merge_bvec_fn)
return max_size;
bvm->bi_bdev = pt->data_dev->bdev;
return min(max_size, q->merge_bvec_fn(q, bvm, biovec));
}
static void set_discard_limits(struct pool_c *pt, struct queue_limits *limits)
{
struct pool *pool = pt->pool;
struct queue_limits *data_limits;
limits->max_discard_sectors = pool->sectors_per_block;
if (pt->adjusted_pf.discard_passdown) {
data_limits = &bdev_get_queue(pt->data_dev->bdev)->limits;
limits->discard_granularity = max(data_limits->discard_granularity,
pool->sectors_per_block << SECTOR_SHIFT);
} else
limits->discard_granularity = pool->sectors_per_block << SECTOR_SHIFT;
}
static void pool_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
uint64_t io_opt_sectors = limits->io_opt >> SECTOR_SHIFT;
if (io_opt_sectors < pool->sectors_per_block ||
do_div(io_opt_sectors, pool->sectors_per_block)) {
blk_limits_io_min(limits, pool->sectors_per_block << SECTOR_SHIFT);
blk_limits_io_opt(limits, pool->sectors_per_block << SECTOR_SHIFT);
}
if (!pt->adjusted_pf.discard_enabled) {
limits->discard_granularity = 0;
return;
}
disable_passdown_if_not_supported(pt);
set_discard_limits(pt, limits);
}
static void thin_get(struct thin_c *tc)
{
atomic_inc(&tc->refcount);
}
static void thin_put(struct thin_c *tc)
{
if (atomic_dec_and_test(&tc->refcount))
complete(&tc->can_destroy);
}
static void thin_dtr(struct dm_target *ti)
{
struct thin_c *tc = ti->private;
unsigned long flags;
thin_put(tc);
wait_for_completion(&tc->can_destroy);
spin_lock_irqsave(&tc->pool->lock, flags);
list_del_rcu(&tc->list);
spin_unlock_irqrestore(&tc->pool->lock, flags);
synchronize_rcu();
mutex_lock(&dm_thin_pool_table.mutex);
__pool_dec(tc->pool);
dm_pool_close_thin_device(tc->td);
dm_put_device(ti, tc->pool_dev);
if (tc->origin_dev)
dm_put_device(ti, tc->origin_dev);
kfree(tc);
mutex_unlock(&dm_thin_pool_table.mutex);
}
static int thin_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
int r;
struct thin_c *tc;
struct dm_dev *pool_dev, *origin_dev;
struct mapped_device *pool_md;
unsigned long flags;
mutex_lock(&dm_thin_pool_table.mutex);
if (argc != 2 && argc != 3) {
ti->error = "Invalid argument count";
r = -EINVAL;
goto out_unlock;
}
tc = ti->private = kzalloc(sizeof(*tc), GFP_KERNEL);
if (!tc) {
ti->error = "Out of memory";
r = -ENOMEM;
goto out_unlock;
}
spin_lock_init(&tc->lock);
bio_list_init(&tc->deferred_bio_list);
bio_list_init(&tc->retry_on_resume_list);
tc->sort_bio_list = RB_ROOT;
if (argc == 3) {
r = dm_get_device(ti, argv[2], FMODE_READ, &origin_dev);
if (r) {
ti->error = "Error opening origin device";
goto bad_origin_dev;
}
tc->origin_dev = origin_dev;
}
r = dm_get_device(ti, argv[0], dm_table_get_mode(ti->table), &pool_dev);
if (r) {
ti->error = "Error opening pool device";
goto bad_pool_dev;
}
tc->pool_dev = pool_dev;
if (read_dev_id(argv[1], (unsigned long long *)&tc->dev_id, 0)) {
ti->error = "Invalid device id";
r = -EINVAL;
goto bad_common;
}
pool_md = dm_get_md(tc->pool_dev->bdev->bd_dev);
if (!pool_md) {
ti->error = "Couldn't get pool mapped device";
r = -EINVAL;
goto bad_common;
}
tc->pool = __pool_table_lookup(pool_md);
if (!tc->pool) {
ti->error = "Couldn't find pool object";
r = -EINVAL;
goto bad_pool_lookup;
}
__pool_inc(tc->pool);
if (get_pool_mode(tc->pool) == PM_FAIL) {
ti->error = "Couldn't open thin device, Pool is in fail mode";
r = -EINVAL;
goto bad_thin_open;
}
r = dm_pool_open_thin_device(tc->pool->pmd, tc->dev_id, &tc->td);
if (r) {
ti->error = "Couldn't open thin internal device";
goto bad_thin_open;
}
r = dm_set_target_max_io_len(ti, tc->pool->sectors_per_block);
if (r)
goto bad_target_max_io_len;
ti->num_flush_bios = 1;
ti->flush_supported = true;
ti->per_bio_data_size = sizeof(struct dm_thin_endio_hook);
ti->discard_zeroes_data_unsupported = true;
if (tc->pool->pf.discard_enabled) {
ti->discards_supported = true;
ti->num_discard_bios = 1;
ti->split_discard_bios = true;
}
dm_put(pool_md);
mutex_unlock(&dm_thin_pool_table.mutex);
atomic_set(&tc->refcount, 1);
init_completion(&tc->can_destroy);
spin_lock_irqsave(&tc->pool->lock, flags);
list_add_tail_rcu(&tc->list, &tc->pool->active_thins);
spin_unlock_irqrestore(&tc->pool->lock, flags);
synchronize_rcu();
return 0;
bad_target_max_io_len:
dm_pool_close_thin_device(tc->td);
bad_thin_open:
__pool_dec(tc->pool);
bad_pool_lookup:
dm_put(pool_md);
bad_common:
dm_put_device(ti, tc->pool_dev);
bad_pool_dev:
if (tc->origin_dev)
dm_put_device(ti, tc->origin_dev);
bad_origin_dev:
kfree(tc);
out_unlock:
mutex_unlock(&dm_thin_pool_table.mutex);
return r;
}
static int thin_map(struct dm_target *ti, struct bio *bio)
{
bio->bi_iter.bi_sector = dm_target_offset(ti, bio->bi_iter.bi_sector);
return thin_bio_map(ti, bio);
}
static int thin_endio(struct dm_target *ti, struct bio *bio, int err)
{
unsigned long flags;
struct dm_thin_endio_hook *h = dm_per_bio_data(bio, sizeof(struct dm_thin_endio_hook));
struct list_head work;
struct dm_thin_new_mapping *m, *tmp;
struct pool *pool = h->tc->pool;
if (h->shared_read_entry) {
INIT_LIST_HEAD(&work);
dm_deferred_entry_dec(h->shared_read_entry, &work);
spin_lock_irqsave(&pool->lock, flags);
list_for_each_entry_safe(m, tmp, &work, list) {
list_del(&m->list);
__complete_mapping_preparation(m);
}
spin_unlock_irqrestore(&pool->lock, flags);
}
if (h->all_io_entry) {
INIT_LIST_HEAD(&work);
dm_deferred_entry_dec(h->all_io_entry, &work);
if (!list_empty(&work)) {
spin_lock_irqsave(&pool->lock, flags);
list_for_each_entry_safe(m, tmp, &work, list)
list_add_tail(&m->list, &pool->prepared_discards);
spin_unlock_irqrestore(&pool->lock, flags);
wake_worker(pool);
}
}
return 0;
}
static void thin_presuspend(struct dm_target *ti)
{
struct thin_c *tc = ti->private;
if (dm_noflush_suspending(ti))
noflush_work(tc, do_noflush_start);
}
static void thin_postsuspend(struct dm_target *ti)
{
struct thin_c *tc = ti->private;
noflush_work(tc, do_noflush_stop);
}
static int thin_preresume(struct dm_target *ti)
{
struct thin_c *tc = ti->private;
if (tc->origin_dev)
tc->origin_size = get_dev_size(tc->origin_dev->bdev);
return 0;
}
static void thin_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
int r;
ssize_t sz = 0;
dm_block_t mapped, highest;
char buf[BDEVNAME_SIZE];
struct thin_c *tc = ti->private;
if (get_pool_mode(tc->pool) == PM_FAIL) {
DMEMIT("Fail");
return;
}
if (!tc->td)
DMEMIT("-");
else {
switch (type) {
case STATUSTYPE_INFO:
r = dm_thin_get_mapped_count(tc->td, &mapped);
if (r) {
DMERR("dm_thin_get_mapped_count returned %d", r);
goto err;
}
r = dm_thin_get_highest_mapped_block(tc->td, &highest);
if (r < 0) {
DMERR("dm_thin_get_highest_mapped_block returned %d", r);
goto err;
}
DMEMIT("%llu ", mapped * tc->pool->sectors_per_block);
if (r)
DMEMIT("%llu", ((highest + 1) *
tc->pool->sectors_per_block) - 1);
else
DMEMIT("-");
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %lu",
format_dev_t(buf, tc->pool_dev->bdev->bd_dev),
(unsigned long) tc->dev_id);
if (tc->origin_dev)
DMEMIT(" %s", format_dev_t(buf, tc->origin_dev->bdev->bd_dev));
break;
}
}
return;
err:
DMEMIT("Error");
}
static int thin_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
sector_t blocks;
struct thin_c *tc = ti->private;
struct pool *pool = tc->pool;
if (!pool->ti)
return 0;
blocks = pool->ti->len;
(void) sector_div(blocks, pool->sectors_per_block);
if (blocks)
return fn(ti, tc->pool_dev, 0, pool->sectors_per_block * blocks, data);
return 0;
}
static int __init dm_thin_init(void)
{
int r;
pool_table_init();
r = dm_register_target(&thin_target);
if (r)
return r;
r = dm_register_target(&pool_target);
if (r)
goto bad_pool_target;
r = -ENOMEM;
_new_mapping_cache = KMEM_CACHE(dm_thin_new_mapping, 0);
if (!_new_mapping_cache)
goto bad_new_mapping_cache;
return 0;
bad_new_mapping_cache:
dm_unregister_target(&pool_target);
bad_pool_target:
dm_unregister_target(&thin_target);
return r;
}
static void dm_thin_exit(void)
{
dm_unregister_target(&thin_target);
dm_unregister_target(&pool_target);
kmem_cache_destroy(_new_mapping_cache);
}
