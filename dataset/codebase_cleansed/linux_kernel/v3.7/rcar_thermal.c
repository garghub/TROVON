static u32 rcar_thermal_read(struct rcar_thermal_priv *priv, u32 reg)
{
unsigned long flags;
u32 ret;
spin_lock_irqsave(&priv->lock, flags);
ret = ioread32(priv->base + reg);
spin_unlock_irqrestore(&priv->lock, flags);
return ret;
}
static void rcar_thermal_bset(struct rcar_thermal_priv *priv, u32 reg,
u32 mask, u32 data)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&priv->lock, flags);
val = ioread32(priv->base + reg);
val &= ~mask;
val |= (data & mask);
iowrite32(val, priv->base + reg);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int rcar_thermal_get_temp(struct thermal_zone_device *zone,
unsigned long *temp)
{
struct rcar_thermal_priv *priv = zone->devdata;
int val, min, max, tmp;
tmp = -200;
while (1) {
if (priv->comp < 1 || priv->comp > 12) {
dev_err(priv->dev,
"THSSR invalid data (%d)\n", priv->comp);
priv->comp = 4;
return -EINVAL;
}
min = (priv->comp * 15) - 60;
max = min + 15;
rcar_thermal_bset(priv, THSCR, CPTAP, priv->comp);
udelay(300);
val = rcar_thermal_read(priv, THSSR) & CTEMP;
val = (val * 5) - 65;
dev_dbg(priv->dev, "comp/min/max/val = %d/%d/%d/%d\n",
priv->comp, min, max, val);
if (tmp == val)
break;
if (val <= min) {
tmp = min;
priv->comp--;
} else if (val >= max) {
tmp = max;
priv->comp++;
} else {
tmp = val;
break;
}
}
*temp = tmp;
return 0;
}
static int rcar_thermal_probe(struct platform_device *pdev)
{
struct thermal_zone_device *zone;
struct rcar_thermal_priv *priv;
struct resource *res;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Could not get platform resource\n");
return -ENODEV;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "Could not allocate priv\n");
return -ENOMEM;
}
priv->comp = 4;
priv->dev = &pdev->dev;
spin_lock_init(&priv->lock);
priv->base = devm_ioremap_nocache(&pdev->dev,
res->start, resource_size(res));
if (!priv->base) {
dev_err(&pdev->dev, "Unable to ioremap thermal register\n");
ret = -ENOMEM;
goto error_free_priv;
}
zone = thermal_zone_device_register("rcar_thermal", 0, 0, priv,
&rcar_thermal_zone_ops, 0, 0);
if (IS_ERR(zone)) {
dev_err(&pdev->dev, "thermal zone device is NULL\n");
ret = PTR_ERR(zone);
goto error_iounmap;
}
platform_set_drvdata(pdev, zone);
dev_info(&pdev->dev, "proved\n");
return 0;
error_iounmap:
devm_iounmap(&pdev->dev, priv->base);
error_free_priv:
devm_kfree(&pdev->dev, priv);
return ret;
}
static int rcar_thermal_remove(struct platform_device *pdev)
{
struct thermal_zone_device *zone = platform_get_drvdata(pdev);
struct rcar_thermal_priv *priv = zone->devdata;
thermal_zone_device_unregister(zone);
platform_set_drvdata(pdev, NULL);
devm_iounmap(&pdev->dev, priv->base);
devm_kfree(&pdev->dev, priv);
return 0;
}
