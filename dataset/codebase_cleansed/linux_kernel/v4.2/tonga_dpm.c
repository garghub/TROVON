static int tonga_dpm_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
tonga_dpm_set_funcs(adev);
return 0;
}
static int tonga_dpm_init_microcode(struct amdgpu_device *adev)
{
char fw_name[30] = "amdgpu/tonga_smc.bin";
int err;
err = request_firmware(&adev->pm.fw, fw_name, adev->dev);
if (err)
goto out;
err = amdgpu_ucode_validate(adev->pm.fw);
out:
if (err) {
DRM_ERROR("Failed to load firmware \"%s\"", fw_name);
release_firmware(adev->pm.fw);
adev->pm.fw = NULL;
}
return err;
}
static int tonga_dpm_sw_init(void *handle)
{
int ret;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
ret = tonga_dpm_init_microcode(adev);
if (ret)
return ret;
return 0;
}
static int tonga_dpm_sw_fini(void *handle)
{
return 0;
}
static int tonga_dpm_hw_init(void *handle)
{
int ret;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
mutex_lock(&adev->pm.mutex);
ret = tonga_smu_init(adev);
if (ret) {
DRM_ERROR("SMU initialization failed\n");
goto fail;
}
ret = tonga_smu_start(adev);
if (ret) {
DRM_ERROR("SMU start failed\n");
goto fail;
}
mutex_unlock(&adev->pm.mutex);
return 0;
fail:
adev->firmware.smu_load = false;
mutex_unlock(&adev->pm.mutex);
return -EINVAL;
}
static int tonga_dpm_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
mutex_lock(&adev->pm.mutex);
tonga_smu_fini(adev);
mutex_unlock(&adev->pm.mutex);
return 0;
}
static int tonga_dpm_suspend(void *handle)
{
return 0;
}
static int tonga_dpm_resume(void *handle)
{
int ret;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
mutex_lock(&adev->pm.mutex);
ret = tonga_smu_start(adev);
if (ret) {
DRM_ERROR("SMU start failed\n");
goto fail;
}
fail:
mutex_unlock(&adev->pm.mutex);
return ret;
}
static int tonga_dpm_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int tonga_dpm_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void tonga_dpm_set_funcs(struct amdgpu_device *adev)
{
if (NULL == adev->pm.funcs)
adev->pm.funcs = &tonga_dpm_funcs;
}
