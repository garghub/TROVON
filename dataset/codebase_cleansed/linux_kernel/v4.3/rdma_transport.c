int rds_rdma_cm_event_handler(struct rdma_cm_id *cm_id,
struct rdma_cm_event *event)
{
struct rds_connection *conn = cm_id->context;
struct rds_transport *trans;
int ret = 0;
rdsdebug("conn %p id %p handling event %u (%s)\n", conn, cm_id,
event->event, rdma_event_msg(event->event));
if (cm_id->device->node_type == RDMA_NODE_RNIC)
trans = &rds_iw_transport;
else
trans = &rds_ib_transport;
if (conn) {
mutex_lock(&conn->c_cm_lock);
if (rds_conn_state(conn) == RDS_CONN_DISCONNECTING) {
if (event->event == RDMA_CM_EVENT_CONNECT_REQUEST)
ret = 1;
goto out;
}
}
switch (event->event) {
case RDMA_CM_EVENT_CONNECT_REQUEST:
ret = trans->cm_handle_connect(cm_id, event);
break;
case RDMA_CM_EVENT_ADDR_RESOLVED:
ret = rdma_resolve_route(cm_id,
RDS_RDMA_RESOLVE_TIMEOUT_MS);
break;
case RDMA_CM_EVENT_ROUTE_RESOLVED:
if (conn) {
struct rds_ib_connection *ibic;
ibic = conn->c_transport_data;
if (ibic && ibic->i_cm_id == cm_id)
ret = trans->cm_initiate_connect(cm_id);
else
rds_conn_drop(conn);
}
break;
case RDMA_CM_EVENT_ESTABLISHED:
trans->cm_connect_complete(conn, event);
break;
case RDMA_CM_EVENT_ADDR_ERROR:
case RDMA_CM_EVENT_ROUTE_ERROR:
case RDMA_CM_EVENT_CONNECT_ERROR:
case RDMA_CM_EVENT_UNREACHABLE:
case RDMA_CM_EVENT_REJECTED:
case RDMA_CM_EVENT_DEVICE_REMOVAL:
case RDMA_CM_EVENT_ADDR_CHANGE:
if (conn)
rds_conn_drop(conn);
break;
case RDMA_CM_EVENT_DISCONNECTED:
rdsdebug("DISCONNECT event - dropping connection "
"%pI4->%pI4\n", &conn->c_laddr,
&conn->c_faddr);
rds_conn_drop(conn);
break;
default:
printk(KERN_ERR "RDS: unknown event %u (%s)!\n",
event->event, rdma_event_msg(event->event));
break;
}
out:
if (conn)
mutex_unlock(&conn->c_cm_lock);
rdsdebug("id %p event %u (%s) handling ret %d\n", cm_id, event->event,
rdma_event_msg(event->event), ret);
return ret;
}
static int rds_rdma_listen_init(void)
{
struct sockaddr_in sin;
struct rdma_cm_id *cm_id;
int ret;
cm_id = rdma_create_id(rds_rdma_cm_event_handler, NULL, RDMA_PS_TCP,
IB_QPT_RC);
if (IS_ERR(cm_id)) {
ret = PTR_ERR(cm_id);
printk(KERN_ERR "RDS/RDMA: failed to setup listener, "
"rdma_create_id() returned %d\n", ret);
return ret;
}
sin.sin_family = AF_INET;
sin.sin_addr.s_addr = (__force u32)htonl(INADDR_ANY);
sin.sin_port = (__force u16)htons(RDS_PORT);
ret = rdma_bind_addr(cm_id, (struct sockaddr *)&sin);
if (ret) {
printk(KERN_ERR "RDS/RDMA: failed to setup listener, "
"rdma_bind_addr() returned %d\n", ret);
goto out;
}
ret = rdma_listen(cm_id, 128);
if (ret) {
printk(KERN_ERR "RDS/RDMA: failed to setup listener, "
"rdma_listen() returned %d\n", ret);
goto out;
}
rdsdebug("cm %p listening on port %u\n", cm_id, RDS_PORT);
rds_rdma_listen_id = cm_id;
cm_id = NULL;
out:
if (cm_id)
rdma_destroy_id(cm_id);
return ret;
}
static void rds_rdma_listen_stop(void)
{
if (rds_rdma_listen_id) {
rdsdebug("cm %p\n", rds_rdma_listen_id);
rdma_destroy_id(rds_rdma_listen_id);
rds_rdma_listen_id = NULL;
}
}
static int rds_rdma_init(void)
{
int ret;
ret = rds_rdma_listen_init();
if (ret)
goto out;
ret = rds_iw_init();
if (ret)
goto err_iw_init;
ret = rds_ib_init();
if (ret)
goto err_ib_init;
goto out;
err_ib_init:
rds_iw_exit();
err_iw_init:
rds_rdma_listen_stop();
out:
return ret;
}
static void rds_rdma_exit(void)
{
rds_rdma_listen_stop();
rds_ib_exit();
rds_iw_exit();
}
