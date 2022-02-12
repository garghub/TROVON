int inet6_register_icmp_sender(ip6_icmp_send_t *fn)
{
return (cmpxchg((ip6_icmp_send_t **)&ip6_icmp_send, NULL, fn) == NULL) ?
0 : -EBUSY;
}
int inet6_unregister_icmp_sender(ip6_icmp_send_t *fn)
{
int ret;
ret = (cmpxchg((ip6_icmp_send_t **)&ip6_icmp_send, fn, NULL) == fn) ?
0 : -EINVAL;
synchronize_net();
return ret;
}
void icmpv6_send(struct sk_buff *skb, u8 type, u8 code, __u32 info)
{
ip6_icmp_send_t *send;
rcu_read_lock();
send = rcu_dereference(ip6_icmp_send);
if (!send)
goto out;
send(skb, type, code, info);
out:
rcu_read_unlock();
}
