static int __init txprt_init(void)
{
return synth_add(&synth_txprt);
}
static void __exit txprt_exit(void)
{
synth_remove(&synth_txprt);
}
