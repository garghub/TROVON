static unsigned char pdacf_ak4117_read(void *private_data, unsigned char reg)
{
struct snd_pdacf *chip = private_data;
unsigned long timeout;
unsigned long flags;
unsigned char res;
spin_lock_irqsave(&chip->ak4117_lock, flags);
timeout = 1000;
while (pdacf_reg_read(chip, PDAUDIOCF_REG_SCR) & PDAUDIOCF_AK_SBP) {
udelay(5);
if (--timeout == 0) {
spin_unlock_irqrestore(&chip->ak4117_lock, flags);
snd_printk(KERN_ERR "AK4117 ready timeout (read)\n");
return 0;
}
}
pdacf_reg_write(chip, PDAUDIOCF_REG_AK_IFR, (u16)reg << 8);
timeout = 1000;
while (pdacf_reg_read(chip, PDAUDIOCF_REG_SCR) & PDAUDIOCF_AK_SBP) {
udelay(5);
if (--timeout == 0) {
spin_unlock_irqrestore(&chip->ak4117_lock, flags);
snd_printk(KERN_ERR "AK4117 read timeout (read2)\n");
return 0;
}
}
res = (unsigned char)pdacf_reg_read(chip, PDAUDIOCF_REG_AK_IFR);
spin_unlock_irqrestore(&chip->ak4117_lock, flags);
return res;
}
static void pdacf_ak4117_write(void *private_data, unsigned char reg, unsigned char val)
{
struct snd_pdacf *chip = private_data;
unsigned long timeout;
unsigned long flags;
spin_lock_irqsave(&chip->ak4117_lock, flags);
timeout = 1000;
while (inw(chip->port + PDAUDIOCF_REG_SCR) & PDAUDIOCF_AK_SBP) {
udelay(5);
if (--timeout == 0) {
spin_unlock_irqrestore(&chip->ak4117_lock, flags);
snd_printk(KERN_ERR "AK4117 ready timeout (write)\n");
return;
}
}
outw((u16)reg << 8 | val | (1<<13), chip->port + PDAUDIOCF_REG_AK_IFR);
spin_unlock_irqrestore(&chip->ak4117_lock, flags);
}
static int pdacf_reset(struct snd_pdacf *chip, int powerdown)
{
u16 val;
val = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
val |= PDAUDIOCF_PDN;
val &= ~PDAUDIOCF_RECORD;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
udelay(5);
val |= PDAUDIOCF_RST;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
udelay(200);
val &= ~PDAUDIOCF_RST;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
udelay(5);
if (!powerdown) {
val &= ~PDAUDIOCF_PDN;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
udelay(200);
}
return 0;
}
void pdacf_reinit(struct snd_pdacf *chip, int resume)
{
pdacf_reset(chip, 0);
if (resume)
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, chip->suspend_reg_scr);
snd_ak4117_reinit(chip->ak4117);
pdacf_reg_write(chip, PDAUDIOCF_REG_TCR, chip->regmap[PDAUDIOCF_REG_TCR>>1]);
pdacf_reg_write(chip, PDAUDIOCF_REG_IER, chip->regmap[PDAUDIOCF_REG_IER>>1]);
}
static void pdacf_proc_read(struct snd_info_entry * entry,
struct snd_info_buffer *buffer)
{
struct snd_pdacf *chip = entry->private_data;
u16 tmp;
snd_iprintf(buffer, "PDAudioCF\n\n");
tmp = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
snd_iprintf(buffer, "FPGA revision : 0x%x\n", PDAUDIOCF_FPGAREV(tmp));
}
static void pdacf_proc_init(struct snd_pdacf *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "pdaudiocf", &entry))
snd_info_set_text_ops(entry, chip, pdacf_proc_read);
}
struct snd_pdacf *snd_pdacf_create(struct snd_card *card)
{
struct snd_pdacf *chip;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL)
return NULL;
chip->card = card;
mutex_init(&chip->reg_lock);
spin_lock_init(&chip->ak4117_lock);
card->private_data = chip;
pdacf_proc_init(chip);
return chip;
}
static void snd_pdacf_ak4117_change(struct ak4117 *ak4117, unsigned char c0, unsigned char c1)
{
struct snd_pdacf *chip = ak4117->change_callback_private;
u16 val;
if (!(c0 & AK4117_UNLCK))
return;
mutex_lock(&chip->reg_lock);
val = chip->regmap[PDAUDIOCF_REG_SCR>>1];
if (ak4117->rcs0 & AK4117_UNLCK)
val |= PDAUDIOCF_BLUE_LED_OFF;
else
val &= ~PDAUDIOCF_BLUE_LED_OFF;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
mutex_unlock(&chip->reg_lock);
}
int snd_pdacf_ak4117_create(struct snd_pdacf *chip)
{
int err;
u16 val;
static unsigned char pgm[5] = {
AK4117_XTL_24_576M | AK4117_EXCT,
AK4117_CM_PLL_XTAL | AK4117_PKCS_128fs | AK4117_XCKS_128fs,
AK4117_EFH_1024LRCLK | AK4117_DIF_24R | AK4117_IPS,
0xff,
AK4117_MAUTO | AK4117_MAUD | AK4117_MULK | AK4117_MPAR | AK4117_MV,
};
err = pdacf_reset(chip, 0);
if (err < 0)
return err;
err = snd_ak4117_create(chip->card, pdacf_ak4117_read, pdacf_ak4117_write, pgm, chip, &chip->ak4117);
if (err < 0)
return err;
val = pdacf_reg_read(chip, PDAUDIOCF_REG_TCR);
#if 1
val &= ~(PDAUDIOCF_ELIMAKMBIT|PDAUDIOCF_TESTDATASEL);
#else
val |= PDAUDIOCF_ELIMAKMBIT;
val &= ~PDAUDIOCF_TESTDATASEL;
#endif
pdacf_reg_write(chip, PDAUDIOCF_REG_TCR, val);
val = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
val &= ~(PDAUDIOCF_CLKDIV0 | PDAUDIOCF_CLKDIV1);
val &= ~(PDAUDIOCF_RED_LED_OFF|PDAUDIOCF_BLUE_LED_OFF);
val |= PDAUDIOCF_DATAFMT0 | PDAUDIOCF_DATAFMT1;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
val = pdacf_reg_read(chip, PDAUDIOCF_REG_IER);
val &= ~(PDAUDIOCF_IRQLVLEN0 | PDAUDIOCF_IRQLVLEN1);
val &= ~(PDAUDIOCF_BLUEDUTY0 | PDAUDIOCF_REDDUTY0 | PDAUDIOCF_REDDUTY1);
val |= PDAUDIOCF_BLUEDUTY1 | PDAUDIOCF_HALFRATE;
val |= PDAUDIOCF_IRQOVREN | PDAUDIOCF_IRQAKMEN;
pdacf_reg_write(chip, PDAUDIOCF_REG_IER, val);
chip->ak4117->change_callback_private = chip;
chip->ak4117->change_callback = snd_pdacf_ak4117_change;
snd_pdacf_ak4117_change(chip->ak4117, AK4117_UNLCK, 0);
return 0;
}
void snd_pdacf_powerdown(struct snd_pdacf *chip)
{
u16 val;
val = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
chip->suspend_reg_scr = val;
val |= PDAUDIOCF_RED_LED_OFF | PDAUDIOCF_BLUE_LED_OFF;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, val);
val = inw(chip->port + PDAUDIOCF_REG_IER);
val &= ~(PDAUDIOCF_IRQOVREN|PDAUDIOCF_IRQAKMEN|PDAUDIOCF_IRQLVLEN0|PDAUDIOCF_IRQLVLEN1);
outw(val, chip->port + PDAUDIOCF_REG_IER);
pdacf_reset(chip, 1);
}
int snd_pdacf_suspend(struct snd_pdacf *chip)
{
u16 val;
snd_power_change_state(chip->card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm);
val = inw(chip->port + PDAUDIOCF_REG_IER);
val &= ~(PDAUDIOCF_IRQOVREN|PDAUDIOCF_IRQAKMEN|PDAUDIOCF_IRQLVLEN0|PDAUDIOCF_IRQLVLEN1);
outw(val, chip->port + PDAUDIOCF_REG_IER);
chip->chip_status |= PDAUDIOCF_STAT_IS_SUSPENDED;
snd_pdacf_powerdown(chip);
return 0;
}
static inline int check_signal(struct snd_pdacf *chip)
{
return (chip->ak4117->rcs0 & AK4117_UNLCK) == 0;
}
int snd_pdacf_resume(struct snd_pdacf *chip)
{
int timeout = 40;
pdacf_reinit(chip, 1);
while (timeout-- > 0 &&
(snd_ak4117_external_rate(chip->ak4117) <= 0 || !check_signal(chip)))
mdelay(1);
chip->chip_status &= ~PDAUDIOCF_STAT_IS_SUSPENDED;
snd_power_change_state(chip->card, SNDRV_CTL_POWER_D0);
return 0;
}
