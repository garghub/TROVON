void *ehca_alloc_fw_ctrlblock(gfp_t flags)
{
void *ret = kmem_cache_zalloc(ctblk_cache, flags);
if (!ret)
ehca_gen_err("Out of memory for ctblk");
return ret;
}
void ehca_free_fw_ctrlblock(void *ptr)
{
if (ptr)
kmem_cache_free(ctblk_cache, ptr);
}
int ehca2ib_return_code(u64 ehca_rc)
{
switch (ehca_rc) {
case H_SUCCESS:
return 0;
case H_RESOURCE:
case H_BUSY:
return -EBUSY;
case H_NOT_ENOUGH_RESOURCES:
case H_CONSTRAINED:
case H_NO_MEM:
return -ENOMEM;
default:
return -EINVAL;
}
}
static int ehca_create_slab_caches(void)
{
int ret;
ret = ehca_init_pd_cache();
if (ret) {
ehca_gen_err("Cannot create PD SLAB cache.");
return ret;
}
ret = ehca_init_cq_cache();
if (ret) {
ehca_gen_err("Cannot create CQ SLAB cache.");
goto create_slab_caches2;
}
ret = ehca_init_qp_cache();
if (ret) {
ehca_gen_err("Cannot create QP SLAB cache.");
goto create_slab_caches3;
}
ret = ehca_init_av_cache();
if (ret) {
ehca_gen_err("Cannot create AV SLAB cache.");
goto create_slab_caches4;
}
ret = ehca_init_mrmw_cache();
if (ret) {
ehca_gen_err("Cannot create MR&MW SLAB cache.");
goto create_slab_caches5;
}
ret = ehca_init_small_qp_cache();
if (ret) {
ehca_gen_err("Cannot create small queue SLAB cache.");
goto create_slab_caches6;
}
#ifdef CONFIG_PPC_64K_PAGES
ctblk_cache = kmem_cache_create("ehca_cache_ctblk",
EHCA_PAGESIZE, H_CB_ALIGNMENT,
SLAB_HWCACHE_ALIGN,
NULL);
if (!ctblk_cache) {
ehca_gen_err("Cannot create ctblk SLAB cache.");
ehca_cleanup_small_qp_cache();
goto create_slab_caches6;
}
#endif
return 0;
create_slab_caches6:
ehca_cleanup_mrmw_cache();
create_slab_caches5:
ehca_cleanup_av_cache();
create_slab_caches4:
ehca_cleanup_qp_cache();
create_slab_caches3:
ehca_cleanup_cq_cache();
create_slab_caches2:
ehca_cleanup_pd_cache();
return ret;
}
static void ehca_destroy_slab_caches(void)
{
ehca_cleanup_small_qp_cache();
ehca_cleanup_mrmw_cache();
ehca_cleanup_av_cache();
ehca_cleanup_qp_cache();
ehca_cleanup_cq_cache();
ehca_cleanup_pd_cache();
#ifdef CONFIG_PPC_64K_PAGES
if (ctblk_cache)
kmem_cache_destroy(ctblk_cache);
#endif
}
static int ehca_sense_attributes(struct ehca_shca *shca)
{
int i, ret = 0;
u64 h_ret;
struct hipz_query_hca *rblock;
struct hipz_query_port *port;
const char *loc_code;
static const u32 pgsize_map[] = {
HCA_CAP_MR_PGSIZE_4K, 0x1000,
HCA_CAP_MR_PGSIZE_64K, 0x10000,
HCA_CAP_MR_PGSIZE_1M, 0x100000,
HCA_CAP_MR_PGSIZE_16M, 0x1000000,
};
ehca_gen_dbg("Probing adapter %s...",
shca->ofdev->dev.of_node->full_name);
loc_code = of_get_property(shca->ofdev->dev.of_node, "ibm,loc-code",
NULL);
if (loc_code)
ehca_gen_dbg(" ... location lode=%s", loc_code);
rblock = ehca_alloc_fw_ctrlblock(GFP_KERNEL);
if (!rblock) {
ehca_gen_err("Cannot allocate rblock memory.");
return -ENOMEM;
}
h_ret = hipz_h_query_hca(shca->ipz_hca_handle, rblock);
if (h_ret != H_SUCCESS) {
ehca_gen_err("Cannot query device properties. h_ret=%lli",
h_ret);
ret = -EPERM;
goto sense_attributes1;
}
if (ehca_nr_ports == 1)
shca->num_ports = 1;
else
shca->num_ports = (u8)rblock->num_ports;
ehca_gen_dbg(" ... found %x ports", rblock->num_ports);
if (ehca_hw_level == 0) {
u32 hcaaver;
u32 revid;
hcaaver = EHCA_BMASK_GET(EHCA_HCAAVER, rblock->hw_ver);
revid = EHCA_BMASK_GET(EHCA_REVID, rblock->hw_ver);
ehca_gen_dbg(" ... hardware version=%x:%x", hcaaver, revid);
if (hcaaver == 1) {
if (revid <= 3)
shca->hw_level = 0x10 | (revid + 1);
else
shca->hw_level = 0x14;
} else if (hcaaver == 2) {
if (revid == 0)
shca->hw_level = 0x21;
else if (revid == 0x10)
shca->hw_level = 0x22;
else if (revid == 0x20 || revid == 0x21)
shca->hw_level = 0x23;
}
if (!shca->hw_level) {
ehca_gen_warn("unknown hardware version"
" - assuming default level");
shca->hw_level = 0x22;
}
} else
shca->hw_level = ehca_hw_level;
ehca_gen_dbg(" ... hardware level=%x", shca->hw_level);
shca->hca_cap = rblock->hca_cap_indicators;
ehca_gen_dbg(" ... HCA capabilities:");
for (i = 0; i < ARRAY_SIZE(hca_cap_descr); i++)
if (EHCA_BMASK_GET(hca_cap_descr[i].mask, shca->hca_cap))
ehca_gen_dbg(" %s", hca_cap_descr[i].descr);
if (ehca_lock_hcalls == -1)
ehca_lock_hcalls = !EHCA_BMASK_GET(HCA_CAP_H_ALLOC_RES_SYNC,
shca->hca_cap);
shca->hca_cap_mr_pgsize = EHCA_PAGESIZE;
for (i = 0; i < ARRAY_SIZE(pgsize_map); i += 2)
if (rblock->memory_page_size_supported & pgsize_map[i])
shca->hca_cap_mr_pgsize |= pgsize_map[i + 1];
if (shca->max_num_qps == -1)
shca->max_num_qps = min_t(int, rblock->max_qp,
EHCA_MAX_NUM_QUEUES);
else if (shca->max_num_qps < 1 || shca->max_num_qps > rblock->max_qp) {
ehca_gen_warn("The requested number of QPs is out of range "
"(1 - %i) specified by HW. Value is set to %i",
rblock->max_qp, rblock->max_qp);
shca->max_num_qps = rblock->max_qp;
}
if (shca->max_num_cqs == -1)
shca->max_num_cqs = min_t(int, rblock->max_cq,
EHCA_MAX_NUM_QUEUES);
else if (shca->max_num_cqs < 1 || shca->max_num_cqs > rblock->max_cq) {
ehca_gen_warn("The requested number of CQs is out of range "
"(1 - %i) specified by HW. Value is set to %i",
rblock->max_cq, rblock->max_cq);
}
port = (struct hipz_query_port *)rblock;
h_ret = hipz_h_query_port(shca->ipz_hca_handle, 1, port);
if (h_ret != H_SUCCESS) {
ehca_gen_err("Cannot query port properties. h_ret=%lli",
h_ret);
ret = -EPERM;
goto sense_attributes1;
}
shca->max_mtu = port->max_mtu;
sense_attributes1:
ehca_free_fw_ctrlblock(rblock);
return ret;
}
static int init_node_guid(struct ehca_shca *shca)
{
int ret = 0;
struct hipz_query_hca *rblock;
rblock = ehca_alloc_fw_ctrlblock(GFP_KERNEL);
if (!rblock) {
ehca_err(&shca->ib_device, "Can't allocate rblock memory.");
return -ENOMEM;
}
if (hipz_h_query_hca(shca->ipz_hca_handle, rblock) != H_SUCCESS) {
ehca_err(&shca->ib_device, "Can't query device properties");
ret = -EINVAL;
goto init_node_guid1;
}
memcpy(&shca->ib_device.node_guid, &rblock->node_guid, sizeof(u64));
init_node_guid1:
ehca_free_fw_ctrlblock(rblock);
return ret;
}
static int ehca_init_device(struct ehca_shca *shca)
{
int ret;
ret = init_node_guid(shca);
if (ret)
return ret;
strlcpy(shca->ib_device.name, "ehca%d", IB_DEVICE_NAME_MAX);
shca->ib_device.owner = THIS_MODULE;
shca->ib_device.uverbs_abi_ver = 8;
shca->ib_device.uverbs_cmd_mask =
(1ull << IB_USER_VERBS_CMD_GET_CONTEXT) |
(1ull << IB_USER_VERBS_CMD_QUERY_DEVICE) |
(1ull << IB_USER_VERBS_CMD_QUERY_PORT) |
(1ull << IB_USER_VERBS_CMD_ALLOC_PD) |
(1ull << IB_USER_VERBS_CMD_DEALLOC_PD) |
(1ull << IB_USER_VERBS_CMD_REG_MR) |
(1ull << IB_USER_VERBS_CMD_DEREG_MR) |
(1ull << IB_USER_VERBS_CMD_CREATE_COMP_CHANNEL) |
(1ull << IB_USER_VERBS_CMD_CREATE_CQ) |
(1ull << IB_USER_VERBS_CMD_DESTROY_CQ) |
(1ull << IB_USER_VERBS_CMD_CREATE_QP) |
(1ull << IB_USER_VERBS_CMD_MODIFY_QP) |
(1ull << IB_USER_VERBS_CMD_QUERY_QP) |
(1ull << IB_USER_VERBS_CMD_DESTROY_QP) |
(1ull << IB_USER_VERBS_CMD_ATTACH_MCAST) |
(1ull << IB_USER_VERBS_CMD_DETACH_MCAST);
shca->ib_device.node_type = RDMA_NODE_IB_CA;
shca->ib_device.phys_port_cnt = shca->num_ports;
shca->ib_device.num_comp_vectors = 1;
shca->ib_device.dma_device = &shca->ofdev->dev;
shca->ib_device.query_device = ehca_query_device;
shca->ib_device.query_port = ehca_query_port;
shca->ib_device.query_gid = ehca_query_gid;
shca->ib_device.query_pkey = ehca_query_pkey;
shca->ib_device.modify_port = ehca_modify_port;
shca->ib_device.alloc_ucontext = ehca_alloc_ucontext;
shca->ib_device.dealloc_ucontext = ehca_dealloc_ucontext;
shca->ib_device.alloc_pd = ehca_alloc_pd;
shca->ib_device.dealloc_pd = ehca_dealloc_pd;
shca->ib_device.create_ah = ehca_create_ah;
shca->ib_device.query_ah = ehca_query_ah;
shca->ib_device.destroy_ah = ehca_destroy_ah;
shca->ib_device.create_qp = ehca_create_qp;
shca->ib_device.modify_qp = ehca_modify_qp;
shca->ib_device.query_qp = ehca_query_qp;
shca->ib_device.destroy_qp = ehca_destroy_qp;
shca->ib_device.post_send = ehca_post_send;
shca->ib_device.post_recv = ehca_post_recv;
shca->ib_device.create_cq = ehca_create_cq;
shca->ib_device.destroy_cq = ehca_destroy_cq;
shca->ib_device.resize_cq = ehca_resize_cq;
shca->ib_device.poll_cq = ehca_poll_cq;
shca->ib_device.req_notify_cq = ehca_req_notify_cq;
shca->ib_device.get_dma_mr = ehca_get_dma_mr;
shca->ib_device.reg_phys_mr = ehca_reg_phys_mr;
shca->ib_device.reg_user_mr = ehca_reg_user_mr;
shca->ib_device.query_mr = ehca_query_mr;
shca->ib_device.dereg_mr = ehca_dereg_mr;
shca->ib_device.rereg_phys_mr = ehca_rereg_phys_mr;
shca->ib_device.alloc_mw = ehca_alloc_mw;
shca->ib_device.bind_mw = ehca_bind_mw;
shca->ib_device.dealloc_mw = ehca_dealloc_mw;
shca->ib_device.alloc_fmr = ehca_alloc_fmr;
shca->ib_device.map_phys_fmr = ehca_map_phys_fmr;
shca->ib_device.unmap_fmr = ehca_unmap_fmr;
shca->ib_device.dealloc_fmr = ehca_dealloc_fmr;
shca->ib_device.attach_mcast = ehca_attach_mcast;
shca->ib_device.detach_mcast = ehca_detach_mcast;
shca->ib_device.process_mad = ehca_process_mad;
shca->ib_device.mmap = ehca_mmap;
shca->ib_device.dma_ops = &ehca_dma_mapping_ops;
if (EHCA_BMASK_GET(HCA_CAP_SRQ, shca->hca_cap)) {
shca->ib_device.uverbs_cmd_mask |=
(1ull << IB_USER_VERBS_CMD_CREATE_SRQ) |
(1ull << IB_USER_VERBS_CMD_MODIFY_SRQ) |
(1ull << IB_USER_VERBS_CMD_QUERY_SRQ) |
(1ull << IB_USER_VERBS_CMD_DESTROY_SRQ);
shca->ib_device.create_srq = ehca_create_srq;
shca->ib_device.modify_srq = ehca_modify_srq;
shca->ib_device.query_srq = ehca_query_srq;
shca->ib_device.destroy_srq = ehca_destroy_srq;
shca->ib_device.post_srq_recv = ehca_post_srq_recv;
}
return ret;
}
static int ehca_create_aqp1(struct ehca_shca *shca, u32 port)
{
struct ehca_sport *sport = &shca->sport[port - 1];
struct ib_cq *ibcq;
struct ib_qp *ibqp;
struct ib_qp_init_attr qp_init_attr;
int ret;
if (sport->ibcq_aqp1) {
ehca_err(&shca->ib_device, "AQP1 CQ is already created.");
return -EPERM;
}
ibcq = ib_create_cq(&shca->ib_device, NULL, NULL, (void *)(-1), 10, 0);
if (IS_ERR(ibcq)) {
ehca_err(&shca->ib_device, "Cannot create AQP1 CQ.");
return PTR_ERR(ibcq);
}
sport->ibcq_aqp1 = ibcq;
if (sport->ibqp_sqp[IB_QPT_GSI]) {
ehca_err(&shca->ib_device, "AQP1 QP is already created.");
ret = -EPERM;
goto create_aqp1;
}
memset(&qp_init_attr, 0, sizeof(struct ib_qp_init_attr));
qp_init_attr.send_cq = ibcq;
qp_init_attr.recv_cq = ibcq;
qp_init_attr.sq_sig_type = IB_SIGNAL_ALL_WR;
qp_init_attr.cap.max_send_wr = 100;
qp_init_attr.cap.max_recv_wr = 100;
qp_init_attr.cap.max_send_sge = 2;
qp_init_attr.cap.max_recv_sge = 1;
qp_init_attr.qp_type = IB_QPT_GSI;
qp_init_attr.port_num = port;
qp_init_attr.qp_context = NULL;
qp_init_attr.event_handler = NULL;
qp_init_attr.srq = NULL;
ibqp = ib_create_qp(&shca->pd->ib_pd, &qp_init_attr);
if (IS_ERR(ibqp)) {
ehca_err(&shca->ib_device, "Cannot create AQP1 QP.");
ret = PTR_ERR(ibqp);
goto create_aqp1;
}
sport->ibqp_sqp[IB_QPT_GSI] = ibqp;
return 0;
create_aqp1:
ib_destroy_cq(sport->ibcq_aqp1);
return ret;
}
static int ehca_destroy_aqp1(struct ehca_sport *sport)
{
int ret;
ret = ib_destroy_qp(sport->ibqp_sqp[IB_QPT_GSI]);
if (ret) {
ehca_gen_err("Cannot destroy AQP1 QP. ret=%i", ret);
return ret;
}
ret = ib_destroy_cq(sport->ibcq_aqp1);
if (ret)
ehca_gen_err("Cannot destroy AQP1 CQ. ret=%i", ret);
return ret;
}
static ssize_t ehca_show_debug_level(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ehca_debug_level);
}
static ssize_t ehca_store_debug_level(struct device_driver *ddp,
const char *buf, size_t count)
{
int value = (*buf) - '0';
if (value >= 0 && value <= 9)
ehca_debug_level = value;
return 1;
}
static ssize_t ehca_show_adapter_handle(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ehca_shca *shca = dev_get_drvdata(dev);
return sprintf(buf, "%llx\n", shca->ipz_hca_handle.handle);
}
static int ehca_probe(struct platform_device *dev,
const struct of_device_id *id)
{
struct ehca_shca *shca;
const u64 *handle;
struct ib_pd *ibpd;
int ret, i, eq_size;
unsigned long flags;
handle = of_get_property(dev->dev.of_node, "ibm,hca-handle", NULL);
if (!handle) {
ehca_gen_err("Cannot get eHCA handle for adapter: %s.",
dev->dev.of_node->full_name);
return -ENODEV;
}
if (!(*handle)) {
ehca_gen_err("Wrong eHCA handle for adapter: %s.",
dev->dev.of_node->full_name);
return -ENODEV;
}
shca = (struct ehca_shca *)ib_alloc_device(sizeof(*shca));
if (!shca) {
ehca_gen_err("Cannot allocate shca memory.");
return -ENOMEM;
}
mutex_init(&shca->modify_mutex);
atomic_set(&shca->num_cqs, 0);
atomic_set(&shca->num_qps, 0);
shca->max_num_qps = ehca_max_qp;
shca->max_num_cqs = ehca_max_cq;
for (i = 0; i < ARRAY_SIZE(shca->sport); i++)
spin_lock_init(&shca->sport[i].mod_sqp_lock);
shca->ofdev = dev;
shca->ipz_hca_handle.handle = *handle;
dev_set_drvdata(&dev->dev, shca);
ret = ehca_sense_attributes(shca);
if (ret < 0) {
ehca_gen_err("Cannot sense eHCA attributes.");
goto probe1;
}
ret = ehca_init_device(shca);
if (ret) {
ehca_gen_err("Cannot init ehca device struct");
goto probe1;
}
eq_size = 2 * shca->max_num_cqs + 4 * shca->max_num_qps;
ret = ehca_create_eq(shca, &shca->eq, EHCA_EQ, eq_size);
if (ret) {
ehca_err(&shca->ib_device, "Cannot create EQ.");
goto probe1;
}
ret = ehca_create_eq(shca, &shca->neq, EHCA_NEQ, 513);
if (ret) {
ehca_err(&shca->ib_device, "Cannot create NEQ.");
goto probe3;
}
ibpd = ehca_alloc_pd(&shca->ib_device, (void *)(-1), NULL);
if (IS_ERR(ibpd)) {
ehca_err(&shca->ib_device, "Cannot create internal PD.");
ret = PTR_ERR(ibpd);
goto probe4;
}
shca->pd = container_of(ibpd, struct ehca_pd, ib_pd);
shca->pd->ib_pd.device = &shca->ib_device;
ret = ehca_reg_internal_maxmr(shca, shca->pd, &shca->maxmr);
if (ret) {
ehca_err(&shca->ib_device, "Cannot create internal MR ret=%i",
ret);
goto probe5;
}
ret = ib_register_device(&shca->ib_device, NULL);
if (ret) {
ehca_err(&shca->ib_device,
"ib_register_device() failed ret=%i", ret);
goto probe6;
}
if (ehca_open_aqp1 == 1) {
shca->sport[0].port_state = IB_PORT_DOWN;
ret = ehca_create_aqp1(shca, 1);
if (ret) {
ehca_err(&shca->ib_device,
"Cannot create AQP1 for port 1.");
goto probe7;
}
}
if ((ehca_open_aqp1 == 1) && (shca->num_ports == 2)) {
shca->sport[1].port_state = IB_PORT_DOWN;
ret = ehca_create_aqp1(shca, 2);
if (ret) {
ehca_err(&shca->ib_device,
"Cannot create AQP1 for port 2.");
goto probe8;
}
}
ret = sysfs_create_group(&dev->dev.kobj, &ehca_dev_attr_grp);
if (ret)
ehca_err(&shca->ib_device,
"Cannot create device attributes ret=%d", ret);
spin_lock_irqsave(&shca_list_lock, flags);
list_add(&shca->shca_list, &shca_list);
spin_unlock_irqrestore(&shca_list_lock, flags);
return 0;
probe8:
ret = ehca_destroy_aqp1(&shca->sport[0]);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy AQP1 for port 1. ret=%i", ret);
probe7:
ib_unregister_device(&shca->ib_device);
probe6:
ret = ehca_dereg_internal_maxmr(shca);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy internal MR. ret=%x", ret);
probe5:
ret = ehca_dealloc_pd(&shca->pd->ib_pd);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy internal PD. ret=%x", ret);
probe4:
ret = ehca_destroy_eq(shca, &shca->neq);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy NEQ. ret=%x", ret);
probe3:
ret = ehca_destroy_eq(shca, &shca->eq);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy EQ. ret=%x", ret);
probe1:
ib_dealloc_device(&shca->ib_device);
return -EINVAL;
}
static int ehca_remove(struct platform_device *dev)
{
struct ehca_shca *shca = dev_get_drvdata(&dev->dev);
unsigned long flags;
int ret;
sysfs_remove_group(&dev->dev.kobj, &ehca_dev_attr_grp);
if (ehca_open_aqp1 == 1) {
int i;
for (i = 0; i < shca->num_ports; i++) {
ret = ehca_destroy_aqp1(&shca->sport[i]);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy AQP1 for port %x "
"ret=%i", ret, i);
}
}
ib_unregister_device(&shca->ib_device);
ret = ehca_dereg_internal_maxmr(shca);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy internal MR. ret=%i", ret);
ret = ehca_dealloc_pd(&shca->pd->ib_pd);
if (ret)
ehca_err(&shca->ib_device,
"Cannot destroy internal PD. ret=%i", ret);
ret = ehca_destroy_eq(shca, &shca->eq);
if (ret)
ehca_err(&shca->ib_device, "Cannot destroy EQ. ret=%i", ret);
ret = ehca_destroy_eq(shca, &shca->neq);
if (ret)
ehca_err(&shca->ib_device, "Canot destroy NEQ. ret=%i", ret);
ib_dealloc_device(&shca->ib_device);
spin_lock_irqsave(&shca_list_lock, flags);
list_del(&shca->shca_list);
spin_unlock_irqrestore(&shca_list_lock, flags);
return ret;
}
void ehca_poll_eqs(unsigned long data)
{
struct ehca_shca *shca;
spin_lock(&shca_list_lock);
list_for_each_entry(shca, &shca_list, shca_list) {
if (shca->eq.is_initialized) {
struct ehca_eq *eq = &shca->eq;
int max = 3;
volatile u64 q_ofs, q_ofs2;
unsigned long flags;
spin_lock_irqsave(&eq->spinlock, flags);
q_ofs = eq->ipz_queue.current_q_offset;
spin_unlock_irqrestore(&eq->spinlock, flags);
do {
spin_lock_irqsave(&eq->spinlock, flags);
q_ofs2 = eq->ipz_queue.current_q_offset;
spin_unlock_irqrestore(&eq->spinlock, flags);
max--;
} while (q_ofs == q_ofs2 && max > 0);
if (q_ofs == q_ofs2)
ehca_process_eq(shca, 0);
}
}
mod_timer(&poll_eqs_timer, round_jiffies(jiffies + HZ));
spin_unlock(&shca_list_lock);
}
static int ehca_mem_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
static unsigned long ehca_dmem_warn_time;
unsigned long flags;
switch (action) {
case MEM_CANCEL_OFFLINE:
case MEM_CANCEL_ONLINE:
case MEM_ONLINE:
case MEM_OFFLINE:
return NOTIFY_OK;
case MEM_GOING_ONLINE:
case MEM_GOING_OFFLINE:
spin_lock_irqsave(&shca_list_lock, flags);
if (list_empty(&shca_list)) {
spin_unlock_irqrestore(&shca_list_lock, flags);
return NOTIFY_OK;
} else {
spin_unlock_irqrestore(&shca_list_lock, flags);
if (printk_timed_ratelimit(&ehca_dmem_warn_time,
30 * 1000))
ehca_gen_err("DMEM operations are not allowed"
"in conjunction with eHCA");
return NOTIFY_BAD;
}
}
return NOTIFY_OK;
}
static int __init ehca_module_init(void)
{
int ret;
printk(KERN_INFO "eHCA Infiniband Device Driver "
"(Version " HCAD_VERSION ")\n");
ret = ehca_create_comp_pool();
if (ret) {
ehca_gen_err("Cannot create comp pool.");
return ret;
}
ret = ehca_create_slab_caches();
if (ret) {
ehca_gen_err("Cannot create SLAB caches");
ret = -ENOMEM;
goto module_init1;
}
ret = ehca_create_busmap();
if (ret) {
ehca_gen_err("Cannot create busmap.");
goto module_init2;
}
ret = ibmebus_register_driver(&ehca_driver);
if (ret) {
ehca_gen_err("Cannot register eHCA device driver");
ret = -EINVAL;
goto module_init3;
}
ret = register_memory_notifier(&ehca_mem_nb);
if (ret) {
ehca_gen_err("Failed registering memory add/remove notifier");
goto module_init4;
}
if (ehca_poll_all_eqs != 1) {
ehca_gen_err("WARNING!!!");
ehca_gen_err("It is possible to lose interrupts.");
} else {
init_timer(&poll_eqs_timer);
poll_eqs_timer.function = ehca_poll_eqs;
poll_eqs_timer.expires = jiffies + HZ;
add_timer(&poll_eqs_timer);
}
return 0;
module_init4:
ibmebus_unregister_driver(&ehca_driver);
module_init3:
ehca_destroy_busmap();
module_init2:
ehca_destroy_slab_caches();
module_init1:
ehca_destroy_comp_pool();
return ret;
}
static void __exit ehca_module_exit(void)
{
if (ehca_poll_all_eqs == 1)
del_timer_sync(&poll_eqs_timer);
ibmebus_unregister_driver(&ehca_driver);
unregister_memory_notifier(&ehca_mem_nb);
ehca_destroy_busmap();
ehca_destroy_slab_caches();
ehca_destroy_comp_pool();
idr_destroy(&ehca_cq_idr);
idr_destroy(&ehca_qp_idr);
}
