static int amdgpu_queue_mapper_init(struct amdgpu_queue_mapper *mapper,
int hw_ip)
{
if (!mapper)
return -EINVAL;
if (hw_ip > AMDGPU_MAX_IP_NUM)
return -EINVAL;
mapper->hw_ip = hw_ip;
mutex_init(&mapper->lock);
memset(mapper->queue_map, 0, sizeof(mapper->queue_map));
return 0;
}
static struct amdgpu_ring *amdgpu_get_cached_map(struct amdgpu_queue_mapper *mapper,
int ring)
{
return mapper->queue_map[ring];
}
static int amdgpu_update_cached_map(struct amdgpu_queue_mapper *mapper,
int ring, struct amdgpu_ring *pring)
{
if (WARN_ON(mapper->queue_map[ring])) {
DRM_ERROR("Un-expected ring re-map\n");
return -EINVAL;
}
mapper->queue_map[ring] = pring;
return 0;
}
static int amdgpu_identity_map(struct amdgpu_device *adev,
struct amdgpu_queue_mapper *mapper,
int ring,
struct amdgpu_ring **out_ring)
{
switch (mapper->hw_ip) {
case AMDGPU_HW_IP_GFX:
*out_ring = &adev->gfx.gfx_ring[ring];
break;
case AMDGPU_HW_IP_COMPUTE:
*out_ring = &adev->gfx.compute_ring[ring];
break;
case AMDGPU_HW_IP_DMA:
*out_ring = &adev->sdma.instance[ring].ring;
break;
case AMDGPU_HW_IP_UVD:
*out_ring = &adev->uvd.ring;
break;
case AMDGPU_HW_IP_VCE:
*out_ring = &adev->vce.ring[ring];
break;
case AMDGPU_HW_IP_UVD_ENC:
*out_ring = &adev->uvd.ring_enc[ring];
break;
case AMDGPU_HW_IP_VCN_DEC:
*out_ring = &adev->vcn.ring_dec;
break;
case AMDGPU_HW_IP_VCN_ENC:
*out_ring = &adev->vcn.ring_enc[ring];
break;
default:
*out_ring = NULL;
DRM_ERROR("unknown HW IP type: %d\n", mapper->hw_ip);
return -EINVAL;
}
return amdgpu_update_cached_map(mapper, ring, *out_ring);
}
static enum amdgpu_ring_type amdgpu_hw_ip_to_ring_type(int hw_ip)
{
switch (hw_ip) {
case AMDGPU_HW_IP_GFX:
return AMDGPU_RING_TYPE_GFX;
case AMDGPU_HW_IP_COMPUTE:
return AMDGPU_RING_TYPE_COMPUTE;
case AMDGPU_HW_IP_DMA:
return AMDGPU_RING_TYPE_SDMA;
case AMDGPU_HW_IP_UVD:
return AMDGPU_RING_TYPE_UVD;
case AMDGPU_HW_IP_VCE:
return AMDGPU_RING_TYPE_VCE;
default:
DRM_ERROR("Invalid HW IP specified %d\n", hw_ip);
return -1;
}
}
static int amdgpu_lru_map(struct amdgpu_device *adev,
struct amdgpu_queue_mapper *mapper,
int user_ring,
struct amdgpu_ring **out_ring)
{
int r, i, j;
int ring_type = amdgpu_hw_ip_to_ring_type(mapper->hw_ip);
int ring_blacklist[AMDGPU_MAX_RINGS];
struct amdgpu_ring *ring;
memset(ring_blacklist, 0xff, sizeof(ring_blacklist));
for (i = 0, j = 0; i < AMDGPU_MAX_RINGS; i++) {
ring = mapper->queue_map[i];
if (ring)
ring_blacklist[j++] = ring->idx;
}
r = amdgpu_ring_lru_get(adev, ring_type, ring_blacklist,
j, out_ring);
if (r)
return r;
return amdgpu_update_cached_map(mapper, user_ring, *out_ring);
}
int amdgpu_queue_mgr_init(struct amdgpu_device *adev,
struct amdgpu_queue_mgr *mgr)
{
int i, r;
if (!adev || !mgr)
return -EINVAL;
memset(mgr, 0, sizeof(*mgr));
for (i = 0; i < AMDGPU_MAX_IP_NUM; ++i) {
r = amdgpu_queue_mapper_init(&mgr->mapper[i], i);
if (r)
return r;
}
return 0;
}
int amdgpu_queue_mgr_fini(struct amdgpu_device *adev,
struct amdgpu_queue_mgr *mgr)
{
return 0;
}
int amdgpu_queue_mgr_map(struct amdgpu_device *adev,
struct amdgpu_queue_mgr *mgr,
int hw_ip, int instance, int ring,
struct amdgpu_ring **out_ring)
{
int r, ip_num_rings;
struct amdgpu_queue_mapper *mapper = &mgr->mapper[hw_ip];
if (!adev || !mgr || !out_ring)
return -EINVAL;
if (hw_ip >= AMDGPU_MAX_IP_NUM)
return -EINVAL;
if (ring >= AMDGPU_MAX_RINGS)
return -EINVAL;
if (instance != 0) {
DRM_ERROR("invalid ip instance: %d\n", instance);
return -EINVAL;
}
switch (hw_ip) {
case AMDGPU_HW_IP_GFX:
ip_num_rings = adev->gfx.num_gfx_rings;
break;
case AMDGPU_HW_IP_COMPUTE:
ip_num_rings = adev->gfx.num_compute_rings;
break;
case AMDGPU_HW_IP_DMA:
ip_num_rings = adev->sdma.num_instances;
break;
case AMDGPU_HW_IP_UVD:
ip_num_rings = 1;
break;
case AMDGPU_HW_IP_VCE:
ip_num_rings = adev->vce.num_rings;
break;
case AMDGPU_HW_IP_UVD_ENC:
ip_num_rings = adev->uvd.num_enc_rings;
break;
case AMDGPU_HW_IP_VCN_DEC:
ip_num_rings = 1;
break;
case AMDGPU_HW_IP_VCN_ENC:
ip_num_rings = adev->vcn.num_enc_rings;
break;
default:
DRM_ERROR("unknown ip type: %d\n", hw_ip);
return -EINVAL;
}
if (ring >= ip_num_rings) {
DRM_ERROR("Ring index:%d exceeds maximum:%d for ip:%d\n",
ring, ip_num_rings, hw_ip);
return -EINVAL;
}
mutex_lock(&mapper->lock);
*out_ring = amdgpu_get_cached_map(mapper, ring);
if (*out_ring) {
r = 0;
goto out_unlock;
}
switch (mapper->hw_ip) {
case AMDGPU_HW_IP_GFX:
case AMDGPU_HW_IP_UVD:
case AMDGPU_HW_IP_VCE:
case AMDGPU_HW_IP_UVD_ENC:
case AMDGPU_HW_IP_VCN_DEC:
case AMDGPU_HW_IP_VCN_ENC:
r = amdgpu_identity_map(adev, mapper, ring, out_ring);
break;
case AMDGPU_HW_IP_DMA:
case AMDGPU_HW_IP_COMPUTE:
r = amdgpu_lru_map(adev, mapper, ring, out_ring);
break;
default:
*out_ring = NULL;
r = -EINVAL;
DRM_ERROR("unknown HW IP type: %d\n", mapper->hw_ip);
}
out_unlock:
mutex_unlock(&mapper->lock);
return r;
}
