static int alloc_device(struct nandsim *ns)
{
struct file *cfile;
int i, err;
if (cache_file) {
cfile = filp_open(cache_file, O_CREAT | O_RDWR | O_LARGEFILE, 0600);
if (IS_ERR(cfile))
return PTR_ERR(cfile);
if (!cfile->f_op || (!cfile->f_op->read && !cfile->f_op->aio_read)) {
NS_ERR("alloc_device: cache file not readable\n");
err = -EINVAL;
goto err_close;
}
if (!cfile->f_op->write && !cfile->f_op->aio_write) {
NS_ERR("alloc_device: cache file not writeable\n");
err = -EINVAL;
goto err_close;
}
ns->pages_written = vzalloc(ns->geom.pgnum);
if (!ns->pages_written) {
NS_ERR("alloc_device: unable to allocate pages written array\n");
err = -ENOMEM;
goto err_close;
}
ns->file_buf = kmalloc(ns->geom.pgszoob, GFP_KERNEL);
if (!ns->file_buf) {
NS_ERR("alloc_device: unable to allocate file buf\n");
err = -ENOMEM;
goto err_free;
}
ns->cfile = cfile;
return 0;
}
ns->pages = vmalloc(ns->geom.pgnum * sizeof(union ns_mem));
if (!ns->pages) {
NS_ERR("alloc_device: unable to allocate page array\n");
return -ENOMEM;
}
for (i = 0; i < ns->geom.pgnum; i++) {
ns->pages[i].byte = NULL;
}
ns->nand_pages_slab = kmem_cache_create("nandsim",
ns->geom.pgszoob, 0, 0, NULL);
if (!ns->nand_pages_slab) {
NS_ERR("cache_create: unable to create kmem_cache\n");
return -ENOMEM;
}
return 0;
err_free:
vfree(ns->pages_written);
err_close:
filp_close(cfile, NULL);
return err;
}
static void free_device(struct nandsim *ns)
{
int i;
if (ns->cfile) {
kfree(ns->file_buf);
vfree(ns->pages_written);
filp_close(ns->cfile, NULL);
return;
}
if (ns->pages) {
for (i = 0; i < ns->geom.pgnum; i++) {
if (ns->pages[i].byte)
kmem_cache_free(ns->nand_pages_slab,
ns->pages[i].byte);
}
kmem_cache_destroy(ns->nand_pages_slab);
vfree(ns->pages);
}
}
static char *get_partition_name(int i)
{
char buf[64];
sprintf(buf, "NAND simulator partition %d", i);
return kstrdup(buf, GFP_KERNEL);
}
static uint64_t divide(uint64_t n, uint32_t d)
{
do_div(n, d);
return n;
}
static int init_nandsim(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct nandsim *ns = chip->priv;
int i, ret = 0;
uint64_t remains;
uint64_t next_offset;
if (NS_IS_INITIALIZED(ns)) {
NS_ERR("init_nandsim: nandsim is already initialized\n");
return -EIO;
}
chip->chip_delay = 0;
ns->busw = chip->options & NAND_BUSWIDTH_16 ? 16 : 8;
ns->geom.totsz = mtd->size;
ns->geom.pgsz = mtd->writesize;
ns->geom.oobsz = mtd->oobsize;
ns->geom.secsz = mtd->erasesize;
ns->geom.pgszoob = ns->geom.pgsz + ns->geom.oobsz;
ns->geom.pgnum = divide(ns->geom.totsz, ns->geom.pgsz);
ns->geom.totszoob = ns->geom.totsz + (uint64_t)ns->geom.pgnum * ns->geom.oobsz;
ns->geom.secshift = ffs(ns->geom.secsz) - 1;
ns->geom.pgshift = chip->page_shift;
ns->geom.oobshift = ffs(ns->geom.oobsz) - 1;
ns->geom.pgsec = ns->geom.secsz / ns->geom.pgsz;
ns->geom.secszoob = ns->geom.secsz + ns->geom.oobsz * ns->geom.pgsec;
ns->options = 0;
if (ns->geom.pgsz == 256) {
ns->options |= OPT_PAGE256;
}
else if (ns->geom.pgsz == 512) {
ns->options |= (OPT_PAGE512 | OPT_AUTOINCR);
if (ns->busw == 8)
ns->options |= OPT_PAGE512_8BIT;
} else if (ns->geom.pgsz == 2048) {
ns->options |= OPT_PAGE2048;
} else if (ns->geom.pgsz == 4096) {
ns->options |= OPT_PAGE4096;
} else {
NS_ERR("init_nandsim: unknown page size %u\n", ns->geom.pgsz);
return -EIO;
}
if (ns->options & OPT_SMALLPAGE) {
if (ns->geom.totsz <= (32 << 20)) {
ns->geom.pgaddrbytes = 3;
ns->geom.secaddrbytes = 2;
} else {
ns->geom.pgaddrbytes = 4;
ns->geom.secaddrbytes = 3;
}
} else {
if (ns->geom.totsz <= (128 << 20)) {
ns->geom.pgaddrbytes = 4;
ns->geom.secaddrbytes = 2;
} else {
ns->geom.pgaddrbytes = 5;
ns->geom.secaddrbytes = 3;
}
}
if (parts_num > ARRAY_SIZE(ns->partitions)) {
NS_ERR("too many partitions.\n");
ret = -EINVAL;
goto error;
}
remains = ns->geom.totsz;
next_offset = 0;
for (i = 0; i < parts_num; ++i) {
uint64_t part_sz = (uint64_t)parts[i] * ns->geom.secsz;
if (!part_sz || part_sz > remains) {
NS_ERR("bad partition size.\n");
ret = -EINVAL;
goto error;
}
ns->partitions[i].name = get_partition_name(i);
ns->partitions[i].offset = next_offset;
ns->partitions[i].size = part_sz;
next_offset += ns->partitions[i].size;
remains -= ns->partitions[i].size;
}
ns->nbparts = parts_num;
if (remains) {
if (parts_num + 1 > ARRAY_SIZE(ns->partitions)) {
NS_ERR("too many partitions.\n");
ret = -EINVAL;
goto error;
}
ns->partitions[i].name = get_partition_name(i);
ns->partitions[i].offset = next_offset;
ns->partitions[i].size = remains;
ns->nbparts += 1;
}
for (i = 0; nand_flash_ids[i].name != NULL; i++) {
if (second_id_byte != nand_flash_ids[i].id)
continue;
if (!(nand_flash_ids[i].options & NAND_NO_AUTOINCR))
ns->options |= OPT_AUTOINCR;
}
if (ns->busw == 16)
NS_WARN("16-bit flashes support wasn't tested\n");
printk("flash size: %llu MiB\n",
(unsigned long long)ns->geom.totsz >> 20);
printk("page size: %u bytes\n", ns->geom.pgsz);
printk("OOB area size: %u bytes\n", ns->geom.oobsz);
printk("sector size: %u KiB\n", ns->geom.secsz >> 10);
printk("pages number: %u\n", ns->geom.pgnum);
printk("pages per sector: %u\n", ns->geom.pgsec);
printk("bus width: %u\n", ns->busw);
printk("bits in sector size: %u\n", ns->geom.secshift);
printk("bits in page size: %u\n", ns->geom.pgshift);
printk("bits in OOB size: %u\n", ns->geom.oobshift);
printk("flash size with OOB: %llu KiB\n",
(unsigned long long)ns->geom.totszoob >> 10);
printk("page address bytes: %u\n", ns->geom.pgaddrbytes);
printk("sector address bytes: %u\n", ns->geom.secaddrbytes);
printk("options: %#x\n", ns->options);
if ((ret = alloc_device(ns)) != 0)
goto error;
ns->buf.byte = kmalloc(ns->geom.pgszoob, GFP_KERNEL);
if (!ns->buf.byte) {
NS_ERR("init_nandsim: unable to allocate %u bytes for the internal buffer\n",
ns->geom.pgszoob);
ret = -ENOMEM;
goto error;
}
memset(ns->buf.byte, 0xFF, ns->geom.pgszoob);
return 0;
error:
free_device(ns);
return ret;
}
static void free_nandsim(struct nandsim *ns)
{
kfree(ns->buf.byte);
free_device(ns);
return;
}
static int parse_badblocks(struct nandsim *ns, struct mtd_info *mtd)
{
char *w;
int zero_ok;
unsigned int erase_block_no;
loff_t offset;
if (!badblocks)
return 0;
w = badblocks;
do {
zero_ok = (*w == '0' ? 1 : 0);
erase_block_no = simple_strtoul(w, &w, 0);
if (!zero_ok && !erase_block_no) {
NS_ERR("invalid badblocks.\n");
return -EINVAL;
}
offset = erase_block_no * ns->geom.secsz;
if (mtd->block_markbad(mtd, offset)) {
NS_ERR("invalid badblocks.\n");
return -EINVAL;
}
if (*w == ',')
w += 1;
} while (*w);
return 0;
}
static int parse_weakblocks(void)
{
char *w;
int zero_ok;
unsigned int erase_block_no;
unsigned int max_erases;
struct weak_block *wb;
if (!weakblocks)
return 0;
w = weakblocks;
do {
zero_ok = (*w == '0' ? 1 : 0);
erase_block_no = simple_strtoul(w, &w, 0);
if (!zero_ok && !erase_block_no) {
NS_ERR("invalid weakblocks.\n");
return -EINVAL;
}
max_erases = 3;
if (*w == ':') {
w += 1;
max_erases = simple_strtoul(w, &w, 0);
}
if (*w == ',')
w += 1;
wb = kzalloc(sizeof(*wb), GFP_KERNEL);
if (!wb) {
NS_ERR("unable to allocate memory.\n");
return -ENOMEM;
}
wb->erase_block_no = erase_block_no;
wb->max_erases = max_erases;
list_add(&wb->list, &weak_blocks);
} while (*w);
return 0;
}
static int erase_error(unsigned int erase_block_no)
{
struct weak_block *wb;
list_for_each_entry(wb, &weak_blocks, list)
if (wb->erase_block_no == erase_block_no) {
if (wb->erases_done >= wb->max_erases)
return 1;
wb->erases_done += 1;
return 0;
}
return 0;
}
static int parse_weakpages(void)
{
char *w;
int zero_ok;
unsigned int page_no;
unsigned int max_writes;
struct weak_page *wp;
if (!weakpages)
return 0;
w = weakpages;
do {
zero_ok = (*w == '0' ? 1 : 0);
page_no = simple_strtoul(w, &w, 0);
if (!zero_ok && !page_no) {
NS_ERR("invalid weakpagess.\n");
return -EINVAL;
}
max_writes = 3;
if (*w == ':') {
w += 1;
max_writes = simple_strtoul(w, &w, 0);
}
if (*w == ',')
w += 1;
wp = kzalloc(sizeof(*wp), GFP_KERNEL);
if (!wp) {
NS_ERR("unable to allocate memory.\n");
return -ENOMEM;
}
wp->page_no = page_no;
wp->max_writes = max_writes;
list_add(&wp->list, &weak_pages);
} while (*w);
return 0;
}
static int write_error(unsigned int page_no)
{
struct weak_page *wp;
list_for_each_entry(wp, &weak_pages, list)
if (wp->page_no == page_no) {
if (wp->writes_done >= wp->max_writes)
return 1;
wp->writes_done += 1;
return 0;
}
return 0;
}
static int parse_gravepages(void)
{
char *g;
int zero_ok;
unsigned int page_no;
unsigned int max_reads;
struct grave_page *gp;
if (!gravepages)
return 0;
g = gravepages;
do {
zero_ok = (*g == '0' ? 1 : 0);
page_no = simple_strtoul(g, &g, 0);
if (!zero_ok && !page_no) {
NS_ERR("invalid gravepagess.\n");
return -EINVAL;
}
max_reads = 3;
if (*g == ':') {
g += 1;
max_reads = simple_strtoul(g, &g, 0);
}
if (*g == ',')
g += 1;
gp = kzalloc(sizeof(*gp), GFP_KERNEL);
if (!gp) {
NS_ERR("unable to allocate memory.\n");
return -ENOMEM;
}
gp->page_no = page_no;
gp->max_reads = max_reads;
list_add(&gp->list, &grave_pages);
} while (*g);
return 0;
}
static int read_error(unsigned int page_no)
{
struct grave_page *gp;
list_for_each_entry(gp, &grave_pages, list)
if (gp->page_no == page_no) {
if (gp->reads_done >= gp->max_reads)
return 1;
gp->reads_done += 1;
return 0;
}
return 0;
}
static void free_lists(void)
{
struct list_head *pos, *n;
list_for_each_safe(pos, n, &weak_blocks) {
list_del(pos);
kfree(list_entry(pos, struct weak_block, list));
}
list_for_each_safe(pos, n, &weak_pages) {
list_del(pos);
kfree(list_entry(pos, struct weak_page, list));
}
list_for_each_safe(pos, n, &grave_pages) {
list_del(pos);
kfree(list_entry(pos, struct grave_page, list));
}
kfree(erase_block_wear);
}
static int setup_wear_reporting(struct mtd_info *mtd)
{
size_t mem;
if (!rptwear)
return 0;
wear_eb_count = divide(mtd->size, mtd->erasesize);
mem = wear_eb_count * sizeof(unsigned long);
if (mem / sizeof(unsigned long) != wear_eb_count) {
NS_ERR("Too many erase blocks for wear reporting\n");
return -ENOMEM;
}
erase_block_wear = kzalloc(mem, GFP_KERNEL);
if (!erase_block_wear) {
NS_ERR("Too many erase blocks for wear reporting\n");
return -ENOMEM;
}
return 0;
}
static void update_wear(unsigned int erase_block_no)
{
unsigned long wmin = -1, wmax = 0, avg;
unsigned long deciles[10], decile_max[10], tot = 0;
unsigned int i;
if (!erase_block_wear)
return;
total_wear += 1;
if (total_wear == 0)
NS_ERR("Erase counter total overflow\n");
erase_block_wear[erase_block_no] += 1;
if (erase_block_wear[erase_block_no] == 0)
NS_ERR("Erase counter overflow for erase block %u\n", erase_block_no);
rptwear_cnt += 1;
if (rptwear_cnt < rptwear)
return;
rptwear_cnt = 0;
for (i = 0; i < wear_eb_count; ++i) {
unsigned long wear = erase_block_wear[i];
if (wear < wmin)
wmin = wear;
if (wear > wmax)
wmax = wear;
tot += wear;
}
for (i = 0; i < 9; ++i) {
deciles[i] = 0;
decile_max[i] = (wmax * (i + 1) + 5) / 10;
}
deciles[9] = 0;
decile_max[9] = wmax;
for (i = 0; i < wear_eb_count; ++i) {
int d;
unsigned long wear = erase_block_wear[i];
for (d = 0; d < 10; ++d)
if (wear <= decile_max[d]) {
deciles[d] += 1;
break;
}
}
avg = tot / wear_eb_count;
NS_INFO("*** Wear Report ***\n");
NS_INFO("Total numbers of erases: %lu\n", tot);
NS_INFO("Number of erase blocks: %u\n", wear_eb_count);
NS_INFO("Average number of erases: %lu\n", avg);
NS_INFO("Maximum number of erases: %lu\n", wmax);
NS_INFO("Minimum number of erases: %lu\n", wmin);
for (i = 0; i < 10; ++i) {
unsigned long from = (i ? decile_max[i - 1] + 1 : 0);
if (from > decile_max[i])
continue;
NS_INFO("Number of ebs with erase counts from %lu to %lu : %lu\n",
from,
decile_max[i],
deciles[i]);
}
NS_INFO("*** End of Wear Report ***\n");
}
static char *get_state_name(uint32_t state)
{
switch (NS_STATE(state)) {
case STATE_CMD_READ0:
return "STATE_CMD_READ0";
case STATE_CMD_READ1:
return "STATE_CMD_READ1";
case STATE_CMD_PAGEPROG:
return "STATE_CMD_PAGEPROG";
case STATE_CMD_READOOB:
return "STATE_CMD_READOOB";
case STATE_CMD_READSTART:
return "STATE_CMD_READSTART";
case STATE_CMD_ERASE1:
return "STATE_CMD_ERASE1";
case STATE_CMD_STATUS:
return "STATE_CMD_STATUS";
case STATE_CMD_STATUS_M:
return "STATE_CMD_STATUS_M";
case STATE_CMD_SEQIN:
return "STATE_CMD_SEQIN";
case STATE_CMD_READID:
return "STATE_CMD_READID";
case STATE_CMD_ERASE2:
return "STATE_CMD_ERASE2";
case STATE_CMD_RESET:
return "STATE_CMD_RESET";
case STATE_CMD_RNDOUT:
return "STATE_CMD_RNDOUT";
case STATE_CMD_RNDOUTSTART:
return "STATE_CMD_RNDOUTSTART";
case STATE_ADDR_PAGE:
return "STATE_ADDR_PAGE";
case STATE_ADDR_SEC:
return "STATE_ADDR_SEC";
case STATE_ADDR_ZERO:
return "STATE_ADDR_ZERO";
case STATE_ADDR_COLUMN:
return "STATE_ADDR_COLUMN";
case STATE_DATAIN:
return "STATE_DATAIN";
case STATE_DATAOUT:
return "STATE_DATAOUT";
case STATE_DATAOUT_ID:
return "STATE_DATAOUT_ID";
case STATE_DATAOUT_STATUS:
return "STATE_DATAOUT_STATUS";
case STATE_DATAOUT_STATUS_M:
return "STATE_DATAOUT_STATUS_M";
case STATE_READY:
return "STATE_READY";
case STATE_UNKNOWN:
return "STATE_UNKNOWN";
}
NS_ERR("get_state_name: unknown state, BUG\n");
return NULL;
}
static int check_command(int cmd)
{
switch (cmd) {
case NAND_CMD_READ0:
case NAND_CMD_READ1:
case NAND_CMD_READSTART:
case NAND_CMD_PAGEPROG:
case NAND_CMD_READOOB:
case NAND_CMD_ERASE1:
case NAND_CMD_STATUS:
case NAND_CMD_SEQIN:
case NAND_CMD_READID:
case NAND_CMD_ERASE2:
case NAND_CMD_RESET:
case NAND_CMD_RNDOUT:
case NAND_CMD_RNDOUTSTART:
return 0;
case NAND_CMD_STATUS_MULTI:
default:
return 1;
}
}
static uint32_t get_state_by_command(unsigned command)
{
switch (command) {
case NAND_CMD_READ0:
return STATE_CMD_READ0;
case NAND_CMD_READ1:
return STATE_CMD_READ1;
case NAND_CMD_PAGEPROG:
return STATE_CMD_PAGEPROG;
case NAND_CMD_READSTART:
return STATE_CMD_READSTART;
case NAND_CMD_READOOB:
return STATE_CMD_READOOB;
case NAND_CMD_ERASE1:
return STATE_CMD_ERASE1;
case NAND_CMD_STATUS:
return STATE_CMD_STATUS;
case NAND_CMD_STATUS_MULTI:
return STATE_CMD_STATUS_M;
case NAND_CMD_SEQIN:
return STATE_CMD_SEQIN;
case NAND_CMD_READID:
return STATE_CMD_READID;
case NAND_CMD_ERASE2:
return STATE_CMD_ERASE2;
case NAND_CMD_RESET:
return STATE_CMD_RESET;
case NAND_CMD_RNDOUT:
return STATE_CMD_RNDOUT;
case NAND_CMD_RNDOUTSTART:
return STATE_CMD_RNDOUTSTART;
}
NS_ERR("get_state_by_command: unknown command, BUG\n");
return 0;
}
static inline void accept_addr_byte(struct nandsim *ns, u_char bt)
{
uint byte = (uint)bt;
if (ns->regs.count < (ns->geom.pgaddrbytes - ns->geom.secaddrbytes))
ns->regs.column |= (byte << 8 * ns->regs.count);
else {
ns->regs.row |= (byte << 8 * (ns->regs.count -
ns->geom.pgaddrbytes +
ns->geom.secaddrbytes));
}
return;
}
static inline void switch_to_ready_state(struct nandsim *ns, u_char status)
{
NS_DBG("switch_to_ready_state: switch to %s state\n", get_state_name(STATE_READY));
ns->state = STATE_READY;
ns->nxstate = STATE_UNKNOWN;
ns->op = NULL;
ns->npstates = 0;
ns->stateidx = 0;
ns->regs.num = 0;
ns->regs.count = 0;
ns->regs.off = 0;
ns->regs.row = 0;
ns->regs.column = 0;
ns->regs.status = status;
}
static int find_operation(struct nandsim *ns, uint32_t flag)
{
int opsfound = 0;
int i, j, idx = 0;
for (i = 0; i < NS_OPER_NUM; i++) {
int found = 1;
if (!(ns->options & ops[i].reqopts))
continue;
if (flag) {
if (!(ops[i].states[ns->npstates] & STATE_ADDR_MASK))
continue;
} else {
if (NS_STATE(ns->state) != NS_STATE(ops[i].states[ns->npstates]))
continue;
}
for (j = 0; j < ns->npstates; j++)
if (NS_STATE(ops[i].states[j]) != NS_STATE(ns->pstates[j])
&& (ns->options & ops[idx].reqopts)) {
found = 0;
break;
}
if (found) {
idx = i;
opsfound += 1;
}
}
if (opsfound == 1) {
ns->op = &ops[idx].states[0];
if (flag) {
ns->stateidx = ns->npstates - 1;
} else {
ns->stateidx = ns->npstates;
}
ns->npstates = 0;
ns->state = ns->op[ns->stateidx];
ns->nxstate = ns->op[ns->stateidx + 1];
NS_DBG("find_operation: operation found, index: %d, state: %s, nxstate %s\n",
idx, get_state_name(ns->state), get_state_name(ns->nxstate));
return 0;
}
if (opsfound == 0) {
if (ns->npstates != 0) {
NS_DBG("find_operation: no operation found, try again with state %s\n",
get_state_name(ns->state));
ns->npstates = 0;
return find_operation(ns, 0);
}
NS_DBG("find_operation: no operations found\n");
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return -2;
}
if (flag) {
NS_DBG("find_operation: BUG, operation must be known if address is input\n");
return -2;
}
NS_DBG("find_operation: there is still ambiguity\n");
ns->pstates[ns->npstates++] = ns->state;
return -1;
}
static void put_pages(struct nandsim *ns)
{
int i;
for (i = 0; i < ns->held_cnt; i++)
page_cache_release(ns->held_pages[i]);
}
static int get_pages(struct nandsim *ns, struct file *file, size_t count, loff_t pos)
{
pgoff_t index, start_index, end_index;
struct page *page;
struct address_space *mapping = file->f_mapping;
start_index = pos >> PAGE_CACHE_SHIFT;
end_index = (pos + count - 1) >> PAGE_CACHE_SHIFT;
if (end_index - start_index + 1 > NS_MAX_HELD_PAGES)
return -EINVAL;
ns->held_cnt = 0;
for (index = start_index; index <= end_index; index++) {
page = find_get_page(mapping, index);
if (page == NULL) {
page = find_or_create_page(mapping, index, GFP_NOFS);
if (page == NULL) {
write_inode_now(mapping->host, 1);
page = find_or_create_page(mapping, index, GFP_NOFS);
}
if (page == NULL) {
put_pages(ns);
return -ENOMEM;
}
unlock_page(page);
}
ns->held_pages[ns->held_cnt++] = page;
}
return 0;
}
static int set_memalloc(void)
{
if (current->flags & PF_MEMALLOC)
return 0;
current->flags |= PF_MEMALLOC;
return 1;
}
static void clear_memalloc(int memalloc)
{
if (memalloc)
current->flags &= ~PF_MEMALLOC;
}
static ssize_t read_file(struct nandsim *ns, struct file *file, void *buf, size_t count, loff_t *pos)
{
mm_segment_t old_fs;
ssize_t tx;
int err, memalloc;
err = get_pages(ns, file, count, *pos);
if (err)
return err;
old_fs = get_fs();
set_fs(get_ds());
memalloc = set_memalloc();
tx = vfs_read(file, (char __user *)buf, count, pos);
clear_memalloc(memalloc);
set_fs(old_fs);
put_pages(ns);
return tx;
}
static ssize_t write_file(struct nandsim *ns, struct file *file, void *buf, size_t count, loff_t *pos)
{
mm_segment_t old_fs;
ssize_t tx;
int err, memalloc;
err = get_pages(ns, file, count, *pos);
if (err)
return err;
old_fs = get_fs();
set_fs(get_ds());
memalloc = set_memalloc();
tx = vfs_write(file, (char __user *)buf, count, pos);
clear_memalloc(memalloc);
set_fs(old_fs);
put_pages(ns);
return tx;
}
static inline union ns_mem *NS_GET_PAGE(struct nandsim *ns)
{
return &(ns->pages[ns->regs.row]);
}
static inline u_char *NS_PAGE_BYTE_OFF(struct nandsim *ns)
{
return NS_GET_PAGE(ns)->byte + ns->regs.column + ns->regs.off;
}
int do_read_error(struct nandsim *ns, int num)
{
unsigned int page_no = ns->regs.row;
if (read_error(page_no)) {
int i;
memset(ns->buf.byte, 0xFF, num);
for (i = 0; i < num; ++i)
ns->buf.byte[i] = random32();
NS_WARN("simulating read error in page %u\n", page_no);
return 1;
}
return 0;
}
void do_bit_flips(struct nandsim *ns, int num)
{
if (bitflips && random32() < (1 << 22)) {
int flips = 1;
if (bitflips > 1)
flips = (random32() % (int) bitflips) + 1;
while (flips--) {
int pos = random32() % (num * 8);
ns->buf.byte[pos / 8] ^= (1 << (pos % 8));
NS_WARN("read_page: flipping bit %d in page %d "
"reading from %d ecc: corrected=%u failed=%u\n",
pos, ns->regs.row, ns->regs.column + ns->regs.off,
nsmtd->ecc_stats.corrected, nsmtd->ecc_stats.failed);
}
}
}
static void read_page(struct nandsim *ns, int num)
{
union ns_mem *mypage;
if (ns->cfile) {
if (!ns->pages_written[ns->regs.row]) {
NS_DBG("read_page: page %d not written\n", ns->regs.row);
memset(ns->buf.byte, 0xFF, num);
} else {
loff_t pos;
ssize_t tx;
NS_DBG("read_page: page %d written, reading from %d\n",
ns->regs.row, ns->regs.column + ns->regs.off);
if (do_read_error(ns, num))
return;
pos = (loff_t)ns->regs.row * ns->geom.pgszoob + ns->regs.column + ns->regs.off;
tx = read_file(ns, ns->cfile, ns->buf.byte, num, &pos);
if (tx != num) {
NS_ERR("read_page: read error for page %d ret %ld\n", ns->regs.row, (long)tx);
return;
}
do_bit_flips(ns, num);
}
return;
}
mypage = NS_GET_PAGE(ns);
if (mypage->byte == NULL) {
NS_DBG("read_page: page %d not allocated\n", ns->regs.row);
memset(ns->buf.byte, 0xFF, num);
} else {
NS_DBG("read_page: page %d allocated, reading from %d\n",
ns->regs.row, ns->regs.column + ns->regs.off);
if (do_read_error(ns, num))
return;
memcpy(ns->buf.byte, NS_PAGE_BYTE_OFF(ns), num);
do_bit_flips(ns, num);
}
}
static void erase_sector(struct nandsim *ns)
{
union ns_mem *mypage;
int i;
if (ns->cfile) {
for (i = 0; i < ns->geom.pgsec; i++)
if (ns->pages_written[ns->regs.row + i]) {
NS_DBG("erase_sector: freeing page %d\n", ns->regs.row + i);
ns->pages_written[ns->regs.row + i] = 0;
}
return;
}
mypage = NS_GET_PAGE(ns);
for (i = 0; i < ns->geom.pgsec; i++) {
if (mypage->byte != NULL) {
NS_DBG("erase_sector: freeing page %d\n", ns->regs.row+i);
kmem_cache_free(ns->nand_pages_slab, mypage->byte);
mypage->byte = NULL;
}
mypage++;
}
}
static int prog_page(struct nandsim *ns, int num)
{
int i;
union ns_mem *mypage;
u_char *pg_off;
if (ns->cfile) {
loff_t off, pos;
ssize_t tx;
int all;
NS_DBG("prog_page: writing page %d\n", ns->regs.row);
pg_off = ns->file_buf + ns->regs.column + ns->regs.off;
off = (loff_t)ns->regs.row * ns->geom.pgszoob + ns->regs.column + ns->regs.off;
if (!ns->pages_written[ns->regs.row]) {
all = 1;
memset(ns->file_buf, 0xff, ns->geom.pgszoob);
} else {
all = 0;
pos = off;
tx = read_file(ns, ns->cfile, pg_off, num, &pos);
if (tx != num) {
NS_ERR("prog_page: read error for page %d ret %ld\n", ns->regs.row, (long)tx);
return -1;
}
}
for (i = 0; i < num; i++)
pg_off[i] &= ns->buf.byte[i];
if (all) {
pos = (loff_t)ns->regs.row * ns->geom.pgszoob;
tx = write_file(ns, ns->cfile, ns->file_buf, ns->geom.pgszoob, &pos);
if (tx != ns->geom.pgszoob) {
NS_ERR("prog_page: write error for page %d ret %ld\n", ns->regs.row, (long)tx);
return -1;
}
ns->pages_written[ns->regs.row] = 1;
} else {
pos = off;
tx = write_file(ns, ns->cfile, pg_off, num, &pos);
if (tx != num) {
NS_ERR("prog_page: write error for page %d ret %ld\n", ns->regs.row, (long)tx);
return -1;
}
}
return 0;
}
mypage = NS_GET_PAGE(ns);
if (mypage->byte == NULL) {
NS_DBG("prog_page: allocating page %d\n", ns->regs.row);
mypage->byte = kmem_cache_alloc(ns->nand_pages_slab, GFP_NOFS);
if (mypage->byte == NULL) {
NS_ERR("prog_page: error allocating memory for page %d\n", ns->regs.row);
return -1;
}
memset(mypage->byte, 0xFF, ns->geom.pgszoob);
}
pg_off = NS_PAGE_BYTE_OFF(ns);
for (i = 0; i < num; i++)
pg_off[i] &= ns->buf.byte[i];
return 0;
}
static int do_state_action(struct nandsim *ns, uint32_t action)
{
int num;
int busdiv = ns->busw == 8 ? 1 : 2;
unsigned int erase_block_no, page_no;
action &= ACTION_MASK;
if (action != ACTION_SECERASE && ns->regs.row >= ns->geom.pgnum) {
NS_WARN("do_state_action: wrong page number (%#x)\n", ns->regs.row);
return -1;
}
switch (action) {
case ACTION_CPY:
if (ns->regs.column >= (ns->geom.pgszoob - ns->regs.off)) {
NS_ERR("do_state_action: column number is too large\n");
break;
}
num = ns->geom.pgszoob - ns->regs.off - ns->regs.column;
read_page(ns, num);
NS_DBG("do_state_action: (ACTION_CPY:) copy %d bytes to int buf, raw offset %d\n",
num, NS_RAW_OFFSET(ns) + ns->regs.off);
if (ns->regs.off == 0)
NS_LOG("read page %d\n", ns->regs.row);
else if (ns->regs.off < ns->geom.pgsz)
NS_LOG("read page %d (second half)\n", ns->regs.row);
else
NS_LOG("read OOB of page %d\n", ns->regs.row);
NS_UDELAY(access_delay);
NS_UDELAY(input_cycle * ns->geom.pgsz / 1000 / busdiv);
break;
case ACTION_SECERASE:
if (ns->lines.wp) {
NS_ERR("do_state_action: device is write-protected, ignore sector erase\n");
return -1;
}
if (ns->regs.row >= ns->geom.pgnum - ns->geom.pgsec
|| (ns->regs.row & ~(ns->geom.secsz - 1))) {
NS_ERR("do_state_action: wrong sector address (%#x)\n", ns->regs.row);
return -1;
}
ns->regs.row = (ns->regs.row <<
8 * (ns->geom.pgaddrbytes - ns->geom.secaddrbytes)) | ns->regs.column;
ns->regs.column = 0;
erase_block_no = ns->regs.row >> (ns->geom.secshift - ns->geom.pgshift);
NS_DBG("do_state_action: erase sector at address %#x, off = %d\n",
ns->regs.row, NS_RAW_OFFSET(ns));
NS_LOG("erase sector %u\n", erase_block_no);
erase_sector(ns);
NS_MDELAY(erase_delay);
if (erase_block_wear)
update_wear(erase_block_no);
if (erase_error(erase_block_no)) {
NS_WARN("simulating erase failure in erase block %u\n", erase_block_no);
return -1;
}
break;
case ACTION_PRGPAGE:
if (ns->lines.wp) {
NS_WARN("do_state_action: device is write-protected, programm\n");
return -1;
}
num = ns->geom.pgszoob - ns->regs.off - ns->regs.column;
if (num != ns->regs.count) {
NS_ERR("do_state_action: too few bytes were input (%d instead of %d)\n",
ns->regs.count, num);
return -1;
}
if (prog_page(ns, num) == -1)
return -1;
page_no = ns->regs.row;
NS_DBG("do_state_action: copy %d bytes from int buf to (%#x, %#x), raw off = %d\n",
num, ns->regs.row, ns->regs.column, NS_RAW_OFFSET(ns) + ns->regs.off);
NS_LOG("programm page %d\n", ns->regs.row);
NS_UDELAY(programm_delay);
NS_UDELAY(output_cycle * ns->geom.pgsz / 1000 / busdiv);
if (write_error(page_no)) {
NS_WARN("simulating write failure in page %u\n", page_no);
return -1;
}
break;
case ACTION_ZEROOFF:
NS_DBG("do_state_action: set internal offset to 0\n");
ns->regs.off = 0;
break;
case ACTION_HALFOFF:
if (!(ns->options & OPT_PAGE512_8BIT)) {
NS_ERR("do_state_action: BUG! can't skip half of page for non-512"
"byte page size 8x chips\n");
return -1;
}
NS_DBG("do_state_action: set internal offset to %d\n", ns->geom.pgsz/2);
ns->regs.off = ns->geom.pgsz/2;
break;
case ACTION_OOBOFF:
NS_DBG("do_state_action: set internal offset to %d\n", ns->geom.pgsz);
ns->regs.off = ns->geom.pgsz;
break;
default:
NS_DBG("do_state_action: BUG! unknown action\n");
}
return 0;
}
static void switch_state(struct nandsim *ns)
{
if (ns->op) {
ns->stateidx += 1;
ns->state = ns->nxstate;
ns->nxstate = ns->op[ns->stateidx + 1];
NS_DBG("switch_state: operation is known, switch to the next state, "
"state: %s, nxstate: %s\n",
get_state_name(ns->state), get_state_name(ns->nxstate));
if ((ns->state & ACTION_MASK) && do_state_action(ns, ns->state) < 0) {
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
} else {
ns->state = get_state_by_command(ns->regs.command);
NS_DBG("switch_state: operation is unknown, try to find it\n");
if (find_operation(ns, 0) != 0)
return;
if ((ns->state & ACTION_MASK) && do_state_action(ns, ns->state) < 0) {
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
}
if ((ns->nxstate & STATE_ADDR_MASK) && ns->busw == 16) {
NS_DBG("switch_state: double the column number for 16x device\n");
ns->regs.column <<= 1;
}
if (NS_STATE(ns->nxstate) == STATE_READY) {
u_char status = NS_STATUS_OK(ns);
if ((ns->state & (STATE_DATAIN_MASK | STATE_DATAOUT_MASK))
&& ns->regs.count != ns->regs.num) {
NS_WARN("switch_state: not all bytes were processed, %d left\n",
ns->regs.num - ns->regs.count);
status = NS_STATUS_FAILED(ns);
}
NS_DBG("switch_state: operation complete, switch to STATE_READY state\n");
switch_to_ready_state(ns, status);
return;
} else if (ns->nxstate & (STATE_DATAIN_MASK | STATE_DATAOUT_MASK)) {
ns->state = ns->nxstate;
ns->nxstate = ns->op[++ns->stateidx + 1];
ns->regs.num = ns->regs.count = 0;
NS_DBG("switch_state: the next state is data I/O, switch, "
"state: %s, nxstate: %s\n",
get_state_name(ns->state), get_state_name(ns->nxstate));
switch (NS_STATE(ns->state)) {
case STATE_DATAIN:
case STATE_DATAOUT:
ns->regs.num = ns->geom.pgszoob - ns->regs.off - ns->regs.column;
break;
case STATE_DATAOUT_ID:
ns->regs.num = ns->geom.idbytes;
break;
case STATE_DATAOUT_STATUS:
case STATE_DATAOUT_STATUS_M:
ns->regs.count = ns->regs.num = 0;
break;
default:
NS_ERR("switch_state: BUG! unknown data state\n");
}
} else if (ns->nxstate & STATE_ADDR_MASK) {
ns->regs.count = 0;
switch (NS_STATE(ns->nxstate)) {
case STATE_ADDR_PAGE:
ns->regs.num = ns->geom.pgaddrbytes;
break;
case STATE_ADDR_SEC:
ns->regs.num = ns->geom.secaddrbytes;
break;
case STATE_ADDR_ZERO:
ns->regs.num = 1;
break;
case STATE_ADDR_COLUMN:
ns->regs.num = ns->geom.pgaddrbytes - ns->geom.secaddrbytes;
break;
default:
NS_ERR("switch_state: BUG! unknown address state\n");
}
} else {
ns->regs.num = 0;
ns->regs.count = 0;
}
}
static u_char ns_nand_read_byte(struct mtd_info *mtd)
{
struct nandsim *ns = ((struct nand_chip *)mtd->priv)->priv;
u_char outb = 0x00;
if (!ns->lines.ce) {
NS_ERR("read_byte: chip is disabled, return %#x\n", (uint)outb);
return outb;
}
if (ns->lines.ale || ns->lines.cle) {
NS_ERR("read_byte: ALE or CLE pin is high, return %#x\n", (uint)outb);
return outb;
}
if (!(ns->state & STATE_DATAOUT_MASK)) {
NS_WARN("read_byte: unexpected data output cycle, state is %s "
"return %#x\n", get_state_name(ns->state), (uint)outb);
return outb;
}
if (NS_STATE(ns->state) == STATE_DATAOUT_STATUS) {
NS_DBG("read_byte: return %#x status\n", ns->regs.status);
return ns->regs.status;
}
if (ns->regs.count == ns->regs.num) {
NS_WARN("read_byte: no more data to output, return %#x\n", (uint)outb);
return outb;
}
switch (NS_STATE(ns->state)) {
case STATE_DATAOUT:
if (ns->busw == 8) {
outb = ns->buf.byte[ns->regs.count];
ns->regs.count += 1;
} else {
outb = (u_char)cpu_to_le16(ns->buf.word[ns->regs.count >> 1]);
ns->regs.count += 2;
}
break;
case STATE_DATAOUT_ID:
NS_DBG("read_byte: read ID byte %d, total = %d\n", ns->regs.count, ns->regs.num);
outb = ns->ids[ns->regs.count];
ns->regs.count += 1;
break;
default:
BUG();
}
if (ns->regs.count == ns->regs.num) {
NS_DBG("read_byte: all bytes were read\n");
if ((ns->options & OPT_AUTOINCR) && NS_STATE(ns->state) == STATE_DATAOUT) {
ns->regs.count = 0;
if (ns->regs.row + 1 < ns->geom.pgnum)
ns->regs.row += 1;
NS_DBG("read_byte: switch to the next page (%#x)\n", ns->regs.row);
do_state_action(ns, ACTION_CPY);
}
else if (NS_STATE(ns->nxstate) == STATE_READY)
switch_state(ns);
}
return outb;
}
static void ns_nand_write_byte(struct mtd_info *mtd, u_char byte)
{
struct nandsim *ns = ((struct nand_chip *)mtd->priv)->priv;
if (!ns->lines.ce) {
NS_ERR("write_byte: chip is disabled, ignore write\n");
return;
}
if (ns->lines.ale && ns->lines.cle) {
NS_ERR("write_byte: ALE and CLE pins are high simultaneously, ignore write\n");
return;
}
if (ns->lines.cle == 1) {
if (byte == NAND_CMD_RESET) {
NS_LOG("reset chip\n");
switch_to_ready_state(ns, NS_STATUS_OK(ns));
return;
}
if (check_command(byte)) {
NS_ERR("write_byte: unknown command %#x\n", (uint)byte);
return;
}
if (NS_STATE(ns->state) == STATE_DATAOUT_STATUS
|| NS_STATE(ns->state) == STATE_DATAOUT_STATUS_M
|| NS_STATE(ns->state) == STATE_DATAOUT) {
int row = ns->regs.row;
switch_state(ns);
if (byte == NAND_CMD_RNDOUT)
ns->regs.row = row;
}
if (NS_STATE(ns->nxstate) != STATE_UNKNOWN && !(ns->nxstate & STATE_CMD_MASK)) {
if (!(ns->regs.command == NAND_CMD_READID &&
NS_STATE(ns->state) == STATE_DATAOUT_ID && ns->regs.count == 2)) {
NS_WARN("write_byte: command (%#x) wasn't expected, expected state is %s, "
"ignore previous states\n", (uint)byte, get_state_name(ns->nxstate));
}
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
}
NS_DBG("command byte corresponding to %s state accepted\n",
get_state_name(get_state_by_command(byte)));
ns->regs.command = byte;
switch_state(ns);
} else if (ns->lines.ale == 1) {
if (NS_STATE(ns->nxstate) == STATE_UNKNOWN) {
NS_DBG("write_byte: operation isn't known yet, identify it\n");
if (find_operation(ns, 1) < 0)
return;
if ((ns->state & ACTION_MASK) && do_state_action(ns, ns->state) < 0) {
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
ns->regs.count = 0;
switch (NS_STATE(ns->nxstate)) {
case STATE_ADDR_PAGE:
ns->regs.num = ns->geom.pgaddrbytes;
break;
case STATE_ADDR_SEC:
ns->regs.num = ns->geom.secaddrbytes;
break;
case STATE_ADDR_ZERO:
ns->regs.num = 1;
break;
default:
BUG();
}
}
if (!(ns->nxstate & STATE_ADDR_MASK)) {
NS_ERR("write_byte: address (%#x) isn't expected, expected state is %s, "
"switch to STATE_READY\n", (uint)byte, get_state_name(ns->nxstate));
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
if (ns->regs.count == ns->regs.num) {
NS_ERR("write_byte: no more address bytes expected\n");
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
accept_addr_byte(ns, byte);
ns->regs.count += 1;
NS_DBG("write_byte: address byte %#x was accepted (%d bytes input, %d expected)\n",
(uint)byte, ns->regs.count, ns->regs.num);
if (ns->regs.count == ns->regs.num) {
NS_DBG("address (%#x, %#x) is accepted\n", ns->regs.row, ns->regs.column);
switch_state(ns);
}
} else {
if (!(ns->state & STATE_DATAIN_MASK)) {
NS_ERR("write_byte: data input (%#x) isn't expected, state is %s, "
"switch to %s\n", (uint)byte,
get_state_name(ns->state), get_state_name(STATE_READY));
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
if (ns->regs.count == ns->regs.num) {
NS_WARN("write_byte: %u input bytes has already been accepted, ignore write\n",
ns->regs.num);
return;
}
if (ns->busw == 8) {
ns->buf.byte[ns->regs.count] = byte;
ns->regs.count += 1;
} else {
ns->buf.word[ns->regs.count >> 1] = cpu_to_le16((uint16_t)byte);
ns->regs.count += 2;
}
}
return;
}
static void ns_hwcontrol(struct mtd_info *mtd, int cmd, unsigned int bitmask)
{
struct nandsim *ns = ((struct nand_chip *)mtd->priv)->priv;
ns->lines.cle = bitmask & NAND_CLE ? 1 : 0;
ns->lines.ale = bitmask & NAND_ALE ? 1 : 0;
ns->lines.ce = bitmask & NAND_NCE ? 1 : 0;
if (cmd != NAND_CMD_NONE)
ns_nand_write_byte(mtd, cmd);
}
static int ns_device_ready(struct mtd_info *mtd)
{
NS_DBG("device_ready\n");
return 1;
}
static uint16_t ns_nand_read_word(struct mtd_info *mtd)
{
struct nand_chip *chip = (struct nand_chip *)mtd->priv;
NS_DBG("read_word\n");
return chip->read_byte(mtd) | (chip->read_byte(mtd) << 8);
}
static void ns_nand_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct nandsim *ns = ((struct nand_chip *)mtd->priv)->priv;
if (!(ns->state & STATE_DATAIN_MASK)) {
NS_ERR("write_buf: data input isn't expected, state is %s, "
"switch to STATE_READY\n", get_state_name(ns->state));
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
if (ns->regs.count + len > ns->regs.num) {
NS_ERR("write_buf: too many input bytes\n");
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
memcpy(ns->buf.byte + ns->regs.count, buf, len);
ns->regs.count += len;
if (ns->regs.count == ns->regs.num) {
NS_DBG("write_buf: %d bytes were written\n", ns->regs.count);
}
}
static void ns_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct nandsim *ns = ((struct nand_chip *)mtd->priv)->priv;
if (!ns->lines.ce) {
NS_ERR("read_buf: chip is disabled\n");
return;
}
if (ns->lines.ale || ns->lines.cle) {
NS_ERR("read_buf: ALE or CLE pin is high\n");
return;
}
if (!(ns->state & STATE_DATAOUT_MASK)) {
NS_WARN("read_buf: unexpected data output cycle, current state is %s\n",
get_state_name(ns->state));
return;
}
if (NS_STATE(ns->state) != STATE_DATAOUT) {
int i;
for (i = 0; i < len; i++)
buf[i] = ((struct nand_chip *)mtd->priv)->read_byte(mtd);
return;
}
if (ns->regs.count + len > ns->regs.num) {
NS_ERR("read_buf: too many bytes to read\n");
switch_to_ready_state(ns, NS_STATUS_FAILED(ns));
return;
}
memcpy(buf, ns->buf.byte + ns->regs.count, len);
ns->regs.count += len;
if (ns->regs.count == ns->regs.num) {
if ((ns->options & OPT_AUTOINCR) && NS_STATE(ns->state) == STATE_DATAOUT) {
ns->regs.count = 0;
if (ns->regs.row + 1 < ns->geom.pgnum)
ns->regs.row += 1;
NS_DBG("read_buf: switch to the next page (%#x)\n", ns->regs.row);
do_state_action(ns, ACTION_CPY);
}
else if (NS_STATE(ns->nxstate) == STATE_READY)
switch_state(ns);
}
return;
}
static int ns_nand_verify_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
ns_nand_read_buf(mtd, (u_char *)&ns_verify_buf[0], len);
if (!memcmp(buf, &ns_verify_buf[0], len)) {
NS_DBG("verify_buf: the buffer is OK\n");
return 0;
} else {
NS_DBG("verify_buf: the buffer is wrong\n");
return -EFAULT;
}
}
static int __init ns_init_module(void)
{
struct nand_chip *chip;
struct nandsim *nand;
int retval = -ENOMEM, i;
if (bus_width != 8 && bus_width != 16) {
NS_ERR("wrong bus width (%d), use only 8 or 16\n", bus_width);
return -EINVAL;
}
nsmtd = kzalloc(sizeof(struct mtd_info) + sizeof(struct nand_chip)
+ sizeof(struct nandsim), GFP_KERNEL);
if (!nsmtd) {
NS_ERR("unable to allocate core structures.\n");
return -ENOMEM;
}
chip = (struct nand_chip *)(nsmtd + 1);
nsmtd->priv = (void *)chip;
nand = (struct nandsim *)(chip + 1);
chip->priv = (void *)nand;
chip->cmd_ctrl = ns_hwcontrol;
chip->read_byte = ns_nand_read_byte;
chip->dev_ready = ns_device_ready;
chip->write_buf = ns_nand_write_buf;
chip->read_buf = ns_nand_read_buf;
chip->verify_buf = ns_nand_verify_buf;
chip->read_word = ns_nand_read_word;
chip->ecc.mode = NAND_ECC_SOFT;
chip->options |= NAND_SKIP_BBTSCAN;
switch (bbt) {
case 2:
chip->options |= NAND_USE_FLASH_BBT_NO_OOB;
case 1:
chip->options |= NAND_USE_FLASH_BBT;
case 0:
break;
default:
NS_ERR("bbt has to be 0..2\n");
retval = -EINVAL;
goto error;
}
if (third_id_byte != 0xFF || fourth_id_byte != 0xFF)
nand->geom.idbytes = 4;
else
nand->geom.idbytes = 2;
nand->regs.status = NS_STATUS_OK(nand);
nand->nxstate = STATE_UNKNOWN;
nand->options |= OPT_PAGE256;
nand->ids[0] = first_id_byte;
nand->ids[1] = second_id_byte;
nand->ids[2] = third_id_byte;
nand->ids[3] = fourth_id_byte;
if (bus_width == 16) {
nand->busw = 16;
chip->options |= NAND_BUSWIDTH_16;
}
nsmtd->owner = THIS_MODULE;
if ((retval = parse_weakblocks()) != 0)
goto error;
if ((retval = parse_weakpages()) != 0)
goto error;
if ((retval = parse_gravepages()) != 0)
goto error;
retval = nand_scan_ident(nsmtd, 1, NULL);
if (retval) {
NS_ERR("cannot scan NAND Simulator device\n");
if (retval > 0)
retval = -ENXIO;
goto error;
}
if (bch) {
unsigned int eccsteps, eccbytes;
if (!mtd_nand_has_bch()) {
NS_ERR("BCH ECC support is disabled\n");
retval = -EINVAL;
goto error;
}
eccsteps = nsmtd->writesize/512;
eccbytes = (bch*13+7)/8;
if ((nsmtd->oobsize < 64) || !eccsteps) {
NS_ERR("bch not available on small page devices\n");
retval = -EINVAL;
goto error;
}
if ((eccbytes*eccsteps+2) > nsmtd->oobsize) {
NS_ERR("invalid bch value %u\n", bch);
retval = -EINVAL;
goto error;
}
chip->ecc.mode = NAND_ECC_SOFT_BCH;
chip->ecc.size = 512;
chip->ecc.bytes = eccbytes;
NS_INFO("using %u-bit/%u bytes BCH ECC\n", bch, chip->ecc.size);
}
retval = nand_scan_tail(nsmtd);
if (retval) {
NS_ERR("can't register NAND Simulator\n");
if (retval > 0)
retval = -ENXIO;
goto error;
}
if (overridesize) {
uint64_t new_size = (uint64_t)nsmtd->erasesize << overridesize;
if (new_size >> overridesize != nsmtd->erasesize) {
NS_ERR("overridesize is too big\n");
goto err_exit;
}
nsmtd->size = new_size;
chip->chipsize = new_size;
chip->chip_shift = ffs(nsmtd->erasesize) + overridesize - 1;
chip->pagemask = (chip->chipsize >> chip->page_shift) - 1;
}
if ((retval = setup_wear_reporting(nsmtd)) != 0)
goto err_exit;
if ((retval = init_nandsim(nsmtd)) != 0)
goto err_exit;
if ((retval = nand_default_bbt(nsmtd)) != 0)
goto err_exit;
if ((retval = parse_badblocks(nand, nsmtd)) != 0)
goto err_exit;
retval = mtd_device_register(nsmtd, &nand->partitions[0],
nand->nbparts);
if (retval != 0)
goto err_exit;
return 0;
err_exit:
free_nandsim(nand);
nand_release(nsmtd);
for (i = 0;i < ARRAY_SIZE(nand->partitions); ++i)
kfree(nand->partitions[i].name);
error:
kfree(nsmtd);
free_lists();
return retval;
}
static void __exit ns_cleanup_module(void)
{
struct nandsim *ns = ((struct nand_chip *)nsmtd->priv)->priv;
int i;
free_nandsim(ns);
nand_release(nsmtd);
for (i = 0;i < ARRAY_SIZE(ns->partitions); ++i)
kfree(ns->partitions[i].name);
kfree(nsmtd);
free_lists();
}
