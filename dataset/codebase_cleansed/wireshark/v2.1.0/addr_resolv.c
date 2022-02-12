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
if (memcmp(v1, v2, sizeof (struct e_in6_addr)) == 0) {
return TRUE;
}
return FALSE;
}
static void
add_async_dns_ipv4(int type, guint32 addr)
{
async_dns_queue_msg_t *msg;
msg = wmem_new(wmem_epan_scope(), async_dns_queue_msg_t);
msg->family = type;
msg->addr.ip4 = addr;
wmem_list_append(async_dns_queue_head, (gpointer) msg);
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
*buf = (char *)wmem_alloc(wmem_epan_scope(), *size);
}
g_assert(*buf);
g_assert(*size > 0);
if (feof(fp))
return -1;
len = 0;
while ((c = getc(fp)) != EOF && c != '\r' && c != '\n') {
if (len+1 >= *size) {
*buf = (char *)wmem_realloc(wmem_epan_scope(), *buf, *size += BUFSIZ);
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
key = (int *)wmem_new(wmem_epan_scope(), int);
*key = port;
serv_port_table = (serv_port_t *)g_hash_table_lookup(serv_port_hashtable, &port);
if (serv_port_table == NULL) {
serv_port_table = wmem_new0(wmem_epan_scope(), serv_port_t);
g_hash_table_insert(serv_port_hashtable, key, serv_port_table);
}
else {
wmem_free(wmem_epan_scope(), key);
}
switch(proto) {
case PT_TCP:
wmem_free(wmem_epan_scope(), serv_port_table->tcp_name);
serv_port_table->tcp_name = wmem_strdup(wmem_epan_scope(), service_name);
break;
case PT_UDP:
wmem_free(wmem_epan_scope(), serv_port_table->udp_name);
serv_port_table->udp_name = wmem_strdup(wmem_epan_scope(), service_name);
break;
case PT_SCTP:
wmem_free(wmem_epan_scope(), serv_port_table->sctp_name);
serv_port_table->sctp_name = wmem_strdup(wmem_epan_scope(), service_name);
break;
case PT_DCCP:
wmem_free(wmem_epan_scope(), serv_port_table->dccp_name);
serv_port_table->dccp_name = wmem_strdup(wmem_epan_scope(), service_name);
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
if (strcmp(cp, "tcp") == 0) {
max_port = MAX_TCP_PORT;
proto = PT_TCP;
}
else if (strcmp(cp, "udp") == 0) {
max_port = MAX_UDP_PORT;
proto = PT_UDP;
}
else if (strcmp(cp, "sctp") == 0) {
max_port = MAX_SCTP_PORT;
proto = PT_SCTP;
}
else if (strcmp(cp, "dccp") == 0) {
max_port = MAX_DCCP_PORT;
proto = PT_DCCP;
} else {
return;
}
if (CVT_NO_ERROR != range_convert_str(&port_rng, port, max_port)) {
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
parse_service_line(buf);
}
fclose(serv_p);
}
static gchar *
wmem_utoa(wmem_allocator_t *allocator, guint port)
{
gchar *bp = (gchar *)wmem_alloc(allocator, MAXNAMELEN);
guint32_to_str_buf(port, bp, MAXNAMELEN);
return bp;
}
static const gchar *
_serv_name_lookup(port_type proto, guint port, serv_port_t **value_ret)
{
serv_port_t *serv_port_table;
serv_port_table = (serv_port_t *)g_hash_table_lookup(serv_port_hashtable, &port);
if (value_ret != NULL)
*value_ret = serv_port_table;
if (serv_port_table == NULL)
return NULL;
switch (proto) {
case PT_UDP:
return serv_port_table->udp_name;
case PT_TCP:
return serv_port_table->tcp_name;
case PT_SCTP:
return serv_port_table->sctp_name;
case PT_DCCP:
return serv_port_table->dccp_name;
default:
break;
}
return NULL;
}
const gchar *
try_serv_name_lookup(port_type proto, guint port)
{
return _serv_name_lookup(proto, port, NULL);
}
const gchar *
serv_name_lookup(port_type proto, guint port)
{
serv_port_t *serv_port_table = NULL;
const char *name;
guint *key;
name = _serv_name_lookup(proto, port, &serv_port_table);
if (name != NULL)
return name;
if (serv_port_table == NULL) {
key = (guint *)wmem_new(wmem_epan_scope(), guint);
*key = port;
serv_port_table = wmem_new0(wmem_epan_scope(), serv_port_t);
g_hash_table_insert(serv_port_hashtable, key, serv_port_table);
}
if (serv_port_table->numeric == NULL) {
serv_port_table->numeric = wmem_strdup_printf(wmem_epan_scope(), "%u", port);
}
return serv_port_table->numeric;
}
static void
destroy_serv_port(gpointer data)
{
serv_port_t *table = (serv_port_t*)data;
wmem_free(wmem_epan_scope(), table->udp_name);
wmem_free(wmem_epan_scope(), table->tcp_name);
wmem_free(wmem_epan_scope(), table->sctp_name);
wmem_free(wmem_epan_scope(), table->dccp_name);
wmem_free(wmem_epan_scope(), table->numeric);
wmem_free(wmem_epan_scope(), table);
}
static void
initialize_services(void)
{
g_assert(serv_port_hashtable == NULL);
serv_port_hashtable = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, destroy_serv_port);
if (g_services_path == NULL) {
g_services_path = get_datafile_path(ENAME_SERVICES);
}
parse_services_file(g_services_path);
if (g_pservices_path == NULL) {
g_pservices_path = get_persconffile_path(ENAME_SERVICES, FALSE);
}
parse_services_file(g_pservices_path);
}
static void
service_name_lookup_cleanup(void)
{
if (serv_port_hashtable) {
g_hash_table_destroy(serv_port_hashtable);
serv_port_hashtable = NULL;
}
}
static void
fill_dummy_ip4(const guint addr, hashipv4_t* volatile tp)
{
subnet_entry_t subnet_entry;
if (tp->flags & DUMMY_ADDRESS_ENTRY)
return;
tp->flags |= DUMMY_ADDRESS_ENTRY;
subnet_entry = subnet_lookup(addr);
if (0 != subnet_entry.mask) {
guint32 host_addr;
gchar buffer[MAX_IP_STR_LEN];
gchar* paddr;
gsize i;
host_addr = addr & (~(guint32)subnet_entry.mask);
ip_to_str_buf((guint8 *)&host_addr, buffer, MAX_IP_STR_LEN);
paddr = buffer;
i = subnet_entry.mask_length / 8;
while(*(paddr) != '\0' && i > 0) {
if (*(++paddr) == '.') {
--i;
}
}
g_snprintf(tp->name, MAXNAMELEN, "%s%s", subnet_entry.name, paddr);
} else {
ip_to_str_buf((const guint8 *)&addr, tp->name, MAXNAMELEN);
}
}
static void
fill_dummy_ip6(hashipv6_t* volatile tp)
{
if (tp->flags & DUMMY_ADDRESS_ENTRY)
return;
tp->flags |= DUMMY_ADDRESS_ENTRY;
g_strlcpy(tp->name, tp->ip6, MAXNAMELEN);
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
wmem_free(wmem_epan_scope(), caqm);
}
static hashipv4_t *
new_ipv4(const guint addr)
{
hashipv4_t *tp = wmem_new(wmem_epan_scope(), hashipv4_t);
tp->addr = addr;
tp->flags = 0;
tp->name[0] = '\0';
ip_to_str_buf((const guint8 *)&addr, tp->ip, sizeof(tp->ip));
return tp;
}
static hashipv4_t *
host_lookup(const guint addr)
{
hashipv4_t * volatile tp;
tp = (hashipv4_t *)g_hash_table_lookup(ipv4_hash_table, GUINT_TO_POINTER(addr));
if (tp == NULL) {
tp = new_ipv4(addr);
g_hash_table_insert(ipv4_hash_table, GUINT_TO_POINTER(addr), tp);
} else if ((tp->flags & DUMMY_AND_RESOLVE_FLGS) != DUMMY_ADDRESS_ENTRY) {
return tp;
}
fill_dummy_ip4(addr, tp);
if (!gbl_resolv_flags.network_name)
return tp;
if (gbl_resolv_flags.use_external_net_name_resolver) {
tp->flags |= TRIED_RESOLVE_ADDRESS;
#ifdef HAVE_C_ARES
if (async_dns_initialized && name_resolve_concurrency > 0) {
add_async_dns_ipv4(AF_INET, addr);
}
#endif
}
return tp;
}
static hashipv6_t *
new_ipv6(const struct e_in6_addr *addr)
{
hashipv6_t *tp = wmem_new(wmem_epan_scope(), hashipv6_t);
memcpy(tp->addr, addr->bytes, sizeof tp->addr);
tp->flags = 0;
tp->name[0] = '\0';
ip6_to_str_buf(addr, tp->ip6, sizeof(tp->ip6));
return tp;
}
static hashipv6_t *
host_lookup6(const struct e_in6_addr *addr)
{
hashipv6_t * volatile tp;
#ifdef HAVE_C_ARES
async_dns_queue_msg_t *caqm;
#endif
tp = (hashipv6_t *)g_hash_table_lookup(ipv6_hash_table, addr);
if (tp == NULL) {
struct e_in6_addr *addr_key;
addr_key = wmem_new(wmem_epan_scope(), struct e_in6_addr);
tp = new_ipv6(addr);
memcpy(addr_key, addr, 16);
g_hash_table_insert(ipv6_hash_table, addr_key, tp);
} else if ((tp->flags & DUMMY_AND_RESOLVE_FLGS) != DUMMY_ADDRESS_ENTRY) {
return tp;
}
fill_dummy_ip6(tp);
if (!gbl_resolv_flags.network_name)
return tp;
if (gbl_resolv_flags.use_external_net_name_resolver) {
tp->flags |= TRIED_RESOLVE_ADDRESS;
#ifdef HAVE_C_ARES
if (async_dns_initialized && name_resolve_concurrency > 0) {
caqm = wmem_new(wmem_epan_scope(), async_dns_queue_msg_t);
caqm->family = AF_INET6;
memcpy(&caqm->addr.ip6, addr, sizeof(caqm->addr.ip6));
wmem_list_append(async_dns_queue_head, (gpointer) caqm);
}
#endif
}
return tp;
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
if (!g_ascii_isxdigit(*cp))
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
if (!g_ascii_isdigit(*cp))
return FALSE;
num = strtoul(cp, &p, 10);
if (p == cp)
return FALSE;
cp = p;
if (*cp != '\0' && !g_ascii_isspace(*cp))
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
static hashmanuf_t *manuf_hash_new_entry(const guint8 *addr, char* name)
{
int *manuf_key;
hashmanuf_t *manuf_value;
char *endp;
manuf_key = (int *)wmem_new(wmem_epan_scope(), int);
*manuf_key = (int)((addr[0] << 16) + (addr[1] << 8) + addr[2]);
manuf_value = wmem_new(wmem_epan_scope(), hashmanuf_t);
memcpy(manuf_value->addr, addr, 3);
manuf_value->status = (name != NULL) ? HASHETHER_STATUS_RESOLVED_NAME : HASHETHER_STATUS_UNRESOLVED;
if (name != NULL) {
g_strlcpy(manuf_value->resolved_name, name, MAXNAMELEN);
manuf_value->status = HASHETHER_STATUS_RESOLVED_NAME;
}
else {
manuf_value->status = HASHETHER_STATUS_UNRESOLVED;
manuf_value->resolved_name[0] = '\0';
}
endp = bytes_to_hexstr_punct(manuf_value->hexaddr, addr, sizeof(manuf_value->addr), ':');
*endp = '\0';
g_hash_table_insert(manuf_hashtable, manuf_key, manuf_value);
return manuf_value;
}
static void
add_manuf_name(const guint8 *addr, unsigned int mask, gchar *name)
{
guint8 *wka_key;
if (mask >= 48) {
add_eth_name(addr, name);
return;
}
if (mask == 0) {
manuf_hash_new_entry(addr, name);
return;
}
wka_key = (guint8 *)wmem_alloc(wmem_epan_scope(), 6);
memcpy(wka_key, addr, 6);
g_hash_table_insert(wka_hashtable, wka_key, wmem_strdup(wmem_epan_scope(), name));
}
static hashmanuf_t *
manuf_name_lookup(const guint8 *addr)
{
gint32 manuf_key = 0;
guint8 oct;
hashmanuf_t *manuf_value;
manuf_key = addr[0];
manuf_key = manuf_key<<8;
oct = addr[1];
manuf_key = manuf_key | oct;
manuf_key = manuf_key<<8;
oct = addr[2];
manuf_key = manuf_key | oct;
manuf_value = (hashmanuf_t*)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if (manuf_value != NULL) {
return manuf_value;
}
if ((manuf_key & 0x00010000) != 0) {
manuf_key &= 0x00FEFFFF;
manuf_value = (hashmanuf_t*)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if (manuf_value != NULL) {
return manuf_value;
}
}
return manuf_hash_new_entry(addr, NULL);
}
static gchar *
wka_name_lookup(const guint8 *addr, const unsigned int mask)
{
guint8 masked_addr[6];
guint num;
gint i;
gchar *name;
if (wka_hashtable == NULL) {
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
guint get_hash_ether_status(hashether_t* ether)
{
return ether->status;
}
char* get_hash_ether_hexaddr(hashether_t* ether)
{
return ether->hexaddr;
}
char* get_hash_ether_resolved_name(hashether_t* ether)
{
return ether->resolved_name;
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
guint mask = 0;
wka_hashtable = g_hash_table_new(eth_addr_hash, eth_addr_cmp);
manuf_hashtable = g_hash_table_new(g_int_hash, g_int_equal);
eth_hashtable = g_hash_table_new(eth_addr_hash, eth_addr_cmp);
if (g_ethers_path == NULL) {
g_ethers_path = wmem_strdup_printf(wmem_epan_scope(), "%s" G_DIR_SEPARATOR_S "%s",
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
if (manuf_hashtable) {
g_hash_table_destroy(manuf_hashtable);
manuf_hashtable = NULL;
}
if (wka_hashtable) {
g_hash_table_destroy(wka_hashtable);
wka_hashtable = NULL;
}
if (eth_hashtable) {
g_hash_table_destroy(eth_hashtable);
eth_hashtable = NULL;
}
}
static hashether_t *
eth_addr_resolve(hashether_t *tp) {
ether_t *eth;
hashmanuf_t *manuf_value;
const guint8 *addr = tp->addr;
if ( (eth = get_ethbyaddr(addr)) != NULL) {
g_strlcpy(tp->resolved_name, eth->name, MAXNAMELEN);
tp->status = HASHETHER_STATUS_RESOLVED_NAME;
return tp;
} else {
guint mask;
gchar *name;
address ether_addr;
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
manuf_value = manuf_name_lookup(addr);
if ((manuf_value != NULL) && (manuf_value->status != HASHETHER_STATUS_UNRESOLVED)) {
g_snprintf(tp->resolved_name, MAXNAMELEN, "%s_%02x:%02x:%02x",
manuf_value->resolved_name, addr[3], addr[4], addr[5]);
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
set_address(&ether_addr, AT_ETHER, 6, addr);
address_to_str_buf(&ether_addr, tp->resolved_name, MAXNAMELEN);
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
tp = wmem_new(wmem_epan_scope(), hashether_t);
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
if (tp == NULL) {
tp = eth_hash_new_entry(addr, FALSE);
}
if (strcmp(tp->resolved_name, name) != 0) {
g_strlcpy(tp->resolved_name, name, MAXNAMELEN);
tp->status = HASHETHER_STATUS_RESOLVED_NAME;
new_resolved_objects = TRUE;
}
return tp;
}
static hashether_t *
eth_name_lookup(const guint8 *addr, const gboolean resolve)
{
hashether_t *tp;
tp = (hashether_t *)g_hash_table_lookup(eth_hashtable, addr);
if (tp == NULL) {
tp = eth_hash_new_entry(addr, resolve);
} else {
if (resolve && (tp->status == HASHETHER_STATUS_UNRESOLVED)) {
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
g_ipxnets_path = wmem_strdup_printf(wmem_epan_scope(), "%s" G_DIR_SEPARATOR_S "%s",
get_systemfile_dir(), ENAME_IPXNETS);
}
if (g_pipxnets_path == NULL)
g_pipxnets_path = get_persconffile_path(ENAME_IPXNETS, FALSE);
}
static void
ipx_name_lookup_cleanup(void)
{
if (ipxnet_hash_table) {
g_hash_table_destroy(ipxnet_hash_table);
ipxnet_hash_table = NULL;
}
}
static gchar *
ipxnet_name_lookup(wmem_allocator_t *allocator, const guint addr)
{
hashipxnet_t *tp;
ipxnet_t *ipxnet;
tp = (hashipxnet_t *)g_hash_table_lookup(ipxnet_hash_table, &addr);
if (tp == NULL) {
int *key;
key = (int *)wmem_new(wmem_epan_scope(), int);
*key = addr;
tp = wmem_new(wmem_epan_scope(), hashipxnet_t);
g_hash_table_insert(ipxnet_hash_table, key, tp);
} else {
return wmem_strdup(allocator, tp->name);
}
tp->addr = addr;
if ( (ipxnet = get_ipxnetbyaddr(addr)) == NULL) {
g_snprintf(tp->name, MAXNAMELEN, "%X", addr);
} else {
g_strlcpy(tp->name, ipxnet->name, MAXNAMELEN);
}
return wmem_strdup(allocator, tp->name);
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
static int
parse_vlan_line(char *line, vlan_t *vlan)
{
gchar *cp;
guint16 id;
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t\n")) == NULL)
return -1;
if (sscanf(cp, "%" G_GUINT16_FORMAT, &id) == 1) {
vlan->id = id;
}
else {
return -1;
}
if ((cp = strtok(NULL, "\t\n")) == NULL)
return -1;
g_strlcpy(vlan->name, cp, MAXVLANNAMELEN);
return 0;
}
static void
set_vlanent(char *path)
{
if (vlan_p)
rewind(vlan_p);
else
vlan_p = ws_fopen(path, "r");
}
static void
end_vlanent(void)
{
if (vlan_p) {
fclose(vlan_p);
vlan_p = NULL;
}
}
static vlan_t *
get_vlanent(void)
{
static vlan_t vlan;
static int size = 0;
static char *buf = NULL;
if (vlan_p == NULL)
return NULL;
while (fgetline(&buf, &size, vlan_p) >= 0) {
if (parse_vlan_line(buf, &vlan) == 0) {
return &vlan;
}
}
return NULL;
}
static vlan_t *
get_vlannamebyid(guint16 id)
{
vlan_t *vlan;
set_vlanent(g_pvlan_path);
while (((vlan = get_vlanent()) != NULL) && (id != vlan->id) ) ;
if (vlan == NULL) {
end_vlanent();
}
return vlan;
}
static void
initialize_vlans(void)
{
g_assert(vlan_hash_table == NULL);
vlan_hash_table = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, g_free);
if (g_pvlan_path == NULL)
g_pvlan_path = get_persconffile_path(ENAME_VLANS, FALSE);
}
static void
vlan_name_lookup_cleanup(void)
{
if (vlan_hash_table) {
g_hash_table_destroy(vlan_hash_table);
vlan_hash_table = NULL;
}
}
static const gchar *
vlan_name_lookup(const guint id)
{
hashvlan_t *tp;
vlan_t *vlan;
tp = (hashvlan_t *)g_hash_table_lookup(vlan_hash_table, &id);
if (tp == NULL) {
int *key;
key = (int *)wmem_new(wmem_epan_scope(), int);
*key = id;
tp = wmem_new(wmem_epan_scope(), hashvlan_t);
g_hash_table_insert(vlan_hash_table, key, tp);
} else {
return tp->name;
}
tp->id = id;
if ( (vlan = get_vlannamebyid(id)) == NULL) {
g_snprintf(tp->name, MAXVLANNAMELEN, "<%u>", id);
} else {
g_strlcpy(tp->name, vlan->name, MAXVLANNAMELEN);
}
return tp->name;
}
static gboolean
read_hosts_file (const char *hostspath, gboolean store_entries)
{
FILE *hf;
char *line = NULL;
int size = 0;
gchar *cp;
union {
guint32 ip4_addr;
struct e_in6_addr ip6_addr;
} host_addr;
gboolean is_ipv6, entry_found = FALSE;
if ((hf = ws_fopen(hostspath, "r")) == NULL)
return FALSE;
while (fgetline(&line, &size, hf) >= 0) {
if ((cp = strchr(line, '#')))
*cp = '\0';
if ((cp = strtok(line, " \t")) == NULL)
continue;
if (ws_inet_pton6(cp, &host_addr.ip6_addr)) {
is_ipv6 = TRUE;
} else if (ws_inet_pton4(cp, &host_addr.ip4_addr)) {
is_ipv6 = FALSE;
} else {
continue;
}
if ((cp = strtok(NULL, " \t")) == NULL)
continue;
entry_found = TRUE;
if (store_entries) {
if (is_ipv6) {
add_ipv6_name(&host_addr.ip6_addr, cp);
} else {
add_ipv4_name(host_addr.ip4_addr, cp);
}
}
}
wmem_free(wmem_epan_scope(), line);
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
g_ptr_array_add(extra_hosts_files, wmem_strdup(wmem_epan_scope(), hosts_file));
return read_hosts_file (hosts_file, FALSE);
}
return TRUE;
}
gboolean
add_ip_name_from_string (const char *addr, const char *name)
{
union {
guint32 ip4_addr;
struct e_in6_addr ip6_addr;
} host_addr;
gboolean is_ipv6;
resolved_ipv4_t *resolved_ipv4_entry;
resolved_ipv6_t *resolved_ipv6_entry;
if (ws_inet_pton6(addr, &host_addr.ip6_addr)) {
is_ipv6 = TRUE;
} else if (ws_inet_pton4(addr, &host_addr.ip4_addr)) {
is_ipv6 = FALSE;
} else {
return FALSE;
}
if (is_ipv6) {
resolved_ipv6_entry = wmem_new(wmem_epan_scope(), resolved_ipv6_t);
memcpy(&(resolved_ipv6_entry->ip6_addr), &host_addr.ip6_addr, 16);
g_strlcpy(resolved_ipv6_entry->name, name, MAXNAMELEN);
wmem_list_prepend(manually_resolved_ipv6_list, resolved_ipv6_entry);
} else {
resolved_ipv4_entry = wmem_new(wmem_epan_scope(), resolved_ipv4_t);
resolved_ipv4_entry->host_addr = host_addr.ip4_addr;
g_strlcpy(resolved_ipv4_entry->name, name, MAXNAMELEN);
wmem_list_prepend(manually_resolved_ipv4_list, resolved_ipv4_entry);
}
return TRUE;
}
static void
ipv4_hash_table_resolved_to_list(gpointer key _U_, gpointer value, gpointer user_data)
{
addrinfo_lists_t *lists = (addrinfo_lists_t*)user_data;
hashipv4_t *ipv4_hash_table_entry = (hashipv4_t *)value;
if ((ipv4_hash_table_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED) {
lists->ipv4_addr_list = g_list_prepend(lists->ipv4_addr_list, ipv4_hash_table_entry);
}
}
static void
ipv6_hash_table_resolved_to_list(gpointer key _U_, gpointer value, gpointer user_data)
{
addrinfo_lists_t *lists = (addrinfo_lists_t*)user_data;
hashipv6_t *ipv6_hash_table_entry = (hashipv6_t *)value;
if ((ipv6_hash_table_entry->flags & USED_AND_RESOLVED_MASK) == RESOLVED_ADDRESS_USED) {
lists->ipv6_addr_list = g_list_prepend (lists->ipv6_addr_list, ipv6_hash_table_entry);
}
}
addrinfo_lists_t *
get_addrinfo_list(void) {
if (ipv4_hash_table) {
g_hash_table_foreach(ipv4_hash_table, ipv4_hash_table_resolved_to_list, &addrinfo_lists);
}
if (ipv6_hash_table) {
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
if (NULL == cp2) {
continue;
}
*cp2 = '\0';
++cp2 ;
if (!str_to_ip(cp, &host_addr)) {
continue;
}
mask_length = atoi(cp2);
if (0 >= mask_length || mask_length > 32) {
continue;
}
if ((cp = strtok(NULL, " \t")) == NULL)
continue;
subnet_entry_set(host_addr, (guint32)mask_length, cp);
}
wmem_free(wmem_epan_scope(), line);
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
if (NULL != length_entry->subnet_addresses) {
sub_net_hashipv4_t * tp;
guint32 hash_idx;
masked_addr = addr & length_entry->mask;
hash_idx = HASH_IPV4_ADDRESS(masked_addr);
tp = length_entry->subnet_addresses[hash_idx];
while(tp != NULL && tp->addr != masked_addr) {
tp = tp->next;
}
if (NULL != tp) {
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
if (NULL == entry->subnet_addresses) {
entry->subnet_addresses = (sub_net_hashipv4_t**)wmem_alloc0(wmem_epan_scope(), sizeof(sub_net_hashipv4_t*) * HASHHOSTSIZE);
}
if (NULL != (tp = entry->subnet_addresses[hash_idx])) {
sub_net_hashipv4_t * new_tp;
while (tp->next) {
if (tp->addr == subnet_addr) {
return;
} else {
tp = tp->next;
}
}
new_tp = wmem_new(wmem_epan_scope(), sub_net_hashipv4_t);
tp->next = new_tp;
tp = new_tp;
} else {
tp = entry->subnet_addresses[hash_idx] = wmem_new(wmem_epan_scope(), sub_net_hashipv4_t);
}
tp->next = NULL;
tp->addr = subnet_addr;
tp->flags &= ~DUMMY_ADDRESS_ENTRY;
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
prefs_register_bool_preference(nameres, "dns_pkt_addr_resolution",
"Use captured DNS packet data for address resolution",
"Whether address/name pairs found in captured DNS packets should be used by Wireshark for name resolution.",
&gbl_resolv_flags.dns_pkt_addr_resolution);
#ifdef HAVE_C_ARES
prefs_register_bool_preference(nameres, "use_external_name_resolver",
"Use an external network name resolver",
"Use your system's configured name resolver"
" (usually DNS) to resolve network names."
" Only applies when network name resolution"
" is enabled.",
&gbl_resolv_flags.use_external_net_name_resolver);
prefs_register_obsolete_preference(nameres, "concurrent_dns");
prefs_register_uint_preference(nameres, "name_resolve_concurrency",
"Maximum concurrent requests",
"The maximum number of DNS requests that may"
" be active at any time. A large value (many"
" thousands) might overload the network or make"
" your DNS server behave badly.",
10,
&name_resolve_concurrency);
#else
prefs_register_static_text_preference(nameres, "use_external_name_resolver",
"Use an external network name resolver: N/A",
"Support for using a concurrent external name resolver was not"
" compiled into this version of Wireshark");
#endif
prefs_register_bool_preference(nameres, "hosts_file_handling",
"Only use the profile \"hosts\" file",
"By default \"hosts\" files will be loaded from multiple sources."
" Checking this box only loads the \"hosts\" in the current profile.",
&gbl_resolv_flags.load_hosts_file_from_profile_only);
prefs_register_bool_preference(nameres, "vlan_name",
"Resolve VLAN IDs",
"Resolve VLAN IDs to describing names."
" To do so you need a file called vlans in your"
" user preference directory. Format of the file is:"
" \"ID<Tab>Name\""
" One line per VLAN.",
&gbl_resolv_flags.vlan_name);
}
void
disable_name_resolution(void) {
gbl_resolv_flags.mac_name = FALSE;
gbl_resolv_flags.network_name = FALSE;
gbl_resolv_flags.transport_name = FALSE;
gbl_resolv_flags.dns_pkt_addr_resolution = FALSE;
gbl_resolv_flags.use_external_net_name_resolver = FALSE;
gbl_resolv_flags.vlan_name = FALSE;
}
gboolean
host_name_lookup_process(void) {
async_dns_queue_msg_t *caqm;
struct timeval tv = { 0, 0 };
int nfds;
fd_set rfds, wfds;
gboolean nro = new_resolved_objects;
wmem_list_frame_t* head;
new_resolved_objects = FALSE;
if (!async_dns_initialized)
return nro;
head = wmem_list_head(async_dns_queue_head);
while (head != NULL && async_dns_in_flight <= name_resolve_concurrency) {
caqm = (async_dns_queue_msg_t *)wmem_list_frame_data(head);
wmem_list_remove_frame(async_dns_queue_head, head);
if (caqm->family == AF_INET) {
ares_gethostbyaddr(ghba_chan, &caqm->addr.ip4, sizeof(guint32), AF_INET,
c_ares_ghba_cb, caqm);
async_dns_in_flight++;
} else if (caqm->family == AF_INET6) {
ares_gethostbyaddr(ghba_chan, &caqm->addr.ip6, sizeof(struct e_in6_addr),
AF_INET6, c_ares_ghba_cb, caqm);
async_dns_in_flight++;
}
head = wmem_list_head(async_dns_queue_head);
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
hashipv4_t *tp = host_lookup(addr);
if (!gbl_resolv_flags.network_name)
return tp->ip;
tp->flags |= RESOLVED_ADDRESS_USED;
return tp->name;
}
const gchar *
get_hostname6(const struct e_in6_addr *addr)
{
hashipv6_t *tp = host_lookup6(addr);
if (!gbl_resolv_flags.network_name)
return tp->ip6;
tp->flags |= RESOLVED_ADDRESS_USED;
return tp->name;
}
void
add_ipv4_name(const guint addr, const gchar *name)
{
hashipv4_t *tp;
if (!name || name[0] == '\0')
return;
tp = (hashipv4_t *)g_hash_table_lookup(ipv4_hash_table, GUINT_TO_POINTER(addr));
if (!tp) {
tp = new_ipv4(addr);
g_hash_table_insert(ipv4_hash_table, GUINT_TO_POINTER(addr), tp);
}
if (g_ascii_strcasecmp(tp->name, name)) {
g_strlcpy(tp->name, name, MAXNAMELEN);
new_resolved_objects = TRUE;
}
tp->flags |= TRIED_RESOLVE_ADDRESS|NAME_RESOLVED;
}
void
add_ipv6_name(const struct e_in6_addr *addrp, const gchar *name)
{
hashipv6_t *tp;
if (!name || name[0] == '\0')
return;
tp = (hashipv6_t *)g_hash_table_lookup(ipv6_hash_table, addrp);
if (!tp) {
struct e_in6_addr *addr_key;
addr_key = wmem_new(wmem_epan_scope(), struct e_in6_addr);
tp = new_ipv6(addrp);
memcpy(addr_key, addrp, 16);
g_hash_table_insert(ipv6_hash_table, addr_key, tp);
}
if (g_ascii_strcasecmp(tp->name, name)) {
g_strlcpy(tp->name, name, MAXNAMELEN);
new_resolved_objects = TRUE;
}
tp->flags |= TRIED_RESOLVE_ADDRESS|NAME_RESOLVED;
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
if (manually_resolved_ipv4_list) {
wmem_list_foreach(manually_resolved_ipv4_list, add_manually_resolved_ipv4, NULL);
}
if (manually_resolved_ipv6_list) {
wmem_list_foreach(manually_resolved_ipv6_list, add_manually_resolved_ipv6, NULL);
}
}
void
host_name_lookup_init(void)
{
char *hostspath;
guint i;
g_assert(ipxnet_hash_table == NULL);
ipxnet_hash_table = g_hash_table_new(g_int_hash, g_int_equal);
g_assert(ipv4_hash_table == NULL);
ipv4_hash_table = g_hash_table_new(g_direct_hash, g_direct_equal);
g_assert(ipv6_hash_table == NULL);
ipv6_hash_table = g_hash_table_new(ipv6_oat_hash, ipv6_equal);
#ifdef HAVE_C_ARES
g_assert(async_dns_queue_head == NULL);
async_dns_queue_head = wmem_list_new(wmem_epan_scope());
#endif
if (manually_resolved_ipv4_list == NULL)
manually_resolved_ipv4_list = wmem_list_new(wmem_epan_scope());
if (manually_resolved_ipv6_list == NULL)
manually_resolved_ipv6_list = wmem_list_new(wmem_epan_scope());
if (!gbl_resolv_flags.load_hosts_file_from_profile_only) {
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
#endif
if (extra_hosts_files && !gbl_resolv_flags.load_hosts_file_from_profile_only) {
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
guint32 i, j;
sub_net_hashipv4_t *entry, *next_entry;
_host_name_lookup_cleanup();
if (ipxnet_hash_table) {
g_hash_table_destroy(ipxnet_hash_table);
ipxnet_hash_table = NULL;
}
if (ipv4_hash_table) {
g_hash_table_destroy(ipv4_hash_table);
ipv4_hash_table = NULL;
}
if (ipv6_hash_table) {
g_hash_table_destroy(ipv6_hash_table);
ipv6_hash_table = NULL;
}
for(i = 0; i < SUBNETLENGTHSIZE; ++i) {
if (subnet_length_entries[i].subnet_addresses != NULL) {
for (j = 0; j < HASHHOSTSIZE; j++) {
for (entry = subnet_length_entries[i].subnet_addresses[j];
entry != NULL; entry = next_entry) {
next_entry = entry->next;
wmem_free(wmem_epan_scope(), entry);
}
}
wmem_free(wmem_epan_scope(), subnet_length_entries[i].subnet_addresses);
subnet_length_entries[i].subnet_addresses = NULL;
}
}
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
if (manually_resolved_ipv4_list) {
wmem_list_foreach(manually_resolved_ipv4_list, free_manually_resolved_ipv4, NULL);
manually_resolved_ipv4_list = NULL;
}
if (manually_resolved_ipv6_list) {
wmem_list_foreach(manually_resolved_ipv6_list, free_manually_resolved_ipv6, NULL);
manually_resolved_ipv6_list = NULL;
}
}
gchar *
udp_port_to_display(wmem_allocator_t *allocator, guint port)
{
if (!gbl_resolv_flags.transport_name) {
return wmem_utoa(allocator, port);
}
return wmem_strdup(allocator, serv_name_lookup(PT_UDP, port));
}
gchar *
dccp_port_to_display(wmem_allocator_t *allocator, guint port)
{
if (!gbl_resolv_flags.transport_name) {
return wmem_utoa(allocator, port);
}
return wmem_strdup(allocator, serv_name_lookup(PT_DCCP, port));
}
gchar *
tcp_port_to_display(wmem_allocator_t *allocator, guint port)
{
if (!gbl_resolv_flags.transport_name) {
return wmem_utoa(allocator, port);
}
return wmem_strdup(allocator, serv_name_lookup(PT_TCP, port));
}
gchar *
sctp_port_to_display(wmem_allocator_t *allocator, guint port)
{
if (!gbl_resolv_flags.transport_name) {
return wmem_utoa(allocator, port);
}
return wmem_strdup(allocator, serv_name_lookup(PT_SCTP, port));
}
gchar *
port_with_resolution_to_str(wmem_allocator_t *scope, port_type proto, guint port)
{
const gchar *port_str;
if (!gbl_resolv_flags.transport_name || (proto == PT_NONE)) {
return wmem_strdup_printf(scope, "%u", port);
}
port_str = serv_name_lookup(proto, port);
g_assert(port_str);
return wmem_strdup_printf(scope, "%s (%u)", port_str, port);
}
int
port_with_resolution_to_str_buf(gchar *buf, gulong buf_size, port_type proto, guint port)
{
const gchar *port_str;
if (!gbl_resolv_flags.transport_name || (proto == PT_NONE)) {
return g_snprintf(buf, buf_size, "%u", port);
}
port_str = serv_name_lookup(proto, port);
g_assert(port_str);
return g_snprintf(buf, buf_size, "%s (%u)", port_str, port);
}
const gchar *
get_ether_name(const guint8 *addr)
{
hashether_t *tp;
gboolean resolve = gbl_resolv_flags.mac_name;
tp = eth_name_lookup(addr, resolve);
return resolve ? tp->resolved_name : tp->hexaddr;
}
const gchar *
tvb_get_ether_name(tvbuff_t *tvb, gint offset)
{
return get_ether_name(tvb_get_ptr(tvb, offset, 6));
}
const gchar *
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
hashipv4_t *tp;
if (!gbl_resolv_flags.network_name)
return;
tp = host_lookup(ip);
if (tp->flags & NAME_RESOLVED) {
add_eth_name(eth, tp->name);
}
}
gchar *
ipxnet_to_str_punct(wmem_allocator_t *allocator, const guint32 ad, const char punct)
{
gchar *buf = (gchar *)wmem_alloc(allocator, 12);
*dword_to_hex_punct(buf, ad, punct) = '\0';
return buf;
}
gchar *
get_ipxnet_name(wmem_allocator_t *allocator, const guint32 addr)
{
if (!gbl_resolv_flags.network_name) {
return ipxnet_to_str_punct(allocator, addr, '\0');
}
return ipxnet_name_lookup(allocator, addr);
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
gchar *
get_vlan_name(wmem_allocator_t *allocator, const guint16 id)
{
if (!gbl_resolv_flags.vlan_name) {
return NULL;
}
return wmem_strdup(allocator, vlan_name_lookup(id));
}
const gchar *
get_manuf_name(const guint8 *addr)
{
hashmanuf_t *manuf_value;
manuf_value = manuf_name_lookup(addr);
if (gbl_resolv_flags.mac_name && manuf_value->status != HASHETHER_STATUS_UNRESOLVED)
return manuf_value->resolved_name;
return manuf_value->hexaddr;
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
hashmanuf_t *manuf_value;
int manuf_key;
guint8 oct;
manuf_key = addr[0];
manuf_key = manuf_key<<8;
oct = addr[1];
manuf_key = manuf_key | oct;
manuf_key = manuf_key<<8;
oct = addr[2];
manuf_key = manuf_key | oct;
manuf_value = (hashmanuf_t *)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if ((manuf_value == NULL) || (manuf_value->status != HASHETHER_STATUS_UNRESOLVED)) {
return NULL;
}
return manuf_value->resolved_name;
}
const gchar *
uint_get_manuf_name_if_known(const guint manuf_key)
{
hashmanuf_t *manuf_value;
manuf_value = (hashmanuf_t *)g_hash_table_lookup(manuf_hashtable, &manuf_key);
if ((manuf_value == NULL) || (manuf_value->status != HASHETHER_STATUS_UNRESOLVED)) {
return NULL;
}
return manuf_value->resolved_name;
}
const gchar *
tvb_get_manuf_name_if_known(tvbuff_t *tvb, gint offset)
{
return get_manuf_name_if_known(tvb_get_ptr(tvb, offset, 3));
}
char* get_hash_manuf_resolved_name(hashmanuf_t* manuf)
{
return manuf->resolved_name;
}
gchar *
eui64_to_display(wmem_allocator_t *allocator, const guint64 addr_eui64)
{
guint8 *addr = (guint8 *)wmem_alloc(NULL, 8);
hashmanuf_t *manuf_value;
gchar *ret;
*(guint64 *)(void *)(addr) = pntoh64(&(addr_eui64));
manuf_value = manuf_name_lookup(addr);
if (!gbl_resolv_flags.mac_name || (manuf_value->status == HASHETHER_STATUS_UNRESOLVED)) {
ret = wmem_strdup_printf(allocator, "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7]);
} else {
ret = wmem_strdup_printf(allocator, "%s_%02x:%02x:%02x:%02x:%02x", manuf_value->resolved_name, addr[3], addr[4], addr[5], addr[6], addr[7]);
}
wmem_free(NULL, addr);
return ret;
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
#endif
if (!inet_aton(host, &ipaddr)) {
if (!gbl_resolv_flags.network_name ||
!gbl_resolv_flags.use_external_net_name_resolver) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (!async_dns_initialized || name_resolve_concurrency < 1) {
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
#endif
if (str_to_ip6(host, addrp))
return TRUE;
if (!gbl_resolv_flags.network_name ||
!gbl_resolv_flags.use_external_net_name_resolver) {
return FALSE;
}
#ifdef HAVE_C_ARES
if (!async_dns_initialized || name_resolve_concurrency < 1) {
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
#endif
return FALSE;
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
get_vlan_hash_table(void)
{
return vlan_hash_table;
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
initialize_vlans();
}
void
addr_resolv_cleanup(void)
{
service_name_lookup_cleanup();
eth_name_lookup_cleanup();
ipx_name_lookup_cleanup();
vlan_name_lookup_cleanup();
}
gboolean
str_to_ip(const char *str, void *dst)
{
return ws_inet_pton4(str, (guint32 *)dst);
}
gboolean
str_to_ip6(const char *str, void *dst)
{
return ws_inet_pton6(str, (struct e_in6_addr *)dst);
}
