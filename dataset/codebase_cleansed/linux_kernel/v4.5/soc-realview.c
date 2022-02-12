static const char *realview_board_str(u32 id)
{
switch ((id >> 16) & 0xfff) {
case 0x0147:
return "HBI-0147";
case 0x0159:
return "HBI-0159";
default:
return "Unknown";
}
}
static const char *realview_arch_str(u32 id)
{
switch ((id >> 8) & 0xf) {
case 0x04:
return "AHB";
case 0x05:
return "Multi-layer AXI";
default:
return "Unknown";
}
}
static ssize_t realview_get_manf(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%02x\n", realview_coreid >> 24);
}
static ssize_t realview_get_board(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", realview_board_str(realview_coreid));
}
static ssize_t realview_get_arch(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%s\n", realview_arch_str(realview_coreid));
}
static ssize_t realview_get_build(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%02x\n", (realview_coreid & 0xFF));
}
static int realview_soc_probe(struct platform_device *pdev)
{
static struct regmap *syscon_regmap;
struct soc_device *soc_dev;
struct soc_device_attribute *soc_dev_attr;
struct device_node *np = pdev->dev.of_node;
int ret;
syscon_regmap = syscon_regmap_lookup_by_phandle(np, "regmap");
if (IS_ERR(syscon_regmap))
return PTR_ERR(syscon_regmap);
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
return -ENOMEM;
ret = of_property_read_string(np, "compatible",
&soc_dev_attr->soc_id);
if (ret)
return -EINVAL;
soc_dev_attr->machine = "RealView";
soc_dev_attr->family = "Versatile";
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr);
return -ENODEV;
}
ret = regmap_read(syscon_regmap, REALVIEW_SYS_ID_OFFSET,
&realview_coreid);
if (ret)
return -ENODEV;
device_create_file(soc_device_to_device(soc_dev), &realview_manf_attr);
device_create_file(soc_device_to_device(soc_dev), &realview_board_attr);
device_create_file(soc_device_to_device(soc_dev), &realview_arch_attr);
device_create_file(soc_device_to_device(soc_dev), &realview_build_attr);
dev_info(&pdev->dev, "RealView Syscon Core ID: 0x%08x\n",
realview_coreid);
return 0;
}
