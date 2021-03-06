static s32 ixgbe_ieee_credits(__u8 *bw, __u16 *refill,
__u16 *max, int max_frame)
{
int min_percent = 100;
int min_credit, multiplier;
int i;
min_credit = ((max_frame / 2) + DCB_CREDIT_QUANTUM - 1) /
DCB_CREDIT_QUANTUM;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
if (bw[i] < min_percent && bw[i])
min_percent = bw[i];
}
multiplier = (min_credit / min_percent) + 1;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
int val = min(bw[i] * multiplier, MAX_CREDIT_REFILL);
if (val < min_credit)
val = min_credit;
refill[i] = val;
max[i] = bw[i] ? (bw[i] * MAX_CREDIT)/100 : min_credit;
}
return 0;
}
s32 ixgbe_dcb_calculate_tc_credits(struct ixgbe_hw *hw,
struct ixgbe_dcb_config *dcb_config,
int max_frame, u8 direction)
{
struct tc_bw_alloc *p;
int min_credit;
int min_multiplier;
int min_percent = 100;
u32 credit_refill = 0;
u32 credit_max = 0;
u16 link_percentage = 0;
u8 bw_percent = 0;
u8 i;
if (!dcb_config)
return DCB_ERR_CONFIG;
min_credit = ((max_frame / 2) + DCB_CREDIT_QUANTUM - 1) /
DCB_CREDIT_QUANTUM;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
p = &dcb_config->tc_config[i].path[direction];
bw_percent = dcb_config->bw_percentage[direction][p->bwg_id];
link_percentage = p->bwg_percent;
link_percentage = (link_percentage * bw_percent) / 100;
if (link_percentage && link_percentage < min_percent)
min_percent = link_percentage;
}
min_multiplier = (min_credit / min_percent) + 1;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
p = &dcb_config->tc_config[i].path[direction];
bw_percent = dcb_config->bw_percentage[direction][p->bwg_id];
link_percentage = p->bwg_percent;
link_percentage = (link_percentage * bw_percent) / 100;
if (p->bwg_percent > 0 && link_percentage == 0)
link_percentage = 1;
p->link_percent = (u8)link_percentage;
credit_refill = min(link_percentage * min_multiplier,
MAX_CREDIT_REFILL);
if (credit_refill < min_credit)
credit_refill = min_credit;
p->data_credits_refill = (u16)credit_refill;
credit_max = (link_percentage * MAX_CREDIT) / 100;
if (credit_max < min_credit)
credit_max = min_credit;
if (direction == DCB_TX_CONFIG) {
if ((hw->mac.type == ixgbe_mac_82598EB) &&
credit_max &&
(credit_max < MINIMUM_CREDIT_FOR_TSO))
credit_max = MINIMUM_CREDIT_FOR_TSO;
dcb_config->tc_config[i].desc_credits_max =
(u16)credit_max;
}
p->data_credits_max = (u16)credit_max;
}
return 0;
}
void ixgbe_dcb_unpack_pfc(struct ixgbe_dcb_config *cfg, u8 *pfc_en)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
int tc;
for (*pfc_en = 0, tc = 0; tc < MAX_TRAFFIC_CLASS; tc++) {
if (tc_config[tc].dcb_pfc != pfc_disabled)
*pfc_en |= BIT(tc);
}
}
void ixgbe_dcb_unpack_refill(struct ixgbe_dcb_config *cfg, int direction,
u16 *refill)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
int tc;
for (tc = 0; tc < MAX_TRAFFIC_CLASS; tc++)
refill[tc] = tc_config[tc].path[direction].data_credits_refill;
}
void ixgbe_dcb_unpack_max(struct ixgbe_dcb_config *cfg, u16 *max)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
int tc;
for (tc = 0; tc < MAX_TRAFFIC_CLASS; tc++)
max[tc] = tc_config[tc].desc_credits_max;
}
void ixgbe_dcb_unpack_bwgid(struct ixgbe_dcb_config *cfg, int direction,
u8 *bwgid)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
int tc;
for (tc = 0; tc < MAX_TRAFFIC_CLASS; tc++)
bwgid[tc] = tc_config[tc].path[direction].bwg_id;
}
void ixgbe_dcb_unpack_prio(struct ixgbe_dcb_config *cfg, int direction,
u8 *ptype)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
int tc;
for (tc = 0; tc < MAX_TRAFFIC_CLASS; tc++)
ptype[tc] = tc_config[tc].path[direction].prio_type;
}
u8 ixgbe_dcb_get_tc_from_up(struct ixgbe_dcb_config *cfg, int direction, u8 up)
{
struct tc_configuration *tc_config = &cfg->tc_config[0];
u8 prio_mask = BIT(up);
u8 tc = cfg->num_tcs.pg_tcs;
if (!tc)
return 0;
for (tc--; tc; tc--) {
if (prio_mask & tc_config[tc].path[direction].up_to_tc_bitmap)
break;
}
return tc;
}
void ixgbe_dcb_unpack_map(struct ixgbe_dcb_config *cfg, int direction, u8 *map)
{
u8 up;
for (up = 0; up < MAX_USER_PRIORITY; up++)
map[up] = ixgbe_dcb_get_tc_from_up(cfg, direction, up);
}
s32 ixgbe_dcb_hw_config(struct ixgbe_hw *hw,
struct ixgbe_dcb_config *dcb_config)
{
u8 pfc_en;
u8 ptype[MAX_TRAFFIC_CLASS];
u8 bwgid[MAX_TRAFFIC_CLASS];
u8 prio_tc[MAX_TRAFFIC_CLASS];
u16 refill[MAX_TRAFFIC_CLASS];
u16 max[MAX_TRAFFIC_CLASS];
ixgbe_dcb_unpack_pfc(dcb_config, &pfc_en);
ixgbe_dcb_unpack_refill(dcb_config, DCB_TX_CONFIG, refill);
ixgbe_dcb_unpack_max(dcb_config, max);
ixgbe_dcb_unpack_bwgid(dcb_config, DCB_TX_CONFIG, bwgid);
ixgbe_dcb_unpack_prio(dcb_config, DCB_TX_CONFIG, ptype);
ixgbe_dcb_unpack_map(dcb_config, DCB_TX_CONFIG, prio_tc);
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
return ixgbe_dcb_hw_config_82598(hw, pfc_en, refill, max,
bwgid, ptype);
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
return ixgbe_dcb_hw_config_82599(hw, pfc_en, refill, max,
bwgid, ptype, prio_tc);
default:
break;
}
return 0;
}
s32 ixgbe_dcb_hw_pfc_config(struct ixgbe_hw *hw, u8 pfc_en, u8 *prio_tc)
{
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
return ixgbe_dcb_config_pfc_82598(hw, pfc_en);
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
return ixgbe_dcb_config_pfc_82599(hw, pfc_en, prio_tc);
default:
break;
}
return -EINVAL;
}
s32 ixgbe_dcb_hw_ets(struct ixgbe_hw *hw, struct ieee_ets *ets, int max_frame)
{
__u16 refill[IEEE_8021QAZ_MAX_TCS], max[IEEE_8021QAZ_MAX_TCS];
__u8 prio_type[IEEE_8021QAZ_MAX_TCS];
int i;
__u8 bwg_id[IEEE_8021QAZ_MAX_TCS] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
switch (ets->tc_tsa[i]) {
case IEEE_8021QAZ_TSA_STRICT:
prio_type[i] = 2;
break;
case IEEE_8021QAZ_TSA_ETS:
prio_type[i] = 0;
break;
default:
return -EINVAL;
}
}
ixgbe_ieee_credits(ets->tc_tx_bw, refill, max, max_frame);
return ixgbe_dcb_hw_ets_config(hw, refill, max,
bwg_id, prio_type, ets->prio_tc);
}
s32 ixgbe_dcb_hw_ets_config(struct ixgbe_hw *hw,
u16 *refill, u16 *max, u8 *bwg_id,
u8 *prio_type, u8 *prio_tc)
{
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
ixgbe_dcb_config_rx_arbiter_82598(hw, refill, max,
prio_type);
ixgbe_dcb_config_tx_desc_arbiter_82598(hw, refill, max,
bwg_id, prio_type);
ixgbe_dcb_config_tx_data_arbiter_82598(hw, refill, max,
bwg_id, prio_type);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
ixgbe_dcb_config_rx_arbiter_82599(hw, refill, max,
bwg_id, prio_type, prio_tc);
ixgbe_dcb_config_tx_desc_arbiter_82599(hw, refill, max,
bwg_id, prio_type);
ixgbe_dcb_config_tx_data_arbiter_82599(hw, refill, max, bwg_id,
prio_type, prio_tc);
break;
default:
break;
}
return 0;
}
static void ixgbe_dcb_read_rtrup2tc_82599(struct ixgbe_hw *hw, u8 *map)
{
u32 reg, i;
reg = IXGBE_READ_REG(hw, IXGBE_RTRUP2TC);
for (i = 0; i < MAX_USER_PRIORITY; i++)
map[i] = IXGBE_RTRUP2TC_UP_MASK &
(reg >> (i * IXGBE_RTRUP2TC_UP_SHIFT));
}
void ixgbe_dcb_read_rtrup2tc(struct ixgbe_hw *hw, u8 *map)
{
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
ixgbe_dcb_read_rtrup2tc_82599(hw, map);
break;
default:
break;
}
}
