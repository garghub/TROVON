int uf_start_thread(unifi_priv_t *priv,
struct uf_thread *thread, int (*func)(void *))
{
if (thread->thread_task != NULL) {
unifi_error(priv, "%s thread already started\n", thread->name);
return 0;
}
thread->thread_task = kthread_run(func, priv, "%s", thread->name);
if (IS_ERR(thread->thread_task))
return PTR_ERR(thread->thread_task);
if (bh_priority != -1) {
if (bh_priority >= 0 && bh_priority <= MAX_RT_PRIO) {
struct sched_param param;
priv->bh_thread.prio = bh_priority;
unifi_trace(priv, UDBG1,
"%s thread (RT) priority = %d\n",
thread->name, bh_priority);
param.sched_priority = bh_priority;
sched_setscheduler(thread->thread_task,
SCHED_FIFO, &param);
} else if (bh_priority > MAX_RT_PRIO &&
bh_priority <= MAX_PRIO) {
priv->bh_thread.prio = bh_priority;
unifi_trace(priv, UDBG1, "%s thread priority = %d\n",
thread->name,
PRIO_TO_NICE(bh_priority));
set_user_nice(thread->thread_task,
PRIO_TO_NICE(bh_priority));
} else {
priv->bh_thread.prio = DEFAULT_PRIO;
unifi_warning(priv,
"%s thread unsupported (%d) priority\n",
thread->name, bh_priority);
}
} else
priv->bh_thread.prio = DEFAULT_PRIO;
unifi_trace(priv, UDBG2, "Started %s thread\n", thread->name);
return 0;
}
void uf_stop_thread(unifi_priv_t *priv, struct uf_thread *thread)
{
if (!thread->thread_task) {
unifi_notice(priv, "%s thread is already stopped\n",
thread->name);
return;
}
unifi_trace(priv, UDBG2, "Stopping %s thread\n", thread->name);
kthread_stop(thread->thread_task);
thread->thread_task = NULL;
}
void
uf_wait_for_thread_to_stop(unifi_priv_t *priv, struct uf_thread *thread)
{
unifi_trace(priv, UDBG2, "%s waiting for the stop signal.\n",
thread->name);
set_current_state(TASK_INTERRUPTIBLE);
if (!kthread_should_stop()) {
unifi_trace(priv, UDBG2, "%s schedule....\n", thread->name);
schedule();
}
thread->thread_task = NULL;
unifi_trace(priv, UDBG2, "%s exiting....\n", thread->name);
}
static void
handle_bh_error(unifi_priv_t *priv)
{
netInterface_priv_t *interfacePriv;
u8 conf_param = CONFIG_IND_ERROR;
u8 interfaceTag;
priv->bh_thread.block_thread = 1;
priv->init_progress = UNIFI_INIT_NONE;
for (interfaceTag = 0;
interfaceTag < CSR_WIFI_NUM_INTERFACES; interfaceTag++) {
interfacePriv = priv->interfacePriv[interfaceTag];
if (interfacePriv->netdev_registered)
netif_carrier_off(priv->netdev[interfaceTag]);
}
#ifdef CSR_NATIVE_LINUX
uf_abort_mlme(priv);
flush_workqueue(priv->unifi_workqueue);
#endif
unifi_error(priv,
"handle_bh_error: fatal error is reported to the SME.\n");
ul_log_config_ind(priv, &conf_param, sizeof(u8));
}
static int bh_thread_function(void *arg)
{
unifi_priv_t *priv = (unifi_priv_t *)arg;
CsrResult csrResult;
long ret;
u32 timeout, t;
struct uf_thread *this_thread;
unifi_trace(priv, UDBG2, "bh_thread_function starting\n");
this_thread = &priv->bh_thread;
t = timeout = 0;
while (!kthread_should_stop()) {
unifi_trace(priv, UDBG3, "bh_thread goes to sleep.\n");
if (timeout > 0) {
t = msecs_to_jiffies(timeout);
ret = wait_event_interruptible_timeout(this_thread->wakeup_q,
(this_thread->wakeup_flag && !this_thread->block_thread) ||
kthread_should_stop(),
t);
timeout = (ret > 0) ? jiffies_to_msecs(ret) : 0;
} else {
ret = wait_event_interruptible(this_thread->wakeup_q,
(this_thread->wakeup_flag && !this_thread->block_thread) ||
kthread_should_stop());
}
if (kthread_should_stop()) {
unifi_trace(priv, UDBG2, "bh_thread: signalled to exit\n");
break;
}
if (ret < 0) {
unifi_notice(priv,
"bh_thread: wait_event returned %d, thread will exit\n",
ret);
uf_wait_for_thread_to_stop(priv, this_thread);
break;
}
this_thread->wakeup_flag = 0;
unifi_trace(priv, UDBG3, "bh_thread calls unifi_bh().\n");
CsrSdioClaim(priv->sdio);
csrResult = unifi_bh(priv->card, &timeout);
if(csrResult != CSR_RESULT_SUCCESS) {
if (csrResult == CSR_WIFI_HIP_RESULT_NO_DEVICE) {
CsrSdioRelease(priv->sdio);
uf_wait_for_thread_to_stop(priv, this_thread);
break;
}
handle_bh_error(priv);
}
CsrSdioRelease(priv->sdio);
}
unifi_trace(priv, UDBG2, "bh_thread exiting....\n");
return 0;
}
int
uf_init_bh(unifi_priv_t *priv)
{
int r;
priv->io_aborted = 0;
r = uf_start_thread(priv, &priv->bh_thread, bh_thread_function);
if (r) {
unifi_error(priv,
"uf_init_bh: failed to start the BH thread.\n");
return r;
}
r = csr_sdio_linux_install_irq(priv->sdio);
if (r) {
unifi_error(priv,
"uf_init_bh: failed to install the IRQ.\n");
uf_stop_thread(priv, &priv->bh_thread);
}
return r;
}
CsrResult unifi_run_bh(void *ospriv)
{
unifi_priv_t *priv = ospriv;
if (priv->bh_thread.block_thread == 1) {
unifi_trace(priv, UDBG3, "unifi_run_bh: discard message.\n");
return CSR_RESULT_FAILURE;
}
priv->bh_thread.wakeup_flag = 1;
wake_up_interruptible(&priv->bh_thread.wakeup_q);
return CSR_RESULT_SUCCESS;
}
