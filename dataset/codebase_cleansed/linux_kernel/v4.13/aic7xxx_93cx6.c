static void
send_seeprom_cmd(struct seeprom_descriptor *sd, const struct seeprom_cmd *cmd)
{
uint8_t temp;
int i = 0;
temp = sd->sd_MS ^ sd->sd_CS;
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
for (i = 0; i < cmd->len; i++) {
if (cmd->bits[i] != 0)
temp ^= sd->sd_DO;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
if (cmd->bits[i] != 0)
temp ^= sd->sd_DO;
}
}
static void
reset_seeprom(struct seeprom_descriptor *sd)
{
uint8_t temp;
temp = sd->sd_MS;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
}
int
ahc_read_seeprom(struct seeprom_descriptor *sd, uint16_t *buf,
u_int start_addr, u_int count)
{
int i = 0;
u_int k = 0;
uint16_t v;
uint8_t temp;
for (k = start_addr; k < count + start_addr; k++) {
send_seeprom_cmd(sd, &seeprom_read);
temp = sd->sd_MS ^ sd->sd_CS;
for (i = (sd->sd_chip - 1); i >= 0; i--) {
if ((k & (1 << i)) != 0)
temp ^= sd->sd_DO;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
if ((k & (1 << i)) != 0)
temp ^= sd->sd_DO;
}
v = 0;
for (i = 16; i >= 0; i--) {
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
v <<= 1;
if (SEEPROM_DATA_INB(sd) & sd->sd_DI)
v |= 1;
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
}
buf[k - start_addr] = v;
reset_seeprom(sd);
}
#ifdef AHC_DUMP_EEPROM
printk("\nSerial EEPROM:\n\t");
for (k = 0; k < count; k = k + 1) {
if (((k % 8) == 0) && (k != 0)) {
printk(KERN_CONT "\n\t");
}
printk(KERN_CONT " 0x%x", buf[k]);
}
printk(KERN_CONT "\n");
#endif
return (1);
}
int
ahc_write_seeprom(struct seeprom_descriptor *sd, uint16_t *buf,
u_int start_addr, u_int count)
{
const struct seeprom_cmd *ewen, *ewds;
uint16_t v;
uint8_t temp;
int i, k;
if (sd->sd_chip == C46) {
ewen = &seeprom_ewen;
ewds = &seeprom_ewds;
} else if (sd->sd_chip == C56_66) {
ewen = &seeprom_long_ewen;
ewds = &seeprom_long_ewds;
} else {
printk("ahc_write_seeprom: unsupported seeprom type %d\n",
sd->sd_chip);
return (0);
}
send_seeprom_cmd(sd, ewen);
reset_seeprom(sd);
temp = sd->sd_MS ^ sd->sd_CS;
for (k = start_addr; k < count + start_addr; k++) {
send_seeprom_cmd(sd, &seeprom_write);
for (i = (sd->sd_chip - 1); i >= 0; i--) {
if ((k & (1 << i)) != 0)
temp ^= sd->sd_DO;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
if ((k & (1 << i)) != 0)
temp ^= sd->sd_DO;
}
v = buf[k - start_addr];
for (i = 15; i >= 0; i--) {
if ((v & (1 << i)) != 0)
temp ^= sd->sd_DO;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
if ((v & (1 << i)) != 0)
temp ^= sd->sd_DO;
}
temp = sd->sd_MS;
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
temp = sd->sd_MS ^ sd->sd_CS;
do {
SEEPROM_OUTB(sd, temp);
CLOCK_PULSE(sd, sd->sd_RDY);
SEEPROM_OUTB(sd, temp ^ sd->sd_CK);
CLOCK_PULSE(sd, sd->sd_RDY);
} while ((SEEPROM_DATA_INB(sd) & sd->sd_DI) == 0);
reset_seeprom(sd);
}
send_seeprom_cmd(sd, ewds);
reset_seeprom(sd);
return (1);
}
int
ahc_verify_cksum(struct seeprom_config *sc)
{
int i;
int maxaddr;
uint32_t checksum;
uint16_t *scarray;
maxaddr = (sizeof(*sc)/2) - 1;
checksum = 0;
scarray = (uint16_t *)sc;
for (i = 0; i < maxaddr; i++)
checksum = checksum + scarray[i];
if (checksum == 0
|| (checksum & 0xFFFF) != sc->checksum) {
return (0);
} else {
return(1);
}
}
