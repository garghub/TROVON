static void afs_async_workfn(struct work_struct *work)
{
struct afs_call *call = container_of(work, struct afs_call, async_work);
call->async_workfn(call);
}
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
skb_queue_head_init(&afs_incoming_calls);
ret = -ENOMEM;
afs_async_calls = create_singlethread_workqueue("kafsd");
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
ret = kernel_listen(socket, INT_MAX);
if (ret < 0)
goto error_2;
rxrpc_kernel_intercept_rx_messages(socket, afs_rx_interceptor);
afs_socket = socket;
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
wait_on_atomic_t(&afs_outstanding_calls, afs_wait_atomic_t,
TASK_UNINTERRUPTIBLE);
_debug("no outstanding calls");
sock_release(afs_socket);
_debug("dework");
destroy_workqueue(afs_async_calls);
ASSERTCMP(atomic_read(&afs_outstanding_skbs), ==, 0);
_leave("");
}
void afs_data_consumed(struct afs_call *call, struct sk_buff *skb)
{
if (!skb) {
_debug("DLVR NULL [%d]", atomic_read(&afs_outstanding_skbs));
dump_stack();
} else {
_debug("DLVR %p{%u} [%d]",
skb, skb->mark, atomic_read(&afs_outstanding_skbs));
rxrpc_kernel_data_consumed(call->rxcall, skb);
}
}
static void afs_free_skb(struct sk_buff *skb)
{
if (!skb) {
_debug("FREE NULL [%d]", atomic_read(&afs_outstanding_skbs));
dump_stack();
} else {
_debug("FREE %p{%u} [%d]",
skb, skb->mark, atomic_read(&afs_outstanding_skbs));
if (atomic_dec_return(&afs_outstanding_skbs) == -1)
BUG();
rxrpc_kernel_free_skb(skb);
}
}
static void afs_free_call(struct afs_call *call)
{
_debug("DONE %p{%s} [%d]",
call, call->type->name, atomic_read(&afs_outstanding_calls));
ASSERTCMP(call->rxcall, ==, NULL);
ASSERT(!work_pending(&call->async_work));
ASSERT(skb_queue_empty(&call->rx_queue));
ASSERT(call->type->name != NULL);
kfree(call->request);
kfree(call);
if (atomic_dec_and_test(&afs_outstanding_calls))
wake_up_atomic_t(&afs_outstanding_calls);
}
static void afs_end_call_nofree(struct afs_call *call)
{
if (call->rxcall) {
rxrpc_kernel_end_call(call->rxcall);
call->rxcall = NULL;
}
if (call->type->destructor)
call->type->destructor(call);
}
static void afs_end_call(struct afs_call *call)
{
afs_end_call_nofree(call);
afs_free_call(call);
}
struct afs_call *afs_alloc_flat_call(const struct afs_call_type *type,
size_t request_size, size_t reply_size)
{
struct afs_call *call;
call = kzalloc(sizeof(*call), GFP_NOFS);
if (!call)
goto nomem_call;
_debug("CALL %p{%s} [%d]",
call, type->name, atomic_read(&afs_outstanding_calls));
atomic_inc(&afs_outstanding_calls);
call->type = type;
call->request_size = request_size;
call->reply_max = reply_size;
if (request_size) {
call->request = kmalloc(request_size, GFP_NOFS);
if (!call->request)
goto nomem_free;
}
if (reply_size) {
call->buffer = kmalloc(reply_size, GFP_NOFS);
if (!call->buffer)
goto nomem_free;
}
init_waitqueue_head(&call->waitq);
skb_queue_head_init(&call->rx_queue);
return call;
nomem_free:
afs_free_call(call);
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
static int afs_send_pages(struct afs_call *call, struct msghdr *msg,
struct kvec *iov)
{
struct page *pages[8];
unsigned count, n, loop, offset, to;
pgoff_t first = call->first, last = call->last;
int ret;
_enter("");
offset = call->first_offset;
call->first_offset = 0;
do {
_debug("attach %lx-%lx", first, last);
count = last - first + 1;
if (count > ARRAY_SIZE(pages))
count = ARRAY_SIZE(pages);
n = find_get_pages_contig(call->mapping, first, count, pages);
ASSERTCMP(n, ==, count);
loop = 0;
do {
msg->msg_flags = 0;
to = PAGE_SIZE;
if (first + loop >= last)
to = call->last_to;
else
msg->msg_flags = MSG_MORE;
iov->iov_base = kmap(pages[loop]) + offset;
iov->iov_len = to - offset;
offset = 0;
_debug("- range %u-%u%s",
offset, to, msg->msg_flags ? " [more]" : "");
iov_iter_kvec(&msg->msg_iter, WRITE | ITER_KVEC,
iov, 1, to - offset);
if (first + loop >= last)
call->state = AFS_CALL_AWAIT_REPLY;
ret = rxrpc_kernel_send_data(call->rxcall, msg,
to - offset);
kunmap(pages[loop]);
if (ret < 0)
break;
} while (++loop < count);
first += count;
for (loop = 0; loop < count; loop++)
put_page(pages[loop]);
if (ret < 0)
break;
} while (first <= last);
_leave(" = %d", ret);
return ret;
}
int afs_make_call(struct in_addr *addr, struct afs_call *call, gfp_t gfp,
const struct afs_wait_mode *wait_mode)
{
struct sockaddr_rxrpc srx;
struct rxrpc_call *rxcall;
struct msghdr msg;
struct kvec iov[1];
int ret;
struct sk_buff *skb;
_enter("%x,{%d},", addr->s_addr, ntohs(call->port));
ASSERT(call->type != NULL);
ASSERT(call->type->name != NULL);
_debug("____MAKE %p{%s,%x} [%d]____",
call, call->type->name, key_serial(call->key),
atomic_read(&afs_outstanding_calls));
call->wait_mode = wait_mode;
call->async_workfn = afs_process_async_call;
INIT_WORK(&call->async_work, afs_async_workfn);
memset(&srx, 0, sizeof(srx));
srx.srx_family = AF_RXRPC;
srx.srx_service = call->service_id;
srx.transport_type = SOCK_DGRAM;
srx.transport_len = sizeof(srx.transport.sin);
srx.transport.sin.sin_family = AF_INET;
srx.transport.sin.sin_port = call->port;
memcpy(&srx.transport.sin.sin_addr, addr, 4);
rxcall = rxrpc_kernel_begin_call(afs_socket, &srx, call->key,
(unsigned long) call, gfp);
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
ret = rxrpc_kernel_send_data(rxcall, &msg, call->request_size);
if (ret < 0)
goto error_do_abort;
if (call->send_pages) {
ret = afs_send_pages(call, &msg, iov);
if (ret < 0)
goto error_do_abort;
}
return wait_mode->wait(call);
error_do_abort:
rxrpc_kernel_abort_call(rxcall, RX_USER_ABORT);
while ((skb = skb_dequeue(&call->rx_queue)))
afs_free_skb(skb);
error_kill_call:
afs_end_call(call);
_leave(" = %d", ret);
return ret;
}
static void afs_rx_interceptor(struct sock *sk, unsigned long user_call_ID,
struct sk_buff *skb)
{
struct afs_call *call = (struct afs_call *) user_call_ID;
_enter("%p,,%u", call, skb->mark);
_debug("ICPT %p{%u} [%d]",
skb, skb->mark, atomic_read(&afs_outstanding_skbs));
ASSERTCMP(sk, ==, afs_socket->sk);
atomic_inc(&afs_outstanding_skbs);
if (!call) {
skb_queue_tail(&afs_incoming_calls, skb);
queue_work(afs_wq, &afs_collect_incoming_call_work);
} else {
skb_queue_tail(&call->rx_queue, skb);
call->wait_mode->rx_wakeup(call);
}
_leave("");
}
static void afs_deliver_to_call(struct afs_call *call)
{
struct sk_buff *skb;
bool last;
u32 abort_code;
int ret;
_enter("");
while ((call->state == AFS_CALL_AWAIT_REPLY ||
call->state == AFS_CALL_AWAIT_OP_ID ||
call->state == AFS_CALL_AWAIT_REQUEST ||
call->state == AFS_CALL_AWAIT_ACK) &&
(skb = skb_dequeue(&call->rx_queue))) {
switch (skb->mark) {
case RXRPC_SKB_MARK_DATA:
_debug("Rcv DATA");
last = rxrpc_kernel_is_data_last(skb);
ret = call->type->deliver(call, skb, last);
switch (ret) {
case -EAGAIN:
if (last) {
_debug("short data");
goto unmarshal_error;
}
break;
case 0:
ASSERT(last);
if (call->state == AFS_CALL_AWAIT_REPLY)
call->state = AFS_CALL_COMPLETE;
break;
case -ENOTCONN:
abort_code = RX_CALL_DEAD;
goto do_abort;
case -ENOTSUPP:
abort_code = RX_INVALID_OPERATION;
goto do_abort;
default:
unmarshal_error:
abort_code = RXGEN_CC_UNMARSHAL;
if (call->state != AFS_CALL_AWAIT_REPLY)
abort_code = RXGEN_SS_UNMARSHAL;
do_abort:
rxrpc_kernel_abort_call(call->rxcall,
abort_code);
call->error = ret;
call->state = AFS_CALL_ERROR;
break;
}
break;
case RXRPC_SKB_MARK_FINAL_ACK:
_debug("Rcv ACK");
call->state = AFS_CALL_COMPLETE;
break;
case RXRPC_SKB_MARK_BUSY:
_debug("Rcv BUSY");
call->error = -EBUSY;
call->state = AFS_CALL_BUSY;
break;
case RXRPC_SKB_MARK_REMOTE_ABORT:
abort_code = rxrpc_kernel_get_abort_code(skb);
call->error = call->type->abort_to_error(abort_code);
call->state = AFS_CALL_ABORTED;
_debug("Rcv ABORT %u -> %d", abort_code, call->error);
break;
case RXRPC_SKB_MARK_LOCAL_ABORT:
abort_code = rxrpc_kernel_get_abort_code(skb);
call->error = call->type->abort_to_error(abort_code);
call->state = AFS_CALL_ABORTED;
_debug("Loc ABORT %u -> %d", abort_code, call->error);
break;
case RXRPC_SKB_MARK_NET_ERROR:
call->error = -rxrpc_kernel_get_error_number(skb);
call->state = AFS_CALL_ERROR;
_debug("Rcv NET ERROR %d", call->error);
break;
case RXRPC_SKB_MARK_LOCAL_ERROR:
call->error = -rxrpc_kernel_get_error_number(skb);
call->state = AFS_CALL_ERROR;
_debug("Rcv LOCAL ERROR %d", call->error);
break;
default:
BUG();
break;
}
afs_free_skb(skb);
}
if (call->state >= AFS_CALL_COMPLETE) {
while ((skb = skb_dequeue(&call->rx_queue)))
afs_free_skb(skb);
if (call->incoming)
afs_end_call(call);
}
_leave("");
}
static int afs_wait_for_call_to_complete(struct afs_call *call)
{
struct sk_buff *skb;
int ret;
DECLARE_WAITQUEUE(myself, current);
_enter("");
add_wait_queue(&call->waitq, &myself);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (!skb_queue_empty(&call->rx_queue)) {
__set_current_state(TASK_RUNNING);
afs_deliver_to_call(call);
continue;
}
ret = call->error;
if (call->state >= AFS_CALL_COMPLETE)
break;
ret = -EINTR;
if (signal_pending(current))
break;
schedule();
}
remove_wait_queue(&call->waitq, &myself);
__set_current_state(TASK_RUNNING);
if (call->state < AFS_CALL_COMPLETE) {
_debug("call incomplete");
rxrpc_kernel_abort_call(call->rxcall, RX_CALL_DEAD);
while ((skb = skb_dequeue(&call->rx_queue)))
afs_free_skb(skb);
}
_debug("call complete");
afs_end_call(call);
_leave(" = %d", ret);
return ret;
}
static void afs_wake_up_call_waiter(struct afs_call *call)
{
wake_up(&call->waitq);
}
static void afs_wake_up_async_call(struct afs_call *call)
{
_enter("");
queue_work(afs_async_calls, &call->async_work);
}
static int afs_dont_wait_for_call_to_complete(struct afs_call *call)
{
_enter("");
return -EINPROGRESS;
}
static void afs_delete_async_call(struct afs_call *call)
{
_enter("");
afs_free_call(call);
_leave("");
}
static void afs_process_async_call(struct afs_call *call)
{
_enter("");
if (!skb_queue_empty(&call->rx_queue))
afs_deliver_to_call(call);
if (call->state >= AFS_CALL_COMPLETE && call->wait_mode) {
if (call->wait_mode->async_complete)
call->wait_mode->async_complete(call->reply,
call->error);
call->reply = NULL;
afs_end_call_nofree(call);
call->async_workfn = afs_delete_async_call;
queue_work(afs_async_calls, &call->async_work);
}
_leave("");
}
int afs_transfer_reply(struct afs_call *call, struct sk_buff *skb, bool last)
{
size_t len = skb->len;
if (len > call->reply_max - call->reply_size) {
_leave(" = -EBADMSG [%zu > %u]",
len, call->reply_max - call->reply_size);
return -EBADMSG;
}
if (len > 0) {
if (skb_copy_bits(skb, 0, call->buffer + call->reply_size,
len) < 0)
BUG();
call->reply_size += len;
}
afs_data_consumed(call, skb);
if (!last)
return -EAGAIN;
if (call->reply_size != call->reply_max) {
_leave(" = -EBADMSG [%u != %u]",
call->reply_size, call->reply_max);
return -EBADMSG;
}
return 0;
}
static void afs_collect_incoming_call(struct work_struct *work)
{
struct rxrpc_call *rxcall;
struct afs_call *call = NULL;
struct sk_buff *skb;
while ((skb = skb_dequeue(&afs_incoming_calls))) {
_debug("new call");
afs_free_skb(skb);
if (!call) {
call = kzalloc(sizeof(struct afs_call), GFP_KERNEL);
if (!call) {
rxrpc_kernel_reject_call(afs_socket);
return;
}
call->async_workfn = afs_process_async_call;
INIT_WORK(&call->async_work, afs_async_workfn);
call->wait_mode = &afs_async_incoming_call;
call->type = &afs_RXCMxxxx;
init_waitqueue_head(&call->waitq);
skb_queue_head_init(&call->rx_queue);
call->state = AFS_CALL_AWAIT_OP_ID;
_debug("CALL %p{%s} [%d]",
call, call->type->name,
atomic_read(&afs_outstanding_calls));
atomic_inc(&afs_outstanding_calls);
}
rxcall = rxrpc_kernel_accept_call(afs_socket,
(unsigned long) call);
if (!IS_ERR(rxcall)) {
call->rxcall = rxcall;
call = NULL;
}
}
if (call)
afs_free_call(call);
}
static int afs_deliver_cm_op_id(struct afs_call *call, struct sk_buff *skb,
bool last)
{
size_t len = skb->len;
void *oibuf = (void *) &call->operation_ID;
_enter("{%u},{%zu},%d", call->offset, len, last);
ASSERTCMP(call->offset, <, 4);
len = min_t(size_t, len, 4 - call->offset);
if (skb_copy_bits(skb, 0, oibuf + call->offset, len) < 0)
BUG();
if (!pskb_pull(skb, len))
BUG();
call->offset += len;
if (call->offset < 4) {
afs_data_consumed(call, skb);
_leave(" = -EAGAIN");
return -EAGAIN;
}
call->state = AFS_CALL_AWAIT_REQUEST;
if (!afs_cm_incoming_call(call))
return -ENOTSUPP;
return call->type->deliver(call, skb, last);
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
switch (rxrpc_kernel_send_data(call->rxcall, &msg, 0)) {
case 0:
_leave(" [replied]");
return;
case -ENOMEM:
_debug("oom");
rxrpc_kernel_abort_call(call->rxcall, RX_USER_ABORT);
default:
afs_end_call(call);
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
n = rxrpc_kernel_send_data(call->rxcall, &msg, len);
if (n >= 0) {
_leave(" [replied]");
return;
}
if (n == -ENOMEM) {
_debug("oom");
rxrpc_kernel_abort_call(call->rxcall, RX_USER_ABORT);
}
afs_end_call(call);
_leave(" [error]");
}
int afs_extract_data(struct afs_call *call, struct sk_buff *skb,
bool last, void *buf, size_t count)
{
size_t len = skb->len;
_enter("{%u},{%zu},%d,,%zu", call->offset, len, last, count);
ASSERTCMP(call->offset, <, count);
len = min_t(size_t, len, count - call->offset);
if (skb_copy_bits(skb, 0, buf + call->offset, len) < 0 ||
!pskb_pull(skb, len))
BUG();
call->offset += len;
if (call->offset < count) {
afs_data_consumed(call, skb);
_leave(" = -EAGAIN");
return -EAGAIN;
}
return 0;
}
