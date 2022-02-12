int parse_branch_str(const char *str, __u64 *mode)
{
#define ONLY_PLM \
(PERF_SAMPLE_BRANCH_USER |\
PERF_SAMPLE_BRANCH_KERNEL |\
PERF_SAMPLE_BRANCH_HV)
int ret = 0;
char *p, *s;
char *os = NULL;
const struct branch_mode *br;
if (str == NULL) {
*mode = PERF_SAMPLE_BRANCH_ANY;
return 0;
}
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
ret = -1;
pr_warning("unknown branch filter %s,"
" check man page\n", s);
goto error;
}
*mode |= br->mode;
if (!p)
break;
s = p + 1;
}
if ((*mode & ~ONLY_PLM) == 0) {
*mode = PERF_SAMPLE_BRANCH_ANY;
}
error:
free(os);
return ret;
}
int
parse_branch_stack(const struct option *opt, const char *str, int unset)
{
__u64 *mode = (__u64 *)opt->value;
if (unset)
return 0;
if (*mode)
return -1;
return parse_branch_str(str, mode);
}
