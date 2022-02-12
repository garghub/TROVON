static void addi_eeprom_clk_93c76(unsigned long iobase, unsigned int val)
{
outl(val & ~EE93C76_CLK_BIT, iobase);
udelay(100);
outl(val | EE93C76_CLK_BIT, iobase);
udelay(100);
}
static unsigned int addi_eeprom_cmd_93c76(unsigned long iobase,
unsigned int cmd,
unsigned char len)
{
unsigned int val = EE93C76_CS_BIT;
int i;
outl(val, iobase);
udelay(100);
for (i = (len - 1); i >= 0; i--) {
if (cmd & (1 << i))
val |= EE93C76_DOUT_BIT;
else
val &= ~EE93C76_DOUT_BIT;
outl(val, iobase);
udelay(100);
addi_eeprom_clk_93c76(iobase, val);
}
return val;
}
static unsigned short addi_eeprom_readw_93c76(unsigned long iobase,
unsigned short addr)
{
unsigned short val = 0;
unsigned int cmd;
unsigned int tmp;
int i;
cmd = EE93C76_READ_CMD | (addr / 2);
cmd = addi_eeprom_cmd_93c76(iobase, cmd, EE93C76_CMD_LEN);
for (i = 0; i < 16; i++) {
addi_eeprom_clk_93c76(iobase, cmd);
tmp = inl(iobase);
udelay(100);
val <<= 1;
if (tmp & EE93C76_DIN_BIT)
val |= 0x1;
}
outl(0, iobase);
udelay(100);
return val;
}
static void addi_eeprom_nvram_wait(unsigned long iobase)
{
unsigned char val;
do {
val = inb(iobase + AMCC_OP_REG_MCSR_NVCMD);
} while (val & 0x80);
}
static unsigned short addi_eeprom_readw_nvram(unsigned long iobase,
unsigned short addr)
{
unsigned short val = 0;
unsigned char tmp;
unsigned char i;
for (i = 0; i < 2; i++) {
outb(NVCMD_LOAD_LOW, iobase + AMCC_OP_REG_MCSR_NVCMD);
addi_eeprom_nvram_wait(iobase);
outb((addr + i) & 0xff, iobase + AMCC_OP_REG_MCSR_NVDATA);
addi_eeprom_nvram_wait(iobase);
outb(NVCMD_LOAD_HIGH, iobase + AMCC_OP_REG_MCSR_NVCMD);
addi_eeprom_nvram_wait(iobase);
outb(((addr + i) >> 8) & 0xff,
iobase + AMCC_OP_REG_MCSR_NVDATA);
addi_eeprom_nvram_wait(iobase);
outb(NVCMD_BEGIN_READ, iobase + AMCC_OP_REG_MCSR_NVCMD);
addi_eeprom_nvram_wait(iobase);
tmp = inb(iobase + AMCC_OP_REG_MCSR_NVDATA);
addi_eeprom_nvram_wait(iobase);
if (i == 0)
val |= tmp;
else
val |= (tmp << 8);
}
return val;
}
static unsigned short addi_eeprom_readw(unsigned long iobase,
char *type,
unsigned short addr)
{
unsigned short val = 0;
addr += NVRAM_USER_DATA_START;
if (!strcmp(type, "S5920") || !strcmp(type, "S5933"))
val = addi_eeprom_readw_nvram(iobase, addr);
if (!strcmp(type, "93C76"))
val = addi_eeprom_readw_93c76(iobase, addr);
return val;
}
static void addi_eeprom_read_di_info(struct comedi_device *dev,
unsigned long iobase,
unsigned short addr)
{
const struct addi_board *this_board = dev->board_ptr;
struct addi_private *devpriv = dev->private;
char *type = this_board->pc_EepromChip;
unsigned short tmp;
tmp = addi_eeprom_readw(iobase, type, addr + 6);
devpriv->s_EeParameters.i_NbrDiChannel = tmp;
tmp = addi_eeprom_readw(iobase, type, addr + 8);
tmp = (tmp >> 7) & 0x01;
tmp = addi_eeprom_readw(iobase, type, addr + 10);
}
static void addi_eeprom_read_do_info(struct comedi_device *dev,
unsigned long iobase,
unsigned short addr)
{
const struct addi_board *this_board = dev->board_ptr;
struct addi_private *devpriv = dev->private;
char *type = this_board->pc_EepromChip;
unsigned short tmp;
tmp = addi_eeprom_readw(iobase, type, addr + 6);
devpriv->s_EeParameters.i_NbrDoChannel = tmp;
devpriv->s_EeParameters.i_DoMaxdata = 0xffffffff >> (32 - tmp);
}
static void addi_eeprom_read_timer_info(struct comedi_device *dev,
unsigned long iobase,
unsigned short addr)
{
struct addi_private *devpriv = dev->private;
#if 0
const struct addi_board *this_board = dev->board_ptr;
char *type = this_board->pc_EepromChip;
unsigned short offset = 0;
unsigned short ntimers;
unsigned short tmp;
int i;
ntimers = addi_eeprom_readw(iobase, type, addr + 6);
for (i = 0; i < ntimers; i++) {
unsigned short size;
unsigned short res;
unsigned short mode;
unsigned short min_timing;
unsigned short timebase;
size = addi_eeprom_readw(iobase, type, addr + 8 + offset + 0);
tmp = addi_eeprom_readw(iobase, type, addr + 8 + offset + 2);
res = (tmp >> 10) & 0x3f;
mode = (tmp >> 4) & 0x3f;
tmp = addi_eeprom_readw(iobase, type, addr + 8 + offset + 4);
min_timing = (tmp >> 6) & 0x3ff;
Timebase = tmp & 0x3f;
offset += size;
}
#endif
devpriv->s_EeParameters.i_Timer = 1;
}
static void addi_eeprom_read_ao_info(struct comedi_device *dev,
unsigned long iobase,
unsigned short addr)
{
const struct addi_board *this_board = dev->board_ptr;
struct addi_private *devpriv = dev->private;
char *type = this_board->pc_EepromChip;
unsigned short tmp;
tmp = addi_eeprom_readw(iobase, type, addr + 10);
devpriv->s_EeParameters.i_NbrAoChannel = (tmp >> 4) & 0x3ff;
tmp = addi_eeprom_readw(iobase, type, addr + 16);
tmp = (tmp >> 8) & 0xff;
devpriv->s_EeParameters.i_AoMaxdata = 0xfff >> (16 - tmp);
}
static void addi_eeprom_read_ai_info(struct comedi_device *dev,
unsigned long iobase,
unsigned short addr)
{
const struct addi_board *this_board = dev->board_ptr;
struct addi_private *devpriv = dev->private;
char *type = this_board->pc_EepromChip;
unsigned short offset;
unsigned short tmp;
tmp = addi_eeprom_readw(iobase, type, addr + 10);
devpriv->s_EeParameters.i_NbrAiChannel = (tmp >> 4) & 0x3ff;
if (!strcmp(this_board->pc_DriverName, "apci3200"))
devpriv->s_EeParameters.i_NbrAiChannel *= 4;
tmp = addi_eeprom_readw(iobase, type, addr + 16);
devpriv->s_EeParameters.ui_MinAcquisitiontimeNs = tmp * 1000;
tmp = addi_eeprom_readw(iobase, type, addr + 30);
devpriv->s_EeParameters.ui_MinDelaytimeNs = tmp * 1000;
tmp = addi_eeprom_readw(iobase, type, addr + 20);
tmp = addi_eeprom_readw(iobase, type, addr + 72) & 0xff;
if (tmp) {
offset = 74 + (2 * tmp) + (10 * (1 + (tmp / 16)));
} else {
offset = 74;
}
tmp = addi_eeprom_readw(iobase, type, addr + offset + 2) & 0x1f;
devpriv->s_EeParameters.i_AiMaxdata = 0xffff >> (16 - tmp);
}
static void addi_eeprom_read_info(struct comedi_device *dev,
unsigned long iobase)
{
const struct addi_board *this_board = dev->board_ptr;
char *type = this_board->pc_EepromChip;
unsigned short size;
unsigned char nfuncs;
int i;
size = addi_eeprom_readw(iobase, type, 8);
nfuncs = addi_eeprom_readw(iobase, type, 10) & 0xff;
for (i = 0; i < nfuncs; i++) {
unsigned short offset = i * 4;
unsigned short addr;
unsigned char func;
func = addi_eeprom_readw(iobase, type, 12 + offset) & 0x3f;
addr = addi_eeprom_readw(iobase, type, 14 + offset);
switch (func) {
case EEPROM_DIGITALINPUT:
addi_eeprom_read_di_info(dev, iobase, addr);
break;
case EEPROM_DIGITALOUTPUT:
addi_eeprom_read_do_info(dev, iobase, addr);
break;
case EEPROM_ANALOGINPUT:
addi_eeprom_read_ai_info(dev, iobase, addr);
break;
case EEPROM_ANALOGOUTPUT:
addi_eeprom_read_ao_info(dev, iobase, addr);
break;
case EEPROM_TIMER:
case EEPROM_WATCHDOG:
case EEPROM_TIMER_WATCHDOG_COUNTER:
addi_eeprom_read_timer_info(dev, iobase, addr);
break;
}
}
}
