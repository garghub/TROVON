static int versatile_reboot(struct notifier_block *this, unsigned long mode,
void *cmd)
{
switch (versatile_reboot_type) {
case INTEGRATOR_REBOOT_CM:
regmap_write(syscon_regmap, INTEGRATOR_HDR_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_update_bits(syscon_regmap,
INTEGRATOR_HDR_CTRL_OFFSET,
INTEGRATOR_CM_CTRL_RESET,
INTEGRATOR_CM_CTRL_RESET);
break;
case REALVIEW_REBOOT_EB:
regmap_write(syscon_regmap, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_write(syscon_regmap,
REALVIEW_SYS_RESETCTL_OFFSET, 0x0008);
break;
case REALVIEW_REBOOT_PB1176:
regmap_write(syscon_regmap, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_write(syscon_regmap,
REALVIEW_SYS_RESETCTL_OFFSET, 0x0100);
break;
case REALVIEW_REBOOT_PB11MP:
case REALVIEW_REBOOT_PBA8:
regmap_write(syscon_regmap, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_write(syscon_regmap, REALVIEW_SYS_RESETCTL_OFFSET,
0x0000);
regmap_write(syscon_regmap, REALVIEW_SYS_RESETCTL_OFFSET,
0x0004);
break;
case REALVIEW_REBOOT_PBX:
regmap_write(syscon_regmap, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_write(syscon_regmap, REALVIEW_SYS_RESETCTL_OFFSET,
0x00f0);
regmap_write(syscon_regmap, REALVIEW_SYS_RESETCTL_OFFSET,
0x00f4);
break;
}
dsb();
return NOTIFY_DONE;
}
static int __init versatile_reboot_probe(void)
{
const struct of_device_id *reboot_id;
struct device_node *np;
int err;
np = of_find_matching_node_and_match(NULL, versatile_reboot_of_match,
&reboot_id);
if (!np)
return -ENODEV;
versatile_reboot_type = (enum versatile_reboot)reboot_id->data;
syscon_regmap = syscon_node_to_regmap(np);
if (IS_ERR(syscon_regmap))
return PTR_ERR(syscon_regmap);
err = register_restart_handler(&versatile_reboot_nb);
if (err)
return err;
pr_info("versatile reboot driver registered\n");
return 0;
}
