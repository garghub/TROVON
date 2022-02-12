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
int get_msr(int cpu, off_t offset, unsigned long long *msr)
{
ssize_t retval;
char pathname[32];
int fd;
sprintf(pathname, "/dev/cpu/%d/msr", cpu);
fd = open(pathname, O_RDONLY);
if (fd < 0)
err(-1, "%s open failed, try chown or chmod +r /dev/cpu/*/msr, or run as root", pathname);
retval = pread(fd, msr, sizeof *msr, offset);
close(fd);
if (retval != sizeof *msr)
err(-1, "%s offset 0x%llx read failed", pathname, (unsigned long long)offset);
return 0;
}
void print_header(void)
{
if (show_pkg)
outp += sprintf(outp, " Package");
if (show_core)
outp += sprintf(outp, " Core");
if (show_cpu)
outp += sprintf(outp, " CPU");
if (has_aperf)
outp += sprintf(outp, " Avg_MHz");
if (has_aperf)
outp += sprintf(outp, " %%Busy");
if (has_aperf)
outp += sprintf(outp, " Bzy_MHz");
outp += sprintf(outp, " TSC_MHz");
if (do_smi)
outp += sprintf(outp, " SMI");
if (extra_delta_offset32)
outp += sprintf(outp, " count 0x%03X", extra_delta_offset32);
if (extra_delta_offset64)
outp += sprintf(outp, " COUNT 0x%03X", extra_delta_offset64);
if (extra_msr_offset32)
outp += sprintf(outp, " MSR 0x%03X", extra_msr_offset32);
if (extra_msr_offset64)
outp += sprintf(outp, " MSR 0x%03X", extra_msr_offset64);
if (do_nhm_cstates)
outp += sprintf(outp, " CPU%%c1");
if (do_nhm_cstates && !do_slm_cstates)
outp += sprintf(outp, " CPU%%c3");
if (do_nhm_cstates)
outp += sprintf(outp, " CPU%%c6");
if (do_snb_cstates)
outp += sprintf(outp, " CPU%%c7");
if (do_dts)
outp += sprintf(outp, " CoreTmp");
if (do_ptm)
outp += sprintf(outp, " PkgTmp");
if (do_pc2)
outp += sprintf(outp, " Pkg%%pc2");
if (do_pc3)
outp += sprintf(outp, " Pkg%%pc3");
if (do_pc6)
outp += sprintf(outp, " Pkg%%pc6");
if (do_pc7)
outp += sprintf(outp, " Pkg%%pc7");
if (do_c8_c9_c10) {
outp += sprintf(outp, " Pkg%%pc8");
outp += sprintf(outp, " Pkg%%pc9");
outp += sprintf(outp, " Pk%%pc10");
}
if (do_rapl && !rapl_joules) {
if (do_rapl & RAPL_PKG)
outp += sprintf(outp, " PkgWatt");
if (do_rapl & RAPL_CORES)
outp += sprintf(outp, " CorWatt");
if (do_rapl & RAPL_GFX)
outp += sprintf(outp, " GFXWatt");
if (do_rapl & RAPL_DRAM)
outp += sprintf(outp, " RAMWatt");
if (do_rapl & RAPL_PKG_PERF_STATUS)
outp += sprintf(outp, " PKG_%%");
if (do_rapl & RAPL_DRAM_PERF_STATUS)
outp += sprintf(outp, " RAM_%%");
} else if (do_rapl && rapl_joules) {
if (do_rapl & RAPL_PKG)
outp += sprintf(outp, " Pkg_J");
if (do_rapl & RAPL_CORES)
outp += sprintf(outp, " Cor_J");
if (do_rapl & RAPL_GFX)
outp += sprintf(outp, " GFX_J");
if (do_rapl & RAPL_DRAM)
outp += sprintf(outp, " RAM_W");
if (do_rapl & RAPL_PKG_PERF_STATUS)
outp += sprintf(outp, " PKG_%%");
if (do_rapl & RAPL_DRAM_PERF_STATUS)
outp += sprintf(outp, " RAM_%%");
outp += sprintf(outp, " time");
}
outp += sprintf(outp, "\n");
}
int dump_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
outp += sprintf(outp, "t %p, c %p, p %p\n", t, c, p);
if (t) {
outp += sprintf(outp, "CPU: %d flags 0x%x\n",
t->cpu_id, t->flags);
outp += sprintf(outp, "TSC: %016llX\n", t->tsc);
outp += sprintf(outp, "aperf: %016llX\n", t->aperf);
outp += sprintf(outp, "mperf: %016llX\n", t->mperf);
outp += sprintf(outp, "c1: %016llX\n", t->c1);
outp += sprintf(outp, "msr0x%x: %08llX\n",
extra_delta_offset32, t->extra_delta32);
outp += sprintf(outp, "msr0x%x: %016llX\n",
extra_delta_offset64, t->extra_delta64);
outp += sprintf(outp, "msr0x%x: %08llX\n",
extra_msr_offset32, t->extra_msr32);
outp += sprintf(outp, "msr0x%x: %016llX\n",
extra_msr_offset64, t->extra_msr64);
if (do_smi)
outp += sprintf(outp, "SMI: %08X\n", t->smi_count);
}
if (c) {
outp += sprintf(outp, "core: %d\n", c->core_id);
outp += sprintf(outp, "c3: %016llX\n", c->c3);
outp += sprintf(outp, "c6: %016llX\n", c->c6);
outp += sprintf(outp, "c7: %016llX\n", c->c7);
outp += sprintf(outp, "DTS: %dC\n", c->core_temp_c);
}
if (p) {
outp += sprintf(outp, "package: %d\n", p->package_id);
outp += sprintf(outp, "pc2: %016llX\n", p->pc2);
if (do_pc3)
outp += sprintf(outp, "pc3: %016llX\n", p->pc3);
if (do_pc6)
outp += sprintf(outp, "pc6: %016llX\n", p->pc6);
if (do_pc7)
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
}
outp += sprintf(outp, "\n");
return 0;
}
int format_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
double interval_float;
char *fmt8;
if (show_core_only && !(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (show_pkg_only && !(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
interval_float = tv_delta.tv_sec + tv_delta.tv_usec/1000000.0;
if (t == &average.threads) {
if (show_pkg)
outp += sprintf(outp, " -");
if (show_core)
outp += sprintf(outp, " -");
if (show_cpu)
outp += sprintf(outp, " -");
} else {
if (show_pkg) {
if (p)
outp += sprintf(outp, "%8d", p->package_id);
else
outp += sprintf(outp, " -");
}
if (show_core) {
if (c)
outp += sprintf(outp, "%8d", c->core_id);
else
outp += sprintf(outp, " -");
}
if (show_cpu)
outp += sprintf(outp, "%8d", t->cpu_id);
}
if (has_aperf)
outp += sprintf(outp, "%8.0f",
1.0 / units * t->aperf / interval_float);
if (has_aperf) {
if (!skip_c0)
outp += sprintf(outp, "%8.2f", 100.0 * t->mperf/t->tsc);
else
outp += sprintf(outp, "********");
}
if (has_aperf)
outp += sprintf(outp, "%8.0f",
1.0 * t->tsc / units * t->aperf / t->mperf / interval_float);
outp += sprintf(outp, "%8.0f", 1.0 * t->tsc/units/interval_float);
if (do_smi)
outp += sprintf(outp, "%8d", t->smi_count);
if (extra_delta_offset32)
outp += sprintf(outp, " %11llu", t->extra_delta32);
if (extra_delta_offset64)
outp += sprintf(outp, " %11llu", t->extra_delta64);
if (extra_msr_offset32)
outp += sprintf(outp, " 0x%08llx", t->extra_msr32);
if (extra_msr_offset64)
outp += sprintf(outp, " 0x%016llx", t->extra_msr64);
if (do_nhm_cstates) {
if (!skip_c1)
outp += sprintf(outp, "%8.2f", 100.0 * t->c1/t->tsc);
else
outp += sprintf(outp, "********");
}
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
goto done;
if (do_nhm_cstates && !do_slm_cstates)
outp += sprintf(outp, "%8.2f", 100.0 * c->c3/t->tsc);
if (do_nhm_cstates)
outp += sprintf(outp, "%8.2f", 100.0 * c->c6/t->tsc);
if (do_snb_cstates)
outp += sprintf(outp, "%8.2f", 100.0 * c->c7/t->tsc);
if (do_dts)
outp += sprintf(outp, "%8d", c->core_temp_c);
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
goto done;
if (do_ptm)
outp += sprintf(outp, "%8d", p->pkg_temp_c);
if (do_pc2)
outp += sprintf(outp, "%8.2f", 100.0 * p->pc2/t->tsc);
if (do_pc3)
outp += sprintf(outp, "%8.2f", 100.0 * p->pc3/t->tsc);
if (do_pc6)
outp += sprintf(outp, "%8.2f", 100.0 * p->pc6/t->tsc);
if (do_pc7)
outp += sprintf(outp, "%8.2f", 100.0 * p->pc7/t->tsc);
if (do_c8_c9_c10) {
outp += sprintf(outp, "%8.2f", 100.0 * p->pc8/t->tsc);
outp += sprintf(outp, "%8.2f", 100.0 * p->pc9/t->tsc);
outp += sprintf(outp, "%8.2f", 100.0 * p->pc10/t->tsc);
}
if (interval_float < rapl_joule_counter_range)
fmt8 = "%8.2f";
else
fmt8 = " %6.0f**";
if (do_rapl && !rapl_joules) {
if (do_rapl & RAPL_PKG)
outp += sprintf(outp, fmt8, p->energy_pkg * rapl_energy_units / interval_float);
if (do_rapl & RAPL_CORES)
outp += sprintf(outp, fmt8, p->energy_cores * rapl_energy_units / interval_float);
if (do_rapl & RAPL_GFX)
outp += sprintf(outp, fmt8, p->energy_gfx * rapl_energy_units / interval_float);
if (do_rapl & RAPL_DRAM)
outp += sprintf(outp, fmt8, p->energy_dram * rapl_energy_units / interval_float);
if (do_rapl & RAPL_PKG_PERF_STATUS)
outp += sprintf(outp, fmt8, 100.0 * p->rapl_pkg_perf_status * rapl_time_units / interval_float);
if (do_rapl & RAPL_DRAM_PERF_STATUS)
outp += sprintf(outp, fmt8, 100.0 * p->rapl_dram_perf_status * rapl_time_units / interval_float);
} else if (do_rapl && rapl_joules) {
if (do_rapl & RAPL_PKG)
outp += sprintf(outp, fmt8,
p->energy_pkg * rapl_energy_units);
if (do_rapl & RAPL_CORES)
outp += sprintf(outp, fmt8,
p->energy_cores * rapl_energy_units);
if (do_rapl & RAPL_GFX)
outp += sprintf(outp, fmt8,
p->energy_gfx * rapl_energy_units);
if (do_rapl & RAPL_DRAM)
outp += sprintf(outp, fmt8,
p->energy_dram * rapl_energy_units);
if (do_rapl & RAPL_PKG_PERF_STATUS)
outp += sprintf(outp, fmt8, 100.0 * p->rapl_pkg_perf_status * rapl_time_units / interval_float);
if (do_rapl & RAPL_DRAM_PERF_STATUS)
outp += sprintf(outp, fmt8, 100.0 * p->rapl_dram_perf_status * rapl_time_units / interval_float);
outp += sprintf(outp, fmt8, interval_float);
}
done:
outp += sprintf(outp, "\n");
return 0;
}
void flush_stdout()
{
fputs(output_buffer, stdout);
fflush(stdout);
outp = output_buffer;
}
void flush_stderr()
{
fputs(output_buffer, stderr);
outp = output_buffer;
}
void format_all_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
static int printed;
if (!printed || !summary_only)
print_header();
if (topo.num_cpus > 1)
format_counters(&average.threads, &average.cores,
&average.packages);
printed = 1;
if (summary_only)
return;
for_all_cpus(format_counters, t, c, p);
}
void
delta_package(struct pkg_data *new, struct pkg_data *old)
{
old->pc2 = new->pc2 - old->pc2;
if (do_pc3)
old->pc3 = new->pc3 - old->pc3;
if (do_pc6)
old->pc6 = new->pc6 - old->pc6;
if (do_pc7)
old->pc7 = new->pc7 - old->pc7;
old->pc8 = new->pc8 - old->pc8;
old->pc9 = new->pc9 - old->pc9;
old->pc10 = new->pc10 - old->pc10;
old->pkg_temp_c = new->pkg_temp_c;
DELTA_WRAP32(new->energy_pkg, old->energy_pkg);
DELTA_WRAP32(new->energy_cores, old->energy_cores);
DELTA_WRAP32(new->energy_gfx, old->energy_gfx);
DELTA_WRAP32(new->energy_dram, old->energy_dram);
DELTA_WRAP32(new->rapl_pkg_perf_status, old->rapl_pkg_perf_status);
DELTA_WRAP32(new->rapl_dram_perf_status, old->rapl_dram_perf_status);
}
void
delta_core(struct core_data *new, struct core_data *old)
{
old->c3 = new->c3 - old->c3;
old->c6 = new->c6 - old->c6;
old->c7 = new->c7 - old->c7;
old->core_temp_c = new->core_temp_c;
}
void
delta_thread(struct thread_data *new, struct thread_data *old,
struct core_data *core_delta)
{
old->tsc = new->tsc - old->tsc;
if (old->tsc < (1000 * 1000))
errx(-3, "Insanely slow TSC rate, TSC stops in idle?\n"
"You can disable all c-states by booting with \"idle=poll\"\n"
"or just the deep ones with \"processor.max_cstate=1\"");
old->c1 = new->c1 - old->c1;
if (has_aperf) {
if ((new->aperf > old->aperf) && (new->mperf > old->mperf)) {
old->aperf = new->aperf - old->aperf;
old->mperf = new->mperf - old->mperf;
} else {
if (!aperf_mperf_unstable) {
fprintf(stderr, "%s: APERF or MPERF went backwards *\n", progname);
fprintf(stderr, "* Frequency results do not cover entire interval *\n");
fprintf(stderr, "* fix this by running Linux-2.6.30 or later *\n");
aperf_mperf_unstable = 1;
}
skip_c0 = 1;
skip_c1 = 1;
}
}
if (use_c1_residency_msr) {
} else {
if ((old->mperf + core_delta->c3 + core_delta->c6 + core_delta->c7) > old->tsc)
old->c1 = 0;
else {
old->c1 = old->tsc - old->mperf - core_delta->c3
- core_delta->c6 - core_delta->c7;
}
}
if (old->mperf == 0) {
if (debug > 1) fprintf(stderr, "cpu%d MPERF 0!\n", old->cpu_id);
old->mperf = 1;
}
old->extra_delta32 = new->extra_delta32 - old->extra_delta32;
old->extra_delta32 &= 0xFFFFFFFF;
old->extra_delta64 = new->extra_delta64 - old->extra_delta64;
old->extra_msr32 = new->extra_msr32;
old->extra_msr64 = new->extra_msr64;
if (do_smi)
old->smi_count = new->smi_count - old->smi_count;
}
int delta_cpu(struct thread_data *t, struct core_data *c,
struct pkg_data *p, struct thread_data *t2,
struct core_data *c2, struct pkg_data *p2)
{
if (t->flags & CPU_IS_FIRST_THREAD_IN_CORE)
delta_core(c, c2);
delta_thread(t, t2, c2);
if (t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE)
delta_package(p, p2);
return 0;
}
void clear_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
t->tsc = 0;
t->aperf = 0;
t->mperf = 0;
t->c1 = 0;
t->smi_count = 0;
t->extra_delta32 = 0;
t->extra_delta64 = 0;
t->flags = CPU_IS_FIRST_THREAD_IN_CORE | CPU_IS_FIRST_CORE_IN_PACKAGE;
c->c3 = 0;
c->c6 = 0;
c->c7 = 0;
c->core_temp_c = 0;
p->pc2 = 0;
if (do_pc3)
p->pc3 = 0;
if (do_pc6)
p->pc6 = 0;
if (do_pc7)
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
}
int sum_counters(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
average.threads.tsc += t->tsc;
average.threads.aperf += t->aperf;
average.threads.mperf += t->mperf;
average.threads.c1 += t->c1;
average.threads.extra_delta32 += t->extra_delta32;
average.threads.extra_delta64 += t->extra_delta64;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
average.cores.c3 += c->c3;
average.cores.c6 += c->c6;
average.cores.c7 += c->c7;
average.cores.core_temp_c = MAX(average.cores.core_temp_c, c->core_temp_c);
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
average.packages.pc2 += p->pc2;
if (do_pc3)
average.packages.pc3 += p->pc3;
if (do_pc6)
average.packages.pc6 += p->pc6;
if (do_pc7)
average.packages.pc7 += p->pc7;
average.packages.pc8 += p->pc8;
average.packages.pc9 += p->pc9;
average.packages.pc10 += p->pc10;
average.packages.energy_pkg += p->energy_pkg;
average.packages.energy_dram += p->energy_dram;
average.packages.energy_cores += p->energy_cores;
average.packages.energy_gfx += p->energy_gfx;
average.packages.pkg_temp_c = MAX(average.packages.pkg_temp_c, p->pkg_temp_c);
average.packages.rapl_pkg_perf_status += p->rapl_pkg_perf_status;
average.packages.rapl_dram_perf_status += p->rapl_dram_perf_status;
return 0;
}
void compute_average(struct thread_data *t, struct core_data *c,
struct pkg_data *p)
{
clear_counters(&average.threads, &average.cores, &average.packages);
for_all_cpus(sum_counters, t, c, p);
average.threads.tsc /= topo.num_cpus;
average.threads.aperf /= topo.num_cpus;
average.threads.mperf /= topo.num_cpus;
average.threads.c1 /= topo.num_cpus;
average.threads.extra_delta32 /= topo.num_cpus;
average.threads.extra_delta32 &= 0xFFFFFFFF;
average.threads.extra_delta64 /= topo.num_cpus;
average.cores.c3 /= topo.num_cores;
average.cores.c6 /= topo.num_cores;
average.cores.c7 /= topo.num_cores;
average.packages.pc2 /= topo.num_packages;
if (do_pc3)
average.packages.pc3 /= topo.num_packages;
if (do_pc6)
average.packages.pc6 /= topo.num_packages;
if (do_pc7)
average.packages.pc7 /= topo.num_packages;
average.packages.pc8 /= topo.num_packages;
average.packages.pc9 /= topo.num_packages;
average.packages.pc10 /= topo.num_packages;
}
static unsigned long long rdtsc(void)
{
unsigned int low, high;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return low | ((unsigned long long)high) << 32;
}
int get_counters(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
int cpu = t->cpu_id;
unsigned long long msr;
if (cpu_migrate(cpu)) {
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
t->tsc = rdtsc();
if (has_aperf) {
if (get_msr(cpu, MSR_IA32_APERF, &t->aperf))
return -3;
if (get_msr(cpu, MSR_IA32_MPERF, &t->mperf))
return -4;
}
if (do_smi) {
if (get_msr(cpu, MSR_SMI_COUNT, &msr))
return -5;
t->smi_count = msr & 0xFFFFFFFF;
}
if (extra_delta_offset32) {
if (get_msr(cpu, extra_delta_offset32, &msr))
return -5;
t->extra_delta32 = msr & 0xFFFFFFFF;
}
if (extra_delta_offset64)
if (get_msr(cpu, extra_delta_offset64, &t->extra_delta64))
return -5;
if (extra_msr_offset32) {
if (get_msr(cpu, extra_msr_offset32, &msr))
return -5;
t->extra_msr32 = msr & 0xFFFFFFFF;
}
if (extra_msr_offset64)
if (get_msr(cpu, extra_msr_offset64, &t->extra_msr64))
return -5;
if (use_c1_residency_msr) {
if (get_msr(cpu, MSR_CORE_C1_RES, &t->c1))
return -6;
}
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (do_nhm_cstates && !do_slm_cstates) {
if (get_msr(cpu, MSR_CORE_C3_RESIDENCY, &c->c3))
return -6;
}
if (do_nhm_cstates) {
if (get_msr(cpu, MSR_CORE_C6_RESIDENCY, &c->c6))
return -7;
}
if (do_snb_cstates)
if (get_msr(cpu, MSR_CORE_C7_RESIDENCY, &c->c7))
return -8;
if (do_dts) {
if (get_msr(cpu, MSR_IA32_THERM_STATUS, &msr))
return -9;
c->core_temp_c = tcc_activation_temp - ((msr >> 16) & 0x7F);
}
if (!(t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE))
return 0;
if (do_pc3)
if (get_msr(cpu, MSR_PKG_C3_RESIDENCY, &p->pc3))
return -9;
if (do_pc6)
if (get_msr(cpu, MSR_PKG_C6_RESIDENCY, &p->pc6))
return -10;
if (do_pc2)
if (get_msr(cpu, MSR_PKG_C2_RESIDENCY, &p->pc2))
return -11;
if (do_pc7)
if (get_msr(cpu, MSR_PKG_C7_RESIDENCY, &p->pc7))
return -12;
if (do_c8_c9_c10) {
if (get_msr(cpu, MSR_PKG_C8_RESIDENCY, &p->pc8))
return -13;
if (get_msr(cpu, MSR_PKG_C9_RESIDENCY, &p->pc9))
return -13;
if (get_msr(cpu, MSR_PKG_C10_RESIDENCY, &p->pc10))
return -13;
}
if (do_rapl & RAPL_PKG) {
if (get_msr(cpu, MSR_PKG_ENERGY_STATUS, &msr))
return -13;
p->energy_pkg = msr & 0xFFFFFFFF;
}
if (do_rapl & RAPL_CORES) {
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
if (do_ptm) {
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_STATUS, &msr))
return -17;
p->pkg_temp_c = tcc_activation_temp - ((msr >> 16) & 0x7F);
}
return 0;
}
void print_verbose_header(void)
{
unsigned long long msr;
unsigned int ratio;
if (!do_nhm_platform_info)
return;
get_msr(0, MSR_NHM_PLATFORM_INFO, &msr);
fprintf(stderr, "cpu0: MSR_NHM_PLATFORM_INFO: 0x%08llx\n", msr);
ratio = (msr >> 40) & 0xFF;
fprintf(stderr, "%d * %.0f = %.0f MHz max efficiency\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
fprintf(stderr, "%d * %.0f = %.0f MHz TSC frequency\n",
ratio, bclk, ratio * bclk);
get_msr(0, MSR_IA32_POWER_CTL, &msr);
fprintf(stderr, "cpu0: MSR_IA32_POWER_CTL: 0x%08llx (C1E auto-promotion: %sabled)\n",
msr, msr & 0x2 ? "EN" : "DIS");
if (!do_ivt_turbo_ratio_limit)
goto print_nhm_turbo_ratio_limits;
get_msr(0, MSR_IVT_TURBO_RATIO_LIMIT, &msr);
fprintf(stderr, "cpu0: MSR_IVT_TURBO_RATIO_LIMIT: 0x%08llx\n", msr);
ratio = (msr >> 56) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 16 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 48) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 15 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 40) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 14 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 32) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 13 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 24) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 12 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 11 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 10 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 9 active cores\n",
ratio, bclk, ratio * bclk);
print_nhm_turbo_ratio_limits:
get_msr(0, MSR_NHM_SNB_PKG_CST_CFG_CTL, &msr);
#define SNB_C1_AUTO_UNDEMOTE (1UL << 27)
#define SNB_C3_AUTO_UNDEMOTE (1UL << 28)
fprintf(stderr, "cpu0: MSR_NHM_SNB_PKG_CST_CFG_CTL: 0x%08llx", msr);
fprintf(stderr, " (%s%s%s%s%slocked: pkg-cstate-limit=%d: %s)\n",
(msr & SNB_C3_AUTO_UNDEMOTE) ? "UNdemote-C3, " : "",
(msr & SNB_C1_AUTO_UNDEMOTE) ? "UNdemote-C1, " : "",
(msr & NHM_C3_AUTO_DEMOTE) ? "demote-C3, " : "",
(msr & NHM_C1_AUTO_DEMOTE) ? "demote-C1, " : "",
(msr & (1 << 15)) ? "" : "UN",
(unsigned int)msr & 7,
pkg_cstate_limit_strings[pkg_cstate_limit]);
if (!do_nhm_turbo_ratio_limit)
return;
get_msr(0, MSR_NHM_TURBO_RATIO_LIMIT, &msr);
fprintf(stderr, "cpu0: MSR_NHM_TURBO_RATIO_LIMIT: 0x%08llx\n", msr);
ratio = (msr >> 56) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 8 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 48) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 7 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 40) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 6 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 32) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 5 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 24) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 4 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 16) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 3 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 8) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 2 active cores\n",
ratio, bclk, ratio * bclk);
ratio = (msr >> 0) & 0xFF;
if (ratio)
fprintf(stderr, "%d * %.0f = %.0f MHz max turbo 1 active cores\n",
ratio, bclk, ratio * bclk);
}
void free_all_buffers(void)
{
CPU_FREE(cpu_present_set);
cpu_present_set = NULL;
cpu_present_set = 0;
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
}
FILE *fopen_or_die(const char *path, const char *mode)
{
FILE *filep = fopen(path, "r");
if (!filep)
err(1, "%s: open failed", path);
return filep;
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
int cpu_is_first_sibling_in_core(int cpu)
{
return cpu == parse_int_file("/sys/devices/system/cpu/cpu%d/topology/thread_siblings_list", cpu);
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
int sib1, sib2;
int matches;
char character;
sprintf(path, "/sys/devices/system/cpu/cpu%d/topology/thread_siblings_list", cpu);
filep = fopen_or_die(path, "r");
matches = fscanf(filep, "%d%c%d\n", &sib1, &character, &sib2);
fclose(filep);
if (matches == 3)
return 2;
else
return 1;
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
void turbostat_loop()
{
int retval;
int restarted = 0;
restart:
restarted++;
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
sleep(interval_sec);
retval = for_all_cpus(get_counters, ODD_COUNTERS);
if (retval < -1) {
exit(retval);
} else if (retval == -1) {
re_initialize();
goto restart;
}
gettimeofday(&tv_odd, (struct timezone *)NULL);
timersub(&tv_odd, &tv_even, &tv_delta);
for_all_cpus_2(delta_cpu, ODD_COUNTERS, EVEN_COUNTERS);
compute_average(EVEN_COUNTERS);
format_all_counters(EVEN_COUNTERS);
flush_stdout();
sleep(interval_sec);
retval = for_all_cpus(get_counters, EVEN_COUNTERS);
if (retval < -1) {
exit(retval);
} else if (retval == -1) {
re_initialize();
goto restart;
}
gettimeofday(&tv_even, (struct timezone *)NULL);
timersub(&tv_even, &tv_odd, &tv_delta);
for_all_cpus_2(delta_cpu, EVEN_COUNTERS, ODD_COUNTERS);
compute_average(ODD_COUNTERS);
format_all_counters(ODD_COUNTERS);
flush_stdout();
}
}
void check_dev_msr()
{
struct stat sb;
if (stat("/dev/cpu/0/msr", &sb))
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
cap_header->pid = getpid();
cap_header->version = _LINUX_CAPABILITY_VERSION;
if (capget(cap_header, cap_data) < 0)
err(-6, "capget(2) failed");
if ((cap_data->effective & (1 << CAP_SYS_RAWIO)) == 0) {
do_exit++;
warnx("capget(CAP_SYS_RAWIO) failed,"
" try \"# setcap cap_sys_rawio=ep %s\"", progname);
}
if (euidaccess("/dev/cpu/0/msr", R_OK)) {
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
int *pkg_cstate_limits;
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case 0x1A:
case 0x1E:
case 0x1F:
case 0x25:
case 0x2C:
case 0x2E:
case 0x2F:
pkg_cstate_limits = nhm_pkg_cstate_limits;
break;
case 0x2A:
case 0x2D:
case 0x3A:
case 0x3E:
pkg_cstate_limits = snb_pkg_cstate_limits;
break;
case 0x3C:
case 0x3F:
case 0x45:
case 0x46:
case 0x3D:
case 0x47:
case 0x4F:
case 0x56:
pkg_cstate_limits = hsw_pkg_cstate_limits;
break;
case 0x37:
case 0x4D:
pkg_cstate_limits = slv_pkg_cstate_limits;
break;
case 0x4C:
pkg_cstate_limits = amt_pkg_cstate_limits;
break;
case 0x57:
pkg_cstate_limits = phi_pkg_cstate_limits;
break;
default:
return 0;
}
get_msr(0, MSR_NHM_SNB_PKG_CST_CFG_CTL, &msr);
pkg_cstate_limit = pkg_cstate_limits[msr & 0x7];
return 1;
}
int has_nhm_turbo_ratio_limit(unsigned int family, unsigned int model)
{
switch (model) {
case 0x2E:
case 0x2F:
return 0;
default:
return 1;
}
}
int has_ivt_turbo_ratio_limit(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
if (family != 6)
return 0;
switch (model) {
case 0x3E:
return 1;
default:
return 0;
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
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (get_msr(cpu, MSR_IA32_ENERGY_PERF_BIAS, &msr))
return 0;
switch (msr & 0x7) {
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
fprintf(stderr, "cpu%d: MSR_IA32_ENERGY_PERF_BIAS: 0x%08llx (%s)\n", cpu, msr, epb_string);
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
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (do_core_perf_limit_reasons) {
get_msr(cpu, MSR_CORE_PERF_LIMIT_REASONS, &msr);
fprintf(stderr, "cpu%d: MSR_CORE_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(stderr, " (Active: %s%s%s%s%s%s%s%s%s%s%s%s%s%s)",
(msr & 1 << 0) ? "PROCHOT, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 2) ? "bit2, " : "",
(msr & 1 << 4) ? "Graphics, " : "",
(msr & 1 << 5) ? "Auto-HWP, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 9) ? "CorePwr, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "",
(msr & 1 << 12) ? "MultiCoreTurbo, " : "",
(msr & 1 << 13) ? "Transitions, " : "",
(msr & 1 << 14) ? "bit14, " : "",
(msr & 1 << 15) ? "bit15, " : "");
fprintf(stderr, " (Logged: %s%s%s%s%s%s%s%s%s%s%s%s%s%s)\n",
(msr & 1 << 16) ? "PROCHOT, " : "",
(msr & 1 << 17) ? "ThermStatus, " : "",
(msr & 1 << 18) ? "bit18, " : "",
(msr & 1 << 20) ? "Graphics, " : "",
(msr & 1 << 21) ? "Auto-HWP, " : "",
(msr & 1 << 22) ? "VR-Therm, " : "",
(msr & 1 << 24) ? "Amps, " : "",
(msr & 1 << 25) ? "CorePwr, " : "",
(msr & 1 << 26) ? "PkgPwrL1, " : "",
(msr & 1 << 27) ? "PkgPwrL2, " : "",
(msr & 1 << 28) ? "MultiCoreTurbo, " : "",
(msr & 1 << 29) ? "Transitions, " : "",
(msr & 1 << 30) ? "bit30, " : "",
(msr & 1 << 31) ? "bit31, " : "");
}
if (do_gfx_perf_limit_reasons) {
get_msr(cpu, MSR_GFX_PERF_LIMIT_REASONS, &msr);
fprintf(stderr, "cpu%d: MSR_GFX_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(stderr, " (Active: %s%s%s%s%s%s%s%s)",
(msr & 1 << 0) ? "PROCHOT, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 4) ? "Graphics, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 9) ? "GFXPwr, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "");
fprintf(stderr, " (Logged: %s%s%s%s%s%s%s%s)\n",
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
fprintf(stderr, "cpu%d: MSR_RING_PERF_LIMIT_REASONS, 0x%08llx", cpu, msr);
fprintf(stderr, " (Active: %s%s%s%s%s%s)",
(msr & 1 << 0) ? "PROCHOT, " : "",
(msr & 1 << 1) ? "ThermStatus, " : "",
(msr & 1 << 6) ? "VR-Therm, " : "",
(msr & 1 << 8) ? "Amps, " : "",
(msr & 1 << 10) ? "PkgPwrL1, " : "",
(msr & 1 << 11) ? "PkgPwrL2, " : "");
fprintf(stderr, " (Logged: %s%s%s%s%s%s)\n",
(msr & 1 << 16) ? "PROCHOT, " : "",
(msr & 1 << 17) ? "ThermStatus, " : "",
(msr & 1 << 22) ? "VR-Therm, " : "",
(msr & 1 << 24) ? "Amps, " : "",
(msr & 1 << 26) ? "PkgPwrL1, " : "",
(msr & 1 << 27) ? "PkgPwrL2, " : "");
}
return 0;
}
double get_tdp(model)
{
unsigned long long msr;
if (do_rapl & RAPL_PKG_POWER_INFO)
if (!get_msr(0, MSR_PKG_POWER_INFO, &msr))
return ((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units;
switch (model) {
case 0x37:
case 0x4D:
return 30.0;
default:
return 135.0;
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
case 0x2A:
case 0x3A:
case 0x3C:
case 0x45:
case 0x46:
case 0x3D:
case 0x47:
do_rapl = RAPL_PKG | RAPL_CORES | RAPL_CORE_POLICY | RAPL_GFX | RAPL_PKG_POWER_INFO;
break;
case 0x3F:
case 0x4F:
case 0x56:
do_rapl = RAPL_PKG | RAPL_DRAM | RAPL_DRAM_PERF_STATUS | RAPL_PKG_PERF_STATUS | RAPL_PKG_POWER_INFO;
break;
case 0x2D:
case 0x3E:
do_rapl = RAPL_PKG | RAPL_CORES | RAPL_CORE_POLICY | RAPL_DRAM | RAPL_PKG_PERF_STATUS | RAPL_DRAM_PERF_STATUS | RAPL_PKG_POWER_INFO;
break;
case 0x37:
case 0x4D:
do_rapl = RAPL_PKG | RAPL_CORES ;
break;
default:
return;
}
if (get_msr(0, MSR_RAPL_POWER_UNIT, &msr))
return;
rapl_power_units = 1.0 / (1 << (msr & 0xF));
if (model == 0x37)
rapl_energy_units = 1.0 * (1 << (msr >> 8 & 0x1F)) / 1000000;
else
rapl_energy_units = 1.0 / (1 << (msr >> 8 & 0x1F));
time_unit = msr >> 16 & 0xF;
if (time_unit == 0)
time_unit = 0xA;
rapl_time_units = 1.0 / (1 << (time_unit));
tdp = get_tdp(model);
rapl_joule_counter_range = 0xFFFFFFFF * rapl_energy_units / tdp;
if (debug)
fprintf(stderr, "RAPL: %.0f sec. Joule Counter Range, at %.0f Watts\n", rapl_joule_counter_range, tdp);
return;
}
void perf_limit_reasons_probe(family, model)
{
if (!genuine_intel)
return;
if (family != 6)
return;
switch (model) {
case 0x3C:
case 0x45:
case 0x46:
do_gfx_perf_limit_reasons = 1;
case 0x3F:
do_core_perf_limit_reasons = 1;
do_ring_perf_limit_reasons = 1;
default:
return;
}
}
int print_thermal(struct thread_data *t, struct core_data *c, struct pkg_data *p)
{
unsigned long long msr;
unsigned int dts;
int cpu;
if (!(do_dts || do_ptm))
return 0;
cpu = t->cpu_id;
if (!(t->flags & CPU_IS_FIRST_THREAD_IN_CORE))
return 0;
if (cpu_migrate(cpu)) {
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (do_ptm && (t->flags & CPU_IS_FIRST_CORE_IN_PACKAGE)) {
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_STATUS, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
fprintf(stderr, "cpu%d: MSR_IA32_PACKAGE_THERM_STATUS: 0x%08llx (%d C)\n",
cpu, msr, tcc_activation_temp - dts);
#ifdef THERM_DEBUG
if (get_msr(cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
dts2 = (msr >> 8) & 0x7F;
fprintf(stderr, "cpu%d: MSR_IA32_PACKAGE_THERM_INTERRUPT: 0x%08llx (%d C, %d C)\n",
cpu, msr, tcc_activation_temp - dts, tcc_activation_temp - dts2);
#endif
}
if (do_dts) {
unsigned int resolution;
if (get_msr(cpu, MSR_IA32_THERM_STATUS, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
resolution = (msr >> 27) & 0xF;
fprintf(stderr, "cpu%d: MSR_IA32_THERM_STATUS: 0x%08llx (%d C +/- %d)\n",
cpu, msr, tcc_activation_temp - dts, resolution);
#ifdef THERM_DEBUG
if (get_msr(cpu, MSR_IA32_THERM_INTERRUPT, &msr))
return 0;
dts = (msr >> 16) & 0x7F;
dts2 = (msr >> 8) & 0x7F;
fprintf(stderr, "cpu%d: MSR_IA32_THERM_INTERRUPT: 0x%08llx (%d C, %d C)\n",
cpu, msr, tcc_activation_temp - dts, tcc_activation_temp - dts2);
#endif
}
return 0;
}
void print_power_limit_msr(int cpu, unsigned long long msr, char *label)
{
fprintf(stderr, "cpu%d: %s: %sabled (%f Watts, %f sec, clamp %sabled)\n",
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
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (get_msr(cpu, MSR_RAPL_POWER_UNIT, &msr))
return -1;
if (debug) {
fprintf(stderr, "cpu%d: MSR_RAPL_POWER_UNIT: 0x%08llx "
"(%f Watts, %f Joules, %f sec.)\n", cpu, msr,
rapl_power_units, rapl_energy_units, rapl_time_units);
}
if (do_rapl & RAPL_PKG_POWER_INFO) {
if (get_msr(cpu, MSR_PKG_POWER_INFO, &msr))
return -5;
fprintf(stderr, "cpu%d: MSR_PKG_POWER_INFO: 0x%08llx (%.0f W TDP, RAPL %.0f - %.0f W, %f sec.)\n",
cpu, msr,
((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 16) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 32) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 48) & RAPL_TIME_GRANULARITY) * rapl_time_units);
}
if (do_rapl & RAPL_PKG) {
if (get_msr(cpu, MSR_PKG_POWER_LIMIT, &msr))
return -9;
fprintf(stderr, "cpu%d: MSR_PKG_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 63) & 1 ? "": "UN");
print_power_limit_msr(cpu, msr, "PKG Limit #1");
fprintf(stderr, "cpu%d: PKG Limit #2: %sabled (%f Watts, %f* sec, clamp %sabled)\n",
cpu,
((msr >> 47) & 1) ? "EN" : "DIS",
((msr >> 32) & 0x7FFF) * rapl_power_units,
(1.0 + (((msr >> 54) & 0x3)/4.0)) * (1 << ((msr >> 49) & 0x1F)) * rapl_time_units,
((msr >> 48) & 1) ? "EN" : "DIS");
}
if (do_rapl & RAPL_DRAM) {
if (get_msr(cpu, MSR_DRAM_POWER_INFO, &msr))
return -6;
fprintf(stderr, "cpu%d: MSR_DRAM_POWER_INFO,: 0x%08llx (%.0f W TDP, RAPL %.0f - %.0f W, %f sec.)\n",
cpu, msr,
((msr >> 0) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 16) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 32) & RAPL_POWER_GRANULARITY) * rapl_power_units,
((msr >> 48) & RAPL_TIME_GRANULARITY) * rapl_time_units);
if (get_msr(cpu, MSR_DRAM_POWER_LIMIT, &msr))
return -9;
fprintf(stderr, "cpu%d: MSR_DRAM_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "": "UN");
print_power_limit_msr(cpu, msr, "DRAM Limit");
}
if (do_rapl & RAPL_CORE_POLICY) {
if (debug) {
if (get_msr(cpu, MSR_PP0_POLICY, &msr))
return -7;
fprintf(stderr, "cpu%d: MSR_PP0_POLICY: %lld\n", cpu, msr & 0xF);
}
}
if (do_rapl & RAPL_CORES) {
if (debug) {
if (get_msr(cpu, MSR_PP0_POWER_LIMIT, &msr))
return -9;
fprintf(stderr, "cpu%d: MSR_PP0_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "": "UN");
print_power_limit_msr(cpu, msr, "Cores Limit");
}
}
if (do_rapl & RAPL_GFX) {
if (debug) {
if (get_msr(cpu, MSR_PP1_POLICY, &msr))
return -8;
fprintf(stderr, "cpu%d: MSR_PP1_POLICY: %lld\n", cpu, msr & 0xF);
if (get_msr(cpu, MSR_PP1_POWER_LIMIT, &msr))
return -9;
fprintf(stderr, "cpu%d: MSR_PP1_POWER_LIMIT: 0x%08llx (%slocked)\n",
cpu, msr, (msr >> 31) & 1 ? "": "UN");
print_power_limit_msr(cpu, msr, "GFX Limit");
}
}
return 0;
}
int has_snb_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case 0x2A:
case 0x2D:
case 0x3A:
case 0x3E:
case 0x3C:
case 0x3F:
case 0x45:
case 0x46:
case 0x3D:
case 0x47:
case 0x4F:
case 0x56:
return 1;
}
return 0;
}
int has_hsw_msrs(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case 0x45:
case 0x3D:
return 1;
}
return 0;
}
int is_slm(unsigned int family, unsigned int model)
{
if (!genuine_intel)
return 0;
switch (model) {
case 0x37:
case 0x4D:
return 1;
}
return 0;
}
double slm_bclk(void)
{
unsigned long long msr = 3;
unsigned int i;
double freq;
if (get_msr(0, MSR_FSB_FREQ, &msr))
fprintf(stderr, "SLM BCLK: unknown\n");
i = msr & 0xf;
if (i >= SLM_BCLK_FREQS) {
fprintf(stderr, "SLM BCLK[%d] invalid\n", i);
msr = 3;
}
freq = slm_freq_table[i];
fprintf(stderr, "SLM BCLK: %.1f Mhz\n", freq);
return freq;
}
double discover_bclk(unsigned int family, unsigned int model)
{
if (has_snb_msrs(family, model))
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
fprintf(stderr, "Could not migrate to CPU %d\n", cpu);
return -1;
}
if (tcc_activation_temp_override != 0) {
tcc_activation_temp = tcc_activation_temp_override;
fprintf(stderr, "cpu%d: Using cmdline TCC Target (%d C)\n",
cpu, tcc_activation_temp);
return 0;
}
if (!do_nhm_platform_info)
goto guess;
if (get_msr(0, MSR_IA32_TEMPERATURE_TARGET, &msr))
goto guess;
target_c_local = (msr >> 16) & 0xFF;
if (debug)
fprintf(stderr, "cpu%d: MSR_IA32_TEMPERATURE_TARGET: 0x%08llx (%d C)\n",
cpu, msr, target_c_local);
if (!target_c_local)
goto guess;
tcc_activation_temp = target_c_local;
return 0;
guess:
tcc_activation_temp = TJMAX_DEFAULT;
fprintf(stderr, "cpu%d: Guessing tjMax %d C, Please use -T to specify\n",
cpu, tcc_activation_temp);
return 0;
}
void check_cpuid()
{
unsigned int eax, ebx, ecx, edx, max_level;
unsigned int fms, family, model, stepping;
eax = ebx = ecx = edx = 0;
__get_cpuid(0, &max_level, &ebx, &ecx, &edx);
if (ebx == 0x756e6547 && edx == 0x49656e69 && ecx == 0x6c65746e)
genuine_intel = 1;
if (debug)
fprintf(stderr, "CPUID(0): %.4s%.4s%.4s ",
(char *)&ebx, (char *)&edx, (char *)&ecx);
__get_cpuid(1, &fms, &ebx, &ecx, &edx);
family = (fms >> 8) & 0xf;
model = (fms >> 4) & 0xf;
stepping = fms & 0xf;
if (family == 6 || family == 0xf)
model += ((fms >> 16) & 0xf) << 4;
if (debug)
fprintf(stderr, "%d CPUID levels; family:model:stepping 0x%x:%x:%x (%d:%d:%d)\n",
max_level, family, model, stepping, family, model, stepping);
if (!(edx & (1 << 5)))
errx(1, "CPUID: no MSR");
ebx = ecx = edx = 0;
__get_cpuid(0x80000000, &max_level, &ebx, &ecx, &edx);
if (max_level >= 0x80000007) {
__get_cpuid(0x80000007, &eax, &ebx, &ecx, &edx);
has_invariant_tsc = edx & (1 << 8);
}
__get_cpuid(0x6, &eax, &ebx, &ecx, &edx);
has_aperf = ecx & (1 << 0);
do_dts = eax & (1 << 0);
do_ptm = eax & (1 << 6);
has_epb = ecx & (1 << 3);
if (debug)
fprintf(stderr, "CPUID(6): %sAPERF, %sDTS, %sPTM, %sEPB\n",
has_aperf ? "" : "No ",
do_dts ? "" : "No ",
do_ptm ? "" : "No ",
has_epb ? "" : "No ");
do_nhm_platform_info = do_nhm_cstates = do_smi = probe_nhm_msrs(family, model);
do_snb_cstates = has_snb_msrs(family, model);
do_pc2 = do_snb_cstates && (pkg_cstate_limit >= PCL__2);
do_pc3 = (pkg_cstate_limit >= PCL__3);
do_pc6 = (pkg_cstate_limit >= PCL__6);
do_pc7 = do_snb_cstates && (pkg_cstate_limit >= PCL__7);
do_c8_c9_c10 = has_hsw_msrs(family, model);
do_slm_cstates = is_slm(family, model);
bclk = discover_bclk(family, model);
do_nhm_turbo_ratio_limit = do_nhm_platform_info && has_nhm_turbo_ratio_limit(family, model);
do_ivt_turbo_ratio_limit = has_ivt_turbo_ratio_limit(family, model);
rapl_probe(family, model);
perf_limit_reasons_probe(family, model);
return;
}
void help()
{
fprintf(stderr,
"Usage: turbostat [OPTIONS][(--interval seconds) | COMMAND ...]\n"
"\n"
"Turbostat forks the specified COMMAND and prints statistics\n"
"when COMMAND completes.\n"
"If no COMMAND is specified, turbostat wakes every 5-seconds\n"
"to print statistics, until interrupted.\n"
"--debug run in \"debug\" mode\n"
"--interval sec Override default 5-second measurement interval\n"
"--help print this help message\n"
"--counter msr print 32-bit counter at address \"msr\"\n"
"--Counter msr print 64-bit Counter at address \"msr\"\n"
"--msr msr print 32-bit value at address \"msr\"\n"
"--MSR msr print 64-bit Value at address \"msr\"\n"
"--version print version information\n"
"\n"
"For more help, run \"man turbostat\"\n");
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
show_cpu = 1;
if (debug > 1)
fprintf(stderr, "num_cpus %d max_cpu_num %d\n", topo.num_cpus, topo.max_cpu_num);
cpus = calloc(1, (topo.max_cpu_num + 1) * sizeof(struct cpu_topology));
if (cpus == NULL)
err(1, "calloc cpus");
cpu_present_set = CPU_ALLOC((topo.max_cpu_num + 1));
if (cpu_present_set == NULL)
err(3, "CPU_ALLOC");
cpu_present_setsize = CPU_ALLOC_SIZE((topo.max_cpu_num + 1));
CPU_ZERO_S(cpu_present_setsize, cpu_present_set);
for_all_proc_cpus(mark_cpu_present);
cpu_affinity_set = CPU_ALLOC((topo.max_cpu_num + 1));
if (cpu_affinity_set == NULL)
err(3, "CPU_ALLOC");
cpu_affinity_setsize = CPU_ALLOC_SIZE((topo.max_cpu_num + 1));
CPU_ZERO_S(cpu_affinity_setsize, cpu_affinity_set);
for (i = 0; i <= topo.max_cpu_num; ++i) {
int siblings;
if (cpu_is_not_present(i)) {
if (debug > 1)
fprintf(stderr, "cpu%d NOT PRESENT\n", i);
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
fprintf(stderr, "cpu %d pkg %d core %d\n",
i, cpus[i].physical_package_id, cpus[i].core_id);
}
topo.num_cores_per_pkg = max_core_id + 1;
if (debug > 1)
fprintf(stderr, "max_core_id %d, sizing for %d cores per package\n",
max_core_id, topo.num_cores_per_pkg);
if (!summary_only && topo.num_cores_per_pkg > 1)
show_core = 1;
topo.num_packages = max_package_id + 1;
if (debug > 1)
fprintf(stderr, "max_package_id %d, sizing for %d packages\n",
max_package_id, topo.num_packages);
if (!summary_only && topo.num_packages > 1)
show_pkg = 1;
topo.num_threads_per_core = max_siblings;
if (debug > 1)
fprintf(stderr, "max_siblings %d\n", max_siblings);
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
if (cpu_is_first_sibling_in_core(cpu_id)) {
my_thread_id = 0;
topo.num_cores++;
} else {
my_thread_id = 1;
}
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
void setup_all_buffers(void)
{
topology_probe();
allocate_counters(&thread_even, &core_even, &package_even);
allocate_counters(&thread_odd, &core_odd, &package_odd);
allocate_output_buffer();
for_all_proc_cpus(initialize_counters);
}
void turbostat_init()
{
check_dev_msr();
check_permissions();
check_cpuid();
setup_all_buffers();
if (debug)
print_verbose_header();
if (debug)
for_all_cpus(print_epb, ODD_COUNTERS);
if (debug)
for_all_cpus(print_perf_limit, ODD_COUNTERS);
if (debug)
for_all_cpus(print_rapl, ODD_COUNTERS);
for_all_cpus(set_temperature_target, ODD_COUNTERS);
if (debug)
for_all_cpus(print_thermal, ODD_COUNTERS);
}
int fork_it(char **argv)
{
pid_t child_pid;
int status;
status = for_all_cpus(get_counters, EVEN_COUNTERS);
if (status)
exit(status);
sched_setaffinity(0, cpu_present_setsize, cpu_present_set);
gettimeofday(&tv_even, (struct timezone *)NULL);
child_pid = fork();
if (!child_pid) {
execvp(argv[0], argv);
} else {
if (child_pid == -1)
err(1, "fork");
signal(SIGINT, SIG_IGN);
signal(SIGQUIT, SIG_IGN);
if (waitpid(child_pid, &status, 0) == -1)
err(status, "waitpid");
}
for_all_cpus(get_counters, ODD_COUNTERS);
gettimeofday(&tv_odd, (struct timezone *)NULL);
timersub(&tv_odd, &tv_even, &tv_delta);
for_all_cpus_2(delta_cpu, ODD_COUNTERS, EVEN_COUNTERS);
compute_average(EVEN_COUNTERS);
format_all_counters(EVEN_COUNTERS);
flush_stderr();
fprintf(stderr, "%.6f sec\n", tv_delta.tv_sec + tv_delta.tv_usec/1000000.0);
return status;
}
int get_and_dump_counters(void)
{
int status;
status = for_all_cpus(get_counters, ODD_COUNTERS);
if (status)
return status;
status = for_all_cpus(dump_counters, ODD_COUNTERS);
if (status)
return status;
flush_stdout();
return status;
}
void print_version() {
fprintf(stderr, "turbostat version 4.1 10-Feb, 2015"
" - Len Brown <lenb@kernel.org>\n");
}
void cmdline(int argc, char **argv)
{
int opt;
int option_index = 0;
static struct option long_options[] = {
{"Counter", required_argument, 0, 'C'},
{"counter", required_argument, 0, 'c'},
{"Dump", no_argument, 0, 'D'},
{"debug", no_argument, 0, 'd'},
{"interval", required_argument, 0, 'i'},
{"help", no_argument, 0, 'h'},
{"Joules", no_argument, 0, 'J'},
{"MSR", required_argument, 0, 'M'},
{"msr", required_argument, 0, 'm'},
{"Package", no_argument, 0, 'p'},
{"processor", no_argument, 0, 'p'},
{"Summary", no_argument, 0, 'S'},
{"TCC", required_argument, 0, 'T'},
{"version", no_argument, 0, 'v' },
{0, 0, 0, 0 }
};
progname = argv[0];
while ((opt = getopt_long_only(argc, argv, "C:c:Ddhi:JM:m:PpST:v",
long_options, &option_index)) != -1) {
switch (opt) {
case 'C':
sscanf(optarg, "%x", &extra_delta_offset64);
break;
case 'c':
sscanf(optarg, "%x", &extra_delta_offset32);
break;
case 'D':
dump_only++;
break;
case 'd':
debug++;
break;
case 'h':
default:
help();
exit(1);
case 'i':
interval_sec = atoi(optarg);
break;
case 'J':
rapl_joules++;
break;
case 'M':
sscanf(optarg, "%x", &extra_msr_offset64);
break;
case 'm':
sscanf(optarg, "%x", &extra_msr_offset32);
break;
case 'P':
show_pkg_only++;
break;
case 'p':
show_core_only++;
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
cmdline(argc, argv);
if (debug)
print_version();
turbostat_init();
if (dump_only)
return get_and_dump_counters();
if (argc - optind)
return fork_it(argv + optind);
else
turbostat_loop();
return 0;
}
