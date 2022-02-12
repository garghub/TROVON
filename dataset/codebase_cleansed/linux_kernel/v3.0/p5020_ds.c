static int __init p5020_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P5020DS");
}
