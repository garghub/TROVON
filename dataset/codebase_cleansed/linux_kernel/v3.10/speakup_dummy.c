static int __init dummy_init(void)
{
return synth_add(&synth_dummy);
}
static void __exit dummy_exit(void)
{
synth_remove(&synth_dummy);
}
