static inline unsigned long bug_addr(const struct bug_entry *bug)
{
#ifndef CONFIG_GENERIC_BUG_RELATIVE_POINTERS
return bug->bug_addr;
#else
return (unsigned long)bug + bug->bug_addr_disp;
#endif
}
static struct bug_entry *module_find_bug(unsigned long bugaddr)
{
struct module *mod;
struct bug_entry *bug = NULL;
rcu_read_lock_sched();
list_for_each_entry_rcu(mod, &module_bug_list, bug_list) {
unsigned i;
bug = mod->bug_table;
for (i = 0; i < mod->num_bugs; ++i, ++bug)
if (bugaddr == bug_addr(bug))
goto out;
}
bug = NULL;
out:
rcu_read_unlock_sched();
return bug;
}
void module_bug_finalize(const Elf_Ehdr *hdr, const Elf_Shdr *sechdrs,
struct module *mod)
{
char *secstrings;
unsigned int i;
lockdep_assert_held(&module_mutex);
mod->bug_table = NULL;
mod->num_bugs = 0;
secstrings = (char *)hdr + sechdrs[hdr->e_shstrndx].sh_offset;
for (i = 1; i < hdr->e_shnum; i++) {
if (strcmp(secstrings+sechdrs[i].sh_name, "__bug_table"))
continue;
mod->bug_table = (void *) sechdrs[i].sh_addr;
mod->num_bugs = sechdrs[i].sh_size / sizeof(struct bug_entry);
break;
}
list_add_rcu(&mod->bug_list, &module_bug_list);
}
void module_bug_cleanup(struct module *mod)
{
lockdep_assert_held(&module_mutex);
list_del_rcu(&mod->bug_list);
}
static inline struct bug_entry *module_find_bug(unsigned long bugaddr)
{
return NULL;
}
struct bug_entry *find_bug(unsigned long bugaddr)
{
struct bug_entry *bug;
for (bug = __start___bug_table; bug < __stop___bug_table; ++bug)
if (bugaddr == bug_addr(bug))
return bug;
return module_find_bug(bugaddr);
}
enum bug_trap_type report_bug(unsigned long bugaddr, struct pt_regs *regs)
{
struct bug_entry *bug;
const char *file;
unsigned line, warning, once, done;
if (!is_valid_bugaddr(bugaddr))
return BUG_TRAP_TYPE_NONE;
bug = find_bug(bugaddr);
file = NULL;
line = 0;
warning = 0;
if (bug) {
#ifdef CONFIG_DEBUG_BUGVERBOSE
#ifndef CONFIG_GENERIC_BUG_RELATIVE_POINTERS
file = bug->file;
#else
file = (const char *)bug + bug->file_disp;
#endif
line = bug->line;
#endif
warning = (bug->flags & BUGFLAG_WARNING) != 0;
once = (bug->flags & BUGFLAG_ONCE) != 0;
done = (bug->flags & BUGFLAG_DONE) != 0;
if (warning && once) {
if (done)
return BUG_TRAP_TYPE_WARN;
bug->flags |= BUGFLAG_DONE;
}
}
if (warning) {
__warn(file, line, (void *)bugaddr, BUG_GET_TAINT(bug), regs,
NULL);
return BUG_TRAP_TYPE_WARN;
}
printk(KERN_DEFAULT "------------[ cut here ]------------\n");
if (file)
pr_crit("kernel BUG at %s:%u!\n", file, line);
else
pr_crit("Kernel BUG at %p [verbose debug info unavailable]\n",
(void *)bugaddr);
return BUG_TRAP_TYPE_BUG;
}
