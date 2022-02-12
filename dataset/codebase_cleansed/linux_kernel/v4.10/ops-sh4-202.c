static int sh4202_read_vcr(unsigned long base, struct superhyway_vcr_info *vcr)
{
u32 vcrh, vcrl;
u64 tmp;
vcrh = __raw_readl(base);
vcrl = __raw_readl(base + sizeof(u32));
tmp = ((u64)vcrh << 32) | vcrl;
memcpy(vcr, &tmp, sizeof(u64));
return 0;
}
static int sh4202_write_vcr(unsigned long base, struct superhyway_vcr_info vcr)
{
u64 tmp = *(u64 *)&vcr;
__raw_writel((tmp >> 32) & 0xffffffff, base);
__raw_writel(tmp & 0xffffffff, base + sizeof(u32));
return 0;
}
int __init superhyway_scan_bus(struct superhyway_bus *bus)
{
return superhyway_add_devices(bus, sh4202_devices,
ARRAY_SIZE(sh4202_devices));
}
