int __init msp_eth_setup(void)
{
int i, ret = 0;
msp_gpio_pin_mode(MSP_GPIO_OUTPUT, MSP_ETHERNET_GPIO0);
msp_gpio_pin_hi(MSP_ETHERNET_GPIO0);
#ifdef CONFIG_MSP_HAS_TSMAC
msp_gpio_pin_mode(MSP_GPIO_OUTPUT, MSP_ETHERNET_GPIO1);
msp_gpio_pin_hi(MSP_ETHERNET_GPIO1);
msp_gpio_pin_mode(MSP_GPIO_OUTPUT, MSP_ETHERNET_GPIO2);
msp_gpio_pin_hi(MSP_ETHERNET_GPIO2);
#endif
for (i = 0; i < ARRAY_SIZE(msp_eth_devs); i++) {
ret = platform_device_register(&msp_eth_devs[i]);
printk(KERN_INFO "device: %d, return value = %d\n", i, ret);
if (ret) {
platform_device_unregister(&msp_eth_devs[i]);
break;
}
}
if (ret)
printk(KERN_WARNING "Could not initialize "
"MSPETH device structures.\n");
return ret;
}
