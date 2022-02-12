extern guint32 tpg_ipv4(tvbparse_elem_t* e _U_) {
return 0;
}
extern guint8* tpg_ipv6(tvbparse_elem_t* e _U_) {
return NULL;
}
extern tpg_parser_data_t* tpg_start(proto_tree* root_tree,
tvbuff_t* tvb,
int offset,
int len,
tvbparse_wanted_t* ignore,
void* private_data) {
tpg_parser_data_t* tpg = ep_alloc(sizeof(tpg_parser_data_t));
tpg->private_data = private_data;
tpg->tt = tvbparse_init(tvb,offset,len,tpg,ignore);
tpg->stack = ep_stack_new();
ep_stack_push(tpg->stack,root_tree);
return tpg;
}
