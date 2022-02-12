static int check_return_reg(int ra_regno, Dwarf_Frame *frame)
{
Dwarf_Op ops_mem[2];
Dwarf_Op dummy;
Dwarf_Op *ops = &dummy;
size_t nops;
int result;
result = dwarf_frame_register(frame, ra_regno, ops_mem, &ops, &nops);
if (result < 0) {
pr_debug("dwarf_frame_register() %s\n", dwarf_errmsg(-1));
return -1;
}
if (nops != 0 || ops != NULL)
return 0;
result = dwarf_frame_cfa(frame, &ops, &nops);
if (result < 0) {
pr_debug("dwarf_frame_cfa() returns %d, %s\n", result,
dwarf_errmsg(-1));
return -1;
}
if (nops == 1 && ops[0].atom == DW_OP_bregx && ops[0].number == 1 &&
ops[0].number2 == 0)
return 1;
return 2;
}
static Dwarf_Frame *get_eh_frame(Dwfl_Module *mod, Dwarf_Addr pc)
{
int result;
Dwarf_Addr bias;
Dwarf_CFI *cfi;
Dwarf_Frame *frame;
cfi = dwfl_module_eh_cfi(mod, &bias);
if (!cfi) {
pr_debug("%s(): no CFI - %s\n", __func__, dwfl_errmsg(-1));
return NULL;
}
result = dwarf_cfi_addrframe(cfi, pc, &frame);
if (result) {
pr_debug("%s(): %s\n", __func__, dwfl_errmsg(-1));
return NULL;
}
return frame;
}
static Dwarf_Frame *get_dwarf_frame(Dwfl_Module *mod, Dwarf_Addr pc)
{
Dwarf_CFI *cfi;
Dwarf_Addr bias;
Dwarf_Frame *frame;
int result;
cfi = dwfl_module_dwarf_cfi(mod, &bias);
if (!cfi) {
pr_debug("%s(): no CFI - %s\n", __func__, dwfl_errmsg(-1));
return NULL;
}
result = dwarf_cfi_addrframe(cfi, pc, &frame);
if (result) {
pr_debug("%s(): %s\n", __func__, dwfl_errmsg(-1));
return NULL;
}
return frame;
}
static int check_return_addr(const char *exec_file, Dwarf_Addr pc)
{
int rc = -1;
Dwfl *dwfl;
Dwfl_Module *mod;
Dwarf_Frame *frame;
int ra_regno;
Dwarf_Addr start = pc;
Dwarf_Addr end = pc;
bool signalp;
dwfl = dwfl_begin(&offline_callbacks);
if (!dwfl) {
pr_debug("dwfl_begin() failed: %s\n", dwarf_errmsg(-1));
return -1;
}
if (dwfl_report_offline(dwfl, "", exec_file, -1) == NULL) {
pr_debug("dwfl_report_offline() failed %s\n", dwarf_errmsg(-1));
goto out;
}
mod = dwfl_addrmodule(dwfl, pc);
if (!mod) {
pr_debug("dwfl_addrmodule() failed, %s\n", dwarf_errmsg(-1));
goto out;
}
frame = get_eh_frame(mod, pc);
if (!frame) {
frame = get_dwarf_frame(mod, pc);
if (!frame)
goto out;
}
ra_regno = dwarf_frame_info(frame, &start, &end, &signalp);
if (ra_regno < 0) {
pr_debug("Return address register unavailable: %s\n",
dwarf_errmsg(-1));
goto out;
}
rc = check_return_reg(ra_regno, frame);
out:
dwfl_end(dwfl);
return rc;
}
int arch_skip_callchain_idx(struct machine *machine, struct thread *thread,
struct ip_callchain *chain)
{
struct addr_location al;
struct dso *dso = NULL;
int rc;
u64 ip;
u64 skip_slot = -1;
if (chain->nr < 3)
return skip_slot;
ip = chain->ips[2];
thread__find_addr_location(thread, machine, PERF_RECORD_MISC_USER,
MAP__FUNCTION, ip, &al);
if (al.map)
dso = al.map->dso;
if (!dso) {
pr_debug("%" PRIx64 " dso is NULL\n", ip);
return skip_slot;
}
rc = check_return_addr(dso->long_name, ip);
pr_debug("DSO %s, nr %" PRIx64 ", ip 0x%" PRIx64 "rc %d\n",
dso->long_name, chain->nr, ip, rc);
if (rc == 0) {
skip_slot = 2;
} else if (rc == 2) {
skip_slot = 3;
}
return skip_slot;
}
