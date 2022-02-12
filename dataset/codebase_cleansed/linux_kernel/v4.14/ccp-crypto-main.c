static inline bool ccp_crypto_success(int err)
{
if (err && (err != -EINPROGRESS) && (err != -EBUSY))
return false;
return true;
}
static struct ccp_crypto_cmd *ccp_crypto_cmd_complete(
struct ccp_crypto_cmd *crypto_cmd, struct ccp_crypto_cmd **backlog)
{
struct ccp_crypto_cmd *held = NULL, *tmp;
unsigned long flags;
*backlog = NULL;
spin_lock_irqsave(&req_queue_lock, flags);
tmp = crypto_cmd;
list_for_each_entry_continue(tmp, &req_queue.cmds, entry) {
if (crypto_cmd->tfm != tmp->tfm)
continue;
held = tmp;
break;
}
if (req_queue.backlog != &req_queue.cmds) {
if (req_queue.backlog == &crypto_cmd->entry)
req_queue.backlog = crypto_cmd->entry.next;
*backlog = container_of(req_queue.backlog,
struct ccp_crypto_cmd, entry);
req_queue.backlog = req_queue.backlog->next;
if (req_queue.backlog == &crypto_cmd->entry)
req_queue.backlog = crypto_cmd->entry.next;
}
req_queue.cmd_count--;
list_del(&crypto_cmd->entry);
spin_unlock_irqrestore(&req_queue_lock, flags);
return held;
}
static void ccp_crypto_complete(void *data, int err)
{
struct ccp_crypto_cmd *crypto_cmd = data;
struct ccp_crypto_cmd *held, *next, *backlog;
struct crypto_async_request *req = crypto_cmd->req;
struct ccp_ctx *ctx = crypto_tfm_ctx(req->tfm);
int ret;
if (err == -EINPROGRESS) {
if (crypto_cmd->ret == -EBUSY) {
crypto_cmd->ret = -EINPROGRESS;
req->complete(req, -EINPROGRESS);
}
return;
}
held = ccp_crypto_cmd_complete(crypto_cmd, &backlog);
if (backlog) {
backlog->ret = -EINPROGRESS;
backlog->req->complete(backlog->req, -EINPROGRESS);
}
if (crypto_cmd->ret == -EBUSY)
req->complete(req, -EINPROGRESS);
ret = err;
if (ctx->complete)
ret = ctx->complete(req, ret);
req->complete(req, ret);
while (held) {
held->cmd->flags |= CCP_CMD_MAY_BACKLOG;
ret = ccp_enqueue_cmd(held->cmd);
if (ccp_crypto_success(ret))
break;
ctx = crypto_tfm_ctx(held->req->tfm);
if (ctx->complete)
ret = ctx->complete(held->req, ret);
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
}
static int ccp_crypto_enqueue_cmd(struct ccp_crypto_cmd *crypto_cmd)
{
struct ccp_crypto_cmd *active = NULL, *tmp;
unsigned long flags;
bool free_cmd = true;
int ret;
spin_lock_irqsave(&req_queue_lock, flags);
if (req_queue.cmd_count >= CCP_CRYPTO_MAX_QLEN) {
ret = -EBUSY;
if (!(crypto_cmd->cmd->flags & CCP_CMD_MAY_BACKLOG))
goto e_lock;
}
list_for_each_entry(tmp, &req_queue.cmds, entry) {
if (crypto_cmd->tfm != tmp->tfm)
continue;
active = tmp;
break;
}
ret = -EINPROGRESS;
if (!active) {
ret = ccp_enqueue_cmd(crypto_cmd->cmd);
if (!ccp_crypto_success(ret))
goto e_lock;
if ((ret == -EBUSY) &&
!(crypto_cmd->cmd->flags & CCP_CMD_MAY_BACKLOG))
goto e_lock;
}
if (req_queue.cmd_count >= CCP_CRYPTO_MAX_QLEN) {
ret = -EBUSY;
if (req_queue.backlog == &req_queue.cmds)
req_queue.backlog = &crypto_cmd->entry;
}
crypto_cmd->ret = ret;
req_queue.cmd_count++;
list_add_tail(&crypto_cmd->entry, &req_queue.cmds);
free_cmd = false;
e_lock:
spin_unlock_irqrestore(&req_queue_lock, flags);
if (free_cmd)
kfree(crypto_cmd);
return ret;
}
int ccp_crypto_enqueue_request(struct crypto_async_request *req,
struct ccp_cmd *cmd)
{
struct ccp_crypto_cmd *crypto_cmd;
gfp_t gfp;
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
return ccp_crypto_enqueue_cmd(crypto_cmd);
}
struct scatterlist *ccp_crypto_sg_table_add(struct sg_table *table,
struct scatterlist *sg_add)
{
struct scatterlist *sg, *sg_last = NULL;
for (sg = table->sgl; sg; sg = sg_next(sg))
if (!sg_page(sg))
break;
if (WARN_ON(!sg))
return NULL;
for (; sg && sg_add; sg = sg_next(sg), sg_add = sg_next(sg_add)) {
sg_set_page(sg, sg_page(sg_add), sg_add->length,
sg_add->offset);
sg_last = sg;
}
if (WARN_ON(sg_add))
return NULL;
return sg_last;
}
static int ccp_register_algs(void)
{
int ret;
if (!aes_disable) {
ret = ccp_register_aes_algs(&cipher_algs);
if (ret)
return ret;
ret = ccp_register_aes_cmac_algs(&hash_algs);
if (ret)
return ret;
ret = ccp_register_aes_xts_algs(&cipher_algs);
if (ret)
return ret;
ret = ccp_register_aes_aeads(&aead_algs);
if (ret)
return ret;
}
if (!des3_disable) {
ret = ccp_register_des3_algs(&cipher_algs);
if (ret)
return ret;
}
if (!sha_disable) {
ret = ccp_register_sha_algs(&hash_algs);
if (ret)
return ret;
}
if (!rsa_disable) {
ret = ccp_register_rsa_algs(&akcipher_algs);
if (ret)
return ret;
}
return 0;
}
static void ccp_unregister_algs(void)
{
struct ccp_crypto_ahash_alg *ahash_alg, *ahash_tmp;
struct ccp_crypto_ablkcipher_alg *ablk_alg, *ablk_tmp;
struct ccp_crypto_aead *aead_alg, *aead_tmp;
struct ccp_crypto_akcipher_alg *akc_alg, *akc_tmp;
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
list_for_each_entry_safe(aead_alg, aead_tmp, &aead_algs, entry) {
crypto_unregister_aead(&aead_alg->alg);
list_del(&aead_alg->entry);
kfree(aead_alg);
}
list_for_each_entry_safe(akc_alg, akc_tmp, &akcipher_algs, entry) {
crypto_unregister_akcipher(&akc_alg->alg);
list_del(&akc_alg->entry);
kfree(akc_alg);
}
}
static int ccp_crypto_init(void)
{
int ret;
ret = ccp_present();
if (ret)
return ret;
spin_lock_init(&req_queue_lock);
INIT_LIST_HEAD(&req_queue.cmds);
req_queue.backlog = &req_queue.cmds;
req_queue.cmd_count = 0;
ret = ccp_register_algs();
if (ret)
ccp_unregister_algs();
return ret;
}
static void ccp_crypto_exit(void)
{
ccp_unregister_algs();
}
