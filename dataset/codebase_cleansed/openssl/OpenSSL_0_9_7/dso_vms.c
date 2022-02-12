DSO_METHOD *DSO_METHOD_vms(void)
{
return NULL;
}
DSO_METHOD *DSO_METHOD_vms(void)
{
return(&dso_meth_vms);
}
static int vms_load(DSO *dso)
{
void *ptr = NULL;
char *filename = DSO_convert_filename(dso, NULL);
DSO_VMS_INTERNAL *p;
const char *sp1, *sp2;
if(filename == NULL)
{
DSOerr(DSO_F_DLFCN_LOAD,DSO_R_NO_FILENAME);
goto err;
}
sp1 = strrchr(filename, ']');
sp2 = strrchr(filename, '>');
if (sp1 == NULL) sp1 = sp2;
if (sp2 != NULL && sp2 > sp1) sp1 = sp2;
if (sp1 == NULL) sp1 = strrchr(filename, ':');
if (sp1 == NULL)
sp1 = filename;
else
sp1++;
sp2 = strchr(sp1, '.');
if (sp2 == NULL) sp2 = strchr(sp1, ';');
if (sp2 == NULL) sp2 = sp1 + strlen(sp1);
if (sp2 - sp1 > FILENAME_MAX
|| (sp1 - filename) + strlen(sp2) > FILENAME_MAX)
{
DSOerr(DSO_F_VMS_LOAD,DSO_R_FILENAME_TOO_BIG);
goto err;
}
p = (DSO_VMS_INTERNAL *)OPENSSL_malloc(sizeof(DSO_VMS_INTERNAL));
if(p == NULL)
{
DSOerr(DSO_F_VMS_LOAD,ERR_R_MALLOC_FAILURE);
goto err;
}
strncpy(p->filename, sp1, sp2-sp1);
p->filename[sp2-sp1] = '\0';
strncpy(p->imagename, filename, sp1-filename);
p->imagename[sp1-filename] = '\0';
strcat(p->imagename, sp2);
p->filename_dsc.dsc$w_length = strlen(p->filename);
p->filename_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
p->filename_dsc.dsc$b_class = DSC$K_CLASS_S;
p->filename_dsc.dsc$a_pointer = p->filename;
p->imagename_dsc.dsc$w_length = strlen(p->imagename);
p->imagename_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
p->imagename_dsc.dsc$b_class = DSC$K_CLASS_S;
p->imagename_dsc.dsc$a_pointer = p->imagename;
if(!sk_push(dso->meth_data, (char *)p))
{
DSOerr(DSO_F_VMS_LOAD,DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return(1);
err:
if(p != NULL)
OPENSSL_free(p);
if(filename != NULL)
OPENSSL_free(filename);
return(0);
}
static int vms_unload(DSO *dso)
{
DSO_VMS_INTERNAL *p;
if(dso == NULL)
{
DSOerr(DSO_F_VMS_UNLOAD,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(sk_num(dso->meth_data) < 1)
return(1);
p = (DSO_VMS_INTERNAL *)sk_pop(dso->meth_data);
if(p == NULL)
{
DSOerr(DSO_F_VMS_UNLOAD,DSO_R_NULL_HANDLE);
return(0);
}
OPENSSL_free(p);
return(1);
}
static int do_find_symbol(DSO_VMS_INTERNAL *ptr,
struct dsc$descriptor_s *symname_dsc, void **sym,
unsigned long flags)
{
lib$establish(lib$sig_to_ret);
if(ptr->imagename_dsc.dsc$w_length)
return lib$find_image_symbol(&ptr->filename_dsc,
symname_dsc, sym,
&ptr->imagename_dsc, flags);
else
return lib$find_image_symbol(&ptr->filename_dsc,
symname_dsc, sym,
0, flags);
}
void vms_bind_sym(DSO *dso, const char *symname, void **sym)
{
DSO_VMS_INTERNAL *ptr;
int status;
#if 0
int flags = (1<<4);
#else
int flags = 0;
#endif
struct dsc$descriptor_s symname_dsc;
*sym = NULL;
symname_dsc.dsc$w_length = strlen(symname);
symname_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
symname_dsc.dsc$b_class = DSC$K_CLASS_S;
symname_dsc.dsc$a_pointer = (char *)symname;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_VMS_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return;
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_VMS_BIND_VAR,DSO_R_STACK_ERROR);
return;
}
ptr = (DSO_VMS_INTERNAL *)sk_value(dso->meth_data,
sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_VMS_BIND_VAR,DSO_R_NULL_HANDLE);
return;
}
if(dso->flags & DSO_FLAG_UPCASE_SYMBOL) flags = 0;
status = do_find_symbol(ptr, &symname_dsc, sym, flags);
if(!$VMS_STATUS_SUCCESS(status))
{
unsigned short length;
char errstring[257];
struct dsc$descriptor_s errstring_dsc;
errstring_dsc.dsc$w_length = sizeof(errstring);
errstring_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
errstring_dsc.dsc$b_class = DSC$K_CLASS_S;
errstring_dsc.dsc$a_pointer = errstring;
*sym = NULL;
status = sys$getmsg(status, &length, &errstring_dsc, 1, 0);
if (!$VMS_STATUS_SUCCESS(status))
lib$signal(status);
else
{
errstring[length] = '\0';
DSOerr(DSO_F_VMS_BIND_VAR,DSO_R_SYM_FAILURE);
if (ptr->imagename_dsc.dsc$w_length)
ERR_add_error_data(9,
"Symbol ", symname,
" in ", ptr->filename,
" (", ptr->imagename, ")",
": ", errstring);
else
ERR_add_error_data(6,
"Symbol ", symname,
" in ", ptr->filename,
": ", errstring);
}
return;
}
return;
}
static void *vms_bind_var(DSO *dso, const char *symname)
{
void *sym = 0;
vms_bind_sym(dso, symname, &sym);
return sym;
}
static DSO_FUNC_TYPE vms_bind_func(DSO *dso, const char *symname)
{
DSO_FUNC_TYPE sym = 0;
vms_bind_sym(dso, symname, (void **)&sym);
return sym;
}
static char *vms_name_converter(DSO *dso, const char *filename)
{
int len = strlen(filename);
char *not_translated = OPENSSL_malloc(len+1);
strcpy(not_translated,filename);
return(not_translated);
}
