void * __init prom_early_alloc(unsigned long size)
{
void *ret;
ret = __alloc_bootmem(size, SMP_CACHE_BYTES, 0UL);
if (ret != NULL)
memset(ret, 0, size);
prom_early_allocated += size;
return ret;
}
static void __init sparc32_path_component(struct device_node *dp, char *tmp_buf)
{
struct linux_prom_registers *regs;
struct property *rprop;
rprop = of_find_property(dp, "reg", NULL);
if (!rprop)
return;
regs = rprop->value;
sprintf(tmp_buf, "%s@%x,%x",
dp->name,
regs->which_io, regs->phys_addr);
}
static void __init sbus_path_component(struct device_node *dp, char *tmp_buf)
{
struct linux_prom_registers *regs;
struct property *prop;
prop = of_find_property(dp, "reg", NULL);
if (!prop)
return;
regs = prop->value;
sprintf(tmp_buf, "%s@%x,%x",
dp->name,
regs->which_io,
regs->phys_addr);
}
static void __init pci_path_component(struct device_node *dp, char *tmp_buf)
{
struct linux_prom_pci_registers *regs;
struct property *prop;
unsigned int devfn;
prop = of_find_property(dp, "reg", NULL);
if (!prop)
return;
regs = prop->value;
devfn = (regs->phys_hi >> 8) & 0xff;
if (devfn & 0x07) {
sprintf(tmp_buf, "%s@%x,%x",
dp->name,
devfn >> 3,
devfn & 0x07);
} else {
sprintf(tmp_buf, "%s@%x",
dp->name,
devfn >> 3);
}
}
static void __init ebus_path_component(struct device_node *dp, char *tmp_buf)
{
struct linux_prom_registers *regs;
struct property *prop;
prop = of_find_property(dp, "reg", NULL);
if (!prop)
return;
regs = prop->value;
sprintf(tmp_buf, "%s@%x,%x",
dp->name,
regs->which_io, regs->phys_addr);
}
static void __init ambapp_path_component(struct device_node *dp, char *tmp_buf)
{
struct amba_prom_registers *regs;
unsigned int *intr, *device, *vendor, reg0;
struct property *prop;
int interrupt = 0;
prop = of_find_property(dp, "reg", NULL);
if (!prop) {
reg0 = (unsigned int)dp->phandle;
} else {
regs = prop->value;
reg0 = regs->phys_addr;
}
prop = of_find_property(dp, "interrupts", NULL);
if (!prop)
intr = &interrupt;
else
intr = prop->value;
prop = of_find_property(dp, "vendor", NULL);
if (!prop)
return;
vendor = prop->value;
prop = of_find_property(dp, "device", NULL);
if (!prop)
return;
device = prop->value;
sprintf(tmp_buf, "%s:%d:%d@%x,%x",
dp->name, *vendor, *device,
*intr, reg0);
}
static void __init __build_path_component(struct device_node *dp, char *tmp_buf)
{
struct device_node *parent = dp->parent;
if (parent != NULL) {
if (!strcmp(parent->type, "pci") ||
!strcmp(parent->type, "pciex"))
return pci_path_component(dp, tmp_buf);
if (!strcmp(parent->type, "sbus"))
return sbus_path_component(dp, tmp_buf);
if (!strcmp(parent->type, "ebus"))
return ebus_path_component(dp, tmp_buf);
if (!strcmp(parent->type, "ambapp"))
return ambapp_path_component(dp, tmp_buf);
}
return sparc32_path_component(dp, tmp_buf);
}
char * __init build_path_component(struct device_node *dp)
{
char tmp_buf[64], *n;
tmp_buf[0] = '\0';
__build_path_component(dp, tmp_buf);
if (tmp_buf[0] == '\0')
strcpy(tmp_buf, dp->name);
n = prom_early_alloc(strlen(tmp_buf) + 1);
strcpy(n, tmp_buf);
return n;
}
void __init of_console_init(void)
{
char *msg = "OF stdout device is: %s\n";
struct device_node *dp;
unsigned long flags;
const char *type;
phandle node;
int skip, tmp, fd;
of_console_path = prom_early_alloc(256);
switch (prom_vers) {
case PROM_V0:
skip = 0;
switch (*romvec->pv_stdout) {
case PROMDEV_SCREEN:
type = "display";
break;
case PROMDEV_TTYB:
skip = 1;
case PROMDEV_TTYA:
type = "serial";
break;
default:
prom_printf("Invalid PROM_V0 stdout value %u\n",
*romvec->pv_stdout);
prom_halt();
}
tmp = skip;
for_each_node_by_type(dp, type) {
if (!tmp--)
break;
}
if (!dp) {
prom_printf("Cannot find PROM_V0 console node.\n");
prom_halt();
}
of_console_device = dp;
strcpy(of_console_path, dp->full_name);
if (!strcmp(type, "serial")) {
strcat(of_console_path,
(skip ? ":b" : ":a"));
}
break;
default:
case PROM_V2:
case PROM_V3:
fd = *romvec->pv_v2bootargs.fd_stdout;
spin_lock_irqsave(&prom_lock, flags);
node = (*romvec->pv_v2devops.v2_inst2pkg)(fd);
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
if (!node) {
prom_printf("Cannot resolve stdout node from "
"instance %08x.\n", fd);
prom_halt();
}
dp = of_find_node_by_phandle(node);
type = of_get_property(dp, "device_type", NULL);
if (!type) {
prom_printf("Console stdout lacks "
"device_type property.\n");
prom_halt();
}
if (strcmp(type, "display") && strcmp(type, "serial")) {
prom_printf("Console device_type is neither display "
"nor serial.\n");
prom_halt();
}
of_console_device = dp;
if (prom_vers == PROM_V2) {
strcpy(of_console_path, dp->full_name);
switch (*romvec->pv_stdout) {
case PROMDEV_TTYA:
strcat(of_console_path, ":a");
break;
case PROMDEV_TTYB:
strcat(of_console_path, ":b");
break;
}
} else {
const char *path;
dp = of_find_node_by_path("/");
path = of_get_property(dp, "stdout-path", NULL);
if (!path) {
prom_printf("No stdout-path in root node.\n");
prom_halt();
}
strcpy(of_console_path, path);
}
break;
}
of_console_options = strrchr(of_console_path, ':');
if (of_console_options) {
of_console_options++;
if (*of_console_options == '\0')
of_console_options = NULL;
}
printk(msg, of_console_path);
}
void __init of_fill_in_cpu_data(void)
{
}
void __init irq_trans_init(struct device_node *dp)
{
}
