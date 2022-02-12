static void get_hw_reg_base(struct vdec_vp8_inst *inst)
{
inst->reg_base.top = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_TOP);
inst->reg_base.cm = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_CM);
inst->reg_base.hwd = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_HWD);
inst->reg_base.sys = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_SYS);
inst->reg_base.misc = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_MISC);
inst->reg_base.ld = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_LD);
inst->reg_base.hwb = mtk_vcodec_get_reg_addr(inst->ctx, VDEC_HWB);
}
static void write_hw_segmentation_data(struct vdec_vp8_inst *inst)
{
int i, j;
u32 seg_id_addr;
u32 val;
void __iomem *cm = inst->reg_base.cm;
struct vdec_vp8_vsi *vsi = inst->vsi;
seg_id_addr = readl(inst->reg_base.top + VP8_SEGID_DRAM_ADDR) >> 4;
for (i = 0; i < ARRAY_SIZE(vsi->segment_buf); i++) {
for (j = ARRAY_SIZE(vsi->segment_buf[i]) - 1; j >= 0; j--) {
val = (1 << 16) + ((seg_id_addr + i) << 2) + j;
writel(val, cm + VP8_HW_VLD_ADDR);
val = vsi->segment_buf[i][j];
writel(val, cm + VP8_HW_VLD_VALUE);
}
}
}
static void read_hw_segmentation_data(struct vdec_vp8_inst *inst)
{
int i, j;
u32 seg_id_addr;
u32 val;
void __iomem *cm = inst->reg_base.cm;
struct vdec_vp8_vsi *vsi = inst->vsi;
seg_id_addr = readl(inst->reg_base.top + VP8_SEGID_DRAM_ADDR) >> 4;
for (i = 0; i < ARRAY_SIZE(vsi->segment_buf); i++) {
for (j = ARRAY_SIZE(vsi->segment_buf[i]) - 1; j >= 0; j--) {
val = ((seg_id_addr + i) << 2) + j;
writel(val, cm + VP8_HW_VLD_ADDR);
val = readl(cm + VP8_HW_VLD_VALUE);
vsi->segment_buf[i][j] = val;
}
}
}
static void enable_hw_rw_function(struct vdec_vp8_inst *inst)
{
u32 val = 0;
void __iomem *sys = inst->reg_base.sys;
void __iomem *misc = inst->reg_base.misc;
void __iomem *ld = inst->reg_base.ld;
void __iomem *hwb = inst->reg_base.hwb;
void __iomem *hwd = inst->reg_base.hwd;
writel(0x1, sys + VP8_RW_CKEN_SET);
writel(0x101, ld + VP8_WO_VLD_SRST);
writel(0x101, hwb + VP8_WO_VLD_SRST);
writel(1, sys);
val = readl(misc + VP8_RW_MISC_SRST);
writel((val & 0xFFFFFFFE), misc + VP8_RW_MISC_SRST);
writel(0x1, misc + VP8_RW_MISC_SYS_SEL);
writel(0x17F, misc + VP8_RW_MISC_SPEC_CON);
writel(0x71201100, misc + VP8_RW_MISC_FUNC_CON);
writel(0x0, ld + VP8_WO_VLD_SRST);
writel(0x0, hwb + VP8_WO_VLD_SRST);
writel(0x1, sys + VP8_RW_DCM_CON);
writel(0x1, misc + VP8_RW_MISC_DCM_CON);
writel(0x1, hwd + VP8_RW_VP8_CTRL);
}
static void store_dec_table(struct vdec_vp8_inst *inst)
{
int i, j;
u32 addr = 0, val = 0;
void __iomem *hwd = inst->reg_base.hwd;
u32 *p = &inst->vsi->dec_table[VP8_DEC_TABLE_OFFSET];
for (i = 0; i < VP8_DEC_TABLE_PROC_LOOP; i++) {
writel(addr, hwd + VP8_BSASET);
for (j = 0; j < VP8_DEC_TABLE_UNIT ; j++) {
val = *p++;
writel(val, hwd + VP8_BSDSET);
}
addr += VP8_DEC_TABLE_RW_UNIT;
}
}
static void load_dec_table(struct vdec_vp8_inst *inst)
{
int i;
u32 addr = 0;
u32 *p = &inst->vsi->dec_table[VP8_DEC_TABLE_OFFSET];
void __iomem *hwd = inst->reg_base.hwd;
for (i = 0; i < VP8_DEC_TABLE_PROC_LOOP; i++) {
writel(addr, hwd + VP8_BSASET);
*p++ = readl(hwd + VP8_BSDSET);
*p++ = readl(hwd + VP8_BSDSET);
*p++ = readl(hwd + VP8_BSDSET) & 0xFFFFFF;
addr += VP8_DEC_TABLE_RW_UNIT;
}
}
static void get_pic_info(struct vdec_vp8_inst *inst, struct vdec_pic_info *pic)
{
*pic = inst->vsi->pic;
mtk_vcodec_debug(inst, "pic(%d, %d), buf(%d, %d)",
pic->pic_w, pic->pic_h, pic->buf_w, pic->buf_h);
mtk_vcodec_debug(inst, "Y(%d, %d), C(%d, %d)", pic->y_bs_sz,
pic->y_len_sz, pic->c_bs_sz, pic->c_len_sz);
}
static void vp8_dec_finish(struct vdec_vp8_inst *inst)
{
struct vdec_fb_node *node;
uint64_t prev_y_dma = inst->vsi->dec.prev_y_dma;
mtk_vcodec_debug(inst, "prev fb base dma=%llx", prev_y_dma);
if (prev_y_dma != 0) {
list_for_each_entry(node, &inst->fb_use_list, list) {
struct vdec_fb *fb = (struct vdec_fb *)node->fb;
if (prev_y_dma == (uint64_t)fb->base_y.dma_addr) {
list_move_tail(&node->list,
&inst->fb_free_list);
break;
}
}
}
node = list_first_entry(&inst->available_fb_node_list,
struct vdec_fb_node, list);
node->fb = inst->cur_fb;
list_move_tail(&node->list, &inst->fb_use_list);
if (inst->vsi->dec.show_frame) {
node = list_first_entry(&inst->available_fb_node_list,
struct vdec_fb_node, list);
node->fb = inst->cur_fb;
list_move_tail(&node->list, &inst->fb_disp_list);
}
}
static void move_fb_list_use_to_free(struct vdec_vp8_inst *inst)
{
struct vdec_fb_node *node, *tmp;
list_for_each_entry_safe(node, tmp, &inst->fb_use_list, list)
list_move_tail(&node->list, &inst->fb_free_list);
}
static void init_list(struct vdec_vp8_inst *inst)
{
int i;
INIT_LIST_HEAD(&inst->available_fb_node_list);
INIT_LIST_HEAD(&inst->fb_use_list);
INIT_LIST_HEAD(&inst->fb_free_list);
INIT_LIST_HEAD(&inst->fb_disp_list);
for (i = 0; i < ARRAY_SIZE(inst->dec_fb); i++) {
INIT_LIST_HEAD(&inst->dec_fb[i].list);
inst->dec_fb[i].fb = NULL;
list_add_tail(&inst->dec_fb[i].list,
&inst->available_fb_node_list);
}
}
static void add_fb_to_free_list(struct vdec_vp8_inst *inst, void *fb)
{
struct vdec_fb_node *node;
if (fb) {
node = list_first_entry(&inst->available_fb_node_list,
struct vdec_fb_node, list);
node->fb = fb;
list_move_tail(&node->list, &inst->fb_free_list);
}
}
static int alloc_working_buf(struct vdec_vp8_inst *inst)
{
int err;
struct mtk_vcodec_mem *mem = &inst->working_buf;
mem->size = VP8_WORKING_BUF_SZ;
err = mtk_vcodec_mem_alloc(inst->ctx, mem);
if (err) {
mtk_vcodec_err(inst, "Cannot allocate working buffer");
return err;
}
inst->vsi->dec.working_buf_dma = (uint64_t)mem->dma_addr;
return 0;
}
static void free_working_buf(struct vdec_vp8_inst *inst)
{
struct mtk_vcodec_mem *mem = &inst->working_buf;
if (mem->va)
mtk_vcodec_mem_free(inst->ctx, mem);
inst->vsi->dec.working_buf_dma = 0;
}
static int vdec_vp8_init(struct mtk_vcodec_ctx *ctx, unsigned long *h_vdec)
{
struct vdec_vp8_inst *inst;
int err;
inst = kzalloc(sizeof(*inst), GFP_KERNEL);
if (!inst)
return -ENOMEM;
inst->ctx = ctx;
inst->vpu.id = IPI_VDEC_VP8;
inst->vpu.dev = ctx->dev->vpu_plat_dev;
inst->vpu.ctx = ctx;
inst->vpu.handler = vpu_dec_ipi_handler;
err = vpu_dec_init(&inst->vpu);
if (err) {
mtk_vcodec_err(inst, "vdec_vp8 init err=%d", err);
goto error_free_inst;
}
inst->vsi = (struct vdec_vp8_vsi *)inst->vpu.vsi;
init_list(inst);
err = alloc_working_buf(inst);
if (err)
goto error_deinit;
get_hw_reg_base(inst);
mtk_vcodec_debug(inst, "VP8 Instance >> %p", inst);
*h_vdec = (unsigned long)inst;
return 0;
error_deinit:
vpu_dec_deinit(&inst->vpu);
error_free_inst:
kfree(inst);
return err;
}
static int vdec_vp8_decode(unsigned long h_vdec, struct mtk_vcodec_mem *bs,
struct vdec_fb *fb, bool *res_chg)
{
struct vdec_vp8_inst *inst = (struct vdec_vp8_inst *)h_vdec;
struct vdec_vp8_dec_info *dec = &inst->vsi->dec;
struct vdec_vpu_inst *vpu = &inst->vpu;
unsigned char *bs_va;
unsigned int data;
int err = 0;
uint64_t y_fb_dma;
uint64_t c_fb_dma;
if (bs == NULL) {
move_fb_list_use_to_free(inst);
return vpu_dec_reset(vpu);
}
y_fb_dma = fb ? (u64)fb->base_y.dma_addr : 0;
c_fb_dma = fb ? (u64)fb->base_c.dma_addr : 0;
mtk_vcodec_debug(inst, "+ [%d] FB y_dma=%llx c_dma=%llx fb=%p",
inst->frm_cnt, y_fb_dma, c_fb_dma, fb);
inst->cur_fb = fb;
dec->bs_dma = (unsigned long)bs->dma_addr;
dec->bs_sz = bs->size;
dec->cur_y_fb_dma = y_fb_dma;
dec->cur_c_fb_dma = c_fb_dma;
mtk_vcodec_debug(inst, "\n + FRAME[%d] +\n", inst->frm_cnt);
write_hw_segmentation_data(inst);
enable_hw_rw_function(inst);
store_dec_table(inst);
bs_va = (unsigned char *)bs->va;
data = (*(bs_va + 9) << 24) | (*(bs_va + 8) << 16) |
(*(bs_va + 7) << 8) | *(bs_va + 6);
err = vpu_dec_start(vpu, &data, 1);
if (err) {
add_fb_to_free_list(inst, fb);
if (dec->wait_key_frame) {
mtk_vcodec_debug(inst, "wait key frame !");
return 0;
}
goto error;
}
if (dec->resolution_changed) {
mtk_vcodec_debug(inst, "- resolution_changed -");
*res_chg = true;
add_fb_to_free_list(inst, fb);
return 0;
}
mtk_vcodec_wait_for_done_ctx(inst->ctx, MTK_INST_IRQ_RECEIVED,
WAIT_INTR_TIMEOUT_MS);
if (inst->vsi->load_data)
load_dec_table(inst);
vp8_dec_finish(inst);
read_hw_segmentation_data(inst);
err = vpu_dec_end(vpu);
if (err)
goto error;
mtk_vcodec_debug(inst, "\n - FRAME[%d] - show=%d\n", inst->frm_cnt,
dec->show_frame);
inst->frm_cnt++;
*res_chg = false;
return 0;
error:
mtk_vcodec_err(inst, "\n - FRAME[%d] - err=%d\n", inst->frm_cnt, err);
return err;
}
static void get_disp_fb(struct vdec_vp8_inst *inst, struct vdec_fb **out_fb)
{
struct vdec_fb_node *node;
struct vdec_fb *fb;
node = list_first_entry_or_null(&inst->fb_disp_list,
struct vdec_fb_node, list);
if (node) {
list_move_tail(&node->list, &inst->available_fb_node_list);
fb = (struct vdec_fb *)node->fb;
fb->status |= FB_ST_DISPLAY;
mtk_vcodec_debug(inst, "[FB] get disp fb %p st=%d",
node->fb, fb->status);
} else {
fb = NULL;
mtk_vcodec_debug(inst, "[FB] there is no disp fb");
}
*out_fb = fb;
}
static void get_free_fb(struct vdec_vp8_inst *inst, struct vdec_fb **out_fb)
{
struct vdec_fb_node *node;
struct vdec_fb *fb;
node = list_first_entry_or_null(&inst->fb_free_list,
struct vdec_fb_node, list);
if (node) {
list_move_tail(&node->list, &inst->available_fb_node_list);
fb = (struct vdec_fb *)node->fb;
fb->status |= FB_ST_FREE;
mtk_vcodec_debug(inst, "[FB] get free fb %p st=%d",
node->fb, fb->status);
} else {
fb = NULL;
mtk_vcodec_debug(inst, "[FB] there is no free fb");
}
*out_fb = fb;
}
static void get_crop_info(struct vdec_vp8_inst *inst, struct v4l2_rect *cr)
{
cr->left = 0;
cr->top = 0;
cr->width = inst->vsi->pic.pic_w;
cr->height = inst->vsi->pic.pic_h;
mtk_vcodec_debug(inst, "get crop info l=%d, t=%d, w=%d, h=%d",
cr->left, cr->top, cr->width, cr->height);
}
static int vdec_vp8_get_param(unsigned long h_vdec,
enum vdec_get_param_type type, void *out)
{
struct vdec_vp8_inst *inst = (struct vdec_vp8_inst *)h_vdec;
switch (type) {
case GET_PARAM_DISP_FRAME_BUFFER:
get_disp_fb(inst, out);
break;
case GET_PARAM_FREE_FRAME_BUFFER:
get_free_fb(inst, out);
break;
case GET_PARAM_PIC_INFO:
get_pic_info(inst, out);
break;
case GET_PARAM_CROP_INFO:
get_crop_info(inst, out);
break;
case GET_PARAM_DPB_SIZE:
*((unsigned int *)out) = VP8_DPB_SIZE;
break;
default:
mtk_vcodec_err(inst, "invalid get parameter type=%d", type);
return -EINVAL;
}
return 0;
}
static void vdec_vp8_deinit(unsigned long h_vdec)
{
struct vdec_vp8_inst *inst = (struct vdec_vp8_inst *)h_vdec;
mtk_vcodec_debug_enter(inst);
vpu_dec_deinit(&inst->vpu);
free_working_buf(inst);
kfree(inst);
}
struct vdec_common_if *get_vp8_dec_comm_if(void)
{
return &vdec_vp8_if;
}
