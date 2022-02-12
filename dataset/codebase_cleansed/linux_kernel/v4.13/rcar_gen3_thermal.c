static inline u32 rcar_gen3_thermal_read(struct rcar_gen3_thermal_tsc *tsc,
u32 reg)
{
return ioread32(tsc->base + reg);
}
static inline void rcar_gen3_thermal_write(struct rcar_gen3_thermal_tsc *tsc,
u32 reg, u32 data)
{
iowrite32(data, tsc->base + reg);
}
static void rcar_gen3_thermal_calc_coefs(struct equation_coefs *coef,
int *ptat, int *thcode)
{
int tj_2;
tj_2 = (FIXPT_INT((ptat[1] - ptat[2]) * 137)
/ (ptat[0] - ptat[2])) - FIXPT_INT(41);
coef->a1 = FIXPT_DIV(FIXPT_INT(thcode[1] - thcode[2]),
tj_2 - FIXPT_INT(TJ_3));
coef->b1 = FIXPT_INT(thcode[2]) - coef->a1 * TJ_3;
coef->a2 = FIXPT_DIV(FIXPT_INT(thcode[1] - thcode[0]),
tj_2 - FIXPT_INT(TJ_1));
coef->b2 = FIXPT_INT(thcode[0]) - coef->a2 * TJ_1;
}
static int rcar_gen3_thermal_round(int temp)
{
int result, round_offs;
round_offs = temp >= 0 ? RCAR3_THERMAL_GRAN / 2 :
-RCAR3_THERMAL_GRAN / 2;
result = (temp + round_offs) / RCAR3_THERMAL_GRAN;
return result * RCAR3_THERMAL_GRAN;
}
static int rcar_gen3_thermal_get_temp(void *devdata, int *temp)
{
struct rcar_gen3_thermal_tsc *tsc = devdata;
int mcelsius, val1, val2;
u32 reg;
reg = rcar_gen3_thermal_read(tsc, REG_GEN3_TEMP) & CTEMP_MASK;
val1 = FIXPT_DIV(FIXPT_INT(reg) - tsc->coef.b1, tsc->coef.a1);
val2 = FIXPT_DIV(FIXPT_INT(reg) - tsc->coef.b2, tsc->coef.a2);
mcelsius = FIXPT_TO_MCELSIUS((val1 + val2) / 2);
if ((mcelsius < MCELSIUS(-40)) || (mcelsius > MCELSIUS(125)))
return -EIO;
*temp = rcar_gen3_thermal_round(mcelsius);
return 0;
}
static int rcar_gen3_thermal_mcelsius_to_temp(struct rcar_gen3_thermal_tsc *tsc,
int mcelsius)
{
int celsius, val1, val2;
celsius = DIV_ROUND_CLOSEST(mcelsius, 1000);
val1 = celsius * tsc->coef.a1 + tsc->coef.b1;
val2 = celsius * tsc->coef.a2 + tsc->coef.b2;
return INT_FIXPT((val1 + val2) / 2);
}
static int rcar_gen3_thermal_set_trips(void *devdata, int low, int high)
{
struct rcar_gen3_thermal_tsc *tsc = devdata;
low = clamp_val(low, -40000, 125000);
high = clamp_val(high, -40000, 125000);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQTEMP1,
rcar_gen3_thermal_mcelsius_to_temp(tsc, low));
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQTEMP2,
rcar_gen3_thermal_mcelsius_to_temp(tsc, high));
tsc->low = low;
tsc->high = high;
return 0;
}
static void rcar_thermal_irq_set(struct rcar_gen3_thermal_priv *priv, bool on)
{
unsigned int i;
u32 val = on ? IRQ_TEMPD1 | IRQ_TEMP2 : 0;
for (i = 0; i < priv->num_tscs; i++)
rcar_gen3_thermal_write(priv->tscs[i], REG_GEN3_IRQMSK, val);
}
static irqreturn_t rcar_gen3_thermal_irq(int irq, void *data)
{
struct rcar_gen3_thermal_priv *priv = data;
u32 status;
int i, ret = IRQ_HANDLED;
spin_lock(&priv->lock);
for (i = 0; i < priv->num_tscs; i++) {
status = rcar_gen3_thermal_read(priv->tscs[i], REG_GEN3_IRQSTR);
rcar_gen3_thermal_write(priv->tscs[i], REG_GEN3_IRQSTR, 0);
if (status)
ret = IRQ_WAKE_THREAD;
}
if (ret == IRQ_WAKE_THREAD)
rcar_thermal_irq_set(priv, false);
spin_unlock(&priv->lock);
return ret;
}
static irqreturn_t rcar_gen3_thermal_irq_thread(int irq, void *data)
{
struct rcar_gen3_thermal_priv *priv = data;
unsigned long flags;
int i;
for (i = 0; i < priv->num_tscs; i++)
thermal_zone_device_update(priv->tscs[i]->zone,
THERMAL_EVENT_UNSPECIFIED);
spin_lock_irqsave(&priv->lock, flags);
rcar_thermal_irq_set(priv, true);
spin_unlock_irqrestore(&priv->lock, flags);
return IRQ_HANDLED;
}
static void r8a7795_thermal_init(struct rcar_gen3_thermal_tsc *tsc)
{
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, CTSR_THBGR);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, 0x0);
usleep_range(1000, 2000);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, CTSR_PONM);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQCTL, 0x3F);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQMSK, 0);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQEN, IRQ_TEMPD1 | IRQ_TEMP2);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR,
CTSR_PONM | CTSR_AOUT | CTSR_THBGR | CTSR_VMEN);
usleep_range(100, 200);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR,
CTSR_PONM | CTSR_AOUT | CTSR_THBGR | CTSR_VMEN |
CTSR_VMST | CTSR_THSST);
usleep_range(1000, 2000);
}
static void r8a7796_thermal_init(struct rcar_gen3_thermal_tsc *tsc)
{
u32 reg_val;
reg_val = rcar_gen3_thermal_read(tsc, REG_GEN3_THCTR);
reg_val &= ~THCTR_PONM;
rcar_gen3_thermal_write(tsc, REG_GEN3_THCTR, reg_val);
usleep_range(1000, 2000);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQCTL, 0x3F);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQMSK, 0);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQEN, IRQ_TEMPD1 | IRQ_TEMP2);
reg_val = rcar_gen3_thermal_read(tsc, REG_GEN3_THCTR);
reg_val |= THCTR_THSST;
rcar_gen3_thermal_write(tsc, REG_GEN3_THCTR, reg_val);
usleep_range(1000, 2000);
}
static int rcar_gen3_thermal_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
pm_runtime_put(dev);
pm_runtime_disable(dev);
return 0;
}
static int rcar_gen3_thermal_probe(struct platform_device *pdev)
{
struct rcar_gen3_thermal_priv *priv;
struct device *dev = &pdev->dev;
struct resource *res;
struct thermal_zone_device *zone;
int ret, irq, i;
char *irqname;
int ptat[3] = { 2351, 1509, 435 };
int thcode[TSC_MAX_NUM][3] = {
{ 3248, 2800, 2221 },
{ 3245, 2795, 2216 },
{ 3250, 2805, 2237 },
};
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->data = of_device_get_match_data(dev);
spin_lock_init(&priv->lock);
platform_set_drvdata(pdev, priv);
for (i = 0; i < 2; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0)
return irq;
irqname = devm_kasprintf(dev, GFP_KERNEL, "%s:ch%d",
dev_name(dev), i);
if (!irqname)
return -ENOMEM;
ret = devm_request_threaded_irq(dev, irq, rcar_gen3_thermal_irq,
rcar_gen3_thermal_irq_thread,
IRQF_SHARED, irqname, priv);
if (ret)
return ret;
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
for (i = 0; i < TSC_MAX_NUM; i++) {
struct rcar_gen3_thermal_tsc *tsc;
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
break;
tsc = devm_kzalloc(dev, sizeof(*tsc), GFP_KERNEL);
if (!tsc) {
ret = -ENOMEM;
goto error_unregister;
}
tsc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(tsc->base)) {
ret = PTR_ERR(tsc->base);
goto error_unregister;
}
priv->tscs[i] = tsc;
priv->data->thermal_init(tsc);
rcar_gen3_thermal_calc_coefs(&tsc->coef, ptat, thcode[i]);
zone = devm_thermal_zone_of_sensor_register(dev, i, tsc,
&rcar_gen3_tz_of_ops);
if (IS_ERR(zone)) {
dev_err(dev, "Can't register thermal zone\n");
ret = PTR_ERR(zone);
goto error_unregister;
}
tsc->zone = zone;
ret = of_thermal_get_ntrips(tsc->zone);
if (ret < 0)
goto error_unregister;
dev_info(dev, "TSC%d: Loaded %d trip points\n", i, ret);
}
priv->num_tscs = i;
if (!priv->num_tscs) {
ret = -ENODEV;
goto error_unregister;
}
rcar_thermal_irq_set(priv, true);
return 0;
error_unregister:
rcar_gen3_thermal_remove(pdev);
return ret;
}
static int __maybe_unused rcar_gen3_thermal_suspend(struct device *dev)
{
struct rcar_gen3_thermal_priv *priv = dev_get_drvdata(dev);
rcar_thermal_irq_set(priv, false);
return 0;
}
static int __maybe_unused rcar_gen3_thermal_resume(struct device *dev)
{
struct rcar_gen3_thermal_priv *priv = dev_get_drvdata(dev);
unsigned int i;
for (i = 0; i < priv->num_tscs; i++) {
struct rcar_gen3_thermal_tsc *tsc = priv->tscs[i];
priv->data->thermal_init(tsc);
rcar_gen3_thermal_set_trips(tsc, tsc->low, tsc->high);
}
rcar_thermal_irq_set(priv, true);
return 0;
}
