static inline struct genevehdr *geneve_hdr(const struct sk_buff *skb)
{
return (struct genevehdr *)(udp_hdr(skb) + 1);
}
static struct geneve_sock *geneve_find_sock(struct net *net,
sa_family_t family, __be16 port)
{
struct geneve_net *gn = net_generic(net, geneve_net_id);
struct geneve_sock *gs;
list_for_each_entry(gs, &gn->sock_list, list) {
if (inet_sk(gs->sock->sk)->inet_sport == port &&
inet_sk(gs->sock->sk)->sk.sk_family == family)
return gs;
}
return NULL;
}
static void geneve_build_header(struct genevehdr *geneveh,
__be16 tun_flags, u8 vni[3],
u8 options_len, u8 *options)
{
geneveh->ver = GENEVE_VER;
geneveh->opt_len = options_len / 4;
geneveh->oam = !!(tun_flags & TUNNEL_OAM);
geneveh->critical = !!(tun_flags & TUNNEL_CRIT_OPT);
geneveh->rsvd1 = 0;
memcpy(geneveh->vni, vni, 3);
geneveh->proto_type = htons(ETH_P_TEB);
geneveh->rsvd2 = 0;
memcpy(geneveh->options, options, options_len);
}
int geneve_xmit_skb(struct geneve_sock *gs, struct rtable *rt,
struct sk_buff *skb, __be32 src, __be32 dst, __u8 tos,
__u8 ttl, __be16 df, __be16 src_port, __be16 dst_port,
__be16 tun_flags, u8 vni[3], u8 opt_len, u8 *opt,
bool csum, bool xnet)
{
struct genevehdr *gnvh;
int min_headroom;
int err;
skb = udp_tunnel_handle_offloads(skb, csum);
if (IS_ERR(skb))
return PTR_ERR(skb);
min_headroom = LL_RESERVED_SPACE(rt->dst.dev) + rt->dst.header_len
+ GENEVE_BASE_HLEN + opt_len + sizeof(struct iphdr)
+ (skb_vlan_tag_present(skb) ? VLAN_HLEN : 0);
err = skb_cow_head(skb, min_headroom);
if (unlikely(err)) {
kfree_skb(skb);
return err;
}
skb = vlan_hwaccel_push_inside(skb);
if (unlikely(!skb))
return -ENOMEM;
gnvh = (struct genevehdr *)__skb_push(skb, sizeof(*gnvh) + opt_len);
geneve_build_header(gnvh, tun_flags, vni, opt_len, opt);
skb_set_inner_protocol(skb, htons(ETH_P_TEB));
return udp_tunnel_xmit_skb(rt, skb, src, dst,
tos, ttl, df, src_port, dst_port, xnet,
!csum);
}
static int geneve_hlen(struct genevehdr *gh)
{
return sizeof(*gh) + gh->opt_len * 4;
}
static struct sk_buff **geneve_gro_receive(struct sk_buff **head,
struct sk_buff *skb,
struct udp_offload *uoff)
{
struct sk_buff *p, **pp = NULL;
struct genevehdr *gh, *gh2;
unsigned int hlen, gh_len, off_gnv;
const struct packet_offload *ptype;
__be16 type;
int flush = 1;
off_gnv = skb_gro_offset(skb);
hlen = off_gnv + sizeof(*gh);
gh = skb_gro_header_fast(skb, off_gnv);
if (skb_gro_header_hard(skb, hlen)) {
gh = skb_gro_header_slow(skb, hlen, off_gnv);
if (unlikely(!gh))
goto out;
}
if (gh->ver != GENEVE_VER || gh->oam)
goto out;
gh_len = geneve_hlen(gh);
hlen = off_gnv + gh_len;
if (skb_gro_header_hard(skb, hlen)) {
gh = skb_gro_header_slow(skb, hlen, off_gnv);
if (unlikely(!gh))
goto out;
}
flush = 0;
for (p = *head; p; p = p->next) {
if (!NAPI_GRO_CB(p)->same_flow)
continue;
gh2 = (struct genevehdr *)(p->data + off_gnv);
if (gh->opt_len != gh2->opt_len ||
memcmp(gh, gh2, gh_len)) {
NAPI_GRO_CB(p)->same_flow = 0;
continue;
}
}
type = gh->proto_type;
rcu_read_lock();
ptype = gro_find_receive_by_type(type);
if (ptype == NULL) {
flush = 1;
goto out_unlock;
}
skb_gro_pull(skb, gh_len);
skb_gro_postpull_rcsum(skb, gh, gh_len);
pp = ptype->callbacks.gro_receive(head, skb);
out_unlock:
rcu_read_unlock();
out:
NAPI_GRO_CB(skb)->flush |= flush;
return pp;
}
static int geneve_gro_complete(struct sk_buff *skb, int nhoff,
struct udp_offload *uoff)
{
struct genevehdr *gh;
struct packet_offload *ptype;
__be16 type;
int gh_len;
int err = -ENOSYS;
udp_tunnel_gro_complete(skb, nhoff);
gh = (struct genevehdr *)(skb->data + nhoff);
gh_len = geneve_hlen(gh);
type = gh->proto_type;
rcu_read_lock();
ptype = gro_find_complete_by_type(type);
if (ptype != NULL)
err = ptype->callbacks.gro_complete(skb, nhoff + gh_len);
rcu_read_unlock();
return err;
}
static void geneve_notify_add_rx_port(struct geneve_sock *gs)
{
struct sock *sk = gs->sock->sk;
sa_family_t sa_family = sk->sk_family;
int err;
if (sa_family == AF_INET) {
err = udp_add_offload(&gs->udp_offloads);
if (err)
pr_warn("geneve: udp_add_offload failed with status %d\n",
err);
}
}
static void geneve_notify_del_rx_port(struct geneve_sock *gs)
{
struct sock *sk = gs->sock->sk;
sa_family_t sa_family = sk->sk_family;
if (sa_family == AF_INET)
udp_del_offload(&gs->udp_offloads);
}
static int geneve_udp_encap_recv(struct sock *sk, struct sk_buff *skb)
{
struct genevehdr *geneveh;
struct geneve_sock *gs;
int opts_len;
if (unlikely(!pskb_may_pull(skb, GENEVE_BASE_HLEN)))
goto error;
geneveh = geneve_hdr(skb);
if (unlikely(geneveh->ver != GENEVE_VER))
goto error;
if (unlikely(geneveh->proto_type != htons(ETH_P_TEB)))
goto error;
opts_len = geneveh->opt_len * 4;
if (iptunnel_pull_header(skb, GENEVE_BASE_HLEN + opts_len,
htons(ETH_P_TEB)))
goto drop;
gs = rcu_dereference_sk_user_data(sk);
if (!gs)
goto drop;
gs->rcv(gs, skb);
return 0;
drop:
kfree_skb(skb);
return 0;
error:
return 1;
}
static struct socket *geneve_create_sock(struct net *net, bool ipv6,
__be16 port)
{
struct socket *sock;
struct udp_port_cfg udp_conf;
int err;
memset(&udp_conf, 0, sizeof(udp_conf));
if (ipv6) {
udp_conf.family = AF_INET6;
} else {
udp_conf.family = AF_INET;
udp_conf.local_ip.s_addr = htonl(INADDR_ANY);
}
udp_conf.local_udp_port = port;
err = udp_sock_create(net, &udp_conf, &sock);
if (err < 0)
return ERR_PTR(err);
return sock;
}
static struct geneve_sock *geneve_socket_create(struct net *net, __be16 port,
geneve_rcv_t *rcv, void *data,
bool ipv6)
{
struct geneve_net *gn = net_generic(net, geneve_net_id);
struct geneve_sock *gs;
struct socket *sock;
struct udp_tunnel_sock_cfg tunnel_cfg;
gs = kzalloc(sizeof(*gs), GFP_KERNEL);
if (!gs)
return ERR_PTR(-ENOMEM);
sock = geneve_create_sock(net, ipv6, port);
if (IS_ERR(sock)) {
kfree(gs);
return ERR_CAST(sock);
}
gs->sock = sock;
gs->refcnt = 1;
gs->rcv = rcv;
gs->rcv_data = data;
gs->udp_offloads.port = port;
gs->udp_offloads.callbacks.gro_receive = geneve_gro_receive;
gs->udp_offloads.callbacks.gro_complete = geneve_gro_complete;
geneve_notify_add_rx_port(gs);
tunnel_cfg.sk_user_data = gs;
tunnel_cfg.encap_type = 1;
tunnel_cfg.encap_rcv = geneve_udp_encap_recv;
tunnel_cfg.encap_destroy = NULL;
setup_udp_tunnel_sock(net, sock, &tunnel_cfg);
list_add(&gs->list, &gn->sock_list);
return gs;
}
struct geneve_sock *geneve_sock_add(struct net *net, __be16 port,
geneve_rcv_t *rcv, void *data,
bool no_share, bool ipv6)
{
struct geneve_sock *gs;
mutex_lock(&geneve_mutex);
gs = geneve_find_sock(net, ipv6 ? AF_INET6 : AF_INET, port);
if (gs) {
if (!no_share && gs->rcv == rcv)
gs->refcnt++;
else
gs = ERR_PTR(-EBUSY);
} else {
gs = geneve_socket_create(net, port, rcv, data, ipv6);
}
mutex_unlock(&geneve_mutex);
return gs;
}
void geneve_sock_release(struct geneve_sock *gs)
{
mutex_lock(&geneve_mutex);
if (--gs->refcnt)
goto unlock;
list_del(&gs->list);
geneve_notify_del_rx_port(gs);
udp_tunnel_sock_release(gs->sock);
kfree_rcu(gs, rcu);
unlock:
mutex_unlock(&geneve_mutex);
}
static __net_init int geneve_init_net(struct net *net)
{
struct geneve_net *gn = net_generic(net, geneve_net_id);
INIT_LIST_HEAD(&gn->sock_list);
return 0;
}
static int __init geneve_init_module(void)
{
int rc;
rc = register_pernet_subsys(&geneve_net_ops);
if (rc)
return rc;
pr_info("Geneve driver\n");
return 0;
}
static void __exit geneve_cleanup_module(void)
{
unregister_pernet_subsys(&geneve_net_ops);
}
