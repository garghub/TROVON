static void synth_flush(struct spk_synth *synth)
{
synth->io_ops->send_xchar(SYNTH_CLEAR);
}
