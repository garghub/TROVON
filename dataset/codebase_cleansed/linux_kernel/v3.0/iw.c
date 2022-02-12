static void rds_iw_add_one(struct ib_device *device)
{
struct rds_iw_device *rds_iwdev;
struct ib_device_attr *dev_attr;
if (device->node_type != RDMA_NODE_RNIC)
return;
dev_attr = kmalloc(sizeof *dev_attr, GFP_KERNEL);
if (!dev_attr)
return;
if (ib_query_device(device, dev_attr)) {
rdsdebug("Query device failed for %s\n", device->name);
goto free_attr;
}
rds_iwdev = kmalloc(sizeof *rds_iwdev, GFP_KERNEL);
if (!rds_iwdev)
goto free_attr;
spin_lock_init(&rds_iwdev->spinlock);
rds_iwdev->dma_local_lkey = !!(dev_attr->device_cap_flags & IB_DEVICE_LOCAL_DMA_LKEY);
rds_iwdev->max_wrs = dev_attr->max_qp_wr;
rds_iwdev->max_sge = min(dev_attr->max_sge, RDS_IW_MAX_SGE);
rds_iwdev->dev = device;
rds_iwdev->pd = ib_alloc_pd(device);
if (IS_ERR(rds_iwdev->pd))
goto free_dev;
if (!rds_iwdev->dma_local_lkey) {
rds_iwdev->mr = ib_get_dma_mr(rds_iwdev->pd,
IB_ACCESS_REMOTE_READ |
IB_ACCESS_REMOTE_WRITE |
IB_ACCESS_LOCAL_WRITE);
if (IS_ERR(rds_iwdev->mr))
goto err_pd;
} else
rds_iwdev->mr = NULL;
rds_iwdev->mr_pool = rds_iw_create_mr_pool(rds_iwdev);
if (IS_ERR(rds_iwdev->mr_pool)) {
rds_iwdev->mr_pool = NULL;
goto err_mr;
}
INIT_LIST_HEAD(&rds_iwdev->cm_id_list);
INIT_LIST_HEAD(&rds_iwdev->conn_list);
list_add_tail(&rds_iwdev->list, &rds_iw_devices);
ib_set_client_data(device, &rds_iw_client, rds_iwdev);
goto free_attr;
err_mr:
if (rds_iwdev->mr)
ib_dereg_mr(rds_iwdev->mr);
err_pd:
ib_dealloc_pd(rds_iwdev->pd);
free_dev:
kfree(rds_iwdev);
free_attr:
kfree(dev_attr);
}
static void rds_iw_remove_one(struct ib_device *device)
{
struct rds_iw_device *rds_iwdev;
struct rds_iw_cm_id *i_cm_id, *next;
rds_iwdev = ib_get_client_data(device, &rds_iw_client);
if (!rds_iwdev)
return;
spin_lock_irq(&rds_iwdev->spinlock);
list_for_each_entry_safe(i_cm_id, next, &rds_iwdev->cm_id_list, list) {
list_del(&i_cm_id->list);
kfree(i_cm_id);
}
spin_unlock_irq(&rds_iwdev->spinlock);
rds_iw_destroy_conns(rds_iwdev);
if (rds_iwdev->mr_pool)
rds_iw_destroy_mr_pool(rds_iwdev->mr_pool);
if (rds_iwdev->mr)
ib_dereg_mr(rds_iwdev->mr);
while (ib_dealloc_pd(rds_iwdev->pd)) {
rdsdebug("Failed to dealloc pd %p\n", rds_iwdev->pd);
msleep(1);
}
list_del(&rds_iwdev->list);
kfree(rds_iwdev);
}
static int rds_iw_conn_info_visitor(struct rds_connection *conn,
void *buffer)
{
struct rds_info_rdma_connection *iinfo = buffer;
struct rds_iw_connection *ic;
if (conn->c_trans != &rds_iw_transport)
return 0;
iinfo->src_addr = conn->c_laddr;
iinfo->dst_addr = conn->c_faddr;
memset(&iinfo->src_gid, 0, sizeof(iinfo->src_gid));
memset(&iinfo->dst_gid, 0, sizeof(iinfo->dst_gid));
if (rds_conn_state(conn) == RDS_CONN_UP) {
struct rds_iw_device *rds_iwdev;
struct rdma_dev_addr *dev_addr;
ic = conn->c_transport_data;
dev_addr = &ic->i_cm_id->route.addr.dev_addr;
rdma_addr_get_sgid(dev_addr, (union ib_gid *) &iinfo->src_gid);
rdma_addr_get_dgid(dev_addr, (union ib_gid *) &iinfo->dst_gid);
rds_iwdev = ib_get_client_data(ic->i_cm_id->device, &rds_iw_client);
iinfo->max_send_wr = ic->i_send_ring.w_nr;
iinfo->max_recv_wr = ic->i_recv_ring.w_nr;
iinfo->max_send_sge = rds_iwdev->max_sge;
rds_iw_get_mr_info(rds_iwdev, iinfo);
}
return 1;
}
static void rds_iw_ic_info(struct socket *sock, unsigned int len,
struct rds_info_iterator *iter,
struct rds_info_lengths *lens)
{
rds_for_each_conn_info(sock, len, iter, lens,
rds_iw_conn_info_visitor,
sizeof(struct rds_info_rdma_connection));
}
static int rds_iw_laddr_check(__be32 addr)
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
if (ret || cm_id->device->node_type != RDMA_NODE_RNIC)
ret = -EADDRNOTAVAIL;
rdsdebug("addr %pI4 ret %d node type %d\n",
&addr, ret,
cm_id->device ? cm_id->device->node_type : -1);
rdma_destroy_id(cm_id);
return ret;
}
void rds_iw_exit(void)
{
rds_info_deregister_func(RDS_INFO_IWARP_CONNECTIONS, rds_iw_ic_info);
rds_iw_destroy_nodev_conns();
ib_unregister_client(&rds_iw_client);
rds_iw_sysctl_exit();
rds_iw_recv_exit();
rds_trans_unregister(&rds_iw_transport);
}
int rds_iw_init(void)
{
int ret;
INIT_LIST_HEAD(&rds_iw_devices);
ret = ib_register_client(&rds_iw_client);
if (ret)
goto out;
ret = rds_iw_sysctl_init();
if (ret)
goto out_ibreg;
ret = rds_iw_recv_init();
if (ret)
goto out_sysctl;
ret = rds_trans_register(&rds_iw_transport);
if (ret)
goto out_recv;
rds_info_register_func(RDS_INFO_IWARP_CONNECTIONS, rds_iw_ic_info);
goto out;
out_recv:
rds_iw_recv_exit();
out_sysctl:
rds_iw_sysctl_exit();
out_ibreg:
ib_unregister_client(&rds_iw_client);
out:
return ret;
}
