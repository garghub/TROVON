static void
add_async_dns_ipv4(int type, guint32 addr)
{
async_dns_queue_msg_t *msg;
msg = g_malloc(sizeof(async_dns_queue_msg_t));
#ifdef HAVE_C_ARES
msg->family = type;
msg->addr.ip4 = addr;
#else
msg->type = type;
msg->ip4_addr = addr;
msg->submitted = FALSE;
#endif
async_dns_queue_head = g_list_append(async_dns_queue_head, (gpointer) msg);
}
static int
fgetline(char **buf, int *size, FILE *fp)
{
int len;
int c;
if (fp == NULL || buf == NULL)
return -1;
if (*buf == NULL) {
if (*size == 0)
*size = BUFSIZ;
*buf = g_malloc(*size);
}
g_assert(*buf);
g_assert(*size > 0);
if (feof(fp))
return -1;
len = 0;
while ((c = getc(fp)) != EOF && c != '\r' && c != '\n') {
if (len+1 >= *size) {
*buf = g_realloc(*buf, *size += BUFSIZ);
}
(*buf)[len++] = c;
}
if (len == 0 && c == EOF)
return -1;
(*buf)[len] = '\0';
return len;
}
static void
add_service_name(hashport_t **proto_table, const guint port, const char *service_name)
{
int hash_idx;
hashport_t *tp;
hash_idx = HASH_PORT(port);
tp = proto_table[hash_idx];
if( tp == NULL ) {
tp = proto_table[hash_idx] = (hashport_t *)g_malloc(sizeof(hashport_t));
} else {
while(1) {
if( tp->port == port ) {
return;
}
if (tp->next == NULL) {
tp->next = (hashport_t *)g_malloc(sizeof(hashport_t));
tp = tp->next;
break;
}
tp = tp->next;
}
}
tp->port = port;
tp->next = NULL;
g_strlcpy(tp->name, service_name, MAXNAMELEN);
new_resolved_objects = TRUE;
}
static void
parse_service_line (char *line)
{
gchar *cp;
gchar *service;
gchar *port;
range_t *port_rng = NULL;
guint32 max_port = MAX_UDP_PORT;
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
return;
service = cp;
if ((cp = strtok(NULL, " \t")) == NULL)
return;
port = cp;
if (strtok(cp, "/") == NULL)
return;
if ((cp = strtok(NULL, "/")) == NULL)
return;
if(strcmp(cp, "tcp") == 0) {
max_port = MAX_TCP_PORT;
cb_port_table = tcp_port_table;
}
else if(strcmp(cp, "udp") == 0) {
max_port = MAX_UDP_PORT;
cb_port_table = udp_port_table;
}
else if(strcmp(cp, "sctp") == 0) {
max_port = MAX_SCTP_PORT;
cb_port_table = sctp_port_table;
}
else if(strcmp(cp, "dccp") == 0) {
max_port = MAX_DCCP_PORT;
cb_port_table = dccp_port_table;
} else {
return;
}
if(CVT_NO_ERROR != range_convert_str(&port_rng, port, max_port) ) {
return;
}
cb_service = service;
range_foreach(port_rng, add_serv_port_cb);
g_free (port_rng);
}
static void
add_serv_port_cb(const guint32 port)
{
if ( port ) {
add_service_name(cb_port_table, port, cb_service);
}
}
static void
parse_services_file(const char * path)
{
FILE *serv_p;
static int size = 0;
static char *buf = NULL;
serv_p = ws_fopen(path, "r");
if (serv_p == NULL)
return;
while (fgetline(&buf, &size, serv_p) >= 0) {
parse_service_line (buf);
}
fclose(serv_p);
}
static void
initialize_services(void)
{
if (g_pservices_path == NULL)
g_pservices_path = get_persconffile_path(ENAME_SERVICES, FALSE, FALSE);
parse_services_file(g_pservices_path);
if (g_services_path == NULL) {
g_services_path = get_datafile_path(ENAME_SERVICES);
}
parse_services_file(g_services_path);
}
static gchar
*serv_name_lookup(const guint port, const port_type proto)
{
int hash_idx;
hashport_t *tp;
hashport_t **table;
const char *serv_proto = NULL;
struct servent *servp;
if (!service_resolution_initialized) {
initialize_services();
service_resolution_initialized = 1;
}
switch(proto) {
case PT_UDP:
table = udp_port_table;
serv_proto = "udp";
break;
case PT_TCP:
table = tcp_port_table;
serv_proto = "tcp";
break;
case PT_SCTP:
table = sctp_port_table;
serv_proto = "sctp";
break;
case PT_DCCP:
table = dccp_port_table;
serv_proto = "dcp";
break;
default:
return NULL;
}
hash_idx = HASH_PORT(port);
tp = table[hash_idx];
if( tp == NULL ) {
tp = table[hash_idx] = (hashport_t *)g_malloc(sizeof(hashport_t));
} else {
while(1) {
if( tp->port == port ) {
return tp->name;
}
if (tp->next == NULL) {
tp->next = (hashport_t *)g_malloc(sizeof(hashport_t));
tp = tp->next;
break;
}
tp = tp->next;
}
}
tp->port = port;
tp->next = NULL;
if (!(gbl_resolv_flags & RESOLV_TRANSPORT) ||
(servp = getservbyport(g_htons(port), serv_proto)) == NULL) {
guint32_to_str_buf(port, tp->name, MAXNAMELEN);
} else {
g_strlcpy(tp->name, servp->s_name, MAXNAMELEN);
}
return (tp->name);
}
static void
fill_dummy_ip4(const guint addr, hashipv4_t* volatile tp)
{
subnet_entry_t subnet_entry;
if (tp->is_dummy_entry)
return;
tp->is_dummy_entry = TRUE;
subnet_entry = subnet_lookup(addr);
if(0 != subnet_entry.mask) {
guint32 host_addr;
gchar buffer[MAX_IP_STR_LEN];
gchar* paddr;
gsize i;
host_addr = addr & (~(guint32)subnet_entry.mask);
ip_to_str_buf((guint8 *)&host_addr, buffer, MAX_IP_STR_LEN);
paddr = buffer;
i = subnet_entry.mask_length / 8;
while(*(paddr) != '\0' && i > 0) {
if(*(++paddr) == '.') {
--i;
}
}
g_snprintf(tp->name, MAXNAMELEN, "%s%s", subnet_entry.name, paddr);
} else {
ip_to_str_buf((const guint8 *)&addr, tp->name, MAXNAMELEN);
}
}
static hashipv4_t *
new_ipv4(const guint addr)
{
hashipv4_t *tp = g_malloc(sizeof(hashipv4_t));
tp->addr = addr;
tp->next = NULL;
tp->resolve = FALSE;
tp->is_dummy_entry = FALSE;
ip_to_str_buf((const guint8 *)&addr, tp->ip, sizeof(tp->ip));
return tp;
}
static hashipv4_t *
host_lookup(const guint addr, const gboolean resolve, gboolean *found)
{
int hash_idx;
hashipv4_t * volatile tp;
struct hostent *hostp;
*found = TRUE;
hash_idx = HASH_IPV4_ADDRESS(addr);
tp = ipv4_table[hash_idx];
if( tp == NULL ) {
tp = ipv4_table[hash_idx] = new_ipv4(addr);
} else {
while(1) {
if( tp->addr == addr ) {
if (tp->is_dummy_entry && !tp->resolve)
break;
if (tp->is_dummy_entry)
*found = FALSE;
return tp;
}
if (tp->next == NULL) {
tp->next = new_ipv4(addr);
tp = tp->next;
break;
}
tp = tp->next;
}
}
if (resolve) {
tp->resolve = TRUE;
#ifdef ASYNC_DNS
if ((gbl_resolv_flags & RESOLV_CONCURRENT) &&
prefs.name_resolve_concurrency > 0 &&
async_dns_initialized) {
add_async_dns_ipv4(AF_INET, addr);
fill_dummy_ip4(addr, tp);
return tp;
}
#endif
if (addr != 0 && (gbl_resolv_flags & RESOLV_NETWORK)) {
hostp = gethostbyaddr((char *)&addr, 4, AF_INET);
if (hostp != NULL) {
g_strlcpy(tp->name, hostp->h_name, MAXNAMELEN);
tp->is_dummy_entry = FALSE;
return tp;
}
}
}
*found = FALSE;
fill_dummy_ip4(addr, tp);
return tp;
}
static gchar *
host_name_lookup(const guint addr, gboolean *found)
{
hashipv4_t *tp;
tp = host_lookup(addr, TRUE, found);
return tp->name;
}
static hashipv6_t *
new_ipv6(const struct e_in6_addr *addr)
{
hashipv6_t *tp = g_malloc(sizeof(hashipv6_t));
tp->addr = *addr;
tp->next = NULL;
tp->resolve = FALSE;
tp->is_dummy_entry = FALSE;
ip6_to_str_buf(addr, tp->ip6);
return tp;
}
static hashipv6_t *
host_lookup6(const struct e_in6_addr *addr, const gboolean resolve, gboolean *found)
{
int hash_idx;
hashipv6_t * volatile tp;
#ifdef INET6
#ifdef HAVE_C_ARES
async_dns_queue_msg_t *caqm;
#endif
struct hostent *hostp;
#endif
*found = TRUE;
hash_idx = HASH_IPV6_ADDRESS(*addr);
tp = ipv6_table[hash_idx];
if( tp == NULL ) {
tp = ipv6_table[hash_idx] = new_ipv6(addr);
} else {
while(1) {
if( memcmp(&tp->addr, addr, sizeof (struct e_in6_addr)) == 0 ) {
if (tp->is_dummy_entry && !tp->resolve)
break;
if (tp->is_dummy_entry)
*found = FALSE;
return tp;
}
if (tp->next == NULL) {
tp->next = new_ipv6(addr);
tp = tp->next;
break;
}
tp = tp->next;
}
}
if (resolve) {
tp->resolve = TRUE;
#ifdef INET6
#ifdef HAVE_C_ARES
if ((gbl_resolv_flags & RESOLV_CONCURRENT) &&
prefs.name_resolve_concurrency > 0 &&
async_dns_initialized) {
caqm = g_malloc(sizeof(async_dns_queue_msg_t));
caqm->family = AF_INET6;
memcpy(&caqm->addr.ip6, addr, sizeof(caqm->addr.ip6));
async_dns_queue_head = g_list_append(async_dns_queue_head, (gpointer) caqm);
if (!tp->is_dummy_entry) {
g_strlcpy(tp->name, tp->ip6, MAXNAMELEN);
ip6_to_str_buf(addr, tp->name);
tp->is_dummy_entry = TRUE;
}
return tp;
}
#endif
hostp = gethostbyaddr((char *)addr, sizeof(*addr), AF_INET6);
if (hostp != NULL) {
g_strlcpy(tp->name, hostp->h_name, MAXNAMELEN);
tp->is_dummy_entry = FALSE;
return tp;
}
#endif
}
if (!tp->is_dummy_entry) {
tp->is_dummy_entry = TRUE;
g_strlcpy(tp->name, tp->ip6, MAXNAMELEN);
}
*found = FALSE;
return tp;
}
static const gchar *
solve_address_to_name(const address *addr)
{
switch (addr->type) {
case AT_ETHER:
return get_ether_name(addr->data);
case AT_IPv4: {
guint32 ip4_addr;
memcpy(&ip4_addr, addr->data, sizeof ip4_addr);
return get_hostname(ip4_addr);
}
case AT_IPv6: {
struct e_in6_addr ip6_addr;
memcpy(&ip6_addr.bytes, addr->data, sizeof ip6_addr.bytes);
return get_hostname6(&ip6_addr);
}
case AT_STRINGZ:
return addr->data;
default:
return NULL;
}
}
static const gchar *
se_solve_address_to_name(const address *addr)
{
switch (addr->type) {
case AT_ETHER:
return get_ether_name(addr->data);
case AT_IPv4: {
guint32 ip4_addr;
memcpy(&ip4_addr, addr->data, sizeof ip4_addr);
return get_hostname(ip4_addr);
}
case AT_IPv6: {
struct e_in6_addr ip6_addr;
memcpy(&ip6_addr.bytes, addr->data, sizeof ip6_addr.bytes);
return get_hostname6(&ip6_addr);
}
case AT_STRINGZ:
return se_strdup(addr->data);
default:
return NULL;
}
}
static gboolean
parse_ether_address(const char *cp, ether_t *eth, unsigned int *mask,
const gboolean manuf_file)
{
int i;
unsigned long num;
char *p;
char sep = '\0';
for (i = 0; i < 6; i++) {
if (!isxdigit((unsigned char)*cp))
return FALSE;
num = strtoul(cp, &p, 16);
if (p == cp)
return FALSE;
if (num > 0xFF)
return FALSE;
eth->addr[i] = (guint8) num;
cp = p;
if (*cp == '/') {
if (!manuf_file) {
return FALSE;
}
cp++;
if (!isdigit((unsigned char)*cp))
return FALSE;
num = strtoul(cp, &p, 10);
if (p == cp)
return FALSE;
cp = p;
if (*cp != '\0' && !isspace((unsigned char)*cp))
return FALSE;
if (num == 0 || num >= 48)
return FALSE;
*mask = num;
for (i = 0; num >= 8; i++, num -= 8)
;
eth->addr[i] &= (0xFF << (8 - num));
i++;
for (; i < 6; i++)
eth->addr[i] = 0;
return TRUE;
}
if (*cp == '\0') {
if (i == 2) {
if (!manuf_file) {
return FALSE;
}
*mask = 0;
return TRUE;
}
if (i == 5) {
if (manuf_file)
*mask = 48;
return TRUE;
}
return FALSE;
} else {
if (sep == '\0') {
if (*cp != ':' && *cp != '-' && *cp != '.')
return FALSE;
sep = *cp;
} else {
if (*cp != sep)
return FALSE;
}
}
cp++;
}
return TRUE;
}
static int
parse_ether_line(char *line, ether_t *eth, unsigned int *mask,
const gboolean manuf_file)
{
gchar *cp;
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
return -1;
if (!parse_ether_address(cp, eth, mask, manuf_file))
return -1;
if ((cp = strtok(NULL, " \t")) == NULL)
return -1;
g_strlcpy(eth->name, cp, MAXNAMELEN);
return 0;
}
static void
set_ethent(char *path)
{
if (eth_p)
rewind(eth_p);
else
eth_p = ws_fopen(path, "r");
}
static void
end_ethent(void)
{
if (eth_p) {
fclose(eth_p);
eth_p = NULL;
}
}
static ether_t *
get_ethent(unsigned int *mask, const gboolean manuf_file)
{
static ether_t eth;
static int size = 0;
static char *buf = NULL;
if (eth_p == NULL)
return NULL;
while (fgetline(&buf, &size, eth_p) >= 0) {
if (parse_ether_line(buf, &eth, mask, manuf_file) == 0) {
return &eth;
}
}
return NULL;
}
static ether_t *
get_ethbyname(const gchar *name)
{
ether_t *eth;
set_ethent(g_pethers_path);
while (((eth = get_ethent(NULL, FALSE)) != NULL) && strncmp(name, eth->name, MAXNAMELEN) != 0)
;
if (eth == NULL) {
end_ethent();
set_ethent(g_ethers_path);
while (((eth = get_ethent(NULL, FALSE)) != NULL) && strncmp(name, eth->name, MAXNAMELEN) != 0)
;
end_ethent();
}
return eth;
}
static ether_t *
get_ethbyaddr(const guint8 *addr)
{
ether_t *eth;
set_ethent(g_pethers_path);
while (((eth = get_ethent(NULL, FALSE)) != NULL) && memcmp(addr, eth->addr, 6) != 0)
;
if (eth == NULL) {
end_ethent();
set_ethent(g_ethers_path);
while (((eth = get_ethent(NULL, FALSE)) != NULL) && memcmp(addr, eth->addr, 6) != 0)
;
end_ethent();
}
return eth;
}
static int
hash_eth_wka(const guint8 *addr, unsigned int mask)
{
if (mask <= 8) {
return (addr[0] & (0xFF << (8 - mask))) & (HASHETHSIZE - 1);
}
mask -= 8;
if (mask <= 8) {
return ((addr[0] << 8) | (addr[1] & (0xFF << (8 - mask)))) &
(HASHETHSIZE - 1);
}
mask -= 8;
if (mask <= 8) {
return ((addr[0] << 16) | (addr[1] << 8) | (addr[2] & (0xFF << (8 - mask))))
& (HASHETHSIZE - 1);
}
mask -= 8;
if (mask <= 8) {
return ((((addr[0] << 8) | addr[1]) ^
((addr[2] << 8) | (addr[3] & (0xFF << (8 - mask)))))) &
(HASHETHSIZE - 1);
}
mask -= 8;
if (mask <= 8) {
return ((((addr[1] << 8) | addr[2]) ^
((addr[3] << 8) | (addr[4] & (0xFF << (8 - mask)))))) &
(HASHETHSIZE - 1);
}
mask -= 8;
return ((((addr[1] << 8) | addr[2]) ^
((addr[3] << 8) | (addr[4] & (0xFF << (8 - mask)))))) &
(HASHETHSIZE - 1);
}
static hashmanuf_t *
manuf_hash_new_entry(const guint8 *addr, gchar *name)
{
hashmanuf_t *mtp;
mtp = (hashmanuf_t *)g_malloc(sizeof(hashmanuf_t));
memcpy(mtp->addr, addr, sizeof(mtp->addr));
mtp->name = g_strdup(name);
mtp->next = NULL;
return mtp;
}
static hashwka_t *
wka_hash_new_entry(const guint8 *addr, gchar *name)
{
hashwka_t *wtp;
wtp = (hashwka_t *)g_malloc(sizeof(hashwka_t));
memcpy(wtp->addr, addr, sizeof(wtp->addr));
g_strlcpy(wtp->name, name, MAXNAMELEN);
wtp->next = NULL;
return wtp;
}
static void
add_manuf_name(const guint8 *addr, unsigned int mask, gchar *name)
{
gint hash_idx;
hashmanuf_t *mtp;
hashwka_t *(*wka_tp)[HASHETHSIZE], *wtp;
if (mask >= 48) {
add_eth_name(addr, name);
return;
}
if (mask == 0) {
hash_idx = HASH_ETH_MANUF(addr);
mtp = manuf_table[hash_idx];
if( mtp == NULL ) {
manuf_table[hash_idx] = manuf_hash_new_entry(addr, name);
return;
} else {
while(TRUE) {
if (mtp->next == NULL) {
mtp->next = manuf_hash_new_entry(addr, name);
return;
}
mtp = mtp->next;
}
}
}
wka_tp = wka_table[mask];
if (wka_tp == NULL)
wka_tp = wka_table[mask] = g_malloc0(sizeof *wka_table[mask]);
hash_idx = hash_eth_wka(addr, mask);
wtp = (*wka_tp)[hash_idx];
if( wtp == NULL ) {
(*wka_tp)[hash_idx] = wka_hash_new_entry(addr, name);
return;
} else {
while(TRUE) {
if (memcmp(wtp->addr, addr, sizeof(wtp->addr)) == 0) {
return;
}
if (wtp->next == NULL) {
wtp->next = wka_hash_new_entry(addr, name);
return;
}
wtp = wtp->next;
}
}
}
static hashmanuf_t *
manuf_name_lookup(const guint8 *addr)
{
gint hash_idx;
hashmanuf_t *mtp;
guint8 stripped_addr[3];
hash_idx = HASH_ETH_MANUF(addr);
mtp = manuf_table[hash_idx];
while(mtp != NULL) {
if (memcmp(mtp->addr, addr, sizeof(mtp->addr)) == 0) {
return mtp;
}
mtp = mtp->next;
}
memcpy(stripped_addr, addr, 3);
stripped_addr[0] &= 0xFE;
mtp = manuf_table[hash_idx];
while(mtp != NULL) {
if (memcmp(mtp->addr, stripped_addr, sizeof(mtp->addr)) == 0) {
return mtp;
}
mtp = mtp->next;
}
return NULL;
}
static hashwka_t *
wka_name_lookup(const guint8 *addr, const unsigned int mask)
{
gint hash_idx;
hashwka_t *(*wka_tp)[HASHETHSIZE];
hashwka_t *wtp;
guint8 masked_addr[6];
guint num;
gint i;
wka_tp = wka_table[mask];
if (wka_tp == NULL) {
return NULL;
}
for (i = 0, num = mask; num >= 8; i++, num -= 8)
masked_addr[i] = addr[i];
masked_addr[i] = addr[i] & (0xFF << (8 - num));
i++;
for (; i < 6; i++)
masked_addr[i] = 0;
hash_idx = hash_eth_wka(masked_addr, mask);
wtp = (*wka_tp)[hash_idx];
while(wtp != NULL) {
if (memcmp(wtp->addr, masked_addr, sizeof(wtp->addr)) == 0) {
return wtp;
}
wtp = wtp->next;
}
return NULL;
}
static void
initialize_ethers(void)
{
ether_t *eth;
char *manuf_path;
guint mask;
if (g_ethers_path == NULL) {
g_ethers_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_systemfile_dir(), ENAME_ETHERS);
}
if (g_pethers_path == NULL)
g_pethers_path = get_persconffile_path(ENAME_ETHERS, FALSE, FALSE);
manuf_path = get_datafile_path(ENAME_MANUF);
set_ethent(manuf_path);
while ((eth = get_ethent(&mask, TRUE))) {
add_manuf_name(eth->addr, mask, eth->name);
}
end_ethent();
g_free(manuf_path);
}
static hashether_t *
eth_addr_resolve(hashether_t *tp) {
ether_t *eth;
const guint8 *addr = tp->addr;
if ( (eth = get_ethbyaddr(addr)) != NULL) {
g_strlcpy(tp->resolved_name, eth->name, MAXNAMELEN);
tp->status = HASHETHER_STATUS_RESOLVED_NAME;
return tp;
} else {
hashwka_t *wtp;
hashmanuf_t *mtp;
guint mask;
mask = 7;
for (;;) {
if ((wtp = wka_name_lookup(addr, mask+40)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x",
wtp->name, addr[5] & (0xFF >> mask));
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
mask = 7;
for (;;) {
if ((wtp = wka_name_lookup(addr, mask+32)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x",
wtp->name, addr[4] & (0xFF >> mask), addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
mask = 7;
for (;;) {
if ((wtp = wka_name_lookup(addr, mask+24)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x",
wtp->name, addr[3] & (0xFF >> mask), addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
if ((mtp = manuf_name_lookup(addr)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x",
mtp->name, addr[3], addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
mask = 7;
for (;;) {
if ((wtp = wka_name_lookup(addr, mask+16)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x",
wtp->name, addr[2] & (0xFF >> mask), addr[3], addr[4],
addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
mask = 7;
for (;;) {
if ((wtp = wka_name_lookup(addr, mask+8)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x:%02x",
wtp->name, addr[1] & (0xFF >> mask), addr[2], addr[3],
addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
for (mask = 7; mask > 0; mask--) {
if ((wtp = wka_name_lookup(addr, mask)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x:%02x:%02x",
wtp->name, addr[0] & (0xFF >> mask), addr[1], addr[2],
addr[3], addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
}
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s", ether_to_str(addr));
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
g_assert_not_reached();
}
static hashether_t *
eth_hash_new_entry(const guint8 *addr, const gboolean resolve) {
hashether_t *tp;
tp = (hashether_t *)g_malloc(sizeof(hashether_t));
memcpy(tp->addr, addr, sizeof(tp->addr));
tp->status = HASHETHER_STATUS_UNRESOLVED;
g_strlcpy(tp->hexaddr, bytestring_to_str(addr, sizeof(tp->addr), ':'), sizeof(tp->hexaddr));
tp->resolved_name[0] = '\0';
tp->next = NULL;
if (resolve)
eth_addr_resolve(tp);
return tp;
}
static hashether_t *
add_eth_name(const guint8 *addr, const gchar *name)
{
gint hash_idx;
hashether_t *tp;
hash_idx = HASH_ETH_ADDRESS(addr);
tp = eth_table[hash_idx];
if( tp == NULL ) {
tp = eth_table[hash_idx] = eth_hash_new_entry(addr, FALSE);
} else {
while(TRUE) {
if (memcmp(tp->addr, addr, sizeof(tp->addr)) == 0) {
if (tp->status == HASHETHER_STATUS_RESOLVED_NAME)
return tp;
break;
}
if (tp->next == NULL) {
tp = tp->next = eth_hash_new_entry(addr, FALSE);
break;
}
tp = tp->next;
}
}
g_strlcpy(tp->resolved_name, name, MAXNAMELEN);
tp->status = HASHETHER_STATUS_RESOLVED_NAME;
new_resolved_objects = TRUE;
return tp;
}
static hashether_t *
eth_name_lookup(const guint8 *addr, const gboolean resolve) {
gint hash_idx;
hashether_t *tp;
hash_idx = HASH_ETH_ADDRESS(addr);
tp = eth_table[hash_idx];
if( tp == NULL ) {
tp = eth_table[hash_idx] = eth_hash_new_entry(addr, resolve);
return tp;
} else {
while(TRUE) {
if (memcmp(tp->addr, addr, sizeof(tp->addr)) == 0) {
if (resolve && (tp->status == HASHETHER_STATUS_UNRESOLVED))
eth_addr_resolve(tp);
return tp;
}
if (tp->next == NULL) {
tp->next = eth_hash_new_entry(addr, resolve);
return tp->next;
}
tp = tp->next;
}
}
}
static guint8 *
eth_addr_lookup(const gchar *name)
{
ether_t *eth;
hashether_t *tp;
hashether_t **table = eth_table;
gint i;
for (i = 0; i < HASHETHSIZE; i++) {
tp = table[i];
while (tp) {
if (strcmp(tp->resolved_name, name) == 0)
return tp->addr;
tp = tp->next;
}
}
if ((eth = get_ethbyname(name)) == NULL)
return NULL;
tp = add_eth_name(eth->addr, name);
return tp->addr;
}
static int
parse_ipxnets_line(char *line, ipxnet_t *ipxnet)
{
gchar *cp;
guint32 a, a0, a1, a2, a3;
gboolean found_single_number = FALSE;
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t\n")) == NULL)
return -1;
if (sscanf(cp, "%x:%x:%x:%x", &a0, &a1, &a2, &a3) != 4) {
if (sscanf(cp, "%x-%x-%x-%x", &a0, &a1, &a2, &a3) != 4) {
if (sscanf(cp, "%x.%x.%x.%x", &a0, &a1, &a2, &a3) != 4) {
if (sscanf(cp, "%x", &a) == 1) {
found_single_number = TRUE;
}
else {
return -1;
}
}
}
}
if ((cp = strtok(NULL, " \t\n")) == NULL)
return -1;
if (found_single_number) {
ipxnet->addr = a;
}
else {
ipxnet->addr = (a0 << 24) | (a1 << 16) | (a2 << 8) | a3;
}
g_strlcpy(ipxnet->name, cp, MAXNAMELEN);
return 0;
}
static void
set_ipxnetent(char *path)
{
if (ipxnet_p)
rewind(ipxnet_p);
else
ipxnet_p = ws_fopen(path, "r");
}
static void
end_ipxnetent(void)
{
if (ipxnet_p) {
fclose(ipxnet_p);
ipxnet_p = NULL;
}
}
static ipxnet_t *
get_ipxnetent(void)
{
static ipxnet_t ipxnet;
static int size = 0;
static char *buf = NULL;
if (ipxnet_p == NULL)
return NULL;
while (fgetline(&buf, &size, ipxnet_p) >= 0) {
if (parse_ipxnets_line(buf, &ipxnet) == 0) {
return &ipxnet;
}
}
return NULL;
}
static ipxnet_t *
get_ipxnetbyname(const gchar *name)
{
ipxnet_t *ipxnet;
set_ipxnetent(g_ipxnets_path);
while (((ipxnet = get_ipxnetent()) != NULL) && strncmp(name, ipxnet->name, MAXNAMELEN) != 0)
;
if (ipxnet == NULL) {
end_ipxnetent();
set_ipxnetent(g_pipxnets_path);
while (((ipxnet = get_ipxnetent()) != NULL) && strncmp(name, ipxnet->name, MAXNAMELEN) != 0)
;
end_ipxnetent();
}
return ipxnet;
}
static ipxnet_t *
get_ipxnetbyaddr(guint32 addr)
{
ipxnet_t *ipxnet;
set_ipxnetent(g_ipxnets_path);
while (((ipxnet = get_ipxnetent()) != NULL) && (addr != ipxnet->addr) ) ;
if (ipxnet == NULL) {
end_ipxnetent();
set_ipxnetent(g_pipxnets_path);
while (((ipxnet = get_ipxnetent()) != NULL) && (addr != ipxnet->addr) )
;
end_ipxnetent();
}
return ipxnet;
}
static void
initialize_ipxnets(void)
{
if (g_ipxnets_path == NULL) {
g_ipxnets_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_systemfile_dir(), ENAME_IPXNETS);
}
if (g_pipxnets_path == NULL)
g_pipxnets_path = get_persconffile_path(ENAME_IPXNETS, FALSE, FALSE);
}
static hashipxnet_t *
add_ipxnet_name(guint addr, const gchar *name)
{
int hash_idx;
hashipxnet_t *tp;
hash_idx = HASH_IPX_NET(addr);
tp = ipxnet_table[hash_idx];
if( tp == NULL ) {
tp = ipxnet_table[hash_idx] = (hashipxnet_t *)g_malloc(sizeof(hashipxnet_t));
} else {
while(1) {
if (tp->next == NULL) {
tp->next = (hashipxnet_t *)g_malloc(sizeof(hashipxnet_t));
tp = tp->next;
break;
}
tp = tp->next;
}
}
tp->addr = addr;
g_strlcpy(tp->name, name, MAXNAMELEN);
tp->next = NULL;
new_resolved_objects = TRUE;
return tp;
}
static gchar *
ipxnet_name_lookup(const guint addr)
{
int hash_idx;
hashipxnet_t *tp;
ipxnet_t *ipxnet;
hash_idx = HASH_IPX_NET(addr);
tp = ipxnet_table[hash_idx];
if( tp == NULL ) {
tp = ipxnet_table[hash_idx] = (hashipxnet_t *)g_malloc(sizeof(hashipxnet_t));
} else {
while(1) {
if (tp->addr == addr) {
return tp->name;
}
if (tp->next == NULL) {
tp->next = (hashipxnet_t *)g_malloc(sizeof(hashipxnet_t));
tp = tp->next;
break;
}
tp = tp->next;
}
}
tp->addr = addr;
tp->next = NULL;
if ( (ipxnet = get_ipxnetbyaddr(addr)) == NULL) {
g_snprintf(tp->name, MAXNAMELEN, "%X", addr);
} else {
g_strlcpy(tp->name, ipxnet->name, MAXNAMELEN);
}
return (tp->name);
}
static guint
ipxnet_addr_lookup(const gchar *name, gboolean *success)
{
ipxnet_t *ipxnet;
hashipxnet_t *tp;
hashipxnet_t **table = ipxnet_table;
int i;
for (i = 0; i < HASHIPXNETSIZE; i++) {
tp = table[i];
while (tp) {
if (strcmp(tp->name, name) == 0) {
*success = TRUE;
return tp->addr;
}
tp = tp->next;
}
}
if ((ipxnet = get_ipxnetbyname(name)) == NULL) {
*success = FALSE;
return 0;
}
tp = add_ipxnet_name(ipxnet->addr, name);
*success = TRUE;
return tp->addr;
}
gboolean
read_hosts_file (const char *hostspath)
{
FILE *hf;
char *line = NULL;
int size = 0;
gchar *cp;
guint32 host_addr[4];
struct e_in6_addr ip6_addr;
gboolean is_ipv6;
int ret;
if ((hf = ws_fopen(hostspath, "r")) == NULL)
return FALSE;
while (fgetline(&line, &size, hf) >= 0) {
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
continue;
ret = inet_pton(AF_INET6, cp, &host_addr);
if (ret == -1)
continue;
if (ret == 1) {
is_ipv6 = TRUE;
} else {
if (inet_pton(AF_INET, cp, &host_addr) != 1)
continue;
is_ipv6 = FALSE;
}
if ((cp = strtok(NULL, " \t")) == NULL)
continue;
if (is_ipv6) {
memcpy(&ip6_addr, host_addr, sizeof ip6_addr);
add_ipv6_name(&ip6_addr, cp);
} else
add_ipv4_name(host_addr[0], cp);
while ((cp = strtok(NULL, " \t")) != NULL) {
if (is_ipv6) {
memcpy(&ip6_addr, host_addr, sizeof ip6_addr);
add_ipv6_name(&ip6_addr, cp);
} else
add_ipv4_name(host_addr[0], cp);
}
}
g_free(line);
fclose(hf);
return TRUE;
}
gboolean
add_ip_name_from_string (const char *addr, const char *name)
{
guint32 host_addr[4];
struct e_in6_addr ip6_addr;
gboolean is_ipv6;
int ret;
ret = inet_pton(AF_INET6, addr, &ip6_addr);
if (ret == -1)
return FALSE;
if (ret == 1) {
is_ipv6 = TRUE;
} else {
if (inet_pton(AF_INET, addr, &host_addr) != 1)
return FALSE;
is_ipv6 = FALSE;
}
if (is_ipv6) {
add_ipv6_name(&ip6_addr, name);
} else {
add_ipv4_name(host_addr[0], name);
}
return TRUE;
}
struct addrinfo *
get_addrinfo_list(void) {
return addrinfo_list;
}
static gboolean
read_subnets_file (const char *subnetspath)
{
FILE *hf;
char *line = NULL;
int size = 0;
gchar *cp, *cp2;
guint32 host_addr;
int mask_length;
if ((hf = ws_fopen(subnetspath, "r")) == NULL)
return FALSE;
while (fgetline(&line, &size, hf) >= 0) {
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
continue;
cp2 = strchr(cp, '/');
if(NULL == cp2) {
continue;
}
*cp2 = '\0';
++cp2 ;
if (inet_pton(AF_INET, cp, &host_addr) != 1) {
continue;
}
mask_length = atoi(cp2);
if(0 >= mask_length || mask_length > 31) {
continue;
}
if ((cp = strtok(NULL, " \t")) == NULL)
continue;
subnet_entry_set(host_addr, (guint32)mask_length, cp);
}
g_free(line);
fclose(hf);
return TRUE;
}
static subnet_entry_t
subnet_lookup(const guint32 addr)
{
subnet_entry_t subnet_entry;
guint32 i;
i = SUBNETLENGTHSIZE;
while(have_subnet_entry && i > 0) {
guint32 masked_addr;
subnet_length_entry_t* length_entry;
--i;
g_assert(i < SUBNETLENGTHSIZE);
length_entry = &subnet_length_entries[i];
if(NULL != length_entry->subnet_addresses) {
hashipv4_t * tp;
guint32 hash_idx;
masked_addr = addr & length_entry->mask;
hash_idx = HASH_IPV4_ADDRESS(masked_addr);
tp = length_entry->subnet_addresses[hash_idx];
while(tp != NULL && tp->addr != masked_addr) {
tp = tp->next;
}
if(NULL != tp) {
subnet_entry.mask = length_entry->mask;
subnet_entry.mask_length = i + 1;
subnet_entry.name = tp->name;
return subnet_entry;
}
}
}
subnet_entry.mask = 0;
subnet_entry.mask_length = 0;
subnet_entry.name = NULL;
return subnet_entry;
}
static void
subnet_entry_set(guint32 subnet_addr, const guint32 mask_length, const gchar* name)
{
subnet_length_entry_t* entry;
hashipv4_t * tp;
gsize hash_idx;
g_assert(mask_length > 0 && mask_length <= 32);
entry = &subnet_length_entries[mask_length - 1];
subnet_addr &= entry->mask;
hash_idx = HASH_IPV4_ADDRESS(subnet_addr);
if(NULL == entry->subnet_addresses) {
entry->subnet_addresses = g_new0(hashipv4_t*,HASHHOSTSIZE);
}
if(NULL != (tp = entry->subnet_addresses[hash_idx])) {
if(tp->addr == subnet_addr) {
return;
} else {
hashipv4_t * new_tp = g_new(hashipv4_t,1);
tp->next = new_tp;
tp = new_tp;
}
} else {
tp = entry->subnet_addresses[hash_idx] = g_new(hashipv4_t,1);
}
tp->next = NULL;
tp->addr = subnet_addr;
tp->is_dummy_entry = FALSE;
g_strlcpy(tp->name, name, MAXNAMELEN);
have_subnet_entry = TRUE;
}
static guint32
get_subnet_mask(const guint32 mask_length) {
static guint32 masks[SUBNETLENGTHSIZE];
static gboolean initialised = FALSE;
if(!initialised) {
memset(masks, 0, sizeof(masks));
initialised = TRUE;
inet_pton(AF_INET, "128.0.0.0", &masks[0]);
inet_pton(AF_INET, "192.0.0.0", &masks[1]);
inet_pton(AF_INET, "224.0.0.0", &masks[2]);
inet_pton(AF_INET, "240.0.0.0", &masks[3]);
inet_pton(AF_INET, "248.0.0.0", &masks[4]);
inet_pton(AF_INET, "252.0.0.0", &masks[5]);
inet_pton(AF_INET, "254.0.0.0", &masks[6]);
inet_pton(AF_INET, "255.0.0.0", &masks[7]);
inet_pton(AF_INET, "255.128.0.0", &masks[8]);
inet_pton(AF_INET, "255.192.0.0", &masks[9]);
inet_pton(AF_INET, "255.224.0.0", &masks[10]);
inet_pton(AF_INET, "255.240.0.0", &masks[11]);
inet_pton(AF_INET, "255.248.0.0", &masks[12]);
inet_pton(AF_INET, "255.252.0.0", &masks[13]);
inet_pton(AF_INET, "255.254.0.0", &masks[14]);
inet_pton(AF_INET, "255.255.0.0", &masks[15]);
inet_pton(AF_INET, "255.255.128.0", &masks[16]);
inet_pton(AF_INET, "255.255.192.0", &masks[17]);
inet_pton(AF_INET, "255.255.224.0", &masks[18]);
inet_pton(AF_INET, "255.255.240.0", &masks[19]);
inet_pton(AF_INET, "255.255.248.0", &masks[20]);
inet_pton(AF_INET, "255.255.252.0", &masks[21]);
inet_pton(AF_INET, "255.255.254.0", &masks[22]);
inet_pton(AF_INET, "255.255.255.0", &masks[23]);
inet_pton(AF_INET, "255.255.255.128", &masks[24]);
inet_pton(AF_INET, "255.255.255.192", &masks[25]);
inet_pton(AF_INET, "255.255.255.224", &masks[26]);
inet_pton(AF_INET, "255.255.255.240", &masks[27]);
inet_pton(AF_INET, "255.255.255.248", &masks[28]);
inet_pton(AF_INET, "255.255.255.252", &masks[29]);
inet_pton(AF_INET, "255.255.255.254", &masks[30]);
inet_pton(AF_INET, "255.255.255.255", &masks[31]);
}
if(mask_length == 0 || mask_length > SUBNETLENGTHSIZE) {
g_assert_not_reached();
return 0;
} else {
return masks[mask_length - 1];
}
}
static void
subnet_name_lookup_init(void)
{
gchar* subnetspath;
guint32 i;
for(i = 0; i < SUBNETLENGTHSIZE; ++i) {
guint32 length = i + 1;
subnet_length_entries[i].subnet_addresses = NULL;
subnet_length_entries[i].mask_length = length;
subnet_length_entries[i].mask = get_subnet_mask(length);
}
subnetspath = get_persconffile_path(ENAME_SUBNETS, FALSE, FALSE);
if (!read_subnets_file(subnetspath) && errno != ENOENT) {
report_open_failure(subnetspath, errno, FALSE);
}
g_free(subnetspath);
subnetspath = get_datafile_path(ENAME_SUBNETS);
if (!read_subnets_file(subnetspath) && errno != ENOENT) {
report_open_failure(subnetspath, errno, FALSE);
}
g_free(subnetspath);
}
void
host_name_lookup_init(void) {
char *hostspath;
struct addrinfo *ai;
#ifdef HAVE_GNU_ADNS
#ifdef _WIN32
char *sysroot;
static char rootpath_nt[] = "\\system32\\drivers\\etc\\hosts";
static char rootpath_ot[] = "\\hosts";
#endif
#endif
if (!addrinfo_list) {
ai = g_malloc0(sizeof(struct addrinfo));
addrinfo_list = addrinfo_list_last = ai;
}
hostspath = get_persconffile_path(ENAME_HOSTS, FALSE, FALSE);
if (!read_hosts_file(hostspath) && errno != ENOENT) {
report_open_failure(hostspath, errno, FALSE);
}
g_free(hostspath);
hostspath = get_datafile_path(ENAME_HOSTS);
if (!read_hosts_file(hostspath) && errno != ENOENT) {
report_open_failure(hostspath, errno, FALSE);
}
g_free(hostspath);
#ifdef HAVE_C_ARES
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
if (ares_library_init(ARES_LIB_INIT_ALL) == ARES_SUCCESS) {
#endif
if (ares_init(&ghba_chan) == ARES_SUCCESS && ares_init(&ghbn_chan) == ARES_SUCCESS) {
async_dns_initialized = TRUE;
}
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
}
#endif
#else
#ifdef HAVE_GNU_ADNS
#ifdef _WIN32
sysroot = getenv_utf8("WINDIR");
if (sysroot != NULL) {
hostspath = g_strconcat(sysroot, rootpath_nt, NULL);
if (!read_hosts_file(hostspath)) {
g_free(hostspath);
hostspath = g_strconcat(sysroot, rootpath_ot, NULL);
read_hosts_file(hostspath);
}
g_free(hostspath);
}
#else
read_hosts_file("/etc/hosts");
#endif
if (adns_init(&ads, 0, 0 ) != 0) {
return;
}
async_dns_initialized = TRUE;
async_dns_in_flight = 0;
#endif
#endif
subnet_name_lookup_init();
}
gboolean
host_name_lookup_process(gpointer data _U_) {
async_dns_queue_msg_t *caqm;
struct timeval tv = { 0, 0 };
int nfds;
fd_set rfds, wfds;
gboolean nro = new_resolved_objects;
new_resolved_objects = FALSE;
if (!async_dns_initialized)
return nro;
async_dns_queue_head = g_list_first(async_dns_queue_head);
while (async_dns_queue_head != NULL && async_dns_in_flight <= prefs.name_resolve_concurrency) {
caqm = (async_dns_queue_msg_t *) async_dns_queue_head->data;
async_dns_queue_head = g_list_remove(async_dns_queue_head, (void *) caqm);
if (caqm->family == AF_INET) {
ares_gethostbyaddr(ghba_chan, &caqm->addr.ip4, sizeof(guint32), AF_INET,
c_ares_ghba_cb, caqm);
async_dns_in_flight++;
} else if (caqm->family == AF_INET6) {
ares_gethostbyaddr(ghba_chan, &caqm->addr.ip6, sizeof(struct e_in6_addr),
AF_INET6, c_ares_ghba_cb, caqm);
async_dns_in_flight++;
}
}
FD_ZERO(&rfds);
FD_ZERO(&wfds);
nfds = ares_fds(ghba_chan, &rfds, &wfds);
if (nfds > 0) {
select(nfds, &rfds, &wfds, NULL, &tv);
ares_process(ghba_chan, &rfds, &wfds);
}
return nro;
}
void
host_name_lookup_cleanup(void) {
GList *cur;
cur = g_list_first(async_dns_queue_head);
while (cur) {
g_free(cur->data);
cur = g_list_next (cur);
}
g_list_free(async_dns_queue_head);
if (async_dns_initialized) {
ares_destroy(ghba_chan);
ares_destroy(ghbn_chan);
}
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
ares_library_cleanup();
#endif
async_dns_initialized = FALSE;
}
gboolean
host_name_lookup_process(gpointer data _U_) {
async_dns_queue_msg_t *almsg;
GList *cur;
char addr_str[] = "111.222.333.444.in-addr.arpa.";
guint8 *addr_bytes;
adns_answer *ans;
int ret;
gboolean dequeue;
gboolean nro = new_resolved_objects;
new_resolved_objects = FALSE;
async_dns_queue_head = g_list_first(async_dns_queue_head);
cur = async_dns_queue_head;
while (cur && async_dns_in_flight <= prefs.name_resolve_concurrency) {
almsg = (async_dns_queue_msg_t *) cur->data;
if (! almsg->submitted && almsg->type == AF_INET) {
addr_bytes = (guint8 *) &almsg->ip4_addr;
g_snprintf(addr_str, sizeof addr_str, "%u.%u.%u.%u.in-addr.arpa.", addr_bytes[3],
addr_bytes[2], addr_bytes[1], addr_bytes[0]);
adns_submit (ads, addr_str, adns_r_ptr, 0, NULL, &almsg->query);
almsg->submitted = TRUE;
async_dns_in_flight++;
}
cur = cur->next;
}
cur = async_dns_queue_head;
while (cur) {
dequeue = FALSE;
almsg = (async_dns_queue_msg_t *) cur->data;
if (almsg->submitted) {
ret = adns_check(ads, &almsg->query, &ans, NULL);
if (ret == 0) {
if (ans->status == adns_s_ok) {
add_ipv4_name(almsg->ip4_addr, *ans->rrs.str);
}
dequeue = TRUE;
}
}
cur = cur->next;
if (dequeue) {
async_dns_queue_head = g_list_remove(async_dns_queue_head, (void *) almsg);
g_free(almsg);
async_dns_in_flight--;
}
}
return nro;
}
void
host_name_lookup_cleanup(void) {
void *qdata;
async_dns_queue_head = g_list_first(async_dns_queue_head);
while (async_dns_queue_head) {
qdata = async_dns_queue_head->data;
async_dns_queue_head = g_list_remove(async_dns_queue_head, qdata);
g_free(qdata);
}
if (async_dns_initialized)
adns_finish(ads);
async_dns_initialized = FALSE;
}
gboolean
host_name_lookup_process(gpointer data _U_) {
gboolean nro = new_resolved_objects;
new_resolved_objects = FALSE;
return nro;
}
void
host_name_lookup_cleanup(void) {
}
const gchar *
get_hostname(const guint addr)
{
gboolean found;
gboolean resolve = gbl_resolv_flags & RESOLV_NETWORK;
hashipv4_t *tp = host_lookup(addr, resolve, &found);
if (!resolve)
return tp->ip;
return tp->name;
}
const gchar *
get_hostname6(const struct e_in6_addr *addr)
{
gboolean found;
gboolean resolve = gbl_resolv_flags & RESOLV_NETWORK;
hashipv6_t *tp = host_lookup6(addr, resolve, &found);
if (!resolve)
return tp->ip6;
return tp->name;
}
void
add_ipv4_name(const guint addr, const gchar *name)
{
int hash_idx;
hashipv4_t *tp;
struct addrinfo *ai;
struct sockaddr_in *sa4;
hash_idx = HASH_IPV4_ADDRESS(addr);
tp = ipv4_table[hash_idx];
if( tp == NULL ) {
tp = ipv4_table[hash_idx] = new_ipv4(addr);
} else {
while(1) {
if (tp->addr == addr) {
if (!tp->is_dummy_entry) {
return;
} else {
break;
}
}
if (tp->next == NULL) {
tp->next = new_ipv4(addr);
tp = tp->next;
break;
}
tp = tp->next;
}
}
g_strlcpy(tp->name, name, MAXNAMELEN);
tp->resolve = TRUE;
new_resolved_objects = TRUE;
if (!addrinfo_list) {
ai = g_malloc0(sizeof(struct addrinfo));
addrinfo_list = addrinfo_list_last = ai;
}
sa4 = g_malloc0(sizeof(struct sockaddr_in));
sa4->sin_family = AF_INET;
sa4->sin_addr.s_addr = addr;
ai = g_malloc0(sizeof(struct addrinfo));
ai->ai_family = AF_INET;
ai->ai_addrlen = sizeof(struct sockaddr_in);
ai->ai_canonname = (char *) tp->name;
ai->ai_addr = (struct sockaddr*) sa4;
addrinfo_list_last->ai_next = ai;
addrinfo_list_last = ai;
}
void
add_ipv6_name(const struct e_in6_addr *addrp, const gchar *name)
{
int hash_idx;
hashipv6_t *tp;
struct addrinfo *ai;
struct sockaddr_in6 *sa6;
hash_idx = HASH_IPV6_ADDRESS(*addrp);
tp = ipv6_table[hash_idx];
if( tp == NULL ) {
tp = ipv6_table[hash_idx] = new_ipv6(addrp);
} else {
while(1) {
if (memcmp(&tp->addr, addrp, sizeof (struct e_in6_addr)) == 0) {
if (!tp->is_dummy_entry) {
return;
} else {
break;
}
}
if (tp->next == NULL) {
tp->next = new_ipv6(addrp);
tp = tp->next;
break;
}
tp = tp->next;
}
}
g_strlcpy(tp->name, name, MAXNAMELEN);
tp->resolve = TRUE;
new_resolved_objects = TRUE;
if (!addrinfo_list) {
ai = g_malloc0(sizeof(struct addrinfo));
addrinfo_list = addrinfo_list_last = ai;
}
sa6 = g_malloc0(sizeof(struct sockaddr_in6));
sa6->sin6_family = AF_INET;
memcpy(sa6->sin6_addr.s6_addr, addrp, 16);
ai = g_malloc0(sizeof(struct addrinfo));
ai->ai_family = AF_INET6;
ai->ai_addrlen = sizeof(struct sockaddr_in);
ai->ai_canonname = (char *) tp->name;
ai->ai_addr = (struct sockaddr *) sa6;
addrinfo_list_last->ai_next = ai;
addrinfo_list_last = ai;
}
static gchar *
ep_utoa(guint port)
{
gchar *bp = ep_alloc(MAXNAMELEN);
guint32_to_str_buf(port, bp, MAXNAMELEN);
return bp;
}
gchar *
get_udp_port(guint port)
{
if (!(gbl_resolv_flags & RESOLV_TRANSPORT)) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_UDP);
}
gchar *
get_dccp_port(guint port)
{
if (!(gbl_resolv_flags & RESOLV_TRANSPORT)) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_DCCP);
}
gchar *
get_tcp_port(guint port)
{
if (!(gbl_resolv_flags & RESOLV_TRANSPORT)) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_TCP);
}
gchar *
get_sctp_port(guint port)
{
if (!(gbl_resolv_flags & RESOLV_TRANSPORT)) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_SCTP);
}
const gchar *
get_addr_name(const address *addr)
{
const gchar *result;
result = solve_address_to_name(addr);
if (result != NULL)
return result;
if (addr->type == AT_NONE){
return "NONE";
}
return ep_address_to_str(addr);
}
const gchar *
se_get_addr_name(const address *addr)
{
const gchar *result;
result = se_solve_address_to_name(addr);
if (result != NULL)
return result;
if (addr->type == AT_NONE){
return "NONE";
}
return se_address_to_str(addr);
}
void
get_addr_name_buf(const address *addr, gchar *buf, gsize size)
{
const gchar *result = get_addr_name(addr);
g_strlcpy(buf, result, size);
}
gchar *
get_ether_name(const guint8 *addr)
{
hashether_t *tp;
gboolean resolve = (gbl_resolv_flags & RESOLV_MAC) != 0;
if (resolve && !eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
tp = eth_name_lookup(addr, resolve);
return resolve ? tp->resolved_name : tp->hexaddr;
}
gchar *
get_ether_name_if_known(const guint8 *addr)
{
hashether_t *tp;
if (!(gbl_resolv_flags & RESOLV_MAC))
return NULL;
if (!eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
tp = eth_name_lookup(addr, TRUE);
g_assert(tp != NULL);
if (tp->status == HASHETHER_STATUS_RESOLVED_NAME) {
return tp->resolved_name;
}
else {
return NULL;
}
}
guint8 *
get_ether_addr(const gchar *name)
{
if (!eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
return eth_addr_lookup(name);
}
void
add_ether_byip(const guint ip, const guint8 *eth)
{
gchar *host;
gboolean found;
if (!(gbl_resolv_flags & RESOLV_NETWORK))
return;
if ((host = host_name_lookup(ip, &found)) == NULL)
return;
if (found)
add_eth_name(eth, host);
}
const gchar *
get_ipxnet_name(const guint32 addr)
{
if (!(gbl_resolv_flags & RESOLV_NETWORK)) {
return ipxnet_to_str_punct(addr, '\0');
}
if (!ipxnet_resolution_initialized) {
initialize_ipxnets();
ipxnet_resolution_initialized = 1;
}
return ipxnet_name_lookup(addr);
}
guint32
get_ipxnet_addr(const gchar *name, gboolean *known)
{
guint32 addr;
gboolean success;
if (!ipxnet_resolution_initialized) {
initialize_ipxnets();
ipxnet_resolution_initialized = 1;
}
addr = ipxnet_addr_lookup(name, &success);
*known = success;
return addr;
}
const gchar *
get_manuf_name(const guint8 *addr)
{
gchar *cur;
hashmanuf_t *mtp;
if ((gbl_resolv_flags & RESOLV_MAC) && !eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
if (!(gbl_resolv_flags & RESOLV_MAC) || ((mtp = manuf_name_lookup(addr)) == NULL)) {
cur=ep_strdup_printf("%02x:%02x:%02x", addr[0], addr[1], addr[2]);
return cur;
}
return mtp->name;
}
const gchar *
uint_get_manuf_name(const guint oid)
{
guint8 addr[3];
addr[0] = (oid >> 16) & 0xFF;
addr[1] = (oid >> 8) & 0xFF;
addr[2] = (oid >> 0) & 0xFF;
return get_manuf_name(addr);
}
const gchar *
tvb_get_manuf_name(tvbuff_t *tvb, gint offset)
{
return get_manuf_name(tvb_get_ptr(tvb, offset, 3));
}
const gchar *
get_manuf_name_if_known(const guint8 *addr)
{
hashmanuf_t *mtp;
if (!eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
if ((mtp = manuf_name_lookup(addr)) == NULL) {
return NULL;
}
return mtp->name;
}
const gchar *
uint_get_manuf_name_if_known(const guint oid)
{
guint8 addr[3];
addr[0] = (oid >> 16) & 0xFF;
addr[1] = (oid >> 8) & 0xFF;
addr[2] = (oid >> 0) & 0xFF;
return get_manuf_name_if_known(addr);
}
const gchar *
tvb_get_manuf_name_if_known(tvbuff_t *tvb, gint offset)
{
return get_manuf_name_if_known(tvb_get_ptr(tvb, offset, 3));
}
const gchar *
get_eui64_name(const guint64 addr_eui64)
{
gchar *cur;
hashmanuf_t *mtp;
guint8 *addr = ep_alloc(8);
*(guint64 *)(void *)(addr) = pntoh64(&(addr_eui64));
if ((gbl_resolv_flags & RESOLV_MAC) && !eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
if (!(gbl_resolv_flags & RESOLV_MAC) || ((mtp = manuf_name_lookup(addr)) == NULL)) {
cur=ep_strdup_printf("%02x:%02x:%02x%02x:%02x:%02x%02x:%02x", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
cur=ep_strdup_printf("%s_%02x:%02x:%02x:%02x:%02x", mtp->name, addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
const gchar *
get_eui64_name_if_known(const guint64 addr_eui64)
{
gchar *cur;
hashmanuf_t *mtp;
guint8 *addr = ep_alloc(8);
*(guint64 *)(void *)(addr) = pntoh64(&(addr_eui64));
if (!eth_resolution_initialized) {
initialize_ethers();
eth_resolution_initialized = TRUE;
}
if ((mtp = manuf_name_lookup(addr)) == NULL) {
return NULL;
}
cur=ep_strdup_printf("%s_%02x:%02x:%02x:%02x:%02x", mtp->name, addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
gboolean
get_host_ipaddr(const char *host, guint32 *addrp)
{
struct in_addr ipaddr;
#ifdef HAVE_C_ARES
struct timeval tv = { 0, GHI_TIMEOUT }, *tvp;
int nfds;
fd_set rfds, wfds;
async_hostent_t ahe;
#else
struct hostent *hp;
#endif
if (!inet_aton(host, &ipaddr)) {
if (! (gbl_resolv_flags & RESOLV_NETWORK)) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (! (gbl_resolv_flags & RESOLV_CONCURRENT) ||
prefs.name_resolve_concurrency < 1 ||
! async_dns_initialized) {
return FALSE;
}
ahe.addr_size = (int) sizeof (struct in_addr);
ahe.copied = 0;
ahe.addrp = addrp;
ares_gethostbyname(ghbn_chan, host, AF_INET, c_ares_ghi_cb, &ahe);
FD_ZERO(&rfds);
FD_ZERO(&wfds);
nfds = ares_fds(ghbn_chan, &rfds, &wfds);
if (nfds > 0) {
tvp = ares_timeout(ghbn_chan, &tv, &tv);
select(nfds, &rfds, &wfds, NULL, tvp);
ares_process(ghbn_chan, &rfds, &wfds);
}
ares_cancel(ghbn_chan);
if (ahe.addr_size == ahe.copied) {
return TRUE;
}
return FALSE;
#else
hp = gethostbyname(host);
if (hp == NULL) {
return FALSE;
} else if (hp->h_length <= (int) sizeof (struct in_addr)) {
memcpy(&ipaddr, hp->h_addr, hp->h_length);
} else {
return FALSE;
}
#endif
} else {
unsigned int a0, a1, a2, a3;
if (sscanf(host, "%u.%u.%u.%u", &a0, &a1, &a2, &a3) != 4)
return FALSE;
}
*addrp = ipaddr.s_addr;
return TRUE;
}
gboolean
get_host_ipaddr6(const char *host, struct e_in6_addr *addrp)
{
#ifdef HAVE_C_ARES
struct timeval tv = { 0, GHI_TIMEOUT }, *tvp;
int nfds;
fd_set rfds, wfds;
async_hostent_t ahe;
#elif defined(HAVE_GETHOSTBYNAME2)
struct hostent *hp;
#endif
if (inet_pton(AF_INET6, host, addrp) == 1)
return TRUE;
if (! (gbl_resolv_flags & RESOLV_NETWORK)) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (! (gbl_resolv_flags & RESOLV_CONCURRENT) ||
prefs.name_resolve_concurrency < 1 ||
! async_dns_initialized) {
return FALSE;
}
ahe.addr_size = (int) sizeof (struct e_in6_addr);
ahe.copied = 0;
ahe.addrp = addrp;
ares_gethostbyname(ghbn_chan, host, AF_INET6, c_ares_ghi_cb, &ahe);
FD_ZERO(&rfds);
FD_ZERO(&wfds);
nfds = ares_fds(ghbn_chan, &rfds, &wfds);
if (nfds > 0) {
tvp = ares_timeout(ghbn_chan, &tv, &tv);
select(nfds, &rfds, &wfds, NULL, tvp);
ares_process(ghbn_chan, &rfds, &wfds);
}
ares_cancel(ghbn_chan);
if (ahe.addr_size == ahe.copied) {
return TRUE;
}
#elif defined(HAVE_GETHOSTBYNAME2)
hp = gethostbyname2(host, AF_INET6);
if (hp != NULL && hp->h_length == sizeof(struct e_in6_addr)) {
memcpy(addrp, hp->h_addr, hp->h_length);
return TRUE;
}
#endif
return FALSE;
}
const char* host_ip_af(const char *host
#ifndef HAVE_GETHOSTBYNAME2
_U_
#endif
)
{
#ifdef HAVE_GETHOSTBYNAME2
struct hostent *h;
return (h = gethostbyname2(host, AF_INET6)) && h->h_addrtype == AF_INET6 ? "ip6" : "ip";
#else
return "ip";
#endif
}
