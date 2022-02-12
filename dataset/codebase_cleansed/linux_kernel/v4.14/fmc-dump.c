static const uint8_t *dump_line(int addr, const uint8_t *line,
const uint8_t *prev)
{
int i;
if (!prev || memcmp(line, prev, LINELEN)) {
pr_info("%04x: ", addr);
for (i = 0; i < LINELEN; ) {
printk(KERN_CONT "%02x", line[i]);
i++;
printk(i & 3 ? " " : i & (LINELEN - 1) ? " " : "\n");
}
return line;
}
if (line == prev + LINELEN)
pr_info("[...]\n");
return prev;
}
void fmc_dump_eeprom(const struct fmc_device *fmc)
{
const uint8_t *line, *prev;
int i;
if (!fmc_must_dump_eeprom)
return;
pr_info("FMC: %s (%s), slot %i, device %s\n", dev_name(fmc->hwdev),
fmc->carrier_name, fmc->slot_id, dev_name(&fmc->dev));
pr_info("FMC: dumping eeprom 0x%x (%i) bytes\n", fmc->eeprom_len,
fmc->eeprom_len);
line = fmc->eeprom;
prev = NULL;
for (i = 0; i < fmc->eeprom_len; i += LINELEN, line += LINELEN)
prev = dump_line(i, line, prev);
}
