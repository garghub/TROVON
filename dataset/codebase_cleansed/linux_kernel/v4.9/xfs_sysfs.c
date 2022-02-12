static inline struct xfs_sysfs_attr *
to_attr(struct attribute *attr)
{
return container_of(attr, struct xfs_sysfs_attr, attr);
}
STATIC ssize_t
xfs_sysfs_object_show(
struct kobject *kobject,
struct attribute *attr,
char *buf)
{
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->show ? xfs_attr->show(kobject, buf) : 0;
}
STATIC ssize_t
xfs_sysfs_object_store(
struct kobject *kobject,
struct attribute *attr,
const char *buf,
size_t count)
{
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->store ? xfs_attr->store(kobject, buf, count) : 0;
}
static inline struct xfs_mount *
to_mp(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xfs_mount, m_kobj);
}
STATIC ssize_t
fail_writes_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
struct xfs_mount *mp = to_mp(kobject);
int ret;
int val;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val == 1)
mp->m_fail_writes = true;
else if (val == 0)
mp->m_fail_writes = false;
else
return -EINVAL;
return count;
}
STATIC ssize_t
fail_writes_show(
struct kobject *kobject,
char *buf)
{
struct xfs_mount *mp = to_mp(kobject);
return snprintf(buf, PAGE_SIZE, "%d\n", mp->m_fail_writes ? 1 : 0);
}
STATIC ssize_t
log_recovery_delay_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
int ret;
int val;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val < 0 || val > 60)
return -EINVAL;
xfs_globals.log_recovery_delay = val;
return count;
}
STATIC ssize_t
log_recovery_delay_show(
struct kobject *kobject,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", xfs_globals.log_recovery_delay);
}
static inline struct xstats *
to_xstats(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xstats, xs_kobj);
}
STATIC ssize_t
stats_show(
struct kobject *kobject,
char *buf)
{
struct xstats *stats = to_xstats(kobject);
return xfs_stats_format(stats->xs_stats, buf);
}
STATIC ssize_t
stats_clear_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
int ret;
int val;
struct xstats *stats = to_xstats(kobject);
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val != 1)
return -EINVAL;
xfs_stats_clearall(stats->xs_stats);
return count;
}
static inline struct xlog *
to_xlog(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xlog, l_kobj);
}
STATIC ssize_t
log_head_lsn_show(
struct kobject *kobject,
char *buf)
{
int cycle;
int block;
struct xlog *log = to_xlog(kobject);
spin_lock(&log->l_icloglock);
cycle = log->l_curr_cycle;
block = log->l_curr_block;
spin_unlock(&log->l_icloglock);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, block);
}
STATIC ssize_t
log_tail_lsn_show(
struct kobject *kobject,
char *buf)
{
int cycle;
int block;
struct xlog *log = to_xlog(kobject);
xlog_crack_atomic_lsn(&log->l_tail_lsn, &cycle, &block);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, block);
}
STATIC ssize_t
reserve_grant_head_show(
struct kobject *kobject,
char *buf)
{
int cycle;
int bytes;
struct xlog *log = to_xlog(kobject);
xlog_crack_grant_head(&log->l_reserve_head.grant, &cycle, &bytes);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, bytes);
}
STATIC ssize_t
write_grant_head_show(
struct kobject *kobject,
char *buf)
{
int cycle;
int bytes;
struct xlog *log = to_xlog(kobject);
xlog_crack_grant_head(&log->l_write_head.grant, &cycle, &bytes);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, bytes);
}
STATIC ssize_t
log_badcrc_factor_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
struct xlog *log = to_xlog(kobject);
int ret;
uint32_t val;
ret = kstrtouint(buf, 0, &val);
if (ret)
return ret;
log->l_badcrc_factor = val;
return count;
}
STATIC ssize_t
log_badcrc_factor_show(
struct kobject *kobject,
char *buf)
{
struct xlog *log = to_xlog(kobject);
return snprintf(buf, PAGE_SIZE, "%d\n", log->l_badcrc_factor);
}
static inline struct xfs_error_cfg *
to_error_cfg(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xfs_error_cfg, kobj);
}
static inline struct xfs_mount *
err_to_mp(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xfs_mount, m_error_kobj);
}
static ssize_t
max_retries_show(
struct kobject *kobject,
char *buf)
{
int retries;
struct xfs_error_cfg *cfg = to_error_cfg(kobject);
if (cfg->retry_timeout == XFS_ERR_RETRY_FOREVER)
retries = -1;
else
retries = cfg->max_retries;
return snprintf(buf, PAGE_SIZE, "%d\n", retries);
}
static ssize_t
max_retries_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
struct xfs_error_cfg *cfg = to_error_cfg(kobject);
int ret;
int val;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val < -1)
return -EINVAL;
if (val == -1)
cfg->retry_timeout = XFS_ERR_RETRY_FOREVER;
else
cfg->max_retries = val;
return count;
}
static ssize_t
retry_timeout_seconds_show(
struct kobject *kobject,
char *buf)
{
int timeout;
struct xfs_error_cfg *cfg = to_error_cfg(kobject);
if (cfg->retry_timeout == XFS_ERR_RETRY_FOREVER)
timeout = -1;
else
timeout = jiffies_to_msecs(cfg->retry_timeout) / MSEC_PER_SEC;
return snprintf(buf, PAGE_SIZE, "%d\n", timeout);
}
static ssize_t
retry_timeout_seconds_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
struct xfs_error_cfg *cfg = to_error_cfg(kobject);
int ret;
int val;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val < -1 || val > 86400)
return -EINVAL;
if (val == -1)
cfg->retry_timeout = XFS_ERR_RETRY_FOREVER;
else {
cfg->retry_timeout = msecs_to_jiffies(val * MSEC_PER_SEC);
ASSERT(msecs_to_jiffies(val * MSEC_PER_SEC) < LONG_MAX);
}
return count;
}
static ssize_t
fail_at_unmount_show(
struct kobject *kobject,
char *buf)
{
struct xfs_mount *mp = err_to_mp(kobject);
return snprintf(buf, PAGE_SIZE, "%d\n", mp->m_fail_unmount);
}
static ssize_t
fail_at_unmount_store(
struct kobject *kobject,
const char *buf,
size_t count)
{
struct xfs_mount *mp = err_to_mp(kobject);
int ret;
int val;
ret = kstrtoint(buf, 0, &val);
if (ret)
return ret;
if (val < 0 || val > 1)
return -EINVAL;
mp->m_fail_unmount = val;
return count;
}
static int
xfs_error_sysfs_init_class(
struct xfs_mount *mp,
int class,
const char *parent_name,
struct xfs_kobj *parent_kobj,
const struct xfs_error_init init[])
{
struct xfs_error_cfg *cfg;
int error;
int i;
ASSERT(class < XFS_ERR_CLASS_MAX);
error = xfs_sysfs_init(parent_kobj, &xfs_error_ktype,
&mp->m_error_kobj, parent_name);
if (error)
return error;
for (i = 0; i < XFS_ERR_ERRNO_MAX; i++) {
cfg = &mp->m_error_cfg[class][i];
error = xfs_sysfs_init(&cfg->kobj, &xfs_error_cfg_ktype,
parent_kobj, init[i].name);
if (error)
goto out_error;
cfg->max_retries = init[i].max_retries;
if (init[i].retry_timeout == XFS_ERR_RETRY_FOREVER)
cfg->retry_timeout = XFS_ERR_RETRY_FOREVER;
else
cfg->retry_timeout = msecs_to_jiffies(
init[i].retry_timeout * MSEC_PER_SEC);
}
return 0;
out_error:
for (i--; i >= 0; i--) {
cfg = &mp->m_error_cfg[class][i];
xfs_sysfs_del(&cfg->kobj);
}
xfs_sysfs_del(parent_kobj);
return error;
}
int
xfs_error_sysfs_init(
struct xfs_mount *mp)
{
int error;
error = xfs_sysfs_init(&mp->m_error_kobj, &xfs_error_ktype,
&mp->m_kobj, "error");
if (error)
return error;
error = sysfs_create_file(&mp->m_error_kobj.kobject,
ATTR_LIST(fail_at_unmount));
if (error)
goto out_error;
error = xfs_error_sysfs_init_class(mp, XFS_ERR_METADATA,
"metadata", &mp->m_error_meta_kobj,
xfs_error_meta_init);
if (error)
goto out_error;
return 0;
out_error:
xfs_sysfs_del(&mp->m_error_kobj);
return error;
}
void
xfs_error_sysfs_del(
struct xfs_mount *mp)
{
struct xfs_error_cfg *cfg;
int i, j;
for (i = 0; i < XFS_ERR_CLASS_MAX; i++) {
for (j = 0; j < XFS_ERR_ERRNO_MAX; j++) {
cfg = &mp->m_error_cfg[i][j];
xfs_sysfs_del(&cfg->kobj);
}
}
xfs_sysfs_del(&mp->m_error_meta_kobj);
xfs_sysfs_del(&mp->m_error_kobj);
}
struct xfs_error_cfg *
xfs_error_get_cfg(
struct xfs_mount *mp,
int error_class,
int error)
{
struct xfs_error_cfg *cfg;
if (error < 0)
error = -error;
switch (error) {
case EIO:
cfg = &mp->m_error_cfg[error_class][XFS_ERR_EIO];
break;
case ENOSPC:
cfg = &mp->m_error_cfg[error_class][XFS_ERR_ENOSPC];
break;
case ENODEV:
cfg = &mp->m_error_cfg[error_class][XFS_ERR_ENODEV];
break;
default:
cfg = &mp->m_error_cfg[error_class][XFS_ERR_DEFAULT];
break;
}
return cfg;
}
