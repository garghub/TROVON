static inline struct mtk_ref2usb_tx *to_mtk_ref2usb_tx(struct clk_hw *hw)
{
return container_of(hw, struct mtk_ref2usb_tx, hw);
}
static int mtk_ref2usb_tx_is_prepared(struct clk_hw *hw)
{
struct mtk_ref2usb_tx *tx = to_mtk_ref2usb_tx(hw);
return (readl(tx->base_addr) & REF2USB_EN_MASK) == REF2USB_EN_MASK;
}
static int mtk_ref2usb_tx_prepare(struct clk_hw *hw)
{
struct mtk_ref2usb_tx *tx = to_mtk_ref2usb_tx(hw);
u32 val;
val = readl(tx->base_addr);
val |= REF2USB_TX_EN;
writel(val, tx->base_addr);
udelay(100);
val |= REF2USB_TX_LPF_EN;
writel(val, tx->base_addr);
val |= REF2USB_TX_OUT_EN;
writel(val, tx->base_addr);
return 0;
}
static void mtk_ref2usb_tx_unprepare(struct clk_hw *hw)
{
struct mtk_ref2usb_tx *tx = to_mtk_ref2usb_tx(hw);
u32 val;
val = readl(tx->base_addr);
val &= ~REF2USB_EN_MASK;
writel(val, tx->base_addr);
}
struct clk * __init mtk_clk_register_ref2usb_tx(const char *name,
const char *parent_name, void __iomem *reg)
{
struct mtk_ref2usb_tx *tx;
struct clk_init_data init = {};
struct clk *clk;
tx = kzalloc(sizeof(*tx), GFP_KERNEL);
if (!tx)
return ERR_PTR(-ENOMEM);
tx->base_addr = reg;
tx->hw.init = &init;
init.name = name;
init.ops = &mtk_ref2usb_tx_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(NULL, &tx->hw);
if (IS_ERR(clk)) {
pr_err("Failed to register clk %s: %ld\n", name, PTR_ERR(clk));
kfree(tx);
}
return clk;
}
