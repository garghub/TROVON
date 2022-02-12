static void isp116x_pfm_delay(struct device *dev, int delay)
{
int cyc = delay / 10;
__asm__ volatile ("0:\n"
"subs %0, %1, #1\n"
"bge 0b\n"
:"=r" (cyc)
:"0"(cyc)
);
}
static void __init mp900c_init(void)
{
printk(KERN_INFO "MobilePro 900/C machine init\n");
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
