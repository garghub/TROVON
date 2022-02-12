DSO_METHOD *DSO_METHOD_win32(void)
{
return NULL;
}
static FARPROC GetProcAddressA(HMODULE hModule,LPCSTR lpProcName)
{
WCHAR lpProcNameW[64];
int i;
for (i=0;lpProcName[i] && i<64;i++)
lpProcNameW[i] = (WCHAR)lpProcName[i];
if (i==64) return NULL;
lpProcNameW[i] = 0;
return GetProcAddressW(hModule,lpProcNameW);
}
DSO_METHOD *DSO_METHOD_win32(void)
{
return(&dso_meth_win32);
}
static int win32_load(DSO *dso)
{
HINSTANCE h = NULL, *p = NULL;
char *filename = DSO_convert_filename(dso, NULL);
if(filename == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_NO_FILENAME);
goto err;
}
h = LoadLibraryA(filename);
if(h == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_LOAD_FAILED);
ERR_add_error_data(3, "filename(", filename, ")");
goto err;
}
p = (HINSTANCE *)OPENSSL_malloc(sizeof(HINSTANCE));
if(p == NULL)
{
DSOerr(DSO_F_WIN32_LOAD,ERR_R_MALLOC_FAILURE);
goto err;
}
*p = h;
if(!sk_push(dso->meth_data, (char *)p))
{
DSOerr(DSO_F_WIN32_LOAD,DSO_R_STACK_ERROR);
goto err;
}
dso->loaded_filename = filename;
return(1);
err:
if(filename != NULL)
OPENSSL_free(filename);
if(p != NULL)
OPENSSL_free(p);
if(h != NULL)
FreeLibrary(h);
return(0);
}
static int win32_unload(DSO *dso)
{
HINSTANCE *p;
if(dso == NULL)
{
DSOerr(DSO_F_WIN32_UNLOAD,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if(sk_num(dso->meth_data) < 1)
return(1);
p = (HINSTANCE *)sk_pop(dso->meth_data);
if(p == NULL)
{
DSOerr(DSO_F_WIN32_UNLOAD,DSO_R_NULL_HANDLE);
return(0);
}
if(!FreeLibrary(*p))
{
DSOerr(DSO_F_WIN32_UNLOAD,DSO_R_UNLOAD_FAILED);
sk_push(dso->meth_data, (char *)p);
return(0);
}
OPENSSL_free(p);
return(1);
}
static void *win32_bind_var(DSO *dso, const char *symname)
{
HINSTANCE *ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_WIN32_BIND_VAR,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (HINSTANCE *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = GetProcAddress(*ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_WIN32_BIND_VAR,DSO_R_SYM_FAILURE);
ERR_add_error_data(3, "symname(", symname, ")");
return(NULL);
}
return(sym);
}
static DSO_FUNC_TYPE win32_bind_func(DSO *dso, const char *symname)
{
HINSTANCE *ptr;
void *sym;
if((dso == NULL) || (symname == NULL))
{
DSOerr(DSO_F_WIN32_BIND_FUNC,ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(sk_num(dso->meth_data) < 1)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_STACK_ERROR);
return(NULL);
}
ptr = (HINSTANCE *)sk_value(dso->meth_data, sk_num(dso->meth_data) - 1);
if(ptr == NULL)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_NULL_HANDLE);
return(NULL);
}
sym = GetProcAddress(*ptr, symname);
if(sym == NULL)
{
DSOerr(DSO_F_WIN32_BIND_FUNC,DSO_R_SYM_FAILURE);
ERR_add_error_data(3, "symname(", symname, ")");
return(NULL);
}
return((DSO_FUNC_TYPE)sym);
}
static struct file_st *win32_splitter(DSO *dso, const char *filename,
int assume_last_is_dir)
{
struct file_st *result = NULL;
enum { IN_NODE, IN_DEVICE, IN_FILE } position;
const char *start = filename;
if (!filename)
{
DSOerr(DSO_F_WIN32_SPLITTER,DSO_R_NO_FILENAME);
return(NULL);
}
result = OPENSSL_malloc(sizeof(struct file_st));
if(result == NULL)
{
DSOerr(DSO_F_WIN32_SPLITTER,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
memset(result, 0, sizeof(struct file_st));
position = IN_DEVICE;
if(filename[0] == '\\' && filename[1] == '\\'
|| filename[0] == '/' && filename[1] == '/')
{
position = IN_NODE;
filename += 2;
start = filename;
result->node = start;
}
do
{
switch(filename[0])
{
case ':':
if(position != IN_DEVICE)
{
DSOerr(DSO_F_WIN32_SPLITTER,
DSO_R_INCORRECT_FILE_SYNTAX);
return(NULL);
}
result->device = start;
result->devicelen = filename - start;
position = IN_FILE;
start = ++filename;
result->dir = start;
break;
case '\\':
case '/':
if(position == IN_NODE)
{
result->nodelen = filename - start;
position = IN_FILE;
start = ++filename;
result->dir = start;
}
else
{
filename++;
result->dirlen += filename - start;
}
break;
case '\0':
if(position == IN_NODE)
{
result->nodelen = filename - start;
}
else
{
if(filename - start > 0)
{
if (assume_last_is_dir)
{
result->devicelen += filename - start;
}
else
{
result->file = start;
result->filelen = filename - start;
}
}
}
break;
default:
filename++;
break;
}
}
while(*filename);
if(!result->nodelen) result->node = NULL;
if(!result->devicelen) result->device = NULL;
if(!result->dirlen) result->dir = NULL;
if(!result->filelen) result->file = NULL;
return(result);
}
static char *win32_joiner(DSO *dso, const struct file_st *file_split)
{
int len = 0, offset = 0;
char *result = NULL;
const char *start;
if(!file_split)
{
DSOerr(DSO_F_WIN32_JOINER,
ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if(file_split->node)
{
len += 2 + file_split->nodelen;
if(file_split->predir || file_split->dir || file_split->file)
len++;
}
else if(file_split->device)
{
len += file_split->devicelen + 1;
}
len += file_split->predirlen;
if(file_split->predir && (file_split->dir || file_split->file))
{
len++;
}
len += file_split->dirlen;
if(file_split->dir && file_split->file)
{
len++;
}
len += file_split->filelen;
if(!len)
{
DSOerr(DSO_F_WIN32_JOINER, DSO_R_EMPTY_FILE_STRUCTURE);
return(NULL);
}
result = OPENSSL_malloc(len + 1);
if (!result)
{
DSOerr(DSO_F_WIN32_JOINER,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
if(file_split->node)
{
strcpy(&result[offset], "\\\\"); offset += 2;
strncpy(&result[offset], file_split->node,
file_split->nodelen); offset += file_split->nodelen;
if(file_split->predir || file_split->dir || file_split->file)
{
result[offset] = '\\'; offset++;
}
}
else if(file_split->device)
{
strncpy(&result[offset], file_split->device,
file_split->devicelen); offset += file_split->devicelen;
result[offset] = ':'; offset++;
}
start = file_split->predir;
while(file_split->predirlen > (start - file_split->predir))
{
const char *end = openssl_strnchr(start, '/',
file_split->predirlen - (start - file_split->predir));
if(!end)
end = start
+ file_split->predirlen
- (start - file_split->predir);
strncpy(&result[offset], start,
end - start); offset += end - start;
result[offset] = '\\'; offset++;
start = end + 1;
}
if(file_split->predir && (file_split->dir || file_split->file))
{
result[offset] = '\\'; offset++;
}
start = file_split->dir;
while(file_split->dirlen > (start - file_split->dir))
{
const char *end = openssl_strnchr(start, '/',
file_split->dirlen - (start - file_split->dir));
if(!end)
end = start
+ file_split->dirlen
- (start - file_split->dir);
strncpy(&result[offset], start,
end - start); offset += end - start;
result[offset] = '\\'; offset++;
start = end + 1;
}
if(file_split->dir && file_split->file)
{
result[offset] = '\\'; offset++;
}
strncpy(&result[offset], file_split->file,
file_split->filelen); offset += file_split->filelen;
result[offset] = '\0';
return(result);
}
static char *win32_merger(DSO *dso, const char *filespec1, const char *filespec2)
{
char *merged = NULL;
struct file_st *filespec1_split = NULL;
struct file_st *filespec2_split = NULL;
if(!filespec1 && !filespec2)
{
DSOerr(DSO_F_WIN32_MERGER,
ERR_R_PASSED_NULL_PARAMETER);
return(NULL);
}
if (!filespec2)
{
merged = OPENSSL_malloc(strlen(filespec1) + 1);
if(!merged)
{
DSOerr(DSO_F_WIN32_MERGER,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
strcpy(merged, filespec1);
}
else if (!filespec1)
{
merged = OPENSSL_malloc(strlen(filespec2) + 1);
if(!merged)
{
DSOerr(DSO_F_WIN32_MERGER,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
strcpy(merged, filespec2);
}
else
{
filespec1_split = win32_splitter(dso, filespec1, 1);
if (!filespec1_split)
{
DSOerr(DSO_F_WIN32_MERGER,
ERR_R_MALLOC_FAILURE);
return(NULL);
}
filespec2_split = win32_splitter(dso, filespec2, 0);
if (!filespec1_split)
{
DSOerr(DSO_F_WIN32_MERGER,
ERR_R_MALLOC_FAILURE);
OPENSSL_free(filespec1_split);
return(NULL);
}
if (!filespec1_split->node && !filespec1_split->device)
{
filespec1_split->node = filespec2_split->node;
filespec1_split->nodelen = filespec2_split->nodelen;
filespec1_split->device = filespec2_split->device;
filespec1_split->devicelen = filespec2_split->devicelen;
}
if (!filespec1_split->dir)
{
filespec1_split->dir = filespec2_split->dir;
filespec1_split->dirlen = filespec2_split->dirlen;
}
else if (filespec1_split->dir[0] != '\\'
&& filespec1_split->dir[0] != '/')
{
filespec1_split->predir = filespec2_split->dir;
filespec1_split->predirlen = filespec2_split->dirlen;
}
if (!filespec1_split->file)
{
filespec1_split->file = filespec2_split->file;
filespec1_split->filelen = filespec2_split->filelen;
}
merged = win32_joiner(dso, filespec1_split);
}
return(merged);
}
static char *win32_name_converter(DSO *dso, const char *filename)
{
char *translated;
int len, transform;
len = strlen(filename);
transform = ((strstr(filename, "/") == NULL) &&
(strstr(filename, "\\") == NULL) &&
(strstr(filename, ":") == NULL));
if(transform)
translated = OPENSSL_malloc(len + 5);
else
translated = OPENSSL_malloc(len + 1);
if(translated == NULL)
{
DSOerr(DSO_F_WIN32_NAME_CONVERTER,
DSO_R_NAME_TRANSLATION_FAILED);
return(NULL);
}
if(transform)
sprintf(translated, "%s.dll", filename);
else
sprintf(translated, "%s", filename);
return(translated);
}
static const char *openssl_strnchr(const char *string, int c, size_t len)
{
size_t i;
const char *p;
for (i = 0, p = string; i < len && *p; i++, p++)
{
if (*p == c)
return p;
}
return NULL;
}
