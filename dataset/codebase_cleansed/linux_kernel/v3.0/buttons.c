static __init int cobalt_add_buttons(void)
{
struct platform_device *pd;
int error;
pd = platform_device_alloc("Cobalt buttons", -1);
if (!pd)
return -ENOMEM;
error = platform_device_add_resources(pd, &cobalt_buttons_resource, 1);
if (error)
goto err_free_device;
error = platform_device_add(pd);
if (error)
goto err_free_device;
return 0;
err_free_device:
platform_device_put(pd);
return error;
}
