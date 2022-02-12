static void synth_interrogate(struct spk_synth *synth)
{
unsigned char *t, i;
unsigned char buf[50], rom_v[20];
synth->synth_immediate(synth, "\x18\x01?");
for (i = 0; i < 50; i++) {
buf[i] = synth->io_ops->synth_in();
if (i > 2 && buf[i] == 0x7f)
break;
}
t = buf + 2;
for (i = 0; *t != '\r'; t++) {
rom_v[i] = *t;
if (++i >= 19)
break;
}
rom_v[i] = 0;
pr_info("%s: ROM version: %s\n", synth->long_name, rom_v);
}
static int synth_probe(struct spk_synth *synth)
{
int failed = 0;
failed = spk_ttyio_synth_probe(synth);
if (failed == 0)
synth_interrogate(synth);
synth->alive = !failed;
return failed;
}
