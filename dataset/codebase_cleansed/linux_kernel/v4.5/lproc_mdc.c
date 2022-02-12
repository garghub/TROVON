static ssize_t max_rpcs_in_flight_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
int len;
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct client_obd *cli = &dev->u.cli;
client_obd_list_lock(&cli->cl_loi_list_lock);
len = sprintf(buf, "%u\n", cli->cl_max_rpcs_in_flight);
client_obd_list_unlock(&cli->cl_loi_list_lock);
return len;
}
static ssize_t max_rpcs_in_flight_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer,
size_t count)
{
struct obd_device *dev = container_of(kobj, struct obd_device,
obd_kobj);
struct client_obd *cli = &dev->u.cli;
int rc;
unsigned long val;
rc = kstrtoul(buffer, 10, &val);
if (rc)
return rc;
if (val < 1 || val > MDC_MAX_RIF_MAX)
return -ERANGE;
client_obd_list_lock(&cli->cl_loi_list_lock);
cli->cl_max_rpcs_in_flight = val;
client_obd_list_unlock(&cli->cl_loi_list_lock);
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
