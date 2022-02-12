static void synth_flush(struct spk_synth *synth)
{
int timeout = SPK_XMITR_TIMEOUT;
while (spk_serial_tx_busy()) {
if (!--timeout)
break;
udelay(1);
}
outb(SYNTH_CLEAR, speakup_info.port_tts);
}
