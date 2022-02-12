int proc_dolasatstring(struct ctl_table *table, int write,
void *buffer, size_t *lenp, loff_t *ppos)
{
int r;
r = proc_dostring(table, write, buffer, lenp, ppos);
if ((!write) || r)
return r;
lasat_write_eeprom_info();
return 0;
}
int proc_dolasatint(struct ctl_table *table, int write,
void *buffer, size_t *lenp, loff_t *ppos)
{
int r;
r = proc_dointvec(table, write, buffer, lenp, ppos);
if ((!write) || r)
return r;
lasat_write_eeprom_info();
return 0;
}
int proc_dolasatrtc(struct ctl_table *table, int write,
void *buffer, size_t *lenp, loff_t *ppos)
{
struct timespec ts;
int r;
if (!write) {
read_persistent_clock(&ts);
rtctmp = ts.tv_sec;
if (rtctmp < 0)
rtctmp = 0;
}
r = proc_dointvec(table, write, buffer, lenp, ppos);
if (r)
return r;
if (write)
rtc_mips_set_mmss(rtctmp);
return 0;
}
int proc_lasat_ip(struct ctl_table *table, int write,
void *buffer, size_t *lenp, loff_t *ppos)
{
unsigned int ip;
char *p, c;
int len;
char ipbuf[32];
if (!table->data || !table->maxlen || !*lenp ||
(*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
len = 0;
p = buffer;
while (len < *lenp) {
if (get_user(c, p++))
return -EFAULT;
if (c == 0 || c == '\n')
break;
len++;
}
if (len >= sizeof(ipbuf)-1)
len = sizeof(ipbuf) - 1;
if (copy_from_user(ipbuf, buffer, len))
return -EFAULT;
ipbuf[len] = 0;
*ppos += *lenp;
ip = in_aton(ipbuf);
*(unsigned int *)(table->data) = ip;
lasat_write_eeprom_info();
} else {
ip = *(unsigned int *)(table->data);
sprintf(ipbuf, "%d.%d.%d.%d",
(ip) & 0xff,
(ip >> 8) & 0xff,
(ip >> 16) & 0xff,
(ip >> 24) & 0xff);
len = strlen(ipbuf);
if (len > *lenp)
len = *lenp;
if (len)
if (copy_to_user(buffer, ipbuf, len))
return -EFAULT;
if (len < *lenp) {
if (put_user('\n', ((char *) buffer) + len))
return -EFAULT;
len++;
}
*lenp = len;
*ppos += len;
}
return 0;
}
int proc_lasat_prid(struct ctl_table *table, int write,
void *buffer, size_t *lenp, loff_t *ppos)
{
int r;
r = proc_dointvec(table, write, buffer, lenp, ppos);
if (r < 0)
return r;
if (write) {
lasat_board_info.li_eeprom_info.prid =
lasat_board_info.li_prid;
lasat_write_eeprom_info();
lasat_init_board_info();
}
return 0;
}
static int __init lasat_register_sysctl(void)
{
struct ctl_table_header *lasat_table_header;
lasat_table_header =
register_sysctl_table(lasat_root_table);
if (!lasat_table_header) {
printk(KERN_ERR "Unable to register LASAT sysctl\n");
return -ENOMEM;
}
return 0;
}
