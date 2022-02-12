static int adf_enable_msi(struct adf_accel_dev *accel_dev)
{
struct adf_accel_pci *pci_dev_info = &accel_dev->accel_pci_dev;
int stat = pci_enable_msi(pci_dev_info->pci_dev);
if (stat) {
dev_err(&GET_DEV(accel_dev),
"Failed to enable MSI interrupts\n");
return stat;
}
accel_dev->vf.irq_name = kzalloc(ADF_MAX_MSIX_VECTOR_NAME, GFP_KERNEL);
if (!accel_dev->vf.irq_name)
return -ENOMEM;
return stat;
}
static void adf_disable_msi(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
kfree(accel_dev->vf.irq_name);
pci_disable_msi(pdev);
}
static void adf_dev_stop_async(struct work_struct *work)
{
struct adf_vf_stop_data *stop_data =
container_of(work, struct adf_vf_stop_data, work);
struct adf_accel_dev *accel_dev = stop_data->accel_dev;
adf_dev_stop(accel_dev);
adf_dev_shutdown(accel_dev);
adf_enable_pf2vf_interrupts(accel_dev);
kfree(stop_data);
}
static void adf_pf2vf_bh_handler(void *data)
{
struct adf_accel_dev *accel_dev = data;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
struct adf_bar *pmisc =
&GET_BARS(accel_dev)[hw_data->get_misc_bar_id(hw_data)];
void __iomem *pmisc_bar_addr = pmisc->virt_addr;
u32 msg;
msg = ADF_CSR_RD(pmisc_bar_addr, hw_data->get_pf2vf_offset(0));
if (!(msg & ADF_PF2VF_MSGORIGIN_SYSTEM))
goto err;
switch ((msg & ADF_PF2VF_MSGTYPE_MASK) >> ADF_PF2VF_MSGTYPE_SHIFT) {
case ADF_PF2VF_MSGTYPE_RESTARTING: {
struct adf_vf_stop_data *stop_data;
dev_dbg(&GET_DEV(accel_dev),
"Restarting msg received from PF 0x%x\n", msg);
clear_bit(ADF_STATUS_PF_RUNNING, &accel_dev->status);
stop_data = kzalloc(sizeof(*stop_data), GFP_ATOMIC);
if (!stop_data) {
dev_err(&GET_DEV(accel_dev),
"Couldn't schedule stop for vf_%d\n",
accel_dev->accel_id);
return;
}
stop_data->accel_dev = accel_dev;
INIT_WORK(&stop_data->work, adf_dev_stop_async);
queue_work(adf_vf_stop_wq, &stop_data->work);
msg &= ~ADF_PF2VF_INT;
ADF_CSR_WR(pmisc_bar_addr, hw_data->get_pf2vf_offset(0), msg);
return;
}
case ADF_PF2VF_MSGTYPE_VERSION_RESP:
dev_dbg(&GET_DEV(accel_dev),
"Version resp received from PF 0x%x\n", msg);
accel_dev->vf.pf_version =
(msg & ADF_PF2VF_VERSION_RESP_VERS_MASK) >>
ADF_PF2VF_VERSION_RESP_VERS_SHIFT;
accel_dev->vf.compatible =
(msg & ADF_PF2VF_VERSION_RESP_RESULT_MASK) >>
ADF_PF2VF_VERSION_RESP_RESULT_SHIFT;
complete(&accel_dev->vf.iov_msg_completion);
break;
default:
goto err;
}
msg &= ~ADF_PF2VF_INT;
ADF_CSR_WR(pmisc_bar_addr, hw_data->get_pf2vf_offset(0), msg);
adf_enable_pf2vf_interrupts(accel_dev);
return;
err:
dev_err(&GET_DEV(accel_dev),
"Unknown message from PF (0x%x); leaving PF2VF ints disabled\n",
msg);
}
static int adf_setup_pf2vf_bh(struct adf_accel_dev *accel_dev)
{
tasklet_init(&accel_dev->vf.pf2vf_bh_tasklet,
(void *)adf_pf2vf_bh_handler, (unsigned long)accel_dev);
mutex_init(&accel_dev->vf.vf2pf_lock);
return 0;
}
static void adf_cleanup_pf2vf_bh(struct adf_accel_dev *accel_dev)
{
tasklet_disable(&accel_dev->vf.pf2vf_bh_tasklet);
tasklet_kill(&accel_dev->vf.pf2vf_bh_tasklet);
mutex_destroy(&accel_dev->vf.vf2pf_lock);
}
static irqreturn_t adf_isr(int irq, void *privdata)
{
struct adf_accel_dev *accel_dev = privdata;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
struct adf_bar *pmisc =
&GET_BARS(accel_dev)[hw_data->get_misc_bar_id(hw_data)];
void __iomem *pmisc_bar_addr = pmisc->virt_addr;
u32 v_int;
v_int = ADF_CSR_RD(pmisc_bar_addr, ADF_VINTSOU_OFFSET);
if (v_int & ADF_VINTSOU_PF2VF) {
adf_disable_pf2vf_interrupts(accel_dev);
tasklet_hi_schedule(&accel_dev->vf.pf2vf_bh_tasklet);
return IRQ_HANDLED;
}
if (v_int & ADF_VINTSOU_BUN) {
struct adf_etr_data *etr_data = accel_dev->transport;
struct adf_etr_bank_data *bank = &etr_data->banks[0];
WRITE_CSR_INT_FLAG_AND_COL(bank->csr_addr, bank->bank_number,
0);
tasklet_hi_schedule(&bank->resp_handler);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int adf_request_msi_irq(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
unsigned int cpu;
int ret;
snprintf(accel_dev->vf.irq_name, ADF_MAX_MSIX_VECTOR_NAME,
"qat_%02x:%02d.%02d", pdev->bus->number, PCI_SLOT(pdev->devfn),
PCI_FUNC(pdev->devfn));
ret = request_irq(pdev->irq, adf_isr, 0, accel_dev->vf.irq_name,
(void *)accel_dev);
if (ret) {
dev_err(&GET_DEV(accel_dev), "failed to enable irq for %s\n",
accel_dev->vf.irq_name);
return ret;
}
cpu = accel_dev->accel_id % num_online_cpus();
irq_set_affinity_hint(pdev->irq, get_cpu_mask(cpu));
return ret;
}
static int adf_setup_bh(struct adf_accel_dev *accel_dev)
{
struct adf_etr_data *priv_data = accel_dev->transport;
tasklet_init(&priv_data->banks[0].resp_handler, adf_response_handler,
(unsigned long)priv_data->banks);
return 0;
}
static void adf_cleanup_bh(struct adf_accel_dev *accel_dev)
{
struct adf_etr_data *priv_data = accel_dev->transport;
tasklet_disable(&priv_data->banks[0].resp_handler);
tasklet_kill(&priv_data->banks[0].resp_handler);
}
void adf_vf_isr_resource_free(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
irq_set_affinity_hint(pdev->irq, NULL);
free_irq(pdev->irq, (void *)accel_dev);
adf_cleanup_bh(accel_dev);
adf_cleanup_pf2vf_bh(accel_dev);
adf_disable_msi(accel_dev);
}
int adf_vf_isr_resource_alloc(struct adf_accel_dev *accel_dev)
{
if (adf_enable_msi(accel_dev))
goto err_out;
if (adf_setup_pf2vf_bh(accel_dev))
goto err_out;
if (adf_setup_bh(accel_dev))
goto err_out;
if (adf_request_msi_irq(accel_dev))
goto err_out;
return 0;
err_out:
adf_vf_isr_resource_free(accel_dev);
return -EFAULT;
}
int __init adf_init_vf_wq(void)
{
adf_vf_stop_wq = alloc_workqueue("adf_vf_stop_wq", WQ_MEM_RECLAIM, 0);
return !adf_vf_stop_wq ? -EFAULT : 0;
}
void adf_exit_vf_wq(void)
{
if (adf_vf_stop_wq)
destroy_workqueue(adf_vf_stop_wq);
adf_vf_stop_wq = NULL;
}
