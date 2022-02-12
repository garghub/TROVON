struct instruction *find_insn(struct objtool_file *file,
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
if (!next || &next->list == &file->insn_list || next->sec != insn->sec)
return NULL;
return next;
}
static bool ignore_func(struct objtool_file *file, struct symbol *func)
{
struct rela *rela;
if (file->whitelist && file->whitelist->rela)
list_for_each_entry(rela, &file->whitelist->rela->rela_list, list) {
if (rela->sym->type == STT_SECTION &&
rela->sym->sec == func->sec &&
rela->addend == func->offset)
return true;
if (rela->sym->type == STT_FUNC && rela->sym == func)
return true;
}
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
"do_task_dead",
"__module_put_and_exit",
"complete_and_exit",
"kvm_spurious_fault",
"__reiserfs_panic",
"lbug_with_loc",
"fortify_panic",
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
static void clear_insn_state(struct insn_state *state)
{
int i;
memset(state, 0, sizeof(*state));
state->cfa.base = CFI_UNDEFINED;
for (i = 0; i < CFI_NUM_REGS; i++) {
state->regs[i].base = CFI_UNDEFINED;
state->vals[i].base = CFI_UNDEFINED;
}
state->drap_reg = CFI_UNDEFINED;
state->drap_offset = -1;
}
static int decode_instructions(struct objtool_file *file)
{
struct section *sec;
struct symbol *func;
unsigned long offset;
struct instruction *insn;
int ret;
for_each_sec(file, sec) {
if (!(sec->sh.sh_flags & SHF_EXECINSTR))
continue;
if (strcmp(sec->name, ".altinstr_replacement") &&
strcmp(sec->name, ".altinstr_aux") &&
strncmp(sec->name, ".discard.", 9))
sec->text = true;
for (offset = 0; offset < sec->len; offset += insn->len) {
insn = malloc(sizeof(*insn));
if (!insn) {
WARN("malloc failed");
return -1;
}
memset(insn, 0, sizeof(*insn));
INIT_LIST_HEAD(&insn->alts);
clear_insn_state(&insn->state);
insn->sec = sec;
insn->offset = offset;
ret = arch_decode_instruction(file->elf, sec, offset,
sec->len - offset,
&insn->len, &insn->type,
&insn->immediate,
&insn->stack_op);
if (ret)
goto err;
if (!insn->type || insn->type > INSN_LAST) {
WARN_FUNC("invalid instruction type %d",
insn->sec, insn->offset, insn->type);
ret = -1;
goto err;
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
err:
free(insn);
return ret;
}
static int add_dead_ends(struct objtool_file *file)
{
struct section *sec;
struct rela *rela;
struct instruction *insn;
bool found;
for_each_insn(file, insn)
if (insn->type == INSN_BUG)
insn->dead_end = true;
sec = find_section_by_name(file->elf, ".rela.discard.unreachable");
if (!sec)
goto reachable;
list_for_each_entry(rela, &sec->rela_list, list) {
if (rela->sym->type != STT_SECTION) {
WARN("unexpected relocation symbol type in %s", sec->name);
return -1;
}
insn = find_insn(file, rela->sym->sec, rela->addend);
if (insn)
insn = list_prev_entry(insn, list);
else if (rela->addend == rela->sym->sec->len) {
found = false;
list_for_each_entry_reverse(insn, &file->insn_list, list) {
if (insn->sec == rela->sym->sec) {
found = true;
break;
}
}
if (!found) {
WARN("can't find unreachable insn at %s+0x%x",
rela->sym->sec->name, rela->addend);
return -1;
}
} else {
WARN("can't find unreachable insn at %s+0x%x",
rela->sym->sec->name, rela->addend);
return -1;
}
insn->dead_end = true;
}
reachable:
sec = find_section_by_name(file->elf, ".rela.discard.reachable");
if (!sec)
return 0;
list_for_each_entry(rela, &sec->rela_list, list) {
if (rela->sym->type != STT_SECTION) {
WARN("unexpected relocation symbol type in %s", sec->name);
return -1;
}
insn = find_insn(file, rela->sym->sec, rela->addend);
if (insn)
insn = list_prev_entry(insn, list);
else if (rela->addend == rela->sym->sec->len) {
found = false;
list_for_each_entry_reverse(insn, &file->insn_list, list) {
if (insn->sec == rela->sym->sec) {
found = true;
break;
}
}
if (!found) {
WARN("can't find reachable insn at %s+0x%x",
rela->sym->sec->name, rela->addend);
return -1;
}
} else {
WARN("can't find reachable insn at %s+0x%x",
rela->sym->sec->name, rela->addend);
return -1;
}
insn->dead_end = false;
}
return 0;
}
static void add_ignores(struct objtool_file *file)
{
struct instruction *insn;
struct section *sec;
struct symbol *func;
for_each_sec(file, sec) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
if (!ignore_func(file, func))
continue;
func_for_each_insn(file, func, insn)
insn->ignore = true;
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
if (insn->ignore)
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
clear_insn_state(&fake_jump->state);
fake_jump->sec = special_alt->new_sec;
fake_jump->offset = -1;
fake_jump->type = INSN_JUMP_UNCONDITIONAL;
fake_jump->jump_dest = list_next_entry(last_orig_insn, list);
fake_jump->ignore = true;
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
static struct rela *find_switch_table(struct objtool_file *file,
struct symbol *func,
struct instruction *insn)
{
struct rela *text_rela, *rodata_rela;
struct instruction *orig_insn = insn;
text_rela = find_rela_by_dest_range(insn->sec, insn->offset, insn->len);
if (text_rela && text_rela->sym == file->rodata->sym) {
rodata_rela = find_rela_by_dest(file->rodata,
text_rela->addend);
if (rodata_rela)
return rodata_rela;
rodata_rela = find_rela_by_dest(file->rodata,
text_rela->addend + 4);
if (!rodata_rela)
return NULL;
file->ignore_unreachables = true;
return rodata_rela;
}
func_for_each_insn_continue_reverse(file, func, insn) {
if (insn->type == INSN_JUMP_DYNAMIC)
break;
if (insn->type == INSN_JUMP_UNCONDITIONAL &&
insn->jump_dest &&
(insn->jump_dest->offset <= insn->offset ||
insn->jump_dest->offset > orig_insn->offset))
break;
text_rela = find_rela_by_dest_range(insn->sec, insn->offset,
insn->len);
if (!text_rela || text_rela->sym != file->rodata->sym)
continue;
if (find_symbol_containing(file->rodata, text_rela->addend))
continue;
return find_rela_by_dest(file->rodata, text_rela->addend);
}
return NULL;
}
static int add_func_switch_tables(struct objtool_file *file,
struct symbol *func)
{
struct instruction *insn, *prev_jump = NULL;
struct rela *rela, *prev_rela = NULL;
int ret;
func_for_each_insn(file, func, insn) {
if (insn->type != INSN_JUMP_DYNAMIC)
continue;
rela = find_switch_table(file, func, insn);
if (!rela)
continue;
if (prev_jump) {
ret = add_switch_table(file, func, prev_jump, prev_rela,
rela);
if (ret)
return ret;
}
prev_jump = insn;
prev_rela = rela;
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
for_each_sec(file, sec) {
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
static int read_unwind_hints(struct objtool_file *file)
{
struct section *sec, *relasec;
struct rela *rela;
struct unwind_hint *hint;
struct instruction *insn;
struct cfi_reg *cfa;
int i;
sec = find_section_by_name(file->elf, ".discard.unwind_hints");
if (!sec)
return 0;
relasec = sec->rela;
if (!relasec) {
WARN("missing .rela.discard.unwind_hints section");
return -1;
}
if (sec->len % sizeof(struct unwind_hint)) {
WARN("struct unwind_hint size mismatch");
return -1;
}
file->hints = true;
for (i = 0; i < sec->len / sizeof(struct unwind_hint); i++) {
hint = (struct unwind_hint *)sec->data->d_buf + i;
rela = find_rela_by_dest(sec, i * sizeof(*hint));
if (!rela) {
WARN("can't find rela for unwind_hints[%d]", i);
return -1;
}
insn = find_insn(file, rela->sym->sec, rela->addend);
if (!insn) {
WARN("can't find insn for unwind_hints[%d]", i);
return -1;
}
cfa = &insn->state.cfa;
if (hint->type == UNWIND_HINT_TYPE_SAVE) {
insn->save = true;
continue;
} else if (hint->type == UNWIND_HINT_TYPE_RESTORE) {
insn->restore = true;
insn->hint = true;
continue;
}
insn->hint = true;
switch (hint->sp_reg) {
case ORC_REG_UNDEFINED:
cfa->base = CFI_UNDEFINED;
break;
case ORC_REG_SP:
cfa->base = CFI_SP;
break;
case ORC_REG_BP:
cfa->base = CFI_BP;
break;
case ORC_REG_SP_INDIRECT:
cfa->base = CFI_SP_INDIRECT;
break;
case ORC_REG_R10:
cfa->base = CFI_R10;
break;
case ORC_REG_R13:
cfa->base = CFI_R13;
break;
case ORC_REG_DI:
cfa->base = CFI_DI;
break;
case ORC_REG_DX:
cfa->base = CFI_DX;
break;
default:
WARN_FUNC("unsupported unwind_hint sp base reg %d",
insn->sec, insn->offset, hint->sp_reg);
return -1;
}
cfa->offset = hint->sp_offset;
insn->state.type = hint->type;
}
return 0;
}
static int decode_sections(struct objtool_file *file)
{
int ret;
ret = decode_instructions(file);
if (ret)
return ret;
ret = add_dead_ends(file);
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
ret = read_unwind_hints(file);
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
static bool has_modified_stack_frame(struct insn_state *state)
{
int i;
if (state->cfa.base != initial_func_cfi.cfa.base ||
state->cfa.offset != initial_func_cfi.cfa.offset ||
state->stack_size != initial_func_cfi.cfa.offset ||
state->drap)
return true;
for (i = 0; i < CFI_NUM_REGS; i++)
if (state->regs[i].base != initial_func_cfi.regs[i].base ||
state->regs[i].offset != initial_func_cfi.regs[i].offset)
return true;
return false;
}
static bool has_valid_stack_frame(struct insn_state *state)
{
if (state->cfa.base == CFI_BP && state->regs[CFI_BP].base == CFI_CFA &&
state->regs[CFI_BP].offset == -16)
return true;
if (state->drap && state->regs[CFI_BP].base == CFI_BP)
return true;
return false;
}
static int update_insn_state_regs(struct instruction *insn, struct insn_state *state)
{
struct cfi_reg *cfa = &state->cfa;
struct stack_op *op = &insn->stack_op;
if (cfa->base != CFI_SP)
return 0;
if (op->dest.type == OP_DEST_PUSH)
cfa->offset += 8;
if (op->src.type == OP_SRC_POP)
cfa->offset -= 8;
if (op->dest.type == OP_DEST_REG && op->src.type == OP_SRC_ADD &&
op->dest.reg == CFI_SP && op->src.reg == CFI_SP)
cfa->offset -= op->src.offset;
return 0;
}
static void save_reg(struct insn_state *state, unsigned char reg, int base,
int offset)
{
if (arch_callee_saved_reg(reg) &&
state->regs[reg].base == CFI_UNDEFINED) {
state->regs[reg].base = base;
state->regs[reg].offset = offset;
}
}
static void restore_reg(struct insn_state *state, unsigned char reg)
{
state->regs[reg].base = CFI_UNDEFINED;
state->regs[reg].offset = 0;
}
static int update_insn_state(struct instruction *insn, struct insn_state *state)
{
struct stack_op *op = &insn->stack_op;
struct cfi_reg *cfa = &state->cfa;
struct cfi_reg *regs = state->regs;
if (cfa->base == CFI_UNDEFINED) {
if (insn->func) {
WARN_FUNC("undefined stack state", insn->sec, insn->offset);
return -1;
}
return 0;
}
if (state->type == ORC_TYPE_REGS || state->type == ORC_TYPE_REGS_IRET)
return update_insn_state_regs(insn, state);
switch (op->dest.type) {
case OP_DEST_REG:
switch (op->src.type) {
case OP_SRC_REG:
if (op->src.reg == CFI_SP && op->dest.reg == CFI_BP &&
cfa->base == CFI_SP &&
regs[CFI_BP].base == CFI_CFA &&
regs[CFI_BP].offset == -cfa->offset) {
cfa->base = op->dest.reg;
state->bp_scratch = false;
}
else if (op->src.reg == CFI_SP &&
op->dest.reg == CFI_BP && state->drap) {
regs[CFI_BP].base = CFI_BP;
regs[CFI_BP].offset = -state->stack_size;
state->bp_scratch = false;
}
else if (op->src.reg == CFI_SP && cfa->base == CFI_SP) {
state->vals[op->dest.reg].base = CFI_CFA;
state->vals[op->dest.reg].offset = -state->stack_size;
}
else if (op->dest.reg == cfa->base) {
if (cfa->base == CFI_SP &&
state->vals[op->src.reg].base == CFI_CFA) {
cfa->offset = -state->vals[op->src.reg].offset;
state->stack_size = cfa->offset;
} else {
cfa->base = CFI_UNDEFINED;
cfa->offset = 0;
}
}
break;
case OP_SRC_ADD:
if (op->dest.reg == CFI_SP && op->src.reg == CFI_SP) {
state->stack_size -= op->src.offset;
if (cfa->base == CFI_SP)
cfa->offset -= op->src.offset;
break;
}
if (op->dest.reg == CFI_SP && op->src.reg == CFI_BP) {
state->stack_size = -(op->src.offset + regs[CFI_BP].offset);
break;
}
if (op->src.reg == CFI_SP && cfa->base == CFI_SP) {
state->drap_reg = op->dest.reg;
state->vals[op->dest.reg].base = CFI_CFA;
state->vals[op->dest.reg].offset = \
-state->stack_size + op->src.offset;
break;
}
if (state->drap && op->dest.reg == CFI_SP &&
op->src.reg == state->drap_reg) {
cfa->base = CFI_SP;
cfa->offset = state->stack_size = -op->src.offset;
state->drap_reg = CFI_UNDEFINED;
state->drap = false;
break;
}
if (op->dest.reg == state->cfa.base) {
WARN_FUNC("unsupported stack register modification",
insn->sec, insn->offset);
return -1;
}
break;
case OP_SRC_AND:
if (op->dest.reg != CFI_SP ||
(state->drap_reg != CFI_UNDEFINED && cfa->base != CFI_SP) ||
(state->drap_reg == CFI_UNDEFINED && cfa->base != CFI_BP)) {
WARN_FUNC("unsupported stack pointer realignment",
insn->sec, insn->offset);
return -1;
}
if (state->drap_reg != CFI_UNDEFINED) {
cfa->base = state->drap_reg;
cfa->offset = state->stack_size = 0;
state->drap = true;
}
break;
case OP_SRC_POP:
if (!state->drap && op->dest.type == OP_DEST_REG &&
op->dest.reg == cfa->base) {
cfa->base = CFI_SP;
}
if (state->drap && cfa->base == CFI_BP_INDIRECT &&
op->dest.type == OP_DEST_REG &&
op->dest.reg == state->drap_reg &&
state->drap_offset == -state->stack_size) {
cfa->base = state->drap_reg;
cfa->offset = 0;
state->drap_offset = -1;
} else if (regs[op->dest.reg].offset == -state->stack_size) {
restore_reg(state, op->dest.reg);
}
state->stack_size -= 8;
if (cfa->base == CFI_SP)
cfa->offset -= 8;
break;
case OP_SRC_REG_INDIRECT:
if (state->drap && op->src.reg == CFI_BP &&
op->src.offset == state->drap_offset) {
cfa->base = state->drap_reg;
cfa->offset = 0;
state->drap_offset = -1;
}
if (state->drap && op->src.reg == CFI_BP &&
op->src.offset == regs[op->dest.reg].offset) {
restore_reg(state, op->dest.reg);
} else if (op->src.reg == cfa->base &&
op->src.offset == regs[op->dest.reg].offset + cfa->offset) {
restore_reg(state, op->dest.reg);
}
break;
default:
WARN_FUNC("unknown stack-related instruction",
insn->sec, insn->offset);
return -1;
}
break;
case OP_DEST_PUSH:
state->stack_size += 8;
if (cfa->base == CFI_SP)
cfa->offset += 8;
if (op->src.type != OP_SRC_REG)
break;
if (state->drap) {
if (op->src.reg == cfa->base && op->src.reg == state->drap_reg) {
cfa->base = CFI_BP_INDIRECT;
cfa->offset = -state->stack_size;
state->drap_offset = -state->stack_size;
} else if (op->src.reg == CFI_BP && cfa->base == state->drap_reg) {
state->stack_size = 0;
} else if (regs[op->src.reg].base == CFI_UNDEFINED) {
save_reg(state, op->src.reg, CFI_BP, -state->stack_size);
}
} else {
save_reg(state, op->src.reg, CFI_CFA, -state->stack_size);
}
if (!no_fp && insn->func && op->src.reg == CFI_BP &&
cfa->base != CFI_BP)
state->bp_scratch = true;
break;
case OP_DEST_REG_INDIRECT:
if (state->drap) {
if (op->src.reg == cfa->base && op->src.reg == state->drap_reg) {
cfa->base = CFI_BP_INDIRECT;
cfa->offset = op->dest.offset;
state->drap_offset = op->dest.offset;
}
else if (regs[op->src.reg].base == CFI_UNDEFINED) {
save_reg(state, op->src.reg, CFI_BP, op->dest.offset);
}
} else if (op->dest.reg == cfa->base) {
save_reg(state, op->src.reg, CFI_CFA,
op->dest.offset - state->cfa.offset);
}
break;
case OP_DEST_LEAVE:
if ((!state->drap && cfa->base != CFI_BP) ||
(state->drap && cfa->base != state->drap_reg)) {
WARN_FUNC("leave instruction with modified stack frame",
insn->sec, insn->offset);
return -1;
}
state->stack_size = -state->regs[CFI_BP].offset - 8;
restore_reg(state, CFI_BP);
if (!state->drap) {
cfa->base = CFI_SP;
cfa->offset -= 8;
}
break;
case OP_DEST_MEM:
if (op->src.type != OP_SRC_POP) {
WARN_FUNC("unknown stack-related memory operation",
insn->sec, insn->offset);
return -1;
}
state->stack_size -= 8;
if (cfa->base == CFI_SP)
cfa->offset -= 8;
break;
default:
WARN_FUNC("unknown stack-related instruction",
insn->sec, insn->offset);
return -1;
}
return 0;
}
static bool insn_state_match(struct instruction *insn, struct insn_state *state)
{
struct insn_state *state1 = &insn->state, *state2 = state;
int i;
if (memcmp(&state1->cfa, &state2->cfa, sizeof(state1->cfa))) {
WARN_FUNC("stack state mismatch: cfa1=%d%+d cfa2=%d%+d",
insn->sec, insn->offset,
state1->cfa.base, state1->cfa.offset,
state2->cfa.base, state2->cfa.offset);
} else if (memcmp(&state1->regs, &state2->regs, sizeof(state1->regs))) {
for (i = 0; i < CFI_NUM_REGS; i++) {
if (!memcmp(&state1->regs[i], &state2->regs[i],
sizeof(struct cfi_reg)))
continue;
WARN_FUNC("stack state mismatch: reg1[%d]=%d%+d reg2[%d]=%d%+d",
insn->sec, insn->offset,
i, state1->regs[i].base, state1->regs[i].offset,
i, state2->regs[i].base, state2->regs[i].offset);
break;
}
} else if (state1->type != state2->type) {
WARN_FUNC("stack state mismatch: type1=%d type2=%d",
insn->sec, insn->offset, state1->type, state2->type);
} else if (state1->drap != state2->drap ||
(state1->drap && state1->drap_reg != state2->drap_reg) ||
(state1->drap && state1->drap_offset != state2->drap_offset)) {
WARN_FUNC("stack state mismatch: drap1=%d(%d,%d) drap2=%d(%d,%d)",
insn->sec, insn->offset,
state1->drap, state1->drap_reg, state1->drap_offset,
state2->drap, state2->drap_reg, state2->drap_offset);
} else
return true;
return false;
}
static int validate_branch(struct objtool_file *file, struct instruction *first,
struct insn_state state)
{
struct alternative *alt;
struct instruction *insn, *next_insn;
struct section *sec;
struct symbol *func = NULL;
int ret;
insn = first;
sec = insn->sec;
if (insn->alt_group && list_empty(&insn->alts)) {
WARN_FUNC("don't know how to handle branch to middle of alternative instruction group",
sec, insn->offset);
return 1;
}
while (1) {
next_insn = next_insn_same_sec(file, insn);
if (file->c_file && func && insn->func && func != insn->func) {
WARN("%s() falls through to next function %s()",
func->name, insn->func->name);
return 1;
}
if (insn->func)
func = insn->func;
if (func && insn->ignore) {
WARN_FUNC("BUG: why am I validating an ignored function?",
sec, insn->offset);
return 1;
}
if (insn->visited) {
if (!insn->hint && !insn_state_match(insn, &state))
return 1;
return 0;
}
if (insn->hint) {
if (insn->restore) {
struct instruction *save_insn, *i;
i = insn;
save_insn = NULL;
func_for_each_insn_continue_reverse(file, func, i) {
if (i->save) {
save_insn = i;
break;
}
}
if (!save_insn) {
WARN_FUNC("no corresponding CFI save for CFI restore",
sec, insn->offset);
return 1;
}
if (!save_insn->visited) {
if (insn == first)
return 0;
WARN_FUNC("objtool isn't smart enough to handle this CFI save/restore combo",
sec, insn->offset);
return 1;
}
insn->state = save_insn->state;
}
state = insn->state;
} else
insn->state = state;
insn->visited = true;
list_for_each_entry(alt, &insn->alts, list) {
ret = validate_branch(file, alt->insn, state);
if (ret)
return 1;
}
switch (insn->type) {
case INSN_RETURN:
if (func && has_modified_stack_frame(&state)) {
WARN_FUNC("return with modified stack frame",
sec, insn->offset);
return 1;
}
if (state.bp_scratch) {
WARN("%s uses BP as a scratch register",
insn->func->name);
return 1;
}
return 0;
case INSN_CALL:
if (is_fentry_call(insn))
break;
ret = dead_end_function(file, insn->call_dest);
if (ret == 1)
return 0;
if (ret == -1)
return 1;
case INSN_CALL_DYNAMIC:
if (!no_fp && func && !has_valid_stack_frame(&state)) {
WARN_FUNC("call without frame pointer save/setup",
sec, insn->offset);
return 1;
}
break;
case INSN_JUMP_CONDITIONAL:
case INSN_JUMP_UNCONDITIONAL:
if (insn->jump_dest &&
(!func || !insn->jump_dest->func ||
func == insn->jump_dest->func)) {
ret = validate_branch(file, insn->jump_dest,
state);
if (ret)
return 1;
} else if (func && has_modified_stack_frame(&state)) {
WARN_FUNC("sibling call from callable instruction with modified stack frame",
sec, insn->offset);
return 1;
}
if (insn->type == INSN_JUMP_UNCONDITIONAL)
return 0;
break;
case INSN_JUMP_DYNAMIC:
if (func && list_empty(&insn->alts) &&
has_modified_stack_frame(&state)) {
WARN_FUNC("sibling call from callable instruction with modified stack frame",
sec, insn->offset);
return 1;
}
return 0;
case INSN_CONTEXT_SWITCH:
if (func && (!next_insn || !next_insn->hint)) {
WARN_FUNC("unsupported instruction in callable function",
sec, insn->offset);
return 1;
}
return 0;
case INSN_STACK:
if (update_insn_state(insn, &state))
return 1;
break;
default:
break;
}
if (insn->dead_end)
return 0;
insn = next_insn;
if (!insn) {
WARN("%s: unexpected end of section", sec->name);
return 1;
}
}
return 0;
}
static int validate_unwind_hints(struct objtool_file *file)
{
struct instruction *insn;
int ret, warnings = 0;
struct insn_state state;
if (!file->hints)
return 0;
clear_insn_state(&state);
for_each_insn(file, insn) {
if (insn->hint && !insn->visited) {
ret = validate_branch(file, insn, state);
warnings += ret;
}
}
return warnings;
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
static bool ignore_unreachable_insn(struct instruction *insn)
{
int i;
if (insn->ignore || insn->type == INSN_NOP)
return true;
if (!strcmp(insn->sec->name, ".fixup") ||
!strcmp(insn->sec->name, ".altinstr_replacement") ||
!strcmp(insn->sec->name, ".altinstr_aux"))
return true;
if (!insn->func)
return false;
for (i = 0; i < 5; i++) {
if (is_kasan_insn(insn) || is_ubsan_insn(insn))
return true;
if (insn->type == INSN_JUMP_UNCONDITIONAL && insn->jump_dest) {
insn = insn->jump_dest;
continue;
}
if (insn->offset + insn->len >= insn->func->offset + insn->func->len)
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
struct insn_state state;
int ret, warnings = 0;
clear_insn_state(&state);
state.cfa = initial_func_cfi.cfa;
memcpy(&state.regs, &initial_func_cfi.regs,
CFI_NUM_REGS * sizeof(struct cfi_reg));
state.stack_size = initial_func_cfi.cfa.offset;
for_each_sec(file, sec) {
list_for_each_entry(func, &sec->symbol_list, list) {
if (func->type != STT_FUNC)
continue;
insn = find_insn(file, sec, func->offset);
if (!insn || insn->ignore)
continue;
ret = validate_branch(file, insn, state);
warnings += ret;
}
}
return warnings;
}
static int validate_reachable_instructions(struct objtool_file *file)
{
struct instruction *insn;
if (file->ignore_unreachables)
return 0;
for_each_insn(file, insn) {
if (insn->visited || ignore_unreachable_insn(insn))
continue;
WARN_FUNC("unreachable instruction", insn->sec, insn->offset);
return 1;
}
return 0;
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
int check(const char *_objname, bool _no_fp, bool no_unreachable, bool orc)
{
struct objtool_file file;
int ret, warnings = 0;
objname = _objname;
no_fp = _no_fp;
file.elf = elf_open(objname, orc ? O_RDWR : O_RDONLY);
if (!file.elf)
return 1;
INIT_LIST_HEAD(&file.insn_list);
hash_init(file.insn_hash);
file.whitelist = find_section_by_name(file.elf, ".discard.func_stack_frame_non_standard");
file.rodata = find_section_by_name(file.elf, ".rodata");
file.c_file = find_section_by_name(file.elf, ".comment");
file.ignore_unreachables = no_unreachable;
file.hints = false;
arch_initial_func_cfi_state(&initial_func_cfi);
ret = decode_sections(&file);
if (ret < 0)
goto out;
warnings += ret;
if (list_empty(&file.insn_list))
goto out;
ret = validate_functions(&file);
if (ret < 0)
goto out;
warnings += ret;
ret = validate_unwind_hints(&file);
if (ret < 0)
goto out;
warnings += ret;
if (!warnings) {
ret = validate_reachable_instructions(&file);
if (ret < 0)
goto out;
warnings += ret;
}
if (orc) {
ret = create_orc(&file);
if (ret < 0)
goto out;
ret = create_orc_sections(&file);
if (ret < 0)
goto out;
ret = elf_write(file.elf);
if (ret < 0)
goto out;
}
out:
cleanup(&file);
if (ret || warnings)
return 0;
return 0;
}
