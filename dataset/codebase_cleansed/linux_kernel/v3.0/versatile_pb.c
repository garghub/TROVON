static void __init versatile_pb_init(void)
{
int i;
versatile_init();
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
}
