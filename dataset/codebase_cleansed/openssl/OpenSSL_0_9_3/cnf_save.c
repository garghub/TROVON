main()
{
LHASH *conf;
long l;
conf=CONF_load(NULL,"../../apps/openssl.cnf",&l);
if (conf == NULL)
{
fprintf(stderr,"error loading config, line %ld\n",l);
exit(1);
}
lh_doall(conf,print_conf);
}
void print_conf(CONF_VALUE *cv)
{
int i;
CONF_VALUE *v;
char *section;
char *name;
char *value;
STACK *s;
if (cv->name != NULL) return;
printf("[ %s ]\n",cv->section);
s=(STACK *)cv->value;
for (i=0; i<sk_num(s); i++)
{
v=(CONF_VALUE *)sk_value(s,i);
section=(v->section == NULL)?"None":v->section;
name=(v->name == NULL)?"None":v->name;
value=(v->value == NULL)?"None":v->value;
printf("%s=%s\n",name,value);
}
printf("\n");
}
