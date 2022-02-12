static void setup_indirect_dde(struct data_descriptor_entry *dde,
struct data_descriptor_entry *ddl,
unsigned int dde_count, unsigned int byte_count)
{
dde->flags = 0;
dde->count = dde_count;
dde->index = 0;
dde->length = cpu_to_be32(byte_count);
dde->address = cpu_to_be64(nx842_get_pa(ddl));
}
static unsigned int setup_direct_dde(struct data_descriptor_entry *dde,
unsigned long pa, unsigned int len)
{
unsigned int l = min_t(unsigned int, len, LEN_ON_PAGE(pa));
dde->flags = 0;
dde->count = 0;
dde->index = 0;
dde->length = cpu_to_be32(l);
dde->address = cpu_to_be64(pa);
return l;
}
static int setup_ddl(struct data_descriptor_entry *dde,
struct data_descriptor_entry *ddl,
unsigned char *buf, unsigned int len,
bool in)
{
unsigned long pa = nx842_get_pa(buf);
int i, ret, total_len = len;
if (!IS_ALIGNED(pa, DDE_BUFFER_ALIGN)) {
pr_debug("%s buffer pa 0x%lx not 0x%x-byte aligned\n",
in ? "input" : "output", pa, DDE_BUFFER_ALIGN);
return -EINVAL;
}
if (len % DDE_BUFFER_LAST_MULT) {
pr_debug("%s buffer len 0x%x not a multiple of 0x%x\n",
in ? "input" : "output", len, DDE_BUFFER_LAST_MULT);
if (in)
return -EINVAL;
len = round_down(len, DDE_BUFFER_LAST_MULT);
}
if (len <= LEN_ON_PAGE(pa)) {
ret = setup_direct_dde(dde, pa, len);
WARN_ON(ret < len);
return 0;
}
for (i = 0; i < DDL_LEN_MAX && len > 0; i++) {
ret = setup_direct_dde(&ddl[i], pa, len);
buf += ret;
len -= ret;
pa = nx842_get_pa(buf);
}
if (len > 0) {
pr_debug("0x%x total %s bytes 0x%x too many for DDL.\n",
total_len, in ? "input" : "output", len);
if (in)
return -EMSGSIZE;
total_len -= len;
}
setup_indirect_dde(dde, ddl, i, total_len);
return 0;
}
static int wait_for_csb(struct nx842_workmem *wmem,
struct coprocessor_status_block *csb)
{
ktime_t start = wmem->start, now = ktime_get();
ktime_t timeout = ktime_add_ms(start, CSB_WAIT_MAX);
while (!(ACCESS_ONCE(csb->flags) & CSB_V)) {
cpu_relax();
now = ktime_get();
if (ktime_after(now, timeout))
break;
}
barrier();
if (!(csb->flags & CSB_V)) {
CSB_ERR(csb, "CSB still not valid after %ld us, giving up",
(long)ktime_us_delta(now, start));
return -ETIMEDOUT;
}
if (csb->flags & CSB_F) {
CSB_ERR(csb, "Invalid CSB format");
return -EPROTO;
}
if (csb->flags & CSB_CH) {
CSB_ERR(csb, "Invalid CSB chaining state");
return -EPROTO;
}
if (csb->cs) {
CSB_ERR(csb, "Invalid CSB completion sequence");
return -EPROTO;
}
switch (csb->cc) {
case CSB_CC_SUCCESS:
break;
case CSB_CC_TPBC_GT_SPBC:
break;
case CSB_CC_OPERAND_OVERLAP:
CSB_ERR(csb, "Operand Overlap error");
return -EINVAL;
case CSB_CC_INVALID_OPERAND:
CSB_ERR(csb, "Invalid operand");
return -EINVAL;
case CSB_CC_NOSPC:
return -ENOSPC;
case CSB_CC_ABORT:
CSB_ERR(csb, "Function aborted");
return -EINTR;
case CSB_CC_CRC_MISMATCH:
CSB_ERR(csb, "CRC mismatch");
return -EINVAL;
case CSB_CC_TEMPL_INVALID:
CSB_ERR(csb, "Compressed data template invalid");
return -EINVAL;
case CSB_CC_TEMPL_OVERFLOW:
CSB_ERR(csb, "Compressed data template shows data past end");
return -EINVAL;
case CSB_CC_EXCEED_BYTE_COUNT:
CSB_ERR(csb, "DDE byte count exceeds the limit");
return -EINVAL;
case CSB_CC_INVALID_ALIGN:
CSB_ERR_ADDR(csb, "Invalid alignment");
return -EINVAL;
case CSB_CC_DATA_LENGTH:
CSB_ERR(csb, "Invalid data length");
return -EINVAL;
case CSB_CC_WR_TRANSLATION:
case CSB_CC_TRANSLATION:
case CSB_CC_TRANSLATION_DUP1:
case CSB_CC_TRANSLATION_DUP2:
case CSB_CC_TRANSLATION_DUP3:
case CSB_CC_TRANSLATION_DUP4:
case CSB_CC_TRANSLATION_DUP5:
case CSB_CC_TRANSLATION_DUP6:
CSB_ERR_ADDR(csb, "Translation error");
return -EPROTO;
case CSB_CC_WR_PROTECTION:
case CSB_CC_PROTECTION:
case CSB_CC_PROTECTION_DUP1:
case CSB_CC_PROTECTION_DUP2:
case CSB_CC_PROTECTION_DUP3:
case CSB_CC_PROTECTION_DUP4:
case CSB_CC_PROTECTION_DUP5:
case CSB_CC_PROTECTION_DUP6:
CSB_ERR_ADDR(csb, "Protection error");
return -EPROTO;
case CSB_CC_PRIVILEGE:
CSB_ERR(csb, "Insufficient Privilege error");
return -EPROTO;
case CSB_CC_EXCESSIVE_DDE:
CSB_ERR(csb, "Too many DDEs in DDL");
return -EINVAL;
case CSB_CC_TRANSPORT:
case CSB_CC_INVALID_CRB:
CSB_ERR(csb, "Invalid CRB");
return -EINVAL;
case CSB_CC_INVALID_DDE:
CSB_ERR(csb, "Invalid DDE");
return -EINVAL;
case CSB_CC_SEGMENTED_DDL:
CSB_ERR(csb, "Segmented DDL error");
return -EINVAL;
case CSB_CC_DDE_OVERFLOW:
CSB_ERR(csb, "DDE overflow error");
return -EINVAL;
case CSB_CC_SESSION:
CSB_ERR(csb, "Session violation error");
return -EPROTO;
case CSB_CC_CHAIN:
CSB_ERR(csb, "Chained CRB error");
return -EPROTO;
case CSB_CC_SEQUENCE:
CSB_ERR(csb, "CRB seqeunce number error");
return -EPROTO;
case CSB_CC_UNKNOWN_CODE:
CSB_ERR(csb, "Unknown subfunction code");
return -EPROTO;
case CSB_CC_RD_EXTERNAL:
case CSB_CC_RD_EXTERNAL_DUP1:
case CSB_CC_RD_EXTERNAL_DUP2:
case CSB_CC_RD_EXTERNAL_DUP3:
CSB_ERR_ADDR(csb, "Read error outside coprocessor");
return -EPROTO;
case CSB_CC_WR_EXTERNAL:
CSB_ERR_ADDR(csb, "Write error outside coprocessor");
return -EPROTO;
case CSB_CC_INTERNAL:
CSB_ERR(csb, "Internal error in coprocessor");
return -EPROTO;
case CSB_CC_PROVISION:
CSB_ERR(csb, "Storage provision error");
return -EPROTO;
case CSB_CC_HW:
CSB_ERR(csb, "Correctable hardware error");
return -EPROTO;
case CSB_CC_HW_EXPIRED_TIMER:
CSB_ERR(csb, "Job did not finish within allowed time");
return -EPROTO;
default:
CSB_ERR(csb, "Invalid CC %d", csb->cc);
return -EPROTO;
}
if (csb->ce & CSB_CE_TERMINATION) {
CSB_ERR(csb, "CSB request was terminated");
return -EPROTO;
}
if (csb->ce & CSB_CE_INCOMPLETE) {
CSB_ERR(csb, "CSB request not complete");
return -EPROTO;
}
if (!(csb->ce & CSB_CE_TPBC)) {
CSB_ERR(csb, "TPBC not provided, unknown target length");
return -EPROTO;
}
pr_debug_ratelimited("Processed %u bytes in %lu us\n",
be32_to_cpu(csb->count),
(unsigned long)ktime_us_delta(now, start));
return 0;
}
static int nx842_config_crb(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int outlen,
struct nx842_workmem *wmem)
{
struct coprocessor_request_block *crb;
struct coprocessor_status_block *csb;
u64 csb_addr;
int ret;
crb = &wmem->crb;
csb = &crb->csb;
memset(crb, 0, sizeof(*crb));
ret = setup_ddl(&crb->source, wmem->ddl_in,
(unsigned char *)in, inlen, true);
if (ret)
return ret;
ret = setup_ddl(&crb->target, wmem->ddl_out,
out, outlen, false);
if (ret)
return ret;
csb_addr = nx842_get_pa(csb) & CRB_CSB_ADDRESS;
csb_addr |= CRB_CSB_AT;
crb->csb_addr = cpu_to_be64(csb_addr);
return 0;
}
static int nx842_exec_icswx(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlenp,
void *workmem, int fc)
{
struct coprocessor_request_block *crb;
struct coprocessor_status_block *csb;
struct nx842_workmem *wmem;
int ret;
u32 ccw;
unsigned int outlen = *outlenp;
wmem = PTR_ALIGN(workmem, WORKMEM_ALIGN);
*outlenp = 0;
if (!nx842_ct) {
pr_err_ratelimited("coprocessor CT is 0");
return -ENODEV;
}
ret = nx842_config_crb(in, inlen, out, outlen, wmem);
if (ret)
return ret;
crb = &wmem->crb;
csb = &crb->csb;
ccw = 0;
ccw = SET_FIELD(CCW_CT, ccw, nx842_ct);
ccw = SET_FIELD(CCW_CI_842, ccw, 0);
ccw = SET_FIELD(CCW_FC_842, ccw, fc);
wmem->start = ktime_get();
ret = icswx(cpu_to_be32(ccw), crb);
pr_debug_ratelimited("icswx CR %x ccw %x crb->ccw %x\n", ret,
(unsigned int)ccw,
(unsigned int)be32_to_cpu(crb->ccw));
ret &= ~ICSWX_XERS0;
switch (ret) {
case ICSWX_INITIATED:
ret = wait_for_csb(wmem, csb);
break;
case ICSWX_BUSY:
pr_debug_ratelimited("842 Coprocessor busy\n");
ret = -EBUSY;
break;
case ICSWX_REJECTED:
pr_err_ratelimited("ICSWX rejected\n");
ret = -EPROTO;
break;
}
if (!ret)
*outlenp = be32_to_cpu(csb->count);
return ret;
}
static int nx842_exec_vas(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlenp,
void *workmem, int fc)
{
struct coprocessor_request_block *crb;
struct coprocessor_status_block *csb;
struct nx842_workmem *wmem;
struct vas_window *txwin;
int ret, i = 0;
u32 ccw;
unsigned int outlen = *outlenp;
wmem = PTR_ALIGN(workmem, WORKMEM_ALIGN);
*outlenp = 0;
crb = &wmem->crb;
csb = &crb->csb;
ret = nx842_config_crb(in, inlen, out, outlen, wmem);
if (ret)
return ret;
ccw = 0;
ccw = SET_FIELD(CCW_FC_842, ccw, fc);
crb->ccw = cpu_to_be32(ccw);
txwin = wmem->txwin;
if (!txwin) {
pr_err_ratelimited("NX-842 coprocessor is not available");
return -ENODEV;
}
do {
wmem->start = ktime_get();
preempt_disable();
vas_copy_crb(crb, 0);
ret = vas_paste_crb(txwin, 0, 1);
preempt_enable();
} while (ret && (i++ < VAS_RETRIES));
if (ret) {
pr_err_ratelimited("VAS copy/paste failed\n");
return ret;
}
ret = wait_for_csb(wmem, csb);
if (!ret)
*outlenp = be32_to_cpu(csb->count);
return ret;
}
static int nx842_powernv_compress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlenp,
void *wmem)
{
return nx842_powernv_exec(in, inlen, out, outlenp,
wmem, CCW_FC_842_COMP_CRC);
}
static int nx842_powernv_decompress(const unsigned char *in, unsigned int inlen,
unsigned char *out, unsigned int *outlenp,
void *wmem)
{
return nx842_powernv_exec(in, inlen, out, outlenp,
wmem, CCW_FC_842_DECOMP_CRC);
}
static inline void nx842_add_coprocs_list(struct nx842_coproc *coproc,
int chipid)
{
coproc->chip_id = chipid;
INIT_LIST_HEAD(&coproc->list);
list_add(&coproc->list, &nx842_coprocs);
}
static void nx842_set_per_cpu_coproc(struct nx842_coproc *coproc)
{
unsigned int i, chip_id;
for_each_possible_cpu(i) {
chip_id = cpu_to_chip_id(i);
if (coproc->chip_id == chip_id)
per_cpu(coproc_inst, i) = coproc;
}
}
static struct vas_window *nx842_alloc_txwin(struct nx842_coproc *coproc)
{
struct vas_window *txwin = NULL;
struct vas_tx_win_attr txattr;
vas_init_tx_win_attr(&txattr, coproc->ct);
txattr.lpid = 0;
txattr.pid = 0;
txwin = vas_tx_win_open(coproc->vas.id, coproc->ct, &txattr);
if (IS_ERR(txwin)) {
pr_err("ibm,nx-842: Can not open TX window: %ld\n",
PTR_ERR(txwin));
return NULL;
}
return txwin;
}
static int __init vas_cfg_coproc_info(struct device_node *dn, int chip_id,
int vasid)
{
struct vas_window *rxwin = NULL;
struct vas_rx_win_attr rxattr;
struct nx842_coproc *coproc;
u32 lpid, pid, tid, fifo_size;
u64 rx_fifo;
const char *priority;
int ret;
ret = of_property_read_u64(dn, "rx-fifo-address", &rx_fifo);
if (ret) {
pr_err("Missing rx-fifo-address property\n");
return ret;
}
ret = of_property_read_u32(dn, "rx-fifo-size", &fifo_size);
if (ret) {
pr_err("Missing rx-fifo-size property\n");
return ret;
}
ret = of_property_read_u32(dn, "lpid", &lpid);
if (ret) {
pr_err("Missing lpid property\n");
return ret;
}
ret = of_property_read_u32(dn, "pid", &pid);
if (ret) {
pr_err("Missing pid property\n");
return ret;
}
ret = of_property_read_u32(dn, "tid", &tid);
if (ret) {
pr_err("Missing tid property\n");
return ret;
}
ret = of_property_read_string(dn, "priority", &priority);
if (ret) {
pr_err("Missing priority property\n");
return ret;
}
coproc = kzalloc(sizeof(*coproc), GFP_KERNEL);
if (!coproc)
return -ENOMEM;
if (!strcmp(priority, "High"))
coproc->ct = VAS_COP_TYPE_842_HIPRI;
else if (!strcmp(priority, "Normal"))
coproc->ct = VAS_COP_TYPE_842;
else {
pr_err("Invalid RxFIFO priority value\n");
ret = -EINVAL;
goto err_out;
}
vas_init_rx_win_attr(&rxattr, coproc->ct);
rxattr.rx_fifo = (void *)rx_fifo;
rxattr.rx_fifo_size = fifo_size;
rxattr.lnotify_lpid = lpid;
rxattr.lnotify_pid = pid;
rxattr.lnotify_tid = tid;
rxattr.wcreds_max = MAX_CREDITS_PER_RXFIFO;
rxwin = vas_rx_win_open(vasid, coproc->ct, &rxattr);
if (IS_ERR(rxwin)) {
ret = PTR_ERR(rxwin);
pr_err("setting RxFIFO with VAS failed: %d\n",
ret);
goto err_out;
}
coproc->vas.rxwin = rxwin;
coproc->vas.id = vasid;
nx842_add_coprocs_list(coproc, chip_id);
if (coproc->ct == VAS_COP_TYPE_842_HIPRI)
nx842_set_per_cpu_coproc(coproc);
return 0;
err_out:
kfree(coproc);
return ret;
}
static int __init nx842_powernv_probe_vas(struct device_node *pn)
{
struct device_node *dn;
int chip_id, vasid, ret = 0;
int nx_fifo_found = 0;
chip_id = of_get_ibm_chip_id(pn);
if (chip_id < 0) {
pr_err("ibm,chip-id missing\n");
return -EINVAL;
}
for_each_compatible_node(dn, NULL, "ibm,power9-vas-x") {
if (of_get_ibm_chip_id(dn) == chip_id)
break;
}
if (!dn) {
pr_err("Missing VAS device node\n");
return -EINVAL;
}
if (of_property_read_u32(dn, "ibm,vas-id", &vasid)) {
pr_err("Missing ibm,vas-id device property\n");
of_node_put(dn);
return -EINVAL;
}
of_node_put(dn);
for_each_child_of_node(pn, dn) {
if (of_device_is_compatible(dn, "ibm,p9-nx-842")) {
ret = vas_cfg_coproc_info(dn, chip_id, vasid);
if (ret) {
of_node_put(dn);
return ret;
}
nx_fifo_found++;
}
}
if (!nx_fifo_found) {
pr_err("NX842 FIFO nodes are missing\n");
ret = -EINVAL;
}
return ret;
}
static int __init nx842_powernv_probe(struct device_node *dn)
{
struct nx842_coproc *coproc;
unsigned int ct, ci;
int chip_id;
chip_id = of_get_ibm_chip_id(dn);
if (chip_id < 0) {
pr_err("ibm,chip-id missing\n");
return -EINVAL;
}
if (of_property_read_u32(dn, "ibm,842-coprocessor-type", &ct)) {
pr_err("ibm,842-coprocessor-type missing\n");
return -EINVAL;
}
if (of_property_read_u32(dn, "ibm,842-coprocessor-instance", &ci)) {
pr_err("ibm,842-coprocessor-instance missing\n");
return -EINVAL;
}
coproc = kmalloc(sizeof(*coproc), GFP_KERNEL);
if (!coproc)
return -ENOMEM;
coproc->ct = ct;
coproc->ci = ci;
nx842_add_coprocs_list(coproc, chip_id);
pr_info("coprocessor found on chip %d, CT %d CI %d\n", chip_id, ct, ci);
if (!nx842_ct)
nx842_ct = ct;
else if (nx842_ct != ct)
pr_err("NX842 chip %d, CT %d != first found CT %d\n",
chip_id, ct, nx842_ct);
return 0;
}
static void nx842_delete_coprocs(void)
{
struct nx842_coproc *coproc, *n;
list_for_each_entry_safe(coproc, n, &nx842_coprocs, list) {
if (coproc->vas.rxwin)
vas_win_close(coproc->vas.rxwin);
list_del(&coproc->list);
kfree(coproc);
}
}
static int nx842_powernv_crypto_init_vas(struct crypto_tfm *tfm)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_workmem *wmem;
struct nx842_coproc *coproc;
int ret;
ret = nx842_crypto_init(tfm, &nx842_powernv_driver);
if (ret)
return ret;
wmem = PTR_ALIGN((struct nx842_workmem *)ctx->wmem, WORKMEM_ALIGN);
coproc = per_cpu(coproc_inst, smp_processor_id());
ret = -EINVAL;
if (coproc && coproc->vas.rxwin) {
wmem->txwin = nx842_alloc_txwin(coproc);
if (!IS_ERR(wmem->txwin))
return 0;
ret = PTR_ERR(wmem->txwin);
}
return ret;
}
void nx842_powernv_crypto_exit_vas(struct crypto_tfm *tfm)
{
struct nx842_crypto_ctx *ctx = crypto_tfm_ctx(tfm);
struct nx842_workmem *wmem;
wmem = PTR_ALIGN((struct nx842_workmem *)ctx->wmem, WORKMEM_ALIGN);
if (wmem && wmem->txwin)
vas_win_close(wmem->txwin);
nx842_crypto_exit(tfm);
}
static int nx842_powernv_crypto_init(struct crypto_tfm *tfm)
{
return nx842_crypto_init(tfm, &nx842_powernv_driver);
}
static __init int nx842_powernv_init(void)
{
struct device_node *dn;
int ret;
BUILD_BUG_ON(WORKMEM_ALIGN % CRB_ALIGN);
BUILD_BUG_ON(CRB_ALIGN % DDE_ALIGN);
BUILD_BUG_ON(CRB_SIZE % DDE_ALIGN);
BUILD_BUG_ON(PAGE_SIZE % DDE_BUFFER_ALIGN);
BUILD_BUG_ON(DDE_BUFFER_ALIGN % DDE_BUFFER_SIZE_MULT);
BUILD_BUG_ON(DDE_BUFFER_SIZE_MULT % DDE_BUFFER_LAST_MULT);
for_each_compatible_node(dn, NULL, "ibm,power9-nx") {
ret = nx842_powernv_probe_vas(dn);
if (ret) {
nx842_delete_coprocs();
return ret;
}
}
if (list_empty(&nx842_coprocs)) {
for_each_compatible_node(dn, NULL, "ibm,power-nx")
nx842_powernv_probe(dn);
if (!nx842_ct)
return -ENODEV;
nx842_powernv_exec = nx842_exec_icswx;
} else {
nx842_powernv_exec = nx842_exec_vas;
nx842_powernv_alg.cra_init = nx842_powernv_crypto_init_vas;
nx842_powernv_alg.cra_exit = nx842_powernv_crypto_exit_vas;
}
ret = crypto_register_alg(&nx842_powernv_alg);
if (ret) {
nx842_delete_coprocs();
return ret;
}
return 0;
}
static void __exit nx842_powernv_exit(void)
{
crypto_unregister_alg(&nx842_powernv_alg);
nx842_delete_coprocs();
}
