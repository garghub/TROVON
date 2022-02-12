static struct bch_cgroup *cgroup_to_bcache(struct cgroup *cgroup)
{
struct cgroup_subsys_state *css;
return cgroup &&
(css = cgroup_subsys_state(cgroup, bcache_subsys_id))
? container_of(css, struct bch_cgroup, css)
: &bcache_default_cgroup;
}
struct bch_cgroup *bch_bio_to_cgroup(struct bio *bio)
{
struct cgroup_subsys_state *css = bio->bi_css
? cgroup_subsys_state(bio->bi_css->cgroup, bcache_subsys_id)
: task_subsys_state(current, bcache_subsys_id);
return css
? container_of(css, struct bch_cgroup, css)
: &bcache_default_cgroup;
}
static ssize_t cache_mode_read(struct cgroup *cgrp, struct cftype *cft,
struct file *file,
char __user *buf, size_t nbytes, loff_t *ppos)
{
char tmp[1024];
int len = bch_snprint_string_list(tmp, PAGE_SIZE, bch_cache_modes,
cgroup_to_bcache(cgrp)->cache_mode + 1);
if (len < 0)
return len;
return simple_read_from_buffer(buf, nbytes, ppos, tmp, len);
}
static int cache_mode_write(struct cgroup *cgrp, struct cftype *cft,
const char *buf)
{
int v = bch_read_string_list(buf, bch_cache_modes);
if (v < 0)
return v;
cgroup_to_bcache(cgrp)->cache_mode = v - 1;
return 0;
}
static u64 bch_verify_read(struct cgroup *cgrp, struct cftype *cft)
{
return cgroup_to_bcache(cgrp)->verify;
}
static int bch_verify_write(struct cgroup *cgrp, struct cftype *cft, u64 val)
{
cgroup_to_bcache(cgrp)->verify = val;
return 0;
}
static u64 bch_cache_hits_read(struct cgroup *cgrp, struct cftype *cft)
{
struct bch_cgroup *bcachecg = cgroup_to_bcache(cgrp);
return atomic_read(&bcachecg->stats.cache_hits);
}
static u64 bch_cache_misses_read(struct cgroup *cgrp, struct cftype *cft)
{
struct bch_cgroup *bcachecg = cgroup_to_bcache(cgrp);
return atomic_read(&bcachecg->stats.cache_misses);
}
static u64 bch_cache_bypass_hits_read(struct cgroup *cgrp,
struct cftype *cft)
{
struct bch_cgroup *bcachecg = cgroup_to_bcache(cgrp);
return atomic_read(&bcachecg->stats.cache_bypass_hits);
}
static u64 bch_cache_bypass_misses_read(struct cgroup *cgrp,
struct cftype *cft)
{
struct bch_cgroup *bcachecg = cgroup_to_bcache(cgrp);
return atomic_read(&bcachecg->stats.cache_bypass_misses);
}
static void init_bch_cgroup(struct bch_cgroup *cg)
{
cg->cache_mode = -1;
}
static struct cgroup_subsys_state *bcachecg_create(struct cgroup *cgroup)
{
struct bch_cgroup *cg;
cg = kzalloc(sizeof(*cg), GFP_KERNEL);
if (!cg)
return ERR_PTR(-ENOMEM);
init_bch_cgroup(cg);
return &cg->css;
}
static void bcachecg_destroy(struct cgroup *cgroup)
{
struct bch_cgroup *cg = cgroup_to_bcache(cgroup);
free_css_id(&bcache_subsys, &cg->css);
kfree(cg);
}
static unsigned cache_mode(struct cached_dev *dc, struct bio *bio)
{
#ifdef CONFIG_CGROUP_BCACHE
int r = bch_bio_to_cgroup(bio)->cache_mode;
if (r >= 0)
return r;
#endif
return BDEV_CACHE_MODE(&dc->sb);
}
static bool verify(struct cached_dev *dc, struct bio *bio)
{
#ifdef CONFIG_CGROUP_BCACHE
if (bch_bio_to_cgroup(bio)->verify)
return true;
#endif
return dc->verify;
}
static void bio_csum(struct bio *bio, struct bkey *k)
{
struct bio_vec *bv;
uint64_t csum = 0;
int i;
bio_for_each_segment(bv, bio, i) {
void *d = kmap(bv->bv_page) + bv->bv_offset;
csum = bch_crc64_update(csum, d, bv->bv_len);
kunmap(bv->bv_page);
}
k->ptr[KEY_PTRS(k)] = csum & (~0ULL >> 1);
}
static void bio_invalidate(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
struct bio *bio = op->cache_bio;
pr_debug("invalidating %i sectors from %llu",
bio_sectors(bio), (uint64_t) bio->bi_sector);
while (bio_sectors(bio)) {
unsigned len = min(bio_sectors(bio), 1U << 14);
if (bch_keylist_realloc(&op->keys, 0, op->c))
goto out;
bio->bi_sector += len;
bio->bi_size -= len << 9;
bch_keylist_add(&op->keys,
&KEY(op->inode, bio->bi_sector, len));
}
op->insert_data_done = true;
bio_put(bio);
out:
continue_at(cl, bch_journal, bcache_wq);
}
void bch_open_buckets_free(struct cache_set *c)
{
struct open_bucket *b;
while (!list_empty(&c->data_buckets)) {
b = list_first_entry(&c->data_buckets,
struct open_bucket, list);
list_del(&b->list);
kfree(b);
}
}
int bch_open_buckets_alloc(struct cache_set *c)
{
int i;
spin_lock_init(&c->data_bucket_lock);
for (i = 0; i < 6; i++) {
struct open_bucket *b = kzalloc(sizeof(*b), GFP_KERNEL);
if (!b)
return -ENOMEM;
list_add(&b->list, &c->data_buckets);
}
return 0;
}
static struct open_bucket *pick_data_bucket(struct cache_set *c,
const struct bkey *search,
struct task_struct *task,
struct bkey *alloc)
{
struct open_bucket *ret, *ret_task = NULL;
list_for_each_entry_reverse(ret, &c->data_buckets, list)
if (!bkey_cmp(&ret->key, search))
goto found;
else if (ret->last == task)
ret_task = ret;
ret = ret_task ?: list_first_entry(&c->data_buckets,
struct open_bucket, list);
found:
if (!ret->sectors_free && KEY_PTRS(alloc)) {
ret->sectors_free = c->sb.bucket_size;
bkey_copy(&ret->key, alloc);
bkey_init(alloc);
}
if (!ret->sectors_free)
ret = NULL;
return ret;
}
static bool bch_alloc_sectors(struct bkey *k, unsigned sectors,
struct search *s)
{
struct cache_set *c = s->op.c;
struct open_bucket *b;
BKEY_PADDED(key) alloc;
struct closure cl, *w = NULL;
unsigned i;
if (s->writeback) {
closure_init_stack(&cl);
w = &cl;
}
bkey_init(&alloc.key);
spin_lock(&c->data_bucket_lock);
while (!(b = pick_data_bucket(c, k, s->task, &alloc.key))) {
unsigned watermark = s->op.write_prio
? WATERMARK_MOVINGGC
: WATERMARK_NONE;
spin_unlock(&c->data_bucket_lock);
if (bch_bucket_alloc_set(c, watermark, &alloc.key, 1, w))
return false;
spin_lock(&c->data_bucket_lock);
}
if (KEY_PTRS(&alloc.key))
__bkey_put(c, &alloc.key);
for (i = 0; i < KEY_PTRS(&b->key); i++)
EBUG_ON(ptr_stale(c, &b->key, i));
for (i = 0; i < KEY_PTRS(&b->key); i++)
k->ptr[i] = b->key.ptr[i];
sectors = min(sectors, b->sectors_free);
SET_KEY_OFFSET(k, KEY_OFFSET(k) + sectors);
SET_KEY_SIZE(k, sectors);
SET_KEY_PTRS(k, KEY_PTRS(&b->key));
list_move_tail(&b->list, &c->data_buckets);
bkey_copy_key(&b->key, k);
b->last = s->task;
b->sectors_free -= sectors;
for (i = 0; i < KEY_PTRS(&b->key); i++) {
SET_PTR_OFFSET(&b->key, i, PTR_OFFSET(&b->key, i) + sectors);
atomic_long_add(sectors,
&PTR_CACHE(c, &b->key, i)->sectors_written);
}
if (b->sectors_free < c->sb.block_size)
b->sectors_free = 0;
if (b->sectors_free)
for (i = 0; i < KEY_PTRS(&b->key); i++)
atomic_inc(&PTR_BUCKET(c, &b->key, i)->pin);
spin_unlock(&c->data_bucket_lock);
return true;
}
static void bch_insert_data_error(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
struct bkey *src = op->keys.bottom, *dst = op->keys.bottom;
while (src != op->keys.top) {
struct bkey *n = bkey_next(src);
SET_KEY_PTRS(src, 0);
bkey_copy(dst, src);
dst = bkey_next(dst);
src = n;
}
op->keys.top = dst;
bch_journal(cl);
}
static void bch_insert_data_endio(struct bio *bio, int error)
{
struct closure *cl = bio->bi_private;
struct btree_op *op = container_of(cl, struct btree_op, cl);
struct search *s = container_of(op, struct search, op);
if (error) {
if (s->writeback)
s->error = error;
else if (s->write)
set_closure_fn(cl, bch_insert_data_error, bcache_wq);
else
set_closure_fn(cl, NULL, NULL);
}
bch_bbio_endio(op->c, bio, error, "writing data to cache");
}
static void bch_insert_data_loop(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
struct search *s = container_of(op, struct search, op);
struct bio *bio = op->cache_bio, *n;
if (op->skip)
return bio_invalidate(cl);
if (atomic_sub_return(bio_sectors(bio), &op->c->sectors_to_gc) < 0) {
set_gc_sectors(op->c);
bch_queue_gc(op->c);
}
do {
unsigned i;
struct bkey *k;
struct bio_set *split = s->d
? s->d->bio_split : op->c->bio_split;
if (bch_keylist_realloc(&op->keys,
1 + (op->csum ? 1 : 0),
op->c))
continue_at(cl, bch_journal, bcache_wq);
k = op->keys.top;
bkey_init(k);
SET_KEY_INODE(k, op->inode);
SET_KEY_OFFSET(k, bio->bi_sector);
if (!bch_alloc_sectors(k, bio_sectors(bio), s))
goto err;
n = bch_bio_split(bio, KEY_SIZE(k), GFP_NOIO, split);
if (!n) {
__bkey_put(op->c, k);
continue_at(cl, bch_insert_data_loop, bcache_wq);
}
n->bi_end_io = bch_insert_data_endio;
n->bi_private = cl;
if (s->writeback) {
SET_KEY_DIRTY(k, true);
for (i = 0; i < KEY_PTRS(k); i++)
SET_GC_MARK(PTR_BUCKET(op->c, k, i),
GC_MARK_DIRTY);
}
SET_KEY_CSUM(k, op->csum);
if (KEY_CSUM(k))
bio_csum(n, k);
pr_debug("%s", pkey(k));
bch_keylist_push(&op->keys);
trace_bcache_cache_insert(n, n->bi_sector, n->bi_bdev);
n->bi_rw |= REQ_WRITE;
bch_submit_bbio(n, op->c, k, 0);
} while (n != bio);
op->insert_data_done = true;
continue_at(cl, bch_journal, bcache_wq);
err:
BUG_ON(s->writeback);
if (s->write) {
op->skip = true;
return bio_invalidate(cl);
} else {
op->insert_data_done = true;
bio_put(bio);
if (!bch_keylist_empty(&op->keys))
continue_at(cl, bch_journal, bcache_wq);
else
closure_return(cl);
}
}
void bch_insert_data(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
bch_keylist_init(&op->keys);
bio_get(op->cache_bio);
bch_insert_data_loop(cl);
}
void bch_btree_insert_async(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
struct search *s = container_of(op, struct search, op);
if (bch_btree_insert(op, op->c)) {
s->error = -ENOMEM;
op->insert_data_done = true;
}
if (op->insert_data_done) {
bch_keylist_free(&op->keys);
closure_return(cl);
} else
continue_at(cl, bch_insert_data_loop, bcache_wq);
}
static void request_endio(struct bio *bio, int error)
{
struct closure *cl = bio->bi_private;
if (error) {
struct search *s = container_of(cl, struct search, cl);
s->error = error;
s->recoverable = false;
}
bio_put(bio);
closure_put(cl);
}
void bch_cache_read_endio(struct bio *bio, int error)
{
struct bbio *b = container_of(bio, struct bbio, bio);
struct closure *cl = bio->bi_private;
struct search *s = container_of(cl, struct search, cl);
if (error)
s->error = error;
else if (ptr_stale(s->op.c, &b->key, 0)) {
atomic_long_inc(&s->op.c->cache_read_races);
s->error = -EINTR;
}
bch_bbio_endio(s->op.c, bio, error, "reading from cache");
}
static void bio_complete(struct search *s)
{
if (s->orig_bio) {
int cpu, rw = bio_data_dir(s->orig_bio);
unsigned long duration = jiffies - s->start_time;
cpu = part_stat_lock();
part_round_stats(cpu, &s->d->disk->part0);
part_stat_add(cpu, &s->d->disk->part0, ticks[rw], duration);
part_stat_unlock();
trace_bcache_request_end(s, s->orig_bio);
bio_endio(s->orig_bio, s->error);
s->orig_bio = NULL;
}
}
static void do_bio_hook(struct search *s)
{
struct bio *bio = &s->bio.bio;
memcpy(bio, s->orig_bio, sizeof(struct bio));
bio->bi_end_io = request_endio;
bio->bi_private = &s->cl;
atomic_set(&bio->bi_cnt, 3);
}
static void search_free(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
bio_complete(s);
if (s->op.cache_bio)
bio_put(s->op.cache_bio);
if (s->unaligned_bvec)
mempool_free(s->bio.bio.bi_io_vec, s->d->unaligned_bvec);
closure_debug_destroy(cl);
mempool_free(s, s->d->c->search);
}
static struct search *search_alloc(struct bio *bio, struct bcache_device *d)
{
struct bio_vec *bv;
struct search *s = mempool_alloc(d->c->search, GFP_NOIO);
memset(s, 0, offsetof(struct search, op.keys));
__closure_init(&s->cl, NULL);
s->op.inode = d->id;
s->op.c = d->c;
s->d = d;
s->op.lock = -1;
s->task = current;
s->orig_bio = bio;
s->write = (bio->bi_rw & REQ_WRITE) != 0;
s->op.flush_journal = (bio->bi_rw & REQ_FLUSH) != 0;
s->op.skip = (bio->bi_rw & REQ_DISCARD) != 0;
s->recoverable = 1;
s->start_time = jiffies;
do_bio_hook(s);
if (bio->bi_size != bio_segments(bio) * PAGE_SIZE) {
bv = mempool_alloc(d->unaligned_bvec, GFP_NOIO);
memcpy(bv, bio_iovec(bio),
sizeof(struct bio_vec) * bio_segments(bio));
s->bio.bio.bi_io_vec = bv;
s->unaligned_bvec = 1;
}
return s;
}
static void btree_read_async(struct closure *cl)
{
struct btree_op *op = container_of(cl, struct btree_op, cl);
int ret = btree_root(search_recurse, op->c, op);
if (ret == -EAGAIN)
continue_at(cl, btree_read_async, bcache_wq);
closure_return(cl);
}
static void cached_dev_bio_complete(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
struct cached_dev *dc = container_of(s->d, struct cached_dev, disk);
search_free(cl);
cached_dev_put(dc);
}
static void cached_dev_read_complete(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
if (s->op.insert_collision)
bch_mark_cache_miss_collision(s);
if (s->op.cache_bio) {
int i;
struct bio_vec *bv;
__bio_for_each_segment(bv, s->op.cache_bio, i, 0)
__free_page(bv->bv_page);
}
cached_dev_bio_complete(cl);
}
static void request_read_error(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
struct bio_vec *bv;
int i;
if (s->recoverable) {
pr_debug("recovering at sector %llu",
(uint64_t) s->orig_bio->bi_sector);
s->error = 0;
bv = s->bio.bio.bi_io_vec;
do_bio_hook(s);
s->bio.bio.bi_io_vec = bv;
if (!s->unaligned_bvec)
bio_for_each_segment(bv, s->orig_bio, i)
bv->bv_offset = 0, bv->bv_len = PAGE_SIZE;
else
memcpy(s->bio.bio.bi_io_vec,
bio_iovec(s->orig_bio),
sizeof(struct bio_vec) *
bio_segments(s->orig_bio));
trace_bcache_read_retry(&s->bio.bio);
closure_bio_submit(&s->bio.bio, &s->cl, s->d);
}
continue_at(cl, cached_dev_read_complete, NULL);
}
static void request_read_done(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
struct cached_dev *dc = container_of(s->d, struct cached_dev, disk);
if (s->op.cache_bio) {
struct bio_vec *src, *dst;
unsigned src_offset, dst_offset, bytes;
void *dst_ptr;
bio_reset(s->op.cache_bio);
s->op.cache_bio->bi_sector = s->cache_miss->bi_sector;
s->op.cache_bio->bi_bdev = s->cache_miss->bi_bdev;
s->op.cache_bio->bi_size = s->cache_bio_sectors << 9;
bch_bio_map(s->op.cache_bio, NULL);
src = bio_iovec(s->op.cache_bio);
dst = bio_iovec(s->cache_miss);
src_offset = src->bv_offset;
dst_offset = dst->bv_offset;
dst_ptr = kmap(dst->bv_page);
while (1) {
if (dst_offset == dst->bv_offset + dst->bv_len) {
kunmap(dst->bv_page);
dst++;
if (dst == bio_iovec_idx(s->cache_miss,
s->cache_miss->bi_vcnt))
break;
dst_offset = dst->bv_offset;
dst_ptr = kmap(dst->bv_page);
}
if (src_offset == src->bv_offset + src->bv_len) {
src++;
if (src == bio_iovec_idx(s->op.cache_bio,
s->op.cache_bio->bi_vcnt))
BUG();
src_offset = src->bv_offset;
}
bytes = min(dst->bv_offset + dst->bv_len - dst_offset,
src->bv_offset + src->bv_len - src_offset);
memcpy(dst_ptr + dst_offset,
page_address(src->bv_page) + src_offset,
bytes);
src_offset += bytes;
dst_offset += bytes;
}
bio_put(s->cache_miss);
s->cache_miss = NULL;
}
if (verify(dc, &s->bio.bio) && s->recoverable)
bch_data_verify(s);
bio_complete(s);
if (s->op.cache_bio &&
!test_bit(CACHE_SET_STOPPING, &s->op.c->flags)) {
s->op.type = BTREE_REPLACE;
closure_call(&s->op.cl, bch_insert_data, NULL, cl);
}
continue_at(cl, cached_dev_read_complete, NULL);
}
static void request_read_done_bh(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
struct cached_dev *dc = container_of(s->d, struct cached_dev, disk);
bch_mark_cache_accounting(s, !s->cache_miss, s->op.skip);
if (s->error)
continue_at_nobarrier(cl, request_read_error, bcache_wq);
else if (s->op.cache_bio || verify(dc, &s->bio.bio))
continue_at_nobarrier(cl, request_read_done, bcache_wq);
else
continue_at_nobarrier(cl, cached_dev_read_complete, NULL);
}
static int cached_dev_cache_miss(struct btree *b, struct search *s,
struct bio *bio, unsigned sectors)
{
int ret = 0;
unsigned reada;
struct cached_dev *dc = container_of(s->d, struct cached_dev, disk);
struct bio *miss;
miss = bch_bio_split(bio, sectors, GFP_NOIO, s->d->bio_split);
if (!miss)
return -EAGAIN;
if (miss == bio)
s->op.lookup_done = true;
miss->bi_end_io = request_endio;
miss->bi_private = &s->cl;
if (s->cache_miss || s->op.skip)
goto out_submit;
if (miss != bio ||
(bio->bi_rw & REQ_RAHEAD) ||
(bio->bi_rw & REQ_META) ||
s->op.c->gc_stats.in_use >= CUTOFF_CACHE_READA)
reada = 0;
else {
reada = min(dc->readahead >> 9,
sectors - bio_sectors(miss));
if (bio_end(miss) + reada > bdev_sectors(miss->bi_bdev))
reada = bdev_sectors(miss->bi_bdev) - bio_end(miss);
}
s->cache_bio_sectors = bio_sectors(miss) + reada;
s->op.cache_bio = bio_alloc_bioset(GFP_NOWAIT,
DIV_ROUND_UP(s->cache_bio_sectors, PAGE_SECTORS),
dc->disk.bio_split);
if (!s->op.cache_bio)
goto out_submit;
s->op.cache_bio->bi_sector = miss->bi_sector;
s->op.cache_bio->bi_bdev = miss->bi_bdev;
s->op.cache_bio->bi_size = s->cache_bio_sectors << 9;
s->op.cache_bio->bi_end_io = request_endio;
s->op.cache_bio->bi_private = &s->cl;
ret = -EINTR;
if (!bch_btree_insert_check_key(b, &s->op, s->op.cache_bio))
goto out_put;
bch_bio_map(s->op.cache_bio, NULL);
if (bch_bio_alloc_pages(s->op.cache_bio, __GFP_NOWARN|GFP_NOIO))
goto out_put;
s->cache_miss = miss;
bio_get(s->op.cache_bio);
trace_bcache_cache_miss(s->orig_bio);
closure_bio_submit(s->op.cache_bio, &s->cl, s->d);
return ret;
out_put:
bio_put(s->op.cache_bio);
s->op.cache_bio = NULL;
out_submit:
closure_bio_submit(miss, &s->cl, s->d);
return ret;
}
static void request_read(struct cached_dev *dc, struct search *s)
{
struct closure *cl = &s->cl;
check_should_skip(dc, s);
closure_call(&s->op.cl, btree_read_async, NULL, cl);
continue_at(cl, request_read_done_bh, NULL);
}
static void cached_dev_write_complete(struct closure *cl)
{
struct search *s = container_of(cl, struct search, cl);
struct cached_dev *dc = container_of(s->d, struct cached_dev, disk);
up_read_non_owner(&dc->writeback_lock);
cached_dev_bio_complete(cl);
}
static bool should_writeback(struct cached_dev *dc, struct bio *bio)
{
unsigned threshold = (bio->bi_rw & REQ_SYNC)
? CUTOFF_WRITEBACK_SYNC
: CUTOFF_WRITEBACK;
return !atomic_read(&dc->disk.detaching) &&
cache_mode(dc, bio) == CACHE_MODE_WRITEBACK &&
dc->disk.c->gc_stats.in_use < threshold;
}
static void request_write(struct cached_dev *dc, struct search *s)
{
struct closure *cl = &s->cl;
struct bio *bio = &s->bio.bio;
struct bkey start, end;
start = KEY(dc->disk.id, bio->bi_sector, 0);
end = KEY(dc->disk.id, bio_end(bio), 0);
bch_keybuf_check_overlapping(&s->op.c->moving_gc_keys, &start, &end);
check_should_skip(dc, s);
down_read_non_owner(&dc->writeback_lock);
if (bch_keybuf_check_overlapping(&dc->writeback_keys, &start, &end)) {
s->op.skip = false;
s->writeback = true;
}
if (bio->bi_rw & REQ_DISCARD)
goto skip;
if (s->op.skip)
goto skip;
if (should_writeback(dc, s->orig_bio))
s->writeback = true;
if (!s->writeback) {
s->op.cache_bio = bio_clone_bioset(bio, GFP_NOIO,
dc->disk.bio_split);
trace_bcache_writethrough(s->orig_bio);
closure_bio_submit(bio, cl, s->d);
} else {
s->op.cache_bio = bio;
trace_bcache_writeback(s->orig_bio);
bch_writeback_add(dc, bio_sectors(bio));
}
out:
closure_call(&s->op.cl, bch_insert_data, NULL, cl);
continue_at(cl, cached_dev_write_complete, NULL);
skip:
s->op.skip = true;
s->op.cache_bio = s->orig_bio;
bio_get(s->op.cache_bio);
trace_bcache_write_skip(s->orig_bio);
if ((bio->bi_rw & REQ_DISCARD) &&
!blk_queue_discard(bdev_get_queue(dc->bdev)))
goto out;
closure_bio_submit(bio, cl, s->d);
goto out;
}
static void request_nodata(struct cached_dev *dc, struct search *s)
{
struct closure *cl = &s->cl;
struct bio *bio = &s->bio.bio;
if (bio->bi_rw & REQ_DISCARD) {
request_write(dc, s);
return;
}
if (s->op.flush_journal)
bch_journal_meta(s->op.c, cl);
closure_bio_submit(bio, cl, s->d);
continue_at(cl, cached_dev_bio_complete, NULL);
}
int bch_get_congested(struct cache_set *c)
{
int i;
if (!c->congested_read_threshold_us &&
!c->congested_write_threshold_us)
return 0;
i = (local_clock_us() - c->congested_last_us) / 1024;
if (i < 0)
return 0;
i += atomic_read(&c->congested);
if (i >= 0)
return 0;
i += CONGESTED_MAX;
return i <= 0 ? 1 : fract_exp_two(i, 6);
}
static void add_sequential(struct task_struct *t)
{
ewma_add(t->sequential_io_avg,
t->sequential_io, 8, 0);
t->sequential_io = 0;
}
static struct hlist_head *iohash(struct cached_dev *dc, uint64_t k)
{
return &dc->io_hash[hash_64(k, RECENT_IO_BITS)];
}
static void check_should_skip(struct cached_dev *dc, struct search *s)
{
struct cache_set *c = s->op.c;
struct bio *bio = &s->bio.bio;
long rand;
int cutoff = bch_get_congested(c);
unsigned mode = cache_mode(dc, bio);
if (atomic_read(&dc->disk.detaching) ||
c->gc_stats.in_use > CUTOFF_CACHE_ADD ||
(bio->bi_rw & REQ_DISCARD))
goto skip;
if (mode == CACHE_MODE_NONE ||
(mode == CACHE_MODE_WRITEAROUND &&
(bio->bi_rw & REQ_WRITE)))
goto skip;
if (bio->bi_sector & (c->sb.block_size - 1) ||
bio_sectors(bio) & (c->sb.block_size - 1)) {
pr_debug("skipping unaligned io");
goto skip;
}
if (!cutoff) {
cutoff = dc->sequential_cutoff >> 9;
if (!cutoff)
goto rescale;
if (mode == CACHE_MODE_WRITEBACK &&
(bio->bi_rw & REQ_WRITE) &&
(bio->bi_rw & REQ_SYNC))
goto rescale;
}
if (dc->sequential_merge) {
struct io *i;
spin_lock(&dc->io_lock);
hlist_for_each_entry(i, iohash(dc, bio->bi_sector), hash)
if (i->last == bio->bi_sector &&
time_before(jiffies, i->jiffies))
goto found;
i = list_first_entry(&dc->io_lru, struct io, lru);
add_sequential(s->task);
i->sequential = 0;
found:
if (i->sequential + bio->bi_size > i->sequential)
i->sequential += bio->bi_size;
i->last = bio_end(bio);
i->jiffies = jiffies + msecs_to_jiffies(5000);
s->task->sequential_io = i->sequential;
hlist_del(&i->hash);
hlist_add_head(&i->hash, iohash(dc, i->last));
list_move_tail(&i->lru, &dc->io_lru);
spin_unlock(&dc->io_lock);
} else {
s->task->sequential_io = bio->bi_size;
add_sequential(s->task);
}
rand = get_random_int();
cutoff -= bitmap_weight(&rand, BITS_PER_LONG);
if (cutoff <= (int) (max(s->task->sequential_io,
s->task->sequential_io_avg) >> 9))
goto skip;
rescale:
bch_rescale_priorities(c, bio_sectors(bio));
return;
skip:
bch_mark_sectors_bypassed(s, bio_sectors(bio));
s->op.skip = true;
}
static void cached_dev_make_request(struct request_queue *q, struct bio *bio)
{
struct search *s;
struct bcache_device *d = bio->bi_bdev->bd_disk->private_data;
struct cached_dev *dc = container_of(d, struct cached_dev, disk);
int cpu, rw = bio_data_dir(bio);
cpu = part_stat_lock();
part_stat_inc(cpu, &d->disk->part0, ios[rw]);
part_stat_add(cpu, &d->disk->part0, sectors[rw], bio_sectors(bio));
part_stat_unlock();
bio->bi_bdev = dc->bdev;
bio->bi_sector += dc->sb.data_offset;
if (cached_dev_get(dc)) {
s = search_alloc(bio, d);
trace_bcache_request_start(s, bio);
if (!bio_has_data(bio))
request_nodata(dc, s);
else if (rw)
request_write(dc, s);
else
request_read(dc, s);
} else {
if ((bio->bi_rw & REQ_DISCARD) &&
!blk_queue_discard(bdev_get_queue(dc->bdev)))
bio_endio(bio, 0);
else
bch_generic_make_request(bio, &d->bio_split_hook);
}
}
static int cached_dev_ioctl(struct bcache_device *d, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct cached_dev *dc = container_of(d, struct cached_dev, disk);
return __blkdev_driver_ioctl(dc->bdev, mode, cmd, arg);
}
static int cached_dev_congested(void *data, int bits)
{
struct bcache_device *d = data;
struct cached_dev *dc = container_of(d, struct cached_dev, disk);
struct request_queue *q = bdev_get_queue(dc->bdev);
int ret = 0;
if (bdi_congested(&q->backing_dev_info, bits))
return 1;
if (cached_dev_get(dc)) {
unsigned i;
struct cache *ca;
for_each_cache(ca, d->c, i) {
q = bdev_get_queue(ca->bdev);
ret |= bdi_congested(&q->backing_dev_info, bits);
}
cached_dev_put(dc);
}
return ret;
}
void bch_cached_dev_request_init(struct cached_dev *dc)
{
struct gendisk *g = dc->disk.disk;
g->queue->make_request_fn = cached_dev_make_request;
g->queue->backing_dev_info.congested_fn = cached_dev_congested;
dc->disk.cache_miss = cached_dev_cache_miss;
dc->disk.ioctl = cached_dev_ioctl;
}
static int flash_dev_cache_miss(struct btree *b, struct search *s,
struct bio *bio, unsigned sectors)
{
while (bio->bi_idx != bio->bi_vcnt) {
struct bio_vec *bv = bio_iovec(bio);
unsigned j = min(bv->bv_len >> 9, sectors);
void *p = kmap(bv->bv_page);
memset(p + bv->bv_offset, 0, j << 9);
kunmap(bv->bv_page);
bv->bv_len -= j << 9;
bv->bv_offset += j << 9;
if (bv->bv_len)
return 0;
bio->bi_sector += j;
bio->bi_size -= j << 9;
bio->bi_idx++;
sectors -= j;
}
s->op.lookup_done = true;
return 0;
}
static void flash_dev_make_request(struct request_queue *q, struct bio *bio)
{
struct search *s;
struct closure *cl;
struct bcache_device *d = bio->bi_bdev->bd_disk->private_data;
int cpu, rw = bio_data_dir(bio);
cpu = part_stat_lock();
part_stat_inc(cpu, &d->disk->part0, ios[rw]);
part_stat_add(cpu, &d->disk->part0, sectors[rw], bio_sectors(bio));
part_stat_unlock();
s = search_alloc(bio, d);
cl = &s->cl;
bio = &s->bio.bio;
trace_bcache_request_start(s, bio);
if (bio_has_data(bio) && !rw) {
closure_call(&s->op.cl, btree_read_async, NULL, cl);
} else if (bio_has_data(bio) || s->op.skip) {
bch_keybuf_check_overlapping(&s->op.c->moving_gc_keys,
&KEY(d->id, bio->bi_sector, 0),
&KEY(d->id, bio_end(bio), 0));
s->writeback = true;
s->op.cache_bio = bio;
closure_call(&s->op.cl, bch_insert_data, NULL, cl);
} else {
if (s->op.flush_journal)
bch_journal_meta(s->op.c, cl);
}
continue_at(cl, search_free, NULL);
}
static int flash_dev_ioctl(struct bcache_device *d, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
return -ENOTTY;
}
static int flash_dev_congested(void *data, int bits)
{
struct bcache_device *d = data;
struct request_queue *q;
struct cache *ca;
unsigned i;
int ret = 0;
for_each_cache(ca, d->c, i) {
q = bdev_get_queue(ca->bdev);
ret |= bdi_congested(&q->backing_dev_info, bits);
}
return ret;
}
void bch_flash_dev_request_init(struct bcache_device *d)
{
struct gendisk *g = d->disk;
g->queue->make_request_fn = flash_dev_make_request;
g->queue->backing_dev_info.congested_fn = flash_dev_congested;
d->cache_miss = flash_dev_cache_miss;
d->ioctl = flash_dev_ioctl;
}
void bch_request_exit(void)
{
#ifdef CONFIG_CGROUP_BCACHE
cgroup_unload_subsys(&bcache_subsys);
#endif
if (bch_search_cache)
kmem_cache_destroy(bch_search_cache);
}
int __init bch_request_init(void)
{
bch_search_cache = KMEM_CACHE(search, 0);
if (!bch_search_cache)
return -ENOMEM;
#ifdef CONFIG_CGROUP_BCACHE
cgroup_load_subsys(&bcache_subsys);
init_bch_cgroup(&bcache_default_cgroup);
cgroup_add_cftypes(&bcache_subsys, bch_files);
#endif
return 0;
}
