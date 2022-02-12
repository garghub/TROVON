CONF_VALUE *_CONF_get_section(CONF *conf, char *section)
{
CONF_VALUE *v,vv;
if ((conf == NULL) || (section == NULL)) return(NULL);
vv.name=NULL;
vv.section=section;
v=(CONF_VALUE *)lh_retrieve(conf->data,&vv);
return(v);
}
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
v = (CONF_VALUE *)lh_insert(conf->data, value);
if (v != NULL)
{
sk_CONF_VALUE_delete_ptr(ts,v);
OPENSSL_free(v->name);
OPENSSL_free(v->value);
OPENSSL_free(v);
}
return 1;
}
char *_CONF_get_string(CONF *conf, char *section, char *name)
{
CONF_VALUE *v,vv;
char *p;
if (name == NULL) return(NULL);
if (conf != NULL)
{
if (section != NULL)
{
vv.name=name;
vv.section=section;
v=(CONF_VALUE *)lh_retrieve(conf->data,&vv);
if (v != NULL) return(v->value);
if (strcmp(section,"ENV") == 0)
{
p=Getenv(name);
if (p != NULL) return(p);
}
}
vv.section="default";
vv.name=name;
v=(CONF_VALUE *)lh_retrieve(conf->data,&vv);
if (v != NULL)
return(v->value);
else
return(NULL);
}
else
return(Getenv(name));
}
long _CONF_get_number(CONF *conf, char *section, char *name)
{
char *str;
long ret=0;
str=_CONF_get_string(conf,section,name);
if (str == NULL) return(0);
for (;;)
{
if (conf->meth->is_number(conf, *str))
ret=ret*10+conf->meth->to_int(conf, *str);
else
return(ret);
str++;
}
}
int _CONF_new_data(CONF *conf)
{
if (conf == NULL)
{
return 0;
}
if (conf->data == NULL)
if ((conf->data = lh_new(hash,cmp_conf)) == NULL)
{
return 0;
}
return 1;
}
void _CONF_free_data(CONF *conf)
{
if (conf == NULL || conf->data == NULL) return;
conf->data->down_load=0;
lh_doall_arg(conf->data,(void (*)())value_free_hash,conf->data);
lh_doall_arg(conf->data,(void (*)())value_free_stack,conf->data);
lh_free(conf->data);
}
static void value_free_hash(CONF_VALUE *a, LHASH *conf)
{
if (a->name != NULL)
{
a=(CONF_VALUE *)lh_delete(conf,a);
}
}
static void value_free_stack(CONF_VALUE *a, LHASH *conf)
{
CONF_VALUE *vv;
STACK *sk;
int i;
if (a->name != NULL) return;
sk=(STACK *)a->value;
for (i=sk_num(sk)-1; i>=0; i--)
{
vv=(CONF_VALUE *)sk_value(sk,i);
OPENSSL_free(vv->value);
OPENSSL_free(vv->name);
OPENSSL_free(vv);
}
if (sk != NULL) sk_free(sk);
OPENSSL_free(a->section);
OPENSSL_free(a);
}
static unsigned long hash(CONF_VALUE *v)
{
return((lh_strhash(v->section)<<2)^lh_strhash(v->name));
}
static int cmp_conf(CONF_VALUE *a, CONF_VALUE *b)
{
int i;
if (a->section != b->section)
{
i=strcmp(a->section,b->section);
if (i) return(i);
}
if ((a->name != NULL) && (b->name != NULL))
{
i=strcmp(a->name,b->name);
return(i);
}
else if (a->name == b->name)
return(0);
else
return((a->name == NULL)?-1:1);
}
CONF_VALUE *_CONF_new_section(CONF *conf, char *section)
{
STACK *sk=NULL;
int ok=0,i;
CONF_VALUE *v=NULL,*vv;
if ((sk=sk_new_null()) == NULL)
goto err;
if ((v=(CONF_VALUE *)OPENSSL_malloc(sizeof(CONF_VALUE))) == NULL)
goto err;
i=strlen(section)+1;
if ((v->section=(char *)OPENSSL_malloc(i)) == NULL)
goto err;
memcpy(v->section,section,i);
v->name=NULL;
v->value=(char *)sk;
vv=(CONF_VALUE *)lh_insert(conf->data,v);
assert(vv == NULL);
ok=1;
err:
if (!ok)
{
if (sk != NULL) sk_free(sk);
if (v != NULL) OPENSSL_free(v);
v=NULL;
}
return(v);
}
