static void __init
smp_86xx_release_core(int nr)
{
__be32 __iomem *mcm_vaddr;
unsigned long pcr;
if (nr < 0 || nr >= NR_CPUS)
return;
mcm_vaddr = ioremap(get_immrbase() + MPC86xx_MCM_OFFSET,
MPC86xx_MCM_SIZE);
pcr = in_be32(mcm_vaddr + (MCM_PORT_CONFIG_OFFSET >> 2));
pcr |= 1 << (nr + 24);
out_be32(mcm_vaddr + (MCM_PORT_CONFIG_OFFSET >> 2), pcr);
iounmap(mcm_vaddr);
}
static int __init
smp_86xx_kick_cpu(int nr)
{
unsigned int save_vector;
unsigned long target, flags;
int n = 0;
unsigned int *vector = (unsigned int *)(KERNELBASE + 0x100);
if (nr < 0 || nr >= NR_CPUS)
return -ENOENT;
pr_debug("smp_86xx_kick_cpu: kick CPU #%d\n", nr);
local_irq_save(flags);
save_vector = *vector;
target = (unsigned long) __secondary_start_mpc86xx;
patch_branch(vector, target, BRANCH_SET_LINK);
smp_86xx_release_core(nr);
while ((__secondary_hold_acknowledge != nr) && (n++, n < 1000))
mdelay(1);
*vector = save_vector;
flush_icache_range((unsigned long) vector, (unsigned long) vector + 4);
local_irq_restore(flags);
pr_debug("wait CPU #%d for %d msecs.\n", nr, n);
return 0;
}
static void __init
smp_86xx_setup_cpu(int cpu_nr)
{
mpic_setup_this_cpu();
}
void __init
mpc86xx_smp_init(void)
{
smp_ops = &smp_86xx_ops;
}
