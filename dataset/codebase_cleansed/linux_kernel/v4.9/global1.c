int mv88e6xxx_g1_read(struct mv88e6xxx_chip *chip, int reg, u16 *val)
{
int addr = chip->info->global1_addr;
return mv88e6xxx_read(chip, addr, reg, val);
}
int mv88e6xxx_g1_write(struct mv88e6xxx_chip *chip, int reg, u16 val)
{
int addr = chip->info->global1_addr;
return mv88e6xxx_write(chip, addr, reg, val);
}
int mv88e6xxx_g1_wait(struct mv88e6xxx_chip *chip, int reg, u16 mask)
{
return mv88e6xxx_wait(chip, chip->info->global1_addr, reg, mask);
}
