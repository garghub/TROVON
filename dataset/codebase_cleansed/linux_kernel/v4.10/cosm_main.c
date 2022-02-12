static void cosm_hw_reset(struct cosm_device *cdev, bool force)
{
int i;
#define MIC_RESET_TO (45)
if (force && cdev->hw_ops->force_reset)
cdev->hw_ops->force_reset(cdev);
else
cdev->hw_ops->reset(cdev);
for (i = 0; i < MIC_RESET_TO; i++) {
if (cdev->hw_ops->ready(cdev)) {
cosm_set_state(cdev, MIC_READY);
return;
}
msleep(1000);
}
cosm_set_state(cdev, MIC_RESET_FAILED);
}
int cosm_start(struct cosm_device *cdev)
{
const struct cred *orig_cred;
struct cred *override_cred;
int rc;
mutex_lock(&cdev->cosm_mutex);
if (!cdev->bootmode) {
dev_err(&cdev->dev, "%s %d bootmode not set\n",
__func__, __LINE__);
rc = -EINVAL;
goto unlock_ret;
}
retry:
if (cdev->state != MIC_READY) {
dev_err(&cdev->dev, "%s %d MIC state not READY\n",
__func__, __LINE__);
rc = -EINVAL;
goto unlock_ret;
}
if (!cdev->hw_ops->ready(cdev)) {
cosm_hw_reset(cdev, false);
goto retry;
}
override_cred = prepare_creds();
if (!override_cred) {
dev_err(&cdev->dev, "%s %d prepare_creds failed\n",
__func__, __LINE__);
rc = -ENOMEM;
goto unlock_ret;
}
override_cred->fsuid = GLOBAL_ROOT_UID;
orig_cred = override_creds(override_cred);
rc = cdev->hw_ops->start(cdev, cdev->index);
revert_creds(orig_cred);
put_cred(override_cred);
if (rc)
goto unlock_ret;
if (!strcmp(cdev->bootmode, "linux"))
cosm_set_state(cdev, MIC_BOOTING);
else
cosm_set_state(cdev, MIC_ONLINE);
unlock_ret:
mutex_unlock(&cdev->cosm_mutex);
if (rc)
dev_err(&cdev->dev, "cosm_start failed rc %d\n", rc);
return rc;
}
void cosm_stop(struct cosm_device *cdev, bool force)
{
mutex_lock(&cdev->cosm_mutex);
if (cdev->state != MIC_READY || force) {
u8 state = cdev->state == MIC_RESETTING ?
cdev->prev_state : cdev->state;
bool call_hw_ops = state != MIC_RESET_FAILED &&
state != MIC_READY;
if (cdev->state != MIC_RESETTING)
cosm_set_state(cdev, MIC_RESETTING);
cdev->heartbeat_watchdog_enable = false;
if (call_hw_ops)
cdev->hw_ops->stop(cdev, force);
cosm_hw_reset(cdev, force);
cosm_set_shutdown_status(cdev, MIC_NOP);
if (call_hw_ops && cdev->hw_ops->post_reset)
cdev->hw_ops->post_reset(cdev, cdev->state);
}
mutex_unlock(&cdev->cosm_mutex);
flush_work(&cdev->scif_work);
}
static void cosm_reset_trigger_work(struct work_struct *work)
{
struct cosm_device *cdev = container_of(work, struct cosm_device,
reset_trigger_work);
cosm_stop(cdev, false);
}
int cosm_reset(struct cosm_device *cdev)
{
int rc = 0;
mutex_lock(&cdev->cosm_mutex);
if (cdev->state != MIC_READY) {
if (cdev->state != MIC_RESETTING) {
cdev->prev_state = cdev->state;
cosm_set_state(cdev, MIC_RESETTING);
schedule_work(&cdev->reset_trigger_work);
}
} else {
dev_err(&cdev->dev, "%s %d MIC is READY\n", __func__, __LINE__);
rc = -EINVAL;
}
mutex_unlock(&cdev->cosm_mutex);
return rc;
}
int cosm_shutdown(struct cosm_device *cdev)
{
struct cosm_msg msg = { .id = COSM_MSG_SHUTDOWN };
int rc = 0;
mutex_lock(&cdev->cosm_mutex);
if (cdev->state != MIC_ONLINE) {
rc = -EINVAL;
dev_err(&cdev->dev, "%s %d skipping shutdown in state: %s\n",
__func__, __LINE__, cosm_state_string[cdev->state]);
goto err;
}
if (!cdev->epd) {
rc = -ENOTCONN;
dev_err(&cdev->dev, "%s %d scif endpoint not connected rc %d\n",
__func__, __LINE__, rc);
goto err;
}
rc = scif_send(cdev->epd, &msg, sizeof(msg), SCIF_SEND_BLOCK);
if (rc < 0) {
dev_err(&cdev->dev, "%s %d scif_send failed rc %d\n",
__func__, __LINE__, rc);
goto err;
}
cdev->heartbeat_watchdog_enable = false;
cosm_set_state(cdev, MIC_SHUTTING_DOWN);
rc = 0;
err:
mutex_unlock(&cdev->cosm_mutex);
return rc;
}
static int cosm_driver_probe(struct cosm_device *cdev)
{
int rc;
if (atomic_add_return(1, &g_num_dev) == 1) {
rc = cosm_scif_init();
if (rc)
goto scif_exit;
}
mutex_init(&cdev->cosm_mutex);
INIT_WORK(&cdev->reset_trigger_work, cosm_reset_trigger_work);
INIT_WORK(&cdev->scif_work, cosm_scif_work);
cdev->sysfs_heartbeat_enable = true;
cosm_sysfs_init(cdev);
cdev->sdev = device_create_with_groups(g_cosm_class, cdev->dev.parent,
MKDEV(0, cdev->index), cdev, cdev->attr_group,
"mic%d", cdev->index);
if (IS_ERR(cdev->sdev)) {
rc = PTR_ERR(cdev->sdev);
dev_err(&cdev->dev, "device_create_with_groups failed rc %d\n",
rc);
goto scif_exit;
}
cdev->state_sysfs = sysfs_get_dirent(cdev->sdev->kobj.sd,
"state");
if (!cdev->state_sysfs) {
rc = -ENODEV;
dev_err(&cdev->dev, "sysfs_get_dirent failed rc %d\n", rc);
goto destroy_device;
}
cosm_create_debug_dir(cdev);
return 0;
destroy_device:
device_destroy(g_cosm_class, MKDEV(0, cdev->index));
scif_exit:
if (atomic_dec_and_test(&g_num_dev))
cosm_scif_exit();
return rc;
}
static void cosm_driver_remove(struct cosm_device *cdev)
{
cosm_delete_debug_dir(cdev);
sysfs_put(cdev->state_sysfs);
device_destroy(g_cosm_class, MKDEV(0, cdev->index));
flush_work(&cdev->reset_trigger_work);
cosm_stop(cdev, false);
if (atomic_dec_and_test(&g_num_dev))
cosm_scif_exit();
kfree(cdev->cmdline);
kfree(cdev->firmware);
kfree(cdev->ramdisk);
kfree(cdev->bootmode);
}
static int cosm_suspend(struct device *dev)
{
struct cosm_device *cdev = dev_to_cosm(dev);
mutex_lock(&cdev->cosm_mutex);
switch (cdev->state) {
case MIC_ONLINE:
case MIC_BOOTING:
case MIC_SHUTTING_DOWN:
mutex_unlock(&cdev->cosm_mutex);
cosm_stop(cdev, false);
break;
default:
mutex_unlock(&cdev->cosm_mutex);
break;
}
return 0;
}
static int __init cosm_init(void)
{
int ret;
cosm_init_debugfs();
g_cosm_class = class_create(THIS_MODULE, cosm_driver_name);
if (IS_ERR(g_cosm_class)) {
ret = PTR_ERR(g_cosm_class);
pr_err("class_create failed ret %d\n", ret);
goto cleanup_debugfs;
}
ida_init(&g_cosm_ida);
ret = cosm_register_driver(&cosm_driver);
if (ret) {
pr_err("cosm_register_driver failed ret %d\n", ret);
goto ida_destroy;
}
return 0;
ida_destroy:
ida_destroy(&g_cosm_ida);
class_destroy(g_cosm_class);
cleanup_debugfs:
cosm_exit_debugfs();
return ret;
}
static void __exit cosm_exit(void)
{
cosm_unregister_driver(&cosm_driver);
ida_destroy(&g_cosm_ida);
class_destroy(g_cosm_class);
cosm_exit_debugfs();
}
