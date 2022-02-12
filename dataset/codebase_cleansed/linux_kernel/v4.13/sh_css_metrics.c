void
sh_css_metrics_start_frame(void)
{
sh_css_metrics.frame_metrics.num_frames++;
}
static void
clear_histogram(struct sh_css_pc_histogram *histogram)
{
unsigned i;
assert(histogram != NULL);
for (i = 0; i < histogram->length; i++) {
histogram->run[i] = 0;
histogram->stall[i] = 0;
histogram->msink[i] = 0xFFFF;
}
}
void
sh_css_metrics_enable_pc_histogram(bool enable)
{
pc_histogram_enabled = enable;
}
static void
make_histogram(struct sh_css_pc_histogram *histogram, unsigned length)
{
assert(histogram != NULL);
if (histogram->length)
return;
if (histogram->run)
return;
histogram->run = sh_css_malloc(length * sizeof(*histogram->run));
if (!histogram->run)
return;
histogram->stall = sh_css_malloc(length * sizeof(*histogram->stall));
if (!histogram->stall)
return;
histogram->msink = sh_css_malloc(length * sizeof(*histogram->msink));
if (!histogram->msink)
return;
histogram->length = length;
clear_histogram(histogram);
}
static void
insert_binary_metrics(struct sh_css_binary_metrics **l,
struct sh_css_binary_metrics *metrics)
{
assert(l != NULL);
assert(*l != NULL);
assert(metrics != NULL);
for (; *l; l = &(*l)->next)
if (*l == metrics)
return;
*l = metrics;
metrics->next = NULL;
}
void
sh_css_metrics_start_binary(struct sh_css_binary_metrics *metrics)
{
assert(metrics != NULL);
if (!pc_histogram_enabled)
return;
isp_histogram = &metrics->isp_histogram;
sp_histogram = &metrics->sp_histogram;
make_histogram(isp_histogram, ISP_PMEM_DEPTH);
make_histogram(sp_histogram, SP_PMEM_DEPTH);
insert_binary_metrics(&sh_css_metrics.binary_metrics, metrics);
}
void
sh_css_metrics_sample_pcs(void)
{
bool stall;
unsigned int pc;
unsigned int msink;
#if SUSPEND
unsigned int sc = 0;
unsigned int stopped_sc = 0;
unsigned int resume_sc = 0;
#endif
#if MULTIPLE_PCS
int i;
unsigned int pc_tab[NOF_PCS];
for (i = 0; i < NOF_PCS; i++)
pc_tab[i] = 0;
#endif
if (!pc_histogram_enabled)
return;
if (isp_histogram) {
#if SUSPEND
isp_ctrl_store(ISP0_ID, ISP_SC_REG, STOP_MASK);
#endif
msink = isp_ctrl_load(ISP0_ID, ISP_CTRL_SINK_REG);
#if MULTIPLE_PCS
for (i = 0; i < NOF_PCS; i++)
pc_tab[i] = isp_ctrl_load(ISP0_ID, ISP_PC_REG);
#else
pc = isp_ctrl_load(ISP0_ID, ISP_PC_REG);
#endif
#if SUSPEND
isp_ctrl_store(ISP0_ID, ISP_SC_REG, RESUME_MASK);
#endif
isp_histogram->msink[pc] &= msink;
stall = (msink != 0x7FF);
if (stall)
isp_histogram->stall[pc]++;
else
isp_histogram->run[pc]++;
}
if (sp_histogram && 0) {
msink = sp_ctrl_load(SP0_ID, SP_CTRL_SINK_REG);
pc = sp_ctrl_load(SP0_ID, SP_PC_REG);
sp_histogram->msink[pc] &= msink;
stall = (msink != 0x7FF);
if (stall)
sp_histogram->stall[pc]++;
else
sp_histogram->run[pc]++;
}
}
