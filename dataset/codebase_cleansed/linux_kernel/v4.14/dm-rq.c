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
static void dm_mq_start_queue(struct request_queue *q)
{
blk_mq_unquiesce_queue(q);
blk_mq_kick_requeue_list(q);
}
void dm_start_queue(struct request_queue *q)
{
if (!q->mq_ops)
dm_old_start_queue(q);
else
dm_mq_start_queue(q);
}
static void dm_old_stop_queue(struct request_queue *q)
{
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
if (!blk_queue_stopped(q))
blk_stop_queue(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
static void dm_mq_stop_queue(struct request_queue *q)
{
if (blk_mq_queue_stopped(q))
return;
blk_mq_quiesce_queue(q);
}
void dm_stop_queue(struct request_queue *q)
{
if (!q->mq_ops)
dm_old_stop_queue(q);
else
dm_mq_stop_queue(q);
}
static void end_clone_bio(struct bio *clone)
{
struct dm_rq_clone_bio_info *info =
container_of(clone, struct dm_rq_clone_bio_info, clone);
struct dm_rq_target_io *tio = info->tio;
unsigned int nr_bytes = info->orig->bi_iter.bi_size;
blk_status_t error = clone->bi_status;
bool is_last = !clone->bi_next;
bio_put(clone);
if (tio->error)
return;
else if (error) {
tio->error = error;
goto exit;
}
tio->completed += nr_bytes;
if (is_last)
exit:
blk_update_request(tio->orig, BLK_STS_OK, tio->completed);
}
static struct dm_rq_target_io *tio_from_request(struct request *rq)
{
return blk_mq_rq_to_pdu(rq);
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
struct request_queue *q = md->queue;
unsigned long flags;
atomic_dec(&md->pending[rw]);
if (!md_in_flight(md))
wake_up(&md->wait);
if (!q->mq_ops && run_queue) {
spin_lock_irqsave(q->queue_lock, flags);
blk_run_queue_async(q);
spin_unlock_irqrestore(q->queue_lock, flags);
}
dm_put(md);
}
static void dm_end_request(struct request *clone, blk_status_t error)
{
int rw = rq_data_dir(clone);
struct dm_rq_target_io *tio = clone->end_io_data;
struct mapped_device *md = tio->md;
struct request *rq = tio->orig;
blk_rq_unprep_clone(clone);
tio->ti->type->release_clone_rq(clone);
rq_end_stats(md, rq);
if (!rq->q->mq_ops)
blk_end_request_all(rq, error);
else
blk_mq_end_request(rq, error);
rq_completed(md, rw, true);
}
static void dm_old_requeue_request(struct request *rq, unsigned long delay_ms)
{
struct request_queue *q = rq->q;
unsigned long flags;
spin_lock_irqsave(q->queue_lock, flags);
blk_requeue_request(q, rq);
blk_delay_queue(q, delay_ms);
spin_unlock_irqrestore(q->queue_lock, flags);
}
static void __dm_mq_kick_requeue_list(struct request_queue *q, unsigned long msecs)
{
blk_mq_delay_kick_requeue_list(q, msecs);
}
void dm_mq_kick_requeue_list(struct mapped_device *md)
{
__dm_mq_kick_requeue_list(dm_get_md_queue(md), 0);
}
static void dm_mq_delay_requeue_request(struct request *rq, unsigned long msecs)
{
blk_mq_requeue_request(rq, false);
__dm_mq_kick_requeue_list(rq->q, msecs);
}
static void dm_requeue_original_request(struct dm_rq_target_io *tio, bool delay_requeue)
{
struct mapped_device *md = tio->md;
struct request *rq = tio->orig;
int rw = rq_data_dir(rq);
unsigned long delay_ms = delay_requeue ? 100 : 0;
rq_end_stats(md, rq);
if (tio->clone) {
blk_rq_unprep_clone(tio->clone);
tio->ti->type->release_clone_rq(tio->clone);
}
if (!rq->q->mq_ops)
dm_old_requeue_request(rq, delay_ms);
else
dm_mq_delay_requeue_request(rq, delay_ms);
rq_completed(md, rw, false);
}
static void dm_done(struct request *clone, blk_status_t error, bool mapped)
{
int r = DM_ENDIO_DONE;
struct dm_rq_target_io *tio = clone->end_io_data;
dm_request_endio_fn rq_end_io = NULL;
if (tio->ti) {
rq_end_io = tio->ti->type->rq_end_io;
if (mapped && rq_end_io)
r = rq_end_io(tio->ti, clone, error, &tio->info);
}
if (unlikely(error == BLK_STS_TARGET)) {
if (req_op(clone) == REQ_OP_WRITE_SAME &&
!clone->q->limits.max_write_same_sectors)
disable_write_same(tio->md);
if (req_op(clone) == REQ_OP_WRITE_ZEROES &&
!clone->q->limits.max_write_zeroes_sectors)
disable_write_zeroes(tio->md);
}
switch (r) {
case DM_ENDIO_DONE:
dm_end_request(clone, error);
break;
case DM_ENDIO_INCOMPLETE:
return;
case DM_ENDIO_REQUEUE:
dm_requeue_original_request(tio, false);
break;
default:
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
struct mapped_device *md = tio->md;
rq_end_stats(md, rq);
rw = rq_data_dir(rq);
if (!rq->q->mq_ops)
blk_end_request_all(rq, tio->error);
else
blk_mq_end_request(rq, tio->error);
rq_completed(md, rw, false);
return;
}
if (rq->rq_flags & RQF_FAILED)
mapped = false;
dm_done(clone, tio->error, mapped);
}
static void dm_complete_request(struct request *rq, blk_status_t error)
{
struct dm_rq_target_io *tio = tio_from_request(rq);
tio->error = error;
if (!rq->q->mq_ops)
blk_complete_request(rq);
else
blk_mq_complete_request(rq);
}
static void dm_kill_unmapped_request(struct request *rq, blk_status_t error)
{
rq->rq_flags |= RQF_FAILED;
dm_complete_request(rq, error);
}
static void end_clone_request(struct request *clone, blk_status_t error)
{
struct dm_rq_target_io *tio = clone->end_io_data;
dm_complete_request(tio->orig, error);
}
static void dm_dispatch_clone_request(struct request *clone, struct request *rq)
{
blk_status_t r;
if (blk_queue_io_stat(clone->q))
clone->rq_flags |= RQF_IO_STAT;
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
clone->end_io = end_clone_request;
clone->end_io_data = tio;
tio->clone = clone;
return 0;
}
static void init_tio(struct dm_rq_target_io *tio, struct request *rq,
struct mapped_device *md)
{
tio->md = md;
tio->ti = NULL;
tio->clone = NULL;
tio->orig = rq;
tio->error = 0;
tio->completed = 0;
if (!md->init_tio_pdu)
memset(&tio->info, 0, sizeof(tio->info));
if (md->kworker_task)
kthread_init_work(&tio->work, map_tio_request);
}
static int map_request(struct dm_rq_target_io *tio)
{
int r;
struct dm_target *ti = tio->ti;
struct mapped_device *md = tio->md;
struct request *rq = tio->orig;
struct request *clone = NULL;
r = ti->type->clone_and_map_rq(ti, rq, &tio->info, &clone);
switch (r) {
case DM_MAPIO_SUBMITTED:
break;
case DM_MAPIO_REMAPPED:
if (setup_clone(clone, rq, tio, GFP_ATOMIC)) {
ti->type->release_clone_rq(clone);
return DM_MAPIO_REQUEUE;
}
trace_block_rq_remap(clone->q, clone, disk_devt(dm_disk(md)),
blk_rq_pos(rq));
dm_dispatch_clone_request(clone, rq);
break;
case DM_MAPIO_REQUEUE:
break;
case DM_MAPIO_DELAY_REQUEUE:
dm_requeue_original_request(tio, true);
break;
case DM_MAPIO_KILL:
dm_kill_unmapped_request(rq, BLK_STS_IOERR);
break;
default:
DMWARN("unimplemented target map return value: %d", r);
BUG();
}
return r;
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
static int __dm_rq_init_rq(struct mapped_device *md, struct request *rq)
{
struct dm_rq_target_io *tio = blk_mq_rq_to_pdu(rq);
tio->md = md;
if (md->init_tio_pdu) {
tio->info.ptr = tio + 1;
}
return 0;
}
static int dm_rq_init_rq(struct request_queue *q, struct request *rq, gfp_t gfp)
{
return __dm_rq_init_rq(q->rq_alloc_data, rq);
}
static void map_tio_request(struct kthread_work *work)
{
struct dm_rq_target_io *tio = container_of(work, struct dm_rq_target_io, work);
if (map_request(tio) == DM_MAPIO_REQUEUE)
dm_requeue_original_request(tio, false);
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
if (unlikely(!map)) {
dm_put_live_table(md, srcu_idx);
return;
}
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
md_in_flight(md) && rq->bio && !bio_multiple_segments(rq->bio) &&
md->last_rq_pos == pos && md->last_rq_rw == rq_data_dir(rq)) ||
(ti->type->busy && ti->type->busy(ti))) {
blk_delay_queue(q, 10);
return;
}
dm_start_request(md, rq);
tio = tio_from_request(rq);
init_tio(tio, rq, md);
tio->ti = ti;
kthread_queue_work(&md->kworker, &tio->work);
BUG_ON(!irqs_disabled());
}
}
int dm_old_init_request_queue(struct mapped_device *md, struct dm_table *t)
{
struct dm_target *immutable_tgt;
md->queue->cmd_size = sizeof(struct dm_rq_target_io);
md->queue->rq_alloc_data = md;
md->queue->request_fn = dm_old_request_fn;
md->queue->init_rq_fn = dm_rq_init_rq;
immutable_tgt = dm_table_get_immutable_target(t);
if (immutable_tgt && immutable_tgt->per_io_data_size) {
md->queue->cmd_size += immutable_tgt->per_io_data_size;
md->init_tio_pdu = true;
}
if (blk_init_allocated_queue(md->queue) < 0)
return -EINVAL;
md->seq_rq_merge_deadline_usecs = 0;
dm_init_normal_md_queue(md);
blk_queue_softirq_done(md->queue, dm_softirq_done);
kthread_init_worker(&md->kworker);
md->kworker_task = kthread_run(kthread_worker_fn, &md->kworker,
"kdmwork-%s", dm_device_name(md));
if (IS_ERR(md->kworker_task)) {
int error = PTR_ERR(md->kworker_task);
md->kworker_task = NULL;
return error;
}
elv_register_queue(md->queue);
return 0;
}
static int dm_mq_init_request(struct blk_mq_tag_set *set, struct request *rq,
unsigned int hctx_idx, unsigned int numa_node)
{
return __dm_rq_init_rq(set->driver_data, rq);
}
static blk_status_t dm_mq_queue_rq(struct blk_mq_hw_ctx *hctx,
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
if (ti->type->busy && ti->type->busy(ti))
return BLK_STS_RESOURCE;
dm_start_request(md, rq);
init_tio(tio, rq, md);
tio->ti = ti;
if (map_request(tio) == DM_MAPIO_REQUEUE) {
rq_end_stats(md, rq);
rq_completed(md, rq_data_dir(rq), false);
blk_mq_delay_run_hw_queue(hctx, 100);
return BLK_STS_RESOURCE;
}
return BLK_STS_OK;
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
err = blk_mq_register_dev(disk_to_dev(md->disk), q);
if (err)
goto out_cleanup_queue;
return 0;
out_cleanup_queue:
blk_cleanup_queue(q);
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
