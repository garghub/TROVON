int obd_ioctl_getdata(char **buf, int *len, void __user *arg)
{
struct obd_ioctl_hdr hdr;
struct obd_ioctl_data *data;
int err;
int offset = 0;
if (copy_from_user(&hdr, arg, sizeof(hdr)))
return -EFAULT;
if (hdr.ioc_version != OBD_IOCTL_VERSION) {
CERROR("Version mismatch kernel (%x) vs application (%x)\n",
OBD_IOCTL_VERSION, hdr.ioc_version);
return -EINVAL;
}
if (hdr.ioc_len > OBD_MAX_IOCTL_BUFFER) {
CERROR("User buffer len %d exceeds %d max buffer\n",
hdr.ioc_len, OBD_MAX_IOCTL_BUFFER);
return -EINVAL;
}
if (hdr.ioc_len < sizeof(struct obd_ioctl_data)) {
CERROR("User buffer too small for ioctl (%d)\n", hdr.ioc_len);
return -EINVAL;
}
*buf = libcfs_kvzalloc(hdr.ioc_len, GFP_NOFS);
if (!*buf) {
CERROR("Cannot allocate control buffer of len %d\n",
hdr.ioc_len);
return -EINVAL;
}
*len = hdr.ioc_len;
data = (struct obd_ioctl_data *)*buf;
if (copy_from_user(*buf, arg, hdr.ioc_len)) {
err = -EFAULT;
goto free_buf;
}
if (hdr.ioc_len != data->ioc_len) {
err = -EINVAL;
goto free_buf;
}
if (obd_ioctl_is_invalid(data)) {
CERROR("ioctl not correctly formatted\n");
err = -EINVAL;
goto free_buf;
}
if (data->ioc_inllen1) {
data->ioc_inlbuf1 = &data->ioc_bulk[0];
offset += cfs_size_round(data->ioc_inllen1);
}
if (data->ioc_inllen2) {
data->ioc_inlbuf2 = &data->ioc_bulk[0] + offset;
offset += cfs_size_round(data->ioc_inllen2);
}
if (data->ioc_inllen3) {
data->ioc_inlbuf3 = &data->ioc_bulk[0] + offset;
offset += cfs_size_round(data->ioc_inllen3);
}
if (data->ioc_inllen4)
data->ioc_inlbuf4 = &data->ioc_bulk[0] + offset;
return 0;
free_buf:
kvfree(*buf);
return err;
}
int obd_ioctl_popdata(void __user *arg, void *data, int len)
{
int err;
err = copy_to_user(arg, data, len);
if (err)
err = -EFAULT;
return err;
}
static int obd_class_open(struct inode *inode, struct file *file)
{
try_module_get(THIS_MODULE);
return 0;
}
static int obd_class_release(struct inode *inode, struct file *file)
{
module_put(THIS_MODULE);
return 0;
}
static long obd_class_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
int err = 0;
if (!capable(CFS_CAP_SYS_ADMIN) && (cmd != OBD_IOC_PING_TARGET))
return err = -EACCES;
if ((cmd & 0xffffff00) == ((int)'T') << 8)
return err = -ENOTTY;
err = class_handle_ioctl(cmd, (unsigned long)arg);
return err;
}
static ssize_t version_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", LUSTRE_VERSION_STRING);
}
static ssize_t pinger_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", "on");
}
static ssize_t health_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
bool healthy = true;
int i;
size_t len = 0;
if (libcfs_catastrophe)
return sprintf(buf, "LBUG\n");
read_lock(&obd_dev_lock);
for (i = 0; i < class_devno_max(); i++) {
struct obd_device *obd;
obd = class_num2obd(i);
if (!obd || !obd->obd_attached || !obd->obd_set_up)
continue;
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
if (obd->obd_stopping)
continue;
class_incref(obd, __func__, current);
read_unlock(&obd_dev_lock);
if (obd_health_check(NULL, obd))
healthy = false;
class_decref(obd, __func__, current);
read_lock(&obd_dev_lock);
}
read_unlock(&obd_dev_lock);
if (healthy)
len = sprintf(buf, "healthy\n");
else
len = sprintf(buf, "NOT HEALTHY\n");
return len;
}
static ssize_t jobid_var_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", obd_jobid_var);
}
static ssize_t jobid_var_store(struct kobject *kobj, struct attribute *attr,
const char *buffer,
size_t count)
{
if (!count || count > JOBSTATS_JOBID_VAR_MAX_LEN)
return -EINVAL;
memset(obd_jobid_var, 0, JOBSTATS_JOBID_VAR_MAX_LEN + 1);
memcpy(obd_jobid_var, buffer, count);
if (obd_jobid_var[count - 1] == '\n')
obd_jobid_var[count - 1] = 0;
return count;
}
static ssize_t jobid_name_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", obd_jobid_node);
}
static ssize_t jobid_name_store(struct kobject *kobj, struct attribute *attr,
const char *buffer,
size_t count)
{
if (!count || count > JOBSTATS_JOBID_SIZE)
return -EINVAL;
memcpy(obd_jobid_node, buffer, count);
obd_jobid_node[count] = 0;
if (obd_jobid_node[count - 1] == '\n')
obd_jobid_node[count - 1] = 0;
return count;
}
static void *obd_device_list_seq_start(struct seq_file *p, loff_t *pos)
{
if (*pos >= class_devno_max())
return NULL;
return pos;
}
static void obd_device_list_seq_stop(struct seq_file *p, void *v)
{
}
static void *obd_device_list_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
++*pos;
if (*pos >= class_devno_max())
return NULL;
return pos;
}
static int obd_device_list_seq_show(struct seq_file *p, void *v)
{
loff_t index = *(loff_t *)v;
struct obd_device *obd = class_num2obd((int)index);
char *status;
if (!obd)
return 0;
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
if (obd->obd_stopping)
status = "ST";
else if (obd->obd_inactive)
status = "IN";
else if (obd->obd_set_up)
status = "UP";
else if (obd->obd_attached)
status = "AT";
else
status = "--";
seq_printf(p, "%3d %s %s %s %s %d\n",
(int)index, status, obd->obd_type->typ_name,
obd->obd_name, obd->obd_uuid.uuid,
atomic_read(&obd->obd_refcount));
return 0;
}
static int obd_device_list_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc = seq_open(file, &obd_device_list_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = inode->i_private;
return 0;
}
int class_procfs_init(void)
{
int rc = -ENOMEM;
struct dentry *file;
lustre_kobj = kobject_create_and_add("lustre", fs_kobj);
if (!lustre_kobj)
goto out;
rc = sysfs_create_group(lustre_kobj, &lustre_attr_group);
if (rc) {
kobject_put(lustre_kobj);
goto out;
}
debugfs_lustre_root = debugfs_create_dir("lustre", NULL);
if (IS_ERR_OR_NULL(debugfs_lustre_root)) {
rc = debugfs_lustre_root ? PTR_ERR(debugfs_lustre_root)
: -ENOMEM;
debugfs_lustre_root = NULL;
kobject_put(lustre_kobj);
goto out;
}
file = debugfs_create_file("devices", 0444, debugfs_lustre_root, NULL,
&obd_device_list_fops);
if (IS_ERR_OR_NULL(file)) {
rc = file ? PTR_ERR(file) : -ENOMEM;
kobject_put(lustre_kobj);
goto out;
}
out:
return rc;
}
int class_procfs_clean(void)
{
debugfs_remove_recursive(debugfs_lustre_root);
debugfs_lustre_root = NULL;
kobject_put(lustre_kobj);
return 0;
}
