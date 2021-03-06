int read_ext_dsp_data(struct bridge_dev_context *dev_ctxt,
u8 *host_buff, u32 dsp_addr,
u32 ul_num_bytes, u32 mem_type)
{
int status = 0;
struct bridge_dev_context *dev_context = dev_ctxt;
u32 offset;
u32 ul_tlb_base_virt = 0;
u32 ul_shm_offset_virt = 0;
u32 dw_ext_prog_virt_mem;
u32 dw_base_addr = dev_context->dsp_ext_base_addr;
bool trace_read = false;
if (!ul_shm_base_virt) {
status = dev_get_symbol(dev_context->dev_obj,
SHMBASENAME, &ul_shm_base_virt);
}
DBC_ASSERT(ul_shm_base_virt != 0);
if (!status && !ul_trace_sec_beg) {
status = dev_get_symbol(dev_context->dev_obj,
DSP_TRACESEC_BEG, &ul_trace_sec_beg);
}
DBC_ASSERT(ul_trace_sec_beg != 0);
if (!status && !ul_trace_sec_end) {
status = dev_get_symbol(dev_context->dev_obj,
DSP_TRACESEC_END, &ul_trace_sec_end);
}
DBC_ASSERT(ul_trace_sec_end != 0);
if (!status) {
if ((dsp_addr <= ul_trace_sec_end) &&
(dsp_addr >= ul_trace_sec_beg))
trace_read = true;
}
if (trace_read && dw_base_addr) {
dw_base_addr = 0;
dev_context->dsp_ext_base_addr = 0;
}
if (!dw_base_addr) {
ul_ext_base = 0;
ul_ext_end = 0;
if (!status && !ul_dyn_ext_base) {
status = dev_get_symbol(dev_context->dev_obj,
DYNEXTBASE, &ul_dyn_ext_base);
}
DBC_ASSERT(ul_dyn_ext_base != 0);
if (!status) {
status = dev_get_symbol(dev_context->dev_obj,
EXTBASE, &ul_ext_base);
}
DBC_ASSERT(ul_ext_base != 0);
if (!status) {
status = dev_get_symbol(dev_context->dev_obj,
EXTEND, &ul_ext_end);
}
DBC_ASSERT(ul_ext_end != 0);
if (trace_read) {
ul_ext_base = ul_shm_base_virt;
ul_ext_end = ul_trace_sec_end;
}
DBC_ASSERT(ul_ext_end != 0);
DBC_ASSERT(ul_ext_end > ul_ext_base);
if (ul_ext_end < ul_ext_base)
status = -EPERM;
if (!status) {
ul_tlb_base_virt =
dev_context->atlb_entry[0].dsp_va * DSPWORDSIZE;
DBC_ASSERT(ul_tlb_base_virt <= ul_shm_base_virt);
dw_ext_prog_virt_mem =
dev_context->atlb_entry[0].gpp_va;
if (!trace_read) {
ul_shm_offset_virt =
ul_shm_base_virt - ul_tlb_base_virt;
ul_shm_offset_virt +=
PG_ALIGN_HIGH(ul_ext_end - ul_dyn_ext_base +
1, HW_PAGE_SIZE64KB);
dw_ext_prog_virt_mem -= ul_shm_offset_virt;
dw_ext_prog_virt_mem +=
(ul_ext_base - ul_dyn_ext_base);
dev_context->dsp_ext_base_addr =
dw_ext_prog_virt_mem;
if (!dev_context->dsp_ext_base_addr)
status = -EPERM;
}
dw_base_addr = dw_ext_prog_virt_mem;
}
}
if (!dw_base_addr || !ul_ext_base || !ul_ext_end)
status = -EPERM;
offset = dsp_addr - ul_ext_base;
if (!status)
memcpy(host_buff, (u8 *) dw_base_addr + offset, ul_num_bytes);
return status;
}
int write_dsp_data(struct bridge_dev_context *dev_context,
u8 *host_buff, u32 dsp_addr, u32 ul_num_bytes,
u32 mem_type)
{
u32 offset;
u32 dw_base_addr = dev_context->dsp_base_addr;
struct cfg_hostres *resources = dev_context->resources;
int status = 0;
u32 base1, base2, base3;
base1 = OMAP_DSP_MEM1_SIZE;
base2 = OMAP_DSP_MEM2_BASE - OMAP_DSP_MEM1_BASE;
base3 = OMAP_DSP_MEM3_BASE - OMAP_DSP_MEM1_BASE;
if (!resources)
return -EPERM;
offset = dsp_addr - dev_context->dsp_start_add;
if (offset < base1) {
dw_base_addr = MEM_LINEAR_ADDRESS(resources->mem_base[2],
resources->mem_length[2]);
} else if (offset > base1 && offset < base2 + OMAP_DSP_MEM2_SIZE) {
dw_base_addr = MEM_LINEAR_ADDRESS(resources->mem_base[3],
resources->mem_length[3]);
offset = offset - base2;
} else if (offset >= base2 + OMAP_DSP_MEM2_SIZE &&
offset < base3 + OMAP_DSP_MEM3_SIZE) {
dw_base_addr = MEM_LINEAR_ADDRESS(resources->mem_base[4],
resources->mem_length[4]);
offset = offset - base3;
} else {
return -EPERM;
}
if (ul_num_bytes)
memcpy((u8 *) (dw_base_addr + offset), host_buff, ul_num_bytes);
else
*((u32 *) host_buff) = dw_base_addr + offset;
return status;
}
int write_ext_dsp_data(struct bridge_dev_context *dev_context,
u8 *host_buff, u32 dsp_addr,
u32 ul_num_bytes, u32 mem_type,
bool dynamic_load)
{
u32 dw_base_addr = dev_context->dsp_ext_base_addr;
u32 dw_offset = 0;
u8 temp_byte1, temp_byte2;
u8 remain_byte[4];
s32 i;
int ret = 0;
u32 dw_ext_prog_virt_mem;
u32 ul_tlb_base_virt = 0;
u32 ul_shm_offset_virt = 0;
struct cfg_hostres *host_res = dev_context->resources;
bool trace_load = false;
temp_byte1 = 0x0;
temp_byte2 = 0x0;
if (symbols_reloaded) {
ret = dev_get_symbol(dev_context->dev_obj,
DSP_TRACESEC_BEG, &ul_trace_sec_beg);
if (!ret)
ret = dev_get_symbol(dev_context->dev_obj,
DSP_TRACESEC_END,
&ul_trace_sec_end);
}
if (!ret) {
if ((dsp_addr <= ul_trace_sec_end) &&
(dsp_addr >= ul_trace_sec_beg))
trace_load = true;
}
if ((dynamic_load || trace_load) && dw_base_addr) {
dw_base_addr = 0;
MEM_UNMAP_LINEAR_ADDRESS((void *)
dev_context->dsp_ext_base_addr);
dev_context->dsp_ext_base_addr = 0x0;
}
if (!dw_base_addr) {
if (symbols_reloaded)
ret = dev_get_symbol(dev_context->dev_obj,
SHMBASENAME, &ul_shm_base_virt);
DBC_ASSERT(ul_shm_base_virt != 0);
if (dynamic_load) {
if (!ret) {
if (symbols_reloaded)
ret =
dev_get_symbol
(dev_context->dev_obj, DYNEXTBASE,
&ul_ext_base);
}
DBC_ASSERT(ul_ext_base != 0);
if (!ret) {
if (symbols_reloaded)
ret =
dev_get_symbol
(dev_context->dev_obj, EXTEND,
&ul_ext_end);
}
} else {
if (symbols_reloaded) {
if (!ret)
ret =
dev_get_symbol
(dev_context->dev_obj, EXTBASE,
&ul_ext_base);
DBC_ASSERT(ul_ext_base != 0);
if (!ret)
ret =
dev_get_symbol
(dev_context->dev_obj, EXTEND,
&ul_ext_end);
}
}
if (trace_load)
ul_ext_base = ul_shm_base_virt;
DBC_ASSERT(ul_ext_end != 0);
DBC_ASSERT(ul_ext_end > ul_ext_base);
if (ul_ext_end < ul_ext_base)
ret = -EPERM;
if (!ret) {
ul_tlb_base_virt =
dev_context->atlb_entry[0].dsp_va * DSPWORDSIZE;
DBC_ASSERT(ul_tlb_base_virt <= ul_shm_base_virt);
if (symbols_reloaded) {
ret = dev_get_symbol
(dev_context->dev_obj,
DSP_TRACESEC_END, &shm0_end);
if (!ret) {
ret =
dev_get_symbol
(dev_context->dev_obj, DYNEXTBASE,
&ul_dyn_ext_base);
}
}
ul_shm_offset_virt =
ul_shm_base_virt - ul_tlb_base_virt;
if (trace_load) {
dw_ext_prog_virt_mem =
dev_context->atlb_entry[0].gpp_va;
} else {
dw_ext_prog_virt_mem = host_res->mem_base[1];
dw_ext_prog_virt_mem +=
(ul_ext_base - ul_dyn_ext_base);
}
dev_context->dsp_ext_base_addr =
(u32) MEM_LINEAR_ADDRESS((void *)
dw_ext_prog_virt_mem,
ul_ext_end - ul_ext_base);
dw_base_addr += dev_context->dsp_ext_base_addr;
if (!dev_context->dsp_ext_base_addr)
ret = -EPERM;
}
}
if (!dw_base_addr || !ul_ext_base || !ul_ext_end)
ret = -EPERM;
if (!ret) {
for (i = 0; i < 4; i++)
remain_byte[i] = 0x0;
dw_offset = dsp_addr - ul_ext_base;
if (dsp_addr > ul_ext_end || dw_offset > dsp_addr)
ret = -EPERM;
}
if (!ret) {
if (ul_num_bytes)
memcpy((u8 *) dw_base_addr + dw_offset, host_buff,
ul_num_bytes);
else
*((u32 *) host_buff) = dw_base_addr + dw_offset;
}
if ((dynamic_load || trace_load) && dev_context->dsp_ext_base_addr) {
MEM_UNMAP_LINEAR_ADDRESS((void *)
dev_context->dsp_ext_base_addr);
dev_context->dsp_ext_base_addr = 0x0;
}
symbols_reloaded = false;
return ret;
}
int sm_interrupt_dsp(struct bridge_dev_context *dev_context, u16 mb_val)
{
#ifdef CONFIG_TIDSPBRIDGE_DVFS
u32 opplevel = 0;
#endif
struct omap_dsp_platform_data *pdata =
omap_dspbridge_dev->dev.platform_data;
struct cfg_hostres *resources = dev_context->resources;
int status = 0;
u32 temp;
if (!dev_context->mbox)
return 0;
if (!resources)
return -EPERM;
if (dev_context->brd_state == BRD_DSP_HIBERNATION ||
dev_context->brd_state == BRD_HIBERNATION) {
#ifdef CONFIG_TIDSPBRIDGE_DVFS
if (pdata->dsp_get_opp)
opplevel = (*pdata->dsp_get_opp) ();
if (opplevel == VDD1_OPP1) {
if (pdata->dsp_set_min_opp)
(*pdata->dsp_set_min_opp) (VDD1_OPP2);
}
#endif
dsp_clock_enable_all(dev_context->dsp_per_clks);
dsp_wdt_enable(true);
(*pdata->dsp_cm_write)(1 << OMAP3430_AUTO_IVA2_DPLL_SHIFT,
OMAP3430_IVA2_MOD, OMAP3430_CM_AUTOIDLE_PLL);
(*pdata->dsp_cm_rmw_bits)(OMAP3430_IVA2_DPLL_FREQSEL_MASK |
OMAP3430_EN_IVA2_DPLL_MASK,
0x3 << OMAP3430_IVA2_DPLL_FREQSEL_SHIFT |
0x7 << OMAP3430_EN_IVA2_DPLL_SHIFT,
OMAP3430_IVA2_MOD, OMAP3430_CM_CLKEN_PLL);
omap_mbox_restore_ctx(dev_context->mbox);
temp = readl(resources->dmmu_base + 0x10);
dev_context->brd_state = BRD_RUNNING;
} else if (dev_context->brd_state == BRD_RETENTION) {
dsp_clock_enable_all(dev_context->dsp_per_clks);
}
status = omap_mbox_msg_send(dev_context->mbox, mb_val);
if (status) {
pr_err("omap_mbox_msg_send Fail and status = %d\n", status);
status = -EPERM;
}
return 0;
}
