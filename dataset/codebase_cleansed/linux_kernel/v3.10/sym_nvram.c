void sym_nvram_setup_host(struct Scsi_Host *shost, struct sym_hcb *np, struct sym_nvram *nvram)
{
switch (nvram->type) {
case SYM_SYMBIOS_NVRAM:
if (!(nvram->data.Symbios.flags & SYMBIOS_PARITY_ENABLE))
np->rv_scntl0 &= ~0x0a;
np->myaddr = nvram->data.Symbios.host_id & 0x0f;
if (nvram->data.Symbios.flags & SYMBIOS_VERBOSE_MSGS)
np->verbose += 1;
if (nvram->data.Symbios.flags1 & SYMBIOS_SCAN_HI_LO)
shost->reverse_ordering = 1;
if (nvram->data.Symbios.flags2 & SYMBIOS_AVOID_BUS_RESET)
np->usrflags |= SYM_AVOID_BUS_RESET;
break;
case SYM_TEKRAM_NVRAM:
np->myaddr = nvram->data.Tekram.host_id & 0x0f;
break;
#ifdef CONFIG_PARISC
case SYM_PARISC_PDC:
if (nvram->data.parisc.host_id != -1)
np->myaddr = nvram->data.parisc.host_id;
if (nvram->data.parisc.factor != -1)
np->minsync = nvram->data.parisc.factor;
if (nvram->data.parisc.width != -1)
np->maxwide = nvram->data.parisc.width;
switch (nvram->data.parisc.mode) {
case 0: np->scsi_mode = SMODE_SE; break;
case 1: np->scsi_mode = SMODE_HVD; break;
case 2: np->scsi_mode = SMODE_LVD; break;
default: break;
}
#endif
default:
break;
}
}
static void
sym_Symbios_setup_target(struct sym_tcb *tp, int target, Symbios_nvram *nvram)
{
Symbios_target *tn = &nvram->target[target];
if (!(tn->flags & SYMBIOS_QUEUE_TAGS_ENABLED))
tp->usrtags = 0;
if (!(tn->flags & SYMBIOS_DISCONNECT_ENABLE))
tp->usrflags &= ~SYM_DISC_ENABLED;
if (!(tn->flags & SYMBIOS_SCAN_AT_BOOT_TIME))
tp->usrflags |= SYM_SCAN_BOOT_DISABLED;
if (!(tn->flags & SYMBIOS_SCAN_LUNS))
tp->usrflags |= SYM_SCAN_LUNS_DISABLED;
tp->usr_period = (tn->sync_period + 3) / 4;
tp->usr_width = (tn->bus_width == 0x8) ? 0 : 1;
}
static void
sym_Tekram_setup_target(struct sym_tcb *tp, int target, Tekram_nvram *nvram)
{
struct Tekram_target *tn = &nvram->target[target];
if (tn->flags & TEKRAM_TAGGED_COMMANDS) {
tp->usrtags = 2 << nvram->max_tags_index;
}
if (tn->flags & TEKRAM_DISCONNECT_ENABLE)
tp->usrflags |= SYM_DISC_ENABLED;
if (tn->flags & TEKRAM_SYNC_NEGO)
tp->usr_period = Tekram_sync[tn->sync_index & 0xf];
tp->usr_width = (tn->flags & TEKRAM_WIDE_NEGO) ? 1 : 0;
}
void sym_nvram_setup_target(struct sym_tcb *tp, int target, struct sym_nvram *nvp)
{
switch (nvp->type) {
case SYM_SYMBIOS_NVRAM:
sym_Symbios_setup_target(tp, target, &nvp->data.Symbios);
break;
case SYM_TEKRAM_NVRAM:
sym_Tekram_setup_target(tp, target, &nvp->data.Tekram);
break;
default:
break;
}
}
static void sym_display_Symbios_nvram(struct sym_device *np, Symbios_nvram *nvram)
{
int i;
printf("%s: HOST ID=%d%s%s%s%s%s%s\n",
sym_name(np), nvram->host_id & 0x0f,
(nvram->flags & SYMBIOS_SCAM_ENABLE) ? " SCAM" :"",
(nvram->flags & SYMBIOS_PARITY_ENABLE) ? " PARITY" :"",
(nvram->flags & SYMBIOS_VERBOSE_MSGS) ? " VERBOSE" :"",
(nvram->flags & SYMBIOS_CHS_MAPPING) ? " CHS_ALT" :"",
(nvram->flags2 & SYMBIOS_AVOID_BUS_RESET)?" NO_RESET" :"",
(nvram->flags1 & SYMBIOS_SCAN_HI_LO) ? " HI_LO" :"");
for (i = 0 ; i < 15 ; i++) {
struct Symbios_target *tn = &nvram->target[i];
printf("%s-%d:%s%s%s%s WIDTH=%d SYNC=%d TMO=%d\n",
sym_name(np), i,
(tn->flags & SYMBIOS_DISCONNECT_ENABLE) ? " DISC" : "",
(tn->flags & SYMBIOS_SCAN_AT_BOOT_TIME) ? " SCAN_BOOT" : "",
(tn->flags & SYMBIOS_SCAN_LUNS) ? " SCAN_LUNS" : "",
(tn->flags & SYMBIOS_QUEUE_TAGS_ENABLED)? " TCQ" : "",
tn->bus_width,
tn->sync_period / 4,
tn->timeout);
}
}
static void sym_display_Tekram_nvram(struct sym_device *np, Tekram_nvram *nvram)
{
int i, tags, boot_delay;
char *rem;
tags = 2 << nvram->max_tags_index;
boot_delay = 0;
if (nvram->boot_delay_index < 6)
boot_delay = Tekram_boot_delay[nvram->boot_delay_index];
switch ((nvram->flags & TEKRAM_REMOVABLE_FLAGS) >> 6) {
default:
case 0: rem = ""; break;
case 1: rem = " REMOVABLE=boot device"; break;
case 2: rem = " REMOVABLE=all"; break;
}
printf("%s: HOST ID=%d%s%s%s%s%s%s%s%s%s BOOT DELAY=%d tags=%d\n",
sym_name(np), nvram->host_id & 0x0f,
(nvram->flags1 & SYMBIOS_SCAM_ENABLE) ? " SCAM" :"",
(nvram->flags & TEKRAM_MORE_THAN_2_DRIVES) ? " >2DRIVES":"",
(nvram->flags & TEKRAM_DRIVES_SUP_1GB) ? " >1GB" :"",
(nvram->flags & TEKRAM_RESET_ON_POWER_ON) ? " RESET" :"",
(nvram->flags & TEKRAM_ACTIVE_NEGATION) ? " ACT_NEG" :"",
(nvram->flags & TEKRAM_IMMEDIATE_SEEK) ? " IMM_SEEK" :"",
(nvram->flags & TEKRAM_SCAN_LUNS) ? " SCAN_LUNS" :"",
(nvram->flags1 & TEKRAM_F2_F6_ENABLED) ? " F2_F6" :"",
rem, boot_delay, tags);
for (i = 0; i <= 15; i++) {
int sync, j;
struct Tekram_target *tn = &nvram->target[i];
j = tn->sync_index & 0xf;
sync = Tekram_sync[j];
printf("%s-%d:%s%s%s%s%s%s PERIOD=%d\n",
sym_name(np), i,
(tn->flags & TEKRAM_PARITY_CHECK) ? " PARITY" : "",
(tn->flags & TEKRAM_SYNC_NEGO) ? " SYNC" : "",
(tn->flags & TEKRAM_DISCONNECT_ENABLE) ? " DISC" : "",
(tn->flags & TEKRAM_START_CMD) ? " START" : "",
(tn->flags & TEKRAM_TAGGED_COMMANDS) ? " TCQ" : "",
(tn->flags & TEKRAM_WIDE_NEGO) ? " WIDE" : "",
sync);
}
}
static void sym_display_Symbios_nvram(struct sym_device *np, Symbios_nvram *nvram) { (void)np; (void)nvram; }
static void sym_display_Tekram_nvram(struct sym_device *np, Tekram_nvram *nvram) { (void)np; (void)nvram; }
static void S24C16_set_bit(struct sym_device *np, u_char write_bit, u_char *gpreg,
int bit_mode)
{
udelay(5);
switch (bit_mode) {
case SET_BIT:
*gpreg |= write_bit;
break;
case CLR_BIT:
*gpreg &= 0xfe;
break;
case SET_CLK:
*gpreg |= 0x02;
break;
case CLR_CLK:
*gpreg &= 0xfd;
break;
}
OUTB(np, nc_gpreg, *gpreg);
INB(np, nc_mbox1);
udelay(5);
}
static void S24C16_start(struct sym_device *np, u_char *gpreg)
{
S24C16_set_bit(np, 1, gpreg, SET_BIT);
S24C16_set_bit(np, 0, gpreg, SET_CLK);
S24C16_set_bit(np, 0, gpreg, CLR_BIT);
S24C16_set_bit(np, 0, gpreg, CLR_CLK);
}
static void S24C16_stop(struct sym_device *np, u_char *gpreg)
{
S24C16_set_bit(np, 0, gpreg, SET_CLK);
S24C16_set_bit(np, 1, gpreg, SET_BIT);
}
static void S24C16_do_bit(struct sym_device *np, u_char *read_bit, u_char write_bit,
u_char *gpreg)
{
S24C16_set_bit(np, write_bit, gpreg, SET_BIT);
S24C16_set_bit(np, 0, gpreg, SET_CLK);
if (read_bit)
*read_bit = INB(np, nc_gpreg);
S24C16_set_bit(np, 0, gpreg, CLR_CLK);
S24C16_set_bit(np, 0, gpreg, CLR_BIT);
}
static void S24C16_write_ack(struct sym_device *np, u_char write_bit, u_char *gpreg,
u_char *gpcntl)
{
OUTB(np, nc_gpcntl, *gpcntl & 0xfe);
S24C16_do_bit(np, NULL, write_bit, gpreg);
OUTB(np, nc_gpcntl, *gpcntl);
}
static void S24C16_read_ack(struct sym_device *np, u_char *read_bit, u_char *gpreg,
u_char *gpcntl)
{
OUTB(np, nc_gpcntl, *gpcntl | 0x01);
S24C16_do_bit(np, read_bit, 1, gpreg);
OUTB(np, nc_gpcntl, *gpcntl);
}
static void S24C16_write_byte(struct sym_device *np, u_char *ack_data, u_char write_data,
u_char *gpreg, u_char *gpcntl)
{
int x;
for (x = 0; x < 8; x++)
S24C16_do_bit(np, NULL, (write_data >> (7 - x)) & 0x01, gpreg);
S24C16_read_ack(np, ack_data, gpreg, gpcntl);
}
static void S24C16_read_byte(struct sym_device *np, u_char *read_data, u_char ack_data,
u_char *gpreg, u_char *gpcntl)
{
int x;
u_char read_bit;
*read_data = 0;
for (x = 0; x < 8; x++) {
S24C16_do_bit(np, &read_bit, 1, gpreg);
*read_data |= ((read_bit & 0x01) << (7 - x));
}
S24C16_write_ack(np, ack_data, gpreg, gpcntl);
}
static int sym_write_S24C16_nvram(struct sym_device *np, int offset,
u_char *data, int len)
{
u_char gpcntl, gpreg;
u_char old_gpcntl, old_gpreg;
u_char ack_data;
int x;
old_gpreg = INB(np, nc_gpreg);
old_gpcntl = INB(np, nc_gpcntl);
gpcntl = old_gpcntl & 0x1c;
OUTB(np, nc_gpreg, old_gpreg);
OUTB(np, nc_gpcntl, gpcntl);
gpreg = old_gpreg;
S24C16_set_bit(np, 0, &gpreg, CLR_CLK);
S24C16_set_bit(np, 0, &gpreg, CLR_BIT);
S24C16_stop(np, &gpreg);
for (x = 0; x < len ; x += 16) {
do {
S24C16_start(np, &gpreg);
S24C16_write_byte(np, &ack_data,
0xa0 | (((offset+x) >> 7) & 0x0e),
&gpreg, &gpcntl);
} while (ack_data & 0x01);
S24C16_write_byte(np, &ack_data, (offset+x) & 0xff,
&gpreg, &gpcntl);
for (y = 0; y < 16; y++)
S24C16_write_byte(np, &ack_data, data[x+y],
&gpreg, &gpcntl);
S24C16_stop(np, &gpreg);
}
OUTB(np, nc_gpcntl, old_gpcntl);
OUTB(np, nc_gpreg, old_gpreg);
return 0;
}
static int sym_read_S24C16_nvram(struct sym_device *np, int offset, u_char *data, int len)
{
u_char gpcntl, gpreg;
u_char old_gpcntl, old_gpreg;
u_char ack_data;
int retv = 1;
int x;
old_gpreg = INB(np, nc_gpreg);
old_gpcntl = INB(np, nc_gpcntl);
gpcntl = old_gpcntl & 0x1c;
OUTB(np, nc_gpreg, old_gpreg);
OUTB(np, nc_gpcntl, gpcntl);
gpreg = old_gpreg;
S24C16_set_bit(np, 0, &gpreg, CLR_CLK);
S24C16_set_bit(np, 0, &gpreg, CLR_BIT);
S24C16_stop(np, &gpreg);
S24C16_start(np, &gpreg);
S24C16_write_byte(np, &ack_data,
0xa0 | ((offset >> 7) & 0x0e), &gpreg, &gpcntl);
if (ack_data & 0x01)
goto out;
S24C16_write_byte(np, &ack_data,
offset & 0xff, &gpreg, &gpcntl);
if (ack_data & 0x01)
goto out;
S24C16_start(np, &gpreg);
S24C16_write_byte(np, &ack_data,
0xa1 | ((offset >> 7) & 0x0e), &gpreg, &gpcntl);
if (ack_data & 0x01)
goto out;
gpcntl |= 0x01;
OUTB(np, nc_gpcntl, gpcntl);
for (x = 0; x < len; x++)
S24C16_read_byte(np, &data[x], (x == (len-1)), &gpreg, &gpcntl);
gpcntl &= 0xfe;
OUTB(np, nc_gpcntl, gpcntl);
S24C16_stop(np, &gpreg);
retv = 0;
out:
OUTB(np, nc_gpcntl, old_gpcntl);
OUTB(np, nc_gpreg, old_gpreg);
return retv;
}
static int sym_read_Symbios_nvram(struct sym_device *np, Symbios_nvram *nvram)
{
static u_char Symbios_trailer[6] = {0xfe, 0xfe, 0, 0, 0, 0};
u_char *data = (u_char *) nvram;
int len = sizeof(*nvram);
u_short csum;
int x;
if (sym_read_S24C16_nvram (np, SYMBIOS_NVRAM_ADDRESS, data, len))
return 1;
if (nvram->type != 0 ||
memcmp(nvram->trailer, Symbios_trailer, 6) ||
nvram->byte_count != len - 12)
return 1;
for (x = 6, csum = 0; x < len - 6; x++)
csum += data[x];
if (csum != nvram->checksum)
return 1;
return 0;
}
static void T93C46_Clk(struct sym_device *np, u_char *gpreg)
{
OUTB(np, nc_gpreg, *gpreg | 0x04);
INB(np, nc_mbox1);
udelay(2);
OUTB(np, nc_gpreg, *gpreg);
}
static void T93C46_Read_Bit(struct sym_device *np, u_char *read_bit, u_char *gpreg)
{
udelay(2);
T93C46_Clk(np, gpreg);
*read_bit = INB(np, nc_gpreg);
}
static void T93C46_Write_Bit(struct sym_device *np, u_char write_bit, u_char *gpreg)
{
if (write_bit & 0x01)
*gpreg |= 0x02;
else
*gpreg &= 0xfd;
*gpreg |= 0x10;
OUTB(np, nc_gpreg, *gpreg);
INB(np, nc_mbox1);
udelay(2);
T93C46_Clk(np, gpreg);
}
static void T93C46_Stop(struct sym_device *np, u_char *gpreg)
{
*gpreg &= 0xef;
OUTB(np, nc_gpreg, *gpreg);
INB(np, nc_mbox1);
udelay(2);
T93C46_Clk(np, gpreg);
}
static void T93C46_Send_Command(struct sym_device *np, u_short write_data,
u_char *read_bit, u_char *gpreg)
{
int x;
for (x = 0; x < 9; x++)
T93C46_Write_Bit(np, (u_char) (write_data >> (8 - x)), gpreg);
*read_bit = INB(np, nc_gpreg);
}
static void T93C46_Read_Word(struct sym_device *np,
unsigned short *nvram_data, unsigned char *gpreg)
{
int x;
u_char read_bit;
*nvram_data = 0;
for (x = 0; x < 16; x++) {
T93C46_Read_Bit(np, &read_bit, gpreg);
if (read_bit & 0x01)
*nvram_data |= (0x01 << (15 - x));
else
*nvram_data &= ~(0x01 << (15 - x));
}
}
static int T93C46_Read_Data(struct sym_device *np, unsigned short *data,
int len, unsigned char *gpreg)
{
int x;
for (x = 0; x < len; x++) {
unsigned char read_bit;
T93C46_Send_Command(np, 0x180 | x, &read_bit, gpreg);
if (read_bit & 0x01)
return 1;
T93C46_Read_Word(np, &data[x], gpreg);
T93C46_Stop(np, gpreg);
}
return 0;
}
static int sym_read_T93C46_nvram(struct sym_device *np, Tekram_nvram *nvram)
{
u_char gpcntl, gpreg;
u_char old_gpcntl, old_gpreg;
int retv = 1;
old_gpreg = INB(np, nc_gpreg);
old_gpcntl = INB(np, nc_gpcntl);
gpreg = old_gpreg & 0xe9;
OUTB(np, nc_gpreg, gpreg);
gpcntl = (old_gpcntl & 0xe9) | 0x09;
OUTB(np, nc_gpcntl, gpcntl);
retv = T93C46_Read_Data(np, (u_short *) nvram,
sizeof(*nvram) / sizeof(short), &gpreg);
OUTB(np, nc_gpcntl, old_gpcntl);
OUTB(np, nc_gpreg, old_gpreg);
return retv;
}
static int sym_read_Tekram_nvram (struct sym_device *np, Tekram_nvram *nvram)
{
u_char *data = (u_char *) nvram;
int len = sizeof(*nvram);
u_short csum;
int x;
switch (np->pdev->device) {
case PCI_DEVICE_ID_NCR_53C885:
case PCI_DEVICE_ID_NCR_53C895:
case PCI_DEVICE_ID_NCR_53C896:
x = sym_read_S24C16_nvram(np, TEKRAM_24C16_NVRAM_ADDRESS,
data, len);
break;
case PCI_DEVICE_ID_NCR_53C875:
x = sym_read_S24C16_nvram(np, TEKRAM_24C16_NVRAM_ADDRESS,
data, len);
if (!x)
break;
default:
x = sym_read_T93C46_nvram(np, nvram);
break;
}
if (x)
return 1;
for (x = 0, csum = 0; x < len - 1; x += 2)
csum += data[x] + (data[x+1] << 8);
if (csum != 0x1234)
return 1;
return 0;
}
static int sym_read_parisc_pdc(struct sym_device *np, struct pdc_initiator *pdc)
{
struct hardware_path hwpath;
get_pci_node_path(np->pdev, &hwpath);
if (!pdc_get_initiator(&hwpath, pdc))
return 0;
return SYM_PARISC_PDC;
}
static inline int sym_read_parisc_pdc(struct sym_device *np,
struct pdc_initiator *x)
{
return 0;
}
int sym_read_nvram(struct sym_device *np, struct sym_nvram *nvp)
{
if (!sym_read_Symbios_nvram(np, &nvp->data.Symbios)) {
nvp->type = SYM_SYMBIOS_NVRAM;
sym_display_Symbios_nvram(np, &nvp->data.Symbios);
} else if (!sym_read_Tekram_nvram(np, &nvp->data.Tekram)) {
nvp->type = SYM_TEKRAM_NVRAM;
sym_display_Tekram_nvram(np, &nvp->data.Tekram);
} else {
nvp->type = sym_read_parisc_pdc(np, &nvp->data.parisc);
}
return nvp->type;
}
char *sym_nvram_type(struct sym_nvram *nvp)
{
switch (nvp->type) {
case SYM_SYMBIOS_NVRAM:
return "Symbios NVRAM";
case SYM_TEKRAM_NVRAM:
return "Tekram NVRAM";
case SYM_PARISC_PDC:
return "PA-RISC Firmware";
default:
return "No NVRAM";
}
}
