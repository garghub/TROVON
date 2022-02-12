void ddk750_set_mmio(void __iomem * addr,unsigned short devId,char revId)
{
mmio750 = addr;
devId750 = devId;
revId750 = revId;
if(revId == 0xfe)
printk("found sm750le\n");
}
