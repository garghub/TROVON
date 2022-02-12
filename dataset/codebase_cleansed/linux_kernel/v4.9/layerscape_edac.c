static int __init fsl_ddr_mc_init(void)
{
int res;
switch (edac_op_state) {
case EDAC_OPSTATE_POLL:
case EDAC_OPSTATE_INT:
break;
default:
edac_op_state = EDAC_OPSTATE_INT;
break;
}
res = platform_driver_register(&fsl_ddr_mc_err_driver);
if (res) {
pr_err("MC fails to register\n");
return res;
}
return 0;
}
static void __exit fsl_ddr_mc_exit(void)
{
platform_driver_unregister(&fsl_ddr_mc_err_driver);
}
