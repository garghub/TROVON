static void
exchange (char **argv, struct _getopt_data *d)
{
int bottom = d->__first_nonopt;
int middle = d->__last_nonopt;
int top = d->optind;
char *tem;
#if defined _LIBC && defined USE_NONOPTION_FLAGS
if (d->__nonoption_flags_len > 0 && top >= d->__nonoption_flags_max_len)
{
char *new_str = malloc (top + 1);
if (new_str == NULL)
d->__nonoption_flags_len = d->__nonoption_flags_max_len = 0;
else
{
memset (__mempcpy (new_str, __getopt_nonoption_flags,
d->__nonoption_flags_max_len),
'\0', top + 1 - d->__nonoption_flags_max_len);
d->__nonoption_flags_max_len = top + 1;
__getopt_nonoption_flags = new_str;
}
}
#endif
while (top > middle && middle > bottom)
{
if (top - middle > middle - bottom)
{
int len = middle - bottom;
register int i;
for (i = 0; i < len; i++)
{
tem = argv[bottom + i];
argv[bottom + i] = argv[top - (middle - bottom) + i];
argv[top - (middle - bottom) + i] = tem;
SWAP_FLAGS (bottom + i, top - (middle - bottom) + i);
}
top -= len;
}
else
{
int len = top - middle;
register int i;
for (i = 0; i < len; i++)
{
tem = argv[bottom + i];
argv[bottom + i] = argv[middle + i];
argv[middle + i] = tem;
SWAP_FLAGS (bottom + i, middle + i);
}
bottom += len;
}
}
d->__first_nonopt += (d->optind - d->__last_nonopt);
d->__last_nonopt = d->optind;
}
static const char *
_getopt_initialize (int argc, char *const *argv, const char *optstring,
struct _getopt_data *d, int posixly_correct)
{
d->__first_nonopt = d->__last_nonopt = d->optind;
d->__nextchar = NULL;
d->__posixly_correct = posixly_correct | !!getenv ("POSIXLY_CORRECT");
if (optstring[0] == '-')
{
d->__ordering = RETURN_IN_ORDER;
++optstring;
}
else if (optstring[0] == '+')
{
d->__ordering = REQUIRE_ORDER;
++optstring;
}
else if (d->__posixly_correct)
d->__ordering = REQUIRE_ORDER;
else
d->__ordering = PERMUTE;
#if defined _LIBC && defined USE_NONOPTION_FLAGS
if (!d->__posixly_correct
&& argc == __libc_argc && argv == __libc_argv)
{
if (d->__nonoption_flags_max_len == 0)
{
if (__getopt_nonoption_flags == NULL
|| __getopt_nonoption_flags[0] == '\0')
d->__nonoption_flags_max_len = -1;
else
{
const char *orig_str = __getopt_nonoption_flags;
int len = d->__nonoption_flags_max_len = strlen (orig_str);
if (d->__nonoption_flags_max_len < argc)
d->__nonoption_flags_max_len = argc;
__getopt_nonoption_flags =
(char *) malloc (d->__nonoption_flags_max_len);
if (__getopt_nonoption_flags == NULL)
d->__nonoption_flags_max_len = -1;
else
memset (__mempcpy (__getopt_nonoption_flags, orig_str, len),
'\0', d->__nonoption_flags_max_len - len);
}
}
d->__nonoption_flags_len = d->__nonoption_flags_max_len;
}
else
d->__nonoption_flags_len = 0;
#endif
return optstring;
}
int
_getopt_internal_r (int argc, char *const *argv, const char *optstring,
const struct option *longopts, int *longind,
int long_only, struct _getopt_data *d, int posixly_correct)
{
int print_errors = d->opterr;
if (argc < 1)
return -1;
d->optarg = NULL;
if (d->optind == 0 || !d->__initialized)
{
if (d->optind == 0)
d->optind = 1;
optstring = _getopt_initialize (argc, argv, optstring, d,
posixly_correct);
d->__initialized = 1;
}
else if (optstring[0] == '-' || optstring[0] == '+')
optstring++;
if (optstring[0] == ':')
print_errors = 0;
#if defined _LIBC && defined USE_NONOPTION_FLAGS
# define NONOPTION_P (argv[d->optind][0] != '-' || argv[d->optind][1] == '\0' \
|| (d->optind < d->__nonoption_flags_len \
&& __getopt_nonoption_flags[d->optind] == '1'))
#else
# define NONOPTION_P (argv[d->optind][0] != '-' || argv[d->optind][1] == '\0')
#endif
if (d->__nextchar == NULL || *d->__nextchar == '\0')
{
if (d->__last_nonopt > d->optind)
d->__last_nonopt = d->optind;
if (d->__first_nonopt > d->optind)
d->__first_nonopt = d->optind;
if (d->__ordering == PERMUTE)
{
if (d->__first_nonopt != d->__last_nonopt
&& d->__last_nonopt != d->optind)
exchange ((char **) argv, d);
else if (d->__last_nonopt != d->optind)
d->__first_nonopt = d->optind;
while (d->optind < argc && NONOPTION_P)
d->optind++;
d->__last_nonopt = d->optind;
}
if (d->optind != argc && !strcmp (argv[d->optind], "--"))
{
d->optind++;
if (d->__first_nonopt != d->__last_nonopt
&& d->__last_nonopt != d->optind)
exchange ((char **) argv, d);
else if (d->__first_nonopt == d->__last_nonopt)
d->__first_nonopt = d->optind;
d->__last_nonopt = argc;
d->optind = argc;
}
if (d->optind == argc)
{
if (d->__first_nonopt != d->__last_nonopt)
d->optind = d->__first_nonopt;
return -1;
}
if (NONOPTION_P)
{
if (d->__ordering == REQUIRE_ORDER)
return -1;
d->optarg = argv[d->optind++];
return 1;
}
d->__nextchar = (argv[d->optind] + 1
+ (longopts != NULL && argv[d->optind][1] == '-'));
}
if (longopts != NULL
&& (argv[d->optind][1] == '-'
|| (long_only && (argv[d->optind][2]
|| !strchr (optstring, argv[d->optind][1])))))
{
char *nameend;
size_t namelen;
const struct option *p;
const struct option *pfound = NULL;
struct option_list
{
const struct option *p;
struct option_list *next;
} *ambig_list = NULL;
int exact = 0;
int indfound = -1;
int option_index;
for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
;
namelen = nameend - d->__nextchar;
for (p = longopts, option_index = 0; p->name; p++, option_index++)
if (!strncmp (p->name, d->__nextchar, namelen))
{
if (namelen == (unsigned int) strlen (p->name))
{
pfound = p;
indfound = option_index;
exact = 1;
break;
}
else if (pfound == NULL)
{
pfound = p;
indfound = option_index;
}
else if (long_only
|| pfound->has_arg != p->has_arg
|| pfound->flag != p->flag
|| pfound->val != p->val)
{
struct option_list *newp = alloca (sizeof (*newp));
newp->p = p;
newp->next = ambig_list;
ambig_list = newp;
}
}
if (ambig_list != NULL && !exact)
{
if (print_errors)
{
struct option_list first;
first.p = pfound;
first.next = ambig_list;
ambig_list = &first;
#if defined _LIBC
char *buf = NULL;
size_t buflen = 0;
FILE *fp = open_memstream (&buf, &buflen);
if (fp != NULL)
{
fprintf (fp,
_("%s: option '%s' is ambiguous; possibilities:"),
argv[0], argv[d->optind]);
do
{
fprintf (fp, " '--%s'", ambig_list->p->name);
ambig_list = ambig_list->next;
}
while (ambig_list != NULL);
fputc_unlocked ('\n', fp);
if (__builtin_expect (fclose (fp) != EOF, 1))
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
}
#else
fprintf (stderr,
_("%s: option '%s' is ambiguous; possibilities:"),
argv[0], argv[d->optind]);
do
{
fprintf (stderr, " '--%s'", ambig_list->p->name);
ambig_list = ambig_list->next;
}
while (ambig_list != NULL);
fputc ('\n', stderr);
#endif
}
d->__nextchar += strlen (d->__nextchar);
d->optind++;
d->optopt = 0;
return '?';
}
if (pfound != NULL)
{
option_index = indfound;
d->optind++;
if (*nameend)
{
if (pfound->has_arg)
d->optarg = nameend + 1;
else
{
if (print_errors)
{
#if defined _LIBC
char *buf;
int n;
#endif
if (argv[d->optind - 1][1] == '-')
{
#if defined _LIBC
n = __asprintf (&buf, _("\
%s: option '--%s' doesn't allow an argument\n"),
argv[0], pfound->name);
#else
fprintf (stderr, _("\
%s: option '--%s' doesn't allow an argument\n"),
argv[0], pfound->name);
#endif
}
else
{
#if defined _LIBC
n = __asprintf (&buf, _("\
%s: option '%c%s' doesn't allow an argument\n"),
argv[0], argv[d->optind - 1][0],
pfound->name);
#else
fprintf (stderr, _("\
%s: option '%c%s' doesn't allow an argument\n"),
argv[0], argv[d->optind - 1][0],
pfound->name);
#endif
}
#if defined _LIBC
if (n >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2
|= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#endif
}
d->__nextchar += strlen (d->__nextchar);
d->optopt = pfound->val;
return '?';
}
}
else if (pfound->has_arg == 1)
{
if (d->optind < argc)
d->optarg = argv[d->optind++];
else
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf, _("\
%s: option '--%s' requires an argument\n"),
argv[0], pfound->name) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2
|= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr,
_("%s: option '--%s' requires an argument\n"),
argv[0], pfound->name);
#endif
}
d->__nextchar += strlen (d->__nextchar);
d->optopt = pfound->val;
return optstring[0] == ':' ? ':' : '?';
}
}
d->__nextchar += strlen (d->__nextchar);
if (longind != NULL)
*longind = option_index;
if (pfound->flag)
{
*(pfound->flag) = pfound->val;
return 0;
}
return pfound->val;
}
if (!long_only || argv[d->optind][1] == '-'
|| strchr (optstring, *d->__nextchar) == NULL)
{
if (print_errors)
{
#if defined _LIBC
char *buf;
int n;
#endif
if (argv[d->optind][1] == '-')
{
#if defined _LIBC
n = __asprintf (&buf, _("%s: unrecognized option '--%s'\n"),
argv[0], d->__nextchar);
#else
fprintf (stderr, _("%s: unrecognized option '--%s'\n"),
argv[0], d->__nextchar);
#endif
}
else
{
#if defined _LIBC
n = __asprintf (&buf, _("%s: unrecognized option '%c%s'\n"),
argv[0], argv[d->optind][0], d->__nextchar);
#else
fprintf (stderr, _("%s: unrecognized option '%c%s'\n"),
argv[0], argv[d->optind][0], d->__nextchar);
#endif
}
#if defined _LIBC
if (n >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#endif
}
d->__nextchar = (char *) "";
d->optind++;
d->optopt = 0;
return '?';
}
}
{
char c = *d->__nextchar++;
char *temp = strchr (optstring, c);
char *nameend;
const struct option *p;
const struct option *pfound = NULL;
int exact = 0;
int ambig = 0;
int indfound = 0;
int option_index;
if (*d->__nextchar == '\0')
++d->optind;
if (temp == NULL || c == ':' || c == ';')
{
if (print_errors)
{
#if defined _LIBC
char *buf;
int n;
#endif
#if defined _LIBC
n = __asprintf (&buf, _("%s: invalid option -- '%c'\n"),
argv[0], c);
#else
fprintf (stderr, _("%s: invalid option -- '%c'\n"), argv[0], c);
#endif
#if defined _LIBC
if (n >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#endif
}
d->optopt = c;
return '?';
}
if (temp[0] == 'W' && temp[1] == ';')
{
if (longopts == NULL)
goto no_longs;
if (*d->__nextchar != '\0')
{
d->optarg = d->__nextchar;
d->optind++;
}
else if (d->optind == argc)
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf,
_("%s: option requires an argument -- '%c'\n"),
argv[0], c) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr,
_("%s: option requires an argument -- '%c'\n"),
argv[0], c);
#endif
}
d->optopt = c;
if (optstring[0] == ':')
c = ':';
else
c = '?';
return c;
}
else
d->optarg = argv[d->optind++];
for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
nameend++)
;
for (p = longopts, option_index = 0; p->name; p++, option_index++)
if (!strncmp (p->name, d->__nextchar, nameend - d->__nextchar))
{
if ((unsigned int) (nameend - d->__nextchar) == strlen (p->name))
{
pfound = p;
indfound = option_index;
exact = 1;
break;
}
else if (pfound == NULL)
{
pfound = p;
indfound = option_index;
}
else if (long_only
|| pfound->has_arg != p->has_arg
|| pfound->flag != p->flag
|| pfound->val != p->val)
ambig = 1;
}
if (ambig && !exact)
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf, _("%s: option '-W %s' is ambiguous\n"),
argv[0], d->optarg) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr, _("%s: option '-W %s' is ambiguous\n"),
argv[0], d->optarg);
#endif
}
d->__nextchar += strlen (d->__nextchar);
d->optind++;
return '?';
}
if (pfound != NULL)
{
option_index = indfound;
if (*nameend)
{
if (pfound->has_arg)
d->optarg = nameend + 1;
else
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf, _("\
%s: option '-W %s' doesn't allow an argument\n"),
argv[0], pfound->name) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2
|= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr, _("\
%s: option '-W %s' doesn't allow an argument\n"),
argv[0], pfound->name);
#endif
}
d->__nextchar += strlen (d->__nextchar);
return '?';
}
}
else if (pfound->has_arg == 1)
{
if (d->optind < argc)
d->optarg = argv[d->optind++];
else
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf, _("\
%s: option '-W %s' requires an argument\n"),
argv[0], pfound->name) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2
|= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr, _("\
%s: option '-W %s' requires an argument\n"),
argv[0], pfound->name);
#endif
}
d->__nextchar += strlen (d->__nextchar);
return optstring[0] == ':' ? ':' : '?';
}
}
else
d->optarg = NULL;
d->__nextchar += strlen (d->__nextchar);
if (longind != NULL)
*longind = option_index;
if (pfound->flag)
{
*(pfound->flag) = pfound->val;
return 0;
}
return pfound->val;
}
no_longs:
d->__nextchar = NULL;
return 'W';
}
if (temp[1] == ':')
{
if (temp[2] == ':')
{
if (*d->__nextchar != '\0')
{
d->optarg = d->__nextchar;
d->optind++;
}
else
d->optarg = NULL;
d->__nextchar = NULL;
}
else
{
if (*d->__nextchar != '\0')
{
d->optarg = d->__nextchar;
d->optind++;
}
else if (d->optind == argc)
{
if (print_errors)
{
#if defined _LIBC
char *buf;
if (__asprintf (&buf, _("\
%s: option requires an argument -- '%c'\n"),
argv[0], c) >= 0)
{
_IO_flockfile (stderr);
int old_flags2 = ((_IO_FILE *) stderr)->_flags2;
((_IO_FILE *) stderr)->_flags2 |= _IO_FLAGS2_NOTCANCEL;
__fxprintf (NULL, "%s", buf);
((_IO_FILE *) stderr)->_flags2 = old_flags2;
_IO_funlockfile (stderr);
free (buf);
}
#else
fprintf (stderr,
_("%s: option requires an argument -- '%c'\n"),
argv[0], c);
#endif
}
d->optopt = c;
if (optstring[0] == ':')
c = ':';
else
c = '?';
}
else
d->optarg = argv[d->optind++];
d->__nextchar = NULL;
}
}
return c;
}
}
int
_getopt_internal (int argc, char *const *argv, const char *optstring,
const struct option *longopts, int *longind, int long_only,
int posixly_correct)
{
int result;
getopt_data.optind = optind;
getopt_data.opterr = opterr;
result = _getopt_internal_r (argc, argv, optstring, longopts,
longind, long_only, &getopt_data,
posixly_correct);
optind = getopt_data.optind;
optarg = getopt_data.optarg;
optopt = getopt_data.optopt;
return result;
}
int
getopt (int argc, char *const *argv, const char *optstring)
{
return _getopt_internal (argc, argv, optstring,
(const struct option *) 0,
(int *) 0,
0, 0);
}
int
getopt_long (int argc, char *const *argv, const char *options,
const struct option *long_options, int *opt_index)
{
return _getopt_internal (argc, argv, options, long_options,
opt_index, 0, 0);
}
int
__posix_getopt (int argc, char *const *argv, const char *optstring)
{
return _getopt_internal (argc, argv, optstring,
(const struct option *) 0,
(int *) 0,
0, 1);
}
int
main (int argc, char **argv)
{
int c;
int digit_optind = 0;
while (1)
{
int this_option_optind = optind ? optind : 1;
c = getopt (argc, argv, "abc:d:0123456789");
if (c == -1)
break;
switch (c)
{
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
if (digit_optind != 0 && digit_optind != this_option_optind)
printf ("digits occur in two different argv-elements.\n");
digit_optind = this_option_optind;
printf ("option %c\n", c);
break;
case 'a':
printf ("option a\n");
break;
case 'b':
printf ("option b\n");
break;
case 'c':
printf ("option c with value '%s'\n", optarg);
break;
case '?':
break;
default:
printf ("?? getopt returned character code 0%o ??\n", c);
}
}
if (optind < argc)
{
printf ("non-option ARGV-elements: ");
while (optind < argc)
printf ("%s ", argv[optind++]);
printf ("\n");
}
exit (0);
}
