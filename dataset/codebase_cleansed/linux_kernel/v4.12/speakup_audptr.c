static void synth_flush(struct spk_synth *synth)
{
synth->io_ops->send_xchar(SYNTH_CLEAR);
synth->io_ops->synth_out(synth, PROCSPEECH);
}
static void synth_version(struct spk_synth *synth)
{
unsigned char test = 0;
char synth_id[40] = "";
synth->synth_immediate(synth, "\x05[Q]");
synth_id[test] = spk_serial_in();
if (synth_id[test] == 'A') {
do {
synth_id[++test] = spk_serial_in();
} while (synth_id[test] != '\n' && test < 32);
synth_id[++test] = 0x00;
}
if (synth_id[0] == 'A')
pr_info("%s version: %s", synth->long_name, synth_id);
}
static int synth_probe(struct spk_synth *synth)
{
int failed;
failed = spk_serial_synth_probe(synth);
if (failed == 0)
synth_version(synth);
synth->alive = !failed;
return 0;
}
