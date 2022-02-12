static EC_GROUP *ec_group_new_from_data(const ec_list_element curve)
{
EC_GROUP *group = NULL;
EC_POINT *P = NULL;
BN_CTX *ctx = NULL;
BIGNUM *p = NULL, *a = NULL, *b = NULL, *x = NULL, *y = NULL, *order =
NULL;
int ok = 0;
int seed_len, param_len;
const EC_METHOD *meth;
const EC_CURVE_DATA *data;
const unsigned char *params;
if (curve.data == NULL)
return EC_GROUP_new(curve.meth != NULL ? curve.meth() : NULL);
if ((ctx = BN_CTX_new()) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_MALLOC_FAILURE);
goto err;
}
data = curve.data;
seed_len = data->seed_len;
param_len = data->param_len;
params = (const unsigned char *)(data + 1);
params += seed_len;
if ((p = BN_bin2bn(params + 0 * param_len, param_len, NULL)) == NULL
|| (a = BN_bin2bn(params + 1 * param_len, param_len, NULL)) == NULL
|| (b = BN_bin2bn(params + 2 * param_len, param_len, NULL)) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (curve.meth != 0) {
meth = curve.meth();
if (((group = EC_GROUP_new(meth)) == NULL) ||
(!(group->meth->group_set_curve(group, p, a, b, ctx)))) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
} else if (data->field_type == NID_X9_62_prime_field) {
if ((group = EC_GROUP_new_curve_GFp(p, a, b, ctx)) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
#ifndef OPENSSL_NO_EC2M
else {
if ((group = EC_GROUP_new_curve_GF2m(p, a, b, ctx)) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
#endif
if ((P = EC_POINT_new(group)) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if ((x = BN_bin2bn(params + 3 * param_len, param_len, NULL)) == NULL
|| (y = BN_bin2bn(params + 4 * param_len, param_len, NULL)) == NULL) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (!EC_POINT_set_affine_coordinates_GFp(group, P, x, y, ctx)) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if ((order = BN_bin2bn(params + 5 * param_len, param_len, NULL)) == NULL
|| !BN_set_word(x, (BN_ULONG)data->cofactor)) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (!EC_GROUP_set_generator(group, P, order, x)) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if (seed_len) {
if (!EC_GROUP_set_seed(group, params - seed_len, seed_len)) {
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
ok = 1;
err:
if (!ok) {
EC_GROUP_free(group);
group = NULL;
}
EC_POINT_free(P);
BN_CTX_free(ctx);
BN_free(p);
BN_free(a);
BN_free(b);
BN_free(order);
BN_free(x);
BN_free(y);
return group;
}
EC_GROUP *EC_GROUP_new_by_curve_name(int nid)
{
size_t i;
EC_GROUP *ret = NULL;
if (nid <= 0)
return NULL;
for (i = 0; i < curve_list_length; i++)
if (curve_list[i].nid == nid) {
ret = ec_group_new_from_data(curve_list[i]);
break;
}
if (ret == NULL) {
ECerr(EC_F_EC_GROUP_NEW_BY_CURVE_NAME, EC_R_UNKNOWN_GROUP);
return NULL;
}
EC_GROUP_set_curve_name(ret, nid);
return ret;
}
size_t EC_get_builtin_curves(EC_builtin_curve *r, size_t nitems)
{
size_t i, min;
if (r == NULL || nitems == 0)
return curve_list_length;
min = nitems < curve_list_length ? nitems : curve_list_length;
for (i = 0; i < min; i++) {
r[i].nid = curve_list[i].nid;
r[i].comment = curve_list[i].comment;
}
return curve_list_length;
}
const char *EC_curve_nid2nist(int nid)
{
size_t i;
for (i = 0; i < OSSL_NELEM(nist_curves); i++) {
if (nist_curves[i].nid == nid)
return nist_curves[i].name;
}
return NULL;
}
int EC_curve_nist2nid(const char *name)
{
size_t i;
for (i = 0; i < OSSL_NELEM(nist_curves); i++) {
if (strcmp(nist_curves[i].name, name) == 0)
return nist_curves[i].nid;
}
return NID_undef;
}
