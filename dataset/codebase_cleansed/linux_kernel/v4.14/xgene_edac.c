static void xgene_edac_pcp_rd(struct xgene_edac *edac, u32 reg, u32 *val)
{
*val = readl(edac->pcp_csr + reg);
}
static void xgene_edac_pcp_clrbits(struct xgene_edac *edac, u32 reg,
u32 bits_mask)
{
u32 val;
spin_lock(&edac->lock);
val = readl(edac->pcp_csr + reg);
val &= ~bits_mask;
writel(val, edac->pcp_csr + reg);
spin_unlock(&edac->lock);
}
static void xgene_edac_pcp_setbits(struct xgene_edac *edac, u32 reg,
u32 bits_mask)
{
u32 val;
spin_lock(&edac->lock);
val = readl(edac->pcp_csr + reg);
val |= bits_mask;
writel(val, edac->pcp_csr + reg);
spin_unlock(&edac->lock);
}
static ssize_t xgene_edac_mc_err_inject_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct mem_ctl_info *mci = file->private_data;
struct xgene_edac_mc_ctx *ctx = mci->pvt_info;
int i;
for (i = 0; i < MCU_MAX_RANK; i++) {
writel(MCU_ESRR_MULTUCERR_MASK | MCU_ESRR_BACKUCERR_MASK |
MCU_ESRR_DEMANDUCERR_MASK | MCU_ESRR_CERR_MASK,
ctx->mcu_csr + MCUESRRA0 + i * MCU_RANK_STRIDE);
}
return count;
}
static void xgene_edac_mc_create_debugfs_node(struct mem_ctl_info *mci)
{
if (!IS_ENABLED(CONFIG_EDAC_DEBUG))
return;
if (!mci->debugfs)
return;
edac_debugfs_create_file("inject_ctrl", S_IWUSR, mci->debugfs, mci,
&xgene_edac_mc_debug_inject_fops);
}
static void xgene_edac_mc_check(struct mem_ctl_info *mci)
{
struct xgene_edac_mc_ctx *ctx = mci->pvt_info;
unsigned int pcp_hp_stat;
unsigned int pcp_lp_stat;
u32 reg;
u32 rank;
u32 bank;
u32 count;
u32 col_row;
xgene_edac_pcp_rd(ctx->edac, PCPHPERRINTSTS, &pcp_hp_stat);
xgene_edac_pcp_rd(ctx->edac, PCPLPERRINTSTS, &pcp_lp_stat);
if (!((MCU_UNCORR_ERR_MASK & pcp_hp_stat) ||
(MCU_CTL_ERR_MASK & pcp_hp_stat) ||
(MCU_CORR_ERR_MASK & pcp_lp_stat)))
return;
for (rank = 0; rank < MCU_MAX_RANK; rank++) {
reg = readl(ctx->mcu_csr + MCUESRR0 + rank * MCU_RANK_STRIDE);
if (reg & (MCU_ESRR_DEMANDUCERR_MASK |
MCU_ESRR_BACKUCERR_MASK)) {
edac_mc_chipset_printk(mci, KERN_ERR, "X-Gene",
"MCU uncorrectable error at rank %d\n", rank);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
1, 0, 0, 0, 0, 0, -1, mci->ctl_name, "");
}
if (reg & MCU_ESRR_CERR_MASK) {
bank = readl(ctx->mcu_csr + MCUEBLRR0 +
rank * MCU_RANK_STRIDE);
col_row = readl(ctx->mcu_csr + MCUERCRR0 +
rank * MCU_RANK_STRIDE);
count = readl(ctx->mcu_csr + MCUSBECNT0 +
rank * MCU_RANK_STRIDE);
edac_mc_chipset_printk(mci, KERN_WARNING, "X-Gene",
"MCU correctable error at rank %d bank %d column %d row %d count %d\n",
rank, MCU_EBLRR_ERRBANK_RD(bank),
MCU_ERCRR_ERRCOL_RD(col_row),
MCU_ERCRR_ERRROW_RD(col_row),
MCU_SBECNT_COUNT(count));
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci,
1, 0, 0, 0, 0, 0, -1, mci->ctl_name, "");
}
writel(0x0, ctx->mcu_csr + MCUEBLRR0 + rank * MCU_RANK_STRIDE);
writel(0x0, ctx->mcu_csr + MCUERCRR0 + rank * MCU_RANK_STRIDE);
writel(0x0, ctx->mcu_csr + MCUSBECNT0 +
rank * MCU_RANK_STRIDE);
writel(reg, ctx->mcu_csr + MCUESRR0 + rank * MCU_RANK_STRIDE);
}
reg = readl(ctx->mcu_csr + MCUGESR);
if (reg) {
if (reg & MCU_GESR_ADDRNOMATCH_ERR_MASK)
edac_mc_chipset_printk(mci, KERN_WARNING, "X-Gene",
"MCU address miss-match error\n");
if (reg & MCU_GESR_ADDRMULTIMATCH_ERR_MASK)
edac_mc_chipset_printk(mci, KERN_WARNING, "X-Gene",
"MCU address multi-match error\n");
writel(reg, ctx->mcu_csr + MCUGESR);
}
}
static void xgene_edac_mc_irq_ctl(struct mem_ctl_info *mci, bool enable)
{
struct xgene_edac_mc_ctx *ctx = mci->pvt_info;
unsigned int val;
if (edac_op_state != EDAC_OPSTATE_INT)
return;
mutex_lock(&ctx->edac->mc_lock);
if (enable) {
ctx->edac->mc_registered_mask |= 1 << ctx->mcu_id;
if (ctx->edac->mc_registered_mask ==
ctx->edac->mc_active_mask) {
xgene_edac_pcp_clrbits(ctx->edac, PCPHPERRINTMSK,
MCU_UNCORR_ERR_MASK |
MCU_CTL_ERR_MASK);
xgene_edac_pcp_clrbits(ctx->edac, PCPLPERRINTMSK,
MCU_CORR_ERR_MASK);
}
val = readl(ctx->mcu_csr + MCUGECR);
val |= MCU_GECR_DEMANDUCINTREN_MASK |
MCU_GECR_BACKUCINTREN_MASK |
MCU_GECR_CINTREN_MASK |
MUC_GECR_MCUADDRERREN_MASK;
writel(val, ctx->mcu_csr + MCUGECR);
} else {
val = readl(ctx->mcu_csr + MCUGECR);
val &= ~(MCU_GECR_DEMANDUCINTREN_MASK |
MCU_GECR_BACKUCINTREN_MASK |
MCU_GECR_CINTREN_MASK |
MUC_GECR_MCUADDRERREN_MASK);
writel(val, ctx->mcu_csr + MCUGECR);
xgene_edac_pcp_setbits(ctx->edac, PCPHPERRINTMSK,
MCU_UNCORR_ERR_MASK | MCU_CTL_ERR_MASK);
xgene_edac_pcp_setbits(ctx->edac, PCPLPERRINTMSK,
MCU_CORR_ERR_MASK);
ctx->edac->mc_registered_mask &= ~(1 << ctx->mcu_id);
}
mutex_unlock(&ctx->edac->mc_lock);
}
static int xgene_edac_mc_is_active(struct xgene_edac_mc_ctx *ctx, int mc_idx)
{
unsigned int reg;
u32 mcu_mask;
if (regmap_read(ctx->edac->csw_map, CSW_CSWCR, &reg))
return 0;
if (reg & CSW_CSWCR_DUALMCB_MASK) {
if (regmap_read(ctx->edac->mcbb_map, MCBADDRMR, &reg))
return 0;
mcu_mask = (reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0xF : 0x5;
} else {
if (regmap_read(ctx->edac->mcba_map, MCBADDRMR, &reg))
return 0;
mcu_mask = (reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0x3 : 0x1;
}
if (!ctx->edac->mc_active_mask)
ctx->edac->mc_active_mask = mcu_mask;
return (mcu_mask & (1 << mc_idx)) ? 1 : 0;
}
static int xgene_edac_mc_add(struct xgene_edac *edac, struct device_node *np)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct xgene_edac_mc_ctx tmp_ctx;
struct xgene_edac_mc_ctx *ctx;
struct resource res;
int rc;
memset(&tmp_ctx, 0, sizeof(tmp_ctx));
tmp_ctx.edac = edac;
if (!devres_open_group(edac->dev, xgene_edac_mc_add, GFP_KERNEL))
return -ENOMEM;
rc = of_address_to_resource(np, 0, &res);
if (rc < 0) {
dev_err(edac->dev, "no MCU resource address\n");
goto err_group;
}
tmp_ctx.mcu_csr = devm_ioremap_resource(edac->dev, &res);
if (IS_ERR(tmp_ctx.mcu_csr)) {
dev_err(edac->dev, "unable to map MCU resource\n");
rc = PTR_ERR(tmp_ctx.mcu_csr);
goto err_group;
}
if (of_property_read_u32(np, "memory-controller", &tmp_ctx.mcu_id)) {
dev_err(edac->dev, "no memory-controller property\n");
rc = -ENODEV;
goto err_group;
}
if (!xgene_edac_mc_is_active(&tmp_ctx, tmp_ctx.mcu_id)) {
rc = -ENODEV;
goto err_group;
}
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = 4;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = 2;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(tmp_ctx.mcu_id, ARRAY_SIZE(layers), layers,
sizeof(*ctx));
if (!mci) {
rc = -ENOMEM;
goto err_group;
}
ctx = mci->pvt_info;
*ctx = tmp_ctx;
ctx->name = "xgene_edac_mc_err";
ctx->mci = mci;
mci->pdev = &mci->dev;
mci->ctl_name = ctx->name;
mci->dev_name = ctx->name;
mci->mtype_cap = MEM_FLAG_RDDR | MEM_FLAG_RDDR2 | MEM_FLAG_RDDR3 |
MEM_FLAG_DDR | MEM_FLAG_DDR2 | MEM_FLAG_DDR3;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->mod_name = EDAC_MOD_STR;
mci->ctl_page_to_phys = NULL;
mci->scrub_cap = SCRUB_FLAG_HW_SRC;
mci->scrub_mode = SCRUB_HW_SRC;
if (edac_op_state == EDAC_OPSTATE_POLL)
mci->edac_check = xgene_edac_mc_check;
if (edac_mc_add_mc(mci)) {
dev_err(edac->dev, "edac_mc_add_mc failed\n");
rc = -EINVAL;
goto err_free;
}
xgene_edac_mc_create_debugfs_node(mci);
list_add(&ctx->next, &edac->mcus);
xgene_edac_mc_irq_ctl(mci, true);
devres_remove_group(edac->dev, xgene_edac_mc_add);
dev_info(edac->dev, "X-Gene EDAC MC registered\n");
return 0;
err_free:
edac_mc_free(mci);
err_group:
devres_release_group(edac->dev, xgene_edac_mc_add);
return rc;
}
static int xgene_edac_mc_remove(struct xgene_edac_mc_ctx *mcu)
{
xgene_edac_mc_irq_ctl(mcu->mci, false);
edac_mc_del_mc(&mcu->mci->dev);
edac_mc_free(mcu->mci);
return 0;
}
static void xgene_edac_pmd_l1_check(struct edac_device_ctl_info *edac_dev,
int cpu_idx)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *pg_f;
u32 val;
pg_f = ctx->pmd_csr + cpu_idx * CPU_CSR_STRIDE + CPU_MEMERR_CPU_PAGE;
val = readl(pg_f + MEMERR_CPU_ICFESR_PAGE_OFFSET);
if (!val)
goto chk_lsu;
dev_err(edac_dev->dev,
"CPU%d L1 memory error ICF 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_ICFESR_ERRWAY_RD(val),
MEMERR_CPU_ICFESR_ERRINDEX_RD(val),
MEMERR_CPU_ICFESR_ERRINFO_RD(val));
if (val & MEMERR_CPU_ICFESR_CERR_MASK)
dev_err(edac_dev->dev, "One or more correctable error\n");
if (val & MEMERR_CPU_ICFESR_MULTCERR_MASK)
dev_err(edac_dev->dev, "Multiple correctable error\n");
switch (MEMERR_CPU_ICFESR_ERRTYPE_RD(val)) {
case 1:
dev_err(edac_dev->dev, "L1 TLB multiple hit\n");
break;
case 2:
dev_err(edac_dev->dev, "Way select multiple hit\n");
break;
case 3:
dev_err(edac_dev->dev, "Physical tag parity error\n");
break;
case 4:
case 5:
dev_err(edac_dev->dev, "L1 data parity error\n");
break;
case 6:
dev_err(edac_dev->dev, "L1 pre-decode parity error\n");
break;
}
writel(val, pg_f + MEMERR_CPU_ICFESR_PAGE_OFFSET);
if (val & (MEMERR_CPU_ICFESR_CERR_MASK |
MEMERR_CPU_ICFESR_MULTCERR_MASK))
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
chk_lsu:
val = readl(pg_f + MEMERR_CPU_LSUESR_PAGE_OFFSET);
if (!val)
goto chk_mmu;
dev_err(edac_dev->dev,
"CPU%d memory error LSU 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_LSUESR_ERRWAY_RD(val),
MEMERR_CPU_LSUESR_ERRINDEX_RD(val),
MEMERR_CPU_LSUESR_ERRINFO_RD(val));
if (val & MEMERR_CPU_LSUESR_CERR_MASK)
dev_err(edac_dev->dev, "One or more correctable error\n");
if (val & MEMERR_CPU_LSUESR_MULTCERR_MASK)
dev_err(edac_dev->dev, "Multiple correctable error\n");
switch (MEMERR_CPU_LSUESR_ERRTYPE_RD(val)) {
case 0:
dev_err(edac_dev->dev, "Load tag error\n");
break;
case 1:
dev_err(edac_dev->dev, "Load data error\n");
break;
case 2:
dev_err(edac_dev->dev, "WSL multihit error\n");
break;
case 3:
dev_err(edac_dev->dev, "Store tag error\n");
break;
case 4:
dev_err(edac_dev->dev,
"DTB multihit from load pipeline error\n");
break;
case 5:
dev_err(edac_dev->dev,
"DTB multihit from store pipeline error\n");
break;
}
writel(val, pg_f + MEMERR_CPU_LSUESR_PAGE_OFFSET);
if (val & (MEMERR_CPU_LSUESR_CERR_MASK |
MEMERR_CPU_LSUESR_MULTCERR_MASK))
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
chk_mmu:
val = readl(pg_f + MEMERR_CPU_MMUESR_PAGE_OFFSET);
if (!val)
return;
dev_err(edac_dev->dev,
"CPU%d memory error MMU 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X %s\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_MMUESR_ERRWAY_RD(val),
MEMERR_CPU_MMUESR_ERRINDEX_RD(val),
MEMERR_CPU_MMUESR_ERRINFO_RD(val),
val & MEMERR_CPU_MMUESR_ERRREQSTR_LSU_MASK ? "LSU" : "ICF");
if (val & MEMERR_CPU_MMUESR_CERR_MASK)
dev_err(edac_dev->dev, "One or more correctable error\n");
if (val & MEMERR_CPU_MMUESR_MULTCERR_MASK)
dev_err(edac_dev->dev, "Multiple correctable error\n");
switch (MEMERR_CPU_MMUESR_ERRTYPE_RD(val)) {
case 0:
dev_err(edac_dev->dev, "Stage 1 UTB hit error\n");
break;
case 1:
dev_err(edac_dev->dev, "Stage 1 UTB miss error\n");
break;
case 2:
dev_err(edac_dev->dev, "Stage 1 UTB allocate error\n");
break;
case 3:
dev_err(edac_dev->dev, "TMO operation single bank error\n");
break;
case 4:
dev_err(edac_dev->dev, "Stage 2 UTB error\n");
break;
case 5:
dev_err(edac_dev->dev, "Stage 2 UTB miss error\n");
break;
case 6:
dev_err(edac_dev->dev, "Stage 2 UTB allocate error\n");
break;
case 7:
dev_err(edac_dev->dev, "TMO operation multiple bank error\n");
break;
}
writel(val, pg_f + MEMERR_CPU_MMUESR_PAGE_OFFSET);
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
}
static void xgene_edac_pmd_l2_check(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *pg_d;
void __iomem *pg_e;
u32 val_hi;
u32 val_lo;
u32 val;
pg_e = ctx->pmd_csr + CPU_MEMERR_L2C_PAGE;
val = readl(pg_e + MEMERR_L2C_L2ESR_PAGE_OFFSET);
if (!val)
goto chk_l2c;
val_lo = readl(pg_e + MEMERR_L2C_L2EALR_PAGE_OFFSET);
val_hi = readl(pg_e + MEMERR_L2C_L2EAHR_PAGE_OFFSET);
dev_err(edac_dev->dev,
"PMD%d memory error L2C L2ESR 0x%08X @ 0x%08X.%08X\n",
ctx->pmd, val, val_hi, val_lo);
dev_err(edac_dev->dev,
"ErrSyndrome 0x%02X ErrWay 0x%02X ErrCpu %d ErrGroup 0x%02X ErrAction 0x%02X\n",
MEMERR_L2C_L2ESR_ERRSYN_RD(val),
MEMERR_L2C_L2ESR_ERRWAY_RD(val),
MEMERR_L2C_L2ESR_ERRCPU_RD(val),
MEMERR_L2C_L2ESR_ERRGROUP_RD(val),
MEMERR_L2C_L2ESR_ERRACTION_RD(val));
if (val & MEMERR_L2C_L2ESR_ERR_MASK)
dev_err(edac_dev->dev, "One or more correctable error\n");
if (val & MEMERR_L2C_L2ESR_MULTICERR_MASK)
dev_err(edac_dev->dev, "Multiple correctable error\n");
if (val & MEMERR_L2C_L2ESR_UCERR_MASK)
dev_err(edac_dev->dev, "One or more uncorrectable error\n");
if (val & MEMERR_L2C_L2ESR_MULTUCERR_MASK)
dev_err(edac_dev->dev, "Multiple uncorrectable error\n");
switch (MEMERR_L2C_L2ESR_ERRTYPE_RD(val)) {
case 0:
dev_err(edac_dev->dev, "Outbound SDB parity error\n");
break;
case 1:
dev_err(edac_dev->dev, "Inbound SDB parity error\n");
break;
case 2:
dev_err(edac_dev->dev, "Tag ECC error\n");
break;
case 3:
dev_err(edac_dev->dev, "Data ECC error\n");
break;
}
writel(val, pg_e + MEMERR_L2C_L2ESR_PAGE_OFFSET);
if (val & (MEMERR_L2C_L2ESR_ERR_MASK |
MEMERR_L2C_L2ESR_MULTICERR_MASK))
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
if (val & (MEMERR_L2C_L2ESR_UCERR_MASK |
MEMERR_L2C_L2ESR_MULTUCERR_MASK))
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
chk_l2c:
pg_d = ctx->pmd_csr + CPU_L2C_PAGE;
val = readl(pg_d + CPUX_L2C_L2RTOSR_PAGE_OFFSET);
if (val) {
val_lo = readl(pg_d + CPUX_L2C_L2RTOALR_PAGE_OFFSET);
val_hi = readl(pg_d + CPUX_L2C_L2RTOAHR_PAGE_OFFSET);
dev_err(edac_dev->dev,
"PMD%d L2C error L2C RTOSR 0x%08X @ 0x%08X.%08X\n",
ctx->pmd, val, val_hi, val_lo);
writel(val, pg_d + CPUX_L2C_L2RTOSR_PAGE_OFFSET);
}
}
static void xgene_edac_pmd_check(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
unsigned int pcp_hp_stat;
int i;
xgene_edac_pcp_rd(ctx->edac, PCPHPERRINTSTS, &pcp_hp_stat);
if (!((PMD0_MERR_MASK << ctx->pmd) & pcp_hp_stat))
return;
for (i = 0; i < MAX_CPU_PER_PMD; i++)
xgene_edac_pmd_l1_check(edac_dev, i);
xgene_edac_pmd_l2_check(edac_dev);
}
static void xgene_edac_pmd_cpu_hw_cfg(struct edac_device_ctl_info *edac_dev,
int cpu)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *pg_f = ctx->pmd_csr + cpu * CPU_CSR_STRIDE +
CPU_MEMERR_CPU_PAGE;
writel(0x00000301, pg_f + MEMERR_CPU_ICFECR_PAGE_OFFSET);
writel(0x00000301, pg_f + MEMERR_CPU_LSUECR_PAGE_OFFSET);
writel(0x00000101, pg_f + MEMERR_CPU_MMUECR_PAGE_OFFSET);
}
static void xgene_edac_pmd_hw_cfg(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *pg_d = ctx->pmd_csr + CPU_L2C_PAGE;
void __iomem *pg_e = ctx->pmd_csr + CPU_MEMERR_L2C_PAGE;
writel(0x00000703, pg_e + MEMERR_L2C_L2ECR_PAGE_OFFSET);
if (ctx->version > 1)
writel(0x00000119, pg_d + CPUX_L2C_L2RTOCR_PAGE_OFFSET);
}
static void xgene_edac_pmd_hw_ctl(struct edac_device_ctl_info *edac_dev,
bool enable)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
int i;
if (edac_dev->op_state == OP_RUNNING_INTERRUPT) {
if (enable)
xgene_edac_pcp_clrbits(ctx->edac, PCPHPERRINTMSK,
PMD0_MERR_MASK << ctx->pmd);
else
xgene_edac_pcp_setbits(ctx->edac, PCPHPERRINTMSK,
PMD0_MERR_MASK << ctx->pmd);
}
if (enable) {
xgene_edac_pmd_hw_cfg(edac_dev);
for (i = 0; i < MAX_CPU_PER_PMD; i++)
xgene_edac_pmd_cpu_hw_cfg(edac_dev, i);
}
}
static ssize_t xgene_edac_pmd_l1_inject_ctrl_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct edac_device_ctl_info *edac_dev = file->private_data;
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *cpux_pg_f;
int i;
for (i = 0; i < MAX_CPU_PER_PMD; i++) {
cpux_pg_f = ctx->pmd_csr + i * CPU_CSR_STRIDE +
CPU_MEMERR_CPU_PAGE;
writel(MEMERR_CPU_ICFESR_MULTCERR_MASK |
MEMERR_CPU_ICFESR_CERR_MASK,
cpux_pg_f + MEMERR_CPU_ICFESRA_PAGE_OFFSET);
writel(MEMERR_CPU_LSUESR_MULTCERR_MASK |
MEMERR_CPU_LSUESR_CERR_MASK,
cpux_pg_f + MEMERR_CPU_LSUESRA_PAGE_OFFSET);
writel(MEMERR_CPU_MMUESR_MULTCERR_MASK |
MEMERR_CPU_MMUESR_CERR_MASK,
cpux_pg_f + MEMERR_CPU_MMUESRA_PAGE_OFFSET);
}
return count;
}
static ssize_t xgene_edac_pmd_l2_inject_ctrl_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct edac_device_ctl_info *edac_dev = file->private_data;
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
void __iomem *pg_e = ctx->pmd_csr + CPU_MEMERR_L2C_PAGE;
writel(MEMERR_L2C_L2ESR_MULTUCERR_MASK |
MEMERR_L2C_L2ESR_MULTICERR_MASK |
MEMERR_L2C_L2ESR_UCERR_MASK |
MEMERR_L2C_L2ESR_ERR_MASK,
pg_e + MEMERR_L2C_L2ESRA_PAGE_OFFSET);
return count;
}
static void
xgene_edac_pmd_create_debugfs_nodes(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
struct dentry *dbgfs_dir;
char name[10];
if (!IS_ENABLED(CONFIG_EDAC_DEBUG) || !ctx->edac->dfs)
return;
snprintf(name, sizeof(name), "PMD%d", ctx->pmd);
dbgfs_dir = edac_debugfs_create_dir_at(name, ctx->edac->dfs);
if (!dbgfs_dir)
return;
edac_debugfs_create_file("l1_inject_ctrl", S_IWUSR, dbgfs_dir, edac_dev,
&xgene_edac_pmd_debug_inject_fops[0]);
edac_debugfs_create_file("l2_inject_ctrl", S_IWUSR, dbgfs_dir, edac_dev,
&xgene_edac_pmd_debug_inject_fops[1]);
}
static int xgene_edac_pmd_available(u32 efuse, int pmd)
{
return (efuse & (1 << pmd)) ? 0 : 1;
}
static int xgene_edac_pmd_add(struct xgene_edac *edac, struct device_node *np,
int version)
{
struct edac_device_ctl_info *edac_dev;
struct xgene_edac_pmd_ctx *ctx;
struct resource res;
char edac_name[10];
u32 pmd;
int rc;
u32 val;
if (!devres_open_group(edac->dev, xgene_edac_pmd_add, GFP_KERNEL))
return -ENOMEM;
if (of_property_read_u32(np, "pmd-controller", &pmd)) {
dev_err(edac->dev, "no pmd-controller property\n");
rc = -ENODEV;
goto err_group;
}
rc = regmap_read(edac->efuse_map, 0, &val);
if (rc)
goto err_group;
if (!xgene_edac_pmd_available(val, pmd)) {
rc = -ENODEV;
goto err_group;
}
snprintf(edac_name, sizeof(edac_name), "l2c%d", pmd);
edac_dev = edac_device_alloc_ctl_info(sizeof(*ctx),
edac_name, 1, "l2c", 1, 2, NULL,
0, edac_device_alloc_index());
if (!edac_dev) {
rc = -ENOMEM;
goto err_group;
}
ctx = edac_dev->pvt_info;
ctx->name = "xgene_pmd_err";
ctx->pmd = pmd;
ctx->edac = edac;
ctx->edac_dev = edac_dev;
ctx->ddev = *edac->dev;
ctx->version = version;
edac_dev->dev = &ctx->ddev;
edac_dev->ctl_name = ctx->name;
edac_dev->dev_name = ctx->name;
edac_dev->mod_name = EDAC_MOD_STR;
rc = of_address_to_resource(np, 0, &res);
if (rc < 0) {
dev_err(edac->dev, "no PMD resource address\n");
goto err_free;
}
ctx->pmd_csr = devm_ioremap_resource(edac->dev, &res);
if (IS_ERR(ctx->pmd_csr)) {
dev_err(edac->dev,
"devm_ioremap_resource failed for PMD resource address\n");
rc = PTR_ERR(ctx->pmd_csr);
goto err_free;
}
if (edac_op_state == EDAC_OPSTATE_POLL)
edac_dev->edac_check = xgene_edac_pmd_check;
xgene_edac_pmd_create_debugfs_nodes(edac_dev);
rc = edac_device_add_device(edac_dev);
if (rc > 0) {
dev_err(edac->dev, "edac_device_add_device failed\n");
rc = -ENOMEM;
goto err_free;
}
if (edac_op_state == EDAC_OPSTATE_INT)
edac_dev->op_state = OP_RUNNING_INTERRUPT;
list_add(&ctx->next, &edac->pmds);
xgene_edac_pmd_hw_ctl(edac_dev, 1);
devres_remove_group(edac->dev, xgene_edac_pmd_add);
dev_info(edac->dev, "X-Gene EDAC PMD%d registered\n", ctx->pmd);
return 0;
err_free:
edac_device_free_ctl_info(edac_dev);
err_group:
devres_release_group(edac->dev, xgene_edac_pmd_add);
return rc;
}
static int xgene_edac_pmd_remove(struct xgene_edac_pmd_ctx *pmd)
{
struct edac_device_ctl_info *edac_dev = pmd->edac_dev;
xgene_edac_pmd_hw_ctl(edac_dev, 0);
edac_device_del_device(edac_dev->dev);
edac_device_free_ctl_info(edac_dev);
return 0;
}
static bool xgene_edac_l3_promote_to_uc_err(u32 l3cesr, u32 l3celr)
{
if (l3cesr & L3C_ESR_DATATAG_MASK) {
switch (L3C_ELR_ERRSYN(l3celr)) {
case 0x13C:
case 0x0B4:
case 0x007:
case 0x00D:
case 0x00E:
case 0x019:
case 0x01A:
case 0x01C:
case 0x04E:
case 0x041:
return true;
}
} else if (L3C_ELR_ERRWAY(l3celr) == 9)
return true;
return false;
}
static void xgene_edac_l3_check(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
u32 l3cesr;
u32 l3celr;
u32 l3caelr;
u32 l3cbelr;
l3cesr = readl(ctx->dev_csr + L3C_ESR);
if (!(l3cesr & (L3C_ESR_UCERR_MASK | L3C_ESR_CERR_MASK)))
return;
if (l3cesr & L3C_ESR_UCERR_MASK)
dev_err(edac_dev->dev, "L3C uncorrectable error\n");
if (l3cesr & L3C_ESR_CERR_MASK)
dev_warn(edac_dev->dev, "L3C correctable error\n");
l3celr = readl(ctx->dev_csr + L3C_ELR);
l3caelr = readl(ctx->dev_csr + L3C_AELR);
l3cbelr = readl(ctx->dev_csr + L3C_BELR);
if (l3cesr & L3C_ESR_MULTIHIT_MASK)
dev_err(edac_dev->dev, "L3C multiple hit error\n");
if (l3cesr & L3C_ESR_UCEVICT_MASK)
dev_err(edac_dev->dev,
"L3C dropped eviction of line with error\n");
if (l3cesr & L3C_ESR_MULTIUCERR_MASK)
dev_err(edac_dev->dev, "L3C multiple uncorrectable error\n");
if (l3cesr & L3C_ESR_DATATAG_MASK)
dev_err(edac_dev->dev,
"L3C data error syndrome 0x%X group 0x%X\n",
L3C_ELR_ERRSYN(l3celr), L3C_ELR_ERRGRP(l3celr));
else
dev_err(edac_dev->dev,
"L3C tag error syndrome 0x%X Way of Tag 0x%X Agent ID 0x%X Operation type 0x%X\n",
L3C_ELR_ERRSYN(l3celr), L3C_ELR_ERRWAY(l3celr),
L3C_ELR_AGENTID(l3celr), L3C_ELR_OPTYPE(l3celr));
dev_err(edac_dev->dev, "L3C error address 0x%08X.%08X bank %d\n",
L3C_ELR_PADDRHIGH(l3celr) << 6 | (l3caelr >> 26),
(l3caelr & 0x3FFFFFFF) << 6, L3C_BELR_BANK(l3cbelr));
dev_err(edac_dev->dev,
"L3C error status register value 0x%X\n", l3cesr);
writel(0, ctx->dev_csr + L3C_ESR);
if (ctx->version <= 1 &&
xgene_edac_l3_promote_to_uc_err(l3cesr, l3celr)) {
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
return;
}
if (l3cesr & L3C_ESR_CERR_MASK)
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
if (l3cesr & L3C_ESR_UCERR_MASK)
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
}
static void xgene_edac_l3_hw_init(struct edac_device_ctl_info *edac_dev,
bool enable)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
u32 val;
val = readl(ctx->dev_csr + L3C_ECR);
val |= L3C_UCERREN | L3C_CERREN;
if (edac_dev->op_state == OP_RUNNING_INTERRUPT) {
if (enable)
val |= L3C_ECR_UCINTREN | L3C_ECR_CINTREN;
else
val &= ~(L3C_ECR_UCINTREN | L3C_ECR_CINTREN);
}
writel(val, ctx->dev_csr + L3C_ECR);
if (edac_dev->op_state == OP_RUNNING_INTERRUPT) {
if (enable) {
xgene_edac_pcp_clrbits(ctx->edac, PCPHPERRINTMSK,
L3C_UNCORR_ERR_MASK);
xgene_edac_pcp_clrbits(ctx->edac, PCPLPERRINTMSK,
L3C_CORR_ERR_MASK);
} else {
xgene_edac_pcp_setbits(ctx->edac, PCPHPERRINTMSK,
L3C_UNCORR_ERR_MASK);
xgene_edac_pcp_setbits(ctx->edac, PCPLPERRINTMSK,
L3C_CORR_ERR_MASK);
}
}
}
static ssize_t xgene_edac_l3_inject_ctrl_write(struct file *file,
const char __user *data,
size_t count, loff_t *ppos)
{
struct edac_device_ctl_info *edac_dev = file->private_data;
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
writel(0xFFFFFFFF, ctx->dev_csr + L3C_ESR);
return count;
}
static void
xgene_edac_l3_create_debugfs_nodes(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
struct dentry *dbgfs_dir;
char name[10];
if (!IS_ENABLED(CONFIG_EDAC_DEBUG) || !ctx->edac->dfs)
return;
snprintf(name, sizeof(name), "l3c%d", ctx->edac_idx);
dbgfs_dir = edac_debugfs_create_dir_at(name, ctx->edac->dfs);
if (!dbgfs_dir)
return;
debugfs_create_file("l3_inject_ctrl", S_IWUSR, dbgfs_dir, edac_dev,
&xgene_edac_l3_debug_inject_fops);
}
static int xgene_edac_l3_add(struct xgene_edac *edac, struct device_node *np,
int version)
{
struct edac_device_ctl_info *edac_dev;
struct xgene_edac_dev_ctx *ctx;
struct resource res;
void __iomem *dev_csr;
int edac_idx;
int rc = 0;
if (!devres_open_group(edac->dev, xgene_edac_l3_add, GFP_KERNEL))
return -ENOMEM;
rc = of_address_to_resource(np, 0, &res);
if (rc < 0) {
dev_err(edac->dev, "no L3 resource address\n");
goto err_release_group;
}
dev_csr = devm_ioremap_resource(edac->dev, &res);
if (IS_ERR(dev_csr)) {
dev_err(edac->dev,
"devm_ioremap_resource failed for L3 resource address\n");
rc = PTR_ERR(dev_csr);
goto err_release_group;
}
edac_idx = edac_device_alloc_index();
edac_dev = edac_device_alloc_ctl_info(sizeof(*ctx),
"l3c", 1, "l3c", 1, 0, NULL, 0,
edac_idx);
if (!edac_dev) {
rc = -ENOMEM;
goto err_release_group;
}
ctx = edac_dev->pvt_info;
ctx->dev_csr = dev_csr;
ctx->name = "xgene_l3_err";
ctx->edac_idx = edac_idx;
ctx->edac = edac;
ctx->edac_dev = edac_dev;
ctx->ddev = *edac->dev;
ctx->version = version;
edac_dev->dev = &ctx->ddev;
edac_dev->ctl_name = ctx->name;
edac_dev->dev_name = ctx->name;
edac_dev->mod_name = EDAC_MOD_STR;
if (edac_op_state == EDAC_OPSTATE_POLL)
edac_dev->edac_check = xgene_edac_l3_check;
xgene_edac_l3_create_debugfs_nodes(edac_dev);
rc = edac_device_add_device(edac_dev);
if (rc > 0) {
dev_err(edac->dev, "failed edac_device_add_device()\n");
rc = -ENOMEM;
goto err_ctl_free;
}
if (edac_op_state == EDAC_OPSTATE_INT)
edac_dev->op_state = OP_RUNNING_INTERRUPT;
list_add(&ctx->next, &edac->l3s);
xgene_edac_l3_hw_init(edac_dev, 1);
devres_remove_group(edac->dev, xgene_edac_l3_add);
dev_info(edac->dev, "X-Gene EDAC L3 registered\n");
return 0;
err_ctl_free:
edac_device_free_ctl_info(edac_dev);
err_release_group:
devres_release_group(edac->dev, xgene_edac_l3_add);
return rc;
}
static int xgene_edac_l3_remove(struct xgene_edac_dev_ctx *l3)
{
struct edac_device_ctl_info *edac_dev = l3->edac_dev;
xgene_edac_l3_hw_init(edac_dev, 0);
edac_device_del_device(l3->edac->dev);
edac_device_free_ctl_info(edac_dev);
return 0;
}
static void xgene_edac_iob_gic_report(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
u32 err_addr_lo;
u32 err_addr_hi;
u32 reg;
u32 info;
reg = readl(ctx->dev_csr + XGICTRANSERRINTSTS);
if (!reg)
goto chk_iob_err;
dev_err(edac_dev->dev, "XGIC transaction error\n");
if (reg & RD_ACCESS_ERR_MASK)
dev_err(edac_dev->dev, "XGIC read size error\n");
if (reg & M_RD_ACCESS_ERR_MASK)
dev_err(edac_dev->dev, "Multiple XGIC read size error\n");
if (reg & WR_ACCESS_ERR_MASK)
dev_err(edac_dev->dev, "XGIC write size error\n");
if (reg & M_WR_ACCESS_ERR_MASK)
dev_err(edac_dev->dev, "Multiple XGIC write size error\n");
info = readl(ctx->dev_csr + XGICTRANSERRREQINFO);
dev_err(edac_dev->dev, "XGIC %s access @ 0x%08X (0x%08X)\n",
info & REQTYPE_MASK ? "read" : "write", ERRADDR_RD(info),
info);
writel(reg, ctx->dev_csr + XGICTRANSERRINTSTS);
chk_iob_err:
reg = readl(ctx->dev_csr + GLBL_ERR_STS);
if (!reg)
return;
if (reg & SEC_ERR_MASK) {
err_addr_lo = readl(ctx->dev_csr + GLBL_SEC_ERRL);
err_addr_hi = readl(ctx->dev_csr + GLBL_SEC_ERRH);
dev_err(edac_dev->dev,
"IOB single-bit correctable memory at 0x%08X.%08X error\n",
err_addr_lo, err_addr_hi);
writel(err_addr_lo, ctx->dev_csr + GLBL_SEC_ERRL);
writel(err_addr_hi, ctx->dev_csr + GLBL_SEC_ERRH);
}
if (reg & MSEC_ERR_MASK) {
err_addr_lo = readl(ctx->dev_csr + GLBL_MSEC_ERRL);
err_addr_hi = readl(ctx->dev_csr + GLBL_MSEC_ERRH);
dev_err(edac_dev->dev,
"IOB multiple single-bit correctable memory at 0x%08X.%08X error\n",
err_addr_lo, err_addr_hi);
writel(err_addr_lo, ctx->dev_csr + GLBL_MSEC_ERRL);
writel(err_addr_hi, ctx->dev_csr + GLBL_MSEC_ERRH);
}
if (reg & (SEC_ERR_MASK | MSEC_ERR_MASK))
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
if (reg & DED_ERR_MASK) {
err_addr_lo = readl(ctx->dev_csr + GLBL_DED_ERRL);
err_addr_hi = readl(ctx->dev_csr + GLBL_DED_ERRH);
dev_err(edac_dev->dev,
"IOB double-bit uncorrectable memory at 0x%08X.%08X error\n",
err_addr_lo, err_addr_hi);
writel(err_addr_lo, ctx->dev_csr + GLBL_DED_ERRL);
writel(err_addr_hi, ctx->dev_csr + GLBL_DED_ERRH);
}
if (reg & MDED_ERR_MASK) {
err_addr_lo = readl(ctx->dev_csr + GLBL_MDED_ERRL);
err_addr_hi = readl(ctx->dev_csr + GLBL_MDED_ERRH);
dev_err(edac_dev->dev,
"Multiple IOB double-bit uncorrectable memory at 0x%08X.%08X error\n",
err_addr_lo, err_addr_hi);
writel(err_addr_lo, ctx->dev_csr + GLBL_MDED_ERRL);
writel(err_addr_hi, ctx->dev_csr + GLBL_MDED_ERRH);
}
if (reg & (DED_ERR_MASK | MDED_ERR_MASK))
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
}
static void xgene_edac_rb_report(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
u32 err_addr_lo;
u32 err_addr_hi;
u32 reg;
if (!ctx->edac->rb_map)
goto rb_skip;
if (regmap_read(ctx->edac->rb_map, RBCSR, &reg))
return;
if (reg & STICKYERR_MASK) {
bool write;
u32 address;
dev_err(edac_dev->dev, "IOB bus access error(s)\n");
if (regmap_read(ctx->edac->rb_map, RBEIR, &reg))
return;
write = reg & WRITE_ACCESS_MASK ? 1 : 0;
address = RBERRADDR_RD(reg);
if (reg & AGENT_OFFLINE_ERR_MASK)
dev_err(edac_dev->dev,
"IOB bus %s access to offline agent error\n",
write ? "write" : "read");
if (reg & UNIMPL_RBPAGE_ERR_MASK)
dev_err(edac_dev->dev,
"IOB bus %s access to unimplemented page error\n",
write ? "write" : "read");
if (reg & WORD_ALIGNED_ERR_MASK)
dev_err(edac_dev->dev,
"IOB bus %s word aligned access error\n",
write ? "write" : "read");
if (reg & PAGE_ACCESS_ERR_MASK)
dev_err(edac_dev->dev,
"IOB bus %s to page out of range access error\n",
write ? "write" : "read");
if (regmap_write(ctx->edac->rb_map, RBEIR, 0))
return;
if (regmap_write(ctx->edac->rb_map, RBCSR, 0))
return;
}
rb_skip:
reg = readl(ctx->dev_csr + IOBBATRANSERRINTSTS);
if (!reg)
return;
dev_err(edac_dev->dev, "IOB bridge agent (BA) transaction error\n");
if (reg & WRERR_RESP_MASK)
dev_err(edac_dev->dev, "IOB BA write response error\n");
if (reg & M_WRERR_RESP_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA write response error\n");
if (reg & XGIC_POISONED_REQ_MASK)
dev_err(edac_dev->dev, "IOB BA XGIC poisoned write error\n");
if (reg & M_XGIC_POISONED_REQ_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA XGIC poisoned write error\n");
if (reg & RBM_POISONED_REQ_MASK)
dev_err(edac_dev->dev, "IOB BA RBM poisoned write error\n");
if (reg & M_RBM_POISONED_REQ_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA RBM poisoned write error\n");
if (reg & WDATA_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB BA write error\n");
if (reg & M_WDATA_CORRUPT_MASK)
dev_err(edac_dev->dev, "Multiple IOB BA write error\n");
if (reg & TRANS_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB BA transaction error\n");
if (reg & M_TRANS_CORRUPT_MASK)
dev_err(edac_dev->dev, "Multiple IOB BA transaction error\n");
if (reg & RIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev,
"IOB BA RDIDRAM read transaction ID error\n");
if (reg & M_RIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA RDIDRAM read transaction ID error\n");
if (reg & WIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev,
"IOB BA RDIDRAM write transaction ID error\n");
if (reg & M_WIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA RDIDRAM write transaction ID error\n");
if (reg & ILLEGAL_ACCESS_MASK)
dev_err(edac_dev->dev,
"IOB BA XGIC/RB illegal access error\n");
if (reg & M_ILLEGAL_ACCESS_MASK)
dev_err(edac_dev->dev,
"Multiple IOB BA XGIC/RB illegal access error\n");
err_addr_lo = readl(ctx->dev_csr + IOBBATRANSERRREQINFOL);
err_addr_hi = readl(ctx->dev_csr + IOBBATRANSERRREQINFOH);
dev_err(edac_dev->dev, "IOB BA %s access at 0x%02X.%08X (0x%08X)\n",
REQTYPE_F2_RD(err_addr_hi) ? "read" : "write",
ERRADDRH_F2_RD(err_addr_hi), err_addr_lo, err_addr_hi);
if (reg & WRERR_RESP_MASK)
dev_err(edac_dev->dev, "IOB BA requestor ID 0x%08X\n",
readl(ctx->dev_csr + IOBBATRANSERRCSWREQID));
writel(reg, ctx->dev_csr + IOBBATRANSERRINTSTS);
}
static void xgene_edac_pa_report(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
u32 err_addr_lo;
u32 err_addr_hi;
u32 reg;
reg = readl(ctx->dev_csr + IOBPATRANSERRINTSTS);
if (!reg)
goto chk_iob_axi0;
dev_err(edac_dev->dev, "IOB processing agent (PA) transaction error\n");
if (reg & IOBPA_RDATA_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB PA read data RAM error\n");
if (reg & IOBPA_M_RDATA_CORRUPT_MASK)
dev_err(edac_dev->dev,
"Multiple IOB PA read data RAM error\n");
if (reg & IOBPA_WDATA_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB PA write data RAM error\n");
if (reg & IOBPA_M_WDATA_CORRUPT_MASK)
dev_err(edac_dev->dev,
"Multiple IOB PA write data RAM error\n");
if (reg & IOBPA_TRANS_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB PA transaction error\n");
if (reg & IOBPA_M_TRANS_CORRUPT_MASK)
dev_err(edac_dev->dev, "Multiple IOB PA transaction error\n");
if (reg & IOBPA_REQIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev, "IOB PA transaction ID RAM error\n");
if (reg & IOBPA_M_REQIDRAM_CORRUPT_MASK)
dev_err(edac_dev->dev,
"Multiple IOB PA transaction ID RAM error\n");
writel(reg, ctx->dev_csr + IOBPATRANSERRINTSTS);
chk_iob_axi0:
reg = readl(ctx->dev_csr + IOBAXIS0TRANSERRINTSTS);
if (!reg)
goto chk_iob_axi1;
err_addr_lo = readl(ctx->dev_csr + IOBAXIS0TRANSERRREQINFOL);
err_addr_hi = readl(ctx->dev_csr + IOBAXIS0TRANSERRREQINFOH);
dev_err(edac_dev->dev,
"%sAXI slave 0 illegal %s access @ 0x%02X.%08X (0x%08X)\n",
reg & IOBAXIS0_M_ILLEGAL_ACCESS_MASK ? "Multiple " : "",
REQTYPE_RD(err_addr_hi) ? "read" : "write",
ERRADDRH_RD(err_addr_hi), err_addr_lo, err_addr_hi);
writel(reg, ctx->dev_csr + IOBAXIS0TRANSERRINTSTS);
chk_iob_axi1:
reg = readl(ctx->dev_csr + IOBAXIS1TRANSERRINTSTS);
if (!reg)
return;
err_addr_lo = readl(ctx->dev_csr + IOBAXIS1TRANSERRREQINFOL);
err_addr_hi = readl(ctx->dev_csr + IOBAXIS1TRANSERRREQINFOH);
dev_err(edac_dev->dev,
"%sAXI slave 1 illegal %s access @ 0x%02X.%08X (0x%08X)\n",
reg & IOBAXIS0_M_ILLEGAL_ACCESS_MASK ? "Multiple " : "",
REQTYPE_RD(err_addr_hi) ? "read" : "write",
ERRADDRH_RD(err_addr_hi), err_addr_lo, err_addr_hi);
writel(reg, ctx->dev_csr + IOBAXIS1TRANSERRINTSTS);
}
static void xgene_edac_soc_check(struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
const char * const *soc_mem_err = NULL;
u32 pcp_hp_stat;
u32 pcp_lp_stat;
u32 reg;
int i;
xgene_edac_pcp_rd(ctx->edac, PCPHPERRINTSTS, &pcp_hp_stat);
xgene_edac_pcp_rd(ctx->edac, PCPLPERRINTSTS, &pcp_lp_stat);
xgene_edac_pcp_rd(ctx->edac, MEMERRINTSTS, &reg);
if (!((pcp_hp_stat & (IOB_PA_ERR_MASK | IOB_BA_ERR_MASK |
IOB_XGIC_ERR_MASK | IOB_RB_ERR_MASK)) ||
(pcp_lp_stat & CSW_SWITCH_TRACE_ERR_MASK) || reg))
return;
if (pcp_hp_stat & IOB_XGIC_ERR_MASK)
xgene_edac_iob_gic_report(edac_dev);
if (pcp_hp_stat & (IOB_RB_ERR_MASK | IOB_BA_ERR_MASK))
xgene_edac_rb_report(edac_dev);
if (pcp_hp_stat & IOB_PA_ERR_MASK)
xgene_edac_pa_report(edac_dev);
if (pcp_lp_stat & CSW_SWITCH_TRACE_ERR_MASK) {
dev_info(edac_dev->dev,
"CSW switch trace correctable memory parity error\n");
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
}
if (!reg)
return;
if (ctx->version == 1)
soc_mem_err = soc_mem_err_v1;
if (!soc_mem_err) {
dev_err(edac_dev->dev, "SoC memory parity error 0x%08X\n",
reg);
edac_device_handle_ue(edac_dev, 0, 0, edac_dev->ctl_name);
return;
}
for (i = 0; i < 31; i++) {
if (reg & (1 << i)) {
dev_err(edac_dev->dev, "%s memory parity error\n",
soc_mem_err[i]);
edac_device_handle_ue(edac_dev, 0, 0,
edac_dev->ctl_name);
}
}
}
static void xgene_edac_soc_hw_init(struct edac_device_ctl_info *edac_dev,
bool enable)
{
struct xgene_edac_dev_ctx *ctx = edac_dev->pvt_info;
if (edac_dev->op_state == OP_RUNNING_INTERRUPT) {
if (enable) {
xgene_edac_pcp_clrbits(ctx->edac, PCPHPERRINTMSK,
IOB_PA_ERR_MASK |
IOB_BA_ERR_MASK |
IOB_XGIC_ERR_MASK |
IOB_RB_ERR_MASK);
xgene_edac_pcp_clrbits(ctx->edac, PCPLPERRINTMSK,
CSW_SWITCH_TRACE_ERR_MASK);
} else {
xgene_edac_pcp_setbits(ctx->edac, PCPHPERRINTMSK,
IOB_PA_ERR_MASK |
IOB_BA_ERR_MASK |
IOB_XGIC_ERR_MASK |
IOB_RB_ERR_MASK);
xgene_edac_pcp_setbits(ctx->edac, PCPLPERRINTMSK,
CSW_SWITCH_TRACE_ERR_MASK);
}
writel(enable ? 0x0 : 0xFFFFFFFF,
ctx->dev_csr + IOBAXIS0TRANSERRINTMSK);
writel(enable ? 0x0 : 0xFFFFFFFF,
ctx->dev_csr + IOBAXIS1TRANSERRINTMSK);
writel(enable ? 0x0 : 0xFFFFFFFF,
ctx->dev_csr + XGICTRANSERRINTMSK);
xgene_edac_pcp_setbits(ctx->edac, MEMERRINTMSK,
enable ? 0x0 : 0xFFFFFFFF);
}
}
static int xgene_edac_soc_add(struct xgene_edac *edac, struct device_node *np,
int version)
{
struct edac_device_ctl_info *edac_dev;
struct xgene_edac_dev_ctx *ctx;
void __iomem *dev_csr;
struct resource res;
int edac_idx;
int rc;
if (!devres_open_group(edac->dev, xgene_edac_soc_add, GFP_KERNEL))
return -ENOMEM;
rc = of_address_to_resource(np, 0, &res);
if (rc < 0) {
dev_err(edac->dev, "no SoC resource address\n");
goto err_release_group;
}
dev_csr = devm_ioremap_resource(edac->dev, &res);
if (IS_ERR(dev_csr)) {
dev_err(edac->dev,
"devm_ioremap_resource failed for soc resource address\n");
rc = PTR_ERR(dev_csr);
goto err_release_group;
}
edac_idx = edac_device_alloc_index();
edac_dev = edac_device_alloc_ctl_info(sizeof(*ctx),
"SOC", 1, "SOC", 1, 2, NULL, 0,
edac_idx);
if (!edac_dev) {
rc = -ENOMEM;
goto err_release_group;
}
ctx = edac_dev->pvt_info;
ctx->dev_csr = dev_csr;
ctx->name = "xgene_soc_err";
ctx->edac_idx = edac_idx;
ctx->edac = edac;
ctx->edac_dev = edac_dev;
ctx->ddev = *edac->dev;
ctx->version = version;
edac_dev->dev = &ctx->ddev;
edac_dev->ctl_name = ctx->name;
edac_dev->dev_name = ctx->name;
edac_dev->mod_name = EDAC_MOD_STR;
if (edac_op_state == EDAC_OPSTATE_POLL)
edac_dev->edac_check = xgene_edac_soc_check;
rc = edac_device_add_device(edac_dev);
if (rc > 0) {
dev_err(edac->dev, "failed edac_device_add_device()\n");
rc = -ENOMEM;
goto err_ctl_free;
}
if (edac_op_state == EDAC_OPSTATE_INT)
edac_dev->op_state = OP_RUNNING_INTERRUPT;
list_add(&ctx->next, &edac->socs);
xgene_edac_soc_hw_init(edac_dev, 1);
devres_remove_group(edac->dev, xgene_edac_soc_add);
dev_info(edac->dev, "X-Gene EDAC SoC registered\n");
return 0;
err_ctl_free:
edac_device_free_ctl_info(edac_dev);
err_release_group:
devres_release_group(edac->dev, xgene_edac_soc_add);
return rc;
}
static int xgene_edac_soc_remove(struct xgene_edac_dev_ctx *soc)
{
struct edac_device_ctl_info *edac_dev = soc->edac_dev;
xgene_edac_soc_hw_init(edac_dev, 0);
edac_device_del_device(soc->edac->dev);
edac_device_free_ctl_info(edac_dev);
return 0;
}
static irqreturn_t xgene_edac_isr(int irq, void *dev_id)
{
struct xgene_edac *ctx = dev_id;
struct xgene_edac_pmd_ctx *pmd;
struct xgene_edac_dev_ctx *node;
unsigned int pcp_hp_stat;
unsigned int pcp_lp_stat;
xgene_edac_pcp_rd(ctx, PCPHPERRINTSTS, &pcp_hp_stat);
xgene_edac_pcp_rd(ctx, PCPLPERRINTSTS, &pcp_lp_stat);
if ((MCU_UNCORR_ERR_MASK & pcp_hp_stat) ||
(MCU_CTL_ERR_MASK & pcp_hp_stat) ||
(MCU_CORR_ERR_MASK & pcp_lp_stat)) {
struct xgene_edac_mc_ctx *mcu;
list_for_each_entry(mcu, &ctx->mcus, next)
xgene_edac_mc_check(mcu->mci);
}
list_for_each_entry(pmd, &ctx->pmds, next) {
if ((PMD0_MERR_MASK << pmd->pmd) & pcp_hp_stat)
xgene_edac_pmd_check(pmd->edac_dev);
}
list_for_each_entry(node, &ctx->l3s, next)
xgene_edac_l3_check(node->edac_dev);
list_for_each_entry(node, &ctx->socs, next)
xgene_edac_soc_check(node->edac_dev);
return IRQ_HANDLED;
}
static int xgene_edac_probe(struct platform_device *pdev)
{
struct xgene_edac *edac;
struct device_node *child;
struct resource *res;
int rc;
edac = devm_kzalloc(&pdev->dev, sizeof(*edac), GFP_KERNEL);
if (!edac)
return -ENOMEM;
edac->dev = &pdev->dev;
platform_set_drvdata(pdev, edac);
INIT_LIST_HEAD(&edac->mcus);
INIT_LIST_HEAD(&edac->pmds);
INIT_LIST_HEAD(&edac->l3s);
INIT_LIST_HEAD(&edac->socs);
spin_lock_init(&edac->lock);
mutex_init(&edac->mc_lock);
edac->csw_map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"regmap-csw");
if (IS_ERR(edac->csw_map)) {
dev_err(edac->dev, "unable to get syscon regmap csw\n");
rc = PTR_ERR(edac->csw_map);
goto out_err;
}
edac->mcba_map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"regmap-mcba");
if (IS_ERR(edac->mcba_map)) {
dev_err(edac->dev, "unable to get syscon regmap mcba\n");
rc = PTR_ERR(edac->mcba_map);
goto out_err;
}
edac->mcbb_map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"regmap-mcbb");
if (IS_ERR(edac->mcbb_map)) {
dev_err(edac->dev, "unable to get syscon regmap mcbb\n");
rc = PTR_ERR(edac->mcbb_map);
goto out_err;
}
edac->efuse_map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"regmap-efuse");
if (IS_ERR(edac->efuse_map)) {
dev_err(edac->dev, "unable to get syscon regmap efuse\n");
rc = PTR_ERR(edac->efuse_map);
goto out_err;
}
edac->rb_map = syscon_regmap_lookup_by_phandle(pdev->dev.of_node,
"regmap-rb");
if (IS_ERR(edac->rb_map)) {
dev_warn(edac->dev, "missing syscon regmap rb\n");
edac->rb_map = NULL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
edac->pcp_csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(edac->pcp_csr)) {
dev_err(&pdev->dev, "no PCP resource address\n");
rc = PTR_ERR(edac->pcp_csr);
goto out_err;
}
if (edac_op_state == EDAC_OPSTATE_INT) {
int irq;
int i;
for (i = 0; i < 3; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
rc = -EINVAL;
goto out_err;
}
rc = devm_request_irq(&pdev->dev, irq,
xgene_edac_isr, IRQF_SHARED,
dev_name(&pdev->dev), edac);
if (rc) {
dev_err(&pdev->dev,
"Could not request IRQ %d\n", irq);
goto out_err;
}
}
}
edac->dfs = edac_debugfs_create_dir(pdev->dev.kobj.name);
for_each_child_of_node(pdev->dev.of_node, child) {
if (!of_device_is_available(child))
continue;
if (of_device_is_compatible(child, "apm,xgene-edac-mc"))
xgene_edac_mc_add(edac, child);
if (of_device_is_compatible(child, "apm,xgene-edac-pmd"))
xgene_edac_pmd_add(edac, child, 1);
if (of_device_is_compatible(child, "apm,xgene-edac-pmd-v2"))
xgene_edac_pmd_add(edac, child, 2);
if (of_device_is_compatible(child, "apm,xgene-edac-l3"))
xgene_edac_l3_add(edac, child, 1);
if (of_device_is_compatible(child, "apm,xgene-edac-l3-v2"))
xgene_edac_l3_add(edac, child, 2);
if (of_device_is_compatible(child, "apm,xgene-edac-soc"))
xgene_edac_soc_add(edac, child, 0);
if (of_device_is_compatible(child, "apm,xgene-edac-soc-v1"))
xgene_edac_soc_add(edac, child, 1);
}
return 0;
out_err:
return rc;
}
static int xgene_edac_remove(struct platform_device *pdev)
{
struct xgene_edac *edac = dev_get_drvdata(&pdev->dev);
struct xgene_edac_mc_ctx *mcu;
struct xgene_edac_mc_ctx *temp_mcu;
struct xgene_edac_pmd_ctx *pmd;
struct xgene_edac_pmd_ctx *temp_pmd;
struct xgene_edac_dev_ctx *node;
struct xgene_edac_dev_ctx *temp_node;
list_for_each_entry_safe(mcu, temp_mcu, &edac->mcus, next)
xgene_edac_mc_remove(mcu);
list_for_each_entry_safe(pmd, temp_pmd, &edac->pmds, next)
xgene_edac_pmd_remove(pmd);
list_for_each_entry_safe(node, temp_node, &edac->l3s, next)
xgene_edac_l3_remove(node);
list_for_each_entry_safe(node, temp_node, &edac->socs, next)
xgene_edac_soc_remove(node);
return 0;
}
static int __init xgene_edac_init(void)
{
int rc;
switch (edac_op_state) {
case EDAC_OPSTATE_POLL:
case EDAC_OPSTATE_INT:
break;
default:
edac_op_state = EDAC_OPSTATE_INT;
break;
}
rc = platform_driver_register(&xgene_edac_driver);
if (rc) {
edac_printk(KERN_ERR, EDAC_MOD_STR,
"EDAC fails to register\n");
goto reg_failed;
}
return 0;
reg_failed:
return rc;
}
static void __exit xgene_edac_exit(void)
{
platform_driver_unregister(&xgene_edac_driver);
}
