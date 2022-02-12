static inline bool ccp_crypto_success(int err)
{
if (err && (err != -EINPROGRESS) && (err != -EBUSY))
return false;
return true;
}
static struct ccp_crypto_cmd *ccp_crypto_cmd_complete(
struct ccp_crypto_cmd *crypto_cmd, struct ccp_crypto_cmd **backlog)
{
struct ccp_crypto_cpu_queue *cpu_queue;
struct ccp_crypto_cmd *held = NULL, *tmp;
*backlog = NULL;
cpu_queue = this_cpu_ptr(req_queue.cpu_queue);
tmp = crypto_cmd;
list_for_each_entry_continue(tmp, &cpu_queue->cmds, entry) {
if (crypto_cmd->tfm != tmp->tfm)
continue;
held = tmp;
break;
}
if (cpu_queue->backlog != &cpu_queue->cmds) {
if (cpu_queue->backlog == &crypto_cmd->entry)
cpu_queue->backlog = crypto_cmd->entry.next;
*backlog = container_of(cpu_queue->backlog,
struct ccp_crypto_cmd, entry);
cpu_queue->backlog = cpu_queue->backlog->next;
if (cpu_queue->backlog == &crypto_cmd->entry)
cpu_queue->backlog = crypto_cmd->entry.next;
}
cpu_queue->cmd_count--;
list_del(&crypto_cmd->entry);
return held;
}
static void ccp_crypto_complete_on_cpu(struct work_struct *work)
{
struct ccp_crypto_cpu *cpu_work =
container_of(work, struct ccp_crypto_cpu, work);
struct ccp_crypto_cmd *crypto_cmd = cpu_work->crypto_cmd;
struct ccp_crypto_cmd *held, *next, *backlog;
struct crypto_async_request *req = crypto_cmd->req;
struct ccp_ctx *ctx = crypto_tfm_ctx(req->tfm);
int cpu, ret;
cpu = get_cpu();
if (cpu_work->err == -EINPROGRESS) {
if (crypto_cmd->ret == -EBUSY) {
crypto_cmd->ret = -EINPROGRESS;
req->complete(req, -EINPROGRESS);
}
goto e_cpu;
}
held = ccp_crypto_cmd_complete(crypto_cmd, &backlog);
if (backlog) {
backlog->ret = -EINPROGRESS;
backlog->req->complete(backlog->req, -EINPROGRESS);
}
if (crypto_cmd->ret == -EBUSY)
req->complete(req, -EINPROGRESS);
ret = cpu_work->err;
if (ctx->complete)
ret = ctx->complete(req, ret);
req->complete(req, ret);
while (held) {
ret = ccp_enqueue_cmd(held->cmd);
if (ccp_crypto_success(ret))
break;
held->req->complete(held->req, ret);
next = ccp_crypto_cmd_complete(held, &backlog);
if (backlog) {
backlog->ret = -EINPROGRESS;
backlog->req->complete(backlog->req, -EINPROGRESS);
}
kfree(held);
held = next;
}
kfree(crypto_cmd);
e_cpu:
put_cpu();
complete(&cpu_work->completion);
}
static void ccp_crypto_complete(void *data, int err)
{
struct ccp_crypto_cmd *crypto_cmd = data;
struct ccp_crypto_cpu cpu_work;
INIT_WORK(&cpu_work.work, ccp_crypto_complete_on_cpu);
init_completion(&cpu_work.completion);
cpu_work.crypto_cmd = crypto_cmd;
cpu_work.err = err;
schedule_work_on(crypto_cmd->cpu, &cpu_work.work);
wait_for_completion(&cpu_work.completion);
}
static int ccp_crypto_enqueue_cmd(struct ccp_crypto_cmd *crypto_cmd)
{
struct ccp_crypto_cpu_queue *cpu_queue;
struct ccp_crypto_cmd *active = NULL, *tmp;
int cpu, ret;
cpu = get_cpu();
crypto_cmd->cpu = cpu;
cpu_queue = this_cpu_ptr(req_queue.cpu_queue);
if (cpu_queue->cmd_count >= CCP_CRYPTO_MAX_QLEN) {
ret = -EBUSY;
if (!(crypto_cmd->cmd->flags & CCP_CMD_MAY_BACKLOG))
goto e_cpu;
}
list_for_each_entry(tmp, &cpu_queue->cmds, entry) {
if (crypto_cmd->tfm != tmp->tfm)
continue;
active = tmp;
break;
}
ret = -EINPROGRESS;
if (!active) {
ret = ccp_enqueue_cmd(crypto_cmd->cmd);
if (!ccp_crypto_success(ret))
goto e_cpu;
}
if (cpu_queue->cmd_count >= CCP_CRYPTO_MAX_QLEN) {
ret = -EBUSY;
if (cpu_queue->backlog == &cpu_queue->cmds)
cpu_queue->backlog = &crypto_cmd->entry;
}
crypto_cmd->ret = ret;
cpu_queue->cmd_count++;
list_add_tail(&crypto_cmd->entry, &cpu_queue->cmds);
e_cpu:
put_cpu();
return ret;
}
int ccp_crypto_enqueue_request(struct crypto_async_request *req,
struct ccp_cmd *cmd)
{
struct ccp_crypto_cmd *crypto_cmd;
gfp_t gfp;
int ret;
gfp = req->flags & CRYPTO_TFM_REQ_MAY_SLEEP ? GFP_KERNEL : GFP_ATOMIC;
crypto_cmd = kzalloc(sizeof(*crypto_cmd), gfp);
if (!crypto_cmd)
return -ENOMEM;
crypto_cmd->cmd = cmd;
crypto_cmd->req = req;
crypto_cmd->tfm = req->tfm;
cmd->callback = ccp_crypto_complete;
cmd->data = crypto_cmd;
if (req->flags & CRYPTO_TFM_REQ_MAY_BACKLOG)
cmd->flags |= CCP_CMD_MAY_BACKLOG;
else
cmd->flags &= ~CCP_CMD_MAY_BACKLOG;
ret = ccp_crypto_enqueue_cmd(crypto_cmd);
if (!ccp_crypto_success(ret))
kfree(crypto_cmd);
return ret;
}
struct scatterlist *ccp_crypto_sg_table_add(struct sg_table *table,
struct scatterlist *sg_add)
{
struct scatterlist *sg, *sg_last = NULL;
for (sg = table->sgl; sg; sg = sg_next(sg))
if (!sg_page(sg))
break;
BUG_ON(!sg);
for (; sg && sg_add; sg = sg_next(sg), sg_add = sg_next(sg_add)) {
sg_set_page(sg, sg_page(sg_add), sg_add->length,
sg_add->offset);
sg_last = sg;
}
BUG_ON(sg_add);
return sg_last;
}
static int ccp_register_algs(void)
{
int ret;
ret = ccp_register_aes_algs(&cipher_algs);
if (ret)
return ret;
ret = ccp_register_aes_cmac_algs(&hash_algs);
if (ret)
return ret;
ret = ccp_register_aes_xts_algs(&cipher_algs);
if (ret)
return ret;
ret = ccp_register_sha_algs(&hash_algs);
if (ret)
return ret;
return 0;
}
static void ccp_unregister_algs(void)
{
struct ccp_crypto_ahash_alg *ahash_alg, *ahash_tmp;
struct ccp_crypto_ablkcipher_alg *ablk_alg, *ablk_tmp;
list_for_each_entry_safe(ahash_alg, ahash_tmp, &hash_algs, entry) {
crypto_unregister_ahash(&ahash_alg->alg);
list_del(&ahash_alg->entry);
kfree(ahash_alg);
}
list_for_each_entry_safe(ablk_alg, ablk_tmp, &cipher_algs, entry) {
crypto_unregister_alg(&ablk_alg->alg);
list_del(&ablk_alg->entry);
kfree(ablk_alg);
}
}
static int ccp_init_queues(void)
{
struct ccp_crypto_cpu_queue *cpu_queue;
int cpu;
req_queue.cpu_queue = alloc_percpu(struct ccp_crypto_cpu_queue);
if (!req_queue.cpu_queue)
return -ENOMEM;
for_each_possible_cpu(cpu) {
cpu_queue = per_cpu_ptr(req_queue.cpu_queue, cpu);
INIT_LIST_HEAD(&cpu_queue->cmds);
cpu_queue->backlog = &cpu_queue->cmds;
cpu_queue->cmd_count = 0;
}
return 0;
}
static void ccp_fini_queue(void)
{
struct ccp_crypto_cpu_queue *cpu_queue;
int cpu;
for_each_possible_cpu(cpu) {
cpu_queue = per_cpu_ptr(req_queue.cpu_queue, cpu);
BUG_ON(!list_empty(&cpu_queue->cmds));
}
free_percpu(req_queue.cpu_queue);
}
static int ccp_crypto_init(void)
{
int ret;
ret = ccp_init_queues();
if (ret)
return ret;
ret = ccp_register_algs();
if (ret) {
ccp_unregister_algs();
ccp_fini_queue();
}
return ret;
}
static void ccp_crypto_exit(void)
{
ccp_unregister_algs();
ccp_fini_queue();
}
