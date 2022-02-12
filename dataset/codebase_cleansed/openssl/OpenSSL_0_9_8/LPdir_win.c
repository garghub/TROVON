const char *LP_find_file(LP_DIR_CTX **ctx, const char *directory)
{
struct dirent *direntry = NULL;
if (ctx == NULL || directory == NULL)
{
errno = EINVAL;
return 0;
}
errno = 0;
if (*ctx == NULL)
{
*ctx = (LP_DIR_CTX *)malloc(sizeof(LP_DIR_CTX));
if (*ctx == NULL)
{
errno = ENOMEM;
return 0;
}
memset(*ctx, '\0', sizeof(LP_DIR_CTX));
if (sizeof(TCHAR) != sizeof(char))
{
TCHAR *wdir = NULL;
size_t index = 0,len_0 = strlen(directory) + 1;
wdir = (TCHAR *)malloc(len_0 * sizeof(TCHAR));
if (wdir == NULL)
{
free(*ctx);
*ctx = NULL;
errno = ENOMEM;
return 0;
}
#ifdef LP_MULTIBYTE_AVAILABLE
if (!MultiByteToWideChar(CP_ACP, 0, directory, len_0, (WCHAR *)wdir, len_0))
#endif
for (index = 0; index < len_0; index++)
wdir[index] = (TCHAR)directory[index];
(*ctx)->handle = FindFirstFile(wdir, &(*ctx)->ctx);
free(wdir);
}
else
(*ctx)->handle = FindFirstFile((TCHAR *)directory, &(*ctx)->ctx);
if ((*ctx)->handle == INVALID_HANDLE_VALUE)
{
free(*ctx);
*ctx = NULL;
errno = EINVAL;
return 0;
}
}
else
{
if (FindNextFile((*ctx)->handle, &(*ctx)->ctx) == FALSE)
{
return 0;
}
}
if (sizeof(TCHAR) != sizeof(char))
{
TCHAR *wdir = (*ctx)->ctx.cFileName;
size_t index, len_0 = 0;
while (wdir[len_0] && len_0 < (sizeof((*ctx)->entry_name) - 1)) len_0++;
len_0++;
#ifdef LP_MULTIBYTE_AVAILABLE
if (!WideCharToMultiByte(CP_ACP, 0, (WCHAR *)wdir, len_0, (*ctx)->entry_name,
sizeof((*ctx)->entry_name), NULL, 0))
#endif
for (index = 0; index < len_0; index++)
(*ctx)->entry_name[index] = (char)wdir[index];
}
else
strncpy((*ctx)->entry_name, (const char *)(*ctx)->ctx.cFileName,
sizeof((*ctx)->entry_name)-1);
(*ctx)->entry_name[sizeof((*ctx)->entry_name)-1] = '\0';
return (*ctx)->entry_name;
}
int LP_find_file_end(LP_DIR_CTX **ctx)
{
if (ctx != NULL && *ctx != NULL)
{
FindClose((*ctx)->handle);
free(*ctx);
*ctx = NULL;
return 1;
}
errno = EINVAL;
return 0;
}
