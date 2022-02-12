static inline struct xfs_errortag_attr *
to_attr(struct attribute *attr)
{
return container_of(attr, struct xfs_errortag_attr, attr);
}
static inline struct xfs_mount *
to_mp(struct kobject *kobject)
{
struct xfs_kobj *kobj = to_kobj(kobject);
return container_of(kobj, struct xfs_mount, m_errortag_kobj);
}
STATIC ssize_t
xfs_errortag_attr_store(
struct kobject *kobject,
struct attribute *attr,
const char *buf,
size_t count)
{
struct xfs_mount *mp = to_mp(kobject);
struct xfs_errortag_attr *xfs_attr = to_attr(attr);
int ret;
unsigned int val;
if (strcmp(buf, "default") == 0) {
val = xfs_errortag_random_default[xfs_attr->tag];
} else {
ret = kstrtouint(buf, 0, &val);
if (ret)
return ret;
}
ret = xfs_errortag_set(mp, xfs_attr->tag, val);
if (ret)
return ret;
return count;
}
STATIC ssize_t
xfs_errortag_attr_show(
struct kobject *kobject,
struct attribute *attr,
char *buf)
{
struct xfs_mount *mp = to_mp(kobject);
struct xfs_errortag_attr *xfs_attr = to_attr(attr);
return snprintf(buf, PAGE_SIZE, "%u\n",
xfs_errortag_get(mp, xfs_attr->tag));
}
int
xfs_errortag_init(
struct xfs_mount *mp)
{
mp->m_errortag = kmem_zalloc(sizeof(unsigned int) * XFS_ERRTAG_MAX,
KM_SLEEP | KM_MAYFAIL);
if (!mp->m_errortag)
return -ENOMEM;
return xfs_sysfs_init(&mp->m_errortag_kobj, &xfs_errortag_ktype,
&mp->m_kobj, "errortag");
}
void
xfs_errortag_del(
struct xfs_mount *mp)
{
xfs_sysfs_del(&mp->m_errortag_kobj);
kmem_free(mp->m_errortag);
}
bool
xfs_errortag_test(
struct xfs_mount *mp,
const char *expression,
const char *file,
int line,
unsigned int error_tag)
{
unsigned int randfactor;
if (!mp->m_errortag)
return false;
ASSERT(error_tag < XFS_ERRTAG_MAX);
randfactor = mp->m_errortag[error_tag];
if (!randfactor || prandom_u32() % randfactor)
return false;
xfs_warn_ratelimited(mp,
"Injecting error (%s) at file %s, line %d, on filesystem \"%s\"",
expression, file, line, mp->m_fsname);
return true;
}
int
xfs_errortag_get(
struct xfs_mount *mp,
unsigned int error_tag)
{
if (error_tag >= XFS_ERRTAG_MAX)
return -EINVAL;
return mp->m_errortag[error_tag];
}
int
xfs_errortag_set(
struct xfs_mount *mp,
unsigned int error_tag,
unsigned int tag_value)
{
if (error_tag >= XFS_ERRTAG_MAX)
return -EINVAL;
mp->m_errortag[error_tag] = tag_value;
return 0;
}
int
xfs_errortag_add(
struct xfs_mount *mp,
unsigned int error_tag)
{
if (error_tag >= XFS_ERRTAG_MAX)
return -EINVAL;
return xfs_errortag_set(mp, error_tag,
xfs_errortag_random_default[error_tag]);
}
int
xfs_errortag_clearall(
struct xfs_mount *mp)
{
memset(mp->m_errortag, 0, sizeof(unsigned int) * XFS_ERRTAG_MAX);
return 0;
}
void
xfs_error_report(
const char *tag,
int level,
struct xfs_mount *mp,
const char *filename,
int linenum,
void *ra)
{
if (level <= xfs_error_level) {
xfs_alert_tag(mp, XFS_PTAG_ERROR_REPORT,
"Internal error %s at line %d of file %s. Caller %pS",
tag, linenum, filename, ra);
xfs_stack_trace();
}
}
void
xfs_corruption_error(
const char *tag,
int level,
struct xfs_mount *mp,
void *p,
const char *filename,
int linenum,
void *ra)
{
if (level <= xfs_error_level)
xfs_hex_dump(p, 64);
xfs_error_report(tag, level, mp, filename, linenum, ra);
xfs_alert(mp, "Corruption detected. Unmount and run xfs_repair");
}
void
xfs_verifier_error(
struct xfs_buf *bp)
{
struct xfs_mount *mp = bp->b_target->bt_mount;
xfs_alert(mp, "Metadata %s detected at %pF, %s block 0x%llx",
bp->b_error == -EFSBADCRC ? "CRC error" : "corruption",
__return_address, bp->b_ops->name, bp->b_bn);
xfs_alert(mp, "Unmount and run xfs_repair");
if (xfs_error_level >= XFS_ERRLEVEL_LOW) {
xfs_alert(mp, "First 64 bytes of corrupted metadata buffer:");
xfs_hex_dump(xfs_buf_offset(bp, 0), 64);
}
if (xfs_error_level >= XFS_ERRLEVEL_HIGH)
xfs_stack_trace();
}
