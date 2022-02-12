notrace long
__vdso_getcpu(unsigned *cpu, unsigned *node, struct getcpu_cache *unused)
{
unsigned int p;
p = __getcpu();
if (cpu)
*cpu = p & VGETCPU_CPU_MASK;
if (node)
*node = p >> 12;
return 0;
}
