static void gfx_v8_0_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_TOPAZ:
amdgpu_program_register_sequence(adev,
iceland_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(iceland_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
golden_settings_iceland_a11,
(const u32)ARRAY_SIZE(golden_settings_iceland_a11));
amdgpu_program_register_sequence(adev,
iceland_golden_common_all,
(const u32)ARRAY_SIZE(iceland_golden_common_all));
break;
case CHIP_TONGA:
amdgpu_program_register_sequence(adev,
tonga_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(tonga_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
golden_settings_tonga_a11,
(const u32)ARRAY_SIZE(golden_settings_tonga_a11));
amdgpu_program_register_sequence(adev,
tonga_golden_common_all,
(const u32)ARRAY_SIZE(tonga_golden_common_all));
break;
case CHIP_CARRIZO:
amdgpu_program_register_sequence(adev,
cz_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(cz_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
cz_golden_settings_a11,
(const u32)ARRAY_SIZE(cz_golden_settings_a11));
amdgpu_program_register_sequence(adev,
cz_golden_common_all,
(const u32)ARRAY_SIZE(cz_golden_common_all));
break;
default:
break;
}
}
static void gfx_v8_0_scratch_init(struct amdgpu_device *adev)
{
int i;
adev->gfx.scratch.num_reg = 7;
adev->gfx.scratch.reg_base = mmSCRATCH_REG0;
for (i = 0; i < adev->gfx.scratch.num_reg; i++) {
adev->gfx.scratch.free[i] = true;
adev->gfx.scratch.reg[i] = adev->gfx.scratch.reg_base + i;
}
}
static int gfx_v8_0_ring_test_ring(struct amdgpu_ring *ring)
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
r = amdgpu_ring_lock(ring, 3);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring %d (%d).\n",
ring->idx, r);
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_UCONFIG_REG, 1));
amdgpu_ring_write(ring, (scratch - PACKET3_SET_UCONFIG_REG_START));
amdgpu_ring_write(ring, 0xDEADBEEF);
amdgpu_ring_unlock_commit(ring);
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n",
ring->idx, i);
} else {
DRM_ERROR("amdgpu: ring %d test failed (scratch(0x%04X)=0x%08X)\n",
ring->idx, scratch, tmp);
r = -EINVAL;
}
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
static int gfx_v8_0_ring_test_ib(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib ib;
uint32_t scratch;
uint32_t tmp = 0;
unsigned i;
int r;
r = amdgpu_gfx_scratch_get(adev, &scratch);
if (r) {
DRM_ERROR("amdgpu: failed to get scratch reg (%d).\n", r);
return r;
}
WREG32(scratch, 0xCAFEDEAD);
r = amdgpu_ib_get(ring, NULL, 256, &ib);
if (r) {
DRM_ERROR("amdgpu: failed to get ib (%d).\n", r);
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
ib.ptr[0] = PACKET3(PACKET3_SET_UCONFIG_REG, 1);
ib.ptr[1] = ((scratch - PACKET3_SET_UCONFIG_REG_START));
ib.ptr[2] = 0xDEADBEEF;
ib.length_dw = 3;
r = amdgpu_ib_schedule(adev, 1, &ib, AMDGPU_FENCE_OWNER_UNDEFINED);
if (r) {
amdgpu_gfx_scratch_free(adev, scratch);
amdgpu_ib_free(adev, &ib);
DRM_ERROR("amdgpu: failed to schedule ib (%d).\n", r);
return r;
}
r = amdgpu_fence_wait(ib.fence, false);
if (r) {
DRM_ERROR("amdgpu: fence wait failed (%d).\n", r);
amdgpu_gfx_scratch_free(adev, scratch);
amdgpu_ib_free(adev, &ib);
return r;
}
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(scratch);
if (tmp == 0xDEADBEEF)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ib test on ring %d succeeded in %u usecs\n",
ib.fence->ring->idx, i);
} else {
DRM_ERROR("amdgpu: ib test failed (scratch(0x%04X)=0x%08X)\n",
scratch, tmp);
r = -EINVAL;
}
amdgpu_gfx_scratch_free(adev, scratch);
amdgpu_ib_free(adev, &ib);
return r;
}
static int gfx_v8_0_init_microcode(struct amdgpu_device *adev)
{
const char *chip_name;
char fw_name[30];
int err;
struct amdgpu_firmware_info *info = NULL;
const struct common_firmware_header *header = NULL;
const struct gfx_firmware_header_v1_0 *cp_hdr;
DRM_DEBUG("\n");
switch (adev->asic_type) {
case CHIP_TOPAZ:
chip_name = "topaz";
break;
case CHIP_TONGA:
chip_name = "tonga";
break;
case CHIP_CARRIZO:
chip_name = "carrizo";
break;
default:
BUG();
}
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_pfp.bin", chip_name);
err = request_firmware(&adev->gfx.pfp_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.pfp_fw);
if (err)
goto out;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.pfp_fw->data;
adev->gfx.pfp_fw_version = le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.pfp_feature_version = le32_to_cpu(cp_hdr->ucode_feature_version);
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_me.bin", chip_name);
err = request_firmware(&adev->gfx.me_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.me_fw);
if (err)
goto out;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.me_fw->data;
adev->gfx.me_fw_version = le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.me_feature_version = le32_to_cpu(cp_hdr->ucode_feature_version);
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_ce.bin", chip_name);
err = request_firmware(&adev->gfx.ce_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.ce_fw);
if (err)
goto out;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.ce_fw->data;
adev->gfx.ce_fw_version = le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.ce_feature_version = le32_to_cpu(cp_hdr->ucode_feature_version);
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_rlc.bin", chip_name);
err = request_firmware(&adev->gfx.rlc_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.rlc_fw);
cp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.rlc_fw->data;
adev->gfx.rlc_fw_version = le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.rlc_feature_version = le32_to_cpu(cp_hdr->ucode_feature_version);
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_mec.bin", chip_name);
err = request_firmware(&adev->gfx.mec_fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->gfx.mec_fw);
if (err)
goto out;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
adev->gfx.mec_fw_version = le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.mec_feature_version = le32_to_cpu(cp_hdr->ucode_feature_version);
snprintf(fw_name, sizeof(fw_name), "amdgpu/%s_mec2.bin", chip_name);
err = request_firmware(&adev->gfx.mec2_fw, fw_name, adev->dev);
if (!err) {
err = amdgpu_ucode_validate(adev->gfx.mec2_fw);
if (err)
goto out;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)
adev->gfx.mec2_fw->data;
adev->gfx.mec2_fw_version = le32_to_cpu(
cp_hdr->header.ucode_version);
adev->gfx.mec2_feature_version = le32_to_cpu(
cp_hdr->ucode_feature_version);
} else {
err = 0;
adev->gfx.mec2_fw = NULL;
}
if (adev->firmware.smu_load) {
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_PFP];
info->ucode_id = AMDGPU_UCODE_ID_CP_PFP;
info->fw = adev->gfx.pfp_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_ME];
info->ucode_id = AMDGPU_UCODE_ID_CP_ME;
info->fw = adev->gfx.me_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_CE];
info->ucode_id = AMDGPU_UCODE_ID_CP_CE;
info->fw = adev->gfx.ce_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_RLC_G];
info->ucode_id = AMDGPU_UCODE_ID_RLC_G;
info->fw = adev->gfx.rlc_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_MEC1];
info->ucode_id = AMDGPU_UCODE_ID_CP_MEC1;
info->fw = adev->gfx.mec_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
if (adev->gfx.mec2_fw) {
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_MEC2];
info->ucode_id = AMDGPU_UCODE_ID_CP_MEC2;
info->fw = adev->gfx.mec2_fw;
header = (const struct common_firmware_header *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes), PAGE_SIZE);
}
}
out:
if (err) {
dev_err(adev->dev,
"gfx8: Failed to load firmware \"%s\"\n",
fw_name);
release_firmware(adev->gfx.pfp_fw);
adev->gfx.pfp_fw = NULL;
release_firmware(adev->gfx.me_fw);
adev->gfx.me_fw = NULL;
release_firmware(adev->gfx.ce_fw);
adev->gfx.ce_fw = NULL;
release_firmware(adev->gfx.rlc_fw);
adev->gfx.rlc_fw = NULL;
release_firmware(adev->gfx.mec_fw);
adev->gfx.mec_fw = NULL;
release_firmware(adev->gfx.mec2_fw);
adev->gfx.mec2_fw = NULL;
}
return err;
}
static void gfx_v8_0_mec_fini(struct amdgpu_device *adev)
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
static int gfx_v8_0_mec_init(struct amdgpu_device *adev)
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
AMDGPU_GEM_DOMAIN_GTT, 0, NULL,
&adev->gfx.mec.hpd_eop_obj);
if (r) {
dev_warn(adev->dev, "(%d) create HDP EOP bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.mec.hpd_eop_obj, false);
if (unlikely(r != 0)) {
gfx_v8_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.mec.hpd_eop_obj, AMDGPU_GEM_DOMAIN_GTT,
&adev->gfx.mec.hpd_eop_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin HDP EOP bo failed\n", r);
gfx_v8_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.mec.hpd_eop_obj, (void **)&hpd);
if (r) {
dev_warn(adev->dev, "(%d) map HDP EOP bo failed\n", r);
gfx_v8_0_mec_fini(adev);
return r;
}
memset(hpd, 0, adev->gfx.mec.num_mec *adev->gfx.mec.num_pipe * MEC_HPD_SIZE * 2);
amdgpu_bo_kunmap(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unreserve(adev->gfx.mec.hpd_eop_obj);
return 0;
}
static int gfx_v8_0_sw_init(void *handle)
{
int i, r;
struct amdgpu_ring *ring;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, 181, &adev->gfx.eop_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 184, &adev->gfx.priv_reg_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, 185, &adev->gfx.priv_inst_irq);
if (r)
return r;
adev->gfx.gfx_current_status = AMDGPU_GFX_NORMAL_MODE;
gfx_v8_0_scratch_init(adev);
r = gfx_v8_0_init_microcode(adev);
if (r) {
DRM_ERROR("Failed to load gfx firmware!\n");
return r;
}
r = gfx_v8_0_mec_init(adev);
if (r) {
DRM_ERROR("Failed to init MEC BOs!\n");
return r;
}
r = amdgpu_wb_get(adev, &adev->gfx.ce_sync_offs);
if (r) {
DRM_ERROR("(%d) gfx.ce_sync_offs wb alloc failed\n", r);
return r;
}
for (i = 0; i < adev->gfx.num_gfx_rings; i++) {
ring = &adev->gfx.gfx_ring[i];
ring->ring_obj = NULL;
sprintf(ring->name, "gfx");
if (adev->asic_type != CHIP_TOPAZ) {
ring->use_doorbell = true;
ring->doorbell_index = AMDGPU_DOORBELL_GFX_RING0;
}
r = amdgpu_ring_init(adev, ring, 1024 * 1024,
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
sprintf(ring->name, "comp %d.%d.%d", ring->me, ring->pipe, ring->queue);
irq_type = AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP + ring->pipe;
r = amdgpu_ring_init(adev, ring, 1024 * 1024,
PACKET3(PACKET3_NOP, 0x3FFF), 0xf,
&adev->gfx.eop_irq, irq_type,
AMDGPU_RING_TYPE_COMPUTE);
if (r)
return r;
}
r = amdgpu_bo_create(adev, adev->gds.mem.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GDS, 0,
NULL, &adev->gds.gds_gfx_bo);
if (r)
return r;
r = amdgpu_bo_create(adev, adev->gds.gws.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GWS, 0,
NULL, &adev->gds.gws_gfx_bo);
if (r)
return r;
r = amdgpu_bo_create(adev, adev->gds.oa.gfx_partition_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_OA, 0,
NULL, &adev->gds.oa_gfx_bo);
if (r)
return r;
adev->gfx.ce_ram_size = 0x8000;
return 0;
}
static int gfx_v8_0_sw_fini(void *handle)
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
amdgpu_wb_free(adev, adev->gfx.ce_sync_offs);
gfx_v8_0_mec_fini(adev);
return 0;
}
static void gfx_v8_0_tiling_mode_table_init(struct amdgpu_device *adev)
{
const u32 num_tile_mode_states = 32;
const u32 num_secondary_tile_mode_states = 16;
u32 reg_offset, gb_tile_moden, split_equal_to_row_size;
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
switch (adev->asic_type) {
case CHIP_TOPAZ:
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P2));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 15:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 18:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 19:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 20:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 21:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 22:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 24:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 25:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 26:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 7:
case 12:
case 17:
case 23:
continue;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_TILE_MODE0 + reg_offset, gb_tile_moden);
}
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 1:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_4) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_2) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
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
case 7:
continue;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.macrotile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, gb_tile_moden);
}
case CHIP_TONGA:
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 7:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 12:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 15:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 17:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 18:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 19:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 20:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 21:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 22:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 23:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 24:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 25:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 26:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P8_32x32_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 30:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P4_16x16) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_TILE_MODE0 + reg_offset, gb_tile_moden);
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
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 5:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_16_BANK));
break;
case 6:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_1) |
NUM_BANKS(ADDR_SURF_16_BANK));
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
NUM_BANKS(ADDR_SURF_4_BANK));
break;
case 7:
continue;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.macrotile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, gb_tile_moden);
}
break;
case CHIP_CARRIZO:
default:
for (reg_offset = 0; reg_offset < num_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_64B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 1:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_128B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 2:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_256B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 3:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_512B) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 4:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 5:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 6:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
TILE_SPLIT(ADDR_SURF_TILE_SPLIT_2KB) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DEPTH_MICRO_TILING));
break;
case 8:
gb_tile_moden = (ARRAY_MODE(ARRAY_LINEAR_ALIGNED) |
PIPE_CONFIG(ADDR_SURF_P2));
break;
case 9:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 10:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 11:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_DISPLAY_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 13:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 14:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 15:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 16:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 18:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 19:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 20:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 21:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 22:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 24:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THIN_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 25:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 26:
gb_tile_moden = (ARRAY_MODE(ARRAY_3D_TILED_XTHICK) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_THICK_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_1));
break;
case 27:
gb_tile_moden = (ARRAY_MODE(ARRAY_1D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 28:
gb_tile_moden = (ARRAY_MODE(ARRAY_2D_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_2));
break;
case 29:
gb_tile_moden = (ARRAY_MODE(ARRAY_PRT_TILED_THIN1) |
PIPE_CONFIG(ADDR_SURF_P2) |
MICRO_TILE_MODE_NEW(ADDR_SURF_ROTATED_MICRO_TILING) |
SAMPLE_SPLIT(ADDR_SURF_SAMPLE_SPLIT_8));
break;
case 7:
case 12:
case 17:
case 23:
continue;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.tile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_TILE_MODE0 + reg_offset, gb_tile_moden);
}
for (reg_offset = 0; reg_offset < num_secondary_tile_mode_states; reg_offset++) {
switch (reg_offset) {
case 0:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_4) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 1:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_2) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_4) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 2:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 3:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
break;
case 4:
gb_tile_moden = (BANK_WIDTH(ADDR_SURF_BANK_WIDTH_1) |
BANK_HEIGHT(ADDR_SURF_BANK_HEIGHT_1) |
MACRO_TILE_ASPECT(ADDR_SURF_MACRO_ASPECT_2) |
NUM_BANKS(ADDR_SURF_8_BANK));
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
case 7:
continue;
default:
gb_tile_moden = 0;
break;
};
adev->gfx.config.macrotile_mode_array[reg_offset] = gb_tile_moden;
WREG32(mmGB_MACROTILE_MODE0 + reg_offset, gb_tile_moden);
}
}
}
static u32 gfx_v8_0_create_bitmask(u32 bit_width)
{
u32 i, mask = 0;
for (i = 0; i < bit_width; i++) {
mask <<= 1;
mask |= 1;
}
return mask;
}
void gfx_v8_0_select_se_sh(struct amdgpu_device *adev, u32 se_num, u32 sh_num)
{
u32 data = REG_SET_FIELD(0, GRBM_GFX_INDEX, INSTANCE_BROADCAST_WRITES, 1);
if ((se_num == 0xffffffff) && (sh_num == 0xffffffff)) {
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SH_BROADCAST_WRITES, 1);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SE_BROADCAST_WRITES, 1);
} else if (se_num == 0xffffffff) {
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SH_INDEX, sh_num);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SE_BROADCAST_WRITES, 1);
} else if (sh_num == 0xffffffff) {
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SH_BROADCAST_WRITES, 1);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SE_INDEX, se_num);
} else {
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SH_INDEX, sh_num);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX, SE_INDEX, se_num);
}
WREG32(mmGRBM_GFX_INDEX, data);
}
static u32 gfx_v8_0_get_rb_disabled(struct amdgpu_device *adev,
u32 max_rb_num_per_se,
u32 sh_per_se)
{
u32 data, mask;
data = RREG32(mmCC_RB_BACKEND_DISABLE);
data &= CC_RB_BACKEND_DISABLE__BACKEND_DISABLE_MASK;
data |= RREG32(mmGC_USER_RB_BACKEND_DISABLE);
data >>= GC_USER_RB_BACKEND_DISABLE__BACKEND_DISABLE__SHIFT;
mask = gfx_v8_0_create_bitmask(max_rb_num_per_se / sh_per_se);
return data & mask;
}
static void gfx_v8_0_setup_rb(struct amdgpu_device *adev,
u32 se_num, u32 sh_per_se,
u32 max_rb_num_per_se)
{
int i, j;
u32 data, mask;
u32 disabled_rbs = 0;
u32 enabled_rbs = 0;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < se_num; i++) {
for (j = 0; j < sh_per_se; j++) {
gfx_v8_0_select_se_sh(adev, i, j);
data = gfx_v8_0_get_rb_disabled(adev,
max_rb_num_per_se, sh_per_se);
disabled_rbs |= data << ((i * sh_per_se + j) *
RB_BITMAP_WIDTH_PER_SH);
}
}
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
mask = 1;
for (i = 0; i < max_rb_num_per_se * se_num; i++) {
if (!(disabled_rbs & mask))
enabled_rbs |= mask;
mask <<= 1;
}
adev->gfx.config.backend_enable_mask = enabled_rbs;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < se_num; i++) {
gfx_v8_0_select_se_sh(adev, i, 0xffffffff);
data = 0;
for (j = 0; j < sh_per_se; j++) {
switch (enabled_rbs & 3) {
case 0:
if (j == 0)
data |= (RASTER_CONFIG_RB_MAP_3 <<
PA_SC_RASTER_CONFIG__PKR_MAP__SHIFT);
else
data |= (RASTER_CONFIG_RB_MAP_0 <<
PA_SC_RASTER_CONFIG__PKR_MAP__SHIFT);
break;
case 1:
data |= (RASTER_CONFIG_RB_MAP_0 <<
(i * sh_per_se + j) * 2);
break;
case 2:
data |= (RASTER_CONFIG_RB_MAP_3 <<
(i * sh_per_se + j) * 2);
break;
case 3:
default:
data |= (RASTER_CONFIG_RB_MAP_2 <<
(i * sh_per_se + j) * 2);
break;
}
enabled_rbs >>= 2;
}
WREG32(mmPA_SC_RASTER_CONFIG, data);
}
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
}
static void gmc_v8_0_init_compute_vmid(struct amdgpu_device *adev)
{
int i;
uint32_t sh_mem_config;
uint32_t sh_mem_bases;
sh_mem_bases = DEFAULT_SH_MEM_BASES | (DEFAULT_SH_MEM_BASES << 16);
sh_mem_config = SH_MEM_ADDRESS_MODE_HSA64 <<
SH_MEM_CONFIG__ADDRESS_MODE__SHIFT |
SH_MEM_ALIGNMENT_MODE_UNALIGNED <<
SH_MEM_CONFIG__ALIGNMENT_MODE__SHIFT |
MTYPE_CC << SH_MEM_CONFIG__DEFAULT_MTYPE__SHIFT |
SH_MEM_CONFIG__PRIVATE_ATC_MASK;
mutex_lock(&adev->srbm_mutex);
for (i = FIRST_COMPUTE_VMID; i < LAST_COMPUTE_VMID; i++) {
vi_srbm_select(adev, 0, 0, 0, i);
WREG32(mmSH_MEM_CONFIG, sh_mem_config);
WREG32(mmSH_MEM_APE1_BASE, 1);
WREG32(mmSH_MEM_APE1_LIMIT, 0);
WREG32(mmSH_MEM_BASES, sh_mem_bases);
}
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
}
static void gfx_v8_0_gpu_init(struct amdgpu_device *adev)
{
u32 gb_addr_config;
u32 mc_shared_chmap, mc_arb_ramcfg;
u32 dimm00_addr_map, dimm01_addr_map, dimm10_addr_map, dimm11_addr_map;
u32 tmp;
int i;
switch (adev->asic_type) {
case CHIP_TOPAZ:
adev->gfx.config.max_shader_engines = 1;
adev->gfx.config.max_tile_pipes = 2;
adev->gfx.config.max_cu_per_sh = 6;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 2;
adev->gfx.config.max_texture_channel_caches = 2;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = TOPAZ_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_TONGA:
adev->gfx.config.max_shader_engines = 4;
adev->gfx.config.max_tile_pipes = 8;
adev->gfx.config.max_cu_per_sh = 8;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 2;
adev->gfx.config.max_texture_channel_caches = 8;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = TONGA_GB_ADDR_CONFIG_GOLDEN;
break;
case CHIP_CARRIZO:
adev->gfx.config.max_shader_engines = 1;
adev->gfx.config.max_tile_pipes = 2;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 2;
switch (adev->pdev->revision) {
case 0xc4:
case 0x84:
case 0xc8:
case 0xcc:
adev->gfx.config.max_cu_per_sh = 8;
break;
case 0xc5:
case 0x81:
case 0x85:
case 0xc9:
case 0xcd:
adev->gfx.config.max_cu_per_sh = 6;
break;
case 0xc6:
case 0xca:
case 0xce:
adev->gfx.config.max_cu_per_sh = 6;
break;
case 0xc7:
case 0x87:
case 0xcb:
default:
adev->gfx.config.max_cu_per_sh = 4;
break;
}
adev->gfx.config.max_texture_channel_caches = 2;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x130;
gb_addr_config = CARRIZO_GB_ADDR_CONFIG_GOLDEN;
break;
default:
adev->gfx.config.max_shader_engines = 2;
adev->gfx.config.max_tile_pipes = 4;
adev->gfx.config.max_cu_per_sh = 2;
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
gb_addr_config = TONGA_GB_ADDR_CONFIG_GOLDEN;
break;
}
tmp = RREG32(mmGRBM_CNTL);
tmp = REG_SET_FIELD(tmp, GRBM_CNTL, READ_TIMEOUT, 0xff);
WREG32(mmGRBM_CNTL, tmp);
mc_shared_chmap = RREG32(mmMC_SHARED_CHMAP);
adev->gfx.config.mc_arb_ramcfg = RREG32(mmMC_ARB_RAMCFG);
mc_arb_ramcfg = adev->gfx.config.mc_arb_ramcfg;
adev->gfx.config.num_tile_pipes = adev->gfx.config.max_tile_pipes;
adev->gfx.config.mem_max_burst_length_bytes = 256;
if (adev->flags & AMDGPU_IS_APU) {
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
tmp = REG_GET_FIELD(mc_arb_ramcfg, MC_ARB_RAMCFG, NOOFCOLS);
adev->gfx.config.mem_row_size_in_kb = (4 * (1 << (8 + tmp))) / 1024;
if (adev->gfx.config.mem_row_size_in_kb > 4)
adev->gfx.config.mem_row_size_in_kb = 4;
}
adev->gfx.config.shader_engine_tile_size = 32;
adev->gfx.config.num_gpus = 1;
adev->gfx.config.multi_gpu_tile_size = 64;
switch (adev->gfx.config.mem_row_size_in_kb) {
case 1:
default:
gb_addr_config = REG_SET_FIELD(gb_addr_config, GB_ADDR_CONFIG, ROW_SIZE, 0);
break;
case 2:
gb_addr_config = REG_SET_FIELD(gb_addr_config, GB_ADDR_CONFIG, ROW_SIZE, 1);
break;
case 4:
gb_addr_config = REG_SET_FIELD(gb_addr_config, GB_ADDR_CONFIG, ROW_SIZE, 2);
break;
}
adev->gfx.config.gb_addr_config = gb_addr_config;
WREG32(mmGB_ADDR_CONFIG, gb_addr_config);
WREG32(mmHDP_ADDR_CONFIG, gb_addr_config);
WREG32(mmDMIF_ADDR_CALC, gb_addr_config);
WREG32(mmSDMA0_TILING_CONFIG + SDMA0_REGISTER_OFFSET,
gb_addr_config & 0x70);
WREG32(mmSDMA0_TILING_CONFIG + SDMA1_REGISTER_OFFSET,
gb_addr_config & 0x70);
WREG32(mmUVD_UDEC_ADDR_CONFIG, gb_addr_config);
WREG32(mmUVD_UDEC_DB_ADDR_CONFIG, gb_addr_config);
WREG32(mmUVD_UDEC_DBW_ADDR_CONFIG, gb_addr_config);
gfx_v8_0_tiling_mode_table_init(adev);
gfx_v8_0_setup_rb(adev, adev->gfx.config.max_shader_engines,
adev->gfx.config.max_sh_per_se,
adev->gfx.config.max_backends_per_se);
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < 16; i++) {
vi_srbm_select(adev, 0, 0, 0, i);
if (i == 0) {
tmp = REG_SET_FIELD(0, SH_MEM_CONFIG, DEFAULT_MTYPE, MTYPE_UC);
tmp = REG_SET_FIELD(tmp, SH_MEM_CONFIG, APE1_MTYPE, MTYPE_UC);
tmp = REG_SET_FIELD(tmp, SH_MEM_CONFIG, ALIGNMENT_MODE,
SH_MEM_ALIGNMENT_MODE_UNALIGNED);
WREG32(mmSH_MEM_CONFIG, tmp);
} else {
tmp = REG_SET_FIELD(0, SH_MEM_CONFIG, DEFAULT_MTYPE, MTYPE_NC);
tmp = REG_SET_FIELD(tmp, SH_MEM_CONFIG, APE1_MTYPE, MTYPE_NC);
tmp = REG_SET_FIELD(tmp, SH_MEM_CONFIG, ALIGNMENT_MODE,
SH_MEM_ALIGNMENT_MODE_UNALIGNED);
WREG32(mmSH_MEM_CONFIG, tmp);
}
WREG32(mmSH_MEM_APE1_BASE, 1);
WREG32(mmSH_MEM_APE1_LIMIT, 0);
WREG32(mmSH_MEM_BASES, 0);
}
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
gmc_v8_0_init_compute_vmid(adev);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
WREG32(mmPA_SC_FIFO_SIZE,
(adev->gfx.config.sc_prim_fifo_size_frontend <<
PA_SC_FIFO_SIZE__SC_FRONTEND_PRIM_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_prim_fifo_size_backend <<
PA_SC_FIFO_SIZE__SC_BACKEND_PRIM_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_hiz_tile_fifo_size <<
PA_SC_FIFO_SIZE__SC_HIZ_TILE_FIFO_SIZE__SHIFT) |
(adev->gfx.config.sc_earlyz_tile_fifo_size <<
PA_SC_FIFO_SIZE__SC_EARLYZ_TILE_FIFO_SIZE__SHIFT));
mutex_unlock(&adev->grbm_idx_mutex);
}
static void gfx_v8_0_wait_for_rlc_serdes(struct amdgpu_device *adev)
{
u32 i, j, k;
u32 mask;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
gfx_v8_0_select_se_sh(adev, i, j);
for (k = 0; k < adev->usec_timeout; k++) {
if (RREG32(mmRLC_SERDES_CU_MASTER_BUSY) == 0)
break;
udelay(1);
}
}
}
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
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
static void gfx_v8_0_enable_gui_idle_interrupt(struct amdgpu_device *adev,
bool enable)
{
u32 tmp = RREG32(mmCP_INT_CNTL_RING0);
if (enable) {
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_BUSY_INT_ENABLE, 1);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_EMPTY_INT_ENABLE, 1);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CMP_BUSY_INT_ENABLE, 1);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, GFX_IDLE_INT_ENABLE, 1);
} else {
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_BUSY_INT_ENABLE, 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_EMPTY_INT_ENABLE, 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CMP_BUSY_INT_ENABLE, 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, GFX_IDLE_INT_ENABLE, 0);
}
WREG32(mmCP_INT_CNTL_RING0, tmp);
}
void gfx_v8_0_rlc_stop(struct amdgpu_device *adev)
{
u32 tmp = RREG32(mmRLC_CNTL);
tmp = REG_SET_FIELD(tmp, RLC_CNTL, RLC_ENABLE_F32, 0);
WREG32(mmRLC_CNTL, tmp);
gfx_v8_0_enable_gui_idle_interrupt(adev, false);
gfx_v8_0_wait_for_rlc_serdes(adev);
}
static void gfx_v8_0_rlc_reset(struct amdgpu_device *adev)
{
u32 tmp = RREG32(mmGRBM_SOFT_RESET);
tmp = REG_SET_FIELD(tmp, GRBM_SOFT_RESET, SOFT_RESET_RLC, 1);
WREG32(mmGRBM_SOFT_RESET, tmp);
udelay(50);
tmp = REG_SET_FIELD(tmp, GRBM_SOFT_RESET, SOFT_RESET_RLC, 0);
WREG32(mmGRBM_SOFT_RESET, tmp);
udelay(50);
}
static void gfx_v8_0_rlc_start(struct amdgpu_device *adev)
{
u32 tmp = RREG32(mmRLC_CNTL);
tmp = REG_SET_FIELD(tmp, RLC_CNTL, RLC_ENABLE_F32, 1);
WREG32(mmRLC_CNTL, tmp);
if (adev->asic_type != CHIP_CARRIZO)
gfx_v8_0_enable_gui_idle_interrupt(adev, true);
udelay(50);
}
static int gfx_v8_0_rlc_load_microcode(struct amdgpu_device *adev)
{
const struct rlc_firmware_header_v2_0 *hdr;
const __le32 *fw_data;
unsigned i, fw_size;
if (!adev->gfx.rlc_fw)
return -EINVAL;
hdr = (const struct rlc_firmware_header_v2_0 *)adev->gfx.rlc_fw->data;
amdgpu_ucode_print_rlc_hdr(&hdr->header);
fw_data = (const __le32 *)(adev->gfx.rlc_fw->data +
le32_to_cpu(hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(hdr->header.ucode_size_bytes) / 4;
WREG32(mmRLC_GPM_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmRLC_GPM_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32(mmRLC_GPM_UCODE_ADDR, adev->gfx.rlc_fw_version);
return 0;
}
static int gfx_v8_0_rlc_resume(struct amdgpu_device *adev)
{
int r;
gfx_v8_0_rlc_stop(adev);
WREG32(mmRLC_CGCG_CGLS_CTRL, 0);
WREG32(mmRLC_PG_CNTL, 0);
gfx_v8_0_rlc_reset(adev);
if (!adev->firmware.smu_load) {
r = gfx_v8_0_rlc_load_microcode(adev);
if (r)
return r;
} else {
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
AMDGPU_UCODE_ID_RLC_G);
if (r)
return -EINVAL;
}
gfx_v8_0_rlc_start(adev);
return 0;
}
static void gfx_v8_0_cp_gfx_enable(struct amdgpu_device *adev, bool enable)
{
int i;
u32 tmp = RREG32(mmCP_ME_CNTL);
if (enable) {
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, ME_HALT, 0);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, PFP_HALT, 0);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, CE_HALT, 0);
} else {
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, ME_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, PFP_HALT, 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, CE_HALT, 1);
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].ready = false;
}
WREG32(mmCP_ME_CNTL, tmp);
udelay(50);
}
static int gfx_v8_0_cp_gfx_load_microcode(struct amdgpu_device *adev)
{
const struct gfx_firmware_header_v1_0 *pfp_hdr;
const struct gfx_firmware_header_v1_0 *ce_hdr;
const struct gfx_firmware_header_v1_0 *me_hdr;
const __le32 *fw_data;
unsigned i, fw_size;
if (!adev->gfx.me_fw || !adev->gfx.pfp_fw || !adev->gfx.ce_fw)
return -EINVAL;
pfp_hdr = (const struct gfx_firmware_header_v1_0 *)
adev->gfx.pfp_fw->data;
ce_hdr = (const struct gfx_firmware_header_v1_0 *)
adev->gfx.ce_fw->data;
me_hdr = (const struct gfx_firmware_header_v1_0 *)
adev->gfx.me_fw->data;
amdgpu_ucode_print_gfx_hdr(&pfp_hdr->header);
amdgpu_ucode_print_gfx_hdr(&ce_hdr->header);
amdgpu_ucode_print_gfx_hdr(&me_hdr->header);
gfx_v8_0_cp_gfx_enable(adev, false);
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
static u32 gfx_v8_0_get_csb_size(struct amdgpu_device *adev)
{
u32 count = 0;
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
count += 2;
count += 3;
for (sect = vi_cs_data; sect->section != NULL; ++sect) {
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
static int gfx_v8_0_cp_gfx_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->gfx.gfx_ring[0];
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
int r, i;
WREG32(mmCP_MAX_CONTEXT, adev->gfx.config.max_hw_contexts - 1);
WREG32(mmCP_ENDIAN_SWAP, 0);
WREG32(mmCP_DEVICE_ID, 1);
gfx_v8_0_cp_gfx_enable(adev, true);
r = amdgpu_ring_lock(ring, gfx_v8_0_get_csb_size(adev) + 4);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring (%d).\n", r);
return r;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CONTEXT_CONTROL, 1));
amdgpu_ring_write(ring, 0x80000000);
amdgpu_ring_write(ring, 0x80000000);
for (sect = vi_cs_data; sect->section != NULL; ++sect) {
for (ext = sect->section; ext->extent != NULL; ++ext) {
if (sect->id == SECT_CONTEXT) {
amdgpu_ring_write(ring,
PACKET3(PACKET3_SET_CONTEXT_REG,
ext->reg_count));
amdgpu_ring_write(ring,
ext->reg_index - PACKET3_SET_CONTEXT_REG_START);
for (i = 0; i < ext->reg_count; i++)
amdgpu_ring_write(ring, ext->extent[i]);
}
}
}
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_CONTEXT_REG, 2));
amdgpu_ring_write(ring, mmPA_SC_RASTER_CONFIG - PACKET3_SET_CONTEXT_REG_START);
switch (adev->asic_type) {
case CHIP_TONGA:
amdgpu_ring_write(ring, 0x16000012);
amdgpu_ring_write(ring, 0x0000002A);
break;
case CHIP_TOPAZ:
case CHIP_CARRIZO:
amdgpu_ring_write(ring, 0x00000002);
amdgpu_ring_write(ring, 0x00000000);
break;
default:
BUG();
}
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_END_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CLEAR_STATE, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_BASE, 2));
amdgpu_ring_write(ring, PACKET3_BASE_INDEX(CE_PARTITION_BASE));
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_unlock_commit(ring);
return 0;
}
static int gfx_v8_0_cp_gfx_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
u32 tmp;
u32 rb_bufsz;
u64 rb_addr, rptr_addr;
int r;
WREG32(mmCP_RB_WPTR_DELAY, 0);
WREG32(mmCP_RB_VMID, 0);
ring = &adev->gfx.gfx_ring[0];
rb_bufsz = order_base_2(ring->ring_size / 8);
tmp = REG_SET_FIELD(0, CP_RB0_CNTL, RB_BUFSZ, rb_bufsz);
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, RB_BLKSZ, rb_bufsz - 2);
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, MTYPE, 3);
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, MIN_IB_AVAILSZ, 1);
#ifdef __BIG_ENDIAN
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, BUF_SWAP, 1);
#endif
WREG32(mmCP_RB0_CNTL, tmp);
WREG32(mmCP_RB0_CNTL, tmp | CP_RB0_CNTL__RB_RPTR_WR_ENA_MASK);
ring->wptr = 0;
WREG32(mmCP_RB0_WPTR, ring->wptr);
rptr_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
WREG32(mmCP_RB0_RPTR_ADDR, lower_32_bits(rptr_addr));
WREG32(mmCP_RB0_RPTR_ADDR_HI, upper_32_bits(rptr_addr) & 0xFF);
mdelay(1);
WREG32(mmCP_RB0_CNTL, tmp);
rb_addr = ring->gpu_addr >> 8;
WREG32(mmCP_RB0_BASE, rb_addr);
WREG32(mmCP_RB0_BASE_HI, upper_32_bits(rb_addr));
if (adev->asic_type != CHIP_TOPAZ) {
tmp = RREG32(mmCP_RB_DOORBELL_CONTROL);
if (ring->use_doorbell) {
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL,
DOORBELL_EN, 1);
} else {
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL,
DOORBELL_EN, 0);
}
WREG32(mmCP_RB_DOORBELL_CONTROL, tmp);
if (adev->asic_type == CHIP_TONGA) {
tmp = REG_SET_FIELD(0, CP_RB_DOORBELL_RANGE_LOWER,
DOORBELL_RANGE_LOWER,
AMDGPU_DOORBELL_GFX_RING0);
WREG32(mmCP_RB_DOORBELL_RANGE_LOWER, tmp);
WREG32(mmCP_RB_DOORBELL_RANGE_UPPER,
CP_RB_DOORBELL_RANGE_UPPER__DOORBELL_RANGE_UPPER_MASK);
}
}
gfx_v8_0_cp_gfx_start(adev);
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
return 0;
}
static void gfx_v8_0_cp_compute_enable(struct amdgpu_device *adev, bool enable)
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
static int gfx_v8_0_cp_compute_start(struct amdgpu_device *adev)
{
gfx_v8_0_cp_compute_enable(adev, true);
return 0;
}
static int gfx_v8_0_cp_compute_load_microcode(struct amdgpu_device *adev)
{
const struct gfx_firmware_header_v1_0 *mec_hdr;
const __le32 *fw_data;
unsigned i, fw_size;
if (!adev->gfx.mec_fw)
return -EINVAL;
gfx_v8_0_cp_compute_enable(adev, false);
mec_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
amdgpu_ucode_print_gfx_hdr(&mec_hdr->header);
fw_data = (const __le32 *)
(adev->gfx.mec_fw->data +
le32_to_cpu(mec_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(mec_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_MEC_ME1_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_MEC_ME1_UCODE_DATA, le32_to_cpup(fw_data+i));
WREG32(mmCP_MEC_ME1_UCODE_ADDR, adev->gfx.mec_fw_version);
if (adev->gfx.mec2_fw) {
const struct gfx_firmware_header_v1_0 *mec2_hdr;
mec2_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec2_fw->data;
amdgpu_ucode_print_gfx_hdr(&mec2_hdr->header);
fw_data = (const __le32 *)
(adev->gfx.mec2_fw->data +
le32_to_cpu(mec2_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(mec2_hdr->header.ucode_size_bytes) / 4;
WREG32(mmCP_MEC_ME2_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32(mmCP_MEC_ME2_UCODE_DATA, le32_to_cpup(fw_data+i));
WREG32(mmCP_MEC_ME2_UCODE_ADDR, adev->gfx.mec2_fw_version);
}
return 0;
}
static void gfx_v8_0_cp_compute_fini(struct amdgpu_device *adev)
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
static int gfx_v8_0_cp_compute_resume(struct amdgpu_device *adev)
{
int r, i, j;
u32 tmp;
bool use_doorbell = true;
u64 hqd_gpu_addr;
u64 mqd_gpu_addr;
u64 eop_gpu_addr;
u64 wb_gpu_addr;
u32 *buf;
struct vi_mqd *mqd;
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < (adev->gfx.mec.num_pipe * adev->gfx.mec.num_mec); i++) {
int me = (i < 4) ? 1 : 2;
int pipe = (i < 4) ? i : (i - 4);
eop_gpu_addr = adev->gfx.mec.hpd_eop_gpu_addr + (i * MEC_HPD_SIZE);
eop_gpu_addr >>= 8;
vi_srbm_select(adev, me, pipe, 0, 0);
WREG32(mmCP_HQD_EOP_BASE_ADDR, eop_gpu_addr);
WREG32(mmCP_HQD_EOP_BASE_ADDR_HI, upper_32_bits(eop_gpu_addr));
WREG32(mmCP_HQD_VMID, 0);
tmp = RREG32(mmCP_HQD_EOP_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_EOP_CONTROL, EOP_SIZE,
(order_base_2(MEC_HPD_SIZE / 4) - 1));
WREG32(mmCP_HQD_EOP_CONTROL, tmp);
}
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
struct amdgpu_ring *ring = &adev->gfx.compute_ring[i];
if (ring->mqd_obj == NULL) {
r = amdgpu_bo_create(adev,
sizeof(struct vi_mqd),
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL,
&ring->mqd_obj);
if (r) {
dev_warn(adev->dev, "(%d) create MQD bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0)) {
gfx_v8_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_pin(ring->mqd_obj, AMDGPU_GEM_DOMAIN_GTT,
&mqd_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin MQD bo failed\n", r);
gfx_v8_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_kmap(ring->mqd_obj, (void **)&buf);
if (r) {
dev_warn(adev->dev, "(%d) map MQD bo failed\n", r);
gfx_v8_0_cp_compute_fini(adev);
return r;
}
memset(buf, 0, sizeof(struct vi_mqd));
mqd = (struct vi_mqd *)buf;
mqd->header = 0xC0310800;
mqd->compute_pipelinestat_enable = 0x00000001;
mqd->compute_static_thread_mgmt_se0 = 0xffffffff;
mqd->compute_static_thread_mgmt_se1 = 0xffffffff;
mqd->compute_static_thread_mgmt_se2 = 0xffffffff;
mqd->compute_static_thread_mgmt_se3 = 0xffffffff;
mqd->compute_misc_reserved = 0x00000003;
mutex_lock(&adev->srbm_mutex);
vi_srbm_select(adev, ring->me,
ring->pipe,
ring->queue, 0);
tmp = RREG32(mmCP_PQ_WPTR_POLL_CNTL);
tmp = REG_SET_FIELD(tmp, CP_PQ_WPTR_POLL_CNTL, EN, 0);
WREG32(mmCP_PQ_WPTR_POLL_CNTL, tmp);
mqd->cp_hqd_eop_base_addr_lo =
RREG32(mmCP_HQD_EOP_BASE_ADDR);
mqd->cp_hqd_eop_base_addr_hi =
RREG32(mmCP_HQD_EOP_BASE_ADDR_HI);
tmp = RREG32(mmCP_HQD_PQ_DOORBELL_CONTROL);
if (use_doorbell) {
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 1);
} else {
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 0);
}
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL, tmp);
mqd->cp_hqd_pq_doorbell_control = tmp;
mqd->cp_hqd_dequeue_request = 0;
mqd->cp_hqd_pq_rptr = 0;
mqd->cp_hqd_pq_wptr= 0;
if (RREG32(mmCP_HQD_ACTIVE) & 1) {
WREG32(mmCP_HQD_DEQUEUE_REQUEST, 1);
for (j = 0; j < adev->usec_timeout; j++) {
if (!(RREG32(mmCP_HQD_ACTIVE) & 1))
break;
udelay(1);
}
WREG32(mmCP_HQD_DEQUEUE_REQUEST, mqd->cp_hqd_dequeue_request);
WREG32(mmCP_HQD_PQ_RPTR, mqd->cp_hqd_pq_rptr);
WREG32(mmCP_HQD_PQ_WPTR, mqd->cp_hqd_pq_wptr);
}
mqd->cp_mqd_base_addr_lo = mqd_gpu_addr & 0xfffffffc;
mqd->cp_mqd_base_addr_hi = upper_32_bits(mqd_gpu_addr);
WREG32(mmCP_MQD_BASE_ADDR, mqd->cp_mqd_base_addr_lo);
WREG32(mmCP_MQD_BASE_ADDR_HI, mqd->cp_mqd_base_addr_hi);
tmp = RREG32(mmCP_MQD_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_MQD_CONTROL, VMID, 0);
WREG32(mmCP_MQD_CONTROL, tmp);
mqd->cp_mqd_control = tmp;
hqd_gpu_addr = ring->gpu_addr >> 8;
mqd->cp_hqd_pq_base_lo = hqd_gpu_addr;
mqd->cp_hqd_pq_base_hi = upper_32_bits(hqd_gpu_addr);
WREG32(mmCP_HQD_PQ_BASE, mqd->cp_hqd_pq_base_lo);
WREG32(mmCP_HQD_PQ_BASE_HI, mqd->cp_hqd_pq_base_hi);
tmp = RREG32(mmCP_HQD_PQ_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, QUEUE_SIZE,
(order_base_2(ring->ring_size / 4) - 1));
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, RPTR_BLOCK_SIZE,
((order_base_2(AMDGPU_GPU_PAGE_SIZE / 4) - 1) << 8));
#ifdef __BIG_ENDIAN
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, ENDIAN_SWAP, 1);
#endif
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, UNORD_DISPATCH, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, ROQ_PQ_IB_FLIP, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, PRIV_STATE, 1);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_CONTROL, KMD_QUEUE, 1);
WREG32(mmCP_HQD_PQ_CONTROL, tmp);
mqd->cp_hqd_pq_control = tmp;
wb_gpu_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
mqd->cp_hqd_pq_rptr_report_addr_lo = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_rptr_report_addr_hi =
upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(mmCP_HQD_PQ_RPTR_REPORT_ADDR,
mqd->cp_hqd_pq_rptr_report_addr_lo);
WREG32(mmCP_HQD_PQ_RPTR_REPORT_ADDR_HI,
mqd->cp_hqd_pq_rptr_report_addr_hi);
wb_gpu_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
mqd->cp_hqd_pq_wptr_poll_addr = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_wptr_poll_addr_hi = upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32(mmCP_HQD_PQ_WPTR_POLL_ADDR, mqd->cp_hqd_pq_wptr_poll_addr);
WREG32(mmCP_HQD_PQ_WPTR_POLL_ADDR_HI,
mqd->cp_hqd_pq_wptr_poll_addr_hi);
if (use_doorbell) {
if (adev->asic_type == CHIP_CARRIZO) {
WREG32(mmCP_MEC_DOORBELL_RANGE_LOWER,
AMDGPU_DOORBELL_KIQ << 2);
WREG32(mmCP_MEC_DOORBELL_RANGE_UPPER,
AMDGPU_DOORBELL_MEC_RING7 << 2);
}
tmp = RREG32(mmCP_HQD_PQ_DOORBELL_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 1);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_SOURCE, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_HIT, 0);
mqd->cp_hqd_pq_doorbell_control = tmp;
} else {
mqd->cp_hqd_pq_doorbell_control = 0;
}
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->cp_hqd_pq_doorbell_control);
ring->wptr = 0;
mqd->cp_hqd_pq_wptr = ring->wptr;
WREG32(mmCP_HQD_PQ_WPTR, mqd->cp_hqd_pq_wptr);
mqd->cp_hqd_pq_rptr = RREG32(mmCP_HQD_PQ_RPTR);
mqd->cp_hqd_vmid = 0;
WREG32(mmCP_HQD_VMID, mqd->cp_hqd_vmid);
tmp = RREG32(mmCP_HQD_PERSISTENT_STATE);
tmp = REG_SET_FIELD(tmp, CP_HQD_PERSISTENT_STATE, PRELOAD_SIZE, 0x53);
WREG32(mmCP_HQD_PERSISTENT_STATE, tmp);
mqd->cp_hqd_persistent_state = tmp;
mqd->cp_hqd_active = 1;
WREG32(mmCP_HQD_ACTIVE, mqd->cp_hqd_active);
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
amdgpu_bo_kunmap(ring->mqd_obj);
amdgpu_bo_unreserve(ring->mqd_obj);
}
if (use_doorbell) {
tmp = RREG32(mmCP_PQ_STATUS);
tmp = REG_SET_FIELD(tmp, CP_PQ_STATUS, DOORBELL_ENABLE, 1);
WREG32(mmCP_PQ_STATUS, tmp);
}
r = gfx_v8_0_cp_compute_start(adev);
if (r)
return r;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
struct amdgpu_ring *ring = &adev->gfx.compute_ring[i];
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r)
ring->ready = false;
}
return 0;
}
static int gfx_v8_0_cp_resume(struct amdgpu_device *adev)
{
int r;
if (adev->asic_type != CHIP_CARRIZO)
gfx_v8_0_enable_gui_idle_interrupt(adev, false);
if (!adev->firmware.smu_load) {
r = gfx_v8_0_cp_gfx_load_microcode(adev);
if (r)
return r;
r = gfx_v8_0_cp_compute_load_microcode(adev);
if (r)
return r;
} else {
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
AMDGPU_UCODE_ID_CP_CE);
if (r)
return -EINVAL;
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
AMDGPU_UCODE_ID_CP_PFP);
if (r)
return -EINVAL;
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
AMDGPU_UCODE_ID_CP_ME);
if (r)
return -EINVAL;
r = adev->smu.smumgr_funcs->check_fw_load_finish(adev,
AMDGPU_UCODE_ID_CP_MEC1);
if (r)
return -EINVAL;
}
r = gfx_v8_0_cp_gfx_resume(adev);
if (r)
return r;
r = gfx_v8_0_cp_compute_resume(adev);
if (r)
return r;
gfx_v8_0_enable_gui_idle_interrupt(adev, true);
return 0;
}
static void gfx_v8_0_cp_enable(struct amdgpu_device *adev, bool enable)
{
gfx_v8_0_cp_gfx_enable(adev, enable);
gfx_v8_0_cp_compute_enable(adev, enable);
}
static int gfx_v8_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gfx_v8_0_init_golden_registers(adev);
gfx_v8_0_gpu_init(adev);
r = gfx_v8_0_rlc_resume(adev);
if (r)
return r;
r = gfx_v8_0_cp_resume(adev);
if (r)
return r;
return r;
}
static int gfx_v8_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gfx_v8_0_cp_enable(adev, false);
gfx_v8_0_rlc_stop(adev);
gfx_v8_0_cp_compute_fini(adev);
return 0;
}
static int gfx_v8_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v8_0_hw_fini(adev);
}
static int gfx_v8_0_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v8_0_hw_init(adev);
}
static bool gfx_v8_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (REG_GET_FIELD(RREG32(mmGRBM_STATUS), GRBM_STATUS, GUI_ACTIVE))
return false;
else
return true;
}
static int gfx_v8_0_wait_for_idle(void *handle)
{
unsigned i;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(mmGRBM_STATUS) & GRBM_STATUS__GUI_ACTIVE_MASK;
if (!REG_GET_FIELD(tmp, GRBM_STATUS, GUI_ACTIVE))
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static void gfx_v8_0_print_status(void *handle)
{
int i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
dev_info(adev->dev, "GFX 8.x registers\n");
dev_info(adev->dev, " GRBM_STATUS=0x%08X\n",
RREG32(mmGRBM_STATUS));
dev_info(adev->dev, " GRBM_STATUS2=0x%08X\n",
RREG32(mmGRBM_STATUS2));
dev_info(adev->dev, " GRBM_STATUS_SE0=0x%08X\n",
RREG32(mmGRBM_STATUS_SE0));
dev_info(adev->dev, " GRBM_STATUS_SE1=0x%08X\n",
RREG32(mmGRBM_STATUS_SE1));
dev_info(adev->dev, " GRBM_STATUS_SE2=0x%08X\n",
RREG32(mmGRBM_STATUS_SE2));
dev_info(adev->dev, " GRBM_STATUS_SE3=0x%08X\n",
RREG32(mmGRBM_STATUS_SE3));
dev_info(adev->dev, " CP_STAT = 0x%08x\n", RREG32(mmCP_STAT));
dev_info(adev->dev, " CP_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT1));
dev_info(adev->dev, " CP_STALLED_STAT2 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT2));
dev_info(adev->dev, " CP_STALLED_STAT3 = 0x%08x\n",
RREG32(mmCP_STALLED_STAT3));
dev_info(adev->dev, " CP_CPF_BUSY_STAT = 0x%08x\n",
RREG32(mmCP_CPF_BUSY_STAT));
dev_info(adev->dev, " CP_CPF_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_CPF_STALLED_STAT1));
dev_info(adev->dev, " CP_CPF_STATUS = 0x%08x\n", RREG32(mmCP_CPF_STATUS));
dev_info(adev->dev, " CP_CPC_BUSY_STAT = 0x%08x\n", RREG32(mmCP_CPC_BUSY_STAT));
dev_info(adev->dev, " CP_CPC_STALLED_STAT1 = 0x%08x\n",
RREG32(mmCP_CPC_STALLED_STAT1));
dev_info(adev->dev, " CP_CPC_STATUS = 0x%08x\n", RREG32(mmCP_CPC_STATUS));
for (i = 0; i < 32; i++) {
dev_info(adev->dev, " GB_TILE_MODE%d=0x%08X\n",
i, RREG32(mmGB_TILE_MODE0 + (i * 4)));
}
for (i = 0; i < 16; i++) {
dev_info(adev->dev, " GB_MACROTILE_MODE%d=0x%08X\n",
i, RREG32(mmGB_MACROTILE_MODE0 + (i * 4)));
}
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
dev_info(adev->dev, " se: %d\n", i);
gfx_v8_0_select_se_sh(adev, i, 0xffffffff);
dev_info(adev->dev, " PA_SC_RASTER_CONFIG=0x%08X\n",
RREG32(mmPA_SC_RASTER_CONFIG));
dev_info(adev->dev, " PA_SC_RASTER_CONFIG_1=0x%08X\n",
RREG32(mmPA_SC_RASTER_CONFIG_1));
}
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
dev_info(adev->dev, " GB_ADDR_CONFIG=0x%08X\n",
RREG32(mmGB_ADDR_CONFIG));
dev_info(adev->dev, " HDP_ADDR_CONFIG=0x%08X\n",
RREG32(mmHDP_ADDR_CONFIG));
dev_info(adev->dev, " DMIF_ADDR_CALC=0x%08X\n",
RREG32(mmDMIF_ADDR_CALC));
dev_info(adev->dev, " SDMA0_TILING_CONFIG=0x%08X\n",
RREG32(mmSDMA0_TILING_CONFIG + SDMA0_REGISTER_OFFSET));
dev_info(adev->dev, " SDMA1_TILING_CONFIG=0x%08X\n",
RREG32(mmSDMA0_TILING_CONFIG + SDMA1_REGISTER_OFFSET));
dev_info(adev->dev, " UVD_UDEC_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_ADDR_CONFIG));
dev_info(adev->dev, " UVD_UDEC_DB_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_DB_ADDR_CONFIG));
dev_info(adev->dev, " UVD_UDEC_DBW_ADDR_CONFIG=0x%08X\n",
RREG32(mmUVD_UDEC_DBW_ADDR_CONFIG));
dev_info(adev->dev, " CP_MEQ_THRESHOLDS=0x%08X\n",
RREG32(mmCP_MEQ_THRESHOLDS));
dev_info(adev->dev, " SX_DEBUG_1=0x%08X\n",
RREG32(mmSX_DEBUG_1));
dev_info(adev->dev, " TA_CNTL_AUX=0x%08X\n",
RREG32(mmTA_CNTL_AUX));
dev_info(adev->dev, " SPI_CONFIG_CNTL=0x%08X\n",
RREG32(mmSPI_CONFIG_CNTL));
dev_info(adev->dev, " SQ_CONFIG=0x%08X\n",
RREG32(mmSQ_CONFIG));
dev_info(adev->dev, " DB_DEBUG=0x%08X\n",
RREG32(mmDB_DEBUG));
dev_info(adev->dev, " DB_DEBUG2=0x%08X\n",
RREG32(mmDB_DEBUG2));
dev_info(adev->dev, " DB_DEBUG3=0x%08X\n",
RREG32(mmDB_DEBUG3));
dev_info(adev->dev, " CB_HW_CONTROL=0x%08X\n",
RREG32(mmCB_HW_CONTROL));
dev_info(adev->dev, " SPI_CONFIG_CNTL_1=0x%08X\n",
RREG32(mmSPI_CONFIG_CNTL_1));
dev_info(adev->dev, " PA_SC_FIFO_SIZE=0x%08X\n",
RREG32(mmPA_SC_FIFO_SIZE));
dev_info(adev->dev, " VGT_NUM_INSTANCES=0x%08X\n",
RREG32(mmVGT_NUM_INSTANCES));
dev_info(adev->dev, " CP_PERFMON_CNTL=0x%08X\n",
RREG32(mmCP_PERFMON_CNTL));
dev_info(adev->dev, " PA_SC_FORCE_EOV_MAX_CNTS=0x%08X\n",
RREG32(mmPA_SC_FORCE_EOV_MAX_CNTS));
dev_info(adev->dev, " VGT_CACHE_INVALIDATION=0x%08X\n",
RREG32(mmVGT_CACHE_INVALIDATION));
dev_info(adev->dev, " VGT_GS_VERTEX_REUSE=0x%08X\n",
RREG32(mmVGT_GS_VERTEX_REUSE));
dev_info(adev->dev, " PA_SC_LINE_STIPPLE_STATE=0x%08X\n",
RREG32(mmPA_SC_LINE_STIPPLE_STATE));
dev_info(adev->dev, " PA_CL_ENHANCE=0x%08X\n",
RREG32(mmPA_CL_ENHANCE));
dev_info(adev->dev, " PA_SC_ENHANCE=0x%08X\n",
RREG32(mmPA_SC_ENHANCE));
dev_info(adev->dev, " CP_ME_CNTL=0x%08X\n",
RREG32(mmCP_ME_CNTL));
dev_info(adev->dev, " CP_MAX_CONTEXT=0x%08X\n",
RREG32(mmCP_MAX_CONTEXT));
dev_info(adev->dev, " CP_ENDIAN_SWAP=0x%08X\n",
RREG32(mmCP_ENDIAN_SWAP));
dev_info(adev->dev, " CP_DEVICE_ID=0x%08X\n",
RREG32(mmCP_DEVICE_ID));
dev_info(adev->dev, " CP_SEM_WAIT_TIMER=0x%08X\n",
RREG32(mmCP_SEM_WAIT_TIMER));
dev_info(adev->dev, " CP_RB_WPTR_DELAY=0x%08X\n",
RREG32(mmCP_RB_WPTR_DELAY));
dev_info(adev->dev, " CP_RB_VMID=0x%08X\n",
RREG32(mmCP_RB_VMID));
dev_info(adev->dev, " CP_RB0_CNTL=0x%08X\n",
RREG32(mmCP_RB0_CNTL));
dev_info(adev->dev, " CP_RB0_WPTR=0x%08X\n",
RREG32(mmCP_RB0_WPTR));
dev_info(adev->dev, " CP_RB0_RPTR_ADDR=0x%08X\n",
RREG32(mmCP_RB0_RPTR_ADDR));
dev_info(adev->dev, " CP_RB0_RPTR_ADDR_HI=0x%08X\n",
RREG32(mmCP_RB0_RPTR_ADDR_HI));
dev_info(adev->dev, " CP_RB0_CNTL=0x%08X\n",
RREG32(mmCP_RB0_CNTL));
dev_info(adev->dev, " CP_RB0_BASE=0x%08X\n",
RREG32(mmCP_RB0_BASE));
dev_info(adev->dev, " CP_RB0_BASE_HI=0x%08X\n",
RREG32(mmCP_RB0_BASE_HI));
dev_info(adev->dev, " CP_MEC_CNTL=0x%08X\n",
RREG32(mmCP_MEC_CNTL));
dev_info(adev->dev, " CP_CPF_DEBUG=0x%08X\n",
RREG32(mmCP_CPF_DEBUG));
dev_info(adev->dev, " SCRATCH_ADDR=0x%08X\n",
RREG32(mmSCRATCH_ADDR));
dev_info(adev->dev, " SCRATCH_UMSK=0x%08X\n",
RREG32(mmSCRATCH_UMSK));
dev_info(adev->dev, " CP_INT_CNTL_RING0=0x%08X\n",
RREG32(mmCP_INT_CNTL_RING0));
dev_info(adev->dev, " RLC_LB_CNTL=0x%08X\n",
RREG32(mmRLC_LB_CNTL));
dev_info(adev->dev, " RLC_CNTL=0x%08X\n",
RREG32(mmRLC_CNTL));
dev_info(adev->dev, " RLC_CGCG_CGLS_CTRL=0x%08X\n",
RREG32(mmRLC_CGCG_CGLS_CTRL));
dev_info(adev->dev, " RLC_LB_CNTR_INIT=0x%08X\n",
RREG32(mmRLC_LB_CNTR_INIT));
dev_info(adev->dev, " RLC_LB_CNTR_MAX=0x%08X\n",
RREG32(mmRLC_LB_CNTR_MAX));
dev_info(adev->dev, " RLC_LB_INIT_CU_MASK=0x%08X\n",
RREG32(mmRLC_LB_INIT_CU_MASK));
dev_info(adev->dev, " RLC_LB_PARAMS=0x%08X\n",
RREG32(mmRLC_LB_PARAMS));
dev_info(adev->dev, " RLC_LB_CNTL=0x%08X\n",
RREG32(mmRLC_LB_CNTL));
dev_info(adev->dev, " RLC_MC_CNTL=0x%08X\n",
RREG32(mmRLC_MC_CNTL));
dev_info(adev->dev, " RLC_UCODE_CNTL=0x%08X\n",
RREG32(mmRLC_UCODE_CNTL));
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < 16; i++) {
vi_srbm_select(adev, 0, 0, 0, i);
dev_info(adev->dev, " VM %d:\n", i);
dev_info(adev->dev, " SH_MEM_CONFIG=0x%08X\n",
RREG32(mmSH_MEM_CONFIG));
dev_info(adev->dev, " SH_MEM_APE1_BASE=0x%08X\n",
RREG32(mmSH_MEM_APE1_BASE));
dev_info(adev->dev, " SH_MEM_APE1_LIMIT=0x%08X\n",
RREG32(mmSH_MEM_APE1_LIMIT));
dev_info(adev->dev, " SH_MEM_BASES=0x%08X\n",
RREG32(mmSH_MEM_BASES));
}
vi_srbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
}
static int gfx_v8_0_soft_reset(void *handle)
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
GRBM_STATUS__IA_BUSY_MASK | GRBM_STATUS__IA_BUSY_NO_DMA_MASK)) {
grbm_soft_reset = REG_SET_FIELD(grbm_soft_reset,
GRBM_SOFT_RESET, SOFT_RESET_CP, 1);
grbm_soft_reset = REG_SET_FIELD(grbm_soft_reset,
GRBM_SOFT_RESET, SOFT_RESET_GFX, 1);
}
if (tmp & (GRBM_STATUS__CP_BUSY_MASK | GRBM_STATUS__CP_COHERENCY_BUSY_MASK)) {
grbm_soft_reset = REG_SET_FIELD(grbm_soft_reset,
GRBM_SOFT_RESET, SOFT_RESET_CP, 1);
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset,
SRBM_SOFT_RESET, SOFT_RESET_GRBM, 1);
}
tmp = RREG32(mmGRBM_STATUS2);
if (REG_GET_FIELD(tmp, GRBM_STATUS2, RLC_BUSY))
grbm_soft_reset = REG_SET_FIELD(grbm_soft_reset,
GRBM_SOFT_RESET, SOFT_RESET_RLC, 1);
tmp = RREG32(mmSRBM_STATUS);
if (REG_GET_FIELD(tmp, SRBM_STATUS, GRBM_RQ_PENDING))
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset,
SRBM_SOFT_RESET, SOFT_RESET_GRBM, 1);
if (grbm_soft_reset || srbm_soft_reset) {
gfx_v8_0_print_status((void *)adev);
gfx_v8_0_rlc_stop(adev);
gfx_v8_0_cp_gfx_enable(adev, false);
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
gfx_v8_0_print_status((void *)adev);
}
return 0;
}
uint64_t gfx_v8_0_get_gpu_clock_counter(struct amdgpu_device *adev)
{
uint64_t clock;
mutex_lock(&adev->gfx.gpu_clock_mutex);
WREG32(mmRLC_CAPTURE_GPU_CLOCK_COUNT, 1);
clock = (uint64_t)RREG32(mmRLC_GPU_CLOCK_COUNT_LSB) |
((uint64_t)RREG32(mmRLC_GPU_CLOCK_COUNT_MSB) << 32ULL);
mutex_unlock(&adev->gfx.gpu_clock_mutex);
return clock;
}
static void gfx_v8_0_ring_emit_gds_switch(struct amdgpu_ring *ring,
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
static int gfx_v8_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->gfx.num_gfx_rings = GFX8_NUM_GFX_RINGS;
adev->gfx.num_compute_rings = GFX8_NUM_COMPUTE_RINGS;
gfx_v8_0_set_ring_funcs(adev);
gfx_v8_0_set_irq_funcs(adev);
gfx_v8_0_set_gds_init(adev);
return 0;
}
static int gfx_v8_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static int gfx_v8_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static u32 gfx_v8_0_ring_get_rptr_gfx(struct amdgpu_ring *ring)
{
u32 rptr;
rptr = ring->adev->wb.wb[ring->rptr_offs];
return rptr;
}
static u32 gfx_v8_0_ring_get_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u32 wptr;
if (ring->use_doorbell)
wptr = ring->adev->wb.wb[ring->wptr_offs];
else
wptr = RREG32(mmCP_RB0_WPTR);
return wptr;
}
static void gfx_v8_0_ring_set_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring->use_doorbell) {
adev->wb.wb[ring->wptr_offs] = ring->wptr;
WDOORBELL32(ring->doorbell_index, ring->wptr);
} else {
WREG32(mmCP_RB0_WPTR, ring->wptr);
(void)RREG32(mmCP_RB0_WPTR);
}
}
static void gfx_v8_0_ring_emit_hdp_flush(struct amdgpu_ring *ring)
{
u32 ref_and_mask, reg_mem_engine;
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
reg_mem_engine = 0;
} else {
ref_and_mask = GPU_HDP_FLUSH_DONE__CP0_MASK;
reg_mem_engine = WAIT_REG_MEM_ENGINE(1);
}
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring, (WAIT_REG_MEM_OPERATION(1) |
WAIT_REG_MEM_FUNCTION(3) |
reg_mem_engine));
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_REQ);
amdgpu_ring_write(ring, mmGPU_HDP_FLUSH_DONE);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, ref_and_mask);
amdgpu_ring_write(ring, 0x20);
}
static void gfx_v8_0_ring_emit_ib_gfx(struct amdgpu_ring *ring,
struct amdgpu_ib *ib)
{
bool need_ctx_switch = ring->current_ctx != ib->ctx;
u32 header, control = 0;
u32 next_rptr = ring->wptr + 5;
if ((ib->flags & AMDGPU_IB_FLAG_PREAMBLE) && !need_ctx_switch)
return;
if (need_ctx_switch)
next_rptr += 2;
next_rptr += 4;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, WRITE_DATA_DST_SEL(5) | WR_CONFIRM);
amdgpu_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xffffffff);
amdgpu_ring_write(ring, next_rptr);
if (need_ctx_switch) {
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
}
if (ib->flags & AMDGPU_IB_FLAG_CE)
header = PACKET3(PACKET3_INDIRECT_BUFFER_CONST, 2);
else
header = PACKET3(PACKET3_INDIRECT_BUFFER, 2);
control |= ib->length_dw |
(ib->vm ? (ib->vm->ids[ring->idx].id << 24) : 0);
amdgpu_ring_write(ring, header);
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
amdgpu_ring_write(ring, control);
}
static void gfx_v8_0_ring_emit_ib_compute(struct amdgpu_ring *ring,
struct amdgpu_ib *ib)
{
u32 header, control = 0;
u32 next_rptr = ring->wptr + 5;
control |= INDIRECT_BUFFER_VALID;
next_rptr += 4;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, WRITE_DATA_DST_SEL(5) | WR_CONFIRM);
amdgpu_ring_write(ring, ring->next_rptr_gpu_addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(ring->next_rptr_gpu_addr) & 0xffffffff);
amdgpu_ring_write(ring, next_rptr);
header = PACKET3(PACKET3_INDIRECT_BUFFER, 2);
control |= ib->length_dw |
(ib->vm ? (ib->vm->ids[ring->idx].id << 24) : 0);
amdgpu_ring_write(ring, header);
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
(ib->gpu_addr & 0xFFFFFFFC));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
amdgpu_ring_write(ring, control);
}
static void gfx_v8_0_ring_emit_fence_gfx(struct amdgpu_ring *ring, u64 addr,
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
DATA_SEL(write64bit ? 2 : 1) | INT_SEL(int_sel ? 2 : 0));
amdgpu_ring_write(ring, lower_32_bits(seq));
amdgpu_ring_write(ring, upper_32_bits(seq));
}
static bool gfx_v8_0_ring_emit_semaphore(struct amdgpu_ring *ring,
struct amdgpu_semaphore *semaphore,
bool emit_wait)
{
uint64_t addr = semaphore->gpu_addr;
unsigned sel = emit_wait ? PACKET3_SEM_SEL_WAIT : PACKET3_SEM_SEL_SIGNAL;
if (ring->adev->asic_type == CHIP_TOPAZ ||
ring->adev->asic_type == CHIP_TONGA)
return false;
else {
amdgpu_ring_write(ring, PACKET3(PACKET3_MEM_SEMAPHORE, 2));
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, sel);
}
if (emit_wait && (ring->type == AMDGPU_RING_TYPE_GFX)) {
amdgpu_ring_write(ring, PACKET3(PACKET3_PFP_SYNC_ME, 0));
amdgpu_ring_write(ring, 0x0);
}
return true;
}
static void gfx_v8_0_ce_sync_me(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u64 gpu_addr = adev->wb.gpu_addr + adev->gfx.ce_sync_offs * 4;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(5)));
amdgpu_ring_write(ring, gpu_addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(gpu_addr) & 0xffffffff);
amdgpu_ring_write(ring, 1);
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring, (WAIT_REG_MEM_OPERATION(0) |
WAIT_REG_MEM_MEM_SPACE(1) |
WAIT_REG_MEM_FUNCTION(3) |
WAIT_REG_MEM_ENGINE(2)));
amdgpu_ring_write(ring, gpu_addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(gpu_addr) & 0xffffffff);
amdgpu_ring_write(ring, 1);
amdgpu_ring_write(ring, 0xffffffff);
amdgpu_ring_write(ring, 4);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(2) |
WRITE_DATA_DST_SEL(5) |
WR_CONFIRM));
amdgpu_ring_write(ring, gpu_addr & 0xfffffffc);
amdgpu_ring_write(ring, upper_32_bits(gpu_addr) & 0xffffffff);
amdgpu_ring_write(ring, 0);
}
static void gfx_v8_0_ring_emit_vm_flush(struct amdgpu_ring *ring,
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
gfx_v8_0_ce_sync_me(ring);
}
}
static bool gfx_v8_0_ring_is_lockup(struct amdgpu_ring *ring)
{
if (gfx_v8_0_is_idle(ring->adev)) {
amdgpu_ring_lockup_update(ring);
return false;
}
return amdgpu_ring_test_lockup(ring);
}
static u32 gfx_v8_0_ring_get_rptr_compute(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs];
}
static u32 gfx_v8_0_ring_get_wptr_compute(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->wptr_offs];
}
static void gfx_v8_0_ring_set_wptr_compute(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
adev->wb.wb[ring->wptr_offs] = ring->wptr;
WDOORBELL32(ring->doorbell_index, ring->wptr);
}
static void gfx_v8_0_ring_emit_fence_compute(struct amdgpu_ring *ring,
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
static void gfx_v8_0_set_gfx_eop_interrupt_state(struct amdgpu_device *adev,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl = REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
TIME_STAMP_INT_ENABLE, 0);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl =
REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
TIME_STAMP_INT_ENABLE, 1);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
}
static void gfx_v8_0_set_compute_eop_interrupt_state(struct amdgpu_device *adev,
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
mec_int_cntl = REG_SET_FIELD(mec_int_cntl, CP_ME1_PIPE0_INT_CNTL,
TIME_STAMP_INT_ENABLE, 0);
WREG32(mec_int_cntl_reg, mec_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
mec_int_cntl = RREG32(mec_int_cntl_reg);
mec_int_cntl = REG_SET_FIELD(mec_int_cntl, CP_ME1_PIPE0_INT_CNTL,
TIME_STAMP_INT_ENABLE, 1);
WREG32(mec_int_cntl_reg, mec_int_cntl);
break;
default:
break;
}
}
static int gfx_v8_0_set_priv_reg_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl = REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
PRIV_REG_INT_ENABLE, 0);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl = REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
PRIV_REG_INT_ENABLE, 0);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
return 0;
}
static int gfx_v8_0_set_priv_inst_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 cp_int_cntl;
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl = REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
PRIV_INSTR_INT_ENABLE, 0);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
case AMDGPU_IRQ_STATE_ENABLE:
cp_int_cntl = RREG32(mmCP_INT_CNTL_RING0);
cp_int_cntl = REG_SET_FIELD(cp_int_cntl, CP_INT_CNTL_RING0,
PRIV_INSTR_INT_ENABLE, 1);
WREG32(mmCP_INT_CNTL_RING0, cp_int_cntl);
break;
default:
break;
}
return 0;
}
static int gfx_v8_0_set_eop_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
switch (type) {
case AMDGPU_CP_IRQ_GFX_EOP:
gfx_v8_0_set_gfx_eop_interrupt_state(adev, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 1, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE1_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 1, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE2_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 1, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE3_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 1, 3, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE0_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 2, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE1_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 2, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE2_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 2, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE3_EOP:
gfx_v8_0_set_compute_eop_interrupt_state(adev, 2, 3, state);
break;
default:
break;
}
return 0;
}
static int gfx_v8_0_eop_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
int i;
u8 me_id, pipe_id, queue_id;
struct amdgpu_ring *ring;
DRM_DEBUG("IH: CP EOP\n");
me_id = (entry->ring_id & 0x0c) >> 2;
pipe_id = (entry->ring_id & 0x03) >> 0;
queue_id = (entry->ring_id & 0x70) >> 4;
switch (me_id) {
case 0:
amdgpu_fence_process(&adev->gfx.gfx_ring[0]);
break;
case 1:
case 2:
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
if ((ring->me == me_id) && (ring->pipe == pipe_id) && (ring->queue == queue_id))
amdgpu_fence_process(ring);
}
break;
}
return 0;
}
static int gfx_v8_0_priv_reg_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal register access in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static int gfx_v8_0_priv_inst_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal instruction in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static void gfx_v8_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].funcs = &gfx_v8_0_ring_funcs_gfx;
for (i = 0; i < adev->gfx.num_compute_rings; i++)
adev->gfx.compute_ring[i].funcs = &gfx_v8_0_ring_funcs_compute;
}
static void gfx_v8_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->gfx.eop_irq.num_types = AMDGPU_CP_IRQ_LAST;
adev->gfx.eop_irq.funcs = &gfx_v8_0_eop_irq_funcs;
adev->gfx.priv_reg_irq.num_types = 1;
adev->gfx.priv_reg_irq.funcs = &gfx_v8_0_priv_reg_irq_funcs;
adev->gfx.priv_inst_irq.num_types = 1;
adev->gfx.priv_inst_irq.funcs = &gfx_v8_0_priv_inst_irq_funcs;
}
static void gfx_v8_0_set_gds_init(struct amdgpu_device *adev)
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
static u32 gfx_v8_0_get_cu_active_bitmap(struct amdgpu_device *adev,
u32 se, u32 sh)
{
u32 mask = 0, tmp, tmp1;
int i;
gfx_v8_0_select_se_sh(adev, se, sh);
tmp = RREG32(mmCC_GC_SHADER_ARRAY_CONFIG);
tmp1 = RREG32(mmGC_USER_SHADER_ARRAY_CONFIG);
gfx_v8_0_select_se_sh(adev, 0xffffffff, 0xffffffff);
tmp &= 0xffff0000;
tmp |= tmp1;
tmp >>= 16;
for (i = 0; i < adev->gfx.config.max_cu_per_sh; i ++) {
mask <<= 1;
mask |= 1;
}
return (~tmp) & mask;
}
int gfx_v8_0_get_cu_info(struct amdgpu_device *adev,
struct amdgpu_cu_info *cu_info)
{
int i, j, k, counter, active_cu_number = 0;
u32 mask, bitmap, ao_bitmap, ao_cu_mask = 0;
if (!adev || !cu_info)
return -EINVAL;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
mask = 1;
ao_bitmap = 0;
counter = 0;
bitmap = gfx_v8_0_get_cu_active_bitmap(adev, i, j);
cu_info->bitmap[i][j] = bitmap;
for (k = 0; k < adev->gfx.config.max_cu_per_sh; k ++) {
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
cu_info->number = active_cu_number;
cu_info->ao_cu_mask = ao_cu_mask;
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
