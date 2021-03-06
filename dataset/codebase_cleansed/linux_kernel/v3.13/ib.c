static void rds_ib_nodev_connect(void)
{
struct rds_ib_connection *ic;
spin_lock(&ib_nodev_conns_lock);
list_for_each_entry(ic, &ib_nodev_conns, ib_node)
rds_conn_connect_if_down(ic->conn);
spin_unlock(&ib_nodev_conns_lock);
}
static void rds_ib_dev_shutdown(struct rds_ib_device *rds_ibdev)
{
struct rds_ib_connection *ic;
unsigned long flags;
spin_lock_irqsave(&rds_ibdev->spinlock, flags);
list_for_each_entry(ic, &rds_ibdev->conn_list, ib_node)
rds_conn_drop(ic->conn);
spin_unlock_irqrestore(&rds_ibdev->spinlock, flags);
}
static void rds_ib_dev_free(struct work_struct *work)
{
struct rds_ib_ipaddr *i_ipaddr, *i_next;
struct rds_ib_device *rds_ibdev = container_of(work,
struct rds_ib_device, free_work);
if (rds_ibdev->mr_pool)
rds_ib_destroy_mr_pool(rds_ibdev->mr_pool);
if (rds_ibdev->mr)
ib_dereg_mr(rds_ibdev->mr);
if (rds_ibdev->pd)
ib_dealloc_pd(rds_ibdev->pd);
list_for_each_entry_safe(i_ipaddr, i_next, &rds_ibdev->ipaddr_list, list) {
list_del(&i_ipaddr->list);
kfree(i_ipaddr);
}
kfree(rds_ibdev);
}
void rds_ib_dev_put(struct rds_ib_device *rds_ibdev)
{
BUG_ON(atomic_read(&rds_ibdev->refcount) <= 0);
if (atomic_dec_and_test(&rds_ibdev->refcount))
queue_work(rds_wq, &rds_ibdev->free_work);
}
static void rds_ib_add_one(struct ib_device *device)
{
struct rds_ib_device *rds_ibdev;
struct ib_device_attr *dev_attr;
if (device->node_type != RDMA_NODE_IB_CA)
return;
dev_attr = kmalloc(sizeof *dev_attr, GFP_KERNEL);
if (!dev_attr)
return;
if (ib_query_device(device, dev_attr)) {
rdsdebug("Query device failed for %s\n", device->name);
goto free_attr;
}
rds_ibdev = kzalloc_node(sizeof(struct rds_ib_device), GFP_KERNEL,
ibdev_to_node(device));
if (!rds_ibdev)
goto free_attr;
spin_lock_init(&rds_ibdev->spinlock);
atomic_set(&rds_ibdev->refcount, 1);
INIT_WORK(&rds_ibdev->free_work, rds_ib_dev_free);
rds_ibdev->max_wrs = dev_attr->max_qp_wr;
rds_ibdev->max_sge = min(dev_attr->max_sge, RDS_IB_MAX_SGE);
rds_ibdev->fmr_max_remaps = dev_attr->max_map_per_fmr?: 32;
rds_ibdev->max_fmrs = dev_attr->max_fmr ?
min_t(unsigned int, dev_attr->max_fmr, fmr_pool_size) :
fmr_pool_size;
rds_ibdev->max_initiator_depth = dev_attr->max_qp_init_rd_atom;
rds_ibdev->max_responder_resources = dev_attr->max_qp_rd_atom;
rds_ibdev->dev = device;
rds_ibdev->pd = ib_alloc_pd(device);
if (IS_ERR(rds_ibdev->pd)) {
rds_ibdev->pd = NULL;
goto put_dev;
}
rds_ibdev->mr = ib_get_dma_mr(rds_ibdev->pd, IB_ACCESS_LOCAL_WRITE);
if (IS_ERR(rds_ibdev->mr)) {
rds_ibdev->mr = NULL;
goto put_dev;
}
rds_ibdev->mr_pool = rds_ib_create_mr_pool(rds_ibdev);
if (IS_ERR(rds_ibdev->mr_pool)) {
rds_ibdev->mr_pool = NULL;
goto put_dev;
}
INIT_LIST_HEAD(&rds_ibdev->ipaddr_list);
INIT_LIST_HEAD(&rds_ibdev->conn_list);
down_write(&rds_ib_devices_lock);
list_add_tail_rcu(&rds_ibdev->list, &rds_ib_devices);
up_write(&rds_ib_devices_lock);
atomic_inc(&rds_ibdev->refcount);
ib_set_client_data(device, &rds_ib_client, rds_ibdev);
atomic_inc(&rds_ibdev->refcount);
rds_ib_nodev_connect();
put_dev:
rds_ib_dev_put(rds_ibdev);
free_attr:
kfree(dev_attr);
}
struct rds_ib_device *rds_ib_get_client_data(struct ib_device *device)
{
struct rds_ib_device *rds_ibdev;
rcu_read_lock();
rds_ibdev = ib_get_client_data(device, &rds_ib_client);
if (rds_ibdev)
atomic_inc(&rds_ibdev->refcount);
rcu_read_unlock();
return rds_ibdev;
}
static void rds_ib_remove_one(struct ib_device *device)
{
struct rds_ib_device *rds_ibdev;
rds_ibdev = ib_get_client_data(device, &rds_ib_client);
if (!rds_ibdev)
return;
rds_ib_dev_shutdown(rds_ibdev);
ib_set_client_data(device, &rds_ib_client, NULL);
down_write(&rds_ib_devices_lock);
list_del_rcu(&rds_ibdev->list);
up_write(&rds_ib_devices_lock);
synchronize_rcu();
rds_ib_dev_put(rds_ibdev);
rds_ib_dev_put(rds_ibdev);
}
static int rds_ib_conn_info_visitor(struct rds_connection *conn,
void *buffer)
{
struct rds_info_rdma_connection *iinfo = buffer;
struct rds_ib_connection *ic;
if (conn->c_trans != &rds_ib_transport)
return 0;
iinfo->src_addr = conn->c_laddr;
iinfo->dst_addr = conn->c_faddr;
memset(&iinfo->src_gid, 0, sizeof(iinfo->src_gid));
memset(&iinfo->dst_gid, 0, sizeof(iinfo->dst_gid));
if (rds_conn_state(conn) == RDS_CONN_UP) {
struct rds_ib_device *rds_ibdev;
struct rdma_dev_addr *dev_addr;
ic = conn->c_transport_data;
dev_addr = &ic->i_cm_id->route.addr.dev_addr;
rdma_addr_get_sgid(dev_addr, (union ib_gid *) &iinfo->src_gid);
rdma_addr_get_dgid(dev_addr, (union ib_gid *) &iinfo->dst_gid);
rds_ibdev = ic->rds_ibdev;
iinfo->max_send_wr = ic->i_send_ring.w_nr;
iinfo->max_recv_wr = ic->i_recv_ring.w_nr;
iinfo->max_send_sge = rds_ibdev->max_sge;
rds_ib_get_mr_info(rds_ibdev, iinfo);
}
return 1;
}
static void rds_ib_ic_info(struct socket *sock, unsigned int len,
struct rds_info_iterator *iter,
struct rds_info_lengths *lens)
{
rds_for_each_conn_info(sock, len, iter, lens,
rds_ib_conn_info_visitor,
sizeof(struct rds_info_rdma_connection));
}
static int rds_ib_laddr_check(__be32 addr)
{
int ret;
struct rdma_cm_id *cm_id;
struct sockaddr_in sin;
cm_id = rdma_create_id(NULL, NULL, RDMA_PS_TCP, IB_QPT_RC);
if (IS_ERR(cm_id))
return PTR_ERR(cm_id);
memset(&sin, 0, sizeof(sin));
sin.sin_family = AF_INET;
sin.sin_addr.s_addr = addr;
ret = rdma_bind_addr(cm_id, (struct sockaddr *)&sin);
if (ret || !cm_id->device ||
cm_id->device->node_type != RDMA_NODE_IB_CA)
ret = -EADDRNOTAVAIL;
rdsdebug("addr %pI4 ret %d node type %d\n",
&addr, ret,
cm_id->device ? cm_id->device->node_type : -1);
rdma_destroy_id(cm_id);
return ret;
}
static void rds_ib_unregister_client(void)
{
ib_unregister_client(&rds_ib_client);
flush_workqueue(rds_wq);
}
void rds_ib_exit(void)
{
rds_info_deregister_func(RDS_INFO_IB_CONNECTIONS, rds_ib_ic_info);
rds_ib_unregister_client();
rds_ib_destroy_nodev_conns();
rds_ib_sysctl_exit();
rds_ib_recv_exit();
rds_trans_unregister(&rds_ib_transport);
}
int rds_ib_init(void)
{
int ret;
INIT_LIST_HEAD(&rds_ib_devices);
ret = ib_register_client(&rds_ib_client);
if (ret)
goto out;
ret = rds_ib_sysctl_init();
if (ret)
goto out_ibreg;
ret = rds_ib_recv_init();
if (ret)
goto out_sysctl;
ret = rds_trans_register(&rds_ib_transport);
if (ret)
goto out_recv;
rds_info_register_func(RDS_INFO_IB_CONNECTIONS, rds_ib_ic_info);
goto out;
out_recv:
rds_ib_recv_exit();
out_sysctl:
rds_ib_sysctl_exit();
out_ibreg:
rds_ib_unregister_client();
out:
return ret;
}
