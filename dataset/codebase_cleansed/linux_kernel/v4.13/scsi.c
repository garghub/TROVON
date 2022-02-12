void scsi_put_command(struct scsi_cmnd *cmd)
{
scsi_del_cmd_from_list(cmd);
BUG_ON(delayed_work_pending(&cmd->abort_work));
}
void scsi_log_send(struct scsi_cmnd *cmd)
{
unsigned int level;
if (unlikely(scsi_logging_level)) {
level = SCSI_LOG_LEVEL(SCSI_LOG_MLQUEUE_SHIFT,
SCSI_LOG_MLQUEUE_BITS);
if (level > 1) {
scmd_printk(KERN_INFO, cmd,
"Send: scmd 0x%p\n", cmd);
scsi_print_command(cmd);
}
}
}
void scsi_log_completion(struct scsi_cmnd *cmd, int disposition)
{
unsigned int level;
if (unlikely(scsi_logging_level)) {
level = SCSI_LOG_LEVEL(SCSI_LOG_MLCOMPLETE_SHIFT,
SCSI_LOG_MLCOMPLETE_BITS);
if (((level > 0) && (cmd->result || disposition != SUCCESS)) ||
(level > 1)) {
scsi_print_result(cmd, "Done", disposition);
scsi_print_command(cmd);
if (status_byte(cmd->result) & CHECK_CONDITION)
scsi_print_sense(cmd);
if (level > 3)
scmd_printk(KERN_INFO, cmd,
"scsi host busy %d failed %d\n",
atomic_read(&cmd->device->host->host_busy),
cmd->device->host->host_failed);
}
}
}
void scsi_cmd_get_serial(struct Scsi_Host *host, struct scsi_cmnd *cmd)
{
cmd->serial_number = host->cmd_serial_number++;
if (cmd->serial_number == 0)
cmd->serial_number = host->cmd_serial_number++;
}
void scsi_finish_command(struct scsi_cmnd *cmd)
{
struct scsi_device *sdev = cmd->device;
struct scsi_target *starget = scsi_target(sdev);
struct Scsi_Host *shost = sdev->host;
struct scsi_driver *drv;
unsigned int good_bytes;
scsi_device_unbusy(sdev);
if (atomic_read(&shost->host_blocked))
atomic_set(&shost->host_blocked, 0);
if (atomic_read(&starget->target_blocked))
atomic_set(&starget->target_blocked, 0);
if (atomic_read(&sdev->device_blocked))
atomic_set(&sdev->device_blocked, 0);
if (SCSI_SENSE_VALID(cmd))
cmd->result |= (DRIVER_SENSE << 24);
SCSI_LOG_MLCOMPLETE(4, sdev_printk(KERN_INFO, sdev,
"Notifying upper driver of completion "
"(result %x)\n", cmd->result));
good_bytes = scsi_bufflen(cmd);
if (!blk_rq_is_passthrough(cmd->request)) {
int old_good_bytes = good_bytes;
drv = scsi_cmd_to_driver(cmd);
if (drv->done)
good_bytes = drv->done(cmd);
if (good_bytes == old_good_bytes)
good_bytes -= scsi_get_resid(cmd);
}
scsi_io_completion(cmd, good_bytes);
}
int scsi_change_queue_depth(struct scsi_device *sdev, int depth)
{
if (depth > 0) {
sdev->queue_depth = depth;
wmb();
}
if (sdev->request_queue)
blk_set_queue_depth(sdev->request_queue, depth);
return sdev->queue_depth;
}
int scsi_track_queue_full(struct scsi_device *sdev, int depth)
{
if ((jiffies >> 4) == (sdev->last_queue_full_time >> 4))
return 0;
sdev->last_queue_full_time = jiffies;
if (sdev->last_queue_full_depth != depth) {
sdev->last_queue_full_count = 1;
sdev->last_queue_full_depth = depth;
} else {
sdev->last_queue_full_count++;
}
if (sdev->last_queue_full_count <= 10)
return 0;
return scsi_change_queue_depth(sdev, depth);
}
static int scsi_vpd_inquiry(struct scsi_device *sdev, unsigned char *buffer,
u8 page, unsigned len)
{
int result;
unsigned char cmd[16];
if (len < 4)
return -EINVAL;
cmd[0] = INQUIRY;
cmd[1] = 1;
cmd[2] = page;
cmd[3] = len >> 8;
cmd[4] = len & 0xff;
cmd[5] = 0;
result = scsi_execute_req(sdev, cmd, DMA_FROM_DEVICE, buffer,
len, NULL, 30 * HZ, 3, NULL);
if (result)
return -EIO;
if (buffer[1] != page)
return -EIO;
return get_unaligned_be16(&buffer[2]) + 4;
}
int scsi_get_vpd_page(struct scsi_device *sdev, u8 page, unsigned char *buf,
int buf_len)
{
int i, result;
if (sdev->skip_vpd_pages)
goto fail;
result = scsi_vpd_inquiry(sdev, buf, 0, buf_len);
if (result < 4)
goto fail;
if (page == 0)
return 0;
for (i = 4; i < min(result, buf_len); i++)
if (buf[i] == page)
goto found;
if (i < result && i >= buf_len)
goto found;
goto fail;
found:
result = scsi_vpd_inquiry(sdev, buf, page, buf_len);
if (result < 0)
goto fail;
return 0;
fail:
return -EINVAL;
}
void scsi_attach_vpd(struct scsi_device *sdev)
{
int result, i;
int vpd_len = SCSI_VPD_PG_LEN;
int pg80_supported = 0;
int pg83_supported = 0;
unsigned char __rcu *vpd_buf, *orig_vpd_buf = NULL;
if (!scsi_device_supports_vpd(sdev))
return;
retry_pg0:
vpd_buf = kmalloc(vpd_len, GFP_KERNEL);
if (!vpd_buf)
return;
result = scsi_vpd_inquiry(sdev, vpd_buf, 0, vpd_len);
if (result < 0) {
kfree(vpd_buf);
return;
}
if (result > vpd_len) {
vpd_len = result;
kfree(vpd_buf);
goto retry_pg0;
}
for (i = 4; i < result; i++) {
if (vpd_buf[i] == 0x80)
pg80_supported = 1;
if (vpd_buf[i] == 0x83)
pg83_supported = 1;
}
kfree(vpd_buf);
vpd_len = SCSI_VPD_PG_LEN;
if (pg80_supported) {
retry_pg80:
vpd_buf = kmalloc(vpd_len, GFP_KERNEL);
if (!vpd_buf)
return;
result = scsi_vpd_inquiry(sdev, vpd_buf, 0x80, vpd_len);
if (result < 0) {
kfree(vpd_buf);
return;
}
if (result > vpd_len) {
vpd_len = result;
kfree(vpd_buf);
goto retry_pg80;
}
mutex_lock(&sdev->inquiry_mutex);
orig_vpd_buf = sdev->vpd_pg80;
sdev->vpd_pg80_len = result;
rcu_assign_pointer(sdev->vpd_pg80, vpd_buf);
mutex_unlock(&sdev->inquiry_mutex);
synchronize_rcu();
if (orig_vpd_buf) {
kfree(orig_vpd_buf);
orig_vpd_buf = NULL;
}
vpd_len = SCSI_VPD_PG_LEN;
}
if (pg83_supported) {
retry_pg83:
vpd_buf = kmalloc(vpd_len, GFP_KERNEL);
if (!vpd_buf)
return;
result = scsi_vpd_inquiry(sdev, vpd_buf, 0x83, vpd_len);
if (result < 0) {
kfree(vpd_buf);
return;
}
if (result > vpd_len) {
vpd_len = result;
kfree(vpd_buf);
goto retry_pg83;
}
mutex_lock(&sdev->inquiry_mutex);
orig_vpd_buf = sdev->vpd_pg83;
sdev->vpd_pg83_len = result;
rcu_assign_pointer(sdev->vpd_pg83, vpd_buf);
mutex_unlock(&sdev->inquiry_mutex);
synchronize_rcu();
if (orig_vpd_buf)
kfree(orig_vpd_buf);
}
}
int scsi_report_opcode(struct scsi_device *sdev, unsigned char *buffer,
unsigned int len, unsigned char opcode)
{
unsigned char cmd[16];
struct scsi_sense_hdr sshdr;
int result;
if (sdev->no_report_opcodes || sdev->scsi_level < SCSI_SPC_3)
return -EINVAL;
memset(cmd, 0, 16);
cmd[0] = MAINTENANCE_IN;
cmd[1] = MI_REPORT_SUPPORTED_OPERATION_CODES;
cmd[2] = 1;
cmd[3] = opcode;
put_unaligned_be32(len, &cmd[6]);
memset(buffer, 0, len);
result = scsi_execute_req(sdev, cmd, DMA_FROM_DEVICE, buffer, len,
&sshdr, 30 * HZ, 3, NULL);
if (result && scsi_sense_valid(&sshdr) &&
sshdr.sense_key == ILLEGAL_REQUEST &&
(sshdr.asc == 0x20 || sshdr.asc == 0x24) && sshdr.ascq == 0x00)
return -EINVAL;
if ((buffer[1] & 3) == 3)
return 1;
return 0;
}
int scsi_device_get(struct scsi_device *sdev)
{
if (sdev->sdev_state == SDEV_DEL || sdev->sdev_state == SDEV_CANCEL)
goto fail;
if (!get_device(&sdev->sdev_gendev))
goto fail;
if (!try_module_get(sdev->host->hostt->module))
goto fail_put_device;
return 0;
fail_put_device:
put_device(&sdev->sdev_gendev);
fail:
return -ENXIO;
}
void scsi_device_put(struct scsi_device *sdev)
{
module_put(sdev->host->hostt->module);
put_device(&sdev->sdev_gendev);
}
struct scsi_device *__scsi_iterate_devices(struct Scsi_Host *shost,
struct scsi_device *prev)
{
struct list_head *list = (prev ? &prev->siblings : &shost->__devices);
struct scsi_device *next = NULL;
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
while (list->next != &shost->__devices) {
next = list_entry(list->next, struct scsi_device, siblings);
if (!scsi_device_get(next))
break;
next = NULL;
list = list->next;
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (prev)
scsi_device_put(prev);
return next;
}
void starget_for_each_device(struct scsi_target *starget, void *data,
void (*fn)(struct scsi_device *, void *))
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct scsi_device *sdev;
shost_for_each_device(sdev, shost) {
if ((sdev->channel == starget->channel) &&
(sdev->id == starget->id))
fn(sdev, data);
}
}
void __starget_for_each_device(struct scsi_target *starget, void *data,
void (*fn)(struct scsi_device *, void *))
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct scsi_device *sdev;
__shost_for_each_device(sdev, shost) {
if ((sdev->channel == starget->channel) &&
(sdev->id == starget->id))
fn(sdev, data);
}
}
struct scsi_device *__scsi_device_lookup_by_target(struct scsi_target *starget,
u64 lun)
{
struct scsi_device *sdev;
list_for_each_entry(sdev, &starget->devices, same_target_siblings) {
if (sdev->sdev_state == SDEV_DEL)
continue;
if (sdev->lun ==lun)
return sdev;
}
return NULL;
}
struct scsi_device *scsi_device_lookup_by_target(struct scsi_target *starget,
u64 lun)
{
struct scsi_device *sdev;
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
sdev = __scsi_device_lookup_by_target(starget, lun);
if (sdev && scsi_device_get(sdev))
sdev = NULL;
spin_unlock_irqrestore(shost->host_lock, flags);
return sdev;
}
struct scsi_device *__scsi_device_lookup(struct Scsi_Host *shost,
uint channel, uint id, u64 lun)
{
struct scsi_device *sdev;
list_for_each_entry(sdev, &shost->__devices, siblings) {
if (sdev->sdev_state == SDEV_DEL)
continue;
if (sdev->channel == channel && sdev->id == id &&
sdev->lun ==lun)
return sdev;
}
return NULL;
}
struct scsi_device *scsi_device_lookup(struct Scsi_Host *shost,
uint channel, uint id, u64 lun)
{
struct scsi_device *sdev;
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
sdev = __scsi_device_lookup(shost, channel, id, lun);
if (sdev && scsi_device_get(sdev))
sdev = NULL;
spin_unlock_irqrestore(shost->host_lock, flags);
return sdev;
}
static int __init init_scsi(void)
{
int error;
error = scsi_init_queue();
if (error)
return error;
error = scsi_init_procfs();
if (error)
goto cleanup_queue;
error = scsi_init_devinfo();
if (error)
goto cleanup_procfs;
error = scsi_init_hosts();
if (error)
goto cleanup_devlist;
error = scsi_init_sysctl();
if (error)
goto cleanup_hosts;
error = scsi_sysfs_register();
if (error)
goto cleanup_sysctl;
scsi_netlink_init();
printk(KERN_NOTICE "SCSI subsystem initialized\n");
return 0;
cleanup_sysctl:
scsi_exit_sysctl();
cleanup_hosts:
scsi_exit_hosts();
cleanup_devlist:
scsi_exit_devinfo();
cleanup_procfs:
scsi_exit_procfs();
cleanup_queue:
scsi_exit_queue();
printk(KERN_ERR "SCSI subsystem failed to initialize, error = %d\n",
-error);
return error;
}
static void __exit exit_scsi(void)
{
scsi_netlink_exit();
scsi_sysfs_unregister();
scsi_exit_sysctl();
scsi_exit_hosts();
scsi_exit_devinfo();
scsi_exit_procfs();
scsi_exit_queue();
async_unregister_domain(&scsi_sd_probe_domain);
}
