static int keygen_write_ar_wait(struct fman_kg_regs __iomem *regs, u32 fmkg_ar)
{
iowrite32be(fmkg_ar, &regs->fmkg_ar);
while (fmkg_ar & FM_KG_KGAR_GO)
fmkg_ar = ioread32be(&regs->fmkg_ar);
if (fmkg_ar & FM_KG_KGAR_ERR)
return -EINVAL;
return 0;
}
static u32 build_ar_scheme(u8 scheme_id, bool update_counter, bool write)
{
u32 rw = (u32)(write ? FM_KG_KGAR_WRITE : FM_KG_KGAR_READ);
return (u32)(FM_KG_KGAR_GO |
rw |
FM_KG_KGAR_SEL_SCHEME_ENTRY |
DUMMY_PORT_ID |
((u32)scheme_id << FM_KG_KGAR_NUM_SHIFT) |
(update_counter ? FM_KG_KGAR_SCM_WSEL_UPDATE_CNT : 0));
}
static u32 build_ar_bind_scheme(u8 hwport_id, bool write)
{
u32 rw = write ? (u32)FM_KG_KGAR_WRITE : (u32)FM_KG_KGAR_READ;
return (u32)(FM_KG_KGAR_GO |
rw |
FM_KG_KGAR_SEL_PORT_ENTRY |
hwport_id |
FM_KG_KGAR_SEL_PORT_WSEL_SP);
}
static void keygen_write_sp(struct fman_kg_regs __iomem *regs, u32 sp, bool add)
{
u32 tmp;
tmp = ioread32be(&regs->fmkg_pe.fmkg_pe_sp);
if (add)
tmp |= sp;
else
tmp &= ~sp;
iowrite32be(tmp, &regs->fmkg_pe.fmkg_pe_sp);
}
static u32 build_ar_bind_cls_plan(u8 hwport_id, bool write)
{
u32 rw = write ? (u32)FM_KG_KGAR_WRITE : (u32)FM_KG_KGAR_READ;
return (u32)(FM_KG_KGAR_GO |
rw |
FM_KG_KGAR_SEL_PORT_ENTRY |
hwport_id |
FM_KG_KGAR_SEL_PORT_WSEL_CPP);
}
static void keygen_write_cpp(struct fman_kg_regs __iomem *regs, u32 cpp)
{
iowrite32be(cpp, &regs->fmkg_pe.fmkg_pe_cpp);
}
static int keygen_write_scheme(struct fman_kg_regs __iomem *regs, u8 scheme_id,
struct fman_kg_scheme_regs *scheme_regs,
bool update_counter)
{
u32 ar_reg;
int err, i;
iowrite32be(scheme_regs->kgse_mode, &regs->fmkg_sch.kgse_mode);
iowrite32be(scheme_regs->kgse_ekfc, &regs->fmkg_sch.kgse_ekfc);
iowrite32be(scheme_regs->kgse_ekdv, &regs->fmkg_sch.kgse_ekdv);
iowrite32be(scheme_regs->kgse_bmch, &regs->fmkg_sch.kgse_bmch);
iowrite32be(scheme_regs->kgse_bmcl, &regs->fmkg_sch.kgse_bmcl);
iowrite32be(scheme_regs->kgse_fqb, &regs->fmkg_sch.kgse_fqb);
iowrite32be(scheme_regs->kgse_hc, &regs->fmkg_sch.kgse_hc);
iowrite32be(scheme_regs->kgse_ppc, &regs->fmkg_sch.kgse_ppc);
iowrite32be(scheme_regs->kgse_spc, &regs->fmkg_sch.kgse_spc);
iowrite32be(scheme_regs->kgse_dv0, &regs->fmkg_sch.kgse_dv0);
iowrite32be(scheme_regs->kgse_dv1, &regs->fmkg_sch.kgse_dv1);
iowrite32be(scheme_regs->kgse_ccbs, &regs->fmkg_sch.kgse_ccbs);
iowrite32be(scheme_regs->kgse_mv, &regs->fmkg_sch.kgse_mv);
iowrite32be(scheme_regs->kgse_om, &regs->fmkg_sch.kgse_om);
iowrite32be(scheme_regs->kgse_vsp, &regs->fmkg_sch.kgse_vsp);
for (i = 0 ; i < FM_KG_NUM_OF_GENERIC_REGS ; i++)
iowrite32be(scheme_regs->kgse_gec[i],
&regs->fmkg_sch.kgse_gec[i]);
ar_reg = build_ar_scheme(scheme_id, update_counter, true);
err = keygen_write_ar_wait(regs, ar_reg);
if (err != 0) {
pr_err("Writing Action Register failed\n");
return err;
}
return err;
}
static int get_free_scheme_id(struct fman_keygen *keygen, u8 *scheme_id)
{
u8 i;
for (i = 0; i < FM_KG_MAX_NUM_OF_SCHEMES; i++)
if (!keygen->schemes[i].used) {
*scheme_id = i;
return 0;
}
return -EINVAL;
}
static struct keygen_scheme *get_scheme(struct fman_keygen *keygen,
u8 scheme_id)
{
if (scheme_id >= FM_KG_MAX_NUM_OF_SCHEMES)
return NULL;
return &keygen->schemes[scheme_id];
}
static int keygen_bind_port_to_schemes(struct fman_keygen *keygen,
u8 scheme_id,
bool bind)
{
struct fman_kg_regs __iomem *keygen_regs = keygen->keygen_regs;
struct keygen_scheme *scheme;
u32 ar_reg;
u32 schemes_vector = 0;
int err;
scheme = get_scheme(keygen, scheme_id);
if (!scheme) {
pr_err("Requested Scheme does not exist\n");
return -EINVAL;
}
if (!scheme->used) {
pr_err("Cannot bind port to an invalid scheme\n");
return -EINVAL;
}
schemes_vector |= 1 << (31 - scheme_id);
ar_reg = build_ar_bind_scheme(scheme->hw_port_id, false);
err = keygen_write_ar_wait(keygen_regs, ar_reg);
if (err != 0) {
pr_err("Reading Action Register failed\n");
return err;
}
keygen_write_sp(keygen_regs, schemes_vector, bind);
ar_reg = build_ar_bind_scheme(scheme->hw_port_id, true);
err = keygen_write_ar_wait(keygen_regs, ar_reg);
if (err != 0) {
pr_err("Writing Action Register failed\n");
return err;
}
return 0;
}
static int keygen_scheme_setup(struct fman_keygen *keygen, u8 scheme_id,
bool enable)
{
struct fman_kg_regs __iomem *keygen_regs = keygen->keygen_regs;
struct fman_kg_scheme_regs scheme_regs;
struct keygen_scheme *scheme;
u32 tmp_reg;
int err;
scheme = get_scheme(keygen, scheme_id);
if (!scheme) {
pr_err("Requested Scheme does not exist\n");
return -EINVAL;
}
if (enable && scheme->used) {
pr_err("The requested Scheme is already used\n");
return -EINVAL;
}
memset(&scheme_regs, 0, sizeof(struct fman_kg_scheme_regs));
tmp_reg = 0;
if (enable) {
tmp_reg |= KG_SCH_MODE_EN;
tmp_reg |= ENQUEUE_KG_DFLT_NIA;
}
scheme_regs.kgse_mode = tmp_reg;
scheme_regs.kgse_mv = scheme->match_vector;
scheme_regs.kgse_vsp = KG_SCH_VSP_NO_KSP_EN;
if (scheme->use_hashing) {
scheme_regs.kgse_ekfc = DEFAULT_HASH_KEY_EXTRACT_FIELDS;
tmp_reg = 0;
tmp_reg |= (KG_SCH_DEF_USE_KGSE_DV_0 <<
KG_SCH_DEF_IP_ADDR_SHIFT);
tmp_reg |= (KG_SCH_DEF_USE_KGSE_DV_1 <<
KG_SCH_DEF_L4_PORT_SHIFT);
scheme_regs.kgse_ekdv = tmp_reg;
scheme_regs.kgse_dv0 = DEFAULT_HASH_KEY_IPv4_ADDR;
scheme_regs.kgse_dv1 = DEFAULT_HASH_KEY_L4_PORT;
tmp_reg = 0;
tmp_reg |= ((scheme->hash_fqid_count - 1) <<
DEFAULT_HASH_DIST_FQID_SHIFT);
tmp_reg |= scheme->hashShift << KG_SCH_HASH_CONFIG_SHIFT_SHIFT;
if (scheme->symmetric_hash) {
tmp_reg |= KG_SCH_HASH_CONFIG_SYM;
}
scheme_regs.kgse_hc = tmp_reg;
} else {
scheme_regs.kgse_ekfc = 0;
scheme_regs.kgse_hc = 0;
scheme_regs.kgse_ekdv = 0;
scheme_regs.kgse_dv0 = 0;
scheme_regs.kgse_dv1 = 0;
}
tmp_reg = 0;
tmp_reg |= scheme->base_fqid;
scheme_regs.kgse_fqb = tmp_reg;
scheme_regs.kgse_bmch = 0;
scheme_regs.kgse_bmcl = 0;
scheme_regs.kgse_spc = 0;
err = keygen_write_scheme(keygen_regs, scheme_id, &scheme_regs, true);
if (err != 0) {
pr_err("Writing scheme registers failed\n");
return err;
}
scheme->used = enable;
return 0;
}
struct fman_keygen *keygen_init(struct fman_kg_regs __iomem *keygen_regs)
{
struct fman_keygen *keygen;
u32 ar;
int i;
keygen = kzalloc(sizeof(*keygen), GFP_KERNEL);
if (!keygen)
return NULL;
keygen->keygen_regs = keygen_regs;
iowrite32be(ENQUEUE_KG_DFLT_NIA, &keygen_regs->fmkg_gcr);
iowrite32be(FM_EX_KG_DOUBLE_ECC | FM_EX_KG_KEYSIZE_OVERFLOW,
&keygen_regs->fmkg_eer);
iowrite32be(0, &keygen_regs->fmkg_fdor);
iowrite32be(0, &keygen_regs->fmkg_gdv0r);
iowrite32be(0, &keygen_regs->fmkg_gdv1r);
for (i = 0; i < FMAN_MAX_NUM_OF_HW_PORTS; i++) {
keygen_write_sp(keygen_regs, 0xffffffff, false);
ar = build_ar_bind_scheme(i, true);
keygen_write_ar_wait(keygen_regs, ar);
keygen_write_cpp(keygen_regs, 0);
ar = build_ar_bind_cls_plan(i, true);
keygen_write_ar_wait(keygen_regs, ar);
}
iowrite32be(0xFFFFFFFF, &keygen_regs->fmkg_seer);
iowrite32be(0xFFFFFFFF, &keygen_regs->fmkg_seeer);
iowrite32be(ioread32be(&keygen_regs->fmkg_gcr) | FM_KG_KGGCR_EN,
&keygen_regs->fmkg_gcr);
return keygen;
}
int keygen_port_hashing_init(struct fman_keygen *keygen, u8 hw_port_id,
u32 hash_base_fqid, u32 hash_size)
{
struct keygen_scheme *scheme;
u8 scheme_id;
int err;
if (hash_base_fqid == 0 || (hash_base_fqid & ~0x00FFFFFF)) {
pr_err("Base FQID must be between 1 and 2^24-1\n");
return -EINVAL;
}
if (hash_size == 0 || (hash_size & (hash_size - 1)) != 0) {
pr_err("Hash size must be power of two\n");
return -EINVAL;
}
err = get_free_scheme_id(keygen, &scheme_id);
if (err) {
pr_err("The maximum number of available Schemes has been exceeded\n");
return -EINVAL;
}
scheme = get_scheme(keygen, scheme_id);
if (!scheme) {
pr_err("Requested Scheme does not exist\n");
return -EINVAL;
}
if (scheme->used) {
pr_err("The requested Scheme is already used\n");
return -EINVAL;
}
memset(scheme, 0, sizeof(struct keygen_scheme));
scheme->hw_port_id = hw_port_id;
scheme->use_hashing = true;
scheme->base_fqid = hash_base_fqid;
scheme->hash_fqid_count = hash_size;
scheme->symmetric_hash = DEFAULT_SYMMETRIC_HASH;
scheme->hashShift = DEFAULT_HASH_SHIFT;
scheme->match_vector = 0;
err = keygen_scheme_setup(keygen, scheme_id, true);
if (err != 0) {
pr_err("Scheme setup failed\n");
return err;
}
err = keygen_bind_port_to_schemes(keygen, scheme_id, true);
if (err != 0) {
pr_err("Binding port to schemes failed\n");
return err;
}
return 0;
}
