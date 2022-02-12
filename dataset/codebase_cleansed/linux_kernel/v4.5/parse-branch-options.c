int
parse_branch_stack(const struct option *opt, const char *str, int unset)
{
#define ONLY_PLM \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
uint64_t *mode = (uint64_t *)opt->value;
const struct branch_mode *br;
char *s, *os = NULL, *p;
int ret = -1;
if (unset)
return 0;
if (*mode)
return -1;
if (str) {
s = os = strdup(str);
if (!s)
return -1;
for (;;) {
p = strchr(s, ',');
if (p)
*p = '\0';
for (br = branch_modes; br->name; br++) {
if (!strcasecmp(s, br->name))
break;
}
if (!br->name) {
ui__warning("unknown branch filter %s,"
" check man page\n", s);
goto error;
}
*mode |= br->mode;
if (!p)
break;
s = p + 1;
}
}
ret = 0;
if ((*mode & ~ONLY_PLM) == 0) {
*mode = PERF_SAMPLE_BRANCH_ANY;
}
error:
free(os);
return ret;
}
