int CONF_modules_load(const CONF *cnf, const char *appname,
unsigned long flags)
{
STACK_OF(CONF_VALUE) *values;
CONF_VALUE *vl;
char *vsection;
int ret, i;
if (!cnf)
return 1;
if (appname == NULL)
appname = "openssl_conf";
vsection = NCONF_get_string(cnf, NULL, appname);
if (!vsection)
{
ERR_clear_error();
return 1;
}
values = NCONF_get_section(cnf, vsection);
if (!values)
return 0;
for (i = 0; i < sk_CONF_VALUE_num(values); i++)
{
vl = sk_CONF_VALUE_value(values, i);
ret = module_run(cnf, vl->name, vl->value, flags);
if (ret <= 0)
if(!(flags & CONF_MFLAGS_IGNORE_ERRORS))
return ret;
}
return 1;
}
int CONF_modules_load_file(const char *filename, const char *appname,
unsigned long flags)
{
char *file = NULL;
CONF *conf = NULL;
int ret = 0;
conf = NCONF_new(NULL);
if (!conf)
goto err;
if (filename == NULL)
{
file = CONF_get1_default_config_file();
if (!file)
goto err;
}
else
file = (char *)filename;
if (NCONF_load(conf, file, NULL) <= 0)
{
if ((flags & CONF_MFLAGS_IGNORE_MISSING_FILE) &&
(ERR_GET_REASON(ERR_peek_last_error()) == CONF_R_NO_SUCH_FILE))
{
ERR_clear_error();
ret = 1;
}
goto err;
}
ret = CONF_modules_load(conf, appname, flags);
err:
if (filename == NULL)
OPENSSL_free(file);
NCONF_free(conf);
return ret;
}
static int module_run(const CONF *cnf, char *name, char *value,
unsigned long flags)
{
CONF_MODULE *md;
int ret;
md = module_find(name);
if (!md && !(flags & CONF_MFLAGS_NO_DSO))
md = module_load_dso(cnf, name, value, flags);
if (!md)
{
if (!(flags & CONF_MFLAGS_SILENT))
{
CONFerr(CONF_F_MODULE_RUN, CONF_R_UNKNOWN_MODULE_NAME);
ERR_add_error_data(2, "module=", name);
}
return -1;
}
ret = module_init(md, name, value, cnf);
if (ret <= 0)
{
if (!(flags & CONF_MFLAGS_SILENT))
{
char rcode[DECIMAL_SIZE(ret)+1];
CONFerr(CONF_F_MODULE_RUN, CONF_R_MODULE_INITIALIZATION_ERROR);
BIO_snprintf(rcode, sizeof rcode, "%-8d", ret);
ERR_add_error_data(6, "module=", name, ", value=", value, ", retcode=", rcode);
}
}
return ret;
}
static CONF_MODULE *module_load_dso(const CONF *cnf, char *name, char *value,
unsigned long flags)
{
DSO *dso = NULL;
conf_init_func *ifunc;
conf_finish_func *ffunc;
char *path = NULL;
int errcode = 0;
CONF_MODULE *md;
path = NCONF_get_string(cnf, value, "path");
if (!path)
{
ERR_clear_error();
path = name;
}
dso = DSO_load(NULL, path, NULL, 0);
if (!dso)
{
errcode = CONF_R_ERROR_LOADING_DSO;
goto err;
}
ifunc = (conf_init_func *)DSO_bind_func(dso, DSO_mod_init_name);
if (!ifunc)
{
errcode = CONF_R_MISSING_INIT_FUNCTION;
goto err;
}
ffunc = (conf_finish_func *)DSO_bind_func(dso, DSO_mod_finish_name);
md = module_add(dso, name, ifunc, ffunc);
if (!md)
goto err;
return md;
err:
if (dso)
DSO_free(dso);
CONFerr(CONF_F_MODULE_LOAD_DSO, errcode);
ERR_add_error_data(4, "module=", name, ", path=", path);
return NULL;
}
static CONF_MODULE *module_add(DSO *dso, const char *name,
conf_init_func *ifunc, conf_finish_func *ffunc)
{
CONF_MODULE *tmod = NULL;
if (supported_modules == NULL)
supported_modules = sk_CONF_MODULE_new_null();
if (supported_modules == NULL)
return NULL;
tmod = OPENSSL_malloc(sizeof(CONF_MODULE));
if (tmod == NULL)
return NULL;
tmod->dso = dso;
tmod->name = BUF_strdup(name);
tmod->init = ifunc;
tmod->finish = ffunc;
tmod->links = 0;
if (!sk_CONF_MODULE_push(supported_modules, tmod))
{
OPENSSL_free(tmod);
return NULL;
}
return tmod;
}
static CONF_MODULE *module_find(char *name)
{
CONF_MODULE *tmod;
int i, nchar;
char *p;
p = strrchr(name, '.');
if (p)
nchar = p - name;
else
nchar = strlen(name);
for (i = 0; i < sk_CONF_MODULE_num(supported_modules); i++)
{
tmod = sk_CONF_MODULE_value(supported_modules, i);
if (!strncmp(tmod->name, name, nchar))
return tmod;
}
return NULL;
}
static int module_init(CONF_MODULE *pmod, char *name, char *value,
const CONF *cnf)
{
int ret = 1;
int init_called = 0;
CONF_IMODULE *imod = NULL;
imod = OPENSSL_malloc(sizeof(CONF_IMODULE));
if (!imod)
goto err;
imod->pmod = pmod;
imod->name = BUF_strdup(name);
imod->value = BUF_strdup(value);
imod->usr_data = NULL;
if (!imod->name || !imod->value)
goto memerr;
if(pmod->init)
{
ret = pmod->init(imod, cnf);
init_called = 1;
if (ret <= 0)
goto err;
}
if (initialized_modules == NULL)
{
initialized_modules = sk_CONF_IMODULE_new_null();
if (!initialized_modules)
{
CONFerr(CONF_F_MODULE_INIT, ERR_R_MALLOC_FAILURE);
goto err;
}
}
if (!sk_CONF_IMODULE_push(initialized_modules, imod))
{
CONFerr(CONF_F_MODULE_INIT, ERR_R_MALLOC_FAILURE);
goto err;
}
pmod->links++;
return ret;
err:
if (pmod->finish && init_called)
pmod->finish(imod);
memerr:
if (imod)
{
if (imod->name)
OPENSSL_free(imod->name);
if (imod->value)
OPENSSL_free(imod->value);
OPENSSL_free(imod);
}
return -1;
}
void CONF_modules_unload(int all)
{
int i;
CONF_MODULE *md;
CONF_modules_finish();
for (i = sk_CONF_MODULE_num(supported_modules) - 1; i >= 0; i--)
{
md = sk_CONF_MODULE_value(supported_modules, i);
if (((md->links > 0) || !md->dso) && !all)
continue;
sk_CONF_MODULE_delete(supported_modules, i);
module_free(md);
}
if (sk_CONF_MODULE_num(supported_modules) == 0)
{
sk_CONF_MODULE_free(supported_modules);
supported_modules = NULL;
}
}
static void module_free(CONF_MODULE *md)
{
if (md->dso)
DSO_free(md->dso);
OPENSSL_free(md->name);
OPENSSL_free(md);
}
void CONF_modules_finish(void)
{
CONF_IMODULE *imod;
while (sk_CONF_IMODULE_num(initialized_modules) > 0)
{
imod = sk_CONF_IMODULE_pop(initialized_modules);
module_finish(imod);
}
sk_CONF_IMODULE_free(initialized_modules);
initialized_modules = NULL;
}
static void module_finish(CONF_IMODULE *imod)
{
if (imod->pmod->finish)
imod->pmod->finish(imod);
imod->pmod->links--;
OPENSSL_free(imod->name);
OPENSSL_free(imod->value);
OPENSSL_free(imod);
}
int CONF_module_add(const char *name, conf_init_func *ifunc,
conf_finish_func *ffunc)
{
if (module_add(NULL, name, ifunc, ffunc))
return 1;
else
return 0;
}
void CONF_modules_free(void)
{
CONF_modules_finish();
CONF_modules_unload(1);
}
const char *CONF_imodule_get_name(const CONF_IMODULE *md)
{
return md->name;
}
const char *CONF_imodule_get_value(const CONF_IMODULE *md)
{
return md->value;
}
void *CONF_imodule_get_usr_data(const CONF_IMODULE *md)
{
return md->usr_data;
}
void CONF_imodule_set_usr_data(CONF_IMODULE *md, void *usr_data)
{
md->usr_data = usr_data;
}
CONF_MODULE *CONF_imodule_get_module(const CONF_IMODULE *md)
{
return md->pmod;
}
unsigned long CONF_imodule_get_flags(const CONF_IMODULE *md)
{
return md->flags;
}
void CONF_imodule_set_flags(CONF_IMODULE *md, unsigned long flags)
{
md->flags = flags;
}
void *CONF_module_get_usr_data(CONF_MODULE *pmod)
{
return pmod->usr_data;
}
void CONF_module_set_usr_data(CONF_MODULE *pmod, void *usr_data)
{
pmod->usr_data = usr_data;
}
char *CONF_get1_default_config_file(void)
{
char *file;
int len;
file = getenv("OPENSSL_CONF");
if (file)
return BUF_strdup(file);
len = strlen(X509_get_default_cert_area());
#ifndef OPENSSL_SYS_VMS
len++;
#endif
len += strlen(OPENSSL_CONF);
file = OPENSSL_malloc(len + 1);
if (!file)
return NULL;
BUF_strlcpy(file,X509_get_default_cert_area(),len + 1);
#ifndef OPENSSL_SYS_VMS
BUF_strlcat(file,"/",len + 1);
#endif
BUF_strlcat(file,OPENSSL_CONF,len + 1);
return file;
}
int CONF_parse_list(const char *list_, int sep, int nospc,
int (*list_cb)(const char *elem, int len, void *usr), void *arg)
{
int ret;
const char *lstart, *tmpend, *p;
lstart = list_;
for(;;)
{
if (nospc)
{
while(*lstart && isspace((unsigned char)*lstart))
lstart++;
}
p = strchr(lstart, sep);
if (p == lstart || !*lstart)
ret = list_cb(NULL, 0, arg);
else
{
if (p)
tmpend = p - 1;
else
tmpend = lstart + strlen(lstart) - 1;
if (nospc)
{
while(isspace((unsigned char)*tmpend))
tmpend--;
}
ret = list_cb(lstart, tmpend - lstart + 1, arg);
}
if (ret <= 0)
return ret;
if (p == NULL)
return 1;
lstart = p + 1;
}
}
