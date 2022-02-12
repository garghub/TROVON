static int vexpress_syscfg_exec(struct vexpress_syscfg_func *func,
int index, bool write, u32 *data)
{
struct vexpress_syscfg *syscfg = func->syscfg;
u32 command, status;
int tries;
long timeout;
if (WARN_ON(index > func->num_templates))
return -EINVAL;
command = readl(syscfg->base + SYS_CFGCTRL);
if (WARN_ON(command & SYS_CFGCTRL_START))
return -EBUSY;
command = func->template[index];
command |= SYS_CFGCTRL_START;
command |= write ? SYS_CFGCTRL_WRITE : 0;
if (!write)
*data = 0xdeadbeef;
dev_dbg(syscfg->dev, "func %p, command %x, data %x\n",
func, command, *data);
writel(*data, syscfg->base + SYS_CFGDATA);
writel(0, syscfg->base + SYS_CFGSTAT);
writel(command, syscfg->base + SYS_CFGCTRL);
mb();
tries = 100;
timeout = 100;
do {
if (!irqs_disabled()) {
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(usecs_to_jiffies(timeout));
if (signal_pending(current))
return -EINTR;
} else {
udelay(timeout);
}
status = readl(syscfg->base + SYS_CFGSTAT);
if (status & SYS_CFGSTAT_ERR)
return -EFAULT;
if (timeout > 20)
timeout -= 20;
} while (--tries && !(status & SYS_CFGSTAT_COMPLETE));
if (WARN_ON_ONCE(!tries))
return -ETIMEDOUT;
if (!write) {
*data = readl(syscfg->base + SYS_CFGDATA);
dev_dbg(syscfg->dev, "func %p, read data %x\n", func, *data);
}
return 0;
}
static int vexpress_syscfg_read(void *context, unsigned int index,
unsigned int *val)
{
struct vexpress_syscfg_func *func = context;
return vexpress_syscfg_exec(func, index, false, val);
}
static int vexpress_syscfg_write(void *context, unsigned int index,
unsigned int val)
{
struct vexpress_syscfg_func *func = context;
return vexpress_syscfg_exec(func, index, true, &val);
}
static struct regmap *vexpress_syscfg_regmap_init(struct device *dev,
void *context)
{
int err;
struct vexpress_syscfg *syscfg = context;
struct vexpress_syscfg_func *func;
struct property *prop;
const __be32 *val = NULL;
__be32 energy_quirk[4];
int num;
u32 site, position, dcc;
int i;
err = vexpress_config_get_topo(dev->of_node, &site,
&position, &dcc);
if (err)
return ERR_PTR(err);
prop = of_find_property(dev->of_node,
"arm,vexpress-sysreg,func", NULL);
if (!prop)
return ERR_PTR(-EINVAL);
num = prop->length / sizeof(u32) / 2;
val = prop->value;
if (num == 1 && of_device_is_compatible(dev->of_node,
"arm,vexpress-energy")) {
num = 2;
energy_quirk[0] = *val;
energy_quirk[2] = *val++;
energy_quirk[1] = *val;
energy_quirk[3] = cpu_to_be32(be32_to_cpup(val) + 1);
val = energy_quirk;
}
func = kzalloc(sizeof(*func) + sizeof(*func->template) * num,
GFP_KERNEL);
if (!func)
return ERR_PTR(-ENOMEM);
func->syscfg = syscfg;
func->num_templates = num;
for (i = 0; i < num; i++) {
u32 function, device;
function = be32_to_cpup(val++);
device = be32_to_cpup(val++);
dev_dbg(dev, "func %p: %u/%u/%u/%u/%u\n",
func, site, position, dcc,
function, device);
func->template[i] = SYS_CFGCTRL_DCC(dcc);
func->template[i] |= SYS_CFGCTRL_SITE(site);
func->template[i] |= SYS_CFGCTRL_POSITION(position);
func->template[i] |= SYS_CFGCTRL_FUNC(function);
func->template[i] |= SYS_CFGCTRL_DEVICE(device);
}
vexpress_syscfg_regmap_config.max_register = num - 1;
func->regmap = regmap_init(dev, NULL, func,
&vexpress_syscfg_regmap_config);
if (IS_ERR(func->regmap)) {
void *err = func->regmap;
kfree(func);
return err;
}
list_add(&func->list, &syscfg->funcs);
return func->regmap;
}
static void vexpress_syscfg_regmap_exit(struct regmap *regmap, void *context)
{
struct vexpress_syscfg *syscfg = context;
struct vexpress_syscfg_func *func, *tmp;
regmap_exit(regmap);
list_for_each_entry_safe(func, tmp, &syscfg->funcs, list) {
if (func->regmap == regmap) {
list_del(&syscfg->funcs);
kfree(func);
break;
}
}
}
static int vexpress_syscfg_probe(struct platform_device *pdev)
{
struct vexpress_syscfg *syscfg;
struct resource *res;
struct device *bridge;
syscfg = devm_kzalloc(&pdev->dev, sizeof(*syscfg), GFP_KERNEL);
if (!syscfg)
return -ENOMEM;
syscfg->dev = &pdev->dev;
INIT_LIST_HEAD(&syscfg->funcs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), pdev->name))
return -EBUSY;
syscfg->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!syscfg->base)
return -EFAULT;
bridge = vexpress_config_bridge_register(pdev->dev.parent,
&vexpress_syscfg_bridge_ops, syscfg);
if (IS_ERR(bridge))
return PTR_ERR(bridge);
return 0;
}
static int __init vexpress_syscfg_init(void)
{
return platform_driver_register(&vexpress_syscfg_driver);
}
