static int
protocolinfo_packet(void *prs, packet_info *pinfo, epan_dissect_t *edt, const void *dummy _U_)
{
pci_t *rs=(pci_t *)prs;
GPtrArray *gp;
guint i;
char *str;
if (!col_get_writable(pinfo->cinfo)) {
fprintf(stderr, "tshark: the proto,colinfo tap doesn't work if the INFO column isn't being printed.\n");
exit(1);
}
gp=proto_get_finfo_ptr_array(edt->tree, rs->hf_index);
if(!gp){
return 0;
}
for(i=0;i<gp->len;i++){
str=(char *)proto_construct_match_selected_string((field_info *)gp->pdata[i], NULL);
if(str){
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",str);
}
}
return 0;
}
static void
protocolinfo_init(const char *opt_arg, void* userdata _U_)
{
pci_t *rs;
const char *field=NULL;
const char *filter=NULL;
header_field_info *hfi;
GString *error_string;
if(!strncmp("proto,colinfo,",opt_arg,14)){
filter=opt_arg+14;
field=strchr(filter,',');
if(field){
field+=1;
}
}
if(!field){
fprintf(stderr, "tshark: invalid \"-z proto,colinfo,<filter>,<field>\" argument\n");
exit(1);
}
hfi=proto_registrar_get_byname(field);
if(!hfi){
fprintf(stderr, "tshark: Field \"%s\" doesn't exist.\n", field);
exit(1);
}
rs=g_new(pci_t,1);
rs->hf_index=hfi->id;
if((field-filter)>1){
rs->filter=(char *)g_malloc(field-filter);
g_strlcpy(rs->filter,filter,(field-filter));
} else {
rs->filter=NULL;
}
error_string=register_tap_listener("frame", rs, rs->filter, TL_REQUIRES_PROTO_TREE, NULL, protocolinfo_packet, NULL);
if(error_string){
fprintf(stderr, "tshark: Couldn't register proto,colinfo tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
g_free(rs->filter);
g_free(rs);
exit(1);
}
}
void
register_tap_listener_protocolinfo(void)
{
register_stat_cmd_arg("proto,colinfo,", protocolinfo_init,NULL);
}
