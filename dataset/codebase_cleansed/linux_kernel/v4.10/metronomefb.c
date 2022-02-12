static u8 calc_cksum(int start, int end, u8 *mem)
{
u8 tmp = 0;
int i;
for (i = start; i < end; i++)
tmp += mem[i];
return tmp;
}
static u16 calc_img_cksum(u16 *start, int length)
{
u16 tmp = 0;
while (length--)
tmp += *start++;
return tmp;
}
static int load_waveform(u8 *mem, size_t size, int m, int t,
struct metronomefb_par *par)
{
int tta;
int wmta;
int trn = 0;
int i;
unsigned char v;
u8 cksum;
int cksum_idx;
int wfm_idx, owfm_idx;
int mem_idx = 0;
struct waveform_hdr *wfm_hdr;
u8 *metromem = par->metromem_wfm;
struct device *dev = par->info->dev;
if (user_wfm_size)
epd_frame_table[par->dt].wfm_size = user_wfm_size;
if (size != epd_frame_table[par->dt].wfm_size) {
dev_err(dev, "Error: unexpected size %Zd != %d\n", size,
epd_frame_table[par->dt].wfm_size);
return -EINVAL;
}
wfm_hdr = (struct waveform_hdr *) mem;
if (wfm_hdr->fvsn != 1) {
dev_err(dev, "Error: bad fvsn %x\n", wfm_hdr->fvsn);
return -EINVAL;
}
if (wfm_hdr->luts != 0) {
dev_err(dev, "Error: bad luts %x\n", wfm_hdr->luts);
return -EINVAL;
}
cksum = calc_cksum(32, 47, mem);
if (cksum != wfm_hdr->wfm_cs) {
dev_err(dev, "Error: bad cksum %x != %x\n", cksum,
wfm_hdr->wfm_cs);
return -EINVAL;
}
wfm_hdr->mc += 1;
wfm_hdr->trc += 1;
for (i = 0; i < 5; i++) {
if (*(wfm_hdr->stuff2a + i) != 0) {
dev_err(dev, "Error: unexpected value in padding\n");
return -EINVAL;
}
}
if ((sizeof(*wfm_hdr) + wfm_hdr->trc) > size)
return -EINVAL;
for (i = sizeof(*wfm_hdr); i <= sizeof(*wfm_hdr) + wfm_hdr->trc; i++) {
if (mem[i] > t) {
trn = i - sizeof(*wfm_hdr) - 1;
break;
}
}
cksum_idx = sizeof(*wfm_hdr) + wfm_hdr->trc + 1;
if (cksum_idx > size)
return -EINVAL;
cksum = calc_cksum(sizeof(*wfm_hdr), cksum_idx, mem);
if (cksum != mem[cksum_idx]) {
dev_err(dev, "Error: bad temperature range table cksum"
" %x != %x\n", cksum, mem[cksum_idx]);
return -EINVAL;
}
wmta = get_unaligned_le32(wfm_hdr->wmta) & 0x00FFFFFF;
cksum_idx = wmta + m*4 + 3;
if (cksum_idx > size)
return -EINVAL;
cksum = calc_cksum(cksum_idx - 3, cksum_idx, mem);
if (cksum != mem[cksum_idx]) {
dev_err(dev, "Error: bad mode table address cksum"
" %x != %x\n", cksum, mem[cksum_idx]);
return -EINVAL;
}
tta = get_unaligned_le32(mem + wmta + m * 4) & 0x00FFFFFF;
cksum_idx = tta + trn*4 + 3;
if (cksum_idx > size)
return -EINVAL;
cksum = calc_cksum(cksum_idx - 3, cksum_idx, mem);
if (cksum != mem[cksum_idx]) {
dev_err(dev, "Error: bad temperature table address cksum"
" %x != %x\n", cksum, mem[cksum_idx]);
return -EINVAL;
}
wfm_idx = get_unaligned_le32(mem + tta + trn * 4) & 0x00FFFFFF;
owfm_idx = wfm_idx;
if (wfm_idx > size)
return -EINVAL;
while (wfm_idx < size) {
unsigned char rl;
v = mem[wfm_idx++];
if (v == wfm_hdr->swtb) {
while (((v = mem[wfm_idx++]) != wfm_hdr->swtb) &&
wfm_idx < size)
metromem[mem_idx++] = v;
continue;
}
if (v == wfm_hdr->endb)
break;
rl = mem[wfm_idx++];
for (i = 0; i <= rl; i++)
metromem[mem_idx++] = v;
}
cksum_idx = wfm_idx;
if (cksum_idx > size)
return -EINVAL;
cksum = calc_cksum(owfm_idx, cksum_idx, mem);
if (cksum != mem[cksum_idx]) {
dev_err(dev, "Error: bad waveform data cksum"
" %x != %x\n", cksum, mem[cksum_idx]);
return -EINVAL;
}
par->frame_count = (mem_idx/64);
return 0;
}
static int metronome_display_cmd(struct metronomefb_par *par)
{
int i;
u16 cs;
u16 opcode;
static u8 borderval;
if (par->metromem_cmd->opcode == 0xCC40)
opcode = cs = 0xCC41;
else
opcode = cs = 0xCC40;
i = 0;
par->metromem_cmd->args[i] = 1 << 3
| ((borderval++ % 4) & 0x0F) << 4
| (par->frame_count - 1) << 8;
cs += par->metromem_cmd->args[i++];
memset((u8 *) (par->metromem_cmd->args + i), 0, (32-i)*2);
par->metromem_cmd->csum = cs;
par->metromem_cmd->opcode = opcode;
return par->board->met_wait_event_intr(par);
}
static int metronome_powerup_cmd(struct metronomefb_par *par)
{
int i;
u16 cs;
par->metromem_cmd->opcode = 0x1234;
cs = par->metromem_cmd->opcode;
for (i = 0; i < 3; i++) {
par->metromem_cmd->args[i] = 1024;
cs += par->metromem_cmd->args[i];
}
memset(&par->metromem_cmd->args[i], 0,
(ARRAY_SIZE(par->metromem_cmd->args) - i) * 2);
par->metromem_cmd->csum = cs;
msleep(1);
par->board->set_rst(par, 1);
msleep(1);
par->board->set_stdby(par, 1);
return par->board->met_wait_event(par);
}
static int metronome_config_cmd(struct metronomefb_par *par)
{
memcpy(par->metromem_cmd->args, epd_frame_table[par->dt].config,
sizeof(epd_frame_table[par->dt].config));
memset(&par->metromem_cmd->args[4], 0,
(ARRAY_SIZE(par->metromem_cmd->args) - 4) * 2);
par->metromem_cmd->csum = 0xCC10;
par->metromem_cmd->csum += calc_img_cksum(par->metromem_cmd->args, 4);
par->metromem_cmd->opcode = 0xCC10;
return par->board->met_wait_event(par);
}
static int metronome_init_cmd(struct metronomefb_par *par)
{
int i;
u16 cs;
cs = 0xCC20;
i = 0;
par->metromem_cmd->args[i] = 0;
cs += par->metromem_cmd->args[i++];
memset((u8 *) (par->metromem_cmd->args + i), 0, (32-i)*2);
par->metromem_cmd->csum = cs;
par->metromem_cmd->opcode = 0xCC20;
return par->board->met_wait_event(par);
}
static int metronome_init_regs(struct metronomefb_par *par)
{
int res;
res = par->board->setup_io(par);
if (res)
return res;
res = metronome_powerup_cmd(par);
if (res)
return res;
res = metronome_config_cmd(par);
if (res)
return res;
res = metronome_init_cmd(par);
return res;
}
static void metronomefb_dpy_update(struct metronomefb_par *par)
{
int fbsize;
u16 cksum;
unsigned char *buf = (unsigned char __force *)par->info->screen_base;
fbsize = par->info->fix.smem_len;
memcpy(par->metromem_img, buf, fbsize);
cksum = calc_img_cksum((u16 *) par->metromem_img, fbsize/2);
*((u16 *)(par->metromem_img) + fbsize/2) = cksum;
metronome_display_cmd(par);
}
static u16 metronomefb_dpy_update_page(struct metronomefb_par *par, int index)
{
int i;
u16 csum = 0;
u16 *buf = (u16 __force *)(par->info->screen_base + index);
u16 *img = (u16 *)(par->metromem_img + index);
for (i = 0; i < PAGE_SIZE/2; i++) {
*(img + i) = (buf[i] << 5) & 0xE0E0;
csum += *(img + i);
}
return csum;
}
static void metronomefb_dpy_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
u16 cksum;
struct page *cur;
struct fb_deferred_io *fbdefio = info->fbdefio;
struct metronomefb_par *par = info->par;
list_for_each_entry(cur, &fbdefio->pagelist, lru) {
cksum = metronomefb_dpy_update_page(par,
(cur->index << PAGE_SHIFT));
par->metromem_img_csum -= par->csum_table[cur->index];
par->csum_table[cur->index] = cksum;
par->metromem_img_csum += cksum;
}
metronome_display_cmd(par);
}
static void metronomefb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
struct metronomefb_par *par = info->par;
sys_fillrect(info, rect);
metronomefb_dpy_update(par);
}
static void metronomefb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
struct metronomefb_par *par = info->par;
sys_copyarea(info, area);
metronomefb_dpy_update(par);
}
static void metronomefb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
struct metronomefb_par *par = info->par;
sys_imageblit(info, image);
metronomefb_dpy_update(par);
}
static ssize_t metronomefb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
struct metronomefb_par *par = info->par;
unsigned long p = *ppos;
void *dst;
int err = 0;
unsigned long total_size;
if (info->state != FBINFO_STATE_RUNNING)
return -EPERM;
total_size = info->fix.smem_len;
if (p > total_size)
return -EFBIG;
if (count > total_size) {
err = -EFBIG;
count = total_size;
}
if (count + p > total_size) {
if (!err)
err = -ENOSPC;
count = total_size - p;
}
dst = (void __force *)(info->screen_base + p);
if (copy_from_user(dst, buf, count))
err = -EFAULT;
if (!err)
*ppos += count;
metronomefb_dpy_update(par);
return (err) ? err : count;
}
static int metronomefb_probe(struct platform_device *dev)
{
struct fb_info *info;
struct metronome_board *board;
int retval = -ENOMEM;
int videomemorysize;
unsigned char *videomemory;
struct metronomefb_par *par;
const struct firmware *fw_entry;
int i;
int panel_type;
int fw, fh;
int epd_dt_index;
board = dev->dev.platform_data;
if (!board)
return -EINVAL;
if (!try_module_get(board->owner))
return -ENODEV;
info = framebuffer_alloc(sizeof(struct metronomefb_par), &dev->dev);
if (!info)
goto err;
panel_type = board->get_panel_type();
switch (panel_type) {
case 6:
epd_dt_index = 0;
break;
case 8:
epd_dt_index = 1;
break;
case 97:
epd_dt_index = 2;
break;
default:
dev_err(&dev->dev, "Unexpected panel type. Defaulting to 6\n");
epd_dt_index = 0;
break;
}
fw = epd_frame_table[epd_dt_index].fw;
fh = epd_frame_table[epd_dt_index].fh;
videomemorysize = PAGE_SIZE + (fw * fh);
videomemory = vzalloc(videomemorysize);
if (!videomemory)
goto err_fb_rel;
info->screen_base = (char __force __iomem *)videomemory;
info->fbops = &metronomefb_ops;
metronomefb_fix.line_length = fw;
metronomefb_var.xres = fw;
metronomefb_var.yres = fh;
metronomefb_var.xres_virtual = fw;
metronomefb_var.yres_virtual = fh;
info->var = metronomefb_var;
info->fix = metronomefb_fix;
info->fix.smem_len = videomemorysize;
par = info->par;
par->info = info;
par->board = board;
par->dt = epd_dt_index;
init_waitqueue_head(&par->waitq);
par->csum_table = vmalloc(videomemorysize/PAGE_SIZE);
if (!par->csum_table)
goto err_vfree;
retval = board->setup_fb(par);
if (retval) {
dev_err(&dev->dev, "Failed to setup fb\n");
goto err_csum_table;
}
if ((!par->metromem_wfm) || (!par->metromem_img) ||
(!par->metromem_dma)) {
dev_err(&dev->dev, "fb access failure\n");
retval = -EINVAL;
goto err_csum_table;
}
info->fix.smem_start = par->metromem_dma;
retval = request_firmware(&fw_entry, "metronome.wbf", &dev->dev);
if (retval < 0) {
dev_err(&dev->dev, "Failed to get waveform\n");
goto err_csum_table;
}
retval = load_waveform((u8 *) fw_entry->data, fw_entry->size, 3, 31,
par);
release_firmware(fw_entry);
if (retval < 0) {
dev_err(&dev->dev, "Failed processing waveform\n");
goto err_csum_table;
}
retval = board->setup_irq(info);
if (retval)
goto err_csum_table;
retval = metronome_init_regs(par);
if (retval < 0)
goto err_free_irq;
info->flags = FBINFO_FLAG_DEFAULT | FBINFO_VIRTFB;
info->fbdefio = &metronomefb_defio;
fb_deferred_io_init(info);
retval = fb_alloc_cmap(&info->cmap, 8, 0);
if (retval < 0) {
dev_err(&dev->dev, "Failed to allocate colormap\n");
goto err_free_irq;
}
for (i = 0; i < 8; i++)
info->cmap.red[i] = (((2*i)+1)*(0xFFFF))/16;
memcpy(info->cmap.green, info->cmap.red, sizeof(u16)*8);
memcpy(info->cmap.blue, info->cmap.red, sizeof(u16)*8);
retval = register_framebuffer(info);
if (retval < 0)
goto err_cmap;
platform_set_drvdata(dev, info);
dev_dbg(&dev->dev,
"fb%d: Metronome frame buffer device, using %dK of video"
" memory\n", info->node, videomemorysize >> 10);
return 0;
err_cmap:
fb_dealloc_cmap(&info->cmap);
err_free_irq:
board->cleanup(par);
err_csum_table:
vfree(par->csum_table);
err_vfree:
vfree(videomemory);
err_fb_rel:
framebuffer_release(info);
err:
module_put(board->owner);
return retval;
}
static int metronomefb_remove(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
if (info) {
struct metronomefb_par *par = info->par;
unregister_framebuffer(info);
fb_deferred_io_cleanup(info);
fb_dealloc_cmap(&info->cmap);
par->board->cleanup(par);
vfree(par->csum_table);
vfree((void __force *)info->screen_base);
module_put(par->board->owner);
dev_dbg(&dev->dev, "calling release\n");
framebuffer_release(info);
}
return 0;
}
