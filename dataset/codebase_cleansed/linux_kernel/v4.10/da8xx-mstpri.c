static const struct da8xx_mstpri_board_priorities *
da8xx_mstpri_get_board_prio(void)
{
const struct da8xx_mstpri_board_priorities *board_prio;
int i;
for (i = 0; i < ARRAY_SIZE(da8xx_mstpri_board_confs); i++) {
board_prio = &da8xx_mstpri_board_confs[i];
if (of_machine_is_compatible(board_prio->board))
return board_prio;
}
return NULL;
}
static int da8xx_mstpri_probe(struct platform_device *pdev)
{
const struct da8xx_mstpri_board_priorities *prio_list;
const struct da8xx_mstpri_descr *prio_descr;
const struct da8xx_mstpri_priority *prio;
struct device *dev = &pdev->dev;
struct resource *res;
void __iomem *mstpri;
u32 reg;
int i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mstpri = devm_ioremap_resource(dev, res);
if (IS_ERR(mstpri)) {
dev_err(dev, "unable to map MSTPRI registers\n");
return PTR_ERR(mstpri);
}
prio_list = da8xx_mstpri_get_board_prio();
if (!prio_list) {
dev_err(dev, "no master priorities defined for this board\n");
return -EINVAL;
}
for (i = 0; i < prio_list->numprio; i++) {
prio = &prio_list->priorities[i];
prio_descr = &da8xx_mstpri_priority_list[prio->which];
if (prio_descr->reg + sizeof(u32) > resource_size(res)) {
dev_warn(dev, "register offset out of range\n");
continue;
}
reg = readl(mstpri + prio_descr->reg);
reg &= ~prio_descr->mask;
reg |= prio->val << prio_descr->shift;
writel(reg, mstpri + prio_descr->reg);
}
return 0;
}
