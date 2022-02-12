int
xfs_error_test(int error_tag, int *fsidp, char *expression,
int line, char *file, unsigned long randfactor)
{
int i;
int64_t fsid;
if (prandom_u32() % randfactor)
return 0;
memcpy(&fsid, fsidp, sizeof(xfs_fsid_t));
for (i = 0; i < XFS_NUM_INJECT_ERROR; i++) {
if (xfs_etest[i] == error_tag && xfs_etest_fsid[i] == fsid) {
xfs_warn(NULL,
"Injecting error (%s) at file %s, line %d, on filesystem \"%s\"",
expression, file, line, xfs_etest_fsname[i]);
return 1;
}
}
return 0;
}
int
xfs_errortag_add(int error_tag, xfs_mount_t *mp)
{
int i;
int len;
int64_t fsid;
memcpy(&fsid, mp->m_fixedfsid, sizeof(xfs_fsid_t));
for (i = 0; i < XFS_NUM_INJECT_ERROR; i++) {
if (xfs_etest_fsid[i] == fsid && xfs_etest[i] == error_tag) {
xfs_warn(mp, "error tag #%d on", error_tag);
return 0;
}
}
for (i = 0; i < XFS_NUM_INJECT_ERROR; i++) {
if (xfs_etest[i] == 0) {
xfs_warn(mp, "Turned on XFS error tag #%d",
error_tag);
xfs_etest[i] = error_tag;
xfs_etest_fsid[i] = fsid;
len = strlen(mp->m_fsname);
xfs_etest_fsname[i] = kmem_alloc(len + 1, KM_SLEEP);
strcpy(xfs_etest_fsname[i], mp->m_fsname);
xfs_error_test_active++;
return 0;
}
}
xfs_warn(mp, "error tag overflow, too many turned on");
return 1;
}
int
xfs_errortag_clearall(xfs_mount_t *mp, int loud)
{
int64_t fsid;
int cleared = 0;
int i;
memcpy(&fsid, mp->m_fixedfsid, sizeof(xfs_fsid_t));
for (i = 0; i < XFS_NUM_INJECT_ERROR; i++) {
if ((fsid == 0LL || xfs_etest_fsid[i] == fsid) &&
xfs_etest[i] != 0) {
cleared = 1;
xfs_warn(mp, "Clearing XFS error tag #%d",
xfs_etest[i]);
xfs_etest[i] = 0;
xfs_etest_fsid[i] = 0LL;
kmem_free(xfs_etest_fsname[i]);
xfs_etest_fsname[i] = NULL;
xfs_error_test_active--;
}
}
if (loud || cleared)
xfs_warn(mp, "Cleared all XFS error tags for filesystem");
return 0;
}
void
xfs_error_report(
const char *tag,
int level,
struct xfs_mount *mp,
const char *filename,
int linenum,
inst_t *ra)
{
if (level <= xfs_error_level) {
xfs_alert_tag(mp, XFS_PTAG_ERROR_REPORT,
"Internal error %s at line %d of file %s. Caller %pF",
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
inst_t *ra)
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
xfs_alert(mp, "Metadata %s detected at %pF, block 0x%llx",
bp->b_error == -EFSBADCRC ? "CRC error" : "corruption",
__return_address, bp->b_bn);
xfs_alert(mp, "Unmount and run xfs_repair");
if (xfs_error_level >= XFS_ERRLEVEL_LOW) {
xfs_alert(mp, "First 64 bytes of corrupted metadata buffer:");
xfs_hex_dump(xfs_buf_offset(bp, 0), 64);
}
if (xfs_error_level >= XFS_ERRLEVEL_HIGH)
xfs_stack_trace();
}
