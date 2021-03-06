static inline struct gss_cl_ctx *
gss_get_ctx(struct gss_cl_ctx *ctx)
{
atomic_inc(&ctx->count);
return ctx;
}
static inline void
gss_put_ctx(struct gss_cl_ctx *ctx)
{
if (atomic_dec_and_test(&ctx->count))
gss_free_ctx(ctx);
}
static void
gss_cred_set_ctx(struct rpc_cred *cred, struct gss_cl_ctx *ctx)
{
struct gss_cred *gss_cred = container_of(cred, struct gss_cred, gc_base);
if (!test_bit(RPCAUTH_CRED_NEW, &cred->cr_flags))
return;
gss_get_ctx(ctx);
rcu_assign_pointer(gss_cred->gc_ctx, ctx);
set_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
smp_mb__before_clear_bit();
clear_bit(RPCAUTH_CRED_NEW, &cred->cr_flags);
}
static const void *
simple_get_bytes(const void *p, const void *end, void *res, size_t len)
{
const void *q = (const void *)((const char *)p + len);
if (unlikely(q > end || q < p))
return ERR_PTR(-EFAULT);
memcpy(res, p, len);
return q;
}
static inline const void *
simple_get_netobj(const void *p, const void *end, struct xdr_netobj *dest)
{
const void *q;
unsigned int len;
p = simple_get_bytes(p, end, &len, sizeof(len));
if (IS_ERR(p))
return p;
q = (const void *)((const char *)p + len);
if (unlikely(q > end || q < p))
return ERR_PTR(-EFAULT);
dest->data = kmemdup(p, len, GFP_NOFS);
if (unlikely(dest->data == NULL))
return ERR_PTR(-ENOMEM);
dest->len = len;
return q;
}
static struct gss_cl_ctx *
gss_cred_get_ctx(struct rpc_cred *cred)
{
struct gss_cred *gss_cred = container_of(cred, struct gss_cred, gc_base);
struct gss_cl_ctx *ctx = NULL;
rcu_read_lock();
if (gss_cred->gc_ctx)
ctx = gss_get_ctx(gss_cred->gc_ctx);
rcu_read_unlock();
return ctx;
}
static struct gss_cl_ctx *
gss_alloc_context(void)
{
struct gss_cl_ctx *ctx;
ctx = kzalloc(sizeof(*ctx), GFP_NOFS);
if (ctx != NULL) {
ctx->gc_proc = RPC_GSS_PROC_DATA;
ctx->gc_seq = 1;
spin_lock_init(&ctx->gc_seq_lock);
atomic_set(&ctx->count,1);
}
return ctx;
}
static const void *
gss_fill_context(const void *p, const void *end, struct gss_cl_ctx *ctx, struct gss_api_mech *gm)
{
const void *q;
unsigned int seclen;
unsigned int timeout;
unsigned long now = jiffies;
u32 window_size;
int ret;
p = simple_get_bytes(p, end, &timeout, sizeof(timeout));
if (IS_ERR(p))
goto err;
if (timeout == 0)
timeout = GSSD_MIN_TIMEOUT;
ctx->gc_expiry = now + ((unsigned long)timeout * HZ);
p = simple_get_bytes(p, end, &window_size, sizeof(window_size));
if (IS_ERR(p))
goto err;
ctx->gc_win = window_size;
if (ctx->gc_win == 0) {
p = simple_get_bytes(p, end, &ret, sizeof(ret));
if (!IS_ERR(p))
p = (ret == -EKEYEXPIRED) ? ERR_PTR(-EKEYEXPIRED) :
ERR_PTR(-EACCES);
goto err;
}
p = simple_get_netobj(p, end, &ctx->gc_wire_ctx);
if (IS_ERR(p))
goto err;
p = simple_get_bytes(p, end, &seclen, sizeof(seclen));
if (IS_ERR(p))
goto err;
q = (const void *)((const char *)p + seclen);
if (unlikely(q > end || q < p)) {
p = ERR_PTR(-EFAULT);
goto err;
}
ret = gss_import_sec_context(p, seclen, gm, &ctx->gc_gss_ctx, GFP_NOFS);
if (ret < 0) {
p = ERR_PTR(ret);
goto err;
}
dprintk("RPC: %s Success. gc_expiry %lu now %lu timeout %u\n",
__func__, ctx->gc_expiry, now, timeout);
return q;
err:
dprintk("RPC: %s returns %ld gc_expiry %lu now %lu timeout %u\n",
__func__, -PTR_ERR(p), ctx->gc_expiry, now, timeout);
return p;
}
static int get_pipe_version(void)
{
int ret;
spin_lock(&pipe_version_lock);
if (pipe_version >= 0) {
atomic_inc(&pipe_users);
ret = pipe_version;
} else
ret = -EAGAIN;
spin_unlock(&pipe_version_lock);
return ret;
}
static void put_pipe_version(void)
{
if (atomic_dec_and_lock(&pipe_users, &pipe_version_lock)) {
pipe_version = -1;
spin_unlock(&pipe_version_lock);
}
}
static void
gss_release_msg(struct gss_upcall_msg *gss_msg)
{
if (!atomic_dec_and_test(&gss_msg->count))
return;
put_pipe_version();
BUG_ON(!list_empty(&gss_msg->list));
if (gss_msg->ctx != NULL)
gss_put_ctx(gss_msg->ctx);
rpc_destroy_wait_queue(&gss_msg->rpc_waitqueue);
kfree(gss_msg);
}
static struct gss_upcall_msg *
__gss_find_upcall(struct rpc_pipe *pipe, uid_t uid)
{
struct gss_upcall_msg *pos;
list_for_each_entry(pos, &pipe->in_downcall, list) {
if (pos->uid != uid)
continue;
atomic_inc(&pos->count);
dprintk("RPC: %s found msg %p\n", __func__, pos);
return pos;
}
dprintk("RPC: %s found nothing\n", __func__);
return NULL;
}
static inline struct gss_upcall_msg *
gss_add_msg(struct gss_upcall_msg *gss_msg)
{
struct rpc_pipe *pipe = gss_msg->pipe;
struct gss_upcall_msg *old;
spin_lock(&pipe->lock);
old = __gss_find_upcall(pipe, gss_msg->uid);
if (old == NULL) {
atomic_inc(&gss_msg->count);
list_add(&gss_msg->list, &pipe->in_downcall);
} else
gss_msg = old;
spin_unlock(&pipe->lock);
return gss_msg;
}
static void
__gss_unhash_msg(struct gss_upcall_msg *gss_msg)
{
list_del_init(&gss_msg->list);
rpc_wake_up_status(&gss_msg->rpc_waitqueue, gss_msg->msg.errno);
wake_up_all(&gss_msg->waitqueue);
atomic_dec(&gss_msg->count);
}
static void
gss_unhash_msg(struct gss_upcall_msg *gss_msg)
{
struct rpc_pipe *pipe = gss_msg->pipe;
if (list_empty(&gss_msg->list))
return;
spin_lock(&pipe->lock);
if (!list_empty(&gss_msg->list))
__gss_unhash_msg(gss_msg);
spin_unlock(&pipe->lock);
}
static void
gss_handle_downcall_result(struct gss_cred *gss_cred, struct gss_upcall_msg *gss_msg)
{
switch (gss_msg->msg.errno) {
case 0:
if (gss_msg->ctx == NULL)
break;
clear_bit(RPCAUTH_CRED_NEGATIVE, &gss_cred->gc_base.cr_flags);
gss_cred_set_ctx(&gss_cred->gc_base, gss_msg->ctx);
break;
case -EKEYEXPIRED:
set_bit(RPCAUTH_CRED_NEGATIVE, &gss_cred->gc_base.cr_flags);
}
gss_cred->gc_upcall_timestamp = jiffies;
gss_cred->gc_upcall = NULL;
rpc_wake_up_status(&gss_msg->rpc_waitqueue, gss_msg->msg.errno);
}
static void
gss_upcall_callback(struct rpc_task *task)
{
struct gss_cred *gss_cred = container_of(task->tk_rqstp->rq_cred,
struct gss_cred, gc_base);
struct gss_upcall_msg *gss_msg = gss_cred->gc_upcall;
struct rpc_pipe *pipe = gss_msg->pipe;
spin_lock(&pipe->lock);
gss_handle_downcall_result(gss_cred, gss_msg);
spin_unlock(&pipe->lock);
task->tk_status = gss_msg->msg.errno;
gss_release_msg(gss_msg);
}
static void gss_encode_v0_msg(struct gss_upcall_msg *gss_msg)
{
gss_msg->msg.data = &gss_msg->uid;
gss_msg->msg.len = sizeof(gss_msg->uid);
}
static void gss_encode_v1_msg(struct gss_upcall_msg *gss_msg,
struct rpc_clnt *clnt,
const char *service_name)
{
struct gss_api_mech *mech = gss_msg->auth->mech;
char *p = gss_msg->databuf;
int len = 0;
gss_msg->msg.len = sprintf(gss_msg->databuf, "mech=%s uid=%d ",
mech->gm_name,
gss_msg->uid);
p += gss_msg->msg.len;
if (clnt->cl_principal) {
len = sprintf(p, "target=%s ", clnt->cl_principal);
p += len;
gss_msg->msg.len += len;
}
if (service_name != NULL) {
len = sprintf(p, "service=%s ", service_name);
p += len;
gss_msg->msg.len += len;
}
if (mech->gm_upcall_enctypes) {
len = sprintf(p, "enctypes=%s ", mech->gm_upcall_enctypes);
p += len;
gss_msg->msg.len += len;
}
len = sprintf(p, "\n");
gss_msg->msg.len += len;
gss_msg->msg.data = gss_msg->databuf;
BUG_ON(gss_msg->msg.len > UPCALL_BUF_LEN);
}
static void gss_encode_msg(struct gss_upcall_msg *gss_msg,
struct rpc_clnt *clnt,
const char *service_name)
{
if (pipe_version == 0)
gss_encode_v0_msg(gss_msg);
else
gss_encode_v1_msg(gss_msg, clnt, service_name);
}
static struct gss_upcall_msg *
gss_alloc_msg(struct gss_auth *gss_auth, struct rpc_clnt *clnt,
uid_t uid, const char *service_name)
{
struct gss_upcall_msg *gss_msg;
int vers;
gss_msg = kzalloc(sizeof(*gss_msg), GFP_NOFS);
if (gss_msg == NULL)
return ERR_PTR(-ENOMEM);
vers = get_pipe_version();
if (vers < 0) {
kfree(gss_msg);
return ERR_PTR(vers);
}
gss_msg->pipe = gss_auth->pipe[vers];
INIT_LIST_HEAD(&gss_msg->list);
rpc_init_wait_queue(&gss_msg->rpc_waitqueue, "RPCSEC_GSS upcall waitq");
init_waitqueue_head(&gss_msg->waitqueue);
atomic_set(&gss_msg->count, 1);
gss_msg->uid = uid;
gss_msg->auth = gss_auth;
gss_encode_msg(gss_msg, clnt, service_name);
return gss_msg;
}
static struct gss_upcall_msg *
gss_setup_upcall(struct rpc_clnt *clnt, struct gss_auth *gss_auth, struct rpc_cred *cred)
{
struct gss_cred *gss_cred = container_of(cred,
struct gss_cred, gc_base);
struct gss_upcall_msg *gss_new, *gss_msg;
uid_t uid = cred->cr_uid;
gss_new = gss_alloc_msg(gss_auth, clnt, uid, gss_cred->gc_principal);
if (IS_ERR(gss_new))
return gss_new;
gss_msg = gss_add_msg(gss_new);
if (gss_msg == gss_new) {
int res = rpc_queue_upcall(gss_new->pipe, &gss_new->msg);
if (res) {
gss_unhash_msg(gss_new);
gss_msg = ERR_PTR(res);
}
} else
gss_release_msg(gss_new);
return gss_msg;
}
static void warn_gssd(void)
{
static unsigned long ratelimit;
unsigned long now = jiffies;
if (time_after(now, ratelimit)) {
printk(KERN_WARNING "RPC: AUTH_GSS upcall timed out.\n"
"Please check user daemon is running.\n");
ratelimit = now + 15*HZ;
}
}
static inline int
gss_refresh_upcall(struct rpc_task *task)
{
struct rpc_cred *cred = task->tk_rqstp->rq_cred;
struct gss_auth *gss_auth = container_of(cred->cr_auth,
struct gss_auth, rpc_auth);
struct gss_cred *gss_cred = container_of(cred,
struct gss_cred, gc_base);
struct gss_upcall_msg *gss_msg;
struct rpc_pipe *pipe;
int err = 0;
dprintk("RPC: %5u %s for uid %u\n",
task->tk_pid, __func__, cred->cr_uid);
gss_msg = gss_setup_upcall(task->tk_client, gss_auth, cred);
if (PTR_ERR(gss_msg) == -EAGAIN) {
warn_gssd();
task->tk_timeout = 15*HZ;
rpc_sleep_on(&pipe_version_rpc_waitqueue, task, NULL);
return -EAGAIN;
}
if (IS_ERR(gss_msg)) {
err = PTR_ERR(gss_msg);
goto out;
}
pipe = gss_msg->pipe;
spin_lock(&pipe->lock);
if (gss_cred->gc_upcall != NULL)
rpc_sleep_on(&gss_cred->gc_upcall->rpc_waitqueue, task, NULL);
else if (gss_msg->ctx == NULL && gss_msg->msg.errno >= 0) {
task->tk_timeout = 0;
gss_cred->gc_upcall = gss_msg;
atomic_inc(&gss_msg->count);
rpc_sleep_on(&gss_msg->rpc_waitqueue, task, gss_upcall_callback);
} else {
gss_handle_downcall_result(gss_cred, gss_msg);
err = gss_msg->msg.errno;
}
spin_unlock(&pipe->lock);
gss_release_msg(gss_msg);
out:
dprintk("RPC: %5u %s for uid %u result %d\n",
task->tk_pid, __func__, cred->cr_uid, err);
return err;
}
static inline int
gss_create_upcall(struct gss_auth *gss_auth, struct gss_cred *gss_cred)
{
struct rpc_pipe *pipe;
struct rpc_cred *cred = &gss_cred->gc_base;
struct gss_upcall_msg *gss_msg;
DEFINE_WAIT(wait);
int err = 0;
dprintk("RPC: %s for uid %u\n", __func__, cred->cr_uid);
retry:
gss_msg = gss_setup_upcall(gss_auth->client, gss_auth, cred);
if (PTR_ERR(gss_msg) == -EAGAIN) {
err = wait_event_interruptible_timeout(pipe_version_waitqueue,
pipe_version >= 0, 15*HZ);
if (pipe_version < 0) {
warn_gssd();
err = -EACCES;
}
if (err)
goto out;
goto retry;
}
if (IS_ERR(gss_msg)) {
err = PTR_ERR(gss_msg);
goto out;
}
pipe = gss_msg->pipe;
for (;;) {
prepare_to_wait(&gss_msg->waitqueue, &wait, TASK_KILLABLE);
spin_lock(&pipe->lock);
if (gss_msg->ctx != NULL || gss_msg->msg.errno < 0) {
break;
}
spin_unlock(&pipe->lock);
if (fatal_signal_pending(current)) {
err = -ERESTARTSYS;
goto out_intr;
}
schedule();
}
if (gss_msg->ctx)
gss_cred_set_ctx(cred, gss_msg->ctx);
else
err = gss_msg->msg.errno;
spin_unlock(&pipe->lock);
out_intr:
finish_wait(&gss_msg->waitqueue, &wait);
gss_release_msg(gss_msg);
out:
dprintk("RPC: %s for uid %u result %d\n",
__func__, cred->cr_uid, err);
return err;
}
static ssize_t
gss_pipe_downcall(struct file *filp, const char __user *src, size_t mlen)
{
const void *p, *end;
void *buf;
struct gss_upcall_msg *gss_msg;
struct rpc_pipe *pipe = RPC_I(filp->f_dentry->d_inode)->pipe;
struct gss_cl_ctx *ctx;
uid_t uid;
ssize_t err = -EFBIG;
if (mlen > MSG_BUF_MAXSIZE)
goto out;
err = -ENOMEM;
buf = kmalloc(mlen, GFP_NOFS);
if (!buf)
goto out;
err = -EFAULT;
if (copy_from_user(buf, src, mlen))
goto err;
end = (const void *)((char *)buf + mlen);
p = simple_get_bytes(buf, end, &uid, sizeof(uid));
if (IS_ERR(p)) {
err = PTR_ERR(p);
goto err;
}
err = -ENOMEM;
ctx = gss_alloc_context();
if (ctx == NULL)
goto err;
err = -ENOENT;
spin_lock(&pipe->lock);
gss_msg = __gss_find_upcall(pipe, uid);
if (gss_msg == NULL) {
spin_unlock(&pipe->lock);
goto err_put_ctx;
}
list_del_init(&gss_msg->list);
spin_unlock(&pipe->lock);
p = gss_fill_context(p, end, ctx, gss_msg->auth->mech);
if (IS_ERR(p)) {
err = PTR_ERR(p);
switch (err) {
case -EACCES:
case -EKEYEXPIRED:
gss_msg->msg.errno = err;
err = mlen;
break;
case -EFAULT:
case -ENOMEM:
case -EINVAL:
case -ENOSYS:
gss_msg->msg.errno = -EAGAIN;
break;
default:
printk(KERN_CRIT "%s: bad return from "
"gss_fill_context: %zd\n", __func__, err);
BUG();
}
goto err_release_msg;
}
gss_msg->ctx = gss_get_ctx(ctx);
err = mlen;
err_release_msg:
spin_lock(&pipe->lock);
__gss_unhash_msg(gss_msg);
spin_unlock(&pipe->lock);
gss_release_msg(gss_msg);
err_put_ctx:
gss_put_ctx(ctx);
err:
kfree(buf);
out:
dprintk("RPC: %s returning %Zd\n", __func__, err);
return err;
}
static int gss_pipe_open(struct inode *inode, int new_version)
{
int ret = 0;
spin_lock(&pipe_version_lock);
if (pipe_version < 0) {
pipe_version = new_version;
rpc_wake_up(&pipe_version_rpc_waitqueue);
wake_up(&pipe_version_waitqueue);
} else if (pipe_version != new_version) {
ret = -EBUSY;
goto out;
}
atomic_inc(&pipe_users);
out:
spin_unlock(&pipe_version_lock);
return ret;
}
static int gss_pipe_open_v0(struct inode *inode)
{
return gss_pipe_open(inode, 0);
}
static int gss_pipe_open_v1(struct inode *inode)
{
return gss_pipe_open(inode, 1);
}
static void
gss_pipe_release(struct inode *inode)
{
struct rpc_pipe *pipe = RPC_I(inode)->pipe;
struct gss_upcall_msg *gss_msg;
restart:
spin_lock(&pipe->lock);
list_for_each_entry(gss_msg, &pipe->in_downcall, list) {
if (!list_empty(&gss_msg->msg.list))
continue;
gss_msg->msg.errno = -EPIPE;
atomic_inc(&gss_msg->count);
__gss_unhash_msg(gss_msg);
spin_unlock(&pipe->lock);
gss_release_msg(gss_msg);
goto restart;
}
spin_unlock(&pipe->lock);
put_pipe_version();
}
static void
gss_pipe_destroy_msg(struct rpc_pipe_msg *msg)
{
struct gss_upcall_msg *gss_msg = container_of(msg, struct gss_upcall_msg, msg);
if (msg->errno < 0) {
dprintk("RPC: %s releasing msg %p\n",
__func__, gss_msg);
atomic_inc(&gss_msg->count);
gss_unhash_msg(gss_msg);
if (msg->errno == -ETIMEDOUT)
warn_gssd();
gss_release_msg(gss_msg);
}
}
static void gss_pipes_dentries_destroy(struct rpc_auth *auth)
{
struct gss_auth *gss_auth;
gss_auth = container_of(auth, struct gss_auth, rpc_auth);
if (gss_auth->pipe[0]->dentry)
rpc_unlink(gss_auth->pipe[0]->dentry);
if (gss_auth->pipe[1]->dentry)
rpc_unlink(gss_auth->pipe[1]->dentry);
}
static int gss_pipes_dentries_create(struct rpc_auth *auth)
{
int err;
struct gss_auth *gss_auth;
struct rpc_clnt *clnt;
gss_auth = container_of(auth, struct gss_auth, rpc_auth);
clnt = gss_auth->client;
gss_auth->pipe[1]->dentry = rpc_mkpipe_dentry(clnt->cl_dentry,
"gssd",
clnt, gss_auth->pipe[1]);
if (IS_ERR(gss_auth->pipe[1]->dentry))
return PTR_ERR(gss_auth->pipe[1]->dentry);
gss_auth->pipe[0]->dentry = rpc_mkpipe_dentry(clnt->cl_dentry,
gss_auth->mech->gm_name,
clnt, gss_auth->pipe[0]);
if (IS_ERR(gss_auth->pipe[0]->dentry)) {
err = PTR_ERR(gss_auth->pipe[0]->dentry);
goto err_unlink_pipe_1;
}
return 0;
err_unlink_pipe_1:
rpc_unlink(gss_auth->pipe[1]->dentry);
return err;
}
static void gss_pipes_dentries_destroy_net(struct rpc_clnt *clnt,
struct rpc_auth *auth)
{
struct net *net = rpc_net_ns(clnt);
struct super_block *sb;
sb = rpc_get_sb_net(net);
if (sb) {
if (clnt->cl_dentry)
gss_pipes_dentries_destroy(auth);
rpc_put_sb_net(net);
}
}
static int gss_pipes_dentries_create_net(struct rpc_clnt *clnt,
struct rpc_auth *auth)
{
struct net *net = rpc_net_ns(clnt);
struct super_block *sb;
int err = 0;
sb = rpc_get_sb_net(net);
if (sb) {
if (clnt->cl_dentry)
err = gss_pipes_dentries_create(auth);
rpc_put_sb_net(net);
}
return err;
}
static struct rpc_auth *
gss_create(struct rpc_clnt *clnt, rpc_authflavor_t flavor)
{
struct gss_auth *gss_auth;
struct rpc_auth * auth;
int err = -ENOMEM;
dprintk("RPC: creating GSS authenticator for client %p\n", clnt);
if (!try_module_get(THIS_MODULE))
return ERR_PTR(err);
if (!(gss_auth = kmalloc(sizeof(*gss_auth), GFP_KERNEL)))
goto out_dec;
gss_auth->client = clnt;
err = -EINVAL;
gss_auth->mech = gss_mech_get_by_pseudoflavor(flavor);
if (!gss_auth->mech) {
printk(KERN_WARNING "%s: Pseudoflavor %d not found!\n",
__func__, flavor);
goto err_free;
}
gss_auth->service = gss_pseudoflavor_to_service(gss_auth->mech, flavor);
if (gss_auth->service == 0)
goto err_put_mech;
auth = &gss_auth->rpc_auth;
auth->au_cslack = GSS_CRED_SLACK >> 2;
auth->au_rslack = GSS_VERF_SLACK >> 2;
auth->au_ops = &authgss_ops;
auth->au_flavor = flavor;
atomic_set(&auth->au_count, 1);
kref_init(&gss_auth->kref);
gss_auth->pipe[1] = rpc_mkpipe_data(&gss_upcall_ops_v1,
RPC_PIPE_WAIT_FOR_OPEN);
if (IS_ERR(gss_auth->pipe[1])) {
err = PTR_ERR(gss_auth->pipe[1]);
goto err_put_mech;
}
gss_auth->pipe[0] = rpc_mkpipe_data(&gss_upcall_ops_v0,
RPC_PIPE_WAIT_FOR_OPEN);
if (IS_ERR(gss_auth->pipe[0])) {
err = PTR_ERR(gss_auth->pipe[0]);
goto err_destroy_pipe_1;
}
err = gss_pipes_dentries_create_net(clnt, auth);
if (err)
goto err_destroy_pipe_0;
err = rpcauth_init_credcache(auth);
if (err)
goto err_unlink_pipes;
return auth;
err_unlink_pipes:
gss_pipes_dentries_destroy_net(clnt, auth);
err_destroy_pipe_0:
rpc_destroy_pipe_data(gss_auth->pipe[0]);
err_destroy_pipe_1:
rpc_destroy_pipe_data(gss_auth->pipe[1]);
err_put_mech:
gss_mech_put(gss_auth->mech);
err_free:
kfree(gss_auth);
out_dec:
module_put(THIS_MODULE);
return ERR_PTR(err);
}
static void
gss_free(struct gss_auth *gss_auth)
{
gss_pipes_dentries_destroy_net(gss_auth->client, &gss_auth->rpc_auth);
rpc_destroy_pipe_data(gss_auth->pipe[0]);
rpc_destroy_pipe_data(gss_auth->pipe[1]);
gss_mech_put(gss_auth->mech);
kfree(gss_auth);
module_put(THIS_MODULE);
}
static void
gss_free_callback(struct kref *kref)
{
struct gss_auth *gss_auth = container_of(kref, struct gss_auth, kref);
gss_free(gss_auth);
}
static void
gss_destroy(struct rpc_auth *auth)
{
struct gss_auth *gss_auth;
dprintk("RPC: destroying GSS authenticator %p flavor %d\n",
auth, auth->au_flavor);
rpcauth_destroy_credcache(auth);
gss_auth = container_of(auth, struct gss_auth, rpc_auth);
kref_put(&gss_auth->kref, gss_free_callback);
}
static int
gss_destroying_context(struct rpc_cred *cred)
{
struct gss_cred *gss_cred = container_of(cred, struct gss_cred, gc_base);
struct gss_auth *gss_auth = container_of(cred->cr_auth, struct gss_auth, rpc_auth);
struct rpc_task *task;
if (gss_cred->gc_ctx == NULL ||
test_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags) == 0)
return 0;
gss_cred->gc_ctx->gc_proc = RPC_GSS_PROC_DESTROY;
cred->cr_ops = &gss_nullops;
get_rpccred(cred);
task = rpc_call_null(gss_auth->client, cred, RPC_TASK_ASYNC|RPC_TASK_SOFT);
if (!IS_ERR(task))
rpc_put_task(task);
put_rpccred(cred);
return 1;
}
static void
gss_do_free_ctx(struct gss_cl_ctx *ctx)
{
dprintk("RPC: %s\n", __func__);
gss_delete_sec_context(&ctx->gc_gss_ctx);
kfree(ctx->gc_wire_ctx.data);
kfree(ctx);
}
static void
gss_free_ctx_callback(struct rcu_head *head)
{
struct gss_cl_ctx *ctx = container_of(head, struct gss_cl_ctx, gc_rcu);
gss_do_free_ctx(ctx);
}
static void
gss_free_ctx(struct gss_cl_ctx *ctx)
{
call_rcu(&ctx->gc_rcu, gss_free_ctx_callback);
}
static void
gss_free_cred(struct gss_cred *gss_cred)
{
dprintk("RPC: %s cred=%p\n", __func__, gss_cred);
kfree(gss_cred);
}
static void
gss_free_cred_callback(struct rcu_head *head)
{
struct gss_cred *gss_cred = container_of(head, struct gss_cred, gc_base.cr_rcu);
gss_free_cred(gss_cred);
}
static void
gss_destroy_nullcred(struct rpc_cred *cred)
{
struct gss_cred *gss_cred = container_of(cred, struct gss_cred, gc_base);
struct gss_auth *gss_auth = container_of(cred->cr_auth, struct gss_auth, rpc_auth);
struct gss_cl_ctx *ctx = gss_cred->gc_ctx;
RCU_INIT_POINTER(gss_cred->gc_ctx, NULL);
call_rcu(&cred->cr_rcu, gss_free_cred_callback);
if (ctx)
gss_put_ctx(ctx);
kref_put(&gss_auth->kref, gss_free_callback);
}
static void
gss_destroy_cred(struct rpc_cred *cred)
{
if (gss_destroying_context(cred))
return;
gss_destroy_nullcred(cred);
}
static struct rpc_cred *
gss_lookup_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
return rpcauth_lookup_credcache(auth, acred, flags);
}
static struct rpc_cred *
gss_create_cred(struct rpc_auth *auth, struct auth_cred *acred, int flags)
{
struct gss_auth *gss_auth = container_of(auth, struct gss_auth, rpc_auth);
struct gss_cred *cred = NULL;
int err = -ENOMEM;
dprintk("RPC: %s for uid %d, flavor %d\n",
__func__, acred->uid, auth->au_flavor);
if (!(cred = kzalloc(sizeof(*cred), GFP_NOFS)))
goto out_err;
rpcauth_init_cred(&cred->gc_base, acred, auth, &gss_credops);
cred->gc_base.cr_flags = 1UL << RPCAUTH_CRED_NEW;
cred->gc_service = gss_auth->service;
cred->gc_principal = NULL;
if (acred->machine_cred)
cred->gc_principal = acred->principal;
kref_get(&gss_auth->kref);
return &cred->gc_base;
out_err:
dprintk("RPC: %s failed with error %d\n", __func__, err);
return ERR_PTR(err);
}
static int
gss_cred_init(struct rpc_auth *auth, struct rpc_cred *cred)
{
struct gss_auth *gss_auth = container_of(auth, struct gss_auth, rpc_auth);
struct gss_cred *gss_cred = container_of(cred,struct gss_cred, gc_base);
int err;
do {
err = gss_create_upcall(gss_auth, gss_cred);
} while (err == -EAGAIN);
return err;
}
static int
gss_match(struct auth_cred *acred, struct rpc_cred *rc, int flags)
{
struct gss_cred *gss_cred = container_of(rc, struct gss_cred, gc_base);
if (test_bit(RPCAUTH_CRED_NEW, &rc->cr_flags))
goto out;
if (time_after(jiffies, gss_cred->gc_ctx->gc_expiry))
return 0;
if (!test_bit(RPCAUTH_CRED_UPTODATE, &rc->cr_flags))
return 0;
out:
if (acred->principal != NULL) {
if (gss_cred->gc_principal == NULL)
return 0;
return strcmp(acred->principal, gss_cred->gc_principal) == 0;
}
if (gss_cred->gc_principal != NULL)
return 0;
return rc->cr_uid == acred->uid;
}
static __be32 *
gss_marshal(struct rpc_task *task, __be32 *p)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_cred *cred = req->rq_cred;
struct gss_cred *gss_cred = container_of(cred, struct gss_cred,
gc_base);
struct gss_cl_ctx *ctx = gss_cred_get_ctx(cred);
__be32 *cred_len;
u32 maj_stat = 0;
struct xdr_netobj mic;
struct kvec iov;
struct xdr_buf verf_buf;
dprintk("RPC: %5u %s\n", task->tk_pid, __func__);
*p++ = htonl(RPC_AUTH_GSS);
cred_len = p++;
spin_lock(&ctx->gc_seq_lock);
req->rq_seqno = ctx->gc_seq++;
spin_unlock(&ctx->gc_seq_lock);
*p++ = htonl((u32) RPC_GSS_VERSION);
*p++ = htonl((u32) ctx->gc_proc);
*p++ = htonl((u32) req->rq_seqno);
*p++ = htonl((u32) gss_cred->gc_service);
p = xdr_encode_netobj(p, &ctx->gc_wire_ctx);
*cred_len = htonl((p - (cred_len + 1)) << 2);
iov.iov_base = xprt_skip_transport_header(task->tk_xprt,
req->rq_snd_buf.head[0].iov_base);
iov.iov_len = (u8 *)p - (u8 *)iov.iov_base;
xdr_buf_from_iov(&iov, &verf_buf);
*p++ = htonl(RPC_AUTH_GSS);
mic.data = (u8 *)(p + 1);
maj_stat = gss_get_mic(ctx->gc_gss_ctx, &verf_buf, &mic);
if (maj_stat == GSS_S_CONTEXT_EXPIRED) {
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
} else if (maj_stat != 0) {
printk("gss_marshal: gss_get_mic FAILED (%d)\n", maj_stat);
goto out_put_ctx;
}
p = xdr_encode_opaque(p, NULL, mic.len);
gss_put_ctx(ctx);
return p;
out_put_ctx:
gss_put_ctx(ctx);
return NULL;
}
static int gss_renew_cred(struct rpc_task *task)
{
struct rpc_cred *oldcred = task->tk_rqstp->rq_cred;
struct gss_cred *gss_cred = container_of(oldcred,
struct gss_cred,
gc_base);
struct rpc_auth *auth = oldcred->cr_auth;
struct auth_cred acred = {
.uid = oldcred->cr_uid,
.principal = gss_cred->gc_principal,
.machine_cred = (gss_cred->gc_principal != NULL ? 1 : 0),
};
struct rpc_cred *new;
new = gss_lookup_cred(auth, &acred, RPCAUTH_LOOKUP_NEW);
if (IS_ERR(new))
return PTR_ERR(new);
task->tk_rqstp->rq_cred = new;
put_rpccred(oldcred);
return 0;
}
static int gss_cred_is_negative_entry(struct rpc_cred *cred)
{
if (test_bit(RPCAUTH_CRED_NEGATIVE, &cred->cr_flags)) {
unsigned long now = jiffies;
unsigned long begin, expire;
struct gss_cred *gss_cred;
gss_cred = container_of(cred, struct gss_cred, gc_base);
begin = gss_cred->gc_upcall_timestamp;
expire = begin + gss_expired_cred_retry_delay * HZ;
if (time_in_range_open(now, begin, expire))
return 1;
}
return 0;
}
static int
gss_refresh(struct rpc_task *task)
{
struct rpc_cred *cred = task->tk_rqstp->rq_cred;
int ret = 0;
if (gss_cred_is_negative_entry(cred))
return -EKEYEXPIRED;
if (!test_bit(RPCAUTH_CRED_NEW, &cred->cr_flags) &&
!test_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags)) {
ret = gss_renew_cred(task);
if (ret < 0)
goto out;
cred = task->tk_rqstp->rq_cred;
}
if (test_bit(RPCAUTH_CRED_NEW, &cred->cr_flags))
ret = gss_refresh_upcall(task);
out:
return ret;
}
static int
gss_refresh_null(struct rpc_task *task)
{
return -EACCES;
}
static __be32 *
gss_validate(struct rpc_task *task, __be32 *p)
{
struct rpc_cred *cred = task->tk_rqstp->rq_cred;
struct gss_cl_ctx *ctx = gss_cred_get_ctx(cred);
__be32 seq;
struct kvec iov;
struct xdr_buf verf_buf;
struct xdr_netobj mic;
u32 flav,len;
u32 maj_stat;
dprintk("RPC: %5u %s\n", task->tk_pid, __func__);
flav = ntohl(*p++);
if ((len = ntohl(*p++)) > RPC_MAX_AUTH_SIZE)
goto out_bad;
if (flav != RPC_AUTH_GSS)
goto out_bad;
seq = htonl(task->tk_rqstp->rq_seqno);
iov.iov_base = &seq;
iov.iov_len = sizeof(seq);
xdr_buf_from_iov(&iov, &verf_buf);
mic.data = (u8 *)p;
mic.len = len;
maj_stat = gss_verify_mic(ctx->gc_gss_ctx, &verf_buf, &mic);
if (maj_stat == GSS_S_CONTEXT_EXPIRED)
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
if (maj_stat) {
dprintk("RPC: %5u %s: gss_verify_mic returned error 0x%08x\n",
task->tk_pid, __func__, maj_stat);
goto out_bad;
}
cred->cr_auth->au_verfsize = XDR_QUADLEN(len) + 2;
gss_put_ctx(ctx);
dprintk("RPC: %5u %s: gss_verify_mic succeeded.\n",
task->tk_pid, __func__);
return p + XDR_QUADLEN(len);
out_bad:
gss_put_ctx(ctx);
dprintk("RPC: %5u %s failed.\n", task->tk_pid, __func__);
return NULL;
}
static void gss_wrap_req_encode(kxdreproc_t encode, struct rpc_rqst *rqstp,
__be32 *p, void *obj)
{
struct xdr_stream xdr;
xdr_init_encode(&xdr, &rqstp->rq_snd_buf, p);
encode(rqstp, &xdr, obj);
}
static inline int
gss_wrap_req_integ(struct rpc_cred *cred, struct gss_cl_ctx *ctx,
kxdreproc_t encode, struct rpc_rqst *rqstp,
__be32 *p, void *obj)
{
struct xdr_buf *snd_buf = &rqstp->rq_snd_buf;
struct xdr_buf integ_buf;
__be32 *integ_len = NULL;
struct xdr_netobj mic;
u32 offset;
__be32 *q;
struct kvec *iov;
u32 maj_stat = 0;
int status = -EIO;
integ_len = p++;
offset = (u8 *)p - (u8 *)snd_buf->head[0].iov_base;
*p++ = htonl(rqstp->rq_seqno);
gss_wrap_req_encode(encode, rqstp, p, obj);
if (xdr_buf_subsegment(snd_buf, &integ_buf,
offset, snd_buf->len - offset))
return status;
*integ_len = htonl(integ_buf.len);
if (snd_buf->page_len || snd_buf->tail[0].iov_len)
iov = snd_buf->tail;
else
iov = snd_buf->head;
p = iov->iov_base + iov->iov_len;
mic.data = (u8 *)(p + 1);
maj_stat = gss_get_mic(ctx->gc_gss_ctx, &integ_buf, &mic);
status = -EIO;
if (maj_stat == GSS_S_CONTEXT_EXPIRED)
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
else if (maj_stat)
return status;
q = xdr_encode_opaque(p, NULL, mic.len);
offset = (u8 *)q - (u8 *)p;
iov->iov_len += offset;
snd_buf->len += offset;
return 0;
}
static void
priv_release_snd_buf(struct rpc_rqst *rqstp)
{
int i;
for (i=0; i < rqstp->rq_enc_pages_num; i++)
__free_page(rqstp->rq_enc_pages[i]);
kfree(rqstp->rq_enc_pages);
}
static int
alloc_enc_pages(struct rpc_rqst *rqstp)
{
struct xdr_buf *snd_buf = &rqstp->rq_snd_buf;
int first, last, i;
if (snd_buf->page_len == 0) {
rqstp->rq_enc_pages_num = 0;
return 0;
}
first = snd_buf->page_base >> PAGE_CACHE_SHIFT;
last = (snd_buf->page_base + snd_buf->page_len - 1) >> PAGE_CACHE_SHIFT;
rqstp->rq_enc_pages_num = last - first + 1 + 1;
rqstp->rq_enc_pages
= kmalloc(rqstp->rq_enc_pages_num * sizeof(struct page *),
GFP_NOFS);
if (!rqstp->rq_enc_pages)
goto out;
for (i=0; i < rqstp->rq_enc_pages_num; i++) {
rqstp->rq_enc_pages[i] = alloc_page(GFP_NOFS);
if (rqstp->rq_enc_pages[i] == NULL)
goto out_free;
}
rqstp->rq_release_snd_buf = priv_release_snd_buf;
return 0;
out_free:
rqstp->rq_enc_pages_num = i;
priv_release_snd_buf(rqstp);
out:
return -EAGAIN;
}
static inline int
gss_wrap_req_priv(struct rpc_cred *cred, struct gss_cl_ctx *ctx,
kxdreproc_t encode, struct rpc_rqst *rqstp,
__be32 *p, void *obj)
{
struct xdr_buf *snd_buf = &rqstp->rq_snd_buf;
u32 offset;
u32 maj_stat;
int status;
__be32 *opaque_len;
struct page **inpages;
int first;
int pad;
struct kvec *iov;
char *tmp;
opaque_len = p++;
offset = (u8 *)p - (u8 *)snd_buf->head[0].iov_base;
*p++ = htonl(rqstp->rq_seqno);
gss_wrap_req_encode(encode, rqstp, p, obj);
status = alloc_enc_pages(rqstp);
if (status)
return status;
first = snd_buf->page_base >> PAGE_CACHE_SHIFT;
inpages = snd_buf->pages + first;
snd_buf->pages = rqstp->rq_enc_pages;
snd_buf->page_base -= first << PAGE_CACHE_SHIFT;
if (snd_buf->page_len || snd_buf->tail[0].iov_len) {
tmp = page_address(rqstp->rq_enc_pages[rqstp->rq_enc_pages_num - 1]);
memcpy(tmp, snd_buf->tail[0].iov_base, snd_buf->tail[0].iov_len);
snd_buf->tail[0].iov_base = tmp;
}
maj_stat = gss_wrap(ctx->gc_gss_ctx, offset, snd_buf, inpages);
BUG_ON(snd_buf->len > snd_buf->buflen);
status = -EIO;
if (maj_stat == GSS_S_CONTEXT_EXPIRED)
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
else if (maj_stat)
return status;
*opaque_len = htonl(snd_buf->len - offset);
if (snd_buf->page_len || snd_buf->tail[0].iov_len)
iov = snd_buf->tail;
else
iov = snd_buf->head;
p = iov->iov_base + iov->iov_len;
pad = 3 - ((snd_buf->len - offset - 1) & 3);
memset(p, 0, pad);
iov->iov_len += pad;
snd_buf->len += pad;
return 0;
}
static int
gss_wrap_req(struct rpc_task *task,
kxdreproc_t encode, void *rqstp, __be32 *p, void *obj)
{
struct rpc_cred *cred = task->tk_rqstp->rq_cred;
struct gss_cred *gss_cred = container_of(cred, struct gss_cred,
gc_base);
struct gss_cl_ctx *ctx = gss_cred_get_ctx(cred);
int status = -EIO;
dprintk("RPC: %5u %s\n", task->tk_pid, __func__);
if (ctx->gc_proc != RPC_GSS_PROC_DATA) {
gss_wrap_req_encode(encode, rqstp, p, obj);
status = 0;
goto out;
}
switch (gss_cred->gc_service) {
case RPC_GSS_SVC_NONE:
gss_wrap_req_encode(encode, rqstp, p, obj);
status = 0;
break;
case RPC_GSS_SVC_INTEGRITY:
status = gss_wrap_req_integ(cred, ctx, encode, rqstp, p, obj);
break;
case RPC_GSS_SVC_PRIVACY:
status = gss_wrap_req_priv(cred, ctx, encode, rqstp, p, obj);
break;
}
out:
gss_put_ctx(ctx);
dprintk("RPC: %5u %s returning %d\n", task->tk_pid, __func__, status);
return status;
}
static inline int
gss_unwrap_resp_integ(struct rpc_cred *cred, struct gss_cl_ctx *ctx,
struct rpc_rqst *rqstp, __be32 **p)
{
struct xdr_buf *rcv_buf = &rqstp->rq_rcv_buf;
struct xdr_buf integ_buf;
struct xdr_netobj mic;
u32 data_offset, mic_offset;
u32 integ_len;
u32 maj_stat;
int status = -EIO;
integ_len = ntohl(*(*p)++);
if (integ_len & 3)
return status;
data_offset = (u8 *)(*p) - (u8 *)rcv_buf->head[0].iov_base;
mic_offset = integ_len + data_offset;
if (mic_offset > rcv_buf->len)
return status;
if (ntohl(*(*p)++) != rqstp->rq_seqno)
return status;
if (xdr_buf_subsegment(rcv_buf, &integ_buf, data_offset,
mic_offset - data_offset))
return status;
if (xdr_buf_read_netobj(rcv_buf, &mic, mic_offset))
return status;
maj_stat = gss_verify_mic(ctx->gc_gss_ctx, &integ_buf, &mic);
if (maj_stat == GSS_S_CONTEXT_EXPIRED)
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
if (maj_stat != GSS_S_COMPLETE)
return status;
return 0;
}
static inline int
gss_unwrap_resp_priv(struct rpc_cred *cred, struct gss_cl_ctx *ctx,
struct rpc_rqst *rqstp, __be32 **p)
{
struct xdr_buf *rcv_buf = &rqstp->rq_rcv_buf;
u32 offset;
u32 opaque_len;
u32 maj_stat;
int status = -EIO;
opaque_len = ntohl(*(*p)++);
offset = (u8 *)(*p) - (u8 *)rcv_buf->head[0].iov_base;
if (offset + opaque_len > rcv_buf->len)
return status;
rcv_buf->len = offset + opaque_len;
maj_stat = gss_unwrap(ctx->gc_gss_ctx, offset, rcv_buf);
if (maj_stat == GSS_S_CONTEXT_EXPIRED)
clear_bit(RPCAUTH_CRED_UPTODATE, &cred->cr_flags);
if (maj_stat != GSS_S_COMPLETE)
return status;
if (ntohl(*(*p)++) != rqstp->rq_seqno)
return status;
return 0;
}
static int
gss_unwrap_req_decode(kxdrdproc_t decode, struct rpc_rqst *rqstp,
__be32 *p, void *obj)
{
struct xdr_stream xdr;
xdr_init_decode(&xdr, &rqstp->rq_rcv_buf, p);
return decode(rqstp, &xdr, obj);
}
static int
gss_unwrap_resp(struct rpc_task *task,
kxdrdproc_t decode, void *rqstp, __be32 *p, void *obj)
{
struct rpc_cred *cred = task->tk_rqstp->rq_cred;
struct gss_cred *gss_cred = container_of(cred, struct gss_cred,
gc_base);
struct gss_cl_ctx *ctx = gss_cred_get_ctx(cred);
__be32 *savedp = p;
struct kvec *head = ((struct rpc_rqst *)rqstp)->rq_rcv_buf.head;
int savedlen = head->iov_len;
int status = -EIO;
if (ctx->gc_proc != RPC_GSS_PROC_DATA)
goto out_decode;
switch (gss_cred->gc_service) {
case RPC_GSS_SVC_NONE:
break;
case RPC_GSS_SVC_INTEGRITY:
status = gss_unwrap_resp_integ(cred, ctx, rqstp, &p);
if (status)
goto out;
break;
case RPC_GSS_SVC_PRIVACY:
status = gss_unwrap_resp_priv(cred, ctx, rqstp, &p);
if (status)
goto out;
break;
}
cred->cr_auth->au_rslack = cred->cr_auth->au_verfsize + (p - savedp)
+ (savedlen - head->iov_len);
out_decode:
status = gss_unwrap_req_decode(decode, rqstp, p, obj);
out:
gss_put_ctx(ctx);
dprintk("RPC: %5u %s returning %d\n",
task->tk_pid, __func__, status);
return status;
}
static __net_init int rpcsec_gss_init_net(struct net *net)
{
return gss_svc_init_net(net);
}
static __net_exit void rpcsec_gss_exit_net(struct net *net)
{
gss_svc_shutdown_net(net);
}
static int __init init_rpcsec_gss(void)
{
int err = 0;
err = rpcauth_register(&authgss_ops);
if (err)
goto out;
err = gss_svc_init();
if (err)
goto out_unregister;
err = register_pernet_subsys(&rpcsec_gss_net_ops);
if (err)
goto out_svc_exit;
rpc_init_wait_queue(&pipe_version_rpc_waitqueue, "gss pipe version");
return 0;
out_svc_exit:
gss_svc_shutdown();
out_unregister:
rpcauth_unregister(&authgss_ops);
out:
return err;
}
static void __exit exit_rpcsec_gss(void)
{
unregister_pernet_subsys(&rpcsec_gss_net_ops);
gss_svc_shutdown();
rpcauth_unregister(&authgss_ops);
rcu_barrier();
}
