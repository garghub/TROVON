static unsigned job_stat_hash(cfs_hash_t *hs, const void *key, unsigned mask)
{
return cfs_hash_djb2_hash(key, strlen(key), mask);
}
static void *job_stat_key(struct hlist_node *hnode)
{
struct job_stat *job;
job = hlist_entry(hnode, struct job_stat, js_hash);
return job->js_jobid;
}
static int job_stat_keycmp(const void *key, struct hlist_node *hnode)
{
struct job_stat *job;
job = hlist_entry(hnode, struct job_stat, js_hash);
return (strlen(job->js_jobid) == strlen(key)) &&
!strncmp(job->js_jobid, key, strlen(key));
}
static void *job_stat_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct job_stat, js_hash);
}
static void job_stat_get(cfs_hash_t *hs, struct hlist_node *hnode)
{
struct job_stat *job;
job = hlist_entry(hnode, struct job_stat, js_hash);
atomic_inc(&job->js_refcount);
}
static void job_free(struct job_stat *job)
{
LASSERT(atomic_read(&job->js_refcount) == 0);
LASSERT(job->js_jobstats);
write_lock(&job->js_jobstats->ojs_lock);
list_del_init(&job->js_list);
write_unlock(&job->js_jobstats->ojs_lock);
lprocfs_free_stats(&job->js_stats);
OBD_FREE_PTR(job);
}
static void job_putref(struct job_stat *job)
{
LASSERT(atomic_read(&job->js_refcount) > 0);
if (atomic_dec_and_test(&job->js_refcount))
job_free(job);
}
static void job_stat_put_locked(cfs_hash_t *hs, struct hlist_node *hnode)
{
struct job_stat *job;
job = hlist_entry(hnode, struct job_stat, js_hash);
job_putref(job);
}
static void job_stat_exit(cfs_hash_t *hs, struct hlist_node *hnode)
{
CERROR("Should not have any items!");
}
static int job_iter_callback(cfs_hash_t *hs, cfs_hash_bd_t *bd,
struct hlist_node *hnode, void *data)
{
time_t oldest = *((time_t *)data);
struct job_stat *job;
job = hlist_entry(hnode, struct job_stat, js_hash);
if (!oldest || job->js_timestamp < oldest)
cfs_hash_bd_del_locked(hs, bd, hnode);
return 0;
}
static void lprocfs_job_cleanup(struct obd_job_stats *stats, bool force)
{
time_t oldest, now;
if (stats->ojs_cleanup_interval == 0)
return;
now = cfs_time_current_sec();
if (!force && now < stats->ojs_last_cleanup +
stats->ojs_cleanup_interval)
return;
oldest = now - stats->ojs_cleanup_interval;
cfs_hash_for_each_safe(stats->ojs_hash, job_iter_callback,
&oldest);
stats->ojs_last_cleanup = cfs_time_current_sec();
}
static struct job_stat *job_alloc(char *jobid, struct obd_job_stats *jobs)
{
struct job_stat *job;
LASSERT(jobs->ojs_cntr_num && jobs->ojs_cntr_init_fn);
OBD_ALLOC_PTR(job);
if (job == NULL)
return NULL;
job->js_stats = lprocfs_alloc_stats(jobs->ojs_cntr_num, 0);
if (job->js_stats == NULL) {
OBD_FREE_PTR(job);
return NULL;
}
jobs->ojs_cntr_init_fn(job->js_stats);
memcpy(job->js_jobid, jobid, JOBSTATS_JOBID_SIZE);
job->js_timestamp = cfs_time_current_sec();
job->js_jobstats = jobs;
INIT_HLIST_NODE(&job->js_hash);
INIT_LIST_HEAD(&job->js_list);
atomic_set(&job->js_refcount, 1);
return job;
}
int lprocfs_job_stats_log(struct obd_device *obd, char *jobid,
int event, long amount)
{
struct obd_job_stats *stats = &obd->u.obt.obt_jobstats;
struct job_stat *job, *job2;
ENTRY;
LASSERT(stats && stats->ojs_hash);
lprocfs_job_cleanup(stats, false);
if (!jobid || !strlen(jobid))
RETURN(-EINVAL);
if (strlen(jobid) >= JOBSTATS_JOBID_SIZE) {
CERROR("Invalid jobid size (%lu), expect(%d)\n",
(unsigned long)strlen(jobid) + 1, JOBSTATS_JOBID_SIZE);
RETURN(-EINVAL);
}
job = cfs_hash_lookup(stats->ojs_hash, jobid);
if (job)
goto found;
job = job_alloc(jobid, stats);
if (job == NULL)
RETURN(-ENOMEM);
job2 = cfs_hash_findadd_unique(stats->ojs_hash, job->js_jobid,
&job->js_hash);
if (job2 != job) {
job_putref(job);
job = job2;
} else {
LASSERT(list_empty(&job->js_list));
write_lock(&stats->ojs_lock);
list_add_tail(&job->js_list, &stats->ojs_list);
write_unlock(&stats->ojs_lock);
}
found:
LASSERT(stats == job->js_jobstats);
LASSERT(stats->ojs_cntr_num > event);
job->js_timestamp = cfs_time_current_sec();
lprocfs_counter_add(job->js_stats, event, amount);
job_putref(job);
RETURN(0);
}
void lprocfs_job_stats_fini(struct obd_device *obd)
{
struct obd_job_stats *stats = &obd->u.obt.obt_jobstats;
time_t oldest = 0;
if (stats->ojs_hash == NULL)
return;
cfs_hash_for_each_safe(stats->ojs_hash, job_iter_callback, &oldest);
cfs_hash_putref(stats->ojs_hash);
stats->ojs_hash = NULL;
LASSERT(list_empty(&stats->ojs_list));
}
static void *lprocfs_jobstats_seq_start(struct seq_file *p, loff_t *pos)
{
struct obd_job_stats *stats = p->private;
loff_t off = *pos;
struct job_stat *job;
read_lock(&stats->ojs_lock);
if (off == 0)
return SEQ_START_TOKEN;
off--;
list_for_each_entry(job, &stats->ojs_list, js_list) {
if (!off--)
return job;
}
return NULL;
}
static void lprocfs_jobstats_seq_stop(struct seq_file *p, void *v)
{
struct obd_job_stats *stats = p->private;
read_unlock(&stats->ojs_lock);
}
static void *lprocfs_jobstats_seq_next(struct seq_file *p, void *v, loff_t *pos)
{
struct obd_job_stats *stats = p->private;
struct job_stat *job;
struct list_head *next;
++*pos;
if (v == SEQ_START_TOKEN) {
next = stats->ojs_list.next;
} else {
job = (struct job_stat *)v;
next = job->js_list.next;
}
return next == &stats->ojs_list ? NULL :
list_entry(next, struct job_stat, js_list);
}
static int inline width(const char *str, int len)
{
return len - min((int)strlen(str), 15);
}
static int lprocfs_jobstats_seq_show(struct seq_file *p, void *v)
{
struct job_stat *job = v;
struct lprocfs_stats *s;
struct lprocfs_counter ret;
struct lprocfs_counter *cntr;
struct lprocfs_counter_header *cntr_header;
int i;
if (v == SEQ_START_TOKEN) {
seq_printf(p, "job_stats:\n");
return 0;
}
seq_printf(p, "- %-16s %s\n", "job_id:", job->js_jobid);
seq_printf(p, " %-16s %ld\n", "snapshot_time:", job->js_timestamp);
s = job->js_stats;
for (i = 0; i < s->ls_num; i++) {
cntr = lprocfs_stats_counter_get(s, 0, i);
cntr_header = &s->ls_cnt_header[i];
lprocfs_stats_collect(s, i, &ret);
seq_printf(p, " %s:%.*s { samples: %11"LPF64"u",
cntr_header->lc_name,
width(cntr_header->lc_name, 15), spaces,
ret.lc_count);
if (cntr_header->lc_units[0] != '\0')
seq_printf(p, ", unit: %5s", cntr_header->lc_units);
if (cntr_header->lc_config & LPROCFS_CNTR_AVGMINMAX) {
seq_printf(p, ", min:%8"LPF64"u, max:%8"LPF64"u,"
" sum:%16"LPF64"u",
ret.lc_count ? ret.lc_min : 0,
ret.lc_count ? ret.lc_max : 0,
ret.lc_count ? ret.lc_sum : 0);
}
if (cntr_header->lc_config & LPROCFS_CNTR_STDDEV) {
seq_printf(p, ", sumsq: %18"LPF64"u",
ret.lc_count ? ret.lc_sumsquare : 0);
}
seq_printf(p, " }\n");
}
return 0;
}
static int lprocfs_jobstats_seq_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rc;
rc = seq_open(file, &lprocfs_jobstats_seq_sops);
if (rc)
return rc;
seq = file->private_data;
seq->private = PDE_DATA(inode);
return 0;
}
static ssize_t lprocfs_jobstats_seq_write(struct file *file, const char *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
struct obd_job_stats *stats = seq->private;
char jobid[JOBSTATS_JOBID_SIZE];
int all = 0;
struct job_stat *job;
if (!memcmp(buf, "clear", strlen("clear"))) {
all = 1;
} else if (len < JOBSTATS_JOBID_SIZE) {
memset(jobid, 0, JOBSTATS_JOBID_SIZE);
if (buf[len - 1] == '\n')
memcpy(jobid, buf, len - 1);
else
memcpy(jobid, buf, len);
} else {
return -EINVAL;
}
LASSERT(stats->ojs_hash);
if (all) {
time_t oldest = 0;
cfs_hash_for_each_safe(stats->ojs_hash, job_iter_callback,
&oldest);
return len;
}
if (!strlen(jobid))
return -EINVAL;
job = cfs_hash_lookup(stats->ojs_hash, jobid);
if (!job)
return -EINVAL;
cfs_hash_del_key(stats->ojs_hash, jobid);
job_putref(job);
return len;
}
int lprocfs_job_stats_init(struct obd_device *obd, int cntr_num,
cntr_init_callback init_fn)
{
struct proc_dir_entry *entry;
struct obd_job_stats *stats;
ENTRY;
LASSERT(obd->obd_proc_entry != NULL);
LASSERT(obd->obd_type->typ_name);
if (strcmp(obd->obd_type->typ_name, LUSTRE_MDT_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_OST_NAME)) {
CERROR("Invalid obd device type.\n");
RETURN(-EINVAL);
}
stats = &obd->u.obt.obt_jobstats;
LASSERT(stats->ojs_hash == NULL);
stats->ojs_hash = cfs_hash_create("JOB_STATS",
HASH_JOB_STATS_CUR_BITS,
HASH_JOB_STATS_MAX_BITS,
HASH_JOB_STATS_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&job_stats_hash_ops,
CFS_HASH_DEFAULT);
if (stats->ojs_hash == NULL)
RETURN(-ENOMEM);
INIT_LIST_HEAD(&stats->ojs_list);
rwlock_init(&stats->ojs_lock);
stats->ojs_cntr_num = cntr_num;
stats->ojs_cntr_init_fn = init_fn;
stats->ojs_cleanup_interval = 600;
stats->ojs_last_cleanup = cfs_time_current_sec();
entry = proc_create_data("job_stats", 0644, obd->obd_proc_entry,
&lprocfs_jobstats_seq_fops, stats);
if (entry)
RETURN(0);
else
RETURN(-ENOMEM);
}
int lprocfs_rd_job_interval(struct seq_file *m, void *data)
{
struct obd_device *obd = (struct obd_device *)data;
struct obd_job_stats *stats;
LASSERT(obd != NULL);
stats = &obd->u.obt.obt_jobstats;
return seq_printf(m, "%d\n", stats->ojs_cleanup_interval);
}
int lprocfs_wr_job_interval(struct file *file, const char *buffer,
unsigned long count, void *data)
{
struct obd_device *obd = (struct obd_device *)data;
struct obd_job_stats *stats;
int val, rc;
LASSERT(obd != NULL);
stats = &obd->u.obt.obt_jobstats;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc)
return rc;
stats->ojs_cleanup_interval = val;
lprocfs_job_cleanup(stats, true);
return count;
}
