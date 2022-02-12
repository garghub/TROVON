static int __init drm_kms_helper_init(void)
{
int ret;
ret = drm_fb_helper_modinit();
if (ret < 0)
goto out;
ret = drm_dp_aux_dev_init();
if (ret < 0)
goto out;
out:
return ret;
}
static void __exit drm_kms_helper_exit(void)
{
drm_dp_aux_dev_exit();
}
