static int lprocfs_fid_write_common(const char __user *buffer, size_t count,
struct lu_seq_range *range)
{
struct lu_seq_range tmp;
int rc;
char kernbuf[MAX_FID_RANGE_STRLEN];
LASSERT(range != NULL);
if (count >= sizeof(kernbuf))
return -EINVAL;
if (copy_from_user(kernbuf, buffer, count))
return -EFAULT;
kernbuf[count] = 0;
if (count == 5 && strcmp(kernbuf, "clear") == 0) {
memset(range, 0, sizeof(*range));
return count;
}
rc = sscanf(kernbuf, "[%llx - %llx]\n",
(unsigned long long *)&tmp.lsr_start,
(unsigned long long *)&tmp.lsr_end);
if (!range_is_sane(&tmp) || range_is_zero(&tmp) ||
tmp.lsr_start < range->lsr_start || tmp.lsr_end > range->lsr_end)
return -EINVAL;
*range = tmp;
return count;
}
static ssize_t lprocfs_fid_space_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq;
int rc;
seq = ((struct seq_file *)file->private_data)->private;
LASSERT(seq != NULL);
mutex_lock(&seq->lcs_mutex);
rc = lprocfs_fid_write_common(buffer, count, &seq->lcs_space);
if (rc == 0) {
CDEBUG(D_INFO, "%s: Space: "DRANGE"\n",
seq->lcs_name, PRANGE(&seq->lcs_space));
}
mutex_unlock(&seq->lcs_mutex);
return count;
}
static int
lprocfs_fid_space_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
int rc;
LASSERT(seq != NULL);
mutex_lock(&seq->lcs_mutex);
rc = seq_printf(m, "[%#llx - %#llx]:%x:%s\n", PRANGE(&seq->lcs_space));
mutex_unlock(&seq->lcs_mutex);
return rc;
}
static ssize_t lprocfs_fid_width_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq;
__u64 max;
int rc, val;
seq = ((struct seq_file *)file->private_data)->private;
LASSERT(seq != NULL);
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
mutex_lock(&seq->lcs_mutex);
if (seq->lcs_type == LUSTRE_SEQ_DATA)
max = LUSTRE_DATA_SEQ_MAX_WIDTH;
else
max = LUSTRE_METADATA_SEQ_MAX_WIDTH;
if (val <= max && val > 0) {
seq->lcs_width = val;
if (rc == 0) {
CDEBUG(D_INFO, "%s: Sequence size: %llu\n",
seq->lcs_name, seq->lcs_width);
}
}
mutex_unlock(&seq->lcs_mutex);
return count;
}
static int
lprocfs_fid_width_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
int rc;
LASSERT(seq != NULL);
mutex_lock(&seq->lcs_mutex);
rc = seq_printf(m, "%llu\n", seq->lcs_width);
mutex_unlock(&seq->lcs_mutex);
return rc;
}
static int
lprocfs_fid_fid_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
int rc;
LASSERT(seq != NULL);
mutex_lock(&seq->lcs_mutex);
rc = seq_printf(m, DFID"\n", PFID(&seq->lcs_fid));
mutex_unlock(&seq->lcs_mutex);
return rc;
}
static int
lprocfs_fid_server_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
struct client_obd *cli;
int rc;
LASSERT(seq != NULL);
if (seq->lcs_exp != NULL) {
cli = &seq->lcs_exp->exp_obd->u.cli;
rc = seq_printf(m, "%s\n", cli->cl_target_uuid.uuid);
} else {
rc = seq_printf(m, "%s\n", seq->lcs_srv->lss_name);
}
return rc;
}
