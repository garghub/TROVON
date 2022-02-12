static inline unsigned long vx2_reg_addr(struct vx_core *_chip, int reg)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
return chip->port[vx2_reg_index[reg]] + vx2_reg_offset[reg];
}
static unsigned char vx2_inb(struct vx_core *chip, int offset)
{
return inb(vx2_reg_addr(chip, offset));
}
static void vx2_outb(struct vx_core *chip, int offset, unsigned char val)
{
outb(val, vx2_reg_addr(chip, offset));
}
static unsigned int vx2_inl(struct vx_core *chip, int offset)
{
return inl(vx2_reg_addr(chip, offset));
}
static void vx2_outl(struct vx_core *chip, int offset, unsigned int val)
{
outl(val, vx2_reg_addr(chip, offset));
}
static void vx2_reset_dsp(struct vx_core *_chip)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
vx_outl(chip, CDSP, chip->regCDSP & ~VX_CDSP_DSP_RESET_MASK);
mdelay(XX_DSP_RESET_WAIT_TIME);
chip->regCDSP |= VX_CDSP_DSP_RESET_MASK;
vx_outl(chip, CDSP, chip->regCDSP);
}
static int vx2_test_xilinx(struct vx_core *_chip)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
unsigned int data;
snd_printdd("testing xilinx...\n");
vx_outl(chip, CDSP, chip->regCDSP | VX_CDSP_TEST0_MASK);
vx_inl(chip, ISR);
data = vx_inl(chip, STATUS);
if ((data & VX_STATUS_VAL_TEST0_MASK) == VX_STATUS_VAL_TEST0_MASK) {
snd_printdd("bad!\n");
return -ENODEV;
}
vx_outl(chip, CDSP, chip->regCDSP & ~VX_CDSP_TEST0_MASK);
vx_inl(chip, ISR);
data = vx_inl(chip, STATUS);
if (! (data & VX_STATUS_VAL_TEST0_MASK)) {
snd_printdd("bad! #2\n");
return -ENODEV;
}
if (_chip->type == VX_TYPE_BOARD) {
vx_outl(chip, CDSP, chip->regCDSP | VX_CDSP_TEST1_MASK);
vx_inl(chip, ISR);
data = vx_inl(chip, STATUS);
if ((data & VX_STATUS_VAL_TEST1_MASK) == VX_STATUS_VAL_TEST1_MASK) {
snd_printdd("bad! #3\n");
return -ENODEV;
}
vx_outl(chip, CDSP, chip->regCDSP & ~VX_CDSP_TEST1_MASK);
vx_inl(chip, ISR);
data = vx_inl(chip, STATUS);
if (! (data & VX_STATUS_VAL_TEST1_MASK)) {
snd_printdd("bad! #4\n");
return -ENODEV;
}
}
snd_printdd("ok, xilinx fine.\n");
return 0;
}
static void vx2_setup_pseudo_dma(struct vx_core *chip, int do_write)
{
vx_outl(chip, ICR, do_write ? ICR_TREQ : ICR_RREQ);
vx_outl(chip, RESET_DMA, 0);
}
static inline void vx2_release_pseudo_dma(struct vx_core *chip)
{
vx_outl(chip, ICR, 0);
}
static void vx2_dma_write(struct vx_core *chip, struct snd_pcm_runtime *runtime,
struct vx_pipe *pipe, int count)
{
unsigned long port = vx2_reg_addr(chip, VX_DMA);
int offset = pipe->hw_ptr;
u32 *addr = (u32 *)(runtime->dma_area + offset);
if (snd_BUG_ON(count % 4))
return;
vx2_setup_pseudo_dma(chip, 1);
if (offset + count > pipe->buffer_bytes) {
int length = pipe->buffer_bytes - offset;
count -= length;
length >>= 2;
while (length-- > 0) {
outl(cpu_to_le32(*addr), port);
addr++;
}
addr = (u32 *)runtime->dma_area;
pipe->hw_ptr = 0;
}
pipe->hw_ptr += count;
count >>= 2;
while (count-- > 0) {
outl(cpu_to_le32(*addr), port);
addr++;
}
vx2_release_pseudo_dma(chip);
}
static void vx2_dma_read(struct vx_core *chip, struct snd_pcm_runtime *runtime,
struct vx_pipe *pipe, int count)
{
int offset = pipe->hw_ptr;
u32 *addr = (u32 *)(runtime->dma_area + offset);
unsigned long port = vx2_reg_addr(chip, VX_DMA);
if (snd_BUG_ON(count % 4))
return;
vx2_setup_pseudo_dma(chip, 0);
if (offset + count > pipe->buffer_bytes) {
int length = pipe->buffer_bytes - offset;
count -= length;
length >>= 2;
while (length-- > 0)
*addr++ = le32_to_cpu(inl(port));
addr = (u32 *)runtime->dma_area;
pipe->hw_ptr = 0;
}
pipe->hw_ptr += count;
count >>= 2;
while (count-- > 0)
*addr++ = le32_to_cpu(inl(port));
vx2_release_pseudo_dma(chip);
}
static int put_xilinx_data(struct vx_core *chip, unsigned int port, unsigned int counts, unsigned char data)
{
unsigned int i;
for (i = 0; i < counts; i++) {
unsigned int val;
val = VX_CNTRL_REGISTER_VALUE & ~VX_USERBIT0_MASK;
vx2_outl(chip, port, val);
vx2_inl(chip, port);
udelay(1);
if (data & (1 << i))
val |= VX_USERBIT1_MASK;
else
val &= ~VX_USERBIT1_MASK;
vx2_outl(chip, port, val);
vx2_inl(chip, port);
val |= VX_USERBIT0_MASK;
vx2_outl(chip, port, val);
vx2_inl(chip, port);
udelay(1);
}
return 0;
}
static int vx2_load_xilinx_binary(struct vx_core *chip, const struct firmware *xilinx)
{
unsigned int i;
unsigned int port;
const unsigned char *image;
vx_outl(chip, CNTRL, VX_CNTRL_REGISTER_VALUE | VX_XILINX_RESET_MASK);
vx_inl(chip, CNTRL);
msleep(10);
vx_outl(chip, CNTRL, VX_CNTRL_REGISTER_VALUE);
vx_inl(chip, CNTRL);
msleep(10);
if (chip->type == VX_TYPE_BOARD)
port = VX_CNTRL;
else
port = VX_GPIOC;
image = xilinx->data;
for (i = 0; i < xilinx->size; i++, image++) {
if (put_xilinx_data(chip, port, 8, *image) < 0)
return -EINVAL;
cond_resched();
}
put_xilinx_data(chip, port, 4, 0xff);
msleep(200);
if (chip->type != VX_TYPE_BOARD) {
i = vx_inl(chip, GPIOC);
if (i & 0x0100)
return 0;
snd_printk(KERN_ERR "vx222: xilinx test failed after load, GPIOC=0x%x\n", i);
return -EINVAL;
}
return 0;
}
static int vx2_load_dsp(struct vx_core *vx, int index, const struct firmware *dsp)
{
int err;
switch (index) {
case 1:
if ((err = vx2_load_xilinx_binary(vx, dsp)) < 0)
return err;
if ((err = vx2_test_xilinx(vx)) < 0)
return err;
return 0;
case 2:
return snd_vx_dsp_boot(vx, dsp);
case 3:
return snd_vx_dsp_load(vx, dsp);
default:
snd_BUG();
return -EINVAL;
}
}
static int vx2_test_and_ack(struct vx_core *chip)
{
if (! (chip->chip_status & VX_STAT_XILINX_LOADED))
return -ENXIO;
if (! (vx_inl(chip, STATUS) & VX_STATUS_MEMIRQ_MASK))
return -EIO;
vx_outl(chip, STATUS, 0);
vx_inl(chip, STATUS);
vx_outl(chip, STATUS, VX_STATUS_MEMIRQ_MASK);
vx_inl(chip, STATUS);
vx_outl(chip, STATUS, 0);
return 0;
}
static void vx2_validate_irq(struct vx_core *_chip, int enable)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
if (enable) {
vx_outl(chip, INTCSR, VX_INTCSR_VALUE|VX_PCI_INTERRUPT_MASK);
chip->regCDSP |= VX_CDSP_VALID_IRQ_MASK;
} else {
vx_outl(chip, INTCSR, VX_INTCSR_VALUE&~VX_PCI_INTERRUPT_MASK);
chip->regCDSP &= ~VX_CDSP_VALID_IRQ_MASK;
}
vx_outl(chip, CDSP, chip->regCDSP);
}
static void vx2_write_codec_reg(struct vx_core *chip, unsigned int data)
{
unsigned int i;
vx_inl(chip, HIFREQ);
for (i = 0; i < 24; i++, data <<= 1)
vx_outl(chip, DATA, ((data & 0x800000) ? VX_DATA_CODEC_MASK : 0));
vx_inl(chip, RUER);
}
static void vx2_write_akm(struct vx_core *chip, int reg, unsigned int data)
{
unsigned int val;
if (reg == XX_CODEC_DAC_CONTROL_REGISTER) {
vx2_write_codec_reg(chip, data ? AKM_CODEC_MUTE_CMD : AKM_CODEC_UNMUTE_CMD);
return;
}
if (snd_BUG_ON(data >= sizeof(vx2_akm_gains_lut)))
return;
switch (reg) {
case XX_CODEC_LEVEL_LEFT_REGISTER:
val = AKM_CODEC_LEFT_LEVEL_CMD;
break;
case XX_CODEC_LEVEL_RIGHT_REGISTER:
val = AKM_CODEC_RIGHT_LEVEL_CMD;
break;
default:
snd_BUG();
return;
}
val |= vx2_akm_gains_lut[data];
vx2_write_codec_reg(chip, val);
}
static void vx2_old_write_codec_bit(struct vx_core *chip, int codec, unsigned int data)
{
int i;
vx_inl(chip, HIFREQ);
for (i = 0; i < 24; i++, data <<= 1)
vx_outl(chip, DATA, ((data & 0x800000) ? VX_DATA_CODEC_MASK : 0));
vx_inl(chip, RUER);
}
static void vx2_reset_codec(struct vx_core *_chip)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
vx_outl(chip, CDSP, chip->regCDSP &~ VX_CDSP_CODEC_RESET_MASK);
vx_inl(chip, CDSP);
msleep(10);
chip->regCDSP |= VX_CDSP_CODEC_RESET_MASK;
vx_outl(chip, CDSP, chip->regCDSP);
vx_inl(chip, CDSP);
if (_chip->type == VX_TYPE_BOARD) {
msleep(1);
return;
}
msleep(5);
vx2_write_codec_reg(_chip, AKM_CODEC_POWER_CONTROL_CMD);
vx2_write_codec_reg(_chip, AKM_CODEC_CLOCK_FORMAT_CMD);
vx2_write_codec_reg(_chip, AKM_CODEC_MUTE_CMD);
vx2_write_codec_reg(_chip, AKM_CODEC_RESET_OFF_CMD);
if (_chip->type == VX_TYPE_MIC) {
chip->regSELMIC = MICRO_SELECT_INPUT_NORM |
MICRO_SELECT_PREAMPLI_G_0 |
MICRO_SELECT_NOISE_T_52DB;
chip->regSELMIC &= ~MICRO_SELECT_PHANTOM_ALIM;
vx_outl(_chip, SELMIC, chip->regSELMIC);
}
}
static void vx2_change_audio_source(struct vx_core *_chip, int src)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
switch (src) {
case VX_AUDIO_SRC_DIGITAL:
chip->regCFG |= VX_CFG_DATAIN_SEL_MASK;
break;
default:
chip->regCFG &= ~VX_CFG_DATAIN_SEL_MASK;
break;
}
vx_outl(chip, CFG, chip->regCFG);
}
static void vx2_set_clock_source(struct vx_core *_chip, int source)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
if (source == INTERNAL_QUARTZ)
chip->regCFG &= ~VX_CFG_CLOCKIN_SEL_MASK;
else
chip->regCFG |= VX_CFG_CLOCKIN_SEL_MASK;
vx_outl(chip, CFG, chip->regCFG);
}
static void vx2_reset_board(struct vx_core *_chip, int cold_reset)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
chip->regCDSP = VX_CDSP_CODEC_RESET_MASK | VX_CDSP_DSP_RESET_MASK ;
chip->regCFG = 0;
}
static void vx2_set_input_level(struct snd_vx222 *chip)
{
int i, miclevel, preamp;
unsigned int data;
miclevel = chip->mic_level;
miclevel += V2_MICRO_LEVEL_RANGE;
preamp = 0;
while (miclevel > 210) {
preamp++;
miclevel -= (18 * 2);
}
if (snd_BUG_ON(preamp >= 4))
return;
chip->regSELMIC &= ~MICRO_SELECT_PREAMPLI_MASK;
chip->regSELMIC |= (preamp << MICRO_SELECT_PREAMPLI_OFFSET) & MICRO_SELECT_PREAMPLI_MASK;
vx_outl(chip, SELMIC, chip->regSELMIC);
data = (unsigned int)miclevel << 16 |
(unsigned int)chip->input_level[1] << 8 |
(unsigned int)chip->input_level[0];
vx_inl(chip, DATA);
for (i = 0; i < 32; i++, data <<= 1)
vx_outl(chip, DATA, ((data & 0x80000000) ? VX_DATA_CODEC_MASK : 0));
vx_inl(chip, RUER);
}
static int vx_input_level_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = MIC_LEVEL_MAX;
return 0;
}
static int vx_input_level_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
mutex_lock(&_chip->mixer_mutex);
ucontrol->value.integer.value[0] = chip->input_level[0];
ucontrol->value.integer.value[1] = chip->input_level[1];
mutex_unlock(&_chip->mixer_mutex);
return 0;
}
static int vx_input_level_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
if (ucontrol->value.integer.value[0] < 0 ||
ucontrol->value.integer.value[0] > MIC_LEVEL_MAX)
return -EINVAL;
if (ucontrol->value.integer.value[1] < 0 ||
ucontrol->value.integer.value[1] > MIC_LEVEL_MAX)
return -EINVAL;
mutex_lock(&_chip->mixer_mutex);
if (chip->input_level[0] != ucontrol->value.integer.value[0] ||
chip->input_level[1] != ucontrol->value.integer.value[1]) {
chip->input_level[0] = ucontrol->value.integer.value[0];
chip->input_level[1] = ucontrol->value.integer.value[1];
vx2_set_input_level(chip);
mutex_unlock(&_chip->mixer_mutex);
return 1;
}
mutex_unlock(&_chip->mixer_mutex);
return 0;
}
static int vx_mic_level_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = MIC_LEVEL_MAX;
return 0;
}
static int vx_mic_level_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
ucontrol->value.integer.value[0] = chip->mic_level;
return 0;
}
static int vx_mic_level_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
if (ucontrol->value.integer.value[0] < 0 ||
ucontrol->value.integer.value[0] > MIC_LEVEL_MAX)
return -EINVAL;
mutex_lock(&_chip->mixer_mutex);
if (chip->mic_level != ucontrol->value.integer.value[0]) {
chip->mic_level = ucontrol->value.integer.value[0];
vx2_set_input_level(chip);
mutex_unlock(&_chip->mixer_mutex);
return 1;
}
mutex_unlock(&_chip->mixer_mutex);
return 0;
}
static int vx2_add_mic_controls(struct vx_core *_chip)
{
struct snd_vx222 *chip = (struct snd_vx222 *)_chip;
int err;
if (_chip->type != VX_TYPE_MIC)
return 0;
chip->input_level[0] = chip->input_level[1] = 0;
chip->mic_level = 0;
vx2_set_input_level(chip);
if ((err = snd_ctl_add(_chip->card, snd_ctl_new1(&vx_control_input_level, chip))) < 0)
return err;
if ((err = snd_ctl_add(_chip->card, snd_ctl_new1(&vx_control_mic_level, chip))) < 0)
return err;
return 0;
}
