enum ia_css_err ia_css_spctrl_load_fw(sp_ID_t sp_id,
ia_css_spctrl_cfg *spctrl_cfg)
{
hrt_vaddress code_addr = mmgr_NULL;
struct ia_css_sp_init_dmem_cfg *init_dmem_cfg;
if ((sp_id >= N_SP_ID) || (spctrl_cfg == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
spctrl_cofig_info[sp_id].code_addr = mmgr_NULL;
init_dmem_cfg = &spctrl_cofig_info[sp_id].dmem_config;
init_dmem_cfg->dmem_data_addr = spctrl_cfg->dmem_data_addr;
init_dmem_cfg->dmem_bss_addr = spctrl_cfg->dmem_bss_addr;
init_dmem_cfg->data_size = spctrl_cfg->data_size;
init_dmem_cfg->bss_size = spctrl_cfg->bss_size;
init_dmem_cfg->sp_id = sp_id;
spctrl_cofig_info[sp_id].spctrl_config_dmem_addr = spctrl_cfg->spctrl_config_dmem_addr;
spctrl_cofig_info[sp_id].spctrl_state_dmem_addr = spctrl_cfg->spctrl_state_dmem_addr;
code_addr = mmgr_malloc(spctrl_cfg->code_size);
if (code_addr == mmgr_NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
mmgr_store(code_addr, spctrl_cfg->code, spctrl_cfg->code_size);
if (sizeof(hrt_vaddress) > sizeof(hrt_data)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"size of hrt_vaddress can not be greater than hrt_data\n");
hmm_free(code_addr);
code_addr = mmgr_NULL;
return IA_CSS_ERR_INTERNAL_ERROR;
}
init_dmem_cfg->ddr_data_addr = code_addr + spctrl_cfg->ddr_data_offset;
if ((init_dmem_cfg->ddr_data_addr % HIVE_ISP_DDR_WORD_BYTES) != 0) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"DDR address pointer is not properly aligned for DMA transfer\n");
hmm_free(code_addr);
code_addr = mmgr_NULL;
return IA_CSS_ERR_INTERNAL_ERROR;
}
spctrl_cofig_info[sp_id].sp_entry = spctrl_cfg->sp_entry;
spctrl_cofig_info[sp_id].code_addr = code_addr;
spctrl_cofig_info[sp_id].program_name = spctrl_cfg->program_name;
sp_ctrl_store(sp_id, SP_ICACHE_ADDR_REG, (hrt_data)spctrl_cofig_info[sp_id].code_addr);
sp_ctrl_setbit(sp_id, SP_ICACHE_INV_REG, SP_ICACHE_INV_BIT);
spctrl_loaded[sp_id] = true;
return IA_CSS_SUCCESS;
}
void sh_css_spctrl_reload_fw(sp_ID_t sp_id)
{
sp_ctrl_store(sp_id, SP_ICACHE_ADDR_REG, (hrt_data)spctrl_cofig_info[sp_id].code_addr);
sp_ctrl_setbit(sp_id, SP_ICACHE_INV_REG, SP_ICACHE_INV_BIT);
spctrl_loaded[sp_id] = true;
}
hrt_vaddress get_sp_code_addr(sp_ID_t sp_id)
{
return spctrl_cofig_info[sp_id].code_addr;
}
enum ia_css_err ia_css_spctrl_unload_fw(sp_ID_t sp_id)
{
if ((sp_id >= N_SP_ID) || ((sp_id < N_SP_ID) && (!spctrl_loaded[sp_id])))
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (spctrl_cofig_info[sp_id].code_addr)
hmm_free(spctrl_cofig_info[sp_id].code_addr);
spctrl_loaded[sp_id] = false;
return IA_CSS_SUCCESS;
}
enum ia_css_err ia_css_spctrl_start(sp_ID_t sp_id)
{
if ((sp_id >= N_SP_ID) || ((sp_id < N_SP_ID) && (!spctrl_loaded[sp_id])))
return IA_CSS_ERR_INVALID_ARGUMENTS;
assert(sizeof(unsigned int) <= sizeof(hrt_data));
sp_dmem_store(sp_id,
spctrl_cofig_info[sp_id].spctrl_config_dmem_addr,
&spctrl_cofig_info[sp_id].dmem_config,
sizeof(spctrl_cofig_info[sp_id].dmem_config));
sp_ctrl_store(sp_id, SP_START_ADDR_REG, (hrt_data)spctrl_cofig_info[sp_id].sp_entry);
sp_ctrl_setbit(sp_id, SP_SC_REG, SP_RUN_BIT);
sp_ctrl_setbit(sp_id, SP_SC_REG, SP_START_BIT);
return IA_CSS_SUCCESS;
}
ia_css_spctrl_sp_sw_state ia_css_spctrl_get_state(sp_ID_t sp_id)
{
ia_css_spctrl_sp_sw_state state = 0;
unsigned int HIVE_ADDR_sp_sw_state;
if (sp_id >= N_SP_ID)
return IA_CSS_SP_SW_TERMINATED;
HIVE_ADDR_sp_sw_state = spctrl_cofig_info[sp_id].spctrl_state_dmem_addr;
(void)HIVE_ADDR_sp_sw_state;
if (sp_id == SP0_ID)
state = sp_dmem_load_uint32(sp_id, (unsigned)sp_address_of(sp_sw_state));
return state;
}
int ia_css_spctrl_is_idle(sp_ID_t sp_id)
{
int state = 0;
assert (sp_id < N_SP_ID);
state = sp_ctrl_getbit(sp_id, SP_SC_REG, SP_IDLE_BIT);
return state;
}
