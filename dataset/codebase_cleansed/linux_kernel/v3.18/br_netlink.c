static inline size_t br_port_info_size(void)
{
return nla_total_size(1)
+ nla_total_size(2)
+ nla_total_size(4)
+ nla_total_size(1)
+ nla_total_size(1)
+ nla_total_size(1)
+ nla_total_size(1)
+ nla_total_size(1)
+ nla_total_size(1)
+ 0;
}
static inline size_t br_nlmsg_size(void)
{
return NLMSG_ALIGN(sizeof(struct ifinfomsg))
+ nla_total_size(IFNAMSIZ)
+ nla_total_size(MAX_ADDR_LEN)
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(4)
+ nla_total_size(1)
+ nla_total_size(br_port_info_size());
}
static int br_port_fill_attrs(struct sk_buff *skb,
const struct net_bridge_port *p)
{
u8 mode = !!(p->flags & BR_HAIRPIN_MODE);
if (nla_put_u8(skb, IFLA_BRPORT_STATE, p->state) ||
nla_put_u16(skb, IFLA_BRPORT_PRIORITY, p->priority) ||
nla_put_u32(skb, IFLA_BRPORT_COST, p->path_cost) ||
nla_put_u8(skb, IFLA_BRPORT_MODE, mode) ||
nla_put_u8(skb, IFLA_BRPORT_GUARD, !!(p->flags & BR_BPDU_GUARD)) ||
nla_put_u8(skb, IFLA_BRPORT_PROTECT, !!(p->flags & BR_ROOT_BLOCK)) ||
nla_put_u8(skb, IFLA_BRPORT_FAST_LEAVE, !!(p->flags & BR_MULTICAST_FAST_LEAVE)) ||
nla_put_u8(skb, IFLA_BRPORT_LEARNING, !!(p->flags & BR_LEARNING)) ||
nla_put_u8(skb, IFLA_BRPORT_UNICAST_FLOOD, !!(p->flags & BR_FLOOD)))
return -EMSGSIZE;
return 0;
}
static int br_fill_ifinfo(struct sk_buff *skb,
const struct net_bridge_port *port,
u32 pid, u32 seq, int event, unsigned int flags,
u32 filter_mask, const struct net_device *dev)
{
const struct net_bridge *br;
struct ifinfomsg *hdr;
struct nlmsghdr *nlh;
u8 operstate = netif_running(dev) ? dev->operstate : IF_OPER_DOWN;
if (port)
br = port->br;
else
br = netdev_priv(dev);
br_debug(br, "br_fill_info event %d port %s master %s\n",
event, dev->name, br->dev->name);
nlh = nlmsg_put(skb, pid, seq, event, sizeof(*hdr), flags);
if (nlh == NULL)
return -EMSGSIZE;
hdr = nlmsg_data(nlh);
hdr->ifi_family = AF_BRIDGE;
hdr->__ifi_pad = 0;
hdr->ifi_type = dev->type;
hdr->ifi_index = dev->ifindex;
hdr->ifi_flags = dev_get_flags(dev);
hdr->ifi_change = 0;
if (nla_put_string(skb, IFLA_IFNAME, dev->name) ||
nla_put_u32(skb, IFLA_MASTER, br->dev->ifindex) ||
nla_put_u32(skb, IFLA_MTU, dev->mtu) ||
nla_put_u8(skb, IFLA_OPERSTATE, operstate) ||
(dev->addr_len &&
nla_put(skb, IFLA_ADDRESS, dev->addr_len, dev->dev_addr)) ||
(dev->ifindex != dev->iflink &&
nla_put_u32(skb, IFLA_LINK, dev->iflink)))
goto nla_put_failure;
if (event == RTM_NEWLINK && port) {
struct nlattr *nest
= nla_nest_start(skb, IFLA_PROTINFO | NLA_F_NESTED);
if (nest == NULL || br_port_fill_attrs(skb, port) < 0)
goto nla_put_failure;
nla_nest_end(skb, nest);
}
if (filter_mask & RTEXT_FILTER_BRVLAN) {
struct nlattr *af;
const struct net_port_vlans *pv;
struct bridge_vlan_info vinfo;
u16 vid;
u16 pvid;
if (port)
pv = nbp_get_vlan_info(port);
else
pv = br_get_vlan_info(br);
if (!pv || bitmap_empty(pv->vlan_bitmap, VLAN_N_VID))
goto done;
af = nla_nest_start(skb, IFLA_AF_SPEC);
if (!af)
goto nla_put_failure;
pvid = br_get_pvid(pv);
for_each_set_bit(vid, pv->vlan_bitmap, VLAN_N_VID) {
vinfo.vid = vid;
vinfo.flags = 0;
if (vid == pvid)
vinfo.flags |= BRIDGE_VLAN_INFO_PVID;
if (test_bit(vid, pv->untagged_bitmap))
vinfo.flags |= BRIDGE_VLAN_INFO_UNTAGGED;
if (nla_put(skb, IFLA_BRIDGE_VLAN_INFO,
sizeof(vinfo), &vinfo))
goto nla_put_failure;
}
nla_nest_end(skb, af);
}
done:
return nlmsg_end(skb, nlh);
nla_put_failure:
nlmsg_cancel(skb, nlh);
return -EMSGSIZE;
}
void br_ifinfo_notify(int event, struct net_bridge_port *port)
{
struct net *net;
struct sk_buff *skb;
int err = -ENOBUFS;
if (!port)
return;
net = dev_net(port->dev);
br_debug(port->br, "port %u(%s) event %d\n",
(unsigned int)port->port_no, port->dev->name, event);
skb = nlmsg_new(br_nlmsg_size(), GFP_ATOMIC);
if (skb == NULL)
goto errout;
err = br_fill_ifinfo(skb, port, 0, 0, event, 0, 0, port->dev);
if (err < 0) {
WARN_ON(err == -EMSGSIZE);
kfree_skb(skb);
goto errout;
}
rtnl_notify(skb, net, 0, RTNLGRP_LINK, NULL, GFP_ATOMIC);
return;
errout:
rtnl_set_sk_err(net, RTNLGRP_LINK, err);
}
int br_getlink(struct sk_buff *skb, u32 pid, u32 seq,
struct net_device *dev, u32 filter_mask)
{
int err = 0;
struct net_bridge_port *port = br_port_get_rtnl(dev);
if (!port && !(filter_mask & RTEXT_FILTER_BRVLAN))
goto out;
err = br_fill_ifinfo(skb, port, pid, seq, RTM_NEWLINK, NLM_F_MULTI,
filter_mask, dev);
out:
return err;
}
static int br_afspec(struct net_bridge *br,
struct net_bridge_port *p,
struct nlattr *af_spec,
int cmd)
{
struct nlattr *tb[IFLA_BRIDGE_MAX+1];
int err = 0;
err = nla_parse_nested(tb, IFLA_BRIDGE_MAX, af_spec, ifla_br_policy);
if (err)
return err;
if (tb[IFLA_BRIDGE_VLAN_INFO]) {
struct bridge_vlan_info *vinfo;
vinfo = nla_data(tb[IFLA_BRIDGE_VLAN_INFO]);
if (!vinfo->vid || vinfo->vid >= VLAN_VID_MASK)
return -EINVAL;
switch (cmd) {
case RTM_SETLINK:
if (p) {
err = nbp_vlan_add(p, vinfo->vid, vinfo->flags);
if (err)
break;
if (vinfo->flags & BRIDGE_VLAN_INFO_MASTER)
err = br_vlan_add(p->br, vinfo->vid,
vinfo->flags);
} else
err = br_vlan_add(br, vinfo->vid, vinfo->flags);
break;
case RTM_DELLINK:
if (p) {
nbp_vlan_delete(p, vinfo->vid);
if (vinfo->flags & BRIDGE_VLAN_INFO_MASTER)
br_vlan_delete(p->br, vinfo->vid);
} else
br_vlan_delete(br, vinfo->vid);
break;
}
}
return err;
}
static int br_set_port_state(struct net_bridge_port *p, u8 state)
{
if (state > BR_STATE_BLOCKING)
return -EINVAL;
if (p->br->stp_enabled == BR_KERNEL_STP)
return -EBUSY;
if (!netif_running(p->dev) ||
(!netif_oper_up(p->dev) && state != BR_STATE_DISABLED))
return -ENETDOWN;
br_set_state(p, state);
br_log_state(p);
br_port_state_selection(p->br);
return 0;
}
static void br_set_port_flag(struct net_bridge_port *p, struct nlattr *tb[],
int attrtype, unsigned long mask)
{
if (tb[attrtype]) {
u8 flag = nla_get_u8(tb[attrtype]);
if (flag)
p->flags |= mask;
else
p->flags &= ~mask;
}
}
static int br_setport(struct net_bridge_port *p, struct nlattr *tb[])
{
int err;
unsigned long old_flags = p->flags;
br_set_port_flag(p, tb, IFLA_BRPORT_MODE, BR_HAIRPIN_MODE);
br_set_port_flag(p, tb, IFLA_BRPORT_GUARD, BR_BPDU_GUARD);
br_set_port_flag(p, tb, IFLA_BRPORT_FAST_LEAVE, BR_MULTICAST_FAST_LEAVE);
br_set_port_flag(p, tb, IFLA_BRPORT_PROTECT, BR_ROOT_BLOCK);
br_set_port_flag(p, tb, IFLA_BRPORT_LEARNING, BR_LEARNING);
br_set_port_flag(p, tb, IFLA_BRPORT_UNICAST_FLOOD, BR_FLOOD);
if (tb[IFLA_BRPORT_COST]) {
err = br_stp_set_path_cost(p, nla_get_u32(tb[IFLA_BRPORT_COST]));
if (err)
return err;
}
if (tb[IFLA_BRPORT_PRIORITY]) {
err = br_stp_set_port_priority(p, nla_get_u16(tb[IFLA_BRPORT_PRIORITY]));
if (err)
return err;
}
if (tb[IFLA_BRPORT_STATE]) {
err = br_set_port_state(p, nla_get_u8(tb[IFLA_BRPORT_STATE]));
if (err)
return err;
}
br_port_flags_change(p, old_flags ^ p->flags);
return 0;
}
int br_setlink(struct net_device *dev, struct nlmsghdr *nlh)
{
struct nlattr *protinfo;
struct nlattr *afspec;
struct net_bridge_port *p;
struct nlattr *tb[IFLA_BRPORT_MAX + 1];
int err = 0;
protinfo = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_PROTINFO);
afspec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_AF_SPEC);
if (!protinfo && !afspec)
return 0;
p = br_port_get_rtnl(dev);
if (!p && !afspec)
return -EINVAL;
if (p && protinfo) {
if (protinfo->nla_type & NLA_F_NESTED) {
err = nla_parse_nested(tb, IFLA_BRPORT_MAX,
protinfo, br_port_policy);
if (err)
return err;
spin_lock_bh(&p->br->lock);
err = br_setport(p, tb);
spin_unlock_bh(&p->br->lock);
} else {
if (nla_len(protinfo) < sizeof(u8))
return -EINVAL;
spin_lock_bh(&p->br->lock);
err = br_set_port_state(p, nla_get_u8(protinfo));
spin_unlock_bh(&p->br->lock);
}
if (err)
goto out;
}
if (afspec) {
err = br_afspec((struct net_bridge *)netdev_priv(dev), p,
afspec, RTM_SETLINK);
}
if (err == 0)
br_ifinfo_notify(RTM_NEWLINK, p);
out:
return err;
}
int br_dellink(struct net_device *dev, struct nlmsghdr *nlh)
{
struct nlattr *afspec;
struct net_bridge_port *p;
int err;
afspec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_AF_SPEC);
if (!afspec)
return 0;
p = br_port_get_rtnl(dev);
if (!p && !(dev->priv_flags & IFF_EBRIDGE))
return -EINVAL;
err = br_afspec((struct net_bridge *)netdev_priv(dev), p,
afspec, RTM_DELLINK);
return err;
}
static int br_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
return 0;
}
static int br_dev_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct net_bridge *br = netdev_priv(dev);
if (tb[IFLA_ADDRESS]) {
spin_lock_bh(&br->lock);
br_stp_change_bridge_id(br, nla_data(tb[IFLA_ADDRESS]));
spin_unlock_bh(&br->lock);
}
return register_netdevice(dev);
}
static int br_port_slave_changelink(struct net_device *brdev,
struct net_device *dev,
struct nlattr *tb[],
struct nlattr *data[])
{
if (!data)
return 0;
return br_setport(br_port_get_rtnl(dev), data);
}
static int br_port_fill_slave_info(struct sk_buff *skb,
const struct net_device *brdev,
const struct net_device *dev)
{
return br_port_fill_attrs(skb, br_port_get_rtnl(dev));
}
static size_t br_port_get_slave_size(const struct net_device *brdev,
const struct net_device *dev)
{
return br_port_info_size();
}
static int br_changelink(struct net_device *brdev, struct nlattr *tb[],
struct nlattr *data[])
{
struct net_bridge *br = netdev_priv(brdev);
int err;
if (!data)
return 0;
if (data[IFLA_BR_FORWARD_DELAY]) {
err = br_set_forward_delay(br, nla_get_u32(data[IFLA_BR_FORWARD_DELAY]));
if (err)
return err;
}
if (data[IFLA_BR_HELLO_TIME]) {
err = br_set_hello_time(br, nla_get_u32(data[IFLA_BR_HELLO_TIME]));
if (err)
return err;
}
if (data[IFLA_BR_MAX_AGE]) {
err = br_set_max_age(br, nla_get_u32(data[IFLA_BR_MAX_AGE]));
if (err)
return err;
}
return 0;
}
static size_t br_get_size(const struct net_device *brdev)
{
return nla_total_size(sizeof(u32)) +
nla_total_size(sizeof(u32)) +
nla_total_size(sizeof(u32)) +
0;
}
static int br_fill_info(struct sk_buff *skb, const struct net_device *brdev)
{
struct net_bridge *br = netdev_priv(brdev);
u32 forward_delay = jiffies_to_clock_t(br->forward_delay);
u32 hello_time = jiffies_to_clock_t(br->hello_time);
u32 age_time = jiffies_to_clock_t(br->max_age);
if (nla_put_u32(skb, IFLA_BR_FORWARD_DELAY, forward_delay) ||
nla_put_u32(skb, IFLA_BR_HELLO_TIME, hello_time) ||
nla_put_u32(skb, IFLA_BR_MAX_AGE, age_time))
return -EMSGSIZE;
return 0;
}
static size_t br_get_link_af_size(const struct net_device *dev)
{
struct net_port_vlans *pv;
if (br_port_exists(dev))
pv = nbp_get_vlan_info(br_port_get_rtnl(dev));
else if (dev->priv_flags & IFF_EBRIDGE)
pv = br_get_vlan_info((struct net_bridge *)netdev_priv(dev));
else
return 0;
if (!pv)
return 0;
return pv->num_vlans * nla_total_size(sizeof(struct bridge_vlan_info));
}
int __init br_netlink_init(void)
{
int err;
br_mdb_init();
rtnl_af_register(&br_af_ops);
err = rtnl_link_register(&br_link_ops);
if (err)
goto out_af;
return 0;
out_af:
rtnl_af_unregister(&br_af_ops);
br_mdb_uninit();
return err;
}
void br_netlink_fini(void)
{
br_mdb_uninit();
rtnl_af_unregister(&br_af_ops);
rtnl_link_unregister(&br_link_ops);
}
