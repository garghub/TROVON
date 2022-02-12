struct platform_device *__init mxs_add_mxs_pwm(resource_size_t iobase, int id)
{
struct resource res = {
.flags = IORESOURCE_MEM,
};
res.start = iobase + 0x10 + 0x20 * id;
res.end = res.start + 0x1f;
return mxs_add_platform_device("mxs-pwm", id, &res, 1, NULL, 0);
}
