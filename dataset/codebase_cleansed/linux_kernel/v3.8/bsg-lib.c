static void bsg_destroy_job(struct bsg_job *job)
{
put_device(job->dev);
kfree(job->request_payload.sg_list);
kfree(job->reply_payload.sg_list);
kfree(job);
}
void bsg_job_done(struct bsg_job *job, int result,
unsigned int reply_payload_rcv_len)
{
struct request *req = job->req;
struct request *rsp = req->next_rq;
int err;
err = job->req->errors = result;
if (err < 0)
job->req->sense_len = sizeof(u32);
else
job->req->sense_len = job->reply_len;
req->resid_len = 0;
if (rsp) {
WARN_ON(reply_payload_rcv_len > rsp->resid_len);
rsp->resid_len -= min(reply_payload_rcv_len, rsp->resid_len);
}
blk_complete_request(req);
}
static void bsg_softirq_done(struct request *rq)
{
struct bsg_job *job = rq->special;
blk_end_request_all(rq, rq->errors);
bsg_destroy_job(job);
}
static int bsg_map_buffer(struct bsg_buffer *buf, struct request *req)
{
size_t sz = (sizeof(struct scatterlist) * req->nr_phys_segments);
BUG_ON(!req->nr_phys_segments);
buf->sg_list = kzalloc(sz, GFP_KERNEL);
if (!buf->sg_list)
return -ENOMEM;
sg_init_table(buf->sg_list, req->nr_phys_segments);
buf->sg_cnt = blk_rq_map_sg(req->q, req, buf->sg_list);
buf->payload_len = blk_rq_bytes(req);
return 0;
}
static int bsg_create_job(struct device *dev, struct request *req)
{
struct request *rsp = req->next_rq;
struct request_queue *q = req->q;
struct bsg_job *job;
int ret;
BUG_ON(req->special);
job = kzalloc(sizeof(struct bsg_job) + q->bsg_job_size, GFP_KERNEL);
if (!job)
return -ENOMEM;
req->special = job;
job->req = req;
if (q->bsg_job_size)
job->dd_data = (void *)&job[1];
job->request = req->cmd;
job->request_len = req->cmd_len;
job->reply = req->sense;
job->reply_len = SCSI_SENSE_BUFFERSIZE;
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
return 0;
failjob_rls_rqst_payload:
kfree(job->request_payload.sg_list);
failjob_rls_job:
kfree(job);
return -ENOMEM;
}
void bsg_request_fn(struct request_queue *q)
{
struct device *dev = q->queuedata;
struct request *req;
struct bsg_job *job;
int ret;
if (!get_device(dev))
return;
while (1) {
req = blk_fetch_request(q);
if (!req)
break;
spin_unlock_irq(q->queue_lock);
ret = bsg_create_job(dev, req);
if (ret) {
req->errors = ret;
blk_end_request_all(req, ret);
spin_lock_irq(q->queue_lock);
continue;
}
job = req->special;
ret = q->bsg_job_fn(job);
spin_lock_irq(q->queue_lock);
if (ret)
break;
}
spin_unlock_irq(q->queue_lock);
put_device(dev);
spin_lock_irq(q->queue_lock);
}
int bsg_setup_queue(struct device *dev, struct request_queue *q,
char *name, bsg_job_fn *job_fn, int dd_job_size)
{
int ret;
q->queuedata = dev;
q->bsg_job_size = dd_job_size;
q->bsg_job_fn = job_fn;
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, q);
blk_queue_softirq_done(q, bsg_softirq_done);
blk_queue_rq_timeout(q, BLK_DEFAULT_SG_TIMEOUT);
ret = bsg_register_queue(q, dev, name, NULL);
if (ret) {
printk(KERN_ERR "%s: bsg interface failed to "
"initialize - register queue\n", dev->kobj.name);
return ret;
}
return 0;
}
