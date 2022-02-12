static int __init parse_l2cache(char *p)
{
char *cp = p;
if (get_option(&cp, &l2cache_init) != 1) {
pr_err("Bad l2cache parameter (%s)\n", p);
return 1;
}
return 0;
}
static int __init parse_l2cache_pf(char *p)
{
char *cp = p;
if (get_option(&cp, &l2cache_init_pf) != 1) {
pr_err("Bad l2cache_pf parameter (%s)\n", p);
return 1;
}
return 0;
}
static int __init meta_l2c_setup(void)
{
if (!meta_l2c_is_present()) {
pr_info("L2 Cache: Not present\n");
return 0;
}
if (!meta_l2c_linesize()) {
pr_warn_once("L2 Cache: unknown line size id (config=0x%08x)\n",
meta_l2c_config());
}
l2c_pfenable = _meta_l2c_pf_is_enabled();
if (l2cache_init) {
pr_info("L2 Cache: Enabling... ");
if (meta_l2c_enable())
pr_cont("already enabled\n");
else
pr_cont("done\n");
} else {
pr_info("L2 Cache: Not enabling\n");
}
if (l2cache_init_pf) {
pr_info("L2 Cache: Enabling prefetch... ");
if (meta_l2c_pf_enable(1))
pr_cont("already enabled\n");
else
pr_cont("done\n");
} else {
pr_info("L2 Cache: Not enabling prefetch\n");
}
return 0;
}
int meta_l2c_disable(void)
{
unsigned long flags;
int en;
if (!meta_l2c_is_present())
return 1;
__global_lock2(flags);
en = meta_l2c_is_enabled();
if (likely(en)) {
_meta_l2c_pf_enable(0);
wr_fence();
_meta_l2c_purge();
_meta_l2c_enable(0);
}
__global_unlock2(flags);
return !en;
}
int meta_l2c_enable(void)
{
unsigned long flags;
int en;
if (!meta_l2c_is_present())
return 0;
__global_lock1(flags);
en = meta_l2c_is_enabled();
if (likely(!en)) {
_meta_l2c_init();
_meta_l2c_enable(1);
_meta_l2c_pf_enable(l2c_pfenable);
}
__global_unlock1(flags);
return en;
}
int meta_l2c_pf_enable(int pfenable)
{
unsigned long flags;
int en = l2c_pfenable;
if (!meta_l2c_is_present())
return 0;
__global_lock1(flags);
en = l2c_pfenable;
l2c_pfenable = pfenable;
if (meta_l2c_is_enabled())
_meta_l2c_pf_enable(pfenable);
__global_unlock1(flags);
return en;
}
int meta_l2c_flush(void)
{
unsigned long flags;
int en;
__global_lock2(flags);
en = meta_l2c_is_enabled();
if (likely(en)) {
_meta_l2c_pf_enable(0);
wr_fence();
_meta_l2c_purge();
_meta_l2c_enable(0);
_meta_l2c_init();
_meta_l2c_enable(1);
_meta_l2c_pf_enable(l2c_pfenable);
}
__global_unlock2(flags);
return !en;
}
