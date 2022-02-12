int snd_vx_setup_firmware(struct vx_core *chip)
{
static char *fw_files[VX_TYPE_NUMS][4] = {
[VX_TYPE_BOARD] = {
NULL, "x1_1_vx2.xlx", "bd56002.boot", "l_1_vx2.d56",
},
[VX_TYPE_V2] = {
NULL, "x1_2_v22.xlx", "bd563v2.boot", "l_1_v22.d56",
},
[VX_TYPE_MIC] = {
NULL, "x1_2_v22.xlx", "bd563v2.boot", "l_1_v22.d56",
},
[VX_TYPE_VXPOCKET] = {
"bx_1_vxp.b56", "x1_1_vxp.xlx", "bd563s3.boot", "l_1_vxp.d56"
},
[VX_TYPE_VXP440] = {
"bx_1_vp4.b56", "x1_1_vp4.xlx", "bd563s3.boot", "l_1_vp4.d56"
},
};
int i, err;
for (i = 0; i < 4; i++) {
char path[32];
const struct firmware *fw;
if (! fw_files[chip->type][i])
continue;
sprintf(path, "vx/%s", fw_files[chip->type][i]);
if (request_firmware(&fw, path, chip->dev)) {
snd_printk(KERN_ERR "vx: can't load firmware %s\n", path);
return -ENOENT;
}
err = chip->ops->load_dsp(chip, i, fw);
if (err < 0) {
release_firmware(fw);
return err;
}
if (i == 1)
chip->chip_status |= VX_STAT_XILINX_LOADED;
#ifdef CONFIG_PM
chip->firmware[i] = fw;
#else
release_firmware(fw);
#endif
}
if ((err = snd_vx_pcm_new(chip)) < 0)
return err;
if ((err = snd_vx_mixer_new(chip)) < 0)
return err;
if (chip->ops->add_controls)
if ((err = chip->ops->add_controls(chip)) < 0)
return err;
chip->chip_status |= VX_STAT_DEVICE_INIT;
chip->chip_status |= VX_STAT_CHIP_INIT;
return snd_card_register(chip->card);
}
void snd_vx_free_firmware(struct vx_core *chip)
{
#ifdef CONFIG_PM
int i;
for (i = 0; i < 4; i++)
release_firmware(chip->firmware[i]);
#endif
}
static int vx_hwdep_dsp_status(struct snd_hwdep *hw,
struct snd_hwdep_dsp_status *info)
{
static char *type_ids[VX_TYPE_NUMS] = {
[VX_TYPE_BOARD] = "vxboard",
[VX_TYPE_V2] = "vx222",
[VX_TYPE_MIC] = "vx222",
[VX_TYPE_VXPOCKET] = "vxpocket",
[VX_TYPE_VXP440] = "vxp440",
};
struct vx_core *vx = hw->private_data;
if (snd_BUG_ON(!type_ids[vx->type]))
return -EINVAL;
strcpy(info->id, type_ids[vx->type]);
if (vx_is_pcmcia(vx))
info->num_dsps = 4;
else
info->num_dsps = 3;
if (vx->chip_status & VX_STAT_CHIP_INIT)
info->chip_ready = 1;
info->version = VX_DRIVER_VERSION;
return 0;
}
static void free_fw(const struct firmware *fw)
{
if (fw) {
vfree(fw->data);
kfree(fw);
}
}
static int vx_hwdep_dsp_load(struct snd_hwdep *hw,
struct snd_hwdep_dsp_image *dsp)
{
struct vx_core *vx = hw->private_data;
int index, err;
struct firmware *fw;
if (snd_BUG_ON(!vx->ops->load_dsp))
return -ENXIO;
fw = kmalloc(sizeof(*fw), GFP_KERNEL);
if (! fw) {
snd_printk(KERN_ERR "cannot allocate firmware\n");
return -ENOMEM;
}
fw->size = dsp->length;
fw->data = vmalloc(fw->size);
if (! fw->data) {
snd_printk(KERN_ERR "cannot allocate firmware image (length=%d)\n",
(int)fw->size);
kfree(fw);
return -ENOMEM;
}
if (copy_from_user((void *)fw->data, dsp->image, dsp->length)) {
free_fw(fw);
return -EFAULT;
}
index = dsp->index;
if (! vx_is_pcmcia(vx))
index++;
err = vx->ops->load_dsp(vx, index, fw);
if (err < 0) {
free_fw(fw);
return err;
}
#ifdef CONFIG_PM
vx->firmware[index] = fw;
#else
free_fw(fw);
#endif
if (index == 1)
vx->chip_status |= VX_STAT_XILINX_LOADED;
if (index < 3)
return 0;
if (! (vx->chip_status & VX_STAT_DEVICE_INIT)) {
if ((err = snd_vx_pcm_new(vx)) < 0)
return err;
if ((err = snd_vx_mixer_new(vx)) < 0)
return err;
if (vx->ops->add_controls)
if ((err = vx->ops->add_controls(vx)) < 0)
return err;
if ((err = snd_card_register(vx->card)) < 0)
return err;
vx->chip_status |= VX_STAT_DEVICE_INIT;
}
vx->chip_status |= VX_STAT_CHIP_INIT;
return 0;
}
int snd_vx_setup_firmware(struct vx_core *chip)
{
int err;
struct snd_hwdep *hw;
if ((err = snd_hwdep_new(chip->card, SND_VX_HWDEP_ID, 0, &hw)) < 0)
return err;
hw->iface = SNDRV_HWDEP_IFACE_VX;
hw->private_data = chip;
hw->ops.dsp_status = vx_hwdep_dsp_status;
hw->ops.dsp_load = vx_hwdep_dsp_load;
hw->exclusive = 1;
sprintf(hw->name, "VX Loader (%s)", chip->card->driver);
chip->hwdep = hw;
return snd_card_register(chip->card);
}
void snd_vx_free_firmware(struct vx_core *chip)
{
#ifdef CONFIG_PM
int i;
for (i = 0; i < 4; i++)
free_fw(chip->firmware[i]);
#endif
}
