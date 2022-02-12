static ssize_t active_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
return sprintf(buf, "%u\n", !dev->u.cli.cl_import->imp_deactive);
}
static ssize_t active_store(struct kobject *kobj, struct attribute *attr,
const char *buffer, size_t count)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
unsigned long val;
int rc;
rc = kstrtoul(buffer, 10, &val);
if (rc)
return rc;
if (val > 1)
return -ERANGE;
if (dev->u.cli.cl_import->imp_deactive == val) {
rc = ptlrpc_set_import_active(dev->u.cli.cl_import, val);
if (rc)
count = rc;
} else {
CDEBUG(D_CONFIG, "activate %lu: ignoring repeat request\n", val);
}
return count;
}
static ssize_t max_rpcs_in_flight_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
int len;
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
__u32 max;
max = obd_get_max_rpcs_in_flight(&dev->u.cli);
len = sprintf(buf, "%u\n", max);
return len;
}
static ssize_t max_rpcs_in_flight_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer,
size_t count)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
int rc;
unsigned long val;
rc = kstrtoul(buffer, 10, &val);
if (rc)
return rc;
rc = obd_set_max_rpcs_in_flight(&dev->u.cli, val);
if (rc)
count = rc;
return count;
}
static ssize_t max_mod_rpcs_in_flight_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
u16 max;
int len;
max = dev->u.cli.cl_max_mod_rpcs_in_flight;
len = sprintf(buf, "%hu\n", max);
return len;
}
static ssize_t max_mod_rpcs_in_flight_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer,
size_t count)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
u16 val;
int rc;
rc = kstrtou16(buffer, 10, &val);
if (rc)
return rc;
rc = obd_set_max_mod_rpcs_in_flight(&dev->u.cli, val);
if (rc)
count = rc;
return count;
}
static int mdc_rpc_stats_seq_show(struct seq_file *seq, void *v)
{
struct obd_device *dev = seq->private;
return obd_mod_rpc_stats_seq_show(&dev->u.cli, seq);
}
static ssize_t mdc_rpc_stats_seq_write(struct file *file,
const char __user *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct obd_device *dev = seq->private;
struct client_obd *cli = &dev->u.cli;
lprocfs_oh_clear(&cli->cl_mod_rpcs_hist);
return len;
}
static ssize_t max_pages_per_rpc_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct client_obd *cli = &dev->u.cli;
return sprintf(buf, "%d\n", cli->cl_max_pages_per_rpc);
}
void lprocfs_mdc_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->sysfs_vars = &mdc_attr_group;
lvars->obd_vars = lprocfs_mdc_obd_vars;
}
