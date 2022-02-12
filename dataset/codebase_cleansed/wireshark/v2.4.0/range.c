range_t *range_empty(wmem_allocator_t *scope)
{
range_t *range;
range = (range_t *)wmem_alloc(scope, RANGE_HDR_SIZE);
range->nranges = 0;
return range;
}
convert_ret_t
range_convert_str(wmem_allocator_t *scope, range_t **rangep, const gchar *es, guint32 max_value)
{
return range_convert_str_work(scope, rangep, es, max_value, TRUE);
}
convert_ret_t
range_convert_str_work(wmem_allocator_t *scope, range_t **rangep, const gchar *es, guint32 max_value,
gboolean err_on_max)
{
range_t *range;
guint nranges;
const gchar *p;
char *endp;
gchar c;
guint i;
guint32 tmp;
unsigned long val;
if ( (rangep == NULL) || (es == NULL) )
return CVT_SYNTAX_ERROR;
range = (range_t *)wmem_alloc(scope, RANGE_HDR_SIZE + sizeof (range_admin_t));
range->nranges = 0;
nranges = 1;
p = es;
for (;;) {
while ((c = *p) == ' ' || c == '\t')
p++;
if (c == '\0')
break;
if (range->nranges >= nranges) {
if (nranges == 1)
nranges = 4;
else
nranges += 4;
range = (range_t *)wmem_realloc(scope, range, RANGE_HDR_SIZE +
nranges*sizeof (range_admin_t));
}
if (c == '-') {
range->ranges[range->nranges].low = 1;
} else if (g_ascii_isdigit(c)) {
errno = 0;
val = strtoul(p, &endp, 0);
if (p == endp) {
wmem_free(scope, range);
return CVT_SYNTAX_ERROR;
}
if (errno == ERANGE || val > max_value) {
if (err_on_max) {
wmem_free(scope, range);
return CVT_NUMBER_TOO_BIG;
} else {
val = max_value;
}
}
p = endp;
range->ranges[range->nranges].low = (guint32)val;
while ((c = *p) == ' ' || c == '\t')
p++;
} else {
wmem_free(scope, range);
return CVT_SYNTAX_ERROR;
}
if (c == '-') {
p++;
while ((c = *p) == ' ' || c == '\t')
p++;
if (c == ',' || c == '\0') {
range->ranges[range->nranges].high = max_value;
} else if (g_ascii_isdigit(c)) {
errno = 0;
val = strtoul(p, &endp, 0);
if (p == endp) {
wmem_free(scope, range);
return CVT_SYNTAX_ERROR;
}
if (errno == ERANGE || val > max_value) {
if (err_on_max) {
wmem_free(scope, range);
return CVT_NUMBER_TOO_BIG;
} else {
val = max_value;
}
}
p = endp;
range->ranges[range->nranges].high = (guint32)val;
while ((c = *p) == ' ' || c == '\t')
p++;
} else {
wmem_free(scope, range);
return CVT_SYNTAX_ERROR;
}
} else if (c == ',' || c == '\0') {
range->ranges[range->nranges].high = range->ranges[range->nranges].low;
} else {
wmem_free(scope, range);
return CVT_SYNTAX_ERROR;
}
range->nranges++;
if (c == ',') {
p++;
}
}
for (i=0; i < range->nranges; i++) {
if (range->ranges[i].low > range->ranges[i].high) {
tmp = range->ranges[i].low;
range->ranges[i].low = range->ranges[i].high;
range->ranges[i].high = tmp;
}
}
*rangep = range;
return CVT_NO_ERROR;
}
gboolean
value_is_in_range(range_t *range, guint32 val)
{
guint i;
if (range) {
for (i=0; i < range->nranges; i++) {
if (val >= range->ranges[i].low && val <= range->ranges[i].high)
return TRUE;
}
}
return(FALSE);
}
gboolean
range_add_value(wmem_allocator_t *scope, range_t **range, guint32 val)
{
guint i;
if ((range) && (*range)) {
for (i=0; i < (*range)->nranges; i++) {
if (val >= (*range)->ranges[i].low && val <= (*range)->ranges[i].high)
return TRUE;
if (val == (*range)->ranges[i].low-1)
{
(*range)->ranges[i].low = val;
return TRUE;
}
if (val == (*range)->ranges[i].high+1)
{
(*range)->ranges[i].high = val;
return TRUE;
}
}
(*range) = (range_t *)wmem_realloc(scope, (*range), RANGE_HDR_SIZE +
((*range)->nranges+1)*sizeof (range_admin_t));
(*range)->nranges++;
(*range)->ranges[i].low = (*range)->ranges[i].high = val;
return TRUE;
}
return(FALSE);
}
gboolean
range_remove_value(wmem_allocator_t *scope, range_t **range, guint32 val)
{
guint i, j, new_j;
range_t *new_range;
if ((range) && (*range)) {
for (i=0; i < (*range)->nranges; i++) {
if (val > (*range)->ranges[i].low && val < (*range)->ranges[i].high)
return TRUE;
if ((val == (*range)->ranges[i].low) && (val == (*range)->ranges[i].high))
{
new_range = (range_t*)wmem_alloc(scope, RANGE_HDR_SIZE + ((*range)->nranges-1)*sizeof (range_admin_t));
new_range->nranges = (*range)->nranges-1;
for (j=0, new_j = 0; j < (*range)->nranges; j++) {
if (j == i)
continue;
new_range->ranges[new_j].low = (*range)->ranges[j].low;
new_range->ranges[new_j].high = (*range)->ranges[j].high;
new_j++;
}
wmem_free(scope, *range);
*range = new_range;
return TRUE;
}
if (val == (*range)->ranges[i].low)
{
(*range)->ranges[i].low++;
return TRUE;
}
if (val == (*range)->ranges[i].high)
{
(*range)->ranges[i].high--;
return TRUE;
}
}
return TRUE;
}
return(FALSE);
}
gboolean
ranges_are_equal(range_t *a, range_t *b)
{
guint i;
if ( (a == NULL) || (b == NULL) )
return FALSE;
if (a->nranges != b->nranges)
return FALSE;
for (i=0; i < a->nranges; i++) {
if (a->ranges[i].low != b->ranges[i].low)
return FALSE;
if (a->ranges[i].high != b->ranges[i].high)
return FALSE;
}
return TRUE;
}
void
range_foreach(range_t *range, void (*callback)(guint32 val))
{
guint32 i, j;
if (range && callback) {
for (i=0; i < range->nranges; i++) {
for (j = range->ranges[i].low; j <= range->ranges[i].high; j++)
callback(j);
}
}
}
char *
range_convert_range(wmem_allocator_t *scope, const range_t *range)
{
guint32 i;
gboolean prepend_comma = FALSE;
wmem_strbuf_t *strbuf;
strbuf=wmem_strbuf_new(scope, "");
if (range) {
for (i=0; i < range->nranges; i++) {
if (range->ranges[i].low == range->ranges[i].high) {
wmem_strbuf_append_printf(strbuf, "%s%u", prepend_comma?",":"", range->ranges[i].low);
} else {
wmem_strbuf_append_printf(strbuf, "%s%u-%u", prepend_comma?",":"", range->ranges[i].low, range->ranges[i].high);
}
prepend_comma = TRUE;
}
}
return wmem_strbuf_finalize(strbuf);
}
range_t *
range_copy(wmem_allocator_t *scope, range_t *src)
{
range_t *dst;
size_t range_size;
if (src == NULL)
return NULL;
range_size = RANGE_HDR_SIZE + src->nranges*sizeof (range_admin_t);
dst = (range_t *)wmem_memdup(scope, src, range_size);
return dst;
}
