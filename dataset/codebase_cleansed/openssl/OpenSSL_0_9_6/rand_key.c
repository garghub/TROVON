void des_random_seed(des_cblock *key)
{
RAND_seed(key, sizeof(des_cblock));
}
int des_random_key(des_cblock *ret)
{
do
{
if (RAND_bytes((unsigned char *)ret, sizeof(des_cblock)) != 1)
return (0);
} while (des_is_weak_key(ret));
des_set_odd_parity(ret);
return (1);
}
