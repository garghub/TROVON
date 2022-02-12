static int sanitize_arg(const char *val, char *intf, int intf_len)
{
int len;
if (!val)
return 0;
for (len = 0; len < intf_len - 1 && val[len] && val[len] != '\n'; len++)
intf[len] = val[len];
intf[len] = 0;
if (len == 0 || (val[len] != 0 && val[len] != '\n'))
return 0;
return len;
}
static void rxe_set_port_state(struct net_device *ndev)
{
struct rxe_dev *rxe = net_to_rxe(ndev);
bool is_up = netif_running(ndev) && netif_carrier_ok(ndev);
if (!rxe)
goto out;
if (is_up)
rxe_port_up(rxe);
else
rxe_port_down(rxe);
out:
return;
}
static int rxe_param_set_add(const char *val, const struct kernel_param *kp)
{
int len;
int err = 0;
char intf[32];
struct net_device *ndev = NULL;
struct rxe_dev *rxe;
len = sanitize_arg(val, intf, sizeof(intf));
if (!len) {
pr_err("rxe: add: invalid interface name\n");
err = -EINVAL;
goto err;
}
ndev = dev_get_by_name(&init_net, intf);
if (!ndev) {
pr_err("interface %s not found\n", intf);
err = -EINVAL;
goto err;
}
if (net_to_rxe(ndev)) {
pr_err("rxe: already configured on %s\n", intf);
err = -EINVAL;
goto err;
}
rxe = rxe_net_add(ndev);
if (!rxe) {
pr_err("rxe: failed to add %s\n", intf);
err = -EINVAL;
goto err;
}
rxe_set_port_state(ndev);
pr_info("rxe: added %s to %s\n", rxe->ib_dev.name, intf);
err:
if (ndev)
dev_put(ndev);
return err;
}
static int rxe_param_set_remove(const char *val, const struct kernel_param *kp)
{
int len;
char intf[32];
struct rxe_dev *rxe;
len = sanitize_arg(val, intf, sizeof(intf));
if (!len) {
pr_err("rxe: add: invalid interface name\n");
return -EINVAL;
}
if (strncmp("all", intf, len) == 0) {
pr_info("rxe_sys: remove all");
rxe_remove_all();
return 0;
}
rxe = get_rxe_by_name(intf);
if (!rxe) {
pr_err("rxe: not configured on %s\n", intf);
return -EINVAL;
}
list_del(&rxe->list);
rxe_remove(rxe);
return 0;
}
