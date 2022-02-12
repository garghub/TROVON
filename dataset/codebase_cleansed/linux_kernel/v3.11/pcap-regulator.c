static int pcap_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
if (rdev->desc->n_voltages == 1)
return -EINVAL;
return ezx_pcap_set_bits(pcap, vreg->reg,
(rdev->desc->n_voltages - 1) << vreg->index,
selector << vreg->index);
}
static int pcap_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
u32 tmp;
if (rdev->desc->n_voltages == 1)
return 0;
ezx_pcap_read(pcap, vreg->reg, &tmp);
tmp = ((tmp >> vreg->index) & (rdev->desc->n_voltages - 1));
return tmp;
}
static int pcap_regulator_enable(struct regulator_dev *rdev)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
if (vreg->en == NA)
return -EINVAL;
return ezx_pcap_set_bits(pcap, vreg->reg, 1 << vreg->en, 1 << vreg->en);
}
static int pcap_regulator_disable(struct regulator_dev *rdev)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
if (vreg->en == NA)
return -EINVAL;
return ezx_pcap_set_bits(pcap, vreg->reg, 1 << vreg->en, 0);
}
static int pcap_regulator_is_enabled(struct regulator_dev *rdev)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
u32 tmp;
if (vreg->en == NA)
return -EINVAL;
ezx_pcap_read(pcap, vreg->reg, &tmp);
return (tmp >> vreg->en) & 1;
}
static int pcap_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
void *pcap = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
config.dev = &pdev->dev;
config.init_data = pdev->dev.platform_data;
config.driver_data = pcap;
rdev = regulator_register(&pcap_regulators[pdev->id], &config);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
return 0;
}
static int pcap_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init pcap_regulator_init(void)
{
return platform_driver_register(&pcap_regulator_driver);
}
static void __exit pcap_regulator_exit(void)
{
platform_driver_unregister(&pcap_regulator_driver);
}
