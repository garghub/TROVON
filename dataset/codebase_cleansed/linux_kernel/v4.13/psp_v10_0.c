static int
psp_v10_0_get_fw_type(struct amdgpu_firmware_info *ucode, enum psp_gfx_fw_type *type)
{
switch(ucode->ucode_id) {
case AMDGPU_UCODE_ID_SDMA0:
*type = GFX_FW_TYPE_SDMA0;
break;
case AMDGPU_UCODE_ID_SDMA1:
*type = GFX_FW_TYPE_SDMA1;
break;
case AMDGPU_UCODE_ID_CP_CE:
*type = GFX_FW_TYPE_CP_CE;
break;
case AMDGPU_UCODE_ID_CP_PFP:
*type = GFX_FW_TYPE_CP_PFP;
break;
case AMDGPU_UCODE_ID_CP_ME:
*type = GFX_FW_TYPE_CP_ME;
break;
case AMDGPU_UCODE_ID_CP_MEC1:
*type = GFX_FW_TYPE_CP_MEC;
break;
case AMDGPU_UCODE_ID_CP_MEC1_JT:
*type = GFX_FW_TYPE_CP_MEC_ME1;
break;
case AMDGPU_UCODE_ID_CP_MEC2:
*type = GFX_FW_TYPE_CP_MEC;
break;
case AMDGPU_UCODE_ID_CP_MEC2_JT:
*type = GFX_FW_TYPE_CP_MEC_ME2;
break;
case AMDGPU_UCODE_ID_RLC_G:
*type = GFX_FW_TYPE_RLC_G;
break;
case AMDGPU_UCODE_ID_SMC:
*type = GFX_FW_TYPE_SMU;
break;
case AMDGPU_UCODE_ID_UVD:
*type = GFX_FW_TYPE_UVD;
break;
case AMDGPU_UCODE_ID_VCE:
*type = GFX_FW_TYPE_VCE;
break;
case AMDGPU_UCODE_ID_MAXIMUM:
default:
return -EINVAL;
}
return 0;
}
int psp_v10_0_prep_cmd_buf(struct amdgpu_firmware_info *ucode, struct psp_gfx_cmd_resp *cmd)
{
int ret;
uint64_t fw_mem_mc_addr = ucode->mc_addr;
struct common_firmware_header *header;
memset(cmd, 0, sizeof(struct psp_gfx_cmd_resp));
header = (struct common_firmware_header *)ucode->fw;
cmd->cmd_id = GFX_CMD_ID_LOAD_IP_FW;
cmd->cmd.cmd_load_ip_fw.fw_phy_addr_lo = lower_32_bits(fw_mem_mc_addr);
cmd->cmd.cmd_load_ip_fw.fw_phy_addr_hi = upper_32_bits(fw_mem_mc_addr);
cmd->cmd.cmd_load_ip_fw.fw_size = le32_to_cpu(header->ucode_size_bytes);
ret = psp_v10_0_get_fw_type(ucode, &cmd->cmd.cmd_load_ip_fw.fw_type);
if (ret)
DRM_ERROR("Unknown firmware type\n");
return ret;
}
int psp_v10_0_ring_init(struct psp_context *psp, enum psp_ring_type ring_type)
{
int ret = 0;
unsigned int psp_ring_reg = 0;
struct psp_ring *ring;
struct amdgpu_device *adev = psp->adev;
ring = &psp->km_ring;
ring->ring_type = ring_type;
ring->ring_size = 0x1000;
ret = amdgpu_bo_create_kernel(adev, ring->ring_size, PAGE_SIZE,
AMDGPU_GEM_DOMAIN_VRAM,
&adev->firmware.rbuf,
&ring->ring_mem_mc_addr,
(void **)&ring->ring_mem);
if (ret) {
ring->ring_size = 0;
return ret;
}
psp_ring_reg = lower_32_bits(ring->ring_mem_mc_addr);
WREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_69, psp_ring_reg);
psp_ring_reg = upper_32_bits(ring->ring_mem_mc_addr);
WREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_70, psp_ring_reg);
psp_ring_reg = ring->ring_size;
WREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_71, psp_ring_reg);
psp_ring_reg = ring_type;
psp_ring_reg = psp_ring_reg << 16;
WREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_64, psp_ring_reg);
psp_ring_reg = 0;
while ((psp_ring_reg & 0x80000000) == 0) {
psp_ring_reg = RREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_64);
}
return 0;
}
int psp_v10_0_cmd_submit(struct psp_context *psp,
struct amdgpu_firmware_info *ucode,
uint64_t cmd_buf_mc_addr, uint64_t fence_mc_addr,
int index)
{
unsigned int psp_write_ptr_reg = 0;
struct psp_gfx_rb_frame * write_frame = psp->km_ring.ring_mem;
struct psp_ring *ring = &psp->km_ring;
struct amdgpu_device *adev = psp->adev;
psp_write_ptr_reg = RREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_67);
if ((psp_write_ptr_reg % ring->ring_size) == 0)
write_frame = ring->ring_mem;
else
write_frame = ring->ring_mem + (psp_write_ptr_reg / (sizeof(struct psp_gfx_rb_frame) / 4));
write_frame->cmd_buf_addr_hi = upper_32_bits(cmd_buf_mc_addr);
write_frame->cmd_buf_addr_lo = lower_32_bits(cmd_buf_mc_addr);
write_frame->fence_addr_hi = upper_32_bits(fence_mc_addr);
write_frame->fence_addr_lo = lower_32_bits(fence_mc_addr);
write_frame->fence_value = index;
psp_write_ptr_reg += sizeof(struct psp_gfx_rb_frame) / 4;
psp_write_ptr_reg = (psp_write_ptr_reg >= ring->ring_size) ? 0 : psp_write_ptr_reg;
WREG32_SOC15(MP0, 0, mmMP0_SMN_C2PMSG_67, psp_write_ptr_reg);
return 0;
}
static int
psp_v10_0_sram_map(unsigned int *sram_offset, unsigned int *sram_addr_reg_offset,
unsigned int *sram_data_reg_offset,
enum AMDGPU_UCODE_ID ucode_id)
{
int ret = 0;
switch(ucode_id) {
#if 0
case AMDGPU_UCODE_ID_SMC:
*sram_offset = 0;
*sram_addr_reg_offset = 0;
*sram_data_reg_offset = 0;
break;
#endif
case AMDGPU_UCODE_ID_CP_CE:
*sram_offset = 0x0;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_CE_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_CE_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_CP_PFP:
*sram_offset = 0x0;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_PFP_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_PFP_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_CP_ME:
*sram_offset = 0x0;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_HYP_ME_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_HYP_ME_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_CP_MEC1:
*sram_offset = 0x10000;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_MEC_ME1_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_MEC_ME1_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_CP_MEC2:
*sram_offset = 0x10000;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_HYP_MEC2_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmCP_HYP_MEC2_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_RLC_G:
*sram_offset = 0x2000;
*sram_addr_reg_offset = SOC15_REG_OFFSET(GC, 0, mmRLC_GPM_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(GC, 0, mmRLC_GPM_UCODE_DATA);
break;
case AMDGPU_UCODE_ID_SDMA0:
*sram_offset = 0x0;
*sram_addr_reg_offset = SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_UCODE_ADDR);
*sram_data_reg_offset = SOC15_REG_OFFSET(SDMA0, 0, mmSDMA0_UCODE_DATA);
break;
#if 0
case AMDGPU_UCODE_ID_SDMA1:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
case AMDGPU_UCODE_ID_UVD:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
case AMDGPU_UCODE_ID_VCE:
*sram_offset = ;
*sram_addr_reg_offset = ;
break;
#endif
case AMDGPU_UCODE_ID_MAXIMUM:
default:
ret = -EINVAL;
break;
}
return ret;
}
bool psp_v10_0_compare_sram_data(struct psp_context *psp,
struct amdgpu_firmware_info *ucode,
enum AMDGPU_UCODE_ID ucode_type)
{
int err = 0;
unsigned int fw_sram_reg_val = 0;
unsigned int fw_sram_addr_reg_offset = 0;
unsigned int fw_sram_data_reg_offset = 0;
unsigned int ucode_size;
uint32_t *ucode_mem = NULL;
struct amdgpu_device *adev = psp->adev;
err = psp_v10_0_sram_map(&fw_sram_reg_val, &fw_sram_addr_reg_offset,
&fw_sram_data_reg_offset, ucode_type);
if (err)
return false;
WREG32(fw_sram_addr_reg_offset, fw_sram_reg_val);
ucode_size = ucode->ucode_size;
ucode_mem = (uint32_t *)ucode->kaddr;
while (!ucode_size) {
fw_sram_reg_val = RREG32(fw_sram_data_reg_offset);
if (*ucode_mem != fw_sram_reg_val)
return false;
ucode_mem++;
ucode_size -= 4;
}
return true;
}
