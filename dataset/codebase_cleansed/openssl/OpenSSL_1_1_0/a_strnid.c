void ASN1_STRING_set_default_mask(unsigned long mask)
{
global_mask = mask;
}
unsigned long ASN1_STRING_get_default_mask(void)
{
return global_mask;
}
int ASN1_STRING_set_default_mask_asc(const char *p)
{
unsigned long mask;
char *end;
if (strncmp(p, "MASK:", 5) == 0) {
if (!p[5])
return 0;
mask = strtoul(p + 5, &end, 0);
if (*end)
return 0;
} else if (strcmp(p, "nombstr") == 0)
mask = ~((unsigned long)(B_ASN1_BMPSTRING | B_ASN1_UTF8STRING));
else if (strcmp(p, "pkix") == 0)
mask = ~((unsigned long)B_ASN1_T61STRING);
else if (strcmp(p, "utf8only") == 0)
mask = B_ASN1_UTF8STRING;
else if (strcmp(p, "default") == 0)
mask = 0xFFFFFFFFL;
else
return 0;
ASN1_STRING_set_default_mask(mask);
return 1;
}
ASN1_STRING *ASN1_STRING_set_by_NID(ASN1_STRING **out,
const unsigned char *in, int inlen,
int inform, int nid)
{
ASN1_STRING_TABLE *tbl;
ASN1_STRING *str = NULL;
unsigned long mask;
int ret;
if (!out)
out = &str;
tbl = ASN1_STRING_TABLE_get(nid);
if (tbl) {
mask = tbl->mask;
if (!(tbl->flags & STABLE_NO_MASK))
mask &= global_mask;
ret = ASN1_mbstring_ncopy(out, in, inlen, inform, mask,
tbl->minsize, tbl->maxsize);
} else
ret =
ASN1_mbstring_copy(out, in, inlen, inform,
DIRSTRING_TYPE & global_mask);
if (ret <= 0)
return NULL;
return *out;
}
static int sk_table_cmp(const ASN1_STRING_TABLE *const *a,
const ASN1_STRING_TABLE *const *b)
{
return (*a)->nid - (*b)->nid;
}
static int table_cmp(const ASN1_STRING_TABLE *a, const ASN1_STRING_TABLE *b)
{
return a->nid - b->nid;
}
ASN1_STRING_TABLE *ASN1_STRING_TABLE_get(int nid)
{
int idx;
ASN1_STRING_TABLE fnd;
fnd.nid = nid;
if (stable) {
idx = sk_ASN1_STRING_TABLE_find(stable, &fnd);
if (idx >= 0)
return sk_ASN1_STRING_TABLE_value(stable, idx);
}
return OBJ_bsearch_table(&fnd, tbl_standard, OSSL_NELEM(tbl_standard));
}
static ASN1_STRING_TABLE *stable_get(int nid)
{
ASN1_STRING_TABLE *tmp, *rv;
if (stable == NULL) {
stable = sk_ASN1_STRING_TABLE_new(sk_table_cmp);
if (stable == NULL)
return NULL;
}
tmp = ASN1_STRING_TABLE_get(nid);
if (tmp && tmp->flags & STABLE_FLAGS_MALLOC)
return tmp;
rv = OPENSSL_zalloc(sizeof(*rv));
if (rv == NULL)
return NULL;
if (!sk_ASN1_STRING_TABLE_push(stable, rv)) {
OPENSSL_free(rv);
return NULL;
}
if (tmp) {
rv->nid = tmp->nid;
rv->minsize = tmp->minsize;
rv->maxsize = tmp->maxsize;
rv->mask = tmp->mask;
rv->flags = tmp->flags | STABLE_FLAGS_MALLOC;
} else {
rv->minsize = -1;
rv->maxsize = -1;
rv->flags = STABLE_FLAGS_MALLOC;
}
return rv;
}
int ASN1_STRING_TABLE_add(int nid,
long minsize, long maxsize, unsigned long mask,
unsigned long flags)
{
ASN1_STRING_TABLE *tmp;
tmp = stable_get(nid);
if (!tmp) {
ASN1err(ASN1_F_ASN1_STRING_TABLE_ADD, ERR_R_MALLOC_FAILURE);
return 0;
}
if (minsize >= 0)
tmp->minsize = minsize;
if (maxsize >= 0)
tmp->maxsize = maxsize;
if (mask)
tmp->mask = mask;
if (flags)
tmp->flags = STABLE_FLAGS_MALLOC | flags;
return 1;
}
void ASN1_STRING_TABLE_cleanup(void)
{
STACK_OF(ASN1_STRING_TABLE) *tmp;
tmp = stable;
if (!tmp)
return;
stable = NULL;
sk_ASN1_STRING_TABLE_pop_free(tmp, st_free);
}
static void st_free(ASN1_STRING_TABLE *tbl)
{
if (tbl->flags & STABLE_FLAGS_MALLOC)
OPENSSL_free(tbl);
}
main()
{
ASN1_STRING_TABLE *tmp;
int i, last_nid = -1;
for (tmp = tbl_standard, i = 0; i < OSSL_NELEM(tbl_standard); i++, tmp++) {
if (tmp->nid < last_nid) {
last_nid = 0;
break;
}
last_nid = tmp->nid;
}
if (last_nid != 0) {
printf("Table order OK\n");
exit(0);
}
for (tmp = tbl_standard, i = 0; i < OSSL_NELEM(tbl_standard); i++, tmp++)
printf("Index %d, NID %d, Name=%s\n", i, tmp->nid,
OBJ_nid2ln(tmp->nid));
}
