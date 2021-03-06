void snd_emu10k1_voice_init(struct snd_emu10k1 *emu, int ch)
{
snd_emu10k1_ptr_write(emu, DCYSUSV, ch, 0);
snd_emu10k1_ptr_write(emu, IP, ch, 0);
snd_emu10k1_ptr_write(emu, VTFT, ch, 0xffff);
snd_emu10k1_ptr_write(emu, CVCF, ch, 0xffff);
snd_emu10k1_ptr_write(emu, PTRX, ch, 0);
snd_emu10k1_ptr_write(emu, CPF, ch, 0);
snd_emu10k1_ptr_write(emu, CCR, ch, 0);
snd_emu10k1_ptr_write(emu, PSST, ch, 0);
snd_emu10k1_ptr_write(emu, DSL, ch, 0x10);
snd_emu10k1_ptr_write(emu, CCCA, ch, 0);
snd_emu10k1_ptr_write(emu, Z1, ch, 0);
snd_emu10k1_ptr_write(emu, Z2, ch, 0);
snd_emu10k1_ptr_write(emu, FXRT, ch, 0x32100000);
snd_emu10k1_ptr_write(emu, ATKHLDM, ch, 0);
snd_emu10k1_ptr_write(emu, DCYSUSM, ch, 0);
snd_emu10k1_ptr_write(emu, IFATN, ch, 0xffff);
snd_emu10k1_ptr_write(emu, PEFE, ch, 0);
snd_emu10k1_ptr_write(emu, FMMOD, ch, 0);
snd_emu10k1_ptr_write(emu, TREMFRQ, ch, 24);
snd_emu10k1_ptr_write(emu, FM2FRQ2, ch, 24);
snd_emu10k1_ptr_write(emu, TEMPENV, ch, 0);
snd_emu10k1_ptr_write(emu, LFOVAL2, ch, 0);
snd_emu10k1_ptr_write(emu, LFOVAL1, ch, 0);
snd_emu10k1_ptr_write(emu, ATKHLDV, ch, 0);
snd_emu10k1_ptr_write(emu, ENVVOL, ch, 0);
snd_emu10k1_ptr_write(emu, ENVVAL, ch, 0);
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, 0x4c, ch, 0);
snd_emu10k1_ptr_write(emu, 0x4d, ch, 0);
snd_emu10k1_ptr_write(emu, 0x4e, ch, 0);
snd_emu10k1_ptr_write(emu, 0x4f, ch, 0);
snd_emu10k1_ptr_write(emu, A_FXRT1, ch, 0x03020100);
snd_emu10k1_ptr_write(emu, A_FXRT2, ch, 0x3f3f3f3f);
snd_emu10k1_ptr_write(emu, A_SENDAMOUNTS, ch, 0);
}
}
static int snd_emu10k1_init(struct snd_emu10k1 *emu, int enable_ir, int resume)
{
unsigned int silent_page;
int ch;
u32 tmp;
outl(HCFG_LOCKSOUNDCACHE | HCFG_LOCKTANKCACHE_MASK |
HCFG_MUTEBUTTONENABLE, emu->port + HCFG);
snd_emu10k1_ptr_write(emu, MICBS, 0, ADCBS_BUFSIZE_NONE);
snd_emu10k1_ptr_write(emu, MICBA, 0, 0);
snd_emu10k1_ptr_write(emu, FXBS, 0, ADCBS_BUFSIZE_NONE);
snd_emu10k1_ptr_write(emu, FXBA, 0, 0);
snd_emu10k1_ptr_write(emu, ADCBS, 0, ADCBS_BUFSIZE_NONE);
snd_emu10k1_ptr_write(emu, ADCBA, 0, 0);
outl(0, emu->port + INTE);
snd_emu10k1_ptr_write(emu, CLIEL, 0, 0);
snd_emu10k1_ptr_write(emu, CLIEH, 0, 0);
snd_emu10k1_ptr_write(emu, SOLEL, 0, 0);
snd_emu10k1_ptr_write(emu, SOLEH, 0, 0);
if (emu->audigy) {
snd_emu10k1_ptr_write(emu, SPBYPASS, 0, SPBYPASS_FORMAT);
snd_emu10k1_ptr_write(emu, AC97SLOT, 0, AC97SLOT_REAR_RIGHT |
AC97SLOT_REAR_LEFT);
}
for (ch = 0; ch < NUM_G; ch++)
snd_emu10k1_voice_init(emu, ch);
snd_emu10k1_ptr_write(emu, SPCS0, 0, emu->spdif_bits[0]);
snd_emu10k1_ptr_write(emu, SPCS1, 0, emu->spdif_bits[1]);
snd_emu10k1_ptr_write(emu, SPCS2, 0, emu->spdif_bits[2]);
if (emu->card_capabilities->ca0151_chip) {
tmp = snd_emu10k1_ptr_read(emu, A_SPDIF_SAMPLERATE, 0);
tmp &= 0xfffff1ff;
tmp |= (0x2<<9);
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, 0, tmp);
snd_emu10k1_ptr20_write(emu, SRCSel, 0, 0x14);
snd_emu10k1_ptr20_write(emu, SRCMULTI_ENABLE, 0, 0xFFFFFFFF);
outl(0x0201, emu->port + HCFG2);
snd_emu10k1_ptr20_write(emu, CAPTURE_P16V_SOURCE, 0, 0x78e4);
}
if (emu->card_capabilities->ca0108_chip) {
snd_printk(KERN_INFO "Audigy2 value: Special config.\n");
tmp = snd_emu10k1_ptr_read(emu, A_SPDIF_SAMPLERATE, 0);
tmp &= 0xfffff1ff;
tmp |= (0x2<<9);
snd_emu10k1_ptr_write(emu, A_SPDIF_SAMPLERATE, 0, tmp);
outl(0x600000, emu->port + 0x20);
outl(0x14, emu->port + 0x24);
outl(0x7b0000, emu->port + 0x20);
outl(0xFF000000, emu->port + 0x24);
outl(0x7a0000, emu->port + 0x20);
outl(0xFF000000, emu->port + 0x24);
tmp = inl(emu->port + A_IOCFG) & ~0x8;
outl(tmp, emu->port + A_IOCFG);
}
if (emu->card_capabilities->spi_dac) {
int size, n;
size = ARRAY_SIZE(spi_dac_init);
for (n = 0; n < size; n++)
snd_emu10k1_spi_write(emu, spi_dac_init[n]);
snd_emu10k1_ptr20_write(emu, 0x60, 0, 0x10);
outl(0x76, emu->port + A_IOCFG);
}
if (emu->card_capabilities->i2c_adc) {
int size, n;
snd_emu10k1_ptr20_write(emu, P17V_I2S_SRC_SEL, 0, 0x2020205f);
tmp = inl(emu->port + A_IOCFG);
outl(tmp | 0x4, emu->port + A_IOCFG);
tmp = inl(emu->port + A_IOCFG);
size = ARRAY_SIZE(i2c_adc_init);
for (n = 0; n < size; n++)
snd_emu10k1_i2c_write(emu, i2c_adc_init[n][0], i2c_adc_init[n][1]);
for (n = 0; n < 4; n++) {
emu->i2c_capture_volume[n][0] = 0xcf;
emu->i2c_capture_volume[n][1] = 0xcf;
}
}
snd_emu10k1_ptr_write(emu, PTB, 0, emu->ptb_pages.addr);
snd_emu10k1_ptr_write(emu, TCB, 0, 0);
snd_emu10k1_ptr_write(emu, TCBS, 0, 4);
silent_page = (emu->silent_page.addr << 1) | MAP_PTI_MASK;
for (ch = 0; ch < NUM_G; ch++) {
snd_emu10k1_ptr_write(emu, MAPA, ch, silent_page);
snd_emu10k1_ptr_write(emu, MAPB, ch, silent_page);
}
if (emu->card_capabilities->emu_model) {
outl(HCFG_AUTOMUTE_ASYNC |
HCFG_EMU32_SLAVE |
HCFG_AUDIOENABLE, emu->port + HCFG);
} else if (emu->audigy) {
if (emu->revision == 4)
outl(HCFG_AUDIOENABLE |
HCFG_AC3ENABLE_CDSPDIF |
HCFG_AC3ENABLE_GPSPDIF |
HCFG_AUTOMUTE | HCFG_JOYENABLE, emu->port + HCFG);
else
outl(HCFG_AUTOMUTE | HCFG_JOYENABLE, emu->port + HCFG);
} else if (emu->model == 0x20 ||
emu->model == 0xc400 ||
(emu->model == 0x21 && emu->revision < 6))
outl(HCFG_LOCKTANKCACHE_MASK | HCFG_AUTOMUTE, emu->port + HCFG);
else
outl(HCFG_LOCKTANKCACHE_MASK | HCFG_AUTOMUTE | HCFG_JOYENABLE, emu->port + HCFG);
if (enable_ir) {
if (emu->card_capabilities->emu_model) {
;
} else if (emu->card_capabilities->i2c_adc) {
;
} else if (emu->audigy) {
unsigned int reg = inl(emu->port + A_IOCFG);
outl(reg | A_IOCFG_GPOUT2, emu->port + A_IOCFG);
udelay(500);
outl(reg | A_IOCFG_GPOUT1 | A_IOCFG_GPOUT2, emu->port + A_IOCFG);
udelay(100);
outl(reg, emu->port + A_IOCFG);
} else {
unsigned int reg = inl(emu->port + HCFG);
outl(reg | HCFG_GPOUT2, emu->port + HCFG);
udelay(500);
outl(reg | HCFG_GPOUT1 | HCFG_GPOUT2, emu->port + HCFG);
udelay(100);
outl(reg, emu->port + HCFG);
}
}
if (emu->card_capabilities->emu_model) {
;
} else if (emu->card_capabilities->i2c_adc) {
;
} else if (emu->audigy) {
unsigned int reg = inl(emu->port + A_IOCFG);
outl(reg | A_IOCFG_GPOUT0, emu->port + A_IOCFG);
}
return 0;
}
static void snd_emu10k1_audio_enable(struct snd_emu10k1 *emu)
{
outl(inl(emu->port + HCFG) | HCFG_AUDIOENABLE, emu->port + HCFG);
if (emu->card_capabilities->emu_model) {
;
} else if (emu->card_capabilities->i2c_adc) {
;
} else if (emu->audigy) {
outl(inl(emu->port + A_IOCFG) & ~0x44, emu->port + A_IOCFG);
if (emu->card_capabilities->ca0151_chip) {
outl(inl(emu->port + A_IOCFG) | 0x0040, emu->port + A_IOCFG);
} else if (emu->card_capabilities->ca0108_chip) {
outl(inl(emu->port + A_IOCFG) | 0x0060, emu->port + A_IOCFG);
} else {
outl(inl(emu->port + A_IOCFG) | 0x0080, emu->port + A_IOCFG);
}
}
#if 0
{
unsigned int tmp;
emu->tos_link = 0;
tmp = inl(emu->port + HCFG);
if (tmp & (HCFG_GPINPUT0 | HCFG_GPINPUT1)) {
outl(tmp|0x800, emu->port + HCFG);
udelay(50);
if (tmp != (inl(emu->port + HCFG) & ~0x800)) {
emu->tos_link = 1;
outl(tmp, emu->port + HCFG);
}
}
}
#endif
snd_emu10k1_intr_enable(emu, INTE_PCIERRORENABLE);
}
int snd_emu10k1_done(struct snd_emu10k1 *emu)
{
int ch;
outl(0, emu->port + INTE);
for (ch = 0; ch < NUM_G; ch++)
snd_emu10k1_ptr_write(emu, DCYSUSV, ch, 0);
for (ch = 0; ch < NUM_G; ch++) {
snd_emu10k1_ptr_write(emu, VTFT, ch, 0);
snd_emu10k1_ptr_write(emu, CVCF, ch, 0);
snd_emu10k1_ptr_write(emu, PTRX, ch, 0);
snd_emu10k1_ptr_write(emu, CPF, ch, 0);
}
snd_emu10k1_ptr_write(emu, MICBS, 0, 0);
snd_emu10k1_ptr_write(emu, MICBA, 0, 0);
snd_emu10k1_ptr_write(emu, FXBS, 0, 0);
snd_emu10k1_ptr_write(emu, FXBA, 0, 0);
snd_emu10k1_ptr_write(emu, FXWC, 0, 0);
snd_emu10k1_ptr_write(emu, ADCBS, 0, ADCBS_BUFSIZE_NONE);
snd_emu10k1_ptr_write(emu, ADCBA, 0, 0);
snd_emu10k1_ptr_write(emu, TCBS, 0, TCBS_BUFFSIZE_16K);
snd_emu10k1_ptr_write(emu, TCB, 0, 0);
if (emu->audigy)
snd_emu10k1_ptr_write(emu, A_DBG, 0, A_DBG_SINGLE_STEP);
else
snd_emu10k1_ptr_write(emu, DBG, 0, EMU10K1_DBG_SINGLE_STEP);
snd_emu10k1_ptr_write(emu, CLIEL, 0, 0);
snd_emu10k1_ptr_write(emu, CLIEH, 0, 0);
snd_emu10k1_ptr_write(emu, SOLEL, 0, 0);
snd_emu10k1_ptr_write(emu, SOLEH, 0, 0);
outl(HCFG_LOCKSOUNDCACHE | HCFG_LOCKTANKCACHE_MASK | HCFG_MUTEBUTTONENABLE, emu->port + HCFG);
snd_emu10k1_ptr_write(emu, PTB, 0, 0);
return 0;
}
static void snd_emu10k1_ecard_write(struct snd_emu10k1 *emu, unsigned int value)
{
unsigned short count;
unsigned int data;
unsigned long hc_port;
unsigned int hc_value;
hc_port = emu->port + HCFG;
hc_value = inl(hc_port) & ~(HOOKN_BIT | HANDN_BIT | PULSEN_BIT);
outl(hc_value, hc_port);
for (count = 0; count < EC_NUM_CONTROL_BITS; count++) {
data = ((value & 0x1) ? PULSEN_BIT : 0);
value >>= 1;
outl(hc_value | data, hc_port);
outl(hc_value | data | HANDN_BIT, hc_port);
outl(hc_value | data, hc_port);
}
outl(hc_value | HOOKN_BIT, hc_port);
outl(hc_value, hc_port);
}
static void snd_emu10k1_ecard_setadcgain(struct snd_emu10k1 *emu,
unsigned short gain)
{
unsigned int bit;
snd_emu10k1_ecard_write(emu, emu->ecard_ctrl & ~EC_TRIM_CSN);
snd_emu10k1_ecard_write(emu, emu->ecard_ctrl & ~EC_TRIM_CSN);
for (bit = (1 << 15); bit; bit >>= 1) {
unsigned int value;
value = emu->ecard_ctrl & ~(EC_TRIM_CSN | EC_TRIM_SDATA);
if (gain & bit)
value |= EC_TRIM_SDATA;
snd_emu10k1_ecard_write(emu, value);
snd_emu10k1_ecard_write(emu, value | EC_TRIM_SCLK);
snd_emu10k1_ecard_write(emu, value);
}
snd_emu10k1_ecard_write(emu, emu->ecard_ctrl);
}
static int snd_emu10k1_ecard_init(struct snd_emu10k1 *emu)
{
unsigned int hc_value;
emu->ecard_ctrl = EC_RAW_RUN_MODE |
EC_SPDIF0_SELECT(EC_DEFAULT_SPDIF0_SEL) |
EC_SPDIF1_SELECT(EC_DEFAULT_SPDIF1_SEL);
hc_value = inl(emu->port + HCFG);
outl(hc_value | HCFG_AUDIOENABLE | HCFG_CODECFORMAT_I2S, emu->port + HCFG);
inl(emu->port + HCFG);
snd_emu10k1_ecard_write(emu, EC_ADCCAL | EC_LEDN | EC_TRIM_CSN);
snd_emu10k1_ecard_write(emu, EC_DACCAL | EC_LEDN | EC_TRIM_CSN);
snd_emu10k1_wait(emu, 48000);
snd_emu10k1_ecard_write(emu, EC_ADCCAL | EC_LEDN | EC_TRIM_CSN);
snd_emu10k1_ecard_write(emu, emu->ecard_ctrl);
snd_emu10k1_ecard_setadcgain(emu, EC_DEFAULT_ADC_GAIN);
return 0;
}
static int snd_emu10k1_cardbus_init(struct snd_emu10k1 *emu)
{
unsigned long special_port;
unsigned int value;
special_port = emu->port + 0x38;
value = inl(special_port);
outl(0x00d00000, special_port);
value = inl(special_port);
outl(0x00d00001, special_port);
value = inl(special_port);
outl(0x00d0005f, special_port);
value = inl(special_port);
outl(0x00d0007f, special_port);
value = inl(special_port);
outl(0x0090007f, special_port);
value = inl(special_port);
snd_emu10k1_ptr20_write(emu, TINA2_VOLUME, 0, 0xfefefefe);
msleep(200);
return 0;
}
static int snd_emu1010_load_firmware(struct snd_emu10k1 *emu, const char *filename)
{
int err;
int n, i;
int reg;
int value;
unsigned int write_post;
unsigned long flags;
const struct firmware *fw_entry;
err = request_firmware(&fw_entry, filename, &emu->pci->dev);
if (err != 0) {
snd_printk(KERN_ERR "firmware: %s not found. Err = %d\n", filename, err);
return err;
}
snd_printk(KERN_INFO "firmware size = 0x%zx\n", fw_entry->size);
spin_lock_irqsave(&emu->emu_lock, flags);
outl(0x00, emu->port + A_IOCFG);
write_post = inl(emu->port + A_IOCFG);
udelay(100);
outl(0x80, emu->port + A_IOCFG);
write_post = inl(emu->port + A_IOCFG);
udelay(100);
for (n = 0; n < fw_entry->size; n++) {
value = fw_entry->data[n];
for (i = 0; i < 8; i++) {
reg = 0x80;
if (value & 0x1)
reg = reg | 0x20;
value = value >> 1;
outl(reg, emu->port + A_IOCFG);
write_post = inl(emu->port + A_IOCFG);
outl(reg | 0x40, emu->port + A_IOCFG);
write_post = inl(emu->port + A_IOCFG);
}
}
outl(0x10, emu->port + A_IOCFG);
write_post = inl(emu->port + A_IOCFG);
spin_unlock_irqrestore(&emu->emu_lock, flags);
release_firmware(fw_entry);
return 0;
}
static int emu1010_firmware_thread(void *data)
{
struct snd_emu10k1 *emu = data;
u32 tmp, tmp2, reg;
int err;
for (;;) {
msleep_interruptible(1000);
if (kthread_should_stop())
break;
snd_emu1010_fpga_read(emu, EMU_HANA_IRQ_STATUS, &tmp);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &reg);
if (reg & EMU_HANA_OPTION_DOCK_OFFLINE) {
snd_printk(KERN_INFO "emu1010: Loading Audio Dock Firmware\n");
snd_emu1010_fpga_write(emu, EMU_HANA_FPGA_CONFIG, EMU_HANA_FPGA_CONFIG_AUDIODOCK);
if (emu->card_capabilities->emu_model ==
EMU_MODEL_EMU1010) {
err = snd_emu1010_load_firmware(emu, DOCK_FILENAME);
if (err != 0)
continue;
} else if (emu->card_capabilities->emu_model ==
EMU_MODEL_EMU1010B) {
err = snd_emu1010_load_firmware(emu, MICRO_DOCK_FILENAME);
if (err != 0)
continue;
} else if (emu->card_capabilities->emu_model ==
EMU_MODEL_EMU1616) {
err = snd_emu1010_load_firmware(emu, MICRO_DOCK_FILENAME);
if (err != 0)
continue;
}
snd_emu1010_fpga_write(emu, EMU_HANA_FPGA_CONFIG, 0);
snd_emu1010_fpga_read(emu, EMU_HANA_IRQ_STATUS, &reg);
snd_printk(KERN_INFO "emu1010: EMU_HANA+DOCK_IRQ_STATUS = 0x%x\n", reg);
snd_emu1010_fpga_read(emu, EMU_HANA_ID, &reg);
snd_printk(KERN_INFO "emu1010: EMU_HANA+DOCK_ID = 0x%x\n", reg);
if ((reg & 0x1f) != 0x15) {
snd_printk(KERN_INFO "emu1010: Loading Audio Dock Firmware file failed, reg = 0x%x\n", reg);
continue;
}
snd_printk(KERN_INFO "emu1010: Audio Dock Firmware loaded\n");
snd_emu1010_fpga_read(emu, EMU_DOCK_MAJOR_REV, &tmp);
snd_emu1010_fpga_read(emu, EMU_DOCK_MINOR_REV, &tmp2);
snd_printk(KERN_INFO "Audio Dock ver: %u.%u\n",
tmp, tmp2);
msleep(10);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, EMU_UNMUTE);
}
}
snd_printk(KERN_INFO "emu1010: firmware thread stopping\n");
return 0;
}
static int snd_emu10k1_emu1010_init(struct snd_emu10k1 *emu)
{
unsigned int i;
u32 tmp, tmp2, reg;
int err;
const char *filename = NULL;
snd_printk(KERN_INFO "emu1010: Special config.\n");
outl(0x0005a00c, emu->port + HCFG);
outl(0x0005a004, emu->port + HCFG);
outl(0x0005a000, emu->port + HCFG);
outl(0x0005a000, emu->port + HCFG);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_PWR, 0);
snd_emu1010_fpga_read(emu, EMU_HANA_ID, &reg);
snd_printdd("reg1 = 0x%x\n", reg);
if ((reg & 0x3f) == 0x15) {
snd_emu1010_fpga_write(emu, EMU_HANA_FPGA_CONFIG, 0x02);
}
snd_emu1010_fpga_read(emu, EMU_HANA_ID, &reg);
snd_printdd("reg2 = 0x%x\n", reg);
if ((reg & 0x3f) == 0x15) {
snd_printk(KERN_INFO "emu1010: FPGA failed to return to programming mode\n");
return -ENODEV;
}
snd_printk(KERN_INFO "emu1010: EMU_HANA_ID = 0x%x\n", reg);
switch (emu->card_capabilities->emu_model) {
case EMU_MODEL_EMU1010:
filename = HANA_FILENAME;
break;
case EMU_MODEL_EMU1010B:
filename = EMU1010B_FILENAME;
break;
case EMU_MODEL_EMU1616:
filename = EMU1010_NOTEBOOK_FILENAME;
break;
case EMU_MODEL_EMU0404:
filename = EMU0404_FILENAME;
break;
default:
filename = NULL;
return -ENODEV;
break;
}
snd_printk(KERN_INFO "emu1010: filename %s testing\n", filename);
err = snd_emu1010_load_firmware(emu, filename);
if (err != 0) {
snd_printk(
KERN_INFO "emu1010: Loading Firmware file %s failed\n",
filename);
return err;
}
snd_emu1010_fpga_read(emu, EMU_HANA_ID, &reg);
if ((reg & 0x3f) != 0x15) {
snd_printk(KERN_INFO "emu1010: Loading Hana Firmware file failed, reg = 0x%x\n", reg);
return -ENODEV;
}
snd_printk(KERN_INFO "emu1010: Hana Firmware loaded\n");
snd_emu1010_fpga_read(emu, EMU_HANA_MAJOR_REV, &tmp);
snd_emu1010_fpga_read(emu, EMU_HANA_MINOR_REV, &tmp2);
snd_printk(KERN_INFO "emu1010: Hana version: %u.%u\n", tmp, tmp2);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_PWR, EMU_HANA_DOCK_PWR_ON);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &reg);
snd_printk(KERN_INFO "emu1010: Card options = 0x%x\n", reg);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &reg);
snd_printk(KERN_INFO "emu1010: Card options = 0x%x\n", reg);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTICAL_TYPE, &tmp);
emu->emu1010.optical_in = 1;
emu->emu1010.optical_out = 1;
tmp = 0;
tmp = (emu->emu1010.optical_in ? EMU_HANA_OPTICAL_IN_ADAT : 0) |
(emu->emu1010.optical_out ? EMU_HANA_OPTICAL_OUT_ADAT : 0);
snd_emu1010_fpga_write(emu, EMU_HANA_OPTICAL_TYPE, tmp);
snd_emu1010_fpga_read(emu, EMU_HANA_ADC_PADS, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_ADC_PADS, 0x00);
emu->emu1010.adc_pads = 0x00;
snd_emu1010_fpga_read(emu, EMU_HANA_DOCK_MISC, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_MISC, 0x30);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2, 0x12);
snd_emu1010_fpga_read(emu, EMU_HANA_DAC_PADS, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_DAC_PADS, 0x0f);
emu->emu1010.dac_pads = 0x0f;
snd_emu1010_fpga_read(emu, EMU_HANA_DOCK_MISC, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_MISC, 0x30);
snd_emu1010_fpga_read(emu, EMU_HANA_SPDIF_MODE, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_SPDIF_MODE, 0x10);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_IN, 0x19);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_OUT, 0x0c);
snd_emu1010_fpga_write(emu, EMU_HANA_IRQ_ENABLE, 0x00);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &reg);
snd_printk(KERN_INFO "emu1010: Card options3 = 0x%x\n", reg);
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, 0x00);
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK, EMU_HANA_WCLOCK_INT_48K);
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2, 0x12);
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_0, EMU_SRC_HAMOA_ADC_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_1, EMU_SRC_HAMOA_ADC_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HAMOA_ADC_RIGHT2);
#endif
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_0, EMU_SRC_HAMOA_ADC_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_1, EMU_SRC_HAMOA_ADC_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_2, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_3, EMU_SRC_HAMOA_ADC_RIGHT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HAMOA_ADC_LEFT3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HAMOA_ADC_RIGHT3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_6, EMU_SRC_HAMOA_ADC_LEFT4);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_7, EMU_SRC_HAMOA_ADC_RIGHT4);
#endif
#if 1
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_0, EMU_SRC_DOCK_MIC_A1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_1, EMU_SRC_DOCK_MIC_B1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_2, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_3, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_DOCK_ADC1_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_DOCK_ADC1_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_6, EMU_SRC_DOCK_ADC2_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_7, EMU_SRC_DOCK_ADC2_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_8, EMU_SRC_DOCK_MIC_A1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_9, EMU_SRC_DOCK_MIC_B1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_A, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_B, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_C, EMU_SRC_DOCK_ADC1_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_D, EMU_SRC_DOCK_ADC1_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_E, EMU_SRC_DOCK_ADC2_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_F, EMU_SRC_DOCK_ADC2_RIGHT1);
#endif
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_4, EMU_SRC_HANA_ADAT);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_5, EMU_SRC_HANA_ADAT + 1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_6, EMU_SRC_HANA_ADAT + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_7, EMU_SRC_HANA_ADAT + 3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_8, EMU_SRC_HANA_ADAT + 4);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_9, EMU_SRC_HANA_ADAT + 5);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_A, EMU_SRC_HANA_ADAT + 6);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_B, EMU_SRC_HANA_ADAT + 7);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_C, EMU_SRC_DOCK_MIC_A1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_D, EMU_SRC_DOCK_MIC_B1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_E, EMU_SRC_HAMOA_ADC_LEFT2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE2_EMU32_F, EMU_SRC_HAMOA_ADC_LEFT2);
#endif
for (i = 0; i < 0x20; i++) {
snd_emu1010_fpga_link_dst_src_write(emu, 0x0100 + i, EMU_SRC_SILENCE);
}
for (i = 0; i < 4; i++) {
snd_emu1010_fpga_link_dst_src_write(emu, 0x0200 + i, EMU_SRC_SILENCE);
}
for (i = 0; i < 7; i++) {
snd_emu1010_fpga_link_dst_src_write(emu, 0x0300 + i, EMU_SRC_SILENCE);
}
for (i = 0; i < 7; i++) {
snd_emu1010_fpga_link_dst_src_write(emu, EMU_DST_HANA_ADAT + i, EMU_SRC_SILENCE);
}
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S0_LEFT, EMU_SRC_DOCK_ADC1_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S0_RIGHT, EMU_SRC_DOCK_ADC1_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S1_LEFT, EMU_SRC_DOCK_ADC2_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S1_RIGHT, EMU_SRC_DOCK_ADC2_RIGHT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S2_LEFT, EMU_SRC_DOCK_ADC3_LEFT1);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_ALICE_I2S2_RIGHT, EMU_SRC_DOCK_ADC3_RIGHT1);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, 0x01);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &tmp);
outl(0x0000a000, emu->port + HCFG);
outl(0x0000a001, emu->port + HCFG);
snd_emu1010_fpga_read(emu, EMU_HANA_OPTION_CARDS, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_IN, 0x19);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_OUT, 0x0c);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_IN, 0x19);
snd_emu1010_fpga_write(emu, EMU_HANA_MIDI_OUT, 0x0c);
snd_emu1010_fpga_read(emu, EMU_HANA_SPDIF_MODE, &tmp);
snd_emu1010_fpga_write(emu, EMU_HANA_SPDIF_MODE, 0x10);
if (!emu->emu1010.firmware_thread) {
emu->emu1010.firmware_thread =
kthread_create(emu1010_firmware_thread, emu,
"emu1010_firmware");
wake_up_process(emu->emu1010.firmware_thread);
}
#if 0
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_LEFT1, EMU_SRC_ALICE_EMU32B + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_RIGHT1, EMU_SRC_ALICE_EMU32B + 3);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_LEFT1, EMU_SRC_ALICE_EMU32A + 2);
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_RIGHT1, EMU_SRC_ALICE_EMU32A + 3);
#endif
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1616) {
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC1_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[0] = 17;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC1_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[1] = 18;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC2_LEFT1, EMU_SRC_ALICE_EMU32A + 2);
emu->emu1010.output_source[2] = 19;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC2_RIGHT1, EMU_SRC_ALICE_EMU32A + 3);
emu->emu1010.output_source[3] = 20;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC3_LEFT1, EMU_SRC_ALICE_EMU32A + 4);
emu->emu1010.output_source[4] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC3_RIGHT1, EMU_SRC_ALICE_EMU32A + 5);
emu->emu1010.output_source[5] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_MANA_DAC_LEFT, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[16] = 17;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_MANA_DAC_RIGHT, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[17] = 18;
} else {
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC1_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[0] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC1_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[1] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC2_LEFT1, EMU_SRC_ALICE_EMU32A + 2);
emu->emu1010.output_source[2] = 23;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC2_RIGHT1, EMU_SRC_ALICE_EMU32A + 3);
emu->emu1010.output_source[3] = 24;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC3_LEFT1, EMU_SRC_ALICE_EMU32A + 4);
emu->emu1010.output_source[4] = 25;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC3_RIGHT1, EMU_SRC_ALICE_EMU32A + 5);
emu->emu1010.output_source[5] = 26;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC4_LEFT1, EMU_SRC_ALICE_EMU32A + 6);
emu->emu1010.output_source[6] = 27;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_DAC4_RIGHT1, EMU_SRC_ALICE_EMU32A + 7);
emu->emu1010.output_source[7] = 28;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_PHONES_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[8] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_PHONES_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[9] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_SPDIF_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[10] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_DOCK_SPDIF_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[11] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[12] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_SPDIF_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[13] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_LEFT1, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[14] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HAMOA_DAC_RIGHT1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[15] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT, EMU_SRC_ALICE_EMU32A + 0);
emu->emu1010.output_source[16] = 21;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 1, EMU_SRC_ALICE_EMU32A + 1);
emu->emu1010.output_source[17] = 22;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 2, EMU_SRC_ALICE_EMU32A + 2);
emu->emu1010.output_source[18] = 23;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 3, EMU_SRC_ALICE_EMU32A + 3);
emu->emu1010.output_source[19] = 24;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 4, EMU_SRC_ALICE_EMU32A + 4);
emu->emu1010.output_source[20] = 25;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 5, EMU_SRC_ALICE_EMU32A + 5);
emu->emu1010.output_source[21] = 26;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 6, EMU_SRC_ALICE_EMU32A + 6);
emu->emu1010.output_source[22] = 27;
snd_emu1010_fpga_link_dst_src_write(emu,
EMU_DST_HANA_ADAT + 7, EMU_SRC_ALICE_EMU32A + 7);
emu->emu1010.output_source[23] = 28;
}
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, 0x0);
snd_emu1010_fpga_write(emu, EMU_HANA_DEFCLOCK, 0x0);
snd_emu1010_fpga_write(emu, EMU_HANA_WCLOCK, EMU_HANA_WCLOCK_INT_48K);
emu->emu1010.internal_clock = 1;
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_LEDS_2, 0x12);
snd_emu1010_fpga_write(emu, EMU_HANA_UNMUTE, 0x1);
return 0;
}
static int snd_emu10k1_free(struct snd_emu10k1 *emu)
{
if (emu->port) {
snd_emu10k1_fx8010_tram_setup(emu, 0);
snd_emu10k1_done(emu);
snd_emu10k1_free_efx(emu);
}
if (emu->card_capabilities->emu_model == EMU_MODEL_EMU1010) {
snd_emu1010_fpga_write(emu, EMU_HANA_DOCK_PWR, 0);
}
if (emu->emu1010.firmware_thread)
kthread_stop(emu->emu1010.firmware_thread);
if (emu->irq >= 0)
free_irq(emu->irq, emu);
if (emu->reserved_page) {
snd_emu10k1_synth_free(emu,
(struct snd_util_memblk *)emu->reserved_page);
emu->reserved_page = NULL;
}
if (emu->memhdr)
snd_util_memhdr_free(emu->memhdr);
if (emu->silent_page.area)
snd_dma_free_pages(&emu->silent_page);
if (emu->ptb_pages.area)
snd_dma_free_pages(&emu->ptb_pages);
vfree(emu->page_ptr_table);
vfree(emu->page_addr_table);
#ifdef CONFIG_PM
free_pm_buffer(emu);
#endif
if (emu->port)
pci_release_regions(emu->pci);
if (emu->card_capabilities->ca0151_chip)
snd_p16v_free(emu);
pci_disable_device(emu->pci);
kfree(emu);
return 0;
}
static int snd_emu10k1_dev_free(struct snd_device *device)
{
struct snd_emu10k1 *emu = device->device_data;
return snd_emu10k1_free(emu);
}
int __devinit snd_emu10k1_create(struct snd_card *card,
struct pci_dev *pci,
unsigned short extin_mask,
unsigned short extout_mask,
long max_cache_bytes,
int enable_ir,
uint subsystem,
struct snd_emu10k1 **remu)
{
struct snd_emu10k1 *emu;
int idx, err;
int is_audigy;
unsigned int silent_page;
const struct snd_emu_chip_details *c;
static struct snd_device_ops ops = {
.dev_free = snd_emu10k1_dev_free,
};
*remu = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
emu = kzalloc(sizeof(*emu), GFP_KERNEL);
if (emu == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
emu->card = card;
spin_lock_init(&emu->reg_lock);
spin_lock_init(&emu->emu_lock);
spin_lock_init(&emu->spi_lock);
spin_lock_init(&emu->i2c_lock);
spin_lock_init(&emu->voice_lock);
spin_lock_init(&emu->synth_lock);
spin_lock_init(&emu->memblk_lock);
mutex_init(&emu->fx8010.lock);
INIT_LIST_HEAD(&emu->mapped_link_head);
INIT_LIST_HEAD(&emu->mapped_order_link_head);
emu->pci = pci;
emu->irq = -1;
emu->synth = NULL;
emu->get_synth_voice = NULL;
emu->revision = pci->revision;
pci_read_config_dword(pci, PCI_SUBSYSTEM_VENDOR_ID, &emu->serial);
pci_read_config_word(pci, PCI_SUBSYSTEM_ID, &emu->model);
snd_printdd("vendor = 0x%x, device = 0x%x, subsystem_vendor_id = 0x%x, subsystem_id = 0x%x\n", pci->vendor, pci->device, emu->serial, emu->model);
for (c = emu_chip_details; c->vendor; c++) {
if (c->vendor == pci->vendor && c->device == pci->device) {
if (subsystem) {
if (c->subsystem && (c->subsystem == subsystem))
break;
else
continue;
} else {
if (c->subsystem && (c->subsystem != emu->serial))
continue;
if (c->revision && c->revision != emu->revision)
continue;
}
break;
}
}
if (c->vendor == 0) {
snd_printk(KERN_ERR "emu10k1: Card not recognised\n");
kfree(emu);
pci_disable_device(pci);
return -ENOENT;
}
emu->card_capabilities = c;
if (c->subsystem && !subsystem)
snd_printdd("Sound card name = %s\n", c->name);
else if (subsystem)
snd_printdd("Sound card name = %s, "
"vendor = 0x%x, device = 0x%x, subsystem = 0x%x. "
"Forced to subsystem = 0x%x\n", c->name,
pci->vendor, pci->device, emu->serial, c->subsystem);
else
snd_printdd("Sound card name = %s, "
"vendor = 0x%x, device = 0x%x, subsystem = 0x%x.\n",
c->name, pci->vendor, pci->device,
emu->serial);
if (!*card->id && c->id) {
int i, n = 0;
strlcpy(card->id, c->id, sizeof(card->id));
for (;;) {
for (i = 0; i < snd_ecards_limit; i++) {
if (snd_cards[i] && !strcmp(snd_cards[i]->id, card->id))
break;
}
if (i >= snd_ecards_limit)
break;
n++;
if (n >= SNDRV_CARDS)
break;
snprintf(card->id, sizeof(card->id), "%s_%d", c->id, n);
}
}
is_audigy = emu->audigy = c->emu10k2_chip;
emu->dma_mask = is_audigy ? AUDIGY_DMA_MASK : EMU10K1_DMA_MASK;
if (pci_set_dma_mask(pci, emu->dma_mask) < 0 ||
pci_set_consistent_dma_mask(pci, emu->dma_mask) < 0) {
snd_printk(KERN_ERR "architecture does not support PCI busmaster DMA with mask 0x%lx\n", emu->dma_mask);
kfree(emu);
pci_disable_device(pci);
return -ENXIO;
}
if (is_audigy)
emu->gpr_base = A_FXGPREGBASE;
else
emu->gpr_base = FXGPREGBASE;
err = pci_request_regions(pci, "EMU10K1");
if (err < 0) {
kfree(emu);
pci_disable_device(pci);
return err;
}
emu->port = pci_resource_start(pci, 0);
emu->max_cache_pages = max_cache_bytes >> PAGE_SHIFT;
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
32 * 1024, &emu->ptb_pages) < 0) {
err = -ENOMEM;
goto error;
}
emu->page_ptr_table = vmalloc(emu->max_cache_pages * sizeof(void *));
emu->page_addr_table = vmalloc(emu->max_cache_pages *
sizeof(unsigned long));
if (emu->page_ptr_table == NULL || emu->page_addr_table == NULL) {
err = -ENOMEM;
goto error;
}
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
EMUPAGESIZE, &emu->silent_page) < 0) {
err = -ENOMEM;
goto error;
}
emu->memhdr = snd_util_memhdr_new(emu->max_cache_pages * PAGE_SIZE);
if (emu->memhdr == NULL) {
err = -ENOMEM;
goto error;
}
emu->memhdr->block_extra_size = sizeof(struct snd_emu10k1_memblk) -
sizeof(struct snd_util_memblk);
pci_set_master(pci);
emu->fx8010.fxbus_mask = 0x303f;
if (extin_mask == 0)
extin_mask = 0x3fcf;
if (extout_mask == 0)
extout_mask = 0x7fff;
emu->fx8010.extin_mask = extin_mask;
emu->fx8010.extout_mask = extout_mask;
emu->enable_ir = enable_ir;
if (emu->card_capabilities->ca_cardbus_chip) {
err = snd_emu10k1_cardbus_init(emu);
if (err < 0)
goto error;
}
if (emu->card_capabilities->ecard) {
err = snd_emu10k1_ecard_init(emu);
if (err < 0)
goto error;
} else if (emu->card_capabilities->emu_model) {
err = snd_emu10k1_emu1010_init(emu);
if (err < 0) {
snd_emu10k1_free(emu);
return err;
}
} else {
snd_emu10k1_ptr_write(emu, AC97SLOT, 0,
AC97SLOT_CNTR|AC97SLOT_LFE);
}
emu->fx8010.itram_size = (16 * 1024)/2;
emu->fx8010.etram_pages.area = NULL;
emu->fx8010.etram_pages.bytes = 0;
if (request_irq(pci->irq, snd_emu10k1_interrupt, IRQF_SHARED,
KBUILD_MODNAME, emu)) {
err = -EBUSY;
goto error;
}
emu->irq = pci->irq;
emu->spdif_bits[0] = emu->spdif_bits[1] =
emu->spdif_bits[2] = SPCS_CLKACCY_1000PPM | SPCS_SAMPLERATE_48 |
SPCS_CHANNELNUM_LEFT | SPCS_SOURCENUM_UNSPEC |
SPCS_GENERATIONSTATUS | 0x00001200 |
0x00000000 | SPCS_EMPHASIS_NONE | SPCS_COPYRIGHT;
emu->reserved_page = (struct snd_emu10k1_memblk *)
snd_emu10k1_synth_alloc(emu, 4096);
if (emu->reserved_page)
emu->reserved_page->map_locked = 1;
memset(emu->silent_page.area, 0, PAGE_SIZE);
silent_page = emu->silent_page.addr << 1;
for (idx = 0; idx < MAXPAGES; idx++)
((u32 *)emu->ptb_pages.area)[idx] = cpu_to_le32(silent_page | idx);
for (idx = 0; idx < NUM_G; idx++) {
emu->voices[idx].emu = emu;
emu->voices[idx].number = idx;
}
err = snd_emu10k1_init(emu, enable_ir, 0);
if (err < 0)
goto error;
#ifdef CONFIG_PM
err = alloc_pm_buffer(emu);
if (err < 0)
goto error;
#endif
err = snd_emu10k1_init_efx(emu);
if (err < 0)
goto error;
snd_emu10k1_audio_enable(emu);
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, emu, &ops);
if (err < 0)
goto error;
#ifdef CONFIG_PROC_FS
snd_emu10k1_proc_init(emu);
#endif
snd_card_set_dev(card, &pci->dev);
*remu = emu;
return 0;
error:
snd_emu10k1_free(emu);
return err;
}
static int __devinit alloc_pm_buffer(struct snd_emu10k1 *emu)
{
int size;
size = ARRAY_SIZE(saved_regs);
if (emu->audigy)
size += ARRAY_SIZE(saved_regs_audigy);
emu->saved_ptr = vmalloc(4 * NUM_G * size);
if (!emu->saved_ptr)
return -ENOMEM;
if (snd_emu10k1_efx_alloc_pm_buffer(emu) < 0)
return -ENOMEM;
if (emu->card_capabilities->ca0151_chip &&
snd_p16v_alloc_pm_buffer(emu) < 0)
return -ENOMEM;
return 0;
}
static void free_pm_buffer(struct snd_emu10k1 *emu)
{
vfree(emu->saved_ptr);
snd_emu10k1_efx_free_pm_buffer(emu);
if (emu->card_capabilities->ca0151_chip)
snd_p16v_free_pm_buffer(emu);
}
void snd_emu10k1_suspend_regs(struct snd_emu10k1 *emu)
{
int i;
unsigned char *reg;
unsigned int *val;
val = emu->saved_ptr;
for (reg = saved_regs; *reg != 0xff; reg++)
for (i = 0; i < NUM_G; i++, val++)
*val = snd_emu10k1_ptr_read(emu, *reg, i);
if (emu->audigy) {
for (reg = saved_regs_audigy; *reg != 0xff; reg++)
for (i = 0; i < NUM_G; i++, val++)
*val = snd_emu10k1_ptr_read(emu, *reg, i);
}
if (emu->audigy)
emu->saved_a_iocfg = inl(emu->port + A_IOCFG);
emu->saved_hcfg = inl(emu->port + HCFG);
}
void snd_emu10k1_resume_init(struct snd_emu10k1 *emu)
{
if (emu->card_capabilities->ca_cardbus_chip)
snd_emu10k1_cardbus_init(emu);
if (emu->card_capabilities->ecard)
snd_emu10k1_ecard_init(emu);
else if (emu->card_capabilities->emu_model)
snd_emu10k1_emu1010_init(emu);
else
snd_emu10k1_ptr_write(emu, AC97SLOT, 0, AC97SLOT_CNTR|AC97SLOT_LFE);
snd_emu10k1_init(emu, emu->enable_ir, 1);
}
void snd_emu10k1_resume_regs(struct snd_emu10k1 *emu)
{
int i;
unsigned char *reg;
unsigned int *val;
snd_emu10k1_audio_enable(emu);
if (emu->audigy)
outl(emu->saved_a_iocfg, emu->port + A_IOCFG);
outl(emu->saved_hcfg, emu->port + HCFG);
val = emu->saved_ptr;
for (reg = saved_regs; *reg != 0xff; reg++)
for (i = 0; i < NUM_G; i++, val++)
snd_emu10k1_ptr_write(emu, *reg, i, *val);
if (emu->audigy) {
for (reg = saved_regs_audigy; *reg != 0xff; reg++)
for (i = 0; i < NUM_G; i++, val++)
snd_emu10k1_ptr_write(emu, *reg, i, *val);
}
}
