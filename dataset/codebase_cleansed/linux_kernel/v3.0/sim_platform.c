static int __init mipsnet_devinit(void)
{
int err;
err = platform_device_register(&eth1_device);
if (err)
printk(KERN_ERR "%s: registration failed\n", mipsnet_string);
return err;
}
