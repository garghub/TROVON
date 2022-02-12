static u8 auto_voltage_bits(unsigned int millivolts)
{
if (millivolts < 1800)
return 0x2f;
if (millivolts > 3800)
return 0xff;
millivolts -= 625;
return millivolts / 25;
}
static u8 down_voltage_bits(unsigned int millivolts)
{
if (millivolts < 625)
return 0;
else if (millivolts > 3000)
return 0xff;
millivolts -= 625;
return millivolts / 25;
}
static u8 ldo_voltage_bits(unsigned int millivolts)
{
if (millivolts < 900)
return 0;
else if (millivolts > 3600)
return 0x1f;
millivolts -= 900;
return millivolts / 100;
}
static unsigned int auto_voltage_value(u8 bits)
{
if (bits < 0x2f)
return 0;
return 625 + (bits * 25);
}
static unsigned int down_voltage_value(u8 bits)
{
return 625 + (bits * 25);
}
static unsigned int ldo_voltage_value(u8 bits)
{
bits &= 0x1f;
return 900 + (bits * 100);
}
static int pcf50633_regulator_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV,
unsigned *selector)
{
struct pcf50633 *pcf;
int regulator_id, millivolts;
u8 volt_bits, regnr;
pcf = rdev_get_drvdata(rdev);
regulator_id = rdev_get_id(rdev);
if (regulator_id >= PCF50633_NUM_REGULATORS)
return -EINVAL;
millivolts = min_uV / 1000;
regnr = rdev->desc->vsel_reg;
switch (regulator_id) {
case PCF50633_REGULATOR_AUTO:
volt_bits = auto_voltage_bits(millivolts);
break;
case PCF50633_REGULATOR_DOWN1:
volt_bits = down_voltage_bits(millivolts);
break;
case PCF50633_REGULATOR_DOWN2:
volt_bits = down_voltage_bits(millivolts);
break;
case PCF50633_REGULATOR_LDO1:
case PCF50633_REGULATOR_LDO2:
case PCF50633_REGULATOR_LDO3:
case PCF50633_REGULATOR_LDO4:
case PCF50633_REGULATOR_LDO5:
case PCF50633_REGULATOR_LDO6:
case PCF50633_REGULATOR_HCLDO:
case PCF50633_REGULATOR_MEMLDO:
volt_bits = ldo_voltage_bits(millivolts);
break;
default:
return -EINVAL;
}
*selector = volt_bits;
return pcf50633_reg_write(pcf, regnr, volt_bits);
}
static int pcf50633_regulator_list_voltage(struct regulator_dev *rdev,
unsigned int index)
{
int regulator_id = rdev_get_id(rdev);
int millivolts;
switch (regulator_id) {
case PCF50633_REGULATOR_AUTO:
millivolts = auto_voltage_value(index);
break;
case PCF50633_REGULATOR_DOWN1:
millivolts = down_voltage_value(index);
break;
case PCF50633_REGULATOR_DOWN2:
millivolts = down_voltage_value(index);
break;
case PCF50633_REGULATOR_LDO1:
case PCF50633_REGULATOR_LDO2:
case PCF50633_REGULATOR_LDO3:
case PCF50633_REGULATOR_LDO4:
case PCF50633_REGULATOR_LDO5:
case PCF50633_REGULATOR_LDO6:
case PCF50633_REGULATOR_HCLDO:
case PCF50633_REGULATOR_MEMLDO:
millivolts = ldo_voltage_value(index);
break;
default:
return -EINVAL;
}
return millivolts * 1000;
}
static int __devinit pcf50633_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
struct pcf50633 *pcf;
struct regulator_config config = { };
pcf = dev_to_pcf50633(pdev->dev.parent);
config.dev = &pdev->dev;
config.init_data = pdev->dev.platform_data;
config.driver_data = pcf;
config.regmap = pcf->regmap;
rdev = regulator_register(&regulators[pdev->id], &config);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
if (pcf->pdata->regulator_registered)
pcf->pdata->regulator_registered(pcf, pdev->id);
return 0;
}
static int __devexit pcf50633_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(rdev);
return 0;
}
static int __init pcf50633_regulator_init(void)
{
return platform_driver_register(&pcf50633_regulator_driver);
}
static void __exit pcf50633_regulator_exit(void)
{
platform_driver_unregister(&pcf50633_regulator_driver);
}
