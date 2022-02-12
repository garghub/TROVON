static guint32
ipv6_oat_hash(gconstpointer key)
{
int len = 16;
const unsigned char *p = (const unsigned char *)key;
guint32 h = 0;
int i;
for ( i = 0; i < len; i++ ) {
h += p[i];
h += ( h << 10 );
h ^= ( h >> 6 );
}
h += ( h << 3 );
h ^= ( h >> 11 );
h += ( h << 15 );
return h;
}
static gboolean
ipv6_equal(gconstpointer v1, gconstpointer v2)
{
if( memcmp(v1, v2, sizeof (struct e_in6_addr)) == 0 ) {
return TRUE;
}
return FALSE;
}
static void
add_async_dns_ipv4(int type, guint32 addr)
{
async_dns_queue_msg_t *msg;
msg = g_new(async_dns_queue_msg_t,1);
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
*buf = (char *)g_malloc(*size);
}
g_assert(*buf);
g_assert(*size > 0);
if (feof(fp))
return -1;
len = 0;
while ((c = getc(fp)) != EOF && c != '\r' && c != '\n') {
if (len+1 >= *size) {
*buf = (char *)g_realloc(*buf, *size += BUFSIZ);
}
(*buf)[len++] = c;
}
if (len == 0 && c == EOF)
return -1;
(*buf)[len] = '\0';
return len;
}
static void
add_service_name(port_type proto, const guint port, const char *service_name)
{
serv_port_t *serv_port_table;
int *key;
key = (int *)g_new(int, 1);
*key = port;
serv_port_table = (serv_port_t *)g_hash_table_lookup(serv_port_hashtable, &port);
if (serv_port_table == NULL) {
serv_port_table = g_new0(serv_port_t,1);
g_hash_table_insert(serv_port_hashtable, key, serv_port_table);
}
else {
g_free(key);
}
switch(proto){
case PT_TCP:
g_free(serv_port_table->tcp_name);
serv_port_table->tcp_name = g_strdup(service_name);
break;
case PT_UDP:
g_free(serv_port_table->udp_name);
serv_port_table->udp_name = g_strdup(service_name);
break;
case PT_SCTP:
g_free(serv_port_table->sctp_name);
serv_port_table->sctp_name = g_strdup(service_name);
break;
case PT_DCCP:
g_free(serv_port_table->dccp_name);
serv_port_table->dccp_name = g_strdup(service_name);
break;
default:
return;
}
new_resolved_objects = TRUE;
}
static void
parse_service_line (char *line)
{
gchar *cp;
gchar *service;
gchar *port;
port_type proto;
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
proto = PT_TCP;
}
else if(strcmp(cp, "udp") == 0) {
max_port = MAX_UDP_PORT;
proto = PT_UDP;
}
else if(strcmp(cp, "sctp") == 0) {
max_port = MAX_SCTP_PORT;
proto = PT_SCTP;
}
else if(strcmp(cp, "dccp") == 0) {
max_port = MAX_DCCP_PORT;
proto = PT_DCCP;
} else {
return;
}
if(CVT_NO_ERROR != range_convert_str(&port_rng, port, max_port) ) {
return;
}
cb_service = service;
cb_proto = proto;
range_foreach(port_rng, add_serv_port_cb);
g_free (port_rng);
cb_proto = PT_NONE;
}
static void
add_serv_port_cb(const guint32 port)
{
if ( port ) {
add_service_name(cb_proto, port, cb_service);
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
static gchar *
ep_utoa(guint port)
{
gchar *bp = (gchar *)ep_alloc(MAXNAMELEN);
guint32_to_str_buf(port, bp, MAXNAMELEN);
return bp;
}
static gchar
*serv_name_lookup(const guint port, const port_type proto)
{
serv_port_t *serv_port_table;
gchar *name;
serv_port_table = (serv_port_t *)g_hash_table_lookup(serv_port_hashtable, &port);
if(serv_port_table){
switch(proto) {
case PT_UDP:
if(serv_port_table->udp_name){
return serv_port_table->udp_name;
}
break;
case PT_TCP:
if(serv_port_table->tcp_name){
return serv_port_table->tcp_name;
}
break;
case PT_SCTP:
if(serv_port_table->sctp_name){
return serv_port_table->sctp_name;
}
break;
case PT_DCCP:
if(serv_port_table->dccp_name){
return serv_port_table->dccp_name;
}
break;
default:
return NULL;
}
}
name = (gchar*)g_malloc(16);
guint32_to_str_buf(port, name, 16);
if(serv_port_table == NULL){
int *key;
key = (int *)g_new(int, 1);
*key = port;
serv_port_table = g_new0(serv_port_t,1);
g_hash_table_insert(serv_port_hashtable, key, serv_port_table);
}
switch(proto) {
case PT_UDP:
serv_port_table->udp_name = name;
break;
case PT_TCP:
serv_port_table->tcp_name = name;
break;
case PT_SCTP:
serv_port_table->sctp_name = name;
break;
case PT_DCCP:
serv_port_table->dccp_name = name;
break;
default:
return NULL;
}
return name;
}
static void
destroy_serv_port(gpointer data)
{
serv_port_t *table = (serv_port_t*)data;
g_free(table->udp_name);
g_free(table->tcp_name);
g_free(table->sctp_name);
g_free(table->dccp_name);
g_free(table);
}
static void
initialize_services(void)
{
#ifdef _WIN32
char *hostspath;
char *sysroot;
static char rootpath_nt[] = "\\system32\\drivers\\etc\\services";
#endif
g_assert(serv_port_hashtable == NULL);
serv_port_hashtable = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, destroy_serv_port);
#ifdef _WIN32
sysroot = getenv_utf8("WINDIR");
if (sysroot != NULL) {
hostspath = g_strconcat(sysroot, rootpath_nt, NULL);
parse_services_file(hostspath);
g_free(hostspath);
}
#else
parse_services_file("/etc/services");
#endif
if (g_pservices_path == NULL)
g_pservices_path = get_persconffile_path(ENAME_SERVICES, FALSE);
parse_services_file(g_pservices_path);
if (g_services_path == NULL) {
g_services_path = get_datafile_path(ENAME_SERVICES);
}
parse_services_file(g_services_path);
}
static void
service_name_lookup_cleanup(void)
{
if(serv_port_hashtable){
g_hash_table_destroy(serv_port_hashtable);
serv_port_hashtable = NULL;
}
}
static void
fill_dummy_ip4(const guint addr, hashipv4_t* volatile tp)
{
subnet_entry_t subnet_entry;
if ((tp->flags & DUMMY_ADDRESS_ENTRY) == DUMMY_ADDRESS_ENTRY)
return;
tp->flags = tp->flags | DUMMY_ADDRESS_ENTRY;
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
static void
c_ares_ghba_cb(
void *arg,
int status,
#if ( ( ARES_VERSION_MAJOR < 1 ) \
|| ( 1 == ARES_VERSION_MAJOR && ARES_VERSION_MINOR < 5 ) )
struct hostent *he
#else
int timeouts _U_,
struct hostent *he
#endif
) {
async_dns_queue_msg_t *caqm = (async_dns_queue_msg_t *)arg;
char **p;
if (!caqm) return;
async_dns_in_flight--;
if (status == ARES_SUCCESS) {
for (p = he->h_addr_list; *p != NULL; p++) {
switch(caqm->family) {
case AF_INET:
add_ipv4_name(caqm->addr.ip4, he->h_name);
break;
case AF_INET6:
add_ipv6_name(&caqm->addr.ip6, he->h_name);
break;
default:
break;
}
}
}
g_free(caqm);
}
static hashipv4_t *
new_ipv4(const guint addr)
{
hashipv4_t *tp = g_new(hashipv4_t, 1);
tp->addr = addr;
tp->flags = 0;
ip_to_str_buf((const guint8 *)&addr, tp->ip, sizeof(tp->ip));
return tp;
}
static hashipv4_t *
host_lookup(const guint addr, gboolean *found)
{
hashipv4_t * volatile tp;
*found = TRUE;
tp = (hashipv4_t *)g_hash_table_lookup(ipv4_hash_table, GUINT_TO_POINTER(addr));
if(tp == NULL){
tp = new_ipv4(addr);
g_hash_table_insert(ipv4_hash_table, GUINT_TO_POINTER(addr), tp);
}else{
if ((tp->flags & DUMMY_AND_RESOLVE_FLGS) == DUMMY_ADDRESS_ENTRY){
goto try_resolv;
}
if ((tp->flags & DUMMY_ADDRESS_ENTRY) == DUMMY_ADDRESS_ENTRY){
*found = FALSE;
}
return tp;
}
try_resolv:
if (gbl_resolv_flags.network_name && gbl_resolv_flags.use_external_net_name_resolver) {
tp->flags = tp->flags|TRIED_RESOLVE_ADDRESS;
#ifdef ASYNC_DNS
if (gbl_resolv_flags.concurrent_dns &&
name_resolve_concurrency > 0 &&
async_dns_initialized) {
add_async_dns_ipv4(AF_INET, addr);
fill_dummy_ip4(addr, tp);
return tp;
}
#endif
}
*found = FALSE;
fill_dummy_ip4(addr, tp);
return tp;
}
static hashipv6_t *
new_ipv6(const struct e_in6_addr *addr)
{
hashipv6_t *tp = g_new(hashipv6_t,1);
tp->addr = *addr;
tp->flags = 0;
ip6_to_str_buf(addr, tp->ip6);
return tp;
}
static hashipv6_t *
host_lookup6(const struct e_in6_addr *addr, gboolean *found)
{
hashipv6_t * volatile tp;
#ifdef INET6
#ifdef HAVE_C_ARES
async_dns_queue_msg_t *caqm;
#endif
#endif
*found = TRUE;
tp = (hashipv6_t *)g_hash_table_lookup(ipv6_hash_table, addr);
if(tp == NULL){
struct e_in6_addr *addr_key;
addr_key = g_new(struct e_in6_addr,1);
tp = new_ipv6(addr);
memcpy(addr_key, addr, 16);
g_hash_table_insert(ipv6_hash_table, addr_key, tp);
}else{
if ((tp->flags & DUMMY_AND_RESOLVE_FLGS) == DUMMY_ADDRESS_ENTRY){
goto try_resolv;
}
if ((tp->flags & DUMMY_ADDRESS_ENTRY) == DUMMY_ADDRESS_ENTRY){
*found = FALSE;
}
return tp;
}
try_resolv:
if (gbl_resolv_flags.network_name &&
gbl_resolv_flags.use_external_net_name_resolver) {
tp->flags = tp->flags|TRIED_RESOLVE_ADDRESS;
#ifdef INET6
#ifdef HAVE_C_ARES
if ((gbl_resolv_flags.concurrent_dns) &&
name_resolve_concurrency > 0 &&
async_dns_initialized) {
caqm = g_new(async_dns_queue_msg_t,1);
caqm->family = AF_INET6;
memcpy(&caqm->addr.ip6, addr, sizeof(caqm->addr.ip6));
async_dns_queue_head = g_list_append(async_dns_queue_head, (gpointer) caqm);
if ((tp->flags & DUMMY_ADDRESS_ENTRY) == 0){
g_strlcpy(tp->name, tp->ip6, MAXNAMELEN);
ip6_to_str_buf(addr, tp->name);
tp->flags = tp->flags | DUMMY_ADDRESS_ENTRY;
}
return tp;
}
#endif
#endif
}
if ((tp->flags & DUMMY_ADDRESS_ENTRY) == 0) {
tp->flags = tp->flags | DUMMY_ADDRESS_ENTRY;
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
return get_ether_name((const guint8 *)addr->data);
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
return (const gchar *)addr->data;
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
*mask = (int)num;
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
static void
add_manuf_name(const guint8 *addr, unsigned int mask, gchar *name)
{
guint8 *wka_key;
int *manuf_key;
if (mask >= 48) {
add_eth_name(addr, name);
return;
}
if (mask == 0) {
manuf_key = (int *)g_new(int, 1);
*manuf_key = (int)((addr[0] << 16) + (addr[1] << 8) + addr[2]);
g_hash_table_insert(manuf_hashtable, manuf_key, g_strdup(name));
return;
}
wka_key = (guint8 *)g_malloc(6);
memcpy(wka_key, addr, 6);
g_hash_table_insert(wka_hashtable, wka_key, g_strdup(name));
}
static gchar *
manuf_name_lookup(const guint8 *addr)
{
gint32 manuf_key = 0;
guint8 oct;
gchar *name;
manuf_key = addr[0];
manuf_key = manuf_key<<8;
oct = addr[1];
manuf_key = manuf_key | oct;
manuf_key = manuf_key<<8;
oct = addr[2];
manuf_key = manuf_key | oct;
name = (gchar *)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if(name != NULL){
return name;
}
if((manuf_key & 0x00010000) != 0){
manuf_key &= 0x00FEFFFF;
name = (gchar *)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if(name != NULL){
return name;
}
}
return NULL;
}
static gchar *
wka_name_lookup(const guint8 *addr, const unsigned int mask)
{
guint8 masked_addr[6];
guint num;
gint i;
gchar *name;
if(wka_hashtable == NULL){
return NULL;
}
for (i = 0, num = mask; num >= 8; i++, num -= 8)
masked_addr[i] = addr[i];
masked_addr[i] = addr[i] & (0xFF << (8 - num));
i++;
for (; i < 6; i++)
masked_addr[i] = 0;
name = (gchar *)g_hash_table_lookup(wka_hashtable, masked_addr);
return name;
}
static guint
eth_addr_hash(gconstpointer key)
{
return wmem_strong_hash((const guint8 *)key, 6);
}
static gboolean
eth_addr_cmp(gconstpointer a, gconstpointer b)
{
return (memcmp(a, b, 6) == 0);
}
static void
initialize_ethers(void)
{
ether_t *eth;
char *manuf_path;
guint mask;
wka_hashtable = g_hash_table_new_full(eth_addr_hash, eth_addr_cmp, g_free, g_free);
manuf_hashtable = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, g_free);
eth_hashtable = g_hash_table_new_full(eth_addr_hash, eth_addr_cmp, NULL, g_free);
if (g_ethers_path == NULL) {
g_ethers_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
get_systemfile_dir(), ENAME_ETHERS);
}
if (g_pethers_path == NULL)
g_pethers_path = get_persconffile_path(ENAME_ETHERS, FALSE);
manuf_path = get_datafile_path(ENAME_MANUF);
set_ethent(manuf_path);
while ((eth = get_ethent(&mask, TRUE))) {
add_manuf_name(eth->addr, mask, eth->name);
}
end_ethent();
g_free(manuf_path);
}
static void
eth_name_lookup_cleanup(void)
{
if(manuf_hashtable) {
g_hash_table_destroy(manuf_hashtable);
manuf_hashtable = NULL;
}
if(wka_hashtable) {
g_hash_table_destroy(wka_hashtable);
wka_hashtable = NULL;
}
if(eth_hashtable) {
g_hash_table_destroy(eth_hashtable);
eth_hashtable = NULL;
}
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
guint mask;
gchar *name;
mask = 7;
for (;;) {
if ((name = wka_name_lookup(addr, mask+40)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x",
name, addr[5] & (0xFF >> mask));
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
mask = 7;
for (;;) {
if ((name = wka_name_lookup(addr, mask+32)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x",
name, addr[4] & (0xFF >> mask), addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
mask = 7;
for (;;) {
if ((name = wka_name_lookup(addr, mask+24)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x",
name, addr[3] & (0xFF >> mask), addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
if ((name = manuf_name_lookup(addr)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x",
name, addr[3], addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
mask = 7;
for (;;) {
if ((name = wka_name_lookup(addr, mask+16)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x",
name, addr[2] & (0xFF >> mask), addr[3], addr[4],
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
if ((name = wka_name_lookup(addr, mask+8)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x:%02x",
name, addr[1] & (0xFF >> mask), addr[2], addr[3],
addr[4], addr[5]);
tp->status = HASHETHER_STATUS_RESOLVED_DUMMY;
return tp;
}
if (mask == 0)
break;
mask--;
}
for (mask = 7; mask > 0; mask--) {
if ((name = wka_name_lookup(addr, mask)) != NULL) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x:%02x:%02x:%02x",
name, addr[0] & (0xFF >> mask), addr[1], addr[2],
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
eth_hash_new_entry(const guint8 *addr, const gboolean resolve)
{
hashether_t *tp;
char *endp;
tp = g_new(hashether_t, 1);
memcpy(tp->addr, addr, sizeof(tp->addr));
tp->status = HASHETHER_STATUS_UNRESOLVED;
endp = bytes_to_hexstr_punct(tp->hexaddr, addr, sizeof(tp->addr), ':');
*endp = '\0';
tp->resolved_name[0] = '\0';
if (resolve)
eth_addr_resolve(tp);
g_hash_table_insert(eth_hashtable, tp->addr, tp);
return tp;
}
static hashether_t *
add_eth_name(const guint8 *addr, const gchar *name)
{
hashether_t *tp;
tp = (hashether_t *)g_hash_table_lookup(eth_hashtable, addr);
if( tp == NULL ){
tp = eth_hash_new_entry(addr, FALSE);
}
g_strlcpy(tp->resolved_name, name, MAXNAMELEN);
tp->status = HASHETHER_STATUS_RESOLVED_NAME;
new_resolved_objects = TRUE;
return tp;
}
static hashether_t *
eth_name_lookup(const guint8 *addr, const gboolean resolve)
{
hashether_t *tp;
tp = (hashether_t *)g_hash_table_lookup(eth_hashtable, addr);
if( tp == NULL ) {
tp = eth_hash_new_entry(addr, resolve);
} else {
if (resolve && (tp->status == HASHETHER_STATUS_UNRESOLVED)){
eth_addr_resolve(tp);
}
}
return tp;
}
static guint8 *
eth_addr_lookup(const gchar *name _U_)
{
#if 0
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
#endif
return NULL;
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
g_pipxnets_path = get_persconffile_path(ENAME_IPXNETS, FALSE);
}
static void
ipx_name_lookup_cleanup(void)
{
if(ipxnet_hash_table){
g_hash_table_destroy(ipxnet_hash_table);
ipxnet_hash_table = NULL;
}
}
static gchar *
ipxnet_name_lookup(const guint addr)
{
hashipxnet_t *tp;
ipxnet_t *ipxnet;
tp = (hashipxnet_t *)g_hash_table_lookup(ipxnet_hash_table, &addr);
if(tp == NULL){
int *key;
key = (int *)g_new(int, 1);
*key = addr;
tp = g_new(hashipxnet_t, 1);
g_hash_table_insert(ipxnet_hash_table, key, tp);
}else{
return tp->name;
}
tp->addr = addr;
if ( (ipxnet = get_ipxnetbyaddr(addr)) == NULL) {
g_snprintf(tp->name, MAXNAMELEN, "%X", addr);
} else {
g_strlcpy(tp->name, ipxnet->name, MAXNAMELEN);
}
return (tp->name);
}
static guint
ipxnet_addr_lookup(const gchar *name _U_, gboolean *success)
{
*success = FALSE;
return 0;
#if 0
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
#endif
}
static gboolean
read_hosts_file (const char *hostspath, gboolean store_entries)
{
FILE *hf;
char *line = NULL;
int size = 0;
gchar *cp;
guint32 host_addr[4];
struct e_in6_addr ip6_addr;
gboolean is_ipv6, entry_found = FALSE;
int ret;
if ((hf = ws_fopen(hostspath, "r")) == NULL)
return FALSE;
while (fgetline(&line, &size, hf) >= 0) {
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
continue;
ret = inet_pton(AF_INET6, cp, &host_addr);
if (ret < 0)
continue;
if (ret > 0) {
is_ipv6 = TRUE;
} else {
if (!str_to_ip(cp, &host_addr))
continue;
is_ipv6 = FALSE;
}
if ((cp = strtok(NULL, " \t")) == NULL)
continue;
entry_found = TRUE;
if (store_entries) {
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
}
g_free(line);
fclose(hf);
return entry_found ? TRUE : FALSE;
}
gboolean
add_hosts_file (const char *hosts_file)
{
gboolean found = FALSE;
guint i;
if (!hosts_file)
return FALSE;
if (!extra_hosts_files)
extra_hosts_files = g_ptr_array_new();
for (i = 0; i < extra_hosts_files->len; i++) {
if (strcmp(hosts_file, (const char *) g_ptr_array_index(extra_hosts_files, i)) == 0)
found = TRUE;
}
if (!found) {
g_ptr_array_add(extra_hosts_files, g_strdup(hosts_file));
return read_hosts_file (hosts_file, FALSE);
}
return TRUE;
}
gboolean
add_ip_name_from_string (const char *addr, const char *name)
{
guint32 host_addr[4];
struct e_in6_addr ip6_addr;
gboolean is_ipv6;
int ret;
resolved_ipv4_t *resolved_ipv4_entry;
resolved_ipv6_t *resolved_ipv6_entry;
ret = inet_pton(AF_INET6, addr, &ip6_addr);
if (ret < 0)
return FALSE;
if (ret > 0) {
is_ipv6 = TRUE;
} else {
if (!str_to_ip(addr, &host_addr))
return FALSE;
is_ipv6 = FALSE;
}
if (is_ipv6) {
resolved_ipv6_entry = g_new(resolved_ipv6_t, 1);
memcpy(&(resolved_ipv6_entry->ip6_addr), &ip6_addr, 16);
g_strlcpy(resolved_ipv6_entry->name, name, MAXNAMELEN);
manually_resolved_ipv6_list = g_slist_prepend(manually_resolved_ipv6_list, resolved_ipv6_entry);
} else {
resolved_ipv4_entry = g_new(resolved_ipv4_t, 1);
resolved_ipv4_entry->host_addr = host_addr[0];
g_strlcpy(resolved_ipv4_entry->name, name, MAXNAMELEN);
manually_resolved_ipv4_list = g_slist_prepend(manually_resolved_ipv4_list, resolved_ipv4_entry);
}
return TRUE;
}
static void
ipv4_hash_table_resolved_to_list(gpointer key _U_, gpointer value, gpointer user_data)
{
addrinfo_lists_t *lists = (addrinfo_lists_t*)user_data;
hashipv4_t *ipv4_hash_table_entry = (hashipv4_t *)value;
if((ipv4_hash_table_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED){
lists->ipv4_addr_list = g_list_prepend (lists->ipv4_addr_list, ipv4_hash_table_entry);
}
}
static void
ipv6_hash_table_resolved_to_list(gpointer key _U_, gpointer value, gpointer user_data)
{
addrinfo_lists_t *lists = (addrinfo_lists_t*)user_data;
hashipv6_t *ipv6_hash_table_entry = (hashipv6_t *)value;
if((ipv6_hash_table_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED){
lists->ipv6_addr_list = g_list_prepend (lists->ipv6_addr_list, ipv6_hash_table_entry);
}
}
addrinfo_lists_t *
get_addrinfo_list(void) {
if(ipv4_hash_table){
g_hash_table_foreach(ipv4_hash_table, ipv4_hash_table_resolved_to_list, &addrinfo_lists);
}
if(ipv6_hash_table){
g_hash_table_foreach(ipv6_hash_table, ipv6_hash_table_resolved_to_list, &addrinfo_lists);
}
return &addrinfo_lists;
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
if (!str_to_ip(cp, &host_addr)) {
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
sub_net_hashipv4_t * tp;
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
sub_net_hashipv4_t * tp;
gsize hash_idx;
g_assert(mask_length > 0 && mask_length <= 32);
entry = &subnet_length_entries[mask_length - 1];
subnet_addr &= entry->mask;
hash_idx = HASH_IPV4_ADDRESS(subnet_addr);
if(NULL == entry->subnet_addresses) {
entry->subnet_addresses = (sub_net_hashipv4_t**) se_alloc0(sizeof(sub_net_hashipv4_t*) * HASHHOSTSIZE);
}
if(NULL != (tp = entry->subnet_addresses[hash_idx])) {
if(tp->addr == subnet_addr) {
return;
} else {
sub_net_hashipv4_t * new_tp = se_new(sub_net_hashipv4_t);
tp->next = new_tp;
tp = new_tp;
}
} else {
tp = entry->subnet_addresses[hash_idx] = se_new(sub_net_hashipv4_t);
}
tp->next = NULL;
tp->addr = subnet_addr;
tp->flags = tp->flags & 0xfe;
g_strlcpy(tp->name, name, MAXNAMELEN);
have_subnet_entry = TRUE;
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
subnet_length_entries[i].mask = g_htonl(ip_get_subnet_mask(length));
}
subnetspath = get_persconffile_path(ENAME_SUBNETS, FALSE);
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
addr_resolve_pref_init(module_t *nameres)
{
prefs_register_bool_preference(nameres, "mac_name",
"Resolve MAC addresses",
"Resolve Ethernet MAC address to manufacturer names",
&gbl_resolv_flags.mac_name);
prefs_register_bool_preference(nameres, "transport_name",
"Resolve transport names",
"Resolve TCP/UDP ports into service names",
&gbl_resolv_flags.transport_name);
prefs_register_bool_preference(nameres, "network_name",
"Resolve network (IP) addresses",
"Resolve IPv4, IPv6, and IPX addresses into host names."
" The next set of check boxes determines how name resolution should be performed."
" If no other options are checked name resolution is made from Wireshark's host file,"
" capture file name resolution blocks and DNS packets in the capture.",
&gbl_resolv_flags.network_name);
prefs_register_bool_preference(nameres, "use_external_name_resolver",
"Use an external network name resolver",
"Use your system's configured name resolver"
" (usually DNS) to resolve network names."
" Only applies when network name resolution"
" is enabled.",
&gbl_resolv_flags.use_external_net_name_resolver);
#if defined(HAVE_C_ARES) || defined(HAVE_GNU_ADNS)
prefs_register_bool_preference(nameres, "concurrent_dns",
"Enable concurrent DNS name resolution",
"Enable concurrent DNS name resolution. Only"
" applies when network name resolution is"
" enabled. You probably want to enable this.",
&gbl_resolv_flags.concurrent_dns);
prefs_register_uint_preference(nameres, "name_resolve_concurrency",
"Maximum concurrent requests",
"The maximum number of DNS requests that may"
" be active at any time. A large value (many"
" thousands) might overload the network or make"
" your DNS server behave badly.",
10,
&name_resolve_concurrency);
#else
prefs_register_static_text_preference(nameres, "concurrent_dns",
"Enable concurrent DNS name resolution: N/A",
"Support for concurrent DNS name resolution was not"
" compiled into this version of Wireshark");
#endif
prefs_register_bool_preference(nameres, "hosts_file_handling",
"Only use the profile \"hosts\" file",
"By default \"hosts\" files will be loaded from multiple sources."
" Checking this box only loads the \"hosts\" in the current profile.",
&gbl_resolv_flags.load_hosts_file_from_profile_only);
}
gboolean
host_name_lookup_process(void) {
async_dns_queue_msg_t *caqm;
struct timeval tv = { 0, 0 };
int nfds;
fd_set rfds, wfds;
gboolean nro = new_resolved_objects;
new_resolved_objects = FALSE;
if (!async_dns_initialized)
return nro;
async_dns_queue_head = g_list_first(async_dns_queue_head);
while (async_dns_queue_head != NULL && async_dns_in_flight <= name_resolve_concurrency) {
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
if (select(nfds, &rfds, &wfds, NULL, &tv) == -1) {
fprintf(stderr, "Warning: call to select() failed, error is %s\n", g_strerror(errno));
return nro;
}
ares_process(ghba_chan, &rfds, &wfds);
}
return nro;
}
static void
_host_name_lookup_cleanup(void) {
GList *cur;
cur = g_list_first(async_dns_queue_head);
while (cur) {
g_free(cur->data);
cur = g_list_next (cur);
}
g_list_free(async_dns_queue_head);
async_dns_queue_head = NULL;
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
host_name_lookup_process(void) {
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
while (cur && async_dns_in_flight <= name_resolve_concurrency) {
almsg = (async_dns_queue_msg_t *) cur->data;
if (! almsg->submitted && almsg->type == AF_INET) {
addr_bytes = (guint8 *) &almsg->ip4_addr;
g_snprintf(addr_str, sizeof addr_str, "%u.%u.%u.%u.in-addr.arpa.", addr_bytes[3],
addr_bytes[2], addr_bytes[1], addr_bytes[0]);
adns_submit (ads, addr_str, adns_r_ptr, adns_qf_none, NULL, &almsg->query);
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
static void
_host_name_lookup_cleanup(void) {
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
host_name_lookup_process(void) {
gboolean nro = new_resolved_objects;
new_resolved_objects = FALSE;
return nro;
}
static void
_host_name_lookup_cleanup(void) {
}
const gchar *
get_hostname(const guint addr)
{
gboolean found;
hashipv4_t *tp = host_lookup(addr, &found);
if (!gbl_resolv_flags.network_name)
return tp->ip;
tp->flags = tp->flags | RESOLVED_ADDRESS_USED;
return tp->name;
}
const gchar *
get_hostname6(const struct e_in6_addr *addr)
{
gboolean found;
hashipv6_t *tp = host_lookup6(addr, &found);
if (!gbl_resolv_flags.network_name)
return tp->ip6;
tp->flags = tp->flags | RESOLVED_ADDRESS_USED;
return tp->name;
}
void
add_ipv4_name(const guint addr, const gchar *name)
{
hashipv4_t *tp;
if (name[0] == '\0')
return;
tp = (hashipv4_t *)g_hash_table_lookup(ipv4_hash_table, GUINT_TO_POINTER(addr));
if(tp){
g_strlcpy(tp->name, name, MAXNAMELEN);
}else{
tp = new_ipv4(addr);
g_strlcpy(tp->name, name, MAXNAMELEN);
g_hash_table_insert(ipv4_hash_table, GUINT_TO_POINTER(addr), tp);
}
g_strlcpy(tp->name, name, MAXNAMELEN);
tp->flags = tp->flags | TRIED_RESOLVE_ADDRESS;
new_resolved_objects = TRUE;
}
void
add_ipv6_name(const struct e_in6_addr *addrp, const gchar *name)
{
hashipv6_t *tp;
if (name[0] == '\0')
return;
tp = (hashipv6_t *)g_hash_table_lookup(ipv6_hash_table, addrp);
if(tp){
g_strlcpy(tp->name, name, MAXNAMELEN);
}else{
struct e_in6_addr *addr_key;
addr_key = g_new(struct e_in6_addr,1);
tp = new_ipv6(addrp);
memcpy(addr_key, addrp, 16);
g_strlcpy(tp->name, name, MAXNAMELEN);
g_hash_table_insert(ipv6_hash_table, addr_key, tp);
}
g_strlcpy(tp->name, name, MAXNAMELEN);
tp->flags = tp->flags | TRIED_RESOLVE_ADDRESS;
new_resolved_objects = TRUE;
}
static void
add_manually_resolved_ipv4(gpointer data, gpointer user_data _U_)
{
resolved_ipv4_t *resolved_ipv4_entry = (resolved_ipv4_t *)data;
add_ipv4_name(resolved_ipv4_entry->host_addr, resolved_ipv4_entry->name);
}
static void
add_manually_resolved_ipv6(gpointer data, gpointer user_data _U_)
{
resolved_ipv6_t *resolved_ipv6_entry = (resolved_ipv6_t *)data;
add_ipv6_name(&(resolved_ipv6_entry->ip6_addr), resolved_ipv6_entry->name);
}
static void
add_manually_resolved(void)
{
if(manually_resolved_ipv4_list){
g_slist_foreach(manually_resolved_ipv4_list, add_manually_resolved_ipv4, NULL);
}
if(manually_resolved_ipv6_list){
g_slist_foreach(manually_resolved_ipv6_list, add_manually_resolved_ipv6, NULL);
}
}
void
host_name_lookup_init(void)
{
char *hostspath;
guint i;
#ifdef HAVE_GNU_ADNS
#ifdef _WIN32
char *sysroot;
static char rootpath_nt[] = "\\system32\\drivers\\etc\\hosts";
static char rootpath_ot[] = "\\hosts";
#endif
#endif
g_assert(ipxnet_hash_table == NULL);
ipxnet_hash_table = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, g_free);
g_assert(ipv4_hash_table == NULL);
ipv4_hash_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_free);
g_assert(ipv6_hash_table == NULL);
ipv6_hash_table = g_hash_table_new_full(ipv6_oat_hash, ipv6_equal, g_free, g_free);
if(!gbl_resolv_flags.load_hosts_file_from_profile_only){
hostspath = get_datafile_path(ENAME_HOSTS);
if (!read_hosts_file(hostspath, TRUE) && errno != ENOENT) {
report_open_failure(hostspath, errno, FALSE);
}
g_free(hostspath);
}
hostspath = get_persconffile_path(ENAME_HOSTS, TRUE);
if (!read_hosts_file(hostspath, TRUE) && errno != ENOENT) {
report_open_failure(hostspath, errno, FALSE);
}
g_free(hostspath);
#ifdef HAVE_C_ARES
if (gbl_resolv_flags.concurrent_dns) {
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
if (ares_library_init(ARES_LIB_INIT_ALL) == ARES_SUCCESS) {
#endif
if (ares_init(&ghba_chan) == ARES_SUCCESS && ares_init(&ghbn_chan) == ARES_SUCCESS) {
async_dns_initialized = TRUE;
}
#ifdef CARES_HAVE_ARES_LIBRARY_INIT
}
#endif
}
#else
#ifdef HAVE_GNU_ADNS
#ifdef _WIN32
sysroot = getenv_utf8("WINDIR");
if (sysroot != NULL) {
if(!gbl_resolv_flags.load_hosts_file_from_profile_only){
hostspath = g_strconcat(sysroot, rootpath_nt, NULL);
if (!read_hosts_file(hostspath, TRUE)) {
g_free(hostspath);
hostspath = g_strconcat(sysroot, rootpath_ot, NULL);
read_hosts_file(hostspath, TRUE);
}
g_free(hostspath);
}
}
#else
if(!gbl_resolv_flags.load_hosts_file_from_profile_only){
read_hosts_file("/etc/hosts", TRUE);
}
#endif
if (gbl_resolv_flags.concurrent_dns) {
if (adns_init(&ads, adns_if_none, 0 ) != 0) {
return;
}
async_dns_initialized = TRUE;
async_dns_in_flight = 0;
}
#endif
#endif
if(extra_hosts_files && !gbl_resolv_flags.load_hosts_file_from_profile_only){
for (i = 0; i < extra_hosts_files->len; i++) {
read_hosts_file((const char *) g_ptr_array_index(extra_hosts_files, i), TRUE);
}
}
subnet_name_lookup_init();
add_manually_resolved();
}
void
host_name_lookup_cleanup(void)
{
_host_name_lookup_cleanup();
if(ipxnet_hash_table){
g_hash_table_destroy(ipxnet_hash_table);
ipxnet_hash_table = NULL;
}
if(ipv4_hash_table){
g_hash_table_destroy(ipv4_hash_table);
ipv4_hash_table = NULL;
}
if(ipv6_hash_table){
g_hash_table_destroy(ipv6_hash_table);
ipv6_hash_table = NULL;
}
memset(subnet_length_entries, 0, sizeof(subnet_length_entries));
have_subnet_entry = FALSE;
new_resolved_objects = FALSE;
}
static void
free_manually_resolved_ipv4(gpointer data, gpointer user_data _U_)
{
resolved_ipv4_t *resolved_ipv4_entry = (resolved_ipv4_t *)data;
g_free(resolved_ipv4_entry);
}
static void
free_manually_resolved_ipv6(gpointer data, gpointer user_data _U_)
{
resolved_ipv6_t *resolved_ipv6_entry = (resolved_ipv6_t *)data;
g_free(resolved_ipv6_entry);
}
void
manually_resolve_cleanup(void)
{
if(manually_resolved_ipv4_list){
g_slist_foreach(manually_resolved_ipv4_list, free_manually_resolved_ipv4, NULL);
g_slist_free(manually_resolved_ipv4_list);
manually_resolved_ipv4_list = NULL;
}
if(manually_resolved_ipv6_list){
g_slist_foreach(manually_resolved_ipv6_list, free_manually_resolved_ipv6, NULL);
g_slist_free(manually_resolved_ipv6_list);
manually_resolved_ipv6_list = NULL;
}
}
gchar *
ep_udp_port_to_display(guint port)
{
if (!gbl_resolv_flags.transport_name) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_UDP);
}
gchar *
ep_dccp_port_to_display(guint port)
{
if (!gbl_resolv_flags.transport_name) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_DCCP);
}
gchar *
ep_tcp_port_to_display(guint port)
{
if (!gbl_resolv_flags.transport_name) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_TCP);
}
gchar *
ep_sctp_port_to_display(guint port)
{
if (!gbl_resolv_flags.transport_name) {
return ep_utoa(port);
}
return serv_name_lookup(port, PT_SCTP);
}
const gchar *
ep_address_to_display(const address *addr)
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
get_addr_name(const address *addr)
{
guint32 ip4_addr;
struct e_in6_addr ip6_addr;
switch (addr->type) {
case AT_ETHER:
return get_ether_name((const guint8 *)addr->data);
case AT_IPv4:
memcpy(&ip4_addr, addr->data, sizeof ip4_addr);
return get_hostname(ip4_addr);
case AT_IPv6:
memcpy(&ip6_addr.bytes, addr->data, sizeof ip6_addr.bytes);
return get_hostname6(&ip6_addr);
default:
return NULL;
}
}
void
get_addr_name_buf(const address *addr, gchar *buf, gsize size)
{
const gchar *result = ep_address_to_display(addr);
g_strlcpy(buf, result, size);
}
gchar *
get_ether_name(const guint8 *addr)
{
hashether_t *tp;
gboolean resolve = gbl_resolv_flags.mac_name;
tp = eth_name_lookup(addr, resolve);
return resolve ? tp->resolved_name : tp->hexaddr;
}
gchar *
get_ether_name_if_known(const guint8 *addr)
{
hashether_t *tp;
if (!gbl_resolv_flags.mac_name)
return NULL;
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
return eth_addr_lookup(name);
}
void
add_ether_byip(const guint ip, const guint8 *eth)
{
gboolean found;
hashipv4_t *tp;
if (!gbl_resolv_flags.network_name)
return;
tp = host_lookup(ip, &found);
if (found) {
add_eth_name(eth, tp->name);
}
}
const gchar *
get_ipxnet_name(const guint32 addr)
{
if (!gbl_resolv_flags.network_name) {
return ipxnet_to_str_punct(addr, '\0');
}
return ipxnet_name_lookup(addr);
}
guint32
get_ipxnet_addr(const gchar *name, gboolean *known)
{
guint32 addr;
gboolean success;
addr = ipxnet_addr_lookup(name, &success);
*known = success;
return addr;
}
const gchar *
get_manuf_name(const guint8 *addr)
{
gchar *cur;
int manuf_key;
guint8 oct;
manuf_key = addr[0];
manuf_key = manuf_key<<8;
oct = addr[1];
manuf_key = manuf_key | oct;
manuf_key = manuf_key<<8;
oct = addr[2];
manuf_key = manuf_key | oct;
if (!gbl_resolv_flags.mac_name || ((cur = (gchar *)g_hash_table_lookup(manuf_hashtable, &manuf_key)) == NULL)) {
cur=ep_strdup_printf("%02x:%02x:%02x", addr[0], addr[1], addr[2]);
return cur;
}
return cur;
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
gchar *cur;
int manuf_key;
guint8 oct;
manuf_key = addr[0];
manuf_key = manuf_key<<8;
oct = addr[1];
manuf_key = manuf_key | oct;
manuf_key = manuf_key<<8;
oct = addr[2];
manuf_key = manuf_key | oct;
if ((cur = (gchar *)g_hash_table_lookup(manuf_hashtable, &manuf_key)) == NULL) {
return NULL;
}
return cur;
}
const gchar *
uint_get_manuf_name_if_known(const guint manuf_key)
{
gchar *cur;
if ((cur = (gchar *)g_hash_table_lookup(manuf_hashtable, &manuf_key)) == NULL) {
return NULL;
}
return cur;
}
const gchar *
tvb_get_manuf_name_if_known(tvbuff_t *tvb, gint offset)
{
return get_manuf_name_if_known(tvb_get_ptr(tvb, offset, 3));
}
const gchar *
ep_eui64_to_display(const guint64 addr_eui64)
{
gchar *cur, *name;
guint8 *addr = (guint8 *)ep_alloc(8);
*(guint64 *)(void *)(addr) = pntoh64(&(addr_eui64));
if (!gbl_resolv_flags.mac_name || ((name = manuf_name_lookup(addr)) == NULL)) {
cur=ep_strdup_printf("%02x:%02x:%02x%02x:%02x:%02x%02x:%02x", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
cur=ep_strdup_printf("%s_%02x:%02x:%02x:%02x:%02x", name, addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
const gchar *
ep_eui64_to_display_if_known(const guint64 addr_eui64)
{
gchar *cur, *name;
guint8 *addr = (guint8 *)ep_alloc(8);
*(guint64 *)(void *)(addr) = pntoh64(&(addr_eui64));
if ((name = manuf_name_lookup(addr)) == NULL) {
return NULL;
}
cur=ep_strdup_printf("%s_%02x:%02x:%02x:%02x:%02x", name, addr[3], addr[4], addr[5], addr[6], addr[7]);
return cur;
}
static void
c_ares_ghi_cb(
void *arg,
int status,
#if ( ( ARES_VERSION_MAJOR < 1 ) \
|| ( 1 == ARES_VERSION_MAJOR && ARES_VERSION_MINOR < 5 ) )
struct hostent *hp
#else
int timeouts _U_,
struct hostent *hp
#endif
) {
async_hostent_t *ahp = (async_hostent_t *)arg;
if (status == ARES_SUCCESS && hp && ahp && hp->h_length == ahp->addr_size) {
memcpy(ahp->addrp, hp->h_addr, hp->h_length);
ahp->copied = hp->h_length;
}
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
if (!gbl_resolv_flags.network_name ||
!gbl_resolv_flags.use_external_net_name_resolver) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (! (gbl_resolv_flags.concurrent_dns) ||
name_resolve_concurrency < 1 ||
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
if (select(nfds, &rfds, &wfds, NULL, tvp) == -1) {
fprintf(stderr, "Warning: call to select() failed, error is %s\n", g_strerror(errno));
return FALSE;
}
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
if (str_to_ip6(host, addrp))
return TRUE;
if (!gbl_resolv_flags.network_name ||
!gbl_resolv_flags.use_external_net_name_resolver) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (! (gbl_resolv_flags.concurrent_dns) ||
name_resolve_concurrency < 1 ||
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
if (select(nfds, &rfds, &wfds, NULL, tvp) == -1) {
fprintf(stderr, "Warning: call to select() failed, error is %s\n", g_strerror(errno));
return FALSE;
}
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
GHashTable *
get_manuf_hashtable(void)
{
return manuf_hashtable;
}
GHashTable *
get_wka_hashtable(void)
{
return wka_hashtable;
}
GHashTable *
get_eth_hashtable(void)
{
return eth_hashtable;
}
GHashTable *
get_serv_port_hashtable(void)
{
return serv_port_hashtable;
}
GHashTable *
get_ipxnet_hash_table(void)
{
return ipxnet_hash_table;
}
GHashTable *
get_ipv4_hash_table(void)
{
return ipv4_hash_table;
}
GHashTable *
get_ipv6_hash_table(void)
{
return ipv6_hash_table;
}
void
addr_resolv_init(void)
{
initialize_services();
initialize_ethers();
initialize_ipxnets();
}
void
addr_resolv_cleanup(void)
{
service_name_lookup_cleanup();
eth_name_lookup_cleanup();
ipx_name_lookup_cleanup();
}
gboolean
str_to_ip(const char *str, void *dst)
{
return inet_pton(AF_INET, str, dst) > 0;
}
gboolean
str_to_ip6(const char *str, void *dst)
{
return inet_pton(AF_INET6, str, dst) > 0;
}
