static unsigned int bis_c0_errctl(unsigned int set)
{
unsigned int res;
res = read_c0_errctl();
write_c0_errctl(res | set);
return res;
}
static void ispram_store_tag(unsigned int offset, unsigned int data)
{
unsigned int errctl;
errctl = bis_c0_errctl(ERRCTL_SPRAM);
ehb();
write_c0_taglo(data);
ehb();
cache_op(Index_Store_Tag_I, CKSEG0|offset);
ehb();
write_c0_errctl(errctl);
ehb();
}
static unsigned int ispram_load_tag(unsigned int offset)
{
unsigned int data;
unsigned int errctl;
errctl = bis_c0_errctl(ERRCTL_SPRAM);
ehb();
cache_op(Index_Load_Tag_I, CKSEG0 | offset);
ehb();
data = read_c0_taglo();
ehb();
write_c0_errctl(errctl);
ehb();
return data;
}
static void dspram_store_tag(unsigned int offset, unsigned int data)
{
unsigned int errctl;
errctl = bis_c0_errctl(ERRCTL_SPRAM);
ehb();
write_c0_dtaglo(data);
ehb();
cache_op(Index_Store_Tag_D, CKSEG0 | offset);
ehb();
write_c0_errctl(errctl);
ehb();
}
static unsigned int dspram_load_tag(unsigned int offset)
{
unsigned int data;
unsigned int errctl;
errctl = bis_c0_errctl(ERRCTL_SPRAM);
ehb();
cache_op(Index_Load_Tag_D, CKSEG0 | offset);
ehb();
data = read_c0_dtaglo();
ehb();
write_c0_errctl(errctl);
ehb();
return data;
}
void spram_config(void)
{
unsigned int config0;
switch (current_cpu_type()) {
case CPU_24K:
case CPU_34K:
case CPU_74K:
case CPU_1004K:
case CPU_1074K:
case CPU_INTERAPTIV:
case CPU_PROAPTIV:
case CPU_P5600:
case CPU_QEMU_GENERIC:
case CPU_I6400:
case CPU_P6600:
config0 = read_c0_config();
if (config0 & (1<<24)) {
probe_spram("ISPRAM", 0x1c000000,
&ispram_load_tag, &ispram_store_tag);
}
if (config0 & (1<<23))
probe_spram("DSPRAM", 0x1c100000,
&dspram_load_tag, &dspram_store_tag);
}
}
