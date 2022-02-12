int cfs_strncasecmp(const char *s1, const char *s2, size_t n)
{
if (s1 == NULL || s2 == NULL)
return 1;
if (n == 0)
return 0;
while (n-- != 0 && tolower(*s1) == tolower(*s2)) {
if (n == 0 || *s1 == '\0' || *s2 == '\0')
break;
s1++;
s2++;
}
return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}
int cfs_str2mask(const char *str, const char *(*bit2str)(int bit),
int *oldmask, int minmask, int allmask)
{
const char *debugstr;
char op = 0;
int newmask = minmask, i, len, found = 0;
while (*str != 0) {
while (isspace(*str))
str++;
if (*str == 0)
break;
if (*str == '+' || *str == '-') {
op = *str++;
if (!found)
newmask = *oldmask;
while (isspace(*str))
str++;
if (*str == 0)
return -EINVAL;
}
for (len = 0; str[len] != 0 && !isspace(str[len]) &&
str[len] != '+' && str[len] != '-'; len++);
found = 0;
for (i = 0; i < 32; i++) {
debugstr = bit2str(i);
if (debugstr != NULL &&
strlen(debugstr) == len &&
cfs_strncasecmp(str, debugstr, len) == 0) {
if (op == '-')
newmask &= ~(1 << i);
else
newmask |= (1 << i);
found = 1;
break;
}
}
if (!found && len == 3 &&
(cfs_strncasecmp(str, "ALL", len) == 0)) {
if (op == '-')
newmask = minmask;
else
newmask = allmask;
found = 1;
}
if (!found) {
CWARN("unknown mask '%.*s'.\n"
"mask usage: [+|-]<all|type> ...\n", len, str);
return -EINVAL;
}
str += len;
}
*oldmask = newmask;
return 0;
}
char *cfs_firststr(char *str, size_t size)
{
size_t i = 0;
char *end;
while (i < size && *str && isspace(*str)) {
++i;
++str;
}
if (*str == '\0')
goto out;
end = str;
while (i < size && *end != '\0' && !isspace(*end)) {
++i;
++end;
}
*end= '\0';
out:
return str;
}
char *
cfs_trimwhite(char *str)
{
char *end;
while (cfs_iswhite(*str))
str++;
end = str + strlen(str);
while (end > str) {
if (!cfs_iswhite(end[-1]))
break;
end--;
}
*end = 0;
return str;
}
int
cfs_gettok(struct cfs_lstr *next, char delim, struct cfs_lstr *res)
{
char *end;
if (next->ls_str == NULL)
return 0;
while (next->ls_len) {
if (!cfs_iswhite(*next->ls_str))
break;
next->ls_str++;
next->ls_len--;
}
if (next->ls_len == 0)
return 0;
if (*next->ls_str == delim) {
return 0;
}
res->ls_str = next->ls_str;
end = memchr(next->ls_str, delim, next->ls_len);
if (end == NULL) {
end = next->ls_str + next->ls_len;
next->ls_str = NULL;
} else {
next->ls_str = end + 1;
next->ls_len -= (end - res->ls_str + 1);
}
while (--end != res->ls_str) {
if (!cfs_iswhite(*end))
break;
}
res->ls_len = end - res->ls_str + 1;
return 1;
}
int
cfs_str2num_check(char *str, int nob, unsigned *num,
unsigned min, unsigned max)
{
char *endp;
str = cfs_trimwhite(str);
*num = strtoul(str, &endp, 0);
if (endp == str)
return 0;
for (; endp < str + nob; endp++) {
if (!cfs_iswhite(*endp))
return 0;
}
return (*num >= min && *num <= max);
}
int
cfs_range_expr_parse(struct cfs_lstr *src, unsigned min, unsigned max,
int bracketed, struct cfs_range_expr **expr)
{
struct cfs_range_expr *re;
struct cfs_lstr tok;
LIBCFS_ALLOC(re, sizeof(*re));
if (re == NULL)
return -ENOMEM;
if (src->ls_len == 1 && src->ls_str[0] == '*') {
re->re_lo = min;
re->re_hi = max;
re->re_stride = 1;
goto out;
}
if (cfs_str2num_check(src->ls_str, src->ls_len,
&re->re_lo, min, max)) {
re->re_hi = re->re_lo;
re->re_stride = 1;
goto out;
}
if (!bracketed || !cfs_gettok(src, '-', &tok))
goto failed;
if (!cfs_str2num_check(tok.ls_str, tok.ls_len,
&re->re_lo, min, max))
goto failed;
if (cfs_str2num_check(src->ls_str, src->ls_len,
&re->re_hi, min, max)) {
re->re_stride = 1;
goto out;
}
if (cfs_gettok(src, '/', &tok)) {
if (!cfs_str2num_check(tok.ls_str, tok.ls_len,
&re->re_hi, min, max))
goto failed;
if (cfs_str2num_check(src->ls_str, src->ls_len,
&re->re_stride, min, max)) {
goto out;
}
}
out:
*expr = re;
return 0;
failed:
LIBCFS_FREE(re, sizeof(*re));
return -EINVAL;
}
int
cfs_expr_list_match(__u32 value, struct cfs_expr_list *expr_list)
{
struct cfs_range_expr *expr;
list_for_each_entry(expr, &expr_list->el_exprs, re_link) {
if (value >= expr->re_lo && value <= expr->re_hi &&
((value - expr->re_lo) % expr->re_stride) == 0)
return 1;
}
return 0;
}
int
cfs_expr_list_values(struct cfs_expr_list *expr_list, int max, __u32 **valpp)
{
struct cfs_range_expr *expr;
__u32 *val;
int count = 0;
int i;
list_for_each_entry(expr, &expr_list->el_exprs, re_link) {
for (i = expr->re_lo; i <= expr->re_hi; i++) {
if (((i - expr->re_lo) % expr->re_stride) == 0)
count++;
}
}
if (count == 0)
return 0;
if (count > max) {
CERROR("Number of values %d exceeds max allowed %d\n",
max, count);
return -EINVAL;
}
LIBCFS_ALLOC(val, sizeof(val[0]) * count);
if (val == NULL)
return -ENOMEM;
count = 0;
list_for_each_entry(expr, &expr_list->el_exprs, re_link) {
for (i = expr->re_lo; i <= expr->re_hi; i++) {
if (((i - expr->re_lo) % expr->re_stride) == 0)
val[count++] = i;
}
}
*valpp = val;
return count;
}
void
cfs_expr_list_free(struct cfs_expr_list *expr_list)
{
while (!list_empty(&expr_list->el_exprs)) {
struct cfs_range_expr *expr;
expr = list_entry(expr_list->el_exprs.next,
struct cfs_range_expr, re_link),
list_del(&expr->re_link);
LIBCFS_FREE(expr, sizeof(*expr));
}
LIBCFS_FREE(expr_list, sizeof(*expr_list));
}
void
cfs_expr_list_print(struct cfs_expr_list *expr_list)
{
struct cfs_range_expr *expr;
list_for_each_entry(expr, &expr_list->el_exprs, re_link) {
CDEBUG(D_WARNING, "%d-%d/%d\n",
expr->re_lo, expr->re_hi, expr->re_stride);
}
}
int
cfs_expr_list_parse(char *str, int len, unsigned min, unsigned max,
struct cfs_expr_list **elpp)
{
struct cfs_expr_list *expr_list;
struct cfs_range_expr *expr;
struct cfs_lstr src;
int rc;
LIBCFS_ALLOC(expr_list, sizeof(*expr_list));
if (expr_list == NULL)
return -ENOMEM;
src.ls_str = str;
src.ls_len = len;
INIT_LIST_HEAD(&expr_list->el_exprs);
if (src.ls_str[0] == '[' &&
src.ls_str[src.ls_len - 1] == ']') {
src.ls_str++;
src.ls_len -= 2;
rc = -EINVAL;
while (src.ls_str != NULL) {
struct cfs_lstr tok;
if (!cfs_gettok(&src, ',', &tok)) {
rc = -EINVAL;
break;
}
rc = cfs_range_expr_parse(&tok, min, max, 1, &expr);
if (rc != 0)
break;
list_add_tail(&expr->re_link,
&expr_list->el_exprs);
}
} else {
rc = cfs_range_expr_parse(&src, min, max, 0, &expr);
if (rc == 0) {
list_add_tail(&expr->re_link,
&expr_list->el_exprs);
}
}
if (rc != 0)
cfs_expr_list_free(expr_list);
else
*elpp = expr_list;
return rc;
}
void
cfs_expr_list_free_list(struct list_head *list)
{
struct cfs_expr_list *el;
while (!list_empty(list)) {
el = list_entry(list->next,
struct cfs_expr_list, el_link);
list_del(&el->el_link);
cfs_expr_list_free(el);
}
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
void
cfs_ip_addr_free(struct list_head *list)
{
cfs_expr_list_free_list(list);
}
