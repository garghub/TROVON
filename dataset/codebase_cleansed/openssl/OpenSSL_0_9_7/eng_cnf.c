static char *skip_dot(char *name)
{
char *p;
p = strchr(name, '.');
if (p)
return p + 1;
return name;
}
static int int_engine_init(ENGINE *e)
{
if (!ENGINE_init(e))
return 0;
if (!initialized_engines)
initialized_engines = sk_ENGINE_new_null();
if (!initialized_engines || !sk_ENGINE_push(initialized_engines, e))
{
ENGINE_finish(e);
return 0;
}
return 1;
}
static int int_engine_configure(char *name, char *value, const CONF *cnf)
{
int i;
int ret = 0;
long do_init = -1;
STACK_OF(CONF_VALUE) *ecmds;
CONF_VALUE *ecmd;
char *ctrlname, *ctrlvalue;
ENGINE *e = NULL;
name = skip_dot(name);
#ifdef ENGINE_CONF_DEBUG
fprintf(stderr, "Configuring engine %s\n", name);
#endif
ecmds = NCONF_get_section(cnf, value);
if (!ecmds)
{
ENGINEerr(ENGINE_F_INT_ENGINE_CONFIGURE, ENGINE_R_ENGINE_SECTION_ERROR);
return 0;
}
for (i = 0; i < sk_CONF_VALUE_num(ecmds); i++)
{
ecmd = sk_CONF_VALUE_value(ecmds, i);
ctrlname = skip_dot(ecmd->name);
ctrlvalue = ecmd->value;
#ifdef ENGINE_CONF_DEBUG
fprintf(stderr, "ENGINE conf: doing ctrl(%s,%s)\n", ctrlname, ctrlvalue);
#endif
if (!strcmp(ctrlname, "engine_id"))
name = ctrlvalue;
else if (!strcmp(ctrlname, "dynamic_path"))
{
e = ENGINE_by_id("dynamic");
if (!e)
goto err;
if (!ENGINE_ctrl_cmd_string(e, "SO_PATH", ctrlvalue, 0))
goto err;
if (!ENGINE_ctrl_cmd_string(e, "LIST_ADD", "2", 0))
goto err;
if (!ENGINE_ctrl_cmd_string(e, "LOAD", NULL, 0))
goto err;
}
else
{
if (!e)
{
e = ENGINE_by_id(name);
if (!e)
return 0;
}
if (!strcmp(ctrlvalue, "EMPTY"))
ctrlvalue = NULL;
else if (!strcmp(ctrlname, "init"))
{
if (!NCONF_get_number_e(cnf, value, "init", &do_init))
goto err;
if (do_init == 1)
{
if (!int_engine_init(e))
goto err;
}
else if (do_init != 0)
{
ENGINEerr(ENGINE_F_INT_ENGINE_CONFIGURE, ENGINE_R_INVALID_INIT_VALUE);
goto err;
}
}
else if (!strcmp(ctrlname, "default_algorithms"))
{
if (!ENGINE_set_default_string(e, ctrlvalue))
goto err;
}
else if (!ENGINE_ctrl_cmd_string(e,
ctrlname, ctrlvalue, 0))
return 0;
}
}
if (e && (do_init == -1) && !int_engine_init(e))
goto err;
ret = 1;
err:
if (e)
ENGINE_free(e);
return ret;
}
static int int_engine_module_init(CONF_IMODULE *md, const CONF *cnf)
{
STACK_OF(CONF_VALUE) *elist;
CONF_VALUE *cval;
int i;
#ifdef ENGINE_CONF_DEBUG
fprintf(stderr, "Called engine module: name %s, value %s\n",
CONF_imodule_get_name(md), CONF_imodule_get_value(md));
#endif
elist = NCONF_get_section(cnf, CONF_imodule_get_value(md));
if (!elist)
{
ENGINEerr(ENGINE_F_ENGINE_MODULE_INIT, ENGINE_R_ENGINES_SECTION_ERROR);
return 0;
}
for (i = 0; i < sk_CONF_VALUE_num(elist); i++)
{
cval = sk_CONF_VALUE_value(elist, i);
if (!int_engine_configure(cval->name, cval->value, cnf))
return 0;
}
return 1;
}
static void int_engine_module_finish(CONF_IMODULE *md)
{
ENGINE *e;
while ((e = sk_ENGINE_pop(initialized_engines)))
ENGINE_finish(e);
sk_ENGINE_free(initialized_engines);
initialized_engines = NULL;
}
void ENGINE_add_conf_module(void)
{
CONF_module_add("engines",
int_engine_module_init,
int_engine_module_finish);
}
