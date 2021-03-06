static void optee_cq_wait_init(struct optee_call_queue *cq,
struct optee_call_waiter *w)
{
mutex_lock(&cq->mutex);
init_completion(&w->c);
list_add_tail(&w->list_node, &cq->waiters);
mutex_unlock(&cq->mutex);
}
static void optee_cq_wait_for_completion(struct optee_call_queue *cq,
struct optee_call_waiter *w)
{
wait_for_completion(&w->c);
mutex_lock(&cq->mutex);
list_del(&w->list_node);
reinit_completion(&w->c);
list_add_tail(&w->list_node, &cq->waiters);
mutex_unlock(&cq->mutex);
}
static void optee_cq_complete_one(struct optee_call_queue *cq)
{
struct optee_call_waiter *w;
list_for_each_entry(w, &cq->waiters, list_node) {
if (!completion_done(&w->c)) {
complete(&w->c);
break;
}
}
}
static void optee_cq_wait_final(struct optee_call_queue *cq,
struct optee_call_waiter *w)
{
mutex_lock(&cq->mutex);
list_del(&w->list_node);
optee_cq_complete_one(cq);
if (completion_done(&w->c))
optee_cq_complete_one(cq);
mutex_unlock(&cq->mutex);
}
static struct optee_session *find_session(struct optee_context_data *ctxdata,
u32 session_id)
{
struct optee_session *sess;
list_for_each_entry(sess, &ctxdata->sess_list, list_node)
if (sess->session_id == session_id)
return sess;
return NULL;
}
u32 optee_do_call_with_arg(struct tee_context *ctx, phys_addr_t parg)
{
struct optee *optee = tee_get_drvdata(ctx->teedev);
struct optee_call_waiter w;
struct optee_rpc_param param = { };
u32 ret;
param.a0 = OPTEE_SMC_CALL_WITH_ARG;
reg_pair_from_64(&param.a1, &param.a2, parg);
optee_cq_wait_init(&optee->call_queue, &w);
while (true) {
struct arm_smccc_res res;
optee->invoke_fn(param.a0, param.a1, param.a2, param.a3,
param.a4, param.a5, param.a6, param.a7,
&res);
if (res.a0 == OPTEE_SMC_RETURN_ETHREAD_LIMIT) {
optee_cq_wait_for_completion(&optee->call_queue, &w);
} else if (OPTEE_SMC_RETURN_IS_RPC(res.a0)) {
param.a0 = res.a0;
param.a1 = res.a1;
param.a2 = res.a2;
param.a3 = res.a3;
optee_handle_rpc(ctx, &param);
} else {
ret = res.a0;
break;
}
}
optee_cq_wait_final(&optee->call_queue, &w);
return ret;
}
static struct tee_shm *get_msg_arg(struct tee_context *ctx, size_t num_params,
struct optee_msg_arg **msg_arg,
phys_addr_t *msg_parg)
{
int rc;
struct tee_shm *shm;
struct optee_msg_arg *ma;
shm = tee_shm_alloc(ctx, OPTEE_MSG_GET_ARG_SIZE(num_params),
TEE_SHM_MAPPED);
if (IS_ERR(shm))
return shm;
ma = tee_shm_get_va(shm, 0);
if (IS_ERR(ma)) {
rc = PTR_ERR(ma);
goto out;
}
rc = tee_shm_get_pa(shm, 0, msg_parg);
if (rc)
goto out;
memset(ma, 0, OPTEE_MSG_GET_ARG_SIZE(num_params));
ma->num_params = num_params;
*msg_arg = ma;
out:
if (rc) {
tee_shm_free(shm);
return ERR_PTR(rc);
}
return shm;
}
int optee_open_session(struct tee_context *ctx,
struct tee_ioctl_open_session_arg *arg,
struct tee_param *param)
{
struct optee_context_data *ctxdata = ctx->data;
int rc;
struct tee_shm *shm;
struct optee_msg_arg *msg_arg;
phys_addr_t msg_parg;
struct optee_session *sess = NULL;
shm = get_msg_arg(ctx, arg->num_params + 2, &msg_arg, &msg_parg);
if (IS_ERR(shm))
return PTR_ERR(shm);
msg_arg->cmd = OPTEE_MSG_CMD_OPEN_SESSION;
msg_arg->cancel_id = arg->cancel_id;
msg_arg->params[0].attr = OPTEE_MSG_ATTR_TYPE_VALUE_INPUT |
OPTEE_MSG_ATTR_META;
msg_arg->params[1].attr = OPTEE_MSG_ATTR_TYPE_VALUE_INPUT |
OPTEE_MSG_ATTR_META;
memcpy(&msg_arg->params[0].u.value, arg->uuid, sizeof(arg->uuid));
memcpy(&msg_arg->params[1].u.value, arg->uuid, sizeof(arg->clnt_uuid));
msg_arg->params[1].u.value.c = arg->clnt_login;
rc = optee_to_msg_param(msg_arg->params + 2, arg->num_params, param);
if (rc)
goto out;
sess = kzalloc(sizeof(*sess), GFP_KERNEL);
if (!sess) {
rc = -ENOMEM;
goto out;
}
if (optee_do_call_with_arg(ctx, msg_parg)) {
msg_arg->ret = TEEC_ERROR_COMMUNICATION;
msg_arg->ret_origin = TEEC_ORIGIN_COMMS;
}
if (msg_arg->ret == TEEC_SUCCESS) {
sess->session_id = msg_arg->session;
mutex_lock(&ctxdata->mutex);
list_add(&sess->list_node, &ctxdata->sess_list);
mutex_unlock(&ctxdata->mutex);
} else {
kfree(sess);
}
if (optee_from_msg_param(param, arg->num_params, msg_arg->params + 2)) {
arg->ret = TEEC_ERROR_COMMUNICATION;
arg->ret_origin = TEEC_ORIGIN_COMMS;
optee_close_session(ctx, msg_arg->session);
} else {
arg->session = msg_arg->session;
arg->ret = msg_arg->ret;
arg->ret_origin = msg_arg->ret_origin;
}
out:
tee_shm_free(shm);
return rc;
}
int optee_close_session(struct tee_context *ctx, u32 session)
{
struct optee_context_data *ctxdata = ctx->data;
struct tee_shm *shm;
struct optee_msg_arg *msg_arg;
phys_addr_t msg_parg;
struct optee_session *sess;
mutex_lock(&ctxdata->mutex);
sess = find_session(ctxdata, session);
if (sess)
list_del(&sess->list_node);
mutex_unlock(&ctxdata->mutex);
if (!sess)
return -EINVAL;
kfree(sess);
shm = get_msg_arg(ctx, 0, &msg_arg, &msg_parg);
if (IS_ERR(shm))
return PTR_ERR(shm);
msg_arg->cmd = OPTEE_MSG_CMD_CLOSE_SESSION;
msg_arg->session = session;
optee_do_call_with_arg(ctx, msg_parg);
tee_shm_free(shm);
return 0;
}
int optee_invoke_func(struct tee_context *ctx, struct tee_ioctl_invoke_arg *arg,
struct tee_param *param)
{
struct optee_context_data *ctxdata = ctx->data;
struct tee_shm *shm;
struct optee_msg_arg *msg_arg;
phys_addr_t msg_parg;
struct optee_session *sess;
int rc;
mutex_lock(&ctxdata->mutex);
sess = find_session(ctxdata, arg->session);
mutex_unlock(&ctxdata->mutex);
if (!sess)
return -EINVAL;
shm = get_msg_arg(ctx, arg->num_params, &msg_arg, &msg_parg);
if (IS_ERR(shm))
return PTR_ERR(shm);
msg_arg->cmd = OPTEE_MSG_CMD_INVOKE_COMMAND;
msg_arg->func = arg->func;
msg_arg->session = arg->session;
msg_arg->cancel_id = arg->cancel_id;
rc = optee_to_msg_param(msg_arg->params, arg->num_params, param);
if (rc)
goto out;
if (optee_do_call_with_arg(ctx, msg_parg)) {
msg_arg->ret = TEEC_ERROR_COMMUNICATION;
msg_arg->ret_origin = TEEC_ORIGIN_COMMS;
}
if (optee_from_msg_param(param, arg->num_params, msg_arg->params)) {
msg_arg->ret = TEEC_ERROR_COMMUNICATION;
msg_arg->ret_origin = TEEC_ORIGIN_COMMS;
}
arg->ret = msg_arg->ret;
arg->ret_origin = msg_arg->ret_origin;
out:
tee_shm_free(shm);
return rc;
}
int optee_cancel_req(struct tee_context *ctx, u32 cancel_id, u32 session)
{
struct optee_context_data *ctxdata = ctx->data;
struct tee_shm *shm;
struct optee_msg_arg *msg_arg;
phys_addr_t msg_parg;
struct optee_session *sess;
mutex_lock(&ctxdata->mutex);
sess = find_session(ctxdata, session);
mutex_unlock(&ctxdata->mutex);
if (!sess)
return -EINVAL;
shm = get_msg_arg(ctx, 0, &msg_arg, &msg_parg);
if (IS_ERR(shm))
return PTR_ERR(shm);
msg_arg->cmd = OPTEE_MSG_CMD_CANCEL;
msg_arg->session = session;
msg_arg->cancel_id = cancel_id;
optee_do_call_with_arg(ctx, msg_parg);
tee_shm_free(shm);
return 0;
}
void optee_enable_shm_cache(struct optee *optee)
{
struct optee_call_waiter w;
optee_cq_wait_init(&optee->call_queue, &w);
while (true) {
struct arm_smccc_res res;
optee->invoke_fn(OPTEE_SMC_ENABLE_SHM_CACHE, 0, 0, 0, 0, 0, 0,
0, &res);
if (res.a0 == OPTEE_SMC_RETURN_OK)
break;
optee_cq_wait_for_completion(&optee->call_queue, &w);
}
optee_cq_wait_final(&optee->call_queue, &w);
}
void optee_disable_shm_cache(struct optee *optee)
{
struct optee_call_waiter w;
optee_cq_wait_init(&optee->call_queue, &w);
while (true) {
union {
struct arm_smccc_res smccc;
struct optee_smc_disable_shm_cache_result result;
} res;
optee->invoke_fn(OPTEE_SMC_DISABLE_SHM_CACHE, 0, 0, 0, 0, 0, 0,
0, &res.smccc);
if (res.result.status == OPTEE_SMC_RETURN_ENOTAVAIL)
break;
if (res.result.status == OPTEE_SMC_RETURN_OK) {
struct tee_shm *shm;
shm = reg_pair_to_ptr(res.result.shm_upper32,
res.result.shm_lower32);
tee_shm_free(shm);
} else {
optee_cq_wait_for_completion(&optee->call_queue, &w);
}
}
optee_cq_wait_final(&optee->call_queue, &w);
}
