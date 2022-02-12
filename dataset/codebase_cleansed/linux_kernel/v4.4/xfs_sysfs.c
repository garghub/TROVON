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
