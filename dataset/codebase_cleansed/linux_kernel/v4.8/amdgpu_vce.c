int amdgpu_vce_sw_init(struct amdgpu_device *adev, unsigned long size)
{
struct amdgpu_ring *ring;
struct amd_sched_rq *rq;
const char *fw_name;
const struct common_firmware_header *hdr;
unsigned ucode_version, version_major, version_minor, binary_id;
int i, r;
switch (adev->asic_type) {
#ifdef CONFIG_DRM_AMDGPU_CIK
case CHIP_BONAIRE:
fw_name = FIRMWARE_BONAIRE;
break;
case CHIP_KAVERI:
fw_name = FIRMWARE_KAVERI;
break;
case CHIP_KABINI:
fw_name = FIRMWARE_KABINI;
break;
case CHIP_HAWAII:
fw_name = FIRMWARE_HAWAII;
break;
case CHIP_MULLINS:
fw_name = FIRMWARE_MULLINS;
break;
#endif
case CHIP_TONGA:
fw_name = FIRMWARE_TONGA;
break;
case CHIP_CARRIZO:
fw_name = FIRMWARE_CARRIZO;
break;
case CHIP_FIJI:
fw_name = FIRMWARE_FIJI;
break;
case CHIP_STONEY:
fw_name = FIRMWARE_STONEY;
break;
case CHIP_POLARIS10:
fw_name = FIRMWARE_POLARIS10;
break;
case CHIP_POLARIS11:
fw_name = FIRMWARE_POLARIS11;
break;
default:
return -EINVAL;
}
r = request_firmware(&adev->vce.fw, fw_name, adev->dev);
if (r) {
dev_err(adev->dev, "amdgpu_vce: Can't load firmware \"%s\"\n",
fw_name);
return r;
}
r = amdgpu_ucode_validate(adev->vce.fw);
if (r) {
dev_err(adev->dev, "amdgpu_vce: Can't validate firmware \"%s\"\n",
fw_name);
release_firmware(adev->vce.fw);
adev->vce.fw = NULL;
return r;
}
hdr = (const struct common_firmware_header *)adev->vce.fw->data;
ucode_version = le32_to_cpu(hdr->ucode_version);
version_major = (ucode_version >> 20) & 0xfff;
version_minor = (ucode_version >> 8) & 0xfff;
binary_id = ucode_version & 0xff;
DRM_INFO("Found VCE firmware Version: %hhd.%hhd Binary ID: %hhd\n",
version_major, version_minor, binary_id);
adev->vce.fw_version = ((version_major << 24) | (version_minor << 16) |
(binary_id << 8));
r = amdgpu_bo_create(adev, size, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL, &adev->vce.vcpu_bo);
if (r) {
dev_err(adev->dev, "(%d) failed to allocate VCE bo\n", r);
return r;
}
r = amdgpu_bo_reserve(adev->vce.vcpu_bo, false);
if (r) {
amdgpu_bo_unref(&adev->vce.vcpu_bo);
dev_err(adev->dev, "(%d) failed to reserve VCE bo\n", r);
return r;
}
r = amdgpu_bo_pin(adev->vce.vcpu_bo, AMDGPU_GEM_DOMAIN_VRAM,
&adev->vce.gpu_addr);
amdgpu_bo_unreserve(adev->vce.vcpu_bo);
if (r) {
amdgpu_bo_unref(&adev->vce.vcpu_bo);
dev_err(adev->dev, "(%d) VCE bo pin failed\n", r);
return r;
}
ring = &adev->vce.ring[0];
rq = &ring->sched.sched_rq[AMD_SCHED_PRIORITY_NORMAL];
r = amd_sched_entity_init(&ring->sched, &adev->vce.entity,
rq, amdgpu_sched_jobs);
if (r != 0) {
DRM_ERROR("Failed setting up VCE run queue.\n");
return r;
}
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i) {
atomic_set(&adev->vce.handles[i], 0);
adev->vce.filp[i] = NULL;
}
INIT_DELAYED_WORK(&adev->vce.idle_work, amdgpu_vce_idle_work_handler);
mutex_init(&adev->vce.idle_mutex);
return 0;
}
int amdgpu_vce_sw_fini(struct amdgpu_device *adev)
{
if (adev->vce.vcpu_bo == NULL)
return 0;
amd_sched_entity_fini(&adev->vce.ring[0].sched, &adev->vce.entity);
amdgpu_bo_unref(&adev->vce.vcpu_bo);
amdgpu_ring_fini(&adev->vce.ring[0]);
amdgpu_ring_fini(&adev->vce.ring[1]);
release_firmware(adev->vce.fw);
mutex_destroy(&adev->vce.idle_mutex);
return 0;
}
int amdgpu_vce_suspend(struct amdgpu_device *adev)
{
int i;
if (adev->vce.vcpu_bo == NULL)
return 0;
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i)
if (atomic_read(&adev->vce.handles[i]))
break;
if (i == AMDGPU_MAX_VCE_HANDLES)
return 0;
cancel_delayed_work_sync(&adev->vce.idle_work);
return -EINVAL;
}
int amdgpu_vce_resume(struct amdgpu_device *adev)
{
void *cpu_addr;
const struct common_firmware_header *hdr;
unsigned offset;
int r;
if (adev->vce.vcpu_bo == NULL)
return -EINVAL;
r = amdgpu_bo_reserve(adev->vce.vcpu_bo, false);
if (r) {
dev_err(adev->dev, "(%d) failed to reserve VCE bo\n", r);
return r;
}
r = amdgpu_bo_kmap(adev->vce.vcpu_bo, &cpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->vce.vcpu_bo);
dev_err(adev->dev, "(%d) VCE map failed\n", r);
return r;
}
hdr = (const struct common_firmware_header *)adev->vce.fw->data;
offset = le32_to_cpu(hdr->ucode_array_offset_bytes);
memcpy(cpu_addr, (adev->vce.fw->data) + offset,
(adev->vce.fw->size) - offset);
amdgpu_bo_kunmap(adev->vce.vcpu_bo);
amdgpu_bo_unreserve(adev->vce.vcpu_bo);
return 0;
}
static void amdgpu_vce_idle_work_handler(struct work_struct *work)
{
struct amdgpu_device *adev =
container_of(work, struct amdgpu_device, vce.idle_work.work);
if ((amdgpu_fence_count_emitted(&adev->vce.ring[0]) == 0) &&
(amdgpu_fence_count_emitted(&adev->vce.ring[1]) == 0)) {
if (adev->pm.dpm_enabled) {
amdgpu_dpm_enable_vce(adev, false);
} else {
amdgpu_asic_set_vce_clocks(adev, 0, 0);
}
} else {
schedule_delayed_work(&adev->vce.idle_work, VCE_IDLE_TIMEOUT);
}
}
void amdgpu_vce_ring_begin_use(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
bool set_clocks;
mutex_lock(&adev->vce.idle_mutex);
set_clocks = !cancel_delayed_work_sync(&adev->vce.idle_work);
if (set_clocks) {
if (adev->pm.dpm_enabled) {
amdgpu_dpm_enable_vce(adev, true);
} else {
amdgpu_asic_set_vce_clocks(adev, 53300, 40000);
}
}
mutex_unlock(&adev->vce.idle_mutex);
}
void amdgpu_vce_ring_end_use(struct amdgpu_ring *ring)
{
schedule_delayed_work(&ring->adev->vce.idle_work, VCE_IDLE_TIMEOUT);
}
void amdgpu_vce_free_handles(struct amdgpu_device *adev, struct drm_file *filp)
{
struct amdgpu_ring *ring = &adev->vce.ring[0];
int i, r;
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i) {
uint32_t handle = atomic_read(&adev->vce.handles[i]);
if (!handle || adev->vce.filp[i] != filp)
continue;
r = amdgpu_vce_get_destroy_msg(ring, handle, false, NULL);
if (r)
DRM_ERROR("Error destroying VCE handle (%d)!\n", r);
adev->vce.filp[i] = NULL;
atomic_set(&adev->vce.handles[i], 0);
}
}
int amdgpu_vce_get_create_msg(struct amdgpu_ring *ring, uint32_t handle,
struct fence **fence)
{
const unsigned ib_size_dw = 1024;
struct amdgpu_job *job;
struct amdgpu_ib *ib;
struct fence *f = NULL;
uint64_t dummy;
int i, r;
r = amdgpu_job_alloc_with_ib(ring->adev, ib_size_dw * 4, &job);
if (r)
return r;
ib = &job->ibs[0];
dummy = ib->gpu_addr + 1024;
ib->length_dw = 0;
ib->ptr[ib->length_dw++] = 0x0000000c;
ib->ptr[ib->length_dw++] = 0x00000001;
ib->ptr[ib->length_dw++] = handle;
if ((ring->adev->vce.fw_version >> 24) >= 52)
ib->ptr[ib->length_dw++] = 0x00000040;
else
ib->ptr[ib->length_dw++] = 0x00000030;
ib->ptr[ib->length_dw++] = 0x01000001;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000042;
ib->ptr[ib->length_dw++] = 0x0000000a;
ib->ptr[ib->length_dw++] = 0x00000001;
ib->ptr[ib->length_dw++] = 0x00000080;
ib->ptr[ib->length_dw++] = 0x00000060;
ib->ptr[ib->length_dw++] = 0x00000100;
ib->ptr[ib->length_dw++] = 0x00000100;
ib->ptr[ib->length_dw++] = 0x0000000c;
ib->ptr[ib->length_dw++] = 0x00000000;
if ((ring->adev->vce.fw_version >> 24) >= 52) {
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000000;
}
ib->ptr[ib->length_dw++] = 0x00000014;
ib->ptr[ib->length_dw++] = 0x05000005;
ib->ptr[ib->length_dw++] = upper_32_bits(dummy);
ib->ptr[ib->length_dw++] = dummy;
ib->ptr[ib->length_dw++] = 0x00000001;
for (i = ib->length_dw; i < ib_size_dw; ++i)
ib->ptr[i] = 0x0;
r = amdgpu_ib_schedule(ring, 1, ib, NULL, NULL, &f);
job->fence = fence_get(f);
if (r)
goto err;
amdgpu_job_free(job);
if (fence)
*fence = fence_get(f);
fence_put(f);
return 0;
err:
amdgpu_job_free(job);
return r;
}
int amdgpu_vce_get_destroy_msg(struct amdgpu_ring *ring, uint32_t handle,
bool direct, struct fence **fence)
{
const unsigned ib_size_dw = 1024;
struct amdgpu_job *job;
struct amdgpu_ib *ib;
struct fence *f = NULL;
int i, r;
r = amdgpu_job_alloc_with_ib(ring->adev, ib_size_dw * 4, &job);
if (r)
return r;
ib = &job->ibs[0];
ib->length_dw = 0;
ib->ptr[ib->length_dw++] = 0x0000000c;
ib->ptr[ib->length_dw++] = 0x00000001;
ib->ptr[ib->length_dw++] = handle;
ib->ptr[ib->length_dw++] = 0x00000020;
ib->ptr[ib->length_dw++] = 0x00000002;
ib->ptr[ib->length_dw++] = 0xffffffff;
ib->ptr[ib->length_dw++] = 0x00000001;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0xffffffff;
ib->ptr[ib->length_dw++] = 0x00000000;
ib->ptr[ib->length_dw++] = 0x00000008;
ib->ptr[ib->length_dw++] = 0x02000001;
for (i = ib->length_dw; i < ib_size_dw; ++i)
ib->ptr[i] = 0x0;
if (direct) {
r = amdgpu_ib_schedule(ring, 1, ib, NULL, NULL, &f);
job->fence = fence_get(f);
if (r)
goto err;
amdgpu_job_free(job);
} else {
r = amdgpu_job_submit(job, ring, &ring->adev->vce.entity,
AMDGPU_FENCE_OWNER_UNDEFINED, &f);
if (r)
goto err;
}
if (fence)
*fence = fence_get(f);
fence_put(f);
return 0;
err:
amdgpu_job_free(job);
return r;
}
static int amdgpu_vce_cs_reloc(struct amdgpu_cs_parser *p, uint32_t ib_idx,
int lo, int hi, unsigned size, uint32_t index)
{
struct amdgpu_bo_va_mapping *mapping;
struct amdgpu_bo *bo;
uint64_t addr;
if (index == 0xffffffff)
index = 0;
addr = ((uint64_t)amdgpu_get_ib_value(p, ib_idx, lo)) |
((uint64_t)amdgpu_get_ib_value(p, ib_idx, hi)) << 32;
addr += ((uint64_t)size) * ((uint64_t)index);
mapping = amdgpu_cs_find_mapping(p, addr, &bo);
if (mapping == NULL) {
DRM_ERROR("Can't find BO for addr 0x%010Lx %d %d %d %d\n",
addr, lo, hi, size, index);
return -EINVAL;
}
if ((addr + (uint64_t)size) >
((uint64_t)mapping->it.last + 1) * AMDGPU_GPU_PAGE_SIZE) {
DRM_ERROR("BO to small for addr 0x%010Lx %d %d\n",
addr, lo, hi);
return -EINVAL;
}
addr -= ((uint64_t)mapping->it.start) * AMDGPU_GPU_PAGE_SIZE;
addr += amdgpu_bo_gpu_offset(bo);
addr -= ((uint64_t)size) * ((uint64_t)index);
amdgpu_set_ib_value(p, ib_idx, lo, lower_32_bits(addr));
amdgpu_set_ib_value(p, ib_idx, hi, upper_32_bits(addr));
return 0;
}
static int amdgpu_vce_validate_handle(struct amdgpu_cs_parser *p,
uint32_t handle, uint32_t *allocated)
{
unsigned i;
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i) {
if (atomic_read(&p->adev->vce.handles[i]) == handle) {
if (p->adev->vce.filp[i] != p->filp) {
DRM_ERROR("VCE handle collision detected!\n");
return -EINVAL;
}
return i;
}
}
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i) {
if (!atomic_cmpxchg(&p->adev->vce.handles[i], 0, handle)) {
p->adev->vce.filp[i] = p->filp;
p->adev->vce.img_size[i] = 0;
*allocated |= 1 << i;
return i;
}
}
DRM_ERROR("No more free VCE handles!\n");
return -EINVAL;
}
int amdgpu_vce_ring_parse_cs(struct amdgpu_cs_parser *p, uint32_t ib_idx)
{
struct amdgpu_ib *ib = &p->job->ibs[ib_idx];
unsigned fb_idx = 0, bs_idx = 0;
int session_idx = -1;
uint32_t destroyed = 0;
uint32_t created = 0;
uint32_t allocated = 0;
uint32_t tmp, handle = 0;
uint32_t *size = &tmp;
int i, r = 0, idx = 0;
while (idx < ib->length_dw) {
uint32_t len = amdgpu_get_ib_value(p, ib_idx, idx);
uint32_t cmd = amdgpu_get_ib_value(p, ib_idx, idx + 1);
if ((len < 8) || (len & 3)) {
DRM_ERROR("invalid VCE command length (%d)!\n", len);
r = -EINVAL;
goto out;
}
switch (cmd) {
case 0x00000001:
handle = amdgpu_get_ib_value(p, ib_idx, idx + 2);
session_idx = amdgpu_vce_validate_handle(p, handle,
&allocated);
if (session_idx < 0) {
r = session_idx;
goto out;
}
size = &p->adev->vce.img_size[session_idx];
break;
case 0x00000002:
fb_idx = amdgpu_get_ib_value(p, ib_idx, idx + 6);
bs_idx = amdgpu_get_ib_value(p, ib_idx, idx + 7);
break;
case 0x01000001:
created |= 1 << session_idx;
if (destroyed & (1 << session_idx)) {
destroyed &= ~(1 << session_idx);
allocated |= 1 << session_idx;
} else if (!(allocated & (1 << session_idx))) {
DRM_ERROR("Handle already in use!\n");
r = -EINVAL;
goto out;
}
*size = amdgpu_get_ib_value(p, ib_idx, idx + 8) *
amdgpu_get_ib_value(p, ib_idx, idx + 10) *
8 * 3 / 2;
break;
case 0x04000001:
case 0x04000002:
case 0x04000005:
case 0x04000007:
case 0x04000008:
case 0x04000009:
case 0x05000002:
break;
case 0x03000001:
r = amdgpu_vce_cs_reloc(p, ib_idx, idx + 10, idx + 9,
*size, 0);
if (r)
goto out;
r = amdgpu_vce_cs_reloc(p, ib_idx, idx + 12, idx + 11,
*size / 3, 0);
if (r)
goto out;
break;
case 0x02000001:
destroyed |= 1 << session_idx;
break;
case 0x05000001:
r = amdgpu_vce_cs_reloc(p, ib_idx, idx + 3, idx + 2,
*size * 2, 0);
if (r)
goto out;
break;
case 0x05000004:
tmp = amdgpu_get_ib_value(p, ib_idx, idx + 4);
r = amdgpu_vce_cs_reloc(p, ib_idx, idx + 3, idx + 2,
tmp, bs_idx);
if (r)
goto out;
break;
case 0x05000005:
r = amdgpu_vce_cs_reloc(p, ib_idx, idx + 3, idx + 2,
4096, fb_idx);
if (r)
goto out;
break;
default:
DRM_ERROR("invalid VCE command (0x%x)!\n", cmd);
r = -EINVAL;
goto out;
}
if (session_idx == -1) {
DRM_ERROR("no session command at start of IB\n");
r = -EINVAL;
goto out;
}
idx += len / 4;
}
if (allocated & ~created) {
DRM_ERROR("New session without create command!\n");
r = -ENOENT;
}
out:
if (!r) {
tmp = destroyed;
} else {
tmp = allocated;
}
for (i = 0; i < AMDGPU_MAX_VCE_HANDLES; ++i)
if (tmp & (1 << i))
atomic_set(&p->adev->vce.handles[i], 0);
return r;
}
void amdgpu_vce_ring_emit_ib(struct amdgpu_ring *ring, struct amdgpu_ib *ib,
unsigned vm_id, bool ctx_switch)
{
amdgpu_ring_write(ring, VCE_CMD_IB);
amdgpu_ring_write(ring, lower_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr));
amdgpu_ring_write(ring, ib->length_dw);
}
void amdgpu_vce_ring_emit_fence(struct amdgpu_ring *ring, u64 addr, u64 seq,
unsigned flags)
{
WARN_ON(flags & AMDGPU_FENCE_FLAG_64BIT);
amdgpu_ring_write(ring, VCE_CMD_FENCE);
amdgpu_ring_write(ring, addr);
amdgpu_ring_write(ring, upper_32_bits(addr));
amdgpu_ring_write(ring, seq);
amdgpu_ring_write(ring, VCE_CMD_TRAP);
amdgpu_ring_write(ring, VCE_CMD_END);
}
int amdgpu_vce_ring_test_ring(struct amdgpu_ring *ring)
{
struct amdgpu_device *adev = ring->adev;
uint32_t rptr = amdgpu_ring_get_rptr(ring);
unsigned i;
int r;
r = amdgpu_ring_alloc(ring, 16);
if (r) {
DRM_ERROR("amdgpu: vce failed to lock ring %d (%d).\n",
ring->idx, r);
return r;
}
amdgpu_ring_write(ring, VCE_CMD_END);
amdgpu_ring_commit(ring);
for (i = 0; i < adev->usec_timeout; i++) {
if (amdgpu_ring_get_rptr(ring) != rptr)
break;
DRM_UDELAY(1);
}
if (i < adev->usec_timeout) {
DRM_INFO("ring test on %d succeeded in %d usecs\n",
ring->idx, i);
} else {
DRM_ERROR("amdgpu: ring %d test failed\n",
ring->idx);
r = -ETIMEDOUT;
}
return r;
}
int amdgpu_vce_ring_test_ib(struct amdgpu_ring *ring, long timeout)
{
struct fence *fence = NULL;
long r;
if (ring == &ring->adev->vce.ring[1])
return 0;
r = amdgpu_vce_get_create_msg(ring, 1, NULL);
if (r) {
DRM_ERROR("amdgpu: failed to get create msg (%ld).\n", r);
goto error;
}
r = amdgpu_vce_get_destroy_msg(ring, 1, true, &fence);
if (r) {
DRM_ERROR("amdgpu: failed to get destroy ib (%ld).\n", r);
goto error;
}
r = fence_wait_timeout(fence, false, timeout);
if (r == 0) {
DRM_ERROR("amdgpu: IB test timed out.\n");
r = -ETIMEDOUT;
} else if (r < 0) {
DRM_ERROR("amdgpu: fence wait failed (%ld).\n", r);
} else {
DRM_INFO("ib test on ring %d succeeded\n", ring->idx);
r = 0;
}
error:
fence_put(fence);
return r;
}
