int CONF_set_default_method(CONF_METHOD *meth)
{
default_CONF_method = meth;
return 1;
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
if (conf == NULL)
{
CONFerr(CONF_F_NCONF_LOAD,CONF_R_NO_CONF);
return 0;
}
return conf->meth->load(conf, file, eline);
}
int NCONF_load_fp(CONF *conf, FILE *fp,long *eline)
{
BIO *btmp;
int ret;
if(!(btmp = BIO_new_fp(fp, BIO_NOCLOSE)))
{
CONFerr(CONF_F_NCONF_LOAD_FP,ERR_R_BUF_LIB);
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
return conf->meth->load_bio(conf, bp, eline);
}
int NCONF_dump_fp(const CONF *conf, FILE *out)
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
int NCONF_dump_bio(const CONF *conf, BIO *out)
{
if (conf == NULL)
{
CONFerr(CONF_F_NCONF_DUMP_BIO,CONF_R_NO_CONF);
return 0;
}
return conf->meth->dump(conf, out);
}
