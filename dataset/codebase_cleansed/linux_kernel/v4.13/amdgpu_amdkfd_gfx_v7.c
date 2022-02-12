struct kfd2kgd_calls *amdgpu_amdkfd_gfx_7_get_functions(void)
{
return (struct kfd2kgd_calls *)&kfd2kgd;
}
static inline struct amdgpu_device *get_amdgpu_device(struct kgd_dev *kgd)
{
return (struct amdgpu_device *)kgd;
}
static void lock_srbm(struct kgd_dev *kgd, uint32_t mec, uint32_t pipe,
uint32_t queue, uint32_t vmid)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t value = PIPEID(pipe) | MEID(mec) | VMID(vmid) | QUEUEID(queue);
mutex_lock(&adev->srbm_mutex);
WREG32(mmSRBM_GFX_CNTL, value);
}
static void unlock_srbm(struct kgd_dev *kgd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
WREG32(mmSRBM_GFX_CNTL, 0);
mutex_unlock(&adev->srbm_mutex);
}
static void acquire_queue(struct kgd_dev *kgd, uint32_t pipe_id,
uint32_t queue_id)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t mec = (++pipe_id / adev->gfx.mec.num_pipe_per_mec) + 1;
uint32_t pipe = (pipe_id % adev->gfx.mec.num_pipe_per_mec);
lock_srbm(kgd, mec, pipe, queue_id, 0);
}
static void release_queue(struct kgd_dev *kgd)
{
unlock_srbm(kgd);
}
static void kgd_program_sh_mem_settings(struct kgd_dev *kgd, uint32_t vmid,
uint32_t sh_mem_config,
uint32_t sh_mem_ape1_base,
uint32_t sh_mem_ape1_limit,
uint32_t sh_mem_bases)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
lock_srbm(kgd, 0, 0, 0, vmid);
WREG32(mmSH_MEM_CONFIG, sh_mem_config);
WREG32(mmSH_MEM_APE1_BASE, sh_mem_ape1_base);
WREG32(mmSH_MEM_APE1_LIMIT, sh_mem_ape1_limit);
WREG32(mmSH_MEM_BASES, sh_mem_bases);
unlock_srbm(kgd);
}
static int kgd_set_pasid_vmid_mapping(struct kgd_dev *kgd, unsigned int pasid,
unsigned int vmid)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t pasid_mapping = (pasid == 0) ? 0 : (uint32_t)pasid |
ATC_VMID0_PASID_MAPPING__VALID_MASK;
WREG32(mmATC_VMID0_PASID_MAPPING + vmid, pasid_mapping);
while (!(RREG32(mmATC_VMID_PASID_MAPPING_UPDATE_STATUS) & (1U << vmid)))
cpu_relax();
WREG32(mmATC_VMID_PASID_MAPPING_UPDATE_STATUS, 1U << vmid);
WREG32(mmIH_VMID_0_LUT + vmid, pasid_mapping);
return 0;
}
static int kgd_init_pipeline(struct kgd_dev *kgd, uint32_t pipe_id,
uint32_t hpd_size, uint64_t hpd_gpu_addr)
{
return 0;
}
static int kgd_init_interrupts(struct kgd_dev *kgd, uint32_t pipe_id)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t mec;
uint32_t pipe;
mec = (pipe_id / adev->gfx.mec.num_pipe_per_mec) + 1;
pipe = (pipe_id % adev->gfx.mec.num_pipe_per_mec);
lock_srbm(kgd, mec, pipe, 0, 0);
WREG32(mmCPC_INT_CNTL, CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK |
CP_INT_CNTL_RING0__OPCODE_ERROR_INT_ENABLE_MASK);
unlock_srbm(kgd);
return 0;
}
static inline uint32_t get_sdma_base_addr(struct cik_sdma_rlc_registers *m)
{
uint32_t retval;
retval = m->sdma_engine_id * SDMA1_REGISTER_OFFSET +
m->sdma_queue_id * KFD_CIK_SDMA_QUEUE_OFFSET;
pr_debug("kfd: sdma base address: 0x%x\n", retval);
return retval;
}
static inline struct cik_mqd *get_mqd(void *mqd)
{
return (struct cik_mqd *)mqd;
}
static inline struct cik_sdma_rlc_registers *get_sdma_mqd(void *mqd)
{
return (struct cik_sdma_rlc_registers *)mqd;
}
static int kgd_hqd_load(struct kgd_dev *kgd, void *mqd, uint32_t pipe_id,
uint32_t queue_id, uint32_t __user *wptr)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t wptr_shadow, is_wptr_shadow_valid;
struct cik_mqd *m;
m = get_mqd(mqd);
is_wptr_shadow_valid = !get_user(wptr_shadow, wptr);
if (is_wptr_shadow_valid)
m->cp_hqd_pq_wptr = wptr_shadow;
acquire_queue(kgd, pipe_id, queue_id);
gfx_v7_0_mqd_commit(adev, m);
release_queue(kgd);
return 0;
}
static int kgd_hqd_sdma_load(struct kgd_dev *kgd, void *mqd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
struct cik_sdma_rlc_registers *m;
uint32_t sdma_base_addr;
m = get_sdma_mqd(mqd);
sdma_base_addr = get_sdma_base_addr(m);
WREG32(sdma_base_addr + mmSDMA0_RLC0_VIRTUAL_ADDR,
m->sdma_rlc_virtual_addr);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_BASE,
m->sdma_rlc_rb_base);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_BASE_HI,
m->sdma_rlc_rb_base_hi);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_RPTR_ADDR_LO,
m->sdma_rlc_rb_rptr_addr_lo);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_RPTR_ADDR_HI,
m->sdma_rlc_rb_rptr_addr_hi);
WREG32(sdma_base_addr + mmSDMA0_RLC0_DOORBELL,
m->sdma_rlc_doorbell);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_CNTL,
m->sdma_rlc_rb_cntl);
return 0;
}
static bool kgd_hqd_is_occupied(struct kgd_dev *kgd, uint64_t queue_address,
uint32_t pipe_id, uint32_t queue_id)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t act;
bool retval = false;
uint32_t low, high;
acquire_queue(kgd, pipe_id, queue_id);
act = RREG32(mmCP_HQD_ACTIVE);
if (act) {
low = lower_32_bits(queue_address >> 8);
high = upper_32_bits(queue_address >> 8);
if (low == RREG32(mmCP_HQD_PQ_BASE) &&
high == RREG32(mmCP_HQD_PQ_BASE_HI))
retval = true;
}
release_queue(kgd);
return retval;
}
static bool kgd_hqd_sdma_is_occupied(struct kgd_dev *kgd, void *mqd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
struct cik_sdma_rlc_registers *m;
uint32_t sdma_base_addr;
uint32_t sdma_rlc_rb_cntl;
m = get_sdma_mqd(mqd);
sdma_base_addr = get_sdma_base_addr(m);
sdma_rlc_rb_cntl = RREG32(sdma_base_addr + mmSDMA0_RLC0_RB_CNTL);
if (sdma_rlc_rb_cntl & SDMA0_RLC0_RB_CNTL__RB_ENABLE_MASK)
return true;
return false;
}
static int kgd_hqd_destroy(struct kgd_dev *kgd, uint32_t reset_type,
unsigned int utimeout, uint32_t pipe_id,
uint32_t queue_id)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t temp;
int timeout = utimeout;
acquire_queue(kgd, pipe_id, queue_id);
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL, 0);
WREG32(mmCP_HQD_DEQUEUE_REQUEST, reset_type);
while (true) {
temp = RREG32(mmCP_HQD_ACTIVE);
if (temp & CP_HQD_ACTIVE__ACTIVE_MASK)
break;
if (timeout <= 0) {
pr_err("kfd: cp queue preemption time out.\n");
release_queue(kgd);
return -ETIME;
}
msleep(20);
timeout -= 20;
}
release_queue(kgd);
return 0;
}
static int kgd_hqd_sdma_destroy(struct kgd_dev *kgd, void *mqd,
unsigned int utimeout)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
struct cik_sdma_rlc_registers *m;
uint32_t sdma_base_addr;
uint32_t temp;
int timeout = utimeout;
m = get_sdma_mqd(mqd);
sdma_base_addr = get_sdma_base_addr(m);
temp = RREG32(sdma_base_addr + mmSDMA0_RLC0_RB_CNTL);
temp = temp & ~SDMA0_RLC0_RB_CNTL__RB_ENABLE_MASK;
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_CNTL, temp);
while (true) {
temp = RREG32(sdma_base_addr + mmSDMA0_RLC0_CONTEXT_STATUS);
if (temp & SDMA0_STATUS_REG__RB_CMD_IDLE__SHIFT)
break;
if (timeout <= 0)
return -ETIME;
msleep(20);
timeout -= 20;
}
WREG32(sdma_base_addr + mmSDMA0_RLC0_DOORBELL, 0);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_RPTR, 0);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_WPTR, 0);
WREG32(sdma_base_addr + mmSDMA0_RLC0_RB_BASE, 0);
return 0;
}
static int kgd_address_watch_disable(struct kgd_dev *kgd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
union TCP_WATCH_CNTL_BITS cntl;
unsigned int i;
cntl.u32All = 0;
cntl.bitfields.valid = 0;
cntl.bitfields.mask = ADDRESS_WATCH_REG_CNTL_DEFAULT_MASK;
cntl.bitfields.atc = 1;
for (i = 0; i < MAX_WATCH_ADDRESSES; i++)
WREG32(watchRegs[i * ADDRESS_WATCH_REG_MAX +
ADDRESS_WATCH_REG_CNTL], cntl.u32All);
return 0;
}
static int kgd_address_watch_execute(struct kgd_dev *kgd,
unsigned int watch_point_id,
uint32_t cntl_val,
uint32_t addr_hi,
uint32_t addr_lo)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
union TCP_WATCH_CNTL_BITS cntl;
cntl.u32All = cntl_val;
cntl.bitfields.valid = 0;
WREG32(watchRegs[watch_point_id * ADDRESS_WATCH_REG_MAX +
ADDRESS_WATCH_REG_CNTL], cntl.u32All);
WREG32(watchRegs[watch_point_id * ADDRESS_WATCH_REG_MAX +
ADDRESS_WATCH_REG_ADDR_HI], addr_hi);
WREG32(watchRegs[watch_point_id * ADDRESS_WATCH_REG_MAX +
ADDRESS_WATCH_REG_ADDR_LO], addr_lo);
cntl.bitfields.valid = 1;
WREG32(watchRegs[watch_point_id * ADDRESS_WATCH_REG_MAX +
ADDRESS_WATCH_REG_CNTL], cntl.u32All);
return 0;
}
static int kgd_wave_control_execute(struct kgd_dev *kgd,
uint32_t gfx_index_val,
uint32_t sq_cmd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t data;
mutex_lock(&adev->grbm_idx_mutex);
WREG32(mmGRBM_GFX_INDEX, gfx_index_val);
WREG32(mmSQ_CMD, sq_cmd);
data = GRBM_GFX_INDEX__INSTANCE_BROADCAST_WRITES_MASK |
GRBM_GFX_INDEX__SH_BROADCAST_WRITES_MASK |
GRBM_GFX_INDEX__SE_BROADCAST_WRITES_MASK;
WREG32(mmGRBM_GFX_INDEX, data);
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
static uint32_t kgd_address_watch_get_offset(struct kgd_dev *kgd,
unsigned int watch_point_id,
unsigned int reg_offset)
{
return watchRegs[watch_point_id * ADDRESS_WATCH_REG_MAX + reg_offset];
}
static bool get_atc_vmid_pasid_mapping_valid(struct kgd_dev *kgd,
uint8_t vmid)
{
uint32_t reg;
struct amdgpu_device *adev = (struct amdgpu_device *) kgd;
reg = RREG32(mmATC_VMID0_PASID_MAPPING + vmid);
return reg & ATC_VMID0_PASID_MAPPING__VALID_MASK;
}
static uint16_t get_atc_vmid_pasid_mapping_pasid(struct kgd_dev *kgd,
uint8_t vmid)
{
uint32_t reg;
struct amdgpu_device *adev = (struct amdgpu_device *) kgd;
reg = RREG32(mmATC_VMID0_PASID_MAPPING + vmid);
return reg & ATC_VMID0_PASID_MAPPING__VALID_MASK;
}
static void write_vmid_invalidate_request(struct kgd_dev *kgd, uint8_t vmid)
{
struct amdgpu_device *adev = (struct amdgpu_device *) kgd;
WREG32(mmVM_INVALIDATE_REQUEST, 1 << vmid);
}
static uint16_t get_fw_version(struct kgd_dev *kgd, enum kgd_engine_type type)
{
struct amdgpu_device *adev = (struct amdgpu_device *) kgd;
const union amdgpu_firmware_header *hdr;
BUG_ON(kgd == NULL);
switch (type) {
case KGD_ENGINE_PFP:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.pfp_fw->data;
break;
case KGD_ENGINE_ME:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.me_fw->data;
break;
case KGD_ENGINE_CE:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.ce_fw->data;
break;
case KGD_ENGINE_MEC1:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.mec_fw->data;
break;
case KGD_ENGINE_MEC2:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.mec2_fw->data;
break;
case KGD_ENGINE_RLC:
hdr = (const union amdgpu_firmware_header *)
adev->gfx.rlc_fw->data;
break;
case KGD_ENGINE_SDMA1:
hdr = (const union amdgpu_firmware_header *)
adev->sdma.instance[0].fw->data;
break;
case KGD_ENGINE_SDMA2:
hdr = (const union amdgpu_firmware_header *)
adev->sdma.instance[1].fw->data;
break;
default:
return 0;
}
if (hdr == NULL)
return 0;
return hdr->common.ucode_version;
}
