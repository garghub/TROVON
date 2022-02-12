static int qcom_coincell_chgr_config(struct qcom_coincell *chgr, int rset,
int vset, bool enable)
{
int i, j, rc;
if (!enable)
return regmap_write(chgr->regmap,
chgr->base_addr + QCOM_COINCELL_REG_ENABLE, 0);
for (i = 0; i < ARRAY_SIZE(qcom_rset_map); i++)
if (rset == qcom_rset_map[i])
break;
if (i >= ARRAY_SIZE(qcom_rset_map)) {
dev_err(chgr->dev, "invalid rset-ohms value %d\n", rset);
return -EINVAL;
}
for (j = 0; j < ARRAY_SIZE(qcom_vset_map); j++)
if (vset == qcom_vset_map[j])
break;
if (j >= ARRAY_SIZE(qcom_vset_map)) {
dev_err(chgr->dev, "invalid vset-millivolts value %d\n", vset);
return -EINVAL;
}
rc = regmap_write(chgr->regmap,
chgr->base_addr + QCOM_COINCELL_REG_RSET, i);
if (rc) {
dev_err(chgr->dev, "could not write to RSET register\n");
return rc;
}
rc = regmap_write(chgr->regmap,
chgr->base_addr + QCOM_COINCELL_REG_VSET, j);
if (rc)
return rc;
return regmap_write(chgr->regmap,
chgr->base_addr + QCOM_COINCELL_REG_ENABLE,
QCOM_COINCELL_ENABLE);
}
static int qcom_coincell_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct qcom_coincell chgr;
u32 rset = 0;
u32 vset = 0;
bool enable;
int rc;
chgr.dev = &pdev->dev;
chgr.regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!chgr.regmap) {
dev_err(chgr.dev, "Unable to get regmap\n");
return -EINVAL;
}
rc = of_property_read_u32(node, "reg", &chgr.base_addr);
if (rc)
return rc;
enable = !of_property_read_bool(node, "qcom,charger-disable");
if (enable) {
rc = of_property_read_u32(node, "qcom,rset-ohms", &rset);
if (rc) {
dev_err(chgr.dev,
"can't find 'qcom,rset-ohms' in DT block");
return rc;
}
rc = of_property_read_u32(node, "qcom,vset-millivolts", &vset);
if (rc) {
dev_err(chgr.dev,
"can't find 'qcom,vset-millivolts' in DT block");
return rc;
}
}
return qcom_coincell_chgr_config(&chgr, rset, vset, enable);
}
