static u32 get_longbusy_msecs(int longbusy_rc)
{
switch (longbusy_rc) {
case H_LONG_BUSY_ORDER_1_MSEC:
return 1;
case H_LONG_BUSY_ORDER_10_MSEC:
return 10;
case H_LONG_BUSY_ORDER_100_MSEC:
return 100;
case H_LONG_BUSY_ORDER_1_SEC:
return 1000;
case H_LONG_BUSY_ORDER_10_SEC:
return 10000;
case H_LONG_BUSY_ORDER_100_SEC:
return 100000;
default:
return 1;
}
}
static long ehca_plpar_hcall_norets(unsigned long opcode,
unsigned long arg1,
unsigned long arg2,
unsigned long arg3,
unsigned long arg4,
unsigned long arg5,
unsigned long arg6,
unsigned long arg7)
{
long ret;
int i, sleep_msecs;
unsigned long flags = 0;
if (unlikely(ehca_debug_level >= 2))
ehca_gen_dbg("opcode=%lx " HCALL7_REGS_FORMAT,
opcode, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
for (i = 0; i < 5; i++) {
if (ehca_lock_hcalls)
spin_lock_irqsave(&hcall_lock, flags);
ret = plpar_hcall_norets(opcode, arg1, arg2, arg3, arg4,
arg5, arg6, arg7);
if (ehca_lock_hcalls)
spin_unlock_irqrestore(&hcall_lock, flags);
if (H_IS_LONG_BUSY(ret)) {
sleep_msecs = get_longbusy_msecs(ret);
msleep_interruptible(sleep_msecs);
continue;
}
if (ret < H_SUCCESS)
ehca_gen_err("opcode=%lx ret=%li " HCALL7_REGS_FORMAT,
opcode, ret, arg1, arg2, arg3,
arg4, arg5, arg6, arg7);
else
if (unlikely(ehca_debug_level >= 2))
ehca_gen_dbg("opcode=%lx ret=%li", opcode, ret);
return ret;
}
return H_BUSY;
}
static long ehca_plpar_hcall9(unsigned long opcode,
unsigned long *outs,
unsigned long arg1,
unsigned long arg2,
unsigned long arg3,
unsigned long arg4,
unsigned long arg5,
unsigned long arg6,
unsigned long arg7,
unsigned long arg8,
unsigned long arg9)
{
long ret;
int i, sleep_msecs;
unsigned long flags = 0;
if (unlikely(ehca_debug_level >= 2))
ehca_gen_dbg("INPUT -- opcode=%lx " HCALL9_REGS_FORMAT, opcode,
arg1, arg2, arg3, arg4, arg5,
arg6, arg7, arg8, arg9);
for (i = 0; i < 5; i++) {
if (ehca_lock_hcalls)
spin_lock_irqsave(&hcall_lock, flags);
ret = plpar_hcall9(opcode, outs,
arg1, arg2, arg3, arg4, arg5,
arg6, arg7, arg8, arg9);
if (ehca_lock_hcalls)
spin_unlock_irqrestore(&hcall_lock, flags);
if (H_IS_LONG_BUSY(ret)) {
sleep_msecs = get_longbusy_msecs(ret);
msleep_interruptible(sleep_msecs);
continue;
}
if (ret < H_SUCCESS) {
ehca_gen_err("INPUT -- opcode=%lx " HCALL9_REGS_FORMAT,
opcode, arg1, arg2, arg3, arg4, arg5,
arg6, arg7, arg8, arg9);
ehca_gen_err("OUTPUT -- ret=%li " HCALL9_REGS_FORMAT,
ret, outs[0], outs[1], outs[2], outs[3],
outs[4], outs[5], outs[6], outs[7],
outs[8]);
} else if (unlikely(ehca_debug_level >= 2))
ehca_gen_dbg("OUTPUT -- ret=%li " HCALL9_REGS_FORMAT,
ret, outs[0], outs[1], outs[2], outs[3],
outs[4], outs[5], outs[6], outs[7],
outs[8]);
return ret;
}
return H_BUSY;
}
u64 hipz_h_alloc_resource_eq(const struct ipz_adapter_handle adapter_handle,
struct ehca_pfeq *pfeq,
const u32 neq_control,
const u32 number_of_entries,
struct ipz_eq_handle *eq_handle,
u32 *act_nr_of_entries,
u32 *act_pages,
u32 *eq_ist)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
u64 allocate_controls;
allocate_controls = 3ULL;
if (neq_control != 1)
allocate_controls = (1ULL << (63 - 7)) | allocate_controls;
else
allocate_controls = (1ULL << 63) | allocate_controls;
ret = ehca_plpar_hcall9(H_ALLOC_RESOURCE, outs,
adapter_handle.handle,
allocate_controls,
number_of_entries,
0, 0, 0, 0, 0, 0);
eq_handle->handle = outs[0];
*act_nr_of_entries = (u32)outs[3];
*act_pages = (u32)outs[4];
*eq_ist = (u32)outs[5];
if (ret == H_NOT_ENOUGH_RESOURCES)
ehca_gen_err("Not enough resource - ret=%lli ", ret);
return ret;
}
u64 hipz_h_reset_event(const struct ipz_adapter_handle adapter_handle,
struct ipz_eq_handle eq_handle,
const u64 event_mask)
{
return ehca_plpar_hcall_norets(H_RESET_EVENTS,
adapter_handle.handle,
eq_handle.handle,
event_mask,
0, 0, 0, 0);
}
u64 hipz_h_alloc_resource_cq(const struct ipz_adapter_handle adapter_handle,
struct ehca_cq *cq,
struct ehca_alloc_cq_parms *param)
{
int rc;
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_ALLOC_RESOURCE, outs,
adapter_handle.handle,
2,
param->eq_handle.handle,
cq->token,
param->nr_cqe,
0, 0, 0, 0);
cq->ipz_cq_handle.handle = outs[0];
param->act_nr_of_entries = (u32)outs[3];
param->act_pages = (u32)outs[4];
if (ret == H_SUCCESS) {
rc = hcp_galpas_ctor(&cq->galpas, 0, outs[5], outs[6]);
if (rc) {
ehca_gen_err("Could not establish HW access. rc=%d paddr=%#lx",
rc, outs[5]);
ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
cq->ipz_cq_handle.handle,
0, 0, 0, 0, 0);
ret = H_NO_MEM;
}
}
if (ret == H_NOT_ENOUGH_RESOURCES)
ehca_gen_err("Not enough resources. ret=%lli", ret);
return ret;
}
u64 hipz_h_alloc_resource_qp(const struct ipz_adapter_handle adapter_handle,
struct ehca_alloc_qp_parms *parms, int is_user)
{
int rc;
u64 ret;
u64 allocate_controls, max_r10_reg, r11, r12;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
allocate_controls =
EHCA_BMASK_SET(H_ALL_RES_QP_ENHANCED_OPS, parms->ext_type)
| EHCA_BMASK_SET(H_ALL_RES_QP_PTE_PIN, 0)
| EHCA_BMASK_SET(H_ALL_RES_QP_SERVICE_TYPE, parms->servicetype)
| EHCA_BMASK_SET(H_ALL_RES_QP_SIGNALING_TYPE, parms->sigtype)
| EHCA_BMASK_SET(H_ALL_RES_QP_STORAGE, parms->qp_storage)
| EHCA_BMASK_SET(H_ALL_RES_QP_SMALL_SQ_PAGE_SIZE,
parms->squeue.page_size)
| EHCA_BMASK_SET(H_ALL_RES_QP_SMALL_RQ_PAGE_SIZE,
parms->rqueue.page_size)
| EHCA_BMASK_SET(H_ALL_RES_QP_LL_RQ_CQE_POSTING,
!!(parms->ll_comp_flags & LLQP_RECV_COMP))
| EHCA_BMASK_SET(H_ALL_RES_QP_LL_SQ_CQE_POSTING,
!!(parms->ll_comp_flags & LLQP_SEND_COMP))
| EHCA_BMASK_SET(H_ALL_RES_QP_UD_AV_LKEY_CTRL,
parms->ud_av_l_key_ctl)
| EHCA_BMASK_SET(H_ALL_RES_QP_RESOURCE_TYPE, 1);
max_r10_reg =
EHCA_BMASK_SET(H_ALL_RES_QP_MAX_OUTST_SEND_WR,
parms->squeue.max_wr + 1)
| EHCA_BMASK_SET(H_ALL_RES_QP_MAX_OUTST_RECV_WR,
parms->rqueue.max_wr + 1)
| EHCA_BMASK_SET(H_ALL_RES_QP_MAX_SEND_SGE,
parms->squeue.max_sge)
| EHCA_BMASK_SET(H_ALL_RES_QP_MAX_RECV_SGE,
parms->rqueue.max_sge);
r11 = EHCA_BMASK_SET(H_ALL_RES_QP_SRQ_QP_TOKEN, parms->srq_token);
if (parms->ext_type == EQPT_SRQ)
r12 = EHCA_BMASK_SET(H_ALL_RES_QP_SRQ_LIMIT, parms->srq_limit);
else
r12 = EHCA_BMASK_SET(H_ALL_RES_QP_SRQ_QPN, parms->srq_qpn);
ret = ehca_plpar_hcall9(H_ALLOC_RESOURCE, outs,
adapter_handle.handle,
allocate_controls,
parms->send_cq_handle.handle,
parms->recv_cq_handle.handle,
parms->eq_handle.handle,
((u64)parms->token << 32) | parms->pd.value,
max_r10_reg, r11, r12);
parms->qp_handle.handle = outs[0];
parms->real_qp_num = (u32)outs[1];
parms->squeue.act_nr_wqes =
(u16)EHCA_BMASK_GET(H_ALL_RES_QP_ACT_OUTST_SEND_WR, outs[2]);
parms->rqueue.act_nr_wqes =
(u16)EHCA_BMASK_GET(H_ALL_RES_QP_ACT_OUTST_RECV_WR, outs[2]);
parms->squeue.act_nr_sges =
(u8)EHCA_BMASK_GET(H_ALL_RES_QP_ACT_SEND_SGE, outs[3]);
parms->rqueue.act_nr_sges =
(u8)EHCA_BMASK_GET(H_ALL_RES_QP_ACT_RECV_SGE, outs[3]);
parms->squeue.queue_size =
(u32)EHCA_BMASK_GET(H_ALL_RES_QP_SQUEUE_SIZE_PAGES, outs[4]);
parms->rqueue.queue_size =
(u32)EHCA_BMASK_GET(H_ALL_RES_QP_RQUEUE_SIZE_PAGES, outs[4]);
if (ret == H_SUCCESS) {
rc = hcp_galpas_ctor(&parms->galpas, is_user, outs[6], outs[6]);
if (rc) {
ehca_gen_err("Could not establish HW access. rc=%d paddr=%#lx",
rc, outs[6]);
ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
parms->qp_handle.handle,
0, 0, 0, 0, 0);
ret = H_NO_MEM;
}
}
if (ret == H_NOT_ENOUGH_RESOURCES)
ehca_gen_err("Not enough resources. ret=%lli", ret);
return ret;
}
u64 hipz_h_query_port(const struct ipz_adapter_handle adapter_handle,
const u8 port_id,
struct hipz_query_port *query_port_response_block)
{
u64 ret;
u64 r_cb = __pa(query_port_response_block);
if (r_cb & (EHCA_PAGESIZE-1)) {
ehca_gen_err("response block not page aligned");
return H_PARAMETER;
}
ret = ehca_plpar_hcall_norets(H_QUERY_PORT,
adapter_handle.handle,
port_id,
r_cb,
0, 0, 0, 0);
if (ehca_debug_level >= 2)
ehca_dmp(query_port_response_block, 64, "response_block");
return ret;
}
u64 hipz_h_modify_port(const struct ipz_adapter_handle adapter_handle,
const u8 port_id, const u32 port_cap,
const u8 init_type, const int modify_mask)
{
u64 port_attributes = port_cap;
if (modify_mask & IB_PORT_SHUTDOWN)
port_attributes |= EHCA_BMASK_SET(H_MP_SHUTDOWN, 1);
if (modify_mask & IB_PORT_INIT_TYPE)
port_attributes |= EHCA_BMASK_SET(H_MP_INIT_TYPE, init_type);
if (modify_mask & IB_PORT_RESET_QKEY_CNTR)
port_attributes |= EHCA_BMASK_SET(H_MP_RESET_QKEY_CTR, 1);
return ehca_plpar_hcall_norets(H_MODIFY_PORT,
adapter_handle.handle,
port_id,
port_attributes,
0, 0, 0, 0);
}
u64 hipz_h_query_hca(const struct ipz_adapter_handle adapter_handle,
struct hipz_query_hca *query_hca_rblock)
{
u64 r_cb = __pa(query_hca_rblock);
if (r_cb & (EHCA_PAGESIZE-1)) {
ehca_gen_err("response_block=%p not page aligned",
query_hca_rblock);
return H_PARAMETER;
}
return ehca_plpar_hcall_norets(H_QUERY_HCA,
adapter_handle.handle,
r_cb,
0, 0, 0, 0, 0);
}
u64 hipz_h_register_rpage(const struct ipz_adapter_handle adapter_handle,
const u8 pagesize,
const u8 queue_type,
const u64 resource_handle,
const u64 logical_address_of_page,
u64 count)
{
return ehca_plpar_hcall_norets(H_REGISTER_RPAGES,
adapter_handle.handle,
(u64)queue_type | ((u64)pagesize) << 8,
resource_handle,
logical_address_of_page,
count,
0, 0);
}
u64 hipz_h_register_rpage_eq(const struct ipz_adapter_handle adapter_handle,
const struct ipz_eq_handle eq_handle,
struct ehca_pfeq *pfeq,
const u8 pagesize,
const u8 queue_type,
const u64 logical_address_of_page,
const u64 count)
{
if (count != 1) {
ehca_gen_err("Ppage counter=%llx", count);
return H_PARAMETER;
}
return hipz_h_register_rpage(adapter_handle,
pagesize,
queue_type,
eq_handle.handle,
logical_address_of_page, count);
}
u64 hipz_h_query_int_state(const struct ipz_adapter_handle adapter_handle,
u32 ist)
{
u64 ret;
ret = ehca_plpar_hcall_norets(H_QUERY_INT_STATE,
adapter_handle.handle,
ist,
0, 0, 0, 0, 0);
if (ret != H_SUCCESS && ret != H_BUSY)
ehca_gen_err("Could not query interrupt state.");
return ret;
}
u64 hipz_h_register_rpage_cq(const struct ipz_adapter_handle adapter_handle,
const struct ipz_cq_handle cq_handle,
struct ehca_pfcq *pfcq,
const u8 pagesize,
const u8 queue_type,
const u64 logical_address_of_page,
const u64 count,
const struct h_galpa gal)
{
if (count != 1) {
ehca_gen_err("Page counter=%llx", count);
return H_PARAMETER;
}
return hipz_h_register_rpage(adapter_handle, pagesize, queue_type,
cq_handle.handle, logical_address_of_page,
count);
}
u64 hipz_h_register_rpage_qp(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct ehca_pfqp *pfqp,
const u8 pagesize,
const u8 queue_type,
const u64 logical_address_of_page,
const u64 count,
const struct h_galpa galpa)
{
if (count > 1) {
ehca_gen_err("Page counter=%llx", count);
return H_PARAMETER;
}
return hipz_h_register_rpage(adapter_handle, pagesize, queue_type,
qp_handle.handle, logical_address_of_page,
count);
}
u64 hipz_h_disable_and_get_wqe(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct ehca_pfqp *pfqp,
void **log_addr_next_sq_wqe2processed,
void **log_addr_next_rq_wqe2processed,
int dis_and_get_function_code)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_DISABLE_AND_GETC, outs,
adapter_handle.handle,
dis_and_get_function_code,
qp_handle.handle,
0, 0, 0, 0, 0, 0);
if (log_addr_next_sq_wqe2processed)
*log_addr_next_sq_wqe2processed = (void *)outs[0];
if (log_addr_next_rq_wqe2processed)
*log_addr_next_rq_wqe2processed = (void *)outs[1];
return ret;
}
u64 hipz_h_modify_qp(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct ehca_pfqp *pfqp,
const u64 update_mask,
struct hcp_modify_qp_control_block *mqpcb,
struct h_galpa gal)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_MODIFY_QP, outs,
adapter_handle.handle,
qp_handle.handle,
update_mask,
__pa(mqpcb),
0, 0, 0, 0, 0);
if (ret == H_NOT_ENOUGH_RESOURCES)
ehca_gen_err("Insufficient resources ret=%lli", ret);
return ret;
}
u64 hipz_h_query_qp(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct ehca_pfqp *pfqp,
struct hcp_modify_qp_control_block *qqpcb,
struct h_galpa gal)
{
return ehca_plpar_hcall_norets(H_QUERY_QP,
adapter_handle.handle,
qp_handle.handle,
__pa(qqpcb),
0, 0, 0, 0);
}
u64 hipz_h_destroy_qp(const struct ipz_adapter_handle adapter_handle,
struct ehca_qp *qp)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = hcp_galpas_dtor(&qp->galpas);
if (ret) {
ehca_gen_err("Could not destruct qp->galpas");
return H_RESOURCE;
}
ret = ehca_plpar_hcall9(H_DISABLE_AND_GETC, outs,
adapter_handle.handle,
1,
qp->ipz_qp_handle.handle,
0, 0, 0, 0, 0, 0);
if (ret == H_HARDWARE)
ehca_gen_err("HCA not operational. ret=%lli", ret);
ret = ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
qp->ipz_qp_handle.handle,
0, 0, 0, 0, 0);
if (ret == H_RESOURCE)
ehca_gen_err("Resource still in use. ret=%lli", ret);
return ret;
}
u64 hipz_h_define_aqp0(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct h_galpa gal,
u32 port)
{
return ehca_plpar_hcall_norets(H_DEFINE_AQP0,
adapter_handle.handle,
qp_handle.handle,
port,
0, 0, 0, 0);
}
u64 hipz_h_define_aqp1(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct h_galpa gal,
u32 port, u32 * pma_qp_nr,
u32 * bma_qp_nr)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_DEFINE_AQP1, outs,
adapter_handle.handle,
qp_handle.handle,
port,
0, 0, 0, 0, 0, 0);
*pma_qp_nr = (u32)outs[0];
*bma_qp_nr = (u32)outs[1];
if (ret == H_ALIAS_EXIST)
ehca_gen_err("AQP1 already exists. ret=%lli", ret);
return ret;
}
u64 hipz_h_attach_mcqp(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct h_galpa gal,
u16 mcg_dlid,
u64 subnet_prefix, u64 interface_id)
{
u64 ret;
ret = ehca_plpar_hcall_norets(H_ATTACH_MCQP,
adapter_handle.handle,
qp_handle.handle,
mcg_dlid,
interface_id,
subnet_prefix,
0, 0);
if (ret == H_NOT_ENOUGH_RESOURCES)
ehca_gen_err("Not enough resources. ret=%lli", ret);
return ret;
}
u64 hipz_h_detach_mcqp(const struct ipz_adapter_handle adapter_handle,
const struct ipz_qp_handle qp_handle,
struct h_galpa gal,
u16 mcg_dlid,
u64 subnet_prefix, u64 interface_id)
{
return ehca_plpar_hcall_norets(H_DETACH_MCQP,
adapter_handle.handle,
qp_handle.handle,
mcg_dlid,
interface_id,
subnet_prefix,
0, 0);
}
u64 hipz_h_destroy_cq(const struct ipz_adapter_handle adapter_handle,
struct ehca_cq *cq,
u8 force_flag)
{
u64 ret;
ret = hcp_galpas_dtor(&cq->galpas);
if (ret) {
ehca_gen_err("Could not destruct cp->galpas");
return H_RESOURCE;
}
ret = ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
cq->ipz_cq_handle.handle,
force_flag != 0 ? 1L : 0L,
0, 0, 0, 0);
if (ret == H_RESOURCE)
ehca_gen_err("H_FREE_RESOURCE failed ret=%lli ", ret);
return ret;
}
u64 hipz_h_destroy_eq(const struct ipz_adapter_handle adapter_handle,
struct ehca_eq *eq)
{
u64 ret;
ret = hcp_galpas_dtor(&eq->galpas);
if (ret) {
ehca_gen_err("Could not destruct eq->galpas");
return H_RESOURCE;
}
ret = ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
eq->ipz_eq_handle.handle,
0, 0, 0, 0, 0);
if (ret == H_RESOURCE)
ehca_gen_err("Resource in use. ret=%lli ", ret);
return ret;
}
u64 hipz_h_alloc_resource_mr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr,
const u64 vaddr,
const u64 length,
const u32 access_ctrl,
const struct ipz_pd pd,
struct ehca_mr_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_ALLOC_RESOURCE, outs,
adapter_handle.handle,
5,
vaddr,
length,
(((u64)access_ctrl) << 32ULL),
pd.value,
0, 0, 0);
outparms->handle.handle = outs[0];
outparms->lkey = (u32)outs[2];
outparms->rkey = (u32)outs[3];
return ret;
}
u64 hipz_h_register_rpage_mr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr,
const u8 pagesize,
const u8 queue_type,
const u64 logical_address_of_page,
const u64 count)
{
u64 ret;
if (unlikely(ehca_debug_level >= 3)) {
if (count > 1) {
u64 *kpage;
int i;
kpage = __va(logical_address_of_page);
for (i = 0; i < count; i++)
ehca_gen_dbg("kpage[%d]=%p",
i, (void *)kpage[i]);
} else
ehca_gen_dbg("kpage=%p",
(void *)logical_address_of_page);
}
if ((count > 1) && (logical_address_of_page & (EHCA_PAGESIZE-1))) {
ehca_gen_err("logical_address_of_page not on a 4k boundary "
"adapter_handle=%llx mr=%p mr_handle=%llx "
"pagesize=%x queue_type=%x "
"logical_address_of_page=%llx count=%llx",
adapter_handle.handle, mr,
mr->ipz_mr_handle.handle, pagesize, queue_type,
logical_address_of_page, count);
ret = H_PARAMETER;
} else
ret = hipz_h_register_rpage(adapter_handle, pagesize,
queue_type,
mr->ipz_mr_handle.handle,
logical_address_of_page, count);
return ret;
}
u64 hipz_h_query_mr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr,
struct ehca_mr_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_QUERY_MR, outs,
adapter_handle.handle,
mr->ipz_mr_handle.handle,
0, 0, 0, 0, 0, 0, 0);
outparms->len = outs[0];
outparms->vaddr = outs[1];
outparms->acl = outs[4] >> 32;
outparms->lkey = (u32)(outs[5] >> 32);
outparms->rkey = (u32)(outs[5] & (0xffffffff));
return ret;
}
u64 hipz_h_free_resource_mr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr)
{
return ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
mr->ipz_mr_handle.handle,
0, 0, 0, 0, 0);
}
u64 hipz_h_reregister_pmr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr,
const u64 vaddr_in,
const u64 length,
const u32 access_ctrl,
const struct ipz_pd pd,
const u64 mr_addr_cb,
struct ehca_mr_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_REREGISTER_PMR, outs,
adapter_handle.handle,
mr->ipz_mr_handle.handle,
vaddr_in,
length,
((((u64)access_ctrl) << 32ULL) | pd.value),
mr_addr_cb,
0, 0, 0);
outparms->vaddr = outs[1];
outparms->lkey = (u32)outs[2];
outparms->rkey = (u32)outs[3];
return ret;
}
u64 hipz_h_register_smr(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mr *mr,
const struct ehca_mr *orig_mr,
const u64 vaddr_in,
const u32 access_ctrl,
const struct ipz_pd pd,
struct ehca_mr_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_REGISTER_SMR, outs,
adapter_handle.handle,
orig_mr->ipz_mr_handle.handle,
vaddr_in,
(((u64)access_ctrl) << 32ULL),
pd.value,
0, 0, 0, 0);
outparms->handle.handle = outs[0];
outparms->lkey = (u32)outs[2];
outparms->rkey = (u32)outs[3];
return ret;
}
u64 hipz_h_alloc_resource_mw(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mw *mw,
const struct ipz_pd pd,
struct ehca_mw_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_ALLOC_RESOURCE, outs,
adapter_handle.handle,
6,
pd.value,
0, 0, 0, 0, 0, 0);
outparms->handle.handle = outs[0];
outparms->rkey = (u32)outs[3];
return ret;
}
u64 hipz_h_query_mw(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mw *mw,
struct ehca_mw_hipzout_parms *outparms)
{
u64 ret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
ret = ehca_plpar_hcall9(H_QUERY_MW, outs,
adapter_handle.handle,
mw->ipz_mw_handle.handle,
0, 0, 0, 0, 0, 0, 0);
outparms->rkey = (u32)outs[3];
return ret;
}
u64 hipz_h_free_resource_mw(const struct ipz_adapter_handle adapter_handle,
const struct ehca_mw *mw)
{
return ehca_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle.handle,
mw->ipz_mw_handle.handle,
0, 0, 0, 0, 0);
}
u64 hipz_h_error_data(const struct ipz_adapter_handle adapter_handle,
const u64 ressource_handle,
void *rblock,
unsigned long *byte_count)
{
u64 r_cb = __pa(rblock);
if (r_cb & (EHCA_PAGESIZE-1)) {
ehca_gen_err("rblock not page aligned.");
return H_PARAMETER;
}
return ehca_plpar_hcall_norets(H_ERROR_DATA,
adapter_handle.handle,
ressource_handle,
r_cb,
0, 0, 0, 0);
}
u64 hipz_h_eoi(int irq)
{
unsigned long xirr;
iosync();
xirr = (0xffULL << 24) | irq;
return plpar_hcall_norets(H_EOI, xirr);
}
