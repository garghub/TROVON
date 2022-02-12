static void __init himalaya_lcd_init(void)
{
int himalaya_boardid;
himalaya_boardid = 0x4;
printk(KERN_INFO "himalaya LCD Driver init. boardid=%d\n",
himalaya_boardid);
switch (himalaya_boardid) {
case 0x4:
himalaya_fb_info.modelist = &himalaya4_lcd_mode;
break;
case 0x6:
himalaya_fb_info.modelist = &himalaya6_lcd_mode;
break;
default:
printk(KERN_INFO "himalaya lcd_init: unknown boardid=%d. Using 0x4\n",
himalaya_boardid);
himalaya_fb_info.modelist = &himalaya4_lcd_mode;
}
}
static void __init himalaya_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
himalaya_lcd_init();
platform_add_devices(devices, ARRAY_SIZE(devices));
}
