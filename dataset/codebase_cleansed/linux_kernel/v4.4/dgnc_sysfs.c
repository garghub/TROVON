static ssize_t dgnc_driver_version_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", DG_PART);
}
static ssize_t dgnc_driver_boards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", dgnc_NumBoards);
}
static ssize_t dgnc_driver_maxboards_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", MAXBOARDS);
}
static ssize_t dgnc_driver_pollrate_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%dms\n", dgnc_poll_tick);
}
static ssize_t dgnc_driver_pollrate_store(struct device_driver *ddp,
const char *buf, size_t count)
{
unsigned long flags;
int tick;
int ret;
ret = sscanf(buf, "%d\n", &tick);
if (ret != 1)
return -EINVAL;
spin_lock_irqsave(&dgnc_poll_lock, flags);
dgnc_poll_tick = tick;
spin_unlock_irqrestore(&dgnc_poll_lock, flags);
return count;
}
void dgnc_create_driver_sysfiles(struct pci_driver *dgnc_driver)
{
int rc = 0;
struct device_driver *driverfs = &dgnc_driver->driver;
rc |= driver_create_file(driverfs, &driver_attr_version);
rc |= driver_create_file(driverfs, &driver_attr_boards);
rc |= driver_create_file(driverfs, &driver_attr_maxboards);
rc |= driver_create_file(driverfs, &driver_attr_pollrate);
if (rc)
pr_err("DGNC: sysfs driver_create_file failed!\n");
}
void dgnc_remove_driver_sysfiles(struct pci_driver *dgnc_driver)
{
struct device_driver *driverfs = &dgnc_driver->driver;
driver_remove_file(driverfs, &driver_attr_version);
driver_remove_file(driverfs, &driver_attr_boards);
driver_remove_file(driverfs, &driver_attr_maxboards);
driver_remove_file(driverfs, &driver_attr_pollrate);
}
static ssize_t dgnc_vpd_show(struct device *p, struct device_attribute *attr,
char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
count += sprintf(buf + count,
"\n 0 1 2 3 4 5 6 7 8 9 A B C D E F");
for (i = 0; i < 0x40 * 2; i++) {
if (!(i % 16))
count += sprintf(buf + count, "\n%04X ", i * 2);
count += sprintf(buf + count, "%02X ", bd->vpd[i]);
}
count += sprintf(buf + count, "\n");
return count;
}
static ssize_t dgnc_serial_number_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
DGNC_VERIFY_BOARD(p, bd);
if (bd->serial_num[0] == '\0')
count += sprintf(buf + count, "<UNKNOWN>\n");
else
count += sprintf(buf + count, "%s\n", bd->serial_num);
return count;
}
static ssize_t dgnc_ports_state_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %s\n", bd->channels[i]->ch_portnum,
bd->channels[i]->ch_open_count ? "Open" : "Closed");
}
return count;
}
static ssize_t dgnc_ports_baud_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %d\n", bd->channels[i]->ch_portnum,
bd->channels[i]->ch_old_baud);
}
return count;
}
static ssize_t dgnc_ports_msignals_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
if (bd->channels[i]->ch_open_count) {
count += snprintf(buf + count, PAGE_SIZE - count,
"%d %s %s %s %s %s %s\n",
bd->channels[i]->ch_portnum,
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
static ssize_t dgnc_ports_iflag_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_iflag);
}
return count;
}
static ssize_t dgnc_ports_cflag_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_cflag);
}
return count;
}
static ssize_t dgnc_ports_oflag_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_oflag);
}
return count;
}
static ssize_t dgnc_ports_lflag_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_c_lflag);
}
return count;
}
static ssize_t dgnc_ports_digi_flag_show(struct device *p,
struct device_attribute *attr,
char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %x\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_digi.digi_flags);
}
return count;
}
static ssize_t dgnc_ports_rxcount_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_rxcount);
}
return count;
}
static ssize_t dgnc_ports_txcount_show(struct device *p,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
int count = 0;
int i = 0;
DGNC_VERIFY_BOARD(p, bd);
for (i = 0; i < bd->nasync; i++) {
count += snprintf(buf + count, PAGE_SIZE - count, "%d %ld\n",
bd->channels[i]->ch_portnum,
bd->channels[i]->ch_txcount);
}
return count;
}
void dgnc_create_ports_sysfiles(struct dgnc_board *bd)
{
int rc = 0;
dev_set_drvdata(&bd->pdev->dev, bd);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_state);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_baud);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_msignals);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_iflag);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_cflag);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_oflag);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_lflag);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_digi_flag);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_rxcount);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_ports_txcount);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_vpd);
rc |= device_create_file(&bd->pdev->dev, &dev_attr_serial_number);
if (rc)
dev_err(&bd->pdev->dev, "dgnc: sysfs device_create_file failed!\n");
}
void dgnc_remove_ports_sysfiles(struct dgnc_board *bd)
{
device_remove_file(&bd->pdev->dev, &dev_attr_ports_state);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_baud);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_msignals);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_iflag);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_cflag);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_oflag);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_lflag);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_digi_flag);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_rxcount);
device_remove_file(&bd->pdev->dev, &dev_attr_ports_txcount);
device_remove_file(&bd->pdev->dev, &dev_attr_vpd);
device_remove_file(&bd->pdev->dev, &dev_attr_serial_number);
}
static ssize_t dgnc_tty_state_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%s",
un->un_open_count ? "Open" : "Closed");
}
static ssize_t dgnc_tty_baud_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%d\n", ch->ch_old_baud);
}
static ssize_t dgnc_tty_msignals_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
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
static ssize_t dgnc_tty_iflag_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_iflag);
}
static ssize_t dgnc_tty_cflag_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_cflag);
}
static ssize_t dgnc_tty_oflag_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_oflag);
}
static ssize_t dgnc_tty_lflag_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_c_lflag);
}
static ssize_t dgnc_tty_digi_flag_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%x\n", ch->ch_digi.digi_flags);
}
static ssize_t dgnc_tty_rxcount_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_rxcount);
}
static ssize_t dgnc_tty_txcount_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%ld\n", ch->ch_txcount);
}
static ssize_t dgnc_tty_name_show(struct device *d,
struct device_attribute *attr, char *buf)
{
struct dgnc_board *bd;
struct channel_t *ch;
struct un_t *un;
if (!d)
return 0;
un = dev_get_drvdata(d);
if (!un || un->magic != DGNC_UNIT_MAGIC)
return 0;
ch = un->un_ch;
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return 0;
bd = ch->ch_bd;
if (!bd || bd->magic != DGNC_BOARD_MAGIC)
return 0;
if (bd->state != BOARD_READY)
return 0;
return snprintf(buf, PAGE_SIZE, "%sn%d%c\n",
(un->un_type == DGNC_PRINT) ? "pr" : "tty",
bd->boardnum + 1, 'a' + ch->ch_portnum);
}
void dgnc_create_tty_sysfs(struct un_t *un, struct device *c)
{
int ret;
ret = sysfs_create_group(&c->kobj, &dgnc_tty_attribute_group);
if (ret) {
dev_err(c, "dgnc: failed to create sysfs tty device attributes.\n");
sysfs_remove_group(&c->kobj, &dgnc_tty_attribute_group);
return;
}
dev_set_drvdata(c, un);
}
void dgnc_remove_tty_sysfs(struct device *c)
{
sysfs_remove_group(&c->kobj, &dgnc_tty_attribute_group);
}
