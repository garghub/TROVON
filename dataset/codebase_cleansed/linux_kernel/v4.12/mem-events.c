char *perf_mem_events__name(int i)
{
if (i == PERF_MEM_EVENTS__LOAD) {
if (!mem_loads_name__init) {
mem_loads_name__init = true;
scnprintf(mem_loads_name, sizeof(mem_loads_name),
perf_mem_events[i].name,
perf_mem_events__loads_ldlat);
}
return mem_loads_name;
}
return (char *)perf_mem_events[i].name;
}
int perf_mem_events__parse(const char *str)
{
char *tok, *saveptr = NULL;
bool found = false;
char *buf;
int j;
buf = malloc(strlen(str) + 1);
if (!buf)
return -ENOMEM;
strcpy(buf, str);
tok = strtok_r((char *)buf, ",", &saveptr);
while (tok) {
for (j = 0; j < PERF_MEM_EVENTS__MAX; j++) {
struct perf_mem_event *e = &perf_mem_events[j];
if (strstr(e->tag, tok))
e->record = found = true;
}
tok = strtok_r(NULL, ",", &saveptr);
}
free(buf);
if (found)
return 0;
pr_err("failed: event '%s' not found, use '-e list' to get list of available events\n", str);
return -1;
}
int perf_mem_events__init(void)
{
const char *mnt = sysfs__mount();
bool found = false;
int j;
if (!mnt)
return -ENOENT;
for (j = 0; j < PERF_MEM_EVENTS__MAX; j++) {
char path[PATH_MAX];
struct perf_mem_event *e = &perf_mem_events[j];
struct stat st;
scnprintf(path, PATH_MAX, "%s/devices/cpu/events/%s",
mnt, e->sysfs_name);
if (!stat(path, &st))
e->supported = found = true;
}
return found ? 0 : -ENOENT;
}
int perf_mem__tlb_scnprintf(char *out, size_t sz, struct mem_info *mem_info)
{
size_t l = 0, i;
u64 m = PERF_MEM_TLB_NA;
u64 hit, miss;
sz -= 1;
out[0] = '\0';
if (mem_info)
m = mem_info->data_src.mem_dtlb;
hit = m & PERF_MEM_TLB_HIT;
miss = m & PERF_MEM_TLB_MISS;
m &= ~(PERF_MEM_TLB_HIT|PERF_MEM_TLB_MISS);
for (i = 0; m && i < ARRAY_SIZE(tlb_access); i++, m >>= 1) {
if (!(m & 0x1))
continue;
if (l) {
strcat(out, " or ");
l += 4;
}
l += scnprintf(out + l, sz - l, tlb_access[i]);
}
if (*out == '\0')
l += scnprintf(out, sz - l, "N/A");
if (hit)
l += scnprintf(out + l, sz - l, " hit");
if (miss)
l += scnprintf(out + l, sz - l, " miss");
return l;
}
int perf_mem__lvl_scnprintf(char *out, size_t sz, struct mem_info *mem_info)
{
size_t i, l = 0;
u64 m = PERF_MEM_LVL_NA;
u64 hit, miss;
if (mem_info)
m = mem_info->data_src.mem_lvl;
sz -= 1;
out[0] = '\0';
hit = m & PERF_MEM_LVL_HIT;
miss = m & PERF_MEM_LVL_MISS;
m &= ~(PERF_MEM_LVL_HIT|PERF_MEM_LVL_MISS);
for (i = 0; m && i < ARRAY_SIZE(mem_lvl); i++, m >>= 1) {
if (!(m & 0x1))
continue;
if (l) {
strcat(out, " or ");
l += 4;
}
l += scnprintf(out + l, sz - l, mem_lvl[i]);
}
if (*out == '\0')
l += scnprintf(out, sz - l, "N/A");
if (hit)
l += scnprintf(out + l, sz - l, " hit");
if (miss)
l += scnprintf(out + l, sz - l, " miss");
return l;
}
int perf_mem__snp_scnprintf(char *out, size_t sz, struct mem_info *mem_info)
{
size_t i, l = 0;
u64 m = PERF_MEM_SNOOP_NA;
sz -= 1;
out[0] = '\0';
if (mem_info)
m = mem_info->data_src.mem_snoop;
for (i = 0; m && i < ARRAY_SIZE(snoop_access); i++, m >>= 1) {
if (!(m & 0x1))
continue;
if (l) {
strcat(out, " or ");
l += 4;
}
l += scnprintf(out + l, sz - l, snoop_access[i]);
}
if (*out == '\0')
l += scnprintf(out, sz - l, "N/A");
return l;
}
int perf_mem__lck_scnprintf(char *out, size_t sz, struct mem_info *mem_info)
{
u64 mask = PERF_MEM_LOCK_NA;
int l;
if (mem_info)
mask = mem_info->data_src.mem_lock;
if (mask & PERF_MEM_LOCK_NA)
l = scnprintf(out, sz, "N/A");
else if (mask & PERF_MEM_LOCK_LOCKED)
l = scnprintf(out, sz, "Yes");
else
l = scnprintf(out, sz, "No");
return l;
}
int perf_script__meminfo_scnprintf(char *out, size_t sz, struct mem_info *mem_info)
{
int i = 0;
i += perf_mem__lvl_scnprintf(out, sz, mem_info);
i += scnprintf(out + i, sz - i, "|SNP ");
i += perf_mem__snp_scnprintf(out + i, sz - i, mem_info);
i += scnprintf(out + i, sz - i, "|TLB ");
i += perf_mem__tlb_scnprintf(out + i, sz - i, mem_info);
i += scnprintf(out + i, sz - i, "|LCK ");
i += perf_mem__lck_scnprintf(out + i, sz - i, mem_info);
return i;
}
int c2c_decode_stats(struct c2c_stats *stats, struct mem_info *mi)
{
union perf_mem_data_src *data_src = &mi->data_src;
u64 daddr = mi->daddr.addr;
u64 op = data_src->mem_op;
u64 lvl = data_src->mem_lvl;
u64 snoop = data_src->mem_snoop;
u64 lock = data_src->mem_lock;
int err = 0;
#define HITM_INC(__f) \
do { \
stats->__f++; \
stats->tot_hitm++; \
} while (0)
#define P(a, b) PERF_MEM_##a##_##b
stats->nr_entries++;
if (lock & P(LOCK, LOCKED)) stats->locks++;
if (op & P(OP, LOAD)) {
stats->load++;
if (!daddr) {
stats->ld_noadrs++;
return -1;
}
if (lvl & P(LVL, HIT)) {
if (lvl & P(LVL, UNC)) stats->ld_uncache++;
if (lvl & P(LVL, IO)) stats->ld_io++;
if (lvl & P(LVL, LFB)) stats->ld_fbhit++;
if (lvl & P(LVL, L1 )) stats->ld_l1hit++;
if (lvl & P(LVL, L2 )) stats->ld_l2hit++;
if (lvl & P(LVL, L3 )) {
if (snoop & P(SNOOP, HITM))
HITM_INC(lcl_hitm);
else
stats->ld_llchit++;
}
if (lvl & P(LVL, LOC_RAM)) {
stats->lcl_dram++;
if (snoop & P(SNOOP, HIT))
stats->ld_shared++;
else
stats->ld_excl++;
}
if ((lvl & P(LVL, REM_RAM1)) ||
(lvl & P(LVL, REM_RAM2))) {
stats->rmt_dram++;
if (snoop & P(SNOOP, HIT))
stats->ld_shared++;
else
stats->ld_excl++;
}
}
if ((lvl & P(LVL, REM_CCE1)) ||
(lvl & P(LVL, REM_CCE2))) {
if (snoop & P(SNOOP, HIT))
stats->rmt_hit++;
else if (snoop & P(SNOOP, HITM))
HITM_INC(rmt_hitm);
}
if ((lvl & P(LVL, MISS)))
stats->ld_miss++;
} else if (op & P(OP, STORE)) {
stats->store++;
if (!daddr) {
stats->st_noadrs++;
return -1;
}
if (lvl & P(LVL, HIT)) {
if (lvl & P(LVL, UNC)) stats->st_uncache++;
if (lvl & P(LVL, L1 )) stats->st_l1hit++;
}
if (lvl & P(LVL, MISS))
if (lvl & P(LVL, L1)) stats->st_l1miss++;
} else {
stats->noparse++;
return -1;
}
if (!mi->daddr.map || !mi->iaddr.map) {
stats->nomap++;
return -1;
}
#undef P
#undef HITM_INC
return err;
}
void c2c_add_stats(struct c2c_stats *stats, struct c2c_stats *add)
{
stats->nr_entries += add->nr_entries;
stats->locks += add->locks;
stats->store += add->store;
stats->st_uncache += add->st_uncache;
stats->st_noadrs += add->st_noadrs;
stats->st_l1hit += add->st_l1hit;
stats->st_l1miss += add->st_l1miss;
stats->load += add->load;
stats->ld_excl += add->ld_excl;
stats->ld_shared += add->ld_shared;
stats->ld_uncache += add->ld_uncache;
stats->ld_io += add->ld_io;
stats->ld_miss += add->ld_miss;
stats->ld_noadrs += add->ld_noadrs;
stats->ld_fbhit += add->ld_fbhit;
stats->ld_l1hit += add->ld_l1hit;
stats->ld_l2hit += add->ld_l2hit;
stats->ld_llchit += add->ld_llchit;
stats->lcl_hitm += add->lcl_hitm;
stats->rmt_hitm += add->rmt_hitm;
stats->tot_hitm += add->tot_hitm;
stats->rmt_hit += add->rmt_hit;
stats->lcl_dram += add->lcl_dram;
stats->rmt_dram += add->rmt_dram;
stats->nomap += add->nomap;
stats->noparse += add->noparse;
}
