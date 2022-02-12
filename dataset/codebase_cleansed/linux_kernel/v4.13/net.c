int tipc_net_start(struct net *net, u32 addr)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
char addr_string[16];
tn->own_addr = addr;
smp_mb();
tipc_named_reinit(net);
tipc_sk_reinit(net);
tipc_nametbl_publish(net, TIPC_CFG_SRV, tn->own_addr, tn->own_addr,
TIPC_ZONE_SCOPE, 0, tn->own_addr);
pr_info("Started in network mode\n");
pr_info("Own node address %s, network identity %u\n",
tipc_addr_string_fill(addr_string, tn->own_addr),
tn->net_id);
return 0;
}
void tipc_net_stop(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
if (!tn->own_addr)
return;
tipc_nametbl_withdraw(net, TIPC_CFG_SRV, tn->own_addr, 0,
tn->own_addr);
rtnl_lock();
tipc_bearer_stop(net);
tipc_node_stop(net);
rtnl_unlock();
pr_info("Left network mode\n");
}
static int __tipc_nl_add_net(struct net *net, struct tipc_nl_msg *msg)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
void *hdr;
struct nlattr *attrs;
hdr = genlmsg_put(msg->skb, msg->portid, msg->seq, &tipc_genl_family,
NLM_F_MULTI, TIPC_NL_NET_GET);
if (!hdr)
return -EMSGSIZE;
attrs = nla_nest_start(msg->skb, TIPC_NLA_NET);
if (!attrs)
goto msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_NET_ID, tn->net_id))
goto attr_msg_full;
nla_nest_end(msg->skb, attrs);
genlmsg_end(msg->skb, hdr);
return 0;
attr_msg_full:
nla_nest_cancel(msg->skb, attrs);
msg_full:
genlmsg_cancel(msg->skb, hdr);
return -EMSGSIZE;
}
int tipc_nl_net_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
int err;
int done = cb->args[0];
struct tipc_nl_msg msg;
if (done)
return 0;
msg.skb = skb;
msg.portid = NETLINK_CB(cb->skb).portid;
msg.seq = cb->nlh->nlmsg_seq;
err = __tipc_nl_add_net(net, &msg);
if (err)
goto out;
done = 1;
out:
cb->args[0] = done;
return skb->len;
}
int tipc_nl_net_set(struct sk_buff *skb, struct genl_info *info)
{
struct net *net = sock_net(skb->sk);
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct nlattr *attrs[TIPC_NLA_NET_MAX + 1];
int err;
if (!info->attrs[TIPC_NLA_NET])
return -EINVAL;
err = nla_parse_nested(attrs, TIPC_NLA_NET_MAX,
info->attrs[TIPC_NLA_NET], tipc_nl_net_policy,
info->extack);
if (err)
return err;
if (attrs[TIPC_NLA_NET_ID]) {
u32 val;
if (tn->own_addr)
return -EPERM;
val = nla_get_u32(attrs[TIPC_NLA_NET_ID]);
if (val < 1 || val > 9999)
return -EINVAL;
tn->net_id = val;
}
if (attrs[TIPC_NLA_NET_ADDR]) {
u32 addr;
if (tn->own_addr)
return -EPERM;
addr = nla_get_u32(attrs[TIPC_NLA_NET_ADDR]);
if (!tipc_addr_node_valid(addr))
return -EINVAL;
rtnl_lock();
tipc_net_start(net, addr);
rtnl_unlock();
}
return 0;
}
