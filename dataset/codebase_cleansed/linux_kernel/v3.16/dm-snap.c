struct dm_dev *dm_snap_origin(struct dm_snapshot *s)
{
return s->origin;
}
struct dm_dev *dm_snap_cow(struct dm_snapshot *s)
{
return s->cow;
}
static sector_t chunk_to_sector(struct dm_exception_store *store,
chunk_t chunk)
{
return chunk << store->chunk_shift;
}
static int bdev_equal(struct block_device *lhs, struct block_device *rhs)
{
return lhs == rhs;
}
static void init_tracked_chunk(struct bio *bio)
{
struct dm_snap_tracked_chunk *c = dm_per_bio_data(bio, sizeof(struct dm_snap_tracked_chunk));
INIT_HLIST_NODE(&c->node);
}
static bool is_bio_tracked(struct bio *bio)
{
struct dm_snap_tracked_chunk *c = dm_per_bio_data(bio, sizeof(struct dm_snap_tracked_chunk));
return !hlist_unhashed(&c->node);
}
static void track_chunk(struct dm_snapshot *s, struct bio *bio, chunk_t chunk)
{
struct dm_snap_tracked_chunk *c = dm_per_bio_data(bio, sizeof(struct dm_snap_tracked_chunk));
c->chunk = chunk;
spin_lock_irq(&s->tracked_chunk_lock);
hlist_add_head(&c->node,
&s->tracked_chunk_hash[DM_TRACKED_CHUNK_HASH(chunk)]);
spin_unlock_irq(&s->tracked_chunk_lock);
}
static void stop_tracking_chunk(struct dm_snapshot *s, struct bio *bio)
{
struct dm_snap_tracked_chunk *c = dm_per_bio_data(bio, sizeof(struct dm_snap_tracked_chunk));
unsigned long flags;
spin_lock_irqsave(&s->tracked_chunk_lock, flags);
hlist_del(&c->node);
spin_unlock_irqrestore(&s->tracked_chunk_lock, flags);
}
static int __chunk_is_tracked(struct dm_snapshot *s, chunk_t chunk)
{
struct dm_snap_tracked_chunk *c;
int found = 0;
spin_lock_irq(&s->tracked_chunk_lock);
hlist_for_each_entry(c,
&s->tracked_chunk_hash[DM_TRACKED_CHUNK_HASH(chunk)], node) {
if (c->chunk == chunk) {
found = 1;
break;
}
}
spin_unlock_irq(&s->tracked_chunk_lock);
return found;
}
static void __check_for_conflicting_io(struct dm_snapshot *s, chunk_t chunk)
{
while (__chunk_is_tracked(s, chunk))
msleep(1);
}
static int init_origin_hash(void)
{
int i;
_origins = kmalloc(ORIGIN_HASH_SIZE * sizeof(struct list_head),
GFP_KERNEL);
if (!_origins) {
DMERR("unable to allocate memory");
return -ENOMEM;
}
for (i = 0; i < ORIGIN_HASH_SIZE; i++)
INIT_LIST_HEAD(_origins + i);
init_rwsem(&_origins_lock);
return 0;
}
static void exit_origin_hash(void)
{
kfree(_origins);
}
static unsigned origin_hash(struct block_device *bdev)
{
return bdev->bd_dev & ORIGIN_MASK;
}
static struct origin *__lookup_origin(struct block_device *origin)
{
struct list_head *ol;
struct origin *o;
ol = &_origins[origin_hash(origin)];
list_for_each_entry (o, ol, hash_list)
if (bdev_equal(o->bdev, origin))
return o;
return NULL;
}
static void __insert_origin(struct origin *o)
{
struct list_head *sl = &_origins[origin_hash(o->bdev)];
list_add_tail(&o->hash_list, sl);
}
static int __find_snapshots_sharing_cow(struct dm_snapshot *snap,
struct dm_snapshot **snap_src,
struct dm_snapshot **snap_dest,
struct dm_snapshot **snap_merge)
{
struct dm_snapshot *s;
struct origin *o;
int count = 0;
int active;
o = __lookup_origin(snap->origin->bdev);
if (!o)
goto out;
list_for_each_entry(s, &o->snapshots, list) {
if (dm_target_is_snapshot_merge(s->ti) && snap_merge)
*snap_merge = s;
if (!bdev_equal(s->cow->bdev, snap->cow->bdev))
continue;
down_read(&s->lock);
active = s->active;
up_read(&s->lock);
if (active) {
if (snap_src)
*snap_src = s;
} else if (snap_dest)
*snap_dest = s;
count++;
}
out:
return count;
}
static int __validate_exception_handover(struct dm_snapshot *snap)
{
struct dm_snapshot *snap_src = NULL, *snap_dest = NULL;
struct dm_snapshot *snap_merge = NULL;
if ((__find_snapshots_sharing_cow(snap, &snap_src, &snap_dest,
&snap_merge) == 2) ||
snap_dest) {
snap->ti->error = "Snapshot cow pairing for exception "
"table handover failed";
return -EINVAL;
}
if (!snap_src)
return 0;
if (!dm_target_is_snapshot_merge(snap->ti))
return 1;
if (snap_merge) {
snap->ti->error = "A snapshot is already merging.";
return -EINVAL;
}
if (!snap_src->store->type->prepare_merge ||
!snap_src->store->type->commit_merge) {
snap->ti->error = "Snapshot exception store does not "
"support snapshot-merge.";
return -EINVAL;
}
return 1;
}
static void __insert_snapshot(struct origin *o, struct dm_snapshot *s)
{
struct dm_snapshot *l;
list_for_each_entry(l, &o->snapshots, list)
if (l->store->chunk_size < s->store->chunk_size)
break;
list_add_tail(&s->list, &l->list);
}
static int register_snapshot(struct dm_snapshot *snap)
{
struct origin *o, *new_o = NULL;
struct block_device *bdev = snap->origin->bdev;
int r = 0;
new_o = kmalloc(sizeof(*new_o), GFP_KERNEL);
if (!new_o)
return -ENOMEM;
down_write(&_origins_lock);
r = __validate_exception_handover(snap);
if (r < 0) {
kfree(new_o);
goto out;
}
o = __lookup_origin(bdev);
if (o)
kfree(new_o);
else {
o = new_o;
INIT_LIST_HEAD(&o->snapshots);
o->bdev = bdev;
__insert_origin(o);
}
__insert_snapshot(o, snap);
out:
up_write(&_origins_lock);
return r;
}
static void reregister_snapshot(struct dm_snapshot *s)
{
struct block_device *bdev = s->origin->bdev;
down_write(&_origins_lock);
list_del(&s->list);
__insert_snapshot(__lookup_origin(bdev), s);
up_write(&_origins_lock);
}
static void unregister_snapshot(struct dm_snapshot *s)
{
struct origin *o;
down_write(&_origins_lock);
o = __lookup_origin(s->origin->bdev);
list_del(&s->list);
if (o && list_empty(&o->snapshots)) {
list_del(&o->hash_list);
kfree(o);
}
up_write(&_origins_lock);
}
static int dm_exception_table_init(struct dm_exception_table *et,
uint32_t size, unsigned hash_shift)
{
unsigned int i;
et->hash_shift = hash_shift;
et->hash_mask = size - 1;
et->table = dm_vcalloc(size, sizeof(struct list_head));
if (!et->table)
return -ENOMEM;
for (i = 0; i < size; i++)
INIT_LIST_HEAD(et->table + i);
return 0;
}
static void dm_exception_table_exit(struct dm_exception_table *et,
struct kmem_cache *mem)
{
struct list_head *slot;
struct dm_exception *ex, *next;
int i, size;
size = et->hash_mask + 1;
for (i = 0; i < size; i++) {
slot = et->table + i;
list_for_each_entry_safe (ex, next, slot, hash_list)
kmem_cache_free(mem, ex);
}
vfree(et->table);
}
static uint32_t exception_hash(struct dm_exception_table *et, chunk_t chunk)
{
return (chunk >> et->hash_shift) & et->hash_mask;
}
static void dm_remove_exception(struct dm_exception *e)
{
list_del(&e->hash_list);
}
static struct dm_exception *dm_lookup_exception(struct dm_exception_table *et,
chunk_t chunk)
{
struct list_head *slot;
struct dm_exception *e;
slot = &et->table[exception_hash(et, chunk)];
list_for_each_entry (e, slot, hash_list)
if (chunk >= e->old_chunk &&
chunk <= e->old_chunk + dm_consecutive_chunk_count(e))
return e;
return NULL;
}
static struct dm_exception *alloc_completed_exception(gfp_t gfp)
{
struct dm_exception *e;
e = kmem_cache_alloc(exception_cache, gfp);
if (!e && gfp == GFP_NOIO)
e = kmem_cache_alloc(exception_cache, GFP_ATOMIC);
return e;
}
static void free_completed_exception(struct dm_exception *e)
{
kmem_cache_free(exception_cache, e);
}
static struct dm_snap_pending_exception *alloc_pending_exception(struct dm_snapshot *s)
{
struct dm_snap_pending_exception *pe = mempool_alloc(s->pending_pool,
GFP_NOIO);
atomic_inc(&s->pending_exceptions_count);
pe->snap = s;
return pe;
}
static void free_pending_exception(struct dm_snap_pending_exception *pe)
{
struct dm_snapshot *s = pe->snap;
mempool_free(pe, s->pending_pool);
smp_mb__before_atomic();
atomic_dec(&s->pending_exceptions_count);
}
static void dm_insert_exception(struct dm_exception_table *eh,
struct dm_exception *new_e)
{
struct list_head *l;
struct dm_exception *e = NULL;
l = &eh->table[exception_hash(eh, new_e->old_chunk)];
if (!eh->hash_shift)
goto out;
list_for_each_entry_reverse(e, l, hash_list) {
if (new_e->old_chunk == (e->old_chunk +
dm_consecutive_chunk_count(e) + 1) &&
new_e->new_chunk == (dm_chunk_number(e->new_chunk) +
dm_consecutive_chunk_count(e) + 1)) {
dm_consecutive_chunk_count_inc(e);
free_completed_exception(new_e);
return;
}
if (new_e->old_chunk == (e->old_chunk - 1) &&
new_e->new_chunk == (dm_chunk_number(e->new_chunk) - 1)) {
dm_consecutive_chunk_count_inc(e);
e->old_chunk--;
e->new_chunk--;
free_completed_exception(new_e);
return;
}
if (new_e->old_chunk > e->old_chunk)
break;
}
out:
list_add(&new_e->hash_list, e ? &e->hash_list : l);
}
static int dm_add_exception(void *context, chunk_t old, chunk_t new)
{
struct dm_snapshot *s = context;
struct dm_exception *e;
e = alloc_completed_exception(GFP_KERNEL);
if (!e)
return -ENOMEM;
e->old_chunk = old;
e->new_chunk = new;
dm_insert_exception(&s->complete, e);
return 0;
}
static uint32_t __minimum_chunk_size(struct origin *o)
{
struct dm_snapshot *snap;
unsigned chunk_size = 0;
if (o)
list_for_each_entry(snap, &o->snapshots, list)
chunk_size = min_not_zero(chunk_size,
snap->store->chunk_size);
return (uint32_t) chunk_size;
}
static int calc_max_buckets(void)
{
unsigned long mem = 2 * 1024 * 1024;
mem /= sizeof(struct list_head);
return mem;
}
static int init_hash_tables(struct dm_snapshot *s)
{
sector_t hash_size, cow_dev_size, max_buckets;
cow_dev_size = get_dev_size(s->cow->bdev);
max_buckets = calc_max_buckets();
hash_size = cow_dev_size >> s->store->chunk_shift;
hash_size = min(hash_size, max_buckets);
if (hash_size < 64)
hash_size = 64;
hash_size = rounddown_pow_of_two(hash_size);
if (dm_exception_table_init(&s->complete, hash_size,
DM_CHUNK_CONSECUTIVE_BITS))
return -ENOMEM;
hash_size >>= 3;
if (hash_size < 64)
hash_size = 64;
if (dm_exception_table_init(&s->pending, hash_size, 0)) {
dm_exception_table_exit(&s->complete, exception_cache);
return -ENOMEM;
}
return 0;
}
static void merge_shutdown(struct dm_snapshot *s)
{
clear_bit_unlock(RUNNING_MERGE, &s->state_bits);
smp_mb__after_atomic();
wake_up_bit(&s->state_bits, RUNNING_MERGE);
}
static struct bio *__release_queued_bios_after_merge(struct dm_snapshot *s)
{
s->first_merging_chunk = 0;
s->num_merging_chunks = 0;
return bio_list_get(&s->bios_queued_during_merge);
}
static int __remove_single_exception_chunk(struct dm_snapshot *s,
chunk_t old_chunk)
{
struct dm_exception *e;
e = dm_lookup_exception(&s->complete, old_chunk);
if (!e) {
DMERR("Corruption detected: exception for block %llu is "
"on disk but not in memory",
(unsigned long long)old_chunk);
return -EINVAL;
}
if (!dm_consecutive_chunk_count(e)) {
dm_remove_exception(e);
free_completed_exception(e);
return 0;
}
if (old_chunk == e->old_chunk) {
e->old_chunk++;
e->new_chunk++;
} else if (old_chunk != e->old_chunk +
dm_consecutive_chunk_count(e)) {
DMERR("Attempt to merge block %llu from the "
"middle of a chunk range [%llu - %llu]",
(unsigned long long)old_chunk,
(unsigned long long)e->old_chunk,
(unsigned long long)
e->old_chunk + dm_consecutive_chunk_count(e));
return -EINVAL;
}
dm_consecutive_chunk_count_dec(e);
return 0;
}
static int remove_single_exception_chunk(struct dm_snapshot *s)
{
struct bio *b = NULL;
int r;
chunk_t old_chunk = s->first_merging_chunk + s->num_merging_chunks - 1;
down_write(&s->lock);
do {
r = __remove_single_exception_chunk(s, old_chunk);
if (r)
goto out;
} while (old_chunk-- > s->first_merging_chunk);
b = __release_queued_bios_after_merge(s);
out:
up_write(&s->lock);
if (b)
flush_bios(b);
return r;
}
static uint64_t read_pending_exceptions_done_count(void)
{
uint64_t pending_exceptions_done;
spin_lock(&_pending_exceptions_done_spinlock);
pending_exceptions_done = _pending_exceptions_done_count;
spin_unlock(&_pending_exceptions_done_spinlock);
return pending_exceptions_done;
}
static void increment_pending_exceptions_done_count(void)
{
spin_lock(&_pending_exceptions_done_spinlock);
_pending_exceptions_done_count++;
spin_unlock(&_pending_exceptions_done_spinlock);
wake_up_all(&_pending_exceptions_done);
}
static void snapshot_merge_next_chunks(struct dm_snapshot *s)
{
int i, linear_chunks;
chunk_t old_chunk, new_chunk;
struct dm_io_region src, dest;
sector_t io_size;
uint64_t previous_count;
BUG_ON(!test_bit(RUNNING_MERGE, &s->state_bits));
if (unlikely(test_bit(SHUTDOWN_MERGE, &s->state_bits)))
goto shut;
if (!s->valid) {
DMERR("Snapshot is invalid: can't merge");
goto shut;
}
linear_chunks = s->store->type->prepare_merge(s->store, &old_chunk,
&new_chunk);
if (linear_chunks <= 0) {
if (linear_chunks < 0) {
DMERR("Read error in exception store: "
"shutting down merge");
down_write(&s->lock);
s->merge_failed = 1;
up_write(&s->lock);
}
goto shut;
}
old_chunk = old_chunk + 1 - linear_chunks;
new_chunk = new_chunk + 1 - linear_chunks;
io_size = linear_chunks * s->store->chunk_size;
dest.bdev = s->origin->bdev;
dest.sector = chunk_to_sector(s->store, old_chunk);
dest.count = min(io_size, get_dev_size(dest.bdev) - dest.sector);
src.bdev = s->cow->bdev;
src.sector = chunk_to_sector(s->store, new_chunk);
src.count = dest.count;
previous_count = read_pending_exceptions_done_count();
while (origin_write_extent(s, dest.sector, io_size)) {
wait_event(_pending_exceptions_done,
(read_pending_exceptions_done_count() !=
previous_count));
previous_count = read_pending_exceptions_done_count();
}
down_write(&s->lock);
s->first_merging_chunk = old_chunk;
s->num_merging_chunks = linear_chunks;
up_write(&s->lock);
for (i = 0; i < linear_chunks; i++)
__check_for_conflicting_io(s, old_chunk + i);
dm_kcopyd_copy(s->kcopyd_client, &src, 1, &dest, 0, merge_callback, s);
return;
shut:
merge_shutdown(s);
}
static void merge_callback(int read_err, unsigned long write_err, void *context)
{
struct dm_snapshot *s = context;
struct bio *b = NULL;
if (read_err || write_err) {
if (read_err)
DMERR("Read error: shutting down merge.");
else
DMERR("Write error: shutting down merge.");
goto shut;
}
if (s->store->type->commit_merge(s->store,
s->num_merging_chunks) < 0) {
DMERR("Write error in exception store: shutting down merge");
goto shut;
}
if (remove_single_exception_chunk(s) < 0)
goto shut;
snapshot_merge_next_chunks(s);
return;
shut:
down_write(&s->lock);
s->merge_failed = 1;
b = __release_queued_bios_after_merge(s);
up_write(&s->lock);
error_bios(b);
merge_shutdown(s);
}
static void start_merge(struct dm_snapshot *s)
{
if (!test_and_set_bit(RUNNING_MERGE, &s->state_bits))
snapshot_merge_next_chunks(s);
}
static int wait_schedule(void *ptr)
{
schedule();
return 0;
}
static void stop_merge(struct dm_snapshot *s)
{
set_bit(SHUTDOWN_MERGE, &s->state_bits);
wait_on_bit(&s->state_bits, RUNNING_MERGE, wait_schedule,
TASK_UNINTERRUPTIBLE);
clear_bit(SHUTDOWN_MERGE, &s->state_bits);
}
static int snapshot_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
struct dm_snapshot *s;
int i;
int r = -EINVAL;
char *origin_path, *cow_path;
unsigned args_used, num_flush_bios = 1;
fmode_t origin_mode = FMODE_READ;
if (argc != 4) {
ti->error = "requires exactly 4 arguments";
r = -EINVAL;
goto bad;
}
if (dm_target_is_snapshot_merge(ti)) {
num_flush_bios = 2;
origin_mode = FMODE_WRITE;
}
s = kmalloc(sizeof(*s), GFP_KERNEL);
if (!s) {
ti->error = "Cannot allocate private snapshot structure";
r = -ENOMEM;
goto bad;
}
origin_path = argv[0];
argv++;
argc--;
r = dm_get_device(ti, origin_path, origin_mode, &s->origin);
if (r) {
ti->error = "Cannot get origin device";
goto bad_origin;
}
cow_path = argv[0];
argv++;
argc--;
r = dm_get_device(ti, cow_path, dm_table_get_mode(ti->table), &s->cow);
if (r) {
ti->error = "Cannot get COW device";
goto bad_cow;
}
r = dm_exception_store_create(ti, argc, argv, s, &args_used, &s->store);
if (r) {
ti->error = "Couldn't create exception store";
r = -EINVAL;
goto bad_store;
}
argv += args_used;
argc -= args_used;
s->ti = ti;
s->valid = 1;
s->active = 0;
atomic_set(&s->pending_exceptions_count, 0);
s->exception_start_sequence = 0;
s->exception_complete_sequence = 0;
INIT_LIST_HEAD(&s->out_of_order_list);
init_rwsem(&s->lock);
INIT_LIST_HEAD(&s->list);
spin_lock_init(&s->pe_lock);
s->state_bits = 0;
s->merge_failed = 0;
s->first_merging_chunk = 0;
s->num_merging_chunks = 0;
bio_list_init(&s->bios_queued_during_merge);
if (init_hash_tables(s)) {
ti->error = "Unable to allocate hash table space";
r = -ENOMEM;
goto bad_hash_tables;
}
s->kcopyd_client = dm_kcopyd_client_create(&dm_kcopyd_throttle);
if (IS_ERR(s->kcopyd_client)) {
r = PTR_ERR(s->kcopyd_client);
ti->error = "Could not create kcopyd client";
goto bad_kcopyd;
}
s->pending_pool = mempool_create_slab_pool(MIN_IOS, pending_cache);
if (!s->pending_pool) {
ti->error = "Could not allocate mempool for pending exceptions";
r = -ENOMEM;
goto bad_pending_pool;
}
for (i = 0; i < DM_TRACKED_CHUNK_HASH_SIZE; i++)
INIT_HLIST_HEAD(&s->tracked_chunk_hash[i]);
spin_lock_init(&s->tracked_chunk_lock);
ti->private = s;
ti->num_flush_bios = num_flush_bios;
ti->per_bio_data_size = sizeof(struct dm_snap_tracked_chunk);
r = register_snapshot(s);
if (r == -ENOMEM) {
ti->error = "Snapshot origin struct allocation failed";
goto bad_load_and_register;
} else if (r < 0) {
goto bad_load_and_register;
}
if (r > 0) {
s->store->chunk_size = 0;
return 0;
}
r = s->store->type->read_metadata(s->store, dm_add_exception,
(void *)s);
if (r < 0) {
ti->error = "Failed to read snapshot metadata";
goto bad_read_metadata;
} else if (r > 0) {
s->valid = 0;
DMWARN("Snapshot is marked invalid.");
}
if (!s->store->chunk_size) {
ti->error = "Chunk size not set";
goto bad_read_metadata;
}
r = dm_set_target_max_io_len(ti, s->store->chunk_size);
if (r)
goto bad_read_metadata;
return 0;
bad_read_metadata:
unregister_snapshot(s);
bad_load_and_register:
mempool_destroy(s->pending_pool);
bad_pending_pool:
dm_kcopyd_client_destroy(s->kcopyd_client);
bad_kcopyd:
dm_exception_table_exit(&s->pending, pending_cache);
dm_exception_table_exit(&s->complete, exception_cache);
bad_hash_tables:
dm_exception_store_destroy(s->store);
bad_store:
dm_put_device(ti, s->cow);
bad_cow:
dm_put_device(ti, s->origin);
bad_origin:
kfree(s);
bad:
return r;
}
static void __free_exceptions(struct dm_snapshot *s)
{
dm_kcopyd_client_destroy(s->kcopyd_client);
s->kcopyd_client = NULL;
dm_exception_table_exit(&s->pending, pending_cache);
dm_exception_table_exit(&s->complete, exception_cache);
}
static void __handover_exceptions(struct dm_snapshot *snap_src,
struct dm_snapshot *snap_dest)
{
union {
struct dm_exception_table table_swap;
struct dm_exception_store *store_swap;
} u;
u.table_swap = snap_dest->complete;
snap_dest->complete = snap_src->complete;
snap_src->complete = u.table_swap;
u.store_swap = snap_dest->store;
snap_dest->store = snap_src->store;
snap_src->store = u.store_swap;
snap_dest->store->snap = snap_dest;
snap_src->store->snap = snap_src;
snap_dest->ti->max_io_len = snap_dest->store->chunk_size;
snap_dest->valid = snap_src->valid;
snap_src->valid = 0;
}
static void snapshot_dtr(struct dm_target *ti)
{
#ifdef CONFIG_DM_DEBUG
int i;
#endif
struct dm_snapshot *s = ti->private;
struct dm_snapshot *snap_src = NULL, *snap_dest = NULL;
down_read(&_origins_lock);
(void) __find_snapshots_sharing_cow(s, &snap_src, &snap_dest, NULL);
if (snap_src && snap_dest && (s == snap_src)) {
down_write(&snap_dest->lock);
snap_dest->valid = 0;
up_write(&snap_dest->lock);
DMERR("Cancelling snapshot handover.");
}
up_read(&_origins_lock);
if (dm_target_is_snapshot_merge(ti))
stop_merge(s);
unregister_snapshot(s);
while (atomic_read(&s->pending_exceptions_count))
msleep(1);
smp_mb();
#ifdef CONFIG_DM_DEBUG
for (i = 0; i < DM_TRACKED_CHUNK_HASH_SIZE; i++)
BUG_ON(!hlist_empty(&s->tracked_chunk_hash[i]));
#endif
__free_exceptions(s);
mempool_destroy(s->pending_pool);
dm_exception_store_destroy(s->store);
dm_put_device(ti, s->cow);
dm_put_device(ti, s->origin);
kfree(s);
}
static void flush_bios(struct bio *bio)
{
struct bio *n;
while (bio) {
n = bio->bi_next;
bio->bi_next = NULL;
generic_make_request(bio);
bio = n;
}
}
static void retry_origin_bios(struct dm_snapshot *s, struct bio *bio)
{
struct bio *n;
int r;
while (bio) {
n = bio->bi_next;
bio->bi_next = NULL;
r = do_origin(s->origin, bio);
if (r == DM_MAPIO_REMAPPED)
generic_make_request(bio);
bio = n;
}
}
static void error_bios(struct bio *bio)
{
struct bio *n;
while (bio) {
n = bio->bi_next;
bio->bi_next = NULL;
bio_io_error(bio);
bio = n;
}
}
static void __invalidate_snapshot(struct dm_snapshot *s, int err)
{
if (!s->valid)
return;
if (err == -EIO)
DMERR("Invalidating snapshot: Error reading/writing.");
else if (err == -ENOMEM)
DMERR("Invalidating snapshot: Unable to allocate exception.");
if (s->store->type->drop_snapshot)
s->store->type->drop_snapshot(s->store);
s->valid = 0;
dm_table_event(s->ti->table);
}
static void pending_complete(struct dm_snap_pending_exception *pe, int success)
{
struct dm_exception *e;
struct dm_snapshot *s = pe->snap;
struct bio *origin_bios = NULL;
struct bio *snapshot_bios = NULL;
struct bio *full_bio = NULL;
int error = 0;
if (!success) {
down_write(&s->lock);
__invalidate_snapshot(s, -EIO);
error = 1;
goto out;
}
e = alloc_completed_exception(GFP_NOIO);
if (!e) {
down_write(&s->lock);
__invalidate_snapshot(s, -ENOMEM);
error = 1;
goto out;
}
*e = pe->e;
down_write(&s->lock);
if (!s->valid) {
free_completed_exception(e);
error = 1;
goto out;
}
__check_for_conflicting_io(s, pe->e.old_chunk);
dm_insert_exception(&s->complete, e);
out:
dm_remove_exception(&pe->e);
snapshot_bios = bio_list_get(&pe->snapshot_bios);
origin_bios = bio_list_get(&pe->origin_bios);
full_bio = pe->full_bio;
if (full_bio) {
full_bio->bi_end_io = pe->full_bio_end_io;
full_bio->bi_private = pe->full_bio_private;
atomic_inc(&full_bio->bi_remaining);
}
free_pending_exception(pe);
increment_pending_exceptions_done_count();
up_write(&s->lock);
if (error) {
if (full_bio)
bio_io_error(full_bio);
error_bios(snapshot_bios);
} else {
if (full_bio)
bio_endio(full_bio, 0);
flush_bios(snapshot_bios);
}
retry_origin_bios(s, origin_bios);
}
static void commit_callback(void *context, int success)
{
struct dm_snap_pending_exception *pe = context;
pending_complete(pe, success);
}
static void complete_exception(struct dm_snap_pending_exception *pe)
{
struct dm_snapshot *s = pe->snap;
if (unlikely(pe->copy_error))
pending_complete(pe, 0);
else
s->store->type->commit_exception(s->store, &pe->e,
commit_callback, pe);
}
static void copy_callback(int read_err, unsigned long write_err, void *context)
{
struct dm_snap_pending_exception *pe = context;
struct dm_snapshot *s = pe->snap;
pe->copy_error = read_err || write_err;
if (pe->exception_sequence == s->exception_complete_sequence) {
s->exception_complete_sequence++;
complete_exception(pe);
while (!list_empty(&s->out_of_order_list)) {
pe = list_entry(s->out_of_order_list.next,
struct dm_snap_pending_exception, out_of_order_entry);
if (pe->exception_sequence != s->exception_complete_sequence)
break;
s->exception_complete_sequence++;
list_del(&pe->out_of_order_entry);
complete_exception(pe);
}
} else {
struct list_head *lh;
struct dm_snap_pending_exception *pe2;
list_for_each_prev(lh, &s->out_of_order_list) {
pe2 = list_entry(lh, struct dm_snap_pending_exception, out_of_order_entry);
if (pe2->exception_sequence < pe->exception_sequence)
break;
}
list_add(&pe->out_of_order_entry, lh);
}
}
static void start_copy(struct dm_snap_pending_exception *pe)
{
struct dm_snapshot *s = pe->snap;
struct dm_io_region src, dest;
struct block_device *bdev = s->origin->bdev;
sector_t dev_size;
dev_size = get_dev_size(bdev);
src.bdev = bdev;
src.sector = chunk_to_sector(s->store, pe->e.old_chunk);
src.count = min((sector_t)s->store->chunk_size, dev_size - src.sector);
dest.bdev = s->cow->bdev;
dest.sector = chunk_to_sector(s->store, pe->e.new_chunk);
dest.count = src.count;
dm_kcopyd_copy(s->kcopyd_client, &src, 1, &dest, 0, copy_callback, pe);
}
static void full_bio_end_io(struct bio *bio, int error)
{
void *callback_data = bio->bi_private;
dm_kcopyd_do_callback(callback_data, 0, error ? 1 : 0);
}
static void start_full_bio(struct dm_snap_pending_exception *pe,
struct bio *bio)
{
struct dm_snapshot *s = pe->snap;
void *callback_data;
pe->full_bio = bio;
pe->full_bio_end_io = bio->bi_end_io;
pe->full_bio_private = bio->bi_private;
callback_data = dm_kcopyd_prepare_callback(s->kcopyd_client,
copy_callback, pe);
bio->bi_end_io = full_bio_end_io;
bio->bi_private = callback_data;
generic_make_request(bio);
}
static struct dm_snap_pending_exception *
__lookup_pending_exception(struct dm_snapshot *s, chunk_t chunk)
{
struct dm_exception *e = dm_lookup_exception(&s->pending, chunk);
if (!e)
return NULL;
return container_of(e, struct dm_snap_pending_exception, e);
}
static struct dm_snap_pending_exception *
__find_pending_exception(struct dm_snapshot *s,
struct dm_snap_pending_exception *pe, chunk_t chunk)
{
struct dm_snap_pending_exception *pe2;
pe2 = __lookup_pending_exception(s, chunk);
if (pe2) {
free_pending_exception(pe);
return pe2;
}
pe->e.old_chunk = chunk;
bio_list_init(&pe->origin_bios);
bio_list_init(&pe->snapshot_bios);
pe->started = 0;
pe->full_bio = NULL;
if (s->store->type->prepare_exception(s->store, &pe->e)) {
free_pending_exception(pe);
return NULL;
}
pe->exception_sequence = s->exception_start_sequence++;
dm_insert_exception(&s->pending, &pe->e);
return pe;
}
static void remap_exception(struct dm_snapshot *s, struct dm_exception *e,
struct bio *bio, chunk_t chunk)
{
bio->bi_bdev = s->cow->bdev;
bio->bi_iter.bi_sector =
chunk_to_sector(s->store, dm_chunk_number(e->new_chunk) +
(chunk - e->old_chunk)) +
(bio->bi_iter.bi_sector & s->store->chunk_mask);
}
static int snapshot_map(struct dm_target *ti, struct bio *bio)
{
struct dm_exception *e;
struct dm_snapshot *s = ti->private;
int r = DM_MAPIO_REMAPPED;
chunk_t chunk;
struct dm_snap_pending_exception *pe = NULL;
init_tracked_chunk(bio);
if (bio->bi_rw & REQ_FLUSH) {
bio->bi_bdev = s->cow->bdev;
return DM_MAPIO_REMAPPED;
}
chunk = sector_to_chunk(s->store, bio->bi_iter.bi_sector);
if (!s->valid)
return -EIO;
down_write(&s->lock);
if (!s->valid) {
r = -EIO;
goto out_unlock;
}
e = dm_lookup_exception(&s->complete, chunk);
if (e) {
remap_exception(s, e, bio, chunk);
goto out_unlock;
}
if (bio_rw(bio) == WRITE) {
pe = __lookup_pending_exception(s, chunk);
if (!pe) {
up_write(&s->lock);
pe = alloc_pending_exception(s);
down_write(&s->lock);
if (!s->valid) {
free_pending_exception(pe);
r = -EIO;
goto out_unlock;
}
e = dm_lookup_exception(&s->complete, chunk);
if (e) {
free_pending_exception(pe);
remap_exception(s, e, bio, chunk);
goto out_unlock;
}
pe = __find_pending_exception(s, pe, chunk);
if (!pe) {
__invalidate_snapshot(s, -ENOMEM);
r = -EIO;
goto out_unlock;
}
}
remap_exception(s, &pe->e, bio, chunk);
r = DM_MAPIO_SUBMITTED;
if (!pe->started &&
bio->bi_iter.bi_size ==
(s->store->chunk_size << SECTOR_SHIFT)) {
pe->started = 1;
up_write(&s->lock);
start_full_bio(pe, bio);
goto out;
}
bio_list_add(&pe->snapshot_bios, bio);
if (!pe->started) {
pe->started = 1;
up_write(&s->lock);
start_copy(pe);
goto out;
}
} else {
bio->bi_bdev = s->origin->bdev;
track_chunk(s, bio, chunk);
}
out_unlock:
up_write(&s->lock);
out:
return r;
}
static int snapshot_merge_map(struct dm_target *ti, struct bio *bio)
{
struct dm_exception *e;
struct dm_snapshot *s = ti->private;
int r = DM_MAPIO_REMAPPED;
chunk_t chunk;
init_tracked_chunk(bio);
if (bio->bi_rw & REQ_FLUSH) {
if (!dm_bio_get_target_bio_nr(bio))
bio->bi_bdev = s->origin->bdev;
else
bio->bi_bdev = s->cow->bdev;
return DM_MAPIO_REMAPPED;
}
chunk = sector_to_chunk(s->store, bio->bi_iter.bi_sector);
down_write(&s->lock);
if (!s->valid)
goto redirect_to_origin;
e = dm_lookup_exception(&s->complete, chunk);
if (e) {
if (bio_rw(bio) == WRITE &&
chunk >= s->first_merging_chunk &&
chunk < (s->first_merging_chunk +
s->num_merging_chunks)) {
bio->bi_bdev = s->origin->bdev;
bio_list_add(&s->bios_queued_during_merge, bio);
r = DM_MAPIO_SUBMITTED;
goto out_unlock;
}
remap_exception(s, e, bio, chunk);
if (bio_rw(bio) == WRITE)
track_chunk(s, bio, chunk);
goto out_unlock;
}
redirect_to_origin:
bio->bi_bdev = s->origin->bdev;
if (bio_rw(bio) == WRITE) {
up_write(&s->lock);
return do_origin(s->origin, bio);
}
out_unlock:
up_write(&s->lock);
return r;
}
static int snapshot_end_io(struct dm_target *ti, struct bio *bio, int error)
{
struct dm_snapshot *s = ti->private;
if (is_bio_tracked(bio))
stop_tracking_chunk(s, bio);
return 0;
}
static void snapshot_merge_presuspend(struct dm_target *ti)
{
struct dm_snapshot *s = ti->private;
stop_merge(s);
}
static int snapshot_preresume(struct dm_target *ti)
{
int r = 0;
struct dm_snapshot *s = ti->private;
struct dm_snapshot *snap_src = NULL, *snap_dest = NULL;
down_read(&_origins_lock);
(void) __find_snapshots_sharing_cow(s, &snap_src, &snap_dest, NULL);
if (snap_src && snap_dest) {
down_read(&snap_src->lock);
if (s == snap_src) {
DMERR("Unable to resume snapshot source until "
"handover completes.");
r = -EINVAL;
} else if (!dm_suspended(snap_src->ti)) {
DMERR("Unable to perform snapshot handover until "
"source is suspended.");
r = -EINVAL;
}
up_read(&snap_src->lock);
}
up_read(&_origins_lock);
return r;
}
static void snapshot_resume(struct dm_target *ti)
{
struct dm_snapshot *s = ti->private;
struct dm_snapshot *snap_src = NULL, *snap_dest = NULL;
down_read(&_origins_lock);
(void) __find_snapshots_sharing_cow(s, &snap_src, &snap_dest, NULL);
if (snap_src && snap_dest) {
down_write(&snap_src->lock);
down_write_nested(&snap_dest->lock, SINGLE_DEPTH_NESTING);
__handover_exceptions(snap_src, snap_dest);
up_write(&snap_dest->lock);
up_write(&snap_src->lock);
}
up_read(&_origins_lock);
reregister_snapshot(s);
down_write(&s->lock);
s->active = 1;
up_write(&s->lock);
}
static uint32_t get_origin_minimum_chunksize(struct block_device *bdev)
{
uint32_t min_chunksize;
down_read(&_origins_lock);
min_chunksize = __minimum_chunk_size(__lookup_origin(bdev));
up_read(&_origins_lock);
return min_chunksize;
}
static void snapshot_merge_resume(struct dm_target *ti)
{
struct dm_snapshot *s = ti->private;
snapshot_resume(ti);
ti->max_io_len = get_origin_minimum_chunksize(s->origin->bdev);
start_merge(s);
}
static void snapshot_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
unsigned sz = 0;
struct dm_snapshot *snap = ti->private;
switch (type) {
case STATUSTYPE_INFO:
down_write(&snap->lock);
if (!snap->valid)
DMEMIT("Invalid");
else if (snap->merge_failed)
DMEMIT("Merge failed");
else {
if (snap->store->type->usage) {
sector_t total_sectors, sectors_allocated,
metadata_sectors;
snap->store->type->usage(snap->store,
&total_sectors,
&sectors_allocated,
&metadata_sectors);
DMEMIT("%llu/%llu %llu",
(unsigned long long)sectors_allocated,
(unsigned long long)total_sectors,
(unsigned long long)metadata_sectors);
}
else
DMEMIT("Unknown");
}
up_write(&snap->lock);
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %s", snap->origin->name, snap->cow->name);
snap->store->type->status(snap->store, type, result + sz,
maxlen - sz);
break;
}
}
static int snapshot_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
struct dm_snapshot *snap = ti->private;
int r;
r = fn(ti, snap->origin, 0, ti->len, data);
if (!r)
r = fn(ti, snap->cow, 0, get_dev_size(snap->cow->bdev), data);
return r;
}
static int __origin_write(struct list_head *snapshots, sector_t sector,
struct bio *bio)
{
int r = DM_MAPIO_REMAPPED;
struct dm_snapshot *snap;
struct dm_exception *e;
struct dm_snap_pending_exception *pe;
struct dm_snap_pending_exception *pe_to_start_now = NULL;
struct dm_snap_pending_exception *pe_to_start_last = NULL;
chunk_t chunk;
list_for_each_entry (snap, snapshots, list) {
if (dm_target_is_snapshot_merge(snap->ti))
continue;
down_write(&snap->lock);
if (!snap->valid || !snap->active)
goto next_snapshot;
if (sector >= dm_table_get_size(snap->ti->table))
goto next_snapshot;
chunk = sector_to_chunk(snap->store, sector);
e = dm_lookup_exception(&snap->complete, chunk);
if (e)
goto next_snapshot;
pe = __lookup_pending_exception(snap, chunk);
if (!pe) {
up_write(&snap->lock);
pe = alloc_pending_exception(snap);
down_write(&snap->lock);
if (!snap->valid) {
free_pending_exception(pe);
goto next_snapshot;
}
e = dm_lookup_exception(&snap->complete, chunk);
if (e) {
free_pending_exception(pe);
goto next_snapshot;
}
pe = __find_pending_exception(snap, pe, chunk);
if (!pe) {
__invalidate_snapshot(snap, -ENOMEM);
goto next_snapshot;
}
}
r = DM_MAPIO_SUBMITTED;
if (bio) {
bio_list_add(&pe->origin_bios, bio);
bio = NULL;
if (!pe->started) {
pe->started = 1;
pe_to_start_last = pe;
}
}
if (!pe->started) {
pe->started = 1;
pe_to_start_now = pe;
}
next_snapshot:
up_write(&snap->lock);
if (pe_to_start_now) {
start_copy(pe_to_start_now);
pe_to_start_now = NULL;
}
}
if (pe_to_start_last)
start_copy(pe_to_start_last);
return r;
}
static int do_origin(struct dm_dev *origin, struct bio *bio)
{
struct origin *o;
int r = DM_MAPIO_REMAPPED;
down_read(&_origins_lock);
o = __lookup_origin(origin->bdev);
if (o)
r = __origin_write(&o->snapshots, bio->bi_iter.bi_sector, bio);
up_read(&_origins_lock);
return r;
}
static int origin_write_extent(struct dm_snapshot *merging_snap,
sector_t sector, unsigned size)
{
int must_wait = 0;
sector_t n;
struct origin *o;
down_read(&_origins_lock);
o = __lookup_origin(merging_snap->origin->bdev);
for (n = 0; n < size; n += merging_snap->ti->max_io_len)
if (__origin_write(&o->snapshots, sector + n, NULL) ==
DM_MAPIO_SUBMITTED)
must_wait = 1;
up_read(&_origins_lock);
return must_wait;
}
static int origin_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
int r;
struct dm_origin *o;
if (argc != 1) {
ti->error = "origin: incorrect number of arguments";
return -EINVAL;
}
o = kmalloc(sizeof(struct dm_origin), GFP_KERNEL);
if (!o) {
ti->error = "Cannot allocate private origin structure";
r = -ENOMEM;
goto bad_alloc;
}
r = dm_get_device(ti, argv[0], dm_table_get_mode(ti->table), &o->dev);
if (r) {
ti->error = "Cannot get target device";
goto bad_open;
}
ti->private = o;
ti->num_flush_bios = 1;
return 0;
bad_open:
kfree(o);
bad_alloc:
return r;
}
static void origin_dtr(struct dm_target *ti)
{
struct dm_origin *o = ti->private;
dm_put_device(ti, o->dev);
kfree(o);
}
static int origin_map(struct dm_target *ti, struct bio *bio)
{
struct dm_origin *o = ti->private;
unsigned available_sectors;
bio->bi_bdev = o->dev->bdev;
if (unlikely(bio->bi_rw & REQ_FLUSH))
return DM_MAPIO_REMAPPED;
if (bio_rw(bio) != WRITE)
return DM_MAPIO_REMAPPED;
available_sectors = o->split_boundary -
((unsigned)bio->bi_iter.bi_sector & (o->split_boundary - 1));
if (bio_sectors(bio) > available_sectors)
dm_accept_partial_bio(bio, available_sectors);
return do_origin(o->dev, bio);
}
static void origin_resume(struct dm_target *ti)
{
struct dm_origin *o = ti->private;
o->split_boundary = get_origin_minimum_chunksize(o->dev->bdev);
}
static void origin_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
struct dm_origin *o = ti->private;
switch (type) {
case STATUSTYPE_INFO:
result[0] = '\0';
break;
case STATUSTYPE_TABLE:
snprintf(result, maxlen, "%s", o->dev->name);
break;
}
}
static int origin_merge(struct dm_target *ti, struct bvec_merge_data *bvm,
struct bio_vec *biovec, int max_size)
{
struct dm_origin *o = ti->private;
struct request_queue *q = bdev_get_queue(o->dev->bdev);
if (!q->merge_bvec_fn)
return max_size;
bvm->bi_bdev = o->dev->bdev;
return min(max_size, q->merge_bvec_fn(q, bvm, biovec));
}
static int origin_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
struct dm_origin *o = ti->private;
return fn(ti, o->dev, 0, ti->len, data);
}
static int __init dm_snapshot_init(void)
{
int r;
r = dm_exception_store_init();
if (r) {
DMERR("Failed to initialize exception stores");
return r;
}
r = dm_register_target(&snapshot_target);
if (r < 0) {
DMERR("snapshot target register failed %d", r);
goto bad_register_snapshot_target;
}
r = dm_register_target(&origin_target);
if (r < 0) {
DMERR("Origin target register failed %d", r);
goto bad_register_origin_target;
}
r = dm_register_target(&merge_target);
if (r < 0) {
DMERR("Merge target register failed %d", r);
goto bad_register_merge_target;
}
r = init_origin_hash();
if (r) {
DMERR("init_origin_hash failed.");
goto bad_origin_hash;
}
exception_cache = KMEM_CACHE(dm_exception, 0);
if (!exception_cache) {
DMERR("Couldn't create exception cache.");
r = -ENOMEM;
goto bad_exception_cache;
}
pending_cache = KMEM_CACHE(dm_snap_pending_exception, 0);
if (!pending_cache) {
DMERR("Couldn't create pending cache.");
r = -ENOMEM;
goto bad_pending_cache;
}
return 0;
bad_pending_cache:
kmem_cache_destroy(exception_cache);
bad_exception_cache:
exit_origin_hash();
bad_origin_hash:
dm_unregister_target(&merge_target);
bad_register_merge_target:
dm_unregister_target(&origin_target);
bad_register_origin_target:
dm_unregister_target(&snapshot_target);
bad_register_snapshot_target:
dm_exception_store_exit();
return r;
}
static void __exit dm_snapshot_exit(void)
{
dm_unregister_target(&snapshot_target);
dm_unregister_target(&origin_target);
dm_unregister_target(&merge_target);
exit_origin_hash();
kmem_cache_destroy(pending_cache);
kmem_cache_destroy(exception_cache);
dm_exception_store_exit();
}
