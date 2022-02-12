static int get_random_bytes(unsigned char *buf, int num)
{
size_t rnd;
while (num >= (int)sizeof(size_t)) {
if ((rnd = OPENSSL_ia32_rdrand()) == 0)
return 0;
*((size_t *)buf) = rnd;
buf += sizeof(size_t);
num -= sizeof(size_t);
}
if (num) {
if ((rnd = OPENSSL_ia32_rdrand()) == 0)
return 0;
memcpy(buf, &rnd, num);
}
return 1;
}
static int random_status(void)
{
return 1;
}
static int rdrand_init(ENGINE *e)
{
return 1;
}
static int bind_helper(ENGINE *e)
{
if (!ENGINE_set_id(e, engine_e_rdrand_id) ||
!ENGINE_set_name(e, engine_e_rdrand_name) ||
!ENGINE_set_flags(e, ENGINE_FLAGS_NO_REGISTER_ALL) ||
!ENGINE_set_init_function(e, rdrand_init) ||
!ENGINE_set_RAND(e, &rdrand_meth))
return 0;
return 1;
}
static ENGINE *ENGINE_rdrand(void)
{
ENGINE *ret = ENGINE_new();
if (!ret)
return NULL;
if (!bind_helper(ret)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void ENGINE_load_rdrand(void)
{
extern unsigned int OPENSSL_ia32cap_P[];
if (OPENSSL_ia32cap_P[1] & (1 << (62 - 32))) {
ENGINE *toadd = ENGINE_rdrand();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
}
void ENGINE_load_rdrand(void)
{
}
