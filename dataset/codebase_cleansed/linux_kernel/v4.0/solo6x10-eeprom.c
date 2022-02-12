static unsigned int solo_eeprom_reg_read(struct solo_dev *solo_dev)
{
return solo_reg_read(solo_dev, SOLO_EEPROM_CTRL) & EE_DATA_READ;
}
static void solo_eeprom_reg_write(struct solo_dev *solo_dev, u32 data)
{
solo_reg_write(solo_dev, SOLO_EEPROM_CTRL, data);
eeprom_delay();
}
static void solo_eeprom_cmd(struct solo_dev *solo_dev, int cmd)
{
int i;
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ACCESS_EN);
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE);
for (i = 4 + ADDR_LEN; i >= 0; i--) {
int dataval = (cmd & (1 << i)) ? EE_DATA_WRITE : 0;
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE | dataval);
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE |
EE_SHIFT_CLK | dataval);
}
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE);
}
unsigned int solo_eeprom_ewen(struct solo_dev *solo_dev, int w_en)
{
int ewen_cmd = (w_en ? 0x3f : 0) | (EE_EWEN_CMD << ADDR_LEN);
unsigned int retval = 0;
int i;
solo_eeprom_cmd(solo_dev, ewen_cmd);
for (i = 0; i < 16; i++) {
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE |
EE_SHIFT_CLK);
retval = (retval << 1) | solo_eeprom_reg_read(solo_dev);
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE);
retval = (retval << 1) | solo_eeprom_reg_read(solo_dev);
}
solo_eeprom_reg_write(solo_dev, ~EE_CS);
retval = (retval << 1) | solo_eeprom_reg_read(solo_dev);
return retval;
}
__be16 solo_eeprom_read(struct solo_dev *solo_dev, int loc)
{
int read_cmd = loc | (EE_READ_CMD << ADDR_LEN);
u16 retval = 0;
int i;
solo_eeprom_cmd(solo_dev, read_cmd);
for (i = 0; i < 16; i++) {
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE |
EE_SHIFT_CLK);
retval = (retval << 1) | solo_eeprom_reg_read(solo_dev);
solo_eeprom_reg_write(solo_dev, SOLO_EEPROM_ENABLE);
}
solo_eeprom_reg_write(solo_dev, ~EE_CS);
return (__force __be16)retval;
}
int solo_eeprom_write(struct solo_dev *solo_dev, int loc,
__be16 data)
{
int write_cmd = loc | (EE_WRITE_CMD << ADDR_LEN);
unsigned int retval;
int i;
solo_eeprom_cmd(solo_dev, write_cmd);
for (i = 15; i >= 0; i--) {
unsigned int dataval = ((__force unsigned)data >> i) & 1;
solo_eeprom_reg_write(solo_dev, EE_ENB);
solo_eeprom_reg_write(solo_dev,
EE_ENB | (dataval << 1) | EE_SHIFT_CLK);
}
solo_eeprom_reg_write(solo_dev, EE_ENB);
solo_eeprom_reg_write(solo_dev, ~EE_CS);
solo_eeprom_reg_write(solo_dev, EE_ENB);
for (i = retval = 0; i < 10000 && !retval; i++)
retval = solo_eeprom_reg_read(solo_dev);
solo_eeprom_reg_write(solo_dev, ~EE_CS);
return !retval;
}
