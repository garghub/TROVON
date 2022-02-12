static scom_map_t wsp_scom_map(struct device_node *dev, u64 reg, u64 count)
{
struct resource r;
u64 xscom_addr;
if (!of_get_property(dev, "scom-controller", NULL)) {
pr_err("%s: device %s is not a SCOM controller\n",
__func__, dev->full_name);
return SCOM_MAP_INVALID;
}
if (of_address_to_resource(dev, 0, &r)) {
pr_debug("Failed to find SCOM controller address\n");
return 0;
}
xscom_addr = ((reg & 0x7f000000) >> 1) | ((reg & 0xfffff) << 3);
return (scom_map_t)ioremap(r.start + xscom_addr, count << 3);
}
static void wsp_scom_unmap(scom_map_t map)
{
iounmap((void *)map);
}
static u64 wsp_scom_read(scom_map_t map, u32 reg)
{
u64 __iomem *addr = (u64 __iomem *)map;
return in_be64(addr + reg);
}
static void wsp_scom_write(scom_map_t map, u32 reg, u64 value)
{
u64 __iomem *addr = (u64 __iomem *)map;
return out_be64(addr + reg, value);
}
void scom_init_wsp(void)
{
scom_init(&wsp_scom_controller);
}
