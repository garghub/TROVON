static int __init sh7724_devices_setup(void)
{
platform_resource_setup_memory(&vpu_device, "vpu", 2 << 20);
platform_resource_setup_memory(&veu0_device, "veu0", 2 << 20);
platform_resource_setup_memory(&veu1_device, "veu1", 2 << 20);
platform_resource_setup_memory(&jpu_device, "jpu", 2 << 20);
platform_resource_setup_memory(&spu0_device, "spu0", 2 << 20);
platform_resource_setup_memory(&spu1_device, "spu1", 2 << 20);
return platform_add_devices(sh7724_devices,
ARRAY_SIZE(sh7724_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh7724_early_devices,
ARRAY_SIZE(sh7724_early_devices));
}
void l2_cache_init(void)
{
__raw_writel(L2_CACHE_ENABLE, RAMCR);
}
void __init plat_irq_setup(void)
{
register_intc_controller(&intc_desc);
}
static int sh7724_pre_sleep_notifier_call(struct notifier_block *nb,
unsigned long flags, void *unused)
{
if (!(flags & SUSP_SH_RSTANDBY))
return NOTIFY_DONE;
sh7724_rstandby_state.mmselr = __raw_readl(0xff800020);
sh7724_rstandby_state.mmselr |= 0xa5a50000;
sh7724_rstandby_state.cs0bcr = __raw_readl(0xfec10004);
sh7724_rstandby_state.cs4bcr = __raw_readl(0xfec10010);
sh7724_rstandby_state.cs5abcr = __raw_readl(0xfec10014);
sh7724_rstandby_state.cs5bbcr = __raw_readl(0xfec10018);
sh7724_rstandby_state.cs6abcr = __raw_readl(0xfec1001c);
sh7724_rstandby_state.cs6bbcr = __raw_readl(0xfec10020);
sh7724_rstandby_state.cs4wcr = __raw_readl(0xfec10030);
sh7724_rstandby_state.cs5awcr = __raw_readl(0xfec10034);
sh7724_rstandby_state.cs5bwcr = __raw_readl(0xfec10038);
sh7724_rstandby_state.cs6awcr = __raw_readl(0xfec1003c);
sh7724_rstandby_state.cs6bwcr = __raw_readl(0xfec10040);
sh7724_rstandby_state.ipra = __raw_readw(0xa4080000);
sh7724_rstandby_state.iprb = __raw_readw(0xa4080004);
sh7724_rstandby_state.iprc = __raw_readw(0xa4080008);
sh7724_rstandby_state.iprd = __raw_readw(0xa408000c);
sh7724_rstandby_state.ipre = __raw_readw(0xa4080010);
sh7724_rstandby_state.iprf = __raw_readw(0xa4080014);
sh7724_rstandby_state.iprg = __raw_readw(0xa4080018);
sh7724_rstandby_state.iprh = __raw_readw(0xa408001c);
sh7724_rstandby_state.ipri = __raw_readw(0xa4080020);
sh7724_rstandby_state.iprj = __raw_readw(0xa4080024);
sh7724_rstandby_state.iprk = __raw_readw(0xa4080028);
sh7724_rstandby_state.iprl = __raw_readw(0xa408002c);
sh7724_rstandby_state.imr0 = __raw_readb(0xa4080080);
sh7724_rstandby_state.imr1 = __raw_readb(0xa4080084);
sh7724_rstandby_state.imr2 = __raw_readb(0xa4080088);
sh7724_rstandby_state.imr3 = __raw_readb(0xa408008c);
sh7724_rstandby_state.imr4 = __raw_readb(0xa4080090);
sh7724_rstandby_state.imr5 = __raw_readb(0xa4080094);
sh7724_rstandby_state.imr6 = __raw_readb(0xa4080098);
sh7724_rstandby_state.imr7 = __raw_readb(0xa408009c);
sh7724_rstandby_state.imr8 = __raw_readb(0xa40800a0);
sh7724_rstandby_state.imr9 = __raw_readb(0xa40800a4);
sh7724_rstandby_state.imr10 = __raw_readb(0xa40800a8);
sh7724_rstandby_state.imr11 = __raw_readb(0xa40800ac);
sh7724_rstandby_state.imr12 = __raw_readb(0xa40800b0);
sh7724_rstandby_state.rwtcnt = __raw_readb(0xa4520000);
sh7724_rstandby_state.rwtcnt |= 0x5a00;
sh7724_rstandby_state.rwtcsr = __raw_readb(0xa4520004);
sh7724_rstandby_state.rwtcsr |= 0xa500;
__raw_writew(sh7724_rstandby_state.rwtcsr & 0x07, 0xa4520004);
sh7724_rstandby_state.irdaclk = __raw_readl(0xa4150018);
sh7724_rstandby_state.spuclk = __raw_readl(0xa415003c);
return NOTIFY_DONE;
}
static int sh7724_post_sleep_notifier_call(struct notifier_block *nb,
unsigned long flags, void *unused)
{
if (!(flags & SUSP_SH_RSTANDBY))
return NOTIFY_DONE;
__raw_writel(sh7724_rstandby_state.mmselr, 0xff800020);
__raw_writel(sh7724_rstandby_state.cs0bcr, 0xfec10004);
__raw_writel(sh7724_rstandby_state.cs4bcr, 0xfec10010);
__raw_writel(sh7724_rstandby_state.cs5abcr, 0xfec10014);
__raw_writel(sh7724_rstandby_state.cs5bbcr, 0xfec10018);
__raw_writel(sh7724_rstandby_state.cs6abcr, 0xfec1001c);
__raw_writel(sh7724_rstandby_state.cs6bbcr, 0xfec10020);
__raw_writel(sh7724_rstandby_state.cs4wcr, 0xfec10030);
__raw_writel(sh7724_rstandby_state.cs5awcr, 0xfec10034);
__raw_writel(sh7724_rstandby_state.cs5bwcr, 0xfec10038);
__raw_writel(sh7724_rstandby_state.cs6awcr, 0xfec1003c);
__raw_writel(sh7724_rstandby_state.cs6bwcr, 0xfec10040);
__raw_writew(sh7724_rstandby_state.ipra, 0xa4080000);
__raw_writew(sh7724_rstandby_state.iprb, 0xa4080004);
__raw_writew(sh7724_rstandby_state.iprc, 0xa4080008);
__raw_writew(sh7724_rstandby_state.iprd, 0xa408000c);
__raw_writew(sh7724_rstandby_state.ipre, 0xa4080010);
__raw_writew(sh7724_rstandby_state.iprf, 0xa4080014);
__raw_writew(sh7724_rstandby_state.iprg, 0xa4080018);
__raw_writew(sh7724_rstandby_state.iprh, 0xa408001c);
__raw_writew(sh7724_rstandby_state.ipri, 0xa4080020);
__raw_writew(sh7724_rstandby_state.iprj, 0xa4080024);
__raw_writew(sh7724_rstandby_state.iprk, 0xa4080028);
__raw_writew(sh7724_rstandby_state.iprl, 0xa408002c);
__raw_writeb(sh7724_rstandby_state.imr0, 0xa4080080);
__raw_writeb(sh7724_rstandby_state.imr1, 0xa4080084);
__raw_writeb(sh7724_rstandby_state.imr2, 0xa4080088);
__raw_writeb(sh7724_rstandby_state.imr3, 0xa408008c);
__raw_writeb(sh7724_rstandby_state.imr4, 0xa4080090);
__raw_writeb(sh7724_rstandby_state.imr5, 0xa4080094);
__raw_writeb(sh7724_rstandby_state.imr6, 0xa4080098);
__raw_writeb(sh7724_rstandby_state.imr7, 0xa408009c);
__raw_writeb(sh7724_rstandby_state.imr8, 0xa40800a0);
__raw_writeb(sh7724_rstandby_state.imr9, 0xa40800a4);
__raw_writeb(sh7724_rstandby_state.imr10, 0xa40800a8);
__raw_writeb(sh7724_rstandby_state.imr11, 0xa40800ac);
__raw_writeb(sh7724_rstandby_state.imr12, 0xa40800b0);
__raw_writew(sh7724_rstandby_state.rwtcnt, 0xa4520000);
__raw_writew(sh7724_rstandby_state.rwtcsr, 0xa4520004);
__raw_writel(sh7724_rstandby_state.irdaclk, 0xa4150018);
__raw_writel(sh7724_rstandby_state.spuclk, 0xa415003c);
return NOTIFY_DONE;
}
static int __init sh7724_sleep_setup(void)
{
atomic_notifier_chain_register(&sh_mobile_pre_sleep_notifier_list,
&sh7724_pre_sleep_notifier);
atomic_notifier_chain_register(&sh_mobile_post_sleep_notifier_list,
&sh7724_post_sleep_notifier);
return 0;
}
