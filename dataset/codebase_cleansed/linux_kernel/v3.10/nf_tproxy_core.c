static void
nf_tproxy_destructor(struct sk_buff *skb)
{
struct sock *sk = skb->sk;
skb->sk = NULL;
skb->destructor = NULL;
if (sk)
sock_put(sk);
}
void
nf_tproxy_assign_sock(struct sk_buff *skb, struct sock *sk)
{
if (sk->sk_state == TCP_TIME_WAIT) {
inet_twsk_put(inet_twsk(sk));
return;
}
skb_orphan(skb);
skb->sk = sk;
skb->destructor = nf_tproxy_destructor;
}
static int __init nf_tproxy_init(void)
{
pr_info("NF_TPROXY: Transparent proxy support initialized, version 4.1.0\n");
pr_info("NF_TPROXY: Copyright (c) 2006-2007 BalaBit IT Ltd.\n");
return 0;
}
