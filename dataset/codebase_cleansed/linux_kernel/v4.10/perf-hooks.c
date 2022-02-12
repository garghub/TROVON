void perf_hooks__invoke(const struct perf_hook_desc *desc)
{
if (!(desc && desc->p_hook_func && *desc->p_hook_func))
return;
if (sigsetjmp(jmpbuf, 1)) {
pr_warning("Fatal error (SEGFAULT) in perf hook '%s'\n",
desc->hook_name);
*(current_perf_hook->p_hook_func) = NULL;
} else {
current_perf_hook = desc;
(**desc->p_hook_func)(desc->hook_ctx);
}
current_perf_hook = NULL;
}
void perf_hooks__recover(void)
{
if (current_perf_hook)
siglongjmp(jmpbuf, 1);
}
int perf_hooks__set_hook(const char *hook_name,
perf_hook_func_t hook_func,
void *hook_ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(perf_hooks); i++) {
if (strcmp(hook_name, perf_hooks[i]->hook_name) != 0)
continue;
if (*(perf_hooks[i]->p_hook_func))
pr_warning("Overwrite existing hook: %s\n", hook_name);
*(perf_hooks[i]->p_hook_func) = hook_func;
perf_hooks[i]->hook_ctx = hook_ctx;
return 0;
}
return -ENOENT;
}
perf_hook_func_t perf_hooks__get_hook(const char *hook_name)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(perf_hooks); i++) {
if (strcmp(hook_name, perf_hooks[i]->hook_name) != 0)
continue;
return *(perf_hooks[i]->p_hook_func);
}
return ERR_PTR(-ENOENT);
}
