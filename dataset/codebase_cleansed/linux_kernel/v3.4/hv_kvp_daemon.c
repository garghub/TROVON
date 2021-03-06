static void kvp_acquire_lock(int pool)
{
struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
fl.l_pid = getpid();
if (fcntl(kvp_file_info[pool].fd, F_SETLKW, &fl) == -1) {
syslog(LOG_ERR, "Failed to acquire the lock pool: %d", pool);
exit(-1);
}
}
static void kvp_release_lock(int pool)
{
struct flock fl = {F_UNLCK, SEEK_SET, 0, 0, 0};
fl.l_pid = getpid();
if (fcntl(kvp_file_info[pool].fd, F_SETLK, &fl) == -1) {
perror("fcntl");
syslog(LOG_ERR, "Failed to release the lock pool: %d", pool);
exit(-1);
}
}
static void kvp_update_file(int pool)
{
FILE *filep;
size_t bytes_written;
kvp_acquire_lock(pool);
filep = fopen(kvp_file_info[pool].fname, "w");
if (!filep) {
kvp_release_lock(pool);
syslog(LOG_ERR, "Failed to open file, pool: %d", pool);
exit(-1);
}
bytes_written = fwrite(kvp_file_info[pool].records,
sizeof(struct kvp_record),
kvp_file_info[pool].num_records, filep);
fflush(filep);
kvp_release_lock(pool);
}
static void kvp_update_mem_state(int pool)
{
FILE *filep;
size_t records_read = 0;
struct kvp_record *record = kvp_file_info[pool].records;
struct kvp_record *readp;
int num_blocks = kvp_file_info[pool].num_blocks;
int alloc_unit = sizeof(struct kvp_record) * ENTRIES_PER_BLOCK;
kvp_acquire_lock(pool);
filep = fopen(kvp_file_info[pool].fname, "r");
if (!filep) {
kvp_release_lock(pool);
syslog(LOG_ERR, "Failed to open file, pool: %d", pool);
exit(-1);
}
while (!feof(filep)) {
readp = &record[records_read];
records_read += fread(readp, sizeof(struct kvp_record),
ENTRIES_PER_BLOCK * num_blocks,
filep);
if (!feof(filep)) {
num_blocks++;
record = realloc(record, alloc_unit * num_blocks);
if (record == NULL) {
syslog(LOG_ERR, "malloc failed");
exit(-1);
}
continue;
}
break;
}
kvp_file_info[pool].num_blocks = num_blocks;
kvp_file_info[pool].records = record;
kvp_file_info[pool].num_records = records_read;
kvp_release_lock(pool);
}
static int kvp_file_init(void)
{
int ret, fd;
FILE *filep;
size_t records_read;
__u8 *fname;
struct kvp_record *record;
struct kvp_record *readp;
int num_blocks;
int i;
int alloc_unit = sizeof(struct kvp_record) * ENTRIES_PER_BLOCK;
if (access("/var/opt/hyperv", F_OK)) {
if (mkdir("/var/opt/hyperv", S_IRUSR | S_IWUSR | S_IROTH)) {
syslog(LOG_ERR, " Failed to create /var/opt/hyperv");
exit(-1);
}
}
for (i = 0; i < KVP_POOL_COUNT; i++) {
fname = kvp_file_info[i].fname;
records_read = 0;
num_blocks = 1;
sprintf(fname, "/var/opt/hyperv/.kvp_pool_%d", i);
fd = open(fname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IROTH);
if (fd == -1)
return 1;
filep = fopen(fname, "r");
if (!filep)
return 1;
record = malloc(alloc_unit * num_blocks);
if (record == NULL) {
fclose(filep);
return 1;
}
while (!feof(filep)) {
readp = &record[records_read];
records_read += fread(readp, sizeof(struct kvp_record),
ENTRIES_PER_BLOCK,
filep);
if (!feof(filep)) {
num_blocks++;
record = realloc(record, alloc_unit *
num_blocks);
if (record == NULL) {
fclose(filep);
return 1;
}
continue;
}
break;
}
kvp_file_info[i].fd = fd;
kvp_file_info[i].num_blocks = num_blocks;
kvp_file_info[i].records = record;
kvp_file_info[i].num_records = records_read;
fclose(filep);
}
return 0;
}
static int kvp_key_delete(int pool, __u8 *key, int key_size)
{
int i;
int j, k;
int num_records;
struct kvp_record *record;
kvp_update_mem_state(pool);
num_records = kvp_file_info[pool].num_records;
record = kvp_file_info[pool].records;
for (i = 0; i < num_records; i++) {
if (memcmp(key, record[i].key, key_size))
continue;
if (i == num_records) {
kvp_file_info[pool].num_records--;
kvp_update_file(pool);
return 0;
}
j = i;
k = j + 1;
for (; k < num_records; k++) {
strcpy(record[j].key, record[k].key);
strcpy(record[j].value, record[k].value);
j++;
}
kvp_file_info[pool].num_records--;
kvp_update_file(pool);
return 0;
}
return 1;
}
static int kvp_key_add_or_modify(int pool, __u8 *key, int key_size, __u8 *value,
int value_size)
{
int i;
int j, k;
int num_records;
struct kvp_record *record;
int num_blocks;
if ((key_size > HV_KVP_EXCHANGE_MAX_KEY_SIZE) ||
(value_size > HV_KVP_EXCHANGE_MAX_VALUE_SIZE))
return 1;
kvp_update_mem_state(pool);
num_records = kvp_file_info[pool].num_records;
record = kvp_file_info[pool].records;
num_blocks = kvp_file_info[pool].num_blocks;
for (i = 0; i < num_records; i++) {
if (memcmp(key, record[i].key, key_size))
continue;
memcpy(record[i].value, value, value_size);
kvp_update_file(pool);
return 0;
}
if (num_records == (ENTRIES_PER_BLOCK * num_blocks)) {
record = realloc(record, sizeof(struct kvp_record) *
ENTRIES_PER_BLOCK * (num_blocks + 1));
if (record == NULL)
return 1;
kvp_file_info[pool].num_blocks++;
}
memcpy(record[i].value, value, value_size);
memcpy(record[i].key, key, key_size);
kvp_file_info[pool].records = record;
kvp_file_info[pool].num_records++;
kvp_update_file(pool);
return 0;
}
static int kvp_get_value(int pool, __u8 *key, int key_size, __u8 *value,
int value_size)
{
int i;
int num_records;
struct kvp_record *record;
if ((key_size > HV_KVP_EXCHANGE_MAX_KEY_SIZE) ||
(value_size > HV_KVP_EXCHANGE_MAX_VALUE_SIZE))
return 1;
kvp_update_mem_state(pool);
num_records = kvp_file_info[pool].num_records;
record = kvp_file_info[pool].records;
for (i = 0; i < num_records; i++) {
if (memcmp(key, record[i].key, key_size))
continue;
memcpy(value, record[i].value, value_size);
return 0;
}
return 1;
}
static void kvp_pool_enumerate(int pool, int index, __u8 *key, int key_size,
__u8 *value, int value_size)
{
struct kvp_record *record;
kvp_update_mem_state(pool);
record = kvp_file_info[pool].records;
if (index >= kvp_file_info[pool].num_records) {
strcpy(value, "");
return;
}
memcpy(key, record[index].key, key_size);
memcpy(value, record[index].value, value_size);
}
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
struct hv_kvp_msg *hv_msg;
char *p;
char *key_value;
char *key_name;
daemon(1, 0);
openlog("KVP", 0, LOG_USER);
syslog(LOG_INFO, "KVP starting; pid is:%d", getpid());
kvp_get_os_info();
if (kvp_file_init()) {
syslog(LOG_ERR, "Failed to initialize the pools");
exit(-1);
}
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
hv_msg = (struct hv_kvp_msg *)message->data;
hv_msg->kvp_hdr.operation = KVP_OP_REGISTER;
message->ack = 0;
message->len = sizeof(struct hv_kvp_msg);
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
hv_msg = (struct hv_kvp_msg *)incoming_cn_msg->data;
switch (hv_msg->kvp_hdr.operation) {
case KVP_OP_REGISTER:
p = (char *)hv_msg->body.kvp_register.version;
lic_version = malloc(strlen(p) + 1);
if (lic_version) {
strcpy(lic_version, p);
syslog(LOG_INFO, "KVP LIC Version: %s",
lic_version);
} else {
syslog(LOG_ERR, "malloc failed");
}
continue;
case KVP_OP_SET:
if (kvp_key_add_or_modify(hv_msg->kvp_hdr.pool,
hv_msg->body.kvp_set.data.key,
hv_msg->body.kvp_set.data.key_size,
hv_msg->body.kvp_set.data.value,
hv_msg->body.kvp_set.data.value_size))
strcpy(hv_msg->body.kvp_set.data.key, "");
break;
case KVP_OP_GET:
if (kvp_get_value(hv_msg->kvp_hdr.pool,
hv_msg->body.kvp_set.data.key,
hv_msg->body.kvp_set.data.key_size,
hv_msg->body.kvp_set.data.value,
hv_msg->body.kvp_set.data.value_size))
strcpy(hv_msg->body.kvp_set.data.key, "");
break;
case KVP_OP_DELETE:
if (kvp_key_delete(hv_msg->kvp_hdr.pool,
hv_msg->body.kvp_delete.key,
hv_msg->body.kvp_delete.key_size))
strcpy(hv_msg->body.kvp_delete.key, "");
break;
default:
break;
}
if (hv_msg->kvp_hdr.operation != KVP_OP_ENUMERATE)
goto kvp_done;
if (hv_msg->kvp_hdr.pool != KVP_POOL_AUTO) {
kvp_pool_enumerate(hv_msg->kvp_hdr.pool,
hv_msg->body.kvp_enum_data.index,
hv_msg->body.kvp_enum_data.data.key,
HV_KVP_EXCHANGE_MAX_KEY_SIZE,
hv_msg->body.kvp_enum_data.data.value,
HV_KVP_EXCHANGE_MAX_VALUE_SIZE);
goto kvp_done;
}
hv_msg = (struct hv_kvp_msg *)incoming_cn_msg->data;
key_name = (char *)hv_msg->body.kvp_enum_data.data.key;
key_value = (char *)hv_msg->body.kvp_enum_data.data.value;
switch (hv_msg->body.kvp_enum_data.index) {
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
kvp_done:
incoming_cn_msg->id.idx = CN_KVP_IDX;
incoming_cn_msg->id.val = CN_KVP_VAL;
incoming_cn_msg->ack = 0;
incoming_cn_msg->len = sizeof(struct hv_kvp_msg);
len = netlink_send(fd, incoming_cn_msg);
if (len < 0) {
syslog(LOG_ERR, "net_link send failed; error:%d", len);
exit(-1);
}
}
}
