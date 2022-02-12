static inline void set_command(void __iomem *base, u32 command)
{
writel(command & OTPC_CMD_MASK, base + OTPC_COMMAND_OFFSET);
}
static inline void set_cpu_address(void __iomem *base, u32 addr)
{
writel(addr & OTPC_ADDR_MASK, base + OTPC_CPUADDR_REG_OFFSET);
}
static inline void set_start_bit(void __iomem *base)
{
writel(1 << OTPC_CMD_START_START, base + OTPC_CMD_START_OFFSET);
}
static inline void reset_start_bit(void __iomem *base)
{
writel(0, base + OTPC_CMD_START_OFFSET);
}
static inline void write_cpu_data(void __iomem *base, u32 value)
{
writel(value, base + OTPC_CPU_WRITE_REG_OFFSET);
}
static int poll_cpu_status(void __iomem *base, u32 value)
{
u32 status;
u32 retries;
for (retries = 0; retries < OTPC_RETRIES; retries++) {
status = readl(base + OTPC_CPU_STATUS_OFFSET);
if (status & value)
break;
udelay(1);
}
if (retries == OTPC_RETRIES)
return -EAGAIN;
return 0;
}
static int enable_ocotp_program(void __iomem *base)
{
static const u32 vals[] = OTPC_PROG_EN_SEQ;
int i;
int ret;
set_command(base, OTPC_CMD_OTP_PROG_ENABLE);
for (i = 0; i < ARRAY_SIZE(vals); i++) {
write_cpu_data(base, vals[i]);
set_start_bit(base);
ret = poll_cpu_status(base, OTPC_STAT_CMD_DONE);
reset_start_bit(base);
if (ret)
return ret;
}
return poll_cpu_status(base, OTPC_STAT_PROG_OK);
}
static int disable_ocotp_program(void __iomem *base)
{
int ret;
set_command(base, OTPC_CMD_OTP_PROG_DISABLE);
set_start_bit(base);
ret = poll_cpu_status(base, OTPC_STAT_PROG_OK);
reset_start_bit(base);
return ret;
}
static int bcm_otpc_read(void *context, unsigned int offset, void *val,
size_t bytes)
{
struct otpc_priv *priv = context;
u32 *buf = val;
u32 bytes_read;
u32 address = offset / priv->config->word_size;
int i, ret;
for (bytes_read = 0; bytes_read < bytes;) {
set_command(priv->base, OTPC_CMD_READ);
set_cpu_address(priv->base, address++);
set_start_bit(priv->base);
ret = poll_cpu_status(priv->base, OTPC_STAT_CMD_DONE);
if (ret) {
dev_err(priv->dev, "otp read error: 0x%x", ret);
return -EIO;
}
for (i = 0; i < priv->map->otpc_row_size; i++) {
*buf++ = readl(priv->base +
priv->map->data_r_offset[i]);
bytes_read += sizeof(*buf);
}
reset_start_bit(priv->base);
}
return 0;
}
static int bcm_otpc_write(void *context, unsigned int offset, void *val,
size_t bytes)
{
struct otpc_priv *priv = context;
u32 *buf = val;
u32 bytes_written;
u32 address = offset / priv->config->word_size;
int i, ret;
if (offset % priv->config->word_size)
return -EINVAL;
ret = enable_ocotp_program(priv->base);
if (ret)
return -EIO;
for (bytes_written = 0; bytes_written < bytes;) {
set_command(priv->base, OTPC_CMD_PROGRAM);
set_cpu_address(priv->base, address++);
for (i = 0; i < priv->map->otpc_row_size; i++) {
writel(*buf, priv->base + priv->map->data_r_offset[i]);
buf++;
bytes_written += sizeof(*buf);
}
set_start_bit(priv->base);
ret = poll_cpu_status(priv->base, OTPC_STAT_CMD_DONE);
reset_start_bit(priv->base);
if (ret) {
dev_err(priv->dev, "otp write error: 0x%x", ret);
return -EIO;
}
}
disable_ocotp_program(priv->base);
return 0;
}
static int bcm_otpc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node;
struct resource *res;
struct otpc_priv *priv;
struct nvmem_device *nvmem;
int err;
u32 num_words;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (of_device_is_compatible(dev->of_node, "brcm,ocotp"))
priv->map = &otp_map;
else if (of_device_is_compatible(dev->of_node, "brcm,ocotp-v2"))
priv->map = &otp_map_v2;
else {
dev_err(&pdev->dev,
"%s otpc config map not defined\n", __func__);
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base)) {
dev_err(dev, "unable to map I/O memory\n");
return PTR_ERR(priv->base);
}
writel(readl(priv->base + OTPC_MODE_REG_OFFSET) |
BIT(OTPC_MODE_REG_OTPC_MODE),
priv->base + OTPC_MODE_REG_OFFSET);
reset_start_bit(priv->base);
err = of_property_read_u32(dn, "brcm,ocotp-size", &num_words);
if (err) {
dev_err(dev, "size parameter not specified\n");
return -EINVAL;
} else if (num_words == 0) {
dev_err(dev, "size must be > 0\n");
return -EINVAL;
}
bcm_otpc_nvmem_config.size = 4 * num_words;
bcm_otpc_nvmem_config.dev = dev;
bcm_otpc_nvmem_config.priv = priv;
if (of_device_is_compatible(dev->of_node, "brcm,ocotp-v2")) {
bcm_otpc_nvmem_config.word_size = 8;
bcm_otpc_nvmem_config.stride = 8;
}
priv->config = &bcm_otpc_nvmem_config;
nvmem = nvmem_register(&bcm_otpc_nvmem_config);
if (IS_ERR(nvmem)) {
dev_err(dev, "error registering nvmem config\n");
return PTR_ERR(nvmem);
}
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int bcm_otpc_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
