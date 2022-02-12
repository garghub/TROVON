char *
libcfs_next_nidstring(void)
{
char *str;
unsigned long flags;
spin_lock_irqsave(&libcfs_nidstring_lock, flags);
str = libcfs_nidstrings[libcfs_nidstring_idx++];
if (libcfs_nidstring_idx == ARRAY_SIZE(libcfs_nidstrings))
libcfs_nidstring_idx = 0;
spin_unlock_irqrestore(&libcfs_nidstring_lock, flags);
return str;
}
static int
parse_addrange(const struct cfs_lstr *src, struct nidrange *nidrange)
{
struct addrrange *addrrange;
if (src->ls_len == 1 && src->ls_str[0] == '*') {
nidrange->nr_all = 1;
return 0;
}
LIBCFS_ALLOC(addrrange, sizeof(struct addrrange));
if (addrrange == NULL)
return -ENOMEM;
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
static int
cfs_print_network(char *buffer, int count, struct nidrange *nr)
{
struct netstrfns *nf = nr->nr_netstrfns;
if (nr->nr_netnum == 0)
return scnprintf(buffer, count, "@%s", nf->nf_name);
else
return scnprintf(buffer, count, "@%s%u",
nf->nf_name, nr->nr_netnum);
}
static int
cfs_print_addrranges(char *buffer, int count, struct list_head *addrranges,
struct nidrange *nr)
{
int i = 0;
struct addrrange *ar;
struct netstrfns *nf = nr->nr_netstrfns;
list_for_each_entry(ar, addrranges, ar_link) {
if (i != 0)
i += scnprintf(buffer + i, count - i, " ");
i += nf->nf_print_addrlist(buffer + i, count - i,
&ar->ar_numaddr_ranges);
i += cfs_print_network(buffer + i, count - i, nr);
}
return i;
}
int cfs_print_nidlist(char *buffer, int count, struct list_head *nidlist)
{
int i = 0;
struct nidrange *nr;
if (count <= 0)
return 0;
list_for_each_entry(nr, nidlist, nr_link) {
if (i != 0)
i += scnprintf(buffer + i, count - i, " ");
if (nr->nr_all != 0) {
LASSERT(list_empty(&nr->nr_addrranges));
i += scnprintf(buffer + i, count - i, "*");
i += cfs_print_network(buffer + i, count - i, nr);
} else {
i += cfs_print_addrranges(buffer + i, count - i,
&nr->nr_addrranges, nr);
}
}
return i;
}
static void cfs_ip_ar_min_max(struct addrrange *ar, __u32 *min_nid,
__u32 *max_nid)
{
struct cfs_expr_list *el;
struct cfs_range_expr *re;
__u32 tmp_ip_addr = 0;
unsigned int min_ip[4] = {0};
unsigned int max_ip[4] = {0};
int re_count = 0;
list_for_each_entry(el, &ar->ar_numaddr_ranges, el_link) {
list_for_each_entry(re, &el->el_exprs, re_link) {
min_ip[re_count] = re->re_lo;
max_ip[re_count] = re->re_hi;
re_count++;
}
}
tmp_ip_addr = ((min_ip[0] << 24) | (min_ip[1] << 16) |
(min_ip[2] << 8) | min_ip[3]);
if (min_nid != NULL)
*min_nid = tmp_ip_addr;
tmp_ip_addr = ((max_ip[0] << 24) | (max_ip[1] << 16) |
(max_ip[2] << 8) | max_ip[3]);
if (max_nid != NULL)
*max_nid = tmp_ip_addr;
}
static void cfs_num_ar_min_max(struct addrrange *ar, __u32 *min_nid,
__u32 *max_nid)
{
struct cfs_expr_list *el;
struct cfs_range_expr *re;
unsigned int min_addr = 0;
unsigned int max_addr = 0;
list_for_each_entry(el, &ar->ar_numaddr_ranges, el_link) {
list_for_each_entry(re, &el->el_exprs, re_link) {
if (re->re_lo < min_addr || min_addr == 0)
min_addr = re->re_lo;
if (re->re_hi > max_addr)
max_addr = re->re_hi;
}
}
if (min_nid != NULL)
*min_nid = min_addr;
if (max_nid != NULL)
*max_nid = max_addr;
}
bool cfs_nidrange_is_contiguous(struct list_head *nidlist)
{
struct nidrange *nr;
struct netstrfns *nf = NULL;
char *lndname = NULL;
int netnum = -1;
list_for_each_entry(nr, nidlist, nr_link) {
nf = nr->nr_netstrfns;
if (lndname == NULL)
lndname = nf->nf_name;
if (netnum == -1)
netnum = nr->nr_netnum;
if (strcmp(lndname, nf->nf_name) != 0 ||
netnum != nr->nr_netnum)
return false;
}
if (nf == NULL)
return false;
if (!nf->nf_is_contiguous(nidlist))
return false;
return true;
}
static bool cfs_num_is_contiguous(struct list_head *nidlist)
{
struct nidrange *nr;
struct addrrange *ar;
struct cfs_expr_list *el;
struct cfs_range_expr *re;
int last_hi = 0;
__u32 last_end_nid = 0;
__u32 current_start_nid = 0;
__u32 current_end_nid = 0;
list_for_each_entry(nr, nidlist, nr_link) {
list_for_each_entry(ar, &nr->nr_addrranges, ar_link) {
cfs_num_ar_min_max(ar, &current_start_nid,
&current_end_nid);
if (last_end_nid != 0 &&
(current_start_nid - last_end_nid != 1))
return false;
last_end_nid = current_end_nid;
list_for_each_entry(el, &ar->ar_numaddr_ranges,
el_link) {
list_for_each_entry(re, &el->el_exprs,
re_link) {
if (re->re_stride > 1)
return false;
else if (last_hi != 0 &&
re->re_hi - last_hi != 1)
return false;
last_hi = re->re_hi;
}
}
}
}
return true;
}
static bool cfs_ip_is_contiguous(struct list_head *nidlist)
{
struct nidrange *nr;
struct addrrange *ar;
struct cfs_expr_list *el;
struct cfs_range_expr *re;
int expr_count;
int last_hi = 255;
int last_diff = 0;
__u32 last_end_nid = 0;
__u32 current_start_nid = 0;
__u32 current_end_nid = 0;
list_for_each_entry(nr, nidlist, nr_link) {
list_for_each_entry(ar, &nr->nr_addrranges, ar_link) {
last_hi = 255;
last_diff = 0;
cfs_ip_ar_min_max(ar, &current_start_nid,
&current_end_nid);
if (last_end_nid != 0 &&
(current_start_nid - last_end_nid != 1))
return false;
last_end_nid = current_end_nid;
list_for_each_entry(el, &ar->ar_numaddr_ranges,
el_link) {
expr_count = 0;
list_for_each_entry(re, &el->el_exprs,
re_link) {
expr_count++;
if (re->re_stride > 1 ||
(last_diff > 0 && last_hi != 255) ||
(last_diff > 0 && last_hi == 255 &&
re->re_lo > 0))
return false;
last_hi = re->re_hi;
last_diff = re->re_hi - re->re_lo;
}
}
}
}
return true;
}
void cfs_nidrange_find_min_max(struct list_head *nidlist, char *min_nid,
char *max_nid, size_t nidstr_length)
{
struct nidrange *nr;
struct netstrfns *nf = NULL;
int netnum = -1;
__u32 min_addr;
__u32 max_addr;
char *lndname = NULL;
char min_addr_str[IPSTRING_LENGTH];
char max_addr_str[IPSTRING_LENGTH];
list_for_each_entry(nr, nidlist, nr_link) {
nf = nr->nr_netstrfns;
lndname = nf->nf_name;
if (netnum == -1)
netnum = nr->nr_netnum;
nf->nf_min_max(nidlist, &min_addr, &max_addr);
}
nf->nf_addr2str(min_addr, min_addr_str, sizeof(min_addr_str));
nf->nf_addr2str(max_addr, max_addr_str, sizeof(max_addr_str));
snprintf(min_nid, nidstr_length, "%s@%s%d", min_addr_str, lndname,
netnum);
snprintf(max_nid, nidstr_length, "%s@%s%d", max_addr_str, lndname,
netnum);
}
static void cfs_num_min_max(struct list_head *nidlist, __u32 *min_nid,
__u32 *max_nid)
{
struct nidrange *nr;
struct addrrange *ar;
unsigned int tmp_min_addr = 0;
unsigned int tmp_max_addr = 0;
unsigned int min_addr = 0;
unsigned int max_addr = 0;
list_for_each_entry(nr, nidlist, nr_link) {
list_for_each_entry(ar, &nr->nr_addrranges, ar_link) {
cfs_num_ar_min_max(ar, &tmp_min_addr,
&tmp_max_addr);
if (tmp_min_addr < min_addr || min_addr == 0)
min_addr = tmp_min_addr;
if (tmp_max_addr > max_addr)
max_addr = tmp_min_addr;
}
}
*max_nid = max_addr;
*min_nid = min_addr;
}
static void cfs_ip_min_max(struct list_head *nidlist, __u32 *min_nid,
__u32 *max_nid)
{
struct nidrange *nr;
struct addrrange *ar;
__u32 tmp_min_ip_addr = 0;
__u32 tmp_max_ip_addr = 0;
__u32 min_ip_addr = 0;
__u32 max_ip_addr = 0;
list_for_each_entry(nr, nidlist, nr_link) {
list_for_each_entry(ar, &nr->nr_addrranges, ar_link) {
cfs_ip_ar_min_max(ar, &tmp_min_ip_addr,
&tmp_max_ip_addr);
if (tmp_min_ip_addr < min_ip_addr || min_ip_addr == 0)
min_ip_addr = tmp_min_ip_addr;
if (tmp_max_ip_addr > max_ip_addr)
max_ip_addr = tmp_max_ip_addr;
}
}
if (min_nid != NULL)
*min_nid = min_ip_addr;
if (max_nid != NULL)
*max_nid = max_ip_addr;
}
static int
libcfs_lo_str2addr(const char *str, int nob, __u32 *addr)
{
*addr = 0;
return 1;
}
static void
libcfs_ip_addr2str(__u32 addr, char *str, size_t size)
{
snprintf(str, size, "%u.%u.%u.%u",
(addr >> 24) & 0xff, (addr >> 16) & 0xff,
(addr >> 8) & 0xff, addr & 0xff);
}
static int
libcfs_ip_str2addr(const char *str, int nob, __u32 *addr)
{
unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
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
int
cfs_ip_addr_parse(char *str, int len, struct list_head *list)
{
struct cfs_expr_list *el;
struct cfs_lstr src;
int rc;
int i;
src.ls_str = str;
src.ls_len = len;
i = 0;
while (src.ls_str != NULL) {
struct cfs_lstr res;
if (!cfs_gettok(&src, '.', &res)) {
rc = -EINVAL;
goto out;
}
rc = cfs_expr_list_parse(res.ls_str, res.ls_len, 0, 255, &el);
if (rc != 0)
goto out;
list_add_tail(&el->el_link, list);
i++;
}
if (i == 4)
return 0;
rc = -EINVAL;
out:
cfs_expr_list_free_list(list);
return rc;
}
static int
libcfs_ip_addr_range_print(char *buffer, int count, struct list_head *list)
{
int i = 0, j = 0;
struct cfs_expr_list *el;
list_for_each_entry(el, list, el_link) {
LASSERT(j++ < 4);
if (i != 0)
i += scnprintf(buffer + i, count - i, ".");
i += cfs_expr_list_print(buffer + i, count - i, el);
}
return i;
}
int
cfs_ip_addr_match(__u32 addr, struct list_head *list)
{
struct cfs_expr_list *el;
int i = 0;
list_for_each_entry_reverse(el, list, el_link) {
if (!cfs_expr_list_match(addr & 0xff, el))
return 0;
addr >>= 8;
i++;
}
return i == 4;
}
static void
libcfs_decnum_addr2str(__u32 addr, char *str, size_t size)
{
snprintf(str, size, "%u", addr);
}
static int
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
libcfs_num_addr_range_print(char *buffer, int count, struct list_head *list)
{
int i = 0, j = 0;
struct cfs_expr_list *el;
list_for_each_entry(el, list, el_link) {
LASSERT(j++ < 1);
i += cfs_expr_list_print(buffer + i, count - i, el);
}
return i;
}
static int
libcfs_num_match(__u32 addr, struct list_head *numaddr)
{
struct cfs_expr_list *el;
LASSERT(!list_empty(numaddr));
el = list_entry(numaddr->next, struct cfs_expr_list, el_link);
return cfs_expr_list_match(addr, el);
}
static struct netstrfns *
libcfs_lnd2netstrfns(__u32 lnd)
{
int i;
for (i = 0; i < libcfs_nnetstrfns; i++)
if (lnd == libcfs_netstrfns[i].nf_type)
return &libcfs_netstrfns[i];
return NULL;
}
static struct netstrfns *
libcfs_namenum2netstrfns(const char *name)
{
struct netstrfns *nf;
int i;
for (i = 0; i < libcfs_nnetstrfns; i++) {
nf = &libcfs_netstrfns[i];
if (!strncmp(name, nf->nf_name, strlen(nf->nf_name)))
return nf;
}
return NULL;
}
static struct netstrfns *
libcfs_name2netstrfns(const char *name)
{
int i;
for (i = 0; i < libcfs_nnetstrfns; i++)
if (!strcmp(libcfs_netstrfns[i].nf_name, name))
return &libcfs_netstrfns[i];
return NULL;
}
int
libcfs_isknown_lnd(__u32 lnd)
{
return libcfs_lnd2netstrfns(lnd) != NULL;
}
char *
libcfs_lnd2modname(__u32 lnd)
{
struct netstrfns *nf = libcfs_lnd2netstrfns(lnd);
return (nf == NULL) ? NULL : nf->nf_modname;
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
libcfs_lnd2str_r(__u32 lnd, char *buf, size_t buf_size)
{
struct netstrfns *nf;
nf = libcfs_lnd2netstrfns(lnd);
if (nf == NULL)
snprintf(buf, buf_size, "?%u?", lnd);
else
snprintf(buf, buf_size, "%s", nf->nf_name);
return buf;
}
char *
libcfs_net2str_r(__u32 net, char *buf, size_t buf_size)
{
__u32 nnum = LNET_NETNUM(net);
__u32 lnd = LNET_NETTYP(net);
struct netstrfns *nf;
nf = libcfs_lnd2netstrfns(lnd);
if (nf == NULL)
snprintf(buf, buf_size, "<%u:%u>", lnd, nnum);
else if (nnum == 0)
snprintf(buf, buf_size, "%s", nf->nf_name);
else
snprintf(buf, buf_size, "%s%u", nf->nf_name, nnum);
return buf;
}
char *
libcfs_nid2str_r(lnet_nid_t nid, char *buf, size_t buf_size)
{
__u32 addr = LNET_NIDADDR(nid);
__u32 net = LNET_NIDNET(nid);
__u32 nnum = LNET_NETNUM(net);
__u32 lnd = LNET_NETTYP(net);
struct netstrfns *nf;
if (nid == LNET_NID_ANY) {
strncpy(buf, "<?>", buf_size);
buf[buf_size - 1] = '\0';
return buf;
}
nf = libcfs_lnd2netstrfns(lnd);
if (nf == NULL)
snprintf(buf, buf_size, "%x@<%u:%u>", addr, lnd, nnum);
else {
size_t addr_len;
nf->nf_addr2str(addr, buf, buf_size);
addr_len = strlen(buf);
if (nnum == 0)
snprintf(buf + addr_len, buf_size - addr_len, "@%s",
nf->nf_name);
else
snprintf(buf + addr_len, buf_size - addr_len, "@%s%u",
nf->nf_name, nnum);
}
return buf;
}
static struct netstrfns *
libcfs_str2net_internal(const char *str, __u32 *net)
{
struct netstrfns *uninitialized_var(nf);
int nob;
unsigned int netnum;
int i;
for (i = 0; i < libcfs_nnetstrfns; i++) {
nf = &libcfs_netstrfns[i];
if (!strncmp(str, nf->nf_name, strlen(nf->nf_name)))
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
