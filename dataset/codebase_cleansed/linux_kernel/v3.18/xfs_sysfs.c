static inline struct xfs_sysfs_attr *
to_attr(struct attribute *attr)
{
return container_of(attr, struct xfs_sysfs_attr, attr);
}
STATIC ssize_t
log_recovery_delay_store(
const char *buf,
size_t count,
void *data)
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
char *buf,
void *data)
{
return snprintf(buf, PAGE_SIZE, "%d\n", xfs_globals.log_recovery_delay);
}
STATIC ssize_t
xfs_dbg_show(
struct kobject *kobject,
struct attribute *attr,
char *buf)
{
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->show ? xfs_attr->show(buf, NULL) : 0;
}
STATIC ssize_t
xfs_dbg_store(
struct kobject *kobject,
struct attribute *attr,
const char *buf,
size_t count)
{
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->store ? xfs_attr->store(buf, count, NULL) : 0;
}
STATIC ssize_t
log_head_lsn_show(
char *buf,
void *data)
{
struct xlog *log = data;
int cycle;
int block;
spin_lock(&log->l_icloglock);
cycle = log->l_curr_cycle;
block = log->l_curr_block;
spin_unlock(&log->l_icloglock);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, block);
}
STATIC ssize_t
log_tail_lsn_show(
char *buf,
void *data)
{
struct xlog *log = data;
int cycle;
int block;
xlog_crack_atomic_lsn(&log->l_tail_lsn, &cycle, &block);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, block);
}
STATIC ssize_t
reserve_grant_head_show(
char *buf,
void *data)
{
struct xlog *log = data;
int cycle;
int bytes;
xlog_crack_grant_head(&log->l_reserve_head.grant, &cycle, &bytes);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, bytes);
}
STATIC ssize_t
write_grant_head_show(
char *buf,
void *data)
{
struct xlog *log = data;
int cycle;
int bytes;
xlog_crack_grant_head(&log->l_write_head.grant, &cycle, &bytes);
return snprintf(buf, PAGE_SIZE, "%d:%d\n", cycle, bytes);
}
static inline struct xlog *
to_xlog(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xlog, l_kobj);
}
STATIC ssize_t
xfs_log_show(
struct kobject *kobject,
struct attribute *attr,
char *buf)
{
struct xlog *log = to_xlog(kobject);
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->show ? xfs_attr->show(buf, log) : 0;
}
STATIC ssize_t
xfs_log_store(
struct kobject *kobject,
struct attribute *attr,
const char *buf,
size_t count)
{
struct xlog *log = to_xlog(kobject);
struct xfs_sysfs_attr *xfs_attr = to_attr(attr);
return xfs_attr->store ? xfs_attr->store(buf, count, log) : 0;
}
