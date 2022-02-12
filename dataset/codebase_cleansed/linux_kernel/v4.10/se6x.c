static void se6x_init(struct oxygen *chip)
{
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL, 0x005);
snd_component_add(chip->card, "PCM1792A");
snd_component_add(chip->card, "PCM1804");
}
static int se6x_control_filter(struct snd_kcontrol_new *template)
{
if (!strncmp(template->name, "Master Playback ", 16))
return 1;
return 0;
}
static void se6x_cleanup(struct oxygen *chip)
{
}
static void set_pcm1792a_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
}
static void set_pcm1804_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
}
static unsigned int se6x_adjust_dac_routing(struct oxygen *chip,
unsigned int play_routing)
{
return ( play_routing & OXYGEN_PLAY_DAC0_SOURCE_MASK) |
((play_routing << 2) & OXYGEN_PLAY_DAC1_SOURCE_MASK);
}
static int se6x_get_model(struct oxygen *chip,
const struct pci_device_id *pci_id)
{
chip->model = model_se6x;
return 0;
}
static int se6x_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
++dev;
return -ENOENT;
}
err = oxygen_pci_probe(pci, index[dev], id[dev], THIS_MODULE,
se6x_ids, se6x_get_model);
if (err >= 0)
++dev;
return err;
}
