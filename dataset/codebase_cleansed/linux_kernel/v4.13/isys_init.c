input_system_error_t ia_css_isys_init(void)
{
backend_channel_cfg_t backend_ch0;
backend_channel_cfg_t backend_ch1;
target_cfg2400_t targetB;
target_cfg2400_t targetC;
uint32_t acq_mem_region_size = 24;
uint32_t acq_nof_mem_regions = 2;
input_system_error_t error = INPUT_SYSTEM_ERR_NO_ERROR;
memset(&backend_ch0, 0, sizeof(backend_channel_cfg_t));
memset(&backend_ch1, 0, sizeof(backend_channel_cfg_t));
memset(&targetB, 0, sizeof(targetB));
memset(&targetC, 0, sizeof(targetC));
error = input_system_configuration_reset();
if (error != INPUT_SYSTEM_ERR_NO_ERROR)
return error;
error = input_system_csi_xmem_channel_cfg(
0,
INPUT_SYSTEM_PORT_A,
backend_ch0,
32,
6,
acq_mem_region_size,
acq_nof_mem_regions,
targetB,
3);
if (error != INPUT_SYSTEM_ERR_NO_ERROR)
return error;
error = input_system_csi_xmem_channel_cfg(
1,
INPUT_SYSTEM_PORT_B,
backend_ch0,
16,
3,
acq_mem_region_size,
acq_nof_mem_regions,
targetB,
3);
if (error != INPUT_SYSTEM_ERR_NO_ERROR)
return error;
error = input_system_csi_xmem_channel_cfg(
2,
INPUT_SYSTEM_PORT_C,
backend_ch1,
32,
3,
acq_mem_region_size,
acq_nof_mem_regions,
targetC,
2);
if (error != INPUT_SYSTEM_ERR_NO_ERROR)
return error;
error = input_system_configuration_commit();
return error;
}
input_system_error_t ia_css_isys_init(void)
{
input_system_error_t error = INPUT_SYSTEM_ERR_NO_ERROR;
ia_css_isys_csi_rx_lut_rmgr_init();
ia_css_isys_ibuf_rmgr_init();
ia_css_isys_dma_channel_rmgr_init();
ia_css_isys_stream2mmio_sid_rmgr_init();
isys2401_dma_set_max_burst_size(ISYS2401_DMA0_ID,
1 );
isys_irqc_status_enable(ISYS_IRQ0_ID);
isys_irqc_status_enable(ISYS_IRQ1_ID);
isys_irqc_status_enable(ISYS_IRQ2_ID);
return error;
}
void ia_css_isys_uninit(void)
{
}
void ia_css_isys_uninit(void)
{
ia_css_isys_csi_rx_lut_rmgr_uninit();
ia_css_isys_ibuf_rmgr_uninit();
ia_css_isys_dma_channel_rmgr_uninit();
ia_css_isys_stream2mmio_sid_rmgr_uninit();
}
