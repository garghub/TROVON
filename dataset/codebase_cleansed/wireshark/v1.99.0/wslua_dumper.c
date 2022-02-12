WSLUA_CONSTRUCTOR PseudoHeader_none(lua_State* L) {
PseudoHeader ph = (PseudoHeader)g_malloc(sizeof(struct lua_pseudo_header));
ph->type = PHDR_NONE;
ph->wph = NULL;
pushPseudoHeader(L,ph);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR PseudoHeader_eth(lua_State* L) {
#define WSLUA_OPTARG_PseudoHeader_eth_FCSLEN 1
PseudoHeader ph = (PseudoHeader)g_malloc(sizeof(struct lua_pseudo_header));
ph->type = PHDR_ETH;
ph->wph = (union wtap_pseudo_header *)g_malloc(sizeof(union wtap_pseudo_header));
ph->wph->eth.fcs_len = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_eth_FCSLEN,-1);
pushPseudoHeader(L,ph);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR PseudoHeader_atm(lua_State* L) {
#define WSLUA_OPTARG_PseudoHeader_atm_AAL 1
#define WSLUA_OPTARG_PseudoHeader_atm_VPI 2
#define WSLUA_OPTARG_PseudoHeader_atm_VCI 3
#define WSLUA_OPTARG_PseudoHeader_atm_CHANNEL 4
#define WSLUA_OPTARG_PseudoHeader_atm_CELLS 5
#define WSLUA_OPTARG_PseudoHeader_atm_AAL5U2U 6
#define WSLUA_OPTARG_PseudoHeader_atm_AAL5LEN 7
PseudoHeader ph = (PseudoHeader)g_malloc(sizeof(struct lua_pseudo_header));
ph->type = PHDR_ATM;
ph->wph = (union wtap_pseudo_header *)g_malloc(sizeof(union wtap_pseudo_header));
ph->wph->atm.aal = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_AAL,5);
ph->wph->atm.vpi = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_VPI,1);
ph->wph->atm.vci = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_VCI,1);
ph->wph->atm.channel = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_CHANNEL,0);
ph->wph->atm.cells = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_CELLS,1);
ph->wph->atm.aal5t_u2u = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_AAL5U2U,1);
ph->wph->atm.aal5t_len = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_atm_AAL5LEN,0);
pushPseudoHeader(L,ph);
WSLUA_RETURN(1);
}
WSLUA_CONSTRUCTOR PseudoHeader_mtp2(lua_State* L) {
#define WSLUA_OPTARG_PseudoHeader_mtp2_SENT 1
#define WSLUA_OPTARG_PseudoHeader_mtp2_ANNEXA 2
#define WSLUA_OPTARG_PseudoHeader_mtp2_LINKNUM 3
PseudoHeader ph = (PseudoHeader)g_malloc(sizeof(struct lua_pseudo_header));
ph->type = PHDR_MTP2;
ph->wph = (union wtap_pseudo_header *)g_malloc(sizeof(union wtap_pseudo_header));
ph->wph->mtp2.sent = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_mtp2_SENT,0);
ph->wph->mtp2.annex_a_used = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_mtp2_ANNEXA,0);
ph->wph->mtp2.link_number = luaL_optint(L,WSLUA_OPTARG_PseudoHeader_mtp2_LINKNUM,0);
pushPseudoHeader(L,ph);
WSLUA_RETURN(1);
}
static int PseudoHeader__gc(lua_State* L _U_) {
return 0;
}
int PseudoHeader_register(lua_State* L) {
WSLUA_REGISTER_CLASS(PseudoHeader)
return 0;
}
static const char* cross_plat_fname(const char* fname) {
static char fname_clean[256];
char* f;
g_strlcpy(fname_clean,fname,255);
fname_clean[255] = '\0';
for(f = fname_clean; *f; f++) {
switch(*f) {
case '/': case '\\':
*f = *(G_DIR_SEPARATOR_S);
break;
default:
break;
}
}
return fname_clean;
}
WSLUA_CONSTRUCTOR Dumper_new(lua_State* L) {
#define WSLUA_ARG_Dumper_new_FILENAME 1
#define WSLUA_OPTARG_Dumper_new_FILETYPE 2
#define WSLUA_OPTARG_Dumper_new_ENCAP 3
Dumper d;
const char* fname = luaL_checkstring(L,WSLUA_ARG_Dumper_new_FILENAME);
int filetype = luaL_optint(L,WSLUA_OPTARG_Dumper_new_FILETYPE,WTAP_FILE_TYPE_SUBTYPE_PCAP);
int encap = luaL_optint(L,WSLUA_OPTARG_Dumper_new_ENCAP,WTAP_ENCAP_ETHERNET);
int err = 0;
const char* filename;
if (! fname) return 0;
filename = cross_plat_fname(fname);
d = wtap_dump_open(filename, filetype, encap, 0, FALSE, &err);
if (! d ) {
switch (err) {
case WTAP_ERR_UNSUPPORTED_FILE_TYPE:
luaL_error(L,"Files of file type %s cannot be written",
wtap_file_type_subtype_string(filetype));
break;
case WTAP_ERR_UNSUPPORTED_ENCAP:
luaL_error(L,"Files of file type %s don't support encapsulation %s",
wtap_file_type_subtype_string(filetype),
wtap_encap_short_string(encap));
break;
default:
luaL_error(L,"error while opening `%s': %s",
filename,
wtap_strerror(err));
break;
}
return 0;
}
g_hash_table_insert(dumper_encaps,d,GINT_TO_POINTER(encap));
pushDumper(L,d);
WSLUA_RETURN(1);
}
WSLUA_METHOD Dumper_close(lua_State* L) {
Dumper* dp = (Dumper*)luaL_checkudata(L, 1, "Dumper");
int err;
if (! *dp) {
WSLUA_ERROR(Dumper_close,"Cannot operate on a closed dumper");
return 0;
}
g_hash_table_remove(dumper_encaps,*dp);
if (!wtap_dump_close(*dp, &err)) {
luaL_error(L,"error closing: %s",
wtap_strerror(err));
}
*dp = NULL;
return 0;
}
WSLUA_METHOD Dumper_flush(lua_State* L) {
Dumper d = checkDumper(L,1);
if (!d) return 0;
wtap_dump_flush(d);
return 0;
}
WSLUA_METHOD Dumper_dump(lua_State* L) {
#define WSLUA_ARG_Dumper_dump_TIMESTAMP 2
#define WSLUA_ARG_Dumper_dump_PSEUDOHEADER 3
#define WSLUA_ARG_Dumper_dump_BYTEARRAY 4
Dumper d = checkDumper(L,1);
PseudoHeader ph;
ByteArray ba;
struct wtap_pkthdr pkthdr;
double ts;
int err;
if (!d) return 0;
ts = luaL_checknumber(L,WSLUA_ARG_Dumper_dump_TIMESTAMP);
ph = checkPseudoHeader(L,WSLUA_ARG_Dumper_dump_PSEUDOHEADER);
if (!ph) {
WSLUA_ARG_ERROR(Dumper_dump,TIMESTAMP,"need a PseudoHeader");
return 0;
}
ba = checkByteArray(L,WSLUA_ARG_Dumper_dump_BYTEARRAY);
if (! ba) {
WSLUA_ARG_ERROR(Dumper_dump,BYTEARRAY,"must be a ByteArray");
return 0;
}
memset(&pkthdr, 0, sizeof(pkthdr));
pkthdr.rec_type = REC_TYPE_PACKET;
pkthdr.presence_flags = WTAP_HAS_TS;
pkthdr.ts.secs = (unsigned int)(floor(ts));
pkthdr.ts.nsecs = (unsigned int)(floor((ts - (double)pkthdr.ts.secs) * 1000000000));
pkthdr.len = ba->len;
pkthdr.caplen = ba->len;
pkthdr.pkt_encap = DUMPER_ENCAP(d);
pkthdr.pseudo_header = *ph->wph;
if (! wtap_dump(d, &pkthdr, ba->data, &err)) {
luaL_error(L,"error while dumping: %s",
wtap_strerror(err));
}
return 0;
}
WSLUA_METHOD Dumper_new_for_current(lua_State* L) {
#define WSLUA_OPTARG_Dumper_new_for_current_FILETYPE 2
Dumper d;
const char* fname = luaL_checkstring(L,1);
int filetype = luaL_optint(L,WSLUA_OPTARG_Dumper_new_for_current_FILETYPE,WTAP_FILE_TYPE_SUBTYPE_PCAP);
int encap;
int err = 0;
const char* filename;
if (! fname) return 0;
filename = cross_plat_fname(fname);
if (! lua_pinfo ) {
WSLUA_ERROR(Dumper_new_for_current,"Cannot be used outside a tap or a dissector");
return 0;
}
encap = lua_pinfo->fd->lnk_t;
d = wtap_dump_open(filename, filetype, encap, 0, FALSE, &err);
if (! d ) {
switch (err) {
case WTAP_ERR_UNSUPPORTED_FILE_TYPE:
luaL_error(L,"Files of file type %s cannot be written",
wtap_file_type_subtype_string(filetype));
break;
case WTAP_ERR_UNSUPPORTED_ENCAP:
luaL_error(L,"Files of file type %s don't support encapsulation %s",
wtap_file_type_subtype_string(filetype),
wtap_encap_short_string(encap));
break;
default:
luaL_error(L,"error while opening `%s': %s",
filename,
wtap_strerror(err));
break;
}
return 0;
}
pushDumper(L,d);
WSLUA_RETURN(1);
}
WSLUA_METHOD Dumper_dump_current(lua_State* L) {
Dumper d = checkDumper(L,1);
struct wtap_pkthdr pkthdr;
const guchar* data;
tvbuff_t* tvb;
struct data_source *data_src;
int err = 0;
if (!d) return 0;
if (! lua_pinfo ) {
WSLUA_ERROR(Dumper_new_for_current,"Cannot be used outside a tap or a dissector");
return 0;
}
data_src = (struct data_source*) (lua_pinfo->data_src->data);
if (!data_src)
return 0;
tvb = get_data_source_tvb(data_src);
memset(&pkthdr, 0, sizeof(pkthdr));
pkthdr.rec_type = REC_TYPE_PACKET;
pkthdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
pkthdr.ts.secs = lua_pinfo->fd->abs_ts.secs;
pkthdr.ts.nsecs = lua_pinfo->fd->abs_ts.nsecs;
pkthdr.len = tvb_reported_length(tvb);
pkthdr.caplen = tvb_length(tvb);
pkthdr.pkt_encap = lua_pinfo->fd->lnk_t;
pkthdr.pseudo_header = *lua_pinfo->pseudo_header;
if (lua_pinfo->pkt_comment)
pkthdr.opt_comment = wmem_strdup(wmem_packet_scope(), lua_pinfo->pkt_comment);
data = (const guchar *)tvb_memdup(wmem_packet_scope(),tvb,0,pkthdr.caplen);
if (! wtap_dump(d, &pkthdr, data, &err)) {
luaL_error(L,"error while dumping: %s",
wtap_strerror(err));
}
return 0;
}
static int Dumper__gc(lua_State* L) {
Dumper* dp = (Dumper*)luaL_checkudata(L, 1, "Dumper");
int err;
if (! *dp)
return 0;
g_hash_table_remove(dumper_encaps,*dp);
if (!wtap_dump_close(*dp, &err)) {
luaL_error(L,"error closing: %s",
wtap_strerror(err));
}
return 0;
}
int Dumper_register(lua_State* L) {
dumper_encaps = g_hash_table_new(g_direct_hash,g_direct_equal);
WSLUA_REGISTER_CLASS(Dumper);
return 0;
}
