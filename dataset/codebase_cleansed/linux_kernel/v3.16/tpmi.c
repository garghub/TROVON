__init void iop13xx_add_tpmi_devices(void)
{
unsigned short device_id;
if (__raw_readl(IOP13XX_ESSR0) & IOP13XX_INTERFACE_SEL_PCIX)
device_id = __raw_readw(IOP13XX_ATUE_DID);
else
device_id = __raw_readw(IOP13XX_ATUX_DID);
switch (device_id) {
case 0x3380:
case 0x3384:
case 0x3388:
case 0x338c:
case 0x3382:
case 0x3386:
case 0x338a:
case 0x338e:
return;
case 0x3310:
case 0x3312:
case 0x3314:
case 0x3318:
case 0x331a:
case 0x331c:
case 0x33c0:
case 0x33c2:
case 0x33c4:
case 0x33c8:
case 0x33ca:
case 0x33cc:
case 0x33b0:
case 0x33b2:
case 0x33b4:
case 0x33b8:
case 0x33ba:
case 0x33bc:
case 0x3320:
case 0x3322:
case 0x3324:
case 0x3328:
case 0x332a:
case 0x332c:
platform_device_register(&iop13xx_tpmi_0_device);
return;
default:
platform_device_register(&iop13xx_tpmi_0_device);
platform_device_register(&iop13xx_tpmi_1_device);
platform_device_register(&iop13xx_tpmi_2_device);
platform_device_register(&iop13xx_tpmi_3_device);
return;
}
}
