static int pcap_regulator_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV,
unsigned *selector)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
int uV;
u8 i;
if (vreg->n_voltages == 1)
return -EINVAL;
for (i = 0; i < vreg->n_voltages; i++) {
if (i == 0 && rdev_get_id(rdev) == V1)
i = 1;
else if (i + 1 == vreg->n_voltages && rdev_get_id(rdev) == V1)
i = 0;
uV = vreg->voltage_table[i] * 1000;
if (min_uV <= uV && uV <= max_uV) {
*selector = i;
return ezx_pcap_set_bits(pcap, vreg->reg,
(vreg->n_voltages - 1) << vreg->index,
i << vreg->index);
}
if (i == 0 && rdev_get_id(rdev) == V1)
i = vreg->n_voltages - 1;
}
return -EINVAL;
}
static int pcap_regulator_get_voltage(struct regulator_dev *rdev)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
void *pcap = rdev_get_drvdata(rdev);
u32 tmp;
int mV;
if (vreg->n_voltages == 1)
return vreg->voltage_table[0] * 1000;
ezx_pcap_read(pcap, vreg->reg, &tmp);
tmp = ((tmp >> vreg->index) & (vreg->n_voltages - 1));
mV = vreg->voltage_table[tmp];
return mV * 1000;
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
static int pcap_regulator_list_voltage(struct regulator_dev *rdev,
unsigned int index)
{
struct pcap_regulator *vreg = &vreg_table[rdev_get_id(rdev)];
return vreg->voltage_table[index] * 1000;
}
static int __devinit pcap_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
void *pcap = dev_get_drvdata(pdev->dev.parent);
rdev = regulator_register(&pcap_regulators[pdev->id], &pdev->dev,
pdev->dev.platform_data, pcap, NULL);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit pcap_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
platform_set_drvdata(pdev, NULL);
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
