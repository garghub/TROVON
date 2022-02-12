void dsp_hwec_enable(struct dsp *dsp, const char *arg)
{
int deftaps = 128,
len;
struct mISDN_ctrl_req cq;
if (!dsp) {
printk(KERN_ERR "%s: failed to enable hwec: dsp is NULL\n",
__func__);
return;
}
if (!arg)
goto _do;
len = strlen(arg);
if (!len)
goto _do;
{
char _dup[len + 1];
char *dup, *tok, *name, *val;
int tmp;
strcpy(_dup, arg);
dup = _dup;
while ((tok = strsep(&dup, ","))) {
if (!strlen(tok))
continue;
name = strsep(&tok, "=");
val = tok;
if (!val)
continue;
if (!strcmp(name, "deftaps")) {
if (sscanf(val, "%d", &tmp) == 1)
deftaps = tmp;
}
}
}
_do:
printk(KERN_DEBUG "%s: enabling hwec with deftaps=%d\n",
__func__, deftaps);
memset(&cq, 0, sizeof(cq));
cq.op = MISDN_CTRL_HFC_ECHOCAN_ON;
cq.p1 = deftaps;
if (!dsp->ch.peer->ctrl(&dsp->ch, CONTROL_CHANNEL, &cq)) {
printk(KERN_DEBUG "%s: CONTROL_CHANNEL failed\n",
__func__);
return;
}
}
void dsp_hwec_disable(struct dsp *dsp)
{
struct mISDN_ctrl_req cq;
if (!dsp) {
printk(KERN_ERR "%s: failed to disable hwec: dsp is NULL\n",
__func__);
return;
}
printk(KERN_DEBUG "%s: disabling hwec\n", __func__);
memset(&cq, 0, sizeof(cq));
cq.op = MISDN_CTRL_HFC_ECHOCAN_OFF;
if (!dsp->ch.peer->ctrl(&dsp->ch, CONTROL_CHANNEL, &cq)) {
printk(KERN_DEBUG "%s: CONTROL_CHANNEL failed\n",
__func__);
return;
}
}
int dsp_hwec_init(void)
{
mISDN_dsp_element_register(dsp_hwec);
return 0;
}
void dsp_hwec_exit(void)
{
mISDN_dsp_element_unregister(dsp_hwec);
}
