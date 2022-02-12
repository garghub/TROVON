void rds_connect_complete(struct rds_connection *conn)
{
if (!rds_conn_transition(conn, RDS_CONN_CONNECTING, RDS_CONN_UP)) {
printk(KERN_WARNING "%s: Cannot transition to state UP, "
"current state is %d\n",
__func__,
atomic_read(&conn->c_state));
rds_conn_drop(conn);
return;
}
rdsdebug("conn %p for %pI4 to %pI4 complete\n",
conn, &conn->c_laddr, &conn->c_faddr);
conn->c_reconnect_jiffies = 0;
set_bit(0, &conn->c_map_queued);
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
queue_delayed_work(rds_wq, &conn->c_recv_w, 0);
}
void rds_queue_reconnect(struct rds_connection *conn)
{
unsigned long rand;
rdsdebug("conn %p for %pI4 to %pI4 reconnect jiffies %lu\n",
conn, &conn->c_laddr, &conn->c_faddr,
conn->c_reconnect_jiffies);
set_bit(RDS_RECONNECT_PENDING, &conn->c_flags);
if (conn->c_reconnect_jiffies == 0) {
conn->c_reconnect_jiffies = rds_sysctl_reconnect_min_jiffies;
queue_delayed_work(rds_wq, &conn->c_conn_w, 0);
return;
}
get_random_bytes(&rand, sizeof(rand));
rdsdebug("%lu delay %lu ceil conn %p for %pI4 -> %pI4\n",
rand % conn->c_reconnect_jiffies, conn->c_reconnect_jiffies,
conn, &conn->c_laddr, &conn->c_faddr);
queue_delayed_work(rds_wq, &conn->c_conn_w,
rand % conn->c_reconnect_jiffies);
conn->c_reconnect_jiffies = min(conn->c_reconnect_jiffies * 2,
rds_sysctl_reconnect_max_jiffies);
}
void rds_connect_worker(struct work_struct *work)
{
struct rds_connection *conn = container_of(work, struct rds_connection, c_conn_w.work);
int ret;
clear_bit(RDS_RECONNECT_PENDING, &conn->c_flags);
if (rds_conn_transition(conn, RDS_CONN_DOWN, RDS_CONN_CONNECTING)) {
ret = conn->c_trans->conn_connect(conn);
rdsdebug("conn %p for %pI4 to %pI4 dispatched, ret %d\n",
conn, &conn->c_laddr, &conn->c_faddr, ret);
if (ret) {
if (rds_conn_transition(conn, RDS_CONN_CONNECTING, RDS_CONN_DOWN))
rds_queue_reconnect(conn);
else
rds_conn_error(conn, "RDS: connect failed\n");
}
}
}
void rds_send_worker(struct work_struct *work)
{
struct rds_connection *conn = container_of(work, struct rds_connection, c_send_w.work);
int ret;
if (rds_conn_state(conn) == RDS_CONN_UP) {
ret = rds_send_xmit(conn);
rdsdebug("conn %p ret %d\n", conn, ret);
switch (ret) {
case -EAGAIN:
rds_stats_inc(s_send_immediate_retry);
queue_delayed_work(rds_wq, &conn->c_send_w, 0);
break;
case -ENOMEM:
rds_stats_inc(s_send_delayed_retry);
queue_delayed_work(rds_wq, &conn->c_send_w, 2);
default:
break;
}
}
}
void rds_recv_worker(struct work_struct *work)
{
struct rds_connection *conn = container_of(work, struct rds_connection, c_recv_w.work);
int ret;
if (rds_conn_state(conn) == RDS_CONN_UP) {
ret = conn->c_trans->recv(conn);
rdsdebug("conn %p ret %d\n", conn, ret);
switch (ret) {
case -EAGAIN:
rds_stats_inc(s_recv_immediate_retry);
queue_delayed_work(rds_wq, &conn->c_recv_w, 0);
break;
case -ENOMEM:
rds_stats_inc(s_recv_delayed_retry);
queue_delayed_work(rds_wq, &conn->c_recv_w, 2);
default:
break;
}
}
}
void rds_shutdown_worker(struct work_struct *work)
{
struct rds_connection *conn = container_of(work, struct rds_connection, c_down_w);
rds_conn_shutdown(conn);
}
void rds_threads_exit(void)
{
destroy_workqueue(rds_wq);
}
int rds_threads_init(void)
{
rds_wq = create_singlethread_workqueue("krdsd");
if (!rds_wq)
return -ENOMEM;
return 0;
}
