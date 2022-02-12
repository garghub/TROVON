static int groups16_to_user(u16 __user *grouplist, struct group_info *group_info)
{
struct user_namespace *user_ns = current_user_ns();
int i;
u16 group;
kgid_t kgid;
for (i = 0; i < group_info->ngroups; i++) {
kgid = GROUP_AT(group_info, i);
group = (u16)from_kgid_munged(user_ns, kgid);
if (put_user(group, grouplist+i))
return -EFAULT;
}
return 0;
}
static int groups16_from_user(struct group_info *group_info, u16 __user *grouplist)
{
struct user_namespace *user_ns = current_user_ns();
int i;
u16 group;
kgid_t kgid;
for (i = 0; i < group_info->ngroups; i++) {
if (get_user(group, grouplist+i))
return -EFAULT;
kgid = make_kgid(user_ns, (gid_t)group);
if (!gid_valid(kgid))
return -EINVAL;
GROUP_AT(group_info, i) = kgid;
}
return 0;
}
static int cp_stat64(struct stat64_emu31 __user *ubuf, struct kstat *stat)
{
struct stat64_emu31 tmp;
memset(&tmp, 0, sizeof(tmp));
tmp.st_dev = huge_encode_dev(stat->dev);
tmp.st_ino = stat->ino;
tmp.__st_ino = (u32)stat->ino;
tmp.st_mode = stat->mode;
tmp.st_nlink = (unsigned int)stat->nlink;
tmp.st_uid = from_kuid_munged(current_user_ns(), stat->uid);
tmp.st_gid = from_kgid_munged(current_user_ns(), stat->gid);
tmp.st_rdev = huge_encode_dev(stat->rdev);
tmp.st_size = stat->size;
tmp.st_blksize = (u32)stat->blksize;
tmp.st_blocks = (u32)stat->blocks;
tmp.st_atime = (u32)stat->atime.tv_sec;
tmp.st_mtime = (u32)stat->mtime.tv_sec;
tmp.st_ctime = (u32)stat->ctime.tv_sec;
return copy_to_user(ubuf,&tmp,sizeof(tmp)) ? -EFAULT : 0;
}
