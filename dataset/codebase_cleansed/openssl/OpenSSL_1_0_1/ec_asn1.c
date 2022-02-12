int EC_GROUP_get_basis_type(const EC_GROUP *group)
{
int i=0;
if (EC_METHOD_get_field_type(EC_GROUP_method_of(group)) !=
NID_X9_62_characteristic_two_field)
return 0;
while (group->poly[i] != 0)
i++;
if (i == 4)
return NID_X9_62_ppBasis;
else if (i == 2)
return NID_X9_62_tpBasis;
else
return 0;
}
int EC_GROUP_get_trinomial_basis(const EC_GROUP *group, unsigned int *k)
{
if (group == NULL)
return 0;
if (EC_GROUP_method_of(group)->group_set_curve != ec_GF2m_simple_group_set_curve
|| !((group->poly[0] != 0) && (group->poly[1] != 0) && (group->poly[2] == 0)))
{
ECerr(EC_F_EC_GROUP_GET_TRINOMIAL_BASIS, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return 0;
}
if (k)
*k = group->poly[1];
return 1;
}
int EC_GROUP_get_pentanomial_basis(const EC_GROUP *group, unsigned int *k1,
unsigned int *k2, unsigned int *k3)
{
if (group == NULL)
return 0;
if (EC_GROUP_method_of(group)->group_set_curve != ec_GF2m_simple_group_set_curve
|| !((group->poly[0] != 0) && (group->poly[1] != 0) && (group->poly[2] != 0) && (group->poly[3] != 0) && (group->poly[4] == 0)))
{
ECerr(EC_F_EC_GROUP_GET_PENTANOMIAL_BASIS, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
return 0;
}
if (k1)
*k1 = group->poly[3];
if (k2)
*k2 = group->poly[2];
if (k3)
*k3 = group->poly[1];
return 1;
}
static int ec_asn1_group2fieldid(const EC_GROUP *group, X9_62_FIELDID *field)
{
int ok=0, nid;
BIGNUM *tmp = NULL;
if (group == NULL || field == NULL)
return 0;
if (field->fieldType != NULL)
ASN1_OBJECT_free(field->fieldType);
if (field->p.other != NULL)
ASN1_TYPE_free(field->p.other);
nid = EC_METHOD_get_field_type(EC_GROUP_method_of(group));
if ((field->fieldType = OBJ_nid2obj(nid)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_OBJ_LIB);
goto err;
}
if (nid == NID_X9_62_prime_field)
{
if ((tmp = BN_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EC_GROUP_get_curve_GFp(group, tmp, NULL, NULL, NULL))
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_EC_LIB);
goto err;
}
field->p.prime = BN_to_ASN1_INTEGER(tmp,NULL);
if (field->p.prime == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_ASN1_LIB);
goto err;
}
}
else
#ifdef OPENSSL_NO_EC2M
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, EC_R_GF2M_NOT_SUPPORTED);
goto err;
}
#else
{
int field_type;
X9_62_CHARACTERISTIC_TWO *char_two;
field->p.char_two = X9_62_CHARACTERISTIC_TWO_new();
char_two = field->p.char_two;
if (char_two == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_MALLOC_FAILURE);
goto err;
}
char_two->m = (long)EC_GROUP_get_degree(group);
field_type = EC_GROUP_get_basis_type(group);
if (field_type == 0)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_EC_LIB);
goto err;
}
if ((char_two->type = OBJ_nid2obj(field_type)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_OBJ_LIB);
goto err;
}
if (field_type == NID_X9_62_tpBasis)
{
unsigned int k;
if (!EC_GROUP_get_trinomial_basis(group, &k))
goto err;
char_two->p.tpBasis = ASN1_INTEGER_new();
if (!char_two->p.tpBasis)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!ASN1_INTEGER_set(char_two->p.tpBasis, (long)k))
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID,
ERR_R_ASN1_LIB);
goto err;
}
}
else if (field_type == NID_X9_62_ppBasis)
{
unsigned int k1, k2, k3;
if (!EC_GROUP_get_pentanomial_basis(group, &k1, &k2, &k3))
goto err;
char_two->p.ppBasis = X9_62_PENTANOMIAL_new();
if (!char_two->p.ppBasis)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_MALLOC_FAILURE);
goto err;
}
char_two->p.ppBasis->k1 = (long)k1;
char_two->p.ppBasis->k2 = (long)k2;
char_two->p.ppBasis->k3 = (long)k3;
}
else
{
char_two->p.onBasis = ASN1_NULL_new();
if (!char_two->p.onBasis)
{
ECerr(EC_F_EC_ASN1_GROUP2FIELDID, ERR_R_MALLOC_FAILURE);
goto err;
}
}
}
#endif
ok = 1;
err : if (tmp)
BN_free(tmp);
return(ok);
}
static int ec_asn1_group2curve(const EC_GROUP *group, X9_62_CURVE *curve)
{
int ok=0, nid;
BIGNUM *tmp_1=NULL, *tmp_2=NULL;
unsigned char *buffer_1=NULL, *buffer_2=NULL,
*a_buf=NULL, *b_buf=NULL;
size_t len_1, len_2;
unsigned char char_zero = 0;
if (!group || !curve || !curve->a || !curve->b)
return 0;
if ((tmp_1 = BN_new()) == NULL || (tmp_2 = BN_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_MALLOC_FAILURE);
goto err;
}
nid = EC_METHOD_get_field_type(EC_GROUP_method_of(group));
if (nid == NID_X9_62_prime_field)
{
if (!EC_GROUP_get_curve_GFp(group, NULL, tmp_1, tmp_2, NULL))
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_EC_LIB);
goto err;
}
}
#ifndef OPENSSL_NO_EC2M
else
{
if (!EC_GROUP_get_curve_GF2m(group, NULL, tmp_1, tmp_2, NULL))
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_EC_LIB);
goto err;
}
}
#endif
len_1 = (size_t)BN_num_bytes(tmp_1);
len_2 = (size_t)BN_num_bytes(tmp_2);
if (len_1 == 0)
{
a_buf = &char_zero;
len_1 = 1;
}
else
{
if ((buffer_1 = OPENSSL_malloc(len_1)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE,
ERR_R_MALLOC_FAILURE);
goto err;
}
if ( (len_1 = BN_bn2bin(tmp_1, buffer_1)) == 0)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_BN_LIB);
goto err;
}
a_buf = buffer_1;
}
if (len_2 == 0)
{
b_buf = &char_zero;
len_2 = 1;
}
else
{
if ((buffer_2 = OPENSSL_malloc(len_2)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE,
ERR_R_MALLOC_FAILURE);
goto err;
}
if ( (len_2 = BN_bn2bin(tmp_2, buffer_2)) == 0)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_BN_LIB);
goto err;
}
b_buf = buffer_2;
}
if (!M_ASN1_OCTET_STRING_set(curve->a, a_buf, len_1) ||
!M_ASN1_OCTET_STRING_set(curve->b, b_buf, len_2))
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_ASN1_LIB);
goto err;
}
if (group->seed)
{
if (!curve->seed)
if ((curve->seed = ASN1_BIT_STRING_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_MALLOC_FAILURE);
goto err;
}
curve->seed->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
curve->seed->flags |= ASN1_STRING_FLAG_BITS_LEFT;
if (!ASN1_BIT_STRING_set(curve->seed, group->seed,
(int)group->seed_len))
{
ECerr(EC_F_EC_ASN1_GROUP2CURVE, ERR_R_ASN1_LIB);
goto err;
}
}
else
{
if (curve->seed)
{
ASN1_BIT_STRING_free(curve->seed);
curve->seed = NULL;
}
}
ok = 1;
err: if (buffer_1)
OPENSSL_free(buffer_1);
if (buffer_2)
OPENSSL_free(buffer_2);
if (tmp_1)
BN_free(tmp_1);
if (tmp_2)
BN_free(tmp_2);
return(ok);
}
static ECPARAMETERS *ec_asn1_group2parameters(const EC_GROUP *group,
ECPARAMETERS *param)
{
int ok=0;
size_t len=0;
ECPARAMETERS *ret=NULL;
BIGNUM *tmp=NULL;
unsigned char *buffer=NULL;
const EC_POINT *point=NULL;
point_conversion_form_t form;
if ((tmp = BN_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_MALLOC_FAILURE);
goto err;
}
if (param == NULL)
{
if ((ret = ECPARAMETERS_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS,
ERR_R_MALLOC_FAILURE);
goto err;
}
}
else
ret = param;
ret->version = (long)0x1;
if (!ec_asn1_group2fieldid(group, ret->fieldID))
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_EC_LIB);
goto err;
}
if (!ec_asn1_group2curve(group, ret->curve))
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_EC_LIB);
goto err;
}
if ((point = EC_GROUP_get0_generator(group)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, EC_R_UNDEFINED_GENERATOR);
goto err;
}
form = EC_GROUP_get_point_conversion_form(group);
len = EC_POINT_point2oct(group, point, form, NULL, len, NULL);
if (len == 0)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_EC_LIB);
goto err;
}
if ((buffer = OPENSSL_malloc(len)) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!EC_POINT_point2oct(group, point, form, buffer, len, NULL))
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_EC_LIB);
goto err;
}
if (ret->base == NULL && (ret->base = ASN1_OCTET_STRING_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!ASN1_OCTET_STRING_set(ret->base, buffer, len))
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_ASN1_LIB);
goto err;
}
if (!EC_GROUP_get_order(group, tmp, NULL))
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_EC_LIB);
goto err;
}
ret->order = BN_to_ASN1_INTEGER(tmp, ret->order);
if (ret->order == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_ASN1_LIB);
goto err;
}
if (EC_GROUP_get_cofactor(group, tmp, NULL))
{
ret->cofactor = BN_to_ASN1_INTEGER(tmp, ret->cofactor);
if (ret->cofactor == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PARAMETERS, ERR_R_ASN1_LIB);
goto err;
}
}
ok = 1;
err : if(!ok)
{
if (ret && !param)
ECPARAMETERS_free(ret);
ret = NULL;
}
if (tmp)
BN_free(tmp);
if (buffer)
OPENSSL_free(buffer);
return(ret);
}
ECPKPARAMETERS *ec_asn1_group2pkparameters(const EC_GROUP *group,
ECPKPARAMETERS *params)
{
int ok = 1, tmp;
ECPKPARAMETERS *ret = params;
if (ret == NULL)
{
if ((ret = ECPKPARAMETERS_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_GROUP2PKPARAMETERS,
ERR_R_MALLOC_FAILURE);
return NULL;
}
}
else
{
if (ret->type == 0 && ret->value.named_curve)
ASN1_OBJECT_free(ret->value.named_curve);
else if (ret->type == 1 && ret->value.parameters)
ECPARAMETERS_free(ret->value.parameters);
}
if (EC_GROUP_get_asn1_flag(group))
{
tmp = EC_GROUP_get_curve_name(group);
if (tmp)
{
ret->type = 0;
if ((ret->value.named_curve = OBJ_nid2obj(tmp)) == NULL)
ok = 0;
}
else
ok = 0;
}
else
{
ret->type = 1;
if ((ret->value.parameters = ec_asn1_group2parameters(
group, NULL)) == NULL)
ok = 0;
}
if (!ok)
{
ECPKPARAMETERS_free(ret);
return NULL;
}
return ret;
}
static EC_GROUP *ec_asn1_parameters2group(const ECPARAMETERS *params)
{
int ok = 0, tmp;
EC_GROUP *ret = NULL;
BIGNUM *p = NULL, *a = NULL, *b = NULL;
EC_POINT *point=NULL;
long field_bits;
if (!params->fieldID || !params->fieldID->fieldType ||
!params->fieldID->p.ptr)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
if (!params->curve || !params->curve->a ||
!params->curve->a->data || !params->curve->b ||
!params->curve->b->data)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
a = BN_bin2bn(params->curve->a->data, params->curve->a->length, NULL);
if (a == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_BN_LIB);
goto err;
}
b = BN_bin2bn(params->curve->b->data, params->curve->b->length, NULL);
if (b == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_BN_LIB);
goto err;
}
tmp = OBJ_obj2nid(params->fieldID->fieldType);
if (tmp == NID_X9_62_characteristic_two_field)
#ifdef OPENSSL_NO_EC2M
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_GF2M_NOT_SUPPORTED);
goto err;
}
#else
{
X9_62_CHARACTERISTIC_TWO *char_two;
char_two = params->fieldID->p.char_two;
field_bits = char_two->m;
if (field_bits > OPENSSL_ECC_MAX_FIELD_BITS)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_FIELD_TOO_LARGE);
goto err;
}
if ((p = BN_new()) == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_MALLOC_FAILURE);
goto err;
}
tmp = OBJ_obj2nid(char_two->type);
if (tmp == NID_X9_62_tpBasis)
{
long tmp_long;
if (!char_two->p.tpBasis)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
tmp_long = ASN1_INTEGER_get(char_two->p.tpBasis);
if (!(char_two->m > tmp_long && tmp_long > 0))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_TRINOMIAL_BASIS);
goto err;
}
if (!BN_set_bit(p, (int)char_two->m))
goto err;
if (!BN_set_bit(p, (int)tmp_long))
goto err;
if (!BN_set_bit(p, 0))
goto err;
}
else if (tmp == NID_X9_62_ppBasis)
{
X9_62_PENTANOMIAL *penta;
penta = char_two->p.ppBasis;
if (!penta)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
if (!(char_two->m > penta->k3 && penta->k3 > penta->k2 && penta->k2 > penta->k1 && penta->k1 > 0))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_PENTANOMIAL_BASIS);
goto err;
}
if (!BN_set_bit(p, (int)char_two->m)) goto err;
if (!BN_set_bit(p, (int)penta->k1)) goto err;
if (!BN_set_bit(p, (int)penta->k2)) goto err;
if (!BN_set_bit(p, (int)penta->k3)) goto err;
if (!BN_set_bit(p, 0)) goto err;
}
else if (tmp == NID_X9_62_onBasis)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_NOT_IMPLEMENTED);
goto err;
}
else
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
ret = EC_GROUP_new_curve_GF2m(p, a, b, NULL);
}
#endif
else if (tmp == NID_X9_62_prime_field)
{
if (!params->fieldID->p.prime)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
p = ASN1_INTEGER_to_BN(params->fieldID->p.prime, NULL);
if (p == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_ASN1_LIB);
goto err;
}
if (BN_is_negative(p) || BN_is_zero(p))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_FIELD);
goto err;
}
field_bits = BN_num_bits(p);
if (field_bits > OPENSSL_ECC_MAX_FIELD_BITS)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_FIELD_TOO_LARGE);
goto err;
}
ret = EC_GROUP_new_curve_GFp(p, a, b, NULL);
}
else
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_FIELD);
goto err;
}
if (ret == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_EC_LIB);
goto err;
}
if (params->curve->seed != NULL)
{
if (ret->seed != NULL)
OPENSSL_free(ret->seed);
if (!(ret->seed = OPENSSL_malloc(params->curve->seed->length)))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP,
ERR_R_MALLOC_FAILURE);
goto err;
}
memcpy(ret->seed, params->curve->seed->data,
params->curve->seed->length);
ret->seed_len = params->curve->seed->length;
}
if (!params->order || !params->base || !params->base->data)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_ASN1_ERROR);
goto err;
}
if ((point = EC_POINT_new(ret)) == NULL) goto err;
EC_GROUP_set_point_conversion_form(ret, (point_conversion_form_t)
(params->base->data[0] & ~0x01));
if (!EC_POINT_oct2point(ret, point, params->base->data,
params->base->length, NULL))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_EC_LIB);
goto err;
}
if ((a = ASN1_INTEGER_to_BN(params->order, a)) == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_ASN1_LIB);
goto err;
}
if (BN_is_negative(a) || BN_is_zero(a))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_GROUP_ORDER);
goto err;
}
if (BN_num_bits(a) > (int)field_bits + 1)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, EC_R_INVALID_GROUP_ORDER);
goto err;
}
if (params->cofactor == NULL)
{
if (b)
{
BN_free(b);
b = NULL;
}
}
else
if ((b = ASN1_INTEGER_to_BN(params->cofactor, b)) == NULL)
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_ASN1_LIB);
goto err;
}
if (!EC_GROUP_set_generator(ret, point, a, b))
{
ECerr(EC_F_EC_ASN1_PARAMETERS2GROUP, ERR_R_EC_LIB);
goto err;
}
ok = 1;
err: if (!ok)
{
if (ret)
EC_GROUP_clear_free(ret);
ret = NULL;
}
if (p)
BN_free(p);
if (a)
BN_free(a);
if (b)
BN_free(b);
if (point)
EC_POINT_free(point);
return(ret);
}
EC_GROUP *ec_asn1_pkparameters2group(const ECPKPARAMETERS *params)
{
EC_GROUP *ret=NULL;
int tmp=0;
if (params == NULL)
{
ECerr(EC_F_EC_ASN1_PKPARAMETERS2GROUP,
EC_R_MISSING_PARAMETERS);
return NULL;
}
if (params->type == 0)
{
tmp = OBJ_obj2nid(params->value.named_curve);
if ((ret = EC_GROUP_new_by_curve_name(tmp)) == NULL)
{
ECerr(EC_F_EC_ASN1_PKPARAMETERS2GROUP,
EC_R_EC_GROUP_NEW_BY_NAME_FAILURE);
return NULL;
}
EC_GROUP_set_asn1_flag(ret, OPENSSL_EC_NAMED_CURVE);
}
else if (params->type == 1)
{
ret = ec_asn1_parameters2group(params->value.parameters);
if (!ret)
{
ECerr(EC_F_EC_ASN1_PKPARAMETERS2GROUP, ERR_R_EC_LIB);
return NULL;
}
EC_GROUP_set_asn1_flag(ret, 0x0);
}
else if (params->type == 2)
{
return NULL;
}
else
{
ECerr(EC_F_EC_ASN1_PKPARAMETERS2GROUP, EC_R_ASN1_ERROR);
return NULL;
}
return ret;
}
EC_GROUP *d2i_ECPKParameters(EC_GROUP **a, const unsigned char **in, long len)
{
EC_GROUP *group = NULL;
ECPKPARAMETERS *params = NULL;
if ((params = d2i_ECPKPARAMETERS(NULL, in, len)) == NULL)
{
ECerr(EC_F_D2I_ECPKPARAMETERS, EC_R_D2I_ECPKPARAMETERS_FAILURE);
ECPKPARAMETERS_free(params);
return NULL;
}
if ((group = ec_asn1_pkparameters2group(params)) == NULL)
{
ECerr(EC_F_D2I_ECPKPARAMETERS, EC_R_PKPARAMETERS2GROUP_FAILURE);
ECPKPARAMETERS_free(params);
return NULL;
}
if (a && *a)
EC_GROUP_clear_free(*a);
if (a)
*a = group;
ECPKPARAMETERS_free(params);
return(group);
}
int i2d_ECPKParameters(const EC_GROUP *a, unsigned char **out)
{
int ret=0;
ECPKPARAMETERS *tmp = ec_asn1_group2pkparameters(a, NULL);
if (tmp == NULL)
{
ECerr(EC_F_I2D_ECPKPARAMETERS, EC_R_GROUP2PKPARAMETERS_FAILURE);
return 0;
}
if ((ret = i2d_ECPKPARAMETERS(tmp, out)) == 0)
{
ECerr(EC_F_I2D_ECPKPARAMETERS, EC_R_I2D_ECPKPARAMETERS_FAILURE);
ECPKPARAMETERS_free(tmp);
return 0;
}
ECPKPARAMETERS_free(tmp);
return(ret);
}
EC_KEY *d2i_ECPrivateKey(EC_KEY **a, const unsigned char **in, long len)
{
int ok=0;
EC_KEY *ret=NULL;
EC_PRIVATEKEY *priv_key=NULL;
if ((priv_key = EC_PRIVATEKEY_new()) == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_MALLOC_FAILURE);
return NULL;
}
if ((priv_key = d2i_EC_PRIVATEKEY(&priv_key, in, len)) == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_EC_LIB);
EC_PRIVATEKEY_free(priv_key);
return NULL;
}
if (a == NULL || *a == NULL)
{
if ((ret = EC_KEY_new()) == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY,
ERR_R_MALLOC_FAILURE);
goto err;
}
if (a)
*a = ret;
}
else
ret = *a;
if (priv_key->parameters)
{
if (ret->group)
EC_GROUP_clear_free(ret->group);
ret->group = ec_asn1_pkparameters2group(priv_key->parameters);
}
if (ret->group == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
ret->version = priv_key->version;
if (priv_key->privateKey)
{
ret->priv_key = BN_bin2bn(
M_ASN1_STRING_data(priv_key->privateKey),
M_ASN1_STRING_length(priv_key->privateKey),
ret->priv_key);
if (ret->priv_key == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY,
ERR_R_BN_LIB);
goto err;
}
}
else
{
ECerr(EC_F_D2I_ECPRIVATEKEY,
EC_R_MISSING_PRIVATE_KEY);
goto err;
}
if (priv_key->publicKey)
{
const unsigned char *pub_oct;
size_t pub_oct_len;
if (ret->pub_key)
EC_POINT_clear_free(ret->pub_key);
ret->pub_key = EC_POINT_new(ret->group);
if (ret->pub_key == NULL)
{
ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
pub_oct = M_ASN1_STRING_data(priv_key->publicKey);
pub_oct_len = M_ASN1_STRING_length(priv_key->publicKey);
ret->conv_form = (point_conversion_form_t)(pub_oct[0] & ~0x01);
if (!EC_POINT_oct2point(ret->group, ret->pub_key,
pub_oct, pub_oct_len, NULL))
{
ECerr(EC_F_D2I_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
}
ok = 1;
err:
if (!ok)
{
if (ret)
EC_KEY_free(ret);
ret = NULL;
}
if (priv_key)
EC_PRIVATEKEY_free(priv_key);
return(ret);
}
int i2d_ECPrivateKey(EC_KEY *a, unsigned char **out)
{
int ret=0, ok=0;
unsigned char *buffer=NULL;
size_t buf_len=0, tmp_len;
EC_PRIVATEKEY *priv_key=NULL;
if (a == NULL || a->group == NULL || a->priv_key == NULL)
{
ECerr(EC_F_I2D_ECPRIVATEKEY,
ERR_R_PASSED_NULL_PARAMETER);
goto err;
}
if ((priv_key = EC_PRIVATEKEY_new()) == NULL)
{
ECerr(EC_F_I2D_ECPRIVATEKEY,
ERR_R_MALLOC_FAILURE);
goto err;
}
priv_key->version = a->version;
buf_len = (size_t)BN_num_bytes(a->priv_key);
buffer = OPENSSL_malloc(buf_len);
if (buffer == NULL)
{
ECerr(EC_F_I2D_ECPRIVATEKEY,
ERR_R_MALLOC_FAILURE);
goto err;
}
if (!BN_bn2bin(a->priv_key, buffer))
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_BN_LIB);
goto err;
}
if (!M_ASN1_OCTET_STRING_set(priv_key->privateKey, buffer, buf_len))
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_ASN1_LIB);
goto err;
}
if (!(a->enc_flag & EC_PKEY_NO_PARAMETERS))
{
if ((priv_key->parameters = ec_asn1_group2pkparameters(
a->group, priv_key->parameters)) == NULL)
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
}
if (!(a->enc_flag & EC_PKEY_NO_PUBKEY))
{
priv_key->publicKey = M_ASN1_BIT_STRING_new();
if (priv_key->publicKey == NULL)
{
ECerr(EC_F_I2D_ECPRIVATEKEY,
ERR_R_MALLOC_FAILURE);
goto err;
}
tmp_len = EC_POINT_point2oct(a->group, a->pub_key,
a->conv_form, NULL, 0, NULL);
if (tmp_len > buf_len)
{
unsigned char *tmp_buffer = OPENSSL_realloc(buffer, tmp_len);
if (!tmp_buffer)
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_MALLOC_FAILURE);
goto err;
}
buffer = tmp_buffer;
buf_len = tmp_len;
}
if (!EC_POINT_point2oct(a->group, a->pub_key,
a->conv_form, buffer, buf_len, NULL))
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
priv_key->publicKey->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
priv_key->publicKey->flags |= ASN1_STRING_FLAG_BITS_LEFT;
if (!M_ASN1_BIT_STRING_set(priv_key->publicKey, buffer,
buf_len))
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_ASN1_LIB);
goto err;
}
}
if ((ret = i2d_EC_PRIVATEKEY(priv_key, out)) == 0)
{
ECerr(EC_F_I2D_ECPRIVATEKEY, ERR_R_EC_LIB);
goto err;
}
ok=1;
err:
if (buffer)
OPENSSL_free(buffer);
if (priv_key)
EC_PRIVATEKEY_free(priv_key);
return(ok?ret:0);
}
int i2d_ECParameters(EC_KEY *a, unsigned char **out)
{
if (a == NULL)
{
ECerr(EC_F_I2D_ECPARAMETERS, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
return i2d_ECPKParameters(a->group, out);
}
EC_KEY *d2i_ECParameters(EC_KEY **a, const unsigned char **in, long len)
{
EC_KEY *ret;
if (in == NULL || *in == NULL)
{
ECerr(EC_F_D2I_ECPARAMETERS, ERR_R_PASSED_NULL_PARAMETER);
return NULL;
}
if (a == NULL || *a == NULL)
{
if ((ret = EC_KEY_new()) == NULL)
{
ECerr(EC_F_D2I_ECPARAMETERS, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (a)
*a = ret;
}
else
ret = *a;
if (!d2i_ECPKParameters(&ret->group, in, len))
{
ECerr(EC_F_D2I_ECPARAMETERS, ERR_R_EC_LIB);
return NULL;
}
return ret;
}
EC_KEY *o2i_ECPublicKey(EC_KEY **a, const unsigned char **in, long len)
{
EC_KEY *ret=NULL;
if (a == NULL || (*a) == NULL || (*a)->group == NULL)
{
ECerr(EC_F_O2I_ECPUBLICKEY, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
ret = *a;
if (ret->pub_key == NULL &&
(ret->pub_key = EC_POINT_new(ret->group)) == NULL)
{
ECerr(EC_F_O2I_ECPUBLICKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!EC_POINT_oct2point(ret->group, ret->pub_key, *in, len, NULL))
{
ECerr(EC_F_O2I_ECPUBLICKEY, ERR_R_EC_LIB);
return 0;
}
ret->conv_form = (point_conversion_form_t)(*in[0] & ~0x01);
*in += len;
return ret;
}
int i2o_ECPublicKey(EC_KEY *a, unsigned char **out)
{
size_t buf_len=0;
int new_buffer = 0;
if (a == NULL)
{
ECerr(EC_F_I2O_ECPUBLICKEY, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
buf_len = EC_POINT_point2oct(a->group, a->pub_key,
a->conv_form, NULL, 0, NULL);
if (out == NULL || buf_len == 0)
return buf_len;
if (*out == NULL)
{
if ((*out = OPENSSL_malloc(buf_len)) == NULL)
{
ECerr(EC_F_I2O_ECPUBLICKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
new_buffer = 1;
}
if (!EC_POINT_point2oct(a->group, a->pub_key, a->conv_form,
*out, buf_len, NULL))
{
ECerr(EC_F_I2O_ECPUBLICKEY, ERR_R_EC_LIB);
OPENSSL_free(*out);
*out = NULL;
return 0;
}
if (!new_buffer)
*out += buf_len;
return buf_len;
}
