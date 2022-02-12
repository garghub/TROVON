static int regmap_mmio_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
struct regmap_mmio_context *ctx = context;
u32 offset;
BUG_ON(reg_size != 4);
offset = be32_to_cpup(reg);
while (val_size) {
switch (ctx->val_bytes) {
case 1:
writeb(*(u8 *)val, ctx->regs + offset);
break;
case 2:
writew(be16_to_cpup(val), ctx->regs + offset);
break;
case 4:
writel(be32_to_cpup(val), ctx->regs + offset);
break;
#ifdef CONFIG_64BIT
case 8:
writeq(be64_to_cpup(val), ctx->regs + offset);
break;
#endif
default:
BUG();
}
val_size -= ctx->val_bytes;
val += ctx->val_bytes;
offset += ctx->val_bytes;
}
return 0;
}
static int regmap_mmio_write(void *context, const void *data, size_t count)
{
BUG_ON(count < 4);
return regmap_mmio_gather_write(context, data, 4, data + 4, count - 4);
}
static int regmap_mmio_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct regmap_mmio_context *ctx = context;
u32 offset;
BUG_ON(reg_size != 4);
offset = be32_to_cpup(reg);
while (val_size) {
switch (ctx->val_bytes) {
case 1:
*(u8 *)val = readb(ctx->regs + offset);
break;
case 2:
*(u16 *)val = cpu_to_be16(readw(ctx->regs + offset));
break;
case 4:
*(u32 *)val = cpu_to_be32(readl(ctx->regs + offset));
break;
#ifdef CONFIG_64BIT
case 8:
*(u64 *)val = cpu_to_be32(readq(ctx->regs + offset));
break;
#endif
default:
BUG();
}
val_size -= ctx->val_bytes;
val += ctx->val_bytes;
offset += ctx->val_bytes;
}
return 0;
}
static void regmap_mmio_free_context(void *context)
{
kfree(context);
}
struct regmap_mmio_context *regmap_mmio_gen_context(void __iomem *regs,
const struct regmap_config *config)
{
struct regmap_mmio_context *ctx;
int min_stride;
if (config->reg_bits != 32)
return ERR_PTR(-EINVAL);
if (config->pad_bits)
return ERR_PTR(-EINVAL);
switch (config->val_bits) {
case 8:
min_stride = 0;
break;
case 16:
min_stride = 2;
break;
case 32:
min_stride = 4;
break;
#ifdef CONFIG_64BIT
case 64:
min_stride = 8;
break;
#endif
break;
default:
return ERR_PTR(-EINVAL);
}
if (config->reg_stride < min_stride)
return ERR_PTR(-EINVAL);
ctx = kzalloc(GFP_KERNEL, sizeof(*ctx));
if (!ctx)
return ERR_PTR(-ENOMEM);
ctx->regs = regs;
ctx->val_bytes = config->val_bits / 8;
return ctx;
}
struct regmap *regmap_init_mmio(struct device *dev,
void __iomem *regs,
const struct regmap_config *config)
{
struct regmap_mmio_context *ctx;
ctx = regmap_mmio_gen_context(regs, config);
if (IS_ERR(ctx))
return ERR_CAST(ctx);
return regmap_init(dev, &regmap_mmio, ctx, config);
}
struct regmap *devm_regmap_init_mmio(struct device *dev,
void __iomem *regs,
const struct regmap_config *config)
{
struct regmap_mmio_context *ctx;
ctx = regmap_mmio_gen_context(regs, config);
if (IS_ERR(ctx))
return ERR_CAST(ctx);
return devm_regmap_init(dev, &regmap_mmio, ctx, config);
}
