void isys2401_dma_set_max_burst_size(
const isys2401_dma_ID_t dma_id,
uint32_t max_burst_size)
{
assert(dma_id < N_ISYS2401_DMA_ID);
assert((max_burst_size > 0x00) && (max_burst_size <= 0xFF));
isys2401_dma_reg_store(dma_id,
DMA_DEV_INFO_REG_IDX(_DMA_V2_DEV_INTERF_MAX_BURST_IDX, HIVE_DMA_BUS_DDR_CONN),
(max_burst_size - 1));
}
