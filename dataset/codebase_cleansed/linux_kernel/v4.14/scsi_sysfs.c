const char *scsi_device_state_name(enum scsi_device_state state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(sdev_states); i++) {
if (sdev_states[i].value == state) {
name = sdev_states[i].name;
break;
}
}
return name;
}
const char *scsi_host_state_name(enum scsi_host_state state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(shost_states); i++) {
if (shost_states[i].value == state) {
name = shost_states[i].name;
break;
}
}
return name;
}
static const char *scsi_access_state_name(unsigned char state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(sdev_access_states); i++) {
if (sdev_access_states[i].value == state) {
name = sdev_access_states[i].name;
break;
}
}
return name;
}
static int check_set(unsigned long long *val, char *src)
{
char *last;
if (strcmp(src, "-") == 0) {
*val = SCAN_WILD_CARD;
} else {
*val = simple_strtoull(src, &last, 0);
if (*last != '\0')
return 1;
}
return 0;
}
static int scsi_scan(struct Scsi_Host *shost, const char *str)
{
char s1[15], s2[15], s3[17], junk;
unsigned long long channel, id, lun;
int res;
res = sscanf(str, "%10s %10s %16s %c", s1, s2, s3, &junk);
if (res != 3)
return -EINVAL;
if (check_set(&channel, s1))
return -EINVAL;
if (check_set(&id, s2))
return -EINVAL;
if (check_set(&lun, s3))
return -EINVAL;
if (shost->transportt->user_scan)
res = shost->transportt->user_scan(shost, channel, id, lun);
else
res = scsi_scan_host_selected(shost, channel, id, lun,
SCSI_SCAN_MANUAL);
return res;
}
static ssize_t
store_scan(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
int res;
res = scsi_scan(shost, buf);
if (res == 0)
res = count;
return res;
}
static ssize_t
store_shost_state(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int i;
struct Scsi_Host *shost = class_to_shost(dev);
enum scsi_host_state state = 0;
for (i = 0; i < ARRAY_SIZE(shost_states); i++) {
const int len = strlen(shost_states[i].name);
if (strncmp(shost_states[i].name, buf, len) == 0 &&
buf[len] == '\n') {
state = shost_states[i].value;
break;
}
}
if (!state)
return -EINVAL;
if (scsi_host_set_state(shost, state))
return -EINVAL;
return count;
}
static ssize_t
show_shost_state(struct device *dev, struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
const char *name = scsi_host_state_name(shost->shost_state);
if (!name)
return -EINVAL;
return snprintf(buf, 20, "%s\n", name);
}
static ssize_t
show_shost_mode(unsigned int mode, char *buf)
{
ssize_t len = 0;
if (mode & MODE_INITIATOR)
len = sprintf(buf, "%s", "Initiator");
if (mode & MODE_TARGET)
len += sprintf(buf + len, "%s%s", len ? ", " : "", "Target");
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t
show_shost_supported_mode(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
unsigned int supported_mode = shost->hostt->supported_mode;
if (supported_mode == MODE_UNKNOWN)
supported_mode = MODE_INITIATOR;
return show_shost_mode(supported_mode, buf);
}
static ssize_t
show_shost_active_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
if (shost->active_mode == MODE_UNKNOWN)
return snprintf(buf, 20, "unknown\n");
else
return show_shost_mode(shost->active_mode, buf);
}
static int check_reset_type(const char *str)
{
if (sysfs_streq(str, "adapter"))
return SCSI_ADAPTER_RESET;
else if (sysfs_streq(str, "firmware"))
return SCSI_FIRMWARE_RESET;
else
return 0;
}
static ssize_t
store_host_reset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct scsi_host_template *sht = shost->hostt;
int ret = -EINVAL;
int type;
type = check_reset_type(buf);
if (!type)
goto exit_store_host_reset;
if (sht->host_reset)
ret = sht->host_reset(shost, type);
else
ret = -EOPNOTSUPP;
exit_store_host_reset:
if (ret == 0)
ret = count;
return ret;
}
static ssize_t
show_shost_eh_deadline(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
if (shost->eh_deadline == -1)
return snprintf(buf, strlen("off") + 2, "off\n");
return sprintf(buf, "%u\n", shost->eh_deadline / HZ);
}
static ssize_t
store_shost_eh_deadline(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
int ret = -EINVAL;
unsigned long deadline, flags;
if (shost->transportt &&
(shost->transportt->eh_strategy_handler ||
!shost->hostt->eh_host_reset_handler))
return ret;
if (!strncmp(buf, "off", strlen("off")))
deadline = -1;
else {
ret = kstrtoul(buf, 10, &deadline);
if (ret)
return ret;
if (deadline * HZ > UINT_MAX)
return -EINVAL;
}
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_in_recovery(shost))
ret = -EBUSY;
else {
if (deadline == -1)
shost->eh_deadline = -1;
else
shost->eh_deadline = deadline * HZ;
ret = count;
}
spin_unlock_irqrestore(shost->host_lock, flags);
return ret;
}
static ssize_t
show_host_busy(struct device *dev, struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
return snprintf(buf, 20, "%d\n", atomic_read(&shost->host_busy));
}
static void scsi_device_cls_release(struct device *class_dev)
{
struct scsi_device *sdev;
sdev = class_to_sdev(class_dev);
put_device(&sdev->sdev_gendev);
}
static void scsi_device_dev_release_usercontext(struct work_struct *work)
{
struct scsi_device *sdev;
struct device *parent;
struct list_head *this, *tmp;
struct scsi_vpd *vpd_pg80 = NULL, *vpd_pg83 = NULL;
unsigned long flags;
sdev = container_of(work, struct scsi_device, ew.work);
scsi_dh_release_device(sdev);
parent = sdev->sdev_gendev.parent;
spin_lock_irqsave(sdev->host->host_lock, flags);
list_del(&sdev->siblings);
list_del(&sdev->same_target_siblings);
list_del(&sdev->starved_entry);
spin_unlock_irqrestore(sdev->host->host_lock, flags);
cancel_work_sync(&sdev->event_work);
list_for_each_safe(this, tmp, &sdev->event_list) {
struct scsi_event *evt;
evt = list_entry(this, struct scsi_event, node);
list_del(&evt->node);
kfree(evt);
}
blk_put_queue(sdev->request_queue);
sdev->request_queue = NULL;
mutex_lock(&sdev->inquiry_mutex);
rcu_swap_protected(sdev->vpd_pg80, vpd_pg80,
lockdep_is_held(&sdev->inquiry_mutex));
rcu_swap_protected(sdev->vpd_pg83, vpd_pg83,
lockdep_is_held(&sdev->inquiry_mutex));
mutex_unlock(&sdev->inquiry_mutex);
if (vpd_pg83)
kfree_rcu(vpd_pg83, rcu);
if (vpd_pg80)
kfree_rcu(vpd_pg80, rcu);
kfree(sdev->inquiry);
kfree(sdev);
if (parent)
put_device(parent);
}
static void scsi_device_dev_release(struct device *dev)
{
struct scsi_device *sdp = to_scsi_device(dev);
execute_in_process_context(scsi_device_dev_release_usercontext,
&sdp->ew);
}
static int scsi_bus_match(struct device *dev, struct device_driver *gendrv)
{
struct scsi_device *sdp;
if (dev->type != &scsi_dev_type)
return 0;
sdp = to_scsi_device(dev);
if (sdp->no_uld_attach)
return 0;
return (sdp->inq_periph_qual == SCSI_INQ_PQ_CON)? 1: 0;
}
static int scsi_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct scsi_device *sdev;
if (dev->type != &scsi_dev_type)
return 0;
sdev = to_scsi_device(dev);
add_uevent_var(env, "MODALIAS=" SCSI_DEVICE_MODALIAS_FMT, sdev->type);
return 0;
}
int scsi_sysfs_register(void)
{
int error;
error = bus_register(&scsi_bus_type);
if (!error) {
error = class_register(&sdev_class);
if (error)
bus_unregister(&scsi_bus_type);
}
return error;
}
void scsi_sysfs_unregister(void)
{
class_unregister(&sdev_class);
bus_unregister(&scsi_bus_type);
}
static ssize_t
sdev_show_device_busy(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
return snprintf(buf, 20, "%d\n", atomic_read(&sdev->device_busy));
}
static ssize_t
sdev_show_device_blocked(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
return snprintf(buf, 20, "%d\n", atomic_read(&sdev->device_blocked));
}
static ssize_t
sdev_show_timeout (struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev;
sdev = to_scsi_device(dev);
return snprintf(buf, 20, "%d\n", sdev->request_queue->rq_timeout / HZ);
}
static ssize_t
sdev_store_timeout (struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev;
int timeout;
sdev = to_scsi_device(dev);
sscanf (buf, "%d\n", &timeout);
blk_queue_rq_timeout(sdev->request_queue, timeout * HZ);
return count;
}
static ssize_t
sdev_show_eh_timeout(struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev;
sdev = to_scsi_device(dev);
return snprintf(buf, 20, "%u\n", sdev->eh_timeout / HZ);
}
static ssize_t
sdev_store_eh_timeout(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev;
unsigned int eh_timeout;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
sdev = to_scsi_device(dev);
err = kstrtouint(buf, 10, &eh_timeout);
if (err)
return err;
sdev->eh_timeout = eh_timeout * HZ;
return count;
}
static ssize_t
store_rescan_field (struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
scsi_rescan_device(dev);
return count;
}
static ssize_t
sdev_store_delete(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
if (device_remove_file_self(dev, attr))
scsi_remove_device(to_scsi_device(dev));
return count;
}
static ssize_t
store_state_field(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int i, ret;
struct scsi_device *sdev = to_scsi_device(dev);
enum scsi_device_state state = 0;
for (i = 0; i < ARRAY_SIZE(sdev_states); i++) {
const int len = strlen(sdev_states[i].name);
if (strncmp(sdev_states[i].name, buf, len) == 0 &&
buf[len] == '\n') {
state = sdev_states[i].value;
break;
}
}
if (!state)
return -EINVAL;
mutex_lock(&sdev->state_mutex);
ret = scsi_device_set_state(sdev, state);
mutex_unlock(&sdev->state_mutex);
return ret == 0 ? count : -EINVAL;
}
static ssize_t
show_state_field(struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
const char *name = scsi_device_state_name(sdev->sdev_state);
if (!name)
return -EINVAL;
return snprintf(buf, 20, "%s\n", name);
}
static ssize_t
show_queue_type_field(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
const char *name = "none";
if (sdev->simple_tags)
name = "simple";
return snprintf(buf, 20, "%s\n", name);
}
static ssize_t
store_queue_type_field(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
if (!sdev->tagged_supported)
return -EINVAL;
sdev_printk(KERN_INFO, sdev,
"ignoring write to deprecated queue_type attribute");
return count;
}
static ssize_t show_inquiry(struct file *filep, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct scsi_device *sdev = to_scsi_device(dev);
if (!sdev->inquiry)
return -EINVAL;
return memory_read_from_buffer(buf, count, &off, sdev->inquiry,
sdev->inquiry_len);
}
static ssize_t
show_iostat_counterbits(struct device *dev, struct device_attribute *attr,
char *buf)
{
return snprintf(buf, 20, "%d\n", (int)sizeof(atomic_t) * 8);
}
static ssize_t
sdev_show_modalias(struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev;
sdev = to_scsi_device(dev);
return snprintf (buf, 20, SCSI_DEVICE_MODALIAS_FMT "\n", sdev->type);
}
static ssize_t
sdev_store_queue_depth(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int depth, retval;
struct scsi_device *sdev = to_scsi_device(dev);
struct scsi_host_template *sht = sdev->host->hostt;
if (!sht->change_queue_depth)
return -EINVAL;
depth = simple_strtoul(buf, NULL, 0);
if (depth < 1 || depth > sdev->host->can_queue)
return -EINVAL;
retval = sht->change_queue_depth(sdev, depth);
if (retval < 0)
return retval;
sdev->max_queue_depth = sdev->queue_depth;
return count;
}
static ssize_t
sdev_show_wwid(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
ssize_t count;
count = scsi_vpd_lun_id(sdev, buf, PAGE_SIZE);
if (count > 0) {
buf[count] = '\n';
count++;
}
return count;
}
static ssize_t
sdev_show_dh_state(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
if (!sdev->handler)
return snprintf(buf, 20, "detached\n");
return snprintf(buf, 20, "%s\n", sdev->handler->name);
}
static ssize_t
sdev_store_dh_state(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
int err = -EINVAL;
if (sdev->sdev_state == SDEV_CANCEL ||
sdev->sdev_state == SDEV_DEL)
return -ENODEV;
if (!sdev->handler) {
err = scsi_dh_attach(sdev->request_queue, buf);
} else if (!strncmp(buf, "activate", 8)) {
if (sdev->handler->activate)
err = sdev->handler->activate(sdev, NULL, NULL);
else
err = 0;
} else if (!strncmp(buf, "detach", 6)) {
sdev_printk(KERN_WARNING, sdev,
"can't detach handler %s.\n",
sdev->handler->name);
err = -EINVAL;
}
return err < 0 ? err : count;
}
static ssize_t
sdev_show_access_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
unsigned char access_state;
const char *access_state_name;
if (!sdev->handler)
return -EINVAL;
access_state = (sdev->access_state & SCSI_ACCESS_STATE_MASK);
access_state_name = scsi_access_state_name(access_state);
return sprintf(buf, "%s\n",
access_state_name ? access_state_name : "unknown");
}
static ssize_t
sdev_show_preferred_path(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
if (!sdev->handler)
return -EINVAL;
if (sdev->access_state & SCSI_ACCESS_STATE_PREFERRED)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t
sdev_show_queue_ramp_up_period(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev;
sdev = to_scsi_device(dev);
return snprintf(buf, 20, "%u\n",
jiffies_to_msecs(sdev->queue_ramp_up_period));
}
static ssize_t
sdev_store_queue_ramp_up_period(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
unsigned int period;
if (kstrtouint(buf, 10, &period))
return -EINVAL;
sdev->queue_ramp_up_period = msecs_to_jiffies(period);
return count;
}
static umode_t scsi_sdev_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct scsi_device *sdev = to_scsi_device(dev);
if (attr == &dev_attr_queue_depth.attr &&
!sdev->host->hostt->change_queue_depth)
return S_IRUGO;
if (attr == &dev_attr_queue_ramp_up_period.attr &&
!sdev->host->hostt->change_queue_depth)
return 0;
#ifdef CONFIG_SCSI_DH
if (attr == &dev_attr_access_state.attr &&
!sdev->handler)
return 0;
if (attr == &dev_attr_preferred_path.attr &&
!sdev->handler)
return 0;
#endif
return attr->mode;
}
static umode_t scsi_sdev_bin_attr_is_visible(struct kobject *kobj,
struct bin_attribute *attr, int i)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct scsi_device *sdev = to_scsi_device(dev);
if (attr == &dev_attr_vpd_pg80 && !sdev->vpd_pg80)
return 0;
if (attr == &dev_attr_vpd_pg83 && !sdev->vpd_pg83)
return 0;
return S_IRUGO;
}
static int scsi_target_add(struct scsi_target *starget)
{
int error;
if (starget->state != STARGET_CREATED)
return 0;
error = device_add(&starget->dev);
if (error) {
dev_err(&starget->dev, "target device_add failed, error %d\n", error);
return error;
}
transport_add_device(&starget->dev);
starget->state = STARGET_RUNNING;
pm_runtime_set_active(&starget->dev);
pm_runtime_enable(&starget->dev);
device_enable_async_suspend(&starget->dev);
return 0;
}
int scsi_sysfs_add_sdev(struct scsi_device *sdev)
{
int error, i;
struct request_queue *rq = sdev->request_queue;
struct scsi_target *starget = sdev->sdev_target;
error = scsi_target_add(starget);
if (error)
return error;
transport_configure_device(&starget->dev);
device_enable_async_suspend(&sdev->sdev_gendev);
scsi_autopm_get_target(starget);
pm_runtime_set_active(&sdev->sdev_gendev);
pm_runtime_forbid(&sdev->sdev_gendev);
pm_runtime_enable(&sdev->sdev_gendev);
scsi_autopm_put_target(starget);
scsi_autopm_get_device(sdev);
error = scsi_dh_add_device(sdev);
if (error)
sdev_printk(KERN_INFO, sdev,
"failed to add device handler: %d\n", error);
error = device_add(&sdev->sdev_gendev);
if (error) {
sdev_printk(KERN_INFO, sdev,
"failed to add device: %d\n", error);
scsi_dh_remove_device(sdev);
return error;
}
device_enable_async_suspend(&sdev->sdev_dev);
error = device_add(&sdev->sdev_dev);
if (error) {
sdev_printk(KERN_INFO, sdev,
"failed to add class device: %d\n", error);
scsi_dh_remove_device(sdev);
device_del(&sdev->sdev_gendev);
return error;
}
transport_add_device(&sdev->sdev_gendev);
sdev->is_visible = 1;
error = bsg_register_queue(rq, &sdev->sdev_gendev, NULL, NULL);
if (error)
sdev_printk(KERN_INFO, sdev,
"Failed to register bsg queue, errno=%d\n", error);
if (sdev->host->hostt->sdev_attrs) {
for (i = 0; sdev->host->hostt->sdev_attrs[i]; i++) {
error = device_create_file(&sdev->sdev_gendev,
sdev->host->hostt->sdev_attrs[i]);
if (error)
return error;
}
}
scsi_autopm_put_device(sdev);
return error;
}
void __scsi_remove_device(struct scsi_device *sdev)
{
struct device *dev = &sdev->sdev_gendev;
int res;
if (sdev->sdev_state == SDEV_DEL)
return;
if (sdev->is_visible) {
mutex_lock(&sdev->state_mutex);
res = scsi_device_set_state(sdev, SDEV_CANCEL);
if (res != 0) {
res = scsi_device_set_state(sdev, SDEV_DEL);
if (res == 0)
scsi_start_queue(sdev);
}
mutex_unlock(&sdev->state_mutex);
if (res != 0)
return;
bsg_unregister_queue(sdev->request_queue);
device_unregister(&sdev->sdev_dev);
transport_remove_device(dev);
scsi_dh_remove_device(sdev);
device_del(dev);
} else
put_device(&sdev->sdev_dev);
mutex_lock(&sdev->state_mutex);
scsi_device_set_state(sdev, SDEV_DEL);
mutex_unlock(&sdev->state_mutex);
blk_cleanup_queue(sdev->request_queue);
cancel_work_sync(&sdev->requeue_work);
if (sdev->host->hostt->slave_destroy)
sdev->host->hostt->slave_destroy(sdev);
transport_destroy_device(dev);
scsi_target_reap(scsi_target(sdev));
put_device(dev);
}
void scsi_remove_device(struct scsi_device *sdev)
{
struct Scsi_Host *shost = sdev->host;
mutex_lock(&shost->scan_mutex);
__scsi_remove_device(sdev);
mutex_unlock(&shost->scan_mutex);
}
static void __scsi_remove_target(struct scsi_target *starget)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
unsigned long flags;
struct scsi_device *sdev;
spin_lock_irqsave(shost->host_lock, flags);
restart:
list_for_each_entry(sdev, &shost->__devices, siblings) {
if (sdev->channel != starget->channel ||
sdev->id != starget->id ||
!get_device(&sdev->sdev_gendev))
continue;
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_remove_device(sdev);
put_device(&sdev->sdev_gendev);
spin_lock_irqsave(shost->host_lock, flags);
goto restart;
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
void scsi_remove_target(struct device *dev)
{
struct Scsi_Host *shost = dev_to_shost(dev->parent);
struct scsi_target *starget;
unsigned long flags;
restart:
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(starget, &shost->__targets, siblings) {
if (starget->state == STARGET_DEL ||
starget->state == STARGET_REMOVE ||
starget->state == STARGET_CREATED_REMOVE)
continue;
if (starget->dev.parent == dev || &starget->dev == dev) {
kref_get(&starget->reap_ref);
if (starget->state == STARGET_CREATED)
starget->state = STARGET_CREATED_REMOVE;
else
starget->state = STARGET_REMOVE;
spin_unlock_irqrestore(shost->host_lock, flags);
__scsi_remove_target(starget);
scsi_target_reap(starget);
goto restart;
}
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
int scsi_register_driver(struct device_driver *drv)
{
drv->bus = &scsi_bus_type;
return driver_register(drv);
}
int scsi_register_interface(struct class_interface *intf)
{
intf->class = &sdev_class;
return class_interface_register(intf);
}
int scsi_sysfs_add_host(struct Scsi_Host *shost)
{
int error, i;
if (shost->hostt->shost_attrs) {
for (i = 0; shost->hostt->shost_attrs[i]; i++) {
error = device_create_file(&shost->shost_dev,
shost->hostt->shost_attrs[i]);
if (error)
return error;
}
}
transport_register_device(&shost->shost_gendev);
transport_configure_device(&shost->shost_gendev);
return 0;
}
void scsi_sysfs_device_initialize(struct scsi_device *sdev)
{
unsigned long flags;
struct Scsi_Host *shost = sdev->host;
struct scsi_target *starget = sdev->sdev_target;
device_initialize(&sdev->sdev_gendev);
sdev->sdev_gendev.bus = &scsi_bus_type;
sdev->sdev_gendev.type = &scsi_dev_type;
dev_set_name(&sdev->sdev_gendev, "%d:%d:%d:%llu",
sdev->host->host_no, sdev->channel, sdev->id, sdev->lun);
device_initialize(&sdev->sdev_dev);
sdev->sdev_dev.parent = get_device(&sdev->sdev_gendev);
sdev->sdev_dev.class = &sdev_class;
dev_set_name(&sdev->sdev_dev, "%d:%d:%d:%llu",
sdev->host->host_no, sdev->channel, sdev->id, sdev->lun);
sdev->scsi_level = starget->scsi_level;
if (sdev->scsi_level <= SCSI_2 &&
sdev->scsi_level != SCSI_UNKNOWN &&
!shost->no_scsi2_lun_in_cdb)
sdev->lun_in_cdb = 1;
transport_setup_device(&sdev->sdev_gendev);
spin_lock_irqsave(shost->host_lock, flags);
list_add_tail(&sdev->same_target_siblings, &starget->devices);
list_add_tail(&sdev->siblings, &shost->__devices);
spin_unlock_irqrestore(shost->host_lock, flags);
kref_get(&starget->reap_ref);
}
int scsi_is_sdev_device(const struct device *dev)
{
return dev->type == &scsi_dev_type;
}
