void libcfs_init_nidstrings(void)
{
spin_lock_init(&libcfs_nidstring_lock);
}
static char *
libcfs_next_nidstring(void)
{
char *str;
unsigned long flags;
spin_lock_irqsave(&libcfs_nidstring_lock, flags);
str = libcfs_nidstrings[libcfs_nidstring_idx++];
if (libcfs_nidstring_idx ==
sizeof(libcfs_nidstrings)/sizeof(libcfs_nidstrings[0]))
libcfs_nidstring_idx = 0;
spin_unlock_irqrestore(&libcfs_nidstring_lock, flags);
return str;
}
int
libcfs_lo_str2addr(const char *str, int nob, __u32 *addr)
{
*addr = 0;
return 1;
}
void
libcfs_ip_addr2str(__u32 addr, char *str)
{
#if 0
#endif
snprintf(str, LNET_NIDSTR_SIZE, "%u.%u.%u.%u",
(addr >> 24) & 0xff, (addr >> 16) & 0xff,
(addr >> 8) & 0xff, addr & 0xff);
}
int
libcfs_ip_str2addr(const char *str, int nob, __u32 *addr)
{
int a;
int b;
int c;
int d;
int n = nob;
if (sscanf(str, "%u.%u.%u.%u%n", &a, &b, &c, &d, &n) >= 4 &&
n == nob &&
(a & ~0xff) == 0 && (b & ~0xff) == 0 &&
(c & ~0xff) == 0 && (d & ~0xff) == 0) {
*addr = ((a<<24)|(b<<16)|(c<<8)|d);
return 1;
}
return 0;
}
void
libcfs_decnum_addr2str(__u32 addr, char *str)
{
snprintf(str, LNET_NIDSTR_SIZE, "%u", addr);
}
void
libcfs_hexnum_addr2str(__u32 addr, char *str)
{
snprintf(str, LNET_NIDSTR_SIZE, "0x%x", addr);
}
int
libcfs_num_str2addr(const char *str, int nob, __u32 *addr)
{
int n;
n = nob;
if (sscanf(str, "0x%x%n", addr, &n) >= 1 && n == nob)
return 1;
n = nob;
if (sscanf(str, "0X%x%n", addr, &n) >= 1 && n == nob)
return 1;
n = nob;
if (sscanf(str, "%u%n", addr, &n) >= 1 && n == nob)
return 1;
return 0;
}
struct netstrfns *
libcfs_lnd2netstrfns(int lnd)
{
int i;
if (lnd >= 0)
for (i = 0; i < libcfs_nnetstrfns; i++)
if (lnd == libcfs_netstrfns[i].nf_type)
return &libcfs_netstrfns[i];
return NULL;
}
struct netstrfns *
libcfs_namenum2netstrfns(const char *name)
{
struct netstrfns *nf;
int i;
for (i = 0; i < libcfs_nnetstrfns; i++) {
nf = &libcfs_netstrfns[i];
if (nf->nf_type >= 0 &&
!strncmp(name, nf->nf_name, strlen(nf->nf_name)))
return nf;
}
return NULL;
}
struct netstrfns *
libcfs_name2netstrfns(const char *name)
{
int i;
for (i = 0; i < libcfs_nnetstrfns; i++)
if (libcfs_netstrfns[i].nf_type >= 0 &&
!strcmp(libcfs_netstrfns[i].nf_name, name))
return &libcfs_netstrfns[i];
return NULL;
}
int
libcfs_isknown_lnd(int type)
{
return libcfs_lnd2netstrfns(type) != NULL;
}
char *
libcfs_lnd2modname(int lnd)
{
struct netstrfns *nf = libcfs_lnd2netstrfns(lnd);
return (nf == NULL) ? NULL : nf->nf_modname;
}
char *
libcfs_lnd2str(int lnd)
{
char *str;
struct netstrfns *nf = libcfs_lnd2netstrfns(lnd);
if (nf != NULL)
return nf->nf_name;
str = libcfs_next_nidstring();
snprintf(str, LNET_NIDSTR_SIZE, "?%u?", lnd);
return str;
}
int
libcfs_str2lnd(const char *str)
{
struct netstrfns *nf = libcfs_name2netstrfns(str);
if (nf != NULL)
return nf->nf_type;
return -1;
}
char *
libcfs_net2str(__u32 net)
{
int lnd = LNET_NETTYP(net);
int num = LNET_NETNUM(net);
struct netstrfns *nf = libcfs_lnd2netstrfns(lnd);
char *str = libcfs_next_nidstring();
if (nf == NULL)
snprintf(str, LNET_NIDSTR_SIZE, "<%u:%u>", lnd, num);
else if (num == 0)
snprintf(str, LNET_NIDSTR_SIZE, "%s", nf->nf_name);
else
snprintf(str, LNET_NIDSTR_SIZE, "%s%u", nf->nf_name, num);
return str;
}
char *
libcfs_nid2str(lnet_nid_t nid)
{
__u32 addr = LNET_NIDADDR(nid);
__u32 net = LNET_NIDNET(nid);
int lnd = LNET_NETTYP(net);
int nnum = LNET_NETNUM(net);
struct netstrfns *nf;
char *str;
int nob;
if (nid == LNET_NID_ANY)
return "<?>";
nf = libcfs_lnd2netstrfns(lnd);
str = libcfs_next_nidstring();
if (nf == NULL)
snprintf(str, LNET_NIDSTR_SIZE, "%x@<%u:%u>", addr, lnd, nnum);
else {
nf->nf_addr2str(addr, str);
nob = strlen(str);
if (nnum == 0)
snprintf(str + nob, LNET_NIDSTR_SIZE - nob, "@%s",
nf->nf_name);
else
snprintf(str + nob, LNET_NIDSTR_SIZE - nob, "@%s%u",
nf->nf_name, nnum);
}
return str;
}
static struct netstrfns *
libcfs_str2net_internal(const char *str, __u32 *net)
{
struct netstrfns *uninitialized_var(nf);
int nob;
int netnum;
int i;
for (i = 0; i < libcfs_nnetstrfns; i++) {
nf = &libcfs_netstrfns[i];
if (nf->nf_type >= 0 &&
!strncmp(str, nf->nf_name, strlen(nf->nf_name)))
break;
}
if (i == libcfs_nnetstrfns)
return NULL;
nob = strlen(nf->nf_name);
if (strlen(str) == (unsigned int)nob) {
netnum = 0;
} else {
if (nf->nf_type == LOLND)
return NULL;
str += nob;
i = strlen(str);
if (sscanf(str, "%u%n", &netnum, &i) < 1 ||
i != (int)strlen(str))
return NULL;
}
*net = LNET_MKNET(nf->nf_type, netnum);
return nf;
}
__u32
libcfs_str2net(const char *str)
{
__u32 net;
if (libcfs_str2net_internal(str, &net) != NULL)
return net;
return LNET_NIDNET(LNET_NID_ANY);
}
lnet_nid_t
libcfs_str2nid(const char *str)
{
const char *sep = strchr(str, '@');
struct netstrfns *nf;
__u32 net;
__u32 addr;
if (sep != NULL) {
nf = libcfs_str2net_internal(sep + 1, &net);
if (nf == NULL)
return LNET_NID_ANY;
} else {
sep = str + strlen(str);
net = LNET_MKNET(SOCKLND, 0);
nf = libcfs_lnd2netstrfns(SOCKLND);
LASSERT(nf != NULL);
}
if (!nf->nf_str2addr(str, (int)(sep - str), &addr))
return LNET_NID_ANY;
return LNET_MKNID(net, addr);
}
char *
libcfs_id2str(lnet_process_id_t id)
{
char *str = libcfs_next_nidstring();
if (id.pid == LNET_PID_ANY) {
snprintf(str, LNET_NIDSTR_SIZE,
"LNET_PID_ANY-%s", libcfs_nid2str(id.nid));
return str;
}
snprintf(str, LNET_NIDSTR_SIZE, "%s%u-%s",
((id.pid & LNET_PID_USERFLAG) != 0) ? "U" : "",
(id.pid & ~LNET_PID_USERFLAG), libcfs_nid2str(id.nid));
return str;
}
int
libcfs_str2anynid(lnet_nid_t *nidp, const char *str)
{
if (!strcmp(str, "*")) {
*nidp = LNET_NID_ANY;
return 1;
}
*nidp = libcfs_str2nid(str);
return *nidp != LNET_NID_ANY;
}
static int
libcfs_num_parse(char *str, int len, struct list_head *list)
{
struct cfs_expr_list *el;
int rc;
rc = cfs_expr_list_parse(str, len, 0, MAX_NUMERIC_VALUE, &el);
if (rc == 0)
list_add_tail(&el->el_link, list);
return rc;
}
static int
parse_addrange(const struct cfs_lstr *src, struct nidrange *nidrange)
{
struct addrrange *addrrange;
if (src->ls_len == 1 && src->ls_str[0] == '*') {
nidrange->nr_all = 1;
return 1;
}
LIBCFS_ALLOC(addrrange, sizeof(struct addrrange));
if (addrrange == NULL)
return 0;
list_add_tail(&addrrange->ar_link, &nidrange->nr_addrranges);
INIT_LIST_HEAD(&addrrange->ar_numaddr_ranges);
return nidrange->nr_netstrfns->nf_parse_addrlist(src->ls_str,
src->ls_len,
&addrrange->ar_numaddr_ranges);
}
static struct nidrange *
add_nidrange(const struct cfs_lstr *src,
struct list_head *nidlist)
{
struct netstrfns *nf;
struct nidrange *nr;
int endlen;
unsigned netnum;
if (src->ls_len >= LNET_NIDSTR_SIZE)
return NULL;
nf = libcfs_namenum2netstrfns(src->ls_str);
if (nf == NULL)
return NULL;
endlen = src->ls_len - strlen(nf->nf_name);
if (endlen == 0)
netnum = 0;
else {
if (!cfs_str2num_check(src->ls_str + strlen(nf->nf_name),
endlen, &netnum, 0, MAX_NUMERIC_VALUE))
return NULL;
}
list_for_each_entry(nr, nidlist, nr_link) {
if (nr->nr_netstrfns != nf)
continue;
if (nr->nr_netnum != netnum)
continue;
return nr;
}
LIBCFS_ALLOC(nr, sizeof(struct nidrange));
if (nr == NULL)
return NULL;
list_add_tail(&nr->nr_link, nidlist);
INIT_LIST_HEAD(&nr->nr_addrranges);
nr->nr_netstrfns = nf;
nr->nr_all = 0;
nr->nr_netnum = netnum;
return nr;
}
static int
parse_nidrange(struct cfs_lstr *src, struct list_head *nidlist)
{
struct cfs_lstr addrrange;
struct cfs_lstr net;
struct cfs_lstr tmp;
struct nidrange *nr;
tmp = *src;
if (cfs_gettok(src, '@', &addrrange) == 0)
goto failed;
if (cfs_gettok(src, '@', &net) == 0 || src->ls_str != NULL)
goto failed;
nr = add_nidrange(&net, nidlist);
if (nr == NULL)
goto failed;
if (parse_addrange(&addrrange, nr) != 0)
goto failed;
return 1;
failed:
CWARN("can't parse nidrange: \"%.*s\"\n", tmp.ls_len, tmp.ls_str);
return 0;
}
static void
free_addrranges(struct list_head *list)
{
while (!list_empty(list)) {
struct addrrange *ar;
ar = list_entry(list->next, struct addrrange, ar_link);
cfs_expr_list_free_list(&ar->ar_numaddr_ranges);
list_del(&ar->ar_link);
LIBCFS_FREE(ar, sizeof(struct addrrange));
}
}
void
cfs_free_nidlist(struct list_head *list)
{
struct list_head *pos, *next;
struct nidrange *nr;
list_for_each_safe(pos, next, list) {
nr = list_entry(pos, struct nidrange, nr_link);
free_addrranges(&nr->nr_addrranges);
list_del(pos);
LIBCFS_FREE(nr, sizeof(struct nidrange));
}
}
int
cfs_parse_nidlist(char *str, int len, struct list_head *nidlist)
{
struct cfs_lstr src;
struct cfs_lstr res;
int rc;
src.ls_str = str;
src.ls_len = len;
INIT_LIST_HEAD(nidlist);
while (src.ls_str) {
rc = cfs_gettok(&src, ' ', &res);
if (rc == 0) {
cfs_free_nidlist(nidlist);
return 0;
}
rc = parse_nidrange(&res, nidlist);
if (rc == 0) {
cfs_free_nidlist(nidlist);
return 0;
}
}
return 1;
}
static int
libcfs_num_match(__u32 addr, struct list_head *numaddr)
{
struct cfs_expr_list *el;
LASSERT(!list_empty(numaddr));
el = list_entry(numaddr->next, struct cfs_expr_list, el_link);
return cfs_expr_list_match(addr, el);
}
int cfs_match_nid(lnet_nid_t nid, struct list_head *nidlist)
{
struct nidrange *nr;
struct addrrange *ar;
list_for_each_entry(nr, nidlist, nr_link) {
if (nr->nr_netstrfns->nf_type != LNET_NETTYP(LNET_NIDNET(nid)))
continue;
if (nr->nr_netnum != LNET_NETNUM(LNET_NIDNET(nid)))
continue;
if (nr->nr_all)
return 1;
list_for_each_entry(ar, &nr->nr_addrranges, ar_link)
if (nr->nr_netstrfns->nf_match_addr(LNET_NIDADDR(nid),
&ar->ar_numaddr_ranges))
return 1;
}
return 0;
}
