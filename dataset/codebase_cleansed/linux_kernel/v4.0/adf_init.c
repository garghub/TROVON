static void adf_service_add(struct service_hndl *service)
{
mutex_lock(&service_lock);
list_add(&service->list, &service_table);
mutex_unlock(&service_lock);
}
int adf_service_register(struct service_hndl *service)
{
service->init_status = 0;
service->start_status = 0;
adf_service_add(service);
return 0;
}
static void adf_service_remove(struct service_hndl *service)
{
mutex_lock(&service_lock);
list_del(&service->list);
mutex_unlock(&service_lock);
}
int adf_service_unregister(struct service_hndl *service)
{
if (service->init_status || service->start_status) {
pr_err("QAT: Could not remove active service\n");
return -EFAULT;
}
adf_service_remove(service);
return 0;
}
int adf_dev_init(struct adf_accel_dev *accel_dev)
{
struct service_hndl *service;
struct list_head *list_itr;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
if (!hw_data) {
dev_err(&GET_DEV(accel_dev),
"QAT: Failed to init device - hw_data not set\n");
return -EFAULT;
}
if (!test_bit(ADF_STATUS_CONFIGURED, &accel_dev->status)) {
pr_info("QAT: Device not configured\n");
return -EFAULT;
}
if (adf_init_etr_data(accel_dev)) {
dev_err(&GET_DEV(accel_dev), "Failed initialize etr\n");
return -EFAULT;
}
if (hw_data->init_admin_comms && hw_data->init_admin_comms(accel_dev)) {
dev_err(&GET_DEV(accel_dev), "Failed initialize admin comms\n");
return -EFAULT;
}
if (hw_data->init_arb && hw_data->init_arb(accel_dev)) {
dev_err(&GET_DEV(accel_dev), "Failed initialize hw arbiter\n");
return -EFAULT;
}
hw_data->enable_ints(accel_dev);
if (adf_ae_init(accel_dev)) {
pr_err("QAT: Failed to initialise Acceleration Engine\n");
return -EFAULT;
}
set_bit(ADF_STATUS_AE_INITIALISED, &accel_dev->status);
if (adf_ae_fw_load(accel_dev)) {
pr_err("QAT: Failed to load acceleration FW\n");
adf_ae_fw_release(accel_dev);
return -EFAULT;
}
set_bit(ADF_STATUS_AE_UCODE_LOADED, &accel_dev->status);
if (hw_data->alloc_irq(accel_dev)) {
pr_err("QAT: Failed to allocate interrupts\n");
return -EFAULT;
}
set_bit(ADF_STATUS_IRQ_ALLOCATED, &accel_dev->status);
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_INIT)) {
pr_err("QAT: Failed to initialise service %s\n",
service->name);
return -EFAULT;
}
set_bit(accel_dev->accel_id, &service->init_status);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_INIT)) {
pr_err("QAT: Failed to initialise service %s\n",
service->name);
return -EFAULT;
}
set_bit(accel_dev->accel_id, &service->init_status);
}
hw_data->enable_error_correction(accel_dev);
return 0;
}
int adf_dev_start(struct adf_accel_dev *accel_dev)
{
struct service_hndl *service;
struct list_head *list_itr;
set_bit(ADF_STATUS_STARTING, &accel_dev->status);
if (adf_ae_start(accel_dev)) {
pr_err("QAT: AE Start Failed\n");
return -EFAULT;
}
set_bit(ADF_STATUS_AE_STARTED, &accel_dev->status);
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_START)) {
pr_err("QAT: Failed to start service %s\n",
service->name);
return -EFAULT;
}
set_bit(accel_dev->accel_id, &service->start_status);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_START)) {
pr_err("QAT: Failed to start service %s\n",
service->name);
return -EFAULT;
}
set_bit(accel_dev->accel_id, &service->start_status);
}
clear_bit(ADF_STATUS_STARTING, &accel_dev->status);
set_bit(ADF_STATUS_STARTED, &accel_dev->status);
if (qat_algs_register()) {
pr_err("QAT: Failed to register crypto algs\n");
set_bit(ADF_STATUS_STARTING, &accel_dev->status);
clear_bit(ADF_STATUS_STARTED, &accel_dev->status);
return -EFAULT;
}
return 0;
}
int adf_dev_stop(struct adf_accel_dev *accel_dev)
{
struct service_hndl *service;
struct list_head *list_itr;
bool wait = false;
int ret;
if (!adf_dev_started(accel_dev) &&
!test_bit(ADF_STATUS_STARTING, &accel_dev->status)) {
return 0;
}
clear_bit(ADF_STATUS_STARTING, &accel_dev->status);
clear_bit(ADF_STATUS_STARTED, &accel_dev->status);
if (qat_algs_unregister())
pr_err("QAT: Failed to unregister crypto algs\n");
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (!test_bit(accel_dev->accel_id, &service->start_status))
continue;
ret = service->event_hld(accel_dev, ADF_EVENT_STOP);
if (!ret) {
clear_bit(accel_dev->accel_id, &service->start_status);
} else if (ret == -EAGAIN) {
wait = true;
clear_bit(accel_dev->accel_id, &service->start_status);
}
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (!test_bit(accel_dev->accel_id, &service->start_status))
continue;
if (service->event_hld(accel_dev, ADF_EVENT_STOP))
pr_err("QAT: Failed to shutdown service %s\n",
service->name);
else
clear_bit(accel_dev->accel_id, &service->start_status);
}
if (wait)
msleep(100);
if (test_bit(ADF_STATUS_AE_STARTED, &accel_dev->status)) {
if (adf_ae_stop(accel_dev))
pr_err("QAT: failed to stop AE\n");
else
clear_bit(ADF_STATUS_AE_STARTED, &accel_dev->status);
}
return 0;
}
void adf_dev_shutdown(struct adf_accel_dev *accel_dev)
{
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
struct service_hndl *service;
struct list_head *list_itr;
if (!hw_data) {
dev_err(&GET_DEV(accel_dev),
"QAT: Failed to shutdown device - hw_data not set\n");
return;
}
if (test_bit(ADF_STATUS_AE_UCODE_LOADED, &accel_dev->status)) {
if (adf_ae_fw_release(accel_dev))
pr_err("QAT: Failed to release the ucode\n");
else
clear_bit(ADF_STATUS_AE_UCODE_LOADED,
&accel_dev->status);
}
if (test_bit(ADF_STATUS_AE_INITIALISED, &accel_dev->status)) {
if (adf_ae_shutdown(accel_dev))
pr_err("QAT: Failed to shutdown Accel Engine\n");
else
clear_bit(ADF_STATUS_AE_INITIALISED,
&accel_dev->status);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (!test_bit(accel_dev->accel_id, &service->init_status))
continue;
if (service->event_hld(accel_dev, ADF_EVENT_SHUTDOWN))
pr_err("QAT: Failed to shutdown service %s\n",
service->name);
else
clear_bit(accel_dev->accel_id, &service->init_status);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (!test_bit(accel_dev->accel_id, &service->init_status))
continue;
if (service->event_hld(accel_dev, ADF_EVENT_SHUTDOWN))
pr_err("QAT: Failed to shutdown service %s\n",
service->name);
else
clear_bit(accel_dev->accel_id, &service->init_status);
}
if (test_bit(ADF_STATUS_IRQ_ALLOCATED, &accel_dev->status)) {
hw_data->free_irq(accel_dev);
clear_bit(ADF_STATUS_IRQ_ALLOCATED, &accel_dev->status);
}
if (!test_bit(ADF_STATUS_RESTARTING, &accel_dev->status))
adf_cfg_del_all(accel_dev);
if (hw_data->exit_arb)
hw_data->exit_arb(accel_dev);
if (hw_data->exit_admin_comms)
hw_data->exit_admin_comms(accel_dev);
adf_cleanup_etr_data(accel_dev);
}
int adf_dev_restarting_notify(struct adf_accel_dev *accel_dev)
{
struct service_hndl *service;
struct list_head *list_itr;
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_RESTARTING))
pr_err("QAT: Failed to restart service %s.\n",
service->name);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_RESTARTING))
pr_err("QAT: Failed to restart service %s.\n",
service->name);
}
return 0;
}
int adf_dev_restarted_notify(struct adf_accel_dev *accel_dev)
{
struct service_hndl *service;
struct list_head *list_itr;
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_RESTARTED))
pr_err("QAT: Failed to restart service %s.\n",
service->name);
}
list_for_each(list_itr, &service_table) {
service = list_entry(list_itr, struct service_hndl, list);
if (!service->admin)
continue;
if (service->event_hld(accel_dev, ADF_EVENT_RESTARTED))
pr_err("QAT: Failed to restart service %s.\n",
service->name);
}
return 0;
}
