int mtk_vcodec_wait_for_done_ctx(struct mtk_vcodec_ctx *ctx, int command,
unsigned int timeout_ms)
{
wait_queue_head_t *waitqueue;
long timeout_jiff, ret;
int status = 0;
waitqueue = (wait_queue_head_t *)&ctx->queue;
timeout_jiff = msecs_to_jiffies(timeout_ms);
ret = wait_event_interruptible_timeout(*waitqueue,
(ctx->int_cond &&
(ctx->int_type == command)),
timeout_jiff);
if (!ret) {
status = -1;
mtk_v4l2_err("[%d] cmd=%d, ctx->type=%d, wait_event_interruptible_timeout time=%ums out %d %d!",
ctx->id, ctx->type, command, timeout_ms,
ctx->int_cond, ctx->int_type);
} else if (-ERESTARTSYS == ret) {
mtk_v4l2_err("[%d] cmd=%d, ctx->type=%d, wait_event_interruptible_timeout interrupted by a signal %d %d",
ctx->id, ctx->type, command, ctx->int_cond,
ctx->int_type);
status = -1;
}
ctx->int_cond = 0;
ctx->int_type = 0;
return status;
}
