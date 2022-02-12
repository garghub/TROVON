void rds_connect_path_complete(struct rds_conn_path *cp, int curr)
{
if (!rds_conn_path_transition(cp, curr, RDS_CONN_UP)) {
printk(KERN_WARNING "%s: Cannot transition to state UP, "
"current state is %d\n",
__func__,
atomic_read(&cp->cp_state));
rds_conn_path_drop(cp);
return;
}
rdsdebug("conn %p for %pI4 to %pI4 complete\n",
cp->cp_conn, &cp->cp_conn->c_laddr, &cp->cp_conn->c_faddr);
cp->cp_reconnect_jiffies = 0;
set_bit(0, &cp->cp_conn->c_map_queued);
queue_delayed_work(rds_wq, &cp->cp_send_w, 0);
queue_delayed_work(rds_wq, &cp->cp_recv_w, 0);
}
void rds_connect_complete(struct rds_connection *conn)
{
rds_connect_path_complete(&conn->c_path[0], RDS_CONN_CONNECTING);
}
void rds_queue_reconnect(struct rds_conn_path *cp)
{
unsigned long rand;
struct rds_connection *conn = cp->cp_conn;
rdsdebug("conn %p for %pI4 to %pI4 reconnect jiffies %lu\n",
conn, &conn->c_laddr, &conn->c_faddr,
cp->cp_reconnect_jiffies);
if (conn->c_trans->t_type == RDS_TRANS_TCP &&
conn->c_laddr > conn->c_faddr)
return;
set_bit(RDS_RECONNECT_PENDING, &cp->cp_flags);
if (cp->cp_reconnect_jiffies == 0) {
cp->cp_reconnect_jiffies = rds_sysctl_reconnect_min_jiffies;
queue_delayed_work(rds_wq, &cp->cp_conn_w, 0);
return;
}
get_random_bytes(&rand, sizeof(rand));
rdsdebug("%lu delay %lu ceil conn %p for %pI4 -> %pI4\n",
rand % cp->cp_reconnect_jiffies, cp->cp_reconnect_jiffies,
conn, &conn->c_laddr, &conn->c_faddr);
queue_delayed_work(rds_wq, &cp->cp_conn_w,
rand % cp->cp_reconnect_jiffies);
cp->cp_reconnect_jiffies = min(cp->cp_reconnect_jiffies * 2,
rds_sysctl_reconnect_max_jiffies);
}
void rds_connect_worker(struct work_struct *work)
{
struct rds_conn_path *cp = container_of(work,
struct rds_conn_path,
cp_conn_w.work);
struct rds_connection *conn = cp->cp_conn;
int ret;
if (cp->cp_index > 1 && cp->cp_conn->c_laddr > cp->cp_conn->c_faddr)
return;
clear_bit(RDS_RECONNECT_PENDING, &cp->cp_flags);
ret = rds_conn_path_transition(cp, RDS_CONN_DOWN, RDS_CONN_CONNECTING);
if (ret) {
ret = conn->c_trans->conn_path_connect(cp);
rdsdebug("conn %p for %pI4 to %pI4 dispatched, ret %d\n",
conn, &conn->c_laddr, &conn->c_faddr, ret);
if (ret) {
if (rds_conn_path_transition(cp,
RDS_CONN_CONNECTING,
RDS_CONN_DOWN))
rds_queue_reconnect(cp);
else
rds_conn_path_error(cp, "connect failed\n");
}
}
}
void rds_send_worker(struct work_struct *work)
{
struct rds_conn_path *cp = container_of(work,
struct rds_conn_path,
cp_send_w.work);
int ret;
if (rds_conn_path_state(cp) == RDS_CONN_UP) {
clear_bit(RDS_LL_SEND_FULL, &cp->cp_flags);
ret = rds_send_xmit(cp);
cond_resched();
rdsdebug("conn %p ret %d\n", cp->cp_conn, ret);
switch (ret) {
case -EAGAIN:
rds_stats_inc(s_send_immediate_retry);
queue_delayed_work(rds_wq, &cp->cp_send_w, 0);
break;
case -ENOMEM:
rds_stats_inc(s_send_delayed_retry);
queue_delayed_work(rds_wq, &cp->cp_send_w, 2);
default:
break;
}
}
}
void rds_recv_worker(struct work_struct *work)
{
struct rds_conn_path *cp = container_of(work,
struct rds_conn_path,
cp_recv_w.work);
int ret;
if (rds_conn_path_state(cp) == RDS_CONN_UP) {
ret = cp->cp_conn->c_trans->recv_path(cp);
rdsdebug("conn %p ret %d\n", cp->cp_conn, ret);
switch (ret) {
case -EAGAIN:
rds_stats_inc(s_recv_immediate_retry);
queue_delayed_work(rds_wq, &cp->cp_recv_w, 0);
break;
case -ENOMEM:
rds_stats_inc(s_recv_delayed_retry);
queue_delayed_work(rds_wq, &cp->cp_recv_w, 2);
default:
break;
}
}
}
void rds_shutdown_worker(struct work_struct *work)
{
struct rds_conn_path *cp = container_of(work,
struct rds_conn_path,
cp_down_w);
rds_conn_shutdown(cp);
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
