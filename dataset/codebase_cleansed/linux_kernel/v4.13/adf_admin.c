static int adf_put_admin_msg_sync(struct adf_accel_dev *accel_dev, u32 ae,
void *in, void *out)
{
struct adf_admin_comms *admin = accel_dev->admin;
int offset = ae * ADF_ADMINMSG_LEN * 2;
void __iomem *mailbox = admin->mailbox_addr;
int mb_offset = ae * ADF_DH895XCC_MAILBOX_STRIDE;
int times, received;
mutex_lock(&admin->lock);
if (ADF_CSR_RD(mailbox, mb_offset) == 1) {
mutex_unlock(&admin->lock);
return -EAGAIN;
}
memcpy(admin->virt_addr + offset, in, ADF_ADMINMSG_LEN);
ADF_CSR_WR(mailbox, mb_offset, 1);
received = 0;
for (times = 0; times < 50; times++) {
msleep(20);
if (ADF_CSR_RD(mailbox, mb_offset) == 0) {
received = 1;
break;
}
}
if (received)
memcpy(out, admin->virt_addr + offset +
ADF_ADMINMSG_LEN, ADF_ADMINMSG_LEN);
else
dev_err(&GET_DEV(accel_dev),
"Failed to send admin msg to accelerator\n");
mutex_unlock(&admin->lock);
return received ? 0 : -EFAULT;
}
static int adf_send_admin_cmd(struct adf_accel_dev *accel_dev, int cmd)
{
struct adf_hw_device_data *hw_device = accel_dev->hw_device;
struct icp_qat_fw_init_admin_req req;
struct icp_qat_fw_init_admin_resp resp;
int i;
memset(&req, 0, sizeof(struct icp_qat_fw_init_admin_req));
req.init_admin_cmd_id = cmd;
if (cmd == ICP_QAT_FW_CONSTANTS_CFG) {
req.init_cfg_sz = 1024;
req.init_cfg_ptr = accel_dev->admin->const_tbl_addr;
}
for (i = 0; i < hw_device->get_num_aes(hw_device); i++) {
memset(&resp, 0, sizeof(struct icp_qat_fw_init_admin_resp));
if (adf_put_admin_msg_sync(accel_dev, i, &req, &resp) ||
resp.init_resp_hdr.status)
return -EFAULT;
}
return 0;
}
int adf_send_admin_init(struct adf_accel_dev *accel_dev)
{
int ret = adf_send_admin_cmd(accel_dev, ICP_QAT_FW_INIT_ME);
if (ret)
return ret;
return adf_send_admin_cmd(accel_dev, ICP_QAT_FW_CONSTANTS_CFG);
}
int adf_init_admin_comms(struct adf_accel_dev *accel_dev)
{
struct adf_admin_comms *admin;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
struct adf_bar *pmisc =
&GET_BARS(accel_dev)[hw_data->get_misc_bar_id(hw_data)];
void __iomem *csr = pmisc->virt_addr;
void __iomem *mailbox = (void __iomem *)((uintptr_t)csr +
ADF_DH895XCC_MAILBOX_BASE_OFFSET);
u64 reg_val;
admin = kzalloc_node(sizeof(*accel_dev->admin), GFP_KERNEL,
dev_to_node(&GET_DEV(accel_dev)));
if (!admin)
return -ENOMEM;
admin->virt_addr = dma_zalloc_coherent(&GET_DEV(accel_dev), PAGE_SIZE,
&admin->phy_addr, GFP_KERNEL);
if (!admin->virt_addr) {
dev_err(&GET_DEV(accel_dev), "Failed to allocate dma buff\n");
kfree(admin);
return -ENOMEM;
}
admin->virt_tbl_addr = dma_zalloc_coherent(&GET_DEV(accel_dev),
PAGE_SIZE,
&admin->const_tbl_addr,
GFP_KERNEL);
if (!admin->virt_tbl_addr) {
dev_err(&GET_DEV(accel_dev), "Failed to allocate const_tbl\n");
dma_free_coherent(&GET_DEV(accel_dev), PAGE_SIZE,
admin->virt_addr, admin->phy_addr);
kfree(admin);
return -ENOMEM;
}
memcpy(admin->virt_tbl_addr, const_tab, sizeof(const_tab));
reg_val = (u64)admin->phy_addr;
ADF_CSR_WR(csr, ADF_DH895XCC_ADMINMSGUR_OFFSET, reg_val >> 32);
ADF_CSR_WR(csr, ADF_DH895XCC_ADMINMSGLR_OFFSET, reg_val);
mutex_init(&admin->lock);
admin->mailbox_addr = mailbox;
accel_dev->admin = admin;
return 0;
}
void adf_exit_admin_comms(struct adf_accel_dev *accel_dev)
{
struct adf_admin_comms *admin = accel_dev->admin;
if (!admin)
return;
if (admin->virt_addr)
dma_free_coherent(&GET_DEV(accel_dev), PAGE_SIZE,
admin->virt_addr, admin->phy_addr);
if (admin->virt_tbl_addr)
dma_free_coherent(&GET_DEV(accel_dev), PAGE_SIZE,
admin->virt_tbl_addr, admin->const_tbl_addr);
mutex_destroy(&admin->lock);
kfree(admin);
accel_dev->admin = NULL;
}
