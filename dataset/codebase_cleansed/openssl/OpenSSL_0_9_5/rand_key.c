void des_random_seed(des_cblock *key)
{
RAND_seed(key, sizeof(des_cblock));
}
int des_random_key(des_cblock *ret)
{
int r = RAND_bytes((unsigned char *)ret, sizeof(des_cblock));
des_set_odd_parity(ret);
return r;
}
