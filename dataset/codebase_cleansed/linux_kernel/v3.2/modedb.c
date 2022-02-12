static int fb_try_mode(struct fb_var_screeninfo *var, struct fb_info *info,
const struct fb_videomode *mode, unsigned int bpp)
{
int err = 0;
DPRINTK("Trying mode %s %dx%d-%d@%d\n",
mode->name ? mode->name : "noname",
mode->xres, mode->yres, bpp, mode->refresh);
var->xres = mode->xres;
var->yres = mode->yres;
var->xres_virtual = mode->xres;
var->yres_virtual = mode->yres;
var->xoffset = 0;
var->yoffset = 0;
var->bits_per_pixel = bpp;
var->activate |= FB_ACTIVATE_TEST;
var->pixclock = mode->pixclock;
var->left_margin = mode->left_margin;
var->right_margin = mode->right_margin;
var->upper_margin = mode->upper_margin;
var->lower_margin = mode->lower_margin;
var->hsync_len = mode->hsync_len;
var->vsync_len = mode->vsync_len;
var->sync = mode->sync;
var->vmode = mode->vmode;
if (info->fbops->fb_check_var)
err = info->fbops->fb_check_var(var, info);
var->activate &= ~FB_ACTIVATE_TEST;
return err;
}
int fb_find_mode(struct fb_var_screeninfo *var,
struct fb_info *info, const char *mode_option,
const struct fb_videomode *db, unsigned int dbsize,
const struct fb_videomode *default_mode,
unsigned int default_bpp)
{
int i;
if (!db) {
db = modedb;
dbsize = ARRAY_SIZE(modedb);
}
if (!default_mode)
default_mode = &db[0];
if (!default_bpp)
default_bpp = 8;
if (!mode_option)
mode_option = fb_mode_option;
if (mode_option) {
const char *name = mode_option;
unsigned int namelen = strlen(name);
int res_specified = 0, bpp_specified = 0, refresh_specified = 0;
unsigned int xres = 0, yres = 0, bpp = default_bpp, refresh = 0;
int yres_specified = 0, cvt = 0, rb = 0, interlace = 0;
int margins = 0;
u32 best, diff, tdiff;
for (i = namelen-1; i >= 0; i--) {
switch (name[i]) {
case '@':
namelen = i;
if (!refresh_specified && !bpp_specified &&
!yres_specified) {
refresh = simple_strtol(&name[i+1], NULL,
10);
refresh_specified = 1;
if (cvt || rb)
cvt = 0;
} else
goto done;
break;
case '-':
namelen = i;
if (!bpp_specified && !yres_specified) {
bpp = simple_strtol(&name[i+1], NULL,
10);
bpp_specified = 1;
if (cvt || rb)
cvt = 0;
} else
goto done;
break;
case 'x':
if (!yres_specified) {
yres = simple_strtol(&name[i+1], NULL,
10);
yres_specified = 1;
} else
goto done;
break;
case '0' ... '9':
break;
case 'M':
if (!yres_specified)
cvt = 1;
break;
case 'R':
if (!cvt)
rb = 1;
break;
case 'm':
if (!cvt)
margins = 1;
break;
case 'i':
if (!cvt)
interlace = 1;
break;
default:
goto done;
}
}
if (i < 0 && yres_specified) {
xres = simple_strtol(name, NULL, 10);
res_specified = 1;
}
done:
if (cvt) {
struct fb_videomode cvt_mode;
int ret;
DPRINTK("CVT mode %dx%d@%dHz%s%s%s\n", xres, yres,
(refresh) ? refresh : 60,
(rb) ? " reduced blanking" : "",
(margins) ? " with margins" : "",
(interlace) ? " interlaced" : "");
memset(&cvt_mode, 0, sizeof(cvt_mode));
cvt_mode.xres = xres;
cvt_mode.yres = yres;
cvt_mode.refresh = (refresh) ? refresh : 60;
if (interlace)
cvt_mode.vmode |= FB_VMODE_INTERLACED;
else
cvt_mode.vmode &= ~FB_VMODE_INTERLACED;
ret = fb_find_mode_cvt(&cvt_mode, margins, rb);
if (!ret && !fb_try_mode(var, info, &cvt_mode, bpp)) {
DPRINTK("modedb CVT: CVT mode ok\n");
return 1;
}
DPRINTK("CVT mode invalid, getting mode from database\n");
}
DPRINTK("Trying specified video mode%s %ix%i\n",
refresh_specified ? "" : " (ignoring refresh rate)",
xres, yres);
if (!refresh_specified) {
if (db != modedb &&
info->monspecs.vfmin && info->monspecs.vfmax &&
info->monspecs.hfmin && info->monspecs.hfmax &&
info->monspecs.dclkmax) {
refresh = 1000;
} else {
refresh = 60;
}
}
diff = -1;
best = -1;
for (i = 0; i < dbsize; i++) {
if ((name_matches(db[i], name, namelen) ||
(res_specified && res_matches(db[i], xres, yres))) &&
!fb_try_mode(var, info, &db[i], bpp)) {
if (refresh_specified && db[i].refresh == refresh)
return 1;
if (abs(db[i].refresh - refresh) < diff) {
diff = abs(db[i].refresh - refresh);
best = i;
}
}
}
if (best != -1) {
fb_try_mode(var, info, &db[best], bpp);
return (refresh_specified) ? 2 : 1;
}
diff = 2 * (xres + yres);
best = -1;
DPRINTK("Trying best-fit modes\n");
for (i = 0; i < dbsize; i++) {
DPRINTK("Trying %ix%i\n", db[i].xres, db[i].yres);
if (!fb_try_mode(var, info, &db[i], bpp)) {
tdiff = abs(db[i].xres - xres) +
abs(db[i].yres - yres);
if (xres > db[i].xres || yres > db[i].yres)
tdiff += xres + yres;
if (diff > tdiff) {
diff = tdiff;
best = i;
}
}
}
if (best != -1) {
fb_try_mode(var, info, &db[best], bpp);
return 5;
}
}
DPRINTK("Trying default video mode\n");
if (!fb_try_mode(var, info, default_mode, default_bpp))
return 3;
DPRINTK("Trying all modes\n");
for (i = 0; i < dbsize; i++)
if (!fb_try_mode(var, info, &db[i], default_bpp))
return 4;
DPRINTK("No valid mode found\n");
return 0;
}
void fb_var_to_videomode(struct fb_videomode *mode,
const struct fb_var_screeninfo *var)
{
u32 pixclock, hfreq, htotal, vtotal;
mode->name = NULL;
mode->xres = var->xres;
mode->yres = var->yres;
mode->pixclock = var->pixclock;
mode->hsync_len = var->hsync_len;
mode->vsync_len = var->vsync_len;
mode->left_margin = var->left_margin;
mode->right_margin = var->right_margin;
mode->upper_margin = var->upper_margin;
mode->lower_margin = var->lower_margin;
mode->sync = var->sync;
mode->vmode = var->vmode & FB_VMODE_MASK;
mode->flag = FB_MODE_IS_FROM_VAR;
mode->refresh = 0;
if (!var->pixclock)
return;
pixclock = PICOS2KHZ(var->pixclock) * 1000;
htotal = var->xres + var->right_margin + var->hsync_len +
var->left_margin;
vtotal = var->yres + var->lower_margin + var->vsync_len +
var->upper_margin;
if (var->vmode & FB_VMODE_INTERLACED)
vtotal /= 2;
if (var->vmode & FB_VMODE_DOUBLE)
vtotal *= 2;
hfreq = pixclock/htotal;
mode->refresh = hfreq/vtotal;
}
void fb_videomode_to_var(struct fb_var_screeninfo *var,
const struct fb_videomode *mode)
{
var->xres = mode->xres;
var->yres = mode->yres;
var->xres_virtual = mode->xres;
var->yres_virtual = mode->yres;
var->xoffset = 0;
var->yoffset = 0;
var->pixclock = mode->pixclock;
var->left_margin = mode->left_margin;
var->right_margin = mode->right_margin;
var->upper_margin = mode->upper_margin;
var->lower_margin = mode->lower_margin;
var->hsync_len = mode->hsync_len;
var->vsync_len = mode->vsync_len;
var->sync = mode->sync;
var->vmode = mode->vmode & FB_VMODE_MASK;
}
int fb_mode_is_equal(const struct fb_videomode *mode1,
const struct fb_videomode *mode2)
{
return (mode1->xres == mode2->xres &&
mode1->yres == mode2->yres &&
mode1->pixclock == mode2->pixclock &&
mode1->hsync_len == mode2->hsync_len &&
mode1->vsync_len == mode2->vsync_len &&
mode1->left_margin == mode2->left_margin &&
mode1->right_margin == mode2->right_margin &&
mode1->upper_margin == mode2->upper_margin &&
mode1->lower_margin == mode2->lower_margin &&
mode1->sync == mode2->sync &&
mode1->vmode == mode2->vmode);
}
const struct fb_videomode *fb_find_best_mode(const struct fb_var_screeninfo *var,
struct list_head *head)
{
struct list_head *pos;
struct fb_modelist *modelist;
struct fb_videomode *mode, *best = NULL;
u32 diff = -1;
list_for_each(pos, head) {
u32 d;
modelist = list_entry(pos, struct fb_modelist, list);
mode = &modelist->mode;
if (mode->xres >= var->xres && mode->yres >= var->yres) {
d = (mode->xres - var->xres) +
(mode->yres - var->yres);
if (diff > d) {
diff = d;
best = mode;
} else if (diff == d && best &&
mode->refresh > best->refresh)
best = mode;
}
}
return best;
}
const struct fb_videomode *fb_find_nearest_mode(const struct fb_videomode *mode,
struct list_head *head)
{
struct list_head *pos;
struct fb_modelist *modelist;
struct fb_videomode *cmode, *best = NULL;
u32 diff = -1, diff_refresh = -1;
list_for_each(pos, head) {
u32 d;
modelist = list_entry(pos, struct fb_modelist, list);
cmode = &modelist->mode;
d = abs(cmode->xres - mode->xres) +
abs(cmode->yres - mode->yres);
if (diff > d) {
diff = d;
diff_refresh = abs(cmode->refresh - mode->refresh);
best = cmode;
} else if (diff == d) {
d = abs(cmode->refresh - mode->refresh);
if (diff_refresh > d) {
diff_refresh = d;
best = cmode;
}
}
}
return best;
}
const struct fb_videomode *fb_match_mode(const struct fb_var_screeninfo *var,
struct list_head *head)
{
struct list_head *pos;
struct fb_modelist *modelist;
struct fb_videomode *m, mode;
fb_var_to_videomode(&mode, var);
list_for_each(pos, head) {
modelist = list_entry(pos, struct fb_modelist, list);
m = &modelist->mode;
if (fb_mode_is_equal(m, &mode))
return m;
}
return NULL;
}
int fb_add_videomode(const struct fb_videomode *mode, struct list_head *head)
{
struct list_head *pos;
struct fb_modelist *modelist;
struct fb_videomode *m;
int found = 0;
list_for_each(pos, head) {
modelist = list_entry(pos, struct fb_modelist, list);
m = &modelist->mode;
if (fb_mode_is_equal(m, mode)) {
found = 1;
break;
}
}
if (!found) {
modelist = kmalloc(sizeof(struct fb_modelist),
GFP_KERNEL);
if (!modelist)
return -ENOMEM;
modelist->mode = *mode;
list_add(&modelist->list, head);
}
return 0;
}
void fb_delete_videomode(const struct fb_videomode *mode,
struct list_head *head)
{
struct list_head *pos, *n;
struct fb_modelist *modelist;
struct fb_videomode *m;
list_for_each_safe(pos, n, head) {
modelist = list_entry(pos, struct fb_modelist, list);
m = &modelist->mode;
if (fb_mode_is_equal(m, mode)) {
list_del(pos);
kfree(pos);
}
}
}
void fb_destroy_modelist(struct list_head *head)
{
struct list_head *pos, *n;
list_for_each_safe(pos, n, head) {
list_del(pos);
kfree(pos);
}
}
void fb_videomode_to_modelist(const struct fb_videomode *modedb, int num,
struct list_head *head)
{
int i;
INIT_LIST_HEAD(head);
for (i = 0; i < num; i++) {
if (fb_add_videomode(&modedb[i], head))
return;
}
}
const struct fb_videomode *fb_find_best_display(const struct fb_monspecs *specs,
struct list_head *head)
{
struct list_head *pos;
struct fb_modelist *modelist;
const struct fb_videomode *m, *m1 = NULL, *md = NULL, *best = NULL;
int first = 0;
if (!head->prev || !head->next || list_empty(head))
goto finished;
list_for_each(pos, head) {
modelist = list_entry(pos, struct fb_modelist, list);
m = &modelist->mode;
if (!first) {
m1 = m;
first = 1;
}
if (m->flag & FB_MODE_IS_FIRST) {
md = m;
break;
}
}
if (specs->misc & FB_MISC_1ST_DETAIL) {
best = md;
goto finished;
}
if (specs->max_x && specs->max_y) {
struct fb_var_screeninfo var;
memset(&var, 0, sizeof(struct fb_var_screeninfo));
var.xres = (specs->max_x * 7200)/254;
var.yres = (specs->max_y * 7200)/254;
m = fb_find_best_mode(&var, head);
if (m) {
best = m;
goto finished;
}
}
if (md) {
best = md;
goto finished;
}
best = m1;
finished:
return best;
}
