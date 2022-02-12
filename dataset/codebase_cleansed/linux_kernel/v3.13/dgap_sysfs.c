static ssize_t dgap_driver_version_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", DG_PART);
}
static ssize_t dgap_driver_boards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", dgap_NumBoards);
}
static ssize_t dgap_driver_maxboards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", MAXBOARDS);
}
static ssize_t dgap_driver_pollcounter_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%ld\n", dgap_poll_counter);
}
static ssize_t dgap_driver_state_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", dgap_driver_state_text[dgap_driver_state]);
}
static ssize_t dgap_driver_debug_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%x\n", dgap_debug);
}
static ssize_t dgap_driver_debug_store(struct device_driver *ddp, const char *buf, size_t count)
{
sscanf(buf, "0x%x\n", &dgap_debug);
return count;
}
static ssize_t dgap_driver_rawreadok_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%x\n", dgap_rawreadok);
}
static ssize_t dgap_driver_rawreadok_store(struct device_driver *ddp, const char *buf, size_t count)
{
sscanf(buf, "0x%x\n", &dgap_rawreadok);
return count;
}
static ssize_t dgap_driver_pollrate_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%dms\n", dgap_poll_tick);
}
static ssize_t dgap_driver_pollrate_store(struct device_driver *ddp, const char *buf, size_t count)
{
sscanf(buf, "%d\n", &dgap_poll_tick);
return count;
}
void dgap_create_driver_sysfiles(struct pci_driver *dgap_driver)
{
int rc = 0;
struct device_driver *driverfs = &dgap_driver->driver;
rc |= driver_create_file(driverfs, &driver_attr_version);
rc |= driver_create_file(driverfs, &driver_attr_boards);
rc |= driver_create_file(driverfs, &driver_attr_maxboards);
rc |= driver_create_file(driverfs, &driver_attr_debug);
rc |= driver_create_file(driverfs, &driver_attr_rawreadok);
rc |= driver_create_file(driverfs, &driver_attr_pollrate);
rc |= driver_create_file(driverfs, &driver_attr_pollcounter);
rc |= driver_create_file(driverfs, &driver_attr_state);
if (rc) {
printk(KERN_ERR "DGAP: sysfs driver_create_file failed!\n");
}
}
void dgap_remove_driver_sysfiles(struct pci_driver *dgap_driver)
{
struct device_driver *driverfs = &dgap_driver->driver;
driver_remove_file(driverfs, &driver_attr_version);
driver_remove_file(driverfs, &driver_attr_boards);
driver_remove_file(driverfs, &driver_attr_maxboards);
driver_remove_file(driverfs, &driver_attr_debug);
driver_remove_file(driverfs, &driver_attr_rawreadok);
driver_remove_file(driverfs, &driver_attr_pollrate);
driver_remove_file(driverfs, &driver_attr_pollcounter);
driver_remove_file(driverfs, &driver_attr_state);
}
static ssize_t dgap_ports_baud_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %d\n", bd->channels[i]->ch_portnum, bd->channels[i]->ch_baud_info);
}
return count;
}
static ssize_t dgap_ports_msignals_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
if (bd->channels[i]->ch_open_count) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %s %s %s %s %s %s\n", bd->channels[i]->ch_portnum,
(bd->channels[i]->ch_mostat & UART_MCR_RTS) ? "RTS" : "",
(bd->channels[i]->ch_mistat & UART_MSR_CTS) ? "CTS" : "",
(bd->channels[i]->ch_mostat & UART_MCR_DTR) ? "DTR" : "",
(bd->channels[i]->ch_mistat & UART_MSR_DSR) ? "DSR" : "",
(bd->channels[i]->ch_mistat & UART_MSR_DCD) ? "DCD" : "",
(bd->channels[i]->ch_mistat & UART_MSR_RI) ? "RI" : "");
} else {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d\n", bd->channels[i]->ch_portnum);
}
}
return count;
}
static ssize_t dgap_ports_iflag_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_c_iflag);
}
return count;
}
static ssize_t dgap_ports_cflag_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_c_cflag);
}
return count;
}
static ssize_t dgap_ports_oflag_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_c_oflag);
}
return count;
}
static ssize_t dgap_ports_lflag_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_c_lflag);
}
return count;
}
static ssize_t dgap_ports_digi_flag_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_digi.digi_flags);
}
return count;
}
static ssize_t dgap_ports_rxcount_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_rxcount);
}
return count;
}
static ssize_t dgap_ports_txcount_show(struct device *p, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
int count = 0;
int i = 0;
DGAP_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum, bd->channels[i]->ch_txcount);
}
return count;
}
void dgap_create_ports_sysfiles(struct board_t *bd)
{
int rc = 0;
dev_set_drvdata(&bd->pdev->dev, bd);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_state);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_baud);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_msignals);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_iflag);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_cflag);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_oflag);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_lflag);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_digi_flag);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_rxcount);
rc |= device_create_file(&(bd->pdev->dev), &dev_attr_ports_txcount);
if (rc) {
printk(KERN_ERR "DGAP: sysfs device_create_file failed!\n");
}
}
void dgap_remove_ports_sysfiles(struct board_t *bd)
{
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_state);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_baud);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_msignals);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_iflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_cflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_oflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_lflag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_digi_flag);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_rxcount);
device_remove_file(&(bd->pdev->dev), &dev_attr_ports_txcount);
}
static ssize_t dgap_tty_state_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%s", un->un_open_count ? "Open" : "Closed");
}
static ssize_t dgap_tty_baud_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%d\n", ch->ch_baud_info);
}
static ssize_t dgap_tty_msignals_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
if (ch->ch_open_count) {
return snprintf(buf, PAGE_SIZE, "%s %s %s %s %s %s\n",
(ch->ch_mostat & UART_MCR_RTS) ? "RTS" : "",
(ch->ch_mistat & UART_MSR_CTS) ? "CTS" : "",
(ch->ch_mostat & UART_MCR_DTR) ? "DTR" : "",
(ch->ch_mistat & UART_MSR_DSR) ? "DSR" : "",
(ch->ch_mistat & UART_MSR_DCD) ? "DCD" : "",
(ch->ch_mistat & UART_MSR_RI) ? "RI" : "");
}
return 0;
}
static ssize_t dgap_tty_iflag_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_iflag);
}
static ssize_t dgap_tty_cflag_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_cflag);
}
static ssize_t dgap_tty_oflag_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_oflag);
}
static ssize_t dgap_tty_lflag_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_lflag);
}
static ssize_t dgap_tty_digi_flag_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_digi.digi_flags);
}
static ssize_t dgap_tty_rxcount_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_rxcount);
}
static ssize_t dgap_tty_txcount_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_txcount);
}
static ssize_t dgap_tty_name_show(struct device *d, struct device_attribute *attr, char *buf)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int cn;
int bn;
struct cnode *cptr = NULL;
int found = FALSE;
int ncount = 0;
int starto = 0;
int i = 0;
if (!d)
return (0);
un = dev_get_drvdata(d);
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
if (bd->state != BOARD_READY)
return (0);
bn = bd->boardnum;
cn = ch->ch_portnum;
for (cptr = bd->bd_config; cptr; cptr = cptr->next) {
if ((cptr->type == BNODE) &&
((cptr->u.board.type == APORT2_920P) || (cptr->u.board.type == APORT4_920P) ||
(cptr->u.board.type == APORT8_920P) || (cptr->u.board.type == PAPORT4) ||
(cptr->u.board.type == PAPORT8))) {
found = TRUE;
if (cptr->u.board.v_start)
starto = cptr->u.board.start;
else
starto = 1;
}
if (cptr->type == TNODE && found == TRUE) {
char *ptr1;
if (strstr(cptr->u.ttyname, "tty")) {
ptr1 = cptr->u.ttyname;
ptr1 += 3;
}
else {
ptr1 = cptr->u.ttyname;
}
for (i = 0; i < dgap_config_get_number_of_ports(bd); i++) {
if (cn == i) {
return snprintf(buf, PAGE_SIZE, "%s%s%02d\n",
(un->un_type == DGAP_PRINT) ? "pr" : "tty",
ptr1, i + starto);
}
}
}
if (cptr->type == CNODE) {
for (i = 0; i < cptr->u.conc.nport; i++) {
if (cn == (i + ncount)) {
return snprintf(buf, PAGE_SIZE, "%s%s%02d\n",
(un->un_type == DGAP_PRINT) ? "pr" : "tty",
cptr->u.conc.id,
i + (cptr->u.conc.v_start ? cptr->u.conc.start : 1));
}
}
ncount += cptr->u.conc.nport;
}
if (cptr->type == MNODE) {
for (i = 0; i < cptr->u.module.nport; i++) {
if (cn == (i + ncount)) {
return snprintf(buf, PAGE_SIZE, "%s%s%02d\n",
(un->un_type == DGAP_PRINT) ? "pr" : "tty",
cptr->u.module.id,
i + (cptr->u.module.v_start ? cptr->u.module.start : 1));
}
}
ncount += cptr->u.module.nport;
}
}
return snprintf(buf, PAGE_SIZE, "%s_dgap_%d_%d\n",
(un->un_type == DGAP_PRINT) ? "pr" : "tty", bn, cn);
}
void dgap_create_tty_sysfs(struct un_t *un, struct device *c)
{
int ret;
ret = sysfs_create_group(&c->kobj, &dgap_tty_attribute_group);
if (ret) {
printk(KERN_ERR "dgap: failed to create sysfs tty device attributes.\n");
sysfs_remove_group(&c->kobj, &dgap_tty_attribute_group);
return;
}
dev_set_drvdata(c, un);
}
void dgap_remove_tty_sysfs(struct device *c)
{
sysfs_remove_group(&c->kobj, &dgap_tty_attribute_group);
}
