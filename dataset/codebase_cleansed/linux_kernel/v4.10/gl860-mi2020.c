void mi2020_init_settings(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->vcur.backlight = 0;
sd->vcur.brightness = 70;
sd->vcur.sharpness = 20;
sd->vcur.contrast = 0;
sd->vcur.gamma = 0;
sd->vcur.hue = 0;
sd->vcur.saturation = 60;
sd->vcur.whitebal = 0;
sd->vcur.mirror = 0;
sd->vcur.flip = 0;
sd->vcur.AC50Hz = 1;
sd->vmax.backlight = 64;
sd->vmax.brightness = 128;
sd->vmax.sharpness = 40;
sd->vmax.contrast = 3;
sd->vmax.gamma = 2;
sd->vmax.hue = 0 + 1;
sd->vmax.saturation = 0;
sd->vmax.whitebal = 2;
sd->vmax.mirror = 1;
sd->vmax.flip = 1;
sd->vmax.AC50Hz = 1;
sd->dev_camera_settings = mi2020_camera_settings;
sd->dev_init_at_startup = mi2020_init_at_startup;
sd->dev_configure_alt = mi2020_configure_alt;
sd->dev_init_pre_alt = mi2020_init_pre_alt;
sd->dev_post_unset_alt = mi2020_post_unset_alt;
}
static void common(struct gspca_dev *gspca_dev)
{
fetch_validx(gspca_dev, tbl_common_0B, ARRAY_SIZE(tbl_common_0B));
fetch_idxdata(gspca_dev, tbl_common_3B, ARRAY_SIZE(tbl_common_3B));
ctrl_out(gspca_dev, 0x40, 1, 0x0041, 0x0000, 0, NULL);
}
static int mi2020_init_at_startup(struct gspca_dev *gspca_dev)
{
u8 c;
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0004, 1, &c);
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0004, 1, &c);
fetch_validx(gspca_dev, tbl_init_at_startup,
ARRAY_SIZE(tbl_init_at_startup));
ctrl_out(gspca_dev, 0x40, 1, 0x7a00, 0x8030, 0, NULL);
ctrl_in(gspca_dev, 0xc0, 2, 0x7a00, 0x8030, 1, &c);
common(gspca_dev);
msleep(61);
ctrl_out(gspca_dev, 0x40, 1, 0x0001, 0x0000, 0, NULL);
return 0;
}
static int mi2020_init_pre_alt(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
sd->mirrorMask = 0;
sd->vold.hue = -1;
sd->vold.brightness = -1;
sd->vold.sharpness = -1;
sd->vold.contrast = 0;
sd->vold.gamma = 0;
sd->vold.backlight = 0;
mi2020_init_post_alt(gspca_dev);
return 0;
}
static int mi2020_init_post_alt(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
s32 mirror = (((sd->vcur.mirror > 0) ^ sd->mirrorMask) > 0);
s32 flip = (((sd->vcur.flip > 0) ^ sd->mirrorMask) > 0);
s32 freq = (sd->vcur.AC50Hz > 0);
s32 wbal = sd->vcur.whitebal;
u8 dat_freq2[] = {0x90, 0x00, 0x80};
u8 dat_multi1[] = {0x8c, 0xa7, 0x00};
u8 dat_multi2[] = {0x90, 0x00, 0x00};
u8 dat_multi3[] = {0x8c, 0xa7, 0x00};
u8 dat_multi4[] = {0x90, 0x00, 0x00};
u8 dat_hvflip2[] = {0x90, 0x04, 0x6c};
u8 dat_hvflip4[] = {0x90, 0x00, 0x24};
u8 dat_wbal2[] = {0x90, 0x00, 0x00};
u8 c;
sd->nbIm = -1;
dat_freq2[2] = freq ? 0xc0 : 0x80;
dat_multi1[2] = 0x9d;
dat_multi3[2] = dat_multi1[2] + 1;
if (wbal == 0) {
dat_multi4[2] = dat_multi2[2] = 0;
dat_wbal2[2] = 0x17;
} else if (wbal == 1) {
dat_multi4[2] = dat_multi2[2] = 0;
dat_wbal2[2] = 0x35;
} else if (wbal == 2) {
dat_multi4[2] = dat_multi2[2] = 0x20;
dat_wbal2[2] = 0x17;
}
dat_hvflip2[2] = 0x6c + 2 * (1 - flip) + (1 - mirror);
dat_hvflip4[2] = 0x24 + 2 * (1 - flip) + (1 - mirror);
msleep(200);
ctrl_out(gspca_dev, 0x40, 5, 0x0001, 0x0000, 0, NULL);
msleep(2);
common(gspca_dev);
msleep(142);
ctrl_out(gspca_dev, 0x40, 1, 0x0010, 0x0010, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0003, 0x00c1, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0042, 0x00c2, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x006a, 0x000d, 0, NULL);
switch (reso) {
case IMAGE_640:
case IMAGE_800:
if (reso != IMAGE_800)
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
12, dat_640);
else
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
12, dat_800);
fetch_idxdata(gspca_dev, tbl_init_post_alt_low1,
ARRAY_SIZE(tbl_init_post_alt_low1));
if (reso == IMAGE_800)
fetch_idxdata(gspca_dev, tbl_init_post_alt_low2,
ARRAY_SIZE(tbl_init_post_alt_low2));
fetch_idxdata(gspca_dev, tbl_init_post_alt_low3,
ARRAY_SIZE(tbl_init_post_alt_low3));
ctrl_out(gspca_dev, 0x40, 1, 0x0010, 0x0010, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0000, 0x00c1, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0041, 0x00c2, 0, NULL);
msleep(120);
break;
case IMAGE_1280:
case IMAGE_1600:
if (reso == IMAGE_1280) {
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
12, dat_1280);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x8c\x27\x07");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x90\x05\x04");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x8c\x27\x09");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x90\x04\x02");
} else {
ctrl_out(gspca_dev, 0x40, 3, 0x0000, 0x0200,
12, dat_1600);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x8c\x27\x07");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x90\x06\x40");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x8c\x27\x09");
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033,
3, "\x90\x04\xb0");
}
fetch_idxdata(gspca_dev, tbl_init_post_alt_big,
ARRAY_SIZE(tbl_init_post_alt_big));
ctrl_out(gspca_dev, 0x40, 1, 0x0001, 0x0010, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0000, 0x00c1, 0, NULL);
ctrl_out(gspca_dev, 0x40, 1, 0x0041, 0x00c2, 0, NULL);
msleep(1850);
}
ctrl_out(gspca_dev, 0x40, 1, 0x0040, 0x0000, 0, NULL);
msleep(40);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_freq1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_freq2);
msleep(33);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_wbal1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_wbal2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi6);
msleep(7);
ctrl_in(gspca_dev, 0xc0, 2, 0x0000, 0x0000, 1, &c);
fetch_idxdata(gspca_dev, tbl_init_post_alt_3B,
ARRAY_SIZE(tbl_init_post_alt_3B));
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip6);
msleep(250);
if (reso == IMAGE_640 || reso == IMAGE_800)
fetch_idxdata(gspca_dev, tbl_middle_hvflip_low,
ARRAY_SIZE(tbl_middle_hvflip_low));
else
fetch_idxdata(gspca_dev, tbl_middle_hvflip_big,
ARRAY_SIZE(tbl_middle_hvflip_big));
fetch_idxdata(gspca_dev, tbl_end_hvflip,
ARRAY_SIZE(tbl_end_hvflip));
sd->nbIm = 0;
sd->vold.mirror = mirror;
sd->vold.flip = flip;
sd->vold.AC50Hz = freq;
sd->vold.whitebal = wbal;
mi2020_camera_settings(gspca_dev);
return 0;
}
static int mi2020_configure_alt(struct gspca_dev *gspca_dev)
{
s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
switch (reso) {
case IMAGE_640:
gspca_dev->alt = 3 + 1;
break;
case IMAGE_800:
case IMAGE_1280:
case IMAGE_1600:
gspca_dev->alt = 1 + 1;
break;
}
return 0;
}
static int mi2020_camera_settings(struct gspca_dev *gspca_dev)
{
struct sd *sd = (struct sd *) gspca_dev;
s32 reso = gspca_dev->cam.cam_mode[(s32) gspca_dev->curr_mode].priv;
s32 backlight = sd->vcur.backlight;
s32 bright = sd->vcur.brightness;
s32 sharp = sd->vcur.sharpness;
s32 cntr = sd->vcur.contrast;
s32 gam = sd->vcur.gamma;
s32 hue = (sd->vcur.hue > 0);
s32 mirror = (((sd->vcur.mirror > 0) ^ sd->mirrorMask) > 0);
s32 flip = (((sd->vcur.flip > 0) ^ sd->mirrorMask) > 0);
s32 freq = (sd->vcur.AC50Hz > 0);
s32 wbal = sd->vcur.whitebal;
u8 dat_sharp[] = {0x6c, 0x00, 0x08};
u8 dat_bright2[] = {0x90, 0x00, 0x00};
u8 dat_freq2[] = {0x90, 0x00, 0x80};
u8 dat_multi1[] = {0x8c, 0xa7, 0x00};
u8 dat_multi2[] = {0x90, 0x00, 0x00};
u8 dat_multi3[] = {0x8c, 0xa7, 0x00};
u8 dat_multi4[] = {0x90, 0x00, 0x00};
u8 dat_hvflip2[] = {0x90, 0x04, 0x6c};
u8 dat_hvflip4[] = {0x90, 0x00, 0x24};
u8 dat_wbal2[] = {0x90, 0x00, 0x00};
if (sd->nbIm < 4) {
sd->waitSet = 1;
return 0;
}
sd->waitSet = 0;
if (freq != sd->vold.AC50Hz) {
sd->vold.AC50Hz = freq;
dat_freq2[2] = freq ? 0xc0 : 0x80;
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_freq1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_freq2);
msleep(20);
}
if (wbal != sd->vold.whitebal) {
sd->vold.whitebal = wbal;
if (wbal < 0 || wbal > sd->vmax.whitebal)
wbal = 0;
dat_multi1[2] = 0x9d;
dat_multi3[2] = dat_multi1[2] + 1;
if (wbal == 0) {
dat_multi4[2] = dat_multi2[2] = 0;
dat_wbal2[2] = 0x17;
} else if (wbal == 1) {
dat_multi4[2] = dat_multi2[2] = 0;
dat_wbal2[2] = 0x35;
} else if (wbal == 2) {
dat_multi4[2] = dat_multi2[2] = 0x20;
dat_wbal2[2] = 0x17;
}
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_wbal1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_wbal2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi6);
}
if (mirror != sd->vold.mirror || flip != sd->vold.flip) {
sd->vold.mirror = mirror;
sd->vold.flip = flip;
dat_hvflip2[2] = 0x6c + 2 * (1 - flip) + (1 - mirror);
dat_hvflip4[2] = 0x24 + 2 * (1 - flip) + (1 - mirror);
fetch_idxdata(gspca_dev, tbl_init_post_alt_3B,
ARRAY_SIZE(tbl_init_post_alt_3B));
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_hvflip6);
msleep(40);
if (reso == IMAGE_640 || reso == IMAGE_800)
fetch_idxdata(gspca_dev, tbl_middle_hvflip_low,
ARRAY_SIZE(tbl_middle_hvflip_low));
else
fetch_idxdata(gspca_dev, tbl_middle_hvflip_big,
ARRAY_SIZE(tbl_middle_hvflip_big));
fetch_idxdata(gspca_dev, tbl_end_hvflip,
ARRAY_SIZE(tbl_end_hvflip));
}
if (bright != sd->vold.brightness) {
sd->vold.brightness = bright;
if (bright < 0 || bright > sd->vmax.brightness)
bright = 0;
dat_bright2[2] = bright;
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_bright6);
}
if (cntr != sd->vold.contrast || gam != sd->vold.gamma) {
sd->vold.contrast = cntr;
if (cntr < 0 || cntr > sd->vmax.contrast)
cntr = 0;
sd->vold.gamma = gam;
if (gam < 0 || gam > sd->vmax.gamma)
gam = 0;
dat_multi1[2] = 0x6d;
dat_multi3[2] = dat_multi1[2] + 1;
if (cntr == 0)
cntr = 4;
dat_multi4[2] = dat_multi2[2] = cntr * 0x10 + 2 - gam;
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi6);
}
if (backlight != sd->vold.backlight) {
sd->vold.backlight = backlight;
if (backlight < 0 || backlight > sd->vmax.backlight)
backlight = 0;
dat_multi1[2] = 0x9d;
dat_multi3[2] = dat_multi1[2] + 1;
dat_multi4[2] = dat_multi2[2] = backlight;
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi1);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi2);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi3);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi4);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi5);
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0033, 3, dat_multi6);
}
if (sharp != sd->vold.sharpness) {
sd->vold.sharpness = sharp;
if (sharp < 0 || sharp > sd->vmax.sharpness)
sharp = 0;
dat_sharp[1] = sharp;
ctrl_out(gspca_dev, 0x40, 3, 0x7a00, 0x0032, 3, dat_sharp);
}
if (hue != sd->vold.hue) {
sd->swapRB = hue;
sd->vold.hue = hue;
}
return 0;
}
static void mi2020_post_unset_alt(struct gspca_dev *gspca_dev)
{
ctrl_out(gspca_dev, 0x40, 5, 0x0000, 0x0000, 0, NULL);
msleep(40);
ctrl_out(gspca_dev, 0x40, 1, 0x0001, 0x0000, 0, NULL);
}
