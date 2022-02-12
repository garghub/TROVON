static int __set_clk_parents(struct device_node *node, bool clk_supplier)
{
struct of_phandle_args clkspec;
int index, rc, num_parents;
struct clk *clk, *pclk;
num_parents = of_count_phandle_with_args(node, "assigned-clock-parents",
"#clock-cells");
if (num_parents == -EINVAL)
pr_err("clk: invalid value of clock-parents property at %s\n",
node->full_name);
for (index = 0; index < num_parents; index++) {
rc = of_parse_phandle_with_args(node, "assigned-clock-parents",
"#clock-cells", index, &clkspec);
if (rc < 0) {
if (rc == -ENOENT)
continue;
else
return rc;
}
if (clkspec.np == node && !clk_supplier)
return 0;
pclk = of_clk_get_from_provider(&clkspec);
if (IS_ERR(pclk)) {
pr_warn("clk: couldn't get parent clock %d for %s\n",
index, node->full_name);
return PTR_ERR(pclk);
}
rc = of_parse_phandle_with_args(node, "assigned-clocks",
"#clock-cells", index, &clkspec);
if (rc < 0)
goto err;
if (clkspec.np == node && !clk_supplier) {
rc = 0;
goto err;
}
clk = of_clk_get_from_provider(&clkspec);
if (IS_ERR(clk)) {
pr_warn("clk: couldn't get parent clock %d for %s\n",
index, node->full_name);
rc = PTR_ERR(clk);
goto err;
}
rc = clk_set_parent(clk, pclk);
if (rc < 0)
pr_err("clk: failed to reparent %s to %s: %d\n",
__clk_get_name(clk), __clk_get_name(pclk), rc);
clk_put(clk);
clk_put(pclk);
}
return 0;
err:
clk_put(pclk);
return rc;
}
static int __set_clk_rates(struct device_node *node, bool clk_supplier)
{
struct of_phandle_args clkspec;
struct property *prop;
const __be32 *cur;
int rc, index = 0;
struct clk *clk;
u32 rate;
of_property_for_each_u32(node, "assigned-clock-rates", prop, cur, rate) {
if (rate) {
rc = of_parse_phandle_with_args(node, "assigned-clocks",
"#clock-cells", index, &clkspec);
if (rc < 0) {
if (rc == -ENOENT)
continue;
else
return rc;
}
if (clkspec.np == node && !clk_supplier)
return 0;
clk = of_clk_get_from_provider(&clkspec);
if (IS_ERR(clk)) {
pr_warn("clk: couldn't get clock %d for %s\n",
index, node->full_name);
return PTR_ERR(clk);
}
rc = clk_set_rate(clk, rate);
if (rc < 0)
pr_err("clk: couldn't set %s clock rate: %d\n",
__clk_get_name(clk), rc);
clk_put(clk);
}
index++;
}
return 0;
}
int of_clk_set_defaults(struct device_node *node, bool clk_supplier)
{
int rc;
if (!node)
return 0;
rc = __set_clk_parents(node, clk_supplier);
if (rc < 0)
return rc;
return __set_clk_rates(node, clk_supplier);
}
