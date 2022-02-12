STATIC uint
xfs_buf_log_overhead(void)
{
return round_up(sizeof(struct xlog_op_header) +
sizeof(struct xfs_buf_log_format), 128);
}
STATIC uint
xfs_calc_buf_res(
uint nbufs,
uint size)
{
return nbufs * (size + xfs_buf_log_overhead());
}
STATIC uint
xfs_calc_inode_res(
struct xfs_mount *mp,
uint ninodes)
{
return ninodes * (sizeof(struct xlog_op_header) +
sizeof(struct xfs_inode_log_format) +
mp->m_sb.sb_inodesize +
2 * XFS_BMBT_BLOCK_LEN(mp));
}
STATIC uint
xfs_calc_write_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK),
XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(3, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 2),
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(5, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 2),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_itruncate_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK) + 1,
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(9, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 4),
XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(5, 0) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(2 + mp->m_ialloc_blks +
mp->m_in_maxlevels, 0)));
}
STATIC uint
xfs_calc_rename_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 4) +
xfs_calc_buf_res(2 * XFS_DIROP_LOG_COUNT(mp),
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(7, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 3),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_link_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 2) +
xfs_calc_buf_res(XFS_DIROP_LOG_COUNT(mp),
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(3, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_remove_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 2) +
xfs_calc_buf_res(XFS_DIROP_LOG_COUNT(mp),
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(5, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 2),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_create_resv_modify(
struct xfs_mount *mp)
{
return xfs_calc_inode_res(mp, 2) +
xfs_calc_buf_res(1, mp->m_sb.sb_sectsize) +
(uint)XFS_FSB_TO_B(mp, 1) +
xfs_calc_buf_res(XFS_DIROP_LOG_COUNT(mp), XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_create_resv_alloc(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(2, mp->m_sb.sb_sectsize) +
mp->m_sb.sb_sectsize +
xfs_calc_buf_res(mp->m_ialloc_blks, XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(mp->m_in_maxlevels, XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
__xfs_calc_create_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX(xfs_calc_create_resv_alloc(mp),
xfs_calc_create_resv_modify(mp));
}
STATIC uint
xfs_calc_icreate_resv_alloc(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(2, mp->m_sb.sb_sectsize) +
mp->m_sb.sb_sectsize +
xfs_calc_buf_res(mp->m_in_maxlevels, XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_icreate_reservation(xfs_mount_t *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX(xfs_calc_icreate_resv_alloc(mp),
xfs_calc_create_resv_modify(mp));
}
STATIC uint
xfs_calc_create_reservation(
struct xfs_mount *mp)
{
if (xfs_sb_version_hascrc(&mp->m_sb))
return xfs_calc_icreate_reservation(mp);
return __xfs_calc_create_reservation(mp);
}
STATIC uint
xfs_calc_mkdir_reservation(
struct xfs_mount *mp)
{
return xfs_calc_create_reservation(mp);
}
STATIC uint
xfs_calc_symlink_reservation(
struct xfs_mount *mp)
{
return xfs_calc_create_reservation(mp) +
xfs_calc_buf_res(1, MAXPATHLEN);
}
STATIC uint
xfs_calc_ifree_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(2, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(1, XFS_FSB_TO_B(mp, 1)) +
max_t(uint, XFS_FSB_TO_B(mp, 1), mp->m_inode_cluster_size) +
xfs_calc_buf_res(1, 0) +
xfs_calc_buf_res(2 + mp->m_ialloc_blks +
mp->m_in_maxlevels, 0) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_ichange_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(1, mp->m_sb.sb_sectsize);
}
STATIC uint
xfs_calc_growdata_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(3, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_growrtalloc_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(2, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK),
XFS_FSB_TO_B(mp, 1)) +
xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_growrtzero_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_blocksize);
}
STATIC uint
xfs_calc_growrtfree_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_sectsize) +
xfs_calc_inode_res(mp, 2) +
xfs_calc_buf_res(1, mp->m_sb.sb_blocksize) +
xfs_calc_buf_res(1, mp->m_rsumsize);
}
STATIC uint
xfs_calc_swrite_reservation(
struct xfs_mount *mp)
{
return xfs_calc_inode_res(mp, 1);
}
STATIC uint
xfs_calc_writeid_reservation(
struct xfs_mount *mp)
{
return xfs_calc_inode_res(mp, 1);
}
STATIC uint
xfs_calc_addafork_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(2, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(1, mp->m_dirblksize) +
xfs_calc_buf_res(XFS_DAENTER_BMAP1B(mp, XFS_DATA_FORK) + 1,
XFS_FSB_TO_B(mp, 1)) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 1),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_attrinval_reservation(
struct xfs_mount *mp)
{
return MAX((xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK),
XFS_FSB_TO_B(mp, 1))),
(xfs_calc_buf_res(9, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 4),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_attrsetm_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(1, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_DA_NODE_MAXDEPTH, XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_attrsetrt_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK),
XFS_FSB_TO_B(mp, 1));
}
STATIC uint
xfs_calc_attrrm_reservation(
struct xfs_mount *mp)
{
return XFS_DQUOT_LOGRES(mp) +
MAX((xfs_calc_inode_res(mp, 1) +
xfs_calc_buf_res(XFS_DA_NODE_MAXDEPTH,
XFS_FSB_TO_B(mp, 1)) +
(uint)XFS_FSB_TO_B(mp,
XFS_BM_MAXLEVELS(mp, XFS_ATTR_FORK)) +
xfs_calc_buf_res(XFS_BM_MAXLEVELS(mp, XFS_DATA_FORK), 0)),
(xfs_calc_buf_res(5, mp->m_sb.sb_sectsize) +
xfs_calc_buf_res(XFS_ALLOCFREE_LOG_COUNT(mp, 2),
XFS_FSB_TO_B(mp, 1))));
}
STATIC uint
xfs_calc_clear_agi_bucket_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_sectsize);
}
STATIC uint
xfs_calc_qm_sbchange_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_sectsize);
}
STATIC uint
xfs_calc_qm_setqlim_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, sizeof(struct xfs_disk_dquot));
}
STATIC uint
xfs_calc_qm_dqalloc_reservation(
struct xfs_mount *mp)
{
ASSERT(M_RES(mp)->tr_write.tr_logres);
return M_RES(mp)->tr_write.tr_logres +
xfs_calc_buf_res(1,
XFS_FSB_TO_B(mp, XFS_DQUOT_CLUSTER_SIZE_FSB) - 1);
}
STATIC uint
xfs_calc_qm_quotaoff_reservation(
struct xfs_mount *mp)
{
return sizeof(struct xfs_qoff_logitem) * 2 +
xfs_calc_buf_res(1, mp->m_sb.sb_sectsize);
}
STATIC uint
xfs_calc_qm_quotaoff_end_reservation(
struct xfs_mount *mp)
{
return sizeof(struct xfs_qoff_logitem) * 2;
}
STATIC uint
xfs_calc_sb_reservation(
struct xfs_mount *mp)
{
return xfs_calc_buf_res(1, mp->m_sb.sb_sectsize);
}
void
xfs_trans_resv_calc(
struct xfs_mount *mp,
struct xfs_trans_resv *resp)
{
resp->tr_write.tr_logres = xfs_calc_write_reservation(mp);
resp->tr_write.tr_logcount = XFS_WRITE_LOG_COUNT;
resp->tr_write.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_itruncate.tr_logres = xfs_calc_itruncate_reservation(mp);
resp->tr_itruncate.tr_logcount = XFS_ITRUNCATE_LOG_COUNT;
resp->tr_itruncate.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_rename.tr_logres = xfs_calc_rename_reservation(mp);
resp->tr_rename.tr_logcount = XFS_RENAME_LOG_COUNT;
resp->tr_rename.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_link.tr_logres = xfs_calc_link_reservation(mp);
resp->tr_link.tr_logcount = XFS_LINK_LOG_COUNT;
resp->tr_link.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_remove.tr_logres = xfs_calc_remove_reservation(mp);
resp->tr_remove.tr_logcount = XFS_REMOVE_LOG_COUNT;
resp->tr_remove.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_symlink.tr_logres = xfs_calc_symlink_reservation(mp);
resp->tr_symlink.tr_logcount = XFS_SYMLINK_LOG_COUNT;
resp->tr_symlink.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_create.tr_logres = xfs_calc_create_reservation(mp);
resp->tr_create.tr_logcount = XFS_CREATE_LOG_COUNT;
resp->tr_create.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_mkdir.tr_logres = xfs_calc_mkdir_reservation(mp);
resp->tr_mkdir.tr_logcount = XFS_MKDIR_LOG_COUNT;
resp->tr_mkdir.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_ifree.tr_logres = xfs_calc_ifree_reservation(mp);
resp->tr_ifree.tr_logcount = XFS_INACTIVE_LOG_COUNT;
resp->tr_ifree.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_addafork.tr_logres = xfs_calc_addafork_reservation(mp);
resp->tr_addafork.tr_logcount = XFS_ADDAFORK_LOG_COUNT;
resp->tr_addafork.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_attrinval.tr_logres = xfs_calc_attrinval_reservation(mp);
resp->tr_attrinval.tr_logcount = XFS_ATTRINVAL_LOG_COUNT;
resp->tr_attrinval.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_attrsetm.tr_logres = xfs_calc_attrsetm_reservation(mp);
resp->tr_attrsetm.tr_logcount = XFS_ATTRSET_LOG_COUNT;
resp->tr_attrsetm.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_attrrm.tr_logres = xfs_calc_attrrm_reservation(mp);
resp->tr_attrrm.tr_logcount = XFS_ATTRRM_LOG_COUNT;
resp->tr_attrrm.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_growrtalloc.tr_logres = xfs_calc_growrtalloc_reservation(mp);
resp->tr_growrtalloc.tr_logcount = XFS_DEFAULT_PERM_LOG_COUNT;
resp->tr_growrtalloc.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_qm_dqalloc.tr_logres = xfs_calc_qm_dqalloc_reservation(mp);
resp->tr_qm_dqalloc.tr_logcount = XFS_WRITE_LOG_COUNT;
resp->tr_qm_dqalloc.tr_logflags |= XFS_TRANS_PERM_LOG_RES;
resp->tr_qm_sbchange.tr_logres = xfs_calc_qm_sbchange_reservation(mp);
resp->tr_qm_sbchange.tr_logcount = XFS_DEFAULT_LOG_COUNT;
resp->tr_qm_setqlim.tr_logres = xfs_calc_qm_setqlim_reservation(mp);
resp->tr_qm_setqlim.tr_logcount = XFS_DEFAULT_LOG_COUNT;
resp->tr_qm_quotaoff.tr_logres = xfs_calc_qm_quotaoff_reservation(mp);
resp->tr_qm_quotaoff.tr_logcount = XFS_DEFAULT_LOG_COUNT;
resp->tr_qm_equotaoff.tr_logres =
xfs_calc_qm_quotaoff_end_reservation(mp);
resp->tr_qm_equotaoff.tr_logcount = XFS_DEFAULT_LOG_COUNT;
resp->tr_sb.tr_logres = xfs_calc_sb_reservation(mp);
resp->tr_sb.tr_logcount = XFS_DEFAULT_LOG_COUNT;
resp->tr_ichange.tr_logres = xfs_calc_ichange_reservation(mp);
resp->tr_growdata.tr_logres = xfs_calc_growdata_reservation(mp);
resp->tr_swrite.tr_logres = xfs_calc_swrite_reservation(mp);
resp->tr_fsyncts.tr_logres = xfs_calc_swrite_reservation(mp);
resp->tr_writeid.tr_logres = xfs_calc_writeid_reservation(mp);
resp->tr_attrsetrt.tr_logres = xfs_calc_attrsetrt_reservation(mp);
resp->tr_clearagi.tr_logres = xfs_calc_clear_agi_bucket_reservation(mp);
resp->tr_growrtzero.tr_logres = xfs_calc_growrtzero_reservation(mp);
resp->tr_growrtfree.tr_logres = xfs_calc_growrtfree_reservation(mp);
}
