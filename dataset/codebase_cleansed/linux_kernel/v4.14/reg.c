static const struct ieee80211_regdomain *get_cfg80211_regdom(void)
{
return rtnl_dereference(cfg80211_regdomain);
}
const struct ieee80211_regdomain *get_wiphy_regdom(struct wiphy *wiphy)
{
return rtnl_dereference(wiphy->regd);
}
static const char *reg_dfs_region_str(enum nl80211_dfs_regions dfs_region)
{
switch (dfs_region) {
case NL80211_DFS_UNSET:
return "unset";
case NL80211_DFS_FCC:
return "FCC";
case NL80211_DFS_ETSI:
return "ETSI";
case NL80211_DFS_JP:
return "JP";
}
return "Unknown";
}
enum nl80211_dfs_regions reg_get_dfs_region(struct wiphy *wiphy)
{
const struct ieee80211_regdomain *regd = NULL;
const struct ieee80211_regdomain *wiphy_regd = NULL;
regd = get_cfg80211_regdom();
if (!wiphy)
goto out;
wiphy_regd = get_wiphy_regdom(wiphy);
if (!wiphy_regd)
goto out;
if (wiphy_regd->dfs_region == regd->dfs_region)
goto out;
pr_debug("%s: device specific dfs_region (%s) disagrees with cfg80211's central dfs_region (%s)\n",
dev_name(&wiphy->dev),
reg_dfs_region_str(wiphy_regd->dfs_region),
reg_dfs_region_str(regd->dfs_region));
out:
return regd->dfs_region;
}
static void rcu_free_regdom(const struct ieee80211_regdomain *r)
{
if (!r)
return;
kfree_rcu((struct ieee80211_regdomain *)r, rcu_head);
}
static struct regulatory_request *get_last_request(void)
{
return rcu_dereference_rtnl(last_request);
}
static void reg_free_request(struct regulatory_request *request)
{
if (request == &core_request_world)
return;
if (request != get_last_request())
kfree(request);
}
static void reg_free_last_request(void)
{
struct regulatory_request *lr = get_last_request();
if (lr != &core_request_world && lr)
kfree_rcu(lr, rcu_head);
}
static void reg_update_last_request(struct regulatory_request *request)
{
struct regulatory_request *lr;
lr = get_last_request();
if (lr == request)
return;
reg_free_last_request();
rcu_assign_pointer(last_request, request);
}
static void reset_regdomains(bool full_reset,
const struct ieee80211_regdomain *new_regdom)
{
const struct ieee80211_regdomain *r;
ASSERT_RTNL();
r = get_cfg80211_regdom();
if (r == cfg80211_world_regdom)
r = NULL;
if (cfg80211_world_regdom == &world_regdom)
cfg80211_world_regdom = NULL;
if (r == &world_regdom)
r = NULL;
rcu_free_regdom(r);
rcu_free_regdom(cfg80211_world_regdom);
cfg80211_world_regdom = &world_regdom;
rcu_assign_pointer(cfg80211_regdomain, new_regdom);
if (!full_reset)
return;
reg_update_last_request(&core_request_world);
}
static void update_world_regdomain(const struct ieee80211_regdomain *rd)
{
struct regulatory_request *lr;
lr = get_last_request();
WARN_ON(!lr);
reset_regdomains(false, rd);
cfg80211_world_regdom = rd;
}
bool is_world_regdom(const char *alpha2)
{
if (!alpha2)
return false;
return alpha2[0] == '0' && alpha2[1] == '0';
}
static bool is_alpha2_set(const char *alpha2)
{
if (!alpha2)
return false;
return alpha2[0] && alpha2[1];
}
static bool is_unknown_alpha2(const char *alpha2)
{
if (!alpha2)
return false;
return alpha2[0] == '9' && alpha2[1] == '9';
}
static bool is_intersected_alpha2(const char *alpha2)
{
if (!alpha2)
return false;
return alpha2[0] == '9' && alpha2[1] == '8';
}
static bool is_an_alpha2(const char *alpha2)
{
if (!alpha2)
return false;
return isalpha(alpha2[0]) && isalpha(alpha2[1]);
}
static bool alpha2_equal(const char *alpha2_x, const char *alpha2_y)
{
if (!alpha2_x || !alpha2_y)
return false;
return alpha2_x[0] == alpha2_y[0] && alpha2_x[1] == alpha2_y[1];
}
static bool regdom_changes(const char *alpha2)
{
const struct ieee80211_regdomain *r = get_cfg80211_regdom();
if (!r)
return true;
return !alpha2_equal(r->alpha2, alpha2);
}
static bool is_user_regdom_saved(void)
{
if (user_alpha2[0] == '9' && user_alpha2[1] == '7')
return false;
if (WARN(!is_world_regdom(user_alpha2) && !is_an_alpha2(user_alpha2),
"Unexpected user alpha2: %c%c\n",
user_alpha2[0], user_alpha2[1]))
return false;
return true;
}
static const struct ieee80211_regdomain *
reg_copy_regd(const struct ieee80211_regdomain *src_regd)
{
struct ieee80211_regdomain *regd;
int size_of_regd;
unsigned int i;
size_of_regd =
sizeof(struct ieee80211_regdomain) +
src_regd->n_reg_rules * sizeof(struct ieee80211_reg_rule);
regd = kzalloc(size_of_regd, GFP_KERNEL);
if (!regd)
return ERR_PTR(-ENOMEM);
memcpy(regd, src_regd, sizeof(struct ieee80211_regdomain));
for (i = 0; i < src_regd->n_reg_rules; i++)
memcpy(&regd->reg_rules[i], &src_regd->reg_rules[i],
sizeof(struct ieee80211_reg_rule));
return regd;
}
static void reg_regdb_apply(struct work_struct *work)
{
struct reg_regdb_apply_request *request;
rtnl_lock();
mutex_lock(&reg_regdb_apply_mutex);
while (!list_empty(&reg_regdb_apply_list)) {
request = list_first_entry(&reg_regdb_apply_list,
struct reg_regdb_apply_request,
list);
list_del(&request->list);
set_regdom(request->regdom, REGD_SOURCE_INTERNAL_DB);
kfree(request);
}
mutex_unlock(&reg_regdb_apply_mutex);
rtnl_unlock();
}
static int reg_query_builtin(const char *alpha2)
{
const struct ieee80211_regdomain *regdom = NULL;
struct reg_regdb_apply_request *request;
unsigned int i;
for (i = 0; i < reg_regdb_size; i++) {
if (alpha2_equal(alpha2, reg_regdb[i]->alpha2)) {
regdom = reg_regdb[i];
break;
}
}
if (!regdom)
return -ENODATA;
request = kzalloc(sizeof(struct reg_regdb_apply_request), GFP_KERNEL);
if (!request)
return -ENOMEM;
request->regdom = reg_copy_regd(regdom);
if (IS_ERR_OR_NULL(request->regdom)) {
kfree(request);
return -ENOMEM;
}
mutex_lock(&reg_regdb_apply_mutex);
list_add_tail(&request->list, &reg_regdb_apply_list);
mutex_unlock(&reg_regdb_apply_mutex);
schedule_work(&reg_regdb_work);
return 0;
}
static void reg_regdb_size_check(void)
{
WARN_ONCE(!reg_regdb_size, "db.txt is empty, you should update it...");
}
static inline void reg_regdb_size_check(void) {}
static inline int reg_query_builtin(const char *alpha2)
{
return -ENODATA;
}
static void crda_timeout_work(struct work_struct *work)
{
pr_debug("Timeout while waiting for CRDA to reply, restoring regulatory settings\n");
rtnl_lock();
reg_crda_timeouts++;
restore_regulatory_settings(true);
rtnl_unlock();
}
static void cancel_crda_timeout(void)
{
cancel_delayed_work(&crda_timeout);
}
static void cancel_crda_timeout_sync(void)
{
cancel_delayed_work_sync(&crda_timeout);
}
static void reset_crda_timeouts(void)
{
reg_crda_timeouts = 0;
}
static int call_crda(const char *alpha2)
{
char country[12];
char *env[] = { country, NULL };
int ret;
snprintf(country, sizeof(country), "COUNTRY=%c%c",
alpha2[0], alpha2[1]);
if (reg_crda_timeouts > REG_MAX_CRDA_TIMEOUTS) {
pr_debug("Exceeded CRDA call max attempts. Not calling CRDA\n");
return -EINVAL;
}
if (!is_world_regdom((char *) alpha2))
pr_debug("Calling CRDA for country: %c%c\n",
alpha2[0], alpha2[1]);
else
pr_debug("Calling CRDA to update world regulatory domain\n");
ret = kobject_uevent_env(&reg_pdev->dev.kobj, KOBJ_CHANGE, env);
if (ret)
return ret;
queue_delayed_work(system_power_efficient_wq,
&crda_timeout, msecs_to_jiffies(3142));
return 0;
}
static inline void cancel_crda_timeout(void) {}
static inline void cancel_crda_timeout_sync(void) {}
static inline void reset_crda_timeouts(void) {}
static inline int call_crda(const char *alpha2)
{
return -ENODATA;
}
static bool reg_query_database(struct regulatory_request *request)
{
if (reg_query_builtin(request->alpha2) == 0)
return true;
if (call_crda(request->alpha2) == 0)
return true;
return false;
}
bool reg_is_valid_request(const char *alpha2)
{
struct regulatory_request *lr = get_last_request();
if (!lr || lr->processed)
return false;
return alpha2_equal(lr->alpha2, alpha2);
}
static const struct ieee80211_regdomain *reg_get_regdomain(struct wiphy *wiphy)
{
struct regulatory_request *lr = get_last_request();
if (lr->initiator != NL80211_REGDOM_SET_BY_COUNTRY_IE &&
lr->initiator != NL80211_REGDOM_SET_BY_USER &&
wiphy->regd)
return get_wiphy_regdom(wiphy);
return get_cfg80211_regdom();
}
static unsigned int
reg_get_max_bandwidth_from_range(const struct ieee80211_regdomain *rd,
const struct ieee80211_reg_rule *rule)
{
const struct ieee80211_freq_range *freq_range = &rule->freq_range;
const struct ieee80211_freq_range *freq_range_tmp;
const struct ieee80211_reg_rule *tmp;
u32 start_freq, end_freq, idx, no;
for (idx = 0; idx < rd->n_reg_rules; idx++)
if (rule == &rd->reg_rules[idx])
break;
if (idx == rd->n_reg_rules)
return 0;
no = idx;
while (no) {
tmp = &rd->reg_rules[--no];
freq_range_tmp = &tmp->freq_range;
if (freq_range_tmp->end_freq_khz < freq_range->start_freq_khz)
break;
freq_range = freq_range_tmp;
}
start_freq = freq_range->start_freq_khz;
freq_range = &rule->freq_range;
no = idx;
while (no < rd->n_reg_rules - 1) {
tmp = &rd->reg_rules[++no];
freq_range_tmp = &tmp->freq_range;
if (freq_range_tmp->start_freq_khz > freq_range->end_freq_khz)
break;
freq_range = freq_range_tmp;
}
end_freq = freq_range->end_freq_khz;
return end_freq - start_freq;
}
unsigned int reg_get_max_bandwidth(const struct ieee80211_regdomain *rd,
const struct ieee80211_reg_rule *rule)
{
unsigned int bw = reg_get_max_bandwidth_from_range(rd, rule);
if (rule->flags & NL80211_RRF_NO_160MHZ)
bw = min_t(unsigned int, bw, MHZ_TO_KHZ(80));
if (rule->flags & NL80211_RRF_NO_80MHZ)
bw = min_t(unsigned int, bw, MHZ_TO_KHZ(40));
if (rule->flags & NL80211_RRF_NO_HT40MINUS &&
rule->flags & NL80211_RRF_NO_HT40PLUS)
bw = min_t(unsigned int, bw, MHZ_TO_KHZ(20));
return bw;
}
static bool is_valid_reg_rule(const struct ieee80211_reg_rule *rule)
{
const struct ieee80211_freq_range *freq_range = &rule->freq_range;
u32 freq_diff;
if (freq_range->start_freq_khz <= 0 || freq_range->end_freq_khz <= 0)
return false;
if (freq_range->start_freq_khz > freq_range->end_freq_khz)
return false;
freq_diff = freq_range->end_freq_khz - freq_range->start_freq_khz;
if (freq_range->end_freq_khz <= freq_range->start_freq_khz ||
freq_range->max_bandwidth_khz > freq_diff)
return false;
return true;
}
static bool is_valid_rd(const struct ieee80211_regdomain *rd)
{
const struct ieee80211_reg_rule *reg_rule = NULL;
unsigned int i;
if (!rd->n_reg_rules)
return false;
if (WARN_ON(rd->n_reg_rules > NL80211_MAX_SUPP_REG_RULES))
return false;
for (i = 0; i < rd->n_reg_rules; i++) {
reg_rule = &rd->reg_rules[i];
if (!is_valid_reg_rule(reg_rule))
return false;
}
return true;
}
static bool freq_in_rule_band(const struct ieee80211_freq_range *freq_range,
u32 freq_khz)
{
#define ONE_GHZ_IN_KHZ 1000000
u32 limit = freq_khz > 45 * ONE_GHZ_IN_KHZ ?
10 * ONE_GHZ_IN_KHZ : 2 * ONE_GHZ_IN_KHZ;
if (abs(freq_khz - freq_range->start_freq_khz) <= limit)
return true;
if (abs(freq_khz - freq_range->end_freq_khz) <= limit)
return true;
return false;
#undef ONE_GHZ_IN_KHZ
}
static enum nl80211_dfs_regions
reg_intersect_dfs_region(const enum nl80211_dfs_regions dfs_region1,
const enum nl80211_dfs_regions dfs_region2)
{
if (dfs_region1 != dfs_region2)
return NL80211_DFS_UNSET;
return dfs_region1;
}
static int reg_rules_intersect(const struct ieee80211_regdomain *rd1,
const struct ieee80211_regdomain *rd2,
const struct ieee80211_reg_rule *rule1,
const struct ieee80211_reg_rule *rule2,
struct ieee80211_reg_rule *intersected_rule)
{
const struct ieee80211_freq_range *freq_range1, *freq_range2;
struct ieee80211_freq_range *freq_range;
const struct ieee80211_power_rule *power_rule1, *power_rule2;
struct ieee80211_power_rule *power_rule;
u32 freq_diff, max_bandwidth1, max_bandwidth2;
freq_range1 = &rule1->freq_range;
freq_range2 = &rule2->freq_range;
freq_range = &intersected_rule->freq_range;
power_rule1 = &rule1->power_rule;
power_rule2 = &rule2->power_rule;
power_rule = &intersected_rule->power_rule;
freq_range->start_freq_khz = max(freq_range1->start_freq_khz,
freq_range2->start_freq_khz);
freq_range->end_freq_khz = min(freq_range1->end_freq_khz,
freq_range2->end_freq_khz);
max_bandwidth1 = freq_range1->max_bandwidth_khz;
max_bandwidth2 = freq_range2->max_bandwidth_khz;
if (rule1->flags & NL80211_RRF_AUTO_BW)
max_bandwidth1 = reg_get_max_bandwidth(rd1, rule1);
if (rule2->flags & NL80211_RRF_AUTO_BW)
max_bandwidth2 = reg_get_max_bandwidth(rd2, rule2);
freq_range->max_bandwidth_khz = min(max_bandwidth1, max_bandwidth2);
intersected_rule->flags = rule1->flags | rule2->flags;
if ((rule1->flags & NL80211_RRF_AUTO_BW) &&
(rule2->flags & NL80211_RRF_AUTO_BW))
intersected_rule->flags |= NL80211_RRF_AUTO_BW;
else
intersected_rule->flags &= ~NL80211_RRF_AUTO_BW;
freq_diff = freq_range->end_freq_khz - freq_range->start_freq_khz;
if (freq_range->max_bandwidth_khz > freq_diff)
freq_range->max_bandwidth_khz = freq_diff;
power_rule->max_eirp = min(power_rule1->max_eirp,
power_rule2->max_eirp);
power_rule->max_antenna_gain = min(power_rule1->max_antenna_gain,
power_rule2->max_antenna_gain);
intersected_rule->dfs_cac_ms = max(rule1->dfs_cac_ms,
rule2->dfs_cac_ms);
if (!is_valid_reg_rule(intersected_rule))
return -EINVAL;
return 0;
}
static bool rule_contains(struct ieee80211_reg_rule *r1,
struct ieee80211_reg_rule *r2)
{
if (r1->flags != r2->flags)
return false;
if ((r1->power_rule.max_antenna_gain >
r2->power_rule.max_antenna_gain) ||
r1->power_rule.max_eirp > r2->power_rule.max_eirp)
return false;
if (r1->freq_range.start_freq_khz > r2->freq_range.start_freq_khz ||
r1->freq_range.end_freq_khz < r2->freq_range.end_freq_khz)
return false;
if (r1->freq_range.max_bandwidth_khz <
r2->freq_range.max_bandwidth_khz)
return false;
return true;
}
static void add_rule(struct ieee80211_reg_rule *rule,
struct ieee80211_reg_rule *reg_rules, u32 *n_rules)
{
struct ieee80211_reg_rule *tmp_rule;
int i;
for (i = 0; i < *n_rules; i++) {
tmp_rule = &reg_rules[i];
if (rule_contains(tmp_rule, rule))
return;
if (rule_contains(rule, tmp_rule)) {
memcpy(tmp_rule, rule, sizeof(*rule));
return;
}
}
memcpy(&reg_rules[*n_rules], rule, sizeof(*rule));
(*n_rules)++;
}
static struct ieee80211_regdomain *
regdom_intersect(const struct ieee80211_regdomain *rd1,
const struct ieee80211_regdomain *rd2)
{
int r, size_of_regd;
unsigned int x, y;
unsigned int num_rules = 0;
const struct ieee80211_reg_rule *rule1, *rule2;
struct ieee80211_reg_rule intersected_rule;
struct ieee80211_regdomain *rd;
if (!rd1 || !rd2)
return NULL;
for (x = 0; x < rd1->n_reg_rules; x++) {
rule1 = &rd1->reg_rules[x];
for (y = 0; y < rd2->n_reg_rules; y++) {
rule2 = &rd2->reg_rules[y];
if (!reg_rules_intersect(rd1, rd2, rule1, rule2,
&intersected_rule))
num_rules++;
}
}
if (!num_rules)
return NULL;
size_of_regd = sizeof(struct ieee80211_regdomain) +
num_rules * sizeof(struct ieee80211_reg_rule);
rd = kzalloc(size_of_regd, GFP_KERNEL);
if (!rd)
return NULL;
for (x = 0; x < rd1->n_reg_rules; x++) {
rule1 = &rd1->reg_rules[x];
for (y = 0; y < rd2->n_reg_rules; y++) {
rule2 = &rd2->reg_rules[y];
r = reg_rules_intersect(rd1, rd2, rule1, rule2,
&intersected_rule);
if (r)
continue;
add_rule(&intersected_rule, rd->reg_rules,
&rd->n_reg_rules);
}
}
rd->alpha2[0] = '9';
rd->alpha2[1] = '8';
rd->dfs_region = reg_intersect_dfs_region(rd1->dfs_region,
rd2->dfs_region);
return rd;
}
static u32 map_regdom_flags(u32 rd_flags)
{
u32 channel_flags = 0;
if (rd_flags & NL80211_RRF_NO_IR_ALL)
channel_flags |= IEEE80211_CHAN_NO_IR;
if (rd_flags & NL80211_RRF_DFS)
channel_flags |= IEEE80211_CHAN_RADAR;
if (rd_flags & NL80211_RRF_NO_OFDM)
channel_flags |= IEEE80211_CHAN_NO_OFDM;
if (rd_flags & NL80211_RRF_NO_OUTDOOR)
channel_flags |= IEEE80211_CHAN_INDOOR_ONLY;
if (rd_flags & NL80211_RRF_IR_CONCURRENT)
channel_flags |= IEEE80211_CHAN_IR_CONCURRENT;
if (rd_flags & NL80211_RRF_NO_HT40MINUS)
channel_flags |= IEEE80211_CHAN_NO_HT40MINUS;
if (rd_flags & NL80211_RRF_NO_HT40PLUS)
channel_flags |= IEEE80211_CHAN_NO_HT40PLUS;
if (rd_flags & NL80211_RRF_NO_80MHZ)
channel_flags |= IEEE80211_CHAN_NO_80MHZ;
if (rd_flags & NL80211_RRF_NO_160MHZ)
channel_flags |= IEEE80211_CHAN_NO_160MHZ;
return channel_flags;
}
static const struct ieee80211_reg_rule *
freq_reg_info_regd(u32 center_freq,
const struct ieee80211_regdomain *regd, u32 bw)
{
int i;
bool band_rule_found = false;
bool bw_fits = false;
if (!regd)
return ERR_PTR(-EINVAL);
for (i = 0; i < regd->n_reg_rules; i++) {
const struct ieee80211_reg_rule *rr;
const struct ieee80211_freq_range *fr = NULL;
rr = &regd->reg_rules[i];
fr = &rr->freq_range;
if (!band_rule_found)
band_rule_found = freq_in_rule_band(fr, center_freq);
bw_fits = cfg80211_does_bw_fit_range(fr, center_freq, bw);
if (band_rule_found && bw_fits)
return rr;
}
if (!band_rule_found)
return ERR_PTR(-ERANGE);
return ERR_PTR(-EINVAL);
}
static const struct ieee80211_reg_rule *
__freq_reg_info(struct wiphy *wiphy, u32 center_freq, u32 min_bw)
{
const struct ieee80211_regdomain *regd = reg_get_regdomain(wiphy);
const struct ieee80211_reg_rule *reg_rule = NULL;
u32 bw;
for (bw = MHZ_TO_KHZ(20); bw >= min_bw; bw = bw / 2) {
reg_rule = freq_reg_info_regd(center_freq, regd, bw);
if (!IS_ERR(reg_rule))
return reg_rule;
}
return reg_rule;
}
const struct ieee80211_reg_rule *freq_reg_info(struct wiphy *wiphy,
u32 center_freq)
{
return __freq_reg_info(wiphy, center_freq, MHZ_TO_KHZ(20));
}
const char *reg_initiator_name(enum nl80211_reg_initiator initiator)
{
switch (initiator) {
case NL80211_REGDOM_SET_BY_CORE:
return "core";
case NL80211_REGDOM_SET_BY_USER:
return "user";
case NL80211_REGDOM_SET_BY_DRIVER:
return "driver";
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
return "country IE";
default:
WARN_ON(1);
return "bug";
}
}
static uint32_t reg_rule_to_chan_bw_flags(const struct ieee80211_regdomain *regd,
const struct ieee80211_reg_rule *reg_rule,
const struct ieee80211_channel *chan)
{
const struct ieee80211_freq_range *freq_range = NULL;
u32 max_bandwidth_khz, bw_flags = 0;
freq_range = &reg_rule->freq_range;
max_bandwidth_khz = freq_range->max_bandwidth_khz;
if (reg_rule->flags & NL80211_RRF_AUTO_BW)
max_bandwidth_khz = reg_get_max_bandwidth(regd, reg_rule);
if (!cfg80211_does_bw_fit_range(freq_range,
MHZ_TO_KHZ(chan->center_freq),
MHZ_TO_KHZ(10)))
bw_flags |= IEEE80211_CHAN_NO_10MHZ;
if (!cfg80211_does_bw_fit_range(freq_range,
MHZ_TO_KHZ(chan->center_freq),
MHZ_TO_KHZ(20)))
bw_flags |= IEEE80211_CHAN_NO_20MHZ;
if (max_bandwidth_khz < MHZ_TO_KHZ(10))
bw_flags |= IEEE80211_CHAN_NO_10MHZ;
if (max_bandwidth_khz < MHZ_TO_KHZ(20))
bw_flags |= IEEE80211_CHAN_NO_20MHZ;
if (max_bandwidth_khz < MHZ_TO_KHZ(40))
bw_flags |= IEEE80211_CHAN_NO_HT40;
if (max_bandwidth_khz < MHZ_TO_KHZ(80))
bw_flags |= IEEE80211_CHAN_NO_80MHZ;
if (max_bandwidth_khz < MHZ_TO_KHZ(160))
bw_flags |= IEEE80211_CHAN_NO_160MHZ;
return bw_flags;
}
static void handle_channel(struct wiphy *wiphy,
enum nl80211_reg_initiator initiator,
struct ieee80211_channel *chan)
{
u32 flags, bw_flags = 0;
const struct ieee80211_reg_rule *reg_rule = NULL;
const struct ieee80211_power_rule *power_rule = NULL;
struct wiphy *request_wiphy = NULL;
struct regulatory_request *lr = get_last_request();
const struct ieee80211_regdomain *regd;
request_wiphy = wiphy_idx_to_wiphy(lr->wiphy_idx);
flags = chan->orig_flags;
reg_rule = freq_reg_info(wiphy, MHZ_TO_KHZ(chan->center_freq));
if (IS_ERR(reg_rule)) {
if (initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE &&
PTR_ERR(reg_rule) == -ERANGE)
return;
if (lr->initiator == NL80211_REGDOM_SET_BY_DRIVER &&
request_wiphy && request_wiphy == wiphy &&
request_wiphy->regulatory_flags & REGULATORY_STRICT_REG) {
pr_debug("Disabling freq %d MHz for good\n",
chan->center_freq);
chan->orig_flags |= IEEE80211_CHAN_DISABLED;
chan->flags = chan->orig_flags;
} else {
pr_debug("Disabling freq %d MHz\n",
chan->center_freq);
chan->flags |= IEEE80211_CHAN_DISABLED;
}
return;
}
regd = reg_get_regdomain(wiphy);
power_rule = &reg_rule->power_rule;
bw_flags = reg_rule_to_chan_bw_flags(regd, reg_rule, chan);
if (lr->initiator == NL80211_REGDOM_SET_BY_DRIVER &&
request_wiphy && request_wiphy == wiphy &&
request_wiphy->regulatory_flags & REGULATORY_STRICT_REG) {
chan->flags = chan->orig_flags =
map_regdom_flags(reg_rule->flags) | bw_flags;
chan->max_antenna_gain = chan->orig_mag =
(int) MBI_TO_DBI(power_rule->max_antenna_gain);
chan->max_reg_power = chan->max_power = chan->orig_mpwr =
(int) MBM_TO_DBM(power_rule->max_eirp);
if (chan->flags & IEEE80211_CHAN_RADAR) {
chan->dfs_cac_ms = IEEE80211_DFS_MIN_CAC_TIME_MS;
if (reg_rule->dfs_cac_ms)
chan->dfs_cac_ms = reg_rule->dfs_cac_ms;
}
return;
}
chan->dfs_state = NL80211_DFS_USABLE;
chan->dfs_state_entered = jiffies;
chan->beacon_found = false;
chan->flags = flags | bw_flags | map_regdom_flags(reg_rule->flags);
chan->max_antenna_gain =
min_t(int, chan->orig_mag,
MBI_TO_DBI(power_rule->max_antenna_gain));
chan->max_reg_power = (int) MBM_TO_DBM(power_rule->max_eirp);
if (chan->flags & IEEE80211_CHAN_RADAR) {
if (reg_rule->dfs_cac_ms)
chan->dfs_cac_ms = reg_rule->dfs_cac_ms;
else
chan->dfs_cac_ms = IEEE80211_DFS_MIN_CAC_TIME_MS;
}
if (chan->orig_mpwr) {
if (initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE &&
wiphy->regulatory_flags & REGULATORY_COUNTRY_IE_FOLLOW_POWER)
chan->max_power = chan->max_reg_power;
else
chan->max_power = min(chan->orig_mpwr,
chan->max_reg_power);
} else
chan->max_power = chan->max_reg_power;
}
static void handle_band(struct wiphy *wiphy,
enum nl80211_reg_initiator initiator,
struct ieee80211_supported_band *sband)
{
unsigned int i;
if (!sband)
return;
for (i = 0; i < sband->n_channels; i++)
handle_channel(wiphy, initiator, &sband->channels[i]);
}
static bool reg_request_cell_base(struct regulatory_request *request)
{
if (request->initiator != NL80211_REGDOM_SET_BY_USER)
return false;
return request->user_reg_hint_type == NL80211_USER_REG_HINT_CELL_BASE;
}
bool reg_last_request_cell_base(void)
{
return reg_request_cell_base(get_last_request());
}
static enum reg_request_treatment
reg_ignore_cell_hint(struct regulatory_request *pending_request)
{
struct regulatory_request *lr = get_last_request();
if (!reg_num_devs_support_basehint)
return REG_REQ_IGNORE;
if (reg_request_cell_base(lr) &&
!regdom_changes(pending_request->alpha2))
return REG_REQ_ALREADY_SET;
return REG_REQ_OK;
}
static bool reg_dev_ignore_cell_hint(struct wiphy *wiphy)
{
return !(wiphy->features & NL80211_FEATURE_CELL_BASE_REG_HINTS);
}
static enum reg_request_treatment
reg_ignore_cell_hint(struct regulatory_request *pending_request)
{
return REG_REQ_IGNORE;
}
static bool reg_dev_ignore_cell_hint(struct wiphy *wiphy)
{
return true;
}
static bool wiphy_strict_alpha2_regd(struct wiphy *wiphy)
{
if (wiphy->regulatory_flags & REGULATORY_STRICT_REG &&
!(wiphy->regulatory_flags & REGULATORY_CUSTOM_REG))
return true;
return false;
}
static bool ignore_reg_update(struct wiphy *wiphy,
enum nl80211_reg_initiator initiator)
{
struct regulatory_request *lr = get_last_request();
if (wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED)
return true;
if (!lr) {
pr_debug("Ignoring regulatory request set by %s since last_request is not set\n",
reg_initiator_name(initiator));
return true;
}
if (initiator == NL80211_REGDOM_SET_BY_CORE &&
wiphy->regulatory_flags & REGULATORY_CUSTOM_REG) {
pr_debug("Ignoring regulatory request set by %s since the driver uses its own custom regulatory domain\n",
reg_initiator_name(initiator));
return true;
}
if (wiphy_strict_alpha2_regd(wiphy) && !wiphy->regd &&
initiator != NL80211_REGDOM_SET_BY_COUNTRY_IE &&
!is_world_regdom(lr->alpha2)) {
pr_debug("Ignoring regulatory request set by %s since the driver requires its own regulatory domain to be set first\n",
reg_initiator_name(initiator));
return true;
}
if (reg_request_cell_base(lr))
return reg_dev_ignore_cell_hint(wiphy);
return false;
}
static bool reg_is_world_roaming(struct wiphy *wiphy)
{
const struct ieee80211_regdomain *cr = get_cfg80211_regdom();
const struct ieee80211_regdomain *wr = get_wiphy_regdom(wiphy);
struct regulatory_request *lr = get_last_request();
if (is_world_regdom(cr->alpha2) || (wr && is_world_regdom(wr->alpha2)))
return true;
if (lr && lr->initiator != NL80211_REGDOM_SET_BY_COUNTRY_IE &&
wiphy->regulatory_flags & REGULATORY_CUSTOM_REG)
return true;
return false;
}
static void handle_reg_beacon(struct wiphy *wiphy, unsigned int chan_idx,
struct reg_beacon *reg_beacon)
{
struct ieee80211_supported_band *sband;
struct ieee80211_channel *chan;
bool channel_changed = false;
struct ieee80211_channel chan_before;
sband = wiphy->bands[reg_beacon->chan.band];
chan = &sband->channels[chan_idx];
if (likely(chan->center_freq != reg_beacon->chan.center_freq))
return;
if (chan->beacon_found)
return;
chan->beacon_found = true;
if (!reg_is_world_roaming(wiphy))
return;
if (wiphy->regulatory_flags & REGULATORY_DISABLE_BEACON_HINTS)
return;
chan_before.center_freq = chan->center_freq;
chan_before.flags = chan->flags;
if (chan->flags & IEEE80211_CHAN_NO_IR) {
chan->flags &= ~IEEE80211_CHAN_NO_IR;
channel_changed = true;
}
if (channel_changed)
nl80211_send_beacon_hint_event(wiphy, &chan_before, chan);
}
static void wiphy_update_new_beacon(struct wiphy *wiphy,
struct reg_beacon *reg_beacon)
{
unsigned int i;
struct ieee80211_supported_band *sband;
if (!wiphy->bands[reg_beacon->chan.band])
return;
sband = wiphy->bands[reg_beacon->chan.band];
for (i = 0; i < sband->n_channels; i++)
handle_reg_beacon(wiphy, i, reg_beacon);
}
static void wiphy_update_beacon_reg(struct wiphy *wiphy)
{
unsigned int i;
struct ieee80211_supported_band *sband;
struct reg_beacon *reg_beacon;
list_for_each_entry(reg_beacon, &reg_beacon_list, list) {
if (!wiphy->bands[reg_beacon->chan.band])
continue;
sband = wiphy->bands[reg_beacon->chan.band];
for (i = 0; i < sband->n_channels; i++)
handle_reg_beacon(wiphy, i, reg_beacon);
}
}
static void reg_process_beacons(struct wiphy *wiphy)
{
if (!last_request)
return;
wiphy_update_beacon_reg(wiphy);
}
static bool is_ht40_allowed(struct ieee80211_channel *chan)
{
if (!chan)
return false;
if (chan->flags & IEEE80211_CHAN_DISABLED)
return false;
if ((chan->flags & IEEE80211_CHAN_NO_HT40) == IEEE80211_CHAN_NO_HT40)
return false;
return true;
}
static void reg_process_ht_flags_channel(struct wiphy *wiphy,
struct ieee80211_channel *channel)
{
struct ieee80211_supported_band *sband = wiphy->bands[channel->band];
struct ieee80211_channel *channel_before = NULL, *channel_after = NULL;
const struct ieee80211_regdomain *regd;
unsigned int i;
u32 flags;
if (!is_ht40_allowed(channel)) {
channel->flags |= IEEE80211_CHAN_NO_HT40;
return;
}
for (i = 0; i < sband->n_channels; i++) {
struct ieee80211_channel *c = &sband->channels[i];
if (c->center_freq == (channel->center_freq - 20))
channel_before = c;
if (c->center_freq == (channel->center_freq + 20))
channel_after = c;
}
flags = 0;
regd = get_wiphy_regdom(wiphy);
if (regd) {
const struct ieee80211_reg_rule *reg_rule =
freq_reg_info_regd(MHZ_TO_KHZ(channel->center_freq),
regd, MHZ_TO_KHZ(20));
if (!IS_ERR(reg_rule))
flags = reg_rule->flags;
}
if (!is_ht40_allowed(channel_before) ||
flags & NL80211_RRF_NO_HT40MINUS)
channel->flags |= IEEE80211_CHAN_NO_HT40MINUS;
else
channel->flags &= ~IEEE80211_CHAN_NO_HT40MINUS;
if (!is_ht40_allowed(channel_after) ||
flags & NL80211_RRF_NO_HT40PLUS)
channel->flags |= IEEE80211_CHAN_NO_HT40PLUS;
else
channel->flags &= ~IEEE80211_CHAN_NO_HT40PLUS;
}
static void reg_process_ht_flags_band(struct wiphy *wiphy,
struct ieee80211_supported_band *sband)
{
unsigned int i;
if (!sband)
return;
for (i = 0; i < sband->n_channels; i++)
reg_process_ht_flags_channel(wiphy, &sband->channels[i]);
}
static void reg_process_ht_flags(struct wiphy *wiphy)
{
enum nl80211_band band;
if (!wiphy)
return;
for (band = 0; band < NUM_NL80211_BANDS; band++)
reg_process_ht_flags_band(wiphy, wiphy->bands[band]);
}
static void reg_call_notifier(struct wiphy *wiphy,
struct regulatory_request *request)
{
if (wiphy->reg_notifier)
wiphy->reg_notifier(wiphy, request);
}
static bool reg_wdev_chan_valid(struct wiphy *wiphy, struct wireless_dev *wdev)
{
struct cfg80211_chan_def chandef;
struct cfg80211_registered_device *rdev = wiphy_to_rdev(wiphy);
enum nl80211_iftype iftype;
wdev_lock(wdev);
iftype = wdev->iftype;
if (!wdev->netdev || !netif_running(wdev->netdev))
goto wdev_inactive_unlock;
switch (iftype) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_P2P_GO:
if (!wdev->beacon_interval)
goto wdev_inactive_unlock;
chandef = wdev->chandef;
break;
case NL80211_IFTYPE_ADHOC:
if (!wdev->ssid_len)
goto wdev_inactive_unlock;
chandef = wdev->chandef;
break;
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_P2P_CLIENT:
if (!wdev->current_bss ||
!wdev->current_bss->pub.channel)
goto wdev_inactive_unlock;
if (!rdev->ops->get_channel ||
rdev_get_channel(rdev, wdev, &chandef))
cfg80211_chandef_create(&chandef,
wdev->current_bss->pub.channel,
NL80211_CHAN_NO_HT);
break;
case NL80211_IFTYPE_MONITOR:
case NL80211_IFTYPE_AP_VLAN:
case NL80211_IFTYPE_P2P_DEVICE:
break;
default:
WARN_ON(1);
break;
}
wdev_unlock(wdev);
switch (iftype) {
case NL80211_IFTYPE_AP:
case NL80211_IFTYPE_P2P_GO:
case NL80211_IFTYPE_ADHOC:
return cfg80211_reg_can_beacon_relax(wiphy, &chandef, iftype);
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_P2P_CLIENT:
return cfg80211_chandef_usable(wiphy, &chandef,
IEEE80211_CHAN_DISABLED);
default:
break;
}
return true;
wdev_inactive_unlock:
wdev_unlock(wdev);
return true;
}
static void reg_leave_invalid_chans(struct wiphy *wiphy)
{
struct wireless_dev *wdev;
struct cfg80211_registered_device *rdev = wiphy_to_rdev(wiphy);
ASSERT_RTNL();
list_for_each_entry(wdev, &rdev->wiphy.wdev_list, list)
if (!reg_wdev_chan_valid(wiphy, wdev))
cfg80211_leave(rdev, wdev);
}
static void reg_check_chans_work(struct work_struct *work)
{
struct cfg80211_registered_device *rdev;
pr_debug("Verifying active interfaces after reg change\n");
rtnl_lock();
list_for_each_entry(rdev, &cfg80211_rdev_list, list)
if (!(rdev->wiphy.regulatory_flags &
REGULATORY_IGNORE_STALE_KICKOFF))
reg_leave_invalid_chans(&rdev->wiphy);
rtnl_unlock();
}
static void reg_check_channels(void)
{
mod_delayed_work(system_power_efficient_wq,
&reg_check_chans,
msecs_to_jiffies(REG_ENFORCE_GRACE_MS));
}
static void wiphy_update_regulatory(struct wiphy *wiphy,
enum nl80211_reg_initiator initiator)
{
enum nl80211_band band;
struct regulatory_request *lr = get_last_request();
if (ignore_reg_update(wiphy, initiator)) {
if (initiator == NL80211_REGDOM_SET_BY_CORE &&
wiphy->regulatory_flags & REGULATORY_CUSTOM_REG)
reg_call_notifier(wiphy, lr);
return;
}
lr->dfs_region = get_cfg80211_regdom()->dfs_region;
for (band = 0; band < NUM_NL80211_BANDS; band++)
handle_band(wiphy, initiator, wiphy->bands[band]);
reg_process_beacons(wiphy);
reg_process_ht_flags(wiphy);
reg_call_notifier(wiphy, lr);
}
static void update_all_wiphy_regulatory(enum nl80211_reg_initiator initiator)
{
struct cfg80211_registered_device *rdev;
struct wiphy *wiphy;
ASSERT_RTNL();
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
wiphy = &rdev->wiphy;
wiphy_update_regulatory(wiphy, initiator);
}
reg_check_channels();
}
static void handle_channel_custom(struct wiphy *wiphy,
struct ieee80211_channel *chan,
const struct ieee80211_regdomain *regd)
{
u32 bw_flags = 0;
const struct ieee80211_reg_rule *reg_rule = NULL;
const struct ieee80211_power_rule *power_rule = NULL;
u32 bw;
for (bw = MHZ_TO_KHZ(20); bw >= MHZ_TO_KHZ(5); bw = bw / 2) {
reg_rule = freq_reg_info_regd(MHZ_TO_KHZ(chan->center_freq),
regd, bw);
if (!IS_ERR(reg_rule))
break;
}
if (IS_ERR(reg_rule)) {
pr_debug("Disabling freq %d MHz as custom regd has no rule that fits it\n",
chan->center_freq);
if (wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED) {
chan->flags |= IEEE80211_CHAN_DISABLED;
} else {
chan->orig_flags |= IEEE80211_CHAN_DISABLED;
chan->flags = chan->orig_flags;
}
return;
}
power_rule = &reg_rule->power_rule;
bw_flags = reg_rule_to_chan_bw_flags(regd, reg_rule, chan);
chan->dfs_state_entered = jiffies;
chan->dfs_state = NL80211_DFS_USABLE;
chan->beacon_found = false;
if (wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED)
chan->flags = chan->orig_flags | bw_flags |
map_regdom_flags(reg_rule->flags);
else
chan->flags |= map_regdom_flags(reg_rule->flags) | bw_flags;
chan->max_antenna_gain = (int) MBI_TO_DBI(power_rule->max_antenna_gain);
chan->max_reg_power = chan->max_power =
(int) MBM_TO_DBM(power_rule->max_eirp);
if (chan->flags & IEEE80211_CHAN_RADAR) {
if (reg_rule->dfs_cac_ms)
chan->dfs_cac_ms = reg_rule->dfs_cac_ms;
else
chan->dfs_cac_ms = IEEE80211_DFS_MIN_CAC_TIME_MS;
}
chan->max_power = chan->max_reg_power;
}
static void handle_band_custom(struct wiphy *wiphy,
struct ieee80211_supported_band *sband,
const struct ieee80211_regdomain *regd)
{
unsigned int i;
if (!sband)
return;
for (i = 0; i < sband->n_channels; i++)
handle_channel_custom(wiphy, &sband->channels[i], regd);
}
void wiphy_apply_custom_regulatory(struct wiphy *wiphy,
const struct ieee80211_regdomain *regd)
{
enum nl80211_band band;
unsigned int bands_set = 0;
WARN(!(wiphy->regulatory_flags & REGULATORY_CUSTOM_REG),
"wiphy should have REGULATORY_CUSTOM_REG\n");
wiphy->regulatory_flags |= REGULATORY_CUSTOM_REG;
for (band = 0; band < NUM_NL80211_BANDS; band++) {
if (!wiphy->bands[band])
continue;
handle_band_custom(wiphy, wiphy->bands[band], regd);
bands_set++;
}
WARN_ON(!bands_set);
}
static void reg_set_request_processed(void)
{
bool need_more_processing = false;
struct regulatory_request *lr = get_last_request();
lr->processed = true;
spin_lock(&reg_requests_lock);
if (!list_empty(&reg_requests_list))
need_more_processing = true;
spin_unlock(&reg_requests_lock);
cancel_crda_timeout();
if (need_more_processing)
schedule_work(&reg_work);
}
static enum reg_request_treatment
reg_process_hint_core(struct regulatory_request *core_request)
{
if (reg_query_database(core_request)) {
core_request->intersect = false;
core_request->processed = false;
reg_update_last_request(core_request);
return REG_REQ_OK;
}
return REG_REQ_IGNORE;
}
static enum reg_request_treatment
__reg_process_hint_user(struct regulatory_request *user_request)
{
struct regulatory_request *lr = get_last_request();
if (reg_request_cell_base(user_request))
return reg_ignore_cell_hint(user_request);
if (reg_request_cell_base(lr))
return REG_REQ_IGNORE;
if (lr->initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE)
return REG_REQ_INTERSECT;
if (lr->initiator == NL80211_REGDOM_SET_BY_USER &&
lr->intersect)
return REG_REQ_IGNORE;
if ((lr->initiator == NL80211_REGDOM_SET_BY_CORE ||
lr->initiator == NL80211_REGDOM_SET_BY_DRIVER ||
lr->initiator == NL80211_REGDOM_SET_BY_USER) &&
regdom_changes(lr->alpha2))
return REG_REQ_IGNORE;
if (!regdom_changes(user_request->alpha2))
return REG_REQ_ALREADY_SET;
return REG_REQ_OK;
}
static enum reg_request_treatment
reg_process_hint_user(struct regulatory_request *user_request)
{
enum reg_request_treatment treatment;
treatment = __reg_process_hint_user(user_request);
if (treatment == REG_REQ_IGNORE ||
treatment == REG_REQ_ALREADY_SET)
return REG_REQ_IGNORE;
user_request->intersect = treatment == REG_REQ_INTERSECT;
user_request->processed = false;
if (reg_query_database(user_request)) {
reg_update_last_request(user_request);
user_alpha2[0] = user_request->alpha2[0];
user_alpha2[1] = user_request->alpha2[1];
return REG_REQ_OK;
}
return REG_REQ_IGNORE;
}
static enum reg_request_treatment
__reg_process_hint_driver(struct regulatory_request *driver_request)
{
struct regulatory_request *lr = get_last_request();
if (lr->initiator == NL80211_REGDOM_SET_BY_CORE) {
if (regdom_changes(driver_request->alpha2))
return REG_REQ_OK;
return REG_REQ_ALREADY_SET;
}
if (lr->initiator == NL80211_REGDOM_SET_BY_DRIVER &&
!regdom_changes(driver_request->alpha2))
return REG_REQ_ALREADY_SET;
return REG_REQ_INTERSECT;
}
static enum reg_request_treatment
reg_process_hint_driver(struct wiphy *wiphy,
struct regulatory_request *driver_request)
{
const struct ieee80211_regdomain *regd, *tmp;
enum reg_request_treatment treatment;
treatment = __reg_process_hint_driver(driver_request);
switch (treatment) {
case REG_REQ_OK:
break;
case REG_REQ_IGNORE:
return REG_REQ_IGNORE;
case REG_REQ_INTERSECT:
case REG_REQ_ALREADY_SET:
regd = reg_copy_regd(get_cfg80211_regdom());
if (IS_ERR(regd))
return REG_REQ_IGNORE;
tmp = get_wiphy_regdom(wiphy);
rcu_assign_pointer(wiphy->regd, regd);
rcu_free_regdom(tmp);
}
driver_request->intersect = treatment == REG_REQ_INTERSECT;
driver_request->processed = false;
if (treatment == REG_REQ_ALREADY_SET) {
nl80211_send_reg_change_event(driver_request);
reg_update_last_request(driver_request);
reg_set_request_processed();
return REG_REQ_ALREADY_SET;
}
if (reg_query_database(driver_request)) {
reg_update_last_request(driver_request);
return REG_REQ_OK;
}
return REG_REQ_IGNORE;
}
static enum reg_request_treatment
__reg_process_hint_country_ie(struct wiphy *wiphy,
struct regulatory_request *country_ie_request)
{
struct wiphy *last_wiphy = NULL;
struct regulatory_request *lr = get_last_request();
if (reg_request_cell_base(lr)) {
if (regdom_changes(country_ie_request->alpha2))
return REG_REQ_IGNORE;
return REG_REQ_ALREADY_SET;
} else {
if (wiphy->regulatory_flags & REGULATORY_COUNTRY_IE_IGNORE)
return REG_REQ_IGNORE;
}
if (unlikely(!is_an_alpha2(country_ie_request->alpha2)))
return -EINVAL;
if (lr->initiator != NL80211_REGDOM_SET_BY_COUNTRY_IE)
return REG_REQ_OK;
last_wiphy = wiphy_idx_to_wiphy(lr->wiphy_idx);
if (last_wiphy != wiphy) {
if (regdom_changes(country_ie_request->alpha2))
return REG_REQ_IGNORE;
return REG_REQ_ALREADY_SET;
}
if (regdom_changes(country_ie_request->alpha2))
return REG_REQ_OK;
return REG_REQ_ALREADY_SET;
}
static enum reg_request_treatment
reg_process_hint_country_ie(struct wiphy *wiphy,
struct regulatory_request *country_ie_request)
{
enum reg_request_treatment treatment;
treatment = __reg_process_hint_country_ie(wiphy, country_ie_request);
switch (treatment) {
case REG_REQ_OK:
break;
case REG_REQ_IGNORE:
return REG_REQ_IGNORE;
case REG_REQ_ALREADY_SET:
reg_free_request(country_ie_request);
return REG_REQ_ALREADY_SET;
case REG_REQ_INTERSECT:
WARN_ONCE(1, "Unexpected intersection for country IEs");
return REG_REQ_IGNORE;
}
country_ie_request->intersect = false;
country_ie_request->processed = false;
if (reg_query_database(country_ie_request)) {
reg_update_last_request(country_ie_request);
return REG_REQ_OK;
}
return REG_REQ_IGNORE;
}
bool reg_dfs_domain_same(struct wiphy *wiphy1, struct wiphy *wiphy2)
{
const struct ieee80211_regdomain *wiphy1_regd = NULL;
const struct ieee80211_regdomain *wiphy2_regd = NULL;
const struct ieee80211_regdomain *cfg80211_regd = NULL;
bool dfs_domain_same;
rcu_read_lock();
cfg80211_regd = rcu_dereference(cfg80211_regdomain);
wiphy1_regd = rcu_dereference(wiphy1->regd);
if (!wiphy1_regd)
wiphy1_regd = cfg80211_regd;
wiphy2_regd = rcu_dereference(wiphy2->regd);
if (!wiphy2_regd)
wiphy2_regd = cfg80211_regd;
dfs_domain_same = wiphy1_regd->dfs_region == wiphy2_regd->dfs_region;
rcu_read_unlock();
return dfs_domain_same;
}
static void reg_copy_dfs_chan_state(struct ieee80211_channel *dst_chan,
struct ieee80211_channel *src_chan)
{
if (!(dst_chan->flags & IEEE80211_CHAN_RADAR) ||
!(src_chan->flags & IEEE80211_CHAN_RADAR))
return;
if (dst_chan->flags & IEEE80211_CHAN_DISABLED ||
src_chan->flags & IEEE80211_CHAN_DISABLED)
return;
if (src_chan->center_freq == dst_chan->center_freq &&
dst_chan->dfs_state == NL80211_DFS_USABLE) {
dst_chan->dfs_state = src_chan->dfs_state;
dst_chan->dfs_state_entered = src_chan->dfs_state_entered;
}
}
static void wiphy_share_dfs_chan_state(struct wiphy *dst_wiphy,
struct wiphy *src_wiphy)
{
struct ieee80211_supported_band *src_sband, *dst_sband;
struct ieee80211_channel *src_chan, *dst_chan;
int i, j, band;
if (!reg_dfs_domain_same(dst_wiphy, src_wiphy))
return;
for (band = 0; band < NUM_NL80211_BANDS; band++) {
dst_sband = dst_wiphy->bands[band];
src_sband = src_wiphy->bands[band];
if (!dst_sband || !src_sband)
continue;
for (i = 0; i < dst_sband->n_channels; i++) {
dst_chan = &dst_sband->channels[i];
for (j = 0; j < src_sband->n_channels; j++) {
src_chan = &src_sband->channels[j];
reg_copy_dfs_chan_state(dst_chan, src_chan);
}
}
}
}
static void wiphy_all_share_dfs_chan_state(struct wiphy *wiphy)
{
struct cfg80211_registered_device *rdev;
ASSERT_RTNL();
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
if (wiphy == &rdev->wiphy)
continue;
wiphy_share_dfs_chan_state(wiphy, &rdev->wiphy);
}
}
static void reg_process_hint(struct regulatory_request *reg_request)
{
struct wiphy *wiphy = NULL;
enum reg_request_treatment treatment;
if (reg_request->wiphy_idx != WIPHY_IDX_INVALID)
wiphy = wiphy_idx_to_wiphy(reg_request->wiphy_idx);
switch (reg_request->initiator) {
case NL80211_REGDOM_SET_BY_CORE:
treatment = reg_process_hint_core(reg_request);
break;
case NL80211_REGDOM_SET_BY_USER:
treatment = reg_process_hint_user(reg_request);
break;
case NL80211_REGDOM_SET_BY_DRIVER:
if (!wiphy)
goto out_free;
treatment = reg_process_hint_driver(wiphy, reg_request);
break;
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
if (!wiphy)
goto out_free;
treatment = reg_process_hint_country_ie(wiphy, reg_request);
break;
default:
WARN(1, "invalid initiator %d\n", reg_request->initiator);
goto out_free;
}
if (treatment == REG_REQ_IGNORE)
goto out_free;
WARN(treatment != REG_REQ_OK && treatment != REG_REQ_ALREADY_SET,
"unexpected treatment value %d\n", treatment);
if (treatment == REG_REQ_ALREADY_SET && wiphy &&
wiphy->regulatory_flags & REGULATORY_STRICT_REG) {
wiphy_update_regulatory(wiphy, reg_request->initiator);
wiphy_all_share_dfs_chan_state(wiphy);
reg_check_channels();
}
return;
out_free:
reg_free_request(reg_request);
}
static bool reg_only_self_managed_wiphys(void)
{
struct cfg80211_registered_device *rdev;
struct wiphy *wiphy;
bool self_managed_found = false;
ASSERT_RTNL();
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
wiphy = &rdev->wiphy;
if (wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED)
self_managed_found = true;
else
return false;
}
return self_managed_found;
}
static void reg_process_pending_hints(void)
{
struct regulatory_request *reg_request, *lr;
lr = get_last_request();
if (lr && !lr->processed) {
reg_process_hint(lr);
return;
}
spin_lock(&reg_requests_lock);
if (list_empty(&reg_requests_list)) {
spin_unlock(&reg_requests_lock);
return;
}
reg_request = list_first_entry(&reg_requests_list,
struct regulatory_request,
list);
list_del_init(&reg_request->list);
spin_unlock(&reg_requests_lock);
if (reg_only_self_managed_wiphys()) {
reg_free_request(reg_request);
return;
}
reg_process_hint(reg_request);
lr = get_last_request();
spin_lock(&reg_requests_lock);
if (!list_empty(&reg_requests_list) && lr && lr->processed)
schedule_work(&reg_work);
spin_unlock(&reg_requests_lock);
}
static void reg_process_pending_beacon_hints(void)
{
struct cfg80211_registered_device *rdev;
struct reg_beacon *pending_beacon, *tmp;
spin_lock_bh(&reg_pending_beacons_lock);
list_for_each_entry_safe(pending_beacon, tmp,
&reg_pending_beacons, list) {
list_del_init(&pending_beacon->list);
list_for_each_entry(rdev, &cfg80211_rdev_list, list)
wiphy_update_new_beacon(&rdev->wiphy, pending_beacon);
list_add_tail(&pending_beacon->list, &reg_beacon_list);
}
spin_unlock_bh(&reg_pending_beacons_lock);
}
static void reg_process_self_managed_hints(void)
{
struct cfg80211_registered_device *rdev;
struct wiphy *wiphy;
const struct ieee80211_regdomain *tmp;
const struct ieee80211_regdomain *regd;
enum nl80211_band band;
struct regulatory_request request = {};
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
wiphy = &rdev->wiphy;
spin_lock(&reg_requests_lock);
regd = rdev->requested_regd;
rdev->requested_regd = NULL;
spin_unlock(&reg_requests_lock);
if (regd == NULL)
continue;
tmp = get_wiphy_regdom(wiphy);
rcu_assign_pointer(wiphy->regd, regd);
rcu_free_regdom(tmp);
for (band = 0; band < NUM_NL80211_BANDS; band++)
handle_band_custom(wiphy, wiphy->bands[band], regd);
reg_process_ht_flags(wiphy);
request.wiphy_idx = get_wiphy_idx(wiphy);
request.alpha2[0] = regd->alpha2[0];
request.alpha2[1] = regd->alpha2[1];
request.initiator = NL80211_REGDOM_SET_BY_DRIVER;
nl80211_send_wiphy_reg_change_event(&request);
}
reg_check_channels();
}
static void reg_todo(struct work_struct *work)
{
rtnl_lock();
reg_process_pending_hints();
reg_process_pending_beacon_hints();
reg_process_self_managed_hints();
rtnl_unlock();
}
static void queue_regulatory_request(struct regulatory_request *request)
{
request->alpha2[0] = toupper(request->alpha2[0]);
request->alpha2[1] = toupper(request->alpha2[1]);
spin_lock(&reg_requests_lock);
list_add_tail(&request->list, &reg_requests_list);
spin_unlock(&reg_requests_lock);
schedule_work(&reg_work);
}
static int regulatory_hint_core(const char *alpha2)
{
struct regulatory_request *request;
request = kzalloc(sizeof(struct regulatory_request), GFP_KERNEL);
if (!request)
return -ENOMEM;
request->alpha2[0] = alpha2[0];
request->alpha2[1] = alpha2[1];
request->initiator = NL80211_REGDOM_SET_BY_CORE;
queue_regulatory_request(request);
return 0;
}
int regulatory_hint_user(const char *alpha2,
enum nl80211_user_reg_hint_type user_reg_hint_type)
{
struct regulatory_request *request;
if (WARN_ON(!alpha2))
return -EINVAL;
request = kzalloc(sizeof(struct regulatory_request), GFP_KERNEL);
if (!request)
return -ENOMEM;
request->wiphy_idx = WIPHY_IDX_INVALID;
request->alpha2[0] = alpha2[0];
request->alpha2[1] = alpha2[1];
request->initiator = NL80211_REGDOM_SET_BY_USER;
request->user_reg_hint_type = user_reg_hint_type;
reset_crda_timeouts();
queue_regulatory_request(request);
return 0;
}
int regulatory_hint_indoor(bool is_indoor, u32 portid)
{
spin_lock(&reg_indoor_lock);
reg_is_indoor = is_indoor;
if (reg_is_indoor) {
if (!reg_is_indoor_portid)
reg_is_indoor_portid = portid;
} else {
reg_is_indoor_portid = 0;
}
spin_unlock(&reg_indoor_lock);
if (!is_indoor)
reg_check_channels();
return 0;
}
void regulatory_netlink_notify(u32 portid)
{
spin_lock(&reg_indoor_lock);
if (reg_is_indoor_portid != portid) {
spin_unlock(&reg_indoor_lock);
return;
}
reg_is_indoor = false;
reg_is_indoor_portid = 0;
spin_unlock(&reg_indoor_lock);
reg_check_channels();
}
int regulatory_hint(struct wiphy *wiphy, const char *alpha2)
{
struct regulatory_request *request;
if (WARN_ON(!alpha2 || !wiphy))
return -EINVAL;
wiphy->regulatory_flags &= ~REGULATORY_CUSTOM_REG;
request = kzalloc(sizeof(struct regulatory_request), GFP_KERNEL);
if (!request)
return -ENOMEM;
request->wiphy_idx = get_wiphy_idx(wiphy);
request->alpha2[0] = alpha2[0];
request->alpha2[1] = alpha2[1];
request->initiator = NL80211_REGDOM_SET_BY_DRIVER;
reset_crda_timeouts();
queue_regulatory_request(request);
return 0;
}
void regulatory_hint_country_ie(struct wiphy *wiphy, enum nl80211_band band,
const u8 *country_ie, u8 country_ie_len)
{
char alpha2[2];
enum environment_cap env = ENVIRON_ANY;
struct regulatory_request *request = NULL, *lr;
if (country_ie_len & 0x01)
return;
if (country_ie_len < IEEE80211_COUNTRY_IE_MIN_LEN)
return;
request = kzalloc(sizeof(*request), GFP_KERNEL);
if (!request)
return;
alpha2[0] = country_ie[0];
alpha2[1] = country_ie[1];
if (country_ie[2] == 'I')
env = ENVIRON_INDOOR;
else if (country_ie[2] == 'O')
env = ENVIRON_OUTDOOR;
rcu_read_lock();
lr = get_last_request();
if (unlikely(!lr))
goto out;
if (lr->initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE &&
lr->wiphy_idx != WIPHY_IDX_INVALID)
goto out;
request->wiphy_idx = get_wiphy_idx(wiphy);
request->alpha2[0] = alpha2[0];
request->alpha2[1] = alpha2[1];
request->initiator = NL80211_REGDOM_SET_BY_COUNTRY_IE;
request->country_ie_env = env;
reset_crda_timeouts();
queue_regulatory_request(request);
request = NULL;
out:
kfree(request);
rcu_read_unlock();
}
static void restore_alpha2(char *alpha2, bool reset_user)
{
alpha2[0] = '9';
alpha2[1] = '7';
if (is_user_regdom_saved()) {
if (reset_user) {
pr_debug("Restoring regulatory settings including user preference\n");
user_alpha2[0] = '9';
user_alpha2[1] = '7';
if (!is_world_regdom(ieee80211_regdom)) {
pr_debug("Keeping preference on module parameter ieee80211_regdom: %c%c\n",
ieee80211_regdom[0], ieee80211_regdom[1]);
alpha2[0] = ieee80211_regdom[0];
alpha2[1] = ieee80211_regdom[1];
}
} else {
pr_debug("Restoring regulatory settings while preserving user preference for: %c%c\n",
user_alpha2[0], user_alpha2[1]);
alpha2[0] = user_alpha2[0];
alpha2[1] = user_alpha2[1];
}
} else if (!is_world_regdom(ieee80211_regdom)) {
pr_debug("Keeping preference on module parameter ieee80211_regdom: %c%c\n",
ieee80211_regdom[0], ieee80211_regdom[1]);
alpha2[0] = ieee80211_regdom[0];
alpha2[1] = ieee80211_regdom[1];
} else
pr_debug("Restoring regulatory settings\n");
}
static void restore_custom_reg_settings(struct wiphy *wiphy)
{
struct ieee80211_supported_band *sband;
enum nl80211_band band;
struct ieee80211_channel *chan;
int i;
for (band = 0; band < NUM_NL80211_BANDS; band++) {
sband = wiphy->bands[band];
if (!sband)
continue;
for (i = 0; i < sband->n_channels; i++) {
chan = &sband->channels[i];
chan->flags = chan->orig_flags;
chan->max_antenna_gain = chan->orig_mag;
chan->max_power = chan->orig_mpwr;
chan->beacon_found = false;
}
}
}
static void restore_regulatory_settings(bool reset_user)
{
char alpha2[2];
char world_alpha2[2];
struct reg_beacon *reg_beacon, *btmp;
LIST_HEAD(tmp_reg_req_list);
struct cfg80211_registered_device *rdev;
ASSERT_RTNL();
spin_lock(&reg_indoor_lock);
if (reg_is_indoor && !reg_is_indoor_portid) {
reg_is_indoor = false;
reg_check_channels();
}
spin_unlock(&reg_indoor_lock);
reset_regdomains(true, &world_regdom);
restore_alpha2(alpha2, reset_user);
spin_lock(&reg_requests_lock);
list_splice_tail_init(&reg_requests_list, &tmp_reg_req_list);
spin_unlock(&reg_requests_lock);
spin_lock_bh(&reg_pending_beacons_lock);
list_for_each_entry_safe(reg_beacon, btmp, &reg_pending_beacons, list) {
list_del(&reg_beacon->list);
kfree(reg_beacon);
}
spin_unlock_bh(&reg_pending_beacons_lock);
list_for_each_entry_safe(reg_beacon, btmp, &reg_beacon_list, list) {
list_del(&reg_beacon->list);
kfree(reg_beacon);
}
world_alpha2[0] = cfg80211_world_regdom->alpha2[0];
world_alpha2[1] = cfg80211_world_regdom->alpha2[1];
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
if (rdev->wiphy.regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED)
continue;
if (rdev->wiphy.regulatory_flags & REGULATORY_CUSTOM_REG)
restore_custom_reg_settings(&rdev->wiphy);
}
regulatory_hint_core(world_alpha2);
if (is_an_alpha2(alpha2))
regulatory_hint_user(alpha2, NL80211_USER_REG_HINT_USER);
spin_lock(&reg_requests_lock);
list_splice_tail_init(&tmp_reg_req_list, &reg_requests_list);
spin_unlock(&reg_requests_lock);
pr_debug("Kicking the queue\n");
schedule_work(&reg_work);
}
void regulatory_hint_disconnect(void)
{
pr_debug("All devices are disconnected, going to restore regulatory settings\n");
restore_regulatory_settings(false);
}
static bool freq_is_chan_12_13_14(u16 freq)
{
if (freq == ieee80211_channel_to_frequency(12, NL80211_BAND_2GHZ) ||
freq == ieee80211_channel_to_frequency(13, NL80211_BAND_2GHZ) ||
freq == ieee80211_channel_to_frequency(14, NL80211_BAND_2GHZ))
return true;
return false;
}
static bool pending_reg_beacon(struct ieee80211_channel *beacon_chan)
{
struct reg_beacon *pending_beacon;
list_for_each_entry(pending_beacon, &reg_pending_beacons, list)
if (beacon_chan->center_freq ==
pending_beacon->chan.center_freq)
return true;
return false;
}
int regulatory_hint_found_beacon(struct wiphy *wiphy,
struct ieee80211_channel *beacon_chan,
gfp_t gfp)
{
struct reg_beacon *reg_beacon;
bool processing;
if (beacon_chan->beacon_found ||
beacon_chan->flags & IEEE80211_CHAN_RADAR ||
(beacon_chan->band == NL80211_BAND_2GHZ &&
!freq_is_chan_12_13_14(beacon_chan->center_freq)))
return 0;
spin_lock_bh(&reg_pending_beacons_lock);
processing = pending_reg_beacon(beacon_chan);
spin_unlock_bh(&reg_pending_beacons_lock);
if (processing)
return 0;
reg_beacon = kzalloc(sizeof(struct reg_beacon), gfp);
if (!reg_beacon)
return -ENOMEM;
pr_debug("Found new beacon on frequency: %d MHz (Ch %d) on %s\n",
beacon_chan->center_freq,
ieee80211_frequency_to_channel(beacon_chan->center_freq),
wiphy_name(wiphy));
memcpy(&reg_beacon->chan, beacon_chan,
sizeof(struct ieee80211_channel));
spin_lock_bh(&reg_pending_beacons_lock);
list_add_tail(&reg_beacon->list, &reg_pending_beacons);
spin_unlock_bh(&reg_pending_beacons_lock);
schedule_work(&reg_work);
return 0;
}
static void print_rd_rules(const struct ieee80211_regdomain *rd)
{
unsigned int i;
const struct ieee80211_reg_rule *reg_rule = NULL;
const struct ieee80211_freq_range *freq_range = NULL;
const struct ieee80211_power_rule *power_rule = NULL;
char bw[32], cac_time[32];
pr_debug(" (start_freq - end_freq @ bandwidth), (max_antenna_gain, max_eirp), (dfs_cac_time)\n");
for (i = 0; i < rd->n_reg_rules; i++) {
reg_rule = &rd->reg_rules[i];
freq_range = &reg_rule->freq_range;
power_rule = &reg_rule->power_rule;
if (reg_rule->flags & NL80211_RRF_AUTO_BW)
snprintf(bw, sizeof(bw), "%d KHz, %d KHz AUTO",
freq_range->max_bandwidth_khz,
reg_get_max_bandwidth(rd, reg_rule));
else
snprintf(bw, sizeof(bw), "%d KHz",
freq_range->max_bandwidth_khz);
if (reg_rule->flags & NL80211_RRF_DFS)
scnprintf(cac_time, sizeof(cac_time), "%u s",
reg_rule->dfs_cac_ms/1000);
else
scnprintf(cac_time, sizeof(cac_time), "N/A");
if (power_rule->max_antenna_gain)
pr_debug(" (%d KHz - %d KHz @ %s), (%d mBi, %d mBm), (%s)\n",
freq_range->start_freq_khz,
freq_range->end_freq_khz,
bw,
power_rule->max_antenna_gain,
power_rule->max_eirp,
cac_time);
else
pr_debug(" (%d KHz - %d KHz @ %s), (N/A, %d mBm), (%s)\n",
freq_range->start_freq_khz,
freq_range->end_freq_khz,
bw,
power_rule->max_eirp,
cac_time);
}
}
bool reg_supported_dfs_region(enum nl80211_dfs_regions dfs_region)
{
switch (dfs_region) {
case NL80211_DFS_UNSET:
case NL80211_DFS_FCC:
case NL80211_DFS_ETSI:
case NL80211_DFS_JP:
return true;
default:
pr_debug("Ignoring uknown DFS master region: %d\n", dfs_region);
return false;
}
}
static void print_regdomain(const struct ieee80211_regdomain *rd)
{
struct regulatory_request *lr = get_last_request();
if (is_intersected_alpha2(rd->alpha2)) {
if (lr->initiator == NL80211_REGDOM_SET_BY_COUNTRY_IE) {
struct cfg80211_registered_device *rdev;
rdev = cfg80211_rdev_by_wiphy_idx(lr->wiphy_idx);
if (rdev) {
pr_debug("Current regulatory domain updated by AP to: %c%c\n",
rdev->country_ie_alpha2[0],
rdev->country_ie_alpha2[1]);
} else
pr_debug("Current regulatory domain intersected:\n");
} else
pr_debug("Current regulatory domain intersected:\n");
} else if (is_world_regdom(rd->alpha2)) {
pr_debug("World regulatory domain updated:\n");
} else {
if (is_unknown_alpha2(rd->alpha2))
pr_debug("Regulatory domain changed to driver built-in settings (unknown country)\n");
else {
if (reg_request_cell_base(lr))
pr_debug("Regulatory domain changed to country: %c%c by Cell Station\n",
rd->alpha2[0], rd->alpha2[1]);
else
pr_debug("Regulatory domain changed to country: %c%c\n",
rd->alpha2[0], rd->alpha2[1]);
}
}
pr_debug(" DFS Master region: %s", reg_dfs_region_str(rd->dfs_region));
print_rd_rules(rd);
}
static void print_regdomain_info(const struct ieee80211_regdomain *rd)
{
pr_debug("Regulatory domain: %c%c\n", rd->alpha2[0], rd->alpha2[1]);
print_rd_rules(rd);
}
static int reg_set_rd_core(const struct ieee80211_regdomain *rd)
{
if (!is_world_regdom(rd->alpha2))
return -EINVAL;
update_world_regdomain(rd);
return 0;
}
static int reg_set_rd_user(const struct ieee80211_regdomain *rd,
struct regulatory_request *user_request)
{
const struct ieee80211_regdomain *intersected_rd = NULL;
if (!regdom_changes(rd->alpha2))
return -EALREADY;
if (!is_valid_rd(rd)) {
pr_err("Invalid regulatory domain detected: %c%c\n",
rd->alpha2[0], rd->alpha2[1]);
print_regdomain_info(rd);
return -EINVAL;
}
if (!user_request->intersect) {
reset_regdomains(false, rd);
return 0;
}
intersected_rd = regdom_intersect(rd, get_cfg80211_regdom());
if (!intersected_rd)
return -EINVAL;
kfree(rd);
rd = NULL;
reset_regdomains(false, intersected_rd);
return 0;
}
static int reg_set_rd_driver(const struct ieee80211_regdomain *rd,
struct regulatory_request *driver_request)
{
const struct ieee80211_regdomain *regd;
const struct ieee80211_regdomain *intersected_rd = NULL;
const struct ieee80211_regdomain *tmp;
struct wiphy *request_wiphy;
if (is_world_regdom(rd->alpha2))
return -EINVAL;
if (!regdom_changes(rd->alpha2))
return -EALREADY;
if (!is_valid_rd(rd)) {
pr_err("Invalid regulatory domain detected: %c%c\n",
rd->alpha2[0], rd->alpha2[1]);
print_regdomain_info(rd);
return -EINVAL;
}
request_wiphy = wiphy_idx_to_wiphy(driver_request->wiphy_idx);
if (!request_wiphy)
return -ENODEV;
if (!driver_request->intersect) {
if (request_wiphy->regd)
return -EALREADY;
regd = reg_copy_regd(rd);
if (IS_ERR(regd))
return PTR_ERR(regd);
rcu_assign_pointer(request_wiphy->regd, regd);
reset_regdomains(false, rd);
return 0;
}
intersected_rd = regdom_intersect(rd, get_cfg80211_regdom());
if (!intersected_rd)
return -EINVAL;
tmp = get_wiphy_regdom(request_wiphy);
rcu_assign_pointer(request_wiphy->regd, rd);
rcu_free_regdom(tmp);
rd = NULL;
reset_regdomains(false, intersected_rd);
return 0;
}
static int reg_set_rd_country_ie(const struct ieee80211_regdomain *rd,
struct regulatory_request *country_ie_request)
{
struct wiphy *request_wiphy;
if (!is_alpha2_set(rd->alpha2) && !is_an_alpha2(rd->alpha2) &&
!is_unknown_alpha2(rd->alpha2))
return -EINVAL;
if (!is_valid_rd(rd)) {
pr_err("Invalid regulatory domain detected: %c%c\n",
rd->alpha2[0], rd->alpha2[1]);
print_regdomain_info(rd);
return -EINVAL;
}
request_wiphy = wiphy_idx_to_wiphy(country_ie_request->wiphy_idx);
if (!request_wiphy)
return -ENODEV;
if (country_ie_request->intersect)
return -EINVAL;
reset_regdomains(false, rd);
return 0;
}
int set_regdom(const struct ieee80211_regdomain *rd,
enum ieee80211_regd_source regd_src)
{
struct regulatory_request *lr;
bool user_reset = false;
int r;
if (!reg_is_valid_request(rd->alpha2)) {
kfree(rd);
return -EINVAL;
}
if (regd_src == REGD_SOURCE_CRDA)
reset_crda_timeouts();
lr = get_last_request();
switch (lr->initiator) {
case NL80211_REGDOM_SET_BY_CORE:
r = reg_set_rd_core(rd);
break;
case NL80211_REGDOM_SET_BY_USER:
r = reg_set_rd_user(rd, lr);
user_reset = true;
break;
case NL80211_REGDOM_SET_BY_DRIVER:
r = reg_set_rd_driver(rd, lr);
break;
case NL80211_REGDOM_SET_BY_COUNTRY_IE:
r = reg_set_rd_country_ie(rd, lr);
break;
default:
WARN(1, "invalid initiator %d\n", lr->initiator);
kfree(rd);
return -EINVAL;
}
if (r) {
switch (r) {
case -EALREADY:
reg_set_request_processed();
break;
default:
restore_regulatory_settings(user_reset);
}
kfree(rd);
return r;
}
if (WARN_ON(!lr->intersect && rd != get_cfg80211_regdom()))
return -EINVAL;
update_all_wiphy_regulatory(lr->initiator);
print_regdomain(get_cfg80211_regdom());
nl80211_send_reg_change_event(lr);
reg_set_request_processed();
return 0;
}
static int __regulatory_set_wiphy_regd(struct wiphy *wiphy,
struct ieee80211_regdomain *rd)
{
const struct ieee80211_regdomain *regd;
const struct ieee80211_regdomain *prev_regd;
struct cfg80211_registered_device *rdev;
if (WARN_ON(!wiphy || !rd))
return -EINVAL;
if (WARN(!(wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED),
"wiphy should have REGULATORY_WIPHY_SELF_MANAGED\n"))
return -EPERM;
if (WARN(!is_valid_rd(rd), "Invalid regulatory domain detected\n")) {
print_regdomain_info(rd);
return -EINVAL;
}
regd = reg_copy_regd(rd);
if (IS_ERR(regd))
return PTR_ERR(regd);
rdev = wiphy_to_rdev(wiphy);
spin_lock(&reg_requests_lock);
prev_regd = rdev->requested_regd;
rdev->requested_regd = regd;
spin_unlock(&reg_requests_lock);
kfree(prev_regd);
return 0;
}
int regulatory_set_wiphy_regd(struct wiphy *wiphy,
struct ieee80211_regdomain *rd)
{
int ret = __regulatory_set_wiphy_regd(wiphy, rd);
if (ret)
return ret;
schedule_work(&reg_work);
return 0;
}
int regulatory_set_wiphy_regd_sync_rtnl(struct wiphy *wiphy,
struct ieee80211_regdomain *rd)
{
int ret;
ASSERT_RTNL();
ret = __regulatory_set_wiphy_regd(wiphy, rd);
if (ret)
return ret;
reg_process_self_managed_hints();
return 0;
}
void wiphy_regulatory_register(struct wiphy *wiphy)
{
struct regulatory_request *lr;
if (wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED)
wiphy->regulatory_flags |= REGULATORY_DISABLE_BEACON_HINTS |
REGULATORY_COUNTRY_IE_IGNORE;
if (!reg_dev_ignore_cell_hint(wiphy))
reg_num_devs_support_basehint++;
lr = get_last_request();
wiphy_update_regulatory(wiphy, lr->initiator);
wiphy_all_share_dfs_chan_state(wiphy);
}
void wiphy_regulatory_deregister(struct wiphy *wiphy)
{
struct wiphy *request_wiphy = NULL;
struct regulatory_request *lr;
lr = get_last_request();
if (!reg_dev_ignore_cell_hint(wiphy))
reg_num_devs_support_basehint--;
rcu_free_regdom(get_wiphy_regdom(wiphy));
RCU_INIT_POINTER(wiphy->regd, NULL);
if (lr)
request_wiphy = wiphy_idx_to_wiphy(lr->wiphy_idx);
if (!request_wiphy || request_wiphy != wiphy)
return;
lr->wiphy_idx = WIPHY_IDX_INVALID;
lr->country_ie_env = ENVIRON_ANY;
}
int cfg80211_get_unii(int freq)
{
if (freq >= 5150 && freq <= 5250)
return 0;
if (freq > 5250 && freq <= 5350)
return 1;
if (freq > 5350 && freq <= 5470)
return 2;
if (freq > 5470 && freq <= 5725)
return 3;
if (freq > 5725 && freq <= 5825)
return 4;
return -EINVAL;
}
bool regulatory_indoor_allowed(void)
{
return reg_is_indoor;
}
bool regulatory_pre_cac_allowed(struct wiphy *wiphy)
{
const struct ieee80211_regdomain *regd = NULL;
const struct ieee80211_regdomain *wiphy_regd = NULL;
bool pre_cac_allowed = false;
rcu_read_lock();
regd = rcu_dereference(cfg80211_regdomain);
wiphy_regd = rcu_dereference(wiphy->regd);
if (!wiphy_regd) {
if (regd->dfs_region == NL80211_DFS_ETSI)
pre_cac_allowed = true;
rcu_read_unlock();
return pre_cac_allowed;
}
if (regd->dfs_region == wiphy_regd->dfs_region &&
wiphy_regd->dfs_region == NL80211_DFS_ETSI)
pre_cac_allowed = true;
rcu_read_unlock();
return pre_cac_allowed;
}
void regulatory_propagate_dfs_state(struct wiphy *wiphy,
struct cfg80211_chan_def *chandef,
enum nl80211_dfs_state dfs_state,
enum nl80211_radar_event event)
{
struct cfg80211_registered_device *rdev;
ASSERT_RTNL();
if (WARN_ON(!cfg80211_chandef_valid(chandef)))
return;
list_for_each_entry(rdev, &cfg80211_rdev_list, list) {
if (wiphy == &rdev->wiphy)
continue;
if (!reg_dfs_domain_same(wiphy, &rdev->wiphy))
continue;
if (!ieee80211_get_channel(&rdev->wiphy,
chandef->chan->center_freq))
continue;
cfg80211_set_dfs_state(&rdev->wiphy, chandef, dfs_state);
if (event == NL80211_RADAR_DETECTED ||
event == NL80211_RADAR_CAC_FINISHED)
cfg80211_sched_dfs_chan_update(rdev);
nl80211_radar_notify(rdev, chandef, event, NULL, GFP_KERNEL);
}
}
int __init regulatory_init(void)
{
int err = 0;
reg_pdev = platform_device_register_simple("regulatory", 0, NULL, 0);
if (IS_ERR(reg_pdev))
return PTR_ERR(reg_pdev);
spin_lock_init(&reg_requests_lock);
spin_lock_init(&reg_pending_beacons_lock);
spin_lock_init(&reg_indoor_lock);
reg_regdb_size_check();
rcu_assign_pointer(cfg80211_regdomain, cfg80211_world_regdom);
user_alpha2[0] = '9';
user_alpha2[1] = '7';
err = regulatory_hint_core(cfg80211_world_regdom->alpha2);
if (err) {
if (err == -ENOMEM) {
platform_device_unregister(reg_pdev);
return err;
}
pr_err("kobject_uevent_env() was unable to call CRDA during init\n");
}
if (!is_world_regdom(ieee80211_regdom))
regulatory_hint_user(ieee80211_regdom,
NL80211_USER_REG_HINT_USER);
return 0;
}
void regulatory_exit(void)
{
struct regulatory_request *reg_request, *tmp;
struct reg_beacon *reg_beacon, *btmp;
cancel_work_sync(&reg_work);
cancel_crda_timeout_sync();
cancel_delayed_work_sync(&reg_check_chans);
rtnl_lock();
reset_regdomains(true, NULL);
rtnl_unlock();
dev_set_uevent_suppress(&reg_pdev->dev, true);
platform_device_unregister(reg_pdev);
list_for_each_entry_safe(reg_beacon, btmp, &reg_pending_beacons, list) {
list_del(&reg_beacon->list);
kfree(reg_beacon);
}
list_for_each_entry_safe(reg_beacon, btmp, &reg_beacon_list, list) {
list_del(&reg_beacon->list);
kfree(reg_beacon);
}
list_for_each_entry_safe(reg_request, tmp, &reg_requests_list, list) {
list_del(&reg_request->list);
kfree(reg_request);
}
}
