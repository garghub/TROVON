int DES_random_key(DES_cblock *ret)
{
do {
if (RAND_bytes((unsigned char *)ret, sizeof(DES_cblock)) != 1)
return (0);
} while (DES_is_weak_key(ret));
DES_set_odd_parity(ret);
return (1);
}
