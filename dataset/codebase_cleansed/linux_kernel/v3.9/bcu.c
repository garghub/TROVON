unsigned long vr41xx_get_vtclock_frequency(void)
{
return vr41xx_vtclock;
}
unsigned long vr41xx_get_tclock_frequency(void)
{
return vr41xx_tclock;
}
static inline uint16_t read_clkspeed(void)
{
switch (current_cpu_type()) {
case CPU_VR4111:
case CPU_VR4121: return readw(CLKSPEEDREG_TYPE1);
case CPU_VR4122:
case CPU_VR4131:
case CPU_VR4133: return readw(CLKSPEEDREG_TYPE2);
default:
printk(KERN_INFO "Unexpected CPU of NEC VR4100 series\n");
break;
}
return 0;
}
static inline unsigned long calculate_pclock(uint16_t clkspeed)
{
unsigned long pclock = 0;
switch (current_cpu_type()) {
case CPU_VR4111:
case CPU_VR4121:
pclock = 18432000 * 64;
pclock /= CLKSP(clkspeed);
break;
case CPU_VR4122:
pclock = 18432000 * 98;
pclock /= CLKSP(clkspeed);
break;
case CPU_VR4131:
pclock = 18432000 * 108;
pclock /= CLKSP(clkspeed);
break;
case CPU_VR4133:
switch (CLKSP_VR4133(clkspeed)) {
case 0:
pclock = 133000000;
break;
case 1:
pclock = 149000000;
break;
case 2:
pclock = 165900000;
break;
case 3:
pclock = 199100000;
break;
case 4:
pclock = 265900000;
break;
default:
printk(KERN_INFO "Unknown PClock speed for NEC VR4133\n");
break;
}
break;
default:
printk(KERN_INFO "Unexpected CPU of NEC VR4100 series\n");
break;
}
printk(KERN_INFO "PClock: %ldHz\n", pclock);
return pclock;
}
static inline unsigned long calculate_vtclock(uint16_t clkspeed, unsigned long pclock)
{
unsigned long vtclock = 0;
switch (current_cpu_type()) {
case CPU_VR4111:
break;
case CPU_VR4121:
vtclock = pclock;
if (DIVVT(clkspeed) == 9)
vtclock = pclock * 6;
else if (DIVVT(clkspeed) == 10)
vtclock = pclock * 4;
vtclock /= DIVVT(clkspeed);
printk(KERN_INFO "VTClock: %ldHz\n", vtclock);
break;
case CPU_VR4122:
if(VTDIVMODE(clkspeed) == 7)
vtclock = pclock / 1;
else if(VTDIVMODE(clkspeed) == 1)
vtclock = pclock / 2;
else
vtclock = pclock / VTDIVMODE(clkspeed);
printk(KERN_INFO "VTClock: %ldHz\n", vtclock);
break;
case CPU_VR4131:
case CPU_VR4133:
vtclock = pclock / VTDIVMODE(clkspeed);
printk(KERN_INFO "VTClock: %ldHz\n", vtclock);
break;
default:
printk(KERN_INFO "Unexpected CPU of NEC VR4100 series\n");
break;
}
return vtclock;
}
static inline unsigned long calculate_tclock(uint16_t clkspeed, unsigned long pclock,
unsigned long vtclock)
{
unsigned long tclock = 0;
switch (current_cpu_type()) {
case CPU_VR4111:
if (!(clkspeed & DIV2B))
tclock = pclock / 2;
else if (!(clkspeed & DIV3B))
tclock = pclock / 3;
else if (!(clkspeed & DIV4B))
tclock = pclock / 4;
break;
case CPU_VR4121:
tclock = pclock / DIVT(clkspeed);
break;
case CPU_VR4122:
case CPU_VR4131:
case CPU_VR4133:
tclock = vtclock / TDIVMODE(clkspeed);
break;
default:
printk(KERN_INFO "Unexpected CPU of NEC VR4100 series\n");
break;
}
printk(KERN_INFO "TClock: %ldHz\n", tclock);
return tclock;
}
void vr41xx_calculate_clock_frequency(void)
{
unsigned long pclock;
uint16_t clkspeed;
clkspeed = read_clkspeed();
pclock = calculate_pclock(clkspeed);
vr41xx_vtclock = calculate_vtclock(clkspeed, pclock);
vr41xx_tclock = calculate_tclock(clkspeed, pclock, vr41xx_vtclock);
}
