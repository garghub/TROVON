static int sti_init_graph(struct sti_struct *sti)
{
struct sti_init_inptr *inptr = &sti->sti_data->init_inptr;
struct sti_init_inptr_ext *inptr_ext = &sti->sti_data->init_inptr_ext;
struct sti_init_outptr *outptr = &sti->sti_data->init_outptr;
unsigned long flags;
int ret, err;
spin_lock_irqsave(&sti->lock, flags);
memset(inptr, 0, sizeof(*inptr));
inptr->text_planes = 3;
memset(inptr_ext, 0, sizeof(*inptr_ext));
inptr->ext_ptr = STI_PTR(inptr_ext);
outptr->errno = 0;
ret = sti_call(sti, sti->init_graph, &default_init_flags, inptr,
outptr, sti->glob_cfg);
if (ret >= 0)
sti->text_planes = outptr->text_planes;
err = outptr->errno;
spin_unlock_irqrestore(&sti->lock, flags);
if (ret < 0) {
pr_err("STI init_graph failed (ret %d, errno %d)\n", ret, err);
return -1;
}
return 0;
}
static void sti_inq_conf(struct sti_struct *sti)
{
struct sti_conf_inptr *inptr = &sti->sti_data->inq_inptr;
struct sti_conf_outptr *outptr = &sti->sti_data->inq_outptr;
unsigned long flags;
s32 ret;
outptr->ext_ptr = STI_PTR(&sti->sti_data->inq_outptr_ext);
do {
spin_lock_irqsave(&sti->lock, flags);
memset(inptr, 0, sizeof(*inptr));
ret = sti_call(sti, sti->inq_conf, &default_conf_flags,
inptr, outptr, sti->glob_cfg);
spin_unlock_irqrestore(&sti->lock, flags);
} while (ret == 1);
}
void
sti_putc(struct sti_struct *sti, int c, int y, int x)
{
struct sti_font_inptr *inptr = &sti->sti_data->font_inptr;
struct sti_font_inptr inptr_default = {
.font_start_addr= STI_PTR(sti->font->raw),
.index = c_index(sti, c),
.fg_color = c_fg(sti, c),
.bg_color = c_bg(sti, c),
.dest_x = x * sti->font_width,
.dest_y = y * sti->font_height,
};
struct sti_font_outptr *outptr = &sti->sti_data->font_outptr;
s32 ret;
unsigned long flags;
do {
spin_lock_irqsave(&sti->lock, flags);
*inptr = inptr_default;
ret = sti_call(sti, sti->font_unpmv, &default_font_flags,
inptr, outptr, sti->glob_cfg);
spin_unlock_irqrestore(&sti->lock, flags);
} while (ret == 1);
}
void
sti_set(struct sti_struct *sti, int src_y, int src_x,
int height, int width, u8 color)
{
struct sti_blkmv_inptr *inptr = &sti->sti_data->blkmv_inptr;
struct sti_blkmv_inptr inptr_default = {
.fg_color = color,
.bg_color = color,
.src_x = src_x,
.src_y = src_y,
.dest_x = src_x,
.dest_y = src_y,
.width = width,
.height = height,
};
struct sti_blkmv_outptr *outptr = &sti->sti_data->blkmv_outptr;
s32 ret;
unsigned long flags;
do {
spin_lock_irqsave(&sti->lock, flags);
*inptr = inptr_default;
ret = sti_call(sti, sti->block_move, &clear_blkmv_flags,
inptr, outptr, sti->glob_cfg);
spin_unlock_irqrestore(&sti->lock, flags);
} while (ret == 1);
}
void
sti_clear(struct sti_struct *sti, int src_y, int src_x,
int height, int width, int c)
{
struct sti_blkmv_inptr *inptr = &sti->sti_data->blkmv_inptr;
struct sti_blkmv_inptr inptr_default = {
.fg_color = c_fg(sti, c),
.bg_color = c_bg(sti, c),
.src_x = src_x * sti->font_width,
.src_y = src_y * sti->font_height,
.dest_x = src_x * sti->font_width,
.dest_y = src_y * sti->font_height,
.width = width * sti->font_width,
.height = height* sti->font_height,
};
struct sti_blkmv_outptr *outptr = &sti->sti_data->blkmv_outptr;
s32 ret;
unsigned long flags;
do {
spin_lock_irqsave(&sti->lock, flags);
*inptr = inptr_default;
ret = sti_call(sti, sti->block_move, &clear_blkmv_flags,
inptr, outptr, sti->glob_cfg);
spin_unlock_irqrestore(&sti->lock, flags);
} while (ret == 1);
}
void
sti_bmove(struct sti_struct *sti, int src_y, int src_x,
int dst_y, int dst_x, int height, int width)
{
struct sti_blkmv_inptr *inptr = &sti->sti_data->blkmv_inptr;
struct sti_blkmv_inptr inptr_default = {
.src_x = src_x * sti->font_width,
.src_y = src_y * sti->font_height,
.dest_x = dst_x * sti->font_width,
.dest_y = dst_y * sti->font_height,
.width = width * sti->font_width,
.height = height* sti->font_height,
};
struct sti_blkmv_outptr *outptr = &sti->sti_data->blkmv_outptr;
s32 ret;
unsigned long flags;
do {
spin_lock_irqsave(&sti->lock, flags);
*inptr = inptr_default;
ret = sti_call(sti, sti->block_move, &default_blkmv_flags,
inptr, outptr, sti->glob_cfg);
spin_unlock_irqrestore(&sti->lock, flags);
} while (ret == 1);
}
static void sti_flush(unsigned long start, unsigned long end)
{
flush_icache_range(start, end);
}
static void sti_rom_copy(unsigned long base, unsigned long count, void *dest)
{
unsigned long dest_start = (unsigned long) dest;
while (count >= 4) {
count -= 4;
*(u32 *)dest = gsc_readl(base);
base += 4;
dest += 4;
}
while (count) {
count--;
*(u8 *)dest = gsc_readb(base);
base++;
dest++;
}
sti_flush(dest_start, (unsigned long)dest);
}
static int sti_setup(char *str)
{
if (str)
strlcpy (default_sti_path, str, sizeof (default_sti_path));
return 1;
}
static int sti_font_setup(char *str)
{
char *x;
int i = 0;
while (i<MAX_STI_ROMS && str && *str) {
if (*str>='0' && *str<='9') {
if ((x = strchr(str, 'x')) || (x = strchr(str, '*'))) {
font_height[i] = simple_strtoul(str, NULL, 0);
font_width[i] = simple_strtoul(x+1, NULL, 0);
} else {
font_index[i] = simple_strtoul(str, NULL, 0);
}
} else {
font_name[i] = str;
}
if ((x = strchr(str, ',')))
*x++ = 0;
str = x;
i++;
}
return 1;
}
static void sti_dump_globcfg(struct sti_glob_cfg *glob_cfg,
unsigned int sti_mem_request)
{
struct sti_glob_cfg_ext *cfg;
DPRINTK((KERN_INFO
"%d text planes\n"
"%4d x %4d screen resolution\n"
"%4d x %4d offscreen\n"
"%4d x %4d layout\n"
"regions at %08x %08x %08x %08x\n"
"regions at %08x %08x %08x %08x\n"
"reent_lvl %d\n"
"save_addr %08x\n",
glob_cfg->text_planes,
glob_cfg->onscreen_x, glob_cfg->onscreen_y,
glob_cfg->offscreen_x, glob_cfg->offscreen_y,
glob_cfg->total_x, glob_cfg->total_y,
glob_cfg->region_ptrs[0], glob_cfg->region_ptrs[1],
glob_cfg->region_ptrs[2], glob_cfg->region_ptrs[3],
glob_cfg->region_ptrs[4], glob_cfg->region_ptrs[5],
glob_cfg->region_ptrs[6], glob_cfg->region_ptrs[7],
glob_cfg->reent_lvl,
glob_cfg->save_addr));
cfg = PTR_STI((unsigned long)glob_cfg->ext_ptr);
DPRINTK(( KERN_INFO
"monitor %d\n"
"in friendly mode: %d\n"
"power consumption %d watts\n"
"freq ref %d\n"
"sti_mem_addr %08x (size=%d bytes)\n",
cfg->curr_mon,
cfg->friendly_boot,
cfg->power,
cfg->freq_ref,
cfg->sti_mem_addr, sti_mem_request));
}
static void sti_dump_outptr(struct sti_struct *sti)
{
DPRINTK((KERN_INFO
"%d bits per pixel\n"
"%d used bits\n"
"%d planes\n"
"attributes %08x\n",
sti->sti_data->inq_outptr.bits_per_pixel,
sti->sti_data->inq_outptr.bits_used,
sti->sti_data->inq_outptr.planes,
sti->sti_data->inq_outptr.attributes));
}
static int sti_init_glob_cfg(struct sti_struct *sti, unsigned long rom_address,
unsigned long hpa)
{
struct sti_glob_cfg *glob_cfg;
struct sti_glob_cfg_ext *glob_cfg_ext;
void *save_addr;
void *sti_mem_addr;
int i, size;
if (sti->sti_mem_request < 256)
sti->sti_mem_request = 256;
size = sizeof(struct sti_all_data) + sti->sti_mem_request - 256;
sti->sti_data = kzalloc(size, STI_LOWMEM);
if (!sti->sti_data)
return -ENOMEM;
glob_cfg = &sti->sti_data->glob_cfg;
glob_cfg_ext = &sti->sti_data->glob_cfg_ext;
save_addr = &sti->sti_data->save_addr;
sti_mem_addr = &sti->sti_data->sti_mem_addr;
glob_cfg->ext_ptr = STI_PTR(glob_cfg_ext);
glob_cfg->save_addr = STI_PTR(save_addr);
for (i=0; i<8; i++) {
unsigned long newhpa, len;
if (sti->pd) {
unsigned char offs = sti->rm_entry[i];
if (offs == 0)
continue;
if (offs != PCI_ROM_ADDRESS &&
(offs < PCI_BASE_ADDRESS_0 ||
offs > PCI_BASE_ADDRESS_5)) {
printk (KERN_WARNING
"STI pci region mapping for region %d (%02x) can't be mapped\n",
i,sti->rm_entry[i]);
continue;
}
newhpa = pci_resource_start (sti->pd, (offs - PCI_BASE_ADDRESS_0) / 4);
} else
newhpa = (i == 0) ? rom_address : hpa;
sti->regions_phys[i] =
REGION_OFFSET_TO_PHYS(sti->regions[i], newhpa);
len = sti->regions[i].region_desc.length * 4096;
if (len)
glob_cfg->region_ptrs[i] = sti->regions_phys[i];
DPRINTK(("region #%d: phys %08lx, region_ptr %08x, len=%lukB, "
"btlb=%d, sysonly=%d, cache=%d, last=%d\n",
i, sti->regions_phys[i], glob_cfg->region_ptrs[i],
len/1024,
sti->regions[i].region_desc.btlb,
sti->regions[i].region_desc.sys_only,
sti->regions[i].region_desc.cache,
sti->regions[i].region_desc.last));
if (sti->regions[i].region_desc.last)
break;
}
if (++i<8 && sti->regions[i].region)
printk(KERN_WARNING "%s: *future ptr (0x%8x) not yet supported !\n",
__FILE__, sti->regions[i].region);
glob_cfg_ext->sti_mem_addr = STI_PTR(sti_mem_addr);
sti->glob_cfg = glob_cfg;
return 0;
}
static struct sti_cooked_font *
sti_select_fbfont(struct sti_cooked_rom *cooked_rom, const char *fbfont_name)
{
const struct font_desc *fbfont = NULL;
unsigned int size, bpc;
void *dest;
struct sti_rom_font *nf;
struct sti_cooked_font *cooked_font;
if (fbfont_name && strlen(fbfont_name))
fbfont = find_font(fbfont_name);
if (!fbfont)
fbfont = get_default_font(1024,768, ~(u32)0, ~(u32)0);
if (!fbfont)
return NULL;
pr_info("STI selected %dx%d framebuffer font %s for sticon\n",
fbfont->width, fbfont->height, fbfont->name);
bpc = ((fbfont->width+7)/8) * fbfont->height;
size = bpc * 256;
size += sizeof(struct sti_rom_font);
nf = kzalloc(size, STI_LOWMEM);
if (!nf)
return NULL;
nf->first_char = 0;
nf->last_char = 255;
nf->width = fbfont->width;
nf->height = fbfont->height;
nf->font_type = STI_FONT_HPROMAN8;
nf->bytes_per_char = bpc;
nf->next_font = 0;
nf->underline_height = 1;
nf->underline_pos = fbfont->height - nf->underline_height;
dest = nf;
dest += sizeof(struct sti_rom_font);
memcpy(dest, fbfont->data, bpc*256);
cooked_font = kzalloc(sizeof(*cooked_font), GFP_KERNEL);
if (!cooked_font) {
kfree(nf);
return NULL;
}
cooked_font->raw = nf;
cooked_font->next_font = NULL;
cooked_rom->font_start = cooked_font;
return cooked_font;
}
static struct sti_cooked_font *
sti_select_fbfont(struct sti_cooked_rom *cooked_rom, const char *fbfont_name)
{
return NULL;
}
static struct sti_cooked_font *sti_select_font(struct sti_cooked_rom *rom,
int (*search_font_fnc)(struct sti_cooked_rom *, int, int))
{
struct sti_cooked_font *font;
int i;
int index = num_sti_roms;
if ((font = sti_select_fbfont(rom, font_name[index])))
return font;
if (font_width[index] && font_height[index])
font_index[index] = search_font_fnc(rom,
font_height[index], font_width[index]);
for (font = rom->font_start, i = font_index[index];
font && (i > 0);
font = font->next_font, i--);
if (font)
return font;
else
return rom->font_start;
}
static void sti_dump_rom(struct sti_rom *rom)
{
printk(KERN_INFO " id %04x-%04x, conforms to spec rev. %d.%02x\n",
rom->graphics_id[0],
rom->graphics_id[1],
rom->revno[0] >> 4,
rom->revno[0] & 0x0f);
DPRINTK((" supports %d monitors\n", rom->num_mons));
DPRINTK((" font start %08x\n", rom->font_start));
DPRINTK((" region list %08x\n", rom->region_list));
DPRINTK((" init_graph %08x\n", rom->init_graph));
DPRINTK((" bus support %02x\n", rom->bus_support));
DPRINTK((" ext bus support %02x\n", rom->ext_bus_support));
DPRINTK((" alternate code type %d\n", rom->alt_code_type));
}
static int sti_cook_fonts(struct sti_cooked_rom *cooked_rom,
struct sti_rom *raw_rom)
{
struct sti_rom_font *raw_font, *font_start;
struct sti_cooked_font *cooked_font;
cooked_font = kzalloc(sizeof(*cooked_font), GFP_KERNEL);
if (!cooked_font)
return 0;
cooked_rom->font_start = cooked_font;
raw_font = ((void *)raw_rom) + (raw_rom->font_start);
font_start = raw_font;
cooked_font->raw = raw_font;
while (raw_font->next_font) {
raw_font = ((void *)font_start) + (raw_font->next_font);
cooked_font->next_font = kzalloc(sizeof(*cooked_font), GFP_KERNEL);
if (!cooked_font->next_font)
return 1;
cooked_font = cooked_font->next_font;
cooked_font->raw = raw_font;
}
cooked_font->next_font = NULL;
return 1;
}
static int sti_search_font(struct sti_cooked_rom *rom, int height, int width)
{
struct sti_cooked_font *font;
int i = 0;
for (font = rom->font_start; font; font = font->next_font, i++) {
if ((font->raw->width == width) &&
(font->raw->height == height))
return i;
}
return 0;
}
static void *sti_bmode_font_raw(struct sti_cooked_font *f)
{
unsigned char *n, *p, *q;
int size = f->raw->bytes_per_char*256+sizeof(struct sti_rom_font);
n = kzalloc(4*size, STI_LOWMEM);
if (!n)
return NULL;
p = n + 3;
q = (unsigned char *)f->raw;
while (size--) {
*p = *q++;
p+=4;
}
return n + 3;
}
static void sti_bmode_rom_copy(unsigned long base, unsigned long count,
void *dest)
{
unsigned long dest_start = (unsigned long) dest;
while (count) {
count--;
*(u8 *)dest = gsc_readl(base);
base += 4;
dest++;
}
sti_flush(dest_start, (unsigned long)dest);
}
static struct sti_rom *sti_get_bmode_rom (unsigned long address)
{
struct sti_rom *raw;
u32 size;
struct sti_rom_font *raw_font, *font_start;
sti_bmode_rom_copy(address + BMODE_LAST_ADDR_OFFS, sizeof(size), &size);
size = (size+3) / 4;
raw = kmalloc(size, STI_LOWMEM);
if (raw) {
sti_bmode_rom_copy(address, size, raw);
memmove (&raw->res004, &raw->type[0], 0x3c);
raw->type[3] = raw->res004;
BMODE_RELOCATE (raw->region_list);
BMODE_RELOCATE (raw->font_start);
BMODE_RELOCATE (raw->init_graph);
BMODE_RELOCATE (raw->state_mgmt);
BMODE_RELOCATE (raw->font_unpmv);
BMODE_RELOCATE (raw->block_move);
BMODE_RELOCATE (raw->inq_conf);
raw_font = ((void *)raw) + raw->font_start;
font_start = raw_font;
while (raw_font->next_font) {
BMODE_RELOCATE (raw_font->next_font);
raw_font = ((void *)font_start) + raw_font->next_font;
}
}
return raw;
}
static struct sti_rom *sti_get_wmode_rom(unsigned long address)
{
struct sti_rom *raw;
unsigned long size;
size = gsc_readl(address + offsetof(struct sti_rom,last_addr));
raw = kmalloc(size, STI_LOWMEM);
if (raw)
sti_rom_copy(address, size, raw);
return raw;
}
static int sti_read_rom(int wordmode, struct sti_struct *sti,
unsigned long address)
{
struct sti_cooked_rom *cooked;
struct sti_rom *raw = NULL;
unsigned long revno;
cooked = kmalloc(sizeof *cooked, GFP_KERNEL);
if (!cooked)
goto out_err;
if (wordmode)
raw = sti_get_wmode_rom (address);
else
raw = sti_get_bmode_rom (address);
if (!raw)
goto out_err;
if (!sti_cook_fonts(cooked, raw)) {
printk(KERN_ERR "No font found for STI at %08lx\n", address);
goto out_err;
}
if (raw->region_list)
memcpy(sti->regions, ((void *)raw)+raw->region_list, sizeof(sti->regions));
address = (unsigned long) STI_PTR(raw);
pr_info("STI ROM supports 32 %sbit firmware functions.\n",
raw->alt_code_type == ALT_CODE_TYPE_PA_RISC_64
? "and 64 " : "");
sti->font_unpmv = address + (raw->font_unpmv & 0x03ffffff);
sti->block_move = address + (raw->block_move & 0x03ffffff);
sti->init_graph = address + (raw->init_graph & 0x03ffffff);
sti->inq_conf = address + (raw->inq_conf & 0x03ffffff);
sti->rom = cooked;
sti->rom->raw = raw;
sti->font = sti_select_font(sti->rom, sti_search_font);
sti->font_width = sti->font->raw->width;
sti->font_height = sti->font->raw->height;
if (!wordmode)
sti->font->raw = sti_bmode_font_raw(sti->font);
sti->sti_mem_request = raw->sti_mem_req;
sti->graphics_id[0] = raw->graphics_id[0];
sti->graphics_id[1] = raw->graphics_id[1];
sti_dump_rom(raw);
if (wordmode || sti->graphics_id[1] != 0x09A02587)
goto ok;
revno = (raw->revno[0] << 8) | raw->revno[1];
switch (sti->graphics_id[0]) {
case S9000_ID_HCRX:
if (revno == 0x8408 || revno == 0x840b)
goto msg_not_supported;
break;
case CRT_ID_THUNDER:
if (revno == 0x8509)
goto msg_not_supported;
break;
case CRT_ID_THUNDER2:
if (revno == 0x850c)
goto msg_not_supported;
}
ok:
return 1;
msg_not_supported:
printk(KERN_ERR "Sorry, this GSC/STI card is not yet supported.\n");
printk(KERN_ERR "Please see http://parisc-linux.org/faq/"
"graphics-howto.html for more info.\n");
out_err:
kfree(raw);
kfree(cooked);
return 0;
}
static struct sti_struct *sti_try_rom_generic(unsigned long address,
unsigned long hpa,
struct pci_dev *pd)
{
struct sti_struct *sti;
int ok;
u32 sig;
if (num_sti_roms >= MAX_STI_ROMS) {
printk(KERN_WARNING "maximum number of STI ROMS reached !\n");
return NULL;
}
sti = kzalloc(sizeof(*sti), GFP_KERNEL);
if (!sti) {
printk(KERN_ERR "Not enough memory !\n");
return NULL;
}
spin_lock_init(&sti->lock);
test_rom:
if (pdc_add_valid(address))
goto out_err;
sig = gsc_readl(address);
if ((le32_to_cpu(sig)==0xaa55)) {
unsigned int i, rm_offset;
u32 *rm;
i = gsc_readl(address+0x04);
if (i != 1) {
printk(KERN_WARNING
"PCI ROM is not a STI ROM type image (0x%8x)\n", i);
goto out_err;
}
sti->pd = pd;
i = gsc_readl(address+0x0c);
DPRINTK(("PCI ROM size (from header) = %d kB\n",
le16_to_cpu(i>>16)*512/1024));
rm_offset = le16_to_cpu(i & 0xffff);
if (rm_offset) {
rm = (u32*) &sti->rm_entry;
*rm++ = gsc_readl(address+rm_offset+0x00);
*rm++ = gsc_readl(address+rm_offset+0x04);
*rm++ = gsc_readl(address+rm_offset+0x08);
*rm++ = gsc_readl(address+rm_offset+0x0c);
DPRINTK(("PCI region Mapper offset = %08x: ",
rm_offset));
for (i=0; i<16; i++)
DPRINTK(("%02x ", sti->rm_entry[i]));
DPRINTK(("\n"));
}
address += le32_to_cpu(gsc_readl(address+8));
DPRINTK(("sig %04x, PCI STI ROM at %08lx\n", sig, address));
goto test_rom;
}
ok = 0;
if ((sig & 0xff) == 0x01) {
DPRINTK((" byte mode ROM at %08lx, hpa at %08lx\n",
address, hpa));
ok = sti_read_rom(0, sti, address);
}
if ((sig & 0xffff) == 0x0303) {
DPRINTK((" word mode ROM at %08lx, hpa at %08lx\n",
address, hpa));
ok = sti_read_rom(1, sti, address);
}
if (!ok)
goto out_err;
if (sti_init_glob_cfg(sti, address, hpa))
goto out_err;
if (sti->pd) {
unsigned long rom_base;
rom_base = pci_resource_start(sti->pd, PCI_ROM_RESOURCE);
pci_write_config_dword(sti->pd, PCI_ROM_ADDRESS, rom_base & ~PCI_ROM_ADDRESS_ENABLE);
DPRINTK((KERN_DEBUG "STI PCI ROM disabled\n"));
}
if (sti_init_graph(sti))
goto out_err;
sti_inq_conf(sti);
sti_dump_globcfg(sti->glob_cfg, sti->sti_mem_request);
sti_dump_outptr(sti);
pr_info(" graphics card name: %s\n",
sti->sti_data->inq_outptr.dev_name);
sti_roms[num_sti_roms] = sti;
num_sti_roms++;
return sti;
out_err:
kfree(sti);
return NULL;
}
static void sticore_check_for_default_sti(struct sti_struct *sti, char *path)
{
if (strcmp (path, default_sti_path) == 0)
default_sti = sti;
}
static int sticore_pa_init(struct parisc_device *dev)
{
char pa_path[21];
struct sti_struct *sti = NULL;
int hpa = dev->hpa.start;
if (dev->num_addrs && dev->addr[0])
sti = sti_try_rom_generic(dev->addr[0], hpa, NULL);
if (!sti)
sti = sti_try_rom_generic(hpa, hpa, NULL);
if (!sti)
sti = sti_try_rom_generic(PAGE0->proc_sti, hpa, NULL);
if (!sti)
return 1;
print_pa_hwpath(dev, pa_path);
sticore_check_for_default_sti(sti, pa_path);
return 0;
}
static int sticore_pci_init(struct pci_dev *pd, const struct pci_device_id *ent)
{
#ifdef CONFIG_PCI
unsigned long fb_base, rom_base;
unsigned int fb_len, rom_len;
int err;
struct sti_struct *sti;
err = pci_enable_device(pd);
if (err < 0) {
dev_err(&pd->dev, "Cannot enable PCI device\n");
return err;
}
fb_base = pci_resource_start(pd, 0);
fb_len = pci_resource_len(pd, 0);
rom_base = pci_resource_start(pd, PCI_ROM_RESOURCE);
rom_len = pci_resource_len(pd, PCI_ROM_RESOURCE);
if (rom_base) {
pci_write_config_dword(pd, PCI_ROM_ADDRESS, rom_base | PCI_ROM_ADDRESS_ENABLE);
DPRINTK((KERN_DEBUG "STI PCI ROM enabled at 0x%08lx\n", rom_base));
}
printk(KERN_INFO "STI PCI graphic ROM found at %08lx (%u kB), fb at %08lx (%u MB)\n",
rom_base, rom_len/1024, fb_base, fb_len/1024/1024);
DPRINTK((KERN_DEBUG "Trying PCI STI ROM at %08lx, PCI hpa at %08lx\n",
rom_base, fb_base));
sti = sti_try_rom_generic(rom_base, fb_base, pd);
if (sti) {
char pa_path[30];
print_pci_hwpath(pd, pa_path);
sticore_check_for_default_sti(sti, pa_path);
}
if (!sti) {
printk(KERN_WARNING "Unable to handle STI device '%s'\n",
pci_name(pd));
return -ENODEV;
}
#endif
return 0;
}
static void sticore_pci_remove(struct pci_dev *pd)
{
BUG();
}
static void sti_init_roms(void)
{
if (sticore_initialized)
return;
sticore_initialized = 1;
printk(KERN_INFO "STI GSC/PCI core graphics driver "
STI_DRIVERVERSION "\n");
register_parisc_driver(&pa_sti_driver);
WARN_ON(pci_register_driver(&pci_sti_driver));
if (!default_sti)
default_sti = sti_roms[0];
}
struct sti_struct * sti_get_rom(unsigned int index)
{
if (!sticore_initialized)
sti_init_roms();
if (index == 0)
return default_sti;
if (index > num_sti_roms)
return NULL;
return sti_roms[index-1];
}
int sti_call(const struct sti_struct *sti, unsigned long func,
const void *flags, void *inptr, void *outptr,
struct sti_glob_cfg *glob_cfg)
{
unsigned long _flags = STI_PTR(flags);
unsigned long _inptr = STI_PTR(inptr);
unsigned long _outptr = STI_PTR(outptr);
unsigned long _glob_cfg = STI_PTR(glob_cfg);
int ret;
#ifdef CONFIG_64BIT
if (WARN_ONCE(_flags>>32 || _inptr>>32 || _outptr>>32 || _glob_cfg>>32,
"Out of 32bit-range pointers!"))
return -1;
#endif
ret = pdc_sti_call(func, _flags, _inptr, _outptr, _glob_cfg);
return ret;
}
