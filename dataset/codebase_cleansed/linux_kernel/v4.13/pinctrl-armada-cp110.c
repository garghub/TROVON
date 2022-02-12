static void mvebu_pinctrl_assign_variant(struct mvebu_mpp_mode *m,
u8 variant)
{
struct mvebu_mpp_ctrl_setting *s;
for (s = m->settings ; s->name ; s++)
s->variant = variant;
}
static int armada_cp110_pinctrl_probe(struct platform_device *pdev)
{
struct mvebu_pinctrl_soc_info *soc;
const struct of_device_id *match =
of_match_device(armada_cp110_pinctrl_of_match, &pdev->dev);
int i;
if (!pdev->dev.parent)
return -ENODEV;
soc = devm_kzalloc(&pdev->dev,
sizeof(struct mvebu_pinctrl_soc_info), GFP_KERNEL);
if (!soc)
return -ENOMEM;
soc->variant = (unsigned long) match->data & 0xff;
soc->controls = armada_cp110_mpp_controls;
soc->ncontrols = ARRAY_SIZE(armada_cp110_mpp_controls);
soc->modes = armada_cp110_mpp_modes;
soc->nmodes = ARRAY_SIZE(armada_cp110_mpp_modes);
for (i = 0; i < ARRAY_SIZE(armada_cp110_mpp_modes); i++) {
struct mvebu_mpp_mode *m = &armada_cp110_mpp_modes[i];
switch (i) {
case 0 ... 31:
mvebu_pinctrl_assign_variant(m, V_ARMADA_7K_8K_CPS);
break;
case 32 ... 38:
mvebu_pinctrl_assign_variant(m, V_ARMADA_7K_8K_CPM);
break;
case 39 ... 43:
mvebu_pinctrl_assign_variant(m, V_ARMADA_8K_CPM);
break;
case 44 ... 62:
mvebu_pinctrl_assign_variant(m, V_ARMADA_7K_8K_CPM);
break;
}
}
pdev->dev.platform_data = soc;
return mvebu_pinctrl_simple_regmap_probe(pdev, pdev->dev.parent, 0);
}
