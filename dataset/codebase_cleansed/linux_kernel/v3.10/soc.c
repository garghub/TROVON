int soc_get_exception(void)
{
if (!soc_ops.get_exception)
return -1;
return soc_ops.get_exception();
}
void soc_assert_event(unsigned int evt)
{
if (soc_ops.assert_event)
soc_ops.assert_event(evt);
}
static int __init get_mac_addr_from_cmdline(char *str)
{
int count, i, val;
for (count = 0; count < 6 && *str; count++, str += 3) {
if (!isxdigit(str[0]) || !isxdigit(str[1]))
return 0;
if (str[2] != ((count < 5) ? ':' : '\0'))
return 0;
for (i = 0, val = 0; i < 2; i++) {
val = val << 4;
val |= isdigit(str[i]) ?
str[i] - '0' : toupper(str[i]) - 'A' + 10;
}
cmdline_mac[count] = val;
}
return 1;
}
int soc_mac_addr(unsigned int index, u8 *addr)
{
int i, have_dt_mac = 0, have_cmdline_mac = 0, have_fuse_mac = 0;
for (i = 0; i < 6; i++) {
if (cmdline_mac[i])
have_cmdline_mac = 1;
if (c6x_fuse_mac[i])
have_fuse_mac = 1;
if (addr[i])
have_dt_mac = 1;
}
if (have_cmdline_mac)
memcpy(addr, cmdline_mac, 6);
else if (!have_dt_mac) {
if (have_fuse_mac)
memcpy(addr, c6x_fuse_mac, 6);
else
eth_random_addr(addr);
}
addr[5] += index * c6x_num_cores;
return 1;
}
