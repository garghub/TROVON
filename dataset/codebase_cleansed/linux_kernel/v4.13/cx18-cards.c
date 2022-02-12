const struct cx18_card *cx18_get_card(u16 index)
{
if (index >= ARRAY_SIZE(cx18_card_list))
return NULL;
return cx18_card_list[index];
}
int cx18_get_input(struct cx18 *cx, u16 index, struct v4l2_input *input)
{
const struct cx18_card_video_input *card_input =
cx->card->video_inputs + index;
static const char * const input_strs[] = {
"Tuner 1",
"S-Video 1",
"S-Video 2",
"Composite 1",
"Composite 2",
"Component 1"
};
if (index >= cx->nof_inputs)
return -EINVAL;
input->index = index;
strlcpy(input->name, input_strs[card_input->video_type - 1],
sizeof(input->name));
input->type = (card_input->video_type == CX18_CARD_INPUT_VID_TUNER ?
V4L2_INPUT_TYPE_TUNER : V4L2_INPUT_TYPE_CAMERA);
input->audioset = (1 << cx->nof_audio_inputs) - 1;
input->std = (input->type == V4L2_INPUT_TYPE_TUNER) ?
cx->tuner_std : V4L2_STD_ALL;
return 0;
}
int cx18_get_audio_input(struct cx18 *cx, u16 index, struct v4l2_audio *audio)
{
const struct cx18_card_audio_input *aud_input =
cx->card->audio_inputs + index;
static const char * const input_strs[] = {
"Tuner 1",
"Line In 1",
"Line In 2"
};
memset(audio, 0, sizeof(*audio));
if (index >= cx->nof_audio_inputs)
return -EINVAL;
strlcpy(audio->name, input_strs[aud_input->audio_type - 1],
sizeof(audio->name));
audio->index = index;
audio->capability = V4L2_AUDCAP_STEREO;
return 0;
}
