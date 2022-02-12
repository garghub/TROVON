bool dm_use_blk_mq_default(void)
{
return use_blk_mq;
}
bool dm_use_blk_mq(struct mapped_device *md)
{
return md->use_blk_mq;
}
unsigned dm_get_reserved_rq_based_ios(void)
{
return __dm_get_module_param(&reserved_rq_based_ios,
RESERVED_REQUEST_BASED_IOS, DM_RESERVED_MAX_IOS);
}
static unsigned dm_get_blk_mq_nr_hw_queues(void)
{
return __dm_get_module_param(&dm_mq_nr_hw_queues, 1, 32);
}
static unsigned dm_get_blk_mq_queue_depth(void)
{
return __dm_get_module_param(&dm_mq_queue_depth,
DM_MQ_QUEUE_DEPTH, BLK_MQ_MAX_DEPTH);
}
int dm_request_based(struct mapped_device *md)
{
return blk_queue_stackable(md->queue);
}
static void dm_old_start_queue(struct request_queue *q)
{
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
if (blk_queue_stopped(q))
blk_start_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
void dm_start_queue(struct request_queue *q)
{
if (!q->mq_ops)
dm_old_start_queue(q);
else {
queue_flag_clear_unlocked(QUEUE_FLAG_STOPPED, q);
blk_mq_start_stopped_hw_queues(q, true);
blk_mq_kick_requeue_list(q);
}
}
static void dm_old_stop_queue(struct request_queue *q)
{
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
if (blk_queue_stopped(q)) {
spin_unlock_irqrestore(q->queue_lock, flags);
return;
}
blk_stop_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
void dm_stop_queue(struct request_queue *q)
{
if (!q->mq_ops)
dm_old_stop_queue(q);
else {
spin_lock_irq(q->queue_lock);
queue_flag_set(QUEUE_FLAG_STOPPED, q);
spin_unlock_irq(q->queue_lock);
blk_mq_cancel_requeue_work(q);
blk_mq_stop_hw_queues(q);
}
}
static struct dm_rq_target_io *alloc_old_rq_tio(struct mapped_device *md,
gfp_t gfp_mask)
{
return mempool_alloc(md->io_pool, gfp_mask);
}
static void free_old_rq_tio(struct dm_rq_target_io *tio)
{
mempool_free(tio, tio->md->io_pool);
}
static struct request *alloc_old_clone_request(struct mapped_device *md,
gfp_t gfp_mask)
{
return mempool_alloc(md->rq_pool, gfp_mask);
}
static void free_old_clone_request(struct mapped_device *md, struct request *rq)
{
mempool_free(rq, md->rq_pool);
}
static void end_clone_bio(struct bio *clone)
{
struct dm_rq_clone_bio_info *info =
container_of(clone, struct dm_rq_clone_bio_info, clone);
struct dm_rq_target_io *tio = info->tio;
struct bio *bio = info->orig;
unsigned int nr_bytes = info->orig->bi_iter.bi_size;
int error = clone->bi_error;
bio_put(clone);
if (tio->error)
return;
else if (error) {
tio->error = error;
return;
}
if (tio->orig->bio != bio)
DMERR("bio completion is going in the middle of the request");
blk_update_request(tio->orig, 0, nr_bytes);
}
static struct dm_rq_target_io *tio_from_request(struct request *rq)
{
return (rq->q->mq_ops ? blk_mq_rq_to_pdu(rq) : rq->special);
}
static void rq_end_stats(struct mapped_device *md, struct request *orig)
{
if (unlikely(dm_stats_used(&md->stats))) {
struct dm_rq_target_io *tio = tio_from_request(orig);
tio->duration_jiffies = jiffies - tio->duration_jiffies;
dm_stats_account_io(&md->stats, rq_data_dir(orig),
blk_rq_pos(orig), tio->n_sectors, true,
tio->duration_jiffies, &tio->stats_aux);
}
}
static void rq_completed(struct mapped_device *md, int rw, bool run_queue)
{
atomic_dec(&md->pending[rw]);
if (!md_in_flight(md))
wake_up(&md->wait);
if (!md->queue->mq_ops && run_queue)
blk_run_queue_async(md->queue);
dm_put(md);
}
static void free_rq_clone(struct request *clone)
{
struct dm_rq_target_io *tio = clone->end_io_data;
struct mapped_device *md = tio->md;
blk_rq_unprep_clone(clone);
if (clone->q && clone->q->mq_ops)
tio->ti->type->release_clone_rq(clone);
else if (!md->queue->mq_ops)
free_old_clone_request(md, clone);
if (!md->queue->mq_ops)
free_old_rq_tio(tio);
}
static void dm_end_request(struct request *clone, int error)
{
int rw = rq_data_dir(clone);
struct dm_rq_target_io *tio = clone->end_io_data;
struct mapped_device *md = tio->md;
struct request *rq = tio->orig;
if (rq->cmd_type == REQ_TYPE_BLOCK_PC) {
rq->errors = clone->errors;
rq->resid_len = clone->resid_len;
if (rq->sense)
rq->sense_len = clone->sense_len;
}
free_rq_clone(clone);
rq_end_stats(md, rq);
if (!rq->q->mq_ops)
blk_end_request_all(rq, error);
else
blk_mq_end_request(rq, error);
rq_completed(md, rw, true);
}
static void dm_unprep_request(struct request *rq)
{
struct dm_rq_target_io *tio = tio_from_request(rq);
struct request *clone = tio->clone;
if (!rq->q->mq_ops) {
rq->special = NULL;
rq->cmd_flags &= ~REQ_DONTPREP;
}
if (clone)
free_rq_clone(clone);
else if (!tio->md->queue->mq_ops)
free_old_rq_tio(tio);
}
static void dm_old_requeue_request(struct request *rq)
{
struct request_queue *q = rq->q;
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
blk_requeue_request(q, rq);
blk_run_queue_async(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
static void dm_mq_requeue_request(struct request *rq)
{
struct request_queue *q = rq->q;
unsigned long flags;
blk_mq_requeue_request(rq);
spin_lock_irqsave(q->queue_lock, flags);
if (!blk_queue_stopped(q))
blk_mq_kick_requeue_list(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
static void dm_requeue_original_request(struct mapped_device *md,
struct request *rq)
{
int rw = rq_data_dir(rq);
rq_end_stats(md, rq);
dm_unprep_request(rq);
if (!rq->q->mq_ops)
dm_old_requeue_request(rq);
else
dm_mq_requeue_request(rq);
rq_completed(md, rw, false);
}
static void dm_done(struct request *clone, int error, bool mapped)
{
int r = error;
struct dm_rq_target_io *tio = clone->end_io_data;
dm_request_endio_fn rq_end_io = NULL;
if (tio->ti) {
rq_end_io = tio->ti->type->rq_end_io;
if (mapped && rq_end_io)
r = rq_end_io(tio->ti, clone, error, &tio->info);
}
if (unlikely(r == -EREMOTEIO && (req_op(clone) == REQ_OP_WRITE_SAME) &&
!clone->q->limits.max_write_same_sectors))
disable_write_same(tio->md);
if (r <= 0)
dm_end_request(clone, r);
else if (r == DM_ENDIO_INCOMPLETE)
return;
else if (r == DM_ENDIO_REQUEUE)
dm_requeue_original_request(tio->md, tio->orig);
else {
DMWARN("unimplemented target endio return value: %d", r);
BUG();
}
}
static void dm_softirq_done(struct request *rq)
{
bool mapped = true;
struct dm_rq_target_io *tio = tio_from_request(rq);
struct request *clone = tio->clone;
int rw;
if (!clone) {
rq_end_stats(tio->md, rq);
rw = rq_data_dir(rq);
if (!rq->q->mq_ops) {
blk_end_request_all(rq, tio->error);
rq_completed(tio->md, rw, false);
free_old_rq_tio(tio);
} else {
blk_mq_end_request(rq, tio->error);
rq_completed(tio->md, rw, false);
}
return;
}
if (rq->cmd_flags & REQ_FAILED)
mapped = false;
dm_done(clone, tio->error, mapped);
}
static void dm_complete_request(struct request *rq, int error)
{
struct dm_rq_target_io *tio = tio_from_request(rq);
tio->error = error;
if (!rq->q->mq_ops)
blk_complete_request(rq);
else
blk_mq_complete_request(rq, error);
}
static void dm_kill_unmapped_request(struct request *rq, int error)
{
rq->cmd_flags |= REQ_FAILED;
dm_complete_request(rq, error);
}
static void end_clone_request(struct request *clone, int error)
{
struct dm_rq_target_io *tio = clone->end_io_data;
if (!clone->q->mq_ops) {
__blk_put_request(clone->q, clone);
}
dm_complete_request(tio->orig, error);
}
static void dm_dispatch_clone_request(struct request *clone, struct request *rq)
{
int r;
if (blk_queue_io_stat(clone->q))
clone->cmd_flags |= REQ_IO_STAT;
clone->start_time = jiffies;
r = blk_insert_cloned_request(clone->q, clone);
if (r)
dm_complete_request(rq, r);
}
static int dm_rq_bio_constructor(struct bio *bio, struct bio *bio_orig,
void *data)
{
struct dm_rq_target_io *tio = data;
struct dm_rq_clone_bio_info *info =
container_of(bio, struct dm_rq_clone_bio_info, clone);
info->orig = bio_orig;
info->tio = tio;
bio->bi_end_io = end_clone_bio;
return 0;
}
static int setup_clone(struct request *clone, struct request *rq,
struct dm_rq_target_io *tio, gfp_t gfp_mask)
{
int r;
r = blk_rq_prep_clone(clone, rq, tio->md->bs, gfp_mask,
dm_rq_bio_constructor, tio);
if (r)
return r;
clone->cmd = rq->cmd;
clone->cmd_len = rq->cmd_len;
clone->sense = rq->sense;
clone->end_io = end_clone_request;
clone->end_io_data = tio;
tio->clone = clone;
return 0;
}
static struct request *clone_old_rq(struct request *rq, struct mapped_device *md,
struct dm_rq_target_io *tio, gfp_t gfp_mask)
{
struct request *clone;
clone = alloc_old_clone_request(md, gfp_mask);
if (!clone)
return NULL;
blk_rq_init(NULL, clone);
if (setup_clone(clone, rq, tio, gfp_mask)) {
free_old_clone_request(md, clone);
return NULL;
}
return clone;
}
static void init_tio(struct dm_rq_target_io *tio, struct request *rq,
struct mapped_device *md)
{
tio->md = md;
tio->ti = NULL;
tio->clone = NULL;
tio->orig = rq;
tio->error = 0;
if (!md->init_tio_pdu)
memset(&tio->info, 0, sizeof(tio->info));
if (md->kworker_task)
init_kthread_work(&tio->work, map_tio_request);
}
static struct dm_rq_target_io *dm_old_prep_tio(struct request *rq,
struct mapped_device *md,
gfp_t gfp_mask)
{
struct dm_rq_target_io *tio;
int srcu_idx;
struct dm_table *table;
tio = alloc_old_rq_tio(md, gfp_mask);
if (!tio)
return NULL;
init_tio(tio, rq, md);
table = dm_get_live_table(md, &srcu_idx);
if (!dm_table_all_blk_mq_devices(table)) {
if (!clone_old_rq(rq, md, tio, gfp_mask)) {
dm_put_live_table(md, srcu_idx);
free_old_rq_tio(tio);
return NULL;
}
}
dm_put_live_table(md, srcu_idx);
return tio;
}
static int dm_old_prep_fn(struct request_queue *q, struct request *rq)
{
struct mapped_device *md = q->queuedata;
struct dm_rq_target_io *tio;
if (unlikely(rq->special)) {
DMWARN("Already has something in rq->special.");
return BLKPREP_KILL;
}
tio = dm_old_prep_tio(rq, md, GFP_ATOMIC);
if (!tio)
return BLKPREP_DEFER;
rq->special = tio;
rq->cmd_flags |= REQ_DONTPREP;
return BLKPREP_OK;
}
static int map_request(struct dm_rq_target_io *tio, struct request *rq,
struct mapped_device *md)
{
int r;
struct dm_target *ti = tio->ti;
struct request *clone = NULL;
if (tio->clone) {
clone = tio->clone;
r = ti->type->map_rq(ti, clone, &tio->info);
} else {
r = ti->type->clone_and_map_rq(ti, rq, &tio->info, &clone);
if (r < 0) {
dm_kill_unmapped_request(rq, r);
return r;
}
if (r != DM_MAPIO_REMAPPED)
return r;
if (setup_clone(clone, rq, tio, GFP_ATOMIC)) {
ti->type->release_clone_rq(clone);
return DM_MAPIO_REQUEUE;
}
}
switch (r) {
case DM_MAPIO_SUBMITTED:
break;
case DM_MAPIO_REMAPPED:
trace_block_rq_remap(clone->q, clone, disk_devt(dm_disk(md)),
blk_rq_pos(rq));
dm_dispatch_clone_request(clone, rq);
break;
case DM_MAPIO_REQUEUE:
dm_requeue_original_request(md, tio->orig);
break;
default:
if (r > 0) {
DMWARN("unimplemented target map return value: %d", r);
BUG();
}
dm_kill_unmapped_request(rq, r);
return r;
}
return 0;
}
static void dm_start_request(struct mapped_device *md, struct request *orig)
{
if (!orig->q->mq_ops)
blk_start_request(orig);
else
blk_mq_start_request(orig);
atomic_inc(&md->pending[rq_data_dir(orig)]);
if (md->seq_rq_merge_deadline_usecs) {
md->last_rq_pos = rq_end_sector(orig);
md->last_rq_rw = rq_data_dir(orig);
md->last_rq_start_time = ktime_get();
}
if (unlikely(dm_stats_used(&md->stats))) {
struct dm_rq_target_io *tio = tio_from_request(orig);
tio->duration_jiffies = jiffies;
tio->n_sectors = blk_rq_sectors(orig);
dm_stats_account_io(&md->stats, rq_data_dir(orig),
blk_rq_pos(orig), tio->n_sectors, false, 0,
&tio->stats_aux);
}
dm_get(md);
}
static void map_tio_request(struct kthread_work *work)
{
struct dm_rq_target_io *tio = container_of(work, struct dm_rq_target_io, work);
struct request *rq = tio->orig;
struct mapped_device *md = tio->md;
if (map_request(tio, rq, md) == DM_MAPIO_REQUEUE)
dm_requeue_original_request(md, rq);
}
ssize_t dm_attr_rq_based_seq_io_merge_deadline_show(struct mapped_device *md, char *buf)
{
return sprintf(buf, "%u\n", md->seq_rq_merge_deadline_usecs);
}
ssize_t dm_attr_rq_based_seq_io_merge_deadline_store(struct mapped_device *md,
const char *buf, size_t count)
{
unsigned deadline;
if (dm_get_md_type(md) != DM_TYPE_REQUEST_BASED)
return count;
if (kstrtouint(buf, 10, &deadline))
return -EINVAL;
if (deadline > MAX_SEQ_RQ_MERGE_DEADLINE_USECS)
deadline = MAX_SEQ_RQ_MERGE_DEADLINE_USECS;
md->seq_rq_merge_deadline_usecs = deadline;
return count;
}
static bool dm_old_request_peeked_before_merge_deadline(struct mapped_device *md)
{
ktime_t kt_deadline;
if (!md->seq_rq_merge_deadline_usecs)
return false;
kt_deadline = ns_to_ktime((u64)md->seq_rq_merge_deadline_usecs * NSEC_PER_USEC);
kt_deadline = ktime_add_safe(md->last_rq_start_time, kt_deadline);
return !ktime_after(ktime_get(), kt_deadline);
}
static void dm_old_request_fn(struct request_queue *q)
{
struct mapped_device *md = q->queuedata;
struct dm_target *ti = md->immutable_target;
struct request *rq;
struct dm_rq_target_io *tio;
sector_t pos = 0;
if (unlikely(!ti)) {
int srcu_idx;
struct dm_table *map = dm_get_live_table(md, &srcu_idx);
ti = dm_table_find_target(map, pos);
dm_put_live_table(md, srcu_idx);
}
while (!blk_queue_stopped(q)) {
rq = blk_peek_request(q);
if (!rq)
return;
pos = 0;
if (req_op(rq) != REQ_OP_FLUSH)
pos = blk_rq_pos(rq);
if ((dm_old_request_peeked_before_merge_deadline(md) &&
md_in_flight(md) && rq->bio && rq->bio->bi_vcnt == 1 &&
md->last_rq_pos == pos && md->last_rq_rw == rq_data_dir(rq)) ||
(ti->type->busy && ti->type->busy(ti))) {
blk_delay_queue(q, 10);
return;
}
dm_start_request(md, rq);
tio = tio_from_request(rq);
tio->ti = ti;
queue_kthread_work(&md->kworker, &tio->work);
BUG_ON(!irqs_disabled());
}
}
int dm_old_init_request_queue(struct mapped_device *md)
{
if (!blk_init_allocated_queue(md->queue, dm_old_request_fn, NULL))
return -EINVAL;
md->seq_rq_merge_deadline_usecs = 0;
dm_init_normal_md_queue(md);
blk_queue_softirq_done(md->queue, dm_softirq_done);
blk_queue_prep_rq(md->queue, dm_old_prep_fn);
init_kthread_worker(&md->kworker);
md->kworker_task = kthread_run(kthread_worker_fn, &md->kworker,
"kdmwork-%s", dm_device_name(md));
if (IS_ERR(md->kworker_task))
return PTR_ERR(md->kworker_task);
elv_register_queue(md->queue);
return 0;
}
static int dm_mq_init_request(void *data, struct request *rq,
unsigned int hctx_idx, unsigned int request_idx,
unsigned int numa_node)
{
struct mapped_device *md = data;
struct dm_rq_target_io *tio = blk_mq_rq_to_pdu(rq);
tio->md = md;
if (md->init_tio_pdu) {
tio->info.ptr = tio + 1;
}
return 0;
}
static int dm_mq_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *bd)
{
struct request *rq = bd->rq;
struct dm_rq_target_io *tio = blk_mq_rq_to_pdu(rq);
struct mapped_device *md = tio->md;
struct dm_target *ti = md->immutable_target;
if (unlikely(!ti)) {
int srcu_idx;
struct dm_table *map = dm_get_live_table(md, &srcu_idx);
ti = dm_table_find_target(map, 0);
dm_put_live_table(md, srcu_idx);
}
if (unlikely(test_bit(BLK_MQ_S_STOPPED, &hctx->state)))
return BLK_MQ_RQ_QUEUE_BUSY;
if (ti->type->busy && ti->type->busy(ti))
return BLK_MQ_RQ_QUEUE_BUSY;
dm_start_request(md, rq);
init_tio(tio, rq, md);
tio->ti = ti;
if (map_request(tio, rq, md) == DM_MAPIO_REQUEUE) {
rq_end_stats(md, rq);
rq_completed(md, rq_data_dir(rq), false);
return BLK_MQ_RQ_QUEUE_BUSY;
}
return BLK_MQ_RQ_QUEUE_OK;
}
int dm_mq_init_request_queue(struct mapped_device *md, struct dm_table *t)
{
struct request_queue *q;
struct dm_target *immutable_tgt;
int err;
if (!dm_table_all_blk_mq_devices(t)) {
DMERR("request-based dm-mq may only be stacked on blk-mq device(s)");
return -EINVAL;
}
md->tag_set = kzalloc_node(sizeof(struct blk_mq_tag_set), GFP_KERNEL, md->numa_node_id);
if (!md->tag_set)
return -ENOMEM;
md->tag_set->ops = &dm_mq_ops;
md->tag_set->queue_depth = dm_get_blk_mq_queue_depth();
md->tag_set->numa_node = md->numa_node_id;
md->tag_set->flags = BLK_MQ_F_SHOULD_MERGE | BLK_MQ_F_SG_MERGE;
md->tag_set->nr_hw_queues = dm_get_blk_mq_nr_hw_queues();
md->tag_set->driver_data = md;
md->tag_set->cmd_size = sizeof(struct dm_rq_target_io);
immutable_tgt = dm_table_get_immutable_target(t);
if (immutable_tgt && immutable_tgt->per_io_data_size) {
md->tag_set->cmd_size += immutable_tgt->per_io_data_size;
md->init_tio_pdu = true;
}
err = blk_mq_alloc_tag_set(md->tag_set);
if (err)
goto out_kfree_tag_set;
q = blk_mq_init_allocated_queue(md->tag_set, md->queue);
if (IS_ERR(q)) {
err = PTR_ERR(q);
goto out_tag_set;
}
dm_init_md_queue(md);
blk_mq_register_disk(md->disk);
return 0;
out_tag_set:
blk_mq_free_tag_set(md->tag_set);
out_kfree_tag_set:
kfree(md->tag_set);
return err;
}
void dm_mq_cleanup_mapped_device(struct mapped_device *md)
{
if (md->tag_set) {
blk_mq_free_tag_set(md->tag_set);
kfree(md->tag_set);
}
}
