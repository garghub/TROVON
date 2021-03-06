static void vmlogrdr_iucv_path_complete(struct iucv_path *path, u8 ipuser[16])
{
struct vmlogrdr_priv_t * logptr = path->private;
spin_lock(&logptr->priv_lock);
logptr->connection_established = 1;
spin_unlock(&logptr->priv_lock);
wake_up(&conn_wait_queue);
}
static void vmlogrdr_iucv_path_severed(struct iucv_path *path, u8 ipuser[16])
{
struct vmlogrdr_priv_t * logptr = path->private;
u8 reason = (u8) ipuser[8];
pr_err("vmlogrdr: connection severed with reason %i\n", reason);
iucv_path_sever(path, NULL);
kfree(path);
logptr->path = NULL;
spin_lock(&logptr->priv_lock);
logptr->connection_established = 0;
logptr->iucv_path_severed = 1;
spin_unlock(&logptr->priv_lock);
wake_up(&conn_wait_queue);
wake_up_interruptible(&read_wait_queue);
}
static void vmlogrdr_iucv_message_pending(struct iucv_path *path,
struct iucv_message *msg)
{
struct vmlogrdr_priv_t * logptr = path->private;
spin_lock(&logptr->priv_lock);
memcpy(&logptr->local_interrupt_buffer, msg, sizeof(*msg));
atomic_inc(&logptr->receive_ready);
spin_unlock(&logptr->priv_lock);
wake_up_interruptible(&read_wait_queue);
}
static int vmlogrdr_get_recording_class_AB(void)
{
static const char cp_command[] = "QUERY COMMAND RECORDING ";
char cp_response[80];
char *tail;
int len,i;
cpcmd(cp_command, cp_response, sizeof(cp_response), NULL);
len = strnlen(cp_response,sizeof(cp_response));
tail=strnchr(cp_response,len,'=');
if (!tail)
return 0;
tail++;
if (!strncmp("ANY",tail,3))
return 1;
if (!strncmp("NONE",tail,4))
return 0;
for (i=tail-cp_response; i<len; i++)
if ( cp_response[i]=='A' || cp_response[i]=='B' )
return 1;
return 0;
}
static int vmlogrdr_recording(struct vmlogrdr_priv_t * logptr,
int action, int purge)
{
char cp_command[80];
char cp_response[160];
char *onoff, *qid_string;
int rc;
onoff = ((action == 1) ? "ON" : "OFF");
qid_string = ((recording_class_AB == 1) ? " QID * " : "");
if (purge && (action == 1)) {
memset(cp_command, 0x00, sizeof(cp_command));
memset(cp_response, 0x00, sizeof(cp_response));
snprintf(cp_command, sizeof(cp_command),
"RECORDING %s PURGE %s",
logptr->recording_name,
qid_string);
cpcmd(cp_command, cp_response, sizeof(cp_response), NULL);
}
memset(cp_command, 0x00, sizeof(cp_command));
memset(cp_response, 0x00, sizeof(cp_response));
snprintf(cp_command, sizeof(cp_command), "RECORDING %s %s %s",
logptr->recording_name,
onoff,
qid_string);
cpcmd(cp_command, cp_response, sizeof(cp_response), NULL);
if (strstr(cp_response,"Command complete"))
rc = 0;
else
rc = -EIO;
if (purge && (action == 0)) {
memset(cp_command, 0x00, sizeof(cp_command));
memset(cp_response, 0x00, sizeof(cp_response));
snprintf(cp_command, sizeof(cp_command),
"RECORDING %s PURGE %s",
logptr->recording_name,
qid_string);
cpcmd(cp_command, cp_response, sizeof(cp_response), NULL);
}
return rc;
}
static int vmlogrdr_open (struct inode *inode, struct file *filp)
{
int dev_num = 0;
struct vmlogrdr_priv_t * logptr = NULL;
int connect_rc = 0;
int ret;
dev_num = iminor(inode);
if (dev_num > MAXMINOR)
return -ENODEV;
logptr = &sys_ser[dev_num];
if (filp->f_flags & O_NONBLOCK)
return -ENOSYS;
spin_lock_bh(&logptr->priv_lock);
if (logptr->dev_in_use) {
spin_unlock_bh(&logptr->priv_lock);
return -EBUSY;
}
logptr->dev_in_use = 1;
logptr->connection_established = 0;
logptr->iucv_path_severed = 0;
atomic_set(&logptr->receive_ready, 0);
logptr->buffer_free = 1;
spin_unlock_bh(&logptr->priv_lock);
filp->private_data = logptr;
filp->f_op = &vmlogrdr_fops;
if (logptr->autorecording) {
ret = vmlogrdr_recording(logptr,1,logptr->autopurge);
if (ret)
pr_warning("vmlogrdr: failed to start "
"recording automatically\n");
}
logptr->path = iucv_path_alloc(10, 0, GFP_KERNEL);
if (!logptr->path)
goto out_dev;
connect_rc = iucv_path_connect(logptr->path, &vmlogrdr_iucv_handler,
logptr->system_service, NULL, NULL,
logptr);
if (connect_rc) {
pr_err("vmlogrdr: iucv connection to %s "
"failed with rc %i \n",
logptr->system_service, connect_rc);
goto out_path;
}
wait_event(conn_wait_queue, (logptr->connection_established)
|| (logptr->iucv_path_severed));
if (logptr->iucv_path_severed)
goto out_record;
nonseekable_open(inode, filp);
return 0;
out_record:
if (logptr->autorecording)
vmlogrdr_recording(logptr,0,logptr->autopurge);
out_path:
kfree(logptr->path);
logptr->path = NULL;
out_dev:
logptr->dev_in_use = 0;
return -EIO;
}
static int vmlogrdr_release (struct inode *inode, struct file *filp)
{
int ret;
struct vmlogrdr_priv_t * logptr = filp->private_data;
iucv_path_sever(logptr->path, NULL);
kfree(logptr->path);
logptr->path = NULL;
if (logptr->autorecording) {
ret = vmlogrdr_recording(logptr,0,logptr->autopurge);
if (ret)
pr_warning("vmlogrdr: failed to stop "
"recording automatically\n");
}
logptr->dev_in_use = 0;
return 0;
}
static int vmlogrdr_receive_data(struct vmlogrdr_priv_t *priv)
{
int rc, *temp;
int user_data_count, iucv_data_count;
char * buffer;
if (atomic_read(&priv->receive_ready)) {
spin_lock_bh(&priv->priv_lock);
if (priv->residual_length){
iucv_data_count = priv->residual_length;
user_data_count = 0;
buffer = priv->buffer;
} else {
iucv_data_count = priv->local_interrupt_buffer.length;
user_data_count = sizeof(int);
temp = (int*)priv->buffer;
*temp= iucv_data_count + sizeof(FENCE);
buffer = priv->buffer + sizeof(int);
}
if (iucv_data_count > NET_BUFFER_SIZE)
iucv_data_count = NET_BUFFER_SIZE;
rc = iucv_message_receive(priv->path,
&priv->local_interrupt_buffer,
0, buffer, iucv_data_count,
&priv->residual_length);
spin_unlock_bh(&priv->priv_lock);
if (rc == 5)
rc = 0;
if (rc == 9)
atomic_set(&priv->receive_ready, 0);
} else {
rc = 1;
}
if (!rc) {
priv->buffer_free = 0;
user_data_count += iucv_data_count;
priv->current_position = priv->buffer;
if (priv->residual_length == 0){
atomic_dec(&priv->receive_ready);
buffer = priv->buffer + user_data_count;
memcpy(buffer, FENCE, sizeof(FENCE));
user_data_count += sizeof(FENCE);
}
priv->remaining = user_data_count;
}
return rc;
}
static ssize_t vmlogrdr_read(struct file *filp, char __user *data,
size_t count, loff_t * ppos)
{
int rc;
struct vmlogrdr_priv_t * priv = filp->private_data;
while (priv->buffer_free) {
rc = vmlogrdr_receive_data(priv);
if (rc) {
rc = wait_event_interruptible(read_wait_queue,
atomic_read(&priv->receive_ready));
if (rc)
return rc;
}
}
if (count > priv->remaining)
count = priv->remaining;
if (copy_to_user(data, priv->current_position, count))
return -EFAULT;
*ppos += count;
priv->current_position += count;
priv->remaining -= count;
if (priv->remaining == 0)
priv->buffer_free = 1;
return count;
}
static ssize_t vmlogrdr_autopurge_store(struct device * dev,
struct device_attribute *attr,
const char * buf, size_t count)
{
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
ssize_t ret = count;
switch (buf[0]) {
case '0':
priv->autopurge=0;
break;
case '1':
priv->autopurge=1;
break;
default:
ret = -EINVAL;
}
return ret;
}
static ssize_t vmlogrdr_autopurge_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", priv->autopurge);
}
static ssize_t vmlogrdr_purge_store(struct device * dev,
struct device_attribute *attr,
const char * buf, size_t count)
{
char cp_command[80];
char cp_response[80];
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
if (buf[0] != '1')
return -EINVAL;
memset(cp_command, 0x00, sizeof(cp_command));
memset(cp_response, 0x00, sizeof(cp_response));
if (recording_class_AB)
snprintf(cp_command, sizeof(cp_command),
"RECORDING %s PURGE QID * ",
priv->recording_name);
else
snprintf(cp_command, sizeof(cp_command),
"RECORDING %s PURGE ",
priv->recording_name);
cpcmd(cp_command, cp_response, sizeof(cp_response), NULL);
return count;
}
static ssize_t vmlogrdr_autorecording_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
ssize_t ret = count;
switch (buf[0]) {
case '0':
priv->autorecording=0;
break;
case '1':
priv->autorecording=1;
break;
default:
ret = -EINVAL;
}
return ret;
}
static ssize_t vmlogrdr_autorecording_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", priv->autorecording);
}
static ssize_t vmlogrdr_recording_store(struct device * dev,
struct device_attribute *attr,
const char * buf, size_t count)
{
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
ssize_t ret;
switch (buf[0]) {
case '0':
ret = vmlogrdr_recording(priv,0,0);
break;
case '1':
ret = vmlogrdr_recording(priv,1,0);
break;
default:
ret = -EINVAL;
}
if (ret)
return ret;
else
return count;
}
static ssize_t vmlogrdr_recording_status_show(struct device_driver *driver,
char *buf)
{
static const char cp_command[] = "QUERY RECORDING ";
int len;
cpcmd(cp_command, buf, 4096, NULL);
len = strlen(buf);
return len;
}
static int vmlogrdr_pm_prepare(struct device *dev)
{
int rc;
struct vmlogrdr_priv_t *priv = dev_get_drvdata(dev);
rc = 0;
if (priv) {
spin_lock_bh(&priv->priv_lock);
if (priv->dev_in_use)
rc = -EBUSY;
spin_unlock_bh(&priv->priv_lock);
}
if (rc)
pr_err("vmlogrdr: device %s is busy. Refuse to suspend.\n",
dev_name(dev));
return rc;
}
static int vmlogrdr_register_driver(void)
{
int ret;
ret = iucv_register(&vmlogrdr_iucv_handler, 1);
if (ret)
goto out;
ret = driver_register(&vmlogrdr_driver);
if (ret)
goto out_iucv;
ret = driver_create_file(&vmlogrdr_driver,
&driver_attr_recording_status);
if (ret)
goto out_driver;
vmlogrdr_class = class_create(THIS_MODULE, "vmlogrdr");
if (IS_ERR(vmlogrdr_class)) {
ret = PTR_ERR(vmlogrdr_class);
vmlogrdr_class = NULL;
goto out_attr;
}
return 0;
out_attr:
driver_remove_file(&vmlogrdr_driver, &driver_attr_recording_status);
out_driver:
driver_unregister(&vmlogrdr_driver);
out_iucv:
iucv_unregister(&vmlogrdr_iucv_handler, 1);
out:
return ret;
}
static void vmlogrdr_unregister_driver(void)
{
class_destroy(vmlogrdr_class);
vmlogrdr_class = NULL;
driver_remove_file(&vmlogrdr_driver, &driver_attr_recording_status);
driver_unregister(&vmlogrdr_driver);
iucv_unregister(&vmlogrdr_iucv_handler, 1);
}
static int vmlogrdr_register_device(struct vmlogrdr_priv_t *priv)
{
struct device *dev;
int ret;
dev = kzalloc(sizeof(struct device), GFP_KERNEL);
if (dev) {
dev_set_name(dev, priv->internal_name);
dev->bus = &iucv_bus;
dev->parent = iucv_root;
dev->driver = &vmlogrdr_driver;
dev_set_drvdata(dev, priv);
dev->release = (void (*)(struct device *))kfree;
} else
return -ENOMEM;
ret = device_register(dev);
if (ret) {
put_device(dev);
return ret;
}
ret = sysfs_create_group(&dev->kobj, &vmlogrdr_attr_group);
if (ret) {
device_unregister(dev);
return ret;
}
priv->class_device = device_create(vmlogrdr_class, dev,
MKDEV(vmlogrdr_major,
priv->minor_num),
priv, "%s", dev_name(dev));
if (IS_ERR(priv->class_device)) {
ret = PTR_ERR(priv->class_device);
priv->class_device=NULL;
sysfs_remove_group(&dev->kobj, &vmlogrdr_attr_group);
device_unregister(dev);
return ret;
}
priv->device = dev;
return 0;
}
static int vmlogrdr_unregister_device(struct vmlogrdr_priv_t *priv)
{
device_destroy(vmlogrdr_class, MKDEV(vmlogrdr_major, priv->minor_num));
if (priv->device != NULL) {
sysfs_remove_group(&priv->device->kobj, &vmlogrdr_attr_group);
device_unregister(priv->device);
priv->device=NULL;
}
return 0;
}
static int vmlogrdr_register_cdev(dev_t dev)
{
int rc = 0;
vmlogrdr_cdev = cdev_alloc();
if (!vmlogrdr_cdev) {
return -ENOMEM;
}
vmlogrdr_cdev->owner = THIS_MODULE;
vmlogrdr_cdev->ops = &vmlogrdr_fops;
vmlogrdr_cdev->dev = dev;
rc = cdev_add(vmlogrdr_cdev, vmlogrdr_cdev->dev, MAXMINOR);
if (!rc)
return 0;
kobject_put(&vmlogrdr_cdev->kobj);
vmlogrdr_cdev=NULL;
return rc;
}
static void vmlogrdr_cleanup(void)
{
int i;
if (vmlogrdr_cdev) {
cdev_del(vmlogrdr_cdev);
vmlogrdr_cdev=NULL;
}
for (i=0; i < MAXMINOR; ++i ) {
vmlogrdr_unregister_device(&sys_ser[i]);
free_page((unsigned long)sys_ser[i].buffer);
}
vmlogrdr_unregister_driver();
if (vmlogrdr_major) {
unregister_chrdev_region(MKDEV(vmlogrdr_major, 0), MAXMINOR);
vmlogrdr_major=0;
}
}
static int __init vmlogrdr_init(void)
{
int rc;
int i;
dev_t dev;
if (! MACHINE_IS_VM) {
pr_err("not running under VM, driver not loaded.\n");
return -ENODEV;
}
recording_class_AB = vmlogrdr_get_recording_class_AB();
rc = alloc_chrdev_region(&dev, 0, MAXMINOR, "vmlogrdr");
if (rc)
return rc;
vmlogrdr_major = MAJOR(dev);
rc=vmlogrdr_register_driver();
if (rc)
goto cleanup;
for (i=0; i < MAXMINOR; ++i ) {
sys_ser[i].buffer = (char *) get_zeroed_page(GFP_KERNEL);
if (!sys_ser[i].buffer) {
rc = -ENOMEM;
break;
}
sys_ser[i].current_position = sys_ser[i].buffer;
rc=vmlogrdr_register_device(&sys_ser[i]);
if (rc)
break;
}
if (rc)
goto cleanup;
rc = vmlogrdr_register_cdev(dev);
if (rc)
goto cleanup;
return 0;
cleanup:
vmlogrdr_cleanup();
return rc;
}
static void __exit vmlogrdr_exit(void)
{
vmlogrdr_cleanup();
return;
}
