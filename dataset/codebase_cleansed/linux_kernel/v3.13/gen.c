static int rsnd_regmap_write32(void *context, const void *_data, size_t count)
{
struct rsnd_priv *priv = context;
struct device *dev = rsnd_priv_to_dev(priv);
u32 *data = (u32 *)_data;
u32 val = data[1];
void __iomem *reg = (void *)data[0];
iowrite32(val, reg);
dev_dbg(dev, "w %p : %08x\n", reg, val);
return 0;
}
static int rsnd_regmap_read32(void *context,
const void *_data, size_t reg_size,
void *_val, size_t val_size)
{
struct rsnd_priv *priv = context;
struct device *dev = rsnd_priv_to_dev(priv);
u32 *data = (u32 *)_data;
u32 *val = (u32 *)_val;
void __iomem *reg = (void *)data[0];
*val = ioread32(reg);
dev_dbg(dev, "r %p : %08x\n", reg, *val);
return 0;
}
u32 rsnd_read(struct rsnd_priv *priv,
struct rsnd_mod *mod, enum rsnd_reg reg)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
u32 val;
regmap_fields_read(gen->regs[reg], rsnd_mod_id(mod), &val);
return val;
}
void rsnd_write(struct rsnd_priv *priv,
struct rsnd_mod *mod,
enum rsnd_reg reg, u32 data)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
regmap_fields_write(gen->regs[reg], rsnd_mod_id(mod), data);
}
void rsnd_bset(struct rsnd_priv *priv, struct rsnd_mod *mod,
enum rsnd_reg reg, u32 mask, u32 data)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
regmap_fields_update_bits(gen->regs[reg], rsnd_mod_id(mod),
mask, data);
}
static int rsnd_gen1_path_init(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_mod *mod;
int ret;
int id;
mod = rsnd_ssi_mod_get_frm_dai(priv,
rsnd_dai_id(priv, rdai),
rsnd_dai_is_play(rdai, io));
id = rsnd_mod_id(mod);
mod = rsnd_ssi_mod_get(priv, id);
ret = rsnd_dai_connect(rdai, mod, io);
if (ret < 0)
return ret;
mod = rsnd_scu_mod_get(priv, id);
ret = rsnd_dai_connect(rdai, mod, io);
return ret;
}
static int rsnd_gen1_path_exit(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_mod *mod, *n;
int ret = 0;
for_each_rsnd_mod(mod, n, io)
ret |= rsnd_dai_disconnect(mod);
return ret;
}
static int rsnd_gen1_regmap_init(struct rsnd_priv *priv, struct rsnd_gen *gen)
{
int i;
struct device *dev = rsnd_priv_to_dev(priv);
struct regmap_config regc;
struct reg_field regf[RSND_REG_MAX] = {
RSND_GEN1_S_REG(gen, SRU, SRC_ROUTE_SEL, 0x00),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL0, 0x08),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL1, 0x0c),
RSND_GEN1_S_REG(gen, SRU, SRC_TMG_SEL2, 0x10),
RSND_GEN1_S_REG(gen, SRU, SRC_CTRL, 0xc0),
RSND_GEN1_S_REG(gen, SRU, SSI_MODE0, 0xD0),
RSND_GEN1_S_REG(gen, SRU, SSI_MODE1, 0xD4),
RSND_GEN1_M_REG(gen, SRU, BUSIF_MODE, 0x20, 0x4),
RSND_GEN1_M_REG(gen, SRU, BUSIF_ADINR, 0x214, 0x40),
RSND_GEN1_S_REG(gen, ADG, BRRA, 0x00),
RSND_GEN1_S_REG(gen, ADG, BRRB, 0x04),
RSND_GEN1_S_REG(gen, ADG, SSICKR, 0x08),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL0, 0x0c),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL1, 0x10),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL3, 0x18),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL4, 0x1c),
RSND_GEN1_S_REG(gen, ADG, AUDIO_CLK_SEL5, 0x20),
RSND_GEN1_M_REG(gen, SSI, SSICR, 0x00, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSISR, 0x04, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSITDR, 0x08, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSIRDR, 0x0c, 0x40),
RSND_GEN1_M_REG(gen, SSI, SSIWSR, 0x20, 0x40),
};
memset(&regc, 0, sizeof(regc));
regc.reg_bits = 32;
regc.val_bits = 32;
gen->regmap = devm_regmap_init(dev, &rsnd_regmap_bus, priv, &regc);
if (IS_ERR(gen->regmap)) {
dev_err(dev, "regmap error %ld\n", PTR_ERR(gen->regmap));
return PTR_ERR(gen->regmap);
}
for (i = 0; i < RSND_REG_MAX; i++) {
gen->regs[i] = devm_regmap_field_alloc(dev, gen->regmap, regf[i]);
if (IS_ERR(gen->regs[i]))
return PTR_ERR(gen->regs[i]);
}
return 0;
}
static int rsnd_gen1_probe(struct platform_device *pdev,
struct rcar_snd_info *info,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
struct resource *sru_res;
struct resource *adg_res;
struct resource *ssi_res;
int ret;
sru_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_SRU);
adg_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_ADG);
ssi_res = platform_get_resource(pdev, IORESOURCE_MEM, RSND_GEN1_SSI);
gen->base[RSND_GEN1_SRU] = devm_ioremap_resource(dev, sru_res);
gen->base[RSND_GEN1_ADG] = devm_ioremap_resource(dev, adg_res);
gen->base[RSND_GEN1_SSI] = devm_ioremap_resource(dev, ssi_res);
if (IS_ERR(gen->base[RSND_GEN1_SRU]) ||
IS_ERR(gen->base[RSND_GEN1_ADG]) ||
IS_ERR(gen->base[RSND_GEN1_SSI]))
return -ENODEV;
ret = rsnd_gen1_regmap_init(priv, gen);
if (ret < 0)
return ret;
dev_dbg(dev, "Gen1 device probed\n");
dev_dbg(dev, "SRU : %08x => %p\n", sru_res->start,
gen->base[RSND_GEN1_SRU]);
dev_dbg(dev, "ADG : %08x => %p\n", adg_res->start,
gen->base[RSND_GEN1_ADG]);
dev_dbg(dev, "SSI : %08x => %p\n", ssi_res->start,
gen->base[RSND_GEN1_SSI]);
return 0;
}
static void rsnd_gen1_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
}
int rsnd_gen_path_init(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
return gen->ops->path_init(priv, rdai, io);
}
int rsnd_gen_path_exit(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
return gen->ops->path_exit(priv, rdai, io);
}
int rsnd_gen_probe(struct platform_device *pdev,
struct rcar_snd_info *info,
struct rsnd_priv *priv)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct rsnd_gen *gen;
gen = devm_kzalloc(dev, sizeof(*gen), GFP_KERNEL);
if (!gen) {
dev_err(dev, "GEN allocate failed\n");
return -ENOMEM;
}
if (rsnd_is_gen1(priv))
gen->ops = &rsnd_gen1_ops;
if (!gen->ops) {
dev_err(dev, "unknown generation R-Car sound device\n");
return -ENODEV;
}
priv->gen = gen;
return gen->ops->probe(pdev, info, priv);
}
void rsnd_gen_remove(struct platform_device *pdev,
struct rsnd_priv *priv)
{
struct rsnd_gen *gen = rsnd_priv_to_gen(priv);
gen->ops->remove(pdev, priv);
}
