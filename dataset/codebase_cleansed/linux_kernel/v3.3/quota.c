static int check_quotactl_permission(struct super_block *sb, int type, int cmd,
qid_t id)
{
switch (cmd) {
case Q_GETFMT:
case Q_SYNC:
case Q_GETINFO:
case Q_XGETQSTAT:
case Q_XQUOTASYNC:
break;
case Q_GETQUOTA:
case Q_XGETQUOTA:
if ((type == USRQUOTA && current_euid() == id) ||
(type == GRPQUOTA && in_egroup_p(id)))
break;
default:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
}
return security_quotactl(cmd, type, id, sb);
}
static void quota_sync_one(struct super_block *sb, void *arg)
{
if (sb->s_qcop && sb->s_qcop->quota_sync)
sb->s_qcop->quota_sync(sb, *(int *)arg, 1);
}
static int quota_sync_all(int type)
{
int ret;
if (type >= MAXQUOTAS)
return -EINVAL;
ret = security_quotactl(Q_SYNC, type, 0, NULL);
if (!ret)
iterate_supers(quota_sync_one, &type);
return ret;
}
static int quota_quotaon(struct super_block *sb, int type, int cmd, qid_t id,
struct path *path)
{
if (!sb->s_qcop->quota_on && !sb->s_qcop->quota_on_meta)
return -ENOSYS;
if (sb->s_qcop->quota_on_meta)
return sb->s_qcop->quota_on_meta(sb, type, id);
if (IS_ERR(path))
return PTR_ERR(path);
return sb->s_qcop->quota_on(sb, type, id, path);
}
static int quota_getfmt(struct super_block *sb, int type, void __user *addr)
{
__u32 fmt;
down_read(&sb_dqopt(sb)->dqptr_sem);
if (!sb_has_quota_active(sb, type)) {
up_read(&sb_dqopt(sb)->dqptr_sem);
return -ESRCH;
}
fmt = sb_dqopt(sb)->info[type].dqi_format->qf_fmt_id;
up_read(&sb_dqopt(sb)->dqptr_sem);
if (copy_to_user(addr, &fmt, sizeof(fmt)))
return -EFAULT;
return 0;
}
static int quota_getinfo(struct super_block *sb, int type, void __user *addr)
{
struct if_dqinfo info;
int ret;
if (!sb->s_qcop->get_info)
return -ENOSYS;
ret = sb->s_qcop->get_info(sb, type, &info);
if (!ret && copy_to_user(addr, &info, sizeof(info)))
return -EFAULT;
return ret;
}
static int quota_setinfo(struct super_block *sb, int type, void __user *addr)
{
struct if_dqinfo info;
if (copy_from_user(&info, addr, sizeof(info)))
return -EFAULT;
if (!sb->s_qcop->set_info)
return -ENOSYS;
return sb->s_qcop->set_info(sb, type, &info);
}
static void copy_to_if_dqblk(struct if_dqblk *dst, struct fs_disk_quota *src)
{
dst->dqb_bhardlimit = src->d_blk_hardlimit;
dst->dqb_bsoftlimit = src->d_blk_softlimit;
dst->dqb_curspace = src->d_bcount;
dst->dqb_ihardlimit = src->d_ino_hardlimit;
dst->dqb_isoftlimit = src->d_ino_softlimit;
dst->dqb_curinodes = src->d_icount;
dst->dqb_btime = src->d_btimer;
dst->dqb_itime = src->d_itimer;
dst->dqb_valid = QIF_ALL;
}
static int quota_getquota(struct super_block *sb, int type, qid_t id,
void __user *addr)
{
struct fs_disk_quota fdq;
struct if_dqblk idq;
int ret;
if (!sb->s_qcop->get_dqblk)
return -ENOSYS;
ret = sb->s_qcop->get_dqblk(sb, type, id, &fdq);
if (ret)
return ret;
copy_to_if_dqblk(&idq, &fdq);
if (copy_to_user(addr, &idq, sizeof(idq)))
return -EFAULT;
return 0;
}
static void copy_from_if_dqblk(struct fs_disk_quota *dst, struct if_dqblk *src)
{
dst->d_blk_hardlimit = src->dqb_bhardlimit;
dst->d_blk_softlimit = src->dqb_bsoftlimit;
dst->d_bcount = src->dqb_curspace;
dst->d_ino_hardlimit = src->dqb_ihardlimit;
dst->d_ino_softlimit = src->dqb_isoftlimit;
dst->d_icount = src->dqb_curinodes;
dst->d_btimer = src->dqb_btime;
dst->d_itimer = src->dqb_itime;
dst->d_fieldmask = 0;
if (src->dqb_valid & QIF_BLIMITS)
dst->d_fieldmask |= FS_DQ_BSOFT | FS_DQ_BHARD;
if (src->dqb_valid & QIF_SPACE)
dst->d_fieldmask |= FS_DQ_BCOUNT;
if (src->dqb_valid & QIF_ILIMITS)
dst->d_fieldmask |= FS_DQ_ISOFT | FS_DQ_IHARD;
if (src->dqb_valid & QIF_INODES)
dst->d_fieldmask |= FS_DQ_ICOUNT;
if (src->dqb_valid & QIF_BTIME)
dst->d_fieldmask |= FS_DQ_BTIMER;
if (src->dqb_valid & QIF_ITIME)
dst->d_fieldmask |= FS_DQ_ITIMER;
}
static int quota_setquota(struct super_block *sb, int type, qid_t id,
void __user *addr)
{
struct fs_disk_quota fdq;
struct if_dqblk idq;
if (copy_from_user(&idq, addr, sizeof(idq)))
return -EFAULT;
if (!sb->s_qcop->set_dqblk)
return -ENOSYS;
copy_from_if_dqblk(&fdq, &idq);
return sb->s_qcop->set_dqblk(sb, type, id, &fdq);
}
static int quota_setxstate(struct super_block *sb, int cmd, void __user *addr)
{
__u32 flags;
if (copy_from_user(&flags, addr, sizeof(flags)))
return -EFAULT;
if (!sb->s_qcop->set_xstate)
return -ENOSYS;
return sb->s_qcop->set_xstate(sb, flags, cmd);
}
static int quota_getxstate(struct super_block *sb, void __user *addr)
{
struct fs_quota_stat fqs;
int ret;
if (!sb->s_qcop->get_xstate)
return -ENOSYS;
ret = sb->s_qcop->get_xstate(sb, &fqs);
if (!ret && copy_to_user(addr, &fqs, sizeof(fqs)))
return -EFAULT;
return ret;
}
static int quota_setxquota(struct super_block *sb, int type, qid_t id,
void __user *addr)
{
struct fs_disk_quota fdq;
if (copy_from_user(&fdq, addr, sizeof(fdq)))
return -EFAULT;
if (!sb->s_qcop->set_dqblk)
return -ENOSYS;
return sb->s_qcop->set_dqblk(sb, type, id, &fdq);
}
static int quota_getxquota(struct super_block *sb, int type, qid_t id,
void __user *addr)
{
struct fs_disk_quota fdq;
int ret;
if (!sb->s_qcop->get_dqblk)
return -ENOSYS;
ret = sb->s_qcop->get_dqblk(sb, type, id, &fdq);
if (!ret && copy_to_user(addr, &fdq, sizeof(fdq)))
return -EFAULT;
return ret;
}
static int do_quotactl(struct super_block *sb, int type, int cmd, qid_t id,
void __user *addr, struct path *path)
{
int ret;
if (type >= (XQM_COMMAND(cmd) ? XQM_MAXQUOTAS : MAXQUOTAS))
return -EINVAL;
if (!sb->s_qcop)
return -ENOSYS;
ret = check_quotactl_permission(sb, type, cmd, id);
if (ret < 0)
return ret;
switch (cmd) {
case Q_QUOTAON:
return quota_quotaon(sb, type, cmd, id, path);
case Q_QUOTAOFF:
if (!sb->s_qcop->quota_off)
return -ENOSYS;
return sb->s_qcop->quota_off(sb, type);
case Q_GETFMT:
return quota_getfmt(sb, type, addr);
case Q_GETINFO:
return quota_getinfo(sb, type, addr);
case Q_SETINFO:
return quota_setinfo(sb, type, addr);
case Q_GETQUOTA:
return quota_getquota(sb, type, id, addr);
case Q_SETQUOTA:
return quota_setquota(sb, type, id, addr);
case Q_SYNC:
if (!sb->s_qcop->quota_sync)
return -ENOSYS;
return sb->s_qcop->quota_sync(sb, type, 1);
case Q_XQUOTAON:
case Q_XQUOTAOFF:
case Q_XQUOTARM:
return quota_setxstate(sb, cmd, addr);
case Q_XGETQSTAT:
return quota_getxstate(sb, addr);
case Q_XSETQLIM:
return quota_setxquota(sb, type, id, addr);
case Q_XGETQUOTA:
return quota_getxquota(sb, type, id, addr);
case Q_XQUOTASYNC:
if (sb->s_flags & MS_RDONLY)
return -EROFS;
writeback_inodes_sb(sb, WB_REASON_SYNC);
return 0;
default:
return -EINVAL;
}
}
static int quotactl_cmd_write(int cmd)
{
switch (cmd) {
case Q_GETFMT:
case Q_GETINFO:
case Q_SYNC:
case Q_XGETQSTAT:
case Q_XGETQUOTA:
case Q_XQUOTASYNC:
return 0;
}
return 1;
}
static struct super_block *quotactl_block(const char __user *special, int cmd)
{
#ifdef CONFIG_BLOCK
struct block_device *bdev;
struct super_block *sb;
char *tmp = getname(special);
if (IS_ERR(tmp))
return ERR_CAST(tmp);
bdev = lookup_bdev(tmp);
putname(tmp);
if (IS_ERR(bdev))
return ERR_CAST(bdev);
if (quotactl_cmd_write(cmd))
sb = get_super_thawed(bdev);
else
sb = get_super(bdev);
bdput(bdev);
if (!sb)
return ERR_PTR(-ENODEV);
return sb;
#else
return ERR_PTR(-ENODEV);
#endif
}
