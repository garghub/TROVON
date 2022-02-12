static int mdc_max_rpcs_in_flight_seq_show(struct seq_file *m, void *v)
{
struct obd_device *dev = m->private;
struct client_obd *cli = &dev->u.cli;
client_obd_list_lock(&cli->cl_loi_list_lock);
seq_printf(m, "%u\n", cli->cl_max_rpcs_in_flight);
client_obd_list_unlock(&cli->cl_loi_list_lock);
return 0;
}
static ssize_t mdc_max_rpcs_in_flight_seq_write(struct file *file,
const char __user *buffer,
size_t count,
loff_t *off)
{
struct obd_device *dev =
((struct seq_file *)file->private_data)->private;
struct client_obd *cli = &dev->u.cli;
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
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
return single_open(file, NULL, PDE_DATA(inode));
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
OBD_ALLOC(lh, len);
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
OBD_FREE(lh, len);
if (rc < 0)
return rc;
return count;
}
static int mdc_obd_max_pages_per_rpc_seq_show(struct seq_file *m, void *v)
{
return lprocfs_obd_rd_max_pages_per_rpc(m, m->private);
}
void lprocfs_mdc_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = lprocfs_mdc_module_vars;
lvars->obd_vars = lprocfs_mdc_obd_vars;
}
