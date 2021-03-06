static void scsi_host_cls_release(struct device *dev)
{
put_device(&class_to_shost(dev)->shost_gendev);
}
int scsi_host_set_state(struct Scsi_Host *shost, enum scsi_host_state state)
{
enum scsi_host_state oldstate = shost->shost_state;
if (state == oldstate)
return 0;
switch (state) {
case SHOST_CREATED:
goto illegal;
case SHOST_RUNNING:
switch (oldstate) {
case SHOST_CREATED:
case SHOST_RECOVERY:
break;
default:
goto illegal;
}
break;
case SHOST_RECOVERY:
switch (oldstate) {
case SHOST_RUNNING:
break;
default:
goto illegal;
}
break;
case SHOST_CANCEL:
switch (oldstate) {
case SHOST_CREATED:
case SHOST_RUNNING:
case SHOST_CANCEL_RECOVERY:
break;
default:
goto illegal;
}
break;
case SHOST_DEL:
switch (oldstate) {
case SHOST_CANCEL:
case SHOST_DEL_RECOVERY:
break;
default:
goto illegal;
}
break;
case SHOST_CANCEL_RECOVERY:
switch (oldstate) {
case SHOST_CANCEL:
case SHOST_RECOVERY:
break;
default:
goto illegal;
}
break;
case SHOST_DEL_RECOVERY:
switch (oldstate) {
case SHOST_CANCEL_RECOVERY:
break;
default:
goto illegal;
}
break;
}
shost->shost_state = state;
return 0;
illegal:
SCSI_LOG_ERROR_RECOVERY(1,
shost_printk(KERN_ERR, shost,
"Illegal host state transition"
"%s->%s\n",
scsi_host_state_name(oldstate),
scsi_host_state_name(state)));
return -EINVAL;
}
void scsi_remove_host(struct Scsi_Host *shost)
{
unsigned long flags;
mutex_lock(&shost->scan_mutex);
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_set_state(shost, SHOST_CANCEL))
if (scsi_host_set_state(shost, SHOST_CANCEL_RECOVERY)) {
spin_unlock_irqrestore(shost->host_lock, flags);
mutex_unlock(&shost->scan_mutex);
return;
}
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_autopm_get_host(shost);
scsi_forget_host(shost);
mutex_unlock(&shost->scan_mutex);
scsi_proc_host_rm(shost);
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_set_state(shost, SHOST_DEL))
BUG_ON(scsi_host_set_state(shost, SHOST_DEL_RECOVERY));
spin_unlock_irqrestore(shost->host_lock, flags);
transport_unregister_device(&shost->shost_gendev);
device_unregister(&shost->shost_dev);
device_del(&shost->shost_gendev);
}
int scsi_add_host_with_dma(struct Scsi_Host *shost, struct device *dev,
struct device *dma_dev)
{
struct scsi_host_template *sht = shost->hostt;
int error = -EINVAL;
printk(KERN_INFO "scsi%d : %s\n", shost->host_no,
sht->info ? sht->info(shost) : sht->name);
if (!shost->can_queue) {
printk(KERN_ERR "%s: can_queue = 0 no longer supported\n",
sht->name);
goto fail;
}
error = scsi_setup_command_freelist(shost);
if (error)
goto fail;
if (!shost->shost_gendev.parent)
shost->shost_gendev.parent = dev ? dev : &platform_bus;
shost->dma_dev = dma_dev;
error = device_add(&shost->shost_gendev);
if (error)
goto out;
pm_runtime_set_active(&shost->shost_gendev);
pm_runtime_enable(&shost->shost_gendev);
device_enable_async_suspend(&shost->shost_gendev);
scsi_host_set_state(shost, SHOST_RUNNING);
get_device(shost->shost_gendev.parent);
device_enable_async_suspend(&shost->shost_dev);
error = device_add(&shost->shost_dev);
if (error)
goto out_del_gendev;
get_device(&shost->shost_gendev);
if (shost->transportt->host_size) {
shost->shost_data = kzalloc(shost->transportt->host_size,
GFP_KERNEL);
if (shost->shost_data == NULL) {
error = -ENOMEM;
goto out_del_dev;
}
}
if (shost->transportt->create_work_queue) {
snprintf(shost->work_q_name, sizeof(shost->work_q_name),
"scsi_wq_%d", shost->host_no);
shost->work_q = create_singlethread_workqueue(
shost->work_q_name);
if (!shost->work_q) {
error = -EINVAL;
goto out_free_shost_data;
}
}
error = scsi_sysfs_add_host(shost);
if (error)
goto out_destroy_host;
scsi_proc_host_add(shost);
return error;
out_destroy_host:
if (shost->work_q)
destroy_workqueue(shost->work_q);
out_free_shost_data:
kfree(shost->shost_data);
out_del_dev:
device_del(&shost->shost_dev);
out_del_gendev:
device_del(&shost->shost_gendev);
out:
scsi_destroy_command_freelist(shost);
fail:
return error;
}
static void scsi_host_dev_release(struct device *dev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct device *parent = dev->parent;
scsi_proc_hostdir_rm(shost->hostt);
if (shost->ehandler)
kthread_stop(shost->ehandler);
if (shost->work_q)
destroy_workqueue(shost->work_q);
if (shost->uspace_req_q) {
kfree(shost->uspace_req_q->queuedata);
scsi_free_queue(shost->uspace_req_q);
}
scsi_destroy_command_freelist(shost);
if (shost->bqt)
blk_free_tags(shost->bqt);
kfree(shost->shost_data);
if (parent)
put_device(parent);
kfree(shost);
}
struct Scsi_Host *scsi_host_alloc(struct scsi_host_template *sht, int privsize)
{
struct Scsi_Host *shost;
gfp_t gfp_mask = GFP_KERNEL;
if (sht->unchecked_isa_dma && privsize)
gfp_mask |= __GFP_DMA;
shost = kzalloc(sizeof(struct Scsi_Host) + privsize, gfp_mask);
if (!shost)
return NULL;
shost->host_lock = &shost->default_lock;
spin_lock_init(shost->host_lock);
shost->shost_state = SHOST_CREATED;
INIT_LIST_HEAD(&shost->__devices);
INIT_LIST_HEAD(&shost->__targets);
INIT_LIST_HEAD(&shost->eh_cmd_q);
INIT_LIST_HEAD(&shost->starved_list);
init_waitqueue_head(&shost->host_wait);
mutex_init(&shost->scan_mutex);
shost->host_no = atomic_inc_return(&scsi_host_next_hn) - 1;
shost->dma_channel = 0xff;
shost->max_channel = 0;
shost->max_id = 8;
shost->max_lun = 8;
shost->transportt = &blank_transport_template;
shost->max_cmd_len = 12;
shost->hostt = sht;
shost->this_id = sht->this_id;
shost->can_queue = sht->can_queue;
shost->sg_tablesize = sht->sg_tablesize;
shost->sg_prot_tablesize = sht->sg_prot_tablesize;
shost->cmd_per_lun = sht->cmd_per_lun;
shost->unchecked_isa_dma = sht->unchecked_isa_dma;
shost->use_clustering = sht->use_clustering;
shost->ordered_tag = sht->ordered_tag;
if (sht->supported_mode == MODE_UNKNOWN)
shost->active_mode = MODE_INITIATOR;
else
shost->active_mode = sht->supported_mode;
if (sht->max_host_blocked)
shost->max_host_blocked = sht->max_host_blocked;
else
shost->max_host_blocked = SCSI_DEFAULT_HOST_BLOCKED;
if (sht->max_sectors)
shost->max_sectors = sht->max_sectors;
else
shost->max_sectors = SCSI_DEFAULT_MAX_SECTORS;
if (sht->dma_boundary)
shost->dma_boundary = sht->dma_boundary;
else
shost->dma_boundary = 0xffffffff;
device_initialize(&shost->shost_gendev);
dev_set_name(&shost->shost_gendev, "host%d", shost->host_no);
shost->shost_gendev.bus = &scsi_bus_type;
shost->shost_gendev.type = &scsi_host_type;
device_initialize(&shost->shost_dev);
shost->shost_dev.parent = &shost->shost_gendev;
shost->shost_dev.class = &shost_class;
dev_set_name(&shost->shost_dev, "host%d", shost->host_no);
shost->shost_dev.groups = scsi_sysfs_shost_attr_groups;
shost->ehandler = kthread_run(scsi_error_handler, shost,
"scsi_eh_%d", shost->host_no);
if (IS_ERR(shost->ehandler)) {
printk(KERN_WARNING "scsi%d: error handler thread failed to spawn, error = %ld\n",
shost->host_no, PTR_ERR(shost->ehandler));
goto fail_kfree;
}
scsi_proc_hostdir_add(shost->hostt);
return shost;
fail_kfree:
kfree(shost);
return NULL;
}
struct Scsi_Host *scsi_register(struct scsi_host_template *sht, int privsize)
{
struct Scsi_Host *shost = scsi_host_alloc(sht, privsize);
if (!sht->detect) {
printk(KERN_WARNING "scsi_register() called on new-style "
"template for driver %s\n", sht->name);
dump_stack();
}
if (shost)
list_add_tail(&shost->sht_legacy_list, &sht->legacy_hosts);
return shost;
}
void scsi_unregister(struct Scsi_Host *shost)
{
list_del(&shost->sht_legacy_list);
scsi_host_put(shost);
}
static int __scsi_host_match(struct device *dev, void *data)
{
struct Scsi_Host *p;
unsigned short *hostnum = (unsigned short *)data;
p = class_to_shost(dev);
return p->host_no == *hostnum;
}
struct Scsi_Host *scsi_host_lookup(unsigned short hostnum)
{
struct device *cdev;
struct Scsi_Host *shost = NULL;
cdev = class_find_device(&shost_class, NULL, &hostnum,
__scsi_host_match);
if (cdev) {
shost = scsi_host_get(class_to_shost(cdev));
put_device(cdev);
}
return shost;
}
struct Scsi_Host *scsi_host_get(struct Scsi_Host *shost)
{
if ((shost->shost_state == SHOST_DEL) ||
!get_device(&shost->shost_gendev))
return NULL;
return shost;
}
void scsi_host_put(struct Scsi_Host *shost)
{
put_device(&shost->shost_gendev);
}
int scsi_init_hosts(void)
{
return class_register(&shost_class);
}
void scsi_exit_hosts(void)
{
class_unregister(&shost_class);
}
int scsi_is_host_device(const struct device *dev)
{
return dev->type == &scsi_host_type;
}
int scsi_queue_work(struct Scsi_Host *shost, struct work_struct *work)
{
if (unlikely(!shost->work_q)) {
printk(KERN_ERR
"ERROR: Scsi host '%s' attempted to queue scsi-work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return -EINVAL;
}
return queue_work(shost->work_q, work);
}
void scsi_flush_work(struct Scsi_Host *shost)
{
if (!shost->work_q) {
printk(KERN_ERR
"ERROR: Scsi host '%s' attempted to flush scsi-work, "
"when no workqueue created.\n", shost->hostt->name);
dump_stack();
return;
}
flush_workqueue(shost->work_q);
}
