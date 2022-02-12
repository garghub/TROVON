struct cvmx_sysinfo *cvmx_sysinfo_get(void)
{
return &(state.sysinfo);
}
int cvmx_sysinfo_minimal_initialize(void *phy_mem_desc_ptr,
uint16_t board_type,
uint8_t board_rev_major,
uint8_t board_rev_minor,
uint32_t cpu_clock_hz)
{
if (state.sysinfo.board_type)
return 0;
memset(&(state.sysinfo), 0x0, sizeof(state.sysinfo));
state.sysinfo.phy_mem_desc_ptr = phy_mem_desc_ptr;
state.sysinfo.board_type = board_type;
state.sysinfo.board_rev_major = board_rev_major;
state.sysinfo.board_rev_minor = board_rev_minor;
state.sysinfo.cpu_clock_hz = cpu_clock_hz;
return 1;
}
