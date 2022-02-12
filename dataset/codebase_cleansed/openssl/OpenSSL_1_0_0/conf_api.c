int _CONF_add_string(CONF *conf, CONF_VALUE *section, CONF_VALUE *value)
{
CONF_VALUE *v = NULL;
STACK_OF(CONF_VALUE) *ts;
ts = (STACK_OF(CONF_VALUE) *)section->value;
value->section=section->section;
if (!sk_CONF_VALUE_push(ts,value))
{
return 0;
}
v = lh_CONF_VALUE_insert(conf->data, value);
if (v != NULL)
{
(void)sk_CONF_VALUE_delete_ptr(ts,v);
OPENSSL_free(v->name);
OPENSSL_free(v->value);
OPENSSL_free(v);
}
return 1;
}
char *_CONF_get_string(const CONF *conf, const char *section, const char *name)
{
CONF_VALUE *v,vv;
char *p;
if (name == NULL) return(NULL);
if (conf != NULL)
{
if (section != NULL)
{
vv.name=(char *)name;
vv.section=(char *)section;
v=lh_CONF_VALUE_retrieve(conf->data,&vv);
if (v != NULL) return(v->value);
if (strcmp(section,"ENV") == 0)
{
p=getenv(name);
if (p != NULL) return(p);
}
}
vv.section="default";
vv.name=(char *)name;
v=lh_CONF_VALUE_retrieve(conf->data,&vv);
if (v != NULL)
return(v->value);
else
return(NULL);
}
else
return(getenv(name));
}
static unsigned long conf_value_hash(const CONF_VALUE *v)
{
return (lh_strhash(v->section)<<2)^lh_strhash(v->name);
}
int _CONF_new_data(CONF *conf)
{
if (conf == NULL)
{
return 0;
}
if (conf->data == NULL)
if ((conf->data = lh_CONF_VALUE_new()) == NULL)
{
return 0;
}
return 1;
}
void _CONF_free_data(CONF *conf)
{
if (conf == NULL || conf->data == NULL) return;
lh_CONF_VALUE_down_load(conf->data)=0;
lh_CONF_VALUE_doall_arg(conf->data,
LHASH_DOALL_ARG_FN(value_free_hash),
LHASH_OF(CONF_VALUE), conf->data);
lh_CONF_VALUE_doall(conf->data, LHASH_DOALL_FN(value_free_stack));
lh_CONF_VALUE_free(conf->data);
}
static void value_free_stack_doall(CONF_VALUE *a)
{
CONF_VALUE *vv;
STACK_OF(CONF_VALUE) *sk;
int i;
if (a->name != NULL) return;
sk=(STACK_OF(CONF_VALUE) *)a->value;
for (i=sk_CONF_VALUE_num(sk)-1; i>=0; i--)
{
vv=sk_CONF_VALUE_value(sk,i);
OPENSSL_free(vv->value);
OPENSSL_free(vv->name);
OPENSSL_free(vv);
}
if (sk != NULL) sk_CONF_VALUE_free(sk);
OPENSSL_free(a->section);
OPENSSL_free(a);
}
CONF_VALUE *_CONF_new_section(CONF *conf, const char *section)
{
STACK_OF(CONF_VALUE) *sk=NULL;
int ok=0,i;
CONF_VALUE *v=NULL,*vv;
if ((sk=sk_CONF_VALUE_new_null()) == NULL)
goto err;
if ((v=OPENSSL_malloc(sizeof(CONF_VALUE))) == NULL)
goto err;
i=strlen(section)+1;
if ((v->section=OPENSSL_malloc(i)) == NULL)
goto err;
memcpy(v->section,section,i);
v->name=NULL;
v->value=(char *)sk;
vv=lh_CONF_VALUE_insert(conf->data,v);
assert(vv == NULL);
ok=1;
err:
if (!ok)
{
if (sk != NULL) sk_CONF_VALUE_free(sk);
if (v != NULL) OPENSSL_free(v);
v=NULL;
}
return(v);
}
