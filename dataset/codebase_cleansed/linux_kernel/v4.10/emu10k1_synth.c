static int snd_emu10k1_synth_probe(struct device *_dev)
{
struct snd_seq_device *dev = to_seq_dev(_dev);
struct snd_emux *emux;
struct snd_emu10k1 *hw;
struct snd_emu10k1_synth_arg *arg;
unsigned long flags;
arg = SNDRV_SEQ_DEVICE_ARGPTR(dev);
if (arg == NULL)
return -EINVAL;
if (arg->seq_ports <= 0)
return 0;
if (arg->max_voices < 1)
arg->max_voices = 1;
else if (arg->max_voices > 64)
arg->max_voices = 64;
if (snd_emux_new(&emux) < 0)
return -ENOMEM;
snd_emu10k1_ops_setup(emux);
hw = arg->hwptr;
emux->hw = hw;
emux->max_voices = arg->max_voices;
emux->num_ports = arg->seq_ports;
emux->pitch_shift = -501;
emux->memhdr = hw->memhdr;
emux->midi_ports = arg->seq_ports < 2 ? arg->seq_ports : 2;
emux->midi_devidx = hw->audigy ? 2 : 1;
emux->linear_panning = 0;
emux->hwdep_idx = 2;
if (snd_emux_register(emux, dev->card, arg->index, "Emu10k1") < 0) {
snd_emux_free(emux);
return -ENOMEM;
}
spin_lock_irqsave(&hw->voice_lock, flags);
hw->synth = emux;
hw->get_synth_voice = snd_emu10k1_synth_get_voice;
spin_unlock_irqrestore(&hw->voice_lock, flags);
dev->driver_data = emux;
return 0;
}
static int snd_emu10k1_synth_remove(struct device *_dev)
{
struct snd_seq_device *dev = to_seq_dev(_dev);
struct snd_emux *emux;
struct snd_emu10k1 *hw;
unsigned long flags;
if (dev->driver_data == NULL)
return 0;
emux = dev->driver_data;
hw = emux->hw;
spin_lock_irqsave(&hw->voice_lock, flags);
hw->synth = NULL;
hw->get_synth_voice = NULL;
spin_unlock_irqrestore(&hw->voice_lock, flags);
snd_emux_free(emux);
return 0;
}
