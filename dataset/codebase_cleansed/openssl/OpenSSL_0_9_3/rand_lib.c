void RAND_set_rand_method(RAND_METHOD *meth)
{
rand_meth=meth;
}
RAND_METHOD *RAND_get_rand_method(void)
{
return(rand_meth);
}
void RAND_cleanup(void)
{
if (rand_meth != NULL)
rand_meth->cleanup();
}
void RAND_seed(const void *buf, int num)
{
if (rand_meth != NULL)
rand_meth->seed(buf,num);
}
void RAND_bytes(unsigned char *buf, int num)
{
if (rand_meth != NULL)
rand_meth->bytes(buf,num);
}
