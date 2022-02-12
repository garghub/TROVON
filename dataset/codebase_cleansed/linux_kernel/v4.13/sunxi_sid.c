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
offset += sid->value_offset;
while (bytes--)
*buf++ = sunxi_sid_read_byte(sid, offset++);
return 0;
}
static int sun8i_sid_register_readout(const struct sunxi_sid *sid,
const unsigned int word)
{
u32 reg_val;
int ret;
reg_val = (word & SUN8I_SID_OFFSET_MASK)
<< SUN8I_SID_OFFSET_SHIFT;
reg_val |= SUN8I_SID_OP_LOCK | SUN8I_SID_READ;
writel(reg_val, sid->base + SUN8I_SID_PRCTL);
ret = readl_poll_timeout(sid->base + SUN8I_SID_PRCTL, reg_val,
!(reg_val & SUN8I_SID_READ), 100, 250000);
if (ret)
return ret;
writel(0, sid->base + SUN8I_SID_PRCTL);
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
const struct sunxi_sid_cfg *cfg;
sid = devm_kzalloc(dev, sizeof(*sid), GFP_KERNEL);
if (!sid)
return -ENOMEM;
cfg = of_device_get_match_data(dev);
if (!cfg)
return -EINVAL;
sid->value_offset = cfg->value_offset;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sid->base = devm_ioremap_resource(dev, res);
if (IS_ERR(sid->base))
return PTR_ERR(sid->base);
size = cfg->size;
if (cfg->need_register_readout) {
for (i = 0; i < (size >> 2); i++) {
ret = sun8i_sid_register_readout(sid, i);
if (ret)
return ret;
}
}
econfig.size = size;
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
