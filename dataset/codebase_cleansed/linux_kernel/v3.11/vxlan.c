static inline struct hlist_head *vni_head(struct vxlan_sock *vs, u32 id)
{
return &vs->vni_list[hash_32(id, VNI_HASH_BITS)];
}
static inline struct hlist_head *vs_head(struct net *net, __be16 port)
{
struct vxlan_net *vn = net_generic(net, vxlan_net_id);
return &vn->sock_list[hash_32(ntohs(port), PORT_HASH_BITS)];
}
static inline struct vxlan_rdst *first_remote(struct vxlan_fdb *fdb)
{
return list_first_or_null_rcu(&fdb->remotes, struct vxlan_rdst, list);
}
static struct vxlan_sock *vxlan_find_port(struct net *net, __be16 port)
{
struct vxlan_sock *vs;
hlist_for_each_entry_rcu(vs, vs_head(net, port), hlist) {
if (inet_sk(vs->sock->sk)->inet_sport == port)
return vs;
}
return NULL;
}
static struct vxlan_dev *vxlan_find_vni(struct net *net, u32 id, __be16 port)
{
struct vxlan_sock *vs;
struct vxlan_dev *vxlan;
vs = vxlan_find_port(net, port);
if (!vs)
return NULL;
hlist_for_each_entry_rcu(vxlan, vni_head(vs, id), hlist) {
if (vxlan->default_dst.remote_vni == id)
return vxlan;
}
return NULL;
}
static int vxlan_fdb_info(struct sk_buff *skb, struct vxlan_dev *vxlan,
const struct vxlan_fdb *fdb,
u32 portid, u32 seq, int type, unsigned int flags,
const struct vxlan_rdst *rdst)
{
unsigned long now = jiffies;
struct nda_cacheinfo ci;
struct nlmsghdr *nlh;
struct ndmsg *ndm;
bool send_ip, send_eth;
nlh = nlmsg_put(skb, portid, seq, type, sizeof(*ndm), flags);
if (nlh == NULL)
return -EMSGSIZE;
ndm = nlmsg_data(nlh);
memset(ndm, 0, sizeof(*ndm));
send_eth = send_ip = true;
if (type == RTM_GETNEIGH) {
ndm->ndm_family = AF_INET;
send_ip = rdst->remote_ip != htonl(INADDR_ANY);
send_eth = !is_zero_ether_addr(fdb->eth_addr);
} else
ndm->ndm_family = AF_BRIDGE;
ndm->ndm_state = fdb->state;
ndm->ndm_ifindex = vxlan->dev->ifindex;
ndm->ndm_flags = fdb->flags;
ndm->ndm_type = NDA_DST;
if (send_eth && nla_put(skb, NDA_LLADDR, ETH_ALEN, &fdb->eth_addr))
goto nla_put_failure;
if (send_ip && nla_put_be32(skb, NDA_DST, rdst->remote_ip))
goto nla_put_failure;
if (rdst->remote_port && rdst->remote_port != vxlan->dst_port &&
nla_put_be16(skb, NDA_PORT, rdst->remote_port))
goto nla_put_failure;
if (rdst->remote_vni != vxlan->default_dst.remote_vni &&
nla_put_u32(skb, NDA_VNI, rdst->remote_vni))
goto nla_put_failure;
if (rdst->remote_ifindex &&
nla_put_u32(skb, NDA_IFINDEX, rdst->remote_ifindex))
goto nla_put_failure;
ci.ndm_used = jiffies_to_clock_t(now - fdb->used);
ci.ndm_confirmed = 0;
ci.ndm_updated = jiffies_to_clock_t(now - fdb->updated);
ci.ndm_refcnt = 0;
if (nla_put(skb, NDA_CACHEINFO, sizeof(ci), &ci))
goto nla_put_failure;
return nlmsg_end(skb, nlh);
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
static inline size_t vxlan_nlmsg_size(void)
{
return NLMSG_ALIGN(sizeof(struct ndmsg))
+ nla_total_size(ETH_ALEN)
+ nla_total_size(sizeof(__be32))
+ nla_total_size(sizeof(__be16))
+ nla_total_size(sizeof(__be32))
+ nla_total_size(sizeof(__u32))
+ nla_total_size(sizeof(struct nda_cacheinfo));
}
static void vxlan_fdb_notify(struct vxlan_dev *vxlan,
struct vxlan_fdb *fdb, int type)
{
struct net *net = dev_net(vxlan->dev);
struct sk_buff *skb;
int err = -ENOBUFS;
skb = nlmsg_new(vxlan_nlmsg_size(), GFP_ATOMIC);
if (skb == NULL)
goto errout;
err = vxlan_fdb_info(skb, vxlan, fdb, 0, 0, type, 0, first_remote(fdb));
if (err < 0) {
WARN_ON(err == -EMSGSIZE);
kfree_skb(skb);
goto errout;
}
rtnl_notify(skb, net, 0, RTNLGRP_NEIGH, NULL, GFP_ATOMIC);
return;
errout:
if (err < 0)
rtnl_set_sk_err(net, RTNLGRP_NEIGH, err);
}
static void vxlan_ip_miss(struct net_device *dev, __be32 ipa)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_fdb f = {
.state = NUD_STALE,
};
struct vxlan_rdst remote = {
.remote_ip = ipa,
.remote_vni = VXLAN_N_VID,
};
INIT_LIST_HEAD(&f.remotes);
list_add_rcu(&remote.list, &f.remotes);
vxlan_fdb_notify(vxlan, &f, RTM_GETNEIGH);
}
static void vxlan_fdb_miss(struct vxlan_dev *vxlan, const u8 eth_addr[ETH_ALEN])
{
struct vxlan_fdb f = {
.state = NUD_STALE,
};
INIT_LIST_HEAD(&f.remotes);
memcpy(f.eth_addr, eth_addr, ETH_ALEN);
vxlan_fdb_notify(vxlan, &f, RTM_GETNEIGH);
}
static u32 eth_hash(const unsigned char *addr)
{
u64 value = get_unaligned((u64 *)addr);
#ifdef __BIG_ENDIAN
value >>= 16;
#else
value <<= 16;
#endif
return hash_64(value, FDB_HASH_BITS);
}
static inline struct hlist_head *vxlan_fdb_head(struct vxlan_dev *vxlan,
const u8 *mac)
{
return &vxlan->fdb_head[eth_hash(mac)];
}
static struct vxlan_fdb *__vxlan_find_mac(struct vxlan_dev *vxlan,
const u8 *mac)
{
struct hlist_head *head = vxlan_fdb_head(vxlan, mac);
struct vxlan_fdb *f;
hlist_for_each_entry_rcu(f, head, hlist) {
if (compare_ether_addr(mac, f->eth_addr) == 0)
return f;
}
return NULL;
}
static struct vxlan_fdb *vxlan_find_mac(struct vxlan_dev *vxlan,
const u8 *mac)
{
struct vxlan_fdb *f;
f = __vxlan_find_mac(vxlan, mac);
if (f)
f->used = jiffies;
return f;
}
static struct vxlan_rdst *vxlan_fdb_find_rdst(struct vxlan_fdb *f,
__be32 ip, __be16 port,
__u32 vni, __u32 ifindex)
{
struct vxlan_rdst *rd;
list_for_each_entry(rd, &f->remotes, list) {
if (rd->remote_ip == ip &&
rd->remote_port == port &&
rd->remote_vni == vni &&
rd->remote_ifindex == ifindex)
return rd;
}
return NULL;
}
static int vxlan_fdb_append(struct vxlan_fdb *f,
__be32 ip, __be16 port, __u32 vni, __u32 ifindex)
{
struct vxlan_rdst *rd;
rd = vxlan_fdb_find_rdst(f, ip, port, vni, ifindex);
if (rd)
return 0;
rd = kmalloc(sizeof(*rd), GFP_ATOMIC);
if (rd == NULL)
return -ENOBUFS;
rd->remote_ip = ip;
rd->remote_port = port;
rd->remote_vni = vni;
rd->remote_ifindex = ifindex;
list_add_tail_rcu(&rd->list, &f->remotes);
return 1;
}
static int vxlan_fdb_create(struct vxlan_dev *vxlan,
const u8 *mac, __be32 ip,
__u16 state, __u16 flags,
__be16 port, __u32 vni, __u32 ifindex,
__u8 ndm_flags)
{
struct vxlan_fdb *f;
int notify = 0;
f = __vxlan_find_mac(vxlan, mac);
if (f) {
if (flags & NLM_F_EXCL) {
netdev_dbg(vxlan->dev,
"lost race to create %pM\n", mac);
return -EEXIST;
}
if (f->state != state) {
f->state = state;
f->updated = jiffies;
notify = 1;
}
if (f->flags != ndm_flags) {
f->flags = ndm_flags;
f->updated = jiffies;
notify = 1;
}
if ((flags & NLM_F_APPEND) &&
(is_multicast_ether_addr(f->eth_addr) ||
is_zero_ether_addr(f->eth_addr))) {
int rc = vxlan_fdb_append(f, ip, port, vni, ifindex);
if (rc < 0)
return rc;
notify |= rc;
}
} else {
if (!(flags & NLM_F_CREATE))
return -ENOENT;
if (vxlan->addrmax && vxlan->addrcnt >= vxlan->addrmax)
return -ENOSPC;
netdev_dbg(vxlan->dev, "add %pM -> %pI4\n", mac, &ip);
f = kmalloc(sizeof(*f), GFP_ATOMIC);
if (!f)
return -ENOMEM;
notify = 1;
f->state = state;
f->flags = ndm_flags;
f->updated = f->used = jiffies;
INIT_LIST_HEAD(&f->remotes);
memcpy(f->eth_addr, mac, ETH_ALEN);
vxlan_fdb_append(f, ip, port, vni, ifindex);
++vxlan->addrcnt;
hlist_add_head_rcu(&f->hlist,
vxlan_fdb_head(vxlan, mac));
}
if (notify)
vxlan_fdb_notify(vxlan, f, RTM_NEWNEIGH);
return 0;
}
static void vxlan_fdb_free_rdst(struct rcu_head *head)
{
struct vxlan_rdst *rd = container_of(head, struct vxlan_rdst, rcu);
kfree(rd);
}
static void vxlan_fdb_free(struct rcu_head *head)
{
struct vxlan_fdb *f = container_of(head, struct vxlan_fdb, rcu);
struct vxlan_rdst *rd, *nd;
list_for_each_entry_safe(rd, nd, &f->remotes, list)
kfree(rd);
kfree(f);
}
static void vxlan_fdb_destroy(struct vxlan_dev *vxlan, struct vxlan_fdb *f)
{
netdev_dbg(vxlan->dev,
"delete %pM\n", f->eth_addr);
--vxlan->addrcnt;
vxlan_fdb_notify(vxlan, f, RTM_DELNEIGH);
hlist_del_rcu(&f->hlist);
call_rcu(&f->rcu, vxlan_fdb_free);
}
static int vxlan_fdb_parse(struct nlattr *tb[], struct vxlan_dev *vxlan,
__be32 *ip, __be16 *port, u32 *vni, u32 *ifindex)
{
struct net *net = dev_net(vxlan->dev);
if (tb[NDA_DST]) {
if (nla_len(tb[NDA_DST]) != sizeof(__be32))
return -EAFNOSUPPORT;
*ip = nla_get_be32(tb[NDA_DST]);
} else {
*ip = htonl(INADDR_ANY);
}
if (tb[NDA_PORT]) {
if (nla_len(tb[NDA_PORT]) != sizeof(__be16))
return -EINVAL;
*port = nla_get_be16(tb[NDA_PORT]);
} else {
*port = vxlan->dst_port;
}
if (tb[NDA_VNI]) {
if (nla_len(tb[NDA_VNI]) != sizeof(u32))
return -EINVAL;
*vni = nla_get_u32(tb[NDA_VNI]);
} else {
*vni = vxlan->default_dst.remote_vni;
}
if (tb[NDA_IFINDEX]) {
struct net_device *tdev;
if (nla_len(tb[NDA_IFINDEX]) != sizeof(u32))
return -EINVAL;
*ifindex = nla_get_u32(tb[NDA_IFINDEX]);
tdev = dev_get_by_index(net, *ifindex);
if (!tdev)
return -EADDRNOTAVAIL;
dev_put(tdev);
} else {
*ifindex = 0;
}
return 0;
}
static int vxlan_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 flags)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
__be32 ip;
__be16 port;
u32 vni, ifindex;
int err;
if (!(ndm->ndm_state & (NUD_PERMANENT|NUD_REACHABLE))) {
pr_info("RTM_NEWNEIGH with invalid state %#x\n",
ndm->ndm_state);
return -EINVAL;
}
if (tb[NDA_DST] == NULL)
return -EINVAL;
err = vxlan_fdb_parse(tb, vxlan, &ip, &port, &vni, &ifindex);
if (err)
return err;
spin_lock_bh(&vxlan->hash_lock);
err = vxlan_fdb_create(vxlan, addr, ip, ndm->ndm_state, flags,
port, vni, ifindex, ndm->ndm_flags);
spin_unlock_bh(&vxlan->hash_lock);
return err;
}
static int vxlan_fdb_delete(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_fdb *f;
struct vxlan_rdst *rd = NULL;
__be32 ip;
__be16 port;
u32 vni, ifindex;
int err;
err = vxlan_fdb_parse(tb, vxlan, &ip, &port, &vni, &ifindex);
if (err)
return err;
err = -ENOENT;
spin_lock_bh(&vxlan->hash_lock);
f = vxlan_find_mac(vxlan, addr);
if (!f)
goto out;
if (ip != htonl(INADDR_ANY)) {
rd = vxlan_fdb_find_rdst(f, ip, port, vni, ifindex);
if (!rd)
goto out;
}
err = 0;
if (rd && !list_is_singular(&f->remotes)) {
list_del_rcu(&rd->list);
call_rcu(&rd->rcu, vxlan_fdb_free_rdst);
goto out;
}
vxlan_fdb_destroy(vxlan, f);
out:
spin_unlock_bh(&vxlan->hash_lock);
return err;
}
static int vxlan_fdb_dump(struct sk_buff *skb, struct netlink_callback *cb,
struct net_device *dev, int idx)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
unsigned int h;
for (h = 0; h < FDB_HASH_SIZE; ++h) {
struct vxlan_fdb *f;
int err;
hlist_for_each_entry_rcu(f, &vxlan->fdb_head[h], hlist) {
struct vxlan_rdst *rd;
if (idx < cb->args[0])
goto skip;
list_for_each_entry_rcu(rd, &f->remotes, list) {
err = vxlan_fdb_info(skb, vxlan, f,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq,
RTM_NEWNEIGH,
NLM_F_MULTI, rd);
if (err < 0)
goto out;
}
skip:
++idx;
}
}
out:
return idx;
}
static bool vxlan_snoop(struct net_device *dev,
__be32 src_ip, const u8 *src_mac)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_fdb *f;
f = vxlan_find_mac(vxlan, src_mac);
if (likely(f)) {
struct vxlan_rdst *rdst = first_remote(f);
if (likely(rdst->remote_ip == src_ip))
return false;
if (f->state & NUD_NOARP)
return true;
if (net_ratelimit())
netdev_info(dev,
"%pM migrated from %pI4 to %pI4\n",
src_mac, &rdst->remote_ip, &src_ip);
rdst->remote_ip = src_ip;
f->updated = jiffies;
vxlan_fdb_notify(vxlan, f, RTM_NEWNEIGH);
} else {
spin_lock(&vxlan->hash_lock);
if (netif_running(dev))
vxlan_fdb_create(vxlan, src_mac, src_ip,
NUD_REACHABLE,
NLM_F_EXCL|NLM_F_CREATE,
vxlan->dst_port,
vxlan->default_dst.remote_vni,
0, NTF_SELF);
spin_unlock(&vxlan->hash_lock);
}
return false;
}
static bool vxlan_group_used(struct vxlan_net *vn, __be32 remote_ip)
{
struct vxlan_dev *vxlan;
list_for_each_entry(vxlan, &vn->vxlan_list, next) {
if (!netif_running(vxlan->dev))
continue;
if (vxlan->default_dst.remote_ip == remote_ip)
return true;
}
return false;
}
static void vxlan_sock_hold(struct vxlan_sock *vs)
{
atomic_inc(&vs->refcnt);
}
static void vxlan_sock_release(struct vxlan_net *vn, struct vxlan_sock *vs)
{
if (!atomic_dec_and_test(&vs->refcnt))
return;
spin_lock(&vn->sock_lock);
hlist_del_rcu(&vs->hlist);
spin_unlock(&vn->sock_lock);
queue_work(vxlan_wq, &vs->del_work);
}
static void vxlan_igmp_join(struct work_struct *work)
{
struct vxlan_dev *vxlan = container_of(work, struct vxlan_dev, igmp_join);
struct vxlan_net *vn = net_generic(dev_net(vxlan->dev), vxlan_net_id);
struct vxlan_sock *vs = vxlan->vn_sock;
struct sock *sk = vs->sock->sk;
struct ip_mreqn mreq = {
.imr_multiaddr.s_addr = vxlan->default_dst.remote_ip,
.imr_ifindex = vxlan->default_dst.remote_ifindex,
};
lock_sock(sk);
ip_mc_join_group(sk, &mreq);
release_sock(sk);
vxlan_sock_release(vn, vs);
dev_put(vxlan->dev);
}
static void vxlan_igmp_leave(struct work_struct *work)
{
struct vxlan_dev *vxlan = container_of(work, struct vxlan_dev, igmp_leave);
struct vxlan_net *vn = net_generic(dev_net(vxlan->dev), vxlan_net_id);
struct vxlan_sock *vs = vxlan->vn_sock;
struct sock *sk = vs->sock->sk;
struct ip_mreqn mreq = {
.imr_multiaddr.s_addr = vxlan->default_dst.remote_ip,
.imr_ifindex = vxlan->default_dst.remote_ifindex,
};
lock_sock(sk);
ip_mc_leave_group(sk, &mreq);
release_sock(sk);
vxlan_sock_release(vn, vs);
dev_put(vxlan->dev);
}
static int vxlan_udp_encap_recv(struct sock *sk, struct sk_buff *skb)
{
struct iphdr *oip;
struct vxlanhdr *vxh;
struct vxlan_dev *vxlan;
struct pcpu_tstats *stats;
__be16 port;
__u32 vni;
int err;
__skb_pull(skb, sizeof(struct udphdr));
if (!pskb_may_pull(skb, sizeof(struct vxlanhdr)))
goto error;
vxh = (struct vxlanhdr *) skb->data;
if (vxh->vx_flags != htonl(VXLAN_FLAGS) ||
(vxh->vx_vni & htonl(0xff))) {
netdev_dbg(skb->dev, "invalid vxlan flags=%#x vni=%#x\n",
ntohl(vxh->vx_flags), ntohl(vxh->vx_vni));
goto error;
}
__skb_pull(skb, sizeof(struct vxlanhdr));
vni = ntohl(vxh->vx_vni) >> 8;
port = inet_sk(sk)->inet_sport;
vxlan = vxlan_find_vni(sock_net(sk), vni, port);
if (!vxlan) {
netdev_dbg(skb->dev, "unknown vni %d port %u\n",
vni, ntohs(port));
goto drop;
}
if (!pskb_may_pull(skb, ETH_HLEN)) {
vxlan->dev->stats.rx_length_errors++;
vxlan->dev->stats.rx_errors++;
goto drop;
}
skb_reset_mac_header(skb);
oip = ip_hdr(skb);
skb->protocol = eth_type_trans(skb, vxlan->dev);
if (compare_ether_addr(eth_hdr(skb)->h_source,
vxlan->dev->dev_addr) == 0)
goto drop;
if ((vxlan->flags & VXLAN_F_LEARN) &&
vxlan_snoop(skb->dev, oip->saddr, eth_hdr(skb)->h_source))
goto drop;
__skb_tunnel_rx(skb, vxlan->dev);
skb_reset_network_header(skb);
if (skb->ip_summed != CHECKSUM_UNNECESSARY || !skb->encapsulation ||
!(vxlan->dev->features & NETIF_F_RXCSUM))
skb->ip_summed = CHECKSUM_NONE;
skb->encapsulation = 0;
err = IP_ECN_decapsulate(oip, skb);
if (unlikely(err)) {
if (log_ecn_error)
net_info_ratelimited("non-ECT from %pI4 with TOS=%#x\n",
&oip->saddr, oip->tos);
if (err > 1) {
++vxlan->dev->stats.rx_frame_errors;
++vxlan->dev->stats.rx_errors;
goto drop;
}
}
stats = this_cpu_ptr(vxlan->dev->tstats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets++;
stats->rx_bytes += skb->len;
u64_stats_update_end(&stats->syncp);
netif_rx(skb);
return 0;
error:
__skb_push(skb, sizeof(struct udphdr));
return 1;
drop:
kfree_skb(skb);
return 0;
}
static int arp_reduce(struct net_device *dev, struct sk_buff *skb)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct arphdr *parp;
u8 *arpptr, *sha;
__be32 sip, tip;
struct neighbour *n;
if (dev->flags & IFF_NOARP)
goto out;
if (!pskb_may_pull(skb, arp_hdr_len(dev))) {
dev->stats.tx_dropped++;
goto out;
}
parp = arp_hdr(skb);
if ((parp->ar_hrd != htons(ARPHRD_ETHER) &&
parp->ar_hrd != htons(ARPHRD_IEEE802)) ||
parp->ar_pro != htons(ETH_P_IP) ||
parp->ar_op != htons(ARPOP_REQUEST) ||
parp->ar_hln != dev->addr_len ||
parp->ar_pln != 4)
goto out;
arpptr = (u8 *)parp + sizeof(struct arphdr);
sha = arpptr;
arpptr += dev->addr_len;
memcpy(&sip, arpptr, sizeof(sip));
arpptr += sizeof(sip);
arpptr += dev->addr_len;
memcpy(&tip, arpptr, sizeof(tip));
if (ipv4_is_loopback(tip) ||
ipv4_is_multicast(tip))
goto out;
n = neigh_lookup(&arp_tbl, &tip, dev);
if (n) {
struct vxlan_fdb *f;
struct sk_buff *reply;
if (!(n->nud_state & NUD_CONNECTED)) {
neigh_release(n);
goto out;
}
f = vxlan_find_mac(vxlan, n->ha);
if (f && first_remote(f)->remote_ip == htonl(INADDR_ANY)) {
neigh_release(n);
goto out;
}
reply = arp_create(ARPOP_REPLY, ETH_P_ARP, sip, dev, tip, sha,
n->ha, sha);
neigh_release(n);
skb_reset_mac_header(reply);
__skb_pull(reply, skb_network_offset(reply));
reply->ip_summed = CHECKSUM_UNNECESSARY;
reply->pkt_type = PACKET_HOST;
if (netif_rx_ni(reply) == NET_RX_DROP)
dev->stats.rx_dropped++;
} else if (vxlan->flags & VXLAN_F_L3MISS)
vxlan_ip_miss(dev, tip);
out:
consume_skb(skb);
return NETDEV_TX_OK;
}
static bool route_shortcircuit(struct net_device *dev, struct sk_buff *skb)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct neighbour *n;
struct iphdr *pip;
if (is_multicast_ether_addr(eth_hdr(skb)->h_dest))
return false;
n = NULL;
switch (ntohs(eth_hdr(skb)->h_proto)) {
case ETH_P_IP:
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
return false;
pip = ip_hdr(skb);
n = neigh_lookup(&arp_tbl, &pip->daddr, dev);
break;
default:
return false;
}
if (n) {
bool diff;
diff = compare_ether_addr(eth_hdr(skb)->h_dest, n->ha) != 0;
if (diff) {
memcpy(eth_hdr(skb)->h_source, eth_hdr(skb)->h_dest,
dev->addr_len);
memcpy(eth_hdr(skb)->h_dest, n->ha, dev->addr_len);
}
neigh_release(n);
return diff;
} else if (vxlan->flags & VXLAN_F_L3MISS)
vxlan_ip_miss(dev, pip->daddr);
return false;
}
static void vxlan_sock_put(struct sk_buff *skb)
{
sock_put(skb->sk);
}
static void vxlan_set_owner(struct net_device *dev, struct sk_buff *skb)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct sock *sk = vxlan->vn_sock->sock->sk;
skb_orphan(skb);
sock_hold(sk);
skb->sk = sk;
skb->destructor = vxlan_sock_put;
}
static __be16 vxlan_src_port(const struct vxlan_dev *vxlan, struct sk_buff *skb)
{
unsigned int range = (vxlan->port_max - vxlan->port_min) + 1;
u32 hash;
hash = skb_get_rxhash(skb);
if (!hash)
hash = jhash(skb->data, 2 * ETH_ALEN,
(__force u32) skb->protocol);
return htons((((u64) hash * range) >> 32) + vxlan->port_min);
}
static int handle_offloads(struct sk_buff *skb)
{
if (skb_is_gso(skb)) {
int err = skb_unclone(skb, GFP_ATOMIC);
if (unlikely(err))
return err;
skb_shinfo(skb)->gso_type |= SKB_GSO_UDP_TUNNEL;
} else if (skb->ip_summed != CHECKSUM_PARTIAL)
skb->ip_summed = CHECKSUM_NONE;
return 0;
}
static void vxlan_encap_bypass(struct sk_buff *skb, struct vxlan_dev *src_vxlan,
struct vxlan_dev *dst_vxlan)
{
struct pcpu_tstats *tx_stats = this_cpu_ptr(src_vxlan->dev->tstats);
struct pcpu_tstats *rx_stats = this_cpu_ptr(dst_vxlan->dev->tstats);
skb->pkt_type = PACKET_HOST;
skb->encapsulation = 0;
skb->dev = dst_vxlan->dev;
__skb_pull(skb, skb_network_offset(skb));
if (dst_vxlan->flags & VXLAN_F_LEARN)
vxlan_snoop(skb->dev, htonl(INADDR_LOOPBACK),
eth_hdr(skb)->h_source);
u64_stats_update_begin(&tx_stats->syncp);
tx_stats->tx_packets++;
tx_stats->tx_bytes += skb->len;
u64_stats_update_end(&tx_stats->syncp);
if (netif_rx(skb) == NET_RX_SUCCESS) {
u64_stats_update_begin(&rx_stats->syncp);
rx_stats->rx_packets++;
rx_stats->rx_bytes += skb->len;
u64_stats_update_end(&rx_stats->syncp);
} else {
skb->dev->stats.rx_dropped++;
}
}
static void vxlan_xmit_one(struct sk_buff *skb, struct net_device *dev,
struct vxlan_rdst *rdst, bool did_rsc)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct rtable *rt;
const struct iphdr *old_iph;
struct vxlanhdr *vxh;
struct udphdr *uh;
struct flowi4 fl4;
__be32 dst;
__be16 src_port, dst_port;
u32 vni;
__be16 df = 0;
__u8 tos, ttl;
int err;
dst_port = rdst->remote_port ? rdst->remote_port : vxlan->dst_port;
vni = rdst->remote_vni;
dst = rdst->remote_ip;
if (!dst) {
if (did_rsc) {
vxlan_encap_bypass(skb, vxlan, vxlan);
return;
}
goto drop;
}
if (!skb->encapsulation) {
skb_reset_inner_headers(skb);
skb->encapsulation = 1;
}
if (skb_cow_head(skb, VXLAN_HEADROOM))
goto drop;
old_iph = ip_hdr(skb);
ttl = vxlan->ttl;
if (!ttl && IN_MULTICAST(ntohl(dst)))
ttl = 1;
tos = vxlan->tos;
if (tos == 1)
tos = ip_tunnel_get_dsfield(old_iph, skb);
src_port = vxlan_src_port(vxlan, skb);
memset(&fl4, 0, sizeof(fl4));
fl4.flowi4_oif = rdst->remote_ifindex;
fl4.flowi4_tos = RT_TOS(tos);
fl4.daddr = dst;
fl4.saddr = vxlan->saddr;
rt = ip_route_output_key(dev_net(dev), &fl4);
if (IS_ERR(rt)) {
netdev_dbg(dev, "no route to %pI4\n", &dst);
dev->stats.tx_carrier_errors++;
goto tx_error;
}
if (rt->dst.dev == dev) {
netdev_dbg(dev, "circular route to %pI4\n", &dst);
ip_rt_put(rt);
dev->stats.collisions++;
goto tx_error;
}
if (rt->rt_flags & RTCF_LOCAL &&
!(rt->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST))) {
struct vxlan_dev *dst_vxlan;
ip_rt_put(rt);
dst_vxlan = vxlan_find_vni(dev_net(dev), vni, dst_port);
if (!dst_vxlan)
goto tx_error;
vxlan_encap_bypass(skb, vxlan, dst_vxlan);
return;
}
vxh = (struct vxlanhdr *) __skb_push(skb, sizeof(*vxh));
vxh->vx_flags = htonl(VXLAN_FLAGS);
vxh->vx_vni = htonl(vni << 8);
__skb_push(skb, sizeof(*uh));
skb_reset_transport_header(skb);
uh = udp_hdr(skb);
uh->dest = dst_port;
uh->source = src_port;
uh->len = htons(skb->len);
uh->check = 0;
vxlan_set_owner(dev, skb);
if (handle_offloads(skb))
goto drop;
tos = ip_tunnel_ecn_encap(tos, old_iph, skb);
ttl = ttl ? : ip4_dst_hoplimit(&rt->dst);
err = iptunnel_xmit(dev_net(dev), rt, skb, fl4.saddr, dst,
IPPROTO_UDP, tos, ttl, df);
iptunnel_xmit_stats(err, &dev->stats, dev->tstats);
return;
drop:
dev->stats.tx_dropped++;
goto tx_free;
tx_error:
dev->stats.tx_errors++;
tx_free:
dev_kfree_skb(skb);
}
static netdev_tx_t vxlan_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct ethhdr *eth;
bool did_rsc = false;
struct vxlan_rdst *rdst;
struct vxlan_fdb *f;
skb_reset_mac_header(skb);
eth = eth_hdr(skb);
if ((vxlan->flags & VXLAN_F_PROXY) && ntohs(eth->h_proto) == ETH_P_ARP)
return arp_reduce(dev, skb);
f = vxlan_find_mac(vxlan, eth->h_dest);
did_rsc = false;
if (f && (f->flags & NTF_ROUTER) && (vxlan->flags & VXLAN_F_RSC) &&
ntohs(eth->h_proto) == ETH_P_IP) {
did_rsc = route_shortcircuit(dev, skb);
if (did_rsc)
f = vxlan_find_mac(vxlan, eth->h_dest);
}
if (f == NULL) {
f = vxlan_find_mac(vxlan, all_zeros_mac);
if (f == NULL) {
if ((vxlan->flags & VXLAN_F_L2MISS) &&
!is_multicast_ether_addr(eth->h_dest))
vxlan_fdb_miss(vxlan, eth->h_dest);
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
}
list_for_each_entry_rcu(rdst, &f->remotes, list) {
struct sk_buff *skb1;
skb1 = skb_clone(skb, GFP_ATOMIC);
if (skb1)
vxlan_xmit_one(skb1, dev, rdst, did_rsc);
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void vxlan_cleanup(unsigned long arg)
{
struct vxlan_dev *vxlan = (struct vxlan_dev *) arg;
unsigned long next_timer = jiffies + FDB_AGE_INTERVAL;
unsigned int h;
if (!netif_running(vxlan->dev))
return;
spin_lock_bh(&vxlan->hash_lock);
for (h = 0; h < FDB_HASH_SIZE; ++h) {
struct hlist_node *p, *n;
hlist_for_each_safe(p, n, &vxlan->fdb_head[h]) {
struct vxlan_fdb *f
= container_of(p, struct vxlan_fdb, hlist);
unsigned long timeout;
if (f->state & NUD_PERMANENT)
continue;
timeout = f->used + vxlan->age_interval * HZ;
if (time_before_eq(timeout, jiffies)) {
netdev_dbg(vxlan->dev,
"garbage collect %pM\n",
f->eth_addr);
f->state = NUD_STALE;
vxlan_fdb_destroy(vxlan, f);
} else if (time_before(timeout, next_timer))
next_timer = timeout;
}
}
spin_unlock_bh(&vxlan->hash_lock);
mod_timer(&vxlan->age_timer, next_timer);
}
static int vxlan_init(struct net_device *dev)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_net *vn = net_generic(dev_net(dev), vxlan_net_id);
struct vxlan_sock *vs;
__u32 vni = vxlan->default_dst.remote_vni;
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
spin_lock(&vn->sock_lock);
vs = vxlan_find_port(dev_net(dev), vxlan->dst_port);
if (vs) {
atomic_inc(&vs->refcnt);
vxlan->vn_sock = vs;
hlist_add_head_rcu(&vxlan->hlist, vni_head(vs, vni));
} else {
dev_hold(dev);
queue_work(vxlan_wq, &vxlan->sock_work);
}
spin_unlock(&vn->sock_lock);
return 0;
}
static void vxlan_fdb_delete_default(struct vxlan_dev *vxlan)
{
struct vxlan_fdb *f;
spin_lock_bh(&vxlan->hash_lock);
f = __vxlan_find_mac(vxlan, all_zeros_mac);
if (f)
vxlan_fdb_destroy(vxlan, f);
spin_unlock_bh(&vxlan->hash_lock);
}
static void vxlan_uninit(struct net_device *dev)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_net *vn = net_generic(dev_net(dev), vxlan_net_id);
struct vxlan_sock *vs = vxlan->vn_sock;
vxlan_fdb_delete_default(vxlan);
if (vs)
vxlan_sock_release(vn, vs);
free_percpu(dev->tstats);
}
static int vxlan_open(struct net_device *dev)
{
struct vxlan_net *vn = net_generic(dev_net(dev), vxlan_net_id);
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_sock *vs = vxlan->vn_sock;
if (!vs)
return -ENOTCONN;
if (IN_MULTICAST(ntohl(vxlan->default_dst.remote_ip)) &&
vxlan_group_used(vn, vxlan->default_dst.remote_ip)) {
vxlan_sock_hold(vs);
dev_hold(dev);
queue_work(vxlan_wq, &vxlan->igmp_join);
}
if (vxlan->age_interval)
mod_timer(&vxlan->age_timer, jiffies + FDB_AGE_INTERVAL);
return 0;
}
static void vxlan_flush(struct vxlan_dev *vxlan)
{
unsigned int h;
spin_lock_bh(&vxlan->hash_lock);
for (h = 0; h < FDB_HASH_SIZE; ++h) {
struct hlist_node *p, *n;
hlist_for_each_safe(p, n, &vxlan->fdb_head[h]) {
struct vxlan_fdb *f
= container_of(p, struct vxlan_fdb, hlist);
if (!is_zero_ether_addr(f->eth_addr))
vxlan_fdb_destroy(vxlan, f);
}
}
spin_unlock_bh(&vxlan->hash_lock);
}
static int vxlan_stop(struct net_device *dev)
{
struct vxlan_net *vn = net_generic(dev_net(dev), vxlan_net_id);
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_sock *vs = vxlan->vn_sock;
if (vs && IN_MULTICAST(ntohl(vxlan->default_dst.remote_ip)) &&
! vxlan_group_used(vn, vxlan->default_dst.remote_ip)) {
vxlan_sock_hold(vs);
dev_hold(dev);
queue_work(vxlan_wq, &vxlan->igmp_leave);
}
del_timer_sync(&vxlan->age_timer);
vxlan_flush(vxlan);
return 0;
}
static void vxlan_set_multicast_list(struct net_device *dev)
{
}
static void vxlan_setup(struct net_device *dev)
{
struct vxlan_dev *vxlan = netdev_priv(dev);
unsigned int h;
int low, high;
eth_hw_addr_random(dev);
ether_setup(dev);
dev->hard_header_len = ETH_HLEN + VXLAN_HEADROOM;
dev->netdev_ops = &vxlan_netdev_ops;
dev->destructor = free_netdev;
SET_NETDEV_DEVTYPE(dev, &vxlan_type);
dev->tx_queue_len = 0;
dev->features |= NETIF_F_LLTX;
dev->features |= NETIF_F_NETNS_LOCAL;
dev->features |= NETIF_F_SG | NETIF_F_HW_CSUM;
dev->features |= NETIF_F_RXCSUM;
dev->features |= NETIF_F_GSO_SOFTWARE;
dev->hw_features |= NETIF_F_SG | NETIF_F_HW_CSUM | NETIF_F_RXCSUM;
dev->hw_features |= NETIF_F_GSO_SOFTWARE;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
dev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
INIT_LIST_HEAD(&vxlan->next);
spin_lock_init(&vxlan->hash_lock);
INIT_WORK(&vxlan->igmp_join, vxlan_igmp_join);
INIT_WORK(&vxlan->igmp_leave, vxlan_igmp_leave);
INIT_WORK(&vxlan->sock_work, vxlan_sock_work);
init_timer_deferrable(&vxlan->age_timer);
vxlan->age_timer.function = vxlan_cleanup;
vxlan->age_timer.data = (unsigned long) vxlan;
inet_get_local_port_range(&low, &high);
vxlan->port_min = low;
vxlan->port_max = high;
vxlan->dst_port = htons(vxlan_port);
vxlan->dev = dev;
for (h = 0; h < FDB_HASH_SIZE; ++h)
INIT_HLIST_HEAD(&vxlan->fdb_head[h]);
}
static int vxlan_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN) {
pr_debug("invalid link address (not ethernet)\n");
return -EINVAL;
}
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS]))) {
pr_debug("invalid all zero ethernet address\n");
return -EADDRNOTAVAIL;
}
}
if (!data)
return -EINVAL;
if (data[IFLA_VXLAN_ID]) {
__u32 id = nla_get_u32(data[IFLA_VXLAN_ID]);
if (id >= VXLAN_VID_MASK)
return -ERANGE;
}
if (data[IFLA_VXLAN_PORT_RANGE]) {
const struct ifla_vxlan_port_range *p
= nla_data(data[IFLA_VXLAN_PORT_RANGE]);
if (ntohs(p->high) < ntohs(p->low)) {
pr_debug("port range %u .. %u not valid\n",
ntohs(p->low), ntohs(p->high));
return -EINVAL;
}
}
return 0;
}
static void vxlan_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->version, VXLAN_VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->driver, "vxlan", sizeof(drvinfo->driver));
}
static void vxlan_del_work(struct work_struct *work)
{
struct vxlan_sock *vs = container_of(work, struct vxlan_sock, del_work);
sk_release_kernel(vs->sock->sk);
kfree_rcu(vs, rcu);
}
static struct vxlan_sock *vxlan_socket_create(struct net *net, __be16 port)
{
struct vxlan_sock *vs;
struct sock *sk;
struct sockaddr_in vxlan_addr = {
.sin_family = AF_INET,
.sin_addr.s_addr = htonl(INADDR_ANY),
.sin_port = port,
};
int rc;
unsigned int h;
vs = kmalloc(sizeof(*vs), GFP_KERNEL);
if (!vs)
return ERR_PTR(-ENOMEM);
for (h = 0; h < VNI_HASH_SIZE; ++h)
INIT_HLIST_HEAD(&vs->vni_list[h]);
INIT_WORK(&vs->del_work, vxlan_del_work);
rc = sock_create_kern(AF_INET, SOCK_DGRAM, IPPROTO_UDP, &vs->sock);
if (rc < 0) {
pr_debug("UDP socket create failed\n");
kfree(vs);
return ERR_PTR(rc);
}
sk = vs->sock->sk;
sk_change_net(sk, net);
rc = kernel_bind(vs->sock, (struct sockaddr *) &vxlan_addr,
sizeof(vxlan_addr));
if (rc < 0) {
pr_debug("bind for UDP socket %pI4:%u (%d)\n",
&vxlan_addr.sin_addr, ntohs(vxlan_addr.sin_port), rc);
sk_release_kernel(sk);
kfree(vs);
return ERR_PTR(rc);
}
inet_sk(sk)->mc_loop = 0;
udp_sk(sk)->encap_type = 1;
udp_sk(sk)->encap_rcv = vxlan_udp_encap_recv;
udp_encap_enable();
atomic_set(&vs->refcnt, 1);
return vs;
}
static void vxlan_sock_work(struct work_struct *work)
{
struct vxlan_dev *vxlan
= container_of(work, struct vxlan_dev, sock_work);
struct net_device *dev = vxlan->dev;
struct net *net = dev_net(dev);
__u32 vni = vxlan->default_dst.remote_vni;
__be16 port = vxlan->dst_port;
struct vxlan_net *vn = net_generic(net, vxlan_net_id);
struct vxlan_sock *nvs, *ovs;
nvs = vxlan_socket_create(net, port);
if (IS_ERR(nvs)) {
netdev_err(vxlan->dev, "Can not create UDP socket, %ld\n",
PTR_ERR(nvs));
goto out;
}
spin_lock(&vn->sock_lock);
ovs = vxlan_find_port(net, port);
if (ovs) {
atomic_inc(&ovs->refcnt);
vxlan->vn_sock = ovs;
hlist_add_head_rcu(&vxlan->hlist, vni_head(ovs, vni));
spin_unlock(&vn->sock_lock);
sk_release_kernel(nvs->sock->sk);
kfree(nvs);
} else {
vxlan->vn_sock = nvs;
hlist_add_head_rcu(&nvs->hlist, vs_head(net, port));
hlist_add_head_rcu(&vxlan->hlist, vni_head(nvs, vni));
spin_unlock(&vn->sock_lock);
}
out:
dev_put(dev);
}
static int vxlan_newlink(struct net *net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct vxlan_net *vn = net_generic(net, vxlan_net_id);
struct vxlan_dev *vxlan = netdev_priv(dev);
struct vxlan_rdst *dst = &vxlan->default_dst;
__u32 vni;
int err;
if (!data[IFLA_VXLAN_ID])
return -EINVAL;
vni = nla_get_u32(data[IFLA_VXLAN_ID]);
dst->remote_vni = vni;
if (data[IFLA_VXLAN_GROUP])
dst->remote_ip = nla_get_be32(data[IFLA_VXLAN_GROUP]);
if (data[IFLA_VXLAN_LOCAL])
vxlan->saddr = nla_get_be32(data[IFLA_VXLAN_LOCAL]);
if (data[IFLA_VXLAN_LINK] &&
(dst->remote_ifindex = nla_get_u32(data[IFLA_VXLAN_LINK]))) {
struct net_device *lowerdev
= __dev_get_by_index(net, dst->remote_ifindex);
if (!lowerdev) {
pr_info("ifindex %d does not exist\n", dst->remote_ifindex);
return -ENODEV;
}
if (!tb[IFLA_MTU])
dev->mtu = lowerdev->mtu - VXLAN_HEADROOM;
dev->hard_header_len = lowerdev->hard_header_len +
VXLAN_HEADROOM;
}
if (data[IFLA_VXLAN_TOS])
vxlan->tos = nla_get_u8(data[IFLA_VXLAN_TOS]);
if (data[IFLA_VXLAN_TTL])
vxlan->ttl = nla_get_u8(data[IFLA_VXLAN_TTL]);
if (!data[IFLA_VXLAN_LEARNING] || nla_get_u8(data[IFLA_VXLAN_LEARNING]))
vxlan->flags |= VXLAN_F_LEARN;
if (data[IFLA_VXLAN_AGEING])
vxlan->age_interval = nla_get_u32(data[IFLA_VXLAN_AGEING]);
else
vxlan->age_interval = FDB_AGE_DEFAULT;
if (data[IFLA_VXLAN_PROXY] && nla_get_u8(data[IFLA_VXLAN_PROXY]))
vxlan->flags |= VXLAN_F_PROXY;
if (data[IFLA_VXLAN_RSC] && nla_get_u8(data[IFLA_VXLAN_RSC]))
vxlan->flags |= VXLAN_F_RSC;
if (data[IFLA_VXLAN_L2MISS] && nla_get_u8(data[IFLA_VXLAN_L2MISS]))
vxlan->flags |= VXLAN_F_L2MISS;
if (data[IFLA_VXLAN_L3MISS] && nla_get_u8(data[IFLA_VXLAN_L3MISS]))
vxlan->flags |= VXLAN_F_L3MISS;
if (data[IFLA_VXLAN_LIMIT])
vxlan->addrmax = nla_get_u32(data[IFLA_VXLAN_LIMIT]);
if (data[IFLA_VXLAN_PORT_RANGE]) {
const struct ifla_vxlan_port_range *p
= nla_data(data[IFLA_VXLAN_PORT_RANGE]);
vxlan->port_min = ntohs(p->low);
vxlan->port_max = ntohs(p->high);
}
if (data[IFLA_VXLAN_PORT])
vxlan->dst_port = nla_get_be16(data[IFLA_VXLAN_PORT]);
if (vxlan_find_vni(net, vni, vxlan->dst_port)) {
pr_info("duplicate VNI %u\n", vni);
return -EEXIST;
}
SET_ETHTOOL_OPS(dev, &vxlan_ethtool_ops);
err = vxlan_fdb_create(vxlan, all_zeros_mac,
vxlan->default_dst.remote_ip,
NUD_REACHABLE|NUD_PERMANENT,
NLM_F_EXCL|NLM_F_CREATE,
vxlan->dst_port, vxlan->default_dst.remote_vni,
vxlan->default_dst.remote_ifindex, NTF_SELF);
if (err)
return err;
err = register_netdevice(dev);
if (err) {
vxlan_fdb_delete_default(vxlan);
return err;
}
list_add(&vxlan->next, &vn->vxlan_list);
return 0;
}
static void vxlan_dellink(struct net_device *dev, struct list_head *head)
{
struct vxlan_net *vn = net_generic(dev_net(dev), vxlan_net_id);
struct vxlan_dev *vxlan = netdev_priv(dev);
spin_lock(&vn->sock_lock);
hlist_del_rcu(&vxlan->hlist);
spin_unlock(&vn->sock_lock);
list_del(&vxlan->next);
unregister_netdevice_queue(dev, head);
}
static size_t vxlan_get_size(const struct net_device *dev)
{
return nla_total_size(sizeof(__u32)) +
nla_total_size(sizeof(__be32)) +
nla_total_size(sizeof(__u32)) +
nla_total_size(sizeof(__be32))+
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u8)) +
nla_total_size(sizeof(__u32)) +
nla_total_size(sizeof(__u32)) +
nla_total_size(sizeof(struct ifla_vxlan_port_range)) +
nla_total_size(sizeof(__be16))+
0;
}
static int vxlan_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
const struct vxlan_dev *vxlan = netdev_priv(dev);
const struct vxlan_rdst *dst = &vxlan->default_dst;
struct ifla_vxlan_port_range ports = {
.low = htons(vxlan->port_min),
.high = htons(vxlan->port_max),
};
if (nla_put_u32(skb, IFLA_VXLAN_ID, dst->remote_vni))
goto nla_put_failure;
if (dst->remote_ip && nla_put_be32(skb, IFLA_VXLAN_GROUP, dst->remote_ip))
goto nla_put_failure;
if (dst->remote_ifindex && nla_put_u32(skb, IFLA_VXLAN_LINK, dst->remote_ifindex))
goto nla_put_failure;
if (vxlan->saddr && nla_put_be32(skb, IFLA_VXLAN_LOCAL, vxlan->saddr))
goto nla_put_failure;
if (nla_put_u8(skb, IFLA_VXLAN_TTL, vxlan->ttl) ||
nla_put_u8(skb, IFLA_VXLAN_TOS, vxlan->tos) ||
nla_put_u8(skb, IFLA_VXLAN_LEARNING,
!!(vxlan->flags & VXLAN_F_LEARN)) ||
nla_put_u8(skb, IFLA_VXLAN_PROXY,
!!(vxlan->flags & VXLAN_F_PROXY)) ||
nla_put_u8(skb, IFLA_VXLAN_RSC, !!(vxlan->flags & VXLAN_F_RSC)) ||
nla_put_u8(skb, IFLA_VXLAN_L2MISS,
!!(vxlan->flags & VXLAN_F_L2MISS)) ||
nla_put_u8(skb, IFLA_VXLAN_L3MISS,
!!(vxlan->flags & VXLAN_F_L3MISS)) ||
nla_put_u32(skb, IFLA_VXLAN_AGEING, vxlan->age_interval) ||
nla_put_u32(skb, IFLA_VXLAN_LIMIT, vxlan->addrmax) ||
nla_put_be16(skb, IFLA_VXLAN_PORT, vxlan->dst_port))
goto nla_put_failure;
if (nla_put(skb, IFLA_VXLAN_PORT_RANGE, sizeof(ports), &ports))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static __net_init int vxlan_init_net(struct net *net)
{
struct vxlan_net *vn = net_generic(net, vxlan_net_id);
unsigned int h;
INIT_LIST_HEAD(&vn->vxlan_list);
spin_lock_init(&vn->sock_lock);
for (h = 0; h < PORT_HASH_SIZE; ++h)
INIT_HLIST_HEAD(&vn->sock_list[h]);
return 0;
}
static __net_exit void vxlan_exit_net(struct net *net)
{
struct vxlan_net *vn = net_generic(net, vxlan_net_id);
struct vxlan_dev *vxlan;
LIST_HEAD(list);
rtnl_lock();
list_for_each_entry(vxlan, &vn->vxlan_list, next)
unregister_netdevice_queue(vxlan->dev, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int __init vxlan_init_module(void)
{
int rc;
vxlan_wq = alloc_workqueue("vxlan", 0, 0);
if (!vxlan_wq)
return -ENOMEM;
get_random_bytes(&vxlan_salt, sizeof(vxlan_salt));
rc = register_pernet_device(&vxlan_net_ops);
if (rc)
goto out1;
rc = rtnl_link_register(&vxlan_link_ops);
if (rc)
goto out2;
return 0;
out2:
unregister_pernet_device(&vxlan_net_ops);
out1:
destroy_workqueue(vxlan_wq);
return rc;
}
static void __exit vxlan_cleanup_module(void)
{
rtnl_link_unregister(&vxlan_link_ops);
destroy_workqueue(vxlan_wq);
unregister_pernet_device(&vxlan_net_ops);
rcu_barrier();
}
