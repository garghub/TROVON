static int\r\nclk_src_get(struct snd_bebob *bebob, unsigned int *id)\r\n{\r\nreturn avc_audio_get_selector(bebob->unit, 0, 4, id);\r\n}
