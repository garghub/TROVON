u32 pamu_get_max_subwin_cnt(void)
{
return max_subwindow_count;
}
static struct paace *pamu_get_ppaace(int liodn)
{
if (!ppaact || liodn >= PAACE_NUMBER_ENTRIES) {
pr_debug("PPAACT doesn't exist\n");
return NULL;
}
return &ppaact[liodn];
}
int pamu_enable_liodn(int liodn)
{
struct paace *ppaace;
ppaace = pamu_get_ppaace(liodn);
if (!ppaace) {
pr_debug("Invalid primary paace entry\n");
return -ENOENT;
}
if (!get_bf(ppaace->addr_bitfields, PPAACE_AF_WSE)) {
pr_debug("liodn %d not configured\n", liodn);
return -EINVAL;
}
mb();
set_bf(ppaace->addr_bitfields, PAACE_AF_V, PAACE_V_VALID);
mb();
return 0;
}
int pamu_disable_liodn(int liodn)
{
struct paace *ppaace;
ppaace = pamu_get_ppaace(liodn);
if (!ppaace) {
pr_debug("Invalid primary paace entry\n");
return -ENOENT;
}
set_bf(ppaace->addr_bitfields, PAACE_AF_V, PAACE_V_INVALID);
mb();
return 0;
}
static unsigned int map_addrspace_size_to_wse(phys_addr_t addrspace_size)
{
BUG_ON(addrspace_size & (addrspace_size - 1));
return fls64(addrspace_size) - 2;
}
static unsigned int map_subwindow_cnt_to_wce(u32 subwindow_cnt)
{
return __ffs(subwindow_cnt) - 1;
}
static void pamu_init_ppaace(struct paace *ppaace)
{
set_bf(ppaace->addr_bitfields, PAACE_AF_PT, PAACE_PT_PRIMARY);
set_bf(ppaace->domain_attr.to_host.coherency_required, PAACE_DA_HOST_CR,
PAACE_M_COHERENCE_REQ);
}
static void pamu_init_spaace(struct paace *spaace)
{
set_bf(spaace->addr_bitfields, PAACE_AF_PT, PAACE_PT_SECONDARY);
set_bf(spaace->domain_attr.to_host.coherency_required, PAACE_DA_HOST_CR,
PAACE_M_COHERENCE_REQ);
}
static struct paace *pamu_get_spaace(struct paace *paace, u32 wnum)
{
u32 subwin_cnt;
struct paace *spaace = NULL;
subwin_cnt = 1UL << (get_bf(paace->impl_attr, PAACE_IA_WCE) + 1);
if (wnum < subwin_cnt)
spaace = &spaact[paace->fspi + wnum];
else
pr_debug("secondary paace out of bounds\n");
return spaace;
}
static unsigned long pamu_get_fspi_and_allocate(u32 subwin_cnt)
{
unsigned long spaace_addr;
spaace_addr = gen_pool_alloc(spaace_pool, subwin_cnt * sizeof(struct paace));
if (!spaace_addr)
return ULONG_MAX;
return (spaace_addr - (unsigned long)spaact) / (sizeof(struct paace));
}
void pamu_free_subwins(int liodn)
{
struct paace *ppaace;
u32 subwin_cnt, size;
ppaace = pamu_get_ppaace(liodn);
if (!ppaace) {
pr_debug("Invalid liodn entry\n");
return;
}
if (get_bf(ppaace->addr_bitfields, PPAACE_AF_MW)) {
subwin_cnt = 1UL << (get_bf(ppaace->impl_attr, PAACE_IA_WCE) + 1);
size = (subwin_cnt - 1) * sizeof(struct paace);
gen_pool_free(spaace_pool, (unsigned long)&spaact[ppaace->fspi], size);
set_bf(ppaace->addr_bitfields, PPAACE_AF_MW, 0);
}
}
int pamu_update_paace_stash(int liodn, u32 subwin, u32 value)
{
struct paace *paace;
paace = pamu_get_ppaace(liodn);
if (!paace) {
pr_debug("Invalid liodn entry\n");
return -ENOENT;
}
if (subwin) {
paace = pamu_get_spaace(paace, subwin - 1);
if (!paace)
return -ENOENT;
}
set_bf(paace->impl_attr, PAACE_IA_CID, value);
mb();
return 0;
}
int pamu_disable_spaace(int liodn, u32 subwin)
{
struct paace *paace;
paace = pamu_get_ppaace(liodn);
if (!paace) {
pr_debug("Invalid liodn entry\n");
return -ENOENT;
}
if (subwin) {
paace = pamu_get_spaace(paace, subwin - 1);
if (!paace)
return -ENOENT;
set_bf(paace->addr_bitfields, PAACE_AF_V, PAACE_V_INVALID);
} else {
set_bf(paace->addr_bitfields, PAACE_AF_AP,
PAACE_AP_PERMS_DENIED);
}
mb();
return 0;
}
int pamu_config_ppaace(int liodn, phys_addr_t win_addr, phys_addr_t win_size,
u32 omi, unsigned long rpn, u32 snoopid, u32 stashid,
u32 subwin_cnt, int prot)
{
struct paace *ppaace;
unsigned long fspi;
if ((win_size & (win_size - 1)) || win_size < PAMU_PAGE_SIZE) {
pr_debug("window size too small or not a power of two %pa\n",
&win_size);
return -EINVAL;
}
if (win_addr & (win_size - 1)) {
pr_debug("window address is not aligned with window size\n");
return -EINVAL;
}
ppaace = pamu_get_ppaace(liodn);
if (!ppaace)
return -ENOENT;
set_bf(ppaace->addr_bitfields, PPAACE_AF_WSE,
map_addrspace_size_to_wse(win_size));
pamu_init_ppaace(ppaace);
ppaace->wbah = win_addr >> (PAMU_PAGE_SHIFT + 20);
set_bf(ppaace->addr_bitfields, PPAACE_AF_WBAL,
(win_addr >> PAMU_PAGE_SHIFT));
if (omi < OME_NUMBER_ENTRIES) {
set_bf(ppaace->impl_attr, PAACE_IA_OTM, PAACE_OTM_INDEXED);
ppaace->op_encode.index_ot.omi = omi;
} else if (~omi != 0) {
pr_debug("bad operation mapping index: %d\n", omi);
return -EINVAL;
}
if (~stashid != 0)
set_bf(ppaace->impl_attr, PAACE_IA_CID, stashid);
if (~snoopid != 0)
ppaace->domain_attr.to_host.snpid = snoopid;
if (subwin_cnt) {
fspi = pamu_get_fspi_and_allocate(subwin_cnt - 1);
if (fspi == ULONG_MAX) {
pr_debug("spaace indexes exhausted\n");
return -EINVAL;
}
set_bf(ppaace->impl_attr, PAACE_IA_WCE,
map_subwindow_cnt_to_wce(subwin_cnt));
set_bf(ppaace->addr_bitfields, PPAACE_AF_MW, 0x1);
ppaace->fspi = fspi;
} else {
set_bf(ppaace->impl_attr, PAACE_IA_ATM, PAACE_ATM_WINDOW_XLATE);
ppaace->twbah = rpn >> 20;
set_bf(ppaace->win_bitfields, PAACE_WIN_TWBAL, rpn);
set_bf(ppaace->addr_bitfields, PAACE_AF_AP, prot);
set_bf(ppaace->impl_attr, PAACE_IA_WCE, 0);
set_bf(ppaace->addr_bitfields, PPAACE_AF_MW, 0);
}
mb();
return 0;
}
int pamu_config_spaace(int liodn, u32 subwin_cnt, u32 subwin,
phys_addr_t subwin_size, u32 omi, unsigned long rpn,
u32 snoopid, u32 stashid, int enable, int prot)
{
struct paace *paace;
if (!subwin_cnt) {
pr_debug("Invalid subwindow count\n");
return -EINVAL;
}
paace = pamu_get_ppaace(liodn);
if (subwin > 0 && subwin < subwin_cnt && paace) {
paace = pamu_get_spaace(paace, subwin - 1);
if (paace && !(paace->addr_bitfields & PAACE_V_VALID)) {
pamu_init_spaace(paace);
set_bf(paace->addr_bitfields, SPAACE_AF_LIODN, liodn);
}
}
if (!paace) {
pr_debug("Invalid liodn entry\n");
return -ENOENT;
}
if ((subwin_size & (subwin_size - 1)) || subwin_size < PAMU_PAGE_SIZE) {
pr_debug("subwindow size out of range, or not a power of 2\n");
return -EINVAL;
}
if (rpn == ULONG_MAX) {
pr_debug("real page number out of range\n");
return -EINVAL;
}
set_bf(paace->win_bitfields, PAACE_WIN_SWSE,
map_addrspace_size_to_wse(subwin_size));
set_bf(paace->impl_attr, PAACE_IA_ATM, PAACE_ATM_WINDOW_XLATE);
paace->twbah = rpn >> 20;
set_bf(paace->win_bitfields, PAACE_WIN_TWBAL, rpn);
set_bf(paace->addr_bitfields, PAACE_AF_AP, prot);
if (~snoopid != 0)
paace->domain_attr.to_host.snpid = snoopid;
if (omi < OME_NUMBER_ENTRIES) {
set_bf(paace->impl_attr, PAACE_IA_OTM, PAACE_OTM_INDEXED);
paace->op_encode.index_ot.omi = omi;
} else if (~omi != 0) {
pr_debug("bad operation mapping index: %d\n", omi);
return -EINVAL;
}
if (~stashid != 0)
set_bf(paace->impl_attr, PAACE_IA_CID, stashid);
smp_wmb();
if (enable)
set_bf(paace->addr_bitfields, PAACE_AF_V, PAACE_V_VALID);
mb();
return 0;
}
void get_ome_index(u32 *omi_index, struct device *dev)
{
if (of_device_is_compatible(dev->of_node, "fsl,qman-portal"))
*omi_index = OMI_QMAN;
if (of_device_is_compatible(dev->of_node, "fsl,qman"))
*omi_index = OMI_QMAN_PRIV;
}
u32 get_stash_id(u32 stash_dest_hint, u32 vcpu)
{
const u32 *prop;
struct device_node *node;
u32 cache_level;
int len, found = 0;
int i;
if (stash_dest_hint == PAMU_ATTR_CACHE_L3) {
node = of_find_matching_node(NULL, l3_device_ids);
if (node) {
prop = of_get_property(node, "cache-stash-id", NULL);
if (!prop) {
pr_debug("missing cache-stash-id at %s\n",
node->full_name);
of_node_put(node);
return ~(u32)0;
}
of_node_put(node);
return be32_to_cpup(prop);
}
return ~(u32)0;
}
for_each_node_by_type(node, "cpu") {
prop = of_get_property(node, "reg", &len);
for (i = 0; i < len / sizeof(u32); i++) {
if (be32_to_cpup(&prop[i]) == vcpu) {
found = 1;
goto found_cpu_node;
}
}
}
found_cpu_node:
for (cache_level = PAMU_ATTR_CACHE_L1; (cache_level < PAMU_ATTR_CACHE_L3) && found; cache_level++) {
if (stash_dest_hint == cache_level) {
prop = of_get_property(node, "cache-stash-id", NULL);
if (!prop) {
pr_debug("missing cache-stash-id at %s\n",
node->full_name);
of_node_put(node);
return ~(u32)0;
}
of_node_put(node);
return be32_to_cpup(prop);
}
prop = of_get_property(node, "next-level-cache", NULL);
if (!prop) {
pr_debug("can't find next-level-cache at %s\n",
node->full_name);
of_node_put(node);
return ~(u32)0;
}
of_node_put(node);
node = of_find_node_by_phandle(*prop);
if (!node) {
pr_debug("Invalid node for cache hierarchy\n");
return ~(u32)0;
}
}
pr_debug("stash dest not found for %d on vcpu %d\n",
stash_dest_hint, vcpu);
return ~(u32)0;
}
static void __init setup_qbman_paace(struct paace *ppaace, int paace_type)
{
switch (paace_type) {
case QMAN_PAACE:
set_bf(ppaace->impl_attr, PAACE_IA_OTM, PAACE_OTM_INDEXED);
ppaace->op_encode.index_ot.omi = OMI_QMAN_PRIV;
set_bf(ppaace->impl_attr, PAACE_IA_CID, get_stash_id(PAMU_ATTR_CACHE_L3, 0));
set_bf(ppaace->domain_attr.to_host.coherency_required, PAACE_DA_HOST_CR,
0);
break;
case QMAN_PORTAL_PAACE:
set_bf(ppaace->impl_attr, PAACE_IA_OTM, PAACE_OTM_INDEXED);
ppaace->op_encode.index_ot.omi = OMI_QMAN;
set_bf(ppaace->impl_attr, PAACE_IA_CID, get_stash_id(PAMU_ATTR_CACHE_L3, 0));
break;
case BMAN_PAACE:
set_bf(ppaace->domain_attr.to_host.coherency_required, PAACE_DA_HOST_CR,
0);
break;
}
}
static void __init setup_omt(struct ome *omt)
{
struct ome *ome;
ome = &omt[OMI_QMAN];
ome->moe[IOE_READ_IDX] = EOE_VALID | EOE_READ;
ome->moe[IOE_EREAD0_IDX] = EOE_VALID | EOE_RSA;
ome->moe[IOE_WRITE_IDX] = EOE_VALID | EOE_WRITE;
ome->moe[IOE_EWRITE0_IDX] = EOE_VALID | EOE_WWSAO;
ome->moe[IOE_DIRECT0_IDX] = EOE_VALID | EOE_LDEC;
ome->moe[IOE_DIRECT1_IDX] = EOE_VALID | EOE_LDECPE;
ome = &omt[OMI_FMAN];
ome->moe[IOE_READ_IDX] = EOE_VALID | EOE_READI;
ome->moe[IOE_WRITE_IDX] = EOE_VALID | EOE_WRITE;
ome = &omt[OMI_QMAN_PRIV];
ome->moe[IOE_READ_IDX] = EOE_VALID | EOE_READ;
ome->moe[IOE_WRITE_IDX] = EOE_VALID | EOE_WRITE;
ome->moe[IOE_EREAD0_IDX] = EOE_VALID | EOE_RSA;
ome->moe[IOE_EWRITE0_IDX] = EOE_VALID | EOE_WWSA;
ome = &omt[OMI_CAAM];
ome->moe[IOE_READ_IDX] = EOE_VALID | EOE_READI;
ome->moe[IOE_WRITE_IDX] = EOE_VALID | EOE_WRITE;
}
static void __init get_pamu_cap_values(unsigned long pamu_reg_base)
{
u32 pc_val;
pc_val = in_be32((u32 *)(pamu_reg_base + PAMU_PC3));
max_subwindow_count = 1 << (1 + PAMU_PC3_MWCE(pc_val));
}
static int __init setup_one_pamu(unsigned long pamu_reg_base, unsigned long pamu_reg_size,
phys_addr_t ppaact_phys, phys_addr_t spaact_phys,
phys_addr_t omt_phys)
{
u32 *pc;
struct pamu_mmap_regs *pamu_regs;
pc = (u32 *) (pamu_reg_base + PAMU_PC);
pamu_regs = (struct pamu_mmap_regs *)
(pamu_reg_base + PAMU_MMAP_REGS_BASE);
out_be32(&pamu_regs->ppbah, upper_32_bits(ppaact_phys));
out_be32(&pamu_regs->ppbal, lower_32_bits(ppaact_phys));
ppaact_phys = ppaact_phys + PAACT_SIZE;
out_be32(&pamu_regs->pplah, upper_32_bits(ppaact_phys));
out_be32(&pamu_regs->pplal, lower_32_bits(ppaact_phys));
out_be32(&pamu_regs->spbah, upper_32_bits(spaact_phys));
out_be32(&pamu_regs->spbal, lower_32_bits(spaact_phys));
spaact_phys = spaact_phys + SPAACT_SIZE;
out_be32(&pamu_regs->splah, upper_32_bits(spaact_phys));
out_be32(&pamu_regs->splal, lower_32_bits(spaact_phys));
out_be32(&pamu_regs->obah, upper_32_bits(omt_phys));
out_be32(&pamu_regs->obal, lower_32_bits(omt_phys));
omt_phys = omt_phys + OMT_SIZE;
out_be32(&pamu_regs->olah, upper_32_bits(omt_phys));
out_be32(&pamu_regs->olal, lower_32_bits(omt_phys));
out_be32((u32 *)(pamu_reg_base + PAMU_PICS),
PAMU_ACCESS_VIOLATION_ENABLE);
out_be32(pc, PAMU_PC_PE | PAMU_PC_OCE | PAMU_PC_SPCC | PAMU_PC_PPCC);
return 0;
}
static void __init setup_liodns(void)
{
int i, len;
struct paace *ppaace;
struct device_node *node = NULL;
const u32 *prop;
for_each_node_with_property(node, "fsl,liodn") {
prop = of_get_property(node, "fsl,liodn", &len);
for (i = 0; i < len / sizeof(u32); i++) {
int liodn;
liodn = be32_to_cpup(&prop[i]);
if (liodn >= PAACE_NUMBER_ENTRIES) {
pr_debug("Invalid LIODN value %d\n", liodn);
continue;
}
ppaace = pamu_get_ppaace(liodn);
pamu_init_ppaace(ppaace);
set_bf(ppaace->addr_bitfields, PPAACE_AF_WSE, 35);
ppaace->wbah = 0;
set_bf(ppaace->addr_bitfields, PPAACE_AF_WBAL, 0);
set_bf(ppaace->impl_attr, PAACE_IA_ATM,
PAACE_ATM_NO_XLATE);
set_bf(ppaace->addr_bitfields, PAACE_AF_AP,
PAACE_AP_PERMS_ALL);
if (of_device_is_compatible(node, "fsl,qman-portal"))
setup_qbman_paace(ppaace, QMAN_PORTAL_PAACE);
if (of_device_is_compatible(node, "fsl,qman"))
setup_qbman_paace(ppaace, QMAN_PAACE);
if (of_device_is_compatible(node, "fsl,bman"))
setup_qbman_paace(ppaace, BMAN_PAACE);
mb();
pamu_enable_liodn(liodn);
}
}
}
static irqreturn_t pamu_av_isr(int irq, void *arg)
{
struct pamu_isr_data *data = arg;
phys_addr_t phys;
unsigned int i, j, ret;
pr_emerg("access violation interrupt\n");
for (i = 0; i < data->count; i++) {
void __iomem *p = data->pamu_reg_base + i * PAMU_OFFSET;
u32 pics = in_be32(p + PAMU_PICS);
if (pics & PAMU_ACCESS_VIOLATION_STAT) {
u32 avs1 = in_be32(p + PAMU_AVS1);
struct paace *paace;
pr_emerg("POES1=%08x\n", in_be32(p + PAMU_POES1));
pr_emerg("POES2=%08x\n", in_be32(p + PAMU_POES2));
pr_emerg("AVS1=%08x\n", avs1);
pr_emerg("AVS2=%08x\n", in_be32(p + PAMU_AVS2));
pr_emerg("AVA=%016llx\n",
make64(in_be32(p + PAMU_AVAH),
in_be32(p + PAMU_AVAL)));
pr_emerg("UDAD=%08x\n", in_be32(p + PAMU_UDAD));
pr_emerg("POEA=%016llx\n",
make64(in_be32(p + PAMU_POEAH),
in_be32(p + PAMU_POEAL)));
phys = make64(in_be32(p + PAMU_POEAH),
in_be32(p + PAMU_POEAL));
if (phys) {
u32 *paace = phys_to_virt(phys);
for (j = 0; j < 4; j++)
pr_emerg("PAACE[%u]=%08x\n",
j, in_be32(paace + j));
}
out_be32(p + PAMU_AVS1, avs1 & PAMU_AV_MASK);
paace = pamu_get_ppaace(avs1 >> PAMU_AVS1_LIODN_SHIFT);
BUG_ON(!paace);
if (!get_bf(paace->addr_bitfields, PAACE_AF_V)) {
pics &= ~PAMU_ACCESS_VIOLATION_ENABLE;
} else {
ret = pamu_disable_liodn(avs1 >> PAMU_AVS1_LIODN_SHIFT);
BUG_ON(ret);
pr_emerg("Disabling liodn %x\n",
avs1 >> PAMU_AVS1_LIODN_SHIFT);
}
out_be32((p + PAMU_PICS), pics);
}
}
return IRQ_HANDLED;
}
static int __init create_csd(phys_addr_t phys, size_t size, u32 csd_port_id)
{
struct device_node *np;
const __be32 *iprop;
void __iomem *lac = NULL;
struct ccsr_law __iomem *law;
void __iomem *ccm = NULL;
u32 __iomem *csdids;
unsigned int i, num_laws, num_csds;
u32 law_target = 0;
u32 csd_id = 0;
int ret = 0;
np = of_find_compatible_node(NULL, NULL, "fsl,corenet-law");
if (!np)
return -ENODEV;
iprop = of_get_property(np, "fsl,num-laws", NULL);
if (!iprop) {
ret = -ENODEV;
goto error;
}
num_laws = be32_to_cpup(iprop);
if (!num_laws) {
ret = -ENODEV;
goto error;
}
lac = of_iomap(np, 0);
if (!lac) {
ret = -ENODEV;
goto error;
}
law = lac + 0xC00;
of_node_put(np);
np = of_find_compatible_node(NULL, NULL, "fsl,corenet-cf");
if (!np) {
ret = -ENODEV;
goto error;
}
iprop = of_get_property(np, "fsl,ccf-num-csdids", NULL);
if (!iprop) {
ret = -ENODEV;
goto error;
}
num_csds = be32_to_cpup(iprop);
if (!num_csds) {
ret = -ENODEV;
goto error;
}
ccm = of_iomap(np, 0);
if (!ccm) {
ret = -ENOMEM;
goto error;
}
csdids = ccm + 0x600;
of_node_put(np);
np = NULL;
for (csd_id = 0; csd_id < num_csds; csd_id++) {
if (!csdids[csd_id])
break;
}
csdids[csd_id] = csd_port_id;
for (i = 0; i < num_laws; i++) {
if (law[i].lawar & LAWAR_EN) {
phys_addr_t law_start, law_end;
law_start = make64(law[i].lawbarh, law[i].lawbarl);
law_end = law_start +
(2ULL << (law[i].lawar & LAWAR_SIZE_MASK));
if (law_start <= phys && phys < law_end) {
law_target = law[i].lawar & LAWAR_TARGET_MASK;
break;
}
}
}
if (i == 0 || i == num_laws) {
ret = -ENOENT;
goto error;
}
while (law[--i].lawar & LAWAR_EN) {
if (i == 0) {
ret = -ENOENT;
goto error;
}
}
law[i].lawbarh = upper_32_bits(phys);
law[i].lawbarl = lower_32_bits(phys);
wmb();
law[i].lawar = LAWAR_EN | law_target | (csd_id << LAWAR_CSDID_SHIFT) |
(LAW_SIZE_4K + get_order(size));
wmb();
error:
if (ccm)
iounmap(ccm);
if (lac)
iounmap(lac);
if (np)
of_node_put(np);
return ret;
}
static int __init fsl_pamu_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
void __iomem *pamu_regs = NULL;
struct ccsr_guts __iomem *guts_regs = NULL;
u32 pamubypenr, pamu_counter;
unsigned long pamu_reg_off;
unsigned long pamu_reg_base;
struct pamu_isr_data *data = NULL;
struct device_node *guts_node;
u64 size;
struct page *p;
int ret = 0;
int irq;
phys_addr_t ppaact_phys;
phys_addr_t spaact_phys;
phys_addr_t omt_phys;
size_t mem_size = 0;
unsigned int order = 0;
u32 csd_port_id = 0;
unsigned i;
pamu_regs = of_iomap(dev->of_node, 0);
if (!pamu_regs) {
dev_err(dev, "ioremap of PAMU node failed\n");
return -ENOMEM;
}
of_get_address(dev->of_node, 0, &size, NULL);
irq = irq_of_parse_and_map(dev->of_node, 0);
if (irq == NO_IRQ) {
dev_warn(dev, "no interrupts listed in PAMU node\n");
goto error;
}
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto error;
}
data->pamu_reg_base = pamu_regs;
data->count = size / PAMU_OFFSET;
ret = request_irq(irq, pamu_av_isr, 0, "pamu", data);
if (ret < 0) {
dev_err(dev, "error %i installing ISR for irq %i\n", ret, irq);
goto error;
}
guts_node = of_find_matching_node(NULL, guts_device_ids);
if (!guts_node) {
dev_err(dev, "could not find GUTS node %s\n",
dev->of_node->full_name);
ret = -ENODEV;
goto error;
}
guts_regs = of_iomap(guts_node, 0);
of_node_put(guts_node);
if (!guts_regs) {
dev_err(dev, "ioremap of GUTS node failed\n");
ret = -ENODEV;
goto error;
}
get_pamu_cap_values((unsigned long)pamu_regs);
mem_size = (PAGE_SIZE << get_order(PAACT_SIZE)) +
(PAGE_SIZE << get_order(SPAACT_SIZE)) +
(PAGE_SIZE << get_order(OMT_SIZE));
order = get_order(mem_size);
p = alloc_pages(GFP_KERNEL | __GFP_ZERO, order);
if (!p) {
dev_err(dev, "unable to allocate PAACT/SPAACT/OMT block\n");
ret = -ENOMEM;
goto error;
}
ppaact = page_address(p);
ppaact_phys = page_to_phys(p);
if (ppaact_phys & ((PAGE_SIZE << order) - 1)) {
dev_err(dev, "PAACT/OMT block is unaligned\n");
ret = -ENOMEM;
goto error;
}
spaact = (void *)ppaact + (PAGE_SIZE << get_order(PAACT_SIZE));
omt = (void *)spaact + (PAGE_SIZE << get_order(SPAACT_SIZE));
dev_dbg(dev, "ppaact virt=%p phys=%pa\n", ppaact, &ppaact_phys);
for (i = 0; i < ARRAY_SIZE(port_id_map); i++) {
if (port_id_map[i].svr == (mfspr(SPRN_SVR) & ~SVR_SECURITY)) {
csd_port_id = port_id_map[i].port_id;
dev_dbg(dev, "found matching SVR %08x\n",
port_id_map[i].svr);
break;
}
}
if (csd_port_id) {
dev_dbg(dev, "creating coherency subdomain at address %pa, size %zu, port id 0x%08x",
&ppaact_phys, mem_size, csd_port_id);
ret = create_csd(ppaact_phys, mem_size, csd_port_id);
if (ret) {
dev_err(dev, "could not create coherence subdomain\n");
return ret;
}
}
spaact_phys = virt_to_phys(spaact);
omt_phys = virt_to_phys(omt);
spaace_pool = gen_pool_create(ilog2(sizeof(struct paace)), -1);
if (!spaace_pool) {
ret = -ENOMEM;
dev_err(dev, "Failed to allocate spaace gen pool\n");
goto error;
}
ret = gen_pool_add(spaace_pool, (unsigned long)spaact, SPAACT_SIZE, -1);
if (ret)
goto error_genpool;
pamubypenr = in_be32(&guts_regs->pamubypenr);
for (pamu_reg_off = 0, pamu_counter = 0x80000000; pamu_reg_off < size;
pamu_reg_off += PAMU_OFFSET, pamu_counter >>= 1) {
pamu_reg_base = (unsigned long)pamu_regs + pamu_reg_off;
setup_one_pamu(pamu_reg_base, pamu_reg_off, ppaact_phys,
spaact_phys, omt_phys);
pamubypenr &= ~pamu_counter;
}
setup_omt(omt);
out_be32(&guts_regs->pamubypenr, pamubypenr);
iounmap(guts_regs);
setup_liodns();
return 0;
error_genpool:
gen_pool_destroy(spaace_pool);
error:
if (irq != NO_IRQ)
free_irq(irq, data);
if (data) {
memset(data, 0, sizeof(struct pamu_isr_data));
kfree(data);
}
if (pamu_regs)
iounmap(pamu_regs);
if (guts_regs)
iounmap(guts_regs);
if (ppaact)
free_pages((unsigned long)ppaact, order);
ppaact = NULL;
return ret;
}
static __init int fsl_pamu_init(void)
{
struct platform_device *pdev = NULL;
struct device_node *np;
int ret;
np = of_find_compatible_node(NULL, NULL, "fsl,pamu");
if (!np) {
pr_err("could not find a PAMU node\n");
return -ENODEV;
}
ret = platform_driver_register(&fsl_of_pamu_driver);
if (ret) {
pr_err("could not register driver (err=%i)\n", ret);
goto error_driver_register;
}
pdev = platform_device_alloc("fsl-of-pamu", 0);
if (!pdev) {
pr_err("could not allocate device %s\n",
np->full_name);
ret = -ENOMEM;
goto error_device_alloc;
}
pdev->dev.of_node = of_node_get(np);
ret = pamu_domain_init();
if (ret)
goto error_device_add;
ret = platform_device_add(pdev);
if (ret) {
pr_err("could not add device %s (err=%i)\n",
np->full_name, ret);
goto error_device_add;
}
return 0;
error_device_add:
of_node_put(pdev->dev.of_node);
pdev->dev.of_node = NULL;
platform_device_put(pdev);
error_device_alloc:
platform_driver_unregister(&fsl_of_pamu_driver);
error_driver_register:
of_node_put(np);
return ret;
}
