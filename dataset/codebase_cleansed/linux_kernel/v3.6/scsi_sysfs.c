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
static int check_set(unsigned int *val, char *src)
{
char *last;
if (strncmp(src, "-", 20) == 0) {
*val = SCAN_WILD_CARD;
} else {
*val = simple_strtoul(src, &last, 0);
if (*last != '\0')
return 1;
}
return 0;
}
static int scsi_scan(struct Scsi_Host *shost, const char *str)
{
char s1[15], s2[15], s3[15], junk;
unsigned int channel, id, lun;
int res;
res = sscanf(str, "%10s %10s %10s %c", s1, s2, s3, &junk);
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
res = scsi_scan_host_selected(shost, channel, id, lun, 1);
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
static int check_reset_type(char *str)
{
if (strncmp(str, "adapter", 10) == 0)
return SCSI_ADAPTER_RESET;
else if (strncmp(str, "firmware", 10) == 0)
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
char str[10];
int type;
sscanf(buf, "%s", str);
type = check_reset_type(str);
if (!type)
goto exit_store_host_reset;
if (sht->host_reset)
ret = sht->host_reset(shost, type);
exit_store_host_reset:
if (ret == 0)
ret = count;
return ret;
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
struct scsi_target *starget;
struct list_head *this, *tmp;
unsigned long flags;
sdev = container_of(work, struct scsi_device, ew.work);
parent = sdev->sdev_gendev.parent;
starget = to_scsi_target(parent);
spin_lock_irqsave(sdev->host->host_lock, flags);
starget->reap_ref++;
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
scsi_target_reap(scsi_target(sdev));
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
store_rescan_field (struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
scsi_rescan_device(dev);
return count;
}
static void sdev_store_delete_callback(struct device *dev)
{
scsi_remove_device(to_scsi_device(dev));
}
static ssize_t
sdev_store_delete(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int rc;
rc = device_schedule_callback(dev, sdev_store_delete_callback);
if (rc)
count = rc;
return count;
}
static ssize_t
store_state_field(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int i;
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
if (scsi_device_set_state(sdev, state))
return -EINVAL;
return count;
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
if (sdev->ordered_tags)
name = "ordered";
else if (sdev->simple_tags)
name = "simple";
return snprintf(buf, 20, "%s\n", name);
}
static ssize_t
show_iostat_counterbits(struct device *dev, struct device_attribute *attr, char *buf)
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
sdev_store_queue_depth_rw(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int depth, retval;
struct scsi_device *sdev = to_scsi_device(dev);
struct scsi_host_template *sht = sdev->host->hostt;
if (!sht->change_queue_depth)
return -EINVAL;
depth = simple_strtoul(buf, NULL, 0);
if (depth < 1)
return -EINVAL;
retval = sht->change_queue_depth(sdev, depth,
SCSI_QDEPTH_DEFAULT);
if (retval < 0)
return retval;
sdev->max_queue_depth = sdev->queue_depth;
return count;
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
unsigned long period;
if (strict_strtoul(buf, 10, &period))
return -EINVAL;
sdev->queue_ramp_up_period = msecs_to_jiffies(period);
return period;
}
static ssize_t
sdev_store_queue_type_rw(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
struct scsi_host_template *sht = sdev->host->hostt;
int tag_type = 0, retval;
int prev_tag_type = scsi_get_tag_type(sdev);
if (!sdev->tagged_supported || !sht->change_queue_type)
return -EINVAL;
if (strncmp(buf, "ordered", 7) == 0)
tag_type = MSG_ORDERED_TAG;
else if (strncmp(buf, "simple", 6) == 0)
tag_type = MSG_SIMPLE_TAG;
else if (strncmp(buf, "none", 4) != 0)
return -EINVAL;
if (tag_type == prev_tag_type)
return count;
retval = sht->change_queue_type(sdev, tag_type);
if (retval < 0)
return retval;
return count;
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
error = scsi_device_set_state(sdev, SDEV_RUNNING);
if (error)
return error;
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
error = device_add(&sdev->sdev_gendev);
if (error) {
sdev_printk(KERN_INFO, sdev,
"failed to add device: %d\n", error);
return error;
}
device_enable_async_suspend(&sdev->sdev_dev);
error = device_add(&sdev->sdev_dev);
if (error) {
sdev_printk(KERN_INFO, sdev,
"failed to add class device: %d\n", error);
device_del(&sdev->sdev_gendev);
return error;
}
transport_add_device(&sdev->sdev_gendev);
sdev->is_visible = 1;
if (sdev->host->hostt->change_queue_depth) {
error = device_create_file(&sdev->sdev_gendev,
&sdev_attr_queue_depth_rw);
error = device_create_file(&sdev->sdev_gendev,
&sdev_attr_queue_ramp_up_period);
}
else
error = device_create_file(&sdev->sdev_gendev, &dev_attr_queue_depth);
if (error)
return error;
if (sdev->host->hostt->change_queue_type)
error = device_create_file(&sdev->sdev_gendev, &sdev_attr_queue_type_rw);
else
error = device_create_file(&sdev->sdev_gendev, &dev_attr_queue_type);
if (error)
return error;
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
return error;
}
void __scsi_remove_device(struct scsi_device *sdev)
{
struct device *dev = &sdev->sdev_gendev;
if (sdev->is_visible) {
if (scsi_device_set_state(sdev, SDEV_CANCEL) != 0)
return;
bsg_unregister_queue(sdev->request_queue);
device_unregister(&sdev->sdev_dev);
transport_remove_device(dev);
device_del(dev);
} else
put_device(&sdev->sdev_dev);
scsi_device_set_state(sdev, SDEV_DEL);
blk_cleanup_queue(sdev->request_queue);
cancel_work_sync(&sdev->requeue_work);
if (sdev->host->hostt->slave_destroy)
sdev->host->hostt->slave_destroy(sdev);
transport_destroy_device(dev);
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
scsi_device_get(sdev))
continue;
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_remove_device(sdev);
scsi_device_put(sdev);
spin_lock_irqsave(shost->host_lock, flags);
goto restart;
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
void scsi_remove_target(struct device *dev)
{
struct Scsi_Host *shost = dev_to_shost(dev->parent);
struct scsi_target *starget, *found;
unsigned long flags;
restart:
found = NULL;
spin_lock_irqsave(shost->host_lock, flags);
list_for_each_entry(starget, &shost->__targets, siblings) {
if (starget->state == STARGET_DEL)
continue;
if (starget->dev.parent == dev || &starget->dev == dev) {
found = starget;
found->reap_ref++;
break;
}
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (found) {
__scsi_remove_target(found);
scsi_target_reap(found);
goto restart;
}
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
dev_set_name(&sdev->sdev_gendev, "%d:%d:%d:%d",
sdev->host->host_no, sdev->channel, sdev->id, sdev->lun);
device_initialize(&sdev->sdev_dev);
sdev->sdev_dev.parent = get_device(&sdev->sdev_gendev);
sdev->sdev_dev.class = &sdev_class;
dev_set_name(&sdev->sdev_dev, "%d:%d:%d:%d",
sdev->host->host_no, sdev->channel, sdev->id, sdev->lun);
sdev->scsi_level = starget->scsi_level;
transport_setup_device(&sdev->sdev_gendev);
spin_lock_irqsave(shost->host_lock, flags);
list_add_tail(&sdev->same_target_siblings, &starget->devices);
list_add_tail(&sdev->siblings, &shost->__devices);
spin_unlock_irqrestore(shost->host_lock, flags);
}
int scsi_is_sdev_device(const struct device *dev)
{
return dev->type == &scsi_dev_type;
}
