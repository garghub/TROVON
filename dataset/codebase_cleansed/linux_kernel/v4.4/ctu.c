static void __rsnd_ctu_initialize_lock(struct rsnd_mod *mod, u32 enable)
{
rsnd_mod_write(mod, CTU_CTUIR, enable);
}
static int rsnd_ctu_init(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
rsnd_mod_power_on(mod);
rsnd_ctu_initialize_lock(mod);
rsnd_mod_write(mod, CTU_ADINR, rsnd_get_adinr_chan(mod, io));
rsnd_ctu_initialize_unlock(mod);
return 0;
}
static int rsnd_ctu_quit(struct rsnd_mod *mod,
struct rsnd_dai_stream *io,
struct rsnd_priv *priv)
{
rsnd_mod_power_off(mod);
return 0;
}
struct rsnd_mod *rsnd_ctu_mod_get(struct rsnd_priv *priv, int id)
{
if (WARN_ON(id < 0 || id >= rsnd_ctu_nr(priv)))
id = 0;
return rsnd_mod_get((struct rsnd_ctu *)(priv->ctu) + id);
}
static void rsnd_of_parse_ctu(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device_node *node;
struct rsnd_ctu_platform_info *ctu_info;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = &pdev->dev;
int nr;
if (!of_data)
return;
node = of_get_child_by_name(dev->of_node, "rcar_sound,ctu");
if (!node)
return;
nr = of_get_child_count(node);
if (!nr)
goto rsnd_of_parse_ctu_end;
ctu_info = devm_kzalloc(dev,
sizeof(struct rsnd_ctu_platform_info) * nr,
GFP_KERNEL);
if (!ctu_info) {
dev_err(dev, "ctu info allocation error\n");
goto rsnd_of_parse_ctu_end;
}
info->ctu_info = ctu_info;
info->ctu_info_nr = nr;
rsnd_of_parse_ctu_end:
of_node_put(node);
}
int rsnd_ctu_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_ctu *ctu;
struct clk *clk;
char name[CTU_NAME_SIZE];
int i, nr, ret;
if (rsnd_is_gen1(priv))
return 0;
rsnd_of_parse_ctu(pdev, of_data, priv);
nr = info->ctu_info_nr;
if (!nr)
return 0;
ctu = devm_kzalloc(dev, sizeof(*ctu) * nr, GFP_KERNEL);
if (!ctu)
return -ENOMEM;
priv->ctu_nr = nr;
priv->ctu = ctu;
for_each_rsnd_ctu(ctu, priv, i) {
snprintf(name, CTU_NAME_SIZE, "%s.%d",
CTU_NAME, i / 4);
clk = devm_clk_get(dev, name);
if (IS_ERR(clk))
return PTR_ERR(clk);
ctu->info = &info->ctu_info[i];
ret = rsnd_mod_init(priv, rsnd_mod_get(ctu), &rsnd_ctu_ops,
clk, RSND_MOD_CTU, i);
if (ret)
return ret;
}
return 0;
}
void rsnd_ctu_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_ctu *ctu;
int i;
for_each_rsnd_ctu(ctu, priv, i) {
rsnd_mod_quit(rsnd_mod_get(ctu));
}
}
