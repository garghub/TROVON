static inline struct mcryptd_hash_request_ctx
*cast_hash_to_mcryptd_ctx(struct sha512_hash_ctx *hash_ctx)
{
struct ahash_request *areq;
areq = container_of((void *) hash_ctx, struct ahash_request, __ctx);
return container_of(areq, struct mcryptd_hash_request_ctx, areq);
}
static inline struct ahash_request
*cast_mcryptd_ctx_to_req(struct mcryptd_hash_request_ctx *ctx)
{
return container_of((void *) ctx, struct ahash_request, __ctx);
}
static void req_ctx_init(struct mcryptd_hash_request_ctx *rctx,
struct ahash_request *areq)
{
rctx->flag = HASH_UPDATE;
}
inline void sha512_init_digest(uint64_t *digest)
{
static const uint64_t initial_digest[SHA512_DIGEST_LENGTH] = {
SHA512_H0, SHA512_H1, SHA512_H2,
SHA512_H3, SHA512_H4, SHA512_H5,
SHA512_H6, SHA512_H7 };
memcpy(digest, initial_digest, sizeof(initial_digest));
}
inline uint32_t sha512_pad(uint8_t padblock[SHA512_BLOCK_SIZE * 2],
uint32_t total_len)
{
uint32_t i = total_len & (SHA512_BLOCK_SIZE - 1);
memset(&padblock[i], 0, SHA512_BLOCK_SIZE);
padblock[i] = 0x80;
i += ((SHA512_BLOCK_SIZE - 1) &
(0 - (total_len + SHA512_PADLENGTHFIELD_SIZE + 1)))
+ 1 + SHA512_PADLENGTHFIELD_SIZE;
#if SHA512_PADLENGTHFIELD_SIZE == 16
*((uint64_t *) &padblock[i - 16]) = 0;
#endif
*((uint64_t *) &padblock[i - 8]) = cpu_to_be64(total_len << 3);
return i >> SHA512_LOG2_BLOCK_SIZE;
}
static struct sha512_hash_ctx *sha512_ctx_mgr_resubmit
(struct sha512_ctx_mgr *mgr, struct sha512_hash_ctx *ctx)
{
while (ctx) {
if (ctx->status & HASH_CTX_STS_COMPLETE) {
ctx->status = HASH_CTX_STS_COMPLETE;
return ctx;
}
if (ctx->partial_block_buffer_length == 0 &&
ctx->incoming_buffer_length) {
const void *buffer = ctx->incoming_buffer;
uint32_t len = ctx->incoming_buffer_length;
uint32_t copy_len;
copy_len = len & (SHA512_BLOCK_SIZE-1);
if (copy_len) {
len -= copy_len;
memcpy(ctx->partial_block_buffer,
((const char *) buffer + len),
copy_len);
ctx->partial_block_buffer_length = copy_len;
}
ctx->incoming_buffer_length = 0;
assert((len % SHA512_BLOCK_SIZE) == 0);
len >>= SHA512_LOG2_BLOCK_SIZE;
if (len) {
ctx->job.buffer = (uint8_t *) buffer;
ctx->job.len = len;
ctx = (struct sha512_hash_ctx *)
sha512_job_mgr_submit(&mgr->mgr,
&ctx->job);
continue;
}
}
if (ctx->status & HASH_CTX_STS_LAST) {
uint8_t *buf = ctx->partial_block_buffer;
uint32_t n_extra_blocks =
sha512_pad(buf, ctx->total_length);
ctx->status = (HASH_CTX_STS_PROCESSING |
HASH_CTX_STS_COMPLETE);
ctx->job.buffer = buf;
ctx->job.len = (uint32_t) n_extra_blocks;
ctx = (struct sha512_hash_ctx *)
sha512_job_mgr_submit(&mgr->mgr, &ctx->job);
continue;
}
if (ctx)
ctx->status = HASH_CTX_STS_IDLE;
return ctx;
}
return NULL;
}
static struct sha512_hash_ctx
*sha512_ctx_mgr_get_comp_ctx(struct sha512_ctx_mgr *mgr)
{
struct sha512_hash_ctx *ctx;
ctx = (struct sha512_hash_ctx *)
sha512_job_mgr_get_comp_job(&mgr->mgr);
return sha512_ctx_mgr_resubmit(mgr, ctx);
}
static void sha512_ctx_mgr_init(struct sha512_ctx_mgr *mgr)
{
sha512_job_mgr_init(&mgr->mgr);
}
static struct sha512_hash_ctx
*sha512_ctx_mgr_submit(struct sha512_ctx_mgr *mgr,
struct sha512_hash_ctx *ctx,
const void *buffer,
uint32_t len,
int flags)
{
if (flags & (~HASH_ENTIRE)) {
ctx->error = HASH_CTX_ERROR_INVALID_FLAGS;
return ctx;
}
if (ctx->status & HASH_CTX_STS_PROCESSING) {
ctx->error = HASH_CTX_ERROR_ALREADY_PROCESSING;
return ctx;
}
if ((ctx->status & HASH_CTX_STS_COMPLETE) && !(flags & HASH_FIRST)) {
ctx->error = HASH_CTX_ERROR_ALREADY_COMPLETED;
return ctx;
}
if (flags & HASH_FIRST) {
sha512_init_digest(ctx->job.result_digest);
ctx->total_length = 0;
ctx->partial_block_buffer_length = 0;
}
ctx->error = HASH_CTX_ERROR_NONE;
ctx->incoming_buffer = buffer;
ctx->incoming_buffer_length = len;
ctx->status = (flags & HASH_LAST) ?
(HASH_CTX_STS_PROCESSING | HASH_CTX_STS_LAST) :
HASH_CTX_STS_PROCESSING;
ctx->total_length += len;
if (ctx->partial_block_buffer_length || len < SHA512_BLOCK_SIZE) {
uint32_t copy_len = SHA512_BLOCK_SIZE -
ctx->partial_block_buffer_length;
if (len < copy_len)
copy_len = len;
if (copy_len) {
memcpy
(&ctx->partial_block_buffer[ctx->partial_block_buffer_length],
buffer, copy_len);
ctx->partial_block_buffer_length += copy_len;
ctx->incoming_buffer = (const void *)
((const char *)buffer + copy_len);
ctx->incoming_buffer_length = len - copy_len;
}
assert(ctx->partial_block_buffer_length <= SHA512_BLOCK_SIZE);
if (ctx->partial_block_buffer_length >= SHA512_BLOCK_SIZE) {
ctx->partial_block_buffer_length = 0;
ctx->job.buffer = ctx->partial_block_buffer;
ctx->job.len = 1;
ctx = (struct sha512_hash_ctx *)
sha512_job_mgr_submit(&mgr->mgr, &ctx->job);
}
}
return sha512_ctx_mgr_resubmit(mgr, ctx);
}
static struct sha512_hash_ctx *sha512_ctx_mgr_flush(struct sha512_ctx_mgr *mgr)
{
struct sha512_hash_ctx *ctx;
while (1) {
ctx = (struct sha512_hash_ctx *)
sha512_job_mgr_flush(&mgr->mgr);
if (!ctx)
return NULL;
ctx = sha512_ctx_mgr_resubmit(mgr, ctx);
if (ctx)
return ctx;
}
}
static int sha512_mb_init(struct ahash_request *areq)
{
struct sha512_hash_ctx *sctx = ahash_request_ctx(areq);
hash_ctx_init(sctx);
sctx->job.result_digest[0] = SHA512_H0;
sctx->job.result_digest[1] = SHA512_H1;
sctx->job.result_digest[2] = SHA512_H2;
sctx->job.result_digest[3] = SHA512_H3;
sctx->job.result_digest[4] = SHA512_H4;
sctx->job.result_digest[5] = SHA512_H5;
sctx->job.result_digest[6] = SHA512_H6;
sctx->job.result_digest[7] = SHA512_H7;
sctx->total_length = 0;
sctx->partial_block_buffer_length = 0;
sctx->status = HASH_CTX_STS_IDLE;
return 0;
}
static int sha512_mb_set_results(struct mcryptd_hash_request_ctx *rctx)
{
int i;
struct sha512_hash_ctx *sctx = ahash_request_ctx(&rctx->areq);
__be64 *dst = (__be64 *) rctx->out;
for (i = 0; i < 8; ++i)
dst[i] = cpu_to_be64(sctx->job.result_digest[i]);
return 0;
}
static int sha_finish_walk(struct mcryptd_hash_request_ctx **ret_rctx,
struct mcryptd_alg_cstate *cstate, bool flush)
{
int flag = HASH_UPDATE;
int nbytes, err = 0;
struct mcryptd_hash_request_ctx *rctx = *ret_rctx;
struct sha512_hash_ctx *sha_ctx;
while (!(rctx->flag & HASH_DONE)) {
nbytes = crypto_ahash_walk_done(&rctx->walk, 0);
if (nbytes < 0) {
err = nbytes;
goto out;
}
if (crypto_ahash_walk_last(&rctx->walk)) {
rctx->flag |= HASH_DONE;
if (rctx->flag & HASH_FINAL)
flag |= HASH_LAST;
}
sha_ctx = (struct sha512_hash_ctx *)
ahash_request_ctx(&rctx->areq);
kernel_fpu_begin();
sha_ctx = sha512_ctx_mgr_submit(cstate->mgr, sha_ctx,
rctx->walk.data, nbytes, flag);
if (!sha_ctx) {
if (flush)
sha_ctx = sha512_ctx_mgr_flush(cstate->mgr);
}
kernel_fpu_end();
if (sha_ctx)
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
else {
rctx = NULL;
goto out;
}
}
if (rctx->flag & HASH_FINAL)
sha512_mb_set_results(rctx);
out:
*ret_rctx = rctx;
return err;
}
static int sha_complete_job(struct mcryptd_hash_request_ctx *rctx,
struct mcryptd_alg_cstate *cstate,
int err)
{
struct ahash_request *req = cast_mcryptd_ctx_to_req(rctx);
struct sha512_hash_ctx *sha_ctx;
struct mcryptd_hash_request_ctx *req_ctx;
int ret;
spin_lock(&cstate->work_lock);
list_del(&rctx->waiter);
spin_unlock(&cstate->work_lock);
if (irqs_disabled())
rctx->complete(&req->base, err);
else {
local_bh_disable();
rctx->complete(&req->base, err);
local_bh_enable();
}
sha_ctx = sha512_ctx_mgr_get_comp_ctx(cstate->mgr);
while (sha_ctx) {
req_ctx = cast_hash_to_mcryptd_ctx(sha_ctx);
ret = sha_finish_walk(&req_ctx, cstate, false);
if (req_ctx) {
spin_lock(&cstate->work_lock);
list_del(&req_ctx->waiter);
spin_unlock(&cstate->work_lock);
req = cast_mcryptd_ctx_to_req(req_ctx);
if (irqs_disabled())
req_ctx->complete(&req->base, ret);
else {
local_bh_disable();
req_ctx->complete(&req->base, ret);
local_bh_enable();
}
}
sha_ctx = sha512_ctx_mgr_get_comp_ctx(cstate->mgr);
}
return 0;
}
static void sha512_mb_add_list(struct mcryptd_hash_request_ctx *rctx,
struct mcryptd_alg_cstate *cstate)
{
unsigned long next_flush;
unsigned long delay = usecs_to_jiffies(FLUSH_INTERVAL);
rctx->tag.arrival = jiffies;
rctx->tag.seq_num = cstate->next_seq_num++;
next_flush = rctx->tag.arrival + delay;
rctx->tag.expire = next_flush;
spin_lock(&cstate->work_lock);
list_add_tail(&rctx->waiter, &cstate->work_list);
spin_unlock(&cstate->work_lock);
mcryptd_arm_flusher(cstate, delay);
}
static int sha512_mb_update(struct ahash_request *areq)
{
struct mcryptd_hash_request_ctx *rctx =
container_of(areq, struct mcryptd_hash_request_ctx,
areq);
struct mcryptd_alg_cstate *cstate =
this_cpu_ptr(sha512_mb_alg_state.alg_cstate);
struct ahash_request *req = cast_mcryptd_ctx_to_req(rctx);
struct sha512_hash_ctx *sha_ctx;
int ret = 0, nbytes;
if (rctx->tag.cpu != smp_processor_id()) {
pr_err("mcryptd error: cpu clash\n");
goto done;
}
req_ctx_init(rctx, areq);
nbytes = crypto_ahash_walk_first(req, &rctx->walk);
if (nbytes < 0) {
ret = nbytes;
goto done;
}
if (crypto_ahash_walk_last(&rctx->walk))
rctx->flag |= HASH_DONE;
sha_ctx = (struct sha512_hash_ctx *) ahash_request_ctx(areq);
sha512_mb_add_list(rctx, cstate);
kernel_fpu_begin();
sha_ctx = sha512_ctx_mgr_submit(cstate->mgr, sha_ctx, rctx->walk.data,
nbytes, HASH_UPDATE);
kernel_fpu_end();
if (!sha_ctx)
return -EINPROGRESS;
if (sha_ctx->error) {
ret = sha_ctx->error;
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
goto done;
}
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
ret = sha_finish_walk(&rctx, cstate, false);
if (!rctx)
return -EINPROGRESS;
done:
sha_complete_job(rctx, cstate, ret);
return ret;
}
static int sha512_mb_finup(struct ahash_request *areq)
{
struct mcryptd_hash_request_ctx *rctx =
container_of(areq, struct mcryptd_hash_request_ctx,
areq);
struct mcryptd_alg_cstate *cstate =
this_cpu_ptr(sha512_mb_alg_state.alg_cstate);
struct ahash_request *req = cast_mcryptd_ctx_to_req(rctx);
struct sha512_hash_ctx *sha_ctx;
int ret = 0, flag = HASH_UPDATE, nbytes;
if (rctx->tag.cpu != smp_processor_id()) {
pr_err("mcryptd error: cpu clash\n");
goto done;
}
req_ctx_init(rctx, areq);
nbytes = crypto_ahash_walk_first(req, &rctx->walk);
if (nbytes < 0) {
ret = nbytes;
goto done;
}
if (crypto_ahash_walk_last(&rctx->walk)) {
rctx->flag |= HASH_DONE;
flag = HASH_LAST;
}
rctx->flag |= HASH_FINAL;
sha_ctx = (struct sha512_hash_ctx *) ahash_request_ctx(areq);
sha512_mb_add_list(rctx, cstate);
kernel_fpu_begin();
sha_ctx = sha512_ctx_mgr_submit(cstate->mgr, sha_ctx, rctx->walk.data,
nbytes, flag);
kernel_fpu_end();
if (!sha_ctx)
return -EINPROGRESS;
if (sha_ctx->error) {
ret = sha_ctx->error;
goto done;
}
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
ret = sha_finish_walk(&rctx, cstate, false);
if (!rctx)
return -EINPROGRESS;
done:
sha_complete_job(rctx, cstate, ret);
return ret;
}
static int sha512_mb_final(struct ahash_request *areq)
{
struct mcryptd_hash_request_ctx *rctx =
container_of(areq, struct mcryptd_hash_request_ctx,
areq);
struct mcryptd_alg_cstate *cstate =
this_cpu_ptr(sha512_mb_alg_state.alg_cstate);
struct sha512_hash_ctx *sha_ctx;
int ret = 0;
u8 data;
if (rctx->tag.cpu != smp_processor_id()) {
pr_err("mcryptd error: cpu clash\n");
goto done;
}
req_ctx_init(rctx, areq);
rctx->flag |= HASH_DONE | HASH_FINAL;
sha_ctx = (struct sha512_hash_ctx *) ahash_request_ctx(areq);
sha512_mb_add_list(rctx, cstate);
kernel_fpu_begin();
sha_ctx = sha512_ctx_mgr_submit(cstate->mgr, sha_ctx, &data, 0,
HASH_LAST);
kernel_fpu_end();
if (!sha_ctx)
return -EINPROGRESS;
if (sha_ctx->error) {
ret = sha_ctx->error;
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
goto done;
}
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
ret = sha_finish_walk(&rctx, cstate, false);
if (!rctx)
return -EINPROGRESS;
done:
sha_complete_job(rctx, cstate, ret);
return ret;
}
static int sha512_mb_export(struct ahash_request *areq, void *out)
{
struct sha512_hash_ctx *sctx = ahash_request_ctx(areq);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha512_mb_import(struct ahash_request *areq, const void *in)
{
struct sha512_hash_ctx *sctx = ahash_request_ctx(areq);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int sha512_mb_async_init_tfm(struct crypto_tfm *tfm)
{
struct mcryptd_ahash *mcryptd_tfm;
struct sha512_mb_ctx *ctx = crypto_tfm_ctx(tfm);
struct mcryptd_hash_ctx *mctx;
mcryptd_tfm = mcryptd_alloc_ahash("__intel_sha512-mb",
CRYPTO_ALG_INTERNAL,
CRYPTO_ALG_INTERNAL);
if (IS_ERR(mcryptd_tfm))
return PTR_ERR(mcryptd_tfm);
mctx = crypto_ahash_ctx(&mcryptd_tfm->base);
mctx->alg_state = &sha512_mb_alg_state;
ctx->mcryptd_tfm = mcryptd_tfm;
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct ahash_request) +
crypto_ahash_reqsize(&mcryptd_tfm->base));
return 0;
}
static void sha512_mb_async_exit_tfm(struct crypto_tfm *tfm)
{
struct sha512_mb_ctx *ctx = crypto_tfm_ctx(tfm);
mcryptd_free_ahash(ctx->mcryptd_tfm);
}
static int sha512_mb_areq_init_tfm(struct crypto_tfm *tfm)
{
crypto_ahash_set_reqsize(__crypto_ahash_cast(tfm),
sizeof(struct ahash_request) +
sizeof(struct sha512_hash_ctx));
return 0;
}
static void sha512_mb_areq_exit_tfm(struct crypto_tfm *tfm)
{
struct sha512_mb_ctx *ctx = crypto_tfm_ctx(tfm);
mcryptd_free_ahash(ctx->mcryptd_tfm);
}
static int sha512_mb_async_init(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_init(mcryptd_req);
}
static int sha512_mb_async_update(struct ahash_request *req)
{
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_update(mcryptd_req);
}
static int sha512_mb_async_finup(struct ahash_request *req)
{
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_finup(mcryptd_req);
}
static int sha512_mb_async_final(struct ahash_request *req)
{
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_final(mcryptd_req);
}
static int sha512_mb_async_digest(struct ahash_request *req)
{
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_digest(mcryptd_req);
}
static int sha512_mb_async_export(struct ahash_request *req, void *out)
{
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
return crypto_ahash_export(mcryptd_req, out);
}
static int sha512_mb_async_import(struct ahash_request *req, const void *in)
{
struct ahash_request *mcryptd_req = ahash_request_ctx(req);
struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
struct sha512_mb_ctx *ctx = crypto_ahash_ctx(tfm);
struct mcryptd_ahash *mcryptd_tfm = ctx->mcryptd_tfm;
struct crypto_ahash *child = mcryptd_ahash_child(mcryptd_tfm);
struct mcryptd_hash_request_ctx *rctx;
struct ahash_request *areq;
memcpy(mcryptd_req, req, sizeof(*req));
ahash_request_set_tfm(mcryptd_req, &mcryptd_tfm->base);
rctx = ahash_request_ctx(mcryptd_req);
areq = &rctx->areq;
ahash_request_set_tfm(areq, child);
ahash_request_set_callback(areq, CRYPTO_TFM_REQ_MAY_SLEEP,
rctx->complete, req);
return crypto_ahash_import(mcryptd_req, in);
}
static unsigned long sha512_mb_flusher(struct mcryptd_alg_cstate *cstate)
{
struct mcryptd_hash_request_ctx *rctx;
unsigned long cur_time;
unsigned long next_flush = 0;
struct sha512_hash_ctx *sha_ctx;
cur_time = jiffies;
while (!list_empty(&cstate->work_list)) {
rctx = list_entry(cstate->work_list.next,
struct mcryptd_hash_request_ctx, waiter);
if time_before(cur_time, rctx->tag.expire)
break;
kernel_fpu_begin();
sha_ctx = (struct sha512_hash_ctx *)
sha512_ctx_mgr_flush(cstate->mgr);
kernel_fpu_end();
if (!sha_ctx) {
pr_err("sha512_mb error: nothing got flushed for"
" non-empty list\n");
break;
}
rctx = cast_hash_to_mcryptd_ctx(sha_ctx);
sha_finish_walk(&rctx, cstate, true);
sha_complete_job(rctx, cstate, 0);
}
if (!list_empty(&cstate->work_list)) {
rctx = list_entry(cstate->work_list.next,
struct mcryptd_hash_request_ctx, waiter);
next_flush = rctx->tag.expire;
mcryptd_arm_flusher(cstate, get_delay(next_flush));
}
return next_flush;
}
static int __init sha512_mb_mod_init(void)
{
int cpu;
int err;
struct mcryptd_alg_cstate *cpu_state;
if (!boot_cpu_has(X86_FEATURE_AVX2) ||
!boot_cpu_has(X86_FEATURE_BMI2))
return -ENODEV;
sha512_mb_alg_state.alg_cstate =
alloc_percpu(struct mcryptd_alg_cstate);
sha512_job_mgr_init = sha512_mb_mgr_init_avx2;
sha512_job_mgr_submit = sha512_mb_mgr_submit_avx2;
sha512_job_mgr_flush = sha512_mb_mgr_flush_avx2;
sha512_job_mgr_get_comp_job = sha512_mb_mgr_get_comp_job_avx2;
if (!sha512_mb_alg_state.alg_cstate)
return -ENOMEM;
for_each_possible_cpu(cpu) {
cpu_state = per_cpu_ptr(sha512_mb_alg_state.alg_cstate, cpu);
cpu_state->next_flush = 0;
cpu_state->next_seq_num = 0;
cpu_state->flusher_engaged = false;
INIT_DELAYED_WORK(&cpu_state->flush, mcryptd_flusher);
cpu_state->cpu = cpu;
cpu_state->alg_state = &sha512_mb_alg_state;
cpu_state->mgr = kzalloc(sizeof(struct sha512_ctx_mgr),
GFP_KERNEL);
if (!cpu_state->mgr)
goto err2;
sha512_ctx_mgr_init(cpu_state->mgr);
INIT_LIST_HEAD(&cpu_state->work_list);
spin_lock_init(&cpu_state->work_lock);
}
sha512_mb_alg_state.flusher = &sha512_mb_flusher;
err = crypto_register_ahash(&sha512_mb_areq_alg);
if (err)
goto err2;
err = crypto_register_ahash(&sha512_mb_async_alg);
if (err)
goto err1;
return 0;
err1:
crypto_unregister_ahash(&sha512_mb_areq_alg);
err2:
for_each_possible_cpu(cpu) {
cpu_state = per_cpu_ptr(sha512_mb_alg_state.alg_cstate, cpu);
kfree(cpu_state->mgr);
}
free_percpu(sha512_mb_alg_state.alg_cstate);
return -ENODEV;
}
static void __exit sha512_mb_mod_fini(void)
{
int cpu;
struct mcryptd_alg_cstate *cpu_state;
crypto_unregister_ahash(&sha512_mb_async_alg);
crypto_unregister_ahash(&sha512_mb_areq_alg);
for_each_possible_cpu(cpu) {
cpu_state = per_cpu_ptr(sha512_mb_alg_state.alg_cstate, cpu);
kfree(cpu_state->mgr);
}
free_percpu(sha512_mb_alg_state.alg_cstate);
}
