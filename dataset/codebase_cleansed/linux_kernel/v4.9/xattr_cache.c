int ll_xattr_init(void)
{
return lu_kmem_init(xattr_caches);
}
void ll_xattr_fini(void)
{
lu_kmem_fini(xattr_caches);
}
static void ll_xattr_cache_init(struct ll_inode_info *lli)
{
INIT_LIST_HEAD(&lli->lli_xattrs);
lli->lli_flags |= LLIF_XATTR_CACHE;
}
static int ll_xattr_cache_find(struct list_head *cache,
const char *xattr_name,
struct ll_xattr_entry **xattr)
{
struct ll_xattr_entry *entry;
list_for_each_entry(entry, cache, xe_list) {
if (!xattr_name || strcmp(xattr_name, entry->xe_name) == 0) {
*xattr = entry;
CDEBUG(D_CACHE, "find: [%s]=%.*s\n",
entry->xe_name, entry->xe_vallen,
entry->xe_value);
return 0;
}
}
return -ENODATA;
}
static int ll_xattr_cache_add(struct list_head *cache,
const char *xattr_name,
const char *xattr_val,
unsigned xattr_val_len)
{
struct ll_xattr_entry *xattr;
if (ll_xattr_cache_find(cache, xattr_name, &xattr) == 0) {
CDEBUG(D_CACHE, "duplicate xattr: [%s]\n", xattr_name);
return -EPROTO;
}
xattr = kmem_cache_zalloc(xattr_kmem, GFP_NOFS);
if (!xattr) {
CDEBUG(D_CACHE, "failed to allocate xattr\n");
return -ENOMEM;
}
xattr->xe_name = kstrdup(xattr_name, GFP_NOFS);
if (!xattr->xe_name) {
CDEBUG(D_CACHE, "failed to alloc xattr name %u\n",
xattr->xe_namelen);
goto err_name;
}
xattr->xe_value = kmemdup(xattr_val, xattr_val_len, GFP_NOFS);
if (!xattr->xe_value)
goto err_value;
xattr->xe_vallen = xattr_val_len;
list_add(&xattr->xe_list, cache);
CDEBUG(D_CACHE, "set: [%s]=%.*s\n", xattr_name, xattr_val_len,
xattr_val);
return 0;
err_value:
kfree(xattr->xe_name);
err_name:
kmem_cache_free(xattr_kmem, xattr);
return -ENOMEM;
}
static int ll_xattr_cache_del(struct list_head *cache,
const char *xattr_name)
{
struct ll_xattr_entry *xattr;
CDEBUG(D_CACHE, "del xattr: %s\n", xattr_name);
if (ll_xattr_cache_find(cache, xattr_name, &xattr) == 0) {
list_del(&xattr->xe_list);
kfree(xattr->xe_name);
kfree(xattr->xe_value);
kmem_cache_free(xattr_kmem, xattr);
return 0;
}
return -ENODATA;
}
static int ll_xattr_cache_list(struct list_head *cache,
char *xld_buffer,
int xld_size)
{
struct ll_xattr_entry *xattr, *tmp;
int xld_tail = 0;
list_for_each_entry_safe(xattr, tmp, cache, xe_list) {
CDEBUG(D_CACHE, "list: buffer=%p[%d] name=%s\n",
xld_buffer, xld_tail, xattr->xe_name);
if (xld_buffer) {
xld_size -= xattr->xe_namelen;
if (xld_size < 0)
break;
memcpy(&xld_buffer[xld_tail],
xattr->xe_name, xattr->xe_namelen);
}
xld_tail += xattr->xe_namelen;
}
if (xld_size < 0)
return -ERANGE;
return xld_tail;
}
static int ll_xattr_cache_valid(struct ll_inode_info *lli)
{
return !!(lli->lli_flags & LLIF_XATTR_CACHE);
}
static int ll_xattr_cache_destroy_locked(struct ll_inode_info *lli)
{
if (!ll_xattr_cache_valid(lli))
return 0;
while (ll_xattr_cache_del(&lli->lli_xattrs, NULL) == 0)
;
lli->lli_flags &= ~LLIF_XATTR_CACHE;
return 0;
}
int ll_xattr_cache_destroy(struct inode *inode)
{
struct ll_inode_info *lli = ll_i2info(inode);
int rc;
down_write(&lli->lli_xattrs_list_rwsem);
rc = ll_xattr_cache_destroy_locked(lli);
up_write(&lli->lli_xattrs_list_rwsem);
return rc;
}
static int ll_xattr_find_get_lock(struct inode *inode,
struct lookup_intent *oit,
struct ptlrpc_request **req)
{
enum ldlm_mode mode;
struct lustre_handle lockh = { 0 };
struct md_op_data *op_data;
struct ll_inode_info *lli = ll_i2info(inode);
struct ldlm_enqueue_info einfo = {
.ei_type = LDLM_IBITS,
.ei_mode = it_to_lock_mode(oit),
.ei_cb_bl = &ll_md_blocking_ast,
.ei_cb_cp = &ldlm_completion_ast,
};
struct ll_sb_info *sbi = ll_i2sbi(inode);
struct obd_export *exp = sbi->ll_md_exp;
int rc;
mutex_lock(&lli->lli_xattrs_enq_lock);
if (ll_xattr_cache_valid(lli)) {
mode = ll_take_md_lock(inode, MDS_INODELOCK_XATTR, &lockh, 0,
LCK_PR);
if (mode != 0) {
oit->it_lock_handle = lockh.cookie;
oit->it_lock_mode = mode;
goto out;
}
}
op_data = ll_prep_md_op_data(NULL, inode, NULL, NULL, 0, 0,
LUSTRE_OPC_ANY, NULL);
if (IS_ERR(op_data)) {
mutex_unlock(&lli->lli_xattrs_enq_lock);
return PTR_ERR(op_data);
}
op_data->op_valid = OBD_MD_FLXATTR | OBD_MD_FLXATTRLS;
rc = md_enqueue(exp, &einfo, NULL, oit, op_data, &lockh, 0);
ll_finish_md_op_data(op_data);
if (rc < 0) {
CDEBUG(D_CACHE,
"md_intent_lock failed with %d for fid "DFID"\n",
rc, PFID(ll_inode2fid(inode)));
mutex_unlock(&lli->lli_xattrs_enq_lock);
return rc;
}
*req = oit->it_request;
out:
down_write(&lli->lli_xattrs_list_rwsem);
mutex_unlock(&lli->lli_xattrs_enq_lock);
return 0;
}
static int ll_xattr_cache_refill(struct inode *inode, struct lookup_intent *oit)
{
struct ll_sb_info *sbi = ll_i2sbi(inode);
struct ptlrpc_request *req = NULL;
const char *xdata, *xval, *xtail, *xvtail;
struct ll_inode_info *lli = ll_i2info(inode);
struct mdt_body *body;
__u32 *xsizes;
int rc, i;
rc = ll_xattr_find_get_lock(inode, oit, &req);
if (rc)
goto out_no_unlock;
if (ll_xattr_cache_valid(lli)) {
ll_stats_ops_tally(sbi, LPROC_LL_GETXATTR_HITS, 1);
rc = 0;
goto out_maybe_drop;
}
if (unlikely(!req)) {
CDEBUG(D_CACHE, "cancelled by a parallel getxattr\n");
rc = -EIO;
goto out_maybe_drop;
}
if (oit->it_status < 0) {
CDEBUG(D_CACHE, "getxattr intent returned %d for fid "DFID"\n",
oit->it_status, PFID(ll_inode2fid(inode)));
rc = oit->it_status;
if (rc == -ERANGE)
rc = -EAGAIN;
goto out_destroy;
}
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
if (!body) {
CERROR("no MDT BODY in the refill xattr reply\n");
rc = -EPROTO;
goto out_destroy;
}
xdata = req_capsule_server_sized_get(&req->rq_pill, &RMF_EADATA,
body->mbo_eadatasize);
xval = req_capsule_server_sized_get(&req->rq_pill, &RMF_EAVALS,
body->mbo_aclsize);
xsizes = req_capsule_server_sized_get(&req->rq_pill, &RMF_EAVALS_LENS,
body->mbo_max_mdsize * sizeof(__u32));
if (!xdata || !xval || !xsizes) {
CERROR("wrong setxattr reply\n");
rc = -EPROTO;
goto out_destroy;
}
xtail = xdata + body->mbo_eadatasize;
xvtail = xval + body->mbo_aclsize;
CDEBUG(D_CACHE, "caching: xdata=%p xtail=%p\n", xdata, xtail);
ll_xattr_cache_init(lli);
for (i = 0; i < body->mbo_max_mdsize; i++) {
CDEBUG(D_CACHE, "caching [%s]=%.*s\n", xdata, *xsizes, xval);
if (!memchr(xdata, 0, xtail - xdata)) {
CERROR("xattr protocol violation (names are broken)\n");
rc = -EPROTO;
} else if (xval + *xsizes > xvtail) {
CERROR("xattr protocol violation (vals are broken)\n");
rc = -EPROTO;
} else if (OBD_FAIL_CHECK(OBD_FAIL_LLITE_XATTR_ENOMEM)) {
rc = -ENOMEM;
} else if (!strcmp(xdata, XATTR_NAME_ACL_ACCESS)) {
CDEBUG(D_CACHE, "not caching %s\n",
XATTR_NAME_ACL_ACCESS);
rc = 0;
} else {
rc = ll_xattr_cache_add(&lli->lli_xattrs, xdata, xval,
*xsizes);
}
if (rc < 0) {
ll_xattr_cache_destroy_locked(lli);
goto out_destroy;
}
xdata += strlen(xdata) + 1;
xval += *xsizes;
xsizes++;
}
if (xdata != xtail || xval != xvtail)
CERROR("a hole in xattr data\n");
ll_set_lock_data(sbi->ll_md_exp, inode, oit, NULL);
goto out_maybe_drop;
out_maybe_drop:
ll_intent_drop_lock(oit);
if (rc != 0)
up_write(&lli->lli_xattrs_list_rwsem);
out_no_unlock:
ptlrpc_req_finished(req);
return rc;
out_destroy:
up_write(&lli->lli_xattrs_list_rwsem);
ldlm_lock_decref_and_cancel((struct lustre_handle *)
&oit->it_lock_handle,
oit->it_lock_mode);
goto out_no_unlock;
}
int ll_xattr_cache_get(struct inode *inode, const char *name, char *buffer,
size_t size, __u64 valid)
{
struct lookup_intent oit = { .it_op = IT_GETXATTR };
struct ll_inode_info *lli = ll_i2info(inode);
int rc = 0;
LASSERT(!!(valid & OBD_MD_FLXATTR) ^ !!(valid & OBD_MD_FLXATTRLS));
down_read(&lli->lli_xattrs_list_rwsem);
if (!ll_xattr_cache_valid(lli)) {
up_read(&lli->lli_xattrs_list_rwsem);
rc = ll_xattr_cache_refill(inode, &oit);
if (rc)
return rc;
downgrade_write(&lli->lli_xattrs_list_rwsem);
} else {
ll_stats_ops_tally(ll_i2sbi(inode), LPROC_LL_GETXATTR_HITS, 1);
}
if (valid & OBD_MD_FLXATTR) {
struct ll_xattr_entry *xattr;
rc = ll_xattr_cache_find(&lli->lli_xattrs, name, &xattr);
if (rc == 0) {
rc = xattr->xe_vallen;
if (size != 0) {
if (size >= xattr->xe_vallen)
memcpy(buffer, xattr->xe_value,
xattr->xe_vallen);
else
rc = -ERANGE;
}
}
} else if (valid & OBD_MD_FLXATTRLS) {
rc = ll_xattr_cache_list(&lli->lli_xattrs,
size ? buffer : NULL, size);
}
goto out;
out:
up_read(&lli->lli_xattrs_list_rwsem);
return rc;
}
