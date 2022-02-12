int adf_put_admin_msg_sync(struct adf_accel_dev *accel_dev,
uint32_t ae, void *in, void *out)
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
int adf_init_admin_comms(struct adf_accel_dev *accel_dev)
{
struct adf_admin_comms *admin;
struct adf_bar *pmisc = &GET_BARS(accel_dev)[ADF_DH895XCC_PMISC_BAR];
void __iomem *csr = pmisc->virt_addr;
void __iomem *mailbox = csr + ADF_DH895XCC_MAILBOX_BASE_OFFSET;
uint64_t reg_val;
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
reg_val = (uint64_t)admin->phy_addr;
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
mutex_destroy(&admin->lock);
kfree(admin);
accel_dev->admin = NULL;
}
