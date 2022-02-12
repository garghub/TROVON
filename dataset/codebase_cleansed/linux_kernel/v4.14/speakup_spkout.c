static void synth_flush(struct spk_synth *synth)\r\n{\r\nsynth->io_ops->flush_buffer();\r\nsynth->io_ops->send_xchar(SYNTH_CLEAR);\r\n}
