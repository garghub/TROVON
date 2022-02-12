static void
__xfs_printk(
const char *level,
const struct xfs_mount *mp,
struct va_format *vaf)
{
if (mp && mp->m_fsname) {
printk("%sXFS (%s): %pV\n", level, mp->m_fsname, vaf);
return;
}
printk("%sXFS: %pV\n", level, vaf);
}
void
xfs_alert_tag(
const struct xfs_mount *mp,
int panic_tag,
const char *fmt, ...)
{
struct va_format vaf;
va_list args;
int do_panic = 0;
if (xfs_panic_mask && (xfs_panic_mask & panic_tag)) {
xfs_alert(mp, "Transforming an alert into a BUG.");
do_panic = 1;
}
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
__xfs_printk(KERN_ALERT, mp, &vaf);
va_end(args);
BUG_ON(do_panic);
}
void
asswarn(char *expr, char *file, int line)
{
xfs_warn(NULL, "Assertion failed: %s, file: %s, line: %d",
expr, file, line);
WARN_ON(1);
}
void
assfail(char *expr, char *file, int line)
{
xfs_emerg(NULL, "Assertion failed: %s, file: %s, line: %d",
expr, file, line);
if (xfs_globals.bug_on_assert)
BUG();
else
WARN_ON(1);
}
void
xfs_hex_dump(void *p, int length)
{
print_hex_dump(KERN_ALERT, "", DUMP_PREFIX_ADDRESS, 16, 1, p, length, 1);
}
