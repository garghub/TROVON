static void boston_update(struct img_ascii_lcd_ctx *ctx)
{
ulong val;
#if BITS_PER_LONG == 64
val = *((u64 *)&ctx->curr[0]);
__raw_writeq(val, ctx->base);
#elif BITS_PER_LONG == 32
val = *((u32 *)&ctx->curr[0]);
__raw_writel(val, ctx->base);
val = *((u32 *)&ctx->curr[4]);
__raw_writel(val, ctx->base + 4);
#else
# error Not 32 or 64 bit
#endif
}
static void malta_update(struct img_ascii_lcd_ctx *ctx)
{
unsigned int i;
int err;
for (i = 0; i < ctx->cfg->num_chars; i++) {
err = regmap_write(ctx->regmap,
ctx->offset + (i * 8), ctx->curr[i]);
if (err)
break;
}
if (unlikely(err))
pr_err_ratelimited("Failed to update LCD display: %d\n", err);
}
static int sead3_wait_sm_idle(struct img_ascii_lcd_ctx *ctx)
{
unsigned int status;
int err;
do {
err = regmap_read(ctx->regmap,
ctx->offset + SEAD3_REG_CPLD_STATUS,
&status);
if (err)
return err;
} while (status & SEAD3_REG_CPLD_STATUS_BUSY);
return 0;
}
static int sead3_wait_lcd_idle(struct img_ascii_lcd_ctx *ctx)
{
unsigned int cpld_data;
int err;
err = sead3_wait_sm_idle(ctx);
if (err)
return err;
do {
err = regmap_read(ctx->regmap,
ctx->offset + SEAD3_REG_LCD_CTRL,
&cpld_data);
if (err)
return err;
err = sead3_wait_sm_idle(ctx);
if (err)
return err;
err = regmap_read(ctx->regmap,
ctx->offset + SEAD3_REG_CPLD_DATA,
&cpld_data);
if (err)
return err;
} while (cpld_data & SEAD3_REG_CPLD_DATA_BUSY);
return 0;
}
static void sead3_update(struct img_ascii_lcd_ctx *ctx)
{
unsigned int i;
int err;
for (i = 0; i < ctx->cfg->num_chars; i++) {
err = sead3_wait_lcd_idle(ctx);
if (err)
break;
err = regmap_write(ctx->regmap,
ctx->offset + SEAD3_REG_LCD_CTRL,
SEAD3_REG_LCD_CTRL_SETDRAM | i);
if (err)
break;
err = sead3_wait_lcd_idle(ctx);
if (err)
break;
err = regmap_write(ctx->regmap,
ctx->offset + SEAD3_REG_LCD_DATA,
ctx->curr[i]);
if (err)
break;
}
if (unlikely(err))
pr_err_ratelimited("Failed to update LCD display: %d\n", err);
}
static void img_ascii_lcd_scroll(unsigned long arg)
{
struct img_ascii_lcd_ctx *ctx = (struct img_ascii_lcd_ctx *)arg;
unsigned int i, ch = ctx->scroll_pos;
unsigned int num_chars = ctx->cfg->num_chars;
for (i = 0; i < num_chars;) {
for (; i < num_chars && ch < ctx->message_len; i++, ch++)
ctx->curr[i] = ctx->message[ch];
ch = 0;
}
ctx->cfg->update(ctx);
ctx->scroll_pos++;
ctx->scroll_pos %= ctx->message_len;
if (ctx->message_len > ctx->cfg->num_chars)
mod_timer(&ctx->timer, jiffies + ctx->scroll_rate);
}
static int img_ascii_lcd_display(struct img_ascii_lcd_ctx *ctx,
const char *msg, ssize_t count)
{
char *new_msg;
del_timer_sync(&ctx->timer);
if (count == -1)
count = strlen(msg);
if (msg[count - 1] == '\n')
count--;
new_msg = devm_kmalloc(&ctx->pdev->dev, count + 1, GFP_KERNEL);
if (!new_msg)
return -ENOMEM;
memcpy(new_msg, msg, count);
new_msg[count] = 0;
if (ctx->message)
devm_kfree(&ctx->pdev->dev, ctx->message);
ctx->message = new_msg;
ctx->message_len = count;
ctx->scroll_pos = 0;
img_ascii_lcd_scroll((unsigned long)ctx);
return 0;
}
static ssize_t message_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct img_ascii_lcd_ctx *ctx = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", ctx->message);
}
static ssize_t message_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct img_ascii_lcd_ctx *ctx = dev_get_drvdata(dev);
int err;
err = img_ascii_lcd_display(ctx, buf, count);
return err ?: count;
}
static int img_ascii_lcd_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
const struct img_ascii_lcd_config *cfg;
struct img_ascii_lcd_ctx *ctx;
struct resource *res;
int err;
match = of_match_device(img_ascii_lcd_matches, &pdev->dev);
if (!match)
return -ENODEV;
cfg = match->data;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx) + cfg->num_chars,
GFP_KERNEL);
if (!ctx)
return -ENOMEM;
if (cfg->external_regmap) {
ctx->regmap = syscon_node_to_regmap(pdev->dev.parent->of_node);
if (IS_ERR(ctx->regmap))
return PTR_ERR(ctx->regmap);
if (of_property_read_u32(pdev->dev.of_node, "offset",
&ctx->offset))
return -EINVAL;
} else {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ctx->base))
return PTR_ERR(ctx->base);
}
ctx->pdev = pdev;
ctx->cfg = cfg;
ctx->message = NULL;
ctx->scroll_pos = 0;
ctx->scroll_rate = HZ / 2;
init_timer(&ctx->timer);
ctx->timer.function = img_ascii_lcd_scroll;
ctx->timer.data = (unsigned long)ctx;
platform_set_drvdata(pdev, ctx);
err = img_ascii_lcd_display(ctx, "Linux " UTS_RELEASE " ", -1);
if (err)
goto out_del_timer;
err = device_create_file(&pdev->dev, &dev_attr_message);
if (err)
goto out_del_timer;
return 0;
out_del_timer:
del_timer_sync(&ctx->timer);
return err;
}
static int img_ascii_lcd_remove(struct platform_device *pdev)
{
struct img_ascii_lcd_ctx *ctx = platform_get_drvdata(pdev);
device_remove_file(&pdev->dev, &dev_attr_message);
del_timer_sync(&ctx->timer);
return 0;
}
