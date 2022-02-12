gchar *
protect_arg (const gchar *argv)
{
gchar *new_arg;
const gchar *p = argv;
gchar *q;
gint len = 0;
gboolean need_dblquotes = FALSE;
while (*p) {
if (*p == ' ' || *p == '\t')
need_dblquotes = TRUE;
else if (*p == '"')
len++;
else if (*p == '\\') {
const gchar *pp = p;
while (*pp && *pp == '\\')
pp++;
if (*pp == '"')
len++;
}
len++;
p++;
}
q = new_arg = g_malloc (len + need_dblquotes*2 + 1);
p = argv;
if (need_dblquotes)
*q++ = '"';
while (*p) {
if (*p == '"')
*q++ = '\\';
else if (*p == '\\') {
const gchar *pp = p;
while (*pp && *pp == '\\')
pp++;
if (*pp == '"')
*q++ = '\\';
}
*q++ = *p;
p++;
}
if (need_dblquotes)
*q++ = '"';
*q++ = '\0';
return new_arg;
}
const char *
win32strerror(DWORD error)
{
static char errbuf[ERRBUF_SIZE+1];
size_t errlen;
char *p;
FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, error, 0, errbuf, ERRBUF_SIZE, NULL);
errlen = strlen(errbuf);
if (errlen >= 2) {
errbuf[errlen - 1] = '\0';
errbuf[errlen - 2] = '\0';
}
p = strchr(errbuf, '\0');
g_snprintf(p, (gulong)(sizeof errbuf - (p-errbuf)), " (%lu)", error);
return errbuf;
}
const char *
win32strexception(DWORD exception)
{
static char errbuf[ERRBUF_SIZE+1];
static const struct exception_msg {
int code;
char *msg;
} exceptions[] = {
{ EXCEPTION_ACCESS_VIOLATION, "Access violation" },
{ EXCEPTION_ARRAY_BOUNDS_EXCEEDED, "Array bounds exceeded" },
{ EXCEPTION_BREAKPOINT, "Breakpoint" },
{ EXCEPTION_DATATYPE_MISALIGNMENT, "Data type misalignment" },
{ EXCEPTION_FLT_DENORMAL_OPERAND, "Denormal floating-point operand" },
{ EXCEPTION_FLT_DIVIDE_BY_ZERO, "Floating-point divide by zero" },
{ EXCEPTION_FLT_INEXACT_RESULT, "Floating-point inexact result" },
{ EXCEPTION_FLT_INVALID_OPERATION, "Invalid floating-point operation" },
{ EXCEPTION_FLT_OVERFLOW, "Floating-point overflow" },
{ EXCEPTION_FLT_STACK_CHECK, "Floating-point stack check" },
{ EXCEPTION_FLT_UNDERFLOW, "Floating-point underflow" },
{ EXCEPTION_GUARD_PAGE, "Guard page violation" },
{ EXCEPTION_ILLEGAL_INSTRUCTION, "Illegal instruction" },
{ EXCEPTION_IN_PAGE_ERROR, "Page-in error" },
{ EXCEPTION_INT_DIVIDE_BY_ZERO, "Integer divide by zero" },
{ EXCEPTION_INT_OVERFLOW, "Integer overflow" },
{ EXCEPTION_INVALID_DISPOSITION, "Invalid disposition" },
{ EXCEPTION_INVALID_HANDLE, "Invalid handle" },
{ EXCEPTION_NONCONTINUABLE_EXCEPTION, "Non-continuable exception" },
{ EXCEPTION_PRIV_INSTRUCTION, "Privileged instruction" },
{ EXCEPTION_SINGLE_STEP, "Single-step complete" },
{ EXCEPTION_STACK_OVERFLOW, "Stack overflow" },
{ 0, NULL }
};
#define N_EXCEPTIONS (sizeof exceptions / sizeof exceptions[0])
int i;
for (i = 0; i < N_EXCEPTIONS; i++) {
if (exceptions[i].code == exception)
return exceptions[i].msg;
}
g_snprintf(errbuf, (gulong)sizeof errbuf, "Exception 0x%08x", exception);
return errbuf;
}
