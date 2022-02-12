static int synth_probe(struct spk_synth *synth)
{
int failed;
failed = spk_ttyio_synth_probe(synth);
if (failed == 0) {
synth->synth_immediate(synth, "\033=R\r");
mdelay(100);
}
synth->alive = !failed;
return failed;
}
