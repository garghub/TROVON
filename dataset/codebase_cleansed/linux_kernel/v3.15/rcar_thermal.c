static u32 _rcar_thermal_common_read(struct rcar_thermal_common *common,
u32 reg)
{
return ioread32(common->base + reg);
}
static void _rcar_thermal_common_write(struct rcar_thermal_common *common,
u32 reg, u32 data)
{
iowrite32(data, common->base + reg);
}
static void _rcar_thermal_common_bset(struct rcar_thermal_common *common,
u32 reg, u32 mask, u32 data)
{
u32 val;
val = ioread32(common->base + reg);
val &= ~mask;
val |= (data & mask);
iowrite32(val, common->base + reg);
}
static u32 _rcar_thermal_read(struct rcar_thermal_priv *priv, u32 reg)
{
return ioread32(priv->base + reg);
}
static void _rcar_thermal_write(struct rcar_thermal_priv *priv,
u32 reg, u32 data)
{
iowrite32(data, priv->base + reg);
}
static void _rcar_thermal_bset(struct rcar_thermal_priv *priv, u32 reg,
u32 mask, u32 data)
{
u32 val;
val = ioread32(priv->base + reg);
val &= ~mask;
val |= (data & mask);
iowrite32(val, priv->base + reg);
}
static int rcar_thermal_update_temp(struct rcar_thermal_priv *priv)
{
struct device *dev = rcar_priv_to_dev(priv);
int i;
int ctemp, old, new;
int ret = -EINVAL;
mutex_lock(&priv->lock);
rcar_thermal_bset(priv, THSCR, CPCTL, CPCTL);
ctemp = 0;
old = ~0;
for (i = 0; i < 128; i++) {
udelay(300);
new = rcar_thermal_read(priv, THSSR) & CTEMP;
if (new == old) {
ctemp = new;
break;
}
old = new;
}
if (!ctemp) {
dev_err(dev, "thermal sensor was broken\n");
goto err_out_unlock;
}
if (rcar_has_irq_support(priv)) {
rcar_thermal_write(priv, FILONOFF, 0);
rcar_thermal_write(priv, POSNEG, 0x1);
rcar_thermal_write(priv, INTCTRL, (((ctemp - 0) << 8) |
((ctemp - 1) << 0)));
}
dev_dbg(dev, "thermal%d %d -> %d\n", priv->id, priv->ctemp, ctemp);
priv->ctemp = ctemp;
ret = 0;
err_out_unlock:
mutex_unlock(&priv->lock);
return ret;
}
static int rcar_thermal_get_temp(struct thermal_zone_device *zone,
unsigned long *temp)
{
struct rcar_thermal_priv *priv = rcar_zone_to_priv(zone);
if (!rcar_has_irq_support(priv) || rcar_force_update_temp(priv))
rcar_thermal_update_temp(priv);
mutex_lock(&priv->lock);
*temp = MCELSIUS((priv->ctemp * 5) - 65);
mutex_unlock(&priv->lock);
return 0;
}
static int rcar_thermal_get_trip_type(struct thermal_zone_device *zone,
int trip, enum thermal_trip_type *type)
{
struct rcar_thermal_priv *priv = rcar_zone_to_priv(zone);
struct device *dev = rcar_priv_to_dev(priv);
switch (trip) {
case 0:
*type = THERMAL_TRIP_CRITICAL;
break;
default:
dev_err(dev, "rcar driver trip error\n");
return -EINVAL;
}
return 0;
}
static int rcar_thermal_get_trip_temp(struct thermal_zone_device *zone,
int trip, unsigned long *temp)
{
struct rcar_thermal_priv *priv = rcar_zone_to_priv(zone);
struct device *dev = rcar_priv_to_dev(priv);
switch (trip) {
case 0:
*temp = MCELSIUS(90);
break;
default:
dev_err(dev, "rcar driver trip error\n");
return -EINVAL;
}
return 0;
}
static int rcar_thermal_notify(struct thermal_zone_device *zone,
int trip, enum thermal_trip_type type)
{
struct rcar_thermal_priv *priv = rcar_zone_to_priv(zone);
struct device *dev = rcar_priv_to_dev(priv);
switch (type) {
case THERMAL_TRIP_CRITICAL:
dev_warn(dev, "Thermal reached to critical temperature\n");
break;
default:
break;
}
return 0;
}
static void _rcar_thermal_irq_ctrl(struct rcar_thermal_priv *priv, int enable)
{
struct rcar_thermal_common *common = priv->common;
unsigned long flags;
u32 mask = 0x3 << rcar_id_to_shift(priv);
spin_lock_irqsave(&common->lock, flags);
rcar_thermal_common_bset(common, INTMSK, mask, enable ? 0 : mask);
spin_unlock_irqrestore(&common->lock, flags);
}
static void rcar_thermal_work(struct work_struct *work)
{
struct rcar_thermal_priv *priv;
unsigned long cctemp, nctemp;
priv = container_of(work, struct rcar_thermal_priv, work.work);
rcar_thermal_get_temp(priv->zone, &cctemp);
rcar_thermal_update_temp(priv);
rcar_thermal_irq_enable(priv);
rcar_thermal_get_temp(priv->zone, &nctemp);
if (nctemp != cctemp)
thermal_zone_device_update(priv->zone);
}
static u32 rcar_thermal_had_changed(struct rcar_thermal_priv *priv, u32 status)
{
struct device *dev = rcar_priv_to_dev(priv);
status = (status >> rcar_id_to_shift(priv)) & 0x3;
if (status) {
dev_dbg(dev, "thermal%d %s%s\n",
priv->id,
(status & 0x2) ? "Rising " : "",
(status & 0x1) ? "Falling" : "");
}
return status;
}
static irqreturn_t rcar_thermal_irq(int irq, void *data)
{
struct rcar_thermal_common *common = data;
struct rcar_thermal_priv *priv;
unsigned long flags;
u32 status, mask;
spin_lock_irqsave(&common->lock, flags);
mask = rcar_thermal_common_read(common, INTMSK);
status = rcar_thermal_common_read(common, STR);
rcar_thermal_common_write(common, STR, 0x000F0F0F & mask);
spin_unlock_irqrestore(&common->lock, flags);
status = status & ~mask;
rcar_thermal_for_each_priv(priv, common) {
if (rcar_thermal_had_changed(priv, status)) {
rcar_thermal_irq_disable(priv);
schedule_delayed_work(&priv->work,
msecs_to_jiffies(300));
}
}
return IRQ_HANDLED;
}
static int rcar_thermal_probe(struct platform_device *pdev)
{
struct rcar_thermal_common *common;
struct rcar_thermal_priv *priv;
struct device *dev = &pdev->dev;
struct resource *res, *irq;
int mres = 0;
int i;
int ret = -ENODEV;
int idle = IDLE_INTERVAL;
common = devm_kzalloc(dev, sizeof(*common), GFP_KERNEL);
if (!common) {
dev_err(dev, "Could not allocate common\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&common->head);
spin_lock_init(&common->lock);
common->dev = dev;
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (irq) {
int ret;
ret = devm_request_irq(dev, irq->start, rcar_thermal_irq, 0,
dev_name(dev), common);
if (ret) {
dev_err(dev, "irq request failed\n ");
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, mres++);
common->base = devm_ioremap_resource(dev, res);
if (IS_ERR(common->base))
return PTR_ERR(common->base);
rcar_thermal_common_write(common, ENR, 0x00030303);
idle = 0;
}
for (i = 0;; i++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, mres++);
if (!res)
break;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(dev, "Could not allocate priv\n");
ret = -ENOMEM;
goto error_unregister;
}
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto error_unregister;
}
priv->common = common;
priv->id = i;
mutex_init(&priv->lock);
INIT_LIST_HEAD(&priv->list);
INIT_DELAYED_WORK(&priv->work, rcar_thermal_work);
rcar_thermal_update_temp(priv);
priv->zone = thermal_zone_device_register("rcar_thermal",
1, 0, priv,
&rcar_thermal_zone_ops, NULL, 0,
idle);
if (IS_ERR(priv->zone)) {
dev_err(dev, "can't register thermal zone\n");
ret = PTR_ERR(priv->zone);
goto error_unregister;
}
if (rcar_has_irq_support(priv))
rcar_thermal_irq_enable(priv);
list_move_tail(&priv->list, &common->head);
}
platform_set_drvdata(pdev, common);
dev_info(dev, "%d sensor probed\n", i);
return 0;
error_unregister:
rcar_thermal_for_each_priv(priv, common) {
thermal_zone_device_unregister(priv->zone);
if (rcar_has_irq_support(priv))
rcar_thermal_irq_disable(priv);
}
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return ret;
}
static int rcar_thermal_remove(struct platform_device *pdev)
{
struct rcar_thermal_common *common = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
struct rcar_thermal_priv *priv;
rcar_thermal_for_each_priv(priv, common) {
thermal_zone_device_unregister(priv->zone);
if (rcar_has_irq_support(priv))
rcar_thermal_irq_disable(priv);
}
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
return 0;
}
