int xprt_register_transport(struct xprt_class *transport)
{
struct xprt_class *t;
int result;
result = -EEXIST;
spin_lock(&xprt_list_lock);
list_for_each_entry(t, &xprt_list, list) {
if (t->ident == transport->ident)
goto out;
}
list_add_tail(&transport->list, &xprt_list);
printk(KERN_INFO "RPC: Registered %s transport module.\n",
transport->name);
result = 0;
out:
spin_unlock(&xprt_list_lock);
return result;
}
int xprt_unregister_transport(struct xprt_class *transport)
{
struct xprt_class *t;
int result;
result = 0;
spin_lock(&xprt_list_lock);
list_for_each_entry(t, &xprt_list, list) {
if (t == transport) {
printk(KERN_INFO
"RPC: Unregistered %s transport module.\n",
transport->name);
list_del_init(&transport->list);
goto out;
}
}
result = -ENOENT;
out:
spin_unlock(&xprt_list_lock);
return result;
}
int xprt_load_transport(const char *transport_name)
{
struct xprt_class *t;
int result;
result = 0;
spin_lock(&xprt_list_lock);
list_for_each_entry(t, &xprt_list, list) {
if (strcmp(t->name, transport_name) == 0) {
spin_unlock(&xprt_list_lock);
goto out;
}
}
spin_unlock(&xprt_list_lock);
result = request_module("xprt%s", transport_name);
out:
return result;
}
int xprt_reserve_xprt(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
if (test_and_set_bit(XPRT_LOCKED, &xprt->state)) {
if (task == xprt->snd_task)
return 1;
goto out_sleep;
}
xprt->snd_task = task;
req->rq_bytes_sent = 0;
req->rq_ntrans++;
return 1;
out_sleep:
dprintk("RPC: %5u failed to lock transport %p\n",
task->tk_pid, xprt);
task->tk_timeout = 0;
task->tk_status = -EAGAIN;
if (req->rq_ntrans)
rpc_sleep_on(&xprt->resend, task, NULL);
else
rpc_sleep_on(&xprt->sending, task, NULL);
return 0;
}
static void xprt_clear_locked(struct rpc_xprt *xprt)
{
xprt->snd_task = NULL;
if (!test_bit(XPRT_CLOSE_WAIT, &xprt->state) || xprt->shutdown) {
smp_mb__before_clear_bit();
clear_bit(XPRT_LOCKED, &xprt->state);
smp_mb__after_clear_bit();
} else
queue_work(rpciod_workqueue, &xprt->task_cleanup);
}
int xprt_reserve_xprt_cong(struct rpc_task *task)
{
struct rpc_xprt *xprt = task->tk_xprt;
struct rpc_rqst *req = task->tk_rqstp;
if (test_and_set_bit(XPRT_LOCKED, &xprt->state)) {
if (task == xprt->snd_task)
return 1;
goto out_sleep;
}
if (__xprt_get_cong(xprt, task)) {
xprt->snd_task = task;
if (req) {
req->rq_bytes_sent = 0;
req->rq_ntrans++;
}
return 1;
}
xprt_clear_locked(xprt);
out_sleep:
dprintk("RPC: %5u failed to lock transport %p\n", task->tk_pid, xprt);
task->tk_timeout = 0;
task->tk_status = -EAGAIN;
if (req && req->rq_ntrans)
rpc_sleep_on(&xprt->resend, task, NULL);
else
rpc_sleep_on(&xprt->sending, task, NULL);
return 0;
}
static inline int xprt_lock_write(struct rpc_xprt *xprt, struct rpc_task *task)
{
int retval;
spin_lock_bh(&xprt->transport_lock);
retval = xprt->ops->reserve_xprt(task);
spin_unlock_bh(&xprt->transport_lock);
return retval;
}
static void __xprt_lock_write_next(struct rpc_xprt *xprt)
{
struct rpc_task *task;
struct rpc_rqst *req;
if (test_and_set_bit(XPRT_LOCKED, &xprt->state))
return;
task = rpc_wake_up_next(&xprt->resend);
if (!task) {
task = rpc_wake_up_next(&xprt->sending);
if (!task)
goto out_unlock;
}
req = task->tk_rqstp;
xprt->snd_task = task;
if (req) {
req->rq_bytes_sent = 0;
req->rq_ntrans++;
}
return;
out_unlock:
xprt_clear_locked(xprt);
}
static void __xprt_lock_write_next_cong(struct rpc_xprt *xprt)
{
struct rpc_task *task;
if (test_and_set_bit(XPRT_LOCKED, &xprt->state))
return;
if (RPCXPRT_CONGESTED(xprt))
goto out_unlock;
task = rpc_wake_up_next(&xprt->resend);
if (!task) {
task = rpc_wake_up_next(&xprt->sending);
if (!task)
goto out_unlock;
}
if (__xprt_get_cong(xprt, task)) {
struct rpc_rqst *req = task->tk_rqstp;
xprt->snd_task = task;
if (req) {
req->rq_bytes_sent = 0;
req->rq_ntrans++;
}
return;
}
out_unlock:
xprt_clear_locked(xprt);
}
void xprt_release_xprt(struct rpc_xprt *xprt, struct rpc_task *task)
{
if (xprt->snd_task == task) {
xprt_clear_locked(xprt);
__xprt_lock_write_next(xprt);
}
}
void xprt_release_xprt_cong(struct rpc_xprt *xprt, struct rpc_task *task)
{
if (xprt->snd_task == task) {
xprt_clear_locked(xprt);
__xprt_lock_write_next_cong(xprt);
}
}
static inline void xprt_release_write(struct rpc_xprt *xprt, struct rpc_task *task)
{
spin_lock_bh(&xprt->transport_lock);
xprt->ops->release_xprt(xprt, task);
spin_unlock_bh(&xprt->transport_lock);
}
static int
__xprt_get_cong(struct rpc_xprt *xprt, struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
if (req->rq_cong)
return 1;
dprintk("RPC: %5u xprt_cwnd_limited cong = %lu cwnd = %lu\n",
task->tk_pid, xprt->cong, xprt->cwnd);
if (RPCXPRT_CONGESTED(xprt))
return 0;
req->rq_cong = 1;
xprt->cong += RPC_CWNDSCALE;
return 1;
}
static void
__xprt_put_cong(struct rpc_xprt *xprt, struct rpc_rqst *req)
{
if (!req->rq_cong)
return;
req->rq_cong = 0;
xprt->cong -= RPC_CWNDSCALE;
__xprt_lock_write_next_cong(xprt);
}
void xprt_release_rqst_cong(struct rpc_task *task)
{
__xprt_put_cong(task->tk_xprt, task->tk_rqstp);
}
void xprt_adjust_cwnd(struct rpc_task *task, int result)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = task->tk_xprt;
unsigned long cwnd = xprt->cwnd;
if (result >= 0 && cwnd <= xprt->cong) {
cwnd += (RPC_CWNDSCALE * RPC_CWNDSCALE + (cwnd >> 1)) / cwnd;
if (cwnd > RPC_MAXCWND(xprt))
cwnd = RPC_MAXCWND(xprt);
__xprt_lock_write_next_cong(xprt);
} else if (result == -ETIMEDOUT) {
cwnd >>= 1;
if (cwnd < RPC_CWNDSCALE)
cwnd = RPC_CWNDSCALE;
}
dprintk("RPC: cong %ld, cwnd was %ld, now %ld\n",
xprt->cong, xprt->cwnd, cwnd);
xprt->cwnd = cwnd;
__xprt_put_cong(xprt, req);
}
void xprt_wake_pending_tasks(struct rpc_xprt *xprt, int status)
{
if (status < 0)
rpc_wake_up_status(&xprt->pending, status);
else
rpc_wake_up(&xprt->pending);
}
void xprt_wait_for_buffer_space(struct rpc_task *task, rpc_action action)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
task->tk_timeout = req->rq_timeout;
rpc_sleep_on(&xprt->pending, task, action);
}
void xprt_write_space(struct rpc_xprt *xprt)
{
if (unlikely(xprt->shutdown))
return;
spin_lock_bh(&xprt->transport_lock);
if (xprt->snd_task) {
dprintk("RPC: write space: waking waiting task on "
"xprt %p\n", xprt);
rpc_wake_up_queued_task(&xprt->pending, xprt->snd_task);
}
spin_unlock_bh(&xprt->transport_lock);
}
void xprt_set_retrans_timeout_def(struct rpc_task *task)
{
task->tk_timeout = task->tk_rqstp->rq_timeout;
}
void xprt_set_retrans_timeout_rtt(struct rpc_task *task)
{
int timer = task->tk_msg.rpc_proc->p_timer;
struct rpc_clnt *clnt = task->tk_client;
struct rpc_rtt *rtt = clnt->cl_rtt;
struct rpc_rqst *req = task->tk_rqstp;
unsigned long max_timeout = clnt->cl_timeout->to_maxval;
task->tk_timeout = rpc_calc_rto(rtt, timer);
task->tk_timeout <<= rpc_ntimeo(rtt, timer) + req->rq_retries;
if (task->tk_timeout > max_timeout || task->tk_timeout == 0)
task->tk_timeout = max_timeout;
}
static void xprt_reset_majortimeo(struct rpc_rqst *req)
{
const struct rpc_timeout *to = req->rq_task->tk_client->cl_timeout;
req->rq_majortimeo = req->rq_timeout;
if (to->to_exponential)
req->rq_majortimeo <<= to->to_retries;
else
req->rq_majortimeo += to->to_increment * to->to_retries;
if (req->rq_majortimeo > to->to_maxval || req->rq_majortimeo == 0)
req->rq_majortimeo = to->to_maxval;
req->rq_majortimeo += jiffies;
}
int xprt_adjust_timeout(struct rpc_rqst *req)
{
struct rpc_xprt *xprt = req->rq_xprt;
const struct rpc_timeout *to = req->rq_task->tk_client->cl_timeout;
int status = 0;
if (time_before(jiffies, req->rq_majortimeo)) {
if (to->to_exponential)
req->rq_timeout <<= 1;
else
req->rq_timeout += to->to_increment;
if (to->to_maxval && req->rq_timeout >= to->to_maxval)
req->rq_timeout = to->to_maxval;
req->rq_retries++;
} else {
req->rq_timeout = to->to_initval;
req->rq_retries = 0;
xprt_reset_majortimeo(req);
spin_lock_bh(&xprt->transport_lock);
rpc_init_rtt(req->rq_task->tk_client->cl_rtt, to->to_initval);
spin_unlock_bh(&xprt->transport_lock);
status = -ETIMEDOUT;
}
if (req->rq_timeout == 0) {
printk(KERN_WARNING "xprt_adjust_timeout: rq_timeout = 0!\n");
req->rq_timeout = 5 * HZ;
}
return status;
}
static void xprt_autoclose(struct work_struct *work)
{
struct rpc_xprt *xprt =
container_of(work, struct rpc_xprt, task_cleanup);
xprt->ops->close(xprt);
clear_bit(XPRT_CLOSE_WAIT, &xprt->state);
xprt_release_write(xprt, NULL);
}
void xprt_disconnect_done(struct rpc_xprt *xprt)
{
dprintk("RPC: disconnected transport %p\n", xprt);
spin_lock_bh(&xprt->transport_lock);
xprt_clear_connected(xprt);
xprt_wake_pending_tasks(xprt, -EAGAIN);
spin_unlock_bh(&xprt->transport_lock);
}
void xprt_force_disconnect(struct rpc_xprt *xprt)
{
spin_lock_bh(&xprt->transport_lock);
set_bit(XPRT_CLOSE_WAIT, &xprt->state);
if (test_and_set_bit(XPRT_LOCKED, &xprt->state) == 0)
queue_work(rpciod_workqueue, &xprt->task_cleanup);
xprt_wake_pending_tasks(xprt, -EAGAIN);
spin_unlock_bh(&xprt->transport_lock);
}
void xprt_conditional_disconnect(struct rpc_xprt *xprt, unsigned int cookie)
{
spin_lock_bh(&xprt->transport_lock);
if (cookie != xprt->connect_cookie)
goto out;
if (test_bit(XPRT_CLOSING, &xprt->state) || !xprt_connected(xprt))
goto out;
set_bit(XPRT_CLOSE_WAIT, &xprt->state);
if (test_and_set_bit(XPRT_LOCKED, &xprt->state) == 0)
queue_work(rpciod_workqueue, &xprt->task_cleanup);
xprt_wake_pending_tasks(xprt, -EAGAIN);
out:
spin_unlock_bh(&xprt->transport_lock);
}
static void
xprt_init_autodisconnect(unsigned long data)
{
struct rpc_xprt *xprt = (struct rpc_xprt *)data;
spin_lock(&xprt->transport_lock);
if (!list_empty(&xprt->recv) || xprt->shutdown)
goto out_abort;
if (test_and_set_bit(XPRT_LOCKED, &xprt->state))
goto out_abort;
spin_unlock(&xprt->transport_lock);
set_bit(XPRT_CONNECTION_CLOSE, &xprt->state);
queue_work(rpciod_workqueue, &xprt->task_cleanup);
return;
out_abort:
spin_unlock(&xprt->transport_lock);
}
void xprt_connect(struct rpc_task *task)
{
struct rpc_xprt *xprt = task->tk_xprt;
dprintk("RPC: %5u xprt_connect xprt %p %s connected\n", task->tk_pid,
xprt, (xprt_connected(xprt) ? "is" : "is not"));
if (!xprt_bound(xprt)) {
task->tk_status = -EAGAIN;
return;
}
if (!xprt_lock_write(xprt, task))
return;
if (test_and_clear_bit(XPRT_CLOSE_WAIT, &xprt->state))
xprt->ops->close(xprt);
if (xprt_connected(xprt))
xprt_release_write(xprt, task);
else {
if (task->tk_rqstp)
task->tk_rqstp->rq_bytes_sent = 0;
task->tk_timeout = task->tk_rqstp->rq_timeout;
rpc_sleep_on(&xprt->pending, task, xprt_connect_status);
if (test_bit(XPRT_CLOSING, &xprt->state))
return;
if (xprt_test_and_set_connecting(xprt))
return;
xprt->stat.connect_start = jiffies;
xprt->ops->connect(task);
}
}
static void xprt_connect_status(struct rpc_task *task)
{
struct rpc_xprt *xprt = task->tk_xprt;
if (task->tk_status == 0) {
xprt->stat.connect_count++;
xprt->stat.connect_time += (long)jiffies - xprt->stat.connect_start;
dprintk("RPC: %5u xprt_connect_status: connection established\n",
task->tk_pid);
return;
}
switch (task->tk_status) {
case -EAGAIN:
dprintk("RPC: %5u xprt_connect_status: retrying\n", task->tk_pid);
break;
case -ETIMEDOUT:
dprintk("RPC: %5u xprt_connect_status: connect attempt timed "
"out\n", task->tk_pid);
break;
default:
dprintk("RPC: %5u xprt_connect_status: error %d connecting to "
"server %s\n", task->tk_pid, -task->tk_status,
task->tk_client->cl_server);
xprt_release_write(xprt, task);
task->tk_status = -EIO;
}
}
struct rpc_rqst *xprt_lookup_rqst(struct rpc_xprt *xprt, __be32 xid)
{
struct rpc_rqst *entry;
list_for_each_entry(entry, &xprt->recv, rq_list)
if (entry->rq_xid == xid)
return entry;
dprintk("RPC: xprt_lookup_rqst did not find xid %08x\n",
ntohl(xid));
xprt->stat.bad_xids++;
return NULL;
}
static void xprt_update_rtt(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_rtt *rtt = task->tk_client->cl_rtt;
unsigned timer = task->tk_msg.rpc_proc->p_timer;
long m = usecs_to_jiffies(ktime_to_us(req->rq_rtt));
if (timer) {
if (req->rq_ntrans == 1)
rpc_update_rtt(rtt, timer, m);
rpc_set_timeo(rtt, timer, req->rq_ntrans - 1);
}
}
void xprt_complete_rqst(struct rpc_task *task, int copied)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
dprintk("RPC: %5u xid %08x complete (%d bytes received)\n",
task->tk_pid, ntohl(req->rq_xid), copied);
xprt->stat.recvs++;
req->rq_rtt = ktime_sub(ktime_get(), req->rq_xtime);
if (xprt->ops->timer != NULL)
xprt_update_rtt(task);
list_del_init(&req->rq_list);
req->rq_private_buf.len = copied;
smp_wmb();
req->rq_reply_bytes_recvd = copied;
rpc_wake_up_queued_task(&xprt->pending, task);
}
static void xprt_timer(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
if (task->tk_status != -ETIMEDOUT)
return;
dprintk("RPC: %5u xprt_timer\n", task->tk_pid);
spin_lock_bh(&xprt->transport_lock);
if (!req->rq_reply_bytes_recvd) {
if (xprt->ops->timer)
xprt->ops->timer(task);
} else
task->tk_status = 0;
spin_unlock_bh(&xprt->transport_lock);
}
static inline int xprt_has_timer(struct rpc_xprt *xprt)
{
return xprt->idle_timeout != 0;
}
int xprt_prepare_transmit(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
int err = 0;
dprintk("RPC: %5u xprt_prepare_transmit\n", task->tk_pid);
spin_lock_bh(&xprt->transport_lock);
if (req->rq_reply_bytes_recvd && !req->rq_bytes_sent) {
err = req->rq_reply_bytes_recvd;
goto out_unlock;
}
if (!xprt->ops->reserve_xprt(task))
err = -EAGAIN;
out_unlock:
spin_unlock_bh(&xprt->transport_lock);
return err;
}
void xprt_end_transmit(struct rpc_task *task)
{
xprt_release_write(task->tk_rqstp->rq_xprt, task);
}
void xprt_transmit(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
int status;
dprintk("RPC: %5u xprt_transmit(%u)\n", task->tk_pid, req->rq_slen);
if (!req->rq_reply_bytes_recvd) {
if (list_empty(&req->rq_list) && rpc_reply_expected(task)) {
spin_lock_bh(&xprt->transport_lock);
memcpy(&req->rq_private_buf, &req->rq_rcv_buf,
sizeof(req->rq_private_buf));
list_add_tail(&req->rq_list, &xprt->recv);
spin_unlock_bh(&xprt->transport_lock);
xprt_reset_majortimeo(req);
del_singleshot_timer_sync(&xprt->timer);
}
} else if (!req->rq_bytes_sent)
return;
req->rq_connect_cookie = xprt->connect_cookie;
req->rq_xtime = ktime_get();
status = xprt->ops->send_request(task);
if (status != 0) {
task->tk_status = status;
return;
}
dprintk("RPC: %5u xmit complete\n", task->tk_pid);
task->tk_flags |= RPC_TASK_SENT;
spin_lock_bh(&xprt->transport_lock);
xprt->ops->set_retrans_timeout(task);
xprt->stat.sends++;
xprt->stat.req_u += xprt->stat.sends - xprt->stat.recvs;
xprt->stat.bklog_u += xprt->backlog.qlen;
if (!xprt_connected(xprt))
task->tk_status = -ENOTCONN;
else if (!req->rq_reply_bytes_recvd && rpc_reply_expected(task)) {
rpc_sleep_on(&xprt->pending, task, xprt_timer);
}
spin_unlock_bh(&xprt->transport_lock);
}
static void xprt_alloc_slot(struct rpc_task *task)
{
struct rpc_xprt *xprt = task->tk_xprt;
task->tk_status = 0;
if (task->tk_rqstp)
return;
if (!list_empty(&xprt->free)) {
struct rpc_rqst *req = list_entry(xprt->free.next, struct rpc_rqst, rq_list);
list_del_init(&req->rq_list);
task->tk_rqstp = req;
xprt_request_init(task, xprt);
return;
}
dprintk("RPC: waiting for request slot\n");
task->tk_status = -EAGAIN;
task->tk_timeout = 0;
rpc_sleep_on(&xprt->backlog, task, NULL);
}
static void xprt_free_slot(struct rpc_xprt *xprt, struct rpc_rqst *req)
{
memset(req, 0, sizeof(*req));
spin_lock(&xprt->reserve_lock);
list_add(&req->rq_list, &xprt->free);
rpc_wake_up_next(&xprt->backlog);
spin_unlock(&xprt->reserve_lock);
}
struct rpc_xprt *xprt_alloc(struct net *net, int size, int max_req)
{
struct rpc_xprt *xprt;
xprt = kzalloc(size, GFP_KERNEL);
if (xprt == NULL)
goto out;
atomic_set(&xprt->count, 1);
xprt->max_reqs = max_req;
xprt->slot = kcalloc(max_req, sizeof(struct rpc_rqst), GFP_KERNEL);
if (xprt->slot == NULL)
goto out_free;
xprt->xprt_net = get_net(net);
return xprt;
out_free:
kfree(xprt);
out:
return NULL;
}
void xprt_free(struct rpc_xprt *xprt)
{
put_net(xprt->xprt_net);
kfree(xprt->slot);
kfree(xprt);
}
void xprt_reserve(struct rpc_task *task)
{
struct rpc_xprt *xprt = task->tk_xprt;
task->tk_status = -EIO;
spin_lock(&xprt->reserve_lock);
xprt_alloc_slot(task);
spin_unlock(&xprt->reserve_lock);
}
static inline __be32 xprt_alloc_xid(struct rpc_xprt *xprt)
{
return (__force __be32)xprt->xid++;
}
static inline void xprt_init_xid(struct rpc_xprt *xprt)
{
xprt->xid = net_random();
}
static void xprt_request_init(struct rpc_task *task, struct rpc_xprt *xprt)
{
struct rpc_rqst *req = task->tk_rqstp;
req->rq_timeout = task->tk_client->cl_timeout->to_initval;
req->rq_task = task;
req->rq_xprt = xprt;
req->rq_buffer = NULL;
req->rq_xid = xprt_alloc_xid(xprt);
req->rq_release_snd_buf = NULL;
xprt_reset_majortimeo(req);
dprintk("RPC: %5u reserved req %p xid %08x\n", task->tk_pid,
req, ntohl(req->rq_xid));
}
void xprt_release(struct rpc_task *task)
{
struct rpc_xprt *xprt;
struct rpc_rqst *req;
if (!(req = task->tk_rqstp))
return;
xprt = req->rq_xprt;
rpc_count_iostats(task);
spin_lock_bh(&xprt->transport_lock);
xprt->ops->release_xprt(xprt, task);
if (xprt->ops->release_request)
xprt->ops->release_request(task);
if (!list_empty(&req->rq_list))
list_del(&req->rq_list);
xprt->last_used = jiffies;
if (list_empty(&xprt->recv) && xprt_has_timer(xprt))
mod_timer(&xprt->timer,
xprt->last_used + xprt->idle_timeout);
spin_unlock_bh(&xprt->transport_lock);
if (req->rq_buffer)
xprt->ops->buf_free(req->rq_buffer);
if (req->rq_cred != NULL)
put_rpccred(req->rq_cred);
task->tk_rqstp = NULL;
if (req->rq_release_snd_buf)
req->rq_release_snd_buf(req);
dprintk("RPC: %5u release request %p\n", task->tk_pid, req);
if (likely(!bc_prealloc(req)))
xprt_free_slot(xprt, req);
else
xprt_free_bc_request(req);
}
struct rpc_xprt *xprt_create_transport(struct xprt_create *args)
{
struct rpc_xprt *xprt;
struct rpc_rqst *req;
struct xprt_class *t;
spin_lock(&xprt_list_lock);
list_for_each_entry(t, &xprt_list, list) {
if (t->ident == args->ident) {
spin_unlock(&xprt_list_lock);
goto found;
}
}
spin_unlock(&xprt_list_lock);
printk(KERN_ERR "RPC: transport (%d) not supported\n", args->ident);
return ERR_PTR(-EIO);
found:
xprt = t->setup(args);
if (IS_ERR(xprt)) {
dprintk("RPC: xprt_create_transport: failed, %ld\n",
-PTR_ERR(xprt));
return xprt;
}
if (test_and_set_bit(XPRT_INITIALIZED, &xprt->state))
return xprt;
spin_lock_init(&xprt->transport_lock);
spin_lock_init(&xprt->reserve_lock);
INIT_LIST_HEAD(&xprt->free);
INIT_LIST_HEAD(&xprt->recv);
#if defined(CONFIG_NFS_V4_1)
spin_lock_init(&xprt->bc_pa_lock);
INIT_LIST_HEAD(&xprt->bc_pa_list);
#endif
INIT_WORK(&xprt->task_cleanup, xprt_autoclose);
if (xprt_has_timer(xprt))
setup_timer(&xprt->timer, xprt_init_autodisconnect,
(unsigned long)xprt);
else
init_timer(&xprt->timer);
xprt->last_used = jiffies;
xprt->cwnd = RPC_INITCWND;
xprt->bind_index = 0;
rpc_init_wait_queue(&xprt->binding, "xprt_binding");
rpc_init_wait_queue(&xprt->pending, "xprt_pending");
rpc_init_wait_queue(&xprt->sending, "xprt_sending");
rpc_init_wait_queue(&xprt->resend, "xprt_resend");
rpc_init_priority_wait_queue(&xprt->backlog, "xprt_backlog");
for (req = &xprt->slot[xprt->max_reqs-1]; req >= &xprt->slot[0]; req--)
list_add(&req->rq_list, &xprt->free);
xprt_init_xid(xprt);
dprintk("RPC: created transport %p with %u slots\n", xprt,
xprt->max_reqs);
return xprt;
}
static void xprt_destroy(struct rpc_xprt *xprt)
{
dprintk("RPC: destroying transport %p\n", xprt);
xprt->shutdown = 1;
del_timer_sync(&xprt->timer);
rpc_destroy_wait_queue(&xprt->binding);
rpc_destroy_wait_queue(&xprt->pending);
rpc_destroy_wait_queue(&xprt->sending);
rpc_destroy_wait_queue(&xprt->resend);
rpc_destroy_wait_queue(&xprt->backlog);
cancel_work_sync(&xprt->task_cleanup);
xprt->ops->destroy(xprt);
}
void xprt_put(struct rpc_xprt *xprt)
{
if (atomic_dec_and_test(&xprt->count))
xprt_destroy(xprt);
}
struct rpc_xprt *xprt_get(struct rpc_xprt *xprt)
{
if (atomic_inc_not_zero(&xprt->count))
return xprt;
return NULL;
}
