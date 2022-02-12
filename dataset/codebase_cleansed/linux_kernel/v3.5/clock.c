static void __clk_disable(struct clk *clk)
{
if (clk == NULL || IS_ERR(clk))
return;
WARN_ON(!clk->usecount);
if (!(--clk->usecount)) {
if (clk->disable)
clk->disable(clk);
__clk_disable(clk->parent);
__clk_disable(clk->secondary);
}
}
static int __clk_enable(struct clk *clk)
{
if (clk == NULL || IS_ERR(clk))
return -EINVAL;
if (clk->usecount++ == 0) {
__clk_enable(clk->parent);
__clk_enable(clk->secondary);
if (clk->enable)
clk->enable(clk);
}
return 0;
}
int clk_enable(struct clk *clk)
{
int ret = 0;
if (clk == NULL || IS_ERR(clk))
return -EINVAL;
mutex_lock(&clocks_mutex);
ret = __clk_enable(clk);
mutex_unlock(&clocks_mutex);
return ret;
}
void clk_disable(struct clk *clk)
{
if (clk == NULL || IS_ERR(clk))
return;
mutex_lock(&clocks_mutex);
__clk_disable(clk);
mutex_unlock(&clocks_mutex);
}
unsigned long clk_get_rate(struct clk *clk)
{
if (clk == NULL || IS_ERR(clk))
return 0UL;
if (clk->get_rate)
return clk->get_rate(clk);
return clk_get_rate(clk->parent);
}
long clk_round_rate(struct clk *clk, unsigned long rate)
{
if (clk == NULL || IS_ERR(clk) || !clk->round_rate)
return 0;
return clk->round_rate(clk, rate);
}
int clk_set_rate(struct clk *clk, unsigned long rate)
{
int ret = -EINVAL;
if (clk == NULL || IS_ERR(clk) || clk->set_rate == NULL || rate == 0)
return ret;
mutex_lock(&clocks_mutex);
ret = clk->set_rate(clk, rate);
mutex_unlock(&clocks_mutex);
return ret;
}
int clk_set_parent(struct clk *clk, struct clk *parent)
{
int ret = -EINVAL;
struct clk *old;
if (clk == NULL || IS_ERR(clk) || parent == NULL ||
IS_ERR(parent) || clk->set_parent == NULL)
return ret;
if (clk->usecount)
clk_enable(parent);
mutex_lock(&clocks_mutex);
ret = clk->set_parent(clk, parent);
if (ret == 0) {
old = clk->parent;
clk->parent = parent;
} else {
old = parent;
}
mutex_unlock(&clocks_mutex);
if (clk->usecount)
clk_disable(old);
return ret;
}
struct clk *clk_get_parent(struct clk *clk)
{
struct clk *ret = NULL;
if (clk == NULL || IS_ERR(clk))
return ret;
return clk->parent;
}
unsigned long mxc_decode_pll(unsigned int reg_val, u32 freq)
{
long long ll;
int mfn_abs;
unsigned int mfi, mfn, mfd, pd;
mfi = (reg_val >> 10) & 0xf;
mfn = reg_val & 0x3ff;
mfd = (reg_val >> 16) & 0x3ff;
pd = (reg_val >> 26) & 0xf;
mfi = mfi <= 5 ? 5 : mfi;
mfn_abs = mfn;
if (!cpu_is_mx1() && !cpu_is_mx21() && mfn >= 0x200)
mfn_abs = 0x400 - mfn;
freq *= 2;
freq /= pd + 1;
ll = (unsigned long long)freq * mfn_abs;
do_div(ll, mfd + 1);
if (!cpu_is_mx1() && !cpu_is_mx21() && mfn >= 0x200)
ll = -ll;
ll = (freq * mfi) + ll;
return ll;
}
