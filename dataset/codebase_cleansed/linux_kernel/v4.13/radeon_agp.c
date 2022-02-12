int radeon_agp_init(struct radeon_device *rdev)
{
#if IS_ENABLED(CONFIG_AGP)
struct radeon_agpmode_quirk *p = radeon_agpmode_quirk_list;
struct drm_agp_mode mode;
struct drm_agp_info info;
uint32_t agp_status;
int default_mode;
bool is_v3;
int ret;
ret = drm_agp_acquire(rdev->ddev);
if (ret) {
DRM_ERROR("Unable to acquire AGP: %d\n", ret);
return ret;
}
ret = drm_agp_info(rdev->ddev, &info);
if (ret) {
drm_agp_release(rdev->ddev);
DRM_ERROR("Unable to get AGP info: %d\n", ret);
return ret;
}
if (rdev->ddev->agp->agp_info.aper_size < 32) {
drm_agp_release(rdev->ddev);
dev_warn(rdev->dev, "AGP aperture too small (%zuM) "
"need at least 32M, disabling AGP\n",
rdev->ddev->agp->agp_info.aper_size);
return -EINVAL;
}
mode.mode = info.mode;
if (rdev->family <= CHIP_RV350)
agp_status = (RREG32(RADEON_AGP_STATUS) | RADEON_AGPv3_MODE) & mode.mode;
else
agp_status = mode.mode;
is_v3 = !!(agp_status & RADEON_AGPv3_MODE);
if (is_v3) {
default_mode = (agp_status & RADEON_AGPv3_8X_MODE) ? 8 : 4;
} else {
if (agp_status & RADEON_AGP_4X_MODE) {
default_mode = 4;
} else if (agp_status & RADEON_AGP_2X_MODE) {
default_mode = 2;
} else {
default_mode = 1;
}
}
while (p && p->chip_device != 0) {
if (info.id_vendor == p->hostbridge_vendor &&
info.id_device == p->hostbridge_device &&
rdev->pdev->vendor == p->chip_vendor &&
rdev->pdev->device == p->chip_device &&
rdev->pdev->subsystem_vendor == p->subsys_vendor &&
rdev->pdev->subsystem_device == p->subsys_device) {
default_mode = p->default_mode;
}
++p;
}
if (radeon_agpmode > 0) {
if ((radeon_agpmode < (is_v3 ? 4 : 1)) ||
(radeon_agpmode > (is_v3 ? 8 : 4)) ||
(radeon_agpmode & (radeon_agpmode - 1))) {
DRM_ERROR("Illegal AGP Mode: %d (valid %s), leaving at %d\n",
radeon_agpmode, is_v3 ? "4, 8" : "1, 2, 4",
default_mode);
radeon_agpmode = default_mode;
} else {
DRM_INFO("AGP mode requested: %d\n", radeon_agpmode);
}
} else {
radeon_agpmode = default_mode;
}
mode.mode &= ~RADEON_AGP_MODE_MASK;
if (is_v3) {
switch (radeon_agpmode) {
case 8:
mode.mode |= RADEON_AGPv3_8X_MODE;
break;
case 4:
default:
mode.mode |= RADEON_AGPv3_4X_MODE;
break;
}
} else {
switch (radeon_agpmode) {
case 4:
mode.mode |= RADEON_AGP_4X_MODE;
break;
case 2:
mode.mode |= RADEON_AGP_2X_MODE;
break;
case 1:
default:
mode.mode |= RADEON_AGP_1X_MODE;
break;
}
}
mode.mode &= ~RADEON_AGP_FW_MODE;
ret = drm_agp_enable(rdev->ddev, mode);
if (ret) {
DRM_ERROR("Unable to enable AGP (mode = 0x%lx)\n", mode.mode);
drm_agp_release(rdev->ddev);
return ret;
}
rdev->mc.agp_base = rdev->ddev->agp->agp_info.aper_base;
rdev->mc.gtt_size = rdev->ddev->agp->agp_info.aper_size << 20;
rdev->mc.gtt_start = rdev->mc.agp_base;
rdev->mc.gtt_end = rdev->mc.gtt_start + rdev->mc.gtt_size - 1;
dev_info(rdev->dev, "GTT: %lluM 0x%08llX - 0x%08llX\n",
rdev->mc.gtt_size >> 20, rdev->mc.gtt_start, rdev->mc.gtt_end);
if (rdev->family < CHIP_R200) {
WREG32(RADEON_AGP_CNTL, RREG32(RADEON_AGP_CNTL) | 0x000e0000);
}
return 0;
#else
return 0;
#endif
}
void radeon_agp_resume(struct radeon_device *rdev)
{
#if IS_ENABLED(CONFIG_AGP)
int r;
if (rdev->flags & RADEON_IS_AGP) {
r = radeon_agp_init(rdev);
if (r)
dev_warn(rdev->dev, "radeon AGP reinit failed\n");
}
#endif
}
void radeon_agp_fini(struct radeon_device *rdev)
{
#if IS_ENABLED(CONFIG_AGP)
if (rdev->ddev->agp && rdev->ddev->agp->acquired) {
drm_agp_release(rdev->ddev);
}
#endif
}
void radeon_agp_suspend(struct radeon_device *rdev)
{
radeon_agp_fini(rdev);
}
