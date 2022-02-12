static void adf_cleanup_accel(struct adf_accel_dev *accel_dev)
{
struct adf_accel_pci *accel_pci_dev = &accel_dev->accel_pci_dev;
int i;
adf_dev_shutdown(accel_dev);
for (i = 0; i < ADF_PCI_MAX_BARS; i++) {
struct adf_bar *bar = &accel_pci_dev->pci_bars[i];
if (bar->virt_addr)
pci_iounmap(accel_pci_dev->pci_dev, bar->virt_addr);
}
if (accel_dev->hw_device) {
switch (accel_dev->hw_device->pci_dev_id) {
case ADF_DH895XCC_PCI_DEVICE_ID:
adf_clean_hw_data_dh895xcc(accel_dev->hw_device);
break;
default:
break;
}
kfree(accel_dev->hw_device);
}
adf_cfg_dev_remove(accel_dev);
debugfs_remove(accel_dev->debugfs_dir);
adf_devmgr_rm_dev(accel_dev);
pci_release_regions(accel_pci_dev->pci_dev);
pci_disable_device(accel_pci_dev->pci_dev);
kfree(accel_dev);
}
static int adf_dev_configure(struct adf_accel_dev *accel_dev)
{
int cpus = num_online_cpus();
int banks = GET_MAX_BANKS(accel_dev);
int instances = min(cpus, banks);
char key[ADF_CFG_MAX_KEY_LEN_IN_BYTES];
int i;
unsigned long val;
if (adf_cfg_section_add(accel_dev, ADF_KERNEL_SEC))
goto err;
if (adf_cfg_section_add(accel_dev, "Accelerator0"))
goto err;
for (i = 0; i < instances; i++) {
val = i;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_BANK_NUM, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_ETRMGR_CORE_AFFINITY,
i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_ASYM_SIZE, i);
val = 128;
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 512;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_SYM_SIZE, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 0;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_ASYM_TX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 2;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_SYM_TX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 4;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_RND_TX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 8;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_ASYM_RX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 10;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_SYM_RX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = 12;
snprintf(key, sizeof(key), ADF_CY "%d" ADF_RING_RND_RX, i);
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
key, (void *)&val, ADF_DEC))
goto err;
val = ADF_COALESCING_DEF_TIME;
snprintf(key, sizeof(key), ADF_ETRMGR_COALESCE_TIMER_FORMAT, i);
if (adf_cfg_add_key_value_param(accel_dev, "Accelerator0",
key, (void *)&val, ADF_DEC))
goto err;
}
val = i;
if (adf_cfg_add_key_value_param(accel_dev, ADF_KERNEL_SEC,
ADF_NUM_CY, (void *)&val, ADF_DEC))
goto err;
set_bit(ADF_STATUS_CONFIGURED, &accel_dev->status);
return 0;
err:
dev_err(&GET_DEV(accel_dev), "Failed to start QAT accel dev\n");
return -EINVAL;
}
static int adf_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct adf_accel_dev *accel_dev;
struct adf_accel_pci *accel_pci_dev;
struct adf_hw_device_data *hw_data;
char name[ADF_DEVICE_NAME_LENGTH];
unsigned int i, bar_nr;
int ret;
switch (ent->device) {
case ADF_DH895XCC_PCI_DEVICE_ID:
break;
default:
dev_err(&pdev->dev, "Invalid device 0x%x.\n", ent->device);
return -ENODEV;
}
if (num_possible_nodes() > 1 && dev_to_node(&pdev->dev) < 0) {
dev_err(&pdev->dev, "Invalid NUMA configuration.\n");
return -EINVAL;
}
accel_dev = kzalloc_node(sizeof(*accel_dev), GFP_KERNEL,
dev_to_node(&pdev->dev));
if (!accel_dev)
return -ENOMEM;
INIT_LIST_HEAD(&accel_dev->crypto_list);
if (adf_devmgr_add_dev(accel_dev)) {
dev_err(&pdev->dev, "Failed to add new accelerator device.\n");
kfree(accel_dev);
return -EFAULT;
}
accel_dev->owner = THIS_MODULE;
hw_data = kzalloc_node(sizeof(*hw_data), GFP_KERNEL,
dev_to_node(&pdev->dev));
if (!hw_data) {
ret = -ENOMEM;
goto out_err;
}
accel_dev->hw_device = hw_data;
switch (ent->device) {
case ADF_DH895XCC_PCI_DEVICE_ID:
adf_init_hw_data_dh895xcc(accel_dev->hw_device);
break;
default:
return -ENODEV;
}
accel_pci_dev = &accel_dev->accel_pci_dev;
pci_read_config_byte(pdev, PCI_REVISION_ID, &accel_pci_dev->revid);
pci_read_config_dword(pdev, ADF_DH895XCC_FUSECTL_OFFSET,
&hw_data->fuses);
hw_data->accel_mask = hw_data->get_accel_mask(hw_data->fuses);
hw_data->ae_mask = hw_data->get_ae_mask(hw_data->fuses);
accel_pci_dev->sku = hw_data->get_sku(hw_data);
accel_pci_dev->pci_dev = pdev;
if (!hw_data->accel_mask || !hw_data->ae_mask ||
((~hw_data->ae_mask) & 0x01)) {
dev_err(&pdev->dev, "No acceleration units found");
ret = -EFAULT;
goto out_err;
}
snprintf(name, sizeof(name), "%s%s_dev%d", ADF_DEVICE_NAME_PREFIX,
hw_data->dev_class->name, hw_data->instance_id);
accel_dev->debugfs_dir = debugfs_create_dir(name, NULL);
if (!accel_dev->debugfs_dir) {
dev_err(&pdev->dev, "Could not create debugfs dir\n");
ret = -EINVAL;
goto out_err;
}
ret = adf_cfg_dev_add(accel_dev);
if (ret)
goto out_err;
if (pci_enable_device(pdev)) {
ret = -EFAULT;
goto out_err;
}
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))) {
dev_err(&pdev->dev, "No usable DMA configuration\n");
ret = -EFAULT;
goto out_err;
} else {
pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
}
} else {
pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
}
if (pci_request_regions(pdev, adf_driver_name)) {
ret = -EFAULT;
goto out_err;
}
pci_read_config_dword(pdev, ADF_DH895XCC_LEGFUSE_OFFSET,
&hw_data->accel_capabilities_mask);
for (i = 0; i < ADF_PCI_MAX_BARS; i++) {
struct adf_bar *bar = &accel_pci_dev->pci_bars[i];
bar_nr = i * 2;
bar->base_addr = pci_resource_start(pdev, bar_nr);
if (!bar->base_addr)
break;
bar->size = pci_resource_len(pdev, bar_nr);
bar->virt_addr = pci_iomap(accel_pci_dev->pci_dev, bar_nr, 0);
if (!bar->virt_addr) {
dev_err(&pdev->dev, "Failed to map BAR %d\n", i);
ret = -EFAULT;
goto out_err;
}
}
pci_set_master(pdev);
if (adf_enable_aer(accel_dev, &adf_driver)) {
dev_err(&pdev->dev, "Failed to enable aer\n");
ret = -EFAULT;
goto out_err;
}
if (pci_save_state(pdev)) {
dev_err(&pdev->dev, "Failed to save pci state\n");
ret = -ENOMEM;
goto out_err;
}
ret = adf_dev_configure(accel_dev);
if (ret)
goto out_err;
ret = adf_dev_init(accel_dev);
if (ret)
goto out_err;
ret = adf_dev_start(accel_dev);
if (ret) {
adf_dev_stop(accel_dev);
goto out_err;
}
return 0;
out_err:
adf_cleanup_accel(accel_dev);
return ret;
}
static void adf_remove(struct pci_dev *pdev)
{
struct adf_accel_dev *accel_dev = adf_devmgr_pci_to_accel_dev(pdev);
if (!accel_dev) {
pr_err("QAT: Driver removal failed\n");
return;
}
if (adf_dev_stop(accel_dev))
dev_err(&GET_DEV(accel_dev), "Failed to stop QAT accel dev\n");
adf_disable_aer(accel_dev);
adf_cleanup_accel(accel_dev);
}
static int __init adfdrv_init(void)
{
request_module("intel_qat");
if (qat_admin_register())
return -EFAULT;
if (pci_register_driver(&adf_driver)) {
pr_err("QAT: Driver initialization failed\n");
return -EFAULT;
}
return 0;
}
static void __exit adfdrv_release(void)
{
pci_unregister_driver(&adf_driver);
qat_admin_unregister();
}
