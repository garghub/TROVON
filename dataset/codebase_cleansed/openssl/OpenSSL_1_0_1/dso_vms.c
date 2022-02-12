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
#if __INITIAL_POINTER_SIZE == 64
# define DSO_MALLOC _malloc32
# pragma pointer_size save
# pragma pointer_size 32
#else
# define DSO_MALLOC OPENSSL_malloc
#endif
DSO_VMS_INTERNAL *p = NULL;
#if __INITIAL_POINTER_SIZE == 64
# pragma pointer_size restore
#endif
const char *sp1, *sp2;
if(filename == NULL)
{
DSOerr(DSO_F_VMS_LOAD,DSO_R_NO_FILENAME);
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
p = DSO_MALLOC(sizeof(DSO_VMS_INTERNAL));
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
if(!sk_void_push(dso->meth_data, (char *)p))
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
if(sk_void_num(dso->meth_data) < 1)
return(1);
p = (DSO_VMS_INTERNAL *)sk_void_pop(dso->meth_data);
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
#if __INITIAL_POINTER_SIZE == 64
# define SYMNAME symname_32p
# pragma pointer_size save
# pragma pointer_size 32
char *symname_32p;
# pragma pointer_size restore
char symname_32[ NAMX_MAXRSS+ 1];
#else
# define SYMNAME ((char *) symname)
#endif
*sym = NULL;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_VMS_BIND_SYM,ERR_R_PASSED_NULL_PARAMETER);
return;
}
#if __INITIAL_POINTER_SIZE == 64
symname_32p = symname_32;
strcpy( symname_32p, symname);
#endif
symname_dsc.dsc$w_length = strlen(SYMNAME);
symname_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
symname_dsc.dsc$b_class = DSC$K_CLASS_S;
symname_dsc.dsc$a_pointer = SYMNAME;
if(sk_void_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_VMS_BIND_SYM,DSO_R_STACK_ERROR);
return;
}
ptr = (DSO_VMS_INTERNAL *)sk_void_value(dso->meth_data,
sk_void_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_VMS_BIND_SYM,DSO_R_NULL_HANDLE);
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
DSOerr(DSO_F_VMS_BIND_SYM,DSO_R_SYM_FAILURE);
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
static char *vms_merger(DSO *dso, const char *filespec1, const char *filespec2)
{
int status;
int filespec1len, filespec2len;
struct FAB fab;
struct NAMX_STRUCT nam;
char esa[ NAMX_MAXRSS+ 1];
char *merged;
#if __INITIAL_POINTER_SIZE == 64
# define FILESPEC1 filespec1_32p;
# define FILESPEC2 filespec2_32p;
# pragma pointer_size save
# pragma pointer_size 32
char *filespec1_32p;
char *filespec2_32p;
# pragma pointer_size restore
char filespec1_32[ NAMX_MAXRSS+ 1];
char filespec2_32[ NAMX_MAXRSS+ 1];
#else
# define FILESPEC1 ((char *) filespec1)
# define FILESPEC2 ((char *) filespec2)
#endif
if (!filespec1) filespec1 = "";
if (!filespec2) filespec2 = "";
filespec1len = strlen(filespec1);
filespec2len = strlen(filespec2);
#if __INITIAL_POINTER_SIZE == 64
filespec1_32p = filespec1_32;
filespec2_32p = filespec2_32;
strcpy( filespec1_32p, filespec1);
strcpy( filespec2_32p, filespec2);
#endif
fab = cc$rms_fab;
nam = CC_RMS_NAMX;
FAB_OR_NAML( fab, nam).FAB_OR_NAML_FNA = FILESPEC1;
FAB_OR_NAML( fab, nam).FAB_OR_NAML_FNS = filespec1len;
FAB_OR_NAML( fab, nam).FAB_OR_NAML_DNA = FILESPEC2;
FAB_OR_NAML( fab, nam).FAB_OR_NAML_DNS = filespec2len;
NAMX_DNA_FNA_SET( fab)
nam.NAMX_ESA = esa;
nam.NAMX_ESS = NAMX_MAXRSS;
nam.NAMX_NOP = NAM$M_SYNCHK | NAM$M_PWD;
SET_NAMX_NO_SHORT_UPCASE( nam);
fab.FAB_NAMX = &nam;
status = sys$parse(&fab, 0, 0);
if(!$VMS_STATUS_SUCCESS(status))
{
unsigned short length;
char errstring[257];
struct dsc$descriptor_s errstring_dsc;
errstring_dsc.dsc$w_length = sizeof(errstring);
errstring_dsc.dsc$b_dtype = DSC$K_DTYPE_T;
errstring_dsc.dsc$b_class = DSC$K_CLASS_S;
errstring_dsc.dsc$a_pointer = errstring;
status = sys$getmsg(status, &length, &errstring_dsc, 1, 0);
if (!$VMS_STATUS_SUCCESS(status))
lib$signal(status);
else
{
errstring[length] = '\0';
DSOerr(DSO_F_VMS_MERGER,DSO_R_FAILURE);
ERR_add_error_data(7,
"filespec \"", filespec1, "\", ",
"defaults \"", filespec2, "\": ",
errstring);
}
return(NULL);
}
merged = OPENSSL_malloc( nam.NAMX_ESL+ 1);
if(!merged)
goto malloc_err;
strncpy( merged, nam.NAMX_ESA, nam.NAMX_ESL);
merged[ nam.NAMX_ESL] = '\0';
return(merged);
malloc_err:
DSOerr(DSO_F_VMS_MERGER,
ERR_R_MALLOC_FAILURE);
}
static char *vms_name_converter(DSO *dso, const char *filename)
{
int len = strlen(filename);
char *not_translated = OPENSSL_malloc(len+1);
strcpy(not_translated,filename);
return(not_translated);
}
