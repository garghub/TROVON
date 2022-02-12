static void iwl_free_fw_desc(struct iwl_drv *drv, struct fw_desc *desc)
{
if (desc->v_addr)
dma_free_coherent(drv->trans->dev, desc->len,
desc->v_addr, desc->p_addr);
desc->v_addr = NULL;
desc->len = 0;
}
static void iwl_free_fw_img(struct iwl_drv *drv, struct fw_img *img)
{
int i;
for (i = 0; i < IWL_UCODE_SECTION_MAX; i++)
iwl_free_fw_desc(drv, &img->sec[i]);
}
static void iwl_dealloc_ucode(struct iwl_drv *drv)
{
int i;
for (i = 0; i < IWL_UCODE_TYPE_MAX; i++)
iwl_free_fw_img(drv, drv->fw.img + i);
}
static int iwl_alloc_fw_desc(struct iwl_drv *drv, struct fw_desc *desc,
struct fw_sec *sec)
{
if (!sec || !sec->size) {
desc->v_addr = NULL;
return -EINVAL;
}
desc->v_addr = dma_alloc_coherent(drv->trans->dev, sec->size,
&desc->p_addr, GFP_KERNEL);
if (!desc->v_addr)
return -ENOMEM;
desc->len = sec->size;
desc->offset = sec->offset;
memcpy(desc->v_addr, sec->data, sec->size);
return 0;
}
static int iwl_request_firmware(struct iwl_drv *drv, bool first)
{
const char *name_pre = drv->cfg->fw_name_pre;
char tag[8];
if (first) {
#ifdef CONFIG_IWLWIFI_DEBUG_EXPERIMENTAL_UCODE
drv->fw_index = UCODE_EXPERIMENTAL_INDEX;
strcpy(tag, UCODE_EXPERIMENTAL_TAG);
} else if (drv->fw_index == UCODE_EXPERIMENTAL_INDEX) {
#endif
drv->fw_index = drv->cfg->ucode_api_max;
sprintf(tag, "%d", drv->fw_index);
} else {
drv->fw_index--;
sprintf(tag, "%d", drv->fw_index);
}
if (drv->fw_index < drv->cfg->ucode_api_min) {
IWL_ERR(drv, "no suitable firmware found!\n");
return -ENOENT;
}
sprintf(drv->firmware_name, "%s%s%s", name_pre, tag, ".ucode");
IWL_DEBUG_INFO(drv, "attempting to load firmware %s'%s'\n",
(drv->fw_index == UCODE_EXPERIMENTAL_INDEX)
? "EXPERIMENTAL " : "",
drv->firmware_name);
return request_firmware_nowait(THIS_MODULE, 1, drv->firmware_name,
drv->trans->dev,
GFP_KERNEL, drv, iwl_ucode_callback);
}
static struct fw_sec *get_sec(struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type,
int sec)
{
return &pieces->img[type].sec[sec];
}
static void set_sec_data(struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type,
int sec,
const void *data)
{
pieces->img[type].sec[sec].data = data;
}
static void set_sec_size(struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type,
int sec,
size_t size)
{
pieces->img[type].sec[sec].size = size;
}
static size_t get_sec_size(struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type,
int sec)
{
return pieces->img[type].sec[sec].size;
}
static void set_sec_offset(struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type,
int sec,
u32 offset)
{
pieces->img[type].sec[sec].offset = offset;
}
static int iwl_store_ucode_sec(struct iwl_firmware_pieces *pieces,
const void *data, enum iwl_ucode_type type,
int size)
{
struct fw_img_parsing *img;
struct fw_sec *sec;
struct fw_sec_parsing *sec_parse;
if (WARN_ON(!pieces || !data || type >= IWL_UCODE_TYPE_MAX))
return -1;
sec_parse = (struct fw_sec_parsing *)data;
img = &pieces->img[type];
sec = &img->sec[img->sec_counter];
sec->offset = le32_to_cpu(sec_parse->offset);
sec->data = sec_parse->data;
sec->size = size - sizeof(sec_parse->offset);
++img->sec_counter;
return 0;
}
static int iwl_set_default_calib(struct iwl_drv *drv, const u8 *data)
{
struct iwl_tlv_calib_data *def_calib =
(struct iwl_tlv_calib_data *)data;
u32 ucode_type = le32_to_cpu(def_calib->ucode_type);
if (ucode_type >= IWL_UCODE_TYPE_MAX) {
IWL_ERR(drv, "Wrong ucode_type %u for default calibration.\n",
ucode_type);
return -EINVAL;
}
drv->fw.default_calib[ucode_type] = le64_to_cpu(def_calib->calib);
return 0;
}
static int iwl_parse_v1_v2_firmware(struct iwl_drv *drv,
const struct firmware *ucode_raw,
struct iwl_firmware_pieces *pieces)
{
struct iwl_ucode_header *ucode = (void *)ucode_raw->data;
u32 api_ver, hdr_size, build;
char buildstr[25];
const u8 *src;
drv->fw.ucode_ver = le32_to_cpu(ucode->ver);
api_ver = IWL_UCODE_API(drv->fw.ucode_ver);
switch (api_ver) {
default:
hdr_size = 28;
if (ucode_raw->size < hdr_size) {
IWL_ERR(drv, "File size too small!\n");
return -EINVAL;
}
build = le32_to_cpu(ucode->u.v2.build);
set_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST,
le32_to_cpu(ucode->u.v2.inst_size));
set_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA,
le32_to_cpu(ucode->u.v2.data_size));
set_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST,
le32_to_cpu(ucode->u.v2.init_size));
set_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA,
le32_to_cpu(ucode->u.v2.init_data_size));
src = ucode->u.v2.data;
break;
case 0:
case 1:
case 2:
hdr_size = 24;
if (ucode_raw->size < hdr_size) {
IWL_ERR(drv, "File size too small!\n");
return -EINVAL;
}
build = 0;
set_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST,
le32_to_cpu(ucode->u.v1.inst_size));
set_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA,
le32_to_cpu(ucode->u.v1.data_size));
set_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST,
le32_to_cpu(ucode->u.v1.init_size));
set_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA,
le32_to_cpu(ucode->u.v1.init_data_size));
src = ucode->u.v1.data;
break;
}
if (build)
sprintf(buildstr, " build %u%s", build,
(drv->fw_index == UCODE_EXPERIMENTAL_INDEX)
? " (EXP)" : "");
else
buildstr[0] = '\0';
snprintf(drv->fw.fw_version,
sizeof(drv->fw.fw_version),
"%u.%u.%u.%u%s",
IWL_UCODE_MAJOR(drv->fw.ucode_ver),
IWL_UCODE_MINOR(drv->fw.ucode_ver),
IWL_UCODE_API(drv->fw.ucode_ver),
IWL_UCODE_SERIAL(drv->fw.ucode_ver),
buildstr);
if (ucode_raw->size != hdr_size +
get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST) +
get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA) +
get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST) +
get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA)) {
IWL_ERR(drv,
"uCode file size %d does not match expected size\n",
(int)ucode_raw->size);
return -EINVAL;
}
set_sec_data(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST, src);
src += get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST);
set_sec_offset(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST,
IWLAGN_RTC_INST_LOWER_BOUND);
set_sec_data(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA, src);
src += get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA);
set_sec_offset(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA,
IWLAGN_RTC_DATA_LOWER_BOUND);
set_sec_data(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST, src);
src += get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST);
set_sec_offset(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST,
IWLAGN_RTC_INST_LOWER_BOUND);
set_sec_data(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA, src);
src += get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA);
set_sec_offset(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA,
IWLAGN_RTC_DATA_LOWER_BOUND);
return 0;
}
static int iwl_parse_tlv_firmware(struct iwl_drv *drv,
const struct firmware *ucode_raw,
struct iwl_firmware_pieces *pieces,
struct iwl_ucode_capabilities *capa)
{
struct iwl_tlv_ucode_header *ucode = (void *)ucode_raw->data;
struct iwl_ucode_tlv *tlv;
size_t len = ucode_raw->size;
const u8 *data;
u32 tlv_len;
enum iwl_ucode_tlv_type tlv_type;
const u8 *tlv_data;
char buildstr[25];
u32 build;
if (len < sizeof(*ucode)) {
IWL_ERR(drv, "uCode has invalid length: %zd\n", len);
return -EINVAL;
}
if (ucode->magic != cpu_to_le32(IWL_TLV_UCODE_MAGIC)) {
IWL_ERR(drv, "invalid uCode magic: 0X%x\n",
le32_to_cpu(ucode->magic));
return -EINVAL;
}
drv->fw.ucode_ver = le32_to_cpu(ucode->ver);
build = le32_to_cpu(ucode->build);
if (build)
sprintf(buildstr, " build %u%s", build,
(drv->fw_index == UCODE_EXPERIMENTAL_INDEX)
? " (EXP)" : "");
else
buildstr[0] = '\0';
snprintf(drv->fw.fw_version,
sizeof(drv->fw.fw_version),
"%u.%u.%u.%u%s",
IWL_UCODE_MAJOR(drv->fw.ucode_ver),
IWL_UCODE_MINOR(drv->fw.ucode_ver),
IWL_UCODE_API(drv->fw.ucode_ver),
IWL_UCODE_SERIAL(drv->fw.ucode_ver),
buildstr);
data = ucode->data;
len -= sizeof(*ucode);
while (len >= sizeof(*tlv)) {
len -= sizeof(*tlv);
tlv = (void *)data;
tlv_len = le32_to_cpu(tlv->length);
tlv_type = le32_to_cpu(tlv->type);
tlv_data = tlv->data;
if (len < tlv_len) {
IWL_ERR(drv, "invalid TLV len: %zd/%u\n",
len, tlv_len);
return -EINVAL;
}
len -= ALIGN(tlv_len, 4);
data += sizeof(*tlv) + ALIGN(tlv_len, 4);
switch (tlv_type) {
case IWL_UCODE_TLV_INST:
set_sec_data(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_INST, tlv_data);
set_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_INST, tlv_len);
set_sec_offset(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_INST,
IWLAGN_RTC_INST_LOWER_BOUND);
break;
case IWL_UCODE_TLV_DATA:
set_sec_data(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA, tlv_data);
set_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA, tlv_len);
set_sec_offset(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA,
IWLAGN_RTC_DATA_LOWER_BOUND);
break;
case IWL_UCODE_TLV_INIT:
set_sec_data(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_INST, tlv_data);
set_sec_size(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_INST, tlv_len);
set_sec_offset(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_INST,
IWLAGN_RTC_INST_LOWER_BOUND);
break;
case IWL_UCODE_TLV_INIT_DATA:
set_sec_data(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_DATA, tlv_data);
set_sec_size(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_DATA, tlv_len);
set_sec_offset(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_DATA,
IWLAGN_RTC_DATA_LOWER_BOUND);
break;
case IWL_UCODE_TLV_BOOT:
IWL_ERR(drv, "Found unexpected BOOT ucode\n");
break;
case IWL_UCODE_TLV_PROBE_MAX_LEN:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
capa->max_probe_length =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_PAN:
if (tlv_len)
goto invalid_tlv_len;
capa->flags |= IWL_UCODE_TLV_FLAGS_PAN;
break;
case IWL_UCODE_TLV_FLAGS:
if (tlv_len < sizeof(u32))
goto invalid_tlv_len;
if (tlv_len % sizeof(u32))
goto invalid_tlv_len;
capa->flags = le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_EVTLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_evtlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_EVTLOG_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_evtlog_size =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_INIT_ERRLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->init_errlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_EVTLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_evtlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_EVTLOG_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_evtlog_size =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_RUNT_ERRLOG_PTR:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
pieces->inst_errlog_ptr =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_ENHANCE_SENS_TBL:
if (tlv_len)
goto invalid_tlv_len;
drv->fw.enhance_sensitivity_table = true;
break;
case IWL_UCODE_TLV_WOWLAN_INST:
set_sec_data(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_INST, tlv_data);
set_sec_size(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_INST, tlv_len);
set_sec_offset(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_INST,
IWLAGN_RTC_INST_LOWER_BOUND);
break;
case IWL_UCODE_TLV_WOWLAN_DATA:
set_sec_data(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_DATA, tlv_data);
set_sec_size(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_DATA, tlv_len);
set_sec_offset(pieces, IWL_UCODE_WOWLAN,
IWL_UCODE_SECTION_DATA,
IWLAGN_RTC_DATA_LOWER_BOUND);
break;
case IWL_UCODE_TLV_PHY_CALIBRATION_SIZE:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
capa->standard_phy_calibration_size =
le32_to_cpup((__le32 *)tlv_data);
break;
case IWL_UCODE_TLV_SEC_RT:
iwl_store_ucode_sec(pieces, tlv_data, IWL_UCODE_REGULAR,
tlv_len);
drv->fw.mvm_fw = true;
break;
case IWL_UCODE_TLV_SEC_INIT:
iwl_store_ucode_sec(pieces, tlv_data, IWL_UCODE_INIT,
tlv_len);
drv->fw.mvm_fw = true;
break;
case IWL_UCODE_TLV_SEC_WOWLAN:
iwl_store_ucode_sec(pieces, tlv_data, IWL_UCODE_WOWLAN,
tlv_len);
drv->fw.mvm_fw = true;
break;
case IWL_UCODE_TLV_DEF_CALIB:
if (tlv_len != sizeof(struct iwl_tlv_calib_data))
goto invalid_tlv_len;
if (iwl_set_default_calib(drv, tlv_data))
goto tlv_error;
break;
case IWL_UCODE_TLV_PHY_SKU:
if (tlv_len != sizeof(u32))
goto invalid_tlv_len;
drv->fw.phy_config = le32_to_cpup((__le32 *)tlv_data);
break;
default:
IWL_DEBUG_INFO(drv, "unknown TLV: %d\n", tlv_type);
break;
}
}
if (len) {
IWL_ERR(drv, "invalid TLV after parsing: %zd\n", len);
iwl_print_hex_dump(drv, IWL_DL_FW, (u8 *)data, len);
return -EINVAL;
}
return 0;
invalid_tlv_len:
IWL_ERR(drv, "TLV %d has invalid size: %u\n", tlv_type, tlv_len);
tlv_error:
iwl_print_hex_dump(drv, IWL_DL_FW, tlv_data, tlv_len);
return -EINVAL;
}
static int iwl_alloc_ucode(struct iwl_drv *drv,
struct iwl_firmware_pieces *pieces,
enum iwl_ucode_type type)
{
int i;
for (i = 0;
i < IWL_UCODE_SECTION_MAX && get_sec_size(pieces, type, i);
i++)
if (iwl_alloc_fw_desc(drv, &(drv->fw.img[type].sec[i]),
get_sec(pieces, type, i)))
return -ENOMEM;
return 0;
}
static int validate_sec_sizes(struct iwl_drv *drv,
struct iwl_firmware_pieces *pieces,
const struct iwl_cfg *cfg)
{
IWL_DEBUG_INFO(drv, "f/w package hdr runtime inst size = %Zd\n",
get_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_INST));
IWL_DEBUG_INFO(drv, "f/w package hdr runtime data size = %Zd\n",
get_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA));
IWL_DEBUG_INFO(drv, "f/w package hdr init inst size = %Zd\n",
get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST));
IWL_DEBUG_INFO(drv, "f/w package hdr init data size = %Zd\n",
get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA));
if (get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_INST) >
cfg->max_inst_size) {
IWL_ERR(drv, "uCode instr len %Zd too large to fit in\n",
get_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_INST));
return -1;
}
if (get_sec_size(pieces, IWL_UCODE_REGULAR, IWL_UCODE_SECTION_DATA) >
cfg->max_data_size) {
IWL_ERR(drv, "uCode data len %Zd too large to fit in\n",
get_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA));
return -1;
}
if (get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_INST) >
cfg->max_inst_size) {
IWL_ERR(drv, "uCode init instr len %Zd too large to fit in\n",
get_sec_size(pieces, IWL_UCODE_INIT,
IWL_UCODE_SECTION_INST));
return -1;
}
if (get_sec_size(pieces, IWL_UCODE_INIT, IWL_UCODE_SECTION_DATA) >
cfg->max_data_size) {
IWL_ERR(drv, "uCode init data len %Zd too large to fit in\n",
get_sec_size(pieces, IWL_UCODE_REGULAR,
IWL_UCODE_SECTION_DATA));
return -1;
}
return 0;
}
static void iwl_ucode_callback(const struct firmware *ucode_raw, void *context)
{
struct iwl_drv *drv = context;
struct iwl_fw *fw = &drv->fw;
struct iwl_ucode_header *ucode;
struct iwlwifi_opmode_table *op;
int err;
struct iwl_firmware_pieces pieces;
const unsigned int api_max = drv->cfg->ucode_api_max;
unsigned int api_ok = drv->cfg->ucode_api_ok;
const unsigned int api_min = drv->cfg->ucode_api_min;
u32 api_ver;
int i;
bool load_module = false;
fw->ucode_capa.max_probe_length = 200;
fw->ucode_capa.standard_phy_calibration_size =
IWL_DEFAULT_STANDARD_PHY_CALIBRATE_TBL_SIZE;
if (!api_ok)
api_ok = api_max;
memset(&pieces, 0, sizeof(pieces));
if (!ucode_raw) {
if (drv->fw_index <= api_ok)
IWL_ERR(drv,
"request for firmware file '%s' failed.\n",
drv->firmware_name);
goto try_again;
}
IWL_DEBUG_INFO(drv, "Loaded firmware file '%s' (%zd bytes).\n",
drv->firmware_name, ucode_raw->size);
if (ucode_raw->size < 4) {
IWL_ERR(drv, "File size way too small!\n");
goto try_again;
}
ucode = (struct iwl_ucode_header *)ucode_raw->data;
if (ucode->ver)
err = iwl_parse_v1_v2_firmware(drv, ucode_raw, &pieces);
else
err = iwl_parse_tlv_firmware(drv, ucode_raw, &pieces,
&fw->ucode_capa);
if (err)
goto try_again;
api_ver = IWL_UCODE_API(drv->fw.ucode_ver);
if (drv->fw_index != UCODE_EXPERIMENTAL_INDEX) {
if (api_ver < api_min || api_ver > api_max) {
IWL_ERR(drv,
"Driver unable to support your firmware API. "
"Driver supports v%u, firmware is v%u.\n",
api_max, api_ver);
goto try_again;
}
if (api_ver < api_ok) {
if (api_ok != api_max)
IWL_ERR(drv, "Firmware has old API version, "
"expected v%u through v%u, got v%u.\n",
api_ok, api_max, api_ver);
else
IWL_ERR(drv, "Firmware has old API version, "
"expected v%u, got v%u.\n",
api_max, api_ver);
IWL_ERR(drv, "New firmware can be obtained from "
"http://www.intellinuxwireless.org/.\n");
}
}
IWL_INFO(drv, "loaded firmware version %s", drv->fw.fw_version);
if (!fw->mvm_fw && validate_sec_sizes(drv, &pieces, drv->cfg))
goto try_again;
for (i = 0; i < IWL_UCODE_TYPE_MAX; i++)
if (iwl_alloc_ucode(drv, &pieces, i))
goto out_free_fw;
fw->init_evtlog_ptr = pieces.init_evtlog_ptr;
if (pieces.init_evtlog_size)
fw->init_evtlog_size = (pieces.init_evtlog_size - 16)/12;
else
fw->init_evtlog_size =
drv->cfg->base_params->max_event_log_size;
fw->init_errlog_ptr = pieces.init_errlog_ptr;
fw->inst_evtlog_ptr = pieces.inst_evtlog_ptr;
if (pieces.inst_evtlog_size)
fw->inst_evtlog_size = (pieces.inst_evtlog_size - 16)/12;
else
fw->inst_evtlog_size =
drv->cfg->base_params->max_event_log_size;
fw->inst_errlog_ptr = pieces.inst_errlog_ptr;
if (fw->ucode_capa.standard_phy_calibration_size >
IWL_MAX_PHY_CALIBRATE_TBL_SIZE)
fw->ucode_capa.standard_phy_calibration_size =
IWL_MAX_STANDARD_PHY_CALIBRATE_TBL_SIZE;
release_firmware(ucode_raw);
mutex_lock(&iwlwifi_opmode_table_mtx);
op = &iwlwifi_opmode_table[DVM_OP_MODE];
list_add_tail(&drv->list, &op->drv);
if (op->ops) {
const struct iwl_op_mode_ops *ops = op->ops;
drv->op_mode = ops->start(drv->trans, drv->cfg, &drv->fw);
if (!drv->op_mode) {
mutex_unlock(&iwlwifi_opmode_table_mtx);
goto out_unbind;
}
} else {
load_module = true;
}
mutex_unlock(&iwlwifi_opmode_table_mtx);
complete(&drv->request_firmware_complete);
if (load_module)
request_module("%s", op->name);
return;
try_again:
release_firmware(ucode_raw);
if (iwl_request_firmware(drv, false))
goto out_unbind;
return;
out_free_fw:
IWL_ERR(drv, "failed to allocate pci memory\n");
iwl_dealloc_ucode(drv);
release_firmware(ucode_raw);
out_unbind:
complete(&drv->request_firmware_complete);
device_release_driver(drv->trans->dev);
}
struct iwl_drv *iwl_drv_start(struct iwl_trans *trans,
const struct iwl_cfg *cfg)
{
struct iwl_drv *drv;
int ret;
drv = kzalloc(sizeof(*drv), GFP_KERNEL);
if (!drv)
return NULL;
drv->trans = trans;
drv->dev = trans->dev;
drv->cfg = cfg;
init_completion(&drv->request_firmware_complete);
INIT_LIST_HEAD(&drv->list);
ret = iwl_request_firmware(drv, true);
if (ret) {
IWL_ERR(trans, "Couldn't request the fw\n");
kfree(drv);
drv = NULL;
}
return drv;
}
void iwl_drv_stop(struct iwl_drv *drv)
{
wait_for_completion(&drv->request_firmware_complete);
if (drv->op_mode)
iwl_op_mode_stop(drv->op_mode);
iwl_dealloc_ucode(drv);
mutex_lock(&iwlwifi_opmode_table_mtx);
if (!list_empty(&drv->list))
list_del(&drv->list);
mutex_unlock(&iwlwifi_opmode_table_mtx);
kfree(drv);
}
int iwl_opmode_register(const char *name, const struct iwl_op_mode_ops *ops)
{
int i;
struct iwl_drv *drv;
mutex_lock(&iwlwifi_opmode_table_mtx);
for (i = 0; i < ARRAY_SIZE(iwlwifi_opmode_table); i++) {
if (strcmp(iwlwifi_opmode_table[i].name, name))
continue;
iwlwifi_opmode_table[i].ops = ops;
list_for_each_entry(drv, &iwlwifi_opmode_table[i].drv, list)
drv->op_mode = ops->start(drv->trans, drv->cfg,
&drv->fw);
mutex_unlock(&iwlwifi_opmode_table_mtx);
return 0;
}
mutex_unlock(&iwlwifi_opmode_table_mtx);
return -EIO;
}
void iwl_opmode_deregister(const char *name)
{
int i;
struct iwl_drv *drv;
mutex_lock(&iwlwifi_opmode_table_mtx);
for (i = 0; i < ARRAY_SIZE(iwlwifi_opmode_table); i++) {
if (strcmp(iwlwifi_opmode_table[i].name, name))
continue;
iwlwifi_opmode_table[i].ops = NULL;
list_for_each_entry(drv, &iwlwifi_opmode_table[i].drv, list) {
if (drv->op_mode) {
iwl_op_mode_stop(drv->op_mode);
drv->op_mode = NULL;
}
}
mutex_unlock(&iwlwifi_opmode_table_mtx);
return;
}
mutex_unlock(&iwlwifi_opmode_table_mtx);
}
static int __init iwl_drv_init(void)
{
int i;
mutex_init(&iwlwifi_opmode_table_mtx);
for (i = 0; i < ARRAY_SIZE(iwlwifi_opmode_table); i++)
INIT_LIST_HEAD(&iwlwifi_opmode_table[i].drv);
pr_info(DRV_DESCRIPTION ", " DRV_VERSION "\n");
pr_info(DRV_COPYRIGHT "\n");
return iwl_pci_register_driver();
}
static void __exit iwl_drv_exit(void)
{
iwl_pci_unregister_driver();
}
