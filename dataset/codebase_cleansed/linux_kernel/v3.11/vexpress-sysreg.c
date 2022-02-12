void vexpress_flags_set(u32 data)
{
writel(~0, vexpress_sysreg_base + SYS_FLAGSCLR);
writel(data, vexpress_sysreg_base + SYS_FLAGSSET);
}
u32 vexpress_get_procid(int site)
{
if (site == VEXPRESS_SITE_MASTER)
site = vexpress_master_site;
return readl(vexpress_sysreg_base + (site == VEXPRESS_SITE_DB1 ?
SYS_PROCID0 : SYS_PROCID1));
}
u32 vexpress_get_hbi(int site)
{
u32 id;
switch (site) {
case VEXPRESS_SITE_MB:
id = readl(vexpress_sysreg_base + SYS_ID);
return (id >> SYS_ID_HBI_SHIFT) & SYS_HBI_MASK;
case VEXPRESS_SITE_MASTER:
case VEXPRESS_SITE_DB1:
case VEXPRESS_SITE_DB2:
id = vexpress_get_procid(site);
return (id >> SYS_PROCIDx_HBI_SHIFT) & SYS_HBI_MASK;
}
return ~0;
}
void __iomem *vexpress_get_24mhz_clock_base(void)
{
return vexpress_sysreg_base + SYS_24MHZ;
}
static void vexpress_sysreg_find_prop(struct device_node *node,
const char *name, u32 *val)
{
of_node_get(node);
while (node) {
if (of_property_read_u32(node, name, val) == 0) {
of_node_put(node);
return;
}
node = of_get_next_parent(node);
}
}
unsigned __vexpress_get_site(struct device *dev, struct device_node *node)
{
u32 site = 0;
WARN_ON(dev && node && dev->of_node != node);
if (dev && !node)
node = dev->of_node;
if (node) {
vexpress_sysreg_find_prop(node, "arm,vexpress,site", &site);
} else if (dev && dev->bus == &platform_bus_type) {
struct platform_device *pdev = to_platform_device(dev);
if (pdev->num_resources == 1 &&
pdev->resource[0].flags == IORESOURCE_BUS)
site = pdev->resource[0].start;
} else if (dev && strncmp(dev_name(dev), "ct:", 3) == 0) {
site = VEXPRESS_SITE_MASTER;
}
if (site == VEXPRESS_SITE_MASTER)
site = vexpress_master_site;
return site;
}
static void *vexpress_sysreg_config_func_get(struct device *dev,
struct device_node *node)
{
struct vexpress_sysreg_config_func *config_func;
u32 site;
u32 position = 0;
u32 dcc = 0;
u32 func_device[2];
int err = -EFAULT;
if (node) {
of_node_get(node);
vexpress_sysreg_find_prop(node, "arm,vexpress,site", &site);
vexpress_sysreg_find_prop(node, "arm,vexpress,position",
&position);
vexpress_sysreg_find_prop(node, "arm,vexpress,dcc", &dcc);
err = of_property_read_u32_array(node,
"arm,vexpress-sysreg,func", func_device,
ARRAY_SIZE(func_device));
of_node_put(node);
} else if (dev && dev->bus == &platform_bus_type) {
struct platform_device *pdev = to_platform_device(dev);
if (pdev->num_resources == 1 &&
pdev->resource[0].flags == IORESOURCE_BUS) {
site = pdev->resource[0].start;
func_device[0] = pdev->resource[0].end;
func_device[1] = pdev->id;
err = 0;
}
}
if (err)
return NULL;
config_func = kzalloc(sizeof(*config_func), GFP_KERNEL);
if (!config_func)
return NULL;
config_func->template = SYS_CFGCTRL_DCC(dcc);
config_func->template |= SYS_CFGCTRL_FUNC(func_device[0]);
config_func->template |= SYS_CFGCTRL_SITE(site == VEXPRESS_SITE_MASTER ?
vexpress_master_site : site);
config_func->template |= SYS_CFGCTRL_POSITION(position);
config_func->device |= func_device[1];
dev_dbg(vexpress_sysreg_dev, "func 0x%p = 0x%x, %d\n", config_func,
config_func->template, config_func->device);
return config_func;
}
static void vexpress_sysreg_config_func_put(void *func)
{
kfree(func);
}
static int vexpress_sysreg_config_func_exec(void *func, int offset,
bool write, u32 *data)
{
int status;
struct vexpress_sysreg_config_func *config_func = func;
u32 command;
if (WARN_ON(!vexpress_sysreg_base))
return -ENOENT;
command = readl(vexpress_sysreg_base + SYS_CFGCTRL);
if (WARN_ON(command & SYS_CFGCTRL_START))
return -EBUSY;
command = SYS_CFGCTRL_START;
command |= write ? SYS_CFGCTRL_WRITE : 0;
command |= config_func->template;
command |= SYS_CFGCTRL_DEVICE(config_func->device + offset);
if (!write)
*data = 0xdeadbeef;
dev_dbg(vexpress_sysreg_dev, "command %x, data %x\n",
command, *data);
writel(*data, vexpress_sysreg_base + SYS_CFGDATA);
writel(0, vexpress_sysreg_base + SYS_CFGSTAT);
writel(command, vexpress_sysreg_base + SYS_CFGCTRL);
mb();
if (vexpress_sysreg_dev) {
if (!write)
vexpress_sysreg_config_data = data;
vexpress_sysreg_config_tries = 100;
mod_timer(&vexpress_sysreg_config_timer,
jiffies + usecs_to_jiffies(100));
status = VEXPRESS_CONFIG_STATUS_WAIT;
} else {
u32 cfgstat;
do {
cpu_relax();
cfgstat = readl(vexpress_sysreg_base + SYS_CFGSTAT);
} while (!cfgstat);
if (!write && (cfgstat & SYS_CFGSTAT_COMPLETE))
*data = readl(vexpress_sysreg_base + SYS_CFGDATA);
status = VEXPRESS_CONFIG_STATUS_DONE;
if (cfgstat & SYS_CFGSTAT_ERR)
status = -EINVAL;
}
return status;
}
static void vexpress_sysreg_config_complete(unsigned long data)
{
int status = VEXPRESS_CONFIG_STATUS_DONE;
u32 cfgstat = readl(vexpress_sysreg_base + SYS_CFGSTAT);
if (cfgstat & SYS_CFGSTAT_ERR)
status = -EINVAL;
if (!vexpress_sysreg_config_tries--)
status = -ETIMEDOUT;
if (status < 0) {
dev_err(vexpress_sysreg_dev, "error %d\n", status);
} else if (!(cfgstat & SYS_CFGSTAT_COMPLETE)) {
mod_timer(&vexpress_sysreg_config_timer,
jiffies + usecs_to_jiffies(50));
return;
}
if (vexpress_sysreg_config_data) {
*vexpress_sysreg_config_data = readl(vexpress_sysreg_base +
SYS_CFGDATA);
dev_dbg(vexpress_sysreg_dev, "read data %x\n",
*vexpress_sysreg_config_data);
vexpress_sysreg_config_data = NULL;
}
vexpress_config_complete(vexpress_sysreg_config_bridge, status);
}
void vexpress_sysreg_setup(struct device_node *node)
{
if (WARN_ON(!vexpress_sysreg_base))
return;
if (readl(vexpress_sysreg_base + SYS_MISC) & SYS_MISC_MASTERSITE)
vexpress_master_site = VEXPRESS_SITE_DB2;
else
vexpress_master_site = VEXPRESS_SITE_DB1;
vexpress_sysreg_config_bridge = vexpress_config_bridge_register(
node, &vexpress_sysreg_config_bridge_info);
WARN_ON(!vexpress_sysreg_config_bridge);
}
void __init vexpress_sysreg_early_init(void __iomem *base)
{
vexpress_sysreg_base = base;
vexpress_sysreg_setup(NULL);
}
void __init vexpress_sysreg_of_early_init(void)
{
struct device_node *node;
if (vexpress_sysreg_base)
return;
node = of_find_compatible_node(NULL, NULL, "arm,vexpress-sysreg");
if (node) {
vexpress_sysreg_base = of_iomap(node, 0);
vexpress_sysreg_setup(node);
}
}
static int vexpress_sysreg_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return 0;
}
static int vexpress_sysreg_gpio_get(struct gpio_chip *chip,
unsigned offset)
{
struct vexpress_sysreg_gpio *gpio = &vexpress_sysreg_gpios[offset];
u32 reg_value = readl(vexpress_sysreg_base + gpio->reg);
return !!(reg_value & gpio->value);
}
static void vexpress_sysreg_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct vexpress_sysreg_gpio *gpio = &vexpress_sysreg_gpios[offset];
u32 reg_value = readl(vexpress_sysreg_base + gpio->reg);
if (value)
reg_value |= gpio->value;
else
reg_value &= ~gpio->value;
writel(reg_value, vexpress_sysreg_base + gpio->reg);
}
static int vexpress_sysreg_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
vexpress_sysreg_gpio_set(chip, offset, value);
return 0;
}
static ssize_t vexpress_sysreg_sys_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "0x%08x\n", readl(vexpress_sysreg_base + SYS_ID));
}
static int vexpress_sysreg_probe(struct platform_device *pdev)
{
int err;
struct resource *res = platform_get_resource(pdev,
IORESOURCE_MEM, 0);
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "Failed to request memory region!\n");
return -EBUSY;
}
if (!vexpress_sysreg_base) {
vexpress_sysreg_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
vexpress_sysreg_setup(pdev->dev.of_node);
}
if (!vexpress_sysreg_base) {
dev_err(&pdev->dev, "Failed to obtain base address!\n");
return -EFAULT;
}
setup_timer(&vexpress_sysreg_config_timer,
vexpress_sysreg_config_complete, 0);
vexpress_sysreg_dev = &pdev->dev;
#ifdef CONFIG_GPIOLIB
vexpress_sysreg_gpio_chip.dev = &pdev->dev;
err = gpiochip_add(&vexpress_sysreg_gpio_chip);
if (err) {
vexpress_config_bridge_unregister(
vexpress_sysreg_config_bridge);
dev_err(&pdev->dev, "Failed to register GPIO chip! (%d)\n",
err);
return err;
}
platform_device_register_data(vexpress_sysreg_dev, "leds-gpio",
PLATFORM_DEVID_AUTO, &vexpress_sysreg_leds_pdata,
sizeof(vexpress_sysreg_leds_pdata));
#endif
device_create_file(vexpress_sysreg_dev, &dev_attr_sys_id);
return 0;
}
static int __init vexpress_sysreg_init(void)
{
vexpress_sysreg_of_early_init();
return platform_driver_register(&vexpress_sysreg_driver);
}
