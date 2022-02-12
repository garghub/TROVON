int amdgpu_gfx_scratch_get(struct amdgpu_device *adev, uint32_t *reg)
{
int i;
for (i = 0; i < adev->gfx.scratch.num_reg; i++) {
if (adev->gfx.scratch.free[i]) {
adev->gfx.scratch.free[i] = false;
*reg = adev->gfx.scratch.reg[i];
return 0;
}
}
return -EINVAL;
}
void amdgpu_gfx_scratch_free(struct amdgpu_device *adev, uint32_t reg)
{
int i;
for (i = 0; i < adev->gfx.scratch.num_reg; i++) {
if (adev->gfx.scratch.reg[i] == reg) {
adev->gfx.scratch.free[i] = true;
return;
}
}
}
