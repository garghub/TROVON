static int gfx_v7_0_init_microcode(struct amdgpu_device *adev)
{
const char *chip_name;
char fw_name[30];
int err;
DRM_DEBUG("\n");
switch (adev->asic_type) {
case CHIP_BONAIRE:
chip_name = "bonaire";
break;
case CHIP_HAWAII:
chip_name = "hawaii";
break;
case CHIP_KAVERI:
chip_name = "kaveri";
break;
case CHIP_KABINI:
chip_name = "kabini";
break;
case CHIP_MULLINS:
chip_name = "mullins";
break;
default: BUG();
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_pfp.bin", chip_name);
err = request_firmware(&adev->gfx.pfp_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.pfp_fw);
if (err)
goto out;
snprintf(fw_name, sizeof(fw_name), "radeon/%s_me.bin", chip_name);
err = request_firmware(&adev->gfx.me_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.me_fw);
if (err)
goto out;
snprintf(fw_name, sizeof(fw_name), "radeon/%s_ce.bin", chip_name);
err = request_firmware(&adev->gfx.ce_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.ce_fw);
if (err)
goto out;
snprintf(fw_name, sizeof(fw_name), "radeon/%s_mec.bin", chip_name);
err = request_firmware(&adev->gfx.mec_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.mec_fw);
if (err)
goto out;
if (adev->asic_type == CHIP_KAVERI) {
snprintf(fw_name, sizeof(fw_name), "radeon/%s_mec2.bin", chip_name);
err = request_firmware(&adev->gfx.mec2_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.mec2_fw);
if (err)
goto out;
}
snprintf(fw_name, sizeof(fw_name), "radeon/%s_rlc.bin", chip_name);
err = request_firmware(&adev->gfx.rlc_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.rlc_fw);
out:
if (err) {
printk(KERN_ERR
"gfx7: Failed to load firmware \"%s\"\n",
fw_name);
release_firmware(adev->gfx.pfp_fw);
adev->gfx.pfp_fw = NULL;
release_firmware(adev->gfx.me_fw);
adev->gfx.me_fw = NULL;
release_firmware(adev->gfx.ce_fw);
adev->gfx.ce_fw = NULL;
release_firmware(adev->gfx.mec_fw);
adev->gfx.mec_fw = NULL;
release_firmware(adev->gfx.mec2_fw);
adev->gfx.mec2_fw = NULL;
release_firmware(adev->gfx.rlc_fw);
adev->gfx.rlc_fw = NULL;
}
return err;
}
static void gfx_v7_0_free_microcode(struct amdgpu_device *adev)
{
release_firmware(adev->gfx.pfp_fw);
adev->gfx.pfp_fw = NULL;
release_firmware(adev->gfx.me_fw);
adev->gfx.me_fw = NULL;
release_firmware(adev->gfx.ce_fw);
adev->gfx.ce_fw = NULL;
release_firmware(adev->gfx.mec_fw);
adev->gfx.mec_fw = NULL;
release_firmware(adev->gfx.mec2_fw);
adev->gfx.mec2_fw = NULL;
release_firmware(adev->gfx.rlc_fw);
adev->gfx.rlc_fw = NULL;
}
static void gfx_v7_0_tiling_mode_table_init(struct amdgpu_device *adev)
{
const u32 num_tile_mode_states =
ARRAY_SIZE(adev->gfx.config.tile_mode_array);
const u32 num_secondary_tile_mode_states =
ARRAY_SIZE(adev->gfx.config.macrotile_mode_array);
u32 reg_offset, split_equal_to_row_size;
uint32_t *tile, *macrotile;
tile = adev->gfx.config.tile_mode_array;
macrotile = adev->gfx.config.macrotile_mode_array;
switch (adev->gfx.config.mem_row_size_in_kb) {
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
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++)
tile[reg_offset] = 0;
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++)
macrotile[reg_offset] = 0;
switch (adev->asic_type) {
case CHIP_BONAIRE:
tile[0] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[1] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[2] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[3] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[4] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[5] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[6] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[7] = (TILE_SPLIT(split_equal_to_row_size));
tile[8] = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P4_16x16));
tile[9] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
tile[10] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[11] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[12] = (TILE_SPLIT(split_equal_to_row_size));
tile[13] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
tile[14] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[15] = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[16] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[17] = (TILE_SPLIT(split_equal_to_row_size));
tile[18] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[19] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
tile[20] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[21] = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[22] = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[23] = (TILE_SPLIT(split_equal_to_row_size));
tile[24] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[25] = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[26] = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[27] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
tile[28] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[29] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[30] = (TILE_SPLIT(split_equal_to_row_size));
macrotile[0] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[1] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[2] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[3] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[4] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[5] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[6] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
macrotile[8] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_8) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[9] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[10] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[11] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[12] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[13] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[14] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++)
WREG32(mmGB_TILE_MODE0 + reg_offset, tile[reg_offset]);
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++)
if (reg_offset != 7)
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, macrotile[reg_offset]);
break;
case CHIP_HAWAII:
tile[0] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[1] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[2] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[3] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[4] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[5] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[6] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[7] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[8] = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16));
tile[9] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
tile[10] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[11] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[12] = (ARRAY_MODE(ARRAY_PRT_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[13] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
tile[14] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[15] = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[16] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[17] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[18] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[19] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING));
tile[20] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[21] = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[22] = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[23] = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[24] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[25] = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[26] = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[27] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
tile[28] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[29] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P16_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[30] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
macrotile[0] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[1] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[2] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[3] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[4] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[5] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
macrotile[6] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
macrotile[8] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[9] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[10] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[11] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[12] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[13] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[14] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_4_BANK));
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++)
WREG32(mmGB_TILE_MODE0 + reg_offset, tile[reg_offset]);
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++)
if (reg_offset != 7)
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, macrotile[reg_offset]);
break;
case CHIP_KABINI:
case CHIP_KAVERI:
case CHIP_MULLINS:
default:
tile[0] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[1] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[2] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[3] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[4] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[5] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
tile[6] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING) |
TILE_SPLIT(split_equal_to_row_size));
tile[7] = (TILE_SPLIT(split_equal_to_row_size));
tile[8] = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P2));
tile[9] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING));
tile[10] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[11] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[12] = (TILE_SPLIT(split_equal_to_row_size));
tile[13] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING));
tile[14] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[15] = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[16] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[17] = (TILE_SPLIT(split_equal_to_row_size));
tile[18] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[19] = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING));
tile[20] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[21] = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[22] = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[23] = (TILE_SPLIT(split_equal_to_row_size));
tile[24] = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[25] = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[26] = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
tile[27] = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING));
tile[28] = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
tile[29] = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
tile[30] = (TILE_SPLIT(split_equal_to_row_size));
macrotile[0] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[1] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[2] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[3] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[4] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[5] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[6] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
macrotile[8] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_8) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[9] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[10] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[11] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[12] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[13] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
macrotile[14] = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++)
WREG32(mmGB_TILE_MODE0 + reg_offset, tile[reg_offset]);
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++)
if (reg_offset != 7)
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, macrotile[reg_offset]);
break;
}
}
static void gfx_v7_0_select_se_sh(struct amdgpu_device *adev,
u32 se_num, u32 sh_num, u32 instance)
{
u32 data;
if (instance == 0xffffffff)
data = REG_SET_FIELD(0, GRBM_GFX_INDEX, INSTANCE_BROADCAST_WRITES, 1);
else
data = REG_SET_FIELD(0, GRBM_GFX_INDEX, INSTANCE_INDEX, instance);
if ((se_num == 0xffffffff) && (sh_num == 0xffffffff))
data |= GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK |
GRBM_GFX_INDEX__SE_BROADCAST_WRITES_MASK;
else if (se_num == 0xffffffff)
data |= GRBM_GFX_INDEX__SE_BROADCAST_WRITES_MASK |
(sh_num << GRBM_GFX_INDEX__SH_INDEX__SHIFT);
else if (sh_num == 0xffffffff)
data |= GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK |
(se_num << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
else
data |= (sh_num << GRBM_GFX_INDEX__SH_INDEX__SHIFT) |
(se_num << GRBM_GFX_INDEX__SE_INDEX__SHIFT);
WREG32(mmGRBM_GFX_INDEX, data);
}
static u32 gfx_v7_0_create_bitmask(u32 bit_width)
{
return (u32)((1ULL << bit_width) - 1);
}
static u32 gfx_v7_0_get_rb_active_bitmap(struct amdgpu_device *adev)
{
u32 data, mask;
data = RREG32(mmCC_RB_BACKEND_DISABLE);
data |= RREG32(mmGC_USER_RB_BACKEND_DISABLE);
data &= CC_RB_BACKEND_DISABLE__BACKEND_DISABLE_MASK;
data >>= GC_USER_RB_BACKEND_DISABLE__BACKEND_DISABLE__SHIFT;
mask = gfx_v7_0_create_bitmask(adev->gfx.config.max_backends_per_se /
adev->gfx.config.max_sh_per_se);
return (~data) & mask;
}
static void gfx_v7_0_setup_rb(struct amdgpu_device *adev)
{
int i, j;
u32 data;
u32 active_rbs = 0;
u32 rb_bitmap_width_per_sh = adev->gfx.config.max_backends_per_se /
adev->gfx.config.max_sh_per_se;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
gfx_v7_0_select_se_sh(adev, i, j, 0xffffffff);
data = gfx_v7_0_get_rb_active_bitmap(adev);
active_rbs |= data << ((i * adev->gfx.config.max_sh_per_se + j) *
rb_bitmap_width_per_sh);
}
}
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
adev->gfx.config.backend_enable_mask = active_rbs;
adev->gfx.config.num_rbs = hweight32(active_rbs);
}
static void gmc_v7_0_init_compute_vmid(struct amdgpu_device *adev)
{
int i;
uint32_t sh_mem_config;
uint32_t sh_mem_bases;
sh_mem_bases = DEFAULT_SH_MEM_BASES | (DEFAULT_SH_MEM_BASES << 16);
sh_mem_config = SH_MEM_ALIGNMENT_MODE_UNALIGNED <<
SH_MEM_CONFIG__ALIGNMENT_MODE__SHIFT;
sh_mem_config |= MTYPE_NONCACHED << SH_MEM_CONFIG__DEFAULT_MTYPE__SHIFT;
mutex_lock(&adev->srbm_mutex);
for (i = FIRST_COMPUTE_VMID; i < LAST_COMPUTE_VMID; i++) {
cik_srbm_select(adev, 0, 0, 0, i);
WREG32(mmSH_MEM_CONFIG, sh_mem_config);
WREG32(mmSH_MEM_APE1_BASE, 1);
WREG32(mmSH_MEM_APE1_LIMIT, 0);
WREG32(mmSH_MEM_BASES, sh_mem_bases);
}
cik_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
}
static void gfx_v7_0_gpu_init(struct amdgpu_device *adev)
{
u32 tmp, sh_mem_cfg;
int i;
WREG32(mmGRBM_CNTL, (0xff << GRBM_CNTL__READ_TIMEOUT__SHIFT));
WREG32(mmGB_ADDR_CONFIG, adev->gfx.config.gb_addr_config);
WREG32(mmHDP_ADDR_CONFIG, adev->gfx.config.gb_addr_config);
WREG32(mmDMIF_ADDR_CALC, adev->gfx.config.gb_addr_config);
gfx_v7_0_tiling_mode_table_init(adev);
gfx_v7_0_setup_rb(adev);
gfx_v7_0_get_cu_info(adev);
WREG32(mmCP_MEQ_THRESHOLDS,
(0x30 << CP_MEQ_THRESHOLDS__MEQ1_START__SHIFT) |
(0x60 << CP_MEQ_THRESHOLDS__MEQ2_START__SHIFT));
mutex_lock(&adev->grbm_idx_mutex);
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
sh_mem_cfg = REG_SET_FIELD(0, SH_MEM_CONFIG, ALIGNMENT_MODE,
SH_MEM_ALIGNMENT_MODE_UNALIGNED);
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < 16; i++) {
cik_srbm_select(adev, 0, 0, 0, i);
WREG32(mmSH_MEM_CONFIG, sh_mem_cfg);
WREG32(mmSH_MEM_APE1_BASE, 1);
WREG32(mmSH_MEM_APE1_LIMIT, 0);
WREG32(mmSH_MEM_BASES, 0);
}
cik_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
gmc_v7_0_init_compute_vmid(adev);
WREG32(mmSX_DEBUG_1, 0x20);
WREG32(mmTA_CNTL_AUX, 0x00010000);
tmp = RREG32(mmSPI_CONFIG_CNTL);
tmp |= 0x03000000;
WREG32(mmSPI_CONFIG_CNTL, tmp);
WREG32(mmSQ_CONFIG, 1);
WREG32(mmDB_DEBUG, 0);
tmp = RREG32(mmDB_DEBUG2) & ~0xf00fffff;
tmp |= 0x00000400;
WREG32(mmDB_DEBUG2, tmp);
tmp = RREG32(mmDB_DEBUG3) & ~0x0002021c;
tmp |= 0x00020200;
WREG32(mmDB_DEBUG3, tmp);
tmp = RREG32(mmCB_HW_CONTROL) & ~0x00010000;
tmp |= 0x00018208;
WREG32(mmCB_HW_CONTROL, tmp);
WREG32(mmSPI_CONFIG_CNTL_1, (4 << SPI_CONFIG_CNTL_1__VTX_DONE_DELAY__SHIFT));
WREG32(mmPA_SC_FIFO_SIZE,
((adev->gfx.config.sc_prim_fifo_size_frontend << PA_SC_FIFO_SIZE__SC_FRONTEND_PRIM_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_prim_fifo_size_backend << PA_SC_FIFO_SIZE__SC_BACKEND_PRIM_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_hiz_tile_fifo_size << PA_SC_FIFO_SIZE__SC_HIZ_TILE_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_earlyz_tile_fifo_size << PA_SC_FIFO_SIZE__SC_EARLYZ_TILE_FIFO_SIZE__SHIFT)));
WREG32(mmVGT_NUM_INSTANCES, 1);
WREG32(mmCP_PERFMON_CNTL, 0);
WREG32(mmSQ_CONFIG, 0);
WREG32(mmPA_SC_FORCE_EOV_MAX_CNTS,
((4095 << PA_SC_FORCE_EOV_MAX_CNTS__FORCE_EOV_MAX_CLK_CNT__SHIFT) |
(255 << PA_SC_FORCE_EOV_MAX_CNTS__FORCE_EOV_MAX_REZ_CNT__SHIFT)));
WREG32(mmVGT_CACHE_INVALIDATION,
(VC_AND_TC << VGT_CACHE_INVALIDATION__CACHE_INVALIDATION__SHIFT) |
(ES_AND_GS_AUTO << VGT_CACHE_INVALIDATION__AUTO_INVLD_EN__SHIFT));
WREG32(mmVGT_GS_VERTEX_REUSE, 16);
WREG32(mmPA_SC_LINE_STIPPLE_STATE, 0);
WREG32(mmPA_CL_ENHANCE, PA_CL_ENHANCE__CLIP_VTX_REORDER_ENA_MASK |
(3 << PA_CL_ENHANCE__NUM_CLIP_SEQ__SHIFT));
WREG32(mmPA_SC_ENHANCE, PA_SC_ENHANCE__ENABLE_PA_SC_OUT_OF_ORDER_MASK);
mutex_unlock(&adev->grbm_idx_mutex);
udelay(50);
}
static void gfx_v7_0_scratch_init(struct amdgpu_device *adev)
{
int i;
adev->gfx.scratch.num_reg = 7;
adev->gfx.scratch.reg_base = mmSCRATCH_REG0;
for (i = 0; i < adev->gfx.scratch.num_reg; i++) {
adev->gfx.scratch.free[i] = true;
adev->gfx.scratch.reg[i] = adev->gfx.scratch.reg_base + i;
}
}
static int gfx_v7_0_ring_test_ring(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = amdgpu_gfx_scratch_get(adev, &scratch);
if (r) {
DRM_ERROR("amdgpu: cp failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = amdgpu_ring_alloc(ring, 3);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring %d (%d).\n", ring->idx, r);
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_UCONFIG_REG, 1));
amdgpu_ring_write(ring, (scratch - PACKET3_SET_UCONFIG_REG_START));
amdgpu_ring_write(ring, 0xDEADBEEF);
amdgpu_ring_commit(ring);
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n", ring->idx, i);
} else {
DRM_ERROR("amdgpu: ring %d test failed (scratch(0x%04X)=0x%08X)\n",
ring->idx, scratch, tmp);
r = -EINVAL;
}
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
static void gfx_v7_0_ring_emit_hdp_flush(struct amdgpu_ring *ring)
{
u32 ref_and_mask;
int usepfp = ring->type == AMDGPU_RING_TYPE_COMPUTE ? 0 : 1;
if (ring->type == AMDGPU_RING_TYPE_COMPUTE) {
switch (ring->me) {
case 1:
ref_and_mask = GPU_HDP_FLUSH_DONE__CP2_MASK << ring->pipe;
break;
case 2:
ref_and_mask = GPU_HDP_FLUSH_DONE__CP6_MASK << ring->pipe;
break;
default:
return;
}
} else {
ref_and_mask = GPU_HDP_FLUSH_DONE__CP0_MASK;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring, (WAIT_REG_MEM_OPERATION(1) |
WAIT_REG_MEM_FUNCTION(3) |
WAIT_REG_MEM_ENGINE(usepfp)));
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_REQ);
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_DONE);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, 0x20);
}
static void gfx_v7_0_ring_emit_hdp_invalidate(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0) |
WR_CONFIRM));
amdgpu_ring_write(ring, mmHDP_DEBUG0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 1);
}
static void gfx_v7_0_ring_emit_fence_gfx(struct amdgpu_ring *ring, u64 addr,
u64 seq, unsigned flags)
{
bool write64bit = flags & AMDGPU_FENCE_FLAG_64BIT;
bool int_sel = flags & AMDGPU_FENCE_FLAG_INT;
amdgpu_ring_write(ring, PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
amdgpu_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
amdgpu_ring_write(ring, addr & 0xfffffffc);
amdgpu_ring_write(ring, (upper_32_bits(addr) & 0xffff) |
DATA_SEL(1) | INT_SEL(0));
amdgpu_ring_write(ring, lower_32_bits(seq - 1));
amdgpu_ring_write(ring, upper_32_bits(seq - 1));
amdgpu_ring_write(ring, PACKET3(PACKET3_EVENT_WRITE_EOP, 4));
amdgpu_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
amdgpu_ring_write(ring, addr & 0xfffffffc);
amdgpu_ring_write(ring, (upper_32_bits(addr) & 0xffff) |
DATA_SEL(write64bit ? 2 : 1) | INT_SEL(int_sel ? 2 : 0));
amdgpu_ring_write(ring, lower_32_bits(seq));
amdgpu_ring_write(ring, upper_32_bits(seq));
}
static void gfx_v7_0_ring_emit_fence_compute(struct amdgpu_ring *ring,
u64 addr, u64 seq,
unsigned flags)
{
bool write64bit = flags & AMDGPU_FENCE_FLAG_64BIT;
bool int_sel = flags & AMDGPU_FENCE_FLAG_INT;
amdgpu_ring_write(ring, PACKET3(PACKET3_RELEASE_MEM, 5));
amdgpu_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
amdgpu_ring_write(ring, DATA_SEL(write64bit ? 2 : 1) | INT_SEL(int_sel ? 2 : 0));
amdgpu_ring_write(ring, addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, lower_32_bits(seq));
amdgpu_ring_write(ring, upper_32_bits(seq));
}
static void gfx_v7_0_ring_emit_ib_gfx(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 header, control = 0;
if (ctx_switch) {
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
}
if (ib->flags & AMDGPU_IB_FLAG_CE)
header = PACKET3(PACKET3_INDIRECT_BUFFER_CONST, 2);
else
header = PACKET3(PACKET3_INDIRECT_BUFFER, 2);
control |= ib->length_dw | (vm_id << 24);
amdgpu_ring_write(ring, header);
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
amdgpu_ring_write(ring, control);
}
static void gfx_v7_0_ring_emit_ib_compute(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 control = INDIRECT_BUFFER_VALID | ib->length_dw | (vm_id << 24);
amdgpu_ring_write(ring, PACKET3(PACKET3_INDIRECT_BUFFER, 2));
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
amdgpu_ring_write(ring, control);
}
static int gfx_v7_0_ring_test_ib(struct amdgpu_ring *ring, long timeout)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib ib;
struct fence *f = NULL;
uint32_t scratch;
uint32_t tmp = 0;
long r;
r = amdgpu_gfx_scratch_get(adev, &scratch);
if (r) {
DRM_ERROR("amdgpu: failed to get scratch reg (%ld).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
memset(&ib, 0, sizeof(ib));
r = amdgpu_ib_get(adev, NULL, 256, &ib);
if (r) {
DRM_ERROR("amdgpu: failed to get ib (%ld).\n", r);
goto err1;
}
ib.ptr[0] = PACKET3(PACKET3_SET_UCONFIG_REG, 1);
ib.ptr[1] = ((scratch - PACKET3_SET_UCONFIG_REG_START));
ib.ptr[2] = 0xDEADBEEF;
ib.length_dw = 3;
r = amdgpu_ib_schedule(ring, 1, &ib, NULL, NULL, &f);
if (r)
goto err2;
r = fence_wait_timeout(f, false, timeout);
if (r == 0) {
DRM_ERROR("amdgpu: IB test timed out\n");
r = -ETIMEDOUT;
goto err2;
} else if (r < 0) {
DRM_ERROR("amdgpu: fence wait failed (%ld).\n", r);
goto err2;
}
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF) {
DRM_INFO("ib test on ring %d succeeded\n", ring->idx);
r = 0;
} else {
DRM_ERROR("amdgpu: ib test failed (scratch(0x%04X)=0x%08X)\n",
scratch, tmp);
r = -EINVAL;
}
err2:
amdgpu_ib_free(adev, &ib, NULL);
fence_put(f);
err1:
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
static void gfx_v7_0_cp_gfx_enable(struct amdgpu_device *adev, bool enable)
{
int i;
if (enable) {
WREG32(mmCP_ME_CNTL, 0);
} else {
WREG32(mmCP_ME_CNTL, (CP_ME_CNTL__ME_HALT_MASK | CP_ME_CNTL__PFP_HALT_MASK | CP_ME_CNTL__CE_HALT_MASK));
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].ready = false;
}
udelay(50);
}
static int gfx_v7_0_cp_gfx_load_microcode(struct amdgpu_device *adev)
{
const struct gfx_firmware_header_v1_0 *pfp_hdr;
const struct gfx_firmware_header_v1_0 *ce_hdr;
const struct gfx_firmware_header_v1_0 *me_hdr;
const __le32 *fw_data;
unsigned i, fw_size;
if (!adev->gfx.me_fw || !adev->gfx.pfp_fw || !adev->gfx.ce_fw)
return -EINVAL;
pfp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.pfp_fw->data;
ce_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.ce_fw->data;
me_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.me_fw->data;
amdgpu_ucode_print_gfx_hdr(&pfp_hdr->header);
amdgpu_ucode_print_gfx_hdr(&ce_hdr->header);
amdgpu_ucode_print_gfx_hdr(&me_hdr->header);
adev->gfx.pfp_fw_version = le32_to_cpu(pfp_hdr->header.ucode_version);
adev->gfx.ce_fw_version = le32_to_cpu(ce_hdr->header.ucode_version);
adev->gfx.me_fw_version = le32_to_cpu(me_hdr->header.ucode_version);
adev->gfx.me_feature_version = le32_to_cpu(me_hdr->ucode_feature_version);
adev->gfx.ce_feature_version = le32_to_cpu(ce_hdr->ucode_feature_version);
adev->gfx.pfp_feature_version = le32_to_cpu(pfp_hdr->ucode_feature_version);
gfx_v7_0_cp_gfx_enable(adev, false);
fw_data = (const __le32 *)
(adev->gfx.pfp_fw->data +
le32_to_cpu(pfp_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(pfp_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_PFP_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_PFP_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmCP_PFP_UCODE_ADDR, adev->gfx.pfp_fw_version);
fw_data = (const __le32 *)
(adev->gfx.ce_fw->data +
le32_to_cpu(ce_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(ce_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_CE_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_CE_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmCP_CE_UCODE_ADDR, adev->gfx.ce_fw_version);
fw_data = (const __le32 *)
(adev->gfx.me_fw->data +
le32_to_cpu(me_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(me_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_ME_RAM_WADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_ME_RAM_DATA, le32_to_cpup(fw_data++));
WREG32(mmCP_ME_RAM_WADDR, adev->gfx.me_fw_version);
return 0;
}
static int gfx_v7_0_cp_gfx_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->gfx.gfx_ring[0];
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
int r, i;
WREG32(mmCP_MAX_CONTEXT, adev->gfx.config.max_hw_contexts - 1);
WREG32(mmCP_ENDIAN_SWAP, 0);
WREG32(mmCP_DEVICE_ID, 1);
gfx_v7_0_cp_gfx_enable(adev, true);
r = amdgpu_ring_alloc(ring, gfx_v7_0_get_csb_size(adev) + 8);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring (%d).\n", r);
return r;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_BASE, 2));
amdgpu_ring_write(ring, PACKET3_BASE_INDEX(CE_PARTITION_BASE));
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CONTEXT_CONTROL, 1));
amdgpu_ring_write(ring, 0x80000000);
amdgpu_ring_write(ring, 0x80000000);
for (sect = adev->gfx.rlc.cs_data; sect->section != NULL; ++sect) {
for (ext = sect->section; ext->extent != NULL; ++ext) {
if (sect->id == SECT_CONTEXT) {
amdgpu_ring_write(ring,
PACKET3(PACKET3_SET_CONTEXT_REG, ext->reg_count));
amdgpu_ring_write(ring, ext->reg_index - PACKET3_SET_CONTEXT_REG_START);
for (i = 0; i < ext->reg_count; i++)
amdgpu_ring_write(ring, ext->extent[i]);
}
}
}
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_CONTEXT_REG, 2));
amdgpu_ring_write(ring, mmPA_SC_RASTER_CONFIG - PACKET3_SET_CONTEXT_REG_START);
switch (adev->asic_type) {
case CHIP_BONAIRE:
amdgpu_ring_write(ring, 0x16000012);
amdgpu_ring_write(ring, 0x00000000);
break;
case CHIP_KAVERI:
amdgpu_ring_write(ring, 0x00000000);
amdgpu_ring_write(ring, 0x00000000);
break;
case CHIP_KABINI:
case CHIP_MULLINS:
amdgpu_ring_write(ring, 0x00000000);
amdgpu_ring_write(ring, 0x00000000);
break;
case CHIP_HAWAII:
amdgpu_ring_write(ring, 0x3a00161a);
amdgpu_ring_write(ring, 0x0000002e);
break;
default:
amdgpu_ring_write(ring, 0x00000000);
amdgpu_ring_write(ring, 0x00000000);
break;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_END_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CLEAR_STATE, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_CONTEXT_REG, 2));
amdgpu_ring_write(ring, 0x00000316);
amdgpu_ring_write(ring, 0x0000000e);
amdgpu_ring_write(ring, 0x00000010);
amdgpu_ring_commit(ring);
return 0;
}
static int gfx_v7_0_cp_gfx_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
u32 tmp;
u32 rb_bufsz;
u64 rb_addr, rptr_addr;
int r;
WREG32(mmCP_SEM_WAIT_TIMER, 0x0);
if (adev->asic_type != CHIP_HAWAII)
WREG32(mmCP_SEM_INCOMPLETE_TIMER_CNTL, 0x0);
WREG32(mmCP_RB_WPTR_DELAY, 0);
WREG32(mmCP_RB_VMID, 0);
WREG32(mmSCRATCH_ADDR, 0);
ring = &adev->gfx.gfx_ring[0];
rb_bufsz = order_base_2(ring->ring_size / 8);
tmp = (order_base_2(AMDGPU_GPU_PAGE_SIZE/8) << 8) | rb_bufsz;
#ifdef __BIG_ENDIAN
tmp |= 2 << CP_RB0_CNTL__BUF_SWAP__SHIFT;
#endif
WREG32(mmCP_RB0_CNTL, tmp);
WREG32(mmCP_RB0_CNTL, tmp | CP_RB0_CNTL__RB_RPTR_WR_ENA_MASK);
ring->wptr = 0;
WREG32(mmCP_RB0_WPTR, ring->wptr);
rptr_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
WREG32(mmCP_RB0_RPTR_ADDR, lower_32_bits(rptr_addr));
WREG32(mmCP_RB0_RPTR_ADDR_HI, upper_32_bits(rptr_addr) & 0xFF);
WREG32(mmSCRATCH_UMSK, 0);
mdelay(1);
WREG32(mmCP_RB0_CNTL, tmp);
rb_addr = ring->gpu_addr >> 8;
WREG32(mmCP_RB0_BASE, rb_addr);
WREG32(mmCP_RB0_BASE_HI, upper_32_bits(rb_addr));
gfx_v7_0_cp_gfx_start(adev);
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
return 0;
}
static u32 gfx_v7_0_ring_get_rptr_gfx(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs];
}
static u32 gfx_v7_0_ring_get_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
return RREG32(mmCP_RB0_WPTR);
}
static void gfx_v7_0_ring_set_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
WREG32(mmCP_RB0_WPTR, ring->wptr);
(void)RREG32(mmCP_RB0_WPTR);
}
static u32 gfx_v7_0_ring_get_rptr_compute(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs];
}
static u32 gfx_v7_0_ring_get_wptr_compute(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->wptr_offs];
}
static void gfx_v7_0_ring_set_wptr_compute(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
adev->wb.wb[ring->wptr_offs] = ring->wptr;
WDOORBELL32(ring->doorbell_index, ring->wptr);
}
static void gfx_v7_0_cp_compute_enable(struct amdgpu_device *adev, bool enable)
{
int i;
if (enable) {
WREG32(mmCP_MEC_CNTL, 0);
} else {
WREG32(mmCP_MEC_CNTL, (CP_MEC_CNTL__MEC_ME1_HALT_MASK | CP_MEC_CNTL__MEC_ME2_HALT_MASK));
for (i = 0; i < adev->gfx.num_compute_rings; i++)
adev->gfx.compute_ring[i].ready = false;
}
udelay(50);
}
static int gfx_v7_0_cp_compute_load_microcode(struct amdgpu_device *adev)
{
const struct gfx_firmware_header_v1_0 *mec_hdr;
const __le32 *fw_data;
unsigned i, fw_size;
if (!adev->gfx.mec_fw)
return -EINVAL;
mec_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
amdgpu_ucode_print_gfx_hdr(&mec_hdr->header);
adev->gfx.mec_fw_version = le32_to_cpu(mec_hdr->header.ucode_version);
adev->gfx.mec_feature_version = le32_to_cpu(
mec_hdr->ucode_feature_version);
gfx_v7_0_cp_compute_enable(adev, false);
fw_data = (const __le32 *)
(adev->gfx.mec_fw->data +
le32_to_cpu(mec_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(mec_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_MEC_ME1_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_MEC_ME1_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmCP_MEC_ME1_UCODE_ADDR, 0);
if (adev->asic_type == CHIP_KAVERI) {
const struct gfx_firmware_header_v1_0 *mec2_hdr;
if (!adev->gfx.mec2_fw)
return -EINVAL;
mec2_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec2_fw->data;
amdgpu_ucode_print_gfx_hdr(&mec2_hdr->header);
adev->gfx.mec2_fw_version = le32_to_cpu(mec2_hdr->header.ucode_version);
adev->gfx.mec2_feature_version = le32_to_cpu(
mec2_hdr->ucode_feature_version);
fw_data = (const __le32 *)
(adev->gfx.mec2_fw->data +
le32_to_cpu(mec2_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(mec2_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_MEC_ME2_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_MEC_ME2_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmCP_MEC_ME2_UCODE_ADDR, 0);
}
return 0;
}
static void gfx_v7_0_cp_compute_fini(struct amdgpu_device *adev)
{
int i, r;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
struct amdgpu_ring *ring = &adev->gfx.compute_ring[i];
if (ring->mqd_obj) {
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve MQD bo failed\n", r);
amdgpu_bo_unpin(ring->mqd_obj);
amdgpu_bo_unreserve(ring->mqd_obj);
amdgpu_bo_unref(&ring->mqd_obj);
ring->mqd_obj = NULL;
}
}
}
static void gfx_v7_0_mec_fini(struct amdgpu_device *adev)
{
int r;
if (adev->gfx.mec.hpd_eop_obj) {
r = amdgpu_bo_reserve(adev->gfx.mec.hpd_eop_obj, false);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve HPD EOP bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unreserve(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unref(&adev->gfx.mec.hpd_eop_obj);
adev->gfx.mec.hpd_eop_obj = NULL;
}
}
static int gfx_v7_0_mec_init(struct amdgpu_device *adev)
{
int r;
u32 *hpd;
adev->gfx.mec.num_mec = 1;
adev->gfx.mec.num_pipe = 1;
adev->gfx.mec.num_queue = adev->gfx.mec.num_mec * adev->gfx.mec.num_pipe * 8;
if (adev->gfx.mec.hpd_eop_obj == NULL) {
r = amdgpu_bo_create(adev,
adev->gfx.mec.num_mec *adev->gfx.mec.num_pipe * MEC_HPD_SIZE * 2,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL, NULL,
&adev->gfx.mec.hpd_eop_obj);
if (r) {
dev_warn(adev->dev, "(%d) create HDP EOP bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.mec.hpd_eop_obj, false);
if (unlikely(r != 0)) {
gfx_v7_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.mec.hpd_eop_obj, AMDGPU_GEM_DOMAIN_GTT,
&adev->gfx.mec.hpd_eop_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin HDP EOP bo failed\n", r);
gfx_v7_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.mec.hpd_eop_obj, (void **)&hpd);
if (r) {
dev_warn(adev->dev, "(%d) map HDP EOP bo failed\n", r);
gfx_v7_0_mec_fini(adev);
return r;
}
memset(hpd, 0, adev->gfx.mec.num_mec *adev->gfx.mec.num_pipe * MEC_HPD_SIZE * 2);
amdgpu_bo_kunmap(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unreserve(adev->gfx.mec.hpd_eop_obj);
return 0;
}
static int gfx_v7_0_cp_compute_resume(struct amdgpu_device *adev)
{
int r, i, j;
u32 tmp;
bool use_doorbell = true;
u64 hqd_gpu_addr;
u64 mqd_gpu_addr;
u64 eop_gpu_addr;
u64 wb_gpu_addr;
u32 *buf;
struct bonaire_mqd *mqd;
struct amdgpu_ring *ring;
tmp = RREG32(mmCP_CPF_DEBUG);
tmp |= (1 << 23);
WREG32(mmCP_CPF_DEBUG, tmp);
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < (adev->gfx.mec.num_pipe * adev->gfx.mec.num_mec); i++) {
int me = (i < 4) ? 1 : 2;
int pipe = (i < 4) ? i : (i - 4);
eop_gpu_addr = adev->gfx.mec.hpd_eop_gpu_addr + (i * MEC_HPD_SIZE * 2);
cik_srbm_select(adev, me, pipe, 0, 0);
WREG32(mmCP_HPD_EOP_BASE_ADDR, eop_gpu_addr >> 8);
WREG32(mmCP_HPD_EOP_BASE_ADDR_HI, upper_32_bits(eop_gpu_addr) >> 8);
WREG32(mmCP_HPD_EOP_VMID, 0);
tmp = RREG32(mmCP_HPD_EOP_CONTROL);
tmp &= ~CP_HPD_EOP_CONTROL__EOP_SIZE_MASK;
tmp |= order_base_2(MEC_HPD_SIZE / 8);
WREG32(mmCP_HPD_EOP_CONTROL, tmp);
}
cik_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
if (ring->mqd_obj == NULL) {
r = amdgpu_bo_create(adev,
sizeof(struct bonaire_mqd),
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL, NULL,
&ring->mqd_obj);
if (r) {
dev_warn(adev->dev, "(%d) create MQD bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0)) {
gfx_v7_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_pin(ring->mqd_obj, AMDGPU_GEM_DOMAIN_GTT,
&mqd_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin MQD bo failed\n", r);
gfx_v7_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_kmap(ring->mqd_obj, (void **)&buf);
if (r) {
dev_warn(adev->dev, "(%d) map MQD bo failed\n", r);
gfx_v7_0_cp_compute_fini(adev);
return r;
}
memset(buf, 0, sizeof(struct bonaire_mqd));
mqd = (struct bonaire_mqd *)buf;
mqd->header = 0xC0310800;
mqd->static_thread_mgmt01[0] = 0xffffffff;
mqd->static_thread_mgmt01[1] = 0xffffffff;
mqd->static_thread_mgmt23[0] = 0xffffffff;
mqd->static_thread_mgmt23[1] = 0xffffffff;
mutex_lock(&adev->srbm_mutex);
cik_srbm_select(adev, ring->me,
ring->pipe,
ring->queue, 0);
tmp = RREG32(mmCP_PQ_WPTR_POLL_CNTL);
tmp &= ~CP_PQ_WPTR_POLL_CNTL__EN_MASK;
WREG32(mmCP_PQ_WPTR_POLL_CNTL, tmp);
mqd->queue_state.cp_hqd_pq_doorbell_control =
RREG32(mmCP_HQD_PQ_DOORBELL_CONTROL);
if (use_doorbell)
mqd->queue_state.cp_hqd_pq_doorbell_control |= CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_EN_MASK;
else
mqd->queue_state.cp_hqd_pq_doorbell_control &= ~CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_EN_MASK;
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->queue_state.cp_hqd_pq_doorbell_control);
mqd->queue_state.cp_hqd_dequeue_request = 0;
mqd->queue_state.cp_hqd_pq_rptr = 0;
mqd->queue_state.cp_hqd_pq_wptr= 0;
if (RREG32(mmCP_HQD_ACTIVE) & 1) {
WREG32(mmCP_HQD_DEQUEUE_REQUEST, 1);
for (j = 0; j < adev->usec_timeout; j++) {
if (!(RREG32(mmCP_HQD_ACTIVE) & 1))
break;
udelay(1);
}
WREG32(mmCP_HQD_DEQUEUE_REQUEST, mqd->queue_state.cp_hqd_dequeue_request);
WREG32(mmCP_HQD_PQ_RPTR, mqd->queue_state.cp_hqd_pq_rptr);
WREG32(mmCP_HQD_PQ_WPTR, mqd->queue_state.cp_hqd_pq_wptr);
}
mqd->queue_state.cp_mqd_base_addr = mqd_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_mqd_base_addr_hi = upper_32_bits(mqd_gpu_addr);
WREG32(mmCP_MQD_BASE_ADDR, mqd->queue_state.cp_mqd_base_addr);
WREG32(mmCP_MQD_BASE_ADDR_HI, mqd->queue_state.cp_mqd_base_addr_hi);
mqd->queue_state.cp_mqd_control = RREG32(mmCP_MQD_CONTROL);
mqd->queue_state.cp_mqd_control &= ~CP_MQD_CONTROL__VMID_MASK;
WREG32(mmCP_MQD_CONTROL, mqd->queue_state.cp_mqd_control);
hqd_gpu_addr = ring->gpu_addr >> 8;
mqd->queue_state.cp_hqd_pq_base = hqd_gpu_addr;
mqd->queue_state.cp_hqd_pq_base_hi = upper_32_bits(hqd_gpu_addr);
WREG32(mmCP_HQD_PQ_BASE, mqd->queue_state.cp_hqd_pq_base);
WREG32(mmCP_HQD_PQ_BASE_HI, mqd->queue_state.cp_hqd_pq_base_hi);
mqd->queue_state.cp_hqd_pq_control = RREG32(mmCP_HQD_PQ_CONTROL);
mqd->queue_state.cp_hqd_pq_control &=
~(CP_HQD_PQ_CONTROL__QUEUE_SIZE_MASK |
CP_HQD_PQ_CONTROL__RPTR_BLOCK_SIZE_MASK);
mqd->queue_state.cp_hqd_pq_control |=
order_base_2(ring->ring_size / 8);
mqd->queue_state.cp_hqd_pq_control |=
(order_base_2(AMDGPU_GPU_PAGE_SIZE/8) << 8);
#ifdef __BIG_ENDIAN
mqd->queue_state.cp_hqd_pq_control |=
2 << CP_HQD_PQ_CONTROL__ENDIAN_SWAP__SHIFT;
#endif
mqd->queue_state.cp_hqd_pq_control &=
~(CP_HQD_PQ_CONTROL__UNORD_DISPATCH_MASK |
CP_HQD_PQ_CONTROL__ROQ_PQ_IB_FLIP_MASK |
CP_HQD_PQ_CONTROL__PQ_VOLATILE_MASK);
mqd->queue_state.cp_hqd_pq_control |=
CP_HQD_PQ_CONTROL__PRIV_STATE_MASK |
CP_HQD_PQ_CONTROL__KMD_QUEUE_MASK;
WREG32(mmCP_HQD_PQ_CONTROL, mqd->queue_state.cp_hqd_pq_control);
wb_gpu_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
mqd->queue_state.cp_hqd_pq_wptr_poll_addr = wb_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_hqd_pq_wptr_poll_addr_hi = upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(mmCP_HQD_PQ_WPTR_POLL_ADDR, mqd->queue_state.cp_hqd_pq_wptr_poll_addr);
WREG32(mmCP_HQD_PQ_WPTR_POLL_ADDR_HI,
mqd->queue_state.cp_hqd_pq_wptr_poll_addr_hi);
wb_gpu_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
mqd->queue_state.cp_hqd_pq_rptr_report_addr = wb_gpu_addr & 0xfffffffc;
mqd->queue_state.cp_hqd_pq_rptr_report_addr_hi =
upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(mmCP_HQD_PQ_RPTR_REPORT_ADDR,
mqd->queue_state.cp_hqd_pq_rptr_report_addr);
WREG32(mmCP_HQD_PQ_RPTR_REPORT_ADDR_HI,
mqd->queue_state.cp_hqd_pq_rptr_report_addr_hi);
if (use_doorbell) {
mqd->queue_state.cp_hqd_pq_doorbell_control =
RREG32(mmCP_HQD_PQ_DOORBELL_CONTROL);
mqd->queue_state.cp_hqd_pq_doorbell_control &=
~CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_OFFSET_MASK;
mqd->queue_state.cp_hqd_pq_doorbell_control |=
(ring->doorbell_index <<
CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_OFFSET__SHIFT);
mqd->queue_state.cp_hqd_pq_doorbell_control |=
CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_EN_MASK;
mqd->queue_state.cp_hqd_pq_doorbell_control &=
~(CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_SOURCE_MASK |
CP_HQD_PQ_DOORBELL_CONTROL__DOORBELL_HIT_MASK);
} else {
mqd->queue_state.cp_hqd_pq_doorbell_control = 0;
}
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->queue_state.cp_hqd_pq_doorbell_control);
ring->wptr = 0;
mqd->queue_state.cp_hqd_pq_wptr = ring->wptr;
WREG32(mmCP_HQD_PQ_WPTR, mqd->queue_state.cp_hqd_pq_wptr);
mqd->queue_state.cp_hqd_pq_rptr = RREG32(mmCP_HQD_PQ_RPTR);
mqd->queue_state.cp_hqd_vmid = 0;
WREG32(mmCP_HQD_VMID, mqd->queue_state.cp_hqd_vmid);
mqd->queue_state.cp_hqd_active = 1;
WREG32(mmCP_HQD_ACTIVE, mqd->queue_state.cp_hqd_active);
cik_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
amdgpu_bo_kunmap(ring->mqd_obj);
amdgpu_bo_unreserve(ring->mqd_obj);
ring->ready = true;
}
gfx_v7_0_cp_compute_enable(adev, true);
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
r = amdgpu_ring_test_ring(ring);
if (r)
ring->ready = false;
}
return 0;
}
static void gfx_v7_0_cp_enable(struct amdgpu_device *adev, bool enable)
{
gfx_v7_0_cp_gfx_enable(adev, enable);
gfx_v7_0_cp_compute_enable(adev, enable);
}
static int gfx_v7_0_cp_load_microcode(struct amdgpu_device *adev)
{
int r;
r = gfx_v7_0_cp_gfx_load_microcode(adev);
if (r)
return r;
r = gfx_v7_0_cp_compute_load_microcode(adev);
if (r)
return r;
return 0;
}
static void gfx_v7_0_enable_gui_idle_interrupt(struct amdgpu_device *adev,
bool enable)
{
u32 tmp = RREG32(mmCP_INT_CNTL_RING0);
if (enable)
tmp |= (CP_INT_CNTL_RING0__CNTX_BUSY_INT_ENABLE_MASK |
CP_INT_CNTL_RING0__CNTX_EMPTY_INT_ENABLE_MASK);
else
tmp &= ~(CP_INT_CNTL_RING0__CNTX_BUSY_INT_ENABLE_MASK |
CP_INT_CNTL_RING0__CNTX_EMPTY_INT_ENABLE_MASK);
WREG32(mmCP_INT_CNTL_RING0, tmp);
}
static int gfx_v7_0_cp_resume(struct amdgpu_device *adev)
{
int r;
gfx_v7_0_enable_gui_idle_interrupt(adev, false);
r = gfx_v7_0_cp_load_microcode(adev);
if (r)
return r;
r = gfx_v7_0_cp_gfx_resume(adev);
if (r)
return r;
r = gfx_v7_0_cp_compute_resume(adev);
if (r)
return r;
gfx_v7_0_enable_gui_idle_interrupt(adev, true);
return 0;
}
static void gfx_v7_0_ring_emit_pipeline_sync(struct amdgpu_ring *ring)
{
int usepfp = (ring->type == AMDGPU_RING_TYPE_GFX);
uint32_t seq = ring->fence_drv.sync_seq;
uint64_t addr = ring->fence_drv.gpu_addr;
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring, (WAIT_REG_MEM_MEM_SPACE(1) |
WAIT_REG_MEM_FUNCTION(3) |
WAIT_REG_MEM_ENGINE(usepfp)));
amdgpu_ring_write(ring, addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(addr) & 0xffffffff);
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring, 0xffffffff);
amdgpu_ring_write(ring, 4);
if (usepfp) {
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
}
}
static void gfx_v7_0_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr)
{
int usepfp = (ring->type == AMDGPU_RING_TYPE_GFX);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(usepfp) |
WRITE_DATA_DST_SEL(0)));
if (vm_id < 8) {
amdgpu_ring_write(ring,
(mmVM_CONTEXT0_PAGE_TABLE_BASE_ADDR + vm_id));
} else {
amdgpu_ring_write(ring,
(mmVM_CONTEXT8_PAGE_TABLE_BASE_ADDR + vm_id - 8));
}
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, pd_addr >> 12);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
amdgpu_ring_write(ring, mmVM_INVALIDATE_REQUEST);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 1 << vm_id);
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring, (WAIT_REG_MEM_OPERATION(0) |
WAIT_REG_MEM_FUNCTION(0) |
WAIT_REG_MEM_ENGINE(0)));
amdgpu_ring_write(ring, mmVM_INVALIDATE_REQUEST);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0x20);
if (usepfp) {
amdgpu_ring_write(ring, PACKET3(PACKET3_PFP_SYNC_ME, 0));
amdgpu_ring_write(ring, 0x0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
}
}
static void gfx_v7_0_rlc_fini(struct amdgpu_device *adev)
{
int r;
if (adev->gfx.rlc.save_restore_obj) {
r = amdgpu_bo_reserve(adev->gfx.rlc.save_restore_obj, false);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve RLC sr bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.rlc.save_restore_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.save_restore_obj);
amdgpu_bo_unref(&adev->gfx.rlc.save_restore_obj);
adev->gfx.rlc.save_restore_obj = NULL;
}
if (adev->gfx.rlc.clear_state_obj) {
r = amdgpu_bo_reserve(adev->gfx.rlc.clear_state_obj, false);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve RLC c bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.rlc.clear_state_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.clear_state_obj);
amdgpu_bo_unref(&adev->gfx.rlc.clear_state_obj);
adev->gfx.rlc.clear_state_obj = NULL;
}
if (adev->gfx.rlc.cp_table_obj) {
r = amdgpu_bo_reserve(adev->gfx.rlc.cp_table_obj, false);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve RLC cp table bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.rlc.cp_table_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.cp_table_obj);
amdgpu_bo_unref(&adev->gfx.rlc.cp_table_obj);
adev->gfx.rlc.cp_table_obj = NULL;
}
}
static int gfx_v7_0_rlc_init(struct amdgpu_device *adev)
{
const u32 *src_ptr;
volatile u32 *dst_ptr;
u32 dws, i;
const struct cs_section_def *cs_data;
int r;
if (adev->flags & AMD_IS_APU) {
if (adev->asic_type == CHIP_KAVERI) {
adev->gfx.rlc.reg_list = spectre_rlc_save_restore_register_list;
adev->gfx.rlc.reg_list_size =
(u32)ARRAY_SIZE(spectre_rlc_save_restore_register_list);
} else {
adev->gfx.rlc.reg_list = kalindi_rlc_save_restore_register_list;
adev->gfx.rlc.reg_list_size =
(u32)ARRAY_SIZE(kalindi_rlc_save_restore_register_list);
}
}
adev->gfx.rlc.cs_data = ci_cs_data;
adev->gfx.rlc.cp_table_size = ALIGN(CP_ME_TABLE_SIZE * 5 * 4, 2048);
adev->gfx.rlc.cp_table_size += 64 * 1024;
src_ptr = adev->gfx.rlc.reg_list;
dws = adev->gfx.rlc.reg_list_size;
dws += (5 * 16) + 48 + 48 + 64;
cs_data = adev->gfx.rlc.cs_data;
if (src_ptr) {
if (adev->gfx.rlc.save_restore_obj == NULL) {
r = amdgpu_bo_create(adev, dws * 4, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL,
&adev->gfx.rlc.save_restore_obj);
if (r) {
dev_warn(adev->dev, "(%d) create RLC sr bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.rlc.save_restore_obj, false);
if (unlikely(r != 0)) {
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.rlc.save_restore_obj, AMDGPU_GEM_DOMAIN_VRAM,
&adev->gfx.rlc.save_restore_gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->gfx.rlc.save_restore_obj);
dev_warn(adev->dev, "(%d) pin RLC sr bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.rlc.save_restore_obj, (void **)&adev->gfx.rlc.sr_ptr);
if (r) {
dev_warn(adev->dev, "(%d) map RLC sr bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
dst_ptr = adev->gfx.rlc.sr_ptr;
for (i = 0; i < adev->gfx.rlc.reg_list_size; i++)
dst_ptr[i] = cpu_to_le32(src_ptr[i]);
amdgpu_bo_kunmap(adev->gfx.rlc.save_restore_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.save_restore_obj);
}
if (cs_data) {
adev->gfx.rlc.clear_state_size = dws = gfx_v7_0_get_csb_size(adev);
if (adev->gfx.rlc.clear_state_obj == NULL) {
r = amdgpu_bo_create(adev, dws * 4, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL,
&adev->gfx.rlc.clear_state_obj);
if (r) {
dev_warn(adev->dev, "(%d) create RLC c bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.rlc.clear_state_obj, false);
if (unlikely(r != 0)) {
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.rlc.clear_state_obj, AMDGPU_GEM_DOMAIN_VRAM,
&adev->gfx.rlc.clear_state_gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->gfx.rlc.clear_state_obj);
dev_warn(adev->dev, "(%d) pin RLC c bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.rlc.clear_state_obj, (void **)&adev->gfx.rlc.cs_ptr);
if (r) {
dev_warn(adev->dev, "(%d) map RLC c bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
dst_ptr = adev->gfx.rlc.cs_ptr;
gfx_v7_0_get_csb_buffer(adev, dst_ptr);
amdgpu_bo_kunmap(adev->gfx.rlc.clear_state_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.clear_state_obj);
}
if (adev->gfx.rlc.cp_table_size) {
if (adev->gfx.rlc.cp_table_obj == NULL) {
r = amdgpu_bo_create(adev, adev->gfx.rlc.cp_table_size, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL,
&adev->gfx.rlc.cp_table_obj);
if (r) {
dev_warn(adev->dev, "(%d) create RLC cp table bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.rlc.cp_table_obj, false);
if (unlikely(r != 0)) {
dev_warn(adev->dev, "(%d) reserve RLC cp table bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.rlc.cp_table_obj, AMDGPU_GEM_DOMAIN_VRAM,
&adev->gfx.rlc.cp_table_gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->gfx.rlc.cp_table_obj);
dev_warn(adev->dev, "(%d) pin RLC cp_table bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.rlc.cp_table_obj, (void **)&adev->gfx.rlc.cp_table_ptr);
if (r) {
dev_warn(adev->dev, "(%d) map RLC cp table bo failed\n", r);
gfx_v7_0_rlc_fini(adev);
return r;
}
gfx_v7_0_init_cp_pg_table(adev);
amdgpu_bo_kunmap(adev->gfx.rlc.cp_table_obj);
amdgpu_bo_unreserve(adev->gfx.rlc.cp_table_obj);
}
return 0;
}
static void gfx_v7_0_enable_lbpw(struct amdgpu_device *adev, bool enable)
{
u32 tmp;
tmp = RREG32(mmRLC_LB_CNTL);
if (enable)
tmp |= RLC_LB_CNTL__LOAD_BALANCE_ENABLE_MASK;
else
tmp &= ~RLC_LB_CNTL__LOAD_BALANCE_ENABLE_MASK;
WREG32(mmRLC_LB_CNTL, tmp);
}
static void gfx_v7_0_wait_for_rlc_serdes(struct amdgpu_device *adev)
{
u32 i, j, k;
u32 mask;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
gfx_v7_0_select_se_sh(adev, i, j, 0xffffffff);
for (k = 0; k < adev->usec_timeout; k++) {
if (RREG32(mmRLC_SERDES_CU_MASTER_BUSY) == 0)
break;
udelay(1);
}
}
}
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
mask = RLC_SERDES_NONCU_MASTER_BUSY__SE_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__GC_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__TC0_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__TC1_MASTER_BUSY_MASK;
for (k = 0; k < adev->usec_timeout; k++) {
if ((RREG32(mmRLC_SERDES_NONCU_MASTER_BUSY) & mask) == 0)
break;
udelay(1);
}
}
static void gfx_v7_0_update_rlc(struct amdgpu_device *adev, u32 rlc)
{
u32 tmp;
tmp = RREG32(mmRLC_CNTL);
if (tmp != rlc)
WREG32(mmRLC_CNTL, rlc);
}
static u32 gfx_v7_0_halt_rlc(struct amdgpu_device *adev)
{
u32 data, orig;
orig = data = RREG32(mmRLC_CNTL);
if (data & RLC_CNTL__RLC_ENABLE_F32_MASK) {
u32 i;
data &= ~RLC_CNTL__RLC_ENABLE_F32_MASK;
WREG32(mmRLC_CNTL, data);
for (i = 0; i < adev->usec_timeout; i++) {
if ((RREG32(mmRLC_GPM_STAT) & RLC_GPM_STAT__RLC_BUSY_MASK) == 0)
break;
udelay(1);
}
gfx_v7_0_wait_for_rlc_serdes(adev);
}
return orig;
}
static void gfx_v7_0_enter_rlc_safe_mode(struct amdgpu_device *adev)
{
u32 tmp, i, mask;
tmp = 0x1 | (1 << 1);
WREG32(mmRLC_GPR_REG2, tmp);
mask = RLC_GPM_STAT__GFX_POWER_STATUS_MASK |
RLC_GPM_STAT__GFX_CLOCK_STATUS_MASK;
for (i = 0; i < adev->usec_timeout; i++) {
if ((RREG32(mmRLC_GPM_STAT) & mask) == mask)
break;
udelay(1);
}
for (i = 0; i < adev->usec_timeout; i++) {
if ((RREG32(mmRLC_GPR_REG2) & 0x1) == 0)
break;
udelay(1);
}
}
static void gfx_v7_0_exit_rlc_safe_mode(struct amdgpu_device *adev)
{
u32 tmp;
tmp = 0x1 | (0 << 1);
WREG32(mmRLC_GPR_REG2, tmp);
}
static void gfx_v7_0_rlc_stop(struct amdgpu_device *adev)
{
WREG32(mmRLC_CNTL, 0);
gfx_v7_0_enable_gui_idle_interrupt(adev, false);
gfx_v7_0_wait_for_rlc_serdes(adev);
}
static void gfx_v7_0_rlc_start(struct amdgpu_device *adev)
{
WREG32(mmRLC_CNTL, RLC_CNTL__RLC_ENABLE_F32_MASK);
gfx_v7_0_enable_gui_idle_interrupt(adev, true);
udelay(50);
}
static void gfx_v7_0_rlc_reset(struct amdgpu_device *adev)
{
u32 tmp = RREG32(mmGRBM_SOFT_RESET);
tmp |= GRBM_SOFT_RESET__SOFT_RESET_RLC_MASK;
WREG32(mmGRBM_SOFT_RESET, tmp);
udelay(50);
tmp &= ~GRBM_SOFT_RESET__SOFT_RESET_RLC_MASK;
WREG32(mmGRBM_SOFT_RESET, tmp);
udelay(50);
}
static int gfx_v7_0_rlc_resume(struct amdgpu_device *adev)
{
const struct rlc_firmware_header_v1_0 *hdr;
const __le32 *fw_data;
unsigned i, fw_size;
u32 tmp;
if (!adev->gfx.rlc_fw)
return -EINVAL;
hdr = (const struct rlc_firmware_header_v1_0 *)adev->gfx.rlc_fw->data;
amdgpu_ucode_print_rlc_hdr(&hdr->header);
adev->gfx.rlc_fw_version = le32_to_cpu(hdr->header.ucode_version);
adev->gfx.rlc_feature_version = le32_to_cpu(
hdr->ucode_feature_version);
gfx_v7_0_rlc_stop(adev);
tmp = RREG32(mmRLC_CGCG_CGLS_CTRL) & 0xfffffffc;
WREG32(mmRLC_CGCG_CGLS_CTRL, tmp);
gfx_v7_0_rlc_reset(adev);
gfx_v7_0_init_pg(adev);
WREG32(mmRLC_LB_CNTR_INIT, 0);
WREG32(mmRLC_LB_CNTR_MAX, 0x00008000);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
WREG32(mmRLC_LB_INIT_CU_MASK, 0xffffffff);
WREG32(mmRLC_LB_PARAMS, 0x00600408);
WREG32(mmRLC_LB_CNTL, 0x80000004);
mutex_unlock(&adev->grbm_idx_mutex);
WREG32(mmRLC_MC_CNTL, 0);
WREG32(mmRLC_UCODE_CNTL, 0);
fw_data = (const __le32 *)
(adev->gfx.rlc_fw->data + le32_to_cpu(hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(hdr->header.ucode_size_bytes) / 4;
WREG32(mmRLC_GPM_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmRLC_GPM_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmRLC_GPM_UCODE_ADDR, adev->gfx.rlc_fw_version);
gfx_v7_0_enable_lbpw(adev, false);
if (adev->asic_type == CHIP_BONAIRE)
WREG32(mmRLC_DRIVER_CPDMA_STATUS, 0);
gfx_v7_0_rlc_start(adev);
return 0;
}
static void gfx_v7_0_enable_cgcg(struct amdgpu_device *adev, bool enable)
{
u32 data, orig, tmp, tmp2;
orig = data = RREG32(mmRLC_CGCG_CGLS_CTRL);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_GFX_CGCG)) {
gfx_v7_0_enable_gui_idle_interrupt(adev, true);
tmp = gfx_v7_0_halt_rlc(adev);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
WREG32(mmRLC_SERDES_WR_CU_MASTER_MASK, 0xffffffff);
WREG32(mmRLC_SERDES_WR_NONCU_MASTER_MASK, 0xffffffff);
tmp2 = RLC_SERDES_WR_CTRL__BPM_ADDR_MASK |
RLC_SERDES_WR_CTRL__CGCG_OVERRIDE_0_MASK |
RLC_SERDES_WR_CTRL__CGLS_ENABLE_MASK;
WREG32(mmRLC_SERDES_WR_CTRL, tmp2);
mutex_unlock(&adev->grbm_idx_mutex);
gfx_v7_0_update_rlc(adev, tmp);
data |= RLC_CGCG_CGLS_CTRL__CGCG_EN_MASK | RLC_CGCG_CGLS_CTRL__CGLS_EN_MASK;
} else {
gfx_v7_0_enable_gui_idle_interrupt(adev, false);
RREG32(mmCB_CGTT_SCLK_CTRL);
RREG32(mmCB_CGTT_SCLK_CTRL);
RREG32(mmCB_CGTT_SCLK_CTRL);
RREG32(mmCB_CGTT_SCLK_CTRL);
data &= ~(RLC_CGCG_CGLS_CTRL__CGCG_EN_MASK | RLC_CGCG_CGLS_CTRL__CGLS_EN_MASK);
}
if (orig != data)
WREG32(mmRLC_CGCG_CGLS_CTRL, data);
}
static void gfx_v7_0_enable_mgcg(struct amdgpu_device *adev, bool enable)
{
u32 data, orig, tmp = 0;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_GFX_MGCG)) {
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_MGLS) {
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_CP_LS) {
orig = data = RREG32(mmCP_MEM_SLP_CNTL);
data |= CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK;
if (orig != data)
WREG32(mmCP_MEM_SLP_CNTL, data);
}
}
orig = data = RREG32(mmRLC_CGTT_MGCG_OVERRIDE);
data |= 0x00000001;
data &= 0xfffffffd;
if (orig != data)
WREG32(mmRLC_CGTT_MGCG_OVERRIDE, data);
tmp = gfx_v7_0_halt_rlc(adev);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
WREG32(mmRLC_SERDES_WR_CU_MASTER_MASK, 0xffffffff);
WREG32(mmRLC_SERDES_WR_NONCU_MASTER_MASK, 0xffffffff);
data = RLC_SERDES_WR_CTRL__BPM_ADDR_MASK |
RLC_SERDES_WR_CTRL__MGCG_OVERRIDE_0_MASK;
WREG32(mmRLC_SERDES_WR_CTRL, data);
mutex_unlock(&adev->grbm_idx_mutex);
gfx_v7_0_update_rlc(adev, tmp);
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_CGTS) {
orig = data = RREG32(mmCGTS_SM_CTRL_REG);
data &= ~CGTS_SM_CTRL_REG__SM_MODE_MASK;
data |= (0x2 << CGTS_SM_CTRL_REG__SM_MODE__SHIFT);
data |= CGTS_SM_CTRL_REG__SM_MODE_ENABLE_MASK;
data &= ~CGTS_SM_CTRL_REG__OVERRIDE_MASK;
if ((adev->cg_flags & AMD_CG_SUPPORT_GFX_MGLS) &&
(adev->cg_flags & AMD_CG_SUPPORT_GFX_CGTS_LS))
data &= ~CGTS_SM_CTRL_REG__LS_OVERRIDE_MASK;
data &= ~CGTS_SM_CTRL_REG__ON_MONITOR_ADD_MASK;
data |= CGTS_SM_CTRL_REG__ON_MONITOR_ADD_EN_MASK;
data |= (0x96 << CGTS_SM_CTRL_REG__ON_MONITOR_ADD__SHIFT);
if (orig != data)
WREG32(mmCGTS_SM_CTRL_REG, data);
}
} else {
orig = data = RREG32(mmRLC_CGTT_MGCG_OVERRIDE);
data |= 0x00000003;
if (orig != data)
WREG32(mmRLC_CGTT_MGCG_OVERRIDE, data);
data = RREG32(mmRLC_MEM_SLP_CNTL);
if (data & RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK) {
data &= ~RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK;
WREG32(mmRLC_MEM_SLP_CNTL, data);
}
data = RREG32(mmCP_MEM_SLP_CNTL);
if (data & CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK) {
data &= ~CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK;
WREG32(mmCP_MEM_SLP_CNTL, data);
}
orig = data = RREG32(mmCGTS_SM_CTRL_REG);
data |= CGTS_SM_CTRL_REG__OVERRIDE_MASK | CGTS_SM_CTRL_REG__LS_OVERRIDE_MASK;
if (orig != data)
WREG32(mmCGTS_SM_CTRL_REG, data);
tmp = gfx_v7_0_halt_rlc(adev);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
WREG32(mmRLC_SERDES_WR_CU_MASTER_MASK, 0xffffffff);
WREG32(mmRLC_SERDES_WR_NONCU_MASTER_MASK, 0xffffffff);
data = RLC_SERDES_WR_CTRL__BPM_ADDR_MASK | RLC_SERDES_WR_CTRL__MGCG_OVERRIDE_1_MASK;
WREG32(mmRLC_SERDES_WR_CTRL, data);
mutex_unlock(&adev->grbm_idx_mutex);
gfx_v7_0_update_rlc(adev, tmp);
}
}
static void gfx_v7_0_update_cg(struct amdgpu_device *adev,
bool enable)
{
gfx_v7_0_enable_gui_idle_interrupt(adev, false);
if (enable) {
gfx_v7_0_enable_mgcg(adev, true);
gfx_v7_0_enable_cgcg(adev, true);
} else {
gfx_v7_0_enable_cgcg(adev, false);
gfx_v7_0_enable_mgcg(adev, false);
}
gfx_v7_0_enable_gui_idle_interrupt(adev, true);
}
static void gfx_v7_0_enable_sclk_slowdown_on_pu(struct amdgpu_device *adev,
bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_RLC_SMU_HS))
data |= RLC_PG_CNTL__SMU_CLK_SLOWDOWN_ON_PU_ENABLE_MASK;
else
data &= ~RLC_PG_CNTL__SMU_CLK_SLOWDOWN_ON_PU_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_enable_sclk_slowdown_on_pd(struct amdgpu_device *adev,
bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_RLC_SMU_HS))
data |= RLC_PG_CNTL__SMU_CLK_SLOWDOWN_ON_PD_ENABLE_MASK;
else
data &= ~RLC_PG_CNTL__SMU_CLK_SLOWDOWN_ON_PD_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_enable_cp_pg(struct amdgpu_device *adev, bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_CP))
data &= ~0x8000;
else
data |= 0x8000;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_enable_gds_pg(struct amdgpu_device *adev, bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_GDS))
data &= ~0x2000;
else
data |= 0x2000;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_init_cp_pg_table(struct amdgpu_device *adev)
{
const __le32 *fw_data;
volatile u32 *dst_ptr;
int me, i, max_me = 4;
u32 bo_offset = 0;
u32 table_offset, table_size;
if (adev->asic_type == CHIP_KAVERI)
max_me = 5;
if (adev->gfx.rlc.cp_table_ptr == NULL)
return;
dst_ptr = adev->gfx.rlc.cp_table_ptr;
for (me = 0; me < max_me; me++) {
if (me == 0) {
const struct gfx_firmware_header_v1_0 *hdr =
(const struct gfx_firmware_header_v1_0 *)adev->gfx.ce_fw->data;
fw_data = (const __le32 *)
(adev->gfx.ce_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
table_offset = le32_to_cpu(hdr->jt_offset);
table_size = le32_to_cpu(hdr->jt_size);
} else if (me == 1) {
const struct gfx_firmware_header_v1_0 *hdr =
(const struct gfx_firmware_header_v1_0 *)adev->gfx.pfp_fw->data;
fw_data = (const __le32 *)
(adev->gfx.pfp_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
table_offset = le32_to_cpu(hdr->jt_offset);
table_size = le32_to_cpu(hdr->jt_size);
} else if (me == 2) {
const struct gfx_firmware_header_v1_0 *hdr =
(const struct gfx_firmware_header_v1_0 *)adev->gfx.me_fw->data;
fw_data = (const __le32 *)
(adev->gfx.me_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
table_offset = le32_to_cpu(hdr->jt_offset);
table_size = le32_to_cpu(hdr->jt_size);
} else if (me == 3) {
const struct gfx_firmware_header_v1_0 *hdr =
(const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
fw_data = (const __le32 *)
(adev->gfx.mec_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
table_offset = le32_to_cpu(hdr->jt_offset);
table_size = le32_to_cpu(hdr->jt_size);
} else {
const struct gfx_firmware_header_v1_0 *hdr =
(const struct gfx_firmware_header_v1_0 *)adev->gfx.mec2_fw->data;
fw_data = (const __le32 *)
(adev->gfx.mec2_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
table_offset = le32_to_cpu(hdr->jt_offset);
table_size = le32_to_cpu(hdr->jt_size);
}
for (i = 0; i < table_size; i ++) {
dst_ptr[bo_offset + i] =
cpu_to_le32(le32_to_cpu(fw_data[table_offset + i]));
}
bo_offset += table_size;
}
}
static void gfx_v7_0_enable_gfx_cgpg(struct amdgpu_device *adev,
bool enable)
{
u32 data, orig;
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_GFX_PG)) {
orig = data = RREG32(mmRLC_PG_CNTL);
data |= RLC_PG_CNTL__GFX_POWER_GATING_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
orig = data = RREG32(mmRLC_AUTO_PG_CTRL);
data |= RLC_AUTO_PG_CTRL__AUTO_PG_EN_MASK;
if (orig != data)
WREG32(mmRLC_AUTO_PG_CTRL, data);
} else {
orig = data = RREG32(mmRLC_PG_CNTL);
data &= ~RLC_PG_CNTL__GFX_POWER_GATING_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
orig = data = RREG32(mmRLC_AUTO_PG_CTRL);
data &= ~RLC_AUTO_PG_CTRL__AUTO_PG_EN_MASK;
if (orig != data)
WREG32(mmRLC_AUTO_PG_CTRL, data);
data = RREG32(mmDB_RENDER_CONTROL);
}
}
static void gfx_v7_0_set_user_cu_inactive_bitmap(struct amdgpu_device *adev,
u32 bitmap)
{
u32 data;
if (!bitmap)
return;
data = bitmap << GC_USER_SHADER_ARRAY_CONFIG__INACTIVE_CUS__SHIFT;
data &= GC_USER_SHADER_ARRAY_CONFIG__INACTIVE_CUS_MASK;
WREG32(mmGC_USER_SHADER_ARRAY_CONFIG, data);
}
static u32 gfx_v7_0_get_cu_active_bitmap(struct amdgpu_device *adev)
{
u32 data, mask;
data = RREG32(mmCC_GC_SHADER_ARRAY_CONFIG);
data |= RREG32(mmGC_USER_SHADER_ARRAY_CONFIG);
data &= CC_GC_SHADER_ARRAY_CONFIG__INACTIVE_CUS_MASK;
data >>= CC_GC_SHADER_ARRAY_CONFIG__INACTIVE_CUS__SHIFT;
mask = gfx_v7_0_create_bitmask(adev->gfx.config.max_cu_per_sh);
return (~data) & mask;
}
static void gfx_v7_0_init_ao_cu_mask(struct amdgpu_device *adev)
{
u32 tmp;
WREG32(mmRLC_PG_ALWAYS_ON_CU_MASK, adev->gfx.cu_info.ao_cu_mask);
tmp = RREG32(mmRLC_MAX_PG_CU);
tmp &= ~RLC_MAX_PG_CU__MAX_POWERED_UP_CU_MASK;
tmp |= (adev->gfx.cu_info.number << RLC_MAX_PG_CU__MAX_POWERED_UP_CU__SHIFT);
WREG32(mmRLC_MAX_PG_CU, tmp);
}
static void gfx_v7_0_enable_gfx_static_mgpg(struct amdgpu_device *adev,
bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_GFX_SMG))
data |= RLC_PG_CNTL__STATIC_PER_CU_PG_ENABLE_MASK;
else
data &= ~RLC_PG_CNTL__STATIC_PER_CU_PG_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_enable_gfx_dynamic_mgpg(struct amdgpu_device *adev,
bool enable)
{
u32 data, orig;
orig = data = RREG32(mmRLC_PG_CNTL);
if (enable && (adev->pg_flags & AMD_PG_SUPPORT_GFX_DMG))
data |= RLC_PG_CNTL__DYN_PER_CU_PG_ENABLE_MASK;
else
data &= ~RLC_PG_CNTL__DYN_PER_CU_PG_ENABLE_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
}
static void gfx_v7_0_init_gfx_cgpg(struct amdgpu_device *adev)
{
u32 data, orig;
u32 i;
if (adev->gfx.rlc.cs_data) {
WREG32(mmRLC_GPM_SCRATCH_ADDR, RLC_CLEAR_STATE_DESCRIPTOR_OFFSET);
WREG32(mmRLC_GPM_SCRATCH_DATA, upper_32_bits(adev->gfx.rlc.clear_state_gpu_addr));
WREG32(mmRLC_GPM_SCRATCH_DATA, lower_32_bits(adev->gfx.rlc.clear_state_gpu_addr));
WREG32(mmRLC_GPM_SCRATCH_DATA, adev->gfx.rlc.clear_state_size);
} else {
WREG32(mmRLC_GPM_SCRATCH_ADDR, RLC_CLEAR_STATE_DESCRIPTOR_OFFSET);
for (i = 0; i < 3; i++)
WREG32(mmRLC_GPM_SCRATCH_DATA, 0);
}
if (adev->gfx.rlc.reg_list) {
WREG32(mmRLC_GPM_SCRATCH_ADDR, RLC_SAVE_AND_RESTORE_STARTING_OFFSET);
for (i = 0; i < adev->gfx.rlc.reg_list_size; i++)
WREG32(mmRLC_GPM_SCRATCH_DATA, adev->gfx.rlc.reg_list[i]);
}
orig = data = RREG32(mmRLC_PG_CNTL);
data |= RLC_PG_CNTL__GFX_POWER_GATING_SRC_MASK;
if (orig != data)
WREG32(mmRLC_PG_CNTL, data);
WREG32(mmRLC_SAVE_AND_RESTORE_BASE, adev->gfx.rlc.save_restore_gpu_addr >> 8);
WREG32(mmRLC_JUMP_TABLE_RESTORE, adev->gfx.rlc.cp_table_gpu_addr >> 8);
data = RREG32(mmCP_RB_WPTR_POLL_CNTL);
data &= ~CP_RB_WPTR_POLL_CNTL__IDLE_POLL_COUNT_MASK;
data |= (0x60 << CP_RB_WPTR_POLL_CNTL__IDLE_POLL_COUNT__SHIFT);
WREG32(mmCP_RB_WPTR_POLL_CNTL, data);
data = 0x10101010;
WREG32(mmRLC_PG_DELAY, data);
data = RREG32(mmRLC_PG_DELAY_2);
data &= ~0xff;
data |= 0x3;
WREG32(mmRLC_PG_DELAY_2, data);
data = RREG32(mmRLC_AUTO_PG_CTRL);
data &= ~RLC_AUTO_PG_CTRL__GRBM_REG_SAVE_GFX_IDLE_THRESHOLD_MASK;
data |= (0x700 << RLC_AUTO_PG_CTRL__GRBM_REG_SAVE_GFX_IDLE_THRESHOLD__SHIFT);
WREG32(mmRLC_AUTO_PG_CTRL, data);
}
static void gfx_v7_0_update_gfx_pg(struct amdgpu_device *adev, bool enable)
{
gfx_v7_0_enable_gfx_cgpg(adev, enable);
gfx_v7_0_enable_gfx_static_mgpg(adev, enable);
gfx_v7_0_enable_gfx_dynamic_mgpg(adev, enable);
}
static u32 gfx_v7_0_get_csb_size(struct amdgpu_device *adev)
{
u32 count = 0;
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
if (adev->gfx.rlc.cs_data == NULL)
return 0;
count += 2;
count += 3;
for (sect = adev->gfx.rlc.cs_data; sect->section != NULL; ++sect) {
for (ext = sect->section; ext->extent != NULL; ++ext) {
if (sect->id == SECT_CONTEXT)
count += 2 + ext->reg_count;
else
return 0;
}
}
count += 4;
count += 2;
count += 2;
return count;
}
static void gfx_v7_0_get_csb_buffer(struct amdgpu_device *adev,
volatile u32 *buffer)
{
u32 count = 0, i;
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
if (adev->gfx.rlc.cs_data == NULL)
return;
if (buffer == NULL)
return;
buffer[count++] = cpu_to_le32(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
buffer[count++] = cpu_to_le32(PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
buffer[count++] = cpu_to_le32(PACKET3(PACKET3_CONTEXT_CONTROL, 1));
buffer[count++] = cpu_to_le32(0x80000000);
buffer[count++] = cpu_to_le32(0x80000000);
for (sect = adev->gfx.rlc.cs_data; sect->section != NULL; ++sect) {
for (ext = sect->section; ext->extent != NULL; ++ext) {
if (sect->id == SECT_CONTEXT) {
buffer[count++] =
cpu_to_le32(PACKET3(PACKET3_SET_CONTEXT_REG, ext->reg_count));
buffer[count++] = cpu_to_le32(ext->reg_index - PACKET3_SET_CONTEXT_REG_START);
for (i = 0; i < ext->reg_count; i++)
buffer[count++] = cpu_to_le32(ext->extent[i]);
} else {
return;
}
}
}
buffer[count++] = cpu_to_le32(PACKET3(PACKET3_SET_CONTEXT_REG, 2));
buffer[count++] = cpu_to_le32(mmPA_SC_RASTER_CONFIG - PACKET3_SET_CONTEXT_REG_START);
switch (adev->asic_type) {
case CHIP_BONAIRE:
buffer[count++] = cpu_to_le32(0x16000012);
buffer[count++] = cpu_to_le32(0x00000000);
break;
case CHIP_KAVERI:
buffer[count++] = cpu_to_le32(0x00000000);
buffer[count++] = cpu_to_le32(0x00000000);
break;
case CHIP_KABINI:
case CHIP_MULLINS:
buffer[count++] = cpu_to_le32(0x00000000);
buffer[count++] = cpu_to_le32(0x00000000);
break;
case CHIP_HAWAII:
buffer[count++] = cpu_to_le32(0x3a00161a);
buffer[count++] = cpu_to_le32(0x0000002e);
break;
default:
buffer[count++] = cpu_to_le32(0x00000000);
buffer[count++] = cpu_to_le32(0x00000000);
break;
}
buffer[count++] = cpu_to_le32(PACKET3(PACKET3_PREAMBLE_CNTL, 0));
buffer[count++] = cpu_to_le32(PACKET3_PREAMBLE_END_CLEAR_STATE);
buffer[count++] = cpu_to_le32(PACKET3(PACKET3_CLEAR_STATE, 0));
buffer[count++] = cpu_to_le32(0);
}
static void gfx_v7_0_init_pg(struct amdgpu_device *adev)
{
if (adev->pg_flags & (AMD_PG_SUPPORT_GFX_PG |
AMD_PG_SUPPORT_GFX_SMG |
AMD_PG_SUPPORT_GFX_DMG |
AMD_PG_SUPPORT_CP |
AMD_PG_SUPPORT_GDS |
AMD_PG_SUPPORT_RLC_SMU_HS)) {
gfx_v7_0_enable_sclk_slowdown_on_pu(adev, true);
gfx_v7_0_enable_sclk_slowdown_on_pd(adev, true);
if (adev->pg_flags & AMD_PG_SUPPORT_GFX_PG) {
gfx_v7_0_init_gfx_cgpg(adev);
gfx_v7_0_enable_cp_pg(adev, true);
gfx_v7_0_enable_gds_pg(adev, true);
}
gfx_v7_0_init_ao_cu_mask(adev);
gfx_v7_0_update_gfx_pg(adev, true);
}
}
static void gfx_v7_0_fini_pg(struct amdgpu_device *adev)
{
if (adev->pg_flags & (AMD_PG_SUPPORT_GFX_PG |
AMD_PG_SUPPORT_GFX_SMG |
AMD_PG_SUPPORT_GFX_DMG |
AMD_PG_SUPPORT_CP |
AMD_PG_SUPPORT_GDS |
AMD_PG_SUPPORT_RLC_SMU_HS)) {
gfx_v7_0_update_gfx_pg(adev, false);
if (adev->pg_flags & AMD_PG_SUPPORT_GFX_PG) {
gfx_v7_0_enable_cp_pg(adev, false);
gfx_v7_0_enable_gds_pg(adev, false);
}
}
}
static uint64_t gfx_v7_0_get_gpu_clock_counter(struct amdgpu_device *adev)
{
uint64_t clock;
mutex_lock(&adev->gfx.gpu_clock_mutex);
WREG32(mmRLC_CAPTURE_GPU_CLOCK_COUNT, 1);
clock = (uint64_t)RREG32(mmRLC_GPU_CLOCK_COUNT_LSB) |
((uint64_t)RREG32(mmRLC_GPU_CLOCK_COUNT_MSB) << 32ULL);
mutex_unlock(&adev->gfx.gpu_clock_mutex);
return clock;
}
static void gfx_v7_0_ring_emit_gds_switch(struct amdgpu_ring *ring,
uint32_t vmid,
uint32_t gds_base, uint32_t gds_size,
uint32_t gws_base, uint32_t gws_size,
uint32_t oa_base, uint32_t oa_size)
{
gds_base = gds_base >> AMDGPU_GDS_SHIFT;
gds_size = gds_size >> AMDGPU_GDS_SHIFT;
gws_base = gws_base >> AMDGPU_GWS_SHIFT;
gws_size = gws_size >> AMDGPU_GWS_SHIFT;
oa_base = oa_base >> AMDGPU_OA_SHIFT;
oa_size = oa_size >> AMDGPU_OA_SHIFT;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
amdgpu_ring_write(ring, amdgpu_gds_reg_offset[vmid].mem_base);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, gds_base);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
amdgpu_ring_write(ring, amdgpu_gds_reg_offset[vmid].mem_size);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, gds_size);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
amdgpu_ring_write(ring, amdgpu_gds_reg_offset[vmid].gws);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, gws_size << GDS_GWS_VMID0__SIZE__SHIFT | gws_base);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0)));
amdgpu_ring_write(ring, amdgpu_gds_reg_offset[vmid].oa);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, (1 << (oa_size + oa_base)) - (1 << oa_base));
}
static int gfx_v7_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->gfx.num_gfx_rings = GFX7_NUM_GFX_RINGS;
adev->gfx.num_compute_rings = GFX7_NUM_COMPUTE_RINGS;
adev->gfx.funcs = &gfx_v7_0_gfx_funcs;
adev->gfx.rlc.funcs = &gfx_v7_0_rlc_funcs;
gfx_v7_0_set_ring_funcs(adev);
gfx_v7_0_set_irq_funcs(adev);
gfx_v7_0_set_gds_init(adev);
return 0;
}
static int gfx_v7_0_late_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int r;
r = amdgpu_irq_get(adev, &adev->gfx.priv_reg_irq, 0);
if (r)
return r;
r = amdgpu_irq_get(adev, &adev->gfx.priv_inst_irq, 0);
if (r)
return r;
return 0;
}
static void gfx_v7_0_gpu_early_init(struct amdgpu_device *adev)
{
u32 gb_addr_config;
u32 mc_shared_chmap, mc_arb_ramcfg;
u32 dimm00_addr_map, dimm01_addr_map, dimm10_addr_map, dimm11_addr_map;
u32 tmp;
switch (adev->asic_type) {
case CHIP_BONAIRE:
adev->gfx.config.max_shader_engines = 2;
adev->gfx.config.max_tile_pipes = 4;
adev->gfx.config.max_cu_per_sh = 7;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 2;
adev->gfx.config.max_texture_channel_caches = 4;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = BONAIRE_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_HAWAII:
adev->gfx.config.max_shader_engines = 4;
adev->gfx.config.max_tile_pipes = 16;
adev->gfx.config.max_cu_per_sh = 11;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 4;
adev->gfx.config.max_texture_channel_caches = 16;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = HAWAII_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_KAVERI:
adev->gfx.config.max_shader_engines = 1;
adev->gfx.config.max_tile_pipes = 4;
if ((adev->pdev->device == 0x1304) ||
(adev->pdev->device == 0x1305) ||
(adev->pdev->device == 0x130C) ||
(adev->pdev->device == 0x130F) ||
(adev->pdev->device == 0x1310) ||
(adev->pdev->device == 0x1311) ||
(adev->pdev->device == 0x131C)) {
adev->gfx.config.max_cu_per_sh = 8;
adev->gfx.config.max_backends_per_se = 2;
} else if ((adev->pdev->device == 0x1309) ||
(adev->pdev->device == 0x130A) ||
(adev->pdev->device == 0x130D) ||
(adev->pdev->device == 0x1313) ||
(adev->pdev->device == 0x131D)) {
adev->gfx.config.max_cu_per_sh = 6;
adev->gfx.config.max_backends_per_se = 2;
} else if ((adev->pdev->device == 0x1306) ||
(adev->pdev->device == 0x1307) ||
(adev->pdev->device == 0x130B) ||
(adev->pdev->device == 0x130E) ||
(adev->pdev->device == 0x1315) ||
(adev->pdev->device == 0x131B)) {
adev->gfx.config.max_cu_per_sh = 4;
adev->gfx.config.max_backends_per_se = 1;
} else {
adev->gfx.config.max_cu_per_sh = 3;
adev->gfx.config.max_backends_per_se = 1;
}
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_texture_channel_caches = 4;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 16;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = BONAIRE_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_KABINI:
case CHIP_MULLINS:
default:
adev->gfx.config.max_shader_engines = 1;
adev->gfx.config.max_tile_pipes = 2;
adev->gfx.config.max_cu_per_sh = 2;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 1;
adev->gfx.config.max_texture_channel_caches = 2;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 16;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = BONAIRE_GB_ADDR_CONFIG_GOLDEN;
break;
}
mc_shared_chmap = RREG32(mmMC_SHARED_CHMAP);
adev->gfx.config.mc_arb_ramcfg = RREG32(mmMC_ARB_RAMCFG);
mc_arb_ramcfg = adev->gfx.config.mc_arb_ramcfg;
adev->gfx.config.num_tile_pipes = adev->gfx.config.max_tile_pipes;
adev->gfx.config.mem_max_burst_length_bytes = 256;
if (adev->flags & AMD_IS_APU) {
tmp = RREG32(mmMC_FUS_DRAM0_BANK_ADDR_MAPPING);
dimm00_addr_map = REG_GET_FIELD(tmp, MC_FUS_DRAM0_BANK_ADDR_MAPPING, DIMM0ADDRMAP);
dimm01_addr_map = REG_GET_FIELD(tmp, MC_FUS_DRAM0_BANK_ADDR_MAPPING, DIMM1ADDRMAP);
tmp = RREG32(mmMC_FUS_DRAM1_BANK_ADDR_MAPPING);
dimm10_addr_map = REG_GET_FIELD(tmp, MC_FUS_DRAM1_BANK_ADDR_MAPPING, DIMM0ADDRMAP);
dimm11_addr_map = REG_GET_FIELD(tmp, MC_FUS_DRAM1_BANK_ADDR_MAPPING, DIMM1ADDRMAP);
if ((dimm00_addr_map == 0) || (dimm00_addr_map == 3) || (dimm00_addr_map == 4) || (dimm00_addr_map > 12))
dimm00_addr_map = 0;
if ((dimm01_addr_map == 0) || (dimm01_addr_map == 3) || (dimm01_addr_map == 4) || (dimm01_addr_map > 12))
dimm01_addr_map = 0;
if ((dimm10_addr_map == 0) || (dimm10_addr_map == 3) || (dimm10_addr_map == 4) || (dimm10_addr_map > 12))
dimm10_addr_map = 0;
if ((dimm11_addr_map == 0) || (dimm11_addr_map == 3) || (dimm11_addr_map == 4) || (dimm11_addr_map > 12))
dimm11_addr_map = 0;
if ((dimm00_addr_map == 11) || (dimm01_addr_map == 11) || (dimm10_addr_map == 11) || (dimm11_addr_map == 11))
adev->gfx.config.mem_row_size_in_kb = 2;
else
adev->gfx.config.mem_row_size_in_kb = 1;
} else {
tmp = (mc_arb_ramcfg & MC_ARB_RAMCFG__NOOFCOLS_MASK) >> MC_ARB_RAMCFG__NOOFCOLS__SHIFT;
adev->gfx.config.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
if (adev->gfx.config.mem_row_size_in_kb > 4)
adev->gfx.config.mem_row_size_in_kb = 4;
}
adev->gfx.config.shader_engine_tile_size = 32;
adev->gfx.config.num_gpus = 1;
adev->gfx.config.multi_gpu_tile_size = 64;
gb_addr_config &= ~GB_ADDR_CONFIG__ROW_SIZE_MASK;
switch (adev->gfx.config.mem_row_size_in_kb) {
case 1:
default:
gb_addr_config |= (0 << GB_ADDR_CONFIG__ROW_SIZE__SHIFT);
break;
case 2:
gb_addr_config |= (1 << GB_ADDR_CONFIG__ROW_SIZE__SHIFT);
break;
case 4:
gb_addr_config |= (2 << GB_ADDR_CONFIG__ROW_SIZE__SHIFT);
break;
}
adev->gfx.config.gb_addr_config = gb_addr_config;
}
static int gfx_v7_0_sw_init(void *handle)
{
struct amdgpu_ring *ring;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int i, r;
r = amdgpu_irq_add_id(adev, 181, &adev->gfx.eop_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 184, &adev->gfx.priv_reg_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 185, &adev->gfx.priv_inst_irq);
if (r)
return r;
gfx_v7_0_scratch_init(adev);
r = gfx_v7_0_init_microcode(adev);
if (r) {
DRM_ERROR("Failed to load gfx firmware!\n");
return r;
}
r = gfx_v7_0_rlc_init(adev);
if (r) {
DRM_ERROR("Failed to init rlc BOs!\n");
return r;
}
r = gfx_v7_0_mec_init(adev);
if (r) {
DRM_ERROR("Failed to init MEC BOs!\n");
return r;
}
for (i = 0; i < adev->gfx.num_gfx_rings; i++) {
ring = &adev->gfx.gfx_ring[i];
ring->ring_obj = NULL;
sprintf(ring->name, "gfx");
r = amdgpu_ring_init(adev, ring, 1024,
PACKET3(PACKET3_NOP, 0x3FFF), 0xf,
&adev->gfx.eop_irq, AMDGPU_CP_IRQ_GFX_EOP,
AMDGPU_RING_TYPE_GFX);
if (r)
return r;
}
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
unsigned irq_type;
if ((i >= 32) || (i >= AMDGPU_MAX_COMPUTE_RINGS)) {
DRM_ERROR("Too many (%d) compute rings!\n", i);
break;
}
ring = &adev->gfx.compute_ring[i];
ring->ring_obj = NULL;
ring->use_doorbell = true;
ring->doorbell_index = AMDGPU_DOORBELL_MEC_RING0 + i;
ring->me = 1;
ring->pipe = i / 8;
ring->queue = i % 8;
sprintf(ring->name, "comp_%d.%d.%d", ring->me, ring->pipe, ring->queue);
irq_type = AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP + ring->pipe;
r = amdgpu_ring_init(adev, ring, 1024,
PACKET3(PACKET3_NOP, 0x3FFF), 0xf,
&adev->gfx.eop_irq, irq_type,
AMDGPU_RING_TYPE_COMPUTE);
if (r)
return r;
}
r = amdgpu_bo_create(adev, adev->gds.mem.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GDS, 0,
NULL, NULL, &adev->gds.gds_gfx_bo);
if (r)
return r;
r = amdgpu_bo_create(adev, adev->gds.gws.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GWS, 0,
NULL, NULL, &adev->gds.gws_gfx_bo);
if (r)
return r;
r = amdgpu_bo_create(adev, adev->gds.oa.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_OA, 0,
NULL, NULL, &adev->gds.oa_gfx_bo);
if (r)
return r;
adev->gfx.ce_ram_size = 0x8000;
gfx_v7_0_gpu_early_init(adev);
return r;
}
static int gfx_v7_0_sw_fini(void *handle)
{
int i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_bo_unref(&adev->gds.oa_gfx_bo);
amdgpu_bo_unref(&adev->gds.gws_gfx_bo);
amdgpu_bo_unref(&adev->gds.gds_gfx_bo);
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
amdgpu_ring_fini(&adev->gfx.gfx_ring[i]);
for (i = 0; i < adev->gfx.num_compute_rings; i++)
amdgpu_ring_fini(&adev->gfx.compute_ring[i]);
gfx_v7_0_cp_compute_fini(adev);
gfx_v7_0_rlc_fini(adev);
gfx_v7_0_mec_fini(adev);
gfx_v7_0_free_microcode(adev);
return 0;
}
static int gfx_v7_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gfx_v7_0_gpu_init(adev);
r = gfx_v7_0_rlc_resume(adev);
if (r)
return r;
r = gfx_v7_0_cp_resume(adev);
if (r)
return r;
return r;
}
static int gfx_v7_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_irq_put(adev, &adev->gfx.priv_reg_irq, 0);
amdgpu_irq_put(adev, &adev->gfx.priv_inst_irq, 0);
gfx_v7_0_cp_enable(adev, false);
gfx_v7_0_rlc_stop(adev);
gfx_v7_0_fini_pg(adev);
return 0;
}
static int gfx_v7_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v7_0_hw_fini(adev);
}
static int gfx_v7_0_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v7_0_hw_init(adev);
}
static bool gfx_v7_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (RREG32(mmGRBM_STATUS) & GRBM_STATUS__GUI_ACTIVE_MASK)
return false;
else
return true;
}
static int gfx_v7_0_wait_for_idle(void *handle)
{
unsigned i;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(mmGRBM_STATUS) & GRBM_STATUS__GUI_ACTIVE_MASK;
if (!tmp)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int gfx_v7_0_soft_reset(void *handle)
{
u32 grbm_soft_reset = 0, srbm_soft_reset = 0;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
tmp = RREG32(mmGRBM_STATUS);
if (tmp & (GRBM_STATUS__PA_BUSY_MASK | GRBM_STATUS__SC_BUSY_MASK |
GRBM_STATUS__BCI_BUSY_MASK | GRBM_STATUS__SX_BUSY_MASK |
GRBM_STATUS__TA_BUSY_MASK | GRBM_STATUS__VGT_BUSY_MASK |
GRBM_STATUS__DB_BUSY_MASK | GRBM_STATUS__CB_BUSY_MASK |
GRBM_STATUS__GDS_BUSY_MASK | GRBM_STATUS__SPI_BUSY_MASK |
GRBM_STATUS__IA_BUSY_MASK | GRBM_STATUS__IA_BUSY_NO_DMA_MASK))
grbm_soft_reset |= GRBM_SOFT_RESET__SOFT_RESET_CP_MASK |
GRBM_SOFT_RESET__SOFT_RESET_GFX_MASK;
if (tmp & (GRBM_STATUS__CP_BUSY_MASK | GRBM_STATUS__CP_COHERENCY_BUSY_MASK)) {
grbm_soft_reset |= GRBM_SOFT_RESET__SOFT_RESET_CP_MASK;
srbm_soft_reset |= SRBM_SOFT_RESET__SOFT_RESET_GRBM_MASK;
}
tmp = RREG32(mmGRBM_STATUS2);
if (tmp & GRBM_STATUS2__RLC_BUSY_MASK)
grbm_soft_reset |= GRBM_SOFT_RESET__SOFT_RESET_RLC_MASK;
tmp = RREG32(mmSRBM_STATUS);
if (tmp & SRBM_STATUS__GRBM_RQ_PENDING_MASK)
srbm_soft_reset |= SRBM_SOFT_RESET__SOFT_RESET_GRBM_MASK;
if (grbm_soft_reset || srbm_soft_reset) {
gfx_v7_0_fini_pg(adev);
gfx_v7_0_update_cg(adev, false);
gfx_v7_0_rlc_stop(adev);
WREG32(mmCP_ME_CNTL, CP_ME_CNTL__ME_HALT_MASK | CP_ME_CNTL__PFP_HALT_MASK | CP_ME_CNTL__CE_HALT_MASK);
WREG32(mmCP_MEC_CNTL, CP_MEC_CNTL__MEC_ME1_HALT_MASK | CP_MEC_CNTL__MEC_ME2_HALT_MASK);
if (grbm_soft_reset) {
tmp = RREG32(mmGRBM_SOFT_RESET);
tmp |= grbm_soft_reset;
dev_info(adev->dev, "GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmGRBM_SOFT_RESET, tmp);
tmp = RREG32(mmGRBM_SOFT_RESET);
udelay(50);
tmp &= ~grbm_soft_reset;
WREG32(mmGRBM_SOFT_RESET, tmp);
tmp = RREG32(mmGRBM_SOFT_RESET);
}
if (srbm_soft_reset) {
tmp = RREG32(mmSRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(adev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
}
udelay(50);
}
return 0;
}
static void gfx_v7_0_set_gfx_eop_interrupt_state(struct amdgpu_device *adev,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl &= ~CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl |= CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
}
static void gfx_v7_0_set_compute_eop_interrupt_state(struct amdgpu_device *adev,
int me, int pipe,
enum amdgpu_interrupt_state state)
{
u32 mec_int_cntl, mec_int_cntl_reg;
if (me == 1) {
switch (pipe) {
case 0:
mec_int_cntl_reg = mmCP_ME1_PIPE0_INT_CNTL;
break;
default:
DRM_DEBUG("invalid pipe %d\n", pipe);
return;
}
} else {
DRM_DEBUG("invalid me %d\n", me);
return;
}
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
mec_int_cntl = RREG32(mec_int_cntl_reg);
mec_int_cntl &= ~CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK;
WREG32(mec_int_cntl_reg, mec_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
mec_int_cntl = RREG32(mec_int_cntl_reg);
mec_int_cntl |= CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK;
WREG32(mec_int_cntl_reg, mec_int_cntl);
break;
default:
break;
}
}
static int gfx_v7_0_set_priv_reg_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl &= ~CP_INT_CNTL_RING0__PRIV_REG_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl |= CP_INT_CNTL_RING0__PRIV_REG_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
return 0;
}
static int gfx_v7_0_set_priv_inst_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl &= ~CP_INT_CNTL_RING0__PRIV_INSTR_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl |= CP_INT_CNTL_RING0__PRIV_INSTR_INT_ENABLE_MASK;
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
return 0;
}
static int gfx_v7_0_set_eop_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
switch (type) {
case AMDGPU_CP_IRQ_GFX_EOP:
gfx_v7_0_set_gfx_eop_interrupt_state(adev, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 1, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE1_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 1, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE2_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 1, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE3_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 1, 3, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE0_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 2, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE1_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 2, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE2_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 2, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE3_EOP:
gfx_v7_0_set_compute_eop_interrupt_state(adev, 2, 3, state);
break;
default:
break;
}
return 0;
}
static int gfx_v7_0_eop_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
u8 me_id, pipe_id;
struct amdgpu_ring *ring;
int i;
DRM_DEBUG("IH: CP EOP\n");
me_id = (entry->ring_id & 0x0c) >> 2;
pipe_id = (entry->ring_id & 0x03) >> 0;
switch (me_id) {
case 0:
amdgpu_fence_process(&adev->gfx.gfx_ring[0]);
break;
case 1:
case 2:
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
if ((ring->me == me_id) && (ring->pipe == pipe_id))
amdgpu_fence_process(ring);
}
break;
}
return 0;
}
static int gfx_v7_0_priv_reg_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal register access in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static int gfx_v7_0_priv_inst_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal instruction in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static int gfx_v7_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
bool gate = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (state == AMD_CG_STATE_GATE)
gate = true;
gfx_v7_0_enable_gui_idle_interrupt(adev, false);
if (gate) {
gfx_v7_0_enable_mgcg(adev, true);
gfx_v7_0_enable_cgcg(adev, true);
} else {
gfx_v7_0_enable_cgcg(adev, false);
gfx_v7_0_enable_mgcg(adev, false);
}
gfx_v7_0_enable_gui_idle_interrupt(adev, true);
return 0;
}
static int gfx_v7_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
bool gate = false;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (state == AMD_PG_STATE_GATE)
gate = true;
if (adev->pg_flags & (AMD_PG_SUPPORT_GFX_PG |
AMD_PG_SUPPORT_GFX_SMG |
AMD_PG_SUPPORT_GFX_DMG |
AMD_PG_SUPPORT_CP |
AMD_PG_SUPPORT_GDS |
AMD_PG_SUPPORT_RLC_SMU_HS)) {
gfx_v7_0_update_gfx_pg(adev, gate);
if (adev->pg_flags & AMD_PG_SUPPORT_GFX_PG) {
gfx_v7_0_enable_cp_pg(adev, gate);
gfx_v7_0_enable_gds_pg(adev, gate);
}
}
return 0;
}
static void gfx_v7_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].funcs = &gfx_v7_0_ring_funcs_gfx;
for (i = 0; i < adev->gfx.num_compute_rings; i++)
adev->gfx.compute_ring[i].funcs = &gfx_v7_0_ring_funcs_compute;
}
static void gfx_v7_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->gfx.eop_irq.num_types = AMDGPU_CP_IRQ_LAST;
adev->gfx.eop_irq.funcs = &gfx_v7_0_eop_irq_funcs;
adev->gfx.priv_reg_irq.num_types = 1;
adev->gfx.priv_reg_irq.funcs = &gfx_v7_0_priv_reg_irq_funcs;
adev->gfx.priv_inst_irq.num_types = 1;
adev->gfx.priv_inst_irq.funcs = &gfx_v7_0_priv_inst_irq_funcs;
}
static void gfx_v7_0_set_gds_init(struct amdgpu_device *adev)
{
adev->gds.mem.total_size = RREG32(mmGDS_VMID0_SIZE);
adev->gds.gws.total_size = 64;
adev->gds.oa.total_size = 16;
if (adev->gds.mem.total_size == 64 * 1024) {
adev->gds.mem.gfx_partition_size = 4096;
adev->gds.mem.cs_partition_size = 4096;
adev->gds.gws.gfx_partition_size = 4;
adev->gds.gws.cs_partition_size = 4;
adev->gds.oa.gfx_partition_size = 4;
adev->gds.oa.cs_partition_size = 1;
} else {
adev->gds.mem.gfx_partition_size = 1024;
adev->gds.mem.cs_partition_size = 1024;
adev->gds.gws.gfx_partition_size = 16;
adev->gds.gws.cs_partition_size = 16;
adev->gds.oa.gfx_partition_size = 4;
adev->gds.oa.cs_partition_size = 4;
}
}
static void gfx_v7_0_get_cu_info(struct amdgpu_device *adev)
{
int i, j, k, counter, active_cu_number = 0;
u32 mask, bitmap, ao_bitmap, ao_cu_mask = 0;
struct amdgpu_cu_info *cu_info = &adev->gfx.cu_info;
unsigned disable_masks[4 * 2];
memset(cu_info, 0, sizeof(*cu_info));
amdgpu_gfx_parse_disable_cu(disable_masks, 4, 2);
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
mask = 1;
ao_bitmap = 0;
counter = 0;
gfx_v7_0_select_se_sh(adev, i, j, 0xffffffff);
if (i < 4 && j < 2)
gfx_v7_0_set_user_cu_inactive_bitmap(
adev, disable_masks[i * 2 + j]);
bitmap = gfx_v7_0_get_cu_active_bitmap(adev);
cu_info->bitmap[i][j] = bitmap;
for (k = 0; k < 16; k ++) {
if (bitmap & mask) {
if (counter < 2)
ao_bitmap |= mask;
counter ++;
}
mask <<= 1;
}
active_cu_number += counter;
ao_cu_mask |= (ao_bitmap << (i * 16 + j * 8));
}
}
gfx_v7_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
cu_info->number = active_cu_number;
cu_info->ao_cu_mask = ao_cu_mask;
}
