static EC_GROUP *ec_group_new_from_data(const EC_CURVE_DATA *data)
{
EC_GROUP *group=NULL;
EC_POINT *P=NULL;
BN_CTX *ctx=NULL;
BIGNUM *p=NULL, *a=NULL, *b=NULL, *x=NULL, *y=NULL, *order=NULL;
int ok=0;
if ((ctx = BN_CTX_new()) == NULL)
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_MALLOC_FAILURE);
goto err;
}
if ((p = BN_new()) == NULL || (a = BN_new()) == NULL ||
(b = BN_new()) == NULL || (x = BN_new()) == NULL ||
(y = BN_new()) == NULL || (order = BN_new()) == NULL)
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_MALLOC_FAILURE);
goto err;
}
if (!BN_hex2bn(&p, data->p) || !BN_hex2bn(&a, data->a)
|| !BN_hex2bn(&b, data->b))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (data->field_type == NID_X9_62_prime_field)
{
if ((group = EC_GROUP_new_curve_GFp(p, a, b, ctx)) == NULL)
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
else
{
if ((group = EC_GROUP_new_curve_GF2m(p, a, b, ctx)) == NULL)
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
if ((P = EC_POINT_new(group)) == NULL)
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if (!BN_hex2bn(&x, data->x) || !BN_hex2bn(&y, data->y))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (!EC_POINT_set_affine_coordinates_GF2m(group, P, x, y, ctx))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if (!BN_hex2bn(&order, data->order) || !BN_set_word(x, data->cofactor))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_BN_LIB);
goto err;
}
if (!EC_GROUP_set_generator(group, P, order, x))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
if (data->seed)
{
if (!EC_GROUP_set_seed(group, data->seed, data->seed_len))
{
ECerr(EC_F_EC_GROUP_NEW_FROM_DATA, ERR_R_EC_LIB);
goto err;
}
}
ok=1;
err:
if (!ok)
{
EC_GROUP_free(group);
group = NULL;
}
if (P)
EC_POINT_free(P);
if (ctx)
BN_CTX_free(ctx);
if (p)
BN_free(p);
if (a)
BN_free(a);
if (b)
BN_free(b);
if (order)
BN_free(order);
if (x)
BN_free(x);
if (y)
BN_free(y);
return group;
}
EC_GROUP *EC_GROUP_new_by_curve_name(int nid)
{
size_t i;
EC_GROUP *ret = NULL;
if (nid <= 0)
return NULL;
for (i=0; i<curve_list_length; i++)
if (curve_list[i].nid == nid)
{
ret = ec_group_new_from_data(curve_list[i].data);
break;
}
if (ret == NULL)
{
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
for (i = 0; i < min; i++)
{
r[i].nid = curve_list[i].nid;
r[i].comment = curve_list[i].data->comment;
}
return curve_list_length;
}
