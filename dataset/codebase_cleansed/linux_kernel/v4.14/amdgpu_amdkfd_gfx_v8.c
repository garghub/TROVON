static int get_tile_config(struct kgd_dev *kgd,
struct tile_config *config)
{
struct amdgpu_device *adev = (struct amdgpu_device *)kgd;
config->gb_addr_config = adev->gfx.config.gb_addr_config;
config->num_banks = REG_GET_FIELD(adev->gfx.config.mc_arb_ramcfg,
MC_ARB_RAMCFG, NOOFBANK);
config->num_ranks = REG_GET_FIELD(adev->gfx.config.mc_arb_ramcfg,
MC_ARB_RAMCFG, NOOFRANKS);
config->tile_config_ptr = adev->gfx.config.tile_mode_array;
config->num_tile_configs =
ARRAY_SIZE(adev->gfx.config.tile_mode_array);
config->macro_tile_config_ptr =
adev->gfx.config.macrotile_mode_array;
config->num_macro_tile_configs =
ARRAY_SIZE(adev->gfx.config.macrotile_mode_array);
return 0;
}
struct kfd2kgd_calls *amdgpu_amdkfd_gfx_8_0_get_functions(void)
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
uint32_t mec = (pipe_id / adev->gfx.mec.num_pipe_per_mec) + 1;
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
WREG32(mmCPC_INT_CNTL, CP_INT_CNTL_RING0__TIME_STAMP_INT_ENABLE_MASK);
unlock_srbm(kgd);
return 0;
}
static inline uint32_t get_sdma_base_addr(struct cik_sdma_rlc_registers *m)
{
return 0;
}
static inline struct vi_mqd *get_mqd(void *mqd)
{
return (struct vi_mqd *)mqd;
}
static inline struct cik_sdma_rlc_registers *get_sdma_mqd(void *mqd)
{
return (struct cik_sdma_rlc_registers *)mqd;
}
static int kgd_hqd_load(struct kgd_dev *kgd, void *mqd, uint32_t pipe_id,
uint32_t queue_id, uint32_t __user *wptr,
uint32_t wptr_shift, uint32_t wptr_mask,
struct mm_struct *mm)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
struct vi_mqd *m;
uint32_t *mqd_hqd;
uint32_t reg, wptr_val, data;
m = get_mqd(mqd);
acquire_queue(kgd, pipe_id, queue_id);
if (m->cp_hqd_vmid == 0) {
uint32_t value, mec, pipe;
mec = (pipe_id / adev->gfx.mec.num_pipe_per_mec) + 1;
pipe = (pipe_id % adev->gfx.mec.num_pipe_per_mec);
pr_debug("kfd: set HIQ, mec:%d, pipe:%d, queue:%d.\n",
mec, pipe, queue_id);
value = RREG32(mmRLC_CP_SCHEDULERS);
value = REG_SET_FIELD(value, RLC_CP_SCHEDULERS, scheduler1,
((mec << 5) | (pipe << 3) | queue_id | 0x80));
WREG32(mmRLC_CP_SCHEDULERS, value);
}
mqd_hqd = &m->cp_mqd_base_addr_lo;
for (reg = mmCP_MQD_BASE_ADDR; reg <= mmCP_HQD_EOP_CONTROL; reg++)
WREG32(reg, mqd_hqd[reg - mmCP_MQD_BASE_ADDR]);
if (get_amdgpu_device(kgd)->asic_type != CHIP_TONGA) {
WREG32(mmCP_HQD_EOP_RPTR, m->cp_hqd_eop_rptr);
WREG32(mmCP_HQD_EOP_WPTR, m->cp_hqd_eop_wptr);
WREG32(mmCP_HQD_EOP_WPTR_MEM, m->cp_hqd_eop_wptr_mem);
}
for (reg = mmCP_HQD_EOP_EVENTS; reg <= mmCP_HQD_ERROR; reg++)
WREG32(reg, mqd_hqd[reg - mmCP_MQD_BASE_ADDR]);
data = REG_SET_FIELD(m->cp_hqd_pq_doorbell_control,
CP_HQD_PQ_DOORBELL_CONTROL, DOORBELL_EN, 1);
WREG32(mmCP_HQD_PQ_DOORBELL_CONTROL, data);
if (read_user_wptr(mm, wptr, wptr_val))
WREG32(mmCP_HQD_PQ_WPTR, (wptr_val << wptr_shift) & wptr_mask);
data = REG_SET_FIELD(m->cp_hqd_active, CP_HQD_ACTIVE, ACTIVE, 1);
WREG32(mmCP_HQD_ACTIVE, data);
release_queue(kgd);
return 0;
}
static int kgd_hqd_sdma_load(struct kgd_dev *kgd, void *mqd)
{
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
static int kgd_hqd_destroy(struct kgd_dev *kgd, void *mqd,
enum kfd_preempt_type reset_type,
unsigned int utimeout, uint32_t pipe_id,
uint32_t queue_id)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t temp;
enum hqd_dequeue_request_type type;
unsigned long flags, end_jiffies;
int retry;
struct vi_mqd *m = get_mqd(mqd);
acquire_queue(kgd, pipe_id, queue_id);
if (m->cp_hqd_vmid == 0)
WREG32_FIELD(RLC_CP_SCHEDULERS, scheduler1, 0);
switch (reset_type) {
case KFD_PREEMPT_TYPE_WAVEFRONT_DRAIN:
type = DRAIN_PIPE;
break;
case KFD_PREEMPT_TYPE_WAVEFRONT_RESET:
type = RESET_WAVES;
break;
default:
type = DRAIN_PIPE;
break;
}
local_irq_save(flags);
preempt_disable();
retry = 5000;
while (true) {
temp = RREG32(mmCP_HQD_IQ_TIMER);
if (REG_GET_FIELD(temp, CP_HQD_IQ_TIMER, PROCESSING_IQ)) {
pr_debug("HW is processing IQ\n");
goto loop;
}
if (REG_GET_FIELD(temp, CP_HQD_IQ_TIMER, ACTIVE)) {
if (REG_GET_FIELD(temp, CP_HQD_IQ_TIMER, RETRY_TYPE)
== 3)
break;
if (REG_GET_FIELD(temp, CP_HQD_IQ_TIMER, WAIT_TIME)
>= 10)
break;
pr_debug("IQ timer is active\n");
} else
break;
loop:
if (!retry) {
pr_err("CP HQD IQ timer status time out\n");
break;
}
ndelay(100);
--retry;
}
retry = 1000;
while (true) {
temp = RREG32(mmCP_HQD_DEQUEUE_REQUEST);
if (!(temp & CP_HQD_DEQUEUE_REQUEST__IQ_REQ_PEND_MASK))
break;
pr_debug("Dequeue request is pending\n");
if (!retry) {
pr_err("CP HQD dequeue request time out\n");
break;
}
ndelay(100);
--retry;
}
local_irq_restore(flags);
preempt_enable();
WREG32(mmCP_HQD_DEQUEUE_REQUEST, type);
end_jiffies = (utimeout * HZ / 1000) + jiffies;
while (true) {
temp = RREG32(mmCP_HQD_ACTIVE);
if (!(temp & CP_HQD_ACTIVE__ACTIVE_MASK))
break;
if (time_after(jiffies, end_jiffies)) {
pr_err("cp queue preemption time out.\n");
release_queue(kgd);
return -ETIME;
}
usleep_range(500, 1000);
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
static int kgd_address_watch_disable(struct kgd_dev *kgd)
{
return 0;
}
static int kgd_address_watch_execute(struct kgd_dev *kgd,
unsigned int watch_point_id,
uint32_t cntl_val,
uint32_t addr_hi,
uint32_t addr_lo)
{
return 0;
}
static int kgd_wave_control_execute(struct kgd_dev *kgd,
uint32_t gfx_index_val,
uint32_t sq_cmd)
{
struct amdgpu_device *adev = get_amdgpu_device(kgd);
uint32_t data = 0;
mutex_lock(&adev->grbm_idx_mutex);
WREG32(mmGRBM_GFX_INDEX, gfx_index_val);
WREG32(mmSQ_CMD, sq_cmd);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX,
INSTANCE_BROADCAST_WRITES, 1);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX,
SH_BROADCAST_WRITES, 1);
data = REG_SET_FIELD(data, GRBM_GFX_INDEX,
SE_BROADCAST_WRITES, 1);
WREG32(mmGRBM_GFX_INDEX, data);
mutex_unlock(&adev->grbm_idx_mutex);
return 0;
}
static uint32_t kgd_address_watch_get_offset(struct kgd_dev *kgd,
unsigned int watch_point_id,
unsigned int reg_offset)
{
return 0;
}
static void set_scratch_backing_va(struct kgd_dev *kgd,
uint64_t va, uint32_t vmid)
{
struct amdgpu_device *adev = (struct amdgpu_device *) kgd;
lock_srbm(kgd, 0, 0, 0, vmid);
WREG32(mmSH_HIDDEN_PRIVATE_BASE_VMID, va);
unlock_srbm(kgd);
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
