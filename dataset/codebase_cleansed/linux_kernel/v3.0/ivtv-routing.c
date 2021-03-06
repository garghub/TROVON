void ivtv_audio_set_io(struct ivtv *itv)
{
const struct ivtv_card_audio_input *in;
u32 input, output = 0;
if (test_bit(IVTV_F_I_RADIO_USER, &itv->i_flags))
in = &itv->card->radio_input;
else
in = &itv->card->audio_inputs[itv->audio_input];
input = in->muxer_input;
if (itv->card->hw_muxer & IVTV_HW_M52790)
output = M52790_OUT_STEREO;
v4l2_subdev_call(itv->sd_muxer, audio, s_routing,
input, output, 0);
input = in->audio_input;
output = 0;
if (itv->card->hw_audio & IVTV_HW_MSP34XX)
output = MSP_OUTPUT(MSP_SC_IN_DSP_SCART1);
ivtv_call_hw(itv, itv->card->hw_audio, audio, s_routing,
input, output, 0);
}
void ivtv_video_set_io(struct ivtv *itv)
{
int inp = itv->active_input;
u32 input;
u32 type;
v4l2_subdev_call(itv->sd_video, video, s_routing,
itv->card->video_inputs[inp].video_input, 0, 0);
type = itv->card->video_inputs[inp].video_type;
if (type == IVTV_CARD_INPUT_VID_TUNER) {
input = 0;
} else if (type < IVTV_CARD_INPUT_COMPOSITE1) {
input = 2;
} else {
input = 1;
}
if (itv->card->hw_video & IVTV_HW_GPIO)
ivtv_call_hw(itv, IVTV_HW_GPIO, video, s_routing,
input, 0, 0);
if (itv->card->hw_video & IVTV_HW_UPD64031A) {
if (type == IVTV_CARD_INPUT_VID_TUNER ||
type >= IVTV_CARD_INPUT_COMPOSITE1) {
input = UPD64031A_GR_ON | UPD64031A_3DYCS_COMPOSITE;
} else {
input = UPD64031A_GR_OFF | UPD64031A_3DYCS_DISABLE;
}
input |= itv->card->gr_config;
ivtv_call_hw(itv, IVTV_HW_UPD64031A, video, s_routing,
input, 0, 0);
}
if (itv->card->hw_video & IVTV_HW_UPD6408X) {
input = UPD64083_YCS_MODE;
if (type > IVTV_CARD_INPUT_VID_TUNER &&
type < IVTV_CARD_INPUT_COMPOSITE1) {
input |= UPD64083_YCNR_MODE;
}
else if (itv->card->hw_video & IVTV_HW_UPD64031A) {
if (type == IVTV_CARD_INPUT_VID_TUNER ||
itv->card->type == IVTV_CARD_CX23416GYC) {
input |= UPD64083_EXT_Y_ADC;
}
}
ivtv_call_hw(itv, IVTV_HW_UPD6408X, video, s_routing,
input, 0, 0);
}
}
