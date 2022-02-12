STATIC int
xfs_log_calc_max_attrsetm_res(
struct xfs_mount *mp)
{
int size;
int nblks;
size = xfs_attr_leaf_entsize_local_max(mp->m_attr_geo->blksize) -
MAXNAMELEN - 1;
nblks = XFS_DAENTER_SPACE_RES(mp, XFS_ATTR_FORK);
nblks += XFS_B_TO_FSB(mp, size);
nblks += XFS_NEXTENTADD_SPACE_RES(mp, size, XFS_ATTR_FORK);
return M_RES(mp)->tr_attrsetm.tr_logres +
M_RES(mp)->tr_attrsetrt.tr_logres * nblks;
}
STATIC void
xfs_log_get_max_trans_res(
struct xfs_mount *mp,
struct xfs_trans_res *max_resp)
{
struct xfs_trans_res *resp;
struct xfs_trans_res *end_resp;
int log_space = 0;
int attr_space;
attr_space = xfs_log_calc_max_attrsetm_res(mp);
resp = (struct xfs_trans_res *)M_RES(mp);
end_resp = (struct xfs_trans_res *)(M_RES(mp) + 1);
for (; resp < end_resp; resp++) {
int tmp = resp->tr_logcount > 1 ?
resp->tr_logres * resp->tr_logcount :
resp->tr_logres;
if (log_space < tmp) {
log_space = tmp;
*max_resp = *resp;
}
}
if (attr_space > log_space) {
*max_resp = M_RES(mp)->tr_attrsetm;
max_resp->tr_logres = attr_space;
}
}
int
xfs_log_calc_minimum_size(
struct xfs_mount *mp)
{
struct xfs_trans_res tres = {0};
int max_logres;
int min_logblks = 0;
int lsunit = 0;
xfs_log_get_max_trans_res(mp, &tres);
max_logres = xfs_log_calc_unit_res(mp, tres.tr_logres);
if (tres.tr_logcount > 1)
max_logres *= tres.tr_logcount;
if (xfs_sb_version_haslogv2(&mp->m_sb) && mp->m_sb.sb_logsunit > 1)
lsunit = BTOBB(mp->m_sb.sb_logsunit);
if (lsunit) {
min_logblks = roundup_64(BTOBB(max_logres), lsunit) +
2 * lsunit;
} else
min_logblks = BTOBB(max_logres) + 2 * BBSIZE;
min_logblks *= XFS_MIN_LOG_FACTOR;
return XFS_BB_TO_FSB(mp, min_logblks);
}
