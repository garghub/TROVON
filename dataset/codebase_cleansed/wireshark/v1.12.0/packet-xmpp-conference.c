void
xmpp_conferece_info_advert(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *cinfo_item;
proto_tree *cinfo_tree;
xmpp_attr_info attrs_info [] = {
{"xmlns", &hf_xmpp_xmlns, TRUE, TRUE, NULL, NULL},
{"isfocus", NULL, TRUE, TRUE, NULL, NULL}
};
cinfo_item = proto_tree_add_item(tree, hf_xmpp_conf_info, tvb, element->offset, element->length,
ENC_BIG_ENDIAN);
cinfo_tree = proto_item_add_subtree(cinfo_item, ett_xmpp_conf_info);
xmpp_display_attrs(cinfo_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(cinfo_tree, element, pinfo, tvb, NULL, 0);
}
void
xmpp_conference_info(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *cinfo_item;
proto_tree *cinfo_tree;
static const gchar *state_enums[] = {"full", "partial", "deleted"};
xmpp_array_t *state_array = xmpp_ep_init_array_t(state_enums, array_length(state_enums));
xmpp_attr_info attrs_info [] = {
{"xmlns", &hf_xmpp_xmlns, TRUE, TRUE, NULL, NULL},
{"entity", NULL, TRUE, TRUE, NULL, NULL},
{"state", NULL, FALSE, TRUE, xmpp_val_enum_list, state_array},
{"version", NULL, FALSE, TRUE, NULL, NULL},
{"sid", &hf_xmpp_conf_info_sid, FALSE, TRUE, NULL, NULL}
};
xmpp_elem_info elems_info [] = {
{NAME, "conference-description", xmpp_conf_desc, ONE},
{NAME, "conference-state", xmpp_conf_state, ONE},
{NAME, "users", xmpp_conf_users, ONE},
};
col_append_str(pinfo->cinfo, COL_INFO, "CONFERENC-INFO ");
cinfo_item = proto_tree_add_item(tree, hf_xmpp_conf_info, tvb, element->offset, element->length,
ENC_BIG_ENDIAN);
cinfo_tree = proto_item_add_subtree(cinfo_item, ett_xmpp_conf_info);
xmpp_display_attrs(cinfo_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(cinfo_tree, element, pinfo, tvb, elems_info, array_length(elems_info));
}
static void
xmpp_conf_desc(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *desc_item;
proto_tree *desc_tree;
xmpp_attr_info attrs_info [] = {
{"subject", NULL, FALSE, TRUE, NULL, NULL},
{"display-text", NULL, FALSE, FALSE, NULL, NULL},
{"free-text", NULL, FALSE, FALSE, NULL, NULL},
{"max-user-count", NULL, FALSE, FALSE, NULL, NULL},
};
desc_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "CONFERENCE DESCRIPTION");
desc_tree = proto_item_add_subtree(desc_item, ett_xmpp_conf_desc);
xmpp_change_elem_to_attrib("subject", "subject", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("display-text", "display-text", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("free-text", "free-text", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("maximum-user-count", "max-user-count", element, xmpp_transform_func_cdata);
xmpp_display_attrs(desc_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(desc_tree, element, pinfo, tvb, NULL,0);
}
static void
xmpp_conf_state(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *state_item;
proto_tree *state_tree;
xmpp_attr_info attrs_info [] = {
{"user-count", NULL, FALSE, TRUE, NULL, NULL},
{"active", NULL, FALSE, TRUE, NULL, NULL},
{"locked", NULL, FALSE, TRUE, NULL, NULL}
};
state_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "CONFERENCE STATE");
state_tree = proto_item_add_subtree(state_item, ett_xmpp_conf_state);
xmpp_change_elem_to_attrib("user-count", "user-count", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("active", "active", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("locked", "locked", element, xmpp_transform_func_cdata);
xmpp_display_attrs(state_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(state_tree, element, pinfo, tvb, NULL,0);
}
static void
xmpp_conf_users(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *users_item;
proto_tree *users_tree;
xmpp_attr_info attrs_info [] = {
{"state", NULL, FALSE, TRUE, NULL, NULL}
};
xmpp_elem_info elems_info [] = {
{NAME, "user", xmpp_conf_user, MANY}
};
users_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "USERS");
users_tree = proto_item_add_subtree(users_item, ett_xmpp_conf_users);
xmpp_display_attrs(users_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(users_tree, element, pinfo, tvb, elems_info, array_length(elems_info));
}
static void
xmpp_conf_user(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *user_item;
proto_tree *user_tree;
xmpp_attr_info attrs_info [] = {
{"entity", NULL, FALSE, TRUE, NULL, NULL},
{"state", NULL, FALSE, TRUE, NULL, NULL},
{"display-text", NULL, FALSE, TRUE, NULL, NULL},
{"cascaded-focus", NULL, FALSE, TRUE, NULL, NULL}
};
xmpp_elem_info elems_info [] = {
{NAME, "endpoint", xmpp_conf_endpoint, MANY},
};
user_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "USERS");
user_tree = proto_item_add_subtree(user_item, ett_xmpp_conf_user);
xmpp_change_elem_to_attrib("display-text", "display-text", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("cascaded-focus", "cascaded-focus", element, xmpp_transform_func_cdata);
xmpp_display_attrs(user_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(user_tree, element, pinfo, tvb, elems_info, array_length(elems_info));
}
static void
xmpp_conf_endpoint(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *endpoint_item;
proto_tree *endpoint_tree;
xmpp_attr_info attrs_info [] = {
{"entity", NULL, FALSE, TRUE, NULL, NULL},
{"state", NULL, FALSE, TRUE, NULL, NULL},
{"display-text", NULL, FALSE, TRUE, NULL, NULL},
{"status", NULL, FALSE, TRUE, NULL, NULL},
{"joining-method", NULL, FALSE, TRUE, NULL, NULL},
{"disconnection-method", NULL, FALSE, TRUE, NULL, NULL},
};
xmpp_elem_info elems_info [] = {
{NAME,"media", xmpp_conf_media, ONE},
};
endpoint_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "ENDPOINT");
endpoint_tree = proto_item_add_subtree(endpoint_item, ett_xmpp_conf_endpoint);
xmpp_change_elem_to_attrib("display-text", "display-text", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("status", "status", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("joining-method", "joining-method", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("disconnection-method", "disconnection-method", element, xmpp_transform_func_cdata);
xmpp_display_attrs(endpoint_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(endpoint_tree, element, pinfo, tvb, elems_info, array_length(elems_info));
}
static void
xmpp_conf_media(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, xmpp_element_t *element)
{
proto_item *media_item;
proto_tree *media_tree;
xmpp_attr_info attrs_info[] = {
{"id", NULL, TRUE, TRUE, NULL, NULL},
{"display-text", NULL, FALSE, TRUE, NULL, NULL},
{"type", NULL, FALSE, TRUE, NULL, NULL},
{"label", NULL, FALSE, TRUE, NULL, NULL},
{"src-id", NULL, FALSE, TRUE, NULL, NULL},
{"status", NULL, FALSE, TRUE, NULL, NULL},
};
media_item = proto_tree_add_text(tree, tvb, element->offset, element->length, "MEDIA");
media_tree = proto_item_add_subtree(media_item, ett_xmpp_conf_media);
xmpp_change_elem_to_attrib("display-text", "display-text", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("type", "type", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("label", "label", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("src-id", "src-id", element, xmpp_transform_func_cdata);
xmpp_change_elem_to_attrib("status", "status", element, xmpp_transform_func_cdata);
xmpp_display_attrs(media_tree, element, pinfo, tvb, attrs_info, array_length(attrs_info));
xmpp_display_elems(media_tree, element, pinfo, tvb, NULL, 0);
}
