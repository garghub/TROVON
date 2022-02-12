static void xs_pktdump(char *msg, u32 *packet, unsigned int count)
{
u8 *buf = (u8 *) packet;
int j;
dprintk("RPC: %s\n", msg);
for (j = 0; j < count && j < 128; j += 4) {
if (!(j & 31)) {
if (j)
dprintk("\n");
dprintk("0x%04x ", j);
}
dprintk("%02x%02x%02x%02x ",
buf[j], buf[j+1], buf[j+2], buf[j+3]);
}
dprintk("\n");
}
static inline void xs_pktdump(char *msg, u32 *packet, unsigned int count)
{
}
static inline struct rpc_xprt *xprt_from_sock(struct sock *sk)
{
return (struct rpc_xprt *) sk->sk_user_data;
}
static inline struct sockaddr *xs_addr(struct rpc_xprt *xprt)
{
return (struct sockaddr *) &xprt->addr;
}
static inline struct sockaddr_un *xs_addr_un(struct rpc_xprt *xprt)
{
return (struct sockaddr_un *) &xprt->addr;
}
static inline struct sockaddr_in *xs_addr_in(struct rpc_xprt *xprt)
{
return (struct sockaddr_in *) &xprt->addr;
}
static inline struct sockaddr_in6 *xs_addr_in6(struct rpc_xprt *xprt)
{
return (struct sockaddr_in6 *) &xprt->addr;
}
static void xs_format_common_peer_addresses(struct rpc_xprt *xprt)
{
struct sockaddr *sap = xs_addr(xprt);
struct sockaddr_in6 *sin6;
struct sockaddr_in *sin;
struct sockaddr_un *sun;
char buf[128];
switch (sap->sa_family) {
case AF_LOCAL:
sun = xs_addr_un(xprt);
strlcpy(buf, sun->sun_path, sizeof(buf));
xprt->address_strings[RPC_DISPLAY_ADDR] =
kstrdup(buf, GFP_KERNEL);
break;
case AF_INET:
(void)rpc_ntop(sap, buf, sizeof(buf));
xprt->address_strings[RPC_DISPLAY_ADDR] =
kstrdup(buf, GFP_KERNEL);
sin = xs_addr_in(xprt);
snprintf(buf, sizeof(buf), "%08x", ntohl(sin->sin_addr.s_addr));
break;
case AF_INET6:
(void)rpc_ntop(sap, buf, sizeof(buf));
xprt->address_strings[RPC_DISPLAY_ADDR] =
kstrdup(buf, GFP_KERNEL);
sin6 = xs_addr_in6(xprt);
snprintf(buf, sizeof(buf), "%pi6", &sin6->sin6_addr);
break;
default:
BUG();
}
xprt->address_strings[RPC_DISPLAY_HEX_ADDR] = kstrdup(buf, GFP_KERNEL);
}
static void xs_format_common_peer_ports(struct rpc_xprt *xprt)
{
struct sockaddr *sap = xs_addr(xprt);
char buf[128];
snprintf(buf, sizeof(buf), "%u", rpc_get_port(sap));
xprt->address_strings[RPC_DISPLAY_PORT] = kstrdup(buf, GFP_KERNEL);
snprintf(buf, sizeof(buf), "%4hx", rpc_get_port(sap));
xprt->address_strings[RPC_DISPLAY_HEX_PORT] = kstrdup(buf, GFP_KERNEL);
}
static void xs_format_peer_addresses(struct rpc_xprt *xprt,
const char *protocol,
const char *netid)
{
xprt->address_strings[RPC_DISPLAY_PROTO] = protocol;
xprt->address_strings[RPC_DISPLAY_NETID] = netid;
xs_format_common_peer_addresses(xprt);
xs_format_common_peer_ports(xprt);
}
static void xs_update_peer_port(struct rpc_xprt *xprt)
{
kfree(xprt->address_strings[RPC_DISPLAY_HEX_PORT]);
kfree(xprt->address_strings[RPC_DISPLAY_PORT]);
xs_format_common_peer_ports(xprt);
}
static void xs_free_peer_addresses(struct rpc_xprt *xprt)
{
unsigned int i;
for (i = 0; i < RPC_DISPLAY_MAX; i++)
switch (i) {
case RPC_DISPLAY_PROTO:
case RPC_DISPLAY_NETID:
continue;
default:
kfree(xprt->address_strings[i]);
}
}
static int xs_send_kvec(struct socket *sock, struct sockaddr *addr, int addrlen, struct kvec *vec, unsigned int base, int more)
{
struct msghdr msg = {
.msg_name = addr,
.msg_namelen = addrlen,
.msg_flags = XS_SENDMSG_FLAGS | (more ? MSG_MORE : 0),
};
struct kvec iov = {
.iov_base = vec->iov_base + base,
.iov_len = vec->iov_len - base,
};
if (iov.iov_len != 0)
return kernel_sendmsg(sock, &msg, &iov, 1, iov.iov_len);
return kernel_sendmsg(sock, &msg, NULL, 0, 0);
}
static int xs_send_pagedata(struct socket *sock, struct xdr_buf *xdr, unsigned int base, int more, bool zerocopy, int *sent_p)
{
ssize_t (*do_sendpage)(struct socket *sock, struct page *page,
int offset, size_t size, int flags);
struct page **ppage;
unsigned int remainder;
int err;
remainder = xdr->page_len - base;
base += xdr->page_base;
ppage = xdr->pages + (base >> PAGE_SHIFT);
base &= ~PAGE_MASK;
do_sendpage = sock->ops->sendpage;
if (!zerocopy)
do_sendpage = sock_no_sendpage;
for(;;) {
unsigned int len = min_t(unsigned int, PAGE_SIZE - base, remainder);
int flags = XS_SENDMSG_FLAGS;
remainder -= len;
if (remainder != 0 || more)
flags |= MSG_MORE;
err = do_sendpage(sock, *ppage, base, len, flags);
if (remainder == 0 || err != len)
break;
*sent_p += err;
ppage++;
base = 0;
}
if (err > 0) {
*sent_p += err;
err = 0;
}
return err;
}
static int xs_sendpages(struct socket *sock, struct sockaddr *addr, int addrlen, struct xdr_buf *xdr, unsigned int base, bool zerocopy, int *sent_p)
{
unsigned int remainder = xdr->len - base;
int err = 0;
int sent = 0;
if (unlikely(!sock))
return -ENOTSOCK;
clear_bit(SOCK_ASYNC_NOSPACE, &sock->flags);
if (base != 0) {
addr = NULL;
addrlen = 0;
}
if (base < xdr->head[0].iov_len || addr != NULL) {
unsigned int len = xdr->head[0].iov_len - base;
remainder -= len;
err = xs_send_kvec(sock, addr, addrlen, &xdr->head[0], base, remainder != 0);
if (remainder == 0 || err != len)
goto out;
*sent_p += err;
base = 0;
} else
base -= xdr->head[0].iov_len;
if (base < xdr->page_len) {
unsigned int len = xdr->page_len - base;
remainder -= len;
err = xs_send_pagedata(sock, xdr, base, remainder != 0, zerocopy, &sent);
*sent_p += sent;
if (remainder == 0 || sent != len)
goto out;
base = 0;
} else
base -= xdr->page_len;
if (base >= xdr->tail[0].iov_len)
return 0;
err = xs_send_kvec(sock, NULL, 0, &xdr->tail[0], base, 0);
out:
if (err > 0) {
*sent_p += err;
err = 0;
}
return err;
}
static void xs_nospace_callback(struct rpc_task *task)
{
struct sock_xprt *transport = container_of(task->tk_rqstp->rq_xprt, struct sock_xprt, xprt);
transport->inet->sk_write_pending--;
clear_bit(SOCK_ASYNC_NOSPACE, &transport->sock->flags);
}
static int xs_nospace(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct sock *sk = transport->inet;
int ret = -EAGAIN;
dprintk("RPC: %5u xmit incomplete (%u left of %u)\n",
task->tk_pid, req->rq_slen - req->rq_bytes_sent,
req->rq_slen);
spin_lock_bh(&xprt->transport_lock);
if (xprt_connected(xprt)) {
if (test_bit(SOCK_ASYNC_NOSPACE, &transport->sock->flags)) {
set_bit(SOCK_NOSPACE, &transport->sock->flags);
sk->sk_write_pending++;
xprt_wait_for_buffer_space(task, xs_nospace_callback);
}
} else {
clear_bit(SOCK_ASYNC_NOSPACE, &transport->sock->flags);
ret = -ENOTCONN;
}
spin_unlock_bh(&xprt->transport_lock);
sk->sk_write_space(sk);
return ret;
}
static inline void xs_encode_stream_record_marker(struct xdr_buf *buf)
{
u32 reclen = buf->len - sizeof(rpc_fraghdr);
rpc_fraghdr *base = buf->head[0].iov_base;
*base = cpu_to_be32(RPC_LAST_STREAM_FRAGMENT | reclen);
}
static int xs_local_send_request(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
struct xdr_buf *xdr = &req->rq_snd_buf;
int status;
int sent = 0;
xs_encode_stream_record_marker(&req->rq_snd_buf);
xs_pktdump("packet data:",
req->rq_svec->iov_base, req->rq_svec->iov_len);
status = xs_sendpages(transport->sock, NULL, 0, xdr, req->rq_bytes_sent,
true, &sent);
dprintk("RPC: %s(%u) = %d\n",
__func__, xdr->len - req->rq_bytes_sent, status);
if (likely(sent > 0) || status == 0) {
req->rq_bytes_sent += sent;
req->rq_xmit_bytes_sent += sent;
if (likely(req->rq_bytes_sent >= req->rq_slen)) {
req->rq_bytes_sent = 0;
return 0;
}
status = -EAGAIN;
}
switch (status) {
case -ENOBUFS:
case -EAGAIN:
status = xs_nospace(task);
break;
default:
dprintk("RPC: sendmsg returned unrecognized error %d\n",
-status);
case -EPIPE:
xs_close(xprt);
status = -ENOTCONN;
}
return status;
}
static int xs_udp_send_request(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct xdr_buf *xdr = &req->rq_snd_buf;
int sent = 0;
int status;
xs_pktdump("packet data:",
req->rq_svec->iov_base,
req->rq_svec->iov_len);
if (!xprt_bound(xprt))
return -ENOTCONN;
status = xs_sendpages(transport->sock, xs_addr(xprt), xprt->addrlen,
xdr, req->rq_bytes_sent, true, &sent);
dprintk("RPC: xs_udp_send_request(%u) = %d\n",
xdr->len - req->rq_bytes_sent, status);
if (status == -EPERM)
goto process_status;
if (sent > 0 || status == 0) {
req->rq_xmit_bytes_sent += sent;
if (sent >= req->rq_slen)
return 0;
status = -EAGAIN;
}
process_status:
switch (status) {
case -ENOTSOCK:
status = -ENOTCONN;
break;
case -EAGAIN:
status = xs_nospace(task);
break;
default:
dprintk("RPC: sendmsg returned unrecognized error %d\n",
-status);
case -ENETUNREACH:
case -ENOBUFS:
case -EPIPE:
case -ECONNREFUSED:
case -EPERM:
clear_bit(SOCK_ASYNC_NOSPACE, &transport->sock->flags);
}
return status;
}
static void xs_tcp_shutdown(struct rpc_xprt *xprt)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct socket *sock = transport->sock;
if (sock != NULL) {
kernel_sock_shutdown(sock, SHUT_WR);
trace_rpc_socket_shutdown(xprt, sock);
}
}
static int xs_tcp_send_request(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct rpc_xprt *xprt = req->rq_xprt;
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct xdr_buf *xdr = &req->rq_snd_buf;
bool zerocopy = true;
int status;
int sent;
xs_encode_stream_record_marker(&req->rq_snd_buf);
xs_pktdump("packet data:",
req->rq_svec->iov_base,
req->rq_svec->iov_len);
if (task->tk_flags & RPC_TASK_SENT)
zerocopy = false;
while (1) {
sent = 0;
status = xs_sendpages(transport->sock, NULL, 0, xdr,
req->rq_bytes_sent, zerocopy, &sent);
dprintk("RPC: xs_tcp_send_request(%u) = %d\n",
xdr->len - req->rq_bytes_sent, status);
if (unlikely(sent == 0 && status < 0))
break;
req->rq_bytes_sent += sent;
req->rq_xmit_bytes_sent += sent;
if (likely(req->rq_bytes_sent >= req->rq_slen)) {
req->rq_bytes_sent = 0;
return 0;
}
if (sent != 0)
continue;
status = -EAGAIN;
break;
}
switch (status) {
case -ENOTSOCK:
status = -ENOTCONN;
break;
case -ENOBUFS:
case -EAGAIN:
status = xs_nospace(task);
break;
default:
dprintk("RPC: sendmsg returned unrecognized error %d\n",
-status);
case -ECONNRESET:
xs_tcp_shutdown(xprt);
case -ECONNREFUSED:
case -ENOTCONN:
case -EPIPE:
clear_bit(SOCK_ASYNC_NOSPACE, &transport->sock->flags);
}
return status;
}
static void xs_tcp_release_xprt(struct rpc_xprt *xprt, struct rpc_task *task)
{
struct rpc_rqst *req;
if (task != xprt->snd_task)
return;
if (task == NULL)
goto out_release;
req = task->tk_rqstp;
if (req == NULL)
goto out_release;
if (req->rq_bytes_sent == 0)
goto out_release;
if (req->rq_bytes_sent == req->rq_snd_buf.len)
goto out_release;
set_bit(XPRT_CLOSE_WAIT, &xprt->state);
out_release:
xprt_release_xprt(xprt, task);
}
static void xs_save_old_callbacks(struct sock_xprt *transport, struct sock *sk)
{
transport->old_data_ready = sk->sk_data_ready;
transport->old_state_change = sk->sk_state_change;
transport->old_write_space = sk->sk_write_space;
transport->old_error_report = sk->sk_error_report;
}
static void xs_restore_old_callbacks(struct sock_xprt *transport, struct sock *sk)
{
sk->sk_data_ready = transport->old_data_ready;
sk->sk_state_change = transport->old_state_change;
sk->sk_write_space = transport->old_write_space;
sk->sk_error_report = transport->old_error_report;
}
static void xs_error_report(struct sock *sk)
{
struct rpc_xprt *xprt;
int err;
read_lock_bh(&sk->sk_callback_lock);
if (!(xprt = xprt_from_sock(sk)))
goto out;
err = -sk->sk_err;
if (err == 0)
goto out;
dprintk("RPC: xs_error_report client %p, error=%d...\n",
xprt, -err);
trace_rpc_socket_error(xprt, sk->sk_socket, err);
if (test_bit(XPRT_CONNECTION_REUSE, &xprt->state))
goto out;
xprt_wake_pending_tasks(xprt, err);
out:
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_reset_transport(struct sock_xprt *transport)
{
struct socket *sock = transport->sock;
struct sock *sk = transport->inet;
if (sk == NULL)
return;
transport->srcport = 0;
write_lock_bh(&sk->sk_callback_lock);
transport->inet = NULL;
transport->sock = NULL;
sk->sk_user_data = NULL;
xs_restore_old_callbacks(transport, sk);
write_unlock_bh(&sk->sk_callback_lock);
trace_rpc_socket_close(&transport->xprt, sock);
sock_release(sock);
}
static void xs_close(struct rpc_xprt *xprt)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
dprintk("RPC: xs_close xprt %p\n", xprt);
cancel_delayed_work_sync(&transport->connect_worker);
xs_reset_transport(transport);
xprt->reestablish_timeout = 0;
smp_mb__before_atomic();
clear_bit(XPRT_CONNECTION_ABORT, &xprt->state);
clear_bit(XPRT_CLOSE_WAIT, &xprt->state);
clear_bit(XPRT_CLOSING, &xprt->state);
smp_mb__after_atomic();
xprt_disconnect_done(xprt);
}
static void xs_tcp_close(struct rpc_xprt *xprt)
{
if (test_and_clear_bit(XPRT_CONNECTION_CLOSE, &xprt->state))
xs_close(xprt);
else
xs_tcp_shutdown(xprt);
}
static void xs_xprt_free(struct rpc_xprt *xprt)
{
xs_free_peer_addresses(xprt);
xprt_free(xprt);
}
static void xs_destroy(struct rpc_xprt *xprt)
{
dprintk("RPC: xs_destroy xprt %p\n", xprt);
xs_close(xprt);
xs_xprt_free(xprt);
module_put(THIS_MODULE);
}
static int xs_local_copy_to_xdr(struct xdr_buf *xdr, struct sk_buff *skb)
{
struct xdr_skb_reader desc = {
.skb = skb,
.offset = sizeof(rpc_fraghdr),
.count = skb->len - sizeof(rpc_fraghdr),
};
if (xdr_partial_copy_from_skb(xdr, 0, &desc, xdr_skb_read_bits) < 0)
return -1;
if (desc.count)
return -1;
return 0;
}
static void xs_local_data_ready(struct sock *sk)
{
struct rpc_task *task;
struct rpc_xprt *xprt;
struct rpc_rqst *rovr;
struct sk_buff *skb;
int err, repsize, copied;
u32 _xid;
__be32 *xp;
read_lock_bh(&sk->sk_callback_lock);
dprintk("RPC: %s...\n", __func__);
xprt = xprt_from_sock(sk);
if (xprt == NULL)
goto out;
skb = skb_recv_datagram(sk, 0, 1, &err);
if (skb == NULL)
goto out;
repsize = skb->len - sizeof(rpc_fraghdr);
if (repsize < 4) {
dprintk("RPC: impossible RPC reply size %d\n", repsize);
goto dropit;
}
xp = skb_header_pointer(skb, sizeof(rpc_fraghdr), sizeof(_xid), &_xid);
if (xp == NULL)
goto dropit;
spin_lock(&xprt->transport_lock);
rovr = xprt_lookup_rqst(xprt, *xp);
if (!rovr)
goto out_unlock;
task = rovr->rq_task;
copied = rovr->rq_private_buf.buflen;
if (copied > repsize)
copied = repsize;
if (xs_local_copy_to_xdr(&rovr->rq_private_buf, skb)) {
dprintk("RPC: sk_buff copy failed\n");
goto out_unlock;
}
xprt_complete_rqst(task, copied);
out_unlock:
spin_unlock(&xprt->transport_lock);
dropit:
skb_free_datagram(sk, skb);
out:
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_udp_data_ready(struct sock *sk)
{
struct rpc_task *task;
struct rpc_xprt *xprt;
struct rpc_rqst *rovr;
struct sk_buff *skb;
int err, repsize, copied;
u32 _xid;
__be32 *xp;
read_lock_bh(&sk->sk_callback_lock);
dprintk("RPC: xs_udp_data_ready...\n");
if (!(xprt = xprt_from_sock(sk)))
goto out;
if ((skb = skb_recv_datagram(sk, 0, 1, &err)) == NULL)
goto out;
repsize = skb->len - sizeof(struct udphdr);
if (repsize < 4) {
dprintk("RPC: impossible RPC reply size %d!\n", repsize);
goto dropit;
}
xp = skb_header_pointer(skb, sizeof(struct udphdr),
sizeof(_xid), &_xid);
if (xp == NULL)
goto dropit;
spin_lock(&xprt->transport_lock);
rovr = xprt_lookup_rqst(xprt, *xp);
if (!rovr)
goto out_unlock;
task = rovr->rq_task;
if ((copied = rovr->rq_private_buf.buflen) > repsize)
copied = repsize;
if (csum_partial_copy_to_xdr(&rovr->rq_private_buf, skb)) {
UDPX_INC_STATS_BH(sk, UDP_MIB_INERRORS);
goto out_unlock;
}
UDPX_INC_STATS_BH(sk, UDP_MIB_INDATAGRAMS);
xprt_adjust_cwnd(xprt, task, copied);
xprt_complete_rqst(task, copied);
out_unlock:
spin_unlock(&xprt->transport_lock);
dropit:
skb_free_datagram(sk, skb);
out:
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_tcp_force_close(struct rpc_xprt *xprt)
{
set_bit(XPRT_CONNECTION_CLOSE, &xprt->state);
xprt_force_disconnect(xprt);
}
static inline void xs_tcp_read_fraghdr(struct rpc_xprt *xprt, struct xdr_skb_reader *desc)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
size_t len, used;
char *p;
p = ((char *) &transport->tcp_fraghdr) + transport->tcp_offset;
len = sizeof(transport->tcp_fraghdr) - transport->tcp_offset;
used = xdr_skb_read_bits(desc, p, len);
transport->tcp_offset += used;
if (used != len)
return;
transport->tcp_reclen = ntohl(transport->tcp_fraghdr);
if (transport->tcp_reclen & RPC_LAST_STREAM_FRAGMENT)
transport->tcp_flags |= TCP_RCV_LAST_FRAG;
else
transport->tcp_flags &= ~TCP_RCV_LAST_FRAG;
transport->tcp_reclen &= RPC_FRAGMENT_SIZE_MASK;
transport->tcp_flags &= ~TCP_RCV_COPY_FRAGHDR;
transport->tcp_offset = 0;
if (unlikely(transport->tcp_reclen < 8)) {
dprintk("RPC: invalid TCP record fragment length\n");
xs_tcp_force_close(xprt);
return;
}
dprintk("RPC: reading TCP record fragment of length %d\n",
transport->tcp_reclen);
}
static void xs_tcp_check_fraghdr(struct sock_xprt *transport)
{
if (transport->tcp_offset == transport->tcp_reclen) {
transport->tcp_flags |= TCP_RCV_COPY_FRAGHDR;
transport->tcp_offset = 0;
if (transport->tcp_flags & TCP_RCV_LAST_FRAG) {
transport->tcp_flags &= ~TCP_RCV_COPY_DATA;
transport->tcp_flags |= TCP_RCV_COPY_XID;
transport->tcp_copied = 0;
}
}
}
static inline void xs_tcp_read_xid(struct sock_xprt *transport, struct xdr_skb_reader *desc)
{
size_t len, used;
char *p;
len = sizeof(transport->tcp_xid) - transport->tcp_offset;
dprintk("RPC: reading XID (%Zu bytes)\n", len);
p = ((char *) &transport->tcp_xid) + transport->tcp_offset;
used = xdr_skb_read_bits(desc, p, len);
transport->tcp_offset += used;
if (used != len)
return;
transport->tcp_flags &= ~TCP_RCV_COPY_XID;
transport->tcp_flags |= TCP_RCV_READ_CALLDIR;
transport->tcp_copied = 4;
dprintk("RPC: reading %s XID %08x\n",
(transport->tcp_flags & TCP_RPC_REPLY) ? "reply for"
: "request with",
ntohl(transport->tcp_xid));
xs_tcp_check_fraghdr(transport);
}
static inline void xs_tcp_read_calldir(struct sock_xprt *transport,
struct xdr_skb_reader *desc)
{
size_t len, used;
u32 offset;
char *p;
offset = transport->tcp_offset - sizeof(transport->tcp_xid);
len = sizeof(transport->tcp_calldir) - offset;
dprintk("RPC: reading CALL/REPLY flag (%Zu bytes)\n", len);
p = ((char *) &transport->tcp_calldir) + offset;
used = xdr_skb_read_bits(desc, p, len);
transport->tcp_offset += used;
if (used != len)
return;
transport->tcp_flags &= ~TCP_RCV_READ_CALLDIR;
switch (ntohl(transport->tcp_calldir)) {
case RPC_REPLY:
transport->tcp_flags |= TCP_RCV_COPY_CALLDIR;
transport->tcp_flags |= TCP_RCV_COPY_DATA;
transport->tcp_flags |= TCP_RPC_REPLY;
break;
case RPC_CALL:
transport->tcp_flags |= TCP_RCV_COPY_CALLDIR;
transport->tcp_flags |= TCP_RCV_COPY_DATA;
transport->tcp_flags &= ~TCP_RPC_REPLY;
break;
default:
dprintk("RPC: invalid request message type\n");
xs_tcp_force_close(&transport->xprt);
}
xs_tcp_check_fraghdr(transport);
}
static inline void xs_tcp_read_common(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc,
struct rpc_rqst *req)
{
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
struct xdr_buf *rcvbuf;
size_t len;
ssize_t r;
rcvbuf = &req->rq_private_buf;
if (transport->tcp_flags & TCP_RCV_COPY_CALLDIR) {
memcpy(rcvbuf->head[0].iov_base + transport->tcp_copied,
&transport->tcp_calldir,
sizeof(transport->tcp_calldir));
transport->tcp_copied += sizeof(transport->tcp_calldir);
transport->tcp_flags &= ~TCP_RCV_COPY_CALLDIR;
}
len = desc->count;
if (len > transport->tcp_reclen - transport->tcp_offset) {
struct xdr_skb_reader my_desc;
len = transport->tcp_reclen - transport->tcp_offset;
memcpy(&my_desc, desc, sizeof(my_desc));
my_desc.count = len;
r = xdr_partial_copy_from_skb(rcvbuf, transport->tcp_copied,
&my_desc, xdr_skb_read_bits);
desc->count -= r;
desc->offset += r;
} else
r = xdr_partial_copy_from_skb(rcvbuf, transport->tcp_copied,
desc, xdr_skb_read_bits);
if (r > 0) {
transport->tcp_copied += r;
transport->tcp_offset += r;
}
if (r != len) {
transport->tcp_flags &= ~TCP_RCV_COPY_DATA;
dprintk("RPC: XID %08x truncated request\n",
ntohl(transport->tcp_xid));
dprintk("RPC: xprt = %p, tcp_copied = %lu, "
"tcp_offset = %u, tcp_reclen = %u\n",
xprt, transport->tcp_copied,
transport->tcp_offset, transport->tcp_reclen);
return;
}
dprintk("RPC: XID %08x read %Zd bytes\n",
ntohl(transport->tcp_xid), r);
dprintk("RPC: xprt = %p, tcp_copied = %lu, tcp_offset = %u, "
"tcp_reclen = %u\n", xprt, transport->tcp_copied,
transport->tcp_offset, transport->tcp_reclen);
if (transport->tcp_copied == req->rq_private_buf.buflen)
transport->tcp_flags &= ~TCP_RCV_COPY_DATA;
else if (transport->tcp_offset == transport->tcp_reclen) {
if (transport->tcp_flags & TCP_RCV_LAST_FRAG)
transport->tcp_flags &= ~TCP_RCV_COPY_DATA;
}
}
static inline int xs_tcp_read_reply(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc)
{
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
struct rpc_rqst *req;
dprintk("RPC: read reply XID %08x\n", ntohl(transport->tcp_xid));
spin_lock(&xprt->transport_lock);
req = xprt_lookup_rqst(xprt, transport->tcp_xid);
if (!req) {
dprintk("RPC: XID %08x request not found!\n",
ntohl(transport->tcp_xid));
spin_unlock(&xprt->transport_lock);
return -1;
}
xs_tcp_read_common(xprt, desc, req);
if (!(transport->tcp_flags & TCP_RCV_COPY_DATA))
xprt_complete_rqst(req->rq_task, transport->tcp_copied);
spin_unlock(&xprt->transport_lock);
return 0;
}
static int xs_tcp_read_callback(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc)
{
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
struct rpc_rqst *req;
spin_lock(&xprt->transport_lock);
req = xprt_lookup_bc_request(xprt, transport->tcp_xid);
if (req == NULL) {
spin_unlock(&xprt->transport_lock);
printk(KERN_WARNING "Callback slot table overflowed\n");
xprt_force_disconnect(xprt);
return -1;
}
dprintk("RPC: read callback XID %08x\n", ntohl(req->rq_xid));
xs_tcp_read_common(xprt, desc, req);
if (!(transport->tcp_flags & TCP_RCV_COPY_DATA))
xprt_complete_bc_request(req, transport->tcp_copied);
spin_unlock(&xprt->transport_lock);
return 0;
}
static inline int _xs_tcp_read_data(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc)
{
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
return (transport->tcp_flags & TCP_RPC_REPLY) ?
xs_tcp_read_reply(xprt, desc) :
xs_tcp_read_callback(xprt, desc);
}
static inline int _xs_tcp_read_data(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc)
{
return xs_tcp_read_reply(xprt, desc);
}
static void xs_tcp_read_data(struct rpc_xprt *xprt,
struct xdr_skb_reader *desc)
{
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
if (_xs_tcp_read_data(xprt, desc) == 0)
xs_tcp_check_fraghdr(transport);
else {
transport->tcp_flags &= ~TCP_RCV_COPY_DATA;
}
}
static inline void xs_tcp_read_discard(struct sock_xprt *transport, struct xdr_skb_reader *desc)
{
size_t len;
len = transport->tcp_reclen - transport->tcp_offset;
if (len > desc->count)
len = desc->count;
desc->count -= len;
desc->offset += len;
transport->tcp_offset += len;
dprintk("RPC: discarded %Zu bytes\n", len);
xs_tcp_check_fraghdr(transport);
}
static int xs_tcp_data_recv(read_descriptor_t *rd_desc, struct sk_buff *skb, unsigned int offset, size_t len)
{
struct rpc_xprt *xprt = rd_desc->arg.data;
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct xdr_skb_reader desc = {
.skb = skb,
.offset = offset,
.count = len,
};
dprintk("RPC: xs_tcp_data_recv started\n");
do {
trace_xs_tcp_data_recv(transport);
if (transport->tcp_flags & TCP_RCV_COPY_FRAGHDR) {
xs_tcp_read_fraghdr(xprt, &desc);
continue;
}
if (transport->tcp_flags & TCP_RCV_COPY_XID) {
xs_tcp_read_xid(transport, &desc);
continue;
}
if (transport->tcp_flags & TCP_RCV_READ_CALLDIR) {
xs_tcp_read_calldir(transport, &desc);
continue;
}
if (transport->tcp_flags & TCP_RCV_COPY_DATA) {
xs_tcp_read_data(xprt, &desc);
continue;
}
xs_tcp_read_discard(transport, &desc);
} while (desc.count);
trace_xs_tcp_data_recv(transport);
dprintk("RPC: xs_tcp_data_recv done\n");
return len - desc.count;
}
static void xs_tcp_data_ready(struct sock *sk)
{
struct rpc_xprt *xprt;
read_descriptor_t rd_desc;
int read;
unsigned long total = 0;
dprintk("RPC: xs_tcp_data_ready...\n");
read_lock_bh(&sk->sk_callback_lock);
if (!(xprt = xprt_from_sock(sk))) {
read = 0;
goto out;
}
if (xprt->reestablish_timeout)
xprt->reestablish_timeout = 0;
rd_desc.arg.data = xprt;
do {
rd_desc.count = 65536;
read = tcp_read_sock(sk, &rd_desc, xs_tcp_data_recv);
if (read > 0)
total += read;
} while (read > 0);
out:
trace_xs_tcp_data_ready(xprt, read, total);
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_tcp_schedule_linger_timeout(struct rpc_xprt *xprt,
unsigned long timeout)
{
struct sock_xprt *transport;
if (xprt_test_and_set_connecting(xprt))
return;
set_bit(XPRT_CONNECTION_ABORT, &xprt->state);
transport = container_of(xprt, struct sock_xprt, xprt);
queue_delayed_work(rpciod_workqueue, &transport->connect_worker,
timeout);
}
static void xs_tcp_cancel_linger_timeout(struct rpc_xprt *xprt)
{
struct sock_xprt *transport;
transport = container_of(xprt, struct sock_xprt, xprt);
if (!test_bit(XPRT_CONNECTION_ABORT, &xprt->state) ||
!cancel_delayed_work(&transport->connect_worker))
return;
clear_bit(XPRT_CONNECTION_ABORT, &xprt->state);
xprt_clear_connecting(xprt);
}
static void xs_sock_reset_connection_flags(struct rpc_xprt *xprt)
{
smp_mb__before_atomic();
clear_bit(XPRT_CONNECTION_ABORT, &xprt->state);
clear_bit(XPRT_CONNECTION_CLOSE, &xprt->state);
clear_bit(XPRT_CLOSE_WAIT, &xprt->state);
clear_bit(XPRT_CLOSING, &xprt->state);
smp_mb__after_atomic();
}
static void xs_sock_mark_closed(struct rpc_xprt *xprt)
{
xs_sock_reset_connection_flags(xprt);
xprt_disconnect_done(xprt);
}
static void xs_tcp_state_change(struct sock *sk)
{
struct rpc_xprt *xprt;
read_lock_bh(&sk->sk_callback_lock);
if (!(xprt = xprt_from_sock(sk)))
goto out;
dprintk("RPC: xs_tcp_state_change client %p...\n", xprt);
dprintk("RPC: state %x conn %d dead %d zapped %d sk_shutdown %d\n",
sk->sk_state, xprt_connected(xprt),
sock_flag(sk, SOCK_DEAD),
sock_flag(sk, SOCK_ZAPPED),
sk->sk_shutdown);
trace_rpc_socket_state_change(xprt, sk->sk_socket);
switch (sk->sk_state) {
case TCP_ESTABLISHED:
spin_lock(&xprt->transport_lock);
if (!xprt_test_and_set_connected(xprt)) {
struct sock_xprt *transport = container_of(xprt,
struct sock_xprt, xprt);
transport->tcp_offset = 0;
transport->tcp_reclen = 0;
transport->tcp_copied = 0;
transport->tcp_flags =
TCP_RCV_COPY_FRAGHDR | TCP_RCV_COPY_XID;
xprt->connect_cookie++;
xprt_wake_pending_tasks(xprt, -EAGAIN);
}
spin_unlock(&xprt->transport_lock);
break;
case TCP_FIN_WAIT1:
xprt->connect_cookie++;
xprt->reestablish_timeout = 0;
set_bit(XPRT_CLOSING, &xprt->state);
smp_mb__before_atomic();
clear_bit(XPRT_CONNECTED, &xprt->state);
clear_bit(XPRT_CLOSE_WAIT, &xprt->state);
smp_mb__after_atomic();
xs_tcp_schedule_linger_timeout(xprt, xs_tcp_fin_timeout);
break;
case TCP_CLOSE_WAIT:
xprt->connect_cookie++;
clear_bit(XPRT_CONNECTED, &xprt->state);
xs_tcp_force_close(xprt);
case TCP_CLOSING:
if (xprt->reestablish_timeout < XS_TCP_INIT_REEST_TO)
xprt->reestablish_timeout = XS_TCP_INIT_REEST_TO;
break;
case TCP_LAST_ACK:
set_bit(XPRT_CLOSING, &xprt->state);
xs_tcp_schedule_linger_timeout(xprt, xs_tcp_fin_timeout);
smp_mb__before_atomic();
clear_bit(XPRT_CONNECTED, &xprt->state);
smp_mb__after_atomic();
break;
case TCP_CLOSE:
xs_tcp_cancel_linger_timeout(xprt);
xs_sock_mark_closed(xprt);
}
out:
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_write_space(struct sock *sk)
{
struct socket *sock;
struct rpc_xprt *xprt;
if (unlikely(!(sock = sk->sk_socket)))
return;
clear_bit(SOCK_NOSPACE, &sock->flags);
if (unlikely(!(xprt = xprt_from_sock(sk))))
return;
if (test_and_clear_bit(SOCK_ASYNC_NOSPACE, &sock->flags) == 0)
return;
xprt_write_space(xprt);
}
static void xs_udp_write_space(struct sock *sk)
{
read_lock_bh(&sk->sk_callback_lock);
if (sock_writeable(sk))
xs_write_space(sk);
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_tcp_write_space(struct sock *sk)
{
read_lock_bh(&sk->sk_callback_lock);
if (sk_stream_is_writeable(sk))
xs_write_space(sk);
read_unlock_bh(&sk->sk_callback_lock);
}
static void xs_udp_do_set_buffer_size(struct rpc_xprt *xprt)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
struct sock *sk = transport->inet;
if (transport->rcvsize) {
sk->sk_userlocks |= SOCK_RCVBUF_LOCK;
sk->sk_rcvbuf = transport->rcvsize * xprt->max_reqs * 2;
}
if (transport->sndsize) {
sk->sk_userlocks |= SOCK_SNDBUF_LOCK;
sk->sk_sndbuf = transport->sndsize * xprt->max_reqs * 2;
sk->sk_write_space(sk);
}
}
static void xs_udp_set_buffer_size(struct rpc_xprt *xprt, size_t sndsize, size_t rcvsize)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
transport->sndsize = 0;
if (sndsize)
transport->sndsize = sndsize + 1024;
transport->rcvsize = 0;
if (rcvsize)
transport->rcvsize = rcvsize + 1024;
xs_udp_do_set_buffer_size(xprt);
}
static void xs_udp_timer(struct rpc_xprt *xprt, struct rpc_task *task)
{
xprt_adjust_cwnd(xprt, task, -ETIMEDOUT);
}
static unsigned short xs_get_random_port(void)
{
unsigned short range = xprt_max_resvport - xprt_min_resvport;
unsigned short rand = (unsigned short) prandom_u32() % range;
return rand + xprt_min_resvport;
}
static void xs_set_port(struct rpc_xprt *xprt, unsigned short port)
{
dprintk("RPC: setting port for xprt %p to %u\n", xprt, port);
rpc_set_port(xs_addr(xprt), port);
xs_update_peer_port(xprt);
}
static unsigned short xs_get_srcport(struct sock_xprt *transport)
{
unsigned short port = transport->srcport;
if (port == 0 && transport->xprt.resvport)
port = xs_get_random_port();
return port;
}
static unsigned short xs_next_srcport(struct sock_xprt *transport, unsigned short port)
{
if (transport->srcport != 0)
transport->srcport = 0;
if (!transport->xprt.resvport)
return 0;
if (port <= xprt_min_resvport || port > xprt_max_resvport)
return xprt_max_resvport;
return --port;
}
static int xs_bind(struct sock_xprt *transport, struct socket *sock)
{
struct sockaddr_storage myaddr;
int err, nloop = 0;
unsigned short port = xs_get_srcport(transport);
unsigned short last;
if (port == 0)
return 0;
memcpy(&myaddr, &transport->srcaddr, transport->xprt.addrlen);
do {
rpc_set_port((struct sockaddr *)&myaddr, port);
err = kernel_bind(sock, (struct sockaddr *)&myaddr,
transport->xprt.addrlen);
if (err == 0) {
transport->srcport = port;
break;
}
last = port;
port = xs_next_srcport(transport, port);
if (port > last)
nloop++;
} while (err == -EADDRINUSE && nloop != 2);
if (myaddr.ss_family == AF_INET)
dprintk("RPC: %s %pI4:%u: %s (%d)\n", __func__,
&((struct sockaddr_in *)&myaddr)->sin_addr,
port, err ? "failed" : "ok", err);
else
dprintk("RPC: %s %pI6:%u: %s (%d)\n", __func__,
&((struct sockaddr_in6 *)&myaddr)->sin6_addr,
port, err ? "failed" : "ok", err);
return err;
}
static void xs_local_rpcbind(struct rpc_task *task)
{
rcu_read_lock();
xprt_set_bound(rcu_dereference(task->tk_client->cl_xprt));
rcu_read_unlock();
}
static void xs_local_set_port(struct rpc_xprt *xprt, unsigned short port)
{
}
static inline void xs_reclassify_socketu(struct socket *sock)
{
struct sock *sk = sock->sk;
sock_lock_init_class_and_name(sk, "slock-AF_LOCAL-RPC",
&xs_slock_key[1], "sk_lock-AF_LOCAL-RPC", &xs_key[1]);
}
static inline void xs_reclassify_socket4(struct socket *sock)
{
struct sock *sk = sock->sk;
sock_lock_init_class_and_name(sk, "slock-AF_INET-RPC",
&xs_slock_key[0], "sk_lock-AF_INET-RPC", &xs_key[0]);
}
static inline void xs_reclassify_socket6(struct socket *sock)
{
struct sock *sk = sock->sk;
sock_lock_init_class_and_name(sk, "slock-AF_INET6-RPC",
&xs_slock_key[1], "sk_lock-AF_INET6-RPC", &xs_key[1]);
}
static inline void xs_reclassify_socket(int family, struct socket *sock)
{
WARN_ON_ONCE(sock_owned_by_user(sock->sk));
if (sock_owned_by_user(sock->sk))
return;
switch (family) {
case AF_LOCAL:
xs_reclassify_socketu(sock);
break;
case AF_INET:
xs_reclassify_socket4(sock);
break;
case AF_INET6:
xs_reclassify_socket6(sock);
break;
}
}
static inline void xs_reclassify_socketu(struct socket *sock)
{
}
static inline void xs_reclassify_socket4(struct socket *sock)
{
}
static inline void xs_reclassify_socket6(struct socket *sock)
{
}
static inline void xs_reclassify_socket(int family, struct socket *sock)
{
}
static void xs_dummy_setup_socket(struct work_struct *work)
{
}
static struct socket *xs_create_sock(struct rpc_xprt *xprt,
struct sock_xprt *transport, int family, int type, int protocol)
{
struct socket *sock;
int err;
err = __sock_create(xprt->xprt_net, family, type, protocol, &sock, 1);
if (err < 0) {
dprintk("RPC: can't create %d transport socket (%d).\n",
protocol, -err);
goto out;
}
xs_reclassify_socket(family, sock);
err = xs_bind(transport, sock);
if (err) {
sock_release(sock);
goto out;
}
return sock;
out:
return ERR_PTR(err);
}
static int xs_local_finish_connecting(struct rpc_xprt *xprt,
struct socket *sock)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt,
xprt);
if (!transport->inet) {
struct sock *sk = sock->sk;
write_lock_bh(&sk->sk_callback_lock);
xs_save_old_callbacks(transport, sk);
sk->sk_user_data = xprt;
sk->sk_data_ready = xs_local_data_ready;
sk->sk_write_space = xs_udp_write_space;
sk->sk_error_report = xs_error_report;
sk->sk_allocation = GFP_ATOMIC;
xprt_clear_connected(xprt);
transport->sock = sock;
transport->inet = sk;
write_unlock_bh(&sk->sk_callback_lock);
}
xprt->stat.connect_count++;
xprt->stat.connect_start = jiffies;
return kernel_connect(sock, xs_addr(xprt), xprt->addrlen, 0);
}
static int xs_local_setup_socket(struct sock_xprt *transport)
{
struct rpc_xprt *xprt = &transport->xprt;
struct socket *sock;
int status = -EIO;
clear_bit(XPRT_CONNECTION_ABORT, &xprt->state);
status = __sock_create(xprt->xprt_net, AF_LOCAL,
SOCK_STREAM, 0, &sock, 1);
if (status < 0) {
dprintk("RPC: can't create AF_LOCAL "
"transport socket (%d).\n", -status);
goto out;
}
xs_reclassify_socketu(sock);
dprintk("RPC: worker connecting xprt %p via AF_LOCAL to %s\n",
xprt, xprt->address_strings[RPC_DISPLAY_ADDR]);
status = xs_local_finish_connecting(xprt, sock);
trace_rpc_socket_connect(xprt, sock, status);
switch (status) {
case 0:
dprintk("RPC: xprt %p connected to %s\n",
xprt, xprt->address_strings[RPC_DISPLAY_ADDR]);
xprt_set_connected(xprt);
case -ENOBUFS:
break;
case -ENOENT:
dprintk("RPC: xprt %p: socket %s does not exist\n",
xprt, xprt->address_strings[RPC_DISPLAY_ADDR]);
break;
case -ECONNREFUSED:
dprintk("RPC: xprt %p: connection refused for %s\n",
xprt, xprt->address_strings[RPC_DISPLAY_ADDR]);
break;
default:
printk(KERN_ERR "%s: unhandled error (%d) connecting to %s\n",
__func__, -status,
xprt->address_strings[RPC_DISPLAY_ADDR]);
}
out:
xprt_clear_connecting(xprt);
xprt_wake_pending_tasks(xprt, status);
return status;
}
static void xs_local_connect(struct rpc_xprt *xprt, struct rpc_task *task)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
int ret;
if (RPC_IS_ASYNC(task)) {
rpc_exit(task, -ENOTCONN);
return;
}
ret = xs_local_setup_socket(transport);
if (ret && !RPC_IS_SOFTCONN(task))
msleep_interruptible(15000);
}
static void xs_set_memalloc(struct rpc_xprt *xprt)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt,
xprt);
if (xprt->swapper)
sk_set_memalloc(transport->inet);
}
int xs_swapper(struct rpc_xprt *xprt, int enable)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt,
xprt);
int err = 0;
if (enable) {
xprt->swapper++;
xs_set_memalloc(xprt);
} else if (xprt->swapper) {
xprt->swapper--;
sk_clear_memalloc(transport->inet);
}
return err;
}
static void xs_set_memalloc(struct rpc_xprt *xprt)
{
}
static void xs_udp_finish_connecting(struct rpc_xprt *xprt, struct socket *sock)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
if (!transport->inet) {
struct sock *sk = sock->sk;
write_lock_bh(&sk->sk_callback_lock);
xs_save_old_callbacks(transport, sk);
sk->sk_user_data = xprt;
sk->sk_data_ready = xs_udp_data_ready;
sk->sk_write_space = xs_udp_write_space;
sk->sk_allocation = GFP_ATOMIC;
xprt_set_connected(xprt);
transport->sock = sock;
transport->inet = sk;
xs_set_memalloc(xprt);
write_unlock_bh(&sk->sk_callback_lock);
}
xs_udp_do_set_buffer_size(xprt);
}
static void xs_udp_setup_socket(struct work_struct *work)
{
struct sock_xprt *transport =
container_of(work, struct sock_xprt, connect_worker.work);
struct rpc_xprt *xprt = &transport->xprt;
struct socket *sock = transport->sock;
int status = -EIO;
xs_reset_transport(transport);
sock = xs_create_sock(xprt, transport,
xs_addr(xprt)->sa_family, SOCK_DGRAM, IPPROTO_UDP);
if (IS_ERR(sock))
goto out;
dprintk("RPC: worker connecting xprt %p via %s to "
"%s (port %s)\n", xprt,
xprt->address_strings[RPC_DISPLAY_PROTO],
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PORT]);
xs_udp_finish_connecting(xprt, sock);
trace_rpc_socket_connect(xprt, sock, 0);
status = 0;
out:
xprt_clear_connecting(xprt);
xprt_wake_pending_tasks(xprt, status);
}
static void xs_abort_connection(struct sock_xprt *transport)
{
int result;
struct sockaddr any;
dprintk("RPC: disconnecting xprt %p to reuse port\n", transport);
memset(&any, 0, sizeof(any));
any.sa_family = AF_UNSPEC;
result = kernel_connect(transport->sock, &any, sizeof(any), 0);
trace_rpc_socket_reset_connection(&transport->xprt,
transport->sock, result);
if (!result)
xs_sock_reset_connection_flags(&transport->xprt);
dprintk("RPC: AF_UNSPEC connect return code %d\n", result);
}
static void xs_tcp_reuse_connection(struct sock_xprt *transport)
{
unsigned int state = transport->inet->sk_state;
if (state == TCP_CLOSE && transport->sock->state == SS_UNCONNECTED) {
if (transport->inet->sk_shutdown == 0)
return;
dprintk("RPC: %s: TCP_CLOSEd and sk_shutdown set to %d\n",
__func__, transport->inet->sk_shutdown);
}
if ((1 << state) & (TCPF_ESTABLISHED|TCPF_SYN_SENT)) {
if (transport->inet->sk_shutdown == 0)
return;
dprintk("RPC: %s: ESTABLISHED/SYN_SENT "
"sk_shutdown set to %d\n",
__func__, transport->inet->sk_shutdown);
}
xs_abort_connection(transport);
}
static int xs_tcp_finish_connecting(struct rpc_xprt *xprt, struct socket *sock)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
int ret = -ENOTCONN;
if (!transport->inet) {
struct sock *sk = sock->sk;
unsigned int keepidle = xprt->timeout->to_initval / HZ;
unsigned int keepcnt = xprt->timeout->to_retries + 1;
unsigned int opt_on = 1;
kernel_setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE,
(char *)&opt_on, sizeof(opt_on));
kernel_setsockopt(sock, SOL_TCP, TCP_KEEPIDLE,
(char *)&keepidle, sizeof(keepidle));
kernel_setsockopt(sock, SOL_TCP, TCP_KEEPINTVL,
(char *)&keepidle, sizeof(keepidle));
kernel_setsockopt(sock, SOL_TCP, TCP_KEEPCNT,
(char *)&keepcnt, sizeof(keepcnt));
write_lock_bh(&sk->sk_callback_lock);
xs_save_old_callbacks(transport, sk);
sk->sk_user_data = xprt;
sk->sk_data_ready = xs_tcp_data_ready;
sk->sk_state_change = xs_tcp_state_change;
sk->sk_write_space = xs_tcp_write_space;
sk->sk_error_report = xs_error_report;
sk->sk_allocation = GFP_ATOMIC;
sk->sk_userlocks |= SOCK_BINDPORT_LOCK;
sock_reset_flag(sk, SOCK_LINGER);
tcp_sk(sk)->linger2 = 0;
tcp_sk(sk)->nonagle |= TCP_NAGLE_OFF;
xprt_clear_connected(xprt);
transport->sock = sock;
transport->inet = sk;
write_unlock_bh(&sk->sk_callback_lock);
}
if (!xprt_bound(xprt))
goto out;
xs_set_memalloc(xprt);
xprt->stat.connect_count++;
xprt->stat.connect_start = jiffies;
ret = kernel_connect(sock, xs_addr(xprt), xprt->addrlen, O_NONBLOCK);
switch (ret) {
case 0:
case -EINPROGRESS:
if (xprt->reestablish_timeout < XS_TCP_INIT_REEST_TO)
xprt->reestablish_timeout = XS_TCP_INIT_REEST_TO;
}
out:
return ret;
}
static void xs_tcp_setup_socket(struct work_struct *work)
{
struct sock_xprt *transport =
container_of(work, struct sock_xprt, connect_worker.work);
struct socket *sock = transport->sock;
struct rpc_xprt *xprt = &transport->xprt;
int status = -EIO;
if (!sock) {
clear_bit(XPRT_CONNECTION_ABORT, &xprt->state);
sock = xs_create_sock(xprt, transport,
xs_addr(xprt)->sa_family, SOCK_STREAM, IPPROTO_TCP);
if (IS_ERR(sock)) {
status = PTR_ERR(sock);
goto out;
}
} else {
int abort_and_exit;
abort_and_exit = test_and_clear_bit(XPRT_CONNECTION_ABORT,
&xprt->state);
set_bit(XPRT_CONNECTION_REUSE, &xprt->state);
xs_tcp_reuse_connection(transport);
clear_bit(XPRT_CONNECTION_REUSE, &xprt->state);
if (abort_and_exit)
goto out_eagain;
}
dprintk("RPC: worker connecting xprt %p via %s to "
"%s (port %s)\n", xprt,
xprt->address_strings[RPC_DISPLAY_PROTO],
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PORT]);
status = xs_tcp_finish_connecting(xprt, sock);
trace_rpc_socket_connect(xprt, sock, status);
dprintk("RPC: %p connect status %d connected %d sock state %d\n",
xprt, -status, xprt_connected(xprt),
sock->sk->sk_state);
switch (status) {
default:
printk("%s: connect returned unhandled error %d\n",
__func__, status);
case -EADDRNOTAVAIL:
xs_tcp_force_close(xprt);
break;
case 0:
case -EINPROGRESS:
case -EALREADY:
xprt_clear_connecting(xprt);
return;
case -EINVAL:
case -ECONNREFUSED:
case -ECONNRESET:
case -ENETUNREACH:
case -ENOBUFS:
goto out;
}
out_eagain:
status = -EAGAIN;
out:
xprt_clear_connecting(xprt);
xprt_wake_pending_tasks(xprt, status);
}
static void xs_connect(struct rpc_xprt *xprt, struct rpc_task *task)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
if (transport->sock != NULL && !RPC_IS_SOFTCONN(task)) {
dprintk("RPC: xs_connect delayed xprt %p for %lu "
"seconds\n",
xprt, xprt->reestablish_timeout / HZ);
queue_delayed_work(rpciod_workqueue,
&transport->connect_worker,
xprt->reestablish_timeout);
xprt->reestablish_timeout <<= 1;
if (xprt->reestablish_timeout < XS_TCP_INIT_REEST_TO)
xprt->reestablish_timeout = XS_TCP_INIT_REEST_TO;
if (xprt->reestablish_timeout > XS_TCP_MAX_REEST_TO)
xprt->reestablish_timeout = XS_TCP_MAX_REEST_TO;
} else {
dprintk("RPC: xs_connect scheduled xprt %p\n", xprt);
queue_delayed_work(rpciod_workqueue,
&transport->connect_worker, 0);
}
}
static void xs_local_print_stats(struct rpc_xprt *xprt, struct seq_file *seq)
{
long idle_time = 0;
if (xprt_connected(xprt))
idle_time = (long)(jiffies - xprt->last_used) / HZ;
seq_printf(seq, "\txprt:\tlocal %lu %lu %lu %ld %lu %lu %lu "
"%llu %llu %lu %llu %llu\n",
xprt->stat.bind_count,
xprt->stat.connect_count,
xprt->stat.connect_time,
idle_time,
xprt->stat.sends,
xprt->stat.recvs,
xprt->stat.bad_xids,
xprt->stat.req_u,
xprt->stat.bklog_u,
xprt->stat.max_slots,
xprt->stat.sending_u,
xprt->stat.pending_u);
}
static void xs_udp_print_stats(struct rpc_xprt *xprt, struct seq_file *seq)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
seq_printf(seq, "\txprt:\tudp %u %lu %lu %lu %lu %llu %llu "
"%lu %llu %llu\n",
transport->srcport,
xprt->stat.bind_count,
xprt->stat.sends,
xprt->stat.recvs,
xprt->stat.bad_xids,
xprt->stat.req_u,
xprt->stat.bklog_u,
xprt->stat.max_slots,
xprt->stat.sending_u,
xprt->stat.pending_u);
}
static void xs_tcp_print_stats(struct rpc_xprt *xprt, struct seq_file *seq)
{
struct sock_xprt *transport = container_of(xprt, struct sock_xprt, xprt);
long idle_time = 0;
if (xprt_connected(xprt))
idle_time = (long)(jiffies - xprt->last_used) / HZ;
seq_printf(seq, "\txprt:\ttcp %u %lu %lu %lu %ld %lu %lu %lu "
"%llu %llu %lu %llu %llu\n",
transport->srcport,
xprt->stat.bind_count,
xprt->stat.connect_count,
xprt->stat.connect_time,
idle_time,
xprt->stat.sends,
xprt->stat.recvs,
xprt->stat.bad_xids,
xprt->stat.req_u,
xprt->stat.bklog_u,
xprt->stat.max_slots,
xprt->stat.sending_u,
xprt->stat.pending_u);
}
static void *bc_malloc(struct rpc_task *task, size_t size)
{
struct page *page;
struct rpc_buffer *buf;
WARN_ON_ONCE(size > PAGE_SIZE - sizeof(struct rpc_buffer));
if (size > PAGE_SIZE - sizeof(struct rpc_buffer))
return NULL;
page = alloc_page(GFP_KERNEL);
if (!page)
return NULL;
buf = page_address(page);
buf->len = PAGE_SIZE;
return buf->data;
}
static void bc_free(void *buffer)
{
struct rpc_buffer *buf;
if (!buffer)
return;
buf = container_of(buffer, struct rpc_buffer, data);
free_page((unsigned long)buf);
}
static int bc_sendto(struct rpc_rqst *req)
{
int len;
struct xdr_buf *xbufp = &req->rq_snd_buf;
struct rpc_xprt *xprt = req->rq_xprt;
struct sock_xprt *transport =
container_of(xprt, struct sock_xprt, xprt);
struct socket *sock = transport->sock;
unsigned long headoff;
unsigned long tailoff;
xs_encode_stream_record_marker(xbufp);
tailoff = (unsigned long)xbufp->tail[0].iov_base & ~PAGE_MASK;
headoff = (unsigned long)xbufp->head[0].iov_base & ~PAGE_MASK;
len = svc_send_common(sock, xbufp,
virt_to_page(xbufp->head[0].iov_base), headoff,
xbufp->tail[0].iov_base, tailoff);
if (len != xbufp->len) {
printk(KERN_NOTICE "Error sending entire callback!\n");
len = -EAGAIN;
}
return len;
}
static int bc_send_request(struct rpc_task *task)
{
struct rpc_rqst *req = task->tk_rqstp;
struct svc_xprt *xprt;
u32 len;
dprintk("sending request with xid: %08x\n", ntohl(req->rq_xid));
xprt = req->rq_xprt->bc_xprt;
if (!mutex_trylock(&xprt->xpt_mutex)) {
rpc_sleep_on(&xprt->xpt_bc_pending, task, NULL);
if (!mutex_trylock(&xprt->xpt_mutex))
return -EAGAIN;
rpc_wake_up_queued_task(&xprt->xpt_bc_pending, task);
}
if (test_bit(XPT_DEAD, &xprt->xpt_flags))
len = -ENOTCONN;
else
len = bc_sendto(req);
mutex_unlock(&xprt->xpt_mutex);
if (len > 0)
len = 0;
return len;
}
static void bc_close(struct rpc_xprt *xprt)
{
}
static void bc_destroy(struct rpc_xprt *xprt)
{
dprintk("RPC: bc_destroy xprt %p\n", xprt);
xs_xprt_free(xprt);
module_put(THIS_MODULE);
}
static int xs_init_anyaddr(const int family, struct sockaddr *sap)
{
static const struct sockaddr_in sin = {
.sin_family = AF_INET,
.sin_addr.s_addr = htonl(INADDR_ANY),
};
static const struct sockaddr_in6 sin6 = {
.sin6_family = AF_INET6,
.sin6_addr = IN6ADDR_ANY_INIT,
};
switch (family) {
case AF_LOCAL:
break;
case AF_INET:
memcpy(sap, &sin, sizeof(sin));
break;
case AF_INET6:
memcpy(sap, &sin6, sizeof(sin6));
break;
default:
dprintk("RPC: %s: Bad address family\n", __func__);
return -EAFNOSUPPORT;
}
return 0;
}
static struct rpc_xprt *xs_setup_xprt(struct xprt_create *args,
unsigned int slot_table_size,
unsigned int max_slot_table_size)
{
struct rpc_xprt *xprt;
struct sock_xprt *new;
if (args->addrlen > sizeof(xprt->addr)) {
dprintk("RPC: xs_setup_xprt: address too large\n");
return ERR_PTR(-EBADF);
}
xprt = xprt_alloc(args->net, sizeof(*new), slot_table_size,
max_slot_table_size);
if (xprt == NULL) {
dprintk("RPC: xs_setup_xprt: couldn't allocate "
"rpc_xprt\n");
return ERR_PTR(-ENOMEM);
}
new = container_of(xprt, struct sock_xprt, xprt);
memcpy(&xprt->addr, args->dstaddr, args->addrlen);
xprt->addrlen = args->addrlen;
if (args->srcaddr)
memcpy(&new->srcaddr, args->srcaddr, args->addrlen);
else {
int err;
err = xs_init_anyaddr(args->dstaddr->sa_family,
(struct sockaddr *)&new->srcaddr);
if (err != 0) {
xprt_free(xprt);
return ERR_PTR(err);
}
}
return xprt;
}
static struct rpc_xprt *xs_setup_local(struct xprt_create *args)
{
struct sockaddr_un *sun = (struct sockaddr_un *)args->dstaddr;
struct sock_xprt *transport;
struct rpc_xprt *xprt;
struct rpc_xprt *ret;
xprt = xs_setup_xprt(args, xprt_tcp_slot_table_entries,
xprt_max_tcp_slot_table_entries);
if (IS_ERR(xprt))
return xprt;
transport = container_of(xprt, struct sock_xprt, xprt);
xprt->prot = 0;
xprt->tsh_size = sizeof(rpc_fraghdr) / sizeof(u32);
xprt->max_payload = RPC_MAX_FRAGMENT_SIZE;
xprt->bind_timeout = XS_BIND_TO;
xprt->reestablish_timeout = XS_TCP_INIT_REEST_TO;
xprt->idle_timeout = XS_IDLE_DISC_TO;
xprt->ops = &xs_local_ops;
xprt->timeout = &xs_local_default_timeout;
INIT_DELAYED_WORK(&transport->connect_worker,
xs_dummy_setup_socket);
switch (sun->sun_family) {
case AF_LOCAL:
if (sun->sun_path[0] != '/') {
dprintk("RPC: bad AF_LOCAL address: %s\n",
sun->sun_path);
ret = ERR_PTR(-EINVAL);
goto out_err;
}
xprt_set_bound(xprt);
xs_format_peer_addresses(xprt, "local", RPCBIND_NETID_LOCAL);
ret = ERR_PTR(xs_local_setup_socket(transport));
if (ret)
goto out_err;
break;
default:
ret = ERR_PTR(-EAFNOSUPPORT);
goto out_err;
}
dprintk("RPC: set up xprt to %s via AF_LOCAL\n",
xprt->address_strings[RPC_DISPLAY_ADDR]);
if (try_module_get(THIS_MODULE))
return xprt;
ret = ERR_PTR(-EINVAL);
out_err:
xs_xprt_free(xprt);
return ret;
}
static struct rpc_xprt *xs_setup_udp(struct xprt_create *args)
{
struct sockaddr *addr = args->dstaddr;
struct rpc_xprt *xprt;
struct sock_xprt *transport;
struct rpc_xprt *ret;
xprt = xs_setup_xprt(args, xprt_udp_slot_table_entries,
xprt_udp_slot_table_entries);
if (IS_ERR(xprt))
return xprt;
transport = container_of(xprt, struct sock_xprt, xprt);
xprt->prot = IPPROTO_UDP;
xprt->tsh_size = 0;
xprt->max_payload = (1U << 16) - (MAX_HEADER << 3);
xprt->bind_timeout = XS_BIND_TO;
xprt->reestablish_timeout = XS_UDP_REEST_TO;
xprt->idle_timeout = XS_IDLE_DISC_TO;
xprt->ops = &xs_udp_ops;
xprt->timeout = &xs_udp_default_timeout;
switch (addr->sa_family) {
case AF_INET:
if (((struct sockaddr_in *)addr)->sin_port != htons(0))
xprt_set_bound(xprt);
INIT_DELAYED_WORK(&transport->connect_worker,
xs_udp_setup_socket);
xs_format_peer_addresses(xprt, "udp", RPCBIND_NETID_UDP);
break;
case AF_INET6:
if (((struct sockaddr_in6 *)addr)->sin6_port != htons(0))
xprt_set_bound(xprt);
INIT_DELAYED_WORK(&transport->connect_worker,
xs_udp_setup_socket);
xs_format_peer_addresses(xprt, "udp", RPCBIND_NETID_UDP6);
break;
default:
ret = ERR_PTR(-EAFNOSUPPORT);
goto out_err;
}
if (xprt_bound(xprt))
dprintk("RPC: set up xprt to %s (port %s) via %s\n",
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PORT],
xprt->address_strings[RPC_DISPLAY_PROTO]);
else
dprintk("RPC: set up xprt to %s (autobind) via %s\n",
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PROTO]);
if (try_module_get(THIS_MODULE))
return xprt;
ret = ERR_PTR(-EINVAL);
out_err:
xs_xprt_free(xprt);
return ret;
}
static struct rpc_xprt *xs_setup_tcp(struct xprt_create *args)
{
struct sockaddr *addr = args->dstaddr;
struct rpc_xprt *xprt;
struct sock_xprt *transport;
struct rpc_xprt *ret;
unsigned int max_slot_table_size = xprt_max_tcp_slot_table_entries;
if (args->flags & XPRT_CREATE_INFINITE_SLOTS)
max_slot_table_size = RPC_MAX_SLOT_TABLE_LIMIT;
xprt = xs_setup_xprt(args, xprt_tcp_slot_table_entries,
max_slot_table_size);
if (IS_ERR(xprt))
return xprt;
transport = container_of(xprt, struct sock_xprt, xprt);
xprt->prot = IPPROTO_TCP;
xprt->tsh_size = sizeof(rpc_fraghdr) / sizeof(u32);
xprt->max_payload = RPC_MAX_FRAGMENT_SIZE;
xprt->bind_timeout = XS_BIND_TO;
xprt->reestablish_timeout = XS_TCP_INIT_REEST_TO;
xprt->idle_timeout = XS_IDLE_DISC_TO;
xprt->ops = &xs_tcp_ops;
xprt->timeout = &xs_tcp_default_timeout;
switch (addr->sa_family) {
case AF_INET:
if (((struct sockaddr_in *)addr)->sin_port != htons(0))
xprt_set_bound(xprt);
INIT_DELAYED_WORK(&transport->connect_worker,
xs_tcp_setup_socket);
xs_format_peer_addresses(xprt, "tcp", RPCBIND_NETID_TCP);
break;
case AF_INET6:
if (((struct sockaddr_in6 *)addr)->sin6_port != htons(0))
xprt_set_bound(xprt);
INIT_DELAYED_WORK(&transport->connect_worker,
xs_tcp_setup_socket);
xs_format_peer_addresses(xprt, "tcp", RPCBIND_NETID_TCP6);
break;
default:
ret = ERR_PTR(-EAFNOSUPPORT);
goto out_err;
}
if (xprt_bound(xprt))
dprintk("RPC: set up xprt to %s (port %s) via %s\n",
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PORT],
xprt->address_strings[RPC_DISPLAY_PROTO]);
else
dprintk("RPC: set up xprt to %s (autobind) via %s\n",
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PROTO]);
if (try_module_get(THIS_MODULE))
return xprt;
ret = ERR_PTR(-EINVAL);
out_err:
xs_xprt_free(xprt);
return ret;
}
static struct rpc_xprt *xs_setup_bc_tcp(struct xprt_create *args)
{
struct sockaddr *addr = args->dstaddr;
struct rpc_xprt *xprt;
struct sock_xprt *transport;
struct svc_sock *bc_sock;
struct rpc_xprt *ret;
xprt = xs_setup_xprt(args, xprt_tcp_slot_table_entries,
xprt_tcp_slot_table_entries);
if (IS_ERR(xprt))
return xprt;
transport = container_of(xprt, struct sock_xprt, xprt);
xprt->prot = IPPROTO_TCP;
xprt->tsh_size = sizeof(rpc_fraghdr) / sizeof(u32);
xprt->max_payload = RPC_MAX_FRAGMENT_SIZE;
xprt->timeout = &xs_tcp_default_timeout;
xprt_set_bound(xprt);
xprt->bind_timeout = 0;
xprt->reestablish_timeout = 0;
xprt->idle_timeout = 0;
xprt->ops = &bc_tcp_ops;
switch (addr->sa_family) {
case AF_INET:
xs_format_peer_addresses(xprt, "tcp",
RPCBIND_NETID_TCP);
break;
case AF_INET6:
xs_format_peer_addresses(xprt, "tcp",
RPCBIND_NETID_TCP6);
break;
default:
ret = ERR_PTR(-EAFNOSUPPORT);
goto out_err;
}
dprintk("RPC: set up xprt to %s (port %s) via %s\n",
xprt->address_strings[RPC_DISPLAY_ADDR],
xprt->address_strings[RPC_DISPLAY_PORT],
xprt->address_strings[RPC_DISPLAY_PROTO]);
xprt_get(xprt);
args->bc_xprt->xpt_bc_xprt = xprt;
xprt->bc_xprt = args->bc_xprt;
bc_sock = container_of(args->bc_xprt, struct svc_sock, sk_xprt);
transport->sock = bc_sock->sk_sock;
transport->inet = bc_sock->sk_sk;
xprt_set_connected(xprt);
if (try_module_get(THIS_MODULE))
return xprt;
args->bc_xprt->xpt_bc_xprt = NULL;
xprt_put(xprt);
ret = ERR_PTR(-EINVAL);
out_err:
xs_xprt_free(xprt);
return ret;
}
int init_socket_xprt(void)
{
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
if (!sunrpc_table_header)
sunrpc_table_header = register_sysctl_table(sunrpc_table);
#endif
xprt_register_transport(&xs_local_transport);
xprt_register_transport(&xs_udp_transport);
xprt_register_transport(&xs_tcp_transport);
xprt_register_transport(&xs_bc_tcp_transport);
return 0;
}
void cleanup_socket_xprt(void)
{
#if IS_ENABLED(CONFIG_SUNRPC_DEBUG)
if (sunrpc_table_header) {
unregister_sysctl_table(sunrpc_table_header);
sunrpc_table_header = NULL;
}
#endif
xprt_unregister_transport(&xs_local_transport);
xprt_unregister_transport(&xs_udp_transport);
xprt_unregister_transport(&xs_tcp_transport);
xprt_unregister_transport(&xs_bc_tcp_transport);
}
static int param_set_uint_minmax(const char *val,
const struct kernel_param *kp,
unsigned int min, unsigned int max)
{
unsigned int num;
int ret;
if (!val)
return -EINVAL;
ret = kstrtouint(val, 0, &num);
if (ret == -EINVAL || num < min || num > max)
return -EINVAL;
*((unsigned int *)kp->arg) = num;
return 0;
}
static int param_set_portnr(const char *val, const struct kernel_param *kp)
{
return param_set_uint_minmax(val, kp,
RPC_MIN_RESVPORT,
RPC_MAX_RESVPORT);
}
static int param_set_slot_table_size(const char *val,
const struct kernel_param *kp)
{
return param_set_uint_minmax(val, kp,
RPC_MIN_SLOT_TABLE,
RPC_MAX_SLOT_TABLE);
}
static int param_set_max_slot_table_size(const char *val,
const struct kernel_param *kp)
{
return param_set_uint_minmax(val, kp,
RPC_MIN_SLOT_TABLE,
RPC_MAX_SLOT_TABLE_LIMIT);
}
