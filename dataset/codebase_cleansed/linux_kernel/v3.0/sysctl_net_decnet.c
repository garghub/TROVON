static void strip_it(char *str)
{
for(;;) {
switch(*str) {
case ' ':
case '\n':
case '\r':
case ':':
*str = 0;
case 0:
return;
}
str++;
}
}
static int parse_addr(__le16 *addr, char *str)
{
__u16 area, node;
while(*str && !ISNUM(*str)) str++;
if (*str == 0)
return -1;
area = (*str++ - '0');
if (ISNUM(*str)) {
area *= 10;
area += (*str++ - '0');
}
if (*str++ != '.')
return -1;
if (!ISNUM(*str))
return -1;
node = *str++ - '0';
if (ISNUM(*str)) {
node *= 10;
node += (*str++ - '0');
}
if (ISNUM(*str)) {
node *= 10;
node += (*str++ - '0');
}
if (ISNUM(*str)) {
node *= 10;
node += (*str++ - '0');
}
if ((node > 1023) || (area > 63))
return -1;
if (INVALID_END_CHAR(*str))
return -1;
*addr = cpu_to_le16((area << 10) | node);
return 0;
}
static int dn_node_address_handler(ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
char addr[DN_ASCBUF_LEN];
size_t len;
__le16 dnaddr;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
len = (*lenp < DN_ASCBUF_LEN) ? *lenp : (DN_ASCBUF_LEN-1);
if (copy_from_user(addr, buffer, len))
return -EFAULT;
addr[len] = 0;
strip_it(addr);
if (parse_addr(&dnaddr, addr))
return -EINVAL;
dn_dev_devices_off();
decnet_address = dnaddr;
dn_dev_devices_on();
*ppos += len;
return 0;
}
dn_addr2asc(le16_to_cpu(decnet_address), addr);
len = strlen(addr);
addr[len++] = '\n';
if (len > *lenp) len = *lenp;
if (copy_to_user(buffer, addr, len))
return -EFAULT;
*lenp = len;
*ppos += len;
return 0;
}
static int dn_def_dev_handler(ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
size_t len;
struct net_device *dev;
char devname[17];
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
if (*lenp > 16)
return -E2BIG;
if (copy_from_user(devname, buffer, *lenp))
return -EFAULT;
devname[*lenp] = 0;
strip_it(devname);
dev = dev_get_by_name(&init_net, devname);
if (dev == NULL)
return -ENODEV;
if (dev->dn_ptr == NULL) {
dev_put(dev);
return -ENODEV;
}
if (dn_dev_set_default(dev, 1)) {
dev_put(dev);
return -ENODEV;
}
*ppos += *lenp;
return 0;
}
dev = dn_dev_get_default();
if (dev == NULL) {
*lenp = 0;
return 0;
}
strcpy(devname, dev->name);
dev_put(dev);
len = strlen(devname);
devname[len++] = '\n';
if (len > *lenp) len = *lenp;
if (copy_to_user(buffer, devname, len))
return -EFAULT;
*lenp = len;
*ppos += len;
return 0;
}
void dn_register_sysctl(void)
{
dn_table_header = register_sysctl_paths(dn_path, dn_table);
}
void dn_unregister_sysctl(void)
{
unregister_sysctl_table(dn_table_header);
}
void dn_unregister_sysctl(void)
{
}
void dn_register_sysctl(void)
{
}
