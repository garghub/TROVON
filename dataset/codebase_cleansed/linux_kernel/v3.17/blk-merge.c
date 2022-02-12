static unsigned int __blk_recalc_rq_segments(struct request_queue *q,
struct bio *bio,
bool no_sg_merge)
{
struct bio_vec bv, bvprv = { NULL };
int cluster, high, highprv = 1;
unsigned int seg_size, nr_phys_segs;
struct bio *fbio, *bbio;
struct bvec_iter iter;
if (!bio)
return 0;
if (bio->bi_rw & REQ_DISCARD)
return 1;
if (bio->bi_rw & REQ_WRITE_SAME)
return 1;
fbio = bio;
cluster = blk_queue_cluster(q);
seg_size = 0;
nr_phys_segs = 0;
high = 0;
for_each_bio(bio) {
bio_for_each_segment(bv, bio, iter) {
if (no_sg_merge)
goto new_segment;
high = page_to_pfn(bv.bv_page) > queue_bounce_pfn(q);
if (!high && !highprv && cluster) {
if (seg_size + bv.bv_len
> queue_max_segment_size(q))
goto new_segment;
if (!BIOVEC_PHYS_MERGEABLE(&bvprv, &bv))
goto new_segment;
if (!BIOVEC_SEG_BOUNDARY(q, &bvprv, &bv))
goto new_segment;
seg_size += bv.bv_len;
bvprv = bv;
continue;
}
new_segment:
if (nr_phys_segs == 1 && seg_size >
fbio->bi_seg_front_size)
fbio->bi_seg_front_size = seg_size;
nr_phys_segs++;
bvprv = bv;
seg_size = bv.bv_len;
highprv = high;
}
bbio = bio;
}
if (nr_phys_segs == 1 && seg_size > fbio->bi_seg_front_size)
fbio->bi_seg_front_size = seg_size;
if (seg_size > bbio->bi_seg_back_size)
bbio->bi_seg_back_size = seg_size;
return nr_phys_segs;
}
void blk_recalc_rq_segments(struct request *rq)
{
bool no_sg_merge = !!test_bit(QUEUE_FLAG_NO_SG_MERGE,
&rq->q->queue_flags);
rq->nr_phys_segments = __blk_recalc_rq_segments(rq->q, rq->bio,
no_sg_merge);
}
void blk_recount_segments(struct request_queue *q, struct bio *bio)
{
if (test_bit(QUEUE_FLAG_NO_SG_MERGE, &q->queue_flags) &&
bio->bi_vcnt < queue_max_segments(q))
bio->bi_phys_segments = bio->bi_vcnt;
else {
struct bio *nxt = bio->bi_next;
bio->bi_next = NULL;
bio->bi_phys_segments = __blk_recalc_rq_segments(q, bio, false);
bio->bi_next = nxt;
}
bio->bi_flags |= (1 << BIO_SEG_VALID);
}
static int blk_phys_contig_segment(struct request_queue *q, struct bio *bio,
struct bio *nxt)
{
struct bio_vec end_bv = { NULL }, nxt_bv;
struct bvec_iter iter;
if (!blk_queue_cluster(q))
return 0;
if (bio->bi_seg_back_size + nxt->bi_seg_front_size >
queue_max_segment_size(q))
return 0;
if (!bio_has_data(bio))
return 1;
bio_for_each_segment(end_bv, bio, iter)
if (end_bv.bv_len == iter.bi_size)
break;
nxt_bv = bio_iovec(nxt);
if (!BIOVEC_PHYS_MERGEABLE(&end_bv, &nxt_bv))
return 0;
if (BIOVEC_SEG_BOUNDARY(q, &end_bv, &nxt_bv))
return 1;
return 0;
}
static inline void
__blk_segment_map_sg(struct request_queue *q, struct bio_vec *bvec,
struct scatterlist *sglist, struct bio_vec *bvprv,
struct scatterlist **sg, int *nsegs, int *cluster)
{
int nbytes = bvec->bv_len;
if (*sg && *cluster) {
if ((*sg)->length + nbytes > queue_max_segment_size(q))
goto new_segment;
if (!BIOVEC_PHYS_MERGEABLE(bvprv, bvec))
goto new_segment;
if (!BIOVEC_SEG_BOUNDARY(q, bvprv, bvec))
goto new_segment;
(*sg)->length += nbytes;
} else {
new_segment:
if (!*sg)
*sg = sglist;
else {
sg_unmark_end(*sg);
*sg = sg_next(*sg);
}
sg_set_page(*sg, bvec->bv_page, nbytes, bvec->bv_offset);
(*nsegs)++;
}
*bvprv = *bvec;
}
static int __blk_bios_map_sg(struct request_queue *q, struct bio *bio,
struct scatterlist *sglist,
struct scatterlist **sg)
{
struct bio_vec bvec, bvprv = { NULL };
struct bvec_iter iter;
int nsegs, cluster;
nsegs = 0;
cluster = blk_queue_cluster(q);
if (bio->bi_rw & REQ_DISCARD) {
if (bio->bi_vcnt)
goto single_segment;
return 0;
}
if (bio->bi_rw & REQ_WRITE_SAME) {
single_segment:
*sg = sglist;
bvec = bio_iovec(bio);
sg_set_page(*sg, bvec.bv_page, bvec.bv_len, bvec.bv_offset);
return 1;
}
for_each_bio(bio)
bio_for_each_segment(bvec, bio, iter)
__blk_segment_map_sg(q, &bvec, sglist, &bvprv, sg,
&nsegs, &cluster);
return nsegs;
}
int blk_rq_map_sg(struct request_queue *q, struct request *rq,
struct scatterlist *sglist)
{
struct scatterlist *sg = NULL;
int nsegs = 0;
if (rq->bio)
nsegs = __blk_bios_map_sg(q, rq->bio, sglist, &sg);
if (unlikely(rq->cmd_flags & REQ_COPY_USER) &&
(blk_rq_bytes(rq) & q->dma_pad_mask)) {
unsigned int pad_len =
(q->dma_pad_mask & ~blk_rq_bytes(rq)) + 1;
sg->length += pad_len;
rq->extra_len += pad_len;
}
if (q->dma_drain_size && q->dma_drain_needed(rq)) {
if (rq->cmd_flags & REQ_WRITE)
memset(q->dma_drain_buffer, 0, q->dma_drain_size);
sg->page_link &= ~0x02;
sg = sg_next(sg);
sg_set_page(sg, virt_to_page(q->dma_drain_buffer),
q->dma_drain_size,
((unsigned long)q->dma_drain_buffer) &
(PAGE_SIZE - 1));
nsegs++;
rq->extra_len += q->dma_drain_size;
}
if (sg)
sg_mark_end(sg);
return nsegs;
}
int blk_bio_map_sg(struct request_queue *q, struct bio *bio,
struct scatterlist *sglist)
{
struct scatterlist *sg = NULL;
int nsegs;
struct bio *next = bio->bi_next;
bio->bi_next = NULL;
nsegs = __blk_bios_map_sg(q, bio, sglist, &sg);
bio->bi_next = next;
if (sg)
sg_mark_end(sg);
BUG_ON(bio->bi_phys_segments && nsegs > bio->bi_phys_segments);
return nsegs;
}
static inline int ll_new_hw_segment(struct request_queue *q,
struct request *req,
struct bio *bio)
{
int nr_phys_segs = bio_phys_segments(q, bio);
if (req->nr_phys_segments + nr_phys_segs > queue_max_segments(q))
goto no_merge;
if (bio_integrity(bio) && blk_integrity_merge_bio(q, req, bio))
goto no_merge;
req->nr_phys_segments += nr_phys_segs;
return 1;
no_merge:
req->cmd_flags |= REQ_NOMERGE;
if (req == q->last_merge)
q->last_merge = NULL;
return 0;
}
int ll_back_merge_fn(struct request_queue *q, struct request *req,
struct bio *bio)
{
if (blk_rq_sectors(req) + bio_sectors(bio) >
blk_rq_get_max_sectors(req)) {
req->cmd_flags |= REQ_NOMERGE;
if (req == q->last_merge)
q->last_merge = NULL;
return 0;
}
if (!bio_flagged(req->biotail, BIO_SEG_VALID))
blk_recount_segments(q, req->biotail);
if (!bio_flagged(bio, BIO_SEG_VALID))
blk_recount_segments(q, bio);
return ll_new_hw_segment(q, req, bio);
}
int ll_front_merge_fn(struct request_queue *q, struct request *req,
struct bio *bio)
{
if (blk_rq_sectors(req) + bio_sectors(bio) >
blk_rq_get_max_sectors(req)) {
req->cmd_flags |= REQ_NOMERGE;
if (req == q->last_merge)
q->last_merge = NULL;
return 0;
}
if (!bio_flagged(bio, BIO_SEG_VALID))
blk_recount_segments(q, bio);
if (!bio_flagged(req->bio, BIO_SEG_VALID))
blk_recount_segments(q, req->bio);
return ll_new_hw_segment(q, req, bio);
}
static bool req_no_special_merge(struct request *req)
{
struct request_queue *q = req->q;
return !q->mq_ops && req->special;
}
static int ll_merge_requests_fn(struct request_queue *q, struct request *req,
struct request *next)
{
int total_phys_segments;
unsigned int seg_size =
req->biotail->bi_seg_back_size + next->bio->bi_seg_front_size;
if (req_no_special_merge(req) || req_no_special_merge(next))
return 0;
if ((blk_rq_sectors(req) + blk_rq_sectors(next)) >
blk_rq_get_max_sectors(req))
return 0;
total_phys_segments = req->nr_phys_segments + next->nr_phys_segments;
if (blk_phys_contig_segment(q, req->biotail, next->bio)) {
if (req->nr_phys_segments == 1)
req->bio->bi_seg_front_size = seg_size;
if (next->nr_phys_segments == 1)
next->biotail->bi_seg_back_size = seg_size;
total_phys_segments--;
}
if (total_phys_segments > queue_max_segments(q))
return 0;
if (blk_integrity_rq(req) && blk_integrity_merge_rq(q, req, next))
return 0;
req->nr_phys_segments = total_phys_segments;
return 1;
}
void blk_rq_set_mixed_merge(struct request *rq)
{
unsigned int ff = rq->cmd_flags & REQ_FAILFAST_MASK;
struct bio *bio;
if (rq->cmd_flags & REQ_MIXED_MERGE)
return;
for (bio = rq->bio; bio; bio = bio->bi_next) {
WARN_ON_ONCE((bio->bi_rw & REQ_FAILFAST_MASK) &&
(bio->bi_rw & REQ_FAILFAST_MASK) != ff);
bio->bi_rw |= ff;
}
rq->cmd_flags |= REQ_MIXED_MERGE;
}
static void blk_account_io_merge(struct request *req)
{
if (blk_do_io_stat(req)) {
struct hd_struct *part;
int cpu;
cpu = part_stat_lock();
part = req->part;
part_round_stats(cpu, part);
part_dec_in_flight(part, rq_data_dir(req));
hd_struct_put(part);
part_stat_unlock();
}
}
static int attempt_merge(struct request_queue *q, struct request *req,
struct request *next)
{
if (!rq_mergeable(req) || !rq_mergeable(next))
return 0;
if (!blk_check_merge_flags(req->cmd_flags, next->cmd_flags))
return 0;
if (blk_rq_pos(req) + blk_rq_sectors(req) != blk_rq_pos(next))
return 0;
if (rq_data_dir(req) != rq_data_dir(next)
|| req->rq_disk != next->rq_disk
|| req_no_special_merge(next))
return 0;
if (req->cmd_flags & REQ_WRITE_SAME &&
!blk_write_same_mergeable(req->bio, next->bio))
return 0;
if (!ll_merge_requests_fn(q, req, next))
return 0;
if ((req->cmd_flags | next->cmd_flags) & REQ_MIXED_MERGE ||
(req->cmd_flags & REQ_FAILFAST_MASK) !=
(next->cmd_flags & REQ_FAILFAST_MASK)) {
blk_rq_set_mixed_merge(req);
blk_rq_set_mixed_merge(next);
}
if (time_after(req->start_time, next->start_time))
req->start_time = next->start_time;
req->biotail->bi_next = next->bio;
req->biotail = next->biotail;
req->__data_len += blk_rq_bytes(next);
elv_merge_requests(q, req, next);
blk_account_io_merge(next);
req->ioprio = ioprio_best(req->ioprio, next->ioprio);
if (blk_rq_cpu_valid(next))
req->cpu = next->cpu;
next->bio = NULL;
__blk_put_request(q, next);
return 1;
}
int attempt_back_merge(struct request_queue *q, struct request *rq)
{
struct request *next = elv_latter_request(q, rq);
if (next)
return attempt_merge(q, rq, next);
return 0;
}
int attempt_front_merge(struct request_queue *q, struct request *rq)
{
struct request *prev = elv_former_request(q, rq);
if (prev)
return attempt_merge(q, prev, rq);
return 0;
}
int blk_attempt_req_merge(struct request_queue *q, struct request *rq,
struct request *next)
{
return attempt_merge(q, rq, next);
}
bool blk_rq_merge_ok(struct request *rq, struct bio *bio)
{
struct request_queue *q = rq->q;
if (!rq_mergeable(rq) || !bio_mergeable(bio))
return false;
if (!blk_check_merge_flags(rq->cmd_flags, bio->bi_rw))
return false;
if (bio_data_dir(bio) != rq_data_dir(rq))
return false;
if (rq->rq_disk != bio->bi_bdev->bd_disk || req_no_special_merge(rq))
return false;
if (bio_integrity(bio) != blk_integrity_rq(rq))
return false;
if (rq->cmd_flags & REQ_WRITE_SAME &&
!blk_write_same_mergeable(rq->bio, bio))
return false;
if (q->queue_flags & (1 << QUEUE_FLAG_SG_GAPS)) {
struct bio_vec *bprev;
bprev = &rq->biotail->bi_io_vec[bio->bi_vcnt - 1];
if (bvec_gap_to_prev(bprev, bio->bi_io_vec[0].bv_offset))
return false;
}
return true;
}
int blk_try_merge(struct request *rq, struct bio *bio)
{
if (blk_rq_pos(rq) + blk_rq_sectors(rq) == bio->bi_iter.bi_sector)
return ELEVATOR_BACK_MERGE;
else if (blk_rq_pos(rq) - bio_sectors(bio) == bio->bi_iter.bi_sector)
return ELEVATOR_FRONT_MERGE;
return ELEVATOR_NO_MERGE;
}
