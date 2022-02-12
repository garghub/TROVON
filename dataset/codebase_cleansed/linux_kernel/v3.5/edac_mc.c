static void edac_mc_dump_channel(struct rank_info *chan)
{
debugf4("\tchannel = %p\n", chan);
debugf4("\tchannel->chan_idx = %d\n", chan->chan_idx);
debugf4("\tchannel->csrow = %p\n\n", chan->csrow);
debugf4("\tchannel->dimm = %p\n", chan->dimm);
}
static void edac_mc_dump_dimm(struct dimm_info *dimm)
{
int i;
debugf4("\tdimm = %p\n", dimm);
debugf4("\tdimm->label = '%s'\n", dimm->label);
debugf4("\tdimm->nr_pages = 0x%x\n", dimm->nr_pages);
debugf4("\tdimm location ");
for (i = 0; i < dimm->mci->n_layers; i++) {
printk(KERN_CONT "%d", dimm->location[i]);
if (i < dimm->mci->n_layers - 1)
printk(KERN_CONT ".");
}
printk(KERN_CONT "\n");
debugf4("\tdimm->grain = %d\n", dimm->grain);
debugf4("\tdimm->nr_pages = 0x%x\n", dimm->nr_pages);
}
static void edac_mc_dump_csrow(struct csrow_info *csrow)
{
debugf4("\tcsrow = %p\n", csrow);
debugf4("\tcsrow->csrow_idx = %d\n", csrow->csrow_idx);
debugf4("\tcsrow->first_page = 0x%lx\n", csrow->first_page);
debugf4("\tcsrow->last_page = 0x%lx\n", csrow->last_page);
debugf4("\tcsrow->page_mask = 0x%lx\n", csrow->page_mask);
debugf4("\tcsrow->nr_channels = %d\n", csrow->nr_channels);
debugf4("\tcsrow->channels = %p\n", csrow->channels);
debugf4("\tcsrow->mci = %p\n\n", csrow->mci);
}
static void edac_mc_dump_mci(struct mem_ctl_info *mci)
{
debugf3("\tmci = %p\n", mci);
debugf3("\tmci->mtype_cap = %lx\n", mci->mtype_cap);
debugf3("\tmci->edac_ctl_cap = %lx\n", mci->edac_ctl_cap);
debugf3("\tmci->edac_cap = %lx\n", mci->edac_cap);
debugf4("\tmci->edac_check = %p\n", mci->edac_check);
debugf3("\tmci->nr_csrows = %d, csrows = %p\n",
mci->nr_csrows, mci->csrows);
debugf3("\tmci->nr_dimms = %d, dimms = %p\n",
mci->tot_dimms, mci->dimms);
debugf3("\tdev = %p\n", mci->dev);
debugf3("\tmod_name:ctl_name = %s:%s\n", mci->mod_name, mci->ctl_name);
debugf3("\tpvt_info = %p\n\n", mci->pvt_info);
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
struct mem_ctl_info *edac_mc_alloc(unsigned mc_num,
unsigned n_layers,
struct edac_mc_layer *layers,
unsigned sz_pvt)
{
struct mem_ctl_info *mci;
struct edac_mc_layer *layer;
struct csrow_info *csi, *csr;
struct rank_info *chi, *chp, *chan;
struct dimm_info *dimm;
u32 *ce_per_layer[EDAC_MAX_LAYERS], *ue_per_layer[EDAC_MAX_LAYERS];
unsigned pos[EDAC_MAX_LAYERS];
unsigned size, tot_dimms = 1, count = 1;
unsigned tot_csrows = 1, tot_channels = 1, tot_errcount = 0;
void *pvt, *p, *ptr = NULL;
int i, j, err, row, chn, n, len;
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
csi = edac_align_ptr(&ptr, sizeof(*csi), tot_csrows);
chi = edac_align_ptr(&ptr, sizeof(*chi), tot_csrows * tot_channels);
dimm = edac_align_ptr(&ptr, sizeof(*dimm), tot_dimms);
for (i = 0; i < n_layers; i++) {
count *= layers[i].size;
debugf4("%s: errcount layer %d size %d\n", __func__, i, count);
ce_per_layer[i] = edac_align_ptr(&ptr, sizeof(u32), count);
ue_per_layer[i] = edac_align_ptr(&ptr, sizeof(u32), count);
tot_errcount += 2 * count;
}
debugf4("%s: allocating %d error counters\n", __func__, tot_errcount);
pvt = edac_align_ptr(&ptr, sz_pvt, 1);
size = ((unsigned long)pvt) + sz_pvt;
debugf1("%s(): allocating %u bytes for mci data (%d %s, %d csrows/channels)\n",
__func__, size,
tot_dimms,
per_rank ? "ranks" : "dimms",
tot_csrows * tot_channels);
mci = kzalloc(size, GFP_KERNEL);
if (mci == NULL)
return NULL;
layer = (struct edac_mc_layer *)(((char *)mci) + ((unsigned long)layer));
csi = (struct csrow_info *)(((char *)mci) + ((unsigned long)csi));
chi = (struct rank_info *)(((char *)mci) + ((unsigned long)chi));
dimm = (struct dimm_info *)(((char *)mci) + ((unsigned long)dimm));
for (i = 0; i < n_layers; i++) {
mci->ce_per_layer[i] = (u32 *)((char *)mci + ((unsigned long)ce_per_layer[i]));
mci->ue_per_layer[i] = (u32 *)((char *)mci + ((unsigned long)ue_per_layer[i]));
}
pvt = sz_pvt ? (((char *)mci) + ((unsigned long)pvt)) : NULL;
mci->mc_idx = mc_num;
mci->csrows = csi;
mci->dimms = dimm;
mci->tot_dimms = tot_dimms;
mci->pvt_info = pvt;
mci->n_layers = n_layers;
mci->layers = layer;
memcpy(mci->layers, layers, sizeof(*layer) * n_layers);
mci->nr_csrows = tot_csrows;
mci->num_cschannel = tot_channels;
mci->mem_is_per_rank = per_rank;
for (row = 0; row < tot_csrows; row++) {
csr = &csi[row];
csr->csrow_idx = row;
csr->mci = mci;
csr->nr_channels = tot_channels;
chp = &chi[row * tot_channels];
csr->channels = chp;
for (chn = 0; chn < tot_channels; chn++) {
chan = &chp[chn];
chan->chan_idx = chn;
chan->csrow = csr;
}
}
memset(&pos, 0, sizeof(pos));
row = 0;
chn = 0;
debugf4("%s: initializing %d %s\n", __func__, tot_dimms,
per_rank ? "ranks" : "dimms");
for (i = 0; i < tot_dimms; i++) {
chan = &csi[row].channels[chn];
dimm = EDAC_DIMM_PTR(layer, mci->dimms, n_layers,
pos[0], pos[1], pos[2]);
dimm->mci = mci;
debugf2("%s: %d: %s%zd (%d:%d:%d): row %d, chan %d\n", __func__,
i, per_rank ? "rank" : "dimm", (dimm - mci->dimms),
pos[0], pos[1], pos[2], row, chn);
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
INIT_LIST_HEAD(&mci->grp_kobj_list);
err = edac_mc_register_sysfs_main_kobj(mci);
if (err) {
kfree(mci);
return NULL;
}
return mci;
}
void edac_mc_free(struct mem_ctl_info *mci)
{
debugf1("%s()\n", __func__);
edac_mc_unregister_sysfs_main_kobj(mci);
kfree(mci);
}
struct mem_ctl_info *find_mci_by_dev(struct device *dev)
{
struct mem_ctl_info *mci;
struct list_head *item;
debugf3("%s()\n", __func__);
list_for_each(item, &mc_devices) {
mci = list_entry(item, struct mem_ctl_info, link);
if (mci->dev == dev)
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
debugf0("%s()\n", __func__);
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
debugf0("%s() not canceled, flush the queue\n",
__func__);
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
p = find_mci_by_dev(mci->dev);
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
"%s (%s) %s %s already assigned %d\n", dev_name(p->dev),
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
debugf0("%s()\n", __func__);
#ifdef CONFIG_EDAC_DEBUG
if (edac_debug_level >= 3)
edac_mc_dump_mci(mci);
if (edac_debug_level >= 4) {
int i;
for (i = 0; i < mci->nr_csrows; i++) {
int j;
edac_mc_dump_csrow(&mci->csrows[i]);
for (j = 0; j < mci->csrows[i].nr_channels; j++)
edac_mc_dump_channel(&mci->csrows[i].
channels[j]);
}
for (i = 0; i < mci->tot_dimms; i++)
edac_mc_dump_dimm(&mci->dimms[i]);
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
debugf0("%s()\n", __func__);
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
debugf3("%s()\n", __func__);
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
struct csrow_info *csrows = mci->csrows;
int row, i, j, n;
debugf1("MC%d: %s(): 0x%lx\n", mci->mc_idx, __func__, page);
row = -1;
for (i = 0; i < mci->nr_csrows; i++) {
struct csrow_info *csrow = &csrows[i];
n = 0;
for (j = 0; j < csrow->nr_channels; j++) {
struct dimm_info *dimm = csrow->channels[j].dimm;
n += dimm->nr_pages;
}
if (n == 0)
continue;
debugf3("MC%d: %s(): first(0x%lx) page(0x%lx) last(0x%lx) "
"mask(0x%lx)\n", mci->mc_idx, __func__,
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
const int pos[EDAC_MAX_LAYERS])
{
int i, index = 0;
mci->ce_mc++;
if (!enable_per_layer_report) {
mci->ce_noinfo_count++;
return;
}
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
break;
index += pos[i];
mci->ce_per_layer[i][index]++;
if (i < mci->n_layers - 1)
index *= mci->layers[i + 1].size;
}
}
static void edac_inc_ue_error(struct mem_ctl_info *mci,
bool enable_per_layer_report,
const int pos[EDAC_MAX_LAYERS])
{
int i, index = 0;
mci->ue_mc++;
if (!enable_per_layer_report) {
mci->ce_noinfo_count++;
return;
}
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
break;
index += pos[i];
mci->ue_per_layer[i][index]++;
if (i < mci->n_layers - 1)
index *= mci->layers[i + 1].size;
}
}
static void edac_ce_error(struct mem_ctl_info *mci,
const int pos[EDAC_MAX_LAYERS],
const char *msg,
const char *location,
const char *label,
const char *detail,
const char *other_detail,
const bool enable_per_layer_report,
const unsigned long page_frame_number,
const unsigned long offset_in_page,
u32 grain)
{
unsigned long remapped_page;
if (edac_mc_get_log_ce()) {
if (other_detail && *other_detail)
edac_mc_printk(mci, KERN_WARNING,
"CE %s on %s (%s%s - %s)\n",
msg, label, location,
detail, other_detail);
else
edac_mc_printk(mci, KERN_WARNING,
"CE %s on %s (%s%s)\n",
msg, label, location,
detail);
}
edac_inc_ce_error(mci, enable_per_layer_report, pos);
if (mci->scrub_mode & SCRUB_SW_SRC) {
remapped_page = mci->ctl_page_to_phys ?
mci->ctl_page_to_phys(mci, page_frame_number) :
page_frame_number;
edac_mc_scrub_block(remapped_page,
offset_in_page, grain);
}
}
static void edac_ue_error(struct mem_ctl_info *mci,
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
"UE %s on %s (%s%s - %s)\n",
msg, label, location, detail,
other_detail);
else
edac_mc_printk(mci, KERN_WARNING,
"UE %s on %s (%s%s)\n",
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
edac_inc_ue_error(mci, enable_per_layer_report, pos);
}
void edac_mc_handle_error(const enum hw_event_mc_err_type type,
struct mem_ctl_info *mci,
const unsigned long page_frame_number,
const unsigned long offset_in_page,
const unsigned long syndrome,
const int layer0,
const int layer1,
const int layer2,
const char *msg,
const char *other_detail,
const void *mcelog)
{
char detail[80], location[80];
char label[(EDAC_MC_LABEL_LEN + 1 + sizeof(OTHER_LABEL)) * mci->tot_dimms];
char *p;
int row = -1, chan = -1;
int pos[EDAC_MAX_LAYERS] = { layer0, layer1, layer2 };
int i;
u32 grain;
bool enable_per_layer_report = false;
debugf3("MC%d: %s()\n", mci->mc_idx, __func__);
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
struct dimm_info *dimm = &mci->dimms[i];
if (layer0 >= 0 && layer0 != dimm->location[0])
continue;
if (layer1 >= 0 && layer1 != dimm->location[1])
continue;
if (layer2 >= 0 && layer2 != dimm->location[2])
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
debugf4("%s: %s csrows map: (%d,%d)\n",
__func__,
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
debugf4("%s: csrow/channel to increment: (%d,%d)\n",
__func__, row, chan);
if (p == label)
strcpy(label, "unknown memory");
if (type == HW_EVENT_ERR_CORRECTED) {
if (row >= 0) {
mci->csrows[row].ce_count++;
if (chan >= 0)
mci->csrows[row].channels[chan].ce_count++;
}
} else
if (row >= 0)
mci->csrows[row].ue_count++;
}
p = location;
for (i = 0; i < mci->n_layers; i++) {
if (pos[i] < 0)
continue;
p += sprintf(p, "%s:%d ",
edac_layer_name[mci->layers[i].type],
pos[i]);
}
if (type == HW_EVENT_ERR_CORRECTED) {
snprintf(detail, sizeof(detail),
"page:0x%lx offset:0x%lx grain:%d syndrome:0x%lx",
page_frame_number, offset_in_page,
grain, syndrome);
edac_ce_error(mci, pos, msg, location, label, detail,
other_detail, enable_per_layer_report,
page_frame_number, offset_in_page, grain);
} else {
snprintf(detail, sizeof(detail),
"page:0x%lx offset:0x%lx grain:%d",
page_frame_number, offset_in_page, grain);
edac_ue_error(mci, pos, msg, location, label, detail,
other_detail, enable_per_layer_report);
}
}
