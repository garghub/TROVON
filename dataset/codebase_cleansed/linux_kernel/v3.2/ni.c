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
static u32 cayman_get_tile_pipe_to_backend_map(struct radeon_device *rdev,
u32 num_tile_pipes,
u32 num_backends_per_asic,
u32 *backend_disable_mask_per_asic,
u32 num_shader_engines)
{
u32 backend_map = 0;
u32 enabled_backends_mask = 0;
u32 enabled_backends_count = 0;
u32 num_backends_per_se;
u32 cur_pipe;
u32 swizzle_pipe[CAYMAN_MAX_PIPES];
u32 cur_backend = 0;
u32 i;
bool force_no_swizzle;
if (num_tile_pipes < 1)
num_tile_pipes = 1;
if (num_tile_pipes > rdev->config.cayman.max_tile_pipes)
num_tile_pipes = rdev->config.cayman.max_tile_pipes;
if (num_shader_engines < 1)
num_shader_engines = 1;
if (num_shader_engines > rdev->config.cayman.max_shader_engines)
num_shader_engines = rdev->config.cayman.max_shader_engines;
if (num_backends_per_asic < num_shader_engines)
num_backends_per_asic = num_shader_engines;
if (num_backends_per_asic > (rdev->config.cayman.max_backends_per_se * num_shader_engines))
num_backends_per_asic = rdev->config.cayman.max_backends_per_se * num_shader_engines;
num_backends_per_asic = ALIGN(num_backends_per_asic, num_shader_engines);
num_backends_per_se = num_backends_per_asic / num_shader_engines;
if (num_backends_per_se > rdev->config.cayman.max_backends_per_se) {
num_backends_per_se = rdev->config.cayman.max_backends_per_se;
num_backends_per_asic = num_backends_per_se * num_shader_engines;
}
for (i = 0; i < CAYMAN_MAX_BACKENDS; ++i) {
if (((*backend_disable_mask_per_asic >> i) & 1) == 0) {
enabled_backends_mask |= (1 << i);
++enabled_backends_count;
}
if (enabled_backends_count == num_backends_per_asic)
break;
}
if (enabled_backends_count != num_backends_per_asic) {
u32 this_backend_enabled;
u32 shader_engine;
u32 backend_per_se;
enabled_backends_mask = 0;
enabled_backends_count = 0;
*backend_disable_mask_per_asic = CAYMAN_MAX_BACKENDS_MASK;
for (i = 0; i < CAYMAN_MAX_BACKENDS; ++i) {
shader_engine = i / rdev->config.cayman.max_backends_per_se;
backend_per_se = i % rdev->config.cayman.max_backends_per_se;
this_backend_enabled = 0;
if ((shader_engine < num_shader_engines) &&
(backend_per_se < num_backends_per_se))
this_backend_enabled = 1;
if (this_backend_enabled) {
enabled_backends_mask |= (1 << i);
*backend_disable_mask_per_asic &= ~(1 << i);
++enabled_backends_count;
}
}
}
memset((uint8_t *)&swizzle_pipe[0], 0, sizeof(u32) * CAYMAN_MAX_PIPES);
switch (rdev->family) {
case CHIP_CAYMAN:
force_no_swizzle = true;
break;
default:
force_no_swizzle = false;
break;
}
if (force_no_swizzle) {
bool last_backend_enabled = false;
force_no_swizzle = false;
for (i = 0; i < CAYMAN_MAX_BACKENDS; ++i) {
if (((enabled_backends_mask >> i) & 1) == 1) {
if (last_backend_enabled)
force_no_swizzle = true;
last_backend_enabled = true;
} else
last_backend_enabled = false;
}
}
switch (num_tile_pipes) {
case 1:
case 3:
case 5:
case 7:
DRM_ERROR("odd number of pipes!\n");
break;
case 2:
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
break;
case 4:
if (force_no_swizzle) {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
swizzle_pipe[3] = 3;
} else {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 1;
swizzle_pipe[3] = 3;
}
break;
case 6:
if (force_no_swizzle) {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
swizzle_pipe[3] = 3;
swizzle_pipe[4] = 4;
swizzle_pipe[5] = 5;
} else {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 4;
swizzle_pipe[3] = 1;
swizzle_pipe[4] = 3;
swizzle_pipe[5] = 5;
}
break;
case 8:
if (force_no_swizzle) {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 1;
swizzle_pipe[2] = 2;
swizzle_pipe[3] = 3;
swizzle_pipe[4] = 4;
swizzle_pipe[5] = 5;
swizzle_pipe[6] = 6;
swizzle_pipe[7] = 7;
} else {
swizzle_pipe[0] = 0;
swizzle_pipe[1] = 2;
swizzle_pipe[2] = 4;
swizzle_pipe[3] = 6;
swizzle_pipe[4] = 1;
swizzle_pipe[5] = 3;
swizzle_pipe[6] = 5;
swizzle_pipe[7] = 7;
}
break;
}
for (cur_pipe = 0; cur_pipe < num_tile_pipes; ++cur_pipe) {
while (((1 << cur_backend) & enabled_backends_mask) == 0)
cur_backend = (cur_backend + 1) % CAYMAN_MAX_BACKENDS;
backend_map |= (((cur_backend & 0xf) << (swizzle_pipe[cur_pipe] * 4)));
cur_backend = (cur_backend + 1) % CAYMAN_MAX_BACKENDS;
}
return backend_map;
}
static u32 cayman_get_disable_mask_per_asic(struct radeon_device *rdev,
u32 disable_mask_per_se,
u32 max_disable_mask_per_se,
u32 num_shader_engines)
{
u32 disable_field_width_per_se = r600_count_pipe_bits(disable_mask_per_se);
u32 disable_mask_per_asic = disable_mask_per_se & max_disable_mask_per_se;
if (num_shader_engines == 1)
return disable_mask_per_asic;
else if (num_shader_engines == 2)
return disable_mask_per_asic | (disable_mask_per_asic << disable_field_width_per_se);
else
return 0xffffffff;
}
static void cayman_gpu_init(struct radeon_device *rdev)
{
u32 cc_rb_backend_disable = 0;
u32 cc_gc_shader_pipe_config;
u32 gb_addr_config = 0;
u32 mc_shared_chmap, mc_arb_ramcfg;
u32 gb_backend_map;
u32 cgts_tcc_disable;
u32 sx_debug_1;
u32 smx_dc_ctl0;
u32 gc_user_shader_pipe_config;
u32 gc_user_rb_backend_disable;
u32 cgts_user_tcc_disable;
u32 cgts_sm_ctrl_reg;
u32 hdp_host_path_cntl;
u32 tmp;
int i, j;
switch (rdev->family) {
case CHIP_CAYMAN:
default:
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
cc_rb_backend_disable = RREG32(CC_RB_BACKEND_DISABLE);
cc_gc_shader_pipe_config = RREG32(CC_GC_SHADER_PIPE_CONFIG);
cgts_tcc_disable = 0xff000000;
gc_user_rb_backend_disable = RREG32(GC_USER_RB_BACKEND_DISABLE);
gc_user_shader_pipe_config = RREG32(GC_USER_SHADER_PIPE_CONFIG);
cgts_user_tcc_disable = RREG32(CGTS_USER_TCC_DISABLE);
rdev->config.cayman.num_shader_engines = rdev->config.cayman.max_shader_engines;
tmp = ((~gc_user_shader_pipe_config) & INACTIVE_QD_PIPES_MASK) >> INACTIVE_QD_PIPES_SHIFT;
rdev->config.cayman.num_shader_pipes_per_simd = r600_count_pipe_bits(tmp);
rdev->config.cayman.num_tile_pipes = rdev->config.cayman.max_tile_pipes;
tmp = ((~gc_user_shader_pipe_config) & INACTIVE_SIMDS_MASK) >> INACTIVE_SIMDS_SHIFT;
rdev->config.cayman.num_simds_per_se = r600_count_pipe_bits(tmp);
tmp = ((~gc_user_rb_backend_disable) & BACKEND_DISABLE_MASK) >> BACKEND_DISABLE_SHIFT;
rdev->config.cayman.num_backends_per_se = r600_count_pipe_bits(tmp);
tmp = (gc_user_rb_backend_disable & BACKEND_DISABLE_MASK) >> BACKEND_DISABLE_SHIFT;
rdev->config.cayman.backend_disable_mask_per_asic =
cayman_get_disable_mask_per_asic(rdev, tmp, CAYMAN_MAX_BACKENDS_PER_SE_MASK,
rdev->config.cayman.num_shader_engines);
rdev->config.cayman.backend_map =
cayman_get_tile_pipe_to_backend_map(rdev, rdev->config.cayman.num_tile_pipes,
rdev->config.cayman.num_backends_per_se *
rdev->config.cayman.num_shader_engines,
&rdev->config.cayman.backend_disable_mask_per_asic,
rdev->config.cayman.num_shader_engines);
tmp = ((~cgts_user_tcc_disable) & TCC_DISABLE_MASK) >> TCC_DISABLE_SHIFT;
rdev->config.cayman.num_texture_channel_caches = r600_count_pipe_bits(tmp);
tmp = (mc_arb_ramcfg & BURSTLENGTH_MASK) >> BURSTLENGTH_SHIFT;
rdev->config.cayman.mem_max_burst_length_bytes = (tmp + 1) * 256;
if (rdev->config.cayman.mem_max_burst_length_bytes > 512)
rdev->config.cayman.mem_max_burst_length_bytes = 512;
tmp = (mc_arb_ramcfg & NOOFCOLS_MASK) >> NOOFCOLS_SHIFT;
rdev->config.cayman.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
if (rdev->config.cayman.mem_row_size_in_kb > 4)
rdev->config.cayman.mem_row_size_in_kb = 4;
rdev->config.cayman.shader_engine_tile_size = 32;
rdev->config.cayman.num_gpus = 1;
rdev->config.cayman.multi_gpu_tile_size = 64;
#if 0
gb_addr_config = RREG32(GB_ADDR_CONFIG);
#else
gb_addr_config = 0;
switch (rdev->config.cayman.num_tile_pipes) {
case 1:
default:
gb_addr_config |= NUM_PIPES(0);
break;
case 2:
gb_addr_config |= NUM_PIPES(1);
break;
case 4:
gb_addr_config |= NUM_PIPES(2);
break;
case 8:
gb_addr_config |= NUM_PIPES(3);
break;
}
tmp = (rdev->config.cayman.mem_max_burst_length_bytes / 256) - 1;
gb_addr_config |= PIPE_INTERLEAVE_SIZE(tmp);
gb_addr_config |= NUM_SHADER_ENGINES(rdev->config.cayman.num_shader_engines - 1);
tmp = (rdev->config.cayman.shader_engine_tile_size / 16) - 1;
gb_addr_config |= SHADER_ENGINE_TILE_SIZE(tmp);
switch (rdev->config.cayman.num_gpus) {
case 1:
default:
gb_addr_config |= NUM_GPUS(0);
break;
case 2:
gb_addr_config |= NUM_GPUS(1);
break;
case 4:
gb_addr_config |= NUM_GPUS(2);
break;
}
switch (rdev->config.cayman.multi_gpu_tile_size) {
case 16:
gb_addr_config |= MULTI_GPU_TILE_SIZE(0);
break;
case 32:
default:
gb_addr_config |= MULTI_GPU_TILE_SIZE(1);
break;
case 64:
gb_addr_config |= MULTI_GPU_TILE_SIZE(2);
break;
case 128:
gb_addr_config |= MULTI_GPU_TILE_SIZE(3);
break;
}
switch (rdev->config.cayman.mem_row_size_in_kb) {
case 1:
default:
gb_addr_config |= ROW_SIZE(0);
break;
case 2:
gb_addr_config |= ROW_SIZE(1);
break;
case 4:
gb_addr_config |= ROW_SIZE(2);
break;
}
#endif
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
#if 0
gb_backend_map = RREG32(GB_BACKEND_MAP);
#else
gb_backend_map =
cayman_get_tile_pipe_to_backend_map(rdev, rdev->config.cayman.num_tile_pipes,
rdev->config.cayman.num_backends_per_se *
rdev->config.cayman.num_shader_engines,
&rdev->config.cayman.backend_disable_mask_per_asic,
rdev->config.cayman.num_shader_engines);
#endif
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
rdev->config.cayman.tile_config |=
((mc_arb_ramcfg & NOOFBANK_MASK) >> NOOFBANK_SHIFT) << 4;
rdev->config.cayman.tile_config |=
((gb_addr_config & PIPE_INTERLEAVE_SIZE_MASK) >> PIPE_INTERLEAVE_SIZE_SHIFT) << 8;
rdev->config.cayman.tile_config |=
((gb_addr_config & ROW_SIZE_MASK) >> ROW_SIZE_SHIFT) << 12;
rdev->config.cayman.backend_map = gb_backend_map;
WREG32(GB_BACKEND_MAP, gb_backend_map);
WREG32(GB_ADDR_CONFIG, gb_addr_config);
WREG32(DMIF_ADDR_CONFIG, gb_addr_config);
WREG32(HDP_ADDR_CONFIG, gb_addr_config);
WREG32(CC_RB_BACKEND_DISABLE, cc_rb_backend_disable);
WREG32(CC_SYS_RB_BACKEND_DISABLE, cc_rb_backend_disable);
WREG32(CC_GC_SHADER_PIPE_CONFIG, cc_gc_shader_pipe_config);
WREG32(CGTS_TCC_DISABLE, cgts_tcc_disable);
WREG32(CGTS_SYS_TCC_DISABLE, cgts_tcc_disable);
WREG32(GC_USER_RB_BACKEND_DISABLE, cc_rb_backend_disable);
WREG32(GC_USER_SYS_RB_BACKEND_DISABLE, cc_rb_backend_disable);
WREG32(GC_USER_SHADER_PIPE_CONFIG, cc_gc_shader_pipe_config);
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
int cayman_pcie_gart_enable(struct radeon_device *rdev)
{
int r;
if (rdev->gart.robj == NULL) {
dev_err(rdev->dev, "No VRAM object for PCIE GART.\n");
return -EINVAL;
}
r = radeon_gart_table_vram_pin(rdev);
if (r)
return r;
radeon_gart_restore(rdev);
WREG32(MC_VM_MX_L1_TLB_CNTL, ENABLE_L1_TLB |
ENABLE_L1_FRAGMENT_PROCESSING |
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
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
WREG32(VM_CONTEXT1_CNTL2, 0);
WREG32(VM_CONTEXT1_CNTL, 0);
cayman_pcie_gart_tlb_flush(rdev);
DRM_INFO("PCIE GART of %uM enabled (table at 0x%016llX).\n",
(unsigned)(rdev->mc.gtt_size >> 20),
(unsigned long long)rdev->gart.table_addr);
rdev->gart.ready = true;
return 0;
}
void cayman_pcie_gart_disable(struct radeon_device *rdev)
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
void cayman_pcie_gart_fini(struct radeon_device *rdev)
{
cayman_pcie_gart_disable(rdev);
radeon_gart_table_vram_free(rdev);
radeon_gart_fini(rdev);
}
static void cayman_cp_enable(struct radeon_device *rdev, bool enable)
{
if (enable)
WREG32(CP_ME_CNTL, 0);
else {
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
WREG32(CP_ME_CNTL, (CP_ME_HALT | CP_PFP_HALT));
WREG32(SCRATCH_UMSK, 0);
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
int r, i;
r = radeon_ring_lock(rdev, 7);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(rdev, PACKET3(PACKET3_ME_INITIALIZE, 5));
radeon_ring_write(rdev, 0x1);
radeon_ring_write(rdev, 0x0);
radeon_ring_write(rdev, rdev->config.cayman.max_hw_contexts - 1);
radeon_ring_write(rdev, PACKET3_ME_INITIALIZE_DEVICE_ID(1));
radeon_ring_write(rdev, 0);
radeon_ring_write(rdev, 0);
radeon_ring_unlock_commit(rdev);
cayman_cp_enable(rdev, true);
r = radeon_ring_lock(rdev, cayman_default_size + 19);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(rdev, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(rdev, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
for (i = 0; i < cayman_default_size; i++)
radeon_ring_write(rdev, cayman_default_state[i]);
radeon_ring_write(rdev, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(rdev, PACKET3_PREAMBLE_END_CLEAR_STATE);
radeon_ring_write(rdev, PACKET3(PACKET3_CLEAR_STATE, 0));
radeon_ring_write(rdev, 0);
radeon_ring_write(rdev, 0xc0026f00);
radeon_ring_write(rdev, 0x00000000);
radeon_ring_write(rdev, 0x00000000);
radeon_ring_write(rdev, 0x00000000);
radeon_ring_write(rdev, 0xc0036f00);
radeon_ring_write(rdev, 0x00000bc4);
radeon_ring_write(rdev, 0xffffffff);
radeon_ring_write(rdev, 0xffffffff);
radeon_ring_write(rdev, 0xffffffff);
radeon_ring_write(rdev, 0xc0026900);
radeon_ring_write(rdev, 0x00000316);
radeon_ring_write(rdev, 0x0000000e);
radeon_ring_write(rdev, 0x00000010);
radeon_ring_unlock_commit(rdev);
return 0;
}
static void cayman_cp_fini(struct radeon_device *rdev)
{
cayman_cp_enable(rdev, false);
radeon_ring_fini(rdev);
}
int cayman_cp_resume(struct radeon_device *rdev)
{
u32 tmp;
u32 rb_bufsz;
int r;
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
WREG32(CP_SEM_WAIT_TIMER, 0x4);
WREG32(CP_RB_WPTR_DELAY, 0);
WREG32(CP_DEBUG, (1 << 27));
rb_bufsz = drm_order(rdev->cp.ring_size / 8);
tmp = (drm_order(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= BUF_SWAP_32BIT;
#endif
WREG32(CP_RB0_CNTL, tmp);
WREG32(CP_RB0_CNTL, tmp | RB_RPTR_WR_ENA);
rdev->cp.wptr = 0;
WREG32(CP_RB0_WPTR, rdev->cp.wptr);
WREG32(CP_RB0_RPTR_ADDR, (rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFFFFFFFC);
WREG32(CP_RB0_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFF);
WREG32(SCRATCH_ADDR, ((rdev->wb.gpu_addr + RADEON_WB_SCRATCH_OFFSET) >> 8) & 0xFFFFFFFF);
if (rdev->wb.enabled)
WREG32(SCRATCH_UMSK, 0xff);
else {
tmp |= RB_NO_UPDATE;
WREG32(SCRATCH_UMSK, 0);
}
mdelay(1);
WREG32(CP_RB0_CNTL, tmp);
WREG32(CP_RB0_BASE, rdev->cp.gpu_addr >> 8);
rdev->cp.rptr = RREG32(CP_RB0_RPTR);
rb_bufsz = drm_order(rdev->cp1.ring_size / 8);
tmp = (drm_order(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= BUF_SWAP_32BIT;
#endif
WREG32(CP_RB1_CNTL, tmp);
WREG32(CP_RB1_CNTL, tmp | RB_RPTR_WR_ENA);
rdev->cp1.wptr = 0;
WREG32(CP_RB1_WPTR, rdev->cp1.wptr);
WREG32(CP_RB1_RPTR_ADDR, (rdev->wb.gpu_addr + RADEON_WB_CP1_RPTR_OFFSET) & 0xFFFFFFFC);
WREG32(CP_RB1_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP1_RPTR_OFFSET) & 0xFF);
mdelay(1);
WREG32(CP_RB1_CNTL, tmp);
WREG32(CP_RB1_BASE, rdev->cp1.gpu_addr >> 8);
rdev->cp1.rptr = RREG32(CP_RB1_RPTR);
rb_bufsz = drm_order(rdev->cp2.ring_size / 8);
tmp = (drm_order(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= BUF_SWAP_32BIT;
#endif
WREG32(CP_RB2_CNTL, tmp);
WREG32(CP_RB2_CNTL, tmp | RB_RPTR_WR_ENA);
rdev->cp2.wptr = 0;
WREG32(CP_RB2_WPTR, rdev->cp2.wptr);
WREG32(CP_RB2_RPTR_ADDR, (rdev->wb.gpu_addr + RADEON_WB_CP2_RPTR_OFFSET) & 0xFFFFFFFC);
WREG32(CP_RB2_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP2_RPTR_OFFSET) & 0xFF);
mdelay(1);
WREG32(CP_RB2_CNTL, tmp);
WREG32(CP_RB2_BASE, rdev->cp2.gpu_addr >> 8);
rdev->cp2.rptr = RREG32(CP_RB2_RPTR);
cayman_cp_start(rdev);
rdev->cp.ready = true;
rdev->cp1.ready = true;
rdev->cp2.ready = true;
r = radeon_ring_test(rdev);
if (r) {
rdev->cp.ready = false;
rdev->cp1.ready = false;
rdev->cp2.ready = false;
return r;
}
return 0;
}
bool cayman_gpu_is_lockup(struct radeon_device *rdev)
{
u32 srbm_status;
u32 grbm_status;
u32 grbm_status_se0, grbm_status_se1;
struct r100_gpu_lockup *lockup = &rdev->config.cayman.lockup;
int r;
srbm_status = RREG32(SRBM_STATUS);
grbm_status = RREG32(GRBM_STATUS);
grbm_status_se0 = RREG32(GRBM_STATUS_SE0);
grbm_status_se1 = RREG32(GRBM_STATUS_SE1);
if (!(grbm_status & GUI_ACTIVE)) {
r100_gpu_lockup_update(lockup, &rdev->cp);
return false;
}
r = radeon_ring_lock(rdev, 2);
if (!r) {
radeon_ring_write(rdev, 0x80000000);
radeon_ring_write(rdev, 0x80000000);
radeon_ring_unlock_commit(rdev);
}
rdev->cp.rptr = RREG32(CP_RB0_RPTR);
return r100_gpu_cp_is_lockup(rdev, lockup, &rdev->cp);
}
static int cayman_gpu_soft_reset(struct radeon_device *rdev)
{
struct evergreen_mc_save save;
u32 grbm_reset = 0;
if (!(RREG32(GRBM_STATUS) & GUI_ACTIVE))
return 0;
dev_info(rdev->dev, "GPU softreset \n");
dev_info(rdev->dev, " GRBM_STATUS=0x%08X\n",
RREG32(GRBM_STATUS));
dev_info(rdev->dev, " GRBM_STATUS_SE0=0x%08X\n",
RREG32(GRBM_STATUS_SE0));
dev_info(rdev->dev, " GRBM_STATUS_SE1=0x%08X\n",
RREG32(GRBM_STATUS_SE1));
dev_info(rdev->dev, " SRBM_STATUS=0x%08X\n",
RREG32(SRBM_STATUS));
evergreen_mc_stop(rdev, &save);
if (evergreen_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
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
udelay(50);
dev_info(rdev->dev, " GRBM_STATUS=0x%08X\n",
RREG32(GRBM_STATUS));
dev_info(rdev->dev, " GRBM_STATUS_SE0=0x%08X\n",
RREG32(GRBM_STATUS_SE0));
dev_info(rdev->dev, " GRBM_STATUS_SE1=0x%08X\n",
RREG32(GRBM_STATUS_SE1));
dev_info(rdev->dev, " SRBM_STATUS=0x%08X\n",
RREG32(SRBM_STATUS));
evergreen_mc_resume(rdev, &save);
return 0;
}
int cayman_asic_reset(struct radeon_device *rdev)
{
return cayman_gpu_soft_reset(rdev);
}
static int cayman_startup(struct radeon_device *rdev)
{
int r;
evergreen_pcie_gen2_enable(rdev);
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
rdev->asic->copy = NULL;
dev_warn(rdev->dev, "failed blitter (%d) falling back to memcpy\n", r);
}
r = radeon_wb_init(rdev);
if (r)
return r;
r = r600_irq_init(rdev);
if (r) {
DRM_ERROR("radeon: IH init failed (%d).\n", r);
radeon_irq_kms_fini(rdev);
return r;
}
evergreen_irq_set(rdev);
r = radeon_ring_init(rdev, rdev->cp.ring_size);
if (r)
return r;
r = cayman_cp_load_microcode(rdev);
if (r)
return r;
r = cayman_cp_resume(rdev);
if (r)
return r;
return 0;
}
int cayman_resume(struct radeon_device *rdev)
{
int r;
atom_asic_init(rdev->mode_info.atom_context);
r = cayman_startup(rdev);
if (r) {
DRM_ERROR("cayman startup failed on resume\n");
return r;
}
r = r600_ib_test(rdev);
if (r) {
DRM_ERROR("radeon: failled testing IB (%d).\n", r);
return r;
}
return r;
}
int cayman_suspend(struct radeon_device *rdev)
{
cayman_cp_enable(rdev, false);
rdev->cp.ready = false;
evergreen_irq_suspend(rdev);
radeon_wb_disable(rdev);
cayman_pcie_gart_disable(rdev);
r600_blit_suspend(rdev);
return 0;
}
int cayman_init(struct radeon_device *rdev)
{
int r;
r = radeon_gem_init(rdev);
if (r)
return r;
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
rdev->cp.ring_obj = NULL;
r600_ring_init(rdev, 1024 * 1024);
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
r600_irq_fini(rdev);
radeon_wb_fini(rdev);
radeon_irq_kms_fini(rdev);
cayman_pcie_gart_fini(rdev);
rdev->accel_working = false;
}
if (rdev->accel_working) {
r = radeon_ib_pool_init(rdev);
if (r) {
DRM_ERROR("radeon: failed initializing IB pool (%d).\n", r);
rdev->accel_working = false;
}
r = r600_ib_test(rdev);
if (r) {
DRM_ERROR("radeon: failed testing IB (%d).\n", r);
rdev->accel_working = false;
}
}
if (!rdev->mc_fw) {
DRM_ERROR("radeon: MC ucode required for NI+.\n");
return -EINVAL;
}
return 0;
}
void cayman_fini(struct radeon_device *rdev)
{
r600_blit_fini(rdev);
cayman_cp_fini(rdev);
r600_irq_fini(rdev);
radeon_wb_fini(rdev);
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
