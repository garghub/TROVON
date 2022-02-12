static int stm32_lptim_validate_device(struct iio_trigger *trig,
struct iio_dev *indio_dev)
{
if (indio_dev->modes & INDIO_HARDWARE_TRIGGERED)
return 0;
return -EINVAL;
}
bool is_stm32_lptim_trigger(struct iio_trigger *trig)
{
return (trig->ops == &stm32_lptim_trigger_ops);
}
static int stm32_lptim_setup_trig(struct stm32_lptim_trigger *priv)
{
struct iio_trigger *trig;
trig = devm_iio_trigger_alloc(priv->dev, "%s", priv->trg);
if (!trig)
return -ENOMEM;
trig->dev.parent = priv->dev->parent;
trig->ops = &stm32_lptim_trigger_ops;
iio_trigger_set_drvdata(trig, priv);
return devm_iio_trigger_register(priv->dev, trig);
}
static int stm32_lptim_trigger_probe(struct platform_device *pdev)
{
struct stm32_lptim_trigger *priv;
u32 index;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (of_property_read_u32(pdev->dev.of_node, "reg", &index))
return -EINVAL;
if (index >= ARRAY_SIZE(stm32_lptim_triggers))
return -EINVAL;
priv->dev = &pdev->dev;
priv->trg = stm32_lptim_triggers[index];
ret = stm32_lptim_setup_trig(priv);
if (ret)
return ret;
platform_set_drvdata(pdev, priv);
return 0;
}
