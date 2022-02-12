void g2d_reset(struct g2d_dev *d)
{
w(1, SOFT_RESET_REG);
}
void g2d_set_src_size(struct g2d_dev *d, struct g2d_frame *f)
{
u32 n;
w(f->stride & 0xFFFF, SRC_STRIDE_REG);
n = f->o_height & 0xFFF;
n <<= 16;
n |= f->o_width & 0xFFF;
w(n, SRC_LEFT_TOP_REG);
n = f->bottom & 0xFFF;
n <<= 16;
n |= f->right & 0xFFF;
w(n, SRC_RIGHT_BOTTOM_REG);
w(f->fmt->hw, SRC_COLOR_MODE_REG);
}
void g2d_set_src_addr(struct g2d_dev *d, dma_addr_t a)
{
w(a, SRC_BASE_ADDR_REG);
}
void g2d_set_dst_size(struct g2d_dev *d, struct g2d_frame *f)
{
u32 n;
w(f->stride & 0xFFFF, DST_STRIDE_REG);
n = f->o_height & 0xFFF;
n <<= 16;
n |= f->o_width & 0xFFF;
w(n, DST_LEFT_TOP_REG);
n = f->bottom & 0xFFF;
n <<= 16;
n |= f->right & 0xFFF;
w(n, DST_RIGHT_BOTTOM_REG);
w(f->fmt->hw, DST_COLOR_MODE_REG);
}
void g2d_set_dst_addr(struct g2d_dev *d, dma_addr_t a)
{
w(a, DST_BASE_ADDR_REG);
}
void g2d_set_rop4(struct g2d_dev *d, u32 r)
{
w(r, ROP4_REG);
}
u32 g2d_cmd_stretch(u32 e)
{
e &= 1;
return e << 4;
}
void g2d_set_cmd(struct g2d_dev *d, u32 c)
{
w(c, BITBLT_COMMAND_REG);
}
void g2d_start(struct g2d_dev *d)
{
w(0x7, CACHECTL_REG);
w(1, INTEN_REG);
w(1, BITBLT_START_REG);
}
void g2d_clear_int(struct g2d_dev *d)
{
w(1, INTC_PEND_REG);
}
