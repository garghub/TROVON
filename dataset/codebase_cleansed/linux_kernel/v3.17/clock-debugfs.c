static int jz4740_clock_debugfs_show_enabled(void *data, uint64_t *value)
{
struct clk *clk = data;
*value = clk_is_enabled(clk);
return 0;
}
static int jz4740_clock_debugfs_set_enabled(void *data, uint64_t value)
{
struct clk *clk = data;
if (value)
return clk_enable(clk);
else
clk_disable(clk);
return 0;
}
static int jz4740_clock_debugfs_show_rate(void *data, uint64_t *value)
{
struct clk *clk = data;
*value = clk_get_rate(clk);
return 0;
}
void jz4740_clock_debugfs_add_clk(struct clk *clk)
{
if (!jz4740_clock_debugfs)
return;
clk->debugfs_entry = debugfs_create_dir(clk->name, jz4740_clock_debugfs);
debugfs_create_file("rate", S_IWUGO | S_IRUGO, clk->debugfs_entry, clk,
&jz4740_clock_debugfs_ops_rate);
debugfs_create_file("enabled", S_IRUGO, clk->debugfs_entry, clk,
&jz4740_clock_debugfs_ops_enabled);
if (clk->parent) {
char parent_path[100];
snprintf(parent_path, 100, "../%s", clk->parent->name);
clk->debugfs_parent_entry = debugfs_create_symlink("parent",
clk->debugfs_entry,
parent_path);
}
}
void jz4740_clock_debugfs_update_parent(struct clk *clk)
{
debugfs_remove(clk->debugfs_parent_entry);
if (clk->parent) {
char parent_path[100];
snprintf(parent_path, 100, "../%s", clk->parent->name);
clk->debugfs_parent_entry = debugfs_create_symlink("parent",
clk->debugfs_entry,
parent_path);
} else {
clk->debugfs_parent_entry = NULL;
}
}
void jz4740_clock_debugfs_init(void)
{
jz4740_clock_debugfs = debugfs_create_dir("jz4740-clock", NULL);
if (IS_ERR(jz4740_clock_debugfs))
jz4740_clock_debugfs = NULL;
}
