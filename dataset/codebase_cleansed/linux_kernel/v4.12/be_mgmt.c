int beiscsi_modify_eq_delay(struct beiscsi_hba *phba,
struct be_set_eqd *set_eqd,
int num)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_cmd_req_modify_eq_delay *req;
unsigned int tag;
int i;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_COMMON,
OPCODE_COMMON_MODIFY_EQ_DELAY, sizeof(*req));
req->num_eq = cpu_to_le32(num);
for (i = 0; i < num; i++) {
req->delay[i].eq_id = cpu_to_le32(set_eqd[i].eq_id);
req->delay[i].phase = 0;
req->delay[i].delay_multiplier =
cpu_to_le32(set_eqd[i].delay_multiplier);
}
set_bit(MCC_TAG_STATE_IGNORE, &ctrl->ptag_state[tag].tag_state);
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
unsigned int mgmt_vendor_specific_fw_cmd(struct be_ctrl_info *ctrl,
struct beiscsi_hba *phba,
struct bsg_job *job,
struct be_dma_mem *nonemb_cmd)
{
struct be_mcc_wrb *wrb;
struct be_sge *mcc_sge;
unsigned int tag = 0;
struct iscsi_bsg_request *bsg_req = job->request;
struct be_bsg_vendor_cmd *req = nonemb_cmd->va;
unsigned short region, sector_size, sector, offset;
nonemb_cmd->size = job->request_payload.payload_len;
memset(nonemb_cmd->va, 0, nonemb_cmd->size);
region = bsg_req->rqst_data.h_vendor.vendor_cmd[1];
sector_size = bsg_req->rqst_data.h_vendor.vendor_cmd[2];
sector = bsg_req->rqst_data.h_vendor.vendor_cmd[3];
offset = bsg_req->rqst_data.h_vendor.vendor_cmd[4];
req->region = region;
req->sector = sector;
req->offset = offset;
if (mutex_lock_interruptible(&ctrl->mbox_lock))
return 0;
switch (bsg_req->rqst_data.h_vendor.vendor_cmd[0]) {
case BEISCSI_WRITE_FLASH:
offset = sector * sector_size + offset;
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI,
OPCODE_COMMON_WRITE_FLASH, sizeof(*req));
sg_copy_to_buffer(job->request_payload.sg_list,
job->request_payload.sg_cnt,
nonemb_cmd->va + offset, job->request_len);
break;
case BEISCSI_READ_FLASH:
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI,
OPCODE_COMMON_READ_FLASH, sizeof(*req));
break;
default:
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Unsupported cmd = 0x%x\n\n",
bsg_req->rqst_data.h_vendor.vendor_cmd[0]);
mutex_unlock(&ctrl->mbox_lock);
return -EPERM;
}
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
mcc_sge = nonembedded_sgl(wrb);
be_wrb_hdr_prepare(wrb, nonemb_cmd->size, false,
job->request_payload.sg_cnt);
mcc_sge->pa_hi = cpu_to_le32(upper_32_bits(nonemb_cmd->dma));
mcc_sge->pa_lo = cpu_to_le32(nonemb_cmd->dma & 0xFFFFFFFF);
mcc_sge->len = cpu_to_le32(nonemb_cmd->size);
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
int mgmt_open_connection(struct beiscsi_hba *phba,
struct sockaddr *dst_addr,
struct beiscsi_endpoint *beiscsi_ep,
struct be_dma_mem *nonemb_cmd)
{
struct hwi_controller *phwi_ctrlr;
struct hwi_context_memory *phwi_context;
struct sockaddr_in *daddr_in = (struct sockaddr_in *)dst_addr;
struct sockaddr_in6 *daddr_in6 = (struct sockaddr_in6 *)dst_addr;
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct tcp_connect_and_offload_in_v1 *req;
unsigned short def_hdr_id;
unsigned short def_data_id;
struct phys_addr template_address = { 0, 0 };
struct phys_addr *ptemplate_address;
unsigned int tag = 0;
unsigned int i, ulp_num;
unsigned short cid = beiscsi_ep->ep_cid;
struct be_sge *sge;
if (dst_addr->sa_family != PF_INET && dst_addr->sa_family != PF_INET6) {
beiscsi_log(phba, KERN_ERR, BEISCSI_LOG_CONFIG,
"BG_%d : unknown addr family %d\n",
dst_addr->sa_family);
return -EINVAL;
}
phwi_ctrlr = phba->phwi_ctrlr;
phwi_context = phwi_ctrlr->phwi_ctxt;
ulp_num = phwi_ctrlr->wrb_context[BE_GET_CRI_FROM_CID(cid)].ulp_num;
def_hdr_id = (unsigned short)HWI_GET_DEF_HDRQ_ID(phba, ulp_num);
def_data_id = (unsigned short)HWI_GET_DEF_BUFQ_ID(phba, ulp_num);
ptemplate_address = &template_address;
ISCSI_GET_PDU_TEMPLATE_ADDRESS(phba, ptemplate_address);
if (mutex_lock_interruptible(&ctrl->mbox_lock))
return 0;
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
sge = nonembedded_sgl(wrb);
req = nonemb_cmd->va;
memset(req, 0, sizeof(*req));
be_wrb_hdr_prepare(wrb, nonemb_cmd->size, false, 1);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI,
OPCODE_COMMON_ISCSI_TCP_CONNECT_AND_OFFLOAD,
nonemb_cmd->size);
if (dst_addr->sa_family == PF_INET) {
__be32 s_addr = daddr_in->sin_addr.s_addr;
req->ip_address.ip_type = BEISCSI_IP_TYPE_V4;
req->ip_address.addr[0] = s_addr & 0x000000ff;
req->ip_address.addr[1] = (s_addr & 0x0000ff00) >> 8;
req->ip_address.addr[2] = (s_addr & 0x00ff0000) >> 16;
req->ip_address.addr[3] = (s_addr & 0xff000000) >> 24;
req->tcp_port = ntohs(daddr_in->sin_port);
beiscsi_ep->dst_addr = daddr_in->sin_addr.s_addr;
beiscsi_ep->dst_tcpport = ntohs(daddr_in->sin_port);
beiscsi_ep->ip_type = BEISCSI_IP_TYPE_V4;
} else {
req->ip_address.ip_type = BEISCSI_IP_TYPE_V6;
memcpy(&req->ip_address.addr,
&daddr_in6->sin6_addr.in6_u.u6_addr8, 16);
req->tcp_port = ntohs(daddr_in6->sin6_port);
beiscsi_ep->dst_tcpport = ntohs(daddr_in6->sin6_port);
memcpy(&beiscsi_ep->dst6_addr,
&daddr_in6->sin6_addr.in6_u.u6_addr8, 16);
beiscsi_ep->ip_type = BEISCSI_IP_TYPE_V6;
}
req->cid = cid;
i = phba->nxt_cqid++;
if (phba->nxt_cqid == phba->num_cpus)
phba->nxt_cqid = 0;
req->cq_id = phwi_context->be_cq[i].id;
beiscsi_log(phba, KERN_INFO, BEISCSI_LOG_CONFIG,
"BG_%d : i=%d cq_id=%d\n", i, req->cq_id);
req->defq_id = def_hdr_id;
req->hdr_ring_id = def_hdr_id;
req->data_ring_id = def_data_id;
req->do_offload = 1;
req->dataout_template_pa.lo = ptemplate_address->lo;
req->dataout_template_pa.hi = ptemplate_address->hi;
sge->pa_hi = cpu_to_le32(upper_32_bits(nonemb_cmd->dma));
sge->pa_lo = cpu_to_le32(nonemb_cmd->dma & 0xFFFFFFFF);
sge->len = cpu_to_le32(nonemb_cmd->size);
if (!is_chip_be2_be3r(phba)) {
req->hdr.version = MBX_CMD_VER1;
req->tcp_window_size = 0x8000;
req->tcp_window_scale_count = 2;
}
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
static int mgmt_exec_nonemb_cmd(struct beiscsi_hba *phba,
struct be_dma_mem *nonemb_cmd, void *resp_buf,
int resp_buf_len)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_sge *sge;
unsigned int tag;
int rc = 0;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
rc = -ENOMEM;
goto free_cmd;
}
sge = nonembedded_sgl(wrb);
be_wrb_hdr_prepare(wrb, nonemb_cmd->size, false, 1);
sge->pa_hi = cpu_to_le32(upper_32_bits(nonemb_cmd->dma));
sge->pa_lo = cpu_to_le32(lower_32_bits(nonemb_cmd->dma));
sge->len = cpu_to_le32(nonemb_cmd->size);
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
rc = beiscsi_mccq_compl_wait(phba, tag, NULL, nonemb_cmd);
if (resp_buf)
memcpy(resp_buf, nonemb_cmd->va, resp_buf_len);
if (rc) {
if (rc == -EAGAIN)
return rc;
beiscsi_log(phba, KERN_WARNING,
BEISCSI_LOG_CONFIG | BEISCSI_LOG_MBOX,
"BG_%d : mgmt_exec_nonemb_cmd Failed status\n");
if (rc != -EBUSY)
goto free_cmd;
else
return rc;
}
free_cmd:
pci_free_consistent(ctrl->pdev, nonemb_cmd->size,
nonemb_cmd->va, nonemb_cmd->dma);
return rc;
}
static int mgmt_alloc_cmd_data(struct beiscsi_hba *phba, struct be_dma_mem *cmd,
int iscsi_cmd, int size)
{
cmd->va = pci_zalloc_consistent(phba->ctrl.pdev, size, &cmd->dma);
if (!cmd->va) {
beiscsi_log(phba, KERN_ERR, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to allocate memory for if info\n");
return -ENOMEM;
}
cmd->size = size;
be_cmd_hdr_prepare(cmd->va, CMD_SUBSYSTEM_ISCSI, iscsi_cmd, size);
beiscsi_log(phba, KERN_INFO, BEISCSI_LOG_CONFIG,
"BG_%d : subsystem iSCSI cmd %d size %d\n",
iscsi_cmd, size);
return 0;
}
unsigned int beiscsi_if_get_handle(struct beiscsi_hba *phba)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_cmd_get_all_if_id_req *req;
struct be_cmd_get_all_if_id_req *pbe_allid;
unsigned int tag;
int status = 0;
if (mutex_lock_interruptible(&ctrl->mbox_lock))
return -EINTR;
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return -ENOMEM;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI,
OPCODE_COMMON_ISCSI_NTWK_GET_ALL_IF_ID,
sizeof(*req));
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
status = beiscsi_mccq_compl_wait(phba, tag, &wrb, NULL);
if (status) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : %s failed: %d\n", __func__, status);
return -EBUSY;
}
pbe_allid = embedded_payload(wrb);
phba->interface_handle = pbe_allid->if_hndl_list[0];
return status;
}
static inline bool beiscsi_if_zero_ip(u8 *ip, u32 ip_type)
{
u32 len;
len = (ip_type < BEISCSI_IP_TYPE_V6) ? IP_V4_LEN : IP_V6_LEN;
while (len && !ip[len - 1])
len--;
return (len == 0);
}
static int beiscsi_if_mod_gw(struct beiscsi_hba *phba,
u32 action, u32 ip_type, u8 *gw)
{
struct be_cmd_set_def_gateway_req *req;
struct be_dma_mem nonemb_cmd;
int rt_val;
rt_val = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_MODIFY_DEFAULT_GATEWAY,
sizeof(*req));
if (rt_val)
return rt_val;
req = nonemb_cmd.va;
req->action = action;
req->ip_addr.ip_type = ip_type;
memcpy(req->ip_addr.addr, gw,
(ip_type < BEISCSI_IP_TYPE_V6) ? IP_V4_LEN : IP_V6_LEN);
return mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, NULL, 0);
}
int beiscsi_if_set_gw(struct beiscsi_hba *phba, u32 ip_type, u8 *gw)
{
struct be_cmd_get_def_gateway_resp gw_resp;
int rt_val;
memset(&gw_resp, 0, sizeof(gw_resp));
rt_val = beiscsi_if_get_gw(phba, ip_type, &gw_resp);
if (rt_val) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to Get Gateway Addr\n");
return rt_val;
}
if (!beiscsi_if_zero_ip(gw_resp.ip_addr.addr, ip_type)) {
rt_val = beiscsi_if_mod_gw(phba, IP_ACTION_DEL, ip_type,
gw_resp.ip_addr.addr);
if (rt_val) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to clear Gateway Addr Set\n");
return rt_val;
}
}
rt_val = beiscsi_if_mod_gw(phba, IP_ACTION_ADD, ip_type, gw);
if (rt_val)
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to Set Gateway Addr\n");
return rt_val;
}
int beiscsi_if_get_gw(struct beiscsi_hba *phba, u32 ip_type,
struct be_cmd_get_def_gateway_resp *resp)
{
struct be_cmd_get_def_gateway_req *req;
struct be_dma_mem nonemb_cmd;
int rc;
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_GET_DEFAULT_GATEWAY,
sizeof(*resp));
if (rc)
return rc;
req = nonemb_cmd.va;
req->ip_type = ip_type;
return mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, resp,
sizeof(*resp));
}
static int
beiscsi_if_clr_ip(struct beiscsi_hba *phba,
struct be_cmd_get_if_info_resp *if_info)
{
struct be_cmd_set_ip_addr_req *req;
struct be_dma_mem nonemb_cmd;
int rc;
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_MODIFY_IP_ADDR,
sizeof(*req));
if (rc)
return rc;
req = nonemb_cmd.va;
req->ip_params.record_entry_count = 1;
req->ip_params.ip_record.action = IP_ACTION_DEL;
req->ip_params.ip_record.interface_hndl =
phba->interface_handle;
req->ip_params.ip_record.ip_addr.size_of_structure =
sizeof(struct be_ip_addr_subnet_format);
req->ip_params.ip_record.ip_addr.ip_type = if_info->ip_addr.ip_type;
memcpy(req->ip_params.ip_record.ip_addr.addr,
if_info->ip_addr.addr,
sizeof(if_info->ip_addr.addr));
memcpy(req->ip_params.ip_record.ip_addr.subnet_mask,
if_info->ip_addr.subnet_mask,
sizeof(if_info->ip_addr.subnet_mask));
rc = mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, NULL, 0);
if (rc < 0 || req->ip_params.ip_record.status) {
beiscsi_log(phba, KERN_INFO, BEISCSI_LOG_CONFIG,
"BG_%d : failed to clear IP: rc %d status %d\n",
rc, req->ip_params.ip_record.status);
}
return rc;
}
static int
beiscsi_if_set_ip(struct beiscsi_hba *phba, u8 *ip,
u8 *subnet, u32 ip_type)
{
struct be_cmd_set_ip_addr_req *req;
struct be_dma_mem nonemb_cmd;
uint32_t ip_len;
int rc;
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_MODIFY_IP_ADDR,
sizeof(*req));
if (rc)
return rc;
req = nonemb_cmd.va;
req->ip_params.record_entry_count = 1;
req->ip_params.ip_record.action = IP_ACTION_ADD;
req->ip_params.ip_record.interface_hndl =
phba->interface_handle;
req->ip_params.ip_record.ip_addr.size_of_structure =
sizeof(struct be_ip_addr_subnet_format);
req->ip_params.ip_record.ip_addr.ip_type = ip_type;
ip_len = (ip_type < BEISCSI_IP_TYPE_V6) ? IP_V4_LEN : IP_V6_LEN;
memcpy(req->ip_params.ip_record.ip_addr.addr, ip, ip_len);
if (subnet)
memcpy(req->ip_params.ip_record.ip_addr.subnet_mask,
subnet, ip_len);
rc = mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, NULL, 0);
if (rc < 0 || req->ip_params.ip_record.status) {
__beiscsi_log(phba, KERN_ERR,
"BG_%d : failed to set IP: rc %d status %d\n",
rc, req->ip_params.ip_record.status);
if (req->ip_params.ip_record.status)
rc = -EINVAL;
}
return rc;
}
int beiscsi_if_en_static(struct beiscsi_hba *phba, u32 ip_type,
u8 *ip, u8 *subnet)
{
struct be_cmd_get_if_info_resp *if_info;
struct be_cmd_rel_dhcp_req *reldhcp;
struct be_dma_mem nonemb_cmd;
int rc;
rc = beiscsi_if_get_info(phba, ip_type, &if_info);
if (rc)
return rc;
if (if_info->dhcp_state) {
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_REL_STATELESS_IP_ADDR,
sizeof(*reldhcp));
if (rc)
goto exit;
reldhcp = nonemb_cmd.va;
reldhcp->interface_hndl = phba->interface_handle;
reldhcp->ip_type = ip_type;
rc = mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, NULL, 0);
if (rc < 0) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : failed to release existing DHCP: %d\n",
rc);
goto exit;
}
}
if (!beiscsi_if_zero_ip(if_info->ip_addr.addr, ip_type)) {
rc = beiscsi_if_clr_ip(phba, if_info);
if (rc)
goto exit;
}
if (ip)
rc = beiscsi_if_set_ip(phba, ip, subnet, ip_type);
exit:
kfree(if_info);
return rc;
}
int beiscsi_if_en_dhcp(struct beiscsi_hba *phba, u32 ip_type)
{
struct be_cmd_get_def_gateway_resp gw_resp;
struct be_cmd_get_if_info_resp *if_info;
struct be_cmd_set_dhcp_req *dhcpreq;
struct be_dma_mem nonemb_cmd;
u8 *gw;
int rc;
rc = beiscsi_if_get_info(phba, ip_type, &if_info);
if (rc)
return rc;
if (if_info->dhcp_state) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : DHCP Already Enabled\n");
goto exit;
}
if (!beiscsi_if_zero_ip(if_info->ip_addr.addr, ip_type)) {
rc = beiscsi_if_clr_ip(phba, if_info);
if (rc)
goto exit;
}
memset(&gw_resp, 0, sizeof(gw_resp));
rc = beiscsi_if_get_gw(phba, if_info->ip_addr.ip_type, &gw_resp);
if (rc) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to Get Gateway Addr\n");
goto exit;
}
gw = (u8 *)&gw_resp.ip_addr.addr;
if (!beiscsi_if_zero_ip(gw, if_info->ip_addr.ip_type)) {
rc = beiscsi_if_mod_gw(phba, IP_ACTION_DEL,
if_info->ip_addr.ip_type, gw);
if (rc) {
beiscsi_log(phba, KERN_WARNING, BEISCSI_LOG_CONFIG,
"BG_%d : Failed to clear Gateway Addr Set\n");
goto exit;
}
}
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_CONFIG_STATELESS_IP_ADDR,
sizeof(*dhcpreq));
if (rc)
goto exit;
dhcpreq = nonemb_cmd.va;
dhcpreq->flags = 1;
dhcpreq->retry_count = 1;
dhcpreq->interface_hndl = phba->interface_handle;
dhcpreq->ip_type = ip_type;
rc = mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, NULL, 0);
exit:
kfree(if_info);
return rc;
}
int beiscsi_if_set_vlan(struct beiscsi_hba *phba, uint16_t vlan_tag)
{
int rc;
unsigned int tag;
tag = be_cmd_set_vlan(phba, vlan_tag);
if (!tag) {
beiscsi_log(phba, KERN_ERR,
(BEISCSI_LOG_CONFIG | BEISCSI_LOG_MBOX),
"BG_%d : VLAN Setting Failed\n");
return -EBUSY;
}
rc = beiscsi_mccq_compl_wait(phba, tag, NULL, NULL);
if (rc) {
beiscsi_log(phba, KERN_ERR,
(BEISCSI_LOG_CONFIG | BEISCSI_LOG_MBOX),
"BS_%d : VLAN MBX Cmd Failed\n");
return rc;
}
return rc;
}
int beiscsi_if_get_info(struct beiscsi_hba *phba, int ip_type,
struct be_cmd_get_if_info_resp **if_info)
{
struct be_cmd_get_if_info_req *req;
struct be_dma_mem nonemb_cmd;
uint32_t ioctl_size = sizeof(struct be_cmd_get_if_info_resp);
int rc;
rc = beiscsi_if_get_handle(phba);
if (rc)
return rc;
do {
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_GET_IF_INFO,
ioctl_size);
if (rc)
return rc;
req = nonemb_cmd.va;
req->interface_hndl = phba->interface_handle;
req->ip_type = ip_type;
*if_info = kzalloc(ioctl_size, GFP_KERNEL);
if (!*if_info) {
beiscsi_log(phba, KERN_ERR,
BEISCSI_LOG_INIT | BEISCSI_LOG_CONFIG,
"BG_%d : Memory Allocation Failure\n");
pci_free_consistent(phba->ctrl.pdev,
nonemb_cmd.size,
nonemb_cmd.va,
nonemb_cmd.dma);
return -ENOMEM;
}
rc = mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, *if_info,
ioctl_size);
if (rc == -EAGAIN) {
ioctl_size = ((struct be_cmd_resp_hdr *)
nonemb_cmd.va)->actual_resp_len;
ioctl_size += sizeof(struct be_cmd_req_hdr);
pci_free_consistent(phba->ctrl.pdev, nonemb_cmd.size,
nonemb_cmd.va,
nonemb_cmd.dma);
kfree(*if_info);
} else
break;
} while (true);
return rc;
}
int mgmt_get_nic_conf(struct beiscsi_hba *phba,
struct be_cmd_get_nic_conf_resp *nic)
{
struct be_dma_mem nonemb_cmd;
int rc;
rc = mgmt_alloc_cmd_data(phba, &nonemb_cmd,
OPCODE_COMMON_ISCSI_NTWK_GET_NIC_CONFIG,
sizeof(*nic));
if (rc)
return rc;
return mgmt_exec_nonemb_cmd(phba, &nonemb_cmd, nic, sizeof(*nic));
}
unsigned int be_cmd_get_initname(struct beiscsi_hba *phba)
{
unsigned int tag;
struct be_mcc_wrb *wrb;
struct be_cmd_hba_name *req;
struct be_ctrl_info *ctrl = &phba->ctrl;
if (mutex_lock_interruptible(&ctrl->mbox_lock))
return 0;
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_CFG_GET_HBA_NAME,
sizeof(*req));
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
static void beiscsi_boot_process_compl(struct beiscsi_hba *phba,
unsigned int tag)
{
struct be_cmd_get_boot_target_resp *boot_resp;
struct be_cmd_resp_logout_fw_sess *logo_resp;
struct be_cmd_get_session_resp *sess_resp;
struct be_mcc_wrb *wrb;
struct boot_struct *bs;
int boot_work, status;
if (!test_bit(BEISCSI_HBA_BOOT_WORK, &phba->state)) {
__beiscsi_log(phba, KERN_ERR,
"BG_%d : %s no boot work %lx\n",
__func__, phba->state);
return;
}
if (phba->boot_struct.tag != tag) {
__beiscsi_log(phba, KERN_ERR,
"BG_%d : %s tag mismatch %d:%d\n",
__func__, tag, phba->boot_struct.tag);
return;
}
bs = &phba->boot_struct;
boot_work = 1;
status = 0;
switch (bs->action) {
case BEISCSI_BOOT_REOPEN_SESS:
status = __beiscsi_mcc_compl_status(phba, tag, NULL, NULL);
if (!status)
bs->action = BEISCSI_BOOT_GET_SHANDLE;
else
bs->retry--;
break;
case BEISCSI_BOOT_GET_SHANDLE:
status = __beiscsi_mcc_compl_status(phba, tag, &wrb, NULL);
if (!status) {
boot_resp = embedded_payload(wrb);
bs->s_handle = boot_resp->boot_session_handle;
}
if (bs->s_handle == BE_BOOT_INVALID_SHANDLE) {
bs->action = BEISCSI_BOOT_REOPEN_SESS;
bs->retry--;
} else {
bs->action = BEISCSI_BOOT_GET_SINFO;
}
break;
case BEISCSI_BOOT_GET_SINFO:
status = __beiscsi_mcc_compl_status(phba, tag, NULL,
&bs->nonemb_cmd);
if (!status) {
sess_resp = bs->nonemb_cmd.va;
memcpy(&bs->boot_sess, &sess_resp->session_info,
sizeof(struct mgmt_session_info));
bs->action = BEISCSI_BOOT_LOGOUT_SESS;
} else {
__beiscsi_log(phba, KERN_ERR,
"BG_%d : get boot session info error : 0x%x\n",
status);
boot_work = 0;
}
pci_free_consistent(phba->ctrl.pdev, bs->nonemb_cmd.size,
bs->nonemb_cmd.va, bs->nonemb_cmd.dma);
bs->nonemb_cmd.va = NULL;
break;
case BEISCSI_BOOT_LOGOUT_SESS:
status = __beiscsi_mcc_compl_status(phba, tag, &wrb, NULL);
if (!status) {
logo_resp = embedded_payload(wrb);
if (logo_resp->session_status != BE_SESS_STATUS_CLOSE) {
__beiscsi_log(phba, KERN_ERR,
"BG_%d : FW boot session logout error : 0x%x\n",
logo_resp->session_status);
}
}
bs->action = BEISCSI_BOOT_CREATE_KSET;
break;
default:
break;
}
bs->tag = 0;
if (!bs->retry) {
boot_work = 0;
__beiscsi_log(phba, KERN_ERR,
"BG_%d : failed to setup boot target: status %d action %d\n",
status, bs->action);
}
if (!boot_work) {
clear_bit(BEISCSI_HBA_BOOT_WORK, &phba->state);
return;
}
schedule_work(&phba->boot_work);
}
unsigned int beiscsi_boot_logout_sess(struct beiscsi_hba *phba)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_cmd_req_logout_fw_sess *req;
unsigned int tag;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_SESSION_LOGOUT_TARGET,
sizeof(struct be_cmd_req_logout_fw_sess));
req->session_handle = phba->boot_struct.boot_sess.session_handle;
phba->boot_struct.tag = tag;
set_bit(MCC_TAG_STATE_ASYNC, &ctrl->ptag_state[tag].tag_state);
ctrl->ptag_state[tag].cbfn = beiscsi_boot_process_compl;
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
unsigned int beiscsi_boot_reopen_sess(struct beiscsi_hba *phba)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_cmd_reopen_session_req *req;
unsigned int tag;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_DRIVER_REOPEN_ALL_SESSIONS,
sizeof(struct be_cmd_reopen_session_resp));
req->reopen_type = BE_REOPEN_BOOT_SESSIONS;
req->session_handle = BE_BOOT_INVALID_SHANDLE;
phba->boot_struct.tag = tag;
set_bit(MCC_TAG_STATE_ASYNC, &ctrl->ptag_state[tag].tag_state);
ctrl->ptag_state[tag].cbfn = beiscsi_boot_process_compl;
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
unsigned int beiscsi_boot_get_sinfo(struct beiscsi_hba *phba)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_cmd_get_session_req *req;
struct be_dma_mem *nonemb_cmd;
struct be_mcc_wrb *wrb;
struct be_sge *sge;
unsigned int tag;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
nonemb_cmd = &phba->boot_struct.nonemb_cmd;
nonemb_cmd->size = sizeof(struct be_cmd_get_session_resp);
nonemb_cmd->va = pci_alloc_consistent(phba->ctrl.pdev,
nonemb_cmd->size,
&nonemb_cmd->dma);
if (!nonemb_cmd->va) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = nonemb_cmd->va;
memset(req, 0, sizeof(*req));
sge = nonembedded_sgl(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), false, 1);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_SESSION_GET_A_SESSION,
sizeof(struct be_cmd_get_session_resp));
req->session_handle = phba->boot_struct.s_handle;
sge->pa_hi = cpu_to_le32(upper_32_bits(nonemb_cmd->dma));
sge->pa_lo = cpu_to_le32(nonemb_cmd->dma & 0xFFFFFFFF);
sge->len = cpu_to_le32(nonemb_cmd->size);
phba->boot_struct.tag = tag;
set_bit(MCC_TAG_STATE_ASYNC, &ctrl->ptag_state[tag].tag_state);
ctrl->ptag_state[tag].cbfn = beiscsi_boot_process_compl;
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
unsigned int __beiscsi_boot_get_shandle(struct beiscsi_hba *phba, int async)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_cmd_get_boot_target_req *req;
unsigned int tag;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(*req), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_BOOT_GET_BOOT_TARGET,
sizeof(struct be_cmd_get_boot_target_resp));
if (async) {
phba->boot_struct.tag = tag;
set_bit(MCC_TAG_STATE_ASYNC, &ctrl->ptag_state[tag].tag_state);
ctrl->ptag_state[tag].cbfn = beiscsi_boot_process_compl;
}
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
int beiscsi_boot_get_shandle(struct beiscsi_hba *phba, unsigned int *s_handle)
{
struct be_cmd_get_boot_target_resp *boot_resp;
struct be_mcc_wrb *wrb;
unsigned int tag;
int rc;
*s_handle = BE_BOOT_INVALID_SHANDLE;
tag = __beiscsi_boot_get_shandle(phba, 0);
if (!tag) {
beiscsi_log(phba, KERN_ERR,
BEISCSI_LOG_CONFIG | BEISCSI_LOG_INIT,
"BG_%d : Getting Boot Target Info Failed\n");
return -EAGAIN;
}
rc = beiscsi_mccq_compl_wait(phba, tag, &wrb, NULL);
if (rc) {
beiscsi_log(phba, KERN_ERR,
BEISCSI_LOG_INIT | BEISCSI_LOG_CONFIG,
"BG_%d : MBX CMD get_boot_target Failed\n");
return -EBUSY;
}
boot_resp = embedded_payload(wrb);
if (!boot_resp->boot_session_count) {
__beiscsi_log(phba, KERN_INFO,
"BG_%d : No boot targets configured\n");
return -ENXIO;
}
*s_handle = boot_resp->boot_session_handle;
return 1;
}
ssize_t
beiscsi_drvr_ver_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, BE_NAME "\n");
}
ssize_t
beiscsi_fw_ver_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct beiscsi_hba *phba = iscsi_host_priv(shost);
return snprintf(buf, PAGE_SIZE, "%s\n", phba->fw_ver_str);
}
ssize_t
beiscsi_active_session_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct beiscsi_hba *phba = iscsi_host_priv(shost);
uint16_t avlbl_cids = 0, ulp_num, len = 0, total_cids = 0;
for (ulp_num = 0; ulp_num < BEISCSI_ULP_COUNT; ulp_num++) {
if (test_bit(ulp_num, (void *)&phba->fw_config.ulp_supported)) {
avlbl_cids = BEISCSI_ULP_AVLBL_CID(phba, ulp_num);
total_cids = BEISCSI_GET_CID_COUNT(phba, ulp_num);
len += snprintf(buf+len, PAGE_SIZE - len,
"ULP%d : %d\n", ulp_num,
(total_cids - avlbl_cids));
} else
len += snprintf(buf+len, PAGE_SIZE - len,
"ULP%d : %d\n", ulp_num, 0);
}
return len;
}
ssize_t
beiscsi_free_session_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct beiscsi_hba *phba = iscsi_host_priv(shost);
uint16_t ulp_num, len = 0;
for (ulp_num = 0; ulp_num < BEISCSI_ULP_COUNT; ulp_num++) {
if (test_bit(ulp_num, (void *)&phba->fw_config.ulp_supported))
len += snprintf(buf+len, PAGE_SIZE - len,
"ULP%d : %d\n", ulp_num,
BEISCSI_ULP_AVLBL_CID(phba, ulp_num));
else
len += snprintf(buf+len, PAGE_SIZE - len,
"ULP%d : %d\n", ulp_num, 0);
}
return len;
}
ssize_t
beiscsi_adap_family_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
uint16_t dev_id = 0;
struct Scsi_Host *shost = class_to_shost(dev);
struct beiscsi_hba *phba = iscsi_host_priv(shost);
dev_id = phba->pcidev->device;
switch (dev_id) {
case BE_DEVICE_ID1:
case OC_DEVICE_ID1:
case OC_DEVICE_ID2:
return snprintf(buf, PAGE_SIZE,
"Obsolete/Unsupported BE2 Adapter Family\n");
break;
case BE_DEVICE_ID2:
case OC_DEVICE_ID3:
return snprintf(buf, PAGE_SIZE, "BE3-R Adapter Family\n");
break;
case OC_SKH_ID1:
return snprintf(buf, PAGE_SIZE, "Skyhawk-R Adapter Family\n");
break;
default:
return snprintf(buf, PAGE_SIZE,
"Unknown Adapter Family: 0x%x\n", dev_id);
break;
}
}
ssize_t
beiscsi_phys_port_disp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct beiscsi_hba *phba = iscsi_host_priv(shost);
return snprintf(buf, PAGE_SIZE, "Port Identifier : %u\n",
phba->fw_config.phys_port);
}
void beiscsi_offload_cxn_v0(struct beiscsi_offload_params *params,
struct wrb_handle *pwrb_handle,
struct be_mem_descriptor *mem_descr,
struct hwi_wrb_context *pwrb_context)
{
struct iscsi_wrb *pwrb = pwrb_handle->pwrb;
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
max_send_data_segment_length, pwrb,
params->dw[offsetof(struct amap_beiscsi_offload_params,
max_send_data_segment_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, type, pwrb,
BE_TGT_CTX_UPDT_CMD);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
first_burst_length,
pwrb,
params->dw[offsetof(struct amap_beiscsi_offload_params,
first_burst_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, erl, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
erl) / 32] & OFFLD_PARAMS_ERL));
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, dde, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
dde) / 32] & OFFLD_PARAMS_DDE) >> 2);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, hde, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
hde) / 32] & OFFLD_PARAMS_HDE) >> 3);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, ir2t, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
ir2t) / 32] & OFFLD_PARAMS_IR2T) >> 4);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, imd, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
imd) / 32] & OFFLD_PARAMS_IMD) >> 5);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, stat_sn,
pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
exp_statsn) / 32] + 1));
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, wrb_idx,
pwrb, pwrb_handle->wrb_index);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
max_burst_length, pwrb, params->dw[offsetof
(struct amap_beiscsi_offload_params,
max_burst_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, ptr2nextwrb,
pwrb, pwrb_handle->wrb_index);
if (pwrb_context->plast_wrb)
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
ptr2nextwrb,
pwrb_context->plast_wrb,
pwrb_handle->wrb_index);
pwrb_context->plast_wrb = pwrb;
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
session_state, pwrb, 0);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, compltonack,
pwrb, 1);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, notpredblq,
pwrb, 0);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb, mode, pwrb,
0);
mem_descr += ISCSI_MEM_GLOBAL_HEADER;
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
pad_buffer_addr_hi, pwrb,
mem_descr->mem_array[0].bus_address.u.a32.address_hi);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb,
pad_buffer_addr_lo, pwrb,
mem_descr->mem_array[0].bus_address.u.a32.address_lo);
}
void beiscsi_offload_cxn_v2(struct beiscsi_offload_params *params,
struct wrb_handle *pwrb_handle,
struct hwi_wrb_context *pwrb_context)
{
struct iscsi_wrb *pwrb = pwrb_handle->pwrb;
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
max_burst_length, pwrb, params->dw[offsetof
(struct amap_beiscsi_offload_params,
max_burst_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
type, pwrb,
BE_TGT_CTX_UPDT_CMD);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
ptr2nextwrb,
pwrb, pwrb_handle->wrb_index);
if (pwrb_context->plast_wrb)
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
ptr2nextwrb,
pwrb_context->plast_wrb,
pwrb_handle->wrb_index);
pwrb_context->plast_wrb = pwrb;
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, wrb_idx,
pwrb, pwrb_handle->wrb_index);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
max_send_data_segment_length, pwrb,
params->dw[offsetof(struct amap_beiscsi_offload_params,
max_send_data_segment_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
first_burst_length, pwrb,
params->dw[offsetof(struct amap_beiscsi_offload_params,
first_burst_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
max_recv_dataseg_len, pwrb,
params->dw[offsetof(struct amap_beiscsi_offload_params,
max_recv_data_segment_length) / 32]);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
max_cxns, pwrb, BEISCSI_MAX_CXNS);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, erl, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
erl) / 32] & OFFLD_PARAMS_ERL));
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, dde, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
dde) / 32] & OFFLD_PARAMS_DDE) >> 2);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, hde, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
hde) / 32] & OFFLD_PARAMS_HDE) >> 3);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
ir2t, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
ir2t) / 32] & OFFLD_PARAMS_IR2T) >> 4);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, imd, pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
imd) / 32] & OFFLD_PARAMS_IMD) >> 5);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
data_seq_inorder,
pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
data_seq_inorder) / 32] &
OFFLD_PARAMS_DATA_SEQ_INORDER) >> 6);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2,
pdu_seq_inorder,
pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
pdu_seq_inorder) / 32] &
OFFLD_PARAMS_PDU_SEQ_INORDER) >> 7);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, max_r2t,
pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
max_r2t) / 32] &
OFFLD_PARAMS_MAX_R2T) >> 8);
AMAP_SET_BITS(struct amap_iscsi_target_context_update_wrb_v2, stat_sn,
pwrb,
(params->dw[offsetof(struct amap_beiscsi_offload_params,
exp_statsn) / 32] + 1));
}
unsigned int beiscsi_invalidate_cxn(struct beiscsi_hba *phba,
struct beiscsi_endpoint *beiscsi_ep)
{
struct be_invalidate_connection_params_in *req;
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
unsigned int tag = 0;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(union be_invalidate_connection_params),
true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI_INI,
OPCODE_ISCSI_INI_DRIVER_INVALIDATE_CONNECTION,
sizeof(*req));
req->session_handle = beiscsi_ep->fw_handle;
req->cid = beiscsi_ep->ep_cid;
if (beiscsi_ep->conn)
req->cleanup_type = BE_CLEANUP_TYPE_INVALIDATE;
else
req->cleanup_type = BE_CLEANUP_TYPE_ISSUE_TCP_RST;
req->save_cfg = 0;
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
unsigned int beiscsi_upload_cxn(struct beiscsi_hba *phba,
struct beiscsi_endpoint *beiscsi_ep)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct be_mcc_wrb *wrb;
struct be_tcp_upload_params_in *req;
unsigned int tag;
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
return 0;
}
req = embedded_payload(wrb);
be_wrb_hdr_prepare(wrb, sizeof(union be_tcp_upload_params), true, 0);
be_cmd_hdr_prepare(&req->hdr, CMD_COMMON_TCP_UPLOAD,
OPCODE_COMMON_TCP_UPLOAD, sizeof(*req));
req->id = beiscsi_ep->ep_cid;
if (beiscsi_ep->conn)
req->upload_type = BE_UPLOAD_TYPE_GRACEFUL;
else
req->upload_type = BE_UPLOAD_TYPE_ABORT;
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
return tag;
}
int beiscsi_mgmt_invalidate_icds(struct beiscsi_hba *phba,
struct invldt_cmd_tbl *inv_tbl,
unsigned int nents)
{
struct be_ctrl_info *ctrl = &phba->ctrl;
struct invldt_cmds_params_in *req;
struct be_dma_mem nonemb_cmd;
struct be_mcc_wrb *wrb;
unsigned int i, tag;
struct be_sge *sge;
int rc;
if (!nents || nents > BE_INVLDT_CMD_TBL_SZ)
return -EINVAL;
nonemb_cmd.size = sizeof(union be_invldt_cmds_params);
nonemb_cmd.va = pci_zalloc_consistent(phba->ctrl.pdev,
nonemb_cmd.size,
&nonemb_cmd.dma);
if (!nonemb_cmd.va) {
beiscsi_log(phba, KERN_ERR, BEISCSI_LOG_EH,
"BM_%d : invldt_cmds_params alloc failed\n");
return -ENOMEM;
}
mutex_lock(&ctrl->mbox_lock);
wrb = alloc_mcc_wrb(phba, &tag);
if (!wrb) {
mutex_unlock(&ctrl->mbox_lock);
pci_free_consistent(phba->ctrl.pdev, nonemb_cmd.size,
nonemb_cmd.va, nonemb_cmd.dma);
return -ENOMEM;
}
req = nonemb_cmd.va;
be_wrb_hdr_prepare(wrb, nonemb_cmd.size, false, 1);
be_cmd_hdr_prepare(&req->hdr, CMD_SUBSYSTEM_ISCSI,
OPCODE_COMMON_ISCSI_ERROR_RECOVERY_INVALIDATE_COMMANDS,
sizeof(*req));
req->ref_handle = 0;
req->cleanup_type = CMD_ISCSI_COMMAND_INVALIDATE;
for (i = 0; i < nents; i++) {
req->table[i].icd = inv_tbl[i].icd;
req->table[i].cid = inv_tbl[i].cid;
req->icd_count++;
}
sge = nonembedded_sgl(wrb);
sge->pa_hi = cpu_to_le32(upper_32_bits(nonemb_cmd.dma));
sge->pa_lo = cpu_to_le32(lower_32_bits(nonemb_cmd.dma));
sge->len = cpu_to_le32(nonemb_cmd.size);
be_mcc_notify(phba, tag);
mutex_unlock(&ctrl->mbox_lock);
rc = beiscsi_mccq_compl_wait(phba, tag, NULL, &nonemb_cmd);
if (rc != -EBUSY)
pci_free_consistent(phba->ctrl.pdev, nonemb_cmd.size,
nonemb_cmd.va, nonemb_cmd.dma);
return rc;
}
