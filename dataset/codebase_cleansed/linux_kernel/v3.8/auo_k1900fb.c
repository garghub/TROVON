static void auok1900_init(struct auok190xfb_par *par)
{
struct auok190x_board *board = par->board;
u16 init_param = 0;
init_param |= AUOK1900_INIT_TEMP_AVERAGE;
init_param |= AUOK1900_INIT_ROTATE(par->rotation);
init_param |= AUOK190X_INIT_INVERSE_WHITE;
init_param |= AUOK190X_INIT_FORMAT0;
init_param |= AUOK1900_INIT_RESOLUTION(par->resolution);
init_param |= AUOK190X_INIT_SHIFT_RIGHT;
auok190x_send_cmdargs(par, AUOK190X_CMD_INIT, 1, &init_param);
board->wait_for_rdy(par);
}
static void auok1900_update_region(struct auok190xfb_par *par, int mode,
u16 y1, u16 y2)
{
struct device *dev = par->info->device;
unsigned char *buf = (unsigned char *)par->info->screen_base;
int xres = par->info->var.xres;
u16 args[4];
pm_runtime_get_sync(dev);
mutex_lock(&(par->io_lock));
y1 &= 0xfffe;
y2 &= 0xfffe;
dev_dbg(dev, "update (x,y,w,h,mode)=(%d,%d,%d,%d,%d)\n",
1, y1+1, xres, y2-y1, mode);
args[0] = mode | 1;
args[1] = y1 + 1;
args[2] = xres;
args[3] = y2 - y1;
buf += y1 * xres;
auok190x_send_cmdargs_pixels(par, AUOK1900_CMD_PARTIALDISP, 4, args,
((y2 - y1) * xres)/2, (u16 *) buf);
auok190x_send_command(par, AUOK190X_CMD_DATA_STOP);
par->update_cnt++;
mutex_unlock(&(par->io_lock));
pm_runtime_mark_last_busy(dev);
pm_runtime_put_autosuspend(dev);
}
static void auok1900fb_dpy_update_pages(struct auok190xfb_par *par,
u16 y1, u16 y2)
{
int mode;
if (par->update_mode < 0) {
mode = AUOK190X_UPDATE_MODE(1);
par->last_mode = -1;
} else {
mode = AUOK190X_UPDATE_MODE(par->update_mode);
par->last_mode = par->update_mode;
}
if (par->flash)
mode |= AUOK190X_UPDATE_NONFLASH;
auok1900_update_region(par, mode, y1, y2);
}
static void auok1900fb_dpy_update(struct auok190xfb_par *par)
{
int mode;
if (par->update_mode < 0) {
mode = AUOK190X_UPDATE_MODE(0);
par->last_mode = -1;
} else {
mode = AUOK190X_UPDATE_MODE(par->update_mode);
par->last_mode = par->update_mode;
}
if (par->flash)
mode |= AUOK190X_UPDATE_NONFLASH;
auok1900_update_region(par, mode, 0, par->info->var.yres);
par->update_cnt = 0;
}
static bool auok1900fb_need_refresh(struct auok190xfb_par *par)
{
return (par->update_cnt > 10);
}
static int auok1900fb_probe(struct platform_device *pdev)
{
struct auok190x_init_data init;
struct auok190x_board *board;
board = pdev->dev.platform_data;
if (!board)
return -EINVAL;
init.id = "auo_k1900fb";
init.board = board;
init.update_partial = auok1900fb_dpy_update_pages;
init.update_all = auok1900fb_dpy_update;
init.need_refresh = auok1900fb_need_refresh;
init.init = auok1900_init;
return auok190x_common_probe(pdev, &init);
}
static int auok1900fb_remove(struct platform_device *pdev)
{
return auok190x_common_remove(pdev);
}
