int amdgpu_gfx_scratch_get(struct amdgpu_device *adev, uint32_t *reg)
{
int i;
i = ffs(adev->gfx.scratch.free_mask);
if (i != 0 && i <= adev->gfx.scratch.num_reg) {
i--;
adev->gfx.scratch.free_mask &= ~(1u << i);
*reg = adev->gfx.scratch.reg_base + i;
return 0;
}
return -EINVAL;
}
void amdgpu_gfx_scratch_free(struct amdgpu_device *adev, uint32_t reg)
{
adev->gfx.scratch.free_mask |= 1u << (reg - adev->gfx.scratch.reg_base);
}
void amdgpu_gfx_parse_disable_cu(unsigned *mask, unsigned max_se, unsigned max_sh)
{
unsigned se, sh, cu;
const char *p;
memset(mask, 0, sizeof(*mask) * max_se * max_sh);
if (!amdgpu_disable_cu || !*amdgpu_disable_cu)
return;
p = amdgpu_disable_cu;
for (;;) {
char *next;
int ret = sscanf(p, "%u.%u.%u", &se, &sh, &cu);
if (ret < 3) {
DRM_ERROR("amdgpu: could not parse disable_cu\n");
return;
}
if (se < max_se && sh < max_sh && cu < 16) {
DRM_INFO("amdgpu: disabling CU %u.%u.%u\n", se, sh, cu);
mask[se * max_sh + sh] |= 1u << cu;
} else {
DRM_ERROR("amdgpu: disable_cu %u.%u.%u is out of range\n",
se, sh, cu);
}
next = strchr(p, ',');
if (!next)
break;
p = next + 1;
}
}
