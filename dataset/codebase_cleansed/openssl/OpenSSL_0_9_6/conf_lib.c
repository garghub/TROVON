int CONF_set_default_method(CONF_METHOD *meth)
{
default_CONF_method = meth;
return 1;
}
LHASH *CONF_load(LHASH *conf, const char *file, long *eline)
{
LHASH *ltmp;
BIO *in=NULL;
#ifdef VMS
in=BIO_new_file(file, "r");
#else
in=BIO_new_file(file, "rb");
#endif
if (in == NULL)
{
CONFerr(CONF_F_CONF_LOAD,ERR_R_SYS_LIB);
return NULL;
}
ltmp = CONF_load_bio(conf, in, eline);
BIO_free(in);
return ltmp;
}
LHASH *CONF_load_fp(LHASH *conf, FILE *fp,long *eline)
{
BIO *btmp;
LHASH *ltmp;
if(!(btmp = BIO_new_fp(fp, BIO_NOCLOSE))) {
CONFerr(CONF_F_CONF_LOAD_FP,ERR_R_BUF_LIB);
return NULL;
}
ltmp = CONF_load_bio(conf, btmp, eline);
BIO_free(btmp);
return ltmp;
}
LHASH *CONF_load_bio(LHASH *conf, BIO *bp,long *eline)
{
CONF ctmp;
int ret;
if (default_CONF_method == NULL)
default_CONF_method = NCONF_default();
default_CONF_method->init(&ctmp);
ctmp.data = conf;
ret = NCONF_load_bio(&ctmp, bp, eline);
if (ret)
return ctmp.data;
return NULL;
}
void CONF_free(LHASH *conf)
{
CONF ctmp;
if (default_CONF_method == NULL)
default_CONF_method = NCONF_default();
default_CONF_method->init(&ctmp);
ctmp.data = conf;
NCONF_free_data(&ctmp);
}
int CONF_dump_fp(LHASH *conf, FILE *out)
{
BIO *btmp;
int ret;
if(!(btmp = BIO_new_fp(out, BIO_NOCLOSE))) {
CONFerr(CONF_F_CONF_DUMP_FP,ERR_R_BUF_LIB);
return 0;
}
ret = CONF_dump_bio(conf, btmp);
BIO_free(btmp);
return ret;
}
int CONF_dump_bio(LHASH *conf, BIO *out)
{
CONF ctmp;
if (default_CONF_method == NULL)
default_CONF_method = NCONF_default();
default_CONF_method->init(&ctmp);
ctmp.data = conf;
return NCONF_dump_bio(&ctmp, out);
}
CONF *NCONF_new(CONF_METHOD *meth)
{
CONF *ret;
if (meth == NULL)
meth = NCONF_default();
ret = meth->create(meth);
if (ret == NULL)
{
CONFerr(CONF_F_NCONF_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
return ret;
}
void NCONF_free(CONF *conf)
{
if (conf == NULL)
return;
conf->meth->destroy(conf);
}
void NCONF_free_data(CONF *conf)
{
if (conf == NULL)
return;
conf->meth->destroy_data(conf);
}
int NCONF_load(CONF *conf, const char *file, long *eline)
{
int ret;
BIO *in=NULL;
#ifdef VMS
in=BIO_new_file(file, "r");
#else
in=BIO_new_file(file, "rb");
#endif
if (in == NULL)
{
CONFerr(CONF_F_CONF_LOAD,ERR_R_SYS_LIB);
return 0;
}
ret = NCONF_load_bio(conf, in, eline);
BIO_free(in);
return ret;
}
int NCONF_load_fp(CONF *conf, FILE *fp,long *eline)
{
BIO *btmp;
int ret;
if(!(btmp = BIO_new_fp(fp, BIO_NOCLOSE)))
{
CONFerr(CONF_F_CONF_LOAD_FP,ERR_R_BUF_LIB);
return 0;
}
ret = NCONF_load_bio(conf, btmp, eline);
BIO_free(btmp);
return ret;
}
int NCONF_load_bio(CONF *conf, BIO *bp,long *eline)
{
if (conf == NULL)
{
CONFerr(CONF_F_NCONF_LOAD_BIO,CONF_R_NO_CONF);
return 0;
}
return conf->meth->load(conf, bp, eline);
}
int NCONF_dump_fp(CONF *conf, FILE *out)
{
BIO *btmp;
int ret;
if(!(btmp = BIO_new_fp(out, BIO_NOCLOSE))) {
CONFerr(CONF_F_NCONF_DUMP_FP,ERR_R_BUF_LIB);
return 0;
}
ret = NCONF_dump_bio(conf, btmp);
BIO_free(btmp);
return ret;
}
int NCONF_dump_bio(CONF *conf, BIO *out)
{
if (conf == NULL)
{
CONFerr(CONF_F_NCONF_DUMP_BIO,CONF_R_NO_CONF);
return 0;
}
return conf->meth->dump(conf, out);
}
