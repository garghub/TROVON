static void smc_rx_data_ready(struct sock *sk)
{
struct socket_wq *wq;
rcu_read_lock();
wq = rcu_dereference(sk->sk_wq);
if (skwq_has_sleeper(wq))
wake_up_interruptible_sync_poll(&wq->wait, POLLIN | POLLPRI |
POLLRDNORM | POLLRDBAND);
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_IN);
if ((sk->sk_shutdown == SHUTDOWN_MASK) ||
(sk->sk_state == SMC_CLOSED))
sk_wake_async(sk, SOCK_WAKE_WAITD, POLL_HUP);
rcu_read_unlock();
}
static int smc_rx_wait_data(struct smc_sock *smc, long *timeo)
{
DEFINE_WAIT_FUNC(wait, woken_wake_function);
struct smc_connection *conn = &smc->conn;
struct sock *sk = &smc->sk;
int rc;
if (atomic_read(&conn->bytes_to_rcv))
return 1;
sk_set_bit(SOCKWQ_ASYNC_WAITDATA, sk);
add_wait_queue(sk_sleep(sk), &wait);
rc = sk_wait_event(sk, timeo,
sk->sk_err ||
sk->sk_shutdown & RCV_SHUTDOWN ||
sock_flag(sk, SOCK_DONE) ||
atomic_read(&conn->bytes_to_rcv) ||
smc_cdc_rxed_any_close_or_senddone(conn),
&wait);
remove_wait_queue(sk_sleep(sk), &wait);
sk_clear_bit(SOCKWQ_ASYNC_WAITDATA, sk);
return rc;
}
int smc_rx_recvmsg(struct smc_sock *smc, struct msghdr *msg, size_t len,
int flags)
{
size_t copylen, read_done = 0, read_remaining = len;
size_t chunk_len, chunk_off, chunk_len_sum;
struct smc_connection *conn = &smc->conn;
union smc_host_cursor cons;
int readable, chunk;
char *rcvbuf_base;
struct sock *sk;
long timeo;
int target;
int rc;
if (unlikely(flags & MSG_ERRQUEUE))
return -EINVAL;
if (flags & MSG_OOB)
return -EINVAL;
sk = &smc->sk;
if (sk->sk_state == SMC_LISTEN)
return -ENOTCONN;
timeo = sock_rcvtimeo(sk, flags & MSG_DONTWAIT);
target = sock_rcvlowat(sk, flags & MSG_WAITALL, len);
msg->msg_namelen = 0;
rcvbuf_base = conn->rmb_desc->cpu_addr;
do {
if (read_done >= target)
break;
if (atomic_read(&conn->bytes_to_rcv))
goto copy;
if (read_done) {
if (sk->sk_err ||
sk->sk_state == SMC_CLOSED ||
(sk->sk_shutdown & RCV_SHUTDOWN) ||
!timeo ||
signal_pending(current) ||
smc_cdc_rxed_any_close_or_senddone(conn) ||
conn->local_tx_ctrl.conn_state_flags.
peer_conn_abort)
break;
} else {
if (sock_flag(sk, SOCK_DONE))
break;
if (sk->sk_err) {
read_done = sock_error(sk);
break;
}
if (sk->sk_shutdown & RCV_SHUTDOWN ||
smc_cdc_rxed_any_close_or_senddone(conn) ||
conn->local_tx_ctrl.conn_state_flags.
peer_conn_abort)
break;
if (sk->sk_state == SMC_CLOSED) {
if (!sock_flag(sk, SOCK_DONE)) {
read_done = -ENOTCONN;
break;
}
break;
}
if (signal_pending(current)) {
read_done = sock_intr_errno(timeo);
break;
}
if (!timeo)
return -EAGAIN;
}
if (!atomic_read(&conn->bytes_to_rcv)) {
smc_rx_wait_data(smc, &timeo);
continue;
}
copy:
readable = atomic_read(&conn->bytes_to_rcv);
copylen = min_t(size_t, read_remaining, readable);
smc_curs_write(&cons,
smc_curs_read(&conn->local_tx_ctrl.cons, conn),
conn);
chunk_len = min_t(size_t,
copylen, conn->rmbe_size - cons.count);
chunk_len_sum = chunk_len;
chunk_off = cons.count;
smc_rmb_sync_sg_for_cpu(conn);
for (chunk = 0; chunk < 2; chunk++) {
if (!(flags & MSG_TRUNC)) {
rc = memcpy_to_msg(msg, rcvbuf_base + chunk_off,
chunk_len);
if (rc) {
if (!read_done)
read_done = -EFAULT;
smc_rmb_sync_sg_for_device(conn);
goto out;
}
}
read_remaining -= chunk_len;
read_done += chunk_len;
if (chunk_len_sum == copylen)
break;
chunk_len = copylen - chunk_len;
chunk_len_sum += chunk_len;
chunk_off = 0;
}
smc_rmb_sync_sg_for_device(conn);
if (!(flags & MSG_PEEK)) {
smc_curs_add(conn->rmbe_size, &cons, copylen);
smp_mb__before_atomic();
atomic_sub(copylen, &conn->bytes_to_rcv);
smp_mb__after_atomic();
smc_curs_write(&conn->local_tx_ctrl.cons,
smc_curs_read(&cons, conn),
conn);
smc_tx_consumer_update(conn);
}
} while (read_remaining);
out:
return read_done;
}
void smc_rx_init(struct smc_sock *smc)
{
smc->sk.sk_data_ready = smc_rx_data_ready;
}
