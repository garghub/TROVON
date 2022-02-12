static guint erf_anchor_mapping_hash(gconstpointer key) {
const struct erf_anchor_mapping *anchor_map = (const struct erf_anchor_mapping*) key;
return ((guint32)anchor_map->host_id ^ (guint32)anchor_map->anchor_id);
}
static gboolean erf_anchor_mapping_equal(gconstpointer a, gconstpointer b) {
const struct erf_anchor_mapping *anchor_map_a = (const struct erf_anchor_mapping*) a ;
const struct erf_anchor_mapping *anchor_map_b = (const struct erf_anchor_mapping*) b ;
return (anchor_map_a->host_id) == (anchor_map_b->host_id) &&
(anchor_map_a->anchor_id & ERF_EXT_HDR_TYPE_ANCHOR_ID) == (anchor_map_b->anchor_id & ERF_EXT_HDR_TYPE_ANCHOR_ID);
}
static void erf_anchor_mapping_destroy(gpointer key) {
struct erf_anchor_mapping *anchor_map = (struct erf_anchor_mapping*) key;
if(anchor_map->comment != NULL) {
g_free(anchor_map->comment);
anchor_map->comment = NULL;
}
g_free(anchor_map);
anchor_map = NULL;
}
static gboolean erf_if_mapping_equal(gconstpointer a, gconstpointer b)
{
const struct erf_if_mapping *if_map_a = (const struct erf_if_mapping*) a;
const struct erf_if_mapping *if_map_b = (const struct erf_if_mapping*) b;
return if_map_a->source_id == if_map_b->source_id && if_map_a->host_id == if_map_b->host_id;
}
static guint erf_if_mapping_hash(gconstpointer key)
{
const struct erf_if_mapping *if_map = (const struct erf_if_mapping*) key;
return (((guint) if_map->host_id) << 16) | if_map->source_id;
}
static void erf_if_mapping_destroy(gpointer key)
{
int i = 0;
struct erf_if_mapping *if_map = (struct erf_if_mapping*) key;
for (i = 0; i < 4; i++) {
g_free(if_map->interfaces[i].name);
g_free(if_map->interfaces[i].descr);
}
g_free(if_map->module_filter_str);
g_free(if_map);
}
static struct erf_if_mapping* erf_if_mapping_create(guint64 host_id, guint8 source_id)
{
int i = 0;
struct erf_if_mapping *if_map = NULL;
if_map = (struct erf_if_mapping*) g_malloc0(sizeof(struct erf_if_mapping));
if_map->host_id = host_id;
if_map->source_id = source_id;
for (i = 0; i < 4; i++) {
if_map->interfaces[i].if_index = -1;
if_map->interfaces[i].stream_num = -1;
}
if_map->module_fcs_len = -1;
if_map->module_snaplen = (guint32) -1;
return if_map;
}
erf_t *erf_priv_create(void)
{
erf_t *erf_priv;
erf_priv = (erf_t*) g_malloc(sizeof(erf_t));
erf_priv->anchor_map = g_hash_table_new_full(erf_anchor_mapping_hash, erf_anchor_mapping_equal, erf_anchor_mapping_destroy, NULL);
erf_priv->if_map = g_hash_table_new_full(erf_if_mapping_hash, erf_if_mapping_equal, erf_if_mapping_destroy, NULL);
erf_priv->implicit_host_id = ERF_META_HOST_ID_IMPLICIT;
erf_priv->capture_gentime = 0;
erf_priv->host_gentime = 0;
return erf_priv;
}
erf_t* erf_priv_free(erf_t* erf_priv)
{
if (erf_priv)
{
g_hash_table_destroy(erf_priv->anchor_map);
g_hash_table_destroy(erf_priv->if_map);
g_free(erf_priv);
}
return NULL;
}
static void erf_dump_priv_free(erf_dump_t *dump_priv) {
if(dump_priv) {
if(dump_priv->periodic_sections) {
g_ptr_array_free(dump_priv->periodic_sections, TRUE);
}
if(dump_priv->periodic_extra_ehdrs) {
g_array_free(dump_priv->periodic_extra_ehdrs, TRUE);
}
if(dump_priv->user_comment_ptr) {
g_free(dump_priv->user_comment_ptr);
}
g_free(dump_priv->rand);
g_free(dump_priv);
}
}
static void erf_meta_section_free(gpointer data) {
struct erf_meta_section *section_ptr = (struct erf_meta_section*) data;
if (section_ptr) {
g_ptr_array_free(section_ptr->tags, TRUE);
section_ptr->tags = NULL;
}
g_free(section_ptr);
}
static void erf_meta_tag_free(gpointer data) {
struct erf_meta_tag *tag_ptr = (struct erf_meta_tag*) data;
if (tag_ptr) {
g_free(tag_ptr->value);
tag_ptr->value = NULL;
}
g_free(tag_ptr);
}
static gboolean erf_dump_finish(struct wtap_dumper *wdh, int *err) {
erf_dump_t *dump_priv = (erf_dump_t*)wdh->priv;
gboolean ret = TRUE;
if(dump_priv->write_next_extra_meta) {
if (!dump_priv->periodic_sections) {
dump_priv->periodic_sections = g_ptr_array_new_with_free_func(erf_meta_section_free);
if (dump_priv->prev_erf_type == ERF_TYPE_META && dump_priv->last_meta_periodic) {
erf_comment_to_sections(wdh, ERF_META_SECTION_CAPTURE, 0, dump_priv->user_comment_ptr, dump_priv->periodic_sections);
} else {
erf_wtap_info_to_sections(wdh, dump_priv->periodic_sections);
}
}
if (!erf_write_meta_record(wdh, dump_priv, dump_priv->prev_frame_ts, dump_priv->periodic_sections, dump_priv->periodic_extra_ehdrs, err)) ret = FALSE;
}
erf_dump_priv_free(dump_priv);
wdh->priv = NULL;
return ret;
}
static void
erf_free_data(gpointer data, gpointer user_data _U_)
{
g_free(data);
}
extern wtap_open_return_val erf_open(wtap *wth, int *err, gchar **err_info)
{
int i, n, records_for_erf_check = RECORDS_FOR_ERF_CHECK;
int valid_prev = 0;
char *s;
erf_timestamp_t prevts,ts;
erf_header_t header;
guint32 mc_hdr;
struct erf_eth_hdr eth_hdr;
guint32 packet_size;
guint16 rlen;
guint64 erf_ext_header;
guint8 type;
memset(&prevts, 0, sizeof(prevts));
if ((s = getenv("ERF_RECORDS_TO_CHECK")) != NULL) {
if (ws_strtoi32(s, NULL, &n) && n >= 0 && n < 101) {
records_for_erf_check = n;
}
}
for (i = 0; i < records_for_erf_check; i++) {
if (!wtap_read_bytes_or_eof(wth->fh,&header,sizeof(header),err,err_info)) {
if (*err == 0) {
break;
}
if (*err == WTAP_ERR_SHORT_READ) {
if (i < MIN_RECORDS_FOR_ERF_CHECK) {
return WTAP_OPEN_NOT_MINE;
} else {
break;
}
} else {
return WTAP_OPEN_ERROR;
}
}
rlen=g_ntohs(header.rlen);
if (rlen < 16) {
return WTAP_OPEN_NOT_MINE;
}
packet_size = rlen - (guint32)sizeof(header);
if (packet_size > WTAP_MAX_PACKET_SIZE_STANDARD) {
return WTAP_OPEN_NOT_MINE;
}
if ((header.type & 0x7F) == ERF_TYPE_PAD) {
if (!wtap_read_bytes(wth->fh, NULL, packet_size, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_ERROR;
}
if (i < MIN_RECORDS_FOR_ERF_CHECK) {
return WTAP_OPEN_NOT_MINE;
}
}
continue;
}
if ((header.type & 0x7F) == 0) {
return WTAP_OPEN_NOT_MINE;
}
if ((ts = pletoh64(&header.ts)) < prevts) {
if ( ((prevts-ts)>>32) > 1 ) {
return WTAP_OPEN_NOT_MINE;
}
}
if ( (valid_prev) && (ts > prevts) && (((ts-prevts)>>32) > 3600*24*7) ) {
return WTAP_OPEN_NOT_MINE;
}
memcpy(&prevts, &ts, sizeof(prevts));
type = header.type;
while (type & 0x80){
if (!wtap_read_bytes(wth->fh,&erf_ext_header,sizeof(erf_ext_header),err,err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_NOT_MINE;
}
return WTAP_OPEN_ERROR;
}
packet_size -= (guint32)sizeof(erf_ext_header);
memcpy(&type, &erf_ext_header, sizeof(type));
}
switch(header.type & 0x7F) {
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
case ERF_TYPE_AAL2:
if (!wtap_read_bytes(wth->fh,&mc_hdr,sizeof(mc_hdr),err,err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_NOT_MINE;
}
return WTAP_OPEN_ERROR;
}
packet_size -= (guint32)sizeof(mc_hdr);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
if (!wtap_read_bytes(wth->fh,&eth_hdr,sizeof(eth_hdr),err,err_info)) {
if (*err == WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_NOT_MINE;
}
return WTAP_OPEN_ERROR;
}
packet_size -= (guint32)sizeof(eth_hdr);
break;
default:
break;
}
if (packet_size > WTAP_MAX_PACKET_SIZE_STANDARD) {
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, NULL, packet_size, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ) {
return WTAP_OPEN_ERROR;
}
if (i < MIN_RECORDS_FOR_ERF_CHECK) {
return WTAP_OPEN_NOT_MINE;
}
}
valid_prev = 1;
}
if (file_seek(wth->fh, 0L, SEEK_SET, err) == -1) {
return WTAP_OPEN_ERROR;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_ERF;
wth->snapshot_length = 0;
wth->file_encap = WTAP_ENCAP_ERF;
wth->subtype_read = erf_read;
wth->subtype_seek_read = erf_seek_read;
wth->subtype_close = erf_close;
wth->file_tsprec = WTAP_TSPREC_NSEC;
wth->priv = erf_priv_create();
return WTAP_OPEN_MINE;
}
static gboolean erf_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
erf_header_t erf_header;
guint32 packet_size, bytes_read;
GPtrArray *anchor_mappings_to_update;
*data_offset = file_tell(wth->fh);
anchor_mappings_to_update = g_ptr_array_new_with_free_func(erf_anchor_mapping_destroy);
do {
if (!erf_read_header(wth, wth->fh,
&wth->phdr, &erf_header,
err, err_info, &bytes_read, &packet_size,
anchor_mappings_to_update)) {
g_ptr_array_free(anchor_mappings_to_update, TRUE);
return FALSE;
}
if (!wtap_read_packet_bytes(wth->fh, wth->frame_buffer, packet_size,
err, err_info)) {
g_ptr_array_free(anchor_mappings_to_update, TRUE);
return FALSE;
}
if ((erf_header.type & 0x7F) == ERF_TYPE_META && packet_size > 0)
{
populate_summary_info((erf_t*) wth->priv, wth, &wth->phdr.pseudo_header, packet_size, anchor_mappings_to_update);
}
} while ( erf_header.type == ERF_TYPE_PAD );
g_ptr_array_free(anchor_mappings_to_update, TRUE);
return TRUE;
}
static gboolean erf_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
erf_header_t erf_header;
guint32 packet_size;
GPtrArray *anchor_mappings_to_update;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
anchor_mappings_to_update = g_ptr_array_new_with_free_func(erf_anchor_mapping_destroy);
do {
if (!erf_read_header(wth, wth->random_fh, phdr, &erf_header,
err, err_info, NULL, &packet_size, anchor_mappings_to_update)) {
g_ptr_array_free(anchor_mappings_to_update, TRUE);
return FALSE;
}
} while ( erf_header.type == ERF_TYPE_PAD );
g_ptr_array_free(anchor_mappings_to_update, TRUE);
return wtap_read_packet_bytes(wth->random_fh, buf, packet_size,
err, err_info);
}
static struct erf_anchor_mapping* erf_find_anchor_mapping(erf_t *priv,
guint64 host_id,
guint64 anchor_id)
{
struct erf_anchor_mapping mapping = {
host_id,
anchor_id,
0,
NULL
};
if (!priv) {
return NULL;
}
return (struct erf_anchor_mapping*)g_hash_table_lookup(priv->anchor_map, &mapping);
}
static gboolean erf_read_header(wtap *wth, FILE_T fh,
struct wtap_pkthdr *phdr,
erf_header_t *erf_header,
int *err,
gchar **err_info,
guint32 *bytes_read,
guint32 *packet_size,
GPtrArray *anchor_mappings_to_update)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
guint8 erf_exhdr[8];
guint64 erf_exhdr_sw;
guint8 type = 0;
guint32 mc_hdr;
guint32 aal2_hdr;
struct wtap_erf_eth_hdr eth_hdr;
guint32 skiplen = 0;
int i = 0;
int max = sizeof(pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
erf_t *priv = (erf_t*)wth->priv;
guint64 host_id = ERF_META_HOST_ID_IMPLICIT;
guint8 source_id = 0;
guint8 if_num = 0;
gboolean host_id_found = FALSE;
if (!wtap_read_bytes_or_eof(fh, erf_header, sizeof(*erf_header), err, err_info)) {
return FALSE;
}
if (bytes_read != NULL) {
*bytes_read = sizeof(*erf_header);
}
*packet_size = g_ntohs(erf_header->rlen) - (guint32)sizeof(*erf_header);
if (*packet_size > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("erf: File has %u-byte packet, bigger than maximum of %u",
*packet_size, WTAP_MAX_PACKET_SIZE_STANDARD);
return FALSE;
}
if (*packet_size == 0) {
if ((erf_header->type & 0x7F) != ERF_TYPE_PAD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("erf: File has 0 byte packet");
return FALSE;
}
}
{
guint64 ts = pletoh64(&erf_header->ts);
phdr->rec_type = REC_TYPE_PACKET;
#if 0
} else {
phdr->rec_type = REC_TYPE_FT_SPECIFIC_REPORT;
}
#endif
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN|WTAP_HAS_INTERFACE_ID;
phdr->ts.secs = (long) (ts >> 32);
ts = ((ts & 0xffffffff) * 1000 * 1000 * 1000);
ts += (ts & 0x80000000) << 1;
phdr->ts.nsecs = ((int) (ts >> 32));
if (phdr->ts.nsecs >= 1000000000) {
phdr->ts.nsecs -= 1000000000;
phdr->ts.secs += 1;
}
if_num = erf_header->flags & 0x03;
}
memset(&pseudo_header->erf, 0, sizeof(pseudo_header->erf));
pseudo_header->erf.phdr.ts = pletoh64(&erf_header->ts);
pseudo_header->erf.phdr.type = erf_header->type;
pseudo_header->erf.phdr.flags = erf_header->flags;
pseudo_header->erf.phdr.rlen = g_ntohs(erf_header->rlen);
pseudo_header->erf.phdr.lctr = g_ntohs(erf_header->lctr);
pseudo_header->erf.phdr.wlen = g_ntohs(erf_header->wlen);
type = erf_header->type;
while (type & 0x80){
if (!wtap_read_bytes(fh, &erf_exhdr, sizeof(erf_exhdr),
err, err_info))
return FALSE;
if (bytes_read != NULL)
*bytes_read += (guint32)sizeof(erf_exhdr);
*packet_size -= (guint32)sizeof(erf_exhdr);
skiplen += (guint32)sizeof(erf_exhdr);
erf_exhdr_sw = pntoh64(erf_exhdr);
if (i < max)
memcpy(&pseudo_header->erf.ehdr_list[i].ehdr, &erf_exhdr_sw, sizeof(erf_exhdr_sw));
type = erf_exhdr[0];
switch (type & 0x7FU) {
case ERF_EXT_HDR_TYPE_HOST_ID:
if (!host_id_found)
host_id = erf_exhdr_sw & ERF_EHDR_HOST_ID_MASK;
host_id_found = TRUE;
case ERF_EXT_HDR_TYPE_FLOW_ID:
if (!source_id)
source_id = (erf_exhdr_sw >> 48) & 0xff;
break;
case ERF_EXT_HDR_TYPE_ANCHOR_ID:
break;
}
i++;
}
phdr->interface_id = (guint) erf_populate_interface((erf_t*) wth->priv, wth, pseudo_header, host_id, source_id, if_num);
erf_update_anchors_from_header(priv, phdr, pseudo_header, host_id, anchor_mappings_to_update);
switch (erf_header->type & 0x7F) {
case ERF_TYPE_IPV4:
case ERF_TYPE_IPV6:
case ERF_TYPE_RAW_LINK:
case ERF_TYPE_INFINIBAND:
case ERF_TYPE_INFINIBAND_LINK:
case ERF_TYPE_META:
case ERF_TYPE_OPA_SNC:
case ERF_TYPE_OPA_9B:
#if 0
{
phdr->len = g_htons(erf_header->wlen);
phdr->caplen = g_htons(erf_header->wlen);
}
return TRUE;
#endif
break;
case ERF_TYPE_PAD:
case ERF_TYPE_HDLC_POS:
case ERF_TYPE_COLOR_HDLC_POS:
case ERF_TYPE_DSM_COLOR_HDLC_POS:
case ERF_TYPE_COLOR_HASH_POS:
case ERF_TYPE_ATM:
case ERF_TYPE_AAL5:
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
if (!wtap_read_bytes(fh, &eth_hdr, sizeof(eth_hdr), err, err_info))
return FALSE;
if (bytes_read != NULL)
*bytes_read += (guint32)sizeof(eth_hdr);
*packet_size -= (guint32)sizeof(eth_hdr);
skiplen += (guint32)sizeof(eth_hdr);
pseudo_header->erf.subhdr.eth_hdr = eth_hdr;
break;
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
if (!wtap_read_bytes(fh, &mc_hdr, sizeof(mc_hdr), err, err_info))
return FALSE;
if (bytes_read != NULL)
*bytes_read += (guint32)sizeof(mc_hdr);
*packet_size -= (guint32)sizeof(mc_hdr);
skiplen += (guint32)sizeof(mc_hdr);
pseudo_header->erf.subhdr.mc_hdr = g_ntohl(mc_hdr);
break;
case ERF_TYPE_AAL2:
if (!wtap_read_bytes(fh, &aal2_hdr, sizeof(aal2_hdr), err, err_info))
return FALSE;
if (bytes_read != NULL)
*bytes_read += (guint32)sizeof(aal2_hdr);
*packet_size -= (guint32)sizeof(aal2_hdr);
skiplen += (guint32)sizeof(aal2_hdr);
pseudo_header->erf.subhdr.aal2_hdr = g_ntohl(aal2_hdr);
break;
case ERF_TYPE_IP_COUNTER:
case ERF_TYPE_TCP_FLOW_COUNTER:
default:
break;
}
{
phdr->len = g_ntohs(erf_header->wlen);
phdr->caplen = MIN( g_ntohs(erf_header->wlen),
g_ntohs(erf_header->rlen) - (guint32)sizeof(*erf_header) - skiplen );
}
if (*packet_size > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("erf: File has %u-byte packet, bigger than maximum of %u",
*packet_size, WTAP_MAX_PACKET_SIZE_STANDARD);
return FALSE;
}
return TRUE;
}
static int wtap_wtap_encap_to_erf_encap(int encap)
{
unsigned int i;
for(i = 0; i < NUM_ERF_ENCAPS; i++){
if(erf_to_wtap_map[i].wtap_encap_value == encap)
return erf_to_wtap_map[i].erf_encap_value;
}
return -1;
}
static gboolean erf_write_phdr(wtap_dumper *wdh, int encap, const union wtap_pseudo_header *pseudo_header, int * err)
{
guint8 erf_hdr[sizeof(struct erf_mc_phdr)];
guint8 erf_subhdr[sizeof(union erf_subhdr)];
guint8 ehdr[8*MAX_ERF_EHDR];
size_t size = 0;
size_t subhdr_size = 0;
int i = 0;
guint8 has_more = 0;
switch(encap){
case WTAP_ENCAP_ERF:
memset(&erf_hdr, 0, sizeof(erf_hdr));
phtolell(&erf_hdr[0], pseudo_header->erf.phdr.ts);
erf_hdr[8] = pseudo_header->erf.phdr.type;
erf_hdr[9] = pseudo_header->erf.phdr.flags;
phtons(&erf_hdr[10], pseudo_header->erf.phdr.rlen);
phtons(&erf_hdr[12], pseudo_header->erf.phdr.lctr);
phtons(&erf_hdr[14], pseudo_header->erf.phdr.wlen);
size = sizeof(struct erf_phdr);
switch(pseudo_header->erf.phdr.type & 0x7F) {
case ERF_TYPE_MC_HDLC:
case ERF_TYPE_MC_RAW:
case ERF_TYPE_MC_ATM:
case ERF_TYPE_MC_RAW_CHANNEL:
case ERF_TYPE_MC_AAL5:
case ERF_TYPE_MC_AAL2:
case ERF_TYPE_COLOR_MC_HDLC_POS:
phtonl(&erf_subhdr[0], pseudo_header->erf.subhdr.mc_hdr);
subhdr_size += (int)sizeof(struct erf_mc_hdr);
break;
case ERF_TYPE_AAL2:
phtonl(&erf_subhdr[0], pseudo_header->erf.subhdr.aal2_hdr);
subhdr_size += (int)sizeof(struct erf_aal2_hdr);
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
memcpy(&erf_subhdr[0], &pseudo_header->erf.subhdr.eth_hdr, sizeof pseudo_header->erf.subhdr.eth_hdr);
subhdr_size += (int)sizeof(struct erf_eth_hdr);
break;
default:
break;
}
break;
default:
return FALSE;
}
if (!wtap_dump_file_write(wdh, erf_hdr, size, err))
return FALSE;
wdh->bytes_dumped += size;
has_more = pseudo_header->erf.phdr.type & 0x80;
if(has_more){
do{
phtonll(ehdr+(i*8), pseudo_header->erf.ehdr_list[i].ehdr);
if(i == MAX_ERF_EHDR-1) ehdr[i*8] = ehdr[i*8] & 0x7F;
has_more = ehdr[i*8] & 0x80;
i++;
}while(has_more && i < MAX_ERF_EHDR);
if (!wtap_dump_file_write(wdh, ehdr, 8*i, err))
return FALSE;
wdh->bytes_dumped += 8*i;
}
if(!wtap_dump_file_write(wdh, erf_subhdr, subhdr_size, err))
return FALSE;
wdh->bytes_dumped += subhdr_size;
return TRUE;
}
static void erf_dump_priv_init_gen_time(erf_dump_t *dump_priv) {
GTimeVal real_time;
g_get_current_time(&real_time);
dump_priv->gen_time = ((guint64) real_time.tv_sec << 32) + ((guint64) real_time.tv_usec << 32) / 1000 / 1000;
}
static void erf_write_wtap_option_to_capture_tag(wtap_block_t block _U_,
guint option_id,
wtap_opttype_e option_type _U_,
wtap_optval_t *optval,
void* user_data) {
struct erf_meta_section *section_ptr = (struct erf_meta_section*) user_data;
struct erf_meta_tag *tag_ptr = NULL;
tag_ptr = (struct erf_meta_tag*) g_malloc0(sizeof(struct erf_meta_tag));
switch(option_id) {
case OPT_SHB_USERAPPL:
tag_ptr->type = ERF_META_TAG_app_name;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_COMMENT:
tag_ptr->type = ERF_META_TAG_comment;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
default:
erf_meta_tag_free(tag_ptr);
tag_ptr = NULL;
break;
}
if (tag_ptr)
g_ptr_array_add(section_ptr->tags, tag_ptr);
}
static void erf_write_wtap_option_to_host_tag(wtap_block_t block _U_,
guint option_id,
wtap_opttype_e option_type _U_,
wtap_optval_t *optval,
void* user_data) {
struct erf_meta_section *section_ptr = (struct erf_meta_section*) user_data;
struct erf_meta_tag *tag_ptr = NULL;
tag_ptr = (struct erf_meta_tag*) g_malloc0(sizeof(struct erf_meta_tag));
switch(option_id) {
case OPT_SHB_HARDWARE:
tag_ptr->type = ERF_META_TAG_cpu;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_SHB_OS:
tag_ptr->type = ERF_META_TAG_os;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
default:
erf_meta_tag_free(tag_ptr);
tag_ptr = NULL;
break;
}
if (tag_ptr)
g_ptr_array_add(section_ptr->tags, tag_ptr);
}
static void erf_write_wtap_option_to_interface_tag(wtap_block_t block _U_,
guint option_id,
wtap_opttype_e option_type _U_,
wtap_optval_t *optval,
void* user_data) {
struct erf_meta_section *section_ptr = (struct erf_meta_section*) user_data;
struct erf_meta_tag *tag_ptr = NULL;
tag_ptr = (struct erf_meta_tag*) g_malloc0(sizeof(struct erf_meta_tag));
switch(option_id) {
case OPT_COMMENT:
tag_ptr->type = ERF_META_TAG_comment;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_IDB_NAME:
tag_ptr->type = ERF_META_TAG_name;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_IDB_DESCR:
tag_ptr->type = ERF_META_TAG_descr;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_IDB_OS:
tag_ptr->type = ERF_META_TAG_os;
tag_ptr->value = (guint8*)g_strdup(optval->stringval);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
break;
case OPT_IDB_TSOFFSET:
tag_ptr->type = ERF_META_TAG_ts_offset;
tag_ptr->length = 8;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->uint64val));
phtolell(tag_ptr->value, optval->uint64val << 32);
break;
case OPT_IDB_SPEED:
tag_ptr->type = ERF_META_TAG_if_speed;
tag_ptr->length = 8;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->uint64val));
phtonll(tag_ptr->value, optval->uint64val);
break;
case OPT_IDB_IP4ADDR:
tag_ptr->type = ERF_META_TAG_if_ipv4;
tag_ptr->length = 4;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->ipv4val));
memcpy(tag_ptr->value, &optval->ipv4val, sizeof(optval->ipv4val));
break;
case OPT_IDB_IP6ADDR:
tag_ptr->type = ERF_META_TAG_if_ipv6;
tag_ptr->length = 16;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->ipv6val));
memcpy(tag_ptr->value, &optval->ipv6val, sizeof(optval->ipv6val));
break;
case OPT_IDB_FILTER:
{
wtapng_if_descr_filter_t *filter;
tag_ptr->type = 0xF800;
filter = (wtapng_if_descr_filter_t*)&optval->customval;
if(filter->if_filter_str) {
tag_ptr->type = ERF_META_TAG_filter;
tag_ptr->value = (guint8*)g_strdup(filter->if_filter_str);
tag_ptr->length = (guint16)strlen((char*)tag_ptr->value);
}
}
break;
case OPT_IDB_FCSLEN:
tag_ptr->type = ERF_META_TAG_fcs_len;
tag_ptr->length = 4;
tag_ptr->value = (guint8*)g_malloc(tag_ptr->length);
phtonl(tag_ptr->value, (guint32)optval->uint8val);
break;
case OPT_IDB_EUIADDR:
#if 0
tag_ptr->type = ERF_META_TAG_if_eui;
tag_ptr->length = 8;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->eui64val));
memcpy(tag_ptr->value, &optval->euival, sizeof(optval->eui64val));
break;
#endif
case OPT_IDB_MACADDR:
#if 0
tag_ptr->type = ERF_META_TAG_if_mac;
tag_ptr->length = 6;
tag_ptr->value = (guint8*)g_malloc(sizeof(optval->macval));
memcpy(tag_ptr->value, &optval->macval, sizeof(optval->macval));
break;
#endif
case OPT_IDB_TSRESOL:
case OPT_IDB_TZONE:
default:
erf_meta_tag_free(tag_ptr);
tag_ptr = NULL;
break;
}
if (tag_ptr)
g_ptr_array_add(section_ptr->tags, tag_ptr);
}
static void erf_populate_section_length_by_tags(struct erf_meta_section *section_ptr) {
guint i = 0;
struct erf_meta_tag *tag_ptr;
section_ptr->section_length = 8;
for(;i < section_ptr->tags->len; i++) {
tag_ptr = (struct erf_meta_tag*)g_ptr_array_index(section_ptr->tags, i);
section_ptr->section_length += ERF_META_TAG_TOTAL_ALIGNED_LENGTH(tag_ptr->length);
}
}
static gboolean erf_wtap_blocks_to_erf_sections(wtap_block_t block, GPtrArray *sections, guint16 section_type, guint16 section_id, wtap_block_foreach_func func) {
if(!block || !sections || !func) {
return FALSE;
}
struct erf_meta_section *section_ptr;
section_ptr = (struct erf_meta_section*) g_malloc(sizeof(struct erf_meta_section));
section_ptr->tags = g_ptr_array_new_with_free_func(erf_meta_tag_free);
section_ptr->type = section_type;
section_ptr->section_id = section_id;
wtap_block_foreach_option(block, func, (void*)section_ptr);
erf_populate_section_length_by_tags(section_ptr);
g_ptr_array_add(sections, section_ptr);
return TRUE;
}
static gboolean erf_meta_write_tag(wtap_dumper *wdh, struct erf_meta_tag *tag_ptr, int *err) {
guint16 data[2];
guint pad = 0;
guint32 padbuf = 0;
pad = ERF_META_TAG_ALIGNED_LENGTH(tag_ptr->length) - tag_ptr->length;
data[0] = g_htons(tag_ptr->type);
data[1] = g_htons(tag_ptr->length);
if(!wtap_dump_file_write(wdh, data, sizeof(data), err)) return FALSE;
wdh->bytes_dumped += sizeof(data);
if(!wtap_dump_file_write(wdh, tag_ptr->value, tag_ptr->length, err)) return FALSE;
wdh->bytes_dumped += tag_ptr->length;
if(pad) {
if(!wtap_dump_file_write(wdh, &padbuf, pad, err)) return FALSE;
wdh->bytes_dumped += pad;
}
return TRUE;
}
static gboolean erf_meta_write_section(wtap_dumper *wdh, struct erf_meta_section *section_ptr, int *err) {
struct erf_meta_tag *tag_ptr;
guint i;
guint16 data[4];
data[0] = g_htons(section_ptr->type);
data[1] = g_htons(4);
data[2] = g_htons(section_ptr->section_id);
data[3] = g_htons(section_ptr->section_length);
if(!wtap_dump_file_write(wdh, data, sizeof(data), err)) return FALSE;
wdh->bytes_dumped += sizeof(data);
for(i = 0; i < section_ptr->tags->len; i++) {
tag_ptr = (struct erf_meta_tag*)g_ptr_array_index(section_ptr->tags, i);
if(!erf_meta_write_tag(wdh, tag_ptr, err)) return FALSE;
}
return TRUE;
}
static gboolean erf_wtap_info_to_sections(wtap_dumper *wdh, GPtrArray *sections) {
wtap_block_t block;
guint i = 0;
block = g_array_index(wdh->shb_hdrs, wtap_block_t, 0);
erf_wtap_blocks_to_erf_sections(block, sections, ERF_META_SECTION_CAPTURE, 0, erf_write_wtap_option_to_capture_tag);
block = g_array_index(wdh->shb_hdrs, wtap_block_t, 0);
erf_wtap_blocks_to_erf_sections(block, sections, ERF_META_SECTION_HOST, 0, erf_write_wtap_option_to_host_tag);
for(i = 0; i < wdh->interface_data->len; i++) {
block = g_array_index(wdh->interface_data, wtap_block_t, i);
erf_wtap_blocks_to_erf_sections(block, sections, ERF_META_SECTION_INTERFACE, (gint16)i+1, erf_write_wtap_option_to_interface_tag);
}
return TRUE;
}
static gboolean erf_comment_to_sections(wtap_dumper *wdh _U_, guint16 section_type, guint16 section_id, gchar *comment, GPtrArray *sections){
struct erf_meta_section *section_ptr;
struct erf_meta_tag *comment_tag_ptr = NULL;
struct erf_meta_tag *user_tag_ptr = NULL;
const gchar *user = NULL;
section_ptr = (struct erf_meta_section*) g_malloc(sizeof(struct erf_meta_section));
section_ptr->type = section_type;
section_ptr->section_id = section_id;
section_ptr->tags = g_ptr_array_new_with_free_func(erf_meta_tag_free);
comment_tag_ptr = (struct erf_meta_tag*) g_malloc(sizeof(struct erf_meta_tag));
comment_tag_ptr->type = ERF_META_TAG_comment;
comment_tag_ptr->value = (guint8*)g_strdup(comment ? comment : "");
comment_tag_ptr->length = (guint16)strlen((char*)comment_tag_ptr->value);
g_ptr_array_add(section_ptr->tags, comment_tag_ptr);
user = g_get_user_name();
if (user) {
user_tag_ptr = (struct erf_meta_tag*) g_malloc(sizeof(struct erf_meta_tag));
user_tag_ptr->type = ERF_META_TAG_user;
user_tag_ptr->value = (guint8*)g_strdup(user);
user_tag_ptr->length = (guint16)strlen((char*)user_tag_ptr->value);
g_ptr_array_add(section_ptr->tags, user_tag_ptr);
}
erf_populate_section_length_by_tags(section_ptr);
g_ptr_array_add(sections, section_ptr);
return TRUE;
}
static guint64 erf_get_random_anchor_id(erf_dump_t *dump_priv) {
return (((guint64)g_rand_int(dump_priv->rand) << 32) | (guint64)g_rand_int(dump_priv->rand)) >> 16;
}
static guint64 erf_metaid_ext_hdr(guint8 exthdr_type, guint64 id, guint8 srcid_flags) {
guint64 ext_hdr;
ext_hdr = id & ERF_EHDR_HOST_ID_MASK;
ext_hdr |= ((guint64)srcid_flags) << 48;
ext_hdr |= ((guint64)exthdr_type) << 56;
return ext_hdr;
}
static inline gboolean erf_add_ext_hdr_to_list(guint64 ext_hdr, guint64 comparison_mask, GArray *extra_ehdrs) {
guint i = 0;
struct erf_ehdr ehdr_tmp;
struct erf_ehdr *ehdr_ptr = NULL;
if (!extra_ehdrs)
return FALSE;
ext_hdr = ext_hdr & ~ERF_EHDR_MORE_EXTHDR_MASK;
if (comparison_mask == 0)
comparison_mask = G_MAXUINT64;
comparison_mask &= ~ERF_EHDR_MORE_EXTHDR_MASK;
for (i = 0; i < extra_ehdrs->len; i++) {
ehdr_ptr = &g_array_index(extra_ehdrs, struct erf_ehdr, i);
if (ext_hdr == (ehdr_ptr->ehdr & comparison_mask)) {
return TRUE;
}
}
if (ehdr_ptr) {
ehdr_ptr->ehdr |= ERF_EHDR_MORE_EXTHDR_MASK;
}
ehdr_tmp.ehdr = ext_hdr;
g_array_append_val(extra_ehdrs, ehdr_tmp);
return TRUE;
}
static inline gboolean erf_append_ext_hdr_to_list(guint64 ext_hdr, GArray *extra_ehdrs) {
struct erf_ehdr ehdr_tmp;
if (!extra_ehdrs)
return FALSE;
ehdr_tmp.ehdr = ext_hdr & ~ERF_EHDR_MORE_EXTHDR_MASK;
if (extra_ehdrs->len) {
g_array_index(extra_ehdrs, struct erf_ehdr, extra_ehdrs->len - 1).ehdr |= ERF_EHDR_MORE_EXTHDR_MASK;
}
g_array_append_val(extra_ehdrs, ehdr_tmp);
return TRUE;
}
static gboolean erf_update_host_id_ext_hdrs_list(erf_dump_t *dump_priv, const union wtap_pseudo_header *pseudo_header, GArray *extra_ehdrs) {
guint8 type;
guint8 erf_type;
int has_more;
guint64 hdr;
int i = 0;
guint8 source_id = 0;
guint64 host_id = 0;
gboolean host_id_found = FALSE;
if (!extra_ehdrs)
return FALSE;
erf_type = pseudo_header->erf.phdr.type & 0x7f;
has_more = pseudo_header->erf.phdr.type & 0x80;
while (has_more && i < MAX_ERF_EHDR) {
hdr = pseudo_header->erf.ehdr_list[i].ehdr;
type = (guint8) (hdr >> 56);
switch (type & 0x7f) {
case ERF_EXT_HDR_TYPE_HOST_ID:
host_id = hdr & ERF_EHDR_HOST_ID_MASK;
source_id = (hdr >> 48) & 0xff;
if (host_id != dump_priv->host_id || source_id != 0)
if (!erf_add_ext_hdr_to_list(hdr, 0, extra_ehdrs)) return FALSE;
if (!host_id_found) {
if (erf_type == ERF_TYPE_META && ((hdr >> 48) & 0xff) > 0) {
if (dump_priv->implicit_host_id == ERF_META_HOST_ID_IMPLICIT) {
dump_priv->implicit_host_id = host_id;
}
}
}
host_id_found = TRUE;
break;
case ERF_EXT_HDR_TYPE_FLOW_ID:
if (source_id == 0)
source_id = (hdr >> 48) & 0xff;
break;
}
has_more = type & 0x80;
i++;
}
if (!host_id_found) {
guint64 implicit_host_id = dump_priv->implicit_host_id == ERF_META_HOST_ID_IMPLICIT ? 0 : dump_priv->implicit_host_id;
if (implicit_host_id != dump_priv->host_id || source_id != 0)
if (!erf_add_ext_hdr_to_list(erf_host_id_ext_hdr(implicit_host_id, source_id), 0, extra_ehdrs)) return FALSE;
}
return TRUE;
}
static gboolean erf_write_anchor_meta_update_phdr(wtap_dumper *wdh, erf_dump_t *dump_priv, const struct wtap_pkthdr *phdr, union wtap_pseudo_header *mutable_hdr, int *err) {
GArray *meta_ehdrs;
GPtrArray* sections = NULL;
guint8 has_more;
guint8 i = 0;
guint8 ext_hdr_count = 0;
guint8 j = 0;
guint64 host_id_src_hdr = ERF_META_HOST_ID_IMPLICIT;
guint64 host_id_own_hdr = erf_host_id_ext_hdr(dump_priv->host_id, 0);
guint64 flow_id_hdr = 0;
guint64 anchor_id_hdr = 0;
gboolean found_host_id = FALSE;
gboolean found_own_host_id = FALSE;
gboolean found_flow_id = FALSE;
gint new_ext_hdrs = 0;
guint8 insert_idx = 0;
guint8 source_id = 0;
gboolean ret = FALSE;
guint64 implicit_host_id = dump_priv->implicit_host_id == ERF_META_HOST_ID_IMPLICIT ? 0 : dump_priv->implicit_host_id;
has_more = mutable_hdr->erf.phdr.type & 0x80;
while (has_more && (i < MAX_ERF_EHDR)) {
guint64 hdr = mutable_hdr->erf.ehdr_list[i].ehdr;
guint8 type = (guint8) (hdr >> 56);
switch (type & 0x7f) {
case ERF_EXT_HDR_TYPE_HOST_ID:
if (found_own_host_id && !insert_idx)
insert_idx = i;
if ((hdr & ERF_EHDR_HOST_ID_MASK) == dump_priv->host_id){
found_own_host_id = TRUE;
}
if (!found_host_id)
host_id_src_hdr = hdr;
found_host_id = TRUE;
break;
case ERF_EXT_HDR_TYPE_FLOW_ID:
if (source_id == 0)
source_id = (guint8)(hdr >> 48);
if (!found_flow_id)
flow_id_hdr = hdr;
found_flow_id = TRUE;
break;
}
has_more = type & 0x80;
i += 1;
}
ext_hdr_count = i;
if (!insert_idx)
insert_idx = i;
if (!found_host_id && implicit_host_id == dump_priv->host_id) {
found_own_host_id = TRUE;
}
new_ext_hdrs = 1 + (found_own_host_id?0:1) + (found_host_id?0:1);
if(ext_hdr_count + new_ext_hdrs > MAX_ERF_EHDR
|| mutable_hdr->erf.phdr.rlen + new_ext_hdrs * 8 > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
mutable_hdr->erf.phdr.rlen += new_ext_hdrs * 8;
mutable_hdr->erf.phdr.type |= 0x80;
if (insert_idx > 0) {
mutable_hdr->erf.ehdr_list[insert_idx-1].ehdr |= ERF_EHDR_MORE_EXTHDR_MASK;
}
anchor_id_hdr = erf_anchor_id_ext_hdr(erf_get_random_anchor_id(dump_priv), 0);
if (insert_idx < ext_hdr_count) {
for (j = ext_hdr_count; j > insert_idx; j--) {
mutable_hdr->erf.ehdr_list[j].ehdr = mutable_hdr->erf.ehdr_list[j-1].ehdr;
}
anchor_id_hdr |= ERF_EHDR_MORE_EXTHDR_MASK;
}
if(!found_host_id) {
host_id_src_hdr = erf_host_id_ext_hdr(implicit_host_id, source_id);
mutable_hdr->erf.ehdr_list[insert_idx++].ehdr = ERF_EHDR_SET_MORE_EXTHDR(host_id_src_hdr);
}
if(!found_own_host_id) {
mutable_hdr->erf.ehdr_list[insert_idx++].ehdr = ERF_EHDR_SET_MORE_EXTHDR(host_id_own_hdr);
}
mutable_hdr->erf.ehdr_list[insert_idx].ehdr = anchor_id_hdr;
meta_ehdrs = g_array_new(FALSE, FALSE, sizeof(struct erf_ehdr));
erf_append_ext_hdr_to_list(anchor_id_hdr | ERF_EHDR_ANCHOR_ID_DEFINITION_MASK, meta_ehdrs);
erf_append_ext_hdr_to_list(host_id_src_hdr, meta_ehdrs);
if (found_flow_id) {
erf_append_ext_hdr_to_list(flow_id_hdr & ~(ERF_EHDR_FLOW_ID_STACK_TYPE_MASK|ERF_EHDR_FLOW_ID_SOURCE_ID_MASK), meta_ehdrs);
}
sections = g_ptr_array_new_with_free_func(erf_meta_section_free);
erf_comment_to_sections(wdh, ERF_META_SECTION_INFO, 0x8000 , phdr->opt_comment, sections);
ret = erf_write_meta_record(wdh, dump_priv, mutable_hdr->erf.phdr.ts, sections, meta_ehdrs, err);
g_ptr_array_free(sections, TRUE);
g_array_free(meta_ehdrs, TRUE);
return ret;
}
static gboolean erf_write_meta_record(wtap_dumper *wdh, erf_dump_t *dump_priv, guint64 timestamp, GPtrArray *sections, GArray *extra_ehdrs, int *err) {
union wtap_pseudo_header other_header;
struct erf_meta_tag gen_time_tag;
struct erf_meta_section *section_ptr;
guint total_wlen = 0;
guint total_rlen = 0;
gint64 alignbytes = 0;
guint i;
guint num_extra_ehdrs = 0;
if(!sections || sections->len <= 0)
return FALSE;
for(i = 0; i < sections->len; i++) {
section_ptr = (struct erf_meta_section*)g_ptr_array_index(sections, i);
total_wlen += section_ptr->section_length;
}
gen_time_tag.type = ERF_META_TAG_gen_time;
gen_time_tag.length = 8U;
gen_time_tag.value = (guint8*)&dump_priv->gen_time;
total_wlen += gen_time_tag.length + 4;
total_rlen = total_wlen + 24;
if (extra_ehdrs) {
num_extra_ehdrs = MIN(extra_ehdrs->len, MAX_ERF_EHDR - 1);
total_rlen += num_extra_ehdrs * 8;
}
total_rlen += ERF_PADDING_TO_8(total_rlen);
if(total_rlen > 65535) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
other_header.erf.phdr.ts = timestamp;
other_header.erf.phdr.type = ERF_TYPE_META | 0x80;
other_header.erf.phdr.flags = 0x04;
other_header.erf.phdr.lctr = 0;
other_header.erf.phdr.wlen = (guint16)total_wlen;
other_header.erf.phdr.rlen = (guint16)total_rlen;
other_header.erf.ehdr_list[0].ehdr = erf_host_id_ext_hdr(dump_priv->host_id, 0);
if (num_extra_ehdrs > 0) {
other_header.erf.ehdr_list[0].ehdr |= ERF_EHDR_MORE_EXTHDR_MASK;
memcpy(&other_header.erf.ehdr_list[1], extra_ehdrs->data, sizeof(struct erf_ehdr) * num_extra_ehdrs);
}
alignbytes = wdh->bytes_dumped + other_header.erf.phdr.rlen;
if(!erf_write_phdr(wdh, WTAP_ENCAP_ERF, &other_header, err)) return FALSE;
erf_meta_write_tag(wdh, &gen_time_tag, err);
for(i = 0; i < sections->len; i++) {
section_ptr = (struct erf_meta_section*)g_ptr_array_index(sections, i);
erf_meta_write_section(wdh, section_ptr, err);
}
while(wdh->bytes_dumped < alignbytes){
if(!wtap_dump_file_write(wdh, "", 1, err)) return FALSE;
wdh->bytes_dumped++;
}
wdh->needs_reload = TRUE;
return TRUE;
}
erf_dump_t *erf_dump_priv_create(void) {
erf_dump_t *dump_priv;
dump_priv = (erf_dump_t*)g_malloc(sizeof(erf_dump_t));
dump_priv->write_next_extra_meta = FALSE;
dump_priv->last_meta_periodic = FALSE;
dump_priv->gen_time = 0;
dump_priv->host_id = ERF_WS_DEFAULT_HOST_ID;
dump_priv->implicit_host_id = ERF_META_HOST_ID_IMPLICIT;
dump_priv->first_frame_time_sec = 0;
dump_priv->prev_inserted_time_sec = 0;
dump_priv->prev_frame_ts = 0;
dump_priv->prev_erf_type = 0;
dump_priv->user_comment_ptr = NULL;
dump_priv->periodic_sections = NULL;
dump_priv->periodic_extra_ehdrs = g_array_new(FALSE, FALSE, sizeof(struct erf_ehdr));
dump_priv->rand = g_rand_new();
return dump_priv;
}
static gboolean erf_dump(
wtap_dumper *wdh,
const struct wtap_pkthdr *phdr,
const guint8 *pd,
int *err,
gchar **err_info _U_)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
union wtap_pseudo_header other_phdr;
int encap;
int erf_type;
gint64 alignbytes = 0;
guint padbytes = 0;
int round_down = 0;
gboolean must_add_crc = FALSE;
guint32 crc32 = 0x00000000;
erf_dump_t *dump_priv = (erf_dump_t*)wdh->priv;
guint64 non_erf_host_id_ehdr = erf_host_id_ext_hdr(0, 1);
if(phdr->caplen > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
if(wdh->encap == WTAP_ENCAP_PER_PACKET){
encap = phdr->pkt_encap;
}else{
encap = wdh->encap;
}
if(!dump_priv->gen_time) {
erf_dump_priv_init_gen_time(dump_priv);
dump_priv->first_frame_time_sec = phdr->ts.secs;
}
if (encap != WTAP_ENCAP_ERF) {
unsigned int total_rlen;;
unsigned int total_wlen;
total_rlen = phdr->caplen+16;
total_wlen = phdr->len;
if (phdr->rec_type != REC_TYPE_PACKET) {
*err = WTAP_ERR_UNWRITABLE_REC_TYPE;
return FALSE;
}
if ((erf_type = wtap_wtap_encap_to_erf_encap(encap)) == -1) {
*err = WTAP_ERR_UNWRITABLE_ENCAP;
return FALSE;
}
memset(&other_phdr, 0, sizeof(union wtap_pseudo_header));
other_phdr.erf.phdr.ts = ((guint64) phdr->ts.secs << 32) + (((guint64) phdr->ts.nsecs <<32) / 1000 / 1000 / 1000);
other_phdr.erf.phdr.type = (guint8)erf_type;
other_phdr.erf.phdr.flags = phdr->interface_id % ERF_MAX_INTERFACES;
other_phdr.erf.phdr.flags |= 0x4;
other_phdr.erf.phdr.lctr = 0;
switch(other_phdr.erf.phdr.type & 0x7F){
case ERF_TYPE_ETH:
total_rlen += 2;
if (pseudo_header->eth.fcs_len != 4) {
if(!(phdr->caplen < phdr->len)){
crc32 = crc32_ccitt_seed(pd, phdr->caplen, 0xFFFFFFFF);
total_rlen += 4;
total_wlen += 4;
must_add_crc = TRUE;
}
}
break;
case ERF_TYPE_HDLC_POS:
if(!(phdr->caplen < phdr->len)){
crc32 = crc32_ccitt_seed(pd, phdr->caplen, 0xFFFFFFFF);
total_rlen += 4;
total_wlen += 4;
must_add_crc = TRUE;
}
break;
default:
break;
}
other_phdr.erf.phdr.type |= 0x80;
other_phdr.erf.ehdr_list[0].ehdr = non_erf_host_id_ehdr;
total_rlen += 8;
padbytes = ERF_PADDING_TO_8(total_rlen);
if(phdr->caplen < phdr->len){
round_down = (8 - padbytes) % 8;
total_rlen -= round_down;
}else{
total_rlen += padbytes;
}
if (total_rlen > G_MAXUINT16 || total_wlen > G_MAXUINT16) {
*err = WTAP_ERR_PACKET_TOO_LARGE;
return FALSE;
}
other_phdr.erf.phdr.rlen = (guint16)total_rlen;
other_phdr.erf.phdr.wlen = (guint16)total_wlen;
pseudo_header = &other_phdr;
}
erf_type = pseudo_header->erf.phdr.type & 0x7FU;
erf_update_host_id_ext_hdrs_list(dump_priv, pseudo_header, dump_priv->periodic_extra_ehdrs);
if (erf_type == ERF_TYPE_META) {
dump_priv->last_meta_periodic = erf_dump_priv_compare_capture_comment(wdh, dump_priv, pseudo_header, pd);
} else {
if (dump_priv->prev_erf_type == ERF_TYPE_META && dump_priv->last_meta_periodic) {
if(dump_priv->write_next_extra_meta) {
if (!dump_priv->periodic_sections) {
dump_priv->periodic_sections = g_ptr_array_new_with_free_func(erf_meta_section_free);
erf_comment_to_sections(wdh, ERF_META_SECTION_CAPTURE, 0, dump_priv->user_comment_ptr, dump_priv->periodic_sections);
}
if (!erf_write_meta_record(wdh, dump_priv, dump_priv->prev_frame_ts, dump_priv->periodic_sections, dump_priv->periodic_extra_ehdrs, err)) return FALSE;
dump_priv->prev_inserted_time_sec = phdr->ts.secs;
}
dump_priv->write_next_extra_meta = FALSE;
} else if (phdr->ts.secs > dump_priv->first_frame_time_sec + 1
&& dump_priv->prev_inserted_time_sec != phdr->ts.secs) {
if (dump_priv->write_next_extra_meta) {
if (!dump_priv->periodic_sections) {
dump_priv->periodic_sections = g_ptr_array_new_with_free_func(erf_meta_section_free);
erf_wtap_info_to_sections(wdh, dump_priv->periodic_sections);
}
}
if (dump_priv->periodic_sections) {
if (!erf_write_meta_record(wdh, dump_priv, (guint64)(phdr->ts.secs) << 32, dump_priv->periodic_sections, dump_priv->periodic_extra_ehdrs, err)) return FALSE;
dump_priv->prev_inserted_time_sec = phdr->ts.secs;
}
}
}
if(phdr->opt_comment || phdr->has_comment_changed) {
if (encap == WTAP_ENCAP_ERF) {
if(phdr->has_comment_changed) {
memcpy(&other_phdr, pseudo_header, sizeof(union wtap_pseudo_header));
if(!erf_write_anchor_meta_update_phdr(wdh, dump_priv, phdr, &other_phdr, err)) return FALSE;
pseudo_header = &other_phdr;
}
} else {
if(!erf_write_anchor_meta_update_phdr(wdh, dump_priv, phdr, &other_phdr, err)) return FALSE;
}
}
alignbytes = wdh->bytes_dumped + pseudo_header->erf.phdr.rlen;
if(!erf_write_phdr(wdh, WTAP_ENCAP_ERF, pseudo_header, err)) return FALSE;
if(!wtap_dump_file_write(wdh, pd, phdr->caplen - round_down, err)) return FALSE;
wdh->bytes_dumped += phdr->caplen - round_down;
if(must_add_crc){
if(!wtap_dump_file_write(wdh, &crc32, 4, err)) return FALSE;
wdh->bytes_dumped += 4;
}
while(wdh->bytes_dumped < alignbytes){
if(!wtap_dump_file_write(wdh, "", 1, err)) return FALSE;
wdh->bytes_dumped++;
}
dump_priv->prev_erf_type = pseudo_header->erf.phdr.type & 0x7FU;
dump_priv->prev_frame_ts = pseudo_header->erf.phdr.ts;
return TRUE;
}
int erf_dump_can_write_encap(int encap)
{
if(encap == WTAP_ENCAP_PER_PACKET)
return 0;
if (wtap_wtap_encap_to_erf_encap(encap) == -1)
return WTAP_ERR_UNWRITABLE_ENCAP;
return 0;
}
int erf_dump_open(wtap_dumper *wdh, int *err _U_)
{
erf_dump_t *dump_priv;
gchar *s;
guint64 host_id;
dump_priv = erf_dump_priv_create();
wdh->subtype_write = erf_dump;
wdh->priv = dump_priv;
wdh->subtype_finish = erf_dump_finish;
get_user_comment_string(wdh, &dump_priv->user_comment_ptr);
if (dump_priv->user_comment_ptr || wdh->encap != WTAP_ENCAP_ERF)
dump_priv->write_next_extra_meta = TRUE;
if ((s = getenv("ERF_HOST_ID")) != NULL) {
if (ws_hexstrtou64(s, NULL, &host_id)) {
dump_priv->host_id = host_id & ERF_EHDR_HOST_ID_MASK;
}
}
return TRUE;
}
int erf_populate_interfaces(wtap *wth)
{
wtap_block_t int_data;
wtapng_if_descr_mandatory_t* int_data_mand;
int i;
if (!wth)
return -1;
for (i=0; i<4; i++) {
int_data = wtap_block_create(WTAP_BLOCK_IF_DESCR);
int_data_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(int_data);
int_data_mand->wtap_encap = WTAP_ENCAP_ERF;
int_data_mand->time_units_per_second = 1000000000;
int_data_mand->snap_len = 65535;
wtap_block_add_uint8_option(int_data, OPT_IDB_TSRESOL, 0x09);
int_data_mand->num_stat_entries = 0;
int_data_mand->interface_statistics = NULL;
wtap_block_add_string_option_format(int_data, OPT_IDB_NAME, "Port %c", 'A'+i);
wtap_block_add_string_option_format(int_data, OPT_IDB_DESCR, "ERF Interface Id %d (Port %c)", i, 'A'+i);
g_array_append_val(wth->interface_data, int_data);
}
return 0;
}
int erf_get_source_from_header(union wtap_pseudo_header *pseudo_header, guint64 *host_id, guint8 *source_id)
{
guint8 type;
guint8 has_more;
guint64 hdr;
int i = 0;
gboolean host_id_found = FALSE;
if (!pseudo_header || !host_id || !source_id)
return -1;
*host_id = ERF_META_HOST_ID_IMPLICIT;
*source_id = 0;
has_more = pseudo_header->erf.phdr.type & 0x80;
while (has_more && (i < MAX_ERF_EHDR)) {
hdr = pseudo_header->erf.ehdr_list[i].ehdr;
type = (guint8) (hdr >> 56);
switch (type & 0x7f) {
case ERF_EXT_HDR_TYPE_HOST_ID:
if (!host_id_found)
*host_id = hdr & ERF_EHDR_HOST_ID_MASK;
host_id_found = TRUE;
case ERF_EXT_HDR_TYPE_FLOW_ID:
if (*source_id == 0)
*source_id = (hdr >> 48) & 0xff;
break;
}
if (host_id_found)
break;
has_more = type & 0x80;
i += 1;
}
return 0;
}
int erf_populate_interface_from_header(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header)
{
guint64 host_id;
guint8 source_id;
guint8 if_num;
if (!pseudo_header)
return -1;
if_num = pseudo_header->erf.phdr.flags & 0x03;
erf_get_source_from_header(pseudo_header, &host_id, &source_id);
return erf_populate_interface(erf_priv, wth, pseudo_header, host_id, source_id, if_num);
}
static struct erf_if_mapping* erf_find_interface_mapping(erf_t *erf_priv, guint64 host_id, guint8 source_id)
{
struct erf_if_mapping if_map_lookup;
if (!erf_priv)
return NULL;
if_map_lookup.host_id = host_id;
if_map_lookup.source_id = source_id;
return (struct erf_if_mapping*) g_hash_table_lookup(erf_priv->if_map, &if_map_lookup);
}
static void erf_set_interface_descr(wtap_block_t block, guint option_id, guint64 host_id, guint8 source_id, guint8 if_num, const gchar *descr)
{
char sourceid_buf[16];
char hostid_buf[24];
sourceid_buf[0] = '\0';
hostid_buf[0] = '\0';
if (host_id == ERF_META_HOST_ID_IMPLICIT) {
host_id = 0;
}
if (host_id > 0) {
g_snprintf(hostid_buf, sizeof(hostid_buf), " Host %012" G_GINT64_MODIFIER "x,", host_id);
}
if (source_id > 0) {
g_snprintf(sourceid_buf, sizeof(sourceid_buf), " Source %u,", source_id);
}
if (descr) {
wtap_block_set_string_option_value_format(block, option_id, "%s (ERF%s%s Interface %d)", descr, hostid_buf, sourceid_buf, if_num);
} else {
wtap_block_set_string_option_value_format(block, option_id, "Port %c (ERF%s%s Interface %d)", 'A'+if_num, hostid_buf, sourceid_buf, if_num);
}
}
static int erf_update_anchors_from_header(erf_t *erf_priv, struct wtap_pkthdr *phdr, union wtap_pseudo_header *pseudo_header, guint64 host_id, GPtrArray *anchor_mappings_to_update)
{
guint8 type;
guint8 has_more;
guint64 hdr;
guint64 comment_gen_time = 0;
guint64 host_id_current;
guint64 anchor_id_current = 0;
int i = 0;
gchar *comment = NULL;
if (!phdr || !pseudo_header)
return -1;
host_id_current = host_id == ERF_META_HOST_ID_IMPLICIT ? erf_priv->implicit_host_id : host_id;
has_more = pseudo_header->erf.phdr.type & 0x80;
while (has_more && (i < MAX_ERF_EHDR)) {
hdr = pseudo_header->erf.ehdr_list[i].ehdr;
type = (guint8) (hdr >> 56);
switch (type & 0x7f) {
case ERF_EXT_HDR_TYPE_HOST_ID:
host_id_current = hdr & ERF_EHDR_HOST_ID_MASK;
break;
case ERF_EXT_HDR_TYPE_ANCHOR_ID:
{
anchor_id_current = hdr & ERF_EHDR_ANCHOR_ID_MASK;
if (!(ERF_ANCHOR_ID_IS_DEFINITION(hdr))) {
struct erf_anchor_mapping* lookup_result;
lookup_result = erf_find_anchor_mapping(erf_priv, host_id_current, anchor_id_current);
if (lookup_result) {
if (lookup_result->gen_time > comment_gen_time) {
if (lookup_result->comment && lookup_result->comment[0] != '\0') {
comment = lookup_result->comment;
}
comment_gen_time = lookup_result->gen_time;
}
}
}
else {
if (anchor_mappings_to_update && (pseudo_header->erf.phdr.type & 0x7f) == ERF_TYPE_META) {
struct erf_anchor_mapping *mapping_ptr =
(struct erf_anchor_mapping*)g_malloc0(sizeof(struct erf_anchor_mapping));
mapping_ptr->host_id = host_id_current;
mapping_ptr->anchor_id = anchor_id_current;
g_ptr_array_add(anchor_mappings_to_update, mapping_ptr);
}
}
break;
}
}
has_more = type & 0x80;
i += 1;
}
if (comment) {
phdr->opt_comment = g_strdup(comment);
phdr->presence_flags |= WTAP_HAS_COMMENTS;
} else {
phdr->opt_comment = NULL;
}
return 0;
}
static int erf_update_implicit_host_id(erf_t *erf_priv, wtap *wth, guint64 implicit_host_id)
{
GHashTableIter iter;
gpointer iter_value;
GList* implicit_list = NULL;
GList* item = NULL;
wtap_block_t int_data;
struct erf_if_mapping* if_map = NULL;
struct erf_if_mapping* if_map_other = NULL;
struct erf_if_info* if_info = NULL;
struct erf_anchor_mapping* anchor_mapping = NULL;
struct erf_anchor_mapping* anchor_mapping_other = NULL;
gchar *oldstr = NULL;
char portstr_buf[16];
int i;
if (!erf_priv)
return -1;
erf_priv->implicit_host_id = implicit_host_id;
g_hash_table_iter_init(&iter, erf_priv->if_map);
while (g_hash_table_iter_next(&iter, &iter_value, NULL)) {
if_map = (struct erf_if_mapping*) iter_value;
if (if_map->host_id == ERF_META_HOST_ID_IMPLICIT) {
if_map_other = erf_find_interface_mapping(erf_priv, implicit_host_id, if_map->source_id);
if (!if_map_other) {
g_hash_table_iter_steal(&iter);
implicit_list = g_list_prepend(implicit_list, if_map);
} else {
for (i = 0; i < 4; i++) {
if_info = &if_map->interfaces[i];
if (if_info->if_index >= 0) {
int_data = g_array_index(wth->interface_data, wtap_block_t, if_info->if_index);
g_snprintf(portstr_buf, sizeof(portstr_buf), "Port %c", 'A'+i);
oldstr = if_info->name;
if_info->name = g_strconcat(oldstr ? oldstr : portstr_buf, " [unmatched implicit]", NULL);
g_free(oldstr);
oldstr = if_info->descr;
if_info->descr = g_strconcat(oldstr ? oldstr : portstr_buf, " [unmatched implicit]", NULL);
g_free(oldstr);
erf_set_interface_descr(int_data, OPT_IDB_NAME, implicit_host_id, if_map->source_id, (guint8) i, if_info->name);
erf_set_interface_descr(int_data, OPT_IDB_DESCR, implicit_host_id, if_map->source_id, (guint8) i, if_info->descr);
}
}
}
}
}
if (implicit_list) {
item = implicit_list;
do {
if_map = (struct erf_if_mapping*) item->data;
for (i = 0; i < 4; i++) {
if_info = &if_map->interfaces[i];
if (if_info->if_index >= 0) {
int_data = g_array_index(wth->interface_data, wtap_block_t, if_info->if_index);
erf_set_interface_descr(int_data, OPT_IDB_NAME, implicit_host_id, if_map->source_id, (guint8) i, if_info->name);
erf_set_interface_descr(int_data, OPT_IDB_DESCR, implicit_host_id, if_map->source_id, (guint8) i, if_info->descr);
}
}
if_map->host_id = implicit_host_id;
g_hash_table_replace(erf_priv->if_map, if_map, if_map);
} while ((item = g_list_next(item)));
g_list_free(implicit_list);
implicit_list = NULL;
}
g_hash_table_iter_init(&iter, erf_priv->anchor_map);
while (g_hash_table_iter_next(&iter, &iter_value, NULL)) {
anchor_mapping = (struct erf_anchor_mapping*) iter_value;
if (anchor_mapping->host_id == ERF_META_HOST_ID_IMPLICIT) {
anchor_mapping_other = erf_find_anchor_mapping(erf_priv, implicit_host_id,
anchor_mapping->anchor_id);
if (anchor_mapping_other && anchor_mapping_other->gen_time >= anchor_mapping->gen_time) {
g_hash_table_iter_remove(&iter);
} else {
g_hash_table_iter_steal(&iter);
implicit_list = g_list_prepend(implicit_list, anchor_mapping);
}
}
}
if (implicit_list) {
item = implicit_list;
do {
anchor_mapping = (struct erf_anchor_mapping*) item->data;
anchor_mapping->host_id = implicit_host_id;
g_hash_table_replace(erf_priv->anchor_map, anchor_mapping, anchor_mapping);
} while ((item = g_list_next(item)));
g_list_free(implicit_list);
implicit_list = NULL;
}
return 0;
}
int erf_populate_interface(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header, guint64 host_id, guint8 source_id, guint8 if_num)
{
wtap_block_t int_data;
wtapng_if_descr_mandatory_t* int_data_mand;
struct erf_if_mapping* if_map = NULL;
if (!wth || !pseudo_header || !erf_priv || if_num > 3)
return -1;
if (host_id == ERF_META_HOST_ID_IMPLICIT) {
host_id = erf_priv->implicit_host_id;
} else if ((pseudo_header->erf.phdr.type & 0x7f) == ERF_TYPE_META) {
if (erf_priv->implicit_host_id == ERF_META_HOST_ID_IMPLICIT && source_id > 0) {
erf_update_implicit_host_id(erf_priv, wth, host_id);
}
}
if_map = erf_find_interface_mapping(erf_priv, host_id, source_id);
if (!if_map) {
if_map = erf_if_mapping_create(host_id, source_id);
g_hash_table_replace(erf_priv->if_map, if_map, if_map);
}
if (if_map->interfaces[if_num].if_index >= 0) {
return if_map->interfaces[if_num].if_index;
}
int_data = wtap_block_create(WTAP_BLOCK_IF_DESCR);
int_data_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(int_data);
int_data_mand->wtap_encap = WTAP_ENCAP_ERF;
int_data_mand->time_units_per_second = 1000000000;
int_data_mand->snap_len = 65535;
wtap_block_add_uint8_option(int_data, OPT_IDB_TSRESOL, 0x09);
int_data_mand->num_stat_entries = 0;
int_data_mand->interface_statistics = NULL;
erf_set_interface_descr(int_data, OPT_IDB_NAME, host_id, source_id, if_num, NULL);
erf_set_interface_descr(int_data, OPT_IDB_DESCR, host_id, source_id, if_num, NULL);
if_map->interfaces[if_num].if_index = (int) wth->interface_data->len;
g_array_append_val(wth->interface_data, int_data);
return if_map->interfaces[if_num].if_index;
}
static guint32 erf_meta_read_tag(struct erf_meta_tag* tag, guint8 *tag_ptr, guint32 remaining_len)
{
guint16 tagtype;
guint16 taglength;
guint32 tagtotallength;
if (!tag_ptr || !tag || remaining_len < ERF_META_TAG_HEADERLEN)
return 0;
tagtype = pntoh16(&tag_ptr[0]);
taglength = pntoh16(&tag_ptr[2]);
tagtotallength = ERF_META_TAG_TOTAL_ALIGNED_LENGTH(taglength);
if (remaining_len < tagtotallength) {
return 0;
}
tag->type = tagtype;
tag->length = taglength;
tag->value = &tag_ptr[4];
return tagtotallength;
}
static int populate_capture_host_info(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header _U_, struct erf_meta_read_state *state)
{
struct erf_meta_tag tag = {0, 0, NULL};
wtap_block_t shb_hdr;
char* tmp;
gchar* app_name = NULL;
gchar* app_version = NULL;
gchar* model = NULL;
gchar* descr = NULL;
gchar* cpu = NULL;
gchar* modelcpu = NULL;
guint32 tagtotallength;
if (!wth || !state || !wth->shb_hdrs || (wth->shb_hdrs->len == 0))
return -1;
shb_hdr = g_array_index(wth->shb_hdrs, wtap_block_t, 0);
while ((tagtotallength = erf_meta_read_tag(&tag, state->tag_ptr, state->remaining_len)) && !ERF_META_IS_SECTION(tag.type)) {
switch (state->sectiontype) {
case ERF_META_SECTION_CAPTURE:
{
if (erf_priv->capture_gentime > state->gen_time) {
return 0;
}
switch (tag.type) {
case ERF_META_TAG_comment:
{
gchar *existing_comment = NULL;
if (wtap_block_get_nth_string_option_value(shb_hdr, OPT_COMMENT, 0, &existing_comment) == WTAP_OPTTYPE_SUCCESS) {
wtap_block_set_nth_string_option_value(shb_hdr, OPT_COMMENT, 0, tag.value, tag.length);
} else {
wtap_block_add_string_option(shb_hdr, OPT_COMMENT, tag.value, tag.length);
}
break;
}
}
}
case ERF_META_SECTION_HOST:
{
if (erf_priv->host_gentime > state->gen_time) {
return 0;
}
switch (tag.type) {
case ERF_META_TAG_model:
g_free(model);
model = g_strndup((gchar*) tag.value, tag.length);
break;
case ERF_META_TAG_cpu:
g_free(cpu);
cpu = g_strndup((gchar*) tag.value, tag.length);
break;
case ERF_META_TAG_descr:
g_free(descr);
descr = g_strndup((gchar*) tag.value, tag.length);
break;
case ERF_META_TAG_os:
wtap_block_set_string_option_value(shb_hdr, OPT_SHB_OS, tag.value, tag.length);
break;
case ERF_META_TAG_app_name:
g_free(app_name);
app_name = g_strndup((gchar*) tag.value, tag.length);
break;
case ERF_META_TAG_app_version:
g_free(app_version);
app_version = g_strndup((gchar*) tag.value, tag.length);
break;
case ERF_META_TAG_filter:
g_free(state->if_map->capture_filter_str);
state->if_map->capture_filter_str = g_strndup((gchar*) tag.value, tag.length);
break;
default:
break;
}
}
break;
}
state->tag_ptr += tagtotallength;
state->remaining_len -= tagtotallength;
}
if (app_name) {
tmp = g_strjoin(" ", app_name, app_version, NULL);
wtap_block_set_string_option_value(shb_hdr, OPT_SHB_USERAPPL, tmp, strlen(tmp));
g_free(tmp);
g_free(app_name);
g_free(app_version);
app_name = NULL;
app_version = NULL;
}
if (model || cpu) {
if (model && cpu) {
modelcpu = g_strconcat(model, "; ", cpu, NULL);
} else if (cpu) {
modelcpu = cpu;
cpu = NULL;
} else {
modelcpu = model;
model = NULL;
}
}
if (state->sectiontype == ERF_META_SECTION_HOST && descr) {
if (modelcpu) {
wtap_block_set_string_option_value_format(shb_hdr, OPT_SHB_HARDWARE, "%s (%s)", descr, modelcpu);
} else {
wtap_block_set_string_option_value(shb_hdr, OPT_SHB_HARDWARE, descr, strlen(descr));
}
} else if (modelcpu) {
wtap_block_set_string_option_value(shb_hdr, OPT_SHB_HARDWARE, modelcpu, strlen(modelcpu));
}
g_free(modelcpu);
g_free(model);
g_free(descr);
g_free(cpu);
if (state->sectiontype == ERF_META_SECTION_CAPTURE) {
erf_priv->capture_gentime = state->gen_time;
} else {
erf_priv->host_gentime = state->gen_time;
}
return 1;
}
static int populate_module_info(erf_t *erf_priv _U_, wtap *wth, union wtap_pseudo_header *pseudo_header _U_, struct erf_meta_read_state *state)
{
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
if (!wth || !state)
return -1;
if (state->if_map->module_gentime > state->gen_time) {
return 0;
}
while ((tagtotallength = erf_meta_read_tag(&tag, state->tag_ptr, state->remaining_len)) && !ERF_META_IS_SECTION(tag.type)) {
switch (tag.type) {
case ERF_META_TAG_fcs_len:
if (tag.length >= 4) {
state->if_map->module_fcs_len = (gint8) pntoh32(tag.value);
}
break;
case ERF_META_TAG_snaplen:
if (tag.length >= 4) {
state->if_map->module_snaplen = pntoh32(tag.value);
}
break;
case ERF_META_TAG_filter:
g_free(state->if_map->module_filter_str);
state->if_map->module_filter_str = g_strndup((gchar*) tag.value, tag.length);
break;
}
state->tag_ptr += tagtotallength;
state->remaining_len -= tagtotallength;
}
state->if_map->module_gentime = state->gen_time;
return 1;
}
static int populate_interface_info(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header, struct erf_meta_read_state *state)
{
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
int interface_index = -1;
wtap_block_t int_data = NULL;
wtapng_if_descr_mandatory_t* int_data_mand = NULL;
wtapng_if_descr_filter_t if_filter;
guint32 if_num = 0;
struct erf_if_info* if_info = NULL;
memset(&if_filter, 0, sizeof(if_filter));
if (!wth || !state || !pseudo_header || !state->if_map)
return -1;
if_num = state->sectionid - 1;
if (if_num < 4) {
if_info = &state->if_map->interfaces[if_num];
interface_index = if_info->if_index;
if (interface_index == -1) {
guint8 *tag_ptr_tmp = state->tag_ptr;
guint32 remaining_len_tmp = state->remaining_len;
while ((tagtotallength = erf_meta_read_tag(&tag, tag_ptr_tmp, remaining_len_tmp)) && !ERF_META_IS_SECTION(tag.type)) {
if (tag.type == ERF_META_TAG_if_port_type) {
if (tag.length >= 4 && pntoh32(tag.value) == 2) {
if_info->if_index = -2;
interface_index = -2;
}
} else if (tag.type == ERF_META_TAG_stream_num) {
if (tag.length >= 4) {
if_info->stream_num = (gint32) pntoh32(tag.value);
}
}
tag_ptr_tmp += tagtotallength;
remaining_len_tmp -= tagtotallength;
}
if (interface_index == -1) {
interface_index = erf_populate_interface(erf_priv, wth, pseudo_header, state->if_map->host_id, state->if_map->source_id, (guint8) if_num);
}
}
if (interface_index >= 0) {
int_data = g_array_index(wth->interface_data, wtap_block_t, interface_index);
int_data_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(int_data);
} else if (interface_index == -2) {
return 0;
} else {
return -1;
}
}
if (!int_data)
return 0;
if (state->if_map->interface_gentime > state->gen_time && state->if_map->interface_metadata & (1 << if_num))
return 0;
while ((tagtotallength = erf_meta_read_tag(&tag, state->tag_ptr, state->remaining_len)) && !ERF_META_IS_SECTION(tag.type)) {
switch (tag.type) {
case ERF_META_TAG_name:
if (!if_info->name) {
if_info->name = g_strndup((gchar*) tag.value, tag.length);
erf_set_interface_descr(int_data, OPT_IDB_NAME, state->if_map->host_id, state->if_map->source_id, (guint8) if_num, if_info->name);
if (!if_info->descr) {
erf_set_interface_descr(int_data, OPT_IDB_DESCR, state->if_map->host_id, state->if_map->source_id, (guint8) if_num, if_info->name);
}
}
break;
case ERF_META_TAG_descr:
if (!if_info->descr) {
if_info->descr = g_strndup((gchar*) tag.value, tag.length);
erf_set_interface_descr(int_data, OPT_IDB_DESCR, state->if_map->host_id, state->if_map->source_id, (guint8) if_num, if_info->descr);
if (!if_info->name) {
erf_set_interface_descr(int_data, OPT_IDB_NAME, state->if_map->host_id, state->if_map->source_id, (guint8) if_num, if_info->descr);
}
}
break;
case ERF_META_TAG_if_speed:
if (tag.length >= 8)
wtap_block_add_uint64_option(int_data, OPT_IDB_SPEED, pntoh64(tag.value));
break;
case ERF_META_TAG_if_num:
break;
case ERF_META_TAG_fcs_len:
if (tag.length >= 4) {
wtap_block_add_uint8_option(int_data, OPT_IDB_FCSLEN, (guint8) pntoh32(tag.value));
if_info->set_flags.fcs_len = 1;
}
break;
case ERF_META_TAG_snaplen:
if (tag.length >= 4) {
int_data_mand->snap_len = pntoh32(tag.value);
if_info->set_flags.snaplen = 1;
}
break;
case ERF_META_TAG_comment:
wtap_block_add_string_option(int_data, OPT_COMMENT, tag.value, tag.length);
break;
case ERF_META_TAG_filter:
if_filter.if_filter_str = g_strndup((gchar*) tag.value, tag.length);
wtap_block_add_custom_option(int_data, OPT_IDB_FILTER, &if_filter, sizeof if_filter);
g_free(if_filter.if_filter_str);
if_info->set_flags.filter = 1;
break;
default:
break;
}
state->tag_ptr += tagtotallength;
state->remaining_len -= tagtotallength;
}
if (!if_info->set_flags.filter) {
if (state->if_map->module_filter_str) {
if_filter.if_filter_str = state->if_map->module_filter_str;
wtap_block_add_custom_option(int_data, OPT_IDB_FILTER, &if_filter, sizeof if_filter);
} else if (state->if_map->capture_filter_str) {
if_filter.if_filter_str = state->if_map->capture_filter_str;
wtap_block_add_custom_option(int_data, OPT_IDB_FILTER, &if_filter, sizeof if_filter);
}
}
if (state->if_map->module_fcs_len != -1 && !if_info->set_flags.fcs_len) {
wtap_block_add_uint8_option(int_data, OPT_IDB_FCSLEN, (guint8) state->if_map->module_fcs_len);
if_info->set_flags.fcs_len = 1;
}
if (state->if_map->module_snaplen != (guint32) -1 && !if_info->set_flags.snaplen) {
int_data_mand->snap_len = pntoh32(tag.value);
if_info->set_flags.snaplen = 1;
}
state->interface_metadata |= 1 << if_num;
return 1;
}
static int populate_stream_info(erf_t *erf_priv _U_, wtap *wth, union wtap_pseudo_header *pseudo_header, struct erf_meta_read_state *state)
{
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
int interface_index = -1;
wtap_block_t int_data = NULL;
wtapng_if_descr_mandatory_t* int_data_mand = NULL;
wtapng_if_descr_filter_t if_filter;
guint32 if_num = 0;
gint32 stream_num = -1;
guint8 *tag_ptr_tmp;
guint32 remaining_len_tmp;
struct erf_if_info* if_info = NULL;
memset(&if_filter, 0, sizeof(if_filter));
if (!wth || !pseudo_header || !state || !state->if_map)
return -1;
tag_ptr_tmp = state->tag_ptr;
remaining_len_tmp = state->remaining_len;
if (state->sectionid > 0 && state->sectionid != 0x7fff) {
stream_num = state->sectionid - 1;
} else {
while ((tagtotallength = erf_meta_read_tag(&tag, tag_ptr_tmp, remaining_len_tmp)) && !ERF_META_IS_SECTION(tag.type)) {
if (tag.type == ERF_META_TAG_stream_num) {
if (tag.length >= 4) {
stream_num = (gint32) pntoh32(tag.value);
}
}
tag_ptr_tmp += tagtotallength;
remaining_len_tmp -= tagtotallength;
}
}
for (if_num = 0; if_num < 4; if_num++) {
tag_ptr_tmp = state->tag_ptr;
remaining_len_tmp = state->remaining_len;
if_info = &state->if_map->interfaces[if_num];
if (state->if_map->interface_metadata & (1 << if_num)
|| !(state->interface_metadata & (1 << if_num))) {
continue;
}
if (if_info->stream_num != -1
&& if_info->stream_num != stream_num) {
continue;
}
interface_index = if_info->if_index;
if (interface_index >= 0) {
int_data = g_array_index(wth->interface_data, wtap_block_t, interface_index);
int_data_mand = (wtapng_if_descr_mandatory_t*)wtap_block_get_mandatory_data(int_data);
}
if (!int_data) {
continue;
}
while ((tagtotallength = erf_meta_read_tag(&tag, tag_ptr_tmp, remaining_len_tmp)) && !ERF_META_IS_SECTION(tag.type)) {
switch (tag.type) {
case ERF_META_TAG_fcs_len:
if (tag.length >= 4) {
gint8 fcs_len = (gint8) pntoh32(tag.value);
guint8 old_fcs_len = 0;
switch (wtap_block_get_uint8_option_value(int_data, OPT_IDB_FCSLEN, &old_fcs_len)) {
case WTAP_OPTTYPE_SUCCESS:
if (fcs_len > old_fcs_len || !if_info->set_flags.fcs_len) {
wtap_block_set_uint8_option_value(int_data, OPT_IDB_FCSLEN, (guint8) pntoh32(tag.value));
if_info->set_flags.fcs_len = 1;
}
break;
case WTAP_OPTTYPE_NOT_FOUND:
wtap_block_add_uint8_option(int_data, OPT_IDB_FCSLEN, (guint8) pntoh32(tag.value));
if_info->set_flags.fcs_len = 1;
break;
default:
break;
}
}
break;
case ERF_META_TAG_snaplen:
if (tag.length >= 4) {
guint32 snaplen = pntoh32(tag.value);
if (snaplen > int_data_mand->snap_len || !if_info->set_flags.snaplen) {
int_data_mand->snap_len = pntoh32(tag.value);
if_info->set_flags.snaplen = 1;
}
}
break;
case ERF_META_TAG_filter:
if (!if_info->set_flags.filter) {
if_filter.if_filter_str = g_strndup((gchar*) tag.value, tag.length);
wtap_block_add_custom_option(int_data, OPT_IDB_FILTER, &if_filter, sizeof if_filter);
g_free(if_filter.if_filter_str);
if_info->set_flags.filter = 1;
}
break;
default:
break;
}
tag_ptr_tmp += tagtotallength;
remaining_len_tmp -= tagtotallength;
}
}
state->tag_ptr = tag_ptr_tmp;
state->remaining_len = remaining_len_tmp;
return 1;
}
static int populate_anchor_info(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header, struct erf_meta_read_state *state, GPtrArray *anchor_mappings_to_update) {
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
gchar *comment_ptr = NULL;
guint i = 0;
if (!wth || !state || !pseudo_header)
return -1;
if (!anchor_mappings_to_update || anchor_mappings_to_update->len == 0)
return 0;
while ((tagtotallength = erf_meta_read_tag(&tag, state->tag_ptr, state->remaining_len)) && !ERF_META_IS_SECTION(tag.type)) {
switch(tag.type) {
case ERF_META_TAG_comment:
if(!comment_ptr) {
comment_ptr = g_strndup((gchar*)tag.value, tag.length);
}
break;
default:
break;
}
state->tag_ptr += tagtotallength;
state->remaining_len -= tagtotallength;
}
if(comment_ptr) {
for(i = 0; i < anchor_mappings_to_update->len; i++) {
struct erf_anchor_mapping *mapping;
struct erf_anchor_mapping *lookup_result;
mapping = (struct erf_anchor_mapping*)g_ptr_array_index(anchor_mappings_to_update, i);
lookup_result = (struct erf_anchor_mapping*)g_hash_table_lookup(erf_priv->anchor_map, mapping);
if(lookup_result) {
if(lookup_result->gen_time < state->gen_time) {
lookup_result->gen_time = state->gen_time;
g_free(lookup_result->comment);
lookup_result->comment = g_strdup(comment_ptr);
}
}
else {
struct erf_anchor_mapping *new_mapping;
new_mapping = (struct erf_anchor_mapping *)g_malloc0(sizeof(struct erf_anchor_mapping));
new_mapping->anchor_id = mapping->anchor_id;
new_mapping->host_id = mapping->host_id;
new_mapping->gen_time = state->gen_time;
new_mapping->comment = g_strdup(comment_ptr);
g_hash_table_replace(erf_priv->anchor_map, new_mapping, new_mapping);
}
}
}
g_free(comment_ptr);
return 1;
}
static int populate_summary_info(erf_t *erf_priv, wtap *wth, union wtap_pseudo_header *pseudo_header, guint32 packet_size, GPtrArray *anchor_mappings_to_update)
{
struct erf_meta_read_state state;
struct erf_meta_read_state *state_post = NULL;
guint64 host_id;
guint8 source_id;
GList *post_list = NULL;
GList *item = NULL;
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
if (!erf_priv || !wth || !pseudo_header)
return -1;
memset(&state, 0, sizeof(struct erf_meta_read_state));
erf_get_source_from_header(pseudo_header, &host_id, &source_id);
if (host_id == 0) {
host_id = erf_priv->implicit_host_id;
}
state.if_map = erf_find_interface_mapping(erf_priv, host_id, source_id);
if (!state.if_map) {
state.if_map = erf_if_mapping_create(host_id, source_id);
g_hash_table_replace(erf_priv->if_map, state.if_map, state.if_map);
}
state.tag_ptr = wth->frame_buffer->data;
state.remaining_len = packet_size;
while ((tagtotallength = erf_meta_read_tag(&tag, state.tag_ptr, state.remaining_len))) {
if (!ERF_META_IS_SECTION(tag.type)) {
if(state.gen_time == 0U
&& tag.type == ERF_META_TAG_gen_time
) {
memcpy(&state.gen_time, tag.value, sizeof(state.gen_time));
if ((state.if_map->interface_metadata & 0x03)
&& state.gen_time < erf_priv->host_gentime && state.gen_time < erf_priv->capture_gentime
&& (!anchor_mappings_to_update || !anchor_mappings_to_update->len)) {
return 0;
}
}
state.tag_ptr += tagtotallength;
state.remaining_len -= tagtotallength;
continue;
}
if (tag.type != state.sectiontype) {
if ((tag.type == ERF_META_SECTION_STREAM && state.sectiontype == ERF_META_SECTION_INTERFACE) ||
(tag.type == ERF_META_SECTION_INTERFACE && state.sectiontype == ERF_META_SECTION_STREAM)) {
} else {
state.parentsectiontype = state.sectiontype;
state.parentsectionid = state.sectionid;
}
}
state.sectiontype = tag.type;
if (tag.length >= 4) {
state.sectionid = pntoh16(tag.value);
} else {
state.sectionid = 0;
}
state.tag_ptr += tagtotallength;
state.remaining_len -= tagtotallength;
if ((tagtotallength = erf_meta_read_tag(&tag, state.tag_ptr, state.remaining_len))) {
if (tag.type == ERF_META_TAG_parent_section && tag.length >= 4) {
state.parentsectiontype = pntoh16(tag.value);
state.parentsectionid = pntoh16(&tag.value[2]);
}
}
if (ERF_META_IS_SECTION(tag.type)) {
continue;
}
if (state.sectionid & 0x8000) {
if(state.sectiontype & (ERF_META_SECTION_INFO)) {
populate_anchor_info(erf_priv, wth, pseudo_header, &state, anchor_mappings_to_update);
}
continue;
}
switch (state.sectiontype) {
case ERF_META_SECTION_CAPTURE:
case ERF_META_SECTION_HOST:
populate_capture_host_info(erf_priv, wth, pseudo_header, &state);
break;
case ERF_META_SECTION_MODULE:
populate_module_info(erf_priv, wth, pseudo_header, &state);
break;
case ERF_META_SECTION_INTERFACE:
populate_interface_info(erf_priv, wth, pseudo_header, &state);
break;
case ERF_META_SECTION_STREAM:
post_list = g_list_append(post_list, g_memdup(&state, sizeof(struct erf_meta_read_state)));
break;
case ERF_META_SECTION_SOURCE:
case ERF_META_SECTION_DNS:
default:
break;
}
}
if (post_list) {
item = post_list;
do {
state_post = (struct erf_meta_read_state*) item->data;
switch (state_post->sectiontype) {
case ERF_META_SECTION_STREAM:
populate_stream_info(erf_priv, wth, pseudo_header, state_post);
break;
}
} while ((item = g_list_next(item)));
g_list_foreach(post_list, erf_free_data, NULL);
g_list_free(post_list);
}
if (state.interface_metadata) {
state.if_map->interface_metadata |= state.interface_metadata;
state.if_map->interface_gentime = state.gen_time;
}
return 0;
}
static gboolean get_user_comment_string(wtap_dumper *wdh, gchar** user_comment_ptr) {
wtap_block_t wtap_block;
gboolean ret;
wtap_block = NULL;
if(wdh->shb_hdrs && (wdh->shb_hdrs->len > 0)) {
wtap_block = g_array_index(wdh->shb_hdrs, wtap_block_t, 0);
}
if(wtap_block != NULL) {
ret = wtap_block_get_nth_string_option_value(wtap_block, OPT_COMMENT, 0, user_comment_ptr);
if(ret) {
return FALSE;
}
}
return TRUE;
}
static gboolean erf_dump_priv_compare_capture_comment(wtap_dumper *wdh _U_, erf_dump_t *dump_priv, const union wtap_pseudo_header *pseudo_header, const guint8 *pd){
struct erf_meta_read_state state;
struct erf_meta_tag tag = {0, 0, NULL};
guint32 tagtotallength;
gboolean found_capture_section = FALSE;
gboolean found_normal_section = FALSE;
gchar* comment_ptr = NULL;
memset(&state, 0, sizeof(struct erf_meta_read_state));
state.remaining_len = pseudo_header->erf.phdr.wlen;
memcpy(&(state.tag_ptr), &pd, sizeof(pd));
while((tagtotallength = erf_meta_read_tag(&tag, state.tag_ptr, state.remaining_len))) {
if (ERF_META_IS_SECTION(tag.type)) {
state.sectiontype = tag.type;
if (tag.length >= 4) {
state.sectionid = pntoh16(tag.value);
} else {
state.sectionid = 0;
}
if (!(state.sectionid & 0x8000)) {
found_normal_section = TRUE;
if(tag.type == ERF_META_SECTION_CAPTURE) {
found_capture_section = TRUE;
}
}
} else {
if (state.sectiontype == ERF_META_SECTION_CAPTURE && !(state.sectionid & 0x8000)) {
if (tag.type == ERF_META_TAG_comment) {
if(!comment_ptr) {
comment_ptr = g_strndup((char*)tag.value, tag.length);
}
break;
}
}
}
state.tag_ptr += tagtotallength;
state.remaining_len -= tagtotallength;
}
if(found_capture_section && (comment_ptr || dump_priv->user_comment_ptr)) {
if(g_strcmp0(comment_ptr, dump_priv->user_comment_ptr)
&& !(dump_priv->user_comment_ptr == NULL && comment_ptr && comment_ptr[0] == '\0')) {
dump_priv->write_next_extra_meta = TRUE;
g_free(comment_ptr);
return TRUE;
} else {
dump_priv->write_next_extra_meta = FALSE;
}
}
g_free(comment_ptr);
return found_normal_section;
}
static void erf_close(wtap *wth)
{
erf_t* erf_priv = (erf_t*)wth->priv;
erf_priv_free(erf_priv);
wth->priv = NULL;
}
