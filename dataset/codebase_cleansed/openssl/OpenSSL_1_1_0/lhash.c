OPENSSL_LHASH *OPENSSL_LH_new(OPENSSL_LH_HASHFUNC h, OPENSSL_LH_COMPFUNC c)
{
OPENSSL_LHASH *ret;
if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
goto err0;
if ((ret->b = OPENSSL_zalloc(sizeof(*ret->b) * MIN_NODES)) == NULL)
goto err1;
ret->comp = ((c == NULL) ? (OPENSSL_LH_COMPFUNC)strcmp : c);
ret->hash = ((h == NULL) ? (OPENSSL_LH_HASHFUNC)OPENSSL_LH_strhash : h);
ret->num_nodes = MIN_NODES / 2;
ret->num_alloc_nodes = MIN_NODES;
ret->pmax = MIN_NODES / 2;
ret->up_load = UP_LOAD;
ret->down_load = DOWN_LOAD;
return (ret);
err1:
OPENSSL_free(ret);
err0:
return (NULL);
}
void OPENSSL_LH_free(OPENSSL_LHASH *lh)
{
unsigned int i;
OPENSSL_LH_NODE *n, *nn;
if (lh == NULL)
return;
for (i = 0; i < lh->num_nodes; i++) {
n = lh->b[i];
while (n != NULL) {
nn = n->next;
OPENSSL_free(n);
n = nn;
}
}
OPENSSL_free(lh->b);
OPENSSL_free(lh);
}
void *OPENSSL_LH_insert(OPENSSL_LHASH *lh, void *data)
{
unsigned long hash;
OPENSSL_LH_NODE *nn, **rn;
void *ret;
lh->error = 0;
if ((lh->up_load <= (lh->num_items * LH_LOAD_MULT / lh->num_nodes)) && !expand(lh))
return NULL;
rn = getrn(lh, data, &hash);
if (*rn == NULL) {
if ((nn = OPENSSL_malloc(sizeof(*nn))) == NULL) {
lh->error++;
return (NULL);
}
nn->data = data;
nn->next = NULL;
nn->hash = hash;
*rn = nn;
ret = NULL;
lh->num_insert++;
lh->num_items++;
} else {
ret = (*rn)->data;
(*rn)->data = data;
lh->num_replace++;
}
return (ret);
}
void *OPENSSL_LH_delete(OPENSSL_LHASH *lh, const void *data)
{
unsigned long hash;
OPENSSL_LH_NODE *nn, **rn;
void *ret;
lh->error = 0;
rn = getrn(lh, data, &hash);
if (*rn == NULL) {
lh->num_no_delete++;
return (NULL);
} else {
nn = *rn;
*rn = nn->next;
ret = nn->data;
OPENSSL_free(nn);
lh->num_delete++;
}
lh->num_items--;
if ((lh->num_nodes > MIN_NODES) &&
(lh->down_load >= (lh->num_items * LH_LOAD_MULT / lh->num_nodes)))
contract(lh);
return (ret);
}
void *OPENSSL_LH_retrieve(OPENSSL_LHASH *lh, const void *data)
{
unsigned long hash;
OPENSSL_LH_NODE **rn;
void *ret;
lh->error = 0;
rn = getrn(lh, data, &hash);
if (*rn == NULL) {
lh->num_retrieve_miss++;
return (NULL);
} else {
ret = (*rn)->data;
lh->num_retrieve++;
}
return (ret);
}
static void doall_util_fn(OPENSSL_LHASH *lh, int use_arg,
OPENSSL_LH_DOALL_FUNC func,
OPENSSL_LH_DOALL_FUNCARG func_arg, void *arg)
{
int i;
OPENSSL_LH_NODE *a, *n;
if (lh == NULL)
return;
for (i = lh->num_nodes - 1; i >= 0; i--) {
a = lh->b[i];
while (a != NULL) {
n = a->next;
if (use_arg)
func_arg(a->data, arg);
else
func(a->data);
a = n;
}
}
}
void OPENSSL_LH_doall(OPENSSL_LHASH *lh, OPENSSL_LH_DOALL_FUNC func)
{
doall_util_fn(lh, 0, func, (OPENSSL_LH_DOALL_FUNCARG)0, NULL);
}
void OPENSSL_LH_doall_arg(OPENSSL_LHASH *lh, OPENSSL_LH_DOALL_FUNCARG func, void *arg)
{
doall_util_fn(lh, 1, (OPENSSL_LH_DOALL_FUNC)0, func, arg);
}
static int expand(OPENSSL_LHASH *lh)
{
OPENSSL_LH_NODE **n, **n1, **n2, *np;
unsigned int p, i, j;
unsigned long hash, nni;
lh->num_nodes++;
lh->num_expands++;
p = (int)lh->p++;
n1 = &(lh->b[p]);
n2 = &(lh->b[p + (int)lh->pmax]);
*n2 = NULL;
nni = lh->num_alloc_nodes;
for (np = *n1; np != NULL;) {
hash = np->hash;
if ((hash % nni) != p) {
*n1 = (*n1)->next;
np->next = *n2;
*n2 = np;
} else
n1 = &((*n1)->next);
np = *n1;
}
if ((lh->p) >= lh->pmax) {
j = (int)lh->num_alloc_nodes * 2;
n = OPENSSL_realloc(lh->b, (int)(sizeof(OPENSSL_LH_NODE *) * j));
if (n == NULL) {
lh->error++;
lh->p = 0;
return 0;
}
for (i = (int)lh->num_alloc_nodes; i < j; i++)
n[i] = NULL;
lh->pmax = lh->num_alloc_nodes;
lh->num_alloc_nodes = j;
lh->num_expand_reallocs++;
lh->p = 0;
lh->b = n;
}
return 1;
}
static void contract(OPENSSL_LHASH *lh)
{
OPENSSL_LH_NODE **n, *n1, *np;
np = lh->b[lh->p + lh->pmax - 1];
lh->b[lh->p + lh->pmax - 1] = NULL;
if (lh->p == 0) {
n = OPENSSL_realloc(lh->b,
(unsigned int)(sizeof(OPENSSL_LH_NODE *) * lh->pmax));
if (n == NULL) {
lh->error++;
return;
}
lh->num_contract_reallocs++;
lh->num_alloc_nodes /= 2;
lh->pmax /= 2;
lh->p = lh->pmax - 1;
lh->b = n;
} else
lh->p--;
lh->num_nodes--;
lh->num_contracts++;
n1 = lh->b[(int)lh->p];
if (n1 == NULL)
lh->b[(int)lh->p] = np;
else {
while (n1->next != NULL)
n1 = n1->next;
n1->next = np;
}
}
static OPENSSL_LH_NODE **getrn(OPENSSL_LHASH *lh,
const void *data, unsigned long *rhash)
{
OPENSSL_LH_NODE **ret, *n1;
unsigned long hash, nn;
OPENSSL_LH_COMPFUNC cf;
hash = (*(lh->hash)) (data);
lh->num_hash_calls++;
*rhash = hash;
nn = hash % lh->pmax;
if (nn < lh->p)
nn = hash % lh->num_alloc_nodes;
cf = lh->comp;
ret = &(lh->b[(int)nn]);
for (n1 = *ret; n1 != NULL; n1 = n1->next) {
lh->num_hash_comps++;
if (n1->hash != hash) {
ret = &(n1->next);
continue;
}
lh->num_comp_calls++;
if (cf(n1->data, data) == 0)
break;
ret = &(n1->next);
}
return (ret);
}
unsigned long OPENSSL_LH_strhash(const char *c)
{
unsigned long ret = 0;
long n;
unsigned long v;
int r;
if ((c == NULL) || (*c == '\0'))
return (ret);
n = 0x100;
while (*c) {
v = n | (*c);
n += 0x100;
r = (int)((v >> 2) ^ v) & 0x0f;
ret = (ret << r) | (ret >> (32 - r));
ret &= 0xFFFFFFFFL;
ret ^= v * v;
c++;
}
return ((ret >> 16) ^ ret);
}
unsigned long OPENSSL_LH_num_items(const OPENSSL_LHASH *lh)
{
return lh ? lh->num_items : 0;
}
unsigned long OPENSSL_LH_get_down_load(const OPENSSL_LHASH *lh)
{
return lh->down_load;
}
void OPENSSL_LH_set_down_load(OPENSSL_LHASH *lh, unsigned long down_load)
{
lh->down_load = down_load;
}
int OPENSSL_LH_error(OPENSSL_LHASH *lh)
{
return lh->error;
}
