static void rds_tcp_cork(struct socket *sock, int val)
{
mm_segment_t oldfs;
oldfs = get_fs();
set_fs(KERNEL_DS);
sock->ops->setsockopt(sock, SOL_TCP, TCP_CORK, (char __user *)&val,
sizeof(val));
set_fs(oldfs);
}
void rds_tcp_xmit_prepare(struct rds_connection *conn)
{
struct rds_tcp_connection *tc = conn->c_transport_data;
rds_tcp_cork(tc->t_sock, 1);
}
void rds_tcp_xmit_complete(struct rds_connection *conn)
{
struct rds_tcp_connection *tc = conn->c_transport_data;
rds_tcp_cork(tc->t_sock, 0);
}
static int rds_tcp_sendmsg(struct socket *sock, void *data, unsigned int len)
{
struct kvec vec = {
.iov_base = data,
.iov_len = len,
};
struct msghdr msg = {
.msg_flags = MSG_DONTWAIT | MSG_NOSIGNAL,
};
return kernel_sendmsg(sock, &msg, &vec, 1, vec.iov_len);
}
int rds_tcp_xmit(struct rds_connection *conn, struct rds_message *rm,
unsigned int hdr_off, unsigned int sg, unsigned int off)
{
struct rds_tcp_connection *tc = conn->c_transport_data;
int done = 0;
int ret = 0;
if (hdr_off == 0) {
tc->t_last_sent_nxt = rds_tcp_snd_nxt(tc);
rm->m_ack_seq = tc->t_last_sent_nxt +
sizeof(struct rds_header) +
be32_to_cpu(rm->m_inc.i_hdr.h_len) - 1;
smp_mb__before_clear_bit();
set_bit(RDS_MSG_HAS_ACK_SEQ, &rm->m_flags);
tc->t_last_expected_una = rm->m_ack_seq + 1;
rdsdebug("rm %p tcp nxt %u ack_seq %llu\n",
rm, rds_tcp_snd_nxt(tc),
(unsigned long long)rm->m_ack_seq);
}
if (hdr_off < sizeof(struct rds_header)) {
set_bit(SOCK_NOSPACE, &tc->t_sock->sk->sk_socket->flags);
ret = rds_tcp_sendmsg(tc->t_sock,
(void *)&rm->m_inc.i_hdr + hdr_off,
sizeof(rm->m_inc.i_hdr) - hdr_off);
if (ret < 0)
goto out;
done += ret;
if (hdr_off + done != sizeof(struct rds_header))
goto out;
}
while (sg < rm->data.op_nents) {
ret = tc->t_sock->ops->sendpage(tc->t_sock,
sg_page(&rm->data.op_sg[sg]),
rm->data.op_sg[sg].offset + off,
rm->data.op_sg[sg].length - off,
MSG_DONTWAIT|MSG_NOSIGNAL);
rdsdebug("tcp sendpage %p:%u:%u ret %d\n", (void *)sg_page(&rm->data.op_sg[sg]),
rm->data.op_sg[sg].offset + off, rm->data.op_sg[sg].length - off,
ret);
if (ret <= 0)
break;
off += ret;
done += ret;
if (off == rm->data.op_sg[sg].length) {
off = 0;
sg++;
}
}
out:
if (ret <= 0) {
if (ret == -EAGAIN) {
rds_tcp_stats_inc(s_tcp_sndbuf_full);
ret = 0;
} else {
printk(KERN_WARNING "RDS/tcp: send to %pI4 "
"returned %d, disconnecting and reconnecting\n",
&conn->c_faddr, ret);
rds_conn_drop(conn);
}
}
if (done == 0)
done = ret;
return done;
}
static int rds_tcp_is_acked(struct rds_message *rm, uint64_t ack)
{
if (!test_bit(RDS_MSG_HAS_ACK_SEQ, &rm->m_flags))
return 0;
return (__s32)((u32)rm->m_ack_seq - (u32)ack) < 0;
}
void rds_tcp_write_space(struct sock *sk)
{
void (*write_space)(struct sock *sk);
struct rds_connection *conn;
struct rds_tcp_connection *tc;
read_lock(&sk->sk_callback_lock);
conn = sk->sk_user_data;
if (!conn) {
write_space = sk->sk_write_space;
goto out;
}
tc = conn->c_transport_data;
rdsdebug("write_space for tc %p\n", tc);
write_space = tc->t_orig_write_space;
rds_tcp_stats_inc(s_tcp_write_space_calls);
rdsdebug("tcp una %u\n", rds_tcp_snd_una(tc));
tc->t_last_seen_una = rds_tcp_snd_una(tc);
rds_send_drop_acked(conn, rds_tcp_snd_una(tc), rds_tcp_is_acked);
if ((atomic_read(&sk->sk_wmem_alloc) << 1) <= sk->sk_sndbuf)
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
out:
read_unlock(&sk->sk_callback_lock);
write_space(sk);
if (sk->sk_socket)
set_bit(SOCK_NOSPACE, &sk->sk_socket->flags);
}
