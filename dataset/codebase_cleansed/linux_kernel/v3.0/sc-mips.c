static void mips_sc_wback_inv(unsigned long addr, unsigned long size)
{
blast_scache_range(addr, addr + size);
}
static void mips_sc_inv(unsigned long addr, unsigned long size)
{
unsigned long lsize = cpu_scache_line_size();
unsigned long almask = ~(lsize - 1);
cache_op(Hit_Writeback_Inv_SD, addr & almask);
cache_op(Hit_Writeback_Inv_SD, (addr + size - 1) & almask);
blast_inv_scache_range(addr, addr + size);
}
static void mips_sc_enable(void)
{
}
static void mips_sc_disable(void)
{
}
static inline int mips_sc_is_activated(struct cpuinfo_mips *c)
{
unsigned int config2 = read_c0_config2();
unsigned int tmp;
switch (c->cputype) {
case CPU_34K:
case CPU_74K:
case CPU_1004K:
case CPU_BMIPS5000:
if (config2 & (1 << 12))
return 0;
}
tmp = (config2 >> 4) & 0x0f;
if (0 < tmp && tmp <= 7)
c->scache.linesz = 2 << tmp;
else
return 0;
return 1;
}
static inline int __init mips_sc_probe(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
unsigned int config1, config2;
unsigned int tmp;
c->scache.flags |= MIPS_CACHE_NOT_PRESENT;
if (c->isa_level != MIPS_CPU_ISA_M32R1 &&
c->isa_level != MIPS_CPU_ISA_M32R2 &&
c->isa_level != MIPS_CPU_ISA_M64R1 &&
c->isa_level != MIPS_CPU_ISA_M64R2)
return 0;
config1 = read_c0_config1();
if (!(config1 & MIPS_CONF_M))
return 0;
config2 = read_c0_config2();
if (!mips_sc_is_activated(c))
return 0;
tmp = (config2 >> 8) & 0x0f;
if (0 <= tmp && tmp <= 7)
c->scache.sets = 64 << tmp;
else
return 0;
tmp = (config2 >> 0) & 0x0f;
if (0 <= tmp && tmp <= 7)
c->scache.ways = tmp + 1;
else
return 0;
c->scache.waysize = c->scache.sets * c->scache.linesz;
c->scache.waybit = __ffs(c->scache.waysize);
c->scache.flags &= ~MIPS_CACHE_NOT_PRESENT;
return 1;
}
int __cpuinit mips_sc_init(void)
{
int found = mips_sc_probe();
if (found) {
mips_sc_enable();
bcops = &mips_sc_ops;
}
return found;
}
