static void tb_pci_init_path(struct tb_path *path)
{
path->egress_fc_enable = TB_PATH_SOURCE | TB_PATH_INTERNAL;
path->egress_shared_buffer = TB_PATH_NONE;
path->ingress_fc_enable = TB_PATH_ALL;
path->ingress_shared_buffer = TB_PATH_NONE;
path->priority = 3;
path->weight = 1;
path->drop_packages = 0;
path->nfc_credits = 0;
}
struct tb_pci_tunnel *tb_pci_alloc(struct tb *tb, struct tb_port *up,
struct tb_port *down)
{
struct tb_pci_tunnel *tunnel = kzalloc(sizeof(*tunnel), GFP_KERNEL);
if (!tunnel)
goto err;
tunnel->tb = tb;
tunnel->down_port = down;
tunnel->up_port = up;
INIT_LIST_HEAD(&tunnel->list);
tunnel->path_to_up = tb_path_alloc(up->sw->tb, 2);
if (!tunnel->path_to_up)
goto err;
tunnel->path_to_down = tb_path_alloc(up->sw->tb, 2);
if (!tunnel->path_to_down)
goto err;
tb_pci_init_path(tunnel->path_to_up);
tb_pci_init_path(tunnel->path_to_down);
tunnel->path_to_up->hops[0].in_port = down;
tunnel->path_to_up->hops[0].in_hop_index = 8;
tunnel->path_to_up->hops[0].in_counter_index = -1;
tunnel->path_to_up->hops[0].out_port = tb_upstream_port(up->sw)->remote;
tunnel->path_to_up->hops[0].next_hop_index = 8;
tunnel->path_to_up->hops[1].in_port = tb_upstream_port(up->sw);
tunnel->path_to_up->hops[1].in_hop_index = 8;
tunnel->path_to_up->hops[1].in_counter_index = -1;
tunnel->path_to_up->hops[1].out_port = up;
tunnel->path_to_up->hops[1].next_hop_index = 8;
tunnel->path_to_down->hops[0].in_port = up;
tunnel->path_to_down->hops[0].in_hop_index = 8;
tunnel->path_to_down->hops[0].in_counter_index = -1;
tunnel->path_to_down->hops[0].out_port = tb_upstream_port(up->sw);
tunnel->path_to_down->hops[0].next_hop_index = 8;
tunnel->path_to_down->hops[1].in_port =
tb_upstream_port(up->sw)->remote;
tunnel->path_to_down->hops[1].in_hop_index = 8;
tunnel->path_to_down->hops[1].in_counter_index = -1;
tunnel->path_to_down->hops[1].out_port = down;
tunnel->path_to_down->hops[1].next_hop_index = 8;
return tunnel;
err:
if (tunnel) {
if (tunnel->path_to_down)
tb_path_free(tunnel->path_to_down);
if (tunnel->path_to_up)
tb_path_free(tunnel->path_to_up);
kfree(tunnel);
}
return NULL;
}
void tb_pci_free(struct tb_pci_tunnel *tunnel)
{
if (tunnel->path_to_up->activated || tunnel->path_to_down->activated) {
tb_tunnel_WARN(tunnel, "trying to free an activated tunnel\n");
return;
}
tb_path_free(tunnel->path_to_up);
tb_path_free(tunnel->path_to_down);
kfree(tunnel);
}
bool tb_pci_is_invalid(struct tb_pci_tunnel *tunnel)
{
WARN_ON(!tunnel->path_to_up->activated);
WARN_ON(!tunnel->path_to_down->activated);
return tb_path_is_invalid(tunnel->path_to_up)
|| tb_path_is_invalid(tunnel->path_to_down);
}
static int tb_pci_port_active(struct tb_port *port, bool active)
{
u32 word = active ? 0x80000000 : 0x0;
int cap = tb_find_cap(port, TB_CFG_PORT, TB_CAP_PCIE);
if (cap <= 0) {
tb_port_warn(port, "TB_CAP_PCIE not found: %d\n", cap);
return cap ? cap : -ENXIO;
}
return tb_port_write(port, &word, TB_CFG_PORT, cap, 1);
}
int tb_pci_restart(struct tb_pci_tunnel *tunnel)
{
int res;
tunnel->path_to_up->activated = false;
tunnel->path_to_down->activated = false;
tb_tunnel_info(tunnel, "activating\n");
res = tb_path_activate(tunnel->path_to_up);
if (res)
goto err;
res = tb_path_activate(tunnel->path_to_down);
if (res)
goto err;
res = tb_pci_port_active(tunnel->down_port, true);
if (res)
goto err;
res = tb_pci_port_active(tunnel->up_port, true);
if (res)
goto err;
return 0;
err:
tb_tunnel_warn(tunnel, "activation failed\n");
tb_pci_deactivate(tunnel);
return res;
}
int tb_pci_activate(struct tb_pci_tunnel *tunnel)
{
int res;
if (tunnel->path_to_up->activated || tunnel->path_to_down->activated) {
tb_tunnel_WARN(tunnel,
"trying to activate an already activated tunnel\n");
return -EINVAL;
}
res = tb_pci_restart(tunnel);
if (res)
return res;
list_add(&tunnel->list, &tunnel->tb->tunnel_list);
return 0;
}
void tb_pci_deactivate(struct tb_pci_tunnel *tunnel)
{
tb_tunnel_info(tunnel, "deactivating\n");
tb_pci_port_active(tunnel->up_port, false);
tb_pci_port_active(tunnel->down_port, false);
if (tunnel->path_to_down->activated)
tb_path_deactivate(tunnel->path_to_down);
if (tunnel->path_to_up->activated)
tb_path_deactivate(tunnel->path_to_up);
list_del_init(&tunnel->list);
}
