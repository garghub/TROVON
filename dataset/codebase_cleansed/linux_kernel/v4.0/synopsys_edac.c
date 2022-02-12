static int synps_edac_geterror_info(void __iomem *base,
struct synps_ecc_status *p)
{
u32 regval, clearval = 0;
regval = readl(base + STAT_OFST);
if (!regval)
return 1;
p->ce_cnt = (regval & STAT_CECNT_MASK) >> STAT_CECNT_SHIFT;
p->ue_cnt = regval & STAT_UECNT_MASK;
regval = readl(base + CE_LOG_OFST);
if (!(p->ce_cnt && (regval & LOG_VALID)))
goto ue_err;
p->ceinfo.bitpos = (regval & CE_LOG_BITPOS_MASK) >> CE_LOG_BITPOS_SHIFT;
regval = readl(base + CE_ADDR_OFST);
p->ceinfo.row = (regval & ADDR_ROW_MASK) >> ADDR_ROW_SHIFT;
p->ceinfo.col = regval & ADDR_COL_MASK;
p->ceinfo.bank = (regval & ADDR_BANK_MASK) >> ADDR_BANK_SHIFT;
p->ceinfo.data = readl(base + CE_DATA_31_0_OFST);
edac_dbg(3, "ce bit position: %d data: %d\n", p->ceinfo.bitpos,
p->ceinfo.data);
clearval = ECC_CTRL_CLR_CE_ERR;
ue_err:
regval = readl(base + UE_LOG_OFST);
if (!(p->ue_cnt && (regval & LOG_VALID)))
goto out;
regval = readl(base + UE_ADDR_OFST);
p->ueinfo.row = (regval & ADDR_ROW_MASK) >> ADDR_ROW_SHIFT;
p->ueinfo.col = regval & ADDR_COL_MASK;
p->ueinfo.bank = (regval & ADDR_BANK_MASK) >> ADDR_BANK_SHIFT;
p->ueinfo.data = readl(base + UE_DATA_31_0_OFST);
clearval |= ECC_CTRL_CLR_UE_ERR;
out:
writel(clearval, base + ECC_CTRL_OFST);
writel(0x0, base + ECC_CTRL_OFST);
return 0;
}
static void synps_edac_handle_error(struct mem_ctl_info *mci,
struct synps_ecc_status *p)
{
struct synps_edac_priv *priv = mci->pvt_info;
struct ecc_error_info *pinf;
if (p->ce_cnt) {
pinf = &p->ceinfo;
snprintf(priv->message, SYNPS_EDAC_MSG_SIZE,
"DDR ECC error type :%s Row %d Bank %d Col %d ",
"CE", pinf->row, pinf->bank, pinf->col);
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci,
p->ce_cnt, 0, 0, 0, 0, 0, -1,
priv->message, "");
}
if (p->ue_cnt) {
pinf = &p->ueinfo;
snprintf(priv->message, SYNPS_EDAC_MSG_SIZE,
"DDR ECC error type :%s Row %d Bank %d Col %d ",
"UE", pinf->row, pinf->bank, pinf->col);
edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci,
p->ue_cnt, 0, 0, 0, 0, 0, -1,
priv->message, "");
}
memset(p, 0, sizeof(*p));
}
static void synps_edac_check(struct mem_ctl_info *mci)
{
struct synps_edac_priv *priv = mci->pvt_info;
int status;
status = synps_edac_geterror_info(priv->baseaddr, &priv->stat);
if (status)
return;
priv->ce_cnt += priv->stat.ce_cnt;
priv->ue_cnt += priv->stat.ue_cnt;
synps_edac_handle_error(mci, &priv->stat);
edac_dbg(3, "Total error count ce %d ue %d\n",
priv->ce_cnt, priv->ue_cnt);
}
static enum dev_type synps_edac_get_dtype(const void __iomem *base)
{
enum dev_type dt;
u32 width;
width = readl(base + CTRL_OFST);
width = (width & CTRL_BW_MASK) >> CTRL_BW_SHIFT;
switch (width) {
case DDRCTL_WDTH_16:
dt = DEV_X2;
break;
case DDRCTL_WDTH_32:
dt = DEV_X4;
break;
default:
dt = DEV_UNKNOWN;
}
return dt;
}
static bool synps_edac_get_eccstate(void __iomem *base)
{
enum dev_type dt;
u32 ecctype;
bool state = false;
dt = synps_edac_get_dtype(base);
if (dt == DEV_UNKNOWN)
return state;
ecctype = readl(base + SCRUB_OFST) & SCRUB_MODE_MASK;
if ((ecctype == SCRUB_MODE_SECDED) && (dt == DEV_X2))
state = true;
return state;
}
static u32 synps_edac_get_memsize(void)
{
struct sysinfo inf;
si_meminfo(&inf);
return inf.totalram * inf.mem_unit;
}
static enum mem_type synps_edac_get_mtype(const void __iomem *base)
{
enum mem_type mt;
u32 memtype;
memtype = readl(base + T_ZQ_OFST);
if (memtype & T_ZQ_DDRMODE_MASK)
mt = MEM_DDR3;
else
mt = MEM_DDR2;
return mt;
}
static int synps_edac_init_csrows(struct mem_ctl_info *mci)
{
struct csrow_info *csi;
struct dimm_info *dimm;
struct synps_edac_priv *priv = mci->pvt_info;
u32 size;
int row, j;
for (row = 0; row < mci->nr_csrows; row++) {
csi = mci->csrows[row];
size = synps_edac_get_memsize();
for (j = 0; j < csi->nr_channels; j++) {
dimm = csi->channels[j]->dimm;
dimm->edac_mode = EDAC_FLAG_SECDED;
dimm->mtype = synps_edac_get_mtype(priv->baseaddr);
dimm->nr_pages = (size >> PAGE_SHIFT) / csi->nr_channels;
dimm->grain = SYNPS_EDAC_ERR_GRAIN;
dimm->dtype = synps_edac_get_dtype(priv->baseaddr);
}
}
return 0;
}
static int synps_edac_mc_init(struct mem_ctl_info *mci,
struct platform_device *pdev)
{
int status;
struct synps_edac_priv *priv;
mci->pdev = &pdev->dev;
priv = mci->pvt_info;
platform_set_drvdata(pdev, mci);
mci->mtype_cap = MEM_FLAG_DDR3 | MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_NONE | EDAC_FLAG_SECDED;
mci->scrub_cap = SCRUB_HW_SRC;
mci->scrub_mode = SCRUB_NONE;
mci->edac_cap = EDAC_FLAG_SECDED;
mci->ctl_name = "synps_ddr_controller";
mci->dev_name = SYNPS_EDAC_MOD_STRING;
mci->mod_name = SYNPS_EDAC_MOD_VER;
mci->mod_ver = "1";
edac_op_state = EDAC_OPSTATE_POLL;
mci->edac_check = synps_edac_check;
mci->ctl_page_to_phys = NULL;
status = synps_edac_init_csrows(mci);
return status;
}
static int synps_edac_mc_probe(struct platform_device *pdev)
{
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct synps_edac_priv *priv;
int rc;
struct resource *res;
void __iomem *baseaddr;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
baseaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(baseaddr))
return PTR_ERR(baseaddr);
if (!synps_edac_get_eccstate(baseaddr)) {
edac_printk(KERN_INFO, EDAC_MC, "ECC not enabled\n");
return -ENXIO;
}
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = SYNPS_EDAC_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = SYNPS_EDAC_NR_CHANS;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(0, ARRAY_SIZE(layers), layers,
sizeof(struct synps_edac_priv));
if (!mci) {
edac_printk(KERN_ERR, EDAC_MC,
"Failed memory allocation for mc instance\n");
return -ENOMEM;
}
priv = mci->pvt_info;
priv->baseaddr = baseaddr;
rc = synps_edac_mc_init(mci, pdev);
if (rc) {
edac_printk(KERN_ERR, EDAC_MC,
"Failed to initialize instance\n");
goto free_edac_mc;
}
rc = edac_mc_add_mc(mci);
if (rc) {
edac_printk(KERN_ERR, EDAC_MC,
"Failed to register with EDAC core\n");
goto free_edac_mc;
}
writel(0x0, baseaddr + ECC_CTRL_OFST);
return rc;
free_edac_mc:
edac_mc_free(mci);
return rc;
}
static int synps_edac_mc_remove(struct platform_device *pdev)
{
struct mem_ctl_info *mci = platform_get_drvdata(pdev);
edac_mc_del_mc(&pdev->dev);
edac_mc_free(mci);
return 0;
}
