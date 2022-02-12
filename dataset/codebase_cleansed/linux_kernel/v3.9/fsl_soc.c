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
struct device_node *soc;
const u32 *prop;
int size;
if (sysfreq != -1)
return sysfreq;
soc = of_find_node_by_type(NULL, "soc");
if (!soc)
return -1;
prop = of_get_property(soc, "clock-frequency", &size);
if (!prop || size != sizeof(*prop) || *prop == 0)
prop = of_get_property(soc, "bus-frequency", &size);
if (prop && size == sizeof(*prop))
sysfreq = *prop;
of_node_put(soc);
return sysfreq;
}
u32 get_brgfreq(void)
{
struct device_node *node;
const unsigned int *prop;
int size;
if (brgfreq != -1)
return brgfreq;
node = of_find_compatible_node(NULL, NULL, "fsl,cpm-brg");
if (node) {
prop = of_get_property(node, "clock-frequency", &size);
if (prop && size == 4)
brgfreq = *prop;
of_node_put(node);
return brgfreq;
}
node = of_find_node_by_type(NULL, "cpm");
if (!node)
node = of_find_compatible_node(NULL, NULL, "fsl,qe");
if (!node)
node = of_find_node_by_type(NULL, "qe");
if (node) {
prop = of_get_property(node, "brg-frequency", &size);
if (prop && size == 4)
brgfreq = *prop;
if (brgfreq == -1 || brgfreq == 0) {
prop = of_get_property(node, "bus-frequency", &size);
if (prop && size == 4)
brgfreq = *prop / 2;
}
of_node_put(node);
}
return brgfreq;
}
u32 get_baudrate(void)
{
struct device_node *node;
if (fs_baudrate != -1)
return fs_baudrate;
node = of_find_node_by_type(NULL, "serial");
if (node) {
int size;
const unsigned int *prop = of_get_property(node,
"current-speed", &size);
if (prop)
fs_baudrate = *prop;
of_node_put(node);
}
return fs_baudrate;
}
static int __init of_add_fixed_phys(void)
{
int ret;
struct device_node *np;
u32 *fixed_link;
struct fixed_phy_status status = {};
for_each_node_by_name(np, "ethernet") {
fixed_link = (u32 *)of_get_property(np, "fixed-link", NULL);
if (!fixed_link)
continue;
status.link = 1;
status.duplex = fixed_link[1];
status.speed = fixed_link[2];
status.pause = fixed_link[3];
status.asym_pause = fixed_link[4];
ret = fixed_phy_add(PHY_POLL, fixed_link[0], &status);
if (ret) {
of_node_put(np);
return ret;
}
}
return 0;
}
static int __init setup_rstcr(void)
{
struct device_node *np;
for_each_node_by_name(np, "global-utilities") {
if ((of_get_property(np, "fsl,has-rstcr", NULL))) {
rstcr = of_iomap(np, 0) + 0xb0;
if (!rstcr)
printk (KERN_ERR "Error: reset control "
"register not mapped!\n");
break;
}
}
if (!rstcr && ppc_md.restart == fsl_rstcr_restart)
printk(KERN_ERR "No RSTCR register, warm reboot won't work\n");
if (np)
of_node_put(np);
return 0;
}
void fsl_rstcr_restart(char *cmd)
{
local_irq_disable();
if (rstcr)
out_be32(rstcr, 0x2);
while (1) ;
}
void fsl_hv_restart(char *cmd)
{
pr_info("hv restart\n");
fh_partition_restart(-1);
}
void fsl_hv_halt(void)
{
pr_info("hv exit\n");
fh_partition_stop(-1);
}
