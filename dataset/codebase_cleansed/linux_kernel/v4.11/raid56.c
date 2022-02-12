int btrfs_alloc_stripe_hash_table(struct btrfs_fs_info *info)
{
struct btrfs_stripe_hash_table *table;
struct btrfs_stripe_hash_table *x;
struct btrfs_stripe_hash *cur;
struct btrfs_stripe_hash *h;
int num_entries = 1 << BTRFS_STRIPE_HASH_TABLE_BITS;
int i;
int table_size;
if (info->stripe_hash_table)
return 0;
table_size = sizeof(*table) + sizeof(*h) * num_entries;
table = kzalloc(table_size, GFP_KERNEL | __GFP_NOWARN | __GFP_REPEAT);
if (!table) {
table = vzalloc(table_size);
if (!table)
return -ENOMEM;
}
spin_lock_init(&table->cache_lock);
INIT_LIST_HEAD(&table->stripe_cache);
h = table->table;
for (i = 0; i < num_entries; i++) {
cur = h + i;
INIT_LIST_HEAD(&cur->hash_list);
spin_lock_init(&cur->lock);
init_waitqueue_head(&cur->wait);
}
x = cmpxchg(&info->stripe_hash_table, NULL, table);
if (x)
kvfree(x);
return 0;
}
static void cache_rbio_pages(struct btrfs_raid_bio *rbio)
{
int i;
char *s;
char *d;
int ret;
ret = alloc_rbio_pages(rbio);
if (ret)
return;
for (i = 0; i < rbio->nr_pages; i++) {
if (!rbio->bio_pages[i])
continue;
s = kmap(rbio->bio_pages[i]);
d = kmap(rbio->stripe_pages[i]);
memcpy(d, s, PAGE_SIZE);
kunmap(rbio->bio_pages[i]);
kunmap(rbio->stripe_pages[i]);
SetPageUptodate(rbio->stripe_pages[i]);
}
set_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
}
static int rbio_bucket(struct btrfs_raid_bio *rbio)
{
u64 num = rbio->bbio->raid_map[0];
return hash_64(num >> 16, BTRFS_STRIPE_HASH_TABLE_BITS);
}
static void steal_rbio(struct btrfs_raid_bio *src, struct btrfs_raid_bio *dest)
{
int i;
struct page *s;
struct page *d;
if (!test_bit(RBIO_CACHE_READY_BIT, &src->flags))
return;
for (i = 0; i < dest->nr_pages; i++) {
s = src->stripe_pages[i];
if (!s || !PageUptodate(s)) {
continue;
}
d = dest->stripe_pages[i];
if (d)
__free_page(d);
dest->stripe_pages[i] = s;
src->stripe_pages[i] = NULL;
}
}
static void merge_rbio(struct btrfs_raid_bio *dest,
struct btrfs_raid_bio *victim)
{
bio_list_merge(&dest->bio_list, &victim->bio_list);
dest->bio_list_bytes += victim->bio_list_bytes;
dest->generic_bio_cnt += victim->generic_bio_cnt;
bio_list_init(&victim->bio_list);
}
static void __remove_rbio_from_cache(struct btrfs_raid_bio *rbio)
{
int bucket = rbio_bucket(rbio);
struct btrfs_stripe_hash_table *table;
struct btrfs_stripe_hash *h;
int freeit = 0;
if (!test_bit(RBIO_CACHE_BIT, &rbio->flags))
return;
table = rbio->fs_info->stripe_hash_table;
h = table->table + bucket;
spin_lock(&h->lock);
spin_lock(&rbio->bio_list_lock);
if (test_and_clear_bit(RBIO_CACHE_BIT, &rbio->flags)) {
list_del_init(&rbio->stripe_cache);
table->cache_size -= 1;
freeit = 1;
if (bio_list_empty(&rbio->bio_list)) {
if (!list_empty(&rbio->hash_list)) {
list_del_init(&rbio->hash_list);
atomic_dec(&rbio->refs);
BUG_ON(!list_empty(&rbio->plug_list));
}
}
}
spin_unlock(&rbio->bio_list_lock);
spin_unlock(&h->lock);
if (freeit)
__free_raid_bio(rbio);
}
static void remove_rbio_from_cache(struct btrfs_raid_bio *rbio)
{
struct btrfs_stripe_hash_table *table;
unsigned long flags;
if (!test_bit(RBIO_CACHE_BIT, &rbio->flags))
return;
table = rbio->fs_info->stripe_hash_table;
spin_lock_irqsave(&table->cache_lock, flags);
__remove_rbio_from_cache(rbio);
spin_unlock_irqrestore(&table->cache_lock, flags);
}
static void btrfs_clear_rbio_cache(struct btrfs_fs_info *info)
{
struct btrfs_stripe_hash_table *table;
unsigned long flags;
struct btrfs_raid_bio *rbio;
table = info->stripe_hash_table;
spin_lock_irqsave(&table->cache_lock, flags);
while (!list_empty(&table->stripe_cache)) {
rbio = list_entry(table->stripe_cache.next,
struct btrfs_raid_bio,
stripe_cache);
__remove_rbio_from_cache(rbio);
}
spin_unlock_irqrestore(&table->cache_lock, flags);
}
void btrfs_free_stripe_hash_table(struct btrfs_fs_info *info)
{
if (!info->stripe_hash_table)
return;
btrfs_clear_rbio_cache(info);
kvfree(info->stripe_hash_table);
info->stripe_hash_table = NULL;
}
static void cache_rbio(struct btrfs_raid_bio *rbio)
{
struct btrfs_stripe_hash_table *table;
unsigned long flags;
if (!test_bit(RBIO_CACHE_READY_BIT, &rbio->flags))
return;
table = rbio->fs_info->stripe_hash_table;
spin_lock_irqsave(&table->cache_lock, flags);
spin_lock(&rbio->bio_list_lock);
if (!test_and_set_bit(RBIO_CACHE_BIT, &rbio->flags))
atomic_inc(&rbio->refs);
if (!list_empty(&rbio->stripe_cache)){
list_move(&rbio->stripe_cache, &table->stripe_cache);
} else {
list_add(&rbio->stripe_cache, &table->stripe_cache);
table->cache_size += 1;
}
spin_unlock(&rbio->bio_list_lock);
if (table->cache_size > RBIO_CACHE_SIZE) {
struct btrfs_raid_bio *found;
found = list_entry(table->stripe_cache.prev,
struct btrfs_raid_bio,
stripe_cache);
if (found != rbio)
__remove_rbio_from_cache(found);
}
spin_unlock_irqrestore(&table->cache_lock, flags);
}
static void run_xor(void **pages, int src_cnt, ssize_t len)
{
int src_off = 0;
int xor_src_cnt = 0;
void *dest = pages[src_cnt];
while(src_cnt > 0) {
xor_src_cnt = min(src_cnt, MAX_XOR_BLOCKS);
xor_blocks(xor_src_cnt, len, dest, pages + src_off);
src_cnt -= xor_src_cnt;
src_off += xor_src_cnt;
}
}
static int __rbio_is_full(struct btrfs_raid_bio *rbio)
{
unsigned long size = rbio->bio_list_bytes;
int ret = 1;
if (size != rbio->nr_data * rbio->stripe_len)
ret = 0;
BUG_ON(size > rbio->nr_data * rbio->stripe_len);
return ret;
}
static int rbio_is_full(struct btrfs_raid_bio *rbio)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&rbio->bio_list_lock, flags);
ret = __rbio_is_full(rbio);
spin_unlock_irqrestore(&rbio->bio_list_lock, flags);
return ret;
}
static int rbio_can_merge(struct btrfs_raid_bio *last,
struct btrfs_raid_bio *cur)
{
if (test_bit(RBIO_RMW_LOCKED_BIT, &last->flags) ||
test_bit(RBIO_RMW_LOCKED_BIT, &cur->flags))
return 0;
if (test_bit(RBIO_CACHE_BIT, &last->flags) ||
test_bit(RBIO_CACHE_BIT, &cur->flags))
return 0;
if (last->bbio->raid_map[0] !=
cur->bbio->raid_map[0])
return 0;
if (last->operation != cur->operation)
return 0;
if (last->operation == BTRFS_RBIO_PARITY_SCRUB ||
cur->operation == BTRFS_RBIO_PARITY_SCRUB)
return 0;
if (last->operation == BTRFS_RBIO_REBUILD_MISSING ||
cur->operation == BTRFS_RBIO_REBUILD_MISSING)
return 0;
return 1;
}
static int rbio_stripe_page_index(struct btrfs_raid_bio *rbio, int stripe,
int index)
{
return stripe * rbio->stripe_npages + index;
}
static struct page *rbio_stripe_page(struct btrfs_raid_bio *rbio, int stripe,
int index)
{
return rbio->stripe_pages[rbio_stripe_page_index(rbio, stripe, index)];
}
static struct page *rbio_pstripe_page(struct btrfs_raid_bio *rbio, int index)
{
return rbio_stripe_page(rbio, rbio->nr_data, index);
}
static struct page *rbio_qstripe_page(struct btrfs_raid_bio *rbio, int index)
{
if (rbio->nr_data + 1 == rbio->real_stripes)
return NULL;
return rbio_stripe_page(rbio, rbio->nr_data + 1, index);
}
static noinline int lock_stripe_add(struct btrfs_raid_bio *rbio)
{
int bucket = rbio_bucket(rbio);
struct btrfs_stripe_hash *h = rbio->fs_info->stripe_hash_table->table + bucket;
struct btrfs_raid_bio *cur;
struct btrfs_raid_bio *pending;
unsigned long flags;
DEFINE_WAIT(wait);
struct btrfs_raid_bio *freeit = NULL;
struct btrfs_raid_bio *cache_drop = NULL;
int ret = 0;
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(cur, &h->hash_list, hash_list) {
if (cur->bbio->raid_map[0] == rbio->bbio->raid_map[0]) {
spin_lock(&cur->bio_list_lock);
if (bio_list_empty(&cur->bio_list) &&
list_empty(&cur->plug_list) &&
test_bit(RBIO_CACHE_BIT, &cur->flags) &&
!test_bit(RBIO_RMW_LOCKED_BIT, &cur->flags)) {
list_del_init(&cur->hash_list);
atomic_dec(&cur->refs);
steal_rbio(cur, rbio);
cache_drop = cur;
spin_unlock(&cur->bio_list_lock);
goto lockit;
}
if (rbio_can_merge(cur, rbio)) {
merge_rbio(cur, rbio);
spin_unlock(&cur->bio_list_lock);
freeit = rbio;
ret = 1;
goto out;
}
list_for_each_entry(pending, &cur->plug_list,
plug_list) {
if (rbio_can_merge(pending, rbio)) {
merge_rbio(pending, rbio);
spin_unlock(&cur->bio_list_lock);
freeit = rbio;
ret = 1;
goto out;
}
}
list_add_tail(&rbio->plug_list, &cur->plug_list);
spin_unlock(&cur->bio_list_lock);
ret = 1;
goto out;
}
}
lockit:
atomic_inc(&rbio->refs);
list_add(&rbio->hash_list, &h->hash_list);
out:
spin_unlock_irqrestore(&h->lock, flags);
if (cache_drop)
remove_rbio_from_cache(cache_drop);
if (freeit)
__free_raid_bio(freeit);
return ret;
}
static noinline void unlock_stripe(struct btrfs_raid_bio *rbio)
{
int bucket;
struct btrfs_stripe_hash *h;
unsigned long flags;
int keep_cache = 0;
bucket = rbio_bucket(rbio);
h = rbio->fs_info->stripe_hash_table->table + bucket;
if (list_empty(&rbio->plug_list))
cache_rbio(rbio);
spin_lock_irqsave(&h->lock, flags);
spin_lock(&rbio->bio_list_lock);
if (!list_empty(&rbio->hash_list)) {
if (list_empty(&rbio->plug_list) &&
test_bit(RBIO_CACHE_BIT, &rbio->flags)) {
keep_cache = 1;
clear_bit(RBIO_RMW_LOCKED_BIT, &rbio->flags);
BUG_ON(!bio_list_empty(&rbio->bio_list));
goto done;
}
list_del_init(&rbio->hash_list);
atomic_dec(&rbio->refs);
if (!list_empty(&rbio->plug_list)) {
struct btrfs_raid_bio *next;
struct list_head *head = rbio->plug_list.next;
next = list_entry(head, struct btrfs_raid_bio,
plug_list);
list_del_init(&rbio->plug_list);
list_add(&next->hash_list, &h->hash_list);
atomic_inc(&next->refs);
spin_unlock(&rbio->bio_list_lock);
spin_unlock_irqrestore(&h->lock, flags);
if (next->operation == BTRFS_RBIO_READ_REBUILD)
async_read_rebuild(next);
else if (next->operation == BTRFS_RBIO_REBUILD_MISSING) {
steal_rbio(rbio, next);
async_read_rebuild(next);
} else if (next->operation == BTRFS_RBIO_WRITE) {
steal_rbio(rbio, next);
async_rmw_stripe(next);
} else if (next->operation == BTRFS_RBIO_PARITY_SCRUB) {
steal_rbio(rbio, next);
async_scrub_parity(next);
}
goto done_nolock;
} else if (waitqueue_active(&h->wait)) {
spin_unlock(&rbio->bio_list_lock);
spin_unlock_irqrestore(&h->lock, flags);
wake_up(&h->wait);
goto done_nolock;
}
}
done:
spin_unlock(&rbio->bio_list_lock);
spin_unlock_irqrestore(&h->lock, flags);
done_nolock:
if (!keep_cache)
remove_rbio_from_cache(rbio);
}
static void __free_raid_bio(struct btrfs_raid_bio *rbio)
{
int i;
WARN_ON(atomic_read(&rbio->refs) < 0);
if (!atomic_dec_and_test(&rbio->refs))
return;
WARN_ON(!list_empty(&rbio->stripe_cache));
WARN_ON(!list_empty(&rbio->hash_list));
WARN_ON(!bio_list_empty(&rbio->bio_list));
for (i = 0; i < rbio->nr_pages; i++) {
if (rbio->stripe_pages[i]) {
__free_page(rbio->stripe_pages[i]);
rbio->stripe_pages[i] = NULL;
}
}
btrfs_put_bbio(rbio->bbio);
kfree(rbio);
}
static void free_raid_bio(struct btrfs_raid_bio *rbio)
{
unlock_stripe(rbio);
__free_raid_bio(rbio);
}
static void rbio_orig_end_io(struct btrfs_raid_bio *rbio, int err)
{
struct bio *cur = bio_list_get(&rbio->bio_list);
struct bio *next;
if (rbio->generic_bio_cnt)
btrfs_bio_counter_sub(rbio->fs_info, rbio->generic_bio_cnt);
free_raid_bio(rbio);
while (cur) {
next = cur->bi_next;
cur->bi_next = NULL;
cur->bi_error = err;
bio_endio(cur);
cur = next;
}
}
static void raid_write_end_io(struct bio *bio)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
int err = bio->bi_error;
int max_errors;
if (err)
fail_bio_stripe(rbio, bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->stripes_pending))
return;
err = 0;
max_errors = (rbio->operation == BTRFS_RBIO_PARITY_SCRUB) ?
0 : rbio->bbio->max_errors;
if (atomic_read(&rbio->error) > max_errors)
err = -EIO;
rbio_orig_end_io(rbio, err);
}
static struct page *page_in_rbio(struct btrfs_raid_bio *rbio,
int index, int pagenr, int bio_list_only)
{
int chunk_page;
struct page *p = NULL;
chunk_page = index * (rbio->stripe_len >> PAGE_SHIFT) + pagenr;
spin_lock_irq(&rbio->bio_list_lock);
p = rbio->bio_pages[chunk_page];
spin_unlock_irq(&rbio->bio_list_lock);
if (p || bio_list_only)
return p;
return rbio->stripe_pages[chunk_page];
}
static unsigned long rbio_nr_pages(unsigned long stripe_len, int nr_stripes)
{
return DIV_ROUND_UP(stripe_len, PAGE_SIZE) * nr_stripes;
}
static struct btrfs_raid_bio *alloc_rbio(struct btrfs_fs_info *fs_info,
struct btrfs_bio *bbio,
u64 stripe_len)
{
struct btrfs_raid_bio *rbio;
int nr_data = 0;
int real_stripes = bbio->num_stripes - bbio->num_tgtdevs;
int num_pages = rbio_nr_pages(stripe_len, real_stripes);
int stripe_npages = DIV_ROUND_UP(stripe_len, PAGE_SIZE);
void *p;
rbio = kzalloc(sizeof(*rbio) + num_pages * sizeof(struct page *) * 2 +
DIV_ROUND_UP(stripe_npages, BITS_PER_LONG) *
sizeof(long), GFP_NOFS);
if (!rbio)
return ERR_PTR(-ENOMEM);
bio_list_init(&rbio->bio_list);
INIT_LIST_HEAD(&rbio->plug_list);
spin_lock_init(&rbio->bio_list_lock);
INIT_LIST_HEAD(&rbio->stripe_cache);
INIT_LIST_HEAD(&rbio->hash_list);
rbio->bbio = bbio;
rbio->fs_info = fs_info;
rbio->stripe_len = stripe_len;
rbio->nr_pages = num_pages;
rbio->real_stripes = real_stripes;
rbio->stripe_npages = stripe_npages;
rbio->faila = -1;
rbio->failb = -1;
atomic_set(&rbio->refs, 1);
atomic_set(&rbio->error, 0);
atomic_set(&rbio->stripes_pending, 0);
p = rbio + 1;
rbio->stripe_pages = p;
rbio->bio_pages = p + sizeof(struct page *) * num_pages;
rbio->dbitmap = p + sizeof(struct page *) * num_pages * 2;
if (bbio->map_type & BTRFS_BLOCK_GROUP_RAID5)
nr_data = real_stripes - 1;
else if (bbio->map_type & BTRFS_BLOCK_GROUP_RAID6)
nr_data = real_stripes - 2;
else
BUG();
rbio->nr_data = nr_data;
return rbio;
}
static int alloc_rbio_pages(struct btrfs_raid_bio *rbio)
{
int i;
struct page *page;
for (i = 0; i < rbio->nr_pages; i++) {
if (rbio->stripe_pages[i])
continue;
page = alloc_page(GFP_NOFS | __GFP_HIGHMEM);
if (!page)
return -ENOMEM;
rbio->stripe_pages[i] = page;
}
return 0;
}
static int alloc_rbio_parity_pages(struct btrfs_raid_bio *rbio)
{
int i;
struct page *page;
i = rbio_stripe_page_index(rbio, rbio->nr_data, 0);
for (; i < rbio->nr_pages; i++) {
if (rbio->stripe_pages[i])
continue;
page = alloc_page(GFP_NOFS | __GFP_HIGHMEM);
if (!page)
return -ENOMEM;
rbio->stripe_pages[i] = page;
}
return 0;
}
static int rbio_add_io_page(struct btrfs_raid_bio *rbio,
struct bio_list *bio_list,
struct page *page,
int stripe_nr,
unsigned long page_index,
unsigned long bio_max_len)
{
struct bio *last = bio_list->tail;
u64 last_end = 0;
int ret;
struct bio *bio;
struct btrfs_bio_stripe *stripe;
u64 disk_start;
stripe = &rbio->bbio->stripes[stripe_nr];
disk_start = stripe->physical + (page_index << PAGE_SHIFT);
if (!stripe->dev->bdev)
return fail_rbio_index(rbio, stripe_nr);
if (last) {
last_end = (u64)last->bi_iter.bi_sector << 9;
last_end += last->bi_iter.bi_size;
if (last_end == disk_start && stripe->dev->bdev &&
!last->bi_error &&
last->bi_bdev == stripe->dev->bdev) {
ret = bio_add_page(last, page, PAGE_SIZE, 0);
if (ret == PAGE_SIZE)
return 0;
}
}
bio = btrfs_io_bio_alloc(GFP_NOFS, bio_max_len >> PAGE_SHIFT?:1);
if (!bio)
return -ENOMEM;
bio->bi_iter.bi_size = 0;
bio->bi_bdev = stripe->dev->bdev;
bio->bi_iter.bi_sector = disk_start >> 9;
bio_add_page(bio, page, PAGE_SIZE, 0);
bio_list_add(bio_list, bio);
return 0;
}
static void validate_rbio_for_rmw(struct btrfs_raid_bio *rbio)
{
if (rbio->faila >= 0 || rbio->failb >= 0) {
BUG_ON(rbio->faila == rbio->real_stripes - 1);
__raid56_parity_recover(rbio);
} else {
finish_rmw(rbio);
}
}
static void index_rbio_pages(struct btrfs_raid_bio *rbio)
{
struct bio *bio;
struct bio_vec *bvec;
u64 start;
unsigned long stripe_offset;
unsigned long page_index;
int i;
spin_lock_irq(&rbio->bio_list_lock);
bio_list_for_each(bio, &rbio->bio_list) {
start = (u64)bio->bi_iter.bi_sector << 9;
stripe_offset = start - rbio->bbio->raid_map[0];
page_index = stripe_offset >> PAGE_SHIFT;
bio_for_each_segment_all(bvec, bio, i)
rbio->bio_pages[page_index + i] = bvec->bv_page;
}
spin_unlock_irq(&rbio->bio_list_lock);
}
static noinline void finish_rmw(struct btrfs_raid_bio *rbio)
{
struct btrfs_bio *bbio = rbio->bbio;
void *pointers[rbio->real_stripes];
int nr_data = rbio->nr_data;
int stripe;
int pagenr;
int p_stripe = -1;
int q_stripe = -1;
struct bio_list bio_list;
struct bio *bio;
int ret;
bio_list_init(&bio_list);
if (rbio->real_stripes - rbio->nr_data == 1) {
p_stripe = rbio->real_stripes - 1;
} else if (rbio->real_stripes - rbio->nr_data == 2) {
p_stripe = rbio->real_stripes - 2;
q_stripe = rbio->real_stripes - 1;
} else {
BUG();
}
spin_lock_irq(&rbio->bio_list_lock);
set_bit(RBIO_RMW_LOCKED_BIT, &rbio->flags);
spin_unlock_irq(&rbio->bio_list_lock);
atomic_set(&rbio->error, 0);
index_rbio_pages(rbio);
if (!rbio_is_full(rbio))
cache_rbio_pages(rbio);
else
clear_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
struct page *p;
for (stripe = 0; stripe < nr_data; stripe++) {
p = page_in_rbio(rbio, stripe, pagenr, 0);
pointers[stripe] = kmap(p);
}
p = rbio_pstripe_page(rbio, pagenr);
SetPageUptodate(p);
pointers[stripe++] = kmap(p);
if (q_stripe != -1) {
p = rbio_qstripe_page(rbio, pagenr);
SetPageUptodate(p);
pointers[stripe++] = kmap(p);
raid6_call.gen_syndrome(rbio->real_stripes, PAGE_SIZE,
pointers);
} else {
memcpy(pointers[nr_data], pointers[0], PAGE_SIZE);
run_xor(pointers + 1, nr_data - 1, PAGE_SIZE);
}
for (stripe = 0; stripe < rbio->real_stripes; stripe++)
kunmap(page_in_rbio(rbio, stripe, pagenr, 0));
}
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
struct page *page;
if (stripe < rbio->nr_data) {
page = page_in_rbio(rbio, stripe, pagenr, 1);
if (!page)
continue;
} else {
page = rbio_stripe_page(rbio, stripe, pagenr);
}
ret = rbio_add_io_page(rbio, &bio_list,
page, stripe, pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
}
if (likely(!bbio->num_tgtdevs))
goto write_data;
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
if (!bbio->tgtdev_map[stripe])
continue;
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
struct page *page;
if (stripe < rbio->nr_data) {
page = page_in_rbio(rbio, stripe, pagenr, 1);
if (!page)
continue;
} else {
page = rbio_stripe_page(rbio, stripe, pagenr);
}
ret = rbio_add_io_page(rbio, &bio_list, page,
rbio->bbio->tgtdev_map[stripe],
pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
}
write_data:
atomic_set(&rbio->stripes_pending, bio_list_size(&bio_list));
BUG_ON(atomic_read(&rbio->stripes_pending) == 0);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_write_end_io;
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
submit_bio(bio);
}
return;
cleanup:
rbio_orig_end_io(rbio, -EIO);
}
static int find_bio_stripe(struct btrfs_raid_bio *rbio,
struct bio *bio)
{
u64 physical = bio->bi_iter.bi_sector;
u64 stripe_start;
int i;
struct btrfs_bio_stripe *stripe;
physical <<= 9;
for (i = 0; i < rbio->bbio->num_stripes; i++) {
stripe = &rbio->bbio->stripes[i];
stripe_start = stripe->physical;
if (physical >= stripe_start &&
physical < stripe_start + rbio->stripe_len &&
bio->bi_bdev == stripe->dev->bdev) {
return i;
}
}
return -1;
}
static int find_logical_bio_stripe(struct btrfs_raid_bio *rbio,
struct bio *bio)
{
u64 logical = bio->bi_iter.bi_sector;
u64 stripe_start;
int i;
logical <<= 9;
for (i = 0; i < rbio->nr_data; i++) {
stripe_start = rbio->bbio->raid_map[i];
if (logical >= stripe_start &&
logical < stripe_start + rbio->stripe_len) {
return i;
}
}
return -1;
}
static int fail_rbio_index(struct btrfs_raid_bio *rbio, int failed)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&rbio->bio_list_lock, flags);
if (rbio->faila == failed || rbio->failb == failed)
goto out;
if (rbio->faila == -1) {
rbio->faila = failed;
atomic_inc(&rbio->error);
} else if (rbio->failb == -1) {
rbio->failb = failed;
atomic_inc(&rbio->error);
} else {
ret = -EIO;
}
out:
spin_unlock_irqrestore(&rbio->bio_list_lock, flags);
return ret;
}
static int fail_bio_stripe(struct btrfs_raid_bio *rbio,
struct bio *bio)
{
int failed = find_bio_stripe(rbio, bio);
if (failed < 0)
return -EIO;
return fail_rbio_index(rbio, failed);
}
static void set_bio_pages_uptodate(struct bio *bio)
{
struct bio_vec *bvec;
int i;
bio_for_each_segment_all(bvec, bio, i)
SetPageUptodate(bvec->bv_page);
}
static void raid_rmw_end_io(struct bio *bio)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (bio->bi_error)
fail_bio_stripe(rbio, bio);
else
set_bio_pages_uptodate(bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->stripes_pending))
return;
if (atomic_read(&rbio->error) > rbio->bbio->max_errors)
goto cleanup;
validate_rbio_for_rmw(rbio);
return;
cleanup:
rbio_orig_end_io(rbio, -EIO);
}
static void async_rmw_stripe(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper, rmw_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers, &rbio->work);
}
static void async_read_rebuild(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper,
read_rebuild_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers, &rbio->work);
}
static int raid56_rmw_stripe(struct btrfs_raid_bio *rbio)
{
int bios_to_read = 0;
struct bio_list bio_list;
int ret;
int pagenr;
int stripe;
struct bio *bio;
bio_list_init(&bio_list);
ret = alloc_rbio_pages(rbio);
if (ret)
goto cleanup;
index_rbio_pages(rbio);
atomic_set(&rbio->error, 0);
for (stripe = 0; stripe < rbio->nr_data; stripe++) {
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
struct page *page;
page = page_in_rbio(rbio, stripe, pagenr, 1);
if (page)
continue;
page = rbio_stripe_page(rbio, stripe, pagenr);
if (PageUptodate(page))
continue;
ret = rbio_add_io_page(rbio, &bio_list, page,
stripe, pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
}
bios_to_read = bio_list_size(&bio_list);
if (!bios_to_read) {
goto finish;
}
atomic_set(&rbio->stripes_pending, bios_to_read);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_rmw_end_io;
bio_set_op_attrs(bio, REQ_OP_READ, 0);
btrfs_bio_wq_end_io(rbio->fs_info, bio, BTRFS_WQ_ENDIO_RAID56);
submit_bio(bio);
}
return 0;
cleanup:
rbio_orig_end_io(rbio, -EIO);
return -EIO;
finish:
validate_rbio_for_rmw(rbio);
return 0;
}
static int full_stripe_write(struct btrfs_raid_bio *rbio)
{
int ret;
ret = alloc_rbio_parity_pages(rbio);
if (ret) {
__free_raid_bio(rbio);
return ret;
}
ret = lock_stripe_add(rbio);
if (ret == 0)
finish_rmw(rbio);
return 0;
}
static int partial_stripe_write(struct btrfs_raid_bio *rbio)
{
int ret;
ret = lock_stripe_add(rbio);
if (ret == 0)
async_rmw_stripe(rbio);
return 0;
}
static int __raid56_parity_write(struct btrfs_raid_bio *rbio)
{
if (!rbio_is_full(rbio))
return partial_stripe_write(rbio);
return full_stripe_write(rbio);
}
static int plug_cmp(void *priv, struct list_head *a, struct list_head *b)
{
struct btrfs_raid_bio *ra = container_of(a, struct btrfs_raid_bio,
plug_list);
struct btrfs_raid_bio *rb = container_of(b, struct btrfs_raid_bio,
plug_list);
u64 a_sector = ra->bio_list.head->bi_iter.bi_sector;
u64 b_sector = rb->bio_list.head->bi_iter.bi_sector;
if (a_sector < b_sector)
return -1;
if (a_sector > b_sector)
return 1;
return 0;
}
static void run_plug(struct btrfs_plug_cb *plug)
{
struct btrfs_raid_bio *cur;
struct btrfs_raid_bio *last = NULL;
list_sort(NULL, &plug->rbio_list, plug_cmp);
while (!list_empty(&plug->rbio_list)) {
cur = list_entry(plug->rbio_list.next,
struct btrfs_raid_bio, plug_list);
list_del_init(&cur->plug_list);
if (rbio_is_full(cur)) {
full_stripe_write(cur);
continue;
}
if (last) {
if (rbio_can_merge(last, cur)) {
merge_rbio(last, cur);
__free_raid_bio(cur);
continue;
}
__raid56_parity_write(last);
}
last = cur;
}
if (last) {
__raid56_parity_write(last);
}
kfree(plug);
}
static void unplug_work(struct btrfs_work *work)
{
struct btrfs_plug_cb *plug;
plug = container_of(work, struct btrfs_plug_cb, work);
run_plug(plug);
}
static void btrfs_raid_unplug(struct blk_plug_cb *cb, bool from_schedule)
{
struct btrfs_plug_cb *plug;
plug = container_of(cb, struct btrfs_plug_cb, cb);
if (from_schedule) {
btrfs_init_work(&plug->work, btrfs_rmw_helper,
unplug_work, NULL, NULL);
btrfs_queue_work(plug->info->rmw_workers,
&plug->work);
return;
}
run_plug(plug);
}
int raid56_parity_write(struct btrfs_fs_info *fs_info, struct bio *bio,
struct btrfs_bio *bbio, u64 stripe_len)
{
struct btrfs_raid_bio *rbio;
struct btrfs_plug_cb *plug = NULL;
struct blk_plug_cb *cb;
int ret;
rbio = alloc_rbio(fs_info, bbio, stripe_len);
if (IS_ERR(rbio)) {
btrfs_put_bbio(bbio);
return PTR_ERR(rbio);
}
bio_list_add(&rbio->bio_list, bio);
rbio->bio_list_bytes = bio->bi_iter.bi_size;
rbio->operation = BTRFS_RBIO_WRITE;
btrfs_bio_counter_inc_noblocked(fs_info);
rbio->generic_bio_cnt = 1;
if (rbio_is_full(rbio)) {
ret = full_stripe_write(rbio);
if (ret)
btrfs_bio_counter_dec(fs_info);
return ret;
}
cb = blk_check_plugged(btrfs_raid_unplug, fs_info, sizeof(*plug));
if (cb) {
plug = container_of(cb, struct btrfs_plug_cb, cb);
if (!plug->info) {
plug->info = fs_info;
INIT_LIST_HEAD(&plug->rbio_list);
}
list_add_tail(&rbio->plug_list, &plug->rbio_list);
ret = 0;
} else {
ret = __raid56_parity_write(rbio);
if (ret)
btrfs_bio_counter_dec(fs_info);
}
return ret;
}
static void __raid_recover_end_io(struct btrfs_raid_bio *rbio)
{
int pagenr, stripe;
void **pointers;
int faila = -1, failb = -1;
struct page *page;
int err;
int i;
pointers = kcalloc(rbio->real_stripes, sizeof(void *), GFP_NOFS);
if (!pointers) {
err = -ENOMEM;
goto cleanup_io;
}
faila = rbio->faila;
failb = rbio->failb;
if (rbio->operation == BTRFS_RBIO_READ_REBUILD ||
rbio->operation == BTRFS_RBIO_REBUILD_MISSING) {
spin_lock_irq(&rbio->bio_list_lock);
set_bit(RBIO_RMW_LOCKED_BIT, &rbio->flags);
spin_unlock_irq(&rbio->bio_list_lock);
}
index_rbio_pages(rbio);
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
if (rbio->operation == BTRFS_RBIO_PARITY_SCRUB &&
!test_bit(pagenr, rbio->dbitmap))
continue;
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
if ((rbio->operation == BTRFS_RBIO_READ_REBUILD ||
rbio->operation == BTRFS_RBIO_REBUILD_MISSING) &&
(stripe == faila || stripe == failb)) {
page = page_in_rbio(rbio, stripe, pagenr, 0);
} else {
page = rbio_stripe_page(rbio, stripe, pagenr);
}
pointers[stripe] = kmap(page);
}
if (rbio->bbio->map_type & BTRFS_BLOCK_GROUP_RAID6) {
if (failb < 0) {
if (faila == rbio->nr_data) {
err = -EIO;
goto cleanup;
}
goto pstripe;
}
if (faila > failb) {
int tmp = failb;
failb = faila;
faila = tmp;
}
if (rbio->bbio->raid_map[failb] == RAID6_Q_STRIPE) {
if (rbio->bbio->raid_map[faila] ==
RAID5_P_STRIPE) {
err = -EIO;
goto cleanup;
}
goto pstripe;
}
if (rbio->bbio->raid_map[failb] == RAID5_P_STRIPE) {
raid6_datap_recov(rbio->real_stripes,
PAGE_SIZE, faila, pointers);
} else {
raid6_2data_recov(rbio->real_stripes,
PAGE_SIZE, faila, failb,
pointers);
}
} else {
void *p;
BUG_ON(failb != -1);
pstripe:
memcpy(pointers[faila],
pointers[rbio->nr_data],
PAGE_SIZE);
p = pointers[faila];
for (stripe = faila; stripe < rbio->nr_data - 1; stripe++)
pointers[stripe] = pointers[stripe + 1];
pointers[rbio->nr_data - 1] = p;
run_xor(pointers, rbio->nr_data - 1, PAGE_SIZE);
}
if (rbio->operation == BTRFS_RBIO_WRITE) {
for (i = 0; i < rbio->stripe_npages; i++) {
if (faila != -1) {
page = rbio_stripe_page(rbio, faila, i);
SetPageUptodate(page);
}
if (failb != -1) {
page = rbio_stripe_page(rbio, failb, i);
SetPageUptodate(page);
}
}
}
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
if ((rbio->operation == BTRFS_RBIO_READ_REBUILD ||
rbio->operation == BTRFS_RBIO_REBUILD_MISSING) &&
(stripe == faila || stripe == failb)) {
page = page_in_rbio(rbio, stripe, pagenr, 0);
} else {
page = rbio_stripe_page(rbio, stripe, pagenr);
}
kunmap(page);
}
}
err = 0;
cleanup:
kfree(pointers);
cleanup_io:
if (rbio->operation == BTRFS_RBIO_READ_REBUILD) {
if (err == 0)
cache_rbio_pages(rbio);
else
clear_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
rbio_orig_end_io(rbio, err);
} else if (rbio->operation == BTRFS_RBIO_REBUILD_MISSING) {
rbio_orig_end_io(rbio, err);
} else if (err == 0) {
rbio->faila = -1;
rbio->failb = -1;
if (rbio->operation == BTRFS_RBIO_WRITE)
finish_rmw(rbio);
else if (rbio->operation == BTRFS_RBIO_PARITY_SCRUB)
finish_parity_scrub(rbio, 0);
else
BUG();
} else {
rbio_orig_end_io(rbio, err);
}
}
static void raid_recover_end_io(struct bio *bio)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (bio->bi_error)
fail_bio_stripe(rbio, bio);
else
set_bio_pages_uptodate(bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->stripes_pending))
return;
if (atomic_read(&rbio->error) > rbio->bbio->max_errors)
rbio_orig_end_io(rbio, -EIO);
else
__raid_recover_end_io(rbio);
}
static int __raid56_parity_recover(struct btrfs_raid_bio *rbio)
{
int bios_to_read = 0;
struct bio_list bio_list;
int ret;
int pagenr;
int stripe;
struct bio *bio;
bio_list_init(&bio_list);
ret = alloc_rbio_pages(rbio);
if (ret)
goto cleanup;
atomic_set(&rbio->error, 0);
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
if (rbio->faila == stripe || rbio->failb == stripe) {
atomic_inc(&rbio->error);
continue;
}
for (pagenr = 0; pagenr < rbio->stripe_npages; pagenr++) {
struct page *p;
p = rbio_stripe_page(rbio, stripe, pagenr);
if (PageUptodate(p))
continue;
ret = rbio_add_io_page(rbio, &bio_list,
rbio_stripe_page(rbio, stripe, pagenr),
stripe, pagenr, rbio->stripe_len);
if (ret < 0)
goto cleanup;
}
}
bios_to_read = bio_list_size(&bio_list);
if (!bios_to_read) {
if (atomic_read(&rbio->error) <= rbio->bbio->max_errors) {
__raid_recover_end_io(rbio);
goto out;
} else {
goto cleanup;
}
}
atomic_set(&rbio->stripes_pending, bios_to_read);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_recover_end_io;
bio_set_op_attrs(bio, REQ_OP_READ, 0);
btrfs_bio_wq_end_io(rbio->fs_info, bio, BTRFS_WQ_ENDIO_RAID56);
submit_bio(bio);
}
out:
return 0;
cleanup:
if (rbio->operation == BTRFS_RBIO_READ_REBUILD ||
rbio->operation == BTRFS_RBIO_REBUILD_MISSING)
rbio_orig_end_io(rbio, -EIO);
return -EIO;
}
int raid56_parity_recover(struct btrfs_fs_info *fs_info, struct bio *bio,
struct btrfs_bio *bbio, u64 stripe_len,
int mirror_num, int generic_io)
{
struct btrfs_raid_bio *rbio;
int ret;
rbio = alloc_rbio(fs_info, bbio, stripe_len);
if (IS_ERR(rbio)) {
if (generic_io)
btrfs_put_bbio(bbio);
return PTR_ERR(rbio);
}
rbio->operation = BTRFS_RBIO_READ_REBUILD;
bio_list_add(&rbio->bio_list, bio);
rbio->bio_list_bytes = bio->bi_iter.bi_size;
rbio->faila = find_logical_bio_stripe(rbio, bio);
if (rbio->faila == -1) {
btrfs_warn(fs_info,
"%s could not find the bad stripe in raid56 so that we cannot recover any more (bio has logical %llu len %llu, bbio has map_type %llu)",
__func__, (u64)bio->bi_iter.bi_sector << 9,
(u64)bio->bi_iter.bi_size, bbio->map_type);
if (generic_io)
btrfs_put_bbio(bbio);
kfree(rbio);
return -EIO;
}
if (generic_io) {
btrfs_bio_counter_inc_noblocked(fs_info);
rbio->generic_bio_cnt = 1;
} else {
btrfs_get_bbio(bbio);
}
if (mirror_num == 3)
rbio->failb = rbio->real_stripes - 2;
ret = lock_stripe_add(rbio);
if (ret == 0)
__raid56_parity_recover(rbio);
return 0;
}
static void rmw_work(struct btrfs_work *work)
{
struct btrfs_raid_bio *rbio;
rbio = container_of(work, struct btrfs_raid_bio, work);
raid56_rmw_stripe(rbio);
}
static void read_rebuild_work(struct btrfs_work *work)
{
struct btrfs_raid_bio *rbio;
rbio = container_of(work, struct btrfs_raid_bio, work);
__raid56_parity_recover(rbio);
}
struct btrfs_raid_bio *
raid56_parity_alloc_scrub_rbio(struct btrfs_fs_info *fs_info, struct bio *bio,
struct btrfs_bio *bbio, u64 stripe_len,
struct btrfs_device *scrub_dev,
unsigned long *dbitmap, int stripe_nsectors)
{
struct btrfs_raid_bio *rbio;
int i;
rbio = alloc_rbio(fs_info, bbio, stripe_len);
if (IS_ERR(rbio))
return NULL;
bio_list_add(&rbio->bio_list, bio);
ASSERT(!bio->bi_iter.bi_size);
rbio->operation = BTRFS_RBIO_PARITY_SCRUB;
for (i = 0; i < rbio->real_stripes; i++) {
if (bbio->stripes[i].dev == scrub_dev) {
rbio->scrubp = i;
break;
}
}
ASSERT(fs_info->sectorsize == PAGE_SIZE);
ASSERT(rbio->stripe_npages == stripe_nsectors);
bitmap_copy(rbio->dbitmap, dbitmap, stripe_nsectors);
return rbio;
}
void raid56_add_scrub_pages(struct btrfs_raid_bio *rbio, struct page *page,
u64 logical)
{
int stripe_offset;
int index;
ASSERT(logical >= rbio->bbio->raid_map[0]);
ASSERT(logical + PAGE_SIZE <= rbio->bbio->raid_map[0] +
rbio->stripe_len * rbio->nr_data);
stripe_offset = (int)(logical - rbio->bbio->raid_map[0]);
index = stripe_offset >> PAGE_SHIFT;
rbio->bio_pages[index] = page;
}
static int alloc_rbio_essential_pages(struct btrfs_raid_bio *rbio)
{
int i;
int bit;
int index;
struct page *page;
for_each_set_bit(bit, rbio->dbitmap, rbio->stripe_npages) {
for (i = 0; i < rbio->real_stripes; i++) {
index = i * rbio->stripe_npages + bit;
if (rbio->stripe_pages[index])
continue;
page = alloc_page(GFP_NOFS | __GFP_HIGHMEM);
if (!page)
return -ENOMEM;
rbio->stripe_pages[index] = page;
}
}
return 0;
}
static noinline void finish_parity_scrub(struct btrfs_raid_bio *rbio,
int need_check)
{
struct btrfs_bio *bbio = rbio->bbio;
void *pointers[rbio->real_stripes];
DECLARE_BITMAP(pbitmap, rbio->stripe_npages);
int nr_data = rbio->nr_data;
int stripe;
int pagenr;
int p_stripe = -1;
int q_stripe = -1;
struct page *p_page = NULL;
struct page *q_page = NULL;
struct bio_list bio_list;
struct bio *bio;
int is_replace = 0;
int ret;
bio_list_init(&bio_list);
if (rbio->real_stripes - rbio->nr_data == 1) {
p_stripe = rbio->real_stripes - 1;
} else if (rbio->real_stripes - rbio->nr_data == 2) {
p_stripe = rbio->real_stripes - 2;
q_stripe = rbio->real_stripes - 1;
} else {
BUG();
}
if (bbio->num_tgtdevs && bbio->tgtdev_map[rbio->scrubp]) {
is_replace = 1;
bitmap_copy(pbitmap, rbio->dbitmap, rbio->stripe_npages);
}
clear_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
if (!need_check)
goto writeback;
p_page = alloc_page(GFP_NOFS | __GFP_HIGHMEM);
if (!p_page)
goto cleanup;
SetPageUptodate(p_page);
if (q_stripe != -1) {
q_page = alloc_page(GFP_NOFS | __GFP_HIGHMEM);
if (!q_page) {
__free_page(p_page);
goto cleanup;
}
SetPageUptodate(q_page);
}
atomic_set(&rbio->error, 0);
for_each_set_bit(pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct page *p;
void *parity;
for (stripe = 0; stripe < nr_data; stripe++) {
p = page_in_rbio(rbio, stripe, pagenr, 0);
pointers[stripe] = kmap(p);
}
pointers[stripe++] = kmap(p_page);
if (q_stripe != -1) {
pointers[stripe++] = kmap(q_page);
raid6_call.gen_syndrome(rbio->real_stripes, PAGE_SIZE,
pointers);
} else {
memcpy(pointers[nr_data], pointers[0], PAGE_SIZE);
run_xor(pointers + 1, nr_data - 1, PAGE_SIZE);
}
p = rbio_stripe_page(rbio, rbio->scrubp, pagenr);
parity = kmap(p);
if (memcmp(parity, pointers[rbio->scrubp], PAGE_SIZE))
memcpy(parity, pointers[rbio->scrubp], PAGE_SIZE);
else
bitmap_clear(rbio->dbitmap, pagenr, 1);
kunmap(p);
for (stripe = 0; stripe < rbio->real_stripes; stripe++)
kunmap(page_in_rbio(rbio, stripe, pagenr, 0));
}
__free_page(p_page);
if (q_page)
__free_page(q_page);
writeback:
for_each_set_bit(pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct page *page;
page = rbio_stripe_page(rbio, rbio->scrubp, pagenr);
ret = rbio_add_io_page(rbio, &bio_list,
page, rbio->scrubp, pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
if (!is_replace)
goto submit_write;
for_each_set_bit(pagenr, pbitmap, rbio->stripe_npages) {
struct page *page;
page = rbio_stripe_page(rbio, rbio->scrubp, pagenr);
ret = rbio_add_io_page(rbio, &bio_list, page,
bbio->tgtdev_map[rbio->scrubp],
pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
submit_write:
nr_data = bio_list_size(&bio_list);
if (!nr_data) {
rbio_orig_end_io(rbio, 0);
return;
}
atomic_set(&rbio->stripes_pending, nr_data);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_write_end_io;
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
submit_bio(bio);
}
return;
cleanup:
rbio_orig_end_io(rbio, -EIO);
}
static inline int is_data_stripe(struct btrfs_raid_bio *rbio, int stripe)
{
if (stripe >= 0 && stripe < rbio->nr_data)
return 1;
return 0;
}
static void validate_rbio_for_parity_scrub(struct btrfs_raid_bio *rbio)
{
if (atomic_read(&rbio->error) > rbio->bbio->max_errors)
goto cleanup;
if (rbio->faila >= 0 || rbio->failb >= 0) {
int dfail = 0, failp = -1;
if (is_data_stripe(rbio, rbio->faila))
dfail++;
else if (is_parity_stripe(rbio->faila))
failp = rbio->faila;
if (is_data_stripe(rbio, rbio->failb))
dfail++;
else if (is_parity_stripe(rbio->failb))
failp = rbio->failb;
if (dfail > rbio->bbio->max_errors - 1)
goto cleanup;
if (dfail == 0) {
finish_parity_scrub(rbio, 0);
return;
}
if (failp != rbio->scrubp)
goto cleanup;
__raid_recover_end_io(rbio);
} else {
finish_parity_scrub(rbio, 1);
}
return;
cleanup:
rbio_orig_end_io(rbio, -EIO);
}
static void raid56_parity_scrub_end_io(struct bio *bio)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (bio->bi_error)
fail_bio_stripe(rbio, bio);
else
set_bio_pages_uptodate(bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->stripes_pending))
return;
validate_rbio_for_parity_scrub(rbio);
}
static void raid56_parity_scrub_stripe(struct btrfs_raid_bio *rbio)
{
int bios_to_read = 0;
struct bio_list bio_list;
int ret;
int pagenr;
int stripe;
struct bio *bio;
ret = alloc_rbio_essential_pages(rbio);
if (ret)
goto cleanup;
bio_list_init(&bio_list);
atomic_set(&rbio->error, 0);
for (stripe = 0; stripe < rbio->real_stripes; stripe++) {
for_each_set_bit(pagenr, rbio->dbitmap, rbio->stripe_npages) {
struct page *page;
page = page_in_rbio(rbio, stripe, pagenr, 1);
if (page)
continue;
page = rbio_stripe_page(rbio, stripe, pagenr);
if (PageUptodate(page))
continue;
ret = rbio_add_io_page(rbio, &bio_list, page,
stripe, pagenr, rbio->stripe_len);
if (ret)
goto cleanup;
}
}
bios_to_read = bio_list_size(&bio_list);
if (!bios_to_read) {
goto finish;
}
atomic_set(&rbio->stripes_pending, bios_to_read);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid56_parity_scrub_end_io;
bio_set_op_attrs(bio, REQ_OP_READ, 0);
btrfs_bio_wq_end_io(rbio->fs_info, bio, BTRFS_WQ_ENDIO_RAID56);
submit_bio(bio);
}
return;
cleanup:
rbio_orig_end_io(rbio, -EIO);
return;
finish:
validate_rbio_for_parity_scrub(rbio);
}
static void scrub_parity_work(struct btrfs_work *work)
{
struct btrfs_raid_bio *rbio;
rbio = container_of(work, struct btrfs_raid_bio, work);
raid56_parity_scrub_stripe(rbio);
}
static void async_scrub_parity(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper,
scrub_parity_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers, &rbio->work);
}
void raid56_parity_submit_scrub_rbio(struct btrfs_raid_bio *rbio)
{
if (!lock_stripe_add(rbio))
async_scrub_parity(rbio);
}
struct btrfs_raid_bio *
raid56_alloc_missing_rbio(struct btrfs_fs_info *fs_info, struct bio *bio,
struct btrfs_bio *bbio, u64 length)
{
struct btrfs_raid_bio *rbio;
rbio = alloc_rbio(fs_info, bbio, length);
if (IS_ERR(rbio))
return NULL;
rbio->operation = BTRFS_RBIO_REBUILD_MISSING;
bio_list_add(&rbio->bio_list, bio);
ASSERT(!bio->bi_iter.bi_size);
rbio->faila = find_logical_bio_stripe(rbio, bio);
if (rbio->faila == -1) {
BUG();
kfree(rbio);
return NULL;
}
return rbio;
}
static void missing_raid56_work(struct btrfs_work *work)
{
struct btrfs_raid_bio *rbio;
rbio = container_of(work, struct btrfs_raid_bio, work);
__raid56_parity_recover(rbio);
}
static void async_missing_raid56(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper,
missing_raid56_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers, &rbio->work);
}
void raid56_submit_missing_rbio(struct btrfs_raid_bio *rbio)
{
if (!lock_stripe_add(rbio))
async_missing_raid56(rbio);
}
