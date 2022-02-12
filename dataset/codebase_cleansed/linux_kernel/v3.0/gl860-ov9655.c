void ov9655_init_settings(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vcur.backlight = 0;
sd->vcur.brightness = 128;
sd->vcur.sharpness = 0;
sd->vcur.contrast = 0;
sd->vcur.gamma = 0;
sd->vcur.hue = 0;
sd->vcur.saturation = 0;
sd->vcur.whitebal = 0;
sd->vmax.backlight = 0;
sd->vmax.brightness = 255;
sd->vmax.sharpness = 0;
sd->vmax.contrast = 0;
sd->vmax.gamma = 0;
sd->vmax.hue = 0 + 1;
sd->vmax.saturation = 0;
sd->vmax.whitebal = 0;
sd->vmax.mirror = 0;
sd->vmax.flip = 0;
sd->vmax.AC50Hz = 0;
sd->dev_camera_settings = ov9655_camera_settings;
sd->dev_init_at_startup = ov9655_init_at_startup;
sd->dev_configure_alt = ov9655_configure_alt;
sd->dev_init_pre_alt = ov9655_init_pre_alt;
sd->dev_post_unset_alt = ov9655_post_unset_alt;
}
static int ov9655_init_at_startup(struct gspca_dev *gspca_dev)
{
fetch_validx(gspca_dev, tbl_init_at_startup,
ARRAY_SIZE(tbl_init_at_startup));
fetch_validx(gspca_dev, tbl_commmon, ARRAY_SIZE(tbl_commmon));
return 0;
}
static int ov9655_init_pre_alt(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vold.brightness = -1;
sd->vold.hue = -1;
fetch_validx(gspca_dev, tbl_commmon, ARRAY_SIZE(tbl_commmon));
ov9655_init_post_alt(gspca_dev);
return 0;
}
static int ov9655_init_post_alt(struct gspca_dev *gspca_dev)
{
s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
s32 n;
s32 i;
u8 **tbl;
ctrl_out(gspca_dev, 0x40, 5, 0x0001, 0x0000, 0, NULL);
tbl = (reso == IMAGE_640) ? tbl_640 : tbl_1280;
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
tbl_length[0], tbl[0]);
for (i = 1; i < 7; i++)
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200,
tbl_length[i], tbl[i]);
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
tbl_length[7], tbl[7]);
n = fetch_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt));
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_in(gspca_dev, 0xc0, 2, 0x6000, 0x801e, 1, c04);
keep_on_fetching_validx(gspca_dev, tbl_init_post_alt,
ARRAY_SIZE(tbl_init_post_alt), n);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post1);
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post2);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post3);
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post4);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post5);
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200, 4, dat_post6);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post7);
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_post8);
ov9655_camera_settings(gspca_dev);
return 0;
}
static int ov9655_configure_alt(struct gspca_dev *gspca_dev)
{
s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
switch (reso) {
case IMAGE_640:
gspca_dev->alt = 1 + 1;
break;
default:
gspca_dev->alt = 1 + 1;
break;
}
return 0;
}
static int ov9655_camera_settings(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
u8 dat_bright[] = "\x04\x00\x10\x7c\xa1\x00\x00\x70";
s32 bright = sd->vcur.brightness;
s32 hue = sd->vcur.hue;
if (bright != sd->vold.brightness) {
sd->vold.brightness = bright;
if (bright < 0 || bright > sd->vmax.brightness)
bright = 0;
dat_bright[3] = bright;
ctrl_out(gspca_dev, 0x40, 3, 0x6000, 0x0200, 8, dat_bright);
}
if (hue != sd->vold.hue) {
sd->vold.hue = hue;
sd->swapRB = (hue != 0);
}
return 0;
}
static void ov9655_post_unset_alt(struct gspca_dev *gspca_dev)
{
ctrl_out(gspca_dev, 0x40, 5, 0x0000, 0x0000, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0061, 0x0000, 0, NULL);
}
