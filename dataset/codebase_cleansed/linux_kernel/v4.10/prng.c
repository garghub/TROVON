unsigned int cfs_rand(void)
{
seed_x = RANDOM_CONST_A * (seed_x & 65535) + (seed_x >> 16);
seed_y = RANDOM_CONST_B * (seed_y & 65535) + (seed_y >> 16);
return ((seed_x << 16) + (seed_y & 65535));
}
void cfs_srand(unsigned int seed1, unsigned int seed2)
{
if (seed1)
seed_x = seed1;
if (seed2)
seed_y = seed2;
}
void cfs_get_random_bytes(void *buf, int size)
{
int *p = buf;
int rem, tmp;
LASSERT(size >= 0);
rem = min((int)((unsigned long)buf & (sizeof(int) - 1)), size);
if (rem) {
get_random_bytes(&tmp, sizeof(tmp));
tmp ^= cfs_rand();
memcpy(buf, &tmp, rem);
p = buf + rem;
size -= rem;
}
while (size >= sizeof(int)) {
get_random_bytes(&tmp, sizeof(tmp));
*p = cfs_rand() ^ tmp;
size -= sizeof(int);
p++;
}
buf = p;
if (size) {
get_random_bytes(&tmp, sizeof(tmp));
tmp ^= cfs_rand();
memcpy(buf, &tmp, size);
}
}
