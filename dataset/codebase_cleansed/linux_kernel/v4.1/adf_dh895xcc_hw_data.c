static uint32_t get_accel_mask(uint32_t fuse)
{
return (~fuse) >> ADF_DH895XCC_ACCELERATORS_REG_OFFSET &
ADF_DH895XCC_ACCELERATORS_MASK;
}
static uint32_t get_ae_mask(uint32_t fuse)
{
return (~fuse) & ADF_DH895XCC_ACCELENGINES_MASK;
}
static uint32_t get_num_accels(struct adf_hw_device_data *self)
{
uint32_t i, ctr = 0;
if (!self || !self->accel_mask)
return 0;
for (i = 0; i < ADF_DH895XCC_MAX_ACCELERATORS; i++) {
if (self->accel_mask & (1 << i))
ctr++;
}
return ctr;
}
static uint32_t get_num_aes(struct adf_hw_device_data *self)
{
uint32_t i, ctr = 0;
if (!self || !self->ae_mask)
return 0;
for (i = 0; i < ADF_DH895XCC_MAX_ACCELENGINES; i++) {
if (self->ae_mask & (1 << i))
ctr++;
}
return ctr;
}
static uint32_t get_misc_bar_id(struct adf_hw_device_data *self)
{
return ADF_DH895XCC_PMISC_BAR;
}
static uint32_t get_etr_bar_id(struct adf_hw_device_data *self)
{
return ADF_DH895XCC_ETR_BAR;
}
static enum dev_sku_info get_sku(struct adf_hw_device_data *self)
{
int sku = (self->fuses & ADF_DH895XCC_FUSECTL_SKU_MASK)
>> ADF_DH895XCC_FUSECTL_SKU_SHIFT;
switch (sku) {
case ADF_DH895XCC_FUSECTL_SKU_1:
return DEV_SKU_1;
case ADF_DH895XCC_FUSECTL_SKU_2:
return DEV_SKU_2;
case ADF_DH895XCC_FUSECTL_SKU_3:
return DEV_SKU_3;
case ADF_DH895XCC_FUSECTL_SKU_4:
return DEV_SKU_4;
default:
return DEV_SKU_UNKNOWN;
}
return DEV_SKU_UNKNOWN;
}
void adf_get_arbiter_mapping(struct adf_accel_dev *accel_dev,
uint32_t const **arb_map_config)
{
switch (accel_dev->accel_pci_dev.sku) {
case DEV_SKU_1:
*arb_map_config = thrd_to_arb_map_sku4;
break;
case DEV_SKU_2:
case DEV_SKU_4:
*arb_map_config = thrd_to_arb_map_sku6;
break;
default:
dev_err(&GET_DEV(accel_dev),
"The configuration doesn't match any SKU");
*arb_map_config = NULL;
}
}
static void adf_enable_error_correction(struct adf_accel_dev *accel_dev)
{
struct adf_hw_device_data *hw_device = accel_dev->hw_device;
struct adf_bar *misc_bar = &GET_BARS(accel_dev)[ADF_DH895XCC_PMISC_BAR];
void __iomem *csr = misc_bar->virt_addr;
unsigned int val, i;
for (i = 0; i < hw_device->get_num_aes(hw_device); i++) {
val = ADF_CSR_RD(csr, ADF_DH895XCC_AE_CTX_ENABLES(i));
val |= ADF_DH895XCC_ENABLE_AE_ECC_ERR;
ADF_CSR_WR(csr, ADF_DH895XCC_AE_CTX_ENABLES(i), val);
val = ADF_CSR_RD(csr, ADF_DH895XCC_AE_MISC_CONTROL(i));
val |= ADF_DH895XCC_ENABLE_AE_ECC_PARITY_CORR;
ADF_CSR_WR(csr, ADF_DH895XCC_AE_MISC_CONTROL(i), val);
}
for (i = 0; i < hw_device->get_num_accels(hw_device); i++) {
val = ADF_CSR_RD(csr, ADF_DH895XCC_UERRSSMSH(i));
val |= ADF_DH895XCC_ERRSSMSH_EN;
ADF_CSR_WR(csr, ADF_DH895XCC_UERRSSMSH(i), val);
val = ADF_CSR_RD(csr, ADF_DH895XCC_CERRSSMSH(i));
val |= ADF_DH895XCC_ERRSSMSH_EN;
ADF_CSR_WR(csr, ADF_DH895XCC_CERRSSMSH(i), val);
}
}
static void adf_enable_ints(struct adf_accel_dev *accel_dev)
{
void __iomem *addr;
addr = (&GET_BARS(accel_dev)[ADF_DH895XCC_PMISC_BAR])->virt_addr;
ADF_CSR_WR(addr, ADF_DH895XCC_SMIAPF0_MASK_OFFSET,
ADF_DH895XCC_SMIA0_MASK);
ADF_CSR_WR(addr, ADF_DH895XCC_SMIAPF1_MASK_OFFSET,
ADF_DH895XCC_SMIA1_MASK);
}
void adf_init_hw_data_dh895xcc(struct adf_hw_device_data *hw_data)
{
hw_data->dev_class = &dh895xcc_class;
hw_data->instance_id = dh895xcc_class.instances++;
hw_data->num_banks = ADF_DH895XCC_ETR_MAX_BANKS;
hw_data->num_accel = ADF_DH895XCC_MAX_ACCELERATORS;
hw_data->pci_dev_id = ADF_DH895XCC_PCI_DEVICE_ID;
hw_data->num_logical_accel = 1;
hw_data->num_engines = ADF_DH895XCC_MAX_ACCELENGINES;
hw_data->tx_rx_gap = ADF_DH895XCC_RX_RINGS_OFFSET;
hw_data->tx_rings_mask = ADF_DH895XCC_TX_RINGS_MASK;
hw_data->alloc_irq = adf_isr_resource_alloc;
hw_data->free_irq = adf_isr_resource_free;
hw_data->enable_error_correction = adf_enable_error_correction;
hw_data->hw_arb_ring_enable = adf_update_ring_arb_enable;
hw_data->hw_arb_ring_disable = adf_update_ring_arb_enable;
hw_data->get_accel_mask = get_accel_mask;
hw_data->get_ae_mask = get_ae_mask;
hw_data->get_num_accels = get_num_accels;
hw_data->get_num_aes = get_num_aes;
hw_data->get_etr_bar_id = get_etr_bar_id;
hw_data->get_misc_bar_id = get_misc_bar_id;
hw_data->get_sku = get_sku;
hw_data->fw_name = ADF_DH895XCC_FW;
hw_data->init_admin_comms = adf_init_admin_comms;
hw_data->exit_admin_comms = adf_exit_admin_comms;
hw_data->init_arb = adf_init_arb;
hw_data->exit_arb = adf_exit_arb;
hw_data->enable_ints = adf_enable_ints;
}
void adf_clean_hw_data_dh895xcc(struct adf_hw_device_data *hw_data)
{
hw_data->dev_class->instances--;
}
