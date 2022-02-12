static int __init mpc5121_generic_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
