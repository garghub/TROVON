void dn_start_slow_timer(struct sock *sk)
{
sk->sk_timer.expires = jiffies + SLOW_INTERVAL;
sk->sk_timer.function = dn_slow_timer;
sk->sk_timer.data = (unsigned long)sk;
add_timer(&sk->sk_timer);
}
void dn_stop_slow_timer(struct sock *sk)
{
del_timer(&sk->sk_timer);
}
static void dn_slow_timer(unsigned long arg)
{
struct sock *sk = (struct sock *)arg;
struct dn_scp *scp = DN_SK(sk);
sock_hold(sk);
bh_lock_sock(sk);
if (sock_owned_by_user(sk)) {
sk->sk_timer.expires = jiffies + HZ / 10;
add_timer(&sk->sk_timer);
goto out;
}
if (scp->persist && scp->persist_fxn) {
if (scp->persist <= SLOW_INTERVAL) {
scp->persist = 0;
if (scp->persist_fxn(sk))
goto out;
} else {
scp->persist -= SLOW_INTERVAL;
}
}
if (scp->keepalive && scp->keepalive_fxn && (scp->state == DN_RUN)) {
if ((jiffies - scp->stamp) >= scp->keepalive)
scp->keepalive_fxn(sk);
}
sk->sk_timer.expires = jiffies + SLOW_INTERVAL;
add_timer(&sk->sk_timer);
out:
bh_unlock_sock(sk);
sock_put(sk);
}
