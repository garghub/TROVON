unsigned edac_dimm_info_location(struct dimm_info *dimm, char *buf,
unsigned len)
{
struct mem_ctl_info *mci = dimm->mci;
int i, n, count = 0;
char *p = buf;
for (i = 0; i < mci->n_layers; i++) {
n = snprintf(p, len, "%s %d ",
edac_layer_name[mci->layers[i].type],
dimm->location[i]);
p += n;
len -= n;
count += n;
if (!len)
break;
}
return count;
}
static void edac_mc_dump_channel(struct rank_info *chan)
{
edac_dbg(4, " channel->chan_idx = %d\n", chan->chan_idx);
edac_dbg(4, " channel = %p\n", chan);
edac_dbg(4, " channel->csrow = %p\n", chan->csrow);
edac_dbg(4, " channel->dimm = %p\n", chan->dimm);
}
static void edac_mc_dump_dimm(struct dimm_info *dimm, int number)
{
char location[80];
edac_dimm_info_location(dimm, location, sizeof(location));
edac_dbg(4, "%s%i: %smapped as virtual row %d, chan %d\n",
dimm->mci->mem_is_per_rank ? "rank" : "dimm",
number, location, dimm->csrow, dimm->cschannel);
edac_dbg(4, " dimm = %p\n", dimm);
edac_dbg(4, " dimm->label = '%s'\n", dimm->label);
edac_dbg(4, " dimm->nr_pages = 0x%x\n", dimm->nr_pages);
edac_dbg(4, " dimm->grain = %d\n", dimm->grain);
edac_dbg(4, " dimm->nr_pages = 0x%x\n", dimm->nr_pages);
}
static void edac_mc_dump_csrow(struct csrow_info *csrow)
{
edac_dbg(4, "csrow->csrow_idx = %d\n", csrow->csrow_idx);
edac_dbg(4, " csrow = %p\n", csrow);
edac_dbg(4, " csrow->first_page = 0x%lx\n", csrow->first_page);
edac_dbg(4, " csrow->last_page = 0x%lx\n", csrow->last_page);
edac_dbg(4, " csrow->page_mask = 0x%lx\n", csrow->page_mask);
edac_dbg(4, " csrow->nr_channels = %d\n", csrow->nr_channels);
edac_dbg(4, " csrow->channels = %p\n", csrow->channels);
edac_dbg(4, " csrow->mci = %p\n", csrow->mci);
}
static void edac_mc_dump_mci(struct mem_ctl_info *mci)
{
edac_dbg(3, "\tmci = %p\n", mci);
edac_dbg(3, "\tmci->mtype_cap = %lx\n", mci->mtype_cap);
edac_dbg(3, "\tmci->edac_ctl_cap = %lx\n", mci->edac_ctl_cap);
edac_dbg(3, "\tmci->edac_cap = %lx\n", mci->edac_cap);
edac_dbg(4, "\tmci->edac_check = %p\n", mci->edac_check);
edac_dbg(3, "\tmci->nr_csrows = %d, csrows = %p\n",
mci->nr_csrows, mci->csrows);
edac_dbg(3, "\tmci->nr_dimms = %d, dimms = %p\n",
mci->tot_dimms, mci->dimms);
edac_dbg(3, "\tdev = %p\n", mci->pdev);
edac_dbg(3, "\tmod_name:ctl_name = %s:%s\n",
mci->mod_name, mci->ctl_name);
edac_dbg(3, "\tpvt_info = %p\n\n", mci->pvt_info);
}
void *edac_align_ptr(void **p, unsigned size, int n_elems)
{
unsigned align, r;
void *ptr = *p;
*p += size * n_elems;
if (size > sizeof(long))
align = sizeof(long long);
else if (size > sizeof(int))
align = sizeof(long);
else if (size > sizeof(short))
align = sizeof(int);
else if (size > sizeof(char))
align = sizeof(short);
else
return (char *)ptr;
r = (unsigned long)p % align;
if (r == 0)
return (char *)ptr;
*p += align - r;
return (void *)(((unsigned long)ptr) + align - r);
}
static void _edac_mc_free(struct mem_ctl_info *mci)
{
int i, chn, row;
struct csrow_info *csr;
const unsigned int tot_dimms = mci->tot_dimms;
const unsigned int tot_channels = mci->num_cschannel;
const unsigned int tot_csrows = mci->nr_csrows;
if (mci->dimms) {
for (i = 0; i < tot_dimms; i++)
kfree(mci->dimms[i]);
kfree(mci->dimms);
}
if (mci->csrows) {
for (row = 0; row < tot_csrows; row++) {
csr = mci->csrows[row];
if (csr) {
if (csr->channels) {
for (chn = 0; chn < tot_channels; chn++)
kfree(csr->channels[chn]);
kfree(csr->channels);
}
kfree(csr);
}
}
kfree(mci->csrows);
}
kfree(mci);
}
struct mem_ctl_info *edac_mc_alloc(unsigned mc_num,
unsigned n_layers,
struct edac_mc_layer *layers,
unsigned sz_pvt)
{
struct mem_ctl_info *mci;
struct edac_mc_layer *layer;
struct csrow_info *csr;
struct rank_info *chan;
struct dimm_info *dimm;
u32 *ce_per_layer[EDAC_MAX_LAYERS], *ue_per_layer[EDAC_MAX_LAYERS];
unsigned pos[EDAC_MAX_LAYERS];
unsigned size, tot_dimms = 1, count = 1;
unsigned tot_csrows = 1, tot_channels = 1, tot_errcount = 0;
void *pvt, *p, *ptr = NULL;
int i, j, row, chn, n, len, off;
bool per_rank = false;
BUG_ON(n_layers > EDAC_MAX_LAYERS || n_layers == 0);
for (i = 0; i < n_layers; i++) {
tot_dimms *= layers[i].size;
if (layers[i].is_virt_csrow)
tot_csrows *= layers[i].size;
else
tot_channels *= layers[i].size;
if (layers[i].type == EDAC_MC_LAYER_CHIP_SELECT)
per_rank = true;
}
mci = edac_align_ptr(&ptr, sizeof(*mci), 1);
layer = edac_align_ptr(&ptr, sizeof(*layer), n_layers);
for (i = 0; i < n_layers; i++) {
count *= layers[i].size;
edac_dbg(4, "errcount layer %d size %d\n", i, count);
ce_per_layer[i] = edac_align_ptr(&ptr, sizeof(u32), count);
ue_per_layer[i] = edac_align_ptr(&ptr, sizeof(u32), count);
tot_errcount += 2 * count;
}
edac_dbg(4, "allocating %d error counters\n", tot_errcount);
pvt = edac_align_ptr(&ptr, sz_pvt, 1);
size = ((unsigned long)pvt) + sz_pvt;
edac_dbg(1, "allocating %u bytes for mci data (%d %s, %d csrows/channels)\n",
size,
tot_dimms,
per_rank ? "ranks" : "dimms",
tot_csrows * tot_channels);
mci = kzalloc(size, GFP_KERNEL);
if (mci == NULL)
return NULL;
layer = (struct edac_mc_layer *)(((char *)mci) + ((unsigned long)layer));
for (i = 0; i < n_layers; i++) {
mci->ce_per_layer[i] = (u32 *)((char *)mci + ((unsigned long)ce_per_layer[i]));
mci->ue_per_layer[i] = (u32 *)((char *)mci + ((unsigned long)ue_per_layer[i]));
}
pvt = sz_pvt ? (((char *)mci) + ((unsigned long)pvt)) : NULL;
mci->mc_idx = mc_num;
mci->tot_dimms = tot_dimms;
mci->pvt_info = pvt;
mci->n_layers = n_layers;
mci->layers = layer;
memcpy(mci->layers, layers, sizeof(*layer) * n_layers);
mci->nr_csrows = tot_csrows;
mci->num_cschannel = tot_channels;
mci->mem_is_per_rank = per_rank;
mci->csrows = kcalloc(sizeof(*mci->csrows), tot_csrows, GFP_KERNEL);
if (!mci->csrows)
goto error;
for (row = 0; row < tot_csrows; row++) {
csr = kzalloc(sizeof(**mci->csrows), GFP_KERNEL);
if (!csr)
goto error;
mci->csrows[row] = csr;
csr->csrow_idx = row;
csr->mci = mci;
csr->nr_channels = tot_channels;
csr->channels = kcalloc(sizeof(*csr->channels), tot_channels,
GFP_KERNEL);
if (!csr->channels)
goto error;
for (chn = 0; chn < tot_channels; chn++) {
chan = kzalloc(sizeof(**csr->channels), GFP_KERNEL);
if (!chan)
goto error;
csr->channels[chn] = chan;
chan->chan_idx = chn;
chan->csrow = csr;
}
}
mci->dimms = kcalloc(sizeof(*mci->dimms), tot_dimms, GFP_KERNEL);
if (!mci->dimms)
goto error;
memset(&pos, 0, sizeof(pos));
row = 0;
chn = 0;
for (i = 0; i < tot_dimms; i++) {
chan = mci->csrows[row]->channels[chn];
off = EDAC_DIMM_OFF(layer, n_layers, pos[0], pos[1], pos[2]);
if (off < 0 || off >= tot_dimms) {
edac_mc_printk(mci, KERN_ERR, "EDAC core bug: EDAC_DIMM_OFF is trying to do an illegal data access\n");
goto error;
}
dimm = kzalloc(sizeof(**mci->dimms), GFP_KERNEL);
if (!dimm)
goto error;
mci->dimms[off] = dimm;
dimm->mci = mci;
len = sizeof(dimm->label);
p = dimm->label;
n = snprintf(p, len, "mc#%u", mc_num);
p += n;
len -= n;
for (j = 0; j < n_layers; j++) {
n = snprintf(p, len, "%s#%u",
edac_layer_name[layers[j].type],
pos[j]);
p += n;
len -= n;
dimm->location[j] = pos[j];
if (len <= 0)
break;
}
chan->dimm = dimm;
dimm->csrow = row;
dimm->cschannel = chn;
row++;
if (row == tot_csrows) {
row = 0;
chn++;
}
for (j = n_layers - 1; j >= 0; j--) {
pos[j]++;
if (pos[j] < layers[j].size)
break;
pos[j] = 0;
}
}
mci->op_state = OP_ALLOC;
return mci;
error:
_edac_mc_free(mci);
return NULL;
}
void edac_mc_free(struct mem_ctl_info *mci)
{
edac_dbg(1, "\n");
if (!device_is_registered(&mci->dev)) {
_edac_mc_free(mci);
return;
}
edac_unregister_sysfs(mci);
}
struct mem_ctl_info *find_mci_by_dev(struct device *dev)
{
struct mem_ctl_info *mci;
struct list_head *item;
edac_dbg(3, "\n");
list_for_each(item, &mc_devices) {
mci = list_entry(item, struct mem_ctl_info, link);
if (mci->pdev == dev)
return mci;
}
return NULL;
}
static int edac_mc_assert_error_check_and_clear(void)
{
int old_state;
if (edac_op_state == EDAC_OPSTATE_POLL)
return 1;
old_state = edac_err_assert;
edac_err_assert = 0;
return old_state;
}
static void edac_mc_workq_function(struct work_struct *work_req)
{
struct delayed_work *d_work = to_delayed_work(work_req);
struct mem_ctl_info *mci = to_edac_mem_ctl_work(d_work);
mutex_lock(&mem_ctls_mutex);
if (mci->op_state == OP_OFFLINE) {
mutex_unlock(&mem_ctls_mutex);
return;
}
if (edac_mc_assert_error_check_and_clear() && (mci->edac_check != NULL))
mci->edac_check(mci);
mutex_unlock(&mem_ctls_mutex);
queue_delayed_work(edac_workqueue, &mci->work,
msecs_to_jiffies(edac_mc_get_poll_msec()));
}
static void edac_mc_workq_setup(struct mem_ctl_info *mci, unsigned msec)
{
edac_dbg(0, "\n");
if (mci->op_state != OP_RUNNING_POLL)
return;
INIT_DELAYED_WORK(&mci->work, edac_mc_workq_function);
queue_delayed_work(edac_workqueue, &mci->work, msecs_to_jiffies(msec));
}
static void edac_mc_workq_teardown(struct mem_ctl_info *mci)
{
int status;
if (mci->op_state != OP_RUNNING_POLL)
return;
status = cancel_delayed_work(&mci->work);
if (status == 0) {
edac_dbg(0, "not canceled, flush the queue\n");
flush_workqueue(edac_workqueue);
}
}
void edac_mc_reset_delay_period(int value)
{
struct mem_ctl_info *mci;
struct list_head *item;
mutex_lock(&mem_ctls_mutex);
list_for_each(item, &mc_devices) {
mci = list_entry(item, struct mem_ctl_info, link);
if (mci->op_state == OP_RUNNING_POLL)
cancel_delayed_work(&mci->work);
}
mutex_unlock(&mem_ctls_mutex);
mutex_lock(&mem_ctls_mutex);
list_for_each(item, &mc_devices) {
mci = list_entry(item, struct mem_ctl_info, link);
edac_mc_workq_setup(mci, (unsigned long) value);
}
mutex_unlock(&mem_ctls_mutex);
}
static int add_mc_to_global_list(struct mem_ctl_info *mci)
{
struct list_head *item, *insert_before;
struct mem_ctl_info *p;
insert_before = &mc_devices;
p = find_mci_by_dev(mci->pdev);
if (unlikely(p != NULL))
goto fail0;
list_for_each(item, &mc_devices) {
p = list_entry(item, struct mem_ctl_info, link);
if (p->mc_idx >= mci->mc_idx) {
if (unlikely(p->mc_idx == mci->mc_idx))
goto fail1;
insert_before = item;
break;
}
}
list_add_tail_rcu(&mci->link, insert_before);
atomic_inc(&edac_handlers);
return 0;
fail0:
edac_printk(KERN_WARNING, EDAC_MC,
"%s (%s) %s %s already assigned %d\n", dev_name(p->pdev),
edac_dev_name(mci), p->mod_name, p->ctl_name, p->mc_idx);
return 1;
fail1:
edac_printk(KERN_WARNING, EDAC_MC,
"bug in low-level driver: attempt to assign\n"
" duplicate mc_idx %d in %s()\n", p->mc_idx, __func__);
return 1;
}
static void del_mc_from_global_list(struct mem_ctl_info *mci)
{
atomic_dec(&edac_handlers);
list_del_rcu(&mci->link);
synchronize_rcu();
INIT_LIST_HEAD(&mci->link);
}
struct mem_ctl_info *edac_mc_find(int idx)
{
struct list_head *item;
struct mem_ctl_info *mci;
list_for_each(item, &mc_devices) {
mci = list_entry(item, struct mem_ctl_info, link);
if (mci->mc_idx >= idx) {
if (mci->mc_idx == idx)
return mci;
break;
}
}
return NULL;
}
int edac_mc_add_mc(struct mem_ctl_info *mci)
{
edac_dbg(0, "\n");
#ifdef CONFIG_EDAC_DEBUG
if (edac_debug_level >= 3)
edac_mc_dump_mci(mci);
if (edac_debug_level >= 4) {
int i;
for (i = 0; i < mci->nr_csrows; i++) {
struct csrow_info *csrow = mci->csrows[i];
u32 nr_pages = 0;
int j;
for (j = 0; j < csrow->nr_channels; j++)
nr_pages += csrow->channels[j]->dimm->nr_pages;
if (!nr_pages)
continue;
edac_mc_dump_csrow(csrow);
for (j = 0; j < csrow->nr_channels; j++)
if (csrow->channels[j]->dimm->nr_pages)
edac_mc_dump_channel(csrow->channels[j]);
}
for (i = 0; i < mci->tot_dimms; i++)
if (mci->dimms[i]->nr_pages)
edac_mc_dump_dimm(mci->dimms[i], i);
}
#endif
mutex_lock(&mem_ctls_mutex);
if (add_mc_to_global_list(mci))
goto fail0;
mci->start_time = jiffies;
if (edac_create_sysfs_mci_device(mci)) {
edac_mc_printk(mci, KERN_WARNING,
"failed to create sysfs device\n");
goto fail1;
}
if (mci->edac_check != NULL) {
mci->op_state = OP_RUNNING_POLL;
edac_mc_workq_setup(mci, edac_mc_get_poll_msec());
} else {
mci->op_state = OP_RUNNING_INTERRUPT;
}
edac_mc_printk(mci, KERN_INFO, "Giving out device to '%s' '%s':"
" DEV %s\n", mci->mod_name, mci->ctl_name, edac_dev_name(mci));
mutex_unlock(&mem_ctls_mutex);
return 0;
fail1:
del_mc_from_global_list(mci);
fail0:
mutex_unlock(&mem_ctls_mutex);
return 1;
}
struct mem_ctl_info *edac_mc_del_mc(struct device *dev)
{
struct mem_ctl_info *mci;
edac_dbg(0, "\n");
mutex_lock(&mem_ctls_mutex);
mci = find_mci_by_dev(dev);
if (mci == NULL) {
mutex_unlock(&mem_ctls_mutex);
return NULL;
}
del_mc_from_global_list(mci);
mutex_unlock(&mem_ctls_mutex);
edac_mc_workq_teardown(mci);
mci->op_state = OP_OFFLINE;
edac_remove_sysfs_mci_device(mci);
edac_printk(KERN_INFO, EDAC_MC,
"Removed device %d for %s %s: DEV %s\n", mci->mc_idx,
mci->mod_name, mci->ctl_name, edac_dev_name(mci));
return mci;
}
static void edac_mc_scrub_block(unsigned long page, unsigned long offset,
u32 size)
{
struct page *pg;
void *virt_addr;
unsigned long flags = 0;
edac_dbg(3, "\n");
if (!pfn_valid(page))
return;
pg = pfn_to_page(page);
if (PageHighMem(pg))
local_irq_save(flags);
virt_addr = kmap_atomic(pg);
atomic_scrub(virt_addr + offset, size);
kunmap_atomic(virt_addr);
if (PageHighMem(pg))
local_irq_restore(flags);
}
int edac_mc_find_csrow_by_page(struct mem_ctl_info *mci, unsigned long page)
{
struct csrow_info **csrows = mci->csrows;
int row, i, j, n;
edac_dbg(1, "MC%d: 0x%lx\n", mci->mc_idx, page);
row = -1;
for (i = 0; i < mci->nr_csrows; i++) {
struct csrow_info *csrow = csrows[i];
n = 0;
for (j = 0; j < csrow->nr_channels; j++) {
struct dimm_info *dimm = csrow->channels[j]->dimm;
n += dimm->nr_pages;
}
if (n == 0)
continue;
edac_dbg(3, "MC%d: first(0x%lx) page(0x%lx) last(0x%lx) mask(0x%lx)\n",
mci->mc_idx,
csrow->first_page, page, csrow->last_page,
csrow->page_mask);
if ((page >= csrow->first_page) &&
(page <= csrow->last_page) &&
((page & csrow->page_mask) ==
(csrow->first_page & csrow->page_mask))) {
row = i;
break;
}
}
if (row == -1)
edac_mc_printk(mci, KERN_ERR,
"could not look up page error address %lx\n",
(unsigned long)page);
return row;
}
static void edac_inc_ce_error(struct mem_ctl_info *mci,
bool enable_per_layer_report,
const int pos[EDAC_MAX_LAYERS],
const u16 count)
{
int i, index = 0;
mci->ce_mc += count;
if (!enable_per_layer_report) {
mci->ce_noinfo_count += count;
return;
}
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
break;
index += pos[i];
mci->ce_per_layer[i][index] += count;
if (i < mci->n_layers - 1)
index *= mci->layers[i + 1].size;
}
}
static void edac_inc_ue_error(struct mem_ctl_info *mci,
bool enable_per_layer_report,
const int pos[EDAC_MAX_LAYERS],
const u16 count)
{
int i, index = 0;
mci->ue_mc += count;
if (!enable_per_layer_report) {
mci->ce_noinfo_count += count;
return;
}
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
break;
index += pos[i];
mci->ue_per_layer[i][index] += count;
if (i < mci->n_layers - 1)
index *= mci->layers[i + 1].size;
}
}
static void edac_ce_error(struct mem_ctl_info *mci,
const u16 error_count,
const int pos[EDAC_MAX_LAYERS],
const char *msg,
const char *location,
const char *label,
const char *detail,
const char *other_detail,
const bool enable_per_layer_report,
const unsigned long page_frame_number,
const unsigned long offset_in_page,
long grain)
{
unsigned long remapped_page;
if (edac_mc_get_log_ce()) {
if (other_detail && *other_detail)
edac_mc_printk(mci, KERN_WARNING,
"%d CE %s on %s (%s %s - %s)\n",
error_count,
msg, label, location,
detail, other_detail);
else
edac_mc_printk(mci, KERN_WARNING,
"%d CE %s on %s (%s %s)\n",
error_count,
msg, label, location,
detail);
}
edac_inc_ce_error(mci, enable_per_layer_report, pos, error_count);
if (mci->scrub_mode & SCRUB_SW_SRC) {
remapped_page = mci->ctl_page_to_phys ?
mci->ctl_page_to_phys(mci, page_frame_number) :
page_frame_number;
edac_mc_scrub_block(remapped_page,
offset_in_page, grain);
}
}
static void edac_ue_error(struct mem_ctl_info *mci,
const u16 error_count,
const int pos[EDAC_MAX_LAYERS],
const char *msg,
const char *location,
const char *label,
const char *detail,
const char *other_detail,
const bool enable_per_layer_report)
{
if (edac_mc_get_log_ue()) {
if (other_detail && *other_detail)
edac_mc_printk(mci, KERN_WARNING,
"%d UE %s on %s (%s %s - %s)\n",
error_count,
msg, label, location, detail,
other_detail);
else
edac_mc_printk(mci, KERN_WARNING,
"%d UE %s on %s (%s %s)\n",
error_count,
msg, label, location, detail);
}
if (edac_mc_get_panic_on_ue()) {
if (other_detail && *other_detail)
panic("UE %s on %s (%s%s - %s)\n",
msg, label, location, detail, other_detail);
else
panic("UE %s on %s (%s%s)\n",
msg, label, location, detail);
}
edac_inc_ue_error(mci, enable_per_layer_report, pos, error_count);
}
void edac_mc_handle_error(const enum hw_event_mc_err_type type,
struct mem_ctl_info *mci,
const u16 error_count,
const unsigned long page_frame_number,
const unsigned long offset_in_page,
const unsigned long syndrome,
const int top_layer,
const int mid_layer,
const int low_layer,
const char *msg,
const char *other_detail)
{
char detail[80], location[80];
char label[(EDAC_MC_LABEL_LEN + 1 + sizeof(OTHER_LABEL)) * mci->tot_dimms];
char *p;
int row = -1, chan = -1;
int pos[EDAC_MAX_LAYERS] = { top_layer, mid_layer, low_layer };
int i;
long grain;
bool enable_per_layer_report = false;
u8 grain_bits;
edac_dbg(3, "MC%d\n", mci->mc_idx);
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] >= (int)mci->layers[i].size) {
if (type == HW_EVENT_ERR_CORRECTED)
p = "CE";
else
p = "UE";
edac_mc_printk(mci, KERN_ERR,
"INTERNAL ERROR: %s value is out of range (%d >= %d)\n",
edac_layer_name[mci->layers[i].type],
pos[i], mci->layers[i].size);
pos[i] = -1;
}
if (pos[i] >= 0)
enable_per_layer_report = true;
}
grain = 0;
p = label;
*p = '\0';
for (i = 0; i < mci->tot_dimms; i++) {
struct dimm_info *dimm = mci->dimms[i];
if (top_layer >= 0 && top_layer != dimm->location[0])
continue;
if (mid_layer >= 0 && mid_layer != dimm->location[1])
continue;
if (low_layer >= 0 && low_layer != dimm->location[2])
continue;
if (dimm->grain > grain)
grain = dimm->grain;
if (enable_per_layer_report && dimm->nr_pages) {
if (p != label) {
strcpy(p, OTHER_LABEL);
p += strlen(OTHER_LABEL);
}
strcpy(p, dimm->label);
p += strlen(p);
*p = '\0';
edac_dbg(4, "%s csrows map: (%d,%d)\n",
mci->mem_is_per_rank ? "rank" : "dimm",
dimm->csrow, dimm->cschannel);
if (row == -1)
row = dimm->csrow;
else if (row >= 0 && row != dimm->csrow)
row = -2;
if (chan == -1)
chan = dimm->cschannel;
else if (chan >= 0 && chan != dimm->cschannel)
chan = -2;
}
}
if (!enable_per_layer_report) {
strcpy(label, "any memory");
} else {
edac_dbg(4, "csrow/channel to increment: (%d,%d)\n", row, chan);
if (p == label)
strcpy(label, "unknown memory");
if (type == HW_EVENT_ERR_CORRECTED) {
if (row >= 0) {
mci->csrows[row]->ce_count += error_count;
if (chan >= 0)
mci->csrows[row]->channels[chan]->ce_count += error_count;
}
} else
if (row >= 0)
mci->csrows[row]->ue_count += error_count;
}
p = location;
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
continue;
p += sprintf(p, "%s:%d ",
edac_layer_name[mci->layers[i].type],
pos[i]);
}
if (p > location)
*(p - 1) = '\0';
grain_bits = fls_long(grain) + 1;
trace_mc_event(type, msg, label, error_count,
mci->mc_idx, top_layer, mid_layer, low_layer,
PAGES_TO_MiB(page_frame_number) | offset_in_page,
grain_bits, syndrome, other_detail);
if (type == HW_EVENT_ERR_CORRECTED) {
snprintf(detail, sizeof(detail),
"page:0x%lx offset:0x%lx grain:%ld syndrome:0x%lx",
page_frame_number, offset_in_page,
grain, syndrome);
edac_ce_error(mci, error_count, pos, msg, location, label,
detail, other_detail, enable_per_layer_report,
page_frame_number, offset_in_page, grain);
} else {
snprintf(detail, sizeof(detail),
"page:0x%lx offset:0x%lx grain:%ld",
page_frame_number, offset_in_page, grain);
edac_ue_error(mci, error_count, pos, msg, location, label,
detail, other_detail, enable_per_layer_report);
}
}
