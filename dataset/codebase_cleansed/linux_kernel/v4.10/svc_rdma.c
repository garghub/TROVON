static int read_reset_stat(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
atomic_t *stat = (atomic_t *)table->data;
if (!stat)
return -EINVAL;
if (write)
atomic_set(stat, 0);
else {
char str_buf[32];
char *data;
int len = snprintf(str_buf, 32, "%d\n", atomic_read(stat));
if (len >= 32)
return -EFAULT;
len = strlen(str_buf);
if (*ppos > len) {
*lenp = 0;
return 0;
}
data = &str_buf[*ppos];
len -= *ppos;
if (len > *lenp)
len = *lenp;
if (len && copy_to_user(buffer, str_buf, len))
return -EFAULT;
*lenp = len;
*ppos += len;
}
return 0;
}
void svc_rdma_cleanup(void)
{
dprintk("SVCRDMA Module Removed, deregister RPC RDMA transport\n");
destroy_workqueue(svc_rdma_wq);
if (svcrdma_table_header) {
unregister_sysctl_table(svcrdma_table_header);
svcrdma_table_header = NULL;
}
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
svc_unreg_xprt_class(&svc_rdma_bc_class);
#endif
svc_unreg_xprt_class(&svc_rdma_class);
}
int svc_rdma_init(void)
{
dprintk("SVCRDMA Module Init, register RPC RDMA transport\n");
dprintk("\tsvcrdma_ord : %d\n", svcrdma_ord);
dprintk("\tmax_requests : %u\n", svcrdma_max_requests);
dprintk("\tsq_depth : %u\n",
svcrdma_max_requests * RPCRDMA_SQ_DEPTH_MULT);
dprintk("\tmax_bc_requests : %u\n", svcrdma_max_bc_requests);
dprintk("\tmax_inline : %d\n", svcrdma_max_req_size);
svc_rdma_wq = alloc_workqueue("svc_rdma", 0, 0);
if (!svc_rdma_wq)
return -ENOMEM;
if (!svcrdma_table_header)
svcrdma_table_header =
register_sysctl_table(svcrdma_root_table);
svc_reg_xprt_class(&svc_rdma_class);
#if defined(CONFIG_SUNRPC_BACKCHANNEL)
svc_reg_xprt_class(&svc_rdma_bc_class);
#endif
return 0;
}
