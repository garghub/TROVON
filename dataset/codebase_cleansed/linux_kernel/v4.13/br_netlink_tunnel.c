static size_t __get_vlan_tinfo_size(void)
{
return nla_total_size(0) +
nla_total_size(sizeof(u32)) +
nla_total_size(sizeof(u16)) +
nla_total_size(sizeof(u16));
}
static bool vlan_tunid_inrange(struct net_bridge_vlan *v_curr,
struct net_bridge_vlan *v_last)
{
__be32 tunid_curr = tunnel_id_to_key32(v_curr->tinfo.tunnel_id);
__be32 tunid_last = tunnel_id_to_key32(v_last->tinfo.tunnel_id);
return (be32_to_cpu(tunid_curr) - be32_to_cpu(tunid_last)) == 1;
}
static int __get_num_vlan_tunnel_infos(struct net_bridge_vlan_group *vg)
{
struct net_bridge_vlan *v, *vtbegin = NULL, *vtend = NULL;
int num_tinfos = 0;
list_for_each_entry_rcu(v, &vg->vlan_list, vlist) {
if (!br_vlan_should_use(v) || !v->tinfo.tunnel_id)
continue;
if (!vtbegin) {
goto initvars;
} else if ((v->vid - vtend->vid) == 1 &&
vlan_tunid_inrange(v, vtend)) {
vtend = v;
continue;
} else {
if ((vtend->vid - vtbegin->vid) > 0)
num_tinfos += 2;
else
num_tinfos += 1;
}
initvars:
vtbegin = v;
vtend = v;
}
if (vtbegin && vtend) {
if ((vtend->vid - vtbegin->vid) > 0)
num_tinfos += 2;
else
num_tinfos += 1;
}
return num_tinfos;
}
int br_get_vlan_tunnel_info_size(struct net_bridge_vlan_group *vg)
{
int num_tinfos;
if (!vg)
return 0;
rcu_read_lock();
num_tinfos = __get_num_vlan_tunnel_infos(vg);
rcu_read_unlock();
return num_tinfos * __get_vlan_tinfo_size();
}
static int br_fill_vlan_tinfo(struct sk_buff *skb, u16 vid,
__be64 tunnel_id, u16 flags)
{
__be32 tid = tunnel_id_to_key32(tunnel_id);
struct nlattr *tmap;
tmap = nla_nest_start(skb, IFLA_BRIDGE_VLAN_TUNNEL_INFO);
if (!tmap)
return -EMSGSIZE;
if (nla_put_u32(skb, IFLA_BRIDGE_VLAN_TUNNEL_ID,
be32_to_cpu(tid)))
goto nla_put_failure;
if (nla_put_u16(skb, IFLA_BRIDGE_VLAN_TUNNEL_VID,
vid))
goto nla_put_failure;
if (nla_put_u16(skb, IFLA_BRIDGE_VLAN_TUNNEL_FLAGS,
flags))
goto nla_put_failure;
nla_nest_end(skb, tmap);
return 0;
nla_put_failure:
nla_nest_cancel(skb, tmap);
return -EMSGSIZE;
}
static int br_fill_vlan_tinfo_range(struct sk_buff *skb,
struct net_bridge_vlan *vtbegin,
struct net_bridge_vlan *vtend)
{
int err;
if (vtend && (vtend->vid - vtbegin->vid) > 0) {
err = br_fill_vlan_tinfo(skb, vtbegin->vid,
vtbegin->tinfo.tunnel_id,
BRIDGE_VLAN_INFO_RANGE_BEGIN);
if (err)
return err;
err = br_fill_vlan_tinfo(skb, vtend->vid,
vtend->tinfo.tunnel_id,
BRIDGE_VLAN_INFO_RANGE_END);
if (err)
return err;
} else {
err = br_fill_vlan_tinfo(skb, vtbegin->vid,
vtbegin->tinfo.tunnel_id,
0);
if (err)
return err;
}
return 0;
}
int br_fill_vlan_tunnel_info(struct sk_buff *skb,
struct net_bridge_vlan_group *vg)
{
struct net_bridge_vlan *vtbegin = NULL;
struct net_bridge_vlan *vtend = NULL;
struct net_bridge_vlan *v;
int err;
list_for_each_entry_rcu(v, &vg->vlan_list, vlist) {
if (!br_vlan_should_use(v))
continue;
if (!v->tinfo.tunnel_dst)
continue;
if (!vtbegin) {
goto initvars;
} else if ((v->vid - vtend->vid) == 1 &&
vlan_tunid_inrange(v, vtend)) {
vtend = v;
continue;
} else {
err = br_fill_vlan_tinfo_range(skb, vtbegin, vtend);
if (err)
return err;
}
initvars:
vtbegin = v;
vtend = v;
}
if (vtbegin) {
err = br_fill_vlan_tinfo_range(skb, vtbegin, vtend);
if (err)
return err;
}
return 0;
}
static int br_vlan_tunnel_info(struct net_bridge_port *p, int cmd,
u16 vid, u32 tun_id)
{
int err = 0;
if (!p)
return -EINVAL;
switch (cmd) {
case RTM_SETLINK:
err = nbp_vlan_tunnel_info_add(p, vid, tun_id);
break;
case RTM_DELLINK:
nbp_vlan_tunnel_info_delete(p, vid);
break;
}
return err;
}
int br_parse_vlan_tunnel_info(struct nlattr *attr,
struct vtunnel_info *tinfo)
{
struct nlattr *tb[IFLA_BRIDGE_VLAN_TUNNEL_MAX + 1];
u32 tun_id;
u16 vid, flags = 0;
int err;
memset(tinfo, 0, sizeof(*tinfo));
err = nla_parse_nested(tb, IFLA_BRIDGE_VLAN_TUNNEL_MAX, attr,
vlan_tunnel_policy, NULL);
if (err < 0)
return err;
if (!tb[IFLA_BRIDGE_VLAN_TUNNEL_ID] ||
!tb[IFLA_BRIDGE_VLAN_TUNNEL_VID])
return -EINVAL;
tun_id = nla_get_u32(tb[IFLA_BRIDGE_VLAN_TUNNEL_ID]);
vid = nla_get_u16(tb[IFLA_BRIDGE_VLAN_TUNNEL_VID]);
if (vid >= VLAN_VID_MASK)
return -ERANGE;
if (tb[IFLA_BRIDGE_VLAN_TUNNEL_FLAGS])
flags = nla_get_u16(tb[IFLA_BRIDGE_VLAN_TUNNEL_FLAGS]);
tinfo->tunid = tun_id;
tinfo->vid = vid;
tinfo->flags = flags;
return 0;
}
int br_process_vlan_tunnel_info(struct net_bridge *br,
struct net_bridge_port *p, int cmd,
struct vtunnel_info *tinfo_curr,
struct vtunnel_info *tinfo_last)
{
int err;
if (tinfo_curr->flags & BRIDGE_VLAN_INFO_RANGE_BEGIN) {
if (tinfo_last->flags & BRIDGE_VLAN_INFO_RANGE_BEGIN)
return -EINVAL;
memcpy(tinfo_last, tinfo_curr, sizeof(struct vtunnel_info));
} else if (tinfo_curr->flags & BRIDGE_VLAN_INFO_RANGE_END) {
int t, v;
if (!(tinfo_last->flags & BRIDGE_VLAN_INFO_RANGE_BEGIN))
return -EINVAL;
if ((tinfo_curr->vid - tinfo_last->vid) !=
(tinfo_curr->tunid - tinfo_last->tunid))
return -EINVAL;
t = tinfo_last->tunid;
for (v = tinfo_last->vid; v <= tinfo_curr->vid; v++) {
err = br_vlan_tunnel_info(p, cmd, v, t);
if (err)
return err;
t++;
}
memset(tinfo_last, 0, sizeof(struct vtunnel_info));
memset(tinfo_curr, 0, sizeof(struct vtunnel_info));
} else {
if (tinfo_last->flags)
return -EINVAL;
err = br_vlan_tunnel_info(p, cmd, tinfo_curr->vid,
tinfo_curr->tunid);
if (err)
return err;
memset(tinfo_last, 0, sizeof(struct vtunnel_info));
memset(tinfo_curr, 0, sizeof(struct vtunnel_info));
}
return 0;
}
