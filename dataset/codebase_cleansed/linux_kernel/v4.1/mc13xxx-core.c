void mc13xxx_lock(struct mc13xxx *mc13xxx)
{
if (!mutex_trylock(&mc13xxx->lock)) {
dev_dbg(mc13xxx->dev, "wait for %s from %ps\n",
__func__, __builtin_return_address(0));
mutex_lock(&mc13xxx->lock);
}
dev_dbg(mc13xxx->dev, "%s from %ps\n",
__func__, __builtin_return_address(0));
}
void mc13xxx_unlock(struct mc13xxx *mc13xxx)
{
dev_dbg(mc13xxx->dev, "%s from %ps\n",
__func__, __builtin_return_address(0));
mutex_unlock(&mc13xxx->lock);
}
int mc13xxx_reg_read(struct mc13xxx *mc13xxx, unsigned int offset, u32 *val)
{
int ret;
ret = regmap_read(mc13xxx->regmap, offset, val);
dev_vdbg(mc13xxx->dev, "[0x%02x] -> 0x%06x\n", offset, *val);
return ret;
}
int mc13xxx_reg_write(struct mc13xxx *mc13xxx, unsigned int offset, u32 val)
{
dev_vdbg(mc13xxx->dev, "[0x%02x] <- 0x%06x\n", offset, val);
if (val >= BIT(24))
return -EINVAL;
return regmap_write(mc13xxx->regmap, offset, val);
}
int mc13xxx_reg_rmw(struct mc13xxx *mc13xxx, unsigned int offset,
u32 mask, u32 val)
{
BUG_ON(val & ~mask);
dev_vdbg(mc13xxx->dev, "[0x%02x] <- 0x%06x (mask: 0x%06x)\n",
offset, val, mask);
return regmap_update_bits(mc13xxx->regmap, offset, mask, val);
}
int mc13xxx_irq_mask(struct mc13xxx *mc13xxx, int irq)
{
int virq = regmap_irq_get_virq(mc13xxx->irq_data, irq);
disable_irq_nosync(virq);
return 0;
}
int mc13xxx_irq_unmask(struct mc13xxx *mc13xxx, int irq)
{
int virq = regmap_irq_get_virq(mc13xxx->irq_data, irq);
enable_irq(virq);
return 0;
}
int mc13xxx_irq_status(struct mc13xxx *mc13xxx, int irq,
int *enabled, int *pending)
{
int ret;
unsigned int offmask = irq < 24 ? MC13XXX_IRQMASK0 : MC13XXX_IRQMASK1;
unsigned int offstat = irq < 24 ? MC13XXX_IRQSTAT0 : MC13XXX_IRQSTAT1;
u32 irqbit = 1 << (irq < 24 ? irq : irq - 24);
if (irq < 0 || irq >= ARRAY_SIZE(mc13xxx->irqs))
return -EINVAL;
if (enabled) {
u32 mask;
ret = mc13xxx_reg_read(mc13xxx, offmask, &mask);
if (ret)
return ret;
*enabled = mask & irqbit;
}
if (pending) {
u32 stat;
ret = mc13xxx_reg_read(mc13xxx, offstat, &stat);
if (ret)
return ret;
*pending = stat & irqbit;
}
return 0;
}
int mc13xxx_irq_request(struct mc13xxx *mc13xxx, int irq,
irq_handler_t handler, const char *name, void *dev)
{
int virq = regmap_irq_get_virq(mc13xxx->irq_data, irq);
return devm_request_threaded_irq(mc13xxx->dev, virq, NULL, handler,
0, name, dev);
}
int mc13xxx_irq_free(struct mc13xxx *mc13xxx, int irq, void *dev)
{
int virq = regmap_irq_get_virq(mc13xxx->irq_data, irq);
devm_free_irq(mc13xxx->dev, virq, dev);
return 0;
}
static void mc13xxx_print_revision(struct mc13xxx *mc13xxx, u32 revision)
{
dev_info(mc13xxx->dev, "%s: rev: %d.%d, "
"fin: %d, fab: %d, icid: %d/%d\n",
mc13xxx->variant->name,
maskval(revision, MC13XXX_REVISION_REVFULL),
maskval(revision, MC13XXX_REVISION_REVMETAL),
maskval(revision, MC13XXX_REVISION_FIN),
maskval(revision, MC13XXX_REVISION_FAB),
maskval(revision, MC13XXX_REVISION_ICID),
maskval(revision, MC13XXX_REVISION_ICIDCODE));
}
static void mc34708_print_revision(struct mc13xxx *mc13xxx, u32 revision)
{
dev_info(mc13xxx->dev, "%s: rev %d.%d, fin: %d, fab: %d\n",
mc13xxx->variant->name,
maskval(revision, MC34708_REVISION_REVFULL),
maskval(revision, MC34708_REVISION_REVMETAL),
maskval(revision, MC34708_REVISION_FIN),
maskval(revision, MC34708_REVISION_FAB));
}
static const char *mc13xxx_get_chipname(struct mc13xxx *mc13xxx)
{
return mc13xxx->variant->name;
}
int mc13xxx_get_flags(struct mc13xxx *mc13xxx)
{
return mc13xxx->flags;
}
static irqreturn_t mc13xxx_handler_adcdone(int irq, void *data)
{
struct mc13xxx_adcdone_data *adcdone_data = data;
complete_all(&adcdone_data->done);
return IRQ_HANDLED;
}
int mc13xxx_adc_do_conversion(struct mc13xxx *mc13xxx, unsigned int mode,
unsigned int channel, u8 ato, bool atox,
unsigned int *sample)
{
u32 adc0, adc1, old_adc0;
int i, ret;
struct mc13xxx_adcdone_data adcdone_data = {
.mc13xxx = mc13xxx,
};
init_completion(&adcdone_data.done);
dev_dbg(mc13xxx->dev, "%s\n", __func__);
mc13xxx_lock(mc13xxx);
if (mc13xxx->adcflags & MC13XXX_ADC_WORKING) {
ret = -EBUSY;
goto out;
}
mc13xxx->adcflags |= MC13XXX_ADC_WORKING;
mc13xxx_reg_read(mc13xxx, MC13XXX_ADC0, &old_adc0);
adc0 = MC13XXX_ADC0_ADINC1 | MC13XXX_ADC0_ADINC2;
adc1 = MC13XXX_ADC1_ADEN | MC13XXX_ADC1_ADTRIGIGN | MC13XXX_ADC1_ASC;
if (channel > 7)
adc1 |= MC13XXX_ADC1_ADSEL;
switch (mode) {
case MC13XXX_ADC_MODE_TS:
adc0 |= MC13XXX_ADC0_ADREFEN | MC13XXX_ADC0_TSMOD0 |
MC13XXX_ADC0_TSMOD1;
adc1 |= 4 << MC13XXX_ADC1_CHAN1_SHIFT;
break;
case MC13XXX_ADC_MODE_SINGLE_CHAN:
adc0 |= old_adc0 & MC13XXX_ADC0_CONFIG_MASK;
adc1 |= (channel & 0x7) << MC13XXX_ADC1_CHAN0_SHIFT;
adc1 |= MC13XXX_ADC1_RAND;
break;
case MC13XXX_ADC_MODE_MULT_CHAN:
adc0 |= old_adc0 & MC13XXX_ADC0_CONFIG_MASK;
adc1 |= 4 << MC13XXX_ADC1_CHAN1_SHIFT;
break;
default:
mc13xxx_unlock(mc13xxx);
return -EINVAL;
}
adc1 |= ato << MC13783_ADC1_ATO_SHIFT;
if (atox)
adc1 |= MC13783_ADC1_ATOX;
dev_dbg(mc13xxx->dev, "%s: request irq\n", __func__);
mc13xxx_irq_request(mc13xxx, MC13XXX_IRQ_ADCDONE,
mc13xxx_handler_adcdone, __func__, &adcdone_data);
mc13xxx_reg_write(mc13xxx, MC13XXX_ADC0, adc0);
mc13xxx_reg_write(mc13xxx, MC13XXX_ADC1, adc1);
mc13xxx_unlock(mc13xxx);
ret = wait_for_completion_interruptible_timeout(&adcdone_data.done, HZ);
if (!ret)
ret = -ETIMEDOUT;
mc13xxx_lock(mc13xxx);
mc13xxx_irq_free(mc13xxx, MC13XXX_IRQ_ADCDONE, &adcdone_data);
if (ret > 0)
for (i = 0; i < 4; ++i) {
ret = mc13xxx_reg_read(mc13xxx,
MC13XXX_ADC2, &sample[i]);
if (ret)
break;
}
if (mode == MC13XXX_ADC_MODE_TS)
mc13xxx_reg_write(mc13xxx, MC13XXX_ADC0, old_adc0);
mc13xxx->adcflags &= ~MC13XXX_ADC_WORKING;
out:
mc13xxx_unlock(mc13xxx);
return ret;
}
static int mc13xxx_add_subdevice_pdata(struct mc13xxx *mc13xxx,
const char *format, void *pdata, size_t pdata_size)
{
char buf[30];
const char *name = mc13xxx_get_chipname(mc13xxx);
struct mfd_cell cell = {
.platform_data = pdata,
.pdata_size = pdata_size,
};
if (snprintf(buf, sizeof(buf), format, name) > sizeof(buf))
return -E2BIG;
cell.name = kmemdup(buf, strlen(buf) + 1, GFP_KERNEL);
if (!cell.name)
return -ENOMEM;
return mfd_add_devices(mc13xxx->dev, -1, &cell, 1, NULL, 0,
regmap_irq_get_domain(mc13xxx->irq_data));
}
static int mc13xxx_add_subdevice(struct mc13xxx *mc13xxx, const char *format)
{
return mc13xxx_add_subdevice_pdata(mc13xxx, format, NULL, 0);
}
static int mc13xxx_probe_flags_dt(struct mc13xxx *mc13xxx)
{
struct device_node *np = mc13xxx->dev->of_node;
if (!np)
return -ENODEV;
if (of_get_property(np, "fsl,mc13xxx-uses-adc", NULL))
mc13xxx->flags |= MC13XXX_USE_ADC;
if (of_get_property(np, "fsl,mc13xxx-uses-codec", NULL))
mc13xxx->flags |= MC13XXX_USE_CODEC;
if (of_get_property(np, "fsl,mc13xxx-uses-rtc", NULL))
mc13xxx->flags |= MC13XXX_USE_RTC;
if (of_get_property(np, "fsl,mc13xxx-uses-touch", NULL))
mc13xxx->flags |= MC13XXX_USE_TOUCHSCREEN;
return 0;
}
static inline int mc13xxx_probe_flags_dt(struct mc13xxx *mc13xxx)
{
return -ENODEV;
}
int mc13xxx_common_init(struct device *dev)
{
struct mc13xxx_platform_data *pdata = dev_get_platdata(dev);
struct mc13xxx *mc13xxx = dev_get_drvdata(dev);
u32 revision;
int i, ret;
mc13xxx->dev = dev;
ret = mc13xxx_reg_read(mc13xxx, MC13XXX_REVISION, &revision);
if (ret)
return ret;
mc13xxx->variant->print_revision(mc13xxx, revision);
ret = mc13xxx_reg_rmw(mc13xxx, MC13XXX_PWRCTRL,
MC13XXX_PWRCTRL_WDIRESET, MC13XXX_PWRCTRL_WDIRESET);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(mc13xxx->irqs); i++) {
mc13xxx->irqs[i].reg_offset = i / MC13XXX_IRQ_PER_REG;
mc13xxx->irqs[i].mask = BIT(i % MC13XXX_IRQ_PER_REG);
}
mc13xxx->irq_chip.name = dev_name(dev);
mc13xxx->irq_chip.status_base = MC13XXX_IRQSTAT0;
mc13xxx->irq_chip.mask_base = MC13XXX_IRQMASK0;
mc13xxx->irq_chip.ack_base = MC13XXX_IRQSTAT0;
mc13xxx->irq_chip.irq_reg_stride = MC13XXX_IRQSTAT1 - MC13XXX_IRQSTAT0;
mc13xxx->irq_chip.init_ack_masked = true;
mc13xxx->irq_chip.use_ack = true;
mc13xxx->irq_chip.num_regs = MC13XXX_IRQ_REG_CNT;
mc13xxx->irq_chip.irqs = mc13xxx->irqs;
mc13xxx->irq_chip.num_irqs = ARRAY_SIZE(mc13xxx->irqs);
ret = regmap_add_irq_chip(mc13xxx->regmap, mc13xxx->irq, IRQF_ONESHOT,
0, &mc13xxx->irq_chip, &mc13xxx->irq_data);
if (ret)
return ret;
mutex_init(&mc13xxx->lock);
if (mc13xxx_probe_flags_dt(mc13xxx) < 0 && pdata)
mc13xxx->flags = pdata->flags;
if (pdata) {
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-regulator",
&pdata->regulators, sizeof(pdata->regulators));
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-led",
pdata->leds, sizeof(*pdata->leds));
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-pwrbutton",
pdata->buttons, sizeof(*pdata->buttons));
if (mc13xxx->flags & MC13XXX_USE_CODEC)
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-codec",
pdata->codec, sizeof(*pdata->codec));
if (mc13xxx->flags & MC13XXX_USE_TOUCHSCREEN)
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-ts",
&pdata->touch, sizeof(pdata->touch));
} else {
mc13xxx_add_subdevice(mc13xxx, "%s-regulator");
mc13xxx_add_subdevice(mc13xxx, "%s-led");
mc13xxx_add_subdevice(mc13xxx, "%s-pwrbutton");
if (mc13xxx->flags & MC13XXX_USE_CODEC)
mc13xxx_add_subdevice(mc13xxx, "%s-codec");
if (mc13xxx->flags & MC13XXX_USE_TOUCHSCREEN)
mc13xxx_add_subdevice(mc13xxx, "%s-ts");
}
if (mc13xxx->flags & MC13XXX_USE_ADC)
mc13xxx_add_subdevice(mc13xxx, "%s-adc");
if (mc13xxx->flags & MC13XXX_USE_RTC)
mc13xxx_add_subdevice(mc13xxx, "%s-rtc");
return 0;
}
int mc13xxx_common_exit(struct device *dev)
{
struct mc13xxx *mc13xxx = dev_get_drvdata(dev);
mfd_remove_devices(dev);
regmap_del_irq_chip(mc13xxx->irq, mc13xxx->irq_data);
mutex_destroy(&mc13xxx->lock);
return 0;
}
