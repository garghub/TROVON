static inline unsigned long vxp_reg_addr(struct vx_core *_chip, int reg)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
return chip->port + vxp_reg_offset[reg];
}
static unsigned char vxp_inb(struct vx_core *chip, int offset)
{
return inb(vxp_reg_addr(chip, offset));
}
static void vxp_outb(struct vx_core *chip, int offset, unsigned char val)
{
outb(val, vxp_reg_addr(chip, offset));
}
static int vx_check_magic(struct vx_core *chip)
{
unsigned long end_time = jiffies + HZ / 5;
int c;
do {
c = vx_inb(chip, CDSP);
if (c == CDSP_MAGIC)
return 0;
msleep(10);
} while (time_after_eq(end_time, jiffies));
snd_printk(KERN_ERR "cannot find xilinx magic word (%x)\n", c);
return -EIO;
}
static void vxp_reset_dsp(struct vx_core *_chip)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
vx_outb(chip, CDSP, chip->regCDSP | VXP_CDSP_DSP_RESET_MASK);
vx_inb(chip, CDSP);
mdelay(XX_DSP_RESET_WAIT_TIME);
chip->regCDSP &= ~VXP_CDSP_DSP_RESET_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
vx_inb(chip, CDSP);
mdelay(XX_DSP_RESET_WAIT_TIME);
}
static void vxp_reset_codec(struct vx_core *_chip)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
vx_outb(chip, CDSP, chip->regCDSP | VXP_CDSP_CODEC_RESET_MASK);
vx_inb(chip, CDSP);
msleep(10);
chip->regCDSP &= ~VXP_CDSP_CODEC_RESET_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
vx_inb(chip, CDSP);
msleep(1);
}
static int vxp_load_xilinx_binary(struct vx_core *_chip, const struct firmware *fw)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
unsigned int i;
int c;
int regCSUER, regRUER;
const unsigned char *image;
unsigned char data;
chip->regDIALOG |= VXP_DLG_XILINX_REPROG_MASK;
vx_outb(chip, DIALOG, chip->regDIALOG);
regCSUER = vx_inb(chip, CSUER);
regRUER = vx_inb(chip, RUER);
vx_outb(chip, ICR, 0);
snd_printdd(KERN_DEBUG "check ISR_HF2\n");
if (vx_check_isr(_chip, ISR_HF2, ISR_HF2, 20) < 0)
goto _error;
vx_outb(chip, ICR, ICR_HF1);
image = fw->data;
for (i = 0; i < fw->size; i++, image++) {
data = *image;
if (vx_wait_isr_bit(_chip, ISR_TX_EMPTY) < 0)
goto _error;
vx_outb(chip, TXL, data);
if (vx_wait_for_rx_full(_chip) < 0)
goto _error;
c = vx_inb(chip, RXL);
if (c != (int)data)
snd_printk(KERN_ERR "vxpocket: load xilinx mismatch at %d: 0x%x != 0x%x\n", i, c, (int)data);
}
vx_outb(chip, ICR, 0);
if (vx_check_isr(_chip, ISR_HF3, ISR_HF3, 20) < 0)
goto _error;
if (vx_wait_for_rx_full(_chip) < 0)
goto _error;
c = (int)vx_inb(chip, RXH) << 16;
c |= (int)vx_inb(chip, RXM) << 8;
c |= vx_inb(chip, RXL);
snd_printdd(KERN_DEBUG "xilinx: dsp size received 0x%x, orig 0x%Zx\n", c, fw->size);
vx_outb(chip, ICR, ICR_HF0);
msleep(300);
if (vx_check_magic(_chip) < 0)
goto _error;
vx_outb(chip, CSUER, regCSUER);
vx_outb(chip, RUER, regRUER);
chip->regDIALOG |= VXP_DLG_XILINX_REPROG_MASK;
vx_outb(chip, DIALOG, chip->regDIALOG);
vx_inb(chip, DIALOG);
msleep(10);
chip->regDIALOG &= ~VXP_DLG_XILINX_REPROG_MASK;
vx_outb(chip, DIALOG, chip->regDIALOG);
vx_inb(chip, DIALOG);
vxp_reset_codec(_chip);
vx_reset_dsp(_chip);
return 0;
_error:
vx_outb(chip, CSUER, regCSUER);
vx_outb(chip, RUER, regRUER);
chip->regDIALOG &= ~VXP_DLG_XILINX_REPROG_MASK;
vx_outb(chip, DIALOG, chip->regDIALOG);
return -EIO;
}
static int vxp_load_dsp(struct vx_core *vx, int index, const struct firmware *fw)
{
int err;
switch (index) {
case 0:
if ((err = vx_check_magic(vx)) < 0)
return err;
if ((err = snd_vx_load_boot_image(vx, fw)) < 0)
return err;
return 0;
case 1:
return vxp_load_xilinx_binary(vx, fw);
case 2:
return snd_vx_dsp_boot(vx, fw);
case 3:
return snd_vx_dsp_load(vx, fw);
default:
snd_BUG();
return -EINVAL;
}
}
static int vxp_test_and_ack(struct vx_core *_chip)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
if (! (_chip->chip_status & VX_STAT_XILINX_LOADED))
return -ENXIO;
if (! (vx_inb(chip, DIALOG) & VXP_DLG_MEMIRQ_MASK))
return -EIO;
vx_outb(chip, DIALOG, chip->regDIALOG | VXP_DLG_ACK_MEMIRQ_MASK);
vx_inb(chip, DIALOG);
vx_outb(chip, DIALOG, chip->regDIALOG & ~VXP_DLG_ACK_MEMIRQ_MASK);
return 0;
}
static void vxp_validate_irq(struct vx_core *_chip, int enable)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
if (enable)
chip->regCDSP |= VXP_CDSP_VALID_IRQ_MASK;
else
chip->regCDSP &= ~VXP_CDSP_VALID_IRQ_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
}
static void vx_setup_pseudo_dma(struct vx_core *_chip, int do_write)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
vx_outb(chip, ICR, do_write ? ICR_TREQ : ICR_RREQ);
vx_inb(chip, ISR);
vx_outb(chip, ISR, 0);
chip->regDIALOG |= VXP_DLG_DMA16_SEL_MASK;
chip->regDIALOG |= do_write ? VXP_DLG_DMAWRITE_SEL_MASK : VXP_DLG_DMAREAD_SEL_MASK;
vx_outb(chip, DIALOG, chip->regDIALOG);
}
static void vx_release_pseudo_dma(struct vx_core *_chip)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
chip->regDIALOG &= ~(VXP_DLG_DMAWRITE_SEL_MASK|
VXP_DLG_DMAREAD_SEL_MASK|
VXP_DLG_DMA16_SEL_MASK);
vx_outb(chip, DIALOG, chip->regDIALOG);
vx_outb(chip, ICR, 0);
}
static void vxp_dma_write(struct vx_core *chip, struct snd_pcm_runtime *runtime,
struct vx_pipe *pipe, int count)
{
long port = vxp_reg_addr(chip, VX_DMA);
int offset = pipe->hw_ptr;
unsigned short *addr = (unsigned short *)(runtime->dma_area + offset);
vx_setup_pseudo_dma(chip, 1);
if (offset + count > pipe->buffer_bytes) {
int length = pipe->buffer_bytes - offset;
count -= length;
length >>= 1;
while (length-- > 0) {
outw(cpu_to_le16(*addr), port);
addr++;
}
addr = (unsigned short *)runtime->dma_area;
pipe->hw_ptr = 0;
}
pipe->hw_ptr += count;
count >>= 1;
while (count-- > 0) {
outw(cpu_to_le16(*addr), port);
addr++;
}
vx_release_pseudo_dma(chip);
}
static void vxp_dma_read(struct vx_core *chip, struct snd_pcm_runtime *runtime,
struct vx_pipe *pipe, int count)
{
struct snd_vxpocket *pchip = (struct snd_vxpocket *)chip;
long port = vxp_reg_addr(chip, VX_DMA);
int offset = pipe->hw_ptr;
unsigned short *addr = (unsigned short *)(runtime->dma_area + offset);
if (snd_BUG_ON(count % 2))
return;
vx_setup_pseudo_dma(chip, 0);
if (offset + count > pipe->buffer_bytes) {
int length = pipe->buffer_bytes - offset;
count -= length;
length >>= 1;
while (length-- > 0)
*addr++ = le16_to_cpu(inw(port));
addr = (unsigned short *)runtime->dma_area;
pipe->hw_ptr = 0;
}
pipe->hw_ptr += count;
count >>= 1;
while (count-- > 1)
*addr++ = le16_to_cpu(inw(port));
pchip->regDIALOG &= ~VXP_DLG_DMAREAD_SEL_MASK;
vx_outb(chip, DIALOG, pchip->regDIALOG);
*addr = le16_to_cpu(inw(port));
pchip->regDIALOG &= ~VXP_DLG_DMA16_SEL_MASK;
vx_outb(chip, DIALOG, pchip->regDIALOG);
vx_outb(chip, ICR, 0);
}
static void vxp_write_codec_reg(struct vx_core *chip, int codec, unsigned int data)
{
int i;
if (! codec)
vx_inb(chip, LOFREQ);
else
vx_inb(chip, CODEC2);
for (i = 0; i < 24; i++, data <<= 1)
vx_outb(chip, DATA, ((data & 0x800000) ? VX_DATA_CODEC_MASK : 0));
vx_inb(chip, HIFREQ);
}
void vx_set_mic_boost(struct vx_core *chip, int boost)
{
struct snd_vxpocket *pchip = (struct snd_vxpocket *)chip;
unsigned long flags;
if (chip->chip_status & VX_STAT_IS_STALE)
return;
spin_lock_irqsave(&chip->lock, flags);
if (pchip->regCDSP & P24_CDSP_MICS_SEL_MASK) {
if (boost) {
pchip->regCDSP &= ~P24_CDSP_MIC20_SEL_MASK;
pchip->regCDSP |= P24_CDSP_MIC38_SEL_MASK;
} else {
pchip->regCDSP |= P24_CDSP_MIC20_SEL_MASK;
pchip->regCDSP &= ~P24_CDSP_MIC38_SEL_MASK;
}
vx_outb(chip, CDSP, pchip->regCDSP);
}
spin_unlock_irqrestore(&chip->lock, flags);
}
static int vx_compute_mic_level(int level)
{
switch (level) {
case 5: level = 6 ; break;
case 6: level = 8 ; break;
case 7: level = 11; break;
case 8: level = 15; break;
default: break ;
}
return level;
}
void vx_set_mic_level(struct vx_core *chip, int level)
{
struct snd_vxpocket *pchip = (struct snd_vxpocket *)chip;
unsigned long flags;
if (chip->chip_status & VX_STAT_IS_STALE)
return;
spin_lock_irqsave(&chip->lock, flags);
if (pchip->regCDSP & VXP_CDSP_MIC_SEL_MASK) {
level = vx_compute_mic_level(level);
vx_outb(chip, MICRO, level);
}
spin_unlock_irqrestore(&chip->lock, flags);
}
static void vxp_change_audio_source(struct vx_core *_chip, int src)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
switch (src) {
case VX_AUDIO_SRC_DIGITAL:
chip->regCDSP |= VXP_CDSP_DATAIN_SEL_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
break;
case VX_AUDIO_SRC_LINE:
chip->regCDSP &= ~VXP_CDSP_DATAIN_SEL_MASK;
if (_chip->type == VX_TYPE_VXP440)
chip->regCDSP &= ~P24_CDSP_MICS_SEL_MASK;
else
chip->regCDSP &= ~VXP_CDSP_MIC_SEL_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
break;
case VX_AUDIO_SRC_MIC:
chip->regCDSP &= ~VXP_CDSP_DATAIN_SEL_MASK;
if (_chip->type == VX_TYPE_VXP440) {
chip->regCDSP &= ~P24_CDSP_MICS_SEL_MASK;
if (chip->mic_level)
chip->regCDSP |= P24_CDSP_MIC38_SEL_MASK;
else
chip->regCDSP |= P24_CDSP_MIC20_SEL_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
} else {
chip->regCDSP |= VXP_CDSP_MIC_SEL_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
vx_outb(chip, MICRO, vx_compute_mic_level(chip->mic_level));
}
break;
}
}
static void vxp_set_clock_source(struct vx_core *_chip, int source)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
if (source == INTERNAL_QUARTZ)
chip->regCDSP &= ~VXP_CDSP_CLOCKIN_SEL_MASK;
else
chip->regCDSP |= VXP_CDSP_CLOCKIN_SEL_MASK;
vx_outb(chip, CDSP, chip->regCDSP);
}
static void vxp_reset_board(struct vx_core *_chip, int cold_reset)
{
struct snd_vxpocket *chip = (struct snd_vxpocket *)_chip;
chip->regCDSP = 0;
chip->regDIALOG = 0;
}
