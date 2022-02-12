int rds_tcp_keepalive(struct socket *sock)
{
int keepidle = 5;
int keepcnt = 5;
int keepalive = 1;
int ret = 0;
ret = kernel_setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE,
(char *)&keepalive, sizeof(keepalive));
if (ret < 0)
goto bail;
ret = kernel_setsockopt(sock, IPPROTO_TCP, TCP_KEEPCNT,
(char *)&keepcnt, sizeof(keepcnt));
if (ret < 0)
goto bail;
ret = kernel_setsockopt(sock, IPPROTO_TCP, TCP_KEEPIDLE,
(char *)&keepidle, sizeof(keepidle));
if (ret < 0)
goto bail;
ret = kernel_setsockopt(sock, IPPROTO_TCP, TCP_KEEPINTVL,
(char *)&keepidle, sizeof(keepidle));
bail:
return ret;
}
struct rds_tcp_connection *rds_tcp_accept_one_path(struct rds_connection *conn)
{
int i;
bool peer_is_smaller = (conn->c_faddr < conn->c_laddr);
int npaths = max_t(int, 1, conn->c_npaths);
if (!peer_is_smaller) {
if (npaths == 1)
rds_conn_path_connect_if_down(&conn->c_path[0]);
return NULL;
}
for (i = 0; i < npaths; i++) {
struct rds_conn_path *cp = &conn->c_path[i];
if (rds_conn_path_transition(cp, RDS_CONN_DOWN,
RDS_CONN_CONNECTING) ||
rds_conn_path_transition(cp, RDS_CONN_ERROR,
RDS_CONN_CONNECTING)) {
return cp->cp_transport_data;
}
}
return NULL;
}
int rds_tcp_accept_one(struct socket *sock)
{
struct socket *new_sock = NULL;
struct rds_connection *conn;
int ret;
struct inet_sock *inet;
struct rds_tcp_connection *rs_tcp = NULL;
int conn_state;
struct rds_conn_path *cp;
if (!sock)
return -ENETUNREACH;
ret = sock_create_kern(sock_net(sock->sk), sock->sk->sk_family,
sock->sk->sk_type, sock->sk->sk_protocol,
&new_sock);
if (ret)
goto out;
new_sock->type = sock->type;
new_sock->ops = sock->ops;
ret = sock->ops->accept(sock, new_sock, O_NONBLOCK);
if (ret < 0)
goto out;
ret = rds_tcp_keepalive(new_sock);
if (ret < 0)
goto out;
rds_tcp_tune(new_sock);
inet = inet_sk(new_sock->sk);
rdsdebug("accepted tcp %pI4:%u -> %pI4:%u\n",
&inet->inet_saddr, ntohs(inet->inet_sport),
&inet->inet_daddr, ntohs(inet->inet_dport));
conn = rds_conn_create(sock_net(sock->sk),
inet->inet_saddr, inet->inet_daddr,
&rds_tcp_transport, GFP_KERNEL);
if (IS_ERR(conn)) {
ret = PTR_ERR(conn);
goto out;
}
rs_tcp = rds_tcp_accept_one_path(conn);
if (!rs_tcp)
goto rst_nsk;
mutex_lock(&rs_tcp->t_conn_path_lock);
cp = rs_tcp->t_cpath;
conn_state = rds_conn_path_state(cp);
WARN_ON(conn_state == RDS_CONN_UP);
if (conn_state != RDS_CONN_CONNECTING && conn_state != RDS_CONN_ERROR)
goto rst_nsk;
if (rs_tcp->t_sock) {
if (ntohl(inet->inet_saddr) < ntohl(inet->inet_daddr) ||
!cp->cp_outgoing) {
goto rst_nsk;
} else {
rds_tcp_reset_callbacks(new_sock, cp);
cp->cp_outgoing = 0;
rds_connect_path_complete(cp, RDS_CONN_RESETTING);
}
} else {
rds_tcp_set_callbacks(new_sock, cp);
rds_connect_path_complete(cp, RDS_CONN_CONNECTING);
}
new_sock = NULL;
ret = 0;
goto out;
rst_nsk:
kernel_sock_shutdown(new_sock, SHUT_RDWR);
ret = 0;
out:
if (rs_tcp)
mutex_unlock(&rs_tcp->t_conn_path_lock);
if (new_sock)
sock_release(new_sock);
return ret;
}
void rds_tcp_listen_data_ready(struct sock *sk)
{
void (*ready)(struct sock *sk);
rdsdebug("listen data ready sk %p\n", sk);
read_lock_bh(&sk->sk_callback_lock);
ready = sk->sk_user_data;
if (!ready) {
ready = sk->sk_data_ready;
goto out;
}
if (sk->sk_state == TCP_LISTEN)
rds_tcp_accept_work(sk);
else
ready = rds_tcp_listen_sock_def_readable(sock_net(sk));
out:
read_unlock_bh(&sk->sk_callback_lock);
ready(sk);
}
struct socket *rds_tcp_listen_init(struct net *net)
{
struct sockaddr_in sin;
struct socket *sock = NULL;
int ret;
ret = sock_create_kern(net, PF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
if (ret < 0)
goto out;
sock->sk->sk_reuse = SK_CAN_REUSE;
rds_tcp_nonagle(sock);
write_lock_bh(&sock->sk->sk_callback_lock);
sock->sk->sk_user_data = sock->sk->sk_data_ready;
sock->sk->sk_data_ready = rds_tcp_listen_data_ready;
write_unlock_bh(&sock->sk->sk_callback_lock);
sin.sin_family = PF_INET;
sin.sin_addr.s_addr = (__force u32)htonl(INADDR_ANY);
sin.sin_port = (__force u16)htons(RDS_TCP_PORT);
ret = sock->ops->bind(sock, (struct sockaddr *)&sin, sizeof(sin));
if (ret < 0)
goto out;
ret = sock->ops->listen(sock, 64);
if (ret < 0)
goto out;
return sock;
out:
if (sock)
sock_release(sock);
return NULL;
}
void rds_tcp_listen_stop(struct socket *sock)
{
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
}
