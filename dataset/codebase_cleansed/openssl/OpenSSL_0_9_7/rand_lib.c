int RAND_set_rand_method(const RAND_METHOD *meth)
{
if(funct_ref)
{
ENGINE_finish(funct_ref);
funct_ref = NULL;
}
default_RAND_meth = meth;
return 1;
}
const RAND_METHOD *RAND_get_rand_method(void)
{
if (!default_RAND_meth)
{
ENGINE *e = ENGINE_get_default_RAND();
if(e)
{
default_RAND_meth = ENGINE_get_RAND(e);
if(!default_RAND_meth)
{
ENGINE_finish(e);
e = NULL;
}
}
if(e)
funct_ref = e;
else
default_RAND_meth = RAND_SSLeay();
}
return default_RAND_meth;
}
int RAND_set_rand_engine(ENGINE *engine)
{
const RAND_METHOD *tmp_meth = NULL;
if(engine)
{
if(!ENGINE_init(engine))
return 0;
tmp_meth = ENGINE_get_RAND(engine);
if(!tmp_meth)
{
ENGINE_finish(engine);
return 0;
}
}
RAND_set_rand_method(tmp_meth);
funct_ref = engine;
return 1;
}
void RAND_cleanup(void)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->cleanup)
meth->cleanup();
RAND_set_rand_method(NULL);
}
void RAND_seed(const void *buf, int num)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->seed)
meth->seed(buf,num);
}
void RAND_add(const void *buf, int num, double entropy)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->add)
meth->add(buf,num,entropy);
}
int RAND_bytes(unsigned char *buf, int num)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->bytes)
return meth->bytes(buf,num);
return(-1);
}
int RAND_pseudo_bytes(unsigned char *buf, int num)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->pseudorand)
return meth->pseudorand(buf,num);
return(-1);
}
int RAND_status(void)
{
const RAND_METHOD *meth = RAND_get_rand_method();
if (meth && meth->status)
return meth->status();
return 0;
}
