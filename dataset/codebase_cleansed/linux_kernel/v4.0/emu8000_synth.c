static int snd_emu8000_new_device(struct snd_seq_device *dev)
{
struct snd_emu8000 *hw;
struct snd_emux *emu;
hw = *(struct snd_emu8000**)SNDRV_SEQ_DEVICE_ARGPTR(dev);
if (hw == NULL)
return -EINVAL;
if (hw->emu)
return -EBUSY;
if (snd_emux_new(&emu) < 0)
return -ENOMEM;
hw->emu = emu;
snd_emu8000_ops_setup(hw);
emu->hw = hw;
emu->max_voices = EMU8000_DRAM_VOICES;
emu->num_ports = hw->seq_ports;
if (hw->memhdr) {
snd_printk(KERN_ERR "memhdr is already initialized!?\n");
snd_util_memhdr_free(hw->memhdr);
}
hw->memhdr = snd_util_memhdr_new(hw->mem_size);
if (hw->memhdr == NULL) {
snd_emux_free(emu);
hw->emu = NULL;
return -ENOMEM;
}
emu->memhdr = hw->memhdr;
emu->midi_ports = hw->seq_ports < 2 ? hw->seq_ports : 2;
emu->midi_devidx = 1;
emu->linear_panning = 1;
emu->hwdep_idx = 2;
if (snd_emux_register(emu, dev->card, hw->index, "Emu8000") < 0) {
snd_emux_free(emu);
snd_util_memhdr_free(hw->memhdr);
hw->emu = NULL;
hw->memhdr = NULL;
return -ENOMEM;
}
if (hw->mem_size > 0)
snd_emu8000_pcm_new(dev->card, hw, 1);
dev->driver_data = hw;
return 0;
}
static int snd_emu8000_delete_device(struct snd_seq_device *dev)
{
struct snd_emu8000 *hw;
if (dev->driver_data == NULL)
return 0;
hw = dev->driver_data;
if (hw->pcm)
snd_device_free(dev->card, hw->pcm);
snd_emux_free(hw->emu);
snd_util_memhdr_free(hw->memhdr);
hw->emu = NULL;
hw->memhdr = NULL;
return 0;
}
static int __init alsa_emu8000_init(void)
{
static struct snd_seq_dev_ops ops = {
snd_emu8000_new_device,
snd_emu8000_delete_device,
};
return snd_seq_device_register_driver(SNDRV_SEQ_DEV_ID_EMU8000, &ops,
sizeof(struct snd_emu8000*));
}
static void __exit alsa_emu8000_exit(void)
{
snd_seq_device_unregister_driver(SNDRV_SEQ_DEV_ID_EMU8000);
}
