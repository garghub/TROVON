static uint32_t calc_nr_buckets(unsigned nr_cells)
{
uint32_t n = 128;
nr_cells /= 4;
nr_cells = min(nr_cells, 8192u);
while (n < nr_cells)
n <<= 1;
return n;
}
struct dm_bio_prison *dm_bio_prison_create(unsigned nr_cells)
{
unsigned i;
uint32_t nr_buckets = calc_nr_buckets(nr_cells);
size_t len = sizeof(struct dm_bio_prison) +
(sizeof(struct hlist_head) * nr_buckets);
struct dm_bio_prison *prison = kmalloc(len, GFP_KERNEL);
if (!prison)
return NULL;
spin_lock_init(&prison->lock);
prison->cell_pool = mempool_create_slab_pool(nr_cells, _cell_cache);
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
void dm_bio_prison_destroy(struct dm_bio_prison *prison)
{
mempool_destroy(prison->cell_pool);
kfree(prison);
}
static uint32_t hash_key(struct dm_bio_prison *prison, struct dm_cell_key *key)
{
const unsigned long BIG_PRIME = 4294967291UL;
uint64_t hash = key->block * BIG_PRIME;
return (uint32_t) (hash & prison->hash_mask);
}
static int keys_equal(struct dm_cell_key *lhs, struct dm_cell_key *rhs)
{
return (lhs->virtual == rhs->virtual) &&
(lhs->dev == rhs->dev) &&
(lhs->block == rhs->block);
}
static struct dm_bio_prison_cell *__search_bucket(struct hlist_head *bucket,
struct dm_cell_key *key)
{
struct dm_bio_prison_cell *cell;
struct hlist_node *tmp;
hlist_for_each_entry(cell, tmp, bucket, list)
if (keys_equal(&cell->key, key))
return cell;
return NULL;
}
int dm_bio_detain(struct dm_bio_prison *prison, struct dm_cell_key *key,
struct bio *inmate, struct dm_bio_prison_cell **ref)
{
int r = 1;
unsigned long flags;
uint32_t hash = hash_key(prison, key);
struct dm_bio_prison_cell *cell, *cell2;
BUG_ON(hash > prison->nr_buckets);
spin_lock_irqsave(&prison->lock, flags);
cell = __search_bucket(prison->cells + hash, key);
if (cell) {
bio_list_add(&cell->bios, inmate);
goto out;
}
spin_unlock_irqrestore(&prison->lock, flags);
cell2 = mempool_alloc(prison->cell_pool, GFP_NOIO);
spin_lock_irqsave(&prison->lock, flags);
cell = __search_bucket(prison->cells + hash, key);
if (cell) {
mempool_free(cell2, prison->cell_pool);
bio_list_add(&cell->bios, inmate);
goto out;
}
cell = cell2;
cell->prison = prison;
memcpy(&cell->key, key, sizeof(cell->key));
cell->holder = inmate;
bio_list_init(&cell->bios);
hlist_add_head(&cell->list, prison->cells + hash);
r = 0;
out:
spin_unlock_irqrestore(&prison->lock, flags);
*ref = cell;
return r;
}
static void __cell_release(struct dm_bio_prison_cell *cell, struct bio_list *inmates)
{
struct dm_bio_prison *prison = cell->prison;
hlist_del(&cell->list);
if (inmates) {
bio_list_add(inmates, cell->holder);
bio_list_merge(inmates, &cell->bios);
}
mempool_free(cell, prison->cell_pool);
}
void dm_cell_release(struct dm_bio_prison_cell *cell, struct bio_list *bios)
{
unsigned long flags;
struct dm_bio_prison *prison = cell->prison;
spin_lock_irqsave(&prison->lock, flags);
__cell_release(cell, bios);
spin_unlock_irqrestore(&prison->lock, flags);
}
static void __cell_release_singleton(struct dm_bio_prison_cell *cell, struct bio *bio)
{
BUG_ON(cell->holder != bio);
BUG_ON(!bio_list_empty(&cell->bios));
__cell_release(cell, NULL);
}
void dm_cell_release_singleton(struct dm_bio_prison_cell *cell, struct bio *bio)
{
unsigned long flags;
struct dm_bio_prison *prison = cell->prison;
spin_lock_irqsave(&prison->lock, flags);
__cell_release_singleton(cell, bio);
spin_unlock_irqrestore(&prison->lock, flags);
}
static void __cell_release_no_holder(struct dm_bio_prison_cell *cell, struct bio_list *inmates)
{
struct dm_bio_prison *prison = cell->prison;
hlist_del(&cell->list);
bio_list_merge(inmates, &cell->bios);
mempool_free(cell, prison->cell_pool);
}
void dm_cell_release_no_holder(struct dm_bio_prison_cell *cell, struct bio_list *inmates)
{
unsigned long flags;
struct dm_bio_prison *prison = cell->prison;
spin_lock_irqsave(&prison->lock, flags);
__cell_release_no_holder(cell, inmates);
spin_unlock_irqrestore(&prison->lock, flags);
}
void dm_cell_error(struct dm_bio_prison_cell *cell)
{
struct dm_bio_prison *prison = cell->prison;
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
struct dm_deferred_set *dm_deferred_set_create(void)
{
int i;
struct dm_deferred_set *ds;
ds = kmalloc(sizeof(*ds), GFP_KERNEL);
if (!ds)
return NULL;
spin_lock_init(&ds->lock);
ds->current_entry = 0;
ds->sweeper = 0;
for (i = 0; i < DEFERRED_SET_SIZE; i++) {
ds->entries[i].ds = ds;
ds->entries[i].count = 0;
INIT_LIST_HEAD(&ds->entries[i].work_items);
}
return ds;
}
void dm_deferred_set_destroy(struct dm_deferred_set *ds)
{
kfree(ds);
}
struct dm_deferred_entry *dm_deferred_entry_inc(struct dm_deferred_set *ds)
{
unsigned long flags;
struct dm_deferred_entry *entry;
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
static void __sweep(struct dm_deferred_set *ds, struct list_head *head)
{
while ((ds->sweeper != ds->current_entry) &&
!ds->entries[ds->sweeper].count) {
list_splice_init(&ds->entries[ds->sweeper].work_items, head);
ds->sweeper = ds_next(ds->sweeper);
}
if ((ds->sweeper == ds->current_entry) && !ds->entries[ds->sweeper].count)
list_splice_init(&ds->entries[ds->sweeper].work_items, head);
}
void dm_deferred_entry_dec(struct dm_deferred_entry *entry, struct list_head *head)
{
unsigned long flags;
spin_lock_irqsave(&entry->ds->lock, flags);
BUG_ON(!entry->count);
--entry->count;
__sweep(entry->ds, head);
spin_unlock_irqrestore(&entry->ds->lock, flags);
}
int dm_deferred_set_add_work(struct dm_deferred_set *ds, struct list_head *work)
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
static int __init dm_bio_prison_init(void)
{
_cell_cache = KMEM_CACHE(dm_bio_prison_cell, 0);
if (!_cell_cache)
return -ENOMEM;
return 0;
}
static void __exit dm_bio_prison_exit(void)
{
kmem_cache_destroy(_cell_cache);
_cell_cache = NULL;
}
