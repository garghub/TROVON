static void pps_add_offset(struct pps_ktime *ts, struct pps_ktime *offset)
{
ts->nsec += offset->nsec;
while (ts->nsec >= NSEC_PER_SEC) {
ts->nsec -= NSEC_PER_SEC;
ts->sec++;
}
while (ts->nsec < 0) {
ts->nsec += NSEC_PER_SEC;
ts->sec--;
}
ts->sec += offset->sec;
}
struct pps_device *pps_register_source(struct pps_source_info *info,
int default_params)
{
struct pps_device *pps;
int err;
if ((info->mode & default_params) != default_params) {
pr_err("%s: unsupported default parameters\n",
info->name);
err = -EINVAL;
goto pps_register_source_exit;
}
if ((info->mode & (PPS_ECHOASSERT | PPS_ECHOCLEAR)) != 0 &&
info->echo == NULL) {
pr_err("%s: echo function is not defined\n",
info->name);
err = -EINVAL;
goto pps_register_source_exit;
}
if ((info->mode & (PPS_TSFMT_TSPEC | PPS_TSFMT_NTPFP)) == 0) {
pr_err("%s: unspecified time format\n",
info->name);
err = -EINVAL;
goto pps_register_source_exit;
}
pps = kzalloc(sizeof(struct pps_device), GFP_KERNEL);
if (pps == NULL) {
err = -ENOMEM;
goto pps_register_source_exit;
}
pps->params.api_version = PPS_API_VERS;
pps->params.mode = default_params;
pps->info = *info;
init_waitqueue_head(&pps->queue);
spin_lock_init(&pps->lock);
err = pps_register_cdev(pps);
if (err < 0) {
pr_err("%s: unable to create char device\n",
info->name);
goto kfree_pps;
}
dev_info(pps->dev, "new PPS source %s\n", info->name);
return pps;
kfree_pps:
kfree(pps);
pps_register_source_exit:
pr_err("%s: unable to register source\n", info->name);
return NULL;
}
void pps_unregister_source(struct pps_device *pps)
{
pps_kc_remove(pps);
pps_unregister_cdev(pps);
}
void pps_event(struct pps_device *pps, struct pps_event_time *ts, int event,
void *data)
{
unsigned long flags;
int captured = 0;
struct pps_ktime ts_real = { .sec = 0, .nsec = 0, .flags = 0 };
BUG_ON((event & (PPS_CAPTUREASSERT | PPS_CAPTURECLEAR)) == 0);
dev_dbg(pps->dev, "PPS event at %ld.%09ld\n",
ts->ts_real.tv_sec, ts->ts_real.tv_nsec);
timespec_to_pps_ktime(&ts_real, ts->ts_real);
spin_lock_irqsave(&pps->lock, flags);
if ((pps->params.mode & (PPS_ECHOASSERT | PPS_ECHOCLEAR)))
pps->info.echo(pps, event, data);
pps->current_mode = pps->params.mode;
if (event & pps->params.mode & PPS_CAPTUREASSERT) {
if (pps->params.mode & PPS_OFFSETASSERT)
pps_add_offset(&ts_real,
&pps->params.assert_off_tu);
pps->assert_tu = ts_real;
pps->assert_sequence++;
dev_dbg(pps->dev, "capture assert seq #%u\n",
pps->assert_sequence);
captured = ~0;
}
if (event & pps->params.mode & PPS_CAPTURECLEAR) {
if (pps->params.mode & PPS_OFFSETCLEAR)
pps_add_offset(&ts_real,
&pps->params.clear_off_tu);
pps->clear_tu = ts_real;
pps->clear_sequence++;
dev_dbg(pps->dev, "capture clear seq #%u\n",
pps->clear_sequence);
captured = ~0;
}
pps_kc_event(pps, ts, event);
if (captured) {
pps->last_ev++;
wake_up_interruptible_all(&pps->queue);
kill_fasync(&pps->async_queue, SIGIO, POLL_IN);
}
spin_unlock_irqrestore(&pps->lock, flags);
}
