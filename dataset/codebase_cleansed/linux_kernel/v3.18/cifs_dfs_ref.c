static void cifs_dfs_expire_automounts(struct work_struct *work)
{
struct list_head *list = &cifs_dfs_automount_list;
mark_mounts_for_expiry(list);
if (!list_empty(list))
schedule_delayed_work(&cifs_dfs_automount_task,
cifs_dfs_mountpoint_expiry_timeout);
}
void cifs_dfs_release_automount_timer(void)
{
BUG_ON(!list_empty(&cifs_dfs_automount_list));
cancel_delayed_work_sync(&cifs_dfs_automount_task);
}
static char *
cifs_build_devname(char *nodename, const char *prepath)
{
size_t pplen;
size_t unclen;
char *dev;
char *pos;
nodename += strspn(nodename, "\\");
if (!*nodename)
return ERR_PTR(-EINVAL);
unclen = strlen(nodename);
pos = nodename + unclen - 1;
while (*pos == '\\') {
--pos;
--unclen;
}
pplen = prepath ? strlen(prepath) : 0;
dev = kmalloc(2 + unclen + 1 + pplen + 1, GFP_KERNEL);
if (!dev)
return ERR_PTR(-ENOMEM);
pos = dev;
*pos = '/';
++pos;
*pos = '/';
++pos;
memcpy(pos, nodename, unclen);
pos += unclen;
if (pplen) {
*pos = '/';
++pos;
memcpy(pos, prepath, pplen);
pos += pplen;
}
*pos = '\0';
convert_delimiter(dev, '/');
return dev;
}
char *cifs_compose_mount_options(const char *sb_mountdata,
const char *fullpath,
const struct dfs_info3_param *ref,
char **devname)
{
int rc;
char *mountdata = NULL;
const char *prepath = NULL;
int md_len;
char *tkn_e;
char *srvIP = NULL;
char sep = ',';
int off, noff;
if (sb_mountdata == NULL)
return ERR_PTR(-EINVAL);
if (strlen(fullpath) - ref->path_consumed)
prepath = fullpath + ref->path_consumed;
*devname = cifs_build_devname(ref->node_name, prepath);
if (IS_ERR(*devname)) {
rc = PTR_ERR(*devname);
*devname = NULL;
goto compose_mount_options_err;
}
rc = dns_resolve_server_name_to_ip(*devname, &srvIP);
if (rc < 0) {
cifs_dbg(FYI, "%s: Failed to resolve server part of %s to IP: %d\n",
__func__, *devname, rc);
goto compose_mount_options_err;
}
md_len = strlen(sb_mountdata) + INET6_ADDRSTRLEN;
mountdata = kzalloc(md_len + 1, GFP_KERNEL);
if (mountdata == NULL) {
rc = -ENOMEM;
goto compose_mount_options_err;
}
off = 0;
if (strncmp(sb_mountdata, "sep=", 4) == 0) {
sep = sb_mountdata[4];
strncpy(mountdata, sb_mountdata, 5);
off += 5;
}
do {
tkn_e = strchr(sb_mountdata + off, sep);
if (tkn_e == NULL)
noff = strlen(sb_mountdata + off);
else
noff = tkn_e - (sb_mountdata + off) + 1;
if (strncasecmp(sb_mountdata + off, "unc=", 4) == 0) {
off += noff;
continue;
}
if (strncasecmp(sb_mountdata + off, "ip=", 3) == 0) {
off += noff;
continue;
}
if (strncasecmp(sb_mountdata + off, "prefixpath=", 11) == 0) {
off += noff;
continue;
}
strncat(mountdata, sb_mountdata + off, noff);
off += noff;
} while (tkn_e);
strcat(mountdata, sb_mountdata + off);
mountdata[md_len] = '\0';
if (mountdata[strlen(mountdata) - 1] != sep)
strncat(mountdata, &sep, 1);
strcat(mountdata, "ip=");
strcat(mountdata, srvIP);
compose_mount_options_out:
kfree(srvIP);
return mountdata;
compose_mount_options_err:
kfree(mountdata);
mountdata = ERR_PTR(rc);
kfree(*devname);
*devname = NULL;
goto compose_mount_options_out;
}
static struct vfsmount *cifs_dfs_do_refmount(struct cifs_sb_info *cifs_sb,
const char *fullpath, const struct dfs_info3_param *ref)
{
struct vfsmount *mnt;
char *mountdata;
char *devname = NULL;
mountdata = cifs_compose_mount_options(cifs_sb->mountdata,
fullpath + 1, ref, &devname);
if (IS_ERR(mountdata))
return (struct vfsmount *)mountdata;
mnt = vfs_kern_mount(&cifs_fs_type, 0, devname, mountdata);
kfree(mountdata);
kfree(devname);
return mnt;
}
static void dump_referral(const struct dfs_info3_param *ref)
{
cifs_dbg(FYI, "DFS: ref path: %s\n", ref->path_name);
cifs_dbg(FYI, "DFS: node path: %s\n", ref->node_name);
cifs_dbg(FYI, "DFS: fl: %hd, srv_type: %hd\n",
ref->flags, ref->server_type);
cifs_dbg(FYI, "DFS: ref_flags: %hd, path_consumed: %hd\n",
ref->ref_flag, ref->path_consumed);
}
static struct vfsmount *cifs_dfs_do_automount(struct dentry *mntpt)
{
struct dfs_info3_param *referrals = NULL;
unsigned int num_referrals = 0;
struct cifs_sb_info *cifs_sb;
struct cifs_ses *ses;
char *full_path;
unsigned int xid;
int i;
int rc;
struct vfsmount *mnt;
struct tcon_link *tlink;
cifs_dbg(FYI, "in %s\n", __func__);
BUG_ON(IS_ROOT(mntpt));
mnt = ERR_PTR(-ENOMEM);
full_path = build_path_from_dentry(mntpt);
if (full_path == NULL)
goto cdda_exit;
cifs_sb = CIFS_SB(mntpt->d_inode->i_sb);
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink)) {
mnt = ERR_CAST(tlink);
goto free_full_path;
}
ses = tlink_tcon(tlink)->ses;
xid = get_xid();
rc = get_dfs_path(xid, ses, full_path + 1, cifs_sb->local_nls,
&num_referrals, &referrals,
cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR);
free_xid(xid);
cifs_put_tlink(tlink);
mnt = ERR_PTR(-ENOENT);
for (i = 0; i < num_referrals; i++) {
int len;
dump_referral(referrals + i);
len = strlen(referrals[i].node_name);
if (len < 2) {
cifs_dbg(VFS, "%s: Net Address path too short: %s\n",
__func__, referrals[i].node_name);
mnt = ERR_PTR(-EINVAL);
break;
}
mnt = cifs_dfs_do_refmount(cifs_sb,
full_path, referrals + i);
cifs_dbg(FYI, "%s: cifs_dfs_do_refmount:%s , mnt:%p\n",
__func__, referrals[i].node_name, mnt);
if (!IS_ERR(mnt))
goto success;
}
if (rc != 0)
mnt = ERR_PTR(rc);
success:
free_dfs_info_array(referrals, num_referrals);
free_full_path:
kfree(full_path);
cdda_exit:
cifs_dbg(FYI, "leaving %s\n" , __func__);
return mnt;
}
struct vfsmount *cifs_dfs_d_automount(struct path *path)
{
struct vfsmount *newmnt;
cifs_dbg(FYI, "in %s\n", __func__);
newmnt = cifs_dfs_do_automount(path->dentry);
if (IS_ERR(newmnt)) {
cifs_dbg(FYI, "leaving %s [automount failed]\n" , __func__);
return newmnt;
}
mntget(newmnt);
mnt_set_expiry(newmnt, &cifs_dfs_automount_list);
schedule_delayed_work(&cifs_dfs_automount_task,
cifs_dfs_mountpoint_expiry_timeout);
cifs_dbg(FYI, "leaving %s [ok]\n" , __func__);
return newmnt;
}
