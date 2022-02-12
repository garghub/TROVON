unsigned int
nf_nat_redirect_ipv4(struct sk_buff *skb,
const struct nf_nat_ipv4_multi_range_compat *mr,
unsigned int hooknum)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
__be32 newdst;
struct nf_nat_range newrange;
NF_CT_ASSERT(hooknum == NF_INET_PRE_ROUTING ||
hooknum == NF_INET_LOCAL_OUT);
ct = nf_ct_get(skb, &ctinfo);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED));
if (hooknum == NF_INET_LOCAL_OUT) {
newdst = htonl(0x7F000001);
} else {
struct in_device *indev;
struct in_ifaddr *ifa;
newdst = 0;
rcu_read_lock();
indev = __in_dev_get_rcu(skb->dev);
if (indev != NULL) {
ifa = indev->ifa_list;
newdst = ifa->ifa_local;
}
rcu_read_unlock();
if (!newdst)
return NF_DROP;
}
memset(&newrange.min_addr, 0, sizeof(newrange.min_addr));
memset(&newrange.max_addr, 0, sizeof(newrange.max_addr));
newrange.flags = mr->range[0].flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.ip = newdst;
newrange.max_addr.ip = newdst;
newrange.min_proto = mr->range[0].min;
newrange.max_proto = mr->range[0].max;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_DST);
}
unsigned int
nf_nat_redirect_ipv6(struct sk_buff *skb, const struct nf_nat_range *range,
unsigned int hooknum)
{
struct nf_nat_range newrange;
struct in6_addr newdst;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
if (hooknum == NF_INET_LOCAL_OUT) {
newdst = loopback_addr;
} else {
struct inet6_dev *idev;
struct inet6_ifaddr *ifa;
bool addr = false;
rcu_read_lock();
idev = __in6_dev_get(skb->dev);
if (idev != NULL) {
list_for_each_entry(ifa, &idev->addr_list, if_list) {
newdst = ifa->addr;
addr = true;
break;
}
}
rcu_read_unlock();
if (!addr)
return NF_DROP;
}
newrange.flags = range->flags | NF_NAT_RANGE_MAP_IPS;
newrange.min_addr.in6 = newdst;
newrange.max_addr.in6 = newdst;
newrange.min_proto = range->min_proto;
newrange.max_proto = range->max_proto;
return nf_nat_setup_info(ct, &newrange, NF_NAT_MANIP_DST);
}
