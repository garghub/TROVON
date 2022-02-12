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
static int mdc_kuc_open(struct inode *inode, struct file *file)
{
return single_open(file, NULL, inode->i_private);
}
static ssize_t mdc_kuc_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct obd_device *obd =
((struct seq_file *)file->private_data)->private;
struct kuc_hdr *lh;
struct hsm_action_list *hal;
struct hsm_action_item *hai;
int len;
int fd, rc;
rc = lprocfs_write_helper(buffer, count, &fd);
if (rc)
return rc;
if (fd < 0)
return -ERANGE;
CWARN("message to fd %d\n", fd);
len = sizeof(*lh) + sizeof(*hal) + MTI_NAME_MAXLEN +
2 * cfs_size_round(sizeof(*hai));
lh = kzalloc(len, GFP_NOFS);
if (!lh)
return -ENOMEM;
lh->kuc_magic = KUC_MAGIC;
lh->kuc_transport = KUC_TRANSPORT_HSM;
lh->kuc_msgtype = HMT_ACTION_LIST;
lh->kuc_msglen = len;
hal = (struct hsm_action_list *)(lh + 1);
hal->hal_version = HAL_VERSION;
hal->hal_archive_id = 1;
hal->hal_flags = 0;
obd_uuid2fsname(hal->hal_fsname, obd->obd_name, MTI_NAME_MAXLEN);
hal->hal_count = 2;
hai = hai_zero(hal);
hai->hai_action = HSMA_ARCHIVE;
hai->hai_fid.f_oid = 5;
hai->hai_len = sizeof(*hai);
hai = hai_next(hai);
hai->hai_action = HSMA_RESTORE;
hai->hai_fid.f_oid = 10;
hai->hai_len = sizeof(*hai);
if (fd == 0) {
rc = libcfs_kkuc_group_put(KUC_GRP_HSM, lh);
} else {
struct file *fp = fget(fd);
rc = libcfs_kkuc_msg_put(fp, lh);
fput(fp);
}
kfree(lh);
if (rc < 0)
return rc;
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
