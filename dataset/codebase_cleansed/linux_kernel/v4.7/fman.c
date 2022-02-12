static irqreturn_t fman_exceptions(struct fman *fman,
enum fman_exceptions exception)
{
dev_dbg(fman->dev, "%s: FMan[%d] exception %d\n",
__func__, fman->state->fm_id, exception);
return IRQ_HANDLED;
}
static irqreturn_t fman_bus_error(struct fman *fman, u8 __maybe_unused port_id,
u64 __maybe_unused addr,
u8 __maybe_unused tnum,
u16 __maybe_unused liodn)
{
dev_dbg(fman->dev, "%s: FMan[%d] bus error: port_id[%d]\n",
__func__, fman->state->fm_id, port_id);
return IRQ_HANDLED;
}
static inline irqreturn_t call_mac_isr(struct fman *fman, u8 id)
{
if (fman->intr_mng[id].isr_cb) {
fman->intr_mng[id].isr_cb(fman->intr_mng[id].src_handle);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static inline u8 hw_port_id_to_sw_port_id(u8 major, u8 hw_port_id)
{
u8 sw_port_id = 0;
if (hw_port_id >= BASE_TX_PORTID)
sw_port_id = hw_port_id - BASE_TX_PORTID;
else if (hw_port_id >= BASE_RX_PORTID)
sw_port_id = hw_port_id - BASE_RX_PORTID;
else
sw_port_id = 0;
return sw_port_id;
}
static void set_port_order_restoration(struct fman_fpm_regs __iomem *fpm_rg,
u8 port_id)
{
u32 tmp = 0;
tmp = port_id << FPM_PORT_FM_CTL_PORTID_SHIFT;
tmp |= FPM_PRT_FM_CTL2 | FPM_PRT_FM_CTL1;
if (port_id % 2)
tmp |= FPM_PRT_FM_CTL1 << FPM_PRC_ORA_FM_CTL_SEL_SHIFT;
else
tmp |= FPM_PRT_FM_CTL2 << FPM_PRC_ORA_FM_CTL_SEL_SHIFT;
iowrite32be(tmp, &fpm_rg->fmfp_prc);
}
static void set_port_liodn(struct fman *fman, u8 port_id,
u32 liodn_base, u32 liodn_ofst)
{
u32 tmp;
tmp = ioread32be(&fman->dma_regs->fmdmplr[port_id / 2]);
if (port_id % 2) {
tmp &= ~DMA_LIODN_BASE_MASK;
tmp |= liodn_base;
} else {
tmp &= ~(DMA_LIODN_BASE_MASK << DMA_LIODN_SHIFT);
tmp |= liodn_base << DMA_LIODN_SHIFT;
}
iowrite32be(tmp, &fman->dma_regs->fmdmplr[port_id / 2]);
iowrite32be(liodn_ofst, &fman->bmi_regs->fmbm_spliodn[port_id - 1]);
}
static void enable_rams_ecc(struct fman_fpm_regs __iomem *fpm_rg)
{
u32 tmp;
tmp = ioread32be(&fpm_rg->fm_rcr);
if (tmp & FPM_RAM_RAMS_ECC_EN_SRC_SEL)
iowrite32be(tmp | FPM_RAM_IRAM_ECC_EN, &fpm_rg->fm_rcr);
else
iowrite32be(tmp | FPM_RAM_RAMS_ECC_EN |
FPM_RAM_IRAM_ECC_EN, &fpm_rg->fm_rcr);
}
static void disable_rams_ecc(struct fman_fpm_regs __iomem *fpm_rg)
{
u32 tmp;
tmp = ioread32be(&fpm_rg->fm_rcr);
if (tmp & FPM_RAM_RAMS_ECC_EN_SRC_SEL)
iowrite32be(tmp & ~FPM_RAM_IRAM_ECC_EN, &fpm_rg->fm_rcr);
else
iowrite32be(tmp & ~(FPM_RAM_RAMS_ECC_EN | FPM_RAM_IRAM_ECC_EN),
&fpm_rg->fm_rcr);
}
static void fman_defconfig(struct fman_cfg *cfg)
{
memset(cfg, 0, sizeof(struct fman_cfg));
cfg->catastrophic_err = DEFAULT_CATASTROPHIC_ERR;
cfg->dma_err = DEFAULT_DMA_ERR;
cfg->dma_aid_mode = DEFAULT_AID_MODE;
cfg->dma_comm_qtsh_clr_emer = DEFAULT_DMA_COMM_Q_LOW;
cfg->dma_comm_qtsh_asrt_emer = DEFAULT_DMA_COMM_Q_HIGH;
cfg->dma_cache_override = DEFAULT_CACHE_OVERRIDE;
cfg->dma_cam_num_of_entries = DEFAULT_DMA_CAM_NUM_OF_ENTRIES;
cfg->dma_dbg_cnt_mode = DEFAULT_DMA_DBG_CNT_MODE;
cfg->dma_sos_emergency = DEFAULT_DMA_SOS_EMERGENCY;
cfg->dma_watchdog = DEFAULT_DMA_WATCHDOG;
cfg->disp_limit_tsh = DEFAULT_DISP_LIMIT;
cfg->prs_disp_tsh = DEFAULT_PRS_DISP_TH;
cfg->plcr_disp_tsh = DEFAULT_PLCR_DISP_TH;
cfg->kg_disp_tsh = DEFAULT_KG_DISP_TH;
cfg->bmi_disp_tsh = DEFAULT_BMI_DISP_TH;
cfg->qmi_enq_disp_tsh = DEFAULT_QMI_ENQ_DISP_TH;
cfg->qmi_deq_disp_tsh = DEFAULT_QMI_DEQ_DISP_TH;
cfg->fm_ctl1_disp_tsh = DEFAULT_FM_CTL1_DISP_TH;
cfg->fm_ctl2_disp_tsh = DEFAULT_FM_CTL2_DISP_TH;
}
static int dma_init(struct fman *fman)
{
struct fman_dma_regs __iomem *dma_rg = fman->dma_regs;
struct fman_cfg *cfg = fman->cfg;
u32 tmp_reg;
tmp_reg = (DMA_STATUS_BUS_ERR | DMA_STATUS_READ_ECC |
DMA_STATUS_SYSTEM_WRITE_ECC | DMA_STATUS_FM_WRITE_ECC);
iowrite32be(ioread32be(&dma_rg->fmdmsr) | tmp_reg, &dma_rg->fmdmsr);
tmp_reg = 0;
tmp_reg |= cfg->dma_cache_override << DMA_MODE_CACHE_OR_SHIFT;
if (cfg->exceptions & EX_DMA_BUS_ERROR)
tmp_reg |= DMA_MODE_BER;
if ((cfg->exceptions & EX_DMA_SYSTEM_WRITE_ECC) |
(cfg->exceptions & EX_DMA_READ_ECC) |
(cfg->exceptions & EX_DMA_FM_WRITE_ECC))
tmp_reg |= DMA_MODE_ECC;
if (cfg->dma_axi_dbg_num_of_beats)
tmp_reg |= (DMA_MODE_AXI_DBG_MASK &
((cfg->dma_axi_dbg_num_of_beats - 1)
<< DMA_MODE_AXI_DBG_SHIFT));
tmp_reg |= (((cfg->dma_cam_num_of_entries / DMA_CAM_UNITS) - 1) &
DMA_MODE_CEN_MASK) << DMA_MODE_CEN_SHIFT;
tmp_reg |= DMA_MODE_SECURE_PROT;
tmp_reg |= cfg->dma_dbg_cnt_mode << DMA_MODE_DBG_SHIFT;
tmp_reg |= cfg->dma_aid_mode << DMA_MODE_AID_MODE_SHIFT;
iowrite32be(tmp_reg, &dma_rg->fmdmmr);
tmp_reg = ((u32)cfg->dma_comm_qtsh_asrt_emer <<
DMA_THRESH_COMMQ_SHIFT);
tmp_reg |= (cfg->dma_read_buf_tsh_asrt_emer &
DMA_THRESH_READ_INT_BUF_MASK) << DMA_THRESH_READ_INT_BUF_SHIFT;
tmp_reg |= cfg->dma_write_buf_tsh_asrt_emer &
DMA_THRESH_WRITE_INT_BUF_MASK;
iowrite32be(tmp_reg, &dma_rg->fmdmtr);
tmp_reg = ((u32)cfg->dma_comm_qtsh_clr_emer <<
DMA_THRESH_COMMQ_SHIFT);
tmp_reg |= (cfg->dma_read_buf_tsh_clr_emer &
DMA_THRESH_READ_INT_BUF_MASK) << DMA_THRESH_READ_INT_BUF_SHIFT;
tmp_reg |= cfg->dma_write_buf_tsh_clr_emer &
DMA_THRESH_WRITE_INT_BUF_MASK;
iowrite32be(tmp_reg, &dma_rg->fmdmhy);
iowrite32be(cfg->dma_sos_emergency, &dma_rg->fmdmsetr);
iowrite32be((cfg->dma_watchdog * cfg->clk_freq), &dma_rg->fmdmwcr);
iowrite32be(cfg->cam_base_addr, &dma_rg->fmdmebcr);
fman->cam_size =
(u32)(fman->cfg->dma_cam_num_of_entries * DMA_CAM_SIZEOF_ENTRY);
fman->cam_offset = fman_muram_alloc(fman->muram, fman->cam_size);
if (IS_ERR_VALUE(fman->cam_offset)) {
dev_err(fman->dev, "%s: MURAM alloc for DMA CAM failed\n",
__func__);
return -ENOMEM;
}
if (fman->state->rev_info.major == 2) {
u32 __iomem *cam_base_addr;
fman_muram_free_mem(fman->muram, fman->cam_offset,
fman->cam_size);
fman->cam_size = fman->cfg->dma_cam_num_of_entries * 72 + 128;
fman->cam_offset = fman_muram_alloc(fman->muram,
fman->cam_size);
if (IS_ERR_VALUE(fman->cam_offset)) {
dev_err(fman->dev, "%s: MURAM alloc for DMA CAM failed\n",
__func__);
return -ENOMEM;
}
if (fman->cfg->dma_cam_num_of_entries % 8 ||
fman->cfg->dma_cam_num_of_entries > 32) {
dev_err(fman->dev, "%s: wrong dma_cam_num_of_entries\n",
__func__);
return -EINVAL;
}
cam_base_addr = (u32 __iomem *)
fman_muram_offset_to_vbase(fman->muram,
fman->cam_offset);
iowrite32be(~((1 <<
(32 - fman->cfg->dma_cam_num_of_entries)) - 1),
cam_base_addr);
}
fman->cfg->cam_base_addr = fman->cam_offset;
return 0;
}
static void fpm_init(struct fman_fpm_regs __iomem *fpm_rg, struct fman_cfg *cfg)
{
u32 tmp_reg;
int i;
tmp_reg = (u32)(cfg->disp_limit_tsh << FPM_DISP_LIMIT_SHIFT);
iowrite32be(tmp_reg, &fpm_rg->fmfp_mxd);
tmp_reg = (((u32)cfg->prs_disp_tsh << FPM_THR1_PRS_SHIFT) |
((u32)cfg->kg_disp_tsh << FPM_THR1_KG_SHIFT) |
((u32)cfg->plcr_disp_tsh << FPM_THR1_PLCR_SHIFT) |
((u32)cfg->bmi_disp_tsh << FPM_THR1_BMI_SHIFT));
iowrite32be(tmp_reg, &fpm_rg->fmfp_dist1);
tmp_reg =
(((u32)cfg->qmi_enq_disp_tsh << FPM_THR2_QMI_ENQ_SHIFT) |
((u32)cfg->qmi_deq_disp_tsh << FPM_THR2_QMI_DEQ_SHIFT) |
((u32)cfg->fm_ctl1_disp_tsh << FPM_THR2_FM_CTL1_SHIFT) |
((u32)cfg->fm_ctl2_disp_tsh << FPM_THR2_FM_CTL2_SHIFT));
iowrite32be(tmp_reg, &fpm_rg->fmfp_dist2);
tmp_reg = 0;
tmp_reg |= (FPM_EV_MASK_STALL | FPM_EV_MASK_DOUBLE_ECC |
FPM_EV_MASK_SINGLE_ECC);
if (cfg->exceptions & EX_FPM_STALL_ON_TASKS)
tmp_reg |= FPM_EV_MASK_STALL_EN;
if (cfg->exceptions & EX_FPM_SINGLE_ECC)
tmp_reg |= FPM_EV_MASK_SINGLE_ECC_EN;
if (cfg->exceptions & EX_FPM_DOUBLE_ECC)
tmp_reg |= FPM_EV_MASK_DOUBLE_ECC_EN;
tmp_reg |= (cfg->catastrophic_err << FPM_EV_MASK_CAT_ERR_SHIFT);
tmp_reg |= (cfg->dma_err << FPM_EV_MASK_DMA_ERR_SHIFT);
tmp_reg |= FPM_EV_MASK_EXTERNAL_HALT;
tmp_reg |= FPM_EV_MASK_ECC_ERR_HALT;
iowrite32be(tmp_reg, &fpm_rg->fmfp_ee);
for (i = 0; i < FM_NUM_OF_FMAN_CTRL_EVENT_REGS; i++)
iowrite32be(0xFFFFFFFF, &fpm_rg->fmfp_cev[i]);
tmp_reg = (FPM_RAM_MURAM_ECC | FPM_RAM_IRAM_ECC);
iowrite32be(tmp_reg, &fpm_rg->fm_rcr);
tmp_reg = 0;
if (cfg->exceptions & EX_IRAM_ECC) {
tmp_reg |= FPM_IRAM_ECC_ERR_EX_EN;
enable_rams_ecc(fpm_rg);
}
if (cfg->exceptions & EX_MURAM_ECC) {
tmp_reg |= FPM_MURAM_ECC_ERR_EX_EN;
enable_rams_ecc(fpm_rg);
}
iowrite32be(tmp_reg, &fpm_rg->fm_rie);
}
static void bmi_init(struct fman_bmi_regs __iomem *bmi_rg,
struct fman_cfg *cfg)
{
u32 tmp_reg;
tmp_reg = cfg->fifo_base_addr;
tmp_reg = tmp_reg / BMI_FIFO_ALIGN;
tmp_reg |= ((cfg->total_fifo_size / FMAN_BMI_FIFO_UNITS - 1) <<
BMI_CFG1_FIFO_SIZE_SHIFT);
iowrite32be(tmp_reg, &bmi_rg->fmbm_cfg1);
tmp_reg = ((cfg->total_num_of_tasks - 1) & BMI_CFG2_TASKS_MASK) <<
BMI_CFG2_TASKS_SHIFT;
iowrite32be(tmp_reg, &bmi_rg->fmbm_cfg2);
tmp_reg = 0;
iowrite32be(BMI_ERR_INTR_EN_LIST_RAM_ECC |
BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC |
BMI_ERR_INTR_EN_STATISTICS_RAM_ECC |
BMI_ERR_INTR_EN_DISPATCH_RAM_ECC, &bmi_rg->fmbm_ievr);
if (cfg->exceptions & EX_BMI_LIST_RAM_ECC)
tmp_reg |= BMI_ERR_INTR_EN_LIST_RAM_ECC;
if (cfg->exceptions & EX_BMI_STORAGE_PROFILE_ECC)
tmp_reg |= BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC;
if (cfg->exceptions & EX_BMI_STATISTICS_RAM_ECC)
tmp_reg |= BMI_ERR_INTR_EN_STATISTICS_RAM_ECC;
if (cfg->exceptions & EX_BMI_DISPATCH_RAM_ECC)
tmp_reg |= BMI_ERR_INTR_EN_DISPATCH_RAM_ECC;
iowrite32be(tmp_reg, &bmi_rg->fmbm_ier);
}
static void qmi_init(struct fman_qmi_regs __iomem *qmi_rg,
struct fman_cfg *cfg)
{
u32 tmp_reg;
iowrite32be(QMI_ERR_INTR_EN_DOUBLE_ECC | QMI_ERR_INTR_EN_DEQ_FROM_DEF,
&qmi_rg->fmqm_eie);
tmp_reg = 0;
if (cfg->exceptions & EX_QMI_DEQ_FROM_UNKNOWN_PORTID)
tmp_reg |= QMI_ERR_INTR_EN_DEQ_FROM_DEF;
if (cfg->exceptions & EX_QMI_DOUBLE_ECC)
tmp_reg |= QMI_ERR_INTR_EN_DOUBLE_ECC;
iowrite32be(tmp_reg, &qmi_rg->fmqm_eien);
tmp_reg = 0;
iowrite32be(QMI_INTR_EN_SINGLE_ECC, &qmi_rg->fmqm_ie);
if (cfg->exceptions & EX_QMI_SINGLE_ECC)
tmp_reg |= QMI_INTR_EN_SINGLE_ECC;
iowrite32be(tmp_reg, &qmi_rg->fmqm_ien);
}
static int enable(struct fman *fman, struct fman_cfg *cfg)
{
u32 cfg_reg = 0;
cfg_reg = QMI_CFG_EN_COUNTERS;
cfg_reg |= (cfg->qmi_def_tnums_thresh << 8) | cfg->qmi_def_tnums_thresh;
iowrite32be(BMI_INIT_START, &fman->bmi_regs->fmbm_init);
iowrite32be(cfg_reg | QMI_CFG_ENQ_EN | QMI_CFG_DEQ_EN,
&fman->qmi_regs->fmqm_gc);
return 0;
}
static int set_exception(struct fman *fman,
enum fman_exceptions exception, bool enable)
{
u32 tmp;
switch (exception) {
case FMAN_EX_DMA_BUS_ERROR:
tmp = ioread32be(&fman->dma_regs->fmdmmr);
if (enable)
tmp |= DMA_MODE_BER;
else
tmp &= ~DMA_MODE_BER;
iowrite32be(tmp, &fman->dma_regs->fmdmmr);
break;
case FMAN_EX_DMA_READ_ECC:
case FMAN_EX_DMA_SYSTEM_WRITE_ECC:
case FMAN_EX_DMA_FM_WRITE_ECC:
tmp = ioread32be(&fman->dma_regs->fmdmmr);
if (enable)
tmp |= DMA_MODE_ECC;
else
tmp &= ~DMA_MODE_ECC;
iowrite32be(tmp, &fman->dma_regs->fmdmmr);
break;
case FMAN_EX_FPM_STALL_ON_TASKS:
tmp = ioread32be(&fman->fpm_regs->fmfp_ee);
if (enable)
tmp |= FPM_EV_MASK_STALL_EN;
else
tmp &= ~FPM_EV_MASK_STALL_EN;
iowrite32be(tmp, &fman->fpm_regs->fmfp_ee);
break;
case FMAN_EX_FPM_SINGLE_ECC:
tmp = ioread32be(&fman->fpm_regs->fmfp_ee);
if (enable)
tmp |= FPM_EV_MASK_SINGLE_ECC_EN;
else
tmp &= ~FPM_EV_MASK_SINGLE_ECC_EN;
iowrite32be(tmp, &fman->fpm_regs->fmfp_ee);
break;
case FMAN_EX_FPM_DOUBLE_ECC:
tmp = ioread32be(&fman->fpm_regs->fmfp_ee);
if (enable)
tmp |= FPM_EV_MASK_DOUBLE_ECC_EN;
else
tmp &= ~FPM_EV_MASK_DOUBLE_ECC_EN;
iowrite32be(tmp, &fman->fpm_regs->fmfp_ee);
break;
case FMAN_EX_QMI_SINGLE_ECC:
tmp = ioread32be(&fman->qmi_regs->fmqm_ien);
if (enable)
tmp |= QMI_INTR_EN_SINGLE_ECC;
else
tmp &= ~QMI_INTR_EN_SINGLE_ECC;
iowrite32be(tmp, &fman->qmi_regs->fmqm_ien);
break;
case FMAN_EX_QMI_DOUBLE_ECC:
tmp = ioread32be(&fman->qmi_regs->fmqm_eien);
if (enable)
tmp |= QMI_ERR_INTR_EN_DOUBLE_ECC;
else
tmp &= ~QMI_ERR_INTR_EN_DOUBLE_ECC;
iowrite32be(tmp, &fman->qmi_regs->fmqm_eien);
break;
case FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID:
tmp = ioread32be(&fman->qmi_regs->fmqm_eien);
if (enable)
tmp |= QMI_ERR_INTR_EN_DEQ_FROM_DEF;
else
tmp &= ~QMI_ERR_INTR_EN_DEQ_FROM_DEF;
iowrite32be(tmp, &fman->qmi_regs->fmqm_eien);
break;
case FMAN_EX_BMI_LIST_RAM_ECC:
tmp = ioread32be(&fman->bmi_regs->fmbm_ier);
if (enable)
tmp |= BMI_ERR_INTR_EN_LIST_RAM_ECC;
else
tmp &= ~BMI_ERR_INTR_EN_LIST_RAM_ECC;
iowrite32be(tmp, &fman->bmi_regs->fmbm_ier);
break;
case FMAN_EX_BMI_STORAGE_PROFILE_ECC:
tmp = ioread32be(&fman->bmi_regs->fmbm_ier);
if (enable)
tmp |= BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC;
else
tmp &= ~BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC;
iowrite32be(tmp, &fman->bmi_regs->fmbm_ier);
break;
case FMAN_EX_BMI_STATISTICS_RAM_ECC:
tmp = ioread32be(&fman->bmi_regs->fmbm_ier);
if (enable)
tmp |= BMI_ERR_INTR_EN_STATISTICS_RAM_ECC;
else
tmp &= ~BMI_ERR_INTR_EN_STATISTICS_RAM_ECC;
iowrite32be(tmp, &fman->bmi_regs->fmbm_ier);
break;
case FMAN_EX_BMI_DISPATCH_RAM_ECC:
tmp = ioread32be(&fman->bmi_regs->fmbm_ier);
if (enable)
tmp |= BMI_ERR_INTR_EN_DISPATCH_RAM_ECC;
else
tmp &= ~BMI_ERR_INTR_EN_DISPATCH_RAM_ECC;
iowrite32be(tmp, &fman->bmi_regs->fmbm_ier);
break;
case FMAN_EX_IRAM_ECC:
tmp = ioread32be(&fman->fpm_regs->fm_rie);
if (enable) {
enable_rams_ecc(fman->fpm_regs);
tmp |= FPM_IRAM_ECC_ERR_EX_EN;
} else {
disable_rams_ecc(fman->fpm_regs);
tmp &= ~FPM_IRAM_ECC_ERR_EX_EN;
}
iowrite32be(tmp, &fman->fpm_regs->fm_rie);
break;
case FMAN_EX_MURAM_ECC:
tmp = ioread32be(&fman->fpm_regs->fm_rie);
if (enable) {
enable_rams_ecc(fman->fpm_regs);
tmp |= FPM_MURAM_ECC_ERR_EX_EN;
} else {
disable_rams_ecc(fman->fpm_regs);
tmp &= ~FPM_MURAM_ECC_ERR_EX_EN;
}
iowrite32be(tmp, &fman->fpm_regs->fm_rie);
break;
default:
return -EINVAL;
}
return 0;
}
static void resume(struct fman_fpm_regs __iomem *fpm_rg)
{
u32 tmp;
tmp = ioread32be(&fpm_rg->fmfp_ee);
tmp &= ~(FPM_EV_MASK_DOUBLE_ECC |
FPM_EV_MASK_STALL | FPM_EV_MASK_SINGLE_ECC);
tmp |= FPM_EV_MASK_RELEASE_FM;
iowrite32be(tmp, &fpm_rg->fmfp_ee);
}
static int fill_soc_specific_params(struct fman_state_struct *state)
{
u8 minor = state->rev_info.minor;
switch (state->rev_info.major) {
case 3:
state->bmi_max_fifo_size = 160 * 1024;
state->fm_iram_size = 64 * 1024;
state->dma_thresh_max_commq = 31;
state->dma_thresh_max_buf = 127;
state->qmi_max_num_of_tnums = 64;
state->qmi_def_tnums_thresh = 48;
state->bmi_max_num_of_tasks = 128;
state->max_num_of_open_dmas = 32;
state->fm_port_num_of_cg = 256;
state->num_of_rx_ports = 6;
state->total_fifo_size = 122 * 1024;
break;
case 2:
state->bmi_max_fifo_size = 160 * 1024;
state->fm_iram_size = 64 * 1024;
state->dma_thresh_max_commq = 31;
state->dma_thresh_max_buf = 127;
state->qmi_max_num_of_tnums = 64;
state->qmi_def_tnums_thresh = 48;
state->bmi_max_num_of_tasks = 128;
state->max_num_of_open_dmas = 32;
state->fm_port_num_of_cg = 256;
state->num_of_rx_ports = 5;
state->total_fifo_size = 100 * 1024;
break;
case 6:
state->dma_thresh_max_commq = 83;
state->dma_thresh_max_buf = 127;
state->qmi_max_num_of_tnums = 64;
state->qmi_def_tnums_thresh = 32;
state->fm_port_num_of_cg = 256;
if (minor == 1 || minor == 4) {
state->bmi_max_fifo_size = 192 * 1024;
state->bmi_max_num_of_tasks = 64;
state->max_num_of_open_dmas = 32;
state->num_of_rx_ports = 5;
if (minor == 1)
state->fm_iram_size = 32 * 1024;
else
state->fm_iram_size = 64 * 1024;
state->total_fifo_size = 156 * 1024;
}
else if (minor == 0 || minor == 2 || minor == 3) {
state->bmi_max_fifo_size = 384 * 1024;
state->fm_iram_size = 64 * 1024;
state->bmi_max_num_of_tasks = 128;
state->max_num_of_open_dmas = 84;
state->num_of_rx_ports = 8;
state->total_fifo_size = 295 * 1024;
} else {
pr_err("Unsupported FManv3 version\n");
return -EINVAL;
}
break;
default:
pr_err("Unsupported FMan version\n");
return -EINVAL;
}
return 0;
}
static bool is_init_done(struct fman_cfg *cfg)
{
if (!cfg)
return true;
return false;
}
static void free_init_resources(struct fman *fman)
{
if (fman->cam_offset)
fman_muram_free_mem(fman->muram, fman->cam_offset,
fman->cam_size);
if (fman->fifo_offset)
fman_muram_free_mem(fman->muram, fman->fifo_offset,
fman->fifo_size);
}
static irqreturn_t bmi_err_event(struct fman *fman)
{
u32 event, mask, force;
struct fman_bmi_regs __iomem *bmi_rg = fman->bmi_regs;
irqreturn_t ret = IRQ_NONE;
event = ioread32be(&bmi_rg->fmbm_ievr);
mask = ioread32be(&bmi_rg->fmbm_ier);
event &= mask;
force = ioread32be(&bmi_rg->fmbm_ifr);
if (force & event)
iowrite32be(force & ~event, &bmi_rg->fmbm_ifr);
iowrite32be(event, &bmi_rg->fmbm_ievr);
if (event & BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC)
ret = fman->exception_cb(fman, FMAN_EX_BMI_STORAGE_PROFILE_ECC);
if (event & BMI_ERR_INTR_EN_LIST_RAM_ECC)
ret = fman->exception_cb(fman, FMAN_EX_BMI_LIST_RAM_ECC);
if (event & BMI_ERR_INTR_EN_STATISTICS_RAM_ECC)
ret = fman->exception_cb(fman, FMAN_EX_BMI_STATISTICS_RAM_ECC);
if (event & BMI_ERR_INTR_EN_DISPATCH_RAM_ECC)
ret = fman->exception_cb(fman, FMAN_EX_BMI_DISPATCH_RAM_ECC);
return ret;
}
static irqreturn_t qmi_err_event(struct fman *fman)
{
u32 event, mask, force;
struct fman_qmi_regs __iomem *qmi_rg = fman->qmi_regs;
irqreturn_t ret = IRQ_NONE;
event = ioread32be(&qmi_rg->fmqm_eie);
mask = ioread32be(&qmi_rg->fmqm_eien);
event &= mask;
force = ioread32be(&qmi_rg->fmqm_eif);
if (force & event)
iowrite32be(force & ~event, &qmi_rg->fmqm_eif);
iowrite32be(event, &qmi_rg->fmqm_eie);
if (event & QMI_ERR_INTR_EN_DOUBLE_ECC)
ret = fman->exception_cb(fman, FMAN_EX_QMI_DOUBLE_ECC);
if (event & QMI_ERR_INTR_EN_DEQ_FROM_DEF)
ret = fman->exception_cb(fman,
FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID);
return ret;
}
static irqreturn_t dma_err_event(struct fman *fman)
{
u32 status, mask, com_id;
u8 tnum, port_id, relative_port_id;
u16 liodn;
struct fman_dma_regs __iomem *dma_rg = fman->dma_regs;
irqreturn_t ret = IRQ_NONE;
status = ioread32be(&dma_rg->fmdmsr);
mask = ioread32be(&dma_rg->fmdmmr);
if ((mask & DMA_MODE_BER) != DMA_MODE_BER)
status &= ~DMA_STATUS_BUS_ERR;
if ((mask & DMA_MODE_ECC) != DMA_MODE_ECC)
status &= ~(DMA_STATUS_FM_SPDAT_ECC |
DMA_STATUS_READ_ECC |
DMA_STATUS_SYSTEM_WRITE_ECC |
DMA_STATUS_FM_WRITE_ECC);
iowrite32be(status, &dma_rg->fmdmsr);
if (status & DMA_STATUS_BUS_ERR) {
u64 addr;
addr = (u64)ioread32be(&dma_rg->fmdmtal);
addr |= ((u64)(ioread32be(&dma_rg->fmdmtah)) << 32);
com_id = ioread32be(&dma_rg->fmdmtcid);
port_id = (u8)(((com_id & DMA_TRANSFER_PORTID_MASK) >>
DMA_TRANSFER_PORTID_SHIFT));
relative_port_id =
hw_port_id_to_sw_port_id(fman->state->rev_info.major, port_id);
tnum = (u8)((com_id & DMA_TRANSFER_TNUM_MASK) >>
DMA_TRANSFER_TNUM_SHIFT);
liodn = (u16)(com_id & DMA_TRANSFER_LIODN_MASK);
ret = fman->bus_error_cb(fman, relative_port_id, addr, tnum,
liodn);
}
if (status & DMA_STATUS_FM_SPDAT_ECC)
ret = fman->exception_cb(fman, FMAN_EX_DMA_SINGLE_PORT_ECC);
if (status & DMA_STATUS_READ_ECC)
ret = fman->exception_cb(fman, FMAN_EX_DMA_READ_ECC);
if (status & DMA_STATUS_SYSTEM_WRITE_ECC)
ret = fman->exception_cb(fman, FMAN_EX_DMA_SYSTEM_WRITE_ECC);
if (status & DMA_STATUS_FM_WRITE_ECC)
ret = fman->exception_cb(fman, FMAN_EX_DMA_FM_WRITE_ECC);
return ret;
}
static irqreturn_t fpm_err_event(struct fman *fman)
{
u32 event;
struct fman_fpm_regs __iomem *fpm_rg = fman->fpm_regs;
irqreturn_t ret = IRQ_NONE;
event = ioread32be(&fpm_rg->fmfp_ee);
iowrite32be(event, &fpm_rg->fmfp_ee);
if ((event & FPM_EV_MASK_DOUBLE_ECC) &&
(event & FPM_EV_MASK_DOUBLE_ECC_EN))
ret = fman->exception_cb(fman, FMAN_EX_FPM_DOUBLE_ECC);
if ((event & FPM_EV_MASK_STALL) && (event & FPM_EV_MASK_STALL_EN))
ret = fman->exception_cb(fman, FMAN_EX_FPM_STALL_ON_TASKS);
if ((event & FPM_EV_MASK_SINGLE_ECC) &&
(event & FPM_EV_MASK_SINGLE_ECC_EN))
ret = fman->exception_cb(fman, FMAN_EX_FPM_SINGLE_ECC);
return ret;
}
static irqreturn_t muram_err_intr(struct fman *fman)
{
u32 event, mask;
struct fman_fpm_regs __iomem *fpm_rg = fman->fpm_regs;
irqreturn_t ret = IRQ_NONE;
event = ioread32be(&fpm_rg->fm_rcr);
mask = ioread32be(&fpm_rg->fm_rie);
iowrite32be(event & ~FPM_RAM_IRAM_ECC, &fpm_rg->fm_rcr);
if ((mask & FPM_MURAM_ECC_ERR_EX_EN) && (event & FPM_RAM_MURAM_ECC))
ret = fman->exception_cb(fman, FMAN_EX_MURAM_ECC);
return ret;
}
static irqreturn_t qmi_event(struct fman *fman)
{
u32 event, mask, force;
struct fman_qmi_regs __iomem *qmi_rg = fman->qmi_regs;
irqreturn_t ret = IRQ_NONE;
event = ioread32be(&qmi_rg->fmqm_ie);
mask = ioread32be(&qmi_rg->fmqm_ien);
event &= mask;
force = ioread32be(&qmi_rg->fmqm_if);
if (force & event)
iowrite32be(force & ~event, &qmi_rg->fmqm_if);
iowrite32be(event, &qmi_rg->fmqm_ie);
if (event & QMI_INTR_EN_SINGLE_ECC)
ret = fman->exception_cb(fman, FMAN_EX_QMI_SINGLE_ECC);
return ret;
}
static void enable_time_stamp(struct fman *fman)
{
struct fman_fpm_regs __iomem *fpm_rg = fman->fpm_regs;
u16 fm_clk_freq = fman->state->fm_clk_freq;
u32 tmp, intgr, ts_freq;
u64 frac;
ts_freq = (u32)(1 << fman->state->count1_micro_bit);
intgr = ts_freq / fm_clk_freq;
frac = ((ts_freq << 16) - (intgr << 16) * fm_clk_freq) / fm_clk_freq;
if (((ts_freq << 16) - (intgr << 16) * fm_clk_freq) % fm_clk_freq)
frac++;
tmp = (intgr << FPM_TS_INT_SHIFT) | (u16)frac;
iowrite32be(tmp, &fpm_rg->fmfp_tsc2);
iowrite32be(FPM_TS_CTL_EN, &fpm_rg->fmfp_tsc1);
fman->state->enabled_time_stamp = true;
}
static int clear_iram(struct fman *fman)
{
struct fman_iram_regs __iomem *iram;
int i, count;
iram = fman->base_addr + IMEM_OFFSET;
iowrite32be(IRAM_IADD_AIE, &iram->iadd);
count = 100;
do {
udelay(1);
} while ((ioread32be(&iram->iadd) != IRAM_IADD_AIE) && --count);
if (count == 0)
return -EBUSY;
for (i = 0; i < (fman->state->fm_iram_size / 4); i++)
iowrite32be(0xffffffff, &iram->idata);
iowrite32be(fman->state->fm_iram_size - 4, &iram->iadd);
count = 100;
do {
udelay(1);
} while ((ioread32be(&iram->idata) != 0xffffffff) && --count);
if (count == 0)
return -EBUSY;
return 0;
}
static u32 get_exception_flag(enum fman_exceptions exception)
{
u32 bit_mask;
switch (exception) {
case FMAN_EX_DMA_BUS_ERROR:
bit_mask = EX_DMA_BUS_ERROR;
break;
case FMAN_EX_DMA_SINGLE_PORT_ECC:
bit_mask = EX_DMA_SINGLE_PORT_ECC;
break;
case FMAN_EX_DMA_READ_ECC:
bit_mask = EX_DMA_READ_ECC;
break;
case FMAN_EX_DMA_SYSTEM_WRITE_ECC:
bit_mask = EX_DMA_SYSTEM_WRITE_ECC;
break;
case FMAN_EX_DMA_FM_WRITE_ECC:
bit_mask = EX_DMA_FM_WRITE_ECC;
break;
case FMAN_EX_FPM_STALL_ON_TASKS:
bit_mask = EX_FPM_STALL_ON_TASKS;
break;
case FMAN_EX_FPM_SINGLE_ECC:
bit_mask = EX_FPM_SINGLE_ECC;
break;
case FMAN_EX_FPM_DOUBLE_ECC:
bit_mask = EX_FPM_DOUBLE_ECC;
break;
case FMAN_EX_QMI_SINGLE_ECC:
bit_mask = EX_QMI_SINGLE_ECC;
break;
case FMAN_EX_QMI_DOUBLE_ECC:
bit_mask = EX_QMI_DOUBLE_ECC;
break;
case FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID:
bit_mask = EX_QMI_DEQ_FROM_UNKNOWN_PORTID;
break;
case FMAN_EX_BMI_LIST_RAM_ECC:
bit_mask = EX_BMI_LIST_RAM_ECC;
break;
case FMAN_EX_BMI_STORAGE_PROFILE_ECC:
bit_mask = EX_BMI_STORAGE_PROFILE_ECC;
break;
case FMAN_EX_BMI_STATISTICS_RAM_ECC:
bit_mask = EX_BMI_STATISTICS_RAM_ECC;
break;
case FMAN_EX_BMI_DISPATCH_RAM_ECC:
bit_mask = EX_BMI_DISPATCH_RAM_ECC;
break;
case FMAN_EX_MURAM_ECC:
bit_mask = EX_MURAM_ECC;
break;
default:
bit_mask = 0;
break;
}
return bit_mask;
}
static int get_module_event(enum fman_event_modules module, u8 mod_id,
enum fman_intr_type intr_type)
{
int event;
switch (module) {
case FMAN_MOD_MAC:
if (intr_type == FMAN_INTR_TYPE_ERR)
event = FMAN_EV_ERR_MAC0 + mod_id;
else
event = FMAN_EV_MAC0 + mod_id;
break;
case FMAN_MOD_FMAN_CTRL:
if (intr_type == FMAN_INTR_TYPE_ERR)
event = FMAN_EV_CNT;
else
event = (FMAN_EV_FMAN_CTRL_0 + mod_id);
break;
case FMAN_MOD_DUMMY_LAST:
event = FMAN_EV_CNT;
break;
default:
event = FMAN_EV_CNT;
break;
}
return event;
}
static int set_size_of_fifo(struct fman *fman, u8 port_id, u32 *size_of_fifo,
u32 *extra_size_of_fifo)
{
struct fman_bmi_regs __iomem *bmi_rg = fman->bmi_regs;
u32 fifo = *size_of_fifo;
u32 extra_fifo = *extra_size_of_fifo;
u32 tmp;
if (extra_fifo && !fman->state->extra_fifo_pool_size)
fman->state->extra_fifo_pool_size =
fman->state->num_of_rx_ports * FMAN_BMI_FIFO_UNITS;
fman->state->extra_fifo_pool_size =
max(fman->state->extra_fifo_pool_size, extra_fifo);
if ((fman->state->accumulated_fifo_size + fifo) >
(fman->state->total_fifo_size -
fman->state->extra_fifo_pool_size)) {
dev_err(fman->dev, "%s: Requested fifo size and extra size exceed total FIFO size.\n",
__func__);
return -EAGAIN;
}
tmp = (fifo / FMAN_BMI_FIFO_UNITS - 1) |
((extra_fifo / FMAN_BMI_FIFO_UNITS) <<
BMI_EXTRA_FIFO_SIZE_SHIFT);
iowrite32be(tmp, &bmi_rg->fmbm_pfs[port_id - 1]);
fman->state->accumulated_fifo_size += fifo;
return 0;
}
static int set_num_of_tasks(struct fman *fman, u8 port_id, u8 *num_of_tasks,
u8 *num_of_extra_tasks)
{
struct fman_bmi_regs __iomem *bmi_rg = fman->bmi_regs;
u8 tasks = *num_of_tasks;
u8 extra_tasks = *num_of_extra_tasks;
u32 tmp;
if (extra_tasks)
fman->state->extra_tasks_pool_size =
max(fman->state->extra_tasks_pool_size, extra_tasks);
if ((fman->state->accumulated_num_of_tasks + tasks) >
(fman->state->total_num_of_tasks -
fman->state->extra_tasks_pool_size)) {
dev_err(fman->dev, "%s: Requested num_of_tasks and extra tasks pool for fm%d exceed total num_of_tasks.\n",
__func__, fman->state->fm_id);
return -EAGAIN;
}
fman->state->accumulated_num_of_tasks += tasks;
tmp = ioread32be(&bmi_rg->fmbm_pp[port_id - 1]) &
~(BMI_NUM_OF_TASKS_MASK | BMI_NUM_OF_EXTRA_TASKS_MASK);
tmp |= ((u32)((tasks - 1) << BMI_NUM_OF_TASKS_SHIFT) |
(u32)(extra_tasks << BMI_EXTRA_NUM_OF_TASKS_SHIFT));
iowrite32be(tmp, &bmi_rg->fmbm_pp[port_id - 1]);
return 0;
}
static int set_num_of_open_dmas(struct fman *fman, u8 port_id,
u8 *num_of_open_dmas,
u8 *num_of_extra_open_dmas)
{
struct fman_bmi_regs __iomem *bmi_rg = fman->bmi_regs;
u8 open_dmas = *num_of_open_dmas;
u8 extra_open_dmas = *num_of_extra_open_dmas;
u8 total_num_dmas = 0, current_val = 0, current_extra_val = 0;
u32 tmp;
if (!open_dmas) {
tmp = ioread32be(&bmi_rg->fmbm_pp[port_id - 1]);
current_extra_val = (u8)((tmp & BMI_NUM_OF_EXTRA_DMAS_MASK) >>
BMI_EXTRA_NUM_OF_DMAS_SHIFT);
tmp = ioread32be(&bmi_rg->fmbm_pp[port_id - 1]);
current_val = (u8)(((tmp & BMI_NUM_OF_DMAS_MASK) >>
BMI_NUM_OF_DMAS_SHIFT) + 1);
fman->state->extra_open_dmas_pool_size =
(u8)max(fman->state->extra_open_dmas_pool_size,
current_extra_val);
fman->state->accumulated_num_of_open_dmas += current_val;
*num_of_open_dmas = current_val;
*num_of_extra_open_dmas = current_extra_val;
return 0;
}
if (extra_open_dmas > current_extra_val)
fman->state->extra_open_dmas_pool_size =
(u8)max(fman->state->extra_open_dmas_pool_size,
extra_open_dmas);
if ((fman->state->rev_info.major < 6) &&
(fman->state->accumulated_num_of_open_dmas - current_val +
open_dmas > fman->state->max_num_of_open_dmas)) {
dev_err(fman->dev, "%s: Requested num_of_open_dmas for fm%d exceeds total num_of_open_dmas.\n",
__func__, fman->state->fm_id);
return -EAGAIN;
} else if ((fman->state->rev_info.major >= 6) &&
!((fman->state->rev_info.major == 6) &&
(fman->state->rev_info.minor == 0)) &&
(fman->state->accumulated_num_of_open_dmas -
current_val + open_dmas >
fman->state->dma_thresh_max_commq + 1)) {
dev_err(fman->dev, "%s: Requested num_of_open_dmas for fm%d exceeds DMA Command queue (%d)\n",
__func__, fman->state->fm_id,
fman->state->dma_thresh_max_commq + 1);
return -EAGAIN;
}
WARN_ON(fman->state->accumulated_num_of_open_dmas < current_val);
fman->state->accumulated_num_of_open_dmas -= current_val;
fman->state->accumulated_num_of_open_dmas += open_dmas;
if (fman->state->rev_info.major < 6)
total_num_dmas =
(u8)(fman->state->accumulated_num_of_open_dmas +
fman->state->extra_open_dmas_pool_size);
tmp = ioread32be(&bmi_rg->fmbm_pp[port_id - 1]) &
~(BMI_NUM_OF_DMAS_MASK | BMI_NUM_OF_EXTRA_DMAS_MASK);
tmp |= (u32)(((open_dmas - 1) << BMI_NUM_OF_DMAS_SHIFT) |
(extra_open_dmas << BMI_EXTRA_NUM_OF_DMAS_SHIFT));
iowrite32be(tmp, &bmi_rg->fmbm_pp[port_id - 1]);
if (total_num_dmas) {
tmp = ioread32be(&bmi_rg->fmbm_cfg2) & ~BMI_CFG2_DMAS_MASK;
tmp |= (u32)(total_num_dmas - 1) << BMI_CFG2_DMAS_SHIFT;
iowrite32be(tmp, &bmi_rg->fmbm_cfg2);
}
return 0;
}
static int fman_config(struct fman *fman)
{
void __iomem *base_addr;
int err;
base_addr = fman->dts_params.base_addr;
fman->state = kzalloc(sizeof(*fman->state), GFP_KERNEL);
if (!fman->state)
goto err_fm_state;
fman->cfg = kzalloc(sizeof(*fman->cfg), GFP_KERNEL);
if (!fman->cfg)
goto err_fm_drv;
fman->muram =
fman_muram_init(fman->dts_params.muram_res.start,
resource_size(&fman->dts_params.muram_res));
if (!fman->muram)
goto err_fm_soc_specific;
fman->state->fm_id = fman->dts_params.id;
fman->state->fm_clk_freq = fman->dts_params.clk_freq;
fman->state->qman_channel_base = fman->dts_params.qman_channel_base;
fman->state->num_of_qman_channels =
fman->dts_params.num_of_qman_channels;
fman->state->res = fman->dts_params.res;
fman->exception_cb = fman_exceptions;
fman->bus_error_cb = fman_bus_error;
fman->fpm_regs = base_addr + FPM_OFFSET;
fman->bmi_regs = base_addr + BMI_OFFSET;
fman->qmi_regs = base_addr + QMI_OFFSET;
fman->dma_regs = base_addr + DMA_OFFSET;
fman->base_addr = base_addr;
spin_lock_init(&fman->spinlock);
fman_defconfig(fman->cfg);
fman->state->extra_fifo_pool_size = 0;
fman->state->exceptions = (EX_DMA_BUS_ERROR |
EX_DMA_READ_ECC |
EX_DMA_SYSTEM_WRITE_ECC |
EX_DMA_FM_WRITE_ECC |
EX_FPM_STALL_ON_TASKS |
EX_FPM_SINGLE_ECC |
EX_FPM_DOUBLE_ECC |
EX_QMI_DEQ_FROM_UNKNOWN_PORTID |
EX_BMI_LIST_RAM_ECC |
EX_BMI_STORAGE_PROFILE_ECC |
EX_BMI_STATISTICS_RAM_ECC |
EX_MURAM_ECC |
EX_BMI_DISPATCH_RAM_ECC |
EX_QMI_DOUBLE_ECC |
EX_QMI_SINGLE_ECC);
fman_get_revision(fman, &fman->state->rev_info);
err = fill_soc_specific_params(fman->state);
if (err)
goto err_fm_soc_specific;
if (fman->state->rev_info.major >= 6)
fman->cfg->dma_aid_mode = FMAN_DMA_AID_OUT_PORT_ID;
fman->cfg->qmi_def_tnums_thresh = fman->state->qmi_def_tnums_thresh;
fman->state->total_num_of_tasks =
(u8)DFLT_TOTAL_NUM_OF_TASKS(fman->state->rev_info.major,
fman->state->rev_info.minor,
fman->state->bmi_max_num_of_tasks);
if (fman->state->rev_info.major < 6) {
fman->cfg->dma_comm_qtsh_clr_emer =
(u8)DFLT_DMA_COMM_Q_LOW(fman->state->rev_info.major,
fman->state->dma_thresh_max_commq);
fman->cfg->dma_comm_qtsh_asrt_emer =
(u8)DFLT_DMA_COMM_Q_HIGH(fman->state->rev_info.major,
fman->state->dma_thresh_max_commq);
fman->cfg->dma_cam_num_of_entries =
DFLT_DMA_CAM_NUM_OF_ENTRIES(fman->state->rev_info.major);
fman->cfg->dma_read_buf_tsh_clr_emer =
DFLT_DMA_READ_INT_BUF_LOW(fman->state->dma_thresh_max_buf);
fman->cfg->dma_read_buf_tsh_asrt_emer =
DFLT_DMA_READ_INT_BUF_HIGH(fman->state->dma_thresh_max_buf);
fman->cfg->dma_write_buf_tsh_clr_emer =
DFLT_DMA_WRITE_INT_BUF_LOW(fman->state->dma_thresh_max_buf);
fman->cfg->dma_write_buf_tsh_asrt_emer =
DFLT_DMA_WRITE_INT_BUF_HIGH(fman->state->dma_thresh_max_buf);
fman->cfg->dma_axi_dbg_num_of_beats =
DFLT_AXI_DBG_NUM_OF_BEATS;
}
return 0;
err_fm_soc_specific:
kfree(fman->cfg);
err_fm_drv:
kfree(fman->state);
err_fm_state:
kfree(fman);
return -EINVAL;
}
static int fman_reset(struct fman *fman)
{
u32 count;
int err = 0;
if (fman->state->rev_info.major < 6) {
iowrite32be(FPM_RSTC_FM_RESET, &fman->fpm_regs->fm_rstc);
count = 100;
do {
udelay(1);
} while (((ioread32be(&fman->fpm_regs->fm_rstc)) &
FPM_RSTC_FM_RESET) && --count);
if (count == 0)
err = -EBUSY;
goto _return;
} else {
struct device_node *guts_node;
struct ccsr_guts __iomem *guts_regs;
u32 devdisr2, reg;
guts_node =
of_find_compatible_node(NULL, NULL,
"fsl,qoriq-device-config-2.0");
if (!guts_node) {
dev_err(fman->dev, "%s: Couldn't find guts node\n",
__func__);
goto guts_node;
}
guts_regs = of_iomap(guts_node, 0);
if (!guts_regs) {
dev_err(fman->dev, "%s: Couldn't map %s regs\n",
__func__, guts_node->full_name);
goto guts_regs;
}
#define FMAN1_ALL_MACS_MASK 0xFCC00000
#define FMAN2_ALL_MACS_MASK 0x000FCC00
devdisr2 = ioread32be(&guts_regs->devdisr2);
if (fman->dts_params.id == 0)
reg = devdisr2 & ~FMAN1_ALL_MACS_MASK;
else
reg = devdisr2 & ~FMAN2_ALL_MACS_MASK;
iowrite32be(reg, &guts_regs->devdisr2);
iowrite32be(FPM_RSTC_FM_RESET, &fman->fpm_regs->fm_rstc);
count = 100;
do {
udelay(1);
} while (((ioread32be(&fman->fpm_regs->fm_rstc)) &
FPM_RSTC_FM_RESET) && --count);
if (count == 0) {
iounmap(guts_regs);
of_node_put(guts_node);
err = -EBUSY;
goto _return;
}
iowrite32be(devdisr2, &guts_regs->devdisr2);
iounmap(guts_regs);
of_node_put(guts_node);
goto _return;
guts_regs:
of_node_put(guts_node);
guts_node:
dev_dbg(fman->dev, "%s: Didn't perform FManV3 reset due to Errata A007273!\n",
__func__);
}
_return:
return err;
}
static int fman_init(struct fman *fman)
{
struct fman_cfg *cfg = NULL;
int err = 0, i, count;
if (is_init_done(fman->cfg))
return -EINVAL;
fman->state->count1_micro_bit = FM_TIMESTAMP_1_USEC_BIT;
cfg = fman->cfg;
if (fman->state->rev_info.major < 6)
fman->state->exceptions &= ~FMAN_EX_BMI_DISPATCH_RAM_ECC;
if (fman->state->rev_info.major >= 6)
fman->state->exceptions &= ~FMAN_EX_QMI_SINGLE_ECC;
memset_io((void __iomem *)(fman->base_addr + CGP_OFFSET), 0,
fman->state->fm_port_num_of_cg);
for (i = 1; i < FMAN_LIODN_TBL; i++) {
u32 liodn_base;
fman->liodn_offset[i] =
ioread32be(&fman->bmi_regs->fmbm_spliodn[i - 1]);
liodn_base = ioread32be(&fman->dma_regs->fmdmplr[i / 2]);
if (i % 2) {
liodn_base &= DMA_LIODN_BASE_MASK;
} else {
liodn_base >>= DMA_LIODN_SHIFT;
liodn_base &= DMA_LIODN_BASE_MASK;
}
fman->liodn_base[i] = liodn_base;
}
err = fman_reset(fman);
if (err)
return err;
if (ioread32be(&fman->qmi_regs->fmqm_gs) & QMI_GS_HALT_NOT_BUSY) {
resume(fman->fpm_regs);
count = 100;
do {
udelay(1);
} while (((ioread32be(&fman->qmi_regs->fmqm_gs)) &
QMI_GS_HALT_NOT_BUSY) && --count);
if (count == 0)
dev_warn(fman->dev, "%s: QMI is in halt not busy state\n",
__func__);
}
if (clear_iram(fman) != 0)
return -EINVAL;
cfg->exceptions = fman->state->exceptions;
err = dma_init(fman);
if (err != 0) {
free_init_resources(fman);
return err;
}
fpm_init(fman->fpm_regs, fman->cfg);
fman->fifo_offset = fman_muram_alloc(fman->muram,
fman->state->total_fifo_size);
if (IS_ERR_VALUE(fman->cam_offset)) {
free_init_resources(fman);
dev_err(fman->dev, "%s: MURAM alloc for BMI FIFO failed\n",
__func__);
return -ENOMEM;
}
cfg->fifo_base_addr = fman->fifo_offset;
cfg->total_fifo_size = fman->state->total_fifo_size;
cfg->total_num_of_tasks = fman->state->total_num_of_tasks;
cfg->clk_freq = fman->state->fm_clk_freq;
bmi_init(fman->bmi_regs, fman->cfg);
qmi_init(fman->qmi_regs, fman->cfg);
err = enable(fman, cfg);
if (err != 0)
return err;
enable_time_stamp(fman);
kfree(fman->cfg);
fman->cfg = NULL;
return 0;
}
static int fman_set_exception(struct fman *fman,
enum fman_exceptions exception, bool enable)
{
u32 bit_mask = 0;
if (!is_init_done(fman->cfg))
return -EINVAL;
bit_mask = get_exception_flag(exception);
if (bit_mask) {
if (enable)
fman->state->exceptions |= bit_mask;
else
fman->state->exceptions &= ~bit_mask;
} else {
dev_err(fman->dev, "%s: Undefined exception (%d)\n",
__func__, exception);
return -EINVAL;
}
return set_exception(fman, exception, enable);
}
void fman_register_intr(struct fman *fman, enum fman_event_modules module,
u8 mod_id, enum fman_intr_type intr_type,
void (*isr_cb)(void *src_arg), void *src_arg)
{
int event = 0;
event = get_module_event(module, mod_id, intr_type);
WARN_ON(event >= FMAN_EV_CNT);
fman->intr_mng[event].isr_cb = isr_cb;
fman->intr_mng[event].src_handle = src_arg;
}
void fman_unregister_intr(struct fman *fman, enum fman_event_modules module,
u8 mod_id, enum fman_intr_type intr_type)
{
int event = 0;
event = get_module_event(module, mod_id, intr_type);
WARN_ON(event >= FMAN_EV_CNT);
fman->intr_mng[event].isr_cb = NULL;
fman->intr_mng[event].src_handle = NULL;
}
int fman_set_port_params(struct fman *fman,
struct fman_port_init_params *port_params)
{
int err;
unsigned long flags;
u8 port_id = port_params->port_id, mac_id;
spin_lock_irqsave(&fman->spinlock, flags);
err = set_num_of_tasks(fman, port_params->port_id,
&port_params->num_of_tasks,
&port_params->num_of_extra_tasks);
if (err)
goto return_err;
if (port_params->port_type != FMAN_PORT_TYPE_RX) {
u32 enq_th, deq_th, reg;
fman->state->accumulated_num_of_deq_tnums +=
port_params->deq_pipeline_depth;
enq_th = (ioread32be(&fman->qmi_regs->fmqm_gc) &
QMI_CFG_ENQ_MASK) >> QMI_CFG_ENQ_SHIFT;
if (enq_th >= (fman->state->qmi_max_num_of_tnums -
fman->state->accumulated_num_of_deq_tnums)) {
enq_th =
fman->state->qmi_max_num_of_tnums -
fman->state->accumulated_num_of_deq_tnums - 1;
reg = ioread32be(&fman->qmi_regs->fmqm_gc);
reg &= ~QMI_CFG_ENQ_MASK;
reg |= (enq_th << QMI_CFG_ENQ_SHIFT);
iowrite32be(reg, &fman->qmi_regs->fmqm_gc);
}
deq_th = ioread32be(&fman->qmi_regs->fmqm_gc) &
QMI_CFG_DEQ_MASK;
if ((deq_th <= fman->state->accumulated_num_of_deq_tnums) &&
(deq_th < fman->state->qmi_max_num_of_tnums - 1)) {
deq_th = fman->state->accumulated_num_of_deq_tnums + 1;
reg = ioread32be(&fman->qmi_regs->fmqm_gc);
reg &= ~QMI_CFG_DEQ_MASK;
reg |= deq_th;
iowrite32be(reg, &fman->qmi_regs->fmqm_gc);
}
}
err = set_size_of_fifo(fman, port_params->port_id,
&port_params->size_of_fifo,
&port_params->extra_size_of_fifo);
if (err)
goto return_err;
err = set_num_of_open_dmas(fman, port_params->port_id,
&port_params->num_of_open_dmas,
&port_params->num_of_extra_open_dmas);
if (err)
goto return_err;
set_port_liodn(fman, port_id, fman->liodn_base[port_id],
fman->liodn_offset[port_id]);
if (fman->state->rev_info.major < 6)
set_port_order_restoration(fman->fpm_regs, port_id);
mac_id = hw_port_id_to_sw_port_id(fman->state->rev_info.major, port_id);
if (port_params->max_frame_length >= fman->state->mac_mfl[mac_id]) {
fman->state->port_mfl[mac_id] = port_params->max_frame_length;
} else {
dev_warn(fman->dev, "%s: Port (%d) max_frame_length is smaller than MAC (%d) current MTU\n",
__func__, port_id, mac_id);
err = -EINVAL;
goto return_err;
}
spin_unlock_irqrestore(&fman->spinlock, flags);
return 0;
return_err:
spin_unlock_irqrestore(&fman->spinlock, flags);
return err;
}
int fman_reset_mac(struct fman *fman, u8 mac_id)
{
struct fman_fpm_regs __iomem *fpm_rg = fman->fpm_regs;
u32 msk, timeout = 100;
if (fman->state->rev_info.major >= 6) {
dev_err(fman->dev, "%s: FMan MAC reset no available for FMan V3!\n",
__func__);
return -EINVAL;
}
switch (mac_id) {
case 0:
msk = FPM_RSTC_MAC0_RESET;
break;
case 1:
msk = FPM_RSTC_MAC1_RESET;
break;
case 2:
msk = FPM_RSTC_MAC2_RESET;
break;
case 3:
msk = FPM_RSTC_MAC3_RESET;
break;
case 4:
msk = FPM_RSTC_MAC4_RESET;
break;
case 5:
msk = FPM_RSTC_MAC5_RESET;
break;
case 6:
msk = FPM_RSTC_MAC6_RESET;
break;
case 7:
msk = FPM_RSTC_MAC7_RESET;
break;
case 8:
msk = FPM_RSTC_MAC8_RESET;
break;
case 9:
msk = FPM_RSTC_MAC9_RESET;
break;
default:
dev_warn(fman->dev, "%s: Illegal MAC Id [%d]\n",
__func__, mac_id);
return -EINVAL;
}
iowrite32be(msk, &fpm_rg->fm_rstc);
while ((ioread32be(&fpm_rg->fm_rstc) & msk) && --timeout)
udelay(10);
if (!timeout)
return -EIO;
return 0;
}
int fman_set_mac_max_frame(struct fman *fman, u8 mac_id, u16 mfl)
{
if ((!fman->state->port_mfl[mac_id]) ||
(fman->state->port_mfl[mac_id] &&
(mfl <= fman->state->port_mfl[mac_id]))) {
fman->state->mac_mfl[mac_id] = mfl;
} else {
dev_warn(fman->dev, "%s: MAC max_frame_length is larger than Port max_frame_length\n",
__func__);
return -EINVAL;
}
return 0;
}
u16 fman_get_clock_freq(struct fman *fman)
{
return fman->state->fm_clk_freq;
}
u32 fman_get_bmi_max_fifo_size(struct fman *fman)
{
return fman->state->bmi_max_fifo_size;
}
void fman_get_revision(struct fman *fman, struct fman_rev_info *rev_info)
{
u32 tmp;
tmp = ioread32be(&fman->fpm_regs->fm_ip_rev_1);
rev_info->major = (u8)((tmp & FPM_REV1_MAJOR_MASK) >>
FPM_REV1_MAJOR_SHIFT);
rev_info->minor = tmp & FPM_REV1_MINOR_MASK;
}
u32 fman_get_qman_channel_id(struct fman *fman, u32 port_id)
{
int i;
if (fman->state->rev_info.major >= 6) {
u32 port_ids[] = {0x30, 0x31, 0x28, 0x29, 0x2a, 0x2b,
0x2c, 0x2d, 0x2, 0x3, 0x4, 0x5, 0x7, 0x7};
for (i = 0; i < fman->state->num_of_qman_channels; i++) {
if (port_ids[i] == port_id)
break;
}
} else {
u32 port_ids[] = {0x30, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x1,
0x2, 0x3, 0x4, 0x5, 0x7, 0x7};
for (i = 0; i < fman->state->num_of_qman_channels; i++) {
if (port_ids[i] == port_id)
break;
}
}
if (i == fman->state->num_of_qman_channels)
return 0;
return fman->state->qman_channel_base + i;
}
struct resource *fman_get_mem_region(struct fman *fman)
{
return fman->state->res;
}
u16 fman_get_max_frm(void)
{
static bool fm_check_mfl;
if (!fm_check_mfl) {
if (fsl_fm_max_frm > FSL_FM_MAX_POSSIBLE_FRAME_SIZE ||
fsl_fm_max_frm < FSL_FM_MIN_POSSIBLE_FRAME_SIZE) {
pr_warn("Invalid fsl_fm_max_frm value (%d) in bootargs, valid range is %d-%d. Falling back to the default (%d)\n",
fsl_fm_max_frm,
FSL_FM_MIN_POSSIBLE_FRAME_SIZE,
FSL_FM_MAX_POSSIBLE_FRAME_SIZE,
FSL_FM_MAX_FRAME_SIZE);
fsl_fm_max_frm = FSL_FM_MAX_FRAME_SIZE;
}
fm_check_mfl = true;
}
return fsl_fm_max_frm;
}
int fman_get_rx_extra_headroom(void)
{
static bool fm_check_rx_extra_headroom;
if (!fm_check_rx_extra_headroom) {
if (fsl_fm_rx_extra_headroom > FSL_FM_RX_EXTRA_HEADROOM_MAX ||
fsl_fm_rx_extra_headroom < FSL_FM_RX_EXTRA_HEADROOM_MIN) {
pr_warn("Invalid fsl_fm_rx_extra_headroom value (%d) in bootargs, valid range is %d-%d. Falling back to the default (%d)\n",
fsl_fm_rx_extra_headroom,
FSL_FM_RX_EXTRA_HEADROOM_MIN,
FSL_FM_RX_EXTRA_HEADROOM_MAX,
FSL_FM_RX_EXTRA_HEADROOM);
fsl_fm_rx_extra_headroom = FSL_FM_RX_EXTRA_HEADROOM;
}
fm_check_rx_extra_headroom = true;
fsl_fm_rx_extra_headroom = ALIGN(fsl_fm_rx_extra_headroom, 16);
}
return fsl_fm_rx_extra_headroom;
}
struct fman *fman_bind(struct device *fm_dev)
{
return (struct fman *)(dev_get_drvdata(get_device(fm_dev)));
}
static irqreturn_t fman_err_irq(int irq, void *handle)
{
struct fman *fman = (struct fman *)handle;
u32 pending;
struct fman_fpm_regs __iomem *fpm_rg;
irqreturn_t single_ret, ret = IRQ_NONE;
if (!is_init_done(fman->cfg))
return IRQ_NONE;
fpm_rg = fman->fpm_regs;
pending = ioread32be(&fpm_rg->fm_epi);
if (!pending)
return IRQ_NONE;
if (pending & ERR_INTR_EN_BMI) {
single_ret = bmi_err_event(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_QMI) {
single_ret = qmi_err_event(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_FPM) {
single_ret = fpm_err_event(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_DMA) {
single_ret = dma_err_event(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MURAM) {
single_ret = muram_err_intr(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC0) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 0);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC1) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 1);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC2) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 2);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC3) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 3);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC4) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 4);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC5) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 5);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC6) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 6);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC7) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 7);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC8) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 8);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & ERR_INTR_EN_MAC9) {
single_ret = call_mac_isr(fman, FMAN_EV_ERR_MAC0 + 9);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
return ret;
}
static irqreturn_t fman_irq(int irq, void *handle)
{
struct fman *fman = (struct fman *)handle;
u32 pending;
struct fman_fpm_regs __iomem *fpm_rg;
irqreturn_t single_ret, ret = IRQ_NONE;
if (!is_init_done(fman->cfg))
return IRQ_NONE;
fpm_rg = fman->fpm_regs;
pending = ioread32be(&fpm_rg->fm_npi);
if (!pending)
return IRQ_NONE;
if (pending & INTR_EN_QMI) {
single_ret = qmi_event(fman);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC0) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 0);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC1) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 1);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC2) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 2);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC3) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 3);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC4) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 4);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC5) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 5);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC6) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 6);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC7) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 7);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC8) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 8);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
if (pending & INTR_EN_MAC9) {
single_ret = call_mac_isr(fman, FMAN_EV_MAC0 + 9);
if (single_ret == IRQ_HANDLED)
ret = IRQ_HANDLED;
}
return ret;
}
static struct fman *read_dts_node(struct platform_device *of_dev)
{
struct fman *fman;
struct device_node *fm_node, *muram_node;
struct resource *res;
const u32 *u32_prop;
int lenp, err, irq;
struct clk *clk;
u32 clk_rate;
phys_addr_t phys_base_addr;
resource_size_t mem_size;
fman = kzalloc(sizeof(*fman), GFP_KERNEL);
if (!fman)
return NULL;
fm_node = of_node_get(of_dev->dev.of_node);
u32_prop = (const u32 *)of_get_property(fm_node, "cell-index", &lenp);
if (!u32_prop) {
dev_err(&of_dev->dev, "%s: of_get_property(%s, cell-index) failed\n",
__func__, fm_node->full_name);
goto fman_node_put;
}
if (WARN_ON(lenp != sizeof(u32)))
goto fman_node_put;
fman->dts_params.id = (u8)fdt32_to_cpu(u32_prop[0]);
res = platform_get_resource(of_dev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&of_dev->dev, "%s: Can't get FMan IRQ resource\n",
__func__);
goto fman_node_put;
}
irq = res->start;
res = platform_get_resource(of_dev, IORESOURCE_IRQ, 1);
if (!res) {
dev_err(&of_dev->dev, "%s: Can't get FMan Error IRQ resource\n",
__func__);
goto fman_node_put;
}
fman->dts_params.err_irq = res->start;
res = platform_get_resource(of_dev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&of_dev->dev, "%s: Can't get FMan memory resource\n",
__func__);
goto fman_node_put;
}
phys_base_addr = res->start;
mem_size = resource_size(res);
clk = of_clk_get(fm_node, 0);
if (IS_ERR(clk)) {
dev_err(&of_dev->dev, "%s: Failed to get FM%d clock structure\n",
__func__, fman->dts_params.id);
goto fman_node_put;
}
clk_rate = clk_get_rate(clk);
if (!clk_rate) {
dev_err(&of_dev->dev, "%s: Failed to determine FM%d clock rate\n",
__func__, fman->dts_params.id);
goto fman_node_put;
}
fman->dts_params.clk_freq = DIV_ROUND_UP(clk_rate, 1000000);
u32_prop = (const u32 *)of_get_property(fm_node,
"fsl,qman-channel-range",
&lenp);
if (!u32_prop) {
dev_err(&of_dev->dev, "%s: of_get_property(%s, fsl,qman-channel-range) failed\n",
__func__, fm_node->full_name);
goto fman_node_put;
}
if (WARN_ON(lenp != sizeof(u32) * 2))
goto fman_node_put;
fman->dts_params.qman_channel_base = fdt32_to_cpu(u32_prop[0]);
fman->dts_params.num_of_qman_channels = fdt32_to_cpu(u32_prop[1]);
muram_node = of_find_matching_node(fm_node, fman_muram_match);
if (!muram_node) {
dev_err(&of_dev->dev, "%s: could not find MURAM node\n",
__func__);
goto fman_node_put;
}
err = of_address_to_resource(muram_node, 0,
&fman->dts_params.muram_res);
if (err) {
of_node_put(muram_node);
dev_err(&of_dev->dev, "%s: of_address_to_resource() = %d\n",
__func__, err);
goto fman_node_put;
}
of_node_put(muram_node);
of_node_put(fm_node);
err = devm_request_irq(&of_dev->dev, irq, fman_irq, 0, "fman", fman);
if (err < 0) {
dev_err(&of_dev->dev, "%s: irq %d allocation failed (error = %d)\n",
__func__, irq, err);
goto fman_free;
}
if (fman->dts_params.err_irq != 0) {
err = devm_request_irq(&of_dev->dev, fman->dts_params.err_irq,
fman_err_irq, IRQF_SHARED,
"fman-err", fman);
if (err < 0) {
dev_err(&of_dev->dev, "%s: irq %d allocation failed (error = %d)\n",
__func__, fman->dts_params.err_irq, err);
goto fman_free;
}
}
fman->dts_params.res =
devm_request_mem_region(&of_dev->dev, phys_base_addr,
mem_size, "fman");
if (!fman->dts_params.res) {
dev_err(&of_dev->dev, "%s: request_mem_region() failed\n",
__func__);
goto fman_free;
}
fman->dts_params.base_addr =
devm_ioremap(&of_dev->dev, phys_base_addr, mem_size);
if (fman->dts_params.base_addr == 0) {
dev_err(&of_dev->dev, "%s: devm_ioremap() failed\n", __func__);
goto fman_free;
}
fman->dev = &of_dev->dev;
return fman;
fman_node_put:
of_node_put(fm_node);
fman_free:
kfree(fman);
return NULL;
}
static int fman_probe(struct platform_device *of_dev)
{
struct fman *fman;
struct device *dev;
int err;
dev = &of_dev->dev;
fman = read_dts_node(of_dev);
if (!fman)
return -EIO;
err = fman_config(fman);
if (err) {
dev_err(dev, "%s: FMan config failed\n", __func__);
return -EINVAL;
}
if (fman_init(fman) != 0) {
dev_err(dev, "%s: FMan init failed\n", __func__);
return -EINVAL;
}
if (fman->dts_params.err_irq == 0) {
fman_set_exception(fman, FMAN_EX_DMA_BUS_ERROR, false);
fman_set_exception(fman, FMAN_EX_DMA_READ_ECC, false);
fman_set_exception(fman, FMAN_EX_DMA_SYSTEM_WRITE_ECC, false);
fman_set_exception(fman, FMAN_EX_DMA_FM_WRITE_ECC, false);
fman_set_exception(fman, FMAN_EX_DMA_SINGLE_PORT_ECC, false);
fman_set_exception(fman, FMAN_EX_FPM_STALL_ON_TASKS, false);
fman_set_exception(fman, FMAN_EX_FPM_SINGLE_ECC, false);
fman_set_exception(fman, FMAN_EX_FPM_DOUBLE_ECC, false);
fman_set_exception(fman, FMAN_EX_QMI_SINGLE_ECC, false);
fman_set_exception(fman, FMAN_EX_QMI_DOUBLE_ECC, false);
fman_set_exception(fman,
FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID, false);
fman_set_exception(fman, FMAN_EX_BMI_LIST_RAM_ECC, false);
fman_set_exception(fman, FMAN_EX_BMI_STORAGE_PROFILE_ECC,
false);
fman_set_exception(fman, FMAN_EX_BMI_STATISTICS_RAM_ECC, false);
fman_set_exception(fman, FMAN_EX_BMI_DISPATCH_RAM_ECC, false);
}
dev_set_drvdata(dev, fman);
dev_dbg(dev, "FMan%d probed\n", fman->dts_params.id);
return 0;
}
