int aa_getprocattr(struct aa_label *label, char **string)
{
struct aa_ns *ns = labels_ns(label);
struct aa_ns *current_ns = aa_get_current_ns();
int len;
if (!aa_ns_visible(current_ns, ns, true)) {
aa_put_ns(current_ns);
return -EACCES;
}
len = aa_label_snxprint(NULL, 0, current_ns, label,
FLAG_SHOW_MODE | FLAG_VIEW_SUBNS |
FLAG_HIDDEN_UNCONFINED);
AA_BUG(len < 0);
*string = kmalloc(len + 2, GFP_KERNEL);
if (!*string) {
aa_put_ns(current_ns);
return -ENOMEM;
}
len = aa_label_snxprint(*string, len + 2, current_ns, label,
FLAG_SHOW_MODE | FLAG_VIEW_SUBNS |
FLAG_HIDDEN_UNCONFINED);
if (len < 0) {
aa_put_ns(current_ns);
return len;
}
(*string)[len] = '\n';
(*string)[len + 1] = 0;
aa_put_ns(current_ns);
return len + 1;
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
int aa_setprocattr_changehat(char *args, size_t size, int flags)
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
return aa_change_hat(hats, count, token, flags);
}
