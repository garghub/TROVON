void debug_buffer_init(const hrt_address addr)
{
debug_buffer_address = addr;
debug_data.head = 0;
debug_data.tail = 0;
}
void debug_buffer_ddr_init(const hrt_vaddress addr)
{
debug_buf_mode_t mode = DEBUG_BUFFER_MODE_LINEAR;
uint32_t enable = 1;
uint32_t head = 0;
uint32_t tail = 0;
debug_buffer_ddr_address = addr;
mmgr_store(addr + DEBUG_DATA_BUF_MODE_DDR_ADDR,
&mode, sizeof(debug_buf_mode_t));
mmgr_store(addr + DEBUG_DATA_HEAD_DDR_ADDR,
&head, sizeof(uint32_t));
mmgr_store(addr + DEBUG_DATA_TAIL_DDR_ADDR,
&tail, sizeof(uint32_t));
mmgr_store(addr + DEBUG_DATA_ENABLE_DDR_ADDR,
&enable, sizeof(uint32_t));
debug_data.head = 0;
debug_data.tail = 0;
}
void debug_buffer_setmode(const debug_buf_mode_t mode)
{
assert(debug_buffer_address != ((hrt_address)-1));
sp_dmem_store_uint32(SP0_ID,
debug_buffer_address + DEBUG_DATA_BUF_MODE_ADDR, mode);
}
