int gre_add_protocol(const struct gre_protocol *proto, u8 version)
{
if (version >= GREPROTO_MAX)
return -EINVAL;
return (cmpxchg((const struct gre_protocol **)&gre_proto[version], NULL, proto) == NULL) ?
0 : -EBUSY;
}
int gre_del_protocol(const struct gre_protocol *proto, u8 version)
{
int ret;
if (version >= GREPROTO_MAX)
return -EINVAL;
ret = (cmpxchg((const struct gre_protocol **)&gre_proto[version], proto, NULL) == proto) ?
0 : -EBUSY;
if (ret)
return ret;
synchronize_rcu();
return 0;
}
static int gre_rcv(struct sk_buff *skb)
{
const struct gre_protocol *proto;
u8 ver;
int ret;
if (!pskb_may_pull(skb, 12))
goto drop;
ver = skb->data[1]&0x7f;
if (ver >= GREPROTO_MAX)
goto drop;
rcu_read_lock();
proto = rcu_dereference(gre_proto[ver]);
if (!proto || !proto->handler)
goto drop_unlock;
ret = proto->handler(skb);
rcu_read_unlock();
return ret;
drop_unlock:
rcu_read_unlock();
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static void gre_err(struct sk_buff *skb, u32 info)
{
const struct gre_protocol *proto;
const struct iphdr *iph = (const struct iphdr *)skb->data;
u8 ver = skb->data[(iph->ihl<<2) + 1]&0x7f;
if (ver >= GREPROTO_MAX)
return;
rcu_read_lock();
proto = rcu_dereference(gre_proto[ver]);
if (proto && proto->err_handler)
proto->err_handler(skb, info);
rcu_read_unlock();
}
static int __init gre_init(void)
{
pr_info("GRE over IPv4 demultiplexor driver\n");
if (inet_add_protocol(&net_gre_protocol, IPPROTO_GRE) < 0) {
pr_err("can't add protocol\n");
return -EAGAIN;
}
return 0;
}
static void __exit gre_exit(void)
{
inet_del_protocol(&net_gre_protocol, IPPROTO_GRE);
}
