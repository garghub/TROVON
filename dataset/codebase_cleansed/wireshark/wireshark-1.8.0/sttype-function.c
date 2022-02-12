static gpointer
function_new(gpointer funcdef)
{
function_t *stfuncrec;
g_assert(funcdef != NULL);
stfuncrec = g_new(function_t, 1);
stfuncrec->magic = FUNCTION_MAGIC;
stfuncrec->funcdef = (df_func_def_t *)funcdef;
stfuncrec->params = NULL;
return (gpointer) stfuncrec;
}
static void
slist_stnode_free(gpointer data, gpointer user_data _U_)
{
stnode_free((stnode_t *)data);
}
void
st_funcparams_free(GSList *params)
{
g_slist_foreach(params, slist_stnode_free, NULL);
g_slist_free(params);
}
static void
function_free(gpointer value)
{
function_t *stfuncrec = (function_t*)value;
assert_magic(stfuncrec, FUNCTION_MAGIC);
st_funcparams_free(stfuncrec->params);
g_free(stfuncrec);
}
void
sttype_function_set_params(stnode_t *node, GSList *params)
{
function_t *stfuncrec;
stfuncrec = (function_t*)stnode_data(node);
assert_magic(stfuncrec, FUNCTION_MAGIC);
stfuncrec->params = params;
}
df_func_def_t*
sttype_function_funcdef(stnode_t *node)
{
function_t *stfuncrec;
stfuncrec = (function_t*)stnode_data(node);
assert_magic(stfuncrec, FUNCTION_MAGIC);
return stfuncrec->funcdef;
}
GSList*
sttype_function_params(stnode_t *node)
{
function_t *stfuncrec;
stfuncrec = (function_t*)stnode_data(node);
assert_magic(stfuncrec, FUNCTION_MAGIC);
return stfuncrec->params;
}
void
sttype_register_function(void)
{
static sttype_t function_type = {
STTYPE_FUNCTION,
"FUNCTION",
function_new,
function_free,
};
sttype_register(&function_type);
}
