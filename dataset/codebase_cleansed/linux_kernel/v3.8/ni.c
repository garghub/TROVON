int ni_mc_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
u32 mem_type, running, blackout = 0;
u32 *io_mc_regs;
int i, ucode_size, regs_size;
if (!rdev->mc_fw)
return -EINVAL;
switch (rdev->family) {
case CHIP_BARTS:
io_mc_regs = (u32 *)&barts_io_mc_regs;
ucode_size = BTC_MC_UCODE_SIZE;
regs_size = BTC_IO_MC_REGS_SIZE;
break;
case CHIP_TURKS:
io_mc_regs = (u32 *)&turks_io_mc_regs;
ucode_size = BTC_MC_UCODE_SIZE;
regs_size = BTC_IO_MC_REGS_SIZE;
break;
case CHIP_CAICOS:
default:
io_mc_regs = (u32 *)&caicos_io_mc_regs;
ucode_size = BTC_MC_UCODE_SIZE;
regs_size = BTC_IO_MC_REGS_SIZE;
break;
case CHIP_CAYMAN:
io_mc_regs = (u32 *)&cayman_io_mc_regs;
ucode_size = CAYMAN_MC_UCODE_SIZE;
regs_size = BTC_IO_MC_REGS_SIZE;
break;
}
mem_type = (RREG32(MC_SEQ_MISC0) & MC_SEQ_MISC0_GDDR5_MASK) >> MC_SEQ_MISC0_GDDR5_SHIFT;
running = RREG32(MC_SEQ_SUP_CNTL) & RUN_MASK;
if ((mem_type == MC_SEQ_MISC0_GDDR5_VALUE) && (running == 0)) {
if (running) {
blackout = RREG32(MC_SHARED_BLACKOUT_CNTL);
WREG32(MC_SHARED_BLACKOUT_CNTL, 1);
}
WREG32(MC_SEQ_SUP_CNTL, 0x00000008);
WREG32(MC_SEQ_SUP_CNTL, 0x00000010);
for (i = 0; i < regs_size; i++) {
WREG32(MC_SEQ_IO_DEBUG_INDEX, io_mc_regs[(i << 1)]);
WREG32(MC_SEQ_IO_DEBUG_DATA, io_mc_regs[(i << 1) + 1]);
}
fw_data = (const __be32 *)rdev->mc_fw->data;
for (i = 0; i < ucode_size; i++)
WREG32(MC_SEQ_SUP_PGM, be32_to_cpup(fw_data++));
WREG32(MC_SEQ_SUP_CNTL, 0x00000008);
WREG32(MC_SEQ_SUP_CNTL, 0x00000004);
WREG32(MC_SEQ_SUP_CNTL, 0x00000001);
for (i = 0; i < rdev->usec_timeout; i++) {
if (RREG32(MC_IO_PAD_CNTL_D0) & MEM_FALL_OUT_CMD)
break;
udelay(1);
}
if (running)
WREG32(MC_SHARED_BLACKOUT_CNTL, blackout);
}
return 0;
}
int ni_init_microcode(struct radeon_device *rdev)
{
struct platform_device *pdev;
const char *chip_name;
const char *rlc_chip_name;
size_t pfp_req_size, me_req_size, rlc_req_size, mc_req_size;
char fw_name[30];
int err;
DRM_DEBUG("\n");
pdev = platform_device_register_simple("radeon_cp", 0, NULL, 0);
err = IS_ERR(pdev);
if (err) {
printk(KERN_ERR "radeon_cp: Failed to register firmware\n");
return -EINVAL;
}
switch (rdev->family) {
case CHIP_BARTS:
chip_name = "BARTS";
rlc_chip_name = "BTC";
pfp_req_size = EVERGREEN_PFP_UCODE_SIZE * 4;
me_req_size = EVERGREEN_PM4_UCODE_SIZE * 4;
rlc_req_size = EVERGREEN_RLC_UCODE_SIZE * 4;
mc_req_size = BTC_MC_UCODE_SIZE * 4;
break;
case CHIP_TURKS:
chip_name = "TURKS";
rlc_chip_name = "BTC";
pfp_req_size = EVERGREEN_PFP_UCODE_SIZE * 4;
me_req_size = EVERGREEN_PM4_UCODE_SIZE * 4;
rlc_req_size = EVERGREEN_RLC_UCODE_SIZE * 4;
mc_req_size = BTC_MC_UCODE_SIZE * 4;
break;
case CHIP_CAICOS:
chip_name = "CAICOS";
rlc_chip_name = "BTC";
pfp_req_size = EVERGREEN_PFP_UCODE_SIZE * 4;
me_req_size = EVERGREEN_PM4_UCODE_SIZE * 4;
rlc_req_size = EVERGREEN_RLC_UCODE_SIZE * 4;
mc_req_size = BTC_MC_UCODE_SIZE * 4;
break;
case CHIP_CAYMAN:
chip_name = "CAYMAN";
rlc_chip_name = "CAYMAN";
pfp_req_size = CAYMAN_PFP_UCODE_SIZE * 4;
me_req_size = CAYMAN_PM4_UCODE_SIZE * 4;
rlc_req_size = CAYMAN_RLC_UCODE_SIZE * 4;
mc_req_size = CAYMAN_MC_UCODE_SIZE * 4;
break;
case CHIP_ARUBA:
chip_name = "ARUBA";
rlc_chip_name = "ARUBA";
pfp_req_size = CAYMAN_PFP_UCODE_SIZE * 4;
me_req_size = CAYMAN_PM4_UCODE_SIZE * 4;
rlc_req_size = ARUBA_RLC_UCODE_SIZE * 4;
mc_req_size = 0;
break;
default: BUG();
}
DRM_INFO("Loading %s Microcode\n", chip_name);
snprintf(fw_name, sizeof(fw_name), "radeon/%s_pfp.bin", chip_name);
err = request_firmware(&rdev->pfp_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->pfp_fw->size != pfp_req_size) {
printk(KERN_ERR
"ni_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->pfp_fw->size, fw_name);
err = -EINVAL;
goto out;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_me.bin", chip_name);
err = request_firmware(&rdev->me_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->me_fw->size != me_req_size) {
printk(KERN_ERR
"ni_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->me_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_rlc.bin", rlc_chip_name);
err = request_firmware(&rdev->rlc_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->rlc_fw->size != rlc_req_size) {
printk(KERN_ERR
"ni_rlc: Bogus length %zu in firmware \"%s\"\n",
rdev->rlc_fw->size, fw_name);
err = -EINVAL;
}
if (!(rdev->flags & RADEON_IS_IGP)) {
snprintf(fw_name, sizeof(fw_name), "radeon/%s_mc.bin", chip_name);
err = request_firmware(&rdev->mc_fw, fw_name, &pdev->dev);
if (err)
goto out;
if (rdev->mc_fw->size != mc_req_size) {
printk(KERN_ERR
"ni_mc: Bogus length %zu in firmware \"%s\"\n",
rdev->mc_fw->size, fw_name);
err = -EINVAL;
}
}
out:
platform_device_unregister(pdev);
if (err) {
if (err != -EINVAL)
printk(KERN_ERR
"ni_cp: Failed to load firmware \"%s\"\n",
fw_name);
release_firmware(rdev->pfp_fw);
rdev->pfp_fw = NULL;
release_firmware(rdev->me_fw);
rdev->me_fw = NULL;
release_firmware(rdev->rlc_fw);
rdev->rlc_fw = NULL;
release_firmware(rdev->mc_fw);
rdev->mc_fw = NULL;
}
return err;
}
static void cayman_gpu_init(struct radeon_device *rdev)
{
u32 gb_addr_config = 0;
u32 mc_shared_chmap, mc_arb_ramcfg;
u32 cgts_tcc_disable;
u32 sx_debug_1;
u32 smx_dc_ctl0;
u32 cgts_sm_ctrl_reg;
u32 hdp_host_path_cntl;
u32 tmp;
u32 disabled_rb_mask;
int i, j;
switch (rdev->family) {
case CHIP_CAYMAN:
rdev->config.cayman.max_shader_engines = 2;
rdev->config.cayman.max_pipes_per_simd = 4;
rdev->config.cayman.max_tile_pipes = 8;
rdev->config.cayman.max_simds_per_se = 12;
rdev->config.cayman.max_backends_per_se = 4;
rdev->config.cayman.max_texture_channel_caches = 8;
rdev->config.cayman.max_gprs = 256;
rdev->config.cayman.max_threads = 256;
rdev->config.cayman.max_gs_threads = 32;
rdev->config.cayman.max_stack_entries = 512;
rdev->config.cayman.sx_num_of_sets = 8;
rdev->config.cayman.sx_max_export_size = 256;
rdev->config.cayman.sx_max_export_pos_size = 64;
rdev->config.cayman.sx_max_export_smx_size = 192;
rdev->config.cayman.max_hw_contexts = 8;
rdev->config.cayman.sq_num_cf_insts = 2;
rdev->config.cayman.sc_prim_fifo_size = 0x100;
rdev->config.cayman.sc_hiz_tile_fifo_size = 0x30;
rdev->config.cayman.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = CAYMAN_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_ARUBA:
default:
rdev->config.cayman.max_shader_engines = 1;
rdev->config.cayman.max_pipes_per_simd = 4;
rdev->config.cayman.max_tile_pipes = 2;
if ((rdev->pdev->device == 0x9900) ||
(rdev->pdev->device == 0x9901) ||
(rdev->pdev->device == 0x9905) ||
(rdev->pdev->device == 0x9906) ||
(rdev->pdev->device == 0x9907) ||
(rdev->pdev->device == 0x9908) ||
(rdev->pdev->device == 0x9909) ||
(rdev->pdev->device == 0x9910) ||
(rdev->pdev->device == 0x9917)) {
rdev->config.cayman.max_simds_per_se = 6;
rdev->config.cayman.max_backends_per_se = 2;
} else if ((rdev->pdev->device == 0x9903) ||
(rdev->pdev->device == 0x9904) ||
(rdev->pdev->device == 0x990A) ||
(rdev->pdev->device == 0x9913) ||
(rdev->pdev->device == 0x9918)) {
rdev->config.cayman.max_simds_per_se = 4;
rdev->config.cayman.max_backends_per_se = 2;
} else if ((rdev->pdev->device == 0x9919) ||
(rdev->pdev->device == 0x9990) ||
(rdev->pdev->device == 0x9991) ||
(rdev->pdev->device == 0x9994) ||
(rdev->pdev->device == 0x99A0)) {
rdev->config.cayman.max_simds_per_se = 3;
rdev->config.cayman.max_backends_per_se = 1;
} else {
rdev->config.cayman.max_simds_per_se = 2;
rdev->config.cayman.max_backends_per_se = 1;
}
rdev->config.cayman.max_texture_channel_caches = 2;
rdev->config.cayman.max_gprs = 256;
rdev->config.cayman.max_threads = 256;
rdev->config.cayman.max_gs_threads = 32;
rdev->config.cayman.max_stack_entries = 512;
rdev->config.cayman.sx_num_of_sets = 8;
rdev->config.cayman.sx_max_export_size = 256;
rdev->config.cayman.sx_max_export_pos_size = 64;
rdev->config.cayman.sx_max_export_smx_size = 192;
rdev->config.cayman.max_hw_contexts = 8;
rdev->config.cayman.sq_num_cf_insts = 2;
rdev->config.cayman.sc_prim_fifo_size = 0x40;
rdev->config.cayman.sc_hiz_tile_fifo_size = 0x30;
rdev->config.cayman.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = ARUBA_GB_ADDR_CONFIG_GOLDEN;
break;
}
for (i = 0, j = 0; i < 32; i++, j += 0x18) {
WREG32((0x2c14 + j), 0x00000000);
WREG32((0x2c18 + j), 0x00000000);
WREG32((0x2c1c + j), 0x00000000);
WREG32((0x2c20 + j), 0x00000000);
WREG32((0x2c24 + j), 0x00000000);
}
WREG32(GRBM_CNTL, GRBM_READ_TIMEOUT(0xff));
evergreen_fix_pci_max_read_req_size(rdev);
mc_shared_chmap = RREG32(MC_SHARED_CHMAP);
mc_arb_ramcfg = RREG32(MC_ARB_RAMCFG);
tmp = (mc_arb_ramcfg & NOOFCOLS_MASK) >> NOOFCOLS_SHIFT;
rdev->config.cayman.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
if (rdev->config.cayman.mem_row_size_in_kb > 4)
rdev->config.cayman.mem_row_size_in_kb = 4;
rdev->config.cayman.shader_engine_tile_size = 32;
rdev->config.cayman.num_gpus = 1;
rdev->config.cayman.multi_gpu_tile_size = 64;
tmp = (gb_addr_config & NUM_PIPES_MASK) >> NUM_PIPES_SHIFT;
rdev->config.cayman.num_tile_pipes = (1 << tmp);
tmp = (gb_addr_config & PIPE_INTERLEAVE_SIZE_MASK) >> PIPE_INTERLEAVE_SIZE_SHIFT;
rdev->config.cayman.mem_max_burst_length_bytes = (tmp + 1) * 256;
tmp = (gb_addr_config & NUM_SHADER_ENGINES_MASK) >> NUM_SHADER_ENGINES_SHIFT;
rdev->config.cayman.num_shader_engines = tmp + 1;
tmp = (gb_addr_config & NUM_GPUS_MASK) >> NUM_GPUS_SHIFT;
rdev->config.cayman.num_gpus = tmp + 1;
tmp = (gb_addr_config & MULTI_GPU_TILE_SIZE_MASK) >> MULTI_GPU_TILE_SIZE_SHIFT;
rdev->config.cayman.multi_gpu_tile_size = 1 << tmp;
tmp = (gb_addr_config & ROW_SIZE_MASK) >> ROW_SIZE_SHIFT;
rdev->config.cayman.mem_row_size_in_kb = 1 << tmp;
rdev->config.cayman.tile_config = 0;
switch (rdev->config.cayman.num_tile_pipes) {
case 1:
default:
rdev->config.cayman.tile_config |= (0 << 0);
break;
case 2:
rdev->config.cayman.tile_config |= (1 << 0);
break;
case 4:
rdev->config.cayman.tile_config |= (2 << 0);
break;
case 8:
rdev->config.cayman.tile_config |= (3 << 0);
break;
}
if (rdev->flags & RADEON_IS_IGP)
rdev->config.cayman.tile_config |= 1 << 4;
else {
switch ((mc_arb_ramcfg & NOOFBANK_MASK) >> NOOFBANK_SHIFT) {
case 0:
rdev->config.cayman.tile_config |= 0 << 4;
break;
case 1:
rdev->config.cayman.tile_config |= 1 << 4;
break;
case 2:
default:
rdev->config.cayman.tile_config |= 2 << 4;
break;
}
}
rdev->config.cayman.tile_config |=
((gb_addr_config & PIPE_INTERLEAVE_SIZE_MASK) >> PIPE_INTERLEAVE_SIZE_SHIFT) << 8;
rdev->config.cayman.tile_config |=
((gb_addr_config & ROW_SIZE_MASK) >> ROW_SIZE_SHIFT) << 12;
tmp = 0;
for (i = (rdev->config.cayman.max_shader_engines - 1); i >= 0; i--) {
u32 rb_disable_bitmap;
WREG32(GRBM_GFX_INDEX, INSTANCE_BROADCAST_WRITES | SE_INDEX(i));
WREG32(RLC_GFX_INDEX, INSTANCE_BROADCAST_WRITES | SE_INDEX(i));
rb_disable_bitmap = (RREG32(CC_RB_BACKEND_DISABLE) & 0x00ff0000) >> 16;
tmp <<= 4;
tmp |= rb_disable_bitmap;
}
disabled_rb_mask = tmp;
WREG32(GRBM_GFX_INDEX, INSTANCE_BROADCAST_WRITES | SE_BROADCAST_WRITES);
WREG32(RLC_GFX_INDEX, INSTANCE_BROADCAST_WRITES | SE_BROADCAST_WRITES);
WREG32(GB_ADDR_CONFIG, gb_addr_config);
WREG32(DMIF_ADDR_CONFIG, gb_addr_config);
WREG32(HDP_ADDR_CONFIG, gb_addr_config);
WREG32(DMA_TILING_CONFIG + DMA0_REGISTER_OFFSET, gb_addr_config);
WREG32(DMA_TILING_CONFIG + DMA1_REGISTER_OFFSET, gb_addr_config);
tmp = gb_addr_config & NUM_PIPES_MASK;
tmp = r6xx_remap_render_backend(rdev, tmp,
rdev->config.cayman.max_backends_per_se *
rdev->config.cayman.max_shader_engines,
CAYMAN_MAX_BACKENDS, disabled_rb_mask);
WREG32(GB_BACKEND_MAP, tmp);
cgts_tcc_disable = 0xffff0000;
for (i = 0; i < rdev->config.cayman.max_texture_channel_caches; i++)
cgts_tcc_disable &= ~(1 << (16 + i));
WREG32(CGTS_TCC_DISABLE, cgts_tcc_disable);
WREG32(CGTS_SYS_TCC_DISABLE, cgts_tcc_disable);
WREG32(CGTS_USER_SYS_TCC_DISABLE, cgts_tcc_disable);
WREG32(CGTS_USER_TCC_DISABLE, cgts_tcc_disable);
cgts_sm_ctrl_reg = RREG32(CGTS_SM_CTRL_REG);
for (i = 0; i < 16; i++)
WREG32(CGTS_SM_CTRL_REG, OVERRIDE);
WREG32(CGTS_SM_CTRL_REG, cgts_sm_ctrl_reg);
WREG32(CP_MEQ_THRESHOLDS, MEQ1_START(0x30) | MEQ2_START(0x60));
sx_debug_1 = RREG32(SX_DEBUG_1);
sx_debug_1 |= ENABLE_NEW_SMX_ADDRESS;
WREG32(SX_DEBUG_1, sx_debug_1);
smx_dc_ctl0 = RREG32(SMX_DC_CTL0);
smx_dc_ctl0 &= ~NUMBER_OF_SETS(0x1ff);
smx_dc_ctl0 |= NUMBER_OF_SETS(rdev->config.cayman.sx_num_of_sets);
WREG32(SMX_DC_CTL0, smx_dc_ctl0);
WREG32(SPI_CONFIG_CNTL_1, VTX_DONE_DELAY(4) | CRC_SIMD_ID_WADDR_DISABLE);
WREG32(VGT_OFFCHIP_LDS_BASE, 0);
WREG32(SQ_LSTMP_RING_BASE, 0);
WREG32(SQ_HSTMP_RING_BASE, 0);
WREG32(SQ_ESTMP_RING_BASE, 0);
WREG32(SQ_GSTMP_RING_BASE, 0);
WREG32(SQ_VSTMP_RING_BASE, 0);
WREG32(SQ_PSTMP_RING_BASE, 0);
WREG32(TA_CNTL_AUX, DISABLE_CUBE_ANISO);
WREG32(SX_EXPORT_BUFFER_SIZES, (COLOR_BUFFER_SIZE((rdev->config.cayman.sx_max_export_size / 4) - 1) |
POSITION_BUFFER_SIZE((rdev->config.cayman.sx_max_export_pos_size / 4) - 1) |
SMX_BUFFER_SIZE((rdev->config.cayman.sx_max_export_smx_size / 4) - 1)));
WREG32(PA_SC_FIFO_SIZE, (SC_PRIM_FIFO_SIZE(rdev->config.cayman.sc_prim_fifo_size) |
SC_HIZ_TILE_FIFO_SIZE(rdev->config.cayman.sc_hiz_tile_fifo_size) |
SC_EARLYZ_TILE_FIFO_SIZE(rdev->config.cayman.sc_earlyz_tile_fifo_size)));
WREG32(VGT_NUM_INSTANCES, 1);
WREG32(CP_PERFMON_CNTL, 0);
WREG32(SQ_MS_FIFO_SIZES, (CACHE_FIFO_SIZE(16 * rdev->config.cayman.sq_num_cf_insts) |
FETCH_FIFO_HIWATER(0x4) |
DONE_FIFO_HIWATER(0xe0) |
ALU_UPDATE_FIFO_HIWATER(0x8)));
WREG32(SQ_GPR_RESOURCE_MGMT_1, NUM_CLAUSE_TEMP_GPRS(4));
WREG32(SQ_CONFIG, (VC_ENABLE |
EXPORT_SRC_C |
GFX_PRIO(0) |
CS1_PRIO(0) |
CS2_PRIO(1)));
WREG32(SQ_DYN_GPR_CNTL_PS_FLUSH_REQ, DYN_GPR_ENABLE);
WREG32(PA_SC_FORCE_EOV_MAX_CNTS, (FORCE_EOV_MAX_CLK_CNT(4095) |
FORCE_EOV_MAX_REZ_CNT(255)));
WREG32(VGT_CACHE_INVALIDATION, CACHE_INVALIDATION(VC_AND_TC) |
AUTO_INVLD_EN(ES_AND_GS_AUTO));
WREG32(VGT_GS_VERTEX_REUSE, 16);
WREG32(PA_SC_LINE_STIPPLE_STATE, 0);
WREG32(CB_PERF_CTR0_SEL_0, 0);
WREG32(CB_PERF_CTR0_SEL_1, 0);
WREG32(CB_PERF_CTR1_SEL_0, 0);
WREG32(CB_PERF_CTR1_SEL_1, 0);
WREG32(CB_PERF_CTR2_SEL_0, 0);
WREG32(CB_PERF_CTR2_SEL_1, 0);
WREG32(CB_PERF_CTR3_SEL_0, 0);
WREG32(CB_PERF_CTR3_SEL_1, 0);
tmp = RREG32(HDP_MISC_CNTL);
tmp |= HDP_FLUSH_INVALIDATE_CACHE;
WREG32(HDP_MISC_CNTL, tmp);
hdp_host_path_cntl = RREG32(HDP_HOST_PATH_CNTL);
WREG32(HDP_HOST_PATH_CNTL, hdp_host_path_cntl);
WREG32(PA_CL_ENHANCE, CLIP_VTX_REORDER_ENA | NUM_CLIP_SEQ(3));
udelay(50);
}
void cayman_pcie_gart_tlb_flush(struct radeon_device *rdev)
{
WREG32(HDP_MEM_COHERENCY_FLUSH_CNTL, 0x1);
WREG32(VM_INVALIDATE_REQUEST, 1);
}
static int cayman_pcie_gart_enable(struct radeon_device *rdev)
{
int i, r;
if (rdev->gart.robj == NULL) {
dev_err(rdev->dev, "No VRAM object for PCIE GART.\n");
return -EINVAL;
}
r = radeon_gart_table_vram_pin(rdev);
if (r)
return r;
radeon_gart_restore(rdev);
WREG32(MC_VM_MX_L1_TLB_CNTL,
(0xA << 7) |
ENABLE_L1_TLB |
ENABLE_L1_FRAGMENT_PROCESSING |
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
ENABLE_ADVANCED_DRIVER_MODEL |
SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU);
WREG32(VM_L2_CNTL, ENABLE_L2_CACHE |
ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
ENABLE_L2_PDE0_CACHE_LRU_UPDATE_BY_WRITE |
EFFECTIVE_L2_QUEUE_SIZE(7) |
CONTEXT1_IDENTITY_ACCESS_MODE(1));
WREG32(VM_L2_CNTL2, INVALIDATE_ALL_L1_TLBS | INVALIDATE_L2_CACHE);
WREG32(VM_L2_CNTL3, L2_CACHE_BIGK_ASSOCIATIVITY |
L2_CACHE_BIGK_FRAGMENT_SIZE(6));
WREG32(VM_CONTEXT0_PAGE_TABLE_START_ADDR, rdev->mc.gtt_start >> 12);
WREG32(VM_CONTEXT0_PAGE_TABLE_END_ADDR, rdev->mc.gtt_end >> 12);
WREG32(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR, rdev->gart.table_addr >> 12);
WREG32(VM_CONTEXT0_PROTECTION_FAULT_DEFAULT_ADDR,
(u32)(rdev->dummy_page.addr >> 12));
WREG32(VM_CONTEXT0_CNTL2, 0);
WREG32(VM_CONTEXT0_CNTL, ENABLE_CONTEXT | PAGE_TABLE_DEPTH(0) |
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT);
WREG32(0x15D4, 0);
WREG32(0x15D8, 0);
WREG32(0x15DC, 0);
for (i = 1; i < 8; i++) {
WREG32(VM_CONTEXT0_PAGE_TABLE_START_ADDR + (i << 2), 0);
WREG32(VM_CONTEXT0_PAGE_TABLE_END_ADDR + (i << 2), rdev->vm_manager.max_pfn);
WREG32(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (i << 2),
rdev->gart.table_addr >> 12);
}
WREG32(VM_CONTEXT1_PROTECTION_FAULT_DEFAULT_ADDR,
(u32)(rdev->dummy_page.addr >> 12));
WREG32(VM_CONTEXT1_CNTL2, 4);
WREG32(VM_CONTEXT1_CNTL, ENABLE_CONTEXT | PAGE_TABLE_DEPTH(1) |
RANGE_PROTECTION_FAULT_ENABLE_INTERRUPT |
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT |
DUMMY_PAGE_PROTECTION_FAULT_ENABLE_INTERRUPT |
DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT |
PDE0_PROTECTION_FAULT_ENABLE_INTERRUPT |
PDE0_PROTECTION_FAULT_ENABLE_DEFAULT |
VALID_PROTECTION_FAULT_ENABLE_INTERRUPT |
VALID_PROTECTION_FAULT_ENABLE_DEFAULT |
READ_PROTECTION_FAULT_ENABLE_INTERRUPT |
READ_PROTECTION_FAULT_ENABLE_DEFAULT |
WRITE_PROTECTION_FAULT_ENABLE_INTERRUPT |
WRITE_PROTECTION_FAULT_ENABLE_DEFAULT);
cayman_pcie_gart_tlb_flush(rdev);
DRM_INFO("PCIE GART of %uM enabled (table at 0x%016llX).\n",
(unsigned)(rdev->mc.gtt_size >> 20),
(unsigned long long)rdev->gart.table_addr);
rdev->gart.ready = true;
return 0;
}
static void cayman_pcie_gart_disable(struct radeon_device *rdev)
{
WREG32(VM_CONTEXT0_CNTL, 0);
WREG32(VM_CONTEXT1_CNTL, 0);
WREG32(MC_VM_MX_L1_TLB_CNTL, ENABLE_L1_FRAGMENT_PROCESSING |
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU);
WREG32(VM_L2_CNTL, ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
ENABLE_L2_PDE0_CACHE_LRU_UPDATE_BY_WRITE |
EFFECTIVE_L2_QUEUE_SIZE(7) |
CONTEXT1_IDENTITY_ACCESS_MODE(1));
WREG32(VM_L2_CNTL2, 0);
WREG32(VM_L2_CNTL3, L2_CACHE_BIGK_ASSOCIATIVITY |
L2_CACHE_BIGK_FRAGMENT_SIZE(6));
radeon_gart_table_vram_unpin(rdev);
}
static void cayman_pcie_gart_fini(struct radeon_device *rdev)
{
cayman_pcie_gart_disable(rdev);
radeon_gart_table_vram_free(rdev);
radeon_gart_fini(rdev);
}
void cayman_cp_int_cntl_setup(struct radeon_device *rdev,
int ring, u32 cp_int_cntl)
{
u32 srbm_gfx_cntl = RREG32(SRBM_GFX_CNTL) & ~3;
WREG32(SRBM_GFX_CNTL, srbm_gfx_cntl | (ring & 3));
WREG32(CP_INT_CNTL, cp_int_cntl);
}
void cayman_fence_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
radeon_ring_write(ring, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(ring, (CP_COHER_CNTL2 - PACKET3_SET_CONFIG_REG_START) >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_SURFACE_SYNC, 3));
radeon_ring_write(ring, PACKET3_TC_ACTION_ENA | PACKET3_SH_ACTION_ENA);
radeon_ring_write(ring, 0xFFFFFFFF);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 10);
radeon_ring_write(ring, PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
radeon_ring_write(ring, EVENT_TYPE(CACHE_FLUSH_AND_INV_EVENT_TS) | EVENT_INDEX(5));
radeon_ring_write(ring, addr & 0xffffffff);
radeon_ring_write(ring, (upper_32_bits(addr) & 0xff) | DATA_SEL(1) | INT_SEL(2));
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, 0);
}
void cayman_ring_ib_execute(struct radeon_device *rdev, struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
radeon_ring_write(ring, PACKET3(PACKET3_MODE_CONTROL, 0));
radeon_ring_write(ring, 1);
if (ring->rptr_save_reg) {
uint32_t next_rptr = ring->wptr + 3 + 4 + 8;
radeon_ring_write(ring, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(ring, ((ring->rptr_save_reg -
PACKET3_SET_CONFIG_REG_START) >> 2));
radeon_ring_write(ring, next_rptr);
}
radeon_ring_write(ring, PACKET3(PACKET3_INDIRECT_BUFFER, 2));
radeon_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
radeon_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFF);
radeon_ring_write(ring, ib->length_dw |
(ib->vm ? (ib->vm->id << 24) : 0));
radeon_ring_write(ring, PACKET3(PACKET3_SET_CONFIG_REG, 1));
radeon_ring_write(ring, (CP_COHER_CNTL2 - PACKET3_SET_CONFIG_REG_START) >> 2);
radeon_ring_write(ring, ib->vm ? ib->vm->id : 0);
radeon_ring_write(ring, PACKET3(PACKET3_SURFACE_SYNC, 3));
radeon_ring_write(ring, PACKET3_TC_ACTION_ENA | PACKET3_SH_ACTION_ENA);
radeon_ring_write(ring, 0xFFFFFFFF);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 10);
}
static void cayman_cp_enable(struct radeon_device *rdev, bool enable)
{
if (enable)
WREG32(CP_ME_CNTL, 0);
else {
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
WREG32(CP_ME_CNTL, (CP_ME_HALT | CP_PFP_HALT));
WREG32(SCRATCH_UMSK, 0);
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = false;
}
}
static int cayman_cp_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->me_fw || !rdev->pfp_fw)
return -EINVAL;
cayman_cp_enable(rdev, false);
fw_data = (const __be32 *)rdev->pfp_fw->data;
WREG32(CP_PFP_UCODE_ADDR, 0);
for (i = 0; i < CAYMAN_PFP_UCODE_SIZE; i++)
WREG32(CP_PFP_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(CP_PFP_UCODE_ADDR, 0);
fw_data = (const __be32 *)rdev->me_fw->data;
WREG32(CP_ME_RAM_WADDR, 0);
for (i = 0; i < CAYMAN_PM4_UCODE_SIZE; i++)
WREG32(CP_ME_RAM_DATA, be32_to_cpup(fw_data++));
WREG32(CP_PFP_UCODE_ADDR, 0);
WREG32(CP_ME_RAM_WADDR, 0);
WREG32(CP_ME_RAM_RADDR, 0);
return 0;
}
static int cayman_cp_start(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
int r, i;
r = radeon_ring_lock(rdev, ring, 7);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(ring, PACKET3(PACKET3_ME_INITIALIZE, 5));
radeon_ring_write(ring, 0x1);
radeon_ring_write(ring, 0x0);
radeon_ring_write(ring, rdev->config.cayman.max_hw_contexts - 1);
radeon_ring_write(ring, PACKET3_ME_INITIALIZE_DEVICE_ID(1));
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
radeon_ring_unlock_commit(rdev, ring);
cayman_cp_enable(rdev, true);
r = radeon_ring_lock(rdev, ring, cayman_default_size + 19);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(ring, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
for (i = 0; i < cayman_default_size; i++)
radeon_ring_write(ring, cayman_default_state[i]);
radeon_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(ring, PACKET3_PREAMBLE_END_CLEAR_STATE);
radeon_ring_write(ring, PACKET3(PACKET3_CLEAR_STATE, 0));
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0xc0026f00);
radeon_ring_write(ring, 0x00000000);
radeon_ring_write(ring, 0x00000000);
radeon_ring_write(ring, 0x00000000);
radeon_ring_write(ring, 0xc0036f00);
radeon_ring_write(ring, 0x00000bc4);
radeon_ring_write(ring, 0xffffffff);
radeon_ring_write(ring, 0xffffffff);
radeon_ring_write(ring, 0xffffffff);
radeon_ring_write(ring, 0xc0026900);
radeon_ring_write(ring, 0x00000316);
radeon_ring_write(ring, 0x0000000e);
radeon_ring_write(ring, 0x00000010);
radeon_ring_unlock_commit(rdev, ring);
return 0;
}
static void cayman_cp_fini(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
cayman_cp_enable(rdev, false);
radeon_ring_fini(rdev, ring);
radeon_scratch_free(rdev, ring->rptr_save_reg);
}
static int cayman_cp_resume(struct radeon_device *rdev)
{
static const int ridx[] = {
RADEON_RING_TYPE_GFX_INDEX,
CAYMAN_RING_TYPE_CP1_INDEX,
CAYMAN_RING_TYPE_CP2_INDEX
};
static const unsigned cp_rb_cntl[] = {
CP_RB0_CNTL,
CP_RB1_CNTL,
CP_RB2_CNTL,
};
static const unsigned cp_rb_rptr_addr[] = {
CP_RB0_RPTR_ADDR,
CP_RB1_RPTR_ADDR,
CP_RB2_RPTR_ADDR
};
static const unsigned cp_rb_rptr_addr_hi[] = {
CP_RB0_RPTR_ADDR_HI,
CP_RB1_RPTR_ADDR_HI,
CP_RB2_RPTR_ADDR_HI
};
static const unsigned cp_rb_base[] = {
CP_RB0_BASE,
CP_RB1_BASE,
CP_RB2_BASE
};
struct radeon_ring *ring;
int i, r;
WREG32(GRBM_SOFT_RESET, (SOFT_RESET_CP |
SOFT_RESET_PA |
SOFT_RESET_SH |
SOFT_RESET_VGT |
SOFT_RESET_SPI |
SOFT_RESET_SX));
RREG32(GRBM_SOFT_RESET);
mdelay(15);
WREG32(GRBM_SOFT_RESET, 0);
RREG32(GRBM_SOFT_RESET);
WREG32(CP_SEM_WAIT_TIMER, 0x0);
WREG32(CP_SEM_INCOMPLETE_TIMER_CNTL, 0x0);
WREG32(CP_RB_WPTR_DELAY, 0);
WREG32(CP_DEBUG, (1 << 27));
WREG32(SCRATCH_ADDR, ((rdev->wb.gpu_addr + RADEON_WB_SCRATCH_OFFSET) >> 8) & 0xFFFFFFFF);
WREG32(SCRATCH_UMSK, 0xff);
for (i = 0; i < 3; ++i) {
uint32_t rb_cntl;
uint64_t addr;
ring = &rdev->ring[ridx[i]];
rb_cntl = drm_order(ring->ring_size / 8);
rb_cntl |= drm_order(RADEON_GPU_PAGE_SIZE/8) << 8;
#ifdef __BIG_ENDIAN
rb_cntl |= BUF_SWAP_32BIT;
#endif
WREG32(cp_rb_cntl[i], rb_cntl);
addr = rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET;
WREG32(cp_rb_rptr_addr[i], addr & 0xFFFFFFFC);
WREG32(cp_rb_rptr_addr_hi[i], upper_32_bits(addr) & 0xFF);
}
for (i = 0; i < 3; ++i) {
ring = &rdev->ring[ridx[i]];
WREG32(cp_rb_base[i], ring->gpu_addr >> 8);
}
for (i = 0; i < 3; ++i) {
ring = &rdev->ring[ridx[i]];
WREG32_P(cp_rb_cntl[i], RB_RPTR_WR_ENA, ~RB_RPTR_WR_ENA);
ring->rptr = ring->wptr = 0;
WREG32(ring->rptr_reg, ring->rptr);
WREG32(ring->wptr_reg, ring->wptr);
mdelay(1);
WREG32_P(cp_rb_cntl[i], 0, ~RB_RPTR_WR_ENA);
}
cayman_cp_start(rdev);
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = true;
rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX].ready = false;
r = radeon_ring_test(rdev, RADEON_RING_TYPE_GFX_INDEX, &rdev->ring[RADEON_RING_TYPE_GFX_INDEX]);
if (r) {
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX].ready = false;
return r;
}
return 0;
}
void cayman_dma_ring_ib_execute(struct radeon_device *rdev,
struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
if (rdev->wb.enabled) {
u32 next_rptr = ring->wptr + 4;
while ((next_rptr & 7) != 5)
next_rptr++;
next_rptr += 3;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_WRITE, 0, 0, 1));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xff);
radeon_ring_write(ring, next_rptr);
}
while ((ring->wptr & 7) != 5)
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0));
radeon_ring_write(ring, DMA_IB_PACKET(DMA_PACKET_INDIRECT_BUFFER, ib->vm ? ib->vm->id : 0, 0));
radeon_ring_write(ring, (ib->gpu_addr & 0xFFFFFFE0));
radeon_ring_write(ring, (ib->length_dw << 12) | (upper_32_bits(ib->gpu_addr) & 0xFF));
}
void cayman_dma_stop(struct radeon_device *rdev)
{
u32 rb_cntl;
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
rb_cntl = RREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET);
rb_cntl &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET, rb_cntl);
rb_cntl = RREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET);
rb_cntl &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET, rb_cntl);
rdev->ring[R600_RING_TYPE_DMA_INDEX].ready = false;
rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX].ready = false;
}
int cayman_dma_resume(struct radeon_device *rdev)
{
struct radeon_ring *ring;
u32 rb_cntl, dma_cntl, ib_cntl;
u32 rb_bufsz;
u32 reg_offset, wb_offset;
int i, r;
WREG32(SRBM_SOFT_RESET, SOFT_RESET_DMA | SOFT_RESET_DMA1);
RREG32(SRBM_SOFT_RESET);
udelay(50);
WREG32(SRBM_SOFT_RESET, 0);
for (i = 0; i < 2; i++) {
if (i == 0) {
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
reg_offset = DMA0_REGISTER_OFFSET;
wb_offset = R600_WB_DMA_RPTR_OFFSET;
} else {
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
reg_offset = DMA1_REGISTER_OFFSET;
wb_offset = CAYMAN_WB_DMA1_RPTR_OFFSET;
}
WREG32(DMA_SEM_INCOMPLETE_TIMER_CNTL + reg_offset, 0);
WREG32(DMA_SEM_WAIT_FAIL_TIMER_CNTL + reg_offset, 0);
rb_bufsz = drm_order(ring->ring_size / 4);
rb_cntl = rb_bufsz << 1;
#ifdef __BIG_ENDIAN
rb_cntl |= DMA_RB_SWAP_ENABLE | DMA_RPTR_WRITEBACK_SWAP_ENABLE;
#endif
WREG32(DMA_RB_CNTL + reg_offset, rb_cntl);
WREG32(DMA_RB_RPTR + reg_offset, 0);
WREG32(DMA_RB_WPTR + reg_offset, 0);
WREG32(DMA_RB_RPTR_ADDR_HI + reg_offset,
upper_32_bits(rdev->wb.gpu_addr + wb_offset) & 0xFF);
WREG32(DMA_RB_RPTR_ADDR_LO + reg_offset,
((rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC));
if (rdev->wb.enabled)
rb_cntl |= DMA_RPTR_WRITEBACK_ENABLE;
WREG32(DMA_RB_BASE + reg_offset, ring->gpu_addr >> 8);
ib_cntl = DMA_IB_ENABLE | CMD_VMID_FORCE;
#ifdef __BIG_ENDIAN
ib_cntl |= DMA_IB_SWAP_ENABLE;
#endif
WREG32(DMA_IB_CNTL + reg_offset, ib_cntl);
dma_cntl = RREG32(DMA_CNTL + reg_offset);
dma_cntl &= ~CTXEMPTY_INT_ENABLE;
WREG32(DMA_CNTL + reg_offset, dma_cntl);
ring->wptr = 0;
WREG32(DMA_RB_WPTR + reg_offset, ring->wptr << 2);
ring->rptr = RREG32(DMA_RB_RPTR + reg_offset) >> 2;
WREG32(DMA_RB_CNTL + reg_offset, rb_cntl | DMA_RB_ENABLE);
ring->ready = true;
r = radeon_ring_test(rdev, ring->idx, ring);
if (r) {
ring->ready = false;
return r;
}
}
radeon_ttm_set_active_vram_size(rdev, rdev->mc.real_vram_size);
return 0;
}
void cayman_dma_fini(struct radeon_device *rdev)
{
cayman_dma_stop(rdev);
radeon_ring_fini(rdev, &rdev->ring[R600_RING_TYPE_DMA_INDEX]);
radeon_ring_fini(rdev, &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX]);
}
static void cayman_gpu_soft_reset_gfx(struct radeon_device *rdev)
{
u32 grbm_reset = 0;
if (!(RREG32(GRBM_STATUS) & GUI_ACTIVE))
return;
dev_info(rdev->dev, " GRBM_STATUS = 0x%08X\n",
RREG32(GRBM_STATUS));
dev_info(rdev->dev, " GRBM_STATUS_SE0 = 0x%08X\n",
RREG32(GRBM_STATUS_SE0));
dev_info(rdev->dev, " GRBM_STATUS_SE1 = 0x%08X\n",
RREG32(GRBM_STATUS_SE1));
dev_info(rdev->dev, " SRBM_STATUS = 0x%08X\n",
RREG32(SRBM_STATUS));
dev_info(rdev->dev, " R_008674_CP_STALLED_STAT1 = 0x%08X\n",
RREG32(CP_STALLED_STAT1));
dev_info(rdev->dev, " R_008678_CP_STALLED_STAT2 = 0x%08X\n",
RREG32(CP_STALLED_STAT2));
dev_info(rdev->dev, " R_00867C_CP_BUSY_STAT = 0x%08X\n",
RREG32(CP_BUSY_STAT));
dev_info(rdev->dev, " R_008680_CP_STAT = 0x%08X\n",
RREG32(CP_STAT));
WREG32(CP_ME_CNTL, CP_ME_HALT | CP_PFP_HALT);
grbm_reset = (SOFT_RESET_CP |
SOFT_RESET_CB |
SOFT_RESET_DB |
SOFT_RESET_GDS |
SOFT_RESET_PA |
SOFT_RESET_SC |
SOFT_RESET_SPI |
SOFT_RESET_SH |
SOFT_RESET_SX |
SOFT_RESET_TC |
SOFT_RESET_TA |
SOFT_RESET_VGT |
SOFT_RESET_IA);
dev_info(rdev->dev, " GRBM_SOFT_RESET=0x%08X\n", grbm_reset);
WREG32(GRBM_SOFT_RESET, grbm_reset);
(void)RREG32(GRBM_SOFT_RESET);
udelay(50);
WREG32(GRBM_SOFT_RESET, 0);
(void)RREG32(GRBM_SOFT_RESET);
dev_info(rdev->dev, " GRBM_STATUS = 0x%08X\n",
RREG32(GRBM_STATUS));
dev_info(rdev->dev, " GRBM_STATUS_SE0 = 0x%08X\n",
RREG32(GRBM_STATUS_SE0));
dev_info(rdev->dev, " GRBM_STATUS_SE1 = 0x%08X\n",
RREG32(GRBM_STATUS_SE1));
dev_info(rdev->dev, " SRBM_STATUS = 0x%08X\n",
RREG32(SRBM_STATUS));
dev_info(rdev->dev, " R_008674_CP_STALLED_STAT1 = 0x%08X\n",
RREG32(CP_STALLED_STAT1));
dev_info(rdev->dev, " R_008678_CP_STALLED_STAT2 = 0x%08X\n",
RREG32(CP_STALLED_STAT2));
dev_info(rdev->dev, " R_00867C_CP_BUSY_STAT = 0x%08X\n",
RREG32(CP_BUSY_STAT));
dev_info(rdev->dev, " R_008680_CP_STAT = 0x%08X\n",
RREG32(CP_STAT));
}
static void cayman_gpu_soft_reset_dma(struct radeon_device *rdev)
{
u32 tmp;
if (RREG32(DMA_STATUS_REG) & DMA_IDLE)
return;
dev_info(rdev->dev, " R_00D034_DMA_STATUS_REG = 0x%08X\n",
RREG32(DMA_STATUS_REG));
tmp = RREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET);
tmp &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA0_REGISTER_OFFSET, tmp);
tmp = RREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET);
tmp &= ~DMA_RB_ENABLE;
WREG32(DMA_RB_CNTL + DMA1_REGISTER_OFFSET, tmp);
WREG32(SRBM_SOFT_RESET, SOFT_RESET_DMA | SOFT_RESET_DMA1);
RREG32(SRBM_SOFT_RESET);
udelay(50);
WREG32(SRBM_SOFT_RESET, 0);
dev_info(rdev->dev, " R_00D034_DMA_STATUS_REG = 0x%08X\n",
RREG32(DMA_STATUS_REG));
}
static int cayman_gpu_soft_reset(struct radeon_device *rdev, u32 reset_mask)
{
struct evergreen_mc_save save;
if (!(RREG32(GRBM_STATUS) & GUI_ACTIVE))
reset_mask &= ~(RADEON_RESET_GFX | RADEON_RESET_COMPUTE);
if (RREG32(DMA_STATUS_REG) & DMA_IDLE)
reset_mask &= ~RADEON_RESET_DMA;
if (reset_mask == 0)
return 0;
dev_info(rdev->dev, "GPU softreset: 0x%08X\n", reset_mask);
dev_info(rdev->dev, " VM_CONTEXT0_PROTECTION_FAULT_ADDR 0x%08X\n",
RREG32(0x14F8));
dev_info(rdev->dev, " VM_CONTEXT0_PROTECTION_FAULT_STATUS 0x%08X\n",
RREG32(0x14D8));
dev_info(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_ADDR 0x%08X\n",
RREG32(0x14FC));
dev_info(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_STATUS 0x%08X\n",
RREG32(0x14DC));
evergreen_mc_stop(rdev, &save);
if (evergreen_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
if (reset_mask & (RADEON_RESET_GFX | RADEON_RESET_COMPUTE))
cayman_gpu_soft_reset_gfx(rdev);
if (reset_mask & RADEON_RESET_DMA)
cayman_gpu_soft_reset_dma(rdev);
udelay(50);
evergreen_mc_resume(rdev, &save);
return 0;
}
int cayman_asic_reset(struct radeon_device *rdev)
{
return cayman_gpu_soft_reset(rdev, (RADEON_RESET_GFX |
RADEON_RESET_COMPUTE |
RADEON_RESET_DMA));
}
bool cayman_dma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 dma_status_reg;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
dma_status_reg = RREG32(DMA_STATUS_REG + DMA0_REGISTER_OFFSET);
else
dma_status_reg = RREG32(DMA_STATUS_REG + DMA1_REGISTER_OFFSET);
if (dma_status_reg & DMA_IDLE) {
radeon_ring_lockup_update(ring);
return false;
}
radeon_ring_force_activity(rdev, ring);
return radeon_ring_test_lockup(rdev, ring);
}
static int cayman_startup(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
int r;
evergreen_pcie_gen2_enable(rdev);
if (rdev->flags & RADEON_IS_IGP) {
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->rlc_fw) {
r = ni_init_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load firmware!\n");
return r;
}
}
} else {
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->rlc_fw || !rdev->mc_fw) {
r = ni_init_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load firmware!\n");
return r;
}
}
r = ni_mc_load_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load MC firmware!\n");
return r;
}
}
r = r600_vram_scratch_init(rdev);
if (r)
return r;
evergreen_mc_program(rdev);
r = cayman_pcie_gart_enable(rdev);
if (r)
return r;
cayman_gpu_init(rdev);
r = evergreen_blit_init(rdev);
if (r) {
r600_blit_fini(rdev);
rdev->asic->copy.copy = NULL;
dev_warn(rdev->dev, "failed blitter (%d) falling back to memcpy\n", r);
}
if (rdev->flags & RADEON_IS_IGP) {
r = si_rlc_init(rdev);
if (r) {
DRM_ERROR("Failed to init rlc BOs!\n");
return r;
}
}
r = radeon_wb_init(rdev);
if (r)
return r;
r = radeon_fence_driver_start_ring(rdev, RADEON_RING_TYPE_GFX_INDEX);
if (r) {
dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
return r;
}
r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_CP1_INDEX);
if (r) {
dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
return r;
}
r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_CP2_INDEX);
if (r) {
dev_err(rdev->dev, "failed initializing CP fences (%d).\n", r);
return r;
}
r = radeon_fence_driver_start_ring(rdev, R600_RING_TYPE_DMA_INDEX);
if (r) {
dev_err(rdev->dev, "failed initializing DMA fences (%d).\n", r);
return r;
}
r = radeon_fence_driver_start_ring(rdev, CAYMAN_RING_TYPE_DMA1_INDEX);
if (r) {
dev_err(rdev->dev, "failed initializing DMA fences (%d).\n", r);
return r;
}
r = r600_irq_init(rdev);
if (r) {
DRM_ERROR("radeon: IH init failed (%d).\n", r);
radeon_irq_kms_fini(rdev);
return r;
}
evergreen_irq_set(rdev);
r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP_RPTR_OFFSET,
CP_RB0_RPTR, CP_RB0_WPTR,
0, 0xfffff, RADEON_CP_PACKET2);
if (r)
return r;
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, R600_WB_DMA_RPTR_OFFSET,
DMA_RB_RPTR + DMA0_REGISTER_OFFSET,
DMA_RB_WPTR + DMA0_REGISTER_OFFSET,
2, 0x3fffc, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0));
if (r)
return r;
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, CAYMAN_WB_DMA1_RPTR_OFFSET,
DMA_RB_RPTR + DMA1_REGISTER_OFFSET,
DMA_RB_WPTR + DMA1_REGISTER_OFFSET,
2, 0x3fffc, DMA_PACKET(DMA_PACKET_NOP, 0, 0, 0));
if (r)
return r;
r = cayman_cp_load_microcode(rdev);
if (r)
return r;
r = cayman_cp_resume(rdev);
if (r)
return r;
r = cayman_dma_resume(rdev);
if (r)
return r;
r = radeon_ib_pool_init(rdev);
if (r) {
dev_err(rdev->dev, "IB initialization failed (%d).\n", r);
return r;
}
r = radeon_vm_manager_init(rdev);
if (r) {
dev_err(rdev->dev, "vm manager initialization failed (%d).\n", r);
return r;
}
r = r600_audio_init(rdev);
if (r)
return r;
return 0;
}
int cayman_resume(struct radeon_device *rdev)
{
int r;
atom_asic_init(rdev->mode_info.atom_context);
rdev->accel_working = true;
r = cayman_startup(rdev);
if (r) {
DRM_ERROR("cayman startup failed on resume\n");
rdev->accel_working = false;
return r;
}
return r;
}
int cayman_suspend(struct radeon_device *rdev)
{
r600_audio_fini(rdev);
cayman_cp_enable(rdev, false);
cayman_dma_stop(rdev);
evergreen_irq_suspend(rdev);
radeon_wb_disable(rdev);
cayman_pcie_gart_disable(rdev);
return 0;
}
int cayman_init(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
int r;
if (!radeon_get_bios(rdev)) {
if (ASIC_IS_AVIVO(rdev))
return -EINVAL;
}
if (!rdev->is_atom_bios) {
dev_err(rdev->dev, "Expecting atombios for cayman GPU\n");
return -EINVAL;
}
r = radeon_atombios_init(rdev);
if (r)
return r;
if (!radeon_card_posted(rdev)) {
if (!rdev->bios) {
dev_err(rdev->dev, "Card not posted and no BIOS - ignoring\n");
return -EINVAL;
}
DRM_INFO("GPU not posted. posting now...\n");
atom_asic_init(rdev->mode_info.atom_context);
}
r600_scratch_init(rdev);
radeon_surface_init(rdev);
radeon_get_clock_info(rdev->ddev);
r = radeon_fence_driver_init(rdev);
if (r)
return r;
r = evergreen_mc_init(rdev);
if (r)
return r;
r = radeon_bo_init(rdev);
if (r)
return r;
r = radeon_irq_kms_init(rdev);
if (r)
return r;
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 1024 * 1024);
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 64 * 1024);
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 64 * 1024);
rdev->ih.ring_obj = NULL;
r600_ih_ring_init(rdev, 64 * 1024);
r = r600_pcie_gart_init(rdev);
if (r)
return r;
rdev->accel_working = true;
r = cayman_startup(rdev);
if (r) {
dev_err(rdev->dev, "disabling GPU acceleration\n");
cayman_cp_fini(rdev);
cayman_dma_fini(rdev);
r600_irq_fini(rdev);
if (rdev->flags & RADEON_IS_IGP)
si_rlc_fini(rdev);
radeon_wb_fini(rdev);
radeon_ib_pool_fini(rdev);
radeon_vm_manager_fini(rdev);
radeon_irq_kms_fini(rdev);
cayman_pcie_gart_fini(rdev);
rdev->accel_working = false;
}
if (!rdev->mc_fw && !(rdev->flags & RADEON_IS_IGP)) {
DRM_ERROR("radeon: MC ucode required for NI+.\n");
return -EINVAL;
}
return 0;
}
void cayman_fini(struct radeon_device *rdev)
{
r600_blit_fini(rdev);
cayman_cp_fini(rdev);
cayman_dma_fini(rdev);
r600_irq_fini(rdev);
if (rdev->flags & RADEON_IS_IGP)
si_rlc_fini(rdev);
radeon_wb_fini(rdev);
radeon_vm_manager_fini(rdev);
radeon_ib_pool_fini(rdev);
radeon_irq_kms_fini(rdev);
cayman_pcie_gart_fini(rdev);
r600_vram_scratch_fini(rdev);
radeon_gem_fini(rdev);
radeon_fence_driver_fini(rdev);
radeon_bo_fini(rdev);
radeon_atombios_fini(rdev);
kfree(rdev->bios);
rdev->bios = NULL;
}
int cayman_vm_init(struct radeon_device *rdev)
{
rdev->vm_manager.nvm = 8;
if (rdev->flags & RADEON_IS_IGP) {
u64 tmp = RREG32(FUS_MC_VM_FB_OFFSET);
tmp <<= 22;
rdev->vm_manager.vram_base_offset = tmp;
} else
rdev->vm_manager.vram_base_offset = 0;
return 0;
}
void cayman_vm_fini(struct radeon_device *rdev)
{
}
uint32_t cayman_vm_page_flags(struct radeon_device *rdev, uint32_t flags)
{
uint32_t r600_flags = 0;
r600_flags |= (flags & RADEON_VM_PAGE_VALID) ? R600_ENTRY_VALID : 0;
r600_flags |= (flags & RADEON_VM_PAGE_READABLE) ? R600_PTE_READABLE : 0;
r600_flags |= (flags & RADEON_VM_PAGE_WRITEABLE) ? R600_PTE_WRITEABLE : 0;
if (flags & RADEON_VM_PAGE_SYSTEM) {
r600_flags |= R600_PTE_SYSTEM;
r600_flags |= (flags & RADEON_VM_PAGE_SNOOPED) ? R600_PTE_SNOOPED : 0;
}
return r600_flags;
}
void cayman_vm_set_page(struct radeon_device *rdev, uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
struct radeon_ring *ring = &rdev->ring[rdev->asic->vm.pt_ring_index];
uint32_t r600_flags = cayman_vm_page_flags(rdev, flags);
uint64_t value;
unsigned ndw;
if (rdev->asic->vm.pt_ring_index == RADEON_RING_TYPE_GFX_INDEX) {
while (count) {
ndw = 1 + count * 2;
if (ndw > 0x3FFF)
ndw = 0x3FFF;
radeon_ring_write(ring, PACKET3(PACKET3_ME_WRITE, ndw));
radeon_ring_write(ring, pe);
radeon_ring_write(ring, upper_32_bits(pe) & 0xff);
for (; ndw > 1; ndw -= 2, --count, pe += 8) {
if (flags & RADEON_VM_PAGE_SYSTEM) {
value = radeon_vm_map_gart(rdev, addr);
value &= 0xFFFFFFFFFFFFF000ULL;
} else if (flags & RADEON_VM_PAGE_VALID) {
value = addr;
} else {
value = 0;
}
addr += incr;
value |= r600_flags;
radeon_ring_write(ring, value);
radeon_ring_write(ring, upper_32_bits(value));
}
}
} else {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_WRITE, 0, 0, ndw));
radeon_ring_write(ring, pe);
radeon_ring_write(ring, upper_32_bits(pe) & 0xff);
for (; ndw > 0; ndw -= 2, --count, pe += 8) {
if (flags & RADEON_VM_PAGE_SYSTEM) {
value = radeon_vm_map_gart(rdev, addr);
value &= 0xFFFFFFFFFFFFF000ULL;
} else if (flags & RADEON_VM_PAGE_VALID) {
value = addr;
} else {
value = 0;
}
addr += incr;
value |= r600_flags;
radeon_ring_write(ring, value);
radeon_ring_write(ring, upper_32_bits(value));
}
}
}
}
void cayman_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, PACKET0(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2), 0));
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, PACKET0(HDP_MEM_COHERENCY_FLUSH_CNTL, 0));
radeon_ring_write(ring, 0x1);
radeon_ring_write(ring, PACKET0(VM_INVALIDATE_REQUEST, 0));
radeon_ring_write(ring, 1 << vm->id);
radeon_ring_write(ring, PACKET3(PACKET3_PFP_SYNC_ME, 0));
radeon_ring_write(ring, 0x0);
}
void cayman_dma_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | ((VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2));
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (HDP_MEM_COHERENCY_FLUSH_CNTL >> 2));
radeon_ring_write(ring, 1);
radeon_ring_write(ring, DMA_PACKET(DMA_PACKET_SRBM_WRITE, 0, 0, 0));
radeon_ring_write(ring, (0xf << 16) | (VM_INVALIDATE_REQUEST >> 2));
radeon_ring_write(ring, 1 << vm->id);
}
