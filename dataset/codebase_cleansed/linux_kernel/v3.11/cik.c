u32 cik_pciep_rreg(struct radeon_device *rdev, u32 reg)
{
u32 r;
WREG32(PCIE_INDEX, reg);
(void)RREG32(PCIE_INDEX);
r = RREG32(PCIE_DATA);
return r;
}
void cik_pciep_wreg(struct radeon_device *rdev, u32 reg, u32 v)
{
WREG32(PCIE_INDEX, reg);
(void)RREG32(PCIE_INDEX);
WREG32(PCIE_DATA, v);
(void)RREG32(PCIE_DATA);
}
static void cik_init_golden_registers(struct radeon_device *rdev)
{
switch (rdev->family) {
case CHIP_BONAIRE:
radeon_program_register_sequence(rdev,
bonaire_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(bonaire_mgcg_cgcg_init));
radeon_program_register_sequence(rdev,
bonaire_golden_registers,
(const u32)ARRAY_SIZE(bonaire_golden_registers));
radeon_program_register_sequence(rdev,
bonaire_golden_common_registers,
(const u32)ARRAY_SIZE(bonaire_golden_common_registers));
radeon_program_register_sequence(rdev,
bonaire_golden_spm_registers,
(const u32)ARRAY_SIZE(bonaire_golden_spm_registers));
break;
case CHIP_KABINI:
radeon_program_register_sequence(rdev,
kalindi_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(kalindi_mgcg_cgcg_init));
radeon_program_register_sequence(rdev,
kalindi_golden_registers,
(const u32)ARRAY_SIZE(kalindi_golden_registers));
radeon_program_register_sequence(rdev,
kalindi_golden_common_registers,
(const u32)ARRAY_SIZE(kalindi_golden_common_registers));
radeon_program_register_sequence(rdev,
kalindi_golden_spm_registers,
(const u32)ARRAY_SIZE(kalindi_golden_spm_registers));
break;
case CHIP_KAVERI:
radeon_program_register_sequence(rdev,
spectre_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(spectre_mgcg_cgcg_init));
radeon_program_register_sequence(rdev,
spectre_golden_registers,
(const u32)ARRAY_SIZE(spectre_golden_registers));
radeon_program_register_sequence(rdev,
spectre_golden_common_registers,
(const u32)ARRAY_SIZE(spectre_golden_common_registers));
radeon_program_register_sequence(rdev,
spectre_golden_spm_registers,
(const u32)ARRAY_SIZE(spectre_golden_spm_registers));
break;
default:
break;
}
}
u32 cik_get_xclk(struct radeon_device *rdev)
{
u32 reference_clock = rdev->clock.spll.reference_freq;
if (rdev->flags & RADEON_IS_IGP) {
if (RREG32_SMC(GENERAL_PWRMGT) & GPU_COUNTER_CLK)
return reference_clock / 2;
} else {
if (RREG32_SMC(CG_CLKPIN_CNTL) & XTALIN_DIVIDE)
return reference_clock / 4;
}
return reference_clock;
}
u32 cik_mm_rdoorbell(struct radeon_device *rdev, u32 offset)
{
if (offset < rdev->doorbell.size) {
return readl(((void __iomem *)rdev->doorbell.ptr) + offset);
} else {
DRM_ERROR("reading beyond doorbell aperture: 0x%08x!\n", offset);
return 0;
}
}
void cik_mm_wdoorbell(struct radeon_device *rdev, u32 offset, u32 v)
{
if (offset < rdev->doorbell.size) {
writel(v, ((void __iomem *)rdev->doorbell.ptr) + offset);
} else {
DRM_ERROR("writing beyond doorbell aperture: 0x%08x!\n", offset);
}
}
static void cik_srbm_select(struct radeon_device *rdev,
u32 me, u32 pipe, u32 queue, u32 vmid)
{
u32 srbm_gfx_cntl = (PIPEID(pipe & 0x3) |
MEID(me & 0x3) |
VMID(vmid & 0xf) |
QUEUEID(queue & 0x7));
WREG32(SRBM_GFX_CNTL, srbm_gfx_cntl);
}
static int ci_mc_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
u32 running, blackout = 0;
u32 *io_mc_regs;
int i, ucode_size, regs_size;
if (!rdev->mc_fw)
return -EINVAL;
switch (rdev->family) {
case CHIP_BONAIRE:
default:
io_mc_regs = (u32 *)&bonaire_io_mc_regs;
ucode_size = CIK_MC_UCODE_SIZE;
regs_size = BONAIRE_IO_MC_REGS_SIZE;
break;
}
running = RREG32(MC_SEQ_SUP_CNTL) & RUN_MASK;
if (running == 0) {
if (running) {
blackout = RREG32(MC_SHARED_BLACKOUT_CNTL);
WREG32(MC_SHARED_BLACKOUT_CNTL, blackout | 1);
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
if (RREG32(MC_SEQ_TRAIN_WAKEUP_CNTL) & TRAIN_DONE_D0)
break;
udelay(1);
}
for (i = 0; i < rdev->usec_timeout; i++) {
if (RREG32(MC_SEQ_TRAIN_WAKEUP_CNTL) & TRAIN_DONE_D1)
break;
udelay(1);
}
if (running)
WREG32(MC_SHARED_BLACKOUT_CNTL, blackout);
}
return 0;
}
static int cik_init_microcode(struct radeon_device *rdev)
{
const char *chip_name;
size_t pfp_req_size, me_req_size, ce_req_size,
mec_req_size, rlc_req_size, mc_req_size,
sdma_req_size;
char fw_name[30];
int err;
DRM_DEBUG("\n");
switch (rdev->family) {
case CHIP_BONAIRE:
chip_name = "BONAIRE";
pfp_req_size = CIK_PFP_UCODE_SIZE * 4;
me_req_size = CIK_ME_UCODE_SIZE * 4;
ce_req_size = CIK_CE_UCODE_SIZE * 4;
mec_req_size = CIK_MEC_UCODE_SIZE * 4;
rlc_req_size = BONAIRE_RLC_UCODE_SIZE * 4;
mc_req_size = CIK_MC_UCODE_SIZE * 4;
sdma_req_size = CIK_SDMA_UCODE_SIZE * 4;
break;
case CHIP_KAVERI:
chip_name = "KAVERI";
pfp_req_size = CIK_PFP_UCODE_SIZE * 4;
me_req_size = CIK_ME_UCODE_SIZE * 4;
ce_req_size = CIK_CE_UCODE_SIZE * 4;
mec_req_size = CIK_MEC_UCODE_SIZE * 4;
rlc_req_size = KV_RLC_UCODE_SIZE * 4;
sdma_req_size = CIK_SDMA_UCODE_SIZE * 4;
break;
case CHIP_KABINI:
chip_name = "KABINI";
pfp_req_size = CIK_PFP_UCODE_SIZE * 4;
me_req_size = CIK_ME_UCODE_SIZE * 4;
ce_req_size = CIK_CE_UCODE_SIZE * 4;
mec_req_size = CIK_MEC_UCODE_SIZE * 4;
rlc_req_size = KB_RLC_UCODE_SIZE * 4;
sdma_req_size = CIK_SDMA_UCODE_SIZE * 4;
break;
default: BUG();
}
DRM_INFO("Loading %s Microcode\n", chip_name);
snprintf(fw_name, sizeof(fw_name), "radeon/%s_pfp.bin", chip_name);
err = request_firmware(&rdev->pfp_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->pfp_fw->size != pfp_req_size) {
printk(KERN_ERR
"cik_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->pfp_fw->size, fw_name);
err = -EINVAL;
goto out;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_me.bin", chip_name);
err = request_firmware(&rdev->me_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->me_fw->size != me_req_size) {
printk(KERN_ERR
"cik_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->me_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_ce.bin", chip_name);
err = request_firmware(&rdev->ce_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->ce_fw->size != ce_req_size) {
printk(KERN_ERR
"cik_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->ce_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_mec.bin", chip_name);
err = request_firmware(&rdev->mec_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->mec_fw->size != mec_req_size) {
printk(KERN_ERR
"cik_cp: Bogus length %zu in firmware \"%s\"\n",
rdev->mec_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_rlc.bin", chip_name);
err = request_firmware(&rdev->rlc_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->rlc_fw->size != rlc_req_size) {
printk(KERN_ERR
"cik_rlc: Bogus length %zu in firmware \"%s\"\n",
rdev->rlc_fw->size, fw_name);
err = -EINVAL;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_sdma.bin", chip_name);
err = request_firmware(&rdev->sdma_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->sdma_fw->size != sdma_req_size) {
printk(KERN_ERR
"cik_sdma: Bogus length %zu in firmware \"%s\"\n",
rdev->sdma_fw->size, fw_name);
err = -EINVAL;
}
if (!(rdev->flags & RADEON_IS_IGP)) {
snprintf(fw_name, sizeof(fw_name), "radeon/%s_mc.bin", chip_name);
err = request_firmware(&rdev->mc_fw, fw_name, rdev->dev);
if (err)
goto out;
if (rdev->mc_fw->size != mc_req_size) {
printk(KERN_ERR
"cik_mc: Bogus length %zu in firmware \"%s\"\n",
rdev->mc_fw->size, fw_name);
err = -EINVAL;
}
}
out:
if (err) {
if (err != -EINVAL)
printk(KERN_ERR
"cik_cp: Failed to load firmware \"%s\"\n",
fw_name);
release_firmware(rdev->pfp_fw);
rdev->pfp_fw = NULL;
release_firmware(rdev->me_fw);
rdev->me_fw = NULL;
release_firmware(rdev->ce_fw);
rdev->ce_fw = NULL;
release_firmware(rdev->rlc_fw);
rdev->rlc_fw = NULL;
release_firmware(rdev->mc_fw);
rdev->mc_fw = NULL;
}
return err;
}
static void cik_tiling_mode_table_init(struct radeon_device *rdev)
{
const u32 num_tile_mode_states = 32;
const u32 num_secondary_tile_mode_states = 16;
u32 reg_offset, gb_tile_moden, split_equal_to_row_size;
u32 num_pipe_configs;
u32 num_rbs = rdev->config.cik.max_backends_per_se *
rdev->config.cik.max_shader_engines;
switch (rdev->config.cik.mem_row_size_in_kb) {
case 1:
split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_1KB;
break;
case 2:
default:
split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_2KB;
break;
case 4:
split_equal_to_row_size = ADDR_SURF_TILE_SPLIT_4KB;
break;
}
num_pipe_configs = rdev->config.cik.max_tile_pipes;
if (num_pipe_configs > 8)
num_pipe_configs = 8;
if (num_pipe_configs == 8) {
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 7:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 12:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 17:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 30:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
default:
gb_tile_moden = 0;
break;
}
rdev->config.cik.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(GB_TILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 1:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 5:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
break;
case 6:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_2_BANK));
break;
case 8:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_8) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 9:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 10:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 11:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 12:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 13:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
break;
case 14:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_2_BANK));
break;
default:
gb_tile_moden = 0;
break;
}
WREG32(GB_MACROTILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
} else if (num_pipe_configs == 4) {
if (num_rbs == 4) {
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 7:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P4_16x16));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 12:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 17:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 30:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
default:
gb_tile_moden = 0;
break;
}
rdev->config.cik.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(GB_TILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
} else if (num_rbs < 4) {
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 7:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P4_8x16));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 12:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 17:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 30:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P4_8x16) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
default:
gb_tile_moden = 0;
break;
}
rdev->config.cik.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(GB_TILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
}
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 1:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 5:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 6:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
break;
case 8:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_8) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 9:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 10:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 11:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 12:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 13:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 14:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
break;
default:
gb_tile_moden = 0;
break;
}
WREG32(GB_MACROTILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
} else if (num_pipe_configs == 2) {
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B));
break;
case 7:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(split_equal_to_row_size));
break;
case 8:
gb_tile_moden = ARRAY_MODE(ARRAY_LINEAR_ALIGNED);
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 12:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 17:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 30:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
PIPE_CONFIG(ADDR_SURF_P2) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
default:
gb_tile_moden = 0;
break;
}
rdev->config.cik.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(GB_TILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 1:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 5:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 6:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 8:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_8) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 9:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 10:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 11:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 12:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 13:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 14:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
default:
gb_tile_moden = 0;
break;
}
WREG32(GB_MACROTILE_MODE0 + (reg_offset * 4), gb_tile_moden);
}
} else
DRM_ERROR("unknown num pipe config: 0x%x\n", num_pipe_configs);
}
static void cik_select_se_sh(struct radeon_device *rdev,
u32 se_num, u32 sh_num)
{
u32 data = INSTANCE_BROADCAST_WRITES;
if ((se_num == 0xffffffff) && (sh_num == 0xffffffff))
data |= SH_BROADCAST_WRITES | SE_BROADCAST_WRITES;
else if (se_num == 0xffffffff)
data |= SE_BROADCAST_WRITES | SH_INDEX(sh_num);
else if (sh_num == 0xffffffff)
data |= SH_BROADCAST_WRITES | SE_INDEX(se_num);
else
data |= SH_INDEX(sh_num) | SE_INDEX(se_num);
WREG32(GRBM_GFX_INDEX, data);
}
static u32 cik_create_bitmask(u32 bit_width)
{
u32 i, mask = 0;
for (i = 0; i < bit_width; i++) {
mask <<= 1;
mask |= 1;
}
return mask;
}
static u32 cik_get_rb_disabled(struct radeon_device *rdev,
u32 max_rb_num, u32 se_num,
u32 sh_per_se)
{
u32 data, mask;
data = RREG32(CC_RB_BACKEND_DISABLE);
if (data & 1)
data &= BACKEND_DISABLE_MASK;
else
data = 0;
data |= RREG32(GC_USER_RB_BACKEND_DISABLE);
data >>= BACKEND_DISABLE_SHIFT;
mask = cik_create_bitmask(max_rb_num / se_num / sh_per_se);
return data & mask;
}
static void cik_setup_rb(struct radeon_device *rdev,
u32 se_num, u32 sh_per_se,
u32 max_rb_num)
{
int i, j;
u32 data, mask;
u32 disabled_rbs = 0;
u32 enabled_rbs = 0;
for (i = 0; i < se_num; i++) {
for (j = 0; j < sh_per_se; j++) {
cik_select_se_sh(rdev, i, j);
data = cik_get_rb_disabled(rdev, max_rb_num, se_num, sh_per_se);
disabled_rbs |= data << ((i * sh_per_se + j) * CIK_RB_BITMAP_WIDTH_PER_SH);
}
}
cik_select_se_sh(rdev, 0xffffffff, 0xffffffff);
mask = 1;
for (i = 0; i < max_rb_num; i++) {
if (!(disabled_rbs & mask))
enabled_rbs |= mask;
mask <<= 1;
}
for (i = 0; i < se_num; i++) {
cik_select_se_sh(rdev, i, 0xffffffff);
data = 0;
for (j = 0; j < sh_per_se; j++) {
switch (enabled_rbs & 3) {
case 1:
data |= (RASTER_CONFIG_RB_MAP_0 << (i * sh_per_se + j) * 2);
break;
case 2:
data |= (RASTER_CONFIG_RB_MAP_3 << (i * sh_per_se + j) * 2);
break;
case 3:
default:
data |= (RASTER_CONFIG_RB_MAP_2 << (i * sh_per_se + j) * 2);
break;
}
enabled_rbs >>= 2;
}
WREG32(PA_SC_RASTER_CONFIG, data);
}
cik_select_se_sh(rdev, 0xffffffff, 0xffffffff);
}
static void cik_gpu_init(struct radeon_device *rdev)
{
u32 gb_addr_config = RREG32(GB_ADDR_CONFIG);
u32 mc_shared_chmap, mc_arb_ramcfg;
u32 hdp_host_path_cntl;
u32 tmp;
int i, j;
switch (rdev->family) {
case CHIP_BONAIRE:
rdev->config.cik.max_shader_engines = 2;
rdev->config.cik.max_tile_pipes = 4;
rdev->config.cik.max_cu_per_sh = 7;
rdev->config.cik.max_sh_per_se = 1;
rdev->config.cik.max_backends_per_se = 2;
rdev->config.cik.max_texture_channel_caches = 4;
rdev->config.cik.max_gprs = 256;
rdev->config.cik.max_gs_threads = 32;
rdev->config.cik.max_hw_contexts = 8;
rdev->config.cik.sc_prim_fifo_size_frontend = 0x20;
rdev->config.cik.sc_prim_fifo_size_backend = 0x100;
rdev->config.cik.sc_hiz_tile_fifo_size = 0x30;
rdev->config.cik.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = BONAIRE_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_KAVERI:
break;
case CHIP_KABINI:
default:
rdev->config.cik.max_shader_engines = 1;
rdev->config.cik.max_tile_pipes = 2;
rdev->config.cik.max_cu_per_sh = 2;
rdev->config.cik.max_sh_per_se = 1;
rdev->config.cik.max_backends_per_se = 1;
rdev->config.cik.max_texture_channel_caches = 2;
rdev->config.cik.max_gprs = 256;
rdev->config.cik.max_gs_threads = 16;
rdev->config.cik.max_hw_contexts = 8;
rdev->config.cik.sc_prim_fifo_size_frontend = 0x20;
rdev->config.cik.sc_prim_fifo_size_backend = 0x100;
rdev->config.cik.sc_hiz_tile_fifo_size = 0x30;
rdev->config.cik.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = BONAIRE_GB_ADDR_CONFIG_GOLDEN;
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
WREG32(BIF_FB_EN, FB_READ_EN | FB_WRITE_EN);
mc_shared_chmap = RREG32(MC_SHARED_CHMAP);
mc_arb_ramcfg = RREG32(MC_ARB_RAMCFG);
rdev->config.cik.num_tile_pipes = rdev->config.cik.max_tile_pipes;
rdev->config.cik.mem_max_burst_length_bytes = 256;
tmp = (mc_arb_ramcfg & NOOFCOLS_MASK) >> NOOFCOLS_SHIFT;
rdev->config.cik.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
if (rdev->config.cik.mem_row_size_in_kb > 4)
rdev->config.cik.mem_row_size_in_kb = 4;
rdev->config.cik.shader_engine_tile_size = 32;
rdev->config.cik.num_gpus = 1;
rdev->config.cik.multi_gpu_tile_size = 64;
gb_addr_config &= ~ROW_SIZE_MASK;
switch (rdev->config.cik.mem_row_size_in_kb) {
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
rdev->config.cik.tile_config = 0;
switch (rdev->config.cik.num_tile_pipes) {
case 1:
rdev->config.cik.tile_config |= (0 << 0);
break;
case 2:
rdev->config.cik.tile_config |= (1 << 0);
break;
case 4:
rdev->config.cik.tile_config |= (2 << 0);
break;
case 8:
default:
rdev->config.cik.tile_config |= (3 << 0);
break;
}
if ((mc_arb_ramcfg & NOOFBANK_MASK) >> NOOFBANK_SHIFT)
rdev->config.cik.tile_config |= 1 << 4;
else
rdev->config.cik.tile_config |= 0 << 4;
rdev->config.cik.tile_config |=
((gb_addr_config & PIPE_INTERLEAVE_SIZE_MASK) >> PIPE_INTERLEAVE_SIZE_SHIFT) << 8;
rdev->config.cik.tile_config |=
((gb_addr_config & ROW_SIZE_MASK) >> ROW_SIZE_SHIFT) << 12;
WREG32(GB_ADDR_CONFIG, gb_addr_config);
WREG32(HDP_ADDR_CONFIG, gb_addr_config);
WREG32(DMIF_ADDR_CALC, gb_addr_config);
WREG32(SDMA0_TILING_CONFIG + SDMA0_REGISTER_OFFSET, gb_addr_config & 0x70);
WREG32(SDMA0_TILING_CONFIG + SDMA1_REGISTER_OFFSET, gb_addr_config & 0x70);
WREG32(UVD_UDEC_ADDR_CONFIG, gb_addr_config);
WREG32(UVD_UDEC_DB_ADDR_CONFIG, gb_addr_config);
WREG32(UVD_UDEC_DBW_ADDR_CONFIG, gb_addr_config);
cik_tiling_mode_table_init(rdev);
cik_setup_rb(rdev, rdev->config.cik.max_shader_engines,
rdev->config.cik.max_sh_per_se,
rdev->config.cik.max_backends_per_se);
WREG32(CP_MEQ_THRESHOLDS, MEQ1_START(0x30) | MEQ2_START(0x60));
WREG32(SX_DEBUG_1, 0x20);
WREG32(TA_CNTL_AUX, 0x00010000);
tmp = RREG32(SPI_CONFIG_CNTL);
tmp |= 0x03000000;
WREG32(SPI_CONFIG_CNTL, tmp);
WREG32(SQ_CONFIG, 1);
WREG32(DB_DEBUG, 0);
tmp = RREG32(DB_DEBUG2) & ~0xf00fffff;
tmp |= 0x00000400;
WREG32(DB_DEBUG2, tmp);
tmp = RREG32(DB_DEBUG3) & ~0x0002021c;
tmp |= 0x00020200;
WREG32(DB_DEBUG3, tmp);
tmp = RREG32(CB_HW_CONTROL) & ~0x00010000;
tmp |= 0x00018208;
WREG32(CB_HW_CONTROL, tmp);
WREG32(SPI_CONFIG_CNTL_1, VTX_DONE_DELAY(4));
WREG32(PA_SC_FIFO_SIZE, (SC_FRONTEND_PRIM_FIFO_SIZE(rdev->config.cik.sc_prim_fifo_size_frontend) |
SC_BACKEND_PRIM_FIFO_SIZE(rdev->config.cik.sc_prim_fifo_size_backend) |
SC_HIZ_TILE_FIFO_SIZE(rdev->config.cik.sc_hiz_tile_fifo_size) |
SC_EARLYZ_TILE_FIFO_SIZE(rdev->config.cik.sc_earlyz_tile_fifo_size)));
WREG32(VGT_NUM_INSTANCES, 1);
WREG32(CP_PERFMON_CNTL, 0);
WREG32(SQ_CONFIG, 0);
WREG32(PA_SC_FORCE_EOV_MAX_CNTS, (FORCE_EOV_MAX_CLK_CNT(4095) |
FORCE_EOV_MAX_REZ_CNT(255)));
WREG32(VGT_CACHE_INVALIDATION, CACHE_INVALIDATION(VC_AND_TC) |
AUTO_INVLD_EN(ES_AND_GS_AUTO));
WREG32(VGT_GS_VERTEX_REUSE, 16);
WREG32(PA_SC_LINE_STIPPLE_STATE, 0);
tmp = RREG32(HDP_MISC_CNTL);
tmp |= HDP_FLUSH_INVALIDATE_CACHE;
WREG32(HDP_MISC_CNTL, tmp);
hdp_host_path_cntl = RREG32(HDP_HOST_PATH_CNTL);
WREG32(HDP_HOST_PATH_CNTL, hdp_host_path_cntl);
WREG32(PA_CL_ENHANCE, CLIP_VTX_REORDER_ENA | NUM_CLIP_SEQ(3));
WREG32(PA_SC_ENHANCE, ENABLE_PA_SC_OUT_OF_ORDER);
udelay(50);
}
static void cik_scratch_init(struct radeon_device *rdev)
{
int i;
rdev->scratch.num_reg = 7;
rdev->scratch.reg_base = SCRATCH_REG0;
for (i = 0; i < rdev->scratch.num_reg; i++) {
rdev->scratch.free[i] = true;
rdev->scratch.reg[i] = rdev->scratch.reg_base + (i * 4);
}
}
int cik_ring_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = radeon_scratch_get(rdev, &scratch);
if (r) {
DRM_ERROR("radeon: cp failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = radeon_ring_lock(rdev, ring, 3);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring %d (%d).\n", ring->idx, r);
radeon_scratch_free(rdev, scratch);
return r;
}
radeon_ring_write(ring, PACKET3(PACKET3_SET_UCONFIG_REG, 1));
radeon_ring_write(ring, ((scratch - PACKET3_SET_UCONFIG_REG_START) >> 2));
radeon_ring_write(ring, 0xDEADBEEF);
radeon_ring_unlock_commit(rdev, ring);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n", ring->idx, i);
} else {
DRM_ERROR("radeon: ring %d test failed (scratch(0x%04X)=0x%08X)\n",
ring->idx, scratch, tmp);
r = -EINVAL;
}
radeon_scratch_free(rdev, scratch);
return r;
}
void cik_fence_gfx_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
radeon_ring_write(ring, PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
radeon_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
radeon_ring_write(ring, addr & 0xfffffffc);
radeon_ring_write(ring, (upper_32_bits(addr) & 0xffff) | DATA_SEL(1) | INT_SEL(2));
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, HDP_MEM_COHERENCY_FLUSH_CNTL >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
}
void cik_fence_compute_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
radeon_ring_write(ring, PACKET3(PACKET3_RELEASE_MEM, 5));
radeon_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
radeon_ring_write(ring, DATA_SEL(1) | INT_SEL(2));
radeon_ring_write(ring, addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(addr));
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, HDP_MEM_COHERENCY_FLUSH_CNTL >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
}
void cik_semaphore_ring_emit(struct radeon_device *rdev,
struct radeon_ring *ring,
struct radeon_semaphore *semaphore,
bool emit_wait)
{
uint64_t addr = semaphore->gpu_addr;
unsigned sel = emit_wait ? PACKET3_SEM_SEL_WAIT : PACKET3_SEM_SEL_SIGNAL;
radeon_ring_write(ring, PACKET3(PACKET3_MEM_SEMAPHORE, 1));
radeon_ring_write(ring, addr & 0xffffffff);
radeon_ring_write(ring, (upper_32_bits(addr) & 0xffff) | sel);
}
void cik_ring_ib_execute(struct radeon_device *rdev, struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
u32 header, control = INDIRECT_BUFFER_VALID;
if (ib->is_const_ib) {
radeon_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
radeon_ring_write(ring, 0);
header = PACKET3(PACKET3_INDIRECT_BUFFER_CONST, 2);
} else {
u32 next_rptr;
if (ring->rptr_save_reg) {
next_rptr = ring->wptr + 3 + 4;
radeon_ring_write(ring, PACKET3(PACKET3_SET_UCONFIG_REG, 1));
radeon_ring_write(ring, ((ring->rptr_save_reg -
PACKET3_SET_UCONFIG_REG_START) >> 2));
radeon_ring_write(ring, next_rptr);
} else if (rdev->wb.enabled) {
next_rptr = ring->wptr + 5 + 4;
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, WRITE_DATA_DST_SEL(1));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xffffffff);
radeon_ring_write(ring, next_rptr);
}
header = PACKET3(PACKET3_INDIRECT_BUFFER, 2);
}
control |= ib->length_dw |
(ib->vm ? (ib->vm->id << 24) : 0);
radeon_ring_write(ring, header);
radeon_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
radeon_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
radeon_ring_write(ring, control);
}
int cik_ib_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
struct radeon_ib ib;
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = radeon_scratch_get(rdev, &scratch);
if (r) {
DRM_ERROR("radeon: failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = radeon_ib_get(rdev, ring->idx, &ib, NULL, 256);
if (r) {
DRM_ERROR("radeon: failed to get ib (%d).\n", r);
return r;
}
ib.ptr[0] = PACKET3(PACKET3_SET_UCONFIG_REG, 1);
ib.ptr[1] = ((scratch - PACKET3_SET_UCONFIG_REG_START) >> 2);
ib.ptr[2] = 0xDEADBEEF;
ib.length_dw = 3;
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r) {
radeon_scratch_free(rdev, scratch);
radeon_ib_free(rdev, &ib);
DRM_ERROR("radeon: failed to schedule ib (%d).\n", r);
return r;
}
r = radeon_fence_wait(ib.fence, false);
if (r) {
DRM_ERROR("radeon: fence wait failed (%d).\n", r);
return r;
}
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ib test on ring %d succeeded in %u usecs\n", ib.fence->ring, i);
} else {
DRM_ERROR("radeon: ib test failed (scratch(0x%04X)=0x%08X)\n",
scratch, tmp);
r = -EINVAL;
}
radeon_scratch_free(rdev, scratch);
radeon_ib_free(rdev, &ib);
return r;
}
static void cik_cp_gfx_enable(struct radeon_device *rdev, bool enable)
{
if (enable)
WREG32(CP_ME_CNTL, 0);
else {
WREG32(CP_ME_CNTL, (CP_ME_HALT | CP_PFP_HALT | CP_CE_HALT));
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = false;
}
udelay(50);
}
static int cik_cp_gfx_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->ce_fw)
return -EINVAL;
cik_cp_gfx_enable(rdev, false);
fw_data = (const __be32 *)rdev->pfp_fw->data;
WREG32(CP_PFP_UCODE_ADDR, 0);
for (i = 0; i < CIK_PFP_UCODE_SIZE; i++)
WREG32(CP_PFP_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(CP_PFP_UCODE_ADDR, 0);
fw_data = (const __be32 *)rdev->ce_fw->data;
WREG32(CP_CE_UCODE_ADDR, 0);
for (i = 0; i < CIK_CE_UCODE_SIZE; i++)
WREG32(CP_CE_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(CP_CE_UCODE_ADDR, 0);
fw_data = (const __be32 *)rdev->me_fw->data;
WREG32(CP_ME_RAM_WADDR, 0);
for (i = 0; i < CIK_ME_UCODE_SIZE; i++)
WREG32(CP_ME_RAM_DATA, be32_to_cpup(fw_data++));
WREG32(CP_ME_RAM_WADDR, 0);
WREG32(CP_PFP_UCODE_ADDR, 0);
WREG32(CP_CE_UCODE_ADDR, 0);
WREG32(CP_ME_RAM_WADDR, 0);
WREG32(CP_ME_RAM_RADDR, 0);
return 0;
}
static int cik_cp_gfx_start(struct radeon_device *rdev)
{
struct radeon_ring *ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
int r, i;
WREG32(CP_MAX_CONTEXT, rdev->config.cik.max_hw_contexts - 1);
WREG32(CP_ENDIAN_SWAP, 0);
WREG32(CP_DEVICE_ID, 1);
cik_cp_gfx_enable(rdev, true);
r = radeon_ring_lock(rdev, ring, cik_default_size + 17);
if (r) {
DRM_ERROR("radeon: cp failed to lock ring (%d).\n", r);
return r;
}
radeon_ring_write(ring, PACKET3(PACKET3_SET_BASE, 2));
radeon_ring_write(ring, PACKET3_BASE_INDEX(CE_PARTITION_BASE));
radeon_ring_write(ring, 0xc000);
radeon_ring_write(ring, 0xc000);
radeon_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(ring, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
radeon_ring_write(ring, PACKET3(PACKET3_CONTEXT_CONTROL, 1));
radeon_ring_write(ring, 0x80000000);
radeon_ring_write(ring, 0x80000000);
for (i = 0; i < cik_default_size; i++)
radeon_ring_write(ring, cik_default_state[i]);
radeon_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
radeon_ring_write(ring, PACKET3_PREAMBLE_END_CLEAR_STATE);
radeon_ring_write(ring, PACKET3(PACKET3_CLEAR_STATE, 0));
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_SET_CONTEXT_REG, 2));
radeon_ring_write(ring, 0x00000316);
radeon_ring_write(ring, 0x0000000e);
radeon_ring_write(ring, 0x00000010);
radeon_ring_unlock_commit(rdev, ring);
return 0;
}
static void cik_cp_gfx_fini(struct radeon_device *rdev)
{
cik_cp_gfx_enable(rdev, false);
radeon_ring_fini(rdev, &rdev->ring[RADEON_RING_TYPE_GFX_INDEX]);
}
static int cik_cp_gfx_resume(struct radeon_device *rdev)
{
struct radeon_ring *ring;
u32 tmp;
u32 rb_bufsz;
u64 rb_addr;
int r;
WREG32(CP_SEM_WAIT_TIMER, 0x0);
WREG32(CP_SEM_INCOMPLETE_TIMER_CNTL, 0x0);
WREG32(CP_RB_WPTR_DELAY, 0);
WREG32(CP_RB_VMID, 0);
WREG32(SCRATCH_ADDR, ((rdev->wb.gpu_addr + RADEON_WB_SCRATCH_OFFSET) >> 8) & 0xFFFFFFFF);
ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
rb_bufsz = drm_order(ring->ring_size / 8);
tmp = (drm_order(RADEON_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= BUF_SWAP_32BIT;
#endif
WREG32(CP_RB0_CNTL, tmp);
WREG32(CP_RB0_CNTL, tmp | RB_RPTR_WR_ENA);
ring->wptr = 0;
WREG32(CP_RB0_WPTR, ring->wptr);
WREG32(CP_RB0_RPTR_ADDR, (rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFFFFFFFC);
WREG32(CP_RB0_RPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + RADEON_WB_CP_RPTR_OFFSET) & 0xFF);
WREG32(SCRATCH_UMSK, 0);
if (!rdev->wb.enabled)
tmp |= RB_NO_UPDATE;
mdelay(1);
WREG32(CP_RB0_CNTL, tmp);
rb_addr = ring->gpu_addr >> 8;
WREG32(CP_RB0_BASE, rb_addr);
WREG32(CP_RB0_BASE_HI, upper_32_bits(rb_addr));
ring->rptr = RREG32(CP_RB0_RPTR);
cik_cp_gfx_start(rdev);
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = true;
r = radeon_ring_test(rdev, RADEON_RING_TYPE_GFX_INDEX, &rdev->ring[RADEON_RING_TYPE_GFX_INDEX]);
if (r) {
rdev->ring[RADEON_RING_TYPE_GFX_INDEX].ready = false;
return r;
}
return 0;
}
u32 cik_compute_ring_get_rptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 rptr;
if (rdev->wb.enabled) {
rptr = le32_to_cpu(rdev->wb.wb[ring->rptr_offs/4]);
} else {
mutex_lock(&rdev->srbm_mutex);
cik_srbm_select(rdev, ring->me, ring->pipe, ring->queue, 0);
rptr = RREG32(CP_HQD_PQ_RPTR);
cik_srbm_select(rdev, 0, 0, 0, 0);
mutex_unlock(&rdev->srbm_mutex);
}
rptr = (rptr & ring->ptr_reg_mask) >> ring->ptr_reg_shift;
return rptr;
}
u32 cik_compute_ring_get_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 wptr;
if (rdev->wb.enabled) {
wptr = le32_to_cpu(rdev->wb.wb[ring->wptr_offs/4]);
} else {
mutex_lock(&rdev->srbm_mutex);
cik_srbm_select(rdev, ring->me, ring->pipe, ring->queue, 0);
wptr = RREG32(CP_HQD_PQ_WPTR);
cik_srbm_select(rdev, 0, 0, 0, 0);
mutex_unlock(&rdev->srbm_mutex);
}
wptr = (wptr & ring->ptr_reg_mask) >> ring->ptr_reg_shift;
return wptr;
}
void cik_compute_ring_set_wptr(struct radeon_device *rdev,
struct radeon_ring *ring)
{
u32 wptr = (ring->wptr << ring->ptr_reg_shift) & ring->ptr_reg_mask;
rdev->wb.wb[ring->wptr_offs/4] = cpu_to_le32(wptr);
WDOORBELL32(ring->doorbell_offset, wptr);
}
static void cik_cp_compute_enable(struct radeon_device *rdev, bool enable)
{
if (enable)
WREG32(CP_MEC_CNTL, 0);
else
WREG32(CP_MEC_CNTL, (MEC_ME1_HALT | MEC_ME2_HALT));
udelay(50);
}
static int cik_cp_compute_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->mec_fw)
return -EINVAL;
cik_cp_compute_enable(rdev, false);
fw_data = (const __be32 *)rdev->mec_fw->data;
WREG32(CP_MEC_ME1_UCODE_ADDR, 0);
for (i = 0; i < CIK_MEC_UCODE_SIZE; i++)
WREG32(CP_MEC_ME1_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(CP_MEC_ME1_UCODE_ADDR, 0);
if (rdev->family == CHIP_KAVERI) {
fw_data = (const __be32 *)rdev->mec_fw->data;
WREG32(CP_MEC_ME2_UCODE_ADDR, 0);
for (i = 0; i < CIK_MEC_UCODE_SIZE; i++)
WREG32(CP_MEC_ME2_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(CP_MEC_ME2_UCODE_ADDR, 0);
}
return 0;
}
static int cik_cp_compute_start(struct radeon_device *rdev)
{
cik_cp_compute_enable(rdev, true);
return 0;
}
static void cik_cp_compute_fini(struct radeon_device *rdev)
{
int i, idx, r;
cik_cp_compute_enable(rdev, false);
for (i = 0; i < 2; i++) {
if (i == 0)
idx = CAYMAN_RING_TYPE_CP1_INDEX;
else
idx = CAYMAN_RING_TYPE_CP2_INDEX;
if (rdev->ring[idx].mqd_obj) {
r = radeon_bo_reserve(rdev->ring[idx].mqd_obj, false);
if (unlikely(r != 0))
dev_warn(rdev->dev, "(%d) reserve MQD bo failed\n", r);
radeon_bo_unpin(rdev->ring[idx].mqd_obj);
radeon_bo_unreserve(rdev->ring[idx].mqd_obj);
radeon_bo_unref(&rdev->ring[idx].mqd_obj);
rdev->ring[idx].mqd_obj = NULL;
}
}
}
static void cik_mec_fini(struct radeon_device *rdev)
{
int r;
if (rdev->mec.hpd_eop_obj) {
r = radeon_bo_reserve(rdev->mec.hpd_eop_obj, false);
if (unlikely(r != 0))
dev_warn(rdev->dev, "(%d) reserve HPD EOP bo failed\n", r);
radeon_bo_unpin(rdev->mec.hpd_eop_obj);
radeon_bo_unreserve(rdev->mec.hpd_eop_obj);
radeon_bo_unref(&rdev->mec.hpd_eop_obj);
rdev->mec.hpd_eop_obj = NULL;
}
}
static int cik_mec_init(struct radeon_device *rdev)
{
int r;
u32 *hpd;
if (rdev->family == CHIP_KAVERI)
rdev->mec.num_mec = 2;
else
rdev->mec.num_mec = 1;
rdev->mec.num_pipe = 4;
rdev->mec.num_queue = rdev->mec.num_mec * rdev->mec.num_pipe * 8;
if (rdev->mec.hpd_eop_obj == NULL) {
r = radeon_bo_create(rdev,
rdev->mec.num_mec *rdev->mec.num_pipe * MEC_HPD_SIZE * 2,
PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT, NULL,
&rdev->mec.hpd_eop_obj);
if (r) {
dev_warn(rdev->dev, "(%d) create HDP EOP bo failed\n", r);
return r;
}
}
r = radeon_bo_reserve(rdev->mec.hpd_eop_obj, false);
if (unlikely(r != 0)) {
cik_mec_fini(rdev);
return r;
}
r = radeon_bo_pin(rdev->mec.hpd_eop_obj, RADEON_GEM_DOMAIN_GTT,
&rdev->mec.hpd_eop_gpu_addr);
if (r) {
dev_warn(rdev->dev, "(%d) pin HDP EOP bo failed\n", r);
cik_mec_fini(rdev);
return r;
}
r = radeon_bo_kmap(rdev->mec.hpd_eop_obj, (void **)&hpd);
if (r) {
dev_warn(rdev->dev, "(%d) map HDP EOP bo failed\n", r);
cik_mec_fini(rdev);
return r;
}
memset(hpd, 0, rdev->mec.num_mec *rdev->mec.num_pipe * MEC_HPD_SIZE * 2);
radeon_bo_kunmap(rdev->mec.hpd_eop_obj);
radeon_bo_unreserve(rdev->mec.hpd_eop_obj);
return 0;
}
static int cik_cp_compute_resume(struct radeon_device *rdev)
{
int r, i, idx;
u32 tmp;
bool use_doorbell = true;
u64 hqd_gpu_addr;
u64 mqd_gpu_addr;
u64 eop_gpu_addr;
u64 wb_gpu_addr;
u32 *buf;
struct bonaire_mqd *mqd;
r = cik_cp_compute_start(rdev);
if (r)
return r;
tmp = RREG32(CP_CPF_DEBUG);
tmp |= (1 << 23);
WREG32(CP_CPF_DEBUG, tmp);
mutex_lock(&rdev->srbm_mutex);
for (i = 0; i < (rdev->mec.num_pipe * rdev->mec.num_mec); i++) {
int me = (i < 4) ? 1 : 2;
int pipe = (i < 4) ? i : (i - 4);
eop_gpu_addr = rdev->mec.hpd_eop_gpu_addr + (i * MEC_HPD_SIZE * 2);
cik_srbm_select(rdev, me, pipe, 0, 0);
WREG32(CP_HPD_EOP_BASE_ADDR, eop_gpu_addr >> 8);
WREG32(CP_HPD_EOP_BASE_ADDR_HI, upper_32_bits(eop_gpu_addr) >> 8);
WREG32(CP_HPD_EOP_VMID, 0);
tmp = RREG32(CP_HPD_EOP_CONTROL);
tmp &= ~EOP_SIZE_MASK;
tmp |= drm_order(MEC_HPD_SIZE / 8);
WREG32(CP_HPD_EOP_CONTROL, tmp);
}
cik_srbm_select(rdev, 0, 0, 0, 0);
mutex_unlock(&rdev->srbm_mutex);
for (i = 0; i < 2; i++) {
if (i == 0)
idx = CAYMAN_RING_TYPE_CP1_INDEX;
else
idx = CAYMAN_RING_TYPE_CP2_INDEX;
if (rdev->ring[idx].mqd_obj == NULL) {
r = radeon_bo_create(rdev,
sizeof(struct bonaire_mqd),
PAGE_SIZE, true,
RADEON_GEM_DOMAIN_GTT, NULL,
&rdev->ring[idx].mqd_obj);
if (r) {
dev_warn(rdev->dev, "(%d) create MQD bo failed\n", r);
return r;
}
}
r = radeon_bo_reserve(rdev->ring[idx].mqd_obj, false);
if (unlikely(r != 0)) {
cik_cp_compute_fini(rdev);
return r;
}
r = radeon_bo_pin(rdev->ring[idx].mqd_obj, RADEON_GEM_DOMAIN_GTT,
&mqd_gpu_addr);
if (r) {
dev_warn(rdev->dev, "(%d) pin MQD bo failed\n", r);
cik_cp_compute_fini(rdev);
return r;
}
r = radeon_bo_kmap(rdev->ring[idx].mqd_obj, (void **)&buf);
if (r) {
dev_warn(rdev->dev, "(%d) map MQD bo failed\n", r);
cik_cp_compute_fini(rdev);
return r;
}
rdev->ring[idx].doorbell_offset =
(rdev->ring[idx].doorbell_page_num * PAGE_SIZE) + 0;
memset(buf, 0, sizeof(struct bonaire_mqd));
mqd = (struct bonaire_mqd *)buf;
mqd->header = 0xC0310800;
mqd->static_thread_mgmt01[0] = 0xffffffff;
mqd->static_thread_mgmt01[1] = 0xffffffff;
mqd->static_thread_mgmt23[0] = 0xffffffff;
mqd->static_thread_mgmt23[1] = 0xffffffff;
mutex_lock(&rdev->srbm_mutex);
cik_srbm_select(rdev, rdev->ring[idx].me,
rdev->ring[idx].pipe,
rdev->ring[idx].queue, 0);
tmp = RREG32(CP_PQ_WPTR_POLL_CNTL);
tmp &= ~WPTR_POLL_EN;
WREG32(CP_PQ_WPTR_POLL_CNTL, tmp);
mqd->queue_state.cp_hqd_pq_doorbell_control =
RREG32(CP_HQD_PQ_DOORBELL_CONTROL);
if (use_doorbell)
mqd->queue_state.cp_hqd_pq_doorbell_control |= DOORBELL_EN;
else
mqd->queue_state.cp_hqd_pq_doorbell_control &= ~DOORBELL_EN;
WREG32(CP_HQD_PQ_DOORBELL_CONTROL,
mqd->queue_state.cp_hqd_pq_doorbell_control);
mqd->queue_state.cp_hqd_dequeue_request = 0;
mqd->queue_state.cp_hqd_pq_rptr = 0;
mqd->queue_state.cp_hqd_pq_wptr= 0;
if (RREG32(CP_HQD_ACTIVE) & 1) {
WREG32(CP_HQD_DEQUEUE_REQUEST, 1);
for (i = 0; i < rdev->usec_timeout; i++) {
if (!(RREG32(CP_HQD_ACTIVE) & 1))
break;
udelay(1);
}
WREG32(CP_HQD_DEQUEUE_REQUEST, mqd->queue_state.cp_hqd_dequeue_request);
WREG32(CP_HQD_PQ_RPTR, mqd->queue_state.cp_hqd_pq_rptr);
WREG32(CP_HQD_PQ_WPTR, mqd->queue_state.cp_hqd_pq_wptr);
}
mqd->queue_state.cp_mqd_base_addr = mqd_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_mqd_base_addr_hi = upper_32_bits(mqd_gpu_addr);
WREG32(CP_MQD_BASE_ADDR, mqd->queue_state.cp_mqd_base_addr);
WREG32(CP_MQD_BASE_ADDR_HI, mqd->queue_state.cp_mqd_base_addr_hi);
mqd->queue_state.cp_mqd_control = RREG32(CP_MQD_CONTROL);
mqd->queue_state.cp_mqd_control &= ~MQD_VMID_MASK;
WREG32(CP_MQD_CONTROL, mqd->queue_state.cp_mqd_control);
hqd_gpu_addr = rdev->ring[idx].gpu_addr >> 8;
mqd->queue_state.cp_hqd_pq_base = hqd_gpu_addr;
mqd->queue_state.cp_hqd_pq_base_hi = upper_32_bits(hqd_gpu_addr);
WREG32(CP_HQD_PQ_BASE, mqd->queue_state.cp_hqd_pq_base);
WREG32(CP_HQD_PQ_BASE_HI, mqd->queue_state.cp_hqd_pq_base_hi);
mqd->queue_state.cp_hqd_pq_control = RREG32(CP_HQD_PQ_CONTROL);
mqd->queue_state.cp_hqd_pq_control &=
~(QUEUE_SIZE_MASK | RPTR_BLOCK_SIZE_MASK);
mqd->queue_state.cp_hqd_pq_control |=
drm_order(rdev->ring[idx].ring_size / 8);
mqd->queue_state.cp_hqd_pq_control |=
(drm_order(RADEON_GPU_PAGE_SIZE/8) << 8);
#ifdef __BIG_ENDIAN
mqd->queue_state.cp_hqd_pq_control |= BUF_SWAP_32BIT;
#endif
mqd->queue_state.cp_hqd_pq_control &=
~(UNORD_DISPATCH | ROQ_PQ_IB_FLIP | PQ_VOLATILE);
mqd->queue_state.cp_hqd_pq_control |=
PRIV_STATE | KMD_QUEUE;
WREG32(CP_HQD_PQ_CONTROL, mqd->queue_state.cp_hqd_pq_control);
if (i == 0)
wb_gpu_addr = rdev->wb.gpu_addr + CIK_WB_CP1_WPTR_OFFSET;
else
wb_gpu_addr = rdev->wb.gpu_addr + CIK_WB_CP2_WPTR_OFFSET;
mqd->queue_state.cp_hqd_pq_wptr_poll_addr = wb_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_hqd_pq_wptr_poll_addr_hi = upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(CP_HQD_PQ_WPTR_POLL_ADDR, mqd->queue_state.cp_hqd_pq_wptr_poll_addr);
WREG32(CP_HQD_PQ_WPTR_POLL_ADDR_HI,
mqd->queue_state.cp_hqd_pq_wptr_poll_addr_hi);
if (i == 0)
wb_gpu_addr = rdev->wb.gpu_addr + RADEON_WB_CP1_RPTR_OFFSET;
else
wb_gpu_addr = rdev->wb.gpu_addr + RADEON_WB_CP2_RPTR_OFFSET;
mqd->queue_state.cp_hqd_pq_rptr_report_addr = wb_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_hqd_pq_rptr_report_addr_hi =
upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(CP_HQD_PQ_RPTR_REPORT_ADDR,
mqd->queue_state.cp_hqd_pq_rptr_report_addr);
WREG32(CP_HQD_PQ_RPTR_REPORT_ADDR_HI,
mqd->queue_state.cp_hqd_pq_rptr_report_addr_hi);
if (use_doorbell) {
mqd->queue_state.cp_hqd_pq_doorbell_control =
RREG32(CP_HQD_PQ_DOORBELL_CONTROL);
mqd->queue_state.cp_hqd_pq_doorbell_control &= ~DOORBELL_OFFSET_MASK;
mqd->queue_state.cp_hqd_pq_doorbell_control |=
DOORBELL_OFFSET(rdev->ring[idx].doorbell_offset / 4);
mqd->queue_state.cp_hqd_pq_doorbell_control |= DOORBELL_EN;
mqd->queue_state.cp_hqd_pq_doorbell_control &=
~(DOORBELL_SOURCE | DOORBELL_HIT);
} else {
mqd->queue_state.cp_hqd_pq_doorbell_control = 0;
}
WREG32(CP_HQD_PQ_DOORBELL_CONTROL,
mqd->queue_state.cp_hqd_pq_doorbell_control);
rdev->ring[idx].wptr = 0;
mqd->queue_state.cp_hqd_pq_wptr = rdev->ring[idx].wptr;
WREG32(CP_HQD_PQ_WPTR, mqd->queue_state.cp_hqd_pq_wptr);
rdev->ring[idx].rptr = RREG32(CP_HQD_PQ_RPTR);
mqd->queue_state.cp_hqd_pq_rptr = rdev->ring[idx].rptr;
mqd->queue_state.cp_hqd_vmid = 0;
WREG32(CP_HQD_VMID, mqd->queue_state.cp_hqd_vmid);
mqd->queue_state.cp_hqd_active = 1;
WREG32(CP_HQD_ACTIVE, mqd->queue_state.cp_hqd_active);
cik_srbm_select(rdev, 0, 0, 0, 0);
mutex_unlock(&rdev->srbm_mutex);
radeon_bo_kunmap(rdev->ring[idx].mqd_obj);
radeon_bo_unreserve(rdev->ring[idx].mqd_obj);
rdev->ring[idx].ready = true;
r = radeon_ring_test(rdev, idx, &rdev->ring[idx]);
if (r)
rdev->ring[idx].ready = false;
}
return 0;
}
static void cik_cp_enable(struct radeon_device *rdev, bool enable)
{
cik_cp_gfx_enable(rdev, enable);
cik_cp_compute_enable(rdev, enable);
}
static int cik_cp_load_microcode(struct radeon_device *rdev)
{
int r;
r = cik_cp_gfx_load_microcode(rdev);
if (r)
return r;
r = cik_cp_compute_load_microcode(rdev);
if (r)
return r;
return 0;
}
static void cik_cp_fini(struct radeon_device *rdev)
{
cik_cp_gfx_fini(rdev);
cik_cp_compute_fini(rdev);
}
static int cik_cp_resume(struct radeon_device *rdev)
{
int r;
WREG32(GRBM_SOFT_RESET, SOFT_RESET_CP);
RREG32(GRBM_SOFT_RESET);
mdelay(15);
WREG32(GRBM_SOFT_RESET, 0);
RREG32(GRBM_SOFT_RESET);
r = cik_cp_load_microcode(rdev);
if (r)
return r;
r = cik_cp_gfx_resume(rdev);
if (r)
return r;
r = cik_cp_compute_resume(rdev);
if (r)
return r;
return 0;
}
void cik_sdma_ring_ib_execute(struct radeon_device *rdev,
struct radeon_ib *ib)
{
struct radeon_ring *ring = &rdev->ring[ib->ring];
u32 extra_bits = (ib->vm ? ib->vm->id : 0) & 0xf;
if (rdev->wb.enabled) {
u32 next_rptr = ring->wptr + 5;
while ((next_rptr & 7) != 4)
next_rptr++;
next_rptr += 4;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xffffffff);
radeon_ring_write(ring, 1);
radeon_ring_write(ring, next_rptr);
}
while ((ring->wptr & 7) != 4)
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_INDIRECT_BUFFER, 0, extra_bits));
radeon_ring_write(ring, ib->gpu_addr & 0xffffffe0);
radeon_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xffffffff);
radeon_ring_write(ring, ib->length_dw);
}
void cik_sdma_fence_ring_emit(struct radeon_device *rdev,
struct radeon_fence *fence)
{
struct radeon_ring *ring = &rdev->ring[fence->ring];
u64 addr = rdev->fence_drv[fence->ring].gpu_addr;
u32 extra_bits = (SDMA_POLL_REG_MEM_EXTRA_OP(1) |
SDMA_POLL_REG_MEM_EXTRA_FUNC(3));
u32 ref_and_mask;
if (fence->ring == R600_RING_TYPE_DMA_INDEX)
ref_and_mask = SDMA0;
else
ref_and_mask = SDMA1;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_FENCE, 0, 0));
radeon_ring_write(ring, addr & 0xffffffff);
radeon_ring_write(ring, upper_32_bits(addr) & 0xffffffff);
radeon_ring_write(ring, fence->seq);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_TRAP, 0, 0));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_POLL_REG_MEM, 0, extra_bits));
radeon_ring_write(ring, GPU_HDP_FLUSH_DONE);
radeon_ring_write(ring, GPU_HDP_FLUSH_REQ);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, (4 << 16) | 10);
}
void cik_sdma_semaphore_ring_emit(struct radeon_device *rdev,
struct radeon_ring *ring,
struct radeon_semaphore *semaphore,
bool emit_wait)
{
u64 addr = semaphore->gpu_addr;
u32 extra_bits = emit_wait ? 0 : SDMA_SEMAPHORE_EXTRA_S;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SEMAPHORE, 0, extra_bits));
radeon_ring_write(ring, addr & 0xfffffff8);
radeon_ring_write(ring, upper_32_bits(addr) & 0xffffffff);
}
static void cik_sdma_gfx_stop(struct radeon_device *rdev)
{
u32 rb_cntl, reg_offset;
int i;
radeon_ttm_set_active_vram_size(rdev, rdev->mc.visible_vram_size);
for (i = 0; i < 2; i++) {
if (i == 0)
reg_offset = SDMA0_REGISTER_OFFSET;
else
reg_offset = SDMA1_REGISTER_OFFSET;
rb_cntl = RREG32(SDMA0_GFX_RB_CNTL + reg_offset);
rb_cntl &= ~SDMA_RB_ENABLE;
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl);
WREG32(SDMA0_GFX_IB_CNTL + reg_offset, 0);
}
}
static void cik_sdma_rlc_stop(struct radeon_device *rdev)
{
}
static void cik_sdma_enable(struct radeon_device *rdev, bool enable)
{
u32 me_cntl, reg_offset;
int i;
for (i = 0; i < 2; i++) {
if (i == 0)
reg_offset = SDMA0_REGISTER_OFFSET;
else
reg_offset = SDMA1_REGISTER_OFFSET;
me_cntl = RREG32(SDMA0_ME_CNTL + reg_offset);
if (enable)
me_cntl &= ~SDMA_HALT;
else
me_cntl |= SDMA_HALT;
WREG32(SDMA0_ME_CNTL + reg_offset, me_cntl);
}
}
static int cik_sdma_gfx_resume(struct radeon_device *rdev)
{
struct radeon_ring *ring;
u32 rb_cntl, ib_cntl;
u32 rb_bufsz;
u32 reg_offset, wb_offset;
int i, r;
for (i = 0; i < 2; i++) {
if (i == 0) {
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
reg_offset = SDMA0_REGISTER_OFFSET;
wb_offset = R600_WB_DMA_RPTR_OFFSET;
} else {
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
reg_offset = SDMA1_REGISTER_OFFSET;
wb_offset = CAYMAN_WB_DMA1_RPTR_OFFSET;
}
WREG32(SDMA0_SEM_INCOMPLETE_TIMER_CNTL + reg_offset, 0);
WREG32(SDMA0_SEM_WAIT_FAIL_TIMER_CNTL + reg_offset, 0);
rb_bufsz = drm_order(ring->ring_size / 4);
rb_cntl = rb_bufsz << 1;
#ifdef __BIG_ENDIAN
rb_cntl |= SDMA_RB_SWAP_ENABLE | SDMA_RPTR_WRITEBACK_SWAP_ENABLE;
#endif
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl);
WREG32(SDMA0_GFX_RB_RPTR + reg_offset, 0);
WREG32(SDMA0_GFX_RB_WPTR + reg_offset, 0);
WREG32(SDMA0_GFX_RB_RPTR_ADDR_HI + reg_offset,
upper_32_bits(rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFF);
WREG32(SDMA0_GFX_RB_RPTR_ADDR_LO + reg_offset,
((rdev->wb.gpu_addr + wb_offset) & 0xFFFFFFFC));
if (rdev->wb.enabled)
rb_cntl |= SDMA_RPTR_WRITEBACK_ENABLE;
WREG32(SDMA0_GFX_RB_BASE + reg_offset, ring->gpu_addr >> 8);
WREG32(SDMA0_GFX_RB_BASE_HI + reg_offset, ring->gpu_addr >> 40);
ring->wptr = 0;
WREG32(SDMA0_GFX_RB_WPTR + reg_offset, ring->wptr << 2);
ring->rptr = RREG32(SDMA0_GFX_RB_RPTR + reg_offset) >> 2;
WREG32(SDMA0_GFX_RB_CNTL + reg_offset, rb_cntl | SDMA_RB_ENABLE);
ib_cntl = SDMA_IB_ENABLE;
#ifdef __BIG_ENDIAN
ib_cntl |= SDMA_IB_SWAP_ENABLE;
#endif
WREG32(SDMA0_GFX_IB_CNTL + reg_offset, ib_cntl);
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
static int cik_sdma_rlc_resume(struct radeon_device *rdev)
{
return 0;
}
static int cik_sdma_load_microcode(struct radeon_device *rdev)
{
const __be32 *fw_data;
int i;
if (!rdev->sdma_fw)
return -EINVAL;
cik_sdma_gfx_stop(rdev);
cik_sdma_rlc_stop(rdev);
cik_sdma_enable(rdev, false);
fw_data = (const __be32 *)rdev->sdma_fw->data;
WREG32(SDMA0_UCODE_ADDR + SDMA0_REGISTER_OFFSET, 0);
for (i = 0; i < CIK_SDMA_UCODE_SIZE; i++)
WREG32(SDMA0_UCODE_DATA + SDMA0_REGISTER_OFFSET, be32_to_cpup(fw_data++));
WREG32(SDMA0_UCODE_DATA + SDMA0_REGISTER_OFFSET, CIK_SDMA_UCODE_VERSION);
fw_data = (const __be32 *)rdev->sdma_fw->data;
WREG32(SDMA0_UCODE_ADDR + SDMA1_REGISTER_OFFSET, 0);
for (i = 0; i < CIK_SDMA_UCODE_SIZE; i++)
WREG32(SDMA0_UCODE_DATA + SDMA1_REGISTER_OFFSET, be32_to_cpup(fw_data++));
WREG32(SDMA0_UCODE_DATA + SDMA1_REGISTER_OFFSET, CIK_SDMA_UCODE_VERSION);
WREG32(SDMA0_UCODE_ADDR + SDMA0_REGISTER_OFFSET, 0);
WREG32(SDMA0_UCODE_ADDR + SDMA1_REGISTER_OFFSET, 0);
return 0;
}
static int cik_sdma_resume(struct radeon_device *rdev)
{
int r;
WREG32(SRBM_SOFT_RESET, SOFT_RESET_SDMA | SOFT_RESET_SDMA1);
RREG32(SRBM_SOFT_RESET);
udelay(50);
WREG32(SRBM_SOFT_RESET, 0);
RREG32(SRBM_SOFT_RESET);
r = cik_sdma_load_microcode(rdev);
if (r)
return r;
cik_sdma_enable(rdev, true);
r = cik_sdma_gfx_resume(rdev);
if (r)
return r;
r = cik_sdma_rlc_resume(rdev);
if (r)
return r;
return 0;
}
static void cik_sdma_fini(struct radeon_device *rdev)
{
cik_sdma_gfx_stop(rdev);
cik_sdma_rlc_stop(rdev);
cik_sdma_enable(rdev, false);
radeon_ring_fini(rdev, &rdev->ring[R600_RING_TYPE_DMA_INDEX]);
radeon_ring_fini(rdev, &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX]);
}
int cik_copy_dma(struct radeon_device *rdev,
uint64_t src_offset, uint64_t dst_offset,
unsigned num_gpu_pages,
struct radeon_fence **fence)
{
struct radeon_semaphore *sem = NULL;
int ring_index = rdev->asic->copy.dma_ring_index;
struct radeon_ring *ring = &rdev->ring[ring_index];
u32 size_in_bytes, cur_size_in_bytes;
int i, num_loops;
int r = 0;
r = radeon_semaphore_create(rdev, &sem);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
return r;
}
size_in_bytes = (num_gpu_pages << RADEON_GPU_PAGE_SHIFT);
num_loops = DIV_ROUND_UP(size_in_bytes, 0x1fffff);
r = radeon_ring_lock(rdev, ring, num_loops * 7 + 14);
if (r) {
DRM_ERROR("radeon: moving bo (%d).\n", r);
radeon_semaphore_free(rdev, &sem, NULL);
return r;
}
if (radeon_fence_need_sync(*fence, ring->idx)) {
radeon_semaphore_sync_rings(rdev, sem, (*fence)->ring,
ring->idx);
radeon_fence_note_sync(*fence, ring->idx);
} else {
radeon_semaphore_free(rdev, &sem, NULL);
}
for (i = 0; i < num_loops; i++) {
cur_size_in_bytes = size_in_bytes;
if (cur_size_in_bytes > 0x1fffff)
cur_size_in_bytes = 0x1fffff;
size_in_bytes -= cur_size_in_bytes;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_COPY, SDMA_COPY_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, cur_size_in_bytes);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, src_offset & 0xffffffff);
radeon_ring_write(ring, upper_32_bits(src_offset) & 0xffffffff);
radeon_ring_write(ring, dst_offset & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(dst_offset) & 0xffffffff);
src_offset += cur_size_in_bytes;
dst_offset += cur_size_in_bytes;
}
r = radeon_fence_emit(rdev, fence, ring->idx);
if (r) {
radeon_ring_unlock_undo(rdev, ring);
return r;
}
radeon_ring_unlock_commit(rdev, ring);
radeon_semaphore_free(rdev, &sem, *fence);
return r;
}
int cik_sdma_ring_test(struct radeon_device *rdev,
struct radeon_ring *ring)
{
unsigned i;
int r;
void __iomem *ptr = (void *)rdev->vram_scratch.ptr;
u32 tmp;
if (!ptr) {
DRM_ERROR("invalid vram scratch pointer\n");
return -EINVAL;
}
tmp = 0xCAFEDEAD;
writel(tmp, ptr);
r = radeon_ring_lock(rdev, ring, 4);
if (r) {
DRM_ERROR("radeon: dma failed to lock ring %d (%d).\n", ring->idx, r);
return r;
}
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0));
radeon_ring_write(ring, rdev->vram_scratch.gpu_addr & 0xfffffffc);
radeon_ring_write(ring, upper_32_bits(rdev->vram_scratch.gpu_addr) & 0xffffffff);
radeon_ring_write(ring, 1);
radeon_ring_write(ring, 0xDEADBEEF);
radeon_ring_unlock_commit(rdev, ring);
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = readl(ptr);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n", ring->idx, i);
} else {
DRM_ERROR("radeon: ring %d test failed (0x%08X)\n",
ring->idx, tmp);
r = -EINVAL;
}
return r;
}
int cik_sdma_ib_test(struct radeon_device *rdev, struct radeon_ring *ring)
{
struct radeon_ib ib;
unsigned i;
int r;
void __iomem *ptr = (void *)rdev->vram_scratch.ptr;
u32 tmp = 0;
if (!ptr) {
DRM_ERROR("invalid vram scratch pointer\n");
return -EINVAL;
}
tmp = 0xCAFEDEAD;
writel(tmp, ptr);
r = radeon_ib_get(rdev, ring->idx, &ib, NULL, 256);
if (r) {
DRM_ERROR("radeon: failed to get ib (%d).\n", r);
return r;
}
ib.ptr[0] = SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0);
ib.ptr[1] = rdev->vram_scratch.gpu_addr & 0xfffffffc;
ib.ptr[2] = upper_32_bits(rdev->vram_scratch.gpu_addr) & 0xffffffff;
ib.ptr[3] = 1;
ib.ptr[4] = 0xDEADBEEF;
ib.length_dw = 5;
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r) {
radeon_ib_free(rdev, &ib);
DRM_ERROR("radeon: failed to schedule ib (%d).\n", r);
return r;
}
r = radeon_fence_wait(ib.fence, false);
if (r) {
DRM_ERROR("radeon: fence wait failed (%d).\n", r);
return r;
}
for (i = 0; i < rdev->usec_timeout; i++) {
tmp = readl(ptr);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < rdev->usec_timeout) {
DRM_INFO("ib test on ring %d succeeded in %u usecs\n", ib.fence->ring, i);
} else {
DRM_ERROR("radeon: ib test failed (0x%08X)\n", tmp);
r = -EINVAL;
}
radeon_ib_free(rdev, &ib);
return r;
}
static void cik_print_gpu_status_regs(struct radeon_device *rdev)
{
dev_info(rdev->dev, " GRBM_STATUS=0x%08X\n",
RREG32(GRBM_STATUS));
dev_info(rdev->dev, " GRBM_STATUS2=0x%08X\n",
RREG32(GRBM_STATUS2));
dev_info(rdev->dev, " GRBM_STATUS_SE0=0x%08X\n",
RREG32(GRBM_STATUS_SE0));
dev_info(rdev->dev, " GRBM_STATUS_SE1=0x%08X\n",
RREG32(GRBM_STATUS_SE1));
dev_info(rdev->dev, " GRBM_STATUS_SE2=0x%08X\n",
RREG32(GRBM_STATUS_SE2));
dev_info(rdev->dev, " GRBM_STATUS_SE3=0x%08X\n",
RREG32(GRBM_STATUS_SE3));
dev_info(rdev->dev, " SRBM_STATUS=0x%08X\n",
RREG32(SRBM_STATUS));
dev_info(rdev->dev, " SRBM_STATUS2=0x%08X\n",
RREG32(SRBM_STATUS2));
dev_info(rdev->dev, " SDMA0_STATUS_REG = 0x%08X\n",
RREG32(SDMA0_STATUS_REG + SDMA0_REGISTER_OFFSET));
dev_info(rdev->dev, " SDMA1_STATUS_REG = 0x%08X\n",
RREG32(SDMA0_STATUS_REG + SDMA1_REGISTER_OFFSET));
dev_info(rdev->dev, " CP_STAT = 0x%08x\n", RREG32(CP_STAT));
dev_info(rdev->dev, " CP_STALLED_STAT1 = 0x%08x\n",
RREG32(CP_STALLED_STAT1));
dev_info(rdev->dev, " CP_STALLED_STAT2 = 0x%08x\n",
RREG32(CP_STALLED_STAT2));
dev_info(rdev->dev, " CP_STALLED_STAT3 = 0x%08x\n",
RREG32(CP_STALLED_STAT3));
dev_info(rdev->dev, " CP_CPF_BUSY_STAT = 0x%08x\n",
RREG32(CP_CPF_BUSY_STAT));
dev_info(rdev->dev, " CP_CPF_STALLED_STAT1 = 0x%08x\n",
RREG32(CP_CPF_STALLED_STAT1));
dev_info(rdev->dev, " CP_CPF_STATUS = 0x%08x\n", RREG32(CP_CPF_STATUS));
dev_info(rdev->dev, " CP_CPC_BUSY_STAT = 0x%08x\n", RREG32(CP_CPC_BUSY_STAT));
dev_info(rdev->dev, " CP_CPC_STALLED_STAT1 = 0x%08x\n",
RREG32(CP_CPC_STALLED_STAT1));
dev_info(rdev->dev, " CP_CPC_STATUS = 0x%08x\n", RREG32(CP_CPC_STATUS));
}
static u32 cik_gpu_check_soft_reset(struct radeon_device *rdev)
{
u32 reset_mask = 0;
u32 tmp;
tmp = RREG32(GRBM_STATUS);
if (tmp & (PA_BUSY | SC_BUSY |
BCI_BUSY | SX_BUSY |
TA_BUSY | VGT_BUSY |
DB_BUSY | CB_BUSY |
GDS_BUSY | SPI_BUSY |
IA_BUSY | IA_BUSY_NO_DMA))
reset_mask |= RADEON_RESET_GFX;
if (tmp & (CP_BUSY | CP_COHERENCY_BUSY))
reset_mask |= RADEON_RESET_CP;
tmp = RREG32(GRBM_STATUS2);
if (tmp & RLC_BUSY)
reset_mask |= RADEON_RESET_RLC;
tmp = RREG32(SDMA0_STATUS_REG + SDMA0_REGISTER_OFFSET);
if (!(tmp & SDMA_IDLE))
reset_mask |= RADEON_RESET_DMA;
tmp = RREG32(SDMA0_STATUS_REG + SDMA1_REGISTER_OFFSET);
if (!(tmp & SDMA_IDLE))
reset_mask |= RADEON_RESET_DMA1;
tmp = RREG32(SRBM_STATUS2);
if (tmp & SDMA_BUSY)
reset_mask |= RADEON_RESET_DMA;
if (tmp & SDMA1_BUSY)
reset_mask |= RADEON_RESET_DMA1;
tmp = RREG32(SRBM_STATUS);
if (tmp & IH_BUSY)
reset_mask |= RADEON_RESET_IH;
if (tmp & SEM_BUSY)
reset_mask |= RADEON_RESET_SEM;
if (tmp & GRBM_RQ_PENDING)
reset_mask |= RADEON_RESET_GRBM;
if (tmp & VMC_BUSY)
reset_mask |= RADEON_RESET_VMC;
if (tmp & (MCB_BUSY | MCB_NON_DISPLAY_BUSY |
MCC_BUSY | MCD_BUSY))
reset_mask |= RADEON_RESET_MC;
if (evergreen_is_display_hung(rdev))
reset_mask |= RADEON_RESET_DISPLAY;
if (reset_mask & RADEON_RESET_MC) {
DRM_DEBUG("MC busy: 0x%08X, clearing.\n", reset_mask);
reset_mask &= ~RADEON_RESET_MC;
}
return reset_mask;
}
static void cik_gpu_soft_reset(struct radeon_device *rdev, u32 reset_mask)
{
struct evergreen_mc_save save;
u32 grbm_soft_reset = 0, srbm_soft_reset = 0;
u32 tmp;
if (reset_mask == 0)
return;
dev_info(rdev->dev, "GPU softreset: 0x%08X\n", reset_mask);
cik_print_gpu_status_regs(rdev);
dev_info(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_ADDR 0x%08X\n",
RREG32(VM_CONTEXT1_PROTECTION_FAULT_ADDR));
dev_info(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_STATUS 0x%08X\n",
RREG32(VM_CONTEXT1_PROTECTION_FAULT_STATUS));
cik_rlc_stop(rdev);
WREG32(CP_ME_CNTL, CP_ME_HALT | CP_PFP_HALT | CP_CE_HALT);
WREG32(CP_MEC_CNTL, MEC_ME1_HALT | MEC_ME2_HALT);
if (reset_mask & RADEON_RESET_DMA) {
tmp = RREG32(SDMA0_ME_CNTL + SDMA0_REGISTER_OFFSET);
tmp |= SDMA_HALT;
WREG32(SDMA0_ME_CNTL + SDMA0_REGISTER_OFFSET, tmp);
}
if (reset_mask & RADEON_RESET_DMA1) {
tmp = RREG32(SDMA0_ME_CNTL + SDMA1_REGISTER_OFFSET);
tmp |= SDMA_HALT;
WREG32(SDMA0_ME_CNTL + SDMA1_REGISTER_OFFSET, tmp);
}
evergreen_mc_stop(rdev, &save);
if (evergreen_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
if (reset_mask & (RADEON_RESET_GFX | RADEON_RESET_COMPUTE | RADEON_RESET_CP))
grbm_soft_reset = SOFT_RESET_CP | SOFT_RESET_GFX;
if (reset_mask & RADEON_RESET_CP) {
grbm_soft_reset |= SOFT_RESET_CP;
srbm_soft_reset |= SOFT_RESET_GRBM;
}
if (reset_mask & RADEON_RESET_DMA)
srbm_soft_reset |= SOFT_RESET_SDMA;
if (reset_mask & RADEON_RESET_DMA1)
srbm_soft_reset |= SOFT_RESET_SDMA1;
if (reset_mask & RADEON_RESET_DISPLAY)
srbm_soft_reset |= SOFT_RESET_DC;
if (reset_mask & RADEON_RESET_RLC)
grbm_soft_reset |= SOFT_RESET_RLC;
if (reset_mask & RADEON_RESET_SEM)
srbm_soft_reset |= SOFT_RESET_SEM;
if (reset_mask & RADEON_RESET_IH)
srbm_soft_reset |= SOFT_RESET_IH;
if (reset_mask & RADEON_RESET_GRBM)
srbm_soft_reset |= SOFT_RESET_GRBM;
if (reset_mask & RADEON_RESET_VMC)
srbm_soft_reset |= SOFT_RESET_VMC;
if (!(rdev->flags & RADEON_IS_IGP)) {
if (reset_mask & RADEON_RESET_MC)
srbm_soft_reset |= SOFT_RESET_MC;
}
if (grbm_soft_reset) {
tmp = RREG32(GRBM_SOFT_RESET);
tmp |= grbm_soft_reset;
dev_info(rdev->dev, "GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(GRBM_SOFT_RESET, tmp);
tmp = RREG32(GRBM_SOFT_RESET);
udelay(50);
tmp &= ~grbm_soft_reset;
WREG32(GRBM_SOFT_RESET, tmp);
tmp = RREG32(GRBM_SOFT_RESET);
}
if (srbm_soft_reset) {
tmp = RREG32(SRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(rdev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(SRBM_SOFT_RESET, tmp);
tmp = RREG32(SRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(SRBM_SOFT_RESET, tmp);
tmp = RREG32(SRBM_SOFT_RESET);
}
udelay(50);
evergreen_mc_resume(rdev, &save);
udelay(50);
cik_print_gpu_status_regs(rdev);
}
int cik_asic_reset(struct radeon_device *rdev)
{
u32 reset_mask;
reset_mask = cik_gpu_check_soft_reset(rdev);
if (reset_mask)
r600_set_bios_scratch_engine_hung(rdev, true);
cik_gpu_soft_reset(rdev, reset_mask);
reset_mask = cik_gpu_check_soft_reset(rdev);
if (!reset_mask)
r600_set_bios_scratch_engine_hung(rdev, false);
return 0;
}
bool cik_gfx_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = cik_gpu_check_soft_reset(rdev);
if (!(reset_mask & (RADEON_RESET_GFX |
RADEON_RESET_COMPUTE |
RADEON_RESET_CP))) {
radeon_ring_lockup_update(ring);
return false;
}
radeon_ring_force_activity(rdev, ring);
return radeon_ring_test_lockup(rdev, ring);
}
bool cik_sdma_is_lockup(struct radeon_device *rdev, struct radeon_ring *ring)
{
u32 reset_mask = cik_gpu_check_soft_reset(rdev);
u32 mask;
if (ring->idx == R600_RING_TYPE_DMA_INDEX)
mask = RADEON_RESET_DMA;
else
mask = RADEON_RESET_DMA1;
if (!(reset_mask & mask)) {
radeon_ring_lockup_update(ring);
return false;
}
radeon_ring_force_activity(rdev, ring);
return radeon_ring_test_lockup(rdev, ring);
}
static void cik_mc_program(struct radeon_device *rdev)
{
struct evergreen_mc_save save;
u32 tmp;
int i, j;
for (i = 0, j = 0; i < 32; i++, j += 0x18) {
WREG32((0x2c14 + j), 0x00000000);
WREG32((0x2c18 + j), 0x00000000);
WREG32((0x2c1c + j), 0x00000000);
WREG32((0x2c20 + j), 0x00000000);
WREG32((0x2c24 + j), 0x00000000);
}
WREG32(HDP_REG_COHERENCY_FLUSH_CNTL, 0);
evergreen_mc_stop(rdev, &save);
if (radeon_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
WREG32(VGA_HDP_CONTROL, VGA_MEMORY_DISABLE);
WREG32(MC_VM_SYSTEM_APERTURE_LOW_ADDR,
rdev->mc.vram_start >> 12);
WREG32(MC_VM_SYSTEM_APERTURE_HIGH_ADDR,
rdev->mc.vram_end >> 12);
WREG32(MC_VM_SYSTEM_APERTURE_DEFAULT_ADDR,
rdev->vram_scratch.gpu_addr >> 12);
tmp = ((rdev->mc.vram_end >> 24) & 0xFFFF) << 16;
tmp |= ((rdev->mc.vram_start >> 24) & 0xFFFF);
WREG32(MC_VM_FB_LOCATION, tmp);
WREG32(HDP_NONSURFACE_BASE, (rdev->mc.vram_start >> 8));
WREG32(HDP_NONSURFACE_INFO, (2 << 7) | (1 << 30));
WREG32(HDP_NONSURFACE_SIZE, 0x3FFFFFFF);
WREG32(MC_VM_AGP_BASE, 0);
WREG32(MC_VM_AGP_TOP, 0x0FFFFFFF);
WREG32(MC_VM_AGP_BOT, 0x0FFFFFFF);
if (radeon_mc_wait_for_idle(rdev)) {
dev_warn(rdev->dev, "Wait for MC idle timedout !\n");
}
evergreen_mc_resume(rdev, &save);
rv515_vga_render_disable(rdev);
}
static int cik_mc_init(struct radeon_device *rdev)
{
u32 tmp;
int chansize, numchan;
rdev->mc.vram_is_ddr = true;
tmp = RREG32(MC_ARB_RAMCFG);
if (tmp & CHANSIZE_MASK) {
chansize = 64;
} else {
chansize = 32;
}
tmp = RREG32(MC_SHARED_CHMAP);
switch ((tmp & NOOFCHAN_MASK) >> NOOFCHAN_SHIFT) {
case 0:
default:
numchan = 1;
break;
case 1:
numchan = 2;
break;
case 2:
numchan = 4;
break;
case 3:
numchan = 8;
break;
case 4:
numchan = 3;
break;
case 5:
numchan = 6;
break;
case 6:
numchan = 10;
break;
case 7:
numchan = 12;
break;
case 8:
numchan = 16;
break;
}
rdev->mc.vram_width = numchan * chansize;
rdev->mc.aper_base = pci_resource_start(rdev->pdev, 0);
rdev->mc.aper_size = pci_resource_len(rdev->pdev, 0);
rdev->mc.mc_vram_size = RREG32(CONFIG_MEMSIZE) * 1024 * 1024;
rdev->mc.real_vram_size = RREG32(CONFIG_MEMSIZE) * 1024 * 1024;
rdev->mc.visible_vram_size = rdev->mc.aper_size;
si_vram_gtt_location(rdev, &rdev->mc);
radeon_update_bandwidth_info(rdev);
return 0;
}
void cik_pcie_gart_tlb_flush(struct radeon_device *rdev)
{
WREG32(HDP_MEM_COHERENCY_FLUSH_CNTL, 0);
WREG32(VM_INVALIDATE_REQUEST, 0x1);
}
static int cik_pcie_gart_enable(struct radeon_device *rdev)
{
int r, i;
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
SYSTEM_ACCESS_MODE_NOT_IN_SYS |
ENABLE_ADVANCED_DRIVER_MODEL |
SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU);
WREG32(VM_L2_CNTL, ENABLE_L2_CACHE |
ENABLE_L2_FRAGMENT_PROCESSING |
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
WREG32(VM_CONTEXT0_CNTL, (ENABLE_CONTEXT | PAGE_TABLE_DEPTH(0) |
RANGE_PROTECTION_FAULT_ENABLE_DEFAULT));
WREG32(0x15D4, 0);
WREG32(0x15D8, 0);
WREG32(0x15DC, 0);
WREG32(VM_CONTEXT1_PAGE_TABLE_START_ADDR, 0);
WREG32(VM_CONTEXT1_PAGE_TABLE_END_ADDR, rdev->vm_manager.max_pfn);
for (i = 1; i < 16; i++) {
if (i < 8)
WREG32(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (i << 2),
rdev->gart.table_addr >> 12);
else
WREG32(VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((i - 8) << 2),
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
WREG32(TC_CFG_L1_LOAD_POLICY0, 0);
WREG32(TC_CFG_L1_LOAD_POLICY1, 0);
WREG32(TC_CFG_L1_STORE_POLICY, 0);
WREG32(TC_CFG_L2_LOAD_POLICY0, 0);
WREG32(TC_CFG_L2_LOAD_POLICY1, 0);
WREG32(TC_CFG_L2_STORE_POLICY0, 0);
WREG32(TC_CFG_L2_STORE_POLICY1, 0);
WREG32(TC_CFG_L2_ATOMIC_POLICY, 0);
WREG32(TC_CFG_L1_VOLATILE, 0);
WREG32(TC_CFG_L2_VOLATILE, 0);
if (rdev->family == CHIP_KAVERI) {
u32 tmp = RREG32(CHUB_CONTROL);
tmp &= ~BYPASS_VM;
WREG32(CHUB_CONTROL, tmp);
}
mutex_lock(&rdev->srbm_mutex);
for (i = 0; i < 16; i++) {
cik_srbm_select(rdev, 0, 0, 0, i);
WREG32(SH_MEM_CONFIG, 0);
WREG32(SH_MEM_APE1_BASE, 1);
WREG32(SH_MEM_APE1_LIMIT, 0);
WREG32(SH_MEM_BASES, 0);
WREG32(SDMA0_GFX_VIRTUAL_ADDR + SDMA0_REGISTER_OFFSET, 0);
WREG32(SDMA0_GFX_APE1_CNTL + SDMA0_REGISTER_OFFSET, 0);
WREG32(SDMA0_GFX_VIRTUAL_ADDR + SDMA1_REGISTER_OFFSET, 0);
WREG32(SDMA0_GFX_APE1_CNTL + SDMA1_REGISTER_OFFSET, 0);
}
cik_srbm_select(rdev, 0, 0, 0, 0);
mutex_unlock(&rdev->srbm_mutex);
cik_pcie_gart_tlb_flush(rdev);
DRM_INFO("PCIE GART of %uM enabled (table at 0x%016llX).\n",
(unsigned)(rdev->mc.gtt_size >> 20),
(unsigned long long)rdev->gart.table_addr);
rdev->gart.ready = true;
return 0;
}
static void cik_pcie_gart_disable(struct radeon_device *rdev)
{
WREG32(VM_CONTEXT0_CNTL, 0);
WREG32(VM_CONTEXT1_CNTL, 0);
WREG32(MC_VM_MX_L1_TLB_CNTL, SYSTEM_ACCESS_MODE_NOT_IN_SYS |
SYSTEM_APERTURE_UNMAPPED_ACCESS_PASS_THRU);
WREG32(VM_L2_CNTL,
ENABLE_L2_FRAGMENT_PROCESSING |
ENABLE_L2_PTE_CACHE_LRU_UPDATE_BY_WRITE |
ENABLE_L2_PDE0_CACHE_LRU_UPDATE_BY_WRITE |
EFFECTIVE_L2_QUEUE_SIZE(7) |
CONTEXT1_IDENTITY_ACCESS_MODE(1));
WREG32(VM_L2_CNTL2, 0);
WREG32(VM_L2_CNTL3, L2_CACHE_BIGK_ASSOCIATIVITY |
L2_CACHE_BIGK_FRAGMENT_SIZE(6));
radeon_gart_table_vram_unpin(rdev);
}
static void cik_pcie_gart_fini(struct radeon_device *rdev)
{
cik_pcie_gart_disable(rdev);
radeon_gart_table_vram_free(rdev);
radeon_gart_fini(rdev);
}
int cik_ib_parse(struct radeon_device *rdev, struct radeon_ib *ib)
{
return 0;
}
int cik_vm_init(struct radeon_device *rdev)
{
rdev->vm_manager.nvm = 16;
if (rdev->flags & RADEON_IS_IGP) {
u64 tmp = RREG32(MC_VM_FB_OFFSET);
tmp <<= 22;
rdev->vm_manager.vram_base_offset = tmp;
} else
rdev->vm_manager.vram_base_offset = 0;
return 0;
}
void cik_vm_fini(struct radeon_device *rdev)
{
}
static void cik_vm_decode_fault(struct radeon_device *rdev,
u32 status, u32 addr, u32 mc_client)
{
u32 mc_id = (status & MEMORY_CLIENT_ID_MASK) >> MEMORY_CLIENT_ID_SHIFT;
u32 vmid = (status & FAULT_VMID_MASK) >> FAULT_VMID_SHIFT;
u32 protections = (status & PROTECTIONS_MASK) >> PROTECTIONS_SHIFT;
char *block = (char *)&mc_client;
printk("VM fault (0x%02x, vmid %d) at page %u, %s from %s (%d)\n",
protections, vmid, addr,
(status & MEMORY_CLIENT_RW_MASK) ? "write" : "read",
block, mc_id);
}
void cik_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
if (vm == NULL)
return;
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
if (vm->id < 8) {
radeon_ring_write(ring,
(VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2);
} else {
radeon_ring_write(ring,
(VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((vm->id - 8) << 2)) >> 2);
}
radeon_ring_write(ring, 0);
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, VMID(vm->id));
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 6));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, SH_MEM_BASES >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 1);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, VMID(0));
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, HDP_MEM_COHERENCY_FLUSH_CNTL >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
radeon_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
radeon_ring_write(ring, VM_INVALIDATE_REQUEST >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, 1 << vm->id);
if (ridx == RADEON_RING_TYPE_GFX_INDEX) {
radeon_ring_write(ring, PACKET3(PACKET3_PFP_SYNC_ME, 0));
radeon_ring_write(ring, 0x0);
}
}
void cik_vm_set_page(struct radeon_device *rdev,
struct radeon_ib *ib,
uint64_t pe,
uint64_t addr, unsigned count,
uint32_t incr, uint32_t flags)
{
uint32_t r600_flags = cayman_vm_page_flags(rdev, flags);
uint64_t value;
unsigned ndw;
if (rdev->asic->vm.pt_ring_index == RADEON_RING_TYPE_GFX_INDEX) {
while (count) {
ndw = 2 + count * 2;
if (ndw > 0x3FFE)
ndw = 0x3FFE;
ib->ptr[ib->length_dw++] = PACKET3(PACKET3_WRITE_DATA, ndw);
ib->ptr[ib->length_dw++] = (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(1));
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
for (; ndw > 2; ndw -= 2, --count, pe += 8) {
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
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
}
}
} else {
if (flags & RADEON_VM_PAGE_SYSTEM) {
while (count) {
ndw = count * 2;
if (ndw > 0xFFFFE)
ndw = 0xFFFFE;
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_WRITE, SDMA_WRITE_SUB_OPCODE_LINEAR, 0);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = ndw;
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
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
}
}
} else {
while (count) {
ndw = count;
if (ndw > 0x7FFFF)
ndw = 0x7FFFF;
if (flags & RADEON_VM_PAGE_VALID)
value = addr;
else
value = 0;
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_GENERATE_PTE_PDE, 0, 0);
ib->ptr[ib->length_dw++] = pe;
ib->ptr[ib->length_dw++] = upper_32_bits(pe);
ib->ptr[ib->length_dw++] = r600_flags;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = value;
ib->ptr[ib->length_dw++] = upper_32_bits(value);
ib->ptr[ib->length_dw++] = incr;
ib->ptr[ib->length_dw++] = 0;
ib->ptr[ib->length_dw++] = ndw;
pe += ndw * 8;
addr += ndw * incr;
count -= ndw;
}
}
while (ib->length_dw & 0x7)
ib->ptr[ib->length_dw++] = SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0);
}
}
void cik_dma_vm_flush(struct radeon_device *rdev, int ridx, struct radeon_vm *vm)
{
struct radeon_ring *ring = &rdev->ring[ridx];
u32 extra_bits = (SDMA_POLL_REG_MEM_EXTRA_OP(1) |
SDMA_POLL_REG_MEM_EXTRA_FUNC(3));
u32 ref_and_mask;
if (vm == NULL)
return;
if (ridx == R600_RING_TYPE_DMA_INDEX)
ref_and_mask = SDMA0;
else
ref_and_mask = SDMA1;
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
if (vm->id < 8) {
radeon_ring_write(ring, (VM_CONTEXT0_PAGE_TABLE_BASE_ADDR + (vm->id << 2)) >> 2);
} else {
radeon_ring_write(ring, (VM_CONTEXT8_PAGE_TABLE_BASE_ADDR + ((vm->id - 8) << 2)) >> 2);
}
radeon_ring_write(ring, vm->pd_gpu_addr >> 12);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, VMID(vm->id));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_BASES >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_CONFIG >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_APE1_BASE >> 2);
radeon_ring_write(ring, 1);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SH_MEM_APE1_LIMIT >> 2);
radeon_ring_write(ring, 0);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, SRBM_GFX_CNTL >> 2);
radeon_ring_write(ring, VMID(0));
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_POLL_REG_MEM, 0, extra_bits));
radeon_ring_write(ring, GPU_HDP_FLUSH_DONE);
radeon_ring_write(ring, GPU_HDP_FLUSH_REQ);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, ref_and_mask);
radeon_ring_write(ring, (4 << 16) | 10);
radeon_ring_write(ring, SDMA_PACKET(SDMA_OPCODE_SRBM_WRITE, 0, 0xf000));
radeon_ring_write(ring, VM_INVALIDATE_REQUEST >> 2);
radeon_ring_write(ring, 1 << vm->id);
}
static void cik_rlc_stop(struct radeon_device *rdev)
{
int i, j, k;
u32 mask, tmp;
tmp = RREG32(CP_INT_CNTL_RING0);
tmp &= ~(CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE);
WREG32(CP_INT_CNTL_RING0, tmp);
RREG32(CB_CGTT_SCLK_CTRL);
RREG32(CB_CGTT_SCLK_CTRL);
RREG32(CB_CGTT_SCLK_CTRL);
RREG32(CB_CGTT_SCLK_CTRL);
tmp = RREG32(RLC_CGCG_CGLS_CTRL) & 0xfffffffc;
WREG32(RLC_CGCG_CGLS_CTRL, tmp);
WREG32(RLC_CNTL, 0);
for (i = 0; i < rdev->config.cik.max_shader_engines; i++) {
for (j = 0; j < rdev->config.cik.max_sh_per_se; j++) {
cik_select_se_sh(rdev, i, j);
for (k = 0; k < rdev->usec_timeout; k++) {
if (RREG32(RLC_SERDES_CU_MASTER_BUSY) == 0)
break;
udelay(1);
}
}
}
cik_select_se_sh(rdev, 0xffffffff, 0xffffffff);
mask = SE_MASTER_BUSY_MASK | GC_MASTER_BUSY | TC0_MASTER_BUSY | TC1_MASTER_BUSY;
for (k = 0; k < rdev->usec_timeout; k++) {
if ((RREG32(RLC_SERDES_NONCU_MASTER_BUSY) & mask) == 0)
break;
udelay(1);
}
}
static void cik_rlc_start(struct radeon_device *rdev)
{
u32 tmp;
WREG32(RLC_CNTL, RLC_ENABLE);
tmp = RREG32(CP_INT_CNTL_RING0);
tmp |= (CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE);
WREG32(CP_INT_CNTL_RING0, tmp);
udelay(50);
}
static int cik_rlc_resume(struct radeon_device *rdev)
{
u32 i, size;
u32 clear_state_info[3];
const __be32 *fw_data;
if (!rdev->rlc_fw)
return -EINVAL;
switch (rdev->family) {
case CHIP_BONAIRE:
default:
size = BONAIRE_RLC_UCODE_SIZE;
break;
case CHIP_KAVERI:
size = KV_RLC_UCODE_SIZE;
break;
case CHIP_KABINI:
size = KB_RLC_UCODE_SIZE;
break;
}
cik_rlc_stop(rdev);
WREG32(GRBM_SOFT_RESET, SOFT_RESET_RLC);
RREG32(GRBM_SOFT_RESET);
udelay(50);
WREG32(GRBM_SOFT_RESET, 0);
RREG32(GRBM_SOFT_RESET);
udelay(50);
WREG32(RLC_LB_CNTR_INIT, 0);
WREG32(RLC_LB_CNTR_MAX, 0x00008000);
cik_select_se_sh(rdev, 0xffffffff, 0xffffffff);
WREG32(RLC_LB_INIT_CU_MASK, 0xffffffff);
WREG32(RLC_LB_PARAMS, 0x00600408);
WREG32(RLC_LB_CNTL, 0x80000004);
WREG32(RLC_MC_CNTL, 0);
WREG32(RLC_UCODE_CNTL, 0);
fw_data = (const __be32 *)rdev->rlc_fw->data;
WREG32(RLC_GPM_UCODE_ADDR, 0);
for (i = 0; i < size; i++)
WREG32(RLC_GPM_UCODE_DATA, be32_to_cpup(fw_data++));
WREG32(RLC_GPM_UCODE_ADDR, 0);
clear_state_info[0] = 0;
clear_state_info[1] = 0;
clear_state_info[2] = 0;
WREG32(RLC_GPM_SCRATCH_ADDR, 0x3d);
for (i = 0; i < 3; i++)
WREG32(RLC_GPM_SCRATCH_DATA, clear_state_info[i]);
WREG32(RLC_DRIVER_DMA_STATUS, 0);
cik_rlc_start(rdev);
return 0;
}
static void cik_enable_interrupts(struct radeon_device *rdev)
{
u32 ih_cntl = RREG32(IH_CNTL);
u32 ih_rb_cntl = RREG32(IH_RB_CNTL);
ih_cntl |= ENABLE_INTR;
ih_rb_cntl |= IH_RB_ENABLE;
WREG32(IH_CNTL, ih_cntl);
WREG32(IH_RB_CNTL, ih_rb_cntl);
rdev->ih.enabled = true;
}
static void cik_disable_interrupts(struct radeon_device *rdev)
{
u32 ih_rb_cntl = RREG32(IH_RB_CNTL);
u32 ih_cntl = RREG32(IH_CNTL);
ih_rb_cntl &= ~IH_RB_ENABLE;
ih_cntl &= ~ENABLE_INTR;
WREG32(IH_RB_CNTL, ih_rb_cntl);
WREG32(IH_CNTL, ih_cntl);
WREG32(IH_RB_RPTR, 0);
WREG32(IH_RB_WPTR, 0);
rdev->ih.enabled = false;
rdev->ih.rptr = 0;
}
static void cik_disable_interrupt_state(struct radeon_device *rdev)
{
u32 tmp;
WREG32(CP_INT_CNTL_RING0, CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE);
tmp = RREG32(SDMA0_CNTL + SDMA0_REGISTER_OFFSET) & ~TRAP_ENABLE;
WREG32(SDMA0_CNTL + SDMA0_REGISTER_OFFSET, tmp);
tmp = RREG32(SDMA0_CNTL + SDMA1_REGISTER_OFFSET) & ~TRAP_ENABLE;
WREG32(SDMA0_CNTL + SDMA1_REGISTER_OFFSET, tmp);
WREG32(CP_ME1_PIPE0_INT_CNTL, 0);
WREG32(CP_ME1_PIPE1_INT_CNTL, 0);
WREG32(CP_ME1_PIPE2_INT_CNTL, 0);
WREG32(CP_ME1_PIPE3_INT_CNTL, 0);
WREG32(CP_ME2_PIPE0_INT_CNTL, 0);
WREG32(CP_ME2_PIPE1_INT_CNTL, 0);
WREG32(CP_ME2_PIPE2_INT_CNTL, 0);
WREG32(CP_ME2_PIPE3_INT_CNTL, 0);
WREG32(GRBM_INT_CNTL, 0);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC0_REGISTER_OFFSET, 0);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC1_REGISTER_OFFSET, 0);
if (rdev->num_crtc >= 4) {
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC2_REGISTER_OFFSET, 0);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC3_REGISTER_OFFSET, 0);
}
if (rdev->num_crtc >= 6) {
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC4_REGISTER_OFFSET, 0);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC5_REGISTER_OFFSET, 0);
}
WREG32(DAC_AUTODETECT_INT_CONTROL, 0);
tmp = RREG32(DC_HPD1_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD1_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD2_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD2_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD3_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD3_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD4_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD4_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD5_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD5_INT_CONTROL, tmp);
tmp = RREG32(DC_HPD6_INT_CONTROL) & DC_HPDx_INT_POLARITY;
WREG32(DC_HPD6_INT_CONTROL, tmp);
}
static int cik_irq_init(struct radeon_device *rdev)
{
int ret = 0;
int rb_bufsz;
u32 interrupt_cntl, ih_cntl, ih_rb_cntl;
ret = r600_ih_ring_alloc(rdev);
if (ret)
return ret;
cik_disable_interrupts(rdev);
ret = cik_rlc_resume(rdev);
if (ret) {
r600_ih_ring_fini(rdev);
return ret;
}
WREG32(INTERRUPT_CNTL2, rdev->ih.gpu_addr >> 8);
interrupt_cntl = RREG32(INTERRUPT_CNTL);
interrupt_cntl &= ~IH_DUMMY_RD_OVERRIDE;
interrupt_cntl &= ~IH_REQ_NONSNOOP_EN;
WREG32(INTERRUPT_CNTL, interrupt_cntl);
WREG32(IH_RB_BASE, rdev->ih.gpu_addr >> 8);
rb_bufsz = drm_order(rdev->ih.ring_size / 4);
ih_rb_cntl = (IH_WPTR_OVERFLOW_ENABLE |
IH_WPTR_OVERFLOW_CLEAR |
(rb_bufsz << 1));
if (rdev->wb.enabled)
ih_rb_cntl |= IH_WPTR_WRITEBACK_ENABLE;
WREG32(IH_RB_WPTR_ADDR_LO, (rdev->wb.gpu_addr + R600_WB_IH_WPTR_OFFSET) & 0xFFFFFFFC);
WREG32(IH_RB_WPTR_ADDR_HI, upper_32_bits(rdev->wb.gpu_addr + R600_WB_IH_WPTR_OFFSET) & 0xFF);
WREG32(IH_RB_CNTL, ih_rb_cntl);
WREG32(IH_RB_RPTR, 0);
WREG32(IH_RB_WPTR, 0);
ih_cntl = MC_WRREQ_CREDIT(0x10) | MC_WR_CLEAN_CNT(0x10) | MC_VMID(0);
if (rdev->msi_enabled)
ih_cntl |= RPTR_REARM;
WREG32(IH_CNTL, ih_cntl);
cik_disable_interrupt_state(rdev);
pci_set_master(rdev->pdev);
cik_enable_interrupts(rdev);
return ret;
}
int cik_irq_set(struct radeon_device *rdev)
{
u32 cp_int_cntl = CNTX_BUSY_INT_ENABLE | CNTX_EMPTY_INT_ENABLE |
PRIV_INSTR_INT_ENABLE | PRIV_REG_INT_ENABLE;
u32 cp_m1p0, cp_m1p1, cp_m1p2, cp_m1p3;
u32 cp_m2p0, cp_m2p1, cp_m2p2, cp_m2p3;
u32 crtc1 = 0, crtc2 = 0, crtc3 = 0, crtc4 = 0, crtc5 = 0, crtc6 = 0;
u32 hpd1, hpd2, hpd3, hpd4, hpd5, hpd6;
u32 grbm_int_cntl = 0;
u32 dma_cntl, dma_cntl1;
if (!rdev->irq.installed) {
WARN(1, "Can't enable IRQ/MSI because no handler is installed\n");
return -EINVAL;
}
if (!rdev->ih.enabled) {
cik_disable_interrupts(rdev);
cik_disable_interrupt_state(rdev);
return 0;
}
hpd1 = RREG32(DC_HPD1_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd2 = RREG32(DC_HPD2_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd3 = RREG32(DC_HPD3_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd4 = RREG32(DC_HPD4_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd5 = RREG32(DC_HPD5_INT_CONTROL) & ~DC_HPDx_INT_EN;
hpd6 = RREG32(DC_HPD6_INT_CONTROL) & ~DC_HPDx_INT_EN;
dma_cntl = RREG32(SDMA0_CNTL + SDMA0_REGISTER_OFFSET) & ~TRAP_ENABLE;
dma_cntl1 = RREG32(SDMA0_CNTL + SDMA1_REGISTER_OFFSET) & ~TRAP_ENABLE;
cp_m1p0 = RREG32(CP_ME1_PIPE0_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m1p1 = RREG32(CP_ME1_PIPE1_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m1p2 = RREG32(CP_ME1_PIPE2_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m1p3 = RREG32(CP_ME1_PIPE3_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m2p0 = RREG32(CP_ME2_PIPE0_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m2p1 = RREG32(CP_ME2_PIPE1_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m2p2 = RREG32(CP_ME2_PIPE2_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
cp_m2p3 = RREG32(CP_ME2_PIPE3_INT_CNTL) & ~TIME_STAMP_INT_ENABLE;
if (atomic_read(&rdev->irq.ring_int[RADEON_RING_TYPE_GFX_INDEX])) {
DRM_DEBUG("cik_irq_set: sw int gfx\n");
cp_int_cntl |= TIME_STAMP_INT_ENABLE;
}
if (atomic_read(&rdev->irq.ring_int[CAYMAN_RING_TYPE_CP1_INDEX])) {
struct radeon_ring *ring = &rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX];
DRM_DEBUG("si_irq_set: sw int cp1\n");
if (ring->me == 1) {
switch (ring->pipe) {
case 0:
cp_m1p0 |= TIME_STAMP_INT_ENABLE;
break;
case 1:
cp_m1p1 |= TIME_STAMP_INT_ENABLE;
break;
case 2:
cp_m1p2 |= TIME_STAMP_INT_ENABLE;
break;
case 3:
cp_m1p2 |= TIME_STAMP_INT_ENABLE;
break;
default:
DRM_DEBUG("si_irq_set: sw int cp1 invalid pipe %d\n", ring->pipe);
break;
}
} else if (ring->me == 2) {
switch (ring->pipe) {
case 0:
cp_m2p0 |= TIME_STAMP_INT_ENABLE;
break;
case 1:
cp_m2p1 |= TIME_STAMP_INT_ENABLE;
break;
case 2:
cp_m2p2 |= TIME_STAMP_INT_ENABLE;
break;
case 3:
cp_m2p2 |= TIME_STAMP_INT_ENABLE;
break;
default:
DRM_DEBUG("si_irq_set: sw int cp1 invalid pipe %d\n", ring->pipe);
break;
}
} else {
DRM_DEBUG("si_irq_set: sw int cp1 invalid me %d\n", ring->me);
}
}
if (atomic_read(&rdev->irq.ring_int[CAYMAN_RING_TYPE_CP2_INDEX])) {
struct radeon_ring *ring = &rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX];
DRM_DEBUG("si_irq_set: sw int cp2\n");
if (ring->me == 1) {
switch (ring->pipe) {
case 0:
cp_m1p0 |= TIME_STAMP_INT_ENABLE;
break;
case 1:
cp_m1p1 |= TIME_STAMP_INT_ENABLE;
break;
case 2:
cp_m1p2 |= TIME_STAMP_INT_ENABLE;
break;
case 3:
cp_m1p2 |= TIME_STAMP_INT_ENABLE;
break;
default:
DRM_DEBUG("si_irq_set: sw int cp2 invalid pipe %d\n", ring->pipe);
break;
}
} else if (ring->me == 2) {
switch (ring->pipe) {
case 0:
cp_m2p0 |= TIME_STAMP_INT_ENABLE;
break;
case 1:
cp_m2p1 |= TIME_STAMP_INT_ENABLE;
break;
case 2:
cp_m2p2 |= TIME_STAMP_INT_ENABLE;
break;
case 3:
cp_m2p2 |= TIME_STAMP_INT_ENABLE;
break;
default:
DRM_DEBUG("si_irq_set: sw int cp2 invalid pipe %d\n", ring->pipe);
break;
}
} else {
DRM_DEBUG("si_irq_set: sw int cp2 invalid me %d\n", ring->me);
}
}
if (atomic_read(&rdev->irq.ring_int[R600_RING_TYPE_DMA_INDEX])) {
DRM_DEBUG("cik_irq_set: sw int dma\n");
dma_cntl |= TRAP_ENABLE;
}
if (atomic_read(&rdev->irq.ring_int[CAYMAN_RING_TYPE_DMA1_INDEX])) {
DRM_DEBUG("cik_irq_set: sw int dma1\n");
dma_cntl1 |= TRAP_ENABLE;
}
if (rdev->irq.crtc_vblank_int[0] ||
atomic_read(&rdev->irq.pflip[0])) {
DRM_DEBUG("cik_irq_set: vblank 0\n");
crtc1 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.crtc_vblank_int[1] ||
atomic_read(&rdev->irq.pflip[1])) {
DRM_DEBUG("cik_irq_set: vblank 1\n");
crtc2 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.crtc_vblank_int[2] ||
atomic_read(&rdev->irq.pflip[2])) {
DRM_DEBUG("cik_irq_set: vblank 2\n");
crtc3 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.crtc_vblank_int[3] ||
atomic_read(&rdev->irq.pflip[3])) {
DRM_DEBUG("cik_irq_set: vblank 3\n");
crtc4 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.crtc_vblank_int[4] ||
atomic_read(&rdev->irq.pflip[4])) {
DRM_DEBUG("cik_irq_set: vblank 4\n");
crtc5 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.crtc_vblank_int[5] ||
atomic_read(&rdev->irq.pflip[5])) {
DRM_DEBUG("cik_irq_set: vblank 5\n");
crtc6 |= VBLANK_INTERRUPT_MASK;
}
if (rdev->irq.hpd[0]) {
DRM_DEBUG("cik_irq_set: hpd 1\n");
hpd1 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[1]) {
DRM_DEBUG("cik_irq_set: hpd 2\n");
hpd2 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[2]) {
DRM_DEBUG("cik_irq_set: hpd 3\n");
hpd3 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[3]) {
DRM_DEBUG("cik_irq_set: hpd 4\n");
hpd4 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[4]) {
DRM_DEBUG("cik_irq_set: hpd 5\n");
hpd5 |= DC_HPDx_INT_EN;
}
if (rdev->irq.hpd[5]) {
DRM_DEBUG("cik_irq_set: hpd 6\n");
hpd6 |= DC_HPDx_INT_EN;
}
WREG32(CP_INT_CNTL_RING0, cp_int_cntl);
WREG32(SDMA0_CNTL + SDMA0_REGISTER_OFFSET, dma_cntl);
WREG32(SDMA0_CNTL + SDMA1_REGISTER_OFFSET, dma_cntl1);
WREG32(CP_ME1_PIPE0_INT_CNTL, cp_m1p0);
WREG32(CP_ME1_PIPE1_INT_CNTL, cp_m1p1);
WREG32(CP_ME1_PIPE2_INT_CNTL, cp_m1p2);
WREG32(CP_ME1_PIPE3_INT_CNTL, cp_m1p3);
WREG32(CP_ME2_PIPE0_INT_CNTL, cp_m2p0);
WREG32(CP_ME2_PIPE1_INT_CNTL, cp_m2p1);
WREG32(CP_ME2_PIPE2_INT_CNTL, cp_m2p2);
WREG32(CP_ME2_PIPE3_INT_CNTL, cp_m2p3);
WREG32(GRBM_INT_CNTL, grbm_int_cntl);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC0_REGISTER_OFFSET, crtc1);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC1_REGISTER_OFFSET, crtc2);
if (rdev->num_crtc >= 4) {
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC2_REGISTER_OFFSET, crtc3);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC3_REGISTER_OFFSET, crtc4);
}
if (rdev->num_crtc >= 6) {
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC4_REGISTER_OFFSET, crtc5);
WREG32(LB_INTERRUPT_MASK + EVERGREEN_CRTC5_REGISTER_OFFSET, crtc6);
}
WREG32(DC_HPD1_INT_CONTROL, hpd1);
WREG32(DC_HPD2_INT_CONTROL, hpd2);
WREG32(DC_HPD3_INT_CONTROL, hpd3);
WREG32(DC_HPD4_INT_CONTROL, hpd4);
WREG32(DC_HPD5_INT_CONTROL, hpd5);
WREG32(DC_HPD6_INT_CONTROL, hpd6);
return 0;
}
static inline void cik_irq_ack(struct radeon_device *rdev)
{
u32 tmp;
rdev->irq.stat_regs.cik.disp_int = RREG32(DISP_INTERRUPT_STATUS);
rdev->irq.stat_regs.cik.disp_int_cont = RREG32(DISP_INTERRUPT_STATUS_CONTINUE);
rdev->irq.stat_regs.cik.disp_int_cont2 = RREG32(DISP_INTERRUPT_STATUS_CONTINUE2);
rdev->irq.stat_regs.cik.disp_int_cont3 = RREG32(DISP_INTERRUPT_STATUS_CONTINUE3);
rdev->irq.stat_regs.cik.disp_int_cont4 = RREG32(DISP_INTERRUPT_STATUS_CONTINUE4);
rdev->irq.stat_regs.cik.disp_int_cont5 = RREG32(DISP_INTERRUPT_STATUS_CONTINUE5);
rdev->irq.stat_regs.cik.disp_int_cont6 = RREG32(DISP_INTERRUPT_STATUS_CONTINUE6);
if (rdev->irq.stat_regs.cik.disp_int & LB_D1_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC0_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int & LB_D1_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC0_REGISTER_OFFSET, VLINE_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont & LB_D2_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC1_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont & LB_D2_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC1_REGISTER_OFFSET, VLINE_ACK);
if (rdev->num_crtc >= 4) {
if (rdev->irq.stat_regs.cik.disp_int_cont2 & LB_D3_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC2_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont2 & LB_D3_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC2_REGISTER_OFFSET, VLINE_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont3 & LB_D4_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC3_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont3 & LB_D4_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC3_REGISTER_OFFSET, VLINE_ACK);
}
if (rdev->num_crtc >= 6) {
if (rdev->irq.stat_regs.cik.disp_int_cont4 & LB_D5_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC4_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont4 & LB_D5_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC4_REGISTER_OFFSET, VLINE_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont5 & LB_D6_VBLANK_INTERRUPT)
WREG32(LB_VBLANK_STATUS + EVERGREEN_CRTC5_REGISTER_OFFSET, VBLANK_ACK);
if (rdev->irq.stat_regs.cik.disp_int_cont5 & LB_D6_VLINE_INTERRUPT)
WREG32(LB_VLINE_STATUS + EVERGREEN_CRTC5_REGISTER_OFFSET, VLINE_ACK);
}
if (rdev->irq.stat_regs.cik.disp_int & DC_HPD1_INTERRUPT) {
tmp = RREG32(DC_HPD1_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD1_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.cik.disp_int_cont & DC_HPD2_INTERRUPT) {
tmp = RREG32(DC_HPD2_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD2_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.cik.disp_int_cont2 & DC_HPD3_INTERRUPT) {
tmp = RREG32(DC_HPD3_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD3_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.cik.disp_int_cont3 & DC_HPD4_INTERRUPT) {
tmp = RREG32(DC_HPD4_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD4_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.cik.disp_int_cont4 & DC_HPD5_INTERRUPT) {
tmp = RREG32(DC_HPD5_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD5_INT_CONTROL, tmp);
}
if (rdev->irq.stat_regs.cik.disp_int_cont5 & DC_HPD6_INTERRUPT) {
tmp = RREG32(DC_HPD5_INT_CONTROL);
tmp |= DC_HPDx_INT_ACK;
WREG32(DC_HPD6_INT_CONTROL, tmp);
}
}
static void cik_irq_disable(struct radeon_device *rdev)
{
cik_disable_interrupts(rdev);
mdelay(1);
cik_irq_ack(rdev);
cik_disable_interrupt_state(rdev);
}
static void cik_irq_suspend(struct radeon_device *rdev)
{
cik_irq_disable(rdev);
cik_rlc_stop(rdev);
}
static void cik_irq_fini(struct radeon_device *rdev)
{
cik_irq_suspend(rdev);
r600_ih_ring_fini(rdev);
}
static inline u32 cik_get_ih_wptr(struct radeon_device *rdev)
{
u32 wptr, tmp;
if (rdev->wb.enabled)
wptr = le32_to_cpu(rdev->wb.wb[R600_WB_IH_WPTR_OFFSET/4]);
else
wptr = RREG32(IH_RB_WPTR);
if (wptr & RB_OVERFLOW) {
dev_warn(rdev->dev, "IH ring buffer overflow (0x%08X, %d, %d)\n",
wptr, rdev->ih.rptr, (wptr + 16) + rdev->ih.ptr_mask);
rdev->ih.rptr = (wptr + 16) & rdev->ih.ptr_mask;
tmp = RREG32(IH_RB_CNTL);
tmp |= IH_WPTR_OVERFLOW_CLEAR;
WREG32(IH_RB_CNTL, tmp);
}
return (wptr & rdev->ih.ptr_mask);
}
int cik_irq_process(struct radeon_device *rdev)
{
struct radeon_ring *cp1_ring = &rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX];
struct radeon_ring *cp2_ring = &rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX];
u32 wptr;
u32 rptr;
u32 src_id, src_data, ring_id;
u8 me_id, pipe_id, queue_id;
u32 ring_index;
bool queue_hotplug = false;
bool queue_reset = false;
u32 addr, status, mc_client;
if (!rdev->ih.enabled || rdev->shutdown)
return IRQ_NONE;
wptr = cik_get_ih_wptr(rdev);
restart_ih:
if (atomic_xchg(&rdev->ih.lock, 1))
return IRQ_NONE;
rptr = rdev->ih.rptr;
DRM_DEBUG("cik_irq_process start: rptr %d, wptr %d\n", rptr, wptr);
rmb();
cik_irq_ack(rdev);
while (rptr != wptr) {
ring_index = rptr / 4;
src_id = le32_to_cpu(rdev->ih.ring[ring_index]) & 0xff;
src_data = le32_to_cpu(rdev->ih.ring[ring_index + 1]) & 0xfffffff;
ring_id = le32_to_cpu(rdev->ih.ring[ring_index + 2]) & 0xff;
switch (src_id) {
case 1:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int & LB_D1_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[0]) {
drm_handle_vblank(rdev->ddev, 0);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[0]))
radeon_crtc_handle_flip(rdev, 0);
rdev->irq.stat_regs.cik.disp_int &= ~LB_D1_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D1 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int & LB_D1_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int &= ~LB_D1_VLINE_INTERRUPT;
DRM_DEBUG("IH: D1 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 2:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int_cont & LB_D2_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[1]) {
drm_handle_vblank(rdev->ddev, 1);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[1]))
radeon_crtc_handle_flip(rdev, 1);
rdev->irq.stat_regs.cik.disp_int_cont &= ~LB_D2_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D2 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont & LB_D2_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont &= ~LB_D2_VLINE_INTERRUPT;
DRM_DEBUG("IH: D2 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 3:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int_cont2 & LB_D3_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[2]) {
drm_handle_vblank(rdev->ddev, 2);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[2]))
radeon_crtc_handle_flip(rdev, 2);
rdev->irq.stat_regs.cik.disp_int_cont2 &= ~LB_D3_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D3 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont2 & LB_D3_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont2 &= ~LB_D3_VLINE_INTERRUPT;
DRM_DEBUG("IH: D3 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 4:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int_cont3 & LB_D4_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[3]) {
drm_handle_vblank(rdev->ddev, 3);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[3]))
radeon_crtc_handle_flip(rdev, 3);
rdev->irq.stat_regs.cik.disp_int_cont3 &= ~LB_D4_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D4 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont3 & LB_D4_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont3 &= ~LB_D4_VLINE_INTERRUPT;
DRM_DEBUG("IH: D4 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 5:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int_cont4 & LB_D5_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[4]) {
drm_handle_vblank(rdev->ddev, 4);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[4]))
radeon_crtc_handle_flip(rdev, 4);
rdev->irq.stat_regs.cik.disp_int_cont4 &= ~LB_D5_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D5 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont4 & LB_D5_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont4 &= ~LB_D5_VLINE_INTERRUPT;
DRM_DEBUG("IH: D5 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 6:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int_cont5 & LB_D6_VBLANK_INTERRUPT) {
if (rdev->irq.crtc_vblank_int[5]) {
drm_handle_vblank(rdev->ddev, 5);
rdev->pm.vblank_sync = true;
wake_up(&rdev->irq.vblank_queue);
}
if (atomic_read(&rdev->irq.pflip[5]))
radeon_crtc_handle_flip(rdev, 5);
rdev->irq.stat_regs.cik.disp_int_cont5 &= ~LB_D6_VBLANK_INTERRUPT;
DRM_DEBUG("IH: D6 vblank\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont5 & LB_D6_VLINE_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont5 &= ~LB_D6_VLINE_INTERRUPT;
DRM_DEBUG("IH: D6 vline\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 42:
switch (src_data) {
case 0:
if (rdev->irq.stat_regs.cik.disp_int & DC_HPD1_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int &= ~DC_HPD1_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD1\n");
}
break;
case 1:
if (rdev->irq.stat_regs.cik.disp_int_cont & DC_HPD2_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont &= ~DC_HPD2_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD2\n");
}
break;
case 2:
if (rdev->irq.stat_regs.cik.disp_int_cont2 & DC_HPD3_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont2 &= ~DC_HPD3_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD3\n");
}
break;
case 3:
if (rdev->irq.stat_regs.cik.disp_int_cont3 & DC_HPD4_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont3 &= ~DC_HPD4_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD4\n");
}
break;
case 4:
if (rdev->irq.stat_regs.cik.disp_int_cont4 & DC_HPD5_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont4 &= ~DC_HPD5_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD5\n");
}
break;
case 5:
if (rdev->irq.stat_regs.cik.disp_int_cont5 & DC_HPD6_INTERRUPT) {
rdev->irq.stat_regs.cik.disp_int_cont5 &= ~DC_HPD6_INTERRUPT;
queue_hotplug = true;
DRM_DEBUG("IH: HPD6\n");
}
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
break;
case 146:
case 147:
addr = RREG32(VM_CONTEXT1_PROTECTION_FAULT_ADDR);
status = RREG32(VM_CONTEXT1_PROTECTION_FAULT_STATUS);
mc_client = RREG32(VM_CONTEXT1_PROTECTION_FAULT_MCCLIENT);
dev_err(rdev->dev, "GPU fault detected: %d 0x%08x\n", src_id, src_data);
dev_err(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_ADDR 0x%08X\n",
addr);
dev_err(rdev->dev, " VM_CONTEXT1_PROTECTION_FAULT_STATUS 0x%08X\n",
status);
cik_vm_decode_fault(rdev, status, addr, mc_client);
WREG32_P(VM_CONTEXT1_CNTL2, 1, ~1);
break;
case 176:
case 177:
radeon_fence_process(rdev, RADEON_RING_TYPE_GFX_INDEX);
break;
case 181:
DRM_DEBUG("IH: CP EOP\n");
me_id = (ring_id & 0x60) >> 5;
pipe_id = (ring_id & 0x18) >> 3;
queue_id = (ring_id & 0x7) >> 0;
switch (me_id) {
case 0:
radeon_fence_process(rdev, RADEON_RING_TYPE_GFX_INDEX);
break;
case 1:
case 2:
if ((cp1_ring->me == me_id) & (cp1_ring->pipe == pipe_id))
radeon_fence_process(rdev, CAYMAN_RING_TYPE_CP1_INDEX);
if ((cp2_ring->me == me_id) & (cp2_ring->pipe == pipe_id))
radeon_fence_process(rdev, CAYMAN_RING_TYPE_CP2_INDEX);
break;
}
break;
case 184:
DRM_ERROR("Illegal register access in command stream\n");
me_id = (ring_id & 0x60) >> 5;
pipe_id = (ring_id & 0x18) >> 3;
queue_id = (ring_id & 0x7) >> 0;
switch (me_id) {
case 0:
queue_reset = true;
break;
case 1:
queue_reset = true;
break;
case 2:
queue_reset = true;
break;
}
break;
case 185:
DRM_ERROR("Illegal instruction in command stream\n");
me_id = (ring_id & 0x60) >> 5;
pipe_id = (ring_id & 0x18) >> 3;
queue_id = (ring_id & 0x7) >> 0;
switch (me_id) {
case 0:
queue_reset = true;
break;
case 1:
queue_reset = true;
break;
case 2:
queue_reset = true;
break;
}
break;
case 224:
me_id = (ring_id & 0x3) >> 0;
queue_id = (ring_id & 0xc) >> 2;
DRM_DEBUG("IH: SDMA trap\n");
switch (me_id) {
case 0:
switch (queue_id) {
case 0:
radeon_fence_process(rdev, R600_RING_TYPE_DMA_INDEX);
break;
case 1:
break;
case 2:
break;
}
break;
case 1:
switch (queue_id) {
case 0:
radeon_fence_process(rdev, CAYMAN_RING_TYPE_DMA1_INDEX);
break;
case 1:
break;
case 2:
break;
}
break;
}
break;
case 241:
case 247:
DRM_ERROR("Illegal instruction in SDMA command stream\n");
me_id = (ring_id & 0x3) >> 0;
queue_id = (ring_id & 0xc) >> 2;
switch (me_id) {
case 0:
switch (queue_id) {
case 0:
queue_reset = true;
break;
case 1:
queue_reset = true;
break;
case 2:
queue_reset = true;
break;
}
break;
case 1:
switch (queue_id) {
case 0:
queue_reset = true;
break;
case 1:
queue_reset = true;
break;
case 2:
queue_reset = true;
break;
}
break;
}
break;
case 233:
DRM_DEBUG("IH: GUI idle\n");
break;
default:
DRM_DEBUG("Unhandled interrupt: %d %d\n", src_id, src_data);
break;
}
rptr += 16;
rptr &= rdev->ih.ptr_mask;
}
if (queue_hotplug)
schedule_work(&rdev->hotplug_work);
if (queue_reset)
schedule_work(&rdev->reset_work);
rdev->ih.rptr = rptr;
WREG32(IH_RB_RPTR, rdev->ih.rptr);
atomic_set(&rdev->ih.lock, 0);
wptr = cik_get_ih_wptr(rdev);
if (wptr != rptr)
goto restart_ih;
return IRQ_HANDLED;
}
static int cik_startup(struct radeon_device *rdev)
{
struct radeon_ring *ring;
int r;
cik_mc_program(rdev);
if (rdev->flags & RADEON_IS_IGP) {
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->ce_fw ||
!rdev->mec_fw || !rdev->sdma_fw || !rdev->rlc_fw) {
r = cik_init_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load firmware!\n");
return r;
}
}
} else {
if (!rdev->me_fw || !rdev->pfp_fw || !rdev->ce_fw ||
!rdev->mec_fw || !rdev->sdma_fw || !rdev->rlc_fw ||
!rdev->mc_fw) {
r = cik_init_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load firmware!\n");
return r;
}
}
r = ci_mc_load_microcode(rdev);
if (r) {
DRM_ERROR("Failed to load MC firmware!\n");
return r;
}
}
r = r600_vram_scratch_init(rdev);
if (r)
return r;
r = cik_pcie_gart_enable(rdev);
if (r)
return r;
cik_gpu_init(rdev);
r = si_rlc_init(rdev);
if (r) {
DRM_ERROR("Failed to init rlc BOs!\n");
return r;
}
r = radeon_wb_init(rdev);
if (r)
return r;
r = cik_mec_init(rdev);
if (r) {
DRM_ERROR("Failed to init MEC BOs!\n");
return r;
}
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
r = cik_uvd_resume(rdev);
if (!r) {
r = radeon_fence_driver_start_ring(rdev,
R600_RING_TYPE_UVD_INDEX);
if (r)
dev_err(rdev->dev, "UVD fences init error (%d).\n", r);
}
if (r)
rdev->ring[R600_RING_TYPE_UVD_INDEX].ring_size = 0;
if (!rdev->irq.installed) {
r = radeon_irq_kms_init(rdev);
if (r)
return r;
}
r = cik_irq_init(rdev);
if (r) {
DRM_ERROR("radeon: IH init failed (%d).\n", r);
radeon_irq_kms_fini(rdev);
return r;
}
cik_irq_set(rdev);
ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP_RPTR_OFFSET,
CP_RB0_RPTR, CP_RB0_WPTR,
0, 0xfffff, RADEON_CP_PACKET2);
if (r)
return r;
ring = &rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP1_RPTR_OFFSET,
CP_HQD_PQ_RPTR, CP_HQD_PQ_WPTR,
0, 0xfffff, PACKET3(PACKET3_NOP, 0x3FFF));
if (r)
return r;
ring->me = 1;
ring->pipe = 0;
ring->queue = 0;
ring->wptr_offs = CIK_WB_CP1_WPTR_OFFSET;
ring = &rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, RADEON_WB_CP2_RPTR_OFFSET,
CP_HQD_PQ_RPTR, CP_HQD_PQ_WPTR,
0, 0xffffffff, PACKET3(PACKET3_NOP, 0x3FFF));
if (r)
return r;
ring->me = 1;
ring->pipe = 0;
ring->queue = 1;
ring->wptr_offs = CIK_WB_CP2_WPTR_OFFSET;
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, R600_WB_DMA_RPTR_OFFSET,
SDMA0_GFX_RB_RPTR + SDMA0_REGISTER_OFFSET,
SDMA0_GFX_RB_WPTR + SDMA0_REGISTER_OFFSET,
2, 0xfffffffc, SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0));
if (r)
return r;
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
r = radeon_ring_init(rdev, ring, ring->ring_size, CAYMAN_WB_DMA1_RPTR_OFFSET,
SDMA0_GFX_RB_RPTR + SDMA1_REGISTER_OFFSET,
SDMA0_GFX_RB_WPTR + SDMA1_REGISTER_OFFSET,
2, 0xfffffffc, SDMA_PACKET(SDMA_OPCODE_NOP, 0, 0));
if (r)
return r;
r = cik_cp_resume(rdev);
if (r)
return r;
r = cik_sdma_resume(rdev);
if (r)
return r;
ring = &rdev->ring[R600_RING_TYPE_UVD_INDEX];
if (ring->ring_size) {
r = radeon_ring_init(rdev, ring, ring->ring_size,
R600_WB_UVD_RPTR_OFFSET,
UVD_RBC_RB_RPTR, UVD_RBC_RB_WPTR,
0, 0xfffff, RADEON_CP_PACKET2);
if (!r)
r = r600_uvd_init(rdev);
if (r)
DRM_ERROR("radeon: failed initializing UVD (%d).\n", r);
}
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
return 0;
}
int cik_resume(struct radeon_device *rdev)
{
int r;
atom_asic_init(rdev->mode_info.atom_context);
cik_init_golden_registers(rdev);
rdev->accel_working = true;
r = cik_startup(rdev);
if (r) {
DRM_ERROR("cik startup failed on resume\n");
rdev->accel_working = false;
return r;
}
return r;
}
int cik_suspend(struct radeon_device *rdev)
{
radeon_vm_manager_fini(rdev);
cik_cp_enable(rdev, false);
cik_sdma_enable(rdev, false);
r600_uvd_stop(rdev);
radeon_uvd_suspend(rdev);
cik_irq_suspend(rdev);
radeon_wb_disable(rdev);
cik_pcie_gart_disable(rdev);
return 0;
}
int cik_init(struct radeon_device *rdev)
{
struct radeon_ring *ring;
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
cik_init_golden_registers(rdev);
cik_scratch_init(rdev);
radeon_surface_init(rdev);
radeon_get_clock_info(rdev->ddev);
r = radeon_fence_driver_init(rdev);
if (r)
return r;
r = cik_mc_init(rdev);
if (r)
return r;
r = radeon_bo_init(rdev);
if (r)
return r;
ring = &rdev->ring[RADEON_RING_TYPE_GFX_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 1024 * 1024);
ring = &rdev->ring[CAYMAN_RING_TYPE_CP1_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 1024 * 1024);
r = radeon_doorbell_get(rdev, &ring->doorbell_page_num);
if (r)
return r;
ring = &rdev->ring[CAYMAN_RING_TYPE_CP2_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 1024 * 1024);
r = radeon_doorbell_get(rdev, &ring->doorbell_page_num);
if (r)
return r;
ring = &rdev->ring[R600_RING_TYPE_DMA_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 256 * 1024);
ring = &rdev->ring[CAYMAN_RING_TYPE_DMA1_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 256 * 1024);
r = radeon_uvd_init(rdev);
if (!r) {
ring = &rdev->ring[R600_RING_TYPE_UVD_INDEX];
ring->ring_obj = NULL;
r600_ring_init(rdev, ring, 4096);
}
rdev->ih.ring_obj = NULL;
r600_ih_ring_init(rdev, 64 * 1024);
r = r600_pcie_gart_init(rdev);
if (r)
return r;
rdev->accel_working = true;
r = cik_startup(rdev);
if (r) {
dev_err(rdev->dev, "disabling GPU acceleration\n");
cik_cp_fini(rdev);
cik_sdma_fini(rdev);
cik_irq_fini(rdev);
si_rlc_fini(rdev);
cik_mec_fini(rdev);
radeon_wb_fini(rdev);
radeon_ib_pool_fini(rdev);
radeon_vm_manager_fini(rdev);
radeon_irq_kms_fini(rdev);
cik_pcie_gart_fini(rdev);
rdev->accel_working = false;
}
if (!rdev->mc_fw && !(rdev->flags & RADEON_IS_IGP)) {
DRM_ERROR("radeon: MC ucode required for NI+.\n");
return -EINVAL;
}
return 0;
}
void cik_fini(struct radeon_device *rdev)
{
cik_cp_fini(rdev);
cik_sdma_fini(rdev);
cik_irq_fini(rdev);
si_rlc_fini(rdev);
cik_mec_fini(rdev);
radeon_wb_fini(rdev);
radeon_vm_manager_fini(rdev);
radeon_ib_pool_fini(rdev);
radeon_irq_kms_fini(rdev);
r600_uvd_stop(rdev);
radeon_uvd_fini(rdev);
cik_pcie_gart_fini(rdev);
r600_vram_scratch_fini(rdev);
radeon_gem_fini(rdev);
radeon_fence_driver_fini(rdev);
radeon_bo_fini(rdev);
radeon_atombios_fini(rdev);
kfree(rdev->bios);
rdev->bios = NULL;
}
static u32 dce8_line_buffer_adjust(struct radeon_device *rdev,
struct radeon_crtc *radeon_crtc,
struct drm_display_mode *mode)
{
u32 tmp;
if (radeon_crtc->base.enabled && mode) {
if (mode->crtc_hdisplay < 1920)
tmp = 1;
else if (mode->crtc_hdisplay < 2560)
tmp = 2;
else if (mode->crtc_hdisplay < 4096)
tmp = 0;
else {
DRM_DEBUG_KMS("Mode too big for LB!\n");
tmp = 0;
}
} else
tmp = 1;
WREG32(LB_MEMORY_CTRL + radeon_crtc->crtc_offset,
LB_MEMORY_CONFIG(tmp) | LB_MEMORY_SIZE(0x6B0));
if (radeon_crtc->base.enabled && mode) {
switch (tmp) {
case 0:
default:
return 4096 * 2;
case 1:
return 1920 * 2;
case 2:
return 2560 * 2;
}
}
return 0;
}
static u32 cik_get_number_of_dram_channels(struct radeon_device *rdev)
{
u32 tmp = RREG32(MC_SHARED_CHMAP);
switch ((tmp & NOOFCHAN_MASK) >> NOOFCHAN_SHIFT) {
case 0:
default:
return 1;
case 1:
return 2;
case 2:
return 4;
case 3:
return 8;
case 4:
return 3;
case 5:
return 6;
case 6:
return 10;
case 7:
return 12;
case 8:
return 16;
}
}
static u32 dce8_dram_bandwidth(struct dce8_wm_params *wm)
{
fixed20_12 dram_efficiency;
fixed20_12 yclk, dram_channels, bandwidth;
fixed20_12 a;
a.full = dfixed_const(1000);
yclk.full = dfixed_const(wm->yclk);
yclk.full = dfixed_div(yclk, a);
dram_channels.full = dfixed_const(wm->dram_channels * 4);
a.full = dfixed_const(10);
dram_efficiency.full = dfixed_const(7);
dram_efficiency.full = dfixed_div(dram_efficiency, a);
bandwidth.full = dfixed_mul(dram_channels, yclk);
bandwidth.full = dfixed_mul(bandwidth, dram_efficiency);
return dfixed_trunc(bandwidth);
}
static u32 dce8_dram_bandwidth_for_display(struct dce8_wm_params *wm)
{
fixed20_12 disp_dram_allocation;
fixed20_12 yclk, dram_channels, bandwidth;
fixed20_12 a;
a.full = dfixed_const(1000);
yclk.full = dfixed_const(wm->yclk);
yclk.full = dfixed_div(yclk, a);
dram_channels.full = dfixed_const(wm->dram_channels * 4);
a.full = dfixed_const(10);
disp_dram_allocation.full = dfixed_const(3);
disp_dram_allocation.full = dfixed_div(disp_dram_allocation, a);
bandwidth.full = dfixed_mul(dram_channels, yclk);
bandwidth.full = dfixed_mul(bandwidth, disp_dram_allocation);
return dfixed_trunc(bandwidth);
}
static u32 dce8_data_return_bandwidth(struct dce8_wm_params *wm)
{
fixed20_12 return_efficiency;
fixed20_12 sclk, bandwidth;
fixed20_12 a;
a.full = dfixed_const(1000);
sclk.full = dfixed_const(wm->sclk);
sclk.full = dfixed_div(sclk, a);
a.full = dfixed_const(10);
return_efficiency.full = dfixed_const(8);
return_efficiency.full = dfixed_div(return_efficiency, a);
a.full = dfixed_const(32);
bandwidth.full = dfixed_mul(a, sclk);
bandwidth.full = dfixed_mul(bandwidth, return_efficiency);
return dfixed_trunc(bandwidth);
}
static u32 dce8_dmif_request_bandwidth(struct dce8_wm_params *wm)
{
fixed20_12 disp_clk_request_efficiency;
fixed20_12 disp_clk, bandwidth;
fixed20_12 a, b;
a.full = dfixed_const(1000);
disp_clk.full = dfixed_const(wm->disp_clk);
disp_clk.full = dfixed_div(disp_clk, a);
a.full = dfixed_const(32);
b.full = dfixed_mul(a, disp_clk);
a.full = dfixed_const(10);
disp_clk_request_efficiency.full = dfixed_const(8);
disp_clk_request_efficiency.full = dfixed_div(disp_clk_request_efficiency, a);
bandwidth.full = dfixed_mul(b, disp_clk_request_efficiency);
return dfixed_trunc(bandwidth);
}
static u32 dce8_available_bandwidth(struct dce8_wm_params *wm)
{
u32 dram_bandwidth = dce8_dram_bandwidth(wm);
u32 data_return_bandwidth = dce8_data_return_bandwidth(wm);
u32 dmif_req_bandwidth = dce8_dmif_request_bandwidth(wm);
return min(dram_bandwidth, min(data_return_bandwidth, dmif_req_bandwidth));
}
static u32 dce8_average_bandwidth(struct dce8_wm_params *wm)
{
fixed20_12 bpp;
fixed20_12 line_time;
fixed20_12 src_width;
fixed20_12 bandwidth;
fixed20_12 a;
a.full = dfixed_const(1000);
line_time.full = dfixed_const(wm->active_time + wm->blank_time);
line_time.full = dfixed_div(line_time, a);
bpp.full = dfixed_const(wm->bytes_per_pixel);
src_width.full = dfixed_const(wm->src_width);
bandwidth.full = dfixed_mul(src_width, bpp);
bandwidth.full = dfixed_mul(bandwidth, wm->vsc);
bandwidth.full = dfixed_div(bandwidth, line_time);
return dfixed_trunc(bandwidth);
}
static u32 dce8_latency_watermark(struct dce8_wm_params *wm)
{
u32 mc_latency = 2000;
u32 available_bandwidth = dce8_available_bandwidth(wm);
u32 worst_chunk_return_time = (512 * 8 * 1000) / available_bandwidth;
u32 cursor_line_pair_return_time = (128 * 4 * 1000) / available_bandwidth;
u32 dc_latency = 40000000 / wm->disp_clk;
u32 other_heads_data_return_time = ((wm->num_heads + 1) * worst_chunk_return_time) +
(wm->num_heads * cursor_line_pair_return_time);
u32 latency = mc_latency + other_heads_data_return_time + dc_latency;
u32 max_src_lines_per_dst_line, lb_fill_bw, line_fill_time;
u32 tmp, dmif_size = 12288;
fixed20_12 a, b, c;
if (wm->num_heads == 0)
return 0;
a.full = dfixed_const(2);
b.full = dfixed_const(1);
if ((wm->vsc.full > a.full) ||
((wm->vsc.full > b.full) && (wm->vtaps >= 3)) ||
(wm->vtaps >= 5) ||
((wm->vsc.full >= a.full) && wm->interlaced))
max_src_lines_per_dst_line = 4;
else
max_src_lines_per_dst_line = 2;
a.full = dfixed_const(available_bandwidth);
b.full = dfixed_const(wm->num_heads);
a.full = dfixed_div(a, b);
b.full = dfixed_const(mc_latency + 512);
c.full = dfixed_const(wm->disp_clk);
b.full = dfixed_div(b, c);
c.full = dfixed_const(dmif_size);
b.full = dfixed_div(c, b);
tmp = min(dfixed_trunc(a), dfixed_trunc(b));
b.full = dfixed_const(1000);
c.full = dfixed_const(wm->disp_clk);
b.full = dfixed_div(c, b);
c.full = dfixed_const(wm->bytes_per_pixel);
b.full = dfixed_mul(b, c);
lb_fill_bw = min(tmp, dfixed_trunc(b));
a.full = dfixed_const(max_src_lines_per_dst_line * wm->src_width * wm->bytes_per_pixel);
b.full = dfixed_const(1000);
c.full = dfixed_const(lb_fill_bw);
b.full = dfixed_div(c, b);
a.full = dfixed_div(a, b);
line_fill_time = dfixed_trunc(a);
if (line_fill_time < wm->active_time)
return latency;
else
return latency + (line_fill_time - wm->active_time);
}
static bool dce8_average_bandwidth_vs_dram_bandwidth_for_display(struct dce8_wm_params *wm)
{
if (dce8_average_bandwidth(wm) <=
(dce8_dram_bandwidth_for_display(wm) / wm->num_heads))
return true;
else
return false;
}
static bool dce8_average_bandwidth_vs_available_bandwidth(struct dce8_wm_params *wm)
{
if (dce8_average_bandwidth(wm) <=
(dce8_available_bandwidth(wm) / wm->num_heads))
return true;
else
return false;
}
static bool dce8_check_latency_hiding(struct dce8_wm_params *wm)
{
u32 lb_partitions = wm->lb_size / wm->src_width;
u32 line_time = wm->active_time + wm->blank_time;
u32 latency_tolerant_lines;
u32 latency_hiding;
fixed20_12 a;
a.full = dfixed_const(1);
if (wm->vsc.full > a.full)
latency_tolerant_lines = 1;
else {
if (lb_partitions <= (wm->vtaps + 1))
latency_tolerant_lines = 1;
else
latency_tolerant_lines = 2;
}
latency_hiding = (latency_tolerant_lines * line_time + wm->blank_time);
if (dce8_latency_watermark(wm) <= latency_hiding)
return true;
else
return false;
}
static void dce8_program_watermarks(struct radeon_device *rdev,
struct radeon_crtc *radeon_crtc,
u32 lb_size, u32 num_heads)
{
struct drm_display_mode *mode = &radeon_crtc->base.mode;
struct dce8_wm_params wm;
u32 pixel_period;
u32 line_time = 0;
u32 latency_watermark_a = 0, latency_watermark_b = 0;
u32 tmp, wm_mask;
if (radeon_crtc->base.enabled && num_heads && mode) {
pixel_period = 1000000 / (u32)mode->clock;
line_time = min((u32)mode->crtc_htotal * pixel_period, (u32)65535);
wm.yclk = rdev->pm.current_mclk * 10;
wm.sclk = rdev->pm.current_sclk * 10;
wm.disp_clk = mode->clock;
wm.src_width = mode->crtc_hdisplay;
wm.active_time = mode->crtc_hdisplay * pixel_period;
wm.blank_time = line_time - wm.active_time;
wm.interlaced = false;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
wm.interlaced = true;
wm.vsc = radeon_crtc->vsc;
wm.vtaps = 1;
if (radeon_crtc->rmx_type != RMX_OFF)
wm.vtaps = 2;
wm.bytes_per_pixel = 4;
wm.lb_size = lb_size;
wm.dram_channels = cik_get_number_of_dram_channels(rdev);
wm.num_heads = num_heads;
latency_watermark_a = min(dce8_latency_watermark(&wm), (u32)65535);
latency_watermark_b = min(dce8_latency_watermark(&wm), (u32)65535);
if (!dce8_average_bandwidth_vs_dram_bandwidth_for_display(&wm) ||
!dce8_average_bandwidth_vs_available_bandwidth(&wm) ||
!dce8_check_latency_hiding(&wm) ||
(rdev->disp_priority == 2)) {
DRM_DEBUG_KMS("force priority to high\n");
}
}
wm_mask = RREG32(DPG_WATERMARK_MASK_CONTROL + radeon_crtc->crtc_offset);
tmp = wm_mask;
tmp &= ~LATENCY_WATERMARK_MASK(3);
tmp |= LATENCY_WATERMARK_MASK(1);
WREG32(DPG_WATERMARK_MASK_CONTROL + radeon_crtc->crtc_offset, tmp);
WREG32(DPG_PIPE_LATENCY_CONTROL + radeon_crtc->crtc_offset,
(LATENCY_LOW_WATERMARK(latency_watermark_a) |
LATENCY_HIGH_WATERMARK(line_time)));
tmp = RREG32(DPG_WATERMARK_MASK_CONTROL + radeon_crtc->crtc_offset);
tmp &= ~LATENCY_WATERMARK_MASK(3);
tmp |= LATENCY_WATERMARK_MASK(2);
WREG32(DPG_WATERMARK_MASK_CONTROL + radeon_crtc->crtc_offset, tmp);
WREG32(DPG_PIPE_LATENCY_CONTROL + radeon_crtc->crtc_offset,
(LATENCY_LOW_WATERMARK(latency_watermark_b) |
LATENCY_HIGH_WATERMARK(line_time)));
WREG32(DPG_WATERMARK_MASK_CONTROL + radeon_crtc->crtc_offset, wm_mask);
}
void dce8_bandwidth_update(struct radeon_device *rdev)
{
struct drm_display_mode *mode = NULL;
u32 num_heads = 0, lb_size;
int i;
radeon_update_display_priority(rdev);
for (i = 0; i < rdev->num_crtc; i++) {
if (rdev->mode_info.crtcs[i]->base.enabled)
num_heads++;
}
for (i = 0; i < rdev->num_crtc; i++) {
mode = &rdev->mode_info.crtcs[i]->base.mode;
lb_size = dce8_line_buffer_adjust(rdev, rdev->mode_info.crtcs[i], mode);
dce8_program_watermarks(rdev, rdev->mode_info.crtcs[i], lb_size, num_heads);
}
}
uint64_t cik_get_gpu_clock_counter(struct radeon_device *rdev)
{
uint64_t clock;
mutex_lock(&rdev->gpu_clock_mutex);
WREG32(RLC_CAPTURE_GPU_CLOCK_COUNT, 1);
clock = (uint64_t)RREG32(RLC_GPU_CLOCK_COUNT_LSB) |
((uint64_t)RREG32(RLC_GPU_CLOCK_COUNT_MSB) << 32ULL);
mutex_unlock(&rdev->gpu_clock_mutex);
return clock;
}
static int cik_set_uvd_clock(struct radeon_device *rdev, u32 clock,
u32 cntl_reg, u32 status_reg)
{
int r, i;
struct atom_clock_dividers dividers;
uint32_t tmp;
r = radeon_atom_get_clock_dividers(rdev, COMPUTE_GPUCLK_INPUT_FLAG_DEFAULT_GPUCLK,
clock, false, &dividers);
if (r)
return r;
tmp = RREG32_SMC(cntl_reg);
tmp &= ~(DCLK_DIR_CNTL_EN|DCLK_DIVIDER_MASK);
tmp |= dividers.post_divider;
WREG32_SMC(cntl_reg, tmp);
for (i = 0; i < 100; i++) {
if (RREG32_SMC(status_reg) & DCLK_STATUS)
break;
mdelay(10);
}
if (i == 100)
return -ETIMEDOUT;
return 0;
}
int cik_set_uvd_clocks(struct radeon_device *rdev, u32 vclk, u32 dclk)
{
int r = 0;
r = cik_set_uvd_clock(rdev, vclk, CG_VCLK_CNTL, CG_VCLK_STATUS);
if (r)
return r;
r = cik_set_uvd_clock(rdev, dclk, CG_DCLK_CNTL, CG_DCLK_STATUS);
return r;
}
int cik_uvd_resume(struct radeon_device *rdev)
{
uint64_t addr;
uint32_t size;
int r;
r = radeon_uvd_resume(rdev);
if (r)
return r;
addr = rdev->uvd.gpu_addr >> 3;
size = RADEON_GPU_PAGE_ALIGN(rdev->uvd_fw->size + 4) >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET0, addr);
WREG32(UVD_VCPU_CACHE_SIZE0, size);
addr += size;
size = RADEON_UVD_STACK_SIZE >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET1, addr);
WREG32(UVD_VCPU_CACHE_SIZE1, size);
addr += size;
size = RADEON_UVD_HEAP_SIZE >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET2, addr);
WREG32(UVD_VCPU_CACHE_SIZE2, size);
addr = (rdev->uvd.gpu_addr >> 28) & 0xF;
WREG32(UVD_LMI_ADDR_EXT, (addr << 12) | (addr << 0));
addr = (rdev->uvd.gpu_addr >> 32) & 0xFF;
WREG32(UVD_LMI_EXT40_ADDR, addr | (0x9 << 16) | (0x1 << 31));
return 0;
}
