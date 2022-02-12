static int __init wsp_probe_buses(void)
{
static __initdata struct of_device_id bus_ids[] = {
{ .compatible = WSP_SOC_COMPATIBLE, },
{ .compatible = PBIC_COMPATIBLE, },
{ .compatible = COPRO_COMPATIBLE, },
{},
};
of_platform_bus_probe(NULL, bus_ids, NULL);
return 0;
}
void __init wsp_setup_arch(void)
{
loops_per_jiffy = 50000000;
scom_init_wsp();
#ifdef CONFIG_SMP
a2_setup_smp();
#endif
#ifdef CONFIG_PCI
wsp_setup_pci();
#endif
}
void __init wsp_setup_irq(void)
{
wsp_init_irq();
opb_pic_init();
}
int __init wsp_probe_devices(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "dallas,ds1500");
if (np != NULL) {
struct resource res;
if (of_address_to_resource(np, 0, &res) == 0)
platform_device_register_simple("ds1511", 0, &res, 1);
}
wsp_probe_buses();
return 0;
}
void wsp_halt(void)
{
u64 val;
scom_map_t m;
struct device_node *dn;
struct device_node *mine;
struct device_node *me;
int rc;
me = of_get_cpu_node(smp_processor_id(), NULL);
mine = scom_find_parent(me);
for_each_node_with_property(dn, "scom-controller") {
if (dn == mine)
continue;
m = scom_map(dn, 0, 1);
rc = scom_read(m, 0, &val);
if (rc == 0)
scom_write(m, 0, val | 1);
scom_unmap(m);
}
m = scom_map(mine, 0, 1);
rc = scom_read(m, 0, &val);
if (rc == 0)
scom_write(m, 0, val | 1);
scom_unmap(m);
}
