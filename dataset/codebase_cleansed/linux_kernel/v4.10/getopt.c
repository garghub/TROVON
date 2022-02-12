int ncp_getopt(const char *caller, char **options, const struct ncp_option *opts,
char **optopt, char **optarg, unsigned long *value)
{
char *token;
char *val;
do {
if ((token = strsep(options, ",")) == NULL)
return 0;
} while (*token == '\0');
if (optopt)
*optopt = token;
if ((val = strchr (token, '=')) != NULL) {
*val++ = 0;
}
*optarg = val;
for (; opts->name; opts++) {
if (!strcmp(opts->name, token)) {
if (!val) {
if (opts->has_arg & OPT_NOPARAM) {
return opts->val;
}
pr_info("%s: the %s option requires an argument\n",
caller, token);
return -EINVAL;
}
if (opts->has_arg & OPT_INT) {
int rc = kstrtoul(val, 0, value);
if (rc) {
pr_info("%s: invalid numeric value in %s=%s\n",
caller, token, val);
return rc;
}
return opts->val;
}
if (opts->has_arg & OPT_STRING) {
return opts->val;
}
pr_info("%s: unexpected argument %s to the %s option\n",
caller, val, token);
return -EINVAL;
}
}
pr_info("%s: Unrecognized mount option %s\n", caller, token);
return -EOPNOTSUPP;
}
