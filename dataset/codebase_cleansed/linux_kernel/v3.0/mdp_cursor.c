int mdp_hw_cursor_update(struct fb_info *info, struct fb_cursor *cursor)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)info->par;
struct fb_image *img = &cursor->image;
int calpha_en, transp_en;
int alpha;
int ret = 0;
if ((img->width > MDP_CURSOR_WIDTH) ||
(img->height > MDP_CURSOR_HEIGHT) ||
(img->depth != 32))
return -EINVAL;
if (cursor->set & FB_CUR_SETPOS)
MDP_OUTP(MDP_BASE + 0x9004c, (img->dy << 16) | img->dx);
if (cursor->set & FB_CUR_SETIMAGE) {
ret = copy_from_user(mfd->cursor_buf, img->data,
img->width*img->height*4);
if (ret)
return ret;
if (img->bg_color == 0xffffffff)
transp_en = 0;
else
transp_en = 1;
alpha = (img->fg_color & 0xff000000) >> 24;
if (alpha)
calpha_en = 0x2;
else
calpha_en = 0x1;
MDP_OUTP(MDP_BASE + 0x90044, (img->height << 16) | img->width);
MDP_OUTP(MDP_BASE + 0x90048, mfd->cursor_buf_phys);
MDP_OUTP(MDP_BASE + 0x90060,
(transp_en << 3) | (calpha_en << 1) |
(inp32(MDP_BASE + 0x90060) & 0x1));
#ifdef CONFIG_FB_MSM_MDP40
MDP_OUTP(MDP_BASE + 0x90064, (alpha << 24));
MDP_OUTP(MDP_BASE + 0x90068, (0xffffff & img->bg_color));
MDP_OUTP(MDP_BASE + 0x9006C, (0xffffff & img->bg_color));
#else
MDP_OUTP(MDP_BASE + 0x90064,
(alpha << 24) | (0xffffff & img->bg_color));
MDP_OUTP(MDP_BASE + 0x90068, 0);
#endif
}
if ((cursor->enable) && (!cursor_enabled)) {
cursor_enabled = 1;
MDP_OUTP(MDP_BASE + 0x90060, inp32(MDP_BASE + 0x90060) | 0x1);
} else if ((!cursor->enable) && (cursor_enabled)) {
cursor_enabled = 0;
MDP_OUTP(MDP_BASE + 0x90060,
inp32(MDP_BASE + 0x90060) & (~0x1));
}
return 0;
}
