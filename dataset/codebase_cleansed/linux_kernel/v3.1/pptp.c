static struct pppox_sock *lookup_chan(u16 call_id, __be32 s_addr)
{
struct pppox_sock *sock;
struct pptp_opt *opt;
rcu_read_lock();
sock = rcu_dereference(callid_sock[call_id]);
if (sock) {
opt = &sock->proto.pptp;
if (opt->dst_addr.sin_addr.s_addr != s_addr)
sock = NULL;
else
sock_hold(sk_pppox(sock));
}
rcu_read_unlock();
return sock;
}
static int lookup_chan_dst(u16 call_id, __be32 d_addr)
{
struct pppox_sock *sock;
struct pptp_opt *opt;
int i;
rcu_read_lock();
for (i = find_next_bit(callid_bitmap, MAX_CALLID, 1); i < MAX_CALLID;
i = find_next_bit(callid_bitmap, MAX_CALLID, i + 1)) {
sock = rcu_dereference(callid_sock[i]);
if (!sock)
continue;
opt = &sock->proto.pptp;
if (opt->dst_addr.call_id == call_id &&
opt->dst_addr.sin_addr.s_addr == d_addr)
break;
}
rcu_read_unlock();
return i < MAX_CALLID;
}
static int add_chan(struct pppox_sock *sock)
{
static int call_id;
spin_lock(&chan_lock);
if (!sock->proto.pptp.src_addr.call_id) {
call_id = find_next_zero_bit(callid_bitmap, MAX_CALLID, call_id + 1);
if (call_id == MAX_CALLID) {
call_id = find_next_zero_bit(callid_bitmap, MAX_CALLID, 1);
if (call_id == MAX_CALLID)
goto out_err;
}
sock->proto.pptp.src_addr.call_id = call_id;
} else if (test_bit(sock->proto.pptp.src_addr.call_id, callid_bitmap))
goto out_err;
set_bit(sock->proto.pptp.src_addr.call_id, callid_bitmap);
rcu_assign_pointer(callid_sock[sock->proto.pptp.src_addr.call_id], sock);
spin_unlock(&chan_lock);
return 0;
out_err:
spin_unlock(&chan_lock);
return -1;
}
static void del_chan(struct pppox_sock *sock)
{
spin_lock(&chan_lock);
clear_bit(sock->proto.pptp.src_addr.call_id, callid_bitmap);
rcu_assign_pointer(callid_sock[sock->proto.pptp.src_addr.call_id], NULL);
spin_unlock(&chan_lock);
synchronize_rcu();
}
static int pptp_xmit(struct ppp_channel *chan, struct sk_buff *skb)
{
struct sock *sk = (struct sock *) chan->private;
struct pppox_sock *po = pppox_sk(sk);
struct pptp_opt *opt = &po->proto.pptp;
struct pptp_gre_header *hdr;
unsigned int header_len = sizeof(*hdr);
struct flowi4 fl4;
int islcp;
int len;
unsigned char *data;
__u32 seq_recv;
struct rtable *rt;
struct net_device *tdev;
struct iphdr *iph;
int max_headroom;
if (sk_pppox(po)->sk_state & PPPOX_DEAD)
goto tx_error;
rt = ip_route_output_ports(&init_net, &fl4, NULL,
opt->dst_addr.sin_addr.s_addr,
opt->src_addr.sin_addr.s_addr,
0, 0, IPPROTO_GRE,
RT_TOS(0), 0);
if (IS_ERR(rt))
goto tx_error;
tdev = rt->dst.dev;
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(*iph) + sizeof(*hdr) + 2;
if (skb_headroom(skb) < max_headroom || skb_cloned(skb) || skb_shared(skb)) {
struct sk_buff *new_skb = skb_realloc_headroom(skb, max_headroom);
if (!new_skb) {
ip_rt_put(rt);
goto tx_error;
}
if (skb->sk)
skb_set_owner_w(new_skb, skb->sk);
kfree_skb(skb);
skb = new_skb;
}
data = skb->data;
islcp = ((data[0] << 8) + data[1]) == PPP_LCP && 1 <= data[2] && data[2] <= 7;
if ((opt->ppp_flags & SC_COMP_PROT) && data[0] == 0 && !islcp)
skb_pull(skb, 1);
if ((opt->ppp_flags & SC_COMP_AC) == 0 || islcp) {
data = skb_push(skb, 2);
data[0] = PPP_ALLSTATIONS;
data[1] = PPP_UI;
}
len = skb->len;
seq_recv = opt->seq_recv;
if (opt->ack_sent == seq_recv)
header_len -= sizeof(hdr->ack);
skb_push(skb, header_len);
hdr = (struct pptp_gre_header *)(skb->data);
hdr->flags = PPTP_GRE_FLAG_K;
hdr->ver = PPTP_GRE_VER;
hdr->protocol = htons(PPTP_GRE_PROTO);
hdr->call_id = htons(opt->dst_addr.call_id);
hdr->flags |= PPTP_GRE_FLAG_S;
hdr->seq = htonl(++opt->seq_sent);
if (opt->ack_sent != seq_recv) {
hdr->ver |= PPTP_GRE_FLAG_A;
hdr->ack = htonl(seq_recv);
opt->ack_sent = seq_recv;
}
hdr->payload_len = htons(len);
skb_reset_transport_header(skb);
skb_push(skb, sizeof(*iph));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
IPCB(skb)->flags &= ~(IPSKB_XFRM_TUNNEL_SIZE | IPSKB_XFRM_TRANSFORMED | IPSKB_REROUTED);
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr) >> 2;
if (ip_dont_fragment(sk, &rt->dst))
iph->frag_off = htons(IP_DF);
else
iph->frag_off = 0;
iph->protocol = IPPROTO_GRE;
iph->tos = 0;
iph->daddr = fl4.daddr;
iph->saddr = fl4.saddr;
iph->ttl = ip4_dst_hoplimit(&rt->dst);
iph->tot_len = htons(skb->len);
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
nf_reset(skb);
skb->ip_summed = CHECKSUM_NONE;
ip_select_ident(iph, &rt->dst, NULL);
ip_send_check(iph);
ip_local_out(skb);
return 1;
tx_error:
kfree_skb(skb);
return 1;
}
static int pptp_rcv_core(struct sock *sk, struct sk_buff *skb)
{
struct pppox_sock *po = pppox_sk(sk);
struct pptp_opt *opt = &po->proto.pptp;
int headersize, payload_len, seq;
__u8 *payload;
struct pptp_gre_header *header;
if (!(sk->sk_state & PPPOX_CONNECTED)) {
if (sock_queue_rcv_skb(sk, skb))
goto drop;
return NET_RX_SUCCESS;
}
header = (struct pptp_gre_header *)(skb->data);
headersize = sizeof(*header);
if (PPTP_GRE_IS_A(header->ver)) {
__u32 ack;
if (!pskb_may_pull(skb, headersize))
goto drop;
header = (struct pptp_gre_header *)(skb->data);
ack = PPTP_GRE_IS_S(header->flags) ? header->ack : header->seq;
ack = ntohl(ack);
if (ack > opt->ack_recv)
opt->ack_recv = ack;
if (WRAPPED(ack, opt->ack_recv))
opt->ack_recv = ack;
} else {
headersize -= sizeof(header->ack);
}
if (!PPTP_GRE_IS_S(header->flags))
goto drop;
payload_len = ntohs(header->payload_len);
seq = ntohl(header->seq);
if (!pskb_may_pull(skb, headersize + payload_len))
goto drop;
payload = skb->data + headersize;
if (seq < opt->seq_recv + 1 || WRAPPED(opt->seq_recv, seq)) {
if ((payload[0] == PPP_ALLSTATIONS) && (payload[1] == PPP_UI) &&
(PPP_PROTOCOL(payload) == PPP_LCP) &&
((payload[4] == PPP_LCP_ECHOREQ) || (payload[4] == PPP_LCP_ECHOREP)))
goto allow_packet;
} else {
opt->seq_recv = seq;
allow_packet:
skb_pull(skb, headersize);
if (payload[0] == PPP_ALLSTATIONS && payload[1] == PPP_UI) {
if (skb->len < 3)
goto drop;
skb_pull(skb, 2);
}
if ((*skb->data) & 1) {
skb_push(skb, 1)[0] = 0;
}
skb->ip_summed = CHECKSUM_NONE;
skb_set_network_header(skb, skb->head-skb->data);
ppp_input(&po->chan, skb);
return NET_RX_SUCCESS;
}
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static int pptp_rcv(struct sk_buff *skb)
{
struct pppox_sock *po;
struct pptp_gre_header *header;
struct iphdr *iph;
if (skb->pkt_type != PACKET_HOST)
goto drop;
if (!pskb_may_pull(skb, 12))
goto drop;
iph = ip_hdr(skb);
header = (struct pptp_gre_header *)skb->data;
if (ntohs(header->protocol) != PPTP_GRE_PROTO ||
PPTP_GRE_IS_C(header->flags) ||
PPTP_GRE_IS_R(header->flags) ||
!PPTP_GRE_IS_K(header->flags) ||
(header->flags&0xF) != 0)
goto drop;
po = lookup_chan(htons(header->call_id), iph->saddr);
if (po) {
skb_dst_drop(skb);
nf_reset(skb);
return sk_receive_skb(sk_pppox(po), skb, 0);
}
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static int pptp_bind(struct socket *sock, struct sockaddr *uservaddr,
int sockaddr_len)
{
struct sock *sk = sock->sk;
struct sockaddr_pppox *sp = (struct sockaddr_pppox *) uservaddr;
struct pppox_sock *po = pppox_sk(sk);
struct pptp_opt *opt = &po->proto.pptp;
int error = 0;
lock_sock(sk);
opt->src_addr = sp->sa_addr.pptp;
if (add_chan(po)) {
release_sock(sk);
error = -EBUSY;
}
release_sock(sk);
return error;
}
static int pptp_connect(struct socket *sock, struct sockaddr *uservaddr,
int sockaddr_len, int flags)
{
struct sock *sk = sock->sk;
struct sockaddr_pppox *sp = (struct sockaddr_pppox *) uservaddr;
struct pppox_sock *po = pppox_sk(sk);
struct pptp_opt *opt = &po->proto.pptp;
struct rtable *rt;
struct flowi4 fl4;
int error = 0;
if (sp->sa_protocol != PX_PROTO_PPTP)
return -EINVAL;
if (lookup_chan_dst(sp->sa_addr.pptp.call_id, sp->sa_addr.pptp.sin_addr.s_addr))
return -EALREADY;
lock_sock(sk);
if (sk->sk_state & PPPOX_CONNECTED) {
error = -EBUSY;
goto end;
}
if (sk->sk_state & PPPOX_DEAD) {
error = -EALREADY;
goto end;
}
if (!opt->src_addr.sin_addr.s_addr || !sp->sa_addr.pptp.sin_addr.s_addr) {
error = -EINVAL;
goto end;
}
po->chan.private = sk;
po->chan.ops = &pptp_chan_ops;
rt = ip_route_output_ports(&init_net, &fl4, sk,
opt->dst_addr.sin_addr.s_addr,
opt->src_addr.sin_addr.s_addr,
0, 0,
IPPROTO_GRE, RT_CONN_FLAGS(sk), 0);
if (IS_ERR(rt)) {
error = -EHOSTUNREACH;
goto end;
}
sk_setup_caps(sk, &rt->dst);
po->chan.mtu = dst_mtu(&rt->dst);
if (!po->chan.mtu)
po->chan.mtu = PPP_MTU;
ip_rt_put(rt);
po->chan.mtu -= PPTP_HEADER_OVERHEAD;
po->chan.hdrlen = 2 + sizeof(struct pptp_gre_header);
error = ppp_register_channel(&po->chan);
if (error) {
pr_err("PPTP: failed to register PPP channel (%d)\n", error);
goto end;
}
opt->dst_addr = sp->sa_addr.pptp;
sk->sk_state = PPPOX_CONNECTED;
end:
release_sock(sk);
return error;
}
static int pptp_getname(struct socket *sock, struct sockaddr *uaddr,
int *usockaddr_len, int peer)
{
int len = sizeof(struct sockaddr_pppox);
struct sockaddr_pppox sp;
sp.sa_family = AF_PPPOX;
sp.sa_protocol = PX_PROTO_PPTP;
sp.sa_addr.pptp = pppox_sk(sock->sk)->proto.pptp.src_addr;
memcpy(uaddr, &sp, len);
*usockaddr_len = len;
return 0;
}
static int pptp_release(struct socket *sock)
{
struct sock *sk = sock->sk;
struct pppox_sock *po;
struct pptp_opt *opt;
int error = 0;
if (!sk)
return 0;
lock_sock(sk);
if (sock_flag(sk, SOCK_DEAD)) {
release_sock(sk);
return -EBADF;
}
po = pppox_sk(sk);
opt = &po->proto.pptp;
del_chan(po);
pppox_unbind_sock(sk);
sk->sk_state = PPPOX_DEAD;
sock_orphan(sk);
sock->sk = NULL;
release_sock(sk);
sock_put(sk);
return error;
}
static void pptp_sock_destruct(struct sock *sk)
{
if (!(sk->sk_state & PPPOX_DEAD)) {
del_chan(pppox_sk(sk));
pppox_unbind_sock(sk);
}
skb_queue_purge(&sk->sk_receive_queue);
}
static int pptp_create(struct net *net, struct socket *sock)
{
int error = -ENOMEM;
struct sock *sk;
struct pppox_sock *po;
struct pptp_opt *opt;
sk = sk_alloc(net, PF_PPPOX, GFP_KERNEL, &pptp_sk_proto);
if (!sk)
goto out;
sock_init_data(sock, sk);
sock->state = SS_UNCONNECTED;
sock->ops = &pptp_ops;
sk->sk_backlog_rcv = pptp_rcv_core;
sk->sk_state = PPPOX_NONE;
sk->sk_type = SOCK_STREAM;
sk->sk_family = PF_PPPOX;
sk->sk_protocol = PX_PROTO_PPTP;
sk->sk_destruct = pptp_sock_destruct;
po = pppox_sk(sk);
opt = &po->proto.pptp;
opt->seq_sent = 0; opt->seq_recv = 0;
opt->ack_recv = 0; opt->ack_sent = 0;
error = 0;
out:
return error;
}
static int pptp_ppp_ioctl(struct ppp_channel *chan, unsigned int cmd,
unsigned long arg)
{
struct sock *sk = (struct sock *) chan->private;
struct pppox_sock *po = pppox_sk(sk);
struct pptp_opt *opt = &po->proto.pptp;
void __user *argp = (void __user *)arg;
int __user *p = argp;
int err, val;
err = -EFAULT;
switch (cmd) {
case PPPIOCGFLAGS:
val = opt->ppp_flags;
if (put_user(val, p))
break;
err = 0;
break;
case PPPIOCSFLAGS:
if (get_user(val, p))
break;
opt->ppp_flags = val & ~SC_RCV_BITS;
err = 0;
break;
default:
err = -ENOTTY;
}
return err;
}
static int __init pptp_init_module(void)
{
int err = 0;
pr_info("PPTP driver version " PPTP_DRIVER_VERSION "\n");
callid_sock = vzalloc((MAX_CALLID + 1) * sizeof(void *));
if (!callid_sock) {
pr_err("PPTP: cann't allocate memory\n");
return -ENOMEM;
}
err = gre_add_protocol(&gre_pptp_protocol, GREPROTO_PPTP);
if (err) {
pr_err("PPTP: can't add gre protocol\n");
goto out_mem_free;
}
err = proto_register(&pptp_sk_proto, 0);
if (err) {
pr_err("PPTP: can't register sk_proto\n");
goto out_gre_del_protocol;
}
err = register_pppox_proto(PX_PROTO_PPTP, &pppox_pptp_proto);
if (err) {
pr_err("PPTP: can't register pppox_proto\n");
goto out_unregister_sk_proto;
}
return 0;
out_unregister_sk_proto:
proto_unregister(&pptp_sk_proto);
out_gre_del_protocol:
gre_del_protocol(&gre_pptp_protocol, GREPROTO_PPTP);
out_mem_free:
vfree(callid_sock);
return err;
}
static void __exit pptp_exit_module(void)
{
unregister_pppox_proto(PX_PROTO_PPTP);
proto_unregister(&pptp_sk_proto);
gre_del_protocol(&gre_pptp_protocol, GREPROTO_PPTP);
vfree(callid_sock);
}
