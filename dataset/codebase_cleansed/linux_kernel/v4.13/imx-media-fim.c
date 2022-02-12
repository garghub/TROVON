static void update_fim_nominal(struct imx_media_fim *fim,
const struct v4l2_fract *fi)
{
if (fi->denominator == 0) {
dev_dbg(fim->sd->dev, "no frame interval, FIM disabled\n");
fim->enabled = false;
return;
}
fim->nominal = DIV_ROUND_CLOSEST_ULL(1000000ULL * (u64)fi->numerator,
fi->denominator);
dev_dbg(fim->sd->dev, "FI=%lu usec\n", fim->nominal);
}
static void reset_fim(struct imx_media_fim *fim, bool curval)
{
struct v4l2_ctrl *icap_chan = fim->icap_ctrl[FIM_CL_ICAP_CHANNEL];
struct v4l2_ctrl *icap_edge = fim->icap_ctrl[FIM_CL_ICAP_EDGE];
struct v4l2_ctrl *en = fim->ctrl[FIM_CL_ENABLE];
struct v4l2_ctrl *num = fim->ctrl[FIM_CL_NUM];
struct v4l2_ctrl *skip = fim->ctrl[FIM_CL_NUM_SKIP];
struct v4l2_ctrl *tol_min = fim->ctrl[FIM_CL_TOLERANCE_MIN];
struct v4l2_ctrl *tol_max = fim->ctrl[FIM_CL_TOLERANCE_MAX];
if (curval) {
fim->enabled = en->cur.val;
fim->icap_flags = icap_edge->cur.val;
fim->icap_channel = icap_chan->cur.val;
fim->num_avg = num->cur.val;
fim->num_skip = skip->cur.val;
fim->tolerance_min = tol_min->cur.val;
fim->tolerance_max = tol_max->cur.val;
} else {
fim->enabled = en->val;
fim->icap_flags = icap_edge->val;
fim->icap_channel = icap_chan->val;
fim->num_avg = num->val;
fim->num_skip = skip->val;
fim->tolerance_min = tol_min->val;
fim->tolerance_max = tol_max->val;
}
if (fim->tolerance_max <= fim->tolerance_min)
fim->tolerance_max = 0;
if (!icap_enabled(fim))
fim->num_skip = max_t(int, fim->num_skip, 1);
fim->counter = -fim->num_skip;
fim->sum = 0;
}
static void send_fim_event(struct imx_media_fim *fim, unsigned long error)
{
static const struct v4l2_event ev = {
.type = V4L2_EVENT_IMX_FRAME_INTERVAL_ERROR,
};
v4l2_subdev_notify_event(fim->sd, &ev);
}
static void frame_interval_monitor(struct imx_media_fim *fim,
struct timespec *ts)
{
unsigned long interval, error, error_avg;
bool send_event = false;
struct timespec diff;
if (!fim->enabled || ++fim->counter <= 0)
goto out_update_ts;
diff = timespec_sub(*ts, fim->last_ts);
interval = diff.tv_sec * 1000 * 1000 + diff.tv_nsec / 1000;
error = abs(interval - fim->nominal);
if (fim->tolerance_max && error >= fim->tolerance_max) {
dev_dbg(fim->sd->dev,
"FIM: %lu ignored, out of tolerance bounds\n",
error);
fim->counter--;
goto out_update_ts;
}
fim->sum += error;
if (fim->counter == fim->num_avg) {
error_avg = DIV_ROUND_CLOSEST(fim->sum, fim->num_avg);
if (error_avg > fim->tolerance_min)
send_event = true;
dev_dbg(fim->sd->dev, "FIM: error: %lu usec%s\n",
error_avg, send_event ? " (!!!)" : "");
fim->counter = 0;
fim->sum = 0;
}
out_update_ts:
fim->last_ts = *ts;
if (send_event)
send_fim_event(fim, error_avg);
}
static void fim_input_capture_handler(int channel, void *dev_id,
struct timespec *ts)
{
struct imx_media_fim *fim = dev_id;
unsigned long flags;
spin_lock_irqsave(&fim->lock, flags);
frame_interval_monitor(fim, ts);
if (!completion_done(&fim->icap_first_event))
complete(&fim->icap_first_event);
spin_unlock_irqrestore(&fim->lock, flags);
}
static int fim_request_input_capture(struct imx_media_fim *fim)
{
init_completion(&fim->icap_first_event);
return mxc_request_input_capture(fim->icap_channel,
fim_input_capture_handler,
fim->icap_flags, fim);
}
static void fim_free_input_capture(struct imx_media_fim *fim)
{
mxc_free_input_capture(fim->icap_channel, fim);
}
static int fim_request_input_capture(struct imx_media_fim *fim)
{
return 0;
}
static void fim_free_input_capture(struct imx_media_fim *fim)
{
}
static void fim_acquire_first_ts(struct imx_media_fim *fim)
{
unsigned long ret;
if (!fim->enabled || fim->num_skip > 0)
return;
ret = wait_for_completion_timeout(
&fim->icap_first_event,
msecs_to_jiffies(IMX_MEDIA_EOF_TIMEOUT));
if (ret == 0)
v4l2_warn(fim->sd, "wait first icap event timeout\n");
}
static int fim_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct imx_media_fim *fim = container_of(ctrl->handler,
struct imx_media_fim,
ctrl_handler);
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&fim->lock, flags);
switch (ctrl->id) {
case V4L2_CID_IMX_FIM_ENABLE:
break;
case V4L2_CID_IMX_FIM_ICAP_EDGE:
if (fim->stream_on)
ret = -EBUSY;
break;
default:
ret = -EINVAL;
}
if (!ret)
reset_fim(fim, false);
spin_unlock_irqrestore(&fim->lock, flags);
return ret;
}
static int init_fim_controls(struct imx_media_fim *fim)
{
struct v4l2_ctrl_handler *hdlr = &fim->ctrl_handler;
int i, ret;
v4l2_ctrl_handler_init(hdlr, FIM_NUM_CONTROLS + FIM_NUM_ICAP_CONTROLS);
for (i = 0; i < FIM_NUM_CONTROLS; i++)
fim->ctrl[i] = v4l2_ctrl_new_custom(hdlr,
&fim_ctrl[i],
NULL);
for (i = 0; i < FIM_NUM_ICAP_CONTROLS; i++)
fim->icap_ctrl[i] = v4l2_ctrl_new_custom(hdlr,
&fim_icap_ctrl[i],
NULL);
if (hdlr->error) {
ret = hdlr->error;
goto err_free;
}
v4l2_ctrl_cluster(FIM_NUM_CONTROLS, fim->ctrl);
v4l2_ctrl_cluster(FIM_NUM_ICAP_CONTROLS, fim->icap_ctrl);
return 0;
err_free:
v4l2_ctrl_handler_free(hdlr);
return ret;
}
void imx_media_fim_eof_monitor(struct imx_media_fim *fim, struct timespec *ts)
{
unsigned long flags;
spin_lock_irqsave(&fim->lock, flags);
if (!icap_enabled(fim))
frame_interval_monitor(fim, ts);
spin_unlock_irqrestore(&fim->lock, flags);
}
int imx_media_fim_set_stream(struct imx_media_fim *fim,
const struct v4l2_fract *fi,
bool on)
{
unsigned long flags;
int ret = 0;
v4l2_ctrl_lock(fim->ctrl[FIM_CL_ENABLE]);
if (fim->stream_on == on)
goto out;
if (on) {
spin_lock_irqsave(&fim->lock, flags);
reset_fim(fim, true);
update_fim_nominal(fim, fi);
spin_unlock_irqrestore(&fim->lock, flags);
if (icap_enabled(fim)) {
ret = fim_request_input_capture(fim);
if (ret)
goto out;
fim_acquire_first_ts(fim);
}
} else {
if (icap_enabled(fim))
fim_free_input_capture(fim);
}
fim->stream_on = on;
out:
v4l2_ctrl_unlock(fim->ctrl[FIM_CL_ENABLE]);
return ret;
}
int imx_media_fim_add_controls(struct imx_media_fim *fim)
{
return v4l2_ctrl_add_handler(fim->sd->ctrl_handler,
&fim->ctrl_handler, NULL);
}
struct imx_media_fim *imx_media_fim_init(struct v4l2_subdev *sd)
{
struct imx_media_fim *fim;
int ret;
fim = devm_kzalloc(sd->dev, sizeof(*fim), GFP_KERNEL);
if (!fim)
return ERR_PTR(-ENOMEM);
fim->md = dev_get_drvdata(sd->v4l2_dev->dev);
fim->sd = sd;
spin_lock_init(&fim->lock);
ret = init_fim_controls(fim);
if (ret)
return ERR_PTR(ret);
return fim;
}
void imx_media_fim_free(struct imx_media_fim *fim)
{
v4l2_ctrl_handler_free(&fim->ctrl_handler);
}
