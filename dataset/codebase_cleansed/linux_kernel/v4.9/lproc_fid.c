static int
ldebugfs_fid_write_common(const char __user *buffer, size_t count,
struct lu_seq_range *range)
{
struct lu_seq_range tmp;
int rc;
char kernbuf[MAX_FID_RANGE_STRLEN];
LASSERT(range);
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
if (rc != 2)
return -EINVAL;
if (!range_is_sane(&tmp) || range_is_zero(&tmp) ||
tmp.lsr_start < range->lsr_start || tmp.lsr_end > range->lsr_end)
return -EINVAL;
*range = tmp;
return count;
}
static ssize_t
ldebugfs_fid_space_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq;
int rc;
seq = ((struct seq_file *)file->private_data)->private;
mutex_lock(&seq->lcs_mutex);
rc = ldebugfs_fid_write_common(buffer, count, &seq->lcs_space);
if (rc == 0) {
CDEBUG(D_INFO, "%s: Space: " DRANGE "\n",
seq->lcs_name, PRANGE(&seq->lcs_space));
}
mutex_unlock(&seq->lcs_mutex);
return count;
}
static int
ldebugfs_fid_space_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
mutex_lock(&seq->lcs_mutex);
seq_printf(m, "[%#llx - %#llx]:%x:%s\n", PRANGE(&seq->lcs_space));
mutex_unlock(&seq->lcs_mutex);
return 0;
}
static ssize_t
ldebugfs_fid_width_seq_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq;
__u64 max;
int rc, val;
seq = ((struct seq_file *)file->private_data)->private;
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
CDEBUG(D_INFO, "%s: Sequence size: %llu\n", seq->lcs_name,
seq->lcs_width);
}
mutex_unlock(&seq->lcs_mutex);
return count;
}
static int
ldebugfs_fid_width_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
mutex_lock(&seq->lcs_mutex);
seq_printf(m, "%llu\n", seq->lcs_width);
mutex_unlock(&seq->lcs_mutex);
return 0;
}
static int
ldebugfs_fid_fid_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
mutex_lock(&seq->lcs_mutex);
seq_printf(m, DFID "\n", PFID(&seq->lcs_fid));
mutex_unlock(&seq->lcs_mutex);
return 0;
}
static int
ldebugfs_fid_server_seq_show(struct seq_file *m, void *unused)
{
struct lu_client_seq *seq = (struct lu_client_seq *)m->private;
struct client_obd *cli;
if (seq->lcs_exp) {
cli = &seq->lcs_exp->exp_obd->u.cli;
seq_printf(m, "%s\n", cli->cl_target_uuid.uuid);
}
return 0;
}
