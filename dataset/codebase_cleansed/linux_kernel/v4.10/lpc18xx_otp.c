static int lpc18xx_otp_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct lpc18xx_otp *otp = context;
unsigned int count = bytes >> 2;
u32 index = offset >> 2;
u32 *buf = val;
int i;
if (count > (LPC18XX_OTP_SIZE - index))
count = LPC18XX_OTP_SIZE - index;
for (i = index; i < (index + count); i++)
*buf++ = readl(otp->base + i * LPC18XX_OTP_WORD_SIZE);
return 0;
}
static int lpc18xx_otp_probe(struct platform_device *pdev)
{
struct nvmem_device *nvmem;
struct lpc18xx_otp *otp;
struct resource *res;
otp = devm_kzalloc(&pdev->dev, sizeof(*otp), GFP_KERNEL);
if (!otp)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
otp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(otp->base))
return PTR_ERR(otp->base);
lpc18xx_otp_nvmem_config.size = LPC18XX_OTP_SIZE;
lpc18xx_otp_nvmem_config.dev = &pdev->dev;
lpc18xx_otp_nvmem_config.priv = otp;
nvmem = nvmem_register(&lpc18xx_otp_nvmem_config);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int lpc18xx_otp_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
