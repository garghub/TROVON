__u32 get_uuid2int(const char *name, int len)
{
__u32 key0 = 0x12a3fe2d, key1 = 0x37abe8f9;
while (len--) {
__u32 key = key1 + (key0 ^ (*name++ * 7152373));
if (key & 0x80000000) key -= 0x7fffffff;
key1 = key0;
key0 = key;
}
return (key0 << 1);
}
static int ll_nfs_test_inode(struct inode *inode, void *opaque)
{
return lu_fid_eq(&ll_i2info(inode)->lli_fid,
(struct lu_fid *)opaque);
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
ENTRY;
CDEBUG(D_INFO, "searching inode for:(%lu,"DFID")\n", hash, PFID(fid));
inode = ilookup5(sb, hash, ll_nfs_test_inode, (void *)fid);
if (inode)
RETURN(inode);
rc = ll_get_max_mdsize(sbi, &eadatalen);
if (rc)
RETURN(ERR_PTR(rc));
OBD_ALLOC_PTR(op_data);
if (op_data == NULL)
return ERR_PTR(-ENOMEM);
op_data->op_fid1 = *fid;
op_data->op_mode = eadatalen;
op_data->op_valid = OBD_MD_FLEASIZE;
rc = md_getattr(sbi->ll_md_exp, op_data, &req);
OBD_FREE_PTR(op_data);
if (rc) {
CERROR("can't get object attrs, fid "DFID", rc %d\n",
PFID(fid), rc);
RETURN(ERR_PTR(rc));
}
rc = ll_prep_inode(&inode, req, sb, NULL);
ptlrpc_req_finished(req);
if (rc)
RETURN(ERR_PTR(rc));
RETURN(inode);
}
static struct dentry *
ll_iget_for_nfs(struct super_block *sb, struct lu_fid *fid, struct lu_fid *parent)
{
struct inode *inode;
struct dentry *result;
ENTRY;
CDEBUG(D_INFO, "Get dentry for fid: "DFID"\n", PFID(fid));
if (!fid_is_sane(fid))
RETURN(ERR_PTR(-ESTALE));
inode = search_inode_for_lustre(sb, fid);
if (IS_ERR(inode))
RETURN(ERR_PTR(PTR_ERR(inode)));
if (is_bad_inode(inode)) {
iput(inode);
RETURN(ERR_PTR(-ESTALE));
}
if (S_ISREG(inode->i_mode) && !ll_i2info(inode)->lli_has_smd &&
parent != NULL) {
struct ll_inode_info *lli = ll_i2info(inode);
spin_lock(&lli->lli_lock);
lli->lli_pfid = *parent;
spin_unlock(&lli->lli_lock);
}
result = d_obtain_alias(inode);
if (IS_ERR(result))
RETURN(result);
ll_dops_init(result, 1, 0);
RETURN(result);
}
static int ll_encode_fh(struct inode *inode, __u32 *fh, int *plen,
struct inode *parent)
{
struct lustre_nfs_fid *nfs_fid = (void *)fh;
ENTRY;
CDEBUG(D_INFO, "encoding for (%lu,"DFID") maxlen=%d minlen=%d\n",
inode->i_ino, PFID(ll_inode2fid(inode)), *plen,
(int)sizeof(struct lustre_nfs_fid));
if (*plen < sizeof(struct lustre_nfs_fid) / 4)
RETURN(255);
nfs_fid->lnf_child = *ll_inode2fid(inode);
nfs_fid->lnf_parent = *ll_inode2fid(parent);
*plen = sizeof(struct lustre_nfs_fid) / 4;
RETURN(LUSTRE_NFS_FID);
}
static int ll_nfs_get_name_filldir(void *cookie, const char *name, int namelen,
loff_t hash, u64 ino, unsigned type)
{
struct lu_dirent *lde = container_of0(name, struct lu_dirent, lde_name);
struct ll_getname_data *lgd = cookie;
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
struct inode *dir = dentry->d_inode;
struct ll_getname_data lgd;
__u64 offset = 0;
int rc;
ENTRY;
if (!dir || !S_ISDIR(dir->i_mode))
GOTO(out, rc = -ENOTDIR);
if (!dir->i_fop)
GOTO(out, rc = -EINVAL);
lgd.lgd_name = name;
lgd.lgd_fid = ll_i2info(child->d_inode)->lli_fid;
lgd.lgd_found = 0;
mutex_lock(&dir->i_mutex);
rc = ll_dir_read(dir, &offset, &lgd, ll_nfs_get_name_filldir);
mutex_unlock(&dir->i_mutex);
if (!rc && !lgd.lgd_found)
rc = -ENOENT;
EXIT;
out:
return rc;
}
static struct dentry *ll_fh_to_dentry(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
struct lustre_nfs_fid *nfs_fid = (struct lustre_nfs_fid *)fid;
if (fh_type != LUSTRE_NFS_FID)
RETURN(ERR_PTR(-EPROTO));
RETURN(ll_iget_for_nfs(sb, &nfs_fid->lnf_child, &nfs_fid->lnf_parent));
}
static struct dentry *ll_fh_to_parent(struct super_block *sb, struct fid *fid,
int fh_len, int fh_type)
{
struct lustre_nfs_fid *nfs_fid = (struct lustre_nfs_fid *)fid;
if (fh_type != LUSTRE_NFS_FID)
RETURN(ERR_PTR(-EPROTO));
RETURN(ll_iget_for_nfs(sb, &nfs_fid->lnf_parent, NULL));
}
static struct dentry *ll_get_parent(struct dentry *dchild)
{
struct ptlrpc_request *req = NULL;
struct inode *dir = dchild->d_inode;
struct ll_sb_info *sbi;
struct dentry *result = NULL;
struct mdt_body *body;
static char dotdot[] = "..";
struct md_op_data *op_data;
int rc;
int lmmsize;
ENTRY;
LASSERT(dir && S_ISDIR(dir->i_mode));
sbi = ll_s2sbi(dir->i_sb);
CDEBUG(D_INFO, "getting parent for (%lu,"DFID")\n",
dir->i_ino, PFID(ll_inode2fid(dir)));
rc = ll_get_max_mdsize(sbi, &lmmsize);
if (rc != 0)
RETURN(ERR_PTR(rc));
op_data = ll_prep_md_op_data(NULL, dir, NULL, dotdot,
strlen(dotdot), lmmsize,
LUSTRE_OPC_ANY, NULL);
if (IS_ERR(op_data))
RETURN((void *)op_data);
rc = md_getattr_name(sbi->ll_md_exp, op_data, &req);
ll_finish_md_op_data(op_data);
if (rc) {
CERROR("failure %d inode %lu get parent\n", rc, dir->i_ino);
RETURN(ERR_PTR(rc));
}
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
LASSERT(body->valid & OBD_MD_FLID);
CDEBUG(D_INFO, "parent for "DFID" is "DFID"\n",
PFID(ll_inode2fid(dir)), PFID(&body->fid1));
result = ll_iget_for_nfs(dir->i_sb, &body->fid1, NULL);
ptlrpc_req_finished(req);
RETURN(result);
}
