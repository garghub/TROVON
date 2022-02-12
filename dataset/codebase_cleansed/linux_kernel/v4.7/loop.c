static int rds_loop_xmit(struct rds_connection *conn, struct rds_message *rm,
unsigned int hdr_off, unsigned int sg,
unsigned int off)
{
struct scatterlist *sgp = &rm->data.op_sg[sg];
int ret = sizeof(struct rds_header) +
be32_to_cpu(rm->m_inc.i_hdr.h_len);
if (rm->m_inc.i_hdr.h_flags & RDS_FLAG_CONG_BITMAP) {
rds_cong_map_updated(conn->c_fcong, ~(u64) 0);
ret = min_t(int, ret, sgp->length - conn->c_xmit_data_off);
goto out;
}
BUG_ON(hdr_off || sg || off);
rds_inc_init(&rm->m_inc, conn, conn->c_laddr);
rds_message_addref(rm);
rds_recv_incoming(conn, conn->c_laddr, conn->c_faddr, &rm->m_inc,
GFP_KERNEL);
rds_send_drop_acked(conn, be64_to_cpu(rm->m_inc.i_hdr.h_sequence),
NULL);
rds_inc_put(&rm->m_inc);
out:
return ret;
}
static void rds_loop_inc_free(struct rds_incoming *inc)
{
struct rds_message *rm = container_of(inc, struct rds_message, m_inc);
rds_message_put(rm);
}
static int rds_loop_recv(struct rds_connection *conn)
{
return 0;
}
static int rds_loop_conn_alloc(struct rds_connection *conn, gfp_t gfp)
{
struct rds_loop_connection *lc;
unsigned long flags;
lc = kzalloc(sizeof(struct rds_loop_connection), gfp);
if (!lc)
return -ENOMEM;
INIT_LIST_HEAD(&lc->loop_node);
lc->conn = conn;
conn->c_transport_data = lc;
spin_lock_irqsave(&loop_conns_lock, flags);
list_add_tail(&lc->loop_node, &loop_conns);
spin_unlock_irqrestore(&loop_conns_lock, flags);
return 0;
}
static void rds_loop_conn_free(void *arg)
{
struct rds_loop_connection *lc = arg;
unsigned long flags;
rdsdebug("lc %p\n", lc);
spin_lock_irqsave(&loop_conns_lock, flags);
list_del(&lc->loop_node);
spin_unlock_irqrestore(&loop_conns_lock, flags);
kfree(lc);
}
static int rds_loop_conn_connect(struct rds_connection *conn)
{
rds_connect_complete(conn);
return 0;
}
static void rds_loop_conn_shutdown(struct rds_connection *conn)
{
}
void rds_loop_exit(void)
{
struct rds_loop_connection *lc, *_lc;
LIST_HEAD(tmp_list);
spin_lock_irq(&loop_conns_lock);
list_splice(&loop_conns, &tmp_list);
INIT_LIST_HEAD(&loop_conns);
spin_unlock_irq(&loop_conns_lock);
list_for_each_entry_safe(lc, _lc, &tmp_list, loop_node) {
WARN_ON(lc->conn->c_passive);
rds_conn_destroy(lc->conn);
}
}
