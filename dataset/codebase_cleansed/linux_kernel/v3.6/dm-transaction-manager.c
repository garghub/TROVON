static int is_shadow(struct dm_transaction_manager *tm, dm_block_t b)
{
int r = 0;
unsigned bucket = dm_hash_block(b, HASH_MASK);
struct shadow_info *si;
struct hlist_node *n;
spin_lock(&tm->lock);
hlist_for_each_entry(si, n, tm->buckets + bucket, hlist)
if (si->where == b) {
r = 1;
break;
}
spin_unlock(&tm->lock);
return r;
}
static void insert_shadow(struct dm_transaction_manager *tm, dm_block_t b)
{
unsigned bucket;
struct shadow_info *si;
si = kmalloc(sizeof(*si), GFP_NOIO);
if (si) {
si->where = b;
bucket = dm_hash_block(b, HASH_MASK);
spin_lock(&tm->lock);
hlist_add_head(&si->hlist, tm->buckets + bucket);
spin_unlock(&tm->lock);
}
}
static void wipe_shadow_table(struct dm_transaction_manager *tm)
{
struct shadow_info *si;
struct hlist_node *n, *tmp;
struct hlist_head *bucket;
int i;
spin_lock(&tm->lock);
for (i = 0; i < HASH_SIZE; i++) {
bucket = tm->buckets + i;
hlist_for_each_entry_safe(si, n, tmp, bucket, hlist)
kfree(si);
INIT_HLIST_HEAD(bucket);
}
spin_unlock(&tm->lock);
}
static struct dm_transaction_manager *dm_tm_create(struct dm_block_manager *bm,
struct dm_space_map *sm)
{
int i;
struct dm_transaction_manager *tm;
tm = kmalloc(sizeof(*tm), GFP_KERNEL);
if (!tm)
return ERR_PTR(-ENOMEM);
tm->is_clone = 0;
tm->real = NULL;
tm->bm = bm;
tm->sm = sm;
spin_lock_init(&tm->lock);
for (i = 0; i < HASH_SIZE; i++)
INIT_HLIST_HEAD(tm->buckets + i);
return tm;
}
struct dm_transaction_manager *dm_tm_create_non_blocking_clone(struct dm_transaction_manager *real)
{
struct dm_transaction_manager *tm;
tm = kmalloc(sizeof(*tm), GFP_KERNEL);
if (tm) {
tm->is_clone = 1;
tm->real = real;
}
return tm;
}
void dm_tm_destroy(struct dm_transaction_manager *tm)
{
if (!tm->is_clone)
wipe_shadow_table(tm);
kfree(tm);
}
int dm_tm_pre_commit(struct dm_transaction_manager *tm)
{
int r;
if (tm->is_clone)
return -EWOULDBLOCK;
r = dm_sm_commit(tm->sm);
if (r < 0)
return r;
return 0;
}
int dm_tm_commit(struct dm_transaction_manager *tm, struct dm_block *root)
{
if (tm->is_clone)
return -EWOULDBLOCK;
wipe_shadow_table(tm);
return dm_bm_flush_and_unlock(tm->bm, root);
}
int dm_tm_new_block(struct dm_transaction_manager *tm,
struct dm_block_validator *v,
struct dm_block **result)
{
int r;
dm_block_t new_block;
if (tm->is_clone)
return -EWOULDBLOCK;
r = dm_sm_new_block(tm->sm, &new_block);
if (r < 0)
return r;
r = dm_bm_write_lock_zero(tm->bm, new_block, v, result);
if (r < 0) {
dm_sm_dec_block(tm->sm, new_block);
return r;
}
insert_shadow(tm, new_block);
return 0;
}
static int __shadow_block(struct dm_transaction_manager *tm, dm_block_t orig,
struct dm_block_validator *v,
struct dm_block **result)
{
int r;
dm_block_t new;
struct dm_block *orig_block;
r = dm_sm_new_block(tm->sm, &new);
if (r < 0)
return r;
r = dm_sm_dec_block(tm->sm, orig);
if (r < 0)
return r;
r = dm_bm_read_lock(tm->bm, orig, v, &orig_block);
if (r < 0)
return r;
r = dm_bm_write_lock_zero(tm->bm, new, v, result);
if (r) {
dm_bm_unlock(orig_block);
return r;
}
memcpy(dm_block_data(*result), dm_block_data(orig_block),
dm_bm_block_size(tm->bm));
dm_bm_unlock(orig_block);
return r;
}
int dm_tm_shadow_block(struct dm_transaction_manager *tm, dm_block_t orig,
struct dm_block_validator *v, struct dm_block **result,
int *inc_children)
{
int r;
if (tm->is_clone)
return -EWOULDBLOCK;
r = dm_sm_count_is_more_than_one(tm->sm, orig, inc_children);
if (r < 0)
return r;
if (is_shadow(tm, orig) && !*inc_children)
return dm_bm_write_lock(tm->bm, orig, v, result);
r = __shadow_block(tm, orig, v, result);
if (r < 0)
return r;
insert_shadow(tm, dm_block_location(*result));
return r;
}
int dm_tm_read_lock(struct dm_transaction_manager *tm, dm_block_t b,
struct dm_block_validator *v,
struct dm_block **blk)
{
if (tm->is_clone)
return dm_bm_read_try_lock(tm->real->bm, b, v, blk);
return dm_bm_read_lock(tm->bm, b, v, blk);
}
int dm_tm_unlock(struct dm_transaction_manager *tm, struct dm_block *b)
{
return dm_bm_unlock(b);
}
void dm_tm_inc(struct dm_transaction_manager *tm, dm_block_t b)
{
BUG_ON(tm->is_clone);
dm_sm_inc_block(tm->sm, b);
}
void dm_tm_dec(struct dm_transaction_manager *tm, dm_block_t b)
{
BUG_ON(tm->is_clone);
dm_sm_dec_block(tm->sm, b);
}
int dm_tm_ref(struct dm_transaction_manager *tm, dm_block_t b,
uint32_t *result)
{
if (tm->is_clone)
return -EWOULDBLOCK;
return dm_sm_get_count(tm->sm, b, result);
}
struct dm_block_manager *dm_tm_get_bm(struct dm_transaction_manager *tm)
{
return tm->bm;
}
static int dm_tm_create_internal(struct dm_block_manager *bm,
dm_block_t sb_location,
struct dm_transaction_manager **tm,
struct dm_space_map **sm,
int create,
void *sm_root, size_t sm_len)
{
int r;
*sm = dm_sm_metadata_init();
if (IS_ERR(*sm))
return PTR_ERR(*sm);
*tm = dm_tm_create(bm, *sm);
if (IS_ERR(*tm)) {
dm_sm_destroy(*sm);
return PTR_ERR(*tm);
}
if (create) {
r = dm_sm_metadata_create(*sm, *tm, dm_bm_nr_blocks(bm),
sb_location);
if (r) {
DMERR("couldn't create metadata space map");
goto bad;
}
} else {
r = dm_sm_metadata_open(*sm, *tm, sm_root, sm_len);
if (r) {
DMERR("couldn't open metadata space map");
goto bad;
}
}
return 0;
bad:
dm_tm_destroy(*tm);
dm_sm_destroy(*sm);
return r;
}
int dm_tm_create_with_sm(struct dm_block_manager *bm, dm_block_t sb_location,
struct dm_transaction_manager **tm,
struct dm_space_map **sm)
{
return dm_tm_create_internal(bm, sb_location, tm, sm, 1, NULL, 0);
}
int dm_tm_open_with_sm(struct dm_block_manager *bm, dm_block_t sb_location,
void *sm_root, size_t root_len,
struct dm_transaction_manager **tm,
struct dm_space_map **sm)
{
return dm_tm_create_internal(bm, sb_location, tm, sm, 0, sm_root, root_len);
}
