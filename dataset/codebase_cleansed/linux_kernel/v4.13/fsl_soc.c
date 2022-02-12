phys_addr_t get_immrbase(void)
{
struct device_node *soc;
if (immrbase != -1)
return immrbase;
soc = of_find_node_by_type(NULL, "soc");
if (soc) {
int size;
u32 naddr;
const __be32 *prop = of_get_property(soc, "#address-cells", &size);
if (prop && size == 4)
naddr = be32_to_cpup(prop);
else
naddr = 2;
prop = of_get_property(soc, "ranges", &size);
if (prop)
immrbase = of_translate_address(soc, prop + naddr);
of_node_put(soc);
}
return immrbase;
}
u32 fsl_get_sys_freq(void)
{
static u32 sysfreq = -1;
struct device_node *soc;
if (sysfreq != -1)
return sysfreq;
soc = of_find_node_by_type(NULL, "soc");
if (!soc)
return -1;
of_property_read_u32(soc, "clock-frequency", &sysfreq);
if (sysfreq == -1 || !sysfreq)
of_property_read_u32(soc, "bus-frequency", &sysfreq);
of_node_put(soc);
return sysfreq;
}
u32 get_brgfreq(void)
{
static u32 brgfreq = -1;
struct device_node *node;
if (brgfreq != -1)
return brgfreq;
node = of_find_compatible_node(NULL, NULL, "fsl,cpm-brg");
if (node) {
of_property_read_u32(node, "clock-frequency", &brgfreq);
of_node_put(node);
return brgfreq;
}
node = of_find_node_by_type(NULL, "cpm");
if (!node)
node = of_find_compatible_node(NULL, NULL, "fsl,qe");
if (!node)
node = of_find_node_by_type(NULL, "qe");
if (node) {
of_property_read_u32(node, "brg-frequency", &brgfreq);
if (brgfreq == -1 || !brgfreq)
if (!of_property_read_u32(node, "bus-frequency",
&brgfreq))
brgfreq /= 2;
of_node_put(node);
}
return brgfreq;
}
u32 get_baudrate(void)
{
static u32 fs_baudrate = -1;
struct device_node *node;
if (fs_baudrate != -1)
return fs_baudrate;
node = of_find_node_by_type(NULL, "serial");
if (node) {
of_property_read_u32(node, "current-speed", &fs_baudrate);
of_node_put(node);
}
return fs_baudrate;
}
static int fsl_rstcr_restart(struct notifier_block *this,
unsigned long mode, void *cmd)
{
local_irq_disable();
out_be32(rstcr, 0x2);
return NOTIFY_DONE;
}
static int __init setup_rstcr(void)
{
struct device_node *np;
static struct notifier_block restart_handler = {
.notifier_call = fsl_rstcr_restart,
.priority = 128,
};
for_each_node_by_name(np, "global-utilities") {
if ((of_get_property(np, "fsl,has-rstcr", NULL))) {
rstcr = of_iomap(np, 0) + 0xb0;
if (!rstcr) {
printk (KERN_ERR "Error: reset control "
"register not mapped!\n");
} else {
register_restart_handler(&restart_handler);
}
break;
}
}
of_node_put(np);
return 0;
}
void __noreturn fsl_hv_restart(char *cmd)
{
pr_info("hv restart\n");
fh_partition_restart(-1);
while (1) ;
}
void __noreturn fsl_hv_halt(void)
{
pr_info("hv exit\n");
fh_partition_stop(-1);
while (1) ;
}
