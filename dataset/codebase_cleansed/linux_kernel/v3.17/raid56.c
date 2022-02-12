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
if (x) {
if (is_vmalloc_addr(x))
vfree(x);
else
kfree(x);
}
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
memcpy(d, s, PAGE_CACHE_SIZE);
kunmap(rbio->bio_pages[i]);
kunmap(rbio->stripe_pages[i]);
SetPageUptodate(rbio->stripe_pages[i]);
}
set_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
}
static int rbio_bucket(struct btrfs_raid_bio *rbio)
{
u64 num = rbio->raid_map[0];
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
if (is_vmalloc_addr(info->stripe_hash_table))
vfree(info->stripe_hash_table);
else
kfree(info->stripe_hash_table);
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
return;
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
if (last->raid_map[0] !=
cur->raid_map[0])
return 0;
if (last->read_rebuild !=
cur->read_rebuild) {
return 0;
}
return 1;
}
static struct page *rbio_pstripe_page(struct btrfs_raid_bio *rbio, int index)
{
index += (rbio->nr_data * rbio->stripe_len) >> PAGE_CACHE_SHIFT;
return rbio->stripe_pages[index];
}
static struct page *rbio_qstripe_page(struct btrfs_raid_bio *rbio, int index)
{
if (rbio->nr_data + 1 == rbio->bbio->num_stripes)
return NULL;
index += ((rbio->nr_data + 1) * rbio->stripe_len) >>
PAGE_CACHE_SHIFT;
return rbio->stripe_pages[index];
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
int walk = 0;
spin_lock_irqsave(&h->lock, flags);
list_for_each_entry(cur, &h->hash_list, hash_list) {
walk++;
if (cur->raid_map[0] == rbio->raid_map[0]) {
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
if (next->read_rebuild)
async_read_rebuild(next);
else {
steal_rbio(rbio, next);
async_rmw_stripe(next);
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
kfree(rbio->raid_map);
kfree(rbio->bbio);
kfree(rbio);
}
static void free_raid_bio(struct btrfs_raid_bio *rbio)
{
unlock_stripe(rbio);
__free_raid_bio(rbio);
}
static void rbio_orig_end_io(struct btrfs_raid_bio *rbio, int err, int uptodate)
{
struct bio *cur = bio_list_get(&rbio->bio_list);
struct bio *next;
free_raid_bio(rbio);
while (cur) {
next = cur->bi_next;
cur->bi_next = NULL;
if (uptodate)
set_bit(BIO_UPTODATE, &cur->bi_flags);
bio_endio(cur, err);
cur = next;
}
}
static void raid_write_end_io(struct bio *bio, int err)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (err)
fail_bio_stripe(rbio, bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->bbio->stripes_pending))
return;
err = 0;
if (atomic_read(&rbio->bbio->error) > rbio->bbio->max_errors)
err = -EIO;
rbio_orig_end_io(rbio, err, 0);
return;
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
unsigned long nr = stripe_len * nr_stripes;
return (nr + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
}
static struct btrfs_raid_bio *alloc_rbio(struct btrfs_root *root,
struct btrfs_bio *bbio, u64 *raid_map,
u64 stripe_len)
{
struct btrfs_raid_bio *rbio;
int nr_data = 0;
int num_pages = rbio_nr_pages(stripe_len, bbio->num_stripes);
void *p;
rbio = kzalloc(sizeof(*rbio) + num_pages * sizeof(struct page *) * 2,
GFP_NOFS);
if (!rbio) {
kfree(raid_map);
kfree(bbio);
return ERR_PTR(-ENOMEM);
}
bio_list_init(&rbio->bio_list);
INIT_LIST_HEAD(&rbio->plug_list);
spin_lock_init(&rbio->bio_list_lock);
INIT_LIST_HEAD(&rbio->stripe_cache);
INIT_LIST_HEAD(&rbio->hash_list);
rbio->bbio = bbio;
rbio->raid_map = raid_map;
rbio->fs_info = root->fs_info;
rbio->stripe_len = stripe_len;
rbio->nr_pages = num_pages;
rbio->faila = -1;
rbio->failb = -1;
atomic_set(&rbio->refs, 1);
p = rbio + 1;
rbio->stripe_pages = p;
rbio->bio_pages = p + sizeof(struct page *) * num_pages;
if (raid_map[bbio->num_stripes - 1] == RAID6_Q_STRIPE)
nr_data = bbio->num_stripes - 2;
else
nr_data = bbio->num_stripes - 1;
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
ClearPageUptodate(page);
}
return 0;
}
static int alloc_rbio_parity_pages(struct btrfs_raid_bio *rbio)
{
int i;
struct page *page;
i = (rbio->nr_data * rbio->stripe_len) >> PAGE_CACHE_SHIFT;
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
disk_start = stripe->physical + (page_index << PAGE_CACHE_SHIFT);
if (!stripe->dev->bdev)
return fail_rbio_index(rbio, stripe_nr);
if (last) {
last_end = (u64)last->bi_iter.bi_sector << 9;
last_end += last->bi_iter.bi_size;
if (last_end == disk_start && stripe->dev->bdev &&
test_bit(BIO_UPTODATE, &last->bi_flags) &&
last->bi_bdev == stripe->dev->bdev) {
ret = bio_add_page(last, page, PAGE_CACHE_SIZE, 0);
if (ret == PAGE_CACHE_SIZE)
return 0;
}
}
bio = btrfs_io_bio_alloc(GFP_NOFS, bio_max_len >> PAGE_SHIFT?:1);
if (!bio)
return -ENOMEM;
bio->bi_iter.bi_size = 0;
bio->bi_bdev = stripe->dev->bdev;
bio->bi_iter.bi_sector = disk_start >> 9;
set_bit(BIO_UPTODATE, &bio->bi_flags);
bio_add_page(bio, page, PAGE_CACHE_SIZE, 0);
bio_list_add(bio_list, bio);
return 0;
}
static void validate_rbio_for_rmw(struct btrfs_raid_bio *rbio)
{
if (rbio->faila >= 0 || rbio->failb >= 0) {
BUG_ON(rbio->faila == rbio->bbio->num_stripes - 1);
__raid56_parity_recover(rbio);
} else {
finish_rmw(rbio);
}
}
static struct page *rbio_stripe_page(struct btrfs_raid_bio *rbio, int stripe, int page)
{
int index;
index = stripe * (rbio->stripe_len >> PAGE_CACHE_SHIFT);
index += page;
return rbio->stripe_pages[index];
}
static void index_rbio_pages(struct btrfs_raid_bio *rbio)
{
struct bio *bio;
u64 start;
unsigned long stripe_offset;
unsigned long page_index;
struct page *p;
int i;
spin_lock_irq(&rbio->bio_list_lock);
bio_list_for_each(bio, &rbio->bio_list) {
start = (u64)bio->bi_iter.bi_sector << 9;
stripe_offset = start - rbio->raid_map[0];
page_index = stripe_offset >> PAGE_CACHE_SHIFT;
for (i = 0; i < bio->bi_vcnt; i++) {
p = bio->bi_io_vec[i].bv_page;
rbio->bio_pages[page_index + i] = p;
}
}
spin_unlock_irq(&rbio->bio_list_lock);
}
static noinline void finish_rmw(struct btrfs_raid_bio *rbio)
{
struct btrfs_bio *bbio = rbio->bbio;
void *pointers[bbio->num_stripes];
int stripe_len = rbio->stripe_len;
int nr_data = rbio->nr_data;
int stripe;
int pagenr;
int p_stripe = -1;
int q_stripe = -1;
struct bio_list bio_list;
struct bio *bio;
int pages_per_stripe = stripe_len >> PAGE_CACHE_SHIFT;
int ret;
bio_list_init(&bio_list);
if (bbio->num_stripes - rbio->nr_data == 1) {
p_stripe = bbio->num_stripes - 1;
} else if (bbio->num_stripes - rbio->nr_data == 2) {
p_stripe = bbio->num_stripes - 2;
q_stripe = bbio->num_stripes - 1;
} else {
BUG();
}
spin_lock_irq(&rbio->bio_list_lock);
set_bit(RBIO_RMW_LOCKED_BIT, &rbio->flags);
spin_unlock_irq(&rbio->bio_list_lock);
atomic_set(&rbio->bbio->error, 0);
index_rbio_pages(rbio);
if (!rbio_is_full(rbio))
cache_rbio_pages(rbio);
else
clear_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
for (pagenr = 0; pagenr < pages_per_stripe; pagenr++) {
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
raid6_call.gen_syndrome(bbio->num_stripes, PAGE_SIZE,
pointers);
} else {
memcpy(pointers[nr_data], pointers[0], PAGE_SIZE);
run_xor(pointers + 1, nr_data - 1, PAGE_CACHE_SIZE);
}
for (stripe = 0; stripe < bbio->num_stripes; stripe++)
kunmap(page_in_rbio(rbio, stripe, pagenr, 0));
}
for (stripe = 0; stripe < bbio->num_stripes; stripe++) {
for (pagenr = 0; pagenr < pages_per_stripe; pagenr++) {
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
atomic_set(&bbio->stripes_pending, bio_list_size(&bio_list));
BUG_ON(atomic_read(&bbio->stripes_pending) == 0);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_write_end_io;
BUG_ON(!test_bit(BIO_UPTODATE, &bio->bi_flags));
submit_bio(WRITE, bio);
}
return;
cleanup:
rbio_orig_end_io(rbio, -EIO, 0);
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
physical < stripe_start + rbio->stripe_len) {
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
stripe_start = rbio->raid_map[i];
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
atomic_inc(&rbio->bbio->error);
} else if (rbio->failb == -1) {
rbio->failb = failed;
atomic_inc(&rbio->bbio->error);
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
int i;
struct page *p;
for (i = 0; i < bio->bi_vcnt; i++) {
p = bio->bi_io_vec[i].bv_page;
SetPageUptodate(p);
}
}
static void raid_rmw_end_io(struct bio *bio, int err)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (err)
fail_bio_stripe(rbio, bio);
else
set_bio_pages_uptodate(bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->bbio->stripes_pending))
return;
err = 0;
if (atomic_read(&rbio->bbio->error) > rbio->bbio->max_errors)
goto cleanup;
validate_rbio_for_rmw(rbio);
return;
cleanup:
rbio_orig_end_io(rbio, -EIO, 0);
}
static void async_rmw_stripe(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper,
rmw_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers,
&rbio->work);
}
static void async_read_rebuild(struct btrfs_raid_bio *rbio)
{
btrfs_init_work(&rbio->work, btrfs_rmw_helper,
read_rebuild_work, NULL, NULL);
btrfs_queue_work(rbio->fs_info->rmw_workers,
&rbio->work);
}
static int raid56_rmw_stripe(struct btrfs_raid_bio *rbio)
{
int bios_to_read = 0;
struct btrfs_bio *bbio = rbio->bbio;
struct bio_list bio_list;
int ret;
int nr_pages = (rbio->stripe_len + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
int pagenr;
int stripe;
struct bio *bio;
bio_list_init(&bio_list);
ret = alloc_rbio_pages(rbio);
if (ret)
goto cleanup;
index_rbio_pages(rbio);
atomic_set(&rbio->bbio->error, 0);
for (stripe = 0; stripe < rbio->nr_data; stripe++) {
for (pagenr = 0; pagenr < nr_pages; pagenr++) {
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
atomic_set(&bbio->stripes_pending, bios_to_read);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_rmw_end_io;
btrfs_bio_wq_end_io(rbio->fs_info, bio,
BTRFS_WQ_ENDIO_RAID56);
BUG_ON(!test_bit(BIO_UPTODATE, &bio->bi_flags));
submit_bio(READ, bio);
}
return 0;
cleanup:
rbio_orig_end_io(rbio, -EIO, 0);
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
int raid56_parity_write(struct btrfs_root *root, struct bio *bio,
struct btrfs_bio *bbio, u64 *raid_map,
u64 stripe_len)
{
struct btrfs_raid_bio *rbio;
struct btrfs_plug_cb *plug = NULL;
struct blk_plug_cb *cb;
rbio = alloc_rbio(root, bbio, raid_map, stripe_len);
if (IS_ERR(rbio))
return PTR_ERR(rbio);
bio_list_add(&rbio->bio_list, bio);
rbio->bio_list_bytes = bio->bi_iter.bi_size;
if (rbio_is_full(rbio))
return full_stripe_write(rbio);
cb = blk_check_plugged(btrfs_raid_unplug, root->fs_info,
sizeof(*plug));
if (cb) {
plug = container_of(cb, struct btrfs_plug_cb, cb);
if (!plug->info) {
plug->info = root->fs_info;
INIT_LIST_HEAD(&plug->rbio_list);
}
list_add_tail(&rbio->plug_list, &plug->rbio_list);
} else {
return __raid56_parity_write(rbio);
}
return 0;
}
static void __raid_recover_end_io(struct btrfs_raid_bio *rbio)
{
int pagenr, stripe;
void **pointers;
int faila = -1, failb = -1;
int nr_pages = (rbio->stripe_len + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
struct page *page;
int err;
int i;
pointers = kzalloc(rbio->bbio->num_stripes * sizeof(void *),
GFP_NOFS);
if (!pointers) {
err = -ENOMEM;
goto cleanup_io;
}
faila = rbio->faila;
failb = rbio->failb;
if (rbio->read_rebuild) {
spin_lock_irq(&rbio->bio_list_lock);
set_bit(RBIO_RMW_LOCKED_BIT, &rbio->flags);
spin_unlock_irq(&rbio->bio_list_lock);
}
index_rbio_pages(rbio);
for (pagenr = 0; pagenr < nr_pages; pagenr++) {
for (stripe = 0; stripe < rbio->bbio->num_stripes; stripe++) {
if (rbio->read_rebuild &&
(stripe == faila || stripe == failb)) {
page = page_in_rbio(rbio, stripe, pagenr, 0);
} else {
page = rbio_stripe_page(rbio, stripe, pagenr);
}
pointers[stripe] = kmap(page);
}
if (rbio->raid_map[rbio->bbio->num_stripes - 1] ==
RAID6_Q_STRIPE) {
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
if (rbio->raid_map[failb] == RAID6_Q_STRIPE) {
if (rbio->raid_map[faila] == RAID5_P_STRIPE) {
err = -EIO;
goto cleanup;
}
goto pstripe;
}
if (rbio->raid_map[failb] == RAID5_P_STRIPE) {
raid6_datap_recov(rbio->bbio->num_stripes,
PAGE_SIZE, faila, pointers);
} else {
raid6_2data_recov(rbio->bbio->num_stripes,
PAGE_SIZE, faila, failb,
pointers);
}
} else {
void *p;
BUG_ON(failb != -1);
pstripe:
memcpy(pointers[faila],
pointers[rbio->nr_data],
PAGE_CACHE_SIZE);
p = pointers[faila];
for (stripe = faila; stripe < rbio->nr_data - 1; stripe++)
pointers[stripe] = pointers[stripe + 1];
pointers[rbio->nr_data - 1] = p;
run_xor(pointers, rbio->nr_data - 1, PAGE_CACHE_SIZE);
}
if (!rbio->read_rebuild) {
for (i = 0; i < nr_pages; i++) {
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
for (stripe = 0; stripe < rbio->bbio->num_stripes; stripe++) {
if (rbio->read_rebuild &&
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
if (rbio->read_rebuild) {
if (err == 0)
cache_rbio_pages(rbio);
else
clear_bit(RBIO_CACHE_READY_BIT, &rbio->flags);
rbio_orig_end_io(rbio, err, err == 0);
} else if (err == 0) {
rbio->faila = -1;
rbio->failb = -1;
finish_rmw(rbio);
} else {
rbio_orig_end_io(rbio, err, 0);
}
}
static void raid_recover_end_io(struct bio *bio, int err)
{
struct btrfs_raid_bio *rbio = bio->bi_private;
if (err)
fail_bio_stripe(rbio, bio);
else
set_bio_pages_uptodate(bio);
bio_put(bio);
if (!atomic_dec_and_test(&rbio->bbio->stripes_pending))
return;
if (atomic_read(&rbio->bbio->error) > rbio->bbio->max_errors)
rbio_orig_end_io(rbio, -EIO, 0);
else
__raid_recover_end_io(rbio);
}
static int __raid56_parity_recover(struct btrfs_raid_bio *rbio)
{
int bios_to_read = 0;
struct btrfs_bio *bbio = rbio->bbio;
struct bio_list bio_list;
int ret;
int nr_pages = (rbio->stripe_len + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
int pagenr;
int stripe;
struct bio *bio;
bio_list_init(&bio_list);
ret = alloc_rbio_pages(rbio);
if (ret)
goto cleanup;
atomic_set(&rbio->bbio->error, 0);
for (stripe = 0; stripe < bbio->num_stripes; stripe++) {
if (rbio->faila == stripe || rbio->failb == stripe) {
atomic_inc(&rbio->bbio->error);
continue;
}
for (pagenr = 0; pagenr < nr_pages; pagenr++) {
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
if (atomic_read(&rbio->bbio->error) <= rbio->bbio->max_errors) {
__raid_recover_end_io(rbio);
goto out;
} else {
goto cleanup;
}
}
atomic_set(&bbio->stripes_pending, bios_to_read);
while (1) {
bio = bio_list_pop(&bio_list);
if (!bio)
break;
bio->bi_private = rbio;
bio->bi_end_io = raid_recover_end_io;
btrfs_bio_wq_end_io(rbio->fs_info, bio,
BTRFS_WQ_ENDIO_RAID56);
BUG_ON(!test_bit(BIO_UPTODATE, &bio->bi_flags));
submit_bio(READ, bio);
}
out:
return 0;
cleanup:
if (rbio->read_rebuild)
rbio_orig_end_io(rbio, -EIO, 0);
return -EIO;
}
int raid56_parity_recover(struct btrfs_root *root, struct bio *bio,
struct btrfs_bio *bbio, u64 *raid_map,
u64 stripe_len, int mirror_num)
{
struct btrfs_raid_bio *rbio;
int ret;
rbio = alloc_rbio(root, bbio, raid_map, stripe_len);
if (IS_ERR(rbio))
return PTR_ERR(rbio);
rbio->read_rebuild = 1;
bio_list_add(&rbio->bio_list, bio);
rbio->bio_list_bytes = bio->bi_iter.bi_size;
rbio->faila = find_logical_bio_stripe(rbio, bio);
if (rbio->faila == -1) {
BUG();
kfree(raid_map);
kfree(bbio);
kfree(rbio);
return -EIO;
}
if (mirror_num == 3)
rbio->failb = bbio->num_stripes - 2;
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
