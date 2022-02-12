void optee_supp_init(struct optee_supp *supp)
{
memset(supp, 0, sizeof(*supp));
mutex_init(&supp->ctx_mutex);
mutex_init(&supp->thrd_mutex);
mutex_init(&supp->supp_mutex);
init_completion(&supp->data_to_supp);
init_completion(&supp->data_from_supp);
}
void optee_supp_uninit(struct optee_supp *supp)
{
mutex_destroy(&supp->ctx_mutex);
mutex_destroy(&supp->thrd_mutex);
mutex_destroy(&supp->supp_mutex);
}
u32 optee_supp_thrd_req(struct tee_context *ctx, u32 func, size_t num_params,
struct tee_param *param)
{
bool interruptable;
struct optee *optee = tee_get_drvdata(ctx->teedev);
struct optee_supp *supp = &optee->supp;
u32 ret;
while (mutex_lock_interruptible(&supp->thrd_mutex)) {
mutex_lock(&supp->ctx_mutex);
interruptable = !supp->ctx;
mutex_unlock(&supp->ctx_mutex);
if (interruptable)
return TEEC_ERROR_COMMUNICATION;
}
supp->func = func;
supp->num_params = num_params;
supp->param = param;
supp->req_posted = true;
complete(&supp->data_to_supp);
while (wait_for_completion_interruptible(&supp->data_from_supp)) {
mutex_lock(&supp->ctx_mutex);
interruptable = !supp->ctx;
if (interruptable) {
supp->ret = TEEC_ERROR_COMMUNICATION;
init_completion(&supp->data_to_supp);
}
mutex_unlock(&supp->ctx_mutex);
if (interruptable)
break;
}
ret = supp->ret;
supp->param = NULL;
supp->req_posted = false;
mutex_unlock(&supp->thrd_mutex);
return ret;
}
int optee_supp_recv(struct tee_context *ctx, u32 *func, u32 *num_params,
struct tee_param *param)
{
struct tee_device *teedev = ctx->teedev;
struct optee *optee = tee_get_drvdata(teedev);
struct optee_supp *supp = &optee->supp;
int rc;
mutex_lock(&supp->supp_mutex);
if (supp->supp_next_send) {
if (supp->req_posted) {
supp->ret = TEEC_ERROR_COMMUNICATION;
supp->supp_next_send = false;
complete(&supp->data_from_supp);
}
}
if (wait_for_completion_interruptible(&supp->data_to_supp)) {
rc = -ERESTARTSYS;
goto out;
}
if (*num_params < supp->num_params) {
supp->ret = TEEC_ERROR_COMMUNICATION;
rc = -EINVAL;
complete(&supp->data_from_supp);
goto out;
}
*func = supp->func;
*num_params = supp->num_params;
memcpy(param, supp->param,
sizeof(struct tee_param) * supp->num_params);
supp->supp_next_send = true;
rc = 0;
out:
mutex_unlock(&supp->supp_mutex);
return rc;
}
int optee_supp_send(struct tee_context *ctx, u32 ret, u32 num_params,
struct tee_param *param)
{
struct tee_device *teedev = ctx->teedev;
struct optee *optee = tee_get_drvdata(teedev);
struct optee_supp *supp = &optee->supp;
size_t n;
int rc = 0;
mutex_lock(&supp->supp_mutex);
if (!supp->supp_next_send) {
rc = -ENOENT;
goto out;
}
if (num_params != supp->num_params) {
rc = -EINVAL;
goto out;
}
for (n = 0; n < num_params; n++) {
struct tee_param *p = supp->param + n;
switch (p->attr) {
case TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_OUTPUT:
case TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_INOUT:
p->u.value.a = param[n].u.value.a;
p->u.value.b = param[n].u.value.b;
p->u.value.c = param[n].u.value.c;
break;
case TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT:
case TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INOUT:
p->u.memref.size = param[n].u.memref.size;
break;
default:
break;
}
}
supp->ret = ret;
supp->supp_next_send = false;
complete(&supp->data_from_supp);
out:
mutex_unlock(&supp->supp_mutex);
return rc;
}
