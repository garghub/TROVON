static __init int init_emergency_pool(void)
{
#if defined(CONFIG_HIGHMEM) && !defined(CONFIG_MEMORY_HOTPLUG)
if (max_pfn <= max_low_pfn)
return 0;
#endif
page_pool = mempool_create_page_pool(POOL_SIZE, 0);
BUG_ON(!page_pool);
pr_info("pool size: %d pages\n", POOL_SIZE);
return 0;
}
static void bounce_copy_vec(struct bio_vec *to, unsigned char *vfrom)
{
unsigned long flags;
unsigned char *vto;
local_irq_save(flags);
vto = kmap_atomic(to->bv_page);
memcpy(vto + to->bv_offset, vfrom, to->bv_len);
kunmap_atomic(vto);
local_irq_restore(flags);
}
static void *mempool_alloc_pages_isa(gfp_t gfp_mask, void *data)
{
return mempool_alloc_pages(gfp_mask | GFP_DMA, data);
}
int init_emergency_isa_pool(void)
{
if (isa_page_pool)
return 0;
isa_page_pool = mempool_create(ISA_POOL_SIZE, mempool_alloc_pages_isa,
mempool_free_pages, (void *) 0);
BUG_ON(!isa_page_pool);
pr_info("isa pool size: %d pages\n", ISA_POOL_SIZE);
return 0;
}
static void copy_to_high_bio_irq(struct bio *to, struct bio *from)
{
unsigned char *vfrom;
struct bio_vec tovec, *fromvec = from->bi_io_vec;
struct bvec_iter iter;
bio_for_each_segment(tovec, to, iter) {
if (tovec.bv_page != fromvec->bv_page) {
vfrom = page_address(fromvec->bv_page) +
tovec.bv_offset;
bounce_copy_vec(&tovec, vfrom);
flush_dcache_page(tovec.bv_page);
}
fromvec++;
}
}
static void bounce_end_io(struct bio *bio, mempool_t *pool)
{
struct bio *bio_orig = bio->bi_private;
struct bio_vec *bvec, *org_vec;
int i;
int start = bio_orig->bi_iter.bi_idx;
bio_for_each_segment_all(bvec, bio, i) {
org_vec = bio_orig->bi_io_vec + i + start;
if (bvec->bv_page == org_vec->bv_page)
continue;
dec_zone_page_state(bvec->bv_page, NR_BOUNCE);
mempool_free(bvec->bv_page, pool);
}
bio_orig->bi_error = bio->bi_error;
bio_endio(bio_orig);
bio_put(bio);
}
static void bounce_end_io_write(struct bio *bio)
{
bounce_end_io(bio, page_pool);
}
static void bounce_end_io_write_isa(struct bio *bio)
{
bounce_end_io(bio, isa_page_pool);
}
static void __bounce_end_io_read(struct bio *bio, mempool_t *pool)
{
struct bio *bio_orig = bio->bi_private;
if (!bio->bi_error)
copy_to_high_bio_irq(bio_orig, bio);
bounce_end_io(bio, pool);
}
static void bounce_end_io_read(struct bio *bio)
{
__bounce_end_io_read(bio, page_pool);
}
static void bounce_end_io_read_isa(struct bio *bio)
{
__bounce_end_io_read(bio, isa_page_pool);
}
static void __blk_queue_bounce(struct request_queue *q, struct bio **bio_orig,
mempool_t *pool)
{
struct bio *bio;
int rw = bio_data_dir(*bio_orig);
struct bio_vec *to, from;
struct bvec_iter iter;
unsigned i;
bio_for_each_segment(from, *bio_orig, iter)
if (page_to_pfn(from.bv_page) > queue_bounce_pfn(q))
goto bounce;
return;
bounce:
bio = bio_clone_bioset(*bio_orig, GFP_NOIO, fs_bio_set);
bio_for_each_segment_all(to, bio, i) {
struct page *page = to->bv_page;
if (page_to_pfn(page) <= queue_bounce_pfn(q))
continue;
to->bv_page = mempool_alloc(pool, q->bounce_gfp);
inc_zone_page_state(to->bv_page, NR_BOUNCE);
if (rw == WRITE) {
char *vto, *vfrom;
flush_dcache_page(page);
vto = page_address(to->bv_page) + to->bv_offset;
vfrom = kmap_atomic(page) + to->bv_offset;
memcpy(vto, vfrom, to->bv_len);
kunmap_atomic(vfrom);
}
}
trace_block_bio_bounce(q, *bio_orig);
bio->bi_flags |= (1 << BIO_BOUNCED);
if (pool == page_pool) {
bio->bi_end_io = bounce_end_io_write;
if (rw == READ)
bio->bi_end_io = bounce_end_io_read;
} else {
bio->bi_end_io = bounce_end_io_write_isa;
if (rw == READ)
bio->bi_end_io = bounce_end_io_read_isa;
}
bio->bi_private = *bio_orig;
*bio_orig = bio;
}
void blk_queue_bounce(struct request_queue *q, struct bio **bio_orig)
{
mempool_t *pool;
if (!bio_has_data(*bio_orig))
return;
if (!(q->bounce_gfp & GFP_DMA)) {
if (queue_bounce_pfn(q) >= blk_max_pfn)
return;
pool = page_pool;
} else {
BUG_ON(!isa_page_pool);
pool = isa_page_pool;
}
__blk_queue_bounce(q, bio_orig, pool);
}
