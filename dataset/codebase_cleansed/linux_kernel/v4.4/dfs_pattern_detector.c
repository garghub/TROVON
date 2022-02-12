static const struct radar_types *
get_dfs_domain_radar_types(enum nl80211_dfs_regions region)
{
u32 i;
for (i = 0; i < ARRAY_SIZE(dfs_domains); i++) {
if (dfs_domains[i]->region == region)
return dfs_domains[i];
}
return NULL;
}
static void channel_detector_reset(struct dfs_pattern_detector *dpd,
struct channel_detector *cd)
{
u32 i;
if (cd == NULL)
return;
for (i = 0; i < dpd->num_radar_types; i++)
cd->detectors[i]->reset(cd->detectors[i], dpd->last_pulse_ts);
}
static void channel_detector_exit(struct dfs_pattern_detector *dpd,
struct channel_detector *cd)
{
u32 i;
if (cd == NULL)
return;
list_del(&cd->head);
for (i = 0; i < dpd->num_radar_types; i++) {
struct pri_detector *de = cd->detectors[i];
if (de != NULL)
de->exit(de);
}
kfree(cd->detectors);
kfree(cd);
}
static struct channel_detector *
channel_detector_create(struct dfs_pattern_detector *dpd, u16 freq)
{
u32 sz, i;
struct channel_detector *cd;
cd = kmalloc(sizeof(*cd), GFP_ATOMIC);
if (cd == NULL)
goto fail;
INIT_LIST_HEAD(&cd->head);
cd->freq = freq;
sz = sizeof(cd->detectors) * dpd->num_radar_types;
cd->detectors = kzalloc(sz, GFP_ATOMIC);
if (cd->detectors == NULL)
goto fail;
for (i = 0; i < dpd->num_radar_types; i++) {
const struct radar_detector_specs *rs = &dpd->radar_spec[i];
struct pri_detector *de = pri_detector_init(rs);
if (de == NULL)
goto fail;
cd->detectors[i] = de;
}
list_add(&cd->head, &dpd->channel_detectors);
return cd;
fail:
ath_dbg(dpd->common, DFS,
"failed to allocate channel_detector for freq=%d\n", freq);
channel_detector_exit(dpd, cd);
return NULL;
}
static struct channel_detector *
channel_detector_get(struct dfs_pattern_detector *dpd, u16 freq)
{
struct channel_detector *cd;
list_for_each_entry(cd, &dpd->channel_detectors, head) {
if (cd->freq == freq)
return cd;
}
return channel_detector_create(dpd, freq);
}
static void dpd_reset(struct dfs_pattern_detector *dpd)
{
struct channel_detector *cd;
if (!list_empty(&dpd->channel_detectors))
list_for_each_entry(cd, &dpd->channel_detectors, head)
channel_detector_reset(dpd, cd);
}
static void dpd_exit(struct dfs_pattern_detector *dpd)
{
struct channel_detector *cd, *cd0;
if (!list_empty(&dpd->channel_detectors))
list_for_each_entry_safe(cd, cd0, &dpd->channel_detectors, head)
channel_detector_exit(dpd, cd);
kfree(dpd);
}
static bool
dpd_add_pulse(struct dfs_pattern_detector *dpd, struct pulse_event *event)
{
u32 i;
struct channel_detector *cd;
if (dpd->region == NL80211_DFS_UNSET)
return true;
cd = channel_detector_get(dpd, event->freq);
if (cd == NULL)
return false;
if (event->ts < dpd->last_pulse_ts)
dpd_reset(dpd);
dpd->last_pulse_ts = event->ts;
for (i = 0; i < dpd->num_radar_types; i++) {
struct pri_detector *pd = cd->detectors[i];
struct pri_sequence *ps = pd->add_pulse(pd, event);
if (ps != NULL) {
ath_dbg(dpd->common, DFS,
"DFS: radar found on freq=%d: id=%d, pri=%d, "
"count=%d, count_false=%d\n",
event->freq, pd->rs->type_id,
ps->pri, ps->count, ps->count_falses);
pd->reset(pd, dpd->last_pulse_ts);
return true;
}
}
return false;
}
static struct ath_dfs_pool_stats
dpd_get_stats(struct dfs_pattern_detector *dpd)
{
return global_dfs_pool_stats;
}
static bool dpd_set_domain(struct dfs_pattern_detector *dpd,
enum nl80211_dfs_regions region)
{
const struct radar_types *rt;
struct channel_detector *cd, *cd0;
if (dpd->region == region)
return true;
dpd->region = NL80211_DFS_UNSET;
rt = get_dfs_domain_radar_types(region);
if (rt == NULL)
return false;
if (!list_empty(&dpd->channel_detectors))
list_for_each_entry_safe(cd, cd0, &dpd->channel_detectors, head)
channel_detector_exit(dpd, cd);
dpd->radar_spec = rt->radar_types;
dpd->num_radar_types = rt->num_radar_types;
dpd->region = region;
return true;
}
struct dfs_pattern_detector *
dfs_pattern_detector_init(struct ath_common *common,
enum nl80211_dfs_regions region)
{
struct dfs_pattern_detector *dpd;
if (!config_enabled(CONFIG_CFG80211_CERTIFICATION_ONUS))
return NULL;
dpd = kmalloc(sizeof(*dpd), GFP_KERNEL);
if (dpd == NULL)
return NULL;
*dpd = default_dpd;
INIT_LIST_HEAD(&dpd->channel_detectors);
dpd->common = common;
if (dpd->set_dfs_domain(dpd, region))
return dpd;
ath_dbg(common, DFS,"Could not set DFS domain to %d", region);
kfree(dpd);
return NULL;
}
