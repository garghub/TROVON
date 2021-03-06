void vvp_write_pending(struct vvp_object *club, struct vvp_page *page)
{
struct ll_inode_info *lli = ll_i2info(club->vob_inode);
spin_lock(&lli->lli_lock);
lli->lli_flags |= LLIF_SOM_DIRTY;
if (page && list_empty(&page->vpg_pending_linkage))
list_add(&page->vpg_pending_linkage, &club->vob_pending_list);
spin_unlock(&lli->lli_lock);
}
void vvp_write_complete(struct vvp_object *club, struct vvp_page *page)
{
struct ll_inode_info *lli = ll_i2info(club->vob_inode);
int rc = 0;
spin_lock(&lli->lli_lock);
if (page && !list_empty(&page->vpg_pending_linkage)) {
list_del_init(&page->vpg_pending_linkage);
rc = 1;
}
spin_unlock(&lli->lli_lock);
if (rc)
ll_queue_done_writing(club->vob_inode, 0);
}
void ll_queue_done_writing(struct inode *inode, unsigned long flags)
{
struct ll_inode_info *lli = ll_i2info(inode);
struct vvp_object *club = cl2vvp(ll_i2info(inode)->lli_clob);
spin_lock(&lli->lli_lock);
lli->lli_flags |= flags;
if ((lli->lli_flags & LLIF_DONE_WRITING) &&
list_empty(&club->vob_pending_list)) {
struct ll_close_queue *lcq = ll_i2sbi(inode)->ll_lcq;
if (lli->lli_flags & LLIF_MDS_SIZE_LOCK)
CWARN("%s: file "DFID"(flags %u) Size-on-MDS valid, done writing allowed and no diry pages\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), lli->lli_flags);
spin_lock(&lcq->lcq_lock);
LASSERT(list_empty(&lli->lli_close_list));
CDEBUG(D_INODE, "adding inode "DFID" to close list\n",
PFID(ll_inode2fid(inode)));
list_add_tail(&lli->lli_close_list, &lcq->lcq_head);
lli->lli_flags &= ~LLIF_DONE_WRITING;
wake_up(&lcq->lcq_waitq);
spin_unlock(&lcq->lcq_lock);
}
spin_unlock(&lli->lli_lock);
}
void ll_done_writing_attr(struct inode *inode, struct md_op_data *op_data)
{
struct ll_inode_info *lli = ll_i2info(inode);
op_data->op_flags |= MF_SOM_CHANGE;
if (lli->lli_flags & LLIF_MDS_SIZE_LOCK)
CERROR("%s: inode "DFID"(flags %u) MDS holds lock on Size-on-MDS attributes\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), lli->lli_flags);
if (!cl_local_size(inode)) {
op_data->op_attr.ia_valid |= ATTR_MTIME_SET | ATTR_CTIME_SET |
ATTR_ATIME_SET | ATTR_SIZE | ATTR_BLOCKS;
}
}
void ll_ioepoch_close(struct inode *inode, struct md_op_data *op_data,
struct obd_client_handle **och, unsigned long flags)
{
struct ll_inode_info *lli = ll_i2info(inode);
struct vvp_object *club = cl2vvp(ll_i2info(inode)->lli_clob);
spin_lock(&lli->lli_lock);
if (!(list_empty(&club->vob_pending_list))) {
if (!(lli->lli_flags & LLIF_EPOCH_PENDING)) {
LASSERT(*och);
LASSERT(!lli->lli_pending_och);
lli->lli_flags |= LLIF_EPOCH_PENDING;
lli->lli_pending_och = *och;
spin_unlock(&lli->lli_lock);
inode = igrab(inode);
LASSERT(inode);
goto out;
}
if (flags & LLIF_DONE_WRITING) {
LASSERT(!(lli->lli_flags & LLIF_DONE_WRITING));
lli->lli_flags |= LLIF_DONE_WRITING;
spin_unlock(&lli->lli_lock);
inode = igrab(inode);
LASSERT(inode);
goto out;
}
}
CDEBUG(D_INODE, "Epoch %llu closed on "DFID"\n",
ll_i2info(inode)->lli_ioepoch, PFID(&lli->lli_fid));
op_data->op_flags |= MF_EPOCH_CLOSE;
if (flags & LLIF_DONE_WRITING) {
LASSERT(lli->lli_flags & LLIF_SOM_DIRTY);
LASSERT(!(lli->lli_flags & LLIF_DONE_WRITING));
*och = lli->lli_pending_och;
lli->lli_pending_och = NULL;
lli->lli_flags &= ~LLIF_EPOCH_PENDING;
} else {
if (!(lli->lli_flags & LLIF_SOM_DIRTY)) {
spin_unlock(&lli->lli_lock);
goto out;
}
if (lli->lli_flags & LLIF_EPOCH_PENDING) {
spin_unlock(&lli->lli_lock);
goto out;
}
}
LASSERT(list_empty(&club->vob_pending_list));
lli->lli_flags &= ~LLIF_SOM_DIRTY;
spin_unlock(&lli->lli_lock);
ll_done_writing_attr(inode, op_data);
out:
return;
}
int ll_som_update(struct inode *inode, struct md_op_data *op_data)
{
struct ll_inode_info *lli = ll_i2info(inode);
struct ptlrpc_request *request = NULL;
__u32 old_flags;
struct obdo *oa;
int rc;
LASSERT(op_data);
if (lli->lli_flags & LLIF_MDS_SIZE_LOCK)
CERROR("%s: inode "DFID"(flags %u) MDS holds lock on Size-on-MDS attributes\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), lli->lli_flags);
oa = kmem_cache_zalloc(obdo_cachep, GFP_NOFS);
if (!oa) {
CERROR("can't allocate memory for Size-on-MDS update.\n");
return -ENOMEM;
}
old_flags = op_data->op_flags;
op_data->op_flags = MF_SOM_CHANGE;
if (lli->lli_ioepoch == op_data->op_ioepoch) {
rc = ll_inode_getattr(inode, oa, op_data->op_ioepoch,
old_flags & MF_GETATTR_LOCK);
if (rc) {
oa->o_valid = 0;
if (rc != -ENOENT)
CERROR("%s: inode_getattr failed - unable to send a Size-on-MDS attribute update for inode "DFID": rc = %d\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), rc);
} else {
CDEBUG(D_INODE, "Size-on-MDS update on "DFID"\n",
PFID(&lli->lli_fid));
}
md_from_obdo(op_data, oa, oa->o_valid);
}
rc = md_setattr(ll_i2sbi(inode)->ll_md_exp, op_data,
NULL, 0, NULL, 0, &request, NULL);
ptlrpc_req_finished(request);
kmem_cache_free(obdo_cachep, oa);
return rc;
}
static void ll_prepare_done_writing(struct inode *inode,
struct md_op_data *op_data,
struct obd_client_handle **och)
{
ll_ioepoch_close(inode, op_data, och, LLIF_DONE_WRITING);
if (!*och)
return;
ll_pack_inode2opdata(inode, op_data, &(*och)->och_fh);
ll_prep_md_op_data(op_data, inode, NULL, NULL,
0, 0, LUSTRE_OPC_ANY, NULL);
}
static void ll_done_writing(struct inode *inode)
{
struct obd_client_handle *och = NULL;
struct md_op_data *op_data;
int rc;
LASSERT(exp_connect_som(ll_i2mdexp(inode)));
op_data = kzalloc(sizeof(*op_data), GFP_NOFS);
if (!op_data)
return;
ll_prepare_done_writing(inode, op_data, &och);
if (!och)
goto out;
rc = md_done_writing(ll_i2sbi(inode)->ll_md_exp, op_data, NULL);
if (rc == -EAGAIN)
rc = ll_som_update(inode, op_data);
else if (rc) {
CERROR("%s: inode "DFID" mdc done_writing failed: rc = %d\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(ll_inode2fid(inode)), rc);
}
out:
ll_finish_md_op_data(op_data);
if (och) {
md_clear_open_replay_data(ll_i2sbi(inode)->ll_md_exp, och);
kfree(och);
}
}
static struct ll_inode_info *ll_close_next_lli(struct ll_close_queue *lcq)
{
struct ll_inode_info *lli = NULL;
spin_lock(&lcq->lcq_lock);
if (!list_empty(&lcq->lcq_head)) {
lli = list_entry(lcq->lcq_head.next, struct ll_inode_info,
lli_close_list);
list_del_init(&lli->lli_close_list);
} else if (atomic_read(&lcq->lcq_stop)) {
lli = ERR_PTR(-EALREADY);
}
spin_unlock(&lcq->lcq_lock);
return lli;
}
static int ll_close_thread(void *arg)
{
struct ll_close_queue *lcq = arg;
complete(&lcq->lcq_comp);
while (1) {
struct l_wait_info lwi = { 0 };
struct ll_inode_info *lli;
struct inode *inode;
l_wait_event_exclusive(lcq->lcq_waitq,
(lli = ll_close_next_lli(lcq)) != NULL,
&lwi);
if (IS_ERR(lli))
break;
inode = ll_info2i(lli);
CDEBUG(D_INFO, "done_writing for inode "DFID"\n",
PFID(ll_inode2fid(inode)));
ll_done_writing(inode);
iput(inode);
}
CDEBUG(D_INFO, "ll_close exiting\n");
complete(&lcq->lcq_comp);
return 0;
}
int ll_close_thread_start(struct ll_close_queue **lcq_ret)
{
struct ll_close_queue *lcq;
struct task_struct *task;
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_CLOSE_THREAD))
return -EINTR;
lcq = kzalloc(sizeof(*lcq), GFP_NOFS);
if (!lcq)
return -ENOMEM;
spin_lock_init(&lcq->lcq_lock);
INIT_LIST_HEAD(&lcq->lcq_head);
init_waitqueue_head(&lcq->lcq_waitq);
init_completion(&lcq->lcq_comp);
task = kthread_run(ll_close_thread, lcq, "ll_close");
if (IS_ERR(task)) {
kfree(lcq);
return PTR_ERR(task);
}
wait_for_completion(&lcq->lcq_comp);
*lcq_ret = lcq;
return 0;
}
void ll_close_thread_shutdown(struct ll_close_queue *lcq)
{
init_completion(&lcq->lcq_comp);
atomic_inc(&lcq->lcq_stop);
wake_up(&lcq->lcq_waitq);
wait_for_completion(&lcq->lcq_comp);
kfree(lcq);
}
