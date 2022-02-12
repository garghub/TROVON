static void
brcms_c_antsel_init_cfg(struct antsel_info *asi, struct brcms_antselcfg *antsel,
bool auto_sel)
{
if (asi->antsel_type == ANTSEL_2x3) {
u8 antcfg_def = ANT_SELCFG_DEF_2x3 |
((asi->antsel_avail && auto_sel) ? ANT_SELCFG_AUTO : 0);
antsel->ant_config[ANT_SELCFG_TX_DEF] = antcfg_def;
antsel->ant_config[ANT_SELCFG_TX_UNICAST] = antcfg_def;
antsel->ant_config[ANT_SELCFG_RX_DEF] = antcfg_def;
antsel->ant_config[ANT_SELCFG_RX_UNICAST] = antcfg_def;
antsel->num_antcfg = ANT_SELCFG_NUM_2x3;
} else if (asi->antsel_type == ANTSEL_2x4) {
antsel->ant_config[ANT_SELCFG_TX_DEF] = ANT_SELCFG_DEF_2x4;
antsel->ant_config[ANT_SELCFG_TX_UNICAST] = ANT_SELCFG_DEF_2x4;
antsel->ant_config[ANT_SELCFG_RX_DEF] = ANT_SELCFG_DEF_2x4;
antsel->ant_config[ANT_SELCFG_RX_UNICAST] = ANT_SELCFG_DEF_2x4;
antsel->num_antcfg = ANT_SELCFG_NUM_2x4;
} else {
antsel->ant_config[ANT_SELCFG_TX_DEF] = ANT_SELCFG_DEF_2x2;
antsel->ant_config[ANT_SELCFG_TX_UNICAST] = ANT_SELCFG_DEF_2x2;
antsel->ant_config[ANT_SELCFG_RX_DEF] = ANT_SELCFG_DEF_2x2;
antsel->ant_config[ANT_SELCFG_RX_UNICAST] = ANT_SELCFG_DEF_2x2;
antsel->num_antcfg = 0;
}
}
struct antsel_info *brcms_c_antsel_attach(struct brcms_c_info *wlc)
{
struct antsel_info *asi;
struct ssb_sprom *sprom = &wlc->hw->d11core->bus->sprom;
asi = kzalloc(sizeof(struct antsel_info), GFP_ATOMIC);
if (!asi)
return NULL;
asi->wlc = wlc;
asi->pub = wlc->pub;
asi->antsel_type = ANTSEL_NA;
asi->antsel_avail = false;
asi->antsel_antswitch = sprom->antswitch;
if ((asi->pub->sromrev >= 4) && (asi->antsel_antswitch != 0)) {
switch (asi->antsel_antswitch) {
case ANTSWITCH_TYPE_1:
case ANTSWITCH_TYPE_2:
case ANTSWITCH_TYPE_3:
asi->antsel_type = ANTSEL_2x3;
if ((sprom->ant_available_bg == 7) ||
(sprom->ant_available_a == 7)) {
asi->antsel_avail = true;
} else if (
sprom->ant_available_bg == 3 ||
sprom->ant_available_a == 3) {
asi->antsel_avail = false;
} else {
asi->antsel_avail = false;
brcms_err(wlc->hw->d11core,
"antsel_attach: 2o3 "
"board cfg invalid\n");
}
break;
default:
break;
}
} else if ((asi->pub->sromrev == 4) &&
(sprom->ant_available_bg == 7) &&
(sprom->ant_available_a == 0)) {
asi->antsel_type = ANTSEL_2x3;
asi->antsel_avail = true;
} else if (asi->pub->boardflags2 & BFL2_2X4_DIV) {
asi->antsel_type = ANTSEL_2x4;
asi->antsel_avail = true;
}
brcms_b_antsel_type_set(wlc->hw, asi->antsel_type);
brcms_c_antsel_init_cfg(asi, &asi->antcfg_11n, true);
brcms_c_antsel_init_cfg(asi, &asi->antcfg_cur, true);
return asi;
}
void brcms_c_antsel_detach(struct antsel_info *asi)
{
kfree(asi);
}
static u16 brcms_c_antsel_antcfg2antsel(struct antsel_info *asi, u8 ant_cfg)
{
u8 idx = BRCMS_ANTIDX_11N(BRCMS_ANTSEL_11N(ant_cfg));
u16 mimo_antsel = 0;
if (asi->antsel_type == ANTSEL_2x4) {
mimo_antsel = (mimo_2x4_div_antselpat_tbl[idx] & 0xf);
return mimo_antsel;
} else if (asi->antsel_type == ANTSEL_2x3) {
mimo_antsel = (mimo_2x3_div_antselpat_tbl[idx] & 0xf);
return mimo_antsel;
}
return mimo_antsel;
}
static int brcms_c_antsel_cfgupd(struct antsel_info *asi,
struct brcms_antselcfg *antsel)
{
struct brcms_c_info *wlc = asi->wlc;
u8 ant_cfg;
u16 mimo_antsel;
ant_cfg = antsel->ant_config[ANT_SELCFG_TX_DEF];
mimo_antsel = brcms_c_antsel_antcfg2antsel(asi, ant_cfg);
brcms_b_write_shm(wlc->hw, M_MIMO_ANTSEL_TXDFLT, mimo_antsel);
asi->antcfg_cur.ant_config[ANT_SELCFG_TX_DEF] = ant_cfg;
ant_cfg = antsel->ant_config[ANT_SELCFG_RX_DEF];
mimo_antsel = brcms_c_antsel_antcfg2antsel(asi, ant_cfg);
brcms_b_write_shm(wlc->hw, M_MIMO_ANTSEL_RXDFLT, mimo_antsel);
asi->antcfg_cur.ant_config[ANT_SELCFG_RX_DEF] = ant_cfg;
return 0;
}
void brcms_c_antsel_init(struct antsel_info *asi)
{
if ((asi->antsel_type == ANTSEL_2x3) ||
(asi->antsel_type == ANTSEL_2x4))
brcms_c_antsel_cfgupd(asi, &asi->antcfg_11n);
}
static u8 brcms_c_antsel_id2antcfg(struct antsel_info *asi, u8 id)
{
u8 antcfg = ANT_SELCFG_DEF_2x2;
if (asi->antsel_type == ANTSEL_2x4) {
antcfg = (((id & 0x2) << 3) | ((id & 0x1) + 2));
return antcfg;
} else if (asi->antsel_type == ANTSEL_2x3) {
antcfg = (((id & 0x02) << 4) | ((id & 0x1) + 1));
return antcfg;
}
return antcfg;
}
void
brcms_c_antsel_antcfg_get(struct antsel_info *asi, bool usedef, bool sel,
u8 antselid, u8 fbantselid, u8 *antcfg,
u8 *fbantcfg)
{
u8 ant;
if (usedef) {
*antcfg = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_DEF];
*fbantcfg = *antcfg;
return;
}
if (!sel) {
*antcfg = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
*fbantcfg = *antcfg;
} else {
ant = asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
if ((ant & ANT_SELCFG_AUTO) == ANT_SELCFG_AUTO) {
*antcfg = brcms_c_antsel_id2antcfg(asi, antselid);
*fbantcfg = brcms_c_antsel_id2antcfg(asi, fbantselid);
} else {
*antcfg =
asi->antcfg_11n.ant_config[ANT_SELCFG_TX_UNICAST];
*fbantcfg = *antcfg;
}
}
return;
}
u8 brcms_c_antsel_antsel2id(struct antsel_info *asi, u16 antsel)
{
u8 antselid = 0;
if (asi->antsel_type == ANTSEL_2x4) {
antselid = mimo_2x4_div_antselid_tbl[(antsel & 0xf)];
return antselid;
} else if (asi->antsel_type == ANTSEL_2x3) {
antselid = mimo_2x3_div_antselid_tbl[(antsel & 0xf)];
return antselid;
}
return antselid;
}
