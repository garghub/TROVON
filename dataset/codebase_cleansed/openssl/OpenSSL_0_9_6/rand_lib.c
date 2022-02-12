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
void RAND_add(const void *buf, int num, double entropy)
{
if (rand_meth != NULL)
rand_meth->add(buf,num,entropy);
}
int RAND_bytes(unsigned char *buf, int num)
{
if (rand_meth != NULL)
return rand_meth->bytes(buf,num);
return(-1);
}
int RAND_pseudo_bytes(unsigned char *buf, int num)
{
if (rand_meth != NULL)
return rand_meth->pseudorand(buf,num);
return(-1);
}
int RAND_status(void)
{
if (rand_meth != NULL)
return rand_meth->status();
return 0;
}
