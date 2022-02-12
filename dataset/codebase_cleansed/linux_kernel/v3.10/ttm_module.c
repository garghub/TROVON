static void ttm_drm_class_device_release(struct device *dev)
{
atomic_set(&device_released, 1);
wake_up_all(&exit_q);
}
struct kobject *ttm_get_kobj(void)
{
struct kobject *kobj = &ttm_drm_class_device.kobj;
BUG_ON(kobj == NULL);
return kobj;
}
static int __init ttm_init(void)
{
int ret;
ret = dev_set_name(&ttm_drm_class_device, "ttm");
if (unlikely(ret != 0))
return ret;
atomic_set(&device_released, 0);
ret = drm_class_device_register(&ttm_drm_class_device);
if (unlikely(ret != 0))
goto out_no_dev_reg;
return 0;
out_no_dev_reg:
atomic_set(&device_released, 1);
wake_up_all(&exit_q);
return ret;
}
static void __exit ttm_exit(void)
{
drm_class_device_unregister(&ttm_drm_class_device);
wait_event(exit_q, atomic_read(&device_released) == 1);
}
