void rds_tcp_state_change(struct sock *sk)
{
void (*state_change)(struct sock *sk);
struct rds_connection *conn;
struct rds_tcp_connection *tc;
read_lock(&sk->sk_callback_lock);
conn = sk->sk_user_data;
if (!conn) {
state_change = sk->sk_state_change;
goto out;
}
tc = conn->c_transport_data;
state_change = tc->t_orig_state_change;
rdsdebug("sock %p state_change to %d\n", tc->t_sock, sk->sk_state);
switch(sk->sk_state) {
case TCP_SYN_SENT:
case TCP_SYN_RECV:
break;
case TCP_ESTABLISHED:
rds_connect_complete(conn);
break;
case TCP_CLOSE:
rds_conn_drop(conn);
default:
break;
}
out:
read_unlock(&sk->sk_callback_lock);
state_change(sk);
}
int rds_tcp_conn_connect(struct rds_connection *conn)
{
struct socket *sock = NULL;
struct sockaddr_in src, dest;
int ret;
ret = sock_create(PF_INET, SOCK_STREAM, IPPROTO_TCP, &sock);
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
rds_tcp_set_callbacks(sock, conn);
ret = sock->ops->connect(sock, (struct sockaddr *)&dest, sizeof(dest),
O_NONBLOCK);
rdsdebug("connect to address %pI4 returned %d\n", &conn->c_faddr, ret);
if (ret == -EINPROGRESS)
ret = 0;
if (ret == 0)
sock = NULL;
else
rds_tcp_restore_callbacks(sock, conn->c_transport_data);
out:
if (sock)
sock_release(sock);
return ret;
}
void rds_tcp_conn_shutdown(struct rds_connection *conn)
{
struct rds_tcp_connection *tc = conn->c_transport_data;
struct socket *sock = tc->t_sock;
rdsdebug("shutting down conn %p tc %p sock %p\n", conn, tc, sock);
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
