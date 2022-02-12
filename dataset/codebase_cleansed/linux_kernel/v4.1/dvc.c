static void rsnd_dvc_volume_update(struct rsnd_mod *mod)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
u32 val[RSND_DVC_CHANNELS];
u32 dvucr = 0;
u32 mute = 0;
int i;
for (i = 0; i < dvc->mute.cfg.size; i++)
mute |= (!!dvc->mute.cfg.val[i]) << i;
rsnd_mod_write(mod, DVC_DVUER, 0);
if (dvc->ren.val) {
dvucr |= 0x10;
for (i = 0; i < RSND_DVC_CHANNELS; i++)
val[i] = dvc->volume.cfg.max;
rsnd_mod_write(mod, DVC_VRCTR, 0xff);
rsnd_mod_write(mod, DVC_VRPDR, dvc->rup.val << 8 |
dvc->rdown.val);
rsnd_mod_write(mod, DVC_VRDBR,
0x3ff - (dvc->volume.val[0] >> 13));
} else {
for (i = 0; i < RSND_DVC_CHANNELS; i++)
val[i] = dvc->volume.val[i];
}
dvucr |= 0x100;
rsnd_mod_write(mod, DVC_VOL0R, val[0]);
rsnd_mod_write(mod, DVC_VOL1R, val[1]);
if (mute) {
dvucr |= 0x1;
rsnd_mod_write(mod, DVC_ZCMCR, mute);
}
rsnd_mod_write(mod, DVC_DVUCR, dvucr);
rsnd_mod_write(mod, DVC_DVUER, 1);
}
static int rsnd_dvc_remove_gen2(struct rsnd_mod *mod,
struct rsnd_priv *priv)
{
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
rsnd_kctrl_remove(dvc->volume);
rsnd_kctrl_remove(dvc->mute);
rsnd_kctrl_remove(dvc->ren);
rsnd_kctrl_remove(dvc->rup);
rsnd_kctrl_remove(dvc->rdown);
return 0;
}
static int rsnd_dvc_init(struct rsnd_mod *dvc_mod,
struct rsnd_priv *priv)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(dvc_mod);
struct rsnd_mod *src_mod = rsnd_io_to_mod_src(io);
struct device *dev = rsnd_priv_to_dev(priv);
int dvc_id = rsnd_mod_id(dvc_mod);
int src_id = rsnd_mod_id(src_mod);
u32 route[] = {
[0] = 0x30000,
[1] = 0x30001,
[2] = 0x40000,
[3] = 0x10000,
[4] = 0x20000,
[5] = 0x40100
};
if (src_id >= ARRAY_SIZE(route)) {
dev_err(dev, "DVC%d isn't connected to SRC%d\n", dvc_id, src_id);
return -EINVAL;
}
rsnd_mod_hw_start(dvc_mod);
rsnd_mod_write(dvc_mod, CMD_ROUTE_SLCT, route[src_id]);
rsnd_mod_write(dvc_mod, DVC_SWRSR, 0);
rsnd_mod_write(dvc_mod, DVC_SWRSR, 1);
rsnd_mod_write(dvc_mod, DVC_DVUIR, 1);
rsnd_mod_write(dvc_mod, DVC_ADINR, rsnd_get_adinr(dvc_mod));
rsnd_dvc_volume_update(dvc_mod);
rsnd_mod_write(dvc_mod, DVC_DVUIR, 0);
rsnd_adg_set_cmd_timsel_gen2(dvc_mod, io);
return 0;
}
static int rsnd_dvc_quit(struct rsnd_mod *mod,
struct rsnd_priv *priv)
{
rsnd_mod_hw_stop(mod);
return 0;
}
static int rsnd_dvc_start(struct rsnd_mod *mod,
struct rsnd_priv *priv)
{
rsnd_mod_write(mod, CMD_CTRL, 0x10);
return 0;
}
static int rsnd_dvc_stop(struct rsnd_mod *mod,
struct rsnd_priv *priv)
{
rsnd_mod_write(mod, CMD_CTRL, 0);
return 0;
}
static int rsnd_dvc_pcm_new(struct rsnd_mod *mod,
struct snd_soc_pcm_runtime *rtd)
{
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct rsnd_dvc *dvc = rsnd_mod_to_dvc(mod);
int is_play = rsnd_io_is_play(io);
int ret;
ret = rsnd_kctrl_new_m(mod, rtd,
is_play ?
"DVC Out Playback Volume" : "DVC In Capture Volume",
rsnd_dvc_volume_update,
&dvc->volume, 0x00800000 - 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_m(mod, rtd,
is_play ?
"DVC Out Mute Switch" : "DVC In Mute Switch",
rsnd_dvc_volume_update,
&dvc->mute, 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_s(mod, rtd,
is_play ?
"DVC Out Ramp Switch" : "DVC In Ramp Switch",
rsnd_dvc_volume_update,
&dvc->ren, 1);
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_e(mod, rtd,
is_play ?
"DVC Out Ramp Up Rate" : "DVC In Ramp Up Rate",
&dvc->rup,
rsnd_dvc_volume_update,
dvc_ramp_rate, ARRAY_SIZE(dvc_ramp_rate));
if (ret < 0)
return ret;
ret = rsnd_kctrl_new_e(mod, rtd,
is_play ?
"DVC Out Ramp Down Rate" : "DVC In Ramp Down Rate",
&dvc->rdown,
rsnd_dvc_volume_update,
dvc_ramp_rate, ARRAY_SIZE(dvc_ramp_rate));
if (ret < 0)
return ret;
return 0;
}
static struct dma_chan *rsnd_dvc_dma_req(struct rsnd_mod *mod)
{
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
return rsnd_dma_request_channel(rsnd_dvc_of_node(priv),
mod, "tx");
}
struct rsnd_mod *rsnd_dvc_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_dvc_nr(priv)))
id = 0;
return &((struct rsnd_dvc *)(priv->dvc) + id)->mod;
}
static void rsnd_of_parse_dvc(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device_node *node;
struct rsnd_dvc_platform_info *dvc_info;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = &pdev->dev;
int nr;
if (!of_data)
return;
node = of_get_child_by_name(dev->of_node, "rcar_sound,dvc");
if (!node)
return;
nr = of_get_child_count(node);
if (!nr)
goto rsnd_of_parse_dvc_end;
dvc_info = devm_kzalloc(dev,
sizeof(struct rsnd_dvc_platform_info) * nr,
GFP_KERNEL);
if (!dvc_info) {
dev_err(dev, "dvc info allocation error\n");
goto rsnd_of_parse_dvc_end;
}
info->dvc_info = dvc_info;
info->dvc_info_nr = nr;
rsnd_of_parse_dvc_end:
of_node_put(node);
}
int rsnd_dvc_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_dvc *dvc;
struct clk *clk;
char name[RSND_DVC_NAME_SIZE];
int i, nr, ret;
rsnd_of_parse_dvc(pdev, of_data, priv);
nr = info->dvc_info_nr;
if (!nr)
return 0;
if (rsnd_is_gen1(priv)) {
dev_warn(dev, "CMD is not supported on Gen1\n");
return -EINVAL;
}
dvc = devm_kzalloc(dev, sizeof(*dvc) * nr, GFP_KERNEL);
if (!dvc) {
dev_err(dev, "CMD allocate failed\n");
return -ENOMEM;
}
priv->dvc_nr = nr;
priv->dvc = dvc;
for_each_rsnd_dvc(dvc, priv, i) {
snprintf(name, RSND_DVC_NAME_SIZE, "%s.%d",
DVC_NAME, i);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
dvc->info = &info->dvc_info[i];
ret = rsnd_mod_init(&dvc->mod, &rsnd_dvc_ops,
clk, RSND_MOD_DVC, i);
if (ret)
return ret;
}
return 0;
}
void rsnd_dvc_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_dvc *dvc;
int i;
for_each_rsnd_dvc(dvc, priv, i) {
rsnd_mod_quit(&dvc->mod);
}
}
