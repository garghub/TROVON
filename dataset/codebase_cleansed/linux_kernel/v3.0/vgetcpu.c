notrace long
__vdso_getcpu(unsigned *cpu, unsigned *node, struct getcpu_cache *unused)
{
unsigned int p;
if (VVAR(vgetcpu_mode) == VGETCPU_RDTSCP) {
native_read_tscp(&p);
} else {
asm("lsl %1,%0" : "=r" (p) : "r" (__PER_CPU_SEG));
}
if (cpu)
*cpu = p & 0xfff;
if (node)
*node = p >> 12;
return 0;
}
