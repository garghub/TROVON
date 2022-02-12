static void pmic_spmi_show_revid(struct regmap *map, struct device *dev)
{
unsigned int rev2, minor, major, type, subtype;
const char *name = "unknown";
int ret, i;
ret = regmap_read(map, PMIC_TYPE, &type);
if (ret < 0)
return;
if (type != PMIC_TYPE_VALUE)
return;
ret = regmap_read(map, PMIC_SUBTYPE, &subtype);
if (ret < 0)
return;
for (i = 0; i < ARRAY_SIZE(pmic_spmi_id_table); i++) {
if (subtype == (unsigned long)pmic_spmi_id_table[i].data)
break;
}
if (i != ARRAY_SIZE(pmic_spmi_id_table))
name = pmic_spmi_id_table[i].compatible;
ret = regmap_read(map, PMIC_REV2, &rev2);
if (ret < 0)
return;
ret = regmap_read(map, PMIC_REV3, &minor);
if (ret < 0)
return;
ret = regmap_read(map, PMIC_REV4, &major);
if (ret < 0)
return;
if ((subtype == PM8941_SUBTYPE || subtype == PM8226_SUBTYPE) &&
major < 0x02)
major++;
if (subtype == PM8110_SUBTYPE)
minor = rev2;
dev_dbg(dev, "%x: %s v%d.%d\n", subtype, name, major, minor);
}
static int pmic_spmi_probe(struct spmi_device *sdev)
{
struct device_node *root = sdev->dev.of_node;
struct regmap *regmap;
regmap = devm_regmap_init_spmi_ext(sdev, &spmi_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
pmic_spmi_show_revid(regmap, &sdev->dev);
return of_platform_populate(root, NULL, NULL, &sdev->dev);
}
static void pmic_spmi_remove(struct spmi_device *sdev)
{
of_platform_depopulate(&sdev->dev);
}
