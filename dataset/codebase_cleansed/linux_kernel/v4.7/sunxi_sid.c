static u8 sunxi_sid_read_byte(const struct sunxi_sid *sid,
const unsigned int offset)
{
u32 sid_key;
sid_key = ioread32be(sid->base + round_down(offset, 4));
sid_key >>= (offset % 4) * 8;
return sid_key;
}
static int sunxi_sid_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct sunxi_sid *sid = context;
u8 *buf = val;
while (bytes--)
*buf++ = sunxi_sid_read_byte(sid, offset++);
return 0;
}
static int sunxi_sid_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct nvmem_device *nvmem;
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
econfig.size = resource_size(res);
econfig.dev = dev;
econfig.reg_read = sunxi_sid_read;
econfig.priv = sid;
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
