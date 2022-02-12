static void gfx_v9_0_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_VEGA10:
amdgpu_program_register_sequence(adev,
golden_settings_gc_9_0,
(const u32)ARRAY_SIZE(golden_settings_gc_9_0));
amdgpu_program_register_sequence(adev,
golden_settings_gc_9_0_vg10,
(const u32)ARRAY_SIZE(golden_settings_gc_9_0_vg10));
break;
default:
break;
}
}
static void gfx_v9_0_scratch_init(struct amdgpu_device *adev)
{
adev->gfx.scratch.num_reg = 7;
adev->gfx.scratch.reg_base = SOC15_REG_OFFSET(GC, 0, mmSCRATCH_REG0);
adev->gfx.scratch.free_mask = (1u << adev->gfx.scratch.num_reg) - 1;
}
static void gfx_v9_0_write_data_to_reg(struct amdgpu_ring *ring, int eng_sel,
bool wc, uint32_t reg, uint32_t val)
{
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, WRITE_DATA_ENGINE_SEL(eng_sel) |
WRITE_DATA_DST_SEL(0) |
(wc ? WR_CONFIRM : 0));
amdgpu_ring_write(ring, reg);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, val);
}
static void gfx_v9_0_wait_reg_mem(struct amdgpu_ring *ring, int eng_sel,
int mem_space, int opt, uint32_t addr0,
uint32_t addr1, uint32_t ref, uint32_t mask,
uint32_t inv)
{
amdgpu_ring_write(ring, PACKET3(PACKET3_WAIT_REG_MEM, 5));
amdgpu_ring_write(ring,
(WAIT_REG_MEM_MEM_SPACE(mem_space) |
WAIT_REG_MEM_OPERATION(opt) |
WAIT_REG_MEM_FUNCTION(3) |
WAIT_REG_MEM_ENGINE(eng_sel)));
if (mem_space)
BUG_ON(addr0 & 0x3);
amdgpu_ring_write(ring, addr0);
amdgpu_ring_write(ring, addr1);
amdgpu_ring_write(ring, ref);
amdgpu_ring_write(ring, mask);
amdgpu_ring_write(ring, inv);
}
static int gfx_v9_0_ring_test_ring(struct amdgpu_ring *ring)
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
DRM_ERROR("amdgpu: cp failed to lock ring %d (%d).\n",
ring->idx, r);
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
static int gfx_v9_0_ring_test_ib(struct amdgpu_ring *ring, long timeout)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_ib ib;
struct dma_fence *f = NULL;
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
r = amdgpu_ib_schedule(ring, 1, &ib, NULL, &f);
if (r)
goto err2;
r = dma_fence_wait_timeout(f, false, timeout);
if (r == 0) {
DRM_ERROR("amdgpu: IB test timed out.\n");
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
dma_fence_put(f);
err1:
amdgpu_gfx_scratch_free(adev, scratch);
return r;
}
static int gfx_v9_0_init_microcode(struct amdgpu_device *adev)
{
const char *chip_name;
char fw_name[30];
int err;
struct amdgpu_firmware_info *info = NULL;
const struct common_firmware_header *header = NULL;
const struct gfx_firmware_header_v1_0 *cp_hdr;
DRM_DEBUG("\n");
switch (adev->asic_type) {
case CHIP_VEGA10:
chip_name = "vega10";
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
adev->gfx.mec2_fw_version =
le32_to_cpu(cp_hdr->header.ucode_version);
adev->gfx.mec2_feature_version =
le32_to_cpu(cp_hdr->ucode_feature_version);
} else {
err = 0;
adev->gfx.mec2_fw = NULL;
}
if (adev->firmware.load_type == AMDGPU_FW_LOAD_PSP) {
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
cp_hdr = (const struct gfx_firmware_header_v1_0 *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes) - le32_to_cpu(cp_hdr->jt_size) * 4, PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_MEC1_JT];
info->ucode_id = AMDGPU_UCODE_ID_CP_MEC1_JT;
info->fw = adev->gfx.mec_fw;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(cp_hdr->jt_size) * 4, PAGE_SIZE);
if (adev->gfx.mec2_fw) {
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_MEC2];
info->ucode_id = AMDGPU_UCODE_ID_CP_MEC2;
info->fw = adev->gfx.mec2_fw;
header = (const struct common_firmware_header *)info->fw->data;
cp_hdr = (const struct gfx_firmware_header_v1_0 *)info->fw->data;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(header->ucode_size_bytes) - le32_to_cpu(cp_hdr->jt_size) * 4, PAGE_SIZE);
info = &adev->firmware.ucode[AMDGPU_UCODE_ID_CP_MEC2_JT];
info->ucode_id = AMDGPU_UCODE_ID_CP_MEC2_JT;
info->fw = adev->gfx.mec2_fw;
adev->firmware.fw_size +=
ALIGN(le32_to_cpu(cp_hdr->jt_size) * 4, PAGE_SIZE);
}
}
out:
if (err) {
dev_err(adev->dev,
"gfx9: Failed to load firmware \"%s\"\n",
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
static void gfx_v9_0_mec_fini(struct amdgpu_device *adev)
{
int r;
if (adev->gfx.mec.hpd_eop_obj) {
r = amdgpu_bo_reserve(adev->gfx.mec.hpd_eop_obj, true);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve HPD EOP bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unreserve(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unref(&adev->gfx.mec.hpd_eop_obj);
adev->gfx.mec.hpd_eop_obj = NULL;
}
if (adev->gfx.mec.mec_fw_obj) {
r = amdgpu_bo_reserve(adev->gfx.mec.mec_fw_obj, true);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve mec firmware bo failed\n", r);
amdgpu_bo_unpin(adev->gfx.mec.mec_fw_obj);
amdgpu_bo_unreserve(adev->gfx.mec.mec_fw_obj);
amdgpu_bo_unref(&adev->gfx.mec.mec_fw_obj);
adev->gfx.mec.mec_fw_obj = NULL;
}
}
static int gfx_v9_0_mec_init(struct amdgpu_device *adev)
{
int r;
u32 *hpd;
const __le32 *fw_data;
unsigned fw_size;
u32 *fw;
const struct gfx_firmware_header_v1_0 *mec_hdr;
adev->gfx.mec.num_mec = 1;
adev->gfx.mec.num_pipe = 1;
adev->gfx.mec.num_queue = adev->gfx.mec.num_mec * adev->gfx.mec.num_pipe * 8;
if (adev->gfx.mec.hpd_eop_obj == NULL) {
r = amdgpu_bo_create(adev,
adev->gfx.mec.num_queue * MEC_HPD_SIZE,
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
gfx_v9_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.mec.hpd_eop_obj, AMDGPU_GEM_DOMAIN_GTT,
&adev->gfx.mec.hpd_eop_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin HDP EOP bo failed\n", r);
gfx_v9_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.mec.hpd_eop_obj, (void **)&hpd);
if (r) {
dev_warn(adev->dev, "(%d) map HDP EOP bo failed\n", r);
gfx_v9_0_mec_fini(adev);
return r;
}
memset(hpd, 0, adev->gfx.mec.hpd_eop_obj->tbo.mem.size);
amdgpu_bo_kunmap(adev->gfx.mec.hpd_eop_obj);
amdgpu_bo_unreserve(adev->gfx.mec.hpd_eop_obj);
mec_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
fw_data = (const __le32 *)
(adev->gfx.mec_fw->data +
le32_to_cpu(mec_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(mec_hdr->header.ucode_size_bytes) / 4;
if (adev->gfx.mec.mec_fw_obj == NULL) {
r = amdgpu_bo_create(adev,
mec_hdr->header.ucode_size_bytes,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL, NULL,
&adev->gfx.mec.mec_fw_obj);
if (r) {
dev_warn(adev->dev, "(%d) create mec firmware bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(adev->gfx.mec.mec_fw_obj, false);
if (unlikely(r != 0)) {
gfx_v9_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_pin(adev->gfx.mec.mec_fw_obj, AMDGPU_GEM_DOMAIN_GTT,
&adev->gfx.mec.mec_fw_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin mec firmware bo failed\n", r);
gfx_v9_0_mec_fini(adev);
return r;
}
r = amdgpu_bo_kmap(adev->gfx.mec.mec_fw_obj, (void **)&fw);
if (r) {
dev_warn(adev->dev, "(%d) map firmware bo failed\n", r);
gfx_v9_0_mec_fini(adev);
return r;
}
memcpy(fw, fw_data, fw_size);
amdgpu_bo_kunmap(adev->gfx.mec.mec_fw_obj);
amdgpu_bo_unreserve(adev->gfx.mec.mec_fw_obj);
return 0;
}
static void gfx_v9_0_kiq_fini(struct amdgpu_device *adev)
{
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
amdgpu_bo_free_kernel(&kiq->eop_obj, &kiq->eop_gpu_addr, NULL);
}
static int gfx_v9_0_kiq_init(struct amdgpu_device *adev)
{
int r;
u32 *hpd;
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
r = amdgpu_bo_create_kernel(adev, MEC_HPD_SIZE, PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT, &kiq->eop_obj,
&kiq->eop_gpu_addr, (void **)&hpd);
if (r) {
dev_warn(adev->dev, "failed to create KIQ bo (%d).\n", r);
return r;
}
memset(hpd, 0, MEC_HPD_SIZE);
r = amdgpu_bo_reserve(kiq->eop_obj, true);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve kiq eop bo failed\n", r);
amdgpu_bo_kunmap(kiq->eop_obj);
amdgpu_bo_unreserve(kiq->eop_obj);
return 0;
}
static int gfx_v9_0_kiq_init_ring(struct amdgpu_device *adev,
struct amdgpu_ring *ring,
struct amdgpu_irq_src *irq)
{
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
int r = 0;
r = amdgpu_wb_get(adev, &adev->virt.reg_val_offs);
if (r)
return r;
ring->adev = NULL;
ring->ring_obj = NULL;
ring->use_doorbell = true;
ring->doorbell_index = AMDGPU_DOORBELL_KIQ;
if (adev->gfx.mec2_fw) {
ring->me = 2;
ring->pipe = 0;
} else {
ring->me = 1;
ring->pipe = 1;
}
ring->queue = 0;
ring->eop_gpu_addr = kiq->eop_gpu_addr;
sprintf(ring->name, "kiq %d.%d.%d", ring->me, ring->pipe, ring->queue);
r = amdgpu_ring_init(adev, ring, 1024,
irq, AMDGPU_CP_KIQ_IRQ_DRIVER0);
if (r)
dev_warn(adev->dev, "(%d) failed to init kiq ring\n", r);
return r;
}
static void gfx_v9_0_kiq_free_ring(struct amdgpu_ring *ring,
struct amdgpu_irq_src *irq)
{
amdgpu_wb_free(ring->adev, ring->adev->virt.reg_val_offs);
amdgpu_ring_fini(ring);
}
static int gfx_v9_0_compute_mqd_sw_init(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = NULL;
int r, i;
ring = &adev->gfx.kiq.ring;
if (!ring->mqd_obj) {
r = amdgpu_bo_create_kernel(adev, sizeof(struct v9_mqd), PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT, &ring->mqd_obj,
&ring->mqd_gpu_addr, (void **)&ring->mqd_ptr);
if (r) {
dev_warn(adev->dev, "failed to create ring mqd ob (%d)", r);
return r;
}
}
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
if (!ring->mqd_obj) {
r = amdgpu_bo_create_kernel(adev, sizeof(struct v9_mqd), PAGE_SIZE,
AMDGPU_GEM_DOMAIN_GTT, &ring->mqd_obj,
&ring->mqd_gpu_addr, (void **)&ring->mqd_ptr);
if (r) {
dev_warn(adev->dev, "failed to create ring mqd ob (%d)", r);
return r;
}
}
}
return 0;
}
static void gfx_v9_0_compute_mqd_sw_fini(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = NULL;
int i;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
amdgpu_bo_free_kernel(&ring->mqd_obj, &ring->mqd_gpu_addr, (void **)&ring->mqd_ptr);
}
ring = &adev->gfx.kiq.ring;
amdgpu_bo_free_kernel(&ring->mqd_obj, &ring->mqd_gpu_addr, (void **)&ring->mqd_ptr);
}
static uint32_t wave_read_ind(struct amdgpu_device *adev, uint32_t simd, uint32_t wave, uint32_t address)
{
WREG32_SOC15(GC, 0, mmSQ_IND_INDEX,
(wave << SQ_IND_INDEX__WAVE_ID__SHIFT) |
(simd << SQ_IND_INDEX__SIMD_ID__SHIFT) |
(address << SQ_IND_INDEX__INDEX__SHIFT) |
(SQ_IND_INDEX__FORCE_READ_MASK));
return RREG32_SOC15(GC, 0, mmSQ_IND_DATA);
}
static void wave_read_regs(struct amdgpu_device *adev, uint32_t simd,
uint32_t wave, uint32_t thread,
uint32_t regno, uint32_t num, uint32_t *out)
{
WREG32_SOC15(GC, 0, mmSQ_IND_INDEX,
(wave << SQ_IND_INDEX__WAVE_ID__SHIFT) |
(simd << SQ_IND_INDEX__SIMD_ID__SHIFT) |
(regno << SQ_IND_INDEX__INDEX__SHIFT) |
(thread << SQ_IND_INDEX__THREAD_ID__SHIFT) |
(SQ_IND_INDEX__FORCE_READ_MASK) |
(SQ_IND_INDEX__AUTO_INCR_MASK));
while (num--)
*(out++) = RREG32_SOC15(GC, 0, mmSQ_IND_DATA);
}
static void gfx_v9_0_read_wave_data(struct amdgpu_device *adev, uint32_t simd, uint32_t wave, uint32_t *dst, int *no_fields)
{
dst[(*no_fields)++] = 1;
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_STATUS);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_PC_LO);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_PC_HI);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_EXEC_LO);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_EXEC_HI);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_HW_ID);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_INST_DW0);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_INST_DW1);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_GPR_ALLOC);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_LDS_ALLOC);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_TRAPSTS);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_IB_STS);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_IB_DBG0);
dst[(*no_fields)++] = wave_read_ind(adev, simd, wave, ixSQ_WAVE_M0);
}
static void gfx_v9_0_read_wave_sgprs(struct amdgpu_device *adev, uint32_t simd,
uint32_t wave, uint32_t start,
uint32_t size, uint32_t *dst)
{
wave_read_regs(
adev, simd, wave, 0,
start + SQIND_WAVE_SGPRS_OFFSET, size, dst);
}
static void gfx_v9_0_gpu_early_init(struct amdgpu_device *adev)
{
u32 gb_addr_config;
adev->gfx.funcs = &gfx_v9_0_gfx_funcs;
switch (adev->asic_type) {
case CHIP_VEGA10:
adev->gfx.config.max_shader_engines = 4;
adev->gfx.config.max_cu_per_sh = 16;
adev->gfx.config.max_sh_per_se = 1;
adev->gfx.config.max_backends_per_se = 4;
adev->gfx.config.max_texture_channel_caches = 16;
adev->gfx.config.max_gprs = 256;
adev->gfx.config.max_gs_threads = 32;
adev->gfx.config.max_hw_contexts = 8;
adev->gfx.config.sc_prim_fifo_size_frontend = 0x20;
adev->gfx.config.sc_prim_fifo_size_backend = 0x100;
adev->gfx.config.sc_hiz_tile_fifo_size = 0x30;
adev->gfx.config.sc_earlyz_tile_fifo_size = 0x4C0;
adev->gfx.config.gs_vgt_table_depth = 32;
adev->gfx.config.gs_prim_buffer_depth = 1792;
gb_addr_config = VEGA10_GB_ADDR_CONFIG_GOLDEN;
break;
default:
BUG();
break;
}
adev->gfx.config.gb_addr_config = gb_addr_config;
adev->gfx.config.gb_addr_config_fields.num_pipes = 1 <<
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
NUM_PIPES);
adev->gfx.config.max_tile_pipes =
adev->gfx.config.gb_addr_config_fields.num_pipes;
adev->gfx.config.gb_addr_config_fields.num_banks = 1 <<
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
NUM_BANKS);
adev->gfx.config.gb_addr_config_fields.max_compress_frags = 1 <<
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
MAX_COMPRESSED_FRAGS);
adev->gfx.config.gb_addr_config_fields.num_rb_per_se = 1 <<
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
NUM_RB_PER_SE);
adev->gfx.config.gb_addr_config_fields.num_se = 1 <<
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
NUM_SHADER_ENGINES);
adev->gfx.config.gb_addr_config_fields.pipe_interleave_size = 1 << (8 +
REG_GET_FIELD(
adev->gfx.config.gb_addr_config,
GB_ADDR_CONFIG,
PIPE_INTERLEAVE_SIZE));
}
static int gfx_v9_0_ngg_create_buf(struct amdgpu_device *adev,
struct amdgpu_ngg_buf *ngg_buf,
int size_se,
int default_size_se)
{
int r;
if (size_se < 0) {
dev_err(adev->dev, "Buffer size is invalid: %d\n", size_se);
return -EINVAL;
}
size_se = size_se ? size_se : default_size_se;
ngg_buf->size = size_se * adev->gfx.config.max_shader_engines;
r = amdgpu_bo_create_kernel(adev, ngg_buf->size,
PAGE_SIZE, AMDGPU_GEM_DOMAIN_VRAM,
&ngg_buf->bo,
&ngg_buf->gpu_addr,
NULL);
if (r) {
dev_err(adev->dev, "(%d) failed to create NGG buffer\n", r);
return r;
}
ngg_buf->bo_size = amdgpu_bo_size(ngg_buf->bo);
return r;
}
static int gfx_v9_0_ngg_fini(struct amdgpu_device *adev)
{
int i;
for (i = 0; i < NGG_BUF_MAX; i++)
amdgpu_bo_free_kernel(&adev->gfx.ngg.buf[i].bo,
&adev->gfx.ngg.buf[i].gpu_addr,
NULL);
memset(&adev->gfx.ngg.buf[0], 0,
sizeof(struct amdgpu_ngg_buf) * NGG_BUF_MAX);
adev->gfx.ngg.init = false;
return 0;
}
static int gfx_v9_0_ngg_init(struct amdgpu_device *adev)
{
int r;
if (!amdgpu_ngg || adev->gfx.ngg.init == true)
return 0;
adev->gfx.ngg.gds_reserve_size = ALIGN(5 * 4, 0x40);
adev->gds.mem.total_size -= adev->gfx.ngg.gds_reserve_size;
adev->gds.mem.gfx_partition_size -= adev->gfx.ngg.gds_reserve_size;
adev->gfx.ngg.gds_reserve_addr = amdgpu_gds_reg_offset[0].mem_base;
adev->gfx.ngg.gds_reserve_addr += adev->gds.mem.gfx_partition_size;
r = gfx_v9_0_ngg_create_buf(adev, &adev->gfx.ngg.buf[NGG_PRIM],
amdgpu_prim_buf_per_se,
64 * 1024);
if (r) {
dev_err(adev->dev, "Failed to create Primitive Buffer\n");
goto err;
}
r = gfx_v9_0_ngg_create_buf(adev, &adev->gfx.ngg.buf[NGG_POS],
amdgpu_pos_buf_per_se,
256 * 1024);
if (r) {
dev_err(adev->dev, "Failed to create Position Buffer\n");
goto err;
}
r = gfx_v9_0_ngg_create_buf(adev, &adev->gfx.ngg.buf[NGG_CNTL],
amdgpu_cntl_sb_buf_per_se,
256);
if (r) {
dev_err(adev->dev, "Failed to create Control Sideband Buffer\n");
goto err;
}
if (amdgpu_param_buf_per_se <= 0)
goto out;
r = gfx_v9_0_ngg_create_buf(adev, &adev->gfx.ngg.buf[NGG_PARAM],
amdgpu_param_buf_per_se,
512 * 1024);
if (r) {
dev_err(adev->dev, "Failed to create Parameter Cache\n");
goto err;
}
out:
adev->gfx.ngg.init = true;
return 0;
err:
gfx_v9_0_ngg_fini(adev);
return r;
}
static int gfx_v9_0_ngg_en(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->gfx.gfx_ring[0];
int r;
u32 data;
u32 size;
u32 base;
if (!amdgpu_ngg)
return 0;
data = 0;
size = adev->gfx.ngg.buf[NGG_PRIM].size / 256;
data = REG_SET_FIELD(data, WD_BUF_RESOURCE_1, INDEX_BUF_SIZE, size);
size = adev->gfx.ngg.buf[NGG_POS].size / 256;
data = REG_SET_FIELD(data, WD_BUF_RESOURCE_1, POS_BUF_SIZE, size);
WREG32_SOC15(GC, 0, mmWD_BUF_RESOURCE_1, data);
data = 0;
size = adev->gfx.ngg.buf[NGG_CNTL].size / 256;
data = REG_SET_FIELD(data, WD_BUF_RESOURCE_2, CNTL_SB_BUF_SIZE, size);
size = adev->gfx.ngg.buf[NGG_PARAM].size / 1024;
data = REG_SET_FIELD(data, WD_BUF_RESOURCE_2, PARAM_BUF_SIZE, size);
WREG32_SOC15(GC, 0, mmWD_BUF_RESOURCE_2, data);
base = lower_32_bits(adev->gfx.ngg.buf[NGG_PRIM].gpu_addr);
data = REG_SET_FIELD(0, WD_INDEX_BUF_BASE, BASE, base);
WREG32_SOC15(GC, 0, mmWD_INDEX_BUF_BASE, data);
base = upper_32_bits(adev->gfx.ngg.buf[NGG_PRIM].gpu_addr);
data = REG_SET_FIELD(0, WD_INDEX_BUF_BASE_HI, BASE_HI, base);
WREG32_SOC15(GC, 0, mmWD_INDEX_BUF_BASE_HI, data);
base = lower_32_bits(adev->gfx.ngg.buf[NGG_POS].gpu_addr);
data = REG_SET_FIELD(0, WD_POS_BUF_BASE, BASE, base);
WREG32_SOC15(GC, 0, mmWD_POS_BUF_BASE, data);
base = upper_32_bits(adev->gfx.ngg.buf[NGG_POS].gpu_addr);
data = REG_SET_FIELD(0, WD_POS_BUF_BASE_HI, BASE_HI, base);
WREG32_SOC15(GC, 0, mmWD_POS_BUF_BASE_HI, data);
base = lower_32_bits(adev->gfx.ngg.buf[NGG_CNTL].gpu_addr);
data = REG_SET_FIELD(0, WD_CNTL_SB_BUF_BASE, BASE, base);
WREG32_SOC15(GC, 0, mmWD_CNTL_SB_BUF_BASE, data);
base = upper_32_bits(adev->gfx.ngg.buf[NGG_CNTL].gpu_addr);
data = REG_SET_FIELD(0, WD_CNTL_SB_BUF_BASE_HI, BASE_HI, base);
WREG32_SOC15(GC, 0, mmWD_CNTL_SB_BUF_BASE_HI, data);
r = amdgpu_ring_alloc(ring, 17);
if (r) {
DRM_ERROR("amdgpu: NGG failed to lock ring %d (%d).\n",
ring->idx, r);
return r;
}
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[0].mem_size,
(adev->gds.mem.total_size +
adev->gfx.ngg.gds_reserve_size) >>
AMDGPU_GDS_SHIFT);
amdgpu_ring_write(ring, PACKET3(PACKET3_DMA_DATA, 5));
amdgpu_ring_write(ring, (PACKET3_DMA_DATA_CP_SYNC |
PACKET3_DMA_DATA_SRC_SEL(2)));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, adev->gfx.ngg.gds_reserve_addr);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, adev->gfx.ngg.gds_reserve_size);
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[0].mem_size, 0);
amdgpu_ring_commit(ring);
return 0;
}
static int gfx_v9_0_sw_init(void *handle)
{
int i, r;
struct amdgpu_ring *ring;
struct amdgpu_kiq *kiq;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_GRBM_CP, 178, &adev->gfx.kiq.irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_GRBM_CP, 181, &adev->gfx.eop_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_GRBM_CP, 184,
&adev->gfx.priv_reg_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_GRBM_CP, 185,
&adev->gfx.priv_inst_irq);
if (r)
return r;
adev->gfx.gfx_current_status = AMDGPU_GFX_NORMAL_MODE;
gfx_v9_0_scratch_init(adev);
r = gfx_v9_0_init_microcode(adev);
if (r) {
DRM_ERROR("Failed to load gfx firmware!\n");
return r;
}
r = gfx_v9_0_mec_init(adev);
if (r) {
DRM_ERROR("Failed to init MEC BOs!\n");
return r;
}
for (i = 0; i < adev->gfx.num_gfx_rings; i++) {
ring = &adev->gfx.gfx_ring[i];
ring->ring_obj = NULL;
sprintf(ring->name, "gfx");
ring->use_doorbell = true;
ring->doorbell_index = AMDGPU_DOORBELL64_GFX_RING0 << 1;
r = amdgpu_ring_init(adev, ring, 1024,
&adev->gfx.eop_irq, AMDGPU_CP_IRQ_GFX_EOP);
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
ring->doorbell_index = (AMDGPU_DOORBELL64_MEC_RING0 + i) << 1;
ring->me = 1;
ring->pipe = i / 8;
ring->queue = i % 8;
ring->eop_gpu_addr = adev->gfx.mec.hpd_eop_gpu_addr + (i * MEC_HPD_SIZE);
sprintf(ring->name, "comp_%d.%d.%d", ring->me, ring->pipe, ring->queue);
irq_type = AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP + ring->pipe;
r = amdgpu_ring_init(adev, ring, 1024,
&adev->gfx.eop_irq, irq_type);
if (r)
return r;
}
if (amdgpu_sriov_vf(adev)) {
r = gfx_v9_0_kiq_init(adev);
if (r) {
DRM_ERROR("Failed to init KIQ BOs!\n");
return r;
}
kiq = &adev->gfx.kiq;
r = gfx_v9_0_kiq_init_ring(adev, &kiq->ring, &kiq->irq);
if (r)
return r;
r = gfx_v9_0_compute_mqd_sw_init(adev);
if (r)
return r;
}
r = amdgpu_bo_create_kernel(adev, adev->gds.mem.gfx_partition_size,
PAGE_SIZE, AMDGPU_GEM_DOMAIN_GDS,
&adev->gds.gds_gfx_bo, NULL, NULL);
if (r)
return r;
r = amdgpu_bo_create_kernel(adev, adev->gds.gws.gfx_partition_size,
PAGE_SIZE, AMDGPU_GEM_DOMAIN_GWS,
&adev->gds.gws_gfx_bo, NULL, NULL);
if (r)
return r;
r = amdgpu_bo_create_kernel(adev, adev->gds.oa.gfx_partition_size,
PAGE_SIZE, AMDGPU_GEM_DOMAIN_OA,
&adev->gds.oa_gfx_bo, NULL, NULL);
if (r)
return r;
adev->gfx.ce_ram_size = 0x8000;
gfx_v9_0_gpu_early_init(adev);
r = gfx_v9_0_ngg_init(adev);
if (r)
return r;
return 0;
}
static int gfx_v9_0_sw_fini(void *handle)
{
int i;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_bo_free_kernel(&adev->gds.oa_gfx_bo, NULL, NULL);
amdgpu_bo_free_kernel(&adev->gds.gws_gfx_bo, NULL, NULL);
amdgpu_bo_free_kernel(&adev->gds.gds_gfx_bo, NULL, NULL);
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
amdgpu_ring_fini(&adev->gfx.gfx_ring[i]);
for (i = 0; i < adev->gfx.num_compute_rings; i++)
amdgpu_ring_fini(&adev->gfx.compute_ring[i]);
if (amdgpu_sriov_vf(adev)) {
gfx_v9_0_compute_mqd_sw_fini(adev);
gfx_v9_0_kiq_free_ring(&adev->gfx.kiq.ring, &adev->gfx.kiq.irq);
gfx_v9_0_kiq_fini(adev);
}
gfx_v9_0_mec_fini(adev);
gfx_v9_0_ngg_fini(adev);
return 0;
}
static void gfx_v9_0_tiling_mode_table_init(struct amdgpu_device *adev)
{
}
static void gfx_v9_0_select_se_sh(struct amdgpu_device *adev, u32 se_num, u32 sh_num, u32 instance)
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
WREG32_SOC15(GC, 0, mmGRBM_GFX_INDEX, data);
}
static u32 gfx_v9_0_create_bitmask(u32 bit_width)
{
return (u32)((1ULL << bit_width) - 1);
}
static u32 gfx_v9_0_get_rb_active_bitmap(struct amdgpu_device *adev)
{
u32 data, mask;
data = RREG32_SOC15(GC, 0, mmCC_RB_BACKEND_DISABLE);
data |= RREG32_SOC15(GC, 0, mmGC_USER_RB_BACKEND_DISABLE);
data &= CC_RB_BACKEND_DISABLE__BACKEND_DISABLE_MASK;
data >>= GC_USER_RB_BACKEND_DISABLE__BACKEND_DISABLE__SHIFT;
mask = gfx_v9_0_create_bitmask(adev->gfx.config.max_backends_per_se /
adev->gfx.config.max_sh_per_se);
return (~data) & mask;
}
static void gfx_v9_0_setup_rb(struct amdgpu_device *adev)
{
int i, j;
u32 data;
u32 active_rbs = 0;
u32 rb_bitmap_width_per_sh = adev->gfx.config.max_backends_per_se /
adev->gfx.config.max_sh_per_se;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
gfx_v9_0_select_se_sh(adev, i, j, 0xffffffff);
data = gfx_v9_0_get_rb_active_bitmap(adev);
active_rbs |= data << ((i * adev->gfx.config.max_sh_per_se + j) *
rb_bitmap_width_per_sh);
}
}
gfx_v9_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
adev->gfx.config.backend_enable_mask = active_rbs;
adev->gfx.config.num_rbs = hweight32(active_rbs);
}
static void gfx_v9_0_init_compute_vmid(struct amdgpu_device *adev)
{
int i;
uint32_t sh_mem_config;
uint32_t sh_mem_bases;
sh_mem_bases = DEFAULT_SH_MEM_BASES | (DEFAULT_SH_MEM_BASES << 16);
sh_mem_config = SH_MEM_ADDRESS_MODE_64 |
SH_MEM_ALIGNMENT_MODE_UNALIGNED <<
SH_MEM_CONFIG__ALIGNMENT_MODE__SHIFT;
mutex_lock(&adev->srbm_mutex);
for (i = FIRST_COMPUTE_VMID; i < LAST_COMPUTE_VMID; i++) {
soc15_grbm_select(adev, 0, 0, 0, i);
WREG32_SOC15(GC, 0, mmSH_MEM_CONFIG, sh_mem_config);
WREG32_SOC15(GC, 0, mmSH_MEM_BASES, sh_mem_bases);
}
soc15_grbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
}
static void gfx_v9_0_gpu_init(struct amdgpu_device *adev)
{
u32 tmp;
int i;
WREG32_FIELD15(GC, 0, GRBM_CNTL, READ_TIMEOUT, 0xff);
gfx_v9_0_tiling_mode_table_init(adev);
gfx_v9_0_setup_rb(adev);
gfx_v9_0_get_cu_info(adev, &adev->gfx.cu_info);
mutex_lock(&adev->srbm_mutex);
for (i = 0; i < 16; i++) {
soc15_grbm_select(adev, 0, 0, 0, i);
tmp = 0;
tmp = REG_SET_FIELD(tmp, SH_MEM_CONFIG, ALIGNMENT_MODE,
SH_MEM_ALIGNMENT_MODE_UNALIGNED);
WREG32_SOC15(GC, 0, mmSH_MEM_CONFIG, tmp);
WREG32_SOC15(GC, 0, mmSH_MEM_BASES, 0);
}
soc15_grbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
gfx_v9_0_init_compute_vmid(adev);
mutex_lock(&adev->grbm_idx_mutex);
gfx_v9_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
WREG32_SOC15(GC, 0, mmPA_SC_FIFO_SIZE,
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
static void gfx_v9_0_wait_for_rlc_serdes(struct amdgpu_device *adev)
{
u32 i, j, k;
u32 mask;
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
gfx_v9_0_select_se_sh(adev, i, j, 0xffffffff);
for (k = 0; k < adev->usec_timeout; k++) {
if (RREG32_SOC15(GC, 0, mmRLC_SERDES_CU_MASTER_BUSY) == 0)
break;
udelay(1);
}
}
}
gfx_v9_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
mask = RLC_SERDES_NONCU_MASTER_BUSY__SE_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__GC_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__TC0_MASTER_BUSY_MASK |
RLC_SERDES_NONCU_MASTER_BUSY__TC1_MASTER_BUSY_MASK;
for (k = 0; k < adev->usec_timeout; k++) {
if ((RREG32_SOC15(GC, 0, mmRLC_SERDES_NONCU_MASTER_BUSY) & mask) == 0)
break;
udelay(1);
}
}
static void gfx_v9_0_enable_gui_idle_interrupt(struct amdgpu_device *adev,
bool enable)
{
u32 tmp = RREG32_SOC15(GC, 0, mmCP_INT_CNTL_RING0);
if (enable)
return;
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_BUSY_INT_ENABLE, enable ? 1 : 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CNTX_EMPTY_INT_ENABLE, enable ? 1 : 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, CMP_BUSY_INT_ENABLE, enable ? 1 : 0);
tmp = REG_SET_FIELD(tmp, CP_INT_CNTL_RING0, GFX_IDLE_INT_ENABLE, enable ? 1 : 0);
WREG32_SOC15(GC, 0, mmCP_INT_CNTL_RING0, tmp);
}
void gfx_v9_0_rlc_stop(struct amdgpu_device *adev)
{
u32 tmp = RREG32_SOC15(GC, 0, mmRLC_CNTL);
tmp = REG_SET_FIELD(tmp, RLC_CNTL, RLC_ENABLE_F32, 0);
WREG32_SOC15(GC, 0, mmRLC_CNTL, tmp);
gfx_v9_0_enable_gui_idle_interrupt(adev, false);
gfx_v9_0_wait_for_rlc_serdes(adev);
}
static void gfx_v9_0_rlc_reset(struct amdgpu_device *adev)
{
WREG32_FIELD15(GC, 0, GRBM_SOFT_RESET, SOFT_RESET_RLC, 1);
udelay(50);
WREG32_FIELD15(GC, 0, GRBM_SOFT_RESET, SOFT_RESET_RLC, 0);
udelay(50);
}
static void gfx_v9_0_rlc_start(struct amdgpu_device *adev)
{
#ifdef AMDGPU_RLC_DEBUG_RETRY
u32 rlc_ucode_ver;
#endif
WREG32_FIELD15(GC, 0, RLC_CNTL, RLC_ENABLE_F32, 1);
if (!(adev->flags & AMD_IS_APU))
gfx_v9_0_enable_gui_idle_interrupt(adev, true);
udelay(50);
#ifdef AMDGPU_RLC_DEBUG_RETRY
rlc_ucode_ver = RREG32_SOC15(GC, 0, mmRLC_GPM_GENERAL_6);
if(rlc_ucode_ver == 0x108) {
DRM_INFO("Using rlc debug ucode. mmRLC_GPM_GENERAL_6 ==0x08%x / fw_ver == %i \n",
rlc_ucode_ver, adev->gfx.rlc_fw_version);
WREG32_SOC15(GC, 0, mmRLC_GPM_TIMER_INT_3, 0x9C4);
WREG32_SOC15(GC, 0, mmRLC_GPM_GENERAL_12, 0x100);
}
#endif
}
static int gfx_v9_0_rlc_load_microcode(struct amdgpu_device *adev)
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
WREG32_SOC15(GC, 0, mmRLC_GPM_UCODE_ADDR,
RLCG_UCODE_LOADING_START_ADDRESS);
for (i = 0; i < fw_size; i++)
WREG32_SOC15(GC, 0, mmRLC_GPM_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32_SOC15(GC, 0, mmRLC_GPM_UCODE_ADDR, adev->gfx.rlc_fw_version);
return 0;
}
static int gfx_v9_0_rlc_resume(struct amdgpu_device *adev)
{
int r;
if (amdgpu_sriov_vf(adev))
return 0;
gfx_v9_0_rlc_stop(adev);
WREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL, 0);
WREG32_SOC15(GC, 0, mmRLC_PG_CNTL, 0);
gfx_v9_0_rlc_reset(adev);
if (adev->firmware.load_type != AMDGPU_FW_LOAD_PSP) {
r = gfx_v9_0_rlc_load_microcode(adev);
if (r)
return r;
}
gfx_v9_0_rlc_start(adev);
return 0;
}
static void gfx_v9_0_cp_gfx_enable(struct amdgpu_device *adev, bool enable)
{
int i;
u32 tmp = RREG32_SOC15(GC, 0, mmCP_ME_CNTL);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, ME_HALT, enable ? 0 : 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, PFP_HALT, enable ? 0 : 1);
tmp = REG_SET_FIELD(tmp, CP_ME_CNTL, CE_HALT, enable ? 0 : 1);
if (!enable) {
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].ready = false;
}
WREG32_SOC15(GC, 0, mmCP_ME_CNTL, tmp);
udelay(50);
}
static int gfx_v9_0_cp_gfx_load_microcode(struct amdgpu_device *adev)
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
gfx_v9_0_cp_gfx_enable(adev, false);
fw_data = (const __le32 *)
(adev->gfx.pfp_fw->data +
le32_to_cpu(pfp_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(pfp_hdr->header.ucode_size_bytes) / 4;
WREG32_SOC15(GC, 0, mmCP_PFP_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32_SOC15(GC, 0, mmCP_PFP_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32_SOC15(GC, 0, mmCP_PFP_UCODE_ADDR, adev->gfx.pfp_fw_version);
fw_data = (const __le32 *)
(adev->gfx.ce_fw->data +
le32_to_cpu(ce_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(ce_hdr->header.ucode_size_bytes) / 4;
WREG32_SOC15(GC, 0, mmCP_CE_UCODE_ADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32_SOC15(GC, 0, mmCP_CE_UCODE_DATA, le32_to_cpup(fw_data++));
WREG32_SOC15(GC, 0, mmCP_CE_UCODE_ADDR, adev->gfx.ce_fw_version);
fw_data = (const __le32 *)
(adev->gfx.me_fw->data +
le32_to_cpu(me_hdr->header.ucode_array_offset_bytes));
fw_size = le32_to_cpu(me_hdr->header.ucode_size_bytes) / 4;
WREG32_SOC15(GC, 0, mmCP_ME_RAM_WADDR, 0);
for (i = 0; i < fw_size; i++)
WREG32_SOC15(GC, 0, mmCP_ME_RAM_DATA, le32_to_cpup(fw_data++));
WREG32_SOC15(GC, 0, mmCP_ME_RAM_WADDR, adev->gfx.me_fw_version);
return 0;
}
static u32 gfx_v9_0_get_csb_size(struct amdgpu_device *adev)
{
u32 count = 0;
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
count += 2;
count += 3;
for (sect = gfx9_cs_data; sect->section != NULL; ++sect) {
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
static int gfx_v9_0_cp_gfx_start(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = &adev->gfx.gfx_ring[0];
const struct cs_section_def *sect = NULL;
const struct cs_extent_def *ext = NULL;
int r, i;
WREG32_SOC15(GC, 0, mmCP_MAX_CONTEXT, adev->gfx.config.max_hw_contexts - 1);
WREG32_SOC15(GC, 0, mmCP_DEVICE_ID, 1);
gfx_v9_0_cp_gfx_enable(adev, true);
r = amdgpu_ring_alloc(ring, gfx_v9_0_get_csb_size(adev) + 4);
if (r) {
DRM_ERROR("amdgpu: cp failed to lock ring (%d).\n", r);
return r;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_BEGIN_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CONTEXT_CONTROL, 1));
amdgpu_ring_write(ring, 0x80000000);
amdgpu_ring_write(ring, 0x80000000);
for (sect = gfx9_cs_data; sect->section != NULL; ++sect) {
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
amdgpu_ring_write(ring, PACKET3(PACKET3_PREAMBLE_CNTL, 0));
amdgpu_ring_write(ring, PACKET3_PREAMBLE_END_CLEAR_STATE);
amdgpu_ring_write(ring, PACKET3(PACKET3_CLEAR_STATE, 0));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_BASE, 2));
amdgpu_ring_write(ring, PACKET3_BASE_INDEX(CE_PARTITION_BASE));
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_write(ring, 0x8000);
amdgpu_ring_commit(ring);
return 0;
}
static int gfx_v9_0_cp_gfx_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring;
u32 tmp;
u32 rb_bufsz;
u64 rb_addr, rptr_addr, wptr_gpu_addr;
WREG32_SOC15(GC, 0, mmCP_RB_WPTR_DELAY, 0);
WREG32_SOC15(GC, 0, mmCP_RB_VMID, 0);
ring = &adev->gfx.gfx_ring[0];
rb_bufsz = order_base_2(ring->ring_size / 8);
tmp = REG_SET_FIELD(0, CP_RB0_CNTL, RB_BUFSZ, rb_bufsz);
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, RB_BLKSZ, rb_bufsz - 2);
#ifdef __BIG_ENDIAN
tmp = REG_SET_FIELD(tmp, CP_RB0_CNTL, BUF_SWAP, 1);
#endif
WREG32_SOC15(GC, 0, mmCP_RB0_CNTL, tmp);
ring->wptr = 0;
WREG32_SOC15(GC, 0, mmCP_RB0_WPTR, lower_32_bits(ring->wptr));
WREG32_SOC15(GC, 0, mmCP_RB0_WPTR_HI, upper_32_bits(ring->wptr));
rptr_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
WREG32_SOC15(GC, 0, mmCP_RB0_RPTR_ADDR, lower_32_bits(rptr_addr));
WREG32_SOC15(GC, 0, mmCP_RB0_RPTR_ADDR_HI, upper_32_bits(rptr_addr) & CP_RB_RPTR_ADDR_HI__RB_RPTR_ADDR_HI_MASK);
wptr_gpu_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
WREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_ADDR_LO, lower_32_bits(wptr_gpu_addr));
WREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_ADDR_HI, upper_32_bits(wptr_gpu_addr));
mdelay(1);
WREG32_SOC15(GC, 0, mmCP_RB0_CNTL, tmp);
rb_addr = ring->gpu_addr >> 8;
WREG32_SOC15(GC, 0, mmCP_RB0_BASE, rb_addr);
WREG32_SOC15(GC, 0, mmCP_RB0_BASE_HI, upper_32_bits(rb_addr));
tmp = RREG32_SOC15(GC, 0, mmCP_RB_DOORBELL_CONTROL);
if (ring->use_doorbell) {
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL,
DOORBELL_EN, 1);
} else {
tmp = REG_SET_FIELD(tmp, CP_RB_DOORBELL_CONTROL, DOORBELL_EN, 0);
}
WREG32_SOC15(GC, 0, mmCP_RB_DOORBELL_CONTROL, tmp);
tmp = REG_SET_FIELD(0, CP_RB_DOORBELL_RANGE_LOWER,
DOORBELL_RANGE_LOWER, ring->doorbell_index);
WREG32_SOC15(GC, 0, mmCP_RB_DOORBELL_RANGE_LOWER, tmp);
WREG32_SOC15(GC, 0, mmCP_RB_DOORBELL_RANGE_UPPER,
CP_RB_DOORBELL_RANGE_UPPER__DOORBELL_RANGE_UPPER_MASK);
gfx_v9_0_cp_gfx_start(adev);
ring->ready = true;
return 0;
}
static void gfx_v9_0_cp_compute_enable(struct amdgpu_device *adev, bool enable)
{
int i;
if (enable) {
WREG32_SOC15(GC, 0, mmCP_MEC_CNTL, 0);
} else {
WREG32_SOC15(GC, 0, mmCP_MEC_CNTL,
(CP_MEC_CNTL__MEC_ME1_HALT_MASK | CP_MEC_CNTL__MEC_ME2_HALT_MASK));
for (i = 0; i < adev->gfx.num_compute_rings; i++)
adev->gfx.compute_ring[i].ready = false;
adev->gfx.kiq.ring.ready = false;
}
udelay(50);
}
static int gfx_v9_0_cp_compute_start(struct amdgpu_device *adev)
{
gfx_v9_0_cp_compute_enable(adev, true);
return 0;
}
static int gfx_v9_0_cp_compute_load_microcode(struct amdgpu_device *adev)
{
const struct gfx_firmware_header_v1_0 *mec_hdr;
const __le32 *fw_data;
unsigned i;
u32 tmp;
if (!adev->gfx.mec_fw)
return -EINVAL;
gfx_v9_0_cp_compute_enable(adev, false);
mec_hdr = (const struct gfx_firmware_header_v1_0 *)adev->gfx.mec_fw->data;
amdgpu_ucode_print_gfx_hdr(&mec_hdr->header);
fw_data = (const __le32 *)
(adev->gfx.mec_fw->data +
le32_to_cpu(mec_hdr->header.ucode_array_offset_bytes));
tmp = 0;
tmp = REG_SET_FIELD(tmp, CP_CPC_IC_BASE_CNTL, VMID, 0);
tmp = REG_SET_FIELD(tmp, CP_CPC_IC_BASE_CNTL, CACHE_POLICY, 0);
WREG32_SOC15(GC, 0, mmCP_CPC_IC_BASE_CNTL, tmp);
WREG32_SOC15(GC, 0, mmCP_CPC_IC_BASE_LO,
adev->gfx.mec.mec_fw_gpu_addr & 0xFFFFF000);
WREG32_SOC15(GC, 0, mmCP_CPC_IC_BASE_HI,
upper_32_bits(adev->gfx.mec.mec_fw_gpu_addr));
WREG32_SOC15(GC, 0, mmCP_MEC_ME1_UCODE_ADDR,
mec_hdr->jt_offset);
for (i = 0; i < mec_hdr->jt_size; i++)
WREG32_SOC15(GC, 0, mmCP_MEC_ME1_UCODE_DATA,
le32_to_cpup(fw_data + mec_hdr->jt_offset + i));
WREG32_SOC15(GC, 0, mmCP_MEC_ME1_UCODE_ADDR,
adev->gfx.mec_fw_version);
return 0;
}
static void gfx_v9_0_cp_compute_fini(struct amdgpu_device *adev)
{
int i, r;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
struct amdgpu_ring *ring = &adev->gfx.compute_ring[i];
if (ring->mqd_obj) {
r = amdgpu_bo_reserve(ring->mqd_obj, true);
if (unlikely(r != 0))
dev_warn(adev->dev, "(%d) reserve MQD bo failed\n", r);
amdgpu_bo_unpin(ring->mqd_obj);
amdgpu_bo_unreserve(ring->mqd_obj);
amdgpu_bo_unref(&ring->mqd_obj);
ring->mqd_obj = NULL;
}
}
}
static int gfx_v9_0_cp_compute_resume(struct amdgpu_device *adev)
{
int i, r;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
struct amdgpu_ring *ring = &adev->gfx.compute_ring[i];
if (gfx_v9_0_init_queue(ring))
dev_warn(adev->dev, "compute queue %d init failed!\n", i);
}
r = gfx_v9_0_cp_compute_start(adev);
if (r)
return r;
return 0;
}
static void gfx_v9_0_kiq_setting(struct amdgpu_ring *ring)
{
uint32_t tmp;
struct amdgpu_device *adev = ring->adev;
tmp = RREG32_SOC15(GC, 0, mmRLC_CP_SCHEDULERS);
tmp &= 0xffffff00;
tmp |= (ring->me << 5) | (ring->pipe << 3) | (ring->queue);
WREG32_SOC15(GC, 0, mmRLC_CP_SCHEDULERS, tmp);
tmp |= 0x80;
WREG32_SOC15(GC, 0, mmRLC_CP_SCHEDULERS, tmp);
}
static void gfx_v9_0_kiq_enable(struct amdgpu_ring *ring)
{
amdgpu_ring_alloc(ring, 8);
amdgpu_ring_write(ring, PACKET3(PACKET3_SET_RESOURCES, 6));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0x000000FF);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0);
amdgpu_ring_commit(ring);
udelay(50);
}
static void gfx_v9_0_map_queue_enable(struct amdgpu_ring *kiq_ring,
struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = kiq_ring->adev;
uint64_t mqd_addr, wptr_addr;
mqd_addr = amdgpu_bo_gpu_offset(ring->mqd_obj);
wptr_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
amdgpu_ring_alloc(kiq_ring, 8);
amdgpu_ring_write(kiq_ring, PACKET3(PACKET3_MAP_QUEUES, 5));
amdgpu_ring_write(kiq_ring,
(0 << 4) |
(0 << 8) |
(ring->queue << 13 ) |
(ring->pipe << 16) |
((ring->me == 1 ? 0 : 1) << 18) |
(0 << 21) |
(1 << 24) |
(0 << 26) |
(1 << 29));
amdgpu_ring_write(kiq_ring, (ring->doorbell_index << 2));
amdgpu_ring_write(kiq_ring, lower_32_bits(mqd_addr));
amdgpu_ring_write(kiq_ring, upper_32_bits(mqd_addr));
amdgpu_ring_write(kiq_ring, lower_32_bits(wptr_addr));
amdgpu_ring_write(kiq_ring, upper_32_bits(wptr_addr));
amdgpu_ring_commit(kiq_ring);
udelay(50);
}
static int gfx_v9_0_mqd_init(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
struct v9_mqd *mqd = ring->mqd_ptr;
uint64_t hqd_gpu_addr, wb_gpu_addr, eop_base_addr;
uint32_t tmp;
mqd->header = 0xC0310800;
mqd->compute_pipelinestat_enable = 0x00000001;
mqd->compute_static_thread_mgmt_se0 = 0xffffffff;
mqd->compute_static_thread_mgmt_se1 = 0xffffffff;
mqd->compute_static_thread_mgmt_se2 = 0xffffffff;
mqd->compute_static_thread_mgmt_se3 = 0xffffffff;
mqd->compute_misc_reserved = 0x00000003;
eop_base_addr = ring->eop_gpu_addr >> 8;
mqd->cp_hqd_eop_base_addr_lo = eop_base_addr;
mqd->cp_hqd_eop_base_addr_hi = upper_32_bits(eop_base_addr);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_EOP_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_EOP_CONTROL, EOP_SIZE,
(order_base_2(MEC_HPD_SIZE / 4) - 1));
mqd->cp_hqd_eop_control = tmp;
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL);
if (ring->use_doorbell) {
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_EN, 1);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_SOURCE, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_HIT, 0);
}
else
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_EN, 0);
mqd->cp_hqd_pq_doorbell_control = tmp;
ring->wptr = 0;
mqd->cp_hqd_dequeue_request = 0;
mqd->cp_hqd_pq_rptr = 0;
mqd->cp_hqd_pq_wptr_lo = 0;
mqd->cp_hqd_pq_wptr_hi = 0;
mqd->cp_mqd_base_addr_lo = ring->mqd_gpu_addr & 0xfffffffc;
mqd->cp_mqd_base_addr_hi = upper_32_bits(ring->mqd_gpu_addr);
tmp = RREG32_SOC15(GC, 0, mmCP_MQD_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_MQD_CONTROL, VMID, 0);
mqd->cp_mqd_control = tmp;
hqd_gpu_addr = ring->gpu_addr >> 8;
mqd->cp_hqd_pq_base_lo = hqd_gpu_addr;
mqd->cp_hqd_pq_base_hi = upper_32_bits(hqd_gpu_addr);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_CONTROL);
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
mqd->cp_hqd_pq_control = tmp;
wb_gpu_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
mqd->cp_hqd_pq_rptr_report_addr_lo = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_rptr_report_addr_hi =
upper_32_bits(wb_gpu_addr) & 0xffff;
wb_gpu_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
mqd->cp_hqd_pq_wptr_poll_addr_lo = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_wptr_poll_addr_hi = upper_32_bits(wb_gpu_addr) & 0xffff;
tmp = 0;
if (ring->use_doorbell) {
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_EN, 1);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_SOURCE, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_HIT, 0);
}
mqd->cp_hqd_pq_doorbell_control = tmp;
ring->wptr = 0;
mqd->cp_hqd_pq_rptr = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR);
mqd->cp_hqd_vmid = 0;
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PERSISTENT_STATE);
tmp = REG_SET_FIELD(tmp, CP_HQD_PERSISTENT_STATE, PRELOAD_SIZE, 0x53);
mqd->cp_hqd_persistent_state = tmp;
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_IB_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_IB_CONTROL, MIN_IB_AVAIL_SIZE, 3);
mqd->cp_hqd_ib_control = tmp;
mqd->cp_hqd_active = 1;
return 0;
}
static int gfx_v9_0_kiq_init_register(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
struct v9_mqd *mqd = ring->mqd_ptr;
int j;
WREG32_FIELD15(GC, 0, CP_PQ_WPTR_POLL_CNTL, EN, 0);
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_BASE_ADDR,
mqd->cp_hqd_eop_base_addr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_BASE_ADDR_HI,
mqd->cp_hqd_eop_base_addr_hi);
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_CONTROL,
mqd->cp_hqd_eop_control);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->cp_hqd_pq_doorbell_control);
if (RREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE) & 1) {
WREG32_SOC15(GC, 0, mmCP_HQD_DEQUEUE_REQUEST, 1);
for (j = 0; j < adev->usec_timeout; j++) {
if (!(RREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE) & 1))
break;
udelay(1);
}
WREG32_SOC15(GC, 0, mmCP_HQD_DEQUEUE_REQUEST,
mqd->cp_hqd_dequeue_request);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR,
mqd->cp_hqd_pq_rptr);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_LO,
mqd->cp_hqd_pq_wptr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_HI,
mqd->cp_hqd_pq_wptr_hi);
}
WREG32_SOC15(GC, 0, mmCP_MQD_BASE_ADDR,
mqd->cp_mqd_base_addr_lo);
WREG32_SOC15(GC, 0, mmCP_MQD_BASE_ADDR_HI,
mqd->cp_mqd_base_addr_hi);
WREG32_SOC15(GC, 0, mmCP_MQD_CONTROL,
mqd->cp_mqd_control);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_BASE,
mqd->cp_hqd_pq_base_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_BASE_HI,
mqd->cp_hqd_pq_base_hi);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_CONTROL,
mqd->cp_hqd_pq_control);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR_REPORT_ADDR,
mqd->cp_hqd_pq_rptr_report_addr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR_REPORT_ADDR_HI,
mqd->cp_hqd_pq_rptr_report_addr_hi);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_POLL_ADDR,
mqd->cp_hqd_pq_wptr_poll_addr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_POLL_ADDR_HI,
mqd->cp_hqd_pq_wptr_poll_addr_hi);
if (ring->use_doorbell) {
WREG32_SOC15(GC, 0, mmCP_MEC_DOORBELL_RANGE_LOWER,
(AMDGPU_DOORBELL64_KIQ *2) << 2);
WREG32_SOC15(GC, 0, mmCP_MEC_DOORBELL_RANGE_UPPER,
(AMDGPU_DOORBELL64_USERQUEUE_END * 2) << 2);
}
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->cp_hqd_pq_doorbell_control);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_LO,
mqd->cp_hqd_pq_wptr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_HI,
mqd->cp_hqd_pq_wptr_hi);
WREG32_SOC15(GC, 0, mmCP_HQD_VMID, mqd->cp_hqd_vmid);
WREG32_SOC15(GC, 0, mmCP_HQD_PERSISTENT_STATE,
mqd->cp_hqd_persistent_state);
WREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE,
mqd->cp_hqd_active);
if (ring->use_doorbell)
WREG32_FIELD15(GC, 0, CP_PQ_STATUS, DOORBELL_ENABLE, 1);
return 0;
}
static int gfx_v9_0_kiq_init_queue(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
struct v9_mqd *mqd = ring->mqd_ptr;
bool is_kiq = (ring->funcs->type == AMDGPU_RING_TYPE_KIQ);
int mqd_idx = AMDGPU_MAX_COMPUTE_RINGS;
if (is_kiq) {
gfx_v9_0_kiq_setting(&kiq->ring);
} else {
mqd_idx = ring - &adev->gfx.compute_ring[0];
}
if (!adev->gfx.in_reset) {
memset((void *)mqd, 0, sizeof(*mqd));
mutex_lock(&adev->srbm_mutex);
soc15_grbm_select(adev, ring->me, ring->pipe, ring->queue, 0);
gfx_v9_0_mqd_init(ring);
if (is_kiq)
gfx_v9_0_kiq_init_register(ring);
soc15_grbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
} else {
ring->wptr = 0;
if (is_kiq) {
mutex_lock(&adev->srbm_mutex);
soc15_grbm_select(adev, ring->me, ring->pipe, ring->queue, 0);
gfx_v9_0_kiq_init_register(ring);
soc15_grbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
}
}
if (is_kiq)
gfx_v9_0_kiq_enable(ring);
else
gfx_v9_0_map_queue_enable(&kiq->ring, ring);
return 0;
}
static int gfx_v9_0_kiq_resume(struct amdgpu_device *adev)
{
struct amdgpu_ring *ring = NULL;
int r = 0, i;
gfx_v9_0_cp_compute_enable(adev, true);
ring = &adev->gfx.kiq.ring;
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0))
goto done;
r = amdgpu_bo_kmap(ring->mqd_obj, (void **)&ring->mqd_ptr);
if (!r) {
r = gfx_v9_0_kiq_init_queue(ring);
amdgpu_bo_kunmap(ring->mqd_obj);
ring->mqd_ptr = NULL;
}
amdgpu_bo_unreserve(ring->mqd_obj);
if (r)
goto done;
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0))
goto done;
r = amdgpu_bo_kmap(ring->mqd_obj, (void **)&ring->mqd_ptr);
if (!r) {
r = gfx_v9_0_kiq_init_queue(ring);
amdgpu_bo_kunmap(ring->mqd_obj);
ring->mqd_ptr = NULL;
}
amdgpu_bo_unreserve(ring->mqd_obj);
if (r)
goto done;
}
done:
return r;
}
static int gfx_v9_0_cp_resume(struct amdgpu_device *adev)
{
int r,i;
struct amdgpu_ring *ring;
if (!(adev->flags & AMD_IS_APU))
gfx_v9_0_enable_gui_idle_interrupt(adev, false);
if (adev->firmware.load_type != AMDGPU_FW_LOAD_PSP) {
r = gfx_v9_0_cp_gfx_load_microcode(adev);
if (r)
return r;
r = gfx_v9_0_cp_compute_load_microcode(adev);
if (r)
return r;
}
r = gfx_v9_0_cp_gfx_resume(adev);
if (r)
return r;
if (amdgpu_sriov_vf(adev))
r = gfx_v9_0_kiq_resume(adev);
else
r = gfx_v9_0_cp_compute_resume(adev);
if (r)
return r;
ring = &adev->gfx.gfx_ring[0];
r = amdgpu_ring_test_ring(ring);
if (r) {
ring->ready = false;
return r;
}
for (i = 0; i < adev->gfx.num_compute_rings; i++) {
ring = &adev->gfx.compute_ring[i];
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r)
ring->ready = false;
}
if (amdgpu_sriov_vf(adev)) {
ring = &adev->gfx.kiq.ring;
ring->ready = true;
r = amdgpu_ring_test_ring(ring);
if (r)
ring->ready = false;
}
gfx_v9_0_enable_gui_idle_interrupt(adev, true);
return 0;
}
static void gfx_v9_0_cp_enable(struct amdgpu_device *adev, bool enable)
{
gfx_v9_0_cp_gfx_enable(adev, enable);
gfx_v9_0_cp_compute_enable(adev, enable);
}
static int gfx_v9_0_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
gfx_v9_0_init_golden_registers(adev);
gfx_v9_0_gpu_init(adev);
r = gfx_v9_0_rlc_resume(adev);
if (r)
return r;
r = gfx_v9_0_cp_resume(adev);
if (r)
return r;
r = gfx_v9_0_ngg_en(adev);
if (r)
return r;
return r;
}
static int gfx_v9_0_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_irq_put(adev, &adev->gfx.priv_reg_irq, 0);
amdgpu_irq_put(adev, &adev->gfx.priv_inst_irq, 0);
if (amdgpu_sriov_vf(adev)) {
pr_debug("For SRIOV client, shouldn't do anything.\n");
return 0;
}
gfx_v9_0_cp_enable(adev, false);
gfx_v9_0_rlc_stop(adev);
gfx_v9_0_cp_compute_fini(adev);
return 0;
}
static int gfx_v9_0_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v9_0_hw_fini(adev);
}
static int gfx_v9_0_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return gfx_v9_0_hw_init(adev);
}
static bool gfx_v9_0_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (REG_GET_FIELD(RREG32_SOC15(GC, 0, mmGRBM_STATUS),
GRBM_STATUS, GUI_ACTIVE))
return false;
else
return true;
}
static int gfx_v9_0_wait_for_idle(void *handle)
{
unsigned i;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32_SOC15(GC, 0, mmGRBM_STATUS) &
GRBM_STATUS__GUI_ACTIVE_MASK;
if (!REG_GET_FIELD(tmp, GRBM_STATUS, GUI_ACTIVE))
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int gfx_v9_0_soft_reset(void *handle)
{
u32 grbm_soft_reset = 0;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
tmp = RREG32_SOC15(GC, 0, mmGRBM_STATUS);
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
}
tmp = RREG32_SOC15(GC, 0, mmGRBM_STATUS2);
if (REG_GET_FIELD(tmp, GRBM_STATUS2, RLC_BUSY))
grbm_soft_reset = REG_SET_FIELD(grbm_soft_reset,
GRBM_SOFT_RESET, SOFT_RESET_RLC, 1);
if (grbm_soft_reset) {
gfx_v9_0_rlc_stop(adev);
gfx_v9_0_cp_gfx_enable(adev, false);
gfx_v9_0_cp_compute_enable(adev, false);
if (grbm_soft_reset) {
tmp = RREG32_SOC15(GC, 0, mmGRBM_SOFT_RESET);
tmp |= grbm_soft_reset;
dev_info(adev->dev, "GRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32_SOC15(GC, 0, mmGRBM_SOFT_RESET, tmp);
tmp = RREG32_SOC15(GC, 0, mmGRBM_SOFT_RESET);
udelay(50);
tmp &= ~grbm_soft_reset;
WREG32_SOC15(GC, 0, mmGRBM_SOFT_RESET, tmp);
tmp = RREG32_SOC15(GC, 0, mmGRBM_SOFT_RESET);
}
udelay(50);
}
return 0;
}
static uint64_t gfx_v9_0_get_gpu_clock_counter(struct amdgpu_device *adev)
{
uint64_t clock;
mutex_lock(&adev->gfx.gpu_clock_mutex);
WREG32_SOC15(GC, 0, mmRLC_CAPTURE_GPU_CLOCK_COUNT, 1);
clock = (uint64_t)RREG32_SOC15(GC, 0, mmRLC_GPU_CLOCK_COUNT_LSB) |
((uint64_t)RREG32_SOC15(GC, 0, mmRLC_GPU_CLOCK_COUNT_MSB) << 32ULL);
mutex_unlock(&adev->gfx.gpu_clock_mutex);
return clock;
}
static void gfx_v9_0_ring_emit_gds_switch(struct amdgpu_ring *ring,
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
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[vmid].mem_base,
gds_base);
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[vmid].mem_size,
gds_size);
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[vmid].gws,
gws_size << GDS_GWS_VMID0__SIZE__SHIFT | gws_base);
gfx_v9_0_write_data_to_reg(ring, 0, false,
amdgpu_gds_reg_offset[vmid].oa,
(1 << (oa_size + oa_base)) - (1 << oa_base));
}
static int gfx_v9_0_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
adev->gfx.num_gfx_rings = GFX9_NUM_GFX_RINGS;
adev->gfx.num_compute_rings = GFX9_NUM_COMPUTE_RINGS;
gfx_v9_0_set_ring_funcs(adev);
gfx_v9_0_set_irq_funcs(adev);
gfx_v9_0_set_gds_init(adev);
gfx_v9_0_set_rlc_funcs(adev);
return 0;
}
static int gfx_v9_0_late_init(void *handle)
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
static void gfx_v9_0_enter_rlc_safe_mode(struct amdgpu_device *adev)
{
uint32_t rlc_setting, data;
unsigned i;
if (adev->gfx.rlc.in_safe_mode)
return;
rlc_setting = RREG32_SOC15(GC, 0, mmRLC_CNTL);
if (!(rlc_setting & RLC_CNTL__RLC_ENABLE_F32_MASK))
return;
if (adev->cg_flags &
(AMD_CG_SUPPORT_GFX_CGCG | AMD_CG_SUPPORT_GFX_MGCG |
AMD_CG_SUPPORT_GFX_3D_CGCG)) {
data = RLC_SAFE_MODE__CMD_MASK;
data |= (1 << RLC_SAFE_MODE__MESSAGE__SHIFT);
WREG32_SOC15(GC, 0, mmRLC_SAFE_MODE, data);
for (i = 0; i < adev->usec_timeout; i++) {
if (!REG_GET_FIELD(SOC15_REG_OFFSET(GC, 0, mmRLC_SAFE_MODE), RLC_SAFE_MODE, CMD))
break;
udelay(1);
}
adev->gfx.rlc.in_safe_mode = true;
}
}
static void gfx_v9_0_exit_rlc_safe_mode(struct amdgpu_device *adev)
{
uint32_t rlc_setting, data;
if (!adev->gfx.rlc.in_safe_mode)
return;
rlc_setting = RREG32_SOC15(GC, 0, mmRLC_CNTL);
if (!(rlc_setting & RLC_CNTL__RLC_ENABLE_F32_MASK))
return;
if (adev->cg_flags &
(AMD_CG_SUPPORT_GFX_CGCG | AMD_CG_SUPPORT_GFX_MGCG)) {
data = RLC_SAFE_MODE__CMD_MASK;
WREG32_SOC15(GC, 0, mmRLC_SAFE_MODE, data);
adev->gfx.rlc.in_safe_mode = false;
}
}
static void gfx_v9_0_update_medium_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t data, def;
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_GFX_MGCG)) {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE);
data &= ~(RLC_CGTT_MGCG_OVERRIDE__CPF_CGTT_SCLK_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GRBM_CGTT_SCLK_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GFXIP_MGCG_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GFXIP_MGLS_OVERRIDE_MASK);
data |= RLC_CGTT_MGCG_OVERRIDE__RLC_CGTT_SCLK_OVERRIDE_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE, data);
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_MGLS) {
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_RLC_LS) {
def = data = RREG32_SOC15(GC, 0, mmRLC_MEM_SLP_CNTL);
data |= RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_MEM_SLP_CNTL, data);
}
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_CP_LS) {
def = data = RREG32_SOC15(GC, 0, mmCP_MEM_SLP_CNTL);
data |= CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmCP_MEM_SLP_CNTL, data);
}
}
} else {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE);
data |= (RLC_CGTT_MGCG_OVERRIDE__CPF_CGTT_SCLK_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__RLC_CGTT_SCLK_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GRBM_CGTT_SCLK_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GFXIP_MGCG_OVERRIDE_MASK |
RLC_CGTT_MGCG_OVERRIDE__GFXIP_MGLS_OVERRIDE_MASK);
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE, data);
data = RREG32_SOC15(GC, 0, mmRLC_MEM_SLP_CNTL);
if (data & RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK) {
data &= ~RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK;
WREG32_SOC15(GC, 0, mmRLC_MEM_SLP_CNTL, data);
}
data = RREG32_SOC15(GC, 0, mmCP_MEM_SLP_CNTL);
if (data & CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK) {
data &= ~CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK;
WREG32_SOC15(GC, 0, mmCP_MEM_SLP_CNTL, data);
}
}
}
static void gfx_v9_0_update_3d_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t data, def;
adev->gfx.rlc.funcs->enter_safe_mode(adev);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_GFX_3D_CGCG)) {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE);
data &= ~RLC_CGTT_MGCG_OVERRIDE__GFXIP_GFX3D_CG_OVERRIDE_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE, data);
def = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL_3D);
data = (0x2000 << RLC_CGCG_CGLS_CTRL_3D__CGCG_GFX_IDLE_THRESHOLD__SHIFT) |
RLC_CGCG_CGLS_CTRL_3D__CGCG_EN_MASK;
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_3D_CGLS)
data |= (0x000F << RLC_CGCG_CGLS_CTRL_3D__CGLS_REP_COMPANSAT_DELAY__SHIFT) |
RLC_CGCG_CGLS_CTRL_3D__CGLS_EN_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL_3D, data);
def = RREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_CNTL);
data = (0x0100 << CP_RB_WPTR_POLL_CNTL__POLL_FREQUENCY__SHIFT) |
(0x0090 << CP_RB_WPTR_POLL_CNTL__IDLE_POLL_COUNT__SHIFT);
if (def != data)
WREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_CNTL, data);
} else {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL_3D);
data &= ~(RLC_CGCG_CGLS_CTRL_3D__CGCG_EN_MASK |
RLC_CGCG_CGLS_CTRL_3D__CGLS_EN_MASK);
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL_3D, data);
}
adev->gfx.rlc.funcs->exit_safe_mode(adev);
}
static void gfx_v9_0_update_coarse_grain_clock_gating(struct amdgpu_device *adev,
bool enable)
{
uint32_t def, data;
adev->gfx.rlc.funcs->enter_safe_mode(adev);
if (enable && (adev->cg_flags & AMD_CG_SUPPORT_GFX_CGCG)) {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE);
data &= ~RLC_CGTT_MGCG_OVERRIDE__GFXIP_CGCG_OVERRIDE_MASK;
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_CGLS)
data &= ~RLC_CGTT_MGCG_OVERRIDE__GFXIP_CGLS_OVERRIDE_MASK;
else
data |= RLC_CGTT_MGCG_OVERRIDE__GFXIP_CGLS_OVERRIDE_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE, data);
def = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL);
data = (0x2000 << RLC_CGCG_CGLS_CTRL__CGCG_GFX_IDLE_THRESHOLD__SHIFT) |
RLC_CGCG_CGLS_CTRL__CGCG_EN_MASK;
if (adev->cg_flags & AMD_CG_SUPPORT_GFX_CGLS)
data |= (0x000F << RLC_CGCG_CGLS_CTRL__CGLS_REP_COMPANSAT_DELAY__SHIFT) |
RLC_CGCG_CGLS_CTRL__CGLS_EN_MASK;
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL, data);
def = RREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_CNTL);
data = (0x0100 << CP_RB_WPTR_POLL_CNTL__POLL_FREQUENCY__SHIFT) |
(0x0090 << CP_RB_WPTR_POLL_CNTL__IDLE_POLL_COUNT__SHIFT);
if (def != data)
WREG32_SOC15(GC, 0, mmCP_RB_WPTR_POLL_CNTL, data);
} else {
def = data = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL);
data &= ~(RLC_CGCG_CGLS_CTRL__CGCG_EN_MASK | RLC_CGCG_CGLS_CTRL__CGLS_EN_MASK);
if (def != data)
WREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL, data);
}
adev->gfx.rlc.funcs->exit_safe_mode(adev);
}
static int gfx_v9_0_update_gfx_clock_gating(struct amdgpu_device *adev,
bool enable)
{
if (enable) {
gfx_v9_0_update_medium_grain_clock_gating(adev, enable);
gfx_v9_0_update_3d_clock_gating(adev, enable);
gfx_v9_0_update_coarse_grain_clock_gating(adev, enable);
} else {
gfx_v9_0_update_coarse_grain_clock_gating(adev, enable);
gfx_v9_0_update_3d_clock_gating(adev, enable);
gfx_v9_0_update_medium_grain_clock_gating(adev, enable);
}
return 0;
}
static int gfx_v9_0_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static int gfx_v9_0_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
if (amdgpu_sriov_vf(adev))
return 0;
switch (adev->asic_type) {
case CHIP_VEGA10:
gfx_v9_0_update_gfx_clock_gating(adev,
state == AMD_CG_STATE_GATE ? true : false);
break;
default:
break;
}
return 0;
}
static void gfx_v9_0_get_clockgating_state(void *handle, u32 *flags)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
int data;
if (amdgpu_sriov_vf(adev))
*flags = 0;
data = RREG32_SOC15(GC, 0, mmRLC_CGTT_MGCG_OVERRIDE);
if (!(data & RLC_CGTT_MGCG_OVERRIDE__GFXIP_MGCG_OVERRIDE_MASK))
*flags |= AMD_CG_SUPPORT_GFX_MGCG;
data = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL);
if (data & RLC_CGCG_CGLS_CTRL__CGCG_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_CGCG;
if (data & RLC_CGCG_CGLS_CTRL__CGLS_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_CGLS;
data = RREG32_SOC15(GC, 0, mmRLC_MEM_SLP_CNTL);
if (data & RLC_MEM_SLP_CNTL__RLC_MEM_LS_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_RLC_LS | AMD_CG_SUPPORT_GFX_MGLS;
data = RREG32_SOC15(GC, 0, mmCP_MEM_SLP_CNTL);
if (data & CP_MEM_SLP_CNTL__CP_MEM_LS_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_CP_LS | AMD_CG_SUPPORT_GFX_MGLS;
data = RREG32_SOC15(GC, 0, mmRLC_CGCG_CGLS_CTRL_3D);
if (data & RLC_CGCG_CGLS_CTRL_3D__CGCG_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_3D_CGCG;
if (data & RLC_CGCG_CGLS_CTRL_3D__CGLS_EN_MASK)
*flags |= AMD_CG_SUPPORT_GFX_3D_CGLS;
}
static u64 gfx_v9_0_ring_get_rptr_gfx(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs];
}
static u64 gfx_v9_0_ring_get_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
u64 wptr;
if (ring->use_doorbell) {
wptr = atomic64_read((atomic64_t *)&adev->wb.wb[ring->wptr_offs]);
} else {
wptr = RREG32_SOC15(GC, 0, mmCP_RB0_WPTR);
wptr += (u64)RREG32_SOC15(GC, 0, mmCP_RB0_WPTR_HI) << 32;
}
return wptr;
}
static void gfx_v9_0_ring_set_wptr_gfx(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring->use_doorbell) {
atomic64_set((atomic64_t*)&adev->wb.wb[ring->wptr_offs], ring->wptr);
WDOORBELL64(ring->doorbell_index, ring->wptr);
} else {
WREG32_SOC15(GC, 0, mmCP_RB0_WPTR, lower_32_bits(ring->wptr));
WREG32_SOC15(GC, 0, mmCP_RB0_WPTR_HI, upper_32_bits(ring->wptr));
}
}
static void gfx_v9_0_ring_emit_hdp_flush(struct amdgpu_ring *ring)
{
u32 ref_and_mask, reg_mem_engine;
struct nbio_hdp_flush_reg *nbio_hf_reg;
if (ring->adev->asic_type == CHIP_VEGA10)
nbio_hf_reg = &nbio_v6_1_hdp_flush_reg;
if (ring->funcs->type == AMDGPU_RING_TYPE_COMPUTE) {
switch (ring->me) {
case 1:
ref_and_mask = nbio_hf_reg->ref_and_mask_cp2 << ring->pipe;
break;
case 2:
ref_and_mask = nbio_hf_reg->ref_and_mask_cp6 << ring->pipe;
break;
default:
return;
}
reg_mem_engine = 0;
} else {
ref_and_mask = nbio_hf_reg->ref_and_mask_cp0;
reg_mem_engine = 1;
}
gfx_v9_0_wait_reg_mem(ring, reg_mem_engine, 0, 1,
nbio_hf_reg->hdp_flush_req_offset,
nbio_hf_reg->hdp_flush_done_offset,
ref_and_mask, ref_and_mask, 0x20);
}
static void gfx_v9_0_ring_emit_hdp_invalidate(struct amdgpu_ring *ring)
{
gfx_v9_0_write_data_to_reg(ring, 0, true,
SOC15_REG_OFFSET(HDP, 0, mmHDP_DEBUG0), 1);
}
static void gfx_v9_0_ring_emit_ib_gfx(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 header, control = 0;
if (ib->flags & AMDGPU_IB_FLAG_CE)
header = PACKET3(PACKET3_INDIRECT_BUFFER_CONST, 2);
else
header = PACKET3(PACKET3_INDIRECT_BUFFER, 2);
control |= ib->length_dw | (vm_id << 24);
if (amdgpu_sriov_vf(ring->adev) && (ib->flags & AMDGPU_IB_FLAG_PREEMPT))
control |= INDIRECT_BUFFER_PRE_ENB(1);
amdgpu_ring_write(ring, header);
BUG_ON(ib->gpu_addr & 0x3);
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, control);
}
static void gfx_v9_0_ring_emit_ib_compute(struct amdgpu_ring *ring,
struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
u32 control = INDIRECT_BUFFER_VALID | ib->length_dw | (vm_id << 24);
amdgpu_ring_write(ring, PACKET3(PACKET3_INDIRECT_BUFFER, 2));
BUG_ON(ib->gpu_addr & 0x3);
amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
(2 << 0) |
#endif
lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, control);
}
static void gfx_v9_0_ring_emit_fence(struct amdgpu_ring *ring, u64 addr,
u64 seq, unsigned flags)
{
bool write64bit = flags & AMDGPU_FENCE_FLAG_64BIT;
bool int_sel = flags & AMDGPU_FENCE_FLAG_INT;
amdgpu_ring_write(ring, PACKET3(PACKET3_RELEASE_MEM, 6));
amdgpu_ring_write(ring, (EOP_TCL1_ACTION_EN |
EOP_TC_ACTION_EN |
EOP_TC_WB_ACTION_EN |
EOP_TC_MD_ACTION_EN |
EVENT_TYPE(CACHE_FLUSH_AND_INV_TS_EVENT) |
EVENT_INDEX(5)));
amdgpu_ring_write(ring, DATA_SEL(write64bit ? 2 : 1) | INT_SEL(int_sel ? 2 : 0));
if (write64bit)
BUG_ON(addr & 0x7);
else
BUG_ON(addr & 0x3);
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, lower_32_bits(seq));
amdgpu_ring_write(ring, upper_32_bits(seq));
amdgpu_ring_write(ring, 0);
}
static void gfx_v9_0_ring_emit_pipeline_sync(struct amdgpu_ring *ring)
{
int usepfp = (ring->funcs->type == AMDGPU_RING_TYPE_GFX);
uint32_t seq = ring->fence_drv.sync_seq;
uint64_t addr = ring->fence_drv.gpu_addr;
gfx_v9_0_wait_reg_mem(ring, usepfp, 1, 0,
lower_32_bits(addr), upper_32_bits(addr),
seq, 0xffffffff, 4);
}
static void gfx_v9_0_ring_emit_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr)
{
struct amdgpu_vmhub *hub = &ring->adev->vmhub[ring->funcs->vmhub];
int usepfp = (ring->funcs->type == AMDGPU_RING_TYPE_GFX);
uint32_t req = ring->adev->gart.gart_funcs->get_invalidate_req(vm_id);
unsigned eng = ring->vm_inv_eng;
pd_addr = pd_addr | 0x1;
BUG_ON(pd_addr & 0xFFFF00000000003EULL);
gfx_v9_0_write_data_to_reg(ring, usepfp, true,
hub->ctx0_ptb_addr_lo32 + (2 * vm_id),
lower_32_bits(pd_addr));
gfx_v9_0_write_data_to_reg(ring, usepfp, true,
hub->ctx0_ptb_addr_hi32 + (2 * vm_id),
upper_32_bits(pd_addr));
gfx_v9_0_write_data_to_reg(ring, usepfp, true,
hub->vm_inv_eng0_req + eng, req);
gfx_v9_0_wait_reg_mem(ring, 0, 0, 0, hub->vm_inv_eng0_ack +
eng, 0, 1 << vm_id, 1 << vm_id, 0x20);
if (usepfp) {
amdgpu_ring_write(ring, PACKET3(PACKET3_PFP_SYNC_ME, 0));
amdgpu_ring_write(ring, 0x0);
}
}
static u64 gfx_v9_0_ring_get_rptr_compute(struct amdgpu_ring *ring)
{
return ring->adev->wb.wb[ring->rptr_offs];
}
static u64 gfx_v9_0_ring_get_wptr_compute(struct amdgpu_ring *ring)
{
u64 wptr;
if (ring->use_doorbell)
wptr = atomic64_read((atomic64_t *)&ring->adev->wb.wb[ring->wptr_offs]);
else
BUG();
return wptr;
}
static void gfx_v9_0_ring_set_wptr_compute(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
if (ring->use_doorbell) {
atomic64_set((atomic64_t*)&adev->wb.wb[ring->wptr_offs], ring->wptr);
WDOORBELL64(ring->doorbell_index, ring->wptr);
} else{
BUG();
}
}
static void gfx_v9_0_ring_emit_fence_kiq(struct amdgpu_ring *ring, u64 addr,
u64 seq, unsigned int flags)
{
BUG_ON(flags & AMDGPU_FENCE_FLAG_64BIT);
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(5) | WR_CONFIRM));
amdgpu_ring_write(ring, lower_32_bits(addr));
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, lower_32_bits(seq));
if (flags & AMDGPU_FENCE_FLAG_INT) {
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(0) |
WRITE_DATA_DST_SEL(0) | WR_CONFIRM));
amdgpu_ring_write(ring, SOC15_REG_OFFSET(GC, 0, mmCPC_INT_STATUS));
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, 0x20000000);
}
}
static void gfx_v9_ring_emit_sb(struct amdgpu_ring *ring)
{
amdgpu_ring_write(ring, PACKET3(PACKET3_SWITCH_BUFFER, 0));
amdgpu_ring_write(ring, 0);
}
static void gfx_v9_0_ring_emit_ce_meta(struct amdgpu_ring *ring)
{
static struct v9_ce_ib_state ce_payload = {0};
uint64_t csa_addr;
int cnt;
cnt = (sizeof(ce_payload) >> 2) + 4 - 2;
csa_addr = AMDGPU_VA_RESERVED_SIZE - 2 * 4096;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, cnt));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(2) |
WRITE_DATA_DST_SEL(8) |
WR_CONFIRM) |
WRITE_DATA_CACHE_POLICY(0));
amdgpu_ring_write(ring, lower_32_bits(csa_addr + offsetof(struct v9_gfx_meta_data, ce_payload)));
amdgpu_ring_write(ring, upper_32_bits(csa_addr + offsetof(struct v9_gfx_meta_data, ce_payload)));
amdgpu_ring_write_multiple(ring, (void *)&ce_payload, sizeof(ce_payload) >> 2);
}
static void gfx_v9_0_ring_emit_de_meta(struct amdgpu_ring *ring)
{
static struct v9_de_ib_state de_payload = {0};
uint64_t csa_addr, gds_addr;
int cnt;
csa_addr = AMDGPU_VA_RESERVED_SIZE - 2 * 4096;
gds_addr = csa_addr + 4096;
de_payload.gds_backup_addrlo = lower_32_bits(gds_addr);
de_payload.gds_backup_addrhi = upper_32_bits(gds_addr);
cnt = (sizeof(de_payload) >> 2) + 4 - 2;
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, cnt));
amdgpu_ring_write(ring, (WRITE_DATA_ENGINE_SEL(1) |
WRITE_DATA_DST_SEL(8) |
WR_CONFIRM) |
WRITE_DATA_CACHE_POLICY(0));
amdgpu_ring_write(ring, lower_32_bits(csa_addr + offsetof(struct v9_gfx_meta_data, de_payload)));
amdgpu_ring_write(ring, upper_32_bits(csa_addr + offsetof(struct v9_gfx_meta_data, de_payload)));
amdgpu_ring_write_multiple(ring, (void *)&de_payload, sizeof(de_payload) >> 2);
}
static void gfx_v9_ring_emit_cntxcntl(struct amdgpu_ring *ring, uint32_t flags)
{
uint32_t dw2 = 0;
if (amdgpu_sriov_vf(ring->adev))
gfx_v9_0_ring_emit_ce_meta(ring);
dw2 |= 0x80000000;
if (flags & AMDGPU_HAVE_CTX_SWITCH) {
dw2 |= 0x8001;
dw2 |= 0x01000000;
dw2 |= 0x10002;
if (AMDGPU_PREAMBLE_IB_PRESENT & flags)
dw2 |= 0x10000000;
} else {
if (AMDGPU_PREAMBLE_IB_PRESENT_FIRST & flags)
dw2 |= 0x10000000;
}
amdgpu_ring_write(ring, PACKET3(PACKET3_CONTEXT_CONTROL, 1));
amdgpu_ring_write(ring, dw2);
amdgpu_ring_write(ring, 0);
if (amdgpu_sriov_vf(ring->adev))
gfx_v9_0_ring_emit_de_meta(ring);
}
static unsigned gfx_v9_0_ring_emit_init_cond_exec(struct amdgpu_ring *ring)
{
unsigned ret;
amdgpu_ring_write(ring, PACKET3(PACKET3_COND_EXEC, 3));
amdgpu_ring_write(ring, lower_32_bits(ring->cond_exe_gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ring->cond_exe_gpu_addr));
amdgpu_ring_write(ring, 0);
ret = ring->wptr & ring->buf_mask;
amdgpu_ring_write(ring, 0x55aa55aa);
return ret;
}
static void gfx_v9_0_ring_emit_patch_cond_exec(struct amdgpu_ring *ring, unsigned offset)
{
unsigned cur;
BUG_ON(offset > ring->buf_mask);
BUG_ON(ring->ring[offset] != 0x55aa55aa);
cur = (ring->wptr & ring->buf_mask) - 1;
if (likely(cur > offset))
ring->ring[offset] = cur - offset;
else
ring->ring[offset] = (ring->ring_size>>2) - offset + cur;
}
static void gfx_v9_0_ring_emit_rreg(struct amdgpu_ring *ring, uint32_t reg)
{
struct amdgpu_device *adev = ring->adev;
amdgpu_ring_write(ring, PACKET3(PACKET3_COPY_DATA, 4));
amdgpu_ring_write(ring, 0 |
(5 << 8) |
(1 << 20));
amdgpu_ring_write(ring, reg);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, lower_32_bits(adev->wb.gpu_addr +
adev->virt.reg_val_offs * 4));
amdgpu_ring_write(ring, upper_32_bits(adev->wb.gpu_addr +
adev->virt.reg_val_offs * 4));
}
static void gfx_v9_0_ring_emit_wreg(struct amdgpu_ring *ring, uint32_t reg,
uint32_t val)
{
amdgpu_ring_write(ring, PACKET3(PACKET3_WRITE_DATA, 3));
amdgpu_ring_write(ring, (1 << 16));
amdgpu_ring_write(ring, reg);
amdgpu_ring_write(ring, 0);
amdgpu_ring_write(ring, val);
}
static void gfx_v9_0_set_gfx_eop_interrupt_state(struct amdgpu_device *adev,
enum amdgpu_interrupt_state state)
{
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
case AMDGPU_IRQ_STATE_ENABLE:
WREG32_FIELD15(GC, 0, CP_INT_CNTL_RING0,
TIME_STAMP_INT_ENABLE,
state == AMDGPU_IRQ_STATE_ENABLE ? 1 : 0);
break;
default:
break;
}
}
static void gfx_v9_0_set_compute_eop_interrupt_state(struct amdgpu_device *adev,
int me, int pipe,
enum amdgpu_interrupt_state state)
{
u32 mec_int_cntl, mec_int_cntl_reg;
if (me == 1) {
switch (pipe) {
case 0:
mec_int_cntl_reg = SOC15_REG_OFFSET(GC, 0, mmCP_ME1_PIPE0_INT_CNTL);
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
static int gfx_v9_0_set_priv_reg_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
case AMDGPU_IRQ_STATE_ENABLE:
WREG32_FIELD15(GC, 0, CP_INT_CNTL_RING0,
PRIV_REG_INT_ENABLE,
state == AMDGPU_IRQ_STATE_ENABLE ? 1 : 0);
break;
default:
break;
}
return 0;
}
static int gfx_v9_0_set_priv_inst_fault_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
unsigned type,
enum amdgpu_interrupt_state state)
{
switch (state) {
case AMDGPU_IRQ_STATE_DISABLE:
case AMDGPU_IRQ_STATE_ENABLE:
WREG32_FIELD15(GC, 0, CP_INT_CNTL_RING0,
PRIV_INSTR_INT_ENABLE,
state == AMDGPU_IRQ_STATE_ENABLE ? 1 : 0);
default:
break;
}
return 0;
}
static int gfx_v9_0_set_eop_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
switch (type) {
case AMDGPU_CP_IRQ_GFX_EOP:
gfx_v9_0_set_gfx_eop_interrupt_state(adev, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE0_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 1, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE1_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 1, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE2_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 1, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC1_PIPE3_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 1, 3, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE0_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 2, 0, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE1_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 2, 1, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE2_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 2, 2, state);
break;
case AMDGPU_CP_IRQ_COMPUTE_MEC2_PIPE3_EOP:
gfx_v9_0_set_compute_eop_interrupt_state(adev, 2, 3, state);
break;
default:
break;
}
return 0;
}
static int gfx_v9_0_eop_irq(struct amdgpu_device *adev,
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
static int gfx_v9_0_priv_reg_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal register access in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static int gfx_v9_0_priv_inst_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_ERROR("Illegal instruction in command stream\n");
schedule_work(&adev->reset_work);
return 0;
}
static int gfx_v9_0_kiq_set_interrupt_state(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned int type,
enum amdgpu_interrupt_state state)
{
uint32_t tmp, target;
struct amdgpu_ring *ring = &(adev->gfx.kiq.ring);
if (ring->me == 1)
target = SOC15_REG_OFFSET(GC, 0, mmCP_ME1_PIPE0_INT_CNTL);
else
target = SOC15_REG_OFFSET(GC, 0, mmCP_ME2_PIPE0_INT_CNTL);
target += ring->pipe;
switch (type) {
case AMDGPU_CP_KIQ_IRQ_DRIVER0:
if (state == AMDGPU_IRQ_STATE_DISABLE) {
tmp = RREG32_SOC15(GC, 0, mmCPC_INT_CNTL);
tmp = REG_SET_FIELD(tmp, CPC_INT_CNTL,
GENERIC2_INT_ENABLE, 0);
WREG32_SOC15(GC, 0, mmCPC_INT_CNTL, tmp);
tmp = RREG32(target);
tmp = REG_SET_FIELD(tmp, CP_ME2_PIPE0_INT_CNTL,
GENERIC2_INT_ENABLE, 0);
WREG32(target, tmp);
} else {
tmp = RREG32_SOC15(GC, 0, mmCPC_INT_CNTL);
tmp = REG_SET_FIELD(tmp, CPC_INT_CNTL,
GENERIC2_INT_ENABLE, 1);
WREG32_SOC15(GC, 0, mmCPC_INT_CNTL, tmp);
tmp = RREG32(target);
tmp = REG_SET_FIELD(tmp, CP_ME2_PIPE0_INT_CNTL,
GENERIC2_INT_ENABLE, 1);
WREG32(target, tmp);
}
break;
default:
BUG();
break;
}
return 0;
}
static int gfx_v9_0_kiq_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
u8 me_id, pipe_id, queue_id;
struct amdgpu_ring *ring = &(adev->gfx.kiq.ring);
me_id = (entry->ring_id & 0x0c) >> 2;
pipe_id = (entry->ring_id & 0x03) >> 0;
queue_id = (entry->ring_id & 0x70) >> 4;
DRM_DEBUG("IH: CPC GENERIC2_INT, me:%d, pipe:%d, queue:%d\n",
me_id, pipe_id, queue_id);
amdgpu_fence_process(ring);
return 0;
}
static void gfx_v9_0_set_ring_funcs(struct amdgpu_device *adev)
{
int i;
adev->gfx.kiq.ring.funcs = &gfx_v9_0_ring_funcs_kiq;
for (i = 0; i < adev->gfx.num_gfx_rings; i++)
adev->gfx.gfx_ring[i].funcs = &gfx_v9_0_ring_funcs_gfx;
for (i = 0; i < adev->gfx.num_compute_rings; i++)
adev->gfx.compute_ring[i].funcs = &gfx_v9_0_ring_funcs_compute;
}
static void gfx_v9_0_set_irq_funcs(struct amdgpu_device *adev)
{
adev->gfx.eop_irq.num_types = AMDGPU_CP_IRQ_LAST;
adev->gfx.eop_irq.funcs = &gfx_v9_0_eop_irq_funcs;
adev->gfx.priv_reg_irq.num_types = 1;
adev->gfx.priv_reg_irq.funcs = &gfx_v9_0_priv_reg_irq_funcs;
adev->gfx.priv_inst_irq.num_types = 1;
adev->gfx.priv_inst_irq.funcs = &gfx_v9_0_priv_inst_irq_funcs;
adev->gfx.kiq.irq.num_types = AMDGPU_CP_KIQ_IRQ_LAST;
adev->gfx.kiq.irq.funcs = &gfx_v9_0_kiq_irq_funcs;
}
static void gfx_v9_0_set_rlc_funcs(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_VEGA10:
adev->gfx.rlc.funcs = &gfx_v9_0_rlc_funcs;
break;
default:
break;
}
}
static void gfx_v9_0_set_gds_init(struct amdgpu_device *adev)
{
adev->gds.mem.total_size = RREG32_SOC15(GC, 0, mmGDS_VMID0_SIZE);
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
static u32 gfx_v9_0_get_cu_active_bitmap(struct amdgpu_device *adev)
{
u32 data, mask;
data = RREG32_SOC15(GC, 0, mmCC_GC_SHADER_ARRAY_CONFIG);
data |= RREG32_SOC15(GC, 0, mmGC_USER_SHADER_ARRAY_CONFIG);
data &= CC_GC_SHADER_ARRAY_CONFIG__INACTIVE_CUS_MASK;
data >>= CC_GC_SHADER_ARRAY_CONFIG__INACTIVE_CUS__SHIFT;
mask = gfx_v9_0_create_bitmask(adev->gfx.config.max_cu_per_sh);
return (~data) & mask;
}
static int gfx_v9_0_get_cu_info(struct amdgpu_device *adev,
struct amdgpu_cu_info *cu_info)
{
int i, j, k, counter, active_cu_number = 0;
u32 mask, bitmap, ao_bitmap, ao_cu_mask = 0;
if (!adev || !cu_info)
return -EINVAL;
memset(cu_info, 0, sizeof(*cu_info));
mutex_lock(&adev->grbm_idx_mutex);
for (i = 0; i < adev->gfx.config.max_shader_engines; i++) {
for (j = 0; j < adev->gfx.config.max_sh_per_se; j++) {
mask = 1;
ao_bitmap = 0;
counter = 0;
gfx_v9_0_select_se_sh(adev, i, j, 0xffffffff);
bitmap = gfx_v9_0_get_cu_active_bitmap(adev);
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
gfx_v9_0_select_se_sh(adev, 0xffffffff, 0xffffffff, 0xffffffff);
mutex_unlock(&adev->grbm_idx_mutex);
cu_info->number = active_cu_number;
cu_info->ao_cu_mask = ao_cu_mask;
return 0;
}
static int gfx_v9_0_init_queue(struct amdgpu_ring *ring)
{
int r, j;
u32 tmp;
bool use_doorbell = true;
u64 hqd_gpu_addr;
u64 mqd_gpu_addr;
u64 eop_gpu_addr;
u64 wb_gpu_addr;
u32 *buf;
struct v9_mqd *mqd;
struct amdgpu_device *adev;
adev = ring->adev;
if (ring->mqd_obj == NULL) {
r = amdgpu_bo_create(adev,
sizeof(struct v9_mqd),
PAGE_SIZE,true,
AMDGPU_GEM_DOMAIN_GTT, 0, NULL,
NULL, &ring->mqd_obj);
if (r) {
dev_warn(adev->dev, "(%d) create MQD bo failed\n", r);
return r;
}
}
r = amdgpu_bo_reserve(ring->mqd_obj, false);
if (unlikely(r != 0)) {
gfx_v9_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_pin(ring->mqd_obj, AMDGPU_GEM_DOMAIN_GTT,
&mqd_gpu_addr);
if (r) {
dev_warn(adev->dev, "(%d) pin MQD bo failed\n", r);
gfx_v9_0_cp_compute_fini(adev);
return r;
}
r = amdgpu_bo_kmap(ring->mqd_obj, (void **)&buf);
if (r) {
dev_warn(adev->dev, "(%d) map MQD bo failed\n", r);
gfx_v9_0_cp_compute_fini(adev);
return r;
}
memset(buf, 0, sizeof(struct v9_mqd));
mqd = (struct v9_mqd *)buf;
mqd->header = 0xC0310800;
mqd->compute_pipelinestat_enable = 0x00000001;
mqd->compute_static_thread_mgmt_se0 = 0xffffffff;
mqd->compute_static_thread_mgmt_se1 = 0xffffffff;
mqd->compute_static_thread_mgmt_se2 = 0xffffffff;
mqd->compute_static_thread_mgmt_se3 = 0xffffffff;
mqd->compute_misc_reserved = 0x00000003;
mutex_lock(&adev->srbm_mutex);
soc15_grbm_select(adev, ring->me,
ring->pipe,
ring->queue, 0);
WREG32_FIELD15(GC, 0, CP_PQ_WPTR_POLL_CNTL, EN, 0);
BUG_ON(ring->me != 1 || ring->pipe != 0);
eop_gpu_addr = adev->gfx.mec.hpd_eop_gpu_addr + (ring->queue * MEC_HPD_SIZE);
eop_gpu_addr >>= 8;
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_BASE_ADDR, lower_32_bits(eop_gpu_addr));
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_BASE_ADDR_HI, upper_32_bits(eop_gpu_addr));
mqd->cp_hqd_eop_base_addr_lo = lower_32_bits(eop_gpu_addr);
mqd->cp_hqd_eop_base_addr_hi = upper_32_bits(eop_gpu_addr);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_EOP_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_EOP_CONTROL, EOP_SIZE,
(order_base_2(MEC_HPD_SIZE / 4) - 1));
WREG32_SOC15(GC, 0, mmCP_HQD_EOP_CONTROL, tmp);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL);
if (use_doorbell)
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 1);
else
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 0);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL, tmp);
mqd->cp_hqd_pq_doorbell_control = tmp;
ring->wptr = 0;
mqd->cp_hqd_dequeue_request = 0;
mqd->cp_hqd_pq_rptr = 0;
mqd->cp_hqd_pq_wptr_lo = 0;
mqd->cp_hqd_pq_wptr_hi = 0;
if (RREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE) & 1) {
WREG32_SOC15(GC, 0, mmCP_HQD_DEQUEUE_REQUEST, 1);
for (j = 0; j < adev->usec_timeout; j++) {
if (!(RREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE) & 1))
break;
udelay(1);
}
WREG32_SOC15(GC, 0, mmCP_HQD_DEQUEUE_REQUEST, mqd->cp_hqd_dequeue_request);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR, mqd->cp_hqd_pq_rptr);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_LO, mqd->cp_hqd_pq_wptr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_HI, mqd->cp_hqd_pq_wptr_hi);
}
mqd->cp_mqd_base_addr_lo = mqd_gpu_addr & 0xfffffffc;
mqd->cp_mqd_base_addr_hi = upper_32_bits(mqd_gpu_addr);
WREG32_SOC15(GC, 0, mmCP_MQD_BASE_ADDR, mqd->cp_mqd_base_addr_lo);
WREG32_SOC15(GC, 0, mmCP_MQD_BASE_ADDR_HI, mqd->cp_mqd_base_addr_hi);
tmp = RREG32_SOC15(GC, 0, mmCP_MQD_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_MQD_CONTROL, VMID, 0);
WREG32_SOC15(GC, 0, mmCP_MQD_CONTROL, tmp);
mqd->cp_mqd_control = tmp;
hqd_gpu_addr = ring->gpu_addr >> 8;
mqd->cp_hqd_pq_base_lo = hqd_gpu_addr;
mqd->cp_hqd_pq_base_hi = upper_32_bits(hqd_gpu_addr);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_BASE, mqd->cp_hqd_pq_base_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_BASE_HI, mqd->cp_hqd_pq_base_hi);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_CONTROL);
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
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_CONTROL, tmp);
mqd->cp_hqd_pq_control = tmp;
wb_gpu_addr = adev->wb.gpu_addr + (ring->rptr_offs * 4);
mqd->cp_hqd_pq_rptr_report_addr_lo = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_rptr_report_addr_hi =
upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR_REPORT_ADDR,
mqd->cp_hqd_pq_rptr_report_addr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_RPTR_REPORT_ADDR_HI,
mqd->cp_hqd_pq_rptr_report_addr_hi);
wb_gpu_addr = adev->wb.gpu_addr + (ring->wptr_offs * 4);
mqd->cp_hqd_pq_wptr_poll_addr_lo = wb_gpu_addr & 0xfffffffc;
mqd->cp_hqd_pq_wptr_poll_addr_hi = upper_32_bits(wb_gpu_addr) & 0xffff;
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_POLL_ADDR,
mqd->cp_hqd_pq_wptr_poll_addr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_POLL_ADDR_HI,
mqd->cp_hqd_pq_wptr_poll_addr_hi);
if (use_doorbell) {
WREG32_SOC15(GC, 0, mmCP_MEC_DOORBELL_RANGE_LOWER,
(AMDGPU_DOORBELL64_KIQ * 2) << 2);
WREG32_SOC15(GC, 0, mmCP_MEC_DOORBELL_RANGE_UPPER,
(AMDGPU_DOORBELL64_MEC_RING7 * 2) << 2);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL,
DOORBELL_OFFSET, ring->doorbell_index);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 1);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_SOURCE, 0);
tmp = REG_SET_FIELD(tmp, CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_HIT, 0);
mqd->cp_hqd_pq_doorbell_control = tmp;
} else {
mqd->cp_hqd_pq_doorbell_control = 0;
}
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_DOORBELL_CONTROL,
mqd->cp_hqd_pq_doorbell_control);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_LO, mqd->cp_hqd_pq_wptr_lo);
WREG32_SOC15(GC, 0, mmCP_HQD_PQ_WPTR_HI, mqd->cp_hqd_pq_wptr_hi);
mqd->cp_hqd_vmid = 0;
WREG32_SOC15(GC, 0, mmCP_HQD_VMID, mqd->cp_hqd_vmid);
tmp = RREG32_SOC15(GC, 0, mmCP_HQD_PERSISTENT_STATE);
tmp = REG_SET_FIELD(tmp, CP_HQD_PERSISTENT_STATE, PRELOAD_SIZE, 0x53);
WREG32_SOC15(GC, 0, mmCP_HQD_PERSISTENT_STATE, tmp);
mqd->cp_hqd_persistent_state = tmp;
mqd->cp_hqd_active = 1;
WREG32_SOC15(GC, 0, mmCP_HQD_ACTIVE, mqd->cp_hqd_active);
soc15_grbm_select(adev, 0, 0, 0, 0);
mutex_unlock(&adev->srbm_mutex);
amdgpu_bo_kunmap(ring->mqd_obj);
amdgpu_bo_unreserve(ring->mqd_obj);
if (use_doorbell)
WREG32_FIELD15(GC, 0, CP_PQ_STATUS, DOORBELL_ENABLE, 1);
return 0;
}
