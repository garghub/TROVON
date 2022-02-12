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
if (rds_ibdev->mr_8k_pool)
rds_ib_destroy_mr_pool(rds_ibdev->mr_8k_pool);
if (rds_ibdev->mr_1m_pool)
rds_ib_destroy_mr_pool(rds_ibdev->mr_1m_pool);
if (rds_ibdev->pd)
ib_dealloc_pd(rds_ibdev->pd);
list_for_each_entry_safe(i_ipaddr, i_next, &rds_ibdev->ipaddr_list, list) {
list_del(&i_ipaddr->list);
kfree(i_ipaddr);
}
kfree(rds_ibdev->vector_load);
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
if (device->node_type != RDMA_NODE_IB_CA)
return;
rds_ibdev = kzalloc_node(sizeof(struct rds_ib_device), GFP_KERNEL,
ibdev_to_node(device));
if (!rds_ibdev)
return;
spin_lock_init(&rds_ibdev->spinlock);
atomic_set(&rds_ibdev->refcount, 1);
INIT_WORK(&rds_ibdev->free_work, rds_ib_dev_free);
rds_ibdev->max_wrs = device->attrs.max_qp_wr;
rds_ibdev->max_sge = min(device->attrs.max_sge, RDS_IB_MAX_SGE);
rds_ibdev->has_fr = (device->attrs.device_cap_flags &
IB_DEVICE_MEM_MGT_EXTENSIONS);
rds_ibdev->has_fmr = (device->alloc_fmr && device->dealloc_fmr &&
device->map_phys_fmr && device->unmap_fmr);
rds_ibdev->use_fastreg = (rds_ibdev->has_fr && !rds_ibdev->has_fmr);
rds_ibdev->fmr_max_remaps = device->attrs.max_map_per_fmr?: 32;
rds_ibdev->max_1m_mrs = device->attrs.max_mr ?
min_t(unsigned int, (device->attrs.max_mr / 2),
rds_ib_mr_1m_pool_size) : rds_ib_mr_1m_pool_size;
rds_ibdev->max_8k_mrs = device->attrs.max_mr ?
min_t(unsigned int, ((device->attrs.max_mr / 2) * RDS_MR_8K_SCALE),
rds_ib_mr_8k_pool_size) : rds_ib_mr_8k_pool_size;
rds_ibdev->max_initiator_depth = device->attrs.max_qp_init_rd_atom;
rds_ibdev->max_responder_resources = device->attrs.max_qp_rd_atom;
rds_ibdev->vector_load = kzalloc(sizeof(int) * device->num_comp_vectors,
GFP_KERNEL);
if (!rds_ibdev->vector_load) {
pr_err("RDS/IB: %s failed to allocate vector memory\n",
__func__);
goto put_dev;
}
rds_ibdev->dev = device;
rds_ibdev->pd = ib_alloc_pd(device, 0);
if (IS_ERR(rds_ibdev->pd)) {
rds_ibdev->pd = NULL;
goto put_dev;
}
rds_ibdev->mr_1m_pool =
rds_ib_create_mr_pool(rds_ibdev, RDS_IB_MR_1M_POOL);
if (IS_ERR(rds_ibdev->mr_1m_pool)) {
rds_ibdev->mr_1m_pool = NULL;
goto put_dev;
}
rds_ibdev->mr_8k_pool =
rds_ib_create_mr_pool(rds_ibdev, RDS_IB_MR_8K_POOL);
if (IS_ERR(rds_ibdev->mr_8k_pool)) {
rds_ibdev->mr_8k_pool = NULL;
goto put_dev;
}
rdsdebug("RDS/IB: max_mr = %d, max_wrs = %d, max_sge = %d, fmr_max_remaps = %d, max_1m_mrs = %d, max_8k_mrs = %d\n",
device->attrs.max_fmr, rds_ibdev->max_wrs, rds_ibdev->max_sge,
rds_ibdev->fmr_max_remaps, rds_ibdev->max_1m_mrs,
rds_ibdev->max_8k_mrs);
pr_info("RDS/IB: %s: %s supported and preferred\n",
device->name,
rds_ibdev->use_fastreg ? "FRMR" : "FMR");
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
static void rds_ib_remove_one(struct ib_device *device, void *client_data)
{
struct rds_ib_device *rds_ibdev = client_data;
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
static int rds_ib_laddr_check(struct net *net, __be32 addr)
{
int ret;
struct rdma_cm_id *cm_id;
struct sockaddr_in sin;
cm_id = rdma_create_id(&init_net, NULL, NULL, RDMA_PS_TCP, IB_QPT_RC);
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
rds_ib_mr_exit();
}
int rds_ib_init(void)
{
int ret;
INIT_LIST_HEAD(&rds_ib_devices);
ret = rds_ib_mr_init();
if (ret)
goto out;
ret = ib_register_client(&rds_ib_client);
if (ret)
goto out_mr_exit;
ret = rds_ib_sysctl_init();
if (ret)
goto out_ibreg;
ret = rds_ib_recv_init();
if (ret)
goto out_sysctl;
rds_trans_register(&rds_ib_transport);
rds_info_register_func(RDS_INFO_IB_CONNECTIONS, rds_ib_ic_info);
goto out;
out_sysctl:
rds_ib_sysctl_exit();
out_ibreg:
rds_ib_unregister_client();
out_mr_exit:
rds_ib_mr_exit();
out:
return ret;
}
