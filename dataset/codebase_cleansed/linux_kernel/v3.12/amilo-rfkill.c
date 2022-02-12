static int amilo_a1655_rfkill_set_block(void *data, bool blocked)
{
u8 param = blocked ? A1655_WIFI_OFF : A1655_WIFI_ON;
int rc;
i8042_lock_chip();
rc = i8042_command(&param, A1655_WIFI_COMMAND);
i8042_unlock_chip();
return rc;
}
static int amilo_m7440_rfkill_set_block(void *data, bool blocked)
{
u8 val1 = blocked ? M7440_RADIO_OFF1 : M7440_RADIO_ON1;
u8 val2 = blocked ? M7440_RADIO_OFF2 : M7440_RADIO_ON2;
outb(val1, M7440_PORT1);
outb(val2, M7440_PORT2);
if (inb(M7440_PORT1) != val1 || inb(M7440_PORT2) != val2)
return -EIO;
return 0;
}
static int amilo_rfkill_probe(struct platform_device *device)
{
int rc;
const struct dmi_system_id *system_id =
dmi_first_match(amilo_rfkill_id_table);
if (!system_id)
return -ENXIO;
amilo_rfkill_dev = rfkill_alloc(KBUILD_MODNAME, &device->dev,
RFKILL_TYPE_WLAN,
system_id->driver_data, NULL);
if (!amilo_rfkill_dev)
return -ENOMEM;
rc = rfkill_register(amilo_rfkill_dev);
if (rc)
goto fail;
return 0;
fail:
rfkill_destroy(amilo_rfkill_dev);
return rc;
}
static int amilo_rfkill_remove(struct platform_device *device)
{
rfkill_unregister(amilo_rfkill_dev);
rfkill_destroy(amilo_rfkill_dev);
return 0;
}
static int __init amilo_rfkill_init(void)
{
int rc;
if (dmi_first_match(amilo_rfkill_id_table) == NULL)
return -ENODEV;
rc = platform_driver_register(&amilo_rfkill_driver);
if (rc)
return rc;
amilo_rfkill_pdev = platform_device_register_simple(KBUILD_MODNAME, -1,
NULL, 0);
if (IS_ERR(amilo_rfkill_pdev)) {
rc = PTR_ERR(amilo_rfkill_pdev);
goto fail;
}
return 0;
fail:
platform_driver_unregister(&amilo_rfkill_driver);
return rc;
}
static void __exit amilo_rfkill_exit(void)
{
platform_device_unregister(amilo_rfkill_pdev);
platform_driver_unregister(&amilo_rfkill_driver);
}
