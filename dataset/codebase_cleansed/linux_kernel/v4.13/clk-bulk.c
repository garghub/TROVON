void clk_bulk_put(int num_clks, struct clk_bulk_data *clks)
{
while (--num_clks >= 0) {
clk_put(clks[num_clks].clk);
clks[num_clks].clk = NULL;
}
}
int __must_check clk_bulk_get(struct device *dev, int num_clks,
struct clk_bulk_data *clks)
{
int ret;
int i;
for (i = 0; i < num_clks; i++)
clks[i].clk = NULL;
for (i = 0; i < num_clks; i++) {
clks[i].clk = clk_get(dev, clks[i].id);
if (IS_ERR(clks[i].clk)) {
ret = PTR_ERR(clks[i].clk);
dev_err(dev, "Failed to get clk '%s': %d\n",
clks[i].id, ret);
clks[i].clk = NULL;
goto err;
}
}
return 0;
err:
clk_bulk_put(i, clks);
return ret;
}
void clk_bulk_unprepare(int num_clks, const struct clk_bulk_data *clks)
{
while (--num_clks >= 0)
clk_unprepare(clks[num_clks].clk);
}
int __must_check clk_bulk_prepare(int num_clks,
const struct clk_bulk_data *clks)
{
int ret;
int i;
for (i = 0; i < num_clks; i++) {
ret = clk_prepare(clks[i].clk);
if (ret) {
pr_err("Failed to prepare clk '%s': %d\n",
clks[i].id, ret);
goto err;
}
}
return 0;
err:
clk_bulk_unprepare(i, clks);
return ret;
}
void clk_bulk_disable(int num_clks, const struct clk_bulk_data *clks)
{
while (--num_clks >= 0)
clk_disable(clks[num_clks].clk);
}
int __must_check clk_bulk_enable(int num_clks, const struct clk_bulk_data *clks)
{
int ret;
int i;
for (i = 0; i < num_clks; i++) {
ret = clk_enable(clks[i].clk);
if (ret) {
pr_err("Failed to enable clk '%s': %d\n",
clks[i].id, ret);
goto err;
}
}
return 0;
err:
clk_bulk_disable(i, clks);
return ret;
}
