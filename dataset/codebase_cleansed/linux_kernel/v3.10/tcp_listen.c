static int rds_tcp_accept_one(struct socket *sock)
{
struct socket *new_sock = NULL;
struct rds_connection *conn;
int ret;
struct inet_sock *inet;
ret = sock_create_lite(sock->sk->sk_family, sock->sk->sk_type,
sock->sk->sk_protocol, &new_sock);
if (ret)
goto out;
new_sock->type = sock->type;
new_sock->ops = sock->ops;
ret = sock->ops->accept(sock, new_sock, O_NONBLOCK);
if (ret < 0)
goto out;
rds_tcp_tune(new_sock);
inet = inet_sk(new_sock->sk);
rdsdebug("accepted tcp %pI4:%u -> %pI4:%u\n",
&inet->inet_saddr, ntohs(inet->inet_sport),
&inet->inet_daddr, ntohs(inet->inet_dport));
conn = rds_conn_create(inet->inet_saddr, inet->inet_daddr,
&rds_tcp_transport, GFP_KERNEL);
if (IS_ERR(conn)) {
ret = PTR_ERR(conn);
goto out;
}
if (!rds_conn_transition(conn, RDS_CONN_DOWN, RDS_CONN_CONNECTING)) {
if (rds_conn_state(conn) == RDS_CONN_UP)
rds_tcp_stats_inc(s_tcp_listen_closed_stale);
else
rds_tcp_stats_inc(s_tcp_connect_raced);
rds_conn_drop(conn);
ret = 0;
goto out;
}
rds_tcp_set_callbacks(new_sock, conn);
rds_connect_complete(conn);
new_sock = NULL;
ret = 0;
out:
if (new_sock)
sock_release(new_sock);
return ret;
}
static void rds_tcp_accept_worker(struct work_struct *work)
{
while (rds_tcp_accept_one(rds_tcp_listen_sock) == 0)
cond_resched();
}
void rds_tcp_listen_data_ready(struct sock *sk, int bytes)
{
void (*ready)(struct sock *sk, int bytes);
rdsdebug("listen data ready sk %p\n", sk);
read_lock(&sk->sk_callback_lock);
ready = sk->sk_user_data;
if (!ready) {
ready = sk->sk_data_ready;
goto out;
}
if (sk->sk_state == TCP_LISTEN)
queue_work(rds_wq, &rds_tcp_listen_work);
out:
read_unlock(&sk->sk_callback_lock);
ready(sk, bytes);
}
int rds_tcp_listen_init(void)
{
struct sockaddr_in sin;
struct socket *sock = NULL;
int ret;
ret = sock_create(PF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
if (ret < 0)
goto out;
sock->sk->sk_reuse = SK_CAN_REUSE;
rds_tcp_nonagle(sock);
write_lock_bh(&sock->sk->sk_callback_lock);
sock->sk->sk_user_data = sock->sk->sk_data_ready;
sock->sk->sk_data_ready = rds_tcp_listen_data_ready;
write_unlock_bh(&sock->sk->sk_callback_lock);
sin.sin_family = PF_INET,
sin.sin_addr.s_addr = (__force u32)htonl(INADDR_ANY);
sin.sin_port = (__force u16)htons(RDS_TCP_PORT);
ret = sock->ops->bind(sock, (struct sockaddr *)&sin, sizeof(sin));
if (ret < 0)
goto out;
ret = sock->ops->listen(sock, 64);
if (ret < 0)
goto out;
rds_tcp_listen_sock = sock;
sock = NULL;
out:
if (sock)
sock_release(sock);
return ret;
}
void rds_tcp_listen_stop(void)
{
struct socket *sock = rds_tcp_listen_sock;
struct sock *sk;
if (!sock)
return;
sk = sock->sk;
lock_sock(sk);
write_lock_bh(&sk->sk_callback_lock);
if (sk->sk_user_data) {
sk->sk_data_ready = sk->sk_user_data;
sk->sk_user_data = NULL;
}
write_unlock_bh(&sk->sk_callback_lock);
release_sock(sk);
flush_workqueue(rds_wq);
sock_release(sock);
rds_tcp_listen_sock = NULL;
}
