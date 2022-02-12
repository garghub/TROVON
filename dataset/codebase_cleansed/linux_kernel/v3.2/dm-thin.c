static uint32_t calc_nr_buckets(unsigned nr_cells)
{
uint32_t n = 128;
nr_cells /= 4;
nr_cells = min(nr_cells, 8192u);
while (n < nr_cells)
n <<= 1;
return n;
}
static struct bio_prison *prison_create(unsigned nr_cells)
{
unsigned i;
uint32_t nr_buckets = calc_nr_buckets(nr_cells);
size_t len = sizeof(struct bio_prison) +
(sizeof(struct hlist_head) * nr_buckets);
struct bio_prison *prison = kmalloc(len, GFP_KERNEL);
if (!prison)
return NULL;
spin_lock_init(&prison->lock);
prison->cell_pool = mempool_create_kmalloc_pool(nr_cells,
sizeof(struct cell));
if (!prison->cell_pool) {
kfree(prison);
return NULL;
}
prison->nr_buckets = nr_buckets;
prison->hash_mask = nr_buckets - 1;
prison->cells = (struct hlist_head *) (prison + 1);
for (i = 0; i < nr_buckets; i++)
INIT_HLIST_HEAD(prison->cells + i);
return prison;
}
static void prison_destroy(struct bio_prison *prison)
{
mempool_destroy(prison->cell_pool);
kfree(prison);
}
static uint32_t hash_key(struct bio_prison *prison, struct cell_key *key)
{
const unsigned long BIG_PRIME = 4294967291UL;
uint64_t hash = key->block * BIG_PRIME;
return (uint32_t) (hash & prison->hash_mask);
}
static int keys_equal(struct cell_key *lhs, struct cell_key *rhs)
{
return (lhs->virtual == rhs->virtual) &&
(lhs->dev == rhs->dev) &&
(lhs->block == rhs->block);
}
static struct cell *__search_bucket(struct hlist_head *bucket,
struct cell_key *key)
{
struct cell *cell;
struct hlist_node *tmp;
hlist_for_each_entry(cell, tmp, bucket, list)
if (keys_equal(&cell->key, key))
return cell;
return NULL;
}
static int bio_detain(struct bio_prison *prison, struct cell_key *key,
struct bio *inmate, struct cell **ref)
{
int r;
unsigned long flags;
uint32_t hash = hash_key(prison, key);
struct cell *uninitialized_var(cell), *cell2 = NULL;
BUG_ON(hash > prison->nr_buckets);
spin_lock_irqsave(&prison->lock, flags);
cell = __search_bucket(prison->cells + hash, key);
if (!cell) {
spin_unlock_irqrestore(&prison->lock, flags);
cell2 = mempool_alloc(prison->cell_pool, GFP_NOIO);
spin_lock_irqsave(&prison->lock, flags);
cell = __search_bucket(prison->cells + hash, key);
if (!cell) {
cell = cell2;
cell2 = NULL;
cell->prison = prison;
memcpy(&cell->key, key, sizeof(cell->key));
cell->count = 0;
bio_list_init(&cell->bios);
hlist_add_head(&cell->list, prison->cells + hash);
}
}
r = cell->count++;
bio_list_add(&cell->bios, inmate);
spin_unlock_irqrestore(&prison->lock, flags);
if (cell2)
mempool_free(cell2, prison->cell_pool);
*ref = cell;
return r;
}
static void __cell_release(struct cell *cell, struct bio_list *inmates)
{
struct bio_prison *prison = cell->prison;
hlist_del(&cell->list);
if (inmates)
bio_list_merge(inmates, &cell->bios);
mempool_free(cell, prison->cell_pool);
}
static void cell_release(struct cell *cell, struct bio_list *bios)
{
unsigned long flags;
struct bio_prison *prison = cell->prison;
spin_lock_irqsave(&prison->lock, flags);
__cell_release(cell, bios);
spin_unlock_irqrestore(&prison->lock, flags);
}
static void cell_release_singleton(struct cell *cell, struct bio *bio)
{
struct bio_prison *prison = cell->prison;
struct bio_list bios;
struct bio *b;
unsigned long flags;
bio_list_init(&bios);
spin_lock_irqsave(&prison->lock, flags);
__cell_release(cell, &bios);
spin_unlock_irqrestore(&prison->lock, flags);
b = bio_list_pop(&bios);
BUG_ON(b != bio);
BUG_ON(!bio_list_empty(&bios));
}
static void cell_error(struct cell *cell)
{
struct bio_prison *prison = cell->prison;
struct bio_list bios;
struct bio *bio;
unsigned long flags;
bio_list_init(&bios);
spin_lock_irqsave(&prison->lock, flags);
__cell_release(cell, &bios);
spin_unlock_irqrestore(&prison->lock, flags);
while ((bio = bio_list_pop(&bios)))
bio_io_error(bio);
}
static void ds_init(struct deferred_set *ds)
{
int i;
spin_lock_init(&ds->lock);
ds->current_entry = 0;
ds->sweeper = 0;
for (i = 0; i < DEFERRED_SET_SIZE; i++) {
ds->entries[i].ds = ds;
ds->entries[i].count = 0;
INIT_LIST_HEAD(&ds->entries[i].work_items);
}
}
static struct deferred_entry *ds_inc(struct deferred_set *ds)
{
unsigned long flags;
struct deferred_entry *entry;
spin_lock_irqsave(&ds->lock, flags);
entry = ds->entries + ds->current_entry;
entry->count++;
spin_unlock_irqrestore(&ds->lock, flags);
return entry;
}
static unsigned ds_next(unsigned index)
{
return (index + 1) % DEFERRED_SET_SIZE;
}
static void __sweep(struct deferred_set *ds, struct list_head *head)
{
while ((ds->sweeper != ds->current_entry) &&
!ds->entries[ds->sweeper].count) {
list_splice_init(&ds->entries[ds->sweeper].work_items, head);
ds->sweeper = ds_next(ds->sweeper);
}
if ((ds->sweeper == ds->current_entry) && !ds->entries[ds->sweeper].count)
list_splice_init(&ds->entries[ds->sweeper].work_items, head);
}
static void ds_dec(struct deferred_entry *entry, struct list_head *head)
{
unsigned long flags;
spin_lock_irqsave(&entry->ds->lock, flags);
BUG_ON(!entry->count);
--entry->count;
__sweep(entry->ds, head);
spin_unlock_irqrestore(&entry->ds->lock, flags);
}
static int ds_add_work(struct deferred_set *ds, struct list_head *work)
{
int r = 1;
unsigned long flags;
unsigned next_entry;
spin_lock_irqsave(&ds->lock, flags);
if ((ds->sweeper == ds->current_entry) &&
!ds->entries[ds->current_entry].count)
r = 0;
else {
list_add(work, &ds->entries[ds->current_entry].work_items);
next_entry = ds_next(ds->current_entry);
if (!ds->entries[next_entry].count)
ds->current_entry = next_entry;
}
spin_unlock_irqrestore(&ds->lock, flags);
return r;
}
static void build_data_key(struct dm_thin_device *td,
dm_block_t b, struct cell_key *key)
{
key->virtual = 0;
key->dev = dm_thin_dev_id(td);
key->block = b;
}
static void build_virtual_key(struct dm_thin_device *td, dm_block_t b,
struct cell_key *key)
{
key->virtual = 1;
key->dev = dm_thin_dev_id(td);
key->block = b;
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
static void __requeue_bio_list(struct thin_c *tc, struct bio_list *master)
{
struct bio *bio;
struct bio_list bios;
bio_list_init(&bios);
bio_list_merge(&bios, master);
bio_list_init(master);
while ((bio = bio_list_pop(&bios))) {
if (dm_get_mapinfo(bio)->ptr == tc)
bio_endio(bio, DM_ENDIO_REQUEUE);
else
bio_list_add(master, bio);
}
}
static void requeue_io(struct thin_c *tc)
{
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
__requeue_bio_list(tc, &pool->deferred_bios);
__requeue_bio_list(tc, &pool->retry_on_resume_list);
spin_unlock_irqrestore(&pool->lock, flags);
}
static dm_block_t get_bio_block(struct thin_c *tc, struct bio *bio)
{
return bio->bi_sector >> tc->pool->block_shift;
}
static void remap(struct thin_c *tc, struct bio *bio, dm_block_t block)
{
struct pool *pool = tc->pool;
bio->bi_bdev = tc->pool_dev->bdev;
bio->bi_sector = (block << pool->block_shift) +
(bio->bi_sector & pool->offset_mask);
}
static void remap_and_issue(struct thin_c *tc, struct bio *bio,
dm_block_t block)
{
struct pool *pool = tc->pool;
unsigned long flags;
remap(tc, bio, block);
if (bio->bi_rw & (REQ_FLUSH | REQ_FUA)) {
spin_lock_irqsave(&pool->lock, flags);
bio_list_add(&pool->deferred_flush_bios, bio);
spin_unlock_irqrestore(&pool->lock, flags);
} else
generic_make_request(bio);
}
static void wake_worker(struct pool *pool)
{
queue_work(pool->wq, &pool->worker);
}
static void __maybe_add_mapping(struct new_mapping *m)
{
struct pool *pool = m->tc->pool;
if (list_empty(&m->list) && m->prepared) {
list_add(&m->list, &pool->prepared_mappings);
wake_worker(pool);
}
}
static void copy_complete(int read_err, unsigned long write_err, void *context)
{
unsigned long flags;
struct new_mapping *m = context;
struct pool *pool = m->tc->pool;
m->err = read_err || write_err ? -EIO : 0;
spin_lock_irqsave(&pool->lock, flags);
m->prepared = 1;
__maybe_add_mapping(m);
spin_unlock_irqrestore(&pool->lock, flags);
}
static void overwrite_endio(struct bio *bio, int err)
{
unsigned long flags;
struct new_mapping *m = dm_get_mapinfo(bio)->ptr;
struct pool *pool = m->tc->pool;
m->err = err;
spin_lock_irqsave(&pool->lock, flags);
m->prepared = 1;
__maybe_add_mapping(m);
spin_unlock_irqrestore(&pool->lock, flags);
}
static void shared_read_endio(struct bio *bio, int err)
{
struct list_head mappings;
struct new_mapping *m, *tmp;
struct endio_hook *h = dm_get_mapinfo(bio)->ptr;
unsigned long flags;
struct pool *pool = h->tc->pool;
bio->bi_end_io = h->saved_bi_end_io;
bio_endio(bio, err);
INIT_LIST_HEAD(&mappings);
ds_dec(h->entry, &mappings);
spin_lock_irqsave(&pool->lock, flags);
list_for_each_entry_safe(m, tmp, &mappings, list) {
list_del(&m->list);
INIT_LIST_HEAD(&m->list);
__maybe_add_mapping(m);
}
spin_unlock_irqrestore(&pool->lock, flags);
mempool_free(h, pool->endio_hook_pool);
}
static void cell_defer(struct thin_c *tc, struct cell *cell,
dm_block_t data_block)
{
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
cell_release(cell, &pool->deferred_bios);
spin_unlock_irqrestore(&tc->pool->lock, flags);
wake_worker(pool);
}
static void cell_defer_except(struct thin_c *tc, struct cell *cell,
struct bio *exception)
{
struct bio_list bios;
struct bio *bio;
struct pool *pool = tc->pool;
unsigned long flags;
bio_list_init(&bios);
cell_release(cell, &bios);
spin_lock_irqsave(&pool->lock, flags);
while ((bio = bio_list_pop(&bios)))
if (bio != exception)
bio_list_add(&pool->deferred_bios, bio);
spin_unlock_irqrestore(&pool->lock, flags);
wake_worker(pool);
}
static void process_prepared_mapping(struct new_mapping *m)
{
struct thin_c *tc = m->tc;
struct bio *bio;
int r;
bio = m->bio;
if (bio)
bio->bi_end_io = m->saved_bi_end_io;
if (m->err) {
cell_error(m->cell);
return;
}
r = dm_thin_insert_block(tc->td, m->virt_block, m->data_block);
if (r) {
DMERR("dm_thin_insert_block() failed");
cell_error(m->cell);
return;
}
if (bio) {
cell_defer_except(tc, m->cell, bio);
bio_endio(bio, 0);
} else
cell_defer(tc, m->cell, m->data_block);
list_del(&m->list);
mempool_free(m, tc->pool->mapping_pool);
}
static void process_prepared_mappings(struct pool *pool)
{
unsigned long flags;
struct list_head maps;
struct new_mapping *m, *tmp;
INIT_LIST_HEAD(&maps);
spin_lock_irqsave(&pool->lock, flags);
list_splice_init(&pool->prepared_mappings, &maps);
spin_unlock_irqrestore(&pool->lock, flags);
list_for_each_entry_safe(m, tmp, &maps, list)
process_prepared_mapping(m);
}
static int io_overwrites_block(struct pool *pool, struct bio *bio)
{
return ((bio_data_dir(bio) == WRITE) &&
!(bio->bi_sector & pool->offset_mask)) &&
(bio->bi_size == (pool->sectors_per_block << SECTOR_SHIFT));
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
static struct new_mapping *get_next_mapping(struct pool *pool)
{
struct new_mapping *r = pool->next_mapping;
BUG_ON(!pool->next_mapping);
pool->next_mapping = NULL;
return r;
}
static void schedule_copy(struct thin_c *tc, dm_block_t virt_block,
dm_block_t data_origin, dm_block_t data_dest,
struct cell *cell, struct bio *bio)
{
int r;
struct pool *pool = tc->pool;
struct new_mapping *m = get_next_mapping(pool);
INIT_LIST_HEAD(&m->list);
m->prepared = 0;
m->tc = tc;
m->virt_block = virt_block;
m->data_block = data_dest;
m->cell = cell;
m->err = 0;
m->bio = NULL;
ds_add_work(&pool->ds, &m->list);
if (io_overwrites_block(pool, bio)) {
m->bio = bio;
save_and_set_endio(bio, &m->saved_bi_end_io, overwrite_endio);
dm_get_mapinfo(bio)->ptr = m;
remap_and_issue(tc, bio, data_dest);
} else {
struct dm_io_region from, to;
from.bdev = tc->pool_dev->bdev;
from.sector = data_origin * pool->sectors_per_block;
from.count = pool->sectors_per_block;
to.bdev = tc->pool_dev->bdev;
to.sector = data_dest * pool->sectors_per_block;
to.count = pool->sectors_per_block;
r = dm_kcopyd_copy(pool->copier, &from, 1, &to,
0, copy_complete, m);
if (r < 0) {
mempool_free(m, pool->mapping_pool);
DMERR("dm_kcopyd_copy() failed");
cell_error(cell);
}
}
}
static void schedule_zero(struct thin_c *tc, dm_block_t virt_block,
dm_block_t data_block, struct cell *cell,
struct bio *bio)
{
struct pool *pool = tc->pool;
struct new_mapping *m = get_next_mapping(pool);
INIT_LIST_HEAD(&m->list);
m->prepared = 0;
m->tc = tc;
m->virt_block = virt_block;
m->data_block = data_block;
m->cell = cell;
m->err = 0;
m->bio = NULL;
if (!pool->zero_new_blocks)
process_prepared_mapping(m);
else if (io_overwrites_block(pool, bio)) {
m->bio = bio;
save_and_set_endio(bio, &m->saved_bi_end_io, overwrite_endio);
dm_get_mapinfo(bio)->ptr = m;
remap_and_issue(tc, bio, data_block);
} else {
int r;
struct dm_io_region to;
to.bdev = tc->pool_dev->bdev;
to.sector = data_block * pool->sectors_per_block;
to.count = pool->sectors_per_block;
r = dm_kcopyd_zero(pool->copier, 1, &to, 0, copy_complete, m);
if (r < 0) {
mempool_free(m, pool->mapping_pool);
DMERR("dm_kcopyd_zero() failed");
cell_error(cell);
}
}
}
static int alloc_data_block(struct thin_c *tc, dm_block_t *result)
{
int r;
dm_block_t free_blocks;
unsigned long flags;
struct pool *pool = tc->pool;
r = dm_pool_get_free_block_count(pool->pmd, &free_blocks);
if (r)
return r;
if (free_blocks <= pool->low_water_blocks && !pool->low_water_triggered) {
DMWARN("%s: reached low water mark, sending event.",
dm_device_name(pool->pool_md));
spin_lock_irqsave(&pool->lock, flags);
pool->low_water_triggered = 1;
spin_unlock_irqrestore(&pool->lock, flags);
dm_table_event(pool->ti->table);
}
if (!free_blocks) {
if (pool->no_free_space)
return -ENOSPC;
else {
r = dm_pool_commit_metadata(pool->pmd);
if (r) {
DMERR("%s: dm_pool_commit_metadata() failed, error = %d",
__func__, r);
return r;
}
r = dm_pool_get_free_block_count(pool->pmd, &free_blocks);
if (r)
return r;
if (!free_blocks) {
DMWARN("%s: no free space available.",
dm_device_name(pool->pool_md));
spin_lock_irqsave(&pool->lock, flags);
pool->no_free_space = 1;
spin_unlock_irqrestore(&pool->lock, flags);
return -ENOSPC;
}
}
}
r = dm_pool_alloc_data_block(pool->pmd, result);
if (r)
return r;
return 0;
}
static void retry_on_resume(struct bio *bio)
{
struct thin_c *tc = dm_get_mapinfo(bio)->ptr;
struct pool *pool = tc->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
bio_list_add(&pool->retry_on_resume_list, bio);
spin_unlock_irqrestore(&pool->lock, flags);
}
static void no_space(struct cell *cell)
{
struct bio *bio;
struct bio_list bios;
bio_list_init(&bios);
cell_release(cell, &bios);
while ((bio = bio_list_pop(&bios)))
retry_on_resume(bio);
}
static void break_sharing(struct thin_c *tc, struct bio *bio, dm_block_t block,
struct cell_key *key,
struct dm_thin_lookup_result *lookup_result,
struct cell *cell)
{
int r;
dm_block_t data_block;
r = alloc_data_block(tc, &data_block);
switch (r) {
case 0:
schedule_copy(tc, block, lookup_result->block,
data_block, cell, bio);
break;
case -ENOSPC:
no_space(cell);
break;
default:
DMERR("%s: alloc_data_block() failed, error = %d", __func__, r);
cell_error(cell);
break;
}
}
static void process_shared_bio(struct thin_c *tc, struct bio *bio,
dm_block_t block,
struct dm_thin_lookup_result *lookup_result)
{
struct cell *cell;
struct pool *pool = tc->pool;
struct cell_key key;
build_data_key(tc->td, lookup_result->block, &key);
if (bio_detain(pool->prison, &key, bio, &cell))
return;
if (bio_data_dir(bio) == WRITE)
break_sharing(tc, bio, block, &key, lookup_result, cell);
else {
struct endio_hook *h;
h = mempool_alloc(pool->endio_hook_pool, GFP_NOIO);
h->tc = tc;
h->entry = ds_inc(&pool->ds);
save_and_set_endio(bio, &h->saved_bi_end_io, shared_read_endio);
dm_get_mapinfo(bio)->ptr = h;
cell_release_singleton(cell, bio);
remap_and_issue(tc, bio, lookup_result->block);
}
}
static void provision_block(struct thin_c *tc, struct bio *bio, dm_block_t block,
struct cell *cell)
{
int r;
dm_block_t data_block;
if (!bio->bi_size) {
cell_release_singleton(cell, bio);
remap_and_issue(tc, bio, 0);
return;
}
if (bio_data_dir(bio) == READ) {
zero_fill_bio(bio);
cell_release_singleton(cell, bio);
bio_endio(bio, 0);
return;
}
r = alloc_data_block(tc, &data_block);
switch (r) {
case 0:
schedule_zero(tc, block, data_block, cell, bio);
break;
case -ENOSPC:
no_space(cell);
break;
default:
DMERR("%s: alloc_data_block() failed, error = %d", __func__, r);
cell_error(cell);
break;
}
}
static void process_bio(struct thin_c *tc, struct bio *bio)
{
int r;
dm_block_t block = get_bio_block(tc, bio);
struct cell *cell;
struct cell_key key;
struct dm_thin_lookup_result lookup_result;
build_virtual_key(tc->td, block, &key);
if (bio_detain(tc->pool->prison, &key, bio, &cell))
return;
r = dm_thin_find_block(tc->td, block, 1, &lookup_result);
switch (r) {
case 0:
cell_release_singleton(cell, bio);
if (lookup_result.shared)
process_shared_bio(tc, bio, block, &lookup_result);
else
remap_and_issue(tc, bio, lookup_result.block);
break;
case -ENODATA:
provision_block(tc, bio, block, cell);
break;
default:
DMERR("dm_thin_find_block() failed, error = %d", r);
bio_io_error(bio);
break;
}
}
static void process_deferred_bios(struct pool *pool)
{
unsigned long flags;
struct bio *bio;
struct bio_list bios;
int r;
bio_list_init(&bios);
spin_lock_irqsave(&pool->lock, flags);
bio_list_merge(&bios, &pool->deferred_bios);
bio_list_init(&pool->deferred_bios);
spin_unlock_irqrestore(&pool->lock, flags);
while ((bio = bio_list_pop(&bios))) {
struct thin_c *tc = dm_get_mapinfo(bio)->ptr;
if (ensure_next_mapping(pool)) {
spin_lock_irqsave(&pool->lock, flags);
bio_list_merge(&pool->deferred_bios, &bios);
spin_unlock_irqrestore(&pool->lock, flags);
break;
}
process_bio(tc, bio);
}
bio_list_init(&bios);
spin_lock_irqsave(&pool->lock, flags);
bio_list_merge(&bios, &pool->deferred_flush_bios);
bio_list_init(&pool->deferred_flush_bios);
spin_unlock_irqrestore(&pool->lock, flags);
if (bio_list_empty(&bios))
return;
r = dm_pool_commit_metadata(pool->pmd);
if (r) {
DMERR("%s: dm_pool_commit_metadata() failed, error = %d",
__func__, r);
while ((bio = bio_list_pop(&bios)))
bio_io_error(bio);
return;
}
while ((bio = bio_list_pop(&bios)))
generic_make_request(bio);
}
static void do_worker(struct work_struct *ws)
{
struct pool *pool = container_of(ws, struct pool, worker);
process_prepared_mappings(pool);
process_deferred_bios(pool);
}
static void thin_defer_bio(struct thin_c *tc, struct bio *bio)
{
unsigned long flags;
struct pool *pool = tc->pool;
spin_lock_irqsave(&pool->lock, flags);
bio_list_add(&pool->deferred_bios, bio);
spin_unlock_irqrestore(&pool->lock, flags);
wake_worker(pool);
}
static int thin_bio_map(struct dm_target *ti, struct bio *bio,
union map_info *map_context)
{
int r;
struct thin_c *tc = ti->private;
dm_block_t block = get_bio_block(tc, bio);
struct dm_thin_device *td = tc->td;
struct dm_thin_lookup_result result;
map_context->ptr = tc;
if (bio->bi_rw & (REQ_FLUSH | REQ_FUA)) {
thin_defer_bio(tc, bio);
return DM_MAPIO_SUBMITTED;
}
r = dm_thin_find_block(td, block, 0, &result);
switch (r) {
case 0:
if (unlikely(result.shared)) {
thin_defer_bio(tc, bio);
r = DM_MAPIO_SUBMITTED;
} else {
remap(tc, bio, result.block);
r = DM_MAPIO_REMAPPED;
}
break;
case -ENODATA:
case -EWOULDBLOCK:
thin_defer_bio(tc, bio);
r = DM_MAPIO_SUBMITTED;
break;
}
return r;
}
static int pool_is_congested(struct dm_target_callbacks *cb, int bdi_bits)
{
int r;
unsigned long flags;
struct pool_c *pt = container_of(cb, struct pool_c, callbacks);
spin_lock_irqsave(&pt->pool->lock, flags);
r = !bio_list_empty(&pt->pool->retry_on_resume_list);
spin_unlock_irqrestore(&pt->pool->lock, flags);
if (!r) {
struct request_queue *q = bdev_get_queue(pt->data_dev->bdev);
r = bdi_congested(&q->backing_dev_info, bdi_bits);
}
return r;
}
static void __requeue_bios(struct pool *pool)
{
bio_list_merge(&pool->deferred_bios, &pool->retry_on_resume_list);
bio_list_init(&pool->retry_on_resume_list);
}
static int bind_control_target(struct pool *pool, struct dm_target *ti)
{
struct pool_c *pt = ti->private;
pool->ti = ti;
pool->low_water_blocks = pt->low_water_blocks;
pool->zero_new_blocks = pt->zero_new_blocks;
return 0;
}
static void unbind_control_target(struct pool *pool, struct dm_target *ti)
{
if (pool->ti == ti)
pool->ti = NULL;
}
static void __pool_destroy(struct pool *pool)
{
__pool_table_remove(pool);
if (dm_pool_metadata_close(pool->pmd) < 0)
DMWARN("%s: dm_pool_metadata_close() failed.", __func__);
prison_destroy(pool->prison);
dm_kcopyd_client_destroy(pool->copier);
if (pool->wq)
destroy_workqueue(pool->wq);
if (pool->next_mapping)
mempool_free(pool->next_mapping, pool->mapping_pool);
mempool_destroy(pool->mapping_pool);
mempool_destroy(pool->endio_hook_pool);
kfree(pool);
}
static struct pool *pool_create(struct mapped_device *pool_md,
struct block_device *metadata_dev,
unsigned long block_size, char **error)
{
int r;
void *err_p;
struct pool *pool;
struct dm_pool_metadata *pmd;
pmd = dm_pool_metadata_open(metadata_dev, block_size);
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
pool->block_shift = ffs(block_size) - 1;
pool->offset_mask = block_size - 1;
pool->low_water_blocks = 0;
pool->zero_new_blocks = 1;
pool->prison = prison_create(PRISON_CELLS);
if (!pool->prison) {
*error = "Error creating pool's bio prison";
err_p = ERR_PTR(-ENOMEM);
goto bad_prison;
}
pool->copier = dm_kcopyd_client_create();
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
spin_lock_init(&pool->lock);
bio_list_init(&pool->deferred_bios);
bio_list_init(&pool->deferred_flush_bios);
INIT_LIST_HEAD(&pool->prepared_mappings);
pool->low_water_triggered = 0;
pool->no_free_space = 0;
bio_list_init(&pool->retry_on_resume_list);
ds_init(&pool->ds);
pool->next_mapping = NULL;
pool->mapping_pool =
mempool_create_kmalloc_pool(MAPPING_POOL_SIZE, sizeof(struct new_mapping));
if (!pool->mapping_pool) {
*error = "Error creating pool's mapping mempool";
err_p = ERR_PTR(-ENOMEM);
goto bad_mapping_pool;
}
pool->endio_hook_pool =
mempool_create_kmalloc_pool(ENDIO_HOOK_POOL_SIZE, sizeof(struct endio_hook));
if (!pool->endio_hook_pool) {
*error = "Error creating pool's endio_hook mempool";
err_p = ERR_PTR(-ENOMEM);
goto bad_endio_hook_pool;
}
pool->ref_count = 1;
pool->pool_md = pool_md;
pool->md_dev = metadata_dev;
__pool_table_insert(pool);
return pool;
bad_endio_hook_pool:
mempool_destroy(pool->mapping_pool);
bad_mapping_pool:
destroy_workqueue(pool->wq);
bad_wq:
dm_kcopyd_client_destroy(pool->copier);
bad_kcopyd_client:
prison_destroy(pool->prison);
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
unsigned long block_size, char **error)
{
struct pool *pool = __pool_table_lookup_metadata_dev(metadata_dev);
if (pool) {
if (pool->pool_md != pool_md)
return ERR_PTR(-EBUSY);
__pool_inc(pool);
} else {
pool = __pool_table_lookup(pool_md);
if (pool) {
if (pool->md_dev != metadata_dev)
return ERR_PTR(-EINVAL);
__pool_inc(pool);
} else
pool = pool_create(pool_md, metadata_dev, block_size, error);
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
{0, 1, "Invalid number of pool feature arguments"},
};
if (!as->argc)
return 0;
r = dm_read_arg_group(_args, as, &argc, &ti->error);
if (r)
return -EINVAL;
while (argc && !r) {
arg_name = dm_shift_arg(as);
argc--;
if (!strcasecmp(arg_name, "skip_block_zeroing")) {
pf->zero_new_blocks = 0;
continue;
}
ti->error = "Unrecognised pool feature requested";
r = -EINVAL;
}
return r;
}
static int pool_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
int r;
struct pool_c *pt;
struct pool *pool;
struct pool_features pf;
struct dm_arg_set as;
struct dm_dev *data_dev;
unsigned long block_size;
dm_block_t low_water_blocks;
struct dm_dev *metadata_dev;
sector_t metadata_dev_size;
mutex_lock(&dm_thin_pool_table.mutex);
if (argc < 4) {
ti->error = "Invalid argument count";
r = -EINVAL;
goto out_unlock;
}
as.argc = argc;
as.argv = argv;
r = dm_get_device(ti, argv[0], FMODE_READ | FMODE_WRITE, &metadata_dev);
if (r) {
ti->error = "Error opening metadata block device";
goto out_unlock;
}
metadata_dev_size = i_size_read(metadata_dev->bdev->bd_inode) >> SECTOR_SHIFT;
if (metadata_dev_size > METADATA_DEV_MAX_SECTORS) {
ti->error = "Metadata device is too large";
r = -EINVAL;
goto out_metadata;
}
r = dm_get_device(ti, argv[1], FMODE_READ | FMODE_WRITE, &data_dev);
if (r) {
ti->error = "Error getting data device";
goto out_metadata;
}
if (kstrtoul(argv[2], 10, &block_size) || !block_size ||
block_size < DATA_DEV_BLOCK_SIZE_MIN_SECTORS ||
block_size > DATA_DEV_BLOCK_SIZE_MAX_SECTORS ||
!is_power_of_2(block_size)) {
ti->error = "Invalid block size";
r = -EINVAL;
goto out;
}
if (kstrtoull(argv[3], 10, (unsigned long long *)&low_water_blocks)) {
ti->error = "Invalid low water mark";
r = -EINVAL;
goto out;
}
memset(&pf, 0, sizeof(pf));
pf.zero_new_blocks = 1;
dm_consume_args(&as, 4);
r = parse_pool_features(&as, &pf, ti);
if (r)
goto out;
pt = kzalloc(sizeof(*pt), GFP_KERNEL);
if (!pt) {
r = -ENOMEM;
goto out;
}
pool = __pool_find(dm_table_get_md(ti->table), metadata_dev->bdev,
block_size, &ti->error);
if (IS_ERR(pool)) {
r = PTR_ERR(pool);
goto out_free_pt;
}
pt->pool = pool;
pt->ti = ti;
pt->metadata_dev = metadata_dev;
pt->data_dev = data_dev;
pt->low_water_blocks = low_water_blocks;
pt->zero_new_blocks = pf.zero_new_blocks;
ti->num_flush_requests = 1;
ti->num_discard_requests = 0;
ti->private = pt;
pt->callbacks.congested_fn = pool_is_congested;
dm_table_add_target_callbacks(ti->table, &pt->callbacks);
mutex_unlock(&dm_thin_pool_table.mutex);
return 0;
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
static int pool_map(struct dm_target *ti, struct bio *bio,
union map_info *map_context)
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
static int pool_preresume(struct dm_target *ti)
{
int r;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
dm_block_t data_size, sb_data_size;
r = bind_control_target(pool, ti);
if (r)
return r;
data_size = ti->len >> pool->block_shift;
r = dm_pool_get_data_dev_size(pool->pmd, &sb_data_size);
if (r) {
DMERR("failed to retrieve data device size");
return r;
}
if (data_size < sb_data_size) {
DMERR("pool target too small, is %llu blocks (expected %llu)",
data_size, sb_data_size);
return -EINVAL;
} else if (data_size > sb_data_size) {
r = dm_pool_resize_data_dev(pool->pmd, data_size);
if (r) {
DMERR("failed to resize data device");
return r;
}
r = dm_pool_commit_metadata(pool->pmd);
if (r) {
DMERR("%s: dm_pool_commit_metadata() failed, error = %d",
__func__, r);
return r;
}
}
return 0;
}
static void pool_resume(struct dm_target *ti)
{
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
unsigned long flags;
spin_lock_irqsave(&pool->lock, flags);
pool->low_water_triggered = 0;
pool->no_free_space = 0;
__requeue_bios(pool);
spin_unlock_irqrestore(&pool->lock, flags);
wake_worker(pool);
}
static void pool_postsuspend(struct dm_target *ti)
{
int r;
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
flush_workqueue(pool->wq);
r = dm_pool_commit_metadata(pool->pmd);
if (r < 0) {
DMERR("%s: dm_pool_commit_metadata() failed, error = %d",
__func__, r);
}
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
else
DMWARN("Unrecognised thin pool target message received: %s", argv[0]);
if (!r) {
r = dm_pool_commit_metadata(pool->pmd);
if (r)
DMERR("%s message: dm_pool_commit_metadata() failed, error = %d",
argv[0], r);
}
return r;
}
static int pool_status(struct dm_target *ti, status_type_t type,
char *result, unsigned maxlen)
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
r = dm_pool_get_metadata_transaction_id(pool->pmd,
&transaction_id);
if (r)
return r;
r = dm_pool_get_free_metadata_block_count(pool->pmd,
&nr_free_blocks_metadata);
if (r)
return r;
r = dm_pool_get_metadata_dev_size(pool->pmd, &nr_blocks_metadata);
if (r)
return r;
r = dm_pool_get_free_block_count(pool->pmd,
&nr_free_blocks_data);
if (r)
return r;
r = dm_pool_get_data_dev_size(pool->pmd, &nr_blocks_data);
if (r)
return r;
r = dm_pool_get_held_metadata_root(pool->pmd, &held_root);
if (r)
return r;
DMEMIT("%llu %llu/%llu %llu/%llu ",
(unsigned long long)transaction_id,
(unsigned long long)(nr_blocks_metadata - nr_free_blocks_metadata),
(unsigned long long)nr_blocks_metadata,
(unsigned long long)(nr_blocks_data - nr_free_blocks_data),
(unsigned long long)nr_blocks_data);
if (held_root)
DMEMIT("%llu", held_root);
else
DMEMIT("-");
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %s %lu %llu ",
format_dev_t(buf, pt->metadata_dev->bdev->bd_dev),
format_dev_t(buf2, pt->data_dev->bdev->bd_dev),
(unsigned long)pool->sectors_per_block,
(unsigned long long)pt->low_water_blocks);
DMEMIT("%u ", !pool->zero_new_blocks);
if (!pool->zero_new_blocks)
DMEMIT("skip_block_zeroing ");
break;
}
return 0;
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
static void pool_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct pool_c *pt = ti->private;
struct pool *pool = pt->pool;
blk_limits_io_min(limits, 0);
blk_limits_io_opt(limits, pool->sectors_per_block << SECTOR_SHIFT);
}
static void thin_dtr(struct dm_target *ti)
{
struct thin_c *tc = ti->private;
mutex_lock(&dm_thin_pool_table.mutex);
__pool_dec(tc->pool);
dm_pool_close_thin_device(tc->td);
dm_put_device(ti, tc->pool_dev);
kfree(tc);
mutex_unlock(&dm_thin_pool_table.mutex);
}
static int thin_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
int r;
struct thin_c *tc;
struct dm_dev *pool_dev;
struct mapped_device *pool_md;
mutex_lock(&dm_thin_pool_table.mutex);
if (argc != 2) {
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
r = dm_pool_open_thin_device(tc->pool->pmd, tc->dev_id, &tc->td);
if (r) {
ti->error = "Couldn't open thin internal device";
goto bad_thin_open;
}
ti->split_io = tc->pool->sectors_per_block;
ti->num_flush_requests = 1;
ti->num_discard_requests = 0;
ti->discards_supported = 0;
dm_put(pool_md);
mutex_unlock(&dm_thin_pool_table.mutex);
return 0;
bad_thin_open:
__pool_dec(tc->pool);
bad_pool_lookup:
dm_put(pool_md);
bad_common:
dm_put_device(ti, tc->pool_dev);
bad_pool_dev:
kfree(tc);
out_unlock:
mutex_unlock(&dm_thin_pool_table.mutex);
return r;
}
static int thin_map(struct dm_target *ti, struct bio *bio,
union map_info *map_context)
{
bio->bi_sector -= ti->begin;
return thin_bio_map(ti, bio, map_context);
}
static void thin_postsuspend(struct dm_target *ti)
{
if (dm_noflush_suspending(ti))
requeue_io((struct thin_c *)ti->private);
}
static int thin_status(struct dm_target *ti, status_type_t type,
char *result, unsigned maxlen)
{
int r;
ssize_t sz = 0;
dm_block_t mapped, highest;
char buf[BDEVNAME_SIZE];
struct thin_c *tc = ti->private;
if (!tc->td)
DMEMIT("-");
else {
switch (type) {
case STATUSTYPE_INFO:
r = dm_thin_get_mapped_count(tc->td, &mapped);
if (r)
return r;
r = dm_thin_get_highest_mapped_block(tc->td, &highest);
if (r < 0)
return r;
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
break;
}
}
return 0;
}
static int thin_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
dm_block_t blocks;
struct thin_c *tc = ti->private;
if (!tc->pool->ti)
return 0;
blocks = tc->pool->ti->len >> tc->pool->block_shift;
if (blocks)
return fn(ti, tc->pool_dev, 0, tc->pool->sectors_per_block * blocks, data);
return 0;
}
static void thin_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct thin_c *tc = ti->private;
blk_limits_io_min(limits, 0);
blk_limits_io_opt(limits, tc->pool->sectors_per_block << SECTOR_SHIFT);
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
dm_unregister_target(&thin_target);
return r;
}
static void dm_thin_exit(void)
{
dm_unregister_target(&thin_target);
dm_unregister_target(&pool_target);
}
