static int __init vr41xx_siu_add(void)
{
struct platform_device *pdev;
struct resource *res;
unsigned int num;
int retval;
pdev = platform_device_alloc("SIU", -1);
if (!pdev)
return -ENOMEM;
switch (current_cpu_type()) {
case CPU_VR4111:
case CPU_VR4121:
pdev->dev.platform_data = siu_type1_ports;
res = siu_type1_resource;
num = ARRAY_SIZE(siu_type1_resource);
break;
case CPU_VR4122:
case CPU_VR4131:
case CPU_VR4133:
pdev->dev.platform_data = siu_type2_ports;
res = siu_type2_resource;
num = ARRAY_SIZE(siu_type2_resource);
break;
default:
retval = -ENODEV;
goto err_free_device;
}
retval = platform_device_add_resources(pdev, res, num);
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
void __init vr41xx_siu_setup(void)
{
struct uart_port port;
struct resource *res;
unsigned int *type;
int i;
switch (current_cpu_type()) {
case CPU_VR4111:
case CPU_VR4121:
type = siu_type1_ports;
res = siu_type1_resource;
break;
case CPU_VR4122:
case CPU_VR4131:
case CPU_VR4133:
type = siu_type2_ports;
res = siu_type2_resource;
break;
default:
return;
}
for (i = 0; i < SIU_PORTS_MAX; i++) {
port.line = i;
port.type = type[i];
if (port.type == PORT_UNKNOWN)
break;
port.mapbase = res[i].start;
port.membase = (unsigned char __iomem *)KSEG1ADDR(res[i].start);
vr41xx_siu_early_setup(&port);
}
}
