static bool qm_ecir_is_dcp(const struct qm_ecir *p)
{
return p->info & BIT(29);
}
static int qm_ecir_get_pnum(const struct qm_ecir *p)
{
return (p->info >> 24) & 0x1f;
}
static int qm_ecir_get_fqid(const struct qm_ecir *p)
{
return p->info & (BIT(24) - 1);
}
static bool qm_ecir2_is_dcp(const struct qm_ecir2 *p)
{
return p->info & BIT(31);
}
static int qm_ecir2_get_pnum(const struct qm_ecir2 *p)
{
return p->info & (BIT(10) - 1);
}
static int qm_eadr_get_memid(const struct qm_eadr *p)
{
return (p->info >> 24) & 0xf;
}
static int qm_eadr_get_eadr(const struct qm_eadr *p)
{
return p->info & (BIT(12) - 1);
}
static int qm_eadr_v3_get_memid(const struct qm_eadr *p)
{
return (p->info >> 24) & 0x1f;
}
static int qm_eadr_v3_get_eadr(const struct qm_eadr *p)
{
return p->info & (BIT(16) - 1);
}
static inline u32 qm_ccsr_in(u32 offset)
{
return ioread32be(qm_ccsr_start + offset/4);
}
static inline void qm_ccsr_out(u32 offset, u32 val)
{
iowrite32be(val, qm_ccsr_start + offset/4);
}
u32 qm_get_pools_sdqcr(void)
{
return qm_pools_sdqcr;
}
static void qm_set_dc(enum qm_dc_portal portal, int ed, u8 sernd)
{
DPAA_ASSERT(!ed || portal == qm_dc_portal_fman0 ||
portal == qm_dc_portal_fman1);
if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
qm_ccsr_out(REG_DCP_CFG(portal),
(ed ? 0x1000 : 0) | (sernd & 0x3ff));
else
qm_ccsr_out(REG_DCP_CFG(portal),
(ed ? 0x100 : 0) | (sernd & 0x1f));
}
static void qm_set_wq_scheduling(enum qm_wq_class wq_class,
u8 cs_elev, u8 csw2, u8 csw3, u8 csw4,
u8 csw5, u8 csw6, u8 csw7)
{
qm_ccsr_out(REG_WQ_CS_CFG(wq_class), ((cs_elev & 0xff) << 24) |
((csw2 & 0x7) << 20) | ((csw3 & 0x7) << 16) |
((csw4 & 0x7) << 12) | ((csw5 & 0x7) << 8) |
((csw6 & 0x7) << 4) | (csw7 & 0x7));
}
static void qm_set_hid(void)
{
qm_ccsr_out(REG_HID_CFG, 0);
}
static void qm_set_corenet_initiator(void)
{
qm_ccsr_out(REG_CI_SCHED_CFG, QM_CI_SCHED_CFG_SRCCIV_EN |
(QM_CI_SCHED_CFG_SRCCIV << 24) |
(QM_CI_SCHED_CFG_SRQ_W << 8) |
(QM_CI_SCHED_CFG_RW_W << 4) |
QM_CI_SCHED_CFG_BMAN_W);
}
static void qm_get_version(u16 *id, u8 *major, u8 *minor)
{
u32 v = qm_ccsr_in(REG_IP_REV_1);
*id = (v >> 16);
*major = (v >> 8) & 0xff;
*minor = v & 0xff;
}
static void qm_set_memory(enum qm_memory memory, u64 ba, u32 size)
{
u32 offset = (memory == qm_memory_fqd) ? REG_FQD_BARE : REG_PFDR_BARE;
u32 exp = ilog2(size);
DPAA_ASSERT((size >= 4096) && (size <= 1024*1024*1024) &&
is_power_of_2(size));
DPAA_ASSERT(!(ba & (size - 1)));
qm_ccsr_out(offset, upper_32_bits(ba));
qm_ccsr_out(offset + REG_offset_BAR, lower_32_bits(ba));
qm_ccsr_out(offset + REG_offset_AR, PFDR_AR_EN | (exp - 1));
}
static void qm_set_pfdr_threshold(u32 th, u8 k)
{
qm_ccsr_out(REG_PFDR_FP_LWIT, th & 0xffffff);
qm_ccsr_out(REG_PFDR_CFG, k);
}
static void qm_set_sfdr_threshold(u16 th)
{
qm_ccsr_out(REG_SFDR_CFG, th & 0x3ff);
}
static int qm_init_pfdr(struct device *dev, u32 pfdr_start, u32 num)
{
u8 rslt = MCR_get_rslt(qm_ccsr_in(REG_MCR));
DPAA_ASSERT(pfdr_start && !(pfdr_start & 7) && !(num & 7) && num);
if (!MCR_rslt_idle(rslt)) {
dev_crit(dev, "QMAN_MCR isn't idle");
WARN_ON(1);
}
qm_ccsr_out(REG_MCP(0), pfdr_start);
qm_ccsr_out(REG_MCP(1), pfdr_start + num - 16);
dma_wmb();
qm_ccsr_out(REG_MCR, MCR_INIT_PFDR);
do {
rslt = MCR_get_rslt(qm_ccsr_in(REG_MCR));
} while (!MCR_rslt_idle(rslt));
if (MCR_rslt_ok(rslt))
return 0;
if (MCR_rslt_eaccess(rslt))
return -EACCES;
if (MCR_rslt_inval(rslt))
return -EINVAL;
dev_crit(dev, "Unexpected result from MCR_INIT_PFDR: %02x\n", rslt);
return -ENODEV;
}
static int qman_fqd(struct reserved_mem *rmem)
{
fqd_a = rmem->base;
fqd_sz = rmem->size;
WARN_ON(!(fqd_a && fqd_sz));
return 0;
}
static int qman_pfdr(struct reserved_mem *rmem)
{
pfdr_a = rmem->base;
pfdr_sz = rmem->size;
WARN_ON(!(pfdr_a && pfdr_sz));
return 0;
}
static unsigned int qm_get_fqid_maxcnt(void)
{
return fqd_sz / 64;
}
static int zero_priv_mem(struct device *dev, struct device_node *node,
phys_addr_t addr, size_t sz)
{
void __iomem *tmpp = ioremap_prot(addr, sz, 0);
if (!tmpp)
return -ENOMEM;
memset_io(tmpp, 0, sz);
flush_dcache_range((unsigned long)tmpp,
(unsigned long)tmpp + sz);
iounmap(tmpp);
return 0;
}
static void log_edata_bits(struct device *dev, u32 bit_count)
{
u32 i, j, mask = 0xffffffff;
dev_warn(dev, "ErrInt, EDATA:\n");
i = bit_count / 32;
if (bit_count % 32) {
i++;
mask = ~(mask << bit_count % 32);
}
j = 16 - i;
dev_warn(dev, " 0x%08x\n", qm_ccsr_in(REG_EDATA(j)) & mask);
j++;
for (; j < 16; j++)
dev_warn(dev, " 0x%08x\n", qm_ccsr_in(REG_EDATA(j)));
}
static void log_additional_error_info(struct device *dev, u32 isr_val,
u32 ecsr_val)
{
struct qm_ecir ecir_val;
struct qm_eadr eadr_val;
int memid;
ecir_val.info = qm_ccsr_in(REG_ECIR);
if ((qman_ip_rev & 0xFF00) >= QMAN_REV30) {
struct qm_ecir2 ecir2_val;
ecir2_val.info = qm_ccsr_in(REG_ECIR2);
if (ecsr_val & PORTAL_ECSR_ERR) {
dev_warn(dev, "ErrInt: %s id %d\n",
qm_ecir2_is_dcp(&ecir2_val) ? "DCP" : "SWP",
qm_ecir2_get_pnum(&ecir2_val));
}
if (ecsr_val & (FQID_ECSR_ERR | QM_EIRQ_IECE))
dev_warn(dev, "ErrInt: ecir.fqid 0x%x\n",
qm_ecir_get_fqid(&ecir_val));
if (ecsr_val & (QM_EIRQ_SBEI|QM_EIRQ_MBEI)) {
eadr_val.info = qm_ccsr_in(REG_EADR);
memid = qm_eadr_v3_get_memid(&eadr_val);
dev_warn(dev, "ErrInt: EADR Memory: %s, 0x%x\n",
error_mdata[memid].txt,
error_mdata[memid].addr_mask
& qm_eadr_v3_get_eadr(&eadr_val));
log_edata_bits(dev, error_mdata[memid].bits);
}
} else {
if (ecsr_val & PORTAL_ECSR_ERR) {
dev_warn(dev, "ErrInt: %s id %d\n",
qm_ecir_is_dcp(&ecir_val) ? "DCP" : "SWP",
qm_ecir_get_pnum(&ecir_val));
}
if (ecsr_val & FQID_ECSR_ERR)
dev_warn(dev, "ErrInt: ecir.fqid 0x%x\n",
qm_ecir_get_fqid(&ecir_val));
if (ecsr_val & (QM_EIRQ_SBEI|QM_EIRQ_MBEI)) {
eadr_val.info = qm_ccsr_in(REG_EADR);
memid = qm_eadr_get_memid(&eadr_val);
dev_warn(dev, "ErrInt: EADR Memory: %s, 0x%x\n",
error_mdata[memid].txt,
error_mdata[memid].addr_mask
& qm_eadr_get_eadr(&eadr_val));
log_edata_bits(dev, error_mdata[memid].bits);
}
}
}
static irqreturn_t qman_isr(int irq, void *ptr)
{
u32 isr_val, ier_val, ecsr_val, isr_mask, i;
struct device *dev = ptr;
ier_val = qm_ccsr_in(REG_ERR_IER);
isr_val = qm_ccsr_in(REG_ERR_ISR);
ecsr_val = qm_ccsr_in(REG_ECSR);
isr_mask = isr_val & ier_val;
if (!isr_mask)
return IRQ_NONE;
for (i = 0; i < ARRAY_SIZE(qman_hwerr_txts); i++) {
if (qman_hwerr_txts[i].mask & isr_mask) {
dev_err_ratelimited(dev, "ErrInt: %s\n",
qman_hwerr_txts[i].txt);
if (qman_hwerr_txts[i].mask & ecsr_val) {
log_additional_error_info(dev, isr_mask,
ecsr_val);
qm_ccsr_out(REG_ECSR, ecsr_val);
}
if (qman_hwerr_txts[i].mask & QMAN_ERRS_TO_DISABLE) {
dev_dbg(dev, "Disabling error 0x%x\n",
qman_hwerr_txts[i].mask);
ier_val &= ~qman_hwerr_txts[i].mask;
qm_ccsr_out(REG_ERR_IER, ier_val);
}
}
}
qm_ccsr_out(REG_ERR_ISR, isr_val);
return IRQ_HANDLED;
}
static int qman_init_ccsr(struct device *dev)
{
int i, err;
qm_set_memory(qm_memory_fqd, fqd_a, fqd_sz);
qm_set_memory(qm_memory_pfdr, pfdr_a, pfdr_sz);
err = qm_init_pfdr(dev, 8, pfdr_sz / 64 - 8);
if (err)
return err;
qm_set_pfdr_threshold(512, 64);
qm_set_sfdr_threshold(128);
qm_ccsr_out(REG_ERR_ISR, QM_EIRQ_PEBI);
qm_set_corenet_initiator();
qm_set_hid();
for (i = qm_wq_first; i <= qm_wq_last; i++)
qm_set_wq_scheduling(i, 0, 0, 0, 0, 0, 0, 0);
qm_set_dc(qm_dc_portal_fman0, 1, 0);
qm_set_dc(qm_dc_portal_fman1, 1, 0);
return 0;
}
void qman_liodn_fixup(u16 channel)
{
static int done;
static u32 liodn_offset;
u32 before, after;
int idx = channel - QM_CHANNEL_SWPORTAL0;
if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
before = qm_ccsr_in(REG_REV3_QCSP_LIO_CFG(idx));
else
before = qm_ccsr_in(REG_QCSP_LIO_CFG(idx));
if (!done) {
liodn_offset = before & LIO_CFG_LIODN_MASK;
done = 1;
return;
}
after = (before & (~LIO_CFG_LIODN_MASK)) | liodn_offset;
if ((qman_ip_rev & 0xFF00) >= QMAN_REV30)
qm_ccsr_out(REG_REV3_QCSP_LIO_CFG(idx), after);
else
qm_ccsr_out(REG_QCSP_LIO_CFG(idx), after);
}
void qman_set_sdest(u16 channel, unsigned int cpu_idx)
{
int idx = channel - QM_CHANNEL_SWPORTAL0;
u32 before, after;
if ((qman_ip_rev & 0xFF00) >= QMAN_REV30) {
before = qm_ccsr_in(REG_REV3_QCSP_IO_CFG(idx));
cpu_idx /= 2;
after = (before & (~IO_CFG_SDEST_MASK)) | (cpu_idx << 16);
qm_ccsr_out(REG_REV3_QCSP_IO_CFG(idx), after);
} else {
before = qm_ccsr_in(REG_QCSP_IO_CFG(idx));
after = (before & (~IO_CFG_SDEST_MASK)) | (cpu_idx << 16);
qm_ccsr_out(REG_QCSP_IO_CFG(idx), after);
}
}
static int qman_resource_init(struct device *dev)
{
int pool_chan_num, cgrid_num;
int ret, i;
switch (qman_ip_rev >> 8) {
case 1:
pool_chan_num = 15;
cgrid_num = 256;
break;
case 2:
pool_chan_num = 3;
cgrid_num = 64;
break;
case 3:
pool_chan_num = 15;
cgrid_num = 256;
break;
default:
return -ENODEV;
}
ret = gen_pool_add(qm_qpalloc, qm_channel_pool1 | DPAA_GENALLOC_OFF,
pool_chan_num, -1);
if (ret) {
dev_err(dev, "Failed to seed pool channels (%d)\n", ret);
return ret;
}
ret = gen_pool_add(qm_cgralloc, DPAA_GENALLOC_OFF, cgrid_num, -1);
if (ret) {
dev_err(dev, "Failed to seed CGRID range (%d)\n", ret);
return ret;
}
for (i = 0; i < cgrid_num; i++)
qm_pools_sdqcr |= QM_SDQCR_CHANNELS_POOL_CONV(i);
ret = gen_pool_add(qm_fqalloc, QM_FQID_RANGE_START | DPAA_GENALLOC_OFF,
qm_get_fqid_maxcnt() - QM_FQID_RANGE_START, -1);
if (ret) {
dev_err(dev, "Failed to seed FQID range (%d)\n", ret);
return ret;
}
return 0;
}
static int fsl_qman_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
int ret, err_irq;
u16 id;
u8 major, minor;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "Can't get %s property 'IORESOURCE_MEM'\n",
node->full_name);
return -ENXIO;
}
qm_ccsr_start = devm_ioremap(dev, res->start, resource_size(res));
if (!qm_ccsr_start)
return -ENXIO;
qm_get_version(&id, &major, &minor);
if (major == 1 && minor == 0) {
dev_err(dev, "Rev1.0 on P4080 rev1 is not supported!\n");
return -ENODEV;
} else if (major == 1 && minor == 1)
qman_ip_rev = QMAN_REV11;
else if (major == 1 && minor == 2)
qman_ip_rev = QMAN_REV12;
else if (major == 2 && minor == 0)
qman_ip_rev = QMAN_REV20;
else if (major == 3 && minor == 0)
qman_ip_rev = QMAN_REV30;
else if (major == 3 && minor == 1)
qman_ip_rev = QMAN_REV31;
else {
dev_err(dev, "Unknown QMan version\n");
return -ENODEV;
}
if ((qman_ip_rev & 0xff00) >= QMAN_REV30)
qm_channel_pool1 = QMAN_CHANNEL_POOL1_REV3;
ret = zero_priv_mem(dev, node, fqd_a, fqd_sz);
WARN_ON(ret);
if (ret)
return -ENODEV;
ret = qman_init_ccsr(dev);
if (ret) {
dev_err(dev, "CCSR setup failed\n");
return ret;
}
err_irq = platform_get_irq(pdev, 0);
if (err_irq <= 0) {
dev_info(dev, "Can't get %s property 'interrupts'\n",
node->full_name);
return -ENODEV;
}
ret = devm_request_irq(dev, err_irq, qman_isr, IRQF_SHARED, "qman-err",
dev);
if (ret) {
dev_err(dev, "devm_request_irq() failed %d for '%s'\n",
ret, node->full_name);
return ret;
}
qm_ccsr_out(REG_ERR_ISR, 0xffffffff);
qm_ccsr_out(REG_ERR_IER, 0xffffffff);
qm_fqalloc = devm_gen_pool_create(dev, 0, -1, "qman-fqalloc");
if (IS_ERR(qm_fqalloc)) {
ret = PTR_ERR(qm_fqalloc);
dev_err(dev, "qman-fqalloc pool init failed (%d)\n", ret);
return ret;
}
qm_qpalloc = devm_gen_pool_create(dev, 0, -1, "qman-qpalloc");
if (IS_ERR(qm_qpalloc)) {
ret = PTR_ERR(qm_qpalloc);
dev_err(dev, "qman-qpalloc pool init failed (%d)\n", ret);
return ret;
}
qm_cgralloc = devm_gen_pool_create(dev, 0, -1, "qman-cgralloc");
if (IS_ERR(qm_cgralloc)) {
ret = PTR_ERR(qm_cgralloc);
dev_err(dev, "qman-cgralloc pool init failed (%d)\n", ret);
return ret;
}
ret = qman_resource_init(dev);
if (ret)
return ret;
ret = qman_alloc_fq_table(qm_get_fqid_maxcnt());
if (ret)
return ret;
ret = qman_wq_alloc();
if (ret)
return ret;
return 0;
}
