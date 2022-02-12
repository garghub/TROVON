static int pti_width_mode(unsigned int width)
{
int i;
for (i = 0; i < ARRAY_SIZE(pti_mode); i++)
if (pti_mode[i] == width)
return i;
return -EINVAL;
}
static ssize_t mode_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pti_device *pti = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", pti_mode[pti->mode]);
}
static ssize_t mode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct pti_device *pti = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
ret = pti_width_mode(val);
if (ret < 0)
return ret;
pti->mode = ret;
return size;
}
static ssize_t
freerunning_clock_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pti_device *pti = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", pti->freeclk);
}
static ssize_t
freerunning_clock_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct pti_device *pti = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
pti->freeclk = !!val;
return size;
}
static ssize_t
clock_divider_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct pti_device *pti = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", 1u << pti->clkdiv);
}
static ssize_t
clock_divider_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct pti_device *pti = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (!is_power_of_2(val) || val > 8 || !val)
return -EINVAL;
pti->clkdiv = val;
return size;
}
static int intel_th_pti_activate(struct intel_th_device *thdev)
{
struct pti_device *pti = dev_get_drvdata(&thdev->dev);
u32 ctl = PTI_EN;
if (pti->patgen)
ctl |= pti->patgen << __ffs(PTI_PATGENMODE);
if (pti->freeclk)
ctl |= PTI_FCEN;
ctl |= pti->mode << __ffs(PTI_MODE);
ctl |= pti->clkdiv << __ffs(PTI_CLKDIV);
iowrite32(ctl, pti->base + REG_PTI_CTL);
intel_th_trace_enable(thdev);
return 0;
}
static void intel_th_pti_deactivate(struct intel_th_device *thdev)
{
struct pti_device *pti = dev_get_drvdata(&thdev->dev);
intel_th_trace_disable(thdev);
iowrite32(0, pti->base + REG_PTI_CTL);
}
static void read_hw_config(struct pti_device *pti)
{
u32 ctl = ioread32(pti->base + REG_PTI_CTL);
pti->mode = (ctl & PTI_MODE) >> __ffs(PTI_MODE);
pti->clkdiv = (ctl & PTI_CLKDIV) >> __ffs(PTI_CLKDIV);
pti->freeclk = !!(ctl & PTI_FCEN);
if (!pti_mode[pti->mode])
pti->mode = pti_width_mode(4);
if (!pti->clkdiv)
pti->clkdiv = 1;
}
static int intel_th_pti_probe(struct intel_th_device *thdev)
{
struct device *dev = &thdev->dev;
struct resource *res;
struct pti_device *pti;
void __iomem *base;
res = intel_th_device_get_resource(thdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
base = devm_ioremap(dev, res->start, resource_size(res));
if (!base)
return -ENOMEM;
pti = devm_kzalloc(dev, sizeof(*pti), GFP_KERNEL);
if (!pti)
return -ENOMEM;
pti->thdev = thdev;
pti->base = base;
read_hw_config(pti);
dev_set_drvdata(dev, pti);
return 0;
}
static void intel_th_pti_remove(struct intel_th_device *thdev)
{
}
