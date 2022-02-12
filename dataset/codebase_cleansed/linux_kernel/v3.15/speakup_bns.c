static int __init bns_init(void)
{
return synth_add(&synth_bns);
}
static void __exit bns_exit(void)
{
synth_remove(&synth_bns);
}
