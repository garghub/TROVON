void nlmclnt_next_cookie(struct nlm_cookie *c)
{
u32 cookie = atomic_inc_return(&nlm_cookie);
memcpy(c->data, &cookie, 4);
c->len=4;
}
static struct nlm_lockowner *nlm_get_lockowner(struct nlm_lockowner *lockowner)
{
atomic_inc(&lockowner->count);
return lockowner;
}
static void nlm_put_lockowner(struct nlm_lockowner *lockowner)
{
if (!atomic_dec_and_lock(&lockowner->count, &lockowner->host->h_lock))
return;
list_del(&lockowner->list);
spin_unlock(&lockowner->host->h_lock);
nlmclnt_release_host(lockowner->host);
kfree(lockowner);
}
static inline int nlm_pidbusy(struct nlm_host *host, uint32_t pid)
{
struct nlm_lockowner *lockowner;
list_for_each_entry(lockowner, &host->h_lockowners, list) {
if (lockowner->pid == pid)
return -EBUSY;
}
return 0;
}
static inline uint32_t __nlm_alloc_pid(struct nlm_host *host)
{
uint32_t res;
do {
res = host->h_pidcount++;
} while (nlm_pidbusy(host, res) < 0);
return res;
}
static struct nlm_lockowner *__nlm_find_lockowner(struct nlm_host *host, fl_owner_t owner)
{
struct nlm_lockowner *lockowner;
list_for_each_entry(lockowner, &host->h_lockowners, list) {
if (lockowner->owner != owner)
continue;
return nlm_get_lockowner(lockowner);
}
return NULL;
}
static struct nlm_lockowner *nlm_find_lockowner(struct nlm_host *host, fl_owner_t owner)
{
struct nlm_lockowner *res, *new = NULL;
spin_lock(&host->h_lock);
res = __nlm_find_lockowner(host, owner);
if (res == NULL) {
spin_unlock(&host->h_lock);
new = kmalloc(sizeof(*new), GFP_KERNEL);
spin_lock(&host->h_lock);
res = __nlm_find_lockowner(host, owner);
if (res == NULL && new != NULL) {
res = new;
atomic_set(&new->count, 1);
new->owner = owner;
new->pid = __nlm_alloc_pid(host);
new->host = nlm_get_host(host);
list_add(&new->list, &host->h_lockowners);
new = NULL;
}
}
spin_unlock(&host->h_lock);
kfree(new);
return res;
}
static void nlmclnt_setlockargs(struct nlm_rqst *req, struct file_lock *fl)
{
struct nlm_args *argp = &req->a_args;
struct nlm_lock *lock = &argp->lock;
char *nodename = req->a_host->h_rpcclnt->cl_nodename;
nlmclnt_next_cookie(&argp->cookie);
memcpy(&lock->fh, NFS_FH(file_inode(fl->fl_file)), sizeof(struct nfs_fh));
lock->caller = nodename;
lock->oh.data = req->a_owner;
lock->oh.len = snprintf(req->a_owner, sizeof(req->a_owner), "%u@%s",
(unsigned int)fl->fl_u.nfs_fl.owner->pid,
nodename);
lock->svid = fl->fl_u.nfs_fl.owner->pid;
lock->fl.fl_start = fl->fl_start;
lock->fl.fl_end = fl->fl_end;
lock->fl.fl_type = fl->fl_type;
}
static void nlmclnt_release_lockargs(struct nlm_rqst *req)
{
WARN_ON_ONCE(req->a_args.lock.fl.fl_ops != NULL);
}
int nlmclnt_proc(struct nlm_host *host, int cmd, struct file_lock *fl)
{
struct nlm_rqst *call;
int status;
call = nlm_alloc_call(host);
if (call == NULL)
return -ENOMEM;
nlmclnt_locks_init_private(fl, host);
if (!fl->fl_u.nfs_fl.owner) {
nlmclnt_release_call(call);
return -ENOMEM;
}
nlmclnt_setlockargs(call, fl);
if (IS_SETLK(cmd) || IS_SETLKW(cmd)) {
if (fl->fl_type != F_UNLCK) {
call->a_args.block = IS_SETLKW(cmd) ? 1 : 0;
status = nlmclnt_lock(call, fl);
} else
status = nlmclnt_unlock(call, fl);
} else if (IS_GETLK(cmd))
status = nlmclnt_test(call, fl);
else
status = -EINVAL;
fl->fl_ops->fl_release_private(fl);
fl->fl_ops = NULL;
dprintk("lockd: clnt proc returns %d\n", status);
return status;
}
struct nlm_rqst *nlm_alloc_call(struct nlm_host *host)
{
struct nlm_rqst *call;
for(;;) {
call = kzalloc(sizeof(*call), GFP_KERNEL);
if (call != NULL) {
atomic_set(&call->a_count, 1);
locks_init_lock(&call->a_args.lock.fl);
locks_init_lock(&call->a_res.lock.fl);
call->a_host = nlm_get_host(host);
return call;
}
if (signalled())
break;
printk("nlm_alloc_call: failed, waiting for memory\n");
schedule_timeout_interruptible(5*HZ);
}
return NULL;
}
void nlmclnt_release_call(struct nlm_rqst *call)
{
if (!atomic_dec_and_test(&call->a_count))
return;
nlmclnt_release_host(call->a_host);
nlmclnt_release_lockargs(call);
kfree(call);
}
static void nlmclnt_rpc_release(void *data)
{
nlmclnt_release_call(data);
}
static int nlm_wait_on_grace(wait_queue_head_t *queue)
{
DEFINE_WAIT(wait);
int status = -EINTR;
prepare_to_wait(queue, &wait, TASK_INTERRUPTIBLE);
if (!signalled ()) {
schedule_timeout(NLMCLNT_GRACE_WAIT);
try_to_freeze();
if (!signalled ())
status = 0;
}
finish_wait(queue, &wait);
return status;
}
static int
nlmclnt_call(struct rpc_cred *cred, struct nlm_rqst *req, u32 proc)
{
struct nlm_host *host = req->a_host;
struct rpc_clnt *clnt;
struct nlm_args *argp = &req->a_args;
struct nlm_res *resp = &req->a_res;
struct rpc_message msg = {
.rpc_argp = argp,
.rpc_resp = resp,
.rpc_cred = cred,
};
int status;
dprintk("lockd: call procedure %d on %s\n",
(int)proc, host->h_name);
do {
if (host->h_reclaiming && !argp->reclaim)
goto in_grace_period;
if ((clnt = nlm_bind_host(host)) == NULL)
return -ENOLCK;
msg.rpc_proc = &clnt->cl_procinfo[proc];
if ((status = rpc_call_sync(clnt, &msg, 0)) < 0) {
dprintk("lockd: rpc_call returned error %d\n", -status);
switch (status) {
case -EPROTONOSUPPORT:
status = -EINVAL;
break;
case -ECONNREFUSED:
case -ETIMEDOUT:
case -ENOTCONN:
nlm_rebind_host(host);
status = -EAGAIN;
break;
case -ERESTARTSYS:
return signalled () ? -EINTR : status;
default:
break;
}
break;
} else
if (resp->status == nlm_lck_denied_grace_period) {
dprintk("lockd: server in grace period\n");
if (argp->reclaim) {
printk(KERN_WARNING
"lockd: spurious grace period reject?!\n");
return -ENOLCK;
}
} else {
if (!argp->reclaim) {
wake_up_all(&host->h_gracewait);
}
dprintk("lockd: server returns status %d\n",
ntohl(resp->status));
return 0;
}
in_grace_period:
status = nlm_wait_on_grace(&host->h_gracewait);
} while (status == 0);
return status;
}
static struct rpc_task *__nlm_async_call(struct nlm_rqst *req, u32 proc, struct rpc_message *msg, const struct rpc_call_ops *tk_ops)
{
struct nlm_host *host = req->a_host;
struct rpc_clnt *clnt;
struct rpc_task_setup task_setup_data = {
.rpc_message = msg,
.callback_ops = tk_ops,
.callback_data = req,
.flags = RPC_TASK_ASYNC,
};
dprintk("lockd: call procedure %d on %s (async)\n",
(int)proc, host->h_name);
clnt = nlm_bind_host(host);
if (clnt == NULL)
goto out_err;
msg->rpc_proc = &clnt->cl_procinfo[proc];
task_setup_data.rpc_client = clnt;
return rpc_run_task(&task_setup_data);
out_err:
tk_ops->rpc_release(req);
return ERR_PTR(-ENOLCK);
}
static int nlm_do_async_call(struct nlm_rqst *req, u32 proc, struct rpc_message *msg, const struct rpc_call_ops *tk_ops)
{
struct rpc_task *task;
task = __nlm_async_call(req, proc, msg, tk_ops);
if (IS_ERR(task))
return PTR_ERR(task);
rpc_put_task(task);
return 0;
}
int nlm_async_call(struct nlm_rqst *req, u32 proc, const struct rpc_call_ops *tk_ops)
{
struct rpc_message msg = {
.rpc_argp = &req->a_args,
.rpc_resp = &req->a_res,
};
return nlm_do_async_call(req, proc, &msg, tk_ops);
}
int nlm_async_reply(struct nlm_rqst *req, u32 proc, const struct rpc_call_ops *tk_ops)
{
struct rpc_message msg = {
.rpc_argp = &req->a_res,
};
return nlm_do_async_call(req, proc, &msg, tk_ops);
}
static int nlmclnt_async_call(struct rpc_cred *cred, struct nlm_rqst *req, u32 proc, const struct rpc_call_ops *tk_ops)
{
struct rpc_message msg = {
.rpc_argp = &req->a_args,
.rpc_resp = &req->a_res,
.rpc_cred = cred,
};
struct rpc_task *task;
int err;
task = __nlm_async_call(req, proc, &msg, tk_ops);
if (IS_ERR(task))
return PTR_ERR(task);
err = rpc_wait_for_completion_task(task);
rpc_put_task(task);
return err;
}
static int
nlmclnt_test(struct nlm_rqst *req, struct file_lock *fl)
{
int status;
status = nlmclnt_call(nfs_file_cred(fl->fl_file), req, NLMPROC_TEST);
if (status < 0)
goto out;
switch (req->a_res.status) {
case nlm_granted:
fl->fl_type = F_UNLCK;
break;
case nlm_lck_denied:
fl->fl_start = req->a_res.lock.fl.fl_start;
fl->fl_end = req->a_res.lock.fl.fl_end;
fl->fl_type = req->a_res.lock.fl.fl_type;
fl->fl_pid = 0;
break;
default:
status = nlm_stat_to_errno(req->a_res.status);
}
out:
nlmclnt_release_call(req);
return status;
}
static void nlmclnt_locks_copy_lock(struct file_lock *new, struct file_lock *fl)
{
spin_lock(&fl->fl_u.nfs_fl.owner->host->h_lock);
new->fl_u.nfs_fl.state = fl->fl_u.nfs_fl.state;
new->fl_u.nfs_fl.owner = nlm_get_lockowner(fl->fl_u.nfs_fl.owner);
list_add_tail(&new->fl_u.nfs_fl.list, &fl->fl_u.nfs_fl.owner->host->h_granted);
spin_unlock(&fl->fl_u.nfs_fl.owner->host->h_lock);
}
static void nlmclnt_locks_release_private(struct file_lock *fl)
{
spin_lock(&fl->fl_u.nfs_fl.owner->host->h_lock);
list_del(&fl->fl_u.nfs_fl.list);
spin_unlock(&fl->fl_u.nfs_fl.owner->host->h_lock);
nlm_put_lockowner(fl->fl_u.nfs_fl.owner);
}
static void nlmclnt_locks_init_private(struct file_lock *fl, struct nlm_host *host)
{
fl->fl_u.nfs_fl.state = 0;
fl->fl_u.nfs_fl.owner = nlm_find_lockowner(host, fl->fl_owner);
INIT_LIST_HEAD(&fl->fl_u.nfs_fl.list);
fl->fl_ops = &nlmclnt_lock_ops;
}
static int do_vfs_lock(struct file_lock *fl)
{
return locks_lock_file_wait(fl->fl_file, fl);
}
static int
nlmclnt_lock(struct nlm_rqst *req, struct file_lock *fl)
{
struct rpc_cred *cred = nfs_file_cred(fl->fl_file);
struct nlm_host *host = req->a_host;
struct nlm_res *resp = &req->a_res;
struct nlm_wait *block = NULL;
unsigned char fl_flags = fl->fl_flags;
unsigned char fl_type;
int status = -ENOLCK;
if (nsm_monitor(host) < 0)
goto out;
req->a_args.state = nsm_local_state;
fl->fl_flags |= FL_ACCESS;
status = do_vfs_lock(fl);
fl->fl_flags = fl_flags;
if (status < 0)
goto out;
block = nlmclnt_prepare_block(host, fl);
again:
resp->status = nlm_lck_blocked;
for(;;) {
fl->fl_u.nfs_fl.state = host->h_state;
status = nlmclnt_call(cred, req, NLMPROC_LOCK);
if (status < 0)
break;
if (resp->status == nlm_lck_denied_grace_period)
continue;
if (resp->status != nlm_lck_blocked)
break;
status = nlmclnt_block(block, req, NLMCLNT_POLL_TIMEOUT);
if (status < 0)
break;
if (resp->status != nlm_lck_blocked)
break;
}
if (resp->status == nlm_lck_blocked) {
if (!req->a_args.block)
goto out_unlock;
if (nlmclnt_cancel(host, req->a_args.block, fl) == 0)
goto out_unblock;
}
if (resp->status == nlm_granted) {
down_read(&host->h_rwsem);
if (fl->fl_u.nfs_fl.state != host->h_state) {
up_read(&host->h_rwsem);
goto again;
}
fl->fl_flags |= FL_SLEEP;
if (do_vfs_lock(fl) < 0)
printk(KERN_WARNING "%s: VFS is out of sync with lock manager!\n", __func__);
up_read(&host->h_rwsem);
fl->fl_flags = fl_flags;
status = 0;
}
if (status < 0)
goto out_unlock;
if (resp->status == nlm_lck_denied && (fl_flags & FL_SLEEP))
status = -ENOLCK;
else
status = nlm_stat_to_errno(resp->status);
out_unblock:
nlmclnt_finish_block(block);
out:
nlmclnt_release_call(req);
return status;
out_unlock:
dprintk("lockd: lock attempt ended in fatal error.\n"
" Attempting to unlock.\n");
nlmclnt_finish_block(block);
fl_type = fl->fl_type;
fl->fl_type = F_UNLCK;
down_read(&host->h_rwsem);
do_vfs_lock(fl);
up_read(&host->h_rwsem);
fl->fl_type = fl_type;
fl->fl_flags = fl_flags;
nlmclnt_async_call(cred, req, NLMPROC_UNLOCK, &nlmclnt_unlock_ops);
return status;
}
int
nlmclnt_reclaim(struct nlm_host *host, struct file_lock *fl,
struct nlm_rqst *req)
{
int status;
memset(req, 0, sizeof(*req));
locks_init_lock(&req->a_args.lock.fl);
locks_init_lock(&req->a_res.lock.fl);
req->a_host = host;
nlmclnt_setlockargs(req, fl);
req->a_args.reclaim = 1;
status = nlmclnt_call(nfs_file_cred(fl->fl_file), req, NLMPROC_LOCK);
if (status >= 0 && req->a_res.status == nlm_granted)
return 0;
printk(KERN_WARNING "lockd: failed to reclaim lock for pid %d "
"(errno %d, status %d)\n", fl->fl_pid,
status, ntohl(req->a_res.status));
return -ENOLCK;
}
static int
nlmclnt_unlock(struct nlm_rqst *req, struct file_lock *fl)
{
struct nlm_host *host = req->a_host;
struct nlm_res *resp = &req->a_res;
int status;
unsigned char fl_flags = fl->fl_flags;
fl->fl_flags |= FL_EXISTS;
down_read(&host->h_rwsem);
status = do_vfs_lock(fl);
up_read(&host->h_rwsem);
fl->fl_flags = fl_flags;
if (status == -ENOENT) {
status = 0;
goto out;
}
atomic_inc(&req->a_count);
status = nlmclnt_async_call(nfs_file_cred(fl->fl_file), req,
NLMPROC_UNLOCK, &nlmclnt_unlock_ops);
if (status < 0)
goto out;
if (resp->status == nlm_granted)
goto out;
if (resp->status != nlm_lck_denied_nolocks)
printk("lockd: unexpected unlock status: %d\n",
ntohl(resp->status));
status = -ENOLCK;
out:
nlmclnt_release_call(req);
return status;
}
static void nlmclnt_unlock_callback(struct rpc_task *task, void *data)
{
struct nlm_rqst *req = data;
u32 status = ntohl(req->a_res.status);
if (RPC_ASSASSINATED(task))
goto die;
if (task->tk_status < 0) {
dprintk("lockd: unlock failed (err = %d)\n", -task->tk_status);
switch (task->tk_status) {
case -EACCES:
case -EIO:
goto die;
default:
goto retry_rebind;
}
}
if (status == NLM_LCK_DENIED_GRACE_PERIOD) {
rpc_delay(task, NLMCLNT_GRACE_WAIT);
goto retry_unlock;
}
if (status != NLM_LCK_GRANTED)
printk(KERN_WARNING "lockd: unexpected unlock status: %d\n", status);
die:
return;
retry_rebind:
nlm_rebind_host(req->a_host);
retry_unlock:
rpc_restart_call(task);
}
static int nlmclnt_cancel(struct nlm_host *host, int block, struct file_lock *fl)
{
struct nlm_rqst *req;
int status;
dprintk("lockd: blocking lock attempt was interrupted by a signal.\n"
" Attempting to cancel lock.\n");
req = nlm_alloc_call(host);
if (!req)
return -ENOMEM;
req->a_flags = RPC_TASK_ASYNC;
nlmclnt_setlockargs(req, fl);
req->a_args.block = block;
atomic_inc(&req->a_count);
status = nlmclnt_async_call(nfs_file_cred(fl->fl_file), req,
NLMPROC_CANCEL, &nlmclnt_cancel_ops);
if (status == 0 && req->a_res.status == nlm_lck_denied)
status = -ENOLCK;
nlmclnt_release_call(req);
return status;
}
static void nlmclnt_cancel_callback(struct rpc_task *task, void *data)
{
struct nlm_rqst *req = data;
u32 status = ntohl(req->a_res.status);
if (RPC_ASSASSINATED(task))
goto die;
if (task->tk_status < 0) {
dprintk("lockd: CANCEL call error %d, retrying.\n",
task->tk_status);
goto retry_cancel;
}
dprintk("lockd: cancel status %u (task %u)\n",
status, task->tk_pid);
switch (status) {
case NLM_LCK_GRANTED:
case NLM_LCK_DENIED_GRACE_PERIOD:
case NLM_LCK_DENIED:
break;
case NLM_LCK_DENIED_NOLOCKS:
dprintk("lockd: CANCEL failed (server has no locks)\n");
goto retry_cancel;
default:
printk(KERN_NOTICE "lockd: weird return %d for CANCEL call\n",
status);
}
die:
return;
retry_cancel:
if (req->a_retries++ >= NLMCLNT_MAX_RETRIES)
goto die;
nlm_rebind_host(req->a_host);
rpc_restart_call(task);
rpc_delay(task, 30 * HZ);
}
static int
nlm_stat_to_errno(__be32 status)
{
switch(ntohl(status)) {
case NLM_LCK_GRANTED:
return 0;
case NLM_LCK_DENIED:
return -EAGAIN;
case NLM_LCK_DENIED_NOLOCKS:
case NLM_LCK_DENIED_GRACE_PERIOD:
return -ENOLCK;
case NLM_LCK_BLOCKED:
printk(KERN_NOTICE "lockd: unexpected status NLM_BLOCKED\n");
return -ENOLCK;
#ifdef CONFIG_LOCKD_V4
case NLM_DEADLCK:
return -EDEADLK;
case NLM_ROFS:
return -EROFS;
case NLM_STALE_FH:
return -ESTALE;
case NLM_FBIG:
return -EOVERFLOW;
case NLM_FAILED:
return -ENOLCK;
#endif
}
printk(KERN_NOTICE "lockd: unexpected server status %d\n",
ntohl(status));
return -ENOLCK;
}
