static u8 sunxi_sid_read_byte(const struct sunxi_sid_data *sid_data,
const unsigned int offset)
{
u32 sid_key;
if (offset >= sid_data->keysize)
return 0;
sid_key = ioread32be(sid_data->reg_base + round_down(offset, 4));
sid_key >>= (offset % 4) * 8;
return sid_key;
}
static ssize_t sid_read(struct file *fd, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t pos, size_t size)
{
struct platform_device *pdev;
struct sunxi_sid_data *sid_data;
int i;
pdev = to_platform_device(kobj_to_dev(kobj));
sid_data = platform_get_drvdata(pdev);
if (pos < 0 || pos >= sid_data->keysize)
return 0;
if (size > sid_data->keysize - pos)
size = sid_data->keysize - pos;
for (i = 0; i < size; i++)
buf[i] = sunxi_sid_read_byte(sid_data, pos + i);
return i;
}
static int sunxi_sid_remove(struct platform_device *pdev)
{
device_remove_bin_file(&pdev->dev, &sid_bin_attr);
dev_dbg(&pdev->dev, "driver unloaded\n");
return 0;
}
static int sunxi_sid_probe(struct platform_device *pdev)
{
struct sunxi_sid_data *sid_data;
struct resource *res;
const struct of_device_id *of_dev_id;
u8 *entropy;
unsigned int i;
sid_data = devm_kzalloc(&pdev->dev, sizeof(struct sunxi_sid_data),
GFP_KERNEL);
if (!sid_data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sid_data->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sid_data->reg_base))
return PTR_ERR(sid_data->reg_base);
of_dev_id = of_match_device(sunxi_sid_of_match, &pdev->dev);
if (!of_dev_id)
return -ENODEV;
sid_data->keysize = (int)of_dev_id->data;
platform_set_drvdata(pdev, sid_data);
sid_bin_attr.size = sid_data->keysize;
if (device_create_bin_file(&pdev->dev, &sid_bin_attr))
return -ENODEV;
entropy = kzalloc(sizeof(u8) * sid_data->keysize, GFP_KERNEL);
for (i = 0; i < sid_data->keysize; i++)
entropy[i] = sunxi_sid_read_byte(sid_data, i);
add_device_randomness(entropy, sid_data->keysize);
kfree(entropy);
dev_dbg(&pdev->dev, "loaded\n");
return 0;
}
