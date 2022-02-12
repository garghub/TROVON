static int count_argc(const char *str)
{
int count = 0;
bool was_space;
for (was_space = true; *str; str++) {
if (isspace(*str)) {
was_space = true;
} else if (was_space) {
was_space = false;
count++;
}
}
return count;
}
void argv_free(char **argv)
{
argv--;
kfree(argv[0]);
kfree(argv);
}
char **argv_split(gfp_t gfp, const char *str, int *argcp)
{
char *argv_str;
bool was_space;
char **argv, **argv_ret;
int argc;
argv_str = kstrndup(str, KMALLOC_MAX_SIZE - 1, gfp);
if (!argv_str)
return NULL;
argc = count_argc(argv_str);
argv = kmalloc(sizeof(*argv) * (argc + 2), gfp);
if (!argv) {
kfree(argv_str);
return NULL;
}
*argv = argv_str;
argv_ret = ++argv;
for (was_space = true; *argv_str; argv_str++) {
if (isspace(*argv_str)) {
was_space = true;
*argv_str = 0;
} else if (was_space) {
was_space = false;
*argv++ = argv_str;
}
}
*argv = NULL;
if (argcp)
*argcp = argc;
return argv_ret;
}
