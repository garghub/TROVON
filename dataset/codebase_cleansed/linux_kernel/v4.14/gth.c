static void gth_output_set(struct gth_device *gth, int port,
unsigned int config)
{
unsigned long reg = port & 4 ? REG_GTH_GTHOPT1 : REG_GTH_GTHOPT0;
u32 val;
int shift = (port & 3) * 8;
val = ioread32(gth->base + reg);
val &= ~(0xff << shift);
val |= config << shift;
iowrite32(val, gth->base + reg);
}
static unsigned int gth_output_get(struct gth_device *gth, int port)
{
unsigned long reg = port & 4 ? REG_GTH_GTHOPT1 : REG_GTH_GTHOPT0;
u32 val;
int shift = (port & 3) * 8;
val = ioread32(gth->base + reg);
val &= 0xff << shift;
val >>= shift;
return val;
}
static void gth_smcfreq_set(struct gth_device *gth, int port,
unsigned int freq)
{
unsigned long reg = REG_GTH_SMCR0 + ((port / 2) * 4);
int shift = (port & 1) * 16;
u32 val;
val = ioread32(gth->base + reg);
val &= ~(0xffff << shift);
val |= freq << shift;
iowrite32(val, gth->base + reg);
}
static unsigned int gth_smcfreq_get(struct gth_device *gth, int port)
{
unsigned long reg = REG_GTH_SMCR0 + ((port / 2) * 4);
int shift = (port & 1) * 16;
u32 val;
val = ioread32(gth->base + reg);
val &= 0xffff << shift;
val >>= shift;
return val;
}
static void
gth_master_set(struct gth_device *gth, unsigned int master, int port)
{
unsigned int reg = REG_GTH_SWDEST0 + ((master >> 1) & ~3u);
unsigned int shift = (master & 0x7) * 4;
u32 val;
if (master >= 256) {
reg = REG_GTH_GSWTDEST;
shift = 0;
}
val = ioread32(gth->base + reg);
val &= ~(0xf << shift);
if (port >= 0)
val |= (0x8 | port) << shift;
iowrite32(val, gth->base + reg);
}
static ssize_t master_attr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct master_attribute *ma =
container_of(attr, struct master_attribute, attr);
struct gth_device *gth = ma->gth;
size_t count;
int port;
spin_lock(&gth->gth_lock);
port = gth->master[ma->master];
spin_unlock(&gth->gth_lock);
if (port >= 0)
count = snprintf(buf, PAGE_SIZE, "%x\n", port);
else
count = snprintf(buf, PAGE_SIZE, "disabled\n");
return count;
}
static ssize_t master_attr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct master_attribute *ma =
container_of(attr, struct master_attribute, attr);
struct gth_device *gth = ma->gth;
int old_port, port;
if (kstrtoint(buf, 10, &port) < 0)
return -EINVAL;
if (port >= TH_POSSIBLE_OUTPUTS || port < -1)
return -EINVAL;
spin_lock(&gth->gth_lock);
old_port = gth->master[ma->master];
if (old_port >= 0) {
gth->master[ma->master] = -1;
clear_bit(ma->master, gth->output[old_port].master);
if (gth->output[old_port].output->active)
gth_master_set(gth, ma->master, -1);
}
if (port >= 0) {
if (!gth->output[port].output) {
count = -ENODEV;
goto unlock;
}
set_bit(ma->master, gth->output[port].master);
if (gth->output[port].output->active)
gth_master_set(gth, ma->master, port);
}
gth->master[ma->master] = port;
unlock:
spin_unlock(&gth->gth_lock);
return count;
}
static void
gth_output_parm_set(struct gth_device *gth, int port, unsigned int parm,
unsigned int val)
{
unsigned int config = output_parms[parm].get(gth, port);
unsigned int mask = output_parms[parm].mask;
unsigned int shift = __ffs(mask);
config &= ~mask;
config |= (val << shift) & mask;
output_parms[parm].set(gth, port, config);
}
static unsigned int
gth_output_parm_get(struct gth_device *gth, int port, unsigned int parm)
{
unsigned int config = output_parms[parm].get(gth, port);
unsigned int mask = output_parms[parm].mask;
unsigned int shift = __ffs(mask);
config &= mask;
config >>= shift;
return config;
}
static int intel_th_gth_reset(struct gth_device *gth)
{
u32 reg;
int port, i;
reg = ioread32(gth->base + REG_GTH_SCRPD0);
if (reg & SCRPD_DEBUGGER_IN_USE)
return -EBUSY;
reg |= SCRPD_STH_IS_ENABLED | SCRPD_TRIGGER_IS_ENABLED;
iowrite32(reg, gth->base + REG_GTH_SCRPD0);
for (port = 0; port < 8; port++) {
if (gth_output_parm_get(gth, port, TH_OUTPUT_PARM(port)) ==
GTH_NONE)
continue;
gth_output_set(gth, port, 0);
gth_smcfreq_set(gth, port, 16);
}
iowrite32(0, gth->base + REG_GTH_DESTOVR);
for (i = 0; i < 33; i++)
iowrite32(0, gth->base + REG_GTH_SWDEST0 + i * 4);
iowrite32(0, gth->base + REG_GTH_SCR);
iowrite32(0xfc, gth->base + REG_GTH_SCR2);
return 0;
}
static ssize_t output_attr_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct output_attribute *oa =
container_of(attr, struct output_attribute, attr);
struct gth_device *gth = oa->gth;
size_t count;
pm_runtime_get_sync(dev);
spin_lock(&gth->gth_lock);
count = snprintf(buf, PAGE_SIZE, "%x\n",
gth_output_parm_get(gth, oa->port, oa->parm));
spin_unlock(&gth->gth_lock);
pm_runtime_put(dev);
return count;
}
static ssize_t output_attr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct output_attribute *oa =
container_of(attr, struct output_attribute, attr);
struct gth_device *gth = oa->gth;
unsigned int config;
if (kstrtouint(buf, 16, &config) < 0)
return -EINVAL;
pm_runtime_get_sync(dev);
spin_lock(&gth->gth_lock);
gth_output_parm_set(gth, oa->port, oa->parm, config);
spin_unlock(&gth->gth_lock);
pm_runtime_put(dev);
return count;
}
static int intel_th_master_attributes(struct gth_device *gth)
{
struct master_attribute *master_attrs;
struct attribute **attrs;
int i, nattrs = TH_CONFIGURABLE_MASTERS + 2;
attrs = devm_kcalloc(gth->dev, nattrs, sizeof(void *), GFP_KERNEL);
if (!attrs)
return -ENOMEM;
master_attrs = devm_kcalloc(gth->dev, nattrs,
sizeof(struct master_attribute),
GFP_KERNEL);
if (!master_attrs)
return -ENOMEM;
for (i = 0; i < TH_CONFIGURABLE_MASTERS + 1; i++) {
char *name;
name = devm_kasprintf(gth->dev, GFP_KERNEL, "%d%s", i,
i == TH_CONFIGURABLE_MASTERS ? "+" : "");
if (!name)
return -ENOMEM;
master_attrs[i].attr.attr.name = name;
master_attrs[i].attr.attr.mode = S_IRUGO | S_IWUSR;
master_attrs[i].attr.show = master_attr_show;
master_attrs[i].attr.store = master_attr_store;
sysfs_attr_init(&master_attrs[i].attr.attr);
attrs[i] = &master_attrs[i].attr.attr;
master_attrs[i].gth = gth;
master_attrs[i].master = i;
}
gth->master_group.name = "masters";
gth->master_group.attrs = attrs;
return sysfs_create_group(&gth->dev->kobj, &gth->master_group);
}
static int intel_th_output_attributes(struct gth_device *gth)
{
struct output_attribute *out_attrs;
struct attribute **attrs;
int i, j, nouts = TH_POSSIBLE_OUTPUTS;
int nparms = ARRAY_SIZE(output_parms);
int nattrs = nouts * nparms + 1;
attrs = devm_kcalloc(gth->dev, nattrs, sizeof(void *), GFP_KERNEL);
if (!attrs)
return -ENOMEM;
out_attrs = devm_kcalloc(gth->dev, nattrs,
sizeof(struct output_attribute),
GFP_KERNEL);
if (!out_attrs)
return -ENOMEM;
for (i = 0; i < nouts; i++) {
for (j = 0; j < nparms; j++) {
unsigned int idx = i * nparms + j;
char *name;
name = devm_kasprintf(gth->dev, GFP_KERNEL, "%d_%s", i,
output_parms[j].name);
if (!name)
return -ENOMEM;
out_attrs[idx].attr.attr.name = name;
if (output_parms[j].readable) {
out_attrs[idx].attr.attr.mode |= S_IRUGO;
out_attrs[idx].attr.show = output_attr_show;
}
if (output_parms[j].writable) {
out_attrs[idx].attr.attr.mode |= S_IWUSR;
out_attrs[idx].attr.store = output_attr_store;
}
sysfs_attr_init(&out_attrs[idx].attr.attr);
attrs[idx] = &out_attrs[idx].attr.attr;
out_attrs[idx].gth = gth;
out_attrs[idx].port = i;
out_attrs[idx].parm = j;
}
}
gth->output_group.name = "outputs";
gth->output_group.attrs = attrs;
return sysfs_create_group(&gth->dev->kobj, &gth->output_group);
}
static void intel_th_gth_disable(struct intel_th_device *thdev,
struct intel_th_output *output)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
unsigned long count;
int master;
u32 reg;
spin_lock(&gth->gth_lock);
output->active = false;
for_each_set_bit(master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS) {
gth_master_set(gth, master, -1);
}
spin_unlock(&gth->gth_lock);
iowrite32(0, gth->base + REG_GTH_SCR);
iowrite32(0xfd, gth->base + REG_GTH_SCR2);
for (reg = 0, count = GTH_PLE_WAITLOOP_DEPTH;
count && !(reg & BIT(output->port)); count--) {
reg = ioread32(gth->base + REG_GTH_STAT);
cpu_relax();
}
iowrite32(0xfc, gth->base + REG_GTH_SCR2);
if (!count)
dev_dbg(&thdev->dev, "timeout waiting for GTH[%d] PLE\n",
output->port);
reg = ioread32(gth->base + REG_GTH_SCRPD0);
reg &= ~output->scratchpad;
iowrite32(reg, gth->base + REG_GTH_SCRPD0);
}
static void gth_tscu_resync(struct gth_device *gth)
{
u32 reg;
reg = ioread32(gth->base + REG_TSCU_TSUCTRL);
reg &= ~TSUCTRL_CTCRESYNC;
iowrite32(reg, gth->base + REG_TSCU_TSUCTRL);
}
static void intel_th_gth_enable(struct intel_th_device *thdev,
struct intel_th_output *output)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
struct intel_th *th = to_intel_th(thdev);
u32 scr = 0xfc0000, scrpd;
int master;
spin_lock(&gth->gth_lock);
for_each_set_bit(master, gth->output[output->port].master,
TH_CONFIGURABLE_MASTERS + 1) {
gth_master_set(gth, master, output->port);
}
if (output->multiblock)
scr |= 0xff;
output->active = true;
spin_unlock(&gth->gth_lock);
if (INTEL_TH_CAP(th, tscu_enable))
gth_tscu_resync(gth);
scrpd = ioread32(gth->base + REG_GTH_SCRPD0);
scrpd |= output->scratchpad;
iowrite32(scrpd, gth->base + REG_GTH_SCRPD0);
iowrite32(scr, gth->base + REG_GTH_SCR);
iowrite32(0, gth->base + REG_GTH_SCR2);
}
static int intel_th_gth_assign(struct intel_th_device *thdev,
struct intel_th_device *othdev)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
int i, id;
if (thdev->host_mode)
return -EBUSY;
if (othdev->type != INTEL_TH_OUTPUT)
return -EINVAL;
for (i = 0, id = 0; i < TH_POSSIBLE_OUTPUTS; i++) {
if (gth->output[i].port_type != othdev->output.type)
continue;
if (othdev->id == -1 || othdev->id == id)
goto found;
id++;
}
return -ENOENT;
found:
spin_lock(&gth->gth_lock);
othdev->output.port = i;
othdev->output.active = false;
gth->output[i].output = &othdev->output;
spin_unlock(&gth->gth_lock);
return 0;
}
static void intel_th_gth_unassign(struct intel_th_device *thdev,
struct intel_th_device *othdev)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
int port = othdev->output.port;
if (thdev->host_mode)
return;
spin_lock(&gth->gth_lock);
othdev->output.port = -1;
othdev->output.active = false;
gth->output[port].output = NULL;
spin_unlock(&gth->gth_lock);
}
static int
intel_th_gth_set_output(struct intel_th_device *thdev, unsigned int master)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
int port = 0;
if (master > TH_CONFIGURABLE_MASTERS)
master = TH_CONFIGURABLE_MASTERS;
spin_lock(&gth->gth_lock);
if (gth->master[master] == -1) {
set_bit(master, gth->output[port].master);
gth->master[master] = port;
}
spin_unlock(&gth->gth_lock);
return 0;
}
static int intel_th_gth_probe(struct intel_th_device *thdev)
{
struct device *dev = &thdev->dev;
struct intel_th *th = dev_get_drvdata(dev->parent);
struct gth_device *gth;
struct resource *res;
void __iomem *base;
int i, ret;
res = intel_th_device_get_resource(thdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
base = devm_ioremap(dev, res->start, resource_size(res));
if (!base)
return -ENOMEM;
gth = devm_kzalloc(dev, sizeof(*gth), GFP_KERNEL);
if (!gth)
return -ENOMEM;
gth->dev = dev;
gth->base = base;
spin_lock_init(&gth->gth_lock);
dev_set_drvdata(dev, gth);
if (thdev->host_mode)
return 0;
ret = intel_th_gth_reset(gth);
if (ret) {
if (ret != -EBUSY)
return ret;
thdev->host_mode = true;
return 0;
}
for (i = 0; i < TH_CONFIGURABLE_MASTERS + 1; i++)
gth->master[i] = -1;
for (i = 0; i < TH_POSSIBLE_OUTPUTS; i++) {
gth->output[i].gth = gth;
gth->output[i].index = i;
gth->output[i].port_type =
gth_output_parm_get(gth, i, TH_OUTPUT_PARM(port));
if (gth->output[i].port_type == GTH_NONE)
continue;
ret = intel_th_output_enable(th, gth->output[i].port_type);
if (ret && ret != -ENODEV)
return ret;
}
if (intel_th_output_attributes(gth) ||
intel_th_master_attributes(gth)) {
pr_warn("Can't initialize sysfs attributes\n");
if (gth->output_group.attrs)
sysfs_remove_group(&gth->dev->kobj, &gth->output_group);
return -ENOMEM;
}
return 0;
}
static void intel_th_gth_remove(struct intel_th_device *thdev)
{
struct gth_device *gth = dev_get_drvdata(&thdev->dev);
sysfs_remove_group(&gth->dev->kobj, &gth->output_group);
sysfs_remove_group(&gth->dev->kobj, &gth->master_group);
}
