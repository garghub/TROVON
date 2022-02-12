static inline void eeprom_93cx6_pulse_high(struct eeprom_93cx6 *eeprom)
{
eeprom->reg_data_clock = 1;
eeprom->register_write(eeprom);
ndelay(450);
}
static inline void eeprom_93cx6_pulse_low(struct eeprom_93cx6 *eeprom)
{
eeprom->reg_data_clock = 0;
eeprom->register_write(eeprom);
ndelay(450);
}
static void eeprom_93cx6_startup(struct eeprom_93cx6 *eeprom)
{
eeprom->register_read(eeprom);
eeprom->reg_data_in = 0;
eeprom->reg_data_out = 0;
eeprom->reg_data_clock = 0;
eeprom->reg_chip_select = 1;
eeprom->register_write(eeprom);
eeprom_93cx6_pulse_high(eeprom);
eeprom_93cx6_pulse_low(eeprom);
}
static void eeprom_93cx6_cleanup(struct eeprom_93cx6 *eeprom)
{
eeprom->register_read(eeprom);
eeprom->reg_data_in = 0;
eeprom->reg_chip_select = 0;
eeprom->register_write(eeprom);
eeprom_93cx6_pulse_high(eeprom);
eeprom_93cx6_pulse_low(eeprom);
}
static void eeprom_93cx6_write_bits(struct eeprom_93cx6 *eeprom,
const u16 data, const u16 count)
{
unsigned int i;
eeprom->register_read(eeprom);
eeprom->reg_data_in = 0;
eeprom->reg_data_out = 0;
for (i = count; i > 0; i--) {
eeprom->reg_data_in = !!(data & (1 << (i - 1)));
eeprom->register_write(eeprom);
eeprom_93cx6_pulse_high(eeprom);
eeprom_93cx6_pulse_low(eeprom);
}
eeprom->reg_data_in = 0;
eeprom->register_write(eeprom);
}
static void eeprom_93cx6_read_bits(struct eeprom_93cx6 *eeprom,
u16 *data, const u16 count)
{
unsigned int i;
u16 buf = 0;
eeprom->register_read(eeprom);
eeprom->reg_data_in = 0;
eeprom->reg_data_out = 0;
for (i = count; i > 0; i--) {
eeprom_93cx6_pulse_high(eeprom);
eeprom->register_read(eeprom);
eeprom->reg_data_in = 0;
if (eeprom->reg_data_out)
buf |= (1 << (i - 1));
eeprom_93cx6_pulse_low(eeprom);
}
*data = buf;
}
void eeprom_93cx6_read(struct eeprom_93cx6 *eeprom, const u8 word,
u16 *data)
{
u16 command;
eeprom_93cx6_startup(eeprom);
command = (PCI_EEPROM_READ_OPCODE << eeprom->width) | word;
eeprom_93cx6_write_bits(eeprom, command,
PCI_EEPROM_WIDTH_OPCODE + eeprom->width);
eeprom_93cx6_read_bits(eeprom, data, 16);
eeprom_93cx6_cleanup(eeprom);
}
void eeprom_93cx6_multiread(struct eeprom_93cx6 *eeprom, const u8 word,
__le16 *data, const u16 words)
{
unsigned int i;
u16 tmp;
for (i = 0; i < words; i++) {
tmp = 0;
eeprom_93cx6_read(eeprom, word + i, &tmp);
data[i] = cpu_to_le16(tmp);
}
}
