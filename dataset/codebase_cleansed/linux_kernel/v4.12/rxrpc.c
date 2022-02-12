static int afs_wait_atomic_t(atomic_t *p)
{
schedule();
return 0;
}
int afs_open_socket(void)
{
struct sockaddr_rxrpc srx;
struct socket *socket;
int ret;
_enter("");
ret = -ENOMEM;
afs_async_calls = alloc_workqueue("kafsd", WQ_MEM_RECLAIM, 0);
if (!afs_async_calls)
goto error_0;
ret = sock_create_kern(&init_net, AF_RXRPC, SOCK_DGRAM, PF_INET, &socket);
if (ret < 0)
goto error_1;
socket->sk->sk_allocation = GFP_NOFS;
srx.srx_family = AF_RXRPC;
srx.srx_service = CM_SERVICE;
srx.transport_type = SOCK_DGRAM;
srx.transport_len = sizeof(srx.transport.sin);
srx.transport.sin.sin_family = AF_INET;
srx.transport.sin.sin_port = htons(AFS_CM_PORT);
memset(&srx.transport.sin.sin_addr, 0,
sizeof(srx.transport.sin.sin_addr));
ret = kernel_bind(socket, (struct sockaddr *) &srx, sizeof(srx));
if (ret < 0)
goto error_2;
rxrpc_kernel_new_call_notification(socket, afs_rx_new_call,
afs_rx_discard_new_call);
ret = kernel_listen(socket, INT_MAX);
if (ret < 0)
goto error_2;
afs_socket = socket;
afs_charge_preallocation(NULL);
_leave(" = 0");
return 0;
error_2:
sock_release(socket);
error_1:
destroy_workqueue(afs_async_calls);
error_0:
_leave(" = %d", ret);
return ret;
}
void afs_close_socket(void)
{
_enter("");
kernel_listen(afs_socket, 0);
flush_workqueue(afs_async_calls);
if (afs_spare_incoming_call) {
afs_put_call(afs_spare_incoming_call);
afs_spare_incoming_call = NULL;
}
_debug("outstanding %u", atomic_read(&afs_outstanding_calls));
wait_on_atomic_t(&afs_outstanding_calls, afs_wait_atomic_t,
TASK_UNINTERRUPTIBLE);
_debug("no outstanding calls");
kernel_sock_shutdown(afs_socket, SHUT_RDWR);
flush_workqueue(afs_async_calls);
sock_release(afs_socket);
_debug("dework");
destroy_workqueue(afs_async_calls);
_leave("");
}
static struct afs_call *afs_alloc_call(const struct afs_call_type *type,
gfp_t gfp)
{
struct afs_call *call;
int o;
call = kzalloc(sizeof(*call), gfp);
if (!call)
return NULL;
call->type = type;
atomic_set(&call->usage, 1);
INIT_WORK(&call->async_work, afs_process_async_call);
init_waitqueue_head(&call->waitq);
o = atomic_inc_return(&afs_outstanding_calls);
trace_afs_call(call, afs_call_trace_alloc, 1, o,
__builtin_return_address(0));
return call;
}
void afs_put_call(struct afs_call *call)
{
int n = atomic_dec_return(&call->usage);
int o = atomic_read(&afs_outstanding_calls);
trace_afs_call(call, afs_call_trace_put, n + 1, o,
__builtin_return_address(0));
ASSERTCMP(n, >=, 0);
if (n == 0) {
ASSERT(!work_pending(&call->async_work));
ASSERT(call->type->name != NULL);
if (call->rxcall) {
rxrpc_kernel_end_call(afs_socket, call->rxcall);
call->rxcall = NULL;
}
if (call->type->destructor)
call->type->destructor(call);
kfree(call->request);
kfree(call);
o = atomic_dec_return(&afs_outstanding_calls);
trace_afs_call(call, afs_call_trace_free, 0, o,
__builtin_return_address(0));
if (o == 0)
wake_up_atomic_t(&afs_outstanding_calls);
}
}
int afs_queue_call_work(struct afs_call *call)
{
int u = atomic_inc_return(&call->usage);
trace_afs_call(call, afs_call_trace_work, u,
atomic_read(&afs_outstanding_calls),
__builtin_return_address(0));
INIT_WORK(&call->work, call->type->work);
if (!queue_work(afs_wq, &call->work))
afs_put_call(call);
return 0;
}
struct afs_call *afs_alloc_flat_call(const struct afs_call_type *type,
size_t request_size, size_t reply_max)
{
struct afs_call *call;
call = afs_alloc_call(type, GFP_NOFS);
if (!call)
goto nomem_call;
if (request_size) {
call->request_size = request_size;
call->request = kmalloc(request_size, GFP_NOFS);
if (!call->request)
goto nomem_free;
}
if (reply_max) {
call->reply_max = reply_max;
call->buffer = kmalloc(reply_max, GFP_NOFS);
if (!call->buffer)
goto nomem_free;
}
init_waitqueue_head(&call->waitq);
return call;
nomem_free:
afs_put_call(call);
nomem_call:
return NULL;
}
void afs_flat_call_destructor(struct afs_call *call)
{
_enter("");
kfree(call->request);
call->request = NULL;
kfree(call->buffer);
call->buffer = NULL;
}
static void afs_load_bvec(struct afs_call *call, struct msghdr *msg,
struct bio_vec *bv, pgoff_t first, pgoff_t last,
unsigned offset)
{
struct page *pages[AFS_BVEC_MAX];
unsigned int nr, n, i, to, bytes = 0;
nr = min_t(pgoff_t, last - first + 1, AFS_BVEC_MAX);
n = find_get_pages_contig(call->mapping, first, nr, pages);
ASSERTCMP(n, ==, nr);
msg->msg_flags |= MSG_MORE;
for (i = 0; i < nr; i++) {
to = PAGE_SIZE;
if (first + i >= last) {
to = call->last_to;
msg->msg_flags &= ~MSG_MORE;
}
bv[i].bv_page = pages[i];
bv[i].bv_len = to - offset;
bv[i].bv_offset = offset;
bytes += to - offset;
offset = 0;
}
iov_iter_bvec(&msg->msg_iter, WRITE | ITER_BVEC, bv, nr, bytes);
}
static int afs_send_pages(struct afs_call *call, struct msghdr *msg)
{
struct bio_vec bv[AFS_BVEC_MAX];
unsigned int bytes, nr, loop, offset;
pgoff_t first = call->first, last = call->last;
int ret;
offset = call->first_offset;
call->first_offset = 0;
do {
afs_load_bvec(call, msg, bv, first, last, offset);
offset = 0;
bytes = msg->msg_iter.count;
nr = msg->msg_iter.nr_segs;
if (first + nr - 1 >= last)
call->state = AFS_CALL_AWAIT_REPLY;
ret = rxrpc_kernel_send_data(afs_socket, call->rxcall,
msg, bytes);
for (loop = 0; loop < nr; loop++)
put_page(bv[loop].bv_page);
if (ret < 0)
break;
first += nr;
} while (first <= last);
return ret;
}
int afs_make_call(struct in_addr *addr, struct afs_call *call, gfp_t gfp,
bool async)
{
struct sockaddr_rxrpc srx;
struct rxrpc_call *rxcall;
struct msghdr msg;
struct kvec iov[1];
size_t offset;
u32 abort_code;
int ret;
_enter("%x,{%d},", addr->s_addr, ntohs(call->port));
ASSERT(call->type != NULL);
ASSERT(call->type->name != NULL);
_debug("____MAKE %p{%s,%x} [%d]____",
call, call->type->name, key_serial(call->key),
atomic_read(&afs_outstanding_calls));
call->async = async;
memset(&srx, 0, sizeof(srx));
srx.srx_family = AF_RXRPC;
srx.srx_service = call->service_id;
srx.transport_type = SOCK_DGRAM;
srx.transport_len = sizeof(srx.transport.sin);
srx.transport.sin.sin_family = AF_INET;
srx.transport.sin.sin_port = call->port;
memcpy(&srx.transport.sin.sin_addr, addr, 4);
rxcall = rxrpc_kernel_begin_call(afs_socket, &srx, call->key,
(unsigned long) call, gfp,
(async ?
afs_wake_up_async_call :
afs_wake_up_call_waiter));
call->key = NULL;
if (IS_ERR(rxcall)) {
ret = PTR_ERR(rxcall);
goto error_kill_call;
}
call->rxcall = rxcall;
iov[0].iov_base = call->request;
iov[0].iov_len = call->request_size;
msg.msg_name = NULL;
msg.msg_namelen = 0;
iov_iter_kvec(&msg.msg_iter, WRITE | ITER_KVEC, iov, 1,
call->request_size);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = (call->send_pages ? MSG_MORE : 0);
if (!call->send_pages)
call->state = AFS_CALL_AWAIT_REPLY;
ret = rxrpc_kernel_send_data(afs_socket, rxcall,
&msg, call->request_size);
if (ret < 0)
goto error_do_abort;
if (call->send_pages) {
ret = afs_send_pages(call, &msg);
if (ret < 0)
goto error_do_abort;
}
if (call->async)
return -EINPROGRESS;
return afs_wait_for_call_to_complete(call);
error_do_abort:
call->state = AFS_CALL_COMPLETE;
if (ret != -ECONNABORTED) {
rxrpc_kernel_abort_call(afs_socket, rxcall, RX_USER_ABORT,
ret, "KSD");
} else {
abort_code = 0;
offset = 0;
rxrpc_kernel_recv_data(afs_socket, rxcall, NULL, 0, &offset,
false, &abort_code);
ret = call->type->abort_to_error(abort_code);
}
error_kill_call:
afs_put_call(call);
_leave(" = %d", ret);
return ret;
}
static void afs_deliver_to_call(struct afs_call *call)
{
u32 abort_code;
int ret;
_enter("%s", call->type->name);
while (call->state == AFS_CALL_AWAIT_REPLY ||
call->state == AFS_CALL_AWAIT_OP_ID ||
call->state == AFS_CALL_AWAIT_REQUEST ||
call->state == AFS_CALL_AWAIT_ACK
) {
if (call->state == AFS_CALL_AWAIT_ACK) {
size_t offset = 0;
ret = rxrpc_kernel_recv_data(afs_socket, call->rxcall,
NULL, 0, &offset, false,
&call->abort_code);
trace_afs_recv_data(call, 0, offset, false, ret);
if (ret == -EINPROGRESS || ret == -EAGAIN)
return;
if (ret == 1 || ret < 0) {
call->state = AFS_CALL_COMPLETE;
goto done;
}
return;
}
ret = call->type->deliver(call);
switch (ret) {
case 0:
if (call->state == AFS_CALL_AWAIT_REPLY)
call->state = AFS_CALL_COMPLETE;
goto done;
case -EINPROGRESS:
case -EAGAIN:
goto out;
case -ECONNABORTED:
goto call_complete;
case -ENOTCONN:
abort_code = RX_CALL_DEAD;
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
abort_code, ret, "KNC");
goto save_error;
case -ENOTSUPP:
abort_code = RXGEN_OPCODE;
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
abort_code, ret, "KIV");
goto save_error;
case -ENODATA:
case -EBADMSG:
case -EMSGSIZE:
default:
abort_code = RXGEN_CC_UNMARSHAL;
if (call->state != AFS_CALL_AWAIT_REPLY)
abort_code = RXGEN_SS_UNMARSHAL;
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
abort_code, -EBADMSG, "KUM");
goto save_error;
}
}
done:
if (call->state == AFS_CALL_COMPLETE && call->incoming)
afs_put_call(call);
out:
_leave("");
return;
save_error:
call->error = ret;
call_complete:
call->state = AFS_CALL_COMPLETE;
goto done;
}
static int afs_wait_for_call_to_complete(struct afs_call *call)
{
int ret;
DECLARE_WAITQUEUE(myself, current);
_enter("");
add_wait_queue(&call->waitq, &myself);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (call->state < AFS_CALL_COMPLETE && call->need_attention) {
call->need_attention = false;
__set_current_state(TASK_RUNNING);
afs_deliver_to_call(call);
continue;
}
if (call->state == AFS_CALL_COMPLETE ||
signal_pending(current))
break;
schedule();
}
remove_wait_queue(&call->waitq, &myself);
__set_current_state(TASK_RUNNING);
if (call->state < AFS_CALL_COMPLETE) {
_debug("call interrupted");
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
RX_USER_ABORT, -EINTR, "KWI");
}
ret = call->error;
_debug("call complete");
afs_put_call(call);
_leave(" = %d", ret);
return ret;
}
static void afs_wake_up_call_waiter(struct sock *sk, struct rxrpc_call *rxcall,
unsigned long call_user_ID)
{
struct afs_call *call = (struct afs_call *)call_user_ID;
call->need_attention = true;
wake_up(&call->waitq);
}
static void afs_wake_up_async_call(struct sock *sk, struct rxrpc_call *rxcall,
unsigned long call_user_ID)
{
struct afs_call *call = (struct afs_call *)call_user_ID;
int u;
trace_afs_notify_call(rxcall, call);
call->need_attention = true;
u = __atomic_add_unless(&call->usage, 1, 0);
if (u != 0) {
trace_afs_call(call, afs_call_trace_wake, u,
atomic_read(&afs_outstanding_calls),
__builtin_return_address(0));
if (!queue_work(afs_async_calls, &call->async_work))
afs_put_call(call);
}
}
static void afs_delete_async_call(struct work_struct *work)
{
struct afs_call *call = container_of(work, struct afs_call, async_work);
_enter("");
afs_put_call(call);
_leave("");
}
static void afs_process_async_call(struct work_struct *work)
{
struct afs_call *call = container_of(work, struct afs_call, async_work);
_enter("");
if (call->state < AFS_CALL_COMPLETE && call->need_attention) {
call->need_attention = false;
afs_deliver_to_call(call);
}
if (call->state == AFS_CALL_COMPLETE) {
call->reply = NULL;
call->async_work.func = afs_delete_async_call;
if (!queue_work(afs_async_calls, &call->async_work))
afs_put_call(call);
}
afs_put_call(call);
_leave("");
}
static void afs_rx_attach(struct rxrpc_call *rxcall, unsigned long user_call_ID)
{
struct afs_call *call = (struct afs_call *)user_call_ID;
call->rxcall = rxcall;
}
static void afs_charge_preallocation(struct work_struct *work)
{
struct afs_call *call = afs_spare_incoming_call;
for (;;) {
if (!call) {
call = afs_alloc_call(&afs_RXCMxxxx, GFP_KERNEL);
if (!call)
break;
call->async = true;
call->state = AFS_CALL_AWAIT_OP_ID;
init_waitqueue_head(&call->waitq);
}
if (rxrpc_kernel_charge_accept(afs_socket,
afs_wake_up_async_call,
afs_rx_attach,
(unsigned long)call,
GFP_KERNEL) < 0)
break;
call = NULL;
}
afs_spare_incoming_call = call;
}
static void afs_rx_discard_new_call(struct rxrpc_call *rxcall,
unsigned long user_call_ID)
{
struct afs_call *call = (struct afs_call *)user_call_ID;
call->rxcall = NULL;
afs_put_call(call);
}
static void afs_rx_new_call(struct sock *sk, struct rxrpc_call *rxcall,
unsigned long user_call_ID)
{
queue_work(afs_wq, &afs_charge_preallocation_work);
}
static int afs_deliver_cm_op_id(struct afs_call *call)
{
int ret;
_enter("{%zu}", call->offset);
ASSERTCMP(call->offset, <, 4);
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
call->operation_ID = ntohl(call->tmp);
call->state = AFS_CALL_AWAIT_REQUEST;
call->offset = 0;
if (!afs_cm_incoming_call(call))
return -ENOTSUPP;
trace_afs_cb_call(call);
return call->type->deliver(call);
}
void afs_send_empty_reply(struct afs_call *call)
{
struct msghdr msg;
_enter("");
msg.msg_name = NULL;
msg.msg_namelen = 0;
iov_iter_kvec(&msg.msg_iter, WRITE | ITER_KVEC, NULL, 0, 0);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
call->state = AFS_CALL_AWAIT_ACK;
switch (rxrpc_kernel_send_data(afs_socket, call->rxcall, &msg, 0)) {
case 0:
_leave(" [replied]");
return;
case -ENOMEM:
_debug("oom");
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
RX_USER_ABORT, -ENOMEM, "KOO");
default:
_leave(" [error]");
return;
}
}
void afs_send_simple_reply(struct afs_call *call, const void *buf, size_t len)
{
struct msghdr msg;
struct kvec iov[1];
int n;
_enter("");
iov[0].iov_base = (void *) buf;
iov[0].iov_len = len;
msg.msg_name = NULL;
msg.msg_namelen = 0;
iov_iter_kvec(&msg.msg_iter, WRITE | ITER_KVEC, iov, 1, len);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
call->state = AFS_CALL_AWAIT_ACK;
n = rxrpc_kernel_send_data(afs_socket, call->rxcall, &msg, len);
if (n >= 0) {
_leave(" [replied]");
return;
}
if (n == -ENOMEM) {
_debug("oom");
rxrpc_kernel_abort_call(afs_socket, call->rxcall,
RX_USER_ABORT, -ENOMEM, "KOO");
}
_leave(" [error]");
}
int afs_extract_data(struct afs_call *call, void *buf, size_t count,
bool want_more)
{
int ret;
_enter("{%s,%zu},,%zu,%d",
call->type->name, call->offset, count, want_more);
ASSERTCMP(call->offset, <=, count);
ret = rxrpc_kernel_recv_data(afs_socket, call->rxcall,
buf, count, &call->offset,
want_more, &call->abort_code);
trace_afs_recv_data(call, count, call->offset, want_more, ret);
if (ret == 0 || ret == -EAGAIN)
return ret;
if (ret == 1) {
switch (call->state) {
case AFS_CALL_AWAIT_REPLY:
call->state = AFS_CALL_COMPLETE;
break;
case AFS_CALL_AWAIT_REQUEST:
call->state = AFS_CALL_REPLYING;
break;
default:
break;
}
return 0;
}
if (ret == -ECONNABORTED)
call->error = call->type->abort_to_error(call->abort_code);
else
call->error = ret;
call->state = AFS_CALL_COMPLETE;
return ret;
}
