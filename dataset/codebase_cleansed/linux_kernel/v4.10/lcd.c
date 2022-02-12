static __init int cobalt_lcd_add(void)
{
struct platform_device *pdev;
int retval;
pdev = platform_device_alloc("cobalt-lcd", -1);
if (!pdev)
return -ENOMEM;
retval = platform_device_add_resources(pdev, &cobalt_lcd_resource, 1);
if (retval)
goto err_free_device;
retval = platform_device_add(pdev);
if (retval)
goto err_free_device;
return 0;
err_free_device:
platform_device_put(pdev);
return retval;
}
