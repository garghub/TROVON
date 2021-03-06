static int perf_unknown_cmd_config(const char *var, const char *value, void *cb)
{
if (!strcmp(var, "help.autocorrect"))
autocorrect = perf_config_int(var,value);
if (!prefixcmp(var, "alias."))
add_cmdname(&aliases, var + 6, strlen(var + 6));
return perf_default_config(var, value, cb);
}
static int levenshtein_compare(const void *p1, const void *p2)
{
const struct cmdname *const *c1 = p1, *const *c2 = p2;
const char *s1 = (*c1)->name, *s2 = (*c2)->name;
int l1 = (*c1)->len;
int l2 = (*c2)->len;
return l1 != l2 ? l1 - l2 : strcmp(s1, s2);
}
static void add_cmd_list(struct cmdnames *cmds, struct cmdnames *old)
{
unsigned int i;
ALLOC_GROW(cmds->names, cmds->cnt + old->cnt, cmds->alloc);
for (i = 0; i < old->cnt; i++)
cmds->names[cmds->cnt++] = old->names[i];
zfree(&old->names);
old->cnt = 0;
}
const char *help_unknown_cmd(const char *cmd)
{
unsigned int i, n = 0, best_similarity = 0;
struct cmdnames main_cmds, other_cmds;
memset(&main_cmds, 0, sizeof(main_cmds));
memset(&other_cmds, 0, sizeof(main_cmds));
memset(&aliases, 0, sizeof(aliases));
perf_config(perf_unknown_cmd_config, NULL);
load_command_list("perf-", &main_cmds, &other_cmds);
add_cmd_list(&main_cmds, &aliases);
add_cmd_list(&main_cmds, &other_cmds);
qsort(main_cmds.names, main_cmds.cnt,
sizeof(main_cmds.names), cmdname_compare);
uniq(&main_cmds);
if (main_cmds.cnt) {
for (i = 0; i < main_cmds.cnt; ++i)
main_cmds.names[i]->len =
levenshtein(cmd, main_cmds.names[i]->name, 0, 2, 1, 4);
qsort(main_cmds.names, main_cmds.cnt,
sizeof(*main_cmds.names), levenshtein_compare);
best_similarity = main_cmds.names[0]->len;
n = 1;
while (n < main_cmds.cnt && best_similarity == main_cmds.names[n]->len)
++n;
}
if (autocorrect && n == 1) {
const char *assumed = main_cmds.names[0]->name;
main_cmds.names[0] = NULL;
clean_cmdnames(&main_cmds);
fprintf(stderr, "WARNING: You called a perf program named '%s', "
"which does not exist.\n"
"Continuing under the assumption that you meant '%s'\n",
cmd, assumed);
if (autocorrect > 0) {
fprintf(stderr, "in %0.1f seconds automatically...\n",
(float)autocorrect/10.0);
poll(NULL, 0, autocorrect * 100);
}
return assumed;
}
fprintf(stderr, "perf: '%s' is not a perf-command. See 'perf --help'.\n", cmd);
if (main_cmds.cnt && best_similarity < 6) {
fprintf(stderr, "\nDid you mean %s?\n",
n < 2 ? "this": "one of these");
for (i = 0; i < n; i++)
fprintf(stderr, "\t%s\n", main_cmds.names[i]->name);
}
exit(1);
}
