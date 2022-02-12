const char *LP_find_file(LP_DIR_CTX **ctx, const char *directory)
{
if (ctx == NULL || directory == NULL) {
errno = EINVAL;
return 0;
}
errno = 0;
if (*ctx == NULL) {
size_t dirlen = strlen(directory);
if (dirlen == 0 || dirlen > INT_MAX - 3) {
errno = ENOENT;
return 0;
}
*ctx = malloc(sizeof(**ctx));
if (*ctx == NULL) {
errno = ENOMEM;
return 0;
}
memset(*ctx, 0, sizeof(**ctx));
if (sizeof(TCHAR) != sizeof(char)) {
TCHAR *wdir = NULL;
size_t index = 0, len_0 = dirlen + 1;
#ifdef LP_MULTIBYTE_AVAILABLE
int sz = 0;
UINT cp;
do {
# ifdef CP_UTF8
if ((sz = MultiByteToWideChar((cp = CP_UTF8), 0,
directory, len_0,
NULL, 0)) > 0 ||
GetLastError() != ERROR_NO_UNICODE_TRANSLATION)
break;
# endif
sz = MultiByteToWideChar((cp = CP_ACP), 0,
directory, len_0,
NULL, 0);
} while (0);
if (sz > 0) {
wdir = _alloca((sz + 2) * sizeof(TCHAR));
if (!MultiByteToWideChar(cp, 0, directory, len_0,
(WCHAR *)wdir, sz)) {
free(*ctx);
*ctx = NULL;
errno = EINVAL;
return 0;
}
} else
#endif
{
sz = len_0;
wdir = _alloca((sz + 2) * sizeof(TCHAR));
for (index = 0; index < len_0; index++)
wdir[index] = (TCHAR)directory[index];
}
sz--;
if (wdir[sz - 1] != TEXT('*')) {
if (wdir[sz - 1] != TEXT('/') && wdir[sz - 1] != TEXT('\\'))
_tcscpy(wdir + sz, TEXT("/*"));
else
_tcscpy(wdir + sz, TEXT("*"));
}
(*ctx)->handle = FindFirstFile(wdir, &(*ctx)->ctx);
} else {
if (directory[dirlen - 1] != '*') {
char *buf = _alloca(dirlen + 3);
strcpy(buf, directory);
if (buf[dirlen - 1] != '/' && buf[dirlen - 1] != '\\')
strcpy(buf + dirlen, "/*");
else
strcpy(buf + dirlen, "*");
directory = buf;
}
(*ctx)->handle = FindFirstFile((TCHAR *)directory, &(*ctx)->ctx);
}
if ((*ctx)->handle == INVALID_HANDLE_VALUE) {
free(*ctx);
*ctx = NULL;
errno = EINVAL;
return 0;
}
} else {
if (FindNextFile((*ctx)->handle, &(*ctx)->ctx) == FALSE) {
return 0;
}
}
if (sizeof(TCHAR) != sizeof(char)) {
TCHAR *wdir = (*ctx)->ctx.cFileName;
size_t index, len_0 = 0;
while (wdir[len_0] && len_0 < (sizeof((*ctx)->entry_name) - 1))
len_0++;
len_0++;
#ifdef LP_MULTIBYTE_AVAILABLE
if (!WideCharToMultiByte(CP_DEFAULT, 0, (WCHAR *)wdir, len_0,
(*ctx)->entry_name,
sizeof((*ctx)->entry_name), NULL, 0))
#endif
for (index = 0; index < len_0; index++)
(*ctx)->entry_name[index] = (char)wdir[index];
} else
strncpy((*ctx)->entry_name, (const char *)(*ctx)->ctx.cFileName,
sizeof((*ctx)->entry_name) - 1);
(*ctx)->entry_name[sizeof((*ctx)->entry_name) - 1] = '\0';
return (*ctx)->entry_name;
}
int LP_find_file_end(LP_DIR_CTX **ctx)
{
if (ctx != NULL && *ctx != NULL) {
FindClose((*ctx)->handle);
free(*ctx);
*ctx = NULL;
return 1;
}
errno = EINVAL;
return 0;
}
