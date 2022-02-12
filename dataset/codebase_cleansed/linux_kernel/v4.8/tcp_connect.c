void rds_tcp_state_change(struct sock *sk)
{
void (*state_change)(struct sock *sk);
struct rds_conn_path *cp;
struct rds_tcp_connection *tc;
read_lock_bh(&sk->sk_callback_lock);
cp = sk->sk_user_data;
if (!cp) {
state_change = sk->sk_state_change;
goto out;
}
tc = cp->cp_transport_data;
state_change = tc->t_orig_state_change;
rdsdebug("sock %p state_change to %d\n", tc->t_sock, sk->sk_state);
switch (sk->sk_state) {
case TCP_SYN_SENT:
case TCP_SYN_RECV:
break;
case TCP_ESTABLISHED:
rds_connect_path_complete(cp, RDS_CONN_CONNECTING);
break;
case TCP_CLOSE_WAIT:
case TCP_CLOSE:
rds_conn_path_drop(cp);
default:
break;
}
out:
read_unlock_bh(&sk->sk_callback_lock);
state_change(sk);
}
int rds_tcp_conn_path_connect(struct rds_conn_path *cp)
{
struct socket *sock = NULL;
struct sockaddr_in src, dest;
int ret;
struct rds_connection *conn = cp->cp_conn;
struct rds_tcp_connection *tc = cp->cp_transport_data;
if (cp->cp_index > 0 && cp->cp_conn->c_npaths < 2)
return -EAGAIN;
mutex_lock(&tc->t_conn_path_lock);
if (rds_conn_path_up(cp)) {
mutex_unlock(&tc->t_conn_path_lock);
return 0;
}
ret = sock_create_kern(rds_conn_net(conn), PF_INET,
SOCK_STREAM, IPPROTO_TCP, &sock);
if (ret < 0)
goto out;
rds_tcp_tune(sock);
src.sin_family = AF_INET;
src.sin_addr.s_addr = (__force u32)conn->c_laddr;
src.sin_port = (__force u16)htons(0);
ret = sock->ops->bind(sock, (struct sockaddr *)&src, sizeof(src));
if (ret) {
rdsdebug("bind failed with %d at address %pI4\n",
ret, &conn->c_laddr);
goto out;
}
dest.sin_family = AF_INET;
dest.sin_addr.s_addr = (__force u32)conn->c_faddr;
dest.sin_port = (__force u16)htons(RDS_TCP_PORT);
rds_tcp_set_callbacks(sock, cp);
ret = sock->ops->connect(sock, (struct sockaddr *)&dest, sizeof(dest),
O_NONBLOCK);
cp->cp_outgoing = 1;
rdsdebug("connect to address %pI4 returned %d\n", &conn->c_faddr, ret);
if (ret == -EINPROGRESS)
ret = 0;
if (ret == 0) {
rds_tcp_keepalive(sock);
sock = NULL;
} else {
rds_tcp_restore_callbacks(sock, cp->cp_transport_data);
}
out:
mutex_unlock(&tc->t_conn_path_lock);
if (sock)
sock_release(sock);
return ret;
}
void rds_tcp_conn_path_shutdown(struct rds_conn_path *cp)
{
struct rds_tcp_connection *tc = cp->cp_transport_data;
struct socket *sock = tc->t_sock;
rdsdebug("shutting down conn %p tc %p sock %p\n",
cp->cp_conn, tc, sock);
if (sock) {
sock->ops->shutdown(sock, RCV_SHUTDOWN | SEND_SHUTDOWN);
lock_sock(sock->sk);
rds_tcp_restore_callbacks(sock, tc);
release_sock(sock->sk);
sock_release(sock);
}
if (tc->t_tinc) {
rds_inc_put(&tc->t_tinc->ti_inc);
tc->t_tinc = NULL;
}
tc->t_tinc_hdr_rem = sizeof(struct rds_header);
tc->t_tinc_data_rem = 0;
}
