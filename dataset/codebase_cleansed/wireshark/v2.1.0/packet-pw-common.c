void pwc_item_append_cw(proto_item* item, const guint32 cw, const gboolean append_text)
{
if (item != NULL)
{
if (append_text)
{
proto_item_append_text(item, ", CW");
}
proto_item_append_text(item, ": 0x%.8" G_GINT32_MODIFIER "x", cw);
}
return;
}
void pwc_item_append_text_n_items(proto_item* item, const int n, const char * const item_text)
{
if (item != NULL)
{
if (n >=0)
{
proto_item_append_text(item, ", %d %s%s", n, item_text, plurality(n,"","s"));
}
}
return;
}
static
int dissect_pw_padding(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void* data _U_)
{
gint size;
proto_item* item;
proto_tree* tree_p;
size = tvb_reported_length_remaining(tvb, 0);
item = proto_tree_add_item(tree, proto_pw_padding, tvb, 0, -1, ENC_NA);
pwc_item_append_text_n_items(item,size,"byte");
tree_p = proto_item_add_subtree(item, ett);
call_data_dissector(tvb, pinfo, tree_p);
item = proto_tree_add_int(tree_p, hf_padding_len, tvb, 0, 0, size);
PROTO_ITEM_SET_HIDDEN(item);
return tvb_captured_length(tvb);
}
void proto_register_pw_padding(void)
{
static hf_register_info hfpadding[] = {
{&hf_padding_len ,{"Length" ,"pw.padding.len"
,FT_INT32 ,BASE_DEC ,NULL ,0
,NULL ,HFILL }}
};
static gint *ett_array[] = {
&ett
};
proto_pw_padding = proto_register_protocol("Pseudowire Padding","PW Padding","pw.padding");
proto_register_field_array(proto_pw_padding, hfpadding, array_length(hfpadding));
proto_register_subtree_array(ett_array, array_length(ett_array));
register_dissector("pw_padding", dissect_pw_padding, proto_pw_padding);
}
