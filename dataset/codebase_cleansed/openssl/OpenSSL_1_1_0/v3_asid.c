int i2r_ASIdentifiers(const X509V3_EXT_METHOD *method,
void *ext, BIO *out, int indent)
{
ASIdentifiers *asid = ext;
return (i2r_ASIdentifierChoice(out, asid->asnum, indent,
"Autonomous System Numbers") &&
i2r_ASIdentifierChoice(out, asid->rdi, indent,
"Routing Domain Identifiers"));
}
static int ASIdOrRange_cmp(const ASIdOrRange *const *a_,
const ASIdOrRange *const *b_)
{
const ASIdOrRange *a = *a_, *b = *b_;
OPENSSL_assert((a->type == ASIdOrRange_id && a->u.id != NULL) ||
(a->type == ASIdOrRange_range && a->u.range != NULL &&
a->u.range->min != NULL && a->u.range->max != NULL));
OPENSSL_assert((b->type == ASIdOrRange_id && b->u.id != NULL) ||
(b->type == ASIdOrRange_range && b->u.range != NULL &&
b->u.range->min != NULL && b->u.range->max != NULL));
if (a->type == ASIdOrRange_id && b->type == ASIdOrRange_id)
return ASN1_INTEGER_cmp(a->u.id, b->u.id);
if (a->type == ASIdOrRange_range && b->type == ASIdOrRange_range) {
int r = ASN1_INTEGER_cmp(a->u.range->min, b->u.range->min);
return r != 0 ? r : ASN1_INTEGER_cmp(a->u.range->max,
b->u.range->max);
}
if (a->type == ASIdOrRange_id)
return ASN1_INTEGER_cmp(a->u.id, b->u.range->min);
else
return ASN1_INTEGER_cmp(a->u.range->min, b->u.id);
}
int X509v3_asid_add_inherit(ASIdentifiers *asid, int which)
{
ASIdentifierChoice **choice;
if (asid == NULL)
return 0;
switch (which) {
case V3_ASID_ASNUM:
choice = &asid->asnum;
break;
case V3_ASID_RDI:
choice = &asid->rdi;
break;
default:
return 0;
}
if (*choice == NULL) {
if ((*choice = ASIdentifierChoice_new()) == NULL)
return 0;
OPENSSL_assert((*choice)->u.inherit == NULL);
if (((*choice)->u.inherit = ASN1_NULL_new()) == NULL)
return 0;
(*choice)->type = ASIdentifierChoice_inherit;
}
return (*choice)->type == ASIdentifierChoice_inherit;
}
int X509v3_asid_add_id_or_range(ASIdentifiers *asid,
int which, ASN1_INTEGER *min, ASN1_INTEGER *max)
{
ASIdentifierChoice **choice;
ASIdOrRange *aor;
if (asid == NULL)
return 0;
switch (which) {
case V3_ASID_ASNUM:
choice = &asid->asnum;
break;
case V3_ASID_RDI:
choice = &asid->rdi;
break;
default:
return 0;
}
if (*choice != NULL && (*choice)->type == ASIdentifierChoice_inherit)
return 0;
if (*choice == NULL) {
if ((*choice = ASIdentifierChoice_new()) == NULL)
return 0;
OPENSSL_assert((*choice)->u.asIdsOrRanges == NULL);
(*choice)->u.asIdsOrRanges = sk_ASIdOrRange_new(ASIdOrRange_cmp);
if ((*choice)->u.asIdsOrRanges == NULL)
return 0;
(*choice)->type = ASIdentifierChoice_asIdsOrRanges;
}
if ((aor = ASIdOrRange_new()) == NULL)
return 0;
if (max == NULL) {
aor->type = ASIdOrRange_id;
aor->u.id = min;
} else {
aor->type = ASIdOrRange_range;
if ((aor->u.range = ASRange_new()) == NULL)
goto err;
ASN1_INTEGER_free(aor->u.range->min);
aor->u.range->min = min;
ASN1_INTEGER_free(aor->u.range->max);
aor->u.range->max = max;
}
if (!(sk_ASIdOrRange_push((*choice)->u.asIdsOrRanges, aor)))
goto err;
return 1;
err:
ASIdOrRange_free(aor);
return 0;
}
static void extract_min_max(ASIdOrRange *aor,
ASN1_INTEGER **min, ASN1_INTEGER **max)
{
OPENSSL_assert(aor != NULL && min != NULL && max != NULL);
switch (aor->type) {
case ASIdOrRange_id:
*min = aor->u.id;
*max = aor->u.id;
return;
case ASIdOrRange_range:
*min = aor->u.range->min;
*max = aor->u.range->max;
return;
}
}
static int ASIdentifierChoice_is_canonical(ASIdentifierChoice *choice)
{
ASN1_INTEGER *a_max_plus_one = NULL;
BIGNUM *bn = NULL;
int i, ret = 0;
if (choice == NULL || choice->type == ASIdentifierChoice_inherit)
return 1;
if (choice->type != ASIdentifierChoice_asIdsOrRanges ||
sk_ASIdOrRange_num(choice->u.asIdsOrRanges) == 0)
return 0;
for (i = 0; i < sk_ASIdOrRange_num(choice->u.asIdsOrRanges) - 1; i++) {
ASIdOrRange *a = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i);
ASIdOrRange *b = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i + 1);
ASN1_INTEGER *a_min = NULL, *a_max = NULL, *b_min = NULL, *b_max =
NULL;
extract_min_max(a, &a_min, &a_max);
extract_min_max(b, &b_min, &b_max);
if (ASN1_INTEGER_cmp(a_min, b_min) >= 0 ||
ASN1_INTEGER_cmp(a_min, a_max) > 0 ||
ASN1_INTEGER_cmp(b_min, b_max) > 0)
goto done;
if ((bn == NULL && (bn = BN_new()) == NULL) ||
ASN1_INTEGER_to_BN(a_max, bn) == NULL ||
!BN_add_word(bn, 1) ||
(a_max_plus_one =
BN_to_ASN1_INTEGER(bn, a_max_plus_one)) == NULL) {
X509V3err(X509V3_F_ASIDENTIFIERCHOICE_IS_CANONICAL,
ERR_R_MALLOC_FAILURE);
goto done;
}
if (ASN1_INTEGER_cmp(a_max_plus_one, b_min) >= 0)
goto done;
}
i = sk_ASIdOrRange_num(choice->u.asIdsOrRanges) - 1;
{
ASIdOrRange *a = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i);
ASN1_INTEGER *a_min, *a_max;
if (a != NULL && a->type == ASIdOrRange_range) {
extract_min_max(a, &a_min, &a_max);
if (ASN1_INTEGER_cmp(a_min, a_max) > 0)
goto done;
}
}
ret = 1;
done:
ASN1_INTEGER_free(a_max_plus_one);
BN_free(bn);
return ret;
}
int X509v3_asid_is_canonical(ASIdentifiers *asid)
{
return (asid == NULL ||
(ASIdentifierChoice_is_canonical(asid->asnum) &&
ASIdentifierChoice_is_canonical(asid->rdi)));
}
static int ASIdentifierChoice_canonize(ASIdentifierChoice *choice)
{
ASN1_INTEGER *a_max_plus_one = NULL;
BIGNUM *bn = NULL;
int i, ret = 0;
if (choice == NULL || choice->type == ASIdentifierChoice_inherit)
return 1;
if (choice->type != ASIdentifierChoice_asIdsOrRanges ||
sk_ASIdOrRange_num(choice->u.asIdsOrRanges) == 0) {
X509V3err(X509V3_F_ASIDENTIFIERCHOICE_CANONIZE,
X509V3_R_EXTENSION_VALUE_ERROR);
return 0;
}
sk_ASIdOrRange_sort(choice->u.asIdsOrRanges);
for (i = 0; i < sk_ASIdOrRange_num(choice->u.asIdsOrRanges) - 1; i++) {
ASIdOrRange *a = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i);
ASIdOrRange *b = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i + 1);
ASN1_INTEGER *a_min = NULL, *a_max = NULL, *b_min = NULL, *b_max =
NULL;
extract_min_max(a, &a_min, &a_max);
extract_min_max(b, &b_min, &b_max);
OPENSSL_assert(ASN1_INTEGER_cmp(a_min, b_min) <= 0);
if (ASN1_INTEGER_cmp(a_min, a_max) > 0 ||
ASN1_INTEGER_cmp(b_min, b_max) > 0)
goto done;
if (ASN1_INTEGER_cmp(a_max, b_min) >= 0) {
X509V3err(X509V3_F_ASIDENTIFIERCHOICE_CANONIZE,
X509V3_R_EXTENSION_VALUE_ERROR);
goto done;
}
if ((bn == NULL && (bn = BN_new()) == NULL) ||
ASN1_INTEGER_to_BN(a_max, bn) == NULL ||
!BN_add_word(bn, 1) ||
(a_max_plus_one =
BN_to_ASN1_INTEGER(bn, a_max_plus_one)) == NULL) {
X509V3err(X509V3_F_ASIDENTIFIERCHOICE_CANONIZE,
ERR_R_MALLOC_FAILURE);
goto done;
}
if (ASN1_INTEGER_cmp(a_max_plus_one, b_min) == 0) {
ASRange *r;
switch (a->type) {
case ASIdOrRange_id:
if ((r = OPENSSL_malloc(sizeof(*r))) == NULL) {
X509V3err(X509V3_F_ASIDENTIFIERCHOICE_CANONIZE,
ERR_R_MALLOC_FAILURE);
goto done;
}
r->min = a_min;
r->max = b_max;
a->type = ASIdOrRange_range;
a->u.range = r;
break;
case ASIdOrRange_range:
ASN1_INTEGER_free(a->u.range->max);
a->u.range->max = b_max;
break;
}
switch (b->type) {
case ASIdOrRange_id:
b->u.id = NULL;
break;
case ASIdOrRange_range:
b->u.range->max = NULL;
break;
}
ASIdOrRange_free(b);
(void)sk_ASIdOrRange_delete(choice->u.asIdsOrRanges, i + 1);
i--;
continue;
}
}
i = sk_ASIdOrRange_num(choice->u.asIdsOrRanges) - 1;
{
ASIdOrRange *a = sk_ASIdOrRange_value(choice->u.asIdsOrRanges, i);
ASN1_INTEGER *a_min, *a_max;
if (a != NULL && a->type == ASIdOrRange_range) {
extract_min_max(a, &a_min, &a_max);
if (ASN1_INTEGER_cmp(a_min, a_max) > 0)
goto done;
}
}
OPENSSL_assert(ASIdentifierChoice_is_canonical(choice));
ret = 1;
done:
ASN1_INTEGER_free(a_max_plus_one);
BN_free(bn);
return ret;
}
int X509v3_asid_canonize(ASIdentifiers *asid)
{
return (asid == NULL ||
(ASIdentifierChoice_canonize(asid->asnum) &&
ASIdentifierChoice_canonize(asid->rdi)));
}
int X509v3_asid_inherits(ASIdentifiers *asid)
{
return (asid != NULL &&
((asid->asnum != NULL &&
asid->asnum->type == ASIdentifierChoice_inherit) ||
(asid->rdi != NULL &&
asid->rdi->type == ASIdentifierChoice_inherit)));
}
static int asid_contains(ASIdOrRanges *parent, ASIdOrRanges *child)
{
ASN1_INTEGER *p_min = NULL, *p_max = NULL, *c_min = NULL, *c_max = NULL;
int p, c;
if (child == NULL || parent == child)
return 1;
if (parent == NULL)
return 0;
p = 0;
for (c = 0; c < sk_ASIdOrRange_num(child); c++) {
extract_min_max(sk_ASIdOrRange_value(child, c), &c_min, &c_max);
for (;; p++) {
if (p >= sk_ASIdOrRange_num(parent))
return 0;
extract_min_max(sk_ASIdOrRange_value(parent, p), &p_min, &p_max);
if (ASN1_INTEGER_cmp(p_max, c_max) < 0)
continue;
if (ASN1_INTEGER_cmp(p_min, c_min) > 0)
return 0;
break;
}
}
return 1;
}
int X509v3_asid_subset(ASIdentifiers *a, ASIdentifiers *b)
{
return (a == NULL ||
a == b ||
(b != NULL &&
!X509v3_asid_inherits(a) &&
!X509v3_asid_inherits(b) &&
asid_contains(b->asnum->u.asIdsOrRanges,
a->asnum->u.asIdsOrRanges) &&
asid_contains(b->rdi->u.asIdsOrRanges,
a->rdi->u.asIdsOrRanges)));
}
int X509v3_asid_validate_path(X509_STORE_CTX *ctx)
{
return asid_validate_path_internal(ctx, ctx->chain, NULL);
}
