static inline u32 gtp0_hashfn(u64 tid)
{
u32 *tid32 = (u32 *) &tid;
return jhash_2words(tid32[0], tid32[1], gtp_h_initval);
}
static inline u32 gtp1u_hashfn(u32 tid)
{
return jhash_1word(tid, gtp_h_initval);
}
static inline u32 ipv4_hashfn(__be32 ip)
{
return jhash_1word((__force u32)ip, gtp_h_initval);
}
static struct pdp_ctx *gtp0_pdp_find(struct gtp_dev *gtp, u64 tid)
{
struct hlist_head *head;
struct pdp_ctx *pdp;
head = &gtp->tid_hash[gtp0_hashfn(tid) % gtp->hash_size];
hlist_for_each_entry_rcu(pdp, head, hlist_tid) {
if (pdp->gtp_version == GTP_V0 &&
pdp->u.v0.tid == tid)
return pdp;
}
return NULL;
}
static struct pdp_ctx *gtp1_pdp_find(struct gtp_dev *gtp, u32 tid)
{
struct hlist_head *head;
struct pdp_ctx *pdp;
head = &gtp->tid_hash[gtp1u_hashfn(tid) % gtp->hash_size];
hlist_for_each_entry_rcu(pdp, head, hlist_tid) {
if (pdp->gtp_version == GTP_V1 &&
pdp->u.v1.i_tei == tid)
return pdp;
}
return NULL;
}
static struct pdp_ctx *ipv4_pdp_find(struct gtp_dev *gtp, __be32 ms_addr)
{
struct hlist_head *head;
struct pdp_ctx *pdp;
head = &gtp->addr_hash[ipv4_hashfn(ms_addr) % gtp->hash_size];
hlist_for_each_entry_rcu(pdp, head, hlist_addr) {
if (pdp->af == AF_INET &&
pdp->ms_addr_ip4.s_addr == ms_addr)
return pdp;
}
return NULL;
}
static bool gtp_check_ms_ipv4(struct sk_buff *skb, struct pdp_ctx *pctx,
unsigned int hdrlen, unsigned int role)
{
struct iphdr *iph;
if (!pskb_may_pull(skb, hdrlen + sizeof(struct iphdr)))
return false;
iph = (struct iphdr *)(skb->data + hdrlen);
if (role == GTP_ROLE_SGSN)
return iph->daddr == pctx->ms_addr_ip4.s_addr;
else
return iph->saddr == pctx->ms_addr_ip4.s_addr;
}
static bool gtp_check_ms(struct sk_buff *skb, struct pdp_ctx *pctx,
unsigned int hdrlen, unsigned int role)
{
switch (ntohs(skb->protocol)) {
case ETH_P_IP:
return gtp_check_ms_ipv4(skb, pctx, hdrlen, role);
}
return false;
}
static int gtp_rx(struct pdp_ctx *pctx, struct sk_buff *skb,
unsigned int hdrlen, unsigned int role)
{
struct pcpu_sw_netstats *stats;
if (!gtp_check_ms(skb, pctx, hdrlen, role)) {
netdev_dbg(pctx->dev, "No PDP ctx for this MS\n");
return 1;
}
if (iptunnel_pull_header(skb, hdrlen, skb->protocol,
!net_eq(sock_net(pctx->sk), dev_net(pctx->dev))))
return -1;
netdev_dbg(pctx->dev, "forwarding packet from GGSN to uplink\n");
skb_reset_network_header(skb);
skb->dev = pctx->dev;
stats = this_cpu_ptr(pctx->dev->tstats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets++;
stats->rx_bytes += skb->len;
u64_stats_update_end(&stats->syncp);
netif_rx(skb);
return 0;
}
static int gtp0_udp_encap_recv(struct gtp_dev *gtp, struct sk_buff *skb)
{
unsigned int hdrlen = sizeof(struct udphdr) +
sizeof(struct gtp0_header);
struct gtp0_header *gtp0;
struct pdp_ctx *pctx;
if (!pskb_may_pull(skb, hdrlen))
return -1;
gtp0 = (struct gtp0_header *)(skb->data + sizeof(struct udphdr));
if ((gtp0->flags >> 5) != GTP_V0)
return 1;
if (gtp0->type != GTP_TPDU)
return 1;
pctx = gtp0_pdp_find(gtp, be64_to_cpu(gtp0->tid));
if (!pctx) {
netdev_dbg(gtp->dev, "No PDP ctx to decap skb=%p\n", skb);
return 1;
}
return gtp_rx(pctx, skb, hdrlen, gtp->role);
}
static int gtp1u_udp_encap_recv(struct gtp_dev *gtp, struct sk_buff *skb)
{
unsigned int hdrlen = sizeof(struct udphdr) +
sizeof(struct gtp1_header);
struct gtp1_header *gtp1;
struct pdp_ctx *pctx;
if (!pskb_may_pull(skb, hdrlen))
return -1;
gtp1 = (struct gtp1_header *)(skb->data + sizeof(struct udphdr));
if ((gtp1->flags >> 5) != GTP_V1)
return 1;
if (gtp1->type != GTP_TPDU)
return 1;
if (gtp1->flags & GTP1_F_MASK)
hdrlen += 4;
if (!pskb_may_pull(skb, hdrlen))
return -1;
gtp1 = (struct gtp1_header *)(skb->data + sizeof(struct udphdr));
pctx = gtp1_pdp_find(gtp, ntohl(gtp1->tid));
if (!pctx) {
netdev_dbg(gtp->dev, "No PDP ctx to decap skb=%p\n", skb);
return 1;
}
return gtp_rx(pctx, skb, hdrlen, gtp->role);
}
static void gtp_encap_destroy(struct sock *sk)
{
struct gtp_dev *gtp;
gtp = rcu_dereference_sk_user_data(sk);
if (gtp) {
udp_sk(sk)->encap_type = 0;
rcu_assign_sk_user_data(sk, NULL);
sock_put(sk);
}
}
static void gtp_encap_disable_sock(struct sock *sk)
{
if (!sk)
return;
gtp_encap_destroy(sk);
}
static void gtp_encap_disable(struct gtp_dev *gtp)
{
gtp_encap_disable_sock(gtp->sk0);
gtp_encap_disable_sock(gtp->sk1u);
}
static int gtp_encap_recv(struct sock *sk, struct sk_buff *skb)
{
struct gtp_dev *gtp;
int ret = 0;
gtp = rcu_dereference_sk_user_data(sk);
if (!gtp)
return 1;
netdev_dbg(gtp->dev, "encap_recv sk=%p\n", sk);
switch (udp_sk(sk)->encap_type) {
case UDP_ENCAP_GTP0:
netdev_dbg(gtp->dev, "received GTP0 packet\n");
ret = gtp0_udp_encap_recv(gtp, skb);
break;
case UDP_ENCAP_GTP1U:
netdev_dbg(gtp->dev, "received GTP1U packet\n");
ret = gtp1u_udp_encap_recv(gtp, skb);
break;
default:
ret = -1;
}
switch (ret) {
case 1:
netdev_dbg(gtp->dev, "pass up to the process\n");
break;
case 0:
break;
case -1:
netdev_dbg(gtp->dev, "GTP packet has been dropped\n");
kfree_skb(skb);
ret = 0;
break;
}
return ret;
}
static int gtp_dev_init(struct net_device *dev)
{
struct gtp_dev *gtp = netdev_priv(dev);
gtp->dev = dev;
dev->tstats = alloc_percpu(struct pcpu_sw_netstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static void gtp_dev_uninit(struct net_device *dev)
{
struct gtp_dev *gtp = netdev_priv(dev);
gtp_encap_disable(gtp);
free_percpu(dev->tstats);
}
static struct rtable *ip4_route_output_gtp(struct flowi4 *fl4,
const struct sock *sk,
__be32 daddr)
{
memset(fl4, 0, sizeof(*fl4));
fl4->flowi4_oif = sk->sk_bound_dev_if;
fl4->daddr = daddr;
fl4->saddr = inet_sk(sk)->inet_saddr;
fl4->flowi4_tos = RT_CONN_FLAGS(sk);
fl4->flowi4_proto = sk->sk_protocol;
return ip_route_output_key(sock_net(sk), fl4);
}
static inline void gtp0_push_header(struct sk_buff *skb, struct pdp_ctx *pctx)
{
int payload_len = skb->len;
struct gtp0_header *gtp0;
gtp0 = (struct gtp0_header *) skb_push(skb, sizeof(*gtp0));
gtp0->flags = 0x1e;
gtp0->type = GTP_TPDU;
gtp0->length = htons(payload_len);
gtp0->seq = htons((atomic_inc_return(&pctx->tx_seq) - 1) % 0xffff);
gtp0->flow = htons(pctx->u.v0.flow);
gtp0->number = 0xff;
gtp0->spare[0] = gtp0->spare[1] = gtp0->spare[2] = 0xff;
gtp0->tid = cpu_to_be64(pctx->u.v0.tid);
}
static inline void gtp1_push_header(struct sk_buff *skb, struct pdp_ctx *pctx)
{
int payload_len = skb->len;
struct gtp1_header *gtp1;
gtp1 = (struct gtp1_header *) skb_push(skb, sizeof(*gtp1));
gtp1->flags = 0x30;
gtp1->type = GTP_TPDU;
gtp1->length = htons(payload_len);
gtp1->tid = htonl(pctx->u.v1.o_tei);
}
static void gtp_push_header(struct sk_buff *skb, struct gtp_pktinfo *pktinfo)
{
switch (pktinfo->pctx->gtp_version) {
case GTP_V0:
pktinfo->gtph_port = htons(GTP0_PORT);
gtp0_push_header(skb, pktinfo->pctx);
break;
case GTP_V1:
pktinfo->gtph_port = htons(GTP1U_PORT);
gtp1_push_header(skb, pktinfo->pctx);
break;
}
}
static inline void gtp_set_pktinfo_ipv4(struct gtp_pktinfo *pktinfo,
struct sock *sk, struct iphdr *iph,
struct pdp_ctx *pctx, struct rtable *rt,
struct flowi4 *fl4,
struct net_device *dev)
{
pktinfo->sk = sk;
pktinfo->iph = iph;
pktinfo->pctx = pctx;
pktinfo->rt = rt;
pktinfo->fl4 = *fl4;
pktinfo->dev = dev;
}
static int gtp_build_skb_ip4(struct sk_buff *skb, struct net_device *dev,
struct gtp_pktinfo *pktinfo)
{
struct gtp_dev *gtp = netdev_priv(dev);
struct pdp_ctx *pctx;
struct rtable *rt;
struct flowi4 fl4;
struct iphdr *iph;
__be16 df;
int mtu;
iph = ip_hdr(skb);
if (gtp->role == GTP_ROLE_SGSN)
pctx = ipv4_pdp_find(gtp, iph->saddr);
else
pctx = ipv4_pdp_find(gtp, iph->daddr);
if (!pctx) {
netdev_dbg(dev, "no PDP ctx found for %pI4, skip\n",
&iph->daddr);
return -ENOENT;
}
netdev_dbg(dev, "found PDP context %p\n", pctx);
rt = ip4_route_output_gtp(&fl4, pctx->sk, pctx->peer_addr_ip4.s_addr);
if (IS_ERR(rt)) {
netdev_dbg(dev, "no route to SSGN %pI4\n",
&pctx->peer_addr_ip4.s_addr);
dev->stats.tx_carrier_errors++;
goto err;
}
if (rt->dst.dev == dev) {
netdev_dbg(dev, "circular route to SSGN %pI4\n",
&pctx->peer_addr_ip4.s_addr);
dev->stats.collisions++;
goto err_rt;
}
skb_dst_drop(skb);
df = iph->frag_off;
if (df) {
mtu = dst_mtu(&rt->dst) - dev->hard_header_len -
sizeof(struct iphdr) - sizeof(struct udphdr);
switch (pctx->gtp_version) {
case GTP_V0:
mtu -= sizeof(struct gtp0_header);
break;
case GTP_V1:
mtu -= sizeof(struct gtp1_header);
break;
}
} else {
mtu = dst_mtu(&rt->dst);
}
rt->dst.ops->update_pmtu(&rt->dst, NULL, skb, mtu);
if (!skb_is_gso(skb) && (iph->frag_off & htons(IP_DF)) &&
mtu < ntohs(iph->tot_len)) {
netdev_dbg(dev, "packet too big, fragmentation needed\n");
memset(IPCB(skb), 0, sizeof(*IPCB(skb)));
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
goto err_rt;
}
gtp_set_pktinfo_ipv4(pktinfo, pctx->sk, iph, pctx, rt, &fl4, dev);
gtp_push_header(skb, pktinfo);
return 0;
err_rt:
ip_rt_put(rt);
err:
return -EBADMSG;
}
static netdev_tx_t gtp_dev_xmit(struct sk_buff *skb, struct net_device *dev)
{
unsigned int proto = ntohs(skb->protocol);
struct gtp_pktinfo pktinfo;
int err;
if (skb_cow_head(skb, dev->needed_headroom))
goto tx_err;
skb_reset_inner_headers(skb);
rcu_read_lock();
switch (proto) {
case ETH_P_IP:
err = gtp_build_skb_ip4(skb, dev, &pktinfo);
break;
default:
err = -EOPNOTSUPP;
break;
}
rcu_read_unlock();
if (err < 0)
goto tx_err;
switch (proto) {
case ETH_P_IP:
netdev_dbg(pktinfo.dev, "gtp -> IP src: %pI4 dst: %pI4\n",
&pktinfo.iph->saddr, &pktinfo.iph->daddr);
udp_tunnel_xmit_skb(pktinfo.rt, pktinfo.sk, skb,
pktinfo.fl4.saddr, pktinfo.fl4.daddr,
pktinfo.iph->tos,
ip4_dst_hoplimit(&pktinfo.rt->dst),
0,
pktinfo.gtph_port, pktinfo.gtph_port,
true, false);
break;
}
return NETDEV_TX_OK;
tx_err:
dev->stats.tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void gtp_link_setup(struct net_device *dev)
{
dev->netdev_ops = &gtp_netdev_ops;
dev->needs_free_netdev = true;
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->type = ARPHRD_NONE;
dev->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
dev->priv_flags |= IFF_NO_QUEUE;
dev->features |= NETIF_F_LLTX;
netif_keep_dst(dev);
dev->needed_headroom = LL_MAX_HEADER +
sizeof(struct iphdr) +
sizeof(struct udphdr) +
sizeof(struct gtp0_header);
}
static int gtp_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct gtp_dev *gtp;
struct gtp_net *gn;
int hashsize, err;
if (!data[IFLA_GTP_FD0] && !data[IFLA_GTP_FD1])
return -EINVAL;
gtp = netdev_priv(dev);
err = gtp_encap_enable(gtp, data);
if (err < 0)
return err;
if (!data[IFLA_GTP_PDP_HASHSIZE])
hashsize = 1024;
else
hashsize = nla_get_u32(data[IFLA_GTP_PDP_HASHSIZE]);
err = gtp_hashtable_new(gtp, hashsize);
if (err < 0)
goto out_encap;
err = register_netdevice(dev);
if (err < 0) {
netdev_dbg(dev, "failed to register new netdev %d\n", err);
goto out_hashtable;
}
gn = net_generic(dev_net(dev), gtp_net_id);
list_add_rcu(&gtp->list, &gn->gtp_dev_list);
netdev_dbg(dev, "registered new GTP interface\n");
return 0;
out_hashtable:
gtp_hashtable_free(gtp);
out_encap:
gtp_encap_disable(gtp);
return err;
}
static void gtp_dellink(struct net_device *dev, struct list_head *head)
{
struct gtp_dev *gtp = netdev_priv(dev);
gtp_encap_disable(gtp);
gtp_hashtable_free(gtp);
list_del_rcu(&gtp->list);
unregister_netdevice_queue(dev, head);
}
static int gtp_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (!data)
return -EINVAL;
return 0;
}
static size_t gtp_get_size(const struct net_device *dev)
{
return nla_total_size(sizeof(__u32));
}
static int gtp_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct gtp_dev *gtp = netdev_priv(dev);
if (nla_put_u32(skb, IFLA_GTP_PDP_HASHSIZE, gtp->hash_size))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int gtp_hashtable_new(struct gtp_dev *gtp, int hsize)
{
int i;
gtp->addr_hash = kmalloc(sizeof(struct hlist_head) * hsize, GFP_KERNEL);
if (gtp->addr_hash == NULL)
return -ENOMEM;
gtp->tid_hash = kmalloc(sizeof(struct hlist_head) * hsize, GFP_KERNEL);
if (gtp->tid_hash == NULL)
goto err1;
gtp->hash_size = hsize;
for (i = 0; i < hsize; i++) {
INIT_HLIST_HEAD(&gtp->addr_hash[i]);
INIT_HLIST_HEAD(&gtp->tid_hash[i]);
}
return 0;
err1:
kfree(gtp->addr_hash);
return -ENOMEM;
}
static void gtp_hashtable_free(struct gtp_dev *gtp)
{
struct pdp_ctx *pctx;
int i;
for (i = 0; i < gtp->hash_size; i++)
hlist_for_each_entry_rcu(pctx, &gtp->tid_hash[i], hlist_tid)
pdp_context_delete(pctx);
synchronize_rcu();
kfree(gtp->addr_hash);
kfree(gtp->tid_hash);
}
static struct sock *gtp_encap_enable_socket(int fd, int type,
struct gtp_dev *gtp)
{
struct udp_tunnel_sock_cfg tuncfg = {NULL};
struct socket *sock;
struct sock *sk;
int err;
pr_debug("enable gtp on %d, %d\n", fd, type);
sock = sockfd_lookup(fd, &err);
if (!sock) {
pr_debug("gtp socket fd=%d not found\n", fd);
return NULL;
}
if (sock->sk->sk_protocol != IPPROTO_UDP) {
pr_debug("socket fd=%d not UDP\n", fd);
sk = ERR_PTR(-EINVAL);
goto out_sock;
}
if (rcu_dereference_sk_user_data(sock->sk)) {
sk = ERR_PTR(-EBUSY);
goto out_sock;
}
sk = sock->sk;
sock_hold(sk);
tuncfg.sk_user_data = gtp;
tuncfg.encap_type = type;
tuncfg.encap_rcv = gtp_encap_recv;
tuncfg.encap_destroy = gtp_encap_destroy;
setup_udp_tunnel_sock(sock_net(sock->sk), sock, &tuncfg);
out_sock:
sockfd_put(sock);
return sk;
}
static int gtp_encap_enable(struct gtp_dev *gtp, struct nlattr *data[])
{
struct sock *sk1u = NULL;
struct sock *sk0 = NULL;
unsigned int role = GTP_ROLE_GGSN;
if (data[IFLA_GTP_FD0]) {
u32 fd0 = nla_get_u32(data[IFLA_GTP_FD0]);
sk0 = gtp_encap_enable_socket(fd0, UDP_ENCAP_GTP0, gtp);
if (IS_ERR(sk0))
return PTR_ERR(sk0);
}
if (data[IFLA_GTP_FD1]) {
u32 fd1 = nla_get_u32(data[IFLA_GTP_FD1]);
sk1u = gtp_encap_enable_socket(fd1, UDP_ENCAP_GTP1U, gtp);
if (IS_ERR(sk1u)) {
if (sk0)
gtp_encap_disable_sock(sk0);
return PTR_ERR(sk1u);
}
}
if (data[IFLA_GTP_ROLE]) {
role = nla_get_u32(data[IFLA_GTP_ROLE]);
if (role > GTP_ROLE_SGSN)
return -EINVAL;
}
gtp->sk0 = sk0;
gtp->sk1u = sk1u;
gtp->role = role;
return 0;
}
static struct gtp_dev *gtp_find_dev(struct net *src_net, struct nlattr *nla[])
{
struct gtp_dev *gtp = NULL;
struct net_device *dev;
struct net *net;
if (nla[GTPA_NET_NS_FD])
net = get_net_ns_by_fd(nla_get_u32(nla[GTPA_NET_NS_FD]));
else
net = get_net(src_net);
if (IS_ERR(net))
return NULL;
dev = dev_get_by_index_rcu(net, nla_get_u32(nla[GTPA_LINK]));
if (dev && dev->netdev_ops == &gtp_netdev_ops)
gtp = netdev_priv(dev);
put_net(net);
return gtp;
}
static void ipv4_pdp_fill(struct pdp_ctx *pctx, struct genl_info *info)
{
pctx->gtp_version = nla_get_u32(info->attrs[GTPA_VERSION]);
pctx->af = AF_INET;
pctx->peer_addr_ip4.s_addr =
nla_get_be32(info->attrs[GTPA_PEER_ADDRESS]);
pctx->ms_addr_ip4.s_addr =
nla_get_be32(info->attrs[GTPA_MS_ADDRESS]);
switch (pctx->gtp_version) {
case GTP_V0:
pctx->u.v0.tid = nla_get_u64(info->attrs[GTPA_TID]);
pctx->u.v0.flow = nla_get_u16(info->attrs[GTPA_FLOW]);
break;
case GTP_V1:
pctx->u.v1.i_tei = nla_get_u32(info->attrs[GTPA_I_TEI]);
pctx->u.v1.o_tei = nla_get_u32(info->attrs[GTPA_O_TEI]);
break;
default:
break;
}
}
static int ipv4_pdp_add(struct gtp_dev *gtp, struct sock *sk,
struct genl_info *info)
{
struct net_device *dev = gtp->dev;
u32 hash_ms, hash_tid = 0;
struct pdp_ctx *pctx;
bool found = false;
__be32 ms_addr;
ms_addr = nla_get_be32(info->attrs[GTPA_MS_ADDRESS]);
hash_ms = ipv4_hashfn(ms_addr) % gtp->hash_size;
hlist_for_each_entry_rcu(pctx, &gtp->addr_hash[hash_ms], hlist_addr) {
if (pctx->ms_addr_ip4.s_addr == ms_addr) {
found = true;
break;
}
}
if (found) {
if (info->nlhdr->nlmsg_flags & NLM_F_EXCL)
return -EEXIST;
if (info->nlhdr->nlmsg_flags & NLM_F_REPLACE)
return -EOPNOTSUPP;
ipv4_pdp_fill(pctx, info);
if (pctx->gtp_version == GTP_V0)
netdev_dbg(dev, "GTPv0-U: update tunnel id = %llx (pdp %p)\n",
pctx->u.v0.tid, pctx);
else if (pctx->gtp_version == GTP_V1)
netdev_dbg(dev, "GTPv1-U: update tunnel id = %x/%x (pdp %p)\n",
pctx->u.v1.i_tei, pctx->u.v1.o_tei, pctx);
return 0;
}
pctx = kmalloc(sizeof(struct pdp_ctx), GFP_KERNEL);
if (pctx == NULL)
return -ENOMEM;
sock_hold(sk);
pctx->sk = sk;
pctx->dev = gtp->dev;
ipv4_pdp_fill(pctx, info);
atomic_set(&pctx->tx_seq, 0);
switch (pctx->gtp_version) {
case GTP_V0:
hash_tid = gtp0_hashfn(pctx->u.v0.tid) % gtp->hash_size;
break;
case GTP_V1:
hash_tid = gtp1u_hashfn(pctx->u.v1.i_tei) % gtp->hash_size;
break;
}
hlist_add_head_rcu(&pctx->hlist_addr, &gtp->addr_hash[hash_ms]);
hlist_add_head_rcu(&pctx->hlist_tid, &gtp->tid_hash[hash_tid]);
switch (pctx->gtp_version) {
case GTP_V0:
netdev_dbg(dev, "GTPv0-U: new PDP ctx id=%llx ssgn=%pI4 ms=%pI4 (pdp=%p)\n",
pctx->u.v0.tid, &pctx->peer_addr_ip4,
&pctx->ms_addr_ip4, pctx);
break;
case GTP_V1:
netdev_dbg(dev, "GTPv1-U: new PDP ctx id=%x/%x ssgn=%pI4 ms=%pI4 (pdp=%p)\n",
pctx->u.v1.i_tei, pctx->u.v1.o_tei,
&pctx->peer_addr_ip4, &pctx->ms_addr_ip4, pctx);
break;
}
return 0;
}
static void pdp_context_free(struct rcu_head *head)
{
struct pdp_ctx *pctx = container_of(head, struct pdp_ctx, rcu_head);
sock_put(pctx->sk);
kfree(pctx);
}
static void pdp_context_delete(struct pdp_ctx *pctx)
{
hlist_del_rcu(&pctx->hlist_tid);
hlist_del_rcu(&pctx->hlist_addr);
call_rcu(&pctx->rcu_head, pdp_context_free);
}
static int gtp_genl_new_pdp(struct sk_buff *skb, struct genl_info *info)
{
unsigned int version;
struct gtp_dev *gtp;
struct sock *sk;
int err;
if (!info->attrs[GTPA_VERSION] ||
!info->attrs[GTPA_LINK] ||
!info->attrs[GTPA_PEER_ADDRESS] ||
!info->attrs[GTPA_MS_ADDRESS])
return -EINVAL;
version = nla_get_u32(info->attrs[GTPA_VERSION]);
switch (version) {
case GTP_V0:
if (!info->attrs[GTPA_TID] ||
!info->attrs[GTPA_FLOW])
return -EINVAL;
break;
case GTP_V1:
if (!info->attrs[GTPA_I_TEI] ||
!info->attrs[GTPA_O_TEI])
return -EINVAL;
break;
default:
return -EINVAL;
}
rcu_read_lock();
gtp = gtp_find_dev(sock_net(skb->sk), info->attrs);
if (!gtp) {
err = -ENODEV;
goto out_unlock;
}
if (version == GTP_V0)
sk = gtp->sk0;
else if (version == GTP_V1)
sk = gtp->sk1u;
else
sk = NULL;
if (!sk) {
err = -ENODEV;
goto out_unlock;
}
err = ipv4_pdp_add(gtp, sk, info);
out_unlock:
rcu_read_unlock();
return err;
}
static struct pdp_ctx *gtp_find_pdp_by_link(struct net *net,
struct nlattr *nla[])
{
struct gtp_dev *gtp;
gtp = gtp_find_dev(net, nla);
if (!gtp)
return ERR_PTR(-ENODEV);
if (nla[GTPA_MS_ADDRESS]) {
__be32 ip = nla_get_be32(nla[GTPA_MS_ADDRESS]);
return ipv4_pdp_find(gtp, ip);
} else if (nla[GTPA_VERSION]) {
u32 gtp_version = nla_get_u32(nla[GTPA_VERSION]);
if (gtp_version == GTP_V0 && nla[GTPA_TID])
return gtp0_pdp_find(gtp, nla_get_u64(nla[GTPA_TID]));
else if (gtp_version == GTP_V1 && nla[GTPA_I_TEI])
return gtp1_pdp_find(gtp, nla_get_u32(nla[GTPA_I_TEI]));
}
return ERR_PTR(-EINVAL);
}
static struct pdp_ctx *gtp_find_pdp(struct net *net, struct nlattr *nla[])
{
struct pdp_ctx *pctx;
if (nla[GTPA_LINK])
pctx = gtp_find_pdp_by_link(net, nla);
else
pctx = ERR_PTR(-EINVAL);
if (!pctx)
pctx = ERR_PTR(-ENOENT);
return pctx;
}
static int gtp_genl_del_pdp(struct sk_buff *skb, struct genl_info *info)
{
struct pdp_ctx *pctx;
int err = 0;
if (!info->attrs[GTPA_VERSION])
return -EINVAL;
rcu_read_lock();
pctx = gtp_find_pdp(sock_net(skb->sk), info->attrs);
if (IS_ERR(pctx)) {
err = PTR_ERR(pctx);
goto out_unlock;
}
if (pctx->gtp_version == GTP_V0)
netdev_dbg(pctx->dev, "GTPv0-U: deleting tunnel id = %llx (pdp %p)\n",
pctx->u.v0.tid, pctx);
else if (pctx->gtp_version == GTP_V1)
netdev_dbg(pctx->dev, "GTPv1-U: deleting tunnel id = %x/%x (pdp %p)\n",
pctx->u.v1.i_tei, pctx->u.v1.o_tei, pctx);
pdp_context_delete(pctx);
out_unlock:
rcu_read_unlock();
return err;
}
static int gtp_genl_fill_info(struct sk_buff *skb, u32 snd_portid, u32 snd_seq,
u32 type, struct pdp_ctx *pctx)
{
void *genlh;
genlh = genlmsg_put(skb, snd_portid, snd_seq, &gtp_genl_family, 0,
type);
if (genlh == NULL)
goto nlmsg_failure;
if (nla_put_u32(skb, GTPA_VERSION, pctx->gtp_version) ||
nla_put_be32(skb, GTPA_PEER_ADDRESS, pctx->peer_addr_ip4.s_addr) ||
nla_put_be32(skb, GTPA_MS_ADDRESS, pctx->ms_addr_ip4.s_addr))
goto nla_put_failure;
switch (pctx->gtp_version) {
case GTP_V0:
if (nla_put_u64_64bit(skb, GTPA_TID, pctx->u.v0.tid, GTPA_PAD) ||
nla_put_u16(skb, GTPA_FLOW, pctx->u.v0.flow))
goto nla_put_failure;
break;
case GTP_V1:
if (nla_put_u32(skb, GTPA_I_TEI, pctx->u.v1.i_tei) ||
nla_put_u32(skb, GTPA_O_TEI, pctx->u.v1.o_tei))
goto nla_put_failure;
break;
}
genlmsg_end(skb, genlh);
return 0;
nlmsg_failure:
nla_put_failure:
genlmsg_cancel(skb, genlh);
return -EMSGSIZE;
}
static int gtp_genl_get_pdp(struct sk_buff *skb, struct genl_info *info)
{
struct pdp_ctx *pctx = NULL;
struct sk_buff *skb2;
int err;
if (!info->attrs[GTPA_VERSION])
return -EINVAL;
rcu_read_lock();
pctx = gtp_find_pdp(sock_net(skb->sk), info->attrs);
if (IS_ERR(pctx)) {
err = PTR_ERR(pctx);
goto err_unlock;
}
skb2 = genlmsg_new(NLMSG_GOODSIZE, GFP_ATOMIC);
if (skb2 == NULL) {
err = -ENOMEM;
goto err_unlock;
}
err = gtp_genl_fill_info(skb2, NETLINK_CB(skb).portid,
info->snd_seq, info->nlhdr->nlmsg_type, pctx);
if (err < 0)
goto err_unlock_free;
rcu_read_unlock();
return genlmsg_unicast(genl_info_net(info), skb2, info->snd_portid);
err_unlock_free:
kfree_skb(skb2);
err_unlock:
rcu_read_unlock();
return err;
}
static int gtp_genl_dump_pdp(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct gtp_dev *last_gtp = (struct gtp_dev *)cb->args[2], *gtp;
struct net *net = sock_net(skb->sk);
struct gtp_net *gn = net_generic(net, gtp_net_id);
unsigned long tid = cb->args[1];
int i, k = cb->args[0], ret;
struct pdp_ctx *pctx;
if (cb->args[4])
return 0;
list_for_each_entry_rcu(gtp, &gn->gtp_dev_list, list) {
if (last_gtp && last_gtp != gtp)
continue;
else
last_gtp = NULL;
for (i = k; i < gtp->hash_size; i++) {
hlist_for_each_entry_rcu(pctx, &gtp->tid_hash[i], hlist_tid) {
if (tid && tid != pctx->u.tid)
continue;
else
tid = 0;
ret = gtp_genl_fill_info(skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
cb->nlh->nlmsg_type, pctx);
if (ret < 0) {
cb->args[0] = i;
cb->args[1] = pctx->u.tid;
cb->args[2] = (unsigned long)gtp;
goto out;
}
}
}
}
cb->args[4] = 1;
out:
return skb->len;
}
static int __net_init gtp_net_init(struct net *net)
{
struct gtp_net *gn = net_generic(net, gtp_net_id);
INIT_LIST_HEAD(&gn->gtp_dev_list);
return 0;
}
static void __net_exit gtp_net_exit(struct net *net)
{
struct gtp_net *gn = net_generic(net, gtp_net_id);
struct gtp_dev *gtp;
LIST_HEAD(list);
rtnl_lock();
list_for_each_entry(gtp, &gn->gtp_dev_list, list)
gtp_dellink(gtp->dev, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int __init gtp_init(void)
{
int err;
get_random_bytes(&gtp_h_initval, sizeof(gtp_h_initval));
err = rtnl_link_register(&gtp_link_ops);
if (err < 0)
goto error_out;
err = genl_register_family(&gtp_genl_family);
if (err < 0)
goto unreg_rtnl_link;
err = register_pernet_subsys(&gtp_net_ops);
if (err < 0)
goto unreg_genl_family;
pr_info("GTP module loaded (pdp ctx size %zd bytes)\n",
sizeof(struct pdp_ctx));
return 0;
unreg_genl_family:
genl_unregister_family(&gtp_genl_family);
unreg_rtnl_link:
rtnl_link_unregister(&gtp_link_ops);
error_out:
pr_err("error loading GTP module loaded\n");
return err;
}
static void __exit gtp_fini(void)
{
unregister_pernet_subsys(&gtp_net_ops);
genl_unregister_family(&gtp_genl_family);
rtnl_link_unregister(&gtp_link_ops);
pr_info("GTP module unloaded\n");
}
