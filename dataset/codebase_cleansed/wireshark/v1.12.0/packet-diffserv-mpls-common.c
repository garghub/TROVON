void
dissect_diffserv_mpls_common(tvbuff_t *tvb, proto_tree *tree, int type,
int offset, int **hfindexes, gint **etts)
{
proto_item *ti = NULL, *sub_ti;
proto_tree *tree2 = NULL, *phbid_subtree;
int exp;
guint16 phbid;
switch (type) {
case 1:
ti = proto_tree_add_item(tree, hf_map, tvb, offset, 4, ENC_NA);
tree2 = proto_item_add_subtree(ti, ett_map);
proto_item_set_text(ti, "MAP: ");
offset ++;
exp = tvb_get_guint8(tvb, offset) & 7;
proto_tree_add_uint(tree2, hf_exp, tvb, offset, 1, exp);
proto_item_append_text(ti, "EXP %u, ", exp);
offset ++;
break;
case 2:
tree2 = tree;
break;
default:
return;
}
sub_ti = proto_tree_add_item(tree2, hf_phbid, tvb, offset, 2, ENC_NA);
phbid_subtree = proto_item_add_subtree(sub_ti, ett_map_phbid);
proto_item_set_text(sub_ti, "%s: ", (type == 1) ? PHBID_DESCRIPTION : "PSC");
phbid = tvb_get_ntohs(tvb, offset);
if ((phbid & 1) == 0) {
proto_tree_add_uint(phbid_subtree, hf_phbid_dscp,
tvb, offset, 2, phbid);
if (type == 1)
proto_item_append_text(ti, "DSCP %u", phbid >> 10);
proto_item_append_text(sub_ti, "DSCP %u", phbid >> 10);
}
else {
proto_tree_add_uint(phbid_subtree, hf_phbid_code,
tvb, offset, 2, phbid);
if (type == 1)
proto_item_append_text(ti, "PHB id code %u", phbid >> 4);
proto_item_append_text(sub_ti, "PHB id code %u", phbid >> 4);
}
proto_tree_add_uint(phbid_subtree, hf_phbid_bit14, tvb, offset, 2, phbid);
proto_tree_add_uint(phbid_subtree, hf_phbid_bit15, tvb, offset, 2, phbid);
}
