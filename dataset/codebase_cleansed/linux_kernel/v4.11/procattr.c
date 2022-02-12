int aa_getprocattr(struct aa_profile *profile, char **string)
{
char *str;
int len = 0, mode_len = 0, ns_len = 0, name_len;
const char *mode_str = aa_profile_mode_names[profile->mode];
const char *ns_name = NULL;
struct aa_ns *ns = profile->ns;
struct aa_ns *current_ns = __aa_current_profile()->ns;
char *s;
if (!aa_ns_visible(current_ns, ns, true))
return -EACCES;
ns_name = aa_ns_name(current_ns, ns, true);
ns_len = strlen(ns_name);
if (ns_len)
ns_len += 4;
if (!unconfined(profile))
mode_len = strlen(mode_str) + 3;
name_len = strlen(profile->base.hname);
len = mode_len + ns_len + name_len + 1;
s = str = kmalloc(len + 1, GFP_KERNEL);
if (!str)
return -ENOMEM;
if (ns_len) {
sprintf(s, ":%s://", ns_name);
s += ns_len;
}
if (unconfined(profile))
sprintf(s, "%s\n", profile->base.hname);
else
sprintf(s, "%s (%s)\n", profile->base.hname, mode_str);
*string = str;
return len;
}
static char *split_token_from_name(const char *op, char *args, u64 *token)
{
char *name;
*token = simple_strtoull(args, &name, 16);
if ((name == args) || *name != '^') {
AA_ERROR("%s: Invalid input '%s'", op, args);
return ERR_PTR(-EINVAL);
}
name++;
if (!*name)
name = NULL;
return name;
}
int aa_setprocattr_changehat(char *args, size_t size, int test)
{
char *hat;
u64 token;
const char *hats[16];
int count = 0;
hat = split_token_from_name(OP_CHANGE_HAT, args, &token);
if (IS_ERR(hat))
return PTR_ERR(hat);
if (!hat && !token) {
AA_ERROR("change_hat: Invalid input, NULL hat and NULL magic");
return -EINVAL;
}
if (hat) {
char *end = args + size;
for (count = 0; (hat < end) && count < 16; ++count) {
char *next = hat + strlen(hat) + 1;
hats[count] = hat;
AA_DEBUG("%s: (pid %d) Magic 0x%llx count %d hat '%s'\n"
, __func__, current->pid, token, count, hat);
hat = next;
}
} else
AA_DEBUG("%s: (pid %d) Magic 0x%llx count %d Hat '%s'\n",
__func__, current->pid, token, count, "<NULL>");
return aa_change_hat(hats, count, token, test);
}
