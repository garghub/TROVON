int cpu_is_not_present(int cpu)
{
return !CPU_ISSET_S(cpu, cpu_present_setsize, cpu_present_set);
}
int for_all_cpus(int (func)(struct thread_data *, struct core_data *, struct pkg_data *),
struct thread_data *thread_base, struct core_data *core_base, struct pkg_data *pkg_base)
{
int retval, pkg_no, core_no, thread_no;
for (pkg_no = 0; pkg_no < topo.num_packages; ++pkg_no) {
for (core_no = 0; core_no < topo.num_cores_per_pkg; ++core_no) {
for (thread_no = 0; thread_no <
topo.num_threads_per_core; ++thread_no) {
struct thread_data *t;
struct core_data *c;
struct pkg_data *p;
t = GET_THREAD(thread_base, thread_no, core_no, pkg_no);
if (cpu_is_not_present(t->cpu_id))
continue;
c = GET_CORE(core_base, core_no, pkg_no);
p = GET_PKG(pkg_base, pkg_no);
retval = func(t, c, p);
if (retval)
return retval;
}
}
}
return 0;
}
int cpu_migrate(int cpu)
{
CPU_ZERO_S(cpu_affinity_setsize, cpu_affinity_set);
CPU_SET_S(cpu, cpu_affinity_setsize, cpu_affinity_set);
if (sched_setaffinity(0, cpu_affinity_setsize, cpu_affinity_set) == -1)
return -1;
else
return 0;
}
int get_msr_fd(int cpu)
{
char pathname[32];
int fd;
fd = fd_percpu[cpu];
if (fd)
return fd;
sprintf(pathname, "/dev/cpu/%d/msr", cpu);
fd = open(pathname, O_RDONLY);
if (fd < 0)
err(-1, "%s open failed, try chown or chmod +r /dev/cpu/*/msr, or run as root", pathname);
fd_percpu[cpu] = fd;
return fd;
}
int get_msr(int cpu, off_t offset, unsigned long long *msr)
{
ssize_t retval;
retval = pread(get_msr_fd(cpu), msr, sizeof(*msr), offset);
if (retval != sizeof *msr)
err(-1, "cpu%d: msr offset 0x%llx read failed", cpu, (unsigned long long)offset);
return 0;
}
void help(void)
{
fprintf(outf,
"Usage: turbostat [OPTIONS][(--interval seconds) | COMMAND ...]\n"
"\n"
"Turbostat forks the specified COMMAND and prints statistics\n"
"when COMMAND completes.\n"
"If no COMMAND is specified, turbostat wakes every 5-seconds\n"
"to print statistics, until interrupted.\n"
"--add add a counter\n"
" eg. --add msr0x10,u64,cpu,delta,MY_TSC\n"
"--cpu cpu-set limit output to summary plus cpu-set:\n"
" {core | package | j,k,l..m,n-p }\n"
"--quiet skip decoding system configuration header\n"
"--interval sec Override default 5-second measurement interval\n"
"--help print this help message\n"
"--list list column headers only\n"
"--out file create or truncate \"file\" for all output\n"
"--version print version information\n"
"\n"
"For more help, run \"man turbostat\"\n");
}
unsigned long long bic_lookup(char *name_list, enum show_hide_mode mode)
{
int i;
unsigned long long retval = 0;
while (name_list) {
char *comma;
comma = strchr(name_list, ',');
if (comma)
*comma = '\0';
for (i = 0; i < MAX_BIC; ++i) {
if (!strcmp(name_list, bic[i].name)) {
retval |= (1ULL << i);
break;
}
}
if (i == MAX_BIC) {
if (mode == SHOW_LIST) {
fprintf(stderr, "Invalid counter name: %s\n", name_list);
exit(-1);
}
deferred_skip_names[deferred_skip_index++] = name_list;
if (debug)
fprintf(stderr, "deferred \"%s\"\n", name_list);
if (deferred_skip_index >= MAX_DEFERRED) {
fprintf(stderr, "More than max %d un-recognized --skip options '%s'\n",
MAX_DEFERRED, name_list);
help();
exit(1);
}
}
name_list = comma;
if (name_list)
name_list++;
}
return retval;
}
void print_header(char *delim)
{
struct msr_counter *mp;
int printed = 0;
if (DO_BIC(BIC_Package))
outp += sprintf(outp, "%sPackage", (printed++ ? delim : ""));
if (DO_BIC(BIC_Core))
outp += sprintf(outp, "%sCore", (printed++ ? delim : ""));
if (DO_BIC(BIC_CPU))
outp += sprintf(outp, "%sCPU", (printed++ ? delim : ""));
if (DO_BIC(BIC_Avg_MHz))
outp += sprintf(outp, "%sAvg_MHz", (printed++ ? delim : ""));
if (DO_BIC(BIC_Busy))
outp += sprintf(outp, "%sBusy%%", (printed++ ? delim : ""));
if (DO_BIC(BIC_Bzy_MHz))
outp += sprintf(outp, "%sBzy_MHz", (printed++ ? delim : ""));
if (DO_BIC(BIC_TSC_MHz))
outp += sprintf(outp, "%sTSC_MHz", (printed++ ? delim : ""));
if (DO_BIC(BIC_IRQ)) {
if (sums_need_wide_columns)
outp += sprintf(outp, "%s IRQ", (printed++ ? delim : ""));
else
outp += sprintf(outp, "%sIRQ", (printed++ ? delim : ""));
}
if (DO_BIC(BIC_SMI))
outp += sprintf(outp, "%sSMI", (printed++ ? delim : ""));
for (mp = sys.tp; mp; mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 64)
outp += sprintf(outp, "%s%18.18s", (printed++ ? delim : ""), mp->name);
else
outp += sprintf(outp, "%s%10.10s", (printed++ ? delim : ""), mp->name);
} else {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8s", (printed++ ? delim : ""), mp->name);
else
outp += sprintf(outp, "%s%s", (printed++ ? delim : ""), mp->name);
}
}
if (DO_BIC(BIC_CPU_c1))
outp += sprintf(outp, "%sCPU%%c1", (printed++ ? delim : ""));
if (DO_BIC(BIC_CPU_c3) && !do_slm_cstates && !do_knl_cstates)
outp += sprintf(outp, "%sCPU%%c3", (printed++ ? delim : ""));
if (DO_BIC(BIC_CPU_c6))
outp += sprintf(outp, "%sCPU%%c6", (printed++ ? delim : ""));
if (DO_BIC(BIC_CPU_c7))
outp += sprintf(outp, "%sCPU%%c7", (printed++ ? delim : ""));
if (DO_BIC(BIC_Mod_c6))
outp += sprintf(outp, "%sMod%%c6", (printed++ ? delim : ""));
if (DO_BIC(BIC_CoreTmp))
outp += sprintf(outp, "%sCoreTmp", (printed++ ? delim : ""));
for (mp = sys.cp; mp; mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 64)
outp += sprintf(outp, "%s%18.18s", delim, mp->name);
else
outp += sprintf(outp, "%s%10.10s", delim, mp->name);
} else {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8s", delim, mp->name);
else
outp += sprintf(outp, "%s%s", delim, mp->name);
}
}
if (DO_BIC(BIC_PkgTmp))
outp += sprintf(outp, "%sPkgTmp", (printed++ ? delim : ""));
if (DO_BIC(BIC_GFX_rc6))
outp += sprintf(outp, "%sGFX%%rc6", (printed++ ? delim : ""));
if (DO_BIC(BIC_GFXMHz))
outp += sprintf(outp, "%sGFXMHz", (printed++ ? delim : ""));
if (do_skl_residency) {
outp += sprintf(outp, "%sTotl%%C0", (printed++ ? delim : ""));
outp += sprintf(outp, "%sAny%%C0", (printed++ ? delim : ""));
outp += sprintf(outp, "%sGFX%%C0", (printed++ ? delim : ""));
outp += sprintf(outp, "%sCPUGFX%%", (printed++ ? delim : ""));
}
if (DO_BIC(BIC_Pkgpc2))
outp += sprintf(outp, "%sPkg%%pc2", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc3))
outp += sprintf(outp, "%sPkg%%pc3", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc6))
outp += sprintf(outp, "%sPkg%%pc6", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc7))
outp += sprintf(outp, "%sPkg%%pc7", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc8))
outp += sprintf(outp, "%sPkg%%pc8", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc9))
outp += sprintf(outp, "%sPkg%%pc9", (printed++ ? delim : ""));
if (DO_BIC(BIC_Pkgpc10))
outp += sprintf(outp, "%sPk%%pc10", (printed++ ? delim : ""));
if (do_rapl && !rapl_joules) {
if (DO_BIC(BIC_PkgWatt))
outp += sprintf(outp, "%sPkgWatt", (printed++ ? delim : ""));
if (DO_BIC(BIC_CorWatt))
outp += sprintf(outp, "%sCorWatt", (printed++ ? delim : ""));
if (DO_BIC(BIC_GFXWatt))
outp += sprintf(outp, "%sGFXWatt", (printed++ ? delim : ""));
if (DO_BIC(BIC_RAMWatt))
outp += sprintf(outp, "%sRAMWatt", (printed++ ? delim : ""));
if (DO_BIC(BIC_PKG__))
outp += sprintf(outp, "%sPKG_%%", (printed++ ? delim : ""));
if (DO_BIC(BIC_RAM__))
outp += sprintf(outp, "%sRAM_%%", (printed++ ? delim : ""));
} else if (do_rapl && rapl_joules) {
if (DO_BIC(BIC_Pkg_J))
outp += sprintf(outp, "%sPkg_J", (printed++ ? delim : ""));
if (DO_BIC(BIC_Cor_J))
outp += sprintf(outp, "%sCor_J", (printed++ ? delim : ""));
if (DO_BIC(BIC_GFX_J))
outp += sprintf(outp, "%sGFX_J", (printed++ ? delim : ""));
if (DO_BIC(BIC_RAM_J))
outp += sprintf(outp, "%sRAM_J", (printed++ ? delim : ""));
if (DO_BIC(BIC_PKG__))
outp += sprintf(outp, "%sPKG_%%", (printed++ ? delim : ""));
if (DO_BIC(BIC_RAM__))
outp += sprintf(outp, "%sRAM_%%", (printed++ ? delim : ""));
}
for (mp = sys.pp; mp; mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 64)
outp += sprintf(outp, "%s%18.18s", delim, mp->name);
else
outp += sprintf(outp, "%s%10.10s", delim, mp->name);
} else {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8s", delim, mp->name);
else
outp += sprintf(outp, "%s%s", delim, mp->name);
}
}
outp += sprintf(outp, "\n");
}
int dump_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
int i;
struct msr_counter *mp;
outp += sprintf(outp, "t %p, c %p, p %p\n", t, c, p);
if (t) {
outp += sprintf(outp, "CPU: %d flags 0x%x\n",
t->cpu_id, t->flags);
outp += sprintf(outp, "TSC: %016llX\n", t->tsc);
outp += sprintf(outp, "aperf: %016llX\n", t->aperf);
outp += sprintf(outp, "mperf: %016llX\n", t->mperf);
outp += sprintf(outp, "c1: %016llX\n", t->c1);
if (DO_BIC(BIC_IRQ))
outp += sprintf(outp, "IRQ: %lld\n", t->irq_count);
if (DO_BIC(BIC_SMI))
outp += sprintf(outp, "SMI: %d\n", t->smi_count);
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
outp += sprintf(outp, "tADDED [%d] msr0x%x: %08llX\n",
i, mp->msr_num, t->counter[i]);
}
}
if (c) {
outp += sprintf(outp, "core: %d\n", c->core_id);
outp += sprintf(outp, "c3: %016llX\n", c->c3);
outp += sprintf(outp, "c6: %016llX\n", c->c6);
outp += sprintf(outp, "c7: %016llX\n", c->c7);
outp += sprintf(outp, "DTS: %dC\n", c->core_temp_c);
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
outp += sprintf(outp, "cADDED [%d] msr0x%x: %08llX\n",
i, mp->msr_num, c->counter[i]);
}
outp += sprintf(outp, "mc6_us: %016llX\n", c->mc6_us);
}
if (p) {
outp += sprintf(outp, "package: %d\n", p->package_id);
outp += sprintf(outp, "Weighted cores: %016llX\n", p->pkg_wtd_core_c0);
outp += sprintf(outp, "Any cores: %016llX\n", p->pkg_any_core_c0);
outp += sprintf(outp, "Any GFX: %016llX\n", p->pkg_any_gfxe_c0);
outp += sprintf(outp, "CPU + GFX: %016llX\n", p->pkg_both_core_gfxe_c0);
outp += sprintf(outp, "pc2: %016llX\n", p->pc2);
if (DO_BIC(BIC_Pkgpc3))
outp += sprintf(outp, "pc3: %016llX\n", p->pc3);
if (DO_BIC(BIC_Pkgpc6))
outp += sprintf(outp, "pc6: %016llX\n", p->pc6);
if (DO_BIC(BIC_Pkgpc7))
outp += sprintf(outp, "pc7: %016llX\n", p->pc7);
outp += sprintf(outp, "pc8: %016llX\n", p->pc8);
outp += sprintf(outp, "pc9: %016llX\n", p->pc9);
outp += sprintf(outp, "pc10: %016llX\n", p->pc10);
outp += sprintf(outp, "Joules PKG: %0X\n", p->energy_pkg);
outp += sprintf(outp, "Joules COR: %0X\n", p->energy_cores);
outp += sprintf(outp, "Joules GFX: %0X\n", p->energy_gfx);
outp += sprintf(outp, "Joules RAM: %0X\n", p->energy_dram);
outp += sprintf(outp, "Throttle PKG: %0X\n",
p->rapl_pkg_perf_status);
outp += sprintf(outp, "Throttle RAM: %0X\n",
p->rapl_dram_perf_status);
outp += sprintf(outp, "PTM: %dC\n", p->pkg_temp_c);
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
outp += sprintf(outp, "pADDED [%d] msr0x%x: %08llX\n",
i, mp->msr_num, p->counter[i]);
}
}
outp += sprintf(outp, "\n");
return 0;
}
int format_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
double interval_float, tsc;
char *fmt8;
int i;
struct msr_counter *mp;
char *delim = "\t";
int printed = 0;
if (show_core_only && !(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (show_pkg_only && !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if ((t != &average.threads) &&
(cpu_subset && !CPU_ISSET_S(t->cpu_id, cpu_subset_size, cpu_subset)))
return 0;
interval_float = tv_delta.tv_sec + tv_delta.tv_usec/1000000.0;
tsc = t->tsc * tsc_tweak;
if (t == &average.threads) {
if (DO_BIC(BIC_Package))
outp += sprintf(outp, "%s-", (printed++ ? delim : ""));
if (DO_BIC(BIC_Core))
outp += sprintf(outp, "%s-", (printed++ ? delim : ""));
if (DO_BIC(BIC_CPU))
outp += sprintf(outp, "%s-", (printed++ ? delim : ""));
} else {
if (DO_BIC(BIC_Package)) {
if (p)
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), p->package_id);
else
outp += sprintf(outp, "%s-", (printed++ ? delim : ""));
}
if (DO_BIC(BIC_Core)) {
if (c)
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), c->core_id);
else
outp += sprintf(outp, "%s-", (printed++ ? delim : ""));
}
if (DO_BIC(BIC_CPU))
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), t->cpu_id);
}
if (DO_BIC(BIC_Avg_MHz))
outp += sprintf(outp, "%s%.0f", (printed++ ? delim : ""),
1.0 / units * t->aperf / interval_float);
if (DO_BIC(BIC_Busy))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * t->mperf/tsc);
if (DO_BIC(BIC_Bzy_MHz)) {
if (has_base_hz)
outp += sprintf(outp, "%s%.0f", (printed++ ? delim : ""), base_hz / units * t->aperf / t->mperf);
else
outp += sprintf(outp, "%s%.0f", (printed++ ? delim : ""),
tsc / units * t->aperf / t->mperf / interval_float);
}
if (DO_BIC(BIC_TSC_MHz))
outp += sprintf(outp, "%s%.0f", (printed++ ? delim : ""), 1.0 * t->tsc/units/interval_float);
if (DO_BIC(BIC_IRQ)) {
if (sums_need_wide_columns)
outp += sprintf(outp, "%s%8lld", (printed++ ? delim : ""), t->irq_count);
else
outp += sprintf(outp, "%s%lld", (printed++ ? delim : ""), t->irq_count);
}
if (DO_BIC(BIC_SMI))
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), t->smi_count);
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 32)
outp += sprintf(outp, "%s0x%08x", (printed++ ? delim : ""), (unsigned int) t->counter[i]);
else
outp += sprintf(outp, "%s0x%016llx", (printed++ ? delim : ""), t->counter[i]);
} else if (mp->format == FORMAT_DELTA) {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8lld", (printed++ ? delim : ""), t->counter[i]);
else
outp += sprintf(outp, "%s%lld", (printed++ ? delim : ""), t->counter[i]);
} else if (mp->format == FORMAT_PERCENT) {
if (mp->type == COUNTER_USEC)
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), t->counter[i]/interval_float/10000);
else
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * t->counter[i]/tsc);
}
}
if (DO_BIC(BIC_CPU_c1))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * t->c1/tsc);
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
goto done;
if (DO_BIC(BIC_CPU_c3) && !do_slm_cstates && !do_knl_cstates)
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * c->c3/tsc);
if (DO_BIC(BIC_CPU_c6))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * c->c6/tsc);
if (DO_BIC(BIC_CPU_c7))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * c->c7/tsc);
if (DO_BIC(BIC_Mod_c6))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * c->mc6_us / tsc);
if (DO_BIC(BIC_CoreTmp))
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), c->core_temp_c);
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 32)
outp += sprintf(outp, "%s0x%08x", (printed++ ? delim : ""), (unsigned int) c->counter[i]);
else
outp += sprintf(outp, "%s0x%016llx", (printed++ ? delim : ""), c->counter[i]);
} else if (mp->format == FORMAT_DELTA) {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8lld", (printed++ ? delim : ""), c->counter[i]);
else
outp += sprintf(outp, "%s%lld", (printed++ ? delim : ""), c->counter[i]);
} else if (mp->format == FORMAT_PERCENT) {
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * c->counter[i]/tsc);
}
}
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
goto done;
if (DO_BIC(BIC_PkgTmp))
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), p->pkg_temp_c);
if (DO_BIC(BIC_GFX_rc6)) {
if (p->gfx_rc6_ms == -1) {
outp += sprintf(outp, "%s**.**", (printed++ ? delim : ""));
} else {
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""),
p->gfx_rc6_ms / 10.0 / interval_float);
}
}
if (DO_BIC(BIC_GFXMHz))
outp += sprintf(outp, "%s%d", (printed++ ? delim : ""), p->gfx_mhz);
if (do_skl_residency) {
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pkg_wtd_core_c0/tsc);
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pkg_any_core_c0/tsc);
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pkg_any_gfxe_c0/tsc);
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pkg_both_core_gfxe_c0/tsc);
}
if (DO_BIC(BIC_Pkgpc2))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc2/tsc);
if (DO_BIC(BIC_Pkgpc3))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc3/tsc);
if (DO_BIC(BIC_Pkgpc6))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc6/tsc);
if (DO_BIC(BIC_Pkgpc7))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc7/tsc);
if (DO_BIC(BIC_Pkgpc8))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc8/tsc);
if (DO_BIC(BIC_Pkgpc9))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc9/tsc);
if (DO_BIC(BIC_Pkgpc10))
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->pc10/tsc);
if (interval_float < rapl_joule_counter_range)
fmt8 = "%s%.2f";
else
fmt8 = "%6.0f**";
if (DO_BIC(BIC_PkgWatt))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_pkg * rapl_energy_units / interval_float);
if (DO_BIC(BIC_CorWatt))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_cores * rapl_energy_units / interval_float);
if (DO_BIC(BIC_GFXWatt))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_gfx * rapl_energy_units / interval_float);
if (DO_BIC(BIC_RAMWatt))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_dram * rapl_dram_energy_units / interval_float);
if (DO_BIC(BIC_Pkg_J))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_pkg * rapl_energy_units);
if (DO_BIC(BIC_Cor_J))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_cores * rapl_energy_units);
if (DO_BIC(BIC_GFX_J))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_gfx * rapl_energy_units);
if (DO_BIC(BIC_RAM_J))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), p->energy_dram * rapl_dram_energy_units);
if (DO_BIC(BIC_PKG__))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), 100.0 * p->rapl_pkg_perf_status * rapl_time_units / interval_float);
if (DO_BIC(BIC_RAM__))
outp += sprintf(outp, fmt8, (printed++ ? delim : ""), 100.0 * p->rapl_dram_perf_status * rapl_time_units / interval_float);
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW) {
if (mp->width == 32)
outp += sprintf(outp, "%s0x%08x", (printed++ ? delim : ""), (unsigned int) p->counter[i]);
else
outp += sprintf(outp, "%s0x%016llx", (printed++ ? delim : ""), p->counter[i]);
} else if (mp->format == FORMAT_DELTA) {
if ((mp->type == COUNTER_ITEMS) && sums_need_wide_columns)
outp += sprintf(outp, "%s%8lld", (printed++ ? delim : ""), p->counter[i]);
else
outp += sprintf(outp, "%s%lld", (printed++ ? delim : ""), p->counter[i]);
} else if (mp->format == FORMAT_PERCENT) {
outp += sprintf(outp, "%s%.2f", (printed++ ? delim : ""), 100.0 * p->counter[i]/tsc);
}
}
done:
outp += sprintf(outp, "\n");
return 0;
}
void flush_output_stdout(void)
{
FILE *filep;
if (outf == stderr)
filep = stdout;
else
filep = outf;
fputs(output_buffer, filep);
fflush(filep);
outp = output_buffer;
}
void flush_output_stderr(void)
{
fputs(output_buffer, outf);
fflush(outf);
outp = output_buffer;
}
void format_all_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
static int printed;
if (!printed || !summary_only)
print_header("\t");
if (topo.num_cpus > 1)
format_counters(&average.threads, &average.cores,
&average.packages);
printed = 1;
if (summary_only)
return;
for_all_cpus(format_counters, t, c, p);
}
int
delta_package(struct pkg_data *new, struct pkg_data *old)
{
int i;
struct msr_counter *mp;
if (do_skl_residency) {
old->pkg_wtd_core_c0 = new->pkg_wtd_core_c0 - old->pkg_wtd_core_c0;
old->pkg_any_core_c0 = new->pkg_any_core_c0 - old->pkg_any_core_c0;
old->pkg_any_gfxe_c0 = new->pkg_any_gfxe_c0 - old->pkg_any_gfxe_c0;
old->pkg_both_core_gfxe_c0 = new->pkg_both_core_gfxe_c0 - old->pkg_both_core_gfxe_c0;
}
old->pc2 = new->pc2 - old->pc2;
if (DO_BIC(BIC_Pkgpc3))
old->pc3 = new->pc3 - old->pc3;
if (DO_BIC(BIC_Pkgpc6))
old->pc6 = new->pc6 - old->pc6;
if (DO_BIC(BIC_Pkgpc7))
old->pc7 = new->pc7 - old->pc7;
old->pc8 = new->pc8 - old->pc8;
old->pc9 = new->pc9 - old->pc9;
old->pc10 = new->pc10 - old->pc10;
old->pkg_temp_c = new->pkg_temp_c;
if (old->gfx_rc6_ms > new->gfx_rc6_ms)
old->gfx_rc6_ms = -1;
else
old->gfx_rc6_ms = new->gfx_rc6_ms - old->gfx_rc6_ms;
old->gfx_mhz = new->gfx_mhz;
DELTA_WRAP32(new->energy_pkg, old->energy_pkg);
DELTA_WRAP32(new->energy_cores, old->energy_cores);
DELTA_WRAP32(new->energy_gfx, old->energy_gfx);
DELTA_WRAP32(new->energy_dram, old->energy_dram);
DELTA_WRAP32(new->rapl_pkg_perf_status, old->rapl_pkg_perf_status);
DELTA_WRAP32(new->rapl_dram_perf_status, old->rapl_dram_perf_status);
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
old->counter[i] = new->counter[i];
else
old->counter[i] = new->counter[i] - old->counter[i];
}
return 0;
}
void
delta_core(struct core_data *new, struct core_data *old)
{
int i;
struct msr_counter *mp;
old->c3 = new->c3 - old->c3;
old->c6 = new->c6 - old->c6;
old->c7 = new->c7 - old->c7;
old->core_temp_c = new->core_temp_c;
old->mc6_us = new->mc6_us - old->mc6_us;
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
old->counter[i] = new->counter[i];
else
old->counter[i] = new->counter[i] - old->counter[i];
}
}
int
delta_thread(struct thread_data *new, struct thread_data *old,
struct core_data *core_delta)
{
int i;
struct msr_counter *mp;
old->tsc = new->tsc - old->tsc;
if (old->tsc < (1000 * 1000))
errx(-3, "Insanely slow TSC rate, TSC stops in idle?\n"
"You can disable all c-states by booting with \"idle=poll\"\n"
"or just the deep ones with \"processor.max_cstate=1\"");
old->c1 = new->c1 - old->c1;
if (DO_BIC(BIC_Avg_MHz) || DO_BIC(BIC_Busy) || DO_BIC(BIC_Bzy_MHz)) {
if ((new->aperf > old->aperf) && (new->mperf > old->mperf)) {
old->aperf = new->aperf - old->aperf;
old->mperf = new->mperf - old->mperf;
} else {
return -1;
}
}
if (use_c1_residency_msr) {
} else {
if ((old->mperf + core_delta->c3 + core_delta->c6 + core_delta->c7) > (old->tsc * tsc_tweak))
old->c1 = 0;
else {
old->c1 = (old->tsc * tsc_tweak) - old->mperf - core_delta->c3
- core_delta->c6 - core_delta->c7;
}
}
if (old->mperf == 0) {
if (debug > 1)
fprintf(outf, "cpu%d MPERF 0!\n", old->cpu_id);
old->mperf = 1;
}
if (DO_BIC(BIC_IRQ))
old->irq_count = new->irq_count - old->irq_count;
if (DO_BIC(BIC_SMI))
old->smi_count = new->smi_count - old->smi_count;
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
old->counter[i] = new->counter[i];
else
old->counter[i] = new->counter[i] - old->counter[i];
}
return 0;
}
int delta_cpu(struct thread_data *t, struct core_data *c,
struct pkg_data *p, struct thread_data *t2,
struct core_data *c2, struct pkg_data *p2)
{
int retval = 0;
if (t->flags & CPU_IS_FIRST_THREAD_IN_CORE)
delta_core(c, c2);
retval = delta_thread(t, t2, c2);
if (retval)
return retval;
if (t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE)
retval = delta_package(p, p2);
return retval;
}
void clear_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
int i;
struct msr_counter *mp;
t->tsc = 0;
t->aperf = 0;
t->mperf = 0;
t->c1 = 0;
t->irq_count = 0;
t->smi_count = 0;
t->flags = CPU_IS_FIRST_THREAD_IN_CORE | CPU_IS_FIRST_CORE_IN_PACKAGE;
c->c3 = 0;
c->c6 = 0;
c->c7 = 0;
c->mc6_us = 0;
c->core_temp_c = 0;
p->pkg_wtd_core_c0 = 0;
p->pkg_any_core_c0 = 0;
p->pkg_any_gfxe_c0 = 0;
p->pkg_both_core_gfxe_c0 = 0;
p->pc2 = 0;
if (DO_BIC(BIC_Pkgpc3))
p->pc3 = 0;
if (DO_BIC(BIC_Pkgpc6))
p->pc6 = 0;
if (DO_BIC(BIC_Pkgpc7))
p->pc7 = 0;
p->pc8 = 0;
p->pc9 = 0;
p->pc10 = 0;
p->energy_pkg = 0;
p->energy_dram = 0;
p->energy_cores = 0;
p->energy_gfx = 0;
p->rapl_pkg_perf_status = 0;
p->rapl_dram_perf_status = 0;
p->pkg_temp_c = 0;
p->gfx_rc6_ms = 0;
p->gfx_mhz = 0;
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next)
t->counter[i] = 0;
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next)
c->counter[i] = 0;
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next)
p->counter[i] = 0;
}
int sum_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
int i;
struct msr_counter *mp;
average.threads.tsc += t->tsc;
average.threads.aperf += t->aperf;
average.threads.mperf += t->mperf;
average.threads.c1 += t->c1;
average.threads.irq_count += t->irq_count;
average.threads.smi_count += t->smi_count;
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
average.threads.counter[i] += t->counter[i];
}
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
average.cores.c3 += c->c3;
average.cores.c6 += c->c6;
average.cores.c7 += c->c7;
average.cores.mc6_us += c->mc6_us;
average.cores.core_temp_c = MAX(average.cores.core_temp_c, c->core_temp_c);
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
average.cores.counter[i] += c->counter[i];
}
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (do_skl_residency) {
average.packages.pkg_wtd_core_c0 += p->pkg_wtd_core_c0;
average.packages.pkg_any_core_c0 += p->pkg_any_core_c0;
average.packages.pkg_any_gfxe_c0 += p->pkg_any_gfxe_c0;
average.packages.pkg_both_core_gfxe_c0 += p->pkg_both_core_gfxe_c0;
}
average.packages.pc2 += p->pc2;
if (DO_BIC(BIC_Pkgpc3))
average.packages.pc3 += p->pc3;
if (DO_BIC(BIC_Pkgpc6))
average.packages.pc6 += p->pc6;
if (DO_BIC(BIC_Pkgpc7))
average.packages.pc7 += p->pc7;
average.packages.pc8 += p->pc8;
average.packages.pc9 += p->pc9;
average.packages.pc10 += p->pc10;
average.packages.energy_pkg += p->energy_pkg;
average.packages.energy_dram += p->energy_dram;
average.packages.energy_cores += p->energy_cores;
average.packages.energy_gfx += p->energy_gfx;
average.packages.gfx_rc6_ms = p->gfx_rc6_ms;
average.packages.gfx_mhz = p->gfx_mhz;
average.packages.pkg_temp_c = MAX(average.packages.pkg_temp_c, p->pkg_temp_c);
average.packages.rapl_pkg_perf_status += p->rapl_pkg_perf_status;
average.packages.rapl_dram_perf_status += p->rapl_dram_perf_status;
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
average.packages.counter[i] += p->counter[i];
}
return 0;
}
void compute_average(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
int i;
struct msr_counter *mp;
clear_counters(&average.threads, &average.cores, &average.packages);
for_all_cpus(sum_counters, t, c, p);
average.threads.tsc /= topo.num_cpus;
average.threads.aperf /= topo.num_cpus;
average.threads.mperf /= topo.num_cpus;
average.threads.c1 /= topo.num_cpus;
if (average.threads.irq_count > 9999999)
sums_need_wide_columns = 1;
average.cores.c3 /= topo.num_cores;
average.cores.c6 /= topo.num_cores;
average.cores.c7 /= topo.num_cores;
average.cores.mc6_us /= topo.num_cores;
if (do_skl_residency) {
average.packages.pkg_wtd_core_c0 /= topo.num_packages;
average.packages.pkg_any_core_c0 /= topo.num_packages;
average.packages.pkg_any_gfxe_c0 /= topo.num_packages;
average.packages.pkg_both_core_gfxe_c0 /= topo.num_packages;
}
average.packages.pc2 /= topo.num_packages;
if (DO_BIC(BIC_Pkgpc3))
average.packages.pc3 /= topo.num_packages;
if (DO_BIC(BIC_Pkgpc6))
average.packages.pc6 /= topo.num_packages;
if (DO_BIC(BIC_Pkgpc7))
average.packages.pc7 /= topo.num_packages;
average.packages.pc8 /= topo.num_packages;
average.packages.pc9 /= topo.num_packages;
average.packages.pc10 /= topo.num_packages;
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
if (mp->type == COUNTER_ITEMS) {
if (average.threads.counter[i] > 9999999)
sums_need_wide_columns = 1;
continue;
}
average.threads.counter[i] /= topo.num_cpus;
}
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
if (mp->type == COUNTER_ITEMS) {
if (average.cores.counter[i] > 9999999)
sums_need_wide_columns = 1;
}
average.cores.counter[i] /= topo.num_cores;
}
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
if (mp->format == FORMAT_RAW)
continue;
if (mp->type == COUNTER_ITEMS) {
if (average.packages.counter[i] > 9999999)
sums_need_wide_columns = 1;
}
average.packages.counter[i] /= topo.num_packages;
}
}
static unsigned long long rdtsc(void)
{
unsigned int low, high;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return low | ((unsigned long long)high) << 32;
}
FILE *fopen_or_die(const char *path, const char *mode)
{
FILE *filep = fopen(path, mode);
if (!filep)
err(1, "%s: open failed", path);
return filep;
}
unsigned long long snapshot_sysfs_counter(char *path)
{
FILE *fp;
int retval;
unsigned long long counter;
fp = fopen_or_die(path, "r");
retval = fscanf(fp, "%lld", &counter);
if (retval != 1)
err(1, "snapshot_sysfs_counter(%s)", path);
fclose(fp);
return counter;
}
int get_mp(int cpu, struct msr_counter *mp, unsigned long long *counterp)
{
if (mp->msr_num != 0) {
if (get_msr(cpu, mp->msr_num, counterp))
return -1;
} else {
char path[128];
if (mp->flags & SYSFS_PERCPU) {
sprintf(path, "/sys/devices/system/cpu/cpu%d/%s",
cpu, mp->path);
*counterp = snapshot_sysfs_counter(path);
} else {
*counterp = snapshot_sysfs_counter(mp->path);
}
}
return 0;
}
int get_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
int cpu = t->cpu_id;
unsigned long long msr;
int aperf_mperf_retry_count = 0;
struct msr_counter *mp;
int i;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
retry:
t->tsc = rdtsc();
if (DO_BIC(BIC_Avg_MHz) || DO_BIC(BIC_Busy) || DO_BIC(BIC_Bzy_MHz)) {
unsigned long long tsc_before, tsc_between, tsc_after, aperf_time, mperf_time;
if (get_msr(cpu, MSR_IA32_APERF, &t->aperf))
return -3;
t->tsc = rdtsc();
tsc_before = t->tsc;
if (get_msr(cpu, MSR_IA32_APERF, &t->aperf))
return -3;
tsc_between = rdtsc();
if (get_msr(cpu, MSR_IA32_MPERF, &t->mperf))
return -4;
tsc_after = rdtsc();
aperf_time = tsc_between - tsc_before;
mperf_time = tsc_after - tsc_between;
if ((aperf_time > (2 * mperf_time)) || (mperf_time > (2 * aperf_time))) {
aperf_mperf_retry_count++;
if (aperf_mperf_retry_count < 5)
goto retry;
else
warnx("cpu%d jitter %lld %lld",
cpu, aperf_time, mperf_time);
}
aperf_mperf_retry_count = 0;
t->aperf = t->aperf * aperf_mperf_multiplier;
t->mperf = t->mperf * aperf_mperf_multiplier;
}
if (DO_BIC(BIC_IRQ))
t->irq_count = irqs_per_cpu[cpu];
if (DO_BIC(BIC_SMI)) {
if (get_msr(cpu, MSR_SMI_COUNT, &msr))
return -5;
t->smi_count = msr & 0xFFFFFFFF;
}
if (DO_BIC(BIC_CPU_c1) && use_c1_residency_msr) {
if (get_msr(cpu, MSR_CORE_C1_RES, &t->c1))
return -6;
}
for (i = 0, mp = sys.tp; mp; i++, mp = mp->next) {
if (get_mp(cpu, mp, &t->counter[i]))
return -10;
}
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (DO_BIC(BIC_CPU_c3) && !do_slm_cstates && !do_knl_cstates) {
if (get_msr(cpu, MSR_CORE_C3_RESIDENCY, &c->c3))
return -6;
}
if (DO_BIC(BIC_CPU_c6) && !do_knl_cstates) {
if (get_msr(cpu, MSR_CORE_C6_RESIDENCY, &c->c6))
return -7;
} else if (do_knl_cstates) {
if (get_msr(cpu, MSR_KNL_CORE_C6_RESIDENCY, &c->c6))
return -7;
}
if (DO_BIC(BIC_CPU_c7))
if (get_msr(cpu, MSR_CORE_C7_RESIDENCY, &c->c7))
return -8;
if (DO_BIC(BIC_Mod_c6))
if (get_msr(cpu, MSR_MODULE_C6_RES_MS, &c->mc6_us))
return -8;
if (DO_BIC(BIC_CoreTmp)) {
if (get_msr(cpu, MSR_IA32_THERM_STATUS, &msr))
return -9;
c->core_temp_c = tcc_activation_temp - ((msr >> 16) & 0x7F);
}
for (i = 0, mp = sys.cp; mp; i++, mp = mp->next) {
if (get_mp(cpu, mp, &c->counter[i]))
return -10;
}
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (do_skl_residency) {
if (get_msr(cpu, MSR_PKG_WEIGHTED_CORE_C0_RES, &p->pkg_wtd_core_c0))
return -10;
if (get_msr(cpu, MSR_PKG_ANY_CORE_C0_RES, &p->pkg_any_core_c0))
return -11;
if (get_msr(cpu, MSR_PKG_ANY_GFXE_C0_RES, &p->pkg_any_gfxe_c0))
return -12;
if (get_msr(cpu, MSR_PKG_BOTH_CORE_GFXE_C0_RES, &p->pkg_both_core_gfxe_c0))
return -13;
}
if (DO_BIC(BIC_Pkgpc3))
if (get_msr(cpu, MSR_PKG_C3_RESIDENCY, &p->pc3))
return -9;
if (DO_BIC(BIC_Pkgpc6)) {
if (do_slm_cstates) {
if (get_msr(cpu, MSR_ATOM_PKG_C6_RESIDENCY, &p->pc6))
return -10;
} else {
if (get_msr(cpu, MSR_PKG_C6_RESIDENCY, &p->pc6))
return -10;
}
}
if (DO_BIC(BIC_Pkgpc2))
if (get_msr(cpu, MSR_PKG_C2_RESIDENCY, &p->pc2))
return -11;
if (DO_BIC(BIC_Pkgpc7))
if (get_msr(cpu, MSR_PKG_C7_RESIDENCY, &p->pc7))
return -12;
if (DO_BIC(BIC_Pkgpc8))
if (get_msr(cpu, MSR_PKG_C8_RESIDENCY, &p->pc8))
return -13;
if (DO_BIC(BIC_Pkgpc9))
if (get_msr(cpu, MSR_PKG_C9_RESIDENCY, &p->pc9))
return -13;
if (DO_BIC(BIC_Pkgpc10))
if (get_msr(cpu, MSR_PKG_C10_RESIDENCY, &p->pc10))
return -13;
if (do_rapl & RAPL_PKG) {
if (get_msr(cpu, MSR_PKG_ENERGY_STATUS, &msr))
return -13;
p->energy_pkg = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_CORES_ENERGY_STATUS) {
if (get_msr(cpu, MSR_PP0_ENERGY_STATUS, &msr))
return -14;
p->energy_cores = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_DRAM) {
if (get_msr(cpu, MSR_DRAM_ENERGY_STATUS, &msr))
return -15;
p->energy_dram = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_GFX) {
if (get_msr(cpu, MSR_PP1_ENERGY_STATUS, &msr))
return -16;
p->energy_gfx = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_PKG_PERF_STATUS) {
if (get_msr(cpu, MSR_PKG_PERF_STATUS, &msr))
return -16;
p->rapl_pkg_perf_status = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_DRAM_PERF_STATUS) {
if (get_msr(cpu, MSR_DRAM_PERF_STATUS, &msr))
return -16;
p->rapl_dram_perf_status = msr & 0xFFFFFFFF;
}
if (DO_BIC(BIC_PkgTmp)) {
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_STATUS, &msr))
return -17;
p->pkg_temp_c = tcc_activation_temp - ((msr >> 16) & 0x7F);
}
if (DO_BIC(BIC_GFX_rc6))
p->gfx_rc6_ms = gfx_cur_rc6_ms;
if (DO_BIC(BIC_GFXMHz))
p->gfx_mhz = gfx_cur_mhz;
for (i = 0, mp = sys.pp; mp; i++, mp = mp->next) {
if (get_mp(cpu, mp, &p->counter[i]))
return -10;
}
return 0;
}
static void
calculate_tsc_tweak()
{
tsc_tweak = base_hz / tsc_hz;
}
static void
dump_nhm_platform_info(void)
{
unsigned long long msr;
unsigned int ratio;
get_msr(base_cpu, MSR_PLATFORM_INFO, &msr);
fprintf(outf, "cpu%d: MSR_PLATFORM_INFO: 0x%08llx\n", base_cpu, msr);
ratio = (msr >> 40) & 0xFF;
fprintf(outf, "%d * %.1f = %.1f MHz max efficiency frequency\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
fprintf(outf, "%d * %.1f = %.1f MHz base frequency\n",
ratio, bclk, ratio * bclk);
get_msr(base_cpu, MSR_IA32_POWER_CTL, &msr);
fprintf(outf, "cpu%d: MSR_IA32_POWER_CTL: 0x%08llx (C1E auto-promotion: %sabled)\n",
base_cpu, msr, msr & 0x2 ? "EN" : "DIS");
return;
}
static void
dump_hsw_turbo_ratio_limits(void)
{
unsigned long long msr;
unsigned int ratio;
get_msr(base_cpu, MSR_TURBO_RATIO_LIMIT2, &msr);
fprintf(outf, "cpu%d: MSR_TURBO_RATIO_LIMIT2: 0x%08llx\n", base_cpu, msr);
ratio = (msr >> 8) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 18 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 17 active cores\n",
ratio, bclk, ratio * bclk);
return;
}
static void
dump_ivt_turbo_ratio_limits(void)
{
unsigned long long msr;
unsigned int ratio;
get_msr(base_cpu, MSR_TURBO_RATIO_LIMIT1, &msr);
fprintf(outf, "cpu%d: MSR_TURBO_RATIO_LIMIT1: 0x%08llx\n", base_cpu, msr);
ratio = (msr >> 56) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 16 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 48) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 15 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 40) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 14 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 32) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 13 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 24) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 12 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 11 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 10 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 9 active cores\n",
ratio, bclk, ratio * bclk);
return;
}
int has_turbo_ratio_group_limits(int family, int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_ATOM_DENVERTON:
return 1;
}
return 0;
}
static void
dump_turbo_ratio_limits(int family, int model)
{
unsigned long long msr, core_counts;
unsigned int ratio, group_size;
get_msr(base_cpu, MSR_TURBO_RATIO_LIMIT, &msr);
fprintf(outf, "cpu%d: MSR_TURBO_RATIO_LIMIT: 0x%08llx\n", base_cpu, msr);
if (has_turbo_ratio_group_limits(family, model)) {
get_msr(base_cpu, MSR_TURBO_RATIO_LIMIT1, &core_counts);
fprintf(outf, "cpu%d: MSR_TURBO_RATIO_LIMIT1: 0x%08llx\n", base_cpu, core_counts);
} else {
core_counts = 0x0807060504030201;
}
ratio = (msr >> 56) & 0xFF;
group_size = (core_counts >> 56) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 48) & 0xFF;
group_size = (core_counts >> 48) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 40) & 0xFF;
group_size = (core_counts >> 40) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 32) & 0xFF;
group_size = (core_counts >> 32) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 24) & 0xFF;
group_size = (core_counts >> 24) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 16) & 0xFF;
group_size = (core_counts >> 16) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 8) & 0xFF;
group_size = (core_counts >> 8) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
ratio = (msr >> 0) & 0xFF;
group_size = (core_counts >> 0) & 0xFF;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio, bclk, ratio * bclk, group_size);
return;
}
static void
dump_atom_turbo_ratio_limits(void)
{
unsigned long long msr;
unsigned int ratio;
get_msr(base_cpu, MSR_ATOM_CORE_RATIOS, &msr);
fprintf(outf, "cpu%d: MSR_ATOM_CORE_RATIOS: 0x%08llx\n", base_cpu, msr & 0xFFFFFFFF);
ratio = (msr >> 0) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz minimum operating frequency\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz low frequency mode (LFM)\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz base frequency\n",
ratio, bclk, ratio * bclk);
get_msr(base_cpu, MSR_ATOM_CORE_TURBO_RATIOS, &msr);
fprintf(outf, "cpu%d: MSR_ATOM_CORE_TURBO_RATIOS: 0x%08llx\n", base_cpu, msr & 0xFFFFFFFF);
ratio = (msr >> 24) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 4 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 3 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 2 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0x3F;
if (ratio)
fprintf(outf, "%d * %.1f = %.1f MHz max turbo 1 active core\n",
ratio, bclk, ratio * bclk);
}
static void
dump_knl_turbo_ratio_limits(void)
{
const unsigned int buckets_no = 7;
unsigned long long msr;
int delta_cores, delta_ratio;
int i, b_nr;
unsigned int cores[buckets_no];
unsigned int ratio[buckets_no];
get_msr(base_cpu, MSR_TURBO_RATIO_LIMIT, &msr);
fprintf(outf, "cpu%d: MSR_TURBO_RATIO_LIMIT: 0x%08llx\n",
base_cpu, msr);
b_nr = 0;
cores[b_nr] = (msr & 0xFF) >> 1;
ratio[b_nr] = (msr >> 8) & 0xFF;
for (i = 16; i < 64; i += 8) {
delta_cores = (msr >> i) & 0x1F;
delta_ratio = (msr >> (i + 5)) & 0x7;
cores[b_nr + 1] = cores[b_nr] + delta_cores;
ratio[b_nr + 1] = ratio[b_nr] - delta_ratio;
b_nr++;
}
for (i = buckets_no - 1; i >= 0; i--)
if (i > 0 ? ratio[i] != ratio[i - 1] : 1)
fprintf(outf,
"%d * %.1f = %.1f MHz max turbo %d active cores\n",
ratio[i], bclk, ratio[i] * bclk, cores[i]);
}
static void
dump_nhm_cst_cfg(void)
{
unsigned long long msr;
get_msr(base_cpu, MSR_PKG_CST_CONFIG_CONTROL, &msr);
#define SNB_C1_AUTO_UNDEMOTE (1UL << 27)
#define SNB_C3_AUTO_UNDEMOTE (1UL << 28)
fprintf(outf, "cpu%d: MSR_PKG_CST_CONFIG_CONTROL: 0x%08llx", base_cpu, msr);
fprintf(outf, " (%s%s%s%s%slocked: pkg-cstate-limit=%d: %s)\n",
(msr & SNB_C3_AUTO_UNDEMOTE) ? "UNdemote-C3, " : "",
(msr & SNB_C1_AUTO_UNDEMOTE) ? "UNdemote-C1, " : "",
(msr & NHM_C3_AUTO_DEMOTE) ? "demote-C3, " : "",
(msr & NHM_C1_AUTO_DEMOTE) ? "demote-C1, " : "",
(msr & (1 << 15)) ? "" : "UN",
(unsigned int)msr & 0xF,
pkg_cstate_limit_strings[pkg_cstate_limit]);
return;
}
static void
dump_config_tdp(void)
{
unsigned long long msr;
get_msr(base_cpu, MSR_CONFIG_TDP_NOMINAL, &msr);
fprintf(outf, "cpu%d: MSR_CONFIG_TDP_NOMINAL: 0x%08llx", base_cpu, msr);
fprintf(outf, " (base_ratio=%d)\n", (unsigned int)msr & 0xFF);
get_msr(base_cpu, MSR_CONFIG_TDP_LEVEL_1, &msr);
fprintf(outf, "cpu%d: MSR_CONFIG_TDP_LEVEL_1: 0x%08llx (", base_cpu, msr);
if (msr) {
fprintf(outf, "PKG_MIN_PWR_LVL1=%d ", (unsigned int)(msr >> 48) & 0x7FFF);
fprintf(outf, "PKG_MAX_PWR_LVL1=%d ", (unsigned int)(msr >> 32) & 0x7FFF);
fprintf(outf, "LVL1_RATIO=%d ", (unsigned int)(msr >> 16) & 0xFF);
fprintf(outf, "PKG_TDP_LVL1=%d", (unsigned int)(msr) & 0x7FFF);
}
fprintf(outf, ")\n");
get_msr(base_cpu, MSR_CONFIG_TDP_LEVEL_2, &msr);
fprintf(outf, "cpu%d: MSR_CONFIG_TDP_LEVEL_2: 0x%08llx (", base_cpu, msr);
if (msr) {
fprintf(outf, "PKG_MIN_PWR_LVL2=%d ", (unsigned int)(msr >> 48) & 0x7FFF);
fprintf(outf, "PKG_MAX_PWR_LVL2=%d ", (unsigned int)(msr >> 32) & 0x7FFF);
fprintf(outf, "LVL2_RATIO=%d ", (unsigned int)(msr >> 16) & 0xFF);
fprintf(outf, "PKG_TDP_LVL2=%d", (unsigned int)(msr) & 0x7FFF);
}
fprintf(outf, ")\n");
get_msr(base_cpu, MSR_CONFIG_TDP_CONTROL, &msr);
fprintf(outf, "cpu%d: MSR_CONFIG_TDP_CONTROL: 0x%08llx (", base_cpu, msr);
if ((msr) & 0x3)
fprintf(outf, "TDP_LEVEL=%d ", (unsigned int)(msr) & 0x3);
fprintf(outf, " lock=%d", (unsigned int)(msr >> 31) & 1);
fprintf(outf, ")\n");
get_msr(base_cpu, MSR_TURBO_ACTIVATION_RATIO, &msr);
fprintf(outf, "cpu%d: MSR_TURBO_ACTIVATION_RATIO: 0x%08llx (", base_cpu, msr);
fprintf(outf, "MAX_NON_TURBO_RATIO=%d", (unsigned int)(msr) & 0xFF);
fprintf(outf, " lock=%d", (unsigned int)(msr >> 31) & 1);
fprintf(outf, ")\n");
}
void print_irtl(void)
{
unsigned long long msr;
get_msr(base_cpu, MSR_PKGC3_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC3_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
get_msr(base_cpu, MSR_PKGC6_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC6_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
get_msr(base_cpu, MSR_PKGC7_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC7_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
if (!do_irtl_hsw)
return;
get_msr(base_cpu, MSR_PKGC8_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC8_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
get_msr(base_cpu, MSR_PKGC9_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC9_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
get_msr(base_cpu, MSR_PKGC10_IRTL, &msr);
fprintf(outf, "cpu%d: MSR_PKGC10_IRTL: 0x%08llx (", base_cpu, msr);
fprintf(outf, "%svalid, %lld ns)\n", msr & (1 << 15) ? "" : "NOT",
(msr & 0x3FF) * irtl_time_units[(msr >> 10) & 0x3]);
}
void free_fd_percpu(void)
{
int i;
for (i = 0; i < topo.max_cpu_num + 1; ++i) {
if (fd_percpu[i] != 0)
close(fd_percpu[i]);
}
free(fd_percpu);
}
void free_all_buffers(void)
{
CPU_FREE(cpu_present_set);
cpu_present_set = NULL;
cpu_present_setsize = 0;
CPU_FREE(cpu_affinity_set);
cpu_affinity_set = NULL;
cpu_affinity_setsize = 0;
free(thread_even);
free(core_even);
free(package_even);
thread_even = NULL;
core_even = NULL;
package_even = NULL;
free(thread_odd);
free(core_odd);
free(package_odd);
thread_odd = NULL;
core_odd = NULL;
package_odd = NULL;
free(output_buffer);
output_buffer = NULL;
outp = NULL;
free_fd_percpu();
free(irq_column_2_cpu);
free(irqs_per_cpu);
}
int parse_int_file(const char *fmt, ...)
{
va_list args;
char path[PATH_MAX];
FILE *filep;
int value;
va_start(args, fmt);
vsnprintf(path, sizeof(path), fmt, args);
va_end(args);
filep = fopen_or_die(path, "r");
if (fscanf(filep, "%d", &value) != 1)
err(1, "%s: failed to parse number from file", path);
fclose(filep);
return value;
}
int get_cpu_position_in_core(int cpu)
{
char path[64];
FILE *filep;
int this_cpu;
char character;
int i;
sprintf(path,
"/sys/devices/system/cpu/cpu%d/topology/thread_siblings_list",
cpu);
filep = fopen(path, "r");
if (filep == NULL) {
perror(path);
exit(1);
}
for (i = 0; i < topo.num_threads_per_core; i++) {
fscanf(filep, "%d", &this_cpu);
if (this_cpu == cpu) {
fclose(filep);
return i;
}
if (i != (topo.num_threads_per_core - 1))
fscanf(filep, "%c", &character);
}
fclose(filep);
return -1;
}
int cpu_is_first_core_in_package(int cpu)
{
return cpu == parse_int_file("/sys/devices/system/cpu/cpu%d/topology/core_siblings_list", cpu);
}
int get_physical_package_id(int cpu)
{
return parse_int_file("/sys/devices/system/cpu/cpu%d/topology/physical_package_id", cpu);
}
int get_core_id(int cpu)
{
return parse_int_file("/sys/devices/system/cpu/cpu%d/topology/core_id", cpu);
}
int get_num_ht_siblings(int cpu)
{
char path[80];
FILE *filep;
int sib1;
int matches = 0;
char character;
char str[100];
char *ch;
sprintf(path, "/sys/devices/system/cpu/cpu%d/topology/thread_siblings_list", cpu);
filep = fopen_or_die(path, "r");
fscanf(filep, "%d%c\n", &sib1, &character);
fseek(filep, 0, SEEK_SET);
fgets(str, 100, filep);
ch = strchr(str, character);
while (ch != NULL) {
matches++;
ch = strchr(ch+1, character);
}
fclose(filep);
return matches+1;
}
int for_all_cpus_2(int (func)(struct thread_data *, struct core_data *,
struct pkg_data *, struct thread_data *, struct core_data *,
struct pkg_data *), struct thread_data *thread_base,
struct core_data *core_base, struct pkg_data *pkg_base,
struct thread_data *thread_base2, struct core_data *core_base2,
struct pkg_data *pkg_base2)
{
int retval, pkg_no, core_no, thread_no;
for (pkg_no = 0; pkg_no < topo.num_packages; ++pkg_no) {
for (core_no = 0; core_no < topo.num_cores_per_pkg; ++core_no) {
for (thread_no = 0; thread_no <
topo.num_threads_per_core; ++thread_no) {
struct thread_data *t, *t2;
struct core_data *c, *c2;
struct pkg_data *p, *p2;
t = GET_THREAD(thread_base, thread_no, core_no, pkg_no);
if (cpu_is_not_present(t->cpu_id))
continue;
t2 = GET_THREAD(thread_base2, thread_no, core_no, pkg_no);
c = GET_CORE(core_base, core_no, pkg_no);
c2 = GET_CORE(core_base2, core_no, pkg_no);
p = GET_PKG(pkg_base, pkg_no);
p2 = GET_PKG(pkg_base2, pkg_no);
retval = func(t, c, p, t2, c2, p2);
if (retval)
return retval;
}
}
}
return 0;
}
int for_all_proc_cpus(int (func)(int))
{
FILE *fp;
int cpu_num;
int retval;
fp = fopen_or_die(proc_stat, "r");
retval = fscanf(fp, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n");
if (retval != 0)
err(1, "%s: failed to parse format", proc_stat);
while (1) {
retval = fscanf(fp, "cpu%u %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d\n", &cpu_num);
if (retval != 1)
break;
retval = func(cpu_num);
if (retval) {
fclose(fp);
return(retval);
}
}
fclose(fp);
return 0;
}
void re_initialize(void)
{
free_all_buffers();
setup_all_buffers();
printf("turbostat: re-initialized with num_cpus %d\n", topo.num_cpus);
}
int count_cpus(int cpu)
{
if (topo.max_cpu_num < cpu)
topo.max_cpu_num = cpu;
topo.num_cpus += 1;
return 0;
}
int mark_cpu_present(int cpu)
{
CPU_SET_S(cpu, cpu_present_setsize, cpu_present_set);
return 0;
}
int snapshot_proc_interrupts(void)
{
static FILE *fp;
int column, retval;
if (fp == NULL)
fp = fopen_or_die("/proc/interrupts", "r");
else
rewind(fp);
for (column = 0; column < topo.num_cpus; ++column) {
int cpu_number;
retval = fscanf(fp, " CPU%d", &cpu_number);
if (retval != 1)
break;
if (cpu_number > topo.max_cpu_num) {
warn("/proc/interrupts: cpu%d: > %d", cpu_number, topo.max_cpu_num);
return 1;
}
irq_column_2_cpu[column] = cpu_number;
irqs_per_cpu[cpu_number] = 0;
}
while (1) {
int column;
char buf[64];
retval = fscanf(fp, " %s:", buf);
if (retval != 1)
break;
for (column = 0; column < topo.num_cpus; ++column) {
int cpu_number, irq_count;
retval = fscanf(fp, " %d", &irq_count);
if (retval != 1)
break;
cpu_number = irq_column_2_cpu[column];
irqs_per_cpu[cpu_number] += irq_count;
}
while (getc(fp) != '\n')
;
}
return 0;
}
int snapshot_gfx_rc6_ms(void)
{
FILE *fp;
int retval;
fp = fopen_or_die("/sys/class/drm/card0/power/rc6_residency_ms", "r");
retval = fscanf(fp, "%lld", &gfx_cur_rc6_ms);
if (retval != 1)
err(1, "GFX rc6");
fclose(fp);
return 0;
}
int snapshot_gfx_mhz(void)
{
static FILE *fp;
int retval;
if (fp == NULL)
fp = fopen_or_die("/sys/class/graphics/fb0/device/drm/card0/gt_cur_freq_mhz", "r");
else {
rewind(fp);
fflush(fp);
}
retval = fscanf(fp, "%d", &gfx_cur_mhz);
if (retval != 1)
err(1, "GFX MHz");
return 0;
}
int snapshot_proc_sysfs_files(void)
{
if (DO_BIC(BIC_IRQ))
if (snapshot_proc_interrupts())
return 1;
if (DO_BIC(BIC_GFX_rc6))
snapshot_gfx_rc6_ms();
if (DO_BIC(BIC_GFXMHz))
snapshot_gfx_mhz();
return 0;
}
void turbostat_loop()
{
int retval;
int restarted = 0;
restart:
restarted++;
snapshot_proc_sysfs_files();
retval = for_all_cpus(get_counters, EVEN_COUNTERS);
if (retval < -1) {
exit(retval);
} else if (retval == -1) {
if (restarted > 1) {
exit(retval);
}
re_initialize();
goto restart;
}
restarted = 0;
gettimeofday(&tv_even, (struct timezone *)NULL);
while (1) {
if (for_all_proc_cpus(cpu_is_not_present)) {
re_initialize();
goto restart;
}
nanosleep(&interval_ts, NULL);
if (snapshot_proc_sysfs_files())
goto restart;
retval = for_all_cpus(get_counters, ODD_COUNTERS);
if (retval < -1) {
exit(retval);
} else if (retval == -1) {
re_initialize();
goto restart;
}
gettimeofday(&tv_odd, (struct timezone *)NULL);
timersub(&tv_odd, &tv_even, &tv_delta);
if (for_all_cpus_2(delta_cpu, ODD_COUNTERS, EVEN_COUNTERS)) {
re_initialize();
goto restart;
}
compute_average(EVEN_COUNTERS);
format_all_counters(EVEN_COUNTERS);
flush_output_stdout();
nanosleep(&interval_ts, NULL);
if (snapshot_proc_sysfs_files())
goto restart;
retval = for_all_cpus(get_counters, EVEN_COUNTERS);
if (retval < -1) {
exit(retval);
} else if (retval == -1) {
re_initialize();
goto restart;
}
gettimeofday(&tv_even, (struct timezone *)NULL);
timersub(&tv_even, &tv_odd, &tv_delta);
if (for_all_cpus_2(delta_cpu, EVEN_COUNTERS, ODD_COUNTERS)) {
re_initialize();
goto restart;
}
compute_average(ODD_COUNTERS);
format_all_counters(ODD_COUNTERS);
flush_output_stdout();
}
}
void check_dev_msr()
{
struct stat sb;
char pathname[32];
sprintf(pathname, "/dev/cpu/%d/msr", base_cpu);
if (stat(pathname, &sb))
if (system("/sbin/modprobe msr > /dev/null 2>&1"))
err(-5, "no /dev/cpu/0/msr, Try \"# modprobe msr\" ");
}
void check_permissions()
{
struct __user_cap_header_struct cap_header_data;
cap_user_header_t cap_header = &cap_header_data;
struct __user_cap_data_struct cap_data_data;
cap_user_data_t cap_data = &cap_data_data;
extern int capget(cap_user_header_t hdrp, cap_user_data_t datap);
int do_exit = 0;
char pathname[32];
cap_header->pid = getpid();
cap_header->version = _LINUX_CAPABILITY_VERSION;
if (capget(cap_header, cap_data) < 0)
err(-6, "capget(2) failed");
if ((cap_data->effective & (1 << CAP_SYS_RAWIO)) == 0) {
do_exit++;
warnx("capget(CAP_SYS_RAWIO) failed,"
" try \"# setcap cap_sys_rawio=ep %s\"", progname);
}
sprintf(pathname, "/dev/cpu/%d/msr", base_cpu);
if (euidaccess(pathname, R_OK)) {
do_exit++;
warn("/dev/cpu/0/msr open failed, try chown or chmod +r /dev/cpu/*/msr");
}
if (do_exit)
if (getuid() != 0)
warnx("... or simply run as root");
if (do_exit)
exit(-6);
}
int probe_nhm_msrs(unsigned int family, unsigned int model)
{
unsigned long long msr;
unsigned int base_ratio;
int *pkg_cstate_limits;
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
bclk = discover_bclk(family, model);
switch (model) {
case INTEL_FAM6_NEHALEM_EP:
case INTEL_FAM6_NEHALEM:
case 0x1F:
case INTEL_FAM6_WESTMERE:
case INTEL_FAM6_WESTMERE_EP:
case INTEL_FAM6_NEHALEM_EX:
case INTEL_FAM6_WESTMERE_EX:
pkg_cstate_limits = nhm_pkg_cstate_limits;
break;
case INTEL_FAM6_SANDYBRIDGE:
case INTEL_FAM6_SANDYBRIDGE_X:
case INTEL_FAM6_IVYBRIDGE:
case INTEL_FAM6_IVYBRIDGE_X:
pkg_cstate_limits = snb_pkg_cstate_limits;
has_misc_feature_control = 1;
break;
case INTEL_FAM6_HASWELL_CORE:
case INTEL_FAM6_HASWELL_X:
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_HASWELL_GT3E:
case INTEL_FAM6_BROADWELL_CORE:
case INTEL_FAM6_BROADWELL_GT3E:
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
pkg_cstate_limits = hsw_pkg_cstate_limits;
has_misc_feature_control = 1;
break;
case INTEL_FAM6_SKYLAKE_X:
pkg_cstate_limits = skx_pkg_cstate_limits;
has_misc_feature_control = 1;
break;
case INTEL_FAM6_ATOM_SILVERMONT1:
no_MSR_MISC_PWR_MGMT = 1;
case INTEL_FAM6_ATOM_SILVERMONT2:
pkg_cstate_limits = slv_pkg_cstate_limits;
break;
case INTEL_FAM6_ATOM_AIRMONT:
pkg_cstate_limits = amt_pkg_cstate_limits;
no_MSR_MISC_PWR_MGMT = 1;
break;
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
pkg_cstate_limits = phi_pkg_cstate_limits;
break;
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_ATOM_GEMINI_LAKE:
case INTEL_FAM6_ATOM_DENVERTON:
pkg_cstate_limits = bxt_pkg_cstate_limits;
break;
default:
return 0;
}
get_msr(base_cpu, MSR_PKG_CST_CONFIG_CONTROL, &msr);
pkg_cstate_limit = pkg_cstate_limits[msr & 0xF];
get_msr(base_cpu, MSR_PLATFORM_INFO, &msr);
base_ratio = (msr >> 8) & 0xFF;
base_hz = base_ratio * bclk * 1000000;
has_base_hz = 1;
return 1;
}
int has_slv_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_ATOM_SILVERMONT1:
case INTEL_FAM6_ATOM_MERRIFIELD:
case INTEL_FAM6_ATOM_MOOREFIELD:
return 1;
}
return 0;
}
int is_dnv(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_ATOM_DENVERTON:
return 1;
}
return 0;
}
int is_bdx(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
return 1;
}
return 0;
}
int is_skx(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_SKYLAKE_X:
return 1;
}
return 0;
}
int has_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (has_slv_msrs(family, model))
return 0;
switch (model) {
case INTEL_FAM6_NEHALEM_EX:
case INTEL_FAM6_WESTMERE_EX:
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
return 0;
default:
return 1;
}
}
int has_atom_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (has_slv_msrs(family, model))
return 1;
return 0;
}
int has_ivt_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case INTEL_FAM6_IVYBRIDGE_X:
case INTEL_FAM6_HASWELL_X:
return 1;
default:
return 0;
}
}
int has_hsw_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case INTEL_FAM6_HASWELL_X:
return 1;
default:
return 0;
}
}
int has_knl_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
return 1;
default:
return 0;
}
}
int has_glm_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_SKYLAKE_X:
return 1;
default:
return 0;
}
}
int has_config_tdp(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case INTEL_FAM6_IVYBRIDGE:
case INTEL_FAM6_HASWELL_CORE:
case INTEL_FAM6_HASWELL_X:
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_HASWELL_GT3E:
case INTEL_FAM6_BROADWELL_CORE:
case INTEL_FAM6_BROADWELL_GT3E:
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
return 1;
default:
return 0;
}
}
static void
dump_cstate_pstate_config_info(unsigned int family, unsigned int model)
{
if (!do_nhm_platform_info)
return;
dump_nhm_platform_info();
if (has_hsw_turbo_ratio_limit(family, model))
dump_hsw_turbo_ratio_limits();
if (has_ivt_turbo_ratio_limit(family, model))
dump_ivt_turbo_ratio_limits();
if (has_turbo_ratio_limit(family, model))
dump_turbo_ratio_limits(family, model);
if (has_atom_turbo_ratio_limit(family, model))
dump_atom_turbo_ratio_limits();
if (has_knl_turbo_ratio_limit(family, model))
dump_knl_turbo_ratio_limits();
if (has_config_tdp(family, model))
dump_config_tdp();
dump_nhm_cst_cfg();
}
static void
dump_sysfs_cstate_config(void)
{
char path[64];
char name_buf[16];
char desc[64];
FILE *input;
int state;
char *sp;
if (!DO_BIC(BIC_sysfs))
return;
for (state = 0; state < 10; ++state) {
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpuidle/state%d/name",
base_cpu, state);
input = fopen(path, "r");
if (input == NULL)
continue;
fgets(name_buf, sizeof(name_buf), input);
sp = strchr(name_buf, '-');
if (!sp)
sp = strchrnul(name_buf, '\n');
*sp = '\0';
fclose(input);
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpuidle/state%d/desc",
base_cpu, state);
input = fopen(path, "r");
if (input == NULL)
continue;
fgets(desc, sizeof(desc), input);
fprintf(outf, "cpu%d: %s: %s", base_cpu, name_buf, desc);
fclose(input);
}
}
static void
dump_sysfs_pstate_config(void)
{
char path[64];
char driver_buf[64];
char governor_buf[64];
FILE *input;
int turbo;
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpufreq/scaling_driver",
base_cpu);
input = fopen(path, "r");
if (input == NULL) {
fprintf(stderr, "NSFOD %s\n", path);
return;
}
fgets(driver_buf, sizeof(driver_buf), input);
fclose(input);
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpufreq/scaling_governor",
base_cpu);
input = fopen(path, "r");
if (input == NULL) {
fprintf(stderr, "NSFOD %s\n", path);
return;
}
fgets(governor_buf, sizeof(governor_buf), input);
fclose(input);
fprintf(outf, "cpu%d: cpufreq driver: %s", base_cpu, driver_buf);
fprintf(outf, "cpu%d: cpufreq governor: %s", base_cpu, governor_buf);
sprintf(path, "/sys/devices/system/cpu/cpufreq/boost");
input = fopen(path, "r");
if (input != NULL) {
fscanf(input, "%d", &turbo);
fprintf(outf, "cpufreq boost: %d\n", turbo);
fclose(input);
}
sprintf(path, "/sys/devices/system/cpu/intel_pstate/no_turbo");
input = fopen(path, "r");
if (input != NULL) {
fscanf(input, "%d", &turbo);
fprintf(outf, "cpufreq intel_pstate no_turbo: %d\n", turbo);
fclose(input);
}
}
int print_epb(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
char *epb_string;
int cpu;
if (!has_epb)
return 0;
cpu = t->cpu_id;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE) || !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (get_msr(cpu, MSR_IA32_ENERGY_PERF_BIAS, &msr))
return 0;
switch (msr & 0xF) {
case ENERGY_PERF_BIAS_PERFORMANCE:
epb_string = "performance";
break;
case ENERGY_PERF_BIAS_NORMAL:
epb_string = "balanced";
break;
case ENERGY_PERF_BIAS_POWERSAVE:
epb_string = "powersave";
break;
default:
epb_string = "custom";
break;
}
fprintf(outf, "cpu%d: MSR_IA32_ENERGY_PERF_BIAS: 0x%08llx (%s)\n", cpu, msr, epb_string);
return 0;
}
int print_hwp(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
int cpu;
if (!has_hwp)
return 0;
cpu = t->cpu_id;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE) || !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (get_msr(cpu, MSR_PM_ENABLE, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_PM_ENABLE: 0x%08llx (%sHWP)\n",
cpu, msr, (msr & (1 << 0)) ? "" : "No-");
if ((msr & (1 << 0)) == 0)
return 0;
if (get_msr(cpu, MSR_HWP_CAPABILITIES, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_HWP_CAPABILITIES: 0x%08llx "
"(high %d guar %d eff %d low %d)\n",
cpu, msr,
(unsigned int)HWP_HIGHEST_PERF(msr),
(unsigned int)HWP_GUARANTEED_PERF(msr),
(unsigned int)HWP_MOSTEFFICIENT_PERF(msr),
(unsigned int)HWP_LOWEST_PERF(msr));
if (get_msr(cpu, MSR_HWP_REQUEST, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_HWP_REQUEST: 0x%08llx "
"(min %d max %d des %d epp 0x%x window 0x%x pkg 0x%x)\n",
cpu, msr,
(unsigned int)(((msr) >> 0) & 0xff),
(unsigned int)(((msr) >> 8) & 0xff),
(unsigned int)(((msr) >> 16) & 0xff),
(unsigned int)(((msr) >> 24) & 0xff),
(unsigned int)(((msr) >> 32) & 0xff3),
(unsigned int)(((msr) >> 42) & 0x1));
if (has_hwp_pkg) {
if (get_msr(cpu, MSR_HWP_REQUEST_PKG, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_HWP_REQUEST_PKG: 0x%08llx "
"(min %d max %d des %d epp 0x%x window 0x%x)\n",
cpu, msr,
(unsigned int)(((msr) >> 0) & 0xff),
(unsigned int)(((msr) >> 8) & 0xff),
(unsigned int)(((msr) >> 16) & 0xff),
(unsigned int)(((msr) >> 24) & 0xff),
(unsigned int)(((msr) >> 32) & 0xff3));
}
if (has_hwp_notify) {
if (get_msr(cpu, MSR_HWP_INTERRUPT, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_HWP_INTERRUPT: 0x%08llx "
"(%s_Guaranteed_Perf_Change, %s_Excursion_Min)\n",
cpu, msr,
((msr) & 0x1) ? "EN" : "Dis",
((msr) & 0x2) ? "EN" : "Dis");
}
if (get_msr(cpu, MSR_HWP_STATUS, &msr))
return 0;
fprintf(outf, "cpu%d: MSR_HWP_STATUS: 0x%08llx "
"(%sGuaranteed_Perf_Change, %sExcursion_Min)\n",
cpu, msr,
((msr) & 0x1) ? "" : "No-",
((msr) & 0x2) ? "" : "No-");
return 0;
}
int print_perf_limit(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
int cpu;
cpu = t->cpu_id;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE) || !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (do_core_perf_limit_reasons) {
get_msr(cpu, MSR_CORE_PERF_LIMIT_REASONS, &msr);
fprintf(outf, "cpu%d: MSR_CORE_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(outf, " (Active: %s%s%s%s%s%s%s%s%s%s%s%s%s%s)",
(msr & 1 << 15) ? "bit15, " : "",
(msr & 1 << 14) ? "bit14, " : "",
(msr & 1 << 13) ? "Transitions, " : "",
(msr & 1 << 12) ? "MultiCoreTurbo, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 9) ? "CorePwr, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 5) ? "Auto-HWP, " : "",
(msr & 1 << 4) ? "Graphics, " : "",
(msr & 1 << 2) ? "bit2, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 0) ? "PROCHOT, " : "");
fprintf(outf, " (Logged: %s%s%s%s%s%s%s%s%s%s%s%s%s%s)\n",
(msr & 1 << 31) ? "bit31, " : "",
(msr & 1 << 30) ? "bit30, " : "",
(msr & 1 << 29) ? "Transitions, " : "",
(msr & 1 << 28) ? "MultiCoreTurbo, " : "",
(msr & 1 << 27) ? "PkgPwrL2, " : "",
(msr & 1 << 26) ? "PkgPwrL1, " : "",
(msr & 1 << 25) ? "CorePwr, " : "",
(msr & 1 << 24) ? "Amps, " : "",
(msr & 1 << 22) ? "VR-Therm, " : "",
(msr & 1 << 21) ? "Auto-HWP, " : "",
(msr & 1 << 20) ? "Graphics, " : "",
(msr & 1 << 18) ? "bit18, " : "",
(msr & 1 << 17) ? "ThermStatus, " : "",
(msr & 1 << 16) ? "PROCHOT, " : "");
}
if (do_gfx_perf_limit_reasons) {
get_msr(cpu, MSR_GFX_PERF_LIMIT_REASONS, &msr);
fprintf(outf, "cpu%d: MSR_GFX_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(outf, " (Active: %s%s%s%s%s%s%s%s)",
(msr & 1 << 0) ? "PROCHOT, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 4) ? "Graphics, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 9) ? "GFXPwr, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "");
fprintf(outf, " (Logged: %s%s%s%s%s%s%s%s)\n",
(msr & 1 << 16) ? "PROCHOT, " : "",
(msr & 1 << 17) ? "ThermStatus, " : "",
(msr & 1 << 20) ? "Graphics, " : "",
(msr & 1 << 22) ? "VR-Therm, " : "",
(msr & 1 << 24) ? "Amps, " : "",
(msr & 1 << 25) ? "GFXPwr, " : "",
(msr & 1 << 26) ? "PkgPwrL1, " : "",
(msr & 1 << 27) ? "PkgPwrL2, " : "");
}
if (do_ring_perf_limit_reasons) {
get_msr(cpu, MSR_RING_PERF_LIMIT_REASONS, &msr);
fprintf(outf, "cpu%d: MSR_RING_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(outf, " (Active: %s%s%s%s%s%s)",
(msr & 1 << 0) ? "PROCHOT, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "");
fprintf(outf, " (Logged: %s%s%s%s%s%s)\n",
(msr & 1 << 16) ? "PROCHOT, " : "",
(msr & 1 << 17) ? "ThermStatus, " : "",
(msr & 1 << 22) ? "VR-Therm, " : "",
(msr & 1 << 24) ? "Amps, " : "",
(msr & 1 << 26) ? "PkgPwrL1, " : "",
(msr & 1 << 27) ? "PkgPwrL2, " : "");
}
return 0;
}
double get_tdp(unsigned int model)
{
unsigned long long msr;
if (do_rapl & RAPL_PKG_POWER_INFO)
if (!get_msr(base_cpu, MSR_PKG_POWER_INFO, &msr))
return ((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units;
switch (model) {
case INTEL_FAM6_ATOM_SILVERMONT1:
case INTEL_FAM6_ATOM_SILVERMONT2:
return 30.0;
default:
return 135.0;
}
}
static double
rapl_dram_energy_units_probe(int model, double rapl_energy_units)
{
switch (model) {
case INTEL_FAM6_HASWELL_X:
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
return (rapl_dram_energy_units = 15.3 / 1000000);
default:
return (rapl_energy_units);
}
}
void rapl_probe(unsigned int family, unsigned int model)
{
unsigned long long msr;
unsigned int time_unit;
double tdp;
if (!genuine_intel)
return;
if (family != 6)
return;
switch (model) {
case INTEL_FAM6_SANDYBRIDGE:
case INTEL_FAM6_IVYBRIDGE:
case INTEL_FAM6_HASWELL_CORE:
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_HASWELL_GT3E:
case INTEL_FAM6_BROADWELL_CORE:
case INTEL_FAM6_BROADWELL_GT3E:
do_rapl = RAPL_PKG | RAPL_CORES | RAPL_CORE_POLICY | RAPL_GFX | RAPL_PKG_POWER_INFO;
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_Cor_J);
BIC_PRESENT(BIC_GFX_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_CorWatt);
BIC_PRESENT(BIC_GFXWatt);
}
break;
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_ATOM_GEMINI_LAKE:
do_rapl = RAPL_PKG | RAPL_PKG_POWER_INFO;
if (rapl_joules)
BIC_PRESENT(BIC_Pkg_J);
else
BIC_PRESENT(BIC_PkgWatt);
break;
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
do_rapl = RAPL_PKG | RAPL_CORES | RAPL_CORE_POLICY | RAPL_DRAM | RAPL_DRAM_PERF_STATUS | RAPL_PKG_PERF_STATUS | RAPL_GFX | RAPL_PKG_POWER_INFO;
BIC_PRESENT(BIC_PKG__);
BIC_PRESENT(BIC_RAM__);
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_Cor_J);
BIC_PRESENT(BIC_RAM_J);
BIC_PRESENT(BIC_GFX_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_CorWatt);
BIC_PRESENT(BIC_RAMWatt);
BIC_PRESENT(BIC_GFXWatt);
}
break;
case INTEL_FAM6_HASWELL_X:
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
do_rapl = RAPL_PKG | RAPL_DRAM | RAPL_DRAM_POWER_INFO | RAPL_DRAM_PERF_STATUS | RAPL_PKG_PERF_STATUS | RAPL_PKG_POWER_INFO;
BIC_PRESENT(BIC_PKG__);
BIC_PRESENT(BIC_RAM__);
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_RAM_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_RAMWatt);
}
break;
case INTEL_FAM6_SANDYBRIDGE_X:
case INTEL_FAM6_IVYBRIDGE_X:
do_rapl = RAPL_PKG | RAPL_CORES | RAPL_CORE_POLICY | RAPL_DRAM | RAPL_DRAM_POWER_INFO | RAPL_PKG_PERF_STATUS | RAPL_DRAM_PERF_STATUS | RAPL_PKG_POWER_INFO;
BIC_PRESENT(BIC_PKG__);
BIC_PRESENT(BIC_RAM__);
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_Cor_J);
BIC_PRESENT(BIC_RAM_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_CorWatt);
BIC_PRESENT(BIC_RAMWatt);
}
break;
case INTEL_FAM6_ATOM_SILVERMONT1:
case INTEL_FAM6_ATOM_SILVERMONT2:
do_rapl = RAPL_PKG | RAPL_CORES;
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_Cor_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_CorWatt);
}
break;
case INTEL_FAM6_ATOM_DENVERTON:
do_rapl = RAPL_PKG | RAPL_DRAM | RAPL_DRAM_POWER_INFO | RAPL_DRAM_PERF_STATUS | RAPL_PKG_PERF_STATUS | RAPL_PKG_POWER_INFO | RAPL_CORES_ENERGY_STATUS;
BIC_PRESENT(BIC_PKG__);
BIC_PRESENT(BIC_RAM__);
if (rapl_joules) {
BIC_PRESENT(BIC_Pkg_J);
BIC_PRESENT(BIC_Cor_J);
BIC_PRESENT(BIC_RAM_J);
} else {
BIC_PRESENT(BIC_PkgWatt);
BIC_PRESENT(BIC_CorWatt);
BIC_PRESENT(BIC_RAMWatt);
}
break;
default:
return;
}
if (get_msr(base_cpu, MSR_RAPL_POWER_UNIT, &msr))
return;
rapl_power_units = 1.0 / (1 << (msr & 0xF));
if (model == INTEL_FAM6_ATOM_SILVERMONT1)
rapl_energy_units = 1.0 * (1 << (msr >> 8 & 0x1F)) / 1000000;
else
rapl_energy_units = 1.0 / (1 << (msr >> 8 & 0x1F));
rapl_dram_energy_units = rapl_dram_energy_units_probe(model, rapl_energy_units);
time_unit = msr >> 16 & 0xF;
if (time_unit == 0)
time_unit = 0xA;
rapl_time_units = 1.0 / (1 << (time_unit));
tdp = get_tdp(model);
rapl_joule_counter_range = 0xFFFFFFFF * rapl_energy_units / tdp;
if (!quiet)
fprintf(outf, "RAPL: %.0f sec. Joule Counter Range, at %.0f Watts\n", rapl_joule_counter_range, tdp);
return;
}
void perf_limit_reasons_probe(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return;
if (family != 6)
return;
switch (model) {
case INTEL_FAM6_HASWELL_CORE:
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_HASWELL_GT3E:
do_gfx_perf_limit_reasons = 1;
case INTEL_FAM6_HASWELL_X:
do_core_perf_limit_reasons = 1;
do_ring_perf_limit_reasons = 1;
default:
return;
}
}
int print_thermal(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
unsigned int dts, dts2;
int cpu;
if (!(do_dts || do_ptm))
return 0;
cpu = t->cpu_id;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (do_ptm && (t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE)) {
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_STATUS, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
fprintf(outf, "cpu%d: MSR_IA32_PACKAGE_THERM_STATUS: 0x%08llx (%d C)\n",
cpu, msr, tcc_activation_temp - dts);
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
dts2 = (msr >> 8) & 0x7F;
fprintf(outf, "cpu%d: MSR_IA32_PACKAGE_THERM_INTERRUPT: 0x%08llx (%d C, %d C)\n",
cpu, msr, tcc_activation_temp - dts, tcc_activation_temp - dts2);
}
if (do_dts && debug) {
unsigned int resolution;
if (get_msr(cpu, MSR_IA32_THERM_STATUS, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
resolution = (msr >> 27) & 0xF;
fprintf(outf, "cpu%d: MSR_IA32_THERM_STATUS: 0x%08llx (%d C +/- %d)\n",
cpu, msr, tcc_activation_temp - dts, resolution);
if (get_msr(cpu, MSR_IA32_THERM_INTERRUPT, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
dts2 = (msr >> 8) & 0x7F;
fprintf(outf, "cpu%d: MSR_IA32_THERM_INTERRUPT: 0x%08llx (%d C, %d C)\n",
cpu, msr, tcc_activation_temp - dts, tcc_activation_temp - dts2);
}
return 0;
}
void print_power_limit_msr(int cpu, unsigned long long msr, char *label)
{
fprintf(outf, "cpu%d: %s: %sabled (%f Watts, %f sec, clamp %sabled)\n",
cpu, label,
((msr >> 15) & 1) ? "EN" : "DIS",
((msr >> 0) & 0x7FFF) * rapl_power_units,
(1.0 + (((msr >> 22) & 0x3)/4.0)) * (1 << ((msr >> 17) & 0x1F)) * rapl_time_units,
(((msr >> 16) & 1) ? "EN" : "DIS"));
return;
}
int print_rapl(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
int cpu;
if (!do_rapl)
return 0;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE) || !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
cpu = t->cpu_id;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (get_msr(cpu, MSR_RAPL_POWER_UNIT, &msr))
return -1;
fprintf(outf, "cpu%d: MSR_RAPL_POWER_UNIT: 0x%08llx (%f Watts, %f Joules, %f sec.)\n", cpu, msr,
rapl_power_units, rapl_energy_units, rapl_time_units);
if (do_rapl & RAPL_PKG_POWER_INFO) {
if (get_msr(cpu, MSR_PKG_POWER_INFO, &msr))
return -5;
fprintf(outf, "cpu%d: MSR_PKG_POWER_INFO: 0x%08llx (%.0f W TDP, RAPL %.0f - %.0f W, %f sec.)\n",
cpu, msr,
((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 16) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 32) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 48) & RAPL_TIME_GRANULARITY) * rapl_time_units);
}
if (do_rapl & RAPL_PKG) {
if (get_msr(cpu, MSR_PKG_POWER_LIMIT, &msr))
return -9;
fprintf(outf, "cpu%d: MSR_PKG_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 63) & 1 ? "" : "UN");
print_power_limit_msr(cpu, msr, "PKG Limit #1");
fprintf(outf, "cpu%d: PKG Limit #2: %sabled (%f Watts, %f* sec, clamp %sabled)\n",
cpu,
((msr >> 47) & 1) ? "EN" : "DIS",
((msr >> 32) & 0x7FFF) * rapl_power_units,
(1.0 + (((msr >> 54) & 0x3)/4.0)) * (1 << ((msr >> 49) & 0x1F)) * rapl_time_units,
((msr >> 48) & 1) ? "EN" : "DIS");
}
if (do_rapl & RAPL_DRAM_POWER_INFO) {
if (get_msr(cpu, MSR_DRAM_POWER_INFO, &msr))
return -6;
fprintf(outf, "cpu%d: MSR_DRAM_POWER_INFO,: 0x%08llx (%.0f W TDP, RAPL %.0f - %.0f W, %f sec.)\n",
cpu, msr,
((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 16) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 32) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 48) & RAPL_TIME_GRANULARITY) * rapl_time_units);
}
if (do_rapl & RAPL_DRAM) {
if (get_msr(cpu, MSR_DRAM_POWER_LIMIT, &msr))
return -9;
fprintf(outf, "cpu%d: MSR_DRAM_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "" : "UN");
print_power_limit_msr(cpu, msr, "DRAM Limit");
}
if (do_rapl & RAPL_CORE_POLICY) {
if (get_msr(cpu, MSR_PP0_POLICY, &msr))
return -7;
fprintf(outf, "cpu%d: MSR_PP0_POLICY: %lld\n", cpu, msr & 0xF);
}
if (do_rapl & RAPL_CORES_POWER_LIMIT) {
if (get_msr(cpu, MSR_PP0_POWER_LIMIT, &msr))
return -9;
fprintf(outf, "cpu%d: MSR_PP0_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "" : "UN");
print_power_limit_msr(cpu, msr, "Cores Limit");
}
if (do_rapl & RAPL_GFX) {
if (get_msr(cpu, MSR_PP1_POLICY, &msr))
return -8;
fprintf(outf, "cpu%d: MSR_PP1_POLICY: %lld\n", cpu, msr & 0xF);
if (get_msr(cpu, MSR_PP1_POWER_LIMIT, &msr))
return -9;
fprintf(outf, "cpu%d: MSR_PP1_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "" : "UN");
print_power_limit_msr(cpu, msr, "GFX Limit");
}
return 0;
}
int has_snb_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_SANDYBRIDGE:
case INTEL_FAM6_SANDYBRIDGE_X:
case INTEL_FAM6_IVYBRIDGE:
case INTEL_FAM6_IVYBRIDGE_X:
case INTEL_FAM6_HASWELL_CORE:
case INTEL_FAM6_HASWELL_X:
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_HASWELL_GT3E:
case INTEL_FAM6_BROADWELL_CORE:
case INTEL_FAM6_BROADWELL_GT3E:
case INTEL_FAM6_BROADWELL_X:
case INTEL_FAM6_BROADWELL_XEON_D:
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_ATOM_GEMINI_LAKE:
case INTEL_FAM6_ATOM_DENVERTON:
return 1;
}
return 0;
}
int has_hsw_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_HASWELL_ULT:
case INTEL_FAM6_BROADWELL_CORE:
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_ATOM_GEMINI_LAKE:
return 1;
}
return 0;
}
int has_skl_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
return 1;
}
return 0;
}
int is_slm(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_ATOM_SILVERMONT1:
case INTEL_FAM6_ATOM_SILVERMONT2:
return 1;
}
return 0;
}
int is_knl(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case INTEL_FAM6_XEON_PHI_KNL:
case INTEL_FAM6_XEON_PHI_KNM:
return 1;
}
return 0;
}
unsigned int get_aperf_mperf_multiplier(unsigned int family, unsigned int model)
{
if (is_knl(family, model))
return 1024;
return 1;
}
double slm_bclk(void)
{
unsigned long long msr = 3;
unsigned int i;
double freq;
if (get_msr(base_cpu, MSR_FSB_FREQ, &msr))
fprintf(outf, "SLM BCLK: unknown\n");
i = msr & 0xf;
if (i >= SLM_BCLK_FREQS) {
fprintf(outf, "SLM BCLK[%d] invalid\n", i);
i = 3;
}
freq = slm_freq_table[i];
if (!quiet)
fprintf(outf, "SLM BCLK: %.1f Mhz\n", freq);
return freq;
}
double discover_bclk(unsigned int family, unsigned int model)
{
if (has_snb_msrs(family, model) || is_knl(family, model))
return 100.00;
else if (is_slm(family, model))
return slm_bclk();
else
return 133.33;
}
int set_temperature_target(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
unsigned int target_c_local;
int cpu;
if (!(do_dts || do_ptm))
return 0;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE) || !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
cpu = t->cpu_id;
if (cpu_migrate(cpu)) {
fprintf(outf, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (tcc_activation_temp_override != 0) {
tcc_activation_temp = tcc_activation_temp_override;
fprintf(outf, "cpu%d: Using cmdline TCC Target (%d C)\n",
cpu, tcc_activation_temp);
return 0;
}
if (!do_nhm_platform_info)
goto guess;
if (get_msr(base_cpu, MSR_IA32_TEMPERATURE_TARGET, &msr))
goto guess;
target_c_local = (msr >> 16) & 0xFF;
if (!quiet)
fprintf(outf, "cpu%d: MSR_IA32_TEMPERATURE_TARGET: 0x%08llx (%d C)\n",
cpu, msr, target_c_local);
if (!target_c_local)
goto guess;
tcc_activation_temp = target_c_local;
return 0;
guess:
tcc_activation_temp = TJMAX_DEFAULT;
fprintf(outf, "cpu%d: Guessing tjMax %d C, Please use -T to specify\n",
cpu, tcc_activation_temp);
return 0;
}
void decode_feature_control_msr(void)
{
unsigned long long msr;
if (!get_msr(base_cpu, MSR_IA32_FEATURE_CONTROL, &msr))
fprintf(outf, "cpu%d: MSR_IA32_FEATURE_CONTROL: 0x%08llx (%sLocked %s)\n",
base_cpu, msr,
msr & FEATURE_CONTROL_LOCKED ? "" : "UN-",
msr & (1 << 18) ? "SGX" : "");
}
void decode_misc_enable_msr(void)
{
unsigned long long msr;
if (!get_msr(base_cpu, MSR_IA32_MISC_ENABLE, &msr))
fprintf(outf, "cpu%d: MSR_IA32_MISC_ENABLE: 0x%08llx (%sTCC %sEIST %sMWAIT %sPREFETCH %sTURBO)\n",
base_cpu, msr,
msr & MSR_IA32_MISC_ENABLE_TM1 ? "" : "No-",
msr & MSR_IA32_MISC_ENABLE_ENHANCED_SPEEDSTEP ? "" : "No-",
msr & MSR_IA32_MISC_ENABLE_MWAIT ? "No-" : "",
msr & MSR_IA32_MISC_ENABLE_PREFETCH_DISABLE ? "No-" : "",
msr & MSR_IA32_MISC_ENABLE_TURBO_DISABLE ? "No-" : "");
}
void decode_misc_feature_control(void)
{
unsigned long long msr;
if (!has_misc_feature_control)
return;
if (!get_msr(base_cpu, MSR_MISC_FEATURE_CONTROL, &msr))
fprintf(outf, "cpu%d: MSR_MISC_FEATURE_CONTROL: 0x%08llx (%sL2-Prefetch %sL2-Prefetch-pair %sL1-Prefetch %sL1-IP-Prefetch)\n",
base_cpu, msr,
msr & (0 << 0) ? "No-" : "",
msr & (1 << 0) ? "No-" : "",
msr & (2 << 0) ? "No-" : "",
msr & (3 << 0) ? "No-" : "");
}
void decode_misc_pwr_mgmt_msr(void)
{
unsigned long long msr;
if (!do_nhm_platform_info)
return;
if (no_MSR_MISC_PWR_MGMT)
return;
if (!get_msr(base_cpu, MSR_MISC_PWR_MGMT, &msr))
fprintf(outf, "cpu%d: MSR_MISC_PWR_MGMT: 0x%08llx (%sable-EIST_Coordination %sable-EPB %sable-OOB)\n",
base_cpu, msr,
msr & (1 << 0) ? "DIS" : "EN",
msr & (1 << 1) ? "EN" : "DIS",
msr & (1 << 8) ? "EN" : "DIS");
}
void decode_c6_demotion_policy_msr(void)
{
unsigned long long msr;
if (!get_msr(base_cpu, MSR_CC6_DEMOTION_POLICY_CONFIG, &msr))
fprintf(outf, "cpu%d: MSR_CC6_DEMOTION_POLICY_CONFIG: 0x%08llx (%sable-CC6-Demotion)\n",
base_cpu, msr, msr & (1 << 0) ? "EN" : "DIS");
if (!get_msr(base_cpu, MSR_MC6_DEMOTION_POLICY_CONFIG, &msr))
fprintf(outf, "cpu%d: MSR_MC6_DEMOTION_POLICY_CONFIG: 0x%08llx (%sable-MC6-Demotion)\n",
base_cpu, msr, msr & (1 << 0) ? "EN" : "DIS");
}
void process_cpuid()
{
unsigned int eax, ebx, ecx, edx, max_level, max_extended_level;
unsigned int fms, family, model, stepping;
unsigned int has_turbo;
eax = ebx = ecx = edx = 0;
__cpuid(0, max_level, ebx, ecx, edx);
if (ebx == 0x756e6547 && edx == 0x49656e69 && ecx == 0x6c65746e)
genuine_intel = 1;
if (!quiet)
fprintf(outf, "CPUID(0): %.4s%.4s%.4s ",
(char *)&ebx, (char *)&edx, (char *)&ecx);
__cpuid(1, fms, ebx, ecx, edx);
family = (fms >> 8) & 0xf;
model = (fms >> 4) & 0xf;
stepping = fms & 0xf;
if (family == 6 || family == 0xf)
model += ((fms >> 16) & 0xf) << 4;
if (!quiet) {
fprintf(outf, "%d CPUID levels; family:model:stepping 0x%x:%x:%x (%d:%d:%d)\n",
max_level, family, model, stepping, family, model, stepping);
fprintf(outf, "CPUID(1): %s %s %s %s %s %s %s %s %s\n",
ecx & (1 << 0) ? "SSE3" : "-",
ecx & (1 << 3) ? "MONITOR" : "-",
ecx & (1 << 6) ? "SMX" : "-",
ecx & (1 << 7) ? "EIST" : "-",
ecx & (1 << 8) ? "TM2" : "-",
edx & (1 << 4) ? "TSC" : "-",
edx & (1 << 5) ? "MSR" : "-",
edx & (1 << 22) ? "ACPI-TM" : "-",
edx & (1 << 29) ? "TM" : "-");
}
if (!(edx & (1 << 5)))
errx(1, "CPUID: no MSR");
ebx = ecx = edx = 0;
__cpuid(0x80000000, max_extended_level, ebx, ecx, edx);
if (max_extended_level >= 0x80000007) {
__cpuid(0x80000007, eax, ebx, ecx, edx);
has_invariant_tsc = edx & (1 << 8);
}
__cpuid(0x6, eax, ebx, ecx, edx);
has_aperf = ecx & (1 << 0);
if (has_aperf) {
BIC_PRESENT(BIC_Avg_MHz);
BIC_PRESENT(BIC_Busy);
BIC_PRESENT(BIC_Bzy_MHz);
}
do_dts = eax & (1 << 0);
if (do_dts)
BIC_PRESENT(BIC_CoreTmp);
has_turbo = eax & (1 << 1);
do_ptm = eax & (1 << 6);
if (do_ptm)
BIC_PRESENT(BIC_PkgTmp);
has_hwp = eax & (1 << 7);
has_hwp_notify = eax & (1 << 8);
has_hwp_activity_window = eax & (1 << 9);
has_hwp_epp = eax & (1 << 10);
has_hwp_pkg = eax & (1 << 11);
has_epb = ecx & (1 << 3);
if (!quiet)
fprintf(outf, "CPUID(6): %sAPERF, %sTURBO, %sDTS, %sPTM, %sHWP, "
"%sHWPnotify, %sHWPwindow, %sHWPepp, %sHWPpkg, %sEPB\n",
has_aperf ? "" : "No-",
has_turbo ? "" : "No-",
do_dts ? "" : "No-",
do_ptm ? "" : "No-",
has_hwp ? "" : "No-",
has_hwp_notify ? "" : "No-",
has_hwp_activity_window ? "" : "No-",
has_hwp_epp ? "" : "No-",
has_hwp_pkg ? "" : "No-",
has_epb ? "" : "No-");
if (!quiet)
decode_misc_enable_msr();
if (max_level >= 0x7 && !quiet) {
int has_sgx;
ecx = 0;
__cpuid_count(0x7, 0, eax, ebx, ecx, edx);
has_sgx = ebx & (1 << 2);
fprintf(outf, "CPUID(7): %sSGX\n", has_sgx ? "" : "No-");
if (has_sgx)
decode_feature_control_msr();
}
if (max_level >= 0x15) {
unsigned int eax_crystal;
unsigned int ebx_tsc;
eax_crystal = ebx_tsc = crystal_hz = edx = 0;
__cpuid(0x15, eax_crystal, ebx_tsc, crystal_hz, edx);
if (ebx_tsc != 0) {
if (!quiet && (ebx != 0))
fprintf(outf, "CPUID(0x15): eax_crystal: %d ebx_tsc: %d ecx_crystal_hz: %d\n",
eax_crystal, ebx_tsc, crystal_hz);
if (crystal_hz == 0)
switch(model) {
case INTEL_FAM6_SKYLAKE_MOBILE:
case INTEL_FAM6_SKYLAKE_DESKTOP:
case INTEL_FAM6_KABYLAKE_MOBILE:
case INTEL_FAM6_KABYLAKE_DESKTOP:
crystal_hz = 24000000;
break;
case INTEL_FAM6_SKYLAKE_X:
case INTEL_FAM6_ATOM_DENVERTON:
crystal_hz = 25000000;
break;
case INTEL_FAM6_ATOM_GOLDMONT:
case INTEL_FAM6_ATOM_GEMINI_LAKE:
crystal_hz = 19200000;
break;
default:
crystal_hz = 0;
}
if (crystal_hz) {
tsc_hz = (unsigned long long) crystal_hz * ebx_tsc / eax_crystal;
if (!quiet)
fprintf(outf, "TSC: %lld MHz (%d Hz * %d / %d / 1000000)\n",
tsc_hz / 1000000, crystal_hz, ebx_tsc, eax_crystal);
}
}
}
if (max_level >= 0x16) {
unsigned int base_mhz, max_mhz, bus_mhz, edx;
base_mhz = max_mhz = bus_mhz = edx = 0;
__cpuid(0x16, base_mhz, max_mhz, bus_mhz, edx);
if (!quiet)
fprintf(outf, "CPUID(0x16): base_mhz: %d max_mhz: %d bus_mhz: %d\n",
base_mhz, max_mhz, bus_mhz);
}
if (has_aperf)
aperf_mperf_multiplier = get_aperf_mperf_multiplier(family, model);
BIC_PRESENT(BIC_IRQ);
BIC_PRESENT(BIC_TSC_MHz);
if (probe_nhm_msrs(family, model)) {
do_nhm_platform_info = 1;
BIC_PRESENT(BIC_CPU_c1);
BIC_PRESENT(BIC_CPU_c3);
BIC_PRESENT(BIC_CPU_c6);
BIC_PRESENT(BIC_SMI);
}
do_snb_cstates = has_snb_msrs(family, model);
if (do_snb_cstates)
BIC_PRESENT(BIC_CPU_c7);
do_irtl_snb = has_snb_msrs(family, model);
if (do_snb_cstates && (pkg_cstate_limit >= PCL__2))
BIC_PRESENT(BIC_Pkgpc2);
if (pkg_cstate_limit >= PCL__3)
BIC_PRESENT(BIC_Pkgpc3);
if (pkg_cstate_limit >= PCL__6)
BIC_PRESENT(BIC_Pkgpc6);
if (do_snb_cstates && (pkg_cstate_limit >= PCL__7))
BIC_PRESENT(BIC_Pkgpc7);
if (has_slv_msrs(family, model)) {
BIC_NOT_PRESENT(BIC_Pkgpc2);
BIC_NOT_PRESENT(BIC_Pkgpc3);
BIC_PRESENT(BIC_Pkgpc6);
BIC_NOT_PRESENT(BIC_Pkgpc7);
BIC_PRESENT(BIC_Mod_c6);
use_c1_residency_msr = 1;
}
if (is_dnv(family, model)) {
BIC_PRESENT(BIC_CPU_c1);
BIC_NOT_PRESENT(BIC_CPU_c3);
BIC_NOT_PRESENT(BIC_Pkgpc3);
BIC_NOT_PRESENT(BIC_CPU_c7);
BIC_NOT_PRESENT(BIC_Pkgpc7);
use_c1_residency_msr = 1;
}
if (is_skx(family, model)) {
BIC_NOT_PRESENT(BIC_CPU_c3);
BIC_NOT_PRESENT(BIC_Pkgpc3);
BIC_NOT_PRESENT(BIC_CPU_c7);
BIC_NOT_PRESENT(BIC_Pkgpc7);
}
if (is_bdx(family, model)) {
BIC_NOT_PRESENT(BIC_CPU_c7);
BIC_NOT_PRESENT(BIC_Pkgpc7);
}
if (has_hsw_msrs(family, model)) {
BIC_PRESENT(BIC_Pkgpc8);
BIC_PRESENT(BIC_Pkgpc9);
BIC_PRESENT(BIC_Pkgpc10);
}
do_irtl_hsw = has_hsw_msrs(family, model);
do_skl_residency = has_skl_msrs(family, model);
do_slm_cstates = is_slm(family, model);
do_knl_cstates = is_knl(family, model);
if (!quiet)
decode_misc_pwr_mgmt_msr();
if (!quiet && has_slv_msrs(family, model))
decode_c6_demotion_policy_msr();
rapl_probe(family, model);
perf_limit_reasons_probe(family, model);
if (!quiet)
dump_cstate_pstate_config_info(family, model);
if (!quiet)
dump_sysfs_cstate_config();
if (!quiet)
dump_sysfs_pstate_config();
if (has_skl_msrs(family, model))
calculate_tsc_tweak();
if (!access("/sys/class/drm/card0/power/rc6_residency_ms", R_OK))
BIC_PRESENT(BIC_GFX_rc6);
if (!access("/sys/class/graphics/fb0/device/drm/card0/gt_cur_freq_mhz", R_OK))
BIC_PRESENT(BIC_GFXMHz);
if (!quiet)
decode_misc_feature_control();
return;
}
int dir_filter(const struct dirent *dirp)
{
if (isdigit(dirp->d_name[0]))
return 1;
else
return 0;
}
int open_dev_cpu_msr(int dummy1)
{
return 0;
}
void topology_probe()
{
int i;
int max_core_id = 0;
int max_package_id = 0;
int max_siblings = 0;
struct cpu_topology {
int core_id;
int physical_package_id;
} *cpus;
topo.num_cpus = 0;
topo.max_cpu_num = 0;
for_all_proc_cpus(count_cpus);
if (!summary_only && topo.num_cpus > 1)
BIC_PRESENT(BIC_CPU);
if (debug > 1)
fprintf(outf, "num_cpus %d max_cpu_num %d\n", topo.num_cpus, topo.max_cpu_num);
cpus = calloc(1, (topo.max_cpu_num + 1) * sizeof(struct cpu_topology));
if (cpus == NULL)
err(1, "calloc cpus");
cpu_present_set = CPU_ALLOC((topo.max_cpu_num + 1));
if (cpu_present_set == NULL)
err(3, "CPU_ALLOC");
cpu_present_setsize = CPU_ALLOC_SIZE((topo.max_cpu_num + 1));
CPU_ZERO_S(cpu_present_setsize, cpu_present_set);
for_all_proc_cpus(mark_cpu_present);
for (i = 0; i < CPU_SUBSET_MAXCPUS; ++i) {
if (CPU_ISSET_S(i, cpu_subset_size, cpu_subset))
if (!CPU_ISSET_S(i, cpu_present_setsize, cpu_present_set))
err(1, "cpu%d not present", i);
}
cpu_affinity_set = CPU_ALLOC((topo.max_cpu_num + 1));
if (cpu_affinity_set == NULL)
err(3, "CPU_ALLOC");
cpu_affinity_setsize = CPU_ALLOC_SIZE((topo.max_cpu_num + 1));
CPU_ZERO_S(cpu_affinity_setsize, cpu_affinity_set);
for (i = 0; i <= topo.max_cpu_num; ++i) {
int siblings;
if (cpu_is_not_present(i)) {
if (debug > 1)
fprintf(outf, "cpu%d NOT PRESENT\n", i);
continue;
}
cpus[i].core_id = get_core_id(i);
if (cpus[i].core_id > max_core_id)
max_core_id = cpus[i].core_id;
cpus[i].physical_package_id = get_physical_package_id(i);
if (cpus[i].physical_package_id > max_package_id)
max_package_id = cpus[i].physical_package_id;
siblings = get_num_ht_siblings(i);
if (siblings > max_siblings)
max_siblings = siblings;
if (debug > 1)
fprintf(outf, "cpu %d pkg %d core %d\n",
i, cpus[i].physical_package_id, cpus[i].core_id);
}
topo.num_cores_per_pkg = max_core_id + 1;
if (debug > 1)
fprintf(outf, "max_core_id %d, sizing for %d cores per package\n",
max_core_id, topo.num_cores_per_pkg);
if (!summary_only && topo.num_cores_per_pkg > 1)
BIC_PRESENT(BIC_Core);
topo.num_packages = max_package_id + 1;
if (debug > 1)
fprintf(outf, "max_package_id %d, sizing for %d packages\n",
max_package_id, topo.num_packages);
if (!summary_only && topo.num_packages > 1)
BIC_PRESENT(BIC_Package);
topo.num_threads_per_core = max_siblings;
if (debug > 1)
fprintf(outf, "max_siblings %d\n", max_siblings);
free(cpus);
}
void
allocate_counters(struct thread_data **t, struct core_data **c, struct pkg_data **p)
{
int i;
*t = calloc(topo.num_threads_per_core * topo.num_cores_per_pkg *
topo.num_packages, sizeof(struct thread_data));
if (*t == NULL)
goto error;
for (i = 0; i < topo.num_threads_per_core *
topo.num_cores_per_pkg * topo.num_packages; i++)
(*t)[i].cpu_id = -1;
*c = calloc(topo.num_cores_per_pkg * topo.num_packages,
sizeof(struct core_data));
if (*c == NULL)
goto error;
for (i = 0; i < topo.num_cores_per_pkg * topo.num_packages; i++)
(*c)[i].core_id = -1;
*p = calloc(topo.num_packages, sizeof(struct pkg_data));
if (*p == NULL)
goto error;
for (i = 0; i < topo.num_packages; i++)
(*p)[i].package_id = i;
return;
error:
err(1, "calloc counters");
}
void init_counter(struct thread_data *thread_base, struct core_data *core_base,
struct pkg_data *pkg_base, int thread_num, int core_num,
int pkg_num, int cpu_id)
{
struct thread_data *t;
struct core_data *c;
struct pkg_data *p;
t = GET_THREAD(thread_base, thread_num, core_num, pkg_num);
c = GET_CORE(core_base, core_num, pkg_num);
p = GET_PKG(pkg_base, pkg_num);
t->cpu_id = cpu_id;
if (thread_num == 0) {
t->flags |= CPU_IS_FIRST_THREAD_IN_CORE;
if (cpu_is_first_core_in_package(cpu_id))
t->flags |= CPU_IS_FIRST_CORE_IN_PACKAGE;
}
c->core_id = core_num;
p->package_id = pkg_num;
}
int initialize_counters(int cpu_id)
{
int my_thread_id, my_core_id, my_package_id;
my_package_id = get_physical_package_id(cpu_id);
my_core_id = get_core_id(cpu_id);
my_thread_id = get_cpu_position_in_core(cpu_id);
if (!my_thread_id)
topo.num_cores++;
init_counter(EVEN_COUNTERS, my_thread_id, my_core_id, my_package_id, cpu_id);
init_counter(ODD_COUNTERS, my_thread_id, my_core_id, my_package_id, cpu_id);
return 0;
}
void allocate_output_buffer()
{
output_buffer = calloc(1, (1 + topo.num_cpus) * 1024);
outp = output_buffer;
if (outp == NULL)
err(-1, "calloc output buffer");
}
void allocate_fd_percpu(void)
{
fd_percpu = calloc(topo.max_cpu_num + 1, sizeof(int));
if (fd_percpu == NULL)
err(-1, "calloc fd_percpu");
}
void allocate_irq_buffers(void)
{
irq_column_2_cpu = calloc(topo.num_cpus, sizeof(int));
if (irq_column_2_cpu == NULL)
err(-1, "calloc %d", topo.num_cpus);
irqs_per_cpu = calloc(topo.max_cpu_num + 1, sizeof(int));
if (irqs_per_cpu == NULL)
err(-1, "calloc %d", topo.max_cpu_num + 1);
}
void setup_all_buffers(void)
{
topology_probe();
allocate_irq_buffers();
allocate_fd_percpu();
allocate_counters(&thread_even, &core_even, &package_even);
allocate_counters(&thread_odd, &core_odd, &package_odd);
allocate_output_buffer();
for_all_proc_cpus(initialize_counters);
}
void set_base_cpu(void)
{
base_cpu = sched_getcpu();
if (base_cpu < 0)
err(-ENODEV, "No valid cpus found");
if (debug > 1)
fprintf(outf, "base_cpu = %d\n", base_cpu);
}
void turbostat_init()
{
setup_all_buffers();
set_base_cpu();
check_dev_msr();
check_permissions();
process_cpuid();
if (!quiet)
for_all_cpus(print_hwp, ODD_COUNTERS);
if (!quiet)
for_all_cpus(print_epb, ODD_COUNTERS);
if (!quiet)
for_all_cpus(print_perf_limit, ODD_COUNTERS);
if (!quiet)
for_all_cpus(print_rapl, ODD_COUNTERS);
for_all_cpus(set_temperature_target, ODD_COUNTERS);
if (!quiet)
for_all_cpus(print_thermal, ODD_COUNTERS);
if (!quiet && do_irtl_snb)
print_irtl();
}
int fork_it(char **argv)
{
pid_t child_pid;
int status;
snapshot_proc_sysfs_files();
status = for_all_cpus(get_counters, EVEN_COUNTERS);
if (status)
exit(status);
sched_setaffinity(0, cpu_present_setsize, cpu_present_set);
gettimeofday(&tv_even, (struct timezone *)NULL);
child_pid = fork();
if (!child_pid) {
execvp(argv[0], argv);
err(errno, "exec %s", argv[0]);
} else {
if (child_pid == -1)
err(1, "fork");
signal(SIGINT, SIG_IGN);
signal(SIGQUIT, SIG_IGN);
if (waitpid(child_pid, &status, 0) == -1)
err(status, "waitpid");
}
snapshot_proc_sysfs_files();
for_all_cpus(get_counters, ODD_COUNTERS);
gettimeofday(&tv_odd, (struct timezone *)NULL);
timersub(&tv_odd, &tv_even, &tv_delta);
if (for_all_cpus_2(delta_cpu, ODD_COUNTERS, EVEN_COUNTERS))
fprintf(outf, "%s: Counter reset detected\n", progname);
else {
compute_average(EVEN_COUNTERS);
format_all_counters(EVEN_COUNTERS);
}
fprintf(outf, "%.6f sec\n", tv_delta.tv_sec + tv_delta.tv_usec/1000000.0);
flush_output_stderr();
return status;
}
int get_and_dump_counters(void)
{
int status;
snapshot_proc_sysfs_files();
status = for_all_cpus(get_counters, ODD_COUNTERS);
if (status)
return status;
status = for_all_cpus(dump_counters, ODD_COUNTERS);
if (status)
return status;
flush_output_stdout();
return status;
}
void print_version() {
fprintf(outf, "turbostat version 17.04.12"
" - Len Brown <lenb@kernel.org>\n");
}
int add_counter(unsigned int msr_num, char *path, char *name,
unsigned int width, enum counter_scope scope,
enum counter_type type, enum counter_format format, int flags)
{
struct msr_counter *msrp;
msrp = calloc(1, sizeof(struct msr_counter));
if (msrp == NULL) {
perror("calloc");
exit(1);
}
msrp->msr_num = msr_num;
strncpy(msrp->name, name, NAME_BYTES);
if (path)
strncpy(msrp->path, path, PATH_BYTES);
msrp->width = width;
msrp->type = type;
msrp->format = format;
msrp->flags = flags;
switch (scope) {
case SCOPE_CPU:
msrp->next = sys.tp;
sys.tp = msrp;
sys.added_thread_counters++;
if (sys.added_thread_counters > MAX_ADDED_COUNTERS) {
fprintf(stderr, "exceeded max %d added thread counters\n",
MAX_ADDED_COUNTERS);
exit(-1);
}
break;
case SCOPE_CORE:
msrp->next = sys.cp;
sys.cp = msrp;
sys.added_core_counters++;
if (sys.added_core_counters > MAX_ADDED_COUNTERS) {
fprintf(stderr, "exceeded max %d added core counters\n",
MAX_ADDED_COUNTERS);
exit(-1);
}
break;
case SCOPE_PACKAGE:
msrp->next = sys.pp;
sys.pp = msrp;
sys.added_package_counters++;
if (sys.added_package_counters > MAX_ADDED_COUNTERS) {
fprintf(stderr, "exceeded max %d added package counters\n",
MAX_ADDED_COUNTERS);
exit(-1);
}
break;
}
return 0;
}
void parse_add_command(char *add_command)
{
int msr_num = 0;
char *path = NULL;
char name_buffer[NAME_BYTES] = "";
int width = 64;
int fail = 0;
enum counter_scope scope = SCOPE_CPU;
enum counter_type type = COUNTER_CYCLES;
enum counter_format format = FORMAT_DELTA;
while (add_command) {
if (sscanf(add_command, "msr0x%x", &msr_num) == 1)
goto next;
if (sscanf(add_command, "msr%d", &msr_num) == 1)
goto next;
if (*add_command == '/') {
path = add_command;
goto next;
}
if (sscanf(add_command, "u%d", &width) == 1) {
if ((width == 32) || (width == 64))
goto next;
width = 64;
}
if (!strncmp(add_command, "cpu", strlen("cpu"))) {
scope = SCOPE_CPU;
goto next;
}
if (!strncmp(add_command, "core", strlen("core"))) {
scope = SCOPE_CORE;
goto next;
}
if (!strncmp(add_command, "package", strlen("package"))) {
scope = SCOPE_PACKAGE;
goto next;
}
if (!strncmp(add_command, "cycles", strlen("cycles"))) {
type = COUNTER_CYCLES;
goto next;
}
if (!strncmp(add_command, "seconds", strlen("seconds"))) {
type = COUNTER_SECONDS;
goto next;
}
if (!strncmp(add_command, "usec", strlen("usec"))) {
type = COUNTER_USEC;
goto next;
}
if (!strncmp(add_command, "raw", strlen("raw"))) {
format = FORMAT_RAW;
goto next;
}
if (!strncmp(add_command, "delta", strlen("delta"))) {
format = FORMAT_DELTA;
goto next;
}
if (!strncmp(add_command, "percent", strlen("percent"))) {
format = FORMAT_PERCENT;
goto next;
}
if (sscanf(add_command, "%18s,%*s", name_buffer) == 1) {
char *eos;
eos = strchr(name_buffer, ',');
if (eos)
*eos = '\0';
goto next;
}
next:
add_command = strchr(add_command, ',');
if (add_command) {
*add_command = '\0';
add_command++;
}
}
if ((msr_num == 0) && (path == NULL)) {
fprintf(stderr, "--add: (msrDDD | msr0xXXX | /path_to_counter ) required\n");
fail++;
}
if (*name_buffer == '\0') {
if (width == 32)
sprintf(name_buffer, "M0x%x%s", msr_num, format == FORMAT_PERCENT ? "%" : "");
else
sprintf(name_buffer, "M0X%x%s", msr_num, format == FORMAT_PERCENT ? "%" : "");
}
if (add_counter(msr_num, path, name_buffer, width, scope, type, format, 0))
fail++;
if (fail) {
help();
exit(1);
}
}
int is_deferred_skip(char *name)
{
int i;
for (i = 0; i < deferred_skip_index; ++i)
if (!strcmp(name, deferred_skip_names[i]))
return 1;
return 0;
}
void probe_sysfs(void)
{
char path[64];
char name_buf[16];
FILE *input;
int state;
char *sp;
if (!DO_BIC(BIC_sysfs))
return;
for (state = 10; state > 0; --state) {
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpuidle/state%d/name",
base_cpu, state);
input = fopen(path, "r");
if (input == NULL)
continue;
fgets(name_buf, sizeof(name_buf), input);
sp = strchr(name_buf, '-');
if (!sp)
sp = strchrnul(name_buf, '\n');
*sp = '%';
*(sp + 1) = '\0';
fclose(input);
sprintf(path, "cpuidle/state%d/time", state);
if (is_deferred_skip(name_buf))
continue;
add_counter(0, path, name_buf, 64, SCOPE_CPU, COUNTER_USEC,
FORMAT_PERCENT, SYSFS_PERCPU);
}
for (state = 10; state > 0; --state) {
sprintf(path, "/sys/devices/system/cpu/cpu%d/cpuidle/state%d/name",
base_cpu, state);
input = fopen(path, "r");
if (input == NULL)
continue;
fgets(name_buf, sizeof(name_buf), input);
sp = strchr(name_buf, '-');
if (!sp)
sp = strchrnul(name_buf, '\n');
*sp = '\0';
fclose(input);
sprintf(path, "cpuidle/state%d/usage", state);
if (is_deferred_skip(name_buf))
continue;
add_counter(0, path, name_buf, 64, SCOPE_CPU, COUNTER_ITEMS,
FORMAT_DELTA, SYSFS_PERCPU);
}
}
void parse_cpu_command(char *optarg)
{
unsigned int start, end;
char *next;
if (!strcmp(optarg, "core")) {
if (cpu_subset)
goto error;
show_core_only++;
return;
}
if (!strcmp(optarg, "package")) {
if (cpu_subset)
goto error;
show_pkg_only++;
return;
}
if (show_core_only || show_pkg_only)
goto error;
cpu_subset = CPU_ALLOC(CPU_SUBSET_MAXCPUS);
if (cpu_subset == NULL)
err(3, "CPU_ALLOC");
cpu_subset_size = CPU_ALLOC_SIZE(CPU_SUBSET_MAXCPUS);
CPU_ZERO_S(cpu_subset_size, cpu_subset);
next = optarg;
while (next && *next) {
if (*next == '-')
goto error;
start = strtoul(next, &next, 10);
if (start >= CPU_SUBSET_MAXCPUS)
goto error;
CPU_SET_S(start, cpu_subset_size, cpu_subset);
if (*next == '\0')
break;
if (*next == ',') {
next += 1;
continue;
}
if (*next == '-') {
next += 1;
} else if (*next == '.') {
next += 1;
if (*next == '.')
next += 1;
else
goto error;
}
end = strtoul(next, &next, 10);
if (end <= start)
goto error;
while (++start <= end) {
if (start >= CPU_SUBSET_MAXCPUS)
goto error;
CPU_SET_S(start, cpu_subset_size, cpu_subset);
}
if (*next == ',')
next += 1;
else if (*next != '\0')
goto error;
}
return;
error:
fprintf(stderr, "\"--cpu %s\" malformed\n", optarg);
help();
exit(-1);
}
void parse_show_hide(char *optarg, enum show_hide_mode new_mode)
{
if (new_mode == SHOW_LIST) {
if (shown == 0)
bic_enabled = bic_lookup(optarg, new_mode);
else
bic_enabled |= bic_lookup(optarg, new_mode);
shown = 1;
return;
}
bic_enabled &= ~bic_lookup(optarg, new_mode);
}
void cmdline(int argc, char **argv)
{
int opt;
int option_index = 0;
static struct option long_options[] = {
{"add", required_argument, 0, 'a'},
{"cpu", required_argument, 0, 'c'},
{"Dump", no_argument, 0, 'D'},
{"debug", no_argument, 0, 'd'},
{"interval", required_argument, 0, 'i'},
{"help", no_argument, 0, 'h'},
{"hide", required_argument, 0, 'H'},
{"Joules", no_argument, 0, 'J'},
{"list", no_argument, 0, 'l'},
{"out", required_argument, 0, 'o'},
{"quiet", no_argument, 0, 'q'},
{"show", required_argument, 0, 's'},
{"Summary", no_argument, 0, 'S'},
{"TCC", required_argument, 0, 'T'},
{"version", no_argument, 0, 'v' },
{0, 0, 0, 0 }
};
progname = argv[0];
while ((opt = getopt_long_only(argc, argv, "+C:c:Ddhi:JM:m:o:qST:v",
long_options, &option_index)) != -1) {
switch (opt) {
case 'a':
parse_add_command(optarg);
break;
case 'c':
parse_cpu_command(optarg);
break;
case 'D':
dump_only++;
break;
case 'd':
debug++;
break;
case 'H':
parse_show_hide(optarg, HIDE_LIST);
break;
case 'h':
default:
help();
exit(1);
case 'i':
{
double interval = strtod(optarg, NULL);
if (interval < 0.001) {
fprintf(outf, "interval %f seconds is too small\n",
interval);
exit(2);
}
interval_ts.tv_sec = interval;
interval_ts.tv_nsec = (interval - interval_ts.tv_sec) * 1000000000;
}
break;
case 'J':
rapl_joules++;
break;
case 'l':
list_header_only++;
quiet++;
break;
case 'o':
outf = fopen_or_die(optarg, "w");
break;
case 'q':
quiet = 1;
break;
case 's':
parse_show_hide(optarg, SHOW_LIST);
break;
case 'S':
summary_only++;
break;
case 'T':
tcc_activation_temp_override = atoi(optarg);
break;
case 'v':
print_version();
exit(0);
break;
}
}
}
int main(int argc, char **argv)
{
outf = stderr;
cmdline(argc, argv);
if (!quiet)
print_version();
probe_sysfs();
turbostat_init();
if (dump_only)
return get_and_dump_counters();
if (list_header_only) {
print_header(",");
flush_output_stdout();
return 0;
}
if (argc - optind)
return fork_it(argv + optind);
else
turbostat_loop();
return 0;
}
