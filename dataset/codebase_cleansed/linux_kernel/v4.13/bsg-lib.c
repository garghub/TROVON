static void bsg_teardown_job(struct kref *kref)
{
struct bsg_job *job = container_of(kref, struct bsg_job, kref);
struct request *rq = job->req;
put_device(job->dev);
kfree(job->request_payload.sg_list);
kfree(job->reply_payload.sg_list);
blk_end_request_all(rq, BLK_STS_OK);
}
void bsg_job_put(struct bsg_job *job)
{
kref_put(&job->kref, bsg_teardown_job);
}
int bsg_job_get(struct bsg_job *job)
{
return kref_get_unless_zero(&job->kref);
}
void bsg_job_done(struct bsg_job *job, int result,
unsigned int reply_payload_rcv_len)
{
struct request *req = job->req;
struct request *rsp = req->next_rq;
struct scsi_request *rq = scsi_req(req);
int err;
err = scsi_req(job->req)->result = result;
if (err < 0)
rq->sense_len = sizeof(u32);
else
rq->sense_len = job->reply_len;
rq->resid_len = 0;
if (rsp) {
WARN_ON(reply_payload_rcv_len > scsi_req(rsp)->resid_len);
scsi_req(rsp)->resid_len -=
min(reply_payload_rcv_len, scsi_req(rsp)->resid_len);
}
blk_complete_request(req);
}
static void bsg_softirq_done(struct request *rq)
{
struct bsg_job *job = blk_mq_rq_to_pdu(rq);
bsg_job_put(job);
}
static int bsg_map_buffer(struct bsg_buffer *buf, struct request *req)
{
size_t sz = (sizeof(struct scatterlist) * req->nr_phys_segments);
BUG_ON(!req->nr_phys_segments);
buf->sg_list = kzalloc(sz, GFP_KERNEL);
if (!buf->sg_list)
return -ENOMEM;
sg_init_table(buf->sg_list, req->nr_phys_segments);
scsi_req(req)->resid_len = blk_rq_bytes(req);
buf->sg_cnt = blk_rq_map_sg(req->q, req, buf->sg_list);
buf->payload_len = blk_rq_bytes(req);
return 0;
}
static int bsg_prepare_job(struct device *dev, struct request *req)
{
struct request *rsp = req->next_rq;
struct scsi_request *rq = scsi_req(req);
struct bsg_job *job = blk_mq_rq_to_pdu(req);
int ret;
job->request = rq->cmd;
job->request_len = rq->cmd_len;
if (req->bio) {
ret = bsg_map_buffer(&job->request_payload, req);
if (ret)
goto failjob_rls_job;
}
if (rsp && rsp->bio) {
ret = bsg_map_buffer(&job->reply_payload, rsp);
if (ret)
goto failjob_rls_rqst_payload;
}
job->dev = dev;
get_device(job->dev);
kref_init(&job->kref);
return 0;
failjob_rls_rqst_payload:
kfree(job->request_payload.sg_list);
failjob_rls_job:
kfree(job);
return -ENOMEM;
}
static void bsg_request_fn(struct request_queue *q)
__releases(q->queue_lock)
__acquires(q->queue_lock)
{
struct device *dev = q->queuedata;
struct request *req;
int ret;
if (!get_device(dev))
return;
while (1) {
req = blk_fetch_request(q);
if (!req)
break;
spin_unlock_irq(q->queue_lock);
ret = bsg_prepare_job(dev, req);
if (ret) {
scsi_req(req)->result = ret;
blk_end_request_all(req, BLK_STS_OK);
spin_lock_irq(q->queue_lock);
continue;
}
ret = q->bsg_job_fn(blk_mq_rq_to_pdu(req));
spin_lock_irq(q->queue_lock);
if (ret)
break;
}
spin_unlock_irq(q->queue_lock);
put_device(dev);
spin_lock_irq(q->queue_lock);
}
static int bsg_init_rq(struct request_queue *q, struct request *req, gfp_t gfp)
{
struct bsg_job *job = blk_mq_rq_to_pdu(req);
struct scsi_request *sreq = &job->sreq;
memset(job, 0, sizeof(*job));
scsi_req_init(sreq);
sreq->sense_len = SCSI_SENSE_BUFFERSIZE;
sreq->sense = kzalloc(sreq->sense_len, gfp);
if (!sreq->sense)
return -ENOMEM;
job->req = req;
job->reply = sreq->sense;
job->reply_len = sreq->sense_len;
job->dd_data = job + 1;
return 0;
}
static void bsg_exit_rq(struct request_queue *q, struct request *req)
{
struct bsg_job *job = blk_mq_rq_to_pdu(req);
struct scsi_request *sreq = &job->sreq;
kfree(sreq->sense);
}
struct request_queue *bsg_setup_queue(struct device *dev, char *name,
bsg_job_fn *job_fn, int dd_job_size)
{
struct request_queue *q;
int ret;
q = blk_alloc_queue(GFP_KERNEL);
if (!q)
return ERR_PTR(-ENOMEM);
q->cmd_size = sizeof(struct bsg_job) + dd_job_size;
q->init_rq_fn = bsg_init_rq;
q->exit_rq_fn = bsg_exit_rq;
q->request_fn = bsg_request_fn;
ret = blk_init_allocated_queue(q);
if (ret)
goto out_cleanup_queue;
q->queuedata = dev;
q->bsg_job_fn = job_fn;
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, q);
queue_flag_set_unlocked(QUEUE_FLAG_SCSI_PASSTHROUGH, q);
blk_queue_softirq_done(q, bsg_softirq_done);
blk_queue_rq_timeout(q, BLK_DEFAULT_SG_TIMEOUT);
ret = bsg_register_queue(q, dev, name, NULL);
if (ret) {
printk(KERN_ERR "%s: bsg interface failed to "
"initialize - register queue\n", dev->kobj.name);
goto out_cleanup_queue;
}
return q;
out_cleanup_queue:
blk_cleanup_queue(q);
return ERR_PTR(ret);
}
