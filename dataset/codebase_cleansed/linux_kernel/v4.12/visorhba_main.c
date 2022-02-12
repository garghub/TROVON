static struct task_struct *visor_thread_start
(int (*threadfn)(void *), void *thrcontext, char *name)
{
struct task_struct *task;
task = kthread_run(threadfn, thrcontext, "%s", name);
if (IS_ERR(task)) {
pr_err("visorbus failed to start thread\n");
return NULL;
}
return task;
}
static void visor_thread_stop(struct task_struct *task)
{
if (!task)
return;
kthread_stop(task);
}
static int add_scsipending_entry(struct visorhba_devdata *devdata,
char cmdtype, void *new)
{
unsigned long flags;
struct scsipending *entry;
int insert_location;
spin_lock_irqsave(&devdata->privlock, flags);
insert_location = devdata->nextinsert;
while (devdata->pending[insert_location].sent) {
insert_location = (insert_location + 1) % MAX_PENDING_REQUESTS;
if (insert_location == (int)devdata->nextinsert) {
spin_unlock_irqrestore(&devdata->privlock, flags);
return -EBUSY;
}
}
entry = &devdata->pending[insert_location];
memset(&entry->cmdrsp, 0, sizeof(entry->cmdrsp));
entry->cmdtype = cmdtype;
if (new)
entry->sent = new;
else
entry->sent = &entry->cmdrsp;
devdata->nextinsert = (insert_location + 1) % MAX_PENDING_REQUESTS;
spin_unlock_irqrestore(&devdata->privlock, flags);
return insert_location;
}
static void *del_scsipending_ent(struct visorhba_devdata *devdata,
int del)
{
unsigned long flags;
void *sent;
if (del >= MAX_PENDING_REQUESTS)
return NULL;
spin_lock_irqsave(&devdata->privlock, flags);
sent = devdata->pending[del].sent;
devdata->pending[del].cmdtype = 0;
devdata->pending[del].sent = NULL;
spin_unlock_irqrestore(&devdata->privlock, flags);
return sent;
}
static struct uiscmdrsp *get_scsipending_cmdrsp(struct visorhba_devdata *ddata,
int ent)
{
if (ddata->pending[ent].sent)
return &ddata->pending[ent].cmdrsp;
return NULL;
}
static unsigned int simple_idr_get(struct idr *idrtable, void *p,
spinlock_t *lock)
{
int id;
unsigned long flags;
idr_preload(GFP_KERNEL);
spin_lock_irqsave(lock, flags);
id = idr_alloc(idrtable, p, 1, INT_MAX, GFP_NOWAIT);
spin_unlock_irqrestore(lock, flags);
idr_preload_end();
if (id < 0)
return 0;
return (unsigned int)(id);
}
static void setup_scsitaskmgmt_handles(struct idr *idrtable, spinlock_t *lock,
struct uiscmdrsp *cmdrsp,
wait_queue_head_t *event, int *result)
{
cmdrsp->scsitaskmgmt.notify_handle =
simple_idr_get(idrtable, event, lock);
cmdrsp->scsitaskmgmt.notifyresult_handle =
simple_idr_get(idrtable, result, lock);
}
static void cleanup_scsitaskmgmt_handles(struct idr *idrtable,
struct uiscmdrsp *cmdrsp)
{
if (cmdrsp->scsitaskmgmt.notify_handle)
idr_remove(idrtable, cmdrsp->scsitaskmgmt.notify_handle);
if (cmdrsp->scsitaskmgmt.notifyresult_handle)
idr_remove(idrtable, cmdrsp->scsitaskmgmt.notifyresult_handle);
}
static int forward_taskmgmt_command(enum task_mgmt_types tasktype,
struct scsi_cmnd *scsicmd)
{
struct uiscmdrsp *cmdrsp;
struct scsi_device *scsidev = scsicmd->device;
struct visorhba_devdata *devdata =
(struct visorhba_devdata *)scsidev->host->hostdata;
int notifyresult = 0xffff;
wait_queue_head_t notifyevent;
int scsicmd_id = 0;
if (devdata->serverdown || devdata->serverchangingstate)
return FAILED;
scsicmd_id = add_scsipending_entry(devdata, CMD_SCSITASKMGMT_TYPE,
NULL);
if (scsicmd_id < 0)
return FAILED;
cmdrsp = get_scsipending_cmdrsp(devdata, scsicmd_id);
init_waitqueue_head(&notifyevent);
cmdrsp->cmdtype = CMD_SCSITASKMGMT_TYPE;
setup_scsitaskmgmt_handles(&devdata->idr, &devdata->privlock, cmdrsp,
&notifyevent, &notifyresult);
cmdrsp->scsitaskmgmt.tasktype = tasktype;
cmdrsp->scsitaskmgmt.vdest.channel = scsidev->channel;
cmdrsp->scsitaskmgmt.vdest.id = scsidev->id;
cmdrsp->scsitaskmgmt.vdest.lun = scsidev->lun;
cmdrsp->scsitaskmgmt.handle = scsicmd_id;
dev_dbg(&scsidev->sdev_gendev,
"visorhba: initiating type=%d taskmgmt command\n", tasktype);
if (visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
cmdrsp))
goto err_del_scsipending_ent;
if (!wait_event_timeout(notifyevent, notifyresult != 0xffff,
msecs_to_jiffies(45000)))
goto err_del_scsipending_ent;
dev_dbg(&scsidev->sdev_gendev,
"visorhba: taskmgmt type=%d success; result=0x%x\n",
tasktype, notifyresult);
if (tasktype == TASK_MGMT_ABORT_TASK)
scsicmd->result = DID_ABORT << 16;
else
scsicmd->result = DID_RESET << 16;
scsicmd->scsi_done(scsicmd);
cleanup_scsitaskmgmt_handles(&devdata->idr, cmdrsp);
return SUCCESS;
err_del_scsipending_ent:
dev_dbg(&scsidev->sdev_gendev,
"visorhba: taskmgmt type=%d not executed\n", tasktype);
del_scsipending_ent(devdata, scsicmd_id);
cleanup_scsitaskmgmt_handles(&devdata->idr, cmdrsp);
return FAILED;
}
static int visorhba_abort_handler(struct scsi_cmnd *scsicmd)
{
struct scsi_device *scsidev;
struct visordisk_info *vdisk;
struct visorhba_devdata *devdata;
scsidev = scsicmd->device;
devdata = (struct visorhba_devdata *)scsidev->host->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
if (atomic_read(&vdisk->error_count) < VISORHBA_ERROR_COUNT)
atomic_inc(&vdisk->error_count);
else
atomic_set(&vdisk->ios_threshold, IOS_ERROR_THRESHOLD);
}
return forward_taskmgmt_command(TASK_MGMT_ABORT_TASK, scsicmd);
}
static int visorhba_device_reset_handler(struct scsi_cmnd *scsicmd)
{
struct scsi_device *scsidev;
struct visordisk_info *vdisk;
struct visorhba_devdata *devdata;
scsidev = scsicmd->device;
devdata = (struct visorhba_devdata *)scsidev->host->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
if (atomic_read(&vdisk->error_count) < VISORHBA_ERROR_COUNT)
atomic_inc(&vdisk->error_count);
else
atomic_set(&vdisk->ios_threshold, IOS_ERROR_THRESHOLD);
}
return forward_taskmgmt_command(TASK_MGMT_LUN_RESET, scsicmd);
}
static int visorhba_bus_reset_handler(struct scsi_cmnd *scsicmd)
{
struct scsi_device *scsidev;
struct visordisk_info *vdisk;
struct visorhba_devdata *devdata;
scsidev = scsicmd->device;
devdata = (struct visorhba_devdata *)scsidev->host->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
if (atomic_read(&vdisk->error_count) < VISORHBA_ERROR_COUNT)
atomic_inc(&vdisk->error_count);
else
atomic_set(&vdisk->ios_threshold, IOS_ERROR_THRESHOLD);
}
return forward_taskmgmt_command(TASK_MGMT_BUS_RESET, scsicmd);
}
static int
visorhba_host_reset_handler(struct scsi_cmnd *scsicmd)
{
return SUCCESS;
}
static const char *visorhba_get_info(struct Scsi_Host *shp)
{
return "visorhba";
}
static int
visorhba_queue_command_lck(struct scsi_cmnd *scsicmd,
void (*visorhba_cmnd_done)(struct scsi_cmnd *))
{
struct uiscmdrsp *cmdrsp;
struct scsi_device *scsidev = scsicmd->device;
int insert_location;
unsigned char *cdb = scsicmd->cmnd;
struct Scsi_Host *scsihost = scsidev->host;
unsigned int i;
struct visorhba_devdata *devdata =
(struct visorhba_devdata *)scsihost->hostdata;
struct scatterlist *sg = NULL;
struct scatterlist *sglist = NULL;
if (devdata->serverdown || devdata->serverchangingstate)
return SCSI_MLQUEUE_DEVICE_BUSY;
insert_location = add_scsipending_entry(devdata, CMD_SCSI_TYPE,
(void *)scsicmd);
if (insert_location < 0)
return SCSI_MLQUEUE_DEVICE_BUSY;
cmdrsp = get_scsipending_cmdrsp(devdata, insert_location);
cmdrsp->cmdtype = CMD_SCSI_TYPE;
cmdrsp->scsi.handle = insert_location;
scsicmd->scsi_done = visorhba_cmnd_done;
cmdrsp->scsi.vdest.channel = scsidev->channel;
cmdrsp->scsi.vdest.id = scsidev->id;
cmdrsp->scsi.vdest.lun = scsidev->lun;
cmdrsp->scsi.data_dir = scsicmd->sc_data_direction;
memcpy(cmdrsp->scsi.cmnd, cdb, MAX_CMND_SIZE);
cmdrsp->scsi.bufflen = scsi_bufflen(scsicmd);
if (cmdrsp->scsi.bufflen > devdata->max_buff_len)
devdata->max_buff_len = cmdrsp->scsi.bufflen;
if (scsi_sg_count(scsicmd) > MAX_PHYS_INFO)
goto err_del_scsipending_ent;
sglist = scsi_sglist(scsicmd);
for_each_sg(sglist, sg, scsi_sg_count(scsicmd), i) {
cmdrsp->scsi.gpi_list[i].address = sg_phys(sg);
cmdrsp->scsi.gpi_list[i].length = sg->length;
}
cmdrsp->scsi.guest_phys_entries = scsi_sg_count(scsicmd);
if (visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
cmdrsp))
goto err_del_scsipending_ent;
return 0;
err_del_scsipending_ent:
del_scsipending_ent(devdata, insert_location);
return SCSI_MLQUEUE_DEVICE_BUSY;
}
void visorhba_slave_destroy(struct scsi_device *scsidev)
{
struct visordisk_info *vdisk, *delvdisk;
struct visorhba_devdata *devdata;
struct Scsi_Host *scsihost = (struct Scsi_Host *)scsidev->host;
devdata = (struct visorhba_devdata *)scsihost->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
delvdisk = vdisk->next;
vdisk->next = delvdisk->next;
kfree(delvdisk);
return;
}
}
static int info_debugfs_show(struct seq_file *seq, void *v)
{
struct visorhba_devdata *devdata = seq->private;
seq_printf(seq, "max_buff_len = %u\n", devdata->max_buff_len);
seq_printf(seq, "interrupts_rcvd = %llu\n", devdata->interrupts_rcvd);
seq_printf(seq, "interrupts_disabled = %llu\n",
devdata->interrupts_disabled);
seq_printf(seq, "interrupts_notme = %llu\n",
devdata->interrupts_notme);
seq_printf(seq, "flags_addr = %p\n", devdata->flags_addr);
if (devdata->flags_addr) {
u64 phys_flags_addr =
virt_to_phys((__force void *)devdata->flags_addr);
seq_printf(seq, "phys_flags_addr = 0x%016llx\n",
phys_flags_addr);
seq_printf(seq, "FeatureFlags = %llu\n",
(__le64)readq(devdata->flags_addr));
}
seq_printf(seq, "acquire_failed_cnt = %llu\n",
devdata->acquire_failed_cnt);
return 0;
}
static int info_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, info_debugfs_show, inode->i_private);
}
static void complete_taskmgmt_command(struct idr *idrtable,
struct uiscmdrsp *cmdrsp, int result)
{
wait_queue_head_t *wq =
idr_find(idrtable, cmdrsp->scsitaskmgmt.notify_handle);
int *scsi_result_ptr =
idr_find(idrtable, cmdrsp->scsitaskmgmt.notifyresult_handle);
if (unlikely(!(wq && scsi_result_ptr))) {
pr_err("visorhba: no completion context; cmd will time out\n");
return;
}
pr_debug("visorhba: notifying initiator with result=0x%x\n", result);
*scsi_result_ptr = result;
wake_up_all(wq);
}
static void visorhba_serverdown_complete(struct visorhba_devdata *devdata)
{
int i;
struct scsipending *pendingdel = NULL;
struct scsi_cmnd *scsicmd = NULL;
struct uiscmdrsp *cmdrsp;
unsigned long flags;
visor_thread_stop(devdata->thread);
spin_lock_irqsave(&devdata->privlock, flags);
for (i = 0; i < MAX_PENDING_REQUESTS; i++) {
pendingdel = &devdata->pending[i];
switch (pendingdel->cmdtype) {
case CMD_SCSI_TYPE:
scsicmd = pendingdel->sent;
scsicmd->result = DID_RESET << 16;
if (scsicmd->scsi_done)
scsicmd->scsi_done(scsicmd);
break;
case CMD_SCSITASKMGMT_TYPE:
cmdrsp = pendingdel->sent;
complete_taskmgmt_command(&devdata->idr, cmdrsp,
TASK_MGMT_FAILED);
break;
default:
break;
}
pendingdel->cmdtype = 0;
pendingdel->sent = NULL;
}
spin_unlock_irqrestore(&devdata->privlock, flags);
devdata->serverdown = true;
devdata->serverchangingstate = false;
}
static int visorhba_serverdown(struct visorhba_devdata *devdata)
{
if (!devdata->serverdown && !devdata->serverchangingstate) {
devdata->serverchangingstate = true;
visorhba_serverdown_complete(devdata);
} else if (devdata->serverchangingstate) {
return -EINVAL;
}
return 0;
}
static void
do_scsi_linuxstat(struct uiscmdrsp *cmdrsp, struct scsi_cmnd *scsicmd)
{
struct visorhba_devdata *devdata;
struct visordisk_info *vdisk;
struct scsi_device *scsidev;
scsidev = scsicmd->device;
memcpy(scsicmd->sense_buffer, cmdrsp->scsi.sensebuf, MAX_SENSE_SIZE);
if ((cmdrsp->scsi.cmnd[0] == INQUIRY) &&
(host_byte(cmdrsp->scsi.linuxstat) == DID_NO_CONNECT) &&
(cmdrsp->scsi.addlstat == ADDL_SEL_TIMEOUT))
return;
devdata = (struct visorhba_devdata *)scsidev->host->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
if (atomic_read(&vdisk->error_count) < VISORHBA_ERROR_COUNT) {
atomic_inc(&vdisk->error_count);
atomic_set(&vdisk->ios_threshold, IOS_ERROR_THRESHOLD);
}
}
}
static int set_no_disk_inquiry_result(unsigned char *buf,
size_t len, bool is_lun0)
{
if (!buf || len < NO_DISK_INQUIRY_RESULT_LEN)
return -EINVAL;
memset(buf, 0, NO_DISK_INQUIRY_RESULT_LEN);
buf[2] = SCSI_SPC2_VER;
if (is_lun0) {
buf[0] = DEV_DISK_CAPABLE_NOT_PRESENT;
buf[3] = DEV_HISUPPORT;
} else {
buf[0] = DEV_NOT_CAPABLE;
}
buf[4] = NO_DISK_INQUIRY_RESULT_LEN - 5;
strncpy(buf + 8, "DELLPSEUDO DEVICE .", NO_DISK_INQUIRY_RESULT_LEN - 8);
return 0;
}
static void
do_scsi_nolinuxstat(struct uiscmdrsp *cmdrsp, struct scsi_cmnd *scsicmd)
{
struct scsi_device *scsidev;
unsigned char *buf;
struct scatterlist *sg;
unsigned int i;
char *this_page;
char *this_page_orig;
int bufind = 0;
struct visordisk_info *vdisk;
struct visorhba_devdata *devdata;
scsidev = scsicmd->device;
if ((cmdrsp->scsi.cmnd[0] == INQUIRY) &&
(cmdrsp->scsi.bufflen >= MIN_INQUIRY_RESULT_LEN)) {
if (cmdrsp->scsi.no_disk_result == 0)
return;
buf = kzalloc(sizeof(char) * 36, GFP_KERNEL);
if (!buf)
return;
set_no_disk_inquiry_result(buf, (size_t)cmdrsp->scsi.bufflen,
scsidev->lun == 0);
if (scsi_sg_count(scsicmd) == 0) {
memcpy(scsi_sglist(scsicmd), buf,
cmdrsp->scsi.bufflen);
kfree(buf);
return;
}
sg = scsi_sglist(scsicmd);
for (i = 0; i < scsi_sg_count(scsicmd); i++) {
this_page_orig = kmap_atomic(sg_page(sg + i));
this_page = (void *)((unsigned long)this_page_orig |
sg[i].offset);
memcpy(this_page, buf + bufind, sg[i].length);
kunmap_atomic(this_page_orig);
}
kfree(buf);
} else {
devdata = (struct visorhba_devdata *)scsidev->host->hostdata;
for_each_vdisk_match(vdisk, devdata, scsidev) {
if (atomic_read(&vdisk->ios_threshold) > 0) {
atomic_dec(&vdisk->ios_threshold);
if (atomic_read(&vdisk->ios_threshold) == 0)
atomic_set(&vdisk->error_count, 0);
}
}
}
}
static void
complete_scsi_command(struct uiscmdrsp *cmdrsp, struct scsi_cmnd *scsicmd)
{
scsicmd->result = cmdrsp->scsi.linuxstat;
if (cmdrsp->scsi.linuxstat)
do_scsi_linuxstat(cmdrsp, scsicmd);
else
do_scsi_nolinuxstat(cmdrsp, scsicmd);
scsicmd->scsi_done(scsicmd);
}
static void
drain_queue(struct uiscmdrsp *cmdrsp, struct visorhba_devdata *devdata)
{
struct scsi_cmnd *scsicmd;
while (1) {
if (visorchannel_signalremove(devdata->dev->visorchannel,
IOCHAN_FROM_IOPART,
cmdrsp))
break;
if (cmdrsp->cmdtype == CMD_SCSI_TYPE) {
scsicmd = del_scsipending_ent(devdata,
cmdrsp->scsi.handle);
if (!scsicmd)
break;
complete_scsi_command(cmdrsp, scsicmd);
} else if (cmdrsp->cmdtype == CMD_SCSITASKMGMT_TYPE) {
if (!del_scsipending_ent(devdata,
cmdrsp->scsitaskmgmt.handle))
break;
complete_taskmgmt_command(&devdata->idr, cmdrsp,
cmdrsp->scsitaskmgmt.result);
} else if (cmdrsp->cmdtype == CMD_NOTIFYGUEST_TYPE)
dev_err_once(&devdata->dev->device,
"ignoring unsupported NOTIFYGUEST\n");
}
}
static int process_incoming_rsps(void *v)
{
struct visorhba_devdata *devdata = v;
struct uiscmdrsp *cmdrsp = NULL;
const int size = sizeof(*cmdrsp);
cmdrsp = kmalloc(size, GFP_ATOMIC);
if (!cmdrsp)
return -ENOMEM;
while (1) {
if (kthread_should_stop())
break;
wait_event_interruptible_timeout(
devdata->rsp_queue, (atomic_read(
&devdata->interrupt_rcvd) == 1),
msecs_to_jiffies(devdata->thread_wait_ms));
drain_queue(cmdrsp, devdata);
}
kfree(cmdrsp);
return 0;
}
static int visorhba_pause(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visorhba_devdata *devdata = dev_get_drvdata(&dev->device);
visorhba_serverdown(devdata);
complete_func(dev, 0);
return 0;
}
static int visorhba_resume(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visorhba_devdata *devdata;
devdata = dev_get_drvdata(&dev->device);
if (!devdata)
return -EINVAL;
if (devdata->serverdown && !devdata->serverchangingstate)
devdata->serverchangingstate = true;
devdata->thread = visor_thread_start(process_incoming_rsps, devdata,
"vhba_incming");
devdata->serverdown = false;
devdata->serverchangingstate = false;
return 0;
}
static int visorhba_probe(struct visor_device *dev)
{
struct Scsi_Host *scsihost;
struct vhba_config_max max;
struct visorhba_devdata *devdata = NULL;
int err, channel_offset;
u64 features;
scsihost = scsi_host_alloc(&visorhba_driver_template,
sizeof(*devdata));
if (!scsihost)
return -ENODEV;
channel_offset = offsetof(struct spar_io_channel_protocol,
vhba.max);
err = visorbus_read_channel(dev, channel_offset, &max,
sizeof(struct vhba_config_max));
if (err < 0)
goto err_scsi_host_put;
scsihost->max_id = (unsigned int)max.max_id;
scsihost->max_lun = (unsigned int)max.max_lun;
scsihost->cmd_per_lun = (unsigned int)max.cmd_per_lun;
scsihost->max_sectors =
(unsigned short)(max.max_io_size >> 9);
scsihost->sg_tablesize =
(unsigned short)(max.max_io_size / PAGE_SIZE);
if (scsihost->sg_tablesize > MAX_PHYS_INFO)
scsihost->sg_tablesize = MAX_PHYS_INFO;
err = scsi_add_host(scsihost, &dev->device);
if (err < 0)
goto err_scsi_host_put;
devdata = (struct visorhba_devdata *)scsihost->hostdata;
devdata->dev = dev;
dev_set_drvdata(&dev->device, devdata);
devdata->debugfs_dir = debugfs_create_dir(dev_name(&dev->device),
visorhba_debugfs_dir);
if (!devdata->debugfs_dir) {
err = -ENOMEM;
goto err_scsi_remove_host;
}
devdata->debugfs_info =
debugfs_create_file("info", S_IRUSR | S_IRGRP,
devdata->debugfs_dir, devdata,
&info_debugfs_fops);
if (!devdata->debugfs_info) {
err = -ENOMEM;
goto err_debugfs_dir;
}
init_waitqueue_head(&devdata->rsp_queue);
spin_lock_init(&devdata->privlock);
devdata->serverdown = false;
devdata->serverchangingstate = false;
devdata->scsihost = scsihost;
channel_offset = offsetof(struct spar_io_channel_protocol,
channel_header.features);
err = visorbus_read_channel(dev, channel_offset, &features, 8);
if (err)
goto err_debugfs_info;
features |= ULTRA_IO_CHANNEL_IS_POLLING;
err = visorbus_write_channel(dev, channel_offset, &features, 8);
if (err)
goto err_debugfs_info;
idr_init(&devdata->idr);
devdata->thread_wait_ms = 2;
devdata->thread = visor_thread_start(process_incoming_rsps, devdata,
"vhba_incoming");
scsi_scan_host(scsihost);
return 0;
err_debugfs_info:
debugfs_remove(devdata->debugfs_info);
err_debugfs_dir:
debugfs_remove_recursive(devdata->debugfs_dir);
err_scsi_remove_host:
scsi_remove_host(scsihost);
err_scsi_host_put:
scsi_host_put(scsihost);
return err;
}
static void visorhba_remove(struct visor_device *dev)
{
struct visorhba_devdata *devdata = dev_get_drvdata(&dev->device);
struct Scsi_Host *scsihost = NULL;
if (!devdata)
return;
scsihost = devdata->scsihost;
visor_thread_stop(devdata->thread);
scsi_remove_host(scsihost);
scsi_host_put(scsihost);
idr_destroy(&devdata->idr);
dev_set_drvdata(&dev->device, NULL);
debugfs_remove(devdata->debugfs_info);
debugfs_remove_recursive(devdata->debugfs_dir);
}
static int visorhba_init(void)
{
int rc = -ENOMEM;
visorhba_debugfs_dir = debugfs_create_dir("visorhba", NULL);
if (!visorhba_debugfs_dir)
return -ENOMEM;
rc = visorbus_register_visor_driver(&visorhba_driver);
if (rc)
goto cleanup_debugfs;
return 0;
cleanup_debugfs:
debugfs_remove_recursive(visorhba_debugfs_dir);
return rc;
}
static void visorhba_exit(void)
{
visorbus_unregister_visor_driver(&visorhba_driver);
debugfs_remove_recursive(visorhba_debugfs_dir);
}
