static void svc_reclassify_socket(struct socket *sock)
{
struct sock *sk = sock->sk;
WARN_ON_ONCE(sock_owned_by_user(sk));
if (sock_owned_by_user(sk))
return;
switch (sk->sk_family) {
case AF_INET:
sock_lock_init_class_and_name(sk, "slock-AF_INET-NFSD",
&svc_slock_key[0],
"sk_xprt.xpt_lock-AF_INET-NFSD",
&svc_key[0]);
break;
case AF_INET6:
sock_lock_init_class_and_name(sk, "slock-AF_INET6-NFSD",
&svc_slock_key[1],
"sk_xprt.xpt_lock-AF_INET6-NFSD",
&svc_key[1]);
break;
default:
BUG();
}
}
static void svc_reclassify_socket(struct socket *sock)
{
}
static void svc_release_skb(struct svc_rqst *rqstp)
{
struct sk_buff *skb = rqstp->rq_xprt_ctxt;
if (skb) {
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
rqstp->rq_xprt_ctxt = NULL;
dprintk("svc: service %p, releasing skb %p\n", rqstp, skb);
skb_free_datagram_locked(svsk->sk_sk, skb);
}
}
static void svc_set_cmsg_data(struct svc_rqst *rqstp, struct cmsghdr *cmh)
{
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
switch (svsk->sk_sk->sk_family) {
case AF_INET: {
struct in_pktinfo *pki = CMSG_DATA(cmh);
cmh->cmsg_level = SOL_IP;
cmh->cmsg_type = IP_PKTINFO;
pki->ipi_ifindex = 0;
pki->ipi_spec_dst.s_addr =
svc_daddr_in(rqstp)->sin_addr.s_addr;
cmh->cmsg_len = CMSG_LEN(sizeof(*pki));
}
break;
case AF_INET6: {
struct in6_pktinfo *pki = CMSG_DATA(cmh);
struct sockaddr_in6 *daddr = svc_daddr_in6(rqstp);
cmh->cmsg_level = SOL_IPV6;
cmh->cmsg_type = IPV6_PKTINFO;
pki->ipi6_ifindex = daddr->sin6_scope_id;
pki->ipi6_addr = daddr->sin6_addr;
cmh->cmsg_len = CMSG_LEN(sizeof(*pki));
}
break;
}
}
int svc_send_common(struct socket *sock, struct xdr_buf *xdr,
struct page *headpage, unsigned long headoffset,
struct page *tailpage, unsigned long tailoffset)
{
int result;
int size;
struct page **ppage = xdr->pages;
size_t base = xdr->page_base;
unsigned int pglen = xdr->page_len;
unsigned int flags = MSG_MORE;
int slen;
int len = 0;
slen = xdr->len;
if (slen == xdr->head[0].iov_len)
flags = 0;
len = kernel_sendpage(sock, headpage, headoffset,
xdr->head[0].iov_len, flags);
if (len != xdr->head[0].iov_len)
goto out;
slen -= xdr->head[0].iov_len;
if (slen == 0)
goto out;
size = PAGE_SIZE - base < pglen ? PAGE_SIZE - base : pglen;
while (pglen > 0) {
if (slen == size)
flags = 0;
result = kernel_sendpage(sock, *ppage, base, size, flags);
if (result > 0)
len += result;
if (result != size)
goto out;
slen -= size;
pglen -= size;
size = PAGE_SIZE < pglen ? PAGE_SIZE : pglen;
base = 0;
ppage++;
}
if (xdr->tail[0].iov_len) {
result = kernel_sendpage(sock, tailpage, tailoffset,
xdr->tail[0].iov_len, 0);
if (result > 0)
len += result;
}
out:
return len;
}
static int svc_sendto(struct svc_rqst *rqstp, struct xdr_buf *xdr)
{
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
struct socket *sock = svsk->sk_sock;
union {
struct cmsghdr hdr;
long all[SVC_PKTINFO_SPACE / sizeof(long)];
} buffer;
struct cmsghdr *cmh = &buffer.hdr;
int len = 0;
unsigned long tailoff;
unsigned long headoff;
RPC_IFDEBUG(char buf[RPC_MAX_ADDRBUFLEN]);
if (rqstp->rq_prot == IPPROTO_UDP) {
struct msghdr msg = {
.msg_name = &rqstp->rq_addr,
.msg_namelen = rqstp->rq_addrlen,
.msg_control = cmh,
.msg_controllen = sizeof(buffer),
.msg_flags = MSG_MORE,
};
svc_set_cmsg_data(rqstp, cmh);
if (sock_sendmsg(sock, &msg, 0) < 0)
goto out;
}
tailoff = ((unsigned long)xdr->tail[0].iov_base) & (PAGE_SIZE-1);
headoff = 0;
len = svc_send_common(sock, xdr, rqstp->rq_respages[0], headoff,
rqstp->rq_respages[0], tailoff);
out:
dprintk("svc: socket %p sendto([%p %Zu... ], %d) = %d (addr %s)\n",
svsk, xdr->head[0].iov_base, xdr->head[0].iov_len,
xdr->len, len, svc_print_addr(rqstp, buf, sizeof(buf)));
return len;
}
static int svc_one_sock_name(struct svc_sock *svsk, char *buf, int remaining)
{
const struct sock *sk = svsk->sk_sk;
const char *proto_name = sk->sk_protocol == IPPROTO_UDP ?
"udp" : "tcp";
int len;
switch (sk->sk_family) {
case PF_INET:
len = snprintf(buf, remaining, "ipv4 %s %pI4 %d\n",
proto_name,
&inet_sk(sk)->inet_rcv_saddr,
inet_sk(sk)->inet_num);
break;
#if IS_ENABLED(CONFIG_IPV6)
case PF_INET6:
len = snprintf(buf, remaining, "ipv6 %s %pI6 %d\n",
proto_name,
&sk->sk_v6_rcv_saddr,
inet_sk(sk)->inet_num);
break;
#endif
default:
len = snprintf(buf, remaining, "*unknown-%d*\n",
sk->sk_family);
}
if (len >= remaining) {
*buf = '\0';
return -ENAMETOOLONG;
}
return len;
}
static int svc_recvfrom(struct svc_rqst *rqstp, struct kvec *iov, int nr,
int buflen)
{
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
struct msghdr msg = {
.msg_flags = MSG_DONTWAIT,
};
int len;
rqstp->rq_xprt_hlen = 0;
clear_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
len = kernel_recvmsg(svsk->sk_sock, &msg, iov, nr, buflen,
msg.msg_flags);
if (len == buflen)
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
dprintk("svc: socket %p recvfrom(%p, %Zu) = %d\n",
svsk, iov[0].iov_base, iov[0].iov_len, len);
return len;
}
static int svc_partial_recvfrom(struct svc_rqst *rqstp,
struct kvec *iov, int nr,
int buflen, unsigned int base)
{
size_t save_iovlen;
void *save_iovbase;
unsigned int i;
int ret;
if (base == 0)
return svc_recvfrom(rqstp, iov, nr, buflen);
for (i = 0; i < nr; i++) {
if (iov[i].iov_len > base)
break;
base -= iov[i].iov_len;
}
save_iovlen = iov[i].iov_len;
save_iovbase = iov[i].iov_base;
iov[i].iov_len -= base;
iov[i].iov_base += base;
ret = svc_recvfrom(rqstp, &iov[i], nr - i, buflen);
iov[i].iov_len = save_iovlen;
iov[i].iov_base = save_iovbase;
return ret;
}
static void svc_sock_setbufsize(struct socket *sock, unsigned int snd,
unsigned int rcv)
{
#if 0
mm_segment_t oldfs;
oldfs = get_fs(); set_fs(KERNEL_DS);
sock_setsockopt(sock, SOL_SOCKET, SO_SNDBUF,
(char*)&snd, sizeof(snd));
sock_setsockopt(sock, SOL_SOCKET, SO_RCVBUF,
(char*)&rcv, sizeof(rcv));
#else
lock_sock(sock->sk);
sock->sk->sk_sndbuf = snd * 2;
sock->sk->sk_rcvbuf = rcv * 2;
sock->sk->sk_write_space(sock->sk);
release_sock(sock->sk);
#endif
}
static int svc_sock_secure_port(struct svc_rqst *rqstp)
{
return svc_port_is_privileged(svc_addr(rqstp));
}
static void svc_udp_data_ready(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)sk->sk_user_data;
wait_queue_head_t *wq = sk_sleep(sk);
if (svsk) {
dprintk("svc: socket %p(inet %p), busy=%d\n",
svsk, sk,
test_bit(XPT_BUSY, &svsk->sk_xprt.xpt_flags));
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
svc_xprt_enqueue(&svsk->sk_xprt);
}
if (wq && waitqueue_active(wq))
wake_up_interruptible(wq);
}
static void svc_write_space(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)(sk->sk_user_data);
wait_queue_head_t *wq = sk_sleep(sk);
if (svsk) {
dprintk("svc: socket %p(inet %p), write_space busy=%d\n",
svsk, sk, test_bit(XPT_BUSY, &svsk->sk_xprt.xpt_flags));
svc_xprt_enqueue(&svsk->sk_xprt);
}
if (wq && waitqueue_active(wq)) {
dprintk("RPC svc_write_space: someone sleeping on %p\n",
svsk);
wake_up_interruptible(wq);
}
}
static int svc_tcp_has_wspace(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
struct svc_serv *serv = svsk->sk_xprt.xpt_server;
int required;
if (test_bit(XPT_LISTENER, &xprt->xpt_flags))
return 1;
required = atomic_read(&xprt->xpt_reserved) + serv->sv_max_mesg;
if (sk_stream_wspace(svsk->sk_sk) >= required ||
(sk_stream_min_wspace(svsk->sk_sk) == 0 &&
atomic_read(&xprt->xpt_reserved) == 0))
return 1;
set_bit(SOCK_NOSPACE, &svsk->sk_sock->flags);
return 0;
}
static void svc_tcp_write_space(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)(sk->sk_user_data);
struct socket *sock = sk->sk_socket;
if (!sk_stream_is_writeable(sk) || !sock)
return;
if (!svsk || svc_tcp_has_wspace(&svsk->sk_xprt))
clear_bit(SOCK_NOSPACE, &sock->flags);
svc_write_space(sk);
}
static void svc_tcp_adjust_wspace(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
if (svc_tcp_has_wspace(xprt))
clear_bit(SOCK_NOSPACE, &svsk->sk_sock->flags);
}
static int svc_udp_get_dest_address4(struct svc_rqst *rqstp,
struct cmsghdr *cmh)
{
struct in_pktinfo *pki = CMSG_DATA(cmh);
struct sockaddr_in *daddr = svc_daddr_in(rqstp);
if (cmh->cmsg_type != IP_PKTINFO)
return 0;
daddr->sin_family = AF_INET;
daddr->sin_addr.s_addr = pki->ipi_spec_dst.s_addr;
return 1;
}
static int svc_udp_get_dest_address6(struct svc_rqst *rqstp,
struct cmsghdr *cmh)
{
struct in6_pktinfo *pki = CMSG_DATA(cmh);
struct sockaddr_in6 *daddr = svc_daddr_in6(rqstp);
if (cmh->cmsg_type != IPV6_PKTINFO)
return 0;
daddr->sin6_family = AF_INET6;
daddr->sin6_addr = pki->ipi6_addr;
daddr->sin6_scope_id = pki->ipi6_ifindex;
return 1;
}
static int svc_udp_get_dest_address(struct svc_rqst *rqstp,
struct cmsghdr *cmh)
{
switch (cmh->cmsg_level) {
case SOL_IP:
return svc_udp_get_dest_address4(rqstp, cmh);
case SOL_IPV6:
return svc_udp_get_dest_address6(rqstp, cmh);
}
return 0;
}
static int svc_udp_recvfrom(struct svc_rqst *rqstp)
{
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
struct svc_serv *serv = svsk->sk_xprt.xpt_server;
struct sk_buff *skb;
union {
struct cmsghdr hdr;
long all[SVC_PKTINFO_SPACE / sizeof(long)];
} buffer;
struct cmsghdr *cmh = &buffer.hdr;
struct msghdr msg = {
.msg_name = svc_addr(rqstp),
.msg_control = cmh,
.msg_controllen = sizeof(buffer),
.msg_flags = MSG_DONTWAIT,
};
size_t len;
int err;
if (test_and_clear_bit(XPT_CHNGBUF, &svsk->sk_xprt.xpt_flags))
svc_sock_setbufsize(svsk->sk_sock,
(serv->sv_nrthreads+3) * serv->sv_max_mesg,
(serv->sv_nrthreads+3) * serv->sv_max_mesg);
clear_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
skb = NULL;
err = kernel_recvmsg(svsk->sk_sock, &msg, NULL,
0, 0, MSG_PEEK | MSG_DONTWAIT);
if (err >= 0)
skb = skb_recv_datagram(svsk->sk_sk, 0, 1, &err);
if (skb == NULL) {
if (err != -EAGAIN) {
dprintk("svc: recvfrom returned error %d\n", -err);
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
}
return 0;
}
len = svc_addr_len(svc_addr(rqstp));
rqstp->rq_addrlen = len;
if (skb->tstamp.tv64 == 0) {
skb->tstamp = ktime_get_real();
}
svsk->sk_sk->sk_stamp = skb->tstamp;
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
len = skb->len - sizeof(struct udphdr);
rqstp->rq_arg.len = len;
rqstp->rq_prot = IPPROTO_UDP;
if (!svc_udp_get_dest_address(rqstp, cmh)) {
net_warn_ratelimited("svc: received unknown control message %d/%d; dropping RPC reply datagram\n",
cmh->cmsg_level, cmh->cmsg_type);
goto out_free;
}
rqstp->rq_daddrlen = svc_addr_len(svc_daddr(rqstp));
if (skb_is_nonlinear(skb)) {
local_bh_disable();
if (csum_partial_copy_to_xdr(&rqstp->rq_arg, skb)) {
local_bh_enable();
goto out_free;
}
local_bh_enable();
skb_free_datagram_locked(svsk->sk_sk, skb);
} else {
rqstp->rq_arg.head[0].iov_base = skb->data +
sizeof(struct udphdr);
rqstp->rq_arg.head[0].iov_len = len;
if (skb_checksum_complete(skb))
goto out_free;
rqstp->rq_xprt_ctxt = skb;
}
rqstp->rq_arg.page_base = 0;
if (len <= rqstp->rq_arg.head[0].iov_len) {
rqstp->rq_arg.head[0].iov_len = len;
rqstp->rq_arg.page_len = 0;
rqstp->rq_respages = rqstp->rq_pages+1;
} else {
rqstp->rq_arg.page_len = len - rqstp->rq_arg.head[0].iov_len;
rqstp->rq_respages = rqstp->rq_pages + 1 +
DIV_ROUND_UP(rqstp->rq_arg.page_len, PAGE_SIZE);
}
rqstp->rq_next_page = rqstp->rq_respages+1;
if (serv->sv_stats)
serv->sv_stats->netudpcnt++;
return len;
out_free:
trace_kfree_skb(skb, svc_udp_recvfrom);
skb_free_datagram_locked(svsk->sk_sk, skb);
return 0;
}
static int
svc_udp_sendto(struct svc_rqst *rqstp)
{
int error;
error = svc_sendto(rqstp, &rqstp->rq_res);
if (error == -ECONNREFUSED)
error = svc_sendto(rqstp, &rqstp->rq_res);
return error;
}
static void svc_udp_prep_reply_hdr(struct svc_rqst *rqstp)
{
}
static int svc_udp_has_wspace(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
struct svc_serv *serv = xprt->xpt_server;
unsigned long required;
set_bit(SOCK_NOSPACE, &svsk->sk_sock->flags);
required = atomic_read(&svsk->sk_xprt.xpt_reserved) + serv->sv_max_mesg;
if (required*2 > sock_wspace(svsk->sk_sk))
return 0;
clear_bit(SOCK_NOSPACE, &svsk->sk_sock->flags);
return 1;
}
static struct svc_xprt *svc_udp_accept(struct svc_xprt *xprt)
{
BUG();
return NULL;
}
static struct svc_xprt *svc_udp_create(struct svc_serv *serv,
struct net *net,
struct sockaddr *sa, int salen,
int flags)
{
return svc_create_socket(serv, IPPROTO_UDP, net, sa, salen, flags);
}
static void svc_udp_init(struct svc_sock *svsk, struct svc_serv *serv)
{
int err, level, optname, one = 1;
svc_xprt_init(sock_net(svsk->sk_sock->sk), &svc_udp_class,
&svsk->sk_xprt, serv);
clear_bit(XPT_CACHE_AUTH, &svsk->sk_xprt.xpt_flags);
svsk->sk_sk->sk_data_ready = svc_udp_data_ready;
svsk->sk_sk->sk_write_space = svc_write_space;
svc_sock_setbufsize(svsk->sk_sock,
3 * svsk->sk_xprt.xpt_server->sv_max_mesg,
3 * svsk->sk_xprt.xpt_server->sv_max_mesg);
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
set_bit(XPT_CHNGBUF, &svsk->sk_xprt.xpt_flags);
switch (svsk->sk_sk->sk_family) {
case AF_INET:
level = SOL_IP;
optname = IP_PKTINFO;
break;
case AF_INET6:
level = SOL_IPV6;
optname = IPV6_RECVPKTINFO;
break;
default:
BUG();
}
err = kernel_setsockopt(svsk->sk_sock, level, optname,
(char *)&one, sizeof(one));
dprintk("svc: kernel_setsockopt returned %d\n", err);
}
static void svc_tcp_listen_data_ready(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)sk->sk_user_data;
wait_queue_head_t *wq;
dprintk("svc: socket %p TCP (listen) state change %d\n",
sk, sk->sk_state);
if (sk->sk_state == TCP_LISTEN) {
if (svsk) {
set_bit(XPT_CONN, &svsk->sk_xprt.xpt_flags);
svc_xprt_enqueue(&svsk->sk_xprt);
} else
printk("svc: socket %p: no user data\n", sk);
}
wq = sk_sleep(sk);
if (wq && waitqueue_active(wq))
wake_up_interruptible_all(wq);
}
static void svc_tcp_state_change(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)sk->sk_user_data;
wait_queue_head_t *wq = sk_sleep(sk);
dprintk("svc: socket %p TCP (connected) state change %d (svsk %p)\n",
sk, sk->sk_state, sk->sk_user_data);
if (!svsk)
printk("svc: socket %p: no user data\n", sk);
else {
set_bit(XPT_CLOSE, &svsk->sk_xprt.xpt_flags);
svc_xprt_enqueue(&svsk->sk_xprt);
}
if (wq && waitqueue_active(wq))
wake_up_interruptible_all(wq);
}
static void svc_tcp_data_ready(struct sock *sk)
{
struct svc_sock *svsk = (struct svc_sock *)sk->sk_user_data;
wait_queue_head_t *wq = sk_sleep(sk);
dprintk("svc: socket %p TCP data ready (svsk %p)\n",
sk, sk->sk_user_data);
if (svsk) {
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
svc_xprt_enqueue(&svsk->sk_xprt);
}
if (wq && waitqueue_active(wq))
wake_up_interruptible(wq);
}
static struct svc_xprt *svc_tcp_accept(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
struct sockaddr_storage addr;
struct sockaddr *sin = (struct sockaddr *) &addr;
struct svc_serv *serv = svsk->sk_xprt.xpt_server;
struct socket *sock = svsk->sk_sock;
struct socket *newsock;
struct svc_sock *newsvsk;
int err, slen;
RPC_IFDEBUG(char buf[RPC_MAX_ADDRBUFLEN]);
dprintk("svc: tcp_accept %p sock %p\n", svsk, sock);
if (!sock)
return NULL;
clear_bit(XPT_CONN, &svsk->sk_xprt.xpt_flags);
err = kernel_accept(sock, &newsock, O_NONBLOCK);
if (err < 0) {
if (err == -ENOMEM)
printk(KERN_WARNING "%s: no more sockets!\n",
serv->sv_name);
else if (err != -EAGAIN)
net_warn_ratelimited("%s: accept failed (err %d)!\n",
serv->sv_name, -err);
return NULL;
}
set_bit(XPT_CONN, &svsk->sk_xprt.xpt_flags);
err = kernel_getpeername(newsock, sin, &slen);
if (err < 0) {
net_warn_ratelimited("%s: peername failed (err %d)!\n",
serv->sv_name, -err);
goto failed;
}
if (!svc_port_is_privileged(sin)) {
dprintk("%s: connect from unprivileged port: %s\n",
serv->sv_name,
__svc_print_addr(sin, buf, sizeof(buf)));
}
dprintk("%s: connect from %s\n", serv->sv_name,
__svc_print_addr(sin, buf, sizeof(buf)));
newsock->sk->sk_sndtimeo = HZ*30;
newsvsk = svc_setup_socket(serv, newsock,
(SVC_SOCK_ANONYMOUS | SVC_SOCK_TEMPORARY));
if (IS_ERR(newsvsk))
goto failed;
svc_xprt_set_remote(&newsvsk->sk_xprt, sin, slen);
err = kernel_getsockname(newsock, sin, &slen);
if (unlikely(err < 0)) {
dprintk("svc_tcp_accept: kernel_getsockname error %d\n", -err);
slen = offsetof(struct sockaddr, sa_data);
}
svc_xprt_set_local(&newsvsk->sk_xprt, sin, slen);
if (sock_is_loopback(newsock->sk))
set_bit(XPT_LOCAL, &newsvsk->sk_xprt.xpt_flags);
else
clear_bit(XPT_LOCAL, &newsvsk->sk_xprt.xpt_flags);
if (serv->sv_stats)
serv->sv_stats->nettcpconn++;
return &newsvsk->sk_xprt;
failed:
sock_release(newsock);
return NULL;
}
static unsigned int svc_tcp_restore_pages(struct svc_sock *svsk, struct svc_rqst *rqstp)
{
unsigned int i, len, npages;
if (svsk->sk_datalen == 0)
return 0;
len = svsk->sk_datalen;
npages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
if (rqstp->rq_pages[i] != NULL)
put_page(rqstp->rq_pages[i]);
BUG_ON(svsk->sk_pages[i] == NULL);
rqstp->rq_pages[i] = svsk->sk_pages[i];
svsk->sk_pages[i] = NULL;
}
rqstp->rq_arg.head[0].iov_base = page_address(rqstp->rq_pages[0]);
return len;
}
static void svc_tcp_save_pages(struct svc_sock *svsk, struct svc_rqst *rqstp)
{
unsigned int i, len, npages;
if (svsk->sk_datalen == 0)
return;
len = svsk->sk_datalen;
npages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
svsk->sk_pages[i] = rqstp->rq_pages[i];
rqstp->rq_pages[i] = NULL;
}
}
static void svc_tcp_clear_pages(struct svc_sock *svsk)
{
unsigned int i, len, npages;
if (svsk->sk_datalen == 0)
goto out;
len = svsk->sk_datalen;
npages = (len + PAGE_SIZE - 1) >> PAGE_SHIFT;
for (i = 0; i < npages; i++) {
if (svsk->sk_pages[i] == NULL) {
WARN_ON_ONCE(1);
continue;
}
put_page(svsk->sk_pages[i]);
svsk->sk_pages[i] = NULL;
}
out:
svsk->sk_tcplen = 0;
svsk->sk_datalen = 0;
}
static int svc_tcp_recv_record(struct svc_sock *svsk, struct svc_rqst *rqstp)
{
struct svc_serv *serv = svsk->sk_xprt.xpt_server;
unsigned int want;
int len;
if (svsk->sk_tcplen < sizeof(rpc_fraghdr)) {
struct kvec iov;
want = sizeof(rpc_fraghdr) - svsk->sk_tcplen;
iov.iov_base = ((char *) &svsk->sk_reclen) + svsk->sk_tcplen;
iov.iov_len = want;
if ((len = svc_recvfrom(rqstp, &iov, 1, want)) < 0)
goto error;
svsk->sk_tcplen += len;
if (len < want) {
dprintk("svc: short recvfrom while reading record "
"length (%d of %d)\n", len, want);
return -EAGAIN;
}
dprintk("svc: TCP record, %d bytes\n", svc_sock_reclen(svsk));
if (svc_sock_reclen(svsk) + svsk->sk_datalen >
serv->sv_max_mesg) {
net_notice_ratelimited("RPC: fragment too large: %d\n",
svc_sock_reclen(svsk));
goto err_delete;
}
}
return svc_sock_reclen(svsk);
error:
dprintk("RPC: TCP recv_record got %d\n", len);
return len;
err_delete:
set_bit(XPT_CLOSE, &svsk->sk_xprt.xpt_flags);
return -EAGAIN;
}
static int receive_cb_reply(struct svc_sock *svsk, struct svc_rqst *rqstp)
{
struct rpc_xprt *bc_xprt = svsk->sk_xprt.xpt_bc_xprt;
struct rpc_rqst *req = NULL;
struct kvec *src, *dst;
__be32 *p = (__be32 *)rqstp->rq_arg.head[0].iov_base;
__be32 xid;
__be32 calldir;
xid = *p++;
calldir = *p;
if (!bc_xprt)
return -EAGAIN;
spin_lock_bh(&bc_xprt->transport_lock);
req = xprt_lookup_rqst(bc_xprt, xid);
if (!req)
goto unlock_notfound;
memcpy(&req->rq_private_buf, &req->rq_rcv_buf, sizeof(struct xdr_buf));
dst = &req->rq_private_buf.head[0];
src = &rqstp->rq_arg.head[0];
if (dst->iov_len < src->iov_len)
goto unlock_eagain;
memcpy(dst->iov_base, src->iov_base, src->iov_len);
xprt_complete_rqst(req->rq_task, rqstp->rq_arg.len);
rqstp->rq_arg.len = 0;
spin_unlock_bh(&bc_xprt->transport_lock);
return 0;
unlock_notfound:
printk(KERN_NOTICE
"%s: Got unrecognized reply: "
"calldir 0x%x xpt_bc_xprt %p xid %08x\n",
__func__, ntohl(calldir),
bc_xprt, ntohl(xid));
unlock_eagain:
spin_unlock_bh(&bc_xprt->transport_lock);
return -EAGAIN;
}
static int copy_pages_to_kvecs(struct kvec *vec, struct page **pages, int len)
{
int i = 0;
int t = 0;
while (t < len) {
vec[i].iov_base = page_address(pages[i]);
vec[i].iov_len = PAGE_SIZE;
i++;
t += PAGE_SIZE;
}
return i;
}
static void svc_tcp_fragment_received(struct svc_sock *svsk)
{
dprintk("svc: TCP %s record (%d bytes)\n",
svc_sock_final_rec(svsk) ? "final" : "nonfinal",
svc_sock_reclen(svsk));
svsk->sk_tcplen = 0;
svsk->sk_reclen = 0;
}
static int svc_tcp_recvfrom(struct svc_rqst *rqstp)
{
struct svc_sock *svsk =
container_of(rqstp->rq_xprt, struct svc_sock, sk_xprt);
struct svc_serv *serv = svsk->sk_xprt.xpt_server;
int len;
struct kvec *vec;
unsigned int want, base;
__be32 *p;
__be32 calldir;
int pnum;
dprintk("svc: tcp_recv %p data %d conn %d close %d\n",
svsk, test_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags),
test_bit(XPT_CONN, &svsk->sk_xprt.xpt_flags),
test_bit(XPT_CLOSE, &svsk->sk_xprt.xpt_flags));
len = svc_tcp_recv_record(svsk, rqstp);
if (len < 0)
goto error;
base = svc_tcp_restore_pages(svsk, rqstp);
want = svc_sock_reclen(svsk) - (svsk->sk_tcplen - sizeof(rpc_fraghdr));
vec = rqstp->rq_vec;
pnum = copy_pages_to_kvecs(&vec[0], &rqstp->rq_pages[0],
svsk->sk_datalen + want);
rqstp->rq_respages = &rqstp->rq_pages[pnum];
rqstp->rq_next_page = rqstp->rq_respages + 1;
len = svc_partial_recvfrom(rqstp, vec, pnum, want, base);
if (len >= 0) {
svsk->sk_tcplen += len;
svsk->sk_datalen += len;
}
if (len != want || !svc_sock_final_rec(svsk)) {
svc_tcp_save_pages(svsk, rqstp);
if (len < 0 && len != -EAGAIN)
goto err_delete;
if (len == want)
svc_tcp_fragment_received(svsk);
else
dprintk("svc: incomplete TCP record (%d of %d)\n",
(int)(svsk->sk_tcplen - sizeof(rpc_fraghdr)),
svc_sock_reclen(svsk));
goto err_noclose;
}
if (svsk->sk_datalen < 8) {
svsk->sk_datalen = 0;
goto err_delete;
}
rqstp->rq_arg.len = svsk->sk_datalen;
rqstp->rq_arg.page_base = 0;
if (rqstp->rq_arg.len <= rqstp->rq_arg.head[0].iov_len) {
rqstp->rq_arg.head[0].iov_len = rqstp->rq_arg.len;
rqstp->rq_arg.page_len = 0;
} else
rqstp->rq_arg.page_len = rqstp->rq_arg.len - rqstp->rq_arg.head[0].iov_len;
rqstp->rq_xprt_ctxt = NULL;
rqstp->rq_prot = IPPROTO_TCP;
if (test_bit(XPT_LOCAL, &svsk->sk_xprt.xpt_flags))
set_bit(RQ_LOCAL, &rqstp->rq_flags);
else
clear_bit(RQ_LOCAL, &rqstp->rq_flags);
p = (__be32 *)rqstp->rq_arg.head[0].iov_base;
calldir = p[1];
if (calldir)
len = receive_cb_reply(svsk, rqstp);
svsk->sk_datalen = 0;
svc_tcp_fragment_received(svsk);
if (len < 0)
goto error;
svc_xprt_copy_addrs(rqstp, &svsk->sk_xprt);
if (serv->sv_stats)
serv->sv_stats->nettcpcnt++;
return rqstp->rq_arg.len;
error:
if (len != -EAGAIN)
goto err_delete;
dprintk("RPC: TCP recvfrom got EAGAIN\n");
return 0;
err_delete:
printk(KERN_NOTICE "%s: recvfrom returned errno %d\n",
svsk->sk_xprt.xpt_server->sv_name, -len);
set_bit(XPT_CLOSE, &svsk->sk_xprt.xpt_flags);
err_noclose:
return 0;
}
static int svc_tcp_sendto(struct svc_rqst *rqstp)
{
struct xdr_buf *xbufp = &rqstp->rq_res;
int sent;
__be32 reclen;
reclen = htonl(0x80000000|((xbufp->len ) - 4));
memcpy(xbufp->head[0].iov_base, &reclen, 4);
sent = svc_sendto(rqstp, &rqstp->rq_res);
if (sent != xbufp->len) {
printk(KERN_NOTICE
"rpc-srv/tcp: %s: %s %d when sending %d bytes "
"- shutting down socket\n",
rqstp->rq_xprt->xpt_server->sv_name,
(sent<0)?"got error":"sent only",
sent, xbufp->len);
set_bit(XPT_CLOSE, &rqstp->rq_xprt->xpt_flags);
svc_xprt_enqueue(rqstp->rq_xprt);
sent = -EAGAIN;
}
return sent;
}
static void svc_tcp_prep_reply_hdr(struct svc_rqst *rqstp)
{
struct kvec *resv = &rqstp->rq_res.head[0];
svc_putnl(resv, 0);
}
static struct svc_xprt *svc_tcp_create(struct svc_serv *serv,
struct net *net,
struct sockaddr *sa, int salen,
int flags)
{
return svc_create_socket(serv, IPPROTO_TCP, net, sa, salen, flags);
}
static struct svc_xprt *svc_bc_tcp_create(struct svc_serv *serv,
struct net *net,
struct sockaddr *sa, int salen,
int flags)
{
return svc_bc_create_socket(serv, IPPROTO_TCP, net, sa, salen, flags);
}
static void svc_bc_tcp_sock_detach(struct svc_xprt *xprt)
{
}
static void svc_init_bc_xprt_sock(void)
{
svc_reg_xprt_class(&svc_tcp_bc_class);
}
static void svc_cleanup_bc_xprt_sock(void)
{
svc_unreg_xprt_class(&svc_tcp_bc_class);
}
static void svc_init_bc_xprt_sock(void)
{
}
static void svc_cleanup_bc_xprt_sock(void)
{
}
void svc_init_xprt_sock(void)
{
svc_reg_xprt_class(&svc_tcp_class);
svc_reg_xprt_class(&svc_udp_class);
svc_init_bc_xprt_sock();
}
void svc_cleanup_xprt_sock(void)
{
svc_unreg_xprt_class(&svc_tcp_class);
svc_unreg_xprt_class(&svc_udp_class);
svc_cleanup_bc_xprt_sock();
}
static void svc_tcp_init(struct svc_sock *svsk, struct svc_serv *serv)
{
struct sock *sk = svsk->sk_sk;
svc_xprt_init(sock_net(svsk->sk_sock->sk), &svc_tcp_class,
&svsk->sk_xprt, serv);
set_bit(XPT_CACHE_AUTH, &svsk->sk_xprt.xpt_flags);
if (sk->sk_state == TCP_LISTEN) {
dprintk("setting up TCP socket for listening\n");
set_bit(XPT_LISTENER, &svsk->sk_xprt.xpt_flags);
sk->sk_data_ready = svc_tcp_listen_data_ready;
set_bit(XPT_CONN, &svsk->sk_xprt.xpt_flags);
} else {
dprintk("setting up TCP socket for reading\n");
sk->sk_state_change = svc_tcp_state_change;
sk->sk_data_ready = svc_tcp_data_ready;
sk->sk_write_space = svc_tcp_write_space;
svsk->sk_reclen = 0;
svsk->sk_tcplen = 0;
svsk->sk_datalen = 0;
memset(&svsk->sk_pages[0], 0, sizeof(svsk->sk_pages));
tcp_sk(sk)->nonagle |= TCP_NAGLE_OFF;
set_bit(XPT_DATA, &svsk->sk_xprt.xpt_flags);
if (sk->sk_state != TCP_ESTABLISHED)
set_bit(XPT_CLOSE, &svsk->sk_xprt.xpt_flags);
}
}
void svc_sock_update_bufs(struct svc_serv *serv)
{
struct svc_sock *svsk;
spin_lock_bh(&serv->sv_lock);
list_for_each_entry(svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
set_bit(XPT_CHNGBUF, &svsk->sk_xprt.xpt_flags);
spin_unlock_bh(&serv->sv_lock);
}
static struct svc_sock *svc_setup_socket(struct svc_serv *serv,
struct socket *sock,
int flags)
{
struct svc_sock *svsk;
struct sock *inet;
int pmap_register = !(flags & SVC_SOCK_ANONYMOUS);
int err = 0;
dprintk("svc: svc_setup_socket %p\n", sock);
svsk = kzalloc(sizeof(*svsk), GFP_KERNEL);
if (!svsk)
return ERR_PTR(-ENOMEM);
inet = sock->sk;
if (pmap_register)
err = svc_register(serv, sock_net(sock->sk), inet->sk_family,
inet->sk_protocol,
ntohs(inet_sk(inet)->inet_sport));
if (err < 0) {
kfree(svsk);
return ERR_PTR(err);
}
inet->sk_user_data = svsk;
svsk->sk_sock = sock;
svsk->sk_sk = inet;
svsk->sk_ostate = inet->sk_state_change;
svsk->sk_odata = inet->sk_data_ready;
svsk->sk_owspace = inet->sk_write_space;
if (sock->type == SOCK_DGRAM)
svc_udp_init(svsk, serv);
else {
svc_sock_setbufsize(svsk->sk_sock, 4 * serv->sv_max_mesg,
4 * serv->sv_max_mesg);
svc_tcp_init(svsk, serv);
}
dprintk("svc: svc_setup_socket created %p (inet %p)\n",
svsk, svsk->sk_sk);
return svsk;
}
bool svc_alien_sock(struct net *net, int fd)
{
int err;
struct socket *sock = sockfd_lookup(fd, &err);
bool ret = false;
if (!sock)
goto out;
if (sock_net(sock->sk) != net)
ret = true;
sockfd_put(sock);
out:
return ret;
}
int svc_addsock(struct svc_serv *serv, const int fd, char *name_return,
const size_t len)
{
int err = 0;
struct socket *so = sockfd_lookup(fd, &err);
struct svc_sock *svsk = NULL;
struct sockaddr_storage addr;
struct sockaddr *sin = (struct sockaddr *)&addr;
int salen;
if (!so)
return err;
err = -EAFNOSUPPORT;
if ((so->sk->sk_family != PF_INET) && (so->sk->sk_family != PF_INET6))
goto out;
err = -EPROTONOSUPPORT;
if (so->sk->sk_protocol != IPPROTO_TCP &&
so->sk->sk_protocol != IPPROTO_UDP)
goto out;
err = -EISCONN;
if (so->state > SS_UNCONNECTED)
goto out;
err = -ENOENT;
if (!try_module_get(THIS_MODULE))
goto out;
svsk = svc_setup_socket(serv, so, SVC_SOCK_DEFAULTS);
if (IS_ERR(svsk)) {
module_put(THIS_MODULE);
err = PTR_ERR(svsk);
goto out;
}
if (kernel_getsockname(svsk->sk_sock, sin, &salen) == 0)
svc_xprt_set_local(&svsk->sk_xprt, sin, salen);
svc_add_new_perm_xprt(serv, &svsk->sk_xprt);
return svc_one_sock_name(svsk, name_return, len);
out:
sockfd_put(so);
return err;
}
static struct svc_xprt *svc_create_socket(struct svc_serv *serv,
int protocol,
struct net *net,
struct sockaddr *sin, int len,
int flags)
{
struct svc_sock *svsk;
struct socket *sock;
int error;
int type;
struct sockaddr_storage addr;
struct sockaddr *newsin = (struct sockaddr *)&addr;
int newlen;
int family;
int val;
RPC_IFDEBUG(char buf[RPC_MAX_ADDRBUFLEN]);
dprintk("svc: svc_create_socket(%s, %d, %s)\n",
serv->sv_program->pg_name, protocol,
__svc_print_addr(sin, buf, sizeof(buf)));
if (protocol != IPPROTO_UDP && protocol != IPPROTO_TCP) {
printk(KERN_WARNING "svc: only UDP and TCP "
"sockets supported\n");
return ERR_PTR(-EINVAL);
}
type = (protocol == IPPROTO_UDP)? SOCK_DGRAM : SOCK_STREAM;
switch (sin->sa_family) {
case AF_INET6:
family = PF_INET6;
break;
case AF_INET:
family = PF_INET;
break;
default:
return ERR_PTR(-EINVAL);
}
error = __sock_create(net, family, type, protocol, &sock, 1);
if (error < 0)
return ERR_PTR(error);
svc_reclassify_socket(sock);
val = 1;
if (family == PF_INET6)
kernel_setsockopt(sock, SOL_IPV6, IPV6_V6ONLY,
(char *)&val, sizeof(val));
if (type == SOCK_STREAM)
sock->sk->sk_reuse = SK_CAN_REUSE;
error = kernel_bind(sock, sin, len);
if (error < 0)
goto bummer;
newlen = len;
error = kernel_getsockname(sock, newsin, &newlen);
if (error < 0)
goto bummer;
if (protocol == IPPROTO_TCP) {
if ((error = kernel_listen(sock, 64)) < 0)
goto bummer;
}
svsk = svc_setup_socket(serv, sock, flags);
if (IS_ERR(svsk)) {
error = PTR_ERR(svsk);
goto bummer;
}
svc_xprt_set_local(&svsk->sk_xprt, newsin, newlen);
return (struct svc_xprt *)svsk;
bummer:
dprintk("svc: svc_create_socket error = %d\n", -error);
sock_release(sock);
return ERR_PTR(error);
}
static void svc_sock_detach(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
struct sock *sk = svsk->sk_sk;
wait_queue_head_t *wq;
dprintk("svc: svc_sock_detach(%p)\n", svsk);
sk->sk_state_change = svsk->sk_ostate;
sk->sk_data_ready = svsk->sk_odata;
sk->sk_write_space = svsk->sk_owspace;
wq = sk_sleep(sk);
if (wq && waitqueue_active(wq))
wake_up_interruptible(wq);
}
static void svc_tcp_sock_detach(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
dprintk("svc: svc_tcp_sock_detach(%p)\n", svsk);
svc_sock_detach(xprt);
if (!test_bit(XPT_LISTENER, &xprt->xpt_flags)) {
svc_tcp_clear_pages(svsk);
kernel_sock_shutdown(svsk->sk_sock, SHUT_RDWR);
}
}
static void svc_sock_free(struct svc_xprt *xprt)
{
struct svc_sock *svsk = container_of(xprt, struct svc_sock, sk_xprt);
dprintk("svc: svc_sock_free(%p)\n", svsk);
if (svsk->sk_sock->file)
sockfd_put(svsk->sk_sock);
else
sock_release(svsk->sk_sock);
kfree(svsk);
}
static struct svc_xprt *svc_bc_create_socket(struct svc_serv *serv,
int protocol,
struct net *net,
struct sockaddr *sin, int len,
int flags)
{
struct svc_sock *svsk;
struct svc_xprt *xprt;
if (protocol != IPPROTO_TCP) {
printk(KERN_WARNING "svc: only TCP sockets"
" supported on shared back channel\n");
return ERR_PTR(-EINVAL);
}
svsk = kzalloc(sizeof(*svsk), GFP_KERNEL);
if (!svsk)
return ERR_PTR(-ENOMEM);
xprt = &svsk->sk_xprt;
svc_xprt_init(net, &svc_tcp_bc_class, xprt, serv);
serv->sv_bc_xprt = xprt;
return xprt;
}
static void svc_bc_sock_free(struct svc_xprt *xprt)
{
if (xprt)
kfree(container_of(xprt, struct svc_sock, sk_xprt));
}
