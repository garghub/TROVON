static uint32_t calc_nr_buckets(unsigned nr_cells)
{
uint32_t n = 128;
nr_cells /= 4;
nr_cells = min(nr_cells, 8192u);
while (n < nr_cells)
n <<= 1;
return n;
}
static void init_bucket(struct bucket *b)
{
spin_lock_init(&b->lock);
INIT_HLIST_HEAD(&b->cells);
}
struct dm_bio_prison *dm_bio_prison_create(unsigned nr_cells)
{
unsigned i;
uint32_t nr_buckets = calc_nr_buckets(nr_cells);
size_t len = sizeof(struct dm_bio_prison) +
(sizeof(struct bucket) * nr_buckets);
struct dm_bio_prison *prison = kmalloc(len, GFP_KERNEL);
if (!prison)
return NULL;
prison->cell_pool = mempool_create_slab_pool(nr_cells, _cell_cache);
if (!prison->cell_pool) {
kfree(prison);
return NULL;
}
prison->nr_buckets = nr_buckets;
prison->hash_mask = nr_buckets - 1;
prison->buckets = (struct bucket *) (prison + 1);
for (i = 0; i < nr_buckets; i++)
init_bucket(prison->buckets + i);
return prison;
}
void dm_bio_prison_destroy(struct dm_bio_prison *prison)
{
mempool_destroy(prison->cell_pool);
kfree(prison);
}
struct dm_bio_prison_cell *dm_bio_prison_alloc_cell(struct dm_bio_prison *prison, gfp_t gfp)
{
return mempool_alloc(prison->cell_pool, gfp);
}
void dm_bio_prison_free_cell(struct dm_bio_prison *prison,
struct dm_bio_prison_cell *cell)
{
mempool_free(cell, prison->cell_pool);
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
static struct bucket *get_bucket(struct dm_bio_prison *prison,
struct dm_cell_key *key)
{
return prison->buckets + hash_key(prison, key);
}
static struct dm_bio_prison_cell *__search_bucket(struct bucket *b,
struct dm_cell_key *key)
{
struct dm_bio_prison_cell *cell;
hlist_for_each_entry(cell, &b->cells, list)
if (keys_equal(&cell->key, key))
return cell;
return NULL;
}
static void __setup_new_cell(struct bucket *b,
struct dm_cell_key *key,
struct bio *holder,
struct dm_bio_prison_cell *cell)
{
memcpy(&cell->key, key, sizeof(cell->key));
cell->holder = holder;
bio_list_init(&cell->bios);
hlist_add_head(&cell->list, &b->cells);
}
static int __bio_detain(struct bucket *b,
struct dm_cell_key *key,
struct bio *inmate,
struct dm_bio_prison_cell *cell_prealloc,
struct dm_bio_prison_cell **cell_result)
{
struct dm_bio_prison_cell *cell;
cell = __search_bucket(b, key);
if (cell) {
if (inmate)
bio_list_add(&cell->bios, inmate);
*cell_result = cell;
return 1;
}
__setup_new_cell(b, key, inmate, cell_prealloc);
*cell_result = cell_prealloc;
return 0;
}
static int bio_detain(struct dm_bio_prison *prison,
struct dm_cell_key *key,
struct bio *inmate,
struct dm_bio_prison_cell *cell_prealloc,
struct dm_bio_prison_cell **cell_result)
{
int r;
unsigned long flags;
struct bucket *b = get_bucket(prison, key);
spin_lock_irqsave(&b->lock, flags);
r = __bio_detain(b, key, inmate, cell_prealloc, cell_result);
spin_unlock_irqrestore(&b->lock, flags);
return r;
}
int dm_bio_detain(struct dm_bio_prison *prison,
struct dm_cell_key *key,
struct bio *inmate,
struct dm_bio_prison_cell *cell_prealloc,
struct dm_bio_prison_cell **cell_result)
{
return bio_detain(prison, key, inmate, cell_prealloc, cell_result);
}
int dm_get_cell(struct dm_bio_prison *prison,
struct dm_cell_key *key,
struct dm_bio_prison_cell *cell_prealloc,
struct dm_bio_prison_cell **cell_result)
{
return bio_detain(prison, key, NULL, cell_prealloc, cell_result);
}
static void __cell_release(struct dm_bio_prison_cell *cell,
struct bio_list *inmates)
{
hlist_del(&cell->list);
if (inmates) {
if (cell->holder)
bio_list_add(inmates, cell->holder);
bio_list_merge(inmates, &cell->bios);
}
}
void dm_cell_release(struct dm_bio_prison *prison,
struct dm_bio_prison_cell *cell,
struct bio_list *bios)
{
unsigned long flags;
struct bucket *b = get_bucket(prison, &cell->key);
spin_lock_irqsave(&b->lock, flags);
__cell_release(cell, bios);
spin_unlock_irqrestore(&b->lock, flags);
}
static void __cell_release_no_holder(struct dm_bio_prison_cell *cell,
struct bio_list *inmates)
{
hlist_del(&cell->list);
bio_list_merge(inmates, &cell->bios);
}
void dm_cell_release_no_holder(struct dm_bio_prison *prison,
struct dm_bio_prison_cell *cell,
struct bio_list *inmates)
{
unsigned long flags;
struct bucket *b = get_bucket(prison, &cell->key);
spin_lock_irqsave(&b->lock, flags);
__cell_release_no_holder(cell, inmates);
spin_unlock_irqrestore(&b->lock, flags);
}
void dm_cell_error(struct dm_bio_prison *prison,
struct dm_bio_prison_cell *cell, int error)
{
struct bio_list bios;
struct bio *bio;
bio_list_init(&bios);
dm_cell_release(prison, cell, &bios);
while ((bio = bio_list_pop(&bios)))
bio_endio(bio, error);
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
