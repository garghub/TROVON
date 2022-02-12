int main(int argc, char *argv[])
{
char **spp, *master_ifname, *slave_ifname;
int c, i, rv;
int res = 0;
int exclusive = 0;
while ((c = getopt_long(argc, argv, "acdfhuvV", longopts, 0)) != EOF) {
switch (c) {
case 'a': opt_a++; exclusive++; break;
case 'c': opt_c++; exclusive++; break;
case 'd': opt_d++; exclusive++; break;
case 'f': opt_f++; exclusive++; break;
case 'h': opt_h++; exclusive++; break;
case 'u': opt_u++; exclusive++; break;
case 'v': opt_v++; break;
case 'V': opt_V++; exclusive++; break;
case '?':
fprintf(stderr, "%s", usage_msg);
res = 2;
goto out;
}
}
if (exclusive > 1) {
fprintf(stderr, "%s", usage_msg);
res = 2;
goto out;
}
if (opt_v || opt_V) {
printf("%s", version);
if (opt_V) {
res = 0;
goto out;
}
}
if (opt_u) {
printf("%s", usage_msg);
res = 0;
goto out;
}
if (opt_h) {
printf("%s", usage_msg);
printf("%s", help_msg);
res = 0;
goto out;
}
if ((skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
perror("socket");
res = 1;
goto out;
}
if (opt_a) {
if (optind == argc) {
if_print((char *)NULL);
goto out;
} else {
fprintf(stderr, "%s", usage_msg);
res = 2;
goto out;
}
}
spp = argv + optind;
master_ifname = *spp++;
if (master_ifname == NULL) {
fprintf(stderr, "%s", usage_msg);
res = 2;
goto out;
}
res = get_drv_info(master_ifname);
if (res) {
fprintf(stderr,
"Master '%s': Error: handshake with driver failed. "
"Aborting\n",
master_ifname);
goto out;
}
slave_ifname = *spp++;
if (slave_ifname == NULL) {
if (opt_d || opt_c) {
fprintf(stderr, "%s", usage_msg);
res = 2;
goto out;
}
if_print(master_ifname);
goto out;
}
res = get_if_settings(master_ifname, master_ifra);
if (res) {
fprintf(stderr,
"Master '%s': Error: get settings failed: %s. "
"Aborting\n",
master_ifname, strerror(res));
goto out;
}
if (!(master_flags.ifr_flags & IFF_MASTER)) {
fprintf(stderr,
"Illegal operation; the specified interface '%s' "
"is not a master. Aborting\n",
master_ifname);
res = 1;
goto out;
}
if (!(master_flags.ifr_flags & IFF_UP)) {
fprintf(stderr,
"Illegal operation; the specified master interface "
"'%s' is not up.\n",
master_ifname);
res = 1;
goto out;
}
if (!opt_c && !opt_d) {
sa_family_t master_family = master_hwaddr.ifr_hwaddr.sa_family;
unsigned char *hwaddr =
(unsigned char *)master_hwaddr.ifr_hwaddr.sa_data;
if (master_family != 1 && !opt_f) {
fprintf(stderr,
"Illegal operation: The specified master "
"interface '%s' is not ethernet-like.\n "
"This program is designed to work with "
"ethernet-like network interfaces.\n "
"Use the '-f' option to force the "
"operation.\n",
master_ifname);
res = 1;
goto out;
}
for (i = 0; i < 6; i++) {
if (hwaddr[i] != 0) {
hwaddr_set = 1;
break;
}
}
if (hwaddr_set) {
v_print("current hardware address of master '%s' "
"is %2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x, "
"type %d\n",
master_ifname,
hwaddr[0], hwaddr[1],
hwaddr[2], hwaddr[3],
hwaddr[4], hwaddr[5],
master_family);
}
}
if (opt_c) {
res = get_slave_flags(slave_ifname);
if (res) {
fprintf(stderr,
"Slave '%s': Error: get flags failed. "
"Aborting\n",
slave_ifname);
goto out;
}
res = change_active(master_ifname, slave_ifname);
if (res) {
fprintf(stderr,
"Master '%s', Slave '%s': Error: "
"Change active failed\n",
master_ifname, slave_ifname);
}
} else {
do {
if (opt_d) {
rv = get_slave_flags(slave_ifname);
if (rv) {
fprintf(stderr,
"Slave '%s': Error: get flags "
"failed. Skipping\n",
slave_ifname);
res = rv;
continue;
}
rv = release(master_ifname, slave_ifname);
if (rv) {
fprintf(stderr,
"Master '%s', Slave '%s': Error: "
"Release failed\n",
master_ifname, slave_ifname);
res = rv;
}
} else {
rv = get_if_settings(slave_ifname, slave_ifra);
if (rv) {
fprintf(stderr,
"Slave '%s': Error: get "
"settings failed: %s. "
"Skipping\n",
slave_ifname, strerror(rv));
res = rv;
continue;
}
rv = enslave(master_ifname, slave_ifname);
if (rv) {
fprintf(stderr,
"Master '%s', Slave '%s': Error: "
"Enslave failed\n",
master_ifname, slave_ifname);
res = rv;
}
}
} while ((slave_ifname = *spp++) != NULL);
}
out:
if (skfd >= 0) {
close(skfd);
}
return res;
}
static int if_getconfig(char *ifname)
{
struct ifreq ifr;
int metric, mtu;
struct sockaddr dstaddr, broadaddr, netmask;
unsigned char *hwaddr;
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFFLAGS, &ifr) < 0)
return -1;
mif_flags = ifr.ifr_flags;
printf("The result of SIOCGIFFLAGS on %s is %x.\n",
ifname, ifr.ifr_flags);
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFADDR, &ifr) < 0)
return -1;
printf("The result of SIOCGIFADDR is %2.2x.%2.2x.%2.2x.%2.2x.\n",
ifr.ifr_addr.sa_data[0], ifr.ifr_addr.sa_data[1],
ifr.ifr_addr.sa_data[2], ifr.ifr_addr.sa_data[3]);
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFHWADDR, &ifr) < 0)
return -1;
hwaddr = (unsigned char *)ifr.ifr_hwaddr.sa_data;
printf("The result of SIOCGIFHWADDR is type %d "
"%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x.\n",
ifr.ifr_hwaddr.sa_family, hwaddr[0], hwaddr[1],
hwaddr[2], hwaddr[3], hwaddr[4], hwaddr[5]);
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFMETRIC, &ifr) < 0) {
metric = 0;
} else
metric = ifr.ifr_metric;
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFMTU, &ifr) < 0)
mtu = 0;
else
mtu = ifr.ifr_mtu;
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFDSTADDR, &ifr) < 0) {
memset(&dstaddr, 0, sizeof(struct sockaddr));
} else
dstaddr = ifr.ifr_dstaddr;
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFBRDADDR, &ifr) < 0) {
memset(&broadaddr, 0, sizeof(struct sockaddr));
} else
broadaddr = ifr.ifr_broadaddr;
strcpy(ifr.ifr_name, ifname);
if (ioctl(skfd, SIOCGIFNETMASK, &ifr) < 0) {
memset(&netmask, 0, sizeof(struct sockaddr));
} else
netmask = ifr.ifr_netmask;
return 0;
}
static void if_print(char *ifname)
{
char buff[1024];
struct ifconf ifc;
struct ifreq *ifr;
int i;
if (ifname == (char *)NULL) {
ifc.ifc_len = sizeof(buff);
ifc.ifc_buf = buff;
if (ioctl(skfd, SIOCGIFCONF, &ifc) < 0) {
perror("SIOCGIFCONF failed");
return;
}
ifr = ifc.ifc_req;
for (i = ifc.ifc_len / sizeof(struct ifreq); --i >= 0; ifr++) {
if (if_getconfig(ifr->ifr_name) < 0) {
fprintf(stderr,
"%s: unknown interface.\n",
ifr->ifr_name);
continue;
}
if (((mif_flags & IFF_UP) == 0) && !opt_a) continue;
}
} else {
if (if_getconfig(ifname) < 0) {
fprintf(stderr,
"%s: unknown interface.\n", ifname);
}
}
}
static int get_drv_info(char *master_ifname)
{
struct ifreq ifr;
struct ethtool_drvinfo info;
char *endptr;
memset(&ifr, 0, sizeof(ifr));
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
ifr.ifr_data = (caddr_t)&info;
info.cmd = ETHTOOL_GDRVINFO;
strncpy(info.driver, "ifenslave", 32);
snprintf(info.fw_version, 32, "%d", BOND_ABI_VERSION);
if (ioctl(skfd, SIOCETHTOOL, &ifr) < 0) {
if (errno == EOPNOTSUPP) {
goto out;
}
saved_errno = errno;
v_print("Master '%s': Error: get bonding info failed %s\n",
master_ifname, strerror(saved_errno));
return 1;
}
abi_ver = strtoul(info.fw_version, &endptr, 0);
if (*endptr) {
v_print("Master '%s': Error: got invalid string as an ABI "
"version from the bonding module\n",
master_ifname);
return 1;
}
out:
v_print("ABI ver is %d\n", abi_ver);
return 0;
}
static int change_active(char *master_ifname, char *slave_ifname)
{
struct ifreq ifr;
int res = 0;
if (!(slave_flags.ifr_flags & IFF_SLAVE)) {
fprintf(stderr,
"Illegal operation: The specified slave interface "
"'%s' is not a slave\n",
slave_ifname);
return 1;
}
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
strncpy(ifr.ifr_slave, slave_ifname, IFNAMSIZ);
if ((ioctl(skfd, SIOCBONDCHANGEACTIVE, &ifr) < 0) &&
(ioctl(skfd, BOND_CHANGE_ACTIVE_OLD, &ifr) < 0)) {
saved_errno = errno;
v_print("Master '%s': Error: SIOCBONDCHANGEACTIVE failed: "
"%s\n",
master_ifname, strerror(saved_errno));
res = 1;
}
return res;
}
static int enslave(char *master_ifname, char *slave_ifname)
{
struct ifreq ifr;
int res = 0;
if (slave_flags.ifr_flags & IFF_SLAVE) {
fprintf(stderr,
"Illegal operation: The specified slave interface "
"'%s' is already a slave\n",
slave_ifname);
return 1;
}
res = set_if_down(slave_ifname, slave_flags.ifr_flags);
if (res) {
fprintf(stderr,
"Slave '%s': Error: bring interface down failed\n",
slave_ifname);
return res;
}
if (abi_ver < 2) {
set_if_addr(master_ifname, slave_ifname);
} else {
res = clear_if_addr(slave_ifname);
if (res) {
fprintf(stderr,
"Slave '%s': Error: clear address failed\n",
slave_ifname);
return res;
}
}
if (master_mtu.ifr_mtu != slave_mtu.ifr_mtu) {
res = set_slave_mtu(slave_ifname, master_mtu.ifr_mtu);
if (res) {
fprintf(stderr,
"Slave '%s': Error: set MTU failed\n",
slave_ifname);
return res;
}
}
if (hwaddr_set) {
if (abi_ver < 1) {
res = set_slave_hwaddr(slave_ifname,
&(master_hwaddr.ifr_hwaddr));
if (res) {
fprintf(stderr,
"Slave '%s': Error: set hw address "
"failed\n",
slave_ifname);
goto undo_mtu;
}
res = set_if_up(slave_ifname, slave_flags.ifr_flags);
if (res) {
fprintf(stderr,
"Slave '%s': Error: bring interface "
"down failed\n",
slave_ifname);
goto undo_slave_mac;
}
}
} else {
if (abi_ver < 1) {
res = set_if_down(master_ifname, master_flags.ifr_flags);
if (res) {
fprintf(stderr,
"Master '%s': Error: bring interface "
"down failed\n",
master_ifname);
goto undo_mtu;
}
}
res = set_master_hwaddr(master_ifname,
&(slave_hwaddr.ifr_hwaddr));
if (res) {
fprintf(stderr,
"Master '%s': Error: set hw address "
"failed\n",
master_ifname);
goto undo_mtu;
}
if (abi_ver < 1) {
res = set_if_up(master_ifname, master_flags.ifr_flags);
if (res) {
fprintf(stderr,
"Master '%s': Error: bring interface "
"up failed\n",
master_ifname);
goto undo_master_mac;
}
}
hwaddr_set = 1;
}
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
strncpy(ifr.ifr_slave, slave_ifname, IFNAMSIZ);
if ((ioctl(skfd, SIOCBONDENSLAVE, &ifr) < 0) &&
(ioctl(skfd, BOND_ENSLAVE_OLD, &ifr) < 0)) {
saved_errno = errno;
v_print("Master '%s': Error: SIOCBONDENSLAVE failed: %s\n",
master_ifname, strerror(saved_errno));
res = 1;
}
if (res) {
goto undo_master_mac;
}
return 0;
undo_master_mac:
set_master_hwaddr(master_ifname, &(master_hwaddr.ifr_hwaddr));
hwaddr_set = 0;
goto undo_mtu;
undo_slave_mac:
set_slave_hwaddr(slave_ifname, &(slave_hwaddr.ifr_hwaddr));
undo_mtu:
set_slave_mtu(slave_ifname, slave_mtu.ifr_mtu);
return res;
}
static int release(char *master_ifname, char *slave_ifname)
{
struct ifreq ifr;
int res = 0;
if (!(slave_flags.ifr_flags & IFF_SLAVE)) {
fprintf(stderr,
"Illegal operation: The specified slave interface "
"'%s' is not a slave\n",
slave_ifname);
return 1;
}
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
strncpy(ifr.ifr_slave, slave_ifname, IFNAMSIZ);
if ((ioctl(skfd, SIOCBONDRELEASE, &ifr) < 0) &&
(ioctl(skfd, BOND_RELEASE_OLD, &ifr) < 0)) {
saved_errno = errno;
v_print("Master '%s': Error: SIOCBONDRELEASE failed: %s\n",
master_ifname, strerror(saved_errno));
return 1;
} else if (abi_ver < 1) {
res = set_if_down(slave_ifname, slave_flags.ifr_flags);
if (res) {
fprintf(stderr,
"Slave '%s': Error: bring interface "
"down failed\n",
slave_ifname);
}
}
set_slave_mtu(slave_ifname, 1500);
return res;
}
static int get_if_settings(char *ifname, struct dev_ifr ifra[])
{
int i;
int res = 0;
for (i = 0; ifra[i].req_ifr; i++) {
strncpy(ifra[i].req_ifr->ifr_name, ifname, IFNAMSIZ);
res = ioctl(skfd, ifra[i].req_type, ifra[i].req_ifr);
if (res < 0) {
saved_errno = errno;
v_print("Interface '%s': Error: %s failed: %s\n",
ifname, ifra[i].req_name,
strerror(saved_errno));
return saved_errno;
}
}
return 0;
}
static int get_slave_flags(char *slave_ifname)
{
int res = 0;
strncpy(slave_flags.ifr_name, slave_ifname, IFNAMSIZ);
res = ioctl(skfd, SIOCGIFFLAGS, &slave_flags);
if (res < 0) {
saved_errno = errno;
v_print("Slave '%s': Error: SIOCGIFFLAGS failed: %s\n",
slave_ifname, strerror(saved_errno));
} else {
v_print("Slave %s: flags %04X.\n",
slave_ifname, slave_flags.ifr_flags);
}
return res;
}
static int set_master_hwaddr(char *master_ifname, struct sockaddr *hwaddr)
{
unsigned char *addr = (unsigned char *)hwaddr->sa_data;
struct ifreq ifr;
int res = 0;
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
memcpy(&(ifr.ifr_hwaddr), hwaddr, sizeof(struct sockaddr));
res = ioctl(skfd, SIOCSIFHWADDR, &ifr);
if (res < 0) {
saved_errno = errno;
v_print("Master '%s': Error: SIOCSIFHWADDR failed: %s\n",
master_ifname, strerror(saved_errno));
return res;
} else {
v_print("Master '%s': hardware address set to "
"%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x.\n",
master_ifname, addr[0], addr[1], addr[2],
addr[3], addr[4], addr[5]);
}
return res;
}
static int set_slave_hwaddr(char *slave_ifname, struct sockaddr *hwaddr)
{
unsigned char *addr = (unsigned char *)hwaddr->sa_data;
struct ifreq ifr;
int res = 0;
strncpy(ifr.ifr_name, slave_ifname, IFNAMSIZ);
memcpy(&(ifr.ifr_hwaddr), hwaddr, sizeof(struct sockaddr));
res = ioctl(skfd, SIOCSIFHWADDR, &ifr);
if (res < 0) {
saved_errno = errno;
v_print("Slave '%s': Error: SIOCSIFHWADDR failed: %s\n",
slave_ifname, strerror(saved_errno));
if (saved_errno == EBUSY) {
v_print(" The device is busy: it must be idle "
"before running this command.\n");
} else if (saved_errno == EOPNOTSUPP) {
v_print(" The device does not support setting "
"the MAC address.\n"
" Your kernel likely does not support slave "
"devices.\n");
} else if (saved_errno == EINVAL) {
v_print(" The device's address type does not match "
"the master's address type.\n");
}
return res;
} else {
v_print("Slave '%s': hardware address set to "
"%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x.\n",
slave_ifname, addr[0], addr[1], addr[2],
addr[3], addr[4], addr[5]);
}
return res;
}
static int set_slave_mtu(char *slave_ifname, int mtu)
{
struct ifreq ifr;
int res = 0;
ifr.ifr_mtu = mtu;
strncpy(ifr.ifr_name, slave_ifname, IFNAMSIZ);
res = ioctl(skfd, SIOCSIFMTU, &ifr);
if (res < 0) {
saved_errno = errno;
v_print("Slave '%s': Error: SIOCSIFMTU failed: %s\n",
slave_ifname, strerror(saved_errno));
} else {
v_print("Slave '%s': MTU set to %d.\n", slave_ifname, mtu);
}
return res;
}
static int set_if_flags(char *ifname, short flags)
{
struct ifreq ifr;
int res = 0;
ifr.ifr_flags = flags;
strncpy(ifr.ifr_name, ifname, IFNAMSIZ);
res = ioctl(skfd, SIOCSIFFLAGS, &ifr);
if (res < 0) {
saved_errno = errno;
v_print("Interface '%s': Error: SIOCSIFFLAGS failed: %s\n",
ifname, strerror(saved_errno));
} else {
v_print("Interface '%s': flags set to %04X.\n", ifname, flags);
}
return res;
}
static int set_if_up(char *ifname, short flags)
{
return set_if_flags(ifname, flags | IFF_UP);
}
static int set_if_down(char *ifname, short flags)
{
return set_if_flags(ifname, flags & ~IFF_UP);
}
static int clear_if_addr(char *ifname)
{
struct ifreq ifr;
int res = 0;
strncpy(ifr.ifr_name, ifname, IFNAMSIZ);
ifr.ifr_addr.sa_family = AF_INET;
memset(ifr.ifr_addr.sa_data, 0, sizeof(ifr.ifr_addr.sa_data));
res = ioctl(skfd, SIOCSIFADDR, &ifr);
if (res < 0) {
saved_errno = errno;
v_print("Interface '%s': Error: SIOCSIFADDR failed: %s\n",
ifname, strerror(saved_errno));
} else {
v_print("Interface '%s': address cleared\n", ifname);
}
return res;
}
static int set_if_addr(char *master_ifname, char *slave_ifname)
{
struct ifreq ifr;
int res;
unsigned char *ipaddr;
int i;
struct {
char *req_name;
char *desc;
int g_ioctl;
int s_ioctl;
} ifra[] = {
{"IFADDR", "addr", SIOCGIFADDR, SIOCSIFADDR},
{"DSTADDR", "destination addr", SIOCGIFDSTADDR, SIOCSIFDSTADDR},
{"BRDADDR", "broadcast addr", SIOCGIFBRDADDR, SIOCSIFBRDADDR},
{"NETMASK", "netmask", SIOCGIFNETMASK, SIOCSIFNETMASK},
{NULL, NULL, 0, 0},
};
for (i = 0; ifra[i].req_name; i++) {
strncpy(ifr.ifr_name, master_ifname, IFNAMSIZ);
res = ioctl(skfd, ifra[i].g_ioctl, &ifr);
if (res < 0) {
int saved_errno = errno;
v_print("Interface '%s': Error: SIOCG%s failed: %s\n",
master_ifname, ifra[i].req_name,
strerror(saved_errno));
ifr.ifr_addr.sa_family = AF_INET;
memset(ifr.ifr_addr.sa_data, 0,
sizeof(ifr.ifr_addr.sa_data));
}
strncpy(ifr.ifr_name, slave_ifname, IFNAMSIZ);
res = ioctl(skfd, ifra[i].s_ioctl, &ifr);
if (res < 0) {
int saved_errno = errno;
v_print("Interface '%s': Error: SIOCS%s failed: %s\n",
slave_ifname, ifra[i].req_name,
strerror(saved_errno));
}
ipaddr = (unsigned char *)ifr.ifr_addr.sa_data;
v_print("Interface '%s': set IP %s to %d.%d.%d.%d\n",
slave_ifname, ifra[i].desc,
ipaddr[0], ipaddr[1], ipaddr[2], ipaddr[3]);
}
return 0;
}
