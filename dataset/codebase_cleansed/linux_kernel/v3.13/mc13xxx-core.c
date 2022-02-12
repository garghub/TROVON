void mc13xxx_lock(struct mc13xxx *mc13xxx)
{
if (!mutex_trylock(&mc13xxx->lock)) {
dev_dbg(mc13xxx->dev, "wait for %s from %pf\n",
__func__, __builtin_return_address(0));
mutex_lock(&mc13xxx->lock);
}
dev_dbg(mc13xxx->dev, "%s from %pf\n",
__func__, __builtin_return_address(0));
}
void mc13xxx_unlock(struct mc13xxx *mc13xxx)
{
dev_dbg(mc13xxx->dev, "%s from %pf\n",
__func__, __builtin_return_address(0));
mutex_unlock(&mc13xxx->lock);
}
int mc13xxx_reg_read(struct mc13xxx *mc13xxx, unsigned int offset, u32 *val)
{
int ret;
if (offset > MC13XXX_NUMREGS)
return -EINVAL;
ret = regmap_read(mc13xxx->regmap, offset, val);
dev_vdbg(mc13xxx->dev, "[0x%02x] -> 0x%06x\n", offset, *val);
return ret;
}
int mc13xxx_reg_write(struct mc13xxx *mc13xxx, unsigned int offset, u32 val)
{
dev_vdbg(mc13xxx->dev, "[0x%02x] <- 0x%06x\n", offset, val);
if (offset > MC13XXX_NUMREGS || val > 0xffffff)
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
int ret;
unsigned int offmask = irq < 24 ? MC13XXX_IRQMASK0 : MC13XXX_IRQMASK1;
u32 irqbit = 1 << (irq < 24 ? irq : irq - 24);
u32 mask;
if (irq < 0 || irq >= MC13XXX_NUM_IRQ)
return -EINVAL;
ret = mc13xxx_reg_read(mc13xxx, offmask, &mask);
if (ret)
return ret;
if (mask & irqbit)
return 0;
return mc13xxx_reg_write(mc13xxx, offmask, mask | irqbit);
}
int mc13xxx_irq_unmask(struct mc13xxx *mc13xxx, int irq)
{
int ret;
unsigned int offmask = irq < 24 ? MC13XXX_IRQMASK0 : MC13XXX_IRQMASK1;
u32 irqbit = 1 << (irq < 24 ? irq : irq - 24);
u32 mask;
if (irq < 0 || irq >= MC13XXX_NUM_IRQ)
return -EINVAL;
ret = mc13xxx_reg_read(mc13xxx, offmask, &mask);
if (ret)
return ret;
if (!(mask & irqbit))
return 0;
return mc13xxx_reg_write(mc13xxx, offmask, mask & ~irqbit);
}
int mc13xxx_irq_status(struct mc13xxx *mc13xxx, int irq,
int *enabled, int *pending)
{
int ret;
unsigned int offmask = irq < 24 ? MC13XXX_IRQMASK0 : MC13XXX_IRQMASK1;
unsigned int offstat = irq < 24 ? MC13XXX_IRQSTAT0 : MC13XXX_IRQSTAT1;
u32 irqbit = 1 << (irq < 24 ? irq : irq - 24);
if (irq < 0 || irq >= MC13XXX_NUM_IRQ)
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
int mc13xxx_irq_ack(struct mc13xxx *mc13xxx, int irq)
{
unsigned int offstat = irq < 24 ? MC13XXX_IRQSTAT0 : MC13XXX_IRQSTAT1;
unsigned int val = 1 << (irq < 24 ? irq : irq - 24);
BUG_ON(irq < 0 || irq >= MC13XXX_NUM_IRQ);
return mc13xxx_reg_write(mc13xxx, offstat, val);
}
int mc13xxx_irq_request_nounmask(struct mc13xxx *mc13xxx, int irq,
irq_handler_t handler, const char *name, void *dev)
{
BUG_ON(!mutex_is_locked(&mc13xxx->lock));
BUG_ON(!handler);
if (irq < 0 || irq >= MC13XXX_NUM_IRQ)
return -EINVAL;
if (mc13xxx->irqhandler[irq])
return -EBUSY;
mc13xxx->irqhandler[irq] = handler;
mc13xxx->irqdata[irq] = dev;
return 0;
}
int mc13xxx_irq_request(struct mc13xxx *mc13xxx, int irq,
irq_handler_t handler, const char *name, void *dev)
{
int ret;
ret = mc13xxx_irq_request_nounmask(mc13xxx, irq, handler, name, dev);
if (ret)
return ret;
ret = mc13xxx_irq_unmask(mc13xxx, irq);
if (ret) {
mc13xxx->irqhandler[irq] = NULL;
mc13xxx->irqdata[irq] = NULL;
return ret;
}
return 0;
}
int mc13xxx_irq_free(struct mc13xxx *mc13xxx, int irq, void *dev)
{
int ret;
BUG_ON(!mutex_is_locked(&mc13xxx->lock));
if (irq < 0 || irq >= MC13XXX_NUM_IRQ || !mc13xxx->irqhandler[irq] ||
mc13xxx->irqdata[irq] != dev)
return -EINVAL;
ret = mc13xxx_irq_mask(mc13xxx, irq);
if (ret)
return ret;
mc13xxx->irqhandler[irq] = NULL;
mc13xxx->irqdata[irq] = NULL;
return 0;
}
static inline irqreturn_t mc13xxx_irqhandler(struct mc13xxx *mc13xxx, int irq)
{
return mc13xxx->irqhandler[irq](irq, mc13xxx->irqdata[irq]);
}
static int mc13xxx_irq_handle(struct mc13xxx *mc13xxx,
unsigned int offstat, unsigned int offmask, int baseirq)
{
u32 stat, mask;
int ret = mc13xxx_reg_read(mc13xxx, offstat, &stat);
int num_handled = 0;
if (ret)
return ret;
ret = mc13xxx_reg_read(mc13xxx, offmask, &mask);
if (ret)
return ret;
while (stat & ~mask) {
int irq = __ffs(stat & ~mask);
stat &= ~(1 << irq);
if (likely(mc13xxx->irqhandler[baseirq + irq])) {
irqreturn_t handled;
handled = mc13xxx_irqhandler(mc13xxx, baseirq + irq);
if (handled == IRQ_HANDLED)
num_handled++;
} else {
dev_err(mc13xxx->dev,
"BUG: irq %u but no handler\n",
baseirq + irq);
mask |= 1 << irq;
ret = mc13xxx_reg_write(mc13xxx, offmask, mask);
}
}
return num_handled;
}
static irqreturn_t mc13xxx_irq_thread(int irq, void *data)
{
struct mc13xxx *mc13xxx = data;
irqreturn_t ret;
int handled = 0;
mc13xxx_lock(mc13xxx);
ret = mc13xxx_irq_handle(mc13xxx, MC13XXX_IRQSTAT0,
MC13XXX_IRQMASK0, 0);
if (ret > 0)
handled = 1;
ret = mc13xxx_irq_handle(mc13xxx, MC13XXX_IRQSTAT1,
MC13XXX_IRQMASK1, 24);
if (ret > 0)
handled = 1;
mc13xxx_unlock(mc13xxx);
return IRQ_RETVAL(handled);
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
mc13xxx_irq_ack(adcdone_data->mc13xxx, irq);
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
mc13xxx_irq_ack(mc13xxx, MC13XXX_IRQ_ADCDONE);
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
return mfd_add_devices(mc13xxx->dev, -1, &cell, 1, NULL, 0, NULL);
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
int mc13xxx_common_init(struct mc13xxx *mc13xxx,
struct mc13xxx_platform_data *pdata, int irq)
{
int ret;
u32 revision;
mc13xxx_lock(mc13xxx);
ret = mc13xxx_reg_read(mc13xxx, MC13XXX_REVISION, &revision);
if (ret)
goto err_revision;
mc13xxx->variant->print_revision(mc13xxx, revision);
ret = mc13xxx_reg_write(mc13xxx, MC13XXX_IRQMASK0, 0x00ffffff);
if (ret)
goto err_mask;
ret = mc13xxx_reg_write(mc13xxx, MC13XXX_IRQMASK1, 0x00ffffff);
if (ret)
goto err_mask;
ret = request_threaded_irq(irq, NULL, mc13xxx_irq_thread,
IRQF_ONESHOT | IRQF_TRIGGER_HIGH, "mc13xxx", mc13xxx);
if (ret) {
err_mask:
err_revision:
mc13xxx_unlock(mc13xxx);
return ret;
}
mc13xxx->irq = irq;
mc13xxx_unlock(mc13xxx);
if (mc13xxx_probe_flags_dt(mc13xxx) < 0 && pdata)
mc13xxx->flags = pdata->flags;
if (mc13xxx->flags & MC13XXX_USE_ADC)
mc13xxx_add_subdevice(mc13xxx, "%s-adc");
if (mc13xxx->flags & MC13XXX_USE_CODEC)
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-codec",
pdata->codec, sizeof(*pdata->codec));
if (mc13xxx->flags & MC13XXX_USE_RTC)
mc13xxx_add_subdevice(mc13xxx, "%s-rtc");
if (mc13xxx->flags & MC13XXX_USE_TOUCHSCREEN)
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-ts",
&pdata->touch, sizeof(pdata->touch));
if (pdata) {
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-regulator",
&pdata->regulators, sizeof(pdata->regulators));
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-led",
pdata->leds, sizeof(*pdata->leds));
mc13xxx_add_subdevice_pdata(mc13xxx, "%s-pwrbutton",
pdata->buttons, sizeof(*pdata->buttons));
} else {
mc13xxx_add_subdevice(mc13xxx, "%s-regulator");
mc13xxx_add_subdevice(mc13xxx, "%s-led");
mc13xxx_add_subdevice(mc13xxx, "%s-pwrbutton");
}
return 0;
}
void mc13xxx_common_cleanup(struct mc13xxx *mc13xxx)
{
free_irq(mc13xxx->irq, mc13xxx);
mfd_remove_devices(mc13xxx->dev);
}
