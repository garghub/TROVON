static int
lprocfs_fid_write_common(const char *buffer, unsigned long count,
struct lu_seq_range *range)
{
struct lu_seq_range tmp;
int rc;
LASSERT(range != NULL);
rc = sscanf(buffer, "[%llx - %llx]\n",
(long long unsigned *)&tmp.lsr_start,
(long long unsigned *)&tmp.lsr_end);
if (rc != 2 || !range_is_sane(&tmp) || range_is_zero(&tmp))
return -EINVAL;
*range = tmp;
return 0;
}
static ssize_t
lprocfs_fid_space_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq = ((struct seq_file *)file->private_data)->private;
int rc;
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
rc = seq_printf(m, "["LPX64" - "LPX64"]:%x:%s\n", PRANGE(&seq->lcs_space));
mutex_unlock(&seq->lcs_mutex);
return rc;
}
static ssize_t
lprocfs_fid_width_seq_write(struct file *file, const char *buffer,
size_t count, loff_t *off)
{
struct lu_client_seq *seq = ((struct seq_file *)file->private_data)->private;
__u64 max;
int rc, val;
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
CDEBUG(D_INFO, "%s: Sequence size: "LPU64"\n",
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
rc = seq_printf(m, LPU64"\n", seq->lcs_width);
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
