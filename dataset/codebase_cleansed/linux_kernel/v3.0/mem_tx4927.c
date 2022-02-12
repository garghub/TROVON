static unsigned int __init tx4927_process_sdccr(u64 __iomem *addr)
{
u64 val;
unsigned int sdccr_ce;
unsigned int sdccr_bs;
unsigned int sdccr_rs;
unsigned int sdccr_cs;
unsigned int sdccr_mw;
unsigned int bs = 0;
unsigned int rs = 0;
unsigned int cs = 0;
unsigned int mw = 0;
val = __raw_readq(addr);
sdccr_ce = ((val & (1 << 10)) >> 10);
sdccr_bs = ((val & (1 << 8)) >> 8);
sdccr_rs = ((val & (3 << 5)) >> 5);
sdccr_cs = ((val & (7 << 2)) >> 2);
sdccr_mw = ((val & (1 << 0)) >> 0);
if (sdccr_ce) {
bs = 2 << sdccr_bs;
rs = 2048 << sdccr_rs;
cs = 256 << sdccr_cs;
mw = 8 >> sdccr_mw;
}
return rs * cs * mw * bs;
}
unsigned int __init tx4927_get_mem_size(void)
{
unsigned int total = 0;
int i;
for (i = 0; i < ARRAY_SIZE(tx4927_sdramcptr->cr); i++)
total += tx4927_process_sdccr(&tx4927_sdramcptr->cr[i]);
return total;
}
