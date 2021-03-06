static int debuginfo__init_offline_dwarf(struct debuginfo *dbg,
const char *path)
{
int fd;
fd = open(path, O_RDONLY);
if (fd < 0)
return fd;
dbg->dwfl = dwfl_begin(&offline_callbacks);
if (!dbg->dwfl)
goto error;
dbg->mod = dwfl_report_offline(dbg->dwfl, "", "", fd);
if (!dbg->mod)
goto error;
dbg->dbg = dwfl_module_getdwarf(dbg->mod, &dbg->bias);
if (!dbg->dbg)
goto error;
return 0;
error:
if (dbg->dwfl)
dwfl_end(dbg->dwfl);
else
close(fd);
memset(dbg, 0, sizeof(*dbg));
return -ENOENT;
}
static struct debuginfo *__debuginfo__new(const char *path)
{
struct debuginfo *dbg = zalloc(sizeof(*dbg));
if (!dbg)
return NULL;
if (debuginfo__init_offline_dwarf(dbg, path) < 0)
zfree(&dbg);
if (dbg)
pr_debug("Open Debuginfo file: %s\n", path);
return dbg;
}
struct debuginfo *debuginfo__new(const char *path)
{
enum dso_binary_type *type;
char buf[PATH_MAX], nil = '\0';
struct dso *dso;
struct debuginfo *dinfo = NULL;
dso = dso__new(path);
if (!dso)
goto out;
for (type = distro_dwarf_types;
!dinfo && *type != DSO_BINARY_TYPE__NOT_FOUND;
type++) {
if (dso__read_binary_type_filename(dso, *type, &nil,
buf, PATH_MAX) < 0)
continue;
dinfo = __debuginfo__new(buf);
}
dso__delete(dso);
out:
return dinfo ? : __debuginfo__new(path);
}
void debuginfo__delete(struct debuginfo *dbg)
{
if (dbg) {
if (dbg->dwfl)
dwfl_end(dbg->dwfl);
free(dbg);
}
}
static struct probe_trace_arg_ref *alloc_trace_arg_ref(long offs)
{
struct probe_trace_arg_ref *ref;
ref = zalloc(sizeof(struct probe_trace_arg_ref));
if (ref != NULL)
ref->offset = offs;
return ref;
}
static int convert_variable_location(Dwarf_Die *vr_die, Dwarf_Addr addr,
Dwarf_Op *fb_ops, Dwarf_Die *sp_die,
struct probe_trace_arg *tvar)
{
Dwarf_Attribute attr;
Dwarf_Addr tmp = 0;
Dwarf_Op *op;
size_t nops;
unsigned int regn;
Dwarf_Word offs = 0;
bool ref = false;
const char *regs;
int ret;
if (dwarf_attr(vr_die, DW_AT_external, &attr) != NULL)
goto static_var;
if (dwarf_attr(vr_die, DW_AT_location, &attr) == NULL)
return -EINVAL;
if (dwarf_getlocation_addr(&attr, addr, &op, &nops, 1) <= 0) {
ret = dwarf_entrypc(sp_die, &tmp);
if (ret || addr != tmp ||
dwarf_tag(vr_die) != DW_TAG_formal_parameter ||
dwarf_highpc(sp_die, &tmp))
return -ENOENT;
for (addr += 1; addr <= tmp; addr++) {
if (dwarf_getlocation_addr(&attr, addr, &op,
&nops, 1) > 0)
goto found;
}
return -ENOENT;
}
found:
if (nops == 0)
return -ENOENT;
if (op->atom == DW_OP_addr) {
static_var:
if (!tvar)
return 0;
ret = strlen(dwarf_diename(vr_die));
tvar->value = zalloc(ret + 2);
if (tvar->value == NULL)
return -ENOMEM;
snprintf(tvar->value, ret + 2, "@%s", dwarf_diename(vr_die));
tvar->ref = alloc_trace_arg_ref((long)offs);
if (tvar->ref == NULL)
return -ENOMEM;
return 0;
}
if (op->atom == DW_OP_fbreg) {
if (fb_ops == NULL)
return -ENOTSUP;
ref = true;
offs = op->number;
op = &fb_ops[0];
}
if (op->atom >= DW_OP_breg0 && op->atom <= DW_OP_breg31) {
regn = op->atom - DW_OP_breg0;
offs += op->number;
ref = true;
} else if (op->atom >= DW_OP_reg0 && op->atom <= DW_OP_reg31) {
regn = op->atom - DW_OP_reg0;
} else if (op->atom == DW_OP_bregx) {
regn = op->number;
offs += op->number2;
ref = true;
} else if (op->atom == DW_OP_regx) {
regn = op->number;
} else {
pr_debug("DW_OP %x is not supported.\n", op->atom);
return -ENOTSUP;
}
if (!tvar)
return 0;
regs = get_arch_regstr(regn);
if (!regs) {
pr_warning("Mapping for the register number %u "
"missing on this architecture.\n", regn);
return -ERANGE;
}
tvar->value = strdup(regs);
if (tvar->value == NULL)
return -ENOMEM;
if (ref) {
tvar->ref = alloc_trace_arg_ref((long)offs);
if (tvar->ref == NULL)
return -ENOMEM;
}
return 0;
}
static int convert_variable_type(Dwarf_Die *vr_die,
struct probe_trace_arg *tvar,
const char *cast)
{
struct probe_trace_arg_ref **ref_ptr = &tvar->ref;
Dwarf_Die type;
char buf[16];
char sbuf[STRERR_BUFSIZE];
int bsize, boffs, total;
int ret;
if (cast && strcmp(cast, "string") != 0) {
tvar->type = strdup(cast);
return (tvar->type == NULL) ? -ENOMEM : 0;
}
bsize = dwarf_bitsize(vr_die);
if (bsize > 0) {
boffs = dwarf_bitoffset(vr_die);
total = dwarf_bytesize(vr_die);
if (boffs < 0 || total < 0)
return -ENOENT;
ret = snprintf(buf, 16, "b%d@%d/%zd", bsize, boffs,
BYTES_TO_BITS(total));
goto formatted;
}
if (die_get_real_type(vr_die, &type) == NULL) {
pr_warning("Failed to get a type information of %s.\n",
dwarf_diename(vr_die));
return -ENOENT;
}
pr_debug("%s type is %s.\n",
dwarf_diename(vr_die), dwarf_diename(&type));
if (cast && strcmp(cast, "string") == 0) {
ret = dwarf_tag(&type);
if (ret != DW_TAG_pointer_type &&
ret != DW_TAG_array_type) {
pr_warning("Failed to cast into string: "
"%s(%s) is not a pointer nor array.\n",
dwarf_diename(vr_die), dwarf_diename(&type));
return -EINVAL;
}
if (die_get_real_type(&type, &type) == NULL) {
pr_warning("Failed to get a type"
" information.\n");
return -ENOENT;
}
if (ret == DW_TAG_pointer_type) {
while (*ref_ptr)
ref_ptr = &(*ref_ptr)->next;
*ref_ptr = zalloc(sizeof(struct probe_trace_arg_ref));
if (*ref_ptr == NULL) {
pr_warning("Out of memory error\n");
return -ENOMEM;
}
}
if (!die_compare_name(&type, "char") &&
!die_compare_name(&type, "unsigned char")) {
pr_warning("Failed to cast into string: "
"%s is not (unsigned) char *.\n",
dwarf_diename(vr_die));
return -EINVAL;
}
tvar->type = strdup(cast);
return (tvar->type == NULL) ? -ENOMEM : 0;
}
ret = dwarf_bytesize(&type);
if (ret <= 0)
return 0;
ret = BYTES_TO_BITS(ret);
if (ret > MAX_BASIC_TYPE_BITS) {
pr_info("%s exceeds max-bitwidth. Cut down to %d bits.\n",
dwarf_diename(&type), MAX_BASIC_TYPE_BITS);
ret = MAX_BASIC_TYPE_BITS;
}
ret = snprintf(buf, 16, "%c%d",
die_is_signed_type(&type) ? 's' : 'u', ret);
formatted:
if (ret < 0 || ret >= 16) {
if (ret >= 16)
ret = -E2BIG;
pr_warning("Failed to convert variable type: %s\n",
strerror_r(-ret, sbuf, sizeof(sbuf)));
return ret;
}
tvar->type = strdup(buf);
if (tvar->type == NULL)
return -ENOMEM;
return 0;
}
static int convert_variable_fields(Dwarf_Die *vr_die, const char *varname,
struct perf_probe_arg_field *field,
struct probe_trace_arg_ref **ref_ptr,
Dwarf_Die *die_mem)
{
struct probe_trace_arg_ref *ref = *ref_ptr;
Dwarf_Die type;
Dwarf_Word offs;
int ret, tag;
pr_debug("converting %s in %s\n", field->name, varname);
if (die_get_real_type(vr_die, &type) == NULL) {
pr_warning("Failed to get the type of %s.\n", varname);
return -ENOENT;
}
pr_debug2("Var real type: (%x)\n", (unsigned)dwarf_dieoffset(&type));
tag = dwarf_tag(&type);
if (field->name[0] == '[' &&
(tag == DW_TAG_array_type || tag == DW_TAG_pointer_type)) {
if (field->next)
memcpy(die_mem, &type, sizeof(*die_mem));
if (die_get_real_type(&type, &type) == NULL) {
pr_warning("Failed to get the type of %s.\n", varname);
return -ENOENT;
}
pr_debug2("Array real type: (%x)\n",
(unsigned)dwarf_dieoffset(&type));
if (tag == DW_TAG_pointer_type) {
ref = zalloc(sizeof(struct probe_trace_arg_ref));
if (ref == NULL)
return -ENOMEM;
if (*ref_ptr)
(*ref_ptr)->next = ref;
else
*ref_ptr = ref;
}
ref->offset += dwarf_bytesize(&type) * field->index;
if (!field->next)
memcpy(die_mem, vr_die, sizeof(*die_mem));
goto next;
} else if (tag == DW_TAG_pointer_type) {
if (!field->ref) {
pr_err("Semantic error: %s must be referred by '->'\n",
field->name);
return -EINVAL;
}
if (die_get_real_type(&type, &type) == NULL) {
pr_warning("Failed to get the type of %s.\n", varname);
return -ENOENT;
}
tag = dwarf_tag(&type);
if (tag != DW_TAG_structure_type && tag != DW_TAG_union_type) {
pr_warning("%s is not a data structure nor an union.\n",
varname);
return -EINVAL;
}
ref = zalloc(sizeof(struct probe_trace_arg_ref));
if (ref == NULL)
return -ENOMEM;
if (*ref_ptr)
(*ref_ptr)->next = ref;
else
*ref_ptr = ref;
} else {
if (tag != DW_TAG_structure_type && tag != DW_TAG_union_type) {
pr_warning("%s is not a data structure nor an union.\n",
varname);
return -EINVAL;
}
if (field->name[0] == '[') {
pr_err("Semantic error: %s is not a pointor"
" nor array.\n", varname);
return -EINVAL;
}
if (field->ref) {
pr_err("Semantic error: %s must be referred by '.'\n",
field->name);
return -EINVAL;
}
if (!ref) {
pr_warning("Structure on a register is not "
"supported yet.\n");
return -ENOTSUP;
}
}
if (die_find_member(&type, field->name, die_mem) == NULL) {
pr_warning("%s(type:%s) has no member %s.\n", varname,
dwarf_diename(&type), field->name);
return -EINVAL;
}
if (tag == DW_TAG_union_type) {
offs = 0;
} else {
ret = die_get_data_member_location(die_mem, &offs);
if (ret < 0) {
pr_warning("Failed to get the offset of %s.\n",
field->name);
return ret;
}
}
ref->offset += (long)offs;
next:
if (field->next)
return convert_variable_fields(die_mem, field->name,
field->next, &ref, die_mem);
else
return 0;
}
static int convert_variable(Dwarf_Die *vr_die, struct probe_finder *pf)
{
Dwarf_Die die_mem;
int ret;
pr_debug("Converting variable %s into trace event.\n",
dwarf_diename(vr_die));
ret = convert_variable_location(vr_die, pf->addr, pf->fb_ops,
&pf->sp_die, pf->tvar);
if (ret == -ENOENT || ret == -EINVAL)
pr_err("Failed to find the location of %s at this address.\n"
" Perhaps, it has been optimized out.\n", pf->pvar->var);
else if (ret == -ENOTSUP)
pr_err("Sorry, we don't support this variable location yet.\n");
else if (ret == 0 && pf->pvar->field) {
ret = convert_variable_fields(vr_die, pf->pvar->var,
pf->pvar->field, &pf->tvar->ref,
&die_mem);
vr_die = &die_mem;
}
if (ret == 0)
ret = convert_variable_type(vr_die, pf->tvar, pf->pvar->type);
return ret;
}
static int find_variable(Dwarf_Die *sc_die, struct probe_finder *pf)
{
Dwarf_Die vr_die;
char buf[32], *ptr;
int ret = 0;
if (!is_c_varname(pf->pvar->var)) {
pf->tvar->value = strdup(pf->pvar->var);
if (pf->tvar->value == NULL)
return -ENOMEM;
if (pf->pvar->type) {
pf->tvar->type = strdup(pf->pvar->type);
if (pf->tvar->type == NULL)
return -ENOMEM;
}
if (pf->pvar->name) {
pf->tvar->name = strdup(pf->pvar->name);
if (pf->tvar->name == NULL)
return -ENOMEM;
} else
pf->tvar->name = NULL;
return 0;
}
if (pf->pvar->name)
pf->tvar->name = strdup(pf->pvar->name);
else {
ret = synthesize_perf_probe_arg(pf->pvar, buf, 32);
if (ret < 0)
return ret;
ptr = strchr(buf, ':');
if (ptr)
*ptr = '_';
pf->tvar->name = strdup(buf);
}
if (pf->tvar->name == NULL)
return -ENOMEM;
pr_debug("Searching '%s' variable in context.\n", pf->pvar->var);
if (!die_find_variable_at(sc_die, pf->pvar->var, pf->addr, &vr_die)) {
if (!die_find_variable_at(&pf->cu_die, pf->pvar->var, 0, &vr_die))
pr_warning("Failed to find '%s' in this function.\n",
pf->pvar->var);
ret = -ENOENT;
}
if (ret >= 0)
ret = convert_variable(&vr_die, pf);
return ret;
}
static int convert_to_trace_point(Dwarf_Die *sp_die, Dwfl_Module *mod,
Dwarf_Addr paddr, bool retprobe,
struct probe_trace_point *tp)
{
Dwarf_Addr eaddr, highaddr;
GElf_Sym sym;
const char *symbol;
if (dwarf_entrypc(sp_die, &eaddr) != 0) {
pr_warning("Failed to get entry address of %s\n",
dwarf_diename(sp_die));
return -ENOENT;
}
if (dwarf_highpc(sp_die, &highaddr) != 0) {
pr_warning("Failed to get end address of %s\n",
dwarf_diename(sp_die));
return -ENOENT;
}
if (paddr > highaddr) {
pr_warning("Offset specified is greater than size of %s\n",
dwarf_diename(sp_die));
return -EINVAL;
}
symbol = dwarf_diename(sp_die);
if (!symbol) {
symbol = dwfl_module_addrsym(mod, paddr, &sym, NULL);
if (!symbol) {
pr_warning("Failed to find symbol at 0x%lx\n",
(unsigned long)paddr);
return -ENOENT;
}
eaddr = sym.st_value;
}
tp->offset = (unsigned long)(paddr - eaddr);
tp->address = (unsigned long)paddr;
tp->symbol = strdup(symbol);
if (!tp->symbol)
return -ENOMEM;
if (retprobe) {
if (eaddr != paddr) {
pr_warning("Return probe must be on the head of"
" a real function.\n");
return -EINVAL;
}
tp->retprobe = true;
}
return 0;
}
static int call_probe_finder(Dwarf_Die *sc_die, struct probe_finder *pf)
{
Dwarf_Attribute fb_attr;
size_t nops;
int ret;
if (!sc_die) {
pr_err("Caller must pass a scope DIE. Program error.\n");
return -EINVAL;
}
if (!die_is_func_def(sc_die)) {
if (!die_find_realfunc(&pf->cu_die, pf->addr, &pf->sp_die)) {
pr_warning("Failed to find probe point in any "
"functions.\n");
return -ENOENT;
}
} else
memcpy(&pf->sp_die, sc_die, sizeof(Dwarf_Die));
dwarf_attr(&pf->sp_die, DW_AT_frame_base, &fb_attr);
ret = dwarf_getlocation_addr(&fb_attr, pf->addr, &pf->fb_ops, &nops, 1);
if (ret <= 0 || nops == 0) {
pf->fb_ops = NULL;
#if _ELFUTILS_PREREQ(0, 142)
} else if (nops == 1 && pf->fb_ops[0].atom == DW_OP_call_frame_cfa &&
pf->cfi != NULL) {
Dwarf_Frame *frame;
if (dwarf_cfi_addrframe(pf->cfi, pf->addr, &frame) != 0 ||
dwarf_frame_cfa(frame, &pf->fb_ops, &nops) != 0) {
pr_warning("Failed to get call frame on 0x%jx\n",
(uintmax_t)pf->addr);
return -ENOENT;
}
#endif
}
ret = pf->callback(sc_die, pf);
pf->fb_ops = NULL;
return ret;
}
static int find_best_scope_cb(Dwarf_Die *fn_die, void *data)
{
struct find_scope_param *fsp = data;
const char *file;
int lno;
if (fsp->file) {
file = dwarf_decl_file(fn_die);
if (!file || strcmp(fsp->file, file) != 0)
return 0;
}
if (fsp->function) {
if (die_compare_name(fn_die, fsp->function)) {
memcpy(fsp->die_mem, fn_die, sizeof(Dwarf_Die));
fsp->found = true;
return 1;
}
} else {
dwarf_decl_line(fn_die, &lno);
if (lno < fsp->line && fsp->diff > fsp->line - lno) {
fsp->diff = fsp->line - lno;
memcpy(fsp->die_mem, fn_die, sizeof(Dwarf_Die));
fsp->found = true;
}
}
return 0;
}
static Dwarf_Die *find_best_scope(struct probe_finder *pf, Dwarf_Die *die_mem)
{
struct find_scope_param fsp = {
.function = pf->pev->point.function,
.file = pf->fname,
.line = pf->lno,
.diff = INT_MAX,
.die_mem = die_mem,
.found = false,
};
cu_walk_functions_at(&pf->cu_die, pf->addr, find_best_scope_cb, &fsp);
return fsp.found ? die_mem : NULL;
}
static int probe_point_line_walker(const char *fname, int lineno,
Dwarf_Addr addr, void *data)
{
struct probe_finder *pf = data;
Dwarf_Die *sc_die, die_mem;
int ret;
if (lineno != pf->lno || strtailcmp(fname, pf->fname) != 0)
return 0;
pf->addr = addr;
sc_die = find_best_scope(pf, &die_mem);
if (!sc_die) {
pr_warning("Failed to find scope of probe point.\n");
return -ENOENT;
}
ret = call_probe_finder(sc_die, pf);
return ret < 0 ? ret : 0;
}
static int find_probe_point_by_line(struct probe_finder *pf)
{
return die_walk_lines(&pf->cu_die, probe_point_line_walker, pf);
}
static int find_lazy_match_lines(struct intlist *list,
const char *fname, const char *pat)
{
FILE *fp;
char *line = NULL;
size_t line_len;
ssize_t len;
int count = 0, linenum = 1;
char sbuf[STRERR_BUFSIZE];
fp = fopen(fname, "r");
if (!fp) {
pr_warning("Failed to open %s: %s\n", fname,
strerror_r(errno, sbuf, sizeof(sbuf)));
return -errno;
}
while ((len = getline(&line, &line_len, fp)) > 0) {
if (line[len - 1] == '\n')
line[len - 1] = '\0';
if (strlazymatch(line, pat)) {
intlist__add(list, linenum);
count++;
}
linenum++;
}
if (ferror(fp))
count = -errno;
free(line);
fclose(fp);
if (count == 0)
pr_debug("No matched lines found in %s.\n", fname);
return count;
}
static int probe_point_lazy_walker(const char *fname, int lineno,
Dwarf_Addr addr, void *data)
{
struct probe_finder *pf = data;
Dwarf_Die *sc_die, die_mem;
int ret;
if (!intlist__has_entry(pf->lcache, lineno) ||
strtailcmp(fname, pf->fname) != 0)
return 0;
pr_debug("Probe line found: line:%d addr:0x%llx\n",
lineno, (unsigned long long)addr);
pf->addr = addr;
pf->lno = lineno;
sc_die = find_best_scope(pf, &die_mem);
if (!sc_die) {
pr_warning("Failed to find scope of probe point.\n");
return -ENOENT;
}
ret = call_probe_finder(sc_die, pf);
return ret < 0 ? ret : 0;
}
static int find_probe_point_lazy(Dwarf_Die *sp_die, struct probe_finder *pf)
{
int ret = 0;
if (intlist__empty(pf->lcache)) {
ret = find_lazy_match_lines(pf->lcache, pf->fname,
pf->pev->point.lazy_line);
if (ret <= 0)
return ret;
}
return die_walk_lines(sp_die, probe_point_lazy_walker, pf);
}
static int probe_point_inline_cb(Dwarf_Die *in_die, void *data)
{
struct probe_finder *pf = data;
struct perf_probe_point *pp = &pf->pev->point;
Dwarf_Addr addr;
int ret;
if (pp->lazy_line)
ret = find_probe_point_lazy(in_die, pf);
else {
if (dwarf_entrypc(in_die, &addr) != 0) {
pr_warning("Failed to get entry address of %s.\n",
dwarf_diename(in_die));
return -ENOENT;
}
pf->addr = addr;
pf->addr += pp->offset;
pr_debug("found inline addr: 0x%jx\n",
(uintmax_t)pf->addr);
ret = call_probe_finder(in_die, pf);
}
return ret;
}
static int probe_point_search_cb(Dwarf_Die *sp_die, void *data)
{
struct dwarf_callback_param *param = data;
struct probe_finder *pf = param->data;
struct perf_probe_point *pp = &pf->pev->point;
if (!die_is_func_def(sp_die) ||
!die_compare_name(sp_die, pp->function))
return DWARF_CB_OK;
if (pp->file && strtailcmp(pp->file, dwarf_decl_file(sp_die)))
return DWARF_CB_OK;
pf->fname = dwarf_decl_file(sp_die);
if (pp->line) {
dwarf_decl_line(sp_die, &pf->lno);
pf->lno += pp->line;
param->retval = find_probe_point_by_line(pf);
} else if (!dwarf_func_inline(sp_die)) {
if (pp->lazy_line)
param->retval = find_probe_point_lazy(sp_die, pf);
else {
if (dwarf_entrypc(sp_die, &pf->addr) != 0) {
pr_warning("Failed to get entry address of "
"%s.\n", dwarf_diename(sp_die));
param->retval = -ENOENT;
return DWARF_CB_ABORT;
}
pf->addr += pp->offset;
param->retval = call_probe_finder(sp_die, pf);
}
} else
param->retval = die_walk_instances(sp_die,
probe_point_inline_cb, (void *)pf);
return DWARF_CB_ABORT;
}
static int find_probe_point_by_func(struct probe_finder *pf)
{
struct dwarf_callback_param _param = {.data = (void *)pf,
.retval = 0};
dwarf_getfuncs(&pf->cu_die, probe_point_search_cb, &_param, 0);
return _param.retval;
}
static int pubname_search_cb(Dwarf *dbg, Dwarf_Global *gl, void *data)
{
struct pubname_callback_param *param = data;
if (dwarf_offdie(dbg, gl->die_offset, param->sp_die)) {
if (dwarf_tag(param->sp_die) != DW_TAG_subprogram)
return DWARF_CB_OK;
if (die_compare_name(param->sp_die, param->function)) {
if (!dwarf_offdie(dbg, gl->cu_offset, param->cu_die))
return DWARF_CB_OK;
if (param->file &&
strtailcmp(param->file, dwarf_decl_file(param->sp_die)))
return DWARF_CB_OK;
param->found = 1;
return DWARF_CB_ABORT;
}
}
return DWARF_CB_OK;
}
static int debuginfo__find_probes(struct debuginfo *dbg,
struct probe_finder *pf)
{
struct perf_probe_point *pp = &pf->pev->point;
Dwarf_Off off, noff;
size_t cuhl;
Dwarf_Die *diep;
int ret = 0;
#if _ELFUTILS_PREREQ(0, 142)
pf->cfi = dwarf_getcfi_elf(dwarf_getelf(dbg->dbg));
#endif
off = 0;
pf->lcache = intlist__new(NULL);
if (!pf->lcache)
return -ENOMEM;
if (pp->function) {
struct pubname_callback_param pubname_param = {
.function = pp->function,
.file = pp->file,
.cu_die = &pf->cu_die,
.sp_die = &pf->sp_die,
.found = 0,
};
struct dwarf_callback_param probe_param = {
.data = pf,
};
dwarf_getpubnames(dbg->dbg, pubname_search_cb,
&pubname_param, 0);
if (pubname_param.found) {
ret = probe_point_search_cb(&pf->sp_die, &probe_param);
if (ret)
goto found;
}
}
while (!dwarf_nextcu(dbg->dbg, off, &noff, &cuhl, NULL, NULL, NULL)) {
diep = dwarf_offdie(dbg->dbg, off + cuhl, &pf->cu_die);
if (!diep)
continue;
if (pp->file)
pf->fname = cu_find_realpath(&pf->cu_die, pp->file);
else
pf->fname = NULL;
if (!pp->file || pf->fname) {
if (pp->function)
ret = find_probe_point_by_func(pf);
else if (pp->lazy_line)
ret = find_probe_point_lazy(NULL, pf);
else {
pf->lno = pp->line;
ret = find_probe_point_by_line(pf);
}
if (ret < 0)
break;
}
off = noff;
}
found:
intlist__delete(pf->lcache);
pf->lcache = NULL;
return ret;
}
static int copy_variables_cb(Dwarf_Die *die_mem, void *data)
{
struct local_vars_finder *vf = data;
struct probe_finder *pf = vf->pf;
int tag;
tag = dwarf_tag(die_mem);
if (tag == DW_TAG_formal_parameter ||
tag == DW_TAG_variable) {
if (convert_variable_location(die_mem, vf->pf->addr,
vf->pf->fb_ops, &pf->sp_die,
NULL) == 0) {
vf->args[vf->nargs].var = (char *)dwarf_diename(die_mem);
if (vf->args[vf->nargs].var == NULL) {
vf->ret = -ENOMEM;
return DIE_FIND_CB_END;
}
pr_debug(" %s", vf->args[vf->nargs].var);
vf->nargs++;
}
}
if (dwarf_haspc(die_mem, vf->pf->addr))
return DIE_FIND_CB_CONTINUE;
else
return DIE_FIND_CB_SIBLING;
}
static int expand_probe_args(Dwarf_Die *sc_die, struct probe_finder *pf,
struct perf_probe_arg *args)
{
Dwarf_Die die_mem;
int i;
int n = 0;
struct local_vars_finder vf = {.pf = pf, .args = args,
.max_args = MAX_PROBE_ARGS, .ret = 0};
for (i = 0; i < pf->pev->nargs; i++) {
if (strcmp(pf->pev->args[i].var, "$vars") == 0) {
pr_debug("Expanding $vars into:");
vf.nargs = n;
die_find_child(sc_die, copy_variables_cb, (void *)&vf,
&die_mem);
pr_debug(" (%d)\n", vf.nargs - n);
if (vf.ret < 0)
return vf.ret;
n = vf.nargs;
} else {
args[n] = pf->pev->args[i];
n++;
}
}
return n;
}
static int add_probe_trace_event(Dwarf_Die *sc_die, struct probe_finder *pf)
{
struct trace_event_finder *tf =
container_of(pf, struct trace_event_finder, pf);
struct probe_trace_event *tev;
struct perf_probe_arg *args;
int ret, i;
if (tf->ntevs == tf->max_tevs) {
pr_warning("Too many( > %d) probe point found.\n",
tf->max_tevs);
return -ERANGE;
}
tev = &tf->tevs[tf->ntevs++];
ret = convert_to_trace_point(&pf->sp_die, tf->mod, pf->addr,
pf->pev->point.retprobe, &tev->point);
if (ret < 0)
return ret;
pr_debug("Probe point found: %s+%lu\n", tev->point.symbol,
tev->point.offset);
args = zalloc(sizeof(struct perf_probe_arg) * MAX_PROBE_ARGS);
if (args == NULL)
return -ENOMEM;
ret = expand_probe_args(sc_die, pf, args);
if (ret < 0)
goto end;
tev->nargs = ret;
tev->args = zalloc(sizeof(struct probe_trace_arg) * tev->nargs);
if (tev->args == NULL) {
ret = -ENOMEM;
goto end;
}
for (i = 0; i < tev->nargs; i++) {
pf->pvar = &args[i];
pf->tvar = &tev->args[i];
ret = find_variable(sc_die, pf);
if (ret != 0)
break;
}
end:
free(args);
return ret;
}
int debuginfo__find_trace_events(struct debuginfo *dbg,
struct perf_probe_event *pev,
struct probe_trace_event **tevs, int max_tevs)
{
struct trace_event_finder tf = {
.pf = {.pev = pev, .callback = add_probe_trace_event},
.mod = dbg->mod, .max_tevs = max_tevs};
int ret;
*tevs = zalloc(sizeof(struct probe_trace_event) * max_tevs);
if (*tevs == NULL)
return -ENOMEM;
tf.tevs = *tevs;
tf.ntevs = 0;
ret = debuginfo__find_probes(dbg, &tf.pf);
if (ret < 0) {
zfree(tevs);
return ret;
}
return (ret < 0) ? ret : tf.ntevs;
}
static int collect_variables_cb(Dwarf_Die *die_mem, void *data)
{
struct available_var_finder *af = data;
struct variable_list *vl;
char buf[MAX_VAR_LEN];
int tag, ret;
vl = &af->vls[af->nvls - 1];
tag = dwarf_tag(die_mem);
if (tag == DW_TAG_formal_parameter ||
tag == DW_TAG_variable) {
ret = convert_variable_location(die_mem, af->pf.addr,
af->pf.fb_ops, &af->pf.sp_die,
NULL);
if (ret == 0) {
ret = die_get_varname(die_mem, buf, MAX_VAR_LEN);
pr_debug2("Add new var: %s\n", buf);
if (ret > 0)
strlist__add(vl->vars, buf);
}
}
if (af->child && dwarf_haspc(die_mem, af->pf.addr))
return DIE_FIND_CB_CONTINUE;
else
return DIE_FIND_CB_SIBLING;
}
static int add_available_vars(Dwarf_Die *sc_die, struct probe_finder *pf)
{
struct available_var_finder *af =
container_of(pf, struct available_var_finder, pf);
struct variable_list *vl;
Dwarf_Die die_mem;
int ret;
if (af->nvls == af->max_vls) {
pr_warning("Too many( > %d) probe point found.\n", af->max_vls);
return -ERANGE;
}
vl = &af->vls[af->nvls++];
ret = convert_to_trace_point(&pf->sp_die, af->mod, pf->addr,
pf->pev->point.retprobe, &vl->point);
if (ret < 0)
return ret;
pr_debug("Probe point found: %s+%lu\n", vl->point.symbol,
vl->point.offset);
vl->vars = strlist__new(true, NULL);
if (vl->vars == NULL)
return -ENOMEM;
af->child = true;
die_find_child(sc_die, collect_variables_cb, (void *)af, &die_mem);
if (!af->externs)
goto out;
af->child = false;
die_find_child(&pf->cu_die, collect_variables_cb, (void *)af, &die_mem);
out:
if (strlist__empty(vl->vars)) {
strlist__delete(vl->vars);
vl->vars = NULL;
}
return ret;
}
int debuginfo__find_available_vars_at(struct debuginfo *dbg,
struct perf_probe_event *pev,
struct variable_list **vls,
int max_vls, bool externs)
{
struct available_var_finder af = {
.pf = {.pev = pev, .callback = add_available_vars},
.mod = dbg->mod,
.max_vls = max_vls, .externs = externs};
int ret;
*vls = zalloc(sizeof(struct variable_list) * max_vls);
if (*vls == NULL)
return -ENOMEM;
af.vls = *vls;
af.nvls = 0;
ret = debuginfo__find_probes(dbg, &af.pf);
if (ret < 0) {
while (af.nvls--) {
zfree(&af.vls[af.nvls].point.symbol);
strlist__delete(af.vls[af.nvls].vars);
}
zfree(vls);
return ret;
}
return (ret < 0) ? ret : af.nvls;
}
int debuginfo__find_probe_point(struct debuginfo *dbg, unsigned long addr,
struct perf_probe_point *ppt)
{
Dwarf_Die cudie, spdie, indie;
Dwarf_Addr _addr = 0, baseaddr = 0;
const char *fname = NULL, *func = NULL, *basefunc = NULL, *tmp;
int baseline = 0, lineno = 0, ret = 0;
addr += dbg->bias;
if (!dwarf_addrdie(dbg->dbg, (Dwarf_Addr)addr - dbg->bias, &cudie)) {
pr_warning("Failed to find debug information for address %lx\n",
addr);
ret = -EINVAL;
goto end;
}
cu_find_lineinfo(&cudie, addr, &fname, &lineno);
if (die_find_realfunc(&cudie, (Dwarf_Addr)addr, &spdie)) {
func = basefunc = dwarf_diename(&spdie);
if (!func ||
dwarf_entrypc(&spdie, &baseaddr) != 0 ||
dwarf_decl_line(&spdie, &baseline) != 0) {
lineno = 0;
goto post;
}
fname = dwarf_decl_file(&spdie);
if (addr == (unsigned long)baseaddr) {
lineno = baseline;
goto post;
}
while (die_find_top_inlinefunc(&spdie, (Dwarf_Addr)addr,
&indie)) {
if (dwarf_entrypc(&indie, &_addr) == 0 &&
_addr == addr) {
lineno = die_get_call_lineno(&indie);
fname = die_get_call_file(&indie);
break;
} else {
tmp = dwarf_diename(&indie);
if (!tmp ||
dwarf_decl_line(&indie, &baseline) != 0)
break;
func = tmp;
spdie = indie;
}
}
tmp = dwarf_decl_file(&spdie);
if (!tmp || strcmp(tmp, fname) != 0)
lineno = 0;
}
post:
if (lineno)
ppt->line = lineno - baseline;
else if (basefunc) {
ppt->offset = addr - (unsigned long)baseaddr;
func = basefunc;
}
if (func) {
ppt->function = strdup(func);
if (ppt->function == NULL) {
ret = -ENOMEM;
goto end;
}
}
if (fname) {
ppt->file = strdup(fname);
if (ppt->file == NULL) {
zfree(&ppt->function);
ret = -ENOMEM;
goto end;
}
}
end:
if (ret == 0 && (fname || func))
ret = 1;
return ret;
}
static int line_range_add_line(const char *src, unsigned int lineno,
struct line_range *lr)
{
if (!lr->path) {
lr->path = strdup(src);
if (lr->path == NULL)
return -ENOMEM;
}
return intlist__add(lr->line_list, lineno);
}
static int line_range_walk_cb(const char *fname, int lineno,
Dwarf_Addr addr __maybe_unused,
void *data)
{
struct line_finder *lf = data;
int err;
if ((strtailcmp(fname, lf->fname) != 0) ||
(lf->lno_s > lineno || lf->lno_e < lineno))
return 0;
err = line_range_add_line(fname, lineno, lf->lr);
if (err < 0 && err != -EEXIST)
return err;
return 0;
}
static int find_line_range_by_line(Dwarf_Die *sp_die, struct line_finder *lf)
{
int ret;
ret = die_walk_lines(sp_die ?: &lf->cu_die, line_range_walk_cb, lf);
if (ret >= 0)
if (!intlist__empty(lf->lr->line_list))
ret = lf->found = 1;
else
ret = 0;
else {
zfree(&lf->lr->path);
}
return ret;
}
static int line_range_inline_cb(Dwarf_Die *in_die, void *data)
{
int ret = find_line_range_by_line(in_die, data);
return ret < 0 ? ret : 0;
}
static int line_range_search_cb(Dwarf_Die *sp_die, void *data)
{
struct dwarf_callback_param *param = data;
struct line_finder *lf = param->data;
struct line_range *lr = lf->lr;
if (lr->file && strtailcmp(lr->file, dwarf_decl_file(sp_die)))
return DWARF_CB_OK;
if (die_is_func_def(sp_die) &&
die_compare_name(sp_die, lr->function)) {
lf->fname = dwarf_decl_file(sp_die);
dwarf_decl_line(sp_die, &lr->offset);
pr_debug("fname: %s, lineno:%d\n", lf->fname, lr->offset);
lf->lno_s = lr->offset + lr->start;
if (lf->lno_s < 0)
lf->lno_s = INT_MAX;
lf->lno_e = lr->offset + lr->end;
if (lf->lno_e < 0)
lf->lno_e = INT_MAX;
pr_debug("New line range: %d to %d\n", lf->lno_s, lf->lno_e);
lr->start = lf->lno_s;
lr->end = lf->lno_e;
if (dwarf_func_inline(sp_die))
param->retval = die_walk_instances(sp_die,
line_range_inline_cb, lf);
else
param->retval = find_line_range_by_line(sp_die, lf);
return DWARF_CB_ABORT;
}
return DWARF_CB_OK;
}
static int find_line_range_by_func(struct line_finder *lf)
{
struct dwarf_callback_param param = {.data = (void *)lf, .retval = 0};
dwarf_getfuncs(&lf->cu_die, line_range_search_cb, &param, 0);
return param.retval;
}
int debuginfo__find_line_range(struct debuginfo *dbg, struct line_range *lr)
{
struct line_finder lf = {.lr = lr, .found = 0};
int ret = 0;
Dwarf_Off off = 0, noff;
size_t cuhl;
Dwarf_Die *diep;
const char *comp_dir;
if (lr->function) {
struct pubname_callback_param pubname_param = {
.function = lr->function, .file = lr->file,
.cu_die = &lf.cu_die, .sp_die = &lf.sp_die, .found = 0};
struct dwarf_callback_param line_range_param = {
.data = (void *)&lf, .retval = 0};
dwarf_getpubnames(dbg->dbg, pubname_search_cb,
&pubname_param, 0);
if (pubname_param.found) {
line_range_search_cb(&lf.sp_die, &line_range_param);
if (lf.found)
goto found;
}
}
while (!lf.found && ret >= 0) {
if (dwarf_nextcu(dbg->dbg, off, &noff, &cuhl,
NULL, NULL, NULL) != 0)
break;
diep = dwarf_offdie(dbg->dbg, off + cuhl, &lf.cu_die);
if (!diep)
continue;
if (lr->file)
lf.fname = cu_find_realpath(&lf.cu_die, lr->file);
else
lf.fname = 0;
if (!lr->file || lf.fname) {
if (lr->function)
ret = find_line_range_by_func(&lf);
else {
lf.lno_s = lr->start;
lf.lno_e = lr->end;
ret = find_line_range_by_line(NULL, &lf);
}
}
off = noff;
}
found:
if (lf.found) {
comp_dir = cu_get_comp_dir(&lf.cu_die);
if (comp_dir) {
lr->comp_dir = strdup(comp_dir);
if (!lr->comp_dir)
ret = -ENOMEM;
}
}
pr_debug("path: %s\n", lr->path);
return (ret < 0) ? ret : lf.found;
}
