static inline u_int ns_to_cycles(u_int ns, u_int khz)
{
return (ns * khz + 999999) / 1000000;
}
static inline void set_mdcas(u_int *mdcas, int delayed, u_int rcd)
{
u_int shift;
rcd = 2 * rcd - 1;
shift = delayed + 1 + rcd;
mdcas[0] = (1 << rcd) - 1;
mdcas[0] |= 0x55555555 << shift;
mdcas[1] = mdcas[2] = 0x55555555 << (shift & 1);
}
static void
sdram_calculate_timing(struct sdram_info *sd, u_int cpu_khz,
struct sdram_params *sdram)
{
u_int mem_khz, sd_khz, trp, twr;
mem_khz = cpu_khz / 2;
sd_khz = mem_khz;
if ((ns_to_cycles(sdram->tck, sd_khz) > 1) ||
(CPU_REVISION < CPU_SA1110_B2 && sd_khz < 62000))
sd_khz /= 2;
sd->mdcnfg = MDCNFG & 0x007f007f;
twr = ns_to_cycles(sdram->twr, mem_khz);
trp = ns_to_cycles(sdram->trp, mem_khz) - 1;
if (trp < 1)
trp = 1;
sd->mdcnfg |= trp << 8;
sd->mdcnfg |= trp << 24;
sd->mdcnfg |= sdram->cas_latency << 12;
sd->mdcnfg |= sdram->cas_latency << 28;
sd->mdcnfg |= twr << 14;
sd->mdcnfg |= twr << 30;
sd->mdrefr = MDREFR & 0xffbffff0;
sd->mdrefr |= 7;
if (sd_khz != mem_khz)
sd->mdrefr |= MDREFR_K1DB2;
set_mdcas(sd->mdcas, sd_khz >= 62000,
ns_to_cycles(sdram->trcd, mem_khz));
#ifdef DEBUG
printk(KERN_DEBUG "MDCNFG: %08x MDREFR: %08x MDCAS0: %08x MDCAS1: %08x MDCAS2: %08x\n",
sd->mdcnfg, sd->mdrefr, sd->mdcas[0], sd->mdcas[1],
sd->mdcas[2]);
#endif
}
static inline void sdram_set_refresh(u_int dri)
{
MDREFR = (MDREFR & 0xffff000f) | (dri << 4);
(void) MDREFR;
}
static void
sdram_update_refresh(u_int cpu_khz, struct sdram_params *sdram)
{
u_int ns_row = (sdram->refresh * 1000) >> sdram->rows;
u_int dri = ns_to_cycles(ns_row, cpu_khz / 2) / 32;
#ifdef DEBUG
mdelay(250);
printk(KERN_DEBUG "new dri value = %d\n", dri);
#endif
sdram_set_refresh(dri);
}
static int sa1110_target(struct cpufreq_policy *policy, unsigned int ppcr)
{
struct sdram_params *sdram = &sdram_params;
struct sdram_info sd;
unsigned long flags;
unsigned int unused;
sdram_calculate_timing(&sd, sa11x0_freq_table[ppcr].frequency, sdram);
#if 0
if (policy->max < 147500) {
sd.mdrefr |= MDREFR_K1DB2;
sd.mdcas[0] = 0xaaaaaa7f;
} else {
sd.mdrefr &= ~MDREFR_K1DB2;
sd.mdcas[0] = 0xaaaaaa9f;
}
sd.mdcas[1] = 0xaaaaaaaa;
sd.mdcas[2] = 0xaaaaaaaa;
#endif
sdram_set_refresh(2);
if (!irqs_disabled())
msleep(20);
else
mdelay(20);
local_irq_save(flags);
asm("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
udelay(10);
__asm__ __volatile__("\n\
b 2f \n\
.align 5 \n\
1: str %3, [%1, #0] @ MDCNFG \n\
str %4, [%1, #28] @ MDREFR \n\
str %5, [%1, #4] @ MDCAS0 \n\
str %6, [%1, #8] @ MDCAS1 \n\
str %7, [%1, #12] @ MDCAS2 \n\
str %8, [%2, #0] @ PPCR \n\
ldr %0, [%1, #0] \n\
b 3f \n\
2: b 1b \n\
3: nop \n\
nop"
: "=&r" (unused)
: "r" (&MDCNFG), "r" (&PPCR), "0" (sd.mdcnfg),
"r" (sd.mdrefr), "r" (sd.mdcas[0]),
"r" (sd.mdcas[1]), "r" (sd.mdcas[2]), "r" (ppcr));
local_irq_restore(flags);
sdram_update_refresh(sa11x0_freq_table[ppcr].frequency, sdram);
return 0;
}
static int __init sa1110_cpu_init(struct cpufreq_policy *policy)
{
return cpufreq_generic_init(policy, sa11x0_freq_table, CPUFREQ_ETERNAL);
}
static struct sdram_params *sa1110_find_sdram(const char *name)
{
struct sdram_params *sdram;
for (sdram = sdram_tbl; sdram < sdram_tbl + ARRAY_SIZE(sdram_tbl);
sdram++)
if (strcmp(name, sdram->name) == 0)
return sdram;
return NULL;
}
static int __init sa1110_clk_init(void)
{
struct sdram_params *sdram;
const char *name = sdram_name;
if (!cpu_is_sa1110())
return -ENODEV;
if (!name[0]) {
if (machine_is_assabet())
name = "TC59SM716-CL3";
if (machine_is_pt_system3())
name = "K4S641632D";
if (machine_is_h3100())
name = "KM416S4030CT";
if (machine_is_jornada720() || machine_is_h3600())
name = "K4S281632B-1H";
if (machine_is_nanoengine())
name = "MT48LC8M16A2TG-75";
}
sdram = sa1110_find_sdram(name);
if (sdram) {
printk(KERN_DEBUG "SDRAM: tck: %d trcd: %d trp: %d"
" twr: %d refresh: %d cas_latency: %d\n",
sdram->tck, sdram->trcd, sdram->trp,
sdram->twr, sdram->refresh, sdram->cas_latency);
memcpy(&sdram_params, sdram, sizeof(sdram_params));
return cpufreq_register_driver(&sa1110_driver);
}
return 0;
}
