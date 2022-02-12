static inline void eeprom_cmd(unsigned int *ctrl, unsigned cmd, unsigned reg)
{
unsigned short ser_cmd;
int i;
ser_cmd = cmd | (reg << (16 - BITS_IN_COMMAND));
for (i = 0; i < BITS_IN_COMMAND; i++) {
if (ser_cmd & (1<<15))
__raw_writel(__raw_readl(ctrl) | EEPROM_DATO, ctrl);
else
__raw_writel(__raw_readl(ctrl) & ~EEPROM_DATO, ctrl);
__raw_writel(__raw_readl(ctrl) & ~EEPROM_ECLK, ctrl);
delay();
__raw_writel(__raw_readl(ctrl) | EEPROM_ECLK, ctrl);
delay();
ser_cmd <<= 1;
}
__raw_writel(__raw_readl(ctrl) & ~EEPROM_DATO, ctrl);
}
unsigned short ip22_eeprom_read(unsigned int *ctrl, int reg)
{
unsigned short res = 0;
int i;
__raw_writel(__raw_readl(ctrl) & ~EEPROM_EPROT, ctrl);
eeprom_cs_on(ctrl);
eeprom_cmd(ctrl, EEPROM_READ, reg);
for (i = 0; i < 16; i++) {
__raw_writel(__raw_readl(ctrl) & ~EEPROM_ECLK, ctrl);
delay();
__raw_writel(__raw_readl(ctrl) | EEPROM_ECLK, ctrl);
delay();
res <<= 1;
if (__raw_readl(ctrl) & EEPROM_DATI)
res |= 1;
}
eeprom_cs_off(ctrl);
return res;
}
unsigned short ip22_nvram_read(int reg)
{
if (ip22_is_fullhouse())
return ip22_eeprom_read(&hpc3c0->eeprom, reg);
else {
unsigned short tmp;
reg <<= 1;
tmp = hpc3c0->bbram[reg++] & 0xff;
return (tmp << 8) | (hpc3c0->bbram[reg] & 0xff);
}
}
