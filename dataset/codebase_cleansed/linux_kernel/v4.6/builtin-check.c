static struct instruction *find_insn(struct objtool_file *file,
struct section *sec, unsigned long offset)
{
struct instruction *insn;
hash_for_each_possible(file->insn_hash, insn, hash, offset)
if (insn->sec == sec && insn->offset == offset)
return insn;
return NULL;
}
static struct instruction *next_insn_same_sec(struct objtool_file *file,
struct instruction *insn)
{
struct instruction *next = list_next_entry(insn, list);
if (&next->list == &file->insn_list || next->sec != insn->sec)
return NULL;
return next;
}
static bool ignore_func(struct objtool_file *file, struct symbol *func)
{
struct rela *rela;
struct instruction *insn;
if (file->whitelist && file->whitelist->rela)
list_for_each_entry(rela, &file->whitelist->rela->rela_list, list)
if (rela->sym->sec == func->sec &&
rela->addend == func->offset)
return true;
func_for_each_insn(file, func, insn)
if (insn->type == INSN_CONTEXT_SWITCH)
return true;
return false;
}
static int __dead_end_function(struct objtool_file *file, struct symbol *func,
int recursion)
{
int i;
struct instruction *insn;
bool empty = true;
static const char * const global_noreturns[] = {
"__stack_chk_fail",
"panic",
"do_exit",
"__module_put_and_exit",
"complete_and_exit",
"kvm_spurious_fault",
"__reiserfs_panic",
"lbug_with_loc"
};
if (func->bind == STB_WEAK)
return 0;
if (func->bind == STB_GLOBAL)
for (i = 0; i < ARRAY_SIZE(global_noreturns); i++)
if (!strcmp(func->name, global_noreturns[i]))
return 1;
if (!func->sec)
return 0;
func_for_each_insn(file, func, insn) {
empty = false;
if (insn->type == INSN_RETURN)
return 0;
}
if (empty)
return 0;
func_for_each_insn(file, func, insn) {
if (insn->sec != func->sec ||
insn->offset >= func->offset + func->len)
break;
if (insn->type == INSN_JUMP_UNCONDITIONAL) {
struct instruction *dest = insn->jump_dest;
struct symbol *dest_func;
if (!dest)
return 0;
if (dest->sec != func->sec ||
dest->offset < func->offset ||
dest->offset >= func->offset + func->len) {
dest_func = find_symbol_by_offset(dest->sec,
dest->offset);
if (!dest_func)
continue;
if (recursion == 5) {
WARN_FUNC("infinite recursion (objtool bug!)",
dest->sec, dest->offset);
return -1;
}
return __dead_end_function(file, dest_func,
recursion + 1);
}
}
if (insn->type == INSN_JUMP_DYNAMIC && list_empty(&insn->alts))
return 0;
}
return 1;
}
static int dead_end_function(struct objtool_file *file, struct symbol *func)
{
return __dead_end_function(file, func, 0);
}
static int decode_instructions(struct objtool_file *file)
{
struct section *sec;
struct symbol *func;
unsigned long offset;
struct instruction *insn;
int ret;
list_for_each_entry(sec, &file->elf->sections, list) {
if (!(sec->sh.sh_flags & SHF_EXECINSTR))
continue;
for (offset = 0; offset < sec->len; offset += insn->len) {
insn = malloc(sizeof(*insn));
memset(insn, 0, sizeof(*insn));
INIT_LIST_HEAD(&insn->alts);
insn->sec = sec;
insn->offset = offset;
ret = arch_decode_instruction(file->elf, sec, offset,
sec->len - offset,
&insn->len, &insn->type,
&insn->immediate);
if (ret)
return ret;
if (!insn->type || insn->type > INSN_LAST) {
WARN_FUNC("invalid instruction type %d",
insn->sec, insn->offset, insn->type);
return -1;
}
hash_add(file->insn_hash, &insn->hash, insn->offset);
list_add_tail(&insn->list, &file->insn_list);
}
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
if (!find_insn(file, sec, func->offset)) {
WARN("%s(): can't find starting instruction",
func->name);
return -1;
}
func_for_each_insn(file, func, insn)
if (!insn->func)
insn->func = func;
}
}
return 0;
}
static void add_ignores(struct objtool_file *file)
{
struct instruction *insn;
struct section *sec;
struct symbol *func;
list_for_each_entry(sec, &file->elf->sections, list) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
if (!ignore_func(file, func))
continue;
func_for_each_insn(file, func, insn)
insn->visited = true;
}
}
}
static int add_jump_destinations(struct objtool_file *file)
{
struct instruction *insn;
struct rela *rela;
struct section *dest_sec;
unsigned long dest_off;
for_each_insn(file, insn) {
if (insn->type != INSN_JUMP_CONDITIONAL &&
insn->type != INSN_JUMP_UNCONDITIONAL)
continue;
if (insn->visited)
continue;
rela = find_rela_by_dest_range(insn->sec, insn->offset,
insn->len);
if (!rela) {
dest_sec = insn->sec;
dest_off = insn->offset + insn->len + insn->immediate;
} else if (rela->sym->type == STT_SECTION) {
dest_sec = rela->sym->sec;
dest_off = rela->addend + 4;
} else if (rela->sym->sec->idx) {
dest_sec = rela->sym->sec;
dest_off = rela->sym->sym.st_value + rela->addend + 4;
} else {
insn->jump_dest = 0;
continue;
}
insn->jump_dest = find_insn(file, dest_sec, dest_off);
if (!insn->jump_dest) {
if (!strcmp(insn->sec->name, ".altinstr_replacement"))
continue;
WARN_FUNC("can't find jump dest instruction at %s+0x%lx",
insn->sec, insn->offset, dest_sec->name,
dest_off);
return -1;
}
}
return 0;
}
static int add_call_destinations(struct objtool_file *file)
{
struct instruction *insn;
unsigned long dest_off;
struct rela *rela;
for_each_insn(file, insn) {
if (insn->type != INSN_CALL)
continue;
rela = find_rela_by_dest_range(insn->sec, insn->offset,
insn->len);
if (!rela) {
dest_off = insn->offset + insn->len + insn->immediate;
insn->call_dest = find_symbol_by_offset(insn->sec,
dest_off);
if (!insn->call_dest) {
WARN_FUNC("can't find call dest symbol at offset 0x%lx",
insn->sec, insn->offset, dest_off);
return -1;
}
} else if (rela->sym->type == STT_SECTION) {
insn->call_dest = find_symbol_by_offset(rela->sym->sec,
rela->addend+4);
if (!insn->call_dest ||
insn->call_dest->type != STT_FUNC) {
WARN_FUNC("can't find call dest symbol at %s+0x%x",
insn->sec, insn->offset,
rela->sym->sec->name,
rela->addend + 4);
return -1;
}
} else
insn->call_dest = rela->sym;
}
return 0;
}
static int handle_group_alt(struct objtool_file *file,
struct special_alt *special_alt,
struct instruction *orig_insn,
struct instruction **new_insn)
{
struct instruction *last_orig_insn, *last_new_insn, *insn, *fake_jump;
unsigned long dest_off;
last_orig_insn = NULL;
insn = orig_insn;
sec_for_each_insn_from(file, insn) {
if (insn->offset >= special_alt->orig_off + special_alt->orig_len)
break;
if (special_alt->skip_orig)
insn->type = INSN_NOP;
insn->alt_group = true;
last_orig_insn = insn;
}
if (!next_insn_same_sec(file, last_orig_insn)) {
WARN("%s: don't know how to handle alternatives at end of section",
special_alt->orig_sec->name);
return -1;
}
fake_jump = malloc(sizeof(*fake_jump));
if (!fake_jump) {
WARN("malloc failed");
return -1;
}
memset(fake_jump, 0, sizeof(*fake_jump));
INIT_LIST_HEAD(&fake_jump->alts);
fake_jump->sec = special_alt->new_sec;
fake_jump->offset = -1;
fake_jump->type = INSN_JUMP_UNCONDITIONAL;
fake_jump->jump_dest = list_next_entry(last_orig_insn, list);
if (!special_alt->new_len) {
*new_insn = fake_jump;
return 0;
}
last_new_insn = NULL;
insn = *new_insn;
sec_for_each_insn_from(file, insn) {
if (insn->offset >= special_alt->new_off + special_alt->new_len)
break;
last_new_insn = insn;
if (insn->type != INSN_JUMP_CONDITIONAL &&
insn->type != INSN_JUMP_UNCONDITIONAL)
continue;
if (!insn->immediate)
continue;
dest_off = insn->offset + insn->len + insn->immediate;
if (dest_off == special_alt->new_off + special_alt->new_len)
insn->jump_dest = fake_jump;
if (!insn->jump_dest) {
WARN_FUNC("can't find alternative jump destination",
insn->sec, insn->offset);
return -1;
}
}
if (!last_new_insn) {
WARN_FUNC("can't find last new alternative instruction",
special_alt->new_sec, special_alt->new_off);
return -1;
}
list_add(&fake_jump->list, &last_new_insn->list);
return 0;
}
static int handle_jump_alt(struct objtool_file *file,
struct special_alt *special_alt,
struct instruction *orig_insn,
struct instruction **new_insn)
{
if (orig_insn->type == INSN_NOP)
return 0;
if (orig_insn->type != INSN_JUMP_UNCONDITIONAL) {
WARN_FUNC("unsupported instruction at jump label",
orig_insn->sec, orig_insn->offset);
return -1;
}
*new_insn = list_next_entry(orig_insn, list);
return 0;
}
static int add_special_section_alts(struct objtool_file *file)
{
struct list_head special_alts;
struct instruction *orig_insn, *new_insn;
struct special_alt *special_alt, *tmp;
struct alternative *alt;
int ret;
ret = special_get_alts(file->elf, &special_alts);
if (ret)
return ret;
list_for_each_entry_safe(special_alt, tmp, &special_alts, list) {
alt = malloc(sizeof(*alt));
if (!alt) {
WARN("malloc failed");
ret = -1;
goto out;
}
orig_insn = find_insn(file, special_alt->orig_sec,
special_alt->orig_off);
if (!orig_insn) {
WARN_FUNC("special: can't find orig instruction",
special_alt->orig_sec, special_alt->orig_off);
ret = -1;
goto out;
}
new_insn = NULL;
if (!special_alt->group || special_alt->new_len) {
new_insn = find_insn(file, special_alt->new_sec,
special_alt->new_off);
if (!new_insn) {
WARN_FUNC("special: can't find new instruction",
special_alt->new_sec,
special_alt->new_off);
ret = -1;
goto out;
}
}
if (special_alt->group) {
ret = handle_group_alt(file, special_alt, orig_insn,
&new_insn);
if (ret)
goto out;
} else if (special_alt->jump_or_nop) {
ret = handle_jump_alt(file, special_alt, orig_insn,
&new_insn);
if (ret)
goto out;
}
alt->insn = new_insn;
list_add_tail(&alt->list, &orig_insn->alts);
list_del(&special_alt->list);
free(special_alt);
}
out:
return ret;
}
static int add_switch_table(struct objtool_file *file, struct symbol *func,
struct instruction *insn, struct rela *table,
struct rela *next_table)
{
struct rela *rela = table;
struct instruction *alt_insn;
struct alternative *alt;
list_for_each_entry_from(rela, &file->rodata->rela->rela_list, list) {
if (rela == next_table)
break;
if (rela->sym->sec != insn->sec ||
rela->addend <= func->offset ||
rela->addend >= func->offset + func->len)
break;
alt_insn = find_insn(file, insn->sec, rela->addend);
if (!alt_insn) {
WARN("%s: can't find instruction at %s+0x%x",
file->rodata->rela->name, insn->sec->name,
rela->addend);
return -1;
}
alt = malloc(sizeof(*alt));
if (!alt) {
WARN("malloc failed");
return -1;
}
alt->insn = alt_insn;
list_add_tail(&alt->list, &insn->alts);
}
return 0;
}
static int add_func_switch_tables(struct objtool_file *file,
struct symbol *func)
{
struct instruction *insn, *prev_jump;
struct rela *text_rela, *rodata_rela, *prev_rela;
int ret;
prev_jump = NULL;
func_for_each_insn(file, func, insn) {
if (insn->type != INSN_JUMP_DYNAMIC)
continue;
text_rela = find_rela_by_dest_range(insn->sec, insn->offset,
insn->len);
if (!text_rela || text_rela->sym != file->rodata->sym)
continue;
rodata_rela = find_rela_by_dest(file->rodata,
text_rela->addend);
if (!rodata_rela) {
rodata_rela = find_rela_by_dest(file->rodata,
text_rela->addend + 4);
if (rodata_rela)
file->ignore_unreachables = true;
}
if (!rodata_rela)
continue;
if (prev_jump) {
ret = add_switch_table(file, func, prev_jump, prev_rela,
rodata_rela);
if (ret)
return ret;
}
prev_jump = insn;
prev_rela = rodata_rela;
}
if (prev_jump) {
ret = add_switch_table(file, func, prev_jump, prev_rela, NULL);
if (ret)
return ret;
}
return 0;
}
static int add_switch_table_alts(struct objtool_file *file)
{
struct section *sec;
struct symbol *func;
int ret;
if (!file->rodata || !file->rodata->rela)
return 0;
list_for_each_entry(sec, &file->elf->sections, list) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
ret = add_func_switch_tables(file, func);
if (ret)
return ret;
}
}
return 0;
}
static int decode_sections(struct objtool_file *file)
{
int ret;
ret = decode_instructions(file);
if (ret)
return ret;
add_ignores(file);
ret = add_jump_destinations(file);
if (ret)
return ret;
ret = add_call_destinations(file);
if (ret)
return ret;
ret = add_special_section_alts(file);
if (ret)
return ret;
ret = add_switch_table_alts(file);
if (ret)
return ret;
return 0;
}
static bool is_fentry_call(struct instruction *insn)
{
if (insn->type == INSN_CALL &&
insn->call_dest->type == STT_NOTYPE &&
!strcmp(insn->call_dest->name, "__fentry__"))
return true;
return false;
}
static bool has_modified_stack_frame(struct instruction *insn)
{
return (insn->state & STATE_FP_SAVED) ||
(insn->state & STATE_FP_SETUP);
}
static bool has_valid_stack_frame(struct instruction *insn)
{
return (insn->state & STATE_FP_SAVED) &&
(insn->state & STATE_FP_SETUP);
}
static unsigned int frame_state(unsigned long state)
{
return (state & (STATE_FP_SAVED | STATE_FP_SETUP));
}
static int validate_branch(struct objtool_file *file,
struct instruction *first, unsigned char first_state)
{
struct alternative *alt;
struct instruction *insn;
struct section *sec;
struct symbol *func = NULL;
unsigned char state;
int ret;
insn = first;
sec = insn->sec;
state = first_state;
if (insn->alt_group && list_empty(&insn->alts)) {
WARN_FUNC("don't know how to handle branch to middle of alternative instruction group",
sec, insn->offset);
return 1;
}
while (1) {
if (file->c_file && insn->func) {
if (func && func != insn->func) {
WARN("%s() falls through to next function %s()",
func->name, insn->func->name);
return 1;
}
func = insn->func;
}
if (insn->visited) {
if (frame_state(insn->state) != frame_state(state)) {
WARN_FUNC("frame pointer state mismatch",
sec, insn->offset);
return 1;
}
return 0;
}
insn->visited = true;
insn->state = state;
list_for_each_entry(alt, &insn->alts, list) {
ret = validate_branch(file, alt->insn, state);
if (ret)
return 1;
}
switch (insn->type) {
case INSN_FP_SAVE:
if (!nofp) {
if (state & STATE_FP_SAVED) {
WARN_FUNC("duplicate frame pointer save",
sec, insn->offset);
return 1;
}
state |= STATE_FP_SAVED;
}
break;
case INSN_FP_SETUP:
if (!nofp) {
if (state & STATE_FP_SETUP) {
WARN_FUNC("duplicate frame pointer setup",
sec, insn->offset);
return 1;
}
state |= STATE_FP_SETUP;
}
break;
case INSN_FP_RESTORE:
if (!nofp) {
if (has_valid_stack_frame(insn))
state &= ~STATE_FP_SETUP;
state &= ~STATE_FP_SAVED;
}
break;
case INSN_RETURN:
if (!nofp && has_modified_stack_frame(insn)) {
WARN_FUNC("return without frame pointer restore",
sec, insn->offset);
return 1;
}
return 0;
case INSN_CALL:
if (is_fentry_call(insn)) {
state |= STATE_FENTRY;
break;
}
ret = dead_end_function(file, insn->call_dest);
if (ret == 1)
return 0;
if (ret == -1)
return 1;
case INSN_CALL_DYNAMIC:
if (!nofp && !has_valid_stack_frame(insn)) {
WARN_FUNC("call without frame pointer save/setup",
sec, insn->offset);
return 1;
}
break;
case INSN_JUMP_CONDITIONAL:
case INSN_JUMP_UNCONDITIONAL:
if (insn->jump_dest) {
ret = validate_branch(file, insn->jump_dest,
state);
if (ret)
return 1;
} else if (has_modified_stack_frame(insn)) {
WARN_FUNC("sibling call from callable instruction with changed frame pointer",
sec, insn->offset);
return 1;
}
if (insn->type == INSN_JUMP_UNCONDITIONAL)
return 0;
break;
case INSN_JUMP_DYNAMIC:
if (list_empty(&insn->alts) &&
has_modified_stack_frame(insn)) {
WARN_FUNC("sibling call from callable instruction with changed frame pointer",
sec, insn->offset);
return 1;
}
return 0;
case INSN_BUG:
return 0;
default:
break;
}
insn = next_insn_same_sec(file, insn);
if (!insn) {
WARN("%s: unexpected end of section", sec->name);
return 1;
}
}
return 0;
}
static bool is_gcov_insn(struct instruction *insn)
{
struct rela *rela;
struct section *sec;
struct symbol *sym;
unsigned long offset;
rela = find_rela_by_dest_range(insn->sec, insn->offset, insn->len);
if (!rela)
return false;
if (rela->sym->type != STT_SECTION)
return false;
sec = rela->sym->sec;
offset = rela->addend + insn->offset + insn->len - rela->offset;
list_for_each_entry(sym, &sec->symbol_list, list) {
if (sym->type != STT_OBJECT)
continue;
if (offset >= sym->offset && offset < sym->offset + sym->len)
return (!memcmp(sym->name, "__gcov0.", 8));
}
return false;
}
static bool is_kasan_insn(struct instruction *insn)
{
return (insn->type == INSN_CALL &&
!strcmp(insn->call_dest->name, "__asan_handle_no_return"));
}
static bool is_ubsan_insn(struct instruction *insn)
{
return (insn->type == INSN_CALL &&
!strcmp(insn->call_dest->name,
"__ubsan_handle_builtin_unreachable"));
}
static bool ignore_unreachable_insn(struct symbol *func,
struct instruction *insn)
{
int i;
if (insn->type == INSN_NOP)
return true;
if (is_gcov_insn(insn))
return true;
for (i = 0; i < 5; i++) {
if (is_kasan_insn(insn) || is_ubsan_insn(insn))
return true;
if (insn->type == INSN_JUMP_UNCONDITIONAL && insn->jump_dest) {
insn = insn->jump_dest;
continue;
}
if (insn->offset + insn->len >= func->offset + func->len)
break;
insn = list_next_entry(insn, list);
}
return false;
}
static int validate_functions(struct objtool_file *file)
{
struct section *sec;
struct symbol *func;
struct instruction *insn;
int ret, warnings = 0;
list_for_each_entry(sec, &file->elf->sections, list) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
insn = find_insn(file, sec, func->offset);
if (!insn)
continue;
ret = validate_branch(file, insn, 0);
warnings += ret;
}
}
list_for_each_entry(sec, &file->elf->sections, list) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
func_for_each_insn(file, func, insn) {
if (insn->visited)
continue;
insn->visited = true;
if (file->ignore_unreachables || warnings ||
ignore_unreachable_insn(func, insn))
continue;
WARN_FUNC("function has unreachable instruction", insn->sec, insn->offset);
warnings++;
}
}
}
return warnings;
}
static int validate_uncallable_instructions(struct objtool_file *file)
{
struct instruction *insn;
int warnings = 0;
for_each_insn(file, insn) {
if (!insn->visited && insn->type == INSN_RETURN) {
WARN_FUNC("return instruction outside of a callable function",
insn->sec, insn->offset);
warnings++;
}
}
return warnings;
}
static void cleanup(struct objtool_file *file)
{
struct instruction *insn, *tmpinsn;
struct alternative *alt, *tmpalt;
list_for_each_entry_safe(insn, tmpinsn, &file->insn_list, list) {
list_for_each_entry_safe(alt, tmpalt, &insn->alts, list) {
list_del(&alt->list);
free(alt);
}
list_del(&insn->list);
hash_del(&insn->hash);
free(insn);
}
elf_close(file->elf);
}
int cmd_check(int argc, const char **argv)
{
struct objtool_file file;
int ret, warnings = 0;
const struct option options[] = {
OPT_BOOLEAN('f', "no-fp", &nofp, "Skip frame pointer validation"),
OPT_END(),
};
argc = parse_options(argc, argv, options, check_usage, 0);
if (argc != 1)
usage_with_options(check_usage, options);
objname = argv[0];
file.elf = elf_open(objname);
if (!file.elf) {
fprintf(stderr, "error reading elf file %s\n", objname);
return 1;
}
INIT_LIST_HEAD(&file.insn_list);
hash_init(file.insn_hash);
file.whitelist = find_section_by_name(file.elf, "__func_stack_frame_non_standard");
file.rodata = find_section_by_name(file.elf, ".rodata");
file.ignore_unreachables = false;
file.c_file = find_section_by_name(file.elf, ".comment");
ret = decode_sections(&file);
if (ret < 0)
goto out;
warnings += ret;
ret = validate_functions(&file);
if (ret < 0)
goto out;
warnings += ret;
ret = validate_uncallable_instructions(&file);
if (ret < 0)
goto out;
warnings += ret;
out:
cleanup(&file);
if (ret || warnings)
return 0;
return 0;
}
