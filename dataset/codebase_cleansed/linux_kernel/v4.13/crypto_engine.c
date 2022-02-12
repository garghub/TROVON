static void crypto_pump_requests(struct crypto_engine *engine,
bool in_kthread)
{
struct crypto_async_request *async_req, *backlog;
struct ahash_request *hreq;
struct ablkcipher_request *breq;
unsigned long flags;
bool was_busy = false;
int ret, rtype;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->cur_req)
goto out;
if (engine->idling) {
kthread_queue_work(engine->kworker, &engine->pump_requests);
goto out;
}
if (!crypto_queue_len(&engine->queue) || !engine->running) {
if (!engine->busy)
goto out;
if (!in_kthread) {
kthread_queue_work(engine->kworker,
&engine->pump_requests);
goto out;
}
engine->busy = false;
engine->idling = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (engine->unprepare_crypt_hardware &&
engine->unprepare_crypt_hardware(engine))
dev_err(engine->dev, "failed to unprepare crypt hardware\n");
spin_lock_irqsave(&engine->queue_lock, flags);
engine->idling = false;
goto out;
}
backlog = crypto_get_backlog(&engine->queue);
async_req = crypto_dequeue_request(&engine->queue);
if (!async_req)
goto out;
engine->cur_req = async_req;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
if (engine->busy)
was_busy = true;
else
engine->busy = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
rtype = crypto_tfm_alg_type(engine->cur_req->tfm);
if (!was_busy && engine->prepare_crypt_hardware) {
ret = engine->prepare_crypt_hardware(engine);
if (ret) {
dev_err(engine->dev, "failed to prepare crypt hardware\n");
goto req_err;
}
}
switch (rtype) {
case CRYPTO_ALG_TYPE_AHASH:
hreq = ahash_request_cast(engine->cur_req);
if (engine->prepare_hash_request) {
ret = engine->prepare_hash_request(engine, hreq);
if (ret) {
dev_err(engine->dev, "failed to prepare request: %d\n",
ret);
goto req_err;
}
engine->cur_req_prepared = true;
}
ret = engine->hash_one_request(engine, hreq);
if (ret) {
dev_err(engine->dev, "failed to hash one request from queue\n");
goto req_err;
}
return;
case CRYPTO_ALG_TYPE_ABLKCIPHER:
breq = ablkcipher_request_cast(engine->cur_req);
if (engine->prepare_cipher_request) {
ret = engine->prepare_cipher_request(engine, breq);
if (ret) {
dev_err(engine->dev, "failed to prepare request: %d\n",
ret);
goto req_err;
}
engine->cur_req_prepared = true;
}
ret = engine->cipher_one_request(engine, breq);
if (ret) {
dev_err(engine->dev, "failed to cipher one request from queue\n");
goto req_err;
}
return;
default:
dev_err(engine->dev, "failed to prepare request of unknown type\n");
return;
}
req_err:
switch (rtype) {
case CRYPTO_ALG_TYPE_AHASH:
hreq = ahash_request_cast(engine->cur_req);
crypto_finalize_hash_request(engine, hreq, ret);
break;
case CRYPTO_ALG_TYPE_ABLKCIPHER:
breq = ablkcipher_request_cast(engine->cur_req);
crypto_finalize_cipher_request(engine, breq, ret);
break;
}
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
int crypto_transfer_cipher_request(struct crypto_engine *engine,
struct ablkcipher_request *req,
bool need_pump)
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
kthread_queue_work(engine->kworker, &engine->pump_requests);
spin_unlock_irqrestore(&engine->queue_lock, flags);
return ret;
}
int crypto_transfer_cipher_request_to_engine(struct crypto_engine *engine,
struct ablkcipher_request *req)
{
return crypto_transfer_cipher_request(engine, req, true);
}
int crypto_transfer_hash_request(struct crypto_engine *engine,
struct ahash_request *req, bool need_pump)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (!engine->running) {
spin_unlock_irqrestore(&engine->queue_lock, flags);
return -ESHUTDOWN;
}
ret = ahash_enqueue_request(&engine->queue, req);
if (!engine->busy && need_pump)
kthread_queue_work(engine->kworker, &engine->pump_requests);
spin_unlock_irqrestore(&engine->queue_lock, flags);
return ret;
}
int crypto_transfer_hash_request_to_engine(struct crypto_engine *engine,
struct ahash_request *req)
{
return crypto_transfer_hash_request(engine, req, true);
}
void crypto_finalize_cipher_request(struct crypto_engine *engine,
struct ablkcipher_request *req, int err)
{
unsigned long flags;
bool finalize_cur_req = false;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->cur_req == &req->base)
finalize_cur_req = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (finalize_cur_req) {
if (engine->cur_req_prepared &&
engine->unprepare_cipher_request) {
ret = engine->unprepare_cipher_request(engine, req);
if (ret)
dev_err(engine->dev, "failed to unprepare request\n");
}
spin_lock_irqsave(&engine->queue_lock, flags);
engine->cur_req = NULL;
engine->cur_req_prepared = false;
spin_unlock_irqrestore(&engine->queue_lock, flags);
}
req->base.complete(&req->base, err);
kthread_queue_work(engine->kworker, &engine->pump_requests);
}
void crypto_finalize_hash_request(struct crypto_engine *engine,
struct ahash_request *req, int err)
{
unsigned long flags;
bool finalize_cur_req = false;
int ret;
spin_lock_irqsave(&engine->queue_lock, flags);
if (engine->cur_req == &req->base)
finalize_cur_req = true;
spin_unlock_irqrestore(&engine->queue_lock, flags);
if (finalize_cur_req) {
if (engine->cur_req_prepared &&
engine->unprepare_hash_request) {
ret = engine->unprepare_hash_request(engine, req);
if (ret)
dev_err(engine->dev, "failed to unprepare request\n");
}
spin_lock_irqsave(&engine->queue_lock, flags);
engine->cur_req = NULL;
engine->cur_req_prepared = false;
spin_unlock_irqrestore(&engine->queue_lock, flags);
}
req->base.complete(&req->base, err);
kthread_queue_work(engine->kworker, &engine->pump_requests);
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
kthread_queue_work(engine->kworker, &engine->pump_requests);
return 0;
}
int crypto_engine_stop(struct crypto_engine *engine)
{
unsigned long flags;
unsigned int limit = 500;
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
dev_warn(engine->dev, "could not stop engine\n");
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
engine->dev = dev;
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
engine->kworker = kthread_create_worker(0, "%s", engine->name);
if (IS_ERR(engine->kworker)) {
dev_err(dev, "failed to create crypto request pump task\n");
return NULL;
}
kthread_init_work(&engine->pump_requests, crypto_pump_work);
if (engine->rt) {
dev_info(dev, "will run requests pump with realtime priority\n");
sched_setscheduler(engine->kworker->task, SCHED_FIFO, &param);
}
return engine;
}
int crypto_engine_exit(struct crypto_engine *engine)
{
int ret;
ret = crypto_engine_stop(engine);
if (ret)
return ret;
kthread_destroy_worker(engine->kworker);
return 0;
}
