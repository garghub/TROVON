static void tcp_diag_get_info(struct sock *sk, struct inet_diag_msg *r,
void *_info)
{
const struct tcp_sock *tp = tcp_sk(sk);
struct tcp_info *info = _info;
if (sk->sk_state == TCP_LISTEN) {
r->idiag_rqueue = sk->sk_ack_backlog;
r->idiag_wqueue = sk->sk_max_ack_backlog;
} else {
r->idiag_rqueue = max_t(int, tp->rcv_nxt - tp->copied_seq, 0);
r->idiag_wqueue = tp->write_seq - tp->snd_una;
}
if (info != NULL)
tcp_get_info(sk, info);
}
static int __init tcp_diag_init(void)
{
return inet_diag_register(&tcp_diag_handler);
}
static void __exit tcp_diag_exit(void)
{
inet_diag_unregister(&tcp_diag_handler);
}
