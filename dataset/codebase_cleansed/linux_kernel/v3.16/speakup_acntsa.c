static int synth_probe(struct spk_synth *synth)
{
int failed;
failed = spk_serial_synth_probe(synth);
if (failed == 0) {
spk_synth_immediate(synth, "\033=R\r");
mdelay(100);
}
synth->alive = !failed;
return failed;
}
static int __init acntsa_init(void)
{
return synth_add(&synth_acntsa);
}
static void __exit acntsa_exit(void)
{
synth_remove(&synth_acntsa);
}
