const struct ivtv_card *ivtv_get_card(u16 index)
{
if (index >= ARRAY_SIZE(ivtv_card_list))
return NULL;
return ivtv_card_list[index];
}
int ivtv_get_input(struct ivtv *itv, u16 index, struct v4l2_input *input)
{
const struct ivtv_card_video_input *card_input = itv->card->video_inputs + index;
static const char * const input_strs[] = {
"Tuner 1",
"S-Video 1",
"S-Video 2",
"Composite 1",
"Composite 2",
"Composite 3"
};
if (index >= itv->nof_inputs)
return -EINVAL;
input->index = index;
strlcpy(input->name, input_strs[card_input->video_type - 1],
sizeof(input->name));
input->type = (card_input->video_type == IVTV_CARD_INPUT_VID_TUNER ?
V4L2_INPUT_TYPE_TUNER : V4L2_INPUT_TYPE_CAMERA);
input->audioset = (1 << itv->nof_audio_inputs) - 1;
input->std = (input->type == V4L2_INPUT_TYPE_TUNER) ?
itv->tuner_std : V4L2_STD_ALL;
return 0;
}
int ivtv_get_output(struct ivtv *itv, u16 index, struct v4l2_output *output)
{
const struct ivtv_card_output *card_output = itv->card->video_outputs + index;
if (index >= itv->card->nof_outputs)
return -EINVAL;
output->index = index;
strlcpy(output->name, card_output->name, sizeof(output->name));
output->type = V4L2_OUTPUT_TYPE_ANALOG;
output->audioset = 1;
output->std = V4L2_STD_ALL;
return 0;
}
int ivtv_get_audio_input(struct ivtv *itv, u16 index, struct v4l2_audio *audio)
{
const struct ivtv_card_audio_input *aud_input = itv->card->audio_inputs + index;
static const char * const input_strs[] = {
"Tuner 1",
"Line In 1",
"Line In 2"
};
memset(audio, 0, sizeof(*audio));
if (index >= itv->nof_audio_inputs)
return -EINVAL;
strlcpy(audio->name, input_strs[aud_input->audio_type - 1],
sizeof(audio->name));
audio->index = index;
audio->capability = V4L2_AUDCAP_STEREO;
return 0;
}
int ivtv_get_audio_output(struct ivtv *itv, u16 index, struct v4l2_audioout *aud_output)
{
memset(aud_output, 0, sizeof(*aud_output));
if (itv->card->video_outputs == NULL || index != 0)
return -EINVAL;
strlcpy(aud_output->name, "A/V Audio Out", sizeof(aud_output->name));
return 0;
}
