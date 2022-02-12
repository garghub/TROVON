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
#ifdef CONFIG_EDAC_DEBUG
if (!mci->debugfs)
return;
debugfs_create_file("inject_ctrl", S_IWUSR, mci->debugfs, mci,
&xgene_edac_mc_debug_inject_fops);
#endif
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
mci->mod_ver = "0.1";
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
if (val) {
dev_err(edac_dev->dev,
"CPU%d L1 memory error ICF 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_ICFESR_ERRWAY_RD(val),
MEMERR_CPU_ICFESR_ERRINDEX_RD(val),
MEMERR_CPU_ICFESR_ERRINFO_RD(val));
if (val & MEMERR_CPU_ICFESR_CERR_MASK)
dev_err(edac_dev->dev,
"One or more correctable error\n");
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
edac_device_handle_ce(edac_dev, 0, 0,
edac_dev->ctl_name);
}
val = readl(pg_f + MEMERR_CPU_LSUESR_PAGE_OFFSET);
if (val) {
dev_err(edac_dev->dev,
"CPU%d memory error LSU 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_LSUESR_ERRWAY_RD(val),
MEMERR_CPU_LSUESR_ERRINDEX_RD(val),
MEMERR_CPU_LSUESR_ERRINFO_RD(val));
if (val & MEMERR_CPU_LSUESR_CERR_MASK)
dev_err(edac_dev->dev,
"One or more correctable error\n");
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
edac_device_handle_ce(edac_dev, 0, 0,
edac_dev->ctl_name);
}
val = readl(pg_f + MEMERR_CPU_MMUESR_PAGE_OFFSET);
if (val) {
dev_err(edac_dev->dev,
"CPU%d memory error MMU 0x%08X Way 0x%02X Index 0x%02X Info 0x%02X %s\n",
ctx->pmd * MAX_CPU_PER_PMD + cpu_idx, val,
MEMERR_CPU_MMUESR_ERRWAY_RD(val),
MEMERR_CPU_MMUESR_ERRINDEX_RD(val),
MEMERR_CPU_MMUESR_ERRINFO_RD(val),
val & MEMERR_CPU_MMUESR_ERRREQSTR_LSU_MASK ? "LSU" :
"ICF");
if (val & MEMERR_CPU_MMUESR_CERR_MASK)
dev_err(edac_dev->dev,
"One or more correctable error\n");
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
dev_err(edac_dev->dev,
"TMO operation single bank error\n");
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
dev_err(edac_dev->dev,
"TMO operation multiple bank error\n");
break;
}
writel(val, pg_f + MEMERR_CPU_MMUESR_PAGE_OFFSET);
edac_device_handle_ce(edac_dev, 0, 0, edac_dev->ctl_name);
}
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
if (val) {
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
dev_err(edac_dev->dev,
"One or more correctable error\n");
if (val & MEMERR_L2C_L2ESR_MULTICERR_MASK)
dev_err(edac_dev->dev, "Multiple correctable error\n");
if (val & MEMERR_L2C_L2ESR_UCERR_MASK)
dev_err(edac_dev->dev,
"One or more uncorrectable error\n");
if (val & MEMERR_L2C_L2ESR_MULTUCERR_MASK)
dev_err(edac_dev->dev,
"Multiple uncorrectable error\n");
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
edac_device_handle_ce(edac_dev, 0, 0,
edac_dev->ctl_name);
if (val & (MEMERR_L2C_L2ESR_UCERR_MASK |
MEMERR_L2C_L2ESR_MULTUCERR_MASK))
edac_device_handle_ue(edac_dev, 0, 0,
edac_dev->ctl_name);
}
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
static void xgene_edac_pmd_create_debugfs_nodes(
struct edac_device_ctl_info *edac_dev)
{
struct xgene_edac_pmd_ctx *ctx = edac_dev->pvt_info;
struct dentry *edac_debugfs;
char name[30];
if (!IS_ENABLED(CONFIG_EDAC_DEBUG))
return;
if (!ctx->edac->dfs) {
ctx->edac->dfs = debugfs_create_dir(edac_dev->dev->kobj.name,
NULL);
if (!ctx->edac->dfs)
return;
}
sprintf(name, "PMD%d", ctx->pmd);
edac_debugfs = debugfs_create_dir(name, ctx->edac->dfs);
if (!edac_debugfs)
return;
debugfs_create_file("l1_inject_ctrl", S_IWUSR, edac_debugfs, edac_dev,
&xgene_edac_pmd_debug_inject_fops[0]);
debugfs_create_file("l2_inject_ctrl", S_IWUSR, edac_debugfs, edac_dev,
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
sprintf(edac_name, "l2c%d", pmd);
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
static irqreturn_t xgene_edac_isr(int irq, void *dev_id)
{
struct xgene_edac *ctx = dev_id;
struct xgene_edac_pmd_ctx *pmd;
unsigned int pcp_hp_stat;
unsigned int pcp_lp_stat;
xgene_edac_pcp_rd(ctx, PCPHPERRINTSTS, &pcp_hp_stat);
xgene_edac_pcp_rd(ctx, PCPLPERRINTSTS, &pcp_lp_stat);
if ((MCU_UNCORR_ERR_MASK & pcp_hp_stat) ||
(MCU_CTL_ERR_MASK & pcp_hp_stat) ||
(MCU_CORR_ERR_MASK & pcp_lp_stat)) {
struct xgene_edac_mc_ctx *mcu;
list_for_each_entry(mcu, &ctx->mcus, next) {
xgene_edac_mc_check(mcu->mci);
}
}
list_for_each_entry(pmd, &ctx->pmds, next) {
if ((PMD0_MERR_MASK << pmd->pmd) & pcp_hp_stat)
xgene_edac_pmd_check(pmd->edac_dev);
}
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
for_each_child_of_node(pdev->dev.of_node, child) {
if (!of_device_is_available(child))
continue;
if (of_device_is_compatible(child, "apm,xgene-edac-mc"))
xgene_edac_mc_add(edac, child);
if (of_device_is_compatible(child, "apm,xgene-edac-pmd"))
xgene_edac_pmd_add(edac, child, 1);
if (of_device_is_compatible(child, "apm,xgene-edac-pmd-v2"))
xgene_edac_pmd_add(edac, child, 2);
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
list_for_each_entry_safe(mcu, temp_mcu, &edac->mcus, next) {
xgene_edac_mc_remove(mcu);
}
list_for_each_entry_safe(pmd, temp_pmd, &edac->pmds, next) {
xgene_edac_pmd_remove(pmd);
}
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
