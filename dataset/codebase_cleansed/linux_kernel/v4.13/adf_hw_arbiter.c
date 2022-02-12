int adf_init_arb(struct adf_accel_dev *accel_dev)
{
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
void __iomem *csr = accel_dev->transport->banks[0].csr_addr;
u32 arb_cfg = 0x1 << 31 | 0x4 << 4 | 0x1;
u32 arb, i;
const u32 *thd_2_arb_cfg;
for (arb = 0; arb < ADF_ARB_NUM; arb++)
WRITE_CSR_ARB_SARCONFIG(csr, arb, arb_cfg);
for (i = 0; i < hw_data->num_engines; i++)
WRITE_CSR_ARB_WQCFG(csr, i, i);
hw_data->get_arb_mapping(accel_dev, &thd_2_arb_cfg);
if (!thd_2_arb_cfg)
return -EFAULT;
for (i = 0; i < hw_data->num_engines; i++)
WRITE_CSR_ARB_WRK_2_SER_MAP(csr, i, *(thd_2_arb_cfg + i));
return 0;
}
void adf_update_ring_arb(struct adf_etr_ring_data *ring)
{
WRITE_CSR_ARB_RINGSRVARBEN(ring->bank->csr_addr,
ring->bank->bank_number,
ring->bank->ring_mask & 0xFF);
}
void adf_exit_arb(struct adf_accel_dev *accel_dev)
{
struct adf_hw_device_data *hw_data = accel_dev->hw_device;
void __iomem *csr;
unsigned int i;
if (!accel_dev->transport)
return;
csr = accel_dev->transport->banks[0].csr_addr;
for (i = 0; i < ADF_ARB_NUM; i++)
WRITE_CSR_ARB_SARCONFIG(csr, i, 0);
for (i = 0; i < hw_data->num_engines; i++)
WRITE_CSR_ARB_WQCFG(csr, i, 0);
for (i = 0; i < hw_data->num_engines; i++)
WRITE_CSR_ARB_WRK_2_SER_MAP(csr, i, 0);
for (i = 0; i < GET_MAX_BANKS(accel_dev); i++)
WRITE_CSR_ARB_RINGSRVARBEN(csr, i, 0);
}
