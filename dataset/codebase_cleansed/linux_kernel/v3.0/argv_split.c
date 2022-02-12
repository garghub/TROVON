static const char *skip_arg(const char *cp)
{
while (*cp && !isspace(*cp))
cp++;
return cp;
}
static int count_argc(const char *str)
{
int count = 0;
while (*str) {
str = skip_spaces(str);
if (*str) {
count++;
str = skip_arg(str);
}
}
return count;
}
void argv_free(char **argv)
{
char **p;
for (p = argv; *p; p++)
kfree(*p);
kfree(argv);
}
char **argv_split(gfp_t gfp, const char *str, int *argcp)
{
int argc = count_argc(str);
char **argv = kzalloc(sizeof(*argv) * (argc+1), gfp);
char **argvp;
if (argv == NULL)
goto out;
if (argcp)
*argcp = argc;
argvp = argv;
while (*str) {
str = skip_spaces(str);
if (*str) {
const char *p = str;
char *t;
str = skip_arg(str);
t = kstrndup(p, str-p, gfp);
if (t == NULL)
goto fail;
*argvp++ = t;
}
}
*argvp = NULL;
out:
return argv;
fail:
argv_free(argv);
return NULL;
}
