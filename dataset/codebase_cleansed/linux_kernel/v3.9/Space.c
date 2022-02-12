static int __init probe_list2(int unit, struct devprobe2 *p, int autoprobe)
{
struct net_device *dev;
for (; p->probe; p++) {
if (autoprobe && p->status)
continue;
dev = p->probe(unit);
if (!IS_ERR(dev))
return 0;
if (autoprobe)
p->status = PTR_ERR(dev);
}
return -ENODEV;
}
static void __init ethif_probe2(int unit)
{
unsigned long base_addr = netdev_boot_base("eth", unit);
if (base_addr == 1)
return;
(void)( probe_list2(unit, m68k_probes, base_addr == 0) &&
probe_list2(unit, isa_probes, base_addr == 0));
}
static int __init net_olddevs_init(void)
{
int num;
#ifdef CONFIG_SBNI
for (num = 0; num < 8; ++num)
sbni_probe(num);
#endif
for (num = 0; num < 8; ++num)
ethif_probe2(num);
#ifdef CONFIG_COPS
cops_probe(0);
cops_probe(1);
cops_probe(2);
#endif
#ifdef CONFIG_LTPC
ltpc_probe();
#endif
return 0;
}
