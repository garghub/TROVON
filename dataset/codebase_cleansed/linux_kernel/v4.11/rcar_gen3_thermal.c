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
mutex_lock(&tsc->lock);
reg = rcar_gen3_thermal_read(tsc, REG_GEN3_TEMP) & CTEMP_MASK;
val1 = FIXPT_DIV(FIXPT_INT(reg) - tsc->coef.b1, tsc->coef.a1);
val2 = FIXPT_DIV(FIXPT_INT(reg) - tsc->coef.b2, tsc->coef.a2);
mcelsius = FIXPT_TO_MCELSIUS((val1 + val2) / 2);
mutex_unlock(&tsc->lock);
if ((mcelsius < MCELSIUS(-40)) || (mcelsius > MCELSIUS(125)))
return -EIO;
*temp = rcar_gen3_thermal_round(mcelsius);
return 0;
}
static void r8a7795_thermal_init(struct rcar_gen3_thermal_tsc *tsc)
{
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, CTSR_THBGR);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, 0x0);
usleep_range(1000, 2000);
rcar_gen3_thermal_write(tsc, REG_GEN3_CTSR, CTSR_PONM);
rcar_gen3_thermal_write(tsc, REG_GEN3_IRQCTL, 0x3F);
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
reg_val = rcar_gen3_thermal_read(tsc, REG_GEN3_THCTR);
reg_val |= THCTR_THSST;
rcar_gen3_thermal_write(tsc, REG_GEN3_THCTR, reg_val);
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
int ret, i;
const struct rcar_gen3_thermal_data *match_data =
of_device_get_match_data(dev);
int ptat[3] = { 2351, 1509, 435 };
int thcode[TSC_MAX_NUM][3] = {
{ 3248, 2800, 2221 },
{ 3245, 2795, 2216 },
{ 3250, 2805, 2237 },
};
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
for (i = 0; i < TSC_MAX_NUM; i++) {
struct rcar_gen3_thermal_tsc *tsc;
tsc = devm_kzalloc(dev, sizeof(*tsc), GFP_KERNEL);
if (!tsc) {
ret = -ENOMEM;
goto error_unregister;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
break;
tsc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(tsc->base)) {
ret = PTR_ERR(tsc->base);
goto error_unregister;
}
priv->tscs[i] = tsc;
mutex_init(&tsc->lock);
match_data->thermal_init(tsc);
rcar_gen3_thermal_calc_coefs(&tsc->coef, ptat, thcode[i]);
zone = devm_thermal_zone_of_sensor_register(dev, i, tsc,
&rcar_gen3_tz_of_ops);
if (IS_ERR(zone)) {
dev_err(dev, "Can't register thermal zone\n");
ret = PTR_ERR(zone);
goto error_unregister;
}
tsc->zone = zone;
}
return 0;
error_unregister:
rcar_gen3_thermal_remove(pdev);
return ret;
}
