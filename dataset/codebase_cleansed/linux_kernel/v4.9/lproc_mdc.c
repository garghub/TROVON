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
