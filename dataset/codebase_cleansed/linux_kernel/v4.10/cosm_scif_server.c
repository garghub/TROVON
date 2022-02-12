static void cosm_update_mic_status(struct cosm_device *cdev)
{
if (cdev->shutdown_status_int != MIC_NOP) {
cosm_set_shutdown_status(cdev, cdev->shutdown_status_int);
cdev->shutdown_status_int = MIC_NOP;
}
}
static void cosm_shutdown_status_int(struct cosm_device *cdev,
enum mic_status shutdown_status)
{
switch (shutdown_status) {
case MIC_HALTED:
case MIC_POWER_OFF:
case MIC_RESTART:
case MIC_CRASHED:
break;
default:
dev_err(&cdev->dev, "%s %d Unexpected shutdown_status %d\n",
__func__, __LINE__, shutdown_status);
return;
};
cdev->shutdown_status_int = shutdown_status;
cdev->heartbeat_watchdog_enable = false;
if (cdev->state != MIC_SHUTTING_DOWN)
cosm_set_state(cdev, MIC_SHUTTING_DOWN);
}
static void cosm_scif_recv(struct cosm_device *cdev)
{
struct cosm_msg msg;
int rc;
while (1) {
rc = scif_recv(cdev->epd, &msg, sizeof(msg), 0);
if (!rc) {
break;
} else if (rc < 0) {
dev_dbg(&cdev->dev, "%s: %d rc %d\n",
__func__, __LINE__, rc);
break;
}
dev_dbg(&cdev->dev, "%s: %d rc %d id 0x%llx\n",
__func__, __LINE__, rc, msg.id);
switch (msg.id) {
case COSM_MSG_SHUTDOWN_STATUS:
cosm_shutdown_status_int(cdev, msg.shutdown_status);
break;
case COSM_MSG_HEARTBEAT:
break;
default:
dev_err(&cdev->dev, "%s: %d unknown msg.id %lld\n",
__func__, __LINE__, msg.id);
break;
}
}
}
static void cosm_set_crashed(struct cosm_device *cdev)
{
dev_err(&cdev->dev, "node alive timeout\n");
cosm_shutdown_status_int(cdev, MIC_CRASHED);
cosm_update_mic_status(cdev);
}
static void cosm_send_time(struct cosm_device *cdev)
{
struct cosm_msg msg = { .id = COSM_MSG_SYNC_TIME };
int rc;
getnstimeofday64(&msg.timespec);
rc = scif_send(cdev->epd, &msg, sizeof(msg), SCIF_SEND_BLOCK);
if (rc < 0)
dev_err(&cdev->dev, "%s %d scif_send failed rc %d\n",
__func__, __LINE__, rc);
}
static void cosm_scif_close(struct cosm_device *cdev)
{
cosm_update_mic_status(cdev);
scif_close(cdev->epd);
cdev->epd = NULL;
dev_dbg(&cdev->dev, "%s %d\n", __func__, __LINE__);
}
static int cosm_set_online(struct cosm_device *cdev)
{
int rc = 0;
if (MIC_BOOTING == cdev->state || MIC_ONLINE == cdev->state) {
cdev->heartbeat_watchdog_enable = cdev->sysfs_heartbeat_enable;
cdev->epd = cdev->newepd;
if (cdev->state == MIC_BOOTING)
cosm_set_state(cdev, MIC_ONLINE);
cosm_send_time(cdev);
dev_dbg(&cdev->dev, "%s %d\n", __func__, __LINE__);
} else {
dev_warn(&cdev->dev, "%s %d not going online in state: %s\n",
__func__, __LINE__, cosm_state_string[cdev->state]);
rc = -EINVAL;
}
put_device(&cdev->dev);
return rc;
}
void cosm_scif_work(struct work_struct *work)
{
struct cosm_device *cdev = container_of(work, struct cosm_device,
scif_work);
struct scif_pollepd pollepd;
int rc;
mutex_lock(&cdev->cosm_mutex);
if (cosm_set_online(cdev))
goto exit;
while (1) {
pollepd.epd = cdev->epd;
pollepd.events = POLLIN;
mutex_unlock(&cdev->cosm_mutex);
rc = scif_poll(&pollepd, 1, COSM_HEARTBEAT_TIMEOUT_MSEC);
mutex_lock(&cdev->cosm_mutex);
if (rc < 0) {
dev_err(&cdev->dev, "%s %d scif_poll rc %d\n",
__func__, __LINE__, rc);
continue;
}
if (pollepd.revents & POLLIN)
cosm_scif_recv(cdev);
if (pollepd.revents & POLLHUP) {
cosm_scif_close(cdev);
break;
}
if (!rc && cdev->heartbeat_watchdog_enable)
cosm_set_crashed(cdev);
}
exit:
dev_dbg(&cdev->dev, "%s %d exiting\n", __func__, __LINE__);
mutex_unlock(&cdev->cosm_mutex);
}
static int cosm_scif_server(void *unused)
{
struct cosm_device *cdev;
scif_epd_t newepd;
struct scif_port_id port_id;
int rc;
allow_signal(SIGKILL);
while (!kthread_should_stop()) {
rc = scif_accept(listen_epd, &port_id, &newepd,
SCIF_ACCEPT_SYNC);
if (rc < 0) {
if (-ERESTARTSYS != rc)
pr_err("%s %d rc %d\n", __func__, __LINE__, rc);
continue;
}
cdev = cosm_find_cdev_by_id(port_id.node - 1);
if (!cdev)
continue;
cdev->newepd = newepd;
schedule_work(&cdev->scif_work);
}
pr_debug("%s %d Server thread stopped\n", __func__, __LINE__);
return 0;
}
static int cosm_scif_listen(void)
{
int rc;
listen_epd = scif_open();
if (!listen_epd) {
pr_err("%s %d scif_open failed\n", __func__, __LINE__);
return -ENOMEM;
}
rc = scif_bind(listen_epd, SCIF_COSM_LISTEN_PORT);
if (rc < 0) {
pr_err("%s %d scif_bind failed rc %d\n",
__func__, __LINE__, rc);
goto err;
}
rc = scif_listen(listen_epd, COSM_SCIF_BACKLOG);
if (rc < 0) {
pr_err("%s %d scif_listen rc %d\n", __func__, __LINE__, rc);
goto err;
}
pr_debug("%s %d listen_epd set up\n", __func__, __LINE__);
return 0;
err:
scif_close(listen_epd);
listen_epd = NULL;
return rc;
}
static void cosm_scif_listen_exit(void)
{
pr_debug("%s %d closing listen_epd\n", __func__, __LINE__);
if (listen_epd) {
scif_close(listen_epd);
listen_epd = NULL;
}
}
int cosm_scif_init(void)
{
int rc = cosm_scif_listen();
if (rc) {
pr_err("%s %d cosm_scif_listen rc %d\n",
__func__, __LINE__, rc);
goto err;
}
server_thread = kthread_run(cosm_scif_server, NULL, "cosm_server");
if (IS_ERR(server_thread)) {
rc = PTR_ERR(server_thread);
pr_err("%s %d kthread_run rc %d\n", __func__, __LINE__, rc);
goto listen_exit;
}
return 0;
listen_exit:
cosm_scif_listen_exit();
err:
return rc;
}
void cosm_scif_exit(void)
{
int rc;
if (!IS_ERR_OR_NULL(server_thread)) {
rc = send_sig(SIGKILL, server_thread, 0);
if (rc) {
pr_err("%s %d send_sig rc %d\n",
__func__, __LINE__, rc);
return;
}
kthread_stop(server_thread);
}
cosm_scif_listen_exit();
}
