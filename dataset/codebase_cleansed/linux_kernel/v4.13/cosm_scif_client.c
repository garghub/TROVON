static int cosm_reboot_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct cosm_msg msg = { .id = COSM_MSG_SHUTDOWN_STATUS };
int rc;
event = (event == SYS_RESTART) ? SYSTEM_RESTART : event;
dev_info(&client_spdev->dev, "%s %d received event %ld\n",
__func__, __LINE__, event);
msg.shutdown_status = event;
rc = scif_send(client_epd, &msg, sizeof(msg), SCIF_SEND_BLOCK);
if (rc < 0)
dev_err(&client_spdev->dev, "%s %d scif_send rc %d\n",
__func__, __LINE__, rc);
return NOTIFY_DONE;
}
static void cosm_set_time(struct cosm_msg *msg)
{
int rc = do_settimeofday64(&msg->timespec);
if (rc)
dev_err(&client_spdev->dev, "%s: %d settimeofday rc %d\n",
__func__, __LINE__, rc);
}
static void cosm_client_recv(void)
{
struct cosm_msg msg;
int rc;
while (1) {
rc = scif_recv(client_epd, &msg, sizeof(msg), 0);
if (!rc) {
return;
} else if (rc < 0) {
dev_err(&client_spdev->dev, "%s: %d rc %d\n",
__func__, __LINE__, rc);
return;
}
dev_dbg(&client_spdev->dev, "%s: %d rc %d id 0x%llx\n",
__func__, __LINE__, rc, msg.id);
switch (msg.id) {
case COSM_MSG_SYNC_TIME:
cosm_set_time(&msg);
break;
case COSM_MSG_SHUTDOWN:
orderly_poweroff(true);
break;
default:
dev_err(&client_spdev->dev, "%s: %d unknown id %lld\n",
__func__, __LINE__, msg.id);
break;
}
}
}
static int cosm_scif_connect(void)
{
struct scif_port_id port_id;
int i, rc;
client_epd = scif_open();
if (!client_epd) {
dev_err(&client_spdev->dev, "%s %d scif_open failed\n",
__func__, __LINE__);
return -ENOMEM;
}
port_id.node = 0;
port_id.port = SCIF_COSM_LISTEN_PORT;
for (i = 0; i < COSM_SCIF_MAX_RETRIES; i++) {
rc = scif_connect(client_epd, &port_id);
if (rc < 0)
msleep(1000);
else
break;
}
if (rc < 0) {
dev_err(&client_spdev->dev, "%s %d scif_connect rc %d\n",
__func__, __LINE__, rc);
scif_close(client_epd);
client_epd = NULL;
}
return rc < 0 ? rc : 0;
}
static void cosm_scif_connect_exit(void)
{
if (client_epd) {
scif_close(client_epd);
client_epd = NULL;
}
}
static int cosm_scif_client(void *unused)
{
struct cosm_msg msg = { .id = COSM_MSG_HEARTBEAT };
struct scif_pollepd pollepd;
int rc;
allow_signal(SIGKILL);
while (!kthread_should_stop()) {
pollepd.epd = client_epd;
pollepd.events = POLLIN;
rc = scif_poll(&pollepd, 1, COSM_HEARTBEAT_SEND_MSEC);
if (rc < 0) {
if (-EINTR != rc)
dev_err(&client_spdev->dev,
"%s %d scif_poll rc %d\n",
__func__, __LINE__, rc);
continue;
}
if (pollepd.revents & POLLIN)
cosm_client_recv();
msg.id = COSM_MSG_HEARTBEAT;
rc = scif_send(client_epd, &msg, sizeof(msg), SCIF_SEND_BLOCK);
if (rc < 0)
dev_err(&client_spdev->dev, "%s %d scif_send rc %d\n",
__func__, __LINE__, rc);
}
dev_dbg(&client_spdev->dev, "%s %d Client thread stopped\n",
__func__, __LINE__);
return 0;
}
static void cosm_scif_probe(struct scif_peer_dev *spdev)
{
int rc;
dev_dbg(&spdev->dev, "%s %d: dnode %d\n",
__func__, __LINE__, spdev->dnode);
if (spdev->dnode)
return;
client_spdev = spdev;
rc = cosm_scif_connect();
if (rc)
goto exit;
rc = register_reboot_notifier(&cosm_reboot);
if (rc) {
dev_err(&spdev->dev,
"reboot notifier registration failed rc %d\n", rc);
goto connect_exit;
}
client_thread = kthread_run(cosm_scif_client, NULL, "cosm_client");
if (IS_ERR(client_thread)) {
rc = PTR_ERR(client_thread);
dev_err(&spdev->dev, "%s %d kthread_run rc %d\n",
__func__, __LINE__, rc);
goto unreg_reboot;
}
return;
unreg_reboot:
unregister_reboot_notifier(&cosm_reboot);
connect_exit:
cosm_scif_connect_exit();
exit:
client_spdev = NULL;
}
static void cosm_scif_remove(struct scif_peer_dev *spdev)
{
int rc;
dev_dbg(&spdev->dev, "%s %d: dnode %d\n",
__func__, __LINE__, spdev->dnode);
if (spdev->dnode)
return;
if (!IS_ERR_OR_NULL(client_thread)) {
rc = send_sig(SIGKILL, client_thread, 0);
if (rc) {
pr_err("%s %d send_sig rc %d\n",
__func__, __LINE__, rc);
return;
}
kthread_stop(client_thread);
}
unregister_reboot_notifier(&cosm_reboot);
cosm_scif_connect_exit();
client_spdev = NULL;
}
static int __init cosm_client_init(void)
{
int rc = scif_client_register(&scif_client_cosm);
if (rc)
pr_err("scif_client_register failed rc %d\n", rc);
return rc;
}
static void __exit cosm_client_exit(void)
{
scif_client_unregister(&scif_client_cosm);
}
