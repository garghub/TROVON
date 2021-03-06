int amdgpu_uvd_sw_init(struct amdgpu_device *adev)
{
unsigned long bo_size;
const char *fw_name;
const struct common_firmware_header *hdr;
unsigned version_major, version_minor, family_id;
int i, r;
INIT_DELAYED_WORK(&adev->uvd.idle_work, amdgpu_uvd_idle_work_handler);
switch (adev->asic_type) {
#ifdef CONFIG_DRM_AMDGPU_CIK
case CHIP_BONAIRE:
fw_name = FIRMWARE_BONAIRE;
break;
case CHIP_KABINI:
fw_name = FIRMWARE_KABINI;
break;
case CHIP_KAVERI:
fw_name = FIRMWARE_KAVERI;
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
default:
return -EINVAL;
}
r = request_firmware(&adev->uvd.fw, fw_name, adev->dev);
if (r) {
dev_err(adev->dev, "amdgpu_uvd: Can't load firmware \"%s\"\n",
fw_name);
return r;
}
r = amdgpu_ucode_validate(adev->uvd.fw);
if (r) {
dev_err(adev->dev, "amdgpu_uvd: Can't validate firmware \"%s\"\n",
fw_name);
release_firmware(adev->uvd.fw);
adev->uvd.fw = NULL;
return r;
}
hdr = (const struct common_firmware_header *)adev->uvd.fw->data;
family_id = le32_to_cpu(hdr->ucode_version) & 0xff;
version_major = (le32_to_cpu(hdr->ucode_version) >> 24) & 0xff;
version_minor = (le32_to_cpu(hdr->ucode_version) >> 8) & 0xff;
DRM_INFO("Found UVD firmware Version: %hu.%hu Family ID: %hu\n",
version_major, version_minor, family_id);
bo_size = AMDGPU_GPU_PAGE_ALIGN(le32_to_cpu(hdr->ucode_size_bytes) + 8)
+ AMDGPU_UVD_STACK_SIZE + AMDGPU_UVD_HEAP_SIZE;
r = amdgpu_bo_create(adev, bo_size, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM, 0, NULL, &adev->uvd.vcpu_bo);
if (r) {
dev_err(adev->dev, "(%d) failed to allocate UVD bo\n", r);
return r;
}
r = amdgpu_bo_reserve(adev->uvd.vcpu_bo, false);
if (r) {
amdgpu_bo_unref(&adev->uvd.vcpu_bo);
dev_err(adev->dev, "(%d) failed to reserve UVD bo\n", r);
return r;
}
r = amdgpu_bo_pin(adev->uvd.vcpu_bo, AMDGPU_GEM_DOMAIN_VRAM,
&adev->uvd.gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->uvd.vcpu_bo);
amdgpu_bo_unref(&adev->uvd.vcpu_bo);
dev_err(adev->dev, "(%d) UVD bo pin failed\n", r);
return r;
}
r = amdgpu_bo_kmap(adev->uvd.vcpu_bo, &adev->uvd.cpu_addr);
if (r) {
dev_err(adev->dev, "(%d) UVD map failed\n", r);
return r;
}
amdgpu_bo_unreserve(adev->uvd.vcpu_bo);
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i) {
atomic_set(&adev->uvd.handles[i], 0);
adev->uvd.filp[i] = NULL;
}
if (!amdgpu_ip_block_version_cmp(adev, AMD_IP_BLOCK_TYPE_UVD, 5, 0))
adev->uvd.address_64_bit = true;
return 0;
}
int amdgpu_uvd_sw_fini(struct amdgpu_device *adev)
{
int r;
if (adev->uvd.vcpu_bo == NULL)
return 0;
r = amdgpu_bo_reserve(adev->uvd.vcpu_bo, false);
if (!r) {
amdgpu_bo_kunmap(adev->uvd.vcpu_bo);
amdgpu_bo_unpin(adev->uvd.vcpu_bo);
amdgpu_bo_unreserve(adev->uvd.vcpu_bo);
}
amdgpu_bo_unref(&adev->uvd.vcpu_bo);
amdgpu_ring_fini(&adev->uvd.ring);
release_firmware(adev->uvd.fw);
return 0;
}
int amdgpu_uvd_suspend(struct amdgpu_device *adev)
{
unsigned size;
void *ptr;
const struct common_firmware_header *hdr;
int i;
if (adev->uvd.vcpu_bo == NULL)
return 0;
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i)
if (atomic_read(&adev->uvd.handles[i]))
break;
if (i == AMDGPU_MAX_UVD_HANDLES)
return 0;
hdr = (const struct common_firmware_header *)adev->uvd.fw->data;
size = amdgpu_bo_size(adev->uvd.vcpu_bo);
size -= le32_to_cpu(hdr->ucode_size_bytes);
ptr = adev->uvd.cpu_addr;
ptr += le32_to_cpu(hdr->ucode_size_bytes);
adev->uvd.saved_bo = kmalloc(size, GFP_KERNEL);
memcpy(adev->uvd.saved_bo, ptr, size);
return 0;
}
int amdgpu_uvd_resume(struct amdgpu_device *adev)
{
unsigned size;
void *ptr;
const struct common_firmware_header *hdr;
unsigned offset;
if (adev->uvd.vcpu_bo == NULL)
return -EINVAL;
hdr = (const struct common_firmware_header *)adev->uvd.fw->data;
offset = le32_to_cpu(hdr->ucode_array_offset_bytes);
memcpy(adev->uvd.cpu_addr, (adev->uvd.fw->data) + offset,
(adev->uvd.fw->size) - offset);
size = amdgpu_bo_size(adev->uvd.vcpu_bo);
size -= le32_to_cpu(hdr->ucode_size_bytes);
ptr = adev->uvd.cpu_addr;
ptr += le32_to_cpu(hdr->ucode_size_bytes);
if (adev->uvd.saved_bo != NULL) {
memcpy(ptr, adev->uvd.saved_bo, size);
kfree(adev->uvd.saved_bo);
adev->uvd.saved_bo = NULL;
} else
memset(ptr, 0, size);
return 0;
}
void amdgpu_uvd_free_handles(struct amdgpu_device *adev, struct drm_file *filp)
{
struct amdgpu_ring *ring = &adev->uvd.ring;
int i, r;
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i) {
uint32_t handle = atomic_read(&adev->uvd.handles[i]);
if (handle != 0 && adev->uvd.filp[i] == filp) {
struct amdgpu_fence *fence;
amdgpu_uvd_note_usage(adev);
r = amdgpu_uvd_get_destroy_msg(ring, handle, &fence);
if (r) {
DRM_ERROR("Error destroying UVD (%d)!\n", r);
continue;
}
amdgpu_fence_wait(fence, false);
amdgpu_fence_unref(&fence);
adev->uvd.filp[i] = NULL;
atomic_set(&adev->uvd.handles[i], 0);
}
}
}
static void amdgpu_uvd_force_into_uvd_segment(struct amdgpu_bo *rbo)
{
int i;
for (i = 0; i < rbo->placement.num_placement; ++i) {
rbo->placements[i].fpfn = 0 >> PAGE_SHIFT;
rbo->placements[i].lpfn = (256 * 1024 * 1024) >> PAGE_SHIFT;
}
}
static int amdgpu_uvd_cs_pass1(struct amdgpu_uvd_cs_ctx *ctx)
{
struct amdgpu_bo_va_mapping *mapping;
struct amdgpu_bo *bo;
uint32_t cmd, lo, hi;
uint64_t addr;
int r = 0;
lo = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->data0);
hi = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->data1);
addr = ((uint64_t)lo) | (((uint64_t)hi) << 32);
mapping = amdgpu_cs_find_mapping(ctx->parser, addr, &bo);
if (mapping == NULL) {
DRM_ERROR("Can't find BO for addr 0x%08Lx\n", addr);
return -EINVAL;
}
if (!ctx->parser->adev->uvd.address_64_bit) {
cmd = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->idx) >> 1;
if (cmd == 0x0 || cmd == 0x3) {
uint32_t domain = AMDGPU_GEM_DOMAIN_VRAM;
amdgpu_ttm_placement_from_domain(bo, domain);
}
amdgpu_uvd_force_into_uvd_segment(bo);
r = ttm_bo_validate(&bo->tbo, &bo->placement, false, false);
}
return r;
}
static int amdgpu_uvd_cs_msg_decode(uint32_t *msg, unsigned buf_sizes[])
{
unsigned stream_type = msg[4];
unsigned width = msg[6];
unsigned height = msg[7];
unsigned dpb_size = msg[9];
unsigned pitch = msg[28];
unsigned level = msg[57];
unsigned width_in_mb = width / 16;
unsigned height_in_mb = ALIGN(height / 16, 2);
unsigned fs_in_mb = width_in_mb * height_in_mb;
unsigned image_size, tmp, min_dpb_size, num_dpb_buffer, min_ctx_size;
image_size = width * height;
image_size += image_size / 2;
image_size = ALIGN(image_size, 1024);
switch (stream_type) {
case 0:
case 7:
switch(level) {
case 30:
num_dpb_buffer = 8100 / fs_in_mb;
break;
case 31:
num_dpb_buffer = 18000 / fs_in_mb;
break;
case 32:
num_dpb_buffer = 20480 / fs_in_mb;
break;
case 41:
num_dpb_buffer = 32768 / fs_in_mb;
break;
case 42:
num_dpb_buffer = 34816 / fs_in_mb;
break;
case 50:
num_dpb_buffer = 110400 / fs_in_mb;
break;
case 51:
num_dpb_buffer = 184320 / fs_in_mb;
break;
default:
num_dpb_buffer = 184320 / fs_in_mb;
break;
}
num_dpb_buffer++;
if (num_dpb_buffer > 17)
num_dpb_buffer = 17;
min_dpb_size = image_size * num_dpb_buffer;
min_dpb_size += width_in_mb * height_in_mb * num_dpb_buffer * 192;
min_dpb_size += width_in_mb * height_in_mb * 32;
break;
case 1:
min_dpb_size = image_size * 3;
min_dpb_size += width_in_mb * height_in_mb * 128;
min_dpb_size += width_in_mb * 64;
min_dpb_size += width_in_mb * 128;
tmp = max(width_in_mb, height_in_mb);
min_dpb_size += ALIGN(tmp * 7 * 16, 64);
break;
case 3:
min_dpb_size = image_size * 3;
break;
case 4:
min_dpb_size = image_size * 3;
min_dpb_size += width_in_mb * height_in_mb * 64;
min_dpb_size += ALIGN(width_in_mb * height_in_mb * 32, 64);
break;
case 16:
image_size = (ALIGN(width, 16) * ALIGN(height, 16) * 3) / 2;
image_size = ALIGN(image_size, 256);
num_dpb_buffer = (le32_to_cpu(msg[59]) & 0xff) + 2;
min_dpb_size = image_size * num_dpb_buffer;
min_ctx_size = ((width + 255) / 16) * ((height + 255) / 16)
* 16 * num_dpb_buffer + 52 * 1024;
break;
default:
DRM_ERROR("UVD codec not handled %d!\n", stream_type);
return -EINVAL;
}
if (width > pitch) {
DRM_ERROR("Invalid UVD decoding target pitch!\n");
return -EINVAL;
}
if (dpb_size < min_dpb_size) {
DRM_ERROR("Invalid dpb_size in UVD message (%d / %d)!\n",
dpb_size, min_dpb_size);
return -EINVAL;
}
buf_sizes[0x1] = dpb_size;
buf_sizes[0x2] = image_size;
buf_sizes[0x4] = min_ctx_size;
return 0;
}
static int amdgpu_uvd_cs_msg(struct amdgpu_uvd_cs_ctx *ctx,
struct amdgpu_bo *bo, unsigned offset)
{
struct amdgpu_device *adev = ctx->parser->adev;
int32_t *msg, msg_type, handle;
struct fence *f;
void *ptr;
int i, r;
if (offset & 0x3F) {
DRM_ERROR("UVD messages must be 64 byte aligned!\n");
return -EINVAL;
}
f = reservation_object_get_excl(bo->tbo.resv);
if (f) {
r = amdgpu_fence_wait((struct amdgpu_fence *)f, false);
if (r) {
DRM_ERROR("Failed waiting for UVD message (%d)!\n", r);
return r;
}
}
r = amdgpu_bo_kmap(bo, &ptr);
if (r) {
DRM_ERROR("Failed mapping the UVD message (%d)!\n", r);
return r;
}
msg = ptr + offset;
msg_type = msg[1];
handle = msg[2];
if (handle == 0) {
DRM_ERROR("Invalid UVD handle!\n");
return -EINVAL;
}
if (msg_type == 1) {
r = amdgpu_uvd_cs_msg_decode(msg, ctx->buf_sizes);
amdgpu_bo_kunmap(bo);
if (r)
return r;
} else if (msg_type == 2) {
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i)
atomic_cmpxchg(&adev->uvd.handles[i], handle, 0);
amdgpu_bo_kunmap(bo);
return 0;
} else {
amdgpu_bo_kunmap(bo);
if (msg_type != 0) {
DRM_ERROR("Illegal UVD message type (%d)!\n", msg_type);
return -EINVAL;
}
}
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i) {
if (atomic_read(&adev->uvd.handles[i]) == handle)
return 0;
}
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i) {
if (!atomic_cmpxchg(&adev->uvd.handles[i], 0, handle)) {
adev->uvd.filp[i] = ctx->parser->filp;
return 0;
}
}
DRM_ERROR("No more free UVD handles!\n");
return -EINVAL;
}
static int amdgpu_uvd_cs_pass2(struct amdgpu_uvd_cs_ctx *ctx)
{
struct amdgpu_bo_va_mapping *mapping;
struct amdgpu_bo *bo;
struct amdgpu_ib *ib;
uint32_t cmd, lo, hi;
uint64_t start, end;
uint64_t addr;
int r;
lo = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->data0);
hi = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->data1);
addr = ((uint64_t)lo) | (((uint64_t)hi) << 32);
mapping = amdgpu_cs_find_mapping(ctx->parser, addr, &bo);
if (mapping == NULL)
return -EINVAL;
start = amdgpu_bo_gpu_offset(bo);
end = (mapping->it.last + 1 - mapping->it.start);
end = end * AMDGPU_GPU_PAGE_SIZE + start;
addr -= ((uint64_t)mapping->it.start) * AMDGPU_GPU_PAGE_SIZE;
start += addr;
ib = &ctx->parser->ibs[ctx->ib_idx];
ib->ptr[ctx->data0] = start & 0xFFFFFFFF;
ib->ptr[ctx->data1] = start >> 32;
cmd = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->idx) >> 1;
if (cmd < 0x4) {
if ((end - start) < ctx->buf_sizes[cmd]) {
DRM_ERROR("buffer (%d) to small (%d / %d)!\n", cmd,
(unsigned)(end - start),
ctx->buf_sizes[cmd]);
return -EINVAL;
}
} else if (cmd == 0x206) {
if ((end - start) < ctx->buf_sizes[4]) {
DRM_ERROR("buffer (%d) to small (%d / %d)!\n", cmd,
(unsigned)(end - start),
ctx->buf_sizes[4]);
return -EINVAL;
}
} else if ((cmd != 0x100) && (cmd != 0x204)) {
DRM_ERROR("invalid UVD command %X!\n", cmd);
return -EINVAL;
}
if (!ctx->parser->adev->uvd.address_64_bit) {
if ((start >> 28) != ((end - 1) >> 28)) {
DRM_ERROR("reloc %LX-%LX crossing 256MB boundary!\n",
start, end);
return -EINVAL;
}
if ((cmd == 0 || cmd == 0x3) &&
(start >> 28) != (ctx->parser->adev->uvd.gpu_addr >> 28)) {
DRM_ERROR("msg/fb buffer %LX-%LX out of 256MB segment!\n",
start, end);
return -EINVAL;
}
}
if (cmd == 0) {
ctx->has_msg_cmd = true;
r = amdgpu_uvd_cs_msg(ctx, bo, addr);
if (r)
return r;
} else if (!ctx->has_msg_cmd) {
DRM_ERROR("Message needed before other commands are send!\n");
return -EINVAL;
}
return 0;
}
static int amdgpu_uvd_cs_reg(struct amdgpu_uvd_cs_ctx *ctx,
int (*cb)(struct amdgpu_uvd_cs_ctx *ctx))
{
struct amdgpu_ib *ib = &ctx->parser->ibs[ctx->ib_idx];
int i, r;
ctx->idx++;
for (i = 0; i <= ctx->count; ++i) {
unsigned reg = ctx->reg + i;
if (ctx->idx >= ib->length_dw) {
DRM_ERROR("Register command after end of CS!\n");
return -EINVAL;
}
switch (reg) {
case mmUVD_GPCOM_VCPU_DATA0:
ctx->data0 = ctx->idx;
break;
case mmUVD_GPCOM_VCPU_DATA1:
ctx->data1 = ctx->idx;
break;
case mmUVD_GPCOM_VCPU_CMD:
r = cb(ctx);
if (r)
return r;
break;
case mmUVD_ENGINE_CNTL:
break;
default:
DRM_ERROR("Invalid reg 0x%X!\n", reg);
return -EINVAL;
}
ctx->idx++;
}
return 0;
}
static int amdgpu_uvd_cs_packets(struct amdgpu_uvd_cs_ctx *ctx,
int (*cb)(struct amdgpu_uvd_cs_ctx *ctx))
{
struct amdgpu_ib *ib = &ctx->parser->ibs[ctx->ib_idx];
int r;
for (ctx->idx = 0 ; ctx->idx < ib->length_dw; ) {
uint32_t cmd = amdgpu_get_ib_value(ctx->parser, ctx->ib_idx, ctx->idx);
unsigned type = CP_PACKET_GET_TYPE(cmd);
switch (type) {
case PACKET_TYPE0:
ctx->reg = CP_PACKET0_GET_REG(cmd);
ctx->count = CP_PACKET_GET_COUNT(cmd);
r = amdgpu_uvd_cs_reg(ctx, cb);
if (r)
return r;
break;
case PACKET_TYPE2:
++ctx->idx;
break;
default:
DRM_ERROR("Unknown packet type %d !\n", type);
return -EINVAL;
}
}
return 0;
}
int amdgpu_uvd_ring_parse_cs(struct amdgpu_cs_parser *parser, uint32_t ib_idx)
{
struct amdgpu_uvd_cs_ctx ctx = {};
unsigned buf_sizes[] = {
[0x00000000] = 2048,
[0x00000001] = 0xFFFFFFFF,
[0x00000002] = 0xFFFFFFFF,
[0x00000003] = 2048,
[0x00000004] = 0xFFFFFFFF,
};
struct amdgpu_ib *ib = &parser->ibs[ib_idx];
int r;
if (ib->length_dw % 16) {
DRM_ERROR("UVD IB length (%d) not 16 dwords aligned!\n",
ib->length_dw);
return -EINVAL;
}
ctx.parser = parser;
ctx.buf_sizes = buf_sizes;
ctx.ib_idx = ib_idx;
r = amdgpu_uvd_cs_packets(&ctx, amdgpu_uvd_cs_pass1);
if (r)
return r;
r = amdgpu_uvd_cs_packets(&ctx, amdgpu_uvd_cs_pass2);
if (r)
return r;
if (!ctx.has_msg_cmd) {
DRM_ERROR("UVD-IBs need a msg command!\n");
return -EINVAL;
}
amdgpu_uvd_note_usage(ctx.parser->adev);
return 0;
}
static int amdgpu_uvd_send_msg(struct amdgpu_ring *ring,
struct amdgpu_bo *bo,
struct amdgpu_fence **fence)
{
struct ttm_validate_buffer tv;
struct ww_acquire_ctx ticket;
struct list_head head;
struct amdgpu_ib ib;
uint64_t addr;
int i, r;
memset(&tv, 0, sizeof(tv));
tv.bo = &bo->tbo;
INIT_LIST_HEAD(&head);
list_add(&tv.head, &head);
r = ttm_eu_reserve_buffers(&ticket, &head, true, NULL);
if (r)
return r;
if (!bo->adev->uvd.address_64_bit) {
amdgpu_ttm_placement_from_domain(bo, AMDGPU_GEM_DOMAIN_VRAM);
amdgpu_uvd_force_into_uvd_segment(bo);
}
r = ttm_bo_validate(&bo->tbo, &bo->placement, true, false);
if (r)
goto err;
r = amdgpu_ib_get(ring, NULL, 64, &ib);
if (r)
goto err;
addr = amdgpu_bo_gpu_offset(bo);
ib.ptr[0] = PACKET0(mmUVD_GPCOM_VCPU_DATA0, 0);
ib.ptr[1] = addr;
ib.ptr[2] = PACKET0(mmUVD_GPCOM_VCPU_DATA1, 0);
ib.ptr[3] = addr >> 32;
ib.ptr[4] = PACKET0(mmUVD_GPCOM_VCPU_CMD, 0);
ib.ptr[5] = 0;
for (i = 6; i < 16; ++i)
ib.ptr[i] = PACKET2(0);
ib.length_dw = 16;
r = amdgpu_ib_schedule(ring->adev, 1, &ib, AMDGPU_FENCE_OWNER_UNDEFINED);
if (r)
goto err;
ttm_eu_fence_buffer_objects(&ticket, &head, &ib.fence->base);
if (fence)
*fence = amdgpu_fence_ref(ib.fence);
amdgpu_ib_free(ring->adev, &ib);
amdgpu_bo_unref(&bo);
return 0;
err:
ttm_eu_backoff_reservation(&ticket, &head);
return r;
}
int amdgpu_uvd_get_create_msg(struct amdgpu_ring *ring, uint32_t handle,
struct amdgpu_fence **fence)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_bo *bo;
uint32_t *msg;
int r, i;
r = amdgpu_bo_create(adev, 1024, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM, 0, NULL, &bo);
if (r)
return r;
r = amdgpu_bo_reserve(bo, false);
if (r) {
amdgpu_bo_unref(&bo);
return r;
}
r = amdgpu_bo_kmap(bo, (void **)&msg);
if (r) {
amdgpu_bo_unreserve(bo);
amdgpu_bo_unref(&bo);
return r;
}
msg[0] = cpu_to_le32(0x00000de4);
msg[1] = cpu_to_le32(0x00000000);
msg[2] = cpu_to_le32(handle);
msg[3] = cpu_to_le32(0x00000000);
msg[4] = cpu_to_le32(0x00000000);
msg[5] = cpu_to_le32(0x00000000);
msg[6] = cpu_to_le32(0x00000000);
msg[7] = cpu_to_le32(0x00000780);
msg[8] = cpu_to_le32(0x00000440);
msg[9] = cpu_to_le32(0x00000000);
msg[10] = cpu_to_le32(0x01b37000);
for (i = 11; i < 1024; ++i)
msg[i] = cpu_to_le32(0x0);
amdgpu_bo_kunmap(bo);
amdgpu_bo_unreserve(bo);
return amdgpu_uvd_send_msg(ring, bo, fence);
}
int amdgpu_uvd_get_destroy_msg(struct amdgpu_ring *ring, uint32_t handle,
struct amdgpu_fence **fence)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_bo *bo;
uint32_t *msg;
int r, i;
r = amdgpu_bo_create(adev, 1024, PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM, 0, NULL, &bo);
if (r)
return r;
r = amdgpu_bo_reserve(bo, false);
if (r) {
amdgpu_bo_unref(&bo);
return r;
}
r = amdgpu_bo_kmap(bo, (void **)&msg);
if (r) {
amdgpu_bo_unreserve(bo);
amdgpu_bo_unref(&bo);
return r;
}
msg[0] = cpu_to_le32(0x00000de4);
msg[1] = cpu_to_le32(0x00000002);
msg[2] = cpu_to_le32(handle);
msg[3] = cpu_to_le32(0x00000000);
for (i = 4; i < 1024; ++i)
msg[i] = cpu_to_le32(0x0);
amdgpu_bo_kunmap(bo);
amdgpu_bo_unreserve(bo);
return amdgpu_uvd_send_msg(ring, bo, fence);
}
static void amdgpu_uvd_idle_work_handler(struct work_struct *work)
{
struct amdgpu_device *adev =
container_of(work, struct amdgpu_device, uvd.idle_work.work);
unsigned i, fences, handles = 0;
fences = amdgpu_fence_count_emitted(&adev->uvd.ring);
for (i = 0; i < AMDGPU_MAX_UVD_HANDLES; ++i)
if (atomic_read(&adev->uvd.handles[i]))
++handles;
if (fences == 0 && handles == 0) {
if (adev->pm.dpm_enabled) {
amdgpu_dpm_enable_uvd(adev, false);
} else {
amdgpu_asic_set_uvd_clocks(adev, 0, 0);
}
} else {
schedule_delayed_work(&adev->uvd.idle_work,
msecs_to_jiffies(UVD_IDLE_TIMEOUT_MS));
}
}
static void amdgpu_uvd_note_usage(struct amdgpu_device *adev)
{
bool set_clocks = !cancel_delayed_work_sync(&adev->uvd.idle_work);
set_clocks &= schedule_delayed_work(&adev->uvd.idle_work,
msecs_to_jiffies(UVD_IDLE_TIMEOUT_MS));
if (set_clocks) {
if (adev->pm.dpm_enabled) {
amdgpu_dpm_enable_uvd(adev, true);
} else {
amdgpu_asic_set_uvd_clocks(adev, 53300, 40000);
}
}
}
