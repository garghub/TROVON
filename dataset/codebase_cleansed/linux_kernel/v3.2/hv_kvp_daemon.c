void kvp_get_os_info(void)
{
FILE *file;
char *p, buf[512];
uname(&uts_buf);
os_build = uts_buf.release;
processor_arch = uts_buf.machine;
p = strchr(os_build, '-');
if (p)
*p = '\0';
file = fopen("/etc/SuSE-release", "r");
if (file != NULL)
goto kvp_osinfo_found;
file = fopen("/etc/redhat-release", "r");
if (file != NULL)
goto kvp_osinfo_found;
os_name = uts_buf.sysname;
return;
kvp_osinfo_found:
p = fgets(buf, sizeof(buf), file);
if (p) {
p = strchr(buf, '\n');
if (p)
*p = '\0';
p = strdup(buf);
if (!p)
goto done;
os_name = p;
p = fgets(buf, sizeof(buf), file);
if (p) {
p = strchr(buf, '\n');
if (p)
*p = '\0';
p = strdup(buf);
if (!p)
goto done;
os_major = p;
p = fgets(buf, sizeof(buf), file);
if (p) {
p = strchr(buf, '\n');
if (p)
*p = '\0';
p = strdup(buf);
if (p)
os_minor = p;
}
}
}
done:
fclose(file);
return;
}
static int
kvp_get_ip_address(int family, char *buffer, int length)
{
struct ifaddrs *ifap;
struct ifaddrs *curp;
int ipv4_len = strlen("255.255.255.255") + 1;
int ipv6_len = strlen("ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff")+1;
int offset = 0;
const char *str;
char tmp[50];
int error = 0;
if (getifaddrs(&ifap)) {
strcpy(buffer, "getifaddrs failed\n");
return 1;
}
curp = ifap;
while (curp != NULL) {
if ((curp->ifa_addr != NULL) &&
(curp->ifa_addr->sa_family == family)) {
if (family == AF_INET) {
struct sockaddr_in *addr =
(struct sockaddr_in *) curp->ifa_addr;
str = inet_ntop(family, &addr->sin_addr,
tmp, 50);
if (str == NULL) {
strcpy(buffer, "inet_ntop failed\n");
error = 1;
goto getaddr_done;
}
if (offset == 0)
strcpy(buffer, tmp);
else
strcat(buffer, tmp);
strcat(buffer, ";");
offset += strlen(str) + 1;
if ((length - offset) < (ipv4_len + 1))
goto getaddr_done;
} else {
struct sockaddr_in6 *addr =
(struct sockaddr_in6 *) curp->ifa_addr;
str = inet_ntop(family,
&addr->sin6_addr.s6_addr,
tmp, 50);
if (str == NULL) {
strcpy(buffer, "inet_ntop failed\n");
error = 1;
goto getaddr_done;
}
if (offset == 0)
strcpy(buffer, tmp);
else
strcat(buffer, tmp);
strcat(buffer, ";");
offset += strlen(str) + 1;
if ((length - offset) < (ipv6_len + 1))
goto getaddr_done;
}
}
curp = curp->ifa_next;
}
getaddr_done:
freeifaddrs(ifap);
return error;
}
static int
kvp_get_domain_name(char *buffer, int length)
{
struct addrinfo hints, *info ;
int error = 0;
gethostname(buffer, length);
memset(&hints, 0, sizeof(hints));
hints.ai_family = AF_INET;
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_CANONNAME;
error = getaddrinfo(buffer, NULL, &hints, &info);
if (error != 0) {
strcpy(buffer, "getaddrinfo failed\n");
return error;
}
strcpy(buffer, info->ai_canonname);
freeaddrinfo(info);
return error;
}
static int
netlink_send(int fd, struct cn_msg *msg)
{
struct nlmsghdr *nlh;
unsigned int size;
struct msghdr message;
char buffer[64];
struct iovec iov[2];
size = NLMSG_SPACE(sizeof(struct cn_msg) + msg->len);
nlh = (struct nlmsghdr *)buffer;
nlh->nlmsg_seq = 0;
nlh->nlmsg_pid = getpid();
nlh->nlmsg_type = NLMSG_DONE;
nlh->nlmsg_len = NLMSG_LENGTH(size - sizeof(*nlh));
nlh->nlmsg_flags = 0;
iov[0].iov_base = nlh;
iov[0].iov_len = sizeof(*nlh);
iov[1].iov_base = msg;
iov[1].iov_len = size;
memset(&message, 0, sizeof(message));
message.msg_name = &addr;
message.msg_namelen = sizeof(addr);
message.msg_iov = iov;
message.msg_iovlen = 2;
return sendmsg(fd, &message, 0);
}
int main(void)
{
int fd, len, sock_opt;
int error;
struct cn_msg *message;
struct pollfd pfd;
struct nlmsghdr *incoming_msg;
struct cn_msg *incoming_cn_msg;
struct hv_ku_msg *hv_msg;
char *p;
char *key_value;
char *key_name;
daemon(1, 0);
openlog("KVP", 0, LOG_USER);
syslog(LOG_INFO, "KVP starting; pid is:%d", getpid());
kvp_get_os_info();
fd = socket(AF_NETLINK, SOCK_DGRAM, NETLINK_CONNECTOR);
if (fd < 0) {
syslog(LOG_ERR, "netlink socket creation failed; error:%d", fd);
exit(-1);
}
addr.nl_family = AF_NETLINK;
addr.nl_pad = 0;
addr.nl_pid = 0;
addr.nl_groups = CN_KVP_IDX;
error = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
if (error < 0) {
syslog(LOG_ERR, "bind failed; error:%d", error);
close(fd);
exit(-1);
}
sock_opt = addr.nl_groups;
setsockopt(fd, 270, 1, &sock_opt, sizeof(sock_opt));
message = (struct cn_msg *)kvp_send_buffer;
message->id.idx = CN_KVP_IDX;
message->id.val = CN_KVP_VAL;
message->seq = KVP_REGISTER;
message->ack = 0;
message->len = 0;
len = netlink_send(fd, message);
if (len < 0) {
syslog(LOG_ERR, "netlink_send failed; error:%d", len);
close(fd);
exit(-1);
}
pfd.fd = fd;
while (1) {
pfd.events = POLLIN;
pfd.revents = 0;
poll(&pfd, 1, -1);
len = recv(fd, kvp_recv_buffer, sizeof(kvp_recv_buffer), 0);
if (len < 0) {
syslog(LOG_ERR, "recv failed; error:%d", len);
close(fd);
return -1;
}
incoming_msg = (struct nlmsghdr *)kvp_recv_buffer;
incoming_cn_msg = (struct cn_msg *)NLMSG_DATA(incoming_msg);
switch (incoming_cn_msg->seq) {
case KVP_REGISTER:
p = (char *)incoming_cn_msg->data;
lic_version = malloc(strlen(p) + 1);
if (lic_version) {
strcpy(lic_version, p);
syslog(LOG_INFO, "KVP LIC Version: %s",
lic_version);
} else {
syslog(LOG_ERR, "malloc failed");
}
continue;
case KVP_KERNEL_GET:
break;
default:
continue;
}
hv_msg = (struct hv_ku_msg *)incoming_cn_msg->data;
key_name = (char *)hv_msg->kvp_key;
key_value = (char *)hv_msg->kvp_value;
switch (hv_msg->kvp_index) {
case FullyQualifiedDomainName:
kvp_get_domain_name(key_value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE);
strcpy(key_name, "FullyQualifiedDomainName");
break;
case IntegrationServicesVersion:
strcpy(key_name, "IntegrationServicesVersion");
strcpy(key_value, lic_version);
break;
case NetworkAddressIPv4:
kvp_get_ip_address(AF_INET, key_value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE);
strcpy(key_name, "NetworkAddressIPv4");
break;
case NetworkAddressIPv6:
kvp_get_ip_address(AF_INET6, key_value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE);
strcpy(key_name, "NetworkAddressIPv6");
break;
case OSBuildNumber:
strcpy(key_value, os_build);
strcpy(key_name, "OSBuildNumber");
break;
case OSName:
strcpy(key_value, os_name);
strcpy(key_name, "OSName");
break;
case OSMajorVersion:
strcpy(key_value, os_major);
strcpy(key_name, "OSMajorVersion");
break;
case OSMinorVersion:
strcpy(key_value, os_minor);
strcpy(key_name, "OSMinorVersion");
break;
case OSVersion:
strcpy(key_value, os_build);
strcpy(key_name, "OSVersion");
break;
case ProcessorArchitecture:
strcpy(key_value, processor_arch);
strcpy(key_name, "ProcessorArchitecture");
break;
default:
strcpy(key_value, "Unknown Key");
strcpy(key_name, "");
break;
}
incoming_cn_msg->id.idx = CN_KVP_IDX;
incoming_cn_msg->id.val = CN_KVP_VAL;
incoming_cn_msg->seq = KVP_USER_SET;
incoming_cn_msg->ack = 0;
incoming_cn_msg->len = sizeof(struct hv_ku_msg);
len = netlink_send(fd, incoming_cn_msg);
if (len < 0) {
syslog(LOG_ERR, "net_link send failed; error:%d", len);
exit(-1);
}
}
}
