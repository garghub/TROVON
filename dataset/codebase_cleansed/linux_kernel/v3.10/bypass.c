static int do_cmd(struct net_device *dev, struct ifreq *ifr, int cmd, int *data)
{
int ret = -1;
struct if_bypass *bypass_cb;
static int (*ioctl) (struct net_device *, struct ifreq *, int);
bypass_cb = (struct if_bypass *)ifr;
bypass_cb->cmd = cmd;
bypass_cb->data = *data;
if ((dev->netdev_ops) && (ioctl = dev->netdev_ops->ndo_do_ioctl)) {
ret = ioctl(dev, ifr, SIOCGIFBYPASS);
*data = bypass_cb->data;
}
return ret;
}
static int doit(int cmd, int if_index, int *data)
{
struct ifreq ifr;
int ret = -1;
struct net_device *dev;
struct net_device *n;
for_each_netdev_safe(&init_net, dev, n) {
if (dev->ifindex == if_index) {
ret = do_cmd(dev, &ifr, cmd, data);
if (ret < 0)
ret = -1;
}
}
return ret;
}
static int is_dev_sd(int if_index)
{
int ret = 0;
SET_BPLIB_INT_FN(is_bypass, int, if_index, ret);
return (ret >= 0 ? 1 : 0);
}
static int is_bypass_dev(int if_index)
{
struct pci_dev *pdev = NULL;
struct net_device *dev = NULL;
struct ifreq ifr;
int ret = 0, data = 0;
while ((pdev = pci_get_class(PCI_CLASS_NETWORK_ETHERNET << 8, pdev))) {
if ((dev = pci_get_drvdata(pdev)) != NULL)
if (((dev = pci_get_drvdata(pdev)) != NULL) &&
(dev->ifindex == if_index)) {
if ((pdev->vendor == SILICOM_VID) &&
(pdev->device >= SILICOM_BP_PID_MIN) &&
(pdev->device <= SILICOM_BP_PID_MAX))
goto send_cmd;
#if defined(BP_VENDOR_SUPPORT) && defined(ETHTOOL_GDRVINFO)
else {
struct ethtool_drvinfo info;
const struct ethtool_ops *ops =
dev->ethtool_ops;
int k = 0;
if (ops->get_drvinfo) {
memset(&info, 0, sizeof(info));
info.cmd = ETHTOOL_GDRVINFO;
ops->get_drvinfo(dev, &info);
for (; bp_desc_array[k]; k++)
if (!
(strcmp
(bp_desc_array[k],
info.driver)))
goto send_cmd;
}
}
#endif
return -1;
}
}
send_cmd:
ret = do_cmd(dev, &ifr, IS_BYPASS, &data);
return (ret < 0 ? -1 : ret);
}
static int is_bypass(int if_index)
{
int ret = 0;
SET_BPLIB_INT_FN(is_bypass, int, if_index, ret);
if (ret < 0)
return is_bypass_dev(if_index);
return ret;
}
static int get_bypass_slave(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass_slave, GET_BYPASS_SLAVE, if_index);
}
static int get_bypass_caps(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass_caps, GET_BYPASS_CAPS, if_index);
}
static int get_wd_set_caps(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_wd_set_caps, GET_WD_SET_CAPS, if_index);
}
static int set_bypass(int if_index, int bypass_mode)
{
DO_BPLIB_SET_ARG_FN(set_bypass, SET_BYPASS, if_index, bypass_mode);
}
static int get_bypass(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass, GET_BYPASS, if_index);
}
static int get_bypass_change(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass_change, GET_BYPASS_CHANGE, if_index);
}
static int set_dis_bypass(int if_index, int dis_bypass)
{
DO_BPLIB_SET_ARG_FN(set_dis_bypass, SET_DIS_BYPASS, if_index,
dis_bypass);
}
static int get_dis_bypass(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_dis_bypass, GET_DIS_BYPASS, if_index);
}
static int set_bypass_pwoff(int if_index, int bypass_mode)
{
DO_BPLIB_SET_ARG_FN(set_bypass_pwoff, SET_BYPASS_PWOFF, if_index,
bypass_mode);
}
static int get_bypass_pwoff(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass_pwoff, GET_BYPASS_PWOFF, if_index);
}
static int set_bypass_pwup(int if_index, int bypass_mode)
{
DO_BPLIB_SET_ARG_FN(set_bypass_pwup, SET_BYPASS_PWUP, if_index,
bypass_mode);
}
static int get_bypass_pwup(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bypass_pwup, GET_BYPASS_PWUP, if_index);
}
static int set_bypass_wd(int if_index, int ms_timeout, int *ms_timeout_set)
{
int data = ms_timeout, ret = 0;
if (is_dev_sd(if_index))
SET_BPLIB_INT_FN3(set_bypass_wd, int, if_index, int, ms_timeout,
int *, ms_timeout_set, ret);
else {
ret = doit(SET_BYPASS_WD, if_index, &data);
if (ret > 0) {
*ms_timeout_set = ret;
ret = 0;
}
}
return ret;
}
static int get_bypass_wd(int if_index, int *ms_timeout_set)
{
int *data = ms_timeout_set, ret = 0;
if (is_dev_sd(if_index))
SET_BPLIB_INT_FN2(get_bypass_wd, int, if_index, int *,
ms_timeout_set, ret);
else
ret = doit(GET_BYPASS_WD, if_index, data);
return ret;
}
static int get_wd_expire_time(int if_index, int *ms_time_left)
{
int *data = ms_time_left, ret = 0;
if (is_dev_sd(if_index))
SET_BPLIB_INT_FN2(get_wd_expire_time, int, if_index, int *,
ms_time_left, ret);
else {
ret = doit(GET_WD_EXPIRE_TIME, if_index, data);
if ((ret == 0) && (*data != 0))
ret = 1;
}
return ret;
}
static int reset_bypass_wd_timer(int if_index)
{
DO_BPLIB_GET_ARG_FN(reset_bypass_wd_timer, RESET_BYPASS_WD_TIMER,
if_index);
}
static int set_std_nic(int if_index, int bypass_mode)
{
DO_BPLIB_SET_ARG_FN(set_std_nic, SET_STD_NIC, if_index, bypass_mode);
}
static int get_std_nic(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_std_nic, GET_STD_NIC, if_index);
}
static int set_tx(int if_index, int tx_state)
{
DO_BPLIB_SET_ARG_FN(set_tx, SET_TX, if_index, tx_state);
}
static int get_tx(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tx, GET_TX, if_index);
}
static int set_tap(int if_index, int tap_mode)
{
DO_BPLIB_SET_ARG_FN(set_tap, SET_TAP, if_index, tap_mode);
}
static int get_tap(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tap, GET_TAP, if_index);
}
static int get_tap_change(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tap_change, GET_TAP_CHANGE, if_index);
}
static int set_dis_tap(int if_index, int dis_tap)
{
DO_BPLIB_SET_ARG_FN(set_dis_tap, SET_DIS_TAP, if_index, dis_tap);
}
static int get_dis_tap(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_dis_tap, GET_DIS_TAP, if_index);
}
static int set_tap_pwup(int if_index, int tap_mode)
{
DO_BPLIB_SET_ARG_FN(set_tap_pwup, SET_TAP_PWUP, if_index, tap_mode);
}
static int get_tap_pwup(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tap_pwup, GET_TAP_PWUP, if_index);
}
static int set_bp_disc(int if_index, int disc_mode)
{
DO_BPLIB_SET_ARG_FN(set_bp_disc, SET_DISC, if_index, disc_mode);
}
static int get_bp_disc(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bp_disc, GET_DISC, if_index);
}
static int get_bp_disc_change(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bp_disc_change, GET_DISC_CHANGE, if_index);
}
static int set_bp_dis_disc(int if_index, int dis_disc)
{
DO_BPLIB_SET_ARG_FN(set_bp_dis_disc, SET_DIS_DISC, if_index, dis_disc);
}
static int get_bp_dis_disc(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bp_dis_disc, GET_DIS_DISC, if_index);
}
static int set_bp_disc_pwup(int if_index, int disc_mode)
{
DO_BPLIB_SET_ARG_FN(set_bp_disc_pwup, SET_DISC_PWUP, if_index,
disc_mode);
}
static int get_bp_disc_pwup(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_bp_disc_pwup, GET_DISC_PWUP, if_index);
}
static int set_wd_exp_mode(int if_index, int mode)
{
DO_BPLIB_SET_ARG_FN(set_wd_exp_mode, SET_WD_EXP_MODE, if_index, mode);
}
static int get_wd_exp_mode(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_wd_exp_mode, GET_WD_EXP_MODE, if_index);
}
static int set_wd_autoreset(int if_index, int time)
{
DO_BPLIB_SET_ARG_FN(set_wd_autoreset, SET_WD_AUTORESET, if_index, time);
}
static int get_wd_autoreset(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_wd_autoreset, GET_WD_AUTORESET, if_index);
}
static int set_tpl(int if_index, int tpl_mode)
{
DO_BPLIB_SET_ARG_FN(set_tpl, SET_TPL, if_index, tpl_mode);
}
static int get_tpl(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tpl, GET_TPL, if_index);
}
static int set_bp_hw_reset(int if_index, int mode)
{
DO_BPLIB_SET_ARG_FN(set_tpl, SET_BP_HW_RESET, if_index, mode);
}
static int get_bp_hw_reset(int if_index)
{
DO_BPLIB_GET_ARG_FN(get_tpl, GET_BP_HW_RESET, if_index);
}
static int get_bypass_info(int if_index, struct bp_info *bp_info)
{
int ret = 0;
if (is_dev_sd(if_index)) {
SET_BPLIB_INT_FN2(get_bypass_info, int, if_index,
struct bp_info *, bp_info, ret);
} else {
static int (*ioctl) (struct net_device *, struct ifreq *, int);
struct net_device *dev;
struct net_device *n;
for_each_netdev_safe(&init_net, dev, n) {
if (dev->ifindex == if_index) {
struct if_bypass_info *bypass_cb;
struct ifreq ifr;
memset(&ifr, 0, sizeof(ifr));
bypass_cb = (struct if_bypass_info *)&ifr;
bypass_cb->cmd = GET_BYPASS_INFO;
if ((dev->netdev_ops) &&
(ioctl = dev->netdev_ops->ndo_do_ioctl)) {
ret = ioctl(dev, &ifr, SIOCGIFBYPASS);
}
else
ret = -1;
if (ret == 0)
memcpy(bp_info, &bypass_cb->bp_info,
sizeof(struct bp_info));
ret = (ret < 0 ? -1 : 0);
break;
}
}
}
return ret;
}
int init_lib_module(void)
{
printk(VERSION);
return 0;
}
void cleanup_lib_module(void)
{
}
