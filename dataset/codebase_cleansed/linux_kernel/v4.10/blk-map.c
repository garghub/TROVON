int blk_rq_append_bio(struct request *rq, struct bio *bio)
{
if (!rq->bio) {
rq->cmd_flags &= REQ_OP_MASK;
rq->cmd_flags |= (bio->bi_opf & REQ_OP_MASK);
blk_rq_bio_prep(rq->q, rq, bio);
} else {
if (!ll_back_merge_fn(rq->q, rq, bio))
return -EINVAL;
rq->biotail->bi_next = bio;
rq->biotail = bio;
rq->__data_len += bio->bi_iter.bi_size;
}
return 0;
}
static int __blk_rq_unmap_user(struct bio *bio)
{
int ret = 0;
if (bio) {
if (bio_flagged(bio, BIO_USER_MAPPED))
bio_unmap_user(bio);
else
ret = bio_uncopy_user(bio);
}
return ret;
}
static int __blk_rq_map_user_iov(struct request *rq,
struct rq_map_data *map_data, struct iov_iter *iter,
gfp_t gfp_mask, bool copy)
{
struct request_queue *q = rq->q;
struct bio *bio, *orig_bio;
int ret;
if (copy)
bio = bio_copy_user_iov(q, map_data, iter, gfp_mask);
else
bio = bio_map_user_iov(q, iter, gfp_mask);
if (IS_ERR(bio))
return PTR_ERR(bio);
if (map_data && map_data->null_mapped)
bio_set_flag(bio, BIO_NULL_MAPPED);
iov_iter_advance(iter, bio->bi_iter.bi_size);
if (map_data)
map_data->offset += bio->bi_iter.bi_size;
orig_bio = bio;
blk_queue_bounce(q, &bio);
bio_get(bio);
ret = blk_rq_append_bio(rq, bio);
if (ret) {
bio_endio(bio);
__blk_rq_unmap_user(orig_bio);
bio_put(bio);
return ret;
}
return 0;
}
int blk_rq_map_user_iov(struct request_queue *q, struct request *rq,
struct rq_map_data *map_data,
const struct iov_iter *iter, gfp_t gfp_mask)
{
bool copy = false;
unsigned long align = q->dma_pad_mask | queue_dma_alignment(q);
struct bio *bio = NULL;
struct iov_iter i;
int ret;
if (!iter_is_iovec(iter))
goto fail;
if (map_data)
copy = true;
else if (iov_iter_alignment(iter) & align)
copy = true;
else if (queue_virt_boundary(q))
copy = queue_virt_boundary(q) & iov_iter_gap_alignment(iter);
i = *iter;
do {
ret =__blk_rq_map_user_iov(rq, map_data, &i, gfp_mask, copy);
if (ret)
goto unmap_rq;
if (!bio)
bio = rq->bio;
} while (iov_iter_count(&i));
if (!bio_flagged(bio, BIO_USER_MAPPED))
rq->rq_flags |= RQF_COPY_USER;
return 0;
unmap_rq:
__blk_rq_unmap_user(bio);
fail:
rq->bio = NULL;
return -EINVAL;
}
int blk_rq_map_user(struct request_queue *q, struct request *rq,
struct rq_map_data *map_data, void __user *ubuf,
unsigned long len, gfp_t gfp_mask)
{
struct iovec iov;
struct iov_iter i;
int ret = import_single_range(rq_data_dir(rq), ubuf, len, &iov, &i);
if (unlikely(ret < 0))
return ret;
return blk_rq_map_user_iov(q, rq, map_data, &i, gfp_mask);
}
int blk_rq_unmap_user(struct bio *bio)
{
struct bio *mapped_bio;
int ret = 0, ret2;
while (bio) {
mapped_bio = bio;
if (unlikely(bio_flagged(bio, BIO_BOUNCED)))
mapped_bio = bio->bi_private;
ret2 = __blk_rq_unmap_user(mapped_bio);
if (ret2 && !ret)
ret = ret2;
mapped_bio = bio;
bio = bio->bi_next;
bio_put(mapped_bio);
}
return ret;
}
int blk_rq_map_kern(struct request_queue *q, struct request *rq, void *kbuf,
unsigned int len, gfp_t gfp_mask)
{
int reading = rq_data_dir(rq) == READ;
unsigned long addr = (unsigned long) kbuf;
int do_copy = 0;
struct bio *bio;
int ret;
if (len > (queue_max_hw_sectors(q) << 9))
return -EINVAL;
if (!len || !kbuf)
return -EINVAL;
do_copy = !blk_rq_aligned(q, addr, len) || object_is_on_stack(kbuf);
if (do_copy)
bio = bio_copy_kern(q, kbuf, len, gfp_mask, reading);
else
bio = bio_map_kern(q, kbuf, len, gfp_mask);
if (IS_ERR(bio))
return PTR_ERR(bio);
if (!reading)
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
if (do_copy)
rq->rq_flags |= RQF_COPY_USER;
ret = blk_rq_append_bio(rq, bio);
if (unlikely(ret)) {
bio_put(bio);
return ret;
}
blk_queue_bounce(q, &rq->bio);
return 0;
}
