__u32 get_uuid2int(const char *name, int len)
{
__u32 key0 = 0x12a3fe2d, key1 = 0x37abe8f9;
while (len--) {
__u32 key = key1 + (key0 ^ (*name++ * 7152373));
if (key & 0x80000000)
key -= 0x7fffffff;
key1 = key0;
key0 = key;
}
return (key0 << 1);
}
void get_uuid2fsid(const char *name, int len, __kernel_fsid_t *fsid)
{
__u64 key = 0, key0 = 0x12a3fe2d, key1 = 0x37abe8f9;
while (len--) {
key = key1 + (key0 ^ (*name++ * 7152373));
if (key & 0x8000000000000000ULL)
key -= 0x7fffffffffffffffULL;
key1 = key0;
key0 = key;
}
fsid->val[0] = key;
fsid->val[1] = key >> 32;
}
struct inode *search_inode_for_lustre(struct super_block *sb,
const struct lu_fid *fid)
{
struct ll_sb_info *sbi = ll_s2sbi(sb);
struct ptlrpc_request *req = NULL;
struct inode *inode = NULL;
int eadatalen = 0;
unsigned long hash = cl_fid_build_ino(fid,
ll_need_32bit_api(sbi));
struct md_op_data *op_data;
int rc;
CDEBUG(D_INFO, "searching inode for:(%lu," DFID ")\n", hash, PFID(fid));
inode = ilookup5(sb, hash, ll_test_inode_by_fid, (void *)fid);
if (inode)
return inode;
rc = ll_get_default_mdsize(sbi, &eadatalen);
if (rc)
return ERR_PTR(rc);
op_data = kzalloc(sizeof(*op_data), GFP_NOFS);
if (!op_data)
return ERR_PTR(-ENOMEM);
op_data->op_fid1 = *fid;
op_data->op_mode = eadatalen;
op_data->op_valid = OBD_MD_FLEASIZE;
rc = md_getattr(sbi->ll_md_exp, op_data, &req);
kfree(op_data);
if (rc) {
CDEBUG(D_INFO, "can't get object attrs, fid " DFID ", rc %d\n",
PFID(fid), rc);
return ERR_PTR(rc);
}
rc = ll_prep_inode(&inode, req, sb, NULL);
ptlrpc_req_finished(req);
if (rc)
return ERR_PTR(rc);
return inode;
}
static struct dentry *
ll_iget_for_nfs(struct super_block *sb, struct lu_fid *fid, struct lu_fid *parent)
{
struct inode *inode;
struct dentry *result;
if (!fid_is_sane(fid))
return ERR_PTR(-ESTALE);
CDEBUG(D_INFO, "Get dentry for fid: " DFID "\n", PFID(fid));
inode = search_inode_for_lustre(sb, fid);
if (IS_ERR(inode))
return ERR_CAST(inode);
if (is_bad_inode(inode)) {
iput(inode);
return ERR_PTR(-ESTALE);
}
result = d_obtain_alias(inode);
if (IS_ERR(result)) {
iput(inode);
return result;
}
if (parent) {
struct ll_inode_info *lli = ll_i2info(inode);
spin_lock(&lli->lli_lock);
lli->lli_pfid = *parent;
spin_unlock(&lli->lli_lock);
}
result = d_obtain_alias(inode);
if (!IS_ERR(result)) {
ll_d2d(result)->lld_nfs_dentry = 1;
}
return result;
}
static int ll_encode_fh(struct inode *inode, __u32 *fh, int *plen,
struct inode *parent)
{
int fileid_len = sizeof(struct lustre_nfs_fid) / 4;
struct lustre_nfs_fid *nfs_fid = (void *)fh;
CDEBUG(D_INFO, "%s: encoding for (" DFID ") maxlen=%d minlen=%d\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), *plen, fileid_len);
if (*plen < fileid_len) {
*plen = fileid_len;
return FILEID_INVALID;
}
nfs_fid->lnf_child = *ll_inode2fid(inode);
if (parent)
nfs_fid->lnf_parent = *ll_inode2fid(parent);
else
fid_zero(&nfs_fid->lnf_parent);
*plen = fileid_len;
return FILEID_LUSTRE;
}
static int ll_nfs_get_name_filldir(struct dir_context *ctx, const char *name,
int namelen, loff_t hash, u64 ino,
unsigned int type)
{
struct lu_dirent *lde = container_of0(name, struct lu_dirent, lde_name);
struct ll_getname_data *lgd =
container_of(ctx, struct ll_getname_data, ctx);
struct lu_fid fid;
fid_le_to_cpu(&fid, &lde->lde_fid);
if (lu_fid_eq(&fid, &lgd->lgd_fid)) {
memcpy(lgd->lgd_name, name, namelen);
lgd->lgd_name[namelen] = 0;
lgd->lgd_found = 1;
}
return lgd->lgd_found;
}
static int ll_get_name(struct dentry *dentry, char *name,
struct dentry *child)
{
struct inode *dir = d_inode(dentry);
int rc;
struct ll_getname_data lgd = {
.lgd_name = name,
.lgd_fid = ll_i2info(d_inode(child))->lli_fid,
.ctx.actor = ll_nfs_get_name_filldir,
};
struct md_op_data *op_data;
__u64 pos = 0;
if (!dir || !S_ISDIR(dir->i_mode)) {
rc = -ENOTDIR;
goto out;
}
if (!dir->i_fop) {
rc = -EINVAL;
goto out;
}
op_data = ll_prep_md_op_data(NULL, dir, dir, NULL, 0, 0,
LUSTRE_OPC_ANY, dir);
if (IS_ERR(op_data)) {
rc = PTR_ERR(op_data);
goto out;
}
op_data->op_max_pages = ll_i2sbi(dir)->ll_md_brw_pages;
inode_lock(dir);
rc = ll_dir_read(dir, &pos, op_data, &lgd.ctx);
inode_unlock(dir);
ll_finish_md_op_data(op_data);
if (!rc && !lgd.lgd_found)
rc = -ENOENT;
out:
return rc;
}
static struct dentry *ll_fh_to_dentry(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
struct lustre_nfs_fid *nfs_fid = (struct lustre_nfs_fid *)fid;
if (fh_type != FILEID_LUSTRE)
return ERR_PTR(-EPROTO);
return ll_iget_for_nfs(sb, &nfs_fid->lnf_child, &nfs_fid->lnf_parent);
}
static struct dentry *ll_fh_to_parent(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
struct lustre_nfs_fid *nfs_fid = (struct lustre_nfs_fid *)fid;
if (fh_type != FILEID_LUSTRE)
return ERR_PTR(-EPROTO);
return ll_iget_for_nfs(sb, &nfs_fid->lnf_parent, NULL);
}
int ll_dir_get_parent_fid(struct inode *dir, struct lu_fid *parent_fid)
{
struct ptlrpc_request *req = NULL;
struct ll_sb_info *sbi;
struct mdt_body *body;
static const char dotdot[] = "..";
struct md_op_data *op_data;
int rc;
int lmmsize;
LASSERT(dir && S_ISDIR(dir->i_mode));
sbi = ll_s2sbi(dir->i_sb);
CDEBUG(D_INFO, "%s: getting parent for (" DFID ")\n",
ll_get_fsname(dir->i_sb, NULL, 0),
PFID(ll_inode2fid(dir)));
rc = ll_get_default_mdsize(sbi, &lmmsize);
if (rc != 0)
return rc;
op_data = ll_prep_md_op_data(NULL, dir, NULL, dotdot,
strlen(dotdot), lmmsize,
LUSTRE_OPC_ANY, NULL);
if (IS_ERR(op_data))
return PTR_ERR(op_data);
rc = md_getattr_name(sbi->ll_md_exp, op_data, &req);
ll_finish_md_op_data(op_data);
if (rc) {
CERROR("%s: failure inode " DFID " get parent: rc = %d\n",
ll_get_fsname(dir->i_sb, NULL, 0),
PFID(ll_inode2fid(dir)), rc);
return rc;
}
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
if (body->mbo_valid & OBD_MD_FLID) {
CDEBUG(D_INFO, "parent for " DFID " is " DFID "\n",
PFID(ll_inode2fid(dir)), PFID(&body->mbo_fid1));
*parent_fid = body->mbo_fid1;
}
ptlrpc_req_finished(req);
return 0;
}
static struct dentry *ll_get_parent(struct dentry *dchild)
{
struct lu_fid parent_fid = { 0 };
struct dentry *dentry;
int rc;
rc = ll_dir_get_parent_fid(dchild->d_inode, &parent_fid);
if (rc)
return ERR_PTR(rc);
dentry = ll_iget_for_nfs(dchild->d_inode->i_sb, &parent_fid, NULL);
return dentry;
}
