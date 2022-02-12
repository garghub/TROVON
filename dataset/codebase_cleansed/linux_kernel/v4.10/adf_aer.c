static pci_ers_result_t adf_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct adf_accel_dev *accel_dev = adf_devmgr_pci_to_accel_dev(pdev);
dev_info(&pdev->dev, "Acceleration driver hardware error detected.\n");
if (!accel_dev) {
dev_err(&pdev->dev, "Can't find acceleration device\n");
return PCI_ERS_RESULT_DISCONNECT;
}
if (state == pci_channel_io_perm_failure) {
dev_err(&pdev->dev, "Can't recover from device error\n");
return PCI_ERS_RESULT_DISCONNECT;
}
return PCI_ERS_RESULT_NEED_RESET;
}
void adf_reset_sbr(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
struct pci_dev *parent = pdev->bus->self;
uint16_t bridge_ctl = 0;
if (!parent)
parent = pdev;
if (!pci_wait_for_pending_transaction(pdev))
dev_info(&GET_DEV(accel_dev),
"Transaction still in progress. Proceeding\n");
dev_info(&GET_DEV(accel_dev), "Secondary bus reset\n");
pci_read_config_word(parent, PCI_BRIDGE_CONTROL, &bridge_ctl);
bridge_ctl |= PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(parent, PCI_BRIDGE_CONTROL, bridge_ctl);
msleep(100);
bridge_ctl &= ~PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(parent, PCI_BRIDGE_CONTROL, bridge_ctl);
msleep(100);
}
void adf_reset_flr(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
u16 control = 0;
int pos = 0;
dev_info(&GET_DEV(accel_dev), "Function level reset\n");
pos = pci_pcie_cap(pdev);
if (!pos) {
dev_err(&GET_DEV(accel_dev), "Restart device failed\n");
return;
}
pci_read_config_word(pdev, pos + PCI_EXP_DEVCTL, &control);
control |= PCI_EXP_DEVCTL_BCR_FLR;
pci_write_config_word(pdev, pos + PCI_EXP_DEVCTL, control);
msleep(100);
}
void adf_dev_restore(struct adf_accel_dev *accel_dev)
{
struct adf_hw_device_data *hw_device = accel_dev->hw_device;
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
if (hw_device->reset_device) {
dev_info(&GET_DEV(accel_dev), "Resetting device qat_dev%d\n",
accel_dev->accel_id);
hw_device->reset_device(accel_dev);
pci_restore_state(pdev);
pci_save_state(pdev);
}
}
static void adf_device_reset_worker(struct work_struct *work)
{
struct adf_reset_dev_data *reset_data =
container_of(work, struct adf_reset_dev_data, reset_work);
struct adf_accel_dev *accel_dev = reset_data->accel_dev;
adf_dev_restarting_notify(accel_dev);
adf_dev_stop(accel_dev);
adf_dev_shutdown(accel_dev);
if (adf_dev_init(accel_dev) || adf_dev_start(accel_dev)) {
dev_err(&GET_DEV(accel_dev), "Restart device failed\n");
kfree(reset_data);
WARN(1, "QAT: device restart failed. Device is unusable\n");
return;
}
adf_dev_restarted_notify(accel_dev);
clear_bit(ADF_STATUS_RESTARTING, &accel_dev->status);
if (reset_data->mode == ADF_DEV_RESET_SYNC)
complete(&reset_data->compl);
else
kfree(reset_data);
}
static int adf_dev_aer_schedule_reset(struct adf_accel_dev *accel_dev,
enum adf_dev_reset_mode mode)
{
struct adf_reset_dev_data *reset_data;
if (!adf_dev_started(accel_dev) ||
test_bit(ADF_STATUS_RESTARTING, &accel_dev->status))
return 0;
set_bit(ADF_STATUS_RESTARTING, &accel_dev->status);
reset_data = kzalloc(sizeof(*reset_data), GFP_ATOMIC);
if (!reset_data)
return -ENOMEM;
reset_data->accel_dev = accel_dev;
init_completion(&reset_data->compl);
reset_data->mode = mode;
INIT_WORK(&reset_data->reset_work, adf_device_reset_worker);
queue_work(device_reset_wq, &reset_data->reset_work);
if (mode == ADF_DEV_RESET_SYNC) {
int ret = 0;
unsigned long wait_jiffies = msecs_to_jiffies(10000);
unsigned long timeout = wait_for_completion_timeout(
&reset_data->compl, wait_jiffies);
if (!timeout) {
dev_err(&GET_DEV(accel_dev),
"Reset device timeout expired\n");
ret = -EFAULT;
}
kfree(reset_data);
return ret;
}
return 0;
}
static pci_ers_result_t adf_slot_reset(struct pci_dev *pdev)
{
struct adf_accel_dev *accel_dev = adf_devmgr_pci_to_accel_dev(pdev);
if (!accel_dev) {
pr_err("QAT: Can't find acceleration device\n");
return PCI_ERS_RESULT_DISCONNECT;
}
pci_cleanup_aer_uncorrect_error_status(pdev);
if (adf_dev_aer_schedule_reset(accel_dev, ADF_DEV_RESET_SYNC))
return PCI_ERS_RESULT_DISCONNECT;
return PCI_ERS_RESULT_RECOVERED;
}
static void adf_resume(struct pci_dev *pdev)
{
dev_info(&pdev->dev, "Acceleration driver reset completed\n");
dev_info(&pdev->dev, "Device is up and runnig\n");
}
int adf_enable_aer(struct adf_accel_dev *accel_dev, struct pci_driver *adf)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
adf->err_handler = &adf_err_handler;
pci_enable_pcie_error_reporting(pdev);
return 0;
}
void adf_disable_aer(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
pci_disable_pcie_error_reporting(pdev);
}
int adf_init_aer(void)
{
device_reset_wq = alloc_workqueue("qat_device_reset_wq",
WQ_MEM_RECLAIM, 0);
return !device_reset_wq ? -EFAULT : 0;
}
void adf_exit_aer(void)
{
if (device_reset_wq)
destroy_workqueue(device_reset_wq);
device_reset_wq = NULL;
}
