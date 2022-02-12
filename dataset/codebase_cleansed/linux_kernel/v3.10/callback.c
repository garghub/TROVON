void afs_init_callback_state(struct afs_server *server)
{
struct afs_vnode *vnode;
_enter("{%p}", server);
spin_lock(&server->cb_lock);
while (!RB_EMPTY_ROOT(&server->cb_promises)) {
vnode = rb_entry(server->cb_promises.rb_node,
struct afs_vnode, cb_promise);
_debug("UNPROMISE { vid=%x:%u uq=%u}",
vnode->fid.vid, vnode->fid.vnode, vnode->fid.unique);
rb_erase(&vnode->cb_promise, &server->cb_promises);
vnode->cb_promised = false;
}
spin_unlock(&server->cb_lock);
_leave("");
}
void afs_broken_callback_work(struct work_struct *work)
{
struct afs_vnode *vnode =
container_of(work, struct afs_vnode, cb_broken_work);
_enter("");
if (test_bit(AFS_VNODE_DELETED, &vnode->flags))
return;
if (!mutex_trylock(&vnode->validate_lock))
return;
if (test_bit(AFS_VNODE_CB_BROKEN, &vnode->flags)) {
if (S_ISDIR(vnode->vfs_inode.i_mode))
afs_clear_permits(vnode);
if (afs_vnode_fetch_status(vnode, NULL, NULL) < 0)
goto out;
if (test_bit(AFS_VNODE_DELETED, &vnode->flags))
goto out;
if (test_and_clear_bit(AFS_VNODE_ZAP_DATA, &vnode->flags))
afs_zap_data(vnode);
}
out:
mutex_unlock(&vnode->validate_lock);
if (test_bit(AFS_VNODE_CB_BROKEN, &vnode->flags)) {
_debug("requeue");
queue_work(afs_callback_update_worker, &vnode->cb_broken_work);
}
_leave("");
}
static void afs_break_callback(struct afs_server *server,
struct afs_vnode *vnode)
{
_enter("");
set_bit(AFS_VNODE_CB_BROKEN, &vnode->flags);
if (vnode->cb_promised) {
spin_lock(&vnode->lock);
_debug("break callback");
spin_lock(&server->cb_lock);
if (vnode->cb_promised) {
rb_erase(&vnode->cb_promise, &server->cb_promises);
vnode->cb_promised = false;
}
spin_unlock(&server->cb_lock);
queue_work(afs_callback_update_worker, &vnode->cb_broken_work);
if (list_empty(&vnode->granted_locks) &&
!list_empty(&vnode->pending_locks))
afs_lock_may_be_available(vnode);
spin_unlock(&vnode->lock);
}
}
static void afs_break_one_callback(struct afs_server *server,
struct afs_fid *fid)
{
struct afs_vnode *vnode;
struct rb_node *p;
_debug("find");
spin_lock(&server->fs_lock);
p = server->fs_vnodes.rb_node;
while (p) {
vnode = rb_entry(p, struct afs_vnode, server_rb);
if (fid->vid < vnode->fid.vid)
p = p->rb_left;
else if (fid->vid > vnode->fid.vid)
p = p->rb_right;
else if (fid->vnode < vnode->fid.vnode)
p = p->rb_left;
else if (fid->vnode > vnode->fid.vnode)
p = p->rb_right;
else if (fid->unique < vnode->fid.unique)
p = p->rb_left;
else if (fid->unique > vnode->fid.unique)
p = p->rb_right;
else
goto found;
}
not_available:
_debug("not avail");
spin_unlock(&server->fs_lock);
_leave("");
return;
found:
_debug("found");
ASSERTCMP(server, ==, vnode->server);
if (!igrab(AFS_VNODE_TO_I(vnode)))
goto not_available;
spin_unlock(&server->fs_lock);
afs_break_callback(server, vnode);
iput(&vnode->vfs_inode);
_leave("");
}
void afs_break_callbacks(struct afs_server *server, size_t count,
struct afs_callback callbacks[])
{
_enter("%p,%zu,", server, count);
ASSERT(server != NULL);
ASSERTCMP(count, <=, AFSCBMAX);
for (; count > 0; callbacks++, count--) {
_debug("- Fid { vl=%08x n=%u u=%u } CB { v=%u x=%u t=%u }",
callbacks->fid.vid,
callbacks->fid.vnode,
callbacks->fid.unique,
callbacks->version,
callbacks->expiry,
callbacks->type
);
afs_break_one_callback(server, &callbacks->fid);
}
_leave("");
return;
}
static void afs_do_give_up_callback(struct afs_server *server,
struct afs_vnode *vnode)
{
struct afs_callback *cb;
_enter("%p,%p", server, vnode);
cb = &server->cb_break[server->cb_break_head];
cb->fid = vnode->fid;
cb->version = vnode->cb_version;
cb->expiry = vnode->cb_expiry;
cb->type = vnode->cb_type;
smp_wmb();
server->cb_break_head =
(server->cb_break_head + 1) &
(ARRAY_SIZE(server->cb_break) - 1);
switch (atomic_inc_return(&server->cb_break_n)) {
case 1 ... AFSCBMAX - 1:
queue_delayed_work(afs_callback_update_worker,
&server->cb_break_work, HZ * 2);
break;
case AFSCBMAX:
afs_flush_callback_breaks(server);
break;
default:
break;
}
ASSERT(server->cb_promises.rb_node != NULL);
rb_erase(&vnode->cb_promise, &server->cb_promises);
vnode->cb_promised = false;
_leave("");
}
void afs_discard_callback_on_delete(struct afs_vnode *vnode)
{
struct afs_server *server = vnode->server;
_enter("%d", vnode->cb_promised);
if (!vnode->cb_promised) {
_leave(" [not promised]");
return;
}
ASSERT(server != NULL);
spin_lock(&server->cb_lock);
if (vnode->cb_promised) {
ASSERT(server->cb_promises.rb_node != NULL);
rb_erase(&vnode->cb_promise, &server->cb_promises);
vnode->cb_promised = false;
}
spin_unlock(&server->cb_lock);
_leave("");
}
void afs_give_up_callback(struct afs_vnode *vnode)
{
struct afs_server *server = vnode->server;
DECLARE_WAITQUEUE(myself, current);
_enter("%d", vnode->cb_promised);
_debug("GIVE UP INODE %p", &vnode->vfs_inode);
if (!vnode->cb_promised) {
_leave(" [not promised]");
return;
}
ASSERT(server != NULL);
spin_lock(&server->cb_lock);
if (vnode->cb_promised && afs_breakring_space(server) == 0) {
add_wait_queue(&server->cb_break_waitq, &myself);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (!vnode->cb_promised ||
afs_breakring_space(server) != 0)
break;
spin_unlock(&server->cb_lock);
schedule();
spin_lock(&server->cb_lock);
}
remove_wait_queue(&server->cb_break_waitq, &myself);
__set_current_state(TASK_RUNNING);
}
if (vnode->cb_promised)
afs_do_give_up_callback(server, vnode);
spin_unlock(&server->cb_lock);
_leave("");
}
void afs_dispatch_give_up_callbacks(struct work_struct *work)
{
struct afs_server *server =
container_of(work, struct afs_server, cb_break_work.work);
_enter("");
afs_fs_give_up_callbacks(server, &afs_async_call);
}
void afs_flush_callback_breaks(struct afs_server *server)
{
mod_delayed_work(afs_callback_update_worker, &server->cb_break_work, 0);
}
int __init afs_callback_update_init(void)
{
afs_callback_update_worker =
create_singlethread_workqueue("kafs_callbackd");
return afs_callback_update_worker ? 0 : -ENOMEM;
}
void afs_callback_update_kill(void)
{
destroy_workqueue(afs_callback_update_worker);
}
