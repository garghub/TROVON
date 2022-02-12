void __init cyclone_setup(void)
{
use_cyclone = 1;
}
static u64 read_cyclone(struct clocksource *cs)
{
return (u64)readq((void __iomem *)cyclone_mc);
}
int __init init_cyclone_clock(void)
{
u64 __iomem *reg;
u64 base;
u64 offset;
int i;
u32 __iomem *cyclone_timer;
if (!use_cyclone)
return 0;
printk(KERN_INFO "Summit chipset: Starting Cyclone Counter.\n");
offset = (CYCLONE_CBAR_ADDR);
reg = ioremap_nocache(offset, sizeof(u64));
if(!reg){
printk(KERN_ERR "Summit chipset: Could not find valid CBAR"
" register.\n");
use_cyclone = 0;
return -ENODEV;
}
base = readq(reg);
iounmap(reg);
if(!base){
printk(KERN_ERR "Summit chipset: Could not find valid CBAR"
" value.\n");
use_cyclone = 0;
return -ENODEV;
}
offset = (base + CYCLONE_PMCC_OFFSET);
reg = ioremap_nocache(offset, sizeof(u64));
if(!reg){
printk(KERN_ERR "Summit chipset: Could not find valid PMCC"
" register.\n");
use_cyclone = 0;
return -ENODEV;
}
writel(0x00000001,reg);
iounmap(reg);
offset = (base + CYCLONE_MPCS_OFFSET);
reg = ioremap_nocache(offset, sizeof(u64));
if(!reg){
printk(KERN_ERR "Summit chipset: Could not find valid MPCS"
" register.\n");
use_cyclone = 0;
return -ENODEV;
}
writel(0x00000001,reg);
iounmap(reg);
offset = (base + CYCLONE_MPMC_OFFSET);
cyclone_timer = ioremap_nocache(offset, sizeof(u32));
if(!cyclone_timer){
printk(KERN_ERR "Summit chipset: Could not find valid MPMC"
" register.\n");
use_cyclone = 0;
return -ENODEV;
}
for(i=0; i<3; i++){
u32 old = readl(cyclone_timer);
int stall = 100;
while(stall--) barrier();
if(readl(cyclone_timer) == old){
printk(KERN_ERR "Summit chipset: Counter not counting!"
" DISABLED\n");
iounmap(cyclone_timer);
cyclone_timer = NULL;
use_cyclone = 0;
return -ENODEV;
}
}
cyclone_mc = cyclone_timer;
clocksource_cyclone.archdata.fsys_mmio = cyclone_timer;
clocksource_register_hz(&clocksource_cyclone, CYCLONE_TIMER_FREQ);
return 0;
}
