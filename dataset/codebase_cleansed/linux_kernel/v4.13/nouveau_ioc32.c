long nouveau_compat_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
drm_ioctl_compat_t *fn = NULL;
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
#if 0
if (nr < DRM_COMMAND_BASE + ARRAY_SIZE(mga_compat_ioctls))
fn = nouveau_compat_ioctls[nr - DRM_COMMAND_BASE];
#endif
if (fn != NULL)
ret = (*fn)(filp, cmd, arg);
else
ret = nouveau_drm_ioctl(filp, cmd, arg);
return ret;
}
