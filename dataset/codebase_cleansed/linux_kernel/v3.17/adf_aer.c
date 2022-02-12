static pci_ers_result_t adf_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct adf_accel_dev *accel_dev = adf_devmgr_pci_to_accel_dev(pdev);
pr_info("QAT: Acceleration driver hardware error detected.\n");
if (!accel_dev) {
pr_err("QAT: Can't find acceleration device\n");
return PCI_ERS_RESULT_DISCONNECT;
}
if (state == pci_channel_io_perm_failure) {
pr_err("QAT: Can't recover from device error\n");
return PCI_ERS_RESULT_DISCONNECT;
}
return PCI_ERS_RESULT_NEED_RESET;
}
static void adf_dev_restore(struct adf_accel_dev *accel_dev)
{
struct pci_dev *pdev = accel_to_pci_dev(accel_dev);
struct pci_dev *parent = pdev->bus->self;
uint16_t ppdstat = 0, bridge_ctl = 0;
int pending = 0;
pr_info("QAT: Reseting device qat_dev%d\n", accel_dev->accel_id);
pci_read_config_word(pdev, PPDSTAT_OFFSET, &ppdstat);
pending = ppdstat & PCI_EXP_DEVSTA_TRPND;
if (pending) {
int ctr = 0;
do {
msleep(100);
pci_read_config_word(pdev, PPDSTAT_OFFSET, &ppdstat);
pending = ppdstat & PCI_EXP_DEVSTA_TRPND;
} while (pending && ctr++ < 10);
}
if (pending)
pr_info("QAT: Transaction still in progress. Proceeding\n");
pci_read_config_word(parent, PCI_BRIDGE_CONTROL, &bridge_ctl);
bridge_ctl |= PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(parent, PCI_BRIDGE_CONTROL, bridge_ctl);
msleep(100);
bridge_ctl &= ~PCI_BRIDGE_CTL_BUS_RESET;
pci_write_config_word(parent, PCI_BRIDGE_CONTROL, bridge_ctl);
msleep(100);
pci_restore_state(pdev);
pci_save_state(pdev);
}
static void adf_device_reset_worker(struct work_struct *work)
{
struct adf_reset_dev_data *reset_data =
container_of(work, struct adf_reset_dev_data, reset_work);
struct adf_accel_dev *accel_dev = reset_data->accel_dev;
adf_dev_restarting_notify(accel_dev);
adf_dev_stop(accel_dev);
adf_dev_restore(accel_dev);
if (adf_dev_start(accel_dev)) {
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
if (adf_dev_started(accel_dev) &&
!test_bit(ADF_STATUS_RESTARTING, &accel_dev->status))
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
pr_err("QAT: Reset device timeout expired\n");
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
pr_info("QAT: Acceleration driver reset completed\n");
pr_info("QAT: Device is up and runnig\n");
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
device_reset_wq = create_workqueue("qat_device_reset_wq");
return (device_reset_wq == NULL) ? -EFAULT : 0;
}
void adf_exit_aer(void)
{
if (device_reset_wq)
destroy_workqueue(device_reset_wq);
device_reset_wq = NULL;
}
