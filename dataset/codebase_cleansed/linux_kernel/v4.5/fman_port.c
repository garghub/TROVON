static int init_bmi_rx(struct fman_port *port)
{
struct fman_port_rx_bmi_regs __iomem *regs = &port->bmi_regs->rx;
struct fman_port_cfg *cfg = port->cfg;
u32 tmp;
tmp = (u32)cfg->dma_swap_data << BMI_DMA_ATTR_SWP_SHIFT;
tmp |= BMI_DMA_ATTR_WRITE_OPTIMIZE;
iowrite32be(tmp, &regs->fmbm_rda);
tmp = (cfg->rx_pri_elevation / PORT_BMI_FIFO_UNITS - 1) <<
BMI_RX_FIFO_PRI_ELEVATION_SHIFT;
tmp |= cfg->rx_fifo_thr / PORT_BMI_FIFO_UNITS - 1;
iowrite32be(tmp, &regs->fmbm_rfp);
if (cfg->excessive_threshold_register)
iowrite32be(BMI_RX_FIFO_THRESHOLD_ETHE, &regs->fmbm_reth);
tmp = (cfg->cheksum_last_bytes_ignore & BMI_FRAME_END_CS_IGNORE_MASK) <<
BMI_FRAME_END_CS_IGNORE_SHIFT;
tmp |= (cfg->rx_cut_end_bytes & BMI_RX_FRAME_END_CUT_MASK) <<
BMI_RX_FRAME_END_CUT_SHIFT;
if (cfg->errata_A006320)
tmp &= 0xffe0ffff;
iowrite32be(tmp, &regs->fmbm_rfed);
tmp = ((cfg->int_context.ext_buf_offset / PORT_IC_OFFSET_UNITS) &
BMI_IC_TO_EXT_MASK) << BMI_IC_TO_EXT_SHIFT;
tmp |= ((cfg->int_context.int_context_offset / PORT_IC_OFFSET_UNITS) &
BMI_IC_FROM_INT_MASK) << BMI_IC_FROM_INT_SHIFT;
tmp |= (cfg->int_context.size / PORT_IC_OFFSET_UNITS) &
BMI_IC_SIZE_MASK;
iowrite32be(tmp, &regs->fmbm_ricp);
tmp = ((cfg->int_buf_start_margin / PORT_IC_OFFSET_UNITS) &
BMI_INT_BUF_MARG_MASK) << BMI_INT_BUF_MARG_SHIFT;
iowrite32be(tmp, &regs->fmbm_rim);
tmp = (cfg->buf_margins.start_margins & BMI_EXT_BUF_MARG_START_MASK) <<
BMI_EXT_BUF_MARG_START_SHIFT;
tmp |= cfg->buf_margins.end_margins & BMI_EXT_BUF_MARG_END_MASK;
iowrite32be(tmp, &regs->fmbm_rebm);
tmp = BMI_CMD_RX_MR_DEF;
tmp |= BMI_CMD_ATTR_ORDER;
tmp |= (u32)cfg->color << BMI_CMD_ATTR_COLOR_SHIFT;
tmp |= BMI_CMD_ATTR_SYNC;
iowrite32be(tmp, &regs->fmbm_rfca);
tmp = (u32)cfg->rx_fd_bits << BMI_NEXT_ENG_FD_BITS_SHIFT;
tmp |= NIA_ENG_BMI | NIA_BMI_AC_ENQ_FRAME;
iowrite32be(tmp, &regs->fmbm_rfne);
iowrite32be(NIA_ENG_QMI_ENQ | NIA_ORDER_RESTOR, &regs->fmbm_rfene);
iowrite32be((cfg->dflt_fqid & DFLT_FQ_ID), &regs->fmbm_rfqid);
iowrite32be((cfg->err_fqid & DFLT_FQ_ID), &regs->fmbm_refqid);
iowrite32be(cfg->discard_mask, &regs->fmbm_rfsdm);
iowrite32be(cfg->err_mask, &regs->fmbm_rfsem);
return 0;
}
static int init_bmi_tx(struct fman_port *port)
{
struct fman_port_tx_bmi_regs __iomem *regs = &port->bmi_regs->tx;
struct fman_port_cfg *cfg = port->cfg;
u32 tmp;
tmp = 0;
iowrite32be(tmp, &regs->fmbm_tcfg);
tmp = (u32)cfg->dma_swap_data << BMI_DMA_ATTR_SWP_SHIFT;
iowrite32be(tmp, &regs->fmbm_tda);
tmp = (cfg->tx_fifo_min_level / PORT_BMI_FIFO_UNITS) <<
BMI_TX_FIFO_MIN_FILL_SHIFT;
tmp |= ((cfg->tx_fifo_deq_pipeline_depth - 1) &
BMI_FIFO_PIPELINE_DEPTH_MASK) << BMI_FIFO_PIPELINE_DEPTH_SHIFT;
tmp |= (cfg->tx_fifo_low_comf_level / PORT_BMI_FIFO_UNITS) - 1;
iowrite32be(tmp, &regs->fmbm_tfp);
tmp = (cfg->cheksum_last_bytes_ignore & BMI_FRAME_END_CS_IGNORE_MASK) <<
BMI_FRAME_END_CS_IGNORE_SHIFT;
iowrite32be(tmp, &regs->fmbm_tfed);
tmp = ((cfg->int_context.ext_buf_offset / PORT_IC_OFFSET_UNITS) &
BMI_IC_TO_EXT_MASK) << BMI_IC_TO_EXT_SHIFT;
tmp |= ((cfg->int_context.int_context_offset / PORT_IC_OFFSET_UNITS) &
BMI_IC_FROM_INT_MASK) << BMI_IC_FROM_INT_SHIFT;
tmp |= (cfg->int_context.size / PORT_IC_OFFSET_UNITS) &
BMI_IC_SIZE_MASK;
iowrite32be(tmp, &regs->fmbm_ticp);
tmp = BMI_CMD_TX_MR_DEF;
tmp |= BMI_CMD_ATTR_ORDER;
tmp |= (u32)cfg->color << BMI_CMD_ATTR_COLOR_SHIFT;
iowrite32be(tmp, &regs->fmbm_tfca);
iowrite32be(NIA_ENG_QMI_DEQ, &regs->fmbm_tfdne);
iowrite32be(NIA_ENG_QMI_ENQ | NIA_ORDER_RESTOR, &regs->fmbm_tfene);
if (cfg->fmbm_tfne_has_features)
iowrite32be(!cfg->dflt_fqid ?
BMI_EBD_EN | NIA_BMI_AC_FETCH_ALL_FRAME :
NIA_BMI_AC_FETCH_ALL_FRAME, &regs->fmbm_tfne);
if (!cfg->dflt_fqid && cfg->dont_release_buf) {
iowrite32be(DFLT_FQ_ID, &regs->fmbm_tcfqid);
iowrite32be(NIA_ENG_BMI | NIA_BMI_AC_TX_RELEASE,
&regs->fmbm_tfene);
if (cfg->fmbm_tfne_has_features)
iowrite32be(ioread32be(&regs->fmbm_tfne) & ~BMI_EBD_EN,
&regs->fmbm_tfne);
}
if (cfg->dflt_fqid || !cfg->dont_release_buf)
iowrite32be(cfg->dflt_fqid & DFLT_FQ_ID, &regs->fmbm_tcfqid);
iowrite32be((cfg->err_fqid & DFLT_FQ_ID), &regs->fmbm_tefqid);
return 0;
}
static int init_qmi(struct fman_port *port)
{
struct fman_port_qmi_regs __iomem *regs = port->qmi_regs;
struct fman_port_cfg *cfg = port->cfg;
u32 tmp;
if (port->port_type == FMAN_PORT_TYPE_RX) {
iowrite32be(NIA_ENG_BMI | NIA_BMI_AC_RELEASE, &regs->fmqm_pnen);
return 0;
}
if (port->port_type == FMAN_PORT_TYPE_TX) {
iowrite32be(NIA_ENG_BMI | NIA_BMI_AC_TX_RELEASE,
&regs->fmqm_pnen);
iowrite32be(NIA_ENG_BMI | NIA_BMI_AC_TX, &regs->fmqm_pndn);
}
tmp = 0;
if (cfg->deq_high_priority)
tmp |= QMI_DEQ_CFG_PRI;
switch (cfg->deq_type) {
case FMAN_PORT_DEQ_BY_PRI:
tmp |= QMI_DEQ_CFG_TYPE1;
break;
case FMAN_PORT_DEQ_ACTIVE_FQ:
tmp |= QMI_DEQ_CFG_TYPE2;
break;
case FMAN_PORT_DEQ_ACTIVE_FQ_NO_ICS:
tmp |= QMI_DEQ_CFG_TYPE3;
break;
default:
return -EINVAL;
}
switch (cfg->deq_prefetch_option) {
case FMAN_PORT_DEQ_NO_PREFETCH:
break;
case FMAN_PORT_DEQ_PART_PREFETCH:
tmp |= QMI_DEQ_CFG_PREFETCH_PARTIAL;
break;
case FMAN_PORT_DEQ_FULL_PREFETCH:
tmp |= QMI_DEQ_CFG_PREFETCH_FULL;
break;
default:
return -EINVAL;
}
tmp |= (cfg->deq_sp & QMI_DEQ_CFG_SP_MASK) << QMI_DEQ_CFG_SP_SHIFT;
tmp |= cfg->deq_byte_cnt;
iowrite32be(tmp, &regs->fmqm_pndc);
return 0;
}
static int init(struct fman_port *port)
{
int err;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
err = init_bmi_rx(port);
break;
case FMAN_PORT_TYPE_TX:
err = init_bmi_tx(port);
break;
default:
return -EINVAL;
}
if (err)
return err;
err = init_qmi(port);
return err;
return 0;
}
static int set_bpools(const struct fman_port *port,
const struct fman_port_bpools *bp)
{
u32 __iomem *bp_reg, *bp_depl_reg;
u32 tmp;
u8 i, max_bp_num;
bool grp_depl_used = false, rx_port;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
max_bp_num = port->ext_pools_num;
rx_port = true;
bp_reg = port->bmi_regs->rx.fmbm_ebmpi;
bp_depl_reg = &port->bmi_regs->rx.fmbm_mpd;
break;
default:
return -EINVAL;
}
if (rx_port) {
for (i = 0; (i < (bp->count - 1) &&
(i < FMAN_PORT_MAX_EXT_POOLS_NUM - 1)); i++) {
if (bp->bpool[i].size > bp->bpool[i + 1].size)
return -EINVAL;
}
}
for (i = 0; i < bp->count; i++) {
tmp = BMI_EXT_BUF_POOL_VALID;
tmp |= ((u32)bp->bpool[i].bpid <<
BMI_EXT_BUF_POOL_ID_SHIFT) & BMI_EXT_BUF_POOL_ID_MASK;
if (rx_port) {
if (bp->counters_enable)
tmp |= BMI_EXT_BUF_POOL_EN_COUNTER;
if (bp->bpool[i].is_backup)
tmp |= BMI_EXT_BUF_POOL_BACKUP;
tmp |= (u32)bp->bpool[i].size;
}
iowrite32be(tmp, &bp_reg[i]);
}
for (i = bp->count; i < max_bp_num; i++)
iowrite32be(0, &bp_reg[i]);
tmp = 0;
for (i = 0; i < FMAN_PORT_MAX_EXT_POOLS_NUM; i++) {
if (bp->bpool[i].grp_bp_depleted) {
grp_depl_used = true;
tmp |= 0x80000000 >> i;
}
if (bp->bpool[i].single_bp_depleted)
tmp |= 0x80 >> i;
}
if (grp_depl_used)
tmp |= ((u32)bp->grp_bp_depleted_num - 1) <<
BMI_POOL_DEP_NUM_OF_POOLS_SHIFT;
iowrite32be(tmp, bp_depl_reg);
return 0;
}
static bool is_init_done(struct fman_port_cfg *cfg)
{
if (!cfg)
return true;
return false;
}
static int verify_size_of_fifo(struct fman_port *port)
{
u32 min_fifo_size_required = 0, opt_fifo_size_for_b2b = 0;
if (port->port_type == FMAN_PORT_TYPE_TX) {
min_fifo_size_required = (u32)
(roundup(port->max_frame_length,
FMAN_BMI_FIFO_UNITS) + (3 * FMAN_BMI_FIFO_UNITS));
min_fifo_size_required +=
port->cfg->tx_fifo_deq_pipeline_depth *
FMAN_BMI_FIFO_UNITS;
opt_fifo_size_for_b2b = min_fifo_size_required;
if (port->port_speed == 10000)
opt_fifo_size_for_b2b += 3 * FMAN_BMI_FIFO_UNITS;
else
opt_fifo_size_for_b2b += 2 * FMAN_BMI_FIFO_UNITS;
}
else if (port->port_type == FMAN_PORT_TYPE_RX) {
if (port->rev_info.major >= 6)
min_fifo_size_required = (u32)
(roundup(port->max_frame_length,
FMAN_BMI_FIFO_UNITS) +
(5 * FMAN_BMI_FIFO_UNITS));
else
min_fifo_size_required = (u32)
(roundup(min(port->max_frame_length,
port->rx_pools_params.largest_buf_size),
FMAN_BMI_FIFO_UNITS) +
(7 * FMAN_BMI_FIFO_UNITS));
opt_fifo_size_for_b2b = min_fifo_size_required;
if (port->port_speed == 10000)
opt_fifo_size_for_b2b += 8 * FMAN_BMI_FIFO_UNITS;
else
opt_fifo_size_for_b2b += 3 * FMAN_BMI_FIFO_UNITS;
}
WARN_ON(min_fifo_size_required <= 0);
WARN_ON(opt_fifo_size_for_b2b < min_fifo_size_required);
if (port->fifo_bufs.num < min_fifo_size_required)
dev_dbg(port->dev, "%s: FIFO size should be enlarged to %d bytes\n",
__func__, min_fifo_size_required);
else if (port->fifo_bufs.num < opt_fifo_size_for_b2b)
dev_dbg(port->dev, "%s: For b2b processing,FIFO may be enlarged to %d bytes\n",
__func__, opt_fifo_size_for_b2b);
return 0;
}
static int set_ext_buffer_pools(struct fman_port *port)
{
struct fman_ext_pools *ext_buf_pools = &port->cfg->ext_buf_pools;
struct fman_buf_pool_depletion *buf_pool_depletion =
&port->cfg->buf_pool_depletion;
u8 ordered_array[FMAN_PORT_MAX_EXT_POOLS_NUM];
u16 sizes_array[BM_MAX_NUM_OF_POOLS];
int i = 0, j = 0, err;
struct fman_port_bpools bpools;
memset(&ordered_array, 0, sizeof(u8) * FMAN_PORT_MAX_EXT_POOLS_NUM);
memset(&sizes_array, 0, sizeof(u16) * BM_MAX_NUM_OF_POOLS);
memcpy(&port->ext_buf_pools, ext_buf_pools,
sizeof(struct fman_ext_pools));
fman_sp_set_buf_pools_in_asc_order_of_buf_sizes(ext_buf_pools,
ordered_array,
sizes_array);
memset(&bpools, 0, sizeof(struct fman_port_bpools));
bpools.count = ext_buf_pools->num_of_pools_used;
bpools.counters_enable = true;
for (i = 0; i < ext_buf_pools->num_of_pools_used; i++) {
bpools.bpool[i].bpid = ordered_array[i];
bpools.bpool[i].size = sizes_array[ordered_array[i]];
}
port->rx_pools_params.num_of_pools = ext_buf_pools->num_of_pools_used;
port->rx_pools_params.largest_buf_size =
sizes_array[ordered_array[ext_buf_pools->num_of_pools_used - 1]];
port->rx_pools_params.second_largest_buf_size =
sizes_array[ordered_array[ext_buf_pools->num_of_pools_used - 2]];
if (buf_pool_depletion->pools_grp_mode_enable) {
bpools.grp_bp_depleted_num = buf_pool_depletion->num_of_pools;
for (i = 0; i < port->bm_max_num_of_pools; i++) {
if (buf_pool_depletion->pools_to_consider[i]) {
for (j = 0; j < ext_buf_pools->
num_of_pools_used; j++) {
if (i == ordered_array[j]) {
bpools.bpool[j].
grp_bp_depleted = true;
break;
}
}
}
}
}
if (buf_pool_depletion->single_pool_mode_enable) {
for (i = 0; i < port->bm_max_num_of_pools; i++) {
if (buf_pool_depletion->
pools_to_consider_for_single_mode[i]) {
for (j = 0; j < ext_buf_pools->
num_of_pools_used; j++) {
if (i == ordered_array[j]) {
bpools.bpool[j].
single_bp_depleted = true;
break;
}
}
}
}
}
err = set_bpools(port, &bpools);
if (err != 0) {
dev_err(port->dev, "%s: set_bpools() failed\n", __func__);
return -EINVAL;
}
return 0;
}
static int init_low_level_driver(struct fman_port *port)
{
struct fman_port_cfg *cfg = port->cfg;
u32 tmp_val;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
cfg->err_mask = (RX_ERRS_TO_ENQ & ~cfg->discard_mask);
break;
default:
break;
}
tmp_val = (u32)((port->internal_buf_offset % OFFSET_UNITS) ?
(port->internal_buf_offset / OFFSET_UNITS + 1) :
(port->internal_buf_offset / OFFSET_UNITS));
port->internal_buf_offset = (u8)(tmp_val * OFFSET_UNITS);
port->cfg->int_buf_start_margin = port->internal_buf_offset;
if (init(port) != 0) {
dev_err(port->dev, "%s: fman port initialization failed\n",
__func__);
return -ENODEV;
}
if (port->port_type == FMAN_PORT_TYPE_TX) {
if (!cfg->dflt_fqid && cfg->dont_release_buf) {
iowrite32be(0xFFFFFF, &port->bmi_regs->tx.fmbm_tcfqid);
iowrite32be(NIA_ENG_BMI | NIA_BMI_AC_TX_RELEASE,
&port->bmi_regs->tx.fmbm_tfene);
}
}
return 0;
}
static int fill_soc_specific_params(struct fman_port *port)
{
u32 bmi_max_fifo_size;
bmi_max_fifo_size = fman_get_bmi_max_fifo_size(port->fm);
port->max_port_fifo_size = MAX_PORT_FIFO_SIZE(bmi_max_fifo_size);
port->bm_max_num_of_pools = 64;
switch (port->rev_info.major) {
case 2:
case 3:
port->max_num_of_ext_pools = 4;
port->max_num_of_sub_portals = 12;
break;
case 6:
port->max_num_of_ext_pools = 8;
port->max_num_of_sub_portals = 16;
break;
default:
dev_err(port->dev, "%s: Unsupported FMan version\n", __func__);
return -EINVAL;
}
return 0;
}
static int get_dflt_fifo_deq_pipeline_depth(u8 major, enum fman_port_type type,
u16 speed)
{
switch (type) {
case FMAN_PORT_TYPE_RX:
case FMAN_PORT_TYPE_TX:
switch (speed) {
case 10000:
return 4;
case 1000:
if (major >= 6)
return 2;
else
return 1;
default:
return 0;
}
default:
return 0;
}
}
static int get_dflt_num_of_tasks(u8 major, enum fman_port_type type,
u16 speed)
{
switch (type) {
case FMAN_PORT_TYPE_RX:
case FMAN_PORT_TYPE_TX:
switch (speed) {
case 10000:
return 16;
case 1000:
if (major >= 6)
return 4;
else
return 3;
default:
return 0;
}
default:
return 0;
}
}
static int get_dflt_extra_num_of_tasks(u8 major, enum fman_port_type type,
u16 speed)
{
switch (type) {
case FMAN_PORT_TYPE_RX:
if (major >= 6)
return 0;
if (speed == 10000)
return 8;
else
return 2;
case FMAN_PORT_TYPE_TX:
default:
return 0;
}
}
static int get_dflt_num_of_open_dmas(u8 major, enum fman_port_type type,
u16 speed)
{
int val;
if (major >= 6) {
switch (type) {
case FMAN_PORT_TYPE_TX:
if (speed == 10000)
val = 12;
else
val = 3;
break;
case FMAN_PORT_TYPE_RX:
if (speed == 10000)
val = 8;
else
val = 2;
break;
default:
return 0;
}
} else {
switch (type) {
case FMAN_PORT_TYPE_TX:
case FMAN_PORT_TYPE_RX:
if (speed == 10000)
val = 8;
else
val = 1;
break;
default:
val = 0;
}
}
return val;
}
static int get_dflt_extra_num_of_open_dmas(u8 major, enum fman_port_type type,
u16 speed)
{
if (major >= 6)
return 0;
switch (type) {
case FMAN_PORT_TYPE_RX:
case FMAN_PORT_TYPE_TX:
if (speed == 10000)
return 8;
else
return 1;
default:
return 0;
}
}
static int get_dflt_num_of_fifo_bufs(u8 major, enum fman_port_type type,
u16 speed)
{
int val;
if (major >= 6) {
switch (type) {
case FMAN_PORT_TYPE_TX:
if (speed == 10000)
val = 64;
else
val = 50;
break;
case FMAN_PORT_TYPE_RX:
if (speed == 10000)
val = 96;
else
val = 50;
break;
default:
val = 0;
}
} else {
switch (type) {
case FMAN_PORT_TYPE_TX:
if (speed == 10000)
val = 48;
else
val = 44;
break;
case FMAN_PORT_TYPE_RX:
if (speed == 10000)
val = 48;
else
val = 45;
break;
default:
val = 0;
}
}
return val;
}
static void set_dflt_cfg(struct fman_port *port,
struct fman_port_params *port_params)
{
struct fman_port_cfg *cfg = port->cfg;
cfg->dma_swap_data = FMAN_PORT_DMA_NO_SWAP;
cfg->color = FMAN_PORT_COLOR_GREEN;
cfg->rx_cut_end_bytes = DFLT_PORT_CUT_BYTES_FROM_END;
cfg->rx_pri_elevation = BMI_PRIORITY_ELEVATION_LEVEL;
cfg->rx_fifo_thr = BMI_FIFO_THRESHOLD;
cfg->tx_fifo_low_comf_level = (5 * 1024);
cfg->deq_type = FMAN_PORT_DEQ_BY_PRI;
cfg->deq_prefetch_option = FMAN_PORT_DEQ_FULL_PREFETCH;
cfg->tx_fifo_deq_pipeline_depth =
BMI_DEQUEUE_PIPELINE_DEPTH(port->port_type, port->port_speed);
cfg->deq_byte_cnt = QMI_BYTE_COUNT_LEVEL_CONTROL(port->port_type);
cfg->rx_pri_elevation =
DFLT_PORT_RX_FIFO_PRI_ELEVATION_LEV(port->max_port_fifo_size);
port->cfg->rx_fifo_thr =
DFLT_PORT_RX_FIFO_THRESHOLD(port->rev_info.major,
port->max_port_fifo_size);
if ((port->rev_info.major == 6) &&
((port->rev_info.minor == 0) || (port->rev_info.minor == 3)))
cfg->errata_A006320 = true;
if (port->rev_info.major < 6)
cfg->excessive_threshold_register = true;
else
cfg->fmbm_tfne_has_features = true;
cfg->buffer_prefix_content.data_align =
DFLT_PORT_BUFFER_PREFIX_CONTEXT_DATA_ALIGN;
}
static void set_rx_dflt_cfg(struct fman_port *port,
struct fman_port_params *port_params)
{
port->cfg->discard_mask = DFLT_PORT_ERRORS_TO_DISCARD;
memcpy(&port->cfg->ext_buf_pools,
&port_params->specific_params.rx_params.ext_buf_pools,
sizeof(struct fman_ext_pools));
port->cfg->err_fqid =
port_params->specific_params.rx_params.err_fqid;
port->cfg->dflt_fqid =
port_params->specific_params.rx_params.dflt_fqid;
}
static void set_tx_dflt_cfg(struct fman_port *port,
struct fman_port_params *port_params,
struct fman_port_dts_params *dts_params)
{
port->cfg->tx_fifo_deq_pipeline_depth =
get_dflt_fifo_deq_pipeline_depth(port->rev_info.major,
port->port_type,
port->port_speed);
port->cfg->err_fqid =
port_params->specific_params.non_rx_params.err_fqid;
port->cfg->deq_sp =
(u8)(dts_params->qman_channel_id & QMI_DEQ_CFG_SUBPORTAL_MASK);
port->cfg->dflt_fqid =
port_params->specific_params.non_rx_params.dflt_fqid;
port->cfg->deq_high_priority = true;
}
int fman_port_config(struct fman_port *port, struct fman_port_params *params)
{
void __iomem *base_addr = port->dts_params.base_addr;
int err;
port->cfg = kzalloc(sizeof(*port->cfg), GFP_KERNEL);
if (!port->cfg)
goto err_params;
port->port_type = port->dts_params.type;
port->port_speed = port->dts_params.speed;
port->port_id = port->dts_params.id;
port->fm = port->dts_params.fman;
port->ext_pools_num = (u8)8;
fman_get_revision(port->fm, &port->rev_info);
err = fill_soc_specific_params(port);
if (err)
goto err_port_cfg;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
set_rx_dflt_cfg(port, params);
case FMAN_PORT_TYPE_TX:
set_tx_dflt_cfg(port, params, &port->dts_params);
default:
set_dflt_cfg(port, params);
}
port->bmi_regs = base_addr + BMI_PORT_REGS_OFFSET;
port->qmi_regs = base_addr + QMI_PORT_REGS_OFFSET;
port->max_frame_length = DFLT_PORT_MAX_FRAME_LENGTH;
port->fifo_bufs.num =
get_dflt_num_of_fifo_bufs(port->rev_info.major, port->port_type,
port->port_speed) * FMAN_BMI_FIFO_UNITS;
port->fifo_bufs.extra =
DFLT_PORT_EXTRA_NUM_OF_FIFO_BUFS * FMAN_BMI_FIFO_UNITS;
port->open_dmas.num =
get_dflt_num_of_open_dmas(port->rev_info.major,
port->port_type, port->port_speed);
port->open_dmas.extra =
get_dflt_extra_num_of_open_dmas(port->rev_info.major,
port->port_type, port->port_speed);
port->tasks.num =
get_dflt_num_of_tasks(port->rev_info.major,
port->port_type, port->port_speed);
port->tasks.extra =
get_dflt_extra_num_of_tasks(port->rev_info.major,
port->port_type, port->port_speed);
if ((port->rev_info.major == 6) && (port->rev_info.minor == 0) &&
(((port->port_type == FMAN_PORT_TYPE_TX) &&
(port->port_speed == 1000)))) {
port->open_dmas.num = 16;
port->open_dmas.extra = 0;
}
if (port->rev_info.major >= 6 &&
port->port_type == FMAN_PORT_TYPE_TX &&
port->port_speed == 1000) {
if (port->rev_info.major >= 6) {
u32 reg;
reg = 0x00001013;
iowrite32be(reg, &port->bmi_regs->tx.fmbm_tfp);
}
}
return 0;
err_port_cfg:
kfree(port->cfg);
err_params:
kfree(port);
return -EINVAL;
}
int fman_port_init(struct fman_port *port)
{
struct fman_port_cfg *cfg;
int err;
struct fman_port_init_params params;
if (is_init_done(port->cfg))
return -EINVAL;
err = fman_sp_build_buffer_struct(&port->cfg->int_context,
&port->cfg->buffer_prefix_content,
&port->cfg->buf_margins,
&port->buffer_offsets,
&port->internal_buf_offset);
if (err)
return err;
cfg = port->cfg;
if (port->port_type == FMAN_PORT_TYPE_RX) {
err = set_ext_buffer_pools(port);
if (err)
return err;
if (cfg->buf_margins.start_margins + MIN_EXT_BUF_SIZE +
cfg->buf_margins.end_margins >
port->rx_pools_params.largest_buf_size) {
dev_err(port->dev, "%s: buf_margins.start_margins (%d) + minimum buf size (64) + buf_margins.end_margins (%d) is larger than maximum external buffer size (%d)\n",
__func__, cfg->buf_margins.start_margins,
cfg->buf_margins.end_margins,
port->rx_pools_params.largest_buf_size);
return -EINVAL;
}
}
memset(&params, 0, sizeof(params));
params.port_id = port->port_id;
params.port_type = port->port_type;
params.port_speed = port->port_speed;
params.num_of_tasks = (u8)port->tasks.num;
params.num_of_extra_tasks = (u8)port->tasks.extra;
params.num_of_open_dmas = (u8)port->open_dmas.num;
params.num_of_extra_open_dmas = (u8)port->open_dmas.extra;
if (port->fifo_bufs.num) {
err = verify_size_of_fifo(port);
if (err)
return err;
}
params.size_of_fifo = port->fifo_bufs.num;
params.extra_size_of_fifo = port->fifo_bufs.extra;
params.deq_pipeline_depth = port->cfg->tx_fifo_deq_pipeline_depth;
params.max_frame_length = port->max_frame_length;
err = fman_set_port_params(port->fm, &params);
if (err)
return err;
err = init_low_level_driver(port);
if (err)
return err;
kfree(port->cfg);
port->cfg = NULL;
return 0;
}
int fman_port_cfg_buf_prefix_content(struct fman_port *port,
struct fman_buffer_prefix_content *
buffer_prefix_content)
{
if (is_init_done(port->cfg))
return -EINVAL;
memcpy(&port->cfg->buffer_prefix_content,
buffer_prefix_content,
sizeof(struct fman_buffer_prefix_content));
if (!port->cfg->buffer_prefix_content.data_align)
port->cfg->buffer_prefix_content.data_align =
DFLT_PORT_BUFFER_PREFIX_CONTEXT_DATA_ALIGN;
return 0;
}
int fman_port_disable(struct fman_port *port)
{
u32 __iomem *bmi_cfg_reg, *bmi_status_reg, tmp;
bool rx_port, failure = false;
int count;
if (!is_init_done(port->cfg))
return -EINVAL;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
bmi_cfg_reg = &port->bmi_regs->rx.fmbm_rcfg;
bmi_status_reg = &port->bmi_regs->rx.fmbm_rst;
rx_port = true;
break;
case FMAN_PORT_TYPE_TX:
bmi_cfg_reg = &port->bmi_regs->tx.fmbm_tcfg;
bmi_status_reg = &port->bmi_regs->tx.fmbm_tst;
rx_port = false;
break;
default:
return -EINVAL;
}
if (!rx_port) {
tmp = ioread32be(&port->qmi_regs->fmqm_pnc) & ~QMI_PORT_CFG_EN;
iowrite32be(tmp, &port->qmi_regs->fmqm_pnc);
count = 100;
do {
udelay(10);
tmp = ioread32be(&port->qmi_regs->fmqm_pns);
} while ((tmp & QMI_PORT_STATUS_DEQ_FD_BSY) && --count);
if (count == 0) {
failure = true;
}
}
tmp = ioread32be(bmi_cfg_reg) & ~BMI_PORT_CFG_EN;
iowrite32be(tmp, bmi_cfg_reg);
count = 500;
do {
udelay(10);
tmp = ioread32be(bmi_status_reg);
} while ((tmp & BMI_PORT_STATUS_BSY) && --count);
if (count == 0) {
failure = true;
}
if (failure)
dev_dbg(port->dev, "%s: FMan Port[%d]: BMI or QMI is Busy. Port forced down\n",
__func__, port->port_id);
return 0;
}
int fman_port_enable(struct fman_port *port)
{
u32 __iomem *bmi_cfg_reg, tmp;
bool rx_port;
if (!is_init_done(port->cfg))
return -EINVAL;
switch (port->port_type) {
case FMAN_PORT_TYPE_RX:
bmi_cfg_reg = &port->bmi_regs->rx.fmbm_rcfg;
rx_port = true;
break;
case FMAN_PORT_TYPE_TX:
bmi_cfg_reg = &port->bmi_regs->tx.fmbm_tcfg;
rx_port = false;
break;
default:
return -EINVAL;
}
if (!rx_port) {
tmp = ioread32be(&port->qmi_regs->fmqm_pnc) | QMI_PORT_CFG_EN;
iowrite32be(tmp, &port->qmi_regs->fmqm_pnc);
}
tmp = ioread32be(bmi_cfg_reg) | BMI_PORT_CFG_EN;
iowrite32be(tmp, bmi_cfg_reg);
return 0;
}
struct fman_port *fman_port_bind(struct device *dev)
{
return (struct fman_port *)(dev_get_drvdata(get_device(dev)));
}
u32 fman_port_get_qman_channel_id(struct fman_port *port)
{
return port->dts_params.qman_channel_id;
}
static int fman_port_probe(struct platform_device *of_dev)
{
struct fman_port *port;
struct fman *fman;
struct device_node *fm_node, *port_node;
struct resource res;
struct resource *dev_res;
const u32 *u32_prop;
int err = 0, lenp;
enum fman_port_type port_type;
u16 port_speed;
u8 port_id;
port = kzalloc(sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
port->dev = &of_dev->dev;
port_node = of_node_get(of_dev->dev.of_node);
fm_node = of_get_parent(port_node);
if (!fm_node) {
dev_err(port->dev, "%s: of_get_parent() failed\n", __func__);
err = -ENODEV;
goto return_err;
}
fman = dev_get_drvdata(&of_find_device_by_node(fm_node)->dev);
of_node_put(fm_node);
if (!fman) {
err = -EINVAL;
goto return_err;
}
u32_prop = (const u32 *)of_get_property(port_node, "cell-index", &lenp);
if (!u32_prop) {
dev_err(port->dev, "%s: of_get_property(%s, cell-index) failed\n",
__func__, port_node->full_name);
err = -EINVAL;
goto return_err;
}
if (WARN_ON(lenp != sizeof(u32))) {
err = -EINVAL;
goto return_err;
}
port_id = (u8)fdt32_to_cpu(u32_prop[0]);
port->dts_params.id = port_id;
if (of_device_is_compatible(port_node, "fsl,fman-v3-port-tx")) {
port_type = FMAN_PORT_TYPE_TX;
port_speed = 1000;
u32_prop = (const u32 *)of_get_property(port_node,
"fsl,fman-10g-port",
&lenp);
if (u32_prop)
port_speed = 10000;
} else if (of_device_is_compatible(port_node, "fsl,fman-v2-port-tx")) {
if (port_id >= TX_10G_PORT_BASE)
port_speed = 10000;
else
port_speed = 1000;
port_type = FMAN_PORT_TYPE_TX;
} else if (of_device_is_compatible(port_node, "fsl,fman-v3-port-rx")) {
port_type = FMAN_PORT_TYPE_RX;
port_speed = 1000;
u32_prop = (const u32 *)of_get_property(port_node,
"fsl,fman-10g-port", &lenp);
if (u32_prop)
port_speed = 10000;
} else if (of_device_is_compatible(port_node, "fsl,fman-v2-port-rx")) {
if (port_id >= RX_10G_PORT_BASE)
port_speed = 10000;
else
port_speed = 1000;
port_type = FMAN_PORT_TYPE_RX;
} else {
dev_err(port->dev, "%s: Illegal port type\n", __func__);
err = -EINVAL;
goto return_err;
}
port->dts_params.type = port_type;
port->dts_params.speed = port_speed;
if (port_type == FMAN_PORT_TYPE_TX) {
u32 qman_channel_id;
qman_channel_id = fman_get_qman_channel_id(fman, port_id);
if (qman_channel_id == 0) {
dev_err(port->dev, "%s: incorrect qman-channel-id\n",
__func__);
err = -EINVAL;
goto return_err;
}
port->dts_params.qman_channel_id = qman_channel_id;
}
err = of_address_to_resource(port_node, 0, &res);
if (err < 0) {
dev_err(port->dev, "%s: of_address_to_resource() failed\n",
__func__);
err = -ENOMEM;
goto return_err;
}
port->dts_params.fman = fman;
of_node_put(port_node);
dev_res = __devm_request_region(port->dev, &res, res.start,
resource_size(&res), "fman-port");
if (!dev_res) {
dev_err(port->dev, "%s: __devm_request_region() failed\n",
__func__);
err = -EINVAL;
goto free_port;
}
port->dts_params.base_addr = devm_ioremap(port->dev, res.start,
resource_size(&res));
if (port->dts_params.base_addr == 0)
dev_err(port->dev, "%s: devm_ioremap() failed\n", __func__);
dev_set_drvdata(&of_dev->dev, port);
return 0;
return_err:
of_node_put(port_node);
free_port:
kfree(port);
return err;
}
