static u8 sunxi_sid_read_byte(const struct sunxi_sid *sid,
const unsigned int offset)
{
u32 sid_key;
sid_key = ioread32be(sid->base + round_down(offset, 4));
sid_key >>= (offset % 4) * 8;
return sid_key;
}
static int sunxi_sid_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct sunxi_sid *sid = context;
unsigned int offset = *(u32 *)reg;
u8 *buf = val;
while (val_size) {
*buf++ = sunxi_sid_read_byte(sid, offset);
val_size--;
offset++;
}
return 0;
}
static int sunxi_sid_write(void *context, const void *data, size_t count)
{
return 0;
}
static bool sunxi_sid_writeable_reg(struct device *dev, unsigned int reg)
{
return false;
}
static int sunxi_sid_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct nvmem_device *nvmem;
struct regmap *regmap;
struct sunxi_sid *sid;
int ret, i, size;
char *randomness;
sid = devm_kzalloc(dev, sizeof(*sid), GFP_KERNEL);
if (!sid)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sid->base = devm_ioremap_resource(dev, res);
if (IS_ERR(sid->base))
return PTR_ERR(sid->base);
size = resource_size(res) - 1;
sunxi_sid_regmap_config.max_register = size;
regmap = devm_regmap_init(dev, &sunxi_sid_bus, sid,
&sunxi_sid_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(regmap);
}
econfig.dev = dev;
nvmem = nvmem_register(&econfig);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
randomness = kzalloc(sizeof(u8) * (size), GFP_KERNEL);
if (!randomness) {
ret = -EINVAL;
goto err_unreg_nvmem;
}
for (i = 0; i < size; i++)
randomness[i] = sunxi_sid_read_byte(sid, i);
add_device_randomness(randomness, size);
kfree(randomness);
platform_set_drvdata(pdev, nvmem);
return 0;
err_unreg_nvmem:
nvmem_unregister(nvmem);
return ret;
}
static int sunxi_sid_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
