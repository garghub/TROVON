static void __cpuinit per_hub_init(cnodeid_t cnode)
{
struct hub_data *hub = hub_data(cnode);
nasid_t nasid = COMPACT_TO_NASID_NODEID(cnode);
int i;
cpu_set(smp_processor_id(), hub->h_cpus);
if (test_and_set_bit(cnode, hub_init_mask))
return;
REMOTE_HUB_S(nasid, IIO_ICTP, 0x800);
REMOTE_HUB_S(nasid, IIO_ICTO, 0xff);
hub_rtc_init(cnode);
xtalk_probe_node(cnode);
#ifdef CONFIG_REPLICATE_EXHANDLERS
if (get_compact_nodeid() == cnode) {
extern char except_vec2_generic, except_vec3_generic;
extern void build_tlb_refill_handler(void);
memcpy((void *)(CKSEG0 + 0x100), &except_vec2_generic, 0x80);
memcpy((void *)(CKSEG0 + 0x180), &except_vec3_generic, 0x80);
build_tlb_refill_handler();
memcpy((void *)(CKSEG0 + 0x100), (void *) CKSEG0, 0x80);
memcpy((void *)(CKSEG0 + 0x180), &except_vec3_generic, 0x100);
__flush_cache_all();
}
#endif
for (i = 0; i <= BASE_PCI_IRQ; i++) {
__set_bit(i, hub->irq_alloc_mask);
LOCAL_HUB_CLR_INTR(INT_PEND0_BASELVL + i);
}
__set_bit(IP_PEND0_6_63, hub->irq_alloc_mask);
LOCAL_HUB_S(PI_INT_PEND_MOD, IP_PEND0_6_63);
for (i = NI_BRDCAST_ERR_A; i <= MSC_PANIC_INTR; i++) {
__set_bit(i, hub->irq_alloc_mask);
LOCAL_HUB_CLR_INTR(INT_PEND1_BASELVL + i);
}
}
void __cpuinit per_cpu_init(void)
{
int cpu = smp_processor_id();
int slice = LOCAL_HUB_L(PI_CPU_NUM);
cnodeid_t cnode = get_compact_nodeid();
struct hub_data *hub = hub_data(cnode);
struct slice_data *si = hub->slice + slice;
int i;
if (test_and_set_bit(slice, &hub->slice_map))
return;
clear_c0_status(ST0_IM);
per_hub_init(cnode);
for (i = 0; i < LEVELS_PER_SLICE; i++)
si->level_to_irq[i] = -1;
cpu_data[cpu].data = si;
cpu_time_init();
install_ipi();
install_cpu_nmi_handler(cputoslice(cpu));
set_c0_status(SRB_DEV0 | SRB_DEV1);
}
nasid_t
get_nasid(void)
{
return (nasid_t)((LOCAL_HUB_L(NI_STATUS_REV_ID) & NSRI_NODEID_MASK)
>> NSRI_NODEID_SHFT);
}
cnodeid_t get_compact_nodeid(void)
{
return NASID_TO_COMPACT_NODEID(get_nasid());
}
static inline void ioc3_eth_init(void)
{
struct ioc3 *ioc3;
nasid_t nid;
nid = get_nasid();
ioc3 = (struct ioc3 *) KL_CONFIG_CH_CONS_INFO(nid)->memory_base;
ioc3->eier = 0;
}
void __init plat_mem_setup(void)
{
hubreg_t p, e, n_mode;
nasid_t nid;
ip27_reboot_setup();
nid = get_nasid();
printk("IP27: Running on node %d.\n", nid);
p = LOCAL_HUB_L(PI_CPU_PRESENT_A) & 1;
e = LOCAL_HUB_L(PI_CPU_ENABLE_A) & 1;
printk("Node %d has %s primary CPU%s.\n", nid,
p ? "a" : "no",
e ? ", CPU is running" : "");
p = LOCAL_HUB_L(PI_CPU_PRESENT_B) & 1;
e = LOCAL_HUB_L(PI_CPU_ENABLE_B) & 1;
printk("Node %d has %s secondary CPU%s.\n", nid,
p ? "a" : "no",
e ? ", CPU is running" : "");
n_mode = LOCAL_HUB_L(NI_STATUS_REV_ID) & NSRI_MORENODES_MASK;
printk("Machine is in %c mode.\n", n_mode ? 'N' : 'M');
#ifdef CONFIG_SGI_SN_N_MODE
if (!n_mode)
panic("Kernel compiled for M mode.");
#else
if (n_mode)
panic("Kernel compiled for N mode.");
#endif
ioc3_eth_init();
per_cpu_init();
set_io_port_base(IO_BASE);
}
