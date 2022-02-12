static void alloc_cpupda(cpuid_t cpu, int cpunum)
{
cnodeid_t node = get_cpu_cnode(cpu);
nasid_t nasid = COMPACT_TO_NASID_NODEID(node);
cputonasid(cpunum) = nasid;
sn_cpu_info[cpunum].p_nodeid = node;
cputoslice(cpunum) = get_cpu_slice(cpu);
}
static nasid_t get_actual_nasid(lboard_t *brd)
{
klhub_t *hub;
if (!brd)
return INVALID_NASID;
hub = (klhub_t *)find_first_component(brd, KLSTRUCT_HUB);
if (!hub)
return INVALID_NASID;
if (!(hub->hub_info.flags & KLINFO_ENABLE))
return hub->hub_info.physid;
else
return brd->brd_nasid;
}
static int do_cpumask(cnodeid_t cnode, nasid_t nasid, int highest)
{
static int tot_cpus_found = 0;
lboard_t *brd;
klcpu_t *acpu;
int cpus_found = 0;
cpuid_t cpuid;
brd = find_lboard((lboard_t *)KL_CONFIG_INFO(nasid), KLTYPE_IP27);
do {
acpu = (klcpu_t *)find_first_component(brd, KLSTRUCT_CPU);
while (acpu) {
cpuid = acpu->cpu_info.virtid;
if (get_actual_nasid(brd) == brd->brd_nasid)
cpuid_to_compact_node[cpuid] = cnode;
if (cpuid > highest)
highest = cpuid;
if ((acpu->cpu_info.flags & KLINFO_ENABLE) &&
(tot_cpus_found != NR_CPUS)) {
set_cpu_possible(cpuid, true);
alloc_cpupda(cpuid, tot_cpus_found);
cpus_found++;
tot_cpus_found++;
}
acpu = (klcpu_t *)find_component(brd, (klinfo_t *)acpu,
KLSTRUCT_CPU);
}
brd = KLCF_NEXT(brd);
if (!brd)
break;
brd = find_lboard(brd, KLTYPE_IP27);
} while (brd);
return highest;
}
void cpu_node_probe(void)
{
int i, highest = 0;
gda_t *gdap = GDA;
for (i = 0; i < MAX_COMPACT_NODES; i++)
compact_to_nasid_node[i] = INVALID_NASID;
for (i = 0; i < MAX_NASIDS; i++)
nasid_to_compact_node[i] = INVALID_CNODEID;
for (i = 0; i < MAXCPUS; i++)
cpuid_to_compact_node[i] = INVALID_CNODEID;
nodes_clear(node_online_map);
for (i = 0; i < MAX_COMPACT_NODES; i++) {
nasid_t nasid = gdap->g_nasidtable[i];
if (nasid == INVALID_NASID)
break;
compact_to_nasid_node[i] = nasid;
nasid_to_compact_node[nasid] = i;
node_set_online(num_online_nodes());
highest = do_cpumask(i, nasid, highest);
}
printk("Discovered %d cpus on %d nodes\n", highest + 1, num_online_nodes());
}
static __init void intr_clear_all(nasid_t nasid)
{
int i;
REMOTE_HUB_S(nasid, PI_INT_MASK0_A, 0);
REMOTE_HUB_S(nasid, PI_INT_MASK0_B, 0);
REMOTE_HUB_S(nasid, PI_INT_MASK1_A, 0);
REMOTE_HUB_S(nasid, PI_INT_MASK1_B, 0);
for (i = 0; i < 128; i++)
REMOTE_HUB_CLR_INTR(nasid, i);
}
static void ip27_send_ipi_single(int destid, unsigned int action)
{
int irq;
switch (action) {
case SMP_RESCHEDULE_YOURSELF:
irq = CPU_RESCHED_A_IRQ;
break;
case SMP_CALL_FUNCTION:
irq = CPU_CALL_A_IRQ;
break;
default:
panic("sendintr");
}
irq += cputoslice(destid);
REMOTE_HUB_SEND_INTR(COMPACT_TO_NASID_NODEID(cpu_to_node(destid)), irq);
}
static void ip27_send_ipi_mask(const struct cpumask *mask, unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
ip27_send_ipi_single(i, action);
}
static void ip27_init_secondary(void)
{
per_cpu_init();
}
static void ip27_smp_finish(void)
{
extern void hub_rt_clock_event_init(void);
hub_rt_clock_event_init();
local_irq_enable();
}
static void __init ip27_cpus_done(void)
{
}
static void ip27_boot_secondary(int cpu, struct task_struct *idle)
{
unsigned long gp = (unsigned long)task_thread_info(idle);
unsigned long sp = __KSTK_TOS(idle);
LAUNCH_SLAVE(cputonasid(cpu), cputoslice(cpu),
(launch_proc_t)MAPPED_KERN_RW_TO_K0(smp_bootstrap),
0, (void *) sp, (void *) gp);
}
static void __init ip27_smp_setup(void)
{
cnodeid_t cnode;
for_each_online_node(cnode) {
if (cnode == 0)
continue;
intr_clear_all(COMPACT_TO_NASID_NODEID(cnode));
}
replicate_kernel_text();
alloc_cpupda(0, 0);
}
static void __init ip27_prepare_cpus(unsigned int max_cpus)
{
}
