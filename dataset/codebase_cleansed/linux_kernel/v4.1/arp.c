int arp_mc_map(__be32 addr, u8 *haddr, struct net_device *dev, int dir)
{
switch (dev->type) {
case ARPHRD_ETHER:
case ARPHRD_FDDI:
case ARPHRD_IEEE802:
ip_eth_mc_map(addr, haddr);
return 0;
case ARPHRD_INFINIBAND:
ip_ib_mc_map(addr, dev->broadcast, haddr);
return 0;
case ARPHRD_IPGRE:
ip_ipgre_mc_map(addr, dev->broadcast, haddr);
return 0;
default:
if (dir) {
memcpy(haddr, dev->broadcast, dev->addr_len);
return 0;
}
}
return -EINVAL;
}
static u32 arp_hash(const void *pkey,
const struct net_device *dev,
__u32 *hash_rnd)
{
return arp_hashfn(pkey, dev, hash_rnd);
}
static bool arp_key_eq(const struct neighbour *neigh, const void *pkey)
{
return neigh_key_eq32(neigh, pkey);
}
static int arp_constructor(struct neighbour *neigh)
{
__be32 addr = *(__be32 *)neigh->primary_key;
struct net_device *dev = neigh->dev;
struct in_device *in_dev;
struct neigh_parms *parms;
rcu_read_lock();
in_dev = __in_dev_get_rcu(dev);
if (!in_dev) {
rcu_read_unlock();
return -EINVAL;
}
neigh->type = inet_addr_type(dev_net(dev), addr);
parms = in_dev->arp_parms;
__neigh_parms_put(neigh->parms);
neigh->parms = neigh_parms_clone(parms);
rcu_read_unlock();
if (!dev->header_ops) {
neigh->nud_state = NUD_NOARP;
neigh->ops = &arp_direct_ops;
neigh->output = neigh_direct_output;
} else {
if (neigh->type == RTN_MULTICAST) {
neigh->nud_state = NUD_NOARP;
arp_mc_map(addr, neigh->ha, dev, 1);
} else if (dev->flags & (IFF_NOARP | IFF_LOOPBACK)) {
neigh->nud_state = NUD_NOARP;
memcpy(neigh->ha, dev->dev_addr, dev->addr_len);
} else if (neigh->type == RTN_BROADCAST ||
(dev->flags & IFF_POINTOPOINT)) {
neigh->nud_state = NUD_NOARP;
memcpy(neigh->ha, dev->broadcast, dev->addr_len);
}
if (dev->header_ops->cache)
neigh->ops = &arp_hh_ops;
else
neigh->ops = &arp_generic_ops;
if (neigh->nud_state & NUD_VALID)
neigh->output = neigh->ops->connected_output;
else
neigh->output = neigh->ops->output;
}
return 0;
}
static void arp_error_report(struct neighbour *neigh, struct sk_buff *skb)
{
dst_link_failure(skb);
kfree_skb(skb);
}
static void arp_solicit(struct neighbour *neigh, struct sk_buff *skb)
{
__be32 saddr = 0;
u8 dst_ha[MAX_ADDR_LEN], *dst_hw = NULL;
struct net_device *dev = neigh->dev;
__be32 target = *(__be32 *)neigh->primary_key;
int probes = atomic_read(&neigh->probes);
struct in_device *in_dev;
rcu_read_lock();
in_dev = __in_dev_get_rcu(dev);
if (!in_dev) {
rcu_read_unlock();
return;
}
switch (IN_DEV_ARP_ANNOUNCE(in_dev)) {
default:
case 0:
if (skb && inet_addr_type(dev_net(dev),
ip_hdr(skb)->saddr) == RTN_LOCAL)
saddr = ip_hdr(skb)->saddr;
break;
case 1:
if (!skb)
break;
saddr = ip_hdr(skb)->saddr;
if (inet_addr_type(dev_net(dev), saddr) == RTN_LOCAL) {
if (inet_addr_onlink(in_dev, target, saddr))
break;
}
saddr = 0;
break;
case 2:
break;
}
rcu_read_unlock();
if (!saddr)
saddr = inet_select_addr(dev, target, RT_SCOPE_LINK);
probes -= NEIGH_VAR(neigh->parms, UCAST_PROBES);
if (probes < 0) {
if (!(neigh->nud_state & NUD_VALID))
pr_debug("trying to ucast probe in NUD_INVALID\n");
neigh_ha_snapshot(dst_ha, neigh, dev);
dst_hw = dst_ha;
} else {
probes -= NEIGH_VAR(neigh->parms, APP_PROBES);
if (probes < 0) {
neigh_app_ns(neigh);
return;
}
}
arp_send(ARPOP_REQUEST, ETH_P_ARP, target, dev, saddr,
dst_hw, dev->dev_addr, NULL);
}
static int arp_ignore(struct in_device *in_dev, __be32 sip, __be32 tip)
{
struct net *net = dev_net(in_dev->dev);
int scope;
switch (IN_DEV_ARP_IGNORE(in_dev)) {
case 0:
return 0;
case 1:
sip = 0;
scope = RT_SCOPE_HOST;
break;
case 2:
scope = RT_SCOPE_HOST;
break;
case 3:
sip = 0;
scope = RT_SCOPE_LINK;
in_dev = NULL;
break;
case 4:
case 5:
case 6:
case 7:
return 0;
case 8:
return 1;
default:
return 0;
}
return !inet_confirm_addr(net, in_dev, sip, tip, scope);
}
static int arp_filter(__be32 sip, __be32 tip, struct net_device *dev)
{
struct rtable *rt;
int flag = 0;
struct net *net = dev_net(dev);
rt = ip_route_output(net, sip, tip, 0, 0);
if (IS_ERR(rt))
return 1;
if (rt->dst.dev != dev) {
NET_INC_STATS_BH(net, LINUX_MIB_ARPFILTER);
flag = 1;
}
ip_rt_put(rt);
return flag;
}
static inline int arp_fwd_proxy(struct in_device *in_dev,
struct net_device *dev, struct rtable *rt)
{
struct in_device *out_dev;
int imi, omi = -1;
if (rt->dst.dev == dev)
return 0;
if (!IN_DEV_PROXY_ARP(in_dev))
return 0;
imi = IN_DEV_MEDIUM_ID(in_dev);
if (imi == 0)
return 1;
if (imi == -1)
return 0;
out_dev = __in_dev_get_rcu(rt->dst.dev);
if (out_dev)
omi = IN_DEV_MEDIUM_ID(out_dev);
return omi != imi && omi != -1;
}
static inline int arp_fwd_pvlan(struct in_device *in_dev,
struct net_device *dev, struct rtable *rt,
__be32 sip, __be32 tip)
{
if (rt->dst.dev != dev)
return 0;
if (sip == tip)
return 0;
if (IN_DEV_PROXY_ARP_PVLAN(in_dev))
return 1;
else
return 0;
}
struct sk_buff *arp_create(int type, int ptype, __be32 dest_ip,
struct net_device *dev, __be32 src_ip,
const unsigned char *dest_hw,
const unsigned char *src_hw,
const unsigned char *target_hw)
{
struct sk_buff *skb;
struct arphdr *arp;
unsigned char *arp_ptr;
int hlen = LL_RESERVED_SPACE(dev);
int tlen = dev->needed_tailroom;
skb = alloc_skb(arp_hdr_len(dev) + hlen + tlen, GFP_ATOMIC);
if (!skb)
return NULL;
skb_reserve(skb, hlen);
skb_reset_network_header(skb);
arp = (struct arphdr *) skb_put(skb, arp_hdr_len(dev));
skb->dev = dev;
skb->protocol = htons(ETH_P_ARP);
if (!src_hw)
src_hw = dev->dev_addr;
if (!dest_hw)
dest_hw = dev->broadcast;
if (dev_hard_header(skb, dev, ptype, dest_hw, src_hw, skb->len) < 0)
goto out;
switch (dev->type) {
default:
arp->ar_hrd = htons(dev->type);
arp->ar_pro = htons(ETH_P_IP);
break;
#if IS_ENABLED(CONFIG_AX25)
case ARPHRD_AX25:
arp->ar_hrd = htons(ARPHRD_AX25);
arp->ar_pro = htons(AX25_P_IP);
break;
#if IS_ENABLED(CONFIG_NETROM)
case ARPHRD_NETROM:
arp->ar_hrd = htons(ARPHRD_NETROM);
arp->ar_pro = htons(AX25_P_IP);
break;
#endif
#endif
#if IS_ENABLED(CONFIG_FDDI)
case ARPHRD_FDDI:
arp->ar_hrd = htons(ARPHRD_ETHER);
arp->ar_pro = htons(ETH_P_IP);
break;
#endif
}
arp->ar_hln = dev->addr_len;
arp->ar_pln = 4;
arp->ar_op = htons(type);
arp_ptr = (unsigned char *)(arp + 1);
memcpy(arp_ptr, src_hw, dev->addr_len);
arp_ptr += dev->addr_len;
memcpy(arp_ptr, &src_ip, 4);
arp_ptr += 4;
switch (dev->type) {
#if IS_ENABLED(CONFIG_FIREWIRE_NET)
case ARPHRD_IEEE1394:
break;
#endif
default:
if (target_hw)
memcpy(arp_ptr, target_hw, dev->addr_len);
else
memset(arp_ptr, 0, dev->addr_len);
arp_ptr += dev->addr_len;
}
memcpy(arp_ptr, &dest_ip, 4);
return skb;
out:
kfree_skb(skb);
return NULL;
}
void arp_xmit(struct sk_buff *skb)
{
NF_HOOK(NFPROTO_ARP, NF_ARP_OUT, NULL, skb,
NULL, skb->dev, dev_queue_xmit_sk);
}
void arp_send(int type, int ptype, __be32 dest_ip,
struct net_device *dev, __be32 src_ip,
const unsigned char *dest_hw, const unsigned char *src_hw,
const unsigned char *target_hw)
{
struct sk_buff *skb;
if (dev->flags&IFF_NOARP)
return;
skb = arp_create(type, ptype, dest_ip, dev, src_ip,
dest_hw, src_hw, target_hw);
if (!skb)
return;
arp_xmit(skb);
}
static int arp_process(struct sock *sk, struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
struct in_device *in_dev = __in_dev_get_rcu(dev);
struct arphdr *arp;
unsigned char *arp_ptr;
struct rtable *rt;
unsigned char *sha;
__be32 sip, tip;
u16 dev_type = dev->type;
int addr_type;
struct neighbour *n;
struct net *net = dev_net(dev);
bool is_garp = false;
if (!in_dev)
goto out;
arp = arp_hdr(skb);
switch (dev_type) {
default:
if (arp->ar_pro != htons(ETH_P_IP) ||
htons(dev_type) != arp->ar_hrd)
goto out;
break;
case ARPHRD_ETHER:
case ARPHRD_FDDI:
case ARPHRD_IEEE802:
if ((arp->ar_hrd != htons(ARPHRD_ETHER) &&
arp->ar_hrd != htons(ARPHRD_IEEE802)) ||
arp->ar_pro != htons(ETH_P_IP))
goto out;
break;
case ARPHRD_AX25:
if (arp->ar_pro != htons(AX25_P_IP) ||
arp->ar_hrd != htons(ARPHRD_AX25))
goto out;
break;
case ARPHRD_NETROM:
if (arp->ar_pro != htons(AX25_P_IP) ||
arp->ar_hrd != htons(ARPHRD_NETROM))
goto out;
break;
}
if (arp->ar_op != htons(ARPOP_REPLY) &&
arp->ar_op != htons(ARPOP_REQUEST))
goto out;
arp_ptr = (unsigned char *)(arp + 1);
sha = arp_ptr;
arp_ptr += dev->addr_len;
memcpy(&sip, arp_ptr, 4);
arp_ptr += 4;
switch (dev_type) {
#if IS_ENABLED(CONFIG_FIREWIRE_NET)
case ARPHRD_IEEE1394:
break;
#endif
default:
arp_ptr += dev->addr_len;
}
memcpy(&tip, arp_ptr, 4);
if (ipv4_is_multicast(tip) ||
(!IN_DEV_ROUTE_LOCALNET(in_dev) && ipv4_is_loopback(tip)))
goto out;
if (dev_type == ARPHRD_DLCI)
sha = dev->broadcast;
if (sip == 0) {
if (arp->ar_op == htons(ARPOP_REQUEST) &&
inet_addr_type(net, tip) == RTN_LOCAL &&
!arp_ignore(in_dev, sip, tip))
arp_send(ARPOP_REPLY, ETH_P_ARP, sip, dev, tip, sha,
dev->dev_addr, sha);
goto out;
}
if (arp->ar_op == htons(ARPOP_REQUEST) &&
ip_route_input_noref(skb, tip, sip, 0, dev) == 0) {
rt = skb_rtable(skb);
addr_type = rt->rt_type;
if (addr_type == RTN_LOCAL) {
int dont_send;
dont_send = arp_ignore(in_dev, sip, tip);
if (!dont_send && IN_DEV_ARPFILTER(in_dev))
dont_send = arp_filter(sip, tip, dev);
if (!dont_send) {
n = neigh_event_ns(&arp_tbl, sha, &sip, dev);
if (n) {
arp_send(ARPOP_REPLY, ETH_P_ARP, sip,
dev, tip, sha, dev->dev_addr,
sha);
neigh_release(n);
}
}
goto out;
} else if (IN_DEV_FORWARD(in_dev)) {
if (addr_type == RTN_UNICAST &&
(arp_fwd_proxy(in_dev, dev, rt) ||
arp_fwd_pvlan(in_dev, dev, rt, sip, tip) ||
(rt->dst.dev != dev &&
pneigh_lookup(&arp_tbl, net, &tip, dev, 0)))) {
n = neigh_event_ns(&arp_tbl, sha, &sip, dev);
if (n)
neigh_release(n);
if (NEIGH_CB(skb)->flags & LOCALLY_ENQUEUED ||
skb->pkt_type == PACKET_HOST ||
NEIGH_VAR(in_dev->arp_parms, PROXY_DELAY) == 0) {
arp_send(ARPOP_REPLY, ETH_P_ARP, sip,
dev, tip, sha, dev->dev_addr,
sha);
} else {
pneigh_enqueue(&arp_tbl,
in_dev->arp_parms, skb);
return 0;
}
goto out;
}
}
}
n = __neigh_lookup(&arp_tbl, &sip, dev, 0);
if (IN_DEV_ARP_ACCEPT(in_dev)) {
is_garp = arp->ar_op == htons(ARPOP_REQUEST) && tip == sip &&
inet_addr_type(net, sip) == RTN_UNICAST;
if (!n &&
((arp->ar_op == htons(ARPOP_REPLY) &&
inet_addr_type(net, sip) == RTN_UNICAST) || is_garp))
n = __neigh_lookup(&arp_tbl, &sip, dev, 1);
}
if (n) {
int state = NUD_REACHABLE;
int override;
override = time_after(jiffies,
n->updated +
NEIGH_VAR(n->parms, LOCKTIME)) ||
is_garp;
if (arp->ar_op != htons(ARPOP_REPLY) ||
skb->pkt_type != PACKET_HOST)
state = NUD_STALE;
neigh_update(n, sha, state,
override ? NEIGH_UPDATE_F_OVERRIDE : 0);
neigh_release(n);
}
out:
consume_skb(skb);
return 0;
}
static void parp_redo(struct sk_buff *skb)
{
arp_process(NULL, skb);
}
static int arp_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
const struct arphdr *arp;
if (dev->flags & IFF_NOARP ||
skb->pkt_type == PACKET_OTHERHOST ||
skb->pkt_type == PACKET_LOOPBACK)
goto consumeskb;
skb = skb_share_check(skb, GFP_ATOMIC);
if (!skb)
goto out_of_mem;
if (!pskb_may_pull(skb, arp_hdr_len(dev)))
goto freeskb;
arp = arp_hdr(skb);
if (arp->ar_hln != dev->addr_len || arp->ar_pln != 4)
goto freeskb;
memset(NEIGH_CB(skb), 0, sizeof(struct neighbour_cb));
return NF_HOOK(NFPROTO_ARP, NF_ARP_IN, NULL, skb,
dev, NULL, arp_process);
consumeskb:
consume_skb(skb);
return 0;
freeskb:
kfree_skb(skb);
out_of_mem:
return 0;
}
static int arp_req_set_proxy(struct net *net, struct net_device *dev, int on)
{
if (!dev) {
IPV4_DEVCONF_ALL(net, PROXY_ARP) = on;
return 0;
}
if (__in_dev_get_rtnl(dev)) {
IN_DEV_CONF_SET(__in_dev_get_rtnl(dev), PROXY_ARP, on);
return 0;
}
return -ENXIO;
}
static int arp_req_set_public(struct net *net, struct arpreq *r,
struct net_device *dev)
{
__be32 ip = ((struct sockaddr_in *)&r->arp_pa)->sin_addr.s_addr;
__be32 mask = ((struct sockaddr_in *)&r->arp_netmask)->sin_addr.s_addr;
if (mask && mask != htonl(0xFFFFFFFF))
return -EINVAL;
if (!dev && (r->arp_flags & ATF_COM)) {
dev = dev_getbyhwaddr_rcu(net, r->arp_ha.sa_family,
r->arp_ha.sa_data);
if (!dev)
return -ENODEV;
}
if (mask) {
if (!pneigh_lookup(&arp_tbl, net, &ip, dev, 1))
return -ENOBUFS;
return 0;
}
return arp_req_set_proxy(net, dev, 1);
}
static int arp_req_set(struct net *net, struct arpreq *r,
struct net_device *dev)
{
__be32 ip;
struct neighbour *neigh;
int err;
if (r->arp_flags & ATF_PUBL)
return arp_req_set_public(net, r, dev);
ip = ((struct sockaddr_in *)&r->arp_pa)->sin_addr.s_addr;
if (r->arp_flags & ATF_PERM)
r->arp_flags |= ATF_COM;
if (!dev) {
struct rtable *rt = ip_route_output(net, ip, 0, RTO_ONLINK, 0);
if (IS_ERR(rt))
return PTR_ERR(rt);
dev = rt->dst.dev;
ip_rt_put(rt);
if (!dev)
return -EINVAL;
}
switch (dev->type) {
#if IS_ENABLED(CONFIG_FDDI)
case ARPHRD_FDDI:
if (r->arp_ha.sa_family != ARPHRD_FDDI &&
r->arp_ha.sa_family != ARPHRD_ETHER &&
r->arp_ha.sa_family != ARPHRD_IEEE802)
return -EINVAL;
break;
#endif
default:
if (r->arp_ha.sa_family != dev->type)
return -EINVAL;
break;
}
neigh = __neigh_lookup_errno(&arp_tbl, &ip, dev);
err = PTR_ERR(neigh);
if (!IS_ERR(neigh)) {
unsigned int state = NUD_STALE;
if (r->arp_flags & ATF_PERM)
state = NUD_PERMANENT;
err = neigh_update(neigh, (r->arp_flags & ATF_COM) ?
r->arp_ha.sa_data : NULL, state,
NEIGH_UPDATE_F_OVERRIDE |
NEIGH_UPDATE_F_ADMIN);
neigh_release(neigh);
}
return err;
}
static unsigned int arp_state_to_flags(struct neighbour *neigh)
{
if (neigh->nud_state&NUD_PERMANENT)
return ATF_PERM | ATF_COM;
else if (neigh->nud_state&NUD_VALID)
return ATF_COM;
else
return 0;
}
static int arp_req_get(struct arpreq *r, struct net_device *dev)
{
__be32 ip = ((struct sockaddr_in *) &r->arp_pa)->sin_addr.s_addr;
struct neighbour *neigh;
int err = -ENXIO;
neigh = neigh_lookup(&arp_tbl, &ip, dev);
if (neigh) {
read_lock_bh(&neigh->lock);
memcpy(r->arp_ha.sa_data, neigh->ha, dev->addr_len);
r->arp_flags = arp_state_to_flags(neigh);
read_unlock_bh(&neigh->lock);
r->arp_ha.sa_family = dev->type;
strlcpy(r->arp_dev, dev->name, sizeof(r->arp_dev));
neigh_release(neigh);
err = 0;
}
return err;
}
static int arp_invalidate(struct net_device *dev, __be32 ip)
{
struct neighbour *neigh = neigh_lookup(&arp_tbl, &ip, dev);
int err = -ENXIO;
if (neigh) {
if (neigh->nud_state & ~NUD_NOARP)
err = neigh_update(neigh, NULL, NUD_FAILED,
NEIGH_UPDATE_F_OVERRIDE|
NEIGH_UPDATE_F_ADMIN);
neigh_release(neigh);
}
return err;
}
static int arp_req_delete_public(struct net *net, struct arpreq *r,
struct net_device *dev)
{
__be32 ip = ((struct sockaddr_in *) &r->arp_pa)->sin_addr.s_addr;
__be32 mask = ((struct sockaddr_in *)&r->arp_netmask)->sin_addr.s_addr;
if (mask == htonl(0xFFFFFFFF))
return pneigh_delete(&arp_tbl, net, &ip, dev);
if (mask)
return -EINVAL;
return arp_req_set_proxy(net, dev, 0);
}
static int arp_req_delete(struct net *net, struct arpreq *r,
struct net_device *dev)
{
__be32 ip;
if (r->arp_flags & ATF_PUBL)
return arp_req_delete_public(net, r, dev);
ip = ((struct sockaddr_in *)&r->arp_pa)->sin_addr.s_addr;
if (!dev) {
struct rtable *rt = ip_route_output(net, ip, 0, RTO_ONLINK, 0);
if (IS_ERR(rt))
return PTR_ERR(rt);
dev = rt->dst.dev;
ip_rt_put(rt);
if (!dev)
return -EINVAL;
}
return arp_invalidate(dev, ip);
}
int arp_ioctl(struct net *net, unsigned int cmd, void __user *arg)
{
int err;
struct arpreq r;
struct net_device *dev = NULL;
switch (cmd) {
case SIOCDARP:
case SIOCSARP:
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
return -EPERM;
case SIOCGARP:
err = copy_from_user(&r, arg, sizeof(struct arpreq));
if (err)
return -EFAULT;
break;
default:
return -EINVAL;
}
if (r.arp_pa.sa_family != AF_INET)
return -EPFNOSUPPORT;
if (!(r.arp_flags & ATF_PUBL) &&
(r.arp_flags & (ATF_NETMASK | ATF_DONTPUB)))
return -EINVAL;
if (!(r.arp_flags & ATF_NETMASK))
((struct sockaddr_in *)&r.arp_netmask)->sin_addr.s_addr =
htonl(0xFFFFFFFFUL);
rtnl_lock();
if (r.arp_dev[0]) {
err = -ENODEV;
dev = __dev_get_by_name(net, r.arp_dev);
if (!dev)
goto out;
if (!r.arp_ha.sa_family)
r.arp_ha.sa_family = dev->type;
err = -EINVAL;
if ((r.arp_flags & ATF_COM) && r.arp_ha.sa_family != dev->type)
goto out;
} else if (cmd == SIOCGARP) {
err = -ENODEV;
goto out;
}
switch (cmd) {
case SIOCDARP:
err = arp_req_delete(net, &r, dev);
break;
case SIOCSARP:
err = arp_req_set(net, &r, dev);
break;
case SIOCGARP:
err = arp_req_get(&r, dev);
break;
}
out:
rtnl_unlock();
if (cmd == SIOCGARP && !err && copy_to_user(arg, &r, sizeof(r)))
err = -EFAULT;
return err;
}
static int arp_netdev_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct netdev_notifier_change_info *change_info;
switch (event) {
case NETDEV_CHANGEADDR:
neigh_changeaddr(&arp_tbl, dev);
rt_cache_flush(dev_net(dev));
break;
case NETDEV_CHANGE:
change_info = ptr;
if (change_info->flags_changed & IFF_NOARP)
neigh_changeaddr(&arp_tbl, dev);
break;
default:
break;
}
return NOTIFY_DONE;
}
void arp_ifdown(struct net_device *dev)
{
neigh_ifdown(&arp_tbl, dev);
}
void __init arp_init(void)
{
neigh_table_init(NEIGH_ARP_TABLE, &arp_tbl);
dev_add_pack(&arp_packet_type);
arp_proc_init();
#ifdef CONFIG_SYSCTL
neigh_sysctl_register(NULL, &arp_tbl.parms, NULL);
#endif
register_netdevice_notifier(&arp_netdev_notifier);
}
static char *ax2asc2(ax25_address *a, char *buf)
{
char c, *s;
int n;
for (n = 0, s = buf; n < 6; n++) {
c = (a->ax25_call[n] >> 1) & 0x7F;
if (c != ' ')
*s++ = c;
}
*s++ = '-';
n = (a->ax25_call[6] >> 1) & 0x0F;
if (n > 9) {
*s++ = '1';
n -= 10;
}
*s++ = n + '0';
*s++ = '\0';
if (*buf == '\0' || *buf == '-')
return "*";
return buf;
}
static void arp_format_neigh_entry(struct seq_file *seq,
struct neighbour *n)
{
char hbuffer[HBUFFERLEN];
int k, j;
char tbuf[16];
struct net_device *dev = n->dev;
int hatype = dev->type;
read_lock(&n->lock);
#if IS_ENABLED(CONFIG_AX25)
if (hatype == ARPHRD_AX25 || hatype == ARPHRD_NETROM)
ax2asc2((ax25_address *)n->ha, hbuffer);
else {
#endif
for (k = 0, j = 0; k < HBUFFERLEN - 3 && j < dev->addr_len; j++) {
hbuffer[k++] = hex_asc_hi(n->ha[j]);
hbuffer[k++] = hex_asc_lo(n->ha[j]);
hbuffer[k++] = ':';
}
if (k != 0)
--k;
hbuffer[k] = 0;
#if IS_ENABLED(CONFIG_AX25)
}
#endif
sprintf(tbuf, "%pI4", n->primary_key);
seq_printf(seq, "%-16s 0x%-10x0x%-10x%s * %s\n",
tbuf, hatype, arp_state_to_flags(n), hbuffer, dev->name);
read_unlock(&n->lock);
}
static void arp_format_pneigh_entry(struct seq_file *seq,
struct pneigh_entry *n)
{
struct net_device *dev = n->dev;
int hatype = dev ? dev->type : 0;
char tbuf[16];
sprintf(tbuf, "%pI4", n->key);
seq_printf(seq, "%-16s 0x%-10x0x%-10x%s * %s\n",
tbuf, hatype, ATF_PUBL | ATF_PERM, "00:00:00:00:00:00",
dev ? dev->name : "*");
}
static int arp_seq_show(struct seq_file *seq, void *v)
{
if (v == SEQ_START_TOKEN) {
seq_puts(seq, "IP address HW type Flags "
"HW address Mask Device\n");
} else {
struct neigh_seq_state *state = seq->private;
if (state->flags & NEIGH_SEQ_IS_PNEIGH)
arp_format_pneigh_entry(seq, v);
else
arp_format_neigh_entry(seq, v);
}
return 0;
}
static void *arp_seq_start(struct seq_file *seq, loff_t *pos)
{
return neigh_seq_start(seq, pos, &arp_tbl, NEIGH_SEQ_SKIP_NOARP);
}
static int arp_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &arp_seq_ops,
sizeof(struct neigh_seq_state));
}
static int __net_init arp_net_init(struct net *net)
{
if (!proc_create("arp", S_IRUGO, net->proc_net, &arp_seq_fops))
return -ENOMEM;
return 0;
}
static void __net_exit arp_net_exit(struct net *net)
{
remove_proc_entry("arp", net->proc_net);
}
static int __init arp_proc_init(void)
{
return register_pernet_subsys(&arp_net_ops);
}
static int __init arp_proc_init(void)
{
return 0;
}
