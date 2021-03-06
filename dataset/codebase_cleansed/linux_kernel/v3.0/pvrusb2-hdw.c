static void trace_stbit(const char *name,int val)
{
pvr2_trace(PVR2_TRACE_STBITS,
"State bit %s <-- %s",
name,(val ? "true" : "false"));
}
static int ctrl_channelfreq_get(struct pvr2_ctrl *cptr,int *vp)
{
struct pvr2_hdw *hdw = cptr->hdw;
if ((hdw->freqProgSlot > 0) && (hdw->freqProgSlot <= FREQTABLE_SIZE)) {
*vp = hdw->freqTable[hdw->freqProgSlot-1];
} else {
*vp = 0;
}
return 0;
}
static int ctrl_channelfreq_set(struct pvr2_ctrl *cptr,int m,int v)
{
struct pvr2_hdw *hdw = cptr->hdw;
unsigned int slotId = hdw->freqProgSlot;
if ((slotId > 0) && (slotId <= FREQTABLE_SIZE)) {
hdw->freqTable[slotId-1] = v;
if (hdw->freqSelector) {
if (hdw->freqSlotRadio == slotId) {
hdw->freqSlotRadio = 0;
}
} else {
if (hdw->freqSlotTelevision == slotId) {
hdw->freqSlotTelevision = 0;
}
}
}
return 0;
}
static int ctrl_channelprog_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->freqProgSlot;
return 0;
}
static int ctrl_channelprog_set(struct pvr2_ctrl *cptr,int m,int v)
{
struct pvr2_hdw *hdw = cptr->hdw;
if ((v >= 0) && (v <= FREQTABLE_SIZE)) {
hdw->freqProgSlot = v;
}
return 0;
}
static int ctrl_channel_get(struct pvr2_ctrl *cptr,int *vp)
{
struct pvr2_hdw *hdw = cptr->hdw;
*vp = hdw->freqSelector ? hdw->freqSlotRadio : hdw->freqSlotTelevision;
return 0;
}
static int ctrl_channel_set(struct pvr2_ctrl *cptr,int m,int slotId)
{
unsigned freq = 0;
struct pvr2_hdw *hdw = cptr->hdw;
if ((slotId < 0) || (slotId > FREQTABLE_SIZE)) return 0;
if (slotId > 0) {
freq = hdw->freqTable[slotId-1];
if (!freq) return 0;
pvr2_hdw_set_cur_freq(hdw,freq);
}
if (hdw->freqSelector) {
hdw->freqSlotRadio = slotId;
} else {
hdw->freqSlotTelevision = slotId;
}
return 0;
}
static int ctrl_freq_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = pvr2_hdw_get_cur_freq(cptr->hdw);
return 0;
}
static int ctrl_freq_is_dirty(struct pvr2_ctrl *cptr)
{
return cptr->hdw->freqDirty != 0;
}
static void ctrl_freq_clear_dirty(struct pvr2_ctrl *cptr)
{
cptr->hdw->freqDirty = 0;
}
static int ctrl_freq_set(struct pvr2_ctrl *cptr,int m,int v)
{
pvr2_hdw_set_cur_freq(cptr->hdw,v);
return 0;
}
static int ctrl_cropl_min_get(struct pvr2_ctrl *cptr, int *left)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*left = cap->bounds.left;
return 0;
}
static int ctrl_cropl_max_get(struct pvr2_ctrl *cptr, int *left)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*left = cap->bounds.left;
if (cap->bounds.width > cptr->hdw->cropw_val) {
*left += cap->bounds.width - cptr->hdw->cropw_val;
}
return 0;
}
static int ctrl_cropt_min_get(struct pvr2_ctrl *cptr, int *top)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*top = cap->bounds.top;
return 0;
}
static int ctrl_cropt_max_get(struct pvr2_ctrl *cptr, int *top)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*top = cap->bounds.top;
if (cap->bounds.height > cptr->hdw->croph_val) {
*top += cap->bounds.height - cptr->hdw->croph_val;
}
return 0;
}
static int ctrl_cropw_max_get(struct pvr2_ctrl *cptr, int *width)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat, bleftend, cleft;
stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
bleftend = cap->bounds.left+cap->bounds.width;
cleft = cptr->hdw->cropl_val;
*width = cleft < bleftend ? bleftend-cleft : 0;
return 0;
}
static int ctrl_croph_max_get(struct pvr2_ctrl *cptr, int *height)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat, btopend, ctop;
stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
btopend = cap->bounds.top+cap->bounds.height;
ctop = cptr->hdw->cropt_val;
*height = ctop < btopend ? btopend-ctop : 0;
return 0;
}
static int ctrl_get_cropcapbl(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->bounds.left;
return 0;
}
static int ctrl_get_cropcapbt(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->bounds.top;
return 0;
}
static int ctrl_get_cropcapbw(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->bounds.width;
return 0;
}
static int ctrl_get_cropcapbh(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->bounds.height;
return 0;
}
static int ctrl_get_cropcapdl(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->defrect.left;
return 0;
}
static int ctrl_get_cropcapdt(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->defrect.top;
return 0;
}
static int ctrl_get_cropcapdw(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->defrect.width;
return 0;
}
static int ctrl_get_cropcapdh(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->defrect.height;
return 0;
}
static int ctrl_get_cropcappan(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->pixelaspect.numerator;
return 0;
}
static int ctrl_get_cropcappad(struct pvr2_ctrl *cptr, int *val)
{
struct v4l2_cropcap *cap = &cptr->hdw->cropcap_info;
int stat = pvr2_hdw_check_cropcap(cptr->hdw);
if (stat != 0) {
return stat;
}
*val = cap->pixelaspect.denominator;
return 0;
}
static int ctrl_vres_max_get(struct pvr2_ctrl *cptr,int *vp)
{
if (cptr->hdw->std_mask_cur & V4L2_STD_525_60) {
*vp = 480;
} else {
*vp = 576;
}
return 0;
}
static int ctrl_vres_min_get(struct pvr2_ctrl *cptr,int *vp)
{
if (cptr->hdw->hdw_desc->flag_has_cx25840) {
*vp = 75;
} else {
*vp = 17;
}
return 0;
}
static int ctrl_get_input(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->input_val;
return 0;
}
static int ctrl_check_input(struct pvr2_ctrl *cptr,int v)
{
return ((1 << v) & cptr->hdw->input_allowed_mask) != 0;
}
static int ctrl_set_input(struct pvr2_ctrl *cptr,int m,int v)
{
return pvr2_hdw_set_input(cptr->hdw,v);
}
static int ctrl_isdirty_input(struct pvr2_ctrl *cptr)
{
return cptr->hdw->input_dirty != 0;
}
static void ctrl_cleardirty_input(struct pvr2_ctrl *cptr)
{
cptr->hdw->input_dirty = 0;
}
static int ctrl_freq_max_get(struct pvr2_ctrl *cptr, int *vp)
{
unsigned long fv;
struct pvr2_hdw *hdw = cptr->hdw;
if (hdw->tuner_signal_stale) {
pvr2_hdw_status_poll(hdw);
}
fv = hdw->tuner_signal_info.rangehigh;
if (!fv) {
*vp = TV_MAX_FREQ;
return 0;
}
if (hdw->tuner_signal_info.capability & V4L2_TUNER_CAP_LOW) {
fv = (fv * 125) / 2;
} else {
fv = fv * 62500;
}
*vp = fv;
return 0;
}
static int ctrl_freq_min_get(struct pvr2_ctrl *cptr, int *vp)
{
unsigned long fv;
struct pvr2_hdw *hdw = cptr->hdw;
if (hdw->tuner_signal_stale) {
pvr2_hdw_status_poll(hdw);
}
fv = hdw->tuner_signal_info.rangelow;
if (!fv) {
*vp = TV_MIN_FREQ;
return 0;
}
if (hdw->tuner_signal_info.capability & V4L2_TUNER_CAP_LOW) {
fv = (fv * 125) / 2;
} else {
fv = fv * 62500;
}
*vp = fv;
return 0;
}
static int ctrl_cx2341x_is_dirty(struct pvr2_ctrl *cptr)
{
return cptr->hdw->enc_stale != 0;
}
static void ctrl_cx2341x_clear_dirty(struct pvr2_ctrl *cptr)
{
cptr->hdw->enc_stale = 0;
cptr->hdw->enc_unsafe_stale = 0;
}
static int ctrl_cx2341x_get(struct pvr2_ctrl *cptr,int *vp)
{
int ret;
struct v4l2_ext_controls cs;
struct v4l2_ext_control c1;
memset(&cs,0,sizeof(cs));
memset(&c1,0,sizeof(c1));
cs.controls = &c1;
cs.count = 1;
c1.id = cptr->info->v4l_id;
ret = cx2341x_ext_ctrls(&cptr->hdw->enc_ctl_state, 0, &cs,
VIDIOC_G_EXT_CTRLS);
if (ret) return ret;
*vp = c1.value;
return 0;
}
static int ctrl_cx2341x_set(struct pvr2_ctrl *cptr,int m,int v)
{
int ret;
struct pvr2_hdw *hdw = cptr->hdw;
struct v4l2_ext_controls cs;
struct v4l2_ext_control c1;
memset(&cs,0,sizeof(cs));
memset(&c1,0,sizeof(c1));
cs.controls = &c1;
cs.count = 1;
c1.id = cptr->info->v4l_id;
c1.value = v;
ret = cx2341x_ext_ctrls(&hdw->enc_ctl_state,
hdw->state_encoder_run, &cs,
VIDIOC_S_EXT_CTRLS);
if (ret == -EBUSY) {
ret = cx2341x_ext_ctrls(&hdw->enc_ctl_state,
0, &cs,
VIDIOC_S_EXT_CTRLS);
if (!ret) hdw->enc_unsafe_stale = !0;
}
if (ret) return ret;
hdw->enc_stale = !0;
return 0;
}
static unsigned int ctrl_cx2341x_getv4lflags(struct pvr2_ctrl *cptr)
{
struct v4l2_queryctrl qctrl;
struct pvr2_ctl_info *info;
qctrl.id = cptr->info->v4l_id;
cx2341x_ctrl_query(&cptr->hdw->enc_ctl_state,&qctrl);
info = (struct pvr2_ctl_info *)(cptr->info);
if (qctrl.flags & V4L2_CTRL_FLAG_READ_ONLY) {
if (info->set_value) {
info->set_value = NULL;
}
} else {
if (!(info->set_value)) {
info->set_value = ctrl_cx2341x_set;
}
}
return qctrl.flags;
}
static int ctrl_streamingenabled_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->state_pipeline_req;
return 0;
}
static int ctrl_masterstate_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->master_state;
return 0;
}
static int ctrl_hsm_get(struct pvr2_ctrl *cptr,int *vp)
{
int result = pvr2_hdw_is_hsm(cptr->hdw);
*vp = PVR2_CVAL_HSM_FULL;
if (result < 0) *vp = PVR2_CVAL_HSM_FAIL;
if (result) *vp = PVR2_CVAL_HSM_HIGH;
return 0;
}
static int ctrl_stdavail_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->std_mask_avail;
return 0;
}
static int ctrl_stdavail_set(struct pvr2_ctrl *cptr,int m,int v)
{
struct pvr2_hdw *hdw = cptr->hdw;
v4l2_std_id ns;
ns = hdw->std_mask_avail;
ns = (ns & ~m) | (v & m);
if (ns == hdw->std_mask_avail) return 0;
hdw->std_mask_avail = ns;
pvr2_hdw_internal_set_std_avail(hdw);
pvr2_hdw_internal_find_stdenum(hdw);
return 0;
}
static int ctrl_std_val_to_sym(struct pvr2_ctrl *cptr,int msk,int val,
char *bufPtr,unsigned int bufSize,
unsigned int *len)
{
*len = pvr2_std_id_to_str(bufPtr,bufSize,msk & val);
return 0;
}
static int ctrl_std_sym_to_val(struct pvr2_ctrl *cptr,
const char *bufPtr,unsigned int bufSize,
int *mskp,int *valp)
{
int ret;
v4l2_std_id id;
ret = pvr2_std_str_to_id(&id,bufPtr,bufSize);
if (ret < 0) return ret;
if (mskp) *mskp = id;
if (valp) *valp = id;
return 0;
}
static int ctrl_stdcur_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->std_mask_cur;
return 0;
}
static int ctrl_stdcur_set(struct pvr2_ctrl *cptr,int m,int v)
{
struct pvr2_hdw *hdw = cptr->hdw;
v4l2_std_id ns;
ns = hdw->std_mask_cur;
ns = (ns & ~m) | (v & m);
if (ns == hdw->std_mask_cur) return 0;
hdw->std_mask_cur = ns;
hdw->std_dirty = !0;
pvr2_hdw_internal_find_stdenum(hdw);
return 0;
}
static int ctrl_stdcur_is_dirty(struct pvr2_ctrl *cptr)
{
return cptr->hdw->std_dirty != 0;
}
static void ctrl_stdcur_clear_dirty(struct pvr2_ctrl *cptr)
{
cptr->hdw->std_dirty = 0;
}
static int ctrl_signal_get(struct pvr2_ctrl *cptr,int *vp)
{
struct pvr2_hdw *hdw = cptr->hdw;
pvr2_hdw_status_poll(hdw);
*vp = hdw->tuner_signal_info.signal;
return 0;
}
static int ctrl_audio_modes_present_get(struct pvr2_ctrl *cptr,int *vp)
{
int val = 0;
unsigned int subchan;
struct pvr2_hdw *hdw = cptr->hdw;
pvr2_hdw_status_poll(hdw);
subchan = hdw->tuner_signal_info.rxsubchans;
if (subchan & V4L2_TUNER_SUB_MONO) {
val |= (1 << V4L2_TUNER_MODE_MONO);
}
if (subchan & V4L2_TUNER_SUB_STEREO) {
val |= (1 << V4L2_TUNER_MODE_STEREO);
}
if (subchan & V4L2_TUNER_SUB_LANG1) {
val |= (1 << V4L2_TUNER_MODE_LANG1);
}
if (subchan & V4L2_TUNER_SUB_LANG2) {
val |= (1 << V4L2_TUNER_MODE_LANG2);
}
*vp = val;
return 0;
}
static int ctrl_stdenumcur_set(struct pvr2_ctrl *cptr,int m,int v)
{
struct pvr2_hdw *hdw = cptr->hdw;
if (v < 0) return -EINVAL;
if (v > hdw->std_enum_cnt) return -EINVAL;
hdw->std_enum_cur = v;
if (!v) return 0;
v--;
if (hdw->std_mask_cur == hdw->std_defs[v].id) return 0;
hdw->std_mask_cur = hdw->std_defs[v].id;
hdw->std_dirty = !0;
return 0;
}
static int ctrl_stdenumcur_get(struct pvr2_ctrl *cptr,int *vp)
{
*vp = cptr->hdw->std_enum_cur;
return 0;
}
static int ctrl_stdenumcur_is_dirty(struct pvr2_ctrl *cptr)
{
return cptr->hdw->std_dirty != 0;
}
static void ctrl_stdenumcur_clear_dirty(struct pvr2_ctrl *cptr)
{
cptr->hdw->std_dirty = 0;
}
const char *pvr2_config_get_name(enum pvr2_config cfg)
{
switch (cfg) {
case pvr2_config_empty: return "empty";
case pvr2_config_mpeg: return "mpeg";
case pvr2_config_vbi: return "vbi";
case pvr2_config_pcm: return "pcm";
case pvr2_config_rawvideo: return "raw video";
}
return "<unknown>";
}
struct usb_device *pvr2_hdw_get_dev(struct pvr2_hdw *hdw)
{
return hdw->usb_dev;
}
unsigned long pvr2_hdw_get_sn(struct pvr2_hdw *hdw)
{
return hdw->serial_number;
}
const char *pvr2_hdw_get_bus_info(struct pvr2_hdw *hdw)
{
return hdw->bus_info;
}
const char *pvr2_hdw_get_device_identifier(struct pvr2_hdw *hdw)
{
return hdw->identifier;
}
unsigned long pvr2_hdw_get_cur_freq(struct pvr2_hdw *hdw)
{
return hdw->freqSelector ? hdw->freqValTelevision : hdw->freqValRadio;
}
static void pvr2_hdw_set_cur_freq(struct pvr2_hdw *hdw,unsigned long val)
{
if (hdw->input_val == PVR2_CVAL_INPUT_RADIO) {
if (hdw->freqSelector) {
hdw->freqSelector = 0;
hdw->freqDirty = !0;
}
if (hdw->freqValRadio != val) {
hdw->freqValRadio = val;
hdw->freqSlotRadio = 0;
hdw->freqDirty = !0;
}
} else {
if (!(hdw->freqSelector)) {
hdw->freqSelector = 1;
hdw->freqDirty = !0;
}
if (hdw->freqValTelevision != val) {
hdw->freqValTelevision = val;
hdw->freqSlotTelevision = 0;
hdw->freqDirty = !0;
}
}
}
int pvr2_hdw_get_unit_number(struct pvr2_hdw *hdw)
{
return hdw->unit_number;
}
static int pvr2_locate_firmware(struct pvr2_hdw *hdw,
const struct firmware **fw_entry,
const char *fwtypename,
unsigned int fwcount,
const char *fwnames[])
{
unsigned int idx;
int ret = -EINVAL;
for (idx = 0; idx < fwcount; idx++) {
ret = request_firmware(fw_entry,
fwnames[idx],
&hdw->usb_dev->dev);
if (!ret) {
trace_firmware("Located %s firmware: %s;"
" uploading...",
fwtypename,
fwnames[idx]);
return idx;
}
if (ret == -ENOENT) continue;
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"request_firmware fatal error with code=%d",ret);
return ret;
}
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"***WARNING***"
" Device %s firmware"
" seems to be missing.",
fwtypename);
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Did you install the pvrusb2 firmware files"
" in their proper location?");
if (fwcount == 1) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"request_firmware unable to locate %s file %s",
fwtypename,fwnames[0]);
} else {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"request_firmware unable to locate"
" one of the following %s files:",
fwtypename);
for (idx = 0; idx < fwcount; idx++) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"request_firmware: Failed to find %s",
fwnames[idx]);
}
}
return ret;
}
static int pvr2_upload_firmware1(struct pvr2_hdw *hdw)
{
const struct firmware *fw_entry = NULL;
void *fw_ptr;
unsigned int pipe;
unsigned int fwsize;
int ret;
u16 address;
if (!hdw->hdw_desc->fx2_firmware.cnt) {
hdw->fw1_state = FW1_STATE_OK;
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Connected device type defines"
" no firmware to upload; ignoring firmware");
return -ENOTTY;
}
hdw->fw1_state = FW1_STATE_FAILED;
trace_firmware("pvr2_upload_firmware1");
ret = pvr2_locate_firmware(hdw,&fw_entry,"fx2 controller",
hdw->hdw_desc->fx2_firmware.cnt,
hdw->hdw_desc->fx2_firmware.lst);
if (ret < 0) {
if (ret == -ENOENT) hdw->fw1_state = FW1_STATE_MISSING;
return ret;
}
usb_clear_halt(hdw->usb_dev, usb_sndbulkpipe(hdw->usb_dev, 0 & 0x7f));
pipe = usb_sndctrlpipe(hdw->usb_dev, 0);
fwsize = fw_entry->size;
if ((fwsize != 0x2000) &&
(!(hdw->hdw_desc->flag_fx2_16kb && (fwsize == 0x4000)))) {
if (hdw->hdw_desc->flag_fx2_16kb) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Wrong fx2 firmware size"
" (expected 8192 or 16384, got %u)",
fwsize);
} else {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Wrong fx2 firmware size"
" (expected 8192, got %u)",
fwsize);
}
release_firmware(fw_entry);
return -ENOMEM;
}
fw_ptr = kmalloc(0x800, GFP_KERNEL);
if (fw_ptr == NULL){
release_firmware(fw_entry);
return -ENOMEM;
}
pvr2_hdw_cpureset_assert(hdw,1);
ret = 0;
for (address = 0; address < fwsize; address += 0x800) {
memcpy(fw_ptr, fw_entry->data + address, 0x800);
ret += usb_control_msg(hdw->usb_dev, pipe, 0xa0, 0x40, address,
0, fw_ptr, 0x800, HZ);
}
trace_firmware("Upload done, releasing device's CPU");
pvr2_hdw_cpureset_assert(hdw,0);
kfree(fw_ptr);
release_firmware(fw_entry);
trace_firmware("Upload done (%d bytes sent)",ret);
if (ret == fwsize) {
hdw->fw1_state = FW1_STATE_RELOAD;
return 0;
}
return -EIO;
}
int pvr2_upload_firmware2(struct pvr2_hdw *hdw)
{
const struct firmware *fw_entry = NULL;
void *fw_ptr;
unsigned int pipe, fw_len, fw_done, bcnt, icnt;
int actual_length;
int ret = 0;
int fwidx;
static const char *fw_files[] = {
CX2341X_FIRM_ENC_FILENAME,
};
if (hdw->hdw_desc->flag_skip_cx23416_firmware) {
return 0;
}
trace_firmware("pvr2_upload_firmware2");
ret = pvr2_locate_firmware(hdw,&fw_entry,"encoder",
ARRAY_SIZE(fw_files), fw_files);
if (ret < 0) return ret;
fwidx = ret;
ret = 0;
hdw->enc_cur_valid = 0;
del_timer_sync(&hdw->encoder_run_timer);
if (hdw->state_encoder_runok) {
hdw->state_encoder_runok = 0;
trace_stbit("state_encoder_runok",hdw->state_encoder_runok);
}
ret |= pvr2_write_register(hdw, 0x0048, 0xffffffff);
ret |= pvr2_hdw_gpio_chg_dir(hdw,0xffffffff,0x00000088);
ret |= pvr2_hdw_gpio_chg_out(hdw,0xffffffff,0x00000008);
ret |= pvr2_hdw_cmd_deep_reset(hdw);
ret |= pvr2_write_register(hdw, 0xa064, 0x00000000);
ret |= pvr2_hdw_gpio_chg_dir(hdw,0xffffffff,0x00000408);
ret |= pvr2_hdw_gpio_chg_out(hdw,0xffffffff,0x00000008);
ret |= pvr2_write_register(hdw, 0x9058, 0xffffffed);
ret |= pvr2_write_register(hdw, 0x9054, 0xfffffffd);
ret |= pvr2_write_register(hdw, 0x07f8, 0x80000800);
ret |= pvr2_write_register(hdw, 0x07fc, 0x0000001a);
ret |= pvr2_write_register(hdw, 0x0700, 0x00000000);
ret |= pvr2_write_register(hdw, 0xaa00, 0x00000000);
ret |= pvr2_write_register(hdw, 0xaa04, 0x00057810);
ret |= pvr2_write_register(hdw, 0xaa10, 0x00148500);
ret |= pvr2_write_register(hdw, 0xaa18, 0x00840000);
ret |= pvr2_issue_simple_cmd(hdw,FX2CMD_FWPOST1);
ret |= pvr2_issue_simple_cmd(hdw,FX2CMD_MEMSEL | (1 << 8) | (0 << 16));
if (ret) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"firmware2 upload prep failed, ret=%d",ret);
release_firmware(fw_entry);
goto done;
}
fw_len = fw_entry->size;
if (fw_len % sizeof(u32)) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"size of %s firmware"
" must be a multiple of %zu bytes",
fw_files[fwidx],sizeof(u32));
release_firmware(fw_entry);
ret = -EINVAL;
goto done;
}
fw_ptr = kmalloc(FIRMWARE_CHUNK_SIZE, GFP_KERNEL);
if (fw_ptr == NULL){
release_firmware(fw_entry);
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"failed to allocate memory for firmware2 upload");
ret = -ENOMEM;
goto done;
}
pipe = usb_sndbulkpipe(hdw->usb_dev, PVR2_FIRMWARE_ENDPOINT);
fw_done = 0;
for (fw_done = 0; fw_done < fw_len;) {
bcnt = fw_len - fw_done;
if (bcnt > FIRMWARE_CHUNK_SIZE) bcnt = FIRMWARE_CHUNK_SIZE;
memcpy(fw_ptr, fw_entry->data + fw_done, bcnt);
for (icnt = 0; icnt < bcnt/4 ; icnt++)
((u32 *)fw_ptr)[icnt] = swab32(((u32 *)fw_ptr)[icnt]);
ret |= usb_bulk_msg(hdw->usb_dev, pipe, fw_ptr,bcnt,
&actual_length, HZ);
ret |= (actual_length != bcnt);
if (ret) break;
fw_done += bcnt;
}
trace_firmware("upload of %s : %i / %i ",
fw_files[fwidx],fw_done,fw_len);
kfree(fw_ptr);
release_firmware(fw_entry);
if (ret) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"firmware2 upload transfer failure");
goto done;
}
ret |= pvr2_write_register(hdw, 0x9054, 0xffffffff);
ret |= pvr2_write_register(hdw, 0x9058, 0xffffffe8);
ret |= pvr2_issue_simple_cmd(hdw,FX2CMD_MEMSEL | (1 << 8) | (0 << 16));
if (ret) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"firmware2 upload post-proc failure");
}
done:
if (hdw->hdw_desc->signal_routing_scheme ==
PVR2_ROUTING_SCHEME_GOTVIEW) {
pvr2_hdw_gpio_chg_dir(hdw,(1 << 11),~0);
}
return ret;
}
static const char *pvr2_get_state_name(unsigned int st)
{
if (st < ARRAY_SIZE(pvr2_state_names)) {
return pvr2_state_names[st];
}
return "???";
}
static int pvr2_decoder_enable(struct pvr2_hdw *hdw,int enablefl)
{
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 stream=%s",
(enablefl ? "on" : "off"));
v4l2_device_call_all(&hdw->v4l2_dev, 0, video, s_stream, enablefl);
v4l2_device_call_all(&hdw->v4l2_dev, 0, audio, s_stream, enablefl);
if (hdw->decoder_client_id) {
return 0;
}
if (!hdw->flag_decoder_missed) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"WARNING: No decoder present");
hdw->flag_decoder_missed = !0;
trace_stbit("flag_decoder_missed",
hdw->flag_decoder_missed);
}
return -EIO;
}
int pvr2_hdw_get_state(struct pvr2_hdw *hdw)
{
return hdw->master_state;
}
static int pvr2_hdw_untrip_unlocked(struct pvr2_hdw *hdw)
{
if (!hdw->flag_tripped) return 0;
hdw->flag_tripped = 0;
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Clearing driver error statuss");
return !0;
}
int pvr2_hdw_untrip(struct pvr2_hdw *hdw)
{
int fl;
LOCK_TAKE(hdw->big_lock); do {
fl = pvr2_hdw_untrip_unlocked(hdw);
} while (0); LOCK_GIVE(hdw->big_lock);
if (fl) pvr2_hdw_state_sched(hdw);
return 0;
}
int pvr2_hdw_get_streaming(struct pvr2_hdw *hdw)
{
return hdw->state_pipeline_req != 0;
}
int pvr2_hdw_set_streaming(struct pvr2_hdw *hdw,int enable_flag)
{
int ret,st;
LOCK_TAKE(hdw->big_lock); do {
pvr2_hdw_untrip_unlocked(hdw);
if ((!enable_flag) != !(hdw->state_pipeline_req)) {
hdw->state_pipeline_req = enable_flag != 0;
pvr2_trace(PVR2_TRACE_START_STOP,
"/*--TRACE_STREAM--*/ %s",
enable_flag ? "enable" : "disable");
}
pvr2_hdw_state_sched(hdw);
} while (0); LOCK_GIVE(hdw->big_lock);
if ((ret = pvr2_hdw_wait(hdw,0)) < 0) return ret;
if (enable_flag) {
while ((st = hdw->master_state) != PVR2_STATE_RUN) {
if (st != PVR2_STATE_READY) return -EIO;
if ((ret = pvr2_hdw_wait(hdw,st)) < 0) return ret;
}
}
return 0;
}
int pvr2_hdw_set_stream_type(struct pvr2_hdw *hdw,enum pvr2_config config)
{
int fl;
LOCK_TAKE(hdw->big_lock);
if ((fl = (hdw->desired_stream_type != config)) != 0) {
hdw->desired_stream_type = config;
hdw->state_pipeline_config = 0;
trace_stbit("state_pipeline_config",
hdw->state_pipeline_config);
pvr2_hdw_state_sched(hdw);
}
LOCK_GIVE(hdw->big_lock);
if (fl) return 0;
return pvr2_hdw_wait(hdw,0);
}
static int get_default_tuner_type(struct pvr2_hdw *hdw)
{
int unit_number = hdw->unit_number;
int tp = -1;
if ((unit_number >= 0) && (unit_number < PVR_NUM)) {
tp = tuner[unit_number];
}
if (tp < 0) return -EINVAL;
hdw->tuner_type = tp;
hdw->tuner_updated = !0;
return 0;
}
static v4l2_std_id get_default_standard(struct pvr2_hdw *hdw)
{
int unit_number = hdw->unit_number;
int tp = 0;
if ((unit_number >= 0) && (unit_number < PVR_NUM)) {
tp = video_std[unit_number];
if (tp) return tp;
}
return 0;
}
static unsigned int get_default_error_tolerance(struct pvr2_hdw *hdw)
{
int unit_number = hdw->unit_number;
int tp = 0;
if ((unit_number >= 0) && (unit_number < PVR_NUM)) {
tp = tolerance[unit_number];
}
return tp;
}
static int pvr2_hdw_check_firmware(struct pvr2_hdw *hdw)
{
int result;
LOCK_TAKE(hdw->ctl_lock); do {
hdw->cmd_buffer[0] = FX2CMD_GET_EEPROM_ADDR;
result = pvr2_send_request_ex(hdw,HZ*1,!0,
hdw->cmd_buffer,1,
hdw->cmd_buffer,1);
if (result < 0) break;
} while(0); LOCK_GIVE(hdw->ctl_lock);
if (result) {
pvr2_trace(PVR2_TRACE_INIT,
"Probe of device endpoint 1 result status %d",
result);
} else {
pvr2_trace(PVR2_TRACE_INIT,
"Probe of device endpoint 1 succeeded");
}
return result == 0;
}
static void pvr2_hdw_setup_std(struct pvr2_hdw *hdw)
{
char buf[40];
unsigned int bcnt;
v4l2_std_id std1,std2,std3;
std1 = get_default_standard(hdw);
std3 = std1 ? 0 : hdw->hdw_desc->default_std_mask;
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),hdw->std_mask_eeprom);
pvr2_trace(PVR2_TRACE_STD,
"Supported video standard(s) reported available"
" in hardware: %.*s",
bcnt,buf);
hdw->std_mask_avail = hdw->std_mask_eeprom;
std2 = (std1|std3) & ~hdw->std_mask_avail;
if (std2) {
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),std2);
pvr2_trace(PVR2_TRACE_STD,
"Expanding supported video standards"
" to include: %.*s",
bcnt,buf);
hdw->std_mask_avail |= std2;
}
pvr2_hdw_internal_set_std_avail(hdw);
if (std1) {
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),std1);
pvr2_trace(PVR2_TRACE_STD,
"Initial video standard forced to %.*s",
bcnt,buf);
hdw->std_mask_cur = std1;
hdw->std_dirty = !0;
pvr2_hdw_internal_find_stdenum(hdw);
return;
}
if (std3) {
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),std3);
pvr2_trace(PVR2_TRACE_STD,
"Initial video standard"
" (determined by device type): %.*s",bcnt,buf);
hdw->std_mask_cur = std3;
hdw->std_dirty = !0;
pvr2_hdw_internal_find_stdenum(hdw);
return;
}
{
unsigned int idx;
for (idx = 0; idx < ARRAY_SIZE(std_eeprom_maps); idx++) {
if (std_eeprom_maps[idx].msk ?
((std_eeprom_maps[idx].pat ^
hdw->std_mask_eeprom) &
std_eeprom_maps[idx].msk) :
(std_eeprom_maps[idx].pat !=
hdw->std_mask_eeprom)) continue;
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),
std_eeprom_maps[idx].std);
pvr2_trace(PVR2_TRACE_STD,
"Initial video standard guessed as %.*s",
bcnt,buf);
hdw->std_mask_cur = std_eeprom_maps[idx].std;
hdw->std_dirty = !0;
pvr2_hdw_internal_find_stdenum(hdw);
return;
}
}
if (hdw->std_enum_cnt > 1) {
hdw->std_enum_cur = 1;
hdw->std_mask_cur = hdw->std_defs[hdw->std_enum_cur-1].id;
hdw->std_dirty = !0;
pvr2_trace(PVR2_TRACE_STD,
"Initial video standard auto-selected to %s",
hdw->std_defs[hdw->std_enum_cur-1].name);
return;
}
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Unable to select a viable initial video standard");
}
static unsigned int pvr2_copy_i2c_addr_list(
unsigned short *dst, const unsigned char *src,
unsigned int dst_max)
{
unsigned int cnt = 0;
if (!src) return 0;
while (src[cnt] && (cnt + 1) < dst_max) {
dst[cnt] = src[cnt];
cnt++;
}
dst[cnt] = I2C_CLIENT_END;
return cnt;
}
static void pvr2_hdw_cx25840_vbi_hack(struct pvr2_hdw *hdw)
{
struct v4l2_format fmt;
if (hdw->decoder_client_id != PVR2_CLIENT_ID_CX25840) {
return;
}
pvr2_trace(PVR2_TRACE_INIT,
"Module ID %u:"
" Executing cx25840 VBI hack",
hdw->decoder_client_id);
memset(&fmt, 0, sizeof(fmt));
fmt.type = V4L2_BUF_TYPE_SLICED_VBI_CAPTURE;
fmt.fmt.sliced.service_lines[0][21] = V4L2_SLICED_CAPTION_525;
fmt.fmt.sliced.service_lines[1][21] = V4L2_SLICED_CAPTION_525;
v4l2_device_call_all(&hdw->v4l2_dev, hdw->decoder_client_id,
vbi, s_sliced_fmt, &fmt.fmt.sliced);
}
static int pvr2_hdw_load_subdev(struct pvr2_hdw *hdw,
const struct pvr2_device_client_desc *cd)
{
const char *fname;
unsigned char mid;
struct v4l2_subdev *sd;
unsigned int i2ccnt;
const unsigned char *p;
unsigned short i2caddr[25];
mid = cd->module_id;
fname = (mid < ARRAY_SIZE(module_names)) ? module_names[mid] : NULL;
if (!fname) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Module ID %u for device %s has no name?"
" The driver might have a configuration problem.",
mid,
hdw->hdw_desc->description);
return -EINVAL;
}
pvr2_trace(PVR2_TRACE_INIT,
"Module ID %u (%s) for device %s being loaded...",
mid, fname,
hdw->hdw_desc->description);
i2ccnt = pvr2_copy_i2c_addr_list(i2caddr, cd->i2c_address_list,
ARRAY_SIZE(i2caddr));
if (!i2ccnt && ((p = (mid < ARRAY_SIZE(module_i2c_addresses)) ?
module_i2c_addresses[mid] : NULL) != NULL)) {
i2ccnt = pvr2_copy_i2c_addr_list(i2caddr, p,
ARRAY_SIZE(i2caddr));
if (i2ccnt) {
pvr2_trace(PVR2_TRACE_INIT,
"Module ID %u:"
" Using default i2c address list",
mid);
}
}
if (!i2ccnt) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Module ID %u (%s) for device %s:"
" No i2c addresses."
" The driver might have a configuration problem.",
mid, fname, hdw->hdw_desc->description);
return -EINVAL;
}
if (i2ccnt == 1) {
pvr2_trace(PVR2_TRACE_INIT,
"Module ID %u:"
" Setting up with specified i2c address 0x%x",
mid, i2caddr[0]);
sd = v4l2_i2c_new_subdev(&hdw->v4l2_dev, &hdw->i2c_adap,
fname, i2caddr[0], NULL);
} else {
pvr2_trace(PVR2_TRACE_INIT,
"Module ID %u:"
" Setting up with address probe list",
mid);
sd = v4l2_i2c_new_subdev(&hdw->v4l2_dev, &hdw->i2c_adap,
fname, 0, i2caddr);
}
if (!sd) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Module ID %u (%s) for device %s failed to load."
" Possible missing sub-device kernel module or"
" initialization failure within module.",
mid, fname, hdw->hdw_desc->description);
return -EIO;
}
sd->grp_id = mid;
pvr2_trace(PVR2_TRACE_INFO, "Attached sub-driver %s", fname);
switch (mid) {
case PVR2_CLIENT_ID_CX25840:
case PVR2_CLIENT_ID_SAA7115:
hdw->decoder_client_id = mid;
break;
default: break;
}
return 0;
}
static void pvr2_hdw_load_modules(struct pvr2_hdw *hdw)
{
unsigned int idx;
const struct pvr2_string_table *cm;
const struct pvr2_device_client_table *ct;
int okFl = !0;
cm = &hdw->hdw_desc->client_modules;
for (idx = 0; idx < cm->cnt; idx++) {
request_module(cm->lst[idx]);
}
ct = &hdw->hdw_desc->client_table;
for (idx = 0; idx < ct->cnt; idx++) {
if (pvr2_hdw_load_subdev(hdw, &ct->lst[idx]) < 0) okFl = 0;
}
if (!okFl) {
hdw->flag_modulefail = !0;
pvr2_hdw_render_useless(hdw);
}
}
static void pvr2_hdw_setup_low(struct pvr2_hdw *hdw)
{
int ret;
unsigned int idx;
struct pvr2_ctrl *cptr;
int reloadFl = 0;
if (hdw->hdw_desc->fx2_firmware.cnt) {
if (!reloadFl) {
reloadFl =
(hdw->usb_intf->cur_altsetting->desc.bNumEndpoints
== 0);
if (reloadFl) {
pvr2_trace(PVR2_TRACE_INIT,
"USB endpoint config looks strange"
"; possibly firmware needs to be"
" loaded");
}
}
if (!reloadFl) {
reloadFl = !pvr2_hdw_check_firmware(hdw);
if (reloadFl) {
pvr2_trace(PVR2_TRACE_INIT,
"Check for FX2 firmware failed"
"; possibly firmware needs to be"
" loaded");
}
}
if (reloadFl) {
if (pvr2_upload_firmware1(hdw) != 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failure uploading firmware1");
}
return;
}
}
hdw->fw1_state = FW1_STATE_OK;
if (!pvr2_hdw_dev_ok(hdw)) return;
hdw->force_dirty = !0;
if (!hdw->hdw_desc->flag_no_powerup) {
pvr2_hdw_cmd_powerup(hdw);
if (!pvr2_hdw_dev_ok(hdw)) return;
}
if (hdw->ir_scheme_active == PVR2_IR_SCHEME_ZILOG) {
pvr2_issue_simple_cmd(hdw,
FX2CMD_HCW_ZILOG_RESET |
(1 << 8) |
((0) << 16));
}
pvr2_i2c_core_init(hdw);
if (!pvr2_hdw_dev_ok(hdw)) return;
pvr2_hdw_load_modules(hdw);
if (!pvr2_hdw_dev_ok(hdw)) return;
v4l2_device_call_all(&hdw->v4l2_dev, 0, core, load_fw);
for (idx = 0; idx < CTRLDEF_COUNT; idx++) {
cptr = hdw->controls + idx;
if (cptr->info->skip_init) continue;
if (!cptr->info->set_value) continue;
cptr->info->set_value(cptr,~0,cptr->info->default_value);
}
pvr2_hdw_cx25840_vbi_hack(hdw);
hdw->freqValTelevision = default_tv_freq;
hdw->freqValRadio = default_radio_freq;
if (hdw->hdw_desc->flag_has_hauppauge_rom) {
ret = pvr2_hdw_get_eeprom_addr(hdw);
if (!pvr2_hdw_dev_ok(hdw)) return;
if (ret < 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Unable to determine location of eeprom,"
" skipping");
} else {
hdw->eeprom_addr = ret;
pvr2_eeprom_analyze(hdw);
if (!pvr2_hdw_dev_ok(hdw)) return;
}
} else {
hdw->tuner_type = hdw->hdw_desc->default_tuner_type;
hdw->tuner_updated = !0;
hdw->std_mask_eeprom = V4L2_STD_ALL;
}
if (hdw->serial_number) {
idx = scnprintf(hdw->identifier, sizeof(hdw->identifier) - 1,
"sn-%lu", hdw->serial_number);
} else if (hdw->unit_number >= 0) {
idx = scnprintf(hdw->identifier, sizeof(hdw->identifier) - 1,
"unit-%c",
hdw->unit_number + 'a');
} else {
idx = scnprintf(hdw->identifier, sizeof(hdw->identifier) - 1,
"unit-??");
}
hdw->identifier[idx] = 0;
pvr2_hdw_setup_std(hdw);
if (!get_default_tuner_type(hdw)) {
pvr2_trace(PVR2_TRACE_INIT,
"pvr2_hdw_setup: Tuner type overridden to %d",
hdw->tuner_type);
}
if (!pvr2_hdw_dev_ok(hdw)) return;
if (hdw->hdw_desc->signal_routing_scheme ==
PVR2_ROUTING_SCHEME_GOTVIEW) {
pvr2_hdw_gpio_chg_dir(hdw,(1 << 11),~0);
}
pvr2_hdw_commit_setup(hdw);
hdw->vid_stream = pvr2_stream_create();
if (!pvr2_hdw_dev_ok(hdw)) return;
pvr2_trace(PVR2_TRACE_INIT,
"pvr2_hdw_setup: video stream is %p",hdw->vid_stream);
if (hdw->vid_stream) {
idx = get_default_error_tolerance(hdw);
if (idx) {
pvr2_trace(PVR2_TRACE_INIT,
"pvr2_hdw_setup: video stream %p"
" setting tolerance %u",
hdw->vid_stream,idx);
}
pvr2_stream_setup(hdw->vid_stream,hdw->usb_dev,
PVR2_VID_ENDPOINT,idx);
}
if (!pvr2_hdw_dev_ok(hdw)) return;
hdw->flag_init_ok = !0;
pvr2_hdw_state_sched(hdw);
}
static void pvr2_hdw_setup(struct pvr2_hdw *hdw)
{
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_setup(hdw=%p) begin",hdw);
do {
pvr2_hdw_setup_low(hdw);
pvr2_trace(PVR2_TRACE_INIT,
"pvr2_hdw_setup(hdw=%p) done, ok=%d init_ok=%d",
hdw,pvr2_hdw_dev_ok(hdw),hdw->flag_init_ok);
if (pvr2_hdw_dev_ok(hdw)) {
if (hdw->flag_init_ok) {
pvr2_trace(
PVR2_TRACE_INFO,
"Device initialization"
" completed successfully.");
break;
}
if (hdw->fw1_state == FW1_STATE_RELOAD) {
pvr2_trace(
PVR2_TRACE_INFO,
"Device microcontroller firmware"
" (re)loaded; it should now reset"
" and reconnect.");
break;
}
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Device initialization was not successful.");
if (hdw->fw1_state == FW1_STATE_MISSING) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Giving up since device"
" microcontroller firmware"
" appears to be missing.");
break;
}
}
if (hdw->flag_modulefail) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"***WARNING*** pvrusb2 driver initialization"
" failed due to the failure of one or more"
" sub-device kernel modules.");
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"You need to resolve the failing condition"
" before this driver can function. There"
" should be some earlier messages giving more"
" information about the problem.");
break;
}
if (procreload) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Attempting pvrusb2 recovery by reloading"
" primary firmware.");
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"If this works, device should disconnect"
" and reconnect in a sane state.");
hdw->fw1_state = FW1_STATE_UNKNOWN;
pvr2_upload_firmware1(hdw);
} else {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"***WARNING*** pvrusb2 device hardware"
" appears to be jammed"
" and I can't clear it.");
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"You might need to power cycle"
" the pvrusb2 device"
" in order to recover.");
}
} while (0);
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_setup(hdw=%p) end",hdw);
}
int pvr2_hdw_initialize(struct pvr2_hdw *hdw,
void (*callback_func)(void *),
void *callback_data)
{
LOCK_TAKE(hdw->big_lock); do {
if (hdw->flag_disconnected) {
break;
}
hdw->state_data = callback_data;
hdw->state_func = callback_func;
pvr2_hdw_setup(hdw);
} while (0); LOCK_GIVE(hdw->big_lock);
return hdw->flag_init_ok;
}
struct pvr2_hdw *pvr2_hdw_create(struct usb_interface *intf,
const struct usb_device_id *devid)
{
unsigned int idx,cnt1,cnt2,m;
struct pvr2_hdw *hdw = NULL;
int valid_std_mask;
struct pvr2_ctrl *cptr;
struct usb_device *usb_dev;
const struct pvr2_device_desc *hdw_desc;
__u8 ifnum;
struct v4l2_queryctrl qctrl;
struct pvr2_ctl_info *ciptr;
usb_dev = interface_to_usbdev(intf);
hdw_desc = (const struct pvr2_device_desc *)(devid->driver_info);
if (hdw_desc == NULL) {
pvr2_trace(PVR2_TRACE_INIT, "pvr2_hdw_create:"
" No device description pointer,"
" unable to continue.");
pvr2_trace(PVR2_TRACE_INIT, "If you have a new device type,"
" please contact Mike Isely <isely@pobox.com>"
" to get it included in the driver\n");
goto fail;
}
hdw = kzalloc(sizeof(*hdw),GFP_KERNEL);
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_create: hdw=%p, type \"%s\"",
hdw,hdw_desc->description);
pvr2_trace(PVR2_TRACE_INFO, "Hardware description: %s",
hdw_desc->description);
if (hdw_desc->flag_is_experimental) {
pvr2_trace(PVR2_TRACE_INFO, "**********");
pvr2_trace(PVR2_TRACE_INFO,
"WARNING: Support for this device (%s) is"
" experimental.", hdw_desc->description);
pvr2_trace(PVR2_TRACE_INFO,
"Important functionality might not be"
" entirely working.");
pvr2_trace(PVR2_TRACE_INFO,
"Please consider contacting the driver author to"
" help with further stabilization of the driver.");
pvr2_trace(PVR2_TRACE_INFO, "**********");
}
if (!hdw) goto fail;
init_timer(&hdw->quiescent_timer);
hdw->quiescent_timer.data = (unsigned long)hdw;
hdw->quiescent_timer.function = pvr2_hdw_quiescent_timeout;
init_timer(&hdw->decoder_stabilization_timer);
hdw->decoder_stabilization_timer.data = (unsigned long)hdw;
hdw->decoder_stabilization_timer.function =
pvr2_hdw_decoder_stabilization_timeout;
init_timer(&hdw->encoder_wait_timer);
hdw->encoder_wait_timer.data = (unsigned long)hdw;
hdw->encoder_wait_timer.function = pvr2_hdw_encoder_wait_timeout;
init_timer(&hdw->encoder_run_timer);
hdw->encoder_run_timer.data = (unsigned long)hdw;
hdw->encoder_run_timer.function = pvr2_hdw_encoder_run_timeout;
hdw->master_state = PVR2_STATE_DEAD;
init_waitqueue_head(&hdw->state_wait_data);
hdw->tuner_signal_stale = !0;
cx2341x_fill_defaults(&hdw->enc_ctl_state);
m = 0;
if (hdw_desc->flag_has_analogtuner) m |= 1 << PVR2_CVAL_INPUT_TV;
if (hdw_desc->digital_control_scheme != PVR2_DIGITAL_SCHEME_NONE) {
m |= 1 << PVR2_CVAL_INPUT_DTV;
}
if (hdw_desc->flag_has_svideo) m |= 1 << PVR2_CVAL_INPUT_SVIDEO;
if (hdw_desc->flag_has_composite) m |= 1 << PVR2_CVAL_INPUT_COMPOSITE;
if (hdw_desc->flag_has_fmradio) m |= 1 << PVR2_CVAL_INPUT_RADIO;
hdw->input_avail_mask = m;
hdw->input_allowed_mask = hdw->input_avail_mask;
if (!(hdw->input_avail_mask & (1 << PVR2_CVAL_INPUT_DTV))) {
hdw->pathway_state = PVR2_PATHWAY_ANALOG;
} else if (!(hdw->input_avail_mask & (1 << PVR2_CVAL_INPUT_TV))) {
hdw->pathway_state = PVR2_PATHWAY_DIGITAL;
}
hdw->control_cnt = CTRLDEF_COUNT;
hdw->control_cnt += MPEGDEF_COUNT;
hdw->controls = kzalloc(sizeof(struct pvr2_ctrl) * hdw->control_cnt,
GFP_KERNEL);
if (!hdw->controls) goto fail;
hdw->hdw_desc = hdw_desc;
hdw->ir_scheme_active = hdw->hdw_desc->ir_scheme;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
cptr->hdw = hdw;
}
for (idx = 0; idx < 32; idx++) {
hdw->std_mask_ptrs[idx] = hdw->std_mask_names[idx];
}
for (idx = 0; idx < CTRLDEF_COUNT; idx++) {
cptr = hdw->controls + idx;
cptr->info = control_defs+idx;
}
m = hdw->input_avail_mask;
if (m) for (idx = 0; idx < (sizeof(m) << 3); idx++) {
if (!((1 << idx) & m)) continue;
hdw->input_val = idx;
break;
}
hdw->mpeg_ctrl_info = kzalloc(
sizeof(*(hdw->mpeg_ctrl_info)) * MPEGDEF_COUNT, GFP_KERNEL);
if (!hdw->mpeg_ctrl_info) goto fail;
for (idx = 0; idx < MPEGDEF_COUNT; idx++) {
cptr = hdw->controls + idx + CTRLDEF_COUNT;
ciptr = &(hdw->mpeg_ctrl_info[idx].info);
ciptr->desc = hdw->mpeg_ctrl_info[idx].desc;
ciptr->name = mpeg_ids[idx].strid;
ciptr->v4l_id = mpeg_ids[idx].id;
ciptr->skip_init = !0;
ciptr->get_value = ctrl_cx2341x_get;
ciptr->get_v4lflags = ctrl_cx2341x_getv4lflags;
ciptr->is_dirty = ctrl_cx2341x_is_dirty;
if (!idx) ciptr->clear_dirty = ctrl_cx2341x_clear_dirty;
qctrl.id = ciptr->v4l_id;
cx2341x_ctrl_query(&hdw->enc_ctl_state,&qctrl);
if (!(qctrl.flags & V4L2_CTRL_FLAG_READ_ONLY)) {
ciptr->set_value = ctrl_cx2341x_set;
}
strncpy(hdw->mpeg_ctrl_info[idx].desc,qctrl.name,
PVR2_CTLD_INFO_DESC_SIZE);
hdw->mpeg_ctrl_info[idx].desc[PVR2_CTLD_INFO_DESC_SIZE-1] = 0;
ciptr->default_value = qctrl.default_value;
switch (qctrl.type) {
default:
case V4L2_CTRL_TYPE_INTEGER:
ciptr->type = pvr2_ctl_int;
ciptr->def.type_int.min_value = qctrl.minimum;
ciptr->def.type_int.max_value = qctrl.maximum;
break;
case V4L2_CTRL_TYPE_BOOLEAN:
ciptr->type = pvr2_ctl_bool;
break;
case V4L2_CTRL_TYPE_MENU:
ciptr->type = pvr2_ctl_enum;
ciptr->def.type_enum.value_names =
cx2341x_ctrl_get_menu(&hdw->enc_ctl_state,
ciptr->v4l_id);
for (cnt1 = 0;
ciptr->def.type_enum.value_names[cnt1] != NULL;
cnt1++) { }
ciptr->def.type_enum.count = cnt1;
break;
}
cptr->info = ciptr;
}
cptr = pvr2_hdw_get_ctrl_by_id(hdw,PVR2_CID_STDENUM);
if (cptr) {
memcpy(&hdw->std_info_enum,cptr->info,
sizeof(hdw->std_info_enum));
cptr->info = &hdw->std_info_enum;
}
valid_std_mask = pvr2_std_get_usable();
for (idx = 0; idx < 32; idx++) {
if (!(valid_std_mask & (1 << idx))) continue;
cnt1 = pvr2_std_id_to_str(
hdw->std_mask_names[idx],
sizeof(hdw->std_mask_names[idx])-1,
1 << idx);
hdw->std_mask_names[idx][cnt1] = 0;
}
cptr = pvr2_hdw_get_ctrl_by_id(hdw,PVR2_CID_STDAVAIL);
if (cptr) {
memcpy(&hdw->std_info_avail,cptr->info,
sizeof(hdw->std_info_avail));
cptr->info = &hdw->std_info_avail;
hdw->std_info_avail.def.type_bitmask.bit_names =
hdw->std_mask_ptrs;
hdw->std_info_avail.def.type_bitmask.valid_bits =
valid_std_mask;
}
cptr = pvr2_hdw_get_ctrl_by_id(hdw,PVR2_CID_STDCUR);
if (cptr) {
memcpy(&hdw->std_info_cur,cptr->info,
sizeof(hdw->std_info_cur));
cptr->info = &hdw->std_info_cur;
hdw->std_info_cur.def.type_bitmask.bit_names =
hdw->std_mask_ptrs;
hdw->std_info_avail.def.type_bitmask.valid_bits =
valid_std_mask;
}
hdw->cropcap_stale = !0;
hdw->eeprom_addr = -1;
hdw->unit_number = -1;
hdw->v4l_minor_number_video = -1;
hdw->v4l_minor_number_vbi = -1;
hdw->v4l_minor_number_radio = -1;
hdw->ctl_write_buffer = kmalloc(PVR2_CTL_BUFFSIZE,GFP_KERNEL);
if (!hdw->ctl_write_buffer) goto fail;
hdw->ctl_read_buffer = kmalloc(PVR2_CTL_BUFFSIZE,GFP_KERNEL);
if (!hdw->ctl_read_buffer) goto fail;
hdw->ctl_write_urb = usb_alloc_urb(0,GFP_KERNEL);
if (!hdw->ctl_write_urb) goto fail;
hdw->ctl_read_urb = usb_alloc_urb(0,GFP_KERNEL);
if (!hdw->ctl_read_urb) goto fail;
if (v4l2_device_register(&intf->dev, &hdw->v4l2_dev) != 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Error registering with v4l core, giving up");
goto fail;
}
mutex_lock(&pvr2_unit_mtx); do {
for (idx = 0; idx < PVR_NUM; idx++) {
if (unit_pointers[idx]) continue;
hdw->unit_number = idx;
unit_pointers[idx] = hdw;
break;
}
} while (0); mutex_unlock(&pvr2_unit_mtx);
cnt1 = 0;
cnt2 = scnprintf(hdw->name+cnt1,sizeof(hdw->name)-cnt1,"pvrusb2");
cnt1 += cnt2;
if (hdw->unit_number >= 0) {
cnt2 = scnprintf(hdw->name+cnt1,sizeof(hdw->name)-cnt1,"_%c",
('a' + hdw->unit_number));
cnt1 += cnt2;
}
if (cnt1 >= sizeof(hdw->name)) cnt1 = sizeof(hdw->name)-1;
hdw->name[cnt1] = 0;
hdw->workqueue = create_singlethread_workqueue(hdw->name);
INIT_WORK(&hdw->workpoll,pvr2_hdw_worker_poll);
pvr2_trace(PVR2_TRACE_INIT,"Driver unit number is %d, name is %s",
hdw->unit_number,hdw->name);
hdw->tuner_type = -1;
hdw->flag_ok = !0;
hdw->usb_intf = intf;
hdw->usb_dev = usb_dev;
usb_make_path(hdw->usb_dev, hdw->bus_info, sizeof(hdw->bus_info));
ifnum = hdw->usb_intf->cur_altsetting->desc.bInterfaceNumber;
usb_set_interface(hdw->usb_dev,ifnum,0);
mutex_init(&hdw->ctl_lock_mutex);
mutex_init(&hdw->big_lock_mutex);
return hdw;
fail:
if (hdw) {
del_timer_sync(&hdw->quiescent_timer);
del_timer_sync(&hdw->decoder_stabilization_timer);
del_timer_sync(&hdw->encoder_run_timer);
del_timer_sync(&hdw->encoder_wait_timer);
if (hdw->workqueue) {
flush_workqueue(hdw->workqueue);
destroy_workqueue(hdw->workqueue);
hdw->workqueue = NULL;
}
usb_free_urb(hdw->ctl_read_urb);
usb_free_urb(hdw->ctl_write_urb);
kfree(hdw->ctl_read_buffer);
kfree(hdw->ctl_write_buffer);
kfree(hdw->controls);
kfree(hdw->mpeg_ctrl_info);
kfree(hdw->std_defs);
kfree(hdw->std_enum_names);
kfree(hdw);
}
return NULL;
}
static void pvr2_hdw_remove_usb_stuff(struct pvr2_hdw *hdw)
{
if (hdw->flag_disconnected) return;
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_remove_usb_stuff: hdw=%p",hdw);
if (hdw->ctl_read_urb) {
usb_kill_urb(hdw->ctl_read_urb);
usb_free_urb(hdw->ctl_read_urb);
hdw->ctl_read_urb = NULL;
}
if (hdw->ctl_write_urb) {
usb_kill_urb(hdw->ctl_write_urb);
usb_free_urb(hdw->ctl_write_urb);
hdw->ctl_write_urb = NULL;
}
if (hdw->ctl_read_buffer) {
kfree(hdw->ctl_read_buffer);
hdw->ctl_read_buffer = NULL;
}
if (hdw->ctl_write_buffer) {
kfree(hdw->ctl_write_buffer);
hdw->ctl_write_buffer = NULL;
}
hdw->flag_disconnected = !0;
v4l2_device_disconnect(&hdw->v4l2_dev);
hdw->usb_dev = NULL;
hdw->usb_intf = NULL;
pvr2_hdw_render_useless(hdw);
}
void pvr2_hdw_destroy(struct pvr2_hdw *hdw)
{
if (!hdw) return;
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_destroy: hdw=%p",hdw);
if (hdw->workqueue) {
flush_workqueue(hdw->workqueue);
destroy_workqueue(hdw->workqueue);
hdw->workqueue = NULL;
}
del_timer_sync(&hdw->quiescent_timer);
del_timer_sync(&hdw->decoder_stabilization_timer);
del_timer_sync(&hdw->encoder_run_timer);
del_timer_sync(&hdw->encoder_wait_timer);
if (hdw->fw_buffer) {
kfree(hdw->fw_buffer);
hdw->fw_buffer = NULL;
}
if (hdw->vid_stream) {
pvr2_stream_destroy(hdw->vid_stream);
hdw->vid_stream = NULL;
}
pvr2_i2c_core_done(hdw);
v4l2_device_unregister(&hdw->v4l2_dev);
pvr2_hdw_remove_usb_stuff(hdw);
mutex_lock(&pvr2_unit_mtx); do {
if ((hdw->unit_number >= 0) &&
(hdw->unit_number < PVR_NUM) &&
(unit_pointers[hdw->unit_number] == hdw)) {
unit_pointers[hdw->unit_number] = NULL;
}
} while (0); mutex_unlock(&pvr2_unit_mtx);
kfree(hdw->controls);
kfree(hdw->mpeg_ctrl_info);
kfree(hdw->std_defs);
kfree(hdw->std_enum_names);
kfree(hdw);
}
int pvr2_hdw_dev_ok(struct pvr2_hdw *hdw)
{
return (hdw && hdw->flag_ok);
}
void pvr2_hdw_disconnect(struct pvr2_hdw *hdw)
{
pvr2_trace(PVR2_TRACE_INIT,"pvr2_hdw_disconnect(hdw=%p)",hdw);
LOCK_TAKE(hdw->big_lock);
LOCK_TAKE(hdw->ctl_lock);
pvr2_hdw_remove_usb_stuff(hdw);
LOCK_GIVE(hdw->ctl_lock);
LOCK_GIVE(hdw->big_lock);
}
static void pvr2_hdw_internal_find_stdenum(struct pvr2_hdw *hdw)
{
unsigned int idx;
for (idx = 1; idx < hdw->std_enum_cnt; idx++) {
if (hdw->std_defs[idx-1].id == hdw->std_mask_cur) {
hdw->std_enum_cur = idx;
return;
}
}
hdw->std_enum_cur = 0;
}
static void pvr2_hdw_internal_set_std_avail(struct pvr2_hdw *hdw)
{
struct v4l2_standard *newstd;
unsigned int std_cnt;
unsigned int idx;
newstd = pvr2_std_create_enum(&std_cnt,hdw->std_mask_avail);
if (hdw->std_defs) {
kfree(hdw->std_defs);
hdw->std_defs = NULL;
}
hdw->std_enum_cnt = 0;
if (hdw->std_enum_names) {
kfree(hdw->std_enum_names);
hdw->std_enum_names = NULL;
}
if (!std_cnt) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"WARNING: Failed to identify any viable standards");
}
hdw->std_enum_names = kmalloc(sizeof(char *)*(std_cnt+1),GFP_KERNEL);
if (hdw->std_enum_names) {
hdw->std_enum_names[0] = "none";
for (idx = 0; idx < std_cnt; idx++)
hdw->std_enum_names[idx+1] = newstd[idx].name;
hdw->std_info_enum.def.type_enum.value_names =
hdw->std_enum_names;
hdw->std_info_enum.def.type_enum.count = std_cnt+1;
} else {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"WARNING: Failed to alloc memory for names");
hdw->std_info_enum.def.type_enum.value_names = NULL;
hdw->std_info_enum.def.type_enum.count = 0;
}
hdw->std_defs = newstd;
hdw->std_enum_cnt = std_cnt+1;
hdw->std_enum_cur = 0;
hdw->std_info_cur.def.type_bitmask.valid_bits = hdw->std_mask_avail;
}
int pvr2_hdw_get_stdenum_value(struct pvr2_hdw *hdw,
struct v4l2_standard *std,
unsigned int idx)
{
int ret = -EINVAL;
if (!idx) return ret;
LOCK_TAKE(hdw->big_lock); do {
if (idx >= hdw->std_enum_cnt) break;
idx--;
memcpy(std,hdw->std_defs+idx,sizeof(*std));
ret = 0;
} while (0); LOCK_GIVE(hdw->big_lock);
return ret;
}
unsigned int pvr2_hdw_get_ctrl_count(struct pvr2_hdw *hdw)
{
return hdw->control_cnt;
}
struct pvr2_ctrl *pvr2_hdw_get_ctrl_by_index(struct pvr2_hdw *hdw,
unsigned int idx)
{
if (idx >= hdw->control_cnt) return NULL;
return hdw->controls + idx;
}
struct pvr2_ctrl *pvr2_hdw_get_ctrl_by_id(struct pvr2_hdw *hdw,
unsigned int ctl_id)
{
struct pvr2_ctrl *cptr;
unsigned int idx;
int i;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
i = cptr->info->internal_id;
if (i && (i == ctl_id)) return cptr;
}
return NULL;
}
struct pvr2_ctrl *pvr2_hdw_get_ctrl_v4l(struct pvr2_hdw *hdw,unsigned int ctl_id)
{
struct pvr2_ctrl *cptr;
unsigned int idx;
int i;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
i = cptr->info->v4l_id;
if (i && (i == ctl_id)) return cptr;
}
return NULL;
}
struct pvr2_ctrl *pvr2_hdw_get_ctrl_nextv4l(struct pvr2_hdw *hdw,
unsigned int ctl_id)
{
struct pvr2_ctrl *cptr,*cp2;
unsigned int idx;
int i;
cp2 = NULL;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
i = cptr->info->v4l_id;
if (!i) continue;
if (i <= ctl_id) continue;
if (cp2 && (cp2->info->v4l_id < i)) continue;
cp2 = cptr;
}
return cp2;
return NULL;
}
static const char *get_ctrl_typename(enum pvr2_ctl_type tp)
{
switch (tp) {
case pvr2_ctl_int: return "integer";
case pvr2_ctl_enum: return "enum";
case pvr2_ctl_bool: return "boolean";
case pvr2_ctl_bitmask: return "bitmask";
}
return "";
}
static void pvr2_subdev_set_control(struct pvr2_hdw *hdw, int id,
const char *name, int val)
{
struct v4l2_control ctrl;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 %s=%d", name, val);
memset(&ctrl, 0, sizeof(ctrl));
ctrl.id = id;
ctrl.value = val;
v4l2_device_call_all(&hdw->v4l2_dev, 0, core, s_ctrl, &ctrl);
}
static void pvr2_subdev_update(struct pvr2_hdw *hdw)
{
struct v4l2_subdev *sd;
unsigned int id;
pvr2_subdev_update_func fp;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev update...");
if (hdw->tuner_updated || hdw->force_dirty) {
struct tuner_setup setup;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev tuner set_type(%d)",
hdw->tuner_type);
if (((int)(hdw->tuner_type)) >= 0) {
memset(&setup, 0, sizeof(setup));
setup.addr = ADDR_UNSET;
setup.type = hdw->tuner_type;
setup.mode_mask = T_RADIO | T_ANALOG_TV;
v4l2_device_call_all(&hdw->v4l2_dev, 0,
tuner, s_type_addr, &setup);
}
}
if (hdw->input_dirty || hdw->std_dirty || hdw->force_dirty) {
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 set_standard");
if (hdw->input_val == PVR2_CVAL_INPUT_RADIO) {
v4l2_device_call_all(&hdw->v4l2_dev, 0,
tuner, s_radio);
} else {
v4l2_std_id vs;
vs = hdw->std_mask_cur;
v4l2_device_call_all(&hdw->v4l2_dev, 0,
core, s_std, vs);
pvr2_hdw_cx25840_vbi_hack(hdw);
}
hdw->tuner_signal_stale = !0;
hdw->cropcap_stale = !0;
}
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_BRIGHTNESS, brightness);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_CONTRAST, contrast);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_SATURATION, saturation);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_HUE, hue);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_AUDIO_MUTE, mute);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_AUDIO_VOLUME, volume);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_AUDIO_BALANCE, balance);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_AUDIO_BASS, bass);
PVR2_SUBDEV_SET_CONTROL(hdw, V4L2_CID_AUDIO_TREBLE, treble);
if (hdw->input_dirty || hdw->audiomode_dirty || hdw->force_dirty) {
struct v4l2_tuner vt;
memset(&vt, 0, sizeof(vt));
vt.type = (hdw->input_val == PVR2_CVAL_INPUT_RADIO) ?
V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
vt.audmode = hdw->audiomode_val;
v4l2_device_call_all(&hdw->v4l2_dev, 0, tuner, s_tuner, &vt);
}
if (hdw->freqDirty || hdw->force_dirty) {
unsigned long fv;
struct v4l2_frequency freq;
fv = pvr2_hdw_get_cur_freq(hdw);
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 set_freq(%lu)", fv);
if (hdw->tuner_signal_stale) pvr2_hdw_status_poll(hdw);
memset(&freq, 0, sizeof(freq));
if (hdw->tuner_signal_info.capability & V4L2_TUNER_CAP_LOW) {
freq.frequency = (fv * 2) / 125;
} else {
freq.frequency = fv / 62500;
}
if (hdw->input_val == PVR2_CVAL_INPUT_RADIO) {
freq.type = V4L2_TUNER_RADIO;
} else {
freq.type = V4L2_TUNER_ANALOG_TV;
}
freq.tuner = 0;
v4l2_device_call_all(&hdw->v4l2_dev, 0, tuner,
s_frequency, &freq);
}
if (hdw->res_hor_dirty || hdw->res_ver_dirty || hdw->force_dirty) {
struct v4l2_mbus_framefmt fmt;
memset(&fmt, 0, sizeof(fmt));
fmt.width = hdw->res_hor_val;
fmt.height = hdw->res_ver_val;
fmt.code = V4L2_MBUS_FMT_FIXED;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 set_size(%dx%d)",
fmt.width, fmt.height);
v4l2_device_call_all(&hdw->v4l2_dev, 0, video, s_mbus_fmt, &fmt);
}
if (hdw->srate_dirty || hdw->force_dirty) {
u32 val;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev v4l2 set_audio %d",
hdw->srate_val);
switch (hdw->srate_val) {
default:
case V4L2_MPEG_AUDIO_SAMPLING_FREQ_48000:
val = 48000;
break;
case V4L2_MPEG_AUDIO_SAMPLING_FREQ_44100:
val = 44100;
break;
case V4L2_MPEG_AUDIO_SAMPLING_FREQ_32000:
val = 32000;
break;
}
v4l2_device_call_all(&hdw->v4l2_dev, 0,
audio, s_clock_freq, val);
}
v4l2_device_for_each_subdev(sd, &hdw->v4l2_dev) {
id = sd->grp_id;
if (id >= ARRAY_SIZE(pvr2_module_update_functions)) continue;
fp = pvr2_module_update_functions[id];
if (!fp) continue;
(*fp)(hdw, sd);
}
if (hdw->tuner_signal_stale || hdw->cropcap_stale) {
pvr2_hdw_status_poll(hdw);
}
}
static int pvr2_hdw_commit_setup(struct pvr2_hdw *hdw)
{
unsigned int idx;
struct pvr2_ctrl *cptr;
int value;
int commit_flag = hdw->force_dirty;
char buf[100];
unsigned int bcnt,ccnt;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
if (!cptr->info->is_dirty) continue;
if (!cptr->info->is_dirty(cptr)) continue;
commit_flag = !0;
if (!(pvrusb2_debug & PVR2_TRACE_CTL)) continue;
bcnt = scnprintf(buf,sizeof(buf),"\"%s\" <-- ",
cptr->info->name);
value = 0;
cptr->info->get_value(cptr,&value);
pvr2_ctrl_value_to_sym_internal(cptr,~0,value,
buf+bcnt,
sizeof(buf)-bcnt,&ccnt);
bcnt += ccnt;
bcnt += scnprintf(buf+bcnt,sizeof(buf)-bcnt," <%s>",
get_ctrl_typename(cptr->info->type));
pvr2_trace(PVR2_TRACE_CTL,
"/*--TRACE_COMMIT--*/ %.*s",
bcnt,buf);
}
if (!commit_flag) {
return 0;
}
hdw->state_pipeline_config = 0;
trace_stbit("state_pipeline_config",hdw->state_pipeline_config);
pvr2_hdw_state_sched(hdw);
return !0;
}
static int pvr2_hdw_commit_execute(struct pvr2_hdw *hdw)
{
unsigned int idx;
struct pvr2_ctrl *cptr;
int disruptive_change;
if (hdw->input_dirty && hdw->state_pathway_ok &&
(((hdw->input_val == PVR2_CVAL_INPUT_DTV) ?
PVR2_PATHWAY_DIGITAL : PVR2_PATHWAY_ANALOG) !=
hdw->pathway_state)) {
hdw->state_pathway_ok = 0;
trace_stbit("state_pathway_ok", hdw->state_pathway_ok);
}
if (!hdw->state_pathway_ok) {
return 0;
}
if (hdw->std_dirty) {
int nvres;
int gop_size;
if (hdw->std_mask_cur & V4L2_STD_525_60) {
nvres = 480;
gop_size = 15;
} else {
nvres = 576;
gop_size = 12;
}
if (nvres != hdw->res_ver_val) {
hdw->res_ver_val = nvres;
hdw->res_ver_dirty = !0;
}
if (gop_size != hdw->enc_ctl_state.video_gop_size) {
struct v4l2_ext_controls cs;
struct v4l2_ext_control c1;
memset(&cs, 0, sizeof(cs));
memset(&c1, 0, sizeof(c1));
cs.controls = &c1;
cs.count = 1;
c1.id = V4L2_CID_MPEG_VIDEO_GOP_SIZE;
c1.value = gop_size;
cx2341x_ext_ctrls(&hdw->enc_ctl_state, 0, &cs,
VIDIOC_S_EXT_CTRLS);
}
}
if (hdw->res_hor_dirty && hdw->cropw_val < hdw->res_hor_val) {
hdw->cropw_val = hdw->res_hor_val;
hdw->cropw_dirty = !0;
} else if (hdw->cropw_dirty) {
hdw->res_hor_dirty = !0;
hdw->res_hor_val = min(720, hdw->cropw_val);
}
if (hdw->res_ver_dirty && hdw->croph_val < hdw->res_ver_val) {
hdw->croph_val = hdw->res_ver_val;
hdw->croph_dirty = !0;
} else if (hdw->croph_dirty) {
int nvres = hdw->std_mask_cur & V4L2_STD_525_60 ? 480 : 576;
hdw->res_ver_dirty = !0;
hdw->res_ver_val = min(nvres, hdw->croph_val);
}
disruptive_change =
(hdw->std_dirty ||
hdw->enc_unsafe_stale ||
hdw->srate_dirty ||
hdw->res_ver_dirty ||
hdw->res_hor_dirty ||
hdw->cropw_dirty ||
hdw->croph_dirty ||
hdw->input_dirty ||
(hdw->active_stream_type != hdw->desired_stream_type));
if (disruptive_change && !hdw->state_pipeline_idle) {
hdw->state_pipeline_pause = !0;
return 0;
}
if (hdw->srate_dirty) {
struct v4l2_ext_controls cs;
struct v4l2_ext_control c1;
memset(&cs,0,sizeof(cs));
memset(&c1,0,sizeof(c1));
cs.controls = &c1;
cs.count = 1;
c1.id = V4L2_CID_MPEG_AUDIO_SAMPLING_FREQ;
c1.value = hdw->srate_val;
cx2341x_ext_ctrls(&hdw->enc_ctl_state, 0, &cs,VIDIOC_S_EXT_CTRLS);
}
if (hdw->active_stream_type != hdw->desired_stream_type) {
hdw->active_stream_type = hdw->desired_stream_type;
}
if (hdw->hdw_desc->signal_routing_scheme ==
PVR2_ROUTING_SCHEME_GOTVIEW) {
u32 b;
pvr2_hdw_gpio_get_out(hdw,&b);
if (hdw->input_val == PVR2_CVAL_INPUT_RADIO) {
pvr2_hdw_gpio_chg_out(hdw,(1 << 11),~0);
} else {
pvr2_hdw_gpio_chg_out(hdw,(1 << 11),0);
}
}
pvr2_subdev_update(hdw);
hdw->tuner_updated = 0;
hdw->force_dirty = 0;
for (idx = 0; idx < hdw->control_cnt; idx++) {
cptr = hdw->controls + idx;
if (!cptr->info->clear_dirty) continue;
cptr->info->clear_dirty(cptr);
}
if ((hdw->pathway_state == PVR2_PATHWAY_ANALOG) &&
hdw->state_encoder_run) {
if (pvr2_encoder_adjust(hdw) < 0) return !0;
}
hdw->state_pipeline_config = !0;
trace_stbit("state_pipeline_config",hdw->state_pipeline_config);
return !0;
}
int pvr2_hdw_commit_ctl(struct pvr2_hdw *hdw)
{
int fl;
LOCK_TAKE(hdw->big_lock);
fl = pvr2_hdw_commit_setup(hdw);
LOCK_GIVE(hdw->big_lock);
if (!fl) return 0;
return pvr2_hdw_wait(hdw,0);
}
static void pvr2_hdw_worker_poll(struct work_struct *work)
{
int fl = 0;
struct pvr2_hdw *hdw = container_of(work,struct pvr2_hdw,workpoll);
LOCK_TAKE(hdw->big_lock); do {
fl = pvr2_hdw_state_eval(hdw);
} while (0); LOCK_GIVE(hdw->big_lock);
if (fl && hdw->state_func) {
hdw->state_func(hdw->state_data);
}
}
static int pvr2_hdw_wait(struct pvr2_hdw *hdw,int state)
{
return wait_event_interruptible(
hdw->state_wait_data,
(hdw->state_stale == 0) &&
(!state || (hdw->master_state != state)));
}
const char *pvr2_hdw_get_driver_name(struct pvr2_hdw *hdw)
{
return hdw->name;
}
const char *pvr2_hdw_get_desc(struct pvr2_hdw *hdw)
{
return hdw->hdw_desc->description;
}
const char *pvr2_hdw_get_type(struct pvr2_hdw *hdw)
{
return hdw->hdw_desc->shortname;
}
int pvr2_hdw_is_hsm(struct pvr2_hdw *hdw)
{
int result;
LOCK_TAKE(hdw->ctl_lock); do {
hdw->cmd_buffer[0] = FX2CMD_GET_USB_SPEED;
result = pvr2_send_request(hdw,
hdw->cmd_buffer,1,
hdw->cmd_buffer,1);
if (result < 0) break;
result = (hdw->cmd_buffer[0] != 0);
} while(0); LOCK_GIVE(hdw->ctl_lock);
return result;
}
void pvr2_hdw_execute_tuner_poll(struct pvr2_hdw *hdw)
{
LOCK_TAKE(hdw->big_lock); do {
pvr2_hdw_status_poll(hdw);
} while (0); LOCK_GIVE(hdw->big_lock);
}
static int pvr2_hdw_check_cropcap(struct pvr2_hdw *hdw)
{
if (!hdw->cropcap_stale) {
return 0;
}
pvr2_hdw_status_poll(hdw);
if (hdw->cropcap_stale) {
return -EIO;
}
return 0;
}
int pvr2_hdw_get_cropcap(struct pvr2_hdw *hdw, struct v4l2_cropcap *pp)
{
int stat = 0;
LOCK_TAKE(hdw->big_lock);
stat = pvr2_hdw_check_cropcap(hdw);
if (!stat) {
memcpy(pp, &hdw->cropcap_info, sizeof(hdw->cropcap_info));
}
LOCK_GIVE(hdw->big_lock);
return stat;
}
int pvr2_hdw_get_tuner_status(struct pvr2_hdw *hdw,struct v4l2_tuner *vtp)
{
LOCK_TAKE(hdw->big_lock); do {
if (hdw->tuner_signal_stale) {
pvr2_hdw_status_poll(hdw);
}
memcpy(vtp,&hdw->tuner_signal_info,sizeof(struct v4l2_tuner));
} while (0); LOCK_GIVE(hdw->big_lock);
return 0;
}
struct pvr2_stream *pvr2_hdw_get_video_stream(struct pvr2_hdw *hp)
{
return hp->vid_stream;
}
void pvr2_hdw_trigger_module_log(struct pvr2_hdw *hdw)
{
int nr = pvr2_hdw_get_unit_number(hdw);
LOCK_TAKE(hdw->big_lock); do {
printk(KERN_INFO "pvrusb2: ================= START STATUS CARD #%d =================\n", nr);
v4l2_device_call_all(&hdw->v4l2_dev, 0, core, log_status);
pvr2_trace(PVR2_TRACE_INFO,"cx2341x config:");
cx2341x_log_status(&hdw->enc_ctl_state, "pvrusb2");
pvr2_hdw_state_log_state(hdw);
printk(KERN_INFO "pvrusb2: ================== END STATUS CARD #%d ==================\n", nr);
} while (0); LOCK_GIVE(hdw->big_lock);
}
static u8 *pvr2_full_eeprom_fetch(struct pvr2_hdw *hdw)
{
struct i2c_msg msg[2];
u8 *eeprom;
u8 iadd[2];
u8 addr;
u16 eepromSize;
unsigned int offs;
int ret;
int mode16 = 0;
unsigned pcnt,tcnt;
eeprom = kmalloc(EEPROM_SIZE,GFP_KERNEL);
if (!eeprom) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to allocate memory"
" required to read eeprom");
return NULL;
}
trace_eeprom("Value for eeprom addr from controller was 0x%x",
hdw->eeprom_addr);
addr = hdw->eeprom_addr;
if (addr & 0x80) addr >>= 1;
mode16 = (addr & 1);
eepromSize = (mode16 ? EEPROM_SIZE : 256);
trace_eeprom("Examining %d byte eeprom at location 0x%x"
" using %d bit addressing",eepromSize,addr,
mode16 ? 16 : 8);
msg[0].addr = addr;
msg[0].flags = 0;
msg[0].len = mode16 ? 2 : 1;
msg[0].buf = iadd;
msg[1].addr = addr;
msg[1].flags = I2C_M_RD;
memset(eeprom,0,EEPROM_SIZE);
for (tcnt = 0; tcnt < EEPROM_SIZE; tcnt += pcnt) {
pcnt = 16;
if (pcnt + tcnt > EEPROM_SIZE) pcnt = EEPROM_SIZE-tcnt;
offs = tcnt + (eepromSize - EEPROM_SIZE);
if (mode16) {
iadd[0] = offs >> 8;
iadd[1] = offs;
} else {
iadd[0] = offs;
}
msg[1].len = pcnt;
msg[1].buf = eeprom+tcnt;
if ((ret = i2c_transfer(&hdw->i2c_adap,
msg,ARRAY_SIZE(msg))) != 2) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"eeprom fetch set offs err=%d",ret);
kfree(eeprom);
return NULL;
}
}
return eeprom;
}
void pvr2_hdw_cpufw_set_enabled(struct pvr2_hdw *hdw,
int mode,
int enable_flag)
{
int ret;
u16 address;
unsigned int pipe;
LOCK_TAKE(hdw->big_lock); do {
if ((hdw->fw_buffer == NULL) == !enable_flag) break;
if (!enable_flag) {
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Cleaning up after CPU firmware fetch");
kfree(hdw->fw_buffer);
hdw->fw_buffer = NULL;
hdw->fw_size = 0;
if (hdw->fw_cpu_flag) {
pvr2_hdw_cpureset_assert(hdw,0);
}
break;
}
hdw->fw_cpu_flag = (mode != 2);
if (hdw->fw_cpu_flag) {
hdw->fw_size = (mode == 1) ? 0x4000 : 0x2000;
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Preparing to suck out CPU firmware"
" (size=%u)", hdw->fw_size);
hdw->fw_buffer = kzalloc(hdw->fw_size,GFP_KERNEL);
if (!hdw->fw_buffer) {
hdw->fw_size = 0;
break;
}
pvr2_hdw_cpureset_assert(hdw,1);
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Grabbing CPU firmware");
pipe = usb_rcvctrlpipe(hdw->usb_dev, 0);
for(address = 0; address < hdw->fw_size;
address += 0x800) {
ret = usb_control_msg(hdw->usb_dev,pipe,
0xa0,0xc0,
address,0,
hdw->fw_buffer+address,
0x800,HZ);
if (ret < 0) break;
}
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Done grabbing CPU firmware");
} else {
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Sucking down EEPROM contents");
hdw->fw_buffer = pvr2_full_eeprom_fetch(hdw);
if (!hdw->fw_buffer) {
pvr2_trace(PVR2_TRACE_FIRMWARE,
"EEPROM content suck failed.");
break;
}
hdw->fw_size = EEPROM_SIZE;
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Done sucking down EEPROM contents");
}
} while (0); LOCK_GIVE(hdw->big_lock);
}
int pvr2_hdw_cpufw_get_enabled(struct pvr2_hdw *hdw)
{
return hdw->fw_buffer != NULL;
}
int pvr2_hdw_cpufw_get(struct pvr2_hdw *hdw,unsigned int offs,
char *buf,unsigned int cnt)
{
int ret = -EINVAL;
LOCK_TAKE(hdw->big_lock); do {
if (!buf) break;
if (!cnt) break;
if (!hdw->fw_buffer) {
ret = -EIO;
break;
}
if (offs >= hdw->fw_size) {
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Read firmware data offs=%d EOF",
offs);
ret = 0;
break;
}
if (offs + cnt > hdw->fw_size) cnt = hdw->fw_size - offs;
memcpy(buf,hdw->fw_buffer+offs,cnt);
pvr2_trace(PVR2_TRACE_FIRMWARE,
"Read firmware data offs=%d cnt=%d",
offs,cnt);
ret = cnt;
} while (0); LOCK_GIVE(hdw->big_lock);
return ret;
}
int pvr2_hdw_v4l_get_minor_number(struct pvr2_hdw *hdw,
enum pvr2_v4l_type index)
{
switch (index) {
case pvr2_v4l_type_video: return hdw->v4l_minor_number_video;
case pvr2_v4l_type_vbi: return hdw->v4l_minor_number_vbi;
case pvr2_v4l_type_radio: return hdw->v4l_minor_number_radio;
default: return -1;
}
}
void pvr2_hdw_v4l_store_minor_number(struct pvr2_hdw *hdw,
enum pvr2_v4l_type index,int v)
{
switch (index) {
case pvr2_v4l_type_video: hdw->v4l_minor_number_video = v;
case pvr2_v4l_type_vbi: hdw->v4l_minor_number_vbi = v;
case pvr2_v4l_type_radio: hdw->v4l_minor_number_radio = v;
default: break;
}
}
static void pvr2_ctl_write_complete(struct urb *urb)
{
struct pvr2_hdw *hdw = urb->context;
hdw->ctl_write_pend_flag = 0;
if (hdw->ctl_read_pend_flag) return;
complete(&hdw->ctl_done);
}
static void pvr2_ctl_read_complete(struct urb *urb)
{
struct pvr2_hdw *hdw = urb->context;
hdw->ctl_read_pend_flag = 0;
if (hdw->ctl_write_pend_flag) return;
complete(&hdw->ctl_done);
}
static void pvr2_ctl_timeout(unsigned long data)
{
struct pvr2_hdw *hdw = (struct pvr2_hdw *)data;
if (hdw->ctl_write_pend_flag || hdw->ctl_read_pend_flag) {
hdw->ctl_timeout_flag = !0;
if (hdw->ctl_write_pend_flag)
usb_unlink_urb(hdw->ctl_write_urb);
if (hdw->ctl_read_pend_flag)
usb_unlink_urb(hdw->ctl_read_urb);
}
}
static int pvr2_send_request_ex(struct pvr2_hdw *hdw,
unsigned int timeout,int probe_fl,
void *write_data,unsigned int write_len,
void *read_data,unsigned int read_len)
{
unsigned int idx;
int status = 0;
struct timer_list timer;
if (!hdw->ctl_lock_held) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Attempted to execute control transfer"
" without lock!!");
return -EDEADLK;
}
if (!hdw->flag_ok && !probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Attempted to execute control transfer"
" when device not ok");
return -EIO;
}
if (!(hdw->ctl_read_urb && hdw->ctl_write_urb)) {
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Attempted to execute control transfer"
" when USB is disconnected");
}
return -ENOTTY;
}
if (!write_data) write_len = 0;
if (!read_data) read_len = 0;
if (write_len > PVR2_CTL_BUFFSIZE) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Attempted to execute %d byte"
" control-write transfer (limit=%d)",
write_len,PVR2_CTL_BUFFSIZE);
return -EINVAL;
}
if (read_len > PVR2_CTL_BUFFSIZE) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Attempted to execute %d byte"
" control-read transfer (limit=%d)",
write_len,PVR2_CTL_BUFFSIZE);
return -EINVAL;
}
if ((!write_len) && (!read_len)) {
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"Attempted to execute null control transfer?");
return -EINVAL;
}
hdw->cmd_debug_state = 1;
if (write_len) {
hdw->cmd_debug_code = ((unsigned char *)write_data)[0];
} else {
hdw->cmd_debug_code = 0;
}
hdw->cmd_debug_write_len = write_len;
hdw->cmd_debug_read_len = read_len;
init_completion(&hdw->ctl_done);
hdw->ctl_timeout_flag = 0;
hdw->ctl_write_pend_flag = 0;
hdw->ctl_read_pend_flag = 0;
init_timer(&timer);
timer.expires = jiffies + timeout;
timer.data = (unsigned long)hdw;
timer.function = pvr2_ctl_timeout;
if (write_len) {
hdw->cmd_debug_state = 2;
for (idx = 0; idx < write_len; idx++) {
hdw->ctl_write_buffer[idx] =
((unsigned char *)write_data)[idx];
}
usb_fill_bulk_urb(hdw->ctl_write_urb,
hdw->usb_dev,
usb_sndbulkpipe(hdw->usb_dev,
PVR2_CTL_WRITE_ENDPOINT),
hdw->ctl_write_buffer,
write_len,
pvr2_ctl_write_complete,
hdw);
hdw->ctl_write_urb->actual_length = 0;
hdw->ctl_write_pend_flag = !0;
status = usb_submit_urb(hdw->ctl_write_urb,GFP_KERNEL);
if (status < 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to submit write-control"
" URB status=%d",status);
hdw->ctl_write_pend_flag = 0;
goto done;
}
}
if (read_len) {
hdw->cmd_debug_state = 3;
memset(hdw->ctl_read_buffer,0x43,read_len);
usb_fill_bulk_urb(hdw->ctl_read_urb,
hdw->usb_dev,
usb_rcvbulkpipe(hdw->usb_dev,
PVR2_CTL_READ_ENDPOINT),
hdw->ctl_read_buffer,
read_len,
pvr2_ctl_read_complete,
hdw);
hdw->ctl_read_urb->actual_length = 0;
hdw->ctl_read_pend_flag = !0;
status = usb_submit_urb(hdw->ctl_read_urb,GFP_KERNEL);
if (status < 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to submit read-control"
" URB status=%d",status);
hdw->ctl_read_pend_flag = 0;
goto done;
}
}
add_timer(&timer);
hdw->cmd_debug_state = 4;
while (hdw->ctl_write_pend_flag || hdw->ctl_read_pend_flag) {
wait_for_completion(&hdw->ctl_done);
}
hdw->cmd_debug_state = 5;
del_timer_sync(&timer);
hdw->cmd_debug_state = 6;
status = 0;
if (hdw->ctl_timeout_flag) {
status = -ETIMEDOUT;
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Timed out control-write");
}
goto done;
}
if (write_len) {
if ((hdw->ctl_write_urb->status != 0) &&
(hdw->ctl_write_urb->status != -ENOENT) &&
(hdw->ctl_write_urb->status != -ESHUTDOWN) &&
(hdw->ctl_write_urb->status != -ECONNRESET)) {
status = hdw->ctl_write_urb->status;
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"control-write URB failure,"
" status=%d",
status);
}
goto done;
}
if (hdw->ctl_write_urb->actual_length < write_len) {
status = -EIO;
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"control-write URB short,"
" expected=%d got=%d",
write_len,
hdw->ctl_write_urb->actual_length);
}
goto done;
}
}
if (read_len) {
if ((hdw->ctl_read_urb->status != 0) &&
(hdw->ctl_read_urb->status != -ENOENT) &&
(hdw->ctl_read_urb->status != -ESHUTDOWN) &&
(hdw->ctl_read_urb->status != -ECONNRESET)) {
status = hdw->ctl_read_urb->status;
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"control-read URB failure,"
" status=%d",
status);
}
goto done;
}
if (hdw->ctl_read_urb->actual_length < read_len) {
status = -EIO;
if (!probe_fl) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"control-read URB short,"
" expected=%d got=%d",
read_len,
hdw->ctl_read_urb->actual_length);
}
goto done;
}
for (idx = 0; idx < read_len; idx++) {
((unsigned char *)read_data)[idx] =
hdw->ctl_read_buffer[idx];
}
}
done:
hdw->cmd_debug_state = 0;
if ((status < 0) && (!probe_fl)) {
pvr2_hdw_render_useless(hdw);
}
return status;
}
int pvr2_send_request(struct pvr2_hdw *hdw,
void *write_data,unsigned int write_len,
void *read_data,unsigned int read_len)
{
return pvr2_send_request_ex(hdw,HZ*4,0,
write_data,write_len,
read_data,read_len);
}
static int pvr2_issue_simple_cmd(struct pvr2_hdw *hdw,u32 cmdcode)
{
int ret;
unsigned int cnt = 1;
unsigned int args = 0;
LOCK_TAKE(hdw->ctl_lock);
hdw->cmd_buffer[0] = cmdcode & 0xffu;
args = (cmdcode >> 8) & 0xffu;
args = (args > 2) ? 2 : args;
if (args) {
cnt += args;
hdw->cmd_buffer[1] = (cmdcode >> 16) & 0xffu;
if (args > 1) {
hdw->cmd_buffer[2] = (cmdcode >> 24) & 0xffu;
}
}
if (pvrusb2_debug & PVR2_TRACE_INIT) {
unsigned int idx;
unsigned int ccnt,bcnt;
char tbuf[50];
cmdcode &= 0xffu;
bcnt = 0;
ccnt = scnprintf(tbuf+bcnt,
sizeof(tbuf)-bcnt,
"Sending FX2 command 0x%x",cmdcode);
bcnt += ccnt;
for (idx = 0; idx < ARRAY_SIZE(pvr2_fx2cmd_desc); idx++) {
if (pvr2_fx2cmd_desc[idx].id == cmdcode) {
ccnt = scnprintf(tbuf+bcnt,
sizeof(tbuf)-bcnt,
" \"%s\"",
pvr2_fx2cmd_desc[idx].desc);
bcnt += ccnt;
break;
}
}
if (args) {
ccnt = scnprintf(tbuf+bcnt,
sizeof(tbuf)-bcnt,
" (%u",hdw->cmd_buffer[1]);
bcnt += ccnt;
if (args > 1) {
ccnt = scnprintf(tbuf+bcnt,
sizeof(tbuf)-bcnt,
",%u",hdw->cmd_buffer[2]);
bcnt += ccnt;
}
ccnt = scnprintf(tbuf+bcnt,
sizeof(tbuf)-bcnt,
")");
bcnt += ccnt;
}
pvr2_trace(PVR2_TRACE_INIT,"%.*s",bcnt,tbuf);
}
ret = pvr2_send_request(hdw,hdw->cmd_buffer,cnt,NULL,0);
LOCK_GIVE(hdw->ctl_lock);
return ret;
}
int pvr2_write_register(struct pvr2_hdw *hdw, u16 reg, u32 data)
{
int ret;
LOCK_TAKE(hdw->ctl_lock);
hdw->cmd_buffer[0] = FX2CMD_REG_WRITE;
PVR2_DECOMPOSE_LE(hdw->cmd_buffer,1,data);
hdw->cmd_buffer[5] = 0;
hdw->cmd_buffer[6] = (reg >> 8) & 0xff;
hdw->cmd_buffer[7] = reg & 0xff;
ret = pvr2_send_request(hdw, hdw->cmd_buffer, 8, hdw->cmd_buffer, 0);
LOCK_GIVE(hdw->ctl_lock);
return ret;
}
static int pvr2_read_register(struct pvr2_hdw *hdw, u16 reg, u32 *data)
{
int ret = 0;
LOCK_TAKE(hdw->ctl_lock);
hdw->cmd_buffer[0] = FX2CMD_REG_READ;
hdw->cmd_buffer[1] = 0;
hdw->cmd_buffer[2] = 0;
hdw->cmd_buffer[3] = 0;
hdw->cmd_buffer[4] = 0;
hdw->cmd_buffer[5] = 0;
hdw->cmd_buffer[6] = (reg >> 8) & 0xff;
hdw->cmd_buffer[7] = reg & 0xff;
ret |= pvr2_send_request(hdw, hdw->cmd_buffer, 8, hdw->cmd_buffer, 4);
*data = PVR2_COMPOSE_LE(hdw->cmd_buffer,0);
LOCK_GIVE(hdw->ctl_lock);
return ret;
}
void pvr2_hdw_render_useless(struct pvr2_hdw *hdw)
{
if (!hdw->flag_ok) return;
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Device being rendered inoperable");
if (hdw->vid_stream) {
pvr2_stream_setup(hdw->vid_stream,NULL,0,0);
}
hdw->flag_ok = 0;
trace_stbit("flag_ok",hdw->flag_ok);
pvr2_hdw_state_sched(hdw);
}
void pvr2_hdw_device_reset(struct pvr2_hdw *hdw)
{
int ret;
pvr2_trace(PVR2_TRACE_INIT,"Performing a device reset...");
ret = usb_lock_device_for_reset(hdw->usb_dev,NULL);
if (ret == 0) {
ret = usb_reset_device(hdw->usb_dev);
usb_unlock_device(hdw->usb_dev);
} else {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Failed to lock USB device ret=%d",ret);
}
if (init_pause_msec) {
pvr2_trace(PVR2_TRACE_INFO,
"Waiting %u msec for hardware to settle",
init_pause_msec);
msleep(init_pause_msec);
}
}
void pvr2_hdw_cpureset_assert(struct pvr2_hdw *hdw,int val)
{
char *da;
unsigned int pipe;
int ret;
if (!hdw->usb_dev) return;
da = kmalloc(16, GFP_KERNEL);
if (da == NULL) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"Unable to allocate memory to control CPU reset");
return;
}
pvr2_trace(PVR2_TRACE_INIT,"cpureset_assert(%d)",val);
da[0] = val ? 0x01 : 0x00;
pipe = usb_sndctrlpipe(hdw->usb_dev, 0);
ret = usb_control_msg(hdw->usb_dev,pipe,0xa0,0x40,0xe600,0,da,1,HZ);
if (ret < 0) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"cpureset_assert(%d) error=%d",val,ret);
pvr2_hdw_render_useless(hdw);
}
kfree(da);
}
int pvr2_hdw_cmd_deep_reset(struct pvr2_hdw *hdw)
{
return pvr2_issue_simple_cmd(hdw,FX2CMD_DEEP_RESET);
}
int pvr2_hdw_cmd_powerup(struct pvr2_hdw *hdw)
{
return pvr2_issue_simple_cmd(hdw,FX2CMD_POWER_ON);
}
int pvr2_hdw_cmd_powerdown(struct pvr2_hdw *hdw)
{
return pvr2_issue_simple_cmd(hdw,FX2CMD_POWER_OFF);
}
int pvr2_hdw_cmd_decoder_reset(struct pvr2_hdw *hdw)
{
pvr2_trace(PVR2_TRACE_INIT,
"Requesting decoder reset");
if (hdw->decoder_client_id) {
v4l2_device_call_all(&hdw->v4l2_dev, hdw->decoder_client_id,
core, reset, 0);
pvr2_hdw_cx25840_vbi_hack(hdw);
return 0;
}
pvr2_trace(PVR2_TRACE_INIT,
"Unable to reset decoder: nothing attached");
return -ENOTTY;
}
static int pvr2_hdw_cmd_hcw_demod_reset(struct pvr2_hdw *hdw, int onoff)
{
hdw->flag_ok = !0;
return pvr2_issue_simple_cmd(hdw,
FX2CMD_HCW_DEMOD_RESETIN |
(1 << 8) |
((onoff ? 1 : 0) << 16));
}
static int pvr2_hdw_cmd_onair_fe_power_ctrl(struct pvr2_hdw *hdw, int onoff)
{
hdw->flag_ok = !0;
return pvr2_issue_simple_cmd(hdw,(onoff ?
FX2CMD_ONAIR_DTV_POWER_ON :
FX2CMD_ONAIR_DTV_POWER_OFF));
}
static int pvr2_hdw_cmd_onair_digital_path_ctrl(struct pvr2_hdw *hdw,
int onoff)
{
return pvr2_issue_simple_cmd(hdw,(onoff ?
FX2CMD_ONAIR_DTV_STREAMING_ON :
FX2CMD_ONAIR_DTV_STREAMING_OFF));
}
static void pvr2_hdw_cmd_modeswitch(struct pvr2_hdw *hdw,int digitalFl)
{
int cmode;
cmode = (digitalFl ? PVR2_PATHWAY_DIGITAL : PVR2_PATHWAY_ANALOG);
if (cmode == hdw->pathway_state) {
return;
}
switch (hdw->hdw_desc->digital_control_scheme) {
case PVR2_DIGITAL_SCHEME_HAUPPAUGE:
pvr2_hdw_cmd_hcw_demod_reset(hdw,digitalFl);
if (cmode == PVR2_PATHWAY_ANALOG) {
pvr2_hdw_cmd_decoder_reset(hdw);
}
break;
case PVR2_DIGITAL_SCHEME_ONAIR:
pvr2_hdw_cmd_onair_fe_power_ctrl(hdw,digitalFl);
break;
default: break;
}
pvr2_hdw_untrip_unlocked(hdw);
hdw->pathway_state = cmode;
}
static void pvr2_led_ctrl_hauppauge(struct pvr2_hdw *hdw, int onoff)
{
if (onoff) {
pvr2_hdw_gpio_chg_dir(hdw, 0xffffffff, 0x00000481);
} else {
pvr2_hdw_gpio_chg_dir(hdw, 0xffffffff, 0x00000401);
}
pvr2_hdw_gpio_chg_out(hdw, 0xffffffff, 0x00000000);
}
static void pvr2_led_ctrl(struct pvr2_hdw *hdw,int onoff)
{
unsigned int scheme_id;
led_method_func fp;
if ((!onoff) == (!hdw->led_on)) return;
hdw->led_on = onoff != 0;
scheme_id = hdw->hdw_desc->led_scheme;
if (scheme_id < ARRAY_SIZE(led_methods)) {
fp = led_methods[scheme_id];
} else {
fp = NULL;
}
if (fp) (*fp)(hdw,onoff);
}
static int pvr2_hdw_cmd_usbstream(struct pvr2_hdw *hdw,int runFl)
{
int ret;
if (hdw->pathway_state == PVR2_PATHWAY_ANALOG) {
return pvr2_issue_simple_cmd(hdw,
(runFl ?
FX2CMD_STREAMING_ON :
FX2CMD_STREAMING_OFF));
}
if (hdw->pathway_state != PVR2_PATHWAY_DIGITAL) {
return -EINVAL;
}
switch (hdw->hdw_desc->digital_control_scheme) {
case PVR2_DIGITAL_SCHEME_HAUPPAUGE:
return pvr2_issue_simple_cmd(hdw,
(runFl ?
FX2CMD_HCW_DTV_STREAMING_ON :
FX2CMD_HCW_DTV_STREAMING_OFF));
case PVR2_DIGITAL_SCHEME_ONAIR:
ret = pvr2_issue_simple_cmd(hdw,
(runFl ?
FX2CMD_STREAMING_ON :
FX2CMD_STREAMING_OFF));
if (ret) return ret;
return pvr2_hdw_cmd_onair_digital_path_ctrl(hdw,runFl);
default:
return -EINVAL;
}
}
static int state_eval_pathway_ok(struct pvr2_hdw *hdw)
{
if (hdw->state_pathway_ok) {
return 0;
}
if (!hdw->state_pipeline_idle) {
return 0;
}
pvr2_hdw_cmd_modeswitch(hdw,hdw->input_val == PVR2_CVAL_INPUT_DTV);
hdw->state_pathway_ok = !0;
trace_stbit("state_pathway_ok",hdw->state_pathway_ok);
return !0;
}
static int state_eval_encoder_ok(struct pvr2_hdw *hdw)
{
if (hdw->state_encoder_ok) return 0;
if (hdw->flag_tripped) return 0;
if (hdw->state_encoder_run) return 0;
if (hdw->state_encoder_config) return 0;
if (hdw->state_decoder_run) return 0;
if (hdw->state_usbstream_run) return 0;
if (hdw->pathway_state == PVR2_PATHWAY_DIGITAL) {
if (!hdw->hdw_desc->flag_digital_requires_cx23416) return 0;
} else if (hdw->pathway_state != PVR2_PATHWAY_ANALOG) {
return 0;
}
if (pvr2_upload_firmware2(hdw) < 0) {
hdw->flag_tripped = !0;
trace_stbit("flag_tripped",hdw->flag_tripped);
return !0;
}
hdw->state_encoder_ok = !0;
trace_stbit("state_encoder_ok",hdw->state_encoder_ok);
return !0;
}
static int state_eval_encoder_config(struct pvr2_hdw *hdw)
{
if (hdw->state_encoder_config) {
if (hdw->state_encoder_ok) {
if (hdw->state_pipeline_req &&
!hdw->state_pipeline_pause) return 0;
}
hdw->state_encoder_config = 0;
hdw->state_encoder_waitok = 0;
trace_stbit("state_encoder_waitok",hdw->state_encoder_waitok);
del_timer_sync(&hdw->encoder_wait_timer);
} else {
if (!hdw->state_pathway_ok ||
(hdw->pathway_state != PVR2_PATHWAY_ANALOG) ||
!hdw->state_encoder_ok ||
!hdw->state_pipeline_idle ||
hdw->state_pipeline_pause ||
!hdw->state_pipeline_req ||
!hdw->state_pipeline_config) {
if (timer_pending(&hdw->encoder_wait_timer)) {
del_timer_sync(&hdw->encoder_wait_timer);
}
if (hdw->state_encoder_waitok) {
hdw->state_encoder_waitok = 0;
trace_stbit("state_encoder_waitok",
hdw->state_encoder_waitok);
return !0;
}
return 0;
}
if (!hdw->state_encoder_waitok) {
if (!timer_pending(&hdw->encoder_wait_timer)) {
if (!hdw->state_encoder_waitok) {
hdw->encoder_wait_timer.expires =
jiffies +
(HZ * TIME_MSEC_ENCODER_WAIT
/ 1000);
add_timer(&hdw->encoder_wait_timer);
}
}
return 0;
}
pvr2_encoder_configure(hdw);
if (hdw->state_encoder_ok) hdw->state_encoder_config = !0;
}
trace_stbit("state_encoder_config",hdw->state_encoder_config);
return !0;
}
static int state_check_disable_encoder_run(struct pvr2_hdw *hdw)
{
if (!hdw->state_encoder_ok) {
return !0;
}
if (!hdw->state_pathway_ok) {
return !0;
}
switch (hdw->pathway_state) {
case PVR2_PATHWAY_ANALOG:
if (!hdw->state_decoder_run) {
return !0;
}
break;
case PVR2_PATHWAY_DIGITAL:
if (hdw->state_encoder_runok) {
return !0;
}
break;
default:
return !0;
}
return 0;
}
static int state_check_enable_encoder_run(struct pvr2_hdw *hdw)
{
if (!hdw->state_encoder_ok) {
return 0;
}
if (!hdw->state_pathway_ok) {
return 0;
}
switch (hdw->pathway_state) {
case PVR2_PATHWAY_ANALOG:
if (hdw->state_decoder_run && hdw->state_decoder_ready) {
return !0;
}
break;
case PVR2_PATHWAY_DIGITAL:
if ((hdw->hdw_desc->digital_control_scheme ==
PVR2_DIGITAL_SCHEME_ONAIR) &&
!hdw->state_encoder_runok) {
return !0;
}
break;
default:
break;
}
return 0;
}
static int state_eval_encoder_run(struct pvr2_hdw *hdw)
{
if (hdw->state_encoder_run) {
if (!state_check_disable_encoder_run(hdw)) return 0;
if (hdw->state_encoder_ok) {
del_timer_sync(&hdw->encoder_run_timer);
if (pvr2_encoder_stop(hdw) < 0) return !0;
}
hdw->state_encoder_run = 0;
} else {
if (!state_check_enable_encoder_run(hdw)) return 0;
if (pvr2_encoder_start(hdw) < 0) return !0;
hdw->state_encoder_run = !0;
if (!hdw->state_encoder_runok) {
hdw->encoder_run_timer.expires =
jiffies + (HZ * TIME_MSEC_ENCODER_OK / 1000);
add_timer(&hdw->encoder_run_timer);
}
}
trace_stbit("state_encoder_run",hdw->state_encoder_run);
return !0;
}
static void pvr2_hdw_quiescent_timeout(unsigned long data)
{
struct pvr2_hdw *hdw = (struct pvr2_hdw *)data;
hdw->state_decoder_quiescent = !0;
trace_stbit("state_decoder_quiescent",hdw->state_decoder_quiescent);
hdw->state_stale = !0;
queue_work(hdw->workqueue,&hdw->workpoll);
}
static void pvr2_hdw_decoder_stabilization_timeout(unsigned long data)
{
struct pvr2_hdw *hdw = (struct pvr2_hdw *)data;
hdw->state_decoder_ready = !0;
trace_stbit("state_decoder_ready", hdw->state_decoder_ready);
hdw->state_stale = !0;
queue_work(hdw->workqueue, &hdw->workpoll);
}
static void pvr2_hdw_encoder_wait_timeout(unsigned long data)
{
struct pvr2_hdw *hdw = (struct pvr2_hdw *)data;
hdw->state_encoder_waitok = !0;
trace_stbit("state_encoder_waitok",hdw->state_encoder_waitok);
hdw->state_stale = !0;
queue_work(hdw->workqueue,&hdw->workpoll);
}
static void pvr2_hdw_encoder_run_timeout(unsigned long data)
{
struct pvr2_hdw *hdw = (struct pvr2_hdw *)data;
if (!hdw->state_encoder_runok) {
hdw->state_encoder_runok = !0;
trace_stbit("state_encoder_runok",hdw->state_encoder_runok);
hdw->state_stale = !0;
queue_work(hdw->workqueue,&hdw->workpoll);
}
}
static int state_eval_decoder_run(struct pvr2_hdw *hdw)
{
if (hdw->state_decoder_run) {
if (hdw->state_encoder_ok) {
if (hdw->state_pipeline_req &&
!hdw->state_pipeline_pause &&
hdw->state_pathway_ok) return 0;
}
if (!hdw->flag_decoder_missed) {
pvr2_decoder_enable(hdw,0);
}
hdw->state_decoder_quiescent = 0;
hdw->state_decoder_run = 0;
del_timer_sync(&hdw->quiescent_timer);
del_timer_sync(&hdw->decoder_stabilization_timer);
hdw->state_decoder_ready = 0;
} else {
if (!hdw->state_decoder_quiescent) {
if (!timer_pending(&hdw->quiescent_timer)) {
if (!hdw->state_decoder_quiescent) {
hdw->quiescent_timer.expires =
jiffies +
(HZ * TIME_MSEC_DECODER_WAIT
/ 1000);
add_timer(&hdw->quiescent_timer);
}
}
return 0;
}
if (!hdw->state_pathway_ok ||
(hdw->pathway_state != PVR2_PATHWAY_ANALOG) ||
!hdw->state_pipeline_req ||
hdw->state_pipeline_pause ||
!hdw->state_pipeline_config ||
!hdw->state_encoder_config ||
!hdw->state_encoder_ok) return 0;
del_timer_sync(&hdw->quiescent_timer);
if (hdw->flag_decoder_missed) return 0;
if (pvr2_decoder_enable(hdw,!0) < 0) return 0;
hdw->state_decoder_quiescent = 0;
hdw->state_decoder_ready = 0;
hdw->state_decoder_run = !0;
if (hdw->decoder_client_id == PVR2_CLIENT_ID_SAA7115) {
hdw->decoder_stabilization_timer.expires =
jiffies +
(HZ * TIME_MSEC_DECODER_STABILIZATION_WAIT /
1000);
add_timer(&hdw->decoder_stabilization_timer);
} else {
hdw->state_decoder_ready = !0;
}
}
trace_stbit("state_decoder_quiescent",hdw->state_decoder_quiescent);
trace_stbit("state_decoder_run",hdw->state_decoder_run);
trace_stbit("state_decoder_ready", hdw->state_decoder_ready);
return !0;
}
static int state_eval_usbstream_run(struct pvr2_hdw *hdw)
{
if (hdw->state_usbstream_run) {
int fl = !0;
if (hdw->pathway_state == PVR2_PATHWAY_ANALOG) {
fl = (hdw->state_encoder_ok &&
hdw->state_encoder_run);
} else if ((hdw->pathway_state == PVR2_PATHWAY_DIGITAL) &&
(hdw->hdw_desc->flag_digital_requires_cx23416)) {
fl = hdw->state_encoder_ok;
}
if (fl &&
hdw->state_pipeline_req &&
!hdw->state_pipeline_pause &&
hdw->state_pathway_ok) {
return 0;
}
pvr2_hdw_cmd_usbstream(hdw,0);
hdw->state_usbstream_run = 0;
} else {
if (!hdw->state_pipeline_req ||
hdw->state_pipeline_pause ||
!hdw->state_pathway_ok) return 0;
if (hdw->pathway_state == PVR2_PATHWAY_ANALOG) {
if (!hdw->state_encoder_ok ||
!hdw->state_encoder_run) return 0;
} else if ((hdw->pathway_state == PVR2_PATHWAY_DIGITAL) &&
(hdw->hdw_desc->flag_digital_requires_cx23416)) {
if (!hdw->state_encoder_ok) return 0;
if (hdw->state_encoder_run) return 0;
if (hdw->hdw_desc->digital_control_scheme ==
PVR2_DIGITAL_SCHEME_ONAIR) {
if (!hdw->state_encoder_runok) return 0;
}
}
if (pvr2_hdw_cmd_usbstream(hdw,!0) < 0) return 0;
hdw->state_usbstream_run = !0;
}
trace_stbit("state_usbstream_run",hdw->state_usbstream_run);
return !0;
}
static int state_eval_pipeline_config(struct pvr2_hdw *hdw)
{
if (hdw->state_pipeline_config ||
hdw->state_pipeline_pause) return 0;
pvr2_hdw_commit_execute(hdw);
return !0;
}
static int state_update_pipeline_state(struct pvr2_hdw *hdw)
{
unsigned int st;
int updatedFl = 0;
st = !(hdw->state_encoder_run ||
hdw->state_decoder_run ||
hdw->state_usbstream_run ||
(!hdw->state_decoder_quiescent));
if (!st != !hdw->state_pipeline_idle) {
hdw->state_pipeline_idle = st;
updatedFl = !0;
}
if (hdw->state_pipeline_idle && hdw->state_pipeline_pause) {
hdw->state_pipeline_pause = 0;
updatedFl = !0;
}
return updatedFl;
}
static int pvr2_hdw_state_update(struct pvr2_hdw *hdw)
{
unsigned int i;
int state_updated = 0;
int check_flag;
if (!hdw->state_stale) return 0;
if ((hdw->fw1_state != FW1_STATE_OK) ||
!hdw->flag_ok) {
hdw->state_stale = 0;
return !0;
}
do {
check_flag = 0;
state_update_pipeline_state(hdw);
for (i = 0; (i<ARRAY_SIZE(eval_funcs)) && hdw->flag_ok; i++) {
if ((*eval_funcs[i])(hdw)) {
check_flag = !0;
state_updated = !0;
state_update_pipeline_state(hdw);
}
}
} while (check_flag && hdw->flag_ok);
hdw->state_stale = 0;
trace_stbit("state_stale",hdw->state_stale);
return state_updated;
}
static unsigned int print_input_mask(unsigned int msk,
char *buf,unsigned int acnt)
{
unsigned int idx,ccnt;
unsigned int tcnt = 0;
for (idx = 0; idx < ARRAY_SIZE(control_values_input); idx++) {
if (!((1 << idx) & msk)) continue;
ccnt = scnprintf(buf+tcnt,
acnt-tcnt,
"%s%s",
(tcnt ? ", " : ""),
control_values_input[idx]);
tcnt += ccnt;
}
return tcnt;
}
static const char *pvr2_pathway_state_name(int id)
{
switch (id) {
case PVR2_PATHWAY_ANALOG: return "analog";
case PVR2_PATHWAY_DIGITAL: return "digital";
default: return "unknown";
}
}
static unsigned int pvr2_hdw_report_unlocked(struct pvr2_hdw *hdw,int which,
char *buf,unsigned int acnt)
{
switch (which) {
case 0:
return scnprintf(
buf,acnt,
"driver:%s%s%s%s%s <mode=%s>",
(hdw->flag_ok ? " <ok>" : " <fail>"),
(hdw->flag_init_ok ? " <init>" : " <uninitialized>"),
(hdw->flag_disconnected ? " <disconnected>" :
" <connected>"),
(hdw->flag_tripped ? " <tripped>" : ""),
(hdw->flag_decoder_missed ? " <no decoder>" : ""),
pvr2_pathway_state_name(hdw->pathway_state));
case 1:
return scnprintf(
buf,acnt,
"pipeline:%s%s%s%s",
(hdw->state_pipeline_idle ? " <idle>" : ""),
(hdw->state_pipeline_config ?
" <configok>" : " <stale>"),
(hdw->state_pipeline_req ? " <req>" : ""),
(hdw->state_pipeline_pause ? " <pause>" : ""));
case 2:
return scnprintf(
buf,acnt,
"worker:%s%s%s%s%s%s%s",
(hdw->state_decoder_run ?
(hdw->state_decoder_ready ?
"<decode:run>" : " <decode:start>") :
(hdw->state_decoder_quiescent ?
"" : " <decode:stop>")),
(hdw->state_decoder_quiescent ?
" <decode:quiescent>" : ""),
(hdw->state_encoder_ok ?
"" : " <encode:init>"),
(hdw->state_encoder_run ?
(hdw->state_encoder_runok ?
" <encode:run>" :
" <encode:firstrun>") :
(hdw->state_encoder_runok ?
" <encode:stop>" :
" <encode:virgin>")),
(hdw->state_encoder_config ?
" <encode:configok>" :
(hdw->state_encoder_waitok ?
"" : " <encode:waitok>")),
(hdw->state_usbstream_run ?
" <usb:run>" : " <usb:stop>"),
(hdw->state_pathway_ok ?
" <pathway:ok>" : ""));
case 3:
return scnprintf(
buf,acnt,
"state: %s",
pvr2_get_state_name(hdw->master_state));
case 4: {
unsigned int tcnt = 0;
unsigned int ccnt;
ccnt = scnprintf(buf,
acnt,
"Hardware supported inputs: ");
tcnt += ccnt;
tcnt += print_input_mask(hdw->input_avail_mask,
buf+tcnt,
acnt-tcnt);
if (hdw->input_avail_mask != hdw->input_allowed_mask) {
ccnt = scnprintf(buf+tcnt,
acnt-tcnt,
"; allowed inputs: ");
tcnt += ccnt;
tcnt += print_input_mask(hdw->input_allowed_mask,
buf+tcnt,
acnt-tcnt);
}
return tcnt;
}
case 5: {
struct pvr2_stream_stats stats;
if (!hdw->vid_stream) break;
pvr2_stream_get_stats(hdw->vid_stream,
&stats,
0);
return scnprintf(
buf,acnt,
"Bytes streamed=%u"
" URBs: queued=%u idle=%u ready=%u"
" processed=%u failed=%u",
stats.bytes_processed,
stats.buffers_in_queue,
stats.buffers_in_idle,
stats.buffers_in_ready,
stats.buffers_processed,
stats.buffers_failed);
}
case 6: {
unsigned int id = hdw->ir_scheme_active;
return scnprintf(buf, acnt, "ir scheme: id=%d %s", id,
(id >= ARRAY_SIZE(ir_scheme_names) ?
"?" : ir_scheme_names[id]));
}
default: break;
}
return 0;
}
static unsigned int pvr2_hdw_report_clients(struct pvr2_hdw *hdw,
char *buf, unsigned int acnt)
{
struct v4l2_subdev *sd;
unsigned int tcnt = 0;
unsigned int ccnt;
struct i2c_client *client;
const char *p;
unsigned int id;
ccnt = scnprintf(buf, acnt, "Associated v4l2-subdev drivers and I2C clients:\n");
tcnt += ccnt;
v4l2_device_for_each_subdev(sd, &hdw->v4l2_dev) {
id = sd->grp_id;
p = NULL;
if (id < ARRAY_SIZE(module_names)) p = module_names[id];
if (p) {
ccnt = scnprintf(buf + tcnt, acnt - tcnt, " %s:", p);
tcnt += ccnt;
} else {
ccnt = scnprintf(buf + tcnt, acnt - tcnt,
" (unknown id=%u):", id);
tcnt += ccnt;
}
client = v4l2_get_subdevdata(sd);
if (client) {
ccnt = scnprintf(buf + tcnt, acnt - tcnt,
" %s @ %02x\n", client->name,
client->addr);
tcnt += ccnt;
} else {
ccnt = scnprintf(buf + tcnt, acnt - tcnt,
" no i2c client\n");
tcnt += ccnt;
}
}
return tcnt;
}
unsigned int pvr2_hdw_state_report(struct pvr2_hdw *hdw,
char *buf,unsigned int acnt)
{
unsigned int bcnt,ccnt,idx;
bcnt = 0;
LOCK_TAKE(hdw->big_lock);
for (idx = 0; ; idx++) {
ccnt = pvr2_hdw_report_unlocked(hdw,idx,buf,acnt);
if (!ccnt) break;
bcnt += ccnt; acnt -= ccnt; buf += ccnt;
if (!acnt) break;
buf[0] = '\n'; ccnt = 1;
bcnt += ccnt; acnt -= ccnt; buf += ccnt;
}
ccnt = pvr2_hdw_report_clients(hdw, buf, acnt);
bcnt += ccnt; acnt -= ccnt; buf += ccnt;
LOCK_GIVE(hdw->big_lock);
return bcnt;
}
static void pvr2_hdw_state_log_state(struct pvr2_hdw *hdw)
{
char buf[256];
unsigned int idx, ccnt;
unsigned int lcnt, ucnt;
for (idx = 0; ; idx++) {
ccnt = pvr2_hdw_report_unlocked(hdw,idx,buf,sizeof(buf));
if (!ccnt) break;
printk(KERN_INFO "%s %.*s\n",hdw->name,ccnt,buf);
}
ccnt = pvr2_hdw_report_clients(hdw, buf, sizeof(buf));
ucnt = 0;
while (ucnt < ccnt) {
lcnt = 0;
while ((lcnt + ucnt < ccnt) && (buf[lcnt + ucnt] != '\n')) {
lcnt++;
}
printk(KERN_INFO "%s %.*s\n", hdw->name, lcnt, buf + ucnt);
ucnt += lcnt + 1;
}
}
static int pvr2_hdw_state_eval(struct pvr2_hdw *hdw)
{
unsigned int st;
int state_updated = 0;
int callback_flag = 0;
int analog_mode;
pvr2_trace(PVR2_TRACE_STBITS,
"Drive state check START");
if (pvrusb2_debug & PVR2_TRACE_STBITS) {
pvr2_hdw_state_log_state(hdw);
}
state_updated = pvr2_hdw_state_update(hdw);
analog_mode = (hdw->pathway_state != PVR2_PATHWAY_DIGITAL);
if (!hdw->flag_ok) {
st = PVR2_STATE_DEAD;
} else if (hdw->fw1_state != FW1_STATE_OK) {
st = PVR2_STATE_COLD;
} else if ((analog_mode ||
hdw->hdw_desc->flag_digital_requires_cx23416) &&
!hdw->state_encoder_ok) {
st = PVR2_STATE_WARM;
} else if (hdw->flag_tripped ||
(analog_mode && hdw->flag_decoder_missed)) {
st = PVR2_STATE_ERROR;
} else if (hdw->state_usbstream_run &&
(!analog_mode ||
(hdw->state_encoder_run && hdw->state_decoder_run))) {
st = PVR2_STATE_RUN;
} else {
st = PVR2_STATE_READY;
}
if (hdw->master_state != st) {
pvr2_trace(PVR2_TRACE_STATE,
"Device state change from %s to %s",
pvr2_get_state_name(hdw->master_state),
pvr2_get_state_name(st));
pvr2_led_ctrl(hdw,st == PVR2_STATE_RUN);
hdw->master_state = st;
state_updated = !0;
callback_flag = !0;
}
if (state_updated) {
wake_up(&hdw->state_wait_data);
}
if (pvrusb2_debug & PVR2_TRACE_STBITS) {
pvr2_hdw_state_log_state(hdw);
}
pvr2_trace(PVR2_TRACE_STBITS,
"Drive state check DONE callback=%d",callback_flag);
return callback_flag;
}
static void pvr2_hdw_state_sched(struct pvr2_hdw *hdw)
{
if (hdw->state_stale) return;
hdw->state_stale = !0;
trace_stbit("state_stale",hdw->state_stale);
queue_work(hdw->workqueue,&hdw->workpoll);
}
int pvr2_hdw_gpio_get_dir(struct pvr2_hdw *hdw,u32 *dp)
{
return pvr2_read_register(hdw,PVR2_GPIO_DIR,dp);
}
int pvr2_hdw_gpio_get_out(struct pvr2_hdw *hdw,u32 *dp)
{
return pvr2_read_register(hdw,PVR2_GPIO_OUT,dp);
}
int pvr2_hdw_gpio_get_in(struct pvr2_hdw *hdw,u32 *dp)
{
return pvr2_read_register(hdw,PVR2_GPIO_IN,dp);
}
int pvr2_hdw_gpio_chg_dir(struct pvr2_hdw *hdw,u32 msk,u32 val)
{
u32 cval,nval;
int ret;
if (~msk) {
ret = pvr2_read_register(hdw,PVR2_GPIO_DIR,&cval);
if (ret) return ret;
nval = (cval & ~msk) | (val & msk);
pvr2_trace(PVR2_TRACE_GPIO,
"GPIO direction changing 0x%x:0x%x"
" from 0x%x to 0x%x",
msk,val,cval,nval);
} else {
nval = val;
pvr2_trace(PVR2_TRACE_GPIO,
"GPIO direction changing to 0x%x",nval);
}
return pvr2_write_register(hdw,PVR2_GPIO_DIR,nval);
}
int pvr2_hdw_gpio_chg_out(struct pvr2_hdw *hdw,u32 msk,u32 val)
{
u32 cval,nval;
int ret;
if (~msk) {
ret = pvr2_read_register(hdw,PVR2_GPIO_OUT,&cval);
if (ret) return ret;
nval = (cval & ~msk) | (val & msk);
pvr2_trace(PVR2_TRACE_GPIO,
"GPIO output changing 0x%x:0x%x from 0x%x to 0x%x",
msk,val,cval,nval);
} else {
nval = val;
pvr2_trace(PVR2_TRACE_GPIO,
"GPIO output changing to 0x%x",nval);
}
return pvr2_write_register(hdw,PVR2_GPIO_OUT,nval);
}
void pvr2_hdw_status_poll(struct pvr2_hdw *hdw)
{
struct v4l2_tuner *vtp = &hdw->tuner_signal_info;
memset(vtp, 0, sizeof(*vtp));
vtp->type = (hdw->input_val == PVR2_CVAL_INPUT_RADIO) ?
V4L2_TUNER_RADIO : V4L2_TUNER_ANALOG_TV;
hdw->tuner_signal_stale = 0;
v4l2_device_call_all(&hdw->v4l2_dev, 0, tuner, g_tuner, vtp);
pvr2_trace(PVR2_TRACE_CHIPS, "subdev status poll"
" type=%u strength=%u audio=0x%x cap=0x%x"
" low=%u hi=%u",
vtp->type,
vtp->signal, vtp->rxsubchans, vtp->capability,
vtp->rangelow, vtp->rangehigh);
hdw->cropcap_stale = 0;
}
unsigned int pvr2_hdw_get_input_available(struct pvr2_hdw *hdw)
{
return hdw->input_avail_mask;
}
unsigned int pvr2_hdw_get_input_allowed(struct pvr2_hdw *hdw)
{
return hdw->input_allowed_mask;
}
static int pvr2_hdw_set_input(struct pvr2_hdw *hdw,int v)
{
if (hdw->input_val != v) {
hdw->input_val = v;
hdw->input_dirty = !0;
}
if (hdw->input_val == PVR2_CVAL_INPUT_RADIO) {
hdw->freqSelector = 0;
hdw->freqDirty = !0;
} else if ((hdw->input_val == PVR2_CVAL_INPUT_TV) ||
(hdw->input_val == PVR2_CVAL_INPUT_DTV)) {
hdw->freqSelector = 1;
hdw->freqDirty = !0;
}
return 0;
}
int pvr2_hdw_set_input_allowed(struct pvr2_hdw *hdw,
unsigned int change_mask,
unsigned int change_val)
{
int ret = 0;
unsigned int nv,m,idx;
LOCK_TAKE(hdw->big_lock);
do {
nv = hdw->input_allowed_mask & ~change_mask;
nv |= (change_val & change_mask);
nv &= hdw->input_avail_mask;
if (!nv) {
ret = -EPERM;
break;
}
hdw->input_allowed_mask = nv;
if ((1 << hdw->input_val) & hdw->input_allowed_mask) {
break;
}
if (!hdw->input_allowed_mask) {
break;
}
m = hdw->input_allowed_mask;
for (idx = 0; idx < (sizeof(m) << 3); idx++) {
if (!((1 << idx) & m)) continue;
pvr2_hdw_set_input(hdw,idx);
break;
}
} while (0);
LOCK_GIVE(hdw->big_lock);
return ret;
}
static int pvr2_hdw_get_eeprom_addr(struct pvr2_hdw *hdw)
{
int result;
LOCK_TAKE(hdw->ctl_lock); do {
hdw->cmd_buffer[0] = FX2CMD_GET_EEPROM_ADDR;
result = pvr2_send_request(hdw,
hdw->cmd_buffer,1,
hdw->cmd_buffer,1);
if (result < 0) break;
result = hdw->cmd_buffer[0];
} while(0); LOCK_GIVE(hdw->ctl_lock);
return result;
}
int pvr2_hdw_register_access(struct pvr2_hdw *hdw,
struct v4l2_dbg_match *match, u64 reg_id,
int setFl, u64 *val_ptr)
{
#ifdef CONFIG_VIDEO_ADV_DEBUG
struct v4l2_dbg_register req;
int stat = 0;
int okFl = 0;
if (!capable(CAP_SYS_ADMIN)) return -EPERM;
req.match = *match;
req.reg = reg_id;
if (setFl) req.val = *val_ptr;
v4l2_device_call_all(&hdw->v4l2_dev, 0, core, g_register, &req);
if (!setFl) *val_ptr = req.val;
if (okFl) {
return stat;
}
return -EINVAL;
#else
return -ENOSYS;
#endif
}
