static struct kmem_cache *bio_find_or_create_slab(unsigned int extra_size)
{
unsigned int sz = sizeof(struct bio) + extra_size;
struct kmem_cache *slab = NULL;
struct bio_slab *bslab, *new_bio_slabs;
unsigned int new_bio_slab_max;
unsigned int i, entry = -1;
mutex_lock(&bio_slab_lock);
i = 0;
while (i < bio_slab_nr) {
bslab = &bio_slabs[i];
if (!bslab->slab && entry == -1)
entry = i;
else if (bslab->slab_size == sz) {
slab = bslab->slab;
bslab->slab_ref++;
break;
}
i++;
}
if (slab)
goto out_unlock;
if (bio_slab_nr == bio_slab_max && entry == -1) {
new_bio_slab_max = bio_slab_max << 1;
new_bio_slabs = krealloc(bio_slabs,
new_bio_slab_max * sizeof(struct bio_slab),
GFP_KERNEL);
if (!new_bio_slabs)
goto out_unlock;
bio_slab_max = new_bio_slab_max;
bio_slabs = new_bio_slabs;
}
if (entry == -1)
entry = bio_slab_nr++;
bslab = &bio_slabs[entry];
snprintf(bslab->name, sizeof(bslab->name), "bio-%d", entry);
slab = kmem_cache_create(bslab->name, sz, 0, SLAB_HWCACHE_ALIGN, NULL);
if (!slab)
goto out_unlock;
bslab->slab = slab;
bslab->slab_ref = 1;
bslab->slab_size = sz;
out_unlock:
mutex_unlock(&bio_slab_lock);
return slab;
}
static void bio_put_slab(struct bio_set *bs)
{
struct bio_slab *bslab = NULL;
unsigned int i;
mutex_lock(&bio_slab_lock);
for (i = 0; i < bio_slab_nr; i++) {
if (bs->bio_slab == bio_slabs[i].slab) {
bslab = &bio_slabs[i];
break;
}
}
if (WARN(!bslab, KERN_ERR "bio: unable to find slab!\n"))
goto out;
WARN_ON(!bslab->slab_ref);
if (--bslab->slab_ref)
goto out;
kmem_cache_destroy(bslab->slab);
bslab->slab = NULL;
out:
mutex_unlock(&bio_slab_lock);
}
unsigned int bvec_nr_vecs(unsigned short idx)
{
return bvec_slabs[idx].nr_vecs;
}
void bvec_free(mempool_t *pool, struct bio_vec *bv, unsigned int idx)
{
BIO_BUG_ON(idx >= BIOVEC_NR_POOLS);
if (idx == BIOVEC_MAX_IDX)
mempool_free(bv, pool);
else {
struct biovec_slab *bvs = bvec_slabs + idx;
kmem_cache_free(bvs->slab, bv);
}
}
struct bio_vec *bvec_alloc(gfp_t gfp_mask, int nr, unsigned long *idx,
mempool_t *pool)
{
struct bio_vec *bvl;
switch (nr) {
case 1:
*idx = 0;
break;
case 2 ... 4:
*idx = 1;
break;
case 5 ... 16:
*idx = 2;
break;
case 17 ... 64:
*idx = 3;
break;
case 65 ... 128:
*idx = 4;
break;
case 129 ... BIO_MAX_PAGES:
*idx = 5;
break;
default:
return NULL;
}
if (*idx == BIOVEC_MAX_IDX) {
fallback:
bvl = mempool_alloc(pool, gfp_mask);
} else {
struct biovec_slab *bvs = bvec_slabs + *idx;
gfp_t __gfp_mask = gfp_mask & ~(__GFP_WAIT | __GFP_IO);
__gfp_mask |= __GFP_NOMEMALLOC | __GFP_NORETRY | __GFP_NOWARN;
bvl = kmem_cache_alloc(bvs->slab, __gfp_mask);
if (unlikely(!bvl && (gfp_mask & __GFP_WAIT))) {
*idx = BIOVEC_MAX_IDX;
goto fallback;
}
}
return bvl;
}
static void __bio_free(struct bio *bio)
{
bio_disassociate_task(bio);
if (bio_integrity(bio))
bio_integrity_free(bio);
}
static void bio_free(struct bio *bio)
{
struct bio_set *bs = bio->bi_pool;
void *p;
__bio_free(bio);
if (bs) {
if (bio_flagged(bio, BIO_OWNS_VEC))
bvec_free(bs->bvec_pool, bio->bi_io_vec, BIO_POOL_IDX(bio));
p = bio;
p -= bs->front_pad;
mempool_free(p, bs->bio_pool);
} else {
kfree(bio);
}
}
void bio_init(struct bio *bio)
{
memset(bio, 0, sizeof(*bio));
bio->bi_flags = 1 << BIO_UPTODATE;
atomic_set(&bio->bi_remaining, 1);
atomic_set(&bio->bi_cnt, 1);
}
void bio_reset(struct bio *bio)
{
unsigned long flags = bio->bi_flags & (~0UL << BIO_RESET_BITS);
__bio_free(bio);
memset(bio, 0, BIO_RESET_BYTES);
bio->bi_flags = flags|(1 << BIO_UPTODATE);
atomic_set(&bio->bi_remaining, 1);
}
static void bio_chain_endio(struct bio *bio, int error)
{
bio_endio(bio->bi_private, error);
bio_put(bio);
}
void bio_chain(struct bio *bio, struct bio *parent)
{
BUG_ON(bio->bi_private || bio->bi_end_io);
bio->bi_private = parent;
bio->bi_end_io = bio_chain_endio;
atomic_inc(&parent->bi_remaining);
}
static void bio_alloc_rescue(struct work_struct *work)
{
struct bio_set *bs = container_of(work, struct bio_set, rescue_work);
struct bio *bio;
while (1) {
spin_lock(&bs->rescue_lock);
bio = bio_list_pop(&bs->rescue_list);
spin_unlock(&bs->rescue_lock);
if (!bio)
break;
generic_make_request(bio);
}
}
static void punt_bios_to_rescuer(struct bio_set *bs)
{
struct bio_list punt, nopunt;
struct bio *bio;
bio_list_init(&punt);
bio_list_init(&nopunt);
while ((bio = bio_list_pop(current->bio_list)))
bio_list_add(bio->bi_pool == bs ? &punt : &nopunt, bio);
*current->bio_list = nopunt;
spin_lock(&bs->rescue_lock);
bio_list_merge(&bs->rescue_list, &punt);
spin_unlock(&bs->rescue_lock);
queue_work(bs->rescue_workqueue, &bs->rescue_work);
}
struct bio *bio_alloc_bioset(gfp_t gfp_mask, int nr_iovecs, struct bio_set *bs)
{
gfp_t saved_gfp = gfp_mask;
unsigned front_pad;
unsigned inline_vecs;
unsigned long idx = BIO_POOL_NONE;
struct bio_vec *bvl = NULL;
struct bio *bio;
void *p;
if (!bs) {
if (nr_iovecs > UIO_MAXIOV)
return NULL;
p = kmalloc(sizeof(struct bio) +
nr_iovecs * sizeof(struct bio_vec),
gfp_mask);
front_pad = 0;
inline_vecs = nr_iovecs;
} else {
if (current->bio_list && !bio_list_empty(current->bio_list))
gfp_mask &= ~__GFP_WAIT;
p = mempool_alloc(bs->bio_pool, gfp_mask);
if (!p && gfp_mask != saved_gfp) {
punt_bios_to_rescuer(bs);
gfp_mask = saved_gfp;
p = mempool_alloc(bs->bio_pool, gfp_mask);
}
front_pad = bs->front_pad;
inline_vecs = BIO_INLINE_VECS;
}
if (unlikely(!p))
return NULL;
bio = p + front_pad;
bio_init(bio);
if (nr_iovecs > inline_vecs) {
bvl = bvec_alloc(gfp_mask, nr_iovecs, &idx, bs->bvec_pool);
if (!bvl && gfp_mask != saved_gfp) {
punt_bios_to_rescuer(bs);
gfp_mask = saved_gfp;
bvl = bvec_alloc(gfp_mask, nr_iovecs, &idx, bs->bvec_pool);
}
if (unlikely(!bvl))
goto err_free;
bio->bi_flags |= 1 << BIO_OWNS_VEC;
} else if (nr_iovecs) {
bvl = bio->bi_inline_vecs;
}
bio->bi_pool = bs;
bio->bi_flags |= idx << BIO_POOL_OFFSET;
bio->bi_max_vecs = nr_iovecs;
bio->bi_io_vec = bvl;
return bio;
err_free:
mempool_free(p, bs->bio_pool);
return NULL;
}
void zero_fill_bio(struct bio *bio)
{
unsigned long flags;
struct bio_vec bv;
struct bvec_iter iter;
bio_for_each_segment(bv, bio, iter) {
char *data = bvec_kmap_irq(&bv, &flags);
memset(data, 0, bv.bv_len);
flush_dcache_page(bv.bv_page);
bvec_kunmap_irq(data, &flags);
}
}
void bio_put(struct bio *bio)
{
BIO_BUG_ON(!atomic_read(&bio->bi_cnt));
if (atomic_dec_and_test(&bio->bi_cnt))
bio_free(bio);
}
inline int bio_phys_segments(struct request_queue *q, struct bio *bio)
{
if (unlikely(!bio_flagged(bio, BIO_SEG_VALID)))
blk_recount_segments(q, bio);
return bio->bi_phys_segments;
}
void __bio_clone_fast(struct bio *bio, struct bio *bio_src)
{
BUG_ON(bio->bi_pool && BIO_POOL_IDX(bio) != BIO_POOL_NONE);
bio->bi_bdev = bio_src->bi_bdev;
bio->bi_flags |= 1 << BIO_CLONED;
bio->bi_rw = bio_src->bi_rw;
bio->bi_iter = bio_src->bi_iter;
bio->bi_io_vec = bio_src->bi_io_vec;
}
struct bio *bio_clone_fast(struct bio *bio, gfp_t gfp_mask, struct bio_set *bs)
{
struct bio *b;
b = bio_alloc_bioset(gfp_mask, 0, bs);
if (!b)
return NULL;
__bio_clone_fast(b, bio);
if (bio_integrity(bio)) {
int ret;
ret = bio_integrity_clone(b, bio, gfp_mask);
if (ret < 0) {
bio_put(b);
return NULL;
}
}
return b;
}
struct bio *bio_clone_bioset(struct bio *bio_src, gfp_t gfp_mask,
struct bio_set *bs)
{
struct bvec_iter iter;
struct bio_vec bv;
struct bio *bio;
bio = bio_alloc_bioset(gfp_mask, bio_segments(bio_src), bs);
if (!bio)
return NULL;
bio->bi_bdev = bio_src->bi_bdev;
bio->bi_rw = bio_src->bi_rw;
bio->bi_iter.bi_sector = bio_src->bi_iter.bi_sector;
bio->bi_iter.bi_size = bio_src->bi_iter.bi_size;
if (bio->bi_rw & REQ_DISCARD)
goto integrity_clone;
if (bio->bi_rw & REQ_WRITE_SAME) {
bio->bi_io_vec[bio->bi_vcnt++] = bio_src->bi_io_vec[0];
goto integrity_clone;
}
bio_for_each_segment(bv, bio_src, iter)
bio->bi_io_vec[bio->bi_vcnt++] = bv;
integrity_clone:
if (bio_integrity(bio_src)) {
int ret;
ret = bio_integrity_clone(bio, bio_src, gfp_mask);
if (ret < 0) {
bio_put(bio);
return NULL;
}
}
return bio;
}
int bio_get_nr_vecs(struct block_device *bdev)
{
struct request_queue *q = bdev_get_queue(bdev);
int nr_pages;
nr_pages = min_t(unsigned,
queue_max_segments(q),
queue_max_sectors(q) / (PAGE_SIZE >> 9) + 1);
return min_t(unsigned, nr_pages, BIO_MAX_PAGES);
}
static int __bio_add_page(struct request_queue *q, struct bio *bio, struct page
*page, unsigned int len, unsigned int offset,
unsigned int max_sectors)
{
int retried_segments = 0;
struct bio_vec *bvec;
if (unlikely(bio_flagged(bio, BIO_CLONED)))
return 0;
if (((bio->bi_iter.bi_size + len) >> 9) > max_sectors)
return 0;
if (bio->bi_vcnt > 0) {
struct bio_vec *prev = &bio->bi_io_vec[bio->bi_vcnt - 1];
if (page == prev->bv_page &&
offset == prev->bv_offset + prev->bv_len) {
unsigned int prev_bv_len = prev->bv_len;
prev->bv_len += len;
if (q->merge_bvec_fn) {
struct bvec_merge_data bvm = {
.bi_bdev = bio->bi_bdev,
.bi_sector = bio->bi_iter.bi_sector,
.bi_size = bio->bi_iter.bi_size -
prev_bv_len,
.bi_rw = bio->bi_rw,
};
if (q->merge_bvec_fn(q, &bvm, prev) < prev->bv_len) {
prev->bv_len -= len;
return 0;
}
}
goto done;
}
if (q->queue_flags & (1 << QUEUE_FLAG_SG_GAPS) &&
bvec_gap_to_prev(prev, offset))
return 0;
}
if (bio->bi_vcnt >= bio->bi_max_vecs)
return 0;
while (bio->bi_phys_segments >= queue_max_segments(q)) {
if (retried_segments)
return 0;
retried_segments = 1;
blk_recount_segments(q, bio);
}
bvec = &bio->bi_io_vec[bio->bi_vcnt];
bvec->bv_page = page;
bvec->bv_len = len;
bvec->bv_offset = offset;
if (q->merge_bvec_fn) {
struct bvec_merge_data bvm = {
.bi_bdev = bio->bi_bdev,
.bi_sector = bio->bi_iter.bi_sector,
.bi_size = bio->bi_iter.bi_size,
.bi_rw = bio->bi_rw,
};
if (q->merge_bvec_fn(q, &bvm, bvec) < bvec->bv_len) {
bvec->bv_page = NULL;
bvec->bv_len = 0;
bvec->bv_offset = 0;
return 0;
}
}
if (bio->bi_vcnt && (BIOVEC_PHYS_MERGEABLE(bvec-1, bvec)))
bio->bi_flags &= ~(1 << BIO_SEG_VALID);
bio->bi_vcnt++;
bio->bi_phys_segments++;
done:
bio->bi_iter.bi_size += len;
return len;
}
int bio_add_pc_page(struct request_queue *q, struct bio *bio, struct page *page,
unsigned int len, unsigned int offset)
{
return __bio_add_page(q, bio, page, len, offset,
queue_max_hw_sectors(q));
}
int bio_add_page(struct bio *bio, struct page *page, unsigned int len,
unsigned int offset)
{
struct request_queue *q = bdev_get_queue(bio->bi_bdev);
unsigned int max_sectors;
max_sectors = blk_max_size_offset(q, bio->bi_iter.bi_sector);
if ((max_sectors < (len >> 9)) && !bio->bi_iter.bi_size)
max_sectors = len >> 9;
return __bio_add_page(q, bio, page, len, offset, max_sectors);
}
static void submit_bio_wait_endio(struct bio *bio, int error)
{
struct submit_bio_ret *ret = bio->bi_private;
ret->error = error;
complete(&ret->event);
}
int submit_bio_wait(int rw, struct bio *bio)
{
struct submit_bio_ret ret;
rw |= REQ_SYNC;
init_completion(&ret.event);
bio->bi_private = &ret;
bio->bi_end_io = submit_bio_wait_endio;
submit_bio(rw, bio);
wait_for_completion(&ret.event);
return ret.error;
}
void bio_advance(struct bio *bio, unsigned bytes)
{
if (bio_integrity(bio))
bio_integrity_advance(bio, bytes);
bio_advance_iter(bio, &bio->bi_iter, bytes);
}
int bio_alloc_pages(struct bio *bio, gfp_t gfp_mask)
{
int i;
struct bio_vec *bv;
bio_for_each_segment_all(bv, bio, i) {
bv->bv_page = alloc_page(gfp_mask);
if (!bv->bv_page) {
while (--bv >= bio->bi_io_vec)
__free_page(bv->bv_page);
return -ENOMEM;
}
}
return 0;
}
void bio_copy_data(struct bio *dst, struct bio *src)
{
struct bvec_iter src_iter, dst_iter;
struct bio_vec src_bv, dst_bv;
void *src_p, *dst_p;
unsigned bytes;
src_iter = src->bi_iter;
dst_iter = dst->bi_iter;
while (1) {
if (!src_iter.bi_size) {
src = src->bi_next;
if (!src)
break;
src_iter = src->bi_iter;
}
if (!dst_iter.bi_size) {
dst = dst->bi_next;
if (!dst)
break;
dst_iter = dst->bi_iter;
}
src_bv = bio_iter_iovec(src, src_iter);
dst_bv = bio_iter_iovec(dst, dst_iter);
bytes = min(src_bv.bv_len, dst_bv.bv_len);
src_p = kmap_atomic(src_bv.bv_page);
dst_p = kmap_atomic(dst_bv.bv_page);
memcpy(dst_p + dst_bv.bv_offset,
src_p + src_bv.bv_offset,
bytes);
kunmap_atomic(dst_p);
kunmap_atomic(src_p);
bio_advance_iter(src, &src_iter, bytes);
bio_advance_iter(dst, &dst_iter, bytes);
}
}
static void bio_set_map_data(struct bio_map_data *bmd, struct bio *bio,
const struct sg_iovec *iov, int iov_count,
int is_our_pages)
{
memcpy(bmd->sgvecs, iov, sizeof(struct sg_iovec) * iov_count);
bmd->nr_sgvecs = iov_count;
bmd->is_our_pages = is_our_pages;
bio->bi_private = bmd;
}
static struct bio_map_data *bio_alloc_map_data(unsigned int iov_count,
gfp_t gfp_mask)
{
if (iov_count > UIO_MAXIOV)
return NULL;
return kmalloc(sizeof(struct bio_map_data) +
sizeof(struct sg_iovec) * iov_count, gfp_mask);
}
static int __bio_copy_iov(struct bio *bio, const struct sg_iovec *iov, int iov_count,
int to_user, int from_user, int do_free_page)
{
int ret = 0, i;
struct bio_vec *bvec;
int iov_idx = 0;
unsigned int iov_off = 0;
bio_for_each_segment_all(bvec, bio, i) {
char *bv_addr = page_address(bvec->bv_page);
unsigned int bv_len = bvec->bv_len;
while (bv_len && iov_idx < iov_count) {
unsigned int bytes;
char __user *iov_addr;
bytes = min_t(unsigned int,
iov[iov_idx].iov_len - iov_off, bv_len);
iov_addr = iov[iov_idx].iov_base + iov_off;
if (!ret) {
if (to_user)
ret = copy_to_user(iov_addr, bv_addr,
bytes);
if (from_user)
ret = copy_from_user(bv_addr, iov_addr,
bytes);
if (ret)
ret = -EFAULT;
}
bv_len -= bytes;
bv_addr += bytes;
iov_addr += bytes;
iov_off += bytes;
if (iov[iov_idx].iov_len == iov_off) {
iov_idx++;
iov_off = 0;
}
}
if (do_free_page)
__free_page(bvec->bv_page);
}
return ret;
}
int bio_uncopy_user(struct bio *bio)
{
struct bio_map_data *bmd = bio->bi_private;
struct bio_vec *bvec;
int ret = 0, i;
if (!bio_flagged(bio, BIO_NULL_MAPPED)) {
if (current->mm)
ret = __bio_copy_iov(bio, bmd->sgvecs, bmd->nr_sgvecs,
bio_data_dir(bio) == READ,
0, bmd->is_our_pages);
else if (bmd->is_our_pages)
bio_for_each_segment_all(bvec, bio, i)
__free_page(bvec->bv_page);
}
kfree(bmd);
bio_put(bio);
return ret;
}
struct bio *bio_copy_user_iov(struct request_queue *q,
struct rq_map_data *map_data,
const struct sg_iovec *iov, int iov_count,
int write_to_vm, gfp_t gfp_mask)
{
struct bio_map_data *bmd;
struct bio_vec *bvec;
struct page *page;
struct bio *bio;
int i, ret;
int nr_pages = 0;
unsigned int len = 0;
unsigned int offset = map_data ? map_data->offset & ~PAGE_MASK : 0;
for (i = 0; i < iov_count; i++) {
unsigned long uaddr;
unsigned long end;
unsigned long start;
uaddr = (unsigned long)iov[i].iov_base;
end = (uaddr + iov[i].iov_len + PAGE_SIZE - 1) >> PAGE_SHIFT;
start = uaddr >> PAGE_SHIFT;
if (end < start)
return ERR_PTR(-EINVAL);
nr_pages += end - start;
len += iov[i].iov_len;
}
if (offset)
nr_pages++;
bmd = bio_alloc_map_data(iov_count, gfp_mask);
if (!bmd)
return ERR_PTR(-ENOMEM);
ret = -ENOMEM;
bio = bio_kmalloc(gfp_mask, nr_pages);
if (!bio)
goto out_bmd;
if (!write_to_vm)
bio->bi_rw |= REQ_WRITE;
ret = 0;
if (map_data) {
nr_pages = 1 << map_data->page_order;
i = map_data->offset / PAGE_SIZE;
}
while (len) {
unsigned int bytes = PAGE_SIZE;
bytes -= offset;
if (bytes > len)
bytes = len;
if (map_data) {
if (i == map_data->nr_entries * nr_pages) {
ret = -ENOMEM;
break;
}
page = map_data->pages[i / nr_pages];
page += (i % nr_pages);
i++;
} else {
page = alloc_page(q->bounce_gfp | gfp_mask);
if (!page) {
ret = -ENOMEM;
break;
}
}
if (bio_add_pc_page(q, bio, page, bytes, offset) < bytes)
break;
len -= bytes;
offset = 0;
}
if (ret)
goto cleanup;
if ((!write_to_vm && (!map_data || !map_data->null_mapped)) ||
(map_data && map_data->from_user)) {
ret = __bio_copy_iov(bio, iov, iov_count, 0, 1, 0);
if (ret)
goto cleanup;
}
bio_set_map_data(bmd, bio, iov, iov_count, map_data ? 0 : 1);
return bio;
cleanup:
if (!map_data)
bio_for_each_segment_all(bvec, bio, i)
__free_page(bvec->bv_page);
bio_put(bio);
out_bmd:
kfree(bmd);
return ERR_PTR(ret);
}
struct bio *bio_copy_user(struct request_queue *q, struct rq_map_data *map_data,
unsigned long uaddr, unsigned int len,
int write_to_vm, gfp_t gfp_mask)
{
struct sg_iovec iov;
iov.iov_base = (void __user *)uaddr;
iov.iov_len = len;
return bio_copy_user_iov(q, map_data, &iov, 1, write_to_vm, gfp_mask);
}
static struct bio *__bio_map_user_iov(struct request_queue *q,
struct block_device *bdev,
const struct sg_iovec *iov, int iov_count,
int write_to_vm, gfp_t gfp_mask)
{
int i, j;
int nr_pages = 0;
struct page **pages;
struct bio *bio;
int cur_page = 0;
int ret, offset;
for (i = 0; i < iov_count; i++) {
unsigned long uaddr = (unsigned long)iov[i].iov_base;
unsigned long len = iov[i].iov_len;
unsigned long end = (uaddr + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
unsigned long start = uaddr >> PAGE_SHIFT;
if (end < start)
return ERR_PTR(-EINVAL);
nr_pages += end - start;
if (uaddr & queue_dma_alignment(q))
return ERR_PTR(-EINVAL);
}
if (!nr_pages)
return ERR_PTR(-EINVAL);
bio = bio_kmalloc(gfp_mask, nr_pages);
if (!bio)
return ERR_PTR(-ENOMEM);
ret = -ENOMEM;
pages = kcalloc(nr_pages, sizeof(struct page *), gfp_mask);
if (!pages)
goto out;
for (i = 0; i < iov_count; i++) {
unsigned long uaddr = (unsigned long)iov[i].iov_base;
unsigned long len = iov[i].iov_len;
unsigned long end = (uaddr + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
unsigned long start = uaddr >> PAGE_SHIFT;
const int local_nr_pages = end - start;
const int page_limit = cur_page + local_nr_pages;
ret = get_user_pages_fast(uaddr, local_nr_pages,
write_to_vm, &pages[cur_page]);
if (ret < local_nr_pages) {
ret = -EFAULT;
goto out_unmap;
}
offset = uaddr & ~PAGE_MASK;
for (j = cur_page; j < page_limit; j++) {
unsigned int bytes = PAGE_SIZE - offset;
if (len <= 0)
break;
if (bytes > len)
bytes = len;
if (bio_add_pc_page(q, bio, pages[j], bytes, offset) <
bytes)
break;
len -= bytes;
offset = 0;
}
cur_page = j;
while (j < page_limit)
page_cache_release(pages[j++]);
}
kfree(pages);
if (!write_to_vm)
bio->bi_rw |= REQ_WRITE;
bio->bi_bdev = bdev;
bio->bi_flags |= (1 << BIO_USER_MAPPED);
return bio;
out_unmap:
for (i = 0; i < nr_pages; i++) {
if(!pages[i])
break;
page_cache_release(pages[i]);
}
out:
kfree(pages);
bio_put(bio);
return ERR_PTR(ret);
}
struct bio *bio_map_user(struct request_queue *q, struct block_device *bdev,
unsigned long uaddr, unsigned int len, int write_to_vm,
gfp_t gfp_mask)
{
struct sg_iovec iov;
iov.iov_base = (void __user *)uaddr;
iov.iov_len = len;
return bio_map_user_iov(q, bdev, &iov, 1, write_to_vm, gfp_mask);
}
struct bio *bio_map_user_iov(struct request_queue *q, struct block_device *bdev,
const struct sg_iovec *iov, int iov_count,
int write_to_vm, gfp_t gfp_mask)
{
struct bio *bio;
bio = __bio_map_user_iov(q, bdev, iov, iov_count, write_to_vm,
gfp_mask);
if (IS_ERR(bio))
return bio;
bio_get(bio);
return bio;
}
static void __bio_unmap_user(struct bio *bio)
{
struct bio_vec *bvec;
int i;
bio_for_each_segment_all(bvec, bio, i) {
if (bio_data_dir(bio) == READ)
set_page_dirty_lock(bvec->bv_page);
page_cache_release(bvec->bv_page);
}
bio_put(bio);
}
void bio_unmap_user(struct bio *bio)
{
__bio_unmap_user(bio);
bio_put(bio);
}
static void bio_map_kern_endio(struct bio *bio, int err)
{
bio_put(bio);
}
static struct bio *__bio_map_kern(struct request_queue *q, void *data,
unsigned int len, gfp_t gfp_mask)
{
unsigned long kaddr = (unsigned long)data;
unsigned long end = (kaddr + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
unsigned long start = kaddr >> PAGE_SHIFT;
const int nr_pages = end - start;
int offset, i;
struct bio *bio;
bio = bio_kmalloc(gfp_mask, nr_pages);
if (!bio)
return ERR_PTR(-ENOMEM);
offset = offset_in_page(kaddr);
for (i = 0; i < nr_pages; i++) {
unsigned int bytes = PAGE_SIZE - offset;
if (len <= 0)
break;
if (bytes > len)
bytes = len;
if (bio_add_pc_page(q, bio, virt_to_page(data), bytes,
offset) < bytes)
break;
data += bytes;
len -= bytes;
offset = 0;
}
bio->bi_end_io = bio_map_kern_endio;
return bio;
}
struct bio *bio_map_kern(struct request_queue *q, void *data, unsigned int len,
gfp_t gfp_mask)
{
struct bio *bio;
bio = __bio_map_kern(q, data, len, gfp_mask);
if (IS_ERR(bio))
return bio;
if (bio->bi_iter.bi_size == len)
return bio;
bio_put(bio);
return ERR_PTR(-EINVAL);
}
static void bio_copy_kern_endio(struct bio *bio, int err)
{
struct bio_vec *bvec;
const int read = bio_data_dir(bio) == READ;
struct bio_map_data *bmd = bio->bi_private;
int i;
char *p = bmd->sgvecs[0].iov_base;
bio_for_each_segment_all(bvec, bio, i) {
char *addr = page_address(bvec->bv_page);
if (read)
memcpy(p, addr, bvec->bv_len);
__free_page(bvec->bv_page);
p += bvec->bv_len;
}
kfree(bmd);
bio_put(bio);
}
struct bio *bio_copy_kern(struct request_queue *q, void *data, unsigned int len,
gfp_t gfp_mask, int reading)
{
struct bio *bio;
struct bio_vec *bvec;
int i;
bio = bio_copy_user(q, NULL, (unsigned long)data, len, 1, gfp_mask);
if (IS_ERR(bio))
return bio;
if (!reading) {
void *p = data;
bio_for_each_segment_all(bvec, bio, i) {
char *addr = page_address(bvec->bv_page);
memcpy(addr, p, bvec->bv_len);
p += bvec->bv_len;
}
}
bio->bi_end_io = bio_copy_kern_endio;
return bio;
}
void bio_set_pages_dirty(struct bio *bio)
{
struct bio_vec *bvec;
int i;
bio_for_each_segment_all(bvec, bio, i) {
struct page *page = bvec->bv_page;
if (page && !PageCompound(page))
set_page_dirty_lock(page);
}
}
static void bio_release_pages(struct bio *bio)
{
struct bio_vec *bvec;
int i;
bio_for_each_segment_all(bvec, bio, i) {
struct page *page = bvec->bv_page;
if (page)
put_page(page);
}
}
static void bio_dirty_fn(struct work_struct *work)
{
unsigned long flags;
struct bio *bio;
spin_lock_irqsave(&bio_dirty_lock, flags);
bio = bio_dirty_list;
bio_dirty_list = NULL;
spin_unlock_irqrestore(&bio_dirty_lock, flags);
while (bio) {
struct bio *next = bio->bi_private;
bio_set_pages_dirty(bio);
bio_release_pages(bio);
bio_put(bio);
bio = next;
}
}
void bio_check_pages_dirty(struct bio *bio)
{
struct bio_vec *bvec;
int nr_clean_pages = 0;
int i;
bio_for_each_segment_all(bvec, bio, i) {
struct page *page = bvec->bv_page;
if (PageDirty(page) || PageCompound(page)) {
page_cache_release(page);
bvec->bv_page = NULL;
} else {
nr_clean_pages++;
}
}
if (nr_clean_pages) {
unsigned long flags;
spin_lock_irqsave(&bio_dirty_lock, flags);
bio->bi_private = bio_dirty_list;
bio_dirty_list = bio;
spin_unlock_irqrestore(&bio_dirty_lock, flags);
schedule_work(&bio_dirty_work);
} else {
bio_put(bio);
}
}
void bio_flush_dcache_pages(struct bio *bi)
{
struct bio_vec bvec;
struct bvec_iter iter;
bio_for_each_segment(bvec, bi, iter)
flush_dcache_page(bvec.bv_page);
}
void bio_endio(struct bio *bio, int error)
{
while (bio) {
BUG_ON(atomic_read(&bio->bi_remaining) <= 0);
if (error)
clear_bit(BIO_UPTODATE, &bio->bi_flags);
else if (!test_bit(BIO_UPTODATE, &bio->bi_flags))
error = -EIO;
if (!atomic_dec_and_test(&bio->bi_remaining))
return;
if (bio->bi_end_io == bio_chain_endio) {
struct bio *parent = bio->bi_private;
bio_put(bio);
bio = parent;
} else {
if (bio->bi_end_io)
bio->bi_end_io(bio, error);
bio = NULL;
}
}
}
void bio_endio_nodec(struct bio *bio, int error)
{
atomic_inc(&bio->bi_remaining);
bio_endio(bio, error);
}
struct bio *bio_split(struct bio *bio, int sectors,
gfp_t gfp, struct bio_set *bs)
{
struct bio *split = NULL;
BUG_ON(sectors <= 0);
BUG_ON(sectors >= bio_sectors(bio));
split = bio_clone_fast(bio, gfp, bs);
if (!split)
return NULL;
split->bi_iter.bi_size = sectors << 9;
if (bio_integrity(split))
bio_integrity_trim(split, 0, sectors);
bio_advance(bio, split->bi_iter.bi_size);
return split;
}
void bio_trim(struct bio *bio, int offset, int size)
{
size <<= 9;
if (offset == 0 && size == bio->bi_iter.bi_size)
return;
clear_bit(BIO_SEG_VALID, &bio->bi_flags);
bio_advance(bio, offset << 9);
bio->bi_iter.bi_size = size;
}
mempool_t *biovec_create_pool(int pool_entries)
{
struct biovec_slab *bp = bvec_slabs + BIOVEC_MAX_IDX;
return mempool_create_slab_pool(pool_entries, bp->slab);
}
void bioset_free(struct bio_set *bs)
{
if (bs->rescue_workqueue)
destroy_workqueue(bs->rescue_workqueue);
if (bs->bio_pool)
mempool_destroy(bs->bio_pool);
if (bs->bvec_pool)
mempool_destroy(bs->bvec_pool);
bioset_integrity_free(bs);
bio_put_slab(bs);
kfree(bs);
}
struct bio_set *bioset_create(unsigned int pool_size, unsigned int front_pad)
{
unsigned int back_pad = BIO_INLINE_VECS * sizeof(struct bio_vec);
struct bio_set *bs;
bs = kzalloc(sizeof(*bs), GFP_KERNEL);
if (!bs)
return NULL;
bs->front_pad = front_pad;
spin_lock_init(&bs->rescue_lock);
bio_list_init(&bs->rescue_list);
INIT_WORK(&bs->rescue_work, bio_alloc_rescue);
bs->bio_slab = bio_find_or_create_slab(front_pad + back_pad);
if (!bs->bio_slab) {
kfree(bs);
return NULL;
}
bs->bio_pool = mempool_create_slab_pool(pool_size, bs->bio_slab);
if (!bs->bio_pool)
goto bad;
bs->bvec_pool = biovec_create_pool(pool_size);
if (!bs->bvec_pool)
goto bad;
bs->rescue_workqueue = alloc_workqueue("bioset", WQ_MEM_RECLAIM, 0);
if (!bs->rescue_workqueue)
goto bad;
return bs;
bad:
bioset_free(bs);
return NULL;
}
int bio_associate_current(struct bio *bio)
{
struct io_context *ioc;
struct cgroup_subsys_state *css;
if (bio->bi_ioc)
return -EBUSY;
ioc = current->io_context;
if (!ioc)
return -ENOENT;
get_io_context_active(ioc);
bio->bi_ioc = ioc;
rcu_read_lock();
css = task_css(current, blkio_cgrp_id);
if (css && css_tryget_online(css))
bio->bi_css = css;
rcu_read_unlock();
return 0;
}
void bio_disassociate_task(struct bio *bio)
{
if (bio->bi_ioc) {
put_io_context(bio->bi_ioc);
bio->bi_ioc = NULL;
}
if (bio->bi_css) {
css_put(bio->bi_css);
bio->bi_css = NULL;
}
}
static void __init biovec_init_slabs(void)
{
int i;
for (i = 0; i < BIOVEC_NR_POOLS; i++) {
int size;
struct biovec_slab *bvs = bvec_slabs + i;
if (bvs->nr_vecs <= BIO_INLINE_VECS) {
bvs->slab = NULL;
continue;
}
size = bvs->nr_vecs * sizeof(struct bio_vec);
bvs->slab = kmem_cache_create(bvs->name, size, 0,
SLAB_HWCACHE_ALIGN|SLAB_PANIC, NULL);
}
}
static int __init init_bio(void)
{
bio_slab_max = 2;
bio_slab_nr = 0;
bio_slabs = kzalloc(bio_slab_max * sizeof(struct bio_slab), GFP_KERNEL);
if (!bio_slabs)
panic("bio: can't allocate bios\n");
bio_integrity_init();
biovec_init_slabs();
fs_bio_set = bioset_create(BIO_POOL_SIZE, 0);
if (!fs_bio_set)
panic("bio: can't allocate bios\n");
if (bioset_integrity_create(fs_bio_set, BIO_POOL_SIZE))
panic("bio: can't create integrity pool\n");
return 0;
}
