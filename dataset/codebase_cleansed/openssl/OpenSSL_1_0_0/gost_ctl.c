void gost_param_free()
{
int i;
for (i=0;i<=GOST_PARAM_MAX;i++)
if (gost_params[i]!=NULL)
{
OPENSSL_free(gost_params[i]);
gost_params[i]=NULL;
}
}
int gost_control_func(ENGINE *e,int cmd,long i, void *p, void (*f)(void))
{
int param = cmd-ENGINE_CMD_BASE;
int ret=0;
if (param <0 || param >GOST_PARAM_MAX) return -1;
ret=gost_set_default_param(param,p);
return ret;
}
const char *get_gost_engine_param(int param)
{
char *tmp;
if (param <0 || param >GOST_PARAM_MAX) return NULL;
if (gost_params[param]!=NULL)
{
return gost_params[param];
}
tmp = getenv(gost_envnames[param]);
if (tmp)
{
if (gost_params[param]) OPENSSL_free(gost_params[param]);
gost_params[param] = BUF_strdup(tmp);
return gost_params[param];
}
return NULL;
}
int gost_set_default_param(int param, const char *value)
{
const char *tmp;
if (param <0 || param >GOST_PARAM_MAX) return 0;
tmp = getenv(gost_envnames[param]);
if (!tmp) tmp=value;
if (gost_params[param]) OPENSSL_free(gost_params[param]);
gost_params[param] = BUF_strdup(tmp);
return 1;
}
