static void crypto_pump_requests(struct crypto_engine *engine,
bool in_kthread)
{
struct crypto_async_request *async_req, *backlog;
struct ablkcipher_request *req;
unsigned long flags;
bool was_busy = false;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->cur_req)
goto out;
if (engine->idling) {
queue_kthread_work(&engine->kworker, &engine->pump_requests);
goto out;
}
if (!crypto_queue_len(&engine->queue) || !engine->running) {
if (!engine->busy)
goto out;
if (!in_kthread) {
queue_kthread_work(&engine->kworker,
&engine->pump_requests);
goto out;
}
engine->busy = false;
engine->idling = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (engine->unprepare_crypt_hardware &&
engine->unprepare_crypt_hardware(engine))
pr_err("failed to unprepare crypt hardware\n");
spin_lock_irqsave(&engine->queue_lock, flags);
engine->idling = false;
goto out;
}
backlog = crypto_get_backlog(&engine->queue);
async_req = crypto_dequeue_request(&engine->queue);
if (!async_req)
goto out;
req = ablkcipher_request_cast(async_req);
engine->cur_req = req;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
if (engine->busy)
was_busy = true;
else
engine->busy = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (!was_busy && engine->prepare_crypt_hardware) {
ret = engine->prepare_crypt_hardware(engine);
if (ret) {
pr_err("failed to prepare crypt hardware\n");
goto req_err;
}
}
if (engine->prepare_request) {
ret = engine->prepare_request(engine, engine->cur_req);
if (ret) {
pr_err("failed to prepare request: %d\n", ret);
goto req_err;
}
engine->cur_req_prepared = true;
}
ret = engine->crypt_one_request(engine, engine->cur_req);
if (ret) {
pr_err("failed to crypt one request from queue\n");
goto req_err;
}
return;
req_err:
crypto_finalize_request(engine, engine->cur_req, ret);
return;
out:
spin_unlock_irqrestore(&engine->queue_lock, flags);
}
static void crypto_pump_work(struct kthread_work *work)
{
struct crypto_engine *engine =
container_of(work, struct crypto_engine, pump_requests);
crypto_pump_requests(engine, true);
}
int crypto_transfer_request(struct crypto_engine *engine,
struct ablkcipher_request *req, bool need_pump)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (!engine->running) {
spin_unlock_irqrestore(&engine->queue_lock, flags);
return -ESHUTDOWN;
}
ret = ablkcipher_enqueue_request(&engine->queue, req);
if (!engine->busy && need_pump)
queue_kthread_work(&engine->kworker, &engine->pump_requests);
spin_unlock_irqrestore(&engine->queue_lock, flags);
return ret;
}
int crypto_transfer_request_to_engine(struct crypto_engine *engine,
struct ablkcipher_request *req)
{
return crypto_transfer_request(engine, req, true);
}
void crypto_finalize_request(struct crypto_engine *engine,
struct ablkcipher_request *req, int err)
{
unsigned long flags;
bool finalize_cur_req = false;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->cur_req == req)
finalize_cur_req = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (finalize_cur_req) {
if (engine->cur_req_prepared && engine->unprepare_request) {
ret = engine->unprepare_request(engine, req);
if (ret)
pr_err("failed to unprepare request\n");
}
spin_lock_irqsave(&engine->queue_lock, flags);
engine->cur_req = NULL;
engine->cur_req_prepared = false;
spin_unlock_irqrestore(&engine->queue_lock, flags);
}
req->base.complete(&req->base, err);
queue_kthread_work(&engine->kworker, &engine->pump_requests);
}
int crypto_engine_start(struct crypto_engine *engine)
{
unsigned long flags;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->running || engine->busy) {
spin_unlock_irqrestore(&engine->queue_lock, flags);
return -EBUSY;
}
engine->running = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
queue_kthread_work(&engine->kworker, &engine->pump_requests);
return 0;
}
int crypto_engine_stop(struct crypto_engine *engine)
{
unsigned long flags;
unsigned limit = 500;
int ret = 0;
spin_lock_irqsave(&engine->queue_lock, flags);
while ((crypto_queue_len(&engine->queue) || engine->busy) && limit--) {
spin_unlock_irqrestore(&engine->queue_lock, flags);
msleep(20);
spin_lock_irqsave(&engine->queue_lock, flags);
}
if (crypto_queue_len(&engine->queue) || engine->busy)
ret = -EBUSY;
else
engine->running = false;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (ret)
pr_warn("could not stop engine\n");
return ret;
}
struct crypto_engine *crypto_engine_alloc_init(struct device *dev, bool rt)
{
struct sched_param param = { .sched_priority = MAX_RT_PRIO - 1 };
struct crypto_engine *engine;
if (!dev)
return NULL;
engine = devm_kzalloc(dev, sizeof(*engine), GFP_KERNEL);
if (!engine)
return NULL;
engine->rt = rt;
engine->running = false;
engine->busy = false;
engine->idling = false;
engine->cur_req_prepared = false;
engine->priv_data = dev;
snprintf(engine->name, sizeof(engine->name),
"%s-engine", dev_name(dev));
crypto_init_queue(&engine->queue, CRYPTO_ENGINE_MAX_QLEN);
spin_lock_init(&engine->queue_lock);
init_kthread_worker(&engine->kworker);
engine->kworker_task = kthread_run(kthread_worker_fn,
&engine->kworker, "%s",
engine->name);
if (IS_ERR(engine->kworker_task)) {
dev_err(dev, "failed to create crypto request pump task\n");
return NULL;
}
init_kthread_work(&engine->pump_requests, crypto_pump_work);
if (engine->rt) {
dev_info(dev, "will run requests pump with realtime priority\n");
sched_setscheduler(engine->kworker_task, SCHED_FIFO, &param);
}
return engine;
}
int crypto_engine_exit(struct crypto_engine *engine)
{
int ret;
ret = crypto_engine_stop(engine);
if (ret)
return ret;
flush_kthread_worker(&engine->kworker);
kthread_stop(engine->kworker_task);
return 0;
}
