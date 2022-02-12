static inline u16 get_order_of_qentries(u16 queue_entries)
{
u8 ld = 1;
while (((1U << ld) - 1) < queue_entries)
ld++;
return ld - 1;
}
static long ehea_plpar_hcall_norets(unsigned long opcode,
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
for (i = 0; i < 5; i++) {
ret = plpar_hcall_norets(opcode, arg1, arg2, arg3, arg4,
arg5, arg6, arg7);
if (H_IS_LONG_BUSY(ret)) {
sleep_msecs = get_longbusy_msecs(ret);
msleep_interruptible(sleep_msecs);
continue;
}
if (ret < H_SUCCESS)
pr_err("opcode=%lx ret=%lx"
" arg1=%lx arg2=%lx arg3=%lx arg4=%lx"
" arg5=%lx arg6=%lx arg7=%lx\n",
opcode, ret,
arg1, arg2, arg3, arg4, arg5, arg6, arg7);
return ret;
}
return H_BUSY;
}
static long ehea_plpar_hcall9(unsigned long opcode,
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
u8 cb_cat;
for (i = 0; i < 5; i++) {
ret = plpar_hcall9(opcode, outs,
arg1, arg2, arg3, arg4, arg5,
arg6, arg7, arg8, arg9);
if (H_IS_LONG_BUSY(ret)) {
sleep_msecs = get_longbusy_msecs(ret);
msleep_interruptible(sleep_msecs);
continue;
}
cb_cat = EHEA_BMASK_GET(H_MEHEAPORT_CAT, arg2);
if ((ret < H_SUCCESS) && !(((ret == H_AUTHORITY)
&& (opcode == H_MODIFY_HEA_PORT))
&& (((cb_cat == H_PORT_CB4) && ((arg3 == H_PORT_CB4_JUMBO)
|| (arg3 == H_PORT_CB4_SPEED))) || ((cb_cat == H_PORT_CB7)
&& (arg3 == H_PORT_CB7_DUCQPN)))))
pr_err("opcode=%lx ret=%lx"
" arg1=%lx arg2=%lx arg3=%lx arg4=%lx"
" arg5=%lx arg6=%lx arg7=%lx arg8=%lx"
" arg9=%lx"
" out1=%lx out2=%lx out3=%lx out4=%lx"
" out5=%lx out6=%lx out7=%lx out8=%lx"
" out9=%lx\n",
opcode, ret,
arg1, arg2, arg3, arg4, arg5,
arg6, arg7, arg8, arg9,
outs[0], outs[1], outs[2], outs[3], outs[4],
outs[5], outs[6], outs[7], outs[8]);
return ret;
}
return H_BUSY;
}
u64 ehea_h_query_ehea_qp(const u64 adapter_handle, const u8 qp_category,
const u64 qp_handle, const u64 sel_mask, void *cb_addr)
{
return ehea_plpar_hcall_norets(H_QUERY_HEA_QP,
adapter_handle,
qp_category,
qp_handle,
sel_mask,
virt_to_abs(cb_addr),
0, 0);
}
u64 ehea_h_alloc_resource_qp(const u64 adapter_handle,
struct ehea_qp_init_attr *init_attr, const u32 pd,
u64 *qp_handle, struct h_epas *h_epas)
{
u64 hret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
u64 allocate_controls =
EHEA_BMASK_SET(H_ALL_RES_QP_EQPO, init_attr->low_lat_rq1 ? 1 : 0)
| EHEA_BMASK_SET(H_ALL_RES_QP_QPP, 0)
| EHEA_BMASK_SET(H_ALL_RES_QP_RQR, 6)
| EHEA_BMASK_SET(H_ALL_RES_QP_EQEG, 0)
| EHEA_BMASK_SET(H_ALL_RES_QP_LL_QP, init_attr->low_lat_rq1)
| EHEA_BMASK_SET(H_ALL_RES_QP_DMA128, 0)
| EHEA_BMASK_SET(H_ALL_RES_QP_HSM, 0)
| EHEA_BMASK_SET(H_ALL_RES_QP_SIGT, init_attr->signalingtype)
| EHEA_BMASK_SET(H_ALL_RES_QP_RES_TYP, H_ALL_RES_TYPE_QP);
u64 r9_reg = EHEA_BMASK_SET(H_ALL_RES_QP_PD, pd)
| EHEA_BMASK_SET(H_ALL_RES_QP_TOKEN, init_attr->qp_token);
u64 max_r10_reg =
EHEA_BMASK_SET(H_ALL_RES_QP_MAX_SWQE,
get_order_of_qentries(init_attr->max_nr_send_wqes))
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R1WQE,
get_order_of_qentries(init_attr->max_nr_rwqes_rq1))
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R2WQE,
get_order_of_qentries(init_attr->max_nr_rwqes_rq2))
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R3WQE,
get_order_of_qentries(init_attr->max_nr_rwqes_rq3))
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_SSGE, init_attr->wqe_size_enc_sq)
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R1SGE,
init_attr->wqe_size_enc_rq1)
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R2SGE,
init_attr->wqe_size_enc_rq2)
| EHEA_BMASK_SET(H_ALL_RES_QP_MAX_R3SGE,
init_attr->wqe_size_enc_rq3);
u64 r11_in =
EHEA_BMASK_SET(H_ALL_RES_QP_SWQE_IDL, init_attr->swqe_imm_data_len)
| EHEA_BMASK_SET(H_ALL_RES_QP_PORT_NUM, init_attr->port_nr);
u64 threshold =
EHEA_BMASK_SET(H_ALL_RES_QP_TH_RQ2, init_attr->rq2_threshold)
| EHEA_BMASK_SET(H_ALL_RES_QP_TH_RQ3, init_attr->rq3_threshold);
hret = ehea_plpar_hcall9(H_ALLOC_HEA_RESOURCE,
outs,
adapter_handle,
allocate_controls,
init_attr->send_cq_handle,
init_attr->recv_cq_handle,
init_attr->aff_eq_handle,
r9_reg,
max_r10_reg,
r11_in,
threshold);
*qp_handle = outs[0];
init_attr->qp_nr = (u32)outs[1];
init_attr->act_nr_send_wqes =
(u16)EHEA_BMASK_GET(H_ALL_RES_QP_ACT_SWQE, outs[2]);
init_attr->act_nr_rwqes_rq1 =
(u16)EHEA_BMASK_GET(H_ALL_RES_QP_ACT_R1WQE, outs[2]);
init_attr->act_nr_rwqes_rq2 =
(u16)EHEA_BMASK_GET(H_ALL_RES_QP_ACT_R2WQE, outs[2]);
init_attr->act_nr_rwqes_rq3 =
(u16)EHEA_BMASK_GET(H_ALL_RES_QP_ACT_R3WQE, outs[2]);
init_attr->act_wqe_size_enc_sq = init_attr->wqe_size_enc_sq;
init_attr->act_wqe_size_enc_rq1 = init_attr->wqe_size_enc_rq1;
init_attr->act_wqe_size_enc_rq2 = init_attr->wqe_size_enc_rq2;
init_attr->act_wqe_size_enc_rq3 = init_attr->wqe_size_enc_rq3;
init_attr->nr_sq_pages =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_SIZE_SQ, outs[4]);
init_attr->nr_rq1_pages =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_SIZE_RQ1, outs[4]);
init_attr->nr_rq2_pages =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_SIZE_RQ2, outs[5]);
init_attr->nr_rq3_pages =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_SIZE_RQ3, outs[5]);
init_attr->liobn_sq =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_LIOBN_SQ, outs[7]);
init_attr->liobn_rq1 =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_LIOBN_RQ1, outs[7]);
init_attr->liobn_rq2 =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_LIOBN_RQ2, outs[8]);
init_attr->liobn_rq3 =
(u32)EHEA_BMASK_GET(H_ALL_RES_QP_LIOBN_RQ3, outs[8]);
if (!hret)
hcp_epas_ctor(h_epas, outs[6], outs[6]);
return hret;
}
u64 ehea_h_alloc_resource_cq(const u64 adapter_handle,
struct ehea_cq_attr *cq_attr,
u64 *cq_handle, struct h_epas *epas)
{
u64 hret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
hret = ehea_plpar_hcall9(H_ALLOC_HEA_RESOURCE,
outs,
adapter_handle,
H_ALL_RES_TYPE_CQ,
cq_attr->eq_handle,
cq_attr->cq_token,
cq_attr->max_nr_of_cqes,
0, 0, 0, 0);
*cq_handle = outs[0];
cq_attr->act_nr_of_cqes = outs[3];
cq_attr->nr_pages = outs[4];
if (!hret)
hcp_epas_ctor(epas, outs[5], outs[6]);
return hret;
}
u64 ehea_h_alloc_resource_eq(const u64 adapter_handle,
struct ehea_eq_attr *eq_attr, u64 *eq_handle)
{
u64 hret, allocate_controls;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
allocate_controls =
EHEA_BMASK_SET(H_ALL_RES_EQ_RES_TYPE, H_ALL_RES_TYPE_EQ)
| EHEA_BMASK_SET(H_ALL_RES_EQ_NEQ, eq_attr->type ? 1 : 0)
| EHEA_BMASK_SET(H_ALL_RES_EQ_INH_EQE_GEN, !eq_attr->eqe_gen)
| EHEA_BMASK_SET(H_ALL_RES_EQ_NON_NEQ_ISN, 1);
hret = ehea_plpar_hcall9(H_ALLOC_HEA_RESOURCE,
outs,
adapter_handle,
allocate_controls,
eq_attr->max_nr_of_eqes,
0, 0, 0, 0, 0, 0);
*eq_handle = outs[0];
eq_attr->act_nr_of_eqes = outs[3];
eq_attr->nr_pages = outs[4];
eq_attr->ist1 = outs[5];
eq_attr->ist2 = outs[6];
eq_attr->ist3 = outs[7];
eq_attr->ist4 = outs[8];
return hret;
}
u64 ehea_h_modify_ehea_qp(const u64 adapter_handle, const u8 cat,
const u64 qp_handle, const u64 sel_mask,
void *cb_addr, u64 *inv_attr_id, u64 *proc_mask,
u16 *out_swr, u16 *out_rwr)
{
u64 hret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
hret = ehea_plpar_hcall9(H_MODIFY_HEA_QP,
outs,
adapter_handle,
(u64) cat,
qp_handle,
sel_mask,
virt_to_abs(cb_addr),
0, 0, 0, 0);
*inv_attr_id = outs[0];
*out_swr = outs[3];
*out_rwr = outs[4];
*proc_mask = outs[5];
return hret;
}
u64 ehea_h_register_rpage(const u64 adapter_handle, const u8 pagesize,
const u8 queue_type, const u64 resource_handle,
const u64 log_pageaddr, u64 count)
{
u64 reg_control;
reg_control = EHEA_BMASK_SET(H_REG_RPAGE_PAGE_SIZE, pagesize)
| EHEA_BMASK_SET(H_REG_RPAGE_QT, queue_type);
return ehea_plpar_hcall_norets(H_REGISTER_HEA_RPAGES,
adapter_handle,
reg_control,
resource_handle,
log_pageaddr,
count,
0, 0);
}
u64 ehea_h_register_smr(const u64 adapter_handle, const u64 orig_mr_handle,
const u64 vaddr_in, const u32 access_ctrl, const u32 pd,
struct ehea_mr *mr)
{
u64 hret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
hret = ehea_plpar_hcall9(H_REGISTER_SMR,
outs,
adapter_handle ,
orig_mr_handle,
vaddr_in,
(((u64)access_ctrl) << 32ULL),
pd,
0, 0, 0, 0);
mr->handle = outs[0];
mr->lkey = (u32)outs[2];
return hret;
}
u64 ehea_h_disable_and_get_hea(const u64 adapter_handle, const u64 qp_handle)
{
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
return ehea_plpar_hcall9(H_DISABLE_AND_GET_HEA,
outs,
adapter_handle,
H_DISABLE_GET_EHEA_WQE_P,
qp_handle,
0, 0, 0, 0, 0, 0);
}
u64 ehea_h_free_resource(const u64 adapter_handle, const u64 res_handle,
u64 force_bit)
{
return ehea_plpar_hcall_norets(H_FREE_RESOURCE,
adapter_handle,
res_handle,
force_bit,
0, 0, 0, 0);
}
u64 ehea_h_alloc_resource_mr(const u64 adapter_handle, const u64 vaddr,
const u64 length, const u32 access_ctrl,
const u32 pd, u64 *mr_handle, u32 *lkey)
{
u64 hret;
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
hret = ehea_plpar_hcall9(H_ALLOC_HEA_RESOURCE,
outs,
adapter_handle,
5,
vaddr,
length,
(((u64) access_ctrl) << 32ULL),
pd,
0, 0, 0);
*mr_handle = outs[0];
*lkey = (u32)outs[2];
return hret;
}
u64 ehea_h_register_rpage_mr(const u64 adapter_handle, const u64 mr_handle,
const u8 pagesize, const u8 queue_type,
const u64 log_pageaddr, const u64 count)
{
if ((count > 1) && (log_pageaddr & ~PAGE_MASK)) {
pr_err("not on pageboundary\n");
return H_PARAMETER;
}
return ehea_h_register_rpage(adapter_handle, pagesize,
queue_type, mr_handle,
log_pageaddr, count);
}
u64 ehea_h_query_ehea(const u64 adapter_handle, void *cb_addr)
{
u64 hret, cb_logaddr;
cb_logaddr = virt_to_abs(cb_addr);
hret = ehea_plpar_hcall_norets(H_QUERY_HEA,
adapter_handle,
cb_logaddr,
0, 0, 0, 0, 0);
#ifdef DEBUG
ehea_dump(cb_addr, sizeof(struct hcp_query_ehea), "hcp_query_ehea");
#endif
return hret;
}
u64 ehea_h_query_ehea_port(const u64 adapter_handle, const u16 port_num,
const u8 cb_cat, const u64 select_mask,
void *cb_addr)
{
u64 port_info;
u64 cb_logaddr = virt_to_abs(cb_addr);
u64 arr_index = 0;
port_info = EHEA_BMASK_SET(H_MEHEAPORT_CAT, cb_cat)
| EHEA_BMASK_SET(H_MEHEAPORT_PN, port_num);
return ehea_plpar_hcall_norets(H_QUERY_HEA_PORT,
adapter_handle,
port_info,
select_mask,
arr_index,
cb_logaddr,
0, 0);
}
u64 ehea_h_modify_ehea_port(const u64 adapter_handle, const u16 port_num,
const u8 cb_cat, const u64 select_mask,
void *cb_addr)
{
unsigned long outs[PLPAR_HCALL9_BUFSIZE];
u64 port_info;
u64 arr_index = 0;
u64 cb_logaddr = virt_to_abs(cb_addr);
port_info = EHEA_BMASK_SET(H_MEHEAPORT_CAT, cb_cat)
| EHEA_BMASK_SET(H_MEHEAPORT_PN, port_num);
#ifdef DEBUG
ehea_dump(cb_addr, sizeof(struct hcp_ehea_port_cb0), "Before HCALL");
#endif
return ehea_plpar_hcall9(H_MODIFY_HEA_PORT,
outs,
adapter_handle,
port_info,
select_mask,
arr_index,
cb_logaddr,
0, 0, 0, 0);
}
u64 ehea_h_reg_dereg_bcmc(const u64 adapter_handle, const u16 port_num,
const u8 reg_type, const u64 mc_mac_addr,
const u16 vlan_id, const u32 hcall_id)
{
u64 r5_port_num, r6_reg_type, r7_mc_mac_addr, r8_vlan_id;
u64 mac_addr = mc_mac_addr >> 16;
r5_port_num = EHEA_BMASK_SET(H_REGBCMC_PN, port_num);
r6_reg_type = EHEA_BMASK_SET(H_REGBCMC_REGTYPE, reg_type);
r7_mc_mac_addr = EHEA_BMASK_SET(H_REGBCMC_MACADDR, mac_addr);
r8_vlan_id = EHEA_BMASK_SET(H_REGBCMC_VLANID, vlan_id);
return ehea_plpar_hcall_norets(hcall_id,
adapter_handle,
r5_port_num,
r6_reg_type,
r7_mc_mac_addr,
r8_vlan_id,
0, 0);
}
u64 ehea_h_reset_events(const u64 adapter_handle, const u64 neq_handle,
const u64 event_mask)
{
return ehea_plpar_hcall_norets(H_RESET_EVENTS,
adapter_handle,
neq_handle,
event_mask,
0, 0, 0, 0);
}
u64 ehea_h_error_data(const u64 adapter_handle, const u64 ressource_handle,
void *rblock)
{
return ehea_plpar_hcall_norets(H_ERROR_DATA,
adapter_handle,
ressource_handle,
virt_to_abs(rblock),
0, 0, 0, 0);
}
