int adf_ae_fw_load(struct adf_accel_dev *accel_dev)
{
struct adf_fw_loader_data *loader_data = accel_dev->fw_loader;
struct adf_hw_device_data *hw_device = accel_dev->hw_device;
void *uof_addr;
uint32_t uof_size;
if (request_firmware(&loader_data->uof_fw, hw_device->fw_name,
&accel_dev->accel_pci_dev.pci_dev->dev)) {
pr_err("QAT: Failed to load firmware %s\n", hw_device->fw_name);
return -EFAULT;
}
uof_size = loader_data->uof_fw->size;
uof_addr = (void *)loader_data->uof_fw->data;
if (qat_uclo_map_uof_obj(loader_data->fw_loader, uof_addr, uof_size)) {
pr_err("QAT: Failed to map UOF\n");
goto out_err;
}
if (qat_uclo_wr_all_uimage(loader_data->fw_loader)) {
pr_err("QAT: Failed to map UOF\n");
goto out_err;
}
return 0;
out_err:
release_firmware(loader_data->uof_fw);
return -EFAULT;
}
int adf_ae_fw_release(struct adf_accel_dev *accel_dev)
{
struct adf_fw_loader_data *loader_data = accel_dev->fw_loader;
release_firmware(loader_data->uof_fw);
qat_uclo_del_uof_obj(loader_data->fw_loader);
qat_hal_deinit(loader_data->fw_loader);
loader_data->fw_loader = NULL;
return 0;
}
int adf_ae_start(struct adf_accel_dev *accel_dev)
{
struct adf_fw_loader_data *loader_data = accel_dev->fw_loader;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
uint32_t ae_ctr, ae, max_aes = GET_MAX_ACCELENGINES(accel_dev);
for (ae = 0, ae_ctr = 0; ae < max_aes; ae++) {
if (hw_data->ae_mask & (1 << ae)) {
qat_hal_start(loader_data->fw_loader, ae, 0xFF);
ae_ctr++;
}
}
pr_info("QAT: qat_dev%d started %d acceleration engines\n",
accel_dev->accel_id, ae_ctr);
return 0;
}
int adf_ae_stop(struct adf_accel_dev *accel_dev)
{
struct adf_fw_loader_data *loader_data = accel_dev->fw_loader;
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
uint32_t ae_ctr, ae, max_aes = GET_MAX_ACCELENGINES(accel_dev);
for (ae = 0, ae_ctr = 0; ae < max_aes; ae++) {
if (hw_data->ae_mask & (1 << ae)) {
qat_hal_stop(loader_data->fw_loader, ae, 0xFF);
ae_ctr++;
}
}
pr_info("QAT: qat_dev%d stopped %d acceleration engines\n",
accel_dev->accel_id, ae_ctr);
return 0;
}
static int adf_ae_reset(struct adf_accel_dev *accel_dev, int ae)
{
struct adf_fw_loader_data *loader_data = accel_dev->fw_loader;
qat_hal_reset(loader_data->fw_loader);
if (qat_hal_clr_reset(loader_data->fw_loader))
return -EFAULT;
return 0;
}
int adf_ae_init(struct adf_accel_dev *accel_dev)
{
struct adf_fw_loader_data *loader_data;
loader_data = kzalloc(sizeof(*loader_data), GFP_KERNEL);
if (!loader_data)
return -ENOMEM;
accel_dev->fw_loader = loader_data;
if (qat_hal_init(accel_dev)) {
pr_err("QAT: Failed to init the AEs\n");
kfree(loader_data);
return -EFAULT;
}
if (adf_ae_reset(accel_dev, 0)) {
pr_err("QAT: Failed to reset the AEs\n");
qat_hal_deinit(loader_data->fw_loader);
kfree(loader_data);
return -EFAULT;
}
return 0;
}
int adf_ae_shutdown(struct adf_accel_dev *accel_dev)
{
kfree(accel_dev->fw_loader);
accel_dev->fw_loader = NULL;
return 0;
}
