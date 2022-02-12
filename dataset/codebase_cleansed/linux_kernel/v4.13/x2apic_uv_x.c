unsigned long uv_undefined(char *str)
{
if (likely(!disable_uv_undefined_panic))
panic("UV: error: undefined MMR: %s\n", str);
else
pr_crit("UV: error: undefined MMR: %s\n", str);
return ~0ul;
}
static unsigned long __init uv_early_read_mmr(unsigned long addr)
{
unsigned long val, *mmr;
mmr = early_ioremap(UV_LOCAL_MMR_BASE | addr, sizeof(*mmr));
val = *mmr;
early_iounmap(mmr, sizeof(*mmr));
return val;
}
static inline bool is_GRU_range(u64 start, u64 end)
{
if (gru_dist_base) {
u64 su = start & gru_dist_umask;
u64 sl = start & gru_dist_lmask;
u64 eu = end & gru_dist_umask;
u64 el = end & gru_dist_lmask;
return (sl == gru_dist_base && el == gru_dist_base &&
su >= gru_first_node_paddr &&
su <= gru_last_node_paddr &&
eu == su);
} else {
return start >= gru_start_paddr && end <= gru_end_paddr;
}
}
static bool uv_is_untracked_pat_range(u64 start, u64 end)
{
return is_ISA_range(start, end) || is_GRU_range(start, end);
}
static int __init early_get_pnodeid(void)
{
union uvh_node_id_u node_id;
union uvh_rh_gam_config_mmr_u m_n_config;
int pnode;
node_id.v = uv_early_read_mmr(UVH_NODE_ID);
m_n_config.v = uv_early_read_mmr(UVH_RH_GAM_CONFIG_MMR);
uv_min_hub_revision_id = node_id.s.revision;
switch (node_id.s.part_number) {
case UV2_HUB_PART_NUMBER:
case UV2_HUB_PART_NUMBER_X:
uv_min_hub_revision_id += UV2_HUB_REVISION_BASE - 1;
break;
case UV3_HUB_PART_NUMBER:
case UV3_HUB_PART_NUMBER_X:
uv_min_hub_revision_id += UV3_HUB_REVISION_BASE;
break;
case UV4_HUB_PART_NUMBER:
uv_min_hub_revision_id += UV4_HUB_REVISION_BASE - 1;
uv_cpuid.gnode_shift = 2;
break;
}
uv_hub_info->hub_revision = uv_min_hub_revision_id;
uv_cpuid.pnode_mask = (1 << m_n_config.s.n_skt) - 1;
pnode = (node_id.s.node_id >> 1) & uv_cpuid.pnode_mask;
uv_cpuid.gpa_shift = 46;
pr_info("UV: rev:%d part#:%x nodeid:%04x n_skt:%d pnmsk:%x pn:%x\n",
node_id.s.revision, node_id.s.part_number, node_id.s.node_id,
m_n_config.s.n_skt, uv_cpuid.pnode_mask, pnode);
return pnode;
}
static void set_x2apic_bits(void)
{
unsigned int eax, ebx, ecx, edx, sub_index;
unsigned int sid_shift;
cpuid(0, &eax, &ebx, &ecx, &edx);
if (eax < 0xb) {
pr_info("UV: CPU does not have CPUID.11\n");
return;
}
cpuid_count(0xb, SMT_LEVEL, &eax, &ebx, &ecx, &edx);
if (ebx == 0 || (LEAFB_SUBTYPE(ecx) != SMT_TYPE)) {
pr_info("UV: CPUID.11 not implemented\n");
return;
}
sid_shift = BITS_SHIFT_NEXT_LEVEL(eax);
sub_index = 1;
do {
cpuid_count(0xb, sub_index, &eax, &ebx, &ecx, &edx);
if (LEAFB_SUBTYPE(ecx) == CORE_TYPE) {
sid_shift = BITS_SHIFT_NEXT_LEVEL(eax);
break;
}
sub_index++;
} while (LEAFB_SUBTYPE(ecx) != INVALID_TYPE);
uv_cpuid.apicid_shift = 0;
uv_cpuid.apicid_mask = (~(-1 << sid_shift));
uv_cpuid.socketid_shift = sid_shift;
}
static void __init early_get_apic_socketid_shift(void)
{
if (is_uv2_hub() || is_uv3_hub())
uvh_apicid.v = uv_early_read_mmr(UVH_APICID);
set_x2apic_bits();
pr_info("UV: apicid_shift:%d apicid_mask:0x%x\n", uv_cpuid.apicid_shift, uv_cpuid.apicid_mask);
pr_info("UV: socketid_shift:%d pnode_mask:0x%x\n", uv_cpuid.socketid_shift, uv_cpuid.pnode_mask);
}
static void __init uv_set_apicid_hibit(void)
{
union uv1h_lb_target_physical_apic_id_mask_u apicid_mask;
if (is_uv1_hub()) {
apicid_mask.v = uv_early_read_mmr(UV1H_LB_TARGET_PHYSICAL_APIC_ID_MASK);
uv_apicid_hibits = apicid_mask.s1.bit_enables & UV_APICID_HIBIT_MASK;
}
}
static int __init uv_acpi_madt_oem_check(char *oem_id, char *oem_table_id)
{
int pnodeid;
int uv_apic;
if (strncmp(oem_id, "SGI", 3) != 0) {
if (strncmp(oem_id, "NSGI", 4) == 0) {
uv_hubless_system = true;
pr_info("UV: OEM IDs %s/%s, HUBLESS\n",
oem_id, oem_table_id);
}
return 0;
}
if (numa_off) {
pr_err("UV: NUMA is off, disabling UV support\n");
return 0;
}
uv_cpu_info->p_uv_hub_info = &uv_hub_info_node0;
uv_hub_info->hub_revision =
!strncmp(oem_id, "SGI4", 4) ? UV4_HUB_REVISION_BASE :
!strncmp(oem_id, "SGI3", 4) ? UV3_HUB_REVISION_BASE :
!strcmp(oem_id, "SGI2") ? UV2_HUB_REVISION_BASE :
!strcmp(oem_id, "SGI") ? UV1_HUB_REVISION_BASE : 0;
if (uv_hub_info->hub_revision == 0)
goto badbios;
pnodeid = early_get_pnodeid();
early_get_apic_socketid_shift();
x86_platform.is_untracked_pat_range = uv_is_untracked_pat_range;
x86_platform.nmi_init = uv_nmi_init;
if (!strcmp(oem_table_id, "UVX")) {
uv_system_type = UV_X2APIC;
uv_apic = 0;
} else if (!strcmp(oem_table_id, "UVH")) {
uv_system_type = UV_NON_UNIQUE_APIC;
__this_cpu_write(x2apic_extra_bits, pnodeid << uvh_apicid.s.pnode_shift);
uv_set_apicid_hibit();
uv_apic = 1;
} else if (!strcmp(oem_table_id, "UVL")) {
uv_system_type = UV_LEGACY_APIC;
uv_apic = 0;
} else {
goto badbios;
}
pr_info("UV: OEM IDs %s/%s, System/HUB Types %d/%d, uv_apic %d\n", oem_id, oem_table_id, uv_system_type, uv_min_hub_revision_id, uv_apic);
return uv_apic;
badbios:
pr_err("UV: OEM_ID:%s OEM_TABLE_ID:%s\n", oem_id, oem_table_id);
pr_err("Current BIOS not supported, update kernel and/or BIOS\n");
BUG();
}
enum uv_system_type get_uv_system_type(void)
{
return uv_system_type;
}
int is_uv_system(void)
{
return uv_system_type != UV_NONE;
}
int is_uv_hubless(void)
{
return uv_hubless_system;
}
extern int uv_hub_info_version(void)
{
return UV_HUB_INFO_VERSION;
}
static __init void build_uv_gr_table(void)
{
struct uv_gam_range_entry *gre = uv_gre_table;
struct uv_gam_range_s *grt;
unsigned long last_limit = 0, ram_limit = 0;
int bytes, i, sid, lsid = -1, indx = 0, lindx = -1;
if (!gre)
return;
bytes = _gr_table_len * sizeof(struct uv_gam_range_s);
grt = kzalloc(bytes, GFP_KERNEL);
BUG_ON(!grt);
_gr_table = grt;
for (; gre->type != UV_GAM_RANGE_TYPE_UNUSED; gre++) {
if (gre->type == UV_GAM_RANGE_TYPE_HOLE) {
if (!ram_limit) {
ram_limit = last_limit;
last_limit = gre->limit;
lsid++;
continue;
}
last_limit = gre->limit;
pr_info("UV: extra hole in GAM RE table @%d\n", (int)(gre - uv_gre_table));
continue;
}
if (_max_socket < gre->sockid) {
pr_err("UV: GAM table sockid(%d) too large(>%d) @%d\n", gre->sockid, _max_socket, (int)(gre - uv_gre_table));
continue;
}
sid = gre->sockid - _min_socket;
if (lsid < sid) {
grt = &_gr_table[indx];
grt->base = lindx;
grt->nasid = gre->nasid;
grt->limit = last_limit = gre->limit;
lsid = sid;
lindx = indx++;
continue;
}
if (lsid == sid && !ram_limit) {
if (grt->limit == last_limit) {
grt->limit = last_limit = gre->limit;
continue;
}
}
if (!ram_limit) {
grt++;
grt->base = lindx;
grt->nasid = gre->nasid;
grt->limit = last_limit = gre->limit;
continue;
}
grt++;
grt->base = grt - _gr_table;
grt->nasid = gre->nasid;
grt->limit = last_limit = gre->limit;
lsid++;
}
grt++;
i = grt - _gr_table;
if (i < _gr_table_len) {
void *ret;
bytes = i * sizeof(struct uv_gam_range_s);
ret = krealloc(_gr_table, bytes, GFP_KERNEL);
if (ret) {
_gr_table = ret;
_gr_table_len = i;
}
}
for (i = 0, grt = _gr_table; i < _gr_table_len; i++, grt++) {
unsigned long start, end;
int gb = grt->base;
start = gb < 0 ? 0 : (unsigned long)_gr_table[gb].limit << UV_GAM_RANGE_SHFT;
end = (unsigned long)grt->limit << UV_GAM_RANGE_SHFT;
pr_info("UV: GAM Range %2d %04x 0x%013lx-0x%013lx (%d)\n", i, grt->nasid, start, end, gb);
}
}
static int uv_wakeup_secondary(int phys_apicid, unsigned long start_rip)
{
unsigned long val;
int pnode;
pnode = uv_apicid_to_pnode(phys_apicid);
phys_apicid |= uv_apicid_hibits;
val = (1UL << UVH_IPI_INT_SEND_SHFT) |
(phys_apicid << UVH_IPI_INT_APIC_ID_SHFT) |
((start_rip << UVH_IPI_INT_VECTOR_SHFT) >> 12) |
APIC_DM_INIT;
uv_write_global_mmr64(pnode, UVH_IPI_INT, val);
val = (1UL << UVH_IPI_INT_SEND_SHFT) |
(phys_apicid << UVH_IPI_INT_APIC_ID_SHFT) |
((start_rip << UVH_IPI_INT_VECTOR_SHFT) >> 12) |
APIC_DM_STARTUP;
uv_write_global_mmr64(pnode, UVH_IPI_INT, val);
return 0;
}
static void uv_send_IPI_one(int cpu, int vector)
{
unsigned long apicid;
int pnode;
apicid = per_cpu(x86_cpu_to_apicid, cpu);
pnode = uv_apicid_to_pnode(apicid);
uv_hub_send_ipi(pnode, apicid, vector);
}
static void uv_send_IPI_mask(const struct cpumask *mask, int vector)
{
unsigned int cpu;
for_each_cpu(cpu, mask)
uv_send_IPI_one(cpu, vector);
}
static void uv_send_IPI_mask_allbutself(const struct cpumask *mask, int vector)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
for_each_cpu(cpu, mask) {
if (cpu != this_cpu)
uv_send_IPI_one(cpu, vector);
}
}
static void uv_send_IPI_allbutself(int vector)
{
unsigned int this_cpu = smp_processor_id();
unsigned int cpu;
for_each_online_cpu(cpu) {
if (cpu != this_cpu)
uv_send_IPI_one(cpu, vector);
}
}
static void uv_send_IPI_all(int vector)
{
uv_send_IPI_mask(cpu_online_mask, vector);
}
static int uv_apic_id_valid(int apicid)
{
return 1;
}
static int uv_apic_id_registered(void)
{
return 1;
}
static void uv_init_apic_ldr(void)
{
}
static int
uv_cpu_mask_to_apicid(const struct cpumask *mask, struct irq_data *irqdata,
unsigned int *apicid)
{
int ret = default_cpu_mask_to_apicid(mask, irqdata, apicid);
if (!ret)
*apicid |= uv_apicid_hibits;
return ret;
}
static unsigned int x2apic_get_apic_id(unsigned long x)
{
unsigned int id;
WARN_ON(preemptible() && num_online_cpus() > 1);
id = x | __this_cpu_read(x2apic_extra_bits);
return id;
}
static unsigned long set_apic_id(unsigned int id)
{
return id;
}
static unsigned int uv_read_apic_id(void)
{
return x2apic_get_apic_id(apic_read(APIC_ID));
}
static int uv_phys_pkg_id(int initial_apicid, int index_msb)
{
return uv_read_apic_id() >> index_msb;
}
static void uv_send_IPI_self(int vector)
{
apic_write(APIC_SELF_IPI, vector);
}
static int uv_probe(void)
{
return apic == &apic_x2apic_uv_x;
}
static void set_x2apic_extra_bits(int pnode)
{
__this_cpu_write(x2apic_extra_bits, pnode << uvh_apicid.s.pnode_shift);
}
static __init void get_lowmem_redirect(unsigned long *base, unsigned long *size)
{
union uvh_rh_gam_alias210_overlay_config_2_mmr_u alias;
union uvh_rh_gam_alias210_redirect_config_2_mmr_u redirect;
unsigned long m_redirect;
unsigned long m_overlay;
int i;
for (i = 0; i < UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_LENGTH; i++) {
switch (i) {
case 0:
m_redirect = UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_0_MMR;
m_overlay = UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_0_MMR;
break;
case 1:
m_redirect = UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_1_MMR;
m_overlay = UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_1_MMR;
break;
case 2:
m_redirect = UVH_RH_GAM_ALIAS210_REDIRECT_CONFIG_2_MMR;
m_overlay = UVH_RH_GAM_ALIAS210_OVERLAY_CONFIG_2_MMR;
break;
}
alias.v = uv_read_local_mmr(m_overlay);
if (alias.s.enable && alias.s.base == 0) {
*size = (1UL << alias.s.m_alias);
redirect.v = uv_read_local_mmr(m_redirect);
*base = (unsigned long)redirect.s.dest_base << DEST_SHIFT;
return;
}
}
*base = *size = 0;
}
static __init void map_high(char *id, unsigned long base, int pshift, int bshift, int max_pnode, enum map_type map_type)
{
unsigned long bytes, paddr;
paddr = base << pshift;
bytes = (1UL << bshift) * (max_pnode + 1);
if (!paddr) {
pr_info("UV: Map %s_HI base address NULL\n", id);
return;
}
pr_debug("UV: Map %s_HI 0x%lx - 0x%lx\n", id, paddr, paddr + bytes);
if (map_type == map_uc)
init_extra_mapping_uc(paddr, bytes);
else
init_extra_mapping_wb(paddr, bytes);
}
static __init void map_gru_distributed(unsigned long c)
{
union uvh_rh_gam_gru_overlay_config_mmr_u gru;
u64 paddr;
unsigned long bytes;
int nid;
gru.v = c;
gru_dist_base = gru.v & 0x000007fff0000000UL;
if (!gru_dist_base) {
pr_info("UV: Map GRU_DIST base address NULL\n");
return;
}
bytes = 1UL << UVH_RH_GAM_GRU_OVERLAY_CONFIG_MMR_BASE_SHFT;
gru_dist_lmask = ((1UL << uv_hub_info->m_val) - 1) & ~(bytes - 1);
gru_dist_umask = ~((1UL << uv_hub_info->m_val) - 1);
gru_dist_base &= gru_dist_lmask;
for_each_online_node(nid) {
paddr = ((u64)uv_node_to_pnode(nid) << uv_hub_info->m_val) |
gru_dist_base;
init_extra_mapping_wb(paddr, bytes);
gru_first_node_paddr = min(paddr, gru_first_node_paddr);
gru_last_node_paddr = max(paddr, gru_last_node_paddr);
}
gru_first_node_paddr &= gru_dist_umask;
gru_last_node_paddr &= gru_dist_umask;
pr_debug("UV: Map GRU_DIST base 0x%016llx 0x%016llx - 0x%016llx\n", gru_dist_base, gru_first_node_paddr, gru_last_node_paddr);
}
static __init void map_gru_high(int max_pnode)
{
union uvh_rh_gam_gru_overlay_config_mmr_u gru;
int shift = UVH_RH_GAM_GRU_OVERLAY_CONFIG_MMR_BASE_SHFT;
unsigned long mask = UVH_RH_GAM_GRU_OVERLAY_CONFIG_MMR_BASE_MASK;
unsigned long base;
gru.v = uv_read_local_mmr(UVH_RH_GAM_GRU_OVERLAY_CONFIG_MMR);
if (!gru.s.enable) {
pr_info("UV: GRU disabled\n");
return;
}
if (is_uv3_hub() && gru.s3.mode) {
map_gru_distributed(gru.v);
return;
}
base = (gru.v & mask) >> shift;
map_high("GRU", base, shift, shift, max_pnode, map_wb);
gru_start_paddr = ((u64)base << shift);
gru_end_paddr = gru_start_paddr + (1UL << shift) * (max_pnode + 1);
}
static __init void map_mmr_high(int max_pnode)
{
union uvh_rh_gam_mmr_overlay_config_mmr_u mmr;
int shift = UVH_RH_GAM_MMR_OVERLAY_CONFIG_MMR_BASE_SHFT;
mmr.v = uv_read_local_mmr(UVH_RH_GAM_MMR_OVERLAY_CONFIG_MMR);
if (mmr.s.enable)
map_high("MMR", mmr.s.base, shift, shift, max_pnode, map_uc);
else
pr_info("UV: MMR disabled\n");
}
static __init void map_mmioh_high_uv3(int index, int min_pnode, int max_pnode)
{
union uv3h_rh_gam_mmioh_overlay_config0_mmr_u overlay;
unsigned long mmr;
unsigned long base;
int i, n, shift, m_io, max_io;
int nasid, lnasid, fi, li;
char *id;
id = mmiohs[index].id;
overlay.v = uv_read_local_mmr(mmiohs[index].overlay);
pr_info("UV: %s overlay 0x%lx base:0x%x m_io:%d\n", id, overlay.v, overlay.s3.base, overlay.s3.m_io);
if (!overlay.s3.enable) {
pr_info("UV: %s disabled\n", id);
return;
}
shift = UV3H_RH_GAM_MMIOH_OVERLAY_CONFIG0_MMR_BASE_SHFT;
base = (unsigned long)overlay.s3.base;
m_io = overlay.s3.m_io;
mmr = mmiohs[index].redirect;
n = UV3H_RH_GAM_MMIOH_REDIRECT_CONFIG0_MMR_DEPTH;
min_pnode *= 2;
max_pnode *= 2;
max_io = lnasid = fi = li = -1;
for (i = 0; i < n; i++) {
union uv3h_rh_gam_mmioh_redirect_config0_mmr_u redirect;
redirect.v = uv_read_local_mmr(mmr + i * 8);
nasid = redirect.s3.nasid;
if (nasid < min_pnode || max_pnode < nasid)
nasid = -1;
if (nasid == lnasid) {
li = i;
if (i != n-1)
continue;
}
if (lnasid != -1 || (i == n-1 && nasid != -1)) {
unsigned long addr1, addr2;
int f, l;
if (lnasid == -1) {
f = l = i;
lnasid = nasid;
} else {
f = fi;
l = li;
}
addr1 = (base << shift) + f * (1ULL << m_io);
addr2 = (base << shift) + (l + 1) * (1ULL << m_io);
pr_info("UV: %s[%03d..%03d] NASID 0x%04x ADDR 0x%016lx - 0x%016lx\n", id, fi, li, lnasid, addr1, addr2);
if (max_io < l)
max_io = l;
}
fi = li = i;
lnasid = nasid;
}
pr_info("UV: %s base:0x%lx shift:%d M_IO:%d MAX_IO:%d\n", id, base, shift, m_io, max_io);
if (max_io >= 0)
map_high(id, base, shift, m_io, max_io, map_uc);
}
static __init void map_mmioh_high(int min_pnode, int max_pnode)
{
union uvh_rh_gam_mmioh_overlay_config_mmr_u mmioh;
unsigned long mmr, base;
int shift, enable, m_io, n_io;
if (is_uv3_hub() || is_uv4_hub()) {
map_mmioh_high_uv3(0, min_pnode, max_pnode);
map_mmioh_high_uv3(1, min_pnode, max_pnode);
return;
}
if (is_uv1_hub()) {
mmr = UV1H_RH_GAM_MMIOH_OVERLAY_CONFIG_MMR;
shift = UV1H_RH_GAM_MMIOH_OVERLAY_CONFIG_MMR_BASE_SHFT;
mmioh.v = uv_read_local_mmr(mmr);
enable = !!mmioh.s1.enable;
base = mmioh.s1.base;
m_io = mmioh.s1.m_io;
n_io = mmioh.s1.n_io;
} else if (is_uv2_hub()) {
mmr = UV2H_RH_GAM_MMIOH_OVERLAY_CONFIG_MMR;
shift = UV2H_RH_GAM_MMIOH_OVERLAY_CONFIG_MMR_BASE_SHFT;
mmioh.v = uv_read_local_mmr(mmr);
enable = !!mmioh.s2.enable;
base = mmioh.s2.base;
m_io = mmioh.s2.m_io;
n_io = mmioh.s2.n_io;
} else {
return;
}
if (enable) {
max_pnode &= (1 << n_io) - 1;
pr_info("UV: base:0x%lx shift:%d N_IO:%d M_IO:%d max_pnode:0x%x\n", base, shift, m_io, n_io, max_pnode);
map_high("MMIOH", base, shift, m_io, max_pnode, map_uc);
} else {
pr_info("UV: MMIOH disabled\n");
}
}
static __init void map_low_mmrs(void)
{
init_extra_mapping_uc(UV_GLOBAL_MMR32_BASE, UV_GLOBAL_MMR32_SIZE);
init_extra_mapping_uc(UV_LOCAL_MMR_BASE, UV_LOCAL_MMR_SIZE);
}
static __init void uv_rtc_init(void)
{
long status;
u64 ticks_per_sec;
status = uv_bios_freq_base(BIOS_FREQ_BASE_REALTIME_CLOCK, &ticks_per_sec);
if (status != BIOS_STATUS_SUCCESS || ticks_per_sec < 100000) {
pr_warn("UV: unable to determine platform RTC clock frequency, guessing.\n");
sn_rtc_cycles_per_second = 1000000000000UL / 30000UL;
} else {
sn_rtc_cycles_per_second = ticks_per_sec;
}
}
static void uv_heartbeat(unsigned long ignored)
{
struct timer_list *timer = &uv_scir_info->timer;
unsigned char bits = uv_scir_info->state;
bits ^= SCIR_CPU_HEARTBEAT;
if (idle_cpu(raw_smp_processor_id()))
bits &= ~SCIR_CPU_ACTIVITY;
else
bits |= SCIR_CPU_ACTIVITY;
uv_set_scir_bits(bits);
mod_timer(timer, jiffies + SCIR_CPU_HB_INTERVAL);
}
static int uv_heartbeat_enable(unsigned int cpu)
{
while (!uv_cpu_scir_info(cpu)->enabled) {
struct timer_list *timer = &uv_cpu_scir_info(cpu)->timer;
uv_set_cpu_scir_bits(cpu, SCIR_CPU_HEARTBEAT|SCIR_CPU_ACTIVITY);
setup_pinned_timer(timer, uv_heartbeat, cpu);
timer->expires = jiffies + SCIR_CPU_HB_INTERVAL;
add_timer_on(timer, cpu);
uv_cpu_scir_info(cpu)->enabled = 1;
cpu = 0;
}
return 0;
}
static int uv_heartbeat_disable(unsigned int cpu)
{
if (uv_cpu_scir_info(cpu)->enabled) {
uv_cpu_scir_info(cpu)->enabled = 0;
del_timer(&uv_cpu_scir_info(cpu)->timer);
}
uv_set_cpu_scir_bits(cpu, 0xff);
return 0;
}
static __init void uv_scir_register_cpu_notifier(void)
{
cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN, "x86/x2apic-uvx:online",
uv_heartbeat_enable, uv_heartbeat_disable);
}
static __init void uv_scir_register_cpu_notifier(void)
{
}
static __init int uv_init_heartbeat(void)
{
int cpu;
if (is_uv_system()) {
for_each_online_cpu(cpu)
uv_heartbeat_enable(cpu);
}
return 0;
}
int uv_set_vga_state(struct pci_dev *pdev, bool decode, unsigned int command_bits, u32 flags)
{
int domain, bus, rc;
if (!(flags & PCI_VGA_STATE_CHANGE_BRIDGE))
return 0;
if ((command_bits & PCI_COMMAND_IO) == 0)
return 0;
domain = pci_domain_nr(pdev->bus);
bus = pdev->bus->number;
rc = uv_bios_set_legacy_vga_target(decode, domain, bus);
return rc;
}
void uv_cpu_init(void)
{
if (smp_processor_id() == 0)
return;
uv_hub_info->nr_online_cpus++;
if (get_uv_system_type() == UV_NON_UNIQUE_APIC)
set_x2apic_extra_bits(uv_hub_info->pnode);
}
static void get_mn(struct mn *mnp)
{
union uvh_rh_gam_config_mmr_u m_n_config;
union uv3h_gr0_gam_gr_config_u m_gr_config;
memset(mnp, 0, sizeof(*mnp));
m_n_config.v = uv_read_local_mmr(UVH_RH_GAM_CONFIG_MMR);
mnp->n_val = m_n_config.s.n_skt;
if (is_uv4_hub()) {
mnp->m_val = 0;
mnp->n_lshift = 0;
} else if (is_uv3_hub()) {
mnp->m_val = m_n_config.s3.m_skt;
m_gr_config.v = uv_read_local_mmr(UV3H_GR0_GAM_GR_CONFIG);
mnp->n_lshift = m_gr_config.s3.m_skt;
} else if (is_uv2_hub()) {
mnp->m_val = m_n_config.s2.m_skt;
mnp->n_lshift = mnp->m_val == 40 ? 40 : 39;
} else if (is_uv1_hub()) {
mnp->m_val = m_n_config.s1.m_skt;
mnp->n_lshift = mnp->m_val;
}
mnp->m_shift = mnp->m_val ? 64 - mnp->m_val : 0;
}
void __init uv_init_hub_info(struct uv_hub_info_s *hi)
{
union uvh_node_id_u node_id;
struct mn mn;
get_mn(&mn);
hi->gpa_mask = mn.m_val ?
(1UL << (mn.m_val + mn.n_val)) - 1 :
(1UL << uv_cpuid.gpa_shift) - 1;
hi->m_val = mn.m_val;
hi->n_val = mn.n_val;
hi->m_shift = mn.m_shift;
hi->n_lshift = mn.n_lshift ? mn.n_lshift : 0;
hi->hub_revision = uv_hub_info->hub_revision;
hi->pnode_mask = uv_cpuid.pnode_mask;
hi->min_pnode = _min_pnode;
hi->min_socket = _min_socket;
hi->pnode_to_socket = _pnode_to_socket;
hi->socket_to_node = _socket_to_node;
hi->socket_to_pnode = _socket_to_pnode;
hi->gr_table_len = _gr_table_len;
hi->gr_table = _gr_table;
node_id.v = uv_read_local_mmr(UVH_NODE_ID);
uv_cpuid.gnode_shift = max_t(unsigned int, uv_cpuid.gnode_shift, mn.n_val);
hi->gnode_extra = (node_id.s.node_id & ~((1 << uv_cpuid.gnode_shift) - 1)) >> 1;
if (mn.m_val)
hi->gnode_upper = (u64)hi->gnode_extra << mn.m_val;
if (uv_gp_table) {
hi->global_mmr_base = uv_gp_table->mmr_base;
hi->global_mmr_shift = uv_gp_table->mmr_shift;
hi->global_gru_base = uv_gp_table->gru_base;
hi->global_gru_shift = uv_gp_table->gru_shift;
hi->gpa_shift = uv_gp_table->gpa_shift;
hi->gpa_mask = (1UL << hi->gpa_shift) - 1;
} else {
hi->global_mmr_base = uv_read_local_mmr(UVH_RH_GAM_MMR_OVERLAY_CONFIG_MMR) & ~UV_MMR_ENABLE;
hi->global_mmr_shift = _UV_GLOBAL_MMR64_PNODE_SHIFT;
}
get_lowmem_redirect(&hi->lowmem_remap_base, &hi->lowmem_remap_top);
hi->apic_pnode_shift = uv_cpuid.socketid_shift;
pr_info("UV: N:%d M:%d m_shift:%d n_lshift:%d\n", hi->n_val, hi->m_val, hi->m_shift, hi->n_lshift);
pr_info("UV: gpa_mask/shift:0x%lx/%d pnode_mask:0x%x apic_pns:%d\n", hi->gpa_mask, hi->gpa_shift, hi->pnode_mask, hi->apic_pnode_shift);
pr_info("UV: mmr_base/shift:0x%lx/%ld gru_base/shift:0x%lx/%ld\n", hi->global_mmr_base, hi->global_mmr_shift, hi->global_gru_base, hi->global_gru_shift);
pr_info("UV: gnode_upper:0x%lx gnode_extra:0x%x\n", hi->gnode_upper, hi->gnode_extra);
}
static void __init decode_gam_params(unsigned long ptr)
{
uv_gp_table = (struct uv_gam_parameters *)ptr;
pr_info("UV: GAM Params...\n");
pr_info("UV: mmr_base/shift:0x%llx/%d gru_base/shift:0x%llx/%d gpa_shift:%d\n",
uv_gp_table->mmr_base, uv_gp_table->mmr_shift,
uv_gp_table->gru_base, uv_gp_table->gru_shift,
uv_gp_table->gpa_shift);
}
static void __init decode_gam_rng_tbl(unsigned long ptr)
{
struct uv_gam_range_entry *gre = (struct uv_gam_range_entry *)ptr;
unsigned long lgre = 0;
int index = 0;
int sock_min = 999999, pnode_min = 99999;
int sock_max = -1, pnode_max = -1;
uv_gre_table = gre;
for (; gre->type != UV_GAM_RANGE_TYPE_UNUSED; gre++) {
if (!index) {
pr_info("UV: GAM Range Table...\n");
pr_info("UV: # %20s %14s %5s %4s %5s %3s %2s\n", "Range", "", "Size", "Type", "NASID", "SID", "PN");
}
pr_info("UV: %2d: 0x%014lx-0x%014lx %5luG %3d %04x %02x %02x\n",
index++,
(unsigned long)lgre << UV_GAM_RANGE_SHFT,
(unsigned long)gre->limit << UV_GAM_RANGE_SHFT,
((unsigned long)(gre->limit - lgre)) >>
(30 - UV_GAM_RANGE_SHFT),
gre->type, gre->nasid, gre->sockid, gre->pnode);
lgre = gre->limit;
if (sock_min > gre->sockid)
sock_min = gre->sockid;
if (sock_max < gre->sockid)
sock_max = gre->sockid;
if (pnode_min > gre->pnode)
pnode_min = gre->pnode;
if (pnode_max < gre->pnode)
pnode_max = gre->pnode;
}
_min_socket = sock_min;
_max_socket = sock_max;
_min_pnode = pnode_min;
_max_pnode = pnode_max;
_gr_table_len = index;
pr_info("UV: GRT: %d entries, sockets(min:%x,max:%x) pnodes(min:%x,max:%x)\n", index, _min_socket, _max_socket, _min_pnode, _max_pnode);
}
static int __init decode_uv_systab(void)
{
struct uv_systab *st;
int i;
if (uv_hub_info->hub_revision < UV4_HUB_REVISION_BASE)
return 0;
st = uv_systab;
if ((!st) || (st->revision < UV_SYSTAB_VERSION_UV4_LATEST)) {
int rev = st ? st->revision : 0;
pr_err("UV: BIOS UVsystab version(%x) mismatch, expecting(%x)\n", rev, UV_SYSTAB_VERSION_UV4_LATEST);
pr_err("UV: Cannot support UV operations, switching to generic PC\n");
uv_system_type = UV_NONE;
return -EINVAL;
}
for (i = 0; st->entry[i].type != UV_SYSTAB_TYPE_UNUSED; i++) {
unsigned long ptr = st->entry[i].offset;
if (!ptr)
continue;
ptr = ptr + (unsigned long)st;
switch (st->entry[i].type) {
case UV_SYSTAB_TYPE_GAM_PARAMS:
decode_gam_params(ptr);
break;
case UV_SYSTAB_TYPE_GAM_RNG_TBL:
decode_gam_rng_tbl(ptr);
break;
}
}
return 0;
}
static __init void boot_init_possible_blades(struct uv_hub_info_s *hub_info)
{
int i, uv_pb = 0;
pr_info("UV: NODE_PRESENT_DEPTH = %d\n", UVH_NODE_PRESENT_TABLE_DEPTH);
for (i = 0; i < UVH_NODE_PRESENT_TABLE_DEPTH; i++) {
unsigned long np;
np = uv_read_local_mmr(UVH_NODE_PRESENT_TABLE + i * 8);
if (np)
pr_info("UV: NODE_PRESENT(%d) = 0x%016lx\n", i, np);
uv_pb += hweight64(np);
}
if (uv_possible_blades != uv_pb)
uv_possible_blades = uv_pb;
}
static void __init build_socket_tables(void)
{
struct uv_gam_range_entry *gre = uv_gre_table;
int num, nump;
int cpu, i, lnid;
int minsock = _min_socket;
int maxsock = _max_socket;
int minpnode = _min_pnode;
int maxpnode = _max_pnode;
size_t bytes;
if (!gre) {
if (is_uv1_hub() || is_uv2_hub() || is_uv3_hub()) {
pr_info("UV: No UVsystab socket table, ignoring\n");
return;
}
pr_crit("UV: Error: UVsystab address translations not available!\n");
BUG();
}
num = maxsock - minsock + 1;
bytes = num * sizeof(_socket_to_node[0]);
_socket_to_node = kmalloc(bytes, GFP_KERNEL);
_socket_to_pnode = kmalloc(bytes, GFP_KERNEL);
nump = maxpnode - minpnode + 1;
bytes = nump * sizeof(_pnode_to_socket[0]);
_pnode_to_socket = kmalloc(bytes, GFP_KERNEL);
BUG_ON(!_socket_to_node || !_socket_to_pnode || !_pnode_to_socket);
for (i = 0; i < num; i++)
_socket_to_node[i] = _socket_to_pnode[i] = SOCK_EMPTY;
for (i = 0; i < nump; i++)
_pnode_to_socket[i] = SOCK_EMPTY;
pr_info("UV: GAM Building socket/pnode conversion tables\n");
for (; gre->type != UV_GAM_RANGE_TYPE_UNUSED; gre++) {
if (gre->type == UV_GAM_RANGE_TYPE_HOLE)
continue;
i = gre->sockid - minsock;
if (_socket_to_pnode[i] != SOCK_EMPTY)
continue;
_socket_to_pnode[i] = gre->pnode;
i = gre->pnode - minpnode;
_pnode_to_socket[i] = gre->sockid;
pr_info("UV: sid:%02x type:%d nasid:%04x pn:%02x pn2s:%2x\n",
gre->sockid, gre->type, gre->nasid,
_socket_to_pnode[gre->sockid - minsock],
_pnode_to_socket[gre->pnode - minpnode]);
}
lnid = -1;
for_each_present_cpu(cpu) {
int nid = cpu_to_node(cpu);
int apicid, sockid;
if (lnid == nid)
continue;
lnid = nid;
apicid = per_cpu(x86_cpu_to_apicid, cpu);
sockid = apicid >> uv_cpuid.socketid_shift;
_socket_to_node[sockid - minsock] = nid;
pr_info("UV: sid:%02x: apicid:%04x node:%2d\n",
sockid, apicid, nid);
}
bytes = num_possible_nodes() * sizeof(_node_to_pnode[0]);
_node_to_pnode = kmalloc(bytes, GFP_KERNEL);
BUG_ON(!_node_to_pnode);
for (lnid = 0; lnid < num_possible_nodes(); lnid++) {
unsigned short sockid;
for (sockid = minsock; sockid <= maxsock; sockid++) {
if (lnid == _socket_to_node[sockid - minsock]) {
_node_to_pnode[lnid] = _socket_to_pnode[sockid - minsock];
break;
}
}
if (sockid > maxsock) {
pr_err("UV: socket for node %d not found!\n", lnid);
BUG();
}
}
pr_info("UV: Checking socket->node/pnode for identity maps\n");
if (minsock == 0) {
for (i = 0; i < num; i++)
if (_socket_to_node[i] == SOCK_EMPTY || i != _socket_to_node[i])
break;
if (i >= num) {
kfree(_socket_to_node);
_socket_to_node = NULL;
pr_info("UV: 1:1 socket_to_node table removed\n");
}
}
if (minsock == minpnode) {
for (i = 0; i < num; i++)
if (_socket_to_pnode[i] != SOCK_EMPTY &&
_socket_to_pnode[i] != i + minpnode)
break;
if (i >= num) {
kfree(_socket_to_pnode);
_socket_to_pnode = NULL;
pr_info("UV: 1:1 socket_to_pnode table removed\n");
}
}
}
static void __init uv_system_init_hub(void)
{
struct uv_hub_info_s hub_info = {0};
int bytes, cpu, nodeid;
unsigned short min_pnode = 9999, max_pnode = 0;
char *hub = is_uv4_hub() ? "UV400" :
is_uv3_hub() ? "UV300" :
is_uv2_hub() ? "UV2000/3000" :
is_uv1_hub() ? "UV100/1000" : NULL;
if (!hub) {
pr_err("UV: Unknown/unsupported UV hub\n");
return;
}
pr_info("UV: Found %s hub\n", hub);
map_low_mmrs();
uv_bios_init();
if (decode_uv_systab() < 0)
return;
build_socket_tables();
build_uv_gr_table();
uv_init_hub_info(&hub_info);
uv_possible_blades = num_possible_nodes();
if (!_node_to_pnode)
boot_init_possible_blades(&hub_info);
pr_info("UV: Found %d hubs, %d nodes, %d CPUs\n", uv_num_possible_blades(), num_possible_nodes(), num_possible_cpus());
uv_bios_get_sn_info(0, &uv_type, &sn_partition_id, &sn_coherency_id, &sn_region_size, &system_serial_number);
hub_info.coherency_domain_number = sn_coherency_id;
uv_rtc_init();
bytes = sizeof(void *) * uv_num_possible_blades();
__uv_hub_info_list = kzalloc(bytes, GFP_KERNEL);
BUG_ON(!__uv_hub_info_list);
bytes = sizeof(struct uv_hub_info_s);
for_each_node(nodeid) {
struct uv_hub_info_s *new_hub;
if (__uv_hub_info_list[nodeid]) {
pr_err("UV: Node %d UV HUB already initialized!?\n", nodeid);
BUG();
}
new_hub = (nodeid == 0) ? &uv_hub_info_node0 : kzalloc_node(bytes, GFP_KERNEL, nodeid);
BUG_ON(!new_hub);
__uv_hub_info_list[nodeid] = new_hub;
new_hub = uv_hub_info_list(nodeid);
BUG_ON(!new_hub);
*new_hub = hub_info;
if (_node_to_pnode)
new_hub->pnode = _node_to_pnode[nodeid];
else
new_hub->pnode = 0xffff;
new_hub->numa_blade_id = uv_node_to_blade_id(nodeid);
new_hub->memory_nid = -1;
new_hub->nr_possible_cpus = 0;
new_hub->nr_online_cpus = 0;
}
for_each_possible_cpu(cpu) {
int apicid = per_cpu(x86_cpu_to_apicid, cpu);
int numa_node_id;
unsigned short pnode;
nodeid = cpu_to_node(cpu);
numa_node_id = numa_cpu_node(cpu);
pnode = uv_apicid_to_pnode(apicid);
uv_cpu_info_per(cpu)->p_uv_hub_info = uv_hub_info_list(nodeid);
uv_cpu_info_per(cpu)->blade_cpu_id = uv_cpu_hub_info(cpu)->nr_possible_cpus++;
if (uv_cpu_hub_info(cpu)->memory_nid == -1)
uv_cpu_hub_info(cpu)->memory_nid = cpu_to_node(cpu);
if (nodeid != numa_node_id &&
uv_hub_info_list(numa_node_id)->pnode == 0xffff)
uv_hub_info_list(numa_node_id)->pnode = pnode;
else if (uv_cpu_hub_info(cpu)->pnode == 0xffff)
uv_cpu_hub_info(cpu)->pnode = pnode;
uv_cpu_scir_info(cpu)->offset = uv_scir_offset(apicid);
}
for_each_node(nodeid) {
unsigned short pnode = uv_hub_info_list(nodeid)->pnode;
if (pnode == 0xffff) {
unsigned long paddr;
paddr = node_start_pfn(nodeid) << PAGE_SHIFT;
pnode = uv_gpa_to_pnode(uv_soc_phys_ram_to_gpa(paddr));
uv_hub_info_list(nodeid)->pnode = pnode;
}
min_pnode = min(pnode, min_pnode);
max_pnode = max(pnode, max_pnode);
pr_info("UV: UVHUB node:%2d pn:%02x nrcpus:%d\n",
nodeid,
uv_hub_info_list(nodeid)->pnode,
uv_hub_info_list(nodeid)->nr_possible_cpus);
}
pr_info("UV: min_pnode:%02x max_pnode:%02x\n", min_pnode, max_pnode);
map_gru_high(max_pnode);
map_mmr_high(max_pnode);
map_mmioh_high(min_pnode, max_pnode);
uv_nmi_setup();
uv_cpu_init();
uv_scir_register_cpu_notifier();
proc_mkdir("sgi_uv", NULL);
pci_register_set_vga_state(uv_set_vga_state);
if (is_kdump_kernel())
reboot_type = BOOT_ACPI;
}
void __init uv_system_init(void)
{
if (likely(!is_uv_system() && !is_uv_hubless()))
return;
if (is_uv_system())
uv_system_init_hub();
else
uv_nmi_setup_hubless();
}
